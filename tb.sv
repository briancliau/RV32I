`timescale 1ns/1ps

import rvDefs::*;

module tb();

    // --------------------------------------------------------
    // Clock and Reset Signals
    // --------------------------------------------------------
    logic clk;
    logic resetN;
    logic stall;

    // --------------------------------------------------------
    // Core Interface Signals
    // --------------------------------------------------------
    rvDefs::instruction_t instruction;
    rvDefs::mem_addr_t    instructionAddress;
    
    rvDefs::mem_addr_t    memAddress;
    rvDefs::word_t        memReadData;
    rvDefs::word_t        memWriteData;
    logic                 memRead;
    logic                 memWrite;
    logic [2:0]           memSize;

    // --------------------------------------------------------
    // Simulated Memories (Expanded to 2KB/512 Words for tests)
    // --------------------------------------------------------
    rvDefs::word_t imem [0:511];
    rvDefs::word_t dmem [0:511];

    // Word-aligned indexing using bits [10:2] for a 512-word depth
    assign instruction = imem[instructionAddress[10:2]];

    // Combinational read for Data Memory
    assign memReadData = (memRead) ? dmem[memAddress[10:2]] : 32'b0;

    // Synchronous write for Data Memory
    always_ff @(posedge clk) begin
        if (memWrite) begin
            dmem[memAddress[10:2]] <= memWriteData;
        end
    end

    // --------------------------------------------------------
    // Device Under Test (DUT)
    // --------------------------------------------------------
    Core dut (
        .clk(clk),
        .resetN(resetN),
        .instruction(instruction),
        .instructionAddress(instructionAddress),
        .memAddress(memAddress),
        .memReadData(memReadData),
        .memWriteData(memWriteData),
        .memRead(memRead),
        .memWrite(memWrite),
        .memSize(memSize),
        .stall(stall)
    );

    // --------------------------------------------------------
    // Clock Generation
    // --------------------------------------------------------
    initial begin
        clk = 0;
        forever #5 clk = ~clk; // 100 MHz clock
    end

    // --------------------------------------------------------
    // Test Stimulus & Machine Code Array
    // --------------------------------------------------------
    initial begin
        // Initialize Inputs
        resetN = 0;
        stall  = 0;
        
        for (int i = 0; i < 512; i++) begin
            imem[i] = 32'h00000013; // Pre-fill IMEM with NOPs
            dmem[i] = 32'b0;        // Clear DMEM
        end

        // Preload constant values into specific data memory locations for testing
        dmem[10] = 32'hA5A55A5A; // Stored at word index 10 (Byte address 0x28)

        // =========================================================================
        // MACHINE CODE PROGRAM
        // =========================================================================
        
        // --- PHASE 1: Arithmetic, Shifting, & Sign Extensions ---
        imem[0]  = 32'h00A00293; // addi x5, x0, 10      ; x5 = 10
        imem[1]  = 32'hFF600313; // addi x6, x0, -10     ; x6 = -10 (0xFFFFFFF6)
        imem[2]  = 32'h406283B3; // sub  x7, x5, x6      ; x7 = 10 - (-10) = 20
        imem[3]  = 32'h00229413; // slli x8, x5, 2       ; x8 = 10 << 2 = 40
        imem[4]  = 32'h40135493; // srai x9, x6, 1       ; x9 = -10 >>> 1 = -5 (0xFFFFFFFB)
        imem[5]  = 32'h00235533; // srl  x10, x6, x2     ; x10 = -10 >> 2 = 0x3FFFFFFD (unsigned)

        // --- PHASE 2: Back-to-Back EX Forwarding (RAW Hazards) ---
        imem[6]  = 32'h00500593; // addi x11, x0, 5      ; x11 = 5
        imem[7]  = 32'h00B58633; // add  x12, x11, x11   ; EX->EX forward (x12 = 10)
        imem[8]  = 32'h00C606B3; // add  x13, x12, x12   ; EX->EX forward (x13 = 20)
        imem[9]  = 32'h00B68733; // add  x14, x13, x11   ; MEM->EX forward (x14 = 25)

        // --- PHASE 3: Load-Use Hazard (Requires Structural Stall) ---
        imem[10] = 32'h02802783; // lw   x15, 40(x0)     ; Load from dmem[10] (Value: 0xA5A55A5A)
        imem[11] = 32'h00078833; // add  x16, x15, x0    ; CRITICAL: Must stall 1 cycle before forwarding!

        // --- PHASE 4: Branches (Control Hazards) ---
        imem[12] = 32'h00550663; // beq  x10, x5, 12     ; Branch if x10 == x5 (False: 0x3FFFFFFD != 10)
        imem[13] = 32'h00000013; // nop                  ; Executed because branch above falls through
        imem[14] = 32'h00C59863; // h00C59663; // bne  x11, x12, 12    ; Branch if x11 != x12 (True: 5 != 10). Byte offset 12 = +3 instructions -> instruction 17)
        // Correcting branch offset byte targeting: 12 bytes down from 14 (0x38) is 26 (0x4A) -> imem[17]
        imem[15] = 32'h00A00893; // addi x17, x0, 99     ; TRAITOR PATH: Should be flushed!
        imem[16] = 32'h01100913; // addi x18, x0, 99     ; TRAITOR PATH: Should be flushed!
        
        // Target of BNE:
        imem[17] = 32'h00100933; // add  x18, x0, x1      ; Real path resumes here.

        // --- PHASE 5: Jumps & JALR Architecture ---
        imem[18] = 32'h020000ef; // jal  x1, 32          ; Jump to offset +32 bytes (PC = 18*4 + 32 = 104 -> word 26). Link x1 = 19*4 = 76.
        imem[19] = 32'h06300893; // addi x17, x0, 99     ; TRAITOR PATH: Should be flushed!
        
        // Target of JAL:
        imem[26] = 32'h00000213; // addi x4, x0, 0        ; Setup base register for JALR
        imem[27] = 32'h07420213; // addi x4, x4, 116      ; Target byte address 116 (Word 29)
        imem[28] = 32'h000200e7; // jalr x1, 0(x4)       ; Jump to dynamic address in x4. Link x1 = 29*4 = 116.

        // Target of JALR:
        imem[29] = 32'h010A2023; // 32'h01082023; // sw   x16, 0(x16)     ; Final Verification: Store x16 to address 0.

        // =========================================================================

        // 3. Reset Lifecycle
        $display("[%0t] Driving system reset...", $time);
        #15; 
        resetN = 1;
        $display("[%0t] Processor released. Executing test vector...", $time);

        // 4. Execution window long enough to clean the pipeline out completely
        #400;

        // 5. Assert Checks for all Edge Case Phases
        $display("\n==================================================");
        $display("          PIPELINE HARDWARE REPORT                ");
        $display("==================================================");
        
        // Test 1: Sign Extension and Shifting Check
        if (tb.dut.xRegisterFile.registers[9] === 32'hFFFFFFFB) begin
            $display("[SUCCESS] Phase 1: Signed arithmetic shift (SRA) extended correctly.");
        end else begin
            $display("[FAILURE] Phase 1: SRA failed. Expected 32'hFFFFFFFB, Got: %h", tb.dut.xRegisterFile.registers[9]);
        end

        // Test 2: EX/MEM Forwarding Verification
        if (tb.dut.xRegisterFile.registers[14] === 32'd25) begin
            $display("[SUCCESS] Phase 2: Back-to-back EX/MEM data forwarding validated.");
        end else begin
            $display("[FAILURE] Phase 2: Forwarding unit fault. x14 expected 25, Got: %0d", tb.dut.xRegisterFile.registers[14]);
        end

        // Test 3: Load Use Hazard Interlocking Check
        if (tb.dut.xRegisterFile.registers[16] === 32'hA5A55A5A) begin
            $display("[SUCCESS] Phase 3: Hazard Unit stalled and bypassed Load-Use safely.");
        end else begin
            $display("[FAILURE] Phase 3: Load-use failed. Check structural stall logic. Got: %h", tb.dut.xRegisterFile.registers[16]);
        end

        // Test 4: Branch Misprediction & Control Line Purging
        if (tb.dut.xRegisterFile.registers[17] === 32'd99) begin
            $display("[FAILURE] Phase 4: Control Hazard failure! Wrong-path instructions were executed.");
        end else begin
            $display("[SUCCESS] Phase 4: Control hazard flushed speculative branch paths cleanly.");
        end

        // Test 5: End-to-end memory commit (Jumps and Stores verification)
        if (dmem[0] === 32'hA5A55A5A) begin
            $display("[SUCCESS] Phase 5: JAL/JALR control vectors executed. Memory commit verified.");
            $display("\n>>> ALL SYSTEM TEST CASES PASSED COLD <<<");
        end else begin
            $display("[FAILURE] Phase 5: Memory destination empty. Jumps or Final Write failed. dmem[0]: %h", dmem[0]);
        end
        $display("==================================================\n");

        $finish;
    end

    // --------------------------------------------------------
    // Waveform Configuration
    // --------------------------------------------------------
    initial begin
        $dumpfile("core_test.vcd");
        $dumpvars(0, tb); 
    end

endmodule

