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
    (* ram_style = "block" *) logic [7:0] imem [2**ADDR_BITS];

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
endmodule
