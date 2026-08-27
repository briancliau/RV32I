module RV32I_core_bind;

    bind AHBDataManager AHB_lite_checker u_data_manager (
        .HCLK   (clk),
        .HRESETn(resetN),
        .HADDR  (DataManager.HADDR),
        .HTRANS (DataManager.HTRANS),
        .HREADY (DataManager.HREADY),
        .HRESP  (DataManager.HRESP),
        .HWRITE (1'b0),
        .HSIZE  (DataManager.HSIZE),
        .HWDATA (DataManager.HWDATA)
    );

    bind AHBInstructionManager AHB_lite_checker u_instruction_manager (
        .HCLK   (clk),
        .HRESETn(resetN),
        .HADDR  (InstructionManager.HADDR),
        .HTRANS (InstructionManager.HTRANS),
        .HREADY (InstructionManager.HREADY),
        .HRESP  (InstructionManager.HRESP),
        .HWRITE (InstructionManager.HWRITE),
        .HSIZE  (InstructionManager.HSIZE),
        .HWDATA (InstructionManager.HWDATA)
    );

    bind Core RV32I_core_sva u_core_sva (
        .CLK                (CLK),
        .RSTN               (RSTN),
        .writeEnable_WB     (writeEnable_WB),
        .rd_WB              (rd_WB),
        .registerWriteData  (registerWriteData),
        .instructionAddress (instructionAddress),
        .memRead            (memRead),
        .memWrite           (memWrite),
        .address            (address_MEM),
        .memSize            (memSize),
        .pipelineStall      (pipelineStall),
        .pipelineFlush      (pipelineFlush),
        .instruction_ID     (instruction_ID),
        .writeSource        (writeSource),
        .writeEnable_EX     (writeEnable_EX),
        .IFID_write         (IFID_write),
        .instruction_IF     (instructionAddressAHB)
    );

endmodule