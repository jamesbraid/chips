# SN2 graphics: how a GPU board attaches

Two SN2 product families carry vendor graphics boards, and they attach differently. The Silicon Graphics Prism puts an AGP
board behind a TIOCA bridge; the Altix 4700 and 450 graphics option puts a PCI Express x16 board in an expansion blade. This
page records the SGI side of both: carriers, bridges, what the SGI Linux code does for them, and what is left to the board
vendor. The Prism product pages are [prism.md](prism.md), [prism-deskside.md](prism-deskside.md),
[prism-power-team.md](prism-power-team.md) and [prism-extreme.md](prism-extreme.md); the 4700 chassis is
[altix-4700-iru.md](altix-4700-iru.md).

**Out of scope: the graphics silicon.** The GPUs on both lines are third-party parts (ATI FireGL boards on the Prism; an
unnamed PCI Express board on the 4700). Their registers, microcode and drivers are not documented in this repository; the
SGI-written parts below end at the bridge, the aperture and the PCI configuration the board sees. The Prism guides print
board names only (see [prism.md](prism.md#graphics-boards-and-outputs)).

Sources: SGI, *SGI Altix 3D Graphics Option Information* (the user's guide for the 4700 and 450 graphics option),
`007-4954-001` (February 2007, first release; PDF page is printed page plus 6); the Prism guides cited on the Prism pages;
Linux v5.3 files cited as `v5.3:path`. Grades follow [AGENTS.md](../../AGENTS.md).

## Altix 4700 and 450: PCIe boards in expansion blades

Established (007-4954-001):

- The 3D graphics board goes in either a double-wide I4E blade or a single-wide I2E blade (pp.8, 9). Each board occupies the
  width of two PCI slots. A single-wide I2E blade has two PCIe slots but takes one board for its full width; a double-wide I4E
  has two PCIe and two PCI-X slots, and with two boards fitted its PCI-X slots are unusable (p.2).
- The board supports "PCI Express x16" with full OpenGL (p.2). No GPU part, chip family or PCI identifier is printed in the pages read.
- A small power cable below the GPU fan "should remain unplugged at all times" (pp.1, 8). A six-pin cable on the back of the
  card and a flat ImageSync ribbon cable come off in the I4E replacement procedure (p.9).
- Keyboard and mouse connect to USB type A connectors on the IA (base I/O) blade, and at least two USB connections are
  needed (p.3). So the console graphics path is the IA blade's USB plus a PCIe board in an expansion blade, not anything on a
  compute blade.
- Video synchronisation: ImageSync cabling (p.6) and two-system sync (p.7), with an ImageSync connector pinout in the
  guide (p.20); not read in detail.
- Timeline: the 4700 guide says PCI Express is "available as an option" and "may not be immediately available"
  (007-4823-001 pp.53, 87); the graphics guide is dated February 2007, eleven months after it.

The 4700 guide's PCIe notes (p.87): PCIe is point-to-point serial, connectors are not compatible with PCI/PCI-X, a x16 link's
sustained throughput is about four times the fastest PCI-X, and a lane is two pairs of wires.

**Inferred** (not stated by any guide or file read): the PCIe slots of I2E and I4E blades sit behind a TIOCE. The bus
provider for type 5 exists in SGI's Linux code (`v5.3:arch/ia64/include/asm/sn/pcibus_provider_defs.h`), the platform
treats TIOCE like the PIC and TIOCP in placing the controller at the nearest node with CPUs
(`v5.3:arch/ia64/sn/kernel/io_common.c`, `sn_io_late_init`), and no other PCIe bridge is named for the 4700's PCIe blades. See
[tioce](../../devices/tioce/README.md) for the register facts. Also unstated: whether the graphics board is the
only function on its bus, and whether the platform firmware publishes a console entry for it (the Linux console-selection
path needs one, see below).

Unlike the Prism, nothing here uses the AGP aperture, the GART or `sgi-agp`: no TIOCA appears in the 4700 documents read.
The kernel's hotplug code also skips TIOCA buses and, among 4700 expansion blades, enables only the three-slot PCI-X board
([altix-4700-discovery.md](altix-4700-discovery.md)),
so a graphics blade is not hot-pluggable by the SGI driver: **inferred** from the board-type rule, since the code names
board codes, not graphics.

## Silicon Graphics Prism: AGP through a TIOCA

The hardware and wiring are on [the Prism overview](prism.md#graphics-attachment). This section adds what the SGI Linux code
does at run time, which is the part a model must reproduce. All established from the code at v5.3 unless marked.

### Bus and probing

- The PROM reports the bridge as a PCI bus of ASIC type 4. `tioca_bus_fixup`
  (`v5.3:arch/ia64/sn/pci/tioca_provider.c`) copies the PROM's bus record, maps its registers, builds the kernel record,
  finds the bus's device list, sets up the GART, claims the TIOCA error interrupt (`SGI_TIOCA_ERROR`, a shared level
  vector, with its affinity set), and sets the controller's node from the closest-node field in the PROM record. The
  PROM bus record is the contract; its layout is the common bus record of
  `v5.3:include/asm/sn/pcibus_provider_defs.h` plus the TIOCA extension in `tioca.h`.
- With a SHub 1 the kernel refuses to set up a TIOCA if the SAL revision is below 4.06 (`sn_sal_rev() < 0x0406`) and
  says so; there is no such check on SHub 2.
- The error interrupt handler makes one SAL call and leaves the work to the PROM.

### DMA mapping policy

`tioca_dma_map` picks a mode from the device's DMA mask. In order:

1. A device with a full 64-bit mask uses direct 64-bit mode: the bus address is the coretalk address of the page with the
   coherent-memory packet type (`1`) in bits 63:60. The mapper halts if the coretalk address is zero or does not fit in 54 bits.
2. A device with exactly a 48-bit mask uses AGP direct 48-bit mode: bus address bits 47:40 are the low 8 bits of the node id,
   39:38 the chiplet and 37:0 the node offset, so a device targeting node 0 needs at least a 40-bit mask because the chiplet
   field is never zero. The upper node-id bits come from a register field; the mapper refuses a page whose upper node bits
   differ from that field, or a node id above 64, with an error message. The register is `ca_agp_dma_addr_extn`, whose field
   overlap is an open question on [the TIOCA page](../../devices/tioca/README.md).
3. Anything else, or a failure above, uses the GART: contiguous bus space from the PCI part of the aperture.

A 32-bit direct mode exists in the chip but is never used, "so restrictive w.r.t. where the memory resides". MSI-style
mappings (`SN_DMA_MSI`) are refused. This policy is **software**; it does not say that the chip rejects other combinations.

### Fast writes and console

- Fast write is turned on for the bridge only if every VGA-class function on its bus has the AGP capability with the fast-write
  bit in its status; then each such function's AGP command register gets the fast-write bit and the bridge's own control bit
  is set to match (`tioca_fastwrite_enable`). A board with no AGP capability keeps fast write off for the whole bus.
- The kernel finds a VGA console from the PCDP table, as on [the Prism overview](prism.md#graphics-attachment); the only evidence
  that Prism firmware publishes one is the guide's instruction to plug the console monitor into pipe 0's left channel.

### What the card sees

The board is an ordinary AGP master as far as software goes: AGP 3.0 at 8x only with 64-bit addressing, sideband addressing
and fast writes offered (`v5.3:drivers/char/agp/sgi-agp.c`); a 2 GiB aperture at bus address `0x80000000` shared between an
AGP-mapped and a PCI-mapped window ([the TIOCA page](../../devices/tioca/README.md) has the register layout). Everything the
vendor driver does after that, command rings, retained objects, display programming, is the third-party silicon and out of
scope here.

## Unknowns

- The 4700 graphics board's chip and bridge, and the PROM's console entry for it: [questions/altix-4700-open.md](../../questions/altix-4700-open.md).
- Prism items (TIOCA count per XG2N, GPU part, SHub generation per shape): [questions/prism-open.md](../../questions/prism-open.md).
