`timescale 1ns/1ps

module LSU (
    input  logic                    clk,
    input  logic                    resetN,
    input  rvDefs::memory_op_size_t memoryOpSize,
    input  logic                    unsignedLoad,
    input  logic                    storeLoad,
    input  rvDefs::mem_addr_t       address,
    input  rvDefs::word_t           readData,
    input  rvDefs::word_t           memWriteData,
    input  logic                    HREADY_dbus,
    output logic                    memWrite,
    output logic                    memRead,
    output logic [2:0]              memSize,
    output rvDefs::word_t           writeDataLSU,
    output logic [31:0]             addressLSU,
    output rvDefs::word_t           memToRegData
);
    rvDefs::memory_op_size_t prev_memoryOpSize;
    logic                    prev_unsignedLoad;
    logic [31:0]             prev_address;

    assign memWrite = (memoryOpSize != rvDefs::MEMORY_OP_SIZE_NONE) && (storeLoad == 1'b1) && resetN;
    assign memRead = (memoryOpSize != rvDefs::MEMORY_OP_SIZE_NONE) && (storeLoad == 1'b0) && resetN;
    assign addressLSU = address;

    always_comb begin
        case (memoryOpSize)
            rvDefs::MEMORY_OP_SIZE_BYTE: memSize = 3'b000;
            rvDefs::MEMORY_OP_SIZE_HALF: memSize = 3'b001;
            rvDefs::MEMORY_OP_SIZE_WORD: memSize = 3'b010;
            default: memSize = 3'b111;
        endcase
    end

    always_comb begin
        writeDataLSU = 32'b0;
        case (memoryOpSize)
            rvDefs::MEMORY_OP_SIZE_WORD: begin
                writeDataLSU = memWriteData;
            end
            rvDefs::MEMORY_OP_SIZE_HALF: begin
                if (address[1] == 1'b0) begin
                    writeDataLSU = {16'b0, memWriteData[15:0]};
                end else begin
                    writeDataLSU = {memWriteData[15:0], 16'b0};
                end
            end
            rvDefs::MEMORY_OP_SIZE_BYTE: begin
                case (address[1:0])
                    2'b00: begin
                        writeDataLSU = {24'b0, memWriteData[7:0]};
                    end
                    2'b01: begin
                        writeDataLSU = {16'b0, memWriteData[7:0], 8'b0};
                    end
                    2'b10: begin
                        writeDataLSU = {8'b0, memWriteData[7:0], 16'b0};
                    end
                    2'b11: begin
                        writeDataLSU = {memWriteData[7:0], 24'b0};
                    end
                endcase
            end
            default: begin
                writeDataLSU = 32'b0;
            end
        endcase
    end

    always_comb begin
        memToRegData = 32'b0;
        case (prev_memoryOpSize)
            rvDefs::MEMORY_OP_SIZE_BYTE: begin
                case (prev_address[1:0])
                    2'b00: begin
                        if (prev_unsignedLoad) begin
                            memToRegData = {24'b0, readData[7:0]};
                        end
                        else begin
                            memToRegData = {{24{readData[7]}}, readData[7:0]};
                        end
                    end
                    2'b01: begin
                        if (prev_unsignedLoad) begin
                            memToRegData = {24'b0, readData[15:8]};
                        end
                        else begin
                            memToRegData = {{24{readData[15]}}, readData[15:8]};
                        end
                    end
                    2'b10: begin
                        if (prev_unsignedLoad) begin
                            memToRegData = {24'b0, readData[23:16]};
                        end
                        else begin
                            memToRegData = {{24{readData[23]}}, readData[23:16]};
                        end
                    end
                    2'b11: begin
                        if (prev_unsignedLoad) begin
                            memToRegData = {24'b0, readData[31:24]};
                        end
                        else begin
                            memToRegData = {{24{readData[31]}}, readData[31:24]};
                        end
                    end
                endcase
            end
            rvDefs::MEMORY_OP_SIZE_HALF: begin
                if (prev_address[1] == 1'b0) begin
                    if (prev_unsignedLoad) begin
                        memToRegData = {16'b0, readData[15:0]};
                    end
                    else begin
                        memToRegData = {{16{readData[15]}}, readData[15:0]};
                    end
                end
                else begin
                    if (prev_unsignedLoad) begin
                        memToRegData = {16'b0, readData[31:16]};
                    end
                    else begin
                        memToRegData = {{16{readData[31]}}, readData[31:16]};
                    end
                end
            end
            rvDefs::MEMORY_OP_SIZE_WORD: begin
                memToRegData = readData;
            end
            default: begin
                memToRegData = 32'b0;
            end
        endcase
    end

    always_ff @(posedge clk or negedge resetN) begin
        if (!resetN) begin
            prev_memoryOpSize <= rvDefs::MEMORY_OP_SIZE_NONE;
            prev_unsignedLoad <= 1'b0;
            prev_address      <= 32'b0;
        end else if (HREADY_dbus) begin
            prev_memoryOpSize <= memoryOpSize;
            prev_unsignedLoad <= unsignedLoad;
            prev_address      <= address;
        end
    end

endmodule