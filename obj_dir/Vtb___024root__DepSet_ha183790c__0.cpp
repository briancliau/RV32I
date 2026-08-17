// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb.h for the primary calling header

#include "Vtb__pch.h"
#include "Vtb___024root.h"

VL_ATTR_COLD void Vtb___024root___eval_initial__TOP(Vtb___024root* vlSelf);
VlCoroutine Vtb___024root___eval_initial__TOP__Vtiming__0(Vtb___024root* vlSelf);
VlCoroutine Vtb___024root___eval_initial__TOP__Vtiming__1(Vtb___024root* vlSelf);
VlCoroutine Vtb___024root___eval_initial__TOP__Vtiming__2(Vtb___024root* vlSelf);

void Vtb___024root___eval_initial(Vtb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_initial\n"); );
    // Body
    Vtb___024root___eval_initial__TOP(vlSelf);
    vlSelf->__Vm_traceActivity[1U] = 1U;
    Vtb___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vtb___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    Vtb___024root___eval_initial__TOP__Vtiming__2(vlSelf);
    vlSelf->__Vtrigprevexpr___TOP__tb__DOT__CLK__0 
        = vlSelf->tb__DOT__CLK;
    vlSelf->__Vtrigprevexpr___TOP__tb__DOT__RSTN__0 
        = vlSelf->tb__DOT__RSTN;
}

VL_INLINE_OPT VlCoroutine Vtb___024root___eval_initial__TOP__Vtiming__0(Vtb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_initial__TOP__Vtiming__0\n"); );
    // Body
    vlSelf->tb__DOT__CLK = 0U;
    while (1U) {
        co_await vlSelf->__VdlySched.delay(0x1388ULL, 
                                           nullptr, 
                                           "tb.sv", 
                                           117);
        vlSelf->tb__DOT__CLK = (1U & (~ (IData)(vlSelf->tb__DOT__CLK)));
    }
}

VL_INLINE_OPT VlCoroutine Vtb___024root___eval_initial__TOP__Vtiming__1(Vtb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_initial__TOP__Vtiming__1\n"); );
    // Body
    co_await vlSelf->__VdlySched.delay(0x989680ULL, 
                                       nullptr, "tb.sv", 
                                       123);
    VL_WRITEF("[WATCHDOG] Simulation timed out.\n");
    VL_FINISH_MT("tb.sv", 125, "");
}

