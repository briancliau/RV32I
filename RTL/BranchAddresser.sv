import rvDefs::*;

module BranchAddresser (
    input  logic [31:0]     PCAddress,
    input  rvDefs::word_t   offset,
    input  rvDefs::opcode_t opcode,
    output logic [31:0]     BranchAddress
);

    always_comb begin
        case (opcode)
            rvDefs::OPCODE_JAL,
            rvDefs::OPCODE_BRANCH: begin
                BranchAddress = PCAddress + offset;
            end
            
            default: begin
                BranchAddress = 32'b0;
            end
        endcase
    end

endmodule