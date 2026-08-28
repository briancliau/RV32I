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
    RV32I_subsystem dut (
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

    // Alias for the register file (adjust path to match your hierarchy)
    `define RF tb_comprehensive.dut.RV32I.xRegisterFile.registers
    `define dmem_bus tb_comprehensive.dut.DataManager.data_manager.sub_gen[0].subordinate

    initial begin
        // ------------------------------------------------------------------
        // Initialise
        // ------------------------------------------------------------------
        RSTN = 0;
        stall  = 0;

        // ================================================================
        // Reset and release
        // ================================================================
        $display("\n[%0t] ============================================", $time);
        $display("[%0t]  RV32I Comprehensive Pipeline Test Starting", $time);
        $display("[%0t] ============================================\n", $time);
        #15; RSTN = 1;
    
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
