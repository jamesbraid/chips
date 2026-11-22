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
`HalpGetProcessorInfo`, `HalpMapCR3`, `HalpStartProcessor`. Named only in this image: none. Of the 551 functions here, 486 have the same shape in the
multiprocessor image, 45 are near matches (the interrupt entries and the clock and profile code, which use the fixed PCR address here and `fs:` there) and 20
differ (spin locks, fast mutexes and the processor start code).

## Kernel structure use (VW-HAL-PCR, VW-HAL-PRCB)

KPCR offsets read through `fs:` (or the fixed uniprocessor address `0xffdff000`). Columns: functions touching the offset, reads, writes.

| KPCR offset | Functions | Reads | Writes |
|---|---|---|---|
| `0x0` | 18 | 18 | 17 |
| `0x8` | 17 | 17 | 0 |
| `0x20` | 2 | 2 | 0 |
| `0x3c` | 2 | 2 | 0 |
| `0x40` | 2 | 0 | 2 |
| `0x48` | 1 | 1 | 0 |
| `0x4c` | 2 | 1 | 1 |
| `0x50` | 18 | 18 | 0 |
| `0x94` | 1 | 1 | 0 |
| `0x95` | 3 | 1 | 2 |
| `0x96` | 2 | 1 | 2 |
| `0x98` | 2 | 2 | 1 |
| `0xa0` | 3 | 1 | 2 |
| `0xa4` | 2 | 2 | 2 |
| `0xa8` | 2 | 2 | 1 |

Fields reached through a register loaded from `fs:[0x1c]` (PCR) or `fs:[0x20]` (PRCB).

| Base and offset | Functions | Reads | Writes |
|---|---|---|---|
| `PRCB+0xf8` | 18 | 18 | 0 |
| `PRCB+0xfc` | 18 | 18 | 0 |
| `PRCB+0x100` | 18 | 18 | 0 |
| `PRCB+0x104` | 18 | 18 | 0 |
| `PRCB+0x108` | 18 | 18 | 0 |
| `PRCB+0x10c` | 18 | 18 | 0 |

Names and uses are in [the structure tables](../hal-builds.md#structures-the-code-assumes).

The uniprocessor kernel keeps its single PCR at a fixed address, so this image reads the PCR through absolute addresses and not
through `fs:`; the PRCB is at PCR `+0x120`. The offsets in the first table are the same fields as on the multiprocessor page.

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

