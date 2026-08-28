`timescale 1ns/1ps

//------------------------------------------------------------------------------
// Author      : Brian Liau (brian.liau@tufts.edu)
// File        : Core.sv
// Design Unit : Core
// Description : RISC-V RV32I Core connecting the ALU, register file, pipelining
//               , forwarding, hazard detection, and memory transfers.
// Dependencies: rvDefs.sv
// Target      : Synthesis
//------------------------------------------------------------------------------
module Core
(
    // Core Interface
    input  logic                 CLK,
    input  logic                 RSTN,
    input  logic                 stall,

    // Instruction Manager Interface (To AHBInstructionManager)
    output logic                 nextInstructionFlag,
    output rvDefs::mem_addr_t    nextInstructionAddress,
    input  rvDefs::word_t        instruction,
    input  rvDefs::mem_addr_t    instructionAddressAHB,
    input  logic                 HREADY_ibus,

    // Data Manager Interface (To AHBDataManager)
    output logic                 memWrite,
    output logic                 memRead,
    output rvDefs::mem_addr_t    addressLSU,
    output rvDefs::word_t        writeDataLSU,
    output logic [2:0]           memSize,
    input  rvDefs::word_t        memReadData,
    input  logic                 HREADY_dbus
);
    // IF stage signals
    rvDefs::mem_addr_t    instructionAddress;
    rvDefs::word_t        memWriteData;

    // hazard and forwarding signals
    logic                    PC_update;
    logic                    IFID_write;
    logic                    IDEX_delay;
    rvDefs::forward_mux_t    ForwardA;
    rvDefs::forward_mux_t    ForwardB;
    rvDefs::forward_mux_t    ForwardID_A;

    // branch signals
    logic               branchPass;
    logic               branchTaken_EX;
    logic               branchPrediction;
    logic               jump_EX;
    logic               pipelineFlush;
    logic               pipelineFlushIF;
    rvDefs::word_t      branchAddress;
    logic               loadPCValue;
    logic               branchCorrectionJALR;
    logic               JALRCorrection;
    logic               addressCorrectionFlag;
    rvDefs::word_t      JALRAddress;
    rvDefs::word_t      addressCorrectionLoad;
    rvDefs::word_t      branchImmediate;
    rvDefs::branch_op_t branchPredictionOp;

    // IF/ID pipeline register outputs  (ID stage inputs)
    rvDefs::instruction_t    instruction_ID;
    rvDefs::mem_addr_t       instructionAddress_ID;

    // ID stage signals
    rvDefs::xreg_addr_t      rs1;
    rvDefs::xreg_addr_t      rs2;
    rvDefs::xreg_addr_t      rd;
    logic                    xaluArithmeticFlag;
    rvDefs::xalu_op_t        xaluOp;
    logic                    zeroXaluPrimary;
    logic                    pcXaluPrimary;
    logic                    immediateXaluSecondary;
    rvDefs::memory_op_size_t memoryOpSize;
    logic                    unsignedLoad;
    logic                    storeLoad;
    rvDefs::branch_op_t      branchOp;
    logic                    branchNegate;
    logic                    jump;
    rvDefs::write_src_t      writeSource;
    rvDefs::word_t           immediate;
    rvDefs::xreg_t           read1Data;
    rvDefs::xreg_t           read2Data;
    logic                    branchPrediction_ID;

    // ID/EX pipeline register outputs  (EX stage inputs)
    rvDefs::write_src_t      writeSource_EX;
    logic                    writeEnable_EX;
    rvDefs::xreg_t           read1Data_EX;
    rvDefs::xreg_t           read2Data_EX;
    rvDefs::xreg_addr_t      rs1_EX;
    rvDefs::xreg_addr_t      rs2_EX;
    rvDefs::xreg_addr_t      rd_EX;
    rvDefs::mem_addr_t       instructionAddress_EX;
    rvDefs::word_t           immediate_EX;
    rvDefs::xalu_op_t        xaluOp_EX;
    logic                    xaluArithmeticFlag_EX;
    rvDefs::memory_op_size_t memoryOpSize_EX;
    logic                    unsignedLoad_EX;
    logic                    storeLoad_EX;
    logic                    pcXaluPrimary_EX;
    logic                    immediateXaluSecondary_EX;
    logic                    zeroXaluPrimary_EX;
    rvDefs::branch_op_t      branchOp_EX;
    logic                    branchNegate_EX;
    logic                    jump_EX_reg;
    rvDefs::word_t           instruction_EX;
    logic                    branchPrediction_EX;
    logic                    JALR_flag;
    logic                    JALR_EX;
    rvDefs::word_t           address_EX;


    // EX stage signals
    rvDefs::word_t           fwd_rs1;           // forwarded rs1 value
    rvDefs::word_t           fwd_rs2;           // forwarded rs2 value
    rvDefs::word_t           branchTargetJALR;  // calculated branch target address
    rvDefs::word_t           xalu_primary;      // muxed XALU primary input
    rvDefs::word_t           xalu_secondary;    // muxed XALU secondary input
    rvDefs::word_t           aluResult;         // XALU result
    rvDefs::opcode_t         opcodeBranchResolution;
    logic                    branchCorrection;
    rvDefs::word_t           branchCorrectionAddress;
    logic                    branchMispredicted_EX;

    // EX/MEM pipeline register outputs  (MEM stage inputs)
    rvDefs::write_src_t      writeSource_MEM;
    logic                    writeEnable_MEM;
    rvDefs::xreg_addr_t      rd_MEM;
    rvDefs::memory_op_size_t memoryOpSize_MEM;
    logic                    unsignedLoad_MEM;
    logic                    storeLoad_MEM;
    rvDefs::mem_addr_t       address_MEM;
    rvDefs::mem_addr_t       instructionAddress_MEM;
    rvDefs::word_t           memWriteData_MEM;  // rs2 forwarded value latched for stores
    logic                    JALR_MEM;
    logic                    JALR_pipelineFlush;

    // MEM stage signals
    rvDefs::word_t           memToRegData;

    // MEM/WB pipeline register outputs  (WB stage inputs)
    logic                    writeEnable_WB;
    rvDefs::mem_addr_t       address_WB;
    rvDefs::xreg_addr_t      rd_WB;
    rvDefs::word_t           memToRegData_WB;
    rvDefs::mem_addr_t       instructionAddress_WB;
    rvDefs::write_src_t      writeSource_WB;
    logic                    JALR_WB;

    // WB stage signals
    rvDefs::word_t           registerWriteData;

    // AHB Lite stall signals
    logic  pipelineStall;
    assign pipelineStall = !(HREADY_dbus && HREADY_ibus);

    /******************************
     * modules
     ******************************/

    // Program counter — updated from EX stage branch/jump result
    ProgramCounter programCounter(
        .clk                    (CLK),
        .resetN                 (RSTN),
        .enable                 (PC_update & IFID_write & !pipelineStall),
        .branchPrediction       (loadPCValue),
        .branchCorrection       (addressCorrectionFlag),
        .addrLoad               (branchAddress),
        .branchCorrectionLoad   (addressCorrectionLoad),
        .addrOut                (instructionAddress)
    );

    // Future instructions addresses and flags
    assign nextInstructionAddress = loadPCValue ? branchAddress : instructionAddress;
    assign addressCorrectionLoad = branchCorrection ? branchCorrectionAddress : JALRAddress;
    assign nextInstructionFlag = PC_update & IFID_write;
    assign loadPCValue = (jump && !JALR_flag) || branchPrediction;
    
    // Pipeline stall 
    assign pipelineFlush = addressCorrectionFlag || JALR_pipelineFlush;

    // Branch decoder instantiation
    BranchDecoder BranchDecoder (
        .instruction(instruction),
        .branchImmediate(branchImmediate),
        .branchOp(branchPredictionOp),
        .jump(jump),       
        .JALR(JALR_flag)
    );

    // IF/ID pipeline register instantiation
    IFID_register IFID_stage(
        .clk                        (CLK),
        .resetN                     (RSTN),
        .pipelineStall              (pipelineStall),
        .IFID_write                 (IFID_write),
        .flush                      (pipelineFlush),
        .instructionAddress_IF      (instructionAddressAHB),
        .instructionAddress_ID      (instructionAddress_ID),
        .instruction_IF             (instruction),
        .instruction_ID             (instruction_ID),
        .branchPrediction_IF        (branchPrediction),
        .branchPrediction_ID        (branchPrediction_ID)
    );

    // Immediate generator instantiation
    ImmediateGenerator immediateGenerator(
        .instruction (instruction_ID),
        .immediate   (immediate)
    );

    // Instruction decoder instantiation
    InstructionDecoder instructionDecoder(
        .instruction            (instruction_ID),
        .rs1                    (rs1),
        .rs2                    (rs2),
        .rd                     (rd),
        .xaluArithmeticFlag     (xaluArithmeticFlag),
        .xaluOp                 (xaluOp),
        .zeroXaluPrimary        (zeroXaluPrimary),
        .pcXaluPrimary          (pcXaluPrimary),
        .immediateXaluSecondary (immediateXaluSecondary),
        .memoryOpSize           (memoryOpSize),
        .unsignedLoad           (unsignedLoad),
        .storeLoad              (storeLoad),
        .branchOp               (branchOp),
        .branchNegate           (branchNegate),
        .writeSource            (writeSource)
    );

    // Register file instantiation
    XRegisterFile xRegisterFile(
        .clk        (CLK),
        .writeEnable(writeEnable_WB),
        .read1Reg   (rs1),
        .read2Reg   (rs2),
        .writeReg   (rd_WB),
        .writeData  (registerWriteData),
        .read1Data  (read1Data),
        .read2Data  (read2Data)
    );

    // Branch predictor unit instantiation
    BranchPredictor branchPredictor (
        .clk                (CLK),
        .resetN             (RSTN),
        .branchTaken        (branchTaken_EX),
        .branchRequested    (branchPredictionOp != rvDefs::BRANCH_OP_NONE),
        .branchPrediction   (branchPrediction)
    );

    // Branch addresser instantiation
    BranchAddresser branchAddresser (
        .PCAddress          (instructionAddressAHB),
        .offset             (branchImmediate),
        .opcode             (rvDefs::opcode_t'(instruction[6:0])),
        .BranchAddress      (branchAddress)
    );

    // Hazard detection unit instantiation
    HazardDetection hazardDetection(
        .clk            (CLK),
        .resetN         (RSTN),
        .IDEX_r1        (rs1),
        .IDEX_r2        (rs2),
        .EXMEM_rd       (rd_EX),
        .IDEX_memread   (storeLoad_EX == 1'b0 && memoryOpSize_EX != rvDefs::MEMORY_OP_SIZE_NONE),
        .instruction_IF (instruction),
        .PC_update      (PC_update),
        .IFID_write     (IFID_write),
        .IDEX_delay     (IDEX_delay)
    );

    // Forwarding unit instantiation
    ForwardingUnit forwardingUnit(
        .resetN         (RSTN),
        .rs1            (rs1_EX),
        .rs2            (rs2_EX),
        .EXMEM_rd       (rd_MEM),
        .EXMEM_RegWrite (writeEnable_MEM),
        .MEMWB_rd       (rd_WB),
        .MEMWB_RegWrite (writeEnable_WB),
        .ID_rs1         (rs1),
        .ForwardA       (ForwardA),
        .ForwardB       (ForwardB),
        .ForwardID_A    (ForwardID_A)
    );

    // ID/EX pipeline register instantiation
    IDEX_register IDEX_stage(
        .clk                        (CLK),
        .resetN                     (RSTN),
        .pipelineStall              (pipelineStall),
        .flush                      (pipelineFlush),
        .IDEX_delay                 (IDEX_delay),
        .read1Data_ID               (read1Data),
        .read2Data_ID               (read2Data),
        .rs1_ID                     (rs1),
        .rs2_ID                     (rs2),
        .rd_ID                      (rd),
        .instructionAddress_ID      (instructionAddress_ID),
        .immediate_ID               (immediate),
        .xaluOp_ID                  (xaluOp),
        .xaluArithmeticFlag_ID      (xaluArithmeticFlag),
        .memoryOpSize_ID            (memoryOpSize),
        .unsignedLoad_ID            (unsignedLoad),
        .storeLoad_ID               (storeLoad),
        .writeEnable_ID             (writeSource != rvDefs::WRITE_SRC_NONE),
        .writeSource_ID             (writeSource),
        .pcXaluPrimary_ID           (pcXaluPrimary),
        .zeroXaluPrimary_ID         (zeroXaluPrimary),
        .immediateXaluSecondary_ID  (immediateXaluSecondary),
        .branchOp_ID                (branchOp),
        .branchNegate_ID            (branchNegate),
        .instruction_ID             (instruction_ID),
        .jump_ID                    (jump),
        .JALR_ID                    (JALR_flag),
        .branchPrediction_ID        (branchPrediction_ID),
        .branchPrediction_EX        (branchPrediction_EX),
        .immediateXaluSecondary_EX  (immediateXaluSecondary_EX),
        .writeSource_EX             (writeSource_EX),
        .writeEnable_EX             (writeEnable_EX),
        .read1Data_EX               (read1Data_EX),
        .read2Data_EX               (read2Data_EX),
        .rs1_EX                     (rs1_EX),
        .rs2_EX                     (rs2_EX),
        .rd_EX                      (rd_EX),
        .instructionAddress_EX      (instructionAddress_EX),
        .immediate_EX               (immediate_EX),
        .xaluOp_EX                  (xaluOp_EX),
        .xaluArithmeticFlag_EX      (xaluArithmeticFlag_EX),
        .memoryOpSize_EX            (memoryOpSize_EX),
        .unsignedLoad_EX            (unsignedLoad_EX),
        .storeLoad_EX               (storeLoad_EX),
        .pcXaluPrimary_EX           (pcXaluPrimary_EX),
        .zeroXaluPrimary_EX         (zeroXaluPrimary_EX),
        .branchOp_EX                (branchOp_EX),
        .branchNegate_EX            (branchNegate_EX),
        .jump_EX                    (jump_EX_reg),
        .JALR_EX                    (JALR_EX),
        .instruction_EX             (instruction_EX)
    );
    

    /******************************
     * EX stage forwarding muxes
     ******************************/
    always_comb begin
        // ForwardA mux — selects correct rs1 value
        case (ForwardA)
            rvDefs::FORWARD_MEM:  fwd_rs1 = address_MEM;       // from EX/MEM ALU result
            rvDefs::FORWARD_ALU:  fwd_rs1 = registerWriteData; // from MEM/WB writeback
            default:              fwd_rs1 = read1Data_EX;       // from register file
        endcase

        // ForwardB mux — selects correct rs2 value
        case (ForwardB)
            rvDefs::FORWARD_MEM:  fwd_rs2 = address_MEM;
            rvDefs::FORWARD_ALU:  fwd_rs2 = registerWriteData;
            default:              fwd_rs2 = read2Data_EX;
        endcase

        // JALR / Branch evaluation - ID Stage Operand A
        case (ForwardID_A)
            rvDefs::FORWARD_MEM:  branchTargetJALR = address_MEM;
            rvDefs::FORWARD_ALU:  branchTargetJALR = registerWriteData;
            default:              branchTargetJALR = read1Data;
        endcase

        // XALU primary mux
        if (pcXaluPrimary_EX)
            xalu_primary = instructionAddress_EX;
        else if (zeroXaluPrimary_EX)
            xalu_primary = 32'b0;
        else
            xalu_primary = fwd_rs1;

        // XALU secondary mux
        xalu_secondary = immediateXaluSecondary_EX ? immediate_EX : fwd_rs2;
    end

    // XALU instantiation
    XALU xAlu(
        .inputPrimary   (xalu_primary),
        .inputSecondary (xalu_secondary),
        .operation      (xaluOp_EX),
        .arithmeticFlag (xaluArithmeticFlag_EX),
        .JALR_EX        (JALR_EX),
        .result         (aluResult)
    );

    /******************************
     * EX stage branch resolution
     ******************************/
    always_comb begin
        case (branchOp_EX)
            rvDefs::BRANCH_OP_EQ:
                branchPass = (fwd_rs1 == fwd_rs2) ^ branchNegate_EX;
            rvDefs::BRANCH_OP_LT:
                branchPass = ($signed(fwd_rs1) < $signed(fwd_rs2)) ^ branchNegate_EX;
            rvDefs::BRANCH_OP_LTU:
                branchPass = (fwd_rs1 < fwd_rs2) ^ branchNegate_EX;
            default:
                branchPass = 1'b0;
        endcase

        branchTaken_EX = branchPass && (branchOp_EX != rvDefs::BRANCH_OP_NONE);
        jump_EX        = jump_EX_reg;
        opcodeBranchResolution = rvDefs::opcode_t'(instruction_EX[6 : 0]);
    end

    // Branch outcome determined
    always_comb begin
        if (branchOp_EX != rvDefs::BRANCH_OP_NONE) begin
            branchMispredicted_EX = (branchTaken_EX != branchPrediction_EX);
        end else if (JALR_EX) begin
            branchMispredicted_EX = 1'b1;
        end else begin
            branchMispredicted_EX = 1'b0;
        end
    end

    // Branch and JALR PC value correction 
    always_comb begin
        branchCorrectionAddress = 32'b0;
        branchCorrectionJALR    = 1'b0;
        branchCorrection        = 1'b0;

        if (branchMispredicted_EX) begin
            branchCorrection = 1'b1;
            
            if (branchTaken_EX || JALR_EX) begin
                if (JALR_EX) begin
                    branchCorrectionAddress = aluResult;
                    branchCorrectionJALR    = 1'b1;
                end else begin
                    branchCorrectionAddress = instructionAddress_EX + immediate_EX;
                end
            end else begin
                branchCorrectionAddress = instructionAddress_EX + 32'd4;
            end
        end

        if (branchCorrection && !JALR_EX) begin
            addressCorrectionFlag = 1'b1;
        end else if (JALRCorrection) begin
            addressCorrectionFlag = 1'b1;
        end else begin
            addressCorrectionFlag = 1'b0;
        end
    end

    // JALR addresser instantiation
    JALRAddresser JALRaddresser (
        .clk                    (CLK),
        .resetN                 (RSTN),
        .branchCorrectionJALR   (branchCorrectionJALR),
        .aluResult              (aluResult),
        .JALRCorrection         (JALRCorrection),
        .JALR_pipelineFlush     (JALR_pipelineFlush),
        .JALRAddress            (JALRAddress)
    );

    // EX/MEM pipeline register instantiation
    EXMEM_register EXMEM_stage(
        .clk                    (CLK),
        .resetN                 (RSTN),
        .pipelineStall          (pipelineStall),
        .memoryOpSize_EX        (memoryOpSize_EX),
        .unsignedLoad_EX        (unsignedLoad_EX),
        .storeLoad_EX           (storeLoad_EX),
        .address_EX             (aluResult),
        .rd_EX                  (rd_EX),
        .writeEnable_EX         (writeEnable_EX),
        .writeSource_EX         (writeSource_EX),
        .instructionAddress_EX  (instructionAddress_EX),
        .memWriteData_EX        (fwd_rs2),           // use forwarded rs2 for stores
        .JALR_EX                (JALR_EX),
        .JALR_MEM               (JALR_MEM),
        .memWriteData_MEM       (memWriteData),
        .instructionAddress_MEM (instructionAddress_MEM),
        .writeSource_MEM        (writeSource_MEM),
        .writeEnable_MEM        (writeEnable_MEM),
        .rd_MEM                 (rd_MEM),
        .memoryOpSize_MEM       (memoryOpSize_MEM),
        .unsignedLoad_MEM       (unsignedLoad_MEM),
        .storeLoad_MEM          (storeLoad_MEM),
        .address_MEM            (address_MEM)
    );

    // LSU instantiation
    LSU lsu(
        .clk            (CLK),
        .resetN         (RSTN),
        .memoryOpSize   (memoryOpSize_MEM),
        .unsignedLoad   (unsignedLoad_MEM),
        .storeLoad      (storeLoad_MEM),
        .address        (address_MEM),
        .readData       (memReadData),
        .memWriteData   (memWriteData),
        .HREADY_dbus    (HREADY_dbus),
        .memWrite       (memWrite),
        .memRead        (memRead),
        .memSize        (memSize),
        .memToRegData   (memToRegData),
        .writeDataLSU   (writeDataLSU),
        .addressLSU     (addressLSU)
    );

    // MEM/WB pipeline register instantiation
    MEMWB_register MEMWB_stage(
        .clk                    (CLK),
        .resetN                 (RSTN),
        .pipelineStall          (pipelineStall),
        .rd_MEM                 (rd_MEM),
        .address_MEM            (address_MEM),
        .writeEnable_MEM        (writeEnable_MEM),
        .memToRegData_MEM       (memToRegData),
        .writeSource_MEM        (writeSource_MEM),
        .instructionAddress_MEM (instructionAddress_MEM),
        .JALR_MEM               (JALR_MEM),
        .JALR_WB                (JALR_WB),
        .instructionAddress_WB  (instructionAddress_WB),
        .writeSource_WB         (writeSource_WB),
        .writeEnable_WB         (writeEnable_WB),
        .address_WB             (address_WB),
        .rd_WB                  (rd_WB),
        .memToRegData_WB        (memToRegData_WB)
    );

    /******************************
     * WB stage — register write data mux
     ******************************/
    always_comb begin
        case (writeSource_WB)
            rvDefs::WRITE_SRC_ALU:
                registerWriteData = address_WB;
            rvDefs::WRITE_SRC_MEM:
                registerWriteData = memToRegData;
            rvDefs::WRITE_SRC_PC:
                registerWriteData = instructionAddress_WB + rvDefs::word_t'(3'd4);
            default:
                registerWriteData = 32'b0;
        endcase

        // Maintain stricly zero value in register x0 
        if (rd_WB == 5'b000) begin
            registerWriteData = 32'b0;
        end
    end

endmodule
