# Altix 4700 and 450: how software finds the blades

Linux does not probe the IRU. It asks the PROM, through SGI-specific firmware calls, for a description of the nodes, I/O
bridges and routers, and it reads a per-node configuration graph the PROM built. This page records that interface as far
as SGI's Linux platform code defines it, so a machine model knows what the PROM must answer. It holds no register facts;
the chassis and blades are on [altix-4700-iru.md](altix-4700-iru.md), the node address map on
[address-map.md](address-map.md) and the call list on [the SAL page](../../software/sal/README.md).

Sources: Linux v5.3 files (SGI's Linux platform code, graded established as the evidence order says), cited as
`v5.3:path`: `arch/ia64/include/asm/sn/{l1.h,geo.h,module.h,types.h,klconfig.h,sn_sal.h,pcibus_provider_defs.h}`,
`arch/ia64/include/asm/sn/sn2/sn_hwperf.h`, `arch/ia64/sn/kernel/{setup.c,io_init.c,io_common.c}`, `arch/ia64/sn/pci/tioce_provider.c`,
`arch/ia64/sn/kernel/sn2/sn_hwperf.c`, `arch/ia64/sn/pci/pcibr/pcibr_provider.c`, `drivers/pci/hotplug/sgi_hotplug.c`;
manuals as on the [IRU page](altix-4700-iru.md). The same tree serves the 350 and 3000; the 4700-specific parts are marked.

## Node identity from the PROM

- **Generation and sizes (established).** `SN_SAL_GET_SN_INFO` (call number `0x0200001e`) returns, in the first result
  word, the SHub type in bits 7:0 (0 for SHub 1, 1 for SHub 2), log2 of the maximum node count in 15:8, log2 of nodes per
  sharing domain in 23:16, partition id 31:24, coherence id 39:32 and region size 47:40; the second word holds the NASID
  mask in 15:0 and the position of its low bit in 23:16 (`v5.3:arch/ia64/include/asm/sn/sn_sal.h`). The kernel keeps
  the answer per CPU and branches on it for register sets and workarounds. On PROMs that return "not implemented" the
  header falls back to hard-coded SHub 1 values (11-bit NASID mask, shift 38, system size 10, sharing domain 8); a SHub 2 PROM
  must implement the call. Full call reading belongs to the SAL page.
- **CPU to node (established).** `SN_SAL_GET_SAPIC_INFO` (`0x0200001d`) maps a processor's SAPIC id to its NASID,
  sub-node and slice (same header); the kernel's `nasid_slice_to_cpuid` inverts the table (`setup.c`). Slice numbers 0 to 3
  are printed as letters a to d, matching the "logical processor A to D" heartbeat LEDs of the compute blade
  (007-4823-001 Figure 7-1, p.108; inferred match, since the guide does not say the letters are slices).
- **NASID is not a blade number (established).** The kernel numbers nodes with a compact `cnodeid`; compute nodes come first, in
  node order, and I/O nodes (TIOs) and memory-less or headless nodes are appended to the tables after them
  (`v5.3:arch/ia64/sn/kernel/setup.c`, `build_cnode_tables`, comment "ensures cnode == node for all C & M bricks").
  A blade that holds only memory therefore still gets an ordinary node number; a TIO gets a cnode past the compute nodes.

## The configuration graph

`SN_SAL_GET_KLCONFIG_ADDR` (`0x02000005`) returns, per NASID, the address of a header whose first board record starts a
linked list of boards (`v5.3:arch/ia64/sn/kernel/setup.c`, `build_cnode_tables`, which walks `ch_board_info` and `find_lboard_next`). The
walk looks only at board type: `KLTYPE_SNIA` (`CPU class | 1`) and `KLTYPE_TIO` (`CPU class | 2`) each need a cnode
(`board_needs_cnode`). Other types the header names: routers (`KLTYPE_ROUTER`, `META_ROUTER`, `REPEATER_ROUTER`) and
the I/O brick family, whose entries run from the Origin 3000 bricks up to `KLTYPE_IABRICK` (base I/O), `PABRICK`,
`GABRICK` and others (`v5.3:include/asm/sn/klconfig.h`). Established as the header and the walk. The record layout beyond
the board header is not read here; it is also a SAL-page matter. Whether the 4700 PROM reports each blade as one board, or
a router board as two router records, is **unknown**.

## Names and locations

Two naming layers exist, both established from the headers.

**Module identifier** (`v5.3:include/asm/sn/module.h`): a 32-bit value with the rack number in bits 31:16, the brick-type
character in 15:8 and the bay in 7:0. The rack number is a 3-decimal-digit number printed as shown; the header also
carries an older class/group/number decomposition of it (class 0 for compute or mixed racks, 1 for I/O racks). The brick
type is an ASCII letter, so an IRU is `001c07` (rack 1, `c`, bay 7), the form the L1 prints.

**Geographic identifier** (`geoid`, 8 bytes; `v5.3:include/asm/sn/geo.h`): module id, a type byte (module, node, router,
I/O controller, PCI card, CPU, memory), and two 4-bit fields, **slab** (ASIC within a slot, 0 to 15) and **slot** (blade
within the module, 0 to 15). The header comment's longest example is `module/001c07/slab/5/node/memory/2/slot/4`, and a
CPU adds a slice and a memory item adds a bus and slot.

**Location string** that the PROM hands the hardware-performance interface for every object, parsed by `sn_hwperf.c`
(`sn_hwperf_location_to_bpos`): two forms, the old `RRRtBB#S` (rack, type letter, bay, then `#` and slab) and the
bladed form `RRRtBB^SS#S` (adding `^` and a two-digit slot). Both are established as the two `sscanf` formats; an example
processor location has a slice letter appended (`..#0a`). So a blade's identity on a 4700 is rack, IRU, blade slot and slab:
the IRU maps to `RRRtBB`, the blade slot to `^SS`, and the ASIC within the blade, a SHub or a TIO, to the slab. That the slab
is 0 for a compute blade's SHub and nonzero for a second ASIC on a blade is **inferred** from the `slab` field and the L1
guide's "Slab 0" and "Slab 1" labels for the 450's two router boards ([IRU page](altix-4700-iru.md#chassis)); no
source states the slab numbering of the SHub and TIO on an expansion blade.

## The hardware-performance interface

SGI's `SN_SAL_HWPERF_OP` (`0x02000050`, "lock") is a PROM call that returns the system object list and the NUMAlink port
graph; the kernel's `/proc/sgi_sn/` topology file and ioctl nodes are a thin layer over it
(`v5.3:arch/ia64/sn/kernel/sn2/sn_hwperf.c`, `v5.3:include/asm/sn/sn2/sn_hwperf.h`). All established as the code.

- **Call.** `ia64_sn_hwperf_op(nasid, opcode, a0..a4)` goes to the master NASID (the console node). Opcodes: 1 get heap
  size, 2 install a heap, 10 object count, 11 object distance, 12 enumerate objects, 13 enumerate ports, 14 and 15 set and get
  registers, 16 to 18 acquire, release, force-release; the kernel adds three more of its own (100, 101, 102: CPU info, object-to-node and node-to-NASID lookups) that it answers
  without calling the PROM. Statuses: 0 ok, 1 no memory, 2 no permission, 3 I/O error, 4 busy, 253
  reconfigure, 254 invalid. The heap is a buffer the kernel hands the PROM, which the PROM then uses for its answers; the
  size comes from the first call.
- **Object record.** A 32-bit id, a flag word (bit 0 "this partition", bit 1 "shared"), a 128-byte name, a 128-byte
  location string and a port count. Records with neither flag are in another partition and are skipped.
- **Object kind is a substring of the name.** `SHub` is a node, `SHub 2.` a generation 2 node, `TIO` an I/O node,
  `NL3Router` and `NL4Router` and any name containing `Router` are routers. So the PROM's names must contain these strings;
  nothing else distinguishes them in the code. The kernel's slab label for a router is "NL3R or NL4R".
- **Port graph.** For each object with ports, `ENUM_PORTS` returns an array of (port, connected object id, connected port)
  records. The kernel prints each link as `numalink N <location>-<port> ... endpoint <location>-<port>, protocol LLP3` or
  `LLP4`; the protocol is called LLP3 if either end is an NL3 router, otherwise LLP4, with the comment that an NL4 router
  can be configured to run the NL3 protocol and the code does not query it. The nearest-node search keeps the port list in a 16-entry array and halts the
  kernel (`BUG_ON`) for an object with more ports, so no node or router that the code walks there has more than 16. This is the machine's NUMAlink topology source; a model that wants
  `/proc/sgi_sn` to look right must supply it.
- **Nearest node.** For a node without CPUs or without memory, the kernel looks first at the nodes its ports connect to
  directly, then at the other nodes on one router it is connected to, and last at any node with CPUs and memory
  (`sn_hwperf_get_nearest_node_objdata`); a TIO is looked up the same way, skipping other I/O nodes. The kernel uses it to place PCI controllers: the PIC, TIOCP and TIOCE buses are
  attached to the nearest node with CPUs; a TIOCA is placed by the closest-node field the PROM reports (`io_common.c`,
  `sn_io_late_init`, comment).

## PCI buses and expansion blade types

- **Bus providers (established).** Each PCI bus carries an ASIC type: 1 a plain PCI-to-PCI bridge (no fixup), 2 PIC, 3 TIOCP,
  4 TIOCA, 5 TIOCE; a provider table indexed by it maps each to PCI, PCI/PCI-X, AGP or PCIe handlers, the PIC and TIOCP
  sharing one provider and TIOCE having its own (`v5.3:include/asm/sn/pcibus_provider_defs.h`, `pcibr_provider.c`
  lines 257 and 258, `tioce_provider.c` line 1060). The PROM
  supplies the bus record through `SN_SAL_IOIF_GET_PCIBUS_INFO` (`0x02000056`), and device records through
  `...GET_PCIDEV_INFO` (`0x02000057`) and hub-device data through `...GET_HUBDEV_INFO` (`0x02000055`).
- **Which blade maps to which bridge is not stated.** No manual or file reads that the PCIe blade holds a TIOCE and the
  PCI-X blade a TIOCP (or a PIC): **inferred** from the existence of the providers for PIC, TIOCP, TIOCE and the blade
  mix on the 4700, and from the I/O node being a TIO; the chips repository's bridge pages
  ([tioce](../../devices/tioce/README.md), [tiocp](../../devices/tiocp/README.md), [pic](../../devices/pic/README.md))
  hold the register facts. Route: a boot log from a 4700 listing bus numbers and the asic type per bus, or the held SHub 2
  PROM read for the bus-record builder ([questions/altix-4700-open.md](../../questions/altix-4700-open.md)).
- **Board code per I/O node (established).** `SN_SAL_SYSCTL_OP` (`0x02000030`) with sub-operation 1 returns "the associated
  ioboard type" for a NASID (`ia64_sn_sysctl_ioboard_get`, `v5.3:sn_sal.h`); `sn_ioboard_to_pci_bus` (`pcibr_provider.c`) calls it with the
  bus's node. The answer is one of the codes below. The only consumer in the tree is the hotplug driver.

### Board and brick codes

From `v5.3:arch/ia64/include/asm/sn/l1.h`, quoting the header's comment letters. Established as constants; the
mapping to blades is inferred:

| Code | Value | Comment letters | Reading |
|---|---|---|---|
| `L1_BRICKTYPE_IA` | `0x6b` | `k` | the base I/O brick, the IA blade |
| `L1_BRICKTYPE_PA` | `0x6a` | `j` | accepted by hotplug like IA; which unit it names is unknown (the name suggests a PCI-X brick) |
| `L1_BRICKTYPE_IX`, `PX` | `0x3d`, `0x23` | `=`, `#` | the IX- and PX-brick, which the 3000-family pages cover |
| `L1_BRICKTYPE_C` | `0x63` | `c` | the compute brick letter, also the letter in `001c07` |
| `L1_BRICKTYPE_R`, `N`, `X`, `I`, `P` | `0x72 0x6e 0x78 0x69 0x70` | `r n x i p` | router, NUMAlink module, XIO brick and others of the earlier family |
| `L1_BOARDTYPE_IP69` | `0x0100` | `CA` | a compute board |
| `L1_BOARDTYPE_IP63` | `0x0200` | `CB` | a compute board |
| `L1_BOARDTYPE_BASEIO` | `0x0300` | `IB` | base I/O |
| `L1_BOARDTYPE_PCIE2SLOT` | `0x0400` | `IC` | two-slot PCIe: the I2E (inferred from slot count) |
| `L1_BOARDTYPE_PCIX3SLOT` | `0x0500` | `ID` | three-slot PCI-X: the I3X |
| `L1_BOARDTYPE_PCIXPCIE4SLOT` | `0x0600` | `IE` | four-slot PCI-X plus PCIe: the I4E |
| `L1_BOARDTYPE_ABACUS` | `0x0700` | `AB` | an FPGA application board (RASC), inferred from the manual's RC blade |
| `L1_BOARDTYPE_DAYTONA` | `0x0800` | `AD` | unknown |
| `L1_BOARDTYPE_INVAL` | -1 | | invalid |

Pairing the two-letter codes with blades rests on slot counts and the guide's three expansion types. Which of `IP69` and
`IP63` is the single-processor and which the dual-processor compute board, or either of them the SHub 2 board, is
**unknown**; the one L1 example in the guide names a compute board `IP73_667` instead ([IRU page](altix-4700-iru.md)).
The brick-type letters belong to the controller family shared with the earlier machines and are not specific to the 4700.

### Hotplug rules the code implements (established, `v5.3:drivers/pci/hotplug/sgi_hotplug.c`)

- Buses behind a TIOCA never get hotplug slots (`sn_pci_bus_valid`).
- A bus gets slots only if the board code is IX, PX, IA, PA, or the three-slot PCI-X board `ID`. So of the 4700 expansion
  blades only the three-slot PCI-X blade is hot-pluggable, which agrees with the L1 guide's "supports hot-plugging" for I3X
  and not for the others (007-3938-005 p.51).
- On the IX and IA base I/O boards, segment 1 bus 0 (the base I/O board's own bus) rejects hot-plug of every device except
  device 1; the rest of the base-I/O bus belongs to the board's own chips (`sn_pci_slot_valid`). The segment-1 bus-0 rule is
  established; what sits on device 1 is a question for the IA blade page.
- Hotplug state changes go through the PROM (`SN_SAL_IOIF_SLOT_ENABLE`, `SLOT_DISABLE`, `0x02000053`, `0x02000054`).

## The PROM and sizes held

SGI's own `README` shipped inside the PROM packages says `shub2snprom.bin` supports the Altix 4700, and the 450 from
build 10.23 on (see [references/sn2-holdings.md](../../references/sn2-holdings.md)). The held SHub 2 images
([references/ia64-binaries.md](../../references/ia64-binaries.md)) are the route to settle the unknown entries above; no
reading of them is on this page. Nothing here comes from a 4700 boot log.

## Not covered

The `klconfig` board record layout, the IRouter protocol over the SAL channel (`SN_SAL_IROUTER_OP`, `0x02000043`; opcodes
open, close, send, receive and interrupt control), the console and error calls, and everything register-level belong to
the SAL page and the SHub, TIO and router pages. The Altix 450 differs from the 4700 in blade count and router count
only, as far as the guides say; its guide labels the node chip SHub 2 and PROM packaging (from build 10.23) places it
with the SHub 2 image. What the PROM does with board types, and whether it can tell the two apart, is on
[altix-450.md](altix-450.md#3-what-the-shub-2-prom-does-with-board-types).
