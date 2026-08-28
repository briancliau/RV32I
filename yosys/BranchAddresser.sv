`timescale 1ns/1ps
import rvDefs::*;

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
    // Calculate PC-relative target address for JAL and Branch instructions
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