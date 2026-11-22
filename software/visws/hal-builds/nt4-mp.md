# NT 4.0 multiprocessor halborg.dll (nt4-mp)

Part of the [build-by-build HAL reading](../hal-builds.md); requirement ids are defined there. Everything here is from the
disassembly of the image (capstone over the function bounds Ghidra found); the export was produced by `tools/visws-hal/build.sh`.

| Item | Value |
|---|---|
| SHA-256 | `0926cd500c19401c08707336f92deff08cea9db054a051e236509af70244a048` |
| Size | 142496 bytes |
| Version resource | `4.00` |
| PE time stamp | 925217771 |
| Image base | `0x80010000` |
| Sections (RVA, size) | `.text` `0x300` (+`0xfeb5`), `_INIT16` `0x101c0` (+`0x45`), `.data` `0x10220` (+`0x8b30`), `PAGELK` `0x18d60` (+`0x6b2`), `PAGE` `0x19420` (+`0x28b0`), `.edata` `0x1bce0` (+`0xb41`), `INIT` `0x1c840` (+`0x4aba`), `.rsrc` `0x21300` (+`0x3a4`), `.reloc` `0x216c0` (+`0x15c4`) |
| Imports | ntoskrnl.exe: 81 |
| Exports | 93 (92 code, 1 data) |
| Functions | 559 (decompiled 540) |
| Name sources | ANALYSIS 67, DEFAULT 41, IMPORTED 451 |

Source: Silicon Graphics Recovery CD-1 v1.1, `I386/halborg.dll`; symbols `SUPPORT/DEBUG/I386/SYMBOLS/SGI/DLL/halborg.dbg` (SHA-256 `bdab47a1...c083e03`;
CodeView NB09 publics: 1,050 records, 600 function-type, 444 labels, 81 function records not turned into functions, 1 name Ghidra rejects).
540 of 559 functions decompile.

## Exports

1 `ExAcquireFastMutex`, 2 `ExReleaseFastMutex`, 3 `ExTryToAcquireFastMutex`, 4 `HalClearSoftwareInterrupt`, 5 `HalRequestSoftwareInterrupt`, 6 `HalSystemVectorDispatchEntry`, 7 `KeAcquireSpinLockRaiseToSynch`, 8 `KfAcquireSpinLock`, 9 `KfLowerIrql`, 10 `KfRaiseIrql`, 11 `KfReleaseSpinLock`, 12 `HalAcquireDisplayOwnership`, 13 `HalAdjustResourceList`, 14 `HalAllProcessorsStarted`, 15 `HalAllocateAdapterChannel`, 16 `HalAllocateCommonBuffer`, 17 `HalAllocateCrashDumpRegisters`, 18 `HalAssignSlotResources`, 19 `HalBeginSystemInterrupt`, 20 `HalCalibratePerformanceCounter`, 21 `HalDisableSystemInterrupt`, 22 `HalDisplayString`, 23 `HalEnableSystemInterrupt`, 24 `HalEndSystemInterrupt`, 25 `HalFlushCommonBuffer`, 26 `HalFreeCommonBuffer`, 27 `HalGetAdapter`, 28 `HalGetBusData`, 29 `HalGetBusDataByOffset`, 30 `HalGetEnvironmentVariable`, 31 `HalGetInterruptVector`, 32 `HalHandleNMI`, 33 `HalInitSystem`, 34 `HalInitializeProcessor`, 35 `HalMakeBeep`, 36 `HalProcessorIdle`, 37 `HalQueryDisplayParameters`, 38 `HalQueryRealTimeClock`, 39 `HalReadDmaCounter`, 40 `HalReportResourceUsage`, 41 `HalRequestIpi`, 42 `HalReturnToFirmware`, 43 `HalSetBusData`, 44 `HalSetBusDataByOffset`, 45 `HalSetDisplayParameters`, 46 `HalSetEnvironmentVariable`, 47 `HalSetProfileInterval`, 48 `HalSetRealTimeClock`, 49 `HalSetTimeIncrement`, 50 `HalStartNextProcessor`, 51 `HalStartProfileInterrupt`, 52 `HalStopProfileInterrupt`, 53 `HalTranslateBusAddress`, 54 `HalxFlushMdl`, 55 `HalxFlushPhysicalBuffer`, 56 `HalxFlushVirtualBuffer`, 57 `IoAssignDriveLetters`, 58 `IoFlushAdapterBuffers`, 59 `IoFreeAdapterChannel`, 60 `IoFreeMapRegisters`, 61 `IoMapTransfer`, 62 `IoReadPartitionTable`, 63 `IoSetPartitionInformation`, 64 `IoWritePartitionTable`, 65 `KdComPortInUse` (data), 66 `KdPortGetByte`, 67 `KdPortInitialize`, 68 `KdPortPollByte`, 69 `KdPortPutByte`, 70 `KdPortRestore`, 71 `KdPortSave`, 72 `KeAcquireSpinLock`, 73 `KeFlushWriteBuffer`, 74 `KeGetCurrentIrql`, 75 `KeLowerIrql`, 76 `KeQueryPerformanceCounter`, 77 `KeRaiseIrql`, 78 `KeRaiseIrqlToDpcLevel`, 79 `KeRaiseIrqlToSynchLevel`, 80 `KeReleaseSpinLock`, 81 `KeStallExecutionProcessor`, 82 `READ_PORT_BUFFER_UCHAR`, 83 `READ_PORT_BUFFER_ULONG`, 84 `READ_PORT_BUFFER_USHORT`, 85 `READ_PORT_UCHAR`, 86 `READ_PORT_ULONG`, 87 `READ_PORT_USHORT`, 88 `WRITE_PORT_BUFFER_UCHAR`, 89 `WRITE_PORT_BUFFER_ULONG`, 90 `WRITE_PORT_BUFFER_USHORT`, 91 `WRITE_PORT_UCHAR`, 92 `WRITE_PORT_ULONG`, 93 `WRITE_PORT_USHORT`.

