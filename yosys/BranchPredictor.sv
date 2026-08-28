`timescale 1ns/1ps

//------------------------------------------------------------------------------
// Author      : Brian Liau (brian.liau@tufts.edu)
// File        : BranchPredictor.sv
// Design Unit : BranchPredictor
// Description : Combinational branch jump prediction with 2-bit saturation
//               counter and branch correction based off the branch outcome.
// Dependencies: rvDefs.sv
// Target      : Synthesis
//------------------------------------------------------------------------------
module BranchPredictor 
(
    input  logic                clk,
    input  logic                resetN,
    input  logic                branchTaken,
    input  logic                branchRequested,
    output logic                branchPrediction
);
    // 2-bit Saturation Counter
    logic [1:0]             saturationCounter;

    // Combinational assignment for branch prediction
    assign branchPrediction = branchRequested && (saturationCounter >= 2'b10);
    
    // Branch outcome comparison signals
    logic                   req_delay1;
    logic                   req_delay2;
    logic                   req_delay3;
    logic                   branchTaken_delay1;

    // Branch outcome and prediction comparison and correction 
    always_ff @(posedge clk or negedge resetN) begin
        if (!resetN) begin
            saturationCounter <= 2'b01;
            req_delay1        <= 1'b0;
            req_delay2        <= 1'b0;
            req_delay3        <= 1'b0;
            branchTaken_delay1 <= 1'b0;
        end else begin
            req_delay3 <= req_delay2;
            req_delay2 <= req_delay1;
            req_delay1 <= branchRequested;
            branchTaken_delay1 <= branchTaken;

            if (req_delay3) begin
                if (branchTaken_delay1 && saturationCounter != 2'b11) begin
                    saturationCounter <= saturationCounter + 1'b1;
                end else if (!branchTaken_delay1 && saturationCounter != 2'b00) begin
                    saturationCounter <= saturationCounter - 1'b1;
                end
            end
        end
    end

endmodule