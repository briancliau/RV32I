`timescale 1ns/1ps

//------------------------------------------------------------------------------
// Author      : Brian Liau (brian.liau@tufts.edu)
// File        : InstructionDecoder.sv
// Design Unit : InstructionDecoder
// Description : Combinationally determines the control signals for the 
//               instructions.
// Dependencies: rvDefs.sv
// Target      : Synthesis
//------------------------------------------------------------------------------
module InstructionDecoder
(
    input  rvDefs::instruction_t    instruction,            
    output rvDefs::xreg_addr_t      rs1,                    
    output rvDefs::xreg_addr_t      rs2,                    
    output rvDefs::xreg_addr_t      rd,                     
    output logic                    xaluArithmeticFlag,     
    output rvDefs::xalu_op_t        xaluOp,                 
    output logic                    zeroXaluPrimary,        
    output logic                    pcXaluPrimary,          
    output logic                    immediateXaluSecondary, 
    output rvDefs::memory_op_size_t memoryOpSize,           
    output logic                    unsignedLoad,           
    output logic                    storeLoad,              
    output rvDefs::branch_op_t      branchOp,               
    output logic                    branchNegate,           
    output rvDefs::write_src_t      writeSource             
);

    rvDefs::opcode_t opcode;
    logic [2 : 0] funct3;
    logic funct7_5;

    assign opcode =   rvDefs::opcode_t'(instruction[6 : 0]);
    assign funct3 =   instruction[14 : 12];
    assign funct7_5 = instruction[30];

    // Source and Destination Register Field Extraction
    assign rs1 =      rvDefs::xreg_addr_t'(instruction[19 : 15]);
    assign rs2 =      rvDefs::xreg_addr_t'(instruction[24 : 20]);
    assign rd =       rvDefs::xreg_addr_t'(instruction[11 : 7]);

    // Primary ALU Multiplexer Select Controls
    assign zeroXaluPrimary = (opcode == rvDefs::OPCODE_LUI); 
    assign pcXaluPrimary = (
        (opcode == rvDefs::OPCODE_AUIPC) ||
        (opcode == rvDefs::OPCODE_JAL) ||
        (opcode == rvDefs::OPCODE_BRANCH)
    );

    // Secondary ALU Multiplexer Select Controls
    assign immediateXaluSecondary = (
        (opcode == rvDefs::OPCODE_LUI) ||
        (opcode == rvDefs::OPCODE_AUIPC) ||
        (opcode == rvDefs::OPCODE_JAL) ||
        (opcode == rvDefs::OPCODE_JALR) ||
        (opcode == rvDefs::OPCODE_BRANCH) ||
        (opcode == rvDefs::OPCODE_LOAD) ||
        (opcode == rvDefs::OPCODE_STORE) ||
        (opcode == rvDefs::OPCODE_OP_IMM)
    );

    // ALU Arithmetic / Shift Mode Flag
    // SUB / SRA: OP with funct7[5]=1
    // SRAI: OP_IMM with funct3=101 (SRLI/SRAI) and funct7[5]=1
    assign xaluArithmeticFlag = (opcode == rvDefs::OPCODE_OP && funct7_5) || 
                            (opcode == rvDefs::OPCODE_OP_IMM && funct3 == 3'b101 && funct7_5); 
    
    // Memory Control Signals
    assign unsignedLoad = funct3[2];
    assign storeLoad = (opcode == rvDefs::OPCODE_STORE);
    assign memoryOpSize = (
        ((opcode == rvDefs::OPCODE_LOAD) || (opcode == rvDefs::OPCODE_STORE)) ?
            (rvDefs::memory_op_size_t'(funct3[1 : 0])) :
            (rvDefs::MEMORY_OP_SIZE_NONE)
    );
    
    // Branch Control Signals
    assign branchOp = rvDefs::branch_op_t'(opcode == rvDefs::OPCODE_BRANCH ? funct3[2 : 1] : rvDefs::BRANCH_OP_NONE); 
    assign branchNegate = funct3[0]; 


    // Register Write-Back Source Decoding
    always_comb begin
        case (opcode)
            rvDefs::OPCODE_LUI,
            rvDefs::OPCODE_AUIPC,
            rvDefs::OPCODE_OP_IMM,
            rvDefs::OPCODE_OP:
                writeSource = rvDefs::WRITE_SRC_ALU;
            rvDefs::OPCODE_JAL,
            rvDefs::OPCODE_JALR:
                writeSource = rvDefs::WRITE_SRC_PC;
            rvDefs::OPCODE_LOAD:
                writeSource = rvDefs::WRITE_SRC_MEM;
            default:
                writeSource = rvDefs::WRITE_SRC_NONE;
        endcase
    end

    // ALU Operation Decoding
    always_comb begin
        case (opcode)
            rvDefs::OPCODE_OP_IMM,
            rvDefs::OPCODE_OP:
                xaluOp = rvDefs::xalu_op_t'(funct3);
            default:
                xaluOp = rvDefs::XALU_OP_SUM;
        endcase
    end

endmodule