## Kernel structure use (VW-HAL-PCR, VW-HAL-PRCB)

KPCR offsets seen through `fs:` and, on the uniprocessor image, through the fixed address `0xffdff000`. Each cell is functions / reads / writes. "Uncovered code" is code no function Ghidra found covers (23719 bytes of executable sections), disassembled linearly, so a cell there can include a mis-decoded data run; offsets of `0x400` and above are dropped as such. The last column is the operand size in bytes.

| KPCR offset | `fs:` in functions | `0xffdff000`+offset in functions | `fs:` in uncovered code | Size |
|---|---|---|---|---|
| `0x0` | 18 / 18 / 17 | - | - | 4 |
| `0x8` | 17 / 17 / 0 | - | - | 4 |
| `0x1c` | 13 / 31 / 0 | - | - | 4 |
| `0x20` | 26 / 26 / 0 | - | - | 4 |
| `0x3c` | 2 / 2 / 0 | - | - | 4 |
| `0x40` | 3 / 1 / 2 | - | - | 4 |
| `0x48` | 1 / 1 / 0 | - | - | 4 |
| `0x4c` | 2 / 1 / 1 | - | - | 4 |
| `0x50` | 18 / 18 / 0 | - | - | 1 |
| `0x94` | 1 / 1 / 0 | - | - | 1 |
| `0x95` | 3 / 1 / 2 | - | - | 1 |
| `0x96` | 2 / 1 / 2 | - | - | 1 |
| `0x98` | 2 / 2 / 1 | - | - | 4 |
| `0xa0` | 3 / 1 / 2 | - | - | 4 |
| `0xa4` | 2 / 2 / 2 | - | - | 4 |
| `0xa8` | 2 / 2 / 1 | - | 1 / 1 / 1 | 2 |

Fields reached through a register loaded from `fs:[0x1c]` (PCR) or `fs:[0x20]` (PRCB). The last column lists the instructions, `*idx` meaning an indexed address.

