//------------------------------------------------------------------------------
// Author      : Brian Liau (brian.liau@tufts.edu)
// File        : XRegisterFile.sv
// Design Unit : XRegisterFile
// Description : 32x32-bit Integer Register File for RISC-V. Hardwires x0 to 0
//               and supports internal write-to-read forwarding (bypass).
// Dependencies: rvDefs.sv
// Target      : Synthesis
//------------------------------------------------------------------------------
module XRegisterFile
(
    input  logic                clk,         
    input  logic                writeEnable, 
    input  rvDefs::xreg_addr_t  read1Reg,    
    input  rvDefs::xreg_addr_t  read2Reg,    
    input  rvDefs::xreg_addr_t  writeReg,    
    input  rvDefs::xreg_t       writeData,   
    output rvDefs::xreg_t       read1Data,   
    output rvDefs::xreg_t       read2Data    
);
    // Array for registers x1 to x31
    rvDefs::xreg_t registers [1 : rvDefs::XREG_COUNT - 1]; 

    // Synchronous Write on Rising Clock Edge
    always_ff @(posedge clk) begin
        if (writeEnable && (writeReg != rvDefs::xreg_addr_t'(0)))
            registers[writeReg] <= writeData;
    end

    // Combinational Read with Internal Write-Through Forwarding
    always_comb begin
        // Read Port 1
        if (read1Reg == rvDefs::xreg_addr_t'(0)) begin
            read1Data = rvDefs::xreg_t'(0);
        end else if (writeEnable && (read1Reg == writeReg)) begin
            read1Data = writeData; // Internal Forwarding (WB -> ID)
        end else begin
            read1Data = registers[read1Reg];
        end

        // Read Port 2
        if (read2Reg == rvDefs::xreg_addr_t'(0)) begin
            read2Data = rvDefs::xreg_t'(0);
        end else if (writeEnable && (read2Reg == writeReg)) begin
            read2Data = writeData; // Internal Forwarding (WB -> ID)
        end else begin
            read2Data = registers[read2Reg];
        end
    end

endmodule
