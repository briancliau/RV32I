`timescale 1ns/1ps

//------------------------------------------------------------------------------
// Author      : Brian Liau (brian.liau@tufts.edu)
// File        : XALU.sv
// Design Unit : XALU
// Description : Execution Stage Execution ALU supporting arithmetic, logical, 
//               shift, comparison, and target address mask operations for RISC-V.
// Dependencies: rvDefs.sv
// Target      : Synthesis
//------------------------------------------------------------------------------
module XALU
(
    input  rvDefs::word_t    inputPrimary,   
    input  rvDefs::word_t    inputSecondary, 
    input  rvDefs::xalu_op_t operation,      
    input  logic             arithmeticFlag, 
    input  logic             JALR_EX,
    output rvDefs::word_t    result 
);

    logic [4 : 0] shamt;
    assign shamt = inputSecondary[4 : 0];

    always_comb begin
        case (operation)
            rvDefs::XALU_OP_SUM:
                // Subtraction only when arithmeticFlag is explicitly active
                result = arithmeticFlag ? (inputPrimary - inputSecondary) : (inputPrimary + inputSecondary);
            rvDefs::XALU_OP_SLL:
                result = inputPrimary << shamt;
            rvDefs::XALU_OP_SLT:
                result = {31'b0, ($signed(inputPrimary) < $signed(inputSecondary))};
            rvDefs::XALU_OP_SLTU:
                result = {31'b0, (inputPrimary < inputSecondary)};
            rvDefs::XALU_OP_XOR:
                result = inputPrimary ^ inputSecondary;
            rvDefs::XALU_OP_SR:
                begin
                    if (arithmeticFlag)
                        result = $signed(inputPrimary) >>> shamt;
                    else
                        result = inputPrimary >> shamt;
                end
            rvDefs::XALU_OP_OR:
                result = inputPrimary | inputSecondary;
            rvDefs::XALU_OP_AND:
                result = inputPrimary & inputSecondary;
        endcase
    end

endmodule
