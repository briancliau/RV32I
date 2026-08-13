module MEMWB_register (
    input logic clk,
    input logic resetN,
    input rvDefs::xreg_addr_t rd_MEM,
    input  rvDefs::mem_addr_t address_MEM,
    input logic writeEnable_MEM,
    input rvDefs::word_t memToRegData_MEM,
    input rvDefs::write_src_t writeSource_MEM,
    input rvDefs::mem_addr_t instructionAddress_MEM,
    output rvDefs::mem_addr_t instructionAddress_WB,
    output rvDefs::write_src_t writeSource_WB,
    output logic writeEnable_WB,
    output rvDefs::mem_addr_t address_WB,
    output rvDefs::xreg_addr_t rd_WB,
    output rvDefs::word_t memToRegData_WB
);

    always_ff @(posedge clk or negedge resetN) begin
        if (!resetN) begin
            rd_WB <= 5'b0;
            writeEnable_WB <= 1'b0;
            address_WB <= 32'b0;
            writeSource_WB <= rvDefs::WRITE_SRC_NONE;
            instructionAddress_WB <= 32'b0;
            memToRegData_WB <= 32'b0;
        end
        else begin
            rd_WB <= rd_MEM;
            writeEnable_WB <= writeEnable_MEM;
            address_WB <= address_MEM;
            writeSource_WB <= writeSource_MEM;
            instructionAddress_WB <= instructionAddress_MEM;
            memToRegData_WB <= memToRegData_MEM;
        end
    end

endmodule