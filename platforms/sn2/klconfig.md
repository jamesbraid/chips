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
- **Where the PROM puts it (established for the construction, inferred for the address).** `hwcfg init`
  (`0xffaa0100`, which names its source file `hwcfg/common/init.c`) allocates `0xb0000` bytes from the node's heap arena
  (handle at block A `+0x1f8`, allocator `0xffac30c0`, arena magic `ARNA`), stores the pointer at block A `+0x20`
  (block A: the pointer at `0x1000038`), and calls `0xffaa3cf0` to lay the area out. **KLCONFIG starts `0x10000` bytes into that
  block** (every access adds `0x10000`; the allocator checks the 8-byte value at that address is `0xbeedbabe` and prints
  "kl_config_info_alloc: bad magic" otherwise, `0xffaa4560`). The heap is the tail of block A, which `0xffac42d0` places at
  `(nasid << 38) + 0x30_0240_0000` and fills with regions up to `+0x8ae80` (a `0x200`-byte header, then regions) ([block A table](../../software/firmware/snprom/os-handoff-tables.md#5-block-a-and-the-tables-the-builders-read)).
  So the first possible block is `(nasid << 38) + 0x30_0248_ae80` plus arena headers, and **KLCONFIG for NASID 0 is at or after
  `0x30_0249_ae80`** (**inferred**: allocations that come first, and the header sizes, were not read). That is inside the
  type 6 runtime-data range of the memory map. Route for the exact value: trace the allocator (`0xffac13f0`, `0xffac3290`) on a booted node, or a captured `GET_KLCONFIG_ADDR` result.
  That the SAL call returns exactly `block + 0x10000` is **established**: the handler at `0xffb19c20` (`sal_02000005`) returns
  status 0 and, in r9 (`v0`, the only word Linux uses), the word at offset `+0x20` of the node's block A plus `0x10000`; a node
  with no memory gets status -2 and r9 0 (`software/sal/sn2-runtime.md` reads the same routine). The link routine `0xffaa5450`
  stores the first board at block `+0x10014`, which is header `+20`.
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
| I/O board, one per PIC bus | `brd_type` from the brick-type table below, `brd_name` the table's name, `brd_parent` (+152) the midplane board's full address, `brd_slot` from the widget address (bits 27:24, or 29:28 when bit 38 of the address is set) | `0xffabfb10` (`bridge_discover`, read in full) then `0xffaed410` or `0xffabf7c0` | for a PIC with identification `0xd102` and manufacturer 36 (bits 11:1 of the id word equal `0x24`) a second board is created for the second bus at widget base + `0x800000`; each gets a bridge component. `0xffabfb10` also accepts `0xd112` for that second board, but the link walk in `0xffab0f10` only calls it for a link part of `0xd102` (decompiler reading, not cross-checked in disassembly) |
| bridge component on each I/O board | `struct_type` 5, `flags` 1, version 2, `partid` (id bits 27:12, so `0xd102`), `revision` (id bits 31:28), `widid` and `physid` the bus number, `virtid` NASID * 16 + bus, `nic` the board's `brd_nic`, +56 `0xff`, +57 7, +104 text offset (the L1 EEPROM text), `errinfo` a 4-byte block | `0xffabf850` and `0xffabf570` (both read in full) | `brd_nic` of the board is the 64-bit hexadecimal number after `"Laser:"` in the EEPROM text, when present |

No IOC4, IOC3, SCSI or Tigon component is built on this image: the strings `init_klcfg_ioc*` and `init_klcfg_tg3` that older
images carry ([base I/O cards](altix-350-base-io.md)) are absent from 10.54, and the routines that call the board and bridge
builders above are the only I/O klconfig builders found. That no other builder exists in 10.54 is **inferred**: a census of callers of the component allocator `0xffaed090` finds nine (`0xffaa06e0`, `0xffaa1310` hub, `0xffaa1930` hub UART, `0xffaa1a10` memory bank, `0xffaacbd0` CPU, `0xffaae490`, `0xffab1800` crossbar, `0xffabf850` bridge, `0xffaf1fc0` VGA). Only the crossbar and bridge builders are on the I/O path; `0xffaa06e0` (reached from `0xffaa0a30`) and `0xffaae490` (from `0xffaae6a0`) were not traced to their callers.

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

**What a one-node 350 gets: depends on one L1 reply (`0x7e`, `OpusTiobrick`, if `F`; `0x79`, `onboardIO`, if `o`, which the PIC attach favours).** The 350's PIC has an even NASID, so
`bridge_discover` calls `0xffa80430`, which maps the NASID to the chip object (`0xffa7fcb0`) and calls `0xffa7e5e0`, which calls
`0xffa7e3b0` (read in full). That routine reads the cached module word and type (cache keys 8 and 9); on a miss it sends L1
request `0x0003` through `0xffa7ca10` to the **`0x4ffff000` target** (the node path `0xffa7d1f0` uses `0x0ffff000`),
lowercases a type letter `A` to `Z`, and caches the result. With the simulator signature in `cpuid[2]` it skips the L1 and uses rack 1, bay `0xf`,
type `0x3d` (`IXbrick`, `0x77`). `0xffa7e5e0` only folds `0x34` and `0x61` to `0x69`; there is no slab lookup and no fold to `c`
(those are in `0xffa7d510`, the odd-NASID path), and `0xffa7d010` packs rack `<< 16`, type `<< 8`, bay. So the type
byte is whatever the L1 answers to `0x0003` at that target. If the 350's L1 says `F`, the board type is `0x7e`, name `OpusTiobrick`;
that `F` is **inferred** from the L1 default (see the [L1 request page](../../software/firmware/snprom/l1-requests.md#3-0x0003-rack-bay-type))
and no 350 reply is held. The table has a second candidate for an Opus-class compute brick: type byte `0x6f` (`o`, `L1_BRICKTYPE_OPUS` in `v5.3:arch/ia64/include/asm/sn/l1.h`) maps to board type `0x79` (`OPUSBRICK` in the klconfig header) with name `onboardIO`. Which of `0x66` (`f`) and `0x6f` is the 350's letter is **unknown**; neither reaches Linux. A second constraint comes from the PIC attach, which reads the same L1 letter through request `0x0013` and accepts only `#`, `=`, `m`, `o` and `v`
([PIC page](../../devices/pic/README.md#where-the-ioboard-type-comes-from-and-what-an-unaccepted-one-does)): an `F` (`0x66`) would stop the PIC attach with
"Unknown ioboard", so a 350 that boots with this PROM reports one of `#`, `=`, `m`, `o`, `v` (`o`, `0x6f`, board type `0x79`, `onboardIO`, is the one that names an Altix module; inferred), not `F`. One constraint holds either way: with a result of `0x70` the PIC branch of `0xffabfb10` would call the
bridge fill with a null second board, so a working 350 must produce a type in `0x71` to `0x74` or `0x76` to `0x7f`
(inferred from that control flow, not run). Linux does not read the board type of I/O boards for anything other than the SNIA
and TIO test, so this does not affect boot.

### What a one-node Altix 350 with an IO10 gets (summary)

| Board | `brd_type` | `brd_nasid` | Components (`struct_type`) | Grade |
|---|---|---|---|---|
| node, name `IP41` | `0x11` | the node's NASID | hub 2, memory bank `0x32` (per present bank), hub UART `0x11`, CPU 1 (per slice) | established as stores; values inferred as above |
| I/O brick midplane, name `IOBRICK` | `0x42` | the NASID passed to the builder (the node's) | crossbar 4 | established as stores; reached only if widget 0 reads as a crossbar part |
| I/O board, one per PIC bus (two for a PIC `0xd102`) | from the brick-type table, see below | same | bridge 5 | established as stores; the type depends on one L1 reply |

The IO10 itself leaves no component: no IOC4, VSC 7174 or Ethernet record exists on this image, so the base I/O card is invisible
in KLCONFIG apart from the bridge records. Its PCI devices are discovered by the I/O interface set-up behind SAL calls `0x55` to `0x58`
([SAL runtime](../../software/sal/sn2-runtime.md#the-structures-behind-0x55-to-0x58)), which works from the PROM's own bus and device objects (whether it also reads KLCONFIG was not checked).
Sources, per field: NASID, SHub part and revision from the SHub registers; module, slab, slot, CPU enables, EEPROM text and brick type letter from the L1; bank sizes from SPD through the L1; nothing from PIC or TIO probing except the widget id words and the PIC identification word that select the builders.

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

## Geoid and module id

Traced in the IA-64 Ghidra module (`--sn2-prom --no-analysis`, address ranges) with a flat objdump cross-check on `shub1snprom.bin` (snprom 10.54). Linux is the `nsafran1217/linux-sn2` tree (SGI platform code, same files as v5.3).

### The kernel's path (established)

- `scdrv_init` (`drivers/char/snsc.c`) names each system-controller node `format_module_id(geo_module(g), BRIEF)` plus `^slot#slab`, with `g = cnodeid_get_geoid(cnode)`. That function returns `hubdev_info.hdi_geoid`, the first member of the per-node structure. The structure comes from SAL `IOIF_GET_HUBDEV_INFO` (`0x55`, direct path) or from the pointer in the node's ACPI `_CRS` (ACPI path).
- `geoid_t` is 12 bytes (the PCI-card member sets the size): module `u32` at +0, type `u8` at +4, one byte at +5 with slab in the low nibble and slot in the high nibble, `hdi_nasid` at +12. Types: 1 module, 2 node, 3 router, 4 I/O controller, 5 card, 6 CPU, 7 memory.
- `geo_module`, `geo_slot` and `geo_slab` return `0xffffffff`, `0xff` and `0xff` when the type byte is 0. `format_module_id` prints `'0'+class`, `'0'+group`, `'0'+num` of `rack = m >> 16`, then the type character, then the bay (`m & 0xff`) in at least two digits. For `0xffffffff` the rack is 65535: class 655 wraps to a non-printable byte, group 3, num 5; the type byte `0xff` is the second non-printable. So `?35?255^255#255` means exactly one thing: **`hdi_geoid.type == 0`**. A valid type-2 geoid built from failed L1 replies would print slot and slab 15 (the PROM masks `0xff` to a nibble), never 255.
- A good lone 350 gives `001c01^0#0`: rack 1, type `c`, bay 1, slot 0, slab 0.

### The PROM's path (established unless marked)

| Field | Source | Site |
|---|---|---|
| module | L1 `0x0003` word `rack << 6 | bay` and type letter (lowercased); packed `rack << 16 | type << 8 | bay` | `0xffa7d1f0`, `0xffa7d510`, `0xffa7d010` |
| type character | `0x0003` letter; `f`, `l`, `b`, `{` become `c` when L1 `0x000e` returns slab 0 or `0xff` (also `o`, `5`, `m`, `@` become `c` unconditionally) | `0xffa7d510` |
| slab | L1 `0x000e` (low nibble of byte +5) | `0xffa7d950`, `0xffa7ce90` |
| slot | L1 `0x0013` first integer (high nibble of byte +5); `0xff` on error, masked to 15 | `0xffa7d760`, `0xffa7cbe0` |
| type 2 (node) | always written by the builder, whatever the L1 said | `0xffaac4b0`, packer `0xffa11f10` |

1. `main` (`0xffa19a20`) re-initialises the local node record (`0xffa197f0` -> `0xffa0f8c0`, which sets an all-zero, type-0 geoid and partition `0xff`), then stores the `0xffaac4b0(2, nasid)` result at record +8 (8 bytes) and +16 (4 bytes) and the L1 `0x0009` partition at +5. The PROM's own console text (`000c00#0a`, `module/000c00/slab/0`) is printed from this record and the L1 cache, so it can be valid while the kernel's geoid is not.
2. `0xffa47290` copies that record into the configuration table (tag `PCFG`, 0x48-byte entries, record at entry +0x30, geoid at +0x38 and +0x40) through `0xffa450e0`. Only `shub_discover` (`0xffa5df20`, ops slot `0x1c0`, reached from the neighbour crawl `0xffa45780`) rewrites a geoid, and it rewrites a *neighbour's* descriptor, never the local template: it reads the L1 "pushed data" word (`SH_SCRATCH2`, `0x1_101d_0100`, through `0xffa8d120`) and on failure prints "shub_discover: sysctl_get_pushed_data failed" and stores a **type-0** geoid. See "Does the local geoid pass through `shub_discover`" below.
3. At SAL runtime `0xffb28df0` (called from the I/O setup `0xffb2d450`, itself reached from the `IOIF` handlers) walks the table entries of class SHub or TIO whose partition byte equals the local one and, per entry, `0xffb28c30` allocates a `0xc78`-byte node record: geoid copied from the entry to +0 (8 plus 4 bytes), `nasid` at +0xc, peer `0xffff` at +0xe. `0x55` copies the first `0x2f0` bytes of that record (`0xffb3d8e0`); it returns 1 and copies nothing if the NASID is not on the node list.
4. Other places that make a type-0 geoid: `0xffa11f10` with type 0 (also used as the default of `0xffa12440` and `0xffb22720`).

### The 'O' path through the builder (traced in Ghidra, 10.54)

Question: what the PROM derives when the L1 answers `0x0003` = (0, `O`), `0x000e` = (0), `0x0013` = (0, `O`) (the model's current replies).

| Step | Site | Result |
|---|---|---|
| `0x0003` reply | `0xffa7ca10` | integers (word, type); a type in `A` to `Z` gets `+0x20`, so `O` becomes `o` (`0x6f`) (established) |
| rack, bay | `0xffa7d1f0` | word masked to 20 bits; rack = bits 15:6, bay = bits 5:0; word 0 gives rack 0, bay 0 (established) |
| `o` extra reads | `0xffa7d1f0` | for type `o` only: up to 11 board-information-area reads (`0xffa84fd0`, device id 98, selector 2); if one succeeds and the string at offset `0x2e` of the reply buffer matches `030_1951_001` at `0xffbb4670` for the length in the low 6 bits of the byte before it (compare routine `0xffa15040`), bit 4 of the state flag word at +0x50 is set. A missing reply is the `0x8d` die path, not a geoid change (established for the code; the match string's role is inferred) |
| type character | `0xffa7d510` | `o`, `5`, `m` and `@` become `c` unconditionally, so `O` gives `c` and **no `0x000e` lookup is made for it**; `,` and `}` become `.`, `d` becomes `r`; only `l`, `b`, `{` and `f` ask `0x000e` and fold to `c` for slab 0 or -1 (established) |
| module | `0xffa7d010` | `rack << 16 \| type << 8 \| bay`, valid when bay < 0x100: `0x00006300` (established) |
| slot, slab | `0xffa80270` (`0x0013`, first integer), `0xffa802f0` (`0x000e`, first integer) | 0 and 0; both masked to a nibble. The `0x0013` second integer (`O`) is lowercased and discarded by this caller (established) |
| builder | `0xffaac4b0(2, nasid)` | type byte 2, module at +0, slot in bits 47:44 and slab in bits 43:40 of the 8-byte word, bytes 8 to 11 zero from the 12-byte clear (established; bytes 8 to 11 as the second return register `r9` is inferred) |

So for those replies the geoid is `00 63 00 00 02 00 00 00 00 00 00 00` (module `0x00006300`, type 2, slot 0, slab 0), stored at record +8 (8 bytes) and +0x10 (4 bytes) by `main` at `0xffa19d8c`, and `format_module_id` prints `000c00^0#0` (reading of the kernel function in the section above: inferred, not run). It is a valid type-2 geoid. The L1 replies therefore cannot produce `?35?255^255#255`.

A faithful lone Altix 350 with an `O` module at rack 1, bay 1 needs: `0x0003` = (`0x41`, `O`) (word `1 << 6 | 1`), `0x000e` = (0), `0x0013` = (0, `O`). That gives module `0x00016300 | 1 = 0x00016301`, geoid `01 63 01 00 02 00 ...` and `001c01^0#0`. Rack 001, type `c`, bay 01 matches the prompts `001c01-L1>` that the 350 manual (007-4660-001) and the L1 and L2 guide (007-3938-005) print, as recorded on [the L1 request page](../../software/firmware/snprom/l1-requests.md); this pass did not re-open those PDFs. The model must also answer the board-information reads for type `o` (the board-information section of [the L1 request page](../../software/firmware/snprom/l1-requests.md)).

### Does the local geoid pass through `shub_discover` (`0xffa5df20`)?

No on a lone node (established for the code paths, inferred for the port-flag state; not run).

- The local record is the template at `[[0x1000038] + 0x38]`. `main` (`0xffa19a20`, called at `0xffa1e66c`) re-initialises it with `0xffa197f0` -> `0xffa0f8c0` (the only call of `0xffa0f8c0` that targets the template; the other callers at `0xffa0b24c`, `0xffa0b5cc`, `0xffa46d4c`, `0xffaa399c`, `0xffaa4c9c`, `0xffaa960c` build stack temporaries and `0xffa7fcb0` a stack object), then writes the type-2 geoid and L1 partition at `0xffa19d70` to `0xffa19df0` (established).
- `0xffa47290` copies that template into the configuration table with `0xffa450e0`, which calls ops slot `0x1c8` (the insert-time method `0xffa5e0b0`), not `0x1c0`. Its three callers are `0xffa47aac` and `0xffa483ac` (both inside `0xffa47870`, reached from `0xffa1b0dc` in `0xffa1ade0`, itself entered from `0xffa1add0` at the end of the function at `0xffa19850`, called at `0xffa1ecec`) and `0xffb08b9c` (a method of the table at `0xffc4ca80`). `0xffa1e66c` (`main`) comes before `0xffa1ecec` in the same function `0xffa1de00`, so the geoid is written before the copy: **inferred from address order in a straight run, branch structure not checked**.
- Slot `0x1c0` is loaded in one place: `0xffa45a16` in the crawl `0xffa45780`. The descriptor it passes (`0xffa46a50` output, built from the route to the neighbour) lives on the stack, and the crawl runs only for ports whose link flag (byte `+3` bit 0 of the 0x28-byte port record) is set. The only other pointer to `0xffa5df20` is the table entry at `0xffc4bb60`; the `+448` offset loads at `0xffa056fc`, `0xffa9da7c`, `0xffac9840`, `0xffacbb56` and `0xffaf5660` address other structures (read from the listing).
- A failed `0xffa8d120` there writes type 0, module `0xffffffff`, slot and slab `0xff` into that neighbour descriptor's +8, +0x10 and +5 fields only. It cannot zero the local entry. `0xffa8d120` has a second caller, `0xffa6193c` (the TIO discovery).
- What SAL `0x55` returns: `0xffb28df0` loops over the table and, for each SHub or TIO entry whose partition byte equals the template's (`[template + 5]`), `0xffb28c30` allocates the `0xc78`-byte record and copies the entry's geoid (+0x38, +0x40) to record +0, +8, nasid at +0xc; `0xffb3d8e0` copies `0x2f0` bytes of it, or returns 1 and copies nothing when the NASID is not on the list at `[[0x1000038] + 0x10]` (the count `[0]`, entries from `[1]`, `-1` for none). So a type-0 geoid at the kernel is **not explained by the `SH_SCRATCH2` read**. The two open causes are a `0x55` that returns 1 (NASID missing from that list, inferred) and the order of the insert and the geoid store (inferred above). The route stays a run that logs the `0x55` status and the first 16 bytes it returns.

### Why the model shows `?35?255^255#255`

Established: the kernel read a type-0 `hdi_geoid`. Not established: which PROM step produced it. By the reading above, a node whose L1 answers `0x0003`/`0x000e`/`0x0013` (even with zeros, which gives `000c00`) reaches the table with a type-2 geoid, so the L1 values are not the cause. Candidates, in order: (a) `0x55` returned non-zero or was not called, leaving the kernel's zeroed structure (**inferred**: the kernel `kzalloc`s it and skips on a non-zero status); (b) `shub_discover` ran and failed on the pushed-data word (ruled out for the local entry: see the section above); (c) the record at `[[0x1000038]+0x38]` is rebuilt after `main` without a refill (**unknown**: not seen in the direct callers of `0xffa0f8c0`). A run that logs the `0x55` result and dumps the first 16 bytes of the returned structure separates (a) from (b) and (c); that is the route.

### What the model must answer for a lone 350 at rack 1, bay 1

Reply payloads, frame grammar of [the L1 request page](../../software/firmware/snprom/l1-requests.md#conventions-used-below) (status 4 bytes, count, arguments tag `00` plus 4-byte big-endian integer):

| Request | Payload |
|---|---|
| `0x0003` | `00000000 02 00 00000041 00 00000046` (word `1 << 6 | 1`, type `F`) |
| `0x000e` | `00000000 01 00 00000000` (slab 0) |
| `0x0013` | `00000000 02 00 00000000 00 00000046` (slot 0, type `F`) |

The PROM lowercases `F`, sees slab 0 and uses type `c`, so the module is `0x00016301` and the geoid `001c01^0#0` (**inferred** for `F`: no real 350 reply is held; rack 001 and bay 01 are the example's choice). These replies fix the L1-derived fields only; they do not by themselves clear the type-0 symptom (previous section).

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

1. Exact address of KLCONFIG on a booted node: bounded below by `0x30_0249_ae80` for NASID 0 (see above); trace the allocator headers, or a captured `GET_KLCONFIG_ADDR` result.
2. The brick type byte a one-node 350's L1 returns to `0x0003` at target `0x4ffff000` (`f` or `o` are the candidates; the PIC attach rejects `f`, so `o` is inferred), hence the I/O board type (`0xffa7e3b0` is read;
   the reply is not held): a captured L1 exchange, or a `sn_topology` / klconfig dump from a 350.
3. The component layouts beyond `klinfo_t` (hub, memory bank, CPU, bridge, crossbar): Linux does not define them. The PROM
   stores are listed above; field meanings are inferred. A routine in the PROM that reads them back (the diagnostic dump
   `klcfg`, `0xffb220a0` and `0xffb23530`) would name the fields.
4. The chip object that supplies the geoid and NASID: filled by code not read here.
5. The text pool and header `+0x10` role; which routine raises code `0x85`.
6. Whether SAL 5.04 builds anything for a one-node 350 beyond what is above (for example the vga component path
   `init_klcfg_vgagfx` at `0xffaf1fc0`, the routine that adds a graphics component to the master node, is not on the IO10 path as read).
   Needs the call census of `0xffaf23f0`.
7. (Closed in the review below: the 2.6.5 scan also loads `brd_next_any` at offset 0.)

Sources read: Linux `v5.3` and `v2.6.12` `klconfig.h`, `geo.h`, `module.h`, `types.h`, `arch/ia64/sn/kernel/{setup,io_init,io_common,io_acpi_init,klconflib}.c`
(the last at v2.6.12 only), `sn_hwperf.c`, `sn_sal.h`, `addrs.h`; the SAL 5.04 SHub 1 PROM; the held 2.6.5 kernel's `sn_setup`.

## Review

Independent review of this page by a reviewer who did not write it. Reviewed chips revision fc1a4eb. Linux checked at v5.3 and v2.6.12 (`klconfig.h`, `geo.h`, `types.h`, `setup.c`, `io_init.c`, `sn_sal.h`, `l1.h`; single files from raw.githubusercontent.com). The SAL 5.04 SHub 1 image (sha256 `51ccf9ad...3a34617`) was read in the IA-64 Ghidra module (`--ghidra-export --sn2-prom`); the held 2.6.5 kernel could not be exported (the exporter reads ELF files as MIPS, and a flat IA-64 export of `sn_setup` produced no function), so that check is from `ia64-linux-gnu-objdump` and is only a disassembly reading. Decompiler output was used for navigation and the stores below were read against the disassembly or the decompiled stores of each routine.

**Confirmed.**
- Layout: both `klconfig.h` files compile to a 112-byte header with `ch_board_info` at 20, a 232-byte `lboard_t` and a 56-byte `klinfo_t`, with every offset in the page's tables (`brd_type` 5, `brd_geoid` 16, `brd_nic` 40, `brd_nasid` 48, `brd_compts` 52, `brd_parent` 152, `brd_name` 193, `brd_next_same_host` 226, `brd_next_same` 228; `klinfo_t` `partid` 10, `nic` 16, `physid` 24, `virtid` 28, `widid` 32, `nasid` 34, `data` 40, `errinfo` 48). `geoid_t` is 12 bytes (`geo_cpu_t` and `geo_mem_t` grow it past the 8-byte pad array). The two headers differ only in the helper macros the page lists. The magic `0xbeedbabe` is not in either Linux tree; it is the PROM's own value and was not re-read here.
- PROM stores: nasid +48, compts +52, name +193, parent +152 and same-host +226 are all hit by `0xffaed240`, `0xffaa1ea0`, `0xffab0f10`, `0xffaed410`, `0xffabf570`, `0xffaa5450`; the geoid is copied as 8 plus 4 bytes. Defaults in `0xffaed240` match the page.
- Node board: type `0x11`, `brd_sversion` raised to 3, name copied to +193, hub, membank, hub UART and CPU components with the struct types, flags and offsets the page lists (checked for hub, membank and UART in decompiled stores; CPU only through the page's own reading).
- I/O boards: widget 0 part `0xd000` or `0xd100` in `0xffab15c0`; the brick-type table in `0xffabfb10` matches row for row, including the `0x70` WEIRDIO default; the second board for `0xd102` with manufacturer `0x24`; bridge component fields in `0xffabf850` (`partid` id bits 27:12, `revision` bits 31:28, `virtid` NASID * 16 + bus, +56 `0xff`, +57 7); `brd_nic` from `Laser:` in `0xffabf570`; slot bits in `0xffaed410`.
- Linux reads: `board_needs_cnode` tests only `KLTYPE_SNIA` and `KLTYPE_TIO`; `physical_node_map[brd->brd_nasid]`; `find_lboard_next` follows `brd_next_any`; `BUG_ON(NULL)` at v5.3 746; v2.6.12 `scan_for_ionodes` uses the same three fields. `ia64_sn_get_klconfig_addr` uses only the SAL `v0` word (status is ignored), so a status of -2 with r9 0 is the NULL case. No other file read (`io_init.c`, `io_common.c`, `sn_hwperf.c`) touches `lboard_t`.
- Held 2.6.5 kernel (`sn_setup`, objdump): the constant `0x2000005` is loaded at two sites; the scan loads the word at +20 of the SAL result, the byte at +5 of the board (`adds -17`, `cmp4.ltu 1` selects types `0x11` and `0x12`), the halfword at +48, a `short` table lookup indexed by it, and then the word at +0 for the next board. This closes the page's unknown 7.

**Findings.**
1. The `+0x10000` result of `GET_KLCONFIG_ADDR` was graded inferred; `0xffb19c20` shows it directly. Edited to established (mechanical).
2. The 350's I/O board type: `0xffa7e3b0` was marked skimmed. Read in full, it sends `0x0003` to target `0x4ffff000`, not `0x0ffff000`, so the [L1 request page](../../software/firmware/snprom/l1-requests.md) statement that the `0x4ffff006` form is used only by the slot and slab wrappers is wrong for this site (not edited here; another page). The type is the L1's letter lowercased, with no slab fold (the fold to `c` is only on the odd-NASID path). Under the simulator signature it is `0x3d`, `IXbrick`. For a real 350 the answer is `0x7e` `OpusTiobrick` if and only if the L1 replies `F`; that `F` is still inferred, so the page now says "depends on one L1 reply" instead of "unknown". Edited.
3. The PIC part: `0xffabfb10` accepts `0xd112` as well as `0xd102` for the second bus, but `0xffab0f10` only dispatches to it for `0xd102`. Added to the table cell. The dispatch comes from decompiled code with confused register names and was not cross-checked in disassembly.
4. "IP41": the PROM writes it unconditionally. `0xffaa1ea0` copies the string at image `0x1b5de0` (`TIO` sits at `0x1b5dd8`) into +193 whenever the board type is `0x11`, and no `IP57` string exists in the image. It does not describe the 350's node board, which 007-4660-001 calls IP57: it is the board-family label the PROM was built for (the same word is in the SAL banner) and matches Linux's `L1_BRICKTYPE_IP41` (`0x35`, which `0xffa7d510` folds to `c`). The page's statement stands. One unread consequence: the string `update_klcfg_cpuinfo: Can't find IP41 on nasid` says the PROM itself looks the node board up by that name, so a model should not rename it. The routine was not read.
5. IOC4: no IOC4, IOC3, SCSI or Tigon builder string exists in this image (only the `init_klcfg_` names listed by `strings`: hub, hubuart, membnk, cpu, xbow, bridge, iobrick_xbow, iobrick_bridge, vgagfx, corelet), and the two board builders called from `0xffab0f10` are the only I/O record builders on that path. That is a name and call-path argument, not a census: `init_klcfg_corelet` is not mentioned on the page and was not traced. Grade stays inferred.
6. `0xffaa1a10` builds memory components only when its second argument (passed through from `hwcfg_node_init`) is 0. The page lists the components as unconditional. What the argument means is unknown; for the single-node call it is the value `main_two` passes, which was not read.

**Not checked.** The GET_KLCONFIG_ADDR heap address; the header magic check at `0xffaa4560`; region sizes and board and component counts in section 1; the CPU, EEPROM-text and chip-object routines beyond the page's own reading; the `corelet` and `vgagfx` callers; the L1 firmware's real reply for a 350; the v2.6.12 `klconflib.c` helpers; whether `0xffab0f10`'s `0xd102` dispatch holds in disassembly.

Cleared scope: the layout tables, the PROM store offsets, the brick-type table, and the Linux and 2.6.5 read analysis. Not cleared: the "depends on one L1 reply" type claim (the `F` is unverified), finding 5, and finding 6.

## Review of the 350 summary, block A, I/O SAL and console (second reader)

Independent review of chips commits `e009a62`, `f7dba3f`, `962c477` and `a6cb292` by a reader who did not write them. Every address below was re-read in the IA-64 Ghidra module (`--sn2-prom --sal-runtime --no-analysis` with address ranges) and cross-checked against a flat objdump of the same image and the inflated SAL runtime ELF; no grade rests on a model run.

**Confirmed.** Builders `0xffaa1ea0` (node, type `0x11`), `0xffab0f10` (I/O walk), `0xffab19f0` (midplane: type `0x42` at `+5`, name `IOBRICK`, geoid type 1, crossbar through `0xffab1800`, then the link routine `0xffaa5450`), `0xffabfb10`/`0xffabf570` (per-bus board and bridge, `0xd102` only) and the parent store (`+0x98` = midplane) and slot store (`+10`). Sources by field as the page gives them.

**Changed.** The heap start is block A `+0x8ae80`, not `+0x8ac80`: the region carve starts after the 64-word header at block `+0x200`. The KLCONFIG lower bound for NASID 0 is therefore `0x30_0249_ae80`. The "no other component builder" census is now a caller census of the component allocator (nine callers, two untraced), still **inferred**.

**Brick letter, not settled.** Linux `l1.h` names `0x66` `f` as `L1_BRICKTYPE_OPUS_TIO` and `0x6f` `o` as `L1_BRICKTYPE_OPUS`; no Linux or PROM name ties either to the 350. In the L1 firmware notes (sysco), the ARM L1 string-to-type map (`brickConvertString`) has `opus` (`O`) and no 350 string, and the IP57 routines are board-class handlers, not a brick letter. The PROM follows type `o` with board-area EEPROM reads, which fits an on-board base I/O (`onboardIO`), but that is a fit, not a reading. `F` (the blank-L1 default) was the inferred value; the PIC attach, which accepts `o` and rejects `f`, now makes `o` the better-supported one (inferred; see the [PIC page](../../devices/pic/README.md#where-the-ioboard-type-comes-from-and-what-an-unaccepted-one-does)). The page's conditional on the L1 reply stands.

### Review (PIC letter cross-checks, commit 043c9f6)

The ioboard byte comes from request `0x0013` (with a `0x0003` fallback when the L1 answers -101), lower-cased, no slab fold; re-read in the PIC page's review. The ARM L1 1.62.1 answers `0x0013` for a single-slot `F` brick with the unchanged letter `F`, so an `F` still fails the PIC attach. The claim that a booting 350 reports `o` is inferred; `m` and the PX/IX letters also pass.
