module IDEX_register (
    input logic                     clk,
    input logic                     resetN,
    input logic                     flush,
    input logic                     IDEX_delay,
    input rvDefs::xreg_t            read1Data_ID,
    input rvDefs::xreg_t            read2Data_ID,
    input rvDefs::xreg_addr_t       rs1_ID,
    input rvDefs::xreg_addr_t       rs2_ID,
    input rvDefs::xreg_addr_t       rd_ID,
    input rvDefs::mem_addr_t        instructionAddress_ID,
    input rvDefs::word_t            immediate_ID,
    input rvDefs::xalu_op_t         xaluOp_ID,
    input logic                     xaluArithmeticFlag_ID,
    input  rvDefs::memory_op_size_t memoryOpSize_ID,
    input  logic                    unsignedLoad_ID,
    input  logic                    storeLoad_ID,
    input logic                     writeEnable_ID,
    input rvDefs::write_src_t       writeSource_ID,
    input logic                     pcXaluPrimary_ID,
    input logic                     immediateXaluSecondary_ID,
    input logic                     zeroXaluPrimary_ID,
    input rvDefs::branch_op_t       branchOp_ID,
    input logic                     branchNegate_ID,
    input rvDefs::instruction_t     instruction_ID,         
    input logic                     jump_ID,
    input logic                     JALR_ID,
    input logic                     branchPrediction_ID,
    output logic                    branchPrediction_EX,
    output logic                    JALR_EX,
    output rvDefs::branch_op_t      branchOp_EX,
    output logic                    branchNegate_EX,
    output logic                    jump_EX,
    output logic                    zeroXaluPrimary_EX,
    output logic                    immediateXaluSecondary_EX,
    output rvDefs::write_src_t      writeSource_EX,
    output logic                    writeEnable_EX,
    output rvDefs::xreg_t           read1Data_EX,
    output rvDefs::xreg_t           read2Data_EX,
    output rvDefs::xreg_addr_t      rs1_EX,
    output rvDefs::xreg_addr_t      rs2_EX,
    output rvDefs::xreg_addr_t      rd_EX,
    output rvDefs::mem_addr_t       instructionAddress_EX,
    output rvDefs::word_t           immediate_EX,
    output rvDefs::xalu_op_t        xaluOp_EX,
    output logic                    xaluArithmeticFlag_EX,
    output rvDefs::memory_op_size_t memoryOpSize_EX,
    output logic                    unsignedLoad_EX,
    output logic                    storeLoad_EX,
    output logic                    pcXaluPrimary_EX,
    output rvDefs::instruction_t    instruction_EX
);
    rvDefs::xreg_addr_t rd_EX_temp;
    logic writeEnable_EX_temp;
    rvDefs::write_src_t writeSource_EX_temp;
    rvDefs::memory_op_size_t memoryOpSize_EX_temp;
    logic storeLoad_EX_temp;
    logic unsignedLoad_EX_temp;
    rvDefs::xalu_op_t xaluOp_EX_temp;
    logic xaluArithmeticFlag_EX_temp;
    logic immediateXaluSecondary_EX_temp;
    logic pcXaluPrimary_EX_temp;
    rvDefs::xreg_t read1Data_EX_temp;
    rvDefs::xreg_t read2Data_EX_temp;
    rvDefs::xreg_addr_t rs1_EX_temp;
    rvDefs::xreg_addr_t rs2_EX_temp;
    rvDefs::word_t immediate_EX_temp;
    rvDefs::mem_addr_t instructionAddress_EX_temp;
    logic zeroXaluPrimary_EX_temp;
    rvDefs::branch_op_t branchOp_EX_temp;
    rvDefs::instruction_t instruction_EX_temp ;
    logic branchNegate_EX_temp;
    logic branchPrediction_EX_temp;
    logic jump_EX_temp;
    logic JALR_EX_temp;

    always_comb begin
        if (flush || IDEX_delay) begin
            rd_EX_temp           = 5'b0;
            writeEnable_EX_temp  = 1'b0;
            writeSource_EX_temp  = rvDefs::WRITE_SRC_NONE;
            memoryOpSize_EX_temp = rvDefs::MEMORY_OP_SIZE_NONE;
            storeLoad_EX_temp    = 1'b0;
            unsignedLoad_EX_temp = 1'b0;
            xaluOp_EX_temp       = rvDefs::XALU_OP_SUM;
            xaluArithmeticFlag_EX_temp = 1'b0;
            immediateXaluSecondary_EX_temp = 1'b0;
            pcXaluPrimary_EX_temp = 1'b0;
            read1Data_EX_temp     = 32'b0;
            read2Data_EX_temp     = 32'b0;
            rs1_EX_temp           = 5'b0;
            rs2_EX_temp          = 5'b0;
            immediate_EX_temp    = 32'b0;
            instructionAddress_EX_temp = 32'b0;
            zeroXaluPrimary_EX_temp = 1'b0;
            branchOp_EX_temp = rvDefs::BRANCH_OP_NONE;
            instruction_EX_temp = 32'b0;
            branchNegate_EX_temp = 1'b0;
            branchPrediction_EX_temp = 1'b0;
            jump_EX_temp = 1'b0;
            JALR_EX_temp = 1'b0;
        end
        else begin
            read1Data_EX_temp = read1Data_ID;
            read2Data_EX_temp = read2Data_ID;
            rs1_EX_temp = rs1_ID;
            rs2_EX_temp = rs2_ID;
            rd_EX_temp = rd_ID;
            immediate_EX_temp = immediate_ID;
            instructionAddress_EX_temp = instructionAddress_ID;
            xaluOp_EX_temp = xaluOp_ID;
            xaluArithmeticFlag_EX_temp = xaluArithmeticFlag_ID;
            memoryOpSize_EX_temp = memoryOpSize_ID;
            unsignedLoad_EX_temp = unsignedLoad_ID;
            storeLoad_EX_temp = storeLoad_ID;
            writeEnable_EX_temp = writeEnable_ID;
            writeSource_EX_temp = writeSource_ID;
            immediateXaluSecondary_EX_temp = immediateXaluSecondary_ID;
            zeroXaluPrimary_EX_temp = zeroXaluPrimary_ID;
            branchOp_EX_temp = branchOp_ID;
            instruction_EX_temp = instruction_ID;
            pcXaluPrimary_EX_temp = pcXaluPrimary_ID;
            branchNegate_EX_temp = branchNegate_ID;
            branchPrediction_EX_temp = branchPrediction_ID;
            jump_EX_temp = jump_ID;
            JALR_EX_temp = JALR_ID;
        end
    end
    
    always_ff @(posedge clk or negedge resetN) begin
        if (!resetN) begin
            read1Data_EX <= 32'b0;
            read2Data_EX <= 32'b0;
            rs1_EX <= 5'b0;
            rs2_EX <= 5'b0;
            rd_EX <= 5'b0;
            immediate_EX <= 32'b0;
            instructionAddress_EX <= 32'b0;
            xaluOp_EX <= rvDefs::XALU_OP_SUM;
            xaluArithmeticFlag_EX <= 1'b0;
            memoryOpSize_EX <= rvDefs::MEMORY_OP_SIZE_NONE;
            unsignedLoad_EX <= 1'b0;
            storeLoad_EX <= 1'b0;
            writeEnable_EX <= 1'b0;
            writeSource_EX <= rvDefs::WRITE_SRC_NONE;
            immediateXaluSecondary_EX <= 1'b0;
            zeroXaluPrimary_EX <= 1'b0;
            branchOp_EX <= rvDefs::BRANCH_OP_NONE;
            instruction_EX <= 32'b0;
            pcXaluPrimary_EX <= 1'b0;
            branchNegate_EX <= 1'b0;
            branchPrediction_EX <= 1'b0;
            jump_EX <= 1'b0;
            JALR_EX <= 1'b0;
        end
        else begin
            read1Data_EX <= read1Data_EX_temp;
            read2Data_EX <= read2Data_EX_temp;
            rs1_EX <= rs1_EX_temp;
            rs2_EX <= rs2_EX_temp;
            rd_EX <= rd_EX_temp;
            immediate_EX <= immediate_EX_temp;
            instructionAddress_EX <= instructionAddress_EX_temp;
            xaluOp_EX <= xaluOp_EX_temp;
            xaluArithmeticFlag_EX <= xaluArithmeticFlag_EX_temp;
            memoryOpSize_EX <= memoryOpSize_EX_temp;
            unsignedLoad_EX <= unsignedLoad_EX_temp;
            storeLoad_EX <= storeLoad_EX_temp;
            writeEnable_EX <= writeEnable_EX_temp;
            writeSource_EX <= writeSource_EX_temp;
            immediateXaluSecondary_EX <= immediateXaluSecondary_EX_temp;
            zeroXaluPrimary_EX <= zeroXaluPrimary_EX_temp;
            branchOp_EX <= branchOp_EX_temp;
            instruction_EX <= instruction_EX_temp;
            pcXaluPrimary_EX <= pcXaluPrimary_EX_temp;
            branchNegate_EX <= branchNegate_EX_temp;
            branchPrediction_EX <= branchPrediction_EX_temp;
            jump_EX <= jump_EX_temp;
            JALR_EX <= JALR_EX_temp;
        end 
    end

endmodule