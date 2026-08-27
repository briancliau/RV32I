module RV32I_core_sva (
    input logic         CLK,
    input logic         RSTN,
    input logic         writeEnable_WB,
    input logic [4:0]   rd_WB,
    input logic [31:0]  registerWriteData,
    input logic [31:0]  instructionAddress,
    input logic         memRead,
    input logic         memWrite,
    input logic [31:0]  address,
    input logic [2:0]   memSize,
    input logic         pipelineStall,
    input logic         pipelineFlush,
    input logic [31:0]  instruction_ID,
    input logic [1:0]   writeSource,
    input logic         writeEnable_EX,
    input logic         IFID_write,
    input rvDefs::instruction_t instruction_IF
);

    // ---------------------------------------------------------
    // Property Defaults
    // ---------------------------------------------------------
    default clocking cb @(posedge CLK);
    endclocking

    default disable iff (!RSTN);

    
    // ---------------------------------------------------------
    // Core Invariants (RISC-V Specification Rules)
    // ---------------------------------------------------------
    property x0_never_modified;
        (writeEnable_WB && (rd_WB == 5'd0)) |-> (registerWriteData == 32'h0000_0000);
    endproperty
    assert_x0_never_modified : assert property (x0_never_modified)
        else $error("Violation - write back to x0 is not zero");

    property pc_alignment;
        instructionAddress[1:0] == 2'b00;
    endproperty 
    assert_pc_alignment : assert property (pc_alignment)
        else $error("Violation - PC is not word aligned");

    property no_simultaneous_read_write;
        !(memRead && memWrite);
    endproperty
    assert_no_simultaneous_read_write : assert property (no_simultaneous_read_write)
        else $error("Violation - memRead and memWrite assert simultaneously");

    property memory_access_word_aligned;
        ((memRead || memWrite) && (memSize == 3'b010)) |-> (address[1:0] == 2'b00);
    endproperty
    assert_memory_access_word_aligned : assert property (memory_access_word_aligned)
        else $error("Violation - memory access for word not word aligned");

    // ---------------------------------------------------------
    // Pipeline Integrity 
    // ---------------------------------------------------------
    property pipelineStalls_holds_pc;
        pipelineStall |=> $stable(instructionAddress);
    endproperty
    assert_pipelineStalls_holds_pc : assert property (pipelineStalls_holds_pc)
        else $error("Violation - pipeline stalls do not maintain PC value");

    property pipelineStalls_holds_IFID;
        (pipelineStall && !pipelineFlush) |=> $stable(instruction_ID);
    endproperty
    assert_pipelineStalls_holds_IFID : assert property (pipelineStalls_holds_IFID)
        else $error("Violation - pipeline stalls do not maintain instructions in ID");

    property pipelineFlush_clears_ID;
        pipelineFlush |=> (instruction_ID == rvDefs::NOP);
    endproperty
    assert_pipelineFlush_clears_ID : assert property (pipelineFlush_clears_ID)
        else $error("Violation - pipeline flush does not push a NOP to ID stage");

    property pipelineFlush_clears_EX;
        pipelineFlush |=> (writeEnable_EX == 1'b0);
    endproperty
    assert_pipelineFlush_clears_EX : assert property (pipelineFlush_clears_EX)
        else $error("Violation - pipeline flush does not push a NOP to EX stage");

    property no_x_on_reg_write;
        writeEnable_WB |-> !$isunknown(registerWriteData) && !$isunknown(rd_WB);
    endproperty
    assert_no_x_on_reg_write : assert property (no_x_on_reg_write)
        else $error("Violation - write back to register has unknown data or destination register");

endmodule