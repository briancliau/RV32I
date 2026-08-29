//------------------------------------------------------------------------------
// Author      : Brian Liau (brian.liau@tufts.edu)
// File        : AHB_data_top.sv
// Design Unit : AHB_data_top
// Description : AHB_Lite data bus connections for interconnect, default 
//               subordinates, and all subordinates.
// Dependencies: AHB_pkg.sv
// Target      : Synthesis
//------------------------------------------------------------------------------
module AHB_data_top 
(
    input  logic        HCLK,
    input  logic        HRESETn,
    input  logic [31:0] HADDR,
    input  logic [1:0]  HTRANS,
    input  logic        HWRITE,
    input  logic [2:0]  HSIZE,
    input  logic [31:0] HWDATA,
    output logic [31:0] HRDATA,
    output logic        HRESP,
    output logic        HREADY
);
    import AHB_pkg::*;

    // Interconnect output signals
    logic [NTOTAL_D-1:0]  HSELx;

    // Subordinate output arrays back to interconnect
    logic [NTOTAL_D-1:0]  HREADYOUT_S;
    logic [NTOTAL_D-1:0]  HRESP_S;
    logic [31:0]          HRDATA_S [NTOTAL_D];

    // Interconnect instantiation
    AHB_dmem_interconnect data_ic (
        .HCLK       (HCLK),
        .HRESETn    (HRESETn),
        .HADDR      (HADDR),
        .HRDATA_S   (HRDATA_S),
        .HREADYOUT_S(HREADYOUT_S),
        .HRESP_S    (HRESP_S),
        .HRDATA     (HRDATA),
        .HREADY     (HREADY),
        .HRESP      (HRESP),
        .HSELx      (HSELx)
    );

    // Subordinate instantiations
    generate
        for (genvar i = 0; i < NUM_SUBORDINATES_D; i++) begin : sub_gen
            if ((32'h1 << ADDR_BITS_D[i]) != ADDR_SIZE_D[i])
                $error("ADDR_SIZE[%0d] = 0x%0h is not a power of two", i, ADDR_SIZE_D[i]);
            if ((BASE_ADDR_D[i] & (ADDR_SIZE_D[i] - 1)) != 32'h0)
                $error("BASE_ADDR[%0d] = 0x%0h is not naturally aligned", i, BASE_ADDR_D[i]);
            
            AHB_dmem_subordinate #(.ADDR_BITS(ADDR_BITS_D[i]), .NUM_WAITS(WAIT_STATES_D[i])) subordinate
            (
                .HCLK      (HCLK),
                .HRESETn   (HRESETn),
                .HSELx     (HSELx[i]),
                .HREADY    (HREADY),
                .HWRITE    (HWRITE),
                .HADDR     (HADDR),
                .HSIZE     (HSIZE),
                .HTRANS    (HTRANS),
                .HWDATA    (HWDATA),
                .HRESP     (HRESP_S[i]),
                .HREADYOUT (HREADYOUT_S[i]),
                .HRDATA    (HRDATA_S[i])
            );
        end
    endgenerate

    // Default subordinate instantiation (out of address reponse)
    AHB_dmem_default_subordinate default_subordinate (
        .HCLK       (HCLK),
        .HRESETn    (HRESETn),
        .HSELx      (HSELx[DEFAULT_IDX_D]),
        .HREADY     (HREADY),
        .HTRANS     (HTRANS),
        .HREADYOUT  (HREADYOUT_S[DEFAULT_IDX_D]),
        .HRESP      (HRESP_S[DEFAULT_IDX_D]),
        .HRDATA     (HRDATA_S[DEFAULT_IDX_D])
    );

endmodule
