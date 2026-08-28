`timescale 1ns/1ps

//------------------------------------------------------------------------------
// Author      : Brian Liau (brian.liau@tufts.edu)
// File        : JALRAddresser.sv
// Design Unit : JALRAddresser
// Description : Latches and enforces JALR target address generation and pipeline
//               flush signals. Enforces RISC-V spec by zeroing LSB of target address.
// Dependencies: rvDefs.sv
// Target      : Synthesis
//------------------------------------------------------------------------------
module JALRAddresser 
(
    input  logic            clk,
    input  logic            resetN,
    input  logic            branchCorrectionJALR,
    input  rvDefs::word_t   aluResult,
    output logic            JALRCorrection,
    output logic            JALR_pipelineFlush,
    output rvDefs::word_t   JALRAddress
);
    always_ff @(posedge clk or negedge resetN) begin
        if (!resetN) begin
            JALRAddress        <= '0;
            JALRCorrection     <= 1'b0;
            JALR_pipelineFlush <= 1'b0;
        end else begin
            if (branchCorrectionJALR) begin
                // Target address = rs1 + immediate with LSB zeroed
                JALRAddress        <= {aluResult[31:1], 1'b0};
                JALRCorrection     <= 1'b1;
                JALR_pipelineFlush <= 1'b1;
            end else begin
                JALRAddress        <= '0;
                JALRCorrection     <= 1'b0;
                JALR_pipelineFlush <= 1'b0;
            end
        end
    end

endmodule