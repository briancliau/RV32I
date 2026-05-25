module BranchAddresser (
    input [31:0] PCAddress,
    input rvDefs::word_t offset,
    input rvDefs::word_t branchTargetJALR,
    input rvDefs::opcode_t opcode,
    output [31:0] BranchAddress
);
    always_comb begin
        if (opcode == rvDefs::OPCODE_JAL) begin
            BranchAddress = PCAddress + offset;
        end else if (opcode == rvDefs::OPCODE_BRANCH) begin
            BranchAddress = PCAddress + offset;
        // end else if (opcode == rvDefs::OPCODE_JALR) begin
        //     BranchAddress = branchTargetJALR;
        end else begin
            BranchAddress = 32'b0;
        end
    end
endmodule