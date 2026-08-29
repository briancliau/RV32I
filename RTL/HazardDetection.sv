//------------------------------------------------------------------------------
// Author      : Brian Liau (brian.liau@tufts.edu)
// File        : HazardDetection.sv
// Design Unit : HazardDetection
// Description : Pipeline hazard detection unit. Enforces a 2-cycle stall for 
//               all Load-Use data hazards to accommodate AHB bus read latency.
// Dependencies: rvDefs.sv
// Target      : Synthesis
//------------------------------------------------------------------------------
module HazardDetection (
    input  logic                    clk,
    input  logic                    resetN,
    input  rvDefs::xreg_addr_t      IDEX_r1,
    input  rvDefs::xreg_addr_t      IDEX_r2,
    input  rvDefs::xreg_addr_t      EXMEM_rd,
    input  logic                    IDEX_memread,
    input  rvDefs::instruction_t    instruction_IF,
    output logic                    PC_update,
    output logic                    IFID_write,
    output logic                    IDEX_delay
);
    logic [1:0] stallCounter;
    logic       loadUseHazard;

    // Detect Load-Use Hazard: EX stage is reading memory and destination matches source regs
    assign loadUseHazard = IDEX_memread && (EXMEM_rd != '0) && 
                           (IDEX_r1 == EXMEM_rd || IDEX_r2 == EXMEM_rd);

    // Combinational Stall Signal Logic
    always_comb begin
        if (!resetN) begin
            PC_update  = 1'b1;
            IFID_write = 1'b1;
            IDEX_delay = 1'b0;
        end else if (loadUseHazard && (stallCounter < 2'b10)) begin
            // Hold stall for 2 full cycles to allow AHB Address + Data phases to complete
            PC_update  = 1'b0;
            IFID_write = 1'b0;
            IDEX_delay = 1'b1;
        end else begin
            PC_update  = 1'b1;
            IFID_write = 1'b1;
            IDEX_delay = 1'b0;
        end
    end

    // Sequential 2-Cycle Stall Timer
    always_ff @(posedge clk or negedge resetN) begin
        if (!resetN) begin
            stallCounter <= 2'b00;
        end else if (loadUseHazard && (stallCounter < 2'b10)) begin
            stallCounter <= stallCounter + 1'b1;
        end else begin
            stallCounter <= 2'b00;
        end
    end

endmodule