//------------------------------------------------------------------------------
// Author      : Brian Liau (brian.liau@tufts.edu)
// File        : AHB_imem_interconnect.sv
// Design Unit : AHB_imem_interconnect
// Description : AHB_Lite instruction bus interconnect 
// Dependencies: AHB_pkg.sv
// Target      : Synthesis
//------------------------------------------------------------------------------
module AHB_imem_interconnect 
(
    input  logic                            HCLK,
    input  logic                            HRESETn,
    input  logic [31:0]                     HADDR,
    input  logic [31:0]                     HRDATA_S [AHB_pkg::NTOTAL_I],
    input  logic [AHB_pkg::NTOTAL_I-1:0]    HREADYOUT_S,
    input  logic [AHB_pkg::NTOTAL_I-1:0]    HRESP_S,
    output logic [31:0]                     HRDATA,
    output logic                            HREADY,
    output logic                            HRESP,
    output logic [AHB_pkg::NTOTAL_I-1:0]    HSELx
);    
    import AHB_pkg::*;

    // Subordinate selection signals
    logic [NUM_SUBORDINATES_I-1:0]      hsel_subordinates;
    logic [NTOTAL_I-1:0]                hsel_comb;
    logic [NTOTAL_I-1:0]                hsel_dphase;
    assign HSELx = hsel_comb;

    // Selecting Subordinate (Address Phase)
    always_comb begin      
        for (int i = 0; i < NUM_SUBORDINATES_I; i++) begin
            hsel_subordinates[i] = HADDR >= BASE_ADDR_I[i] && HADDR < (BASE_ADDR_I[i] + ADDR_SIZE_I[i]);
        end

        // Append default subordinate selection bit at MSB if no address matched
        hsel_comb = {~(|hsel_subordinates), hsel_subordinates};
    end

    // Subordinate Transfer Operation (Data Phase)
    always_comb begin
        HRDATA = '0;
        HRESP  = 1'b0;
        HREADY = 1'b1;

        for (int i = 0; i < NUM_SUBORDINATES_I + 1; i++) begin
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