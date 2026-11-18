//------------------------------------------------------------------------------
// Author      : Brian Liau (brian.liau@tufts.edu)
// File        : AHBInstructionManagerPort.sv
// Design Unit : AHBInstructionManagerPort
// Description : ASIC variant of AHBInstructionManager. Identical manager logic,
//               but the AHB-Lite bus is exposed as ports instead of connecting
//               to an internal interconnect/memory. Instruction memory lives
//               outside the hardened block (SRAM macro / off-block).
// Dependencies: rvDefs.sv, AHB_pkg.sv
// Target      : Synthesis (OpenLane2)
//------------------------------------------------------------------------------
module AHBInstructionManagerPort (
    input  logic                    clk,
    input  logic                    resetN,

    // Core-side interface
    input  logic                    nextInstructionFlag,
    input  rvDefs::mem_addr_t       instructionAddress,
    output rvDefs::word_t           instruction,
    output rvDefs::mem_addr_t       instructionAddressAHB,
    output logic                    HREADY_ibus,

    // AHB-Lite manager interface (to external interconnect)
    output rvDefs::word_t           HADDR,
    output logic [1:0]              HTRANS,
    output logic                    HWRITE,
    output logic [2:0]              HSIZE,
    output rvDefs::word_t           HWDATA,
    input  rvDefs::word_t           HRDATA,
    input  logic                    HRESP,
    input  logic                    HREADY
);
    logic           mem_access_req;
    logic           error_cancel;
    logic           bus_stage;
    rvDefs::word_t  instruction_addr_reg;
    rvDefs::word_t  instruction_reg;

    // Track active fetch requests and register returned instruction data
    always_ff @(posedge clk or negedge resetN) begin
        if (!resetN) begin
            instruction_addr_reg <= '0;
            bus_stage            <= 1'b0;
            instruction_reg      <= rvDefs::NOP;
        end else begin
            if (HREADY) begin
                instruction_addr_reg <= instructionAddress;
                bus_stage            <= nextInstructionFlag;
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
    assign mem_access_req        = (HREADY && resetN) ? nextInstructionFlag : bus_stage;
    assign HADDR                 = HREADY ? instructionAddress : instruction_addr_reg;
    assign HTRANS                = error_cancel ? AHB_pkg::IDLE : (mem_access_req ? AHB_pkg::NONSEQ : AHB_pkg::IDLE);
    assign HSIZE                 = 3'b010;
    assign HWRITE                = 1'b0;
    assign HWDATA                = '0;
    assign instruction           = (HREADY && bus_stage) ? HRDATA : instruction_reg;
    assign HREADY_ibus           = HREADY;
    assign instructionAddressAHB = instruction_addr_reg;

endmodule
