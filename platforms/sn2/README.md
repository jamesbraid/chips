# SN2: the IA-64 Altix and Prism machines

SN2 is SGI's name, in the Linux platform code, for the NUMAflex generation that pairs Intel Itanium 2 processors
with the SHub node chip and ran Linux only. This directory holds one page per machine. The chips are the SHub (node
controller and crossbar), the PIC and TIO families (PCI-X, PCIe and AGP bridges), the IOC4 on the base I/O card, and
the NUMAlink routers. No SHub, TIO or router register map is held yet, so these pages record topology, population and
what software sees, not registers.

Grades follow [AGENTS.md](../../AGENTS.md): **established** (stated by SGI's Linux platform code at v5.3, or by a cited
manual page), **inferred** (reasoned, reasoning given) and **unknown** (with the route that would settle it). Linux
source is cited as `v5.3:path`. Manuals are cited by number and printed page; [the source index](../../references/documents/INDEX.md)
lists each with what was read. Nothing here comes from IRIX: Altix and Prism ran Linux.

## Machines

| Machine | Guide read | Node enclosure | Interconnect as the guide names it | Page |
|---|---|---|---|---|
| Altix 350 | 007-4660-001 (2004), 007-4660-002 | 2U base compute, CPU expansion and CMPX modules, IP57 node board | "NUMAlink" in -001, NUMAlink-4 in -002; 3.2 GB/s each direction | [altix-350.md](altix-350.md) |
| Altix 330 | 007-4790-001 (2005) | 1U compute module | NUMAlink-4, one port | [altix-330.md](altix-330.md) |
| Altix 3300, 3700 | 007-4579-001 (2003) | C-brick, 3U, two nodes | "NUMA 3", R-brick router | [altix-3000.md](altix-3000.md) |
| Altix 3700 Bx2 | 007-4377-002 (2004) | CR-brick, 4U, up to four nodes and two routers | NUMAlink-4 | [altix-3700-bx2.md](altix-3700-bx2.md) |
| Altix 4700, Altix 450 | 007-4823-001 (2006), 007-4857-001 | blades in a 10U or 5U IRU | NUMAlink 4 | [altix-4700.md](altix-4700.md) |
| Silicon Graphics Prism | 007-4772-001 | deskside node board | not read | [prism-deskside.md](prism-deskside.md) |

The rackmount and scalable Prism guides (007-4701, 007-4774) and the Altix 450 body were only partly read; the
machine pages say where. Brick pages for the CR-brick and the 350 modules are inside their machine pages for now.
The Altix 3000 IX- and PX-brick are on [the Origin 3000 brick pages](../bricks/ixbrick.md), which already cite the
Altix guide.

## Which chip where

**SHub, generation 1 or 2.** The Linux kernel does not infer the generation from the product. At boot it asks the
PROM through a system-abstraction-layer call and keeps the answer per CPU (`v5.3:arch/ia64/sn/kernel/setup.c`,
`ia64_sn_get_sn_info` returning the `shub2` flag; `is_shub1()` and `is_shub2()` select register sets and workarounds
at lines 195 to 225 and 681 to 695; the call is at line 594). The register header names the first generation's registers with an `SH1_`
prefix (`v5.3:arch/ia64/include/asm/sn/shub_mmr.h`). Established: both generations exist and one kernel runs on both.
The manuals rarely name the generation:

| Machine | SHub generation | Grade and source |
|---|---|---|
| Altix 4700 | 2 | established: the L1 guide calls the compute blades C1 and C2 "SHub 2.x based" (007-3938-005 p.50) |
| Altix 3000, 3700 Bx2, 350, 330, 450 | not stated | unknown. Route: a boot log or `/proc/sgi_sn` capture from each, or the generation flag the PROM returns |
| Altix 3700 Bx2 | probably 2 | inferred only from timing: the guide is dated November 2004 and the Linux patch series adding "support for new chipset" (SHub 2) is dated 1 December 2004 (message `20041201203852.GA26131@sgi.com` on the linux-ia64 list) |

The 350 and 330 guides list the same SHub blocks: a crossbar (XN), a processor interface
(PI), a memory and directory interface (MD), two network interfaces (NI), an I/O interface (II) and a local block
(LB) (007-4660-001 p.104; 007-4790-001 p.79). That is the first generation's block list or both; it does not tell
them apart. The 3000 guide calls the same chip the "Super-Bedrock ASIC" (007-4579-001 p.81) and the Bx2 and later
guides "Super-Hub (SHub)". Established that the guides use both names for the node chip of the machine they describe;
inferred that they mean the one part, from the identical role and the 4700 guide's single "SHub" name.

