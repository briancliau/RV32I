module JALRAddresser (
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
            JALRAddress <= '0;
            JALRCorrection <= 1'b0;
        end else begin
            if (branchCorrectionJALR) begin
                JALRAddress <= aluResult;
                JALRCorrection <= 1'b1;
            end else begin
                JALRAddress <= '0;
                JALRCorrection <= 1'b0;
            end

            if (JALRCorrection) begin
                JALR_pipelineFlush <= 1'b1;
            end else begin
                JALR_pipelineFlush <= 1'b0;
            end
        end
    end
endmodule