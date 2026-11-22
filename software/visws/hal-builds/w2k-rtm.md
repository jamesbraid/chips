# Windows 2000 RTM halborg.dll (w2k-rtm)

Part of the [build-by-build HAL reading](../hal-builds.md); requirement ids are defined there. Everything here is from the
disassembly of the image (capstone over the function bounds Ghidra found); the export was produced by `tools/visws-hal/build.sh`.

| Item | Value |
|---|---|
| SHA-256 | `a51bb5188fa40b73c32928cea419f10e8f01a1851acdd3f380b6aea9806a2672` |
| Size | 148672 bytes |
| Version resource | `5.00.2168.1` |
| PE time stamp | 941323696 |
| Image base | `0x80010000` |
| Sections (RVA, size) | `.text` `0x340` (+`0xff31`), `_INIT16` `0x10280` (+`0x45`), `.data` `0x102e0` (+`0x8e7c`), `PAGELK` `0x19160` (+`0xeaa`), `PAGE` `0x1a020` (+`0x3c9b`), `.edata` `0x1dcc0` (+`0xc0d`), `INIT` `0x1e8e0` (+`0x41fa`), `.rsrc` `0x22ae0` (+`0x3b0`), `.reloc` `0x22ea0` (+`0x161c`) |
| Imports | ntoskrnl.exe: 111 |
| Exports | 98 (97 code, 1 data) |
| Functions | 430 (decompiled 430) |
| Name sources | DEFAULT 333, IMPORTED 97 |

Source: Library cache (RTM, build 2168.1). No symbol file is held for any Windows 2000 build; the 97 code exports are the only names.

## Exports

1 `ExAcquireFastMutex`, 2 `ExReleaseFastMutex`, 3 `ExTryToAcquireFastMutex`, 4 `HalClearSoftwareInterrupt`, 5 `HalRequestSoftwareInterrupt`, 6 `HalSystemVectorDispatchEntry`, 7 `KeAcquireQueuedSpinLock`, 8 `KeAcquireQueuedSpinLockRaiseToSynch`, 9 `KeAcquireSpinLockRaiseToSynch`, 10 `KeReleaseQueuedSpinLock`, 11 `KeTryToAcquireQueuedSpinLock`, 12 `KeTryToAcquireQueuedSpinLockRaiseToSynch`, 13 `KfAcquireSpinLock`, 14 `KfLowerIrql`, 15 `KfRaiseIrql`, 16 `KfReleaseSpinLock`, 17 `HalAcquireDisplayOwnership`, 18 `HalAdjustResourceList`, 19 `HalAllProcessorsStarted`, 20 `HalAllocateAdapterChannel`, 21 `HalAllocateCommonBuffer`, 22 `HalAllocateCrashDumpRegisters`, 23 `HalAssignSlotResources`, 24 `HalBeginSystemInterrupt`, 25 `HalCalibratePerformanceCounter`, 26 `HalDisableSystemInterrupt`, 27 `HalDisplayString`, 28 `HalEnableSystemInterrupt`, 29 `HalEndSystemInterrupt`, 30 `HalFlushCommonBuffer`, 31 `HalFreeCommonBuffer`, 32 `HalGetAdapter`, 33 `HalGetBusData`, 34 `HalGetBusDataByOffset`, 35 `HalGetEnvironmentVariable`, 36 `HalGetInterruptVector`, 37 `HalHandleNMI`, 38 `HalInitSystem`, 39 `HalInitializeProcessor`, 40 `HalMakeBeep`, 41 `HalProcessorIdle`, 42 `HalQueryDisplayParameters`, 43 `HalQueryRealTimeClock`, 44 `HalReadDmaCounter`, 45 `HalReportResourceUsage`, 46 `HalRequestIpi`, 47 `HalReturnToFirmware`, 48 `HalSetBusData`, 49 `HalSetBusDataByOffset`, 50 `HalSetDisplayParameters`, 51 `HalSetEnvironmentVariable`, 52 `HalSetProfileInterval`, 53 `HalSetRealTimeClock`, 54 `HalSetTimeIncrement`, 55 `HalStartNextProcessor`, 56 `HalStartProfileInterrupt`, 57 `HalStopProfileInterrupt`, 58 `HalTranslateBusAddress`, 59 `HalxFlushMdl`, 60 `HalxFlushPhysicalBuffer`, 61 `HalxFlushVirtualBuffer`, 62 `IoAssignDriveLetters`, 63 `IoFlushAdapterBuffers`, 64 `IoFreeAdapterChannel`, 65 `IoFreeMapRegisters`, 66 `IoMapTransfer`, 67 `IoReadPartitionTable`, 68 `IoSetPartitionInformation`, 69 `IoWritePartitionTable`, 70 `KdComPortInUse` (data), 71 `KdPortGetByte`, 72 `KdPortInitialize`, 73 `KdPortPollByte`, 74 `KdPortPutByte`, 75 `KdPortRestore`, 76 `KdPortSave`, 77 `KeAcquireSpinLock`, 78 `KeFlushWriteBuffer`, 79 `KeGetCurrentIrql`, 80 `KeLowerIrql`, 81 `KeQueryPerformanceCounter`, 82 `KeRaiseIrql`, 83 `KeRaiseIrqlToDpcLevel`, 84 `KeRaiseIrqlToSynchLevel`, 85 `KeReleaseSpinLock`, 86 `KeStallExecutionProcessor`, 87 `READ_PORT_BUFFER_UCHAR`, 88 `READ_PORT_BUFFER_ULONG`, 89 `READ_PORT_BUFFER_USHORT`, 90 `READ_PORT_UCHAR`, 91 `READ_PORT_ULONG`, 92 `READ_PORT_USHORT`, 93 `WRITE_PORT_BUFFER_UCHAR`, 94 `WRITE_PORT_BUFFER_ULONG`, 95 `WRITE_PORT_BUFFER_USHORT`, 96 `WRITE_PORT_UCHAR`, 97 `WRITE_PORT_ULONG`, 98 `WRITE_PORT_USHORT`.

