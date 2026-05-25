module IFID_register (
    input logic                     clk,
    input logic                     resetN,
    input logic                     IFID_write,
    input logic                     flush,
    input rvDefs::mem_addr_t        instructionAddress_IF,
    input rvDefs::instruction_t     instructions_IF,
    output rvDefs::instruction_t    instructions_ID,
    output rvDefs::mem_addr_t       instructionAddress_ID
);

    always_ff @(posedge clk or negedge resetN) begin
        if (!resetN) begin
            instructions_ID <= 32'b0;
            instructionAddress_ID <= 32'b0;
        end
        else if (flush) begin
            instructions_ID <= 32'h0000_0013;                   // NOP
            instructionAddress_ID <= instructionAddress_ID;
        end
        else if (IFID_write) begin
            instructions_ID <= instructions_IF;
            instructionAddress_ID <= instructionAddress_IF;
        end
        else if (!IFID_write) begin
            instructions_ID <= instructions_ID;           // NOP 32'h0000_0013
            instructionAddress_ID <= instructionAddress_ID;
        end
        
    end

endmodule