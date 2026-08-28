// Packages Utilized
pkg/rvDefs.sv
pkg/AHB_pkg.sv

// AHB RTL Files
AHB_imem_subordinate.sv
AHB_dmem_subordinate.sv
AHB_imem_default_subordinate.sv
AHB_dmem_default_subordinate.sv
AHB_dmem_interconnect.sv
AHB_imem_interconnect.sv
AHB_data_top.sv
AHB_instruction_top.sv
AHBDataManager.sv
AHBInstructionManager.sv

// RV32I RTL Files
ProgramCounter.sv
IFID_register.sv
ImmediateGenerator.sv
InstructionDecoder.sv
XRegisterFile.sv
JALRAddresser.sv
BranchPredictor.sv
BranchDecoder.sv
BranchAddresser.sv
HazardDetection.sv
ForwardingUnit.sv
IDEX_register.sv
XALU.sv
EXMEM_register.sv
LSU.sv
MEMWB_register.sv
Core.sv
RV32I_subsystem.sv
