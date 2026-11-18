//------------------------------------------------------------------------------
// Author      : Brian Liau (brian.liau@tufts.edu)
// File        : tb_core_asic.sv
// Design Unit : tb_core_asic
// Description : Comprehensive testbench for the ASIC hardening top
//               (RV32I_core_asic = Core + AHB-Lite instruction/data managers).
//
//               The AHB-Lite memory system (interconnects, memory subordinates,
//               wait-state subordinates, default/error subordinates) lives in
//               the testbench, exactly as an SoC would surround the hardened
//               block. The test program is preloaded in AHB_imem_subordinate.sv.
//
//               Checks are EVENT-BASED, not time-based: each phase waits until
//               a specific instruction retires (is written back), then checks
//               results. This makes the testbench independent of pipeline
//               timing, so it keeps working when branch prediction moves from
//               IF to the IF/ID register (or any other timing change).
//
//               Phases A-U : original directed tests
//               Memory map: one instruction memory (0x0000-0x1FFF) and one
//               data memory (0x0000-0x0FFF), per AHB_pkg.sv.
//
//               Phases V-Y : wrong-path / redirect tests. Each uses a canary
//                            register (or memory word) that only wrong-path
//                            instructions write, so a leaked instruction is
//                            detected even if a later instruction overwrites
//                            the target register.
//               Phase  Z   : CPI kernel (20-iteration loop, 61 instructions)
//               Phase  AA  : PC tag of an instruction after a load->store stall
//               Phase  AB  : EX-stage redirect (JALR) with a jump in IF
//
// Dependencies: rvDefs.sv, AHB_pkg.sv, RTL/*, RTL/asic/*
// Target      : Simulation (Verilator --binary --timing)
//------------------------------------------------------------------------------
`timescale 1ns/1ps

module tb_core_asic;

    import rvDefs::*;

    // -------------------------------------------------------------------------
    // Clock / Reset
    // -------------------------------------------------------------------------
    logic CLK;
    logic RSTN;
    logic stall;

    initial begin CLK = 1'b0; forever #5 CLK = ~CLK; end   // 100 MHz

    // -------------------------------------------------------------------------
    // AHB-Lite buses between the hardened block and the memory system
    // -------------------------------------------------------------------------
    logic [31:0] I_HADDR,  D_HADDR;
    logic [1:0]  I_HTRANS, D_HTRANS;
    logic        I_HWRITE, D_HWRITE;
    logic [2:0]  I_HSIZE,  D_HSIZE;
    logic [31:0] I_HWDATA, D_HWDATA;
    logic [31:0] I_HRDATA, D_HRDATA;
    logic        I_HRESP,  D_HRESP;
    logic        I_HREADY, D_HREADY;

    // -------------------------------------------------------------------------
    // DUT: hardened block (core + AHB-Lite managers)
    // -------------------------------------------------------------------------
    RV32I_core_asic dut (
        .CLK      (CLK),
        .RSTN     (RSTN),
        .stall    (stall),
        .I_HADDR  (I_HADDR),  .I_HTRANS (I_HTRANS), .I_HWRITE (I_HWRITE),
        .I_HSIZE  (I_HSIZE),  .I_HWDATA (I_HWDATA), .I_HRDATA (I_HRDATA),
        .I_HRESP  (I_HRESP),  .I_HREADY (I_HREADY),
        .D_HADDR  (D_HADDR),  .D_HTRANS (D_HTRANS), .D_HWRITE (D_HWRITE),
        .D_HSIZE  (D_HSIZE),  .D_HWDATA (D_HWDATA), .D_HRDATA (D_HRDATA),
        .D_HRESP  (D_HRESP),  .D_HREADY (D_HREADY)
    );

    // -------------------------------------------------------------------------
    // Memory system outside the hardened block (existing AHB-Lite IP)
    // -------------------------------------------------------------------------
    AHB_instruction_top u_imem_sys (
        .HCLK    (CLK),      .HRESETn (RSTN),
        .HADDR   (I_HADDR),  .HTRANS  (I_HTRANS), .HWRITE (I_HWRITE),
        .HSIZE   (I_HSIZE),  .HWDATA  (I_HWDATA), .HRDATA (I_HRDATA),
        .HRESP   (I_HRESP),  .HREADY  (I_HREADY)
    );

    AHB_data_top u_dmem_sys (
        .HCLK    (CLK),      .HRESETn (RSTN),
        .HADDR   (D_HADDR),  .HTRANS  (D_HTRANS), .HWRITE (D_HWRITE),
        .HSIZE   (D_HSIZE),  .HWDATA  (D_HWDATA), .HRDATA (D_HRDATA),
        .HRESP   (D_HRESP),  .HREADY  (D_HREADY)
    );

    // -------------------------------------------------------------------------
    // Hierarchical aliases (adjust if you rename instances)
    // -------------------------------------------------------------------------
    `define RF      tb_core_asic.dut.RV32I.xRegisterFile.registers
    `define WB_WE   tb_core_asic.dut.RV32I.writeEnable_WB
    `define WB_RD   tb_core_asic.dut.RV32I.rd_WB
    `define WB_PC   tb_core_asic.dut.RV32I.instructionAddress_WB
    `define DMEM0   tb_core_asic.u_dmem_sys.sub_gen[0].subordinate.dmem

    // -------------------------------------------------------------------------
    // Cycle counter and watchdog
    // -------------------------------------------------------------------------
    localparam longint WATCHDOG_CYCLES = 20000;
    localparam int WAIT_TIMEOUT    = 2000;   // max cycles for any single event

    longint cycle = 0;
    always @(posedge CLK) begin
        cycle <= cycle + 1;
        if (cycle == WATCHDOG_CYCLES) begin
            $display("[WATCHDOG] %0d cycles elapsed - simulation stopped.", WATCHDOG_CYCLES);
            $finish;
        end
    end

    // -------------------------------------------------------------------------
    // Scoreboard helpers
    // -------------------------------------------------------------------------
    int pass_count = 0;
    int fail_count = 0;

    task automatic check_reg(input string tag, input int r, input logic [31:0] expected);
        logic [31:0] actual;
        actual = `RF[r];
        if (actual === expected) begin
            $display("[PASS] %-24s x%0d = 0x%08h", tag, r, actual);
            pass_count++;
        end else begin
            $display("[FAIL] %-24s x%0d expected 0x%08h, got 0x%08h", tag, r, expected, actual);
            fail_count++;
        end
    endtask

    // Data memory is a 32-bit word array: index = byte address / 4
    function automatic logic [31:0] dmem0_word(input int byte_addr);
        return `DMEM0[byte_addr >> 2];
    endfunction

    task automatic check_mem(input string tag, input int byte_addr,
                             input logic [31:0] actual, input logic [31:0] expected);
        if (actual === expected) begin
            $display("[PASS] %-24s mem[0x%05h] = 0x%08h", tag, byte_addr, actual);
            pass_count++;
        end else begin
            $display("[FAIL] %-24s mem[0x%05h] expected 0x%08h, got 0x%08h",
                     tag, byte_addr, expected, actual);
            fail_count++;
        end
    endtask

    task automatic report_and_finish();
        $display("\n==================================================");
        $display("  TOTAL: %0d passed, %0d failed out of %0d checks",
                 pass_count, fail_count, pass_count + fail_count);
        $display("  Total cycles: %0d", cycle);
        if (fail_count == 0) $display("  *** ALL TESTS PASSED ***");
        else                 $display("  *** %0d CHECK(S) FAILED - see above ***", fail_count);
        $display("==================================================\n");
        $finish;
    endtask

    // -------------------------------------------------------------------------
    // Event helpers
    // -------------------------------------------------------------------------
    // Each phase is checked when the FIRST register-writing instruction of the
    // NEXT phase retires. Anything leaked or repeated inside the phase (wrong-
    // path instructions, double-executed targets) has landed by then.
    //
    // wait_retire: block until the instruction at byte address `pc` writes back
    // a register (rd != x0), then let that write land in the register file.
    // Signals are sampled at the falling edge, where they are stable.
    // Markers are always register-writing instructions; stores are checked
    // after a LATER instruction retires (the pipeline is in order).
    longint retire_cycle;

    task automatic wait_retire(input logic [31:0] pc, input string what = "");
        int n = 0;
        forever begin
            @(negedge CLK);
            if (RSTN && `WB_WE && (`WB_RD != 5'd0) && (`WB_PC == pc)) break;
            if (++n >= WAIT_TIMEOUT) begin
                $display("[FAIL] TIMEOUT: instruction @0x%03h %s never retired - control flow lost.", pc, what);
                $display("       Stopping: later phases depend on this one.");
                fail_count++;
                report_and_finish();
            end
        end
        retire_cycle = cycle;
        @(posedge CLK); #1;   // register-file write happens on this edge
    endtask

    // wait_fetch: block until the core issues an instruction fetch for `pc`
    task automatic wait_fetch(input logic [31:0] pc);
        int n = 0;
        forever begin
            @(negedge CLK);
            if (RSTN && I_HTRANS[1] && I_HREADY && (I_HADDR == pc)) break;
            if (++n >= WAIT_TIMEOUT) begin
                $display("[FAIL] TIMEOUT: fetch of 0x%03h never issued - control flow lost.", pc);
                fail_count++;
                report_and_finish();
            end
        end
        @(posedge CLK); #1;
    endtask

    // -------------------------------------------------------------------------
    // Main test sequence
    // -------------------------------------------------------------------------
    longint cpi_start, cpi_end;
    localparam int CPI_KERNEL_INSTRS = 61;   // 20 iterations x 3 + final addi

    initial begin
        RSTN  = 1'b0;
        stall = 1'b0;

        $display("\n==================================================");
        $display("  RV32I_core_asic Comprehensive Testbench");
        $display("==================================================");

        repeat (2) @(posedge CLK);
        #1 RSTN = 1'b1;

        // ---------------------------------------------------------------- A
        $display("\n--- Phase A: Logical & Bitwise ---");
        wait_retire(32'h024, "(sll x10)");
        check_reg("A:AND",   3, 32'h0F000F00);
        check_reg("A:OR",    4, 32'hFF0FFF0F);
        check_reg("A:XOR",   5, 32'hF00FF00F);
        check_reg("A:XORI",  6, 32'h00FF00FF);
        check_reg("A:SRLI",  9, 32'h0FF00FF0);
        check_reg("A:SLL",  10, 32'h0F0F0000);

        // ---------------------------------------------------------------- B
        $display("\n--- Phase B: SLT / SLTU / SLTI / SLTIU ---");
        wait_retire(32'h040, "(slt x17)");
        check_reg("B:SLT",   13, 32'h1);
        check_reg("B:SLTU",  14, 32'h0);
        check_reg("B:SLTI",  15, 32'h1);
        check_reg("B:SLTIU", 16, 32'h0);
        check_reg("B:SLT2",  17, 32'h0);

        // ---------------------------------------------------------------- C
        $display("\n--- Phase C: LUI / AUIPC ---");
        wait_retire(32'h058, "(auipc x20)");
        check_reg("C:LUI",        18, 32'hABCDE000);
        check_reg("C:AUIPC",      19, 32'h00000054);
        check_reg("C:AUIPC_wrap", 20, 32'hFFFFF058);

        // ---------------------------------------------------------------- D
        $display("\n--- Phase D: Double EX-Forwarding ---");
        wait_retire(32'h088, "(add x23)");
        check_reg("D:add_fwd", 21, 32'd10);
        check_reg("D:sub_fwd", 22, 32'd7);
        check_reg("D:dbl_fwd", 23, 32'd17);

        // ---------------------------------------------------------------- E
        $display("\n--- Phase E: Load-Use Stall & 2-Instr Gap ---");
        wait_retire(32'h0B8, "(add x28)");
        check_reg("E:load_use_stall", 26, 32'hDEADBEEF);
        check_reg("E:load_2gap",      28, 32'h12345678);

        // ---------------------------------------------------------------- F
        $display("\n--- Phase F: Byte / Halfword Load & Store ---");
        wait_retire(32'h0D4, "(lhu x5)");
        check_reg("F:LB",  29, 32'hFFFFFFEF);
        check_reg("F:LBU", 30, 32'h000000EF);
        check_reg("F:LH",  31, 32'hFFFFBEEF);
        check_reg("F:LHU",  5, 32'h0000BEEF);

        // ---------------------------------------------------------------- G
        // (F's SB/SH are checked here: they are older than G's instructions,
        //  so they have completed once G retires.)
        $display("\n--- Phase G: Branch Forwarding Hazard (+ F stores) ---");
        wait_retire(32'h104, "(addi x8, 55)");
        check_mem("F:SB", 32'h088, dmem0_word(32'h088), 32'h000000FF);
        check_mem("F:SH", 32'h08C, dmem0_word(32'h08C), 32'h00000001);
        check_reg("G:BEQ_fwd", 8, 32'd55);

        // ---------------------------------------------------------------- H
        $display("\n--- Phase H: BLT / BGE ---");
        wait_retire(32'h134, "(addi x18, 1)");
        check_reg("H:BLT", 17, 32'd1);
        check_reg("H:BGE", 18, 32'd1);

        // ---------------------------------------------------------------- I
        $display("\n--- Phase H/I: BLTU / BGEU / Backward Loop ---");
        wait_retire(32'h168, "(jal x1)");
        check_reg("H:BLTU+BGEU",  19, 32'd1);
        check_reg("I:loop_result", 20, 32'd0);

        // ---------------------------------------------------------------- J
        $display("\n--- Phase J: JAL Return Address ---");
        wait_retire(32'h178, "(add x22)");
        check_reg("J:JAL_link",       22, 32'h0000016C);
        check_reg("J:traitors_skipped", 21, 32'd10);     // x21 still from Phase D

        // ---------------------------------------------------------------- K
        $display("\n--- Phase K: JALR LSB Clearing ---");
        wait_retire(32'h1A0, "(add x23)");
        check_reg("K:JALR_link",      23, 32'h00000198);
        check_reg("K:traitor_skipped", 2, 32'h00000198);

        // ---------------------------------------------------------------- L
        $display("\n--- Phase L: x0 Immutability ---");
        wait_retire(32'h1C4, "(add x24)");
        check_reg("L:x24_zero", 24, 32'h0);

        // ---------------------------------------------------------------- M
        // Reset while Phase M instructions are in flight (fetch of 0x1E8),
        // so none of them may retire. Registers have no reset, so values
        // from Phases E/F must survive, with no X.
        $display("\n--- Phase M: Reset Mid-Execution ---");
        wait_fetch(32'h1E8);
        RSTN = 1'b0;
        repeat (2) @(posedge CLK);
        #1 RSTN = 1'b1;
        $display("[INFO] Mid-execution reset applied and released at cycle %0d.", cycle);
        check_reg("M:x25_kept", 25, 32'hDEADBEEF);
        check_reg("M:x26_kept", 26, 32'hDEADBEEF);
        check_reg("M:x27_kept", 27, 32'h12345678);
        check_reg("M:x28_kept", 28, 32'h12345678);
        check_reg("M:x29_kept", 29, 32'hFFFFFFEF);
        check_reg("M:x30_kept", 30, 32'h000000EF);
        check_reg("M:x31_kept", 31, 32'hFFFFBEEF);
        if ($isunknown(`RF[25]) || $isunknown(`RF[26]) || $isunknown(`RF[27])) begin
            $display("[FAIL] M:no_X                   X-state in registers after reset");
            fail_count++;
        end else begin
            $display("[PASS] M:no_X                   no X-state after mid-execution reset");
            pass_count++;
        end

        // Program restarts at 0 and re-runs A-L, then executes Phase M.
        $display("\n--- Phase M (second pass): post-reset execution ---");
        wait_retire(32'h1F8, "(addi x31, 9)");
        check_reg("M2:x25", 25, 32'd5);
        check_reg("M2:x26", 26, 32'd10);
        check_reg("M2:x27", 27, 32'd15);
        check_reg("M2:x28", 28, 32'd20);
        check_reg("M2:x29", 29, 32'd25);
        check_reg("M2:x31", 31, 32'd9);
        // NOTE: imem[500] is commented "addi x30, x0, 7" but encodes x31
        //       (0x00700F93). x30 is therefore not checked here.

        // ---------------------------------------------------------------- N
        $display("\n--- Phase N: Store Data Forwarding ---");
        wait_retire(32'h20C, "(addi x2, 0x200)");
        check_reg("N:x1", 1, 32'h00000055);
        check_reg("N:x2", 2, 32'h00000200);
        wait_retire(32'h214, "(lw x3)");
        check_mem("N:SW", 32'h200, dmem0_word(32'h200), 32'h00000055);
        check_reg("N:x3", 3, 32'h00000055);
        wait_retire(32'h220, "(addi x5)");
        check_mem("N:SB", 32'h200, dmem0_word(32'h200), 32'h0000AA55);
        check_reg("N:x4", 4, 32'h000000AA);
        check_reg("N:x5", 5, 32'h00000123);

        // ---------------------------------------------------------------- O
        $display("\n--- Phase O: Load -> Store Hazard (+ N SH) ---");
        wait_retire(32'h230, "(addi x2, 0x204)");
        check_mem("N:SH", 32'h200, dmem0_word(32'h200), 32'h0123AA55);
        wait_retire(32'h258, "(Phase P: addi x2)");   // first writer after Phase O
        check_reg("O:x1_load",       1, 32'hCAFEBABE);
        check_reg("O:x3_load_store", 3, 32'hCAFEBABE);
        check_mem("O:SW", 32'h208, dmem0_word(32'h208), 32'hCAFEBABE);

        // ---------------------------------------------------------------- P
        $display("\n--- Phase P: Load -> Branch Hazard ---");
        wait_retire(32'h270, "(addi x3, 42)");
        // NOTE: Phase N's SB/SH changed word 0x200 to 0x0123AA55, so this load
        //       returns 0x0123AA55, `beq x1, x4` (x4 = 0x55) is NOT taken, and
        //       x3 = 42 holds either way. See Phase Y for a real taken-branch test.
        check_reg("P:x1_load",   1, 32'h0123AA55);
        check_reg("P:x3_target", 3, 32'd42);

        // ---------------------------------------------------------------- Q
        $display("\n--- Phase Q: ALU -> JALR Hazard ---");
        wait_retire(32'h2A4, "(add x6)");
        check_reg("Q:x1_link",    1, 32'h00000288);
        check_reg("Q:x5_target",  5, 32'd42);
        check_reg("Q:x6_forward", 6, 32'h00000288);

        // ---------------------------------------------------------------- R
        $display("\n--- Phase R: x0 Forwarding Suppression ---");
        wait_retire(32'h2C4, "(add x2)");
        check_reg("R:x1",         1, 32'd7);
        check_reg("R:x2_from_x0", 2, 32'h0);

        // ---------------------------------------------------------------- S
        $display("\n--- Phase S: Shift Corner Cases ---");
        wait_retire(32'h2EC, "(sll x8)");
        check_reg("S:srai",   2, 32'hFFFFFFFF);
        check_reg("S:srli",   3, 32'h7FFFFFFF);
        check_reg("S:slli",   4, 32'h80000000);
        check_reg("S:sll_32", 6, 32'hFFFFFFFF);
        check_reg("S:sll_33", 8, 32'hFFFFFFFE);

        // ---------------------------------------------------------------- T
        $display("\n--- Phase T: Branch Not Taken ---");
        wait_retire(32'h31C, "(addi x4, 43)");
        check_reg("T:x3_fallthrough", 3, 32'd42);
        check_reg("T:x4_fallthrough", 4, 32'd43);

        // ---------------------------------------------------------------- U
        $display("\n--- Phase U: Store Byte Lane Selection ---");
        wait_retire(32'h370, "(Phase V: addi x2)");
        check_mem("U:SB_lanes", 32'h20C, dmem0_word(32'h20C), 32'h44332211);

        // ---------------------------------------------------------------- V
        $display("\n--- Phase V: Wrong-Path Store After JAL ---");
        wait_retire(32'h394, "(Phase W: canary reset)");   // first writer after Phase V
        check_reg("V:target", 3, 32'h0000005A);
        check_mem("V:no_wrong_path_store", 32'h210, dmem0_word(32'h210), 32'h00000000);

        // ---------------------------------------------------------------- W
        $display("\n--- Phase W: Wrong-Path Jump Behind JAL ---");
        wait_retire(32'h3DC, "(Phase X: addi x10, 0)");   // first writer after Phase W
        check_reg("W:target",          4, 32'h00000066);
        check_reg("W:continue",        5, 32'h00000067);
        check_reg("W:canary_clean",   21, 32'h00000000);

        // ---------------------------------------------------------------- X
        $display("\n--- Phase X: Redirect Around Load Stalls ---");
        wait_retire(32'h420, "(Phase Y: canary reset)");   // first writer after Phase X
        check_mem("X:SW",          32'h300, dmem0_word(32'h300), 32'h0000005C);
        check_reg("X:LW",              9, 32'h0000005C);
        check_reg("X:target_once_1",  10, 32'h00000001);
        check_reg("X:load_use",       12, 32'h0000005C);
        check_reg("X:target_once_2",  13, 32'h00000001);
        check_reg("X:canary_clean",   22, 32'h00000000);

        // ---------------------------------------------------------------- Y
        $display("\n--- Phase Y: Branches at a JAL Target ---");
        wait_retire(32'h45C, "(Phase Z: addi x19, 0)");    // first writer after Phase Y
        check_reg("Y:after_taken",    15, 32'h0000006C);
        check_reg("Y:after_nottaken", 16, 32'h0000006D);
        check_reg("Y:continue",       17, 32'h0000006E);
        check_reg("Y:canary_clean",   23, 32'h00000000);

        // ---------------------------------------------------------------- Z
        $display("\n--- Phase Z: CPI Kernel ---");
        wait_retire(32'h460, "(addi x18, 20)");
        cpi_start = retire_cycle;
        wait_retire(32'h470, "(addi x20, 0x70)");
        cpi_end = retire_cycle;
        wait_retire(32'h474, "(Phase AA: addi x2)");      // first writer after Phase Z
        check_reg("Z:loop_count", 19, 32'd20);
        check_reg("Z:done",       20, 32'h00000070);
        // CPI is only meaningful when all other checks pass (a leaked
        // wrong-path instruction changes the work done inside the loop).
        $display("[INFO] CPI kernel: %0d cycles / %0d instructions = CPI %0.3f",
                 cpi_end - cpi_start, CPI_KERNEL_INSTRS,
                 real'(cpi_end - cpi_start) / real'(CPI_KERNEL_INSTRS));

        // ---------------------------------------------------------------- AA
        $display("\n--- Phase AA: PC Tag After Load -> Store Stall ---");
        wait_retire(32'h488, "(Phase AB: canary reset)");  // first writer after Phase AA
        check_reg("AA:auipc_pc", 24, 32'h00000480);

        // ---------------------------------------------------------------- AB
        $display("\n--- Phase AB: EX Redirect With a Jump in IF ---");
        wait_retire(32'h4B4, "(addi x28, 0x73)");
        repeat (10) @(posedge CLK);                        // let any leaked instructions land
        check_reg("AB:jalr_target",  27, 32'h00000072);
        check_reg("AB:continue",     28, 32'h00000073);
        check_reg("AB:canary_clean", 26, 32'h00000000);

        // Wrong-path store target must still be untouched at the very end
        repeat (10) @(posedge CLK);
        check_mem("V:still_clean", 32'h210, dmem0_word(32'h210), 32'h00000000);

        // ---------------------------------------------------------------- Summary
        report_and_finish();
    end

    // -------------------------------------------------------------------------
    // Waveform dump
    // -------------------------------------------------------------------------
    initial begin
        $dumpfile("tb_core_asic.vcd");
        $dumpvars(0, tb_core_asic);
    end

    always @(negedge dut.CLK) if (RSTN && (dut.RV32I.memRead || dut.RV32I.memWrite) && dut.RV32I.memSize == 3'b010 && dut.RV32I.address_MEM[1:0] != 0)
    $display("MISALIGNED t=%0t pc_MEM=%h addr=%h rd=%0d", $time,
             dut.RV32I.instructionAddress_MEM, dut.RV32I.address_MEM, dut.RV32I.rd_MEM);

endmodule
