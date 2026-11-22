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

KPCR offsets seen through `fs:` and, on the uniprocessor image, through the fixed address `0xffdff000`. Each cell is functions / reads / writes. "Uncovered code" is code no function Ghidra found covers (38836 bytes of executable sections), disassembled linearly, so a cell there can include a mis-decoded data run; offsets of `0x400` and above are dropped as such. The last column is the operand size in bytes.

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

Conditions, read in the disassembly: HalDispatchTable `+0x34`, `+0x3c` and `+0x40` are stored only when the table's version dword is 2 or more; HalPrivateDispatchTable `+0x28` is stored only when that slot is still zero. The other stores are unconditional. The `+0x3c` and `+0x40` targets and the private `+8` target are addresses in code Ghidra did not make functions.

## Functions using board addresses or ports (VW-HAL-SGI-03)

`FUN_8001f158` (pm-latch, pm-nmi-port); `FUN_8001f33c` (piix4-pm, piix4-pm-ctl); `FUN_8001f529` (piix4-pm, piix4-pm-ctl); `FUN_8001f60c` (piix4-pm, piix4-pm-ctl, pm-port); `HalInitializeProcessor` (cobalt-apic, cobalt-cpu, cobalt-mem).

## Against the stock Microsoft HALs on the same media

Shape and trigram match (method in [the index](../hal-builds.md#sgi-specific-versus-generic)): exact 197, near 20, by string use 0, no match 214; 57 of the functions have fewer than four instructions.

## Against RTM (VW-HAL-DIFF-04)

Shape comparison with [w2k-rtm](w2k-rtm.md): 417 of 431 functions identical, 9 near and 5 with no match (below). `.text` is 32 bytes longer; the
`.data` and every table are analysed in the next section. Addresses are in the beta image; the RTM address is the counterpart found by position. The
re-read against the disassembly of both images (items marked by the function's role) corrects the first version of this table.

| Beta address | RTM address | Instructions | Role and change |
|---|---|---|---|
| `0x80015e9c` | `0x80015e7c` | 50 | one subtract moved relative to another operation |
| `0x80015fae`, `0x80016234`, `0x800162fa` | `0x80015f8e`, `0x80016214`, `0x800162da` | 223, 76, 111 | range-list routines: two fields (`+0x10`, `+0x18`) are read in the opposite order for a sum (same result) |
| `0x800170e0` | `0x800170c0` | 302 | the DMA map-transfer routine behind `IoMapTransfer`: it programs the 8237 through ports in the `0x0a` to `0x14` range and the page registers, then records the channel (see "The record whose stride changed"). The beta also compares the page-boundary step with unsigned compares (`jb`, `ja` where RTM has `jl`, `jg`) |
| `0x8001746c` | `0x8001744c` | 134 | `IoFlushAdapterBuffers`: same channel-record store with the new stride |
| `0x8002bc88` | `0x8002bc28` | 415 / 406 | `HalGetAdapter`: same channel-record store with the new stride, one extra local flag byte, and the new fourth byte of the record |
| `0x80017fa2` | `0x80017f84` | 79 / 91 | 64-bit range compare reallocated to other registers; no semantic change seen |
| `0x8001ca21` | `0x8001ca1b` | 608 | the range-merge routine. Both builds return with `ret 0x10`, so the argument count is unchanged. The beta spills one value to `[ebp+0x14]` and adds it into the 64-bit running sum; that is register allocation, not a new parameter |
| `0x8001f0a2`, `0x8001f10c` | `0x8001f09a`, `0x8001f0fa` | 37 / 34, 28 / 25 | the bus-data wrappers (inferred from the six arguments, `ret 0x18`, and the handler-sized copy): each copies a `0x6c`-byte record (the size of a bus handler) from a table into a local and calls the common routine. RTM indexes the table with the byte argument at `ebp+0xc`; the beta uses `(argument >= the dword at 0x800268b8) ? 1 : 0` as the index, and the table base moved from `0x80026800` to `0x80026840` |
| `0x8002adf8` | `0x8002ad98` | 338 | two fields (`+0x24`, `+0x28`) read in the opposite order |
| `0x8002d468` | `0x8002d3e8` | 36 / 22 | `HalSetSystemInformation` (HalDispatchTable `+8`), information class 1. RTM: a write-once latch. When a global enable bit is set and the latch dword is zero, the caller's dword is stored in the latch and the call succeeds; any other case returns `0xc0000001`. Beta: the latch is a value plus an owner. A call from no owner records the caller's process id (`PsGetCurrentProcessId`, the one new import) when the value is non-zero; a later call is accepted only from that process; writing zero clears the owner; any other case returns `0xc0000001` |
| `0x800312d2` | `0x80031212` | 63 / 60 | a start-up routine reorders its global stores and also copies one byte (offset `+0x44` of a structure) into a global |

Four RTM functions, at `0x80015dfa`, `0x800190a2`, `0x8001fee2` and `0x8001ff4c` (14, 28, 7 and 11 instructions), have no counterpart by shape, and the beta has
one more function in total. Their roles are not read.

### The record whose stride changed

The table that moves from 3-byte to 4-byte records in `0x800170e0` is **not an interrupt route table**. It is the per-DMA-channel state that `HalGetAdapter` writes and
`IoMapTransfer` and `IoFlushAdapterBuffers` update, one record per 8237 channel and controller. Index in RTM is `channel + 4 * controller - 4` (the controller byte at adapter
object `+0x51` is 1 or 2, the channel byte at `+0x50`) with records of 3 bytes at `0x80028e80`; in the beta it is `channel + 4 * controller` with records of 4 bytes, and the
`-4` bias is gone. References to the table, from a raw search of every executable section for the table addresses: RTM stores at `0x80028e80`, `0x80028e81`, `0x80028e82`
(`HalGetAdapter`, `0x8002c0a1`, `0x8002c0b7`, `0x8002c0cc`) and `0x80028e82` again (`IoMapTransfer`, `IoFlushAdapterBuffers`); the beta stores at `0x80028eb0`, `0x80028eb1`,
`0x80028eb2` and **`0x80028eb3`**, all in `HalGetAdapter` (`0x8002c10c`, `0x8002c121`, `0x8002c13c`, `0x8002c14e`), and `0x80028eb2` again in the same two other routines.

| Record byte | Written by `HalGetAdapter` | Written later |
|---|---|---|
| `+0` | the 8237 mode-register value assembled from the adapter's flags (also kept at adapter object `+0x54`) | |
| `+1` | the byte passed as the third argument | |
| `+2` | the channel number, with bit 2 set when the second argument is zero (the shape of an 8237 single-mask write) | the map-transfer and flush routines store the channel number there |
| `+3` (beta only) | the constant 1 | never |

The extra fourth byte is written once, with the constant 1, and no instruction in any executable section of the beta reads it (the raw search finds no other reference to
`0x80028eb3`), so its purpose is unknown; it behaves like a "channel initialised" flag. A dword array indexed by the same channel number (`HalGetAdapter` reads and writes it)
sits just before the byte records in the beta. Field names are inferred from 8237 register semantics; the stores are established.

### Interrupt route tables, RTM against SP4 and the others (answer to "do any values differ")

Every table was decoded from the images by byte compare after allowing for the 32-byte shift of `.text`: the eight ISA route tables (48 bytes: `0x10888`, `0x108b8`, `0x108e8`,
`0x10918`, `0x10948`, `0x10978`, `0x109a8`, `0x109d8` in RTM; each `+0x20` in SP4 and the beta), the four vector tables (30 entries of 8 bytes, a zero dword then the vector:
`0x10a08`, `0x10b08`, `0x10c08`, `0x10d08`) and the eight PCI pin blocks (five 8-byte entries each, four pin bytes then a pointer: `0x10e08` and every `0x28` after).

- **ISA route tables: 8 of 8 identical** in RTM, RC3, SP4 beta and SP4.
- **Vector tables: 4 of 4 identical** (every vector, in every one of the four interrupt generations, for every entry; and all the zero dwords are zero).
- **PCI pin blocks: 8 of 8 have identical pin bytes** (so every generation, slot and pin gives the same Cobalt entry). The only bytes that differ are the low bytes of the pointer
  in each 8-byte entry (5 or 6 bytes per block), which point back into the table region and move by `0x10` with the layout; the beta and SP4 are byte-identical in these blocks.
- The selection code (which of the four generations a board gets, from SYS TYPE and board revision) is in functions that match by shape in all four builds, so selection is unchanged too.

The 381 `.data` bytes that differ between RTM and the beta account as follows (aligned dword by dword, pointers normalised): 335 dwords are pointers into the image that move by 8 to 96 bytes
with the code (299 of them by `0x10`, 23 by `0x20`); the date and time strings of the build change (`Oct 26 1999 14:01:01` in RC3 and RTM, `Nov  7 2002 10:22:33` in SP4 beta and SP4) with a
build-type string; and 64 zero bytes are inserted near the end of `.data` (the section grows from 36,480 to 36,544 bytes). Nothing else differs, so no table value changed.

### Which build to use as the first reference (inferred)

**SP4 (`213b3d97`, 5.00.2195.6655).** For emulator wiring the four builds are interchangeable: the interrupt, ISA and PCI tables, the generation selection, the Cobalt block addresses, the PCR and PRCB
use and the dispatch-table stores are identical (SP4 beta and SP4 are code-identical; RC3 and RTM are code-identical). The choice is then about what else the HAL does. SP4 is the final Microsoft build,
it is on a widely held disc, and it includes the small corrections between RTM and the beta: the owner check on `HalSetSystemInformation` class 1, the unsigned compares and the extended channel record in the DMA path.
The costs of choosing RTM are a write-once latch that cannot be changed by the right owner, and an earlier DMA record. The cost of choosing SP4 is that SGI's own build is the 1999 one, while the SP4 image carries 2002 to 2003 build strings, so Microsoft rebuilt it; whether the rebuilt HAL was ever run on the machine is not shown, and this reading finds no table or hardware-register difference, so that cost is untested rather than observed. RC3 is not a candidate: it is the RTM code with different time stamps.

### NT 4.0 against Windows 2000 (VW-HAL-DIFF-02), checking the earlier statement that the values matched

Confirmed, with one layout change and no stride change for the other tables. Against the NT 4.0 multiprocessor image: the six ISA route tables at `0x80020d28`, `0x80020d58`, `0x80020d88`,
`0x80020db8`, `0x80020e18`, `0x80020de8` are **byte-identical** to RTM's `0x10888` to `0x10978` in the same order; the three vector tables at `0x80020e48`, `0x80020ec8`, `0x80020f48` have the **same 30 vectors**
as RTM's `0x10a08`, `0x10b08`, `0x10c08`, but NT 4.0 stores them as 30 dwords (4-byte entries) and Windows 2000 as 30 pairs (a zero dword, then the vector), which is the one stride change between the two systems;
the six PCI pin blocks at `0x80020fc8` and every `0x28` after have the **same pin bytes** as RTM's first six, with different pointer fields. The fourth vector set and the fourth pin set, and the two extra ISA
tables, exist only in Windows 2000 (RTM `0x10d08`, `0x10ef8`, `0x10f20`, `0x109a8`, `0x109d8`). The 3-byte to 4-byte change in `0x800170e0` is the DMA channel record above and has nothing to do with this layout change.
