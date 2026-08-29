//------------------------------------------------------------------------------
// Author      : Brian Liau (brian.liau@tufts.edu)
// File        : AHBDataManager.sv
// Design Unit : AHBDataManager
// Description : AHB_Lite data bus manager that controls all transfers.
// Dependencies: AHB_pkg.sv
// Target      : Synthesis
//------------------------------------------------------------------------------
module AHBDataManager 
(
    input  logic                clk,
    input  logic                resetN,
    input  logic                memWrite,
    input  logic                memRead,
    input  rvDefs::mem_addr_t   address,
    input  rvDefs::word_t       writeData,
    input  logic [2:0]          memSize,
	output rvDefs::word_t       readData,
    output logic                HREADY_dbus
);
    // AHB Manager and Transfer Signals
    logic           mem_access_req;
    logic           error_cancel;
    rvDefs::word_t  HADDR;
    logic [1:0]     HTRANS;
    logic           HWRITE;
    logic [2:0]     HSIZE;
    rvDefs::word_t  HWDATA;
    rvDefs::word_t  HRDATA;
    logic           HRESP;
    logic           HREADY;
    logic           bus_stage;
    rvDefs::word_t  hwdata_reg;    

    // AHB Data Bus top-level interconnect instantiation
    AHB_data_top data_manager (
        .HCLK   (clk), 
        .HRESETn(resetN),
        .HADDR  (HADDR),
        .HTRANS (HTRANS),
        .HWRITE (HWRITE),
        .HSIZE  (HSIZE),
        .HWDATA (HWDATA),
        .HRDATA (HRDATA),
        .HRESP  (HRESP),
        .HREADY (HREADY)
    );

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
    assign HADDR = address;
    assign HTRANS = error_cancel ? AHB_pkg::IDLE : (mem_access_req ? AHB_pkg::NONSEQ : AHB_pkg::IDLE);
    assign HSIZE = memSize;
    assign HWDATA = hwdata_reg;
    assign HWRITE = memWrite;
    assign readData = HRDATA;
    assign HREADY_dbus = HREADY;

endmodule
