`timescale 1ns/1ps

//------------------------------------------------------------------------------
// Author      : Brian Liau (brian.liau@tufts.edu)
// File        : IFID_register.sv
// Design Unit : IFID_register
// Description : Instruction Fetch (IF) to Instruction Decode (ID) pipeline  
//               stage register. Latches IF stage evaluation results and control 
//               signal, holding state during bus/pipeline stalls and flushing
//               instructions during pipeline flushes.
// Dependencies: rvDefs.sv
// Target      : Synthesis
//------------------------------------------------------------------------------
module IFID_register (
    input  logic                    clk,
    input  logic                    resetN,
    input  logic                    pipelineStall,
    input  logic                    IFID_write,
    input  logic                    flush,
    input  logic [31:0]             instructionAddress_IF,
    input  logic [31:0]             instruction_IF,
    output logic [31:0]             instruction_ID,
    output logic [31:0]             instructionAddress_ID,
    input  logic                    branchPrediction_IF,
    output logic                    branchPrediction_ID
);
    // Latch IF stage signals into ID stage registers on active clock edge
    always_ff @(posedge clk or negedge resetN) begin
    if (!resetN) begin
        instruction_ID          <= 32'b0;
        instructionAddress_ID   <= 32'b0;
        branchPrediction_ID     <= 1'b0;
    end
    else begin
        // Flush pipelined signals during pipeline flush
        if (flush) begin
            instruction_ID          <= 32'h0000_0013; // Inject NOP
            instructionAddress_ID   <= instructionAddress_IF;
            branchPrediction_ID     <= 1'b0;
        end
        // Advance pipelined signals when not stalled, freeze state during pipeline stalls
        else if (!pipelineStall && IFID_write) begin
            instruction_ID          <= instruction_IF;
            instructionAddress_ID   <= instructionAddress_IF;
            branchPrediction_ID     <= branchPrediction_IF;
        end
    end 
end

endmodule
