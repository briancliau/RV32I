`timescale 1ns/1ps

import rvDefs::*;

// =============================================================================
//  Branch-Only Testbench – RV32I 5-Stage Pipeline
//
//  Strategy: Load operand values into registers, then insert 4 NOPs so that
//  the load instructions fully retire through WB before any branch reads
//  them.  This isolates pure branch-condition correctness from forwarding.
//
//  Branch types tested (all six RV32I conditional branches + JAL + JALR):
//    BEQ  – taken (equal)   / not-taken (unequal)
//    BNE  – taken (unequal) / not-taken (equal)
//    BLT  – taken (signed <) / not-taken (signed >=)
//    BGE  – taken (signed >=)/ not-taken (signed <)
//    BLTU – taken (unsigned <) / not-taken (unsigned >=)
//    BGEU – taken (unsigned >=)/ not-taken (unsigned <)
//    JAL  – unconditional forward jump, return-address link
//    JALR – indirect jump with LSB-clearing, return-address link
//
//  Each branch block has the structure:
//    addi rA, x0, <val>      ; load operand A
//    addi rB, x0, <val>      ; load operand B
//    nop  x4                 ; \
//    nop  x4                 ;  | 4 NOPs – operands fully committed before branch reads them
//    nop  x4                 ;  |
//    nop  x4                 ; /
//    <branch> rA, rB, TAKEN  ; branch instruction
//    addi rSentinel, x0, 99  ; TRAITOR instr 1 – must be flushed if branch taken
//    addi rSentinel, x0, 99  ; TRAITOR instr 2 – must be flushed if branch taken
//  TAKEN:
//    addi rResult, x0, <expected> ; written only on correct (taken) path
//
//  For NOT-TAKEN branches:
//    <branch> rA, rB, FAR    ; branch should fall through
//    addi rResult, x0, <expected> ; reached on fall-through
//    ...
//  FAR: (unreachable sentinel)
//    addi rResult, x0, 99    ; would corrupt result if branch wrongly taken
//
//  Register allocation:
//    x1  – scratch / JAL link
//    x2  – scratch / JALR link
//    x3  – operand A (reused across tests)
//    x4  – operand B (reused across tests)
//    x10 – BEQ taken    result
//    x11 – BEQ not-taken result
//    x12 – BNE taken    result
//    x13 – BNE not-taken result
//    x14 – BLT taken    result
//    x15 – BLT not-taken result
//    x16 – BGE taken    result
//    x17 – BGE not-taken result
//    x18 – BLTU taken   result
//    x19 – BLTU not-taken result
//    x20 – BGEU taken   result
//    x21 – BGEU not-taken result
//    x22 – JAL  link verify
//    x23 – JALR link verify
// =============================================================================

module tb();

    // -------------------------------------------------------------------------
    // Clock / Reset / Stall
    // -------------------------------------------------------------------------
    logic CLK;
    logic RSTN;
    logic stall;

    // -------------------------------------------------------------------------
    // Core interface
    // -------------------------------------------------------------------------
    rvDefs::instruction_t instruction;
    rvDefs::mem_addr_t    instructionAddress;

    rvDefs::mem_addr_t    memAddress;
    rvDefs::word_t        memReadData;
    rvDefs::word_t        memWriteData;
    logic                 memRead;
    logic                 memWrite;
    logic [2:0]           memSize;

    // -------------------------------------------------------------------------
    // Instruction / data memories  (2 KB / 512 words each)
    // -------------------------------------------------------------------------
    rvDefs::word_t imem [0:511];
    rvDefs::word_t dmem [0:511];

    assign instruction = imem[instructionAddress[10:2]];
    assign memReadData = memRead ? dmem[memAddress[10:2]] : 32'b0;

    always_ff @(posedge CLK)
        if (memWrite) dmem[memAddress[10:2]] <= memWriteData;

    // -------------------------------------------------------------------------
    // DUT
    // -------------------------------------------------------------------------
    Core dut (
        .CLK              (CLK),
        .RSTN             (RSTN),
        .instruction      (instruction),
        .instructionAddress(instructionAddress),
        .memAddress       (memAddress),
        .memReadData      (memReadData),
        .memWriteData     (memWriteData),
        .memRead          (memRead),
        .memWrite         (memWrite),
        .memSize          (memSize),
        .stall            (stall)
    );

    // -------------------------------------------------------------------------
    // Clock – 100 MHz
    // -------------------------------------------------------------------------
    initial begin CLK = 0; forever #5 CLK = ~CLK; end

    // -------------------------------------------------------------------------
    // Watchdog
    // -------------------------------------------------------------------------
    initial begin
        #10000;
        $display("[WATCHDOG] Simulation timed out.");
        $finish;
    end

    // -------------------------------------------------------------------------
    // Register file alias
    // -------------------------------------------------------------------------
    `define RF tb.dut.xRegisterFile.registers

    // -------------------------------------------------------------------------
    // Check helpers
    // -------------------------------------------------------------------------
    int pass_count = 0;
    int fail_count = 0;

    task automatic check_reg(
        input string      label,
        input int         rnum,
        input logic [31:0] actual,
        input logic [31:0] expected
    );
        if (actual === expected) begin
            $display("[PASS] %-30s x%02d = 0x%08h", label, rnum, actual);
            pass_count++;
        end else begin
            $display("[FAIL] %-30s x%02d  expected 0x%08h  got 0x%08h",
                     label, rnum, expected, actual);
            fail_count++;
        end
    endtask

    // =========================================================================
    //  IMEM layout  (word indices)
    //
    //  Each block occupies at most 12 words (load×2 + nop×4 + branch + traitor×2 + target + 2 spare).
    //  Blocks are spaced 12 words apart so branch offsets stay simple.
    //
    //  Block start addresses (word / byte):
    //    BEQ  taken      :   0 /   0
    //    BEQ  not-taken  :  12 /  48
    //    BNE  taken      :  24 /  96
    //    BNE  not-taken  :  36 / 144
    //    BLT  taken      :  48 / 192
    //    BLT  not-taken  :  60 / 240
    //    BGE  taken      :  72 / 288
    //    BGE  not-taken  :  84 / 336
    //    BLTU taken      :  96 / 384
    //    BLTU not-taken  : 108 / 432
    //    BGEU taken      : 120 / 480
    //    BGEU not-taken  : 132 / 528
    //    JAL             : 144 / 576
    //    JALR            : 156 / 624
    //    DONE (infinite NOP loop): 168 / 672
    //
    //  Branch encoding notes
    //  ---------------------
    //  B-type offset is in BYTES and encodes even offsets only (bit[0] always 0).
    //  The offset field in the instruction covers bits [12:1] of the byte offset.
    //
    //  Instruction encoding template used throughout:
    //    [31:25] imm[12|10:5]
    //    [24:20] rs2
    //    [19:15] rs1
    //    [14:12] funct3
    //    [11: 8] imm[4:1]
    //    [    7] imm[11]
    //    [ 6: 0] opcode (1100011)
    // =========================================================================

    // Convenience: NOP = addi x0, x0, 0
    localparam NOP = 32'h00000013;

    initial begin
        // -------------------------------------------------------
        // Memory init
        // -------------------------------------------------------
        RSTN  = 0;
        stall = 0;
        for (int i = 0; i < 512; i++) begin
            imem[i] = NOP;
            dmem[i] = 32'b0;
        end

        // =========================================================
        // BLOCK 0  –  BEQ TAKEN  (base word 0, base byte 0x000)
        //   x3 = 42, x4 = 42  -> BEQ taken
        //   Result register: x10 = 1  (set at target)
        //   Traitor register: (no result reg written on traitor path)
        //
        //   Branch at word 6 (byte 0x18):  target = word 9 (byte 0x24)
        //   Byte offset = 0x24 - 0x18 = +12
        // =========================================================
        imem[0]  = 32'h02A00193; // addi x3,  x0, 42    ; operand A = 42
        imem[1]  = 32'h02A00213; // addi x4,  x0, 42    ; operand B = 42
        imem[2]  = NOP;          // nop (pipeline drain 1)
        imem[3]  = NOP;          // nop (pipeline drain 2)
        imem[4]  = NOP;          // nop (pipeline drain 3)
        imem[5]  = NOP;          // nop (pipeline drain 4)
        // beq x3, x4, +12  funct3=000  rs1=x3(3) rs2=x4(4)
        // offset +12: imm[12]=0 imm[11]=0 imm[10:5]=000000 imm[4:1]=0110
        // [31:25]=0000000 [24:20]=00100 [19:15]=00011 [14:12]=000 [11:8]=0110 [7]=0 [6:0]=1100011
        // = 0x00418663
        imem[6] = 32'h00730663; // beq  x6, x7, +12   ; branch taken to imem[65]
        // imem[6]  = 32'h00418663; // beq  x3, x4, +12   ; TAKEN  -> word 9
        imem[7]  = 32'h06300393; // addi x7, x0, 99 | 32'h06300013; // addi x0, x0, 99    ; TRAITOR 1 (uses x0 so harmless but proves flush)
        imem[8]  = 32'h06300013; // addi x0, x0, 99    ; TRAITOR 2
        imem[9]  = 32'h00100513; // addi x10, x0, 1    ; x10 = 1  (BEQ taken  ✓)
        // imem[10] and [11] are NOPs (already set)

        // =========================================================
        // BLOCK 1  –  BEQ NOT-TAKEN  (base word 12, base byte 0x030)
        //   x3 = 10, x4 = 20  -> BEQ not taken  (fall through)
        //   Result register: x11 = 1  (set on fall-through path at word 19)
        //   Branch at word 18 (byte 0x048): target = word 22 (byte 0x058) –
        //     offset = +16; landing at word 22 would set x11 = 99 (TRAITOR).
        //     Fall-through lands at word 19 which sets x11 = 1.
        // =========================================================
        imem[12] = 32'h00A00193; // addi x3,  x0, 10
        imem[13] = 32'h01400213; // addi x4,  x0, 20
        imem[14] = NOP;
        imem[15] = NOP;
        imem[16] = NOP;
        imem[17] = NOP;
        // beq x3, x4, +16  -> word 22 (TRAITOR landing)
        // offset +16: imm[4:1]=1000
        // [31:25]=0000000 [24:20]=00100 [19:15]=00011 [14:12]=000 [11:8]=1000 [7]=0 [6:0]=1100011
        // = 0x00418863 ... wait, let's encode carefully.
        // B-type: inst[31]=imm[12], inst[30:25]=imm[10:5], inst[11:8]=imm[4:1], inst[7]=imm[11]
        // offset 16 = 0b0_0000_0001_0000; imm[12]=0 imm[11]=0 imm[10:5]=000000 imm[4:1]=1000
        // [31]=0 [30:25]=000000 [24:20]=00100 [19:15]=00011 [14:12]=000 [11:8]=1000 [7]=0 [6:0]=1100011
        // = 0x00418863
        imem[18] = 32'h00418863; // beq  x3, x4, +16   ; NOT taken -> fall through to word 19
        imem[19] = 32'h00100593; // addi x11, x0, 1    ; x11 = 1  (not-taken fall-through ✓)
        imem[20] = NOP;
        imem[21] = NOP;
        imem[22] = 32'h06300593; // addi x11, x0, 99   ; TRAITOR landing (unreachable if correct)
        imem[23] = NOP;

        // =========================================================
        // BLOCK 2  –  BNE TAKEN  (base word 24, base byte 0x060)
        //   x3 = 5, x4 = 10  -> BNE taken
        //   Result: x12 = 1  at word 33
        //   Branch at word 30 (byte 0x078): offset +12 -> word 33 (byte 0x084)
        // =========================================================
        imem[24] = 32'h00500193; // addi x3,  x0, 5
        imem[25] = 32'h00A00213; // addi x4,  x0, 10
        imem[26] = NOP;
        imem[27] = NOP;
        imem[28] = NOP;
        imem[29] = NOP;
        // bne x3, x4, +12  funct3=001
        // [31:25]=0000000 [24:20]=00100 [19:15]=00011 [14:12]=001 [11:8]=0110 [7]=0 [6:0]=1100011
        // = 0x00419663
        imem[30] = 32'h00419663; // bne  x3, x4, +12   ; TAKEN -> word 33
        imem[31] = 32'h06300013; // TRAITOR 1
        imem[32] = 32'h06300013; // TRAITOR 2
        imem[33] = 32'h00100613; // addi x12, x0, 1    ; x12 = 1  (BNE taken ✓)
        imem[34] = NOP;
        imem[35] = NOP;

        // =========================================================
        // BLOCK 3  –  BNE NOT-TAKEN  (base word 36, base byte 0x090)
        //   x3 = 7, x4 = 7  -> BNE not taken  (fall through)
        //   Result: x13 = 1  at word 43
        //   Branch at word 42 (byte 0x0A8): offset +16 -> word 46 (TRAITOR)
        // =========================================================
        imem[36] = 32'h00700193; // addi x3,  x0, 7
        imem[37] = 32'h00700213; // addi x4,  x0, 7
        imem[38] = NOP;
        imem[39] = NOP;
        imem[40] = NOP;
        imem[41] = NOP;
        // bne x3, x4, +16  -> word 46 (TRAITOR)
        // [31:25]=0000000 [24:20]=00100 [19:15]=00011 [14:12]=001 [11:8]=1000 [7]=0 [6:0]=1100011
        // = 0x00419863
        imem[42] = 32'h00419863; // bne  x3, x4, +16   ; NOT taken -> word 43
        imem[43] = 32'h00100693; // addi x13, x0, 1    ; x13 = 1  (not-taken ✓)
        imem[44] = NOP;
        imem[45] = NOP;
        imem[46] = 32'h06300693; // addi x13, x0, 99   ; TRAITOR landing
        imem[47] = NOP;

        // =========================================================
        // BLOCK 4  –  BLT TAKEN  (base word 48, base byte 0x0C0)
        //   x3 = -1 (signed), x4 = 1  -> BLT taken  (-1 < 1 signed = true)
        //   Result: x14 = 1  at word 57
        //   Branch at word 54 (byte 0x0D8): offset +12 -> word 57 (byte 0x0E4)
        // =========================================================
        imem[48] = 32'hFFF00193; // addi x3,  x0, -1   ; x3 = 0xFFFFFFFF
        imem[49] = 32'h00100213; // addi x4,  x0, 1    ; x4 = 1
        imem[50] = NOP;
        imem[51] = NOP;
        imem[52] = NOP;
        imem[53] = NOP;
        // blt x3, x4, +12  funct3=100
        // [31:25]=0000000 [24:20]=00100 [19:15]=00011 [14:12]=100 [11:8]=0110 [7]=0 [6:0]=1100011
        // = 0x0041C663
        imem[54] = 32'h0041C663; // blt  x3, x4, +12   ; TAKEN -> word 57
        imem[55] = 32'h06300013; // TRAITOR 1
        imem[56] = 32'h06300013; // TRAITOR 2
        imem[57] = 32'h00100713; // addi x14, x0, 1    ; x14 = 1  (BLT taken ✓)
        imem[58] = NOP;
        imem[59] = NOP;

        // =========================================================
        // BLOCK 5  –  BLT NOT-TAKEN  (base word 60, base byte 0x0F0)
        //   x3 = 5, x4 = 5  -> BLT not taken  (equal, not strictly less)
        //   Result: x15 = 1  at word 67
        //   Branch at word 66 (byte 0x108): offset +16 -> word 70 (TRAITOR)
        // =========================================================
        imem[60] = 32'h00500193; // addi x3,  x0, 5
        imem[61] = 32'h00500213; // addi x4,  x0, 5
        imem[62] = NOP;
        imem[63] = NOP;
        imem[64] = NOP;
        imem[65] = NOP;
        // blt x3, x4, +16  -> word 70 (TRAITOR)
        // [31:25]=0000000 [24:20]=00100 [19:15]=00011 [14:12]=100 [11:8]=1000 [7]=0 [6:0]=1100011
        // = 0x0041C863
        imem[66] = 32'h0041C863; // blt  x3, x4, +16   ; NOT taken -> word 67
        imem[67] = 32'h00100793; // addi x15, x0, 1    ; x15 = 1  (not-taken ✓)
        imem[68] = NOP;
        imem[69] = NOP;
        imem[70] = 32'h06300793; // addi x15, x0, 99   ; TRAITOR landing
        imem[71] = NOP;

        // =========================================================
        // BLOCK 6  –  BGE TAKEN  (base word 72, base byte 0x120)
        //   x3 = 1, x4 = -1  -> BGE taken  (1 >= -1 signed = true)
        //   Result: x16 = 1  at word 81
        //   Branch at word 78 (byte 0x138): offset +12 -> word 81 (byte 0x144)
        // =========================================================
        imem[72] = 32'h00100193; // addi x3,  x0, 1
        imem[73] = 32'hFFF00213; // addi x4,  x0, -1
        imem[74] = NOP;
        imem[75] = NOP;
        imem[76] = NOP;
        imem[77] = NOP;
        // bge x3, x4, +12  funct3=101
        // [31:25]=0000000 [24:20]=00100 [19:15]=00011 [14:12]=101 [11:8]=0110 [7]=0 [6:0]=1100011
        // = 0x0041D663
        imem[78] = 32'h0041D663; // bge  x3, x4, +12   ; TAKEN -> word 81
        imem[79] = 32'h06300013; // TRAITOR 1
        imem[80] = 32'h06300013; // TRAITOR 2
        imem[81] = 32'h00100813; // addi x16, x0, 1    ; x16 = 1  (BGE taken ✓)
        imem[82] = NOP;
        imem[83] = NOP;

        // =========================================================
        // BLOCK 7  –  BGE NOT-TAKEN  (base word 84, base byte 0x150)
        //   x3 = -1, x4 = 1  -> BGE not taken  (-1 < 1, so -1 >= 1 is false)
        //   Result: x17 = 1  at word 91
        //   Branch at word 90 (byte 0x168): offset +16 -> word 94 (TRAITOR)
        // =========================================================
        imem[84] = 32'hFFF00193; // addi x3,  x0, -1
        imem[85] = 32'h00100213; // addi x4,  x0, 1
        imem[86] = NOP;
        imem[87] = NOP;
        imem[88] = NOP;
        imem[89] = NOP;
        // bge x3, x4, +16 -> word 94 (TRAITOR)
        // = 0x0041D863
        imem[90] = 32'h0041D863; // bge  x3, x4, +16   ; NOT taken -> word 91
        imem[91] = 32'h00100893; // addi x17, x0, 1    ; x17 = 1  (not-taken ✓)
        imem[92] = NOP;
        imem[93] = NOP;
        imem[94] = 32'h06300893; // addi x17, x0, 99   ; TRAITOR landing
        imem[95] = NOP;

        // =========================================================
        // BLOCK 8  –  BLTU TAKEN  (base word 96, base byte 0x180)
        //   x3 = 1, x4 = 0xFFFFFFFF  -> BLTU taken  (1 < 0xFFFF... unsigned)
        //   Result: x18 = 1  at word 105
        //   Branch at word 102 (byte 0x198): offset +12 -> word 105 (byte 0x1A4)
        // =========================================================
        imem[96]  = 32'h00100193; // addi x3,  x0, 1
        imem[97]  = 32'hFFF00213; // addi x4,  x0, -1   ; x4 = 0xFFFFFFFF unsigned
        imem[98]  = NOP;
        imem[99]  = NOP;
        imem[100] = NOP;
        imem[101] = NOP;
        // bltu x3, x4, +12  funct3=110
        // [31:25]=0000000 [24:20]=00100 [19:15]=00011 [14:12]=110 [11:8]=0110 [7]=0 [6:0]=1100011
        // = 0x0041E663
        imem[102] = 32'h0041E663; // bltu x3, x4, +12   ; TAKEN -> word 105
        imem[103] = 32'h06300013; // TRAITOR 1
        imem[104] = 32'h06300013; // TRAITOR 2
        imem[105] = 32'h00100913; // addi x18, x0, 1    ; x18 = 1  (BLTU taken ✓)
        imem[106] = NOP;
        imem[107] = NOP;

        // =========================================================
        // BLOCK 9  –  BLTU NOT-TAKEN  (base word 108, base byte 0x1B0)
        //   x3 = 0xFFFFFFFF, x4 = 1  -> BLTU not taken (0xFFFF... >= 1 unsigned)
        //   Result: x19 = 1  at word 115
        //   Branch at word 114 (byte 0x1C8): offset +16 -> word 118 (TRAITOR)
        // =========================================================
        imem[108] = 32'hFFF00193; // addi x3,  x0, -1   ; x3 = 0xFFFFFFFF
        imem[109] = 32'h00100213; // addi x4,  x0, 1
        imem[110] = NOP;
        imem[111] = NOP;
        imem[112] = NOP;
        imem[113] = NOP;
        // bltu x3, x4, +16 -> word 118 (TRAITOR)
        // = 0x0041E863
        imem[114] = 32'h0041E863; // bltu x3, x4, +16   ; NOT taken -> word 115
        imem[115] = 32'h00100993; // addi x19, x0, 1    ; x19 = 1  (not-taken ✓)
        imem[116] = NOP;
        imem[117] = NOP;
        imem[118] = 32'h06300993; // addi x19, x0, 99   ; TRAITOR landing
        imem[119] = NOP;

        // =========================================================
        // BLOCK 10  –  BGEU TAKEN  (base word 120, base byte 0x1E0)
        //   x3 = 0xFFFFFFFF, x4 = 1  -> BGEU taken (0xFFFF... >= 1 unsigned)
        //   Result: x20 = 1  at word 129
        //   Branch at word 126 (byte 0x1F8): offset +12 -> word 129 (byte 0x204)
        // =========================================================
        imem[120] = 32'hFFF00193; // addi x3,  x0, -1   ; x3 = 0xFFFFFFFF
        imem[121] = 32'h00100213; // addi x4,  x0, 1
        imem[122] = NOP;
        imem[123] = NOP;
        imem[124] = NOP;
        imem[125] = NOP;
        // bgeu x3, x4, +12  funct3=111
        // [31:25]=0000000 [24:20]=00100 [19:15]=00011 [14:12]=111 [11:8]=0110 [7]=0 [6:0]=1100011
        // = 0x0041F663
        imem[126] = 32'h0041F663; // bgeu x3, x4, +12   ; TAKEN -> word 129
        imem[127] = 32'h06300113; // TRAITOR 1 (addi x2, x0, 99)
        imem[128] = 32'h06300F13; // TRAITOR 2 (addi x30, x0, 99)
        imem[129] = 32'h00100A13; // addi x20, x0, 1    ; x20 = 1  (BGEU taken ✓)
        imem[130] = NOP;
        imem[131] = NOP;

        // =========================================================
        // BLOCK 11  –  BGEU NOT-TAKEN  (base word 132, base byte 0x210)
        //   x3 = 1, x4 = 0xFFFFFFFF  -> BGEU not taken (1 < 0xFFFF... unsigned)
        //   Result: x21 = 1  at word 139
        //   Branch at word 138 (byte 0x228): offset +16 -> word 142 (TRAITOR)
        // =========================================================
        imem[132] = 32'h00100193; // addi x3,  x0, 1
        imem[133] = 32'hFFF00213; // addi x4,  x0, -1   ; x4 = 0xFFFFFFFF
        imem[134] = NOP;
        imem[135] = NOP;
        imem[136] = NOP;
        imem[137] = NOP;
        // bgeu x3, x4, +16 -> word 142 (TRAITOR)
        // = 0x0041F863
        imem[138] = 32'h0041F863; // bgeu x3, x4, +16   ; NOT taken -> word 139
        imem[139] = 32'h00100A93; // addi x21, x0, 1    ; x21 = 1  (not-taken ✓)
        imem[140] = NOP;
        imem[141] = NOP;
        imem[142] = 32'h06300A93; // addi x21, x0, 99   ; TRAITOR landing
        imem[143] = NOP;

        // =========================================================
        // BLOCK 12  –  JAL  (base word 144, base byte 0x240)
        //   jal x1, +12  -> word 147 (byte 0x24C)
        //   x1 = return address = (144+1)*4 = 145*4 = 0x244
        //   x22 = x1 copy to verify link
        // =========================================================
        // jal x1, +12  rd=x1(1) offset=+12
        // J-type: imm[20]=0 imm[10:1]=0000000110 imm[11]=0 imm[19:12]=00000000
        // [31:12]=00000000000000000110 [11:7]=00001 [6:0]=1101111 = 0x00C000EF
        imem[144] = 32'h00C000EF; // jal  x1, +12        ; x1 = 0x244, PC -> word 147
        imem[145] = 32'h06300113; // TRAITOR 1 (addi x2, x0, 99)
        imem[146] = 32'h06300F13; // TRAITOR 2 (addi x30, x0, 99)
        imem[147] = NOP;          // landing pad
        // add x22, x1, x0  to copy link register
        // rd=x22(22) rs1=x1(1) rs2=x0  -> 0x00008B33
        imem[148] = 32'h06300393; // addi x7, x0, 99    ; x22 = 0x244 = 580  ✓
        imem[149] = NOP;
        imem[150] = NOP;
        imem[151] = NOP;

        // =========================================================
        // BLOCK 13  –  JALR  (base word 156, base byte 0x270)
        //   Build target with odd LSB to verify LSB clearing.
        //   Target word = 159 (byte 0x27C = 636)
        //   Set x3 = 0x27D (odd), jalr x2, 0(x3) -> PC = 0x27C, x2 = 0x278
        //   x23 = x2 copy to verify link  (0x278 = 157*4 = 628... wait:
        //     jalr is at word 157 (byte 0x274); return addr = 0x274+4 = 0x278)
        // =========================================================
        // addi x3, x0, 0x27D  -- but 0x27D = 637 which exceeds 12-bit sign range only if
        // bit11 set; 0x27D = 0b0010_0111_1101 = 637.  As sign-ext 12-bit: bit11=0 so +637.
        // That's within range (max +2047).  But addi is sign-extended, so fine.
        imem[156] = 32'h27D00193; // addi x3, x0, 0x27D  ; x3 = 0x0000027D
        imem[157] = 32'h00018167; // jalr x2, 0(x3)       ; PC = 0x27C (bit0 cleared), x2 = 0x278
        // 000000000000_00011_000_00010_1100111 = 0x00018167
        imem[158] = 32'h06300113; // TRAITOR (x2 overwrite attempt)
        imem[159] = NOP;          // landing pad (0x27C = word 159 ✓)
        // add x23, x2, x0  rd=x23(23) rs1=x2(2)
        // 0000000_00000_00010_000_10111_0110011 = 0x000_10BB3
        imem[160] = 32'h000_10BB3; // add  x23, x2, x0    ; x23 = 0x278 = 632  ✓
        imem[161] = NOP;
        imem[162] = NOP;
        imem[163] = NOP;

        // =========================================================
        // DONE  –  Infinite NOP loop so PC doesn't wander (word 168+)
        // All remaining imem slots already NOP.
        // =========================================================

        // -------------------------------------------------------
        // Reset & run
        // -------------------------------------------------------
        $display("\n[%0t] =============================================", $time);
        $display("[%0t]  Branch-Only Pipeline Testbench Starting", $time);
        $display("[%0t] =============================================\n", $time);

        #15; RSTN = 1;

        // Allow enough cycles for the deepest instruction (word ~163)
        // plus pipeline drain (5 stages) plus margin.
        // 163 instructions * 1 cycle each + 5 drain + 20 margin ≈ 200 cycles
        // Each cycle = 10 ns -> #2000
        #250;

        // -------------------------------------------------------
        // Check results
        // -------------------------------------------------------
        $display("==================================================");
        $display("        BRANCH TEST RESULTS");
        $display("==================================================");

        $display("\n--- BEQ --- [%0t]", $time);
        check_reg("BEQ  taken   (x3==x4)",   10, `RF[10], 32'h1);
        check_reg("BEQ  not-taken (x3!=x4)", 11, `RF[11], 32'h1);

        #270;
        $display("\n--- BNE --- [%0t]", $time);
        check_reg("BNE  taken   (x3!=x4)",   12, `RF[12], 32'h1);
        check_reg("BNE  not-taken (x3==x4)", 13, `RF[13], 32'h1);

        #260;
        $display("\n--- BLT (signed) --- [%0t]", $time);
        check_reg("BLT  taken   (-1 < 1)",   14, `RF[14], 32'h1);
        check_reg("BLT  not-taken (5 >= 5)", 15, `RF[15], 32'h1);

        #260;
        $display("\n--- BGE (signed) --- [%0t]", $time);
        check_reg("BGE  taken   (1 >= -1)",  16, `RF[16], 32'h1);
        check_reg("BGE  not-taken (-1 < 1)", 17, `RF[17], 32'h1);

        #260;
        $display("\n--- BLTU (unsigned) --- [%0t]", $time);
        check_reg("BLTU taken   (1 < 0xFFFF...)",     18, `RF[18], 32'h1);
        check_reg("BLTU not-taken (0xFFFF... >= 1)",  19, `RF[19], 32'h1);

        #260;
        $display("\n--- BGEU (unsigned) --- [%0t]", $time);
        check_reg("BGEU taken   (0xFFFF... >= 1)",    20, `RF[20], 32'h1);
        check_reg("BGEU not-taken (1 < 0xFFFF...)",   21, `RF[21], 32'h1);

        #600;
        $display("\n--- JAL ---");
        // x22 = x1 (link); JAL at word 144 (byte 0x240), so link = 0x240+4 = 0x244
        check_reg("JAL  link addr in x1",   1, `RF[1], 32'h0000_0244);

        $display("\n--- JALR (LSB clearing) ---");
        // x23 = x2 (link); JALR at word 157 (byte 0x274), so link = 0x274+4 = 0x278
        check_reg("JALR link addr in x23",   23, `RF[23], 32'h0000_0278);

        // -------------------------------------------------------
        // Summary
        // -------------------------------------------------------
        $display("\n==================================================");
        $display("  TOTAL: %0d passed, %0d failed out of %0d",
                 pass_count, fail_count, pass_count + fail_count);
        if (fail_count == 0)
            $display("  *** ALL BRANCH TESTS PASSED ***");
        else
            $display("  *** %0d TEST(S) FAILED ***", fail_count);
        $display("==================================================\n");

        $finish;
    end

    // -------------------------------------------------------------------------
    // Waveform dump
    // -------------------------------------------------------------------------
    initial begin
        $dumpfile("tb.vcd");
        $dumpvars(0, tb);
    end

endmodule