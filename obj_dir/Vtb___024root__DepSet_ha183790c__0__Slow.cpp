// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb.h for the primary calling header

#include "Vtb__pch.h"
#include "Vtb___024root.h"

VL_ATTR_COLD void Vtb___024root___eval_static__TOP(Vtb___024root* vlSelf);

VL_ATTR_COLD void Vtb___024root___eval_static(Vtb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_static\n"); );
    // Body
    Vtb___024root___eval_static__TOP(vlSelf);
    vlSelf->__Vm_traceActivity[7U] = 1U;
    vlSelf->__Vm_traceActivity[6U] = 1U;
    vlSelf->__Vm_traceActivity[5U] = 1U;
    vlSelf->__Vm_traceActivity[4U] = 1U;
    vlSelf->__Vm_traceActivity[3U] = 1U;
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
}

VL_ATTR_COLD void Vtb___024root___eval_static__TOP(Vtb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_static__TOP\n"); );
    // Body
    vlSelf->tb__DOT__pass_count = 0U;
    vlSelf->tb__DOT__fail_count = 0U;
}

VL_ATTR_COLD void Vtb___024root___eval_final(Vtb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb___024root___dump_triggers__stl(Vtb___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtb___024root___eval_phase__stl(Vtb___024root* vlSelf);

VL_ATTR_COLD void Vtb___024root___eval_settle(Vtb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_settle\n"); );
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelf->__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            Vtb___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("tb.sv", 63, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vtb___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb___024root___dump_triggers__stl(Vtb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

extern const VlUnpacked<CData/*1:0*/, 128> Vtb__ConstPool__TABLE_hfc6ad3e0_0;

VL_ATTR_COLD void Vtb___024root___stl_sequent__TOP__0(Vtb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___stl_sequent__TOP__0\n"); );
    // Init
    CData/*6:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    vlSelf->tb__DOT__dut__DOT__read1Data = ((0U == 
                                             (0x1fU 
                                              & (vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID 
                                                 >> 0xfU)))
                                             ? 0U : 
                                            ((0x1eU 
                                              >= (0x1fU 
                                                  & ((vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID 
                                                      >> 0xfU) 
                                                     - (IData)(1U))))
                                              ? vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers
                                             [(0x1fU 
                                               & ((vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID 
                                                   >> 0xfU) 
                                                  - (IData)(1U)))]
                                              : 0U));
    __Vtableidx1 = (0x7fU & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID);
    vlSelf->tb__DOT__dut__DOT__writeSource = Vtb__ConstPool__TABLE_hfc6ad3e0_0
        [__Vtableidx1];
    vlSelf->tb__DOT__memReadData = (((~ (IData)(vlSelf->tb__DOT__dut__DOT__storeLoad_MEM)) 
                                     & (3U != (IData)(vlSelf->tb__DOT__dut__DOT__memoryOpSize_MEM)))
                                     ? vlSelf->tb__DOT__dmem
                                    [(0x1ffU & (vlSelf->tb__DOT__dut__DOT__address_MEM 
                                                >> 2U))]
                                     : 0U);
    if (((0x1fU & (vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID 
                   >> 0xfU)) == (IData)(vlSelf->tb__DOT__dut__DOT__rs1_EX))) {
        vlSelf->tb__DOT__dut__DOT__ForwardID_A = 0U;
    }
    vlSelf->tb__DOT__dut__DOT__immediate = ((0x40U 
                                             & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)
                                             ? ((0x20U 
                                                 & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)
                                                 ? 
                                                ((0x10U 
                                                  & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)
                                                  ? 0U
                                                  : 
                                                 ((8U 
                                                   & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)
                                                   ? 
                                                  ((4U 
                                                    & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)
                                                    ? 
                                                   ((2U 
                                                     & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)
                                                     ? 
                                                    ((1U 
                                                      & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)
                                                      ? 
                                                     (((- (IData)(
                                                                  (vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID 
                                                                   >> 0x1fU))) 
                                                       << 0x15U) 
                                                      | ((0x100000U 
                                                          & (vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID 
                                                             >> 0xbU)) 
                                                         | ((0xff000U 
                                                             & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID) 
                                                            | ((0x800U 
                                                                & (vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID 
                                                                   >> 9U)) 
                                                               | (0x7feU 
                                                                  & (vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID 
                                                                     >> 0x14U))))))
                                                      : 0U)
                                                     : 0U)
                                                    : 0U)
                                                   : 
                                                  ((4U 
                                                    & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)
                                                    ? 
                                                   ((2U 
                                                     & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)
                                                     ? 
                                                    ((1U 
                                                      & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)
                                                      ? 
                                                     (((- (IData)(
                                                                  (vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID 
                                                                   >> 0x1fU))) 
                                                       << 0xcU) 
                                                      | (vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID 
                                                         >> 0x14U))
                                                      : 0U)
                                                     : 0U)
                                                    : 
                                                   ((2U 
                                                     & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)
                                                     ? 
                                                    ((1U 
                                                      & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)
                                                      ? 
                                                     (((- (IData)(
                                                                  (vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID 
                                                                   >> 0x1fU))) 
                                                       << 0xdU) 
                                                      | ((0x1000U 
                                                          & (vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID 
                                                             >> 0x13U)) 
                                                         | ((0x800U 
                                                             & (vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID 
                                                                << 4U)) 
                                                            | ((0x7e0U 
                                                                & (vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID 
                                                                   >> 0x14U)) 
                                                               | (0x1eU 
                                                                  & (vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID 
                                                                     >> 7U))))))
                                                      : 0U)
                                                     : 0U))))
                                                 : 0U)
                                             : ((0x20U 
                                                 & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)
                                                 ? 
                                                ((0x10U 
                                                  & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)
                                                  ? 
                                                 ((8U 
                                                   & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)
                                                   ? 0U
                                                   : 
                                                  ((4U 
                                                    & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)
                                                    ? 
                                                   ((2U 
                                                     & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)
                                                     ? 
                                                    ((1U 
                                                      & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)
                                                      ? 
                                                     (0xfffff000U 
                                                      & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)
                                                      : 0U)
                                                     : 0U)
                                                    : 0U))
                                                  : 
                                                 ((8U 
                                                   & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)
                                                   ? 0U
                                                   : 
                                                  ((4U 
                                                    & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)
                                                    ? 0U
                                                    : 
                                                   ((2U 
                                                     & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)
                                                     ? 
                                                    ((1U 
                                                      & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)
                                                      ? 
                                                     (((- (IData)(
                                                                  (vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID 
                                                                   >> 0x1fU))) 
                                                       << 0xcU) 
                                                      | ((0xfe0U 
                                                          & (vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID 
                                                             >> 0x14U)) 
                                                         | (0x1fU 
                                                            & (vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID 
                                                               >> 7U))))
                                                      : 0U)
                                                     : 0U))))
                                                 : 
                                                ((0x10U 
                                                  & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)
                                                  ? 
                                                 ((8U 
                                                   & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)
                                                   ? 0U
                                                   : 
                                                  ((4U 
                                                    & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)
                                                    ? 
                                                   ((2U 
                                                     & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)
                                                     ? 
                                                    ((1U 
                                                      & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)
                                                      ? 
                                                     (0xfffff000U 
                                                      & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)
                                                      : 0U)
                                                     : 0U)
                                                    : 
                                                   ((2U 
                                                     & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)
                                                     ? 
                                                    ((1U 
                                                      & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)
                                                      ? 
                                                     (((- (IData)(
                                                                  (vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID 
                                                                   >> 0x1fU))) 
                                                       << 0xcU) 
                                                      | (vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID 
                                                         >> 0x14U))
                                                      : 0U)
                                                     : 0U)))
                                                  : 
                                                 ((8U 
                                                   & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)
                                                   ? 0U
                                                   : 
                                                  ((4U 
                                                    & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)
                                                    ? 0U
                                                    : 
                                                   ((2U 
                                                     & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)
                                                     ? 
                                                    ((1U 
                                                      & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)
                                                      ? 
                                                     (((- (IData)(
                                                                  (vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID 
                                                                   >> 0x1fU))) 
                                                       << 0xcU) 
                                                      | (vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID 
                                                         >> 0x14U))
                                                      : 0U)
                                                     : 0U))))));
    vlSelf->tb__DOT__dut__DOT__jump = ((0x6fU == (0x7fU 
                                                  & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)) 
                                       | (0x67U == 
                                          (0x7fU & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)));
    vlSelf->tb__DOT__dut__DOT__branchOp = ((0x63U == 
                                            (0x7fU 
                                             & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID))
                                            ? (3U & 
                                               (vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID 
                                                >> 0xdU))
                                            : 1U);
    vlSelf->tb__DOT__dut__DOT____Vcellinp__IFID_stage__instruction_IF 
        = vlSelf->tb__DOT__imem[(0x1ffU & (vlSelf->tb__DOT__instructionAddress 
                                           >> 2U))];
    vlSelf->tb__DOT__dut__DOT____Vcellinp__hazardDetection__IDEX_memread 
        = (1U & (~ ((IData)(vlSelf->tb__DOT__dut__DOT__storeLoad_EX) 
                    | (3U == (IData)(vlSelf->tb__DOT__dut__DOT__memoryOpSize_EX)))));
    if ((1U & (~ (IData)(vlSelf->tb__DOT__RSTN)))) {
        vlSelf->tb__DOT__dut__DOT__ForwardB = 0U;
        vlSelf->tb__DOT__dut__DOT__ForwardA = 0U;
    }
    vlSelf->tb__DOT__dut__DOT__ForwardB = (((IData)(vlSelf->tb__DOT__dut__DOT__writeEnable_MEM) 
                                            & ((IData)(vlSelf->tb__DOT__dut__DOT__rd_MEM) 
                                               == (IData)(vlSelf->tb__DOT__dut__DOT__rs2_EX)))
                                            ? 2U : 
                                           ((((IData)(vlSelf->tb__DOT__dut__DOT__writeEnable_WB) 
                                              & ((IData)(vlSelf->tb__DOT__dut__DOT__rd_WB) 
                                                 == (IData)(vlSelf->tb__DOT__dut__DOT__rs2_EX))) 
                                             & (~ ((IData)(vlSelf->tb__DOT__dut__DOT__writeEnable_MEM) 
                                                   & ((IData)(vlSelf->tb__DOT__dut__DOT__rd_MEM) 
                                                      == (IData)(vlSelf->tb__DOT__dut__DOT__rs2_EX)))))
                                             ? 1U : 0U));
    vlSelf->tb__DOT__dut__DOT__ForwardA = (((IData)(vlSelf->tb__DOT__dut__DOT__writeEnable_MEM) 
                                            & ((IData)(vlSelf->tb__DOT__dut__DOT__rd_MEM) 
                                               == (IData)(vlSelf->tb__DOT__dut__DOT__rs1_EX)))
                                            ? 2U : 
                                           ((((IData)(vlSelf->tb__DOT__dut__DOT__writeEnable_WB) 
                                              & ((IData)(vlSelf->tb__DOT__dut__DOT__rd_WB) 
                                                 == (IData)(vlSelf->tb__DOT__dut__DOT__rs1_EX))) 
                                             & (~ ((IData)(vlSelf->tb__DOT__dut__DOT__writeEnable_MEM) 
                                                   & ((IData)(vlSelf->tb__DOT__dut__DOT__rd_MEM) 
                                                      == (IData)(vlSelf->tb__DOT__dut__DOT__rs1_EX)))))
                                             ? 1U : 0U));
    vlSelf->tb__DOT__dut__DOT__registerWriteData = 
        ((3U == (IData)(vlSelf->tb__DOT__dut__DOT__writeSource_WB))
          ? vlSelf->tb__DOT__dut__DOT__address_WB : 
         ((2U == (IData)(vlSelf->tb__DOT__dut__DOT__writeSource_WB))
           ? vlSelf->tb__DOT__dut__DOT__memToRegData_WB
           : ((1U == (IData)(vlSelf->tb__DOT__dut__DOT__writeSource_WB))
               ? ((IData)(4U) + vlSelf->tb__DOT__dut__DOT__instructionAddress_WB)
               : 0U)));
    vlSelf->tb__DOT__dut__DOT__branchPrediction = (
                                                   (1U 
                                                    != (IData)(vlSelf->tb__DOT__dut__DOT__branchOp)) 
                                                   & (2U 
                                                      <= (IData)(vlSelf->tb__DOT__dut__DOT__branchPredictor__DOT__saturationCounter)));
    vlSelf->tb__DOT__dut__DOT__PC_update = 1U;
    vlSelf->tb__DOT__dut__DOT__IFID_write = 1U;
    vlSelf->tb__DOT__dut__DOT__IDEX_delay = 0U;
    if (vlSelf->tb__DOT__RSTN) {
        vlSelf->tb__DOT__dut__DOT__ForwardID_A = ((
                                                   ((IData)(vlSelf->tb__DOT__dut__DOT__writeEnable_MEM) 
                                                    & (0U 
                                                       != (IData)(vlSelf->tb__DOT__dut__DOT__rd_MEM))) 
                                                   & ((IData)(vlSelf->tb__DOT__dut__DOT__rd_MEM) 
                                                      == 
                                                      (0x1fU 
                                                       & (vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID 
                                                          >> 0xfU))))
                                                   ? 2U
                                                   : 
                                                  ((((IData)(vlSelf->tb__DOT__dut__DOT__writeEnable_WB) 
                                                     & (0U 
                                                        != (IData)(vlSelf->tb__DOT__dut__DOT__rd_WB))) 
                                                    & ((IData)(vlSelf->tb__DOT__dut__DOT__rd_WB) 
                                                       == 
                                                       (0x1fU 
                                                        & (vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID 
                                                           >> 0xfU))))
                                                    ? 1U
                                                    : 0U));
        if ((((IData)(vlSelf->tb__DOT__dut__DOT____Vcellinp__hazardDetection__IDEX_memread) 
              & (((0x1fU & (vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID 
                            >> 0xfU)) == (IData)(vlSelf->tb__DOT__dut__DOT__rd_EX)) 
                 | ((0x1fU & (vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID 
                              >> 0x14U)) == (IData)(vlSelf->tb__DOT__dut__DOT__rd_EX)))) 
             & (3U != (0x7fU & vlSelf->tb__DOT__dut__DOT____Vcellinp__IFID_stage__instruction_IF)))) {
            vlSelf->tb__DOT__dut__DOT__PC_update = 0U;
            vlSelf->tb__DOT__dut__DOT__IFID_write = 0U;
            vlSelf->tb__DOT__dut__DOT__IDEX_delay = 1U;
        } else if ((((IData)(vlSelf->tb__DOT__dut__DOT____Vcellinp__hazardDetection__IDEX_memread) 
                     & (((0x1fU & (vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID 
                                   >> 0xfU)) == (IData)(vlSelf->tb__DOT__dut__DOT__rd_EX)) 
                        | ((0x1fU & (vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID 
                                     >> 0x14U)) == (IData)(vlSelf->tb__DOT__dut__DOT__rd_EX)))) 
                    & (3U == (0x7fU & vlSelf->tb__DOT__dut__DOT____Vcellinp__IFID_stage__instruction_IF)))) {
            vlSelf->tb__DOT__dut__DOT__PC_update = 
                (2U <= (IData)(vlSelf->tb__DOT__dut__DOT__hazardDetection__DOT__loadCounter));
            vlSelf->tb__DOT__dut__DOT__IFID_write = 
                (2U <= (IData)(vlSelf->tb__DOT__dut__DOT__hazardDetection__DOT__loadCounter));
            vlSelf->tb__DOT__dut__DOT__IDEX_delay = 
                (2U > (IData)(vlSelf->tb__DOT__dut__DOT__hazardDetection__DOT__loadCounter));
        }
    } else {
        vlSelf->tb__DOT__dut__DOT__ForwardID_A = 0U;
        vlSelf->tb__DOT__dut__DOT__PC_update = 1U;
        vlSelf->tb__DOT__dut__DOT__IFID_write = 1U;
        vlSelf->tb__DOT__dut__DOT__IDEX_delay = 0U;
    }
    vlSelf->tb__DOT__dut__DOT__fwd_rs2 = ((2U == (IData)(vlSelf->tb__DOT__dut__DOT__ForwardB))
                                           ? vlSelf->tb__DOT__dut__DOT__address_MEM
                                           : ((1U == (IData)(vlSelf->tb__DOT__dut__DOT__ForwardB))
                                               ? vlSelf->tb__DOT__dut__DOT__registerWriteData
                                               : vlSelf->tb__DOT__dut__DOT__read2Data_EX));
    vlSelf->tb__DOT__dut__DOT__xalu_secondary = ((IData)(vlSelf->tb__DOT__dut__DOT__immediateXaluSecondary_EX)
                                                  ? vlSelf->tb__DOT__dut__DOT__immediate_EX
                                                  : vlSelf->tb__DOT__dut__DOT__fwd_rs2);
    vlSelf->tb__DOT__dut__DOT__fwd_rs1 = ((2U == (IData)(vlSelf->tb__DOT__dut__DOT__ForwardA))
                                           ? vlSelf->tb__DOT__dut__DOT__address_MEM
                                           : ((1U == (IData)(vlSelf->tb__DOT__dut__DOT__ForwardA))
                                               ? vlSelf->tb__DOT__dut__DOT__registerWriteData
                                               : vlSelf->tb__DOT__dut__DOT__read1Data_EX));
    vlSelf->tb__DOT__dut__DOT__xalu_primary = ((IData)(vlSelf->tb__DOT__dut__DOT__pcXaluPrimary_EX)
                                                ? vlSelf->tb__DOT__dut__DOT__instructionAddress_EX
                                                : ((IData)(vlSelf->tb__DOT__dut__DOT__zeroXaluPrimary_EX)
                                                    ? 0U
                                                    : vlSelf->tb__DOT__dut__DOT__fwd_rs1));
    vlSelf->tb__DOT__dut__DOT__aluResult = ((4U & (IData)(vlSelf->tb__DOT__dut__DOT__xaluOp_EX))
                                             ? ((2U 
                                                 & (IData)(vlSelf->tb__DOT__dut__DOT__xaluOp_EX))
                                                 ? 
                                                ((1U 
                                                  & (IData)(vlSelf->tb__DOT__dut__DOT__xaluOp_EX))
                                                  ? 
                                                 (vlSelf->tb__DOT__dut__DOT__xalu_primary 
                                                  & vlSelf->tb__DOT__dut__DOT__xalu_secondary)
                                                  : 
                                                 (vlSelf->tb__DOT__dut__DOT__xalu_primary 
                                                  | vlSelf->tb__DOT__dut__DOT__xalu_secondary))
                                                 : 
                                                ((1U 
                                                  & (IData)(vlSelf->tb__DOT__dut__DOT__xaluOp_EX))
                                                  ? 
                                                 ((IData)(vlSelf->tb__DOT__dut__DOT__xaluArithmeticFlag_EX)
                                                   ? 
                                                  VL_SHIFTRS_III(32,32,5, vlSelf->tb__DOT__dut__DOT__xalu_primary, 
                                                                 (0x1fU 
                                                                  & vlSelf->tb__DOT__dut__DOT__xalu_secondary))
                                                   : 
                                                  (vlSelf->tb__DOT__dut__DOT__xalu_primary 
                                                   >> 
                                                   (0x1fU 
                                                    & vlSelf->tb__DOT__dut__DOT__xalu_secondary)))
                                                  : 
                                                 (vlSelf->tb__DOT__dut__DOT__xalu_primary 
                                                  ^ vlSelf->tb__DOT__dut__DOT__xalu_secondary)))
                                             : ((2U 
                                                 & (IData)(vlSelf->tb__DOT__dut__DOT__xaluOp_EX))
                                                 ? 
                                                ((1U 
                                                  & (IData)(vlSelf->tb__DOT__dut__DOT__xaluOp_EX))
                                                  ? 
                                                 (vlSelf->tb__DOT__dut__DOT__xalu_primary 
                                                  < vlSelf->tb__DOT__dut__DOT__xalu_secondary)
                                                  : 
                                                 VL_LTS_III(32, vlSelf->tb__DOT__dut__DOT__xalu_primary, vlSelf->tb__DOT__dut__DOT__xalu_secondary))
                                                 : 
                                                ((1U 
                                                  & (IData)(vlSelf->tb__DOT__dut__DOT__xaluOp_EX))
                                                  ? 
                                                 (vlSelf->tb__DOT__dut__DOT__xalu_primary 
                                                  << 
                                                  (0x1fU 
                                                   & vlSelf->tb__DOT__dut__DOT__xalu_secondary))
                                                  : 
                                                 ((IData)(vlSelf->tb__DOT__dut__DOT__xaluArithmeticFlag_EX)
                                                   ? 
                                                  (vlSelf->tb__DOT__dut__DOT__xalu_primary 
                                                   - vlSelf->tb__DOT__dut__DOT__xalu_secondary)
                                                   : 
                                                  (vlSelf->tb__DOT__dut__DOT__xalu_primary 
                                                   + vlSelf->tb__DOT__dut__DOT__xalu_secondary)))));
    vlSelf->tb__DOT__dut__DOT__branchPass = ((0U == (IData)(vlSelf->tb__DOT__dut__DOT__branchOp_EX))
                                              ? ((vlSelf->tb__DOT__dut__DOT__fwd_rs1 
                                                  == vlSelf->tb__DOT__dut__DOT__fwd_rs2) 
                                                 ^ (IData)(vlSelf->tb__DOT__dut__DOT__branchNegate_EX))
                                              : ((2U 
                                                  == (IData)(vlSelf->tb__DOT__dut__DOT__branchOp_EX))
                                                  ? 
                                                 (VL_LTS_III(32, vlSelf->tb__DOT__dut__DOT__fwd_rs1, vlSelf->tb__DOT__dut__DOT__fwd_rs2) 
                                                  ^ (IData)(vlSelf->tb__DOT__dut__DOT__branchNegate_EX))
                                                  : 
                                                 ((3U 
                                                   == (IData)(vlSelf->tb__DOT__dut__DOT__branchOp_EX)) 
                                                  && ((vlSelf->tb__DOT__dut__DOT__fwd_rs1 
                                                       < vlSelf->tb__DOT__dut__DOT__fwd_rs2) 
                                                      ^ (IData)(vlSelf->tb__DOT__dut__DOT__branchNegate_EX)))));
    if ((1U != (IData)(vlSelf->tb__DOT__dut__DOT__branchOp_EX))) {
        vlSelf->tb__DOT__dut__DOT__branchTaken_EX = vlSelf->tb__DOT__dut__DOT__branchPass;
        vlSelf->tb__DOT__dut__DOT__branchMispredicted_EX 
            = ((IData)(vlSelf->tb__DOT__dut__DOT__branchTaken_EX) 
               != (IData)(vlSelf->tb__DOT__dut__DOT__branchPrediction_EX));
    } else {
        vlSelf->tb__DOT__dut__DOT__branchTaken_EX = 0U;
        vlSelf->tb__DOT__dut__DOT__branchMispredicted_EX 
            = vlSelf->tb__DOT__dut__DOT__JALR_EX;
    }
    vlSelf->tb__DOT__dut__DOT__branchCorrection = 0U;
    vlSelf->tb__DOT__dut__DOT__branchCorrectionAddress = 0U;
    if (vlSelf->tb__DOT__dut__DOT__branchMispredicted_EX) {
        vlSelf->tb__DOT__dut__DOT__branchCorrection = 1U;
        vlSelf->tb__DOT__dut__DOT__branchCorrectionAddress 
            = (((IData)(vlSelf->tb__DOT__dut__DOT__branchTaken_EX) 
                | (IData)(vlSelf->tb__DOT__dut__DOT__JALR_EX))
                ? ((0x67U == (0x7fU & vlSelf->tb__DOT__dut__DOT____Vcellout__IDEX_stage__instruction_EX))
                    ? vlSelf->tb__DOT__dut__DOT__aluResult
                    : (vlSelf->tb__DOT__dut__DOT__instructionAddress_EX 
                       + vlSelf->tb__DOT__dut__DOT__immediate_EX))
                : ((IData)(4U) + vlSelf->tb__DOT__dut__DOT__instructionAddress_EX));
    }
    vlSelf->tb__DOT__dut__DOT__pipelineFlush = ((IData)(vlSelf->tb__DOT__dut__DOT__branchCorrection) 
                                                | ((IData)(vlSelf->tb__DOT__dut__DOT__JALR_EX) 
                                                   | (IData)(vlSelf->tb__DOT__dut__DOT__jump_EX_reg)));
    vlSelf->tb__DOT__dut__DOT__programCounter__DOT__addrNext 
        = ((((0x67U != (0x7fU & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)) 
             & (IData)(vlSelf->tb__DOT__dut__DOT__jump)) 
            | (IData)(vlSelf->tb__DOT__dut__DOT__branchPrediction))
            ? ((0x6fU == (0x7fU & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID))
                ? (vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instructionAddress_ID 
                   + vlSelf->tb__DOT__dut__DOT__immediate)
                : ((0x63U == (0x7fU & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID))
                    ? (vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instructionAddress_ID 
                       + vlSelf->tb__DOT__dut__DOT__immediate)
                    : 0U)) : ((IData)(vlSelf->tb__DOT__dut__DOT__branchCorrection)
                               ? vlSelf->tb__DOT__dut__DOT__branchCorrectionAddress
                               : ((IData)(4U) + vlSelf->tb__DOT__instructionAddress)));
}

VL_ATTR_COLD void Vtb___024root___eval_stl(Vtb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vtb___024root___stl_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[7U] = 1U;
        vlSelf->__Vm_traceActivity[6U] = 1U;
        vlSelf->__Vm_traceActivity[5U] = 1U;
        vlSelf->__Vm_traceActivity[4U] = 1U;
        vlSelf->__Vm_traceActivity[3U] = 1U;
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
    }
}

VL_ATTR_COLD void Vtb___024root___eval_triggers__stl(Vtb___024root* vlSelf);

VL_ATTR_COLD bool Vtb___024root___eval_phase__stl(Vtb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtb___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vtb___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb___024root___dump_triggers__act(Vtb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge tb.CLK)\n");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge tb.CLK or negedge tb.RSTN)\n");
    }
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @(negedge tb.CLK)\n");
    }
    if ((8ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 3 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb___024root___dump_triggers__nba(Vtb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge tb.CLK)\n");
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge tb.CLK or negedge tb.RSTN)\n");
    }
    if ((4ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @(negedge tb.CLK)\n");
    }
    if ((8ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 3 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb___024root___ctor_var_reset(Vtb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->tb__DOT__CLK = VL_RAND_RESET_I(1);
    vlSelf->tb__DOT__RSTN = VL_RAND_RESET_I(1);
    vlSelf->tb__DOT__stall = VL_RAND_RESET_I(1);
    vlSelf->tb__DOT__instructionAddress = VL_RAND_RESET_I(32);
    vlSelf->tb__DOT__memReadData = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 512; ++__Vi0) {
        vlSelf->tb__DOT__imem[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0 = 0; __Vi0 < 512; ++__Vi0) {
        vlSelf->tb__DOT__dmem[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->tb__DOT__pass_count = 0;
    vlSelf->tb__DOT__fail_count = 0;
    vlSelf->tb__DOT__unnamedblk1__DOT__i = 0;
    vlSelf->tb__DOT__dut__DOT__PC_update = VL_RAND_RESET_I(1);
    vlSelf->tb__DOT__dut__DOT__IFID_write = VL_RAND_RESET_I(1);
    vlSelf->tb__DOT__dut__DOT__IDEX_delay = VL_RAND_RESET_I(1);
    vlSelf->tb__DOT__dut__DOT__ForwardA = VL_RAND_RESET_I(2);
    vlSelf->tb__DOT__dut__DOT__ForwardB = VL_RAND_RESET_I(2);
    vlSelf->tb__DOT__dut__DOT__ForwardID_A = VL_RAND_RESET_I(2);
    vlSelf->tb__DOT__dut__DOT__branchPass = VL_RAND_RESET_I(1);
    vlSelf->tb__DOT__dut__DOT__branchTaken_EX = VL_RAND_RESET_I(1);
    vlSelf->tb__DOT__dut__DOT__branchPrediction = VL_RAND_RESET_I(1);
    vlSelf->tb__DOT__dut__DOT__pipelineFlush = VL_RAND_RESET_I(1);
    vlSelf->tb__DOT__dut__DOT__branchOp = VL_RAND_RESET_I(2);
    vlSelf->tb__DOT__dut__DOT__jump = VL_RAND_RESET_I(1);
    vlSelf->tb__DOT__dut__DOT__writeSource = VL_RAND_RESET_I(2);
    vlSelf->tb__DOT__dut__DOT__immediate = VL_RAND_RESET_I(32);
    vlSelf->tb__DOT__dut__DOT__read1Data = VL_RAND_RESET_I(32);
    vlSelf->tb__DOT__dut__DOT__writeSource_EX = VL_RAND_RESET_I(2);
    vlSelf->tb__DOT__dut__DOT__writeEnable_EX = VL_RAND_RESET_I(1);
    vlSelf->tb__DOT__dut__DOT__read1Data_EX = VL_RAND_RESET_I(32);
    vlSelf->tb__DOT__dut__DOT__read2Data_EX = VL_RAND_RESET_I(32);
    vlSelf->tb__DOT__dut__DOT__rs1_EX = VL_RAND_RESET_I(5);
    vlSelf->tb__DOT__dut__DOT__rs2_EX = VL_RAND_RESET_I(5);
    vlSelf->tb__DOT__dut__DOT__rd_EX = VL_RAND_RESET_I(5);
    vlSelf->tb__DOT__dut__DOT__instructionAddress_EX = VL_RAND_RESET_I(32);
    vlSelf->tb__DOT__dut__DOT__immediate_EX = VL_RAND_RESET_I(32);
    vlSelf->tb__DOT__dut__DOT__xaluOp_EX = VL_RAND_RESET_I(3);
    vlSelf->tb__DOT__dut__DOT__xaluArithmeticFlag_EX = VL_RAND_RESET_I(1);
    vlSelf->tb__DOT__dut__DOT__memoryOpSize_EX = VL_RAND_RESET_I(2);
    vlSelf->tb__DOT__dut__DOT__unsignedLoad_EX = VL_RAND_RESET_I(1);
    vlSelf->tb__DOT__dut__DOT__storeLoad_EX = VL_RAND_RESET_I(1);
    vlSelf->tb__DOT__dut__DOT__pcXaluPrimary_EX = VL_RAND_RESET_I(1);
    vlSelf->tb__DOT__dut__DOT__immediateXaluSecondary_EX = VL_RAND_RESET_I(1);
    vlSelf->tb__DOT__dut__DOT__zeroXaluPrimary_EX = VL_RAND_RESET_I(1);
    vlSelf->tb__DOT__dut__DOT__branchOp_EX = VL_RAND_RESET_I(2);
    vlSelf->tb__DOT__dut__DOT__branchNegate_EX = VL_RAND_RESET_I(1);
    vlSelf->tb__DOT__dut__DOT__jump_EX_reg = VL_RAND_RESET_I(1);
    vlSelf->tb__DOT__dut__DOT__branchPrediction_EX = VL_RAND_RESET_I(1);
    vlSelf->tb__DOT__dut__DOT__JALR_EX = VL_RAND_RESET_I(1);
    vlSelf->tb__DOT__dut__DOT__fwd_rs1 = VL_RAND_RESET_I(32);
    vlSelf->tb__DOT__dut__DOT__fwd_rs2 = VL_RAND_RESET_I(32);
    vlSelf->tb__DOT__dut__DOT__xalu_primary = VL_RAND_RESET_I(32);
    vlSelf->tb__DOT__dut__DOT__xalu_secondary = VL_RAND_RESET_I(32);
    vlSelf->tb__DOT__dut__DOT__aluResult = VL_RAND_RESET_I(32);
    vlSelf->tb__DOT__dut__DOT__branchCorrection = VL_RAND_RESET_I(1);
    vlSelf->tb__DOT__dut__DOT__branchCorrectionAddress = VL_RAND_RESET_I(32);
    vlSelf->tb__DOT__dut__DOT__branchMispredicted_EX = VL_RAND_RESET_I(1);
    vlSelf->tb__DOT__dut__DOT__writeSource_MEM = VL_RAND_RESET_I(2);
    vlSelf->tb__DOT__dut__DOT__writeEnable_MEM = VL_RAND_RESET_I(1);
    vlSelf->tb__DOT__dut__DOT__rd_MEM = VL_RAND_RESET_I(5);
    vlSelf->tb__DOT__dut__DOT__memoryOpSize_MEM = VL_RAND_RESET_I(2);
    vlSelf->tb__DOT__dut__DOT__unsignedLoad_MEM = VL_RAND_RESET_I(1);
    vlSelf->tb__DOT__dut__DOT__storeLoad_MEM = VL_RAND_RESET_I(1);
    vlSelf->tb__DOT__dut__DOT__address_MEM = VL_RAND_RESET_I(32);
    vlSelf->tb__DOT__dut__DOT__instructionAddress_MEM = VL_RAND_RESET_I(32);
    vlSelf->tb__DOT__dut__DOT__memWriteData_MEM = VL_RAND_RESET_I(32);
    vlSelf->tb__DOT__dut__DOT__writeEnable_WB = VL_RAND_RESET_I(1);
    vlSelf->tb__DOT__dut__DOT__address_WB = VL_RAND_RESET_I(32);
    vlSelf->tb__DOT__dut__DOT__rd_WB = VL_RAND_RESET_I(5);
    vlSelf->tb__DOT__dut__DOT__memToRegData_WB = VL_RAND_RESET_I(32);
    vlSelf->tb__DOT__dut__DOT__instructionAddress_WB = VL_RAND_RESET_I(32);
    vlSelf->tb__DOT__dut__DOT__writeSource_WB = VL_RAND_RESET_I(2);
    vlSelf->tb__DOT__dut__DOT__registerWriteData = VL_RAND_RESET_I(32);
    vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID = VL_RAND_RESET_I(32);
    vlSelf->tb__DOT__dut__DOT____Vcellinp__IFID_stage__instruction_IF = VL_RAND_RESET_I(32);
    vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instructionAddress_ID = VL_RAND_RESET_I(32);
    vlSelf->tb__DOT__dut__DOT____Vcellinp__hazardDetection__IDEX_memread = VL_RAND_RESET_I(1);
    vlSelf->tb__DOT__dut__DOT____Vcellout__IDEX_stage__instruction_EX = VL_RAND_RESET_I(32);
    vlSelf->tb__DOT__dut__DOT____Vcellout__EXMEM_stage__memWriteData_MEM = VL_RAND_RESET_I(32);
    vlSelf->tb__DOT__dut__DOT__programCounter__DOT__addrNext = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 31; ++__Vi0) {
        vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT____Vlvbound_h744144bb__0 = VL_RAND_RESET_I(32);
    vlSelf->tb__DOT__dut__DOT__branchPredictor__DOT__saturationCounter = VL_RAND_RESET_I(2);
    vlSelf->tb__DOT__dut__DOT__branchPredictor__DOT__req_delay1 = VL_RAND_RESET_I(1);
    vlSelf->tb__DOT__dut__DOT__branchPredictor__DOT__req_delay2 = VL_RAND_RESET_I(1);
    vlSelf->tb__DOT__dut__DOT__branchPredictor__DOT__branchTaken_delay1 = VL_RAND_RESET_I(1);
    vlSelf->tb__DOT__dut__DOT__hazardDetection__DOT__loadCounter = VL_RAND_RESET_I(2);
    vlSelf->__Vdly__tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID = VL_RAND_RESET_I(32);
    vlSelf->__Vtrigprevexpr___TOP__tb__DOT__CLK__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb__DOT__RSTN__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
