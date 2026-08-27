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
    always_ff @(posedge clk or negedge resetN) begin
    if (!resetN) begin
        instruction_ID          <= 32'b0;
        instructionAddress_ID   <= 32'b0;
        branchPrediction_ID     <= 1'b0;
    end
    else begin
        if (flush) begin
            instruction_ID          <= 32'h0000_0013; // Inject NOP
            instructionAddress_ID   <= instructionAddress_IF;
            branchPrediction_ID     <= 1'b0;
        end
        else if (!pipelineStall && IFID_write) begin
            instruction_ID          <= instruction_IF;
            instructionAddress_ID   <= instructionAddress_IF;
            branchPrediction_ID     <= branchPrediction_IF;
        end
    end 
end

endmodule
