`timescale 1ns/1ps

//------------------------------------------------------------------------------
// Author      : Brian Liau (brian.liau@tufts.edu)
// File        : ForwardingUnit.sv
// Design Unit : ForwardingUnit
// Description : Combinational hazard detection and data forwarding unit. 
//               Resolves RAW (read after write) data hazards for EX and ID
//               pipeline stages by forwarding the most recent modfied stage 
//               results prior to write-back.
// Dependencies: rvDefs.sv
// Target      : Synthesis
//------------------------------------------------------------------------------
module ForwardingUnit(
    input logic                    resetN,
    input rvDefs::xreg_addr_t      rs1,
    input rvDefs::xreg_addr_t      rs2,
    input rvDefs::xreg_addr_t      EXMEM_rd,
    input logic                    EXMEM_RegWrite,
    input rvDefs::xreg_addr_t      MEMWB_rd,
    input logic                    MEMWB_RegWrite,
    input rvDefs::xreg_addr_t      ID_rs1,
    output rvDefs::forward_mux_t    ForwardA,
    output rvDefs::forward_mux_t    ForwardB,
    output rvDefs::forward_mux_t    ForwardID_A
);
    always_comb begin
        if (!resetN) begin
            ForwardA    = rvDefs::FORWARD_REGS;
            ForwardB    = rvDefs::FORWARD_REGS;
            ForwardID_A = rvDefs::FORWARD_REGS;
        end else begin
            // Forwarding logic for EX Stage Operand A (rs1)
            if (EXMEM_RegWrite && (EXMEM_rd != 5'd0) && (EXMEM_rd == rs1)) begin
                ForwardA = rvDefs::FORWARD_MEM;
            end else if (MEMWB_RegWrite && (MEMWB_rd != 5'd0) && (MEMWB_rd == rs1)) begin
                ForwardA = rvDefs::FORWARD_ALU;
            end else begin
                ForwardA = rvDefs::FORWARD_REGS;
            end

            // Forwarding logic for EX Stage Operand B (rs2)
            if (EXMEM_RegWrite && (EXMEM_rd != 5'd0) && (EXMEM_rd == rs2)) begin
                ForwardB = rvDefs::FORWARD_MEM;
            end else if (MEMWB_RegWrite && (MEMWB_rd != 5'd0) && (MEMWB_rd == rs2)) begin
                ForwardB = rvDefs::FORWARD_ALU;
            end else begin
                ForwardB = rvDefs::FORWARD_REGS;
            end

            // Forwarding logic for ID Stage Operand A (JALR / Branch evaluation)
            if (EXMEM_RegWrite && (EXMEM_rd != 5'd0) && (EXMEM_rd == ID_rs1)) begin
                ForwardID_A = rvDefs::FORWARD_MEM; 
            end else if (MEMWB_RegWrite && (MEMWB_rd != 5'd0) && (MEMWB_rd == ID_rs1)) begin
                ForwardID_A = rvDefs::FORWARD_ALU; 
            end else begin
                ForwardID_A = rvDefs::FORWARD_REGS;
            end
        end
    end
endmodule