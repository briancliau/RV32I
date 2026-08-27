`timescale 1ns/1ps
`ifndef AHB_PKG_SV
`define AHB_PKG_SV

package AHB_pkg;

    localparam int NUM_SUBORDINATES_I = 2;
    localparam int NTOTAL_I      = NUM_SUBORDINATES_I + 1;
    localparam int DEFAULT_IDX_I = NUM_SUBORDINATES_I;
    localparam int unsigned WAIT_STATES_I[NUM_SUBORDINATES_I] = '{0, 1};

    localparam int NUM_SUBORDINATES_D = 2;
    localparam int NTOTAL_D      = NUM_SUBORDINATES_D + 1;
    localparam int DEFAULT_IDX_D = NUM_SUBORDINATES_D;
    localparam int unsigned WAIT_STATES_D[NUM_SUBORDINATES_D] = '{0, 1};

    // Use curly braces to define unique values for each index
    localparam logic [31:0] BASE_ADDR_I [NUM_SUBORDINATES_I] = '{
        32'h0000_0000, 
        32'h0001_0000
    };

    localparam logic [31:0] ADDR_SIZE_I [NUM_SUBORDINATES_I] = '{
        32'h0000_8000, 
        32'h0000_4000
    };

    localparam int ADDR_BITS_I [NUM_SUBORDINATES_I] = '{
        $clog2(ADDR_SIZE_I[0]),
        $clog2(ADDR_SIZE_I[1])
    };

    localparam logic [31:0] BASE_ADDR_D [NUM_SUBORDINATES_D] = '{
        32'h0000_0000, 
        32'h0003_0000 
    };

    localparam logic [31:0] ADDR_SIZE_D [NUM_SUBORDINATES_D] = '{
        32'h0000_8000, 
        32'h0000_4000
    };

    localparam int ADDR_BITS_D [NUM_SUBORDINATES_D] = '{
        $clog2(ADDR_SIZE_D[0]),
        $clog2(ADDR_SIZE_D[1])
    };

    localparam logic [2:0] BYTE = 3'b000;
    localparam logic [2:0] HALF = 3'b001;
    localparam logic [2:0] WORD = 3'b010;

    localparam logic [1:0] IDLE     = 2'b00;
    localparam logic [1:0] BUSY     = 2'b01;
    localparam logic [1:0] NONSEQ   = 2'b10;
    localparam logic [1:0] SEQ      = 2'b11;

    localparam logic [2:0] SINGLE = 3'b000;
    localparam logic [2:0] INCR   = 3'b001;
    localparam logic [2:0] WRAP4  = 3'b010;
    localparam logic [2:0] INCR4  = 3'b011;
    localparam logic [2:0] WRAP8  = 3'b100;
    localparam logic [2:0] INCR8  = 3'b101;
    localparam logic [2:0] WRAP16 = 3'b110;
    localparam logic [2:0] INCR16 = 3'b111;

endpackage

`endif