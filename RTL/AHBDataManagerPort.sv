//------------------------------------------------------------------------------
// Author      : Brian Liau (brian.liau@tufts.edu)
// File        : AHBDataManagerPort.sv
// Design Unit : AHBDataManagerPort
// Description : ASIC variant of AHBDataManager. Identical manager logic, but
//               the AHB-Lite bus is exposed as ports instead of connecting to
//               an internal interconnect/memory. Data memory lives outside the
//               hardened block (SRAM macro / off-block).
// Dependencies: rvDefs.sv, AHB_pkg.sv
// Target      : Synthesis (OpenLane2)
//------------------------------------------------------------------------------
module AHBDataManagerPort (
    input  logic                clk,
    input  logic                resetN,

    // Core-side interface
    input  logic                memWrite,
    input  logic                memRead,
    input  rvDefs::mem_addr_t   address,
    input  rvDefs::word_t       writeData,
    input  logic [2:0]          memSize,
    output rvDefs::word_t       readData,
    output logic                HREADY_dbus,

    // AHB-Lite manager interface (to external interconnect)
    output rvDefs::word_t       HADDR,
    output logic [1:0]          HTRANS,
    output logic                HWRITE,
    output logic [2:0]          HSIZE,
    output rvDefs::word_t       HWDATA,
    input  rvDefs::word_t       HRDATA,
    input  logic                HRESP,
    input  logic                HREADY
);
    logic           mem_access_req;
    logic           error_cancel;
    rvDefs::word_t  hwdata_reg;

    // Pipeline write data from CPU to align with AHB Data Phase when HREADY is high
    always_ff @(posedge clk or negedge resetN) begin
        if (!resetN) begin
            hwdata_reg <= '0;
        end else if (HREADY) begin
            hwdata_reg <= writeData;
        end
    end

    // Cancel pending transfer (drive IDLE) during second cycle of AHB error response
    always_ff @(posedge clk or negedge resetN) begin
        if (!resetN) begin
            error_cancel <= 1'b0;
        end else begin
            if (HRESP && !HREADY) begin
                error_cancel <= 1'b1;
            end else if (HREADY) begin
                error_cancel <= 1'b0;
            end
        end
    end

    // AHB Transfer Signal assignments based off LSU inputs
    assign mem_access_req = memRead || memWrite;
    assign HTRANS         = error_cancel ? AHB_pkg::IDLE : (mem_access_req ? AHB_pkg::NONSEQ : AHB_pkg::IDLE);
    assign HADDR          = address;
    assign HSIZE          = memSize;
    assign HWDATA         = hwdata_reg;
    assign HWRITE         = memWrite;
    assign readData       = HRDATA;
    assign HREADY_dbus    = HREADY;

endmodule
