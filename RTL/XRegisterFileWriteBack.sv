module XRegisterFileWriteBack (
    input  logic                clk, 
    input  logic                resetN, 
    input  logic                writeEnable, 
    input  rvDefs::xreg_addr_t  writeReg, 
    input  rvDefs::xreg_t       writeData,   
    output logic                writeEnableBack, 
    output rvDefs::xreg_addr_t  writeRegBack, 
    output rvDefs::xreg_t       writeDataBack   
); 
    // always_ff @(posedge clk or negedge resetN) begin
    //     if (!resetN) begin
    //         writeEnableBack <= 1'b0;
    //         writeRegBack <= '0;
    //         writeDataBack <= '0;
    //     end else begin
    //         writeEnableBack <= writeEnable;
    //         writeRegBack <= writeReg;
    //         writeDataBack <= writeData;
    //     end
    // end

    assign writeEnableBack = writeEnable;
    assign writeRegBack = writeReg;
    assign writeDataBack = writeData;
endmodule