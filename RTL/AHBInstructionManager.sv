//------------------------------------------------------------------------------
// Author      : Brian Liau (brian.liau@tufts.edu)
// File        : AHBInstructionManager.sv
// Design Unit : AHBInstructionManager
// Description : AHB_Lite instruction bus manager that controls all transfers.
// Dependencies: AHB_pkg.sv
// Target      : Synthesis
//------------------------------------------------------------------------------
module AHBInstructionManager (
    input  logic                    clk,
    input  logic                    resetN,
    input  logic                    nextInstructionFlag,
    input  rvDefs::mem_addr_t       instructionAddress,
	output rvDefs::word_t           instruction,
    output rvDefs::mem_addr_t       instructionAddressAHB,
    output logic                    HREADY_ibus
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
    rvDefs::word_t  instruction_addr_reg;
    rvDefs::word_t  instruction_reg;
    
    // AHB Instruction Bus top-level interconnect instantiation
    AHB_instruction_top instruction_manager (
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

    // Track active fetch requests and register returned instruction data
    always_ff @(posedge clk or negedge resetN) begin
        if (!resetN) begin
            instruction_addr_reg <= '0;
            bus_stage <= 1'b0;
            instruction_reg <= rvDefs::NOP;
        end else begin
            if (HREADY) begin
                instruction_addr_reg <= instructionAddress;
                bus_stage <= nextInstructionFlag;
            end

            if (bus_stage) begin
                instruction_reg <= HRDATA;
            end
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

    // AHB Command Generation and Bus Assignments
    assign mem_access_req = (HREADY && resetN) ? nextInstructionFlag : bus_stage;
    assign HADDR = HREADY ? instructionAddress : instruction_addr_reg;
    assign HTRANS = error_cancel ? AHB_pkg::IDLE : (mem_access_req ? AHB_pkg::NONSEQ : AHB_pkg::IDLE);
    assign HSIZE = 3'b010;
    assign HWRITE = 1'b0;
    assign HWDATA = '0;
    assign instruction = (HREADY && bus_stage) ? HRDATA : instruction_reg;
    assign HREADY_ibus = HREADY;
    assign instructionAddressAHB = instruction_addr_reg;

endmodule
