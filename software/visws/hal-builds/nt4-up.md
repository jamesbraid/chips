# NT 4.0 uniprocessor halbrgup.dll (nt4-up)

Part of the [build-by-build HAL reading](../hal-builds.md); requirement ids are defined there. Everything here is from the
disassembly of the image (capstone over the function bounds Ghidra found); the export was produced by `tools/visws-hal/build.sh`.

| Item | Value |
|---|---|
| SHA-256 | `21978c787a37744ee6c8037a20b21e41c3401be92fde01ee6abfa154ea1f7de8` |
| Size | 140064 bytes |
| Version resource | `4.00` |
| PE time stamp | 925217773 |
| Image base | `0x80010000` |
| Sections (RVA, size) | `.text` `0x2e0` (+`0xfd15`), `.data` `0x10000` (+`0x8aa0`), `PAGELK` `0x18aa0` (+`0x6b2`), `PAGE` `0x19160` (+`0x28b0`), `.edata` `0x1ba20` (+`0xb41`), `INIT` `0x1c580` (+`0x446a`), `.rsrc` `0x20a00` (+`0x3a4`), `.reloc` `0x20dc0` (+`0x1550`) |
| Imports | ntoskrnl.exe: 81 |
| Exports | 93 (92 code, 1 data) |
| Functions | 551 (decompiled 531) |
| Name sources | ANALYSIS 65, DEFAULT 41, IMPORTED 445 |

Source: Silicon Graphics Recovery CD-1 v1.1, `I386/halbrgup.dll`; symbols `halbrgup.dbg` (SHA-256 `af0c10e5...9ea1f7de8`, 1,037 records, 592 function-type, 439 labels,
81 function records not turned into functions). 531 of 551 functions decompile.

## Exports

