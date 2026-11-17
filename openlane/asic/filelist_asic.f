// Packages
RTL/pkg/rvDefs.sv
RTL/pkg/AHB_pkg.sv

// RV32I core RTL
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

// ASIC top + port-exposed AHB-Lite managers
RTL/asic/AHBInstructionManagerPort.sv
RTL/asic/AHBDataManagerPort.sv
RTL/asic/RV32I_core_asic.sv
