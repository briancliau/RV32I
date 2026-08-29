//------------------------------------------------------------------------------
// Author      : Brian Liau (brian.liau@tufts.edu)
// File        : AHB_dmem_subordinate.sv
// Design Unit : AHB_dmem_subordinate
// Description : AHB_Lite byte-addressable data memory module with dynamic wait 
//               states.
// Dependencies: AHB_pkg.sv
// Target      : Testbench Verification (Synthesis in yosis directory)
//------------------------------------------------------------------------------
module AHB_dmem_subordinate #(
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
    logic [7:0] dmem [2**ADDR_BITS];
    logic [3:0] byte_en;

    // Wait State Counter Logic
    localparam int unsigned counter_width = (NUM_WAITS > 0) ? $clog2(NUM_WAITS + 1) : 1;
    logic [counter_width-1:0] wait_count;

    // Byte Enable Generation based on transfer size and address
    always_comb begin
        case (size_reg) 
            BYTE:     byte_en = 4'b0001 << addr_reg[1:0];
            HALF:     byte_en = addr_reg[1] ? 4'b1100 : 4'b0011;
            WORD:     byte_en = 4'b1111;
            default:  byte_en = 4'b0000;
        endcase
    end

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

    // Memory Write Operation (Data Phase)
    always_ff @(posedge HCLK) begin
        if (dataphase_valid && HREADYOUT && write_reg) begin
            if (byte_en[3]) dmem[word_base + 3] <= HWDATA[31:24];
            if (byte_en[2]) dmem[word_base + 2] <= HWDATA[23:16];
            if (byte_en[1]) dmem[word_base + 1] <= HWDATA[15:8];
            if (byte_en[0]) dmem[word_base    ] <= HWDATA[7:0];
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
    assign HRDATA    = {dmem[word_base + 3], dmem[word_base + 2], dmem[word_base + 1], dmem[word_base]};

    // Preload default memory for testbench verification
    always_comb begin
        // Word 32: 0xDEADBEEF
        dmem [131] = 8'hDE;
        dmem [130] = 8'hAD;
        dmem [129] = 8'hBE;
        dmem [128] = 8'hEF;
        // Word 33: 0x12345678
        dmem [135] = 8'h12;
        dmem [134] = 8'h34;
        dmem [133] = 8'h56;
        dmem [132] = 8'h78;
        // Word 128 @ byte address 0x200
        // Initially zero.
        // Used by Phase N / Phase P.
        dmem[515] = 8'h00;
        dmem[514] = 8'h00;
        dmem[513] = 8'h00;
        dmem[512] = 8'h00;

        // Word 129 @ byte address 0x204
        // Source for Phase O.
        dmem[519] = 8'hCA;
        dmem[518] = 8'hFE;
        dmem[517] = 8'hBA;
        dmem[516] = 8'hBE;

        // Word 130 @ byte address 0x208
        // Destination for Phase O.
        // Initially zero.
        dmem[523] = 8'h00;
        dmem[522] = 8'h00;
        dmem[521] = 8'h00;
        dmem[520] = 8'h00;

        // Word 131 @ byte address 0x20C
        // Phase U byte-lane test.
        // Initial value = 0x11223344.
        dmem[527] = 8'h11;
        dmem[526] = 8'h22;
        dmem[525] = 8'h33;
        dmem[524] = 8'h44;
    end

endmodule
