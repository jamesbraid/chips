# Visual Workstation HAL: build-by-build reading

SGI's Windows HAL for the Visual Workstation 320 and 540 (`halborg.dll`, uniprocessor `halbrgup.dll`) exists in six held builds.
This page is the index and the cross-build summary; each build has its own page under [hal-builds/](hal-builds/). The goal is a
HAL program that can plan our own XP and XP x64 HAL from what SGI's HAL does, so every fact carries a requirement id and an evidence row.
The same format is meant for later targets (SN2 IA-64 and the MIPS NT HALs): only the target prefix and the structure list change.

Hardware behaviour (what the registers do) stays in [nt-hal.md](nt-hal.md); our requirements are in [hal-requirements.md](hal-requirements.md).
This page records what the **code** assumes of the kernel and which parts are SGI's. Nothing is copied from the binaries; names, offsets and
addresses are facts the shipped files carry. Every access offset, store and negative claim below comes from a disassembly of the image
(capstone, in `tools/visws-hal/scan.py`); decompiler output was used only to find function bounds.

## Ids and grades

A requirement id is `TARGET-HAL-AREA-NN`. `TARGET` is `VW` here (`SN2`, `MIPS` later). Areas:

| Area | Covers |
|---|---|
| EXP | export table: names, ordinals, data versus code |
| PCR | KPCR fields the code reads or writes (`fs:` offsets, or the fixed address on a uniprocessor kernel) |
| PRCB | KPRCB fields, reached through the PCR's `Prcb` pointer |
| DISP | HalDispatchTable and HalPrivateDispatchTable slots the HAL fills |
| BUS | bus handler object layout and the handlers the HAL installs |
| ADAP | DMA adapter object layout |
| SGI | what is SGI's own code, as opposed to generic Microsoft HAL code |
| DIFF | what changed between builds |

Grades are those of the [README](README.md). Here **established** means read in the disassembly of the named build and address;
**inferred** means a reasoned reading (reasoning given), for example a field name taken from the public layout of the kernel structure
rather than from the image. Whether our HAL must do the same is for [hal-requirements.md](hal-requirements.md).

## Builds

| Id | Build | Image SHA-256 (prefix) | Bytes | PE time (UTC) | Page |
|---|---|---|---|---|---|
| nt4-mp | NT 4.0 multiprocessor `halborg.dll` | `0926cd50` | 142,496 | 1999-04-27 | [nt4-mp](hal-builds/nt4-mp.md) |
| nt4-up | NT 4.0 uniprocessor `halbrgup.dll` | `21978c78` | 140,064 | 1999-04-27 | [nt4-up](hal-builds/nt4-up.md) |
| w2k-rc3 | Windows 2000 RC3 5.00.2164.1 | `f897718d` | 148,672 | 1999-10-26 | [w2k-rc3](hal-builds/w2k-rc3.md) |
| w2k-rtm | Windows 2000 RTM 5.00.2168.1 | `a51bb518` | 148,672 | 1999-10-30 | [w2k-rtm](hal-builds/w2k-rtm.md) |
| w2k-sp4beta | Windows 2000 SP4 beta 5.00.2195.6615 | `66fb8086` | 148,960 | 2002-11-07 | [w2k-sp4beta](hal-builds/w2k-sp4beta.md) |
| w2k-sp4 | Windows 2000 SP4 5.00.2195.6655 | `213b3d97` | 148,960 | 2003-01-15 | [w2k-sp4](hal-builds/w2k-sp4.md) |

Sources: the NT 4.0 pair and its symbol files are on Silicon Graphics Recovery CD-1 v1.1 (ISO SHA-256 `041f74f9…e0a40`; `I386/` and
`SUPPORT/DEBUG/I386/SYMBOLS/SGI/DLL/`); the same bytes are in the Library cache. The four Windows 2000 builds are in the Library cache
under the visws driver set; RTM and SP4 are also on the Windows 2000 SP4 5-in-1 disc (RTM by SHA-256 only in the cache). The HAL of each
Windows 2000 build carries its own version resource (above) and no symbol file.

## Per-build counts

Functions are those Ghidra found with the symbol file applied where there is one (`re-run --ghidra-export --decompile-all`,
Ghidra 12.1.3). "Named" is a function whose name is not a `FUN_` placeholder. For NT 4.0 every name traces to the `.dbg` file or the
export table (checked: each of the 518 and 510 names occurs in the `.dbg` text or is an export). Windows 2000 has no symbols, so its
named functions are exactly the code exports.

