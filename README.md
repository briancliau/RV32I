# RV32I 5-Stage Pipelined Processor Core

A 32-bit RISC-V (RV32I) processor core implemented in SystemVerilog and synthesized through the OpenLane physical design flow. The architecture is a standard 5-stage pipeline with branch prediction, data forwarding logic, hazard detection, and two AHB-Lite bus interfaces for separate data and instruction memory. The design is verified using SystemVerilog Assertions (SVA) and a directed testbench that cover edge cases.

## Architectural Highlights

* **ISA Compliance:** RV32I Base Integer Instruction Set with support for byte/halfword load/store memory operations.
* **5-Stage Pipeline Architecture:** Standard **IF** $\rightarrow$ **ID** $\rightarrow$ **EX** $\rightarrow$ **MEM** $\rightarrow$ **WB** pipeline.
* **Dual AHB-Lite Bus Interfaces (Harvard Architecture):**
  * **I-AHB Master:** Instruction memory bus utilizing the pipelined address/data phase to achieve 1 instruction per cycle.
  * **D-AHB Master:** Data memory bus utilizing the pipelined address/data phase to handle transfers for the data given by the Load-Store unit.
* **Branch Prediction:** 
  * 2-Bit Saturating Counter branch prediction (`Strongly Not Taken` $\leftrightarrow$ `Strongly Taken`), trained when each branch resolves in `EX`.
  * Prediction is made in the **ID stage from the registered instruction (IF/ID register)**, so no combinational path runs from the instruction bus to the address bus.
  * One bubble for a predicted-taken branch or `JAL`; no penalty for correctly predicted not-taken branches.
  * Mispredictions are resolved in `EX`, which flushes the younger instructions and redirects the fetch.
* **Hazard Handling:**
  * **Data Forwarding Unit:** Resolves Read-After-Write (RAW) data hazards (EX $\rightarrow$ EX, MEM $\rightarrow$ EX).
  * **Hazard Detection Unit:** Identifies non-forwardable Load-Use dependencies and injects hardware stalls.
  * **X0 Register Guarding:** Suppresses writes to `x0` to maintain the zero register. 

## System Architecture

### 1. 5-Stage Core Overview

![RV32I Block Diagram](docs/Summarized_Core.png)
*Figure 1: RV32I 5-stage pipelined datapath featuring branch prediction, hazard handling, and AHB-Lite bus interfaces.*

* **Pipelined Datapath:** Standard 5-stage pipeline (`IF`, `ID`, `EX`, `MEM`, `WB`).
* **AHB-Lite Bus Interfaces:** Independent Instruction and Data AHB-Lite managers.
* **Decoupled Control Paths:** Separates datapath execution from local control hazard evaluation.

### 2. Branch & Jump Control Logic

![Branch Prediction Block Diagram](docs/Branch_Prediction.png)
*Figure 2: Branch prediction and JALR target resolution paths.*

