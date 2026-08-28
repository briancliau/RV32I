`timescale 1ns/1ps

//------------------------------------------------------------------------------
// Author      : Brian Liau (brian.liau@tufts.edu)
// File        : AHB_imem_default_subordinate.sv
// Design Unit : AHB_imem_default_subordinate
// Description : AHB_Lite default subordinate with two-cycle error response for
//               memory accesses to unmapped address spaces.
// Dependencies: AHB_pkg.sv
// Target      : Synthesis
//------------------------------------------------------------------------------
module AHB_imem_default_subordinate (
    input  logic        HCLK,
    input  logic        HRESETn,
    input  logic        HSELx,
    input  logic        HREADY,
    input  logic [1:0]  HTRANS,
    output logic        HREADYOUT,
    output logic        HRESP,
    output logic [31:0] HRDATA
);
    // AHB-Lite Address Phase Latching 
    logic addr_accept;
    logic dataphase_valid;
    logic error_second;

    // Accept new transfers when NONSEQ (2'b10) or SEQ (2'b11) transfers
    assign addr_accept = HSELx && HTRANS[1];

    // Default Error response for instruction memory read
    assign HRDATA = rvDefs::NOP;

    // Latch address phase into data phase
    always_ff @(posedge HCLK or negedge HRESETn) begin
        if (!HRESETn) begin
            dataphase_valid <= 1'b0;
        end else if (HREADY) begin
            dataphase_valid <= addr_accept;
        end
    end

    // Two-cycle error response generator state machine
    always_ff @(posedge HCLK or negedge HRESETn) begin
        if (!HRESETn) begin
            error_second <= 1'b0;
        end else begin
            error_second <= dataphase_valid && !error_second;
        end
    end

    // Output Assignments
    assign HRESP = dataphase_valid;
    assign HREADYOUT = ~(dataphase_valid && !error_second);
endmodule
