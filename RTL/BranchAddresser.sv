//------------------------------------------------------------------------------
// Author      : Brian Liau (brian.liau@tufts.edu)
// File        : BranchAddresser.sv
// Design Unit : BranchAddresser
// Description : Combinational branch/jump target address adder. Calculates
//               PC-relative target addresses for JAL and BRANCH instructions.
// Dependencies: rvDefs.sv
// Target      : Synthesis
//------------------------------------------------------------------------------
module BranchAddresser (
    input  logic [31:0]     PCAddress,
    input  rvDefs::word_t   offset,
    input  rvDefs::opcode_t opcode,
    output logic [31:0]     BranchAddress
);
    always_comb begin
        if (opcode == rvDefs::OPCODE_JAL) begin
            BranchAddress = PCAddress + offset;
        end else if (opcode == rvDefs::OPCODE_BRANCH) begin
            BranchAddress = PCAddress + offset;
        end else begin
            BranchAddress = 32'b0;
        end
    end

endmodule