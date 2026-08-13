module ForwardingUnit(
    input logic                     resetN,
    input rvDefs::xreg_addr_t       rs1,
    input rvDefs::xreg_addr_t       rs2,
    input rvDefs::xreg_addr_t       EXMEM_rd,
    input logic                     EXMEM_RegWrite, // Determined by storeLoad (has to be store)
    input rvDefs::xreg_addr_t       MEMWB_rd,
    input logic                     MEMWB_RegWrite,
    input  rvDefs::xreg_addr_t      ID_rs1,
    output rvDefs::forward_mux_t    ForwardA,
    output rvDefs::forward_mux_t    ForwardB,
    output rvDefs::forward_mux_t    ForwardID_A
);
    always_comb begin
        if (!resetN) begin
            ForwardA = rvDefs::FORWARD_REGS;
            ForwardB = rvDefs::FORWARD_REGS;
        end 
        
        // Register 1 MUX signal
        if (EXMEM_RegWrite == 1'b1 && EXMEM_rd == rs1) begin
            ForwardA = rvDefs::FORWARD_MEM;
        end
        else if ((MEMWB_RegWrite == 1'b1 && MEMWB_rd == rs1) && !(EXMEM_RegWrite == 1'b1 && EXMEM_rd == rs1)) begin
            ForwardA = rvDefs::FORWARD_ALU;
        end
        else begin
            ForwardA = rvDefs::FORWARD_REGS;
        end

        // Register 2 MUX signal
        if (EXMEM_RegWrite == 1'b1 && EXMEM_rd == rs2) begin
            ForwardB = rvDefs::FORWARD_MEM;
        end
        else if ((MEMWB_RegWrite == 1'b1 && MEMWB_rd == rs2) && !(EXMEM_RegWrite == 1'b1 && EXMEM_rd == rs2)) begin
            ForwardB = rvDefs::FORWARD_ALU;
        end
        else begin
            ForwardB = rvDefs::FORWARD_REGS;
        end

        // ID stage register 1 MUX signal
        if (ID_rs1 == rs1) begin
            ForwardID_A = rvDefs::FORWARD_REGS;
        end

        if (!resetN) begin
            ForwardID_A = rvDefs::FORWARD_REGS;
        end else begin
            if (EXMEM_RegWrite == 1'b1 && EXMEM_rd != 5'd0 && EXMEM_rd == ID_rs1) begin
                ForwardID_A = rvDefs::FORWARD_MEM; 
            end else if (MEMWB_RegWrite == 1'b1 && MEMWB_rd != 5'd0 && MEMWB_rd == ID_rs1) begin
                ForwardID_A = rvDefs::FORWARD_ALU; 
            end else begin
                ForwardID_A = rvDefs::FORWARD_REGS;
            end
        end
    end
endmodule