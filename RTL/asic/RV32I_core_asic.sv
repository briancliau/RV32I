//------------------------------------------------------------------------------
// Author      : Brian Liau (brian.liau@tufts.edu)
// File        : RV32I_core_asic.sv
// Design Unit : RV32I_core_asic
// Description : ASIC hardening top: RV32I Core + AHB-Lite instruction and data
//               managers. Both AHB-Lite buses are top-level ports so every
//               architectural result is observable at a pin and the core
//               cannot be optimized away. Instruction/data memories are
//               external to this block (SRAM macros or off-block).
//               (The FPGA/UPduino top with the LED remains RV32I_subsystem.)
// Dependencies: rvDefs.sv, AHB_pkg.sv
// Target      : Synthesis (OpenLane2, sky130_fd_sc_hd)
//------------------------------------------------------------------------------
module RV32I_core_asic (
    input  logic          CLK,
    input  logic          RSTN,
    input  logic          stall,

    // AHB-Lite instruction bus (manager side)
    output logic [31:0]   I_HADDR,
    output logic [1:0]    I_HTRANS,
    output logic          I_HWRITE,
    output logic [2:0]    I_HSIZE,
    output logic [31:0]   I_HWDATA,
    input  logic [31:0]   I_HRDATA,
    input  logic          I_HRESP,
    input  logic          I_HREADY,

    // AHB-Lite data bus (manager side)
    output logic [31:0]   D_HADDR,
    output logic [1:0]    D_HTRANS,
    output logic          D_HWRITE,
    output logic [2:0]    D_HSIZE,
    output logic [31:0]   D_HWDATA,
    input  logic [31:0]   D_HRDATA,
    input  logic          D_HRESP,
    input  logic          D_HREADY
);

    // Core <-> Instruction Manager
    logic               nextInstructionFlag;
    rvDefs::mem_addr_t  nextInstructionAddress;
    rvDefs::word_t      instruction;
    rvDefs::mem_addr_t  instructionAddressAHB;
    logic               HREADY_ibus;

    // Core <-> Data Manager
    logic               memWrite;
    logic               memRead;
    rvDefs::mem_addr_t  addressLSU;
    rvDefs::word_t      writeDataLSU;
    logic [2:0]         memSize;
    rvDefs::word_t      memReadData;
    logic               HREADY_dbus;

    Core RV32I (
        .CLK                    (CLK),
        .RSTN                   (RSTN),
        .stall                  (stall),
        .nextInstructionFlag    (nextInstructionFlag),
        .nextInstructionAddress (nextInstructionAddress),
        .instruction            (instruction),
        .instructionAddressAHB  (instructionAddressAHB),
        .HREADY_ibus            (HREADY_ibus),
        .memWrite               (memWrite),
        .memRead                (memRead),
        .addressLSU             (addressLSU),
        .writeDataLSU           (writeDataLSU),
        .memSize                (memSize),
        .memReadData            (memReadData),
        .HREADY_dbus            (HREADY_dbus)
    );

    AHBInstructionManagerPort InstructionManager (
        .clk                    (CLK),
        .resetN                 (RSTN),
        .nextInstructionFlag    (nextInstructionFlag),
        .instructionAddress     (nextInstructionAddress),
        .instruction            (instruction),
        .instructionAddressAHB  (instructionAddressAHB),
        .HREADY_ibus            (HREADY_ibus),
        .HADDR                  (I_HADDR),
        .HTRANS                 (I_HTRANS),
        .HWRITE                 (I_HWRITE),
        .HSIZE                  (I_HSIZE),
        .HWDATA                 (I_HWDATA),
        .HRDATA                 (I_HRDATA),
        .HRESP                  (I_HRESP),
        .HREADY                 (I_HREADY)
    );

    AHBDataManagerPort DataManager (
        .clk                    (CLK),
        .resetN                 (RSTN),
        .memWrite               (memWrite),
        .memRead                (memRead),
        .address                (addressLSU),
        .writeData              (writeDataLSU),
        .memSize                (memSize),
        .readData               (memReadData),
        .HREADY_dbus            (HREADY_dbus),
        .HADDR                  (D_HADDR),
        .HTRANS                 (D_HTRANS),
        .HWRITE                 (D_HWRITE),
        .HSIZE                  (D_HSIZE),
        .HWDATA                 (D_HWDATA),
        .HRDATA                 (D_HRDATA),
        .HRESP                  (D_HRESP),
        .HREADY                 (D_HREADY)
    );

endmodule
