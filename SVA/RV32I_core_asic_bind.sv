//------------------------------------------------------------------------------
// Author      : Brian Liau (brian.liau@tufts.edu)
// File        : RV32I_core_asic_bind.sv
// Design Unit : RV32I_core_asic_bind
// Description : Binds protocol and core assertions into the ASIC hardening top
//               (RV32I_core_asic). AHB-Lite checkers attach to the port-exposed
//               managers; core invariants attach to Core (unchanged).
// Target      : Simulation
//------------------------------------------------------------------------------
module RV32I_core_asic_bind;

    // AHB-Lite protocol checker on the data bus manager
    bind AHBDataManagerPort AHB_lite_checker u_data_manager_chk (
        .HCLK   (clk),
        .HRESETn(resetN),
        .HADDR  (HADDR),
        .HTRANS (HTRANS),
        .HREADY (HREADY),
        .HRESP  (HRESP),
        .HWRITE (HWRITE),      // was tied to 1'b0 in RV32I_core_bind.sv
        .HSIZE  (HSIZE),
        .HWDATA (HWDATA)
    );

    // AHB-Lite protocol checker on the instruction bus manager
    bind AHBInstructionManagerPort AHB_lite_checker u_instruction_manager_chk (
        .HCLK   (clk),
        .HRESETn(resetN),
        .HADDR  (HADDR),
        .HTRANS (HTRANS),
        .HREADY (HREADY),
        .HRESP  (HRESP),
        .HWRITE (HWRITE),
        .HSIZE  (HSIZE),
        .HWDATA (HWDATA)
    );

    // RV32I core invariants (unchanged)
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
