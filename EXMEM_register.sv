module EXMEM_register (
    input logic                     clk,
    input logic                     resetN,
    input  rvDefs::memory_op_size_t memoryOpSize_EX,
    input  logic                    unsignedLoad_EX,
    input  logic                    storeLoad_EX,
    input  rvDefs::mem_addr_t       address_EX,                 //Is ALU result
    input rvDefs::xreg_addr_t       rd_EX,
    input logic                     writeEnable_EX,
    input rvDefs::write_src_t       writeSource_EX,
    input rvDefs::mem_addr_t        instructionAddress_EX,
    input rvDefs::xreg_t            memWriteData_EX,
    output rvDefs::xreg_t           memWriteData_MEM,
    output rvDefs::mem_addr_t       instructionAddress_MEM,
    output rvDefs::write_src_t      writeSource_MEM,
    output logic                    writeEnable_MEM,
    output rvDefs::xreg_addr_t      rd_MEM,
    output rvDefs::memory_op_size_t memoryOpSize_MEM,
    output logic                    unsignedLoad_MEM,
    output logic                    storeLoad_MEM,
    output rvDefs::mem_addr_t       address_MEM
);
    always_ff @(posedge clk or negedge resetN) begin
        if (!resetN) begin
            rd_MEM <= 5'b0;
            memoryOpSize_MEM <= rvDefs::MEMORY_OP_SIZE_NONE;
            unsignedLoad_MEM <= 1'b0;
            storeLoad_MEM <= 1'b0;
            address_MEM <= 32'b0;
            writeEnable_MEM <= 1'b0;
            writeSource_MEM <= rvDefs::WRITE_SRC_NONE;
            instructionAddress_MEM <= 32'b0;
            memWriteData_MEM <= 32'b0;
        end
        else begin
            rd_MEM <= rd_EX;
            memoryOpSize_MEM <= memoryOpSize_EX;
            unsignedLoad_MEM <= unsignedLoad_EX;
            storeLoad_MEM <= storeLoad_EX;
            address_MEM <= address_EX;
            writeEnable_MEM <= writeEnable_EX;
            writeSource_MEM <= writeSource_EX;
            instructionAddress_MEM <= instructionAddress_EX;
            memWriteData_MEM <= memWriteData_EX;
        end 
    end

endmodule