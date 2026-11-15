# SN2 KLCONFIG: the hardware graph the PROM builds and Linux reads

KLCONFIG is the per-node inventory the SN2 PROM writes into node memory before it starts EFI. Linux gets its address from one
SAL call and walks the board list to find nodes that need a compact node number. This page gives the structure layouts the
kernel was built with, what the SAL 5.04 SHub 1 PROM (`shub1snprom.bin`, snprom 10.54, sha256 `51ccf9ad830b...3a34617`)
writes for a single-node Altix 350, where each value comes from, which fields Linux reads, and what an emulator has to supply.

**Grades** follow [AGENTS.md](../../AGENTS.md). **established**: a header, or a PROM routine read in full. **inferred**:
a reasoned reading, with the reasoning. **unknown**: not settled, with the route. Linux is cited as `v5.3:path` and
`v2.6.12:path` (fetched single files from the `torvalds/linux` tags; SGI's platform code counts as vendor source under the
evidence order). PROM addresses are image addresses; the SAL_B global pointer is `0xffd98000`. Decompiler output
(the IA-64 Ghidra module, `retools/tools/re-run --ghidra-export IMAGE --sn2-prom`) was used for navigation and the store offsets
below were then read in the disassembly of each routine named; where a routine was only skimmed the grade says so.

## 1. Layout

### Where it lives and how Linux finds it

- **Finding it (established).** Linux has no fixed address. `build_cnode_tables` (`v5.3:arch/ia64/sn/kernel/setup.c` 745) calls
  `SN_SAL_GET_KLCONFIG_ADDR` (`0x02000005`) once per compute node; the physical address returned is the base of a
  `kl_config_hdr_t`. A zero result is `BUG_ON` in v5.3 (`BUG()` in v2.6.12 unless it runs on the simulator). Neither tree defines
  a `KL_CONFIG_INFO` pointer or a kldir; the SAL call is the only route. The held 2.6.5 kernel agrees: its `sn_setup`
  loads the constant `0x2000005` into the SAL function argument at two sites and has no helper symbols for the walk (they are
  static).
