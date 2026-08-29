//------------------------------------------------------------------------------
// Author      : Brian Liau (brian.liau@tufts.edu)
// File        : RV32I_subsystem.sv
// Design Unit : RV32I_subsystem
// Description : Top-level subsystem preserving Core and AHB Managers.
//------------------------------------------------------------------------------    
module RV32I_subsystem (
    input  logic CLK,
    input  logic RSTN,
    input  logic stall,
    output logic LED
);

    // Keep attributes on Instruction AHB Bus Interconnects
    (* keep = "true" *) logic               nextInstructionFlag;
    (* keep = "true" *) rvDefs::mem_addr_t  nextInstructionAddress;
    (* keep = "true" *) rvDefs::word_t      instruction;
    (* keep = "true" *) rvDefs::mem_addr_t  instructionAddressAHB;
    (* keep = "true" *) logic               HREADY_ibus;

    // Keep attributes on Data AHB Bus Interconnects
    (* keep = "true" *) logic               memWrite;
    (* keep = "true" *) logic               memRead;
    (* keep = "true" *) rvDefs::mem_addr_t  addressLSU;
    (* keep = "true" *) rvDefs::word_t      writeDataLSU;
    (* keep = "true" *) logic [2:0]         memSize;
    (* keep = "true" *) rvDefs::word_t      memReadData;
    (* keep = "true" *) logic               HREADY_dbus;

    // Preserve the Core hierarchy
    (* keep_hierarchy = "true" *)
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

    // Preserve the Instruction Manager hierarchy
    (* keep_hierarchy = "true" *)
    AHBInstructionManager InstructionManager (
        .clk                    (CLK),
        .resetN                 (RSTN),
        .nextInstructionFlag    (nextInstructionFlag),
        .instructionAddress     (nextInstructionAddress),
        .instruction            (instruction),
        .instructionAddressAHB  (instructionAddressAHB),
        .HREADY_ibus            (HREADY_ibus)
    );

    // Preserve the Data Manager hierarchy
    (* keep_hierarchy = "true" *)
    AHBDataManager DataManager (
        .clk                    (CLK),
        .resetN                 (RSTN),
        .memWrite               (memWrite),
        .memRead                (memRead),
        .address                (addressLSU),
        .writeData              (writeDataLSU),
        .memSize                (memSize),
        .readData               (memReadData),
        .HREADY_dbus            (HREADY_dbus)
    );

    assign LED = nextInstructionFlag;

endmodule