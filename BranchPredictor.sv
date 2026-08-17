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
    logic                   branchTaken_delay1;

    always_comb begin
        if (branchRequested) begin
                branchPrediction = (saturationCounter >= 2'b10);
            end else begin
                branchPrediction = 1'b0;
            end
    end

    always_ff @(posedge clk or negedge resetN) begin
        if (!resetN) begin
            saturationCounter <= 2'b01;
            req_delay1        <= 1'b0;
            req_delay2        <= 1'b0;
            branchTaken_delay1 <= 1'b0;
        end else begin
            req_delay2 <= req_delay1;
            req_delay1 <= branchRequested;
            branchTaken_delay1 <= branchTaken;

            if (req_delay2) begin
                if (branchTaken_delay1 && saturationCounter != 2'b11) begin
                    saturationCounter <= saturationCounter + 1'b1;
                end else if (!branchTaken_delay1 && saturationCounter != 2'b00) begin
                    saturationCounter <= saturationCounter - 1'b1;
                end
            end
        end
    end

endmodule