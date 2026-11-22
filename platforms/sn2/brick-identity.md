# Brick identity on SN2: module ids, brick types, geo ids and how Linux finds them

How an SN2 enclosure (brick, module or blade) is named and told apart, in the PROM's hardware map and in what Linux
reads from it. This is the page to read before modelling a machine's inventory: the node chips are in
[the SHub page](../../devices/shub/README.md); what each enclosure holds is in [bricks.md](bricks.md) and the machine
pages.

Sources: SGI's Linux platform code at v5.3 (cited `v5.3:path`; also v2.6.12 where a file differs), SGI, *SGI L1 and L2
Controller Software User's Guide* `007-3938-005` (April 2006), SGI, *SGI Altix 3000 User's Guide* `007-4579-001`
(printed pages), SGI, *SGI Altix 350 System User's Guide* `007-4660-002`. The community SN2 tree was not needed. No
PROM or kernel binary was read for this page (see Unknown). Grades follow [the SN2 README](README.md).

## The module id

**Established** (`v5.3:arch/ia64/include/asm/sn/module.h`). A `moduleid_t` is a 32-bit number with three fields: bits
31 to 16 the rack, bits 15 to 8 the brick type, bits 7 to 0 the bay (the brick's position in the rack). The brick-type
byte is the L1's brick-type character code (next section), not a small index.

- The rack number is decimal-coded: `class * 100 + group * 10 + number`. `RACK_GET_CLASS` and friends divide it back.
  The kernel comment gives the class digit: 0 is a CPU or mixed rack, 1 is an I/O rack (`module.h`). The guide says
  compute racks (those holding C-bricks) are numbered from 001 and I/O racks by the quadrant they sit in
  (`007-4579-001` p.90, Figure 3-7); it does not mention a class digit. Established for the 3000 family; not checked for
  the 350, which needs no rack.
- The bay is the lowest rack unit the brick occupies: in a 40U rack a C-brick in units 5 to 7 is `c05`
  (`007-4579-001` p.90). Established.
- `format_module_id` (`v5.3:arch/ia64/sn/kernel/klconflib.c`) prints the brief form `RRRtBB`, for example `002c15`: three
  rack digits, one type character, at least two bay digits. The long form is `rack/002/bay/15`. Established.
- Before printing, the type character is folded to the one on the brick's display: the GA and Opus-TIO types print as
  `c`; PX, PE, PA and SA print as `p`; IX and IA print as `i`. Every other type prints as itself. Established (same
  function). The L1's own `config` output uses the folded form: `003c01`, `004i01`, `002c01` and `001x01` appear in the
  guide's examples (`007-3938-005` pp.49 and 50).

`MODULE_*BRICK` constants (`module.h`, unchanged between v2.6.12 and v5.3) number the brick kinds 0 to 17:
`C`, `R`, `I`, `K`, `X`, `D`, `P`, `N`, `PE`, `PX`, `IX`, `CG`, `OPUS`, `SA`, `IA`, `PA`, `GA`, `OPUS_TIO`. The kernel
also keeps a string `"cri.xdpn%#=vo^kjbf890123456789..."` indexed the same way (`brick_types`, `klconflib.c`).
Established that both exist; in the files read nothing indexes `brick_types`, so it is a table with no reader there.
There is no `M` brick kind in the list. See the M-brick note in [bricks.md](bricks.md).

## L1 brick-type codes

The L1 reports a brick type as one byte. `v5.3:arch/ia64/include/asm/sn/l1.h` lists them; the module id carries the
same byte. Established values relevant to the Altix 3000, 350 and Bx2 bricks:

| Code | Char | Name in `l1.h` | Brick |
|---|---|---|---|
| 0x63 | `c` | `C` | C-brick; the Altix 3000 C-brick's L1 sends `5` (IP41) and the PROM folds it to `c` ([altix-3000.md](altix-3000.md)) |
| 0x72 | `r` | `R` | R-brick |
| 0x69 | `i` | `I` | I-brick (Origin 3000, folded target for IX and IA) |
| 0x3d | `=` | `IX` | IX-brick |
| 0x23 | `#` | `PX` | PX-brick |
| 0x70 | `p` | `P` | P-brick (folded target for PX, PE, PA, SA) |
| 0x25 | `%` | `PE` | PE-brick |
| 0x35 | `5` | `IP41` | a board name used as a type code |
| 0x34 | `4` | `IP45` | a board name used as a type code |
| 0x36 | `6` | `TWISTER` | comment: "IP53 and ROUTER" |
| 0x78 and 0x79 | `x`, `y` | `X`, `X2` | XIO brick |
| 0x6f, 0x66 | `o`, `f` | `OPUS`, `OPUS_TIO` | Opus bricks (4700-era and Prism-era TIO platforms) |
| 0x6b, 0x6a, 0x5e | `k`, `j`, `^` | `IA`, `PA`, `SA` | the IA, PA and SA bricks |
| 0x2b, 0x7a | `+`, `z` | `ATHENA`, `DAYTONA` | TIO-attached boards |
| 0x2c, 0x2e | `,`, `.` | `1932`, `191010` | chassis types used by the blade systems (the header's own comments print the two characters swapped; these are the ASCII values) |

The `DAYTONA`, `1932` and `191010` codes and the whole `L1_BOARDTYPE_*` list (`CA`, `CB`, `IB`, `IC`, `ID`, `IE`, `AB`,
`AD`) are absent from v2.6.12 and present in v5.3, so they belong to the 4700 and Prism generation, not to the bricks
here. The mapping of these letters to firmware packages is in sysco `software/firmware/l1/sn2-brick-packages.md`.

**There is no code for the CR-brick.** Nothing in `l1.h` or `module.h` names a CR-brick, and the CR-brick has no
`MODULE_*` entry. The 3700 Bx2 appears in the controller guide's revision log only (`007-3938-005`, revision 004).
Which type character a CR-brick reports is **unknown**; candidates are `c` (the same character as a C-brick) or one of
the board-name codes `4` and `5`. The route is a captured `config` line from a Bx2 or the CR-brick's identity record in
an L1 image.

## The hardware map: KLCONFIG

**Established** (`v5.3:arch/ia64/include/asm/sn/klconfig.h`). The PROM builds a linked list of boards in each node's
memory. Linux gets its address with one SAL call, `SN_SAL_GET_KLCONFIG_ADDR` (0x02000005, `ia64_sn_get_klconfig_addr`,
`sn_sal.h`), which returns the header for a NASID.

- The header (`kl_config_hdr_t`, 112 bytes) has its board-list head at byte 20: a signed 32-bit offset, relative to the
  cached global address of that NASID (`NODE_OFFSET_TO_LBOARD`). The rest is padding as far as the kernel is concerned.
- Each board (`lboard_t`) carries `brd_next_any` (offset of the next board), `brd_type` (class in the high nibble, kind in
  the low), `brd_slot`, `brd_geoid`, `brd_nasid`, `brd_nic`, component offsets (up to 24), a 32-byte `brd_name` and the
  partition and diagnostic fields. The kernel files read use only the type, NASID and next-board offset (the per-node geoid comes from `hubdev_info`, below); the other fields are in the header
  for the PROM and tools, with no Linux reader.
- Classes: `0x10` node (CPU, memory and hub), `0x20` I/O, `0x30` router, `0x40` midplane, `0x70` I/O brick.
- Kinds the Altix generation uses: `KLTYPE_SNIA` 0x11 (a compute node, one per SHub), `KLTYPE_TIO` 0x12; routers
  `ROUTER` 0x31, `META_ROUTER` 0x33, `REPEATER_ROUTER` 0x34; I/O bricks `IOBRICK` 0x70, `NBRICK` 0x74, `PXBRICK` 0x76,
  `IXBRICK` 0x77, `CGBRICK` 0x78, `OPUSBRICK` 0x79, `SABRICK` 0x7a, `IABRICK` 0x7b, `PABRICK` 0x7c, `GABRICK` 0x7d;
  and the midplane `IOBRICK_XBOW` 0x42.

What Linux does with the list: `build_cnode_tables` (`v5.3:arch/ia64/sn/kernel/setup.c`) walks each online node's
board list and gives a compact node number to every board of kind `SNIA` or `TIO` whose NASID it has not seen, which
is how headless nodes and TIOs enter the node tables. Nothing else in the files read looks at `brd_type` or at the
names. Established. The loop starts at `ch_board_info` with no emptiness test: the first board's address is computed
from the offset, so a header whose offset is 0 makes Linux read node memory at offset 0 as a board. A NULL header is a
`BUG_ON` (same function). So an emulated PROM must give every node a header and at least one well-formed board whose
`brd_next_any` ends the list with 0. Established from the code; whether a real PROM ever emits an empty list is unknown.

**Inferred:** each SHub node on a C-brick, CR-brick or Altix 350 module appears as one `KLTYPE_SNIA` board in its own
list, from `board_needs_cnode` and the comment "C/M bricks" in `build_cnode_tables`. The routers' entries
(`KLTYPE_ROUTER` and relatives) and the I/O brick entries are inferred to be built by the PROM for the same reason;
Linux never reads them.

## Geo ids and the location strings

**Established** (`v5.3:arch/ia64/include/asm/sn/geo.h`, `v5.3:arch/ia64/sn/kernel/io_common.c`). A `geoid_t` names a
place in the machine: a module id, a type (module, node, router, I/O controller, PCI card, CPU, memory), a 4-bit
**slab** (the ASIC within a slot) and a 4-bit **slot** (the blade within a module). Fields for PCI cards add a bus and
slot; for CPUs a slice; for memory a bus and slot.

- Each hub carries its geoid in `hubdev_info.hdi_geoid`. The PROM fills it: `sn_fixup_ionodes`
  (`v5.3:arch/ia64/sn/kernel/io_init.c`) calls `SN_SAL_IOIF_GET_HUBDEV_INFO` (0x02000055) for every NASID with the address
  of the structure, and the PROM writes the structure. Established.
- `cnodeid_get_geoid` returns it. Linux reads only the module id, the slot and the slab from it.
- `/proc/sgi_sn/sn_topology` and the hwperf code print a location as `RRRtBB#S` for a brick (rack, type character, bay,
  slab) or `RRRtBB^SS#S` for a blade system (adding a slot) (`sn_hwperf_location_to_bpos`,
  `v5.3:arch/ia64/sn/kernel/sn2/sn_hwperf.c`). A CPU on the node has the same location plus a letter `a` onward for the
  slice. Established. The geoid slab is therefore the node number inside the enclosure. **Inferred** from the
  parse and the guide's node numbering (C-brick nodes 0 and 1; CR-brick nodes 0 to 3): the slab starts at 0 on each
  brick.
- The PCI address string for a bridge is `module_RRRtBB` plus two digits of bay, for example `module_001c07`
  (`sn_generate_path`, `io_common.c`). For the `191010` and `1932` chassis types it appends `^slot`. This function prints
  the raw type character from the module id with no fold. So an IX-brick prints `=` if the PROM stored the raw L1 code
  and `i` if it stored the folded one. Which of the two the PROM stores is **unknown**.
- The hwperf object names classify hardware by substring: an object whose name contains `SHub` is a node (`SHub 2.` a
  generation 2 node), `TIO` an I/O node, `NL3Router` and `NL4Router` routers; any other name containing `Router` also
  counts as a router (`v5.3:arch/ia64/include/asm/sn/sn2/sn_hwperf.h`). Established. The kernel's own comment says an
  NL4 router can run the NL3 protocol, so the printed protocol is a guess. These objects come from a PROM call (hwperf
  `ENUM_OBJECTS`, op 12), so the NL3 or NL4 router in a brick is whatever the PROM names; which name each brick's
  router gets is unknown here.

## What else the kernel asks the PROM about bricks

All **established** as call numbers and arguments (`v5.3:arch/ia64/include/asm/sn/sn_sal.h`):

| Call | Number | Use |
|---|---|---|
| `SN_SAL_GET_SN_INFO` | 0x0200001e | v0: bits 7:0 SHub type (0 SHub 1, 1 SHub 2), 15:8 log2 system node count, 23:16 log2 nodes per sharing domain, 31:24 partition, 39:32 coherency id, 47:40 region size; v1: NASID mask and shift |
| `SN_SAL_SYSCTL_OP` op 1 (`SAL_SYSCTL_OP_IOBOARD`) | 0x02000030 | board type of the I/O board behind a TIO's NASID, as an L1 brick or board code; the TIOCX driver accepts the brick codes `SA` and `ATHENA` and the board code `L1_BOARDTYPE_DAYTONA` (0x0800, not the brick code 0x7a) (`v5.3:arch/ia64/sn/kernel/tiocx.c`) |
| `SN_SAL_SYSCTL_PARTITION_GET` | 0x0200003a | partition number of a NASID |
| `SN_SAL_SYSCTL_IOBRICK_MODULE_GET` | 0x02000033 | module id of an I/O brick (the wrapper exists; no caller in the files read) |
| `SN_SAL_SYSCTL_MODID_GET`, `SN_SAL_SYSCTL_SLAB_GET` | 0x02000031, 0x02000036 | numbers defined, no wrapper or caller in v5.3 |
| `SN_SAL_IOIF_GET_HUBDEV_INFO` | 0x02000055 | fills `hubdev_info` including the geoid, per NASID |
| `SN_SAL_GET_KLCONFIG_ADDR` | 0x02000005 | the board list header |

An odd NASID is a TIO (`v5.3:arch/ia64/sn/kernel/io_common.c`, `sn_common_hubdev_init`: "if TIO"), so the C-brick, CR-brick
and 350 module, which have SHubs only, use even NASIDs. Established as a rule in the code; the assignment of NASID
numbers inside a brick is in [address-map.md](address-map.md).

## How a PROM or L1 identifies the Altix 350 modules

The 350 guide prints no module identifier beyond the IP57 board name and its serial ID EEPROM ("contains component
information", `007-4660-002` p.138, CMPX module; the same list is in the base and expansion module chapters). The base compute, CPU expansion and CMPX modules share one node board
([altix-350.md](altix-350.md)), so the hardware that differs between them is the interface board and the riser. Whether and how the
L1 tells them apart is not printed. Which type character the module's L1 reports, and what the EEPROM holds, is **unknown**: no EEPROM
contents or L1 identity dump is held. See [../../questions/altix-brick-identity.md](../../questions/altix-brick-identity.md).

## Unknown

- The CR-brick's L1 type character and the 350 modules' type character (sysco holds the firmware side). The Altix 3000
  C-brick's is settled: `5`, folded to `c` by the PROM before the module word is packed (`0xffa7d510`, SAL 5.04).
- The contents of a real KLCONFIG board list for any Altix machine. The route is a read of the PROM's list builder in
  `snprom` (Ghidra; held in the RE root) or a captured `/proc/sgi_sn/sn_topology`; neither was done for this page.
- The serial ID EEPROM layout on IP57 and the interface board.