| Base and offset | Where | Functions / reads / writes | Instructions |
|---|---|---|---|
| `PCR+0x94` | functions | 2 / 2 / 0 | lea |
| `PCR+0x98` | functions | 1 / 1 / 0 | mov |
| `PCR+0x20` | functions | 4 / 4 / 0 | mov |
| `PCR+0x30` | functions | 1 / 0 / 1 | mov |
| `PCR+0x38` | functions | 5 / 20 / 0 | mov |
| `PCR+0x4c` | functions | 1 / 0 / 1 | mov |
| `PCR+0x51` | functions | 2 / 2 / 0 | cmp |
| `PRCB+0x10` | functions | 3 / 3 / 0 | cmp,movsx |
| `PRCB+0x18` | functions | 1 / 1 / 0 | cmp |
| `PRCB+0xf8` | functions | 18 / 18 / 0 | mov |
| `PRCB+0x19` | functions | 2 / 2 / 0 | cmp |
| `PRCB+0xfc` | functions | 18 / 18 / 0 | mov |
| `PRCB+0x100` | functions | 18 / 18 / 0 | mov |
| `PRCB+0x104` | functions | 18 / 18 / 0 | mov |
| `PRCB+0x108` | functions | 18 / 18 / 0 | mov |
| `PRCB+0x10c` | functions | 18 / 18 / 0 | mov |

