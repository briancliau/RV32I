// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtb__Syms.h"


VL_ATTR_COLD void Vtb___024root__trace_init_sub__TOP__rvDefs__0(Vtb___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vtb___024root__trace_init_sub__TOP__0(Vtb___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->pushPrefix("rvDefs", VerilatedTracePrefixType::SCOPE_MODULE);
    Vtb___024root__trace_init_sub__TOP__rvDefs__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("tb", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+135,0,"CLK",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"RSTN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"stall",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+25,0,"instruction",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+26,0,"instructionAddress",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+93,0,"memAddress",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+136,0,"memReadData",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+94,0,"memWriteData",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+95,0,"memRead",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+96,0,"memWrite",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+97,0,"memSize",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+3,0,"pass_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+4,0,"fail_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+143,0,"NOP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("dut", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+135,0,"CLK",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"RSTN",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+25,0,"instruction",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+26,0,"instructionAddress",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+93,0,"memAddress",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+136,0,"memReadData",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+94,0,"memWriteData",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+95,0,"memRead",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+96,0,"memWrite",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+97,0,"memSize",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+2,0,"stall",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+6,0,"PC_update",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+7,0,"IFID_write",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+8,0,"IDEX_delay",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+9,0,"ForwardA",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+10,0,"ForwardB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+11,0,"ForwardID_A",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+12,0,"branchPass",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+13,0,"branchTaken_EX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+98,0,"branchPrediction",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+27,0,"jump_EX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+14,0,"pipelineFlush",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+137,0,"branchAddress",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+99,0,"loadPCValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+100,0,"instruction_ID",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+28,0,"instructionAddress_ID",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+101,0,"rs1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+102,0,"rs2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+103,0,"rd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+104,0,"xaluArithmeticFlag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+105,0,"xaluOp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+106,0,"zeroXaluPrimary",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+107,0,"pcXaluPrimary",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+108,0,"immediateXaluSecondary",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+109,0,"memoryOpSize",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+110,0,"unsignedLoad",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+111,0,"storeLoad",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+112,0,"branchOp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+113,0,"branchNegate",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+114,0,"jump",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+115,0,"writeSource",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+116,0,"immediate",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+138,0,"read1Data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+139,0,"read2Data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+29,0,"writeSource_EX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+117,0,"writeEnable_EX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+30,0,"read1Data_EX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+31,0,"read2Data_EX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+32,0,"rs1_EX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+33,0,"rs2_EX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+118,0,"rd_EX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+34,0,"instructionAddress_EX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+35,0,"immediate_EX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+36,0,"xaluOp_EX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+37,0,"xaluArithmeticFlag_EX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+119,0,"memoryOpSize_EX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+38,0,"unsignedLoad_EX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+120,0,"storeLoad_EX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+39,0,"pcXaluPrimary_EX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+40,0,"immediateXaluSecondary_EX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+41,0,"zeroXaluPrimary_EX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+42,0,"branchOp_EX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+43,0,"branchNegate_EX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+27,0,"jump_EX_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+44,0,"instruction_EX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+45,0,"branchPrediction_EX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+121,0,"JALR_flag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+46,0,"JALR_EX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+15,0,"fwd_rs1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+16,0,"fwd_rs2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+140,0,"branchTargetJALR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+17,0,"xalu_primary",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+18,0,"xalu_secondary",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+19,0,"aluResult",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+47,0,"opcodeBranchResolution",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBit(c+20,0,"branchCorrection",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+21,0,"branchCorrectionAddress",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+22,0,"branchMispredicted_EX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+48,0,"writeSource_MEM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+122,0,"writeEnable_MEM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+123,0,"rd_MEM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+124,0,"memoryOpSize_MEM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+49,0,"unsignedLoad_MEM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+125,0,"storeLoad_MEM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+93,0,"address_MEM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+50,0,"instructionAddress_MEM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+144,0,"memWriteData_MEM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+141,0,"memToRegData",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+126,0,"writeEnable_WB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+51,0,"address_WB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+127,0,"rd_WB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+52,0,"memToRegData_WB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+53,0,"instructionAddress_WB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+54,0,"writeSource_WB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+128,0,"registerWriteData",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("EXMEM_stage", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+135,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"resetN",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+119,0,"memoryOpSize_EX",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+38,0,"unsignedLoad_EX",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+120,0,"storeLoad_EX",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+19,0,"address_EX",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+118,0,"rd_EX",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+117,0,"writeEnable_EX",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+29,0,"writeSource_EX",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+34,0,"instructionAddress_EX",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+16,0,"memWriteData_EX",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+94,0,"memWriteData_MEM",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+50,0,"instructionAddress_MEM",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+48,0,"writeSource_MEM",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+122,0,"writeEnable_MEM",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+123,0,"rd_MEM",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+124,0,"memoryOpSize_MEM",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+49,0,"unsignedLoad_MEM",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+125,0,"storeLoad_MEM",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+93,0,"address_MEM",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("IDEX_stage", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+135,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"resetN",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+14,0,"flush",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+8,0,"IDEX_delay",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+138,0,"read1Data_ID",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+139,0,"read2Data_ID",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+101,0,"rs1_ID",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+102,0,"rs2_ID",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+103,0,"rd_ID",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+28,0,"instructionAddress_ID",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+116,0,"immediate_ID",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+105,0,"xaluOp_ID",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+104,0,"xaluArithmeticFlag_ID",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+109,0,"memoryOpSize_ID",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+110,0,"unsignedLoad_ID",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+111,0,"storeLoad_ID",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+129,0,"writeEnable_ID",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+115,0,"writeSource_ID",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+107,0,"pcXaluPrimary_ID",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+108,0,"immediateXaluSecondary_ID",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+106,0,"zeroXaluPrimary_ID",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+112,0,"branchOp_ID",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+113,0,"branchNegate_ID",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+100,0,"instruction_ID",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+114,0,"jump_ID",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+121,0,"JALR_ID",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+98,0,"branchPrediction_ID",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+45,0,"branchPrediction_EX",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+46,0,"JALR_EX",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+42,0,"branchOp_EX",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+43,0,"branchNegate_EX",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+27,0,"jump_EX",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+41,0,"zeroXaluPrimary_EX",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+40,0,"immediateXaluSecondary_EX",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+29,0,"writeSource_EX",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+117,0,"writeEnable_EX",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+30,0,"read1Data_EX",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+31,0,"read2Data_EX",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+32,0,"rs1_EX",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+33,0,"rs2_EX",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+118,0,"rd_EX",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+34,0,"instructionAddress_EX",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+35,0,"immediate_EX",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+36,0,"xaluOp_EX",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+37,0,"xaluArithmeticFlag_EX",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+119,0,"memoryOpSize_EX",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+38,0,"unsignedLoad_EX",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+120,0,"storeLoad_EX",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+39,0,"pcXaluPrimary_EX",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+44,0,"instruction_EX",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("IFID_stage", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+135,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"resetN",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+7,0,"IFID_write",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+14,0,"flush",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+26,0,"instructionAddress_IF",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+25,0,"instruction_IF",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+100,0,"instruction_ID",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+28,0,"instructionAddress_ID",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("MEMWB_stage", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+135,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"resetN",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+123,0,"rd_MEM",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+93,0,"address_MEM",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+122,0,"writeEnable_MEM",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+141,0,"memToRegData_MEM",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+48,0,"writeSource_MEM",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+50,0,"instructionAddress_MEM",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+53,0,"instructionAddress_WB",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+54,0,"writeSource_WB",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+126,0,"writeEnable_WB",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+51,0,"address_WB",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+127,0,"rd_WB",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+52,0,"memToRegData_WB",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("branchAddresser", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+28,0,"PCAddress",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+116,0,"offset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+140,0,"branchTargetJALR",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+130,0,"opcode",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+137,0,"BranchAddress",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("branchPredictor", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+135,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"resetN",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+13,0,"branchTaken",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+131,0,"branchRequested",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+98,0,"branchPrediction",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+55,0,"saturationCounter",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+56,0,"req_delay1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+57,0,"req_delay2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+58,0,"branchTaken_delay1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("forwardingUnit", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+1,0,"resetN",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+32,0,"rs1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+33,0,"rs2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+123,0,"EXMEM_rd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+122,0,"EXMEM_RegWrite",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+127,0,"MEMWB_rd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+126,0,"MEMWB_RegWrite",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+101,0,"ID_rs1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+9,0,"ForwardA",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+10,0,"ForwardB",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+11,0,"ForwardID_A",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->popPrefix();
    tracep->pushPrefix("hazardDetection", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+135,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"resetN",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+101,0,"IDEX_r1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+102,0,"IDEX_r2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+118,0,"EXMEM_rd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+132,0,"IDEX_memread",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+25,0,"instruction_IF",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+6,0,"PC_update",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+7,0,"IFID_write",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+8,0,"IDEX_delay",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+59,0,"loadCounter",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+60,0,"loadInstruction",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+61,0,"opcode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->popPrefix();
    tracep->pushPrefix("immediateGenerator", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+100,0,"instruction",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+116,0,"immediate",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+130,0,"opcode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->popPrefix();
    tracep->pushPrefix("instructionDecoder", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+100,0,"instruction",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+101,0,"rs1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+102,0,"rs2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+103,0,"rd",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+104,0,"xaluArithmeticFlag",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+105,0,"xaluOp",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+106,0,"zeroXaluPrimary",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+107,0,"pcXaluPrimary",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+108,0,"immediateXaluSecondary",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+109,0,"memoryOpSize",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+110,0,"unsignedLoad",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+111,0,"storeLoad",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+112,0,"branchOp",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+113,0,"branchNegate",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+114,0,"jump",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+121,0,"JALR",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+115,0,"writeSource",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+130,0,"opcode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+133,0,"funct3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+134,0,"funct7_5",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("lsu", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+124,0,"memoryOpSize",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+49,0,"unsignedLoad",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+125,0,"storeLoad",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+93,0,"address",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+136,0,"readData",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+96,0,"memWrite",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+95,0,"memRead",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+97,0,"memSize",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+141,0,"memToRegData",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("programCounter", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+145,0,"RESET_VALUE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+135,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"resetN",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+23,0,"enable",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+99,0,"branchPrediction",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+20,0,"branchCorrection",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+137,0,"addrLoad",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+21,0,"branchCorrectionLoad",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+26,0,"addrOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+146,0,"INCREMENT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+142,0,"addrNext",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("xAlu", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+17,0,"inputPrimary",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+18,0,"inputSecondary",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+36,0,"operation",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+37,0,"arithmeticFlag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+19,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+24,0,"shamt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->popPrefix();
    tracep->pushPrefix("xRegisterFile", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+135,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+126,0,"writeEnable",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+101,0,"read1Reg",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+102,0,"read2Reg",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+127,0,"writeReg",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+128,0,"writeData",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+138,0,"read1Data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+139,0,"read2Data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("registers", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 31; ++i) {
        tracep->declBus(c+62+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+1), 31,0);
    }
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+5,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vtb___024root__trace_init_sub__TOP__rvDefs__0(Vtb___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root__trace_init_sub__TOP__rvDefs__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+147,0,"XLEN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+147,0,"XREG_COUNT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+147,0,"IALIGN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+147,0,"ILEN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+148,0,"BYTE_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+149,0,"HALFWORD_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+147,0,"WORD_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
}

VL_ATTR_COLD void Vtb___024root__trace_init_top(Vtb___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root__trace_init_top\n"); );
    // Body
    Vtb___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vtb___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vtb___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtb___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtb___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vtb___024root__trace_register(Vtb___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root__trace_register\n"); );
    // Body
    tracep->addConstCb(&Vtb___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vtb___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vtb___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vtb___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtb___024root__trace_const_0_sub_0(Vtb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtb___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root__trace_const_0\n"); );
    // Init
    Vtb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb___024root*>(voidSelf);
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtb___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtb___024root__trace_const_0_sub_0(Vtb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root__trace_const_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+143,(0x13U),32);
    bufp->fullIData(oldp+144,(vlSelf->tb__DOT__dut__DOT__memWriteData_MEM),32);
    bufp->fullIData(oldp+145,(0U),32);
    bufp->fullIData(oldp+146,(4U),32);
    bufp->fullIData(oldp+147,(0x20U),32);
    bufp->fullIData(oldp+148,(8U),32);
    bufp->fullIData(oldp+149,(0x10U),32);
}

VL_ATTR_COLD void Vtb___024root__trace_full_0_sub_0(Vtb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtb___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root__trace_full_0\n"); );
    // Init
    Vtb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb___024root*>(voidSelf);
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtb___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtb___024root__trace_full_0_sub_0(Vtb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root__trace_full_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSelf->tb__DOT__RSTN));
    bufp->fullBit(oldp+2,(vlSelf->tb__DOT__stall));
    bufp->fullIData(oldp+3,(vlSelf->tb__DOT__pass_count),32);
    bufp->fullIData(oldp+4,(vlSelf->tb__DOT__fail_count),32);
    bufp->fullIData(oldp+5,(vlSelf->tb__DOT__unnamedblk1__DOT__i),32);
    bufp->fullBit(oldp+6,(vlSelf->tb__DOT__dut__DOT__PC_update));
    bufp->fullBit(oldp+7,(vlSelf->tb__DOT__dut__DOT__IFID_write));
    bufp->fullBit(oldp+8,(vlSelf->tb__DOT__dut__DOT__IDEX_delay));
    bufp->fullCData(oldp+9,(vlSelf->tb__DOT__dut__DOT__ForwardA),2);
    bufp->fullCData(oldp+10,(vlSelf->tb__DOT__dut__DOT__ForwardB),2);
    bufp->fullCData(oldp+11,(vlSelf->tb__DOT__dut__DOT__ForwardID_A),2);
    bufp->fullBit(oldp+12,(vlSelf->tb__DOT__dut__DOT__branchPass));
    bufp->fullBit(oldp+13,(vlSelf->tb__DOT__dut__DOT__branchTaken_EX));
    bufp->fullBit(oldp+14,(vlSelf->tb__DOT__dut__DOT__pipelineFlush));
    bufp->fullIData(oldp+15,(vlSelf->tb__DOT__dut__DOT__fwd_rs1),32);
    bufp->fullIData(oldp+16,(vlSelf->tb__DOT__dut__DOT__fwd_rs2),32);
    bufp->fullIData(oldp+17,(vlSelf->tb__DOT__dut__DOT__xalu_primary),32);
    bufp->fullIData(oldp+18,(vlSelf->tb__DOT__dut__DOT__xalu_secondary),32);
    bufp->fullIData(oldp+19,(vlSelf->tb__DOT__dut__DOT__aluResult),32);
    bufp->fullBit(oldp+20,(vlSelf->tb__DOT__dut__DOT__branchCorrection));
    bufp->fullIData(oldp+21,(vlSelf->tb__DOT__dut__DOT__branchCorrectionAddress),32);
    bufp->fullBit(oldp+22,(vlSelf->tb__DOT__dut__DOT__branchMispredicted_EX));
    bufp->fullBit(oldp+23,(((IData)(vlSelf->tb__DOT__dut__DOT__IFID_write) 
                            & (IData)(vlSelf->tb__DOT__dut__DOT__PC_update))));
    bufp->fullCData(oldp+24,((0x1fU & vlSelf->tb__DOT__dut__DOT__xalu_secondary)),5);
    bufp->fullIData(oldp+25,(vlSelf->tb__DOT__dut__DOT____Vcellinp__IFID_stage__instruction_IF),32);
    bufp->fullIData(oldp+26,(vlSelf->tb__DOT__instructionAddress),32);
    bufp->fullBit(oldp+27,(vlSelf->tb__DOT__dut__DOT__jump_EX_reg));
    bufp->fullIData(oldp+28,(vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instructionAddress_ID),32);
    bufp->fullCData(oldp+29,(vlSelf->tb__DOT__dut__DOT__writeSource_EX),2);
    bufp->fullIData(oldp+30,(vlSelf->tb__DOT__dut__DOT__read1Data_EX),32);
    bufp->fullIData(oldp+31,(vlSelf->tb__DOT__dut__DOT__read2Data_EX),32);
    bufp->fullCData(oldp+32,(vlSelf->tb__DOT__dut__DOT__rs1_EX),5);
    bufp->fullCData(oldp+33,(vlSelf->tb__DOT__dut__DOT__rs2_EX),5);
    bufp->fullIData(oldp+34,(vlSelf->tb__DOT__dut__DOT__instructionAddress_EX),32);
    bufp->fullIData(oldp+35,(vlSelf->tb__DOT__dut__DOT__immediate_EX),32);
    bufp->fullCData(oldp+36,(vlSelf->tb__DOT__dut__DOT__xaluOp_EX),3);
    bufp->fullBit(oldp+37,(vlSelf->tb__DOT__dut__DOT__xaluArithmeticFlag_EX));
    bufp->fullBit(oldp+38,(vlSelf->tb__DOT__dut__DOT__unsignedLoad_EX));
    bufp->fullBit(oldp+39,(vlSelf->tb__DOT__dut__DOT__pcXaluPrimary_EX));
    bufp->fullBit(oldp+40,(vlSelf->tb__DOT__dut__DOT__immediateXaluSecondary_EX));
    bufp->fullBit(oldp+41,(vlSelf->tb__DOT__dut__DOT__zeroXaluPrimary_EX));
    bufp->fullCData(oldp+42,(vlSelf->tb__DOT__dut__DOT__branchOp_EX),2);
    bufp->fullBit(oldp+43,(vlSelf->tb__DOT__dut__DOT__branchNegate_EX));
    bufp->fullIData(oldp+44,(vlSelf->tb__DOT__dut__DOT____Vcellout__IDEX_stage__instruction_EX),32);
    bufp->fullBit(oldp+45,(vlSelf->tb__DOT__dut__DOT__branchPrediction_EX));
    bufp->fullBit(oldp+46,(vlSelf->tb__DOT__dut__DOT__JALR_EX));
    bufp->fullCData(oldp+47,((0x7fU & vlSelf->tb__DOT__dut__DOT____Vcellout__IDEX_stage__instruction_EX)),7);
    bufp->fullCData(oldp+48,(vlSelf->tb__DOT__dut__DOT__writeSource_MEM),2);
    bufp->fullBit(oldp+49,(vlSelf->tb__DOT__dut__DOT__unsignedLoad_MEM));
    bufp->fullIData(oldp+50,(vlSelf->tb__DOT__dut__DOT__instructionAddress_MEM),32);
    bufp->fullIData(oldp+51,(vlSelf->tb__DOT__dut__DOT__address_WB),32);
    bufp->fullIData(oldp+52,(vlSelf->tb__DOT__dut__DOT__memToRegData_WB),32);
    bufp->fullIData(oldp+53,(vlSelf->tb__DOT__dut__DOT__instructionAddress_WB),32);
    bufp->fullCData(oldp+54,(vlSelf->tb__DOT__dut__DOT__writeSource_WB),2);
    bufp->fullCData(oldp+55,(vlSelf->tb__DOT__dut__DOT__branchPredictor__DOT__saturationCounter),2);
    bufp->fullBit(oldp+56,(vlSelf->tb__DOT__dut__DOT__branchPredictor__DOT__req_delay1));
    bufp->fullBit(oldp+57,(vlSelf->tb__DOT__dut__DOT__branchPredictor__DOT__req_delay2));
    bufp->fullBit(oldp+58,(vlSelf->tb__DOT__dut__DOT__branchPredictor__DOT__branchTaken_delay1));
    bufp->fullCData(oldp+59,(vlSelf->tb__DOT__dut__DOT__hazardDetection__DOT__loadCounter),2);
    bufp->fullBit(oldp+60,((3U == (0x7fU & vlSelf->tb__DOT__dut__DOT____Vcellinp__IFID_stage__instruction_IF))));
    bufp->fullCData(oldp+61,((0x7fU & vlSelf->tb__DOT__dut__DOT____Vcellinp__IFID_stage__instruction_IF)),7);
    bufp->fullIData(oldp+62,(vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers[0]),32);
    bufp->fullIData(oldp+63,(vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers[1]),32);
    bufp->fullIData(oldp+64,(vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers[2]),32);
    bufp->fullIData(oldp+65,(vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers[3]),32);
    bufp->fullIData(oldp+66,(vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers[4]),32);
    bufp->fullIData(oldp+67,(vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers[5]),32);
    bufp->fullIData(oldp+68,(vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers[6]),32);
    bufp->fullIData(oldp+69,(vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers[7]),32);
    bufp->fullIData(oldp+70,(vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers[8]),32);
    bufp->fullIData(oldp+71,(vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers[9]),32);
    bufp->fullIData(oldp+72,(vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers[10]),32);
    bufp->fullIData(oldp+73,(vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers[11]),32);
    bufp->fullIData(oldp+74,(vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers[12]),32);
    bufp->fullIData(oldp+75,(vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers[13]),32);
    bufp->fullIData(oldp+76,(vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers[14]),32);
    bufp->fullIData(oldp+77,(vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers[15]),32);
    bufp->fullIData(oldp+78,(vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers[16]),32);
    bufp->fullIData(oldp+79,(vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers[17]),32);
    bufp->fullIData(oldp+80,(vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers[18]),32);
    bufp->fullIData(oldp+81,(vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers[19]),32);
    bufp->fullIData(oldp+82,(vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers[20]),32);
    bufp->fullIData(oldp+83,(vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers[21]),32);
    bufp->fullIData(oldp+84,(vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers[22]),32);
    bufp->fullIData(oldp+85,(vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers[23]),32);
    bufp->fullIData(oldp+86,(vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers[24]),32);
    bufp->fullIData(oldp+87,(vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers[25]),32);
    bufp->fullIData(oldp+88,(vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers[26]),32);
    bufp->fullIData(oldp+89,(vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers[27]),32);
    bufp->fullIData(oldp+90,(vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers[28]),32);
    bufp->fullIData(oldp+91,(vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers[29]),32);
    bufp->fullIData(oldp+92,(vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers[30]),32);
    bufp->fullIData(oldp+93,(vlSelf->tb__DOT__dut__DOT__address_MEM),32);
    bufp->fullIData(oldp+94,(vlSelf->tb__DOT__dut__DOT____Vcellout__EXMEM_stage__memWriteData_MEM),32);
    bufp->fullBit(oldp+95,(((~ (IData)(vlSelf->tb__DOT__dut__DOT__storeLoad_MEM)) 
                            & (3U != (IData)(vlSelf->tb__DOT__dut__DOT__memoryOpSize_MEM)))));
    bufp->fullBit(oldp+96,(((3U != (IData)(vlSelf->tb__DOT__dut__DOT__memoryOpSize_MEM)) 
                            & (IData)(vlSelf->tb__DOT__dut__DOT__storeLoad_MEM))));
    bufp->fullCData(oldp+97,(((0U == (IData)(vlSelf->tb__DOT__dut__DOT__memoryOpSize_MEM))
                               ? 0U : ((1U == (IData)(vlSelf->tb__DOT__dut__DOT__memoryOpSize_MEM))
                                        ? 1U : ((2U 
                                                 == (IData)(vlSelf->tb__DOT__dut__DOT__memoryOpSize_MEM))
                                                 ? 2U
                                                 : 7U)))),3);
    bufp->fullBit(oldp+98,(vlSelf->tb__DOT__dut__DOT__branchPrediction));
    bufp->fullBit(oldp+99,((((0x67U != (0x7fU & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)) 
                             & (IData)(vlSelf->tb__DOT__dut__DOT__jump)) 
                            | (IData)(vlSelf->tb__DOT__dut__DOT__branchPrediction))));
    bufp->fullIData(oldp+100,(vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID),32);
    bufp->fullCData(oldp+101,((0x1fU & (vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID 
                                        >> 0xfU))),5);
    bufp->fullCData(oldp+102,((0x1fU & (vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID 
                                        >> 0x14U))),5);
    bufp->fullCData(oldp+103,((0x1fU & (vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID 
                                        >> 7U))),5);
    bufp->fullBit(oldp+104,((((0x33U == (0x7fU & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)) 
                              | (IData)((0x5013U == 
                                         (0x707fU & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)))) 
                             & (vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID 
                                >> 0x1eU))));
    bufp->fullCData(oldp+105,((((0x13U == (0x7fU & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)) 
                                || (0x33U == (0x7fU 
                                              & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)))
                                ? (7U & (vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID 
                                         >> 0xcU)) : 0U)),3);
    bufp->fullBit(oldp+106,((0x37U == (0x7fU & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID))));
    bufp->fullBit(oldp+107,(((0x17U == (0x7fU & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)) 
                             | ((0x6fU == (0x7fU & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)) 
                                | (0x63U == (0x7fU 
                                             & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID))))));
    bufp->fullBit(oldp+108,(((0x37U == (0x7fU & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)) 
                             | ((0x17U == (0x7fU & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)) 
                                | ((0x6fU == (0x7fU 
                                              & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)) 
                                   | ((0x67U == (0x7fU 
                                                 & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)) 
                                      | ((0x63U == 
                                          (0x7fU & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)) 
                                         | ((3U == 
                                             (0x7fU 
                                              & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)) 
                                            | ((0x23U 
                                                == 
                                                (0x7fU 
                                                 & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)) 
                                               | (0x13U 
                                                  == 
                                                  (0x7fU 
                                                   & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)))))))))));
    bufp->fullCData(oldp+109,((((3U == (0x7fU & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)) 
                                | (0x23U == (0x7fU 
                                             & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)))
                                ? (3U & (vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID 
                                         >> 0xcU)) : 3U)),2);
    bufp->fullBit(oldp+110,((1U & (vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID 
                                   >> 0xeU))));
    bufp->fullBit(oldp+111,((0x23U == (0x7fU & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID))));
    bufp->fullCData(oldp+112,(vlSelf->tb__DOT__dut__DOT__branchOp),2);
    bufp->fullBit(oldp+113,((1U & (vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID 
                                   >> 0xcU))));
    bufp->fullBit(oldp+114,(vlSelf->tb__DOT__dut__DOT__jump));
    bufp->fullCData(oldp+115,(vlSelf->tb__DOT__dut__DOT__writeSource),2);
    bufp->fullIData(oldp+116,(vlSelf->tb__DOT__dut__DOT__immediate),32);
    bufp->fullBit(oldp+117,(vlSelf->tb__DOT__dut__DOT__writeEnable_EX));
    bufp->fullCData(oldp+118,(vlSelf->tb__DOT__dut__DOT__rd_EX),5);
    bufp->fullCData(oldp+119,(vlSelf->tb__DOT__dut__DOT__memoryOpSize_EX),2);
    bufp->fullBit(oldp+120,(vlSelf->tb__DOT__dut__DOT__storeLoad_EX));
    bufp->fullBit(oldp+121,((0x67U == (0x7fU & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID))));
    bufp->fullBit(oldp+122,(vlSelf->tb__DOT__dut__DOT__writeEnable_MEM));
    bufp->fullCData(oldp+123,(vlSelf->tb__DOT__dut__DOT__rd_MEM),5);
    bufp->fullCData(oldp+124,(vlSelf->tb__DOT__dut__DOT__memoryOpSize_MEM),2);
    bufp->fullBit(oldp+125,(vlSelf->tb__DOT__dut__DOT__storeLoad_MEM));
    bufp->fullBit(oldp+126,(vlSelf->tb__DOT__dut__DOT__writeEnable_WB));
    bufp->fullCData(oldp+127,(vlSelf->tb__DOT__dut__DOT__rd_WB),5);
    bufp->fullIData(oldp+128,(vlSelf->tb__DOT__dut__DOT__registerWriteData),32);
    bufp->fullBit(oldp+129,((0U != (IData)(vlSelf->tb__DOT__dut__DOT__writeSource))));
    bufp->fullCData(oldp+130,((0x7fU & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)),7);
    bufp->fullBit(oldp+131,((1U != (IData)(vlSelf->tb__DOT__dut__DOT__branchOp))));
    bufp->fullBit(oldp+132,(vlSelf->tb__DOT__dut__DOT____Vcellinp__hazardDetection__IDEX_memread));
    bufp->fullCData(oldp+133,((7U & (vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID 
                                     >> 0xcU))),3);
    bufp->fullBit(oldp+134,((1U & (vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID 
                                   >> 0x1eU))));
    bufp->fullBit(oldp+135,(vlSelf->tb__DOT__CLK));
    bufp->fullIData(oldp+136,(vlSelf->tb__DOT__memReadData),32);
    bufp->fullIData(oldp+137,(((0x6fU == (0x7fU & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID))
                                ? (vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instructionAddress_ID 
                                   + vlSelf->tb__DOT__dut__DOT__immediate)
                                : ((0x63U == (0x7fU 
                                              & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID))
                                    ? (vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instructionAddress_ID 
                                       + vlSelf->tb__DOT__dut__DOT__immediate)
                                    : 0U))),32);
    bufp->fullIData(oldp+138,(vlSelf->tb__DOT__dut__DOT__read1Data),32);
    bufp->fullIData(oldp+139,(((0U == (0x1fU & (vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID 
                                                >> 0x14U)))
                                ? 0U : ((0x1eU >= (0x1fU 
                                                   & ((vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID 
                                                       >> 0x14U) 
                                                      - (IData)(1U))))
                                         ? vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers
                                        [(0x1fU & (
                                                   (vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID 
                                                    >> 0x14U) 
                                                   - (IData)(1U)))]
                                         : 0U))),32);
    bufp->fullIData(oldp+140,(((2U == (IData)(vlSelf->tb__DOT__dut__DOT__ForwardID_A))
                                ? vlSelf->tb__DOT__dut__DOT__address_MEM
                                : ((1U == (IData)(vlSelf->tb__DOT__dut__DOT__ForwardID_A))
                                    ? vlSelf->tb__DOT__dut__DOT__registerWriteData
                                    : vlSelf->tb__DOT__dut__DOT__read1Data))),32);
    bufp->fullIData(oldp+141,(((0U == (IData)(vlSelf->tb__DOT__dut__DOT__memoryOpSize_MEM))
                                ? ((((IData)(vlSelf->tb__DOT__dut__DOT__unsignedLoad_MEM)
                                      ? 0U : (0xffffffU 
                                              & (- (IData)(
                                                           (1U 
                                                            & (VL_SHIFTR_III(32,32,32, vlSelf->tb__DOT__memReadData, 
                                                                             VL_SHIFTL_III(32,32,32, 
                                                                                (3U 
                                                                                & vlSelf->tb__DOT__dut__DOT__address_MEM), 3U)) 
                                                               >> 7U)))))) 
                                    << 8U) | (0xffU 
                                              & VL_SHIFTR_III(8,32,32, vlSelf->tb__DOT__memReadData, 
                                                              VL_SHIFTL_III(32,32,32, 
                                                                            (3U 
                                                                             & vlSelf->tb__DOT__dut__DOT__address_MEM), 3U))))
                                : ((1U == (IData)(vlSelf->tb__DOT__dut__DOT__memoryOpSize_MEM))
                                    ? ((((IData)(vlSelf->tb__DOT__dut__DOT__unsignedLoad_MEM)
                                          ? 0U : (0xffffU 
                                                  & (- (IData)(
                                                               (1U 
                                                                & (VL_SHIFTR_III(32,32,32, vlSelf->tb__DOT__memReadData, 
                                                                                VL_SHIFTL_III(32,32,32, 
                                                                                (1U 
                                                                                & (vlSelf->tb__DOT__dut__DOT__address_MEM 
                                                                                >> 1U)), 4U)) 
                                                                   >> 0xfU)))))) 
                                        << 0x10U) | 
                                       (0xffffU & VL_SHIFTR_III(16,32,32, vlSelf->tb__DOT__memReadData, 
                                                                VL_SHIFTL_III(32,32,32, 
                                                                              (1U 
                                                                               & (vlSelf->tb__DOT__dut__DOT__address_MEM 
                                                                                >> 1U)), 4U))))
                                    : ((2U == (IData)(vlSelf->tb__DOT__dut__DOT__memoryOpSize_MEM))
                                        ? vlSelf->tb__DOT__memReadData
                                        : 0U)))),32);
    bufp->fullIData(oldp+142,(((((0x67U != (0x7fU & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)) 
                                 & (IData)(vlSelf->tb__DOT__dut__DOT__jump)) 
                                | (IData)(vlSelf->tb__DOT__dut__DOT__branchPrediction))
                                ? ((0x6fU == (0x7fU 
                                              & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID))
                                    ? (vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instructionAddress_ID 
                                       + vlSelf->tb__DOT__dut__DOT__immediate)
                                    : ((0x63U == (0x7fU 
                                                  & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID))
                                        ? (vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instructionAddress_ID 
                                           + vlSelf->tb__DOT__dut__DOT__immediate)
                                        : 0U)) : ((IData)(vlSelf->tb__DOT__dut__DOT__branchCorrection)
                                                   ? vlSelf->tb__DOT__dut__DOT__branchCorrectionAddress
                                                   : 
                                                  ((IData)(4U) 
                                                   + vlSelf->tb__DOT__instructionAddress)))),32);
}
