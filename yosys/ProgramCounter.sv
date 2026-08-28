`timescale 1ns/1ps

//------------------------------------------------------------------------------
// Author      : Brian Liau (brian.liau@tufts.edu)
// File        : ProgramCounter.sv
// Design Unit : ProgramCounter
// Description : Program Counter register and next-PC generation logic with 
//               branch prediction/correction support.
// Dependencies: rvDefs.sv
// Target      : Synthesis
//------------------------------------------------------------------------------
module ProgramCounter #(
    parameter rvDefs::mem_addr_t RESET_VALUE = rvDefs::mem_addr_t'(0)
)
(
    input  logic              clk,
    input  logic              resetN,
    input  logic              enable,  
    input  logic              branchPrediction,
    input  logic              branchCorrection,
    input  rvDefs::mem_addr_t addrLoad,
    input  rvDefs::mem_addr_t branchCorrectionLoad,
    output rvDefs::mem_addr_t addrOut 

);

    localparam rvDefs::mem_addr_t INCREMENT = 32'd4;
    rvDefs::mem_addr_t addrNext;
    
    // Next Program Counter Selection Logic
    always_comb begin
        if (branchCorrection) begin
            // Highest priority: Misprediction recovery target (forced alignment)
            addrNext = branchCorrectionLoad;
        end else if (branchPrediction) begin
            // Speculative predicted branch target
            addrNext = addrLoad;
        end else begin
            // Normal sequential instruction fetch (PC + 4)
            addrNext = addrOut + INCREMENT;
        end
    end

    // Program Counter State Register
    always_ff @(posedge clk or negedge resetN) begin
        if (!resetN) begin
            addrOut <= RESET_VALUE;
        end else if (enable) begin
            addrOut <= addrNext;
        end
    end

endmodule
