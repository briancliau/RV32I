`timescale 1ns/1ps

module BranchPredictor (
    input  logic                clk,
    input  logic                resetN,
    input  logic                branchTaken,
    input  logic                branchRequested,
    output logic                branchPrediction
);

    logic [1:0]             saturationCounter;
    logic                   req_delay1, req_delay2;
    logic                   branchPrediction_value;
    logic                   branchPrediction_delay1, branchPrediction_delay2;

    always_comb begin
        branchPrediction = (saturationCounter >= 2'b10);
        branchPrediction_value = branchPrediction;
    end

    always_ff @(posedge clk or negedge resetN) begin
        if (!resetN) begin
            saturationCounter <= 2'b01;
            req_delay1        <= 1'b0;
            req_delay2        <= 1'b0;
            branchPrediction_delay1 <= 1'b0;
            branchPrediction_delay2 <= 1'b0;
        end else begin
            req_delay2 <= req_delay1;
            req_delay1 <= branchRequested;

            branchPrediction_delay2 <= branchPrediction_delay1;
            branchPrediction_delay1 <= branchPrediction_value;

            if (req_delay2) begin
                if (branchTaken && saturationCounter != 2'b11) begin
                    saturationCounter <= saturationCounter + 1'b1;
                end else if (!branchTaken && saturationCounter != 2'b00) begin
                    saturationCounter <= saturationCounter - 1'b1;
                end
            end
        end
    end

endmodule