Identical to [nt4-mp](nt4-mp.md#exports): the same 93 names and ordinals.

## Against the multiprocessor build (VW-HAL-DIFF-01)

Named only in the multiprocessor image: `KeAcquireSpinLockRaiseToSynchMCE`, `StartPx_RMStub`, `StartPx_PMStub`, `HalpBuildTiledCR3`, `HalpFreeTiledCR3`,
`HalpGetProcessorInfo`, `HalpMapCR3`, `HalpStartProcessor`. Named only in this image: none. Matching this image's 551 functions against the multiprocessor image: 486 have the same shape, 45 are near matches (interrupt entries, clock, profile and processor-start code) and 20
differ (spin locks, fast mutexes and the processor start code).

## Kernel structure use (VW-HAL-PCR, VW-HAL-PRCB)

KPCR offsets seen through `fs:` and, on the uniprocessor image, through the fixed address `0xffdff000`. Each cell is functions / reads / writes. "Uncovered code" is code no function Ghidra found covers (23672 bytes of executable sections), disassembled linearly, so a cell there can include a mis-decoded data run; offsets of `0x400` and above are dropped as such. The last column is the operand size in bytes.

| KPCR offset | `fs:` in functions | `0xffdff000`+offset in functions | `fs:` in uncovered code | Size |
|---|---|---|---|---|
| `0x0` | 18 / 18 / 17 | - | - | 4 |
| `0x8` | 17 / 17 / 0 | - | - | 4 |
| `0x20` | 18 / 18 / 0 | 8 / 8 / 0 | - | 4 |
| `0x3c` | - | 2 / 2 / 0 | - | - |
| `0x40` | 1 / 1 / 0 | 2 / 0 / 2 | - | 4 |
| `0x48` | - | 1 / 1 / 0 | - | - |
| `0x4c` | - | 2 / 1 / 1 | - | - |
| `0x50` | - | 18 / 18 / 0 | - | - |
| `0x94` | - | 1 / 1 / 0 | - | - |
| `0x95` | - | 3 / 1 / 2 | - | - |
| `0x96` | - | 2 / 1 / 2 | - | - |
| `0x98` | - | 2 / 2 / 1 | - | - |
| `0xa0` | - | 3 / 1 / 2 | - | - |
| `0xa4` | - | 2 / 2 / 2 | - | - |
| `0xa8` | - | 2 / 2 / 1 | - | - |

Fields reached through a register loaded from `fs:[0x1c]` (PCR) or `fs:[0x20]` (PRCB). The last column lists the instructions, `*idx` meaning an indexed address.

| Base and offset | Where | Functions / reads / writes | Instructions |
|---|---|---|---|
| `PRCB+0xf8` | functions | 18 / 18 / 0 | mov |
| `PRCB+0xfc` | functions | 18 / 18 / 0 | mov |
| `PRCB+0x100` | functions | 18 / 18 / 0 | mov |
| `PRCB+0x104` | functions | 18 / 18 / 0 | mov |
| `PRCB+0x108` | functions | 18 / 18 / 0 | mov |
| `PRCB+0x10c` | functions | 18 / 18 / 0 | mov |

Functions that use an immediate in `0xffdff000`-`0xffdfffff` (the fixed PCR address): `HalAllProcessorsStarted`, `HalInitSystem`, `HalInitializeProcessor`, `_HalpAttach8259Handler@0`, `_HalpEnableNMI@0`, `_HalpGetCpuFeatureBits@0`, `_HalpInitLocalAPIC@0`, `_HalpInitMP@8`, `_HalpInitSoftPower@4`, `_HalpInitializeClock@4`, `_HalpResetThisProcessor@0`, `_HalpSetInternalVector@8`, `_HalpSpliceVersionInfo@0`.

Names and uses are in [the structure tables](../hal-builds.md#structures-the-code-assumes).

The uniprocessor image still reaches the PCR through `fs:` in its interrupt entry stubs (`0x00`, `0x08` and `0x20` in 18 functions each, `0x40` in `HalpBiosCall`) and also through the fixed address `0xffdff000`: eight functions read the Prcb pointer at `+0x20` that way, and the other offsets in the second column are absolute-only. That the PRCB sits at PCR `+0x120` is the public layout (inferred); the image shows only the pointer at `+0x20` and the debug-register area at PRCB `+0xf8`.

## Dispatch table stores (VW-HAL-DISP)

| Stored by | Table | Slot | Routine |
|---|---|---|---|
| `HalInitSystem` (`0x8002d720`) | HalDispatchTable | `+0x4` | `_HaliQuerySystemInformation@16` |
| `HalInitSystem` (`0x8002d720`) | HalDispatchTable | `+0x8` | `_HalpSetSystemInformation@12` |
| `_HalpInitBusHandler@0` (`0x8002f3e0`) | HalPrivateDispatchTable | `+0x10` | `_HaliRegisterBusHandler@32` |
| `_HalpInitBusHandler@0` (`0x8002f3e0`) | HalPrivateDispatchTable | `+0x4` | `HaliHandlerForBus` |
| `_HalpInitBusHandler@0` (`0x8002f3e0`) | HalPrivateDispatchTable | `+0x8` | `HaliHandlerForConfigSpace` |
| `_HalpInitBusHandler@0` (`0x8002f3e0`) | HalDispatchTable | `+0xc` | `_HaliQueryBusSlots@16` |
| `_HalpInitBusHandler@0` (`0x8002f3e0`) | HalDispatchTable | `+0x10` | `_HaliDeviceControl@28` |
| `_HalpInitBusHandler@0` (`0x8002f3e0`) | HalPrivateDispatchTable | `+0xc` | `_HaliCompleteDeviceControl@4` |
| `_HalpInitBusHandler@0` (`0x8002f3e0`) | HalDispatchTable | `+0x28` | `HaliReferenceHandlerForBus` |
| `_HalpInitBusHandler@0` (`0x8002f3e0`) | HalDispatchTable | `+0x2c` | `HaliReferenceBusHandler` |
| `_HalpInitBusHandler@0` (`0x8002f3e0`) | HalDispatchTable | `+0x30` | `HaliDereferenceBusHandler` |

## Functions using board addresses or ports (VW-HAL-SGI-03)

`_HalpHandlePwrMgmtNMI@0` (pm-latch, pm-nmi-port); `pm_init_intr` (piix4-pm, piix4-pm-ctl); `pm_intr_handler` (piix4-pm, piix4-pm-ctl); `_HalpPwrMgmtSuspend@0` (piix4-pm-ctl, pm-port); `HalInitializeProcessor` (cobalt-apic, cobalt-cpu, cobalt-mem).

## Against the stock Microsoft HALs on the same media

Shape and trigram match (method in [the index](../hal-builds.md#sgi-specific-versus-generic)): exact 94, near 11, by string use 1, no match 445; 58 of the functions have fewer than four instructions.