## Kernel structure use (VW-HAL-PCR, VW-HAL-PRCB)

KPCR offsets seen through `fs:` and, on the uniprocessor image, through the fixed address `0xffdff000`. Each cell is functions / reads / writes. "Uncovered code" is code no function Ghidra found covers (38772 bytes of executable sections), disassembled linearly, so a cell there can include a mis-decoded data run; offsets of `0x400` and above are dropped as such. The last column is the operand size in bytes.

| KPCR offset | `fs:` in functions | `0xffdff000`+offset in functions | `fs:` in uncovered code | Size |
|---|---|---|---|---|
| `0x0` | - | - | 8 / 18 / 17 | 4 |
| `0x8` | - | - | 7 / 17 / 0 | 4 |
| `0x1c` | 14 / 32 / 0 | - | - | 4 |
| `0x20` | 10 / 10 / 0 | - | 8 / 19 / 0 | 4 |
| `0x3c` | - | - | 1 / 2 / 0 | 4 |
| `0x40` | 1 / 1 / 0 | - | 1 / 0 / 2 | 4 |
| `0x48` | 1 / 1 / 0 | - | - | 4 |
| `0x4c` | 2 / 1 / 1 | - | - | 4 |
| `0x50` | - | - | 8 / 18 / 0 | 1 |
| `0x94` | - | - | 1 / 1 / 0 | 1 |
| `0x95` | 3 / 1 / 2 | - | - | 1 |
| `0x96` | 2 / 1 / 2 | - | - | 1 |
| `0x98` | 2 / 2 / 1 | - | - | 4 |
| `0xa0` | 3 / 1 / 2 | - | - | 4 |
| `0xa4` | 2 / 2 / 2 | - | - | 4 |
| `0xa8` | 1 / 0 / 1 | - | 1 / 2 / 2 | 2,4 |
| `0xac` | 1 / 0 / 1 | - | - | 4 |

Fields reached through a register loaded from `fs:[0x1c]` (PCR) or `fs:[0x20]` (PRCB). The last column lists the instructions, `*idx` meaning an indexed address.

