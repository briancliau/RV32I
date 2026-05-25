module HazardDetection (
    input  logic clk,
    input  logic resetN,
    input  rvDefs::xreg_addr_t IDEX_r1,
    input  rvDefs::xreg_addr_t IDEX_r2,
    input  rvDefs::xreg_addr_t EXMEM_rd,
    input  logic IDEX_memread,               // Load
    input  rvDefs::instruction_t instruction_IF,
    output logic PC_update,
    output logic IFID_write,
    output logic IDEX_delay
);
    logic [1:0] loadCounter;
    logic loadInstruction;
    rvDefs::opcode_t opcode;
    assign opcode = rvDefs::opcode_t'(instruction_IF[6 : 0]);
    assign loadInstruction = (opcode == OPCODE_LOAD);

    always_comb begin
        PC_update = 1'b1;
        IFID_write = 1'b1;
        IDEX_delay = 1'b0;

        if (!resetN) begin
            PC_update = 1'b1;
            IFID_write = 1'b1;
            IDEX_delay = 1'b0;
        end
        else if (IDEX_memread == 1'b1 && (IDEX_r1 == EXMEM_rd || IDEX_r2 == EXMEM_rd) && !loadInstruction) begin
            PC_update = 1'b0;
            IFID_write = 1'b0;
            IDEX_delay = 1'b1;
        end
        else if (IDEX_memread == 1'b1 && (IDEX_r1 == EXMEM_rd || IDEX_r2 == EXMEM_rd) && loadInstruction) begin
            if (loadCounter < 2'b10) begin
                PC_update = 1'b0;
                IFID_write = 1'b0;
                IDEX_delay = 1'b1;
            end else begin
                PC_update = 1'b1;
                IFID_write = 1'b1;
                IDEX_delay = 1'b0;
            end
        end
    end

    always_ff @(posedge clk or negedge resetN) begin
        if (!resetN) begin
            loadCounter = 2'b0;
        end else if (IDEX_memread == 1'b1 && (IDEX_r1 == EXMEM_rd || IDEX_r2 == EXMEM_rd) && loadInstruction) begin
            if (loadCounter < 2'b10) begin
                loadCounter = loadCounter + 1'b1;
            end else begin
                loadCounter = 2'b0;
            end
        end
    end

endmodule
