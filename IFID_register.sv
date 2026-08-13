module IFID_register (
    input logic                     clk,
    input logic                     resetN,
    input logic                     IFID_write,
    input logic                     flush,
    input logic [31:0]              instructionAddress_IF,
    input logic [31:0]              instruction_IF,
    output logic [31:0]             instruction_ID,
    output logic [31:0]             instructionAddress_ID
);
    logic [31:0] instruction_ID_temp;
    logic [31:0] instructionAddress_ID_temp;

    always_comb begin
        if (flush) begin
            instruction_ID_temp        = 32'h0000_0013;   // NOP
            instructionAddress_ID_temp = instructionAddress_IF;
        end
        else if (IFID_write) begin
            instruction_ID_temp        = instruction_IF;
            instructionAddress_ID_temp = instructionAddress_IF;
        end
        else begin  // stall — hold current register values
            instruction_ID_temp        = instruction_ID;
            instructionAddress_ID_temp = instructionAddress_ID;
        end
    end

    always_ff @(posedge clk or negedge resetN) begin
        if (!resetN) begin
            instruction_ID <= 32'b0;
            instructionAddress_ID <= 32'b0;
        end
        else begin
            instruction_ID <= instruction_ID_temp;
            instructionAddress_ID <= instructionAddress_ID_temp;
        end 
    end

endmodule