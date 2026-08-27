// Packages Utilized
RTL/pkg/rvDefs.sv
RTL/pkg/AHB_pkg.sv

// AHB RTL Files
RTL/AHB_imem_subordinate.sv
RTL/AHB_dmem_subordinate.sv
RTL/AHB_imem_default_subordinate.sv
RTL/AHB_dmem_default_subordinate.sv
RTL/AHB_dmem_interconnect.sv
RTL/AHB_imem_interconnect.sv
RTL/AHB_data_top.sv
RTL/AHB_instruction_top.sv
RTL/AHBDataManager.sv
RTL/AHBInstructionManager.sv

// RV32I RTL Files
RTL/ProgramCounter.sv
RTL/IFID_register.sv
RTL/ImmediateGenerator.sv
RTL/InstructionDecoder.sv
RTL/XRegisterFile.sv
RTL/JALRAddresser.sv
RTL/BranchPredictor.sv
RTL/BranchDecoder.sv
RTL/BranchAddresser.sv
RTL/HazardDetection.sv
RTL/ForwardingUnit.sv
RTL/IDEX_register.sv
RTL/XALU.sv
RTL/EXMEM_register.sv
RTL/LSU.sv
RTL/MEMWB_register.sv
RTL/Core.sv

// SVA and Verification Files
SVA/AHB_lite_checker.sv
SVA/RV32I_core_sva.sv
SVA/RV32I_core_bind.sv
SVA/tb_comprehensive.sv
