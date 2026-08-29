//------------------------------------------------------------------------------
// Author      : Brian Liau (brian.liau@tufts.edu)
// File        : BranchDecoder.sv
// Design Unit : BranchDecoder
// Description : Combinational branch/jump instruction decoder. Determines if a
//               instruction is a branch or jump instruction and calculate the
//               immediate for the instruction.
// Dependencies: rvDefs.sv
// Target      : Synthesis
//------------------------------------------------------------------------------
module BranchDecoder 
(
    input  rvDefs::instruction_t    instruction,
    output rvDefs::word_t           branchImmediate,
    output rvDefs::branch_op_t      branchOp,
    output logic                    jump,
    output logic                    JALR
);
    // Determine the opcode of the instruction
    rvDefs::opcode_t opcode;
    assign opcode = rvDefs::opcode_t'(instruction[6 : 0]);
    
    // Determine the funct3 of the instruction
    logic [2 : 0] funct3;
    assign funct3 =   instruction[14 : 12];

    // Determine if the instruction is a branch or jump instruction and set 
    // flags and branch intermediate value
    always_comb begin
        branchOp = rvDefs::branch_op_t'(opcode == rvDefs::OPCODE_BRANCH ? funct3[2 : 1] : rvDefs::BRANCH_OP_NONE);
        jump = ((opcode == rvDefs::OPCODE_JAL) || (opcode == rvDefs::OPCODE_JALR));
        JALR = (opcode == rvDefs::OPCODE_JALR);
        
        case (opcode)
            rvDefs::OPCODE_JAL:
                    branchImmediate = {{11{instruction[31]}}, instruction[31], instruction[19:12], instruction[20], instruction[30:21], 1'b0};
            rvDefs::OPCODE_JALR,
            rvDefs::OPCODE_BRANCH:
                    branchImmediate = {{19{instruction[31]}}, instruction[31], instruction[7], instruction[30:25], instruction[11:8], 1'b0};
            default:
                    branchImmediate = rvDefs::word_t'(0);
        endcase
    end

endmodule