| Build | Exports (code + data) | Functions | Decompiled | Named | of which export names | Named from the `.dbg` alone | Unnamed |
|---|---|---|---|---|---|---|---|
| nt4-mp | 93 (92 + 1) | 559 | 540 | 518 | 92 | 426 | 41 |
| nt4-up | 93 (92 + 1) | 551 | 531 | 510 | 92 | 418 | 41 |
| w2k-rc3 | 98 (97 + 1) | 430 | 430 | 97 | 97 | 0 | 333 |
| w2k-rtm | 98 (97 + 1) | 430 | 430 | 97 | 97 | 0 | 333 |
| w2k-sp4beta | 98 (97 + 1) | 431 | 431 | 97 | 97 | 0 | 334 |
| w2k-sp4 | 98 (97 + 1) | 431 | 431 | 97 | 97 | 0 | 334 |

The symbol import reads 1,050 records for the MP image and 1,037 for the UP image (600 and 592 function-type records); 81 function
records in each fall inside another function's body and stay labels. The decompiler failed on 19 and 20 functions of the NT 4.0 images
(flagged, not hidden). No halborg PDB is held (Library search for `halborg` with `pdb` and for Windows 2000 symbols returned nothing, and no
`.pdb` is in the cache or on the discs), so `--pdb` was not run and the known failure of the PDB 2.00 import was not exercised.

## SGI-specific versus generic

Stock halmps, halapic and hal from the same media were exported the same way (NT 4.0 SP4 `HAL.DLL`, `HALAPIC.DLL`, `HALMPS.DLL` from
Recovery CD-1 `SP4/I386/`; Windows 2000 SP4 `hal.dll`, `halapic.dll`, `halmps.dll` from the 5-in-1 disc). They are stripped, so only exports are named.
Two tests, both mechanical and both **inferred** evidence of origin:

1. *Body match.* A function's shape is its instruction sequence with immediates, displacements and branch targets of 0x1000 or more
   masked. Exact shape equality, or a mnemonic-trigram Jaccard score over 0.80 with a similar length, counts as a match in the stock set.
   Functions under four instructions (jump stubs) are excluded from claims.
2. *Name match.* NT 4.0 only: the name occurs in the Microsoft HAL symbol files on the same disc (`SUPPORT/DEBUG/I386/SYMBOLS/MS/SP1/DLL/`, HAL,
   HALAPIC, HALMPS; these are SP1 symbols, a different service pack, so this test is loose).

| Build | Functions | Name also in a Microsoft HAL symbol file | Not in one, body matches stock | Not in one, no stock body: SGI-specific candidates | Unnamed |
|---|---|---|---|---|---|
| nt4-mp | 559 | 314 | 22 | 182 | 41 |
| nt4-up | 551 | 308 | 22 | 180 | 41 |