VL_INLINE_OPT VlCoroutine Vtb___024root___eval_initial__TOP__Vtiming__2(Vtb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_initial__TOP__Vtiming__2\n"); );
    // Init
    std::string __Vtask_tb__DOT__check_reg__0__label;
    IData/*31:0*/ __Vtask_tb__DOT__check_reg__0__rnum;
    __Vtask_tb__DOT__check_reg__0__rnum = 0;
    IData/*31:0*/ __Vtask_tb__DOT__check_reg__0__actual;
    __Vtask_tb__DOT__check_reg__0__actual = 0;
    IData/*31:0*/ __Vtask_tb__DOT__check_reg__0__expected;
    __Vtask_tb__DOT__check_reg__0__expected = 0;
    std::string __Vtask_tb__DOT__check_reg__1__label;
    IData/*31:0*/ __Vtask_tb__DOT__check_reg__1__rnum;
    __Vtask_tb__DOT__check_reg__1__rnum = 0;
    IData/*31:0*/ __Vtask_tb__DOT__check_reg__1__actual;
    __Vtask_tb__DOT__check_reg__1__actual = 0;
    IData/*31:0*/ __Vtask_tb__DOT__check_reg__1__expected;
    __Vtask_tb__DOT__check_reg__1__expected = 0;
    std::string __Vtask_tb__DOT__check_reg__2__label;
    IData/*31:0*/ __Vtask_tb__DOT__check_reg__2__rnum;
    __Vtask_tb__DOT__check_reg__2__rnum = 0;
    IData/*31:0*/ __Vtask_tb__DOT__check_reg__2__actual;
    __Vtask_tb__DOT__check_reg__2__actual = 0;
    IData/*31:0*/ __Vtask_tb__DOT__check_reg__2__expected;
    __Vtask_tb__DOT__check_reg__2__expected = 0;
    std::string __Vtask_tb__DOT__check_reg__3__label;
    IData/*31:0*/ __Vtask_tb__DOT__check_reg__3__rnum;
    __Vtask_tb__DOT__check_reg__3__rnum = 0;
    IData/*31:0*/ __Vtask_tb__DOT__check_reg__3__actual;
    __Vtask_tb__DOT__check_reg__3__actual = 0;
    IData/*31:0*/ __Vtask_tb__DOT__check_reg__3__expected;
    __Vtask_tb__DOT__check_reg__3__expected = 0;
    std::string __Vtask_tb__DOT__check_reg__4__label;
    IData/*31:0*/ __Vtask_tb__DOT__check_reg__4__rnum;
    __Vtask_tb__DOT__check_reg__4__rnum = 0;
    IData/*31:0*/ __Vtask_tb__DOT__check_reg__4__actual;
    __Vtask_tb__DOT__check_reg__4__actual = 0;
    IData/*31:0*/ __Vtask_tb__DOT__check_reg__4__expected;
    __Vtask_tb__DOT__check_reg__4__expected = 0;
    std::string __Vtask_tb__DOT__check_reg__5__label;
    IData/*31:0*/ __Vtask_tb__DOT__check_reg__5__rnum;
    __Vtask_tb__DOT__check_reg__5__rnum = 0;
    IData/*31:0*/ __Vtask_tb__DOT__check_reg__5__actual;
    __Vtask_tb__DOT__check_reg__5__actual = 0;
    IData/*31:0*/ __Vtask_tb__DOT__check_reg__5__expected;
    __Vtask_tb__DOT__check_reg__5__expected = 0;
    std::string __Vtask_tb__DOT__check_reg__6__label;
    IData/*31:0*/ __Vtask_tb__DOT__check_reg__6__rnum;
    __Vtask_tb__DOT__check_reg__6__rnum = 0;
    IData/*31:0*/ __Vtask_tb__DOT__check_reg__6__actual;
    __Vtask_tb__DOT__check_reg__6__actual = 0;
    IData/*31:0*/ __Vtask_tb__DOT__check_reg__6__expected;
    __Vtask_tb__DOT__check_reg__6__expected = 0;
    std::string __Vtask_tb__DOT__check_reg__7__label;
    IData/*31:0*/ __Vtask_tb__DOT__check_reg__7__rnum;
    __Vtask_tb__DOT__check_reg__7__rnum = 0;
    IData/*31:0*/ __Vtask_tb__DOT__check_reg__7__actual;
    __Vtask_tb__DOT__check_reg__7__actual = 0;
    IData/*31:0*/ __Vtask_tb__DOT__check_reg__7__expected;
    __Vtask_tb__DOT__check_reg__7__expected = 0;
    std::string __Vtask_tb__DOT__check_reg__8__label;
    IData/*31:0*/ __Vtask_tb__DOT__check_reg__8__rnum;
    __Vtask_tb__DOT__check_reg__8__rnum = 0;
    IData/*31:0*/ __Vtask_tb__DOT__check_reg__8__actual;
    __Vtask_tb__DOT__check_reg__8__actual = 0;
    IData/*31:0*/ __Vtask_tb__DOT__check_reg__8__expected;
    __Vtask_tb__DOT__check_reg__8__expected = 0;
    std::string __Vtask_tb__DOT__check_reg__9__label;
    IData/*31:0*/ __Vtask_tb__DOT__check_reg__9__rnum;
    __Vtask_tb__DOT__check_reg__9__rnum = 0;
    IData/*31:0*/ __Vtask_tb__DOT__check_reg__9__actual;
    __Vtask_tb__DOT__check_reg__9__actual = 0;
    IData/*31:0*/ __Vtask_tb__DOT__check_reg__9__expected;
    __Vtask_tb__DOT__check_reg__9__expected = 0;
    std::string __Vtask_tb__DOT__check_reg__10__label;
    IData/*31:0*/ __Vtask_tb__DOT__check_reg__10__rnum;
    __Vtask_tb__DOT__check_reg__10__rnum = 0;
    IData/*31:0*/ __Vtask_tb__DOT__check_reg__10__actual;
    __Vtask_tb__DOT__check_reg__10__actual = 0;
    IData/*31:0*/ __Vtask_tb__DOT__check_reg__10__expected;
    __Vtask_tb__DOT__check_reg__10__expected = 0;
    std::string __Vtask_tb__DOT__check_reg__11__label;
    IData/*31:0*/ __Vtask_tb__DOT__check_reg__11__rnum;
    __Vtask_tb__DOT__check_reg__11__rnum = 0;
    IData/*31:0*/ __Vtask_tb__DOT__check_reg__11__actual;
    __Vtask_tb__DOT__check_reg__11__actual = 0;
    IData/*31:0*/ __Vtask_tb__DOT__check_reg__11__expected;
    __Vtask_tb__DOT__check_reg__11__expected = 0;
    std::string __Vtask_tb__DOT__check_reg__12__label;
    IData/*31:0*/ __Vtask_tb__DOT__check_reg__12__rnum;
    __Vtask_tb__DOT__check_reg__12__rnum = 0;
    IData/*31:0*/ __Vtask_tb__DOT__check_reg__12__actual;
    __Vtask_tb__DOT__check_reg__12__actual = 0;
    IData/*31:0*/ __Vtask_tb__DOT__check_reg__12__expected;
    __Vtask_tb__DOT__check_reg__12__expected = 0;
    std::string __Vtask_tb__DOT__check_reg__13__label;
    IData/*31:0*/ __Vtask_tb__DOT__check_reg__13__rnum;
    __Vtask_tb__DOT__check_reg__13__rnum = 0;
    IData/*31:0*/ __Vtask_tb__DOT__check_reg__13__actual;
    __Vtask_tb__DOT__check_reg__13__actual = 0;
    IData/*31:0*/ __Vtask_tb__DOT__check_reg__13__expected;
    __Vtask_tb__DOT__check_reg__13__expected = 0;
    // Body
    vlSelf->tb__DOT__RSTN = 0U;
    vlSelf->tb__DOT__stall = 0U;
    vlSelf->tb__DOT__unnamedblk1__DOT__i = 0U;
    while (VL_GTS_III(32, 0x200U, vlSelf->tb__DOT__unnamedblk1__DOT__i)) {
        vlSelf->tb__DOT__imem[(0x1ffU & vlSelf->tb__DOT__unnamedblk1__DOT__i)] = 0x13U;
        vlSelf->tb__DOT__dmem[(0x1ffU & vlSelf->tb__DOT__unnamedblk1__DOT__i)] = 0U;
        vlSelf->tb__DOT__unnamedblk1__DOT__i = ((IData)(1U) 
                                                + vlSelf->tb__DOT__unnamedblk1__DOT__i);
    }
    vlSelf->tb__DOT__imem[0U] = 0x2a00193U;
    vlSelf->tb__DOT__imem[1U] = 0x2a00213U;
    vlSelf->tb__DOT__imem[2U] = 0x13U;
    vlSelf->tb__DOT__imem[3U] = 0x13U;
    vlSelf->tb__DOT__imem[4U] = 0x13U;
    vlSelf->tb__DOT__imem[5U] = 0x13U;
    vlSelf->tb__DOT__imem[6U] = 0x730663U;
    vlSelf->tb__DOT__imem[7U] = 0x6300393U;
    vlSelf->tb__DOT__imem[8U] = 0x6300013U;
    vlSelf->tb__DOT__imem[9U] = 0x100513U;
    vlSelf->tb__DOT__imem[0xcU] = 0xa00193U;
    vlSelf->tb__DOT__imem[0xdU] = 0x1400213U;
    vlSelf->tb__DOT__imem[0xeU] = 0x13U;
    vlSelf->tb__DOT__imem[0xfU] = 0x13U;
    vlSelf->tb__DOT__imem[0x10U] = 0x13U;
    vlSelf->tb__DOT__imem[0x11U] = 0x13U;
    vlSelf->tb__DOT__imem[0x12U] = 0x418863U;
    vlSelf->tb__DOT__imem[0x13U] = 0x100593U;
    vlSelf->tb__DOT__imem[0x14U] = 0x13U;
    vlSelf->tb__DOT__imem[0x15U] = 0x13U;
    vlSelf->tb__DOT__imem[0x16U] = 0x6300593U;
    vlSelf->tb__DOT__imem[0x17U] = 0x13U;
    vlSelf->tb__DOT__imem[0x18U] = 0x500193U;
    vlSelf->tb__DOT__imem[0x19U] = 0xa00213U;
    vlSelf->tb__DOT__imem[0x1aU] = 0x13U;
    vlSelf->tb__DOT__imem[0x1bU] = 0x13U;
    vlSelf->tb__DOT__imem[0x1cU] = 0x13U;
    vlSelf->tb__DOT__imem[0x1dU] = 0x13U;
    vlSelf->tb__DOT__imem[0x1eU] = 0x419663U;
    vlSelf->tb__DOT__imem[0x1fU] = 0x6300013U;
    vlSelf->tb__DOT__imem[0x20U] = 0x6300013U;
    vlSelf->tb__DOT__imem[0x21U] = 0x100613U;
    vlSelf->tb__DOT__imem[0x22U] = 0x13U;
    vlSelf->tb__DOT__imem[0x23U] = 0x13U;
    vlSelf->tb__DOT__imem[0x24U] = 0x700193U;
    vlSelf->tb__DOT__imem[0x25U] = 0x700213U;
    vlSelf->tb__DOT__imem[0x26U] = 0x13U;
    vlSelf->tb__DOT__imem[0x27U] = 0x13U;
    vlSelf->tb__DOT__imem[0x28U] = 0x13U;
    vlSelf->tb__DOT__imem[0x29U] = 0x13U;
    vlSelf->tb__DOT__imem[0x2aU] = 0x419863U;
    vlSelf->tb__DOT__imem[0x2bU] = 0x100693U;
    vlSelf->tb__DOT__imem[0x2cU] = 0x13U;
    vlSelf->tb__DOT__imem[0x2dU] = 0x13U;
    vlSelf->tb__DOT__imem[0x2eU] = 0x6300693U;
    vlSelf->tb__DOT__imem[0x2fU] = 0x13U;
    vlSelf->tb__DOT__imem[0x30U] = 0xfff00193U;
    vlSelf->tb__DOT__imem[0x31U] = 0x100213U;
    vlSelf->tb__DOT__imem[0x32U] = 0x13U;
    vlSelf->tb__DOT__imem[0x33U] = 0x13U;
    vlSelf->tb__DOT__imem[0x34U] = 0x13U;
    vlSelf->tb__DOT__imem[0x35U] = 0x13U;
    vlSelf->tb__DOT__imem[0x36U] = 0x41c663U;
    vlSelf->tb__DOT__imem[0x37U] = 0x6300013U;
    vlSelf->tb__DOT__imem[0x38U] = 0x6300013U;
    vlSelf->tb__DOT__imem[0x39U] = 0x100713U;
    vlSelf->tb__DOT__imem[0x3aU] = 0x13U;
    vlSelf->tb__DOT__imem[0x3bU] = 0x13U;
    vlSelf->tb__DOT__imem[0x3cU] = 0x500193U;
    vlSelf->tb__DOT__imem[0x3dU] = 0x500213U;
    vlSelf->tb__DOT__imem[0x3eU] = 0x13U;
    vlSelf->tb__DOT__imem[0x3fU] = 0x13U;
    vlSelf->tb__DOT__imem[0x40U] = 0x13U;
    vlSelf->tb__DOT__imem[0x41U] = 0x13U;
    vlSelf->tb__DOT__imem[0x42U] = 0x41c863U;
    vlSelf->tb__DOT__imem[0x43U] = 0x100793U;
    vlSelf->tb__DOT__imem[0x44U] = 0x13U;
    vlSelf->tb__DOT__imem[0x45U] = 0x13U;
    vlSelf->tb__DOT__imem[0x46U] = 0x6300793U;
    vlSelf->tb__DOT__imem[0x47U] = 0x13U;
    vlSelf->tb__DOT__imem[0x48U] = 0x100193U;
    vlSelf->tb__DOT__imem[0x49U] = 0xfff00213U;
    vlSelf->tb__DOT__imem[0x4aU] = 0x13U;
    vlSelf->tb__DOT__imem[0x4bU] = 0x13U;
    vlSelf->tb__DOT__imem[0x4cU] = 0x13U;
    vlSelf->tb__DOT__imem[0x4dU] = 0x13U;
    vlSelf->tb__DOT__imem[0x4eU] = 0x41d663U;
    vlSelf->tb__DOT__imem[0x4fU] = 0x6300013U;
    vlSelf->tb__DOT__imem[0x50U] = 0x6300013U;
    vlSelf->tb__DOT__imem[0x51U] = 0x100813U;
    vlSelf->tb__DOT__imem[0x52U] = 0x13U;
    vlSelf->tb__DOT__imem[0x53U] = 0x13U;
    vlSelf->tb__DOT__imem[0x54U] = 0xfff00193U;
    vlSelf->tb__DOT__imem[0x55U] = 0x100213U;
    vlSelf->tb__DOT__imem[0x56U] = 0x13U;
    vlSelf->tb__DOT__imem[0x57U] = 0x13U;
    vlSelf->tb__DOT__imem[0x58U] = 0x13U;
    vlSelf->tb__DOT__imem[0x59U] = 0x13U;
    vlSelf->tb__DOT__imem[0x5aU] = 0x41d863U;
    vlSelf->tb__DOT__imem[0x5bU] = 0x100893U;
    vlSelf->tb__DOT__imem[0x5cU] = 0x13U;
    vlSelf->tb__DOT__imem[0x5dU] = 0x13U;
    vlSelf->tb__DOT__imem[0x5eU] = 0x6300893U;
    vlSelf->tb__DOT__imem[0x5fU] = 0x13U;
    vlSelf->tb__DOT__imem[0x60U] = 0x100193U;
    vlSelf->tb__DOT__imem[0x61U] = 0xfff00213U;
    vlSelf->tb__DOT__imem[0x62U] = 0x13U;
    vlSelf->tb__DOT__imem[0x63U] = 0x13U;
    vlSelf->tb__DOT__imem[0x64U] = 0x13U;
    vlSelf->tb__DOT__imem[0x65U] = 0x13U;
    vlSelf->tb__DOT__imem[0x66U] = 0x41e663U;
    vlSelf->tb__DOT__imem[0x67U] = 0x6300013U;
    vlSelf->tb__DOT__imem[0x68U] = 0x6300013U;
    vlSelf->tb__DOT__imem[0x69U] = 0x100913U;
    vlSelf->tb__DOT__imem[0x6aU] = 0x13U;
    vlSelf->tb__DOT__imem[0x6bU] = 0x13U;
    vlSelf->tb__DOT__imem[0x6cU] = 0xfff00193U;
    vlSelf->tb__DOT__imem[0x6dU] = 0x100213U;
    vlSelf->tb__DOT__imem[0x6eU] = 0x13U;
    vlSelf->tb__DOT__imem[0x6fU] = 0x13U;
    vlSelf->tb__DOT__imem[0x70U] = 0x13U;
    vlSelf->tb__DOT__imem[0x71U] = 0x13U;
    vlSelf->tb__DOT__imem[0x72U] = 0x41e863U;
    vlSelf->tb__DOT__imem[0x73U] = 0x100993U;
    vlSelf->tb__DOT__imem[0x74U] = 0x13U;
    vlSelf->tb__DOT__imem[0x75U] = 0x13U;
    vlSelf->tb__DOT__imem[0x76U] = 0x6300993U;
    vlSelf->tb__DOT__imem[0x77U] = 0x13U;
    vlSelf->tb__DOT__imem[0x78U] = 0xfff00193U;
    vlSelf->tb__DOT__imem[0x79U] = 0x100213U;
    vlSelf->tb__DOT__imem[0x7aU] = 0x13U;
    vlSelf->tb__DOT__imem[0x7bU] = 0x13U;
    vlSelf->tb__DOT__imem[0x7cU] = 0x13U;
    vlSelf->tb__DOT__imem[0x7dU] = 0x13U;
    vlSelf->tb__DOT__imem[0x7eU] = 0x41f663U;
    vlSelf->tb__DOT__imem[0x7fU] = 0x6300113U;
    vlSelf->tb__DOT__imem[0x80U] = 0x6300f13U;
    vlSelf->tb__DOT__imem[0x81U] = 0x100a13U;
    vlSelf->tb__DOT__imem[0x82U] = 0x13U;
    vlSelf->tb__DOT__imem[0x83U] = 0x13U;
    vlSelf->tb__DOT__imem[0x84U] = 0x100193U;
    vlSelf->tb__DOT__imem[0x85U] = 0xfff00213U;
    vlSelf->tb__DOT__imem[0x86U] = 0x13U;
    vlSelf->tb__DOT__imem[0x87U] = 0x13U;
    vlSelf->tb__DOT__imem[0x88U] = 0x13U;
    vlSelf->tb__DOT__imem[0x89U] = 0x13U;
    vlSelf->tb__DOT__imem[0x8aU] = 0x41f863U;
    vlSelf->tb__DOT__imem[0x8bU] = 0x100a93U;
    vlSelf->tb__DOT__imem[0x8cU] = 0x13U;
    vlSelf->tb__DOT__imem[0x8dU] = 0x13U;
    vlSelf->tb__DOT__imem[0x8eU] = 0x6300a93U;
    vlSelf->tb__DOT__imem[0x8fU] = 0x13U;
    vlSelf->tb__DOT__imem[0x90U] = 0xc000efU;
    vlSelf->tb__DOT__imem[0x91U] = 0x6300113U;
    vlSelf->tb__DOT__imem[0x92U] = 0x6300f13U;
    vlSelf->tb__DOT__imem[0x93U] = 0x13U;
    vlSelf->tb__DOT__imem[0x94U] = 0x6300393U;
    vlSelf->tb__DOT__imem[0x95U] = 0x13U;
    vlSelf->tb__DOT__imem[0x96U] = 0x13U;
    vlSelf->tb__DOT__imem[0x97U] = 0x13U;
    vlSelf->tb__DOT__imem[0x9cU] = 0x27d00193U;
    vlSelf->tb__DOT__imem[0x9dU] = 0x18167U;
    vlSelf->tb__DOT__imem[0x9eU] = 0x6300113U;
    vlSelf->tb__DOT__imem[0x9fU] = 0x13U;
    vlSelf->tb__DOT__imem[0xa0U] = 0x10bb3U;
    vlSelf->tb__DOT__imem[0xa1U] = 0x13U;
    vlSelf->tb__DOT__imem[0xa2U] = 0x13U;
    vlSelf->tb__DOT__imem[0xa3U] = 0x13U;
    VL_WRITEF("\n[%0t] =============================================\n[%0t]  Branch-Only Pipeline Testbench Starting\n[%0t] =============================================\n\n",
              64,VL_TIME_UNITED_Q(1000),-9,64,VL_TIME_UNITED_Q(1000),
              -9,64,VL_TIME_UNITED_Q(1000),-9);
    co_await vlSelf->__VdlySched.delay(0x3a98ULL, nullptr, 
                                       "tb.sv", 534);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->tb__DOT__RSTN = 1U;
    co_await vlSelf->__VdlySched.delay(0x3d090ULL, 
                                       nullptr, "tb.sv", 
                                       540);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    VL_WRITEF("==================================================\n        BRANCH TEST RESULTS\n==================================================\n\n--- BEQ --- [%0t]\n",
              64,VL_TIME_UNITED_Q(1000),-9);
    __Vtask_tb__DOT__check_reg__0__expected = 1U;
    __Vtask_tb__DOT__check_reg__0__actual = vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers
        [9U];
    __Vtask_tb__DOT__check_reg__0__rnum = 0xaU;
    __Vtask_tb__DOT__check_reg__0__label = std::string{"BEQ  taken   (x3==x4)"};
    if ((__Vtask_tb__DOT__check_reg__0__actual == __Vtask_tb__DOT__check_reg__0__expected)) {
        VL_WRITEF("[PASS] %-30@ x%02d = 0x%08x\n",-1,
                  &(__Vtask_tb__DOT__check_reg__0__label),
                  32,__Vtask_tb__DOT__check_reg__0__rnum,
                  32,__Vtask_tb__DOT__check_reg__0__actual);
        vlSelf->tb__DOT__pass_count = ((IData)(1U) 
                                       + vlSelf->tb__DOT__pass_count);
    } else {
        VL_WRITEF("[FAIL] %-30@ x%02d  expected 0x%08x  got 0x%08x\n",
                  -1,&(__Vtask_tb__DOT__check_reg__0__label),
                  32,__Vtask_tb__DOT__check_reg__0__rnum,
                  32,__Vtask_tb__DOT__check_reg__0__expected,
                  32,__Vtask_tb__DOT__check_reg__0__actual);
        vlSelf->tb__DOT__fail_count = ((IData)(1U) 
                                       + vlSelf->tb__DOT__fail_count);
    }
    __Vtask_tb__DOT__check_reg__1__expected = 1U;
    __Vtask_tb__DOT__check_reg__1__actual = vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers
        [0xaU];
    __Vtask_tb__DOT__check_reg__1__rnum = 0xbU;
    __Vtask_tb__DOT__check_reg__1__label = std::string{"BEQ  not-taken (x3!=x4)"};
    if ((__Vtask_tb__DOT__check_reg__1__actual == __Vtask_tb__DOT__check_reg__1__expected)) {
        VL_WRITEF("[PASS] %-30@ x%02d = 0x%08x\n",-1,
                  &(__Vtask_tb__DOT__check_reg__1__label),
                  32,__Vtask_tb__DOT__check_reg__1__rnum,
                  32,__Vtask_tb__DOT__check_reg__1__actual);
        vlSelf->tb__DOT__pass_count = ((IData)(1U) 
                                       + vlSelf->tb__DOT__pass_count);
    } else {
        VL_WRITEF("[FAIL] %-30@ x%02d  expected 0x%08x  got 0x%08x\n",
                  -1,&(__Vtask_tb__DOT__check_reg__1__label),
                  32,__Vtask_tb__DOT__check_reg__1__rnum,
                  32,__Vtask_tb__DOT__check_reg__1__expected,
                  32,__Vtask_tb__DOT__check_reg__1__actual);
        vlSelf->tb__DOT__fail_count = ((IData)(1U) 
                                       + vlSelf->tb__DOT__fail_count);
    }
    co_await vlSelf->__VdlySched.delay(0x41eb0ULL, 
                                       nullptr, "tb.sv", 
                                       553);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    VL_WRITEF("\n--- BNE --- [%0t]\n",64,VL_TIME_UNITED_Q(1000),
              -9);
    __Vtask_tb__DOT__check_reg__2__expected = 1U;
    __Vtask_tb__DOT__check_reg__2__actual = vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers
        [0xbU];
    __Vtask_tb__DOT__check_reg__2__rnum = 0xcU;
    __Vtask_tb__DOT__check_reg__2__label = std::string{"BNE  taken   (x3!=x4)"};
    if ((__Vtask_tb__DOT__check_reg__2__actual == __Vtask_tb__DOT__check_reg__2__expected)) {
        VL_WRITEF("[PASS] %-30@ x%02d = 0x%08x\n",-1,
                  &(__Vtask_tb__DOT__check_reg__2__label),
                  32,__Vtask_tb__DOT__check_reg__2__rnum,
                  32,__Vtask_tb__DOT__check_reg__2__actual);
        vlSelf->tb__DOT__pass_count = ((IData)(1U) 
                                       + vlSelf->tb__DOT__pass_count);
    } else {
        VL_WRITEF("[FAIL] %-30@ x%02d  expected 0x%08x  got 0x%08x\n",
                  -1,&(__Vtask_tb__DOT__check_reg__2__label),
                  32,__Vtask_tb__DOT__check_reg__2__rnum,
                  32,__Vtask_tb__DOT__check_reg__2__expected,
                  32,__Vtask_tb__DOT__check_reg__2__actual);
        vlSelf->tb__DOT__fail_count = ((IData)(1U) 
                                       + vlSelf->tb__DOT__fail_count);
    }
    __Vtask_tb__DOT__check_reg__3__expected = 1U;
    __Vtask_tb__DOT__check_reg__3__actual = vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers
        [0xcU];
    __Vtask_tb__DOT__check_reg__3__rnum = 0xdU;
    __Vtask_tb__DOT__check_reg__3__label = std::string{"BNE  not-taken (x3==x4)"};
    if ((__Vtask_tb__DOT__check_reg__3__actual == __Vtask_tb__DOT__check_reg__3__expected)) {
        VL_WRITEF("[PASS] %-30@ x%02d = 0x%08x\n",-1,
                  &(__Vtask_tb__DOT__check_reg__3__label),
                  32,__Vtask_tb__DOT__check_reg__3__rnum,
                  32,__Vtask_tb__DOT__check_reg__3__actual);
        vlSelf->tb__DOT__pass_count = ((IData)(1U) 
                                       + vlSelf->tb__DOT__pass_count);
    } else {
        VL_WRITEF("[FAIL] %-30@ x%02d  expected 0x%08x  got 0x%08x\n",
                  -1,&(__Vtask_tb__DOT__check_reg__3__label),
                  32,__Vtask_tb__DOT__check_reg__3__rnum,
                  32,__Vtask_tb__DOT__check_reg__3__expected,
                  32,__Vtask_tb__DOT__check_reg__3__actual);
        vlSelf->tb__DOT__fail_count = ((IData)(1U) 
                                       + vlSelf->tb__DOT__fail_count);
    }
    co_await vlSelf->__VdlySched.delay(0x3f7a0ULL, 
                                       nullptr, "tb.sv", 
                                       558);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    VL_WRITEF("\n--- BLT (signed) --- [%0t]\n",64,VL_TIME_UNITED_Q(1000),
              -9);
    __Vtask_tb__DOT__check_reg__4__expected = 1U;
    __Vtask_tb__DOT__check_reg__4__actual = vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers
        [0xdU];
    __Vtask_tb__DOT__check_reg__4__rnum = 0xeU;
    __Vtask_tb__DOT__check_reg__4__label = std::string{"BLT  taken   (-1 < 1)"};
    if ((__Vtask_tb__DOT__check_reg__4__actual == __Vtask_tb__DOT__check_reg__4__expected)) {
        VL_WRITEF("[PASS] %-30@ x%02d = 0x%08x\n",-1,
                  &(__Vtask_tb__DOT__check_reg__4__label),
                  32,__Vtask_tb__DOT__check_reg__4__rnum,
                  32,__Vtask_tb__DOT__check_reg__4__actual);
        vlSelf->tb__DOT__pass_count = ((IData)(1U) 
                                       + vlSelf->tb__DOT__pass_count);
    } else {
        VL_WRITEF("[FAIL] %-30@ x%02d  expected 0x%08x  got 0x%08x\n",
                  -1,&(__Vtask_tb__DOT__check_reg__4__label),
                  32,__Vtask_tb__DOT__check_reg__4__rnum,
                  32,__Vtask_tb__DOT__check_reg__4__expected,
                  32,__Vtask_tb__DOT__check_reg__4__actual);
        vlSelf->tb__DOT__fail_count = ((IData)(1U) 
                                       + vlSelf->tb__DOT__fail_count);
    }
    __Vtask_tb__DOT__check_reg__5__expected = 1U;
    __Vtask_tb__DOT__check_reg__5__actual = vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers
        [0xeU];
    __Vtask_tb__DOT__check_reg__5__rnum = 0xfU;
    __Vtask_tb__DOT__check_reg__5__label = std::string{"BLT  not-taken (5 >= 5)"};
    if ((__Vtask_tb__DOT__check_reg__5__actual == __Vtask_tb__DOT__check_reg__5__expected)) {
        VL_WRITEF("[PASS] %-30@ x%02d = 0x%08x\n",-1,
                  &(__Vtask_tb__DOT__check_reg__5__label),
                  32,__Vtask_tb__DOT__check_reg__5__rnum,
                  32,__Vtask_tb__DOT__check_reg__5__actual);
        vlSelf->tb__DOT__pass_count = ((IData)(1U) 
                                       + vlSelf->tb__DOT__pass_count);
    } else {
        VL_WRITEF("[FAIL] %-30@ x%02d  expected 0x%08x  got 0x%08x\n",
                  -1,&(__Vtask_tb__DOT__check_reg__5__label),
                  32,__Vtask_tb__DOT__check_reg__5__rnum,
                  32,__Vtask_tb__DOT__check_reg__5__expected,
                  32,__Vtask_tb__DOT__check_reg__5__actual);
        vlSelf->tb__DOT__fail_count = ((IData)(1U) 
                                       + vlSelf->tb__DOT__fail_count);
    }
    co_await vlSelf->__VdlySched.delay(0x3f7a0ULL, 
                                       nullptr, "tb.sv", 
                                       563);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    VL_WRITEF("\n--- BGE (signed) --- [%0t]\n",64,VL_TIME_UNITED_Q(1000),
              -9);
    __Vtask_tb__DOT__check_reg__6__expected = 1U;
    __Vtask_tb__DOT__check_reg__6__actual = vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers
        [0xfU];
    __Vtask_tb__DOT__check_reg__6__rnum = 0x10U;
    __Vtask_tb__DOT__check_reg__6__label = std::string{"BGE  taken   (1 >= -1)"};
    if ((__Vtask_tb__DOT__check_reg__6__actual == __Vtask_tb__DOT__check_reg__6__expected)) {
        VL_WRITEF("[PASS] %-30@ x%02d = 0x%08x\n",-1,
                  &(__Vtask_tb__DOT__check_reg__6__label),
                  32,__Vtask_tb__DOT__check_reg__6__rnum,
                  32,__Vtask_tb__DOT__check_reg__6__actual);
        vlSelf->tb__DOT__pass_count = ((IData)(1U) 
                                       + vlSelf->tb__DOT__pass_count);
    } else {
        VL_WRITEF("[FAIL] %-30@ x%02d  expected 0x%08x  got 0x%08x\n",
                  -1,&(__Vtask_tb__DOT__check_reg__6__label),
                  32,__Vtask_tb__DOT__check_reg__6__rnum,
                  32,__Vtask_tb__DOT__check_reg__6__expected,
                  32,__Vtask_tb__DOT__check_reg__6__actual);
        vlSelf->tb__DOT__fail_count = ((IData)(1U) 
                                       + vlSelf->tb__DOT__fail_count);
    }
    __Vtask_tb__DOT__check_reg__7__expected = 1U;
    __Vtask_tb__DOT__check_reg__7__actual = vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers
        [0x10U];
    __Vtask_tb__DOT__check_reg__7__rnum = 0x11U;
    __Vtask_tb__DOT__check_reg__7__label = std::string{"BGE  not-taken (-1 < 1)"};
    if ((__Vtask_tb__DOT__check_reg__7__actual == __Vtask_tb__DOT__check_reg__7__expected)) {
        VL_WRITEF("[PASS] %-30@ x%02d = 0x%08x\n",-1,
                  &(__Vtask_tb__DOT__check_reg__7__label),
                  32,__Vtask_tb__DOT__check_reg__7__rnum,
                  32,__Vtask_tb__DOT__check_reg__7__actual);
        vlSelf->tb__DOT__pass_count = ((IData)(1U) 
                                       + vlSelf->tb__DOT__pass_count);
    } else {
        VL_WRITEF("[FAIL] %-30@ x%02d  expected 0x%08x  got 0x%08x\n",
                  -1,&(__Vtask_tb__DOT__check_reg__7__label),
                  32,__Vtask_tb__DOT__check_reg__7__rnum,
                  32,__Vtask_tb__DOT__check_reg__7__expected,
                  32,__Vtask_tb__DOT__check_reg__7__actual);
        vlSelf->tb__DOT__fail_count = ((IData)(1U) 
                                       + vlSelf->tb__DOT__fail_count);
    }
    co_await vlSelf->__VdlySched.delay(0x3f7a0ULL, 
                                       nullptr, "tb.sv", 
                                       568);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    VL_WRITEF("\n--- BLTU (unsigned) --- [%0t]\n",64,
              VL_TIME_UNITED_Q(1000),-9);
    __Vtask_tb__DOT__check_reg__8__expected = 1U;
    __Vtask_tb__DOT__check_reg__8__actual = vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers
        [0x11U];
    __Vtask_tb__DOT__check_reg__8__rnum = 0x12U;
    __Vtask_tb__DOT__check_reg__8__label = std::string{"BLTU taken   (1 < 0xFFFF...)"};
    if ((__Vtask_tb__DOT__check_reg__8__actual == __Vtask_tb__DOT__check_reg__8__expected)) {
        VL_WRITEF("[PASS] %-30@ x%02d = 0x%08x\n",-1,
                  &(__Vtask_tb__DOT__check_reg__8__label),
                  32,__Vtask_tb__DOT__check_reg__8__rnum,
                  32,__Vtask_tb__DOT__check_reg__8__actual);
        vlSelf->tb__DOT__pass_count = ((IData)(1U) 
                                       + vlSelf->tb__DOT__pass_count);
    } else {
        VL_WRITEF("[FAIL] %-30@ x%02d  expected 0x%08x  got 0x%08x\n",
                  -1,&(__Vtask_tb__DOT__check_reg__8__label),
                  32,__Vtask_tb__DOT__check_reg__8__rnum,
                  32,__Vtask_tb__DOT__check_reg__8__expected,
                  32,__Vtask_tb__DOT__check_reg__8__actual);
        vlSelf->tb__DOT__fail_count = ((IData)(1U) 
                                       + vlSelf->tb__DOT__fail_count);
    }
    __Vtask_tb__DOT__check_reg__9__expected = 1U;
    __Vtask_tb__DOT__check_reg__9__actual = vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers
        [0x12U];
    __Vtask_tb__DOT__check_reg__9__rnum = 0x13U;
    __Vtask_tb__DOT__check_reg__9__label = std::string{"BLTU not-taken (0xFFFF... >= 1)"};
    if ((__Vtask_tb__DOT__check_reg__9__actual == __Vtask_tb__DOT__check_reg__9__expected)) {
        VL_WRITEF("[PASS] %-30@ x%02d = 0x%08x\n",-1,
                  &(__Vtask_tb__DOT__check_reg__9__label),
                  32,__Vtask_tb__DOT__check_reg__9__rnum,
                  32,__Vtask_tb__DOT__check_reg__9__actual);
        vlSelf->tb__DOT__pass_count = ((IData)(1U) 
                                       + vlSelf->tb__DOT__pass_count);
    } else {
        VL_WRITEF("[FAIL] %-30@ x%02d  expected 0x%08x  got 0x%08x\n",
                  -1,&(__Vtask_tb__DOT__check_reg__9__label),
                  32,__Vtask_tb__DOT__check_reg__9__rnum,
                  32,__Vtask_tb__DOT__check_reg__9__expected,
                  32,__Vtask_tb__DOT__check_reg__9__actual);
        vlSelf->tb__DOT__fail_count = ((IData)(1U) 
                                       + vlSelf->tb__DOT__fail_count);
    }
    co_await vlSelf->__VdlySched.delay(0x3f7a0ULL, 
                                       nullptr, "tb.sv", 
                                       573);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    VL_WRITEF("\n--- BGEU (unsigned) --- [%0t]\n",64,
              VL_TIME_UNITED_Q(1000),-9);
    __Vtask_tb__DOT__check_reg__10__expected = 1U;
    __Vtask_tb__DOT__check_reg__10__actual = vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers
        [0x13U];
    __Vtask_tb__DOT__check_reg__10__rnum = 0x14U;
    __Vtask_tb__DOT__check_reg__10__label = std::string{"BGEU taken   (0xFFFF... >= 1)"};
    if ((__Vtask_tb__DOT__check_reg__10__actual == __Vtask_tb__DOT__check_reg__10__expected)) {
        VL_WRITEF("[PASS] %-30@ x%02d = 0x%08x\n",-1,
                  &(__Vtask_tb__DOT__check_reg__10__label),
                  32,__Vtask_tb__DOT__check_reg__10__rnum,
                  32,__Vtask_tb__DOT__check_reg__10__actual);
        vlSelf->tb__DOT__pass_count = ((IData)(1U) 
                                       + vlSelf->tb__DOT__pass_count);
    } else {
        VL_WRITEF("[FAIL] %-30@ x%02d  expected 0x%08x  got 0x%08x\n",
                  -1,&(__Vtask_tb__DOT__check_reg__10__label),
                  32,__Vtask_tb__DOT__check_reg__10__rnum,
                  32,__Vtask_tb__DOT__check_reg__10__expected,
                  32,__Vtask_tb__DOT__check_reg__10__actual);
        vlSelf->tb__DOT__fail_count = ((IData)(1U) 
                                       + vlSelf->tb__DOT__fail_count);
    }
    __Vtask_tb__DOT__check_reg__11__expected = 1U;
    __Vtask_tb__DOT__check_reg__11__actual = vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers
        [0x14U];
    __Vtask_tb__DOT__check_reg__11__rnum = 0x15U;
    __Vtask_tb__DOT__check_reg__11__label = std::string{"BGEU not-taken (1 < 0xFFFF...)"};
    if ((__Vtask_tb__DOT__check_reg__11__actual == __Vtask_tb__DOT__check_reg__11__expected)) {
        VL_WRITEF("[PASS] %-30@ x%02d = 0x%08x\n",-1,
                  &(__Vtask_tb__DOT__check_reg__11__label),
                  32,__Vtask_tb__DOT__check_reg__11__rnum,
                  32,__Vtask_tb__DOT__check_reg__11__actual);
        vlSelf->tb__DOT__pass_count = ((IData)(1U) 
                                       + vlSelf->tb__DOT__pass_count);
    } else {
        VL_WRITEF("[FAIL] %-30@ x%02d  expected 0x%08x  got 0x%08x\n",
                  -1,&(__Vtask_tb__DOT__check_reg__11__label),
                  32,__Vtask_tb__DOT__check_reg__11__rnum,
                  32,__Vtask_tb__DOT__check_reg__11__expected,
                  32,__Vtask_tb__DOT__check_reg__11__actual);
        vlSelf->tb__DOT__fail_count = ((IData)(1U) 
                                       + vlSelf->tb__DOT__fail_count);
    }
    co_await vlSelf->__VdlySched.delay(0x927c0ULL, 
                                       nullptr, "tb.sv", 
                                       578);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    VL_WRITEF("\n--- JAL ---\n");
    __Vtask_tb__DOT__check_reg__12__expected = 0x244U;
    __Vtask_tb__DOT__check_reg__12__actual = vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers
        [0U];
    __Vtask_tb__DOT__check_reg__12__rnum = 1U;
    __Vtask_tb__DOT__check_reg__12__label = std::string{"JAL  link addr in x1"};
    if ((__Vtask_tb__DOT__check_reg__12__actual == __Vtask_tb__DOT__check_reg__12__expected)) {
        VL_WRITEF("[PASS] %-30@ x%02d = 0x%08x\n",-1,
                  &(__Vtask_tb__DOT__check_reg__12__label),
                  32,__Vtask_tb__DOT__check_reg__12__rnum,
                  32,__Vtask_tb__DOT__check_reg__12__actual);
        vlSelf->tb__DOT__pass_count = ((IData)(1U) 
                                       + vlSelf->tb__DOT__pass_count);
    } else {
        VL_WRITEF("[FAIL] %-30@ x%02d  expected 0x%08x  got 0x%08x\n",
                  -1,&(__Vtask_tb__DOT__check_reg__12__label),
                  32,__Vtask_tb__DOT__check_reg__12__rnum,
                  32,__Vtask_tb__DOT__check_reg__12__expected,
                  32,__Vtask_tb__DOT__check_reg__12__actual);
        vlSelf->tb__DOT__fail_count = ((IData)(1U) 
                                       + vlSelf->tb__DOT__fail_count);
    }
    VL_WRITEF("\n--- JALR (LSB clearing) ---\n");
    __Vtask_tb__DOT__check_reg__13__expected = 0x278U;
    __Vtask_tb__DOT__check_reg__13__actual = vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers
        [0x16U];
    __Vtask_tb__DOT__check_reg__13__rnum = 0x17U;
    __Vtask_tb__DOT__check_reg__13__label = std::string{"JALR link addr in x23"};
    if ((__Vtask_tb__DOT__check_reg__13__actual == __Vtask_tb__DOT__check_reg__13__expected)) {
        VL_WRITEF("[PASS] %-30@ x%02d = 0x%08x\n",-1,
                  &(__Vtask_tb__DOT__check_reg__13__label),
                  32,__Vtask_tb__DOT__check_reg__13__rnum,
                  32,__Vtask_tb__DOT__check_reg__13__actual);
        vlSelf->tb__DOT__pass_count = ((IData)(1U) 
                                       + vlSelf->tb__DOT__pass_count);
    } else {
        VL_WRITEF("[FAIL] %-30@ x%02d  expected 0x%08x  got 0x%08x\n",
                  -1,&(__Vtask_tb__DOT__check_reg__13__label),
                  32,__Vtask_tb__DOT__check_reg__13__rnum,
                  32,__Vtask_tb__DOT__check_reg__13__expected,
                  32,__Vtask_tb__DOT__check_reg__13__actual);
        vlSelf->tb__DOT__fail_count = ((IData)(1U) 
                                       + vlSelf->tb__DOT__fail_count);
    }
    VL_WRITEF("\n==================================================\n  TOTAL: %0d passed, %0d failed out of %0d\n",
              32,vlSelf->tb__DOT__pass_count,32,vlSelf->tb__DOT__fail_count,
              32,(vlSelf->tb__DOT__pass_count + vlSelf->tb__DOT__fail_count));
    if ((0U == vlSelf->tb__DOT__fail_count)) {
        VL_WRITEF("  *** ALL BRANCH TESTS PASSED ***\n");
    } else {
        VL_WRITEF("  *** %0d TEST(S) FAILED ***\n",
                  32,vlSelf->tb__DOT__fail_count);
    }
    VL_WRITEF("==================================================\n\n");
    VL_FINISH_MT("tb.sv", 599, "");
    vlSelf->__Vm_traceActivity[2U] = 1U;
}