Names and uses are in [the structure tables](../hal-builds.md#structures-the-code-assumes).

## Dispatch table stores (VW-HAL-DISP)

| Stored by | Table | Slot | Routine |
|---|---|---|---|
| `HalInitSystem` (`0x8002dc00`) | HalDispatchTable | `+0x4` | `_HaliQuerySystemInformation@16` |
| `HalInitSystem` (`0x8002dc00`) | HalDispatchTable | `+0x8` | `_HalpSetSystemInformation@12` |
| `_HalpInitBusHandler@0` (`0x8002fcf0`) | HalPrivateDispatchTable | `+0x10` | `_HaliRegisterBusHandler@32` |
| `_HalpInitBusHandler@0` (`0x8002fcf0`) | HalPrivateDispatchTable | `+0x4` | `HaliHandlerForBus` |
| `_HalpInitBusHandler@0` (`0x8002fcf0`) | HalPrivateDispatchTable | `+0x8` | `HaliHandlerForConfigSpace` |
| `_HalpInitBusHandler@0` (`0x8002fcf0`) | HalDispatchTable | `+0xc` | `_HaliQueryBusSlots@16` |
| `_HalpInitBusHandler@0` (`0x8002fcf0`) | HalDispatchTable | `+0x10` | `_HaliDeviceControl@28` |
| `_HalpInitBusHandler@0` (`0x8002fcf0`) | HalPrivateDispatchTable | `+0xc` | `_HaliCompleteDeviceControl@4` |
| `_HalpInitBusHandler@0` (`0x8002fcf0`) | HalDispatchTable | `+0x28` | `HaliReferenceHandlerForBus` |
| `_HalpInitBusHandler@0` (`0x8002fcf0`) | HalDispatchTable | `+0x2c` | `HaliReferenceBusHandler` |
| `_HalpInitBusHandler@0` (`0x8002fcf0`) | HalDispatchTable | `+0x30` | `HaliDereferenceBusHandler` |

## Functions using board addresses or ports (VW-HAL-SGI-03)

`_HalpHandlePwrMgmtNMI@0` (pm-latch, pm-nmi-port); `pm_init_intr` (piix4-pm, piix4-pm-ctl); `pm_intr_handler` (piix4-pm, piix4-pm-ctl); `_HalpPwrMgmtSuspend@0` (piix4-pm-ctl, pm-port); `HalInitializeProcessor` (cobalt-apic, cobalt-cpu, cobalt-mem).

## Against the stock Microsoft HALs on the same media

Shape and trigram match (method in [the index](../hal-builds.md#sgi-specific-versus-generic)): exact 93, near 11, by string use 1, no match 454; 57 of the functions have fewer than four instructions.

## SGI-specific functions

The 182 named functions with no counterpart name in the Microsoft HAL symbol files and no body match in the stock NT 4.0 SP4 HALs (inferred; method in the
index). `Dr_`, `V86_` and `Abios_` are the three trap-entry variants the HAL builds for each interrupt entry.

`Abios_H8259Intr_a`, `Abios_HCoIntr_a`, `Abios_HCoStub_a`, `Abios_Hmem_a`, `Abios_SoftPwrInt_a`, `Dr_H8259Intr_a`, `Dr_HCoIntr_a`, `Dr_HCoStub_a`, `Dr_Hmem_a`, `Dr_SoftPwrInt_a`, `HalpGenerateInterrupt`, `HalpLookupHandler`, `HalxFlushMdl`, `HalxFlushPhysicalBuffer`, `HalxFlushVirtualBuffer`, `KeAcquireSpinLockRaiseToSynchMCE`, `V86_H8259Intr_a`, `V86_HCoIntr_a`, `V86_HCoStub_a`, `V86_Hmem_a`, `V86_SoftPwrInt_a`, `_BoardResetAtPIIX4@8`, `_CacheopInitialize@4`, `_CacheopInterrupt@0`, `_DumpArcInfo@4`, `_GetNodeByName@8`, `_GetNodeDeviceData@4`, `_Halp8259Interrupt@0`, `_HalpAddGbeDisplayToRegistry@0`, `_HalpAddMultiFunctionNode@4`, `_HalpAddValueKey@20`, `_HalpAscii2Unicode@8`, `_HalpAttach8259Handler@0`, `_HalpBeginTime@4`, `_HalpBridgedPciIntPin2SysIntLine@16`, `_HalpCalibrateCobaltTimer@0`, `_HalpCheckCompatibility@0`, `_HalpCheckSumSegment@4`, `_HalpClearVgaDisplay@0`, `_HalpCmpShortDpc@4`, `_HalpCobaltInterrupt@0`, `_HalpCobaltInterruptStub@0`, `_HalpCommitNVRAM@0`, `_HalpCopyFlashEntryToWriteBuf@8`, `_HalpCopyShadowVariableName@8`, `_HalpCorrectSoftEccError@12`, `_HalpCreatePCISubBus@16`, `_HalpCreateShadowTable@8`, `_HalpDebugPrint`, `_HalpDeliverPending8259Ints@0`, `_HalpDisable8259Int@4`, `_HalpDisplaySetup@0`, `_HalpDisplayVersion@0`, `_HalpDumpPCIConfig@8`, `_HalpEccControl@4`, `_HalpEnable307Int@12`, `_HalpEnable8259Int@8`, `_HalpEnableLiInt@4`, `_HalpEnumeratePciBus@4`, `_HalpFixupCpuRegistryNode@4`, `_HalpFixupRegistry@0`, `_HalpFlashBlockEraseMultiple@8`, `_HalpFlashPollStatus@12`, `_HalpGbeClearScreen@0`, `_HalpGbeDisplaySetup@0`, `_HalpGbePutCharacter@12`, `_HalpGbeScrollDisplay@0`, `_HalpGenerateChecksum@4`, `_HalpGetBuildDate@4`, `_HalpGetBuildTime@4`, `_HalpGetCoApicRedirEntry@12`, `_HalpGetCpuFeatureBits@0`, `_HalpGetCursorPosition@8`, `_HalpGetFlashAddress@0`, `_HalpGetGbeDisplayLimits@8`, `_HalpGetIntrDataByVector@28`, `_HalpGetIsaVectorByInt@4`, `_HalpGetLiCnfgAddr@4`, `_HalpGetPciInterrupt@24`, `_HalpGetProcessorInfo@4`, `_HalpGetSystemGenome@0`, `_HalpGrabArcRevInfo@4`, `_HalpGrabSystemName@4`, `_HalpHandleCoNMI@0`, `_HalpHandlePwrMgmtNMI@0`, `_HalpHandleSoftPowerInt@0`, `_HalpInit8259@4`, `_HalpInitAdapterObjects@4`, `_HalpInitBarArray@8`, `_HalpInitCoTimer@0`, `_HalpInitDebug@4`, `_HalpInitEnvironmentVariables@0`, `_HalpInitFlash@4`, `_HalpInitIntrRoute@0`, `_HalpInitLithium@0`, `_HalpInitLocalAPIC@0`, `_HalpInitMemErrSubsystem@0`, `_HalpInitSGIHostBridge@8`, `_HalpInitSerialPort@8`, `_HalpInitShadowTable@4`, `_HalpInitSoftPower@4`, `_HalpInitializeDisplay0@4`, `_HalpInitializeDisplay1@4`, `_HalpInitializeGbeDisplay0@4`, `_HalpInitializeGbeDisplay1@4`, `_HalpInitializeInterrupts@4`, `_HalpInitializePCIBridge@20`, `_HalpInitializePCIFunction@16`, `_HalpInitializeRtc@0`, `_HalpInitializeVgaDisplay@0`, `_HalpIsValidPCISlot@8`, `_HalpIssue8259EOI@4`, `_HalpLock8259@0`, `_HalpLogEccError@12`, `_HalpLogMemErrorToCmos@12`, `_HalpMakeNewImage@8`, `_HalpMemErrInterrupt@0`, `_HalpMemErrorAccessTypeMsg@4`, `_HalpMemErrorEccTypeMsg@4`, `_HalpMemErrorHandler@0`, `_HalpMemErrorInvTypeMsg@4`, `_HalpMemErrorMsg@12`, `_HalpMonth2Ordinal@4`, `_HalpPCIReadUcharTypeBorg@16`, `_HalpPCIReadUlongTypeBorg@16`, `_HalpPCIReadUshortTypeBorg@16`, `_HalpPCIReleaseSynchronzationTypeBorg@8`, `_HalpPCISynchronizeTypeBorg@16`, `_HalpPCIWriteUcharTypeBorg@16`, `_HalpPCIWriteUlongTypeBorg@16`, `_HalpPCIWriteUshortTypeBorg@16`, `_HalpParseFlashVariable@8`, `_HalpPciIntPin2SysIntLine@16`, `_HalpPwrMgmtSuspend@0`, `_HalpRemapKseg0Pages@16`, `_HalpRemapVirtualAddr@16`, `_HalpSerialPutChar@4`, `_HalpSetCoApicRedirEntry@12`, `_HalpSetCursorPosition@8`, `_HalpShadowBuffer@8`, `_HalpSpliceGfxMemory@4`, `_HalpSpliceVersionInfo@0`, `_HalpStringCksum@4`, `_HalpSysIntLine2PciIntPin@20`, `_HalpSzInterruptAffinity`, `_HalpSzTimerRes`, `_HalpSzUse8254`, `_HalpTranslatePCIBusAddress@24`, `_HalpUnLock8259@0`, `_HalpVgaPutCharacter@12`, `_HalpWriteFlash@12`, `_HalpXtractOptionString@12`, `_HalpXtractOptionValue@12`, `_Ns307InitChip@4`, `_RtcDataReadBuffer@12`, `_RtcDataWriteBuffer@12`, `__allrem`, `__aulldiv`, `atoi`, `i2cErrorRecovery`, `i2cHWGetSCL`, `i2cHWGetSDA`, `i2cHWSetSCL`, `i2cHWSetSDA`, `i2cReadBit`, `i2cReadBlock`, `i2cReadByte`, `i2cSendBit`, `i2cSendBlock`, `i2cSendByte`, `i2cSendStart`, `i2cSendStop`, `i2cSyncClock`, `i2cTransfer`, `index`, `mli2cFlatPanelID`, `mli2cFlatPanelStatus`, `pm_init_intr`, `pm_intr_handler`, `sgixCallbackRegister`, `sgixExecuteCallback`, `strctok`.

## Notes

- The multiprocessor-only routines are listed on the [nt4-up](nt4-up.md) page (VW-HAL-DIFF-01).
- The hardware reading of these routines is in [nt-hal.md](../nt-hal.md); this page adds counts and what the code assumes of the kernel.
