//------------------------------------------------------------------------------
// Author      : Brian Liau (brian.liau@tufts.edu)
// File        : AHB_imem_subordinate.sv
// Design Unit : AHB_imem_subordinate
// Description : AHB_Lite byte-addressable instruction memory module with  
//               dynamic wait states.
// Dependencies: AHB_pkg.sv
// Target      : Testbench Verification (Synthesis in yosis directory)
//------------------------------------------------------------------------------
module AHB_imem_subordinate #(
    parameter int unsigned ADDR_BITS = 12, 
    parameter int unsigned NUM_WAITS = 0)
(
    input  logic        HCLK, 
    input  logic        HRESETn,
    input  logic        HSELx,          
    input  logic        HREADY,
    input  logic        HWRITE,     
    input  logic [31:0] HADDR,          
    input  logic [2:0]  HSIZE,
    input  logic [1:0]  HTRANS,
    input  logic [31:0] HWDATA, 
    output logic        HRESP,
    output logic        HREADYOUT,
    output logic [31:0] HRDATA
);    
    import AHB_pkg::*;

    // AHB Address Phase Latching
    logic                   addr_accept;
    logic                   dataphase_valid;
    logic                   write_reg;
    logic [ADDR_BITS-1:0]   addr_reg;
    logic [2:0]             size_reg;

    // Accept new transfers when NONSEQ (2'b10) or SEQ (2'b11) transfers
    assign addr_accept = HSELx && HTRANS[1];

    // Word Alignment
    logic [ADDR_BITS-1:0]   word_base;
    assign word_base = {addr_reg[ADDR_BITS-1:2], 2'b00};

    // Byte wide memory array (2^ADDR_BITS bytes total)
    logic [7:0] imem [2**ADDR_BITS];

    // Wait State Counter Logic
    localparam int unsigned counter_width = (NUM_WAITS > 0) ? $clog2(NUM_WAITS + 1) : 1;
    logic [counter_width-1:0] wait_count;

    // Pipeline address phase signals to data phase
    always_ff @(posedge HCLK or negedge HRESETn) begin
        if (!HRESETn) begin
            dataphase_valid <= 1'b0;
            write_reg       <= 1'b0; 
            addr_reg        <= '0; 
            size_reg        <= 3'b000; 

        end else if (HREADY) begin
            dataphase_valid <= addr_accept;

            if (addr_accept) begin
                write_reg   <= HWRITE;
                addr_reg    <= HADDR[ADDR_BITS-1:0]; 
                size_reg    <= HSIZE;
            end
        end
    end

    // Wait State Counter 
    always_ff @(posedge HCLK or negedge HRESETn) begin
        if (!HRESETn)                    wait_count <= '0;
        else if (HREADY && addr_accept)  wait_count <= NUM_WAITS[counter_width-1:0];    // load on accept
        else if (wait_count != '0)       wait_count <= wait_count - 1;    // count down
    end

    // Output Assignment
    assign HRESP = 1'b0;
    assign HREADYOUT = (wait_count == '0);
    assign HRDATA    = {imem[word_base + 3], imem[word_base + 2], imem[word_base + 1], imem[word_base]};

    // Preload Instruction Memory for Verfication
    // ==================================================================
    // PHASE A – Arithmetic & Logical Immediate / Register (imem 0-9)
    // ==================================================================
    always_comb begin
        imem[0]  = 8'hB7; // lui  x1, 0xFF010   ; x1 = 0xFF010000
        imem[1]  = 8'h00;
        imem[2]  = 8'h01;
        imem[3]  = 8'hFF;

        imem[4]  = 8'h93; // addi x1, x1, -256  ; x1 = 0xFF00FF00
        imem[5]  = 8'h80;
        imem[6]  = 8'h00;
        imem[7]  = 8'hF0;

        // Build x2 = 0x0F0F0F0F
        imem[8]  = 8'h37; // lui  x2, 0x0F0F1   ; x2 = 0x0F0F1000
        imem[9]  = 8'h11;
        imem[10] = 8'h0F;
        imem[11] = 8'h0F;

        imem[12] = 8'h13; // addi x2, x2, -241  ; x2 = 0x0F0F0F0F
        imem[13] = 8'h01;
        imem[14] = 8'hF1;
        imem[15] = 8'hF0;

        imem[16] = 8'hB3; // and  x3, x1, x2    ; x3 = 0x0F000F00
        imem[17] = 8'hF1;
        imem[18] = 8'h20;
        imem[19] = 8'h00;

        imem[20] = 8'h33; // or   x4, x1, x2    ; x4 = 0xFF0FFF0F
        imem[21] = 8'hE2;
        imem[22] = 8'h20;
        imem[23] = 8'h00;

        imem[24] = 8'hB3; // xor  x5, x1, x2    ; x5 = 0xF00FF00F
        imem[25] = 8'hC2;
        imem[26] = 8'h20;
        imem[27] = 8'h00;

        imem[28] = 8'h13; // xori x6, x1, -1    ; x6 = ~x1 = 0x00FF00FF
        imem[29] = 8'hC3;
        imem[30] = 8'hF0;
        imem[31] = 8'hFF;

        imem[32] = 8'h93; // srli x9, x1, 4     ; x9 = 0x0FF00FF0
        imem[33] = 8'hD4;
        imem[34] = 8'h40;
        imem[35] = 8'h00;

        imem[36] = 8'h33; // sll  x10, x2, x9   ; shift amt = x9[4:0]=16 -> x10=0x0F0F0000
        imem[37] = 8'h15;
        imem[38] = 8'h91;
        imem[39] = 8'h00;

        // ==================================================================
        // PHASE B  –  SLT / SLTU / SLTI / SLTIU  (imem 10-16)
        // ==================================================================
        imem[40] = 8'h93; // addi x11, x0, -1   ; x11 = 0xFFFFFFFF
        imem[41] = 8'h05;
        imem[42] = 8'hF0;
        imem[43] = 8'hFF;

        imem[44] = 8'h13; // addi x12, x0, 1    ; x12 = 1
        imem[45] = 8'h06;
        imem[46] = 8'h10;
        imem[47] = 8'h00;

        imem[48] = 8'hB3; // slt  x13, x11, x12 ; x13 = 1
        imem[49] = 8'hA6;
        imem[50] = 8'hC5;
        imem[51] = 8'h00;

        imem[52] = 8'h33; // sltu x14, x11, x12 ; x14 = 0
        imem[53] = 8'hB7;
        imem[54] = 8'hC5;
        imem[55] = 8'h00;

        imem[56] = 8'h93; // slti x15, x11, 0   ; x15 = 1
        imem[57] = 8'hA7;
        imem[58] = 8'h05;
        imem[59] = 8'h00;

        imem[60] = 8'h13; // sltiu x16, x11, 1  ; x16 = 0
        imem[61] = 8'hB8;
        imem[62] = 8'h15;
        imem[63] = 8'h00;

        imem[64] = 8'hB3; // slt  x17, x12, x11 ; x17 = 0
        imem[65] = 8'h28;
        imem[66] = 8'hB6;
        imem[67] = 8'h00;

        // ==================================================================
        // PHASE C  –  LUI / AUIPC  (imem 20-22)
        // ==================================================================
        imem[80] = 8'h37; // lui  x18, 0xABCDE  ; x18 = 0xABCDE000
        imem[81] = 8'hE9;
        imem[82] = 8'hCD;
        imem[83] = 8'hAB;

        imem[84] = 8'h97; // auipc x19, 0       ; x19 = PC = 0x54
        imem[85] = 8'h09;
        imem[86] = 8'h00;
        imem[87] = 8'h00;

        imem[88] = 8'h17; // auipc x20, 0xFFFFF ; x20 = 0xFFFFF000+0x58 = 0xFFFFF058
        imem[89] = 8'hFA;
        imem[90] = 8'hFF;
        imem[91] = 8'hFF;

        // ==================================================================
        // PHASE D  –  Double Forwarding  (imem 30-34)
        // ==================================================================
        imem[120] = 8'h93; // addi x21, x0, 7    ; x21 = 7
        imem[121] = 8'h0A;
        imem[122] = 8'h70;
        imem[123] = 8'h00;

        imem[124] = 8'h13; // addi x22, x0, 3    ; x22 = 3
        imem[125] = 8'h0B;
        imem[126] = 8'h30;
        imem[127] = 8'h00;

        imem[128] = 8'hB3; // add  x21, x21, x22 ; x21 = 10
        imem[129] = 8'h8A;
        imem[130] = 8'h6A;
        imem[131] = 8'h01;

        imem[132] = 8'h33; // sub  x22, x21, x22 ; x22 = 7
        imem[133] = 8'h8B;
        imem[134] = 8'h6A;
        imem[135] = 8'h41;

        imem[136] = 8'hB3; // add  x23, x21, x22 ; x23 = 17
        imem[137] = 8'h8B;
        imem[138] = 8'h6A;
        imem[139] = 8'h01;

        // ==================================================================
        // PHASE E  –  Load-Use Stall & Gap  (imem 40-46)
        // ==================================================================
        imem[160] = 8'h13; // addi x24, x0, 128  ; x24 = 0x80
        imem[161] = 8'h0C;
        imem[162] = 8'h00;
        imem[163] = 8'h08;

        imem[164] = 8'h83; // lw   x25, 0(x24)   ; x25 = 0xDEADBEEF
        imem[165] = 8'h2C;
        imem[166] = 8'h0C;
        imem[167] = 8'h00;

        imem[168] = 8'h33; // add  x26, x25, x0  ; x26 = 0xDEADBEEF
        imem[169] = 8'h8D;
        imem[170] = 8'h0C;
        imem[171] = 8'h00;

        imem[172] = 8'h83; // lw   x27, 4(x24)   ; x27 = 0x12345678
        imem[173] = 8'h2D;
        imem[174] = 8'h4C;
        imem[175] = 8'h00;

        imem[176] = 8'h13; // nop
        imem[177] = 8'h00;
        imem[178] = 8'h00;
        imem[179] = 8'h00;

        imem[180] = 8'h13; // nop
        imem[181] = 8'h00;
        imem[182] = 8'h00;
        imem[183] = 8'h00;

        imem[184] = 8'h33; // add  x28, x27, x0  ; x28 = 0x12345678
        imem[185] = 8'h8E;
        imem[186] = 8'h0D;
        imem[187] = 8'h00;

        // ==================================================================
        // PHASE F  –  Byte / Halfword Loads and Stores  (imem 50-55)
        // ==================================================================
        imem[200] = 8'h83; // lb   x29, 0(x24)   ; x29 = 0xFFFFFFEF
        imem[201] = 8'h0E;
        imem[202] = 8'h0C;
        imem[203] = 8'h00;

        imem[204] = 8'h03; // lbu  x30, 0(x24)   ; x30 = 0x000000EF
        imem[205] = 8'h4F;
        imem[206] = 8'h0C;
        imem[207] = 8'h00;

        imem[208] = 8'h83; // lh   x31, 0(x24)   ; x31 = 0xFFFFBEEF
        imem[209] = 8'h1F;
        imem[210] = 8'h0C;
        imem[211] = 8'h00;

        imem[212] = 8'h83; // lhu  x5,  0(x24)   ; x5  = 0x0000BEEF
        imem[213] = 8'h52;
        imem[214] = 8'h0C;
        imem[215] = 8'h00;

        imem[216] = 8'h23; // sb   x11, 8(x24)   ; dmem[34] byte[0] = 0xFF
        imem[217] = 8'h04;
        imem[218] = 8'hBC;
        imem[219] = 8'h00;

        imem[220] = 8'h23; // sh   x12, 12(x24)  ; dmem[35] hw[0] = 0x0001
        imem[221] = 8'h16;
        imem[222] = 8'hCC;
        imem[223] = 8'h00;

        // ==================================================================
        // PHASE G  –  Branch Forwarding Hazard  (imem 60-65)
        // ==================================================================
        imem[240] = 8'h13; // addi x6, x0, 42    ; x6 = 42
        imem[241] = 8'h03;
        imem[242] = 8'hA0;
        imem[243] = 8'h02;

        imem[244] = 8'h93; // addi x7, x0, 42    ; x7 = 42
        imem[245] = 8'h03;
        imem[246] = 8'hA0;
        imem[247] = 8'h02;

        imem[248] = 8'h63; // beq  x6, x7, +12   ; branch taken to imem[65]
        imem[249] = 8'h06;
        imem[250] = 8'h73;
        imem[251] = 8'h00;

        imem[252] = 8'h13; // addi x8, x0, 99    ; TRAITOR slot 1
        imem[253] = 8'h04;
        imem[254] = 8'h30;
        imem[255] = 8'h06;

        imem[256] = 8'h13; // addi x8, x0, 99    ; TRAITOR slot 2
        imem[257] = 8'h04;
        imem[258] = 8'h30;
        imem[259] = 8'h06;

        imem[260] = 8'h13; // addi x8, x0, 55    ; REAL: x8 = 55
        imem[261] = 8'h04;
        imem[262] = 8'h70;
        imem[263] = 8'h03;

        // ==================================================================
        // PHASE H  –  Full Branch Suite: BLT, BGE, BLTU, BGEU  (imem 70-79)
        // ==================================================================
        imem[280] = 8'h93; // addi x11, x0, -1
        imem[281] = 8'h05;
        imem[282] = 8'hF0;
        imem[283] = 8'hFF;

        imem[284] = 8'h13; // addi x12, x0, 1
        imem[285] = 8'h06;
        imem[286] = 8'h10;
        imem[287] = 8'h00;

        imem[288] = 8'h63; // blt  x11, x12, +8  ; taken -> imem[74]
        imem[289] = 8'hC4;
        imem[290] = 8'hC5;
        imem[291] = 8'h00;

        imem[292] = 8'h93; // addi x17, x0, 99   ; TRAITOR
        imem[293] = 8'h08;
        imem[294] = 8'h30;
        imem[295] = 8'h06;

        imem[296] = 8'h93; // addi x17, x0, 1    ; x17 = 1
        imem[297] = 8'h08;
        imem[298] = 8'h10;
        imem[299] = 8'h00;

        imem[300] = 8'h63; // bge  x12, x11, +8  ; taken -> imem[77]
        imem[301] = 8'h54;
        imem[302] = 8'hB6;
        imem[303] = 8'h00;

        imem[304] = 8'h13; // addi x18, x0, 99   ; TRAITOR
        imem[305] = 8'h09;
        imem[306] = 8'h30;
        imem[307] = 8'h06;

        imem[308] = 8'h13; // addi x18, x0, 1    ; x18 = 1
        imem[309] = 8'h09;
        imem[310] = 8'h10;
        imem[311] = 8'h00;

        imem[312] = 8'h63; // bltu x12, x11, +8  ; taken -> imem[80]
        imem[313] = 8'h64;
        imem[314] = 8'hB6;
        imem[315] = 8'h00;

        imem[316] = 8'h93; // addi x19, x0, 99   ; TRAITOR
        imem[317] = 8'h09;
        imem[318] = 8'h30;
        imem[319] = 8'h06;

        // ==================================================================
        // PHASE I  –  Taken BEQ / Tight Backward Branch (Loop)  (imem 80-85)
        // ==================================================================
        imem[320] = 8'h93; // addi x19, x0, 1    ; x19 = 1
        imem[321] = 8'h09;
        imem[322] = 8'h10;
        imem[323] = 8'h00;

        imem[324] = 8'h63; // bgeu x11, x12, +8  ; taken -> imem[83]
        imem[325] = 8'hF4;
        imem[326] = 8'hC5;
        imem[327] = 8'h00;

        imem[328] = 8'h13; // addi x20, x0, 99   ; TRAITOR
        imem[329] = 8'h0A;
        imem[330] = 8'h30;
        imem[331] = 8'h06;

        imem[332] = 8'h13; // addi x20, x0, 3    ; x20 = 3
        imem[333] = 8'h0A;
        imem[334] = 8'h30;
        imem[335] = 8'h00;

        imem[336] = 8'h13; // addi x20, x20, -1  ; x20--
        imem[337] = 8'h0A;
        imem[338] = 8'hFA;
        imem[339] = 8'hFF;

        imem[340] = 8'hE3; // bne  x20, x0, -4   ; loop back to imem[84]
        imem[341] = 8'h1E;
        imem[342] = 8'h0A;
        imem[343] = 8'hFE;

        // ==================================================================
        // PHASE J  –  JAL Return-Address Verification  (imem 90-94)
        // ==================================================================
        imem[360] = 8'hEF; // jal  x1, +12      ; x1 = 0x16C, PC -> imem[93]
        imem[361] = 8'h00;
        imem[362] = 8'hC0;
        imem[363] = 8'h00;

        imem[364] = 8'h93; // addi x21, x0, 99   ; TRAITOR
        imem[365] = 8'h0A;
        imem[366] = 8'h30;
        imem[367] = 8'h06;

        imem[368] = 8'h93; // addi x21, x0, 99   ; TRAITOR
        imem[369] = 8'h0A;
        imem[370] = 8'h30;
        imem[371] = 8'h06;

        imem[372] = 8'h13; // nop                ; landing pad
        imem[373] = 8'h00;
        imem[374] = 8'h00;
        imem[375] = 8'h00;

        imem[376] = 8'h33; // add  x22, x1, x0   ; x22 = return addr = 0x16C
        imem[377] = 8'h8B;
        imem[378] = 8'h00;
        imem[379] = 8'h00;

        // ==================================================================
        // PHASE K  –  JALR LSB-clearing & Return Address  (imem 100-104)
        // ==================================================================
        imem[400] = 8'h13; // addi x4, x0, 0x19D ; x4 = 0x19D (odd addr)
        imem[401] = 8'h02;
        imem[402] = 8'hD0;
        imem[403] = 8'h19;

        imem[404] = 8'h67; // jalr x2, 0(x4)     ; PC = 0x19C, x2 = 0x198
        imem[405] = 8'h01;
        imem[406] = 8'h02;
        imem[407] = 8'h00;

        imem[408] = 8'h13; // addi x2, x0, 99    ; TRAITOR
        imem[409] = 8'h01;
        imem[410] = 8'h30;
        imem[411] = 8'h06;

        imem[412] = 8'h13; // nop                ; landing (0x19C = imem[103])
        imem[413] = 8'h00;
        imem[414] = 8'h00;
        imem[415] = 8'h00;

        imem[416] = 8'hB3; // add  x23, x2, x0   ; x23 = JALR link = 0x198
        imem[417] = 8'h0B;
        imem[418] = 8'h01;
        imem[419] = 8'h00;

        // ==================================================================
        // PHASE L  –  Write to x0 Must Stay Zero  (imem 110-113)
        // ==================================================================
        imem[440] = 8'h13; // addi x0, x0, 10    ; attempt write to x0
        imem[441] = 8'h00;
        imem[442] = 8'hA0;
        imem[443] = 8'h00;

        imem[444] = 8'h33; // add  x0, x11, x12  ; attempt write to x0
        imem[445] = 8'h80;
        imem[446] = 8'hC5;
        imem[447] = 8'h00;

        imem[448] = 8'h37; // lui  x0, 0xABCDE   ; attempt write to x0
        imem[449] = 8'hE0;
        imem[450] = 8'hCD;
        imem[451] = 8'hAB;

        imem[452] = 8'h33; // add  x24, x0, x0   ; x24 must be 0
        imem[453] = 8'h0C;
        imem[454] = 8'h00;
        imem[455] = 8'h00;

        // ==================================================================
        // PHASE M  –  Reset Mid-Execution  (imem 120-126)
        // ==================================================================
        imem[480] = 8'h93; // addi x25, x0, 5
        imem[481] = 8'h0C;
        imem[482] = 8'h50;
        imem[483] = 8'h00;

        imem[484] = 8'h13; // addi x26, x0, 10
        imem[485] = 8'h0D;
        imem[486] = 8'hA0;
        imem[487] = 8'h00;

        imem[488] = 8'h93; // addi x27, x0, 15
        imem[489] = 8'h0D;
        imem[490] = 8'hF0;
        imem[491] = 8'h00;

        imem[492] = 8'h13; // addi x28, x0, 20
        imem[493] = 8'h0E;
        imem[494] = 8'h40;
        imem[495] = 8'h01;

        imem[496] = 8'h93; // addi x29, x0, 25
        imem[497] = 8'h0E;
        imem[498] = 8'h90;
        imem[499] = 8'h01;

        imem[500] = 8'h93; // addi x30, x0, 7    ; after reset, x30 = 7
        imem[501] = 8'h0F;
        imem[502] = 8'h70;
        imem[503] = 8'h00;

        imem[504] = 8'h93; // addi x31, x0, 9    ; after reset, x31 = 9
        imem[505] = 8'h0F;
        imem[506] = 8'h90;
        imem[507] = 8'h00;

        // ==================================================================
        // PHASE N  –  Store Data Forwarding
        //             ALU result immediately consumed by SW/SB/SH
        //
        //             New data region: byte address 0x200
        //             dmem[512..515]
        // ==================================================================

        // x1 = 0x55
        imem[520] = 8'h93; // addi x1, x0, 85
        imem[521] = 8'h00;
        imem[522] = 8'h50;
        imem[523] = 8'h05;

        // x2 = 0x200
        imem[524] = 8'h13; // addi x2, x0, 512
        imem[525] = 8'h01;
        imem[526] = 8'h00;
        imem[527] = 8'h20;

        // sw x1, 0(x2)
        imem[528] = 8'h23;
        imem[529] = 8'h20;
        imem[530] = 8'h11;
        imem[531] = 8'h00;

        // lw x3, 0(x2)
        imem[532] = 8'h83;
        imem[533] = 8'h21;
        imem[534] = 8'h01;
        imem[535] = 8'h00;

        // x4 = 0xAA
        imem[536] = 8'h13; // addi x4, x0, 0xAA
        imem[537] = 8'h02;
        imem[538] = 8'hA0;
        imem[539] = 8'h0A;

        // sb x4, 1(x2)
        imem[540] = 8'hA3;
        imem[541] = 8'h00;
        imem[542] = 8'h41;
        imem[543] = 8'h00;

        // x5 = 0x123
        imem[544] = 8'h93; // addi x5, x0, 0x123
        imem[545] = 8'h02;
        imem[546] = 8'h30;
        imem[547] = 8'h12;

        // sh x5, 2(x2)
        imem[548] = 8'h23;
        imem[549] = 8'h11;
        imem[550] = 8'h51;
        imem[551] = 8'h00;


        // ==================================================================
        // PHASE O  –  Load -> Store Hazard
        //             lw followed immediately by sw
        //
        //             Source: dmem[516..519] = 0xCAFEBABE
        //             Destination: dmem[520..523]
        // ==================================================================

        // x2 = 0x204
        imem[560] = 8'h13; // addi x2, x0, 516
        imem[561] = 8'h01;
        imem[562] = 8'h40;
        imem[563] = 8'h20;

        // lw x1, 0(x2)
        imem[564] = 8'h83;
        imem[565] = 8'h20;
        imem[566] = 8'h01;
        imem[567] = 8'h00;

        // sw x1, 4(x2)
        imem[568] = 8'h23;
        imem[569] = 8'h22;
        imem[570] = 8'h11;
        imem[571] = 8'h00;

        // lw x3, 4(x2)
        imem[572] = 8'h83;
        imem[573] = 8'h21;
        imem[574] = 8'h41;
        imem[575] = 8'h00;


        // ==================================================================
        // PHASE P  –  Load -> Branch Hazard
        //             Load followed immediately by branch
        //
        //             Source: dmem[512..515] = 0x00000055
        // ==================================================================

        // x2 = 0x200
        imem[600] = 8'h13; // addi x2, x0, 512
        imem[601] = 8'h01;
        imem[602] = 8'h00;
        imem[603] = 8'h20;

        // lw x1, 0(x2)
        imem[604] = 8'h83;
        imem[605] = 8'h20;
        imem[606] = 8'h01;
        imem[607] = 8'h00;

        // x4 = 0x55
        imem[608] = 8'h13; // addi x4, x0, 85
        imem[609] = 8'h02;
        imem[610] = 8'h50;
        imem[611] = 8'h05;

        // bne x1, x4, +12
        // Must be taken: 0x55 == 0x55
        imem[612] = 8'h63;
        imem[613] = 8'h96;
        imem[614] = 8'h40;
        imem[615] = 8'h00;

        // TRAITOR
        imem[616] = 8'h93; // addi x3, x0, 99
        imem[617] = 8'h01;
        imem[618] = 8'h30;
        imem[619] = 8'h06;

        // TRAITOR
        imem[620] = 8'h93; // addi x3, x0, 99
        imem[621] = 8'h01;
        imem[622] = 8'h30;
        imem[623] = 8'h06;

        // TARGET
        imem[624] = 8'h93; // addi x3, x0, 42
        imem[625] = 8'h01;
        imem[626] = 8'hA0;
        imem[627] = 8'h02;


        // ==================================================================
        // PHASE Q  –  ALU -> JALR Hazard
        //             JALR base comes directly from preceding ALU result
        // ==================================================================

        // x4 = 0x2A0
        imem[640] = 8'h13; // addi x4, x0, 0x2A0
        imem[641] = 8'h02;
        imem[642] = 8'h00;
        imem[643] = 8'h2A;

        // jalr x1, 0(x4)
        // target = 0x2A0 = instruction 168
        // link = PC + 4
        imem[644] = 8'hE7;
        imem[645] = 8'h00;
        imem[646] = 8'h42;
        imem[647] = 8'h00;

        // TRAITOR
        imem[648] = 8'h93;
        imem[649] = 8'h02;
        imem[650] = 8'h30;
        imem[651] = 8'h06;

        // TRAITOR
        imem[652] = 8'h93;
        imem[653] = 8'h02;
        imem[654] = 8'h30;
        imem[655] = 8'h06;

        // TARGET: instruction 168
        imem[672] = 8'h93; // addi x5, x0, 42
        imem[673] = 8'h02;
        imem[674] = 8'hA0;
        imem[675] = 8'h02;

        // add x6, x1, x0
        imem[676] = 8'h33;
        imem[677] = 8'h83;
        imem[678] = 8'h00;
        imem[679] = 8'h00;


        // ==================================================================
        // PHASE R  –  x0 Forwarding Suppression
        // ==================================================================

        // x1 = 7
        imem[700] = 8'h93; // addi x1, x0, 7
        imem[701] = 8'h00;
        imem[702] = 8'h70;
        imem[703] = 8'h00;

        // Attempt to write 130 into x0
        imem[704] = 8'h13; // addi x0, x1, 123
        imem[705] = 8'h80;
        imem[706] = 8'hB0;
        imem[707] = 8'h07;

        // add x2, x0, x0
        imem[708] = 8'h33;
        imem[709] = 8'h01;
        imem[710] = 8'h00;
        imem[711] = 8'h00;


        // ==================================================================
        // PHASE S  –  Shift Corner Cases
        // ==================================================================

        // x1 = -1
        imem[720] = 8'h93; // addi x1, x0, -1
        imem[721] = 8'h00;
        imem[722] = 8'hF0;
        imem[723] = 8'hFF;

        // srai x2, x1, 1
        imem[724] = 8'h13;
        imem[725] = 8'hD1;
        imem[726] = 8'h10;
        imem[727] = 8'h40;

        // srli x3, x1, 1
        imem[728] = 8'h93;
        imem[729] = 8'hD1;
        imem[730] = 8'h10;
        imem[731] = 8'h00;

        // slli x4, x1, 31
        imem[732] = 8'h13;
        imem[733] = 8'h92;
        imem[734] = 8'hF0;
        imem[735] = 8'h01;

        // x5 = 32
        imem[736] = 8'h93;
        imem[737] = 8'h02;
        imem[738] = 8'h00;
        imem[739] = 8'h02;

        // sll x6, x1, x5
        imem[740] = 8'h33;
        imem[741] = 8'h93;
        imem[742] = 8'h50;
        imem[743] = 8'h00;

        // x7 = 33
        imem[744] = 8'h93;
        imem[745] = 8'h03;
        imem[746] = 8'h10;
        imem[747] = 8'h02;

        // sll x8, x1, x7
        imem[748] = 8'h33;
        imem[749] = 8'h94;
        imem[750] = 8'h70;
        imem[751] = 8'h00;


        // ==================================================================
        // PHASE T  –  Branch Not Taken
        // ==================================================================

        // x1 = 1
        imem[780] = 8'h93;
        imem[781] = 8'h00;
        imem[782] = 8'h10;
        imem[783] = 8'h00;

        // x2 = 2
        imem[784] = 8'h13;
        imem[785] = 8'h01;
        imem[786] = 8'h20;
        imem[787] = 8'h00;

        // beq x1, x2, +12
        // NOT taken
        imem[788] = 8'h63;
        imem[789] = 8'h86;
        imem[790] = 8'h20;
        imem[791] = 8'h00;

        // Must execute: x3 = 42
        imem[792] = 8'h93;
        imem[793] = 8'h01;
        imem[794] = 8'hA0;
        imem[795] = 8'h02;

        // Must execute: x4 = 43
        imem[796] = 8'h13;
        imem[797] = 8'h02;
        imem[798] = 8'hB0;
        imem[799] = 8'h02;


        // ==================================================================
        // PHASE U  –  Store Byte Lane Selection
        //
        //             New test word:
        //             dmem[524..527] = 0x11223344
        // ==================================================================

        // x2 = 0x20C = byte address 524
        imem[820] = 8'h13;
        imem[821] = 8'h01;
        imem[822] = 8'hC0;
        imem[823] = 8'h20;

        // x1 = 0x11
        imem[824] = 8'h93;
        imem[825] = 8'h00;
        imem[826] = 8'h10;
        imem[827] = 8'h01;

        // sb x1, 0(x2)
        imem[828] = 8'h23;
        imem[829] = 8'h00;
        imem[830] = 8'h11;
        imem[831] = 8'h00;

        // x1 = 0x22
        imem[832] = 8'h93;
        imem[833] = 8'h00;
        imem[834] = 8'h20;
        imem[835] = 8'h02;

        // sb x1, 1(x2)
        imem[836] = 8'hA3;
        imem[837] = 8'h00;
        imem[838] = 8'h11;
        imem[839] = 8'h00;

        // x1 = 0x33
        imem[840] = 8'h93;
        imem[841] = 8'h00;
        imem[842] = 8'h30;
        imem[843] = 8'h03;

        // sb x1, 2(x2)
        imem[844] = 8'h23;
        imem[845] = 8'h01;
        imem[846] = 8'h11;
        imem[847] = 8'h00;

        // x1 = 0x44
        imem[848] = 8'h93;
        imem[849] = 8'h00;
        imem[850] = 8'h40;
        imem[851] = 8'h04;

        // sb x1, 3(x2)
        imem[852] = 8'hA3;
        imem[853] = 8'h01;
        imem[854] = 8'h11;
        imem[855] = 8'h00;
    end
endmodule
