# Windows 2000 RC3 halborg.dll (w2k-rc3)

Part of the [build-by-build HAL reading](../hal-builds.md); requirement ids are defined there. Everything here is from the
disassembly of the image (capstone over the function bounds Ghidra found); the export was produced by `tools/visws-hal/build.sh`.

| Item | Value |
|---|---|
| SHA-256 | `f897718d690dc645d6b3c32a501d610acba751648a4bafd1dcb14a3f5cdbf9b4` |
| Size | 148672 bytes |
| Version resource | `5.00.2164.1` |
| PE time stamp | 940971736 |
| Image base | `0x80010000` |
| Sections (RVA, size) | `.text` `0x340` (+`0xff31`), `_INIT16` `0x10280` (+`0x45`), `.data` `0x102e0` (+`0x8e7c`), `PAGELK` `0x19160` (+`0xeaa`), `PAGE` `0x1a020` (+`0x3c9b`), `.edata` `0x1dcc0` (+`0xc0d`), `INIT` `0x1e8e0` (+`0x41fa`), `.rsrc` `0x22ae0` (+`0x3b0`), `.reloc` `0x22ea0` (+`0x161c`) |
| Imports | ntoskrnl.exe: 111 |
| Exports | 98 (97 code, 1 data) |
| Functions | 430 (decompiled 430) |
| Name sources | DEFAULT 333, IMPORTED 97 |

Source: Library cache, the visws driver set (RC3, build 2164.1). Not on any held disc. No symbol file is held for any Windows 2000 build; the 97 code exports are the only names.

## Exports

Identical to [w2k-rtm](w2k-rtm.md#exports): the same 98 names and ordinals.

## Kernel structure use (VW-HAL-PCR, VW-HAL-PRCB)

KPCR offsets read through `fs:` (or the fixed uniprocessor address `0xffdff000`). Columns: functions touching the offset, reads, writes.

| KPCR offset | Functions | Reads | Writes |
|---|---|---|---|
| `0x1c` | 14 | 32 | 0 |
| `0x20` | 10 | 10 | 0 |
| `0x40` | 1 | 1 | 0 |
| `0x48` | 1 | 1 | 0 |
| `0x4c` | 2 | 1 | 1 |
| `0x95` | 3 | 1 | 2 |
| `0x96` | 2 | 1 | 2 |
| `0x98` | 2 | 2 | 1 |
| `0xa0` | 3 | 1 | 2 |
| `0xa4` | 2 | 2 | 2 |
| `0xa8` | 1 | 0 | 1 |
| `0xac` | 1 | 0 | 1 |

Fields reached through a register loaded from `fs:[0x1c]` (PCR) or `fs:[0x20]` (PRCB).

| Base and offset | Functions | Reads | Writes |
|---|---|---|---|
| `PCR+0x20` | 5 | 5 | 0 |
| `PCR+0x30` | 1 | 1 | 1 |
| `PCR+0x38` | 5 | 18 | 0 |
| `PCR+0x4c` | 1 | 0 | 1 |
| `PCR+0x51` | 2 | 2 | 0 |
| `PCR+0x98` | 1 | 1 | 0 |
| `PRCB+0x10` | 2 | 2 | 0 |
| `PRCB+0x19` | 1 | 1 | 0 |
| `PRCB+0x3bc` | 3 | 3 | 0 |

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

## Functions using board addresses or ports (VW-HAL-SGI-03)

`FUN_8001f13c` (pm-latch, pm-nmi-port); `FUN_8001f320` (piix4-pm, piix4-pm-ctl); `FUN_8001f50d` (piix4-pm, piix4-pm-ctl); `FUN_8001f5f0` (piix4-pm, piix4-pm-ctl, pm-port); `HalInitializeProcessor` (cobalt-apic, cobalt-cpu, cobalt-mem).

## Against the stock Microsoft HALs on the same media

Shape and trigram match (method in [the index](../hal-builds.md#sgi-specific-versus-generic)): exact 195, near 20, by string use 0, no match 215; 56 of the functions have fewer than four instructions.

## Against RTM (VW-HAL-DIFF-03)

All 430 functions have the same shape as in [w2k-rtm](w2k-rtm.md). The files differ in 12 bytes of `.text` (copies of the image time stamp inside the debug
directory records: RC3 `0x383616d8`, RTM `0x383b75b0`), 3 bytes of the export directory (its time stamp) and 4 bytes of the version resource. Data and every
table are identical: RC3 is a code-identical predecessor of RTM.
