module RV32I_subsystem (
    input  logic CLK,
    input  logic RSTN,
    input  logic stall
);    
    // Instruction AHB Bus Signals
    logic               nextInstructionFlag;
    rvDefs::mem_addr_t  nextInstructionAddress;
    rvDefs::word_t      instruction;
    rvDefs::mem_addr_t  instructionAddressAHB;
    logic               HREADY_ibus;

    // Data AHB Bus Signal
    logic                 memWrite;
    logic                 memRead;
    rvDefs::mem_addr_t    addressLSU;
    rvDefs::word_t        writeDataLSU;
    logic [2:0]           memSize;
    rvDefs::word_t        memReadData;
    logic                 HREADY_dbus;

    Core RV32I (
        .CLK                        (CLK),
        .RSTN                       (RSTN),
        .stall                      (stall),              
        .nextInstructionFlag        (nextInstructionFlag),
        .nextInstructionAddress     (nextInstructionAddress),
        .instruction                (instruction),
        .instructionAddressAHB      (instructionAddressAHB),
        .HREADY_ibus                (HREADY_ibus),
        .memWrite                   (memWrite),
        .memRead                    (memRead),
        .addressLSU                 (addressLSU),
        .writeDataLSU               (writeDataLSU),
        .memSize                    (memSize),
        .memReadData                (memReadData),
        .HREADY_dbus                (HREADY_dbus)
    );

    // Initialize Instruction AHB Bus
    AHBInstructionManager InstructionManager (
        .clk                    (CLK),
        .resetN                 (RSTN),
        .nextInstructionFlag    (nextInstructionFlag),
        .instructionAddress     (nextInstructionAddress),
        .instruction            (instruction),
        .instructionAddressAHB  (instructionAddressAHB),
        .HREADY_ibus            (HREADY_ibus)
    );

    // Initialize Data AHB Bus
    AHBDataManager DataManager (
        .clk(CLK),
        .resetN(RSTN),
        .memWrite(memWrite),
        .memRead(memRead),
        .address(addressLSU),
        .writeData(writeDataLSU),
        .memSize(memSize),
	    .readData(memReadData),
        .HREADY_dbus(HREADY_dbus)
    );

endmodule