| Base and offset | Where | Functions / reads / writes | Instructions |
|---|---|---|---|
| `PCR+0x98` | functions | 1 / 1 / 0 | mov |
| `PCR+0x20` | functions | 5 / 5 / 0 | mov |
| `PCR+0x30` | functions | 1 / 1 / 1 | or |
| `PCR+0x38` | functions | 5 / 18 / 0 | mov |
| `PCR+0x4c` | functions | 1 / 0 / 1 | mov |
| `PCR+0x51` | functions | 2 / 2 / 0 | cmp |
| `PRCB+0x10` | functions | 2 / 2 / 0 | cmp |
| `PRCB+0x19` | functions | 1 / 1 / 0 | cmp |
| `PRCB+0x3bc` | functions | 3 / 3 / 0 | lea*idx |
| `PRCB+0x6e` | uncovered code | 1 / 1 / 0 | arpl |
| `PRCB+0x18` | uncovered code | 1 / 1 / 0 | cmp |
| `PRCB+0x2f8` | uncovered code | 8 / 18 / 0 | mov |
| `PRCB+0x2fc` | uncovered code | 8 / 18 / 0 | mov |
| `PRCB+0x300` | uncovered code | 8 / 18 / 0 | mov |
| `PRCB+0x304` | uncovered code | 8 / 18 / 0 | mov |
| `PRCB+0x308` | uncovered code | 8 / 18 / 0 | mov |
| `PRCB+0x30c` | uncovered code | 8 / 18 / 0 | mov |
| `PRCB+0x53` | uncovered code | 1 / 1 / 1 | add |
| `PRCB+0x61` | uncovered code | 1 / 2 / 2 | add*idx,and*idx |

Names and uses are in [the structure tables](../hal-builds.md#structures-the-code-assumes).

## Dispatch table stores (VW-HAL-DISP)

| Stored by | Table | Slot | Routine |
|---|---|---|---|
| `HalInitSystem` (`0x8002f131`) | HalDispatchTable | `+0x4` | code at `0x8002b3a4` |
| `HalInitSystem` (`0x8002f131`) | HalDispatchTable | `+0x8` | code at `0x8002d3e8` |
| `HalInitSystem` (`0x8002f131`) | HalDispatchTable | `+0x34` | code at `0x8002a080` |
| `HalInitSystem` (`0x8002f131`) | HalDispatchTable | `+0x3c` | code at `0x8001665c` |
| `HalInitSystem` (`0x8002f131`) | HalDispatchTable | `+0x40` | code at `0x80019fb9` |
| `FUN_80031384` (`0x80031384`) | HalPrivateDispatchTable | `+0x10` | code at `0x80029ca6` |
| `FUN_80031384` (`0x80031384`) | HalPrivateDispatchTable | `+0x4` | code at `0x8001fea6` |
| `FUN_80031384` (`0x80031384`) | HalPrivateDispatchTable | `+0x8` | code at `0x8001feba` |
| `FUN_80031384` (`0x80031384`) | HalDispatchTable | `+0x28` | code at `0x8001fece` |
| `FUN_80031384` (`0x80031384`) | HalDispatchTable | `+0x2c` | code at `0x8001fe46` |
| `FUN_80031384` (`0x80031384`) | HalDispatchTable | `+0x30` | code at `0x8001fe76` |
| `FUN_80031384` (`0x80031384`) | HalPrivateDispatchTable | `+0x1c` | code at `0x8001ffd2` |
| `FUN_80031384` (`0x80031384`) | HalPrivateDispatchTable | `+0x20` | code at `0x8002d6ca` |
| `FUN_80031384` (`0x80031384`) | HalPrivateDispatchTable | `+0x28` | code at `0x80020052` |

Conditions, read in the disassembly: HalDispatchTable `+0x34`, `+0x3c` and `+0x40` are stored only when the table's version dword is 2 or more; HalPrivateDispatchTable `+0x28` is stored only when that slot is still zero. The other stores are unconditional. The `+0x3c` and `+0x40` targets and the private `+8` target are addresses in code Ghidra did not make functions.

## Functions using board addresses or ports (VW-HAL-SGI-03)

`FUN_8001f13c` (pm-latch, pm-nmi-port); `FUN_8001f320` (piix4-pm, piix4-pm-ctl); `FUN_8001f50d` (piix4-pm, piix4-pm-ctl); `FUN_8001f5f0` (piix4-pm, piix4-pm-ctl, pm-port); `HalInitializeProcessor` (cobalt-apic, cobalt-cpu, cobalt-mem).

## Against the stock Microsoft HALs on the same media

Shape and trigram match (method in [the index](../hal-builds.md#sgi-specific-versus-generic)): exact 195, near 20, by string use 0, no match 215; 56 of the functions have fewer than four instructions.

## Against RC3 and SP4 beta

Against [w2k-rc3](w2k-rc3.md): code and data identical (VW-HAL-DIFF-03). Against [w2k-sp4beta](w2k-sp4beta.md): see that page.
