// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtb__Syms.h"


void Vtb___024root__trace_chg_0_sub_0(Vtb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtb___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root__trace_chg_0\n"); );
    // Init
    Vtb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb___024root*>(voidSelf);
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtb___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtb___024root__trace_chg_0_sub_0(Vtb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[1U] 
                     | vlSelf->__Vm_traceActivity[2U]))) {
        bufp->chgBit(oldp+0,(vlSelf->tb__DOT__RSTN));
        bufp->chgBit(oldp+1,(vlSelf->tb__DOT__stall));
        bufp->chgIData(oldp+2,(vlSelf->tb__DOT__pass_count),32);
        bufp->chgIData(oldp+3,(vlSelf->tb__DOT__fail_count),32);
        bufp->chgIData(oldp+4,(vlSelf->tb__DOT__unnamedblk1__DOT__i),32);
    }
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[3U] 
                     | vlSelf->__Vm_traceActivity[7U]))) {
        bufp->chgBit(oldp+5,(vlSelf->tb__DOT__dut__DOT__PC_update));
        bufp->chgBit(oldp+6,(vlSelf->tb__DOT__dut__DOT__IFID_write));
        bufp->chgBit(oldp+7,(vlSelf->tb__DOT__dut__DOT__IDEX_delay));
        bufp->chgCData(oldp+8,(vlSelf->tb__DOT__dut__DOT__ForwardA),2);
        bufp->chgCData(oldp+9,(vlSelf->tb__DOT__dut__DOT__ForwardB),2);
        bufp->chgCData(oldp+10,(vlSelf->tb__DOT__dut__DOT__ForwardID_A),2);
        bufp->chgBit(oldp+11,(vlSelf->tb__DOT__dut__DOT__branchPass));
        bufp->chgBit(oldp+12,(vlSelf->tb__DOT__dut__DOT__branchTaken_EX));
        bufp->chgBit(oldp+13,(vlSelf->tb__DOT__dut__DOT__pipelineFlush));
        bufp->chgIData(oldp+14,(vlSelf->tb__DOT__dut__DOT__fwd_rs1),32);
        bufp->chgIData(oldp+15,(vlSelf->tb__DOT__dut__DOT__fwd_rs2),32);
        bufp->chgIData(oldp+16,(vlSelf->tb__DOT__dut__DOT__xalu_primary),32);
        bufp->chgIData(oldp+17,(vlSelf->tb__DOT__dut__DOT__xalu_secondary),32);
        bufp->chgIData(oldp+18,(vlSelf->tb__DOT__dut__DOT__aluResult),32);
        bufp->chgBit(oldp+19,(vlSelf->tb__DOT__dut__DOT__branchCorrection));
        bufp->chgIData(oldp+20,(vlSelf->tb__DOT__dut__DOT__branchCorrectionAddress),32);
        bufp->chgBit(oldp+21,(vlSelf->tb__DOT__dut__DOT__branchMispredicted_EX));
        bufp->chgBit(oldp+22,(((IData)(vlSelf->tb__DOT__dut__DOT__IFID_write) 
                               & (IData)(vlSelf->tb__DOT__dut__DOT__PC_update))));
        bufp->chgCData(oldp+23,((0x1fU & vlSelf->tb__DOT__dut__DOT__xalu_secondary)),5);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[4U])) {
        bufp->chgIData(oldp+24,(vlSelf->tb__DOT__dut__DOT____Vcellinp__IFID_stage__instruction_IF),32);
        bufp->chgIData(oldp+25,(vlSelf->tb__DOT__instructionAddress),32);
        bufp->chgBit(oldp+26,(vlSelf->tb__DOT__dut__DOT__jump_EX_reg));
        bufp->chgIData(oldp+27,(vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instructionAddress_ID),32);
        bufp->chgCData(oldp+28,(vlSelf->tb__DOT__dut__DOT__writeSource_EX),2);
        bufp->chgIData(oldp+29,(vlSelf->tb__DOT__dut__DOT__read1Data_EX),32);
        bufp->chgIData(oldp+30,(vlSelf->tb__DOT__dut__DOT__read2Data_EX),32);
        bufp->chgCData(oldp+31,(vlSelf->tb__DOT__dut__DOT__rs1_EX),5);
        bufp->chgCData(oldp+32,(vlSelf->tb__DOT__dut__DOT__rs2_EX),5);
        bufp->chgIData(oldp+33,(vlSelf->tb__DOT__dut__DOT__instructionAddress_EX),32);
        bufp->chgIData(oldp+34,(vlSelf->tb__DOT__dut__DOT__immediate_EX),32);
        bufp->chgCData(oldp+35,(vlSelf->tb__DOT__dut__DOT__xaluOp_EX),3);
        bufp->chgBit(oldp+36,(vlSelf->tb__DOT__dut__DOT__xaluArithmeticFlag_EX));
        bufp->chgBit(oldp+37,(vlSelf->tb__DOT__dut__DOT__unsignedLoad_EX));
        bufp->chgBit(oldp+38,(vlSelf->tb__DOT__dut__DOT__pcXaluPrimary_EX));
        bufp->chgBit(oldp+39,(vlSelf->tb__DOT__dut__DOT__immediateXaluSecondary_EX));
        bufp->chgBit(oldp+40,(vlSelf->tb__DOT__dut__DOT__zeroXaluPrimary_EX));
        bufp->chgCData(oldp+41,(vlSelf->tb__DOT__dut__DOT__branchOp_EX),2);
        bufp->chgBit(oldp+42,(vlSelf->tb__DOT__dut__DOT__branchNegate_EX));
        bufp->chgIData(oldp+43,(vlSelf->tb__DOT__dut__DOT____Vcellout__IDEX_stage__instruction_EX),32);
        bufp->chgBit(oldp+44,(vlSelf->tb__DOT__dut__DOT__branchPrediction_EX));
        bufp->chgBit(oldp+45,(vlSelf->tb__DOT__dut__DOT__JALR_EX));
        bufp->chgCData(oldp+46,((0x7fU & vlSelf->tb__DOT__dut__DOT____Vcellout__IDEX_stage__instruction_EX)),7);
        bufp->chgCData(oldp+47,(vlSelf->tb__DOT__dut__DOT__writeSource_MEM),2);
        bufp->chgBit(oldp+48,(vlSelf->tb__DOT__dut__DOT__unsignedLoad_MEM));
        bufp->chgIData(oldp+49,(vlSelf->tb__DOT__dut__DOT__instructionAddress_MEM),32);
        bufp->chgIData(oldp+50,(vlSelf->tb__DOT__dut__DOT__address_WB),32);
        bufp->chgIData(oldp+51,(vlSelf->tb__DOT__dut__DOT__memToRegData_WB),32);
        bufp->chgIData(oldp+52,(vlSelf->tb__DOT__dut__DOT__instructionAddress_WB),32);
        bufp->chgCData(oldp+53,(vlSelf->tb__DOT__dut__DOT__writeSource_WB),2);
        bufp->chgCData(oldp+54,(vlSelf->tb__DOT__dut__DOT__branchPredictor__DOT__saturationCounter),2);
        bufp->chgBit(oldp+55,(vlSelf->tb__DOT__dut__DOT__branchPredictor__DOT__req_delay1));
        bufp->chgBit(oldp+56,(vlSelf->tb__DOT__dut__DOT__branchPredictor__DOT__req_delay2));
        bufp->chgBit(oldp+57,(vlSelf->tb__DOT__dut__DOT__branchPredictor__DOT__branchTaken_delay1));
        bufp->chgCData(oldp+58,(vlSelf->tb__DOT__dut__DOT__hazardDetection__DOT__loadCounter),2);
        bufp->chgBit(oldp+59,((3U == (0x7fU & vlSelf->tb__DOT__dut__DOT____Vcellinp__IFID_stage__instruction_IF))));
        bufp->chgCData(oldp+60,((0x7fU & vlSelf->tb__DOT__dut__DOT____Vcellinp__IFID_stage__instruction_IF)),7);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[5U])) {
        bufp->chgIData(oldp+61,(vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers[0]),32);
        bufp->chgIData(oldp+62,(vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers[1]),32);
        bufp->chgIData(oldp+63,(vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers[2]),32);
        bufp->chgIData(oldp+64,(vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers[3]),32);
        bufp->chgIData(oldp+65,(vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers[4]),32);
        bufp->chgIData(oldp+66,(vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers[5]),32);
        bufp->chgIData(oldp+67,(vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers[6]),32);
        bufp->chgIData(oldp+68,(vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers[7]),32);
        bufp->chgIData(oldp+69,(vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers[8]),32);
        bufp->chgIData(oldp+70,(vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers[9]),32);
        bufp->chgIData(oldp+71,(vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers[10]),32);
        bufp->chgIData(oldp+72,(vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers[11]),32);
        bufp->chgIData(oldp+73,(vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers[12]),32);
        bufp->chgIData(oldp+74,(vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers[13]),32);
        bufp->chgIData(oldp+75,(vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers[14]),32);
        bufp->chgIData(oldp+76,(vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers[15]),32);
        bufp->chgIData(oldp+77,(vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers[16]),32);
        bufp->chgIData(oldp+78,(vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers[17]),32);
        bufp->chgIData(oldp+79,(vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers[18]),32);
        bufp->chgIData(oldp+80,(vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers[19]),32);
        bufp->chgIData(oldp+81,(vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers[20]),32);
        bufp->chgIData(oldp+82,(vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers[21]),32);
        bufp->chgIData(oldp+83,(vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers[22]),32);
        bufp->chgIData(oldp+84,(vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers[23]),32);
        bufp->chgIData(oldp+85,(vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers[24]),32);
        bufp->chgIData(oldp+86,(vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers[25]),32);
        bufp->chgIData(oldp+87,(vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers[26]),32);
        bufp->chgIData(oldp+88,(vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers[27]),32);
        bufp->chgIData(oldp+89,(vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers[28]),32);
        bufp->chgIData(oldp+90,(vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers[29]),32);
        bufp->chgIData(oldp+91,(vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers[30]),32);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[6U])) {
        bufp->chgIData(oldp+92,(vlSelf->tb__DOT__dut__DOT__address_MEM),32);
        bufp->chgIData(oldp+93,(vlSelf->tb__DOT__dut__DOT____Vcellout__EXMEM_stage__memWriteData_MEM),32);
        bufp->chgBit(oldp+94,(((~ (IData)(vlSelf->tb__DOT__dut__DOT__storeLoad_MEM)) 
                               & (3U != (IData)(vlSelf->tb__DOT__dut__DOT__memoryOpSize_MEM)))));
        bufp->chgBit(oldp+95,(((3U != (IData)(vlSelf->tb__DOT__dut__DOT__memoryOpSize_MEM)) 
                               & (IData)(vlSelf->tb__DOT__dut__DOT__storeLoad_MEM))));
        bufp->chgCData(oldp+96,(((0U == (IData)(vlSelf->tb__DOT__dut__DOT__memoryOpSize_MEM))
                                  ? 0U : ((1U == (IData)(vlSelf->tb__DOT__dut__DOT__memoryOpSize_MEM))
                                           ? 1U : (
                                                   (2U 
                                                    == (IData)(vlSelf->tb__DOT__dut__DOT__memoryOpSize_MEM))
                                                    ? 2U
                                                    : 7U)))),3);
        bufp->chgBit(oldp+97,(vlSelf->tb__DOT__dut__DOT__branchPrediction));
        bufp->chgBit(oldp+98,((((0x67U != (0x7fU & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)) 
                                & (IData)(vlSelf->tb__DOT__dut__DOT__jump)) 
                               | (IData)(vlSelf->tb__DOT__dut__DOT__branchPrediction))));
        bufp->chgIData(oldp+99,(vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID),32);
        bufp->chgCData(oldp+100,((0x1fU & (vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID 
                                           >> 0xfU))),5);
        bufp->chgCData(oldp+101,((0x1fU & (vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID 
                                           >> 0x14U))),5);
        bufp->chgCData(oldp+102,((0x1fU & (vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID 
                                           >> 7U))),5);
        bufp->chgBit(oldp+103,((((0x33U == (0x7fU & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)) 
                                 | (IData)((0x5013U 
                                            == (0x707fU 
                                                & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)))) 
                                & (vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID 
                                   >> 0x1eU))));
        bufp->chgCData(oldp+104,((((0x13U == (0x7fU 
                                              & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)) 
                                   || (0x33U == (0x7fU 
                                                 & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)))
                                   ? (7U & (vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID 
                                            >> 0xcU))
                                   : 0U)),3);
        bufp->chgBit(oldp+105,((0x37U == (0x7fU & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID))));
        bufp->chgBit(oldp+106,(((0x17U == (0x7fU & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)) 
                                | ((0x6fU == (0x7fU 
                                              & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)) 
                                   | (0x63U == (0x7fU 
                                                & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID))))));
        bufp->chgBit(oldp+107,(((0x37U == (0x7fU & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)) 
                                | ((0x17U == (0x7fU 
                                              & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)) 
                                   | ((0x6fU == (0x7fU 
                                                 & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)) 
                                      | ((0x67U == 
                                          (0x7fU & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)) 
                                         | ((0x63U 
                                             == (0x7fU 
                                                 & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)) 
                                            | ((3U 
                                                == 
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
        bufp->chgCData(oldp+108,((((3U == (0x7fU & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)) 
                                   | (0x23U == (0x7fU 
                                                & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)))
                                   ? (3U & (vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID 
                                            >> 0xcU))
                                   : 3U)),2);
        bufp->chgBit(oldp+109,((1U & (vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID 
                                      >> 0xeU))));
        bufp->chgBit(oldp+110,((0x23U == (0x7fU & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID))));
        bufp->chgCData(oldp+111,(vlSelf->tb__DOT__dut__DOT__branchOp),2);
        bufp->chgBit(oldp+112,((1U & (vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID 
                                      >> 0xcU))));
        bufp->chgBit(oldp+113,(vlSelf->tb__DOT__dut__DOT__jump));
        bufp->chgCData(oldp+114,(vlSelf->tb__DOT__dut__DOT__writeSource),2);
        bufp->chgIData(oldp+115,(vlSelf->tb__DOT__dut__DOT__immediate),32);
        bufp->chgBit(oldp+116,(vlSelf->tb__DOT__dut__DOT__writeEnable_EX));
        bufp->chgCData(oldp+117,(vlSelf->tb__DOT__dut__DOT__rd_EX),5);
        bufp->chgCData(oldp+118,(vlSelf->tb__DOT__dut__DOT__memoryOpSize_EX),2);
        bufp->chgBit(oldp+119,(vlSelf->tb__DOT__dut__DOT__storeLoad_EX));
        bufp->chgBit(oldp+120,((0x67U == (0x7fU & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID))));
        bufp->chgBit(oldp+121,(vlSelf->tb__DOT__dut__DOT__writeEnable_MEM));
        bufp->chgCData(oldp+122,(vlSelf->tb__DOT__dut__DOT__rd_MEM),5);
        bufp->chgCData(oldp+123,(vlSelf->tb__DOT__dut__DOT__memoryOpSize_MEM),2);
        bufp->chgBit(oldp+124,(vlSelf->tb__DOT__dut__DOT__storeLoad_MEM));
        bufp->chgBit(oldp+125,(vlSelf->tb__DOT__dut__DOT__writeEnable_WB));
        bufp->chgCData(oldp+126,(vlSelf->tb__DOT__dut__DOT__rd_WB),5);
        bufp->chgIData(oldp+127,(vlSelf->tb__DOT__dut__DOT__registerWriteData),32);
        bufp->chgBit(oldp+128,((0U != (IData)(vlSelf->tb__DOT__dut__DOT__writeSource))));
        bufp->chgCData(oldp+129,((0x7fU & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)),7);
        bufp->chgBit(oldp+130,((1U != (IData)(vlSelf->tb__DOT__dut__DOT__branchOp))));
        bufp->chgBit(oldp+131,(vlSelf->tb__DOT__dut__DOT____Vcellinp__hazardDetection__IDEX_memread));
        bufp->chgCData(oldp+132,((7U & (vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID 
                                        >> 0xcU))),3);
        bufp->chgBit(oldp+133,((1U & (vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID 
                                      >> 0x1eU))));
    }
    bufp->chgBit(oldp+134,(vlSelf->tb__DOT__CLK));
    bufp->chgIData(oldp+135,(vlSelf->tb__DOT__memReadData),32);
    bufp->chgIData(oldp+136,(((0x6fU == (0x7fU & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID))
                               ? (vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instructionAddress_ID 
                                  + vlSelf->tb__DOT__dut__DOT__immediate)
                               : ((0x63U == (0x7fU 
                                             & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID))
                                   ? (vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instructionAddress_ID 
                                      + vlSelf->tb__DOT__dut__DOT__immediate)
                                   : 0U))),32);
    bufp->chgIData(oldp+137,(vlSelf->tb__DOT__dut__DOT__read1Data),32);
    bufp->chgIData(oldp+138,(((0U == (0x1fU & (vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID 
                                               >> 0x14U)))
                               ? 0U : ((0x1eU >= (0x1fU 
                                                  & ((vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID 
                                                      >> 0x14U) 
                                                     - (IData)(1U))))
                                        ? vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers
                                       [(0x1fU & ((vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID 
                                                   >> 0x14U) 
                                                  - (IData)(1U)))]
                                        : 0U))),32);
    bufp->chgIData(oldp+139,(((2U == (IData)(vlSelf->tb__DOT__dut__DOT__ForwardID_A))
                               ? vlSelf->tb__DOT__dut__DOT__address_MEM
                               : ((1U == (IData)(vlSelf->tb__DOT__dut__DOT__ForwardID_A))
                                   ? vlSelf->tb__DOT__dut__DOT__registerWriteData
                                   : vlSelf->tb__DOT__dut__DOT__read1Data))),32);
    bufp->chgIData(oldp+140,(((0U == (IData)(vlSelf->tb__DOT__dut__DOT__memoryOpSize_MEM))
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
    bufp->chgIData(oldp+141,(((((0x67U != (0x7fU & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)) 
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

void Vtb___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root__trace_cleanup\n"); );
    // Init
    Vtb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb___024root*>(voidSelf);
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[4U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[5U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[6U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[7U] = 0U;
}
