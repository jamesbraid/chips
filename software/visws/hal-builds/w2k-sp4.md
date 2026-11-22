# Windows 2000 SP4 halborg.dll (w2k-sp4)

Part of the [build-by-build HAL reading](../hal-builds.md); requirement ids are defined there. Everything here is from the
disassembly of the image (capstone over the function bounds Ghidra found); the export was produced by `tools/visws-hal/build.sh`.

| Item | Value |
|---|---|
| SHA-256 | `213b3d97696203788328a0e0374e7978d4bcac6ed02ed309c113177e7318b524` |
| Size | 148960 bytes |
| Version resource | `5.00.2195.6655` |
| PE time stamp | 1042659713 |
| Image base | `0x80010000` |
| Sections (RVA, size) | `.text` `0x340` (+`0xff55`), `_INIT16` `0x102a0` (+`0x45`), `.data` `0x10300` (+`0x8ebc`), `PAGELK` `0x191c0` (+`0xeaa`), `PAGE` `0x1a080` (+`0x3ced`), `.edata` `0x1dd80` (+`0xc0d`), `INIT` `0x1e9a0` (+`0x4226`), `.rsrc` `0x22be0` (+`0x3c0`), `.reloc` `0x22fa0` (+`0x162e`) |
| Imports | ntoskrnl.exe: 112 |
| Exports | 98 (97 code, 1 data) |
| Functions | 431 (decompiled 431) |
| Name sources | DEFAULT 334, IMPORTED 97 |

Source: Windows 2000 SP4 5-in-1 disc, `ROOT/WRKS/I386/HALBORG.DLL` (the same SHA-256 is in the other editions' trees), and the Library cache. No symbol file is held for any Windows 2000 build; the 97 code exports are the only names.

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
| `HalInitSystem` (`0x8002f1f1`) | HalDispatchTable | `+0x4` | code at `0x8002b404` |
| `HalInitSystem` (`0x8002f1f1`) | HalDispatchTable | `+0x8` | code at `0x8002d468` |
| `HalInitSystem` (`0x8002f1f1`) | HalDispatchTable | `+0x34` | code at `0x8002a0e0` |
| `HalInitSystem` (`0x8002f1f1`) | HalDispatchTable | `+0x3c` | code at `0x8001667c` |
| `HalInitSystem` (`0x8002f1f1`) | HalDispatchTable | `+0x40` | code at `0x80019fbf` |
| `FUN_80031452` (`0x80031452`) | HalPrivateDispatchTable | `+0x10` | code at `0x80029d06` |
| `FUN_80031452` (`0x80031452`) | HalPrivateDispatchTable | `+0x4` | code at `0x8001fec2` |
| `FUN_80031452` (`0x80031452`) | HalPrivateDispatchTable | `+0x8` | code at `0x8001fed6` |
| `FUN_80031452` (`0x80031452`) | HalDispatchTable | `+0x28` | code at `0x8001feea` |
| `FUN_80031452` (`0x80031452`) | HalDispatchTable | `+0x2c` | code at `0x8001fe62` |
| `FUN_80031452` (`0x80031452`) | HalDispatchTable | `+0x30` | code at `0x8001fe92` |
| `FUN_80031452` (`0x80031452`) | HalPrivateDispatchTable | `+0x1c` | code at `0x8001ffee` |
| `FUN_80031452` (`0x80031452`) | HalPrivateDispatchTable | `+0x20` | code at `0x8002d77c` |
| `FUN_80031452` (`0x80031452`) | HalPrivateDispatchTable | `+0x28` | code at `0x8002006e` |

## Functions using board addresses or ports (VW-HAL-SGI-03)

`FUN_8001f158` (pm-latch, pm-nmi-port); `FUN_8001f33c` (piix4-pm, piix4-pm-ctl); `FUN_8001f529` (piix4-pm, piix4-pm-ctl); `FUN_8001f60c` (piix4-pm, piix4-pm-ctl, pm-port); `HalInitializeProcessor` (cobalt-apic, cobalt-cpu, cobalt-mem).

## Against the stock Microsoft HALs on the same media

Shape and trigram match (method in [the index](../hal-builds.md#sgi-specific-versus-generic)): exact 197, near 20, by string use 0, no match 214; 57 of the functions have fewer than four instructions.

## Against SP4 beta (VW-HAL-DIFF-05)

All 431 functions have the same shape as in [w2k-sp4beta](w2k-sp4beta.md). Differences: 16 bytes of `.text` (time stamps in the debug directory records) and 4 bytes of
the version resource. Data and tables are identical. SP4 is a code-identical respin of the beta with a later time stamp (2002-11-07 to 2003-01-15).