For NT 4.0 the body test alone matches only about 100 functions (93 exact, 11 near, one by string use in the MP image). SGI's build
differs from SP4 stock HALs in compiler output, so body match undercounts generic code; the name test is the better signal there. The 182 candidates are
the Cobalt, Lithium, NS87307, PIIX4, I2C, GBE display, flash and environment, memory-error, power-management and `sgix` callback code,
the three-way interrupt-entry stubs for the Cobalt vector (`HCoIntr`, `HCoStub`, `H8259Intr`, `Hmem`, `SoftPwrInt`), the TypeBorg PCI accessors, and some C
library helpers (`atoi`, `index`, `strctok`, `__allrem`, `__aulldiv`) that no Microsoft HAL symbol file lists. The full list is in
[hal-builds/nt4-mp.md](hal-builds/nt4-mp.md#sgi-specific-functions).

| Build | Functions | Body in stock Windows 2000 SP4 HALs (exact + near) | Under 4 instructions | No stock body, 4 or more instructions | Of those, tied to an NT 4.0 SGI-specific name |
|---|---|---|---|---|---|
| w2k-rc3 | 430 | 215 (195 + 20) | 56 | 208 | 7 |
| w2k-rtm | 430 | 215 (195 + 20) | 56 | 208 | 7 |
| w2k-sp4beta | 431 | 217 (197 + 20) | 57 | 207 | 7 |
| w2k-sp4 | 431 | 217 (197 + 20) | 57 | 207 | 7 |

Windows 2000's HAL matches stock far better (half the functions by body), so most of its generic code is Microsoft's Windows 2000 HAL code and the
no-stock-body remainder (about 207) is an upper bound on SGI-specific code: it also holds functions that Microsoft's HAL has in a form the stock
HALs on this disc do not (the stock set has no ACPI-free MP variant with the same options). Tying a Windows 2000 function to an NT 4.0 name worked
for only about 112 functions, because the compiler output differs; 7 of them are SGI-specific by name. Functions that touch board-specific
addresses or ports (the three Cobalt blocks `0xc2000000`, `0xc4000000`, `0xc6000000`, the Lithium windows, the PIIX4 power-management block, the
power-management ports `0xfb0` to `0xff0`) number 5 in every build, NT 4.0 and Windows 2000 alike, because most register traffic goes
through mapped pointers set up once (VW-HAL-SGI-03).

### SGI-specific code, by requirement id

Candidates from the NT 4.0 symbols (names in [nt4-mp](hal-builds/nt4-mp.md#sgi-specific-functions)); the same code is in Windows 2000 where a body or name tie exists, and otherwise only by
inference.

| Id | What | Evidence |
|---|---|---|
| VW-HAL-SGI-01 | Cobalt interrupt entry and priority code: `HalpCobaltInterrupt`, `HalpCobaltInterruptStub`, `HalpGetCoApicRedirEntry`, `HalpSetCoApicRedirEntry`, the three-variant (`Dr_`, `V86_`, `Abios_`) entry stubs `HCoIntr`, `HCoStub`, `H8259Intr`, `Hmem`, `SoftPwrInt`, and the vector tables read by `HalpInitIntrRoute` | established by name and body (NT 4.0) |
| VW-HAL-SGI-02 | Lithium bridge and PCI accessors: `HalpInitLithium`, `HalpInitSGIHostBridge`, `HalpInitializePCIBridge`, the `TypeBorg` read, write and synchronise accessors, `HalpBridgedPciIntPin2SysIntLine`, `HalpGetISAFixedPCIIrq`, `HalpPciIntPin2SysIntLine`, `HalpSysIntLine2PciIntPin` | established (NT 4.0) |
| VW-HAL-SGI-03 | Board-specific addresses and ports occur in 5 functions in every build; Cobalt register traffic otherwise goes through pointers mapped at processor start-up | established |
| VW-HAL-SGI-04 | Super-I/O and power: `Ns307InitChip`, `HalpEnable307Int`, `HalpEnableLiInt`, the PIIX4 reset and power-management routines, `HalpHandlePwrMgmtNMI`, `HalpHandleSoftPowerInt`, `pm_init_intr`, `pm_intr_handler` | established (NT 4.0) |
| VW-HAL-SGI-05 | Memory-controller error handling: `HalpMemErrorHandler`, `HalpEccControl`, `HalpCorrectSoftEccError`, `HalpLogEccError`, `HalpLogMemErrorToCmos` and the message helpers | established (NT 4.0) |
| VW-HAL-SGI-06 | Timers: `HalpCalibrateCobaltTimer`, `HalpInitCoTimer`, `HalpBeginTime` (Cobalt timer calibration against the RTC) | established (NT 4.0) |
| VW-HAL-SGI-07 | Display: the GBE and VGA set-up and text-output routines (`HalpGbe*`, `HalpVga*`, `HalpDisplaySetup`), the two I2C layers (`i2c*`, `mli2c*`) and the graphics-memory split (`HalpSpliceGfxMemory`) | established (NT 4.0) |
| VW-HAL-SGI-08 | Flash and environment variables: `HalpInitFlash`, `HalpWriteFlash`, `HalpFlash*`, `HalpParseFlashVariable`, `HalpInitEnvironmentVariables`, the ARC info readers (`HalpGrabArcRevInfo`, `GetNodeByName`, `DumpArcInfo`) | established (NT 4.0) |
| VW-HAL-SGI-09 | The driver callback interface `sgixCallbackRegister`, `sgixExecuteCallback`, `sgixHalCallbackInitialize`, `HaliQuerySystemInformation` stores `sgixCallbackRegister` into the caller's output buffer for one information class, which is how SGI drivers reach it | established (NT 4.0) |

### Exports

| Id | Fact | Evidence |
|---|---|---|
| VW-HAL-EXP-01 | Both NT 4.0 images export the same 93 names with the same ordinals: 92 functions and the data item `KdComPortInUse` (ordinal 65). Ordinals 1 to 11 are the fast-call group (fast mutexes, software-interrupt calls, `KfAcquireSpinLock` and the other `Kf` calls); 12 onward are alphabetical | established |
| VW-HAL-EXP-02 | The four Windows 2000 images export 98: the 93 plus `KeAcquireQueuedSpinLock`, `KeAcquireQueuedSpinLockRaiseToSynch`, `KeReleaseQueuedSpinLock`, `KeTryToAcquireQueuedSpinLock`, `KeTryToAcquireQueuedSpinLockRaiseToSynch`; `KdComPortInUse` is ordinal 70. The sets are identical across the four builds | established |
| VW-HAL-EXP-03 | None of the exports is a forwarder; the only data export is `KdComPortInUse`. The imports are all from `ntoskrnl.exe`: 81 names in NT 4.0, 111 in Windows 2000 RC3 and RTM, 112 in SP4 beta and SP4 | established |

Full lists are in [nt4-mp](hal-builds/nt4-mp.md#exports) and [w2k-rtm](hal-builds/w2k-rtm.md#exports).

## Structures the code assumes

Offsets are from the disassembly; field names are the public NT x86 layout and so **inferred** unless the table says how the image shows it.

### KPCR (`fs:` on a multiprocessor kernel, the fixed address `0xffdff000` on the uniprocessor kernel)

| Id | Offset | Name (inferred) | Used by (NT 4.0 MP, function counts) | Evidence |
|---|---|---|---|---|
| VW-HAL-PCR-01 | `0x00` | ExceptionList | read and written by 18 interrupt entry stubs; the stubs set it to `0xffffffff` on entry | established |
| VW-HAL-PCR-02 | `0x08` | StackLimit | read by 17 interrupt entry stubs (the ABIOS-variant stubs compare the stack against `0x10000`) | established |
| VW-HAL-PCR-03 | `0x1c` | SelfPcr | read by 13 functions (`HalInitializeProcessor`, `HalpInitLocalAPIC`, `HalpInitializeClock`, ...) | established offset, name inferred |
| VW-HAL-PCR-04 | `0x20` | Prcb (pointer; every PRCB access goes through it) | 26 functions | established |
| VW-HAL-PCR-05 | `0x3c`, `0x40` | GDT, TSS (borrow and return the TSS) | `HalpBorrowTss`, `HalpReturnTss`, `HalpBiosCall` | established offsets, names inferred |
| VW-HAL-PCR-06 | `0x48` | SetMember | `HalpPollForBroadcast` | inferred |
| VW-HAL-PCR-07 | `0x4c` | StallScaleFactor | read by `KeStallExecutionProcessor`; written by `HalpScaleTimers` and `HalInitializeProcessor` | established |
| VW-HAL-PCR-08 | `0x50` | DebugActive and Number (dword read at the start of each interrupt entry stub) | 18 stubs | established offset, name inferred |
| VW-HAL-PCR-09 | `0x51` | Number | `HalpInitializeClock`, `HalAllProcessorsStarted` (through a loaded SelfPcr) | inferred |
| VW-HAL-PCR-10 | `0x94`, `0x95`, `0x96`, `0x98`, `0xa0`, `0xa4`, `0xa8` (`0xac` in Windows 2000) | HalReserved area: the HAL's own per-processor words and flag bytes. `0x95` and `0x96` hold the pending-software-interrupt and DPC flags used by `HalBeginSystemInterrupt`, `HalEndSystemInterrupt`, `HalpSetDpcPending`, `HalpCmpShortDpc`; `0x98`, `0xa0`, `0xa4`, `0xa8` are touched by profile and performance-counter scaling (`HalSetProfileInterval`, `HalStartProfileInterrupt`, `KeQueryPerformanceCounter`, `HalpScaleTimers`) | established offsets and users; the purposes of the flag bytes are inferred from the users' names |

Unused in every build: the KPCR above `0xb0` is never touched through `fs:`. In the four Windows 2000 builds no function touches `0x00`, `0x08`, `0x3c`, `0x50` or `0x94` (the NT 4.0 interrupt entry stubs that use them are gone) and `0xac` is new; the Windows 2000 PRCB accesses are `0x10`, `0x19` and `0x3bc` only (no debug-register restore). Negative claims cover every function range Ghidra found; code hidden in data would escape the scan.

### KPRCB (through the pointer at KPCR `0x20`)

| Id | Offset | Name (inferred) | Use | Evidence |
|---|---|---|---|---|
| VW-HAL-PRCB-01 | `0x10` | Number | `HalpGetCpuFeatureBits`, `HalpRegisterInternalBusHandlers`, `HalpInitOtherBuses` | established offset |
| VW-HAL-PRCB-02 | `0x18` | CpuType | `HalpLocalApicErrorService` | inferred |
| VW-HAL-PRCB-03 | `0x19` | CpuID flag (non-zero means the CPUID instruction exists) | `HalpFlushTLB` runs CPUID, tests feature bit 13 (PGE) and, when set, clears CR4 bit 7 around the CR3 reload | established (the use), name inferred |
| VW-HAL-PRCB-04 | `0xf8` to `0x10c`, six dwords | the saved debug registers DR0, DR1, DR2, DR3, DR6, DR7 | each interrupt entry stub saves the interrupted DRs into trap-frame words `+0x18` to `+0x2c` and loads these six into DR0 to DR7 | established |
| VW-HAL-PRCB-05 | `0x3bc` | (Windows 2000 only) three reads | three Windows 2000 functions | established offset, field unidentified |

### HalDispatchTable and HalPrivateDispatchTable

Both are imported data in every build; the HAL stores code addresses into them. Slot meaning is inferred from the name of the stored routine (NT 4.0
from the symbol file) or from the public slot order (Windows 2000, whose routines are unnamed).

| Id | Table and slot | NT 4.0 (mp and up) | Windows 2000 (all four builds) | Evidence |
|---|---|---|---|---|
| VW-HAL-DISP-01 | HalDispatchTable `+0x04` | `HaliQuerySystemInformation` | stored by `HalInitSystem` | established store, slot name inferred |
| VW-HAL-DISP-02 | HalDispatchTable `+0x08` | `HalpSetSystemInformation` | stored by `HalInitSystem` | same |
| VW-HAL-DISP-03 | HalDispatchTable `+0x0c`, `+0x10` | `HaliQueryBusSlots`, `HaliDeviceControl` (stored by `HalpInitBusHandler`) | not stored | established |
| VW-HAL-DISP-04 | HalDispatchTable `+0x28`, `+0x2c`, `+0x30` | `HaliReferenceHandlerForBus`, `HaliReferenceBusHandler`, `HaliDereferenceBusHandler` | stored, routines unnamed | established |
| VW-HAL-DISP-05 | HalDispatchTable `+0x34`, `+0x3c`, `+0x40` | not stored | stored by `HalInitSystem` (the `+0x3c` and `+0x40` targets are not at a function start Ghidra found) | established stores; slot names inferred (PnP driver initialisation, DMA adapter, interrupt translator) |
| VW-HAL-DISP-06 | HalPrivateDispatchTable `+0x04`, `+0x08` | `HaliHandlerForBus`, `HaliHandlerForConfigSpace` | stored by the bus-handler set-up | established |
| VW-HAL-DISP-07 | HalPrivateDispatchTable `+0x0c` | `HaliCompleteDeviceControl` | not stored | established |
| VW-HAL-DISP-08 | HalPrivateDispatchTable `+0x10` | `HaliRegisterBusHandler` | stored | established |
| VW-HAL-DISP-09 | HalPrivateDispatchTable `+0x1c`, `+0x20`, `+0x28` | not stored | stored (PCI translate, PCI slot-resource assign and bus-address-translation hooks by public slot order) | established stores; slot names inferred |

The NT 4.0 stores are in `HalInitSystem` (`0x8002dc00` MP, `0x8002d720` UP) and `HalpInitBusHandler` (`0x8002fcf0`, `0x8002f3e0`). In Windows 2000 RC3 and RTM
`HalInitSystem` is at `0x8002f131` and the bus-handler set-up (unnamed) at `0x80031384`; in SP4 beta and SP4 at `0x8002f1f1` and `0x80031452`.

### Bus handler object

Read from `HaliRegisterBusHandler` (NT 4.0 `0x80029050`) and the three installers (`HalpRegisterInternalBusHandlers`, `HalpAllocateAndInitPciBusHandler`).
The allocation is the handler size plus `0x78` bytes, pool tag `BusH`, zeroed. The pointer handed back to callers is **allocation + 0xc**: the first
`0xc` bytes are a hidden header (the list link and, at allocation `+8`, a reference count that starts at 1). Offsets below are from the handler pointer.

| Id | Handler offset | Field (inferred from the public BUS_HANDLER layout) | Evidence |
|---|---|---|---|
| VW-HAL-BUS-01 | `+0x04`, `+0x08`, `+0x0c` | InterfaceType, ConfigurationType, BusNumber (stored from the three arguments) | established |
| VW-HAL-BUS-02 | `+0x14` | ParentHandler (the result of `HaliReferenceHandlerForBus` for the parent) | established |
| VW-HAL-BUS-03 | `+0x18` | BusData: set to the `0x78`-byte extension that follows the handler when the caller asked for one | established |
| VW-HAL-BUS-04 | `+0x34`, `+0x38`, `+0x3c`, `+0x40`, `+0x44`, `+0x48` | GetBusData, SetBusData, AdjustResourceList, AssignSlotResources, GetInterruptVector, TranslateBusAddress: stored by the internal-bus and PCI installers. Defaults installed first are `HalpNoBusData`, `HalpNoAdjustResourceList`, `HalpNoAssignSlotResources`; a child inherits its parent's pointers (copy loop in `HaliRegisterBusHandler`) | established |
| VW-HAL-BUS-05 | `+0x34` to `+0x48` and `+0x58` to `+0x68` | a child bus handler is created by copying these slots from its parent, then the installer overwrites what it implements | established |
| VW-HAL-BUS-06 | `+0x58`, `+0x5c`, `+0x60`, `+0x64`, `+0x68` | QueryBusSlots, ReferenceDeviceHandler, DeviceControl, GetDeviceData, SetDeviceData: defaults `HalpNoQueryBusSlots`, `HalpNoReferenceDeviceHandler`, `HalpNoDeviceControl`, `HalpNoGetDeviceData`, `HalpNoSetDeviceData` | established |
| VW-HAL-BUS-07 | PCI bus data block, reached through handler `+0x18` | signature `PCI ` (`0x20494350`) at `+0`, the value 1 at `+4`, `HalpReadPCIConfig` at `+8`, `HalpWritePCIConfig` at `+0xc`, `HalpPciIntPin2SysIntLine` at `+0x10`, `HalpSysIntLine2PciIntPin` at `+0x14`, two words copied from the caller's record at `+0x2c` and `+0x30`, `HalpGetISAFixedPCIIrq` at `+0x34`, the bus number at `+0x40`; `HalpInitSGIHostBridge` runs next | established |

The PCI sub-bus creator (`HalpCreatePCISubBus`) overwrites the block's `+0x10` with `HalpBridgedPciIntPin2SysIntLine`. The two interrupt-pin hooks, the ISA fixed-IRQ hook and the host-bridge call are SGI's (VW-HAL-SGI-02).

### DMA adapter object

`HalpAllocateAdapter` (NT 4.0 `0x80029420`) creates an adapter object of `0x58` bytes (`0x68` in the case that also allocates the master's pool block) with `ObCreateObject` on the I/O adapter object type, zeroes it, and sets: type `1` at `+0`, size at `+2`, the master adapter pointer at `+4`, map registers per
channel (`1`) at `+8`, the adapter base at `+0xc`, a device queue at `+0x20`, an empty list head at `+0x38`/`+0x3c` and a spin lock at `+0x40` (master only), a bitmap
pointer at `+0x44` to a 64-bit bitmap header at `+0x58` initialised all-ones, and (master only) a `0x300`-byte pool block at `+0x10` with counts at `+0x14` and
`+0x18`. This is Microsoft's generic ISA/EISA DMA code (VW-HAL-ADAP-01, established; its body is in the stock HAL too).

## Differences between builds

Details and function addresses are in each build page. Summary (VW-HAL-DIFF-01 to 06):

| Id | Pair | Result | Evidence |
|---|---|---|---|
| VW-HAL-DIFF-01 | nt4-mp against nt4-up | Same 93 exports and ordinals. MP only: the real-mode processor start stub (`StartPx_RMStub`, `StartPx_PMStub`), `HalpStartProcessor`, `HalpGetProcessorInfo`, `HalpBuildTiledCR3`, `HalpMapCR3`, `HalpFreeTiledCR3`, and `KeAcquireSpinLockRaiseToSynchMCE` (8 named; the symbol-record gap is 13 with data labels). Of the shared 551 functions 485 have the same shape, 44 differ, 30 do not match. The UP image reaches the PCR at the fixed address `0xffdff000`; the MP image uses `fs:` | established |
| VW-HAL-DIFF-02 | nt4 against Windows 2000 | Exports: the same 92 code names plus five queued-spin-lock exports (`KeAcquireQueuedSpinLock`, `KeAcquireQueuedSpinLockRaiseToSynch`, `KeReleaseQueuedSpinLock`, `KeTryToAcquireQueuedSpinLock`, `KeTryToAcquireQueuedSpinLockRaiseToSynch`); 98 exports, ordinals after ordinal 6 shift. Functions 559 to 430 (the MP symbol list includes the data labels Ghidra turned into functions). The HalDispatchTable and HalPrivateDispatchTable stores change as listed above | established |
| VW-HAL-DIFF-03 | w2k-rc3 against w2k-rtm | Code identical function by function (430 of 430 same shape). Byte differences: 12 bytes in `.text` (the TimeDateStamp copies in the debug directory records), 3 bytes in the export directory (its time stamp) and 4 bytes of the version resource. No code or table change | established |
| VW-HAL-DIFF-04 | w2k-rtm against w2k-sp4beta | 417 of 431 functions have the same shape; 9 differ and 5 do not match (list in [w2k-sp4beta](hal-builds/w2k-sp4beta.md)). One added function net. The changes, from the disassembly (details in the build page): `HalSetSystemInformation` (the HalDispatchTable `+8` target) now records the calling process id when a setting is made and refuses a change from another process with `0xc0000001`; two small predicates now return a comparison against a global instead of a register; four resource-range routines read two fields in the opposite order (same sum); the vector-to-entry bookkeeping changes its table indexing and uses unsigned compares; the large range-merge routine takes an extra 32-bit addend argument; and a start-up routine copies one more byte from a structure into a global. Nothing in the Cobalt, Lithium or interrupt-routing tables changed | | established; purposes inferred |
| VW-HAL-DIFF-05 | w2k-sp4beta against w2k-sp4 | Identical code, tables and exports; differences are 16 bytes of debug-directory time stamps, and 4 bytes of the version resource | established |
| VW-HAL-DIFF-06 | Boards | Windows 2000 selects among four tables where NT 4.0 selects among three, and has `INTRROUTE=HUGH2` only: see [nt-hal.md](nt-hal.md#the-windows-2000-builds). Not re-read here | cited |

## Not held, and searches

- **Symbol files for Windows 2000 builds.** No `halborg.pdb` or `.dbg` for any Windows 2000 build is held. Searches: the Library for `halborg pdb` and
  `halborg symbols Windows 2000` (no hits), the cache's visws driver set and `oemcd` set (only `halborg.dbg` and `halbrgup.dbg`, both NT 4.0), and the
  Windows 2000 SP4 5-in-1 disc (no symbol directory). The PDB 2.00 import failure the project already knows was therefore not re-run.
- **NT 4.0 service-pack-matched Microsoft symbols.** The only Microsoft HAL symbol files held are SP1 ones on Recovery CD-1; the stock HALs compared are SP4.
- **Other Windows 2000 builds** (RC1, RC2, SP1 to SP3): not held. The cache holds RC3, RTM, SP4 beta and SP4 only.
- **Cross-checks not done.** SGI's Windows 2000 HAL has no stripped-source twin on the same media for the SGI parts, so the Windows 2000 SGI-specific count is an upper bound.

## Rebuilding

`tools/visws-hal/build.sh` ([README](../../tools/visws-hal/README.md)) rebuilds every export from the holdings by SHA-256 with `retools/tools/re-run --ghidra-export`
and writes the statistics and scan results this page cites. The Ghidra export tool deletes its project after writing the export, so the durable product is the JSON
(`decompile.json`, 1.3 MB per build), kept out of the repository; `build.sh` regenerates it.
