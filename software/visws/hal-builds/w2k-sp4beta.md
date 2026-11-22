# Windows 2000 SP4 beta halborg.dll (w2k-sp4beta)

Part of the [build-by-build HAL reading](../hal-builds.md); requirement ids are defined there. Everything here is from the
disassembly of the image (capstone over the function bounds Ghidra found); the export was produced by `tools/visws-hal/build.sh`.

| Item | Value |
|---|---|
| SHA-256 | `66fb808639bd8937a88aa79ad31a61af46cf24d1fffb92841f419bfdd6a66786` |
| Size | 148960 bytes |
| Version resource | `5.00.2195.6615` |
| PE time stamp | 1036693414 |
| Image base | `0x80010000` |
| Sections (RVA, size) | `.text` `0x340` (+`0xff55`), `_INIT16` `0x102a0` (+`0x45`), `.data` `0x10300` (+`0x8ebc`), `PAGELK` `0x191c0` (+`0xeaa`), `PAGE` `0x1a080` (+`0x3ced`), `.edata` `0x1dd80` (+`0xc0d`), `INIT` `0x1e9a0` (+`0x4226`), `.rsrc` `0x22be0` (+`0x3c0`), `.reloc` `0x22fa0` (+`0x162e`) |
| Imports | ntoskrnl.exe: 112 |
| Exports | 98 (97 code, 1 data) |
| Functions | 431 (decompiled 431) |
| Name sources | DEFAULT 334, IMPORTED 97 |

Source: Library cache, the visws driver set (SP4 beta, build 2195.6615). No symbol file is held for any Windows 2000 build; the 97 code exports are the only names.

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

## Against RTM (VW-HAL-DIFF-04)

Shape comparison with [w2k-rtm](w2k-rtm.md): 417 of 431 functions identical, 9 near and 5 with no match (below). `.data` differs in 381 bytes; later sections
shift because `.text` is 32 bytes longer. Addresses are in the beta image; the RTM address is the counterpart found by position.

| Beta address | RTM address | Instructions | Change |
|---|---|---|---|
| `0x80015e9c` | `0x80015e7c` | 50 | one subtract moved relative to another operation |
| `0x80015fae` | `0x80015f8e` | 223 | two fields (`+0x10`, `+0x18`) read in the opposite order for a sum |
| `0x80016234` | `0x80016214` | 76 | same reordering |
| `0x800162fa` | `0x800162da` | 111 | same reordering |
| `0x800170e0` | `0x800170c0` | 302 | signed compares become unsigned; the table index loses a bias of 4 and the 3x scaling becomes 4x |
| `0x8001746c` | `0x8001744c` | 134 | table index change as above |
| `0x80017fa2` | `0x80017f84` | 79 / 91 | 64-bit range compare reallocated to other registers; no semantic change seen |
| `0x8001ca21` | `0x8001ca1b` | 608 | the range-merge routine takes one extra 32-bit addend argument and adds it into a 64-bit running total |
| `0x8001f0a2` | `0x8001f09a` | 37 / 34 | the result becomes a comparison of an argument with a global instead of a copy of the argument |
| `0x8001f10c` | `0x8001f0fa` | 28 / 25 | same change |
| `0x8002adf8` | `0x8002ad98` | 338 | two fields (`+0x24`, `+0x28`) read in the opposite order |
| `0x8002bc88` | `0x8002bc28` | 415 / 406 | an extra local flag byte and the table index change as above |
| `0x8002d468` | `0x8002d3e8` | 36 / 22 | the `HalSetSystemInformation` target (HalDispatchTable `+8`): the beta records the calling process id in a global when the setting is enabled, accepts a later call only from the same process, clears the owner when the value is set to zero, and otherwise returns `0xc0000001` |
| `0x800312d2` | `0x80031212` | 63 / 60 | a start-up routine reorders its global stores and also copies one byte (offset `+0x44` of a structure) into a global |

Four RTM functions, at `0x80015dfa`, `0x800190a2`, `0x8001fee2` and `0x8001ff4c` (14, 28, 7 and 11 instructions), have no counterpart by shape, and the beta has
one more function in total. Their roles are not read.
