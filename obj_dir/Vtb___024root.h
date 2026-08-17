// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb.h for the primary calling header

#ifndef VERILATED_VTB___024ROOT_H_
#define VERILATED_VTB___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ tb__DOT__CLK;
        CData/*0:0*/ tb__DOT__RSTN;
        CData/*0:0*/ tb__DOT__stall;
        CData/*0:0*/ tb__DOT__dut__DOT__PC_update;
        CData/*0:0*/ tb__DOT__dut__DOT__IFID_write;
        CData/*0:0*/ tb__DOT__dut__DOT__IDEX_delay;
        CData/*1:0*/ tb__DOT__dut__DOT__ForwardA;
        CData/*1:0*/ tb__DOT__dut__DOT__ForwardB;
        CData/*1:0*/ tb__DOT__dut__DOT__ForwardID_A;
        CData/*0:0*/ tb__DOT__dut__DOT__branchPass;
        CData/*0:0*/ tb__DOT__dut__DOT__branchTaken_EX;
        CData/*0:0*/ tb__DOT__dut__DOT__branchPrediction;
        CData/*0:0*/ tb__DOT__dut__DOT__pipelineFlush;
        CData/*1:0*/ tb__DOT__dut__DOT__branchOp;
        CData/*0:0*/ tb__DOT__dut__DOT__jump;
        CData/*1:0*/ tb__DOT__dut__DOT__writeSource;
        CData/*1:0*/ tb__DOT__dut__DOT__writeSource_EX;
        CData/*0:0*/ tb__DOT__dut__DOT__writeEnable_EX;
        CData/*4:0*/ tb__DOT__dut__DOT__rs1_EX;
        CData/*4:0*/ tb__DOT__dut__DOT__rs2_EX;
        CData/*4:0*/ tb__DOT__dut__DOT__rd_EX;
        CData/*2:0*/ tb__DOT__dut__DOT__xaluOp_EX;
        CData/*0:0*/ tb__DOT__dut__DOT__xaluArithmeticFlag_EX;
        CData/*1:0*/ tb__DOT__dut__DOT__memoryOpSize_EX;
        CData/*0:0*/ tb__DOT__dut__DOT__unsignedLoad_EX;
        CData/*0:0*/ tb__DOT__dut__DOT__storeLoad_EX;
        CData/*0:0*/ tb__DOT__dut__DOT__pcXaluPrimary_EX;
        CData/*0:0*/ tb__DOT__dut__DOT__immediateXaluSecondary_EX;
        CData/*0:0*/ tb__DOT__dut__DOT__zeroXaluPrimary_EX;
        CData/*1:0*/ tb__DOT__dut__DOT__branchOp_EX;
        CData/*0:0*/ tb__DOT__dut__DOT__branchNegate_EX;
        CData/*0:0*/ tb__DOT__dut__DOT__jump_EX_reg;
        CData/*0:0*/ tb__DOT__dut__DOT__branchPrediction_EX;
        CData/*0:0*/ tb__DOT__dut__DOT__JALR_EX;
        CData/*0:0*/ tb__DOT__dut__DOT__branchCorrection;
        CData/*0:0*/ tb__DOT__dut__DOT__branchMispredicted_EX;
        CData/*1:0*/ tb__DOT__dut__DOT__writeSource_MEM;
        CData/*0:0*/ tb__DOT__dut__DOT__writeEnable_MEM;
        CData/*4:0*/ tb__DOT__dut__DOT__rd_MEM;
        CData/*1:0*/ tb__DOT__dut__DOT__memoryOpSize_MEM;
        CData/*0:0*/ tb__DOT__dut__DOT__unsignedLoad_MEM;
        CData/*0:0*/ tb__DOT__dut__DOT__storeLoad_MEM;
        CData/*0:0*/ tb__DOT__dut__DOT__writeEnable_WB;
        CData/*4:0*/ tb__DOT__dut__DOT__rd_WB;
        CData/*1:0*/ tb__DOT__dut__DOT__writeSource_WB;
        CData/*0:0*/ tb__DOT__dut__DOT____Vcellinp__hazardDetection__IDEX_memread;
        CData/*1:0*/ tb__DOT__dut__DOT__branchPredictor__DOT__saturationCounter;
        CData/*0:0*/ tb__DOT__dut__DOT__branchPredictor__DOT__req_delay1;
        CData/*0:0*/ tb__DOT__dut__DOT__branchPredictor__DOT__req_delay2;
        CData/*0:0*/ tb__DOT__dut__DOT__branchPredictor__DOT__branchTaken_delay1;
        CData/*1:0*/ tb__DOT__dut__DOT__hazardDetection__DOT__loadCounter;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__tb__DOT__CLK__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__tb__DOT__RSTN__0;
        CData/*0:0*/ __VactContinue;
        IData/*31:0*/ tb__DOT__instructionAddress;
        IData/*31:0*/ tb__DOT__memReadData;
        IData/*31:0*/ tb__DOT__pass_count;
        IData/*31:0*/ tb__DOT__fail_count;
        IData/*31:0*/ tb__DOT__unnamedblk1__DOT__i;
        IData/*31:0*/ tb__DOT__dut__DOT__immediate;
        IData/*31:0*/ tb__DOT__dut__DOT__read1Data;
        IData/*31:0*/ tb__DOT__dut__DOT__read1Data_EX;
        IData/*31:0*/ tb__DOT__dut__DOT__read2Data_EX;
    };
    struct {
        IData/*31:0*/ tb__DOT__dut__DOT__instructionAddress_EX;
        IData/*31:0*/ tb__DOT__dut__DOT__immediate_EX;
        IData/*31:0*/ tb__DOT__dut__DOT__fwd_rs1;
        IData/*31:0*/ tb__DOT__dut__DOT__fwd_rs2;
        IData/*31:0*/ tb__DOT__dut__DOT__xalu_primary;
        IData/*31:0*/ tb__DOT__dut__DOT__xalu_secondary;
        IData/*31:0*/ tb__DOT__dut__DOT__aluResult;
        IData/*31:0*/ tb__DOT__dut__DOT__branchCorrectionAddress;
        IData/*31:0*/ tb__DOT__dut__DOT__address_MEM;
        IData/*31:0*/ tb__DOT__dut__DOT__instructionAddress_MEM;
        IData/*31:0*/ tb__DOT__dut__DOT__memWriteData_MEM;
        IData/*31:0*/ tb__DOT__dut__DOT__address_WB;
        IData/*31:0*/ tb__DOT__dut__DOT__memToRegData_WB;
        IData/*31:0*/ tb__DOT__dut__DOT__instructionAddress_WB;
        IData/*31:0*/ tb__DOT__dut__DOT__registerWriteData;
        IData/*31:0*/ tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID;
        IData/*31:0*/ tb__DOT__dut__DOT____Vcellinp__IFID_stage__instruction_IF;
        IData/*31:0*/ tb__DOT__dut__DOT____Vcellout__IFID_stage__instructionAddress_ID;
        IData/*31:0*/ tb__DOT__dut__DOT____Vcellout__IDEX_stage__instruction_EX;
        IData/*31:0*/ tb__DOT__dut__DOT____Vcellout__EXMEM_stage__memWriteData_MEM;
        IData/*31:0*/ tb__DOT__dut__DOT__programCounter__DOT__addrNext;
        IData/*31:0*/ tb__DOT__dut__DOT__xRegisterFile__DOT____Vlvbound_h744144bb__0;
        IData/*31:0*/ __Vdly__tb__DOT__dut__DOT____Vcellout__IFID_stage__instruction_ID;
        IData/*31:0*/ __VactIterCount;
        VlUnpacked<IData/*31:0*/, 512> tb__DOT__imem;
        VlUnpacked<IData/*31:0*/, 512> tb__DOT__dmem;
        VlUnpacked<IData/*31:0*/, 31> tb__DOT__dut__DOT__xRegisterFile__DOT__registers;
        VlUnpacked<CData/*0:0*/, 8> __Vm_traceActivity;
    };
    VlDelayScheduler __VdlySched;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<4> __VactTriggered;
    VlTriggerVec<4> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtb__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtb___024root(Vtb__Syms* symsp, const char* v__name);
    ~Vtb___024root();
    VL_UNCOPYABLE(Vtb___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