VL_INLINE_OPT void Vtb___024root___act_sequent__TOP__0(Vtb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___act_sequent__TOP__0\n"); );
    // Body
    vlSelf->tb__DOT__dut__DOT__PC_update = 1U;
    vlSelf->tb__DOT__dut__DOT__IFID_write = 1U;
    vlSelf->tb__DOT__dut__DOT__IDEX_delay = 0U;
    if (((0x1fU & (vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID 
                   >> 0xfU)) == (IData)(vlSelf->tb__DOT__dut__DOT__rs1_EX))) {
        vlSelf->tb__DOT__dut__DOT__ForwardID_A = 0U;
    }
    if (vlSelf->tb__DOT__RSTN) {
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
    } else {
        vlSelf->tb__DOT__dut__DOT__PC_update = 1U;
        vlSelf->tb__DOT__dut__DOT__IFID_write = 1U;
        vlSelf->tb__DOT__dut__DOT__IDEX_delay = 0U;
        vlSelf->tb__DOT__dut__DOT__ForwardID_A = 0U;
    }
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

void Vtb___024root___eval_act(Vtb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_act\n"); );
    // Body
    if ((8ULL & vlSelf->__VactTriggered.word(0U))) {
        Vtb___024root___act_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[3U] = 1U;
    }
}

VL_INLINE_OPT void Vtb___024root___nba_sequent__TOP__0(Vtb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_sequent__TOP__0\n"); );
    // Init
    IData/*31:0*/ __Vdly__tb__DOT__dut__DOT____Vcellout__IFID_stage__instructionAddress_ID;
    __Vdly__tb__DOT__dut__DOT____Vcellout__IFID_stage__instructionAddress_ID = 0;
    CData/*1:0*/ __Vdly__tb__DOT__dut__DOT__branchPredictor__DOT__saturationCounter;
    __Vdly__tb__DOT__dut__DOT__branchPredictor__DOT__saturationCounter = 0;
    // Body
    __Vdly__tb__DOT__dut__DOT____Vcellout__IFID_stage__instructionAddress_ID 
        = vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instructionAddress_ID;
    vlSelf->__Vdly__tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID 
        = vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID;
    __Vdly__tb__DOT__dut__DOT__branchPredictor__DOT__saturationCounter 
        = vlSelf->tb__DOT__dut__DOT__branchPredictor__DOT__saturationCounter;
    if (vlSelf->tb__DOT__RSTN) {
        if ((((IData)(vlSelf->tb__DOT__dut__DOT____Vcellinp__hazardDetection__IDEX_memread) 
              & (((0x1fU & (vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID 
                            >> 0xfU)) == (IData)(vlSelf->tb__DOT__dut__DOT__rd_EX)) 
                 | ((0x1fU & (vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID 
                              >> 0x14U)) == (IData)(vlSelf->tb__DOT__dut__DOT__rd_EX)))) 
             & (3U == (0x7fU & vlSelf->tb__DOT__dut__DOT____Vcellinp__IFID_stage__instruction_IF)))) {
            vlSelf->tb__DOT__dut__DOT__hazardDetection__DOT__loadCounter 
                = ((2U > (IData)(vlSelf->tb__DOT__dut__DOT__hazardDetection__DOT__loadCounter))
                    ? (3U & ((IData)(1U) + (IData)(vlSelf->tb__DOT__dut__DOT__hazardDetection__DOT__loadCounter)))
                    : 0U);
        }
        if (vlSelf->tb__DOT__dut__DOT__pipelineFlush) {
            __Vdly__tb__DOT__dut__DOT____Vcellout__IFID_stage__instructionAddress_ID 
                = vlSelf->tb__DOT__instructionAddress;
            vlSelf->__Vdly__tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID = 0x13U;
        } else if (vlSelf->tb__DOT__dut__DOT__IFID_write) {
            __Vdly__tb__DOT__dut__DOT____Vcellout__IFID_stage__instructionAddress_ID 
                = vlSelf->tb__DOT__instructionAddress;
            vlSelf->__Vdly__tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID 
                = vlSelf->tb__DOT__dut__DOT____Vcellinp__IFID_stage__instruction_IF;
        } else {
            __Vdly__tb__DOT__dut__DOT____Vcellout__IFID_stage__instructionAddress_ID 
                = vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instructionAddress_ID;
            vlSelf->__Vdly__tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID 
                = vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID;
        }
        if (vlSelf->tb__DOT__dut__DOT__branchPredictor__DOT__req_delay2) {
            if (((IData)(vlSelf->tb__DOT__dut__DOT__branchPredictor__DOT__branchTaken_delay1) 
                 & (3U != (IData)(vlSelf->tb__DOT__dut__DOT__branchPredictor__DOT__saturationCounter)))) {
                __Vdly__tb__DOT__dut__DOT__branchPredictor__DOT__saturationCounter 
                    = (3U & ((IData)(1U) + (IData)(vlSelf->tb__DOT__dut__DOT__branchPredictor__DOT__saturationCounter)));
            } else if (((~ (IData)(vlSelf->tb__DOT__dut__DOT__branchPredictor__DOT__branchTaken_delay1)) 
                        & (0U != (IData)(vlSelf->tb__DOT__dut__DOT__branchPredictor__DOT__saturationCounter)))) {
                __Vdly__tb__DOT__dut__DOT__branchPredictor__DOT__saturationCounter 
                    = (3U & ((IData)(vlSelf->tb__DOT__dut__DOT__branchPredictor__DOT__saturationCounter) 
                             - (IData)(1U)));
            }
        }
        vlSelf->tb__DOT__dut__DOT__writeSource_WB = vlSelf->tb__DOT__dut__DOT__writeSource_MEM;
        vlSelf->tb__DOT__dut__DOT__instructionAddress_WB 
            = vlSelf->tb__DOT__dut__DOT__instructionAddress_MEM;
        vlSelf->tb__DOT__dut__DOT__address_WB = vlSelf->tb__DOT__dut__DOT__address_MEM;
        vlSelf->tb__DOT__dut__DOT__memToRegData_WB 
            = ((0U == (IData)(vlSelf->tb__DOT__dut__DOT__memoryOpSize_MEM))
                ? ((((IData)(vlSelf->tb__DOT__dut__DOT__unsignedLoad_MEM)
                      ? 0U : (0xffffffU & (- (IData)(
                                                     (1U 
                                                      & (VL_SHIFTR_III(32,32,32, vlSelf->tb__DOT__memReadData, 
                                                                       VL_SHIFTL_III(32,32,32, 
                                                                                (3U 
                                                                                & vlSelf->tb__DOT__dut__DOT__address_MEM), 3U)) 
                                                         >> 7U)))))) 
                    << 8U) | (0xffU & VL_SHIFTR_III(8,32,32, vlSelf->tb__DOT__memReadData, 
                                                    VL_SHIFTL_III(32,32,32, 
                                                                  (3U 
                                                                   & vlSelf->tb__DOT__dut__DOT__address_MEM), 3U))))
                : ((1U == (IData)(vlSelf->tb__DOT__dut__DOT__memoryOpSize_MEM))
                    ? ((((IData)(vlSelf->tb__DOT__dut__DOT__unsignedLoad_MEM)
                          ? 0U : (0xffffU & (- (IData)(
                                                       (1U 
                                                        & (VL_SHIFTR_III(32,32,32, vlSelf->tb__DOT__memReadData, 
                                                                         VL_SHIFTL_III(32,32,32, 
                                                                                (1U 
                                                                                & (vlSelf->tb__DOT__dut__DOT__address_MEM 
                                                                                >> 1U)), 4U)) 
                                                           >> 0xfU)))))) 
                        << 0x10U) | (0xffffU & VL_SHIFTR_III(16,32,32, vlSelf->tb__DOT__memReadData, 
                                                             VL_SHIFTL_III(32,32,32, 
                                                                           (1U 
                                                                            & (vlSelf->tb__DOT__dut__DOT__address_MEM 
                                                                               >> 1U)), 4U))))
                    : ((2U == (IData)(vlSelf->tb__DOT__dut__DOT__memoryOpSize_MEM))
                        ? vlSelf->tb__DOT__memReadData
                        : 0U)));
        if (((IData)(vlSelf->tb__DOT__dut__DOT__IFID_write) 
             & (IData)(vlSelf->tb__DOT__dut__DOT__PC_update))) {
            vlSelf->tb__DOT__instructionAddress = vlSelf->tb__DOT__dut__DOT__programCounter__DOT__addrNext;
        }
        vlSelf->tb__DOT__dut__DOT__writeSource_MEM 
            = vlSelf->tb__DOT__dut__DOT__writeSource_EX;
        vlSelf->tb__DOT__dut__DOT__instructionAddress_MEM 
            = vlSelf->tb__DOT__dut__DOT__instructionAddress_EX;
        if (((IData)(vlSelf->tb__DOT__dut__DOT__pipelineFlush) 
             | (IData)(vlSelf->tb__DOT__dut__DOT__IDEX_delay))) {
            vlSelf->tb__DOT__dut__DOT____Vcellout__IDEX_stage__instruction_EX = 0U;
            vlSelf->tb__DOT__dut__DOT__xaluOp_EX = 0U;
            vlSelf->tb__DOT__dut__DOT__read1Data_EX = 0U;
            vlSelf->tb__DOT__dut__DOT__branchOp_EX = 1U;
            vlSelf->tb__DOT__dut__DOT__immediate_EX = 0U;
            vlSelf->tb__DOT__dut__DOT__read2Data_EX = 0U;
            vlSelf->tb__DOT__dut__DOT__rs2_EX = 0U;
            vlSelf->tb__DOT__dut__DOT__rs1_EX = 0U;
            vlSelf->tb__DOT__dut__DOT__writeSource_EX = 0U;
            vlSelf->tb__DOT__dut__DOT__instructionAddress_EX = 0U;
        } else {
            vlSelf->tb__DOT__dut__DOT____Vcellout__IDEX_stage__instruction_EX 
                = vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID;
            vlSelf->tb__DOT__dut__DOT__xaluOp_EX = 
                (((0x13U == (0x7fU & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)) 
                  || (0x33U == (0x7fU & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)))
                  ? (7U & (vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID 
                           >> 0xcU)) : 0U);
            vlSelf->tb__DOT__dut__DOT__read1Data_EX 
                = vlSelf->tb__DOT__dut__DOT__read1Data;
            vlSelf->tb__DOT__dut__DOT__branchOp_EX 
                = vlSelf->tb__DOT__dut__DOT__branchOp;
            vlSelf->tb__DOT__dut__DOT__immediate_EX 
                = vlSelf->tb__DOT__dut__DOT__immediate;
            vlSelf->tb__DOT__dut__DOT__read2Data_EX 
                = ((0U == (0x1fU & (vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID 
                                    >> 0x14U))) ? 0U
                    : ((0x1eU >= (0x1fU & ((vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID 
                                            >> 0x14U) 
                                           - (IData)(1U))))
                        ? vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers
                       [(0x1fU & ((vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID 
                                   >> 0x14U) - (IData)(1U)))]
                        : 0U));
            vlSelf->tb__DOT__dut__DOT__rs2_EX = (0x1fU 
                                                 & (vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID 
                                                    >> 0x14U));
            vlSelf->tb__DOT__dut__DOT__rs1_EX = (0x1fU 
                                                 & (vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID 
                                                    >> 0xfU));
            vlSelf->tb__DOT__dut__DOT__writeSource_EX 
                = vlSelf->tb__DOT__dut__DOT__writeSource;
            vlSelf->tb__DOT__dut__DOT__instructionAddress_EX 
                = vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instructionAddress_ID;
        }
    } else {
        vlSelf->tb__DOT__dut__DOT__hazardDetection__DOT__loadCounter = 0U;
        __Vdly__tb__DOT__dut__DOT____Vcellout__IFID_stage__instructionAddress_ID = 0U;
        vlSelf->__Vdly__tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID = 0U;
        __Vdly__tb__DOT__dut__DOT__branchPredictor__DOT__saturationCounter = 1U;
        vlSelf->tb__DOT__dut__DOT____Vcellout__IDEX_stage__instruction_EX = 0U;
        vlSelf->tb__DOT__dut__DOT__xaluOp_EX = 0U;
        vlSelf->tb__DOT__dut__DOT__read1Data_EX = 0U;
        vlSelf->tb__DOT__dut__DOT__branchOp_EX = 1U;
        vlSelf->tb__DOT__dut__DOT__immediate_EX = 0U;
        vlSelf->tb__DOT__dut__DOT__read2Data_EX = 0U;
        vlSelf->tb__DOT__dut__DOT__rs2_EX = 0U;
        vlSelf->tb__DOT__dut__DOT__rs1_EX = 0U;
        vlSelf->tb__DOT__dut__DOT__writeSource_WB = 0U;
        vlSelf->tb__DOT__dut__DOT__instructionAddress_WB = 0U;
        vlSelf->tb__DOT__dut__DOT__address_WB = 0U;
        vlSelf->tb__DOT__dut__DOT__memToRegData_WB = 0U;
        vlSelf->tb__DOT__instructionAddress = 0U;
        vlSelf->tb__DOT__dut__DOT__writeSource_MEM = 0U;
        vlSelf->tb__DOT__dut__DOT__instructionAddress_MEM = 0U;
        vlSelf->tb__DOT__dut__DOT__writeSource_EX = 0U;
        vlSelf->tb__DOT__dut__DOT__instructionAddress_EX = 0U;
    }
    vlSelf->tb__DOT__dut__DOT__jump_EX_reg = ((IData)(vlSelf->tb__DOT__RSTN) 
                                              && ((1U 
                                                   & (~ 
                                                      ((IData)(vlSelf->tb__DOT__dut__DOT__pipelineFlush) 
                                                       | (IData)(vlSelf->tb__DOT__dut__DOT__IDEX_delay)))) 
                                                  && (IData)(vlSelf->tb__DOT__dut__DOT__jump)));
    vlSelf->tb__DOT__dut__DOT__branchPrediction_EX 
        = ((IData)(vlSelf->tb__DOT__RSTN) && ((1U & 
                                               (~ ((IData)(vlSelf->tb__DOT__dut__DOT__pipelineFlush) 
                                                   | (IData)(vlSelf->tb__DOT__dut__DOT__IDEX_delay)))) 
                                              && (IData)(vlSelf->tb__DOT__dut__DOT__branchPrediction)));
    vlSelf->tb__DOT__dut__DOT__xaluArithmeticFlag_EX 
        = ((IData)(vlSelf->tb__DOT__RSTN) && ((1U & 
                                               (~ ((IData)(vlSelf->tb__DOT__dut__DOT__pipelineFlush) 
                                                   | (IData)(vlSelf->tb__DOT__dut__DOT__IDEX_delay)))) 
                                              && (((0x33U 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)) 
                                                   | (IData)(
                                                             (0x5013U 
                                                              == 
                                                              (0x707fU 
                                                               & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)))) 
                                                  & (vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID 
                                                     >> 0x1eU))));
    vlSelf->tb__DOT__dut__DOT__JALR_EX = ((IData)(vlSelf->tb__DOT__RSTN) 
                                          && ((1U & 
                                               (~ ((IData)(vlSelf->tb__DOT__dut__DOT__pipelineFlush) 
                                                   | (IData)(vlSelf->tb__DOT__dut__DOT__IDEX_delay)))) 
                                              && (0x67U 
                                                  == 
                                                  (0x7fU 
                                                   & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID))));
    vlSelf->tb__DOT__dut__DOT__branchNegate_EX = ((IData)(vlSelf->tb__DOT__RSTN) 
                                                  && ((1U 
                                                       & (~ 
                                                          ((IData)(vlSelf->tb__DOT__dut__DOT__pipelineFlush) 
                                                           | (IData)(vlSelf->tb__DOT__dut__DOT__IDEX_delay)))) 
                                                      && (1U 
                                                          & (vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID 
                                                             >> 0xcU))));
    vlSelf->tb__DOT__dut__DOT__immediateXaluSecondary_EX 
        = ((IData)(vlSelf->tb__DOT__RSTN) && ((1U & 
                                               (~ ((IData)(vlSelf->tb__DOT__dut__DOT__pipelineFlush) 
                                                   | (IData)(vlSelf->tb__DOT__dut__DOT__IDEX_delay)))) 
                                              && ((0x37U 
                                                   == 
                                                   (0x7fU 
                                                    & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)) 
                                                  | ((0x17U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)) 
                                                     | ((0x6fU 
                                                         == 
                                                         (0x7fU 
                                                          & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)) 
                                                        | ((0x67U 
                                                            == 
                                                            (0x7fU 
                                                             & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)) 
                                                           | ((0x63U 
                                                               == 
                                                               (0x7fU 
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
    vlSelf->tb__DOT__dut__DOT__zeroXaluPrimary_EX = 
        ((IData)(vlSelf->tb__DOT__RSTN) && ((1U & (~ 
                                                   ((IData)(vlSelf->tb__DOT__dut__DOT__pipelineFlush) 
                                                    | (IData)(vlSelf->tb__DOT__dut__DOT__IDEX_delay)))) 
                                            && (0x37U 
                                                == 
                                                (0x7fU 
                                                 & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID))));
    vlSelf->tb__DOT__dut__DOT__pcXaluPrimary_EX = ((IData)(vlSelf->tb__DOT__RSTN) 
                                                   && ((1U 
                                                        & (~ 
                                                           ((IData)(vlSelf->tb__DOT__dut__DOT__pipelineFlush) 
                                                            | (IData)(vlSelf->tb__DOT__dut__DOT__IDEX_delay)))) 
                                                       && ((0x17U 
                                                            == 
                                                            (0x7fU 
                                                             & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)) 
                                                           | ((0x6fU 
                                                               == 
                                                               (0x7fU 
                                                                & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)) 
                                                              | (0x63U 
                                                                 == 
                                                                 (0x7fU 
                                                                  & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID))))));
    vlSelf->tb__DOT__dut__DOT__branchPredictor__DOT__saturationCounter 
        = __Vdly__tb__DOT__dut__DOT__branchPredictor__DOT__saturationCounter;
    vlSelf->tb__DOT__dut__DOT__branchPredictor__DOT__branchTaken_delay1 
        = ((IData)(vlSelf->tb__DOT__RSTN) && (IData)(vlSelf->tb__DOT__dut__DOT__branchTaken_EX));
    vlSelf->tb__DOT__dut__DOT__branchPredictor__DOT__req_delay2 
        = ((IData)(vlSelf->tb__DOT__RSTN) && (IData)(vlSelf->tb__DOT__dut__DOT__branchPredictor__DOT__req_delay1));
    vlSelf->tb__DOT__dut__DOT__unsignedLoad_MEM = ((IData)(vlSelf->tb__DOT__RSTN) 
                                                   && (IData)(vlSelf->tb__DOT__dut__DOT__unsignedLoad_EX));
    vlSelf->tb__DOT__dut__DOT____Vcellinp__IFID_stage__instruction_IF 
        = vlSelf->tb__DOT__imem[(0x1ffU & (vlSelf->tb__DOT__instructionAddress 
                                           >> 2U))];
    vlSelf->tb__DOT__dut__DOT__branchPredictor__DOT__req_delay1 
        = ((IData)(vlSelf->tb__DOT__RSTN) && (1U != (IData)(vlSelf->tb__DOT__dut__DOT__branchOp)));
    vlSelf->tb__DOT__dut__DOT__unsignedLoad_EX = ((IData)(vlSelf->tb__DOT__RSTN) 
                                                  && ((1U 
                                                       & (~ 
                                                          ((IData)(vlSelf->tb__DOT__dut__DOT__pipelineFlush) 
                                                           | (IData)(vlSelf->tb__DOT__dut__DOT__IDEX_delay)))) 
                                                      && (1U 
                                                          & (vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID 
                                                             >> 0xeU))));
    vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instructionAddress_ID 
        = __Vdly__tb__DOT__dut__DOT____Vcellout__IFID_stage__instructionAddress_ID;
}

VL_INLINE_OPT void Vtb___024root___nba_sequent__TOP__1(Vtb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_sequent__TOP__1\n"); );
    // Init
    SData/*8:0*/ __Vdlyvdim0__tb__DOT__dmem__v0;
    __Vdlyvdim0__tb__DOT__dmem__v0 = 0;
    IData/*31:0*/ __Vdlyvval__tb__DOT__dmem__v0;
    __Vdlyvval__tb__DOT__dmem__v0 = 0;
    CData/*0:0*/ __Vdlyvset__tb__DOT__dmem__v0;
    __Vdlyvset__tb__DOT__dmem__v0 = 0;
    // Body
    __Vdlyvset__tb__DOT__dmem__v0 = 0U;
    if (((3U != (IData)(vlSelf->tb__DOT__dut__DOT__memoryOpSize_MEM)) 
         & (IData)(vlSelf->tb__DOT__dut__DOT__storeLoad_MEM))) {
        __Vdlyvval__tb__DOT__dmem__v0 = vlSelf->tb__DOT__dut__DOT____Vcellout__EXMEM_stage__memWriteData_MEM;
        __Vdlyvset__tb__DOT__dmem__v0 = 1U;
        __Vdlyvdim0__tb__DOT__dmem__v0 = (0x1ffU & 
                                          (vlSelf->tb__DOT__dut__DOT__address_MEM 
                                           >> 2U));
    }
    if (__Vdlyvset__tb__DOT__dmem__v0) {
        vlSelf->tb__DOT__dmem[__Vdlyvdim0__tb__DOT__dmem__v0] 
            = __Vdlyvval__tb__DOT__dmem__v0;
    }
}

VL_INLINE_OPT void Vtb___024root___nba_sequent__TOP__2(Vtb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_sequent__TOP__2\n"); );
    // Init
    CData/*4:0*/ __Vdlyvdim0__tb__DOT__dut__DOT__xRegisterFile__DOT__registers__v0;
    __Vdlyvdim0__tb__DOT__dut__DOT__xRegisterFile__DOT__registers__v0 = 0;
    IData/*31:0*/ __Vdlyvval__tb__DOT__dut__DOT__xRegisterFile__DOT__registers__v0;
    __Vdlyvval__tb__DOT__dut__DOT__xRegisterFile__DOT__registers__v0 = 0;
    CData/*0:0*/ __Vdlyvset__tb__DOT__dut__DOT__xRegisterFile__DOT__registers__v0;
    __Vdlyvset__tb__DOT__dut__DOT__xRegisterFile__DOT__registers__v0 = 0;
    // Body
    __Vdlyvset__tb__DOT__dut__DOT__xRegisterFile__DOT__registers__v0 = 0U;
    if (((IData)(vlSelf->tb__DOT__dut__DOT__writeEnable_WB) 
         & (0U != (IData)(vlSelf->tb__DOT__dut__DOT__rd_WB)))) {
        vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT____Vlvbound_h744144bb__0 
            = vlSelf->tb__DOT__dut__DOT__registerWriteData;
        if ((0x1eU >= (0x1fU & ((IData)(vlSelf->tb__DOT__dut__DOT__rd_WB) 
                                - (IData)(1U))))) {
            __Vdlyvval__tb__DOT__dut__DOT__xRegisterFile__DOT__registers__v0 
                = vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT____Vlvbound_h744144bb__0;
            __Vdlyvset__tb__DOT__dut__DOT__xRegisterFile__DOT__registers__v0 = 1U;
            __Vdlyvdim0__tb__DOT__dut__DOT__xRegisterFile__DOT__registers__v0 
                = (0x1fU & ((IData)(vlSelf->tb__DOT__dut__DOT__rd_WB) 
                            - (IData)(1U)));
        }
    }
    if (__Vdlyvset__tb__DOT__dut__DOT__xRegisterFile__DOT__registers__v0) {
        vlSelf->tb__DOT__dut__DOT__xRegisterFile__DOT__registers[__Vdlyvdim0__tb__DOT__dut__DOT__xRegisterFile__DOT__registers__v0] 
            = __Vdlyvval__tb__DOT__dut__DOT__xRegisterFile__DOT__registers__v0;
    }
}

extern const VlUnpacked<CData/*1:0*/, 128> Vtb__ConstPool__TABLE_hfc6ad3e0_0;

VL_INLINE_OPT void Vtb___024root___nba_sequent__TOP__3(Vtb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_sequent__TOP__3\n"); );
    // Init
    CData/*6:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    vlSelf->tb__DOT__dut__DOT__registerWriteData = 
        ((3U == (IData)(vlSelf->tb__DOT__dut__DOT__writeSource_WB))
          ? vlSelf->tb__DOT__dut__DOT__address_WB : 
         ((2U == (IData)(vlSelf->tb__DOT__dut__DOT__writeSource_WB))
           ? vlSelf->tb__DOT__dut__DOT__memToRegData_WB
           : ((1U == (IData)(vlSelf->tb__DOT__dut__DOT__writeSource_WB))
               ? ((IData)(4U) + vlSelf->tb__DOT__dut__DOT__instructionAddress_WB)
               : 0U)));
    if (vlSelf->tb__DOT__RSTN) {
        vlSelf->tb__DOT__dut__DOT____Vcellout__EXMEM_stage__memWriteData_MEM 
            = vlSelf->tb__DOT__dut__DOT__fwd_rs2;
        vlSelf->tb__DOT__dut__DOT__memoryOpSize_MEM 
            = vlSelf->tb__DOT__dut__DOT__memoryOpSize_EX;
        vlSelf->tb__DOT__dut__DOT__address_MEM = vlSelf->tb__DOT__dut__DOT__aluResult;
        vlSelf->tb__DOT__dut__DOT__rd_WB = vlSelf->tb__DOT__dut__DOT__rd_MEM;
        vlSelf->tb__DOT__dut__DOT__rd_MEM = vlSelf->tb__DOT__dut__DOT__rd_EX;
        if (((IData)(vlSelf->tb__DOT__dut__DOT__pipelineFlush) 
             | (IData)(vlSelf->tb__DOT__dut__DOT__IDEX_delay))) {
            vlSelf->tb__DOT__dut__DOT__memoryOpSize_EX = 3U;
            vlSelf->tb__DOT__dut__DOT__rd_EX = 0U;
        } else {
            vlSelf->tb__DOT__dut__DOT__memoryOpSize_EX 
                = (((3U == (0x7fU & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)) 
                    | (0x23U == (0x7fU & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID)))
                    ? (3U & (vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID 
                             >> 0xcU)) : 3U);
            vlSelf->tb__DOT__dut__DOT__rd_EX = (0x1fU 
                                                & (vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID 
                                                   >> 7U));
        }
    } else {
        vlSelf->tb__DOT__dut__DOT____Vcellout__EXMEM_stage__memWriteData_MEM = 0U;
        vlSelf->tb__DOT__dut__DOT__memoryOpSize_MEM = 3U;
        vlSelf->tb__DOT__dut__DOT__address_MEM = 0U;
        vlSelf->tb__DOT__dut__DOT__rd_WB = 0U;
        vlSelf->tb__DOT__dut__DOT__memoryOpSize_EX = 3U;
        vlSelf->tb__DOT__dut__DOT__rd_MEM = 0U;
        vlSelf->tb__DOT__dut__DOT__rd_EX = 0U;
    }
    vlSelf->tb__DOT__dut__DOT__storeLoad_MEM = ((IData)(vlSelf->tb__DOT__RSTN) 
                                                && (IData)(vlSelf->tb__DOT__dut__DOT__storeLoad_EX));
    vlSelf->tb__DOT__dut__DOT__writeEnable_WB = ((IData)(vlSelf->tb__DOT__RSTN) 
                                                 && (IData)(vlSelf->tb__DOT__dut__DOT__writeEnable_MEM));
    vlSelf->tb__DOT__dut__DOT__storeLoad_EX = ((IData)(vlSelf->tb__DOT__RSTN) 
                                               && ((1U 
                                                    & (~ 
                                                       ((IData)(vlSelf->tb__DOT__dut__DOT__pipelineFlush) 
                                                        | (IData)(vlSelf->tb__DOT__dut__DOT__IDEX_delay)))) 
                                                   && (0x23U 
                                                       == 
                                                       (0x7fU 
                                                        & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID))));
    vlSelf->tb__DOT__dut__DOT__writeEnable_MEM = ((IData)(vlSelf->tb__DOT__RSTN) 
                                                  && (IData)(vlSelf->tb__DOT__dut__DOT__writeEnable_EX));
    vlSelf->tb__DOT__dut__DOT____Vcellinp__hazardDetection__IDEX_memread 
        = (1U & (~ ((IData)(vlSelf->tb__DOT__dut__DOT__storeLoad_EX) 
                    | (3U == (IData)(vlSelf->tb__DOT__dut__DOT__memoryOpSize_EX)))));
    vlSelf->tb__DOT__dut__DOT__writeEnable_EX = ((IData)(vlSelf->tb__DOT__RSTN) 
                                                 && ((1U 
                                                      & (~ 
                                                         ((IData)(vlSelf->tb__DOT__dut__DOT__pipelineFlush) 
                                                          | (IData)(vlSelf->tb__DOT__dut__DOT__IDEX_delay)))) 
                                                     && (0U 
                                                         != (IData)(vlSelf->tb__DOT__dut__DOT__writeSource))));
    vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID 
        = vlSelf->__Vdly__tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID;
    __Vtableidx1 = (0x7fU & vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID);
    vlSelf->tb__DOT__dut__DOT__writeSource = Vtb__ConstPool__TABLE_hfc6ad3e0_0
        [__Vtableidx1];
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
    vlSelf->tb__DOT__dut__DOT__branchPrediction = (
                                                   (1U 
                                                    != (IData)(vlSelf->tb__DOT__dut__DOT__branchOp)) 
                                                   & (2U 
                                                      <= (IData)(vlSelf->tb__DOT__dut__DOT__branchPredictor__DOT__saturationCounter)));
}

VL_INLINE_OPT void Vtb___024root___nba_comb__TOP__0(Vtb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_comb__TOP__0\n"); );
    // Body
    vlSelf->tb__DOT__memReadData = (((~ (IData)(vlSelf->tb__DOT__dut__DOT__storeLoad_MEM)) 
                                     & (3U != (IData)(vlSelf->tb__DOT__dut__DOT__memoryOpSize_MEM)))
                                     ? vlSelf->tb__DOT__dmem
                                    [(0x1ffU & (vlSelf->tb__DOT__dut__DOT__address_MEM 
                                                >> 2U))]
                                     : 0U);
}

VL_INLINE_OPT void Vtb___024root___nba_comb__TOP__1(Vtb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_comb__TOP__1\n"); );
    // Body
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
    vlSelf->tb__DOT__dut__DOT__PC_update = 1U;
    vlSelf->tb__DOT__dut__DOT__IFID_write = 1U;
    vlSelf->tb__DOT__dut__DOT__IDEX_delay = 0U;
    if (((0x1fU & (vlSelf->tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID 
                   >> 0xfU)) == (IData)(vlSelf->tb__DOT__dut__DOT__rs1_EX))) {
        vlSelf->tb__DOT__dut__DOT__ForwardID_A = 0U;
    }
    if (vlSelf->tb__DOT__RSTN) {
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
    } else {
        vlSelf->tb__DOT__dut__DOT__PC_update = 1U;
        vlSelf->tb__DOT__dut__DOT__IFID_write = 1U;
        vlSelf->tb__DOT__dut__DOT__IDEX_delay = 0U;
        vlSelf->tb__DOT__dut__DOT__ForwardID_A = 0U;
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

VL_INLINE_OPT void Vtb___024root___nba_comb__TOP__2(Vtb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_comb__TOP__2\n"); );
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
}

void Vtb___024root___eval_nba(Vtb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_nba\n"); );
    // Body
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[4U] = 1U;
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((4ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb___024root___nba_sequent__TOP__2(vlSelf);
        vlSelf->__Vm_traceActivity[5U] = 1U;
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb___024root___nba_sequent__TOP__3(vlSelf);
        vlSelf->__Vm_traceActivity[6U] = 1U;
    }
    if ((3ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb___024root___nba_comb__TOP__0(vlSelf);
    }
    if ((0xaULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb___024root___nba_comb__TOP__1(vlSelf);
        vlSelf->__Vm_traceActivity[7U] = 1U;
    }
    if ((6ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb___024root___nba_comb__TOP__2(vlSelf);
    }
}

void Vtb___024root___timing_resume(Vtb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___timing_resume\n"); );
    // Body
    if ((8ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VdlySched.resume();
    }
}

void Vtb___024root___eval_triggers__act(Vtb___024root* vlSelf);

bool Vtb___024root___eval_phase__act(Vtb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<4> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vtb___024root___timing_resume(vlSelf);
        Vtb___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtb___024root___eval_phase__nba(Vtb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtb___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb___024root___dump_triggers__nba(Vtb___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb___024root___dump_triggers__act(Vtb___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb___024root___eval(Vtb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vtb___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("tb.sv", 63, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vtb___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("tb.sv", 63, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vtb___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vtb___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtb___024root___eval_debug_assertions(Vtb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG
