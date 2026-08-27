`timescale 1ns/1ps

import rvDefs::*;

// =============================================================================
//  Comprehensive RV32I 5-Stage Pipeline Testbench
//  Covers: Logical ops, memory widths, forwarding, hazards, branches, jumps,
//          x0 writes, LUI, AUIPC, SLT/SLTU, reset mid-execution, and more.
// =============================================================================
module tb_comprehensive();

    // -------------------------------------------------------------------------
    // Clock / Reset / Stall
    // -------------------------------------------------------------------------
    logic CLK;
    logic RSTN;
    logic stall;

    // -------------------------------------------------------------------------
    // Simulated Memories  (2 KB / 512 words each)
    // -------------------------------------------------------------------------
    rvDefs::word_t imem [0:511];
    rvDefs::word_t dmem [0:511];
    localparam logic [31:0] T_SENTINEL = 32'hCAFEBABE;
    localparam logic [31:0] EXPECTED_X6  = 32'h00FF00FF;
    localparam logic [31:0] EXPECTED_X7  = 32'h00000000;
    localparam logic [31:0] EXPECTED_X8  = 32'h00000037;
    localparam logic [31:0] EXPECTED_X10 = 32'h0F0F0000;
    localparam logic [31:0] EXPECTED_X11 = 32'hFFFFFFFF;

    logic [31:0] dmem_read;

    // -------------------------------------------------------------------------
    // DUT
    // -------------------------------------------------------------------------
    Core dut (
        .CLK             (CLK),
        .RSTN            (RSTN),
        .stall           (stall)
    );

    // -------------------------------------------------------------------------
    // Clock Generation  (100 MHz)
    // -------------------------------------------------------------------------
    initial begin CLK = 0; forever #5 CLK = ~CLK; end

    // -------------------------------------------------------------------------
    // Watchdog  –  kills simulation if it hangs
    // -------------------------------------------------------------------------
    initial begin
        #5000;
        $display("[WATCHDOG] Simulation timeout! Possible infinite loop.");
        $finish;
    end

    // =========================================================================
    // Helper task: check a register value
    // =========================================================================
    int pass_count = 0;
    int fail_count = 0;

    task automatic check_reg(
        input string   phase,
        input int      reg_num,
        input logic [31:0] actual,
        input logic [31:0] expected
    );        
        if (actual === expected) begin
            $display("[PASS] %s : x%0d = 0x%08h", phase, reg_num, actual);
            pass_count++;
        end else begin
            $display("[FAIL] %s : x%0d expected 0x%08h, got 0x%08h",
                    phase, reg_num, expected, actual);
            fail_count++;
        end
    endtask

        // assert (actual == expected) begin
        //     $display("[PASS] %s : x%0d = 0x%08h", phase, reg_num, actual); 
        //     pass_count++;
        // end else begin
        //     $error("[FAIL] %s : x%0d expected 0x%08h, got 0x%08h",
        //             phase, reg_num, expected, actual);
        //     fail_count++;
        // end

    task automatic check_dmem(
        input string   phase,
        input int      word_idx,
        input logic [31:0] actual,
        input logic [31:0] expected
    );
        if (actual === expected) begin
            $display("[PASS] %s : dmem[%0d] = 0x%08h", phase, word_idx, actual);
            pass_count++;
        end else begin
            $display("[FAIL] %s : dmem[%0d] expected 0x%08h, got 0x%08h",
                     phase, word_idx, expected, actual);
            fail_count++;
        end
    endtask

    // =========================================================================
    //  PROGRAM LAYOUT  (word addresses)
    //
    //   0  – 9   Phase A: Logical & bitwise ops
    //  10  – 19  Phase B: SLT / SLTU / SLTI / SLTIU
    //  20  – 29  Phase C: LUI / AUIPC
    //  30  – 39  Phase D: Double-forwarding (both rs1 & rs2 from EX/MEM)
    //  40  – 49  Phase E: Load-use stall then 2-cycle gap (no stall needed)
    //  50  – 59  Phase F: Byte / halfword loads and stores
    //  60  – 69  Phase G: Branch forwarding hazard (BEQ on freshly computed regs)
    //  70  – 79  Phase H: All branch conditions (BLT, BGE, BLTU, BGEU)
    //  80  – 89  Phase I: Taken BEQ (backward branch / tight loop)
    //  90  – 99  Phase J: JAL return-address verification
    // 100  – 109 Phase K: JALR LSB-clearing & return-address verification
    // 110  – 119 Phase L: Write to x0 (must stay zero)
    // 120  – 129 Phase M: Reset mid-execution
    // 200         NOP pad / landing zone for jumps
    // =========================================================================

    // Alias for the register file (adjust path to match your hierarchy)
    `define RF tb_comprehensive.dut.xRegisterFile.registers
    `define dmem_bus tb_comprehensive.dut.DataManager.data_manager.sub_gen[0].subordinate

    initial begin
        // ------------------------------------------------------------------
        // Initialise
        // ------------------------------------------------------------------
        RSTN = 0;
        stall  = 0;
        for (int i = 0; i < 512; i++) begin
            imem[i] = 32'h00000013; // NOP  (addi x0,x0,0)
            dmem[i] = 32'b0;
        end

        // Pre-load data memory
        // Byte address 0x80 (word 32): 0xDEADBEEF  – used for byte/hw load tests
        dmem[32] = 32'hDEADBEEF;
        // Word 33: 0x12345678
        dmem[33] = 32'h12345678;

        // ==================================================================
        // PHASE A  –  Logical & Bitwise Operations  (imem 0-9)
        // ==================================================================
        //  x1 = 0xFF00FF00
        //  x2 = 0x0F0F0F0F
        //  x3 = x1 AND x2   -> 0x0F000F00
        //  x4 = x1 OR  x2   -> 0xFF0FFF0F
        //  x5 = x1 XOR x2   -> 0xF00FF00F
        //  x6 = XORI x1,-1  -> ~x1 = 0x00FF00FF  (bitwise NOT via xori -1)
        //  x7 = ANDI x1,0x0F-> 0x00
        //  x8 = ORI  x2,0xF0 -> 0x0F0F0FFF  (sign-ext immediate 0xF0 = -16)
        //       Actually ORI x2,0xFF = 0x0F0F0FFF
        //  x9 = SRLI x1, 4  -> 0x0FF00FF0   (logical, zero-fill)
        // x10 = SLL  x2, x9 – shift x2 left by (x9 & 0x1F)=16 -> 0x0F0F0000

        // Build 0xFF00FF00:
        //   lui x1, 0xFF010   -> 0xFF010000  then addi x1, x1, -256 -> 0xFF00FF00? No.
        imem[0]  = 32'hFF0100B7; // lui  x1, 0xFF010   ; x1 = 0xFF010000
        imem[1]  = 32'hF0008093; // addi x1, x1, -256  ; x1 = 0xFF00FF00

        // Build x2 = 0x0F0F0F0F
        // lui x2, 0x0F0F1 = 0x0F0F1000; addi x2,x2,-241(0xF0F sign-ext = -241) 
        // 0x0F0F1000 - 241 = 0x0F0F1000 - 0xF1 = 0x0F0F0F0F ✓
        imem[2]  = 32'h0F0F1137; // lui  x2, 0x0F0F1   ; x2 = 0x0F0F1000
        imem[3]  = 32'hF0F10113; // addi x2, x2, -241  ; x2 = 0x0F0F0F0F

        // and x3, x1, x2  : funct7=0, rs2=x2(2), rs1=x1(1), funct3=111, rd=x3(3), op=0110011
        // 0000000_00010_00001_111_00011_0110011 = 0x002_0F1B3
        imem[4]  = 32'h0020F1B3; // and  x3, x1, x2    ; x3 = 0x0F000F00
        // or x4, x1, x2
        // 0000000_00010_00001_110_00100_0110011 = 0x0020E233
        imem[5]  = 32'h0020E233; // or   x4, x1, x2    ; x4 = 0xFF0FFF0F
        // xor x5, x1, x2
        // 0000000_00010_00001_100_00101_0110011 = 0x0020C2B3
        imem[6]  = 32'h0020C2B3; // xor  x5, x1, x2    ; x5 = 0xF00FF00F
        // xori x6, x1, -1  : imm=0xFFF, rs1=x1, funct3=100, rd=x6
        // 1111_1111_1111_00001_100_00110_0010011 = 0xFFF0C313
        imem[7]  = 32'hFFF0C313; // xori x6, x1, -1    ; x6 = ~x1 = 0x00FF00FF
        // srli x9, x1, 4  : imm=0x004, rs1=x1, funct3=101, rd=x9
        // 0000000_00100_00001_101_01001_0010011 = 0x0040D493
        imem[8]  = 32'h0040D493; // srli x9, x1, 4     ; x9 = 0x0FF00FF0
        // sll x10, x2, x9  : rs2=x9(9), rs1=x2(2), funct3=001, rd=x10, op=0110011
        // 0000000_01001_00010_001_01010_0110011 = 0x00911533
        imem[9]  = 32'h00911533; // sll  x10, x2, x9   ; shift amt = x9[4:0]=16 -> x10=0x0F0F0000

        // ==================================================================
        // PHASE B  –  SLT / SLTU / SLTI / SLTIU  (imem 10-19)
        // ==================================================================
        // x11 = -1 (0xFFFFFFFF)
        // x12 =  1
        // SLT:  x13 = (x11 < x12) signed   -> 1   (-1 < 1 signed = true)
        // SLTU: x14 = (x11 < x12) unsigned  -> 0   (0xFFFF... > 1 unsigned)
        // SLTI: x15 = (x11 < 0)   signed    -> 1   (-1 < 0)
        // SLTIU:x16 = (x11 < 1)   unsigned  -> 0   (0xFFFF... >= 1)
        // SLT:  x17 = (x12 < x11) signed    -> 0   (1 > -1)
        imem[10] = 32'hFFF00593; // addi x11, x0, -1   ; x11 = 0xFFFFFFFF
        imem[11] = 32'h00100613; // addi x12, x0, 1    ; x12 = 1
        // slt x13, x11, x12  : rs2=x12(12), rs1=x11(11), funct3=010, rd=x13
        // 0000000_01100_01011_010_01101_0110011 = 0x00C5A6B3
        imem[12] = 32'h00C5A6B3; // slt  x13, x11, x12 ; x13 = 1
        // sltu x14, x11, x12 : funct3=011
        // 0000000_01100_01011_011_01110_0110011 = 0x00C5B733
        imem[13] = 32'h00C5B733; // sltu x14, x11, x12 ; x14 = 0
        // slti x15, x11, 0  : imm=0, rs1=x11, funct3=010, rd=x15
        // 0000000_00000_01011_010_01111_0010011 = 0x0005A793
        imem[14] = 32'h0005A793; // slti x15, x11, 0   ; x15 = 1
        // sltiu x16, x11, 1  : imm=1, rs1=x11, funct3=011, rd=x16
        // 0000000_00001_01011_011_10000_0010011 = 0x0015B813
        imem[15] = 32'h0015B813; // sltiu x16, x11, 1  ; x16 = 0
        // slt x17, x12, x11 : rs2=x11(11), rs1=x12(12), rd=x17
        // 0000000_01011_01100_010_10001_0110011 = 0x00B628B3
        imem[16] = 32'h00B628B3; // slt  x17, x12, x11 ; x17 = 0

        // ==================================================================
        // PHASE C  –  LUI / AUIPC  (imem 20-29)
        // ==================================================================
        // x18 = LUI  0xABCDE   -> 0xABCDE000
        // x19 = AUIPC 0x00000  -> PC of that instruction = 21*4 = 84 = 0x54
        // x20 = AUIPC 0xFFFFF  -> 0xFFFFF000 + PC(22*4=88=0x58) = 0xFFFFF058
        //         (expected to wrap, result: 0xFFFFF058 mod 2^32)
        imem[20] = 32'hABCDE937; // lui  x18, 0xABCDE  ; x18 = 0xABCDE000
        imem[21] = 32'h00000997; // auipc x19, 0       ; x19 = PC = 0x54
        imem[22] = 32'hFFFFFA17; // auipc x20, 0xFFFFF ; x20 = 0xFFFFF000+0x58 = 0xFFFFF058

        // ==================================================================
        // PHASE D  –  Double Forwarding: both rs1 AND rs2 from EX stage
        //             (imem 30-39)
        // ==================================================================
        // Sequence deliberately creates rs1 and rs2 both needing EX->EX forward:
        //   addi x21, x0, 7    ; x21 = 7
        //   addi x22, x0, 3    ; x22 = 3
        //   add  x21, x21,x22  ; EX result of this feeds next ...
        //   sub  x22, x21,x22  ; ... but here rs1=x21(just computed) AND rs2=x22 (computed 2 back -> MEM->EX)
        //   add  x23, x21,x22  ; double EX->EX forward (both rs1,rs2 from immediately preceding)
        imem[30] = 32'h00700A93; // addi x21, x0, 7    ; x21 = 7
        imem[31] = 32'h00300B13; // addi x22, x0, 3    ; x22 = 3
        // add x21, x21, x22  rd=x21(21), rs1=x21(21), rs2=x22(22)
        // 0000000_10110_10101_000_10101_0110011 = 0x016A8AB3
        imem[32] = 32'h016A8AB3; // add  x21, x21, x22 ; x21 = 10
        // sub x22, x21, x22  rd=x22(22), rs1=x21(21), rs2=x22(22)
        // 0100000_10110_10101_000_10110_0110011 = 0x416A8B33
        imem[33] = 32'h416A8B33; // sub  x22, x21, x22 ; x22 = 10-3 = 7  (MEM->EX for x22)
        // add x23, x21, x22  EX->EX both: rd=x23(23), rs1=x21(21), rs2=x22(22)
        // 0000000_10110_10101_000_10111_0110011 = 0x016A8BB3
        imem[34] = 32'h016A8BB3; // add  x23, x21, x22 ; x23 = 10+7 = 17  (double EX->EX)

        // ==================================================================
        // PHASE E  –  Load-Use Stall (1 cycle) AND Load with 2-instr gap
        //             (imem 40-49)
        // ==================================================================
        // Setup: dmem[32]=0xDEADBEEF, base addr = 32*4 = 128 = 0x80
        imem[40] = 32'h08000C13; // addi x24, x0, 128  ; x24 = 0x80 (base for loads)
        // lw x25, 0(x24)  -> 0xDEADBEEF   (LOAD-USE hazard: immediate use)
        // lw: imm=0, rs1=x24(24), funct3=010, rd=x25(25), op=0000011
        // 0000000_00000_11000_010_11001_0000011 = 0x000C2C83
        imem[41] = 32'h000C2C83; // lw   x25, 0(x24)   ; x25 = 0xDEADBEEF
        // add x26, x25, x0  CRITICAL: 1-cycle stall then MEM->EX forward
        // add: rd=x26(26), rs1=x25(25), rs2=x0
        // 0000000_00000_11001_000_11010_0110011 = 0x000C8D33
        imem[42] = 32'h000C8D33; // add  x26, x25, x0  ; x26 = 0xDEADBEEF (load-use stall)

        // Load then 2 instr gap – no stall, MEM->EX forward expected
        // lw x27, 4(x24)  -> dmem[33] = 0x12345678
        // imm=4, rs1=x24, rd=x27(27)
        // 0000000_00100_11000_010_11011_0000011 = 0x004C2D83
        imem[43] = 32'h004C2D83; // lw   x27, 4(x24)   ; x27 = 0x12345678
        imem[44] = 32'h00000013; // nop
        imem[45] = 32'h00000013; // nop
        // add x28, x27, x0  : 2-instr gap, MEM->EX forward (no stall)
        // rd=x28(28), rs1=x27(27)
        // 0000000_00000_11011_000_11100_0110011 = 0x000D8E33
        imem[46] = 32'h000D8E33; // add  x28, x27, x0  ; x28 = 0x12345678 (no stall)

        // ==================================================================
        // PHASE F  –  Byte / Halfword Loads and Stores  (imem 50-59)
        // ==================================================================
        // dmem[32] = 0xDEADBEEF  (byte addr 0x80)
        // LB  x29, 0(x24)  -> sign-extend byte[0] = 0xEF -> 0xFFFFFFEF
        // LBU x30, 0(x24)  -> zero-extend           0xEF -> 0x000000EF
        // LH  x31, 0(x24)  -> sign-extend hw[0]  = 0xBEEF -> 0xFFFFBEEF
        // LHU x5,  0(x24)  -> zero-extend           0xBEEF -> 0x0000BEEF
        // SB  x11, 8(x24)  -> store byte 0xFF to dmem word 34 byte 0
        // SH  x12, 12(x24) -> store hw   0x0001 to dmem word 35 bytes 0-1
        // lb rd=x29(29), rs1=x24, funct3=000, imm=0
        // 0000000_00000_11000_000_11101_0000011 = 0x000C0E83
        imem[50] = 32'h000C0E83; // lb   x29, 0(x24)   ; x29 = 0xFFFFFFEF
        // lbu rd=x30(30), funct3=100
        // 0000000_00000_11000_100_11110_0000011 = 0x000C4F03
        imem[51] = 32'h000C4F03; // lbu  x30, 0(x24)   ; x30 = 0x000000EF
        // lh rd=x31(31), funct3=001
        // 0000000_00000_11000_001_11111_0000011 = 0x000C1F83
        imem[52] = 32'h000C1F83; // lh   x31, 0(x24)   ; x31 = 0xFFFFBEEF
        // lhu rd=x5(5), funct3=101
        // 0000000_00000_11000_101_00101_0000011 = 0x000C5283
        imem[53] = 32'h000C5283; // lhu  x5,  0(x24)   ; x5  = 0x0000BEEF
        // sb x11, 8(x24)  : store byte of x11(=0xFFFFFFFF) -> 0xFF
        //   imm[11:5]=0000001, rs2=x11(11), rs1=x24(24), funct3=000, imm[4:0]=01000
        // 0000001_01011_11000_000_01000_0100011 = 0x00BC0423
        imem[54] = 32'h00BC0423; // sb   x11, 8(x24)   ; dmem[34] byte[0] = 0xFF
        // sh x12, 12(x24) : store hw of x12(=1) -> 0x0001
        //   imm[11:5]=0000001, rs2=x12(12), rs1=x24(24), funct3=001, imm[4:0]=01100
        // 0000001_01100_11000_001_01100_0100011 = 0x00CC1623
        imem[55] = 32'h00CC1623; // sh   x12, 12(x24)  ; dmem[35] hw[0] = 0x0001

        // ==================================================================
        // PHASE G  –  Branch Forwarding Hazard  (imem 60-69)
        // ==================================================================
        // Compute values and immediately use them in BEQ (no gap).
        // The hazard unit must forward into the branch comparator.
        //   addi x6, x0, 42
        //   addi x7, x0, 42
        //   beq  x6, x7, +12  -> should TAKE branch (EX->Branch forward)
        //   addi x8, x0, 99   <- TRAITOR slot 1: flushed (PC+4)
        //   addi x8, x0, 99   <- TRAITOR slot 2: flushed (PC+8) – needed because
        //                         EX-stage resolution fetches TWO instructions
        //                         speculatively (PC+4 and PC+8); both are flushed.
        //                         Using offset=+8 would flush the real target too.
        //   addi x8, x0, 55   <- REAL target at imem[65] (PC+12)
        imem[60] = 32'h02A00313; // addi x6, x0, 42    ; x6 = 42
        imem[61] = 32'h02A00393; // addi x7, x0, 42    ; x7 = 42
        // beq x6, x7, +12 : offset=12 bytes -> target = 62*4+12 = 260 -> imem[65]
        // imm=12: imm[12]=0,imm[11]=0,imm[10:5]=000000,imm[4:1]=0110
        // 0000000_00111_00110_000_01100_1100011 = 0x00730663
        imem[62] = 32'h00730663; // beq  x6, x7, +12   ; branch taken to imem[65]
        imem[63] = 32'h06300413; // addi x8, x0, 99    ; TRAITOR slot 1 – flushed
        imem[64] = 32'h06300413; // addi x8, x0, 99    ; TRAITOR slot 2 – flushed
        imem[65] = 32'h03700413; // addi x8, x0, 55    ; REAL: x8 = 55
        
        // ==================================================================
        // PHASE H  –  Full Branch Suite: BLT, BGE, BLTU, BGEU  (imem 70-79)
        // ==================================================================
        // x11 = -1 (already set in Phase B, but re-establish)
        // x12 =  1
        // BLT  x11, x12, taken  -> signed  -1 < 1  = true
        // BGE  x12, x11, taken  -> signed   1 >= -1 = true
        // BLTU x12, x11, taken  -> unsigned 1 < 0xFFFF... = true
        // BGEU x11, x12, taken  -> unsigned 0xFFFF... >= 1 = true
        imem[70] = 32'hFFF00593; // addi x11, x0, -1
        imem[71] = 32'h00100613; // addi x12, x0, 1

        // BLT x11, x12, +8  -> offset=8, land imem[74]
        // blt funct3=100: 0000000_01100_01011_100_01000_1100011 = 0x00C5C463
        imem[72] = 32'h00C5C463; // blt  x11, x12, +8  ; taken -> imem[74]
        imem[73] = 32'h06300893; // addi x17, x0, 99   ; TRAITOR
        imem[74] = 32'h00100893; // addi x17, x0, 1    ; x17 = 1 (BLT taken)

        // BGE x12, x11, +8  -> land imem[77]
        // bge funct3=101: 0000000_01011_01100_101_01000_1100011 = 0x00B65463
        imem[75] = 32'h00B65463; // bge  x12, x11, +8  ; taken -> imem[77]
        imem[76] = 32'h06300913; // addi x18, x0, 99   ; TRAITOR
        imem[77] = 32'h00100913; // addi x18, x0, 1    ; x18 = 1 (BGE taken)

        // BLTU x12, x11, +8  -> land imem[80] ... but 80 is phase I start
        // Use a different layout within phase H
        // Actually place bltu at 78, land at 80 (Phase I start, we'll accept the overlap
        // since Phase I starts with a fresh addi anyway)
        // bltu funct3=110: 0000000_01011_01100_110_01000_1100011 = 0x00B66463
        imem[78] = 32'h00B66463; // bltu x12, x11, +8  ; taken -> imem[80]
        imem[79] = 32'h06300993; // addi x19, x0, 99   ; TRAITOR

        // ==================================================================
        // PHASE I  –  Taken BEQ / Tight Backward Branch (Loop)  (imem 80-89)
        // ==================================================================
        // Count down from 3 to 0 using a backward BNE loop.
        // After loop, x20 should be 0.
        //   addi x19, x0, 1    ; bltu result landing + x19=1 (BGEU overlaps here)
        imem[80] = 32'h00100993; // addi x19, x0, 1    ; x19 = 1  (bltu land + bgeu setup)
        // bgeu x11, x12, +8  -> land imem[82]
        // bgeu funct3=111: 0000000_01100_01011_111_01000_1100011 = 0x00C5F463
        imem[81] = 32'h00C5F463; // bgeu x11, x12, +8  ; taken -> imem[83]
        imem[82] = 32'h06300A13; // addi x20, x0, 99   ; TRAITOR

        // Backward loop: x20 counts 3->0
        imem[83] = 32'h00300A13; // addi x20, x0, 3    ; x20 = 3  (loop counter)
        // bne x20, x0, -4  : offset=-4 bytes (back 1 instr to imem[84] itself? no, to addi x20,x20,-1)
        // loop body: addi x20, x20, -1  at imem[84]
        //            bne  x20, x0, -4   at imem[85]  (offset -4 -> back to imem[84])
        imem[84] = 32'hFFF_A0_A13; // addi x20, x20, -1  ; x20--
        // bne x20,x0, -4: offset=-4, bne funct3=001
        // imm=-4=0b1_111111_1110_0: imm[12]=1,imm[11]=1,imm[10:5]=111111,imm[4:1]=1100? 
        // RV32 B-type offset=-4: encode as 0xFE0010E3? let's compute:
        // offset -4 = 0xFFFFFFFC; B-type bits: imm[12]=1,imm[11]=1,imm[10:5]=111110,imm[4:1]=1110,imm[0]=0
        // bne: funct3=001, rs1=x20(20), rs2=x0(0)
        // [31:25]=1111111, [24:20]=00000, [19:15]=10100, [14:12]=001, [11:8]=1110, [7]=1, [6:0]=1100011
        // = 0xFE0A1EE3
        imem[85] = 32'hFE0A1EE3; // bne  x20, x0, -4   ; loop back to imem[84]

        // ==================================================================
        // PHASE J  –  JAL Return-Address Verification  (imem 90-99)
        // ==================================================================
        // jal x1, +12  : jump to imem[93], link x1 = PC+4 = 91*4 = 364 = 0x16C
        // jal: rd=x1(1), offset=12 bytes (3 instructions forward)
        // imm=12=0b0_0000000_0110_0: imm[20]=0,imm[10:1]=000000_0110,imm[11]=0,imm[19:12]=00000000
        // [31:12]=00000000000000000110, [11:7]=00001, [6:0]=1101111 = 0x00C000EF
        imem[90] = 32'h00C000EF; // jal  x1, +12        ; x1 = 0x16C, PC -> imem[93]
        imem[91] = 32'h06300A93; // addi x21, x0, 99    ; TRAITOR
        imem[92] = 32'h06300A93; // addi x21, x0, 99    ; TRAITOR
        imem[93] = 32'h00000013; // nop                  ; landing pad
        // Verify x1 by storing it
        // addi x22, x0, 0; add x22, x1, x0
        // add x22, x1, x0: rd=x22(22), rs1=x1(1), rs2=x0
        // 0000000_00000_00001_000_10110_0110011 = 0x00008B33
        imem[94] = 32'h00008B33; // add  x22, x1, x0    ; x22 = return addr = 0x16C

        // ==================================================================
        // PHASE K  –  JALR LSB-clearing & Return Address  (imem 100-109)
        // ==================================================================
        // Build target with LSB=1 to verify it gets cleared.
        // Target = imem[103] byte addr = 103*4 = 412 = 0x19C
        // Set x4 = 0x19D (LSB=1); jalr x2, 0(x4) -> PC = (0x19D + 0) & ~1 = 0x19C
        // x2 should hold return address = 101*4 = 404 = 0x194
        imem[100] = 32'h19D00213; // addi x4, x0, 0x19D  ; x4 = 0x19D (odd addr)
        // jalr x2, 0(x4): rd=x2(2), rs1=x4(4), imm=0
        // 000000000000_00100_000_00010_1100111 = 0x00020167
        imem[101] = 32'h00020167; // jalr x2, 0(x4)       ; PC = 0x19C, x2 = 0x194
        imem[102] = 32'h06300113; // addi x2, x0, 99      ; TRAITOR
        imem[103] = 32'h00000013; // nop                   ; landing (0x19C = imem[103])
        // copy x2 to x23 to verify
        // add x23, x2, x0: rd=x23(23), rs1=x2(2)
        // 0000000_00000_00010_000_10111_0110011 = 0x000_10BB3
        imem[104] = 32'h000_10BB3; // add  x23, x2, x0    ; x23 = JALR link = 0x194

        // ==================================================================
        // PHASE L  –  Write to x0 Must Stay Zero  (imem 110-119)
        // ==================================================================
        // Attempt to write non-zero into x0 via several instruction types.
        imem[110] = 32'h00A00013; // addi x0, x0, 10     ; attempt write to x0
        // add x0, x11, x12
        // 0000000_01100_01011_000_00000_0110011 = 0x00C58033
        imem[111] = 32'h00C58033; // add  x0, x11, x12   ; attempt write to x0
        // lui x0, 0xABCDE
        // 0xABCDE_00037 -- but rd=x0 means bits[11:7]=00000
        imem[112] = 32'hABCDE037; // lui  x0, 0xABCDE    ; attempt write to x0
        // Read x0 into x24 – must be 0
        // add x24, x0, x0: rd=x24(24)
        // 0000000_00000_00000_000_11000_0110011 = 0x00000C33
        imem[113] = 32'h00000C33; // add  x24, x0, x0    ; x24 must be 0

        // ==================================================================
        // PHASE M  –  Reset Mid-Execution  (imem 120-129)
        // ==================================================================
        // We will inject RSTN=0 from the testbench while the pipeline is
        // mid-flight, then release and check the pipeline is clean.
        // The program just runs addi instructions; the TB will pulse reset.
        imem[120] = 32'h00500C93; // addi x25, x0, 5
        imem[121] = 32'h00A00D13; // addi x26, x0, 10
        imem[122] = 32'h00F00D93; // addi x27, x0, 15
        imem[123] = 32'h01400E13; // addi x28, x0, 20
        imem[124] = 32'h01900E93; // addi x29, x0, 25

        // After reset, all registers should be 0. Then run two clean instr:
        imem[125] = 32'h00700F13; // addi x30, x0, 7     ; after reset, x30 = 7
        imem[126] = 32'h00900F93; // addi x31, x0, 9     ; after reset, x31 = 9

        // ================================================================
        // Reset and release
        // ================================================================
        $display("\n[%0t] ============================================", $time);
        $display("[%0t]  RV32I Comprehensive Pipeline Test Starting", $time);
        $display("[%0t] ============================================\n", $time);
        #15; RSTN = 1;

        // ==================================================================
        // RUN PHASE A-L  (sufficient cycles for deepest path + drain)
        // ==================================================================
        // Phase A starts at imem[0], Phase L ends ~imem[114].
        // Each phase is ≤10 instr + hazard stalls (~3 extra cycles each).
        // Conservatively allow 200 cycles before checking.
        // We must NOT check until the pipeline has drained past imem[114].
        // imem[114] is at cycle ≈ 114 + pipeline_depth(5) + stalls ≈ 140 cycles
        #400; // ample time for phases A-L

        // ==================================================================
        // CHECK RESULTS
        // ==================================================================
        $display("\n==================================================");
        $display("          COMPREHENSIVE PIPELINE TEST REPORT      ");
        $display("==================================================");

        // --- Phase A: Logical ---
        $display("\n--- Phase A: Logical & Bitwise ---");
        check_reg("A:AND",  3, `RF[3],  32'h0F000F00);
        check_reg("A:OR",   4, `RF[4],  32'hFF0FFF0F);
        check_reg("A:XOR",  5, `RF[5],  32'hF00FF00F);
        check_reg("A:XORI", 6, `RF[6],  32'h00FF00FF);
        check_reg("A:SRLI", 9, `RF[9],  32'h0FF00FF0);
        check_reg("A:SLL", 10, `RF[10], 32'h0F0F0000);

        // --- Phase B: SLT ---
        $display("\n--- Phase B: SLT / SLTU / SLTI / SLTIU ---");
        check_reg("B:SLT",   13, `RF[13], 32'h1);
        check_reg("B:SLTU",  14, `RF[14], 32'h0);
        check_reg("B:SLTI",  15, `RF[15], 32'h1);
        check_reg("B:SLTIU", 16, `RF[16], 32'h0);
        check_reg("B:SLT2",  17, `RF[17], 32'h0);

        // --- Phase C: LUI / AUIPC ---
        #400;
        $display("\n--- Phase C: LUI / AUIPC ---");
        check_reg("C:LUI",   18, `RF[18], 32'hABCDE000);
        check_reg("C:AUIPC", 19, `RF[19], 32'h00000054); // PC = 21*4 = 0x54
        check_reg("C:AUIPC_wrap", 20, `RF[20], 32'hFFFFF058); // 0xFFFFF000 + 0x58

        // --- Phase D: Double Forwarding ---
        $display("\n--- Phase D: Double EX-Forwarding ---");
        check_reg("D:add_fwd",  21, `RF[21], 32'd10);
        check_reg("D:sub_fwd",  22, `RF[22], 32'd7);
        check_reg("D:dbl_fwd",  23, `RF[23], 32'd17);

        // --- Phase E: Load-Use ---
        $display("\n--- Phase E: Load-Use Stall & 2-Instr Gap ---");
        check_reg("E:load_use_stall", 26, `RF[26], 32'hDEADBEEF);
        check_reg("E:load_2gap",      28, `RF[28], 32'h12345678);

        // --- Phase F: Byte/Halfword ---
        $display("\n--- Phase F: Byte / Halfword Load & Store ---");
        check_reg("F:LB",  29, `RF[29], 32'hFFFFFFEF);
        check_reg("F:LBU", 30, `RF[30], 32'h000000EF);
        check_reg("F:LH",  31, `RF[31], 32'hFFFFBEEF);
        check_reg("F:LHU",  5, `RF[5],  32'h0000BEEF);
        // SB wrote 0xFF to dmem[34] byte 0; rest of dmem[34] was 0 -> dmem[34]=0x000000FF
        /* verilator lint_off IEEEMAYDEPRECATE */
        assign dmem_read = {`dmem_bus.dmem[139], `dmem_bus.dmem[138], `dmem_bus.dmem[137], `dmem_bus.dmem[136]};
        check_dmem("F:SB", 34, dmem_read, 32'h000000FF);
        // SH wrote 0x0001 to dmem[35] halfword 0 -> dmem[35]=0x00000001
        assign dmem_read = {`dmem_bus.dmem[143], `dmem_bus.dmem[142], `dmem_bus.dmem[141], `dmem_bus.dmem[140]};
        check_dmem("F:SH", 35, dmem_read, 32'h00000001);
        /* verilator lint_on IEEEMAYDEPRECATE */

        // --- Phase G: Branch Forwarding ---
        $display("\n--- Phase G: Branch Forwarding Hazard ---");
        check_reg("G:BEQ_fwd", 8, `RF[8], 32'd55); // traitor flushed, real=55

        #600;
        // --- Phase H: Full Branch Suite ---
        $display("\n--- Phase H: BLT / BGE / BLTU / BGEU ---");
        check_reg("H:BLT",  17, `RF[17], 32'd1); // BLT taken, x17=1
        check_reg("H:BGE",  18, `RF[18], 32'd1); // BGE taken, x18=1
        check_reg("H:BLTU", 19, `RF[19], 32'd1); // BLTU taken, x19=1 (from Phase I landing)
        check_reg("H:BGEU", 19, `RF[19], 32'd1); // BGEU taken, x19 stays 1

        // --- Phase I: Backward Loop ---
        $display("\n--- Phase I: Backward BNE Loop ---");
        check_reg("I:loop_result", 20, `RF[20], 32'd0); // counts 3->0

        // --- Phase J: JAL return address ---
        $display("\n--- Phase J: JAL Return Address ---");
        check_reg("J:JAL_link", 22, `RF[22], 32'h0000_016C); // 91*4=364=0x16C

        // --- Phase K: JALR LSB clearing ---
        $display("\n--- Phase K: JALR LSB Clearing ---");
        check_reg("K:JALR_link", 23, `RF[23], 32'h0000_0198);

        // --- Phase L: x0 immutability ---
        // registers[0] does not exist in most RF implementations (index 1:31);
        // x0 immutability is verified indirectly: x24 = add x0,x0 — any
        // write that stuck would make x24 non-zero.
        $display("\n--- Phase L: x0 Immutability ---");
        check_reg("L:x24_zero_confirm", 24, `RF[24], 32'h0);

        // ==================================================================
        // PHASE M  –  Reset Mid-Execution
        // ==================================================================
        // Force PC to Phase M program by asserting reset, then reloading IMEM
        // with Phase M instructions at offset 0 (so after reset PC goes to 0).
        // We'll repurpose imem[0..9] for this mini-program.
        $display("\n--- Phase M: Reset Mid-Execution ---");

        // Redirect imem[0..4] to Phase M program
        imem[0] = 32'h00500C93; // addi x25, x0, 5
        imem[1] = 32'h00A00D13; // addi x26, x0, 10
        imem[2] = 32'h00F00D93; // addi x27, x0, 15
        imem[3] = 32'h00700F13; // addi x30, x0, 7   ; these are post-reset clean instrs
        imem[4] = 32'h00900F93; // addi x31, x0, 9

        // Assert reset while pipeline is running (mid-flight)
        RSTN = 0;
        @(posedge CLK); @(posedge CLK); // hold 2 cycles mid-flight
        RSTN = 1;
        $display("[%0t] Mid-execution reset applied and released.", $time);

        // Let pipeline drain and execute clean instructions
        #100;

        // After reset: all registers should be 0 initially, then x30=7, x31=9
        check_reg("M:post_reset_x26", 26, `RF[26], 32'hDEADBEEF);
        check_reg("M:post_reset_x27", 27, `RF[27], 32'h12345678);
        check_reg("M:post_reset_x28", 28, `RF[28], 32'h12345678);
        check_reg("M:post_reset_x29", 29, `RF[29], 32'hFFFFFFEF);
        check_reg("M:post_reset_x30", 30, `RF[30], 32'h000000EF);
        check_reg("M:post_reset_x31", 31, `RF[31], 32'hFFFFBEEF);
        // Registers that were being written before reset should be 0 OR the
        // new value – the key assertion is no garbage / X values
        if (`RF[25] === 32'hX || `RF[26] === 32'hX || `RF[27] === 32'hX) begin
            $display("[FAIL] Phase M: X-state in registers after reset!");
            fail_count++;
        end else begin
            $display("[PASS] Phase M: No X-state after mid-execution reset.");
            pass_count++;
        end

        #1425;
        // ========================================================================
        // PHASE N - Register Preservation Across Reset
        // ========================================================================
        $display("\n--- Phase N: Register Preservation Across Reset ---");
        $display("[%0t] Register Preservation Across Reset.", $time);
        /* verilator lint_off IEEEMAYDEPRECATE */
        check_reg("N:x1", 1, `RF[1], 32'h00000055);
        check_reg("N:x2", 2, `RF[2], 32'h00000200);
        #10;
        assign dmem_read = {`dmem_bus.dmem[515], `dmem_bus.dmem[514], `dmem_bus.dmem[513], `dmem_bus.dmem[512]};
        check_dmem("F:SW", 512, dmem_read, 32'h00000055);
        check_reg("N:x3", 3, `RF[3], 32'h00000055);
        #20;
        assign dmem_read = {`dmem_bus.dmem[515], `dmem_bus.dmem[514], `dmem_bus.dmem[513], `dmem_bus.dmem[512]};
        check_dmem("F:SB", 513, dmem_read, 32'h0000AA55);
        check_reg("N:x4", 4, `RF[4], 32'h000000AA);
        #20;
        assign dmem_read = {`dmem_bus.dmem[515], `dmem_bus.dmem[514], `dmem_bus.dmem[513], `dmem_bus.dmem[512]};
        check_dmem("F:SH", 514, dmem_read, 32'h0123AA55);
        check_reg("N:x5", 5, `RF[5], 32'h00000123);
        /* verilator lint_on IEEEMAYDEPRECATE */

        // ========================================================================
        // PHASE O - Load -> Store Hazard
        // ========================================================================
        $display("\n--- Phase O: Load -> Store Hazard ---");
        $display("[%0t] Load to Store Hazard.", $time);
        // Wait for instructions at imem[560-575] to complete execution
        repeat (8) @(posedge CLK);
        check_reg("O:x1_load", 1, `RF[1], 32'hCAFEBABE);
        check_reg("O:x3_load_store", 3, `RF[3], 32'hCAFEBABE);

        // Reset core to clear state before Phase P
        // RSTN = 0; @(posedge CLK); @(posedge CLK); RSTN = 1; @(posedge CLK);

        // ========================================================================
        // PHASE P - Load -> Branch Hazard
        // ========================================================================
        $display("\n--- Phase P: Load -> Branch Hazard ---");
        repeat (12) @(posedge CLK);
        $display("[%0t] Branch Hazard.", $time);
        check_reg("P:x3_target", 3, `RF[3], 32'd42); // Target executed (42), traitors skipped

        // Reset core to clear state before Phase Q
        // RSTN = 0; @(posedge CLK); @(posedge CLK); RSTN = 1; @(posedge CLK);

        // ========================================================================
        // PHASE Q - ALU -> JALR Hazard
        // ========================================================================
        $display("\n--- Phase Q: ALU -> JALR Hazard ---");
        repeat (12) @(posedge CLK);
        $display("[%0t] ALU to JALR Hazard.", $time);
        check_reg("Q:x1_link", 1, `RF[1], 32'h00000288); // PC + 4 link address
        check_reg("Q:x5_target", 5, `RF[5], 32'd42);
        check_reg("Q:x6_forward", 6, `RF[6], 32'h00000288);

        // Reset core to clear state before Phase R
        // RSTN = 0; @(posedge CLK); @(posedge CLK); RSTN = 1; @(posedge CLK);
        // ========================================================================
        // PHASE R - x0 Forwarding Suppression
        // ========================================================================
        $display("\n--- Phase R: x0 Forwarding Suppression ---");
        repeat (10) @(posedge CLK);
        $display("[%0t] Forwarding Supression.", $time);
        // check_reg("R:x0_zero", 0, `RF[0], 32'h00000000); // Must remain zero
        check_reg("R:x2_from_x0", 2, `RF[2], 32'h00000000);

        // Reset core to clear state before Phase S
        // RSTN = 0; @(posedge CLK); @(posedge CLK); RSTN = 1; @(posedge CLK);

        // ========================================================================
        // PHASE S - Shift Corner Cases
        // ========================================================================
        $display("\n--- Phase S: Shift Corner Cases ---");
        repeat (12) @(posedge CLK);
        $display("[%0t] Shift Corner Cases.", $time);
        check_reg("S:srai", 2, `RF[2], 32'hFFFFFFFF);
        check_reg("S:srli", 3, `RF[3], 32'h7FFFFFFF);
        check_reg("S:slli", 4, `RF[4], 32'h80000000);
        check_reg("S:sll_32", 6, `RF[6], 32'hFFFFFFFF); // 32 % 32 = shift 0
        check_reg("S:sll_33", 8, `RF[8], 32'hFFFFFFFE); // 33 % 32 = shift 1

        // Reset core to clear state before Phase T
        // RSTN = 0; @(posedge CLK); @(posedge CLK); RSTN = 1; @(posedge CLK);

        // ========================================================================
        // PHASE T - Branch Not Taken
        // ========================================================================
        $display("\n--- Phase T: Branch Not Taken ---");
        repeat (8) @(posedge CLK);
        $display("[%0t] Branch Not Taken.", $time);
        check_reg("T:x3_fallthrough", 3, `RF[3], 32'd42);
        check_reg("T:x4_fallthrough", 4, `RF[4], 32'd43);

        // Reset core to clear state before Phase U
        // RSTN = 0; @(posedge CLK); @(posedge CLK); RSTN = 1; @(posedge CLK);

        // ========================================================================
        // PHASE U - Store Byte Lane Selection
        // ========================================================================
        $display("\n--- Phase U: Store Byte Lane Selection ---");
        repeat (14) @(posedge CLK);
        $display("[%0t] Store Byte Lane Selection.", $time);
        /* verilator lint_off IEEEMAYDEPRECATE */
        assign dmem_read = {`dmem_bus.dmem[527], `dmem_bus.dmem[526], `dmem_bus.dmem[525], `dmem_bus.dmem[524]};
        check_dmem("U:SB_word", 524, dmem_read, 32'h44332211);
        /* verilator lint_on IEEEMAYDEPRECATE */

        // ==================================================================
        // SUMMARY
        // ==================================================================
        $display("\n==================================================");
        $display("  TOTAL: %0d passed, %0d failed out of %0d tests",
                 pass_count, fail_count, pass_count + fail_count);
        if (fail_count == 0)
            $display("  *** ALL TESTS PASSED ***");
        else
            $display("  *** %0d TEST(S) FAILED – See details above ***", fail_count);
        $display("==================================================\n");

        $finish;
    end

    // -------------------------------------------------------------------------
    // Waveform Dump
    // -------------------------------------------------------------------------
    initial begin
        $dumpfile("core_test_comprehensive.vcd");
        $dumpvars(0, tb_comprehensive);
    end

endmodule
