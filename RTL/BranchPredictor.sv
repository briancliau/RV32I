//------------------------------------------------------------------------------
// Author      : Brian Liau (brian.liau@tufts.edu)
// File        : BranchPredictor.sv
// Design Unit : BranchPredictor
// Description : Combinational branch jump prediction with 2-bit saturation
//               counter and branch correction based off the branch outcome.
// Dependencies: rvDefs.sv
// Target      : Synthesis
//------------------------------------------------------------------------------
module BranchPredictor (
    input  logic                clk,
    input  logic                resetN,
    input  logic                branchRequested,   // branch/JAL decoded in ID (prediction lookup)
    input  logic                branchResolved,    // a branch is in EX and advancing this cycle
    input  logic                branchTaken,       // its actual outcome
    output logic                branchPrediction
);
    logic [1:0] saturationCounter;

    assign branchPrediction = branchRequested && (saturationCounter >= 2'b10);

    always_ff @(posedge clk or negedge resetN) begin
        if (!resetN) begin
            saturationCounter <= 2'b01;
        end else if (branchResolved) begin
            if (branchTaken  && saturationCounter != 2'b11) saturationCounter <= saturationCounter + 1'b1;
            else if (!branchTaken && saturationCounter != 2'b00) saturationCounter <= saturationCounter - 1'b1;
        end
    end
endmodule