**PIC or TIO for I/O.** PIC is the PCI-X bridge also used by the Origin 3000 IX- and PX-bricks. TIO is a separate chip
family, with bridge variants for PCI-X (TIOCP), PCIe (TIOCE), AGP (TIOCA) and a Crosstalk-extension carrier
(TIOCX) (`v5.3:arch/ia64/include/asm/sn/tiocp.h`, `tioce.h`, `tioca.h`, `tiocx.h`); the kernel treats a TIO as its own
node with its own NASID (`v5.3:arch/ia64/sn/kernel/setup.c` line 706, node types `KLTYPE_SNIA` and `KLTYPE_TIO`).

| Machine | I/O bridge | Grade and source |
|---|---|---|
| Altix 350, 330 | PIC, on the PCI riser or board, behind an XIO link from the SHub | established for the 350: "PCI riser card provides ... PIC ASIC" (007-4660-001 p.105) and the logic diagram on p.99 |
| Altix 3000, Bx2 IX- and PX-brick | PIC, three per brick | established: the driver guide's IX-brick figure shows three "PCI-X host bridge adapters" (007-4520-006 p.19); chips already holds [IX-brick](../bricks/ixbrick.md) |
| Altix 4700 PCIe and PCI-X expansion blades | TIO bridges | inferred: the blade list has PCIe and PCI-X blades (007-4823-001 p.53; 007-3938-005 p.51) and the controller's board codes `IC`, `ID`, `IE` (PCIe 2-slot, PCI-X 3-slot, PCI-X plus PCIe 4-slot) in `v5.3:arch/ia64/include/asm/sn/l1.h`; no manual here names the bridge chip |
| Prism deskside | AGP slots, PCI-X buses | established for the slots (007-4772-001 pp.19, 27); inferred TIOCA for AGP from the chip's name and function |

**IOC4.** The IO9 base I/O card of the Altix 350 and the 3000 family carries an IOC4 for the IDE channel to the DVD-ROM, the
NVRAM and the time-of-day clock (007-4660-001 p.104; 007-4520-006 p.18 lists serial ports, PS/2 ports and real-time
interrupt ports too). The later Altix 350 and the IX-brick generation also use the **IO10** card, a SATA variant: the
Linux IOC4 driver names IO9, IO10 and PCI-RT as the three IOC4 card variants (`linux-history:drivers/misc/ioc4.c`,
`ioc4_variant`), with a QLogic SCSI controller on IO9 and a Vitesse VSC 7174 SATA controller on IO10 (007-4660-002
pp.72, 112 to 114 for the guide side). The IOC4 driver is not in v5.3; stream B cross-checks it.

**NUMAlink 3 versus 4.** The guides disagree with the usual naming and with each other, so take the table as what
each says, not as a clean split:

- The 3000 guide describes a "third-generation NUMAflex" called NUMA 3 and then says its two nodes are joined by a
  "6.4-GB/s NUMAlink 4 channel" (007-4579-001 p.81). Established as printed; unresolved which is meant.
- The Bx2 and 4700 guides call themselves "fourth-generation NUMAflex" and NUMAlink-4 (007-4377-002 p.49;
  007-4823-001 p.47). The 330 and 450 guides name NUMAlink-4 (007-4790-001 p.57; 007-4857-001 p.64).
- The 350 guide says only "NUMAlink" in the first revision and "NUMAlink-4" in the second, 3.2 GB/s each direction per port (007-4660-001 pp.109, 112; 007-4660-002 pp.66, 69). The driver guide
  gives the SC-brick two "6.4-GB/s (each direction)" NUMAlink channels (007-4520-006 p.17), a different unit from the
  350 figure. Unresolved: whether either guide quotes per direction or both directions.

**Controller.** Every machine has an L1 in the node or IRU and, except the 4700, an optional or required L2; the
kernel reaches them through the PROM, not through registers. The host side is written up in the sysco repository
(`software/firmware/l1/sn2-controller-host-protocol.md`), which also says which L1 firmware packages serve these bricks.

## What a Linux guest sees

Established from Linux v5.3: the console is a PROM-mediated serial port, `ttySG0`, driven by SAL console calls and
the shared vector `SGI_UART_VECTOR` (0xe9) (`v5.3:drivers/tty/serial/sn_console.c` lines 59 to 60, 706 to 715;
`v5.3:arch/ia64/include/asm/sn/intr.h` line 15). The platform reserves vectors 0x30 to 0x38 for XPC activation,
I/O interface error, Crosstalk error, PCI-ASIC error, ACPI SCI, TIOCA error, TIO error, TIOCX error and the SHub
timer, and 0xe7 for XPC notify; device vectors run 0x3c to 0xe6 (`v5.3:arch/ia64/include/asm/sn/intr.h` lines 18 to 30).
The node physical address map is [address-map.md](address-map.md) and the SAL calls the kernel makes are in
[../../software/sal/](../../software/sal/README.md).
