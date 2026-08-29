//------------------------------------------------------------------------------
// Author      : Brian Liau (brian.liau@tufts.edu)
// File        : AHB_dmem_subordinate.sv
// Design Unit : AHB_dmem_subordinate
// Description : AHB_Lite byte-addressable data memory module with dynamic wait 
//               states.
// Dependencies: AHB_pkg.sv
// Target      : Synthesis
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
    (* ram_style = "block" *) logic [7:0] dmem [2**ADDR_BITS];
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
endmodule