* **2-Bit Branch Predictor:** Looks up the prediction in the `ID` stage, using a saturating counter that is updated when the branch resolves in `EX`. A predicted-taken branch or `JAL` redirects the fetch address from `ID` and squashes the sequential instruction fetched behind it (one bubble). See [Design Decision](#design-decision-where-to-make-the-branch-prediction) for why prediction is made in `ID`.
* **Resolution Paths:**
  * **Branch Target (EX Stage):** Evaluated in `EX` to correct branch mispredictions by flushing the pipeline and refetching.
  * **JALR Target (EX Stage):** Evaluated using forwarded ALU results and bit-masking before driving target selection based on correction multiplexers.

### 3. Hazard Detection & Forwarding Unit

![Forwarding Unit Block Diagram](docs/Forwarding_Unit.png)
*Figure 3: Execution stage forwarding matrix for RAW data dependencies.*

* **ALU Forwarding:** Forwards data from `EX/MEM` and `MEM/WB` pipeline registers back to the ALU input MUXes (`Forward A/B`).
* **Load-Use Stalls:** Intercepts `Load-Use` hazards by monitoring `ID/EX.MemRead` and instruction opcodes to stretch pipeline holds across multi-cycle bus transactions.

## Hardware Modules

| Module Name | Description |
| :--- | :--- |
| RV32I_subsystem | Top-level module connecting the RV32I core with the AHB-Lite bus adapters for instruction and data memory. |
| Core | Implements pipeline stages, hazard control, and branch prediction. |
| HazardDetection | Detects load-use hazards and manages pipeline stalls and bubble inserts. |
| ForwardingUnit | Determines which operand source is used for the execution stage from the register file, EX/MEM, or MEM/WB stages. |
| BranchPredictor | 2-bit saturating counter. Predicts in `ID` and trains when the branch resolves in `EX`. |
| BranchDecoder / BranchAddresser | Decode branch and `JAL` instructions in `ID` and compute their targets from the IF/ID register. |
| AHBDataManager | Controls 2-cycle AHB-Lite transactions for data memory load and stores. | 
| AHBInstructionManager | Controls 2-cycle AHB-Lite transactions for instruction fetches. |
| XALU | Execution ALU supporting full 32-bit arithmetic, logical, and shift operations. | 

## Verification of Design

### Verification Strategy

The verification strategy for this RV32I pipelined core uses both **SystemVerilog Assertions (SVA)** for structural checks and a **comprehensive testbench** for instruction execution and hazard validation.

### SystemVerilog Assertions (SVA) — Structural Invariants

The `RV32I_core_sva` module runs concurrently during simulation to enforce RISC-V architectural invariants and pipeline protocol rules at every positive clock edge:

* **Architectural Invariants:**
  * **Register `x0` Hardwiring:** Asserts that any write-back targeted to register `x0` always evaluates to zero (`writeEnable_WB && rd_WB == 0 |-> registerWriteData == 0`).
  * **PC Word Alignment:** Enforces 4-byte boundary alignment on all instruction fetches (`instructionAddress[1:0] == 2'b00`).
  * **Bus Mutual Exclusion:** Ensures `memRead` and `memWrite` signals are never asserted simultaneously.
  * **Access Alignment:** Verifies that word-sized load and store operations are properly aligned.
* **Pipeline Safety & Hazard Rules:**
  * **Stall Integrity:** Guarantees that `instructionAddress` and the `ID` stage instruction register hold their values during a `pipelineStall`.
  * **Flush Execution:** Ensures pipeline flushes correctly insert a `NOP` into the `ID` stage and clear control write enables in `EX` (`writeEnable_EX == 0`).
  * **X-Propagation Detection:** Flags `$isunknown` (X/Z state) errors on register destination or write-data buses during active write-back cycles.

### Directed Testbench (`tb_core_asic`)

The testbench runs the hardened block (`RV32I_core_asic`: core plus AHB-Lite managers) against a memory system that sits outside it, as an SoC would. The program is loaded from `test_core_asic.mem` and the initial data from `data_memory.hex`; run the simulation from the folder containing both. Checks are **event-based**: each phase waits for a specific instruction to retire and then checks the results, so the testbench does not depend on pipeline timing. All **97 checks pass**.

The testbench covers these execution phases:

#### Core Instruction Suite & Arithmetic Edge Cases
* **Logical & Bitwise Operations (Phase A):** Validates signed/unsigned shifts, immediate handling, and bitwise logic (`AND`, `OR`, `XOR`, `SRLI`, `SLL`).
* **Set-Less-Than Suite (Phase B):** Verifies signed vs. unsigned edge cases (`SLT`, `SLTU`, `SLTI`, `SLTIU`), specifically testing negative rollover (e.g., `-1` vs `1`).
* **Immediate & Address Generation (Phases C & S):** Tests upper immediate loading (`LUI`), program-counter offsets (`AUIPC`), address wrapping, and boundary shift operations (e.g., shifts modulo 32).

#### Pipeline Hazard & Forwarding Matrix
* **Double Forwarding (Phase D):** Tests back-to-back operations requiring simultaneous `EX->EX` bypass on both `rs1` and `rs2` registers.
* **Load-Use Hazards (Phases E & O):** Enforces a 1-cycle data stall when an instruction immediately consumes a load result, alongside multi-cycle non-stalling tests.
* **Control Hazards & Branch Logic (Phases G, H, I, P, Q, T):**
  * Verifies branch comparisons (`BEQ`, `BLT`, `BGE`, `BLTU`, `BGEU`) using previous cycle computed register data.
  * Confirms speculative fetch instruction flushing on mispredicted branches and tight loop conditions.
  * Tests ALU-to-`JALR` target calculation forwarding and branch-not-taken fallthrough execution.
* **Forwarding Suppression (Phase R):** Verifies bypass logic suppresses forwarding when source operations target register `x0`.

#### Memory Interface & Sub-Word Granularity
* **Sub-Word Access (Phases F & U):** Validates signed and unsigned byte (`LB`/`LBU`) and halfword (`LH`/`LHU`) loads alongside byte-lane masking for stores (`SB`/`SH`).
* **Return Address Verification (Phases J & K):** Checks link address saving (`PC + 4`) for `JAL` and verifies `JALR` clears the least significant bit (`LSB & ~1`) of target addresses.

#### System Robustness
* **Mid-Execution Reset (Phases M & N):** Asserts reset mid-flight during execution to ensure pipeline registers clear without introducing unknown state (`X` propagation), while preserving core state across soft resets.
* **Watchdog Timeout:** A 20,000-cycle watchdog and a per-event timeout (2,000 cycles) trap infinite loops and lost control flow.

#### Wrong-Path and Redirect Tests (Phases V–AB)
Each phase uses a *canary* register or memory word that only a wrong-path instruction can write, so a leaked instruction is caught even if a later instruction overwrites the target.
* **Wrong-path store and jump behind a `JAL` (V, W):** Instructions behind a taken `JAL` must not store or redirect.
* **Redirect around load stalls (X):** A `JAL` right after a load and after a load-use stall must execute its target exactly once.
* **Branches at a `JAL` target (Y):** Taken and not-taken branches immediately at a jump target.
* **CPI kernel (Z):** A 20-iteration loop of 61 instructions used for CPI measurement.
* **PC tag after a load-to-store stall (AA)** and **`JALR` redirect with a jump in IF (AB).**

## Synthesis & Implementation Metrics

### ASIC Hardening Top (`RV32I_core_asic`)

The ASIC flow uses a dedicated top, `RTL/asic/RV32I_core_asic.sv`, separate from the FPGA/Arty A7-100T top (`RV32I_subsystem`):

* **Hardened block** = RV32I core + AHB-Lite instruction and data managers (`RTL/asic/AHB*ManagerPort.sv`).
* **Both AHB-Lite buses are top-level ports** (`I_*` and `D_*`). Instruction and data memories sit outside the block, as SRAM macros would in a real SoC.
* Every architectural result is observable at a pin, so synthesis cannot remove the core as dead logic.

> **Note on earlier results:** A previous revision reported 91.71 MHz / 8,489 µm² / 1.30 mW for `RV32I_subsystem`. That top's only output (an LED) did not depend on the core's results, so synthesis removed most of the core as dead logic. Those numbers did not describe the full design and have been replaced below.

### Yosys Synthesis (`RV32I_core_asic`)

* **Sequential Elements:** 1,572 flip-flops (flattened, memories mapped to flip-flops)
  * Register file (x1–x31): 992
  * Pipeline registers, PC, branch predictor, AHB managers: 580

## OpenLane Physical Design & PPA Metrics

`RV32I_core_asic` was synthesized, placed, routed, and verified with **OpenLane 2 / OpenROAD** on **SkyWater 130nm (`sky130_fd_sc_hd`)**.

### Signoff Status (19 ns target)
* **Setup Timing:** **PASS** at all corners. Slow corner (`max_ss_100C_1v60`) WNS **+0.180 ns**.
* **Hold Timing:** **PASS** at all corners. Worst hold slack **+0.061 ns** (`min_ff_n40C_1v95`).
* **Routing DRC:** **CLEAN** (0 errors, resolved at detailed-routing iteration 6)
* **LVS:** **CLEAN** (0 errors)

### Performance, Power, and Area (PPA) Summary

| Parameter | Value | Details / Notes |
| :--- | :--- | :--- |
| **Technology Node** | SkyWater 130nm (`sky130_fd_sc_hd`) | High-density standard cell library |
| **Clock Period (met)** | **19.00 ns** (≈ 52.6 MHz) | Signoff pass at the slow corner. `PL/GRT_RESIZER_SETUP_SLACK_MARGIN` = 7 ns, default I/O constraints |
| **$F_{\max}$, slow corner** | **between 52.6 and 54.1 MHz** | 19 ns passes (+0.180 ns); 18.5 ns fails (−0.118 ns) |
| **$F_{\max}$, typical corner (estimate)** | ≈ 81.5 MHz | $T = 19.00 - 6.73 = 12.27$ ns (`max_tt_025C_1v80`), estimated from slack at the 19 ns target |
| **$F_{\max}$, fast corner (estimate)** | ≈ 93.4 MHz | $T = 19.00 - 8.30 = 10.70$ ns (`max_ff_n40C_1v95`), estimated from slack at the 19 ns target |
| **Worst Setup Slack (WNS)** | **+0.180 ns** | Corner: `max_ss_100C_1v60` |
| **Worst Hold Slack (WHS)** | **+0.061 ns** | Corner: `min_ff_n40C_1v95` |
| **Total Power** | **24.13 mW** | OpenLane default activity, 19 ns clock |
| **Die Area** | $253{,}066\ \mu\text{m}^2$ | Sized from `FP_CORE_UTIL` = 40% |
| **Standard Cell Area** | $121{,}692\ \mu\text{m}^2$ | |
| **Utilization** | **51.6%** | Standard-cell area relative to core area |

The slow-corner $F_{\max}$ is bracketed by two real runs (a pass at 19 ns and a failure at 18.5 ns). The typical and fast corner figures are extrapolated from slack and are estimates only.

### Signoff Results

```text
[OpenROAD.DetailedRouting] DRC Errors: 0 (Resolved at iteration 6)
[LVS]                      Errors: 0
[STA] Setup WNS (ss_100C_1v60): +0.180 ns
[STA] Hold  WHS (ff_n40C_1v95): +0.061 ns
```

## Design Decision: Where to Make the Branch Prediction

The core was built in two versions that differ only in where the branch prediction is made. Both were taken through the same testbench and the same OpenLane flow (`config.json`, slack margins, default I/O constraints) so the trade-off could be measured rather than assumed.

* **Previous design: predict in IF from the AHB bus.** The instruction arriving on `I_HRDATA` is decoded, the target is computed, and the result drives `I_HADDR` in the same cycle. A predicted-taken branch or `JAL` costs no bubbles.
* **Final design: predict in ID from the IF/ID register.** The same decode and target logic reads a flip-flop instead of the bus. A predicted-taken branch or `JAL` costs one bubble.

The previous design was first repaired so that the comparison is fair. As committed, it fetched each predicted target twice and let wrong-path instructions redirect the fetch after a misprediction. With three fixes (load `target + 4` into the PC, squash the wrong-path word that arrives one cycle after an EX correction, and block predictions from squashed words) it passes all 97 checks.

### Measured Results

| | Previous design (IF, fixed) | Final design (ID) |
| :--- | :--- | :--- |
| Directed testbench | 97 / 97 | 97 / 97 |
| Slow-corner clock, passing | 22 ns (+1.03 ns slack), 45.5 MHz | 19 ns (+0.18 ns slack), 52.6 MHz |
| Slow-corner clock, failing | not run below 22 ns | 18.5 ns (−0.12 ns) |
| CPI kernel (61 instr) | 67 cycles, **CPI 1.098** | 83 cycles, **CPI 1.361** |
| Whole test program | 512 cycles | 549 cycles |
| Kernel run time | 67 × 22 = **1,474 ns** | 83 × 19 = **1,577 ns** (7% slower) |
| Whole program run time | 512 × 22 = **11,264 ns** | 549 × 19 = **10,431 ns** (8% faster) |
| Total power | 21.66 mW at 22 ns | 24.13 mW at 19 ns |
| Standard cell area | $121{,}305\ \mu\text{m}^2$ | $121{,}692\ \mu\text{m}^2$ |

All cycle counts are with single-cycle (zero wait state) memories. The CPI kernel is a 20-iteration loop in which every third instruction is a taken branch; the whole test program is the full directed testbench. Neither is a standard benchmark.

### Trade-off

Moving the prediction to ID raised $F_{\max}$ by 15.8%. The final design is faster whenever the extra bubbles add fewer than 15.8% more cycles. On the tight loop they add 23.9%, so the previous design wins; on the whole test program they add 7.2%, so the final design wins. The faster design therefore depends on how often the target software takes branches. The previous design's slack at 22 ns suggests it may close near 21 ns, which would not change which design wins either workload.

### Why the Final Design Was Chosen

The deciding factor was timing robustness, not raw speed. In the previous design the critical path was a combinational path from input pins to output pins, `I_HREADY` / `I_HRDATA` → `I_HADDR`: the fetched instruction had to arrive from memory, be decoded, have its target added, and select the next fetch address, all in one cycle. Every nanosecond the instruction memory takes to return data comes straight out of the time left for prediction. In this flow the memory is outside the block and only default I/O delays were assumed. In a real SoC, a slower SRAM macro or bus interconnect would lengthen this path and lower the clock, and the block's timing would depend on whatever memory it is connected to.

In the final design the prediction path starts at the IF/ID flip-flop. The instruction bus only has to meet a register's setup time, and the prediction logic gets the full cycle regardless of memory latency. Timing is contained inside the block, so it can be signed off on its own and integrated with different memories without re-closing the core. That robustness was worth one bubble per predicted-taken branch.

A branch target buffer (BTB), indexed by the fetch PC instead of the fetched instruction, would give zero-bubble taken branches while keeping the prediction path register-based. It is a natural next step.

### Critical Path

The previous design's critical path was the input-to-output path `I_HREADY` → `I_HADDR[30]` described above, dominated by the target adder's carry chain. In the final design that path starts at the IF/ID flip-flop. The critical path report for the final design has not yet been analyzed.

## Prerequisites

* **EDA Toolchain:**
  * [OpenLane 2](https://github.com/efabless/openlane2)
  * [Yosys](https://github.com/YosysHQ/yosys) with the `slang` SystemVerilog frontend (or `yowasp-yosys` via PyPI)
  * [Verilator](https://www.veripool.org/verilator/) (for linting & RTL simulation)
  * [Docker](https://docs.docker.com/desktop/setup/install/windows-install/) (for Windows distribution)
* **PDK:** SkyWater 130nm (`sky130A`)

## Build and Simulation

### Build
```bash
git clone https://github.com/briancliau/RV32I.git
cd RV32I
```

### Simulation
```bash
# Compile design and testbench (test_core_asic.mem and data_memory.hex must be
# in the directory you run the simulation from)
verilator --binary --timing --assert --trace --top tb_core_asic -f filelist.f

# Run simulation
./obj_dir/Vtb_core_asic

# View waveform
gtkwave tb_core_asic.vcd
```

### Physical Layout and Signoff (ASIC)

```bash
# 1. Convert SystemVerilog RTL to plain Verilog for OpenLane
#    (only needed after RTL changes; RV32I_core_asic.v is checked in)
yosys -m slang openlane/asic/sv2v.ys

# 2. Run OpenLane
openlane --dockerized openlane/asic/config.json

# 3. View results
cd openlane/asic/runs/RUN_[date and time]/final
cat metrics.csv

# Sanity check: flip-flop count should be ~1,572
grep -cE "sky130_fd_sc_hd__(df|edf|sdf)" nl/RV32I_core_asic.nl.v
```