- **Where the PROM puts it (established for the construction, unknown for the absolute address).** `hwcfg init`
  (`0xffaa0100`, which names its source file `hwcfg/common/init.c`) allocates `0xb0000` bytes from the node's PROM heap
  (heap handle at node object offset `0x1f8`), stores the pointer at node object `+0x20` (node object: the pointer at
  `0x1000038`), and calls `0xffaa3cf0` to lay the area out. **KLCONFIG starts `0x10000` bytes into that block** (every access
  adds `0x10000`; the allocator checks the 8-byte value at that address is `0xbeedbabe` and prints "kl_config_info_alloc: bad
  magic" otherwise, `0xffaa4560`). So the offset inside the block is fixed and the block's own address depends on heap state:
  **unknown**. Route: trace the heap allocator (`0xffac30c0`) on a booted node, or a captured `GET_KLCONFIG_ADDR` result.
  That the SAL call returns exactly `block + 0x10000` is **inferred**: the existing reading of the handler
  (`salruntime_klconfig_addr`, [snprom README](../../software/firmware/snprom/README.md)) adds `0x10000` and Linux treats the
  value as the header; the handler was not re-read here.
- **Offsets inside the structures (established).** Every link (`brd_next_any`, `brd_compts[]`, `ch_board_info`, `errinfo`) is a
  32-bit value holding the **node-local physical address** of the target (the low 32 bits with the NASID bits and bit 63
  cleared). `NODE_OFFSET_TO_LBOARD(nasid, off)` (`v5.3:klconfig.h`) is `CAC_BASE | (nasid << 38) | off`, and
  `find_lboard_next` takes the NASID from the address of the board it is following, so a link never leaves its node.
  A board is on the list of the node that holds its memory.
- **Region plan (established, `0xffaa2760`, `0xffaa3cf0`).** All figures are offsets from the KLCONFIG base.

| Offset | Content |
|---|---|
| `0x00` | magic, 8 bytes, `0xbeedbabe` (the PROM's own check; Linux does not read it: it sits in `pad[20]`) |
| `0x0c` | 32-bit offset of the allocator table, set to `0x48` |
| `0x10` | 32-bit value set to `0x18` (role: allocator state for the text pool; **unknown**) |
| `0x14` | `ch_board_info`: offset of the first board, 0 until a board is added |
| `0x48` | three allocator descriptors of 12 bytes each: start, limit, next free |
| `0x70` | region 0, lboards: `0x4880` bytes; region 1, components: `0x3de00`; region 2, error and per-component extras: `0x10b80` |
| about `0x9f400` | a pool of text (NIC strings) whose limit is `0xa0000`; **inferred** from `0xffaa4f50` and `0xffaa2760` |

  The header is 112 bytes (`0x70`) and regions follow it. Each allocation takes its size rounded up to 8 plus 16 bytes, so
  successive lboards are `0xf8` apart. Region 0 holds about 74 boards, region 1 about 900 components. An allocator that runs out
  returns -1 and the builder prints a message ("init_klcfg: type %d exceeds klconfig size", "err alloc failed"); it does not stop.

### The structures (established, `v5.3` and `v2.6.12`)

The two `klconfig.h` files give identical structure definitions (a diff differs only in v2.6.12's extra helper macros
`KLCF_NUM_COMPS`, `KLCF_NEXT`, `KLCF_NEXT_ANY`, `KLCF_COMP`, `find_lboard_any`, `find_component`, `find_first_component` and
`root_lboard`). The header defines no component record beyond `klinfo_t`: there is no hub, CPU, memory, bridge or crossbar
structure in Linux. Types: `klconf_off_t` is `s32`, `nasid_t` is `s16`, `partid_t` is `s8`, `moduleid_t` is `u32`, `nic_t` is `u64`
(`asm/sn/types.h`, both tags). Offsets below were computed by compiling the two headers for LP64 (the ia64 ABI) and are
cross-checked against the PROM's stores in section 2.

`kl_config_hdr_t`, 112 bytes: `pad[20]`, `ch_board_info` at 20, `pad0[88]`.

`lboard_t`, 232 bytes, 8-byte aligned:

| Offset | Field | Size |
|---|---|---|
| 0 | `brd_next_any` | 4 |
| 4 | `struct_type` (local or remote board; the PROM writes 1) | 1 |
| 5 | `brd_type` (class in the high nibble, type in the low) | 1 |
| 6 | `brd_sversion` | 1 |
| 7 | `brd_brevision` | 1 |
| 8 | `brd_promver` | 1 |
| 9 | `brd_flags` | 1 |
| 10 | `brd_slot` | 1 |
| 12 | `brd_debugsw` | 2 |
| 16 | `brd_geoid` (a `geoid_t`; 12 bytes with these types, although the union's pad array is 8) | 12 |
| 28 | `brd_partition` | 1 |
| 30 | `brd_diagval` | 2 |
| 32 | `brd_diagparm` | 2 |
| 34 | `brd_inventory` | 1 |
| 35 | `brd_numcompts` | 1 |
| 40 | `brd_nic` | 8 |
| 48 | `brd_nasid` | 2 |
| 52 | `brd_compts[24]` | 96 |
| 148 | `brd_errinfo` | 4 |
| 152 | `brd_parent` (a kernel pointer slot) | 8 |
| 160 | `pad0[4]` | 4 |
| 164 | `brd_confidence` | 1 |
| 166 | `brd_owner` | 2 |
| 168 | `brd_nic_flags` | 1 |
| 169 | `pad1[24]` | 24 |
| 193 | `brd_name[32]` | 32 |
| 226 | `brd_next_same_host` | 2 |
| 228 | `brd_next_same` | 4 |

`klinfo_t` (the generic head every component starts with), 56 bytes:

| Offset | Field | Size |
|---|---|---|
| 0 | `struct_type` | 1 |
| 1 | `struct_version` | 1 |
| 2 | `flags` | 1 |
| 3 | `revision` | 1 |
| 4 | `diagval` | 2 |
| 6 | `diagparm` | 2 |
| 8 | `inventory` | 1 |
| 10 | `partid` | 2 |
| 16 | `nic` | 8 |
| 24 | `physid` | 1 |
| 28 | `virtid` | 4 |
| 32 | `widid` | 1 |
| 34 | `nasid` | 2 |
| 40 | `data` (kernel pointer slot) | 8 |
| 48 | `errinfo` | 4 |
| 52 | `pad3`, `pad4` | 4 |

`geoid_t` and the module id are on [brick identity](brick-identity.md). Board types and classes the header defines:
`KLTYPE_SNIA` `0x11` and `KLTYPE_TIO` `0x12` (class `0x10`, node), routers `0x31`, `0x33`, `0x34`, `KLTYPE_IOBRICK_XBOW`
`0x42` (class midplane), and the I/O brick class `0x70`: `IOBRICK 0x70`, `NBRICK 0x74`, `PXBRICK 0x76`, `IXBRICK 0x77`,
`CGBRICK 0x78`, `OPUSBRICK 0x79`, `SABRICK 0x7a`, `IABRICK 0x7b`, `PABRICK 0x7c`, `GABRICK 0x7d`. The header has no component
type numbers (`struct_type` values); section 2 lists the ones the PROM stores.

**The PROM agrees with the header (established).** Every board store in `0xffaed240` (the lboard allocator and default
filler), `0xffaa1ea0`, `0xffaed410` and `0xffabf570` and every component store in `0xffaed090` and the component builders hits
the offsets in the tables: `brd_type` +5, `brd_slot` +10, `brd_geoid` +16, `brd_nic` +40, `brd_nasid` +48 (`0x30`),
`brd_compts` +52 (`0x34`), `brd_numcompts` +35, `brd_parent` +152 (`0x98`), `brd_name` +193 (`0xc1`),
`brd_next_same_host` +226 (`0xe2`), `brd_next_same` +228 (`0xe4`), and in components `partid` +10, `nic` +16, `physid` +24,
`virtid` +28, `widid` +32, `nasid` +34, `errinfo` +48. The 12-byte geoid is copied as an 8-byte plus a 4-byte store
(`0xffaa1ea0`), which confirms 12 bytes, not 8. The held ProPack 2.6.5 kernel has no DWARF, so its layouts cannot be read
directly; its `sn_setup` scan loads the header word at +20, the board type at +5 and the NASID at +48, and tests the type
as `(type - 17) < 2` (types `0x11` and `0x12`), the same offsets and test as v5.3.

## 2. The builder (SAL 5.04, SHub 1 image)

### How the list is built

- **Allocator (established).** `0xffaed240` allocates a board from region 0 of the node (`0xffaa4c60` picks the node: the
  requested one if it has a usable klconfig, else the first node that does) and fills defaults: `struct_type` 1,
  `brd_sversion` 2, `brd_promver` 1, `brd_flags` 1, `brd_type` `0xff`, geoid invalid (type 0), `brd_nic` all ones,
  `brd_nasid` the argument, `brd_next_same_host` `0xffff`, everything else zero. `0xffaed090` allocates a `0x108`-byte component
  from region 1 and appends its offset to `brd_compts[]`, bumping `brd_numcompts`; defaults `struct_type` `0xff`, version 1,
  flags 1, revision `0xff`, `nic` all ones, `physid` `0xff`, `virtid` all ones. The 24-component limit is not tested in the
  routine.
- **Linking (established, `0xffaa5450`).** The first board of a node is stored at `ch_board_info`; later boards are appended to
  the end of the `brd_next_any` chain. The board is also appended to a second chain through `brd_next_same_host` (the NASID,
  halfword at +226) and `brd_next_same` (offset at +228), which links all boards that share a `brd_nasid`.
- **Order for a one-node machine (established as call order, `main_two` and `main_three`).** (1) `0xffaa0100` builds the empty
  area. (2) `hwcfg_node_init` (`0xffaa1ea0`, via the thunk `0xffa9fe80`, called from `main_two` at `0xffa1b3dc` with board
  type `0x11`) adds the node board. (3) In `main_three`, widget 0 is read at progress `0x24` and, when it identifies as a
  crossbar, `0xffab0f10` adds the I/O brick board and the I/O boards. Routers, TIOs and headless nodes
  (`0xffaa20f0`, `0xffaaf110`, `0xffaacaf0`) exist in the image and are not reached on one node (inferred from reachability; a
  one-node machine has no router and no TIO).

### The node board (type `0x11`, `KLTYPE_SNIA`) on a one-node Altix 350

Built by `hwcfg_node_init` (`0xffaa1ea0`, read in full).

| Field | Value | Source |
|---|---|---|
| `brd_type` | `0x11` | constant argument (established) |
| `brd_nasid` | the node's NASID | the first halfword of the node's chip object (the argument), which the PROM's chip set-up fills; **inferred** to come from bits 42:32 of `0x81_1006_0580` ([boot-sequence](../../software/firmware/snprom/boot-sequence.md)) |
| `brd_geoid` | 12 bytes copied from the chip object at +8 (8 bytes) and +16 (4 bytes) | the chip object is filled by code not read here: **inferred** to carry the module word from L1 request `0x0003`, the slab from `0x000e` and the slot from `0x0013` ([L1 requests](../../software/firmware/snprom/l1-requests.md)). A geoid builder `0xffa11f10` packs type, module, slab and slot |
| `brd_sversion` | raised to 3 if lower | established |
| `brd_brevision` | the SHub revision byte | a method of the chip object (entry `+0x138` of the method table at object `+0x20`); **inferred** to return the revision nibble of the SHub ID register (`0x1_0000_0000` bits 31:28; the PROM wants part number `0x4363`) |
| `brd_name` | `"IP41"` (the string is constant; the image has no `IP57`; a TIO board gets `"TIO"`) | established, and the same fact [boot-sequence](../../software/firmware/snprom/boot-sequence.md#node-board-identification-ip41-ip57-others) records |
| `brd_slot`, `brd_flags`, `brd_promver` | slot untouched here, flags 1, promver 1 | defaults (established) |
| components | hub, up to four memory banks, hub UART, one per CPU (below) | |

Components, in the order they are added:

| `struct_type` | Record | Fields filled | Source |
|---|---|---|---|
| 2 | hub (`init_klcfg_hub`, `0xffaa1310`, read in full) | `flags` 1; `revision` from the chip object byte +4; `partid` from the chip object halfword +2; `physid` and `nasid` the NASID; `virtid` all ones; two 12-byte port slots at +72 set to `0xffff`; +104 the offset of a copy of the node's EEPROM text (`nic` string); +112 a value from the chip object method at table entry `+0x130`; +120 a value from `0xffa80430`; +124 `0xff`; `errinfo` a 16-byte block with a 240-byte second block hung off its +12 | SHub ID register for part and revision (inferred); the EEPROM text from the L1 board-area read (below) |
| `0x32` | memory bank, one per present bank of the four (`init_klcfg_membnk`, `0xffaa1a10`, read in full) | `flags` 2 when bit 0 of the bank record's halfword at +4 is clear, 1 when it is set; `diagval` byte +7 of the bank record; `physid` the bank number 0 to 3; `nasid`; `virtid` byte +6; +56 the 32-bit size from the bank record; +60 zero; `errinfo` a 32-byte block. A bank whose record has bit 1 of its halfword at +4 set (absent) gets no component | the PROM's own memory-discovery table at `[node object +0x70] + 0x38`, 8 bytes per bank. The size field is **inferred** to be megabytes; the bank sizes themselves come from SPD through L1 request `0x0006` selector 4 ([node bring-up](../../software/firmware/snprom/node-bringup.md#spd-contents-for-a-2-gib-node): one 2 GiB bank for four 512 MB DIMMs) |
| `0x11` | hub UART (`init_klcfg_hubuart`, `0xffaa1930`, read in full) | `flags` `0x31`; `physid` 0; `virtid` 0; `nasid` | constants |
| 1 | CPU, per slice 0 to 3 (`init_klcfg_cpu`, `0xffaacbd0`, read through the slice test) | `flags` 1, or 2 with `diagval` `0xfd` when `0xffa99870` returns 0 for the slice (**inferred**: a disabled CPU, after which the `DisabledCpus` and `DisCpusReason` variables are consulted); `physid` the slice; `virtid` and `errinfo` all ones; +56 `0xffff`, +58 0, +60 `0xffff` | present when the slice's bit is set in the L1 request `0x0010` presence-and-enable mask (`0xffae8660`; the mask defaults to `0xf` when the request fails) and `0xffa11710` agrees the slice is present (not read: **inferred** to read processor-interface registers) |

The hub record's `struct_type` and the other numbers in the first column are the byte values the PROM stores
(established). The role names are the PROM's own function names (`init_klcfg_hub`, `_membnk`, `_hubuart`, `_cpu`); the
mapping of any field beyond `klinfo_t` to a meaning (+72 port slots, +104 text, +56 size) is **inferred** from the store
and the function name, because Linux defines none of them. For board `0x11` the builder then writes the text
`brd_name` at +193 and appends the board.

**EEPROM text and L1 requests (established as the path, inferred for the reply layout).** The hub's text comes from
`0xffaeccd0`, which reads the node board's EEPROM through the L1 (`0xffa84fd0`, request `0x0006`, device id 1, the same
read [boot-sequence](../../software/firmware/snprom/boot-sequence.md#node-board-identification-ip41-ip57-others) lists) and
formats it as `Part:...;Name:...;Serial:...;Revision:...;` text (`0xffaec9d0`). If the read fails the PROM prints
"Could not retrieve EEPROM info on nasid %d", stores an empty string and goes on; the klconfig is still built. When the
processor's identification register holds the simulator signature, a built-in string
(`Part:030-1604-001;Name:IP41;...`) is used instead; that path is not a hardware fact.

### The I/O boards on a one-node Altix 350 with IO10

Reached only if the widget-0 read in `0xffab15c0` returns a crossbar part number (`0xd000` or `0xd100`); any other widget
prints "New Widget %x connected to HUB." and no board is added ([boot-sequence](../../software/firmware/snprom/boot-sequence.md#io-discovery)).
Then `0xffab0f10` builds the following.

| Board | Type, name, parent | Built by | Notes |
|---|---|---|---|
| I/O brick midplane | `0x42` (`KLTYPE_IOBRICK_XBOW`), name `"IOBRICK"`; geoid type 1 (module), module id from L1 request `0x0003` via `0xffa80210` | `0xffab19f0` (read in full) | one crossbar component, `struct_type` 4, `partid` and revision from widget 0's id word (bits 27:12 and 31:28), `virtid` 0, `nic` all ones, +248 the master link number from `0xffaaf630`, `errinfo` a 4-byte block (`init_klcfg_xbow`, `0xffab1800`, read in full). Link ports from 8 to 15 are recorded in the crossbar component as 12-byte records starting at +56 + 12 (`link - 8`): halfword 0, a flag byte whose bit 2 is set, and the 32-bit offset of the I/O board on that link (`0xffab1b60`; **inferred** meaning) |
| I/O board, one per PIC bus | `brd_type` from the brick-type table below, `brd_name` the table's name, `brd_parent` (+152) the midplane board's full address, `brd_slot` from the widget address (bits 27:24, or 29:28 when bit 38 of the address is set) | `0xffabfb10` (`bridge_discover`, read in full) then `0xffaed410` or `0xffabf7c0` | for a PIC with identification `0xd102` and manufacturer 36 (bits 11:1 of the id word equal `0x24`) a second board is created for the second bus at widget base + `0x800000`; each gets a bridge component |
| bridge component on each I/O board | `struct_type` 5, `flags` 1, version 2, `partid` (id bits 27:12, so `0xd102`), `revision` (id bits 31:28), `widid` and `physid` the bus number, `virtid` NASID * 16 + bus, `nic` the board's `brd_nic`, +56 `0xff`, +57 7, +104 text offset (the L1 EEPROM text), `errinfo` a 4-byte block | `0xffabf850` and `0xffabf570` (both read in full) | `brd_nic` of the board is the 64-bit hexadecimal number after `"Laser:"` in the EEPROM text, when present |

No IOC4, IOC3, SCSI or Tigon component is built on this image: the strings `init_klcfg_ioc*` and `init_klcfg_tg3` that older
images carry ([base I/O cards](altix-350-base-io.md)) are absent from 10.54, and the routines that call the board and bridge
builders above are the only I/O klconfig builders found. That no other builder exists in 10.54 is **inferred** from the
string list and the caller census (a name-based search, not a proof).

**Brick-type table in `bridge_discover` (established).** The board type comes from the module id's type byte (bits 15:8),
read through `0xffa80430` for an even NASID (a compute SHub) and `0xffa80210` for an odd one. Non-positive result: type
`0x70`, name `WEIRDIO`.

| Type byte | Board type | Name |
|---|---|---|
| `0x3d` | `0x77` | `IXbrick` |
| `0x23` | `0x76` | `PXbrick` |
| `0x76` | `0x78` | `CGbrick` |
| `0x6b` | `0x7b` | `IAbrick` |
| `0x6a` | `0x7c` | `PAbrick` |
| `0x5e` | `0x7a` | `SAbrick` |
| `0x62` | `0x7d` | `GAbrick` |
| `0x66` | `0x7e` | `OpusTiobrick` |
| `0x7d`, `0x2c`, `0x2e` | `0x73` | `Extendedbrick` |
| `0x2b` | `0x74` | `AthenaBrick` |
| `0x6f` | `0x79` | `onboardIO` |
| `0x6d` | `0x71` | `onboardIO` |
| `0x6c` | `0x7f` | `onboardIO` |
| `0x7b` | `0x72` | `onboardIO` |
| anything else | `0x70` | `WEIRDIO` |

**What a one-node 350 gets: unknown, with a constraint.** On the even-NASID path the type byte is the lowercased L1
module type from request `0x0003` with no slab fold (`0xffa80430`, `0xffa7e5e0`; the fold to `c` applies only on the odd-NASID
path `0xffa7d510`). The [L1 request page](../../software/firmware/snprom/l1-requests.md#3-0x0003-rack-bay-type) infers type `F` for a 350, which
lowercases to `0x66` and selects board type `0x7e`, name `OpusTiobrick`. This is **inferred**; `0xffa7e3b0` (the reader behind
`0xffa7e5e0`) was only skimmed (it calls the `0x0003` reader). One constraint holds either way: with a result of `0x70`
the PIC branch of `0xffabfb10` would call the bridge fill with a null second board, so a working 350 must produce a type in
`0x71` to `0x74` or `0x76` to `0x7f` (inferred from that control flow, not run). Linux does not read the board type of
I/O boards for anything other than the SNIA and TIO test, so this does not affect boot.

### Values by source

- **SHub registers** (established as the reads, see [PROM reset accesses](../../devices/shub/prom-reset.md)): NASID at
  `0x81_1006_0580` bits 42:32; SHub ID at node offset `0x1_0000_0000` (part `0x4363`, revision bits 31:28);
  widget id words at `(nasid << 38) + 0x8000_0008_0000_0000 + link * 0x1000000` (compute NASID; the form with
  `0x8000_0000_0000_0000` and `link * 0x10000000` is used when the NASID is odd).
- **L1 replies**: `0x0003` (module word and type), `0x000e` (slab), `0x0013` (slot), `0x0010` (CPU presence and enable),
  `0x0006` with device id 1 (node EEPROM text), device ids 8 to 23 selector 4 (SPD), and the I/O board's own EEPROM text through the
  same `0x0006` family ([L1 requests](../../software/firmware/snprom/l1-requests.md)). Established as the paths; the I/O board's
  reply layout is **unknown** (a captured IO10 board area is not held).
- **SPD**: memory bank sizes only.
- **PROM variables**: `DisabledCpus` and `DisCpusReason` can mark a CPU disabled in its component.

## 3. What Linux reads, and what breaks

Linux reads only the board list header and three board fields. Everything else in the structures is written for other
consumers (the PROM's own diagnostic dump `klcfg`, SAL error handling, and I/O configuration, none of which Linux touches).

| Field | Read by | If absent or wrong |
|---|---|---|
| SAL result of `GET_KLCONFIG_ADDR` | `build_cnode_tables` (v5.3 745), `scan_for_ionodes` (v2.6.12 564), 2.6.5 `sn_setup` | zero: `BUG_ON` (v5.3) or `BUG()` (v2.6.12 except on the simulator): boot stops early. An address that is not physical RAM faults on the first read |
| `ch_board_info` (header +20) | same | zero: the macro still forms a non-null pointer to node offset 0, so the loop reads whatever is there as a board; v5.3 has no empty-list test. Needs a valid first board |
| `brd_type` (+5) | `board_needs_cnode` | only `0x11` and `0x12` have an effect; a node board with another type is ignored, so a headless or memoryless node or a TIO is silently missing from the node tables |
| `brd_nasid` (+48) | `physical_node_map[brd->brd_nasid]` and `sn_cnodeid_to_nasid[num_cnodes]` | a NASID not yet in the map and `>= MAX_NUMALINK_NODES` indexes past the `short` array; a NASID already mapped (the normal one-node case: the SNIA board's own NASID, set from ACPI) adds nothing |
| `brd_next_any` (+0) | `find_lboard_next` | non-zero and not a valid node-local offset reads garbage; a cycle never terminates; 0 ends the walk |

Every other field is unread by Linux v5.3 and v2.6.12 in the files fetched (`setup.c`, `io_init.c`, `io_common.c`,
`io_acpi_init.c`, `sn_hwperf.c`, `klconflib.c`): `struct_type`, `brd_flags`, `brd_geoid`, `brd_nic`, `brd_name`,
`brd_compts[]`, `brd_parent` and every component. v2.6.12's walk differs only in that it first takes the list head of each
node and finds the node's own SNIA board before collecting further ones; the same three fields matter. A full search of the
Linux tree for other readers was not run, so "unread" means unread in those files and in the 2.6.5 `sn_setup` scan.

On a one-node machine the effect of KLCONFIG is therefore small: a valid header and a list that terminates, with one board
of type `0x11` and the node's own NASID. The rest only has to be self-consistent for the PROM's own later users (the PROM's
`klcfg` dump command and error handling; the string "Can't initialize klconfig" is the PROM's fatal code `0x85`, and the routine that raises it was not traced).

## 4. What an emulator must provide

Items 1 to 3 let the PROM finish building; items 4 to 6 shape the contents; item 7 is for Linux.

1. **RAM for the heap block (established that the PROM needs it).** `0xb0000` bytes allocatable from the node heap; the PROM
   stores the block address itself. If the allocation fails the PROM prints "Out of memory - cannot allocate hwcfg" and calls
   its fatal handler with code `0x84`. Established for the code, inferred for the heap source.
2. **NASID register and SHub ID** (`0x81_1006_0580` bits 42:32 and `0x1_0000_0000`): the NASID goes into `brd_nasid`; ID part
   `0x4363` is required by the PROM's own check and the revision nibble reaches `brd_brevision` and the hub component
   (established for the reads, inferred for the nibble reaching `brd_brevision`).
3. **L1 identity replies**: `0x0003` (two integers, module word then type character), `0x000e`, `0x0013`, `0x0009` as in
   [L1 requests](../../software/firmware/snprom/l1-requests.md). They fill the geoid and the I/O board type. Established as
   requests; their effect on the node geoid is **inferred**.
4. **L1 `0x0010` presence and enable**: bit per CPU slice. A failing reply gives mask `0xf`; a reply with a bit clear drops that
   CPU's component (established, `0xffae8660` and `0xffaa1ea0`). Whether the slice presence test `0xffa11710` needs
   processor-interface register values: **unknown** (not read).
5. **SPD replies** for the memory bank (established, see [node bring-up](../../software/firmware/snprom/node-bringup.md#spd-contents-for-a-2-gib-node)):
   they produce the memory bank component. A node with no banks gets no memory components and fails earlier (progress code
   `0x80`).
6. **For the I/O boards**: widget 0 at the node's widget base reads back an id word with part `0xd000` or `0xd100`; a link
   widget (8 to 15) at `link * 0x1000000` returns an id word with bits 11:1 equal to 36 (`0x24`) and bits 27:12 equal
   to `0xd102` (bit 0 is not tested) (for example `0x0d102049` with revision 0), plus the PIC's own register reads that
   [the PIC page](../../devices/pic/README.md) lists. The base-I/O EEPROM text is optional: a failing read leaves the
   board name and `brd_nic` unset and the build continues (established for the hub, inferred for the I/O board). Established
   as the data the code compares; the combination for a real IO10 is **unknown** (a captured widget walk is not held).
7. **What Linux then needs**: a SAL `GET_KLCONFIG_ADDR` that returns the physical address of the header for every compute
   node, a header whose `ch_board_info` offset points to a valid chain, and one `0x11` board per compute node carrying that
   node's NASID. Established from the Linux code. The PROM builds this itself; an emulator that bypasses the PROM can build the
   same minimum, with link values that are node-local physical offsets.

## 5. Unknowns and routes

1. Absolute address of KLCONFIG on a booted node (heap state): trace the allocator, or a captured `GET_KLCONFIG_ADDR` result.
2. The brick type byte a one-node 350 reports on the even-NASID path, hence the I/O board type: read `0xffa7e3b0` in full and the
   L1's reply for the 350; or a captured `sn_topology` / klconfig dump from a 350.
3. The component layouts beyond `klinfo_t` (hub, memory bank, CPU, bridge, crossbar): Linux does not define them. The PROM
   stores are listed above; field meanings are inferred. A routine in the PROM that reads them back (the diagnostic dump
   `klcfg`, `0xffb220a0` and `0xffb23530`) would name the fields.
4. The chip object that supplies the geoid and NASID: filled by code not read here.
5. The text pool and header `+0x10` role; which routine raises code `0x85`.
6. Whether SAL 5.04 builds anything for a one-node 350 beyond what is above (for example the vga component path
   `init_klcfg_vgagfx` at `0xffaf1fc0`, the routine that adds a graphics component to the master node, is not on the IO10 path as read).
   Needs the call census of `0xffaf23f0`.
7. The 2.6.5 kernel's later reads after the type test (next-board load at offset 0) were not traced; only the three loads named
   in section 1.

Sources read: Linux `v5.3` and `v2.6.12` `klconfig.h`, `geo.h`, `module.h`, `types.h`, `arch/ia64/sn/kernel/{setup,io_init,io_common,io_acpi_init,klconflib}.c`
(the last at v2.6.12 only), `sn_hwperf.c`, `sn_sal.h`, `addrs.h`; the SAL 5.04 SHub 1 PROM; the held 2.6.5 kernel's `sn_setup`.
