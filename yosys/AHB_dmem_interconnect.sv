`timescale 1ns/1ps
import AHB_pkg::*;

//------------------------------------------------------------------------------
// Author      : Brian Liau (brian.liau@tufts.edu)
// File        : AHB_dmem_interconnect.sv
// Design Unit : AHB_dmem_interconnect
// Description : AHB_Lite data bus interconnect 
// Dependencies: AHB_pkg.sv
// Target      : Synthesis
//------------------------------------------------------------------------------
module AHB_dmem_interconnect 
(
    input  logic                HCLK,
    input  logic                HRESETn,
    input  logic [31:0]         HADDR,
    input  logic [31:0]         HRDATA_S [NTOTAL_D],
    input  logic [NTOTAL_D-1:0] HREADYOUT_S,
    input  logic [NTOTAL_D-1:0] HRESP_S,
    output logic [31:0]         HRDATA,
    output logic                HREADY,
    output logic                HRESP,
    output logic [NTOTAL_D-1:0] HSELx
);    
    // Subordinate selection signals
    logic [NUM_SUBORDINATES_D-1:0]      hsel_subordinates;
    logic [NTOTAL_D-1:0]                hsel_comb;
    logic [NTOTAL_D-1:0]                hsel_dphase;
    assign HSELx = hsel_comb;

    // Selecting Subordinate (Address Phase)
    always_comb begin      
        for (int i = 0; i < NUM_SUBORDINATES_D; i++) begin
            hsel_subordinates[i] = HADDR >= BASE_ADDR_D[i] && HADDR < (BASE_ADDR_D[i] + ADDR_SIZE_D[i]);
        end

        // Append default subordinate selection bit at MSB if no address matched
        hsel_comb = {~(|hsel_subordinates), hsel_subordinates};
    end

    // Subordinate Transfer Operation (Data Phase)
    always_comb begin
        HRDATA = '0;
        HRESP  = 1'b0;
        HREADY = 1'b1;

        for (int i = 0; i < NUM_SUBORDINATES_D + 1; i++) begin
            if (hsel_dphase[i]) begin
                HRDATA = HRDATA_S[i];
                HRESP = HRESP_S[i];
                HREADY = HREADYOUT_S[i];
            end
        end
    end

    // Pipeline address phase selection to data phase when bus is ready
    always_ff @(posedge HCLK or negedge HRESETn) begin
        if (!HRESETn) begin
            hsel_dphase <= '0;
        end else if (HREADY) begin
            hsel_dphase <= hsel_comb;
        end
    end
endmodule