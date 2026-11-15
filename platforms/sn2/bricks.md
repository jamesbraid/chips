# Altix 3000 and Bx2 bricks, and the 350 modules

What each enclosure of the Altix 3000, 3700 Bx2 and 350 contains: chips, slots, links and controller, as the guides
print them. How the PROM and Linux name and discover each is in [brick-identity.md](brick-identity.md). The Altix 4700
and 450 use blades instead; see [altix-4700.md](altix-4700.md). This page holds no register facts.

Sources: SGI, *SGI Altix 3000 User's Guide* `007-4579-001` (2003); *SGI Altix 3700 Bx2 User's Guide* `007-4377-002`
(Nov 2004); *SGI Altix 350 System User's Guide* `007-4660-002`; *Linux Device Driver Programmer's Guide, Porting to
SGI Altix Systems* `007-4520-006`; *SGI L1 and L2 Controller Software User's Guide* `007-3938-005`; Linux v5.3. Printed
page numbers. Grades follow [the SN2 README](README.md).

## At a glance

| Brick | Machine | Height | Holds | L1 | Links out |
|---|---|---|---|---|---|
| C-brick | Altix 3300, 3700 | 3U | two SHub nodes, four Itanium 2, up to 32 DIMMs | one | two NUMAlink (NI), two XIO (II) |
| CR-brick | Altix 3700 Bx2 | 4U | up to four SHub nodes, up to eight Itanium 2, up to 48 DIMMs, two NL4 router ASICs | one | eight external NUMAlink, two XIO |
| R-brick | 3000 and optional on Bx2 | 2U | one eight-port router ASIC | one, plus a USB hub | eight NUMAlink |
| IX-brick | 3000 and Bx2 | 4U | three PIC ASICs, six PCI-X buses of two slots, an IO9 base I/O card | one | two XIO |
| PX-brick | 3000 and Bx2 | 4U | three PIC ASICs, six PCI-X buses of two slots | one | two XIO |
| Base compute module | Altix 350 | 2U | one IP57 node (one SHub, one or two CPUs), a PCI riser with one PIC, base I/O card | one | two NUMAlink |
| CPU expansion module | Altix 350 | 2U | one IP57 node, no usable PCI | one | two NUMAlink |
| CMPX module | Altix 350 | 2U | one IP57 node, a PCI riser with one PIC, four slots | one | two NUMAlink |

## C-brick (Altix 3300 and 3700)

All **established** from `007-4579-001`:

- 3U. Two SHubs, four Itanium 2 processors and four processor power pods sit on one half-panel board; the node
  electronics, the L1 controller and the power regulators are on a second half-panel board; four memory daughter cards
  carry the DIMMs (p.106). The user's guide names the node chip "Super-Bedrock" (p.87) and the driver guide "SHub", with
  16 DIMM slots per SHub (`007-4520-006` p.16).
- Rear panel (pp.105 to 106): two NODE LINK (NI) connectors, one per node, "Xtown2" connectors for a NUMAlink cable at
  1.6 GB/s each direction, to an R-brick or another C-brick; two NODE XIO (II) connectors, one per node, Xtown2 at
  1.2 GB/s, to an IX- or PX-brick; an RS-232 console port on the L1; a USB L1 port to the rack L2 for systems with no
  router; four heartbeat LED pairs (one pair per node); 32 processor status LEDs (eight per processor); a power
  connector with 12 V and 48 V LEDs and a power switch that powers only the L1.
- Front panel: three fans, the L1 LCD (two lines of 12 characters), on/off, reset and NMI switches (p.103).
- Product options: zero or four processors and 8, 16, 24 or 32 DIMMs in groups of eight (Figures 3-5 and 3-6, pp.88 to
  89). Memory is 512 MB DIMMs in those figures.

The two NI links join each node to the fabric; the two nodes are joined to each other inside the brick, which the
Bx2 guide describes as an internal NUMAlink channel and this guide as part of the board. Which internal path is used
for node-to-node traffic is **unknown**.

## CR-brick (Altix 3700 Bx2)

**Established** from `007-4377-002` (see also [altix-3700-bx2.md](altix-3700-bx2.md)): 4U; up to four nodes, each a SHub
with two processors and 4, 8 or 12 DIMMs, joined internally by NUMAlink; two NL4 router ASICs inside, each wired to four
of the eight rear "Dnet" connectors; two Xtown2 XIO ports from nodes 1 and 3; one L1 with a display; console, L1 USB and
three fans (pp.65 to 74).

**Inferred.** A full brick is a four-node system that needs no external router, because the two router ASICs are
inside it and the guide lists the R-brick as optional (p.97). The guide says the node electronics "are connected
internally to two NL4 router ASICs" (p.72) and gives no per-link table, so the router-to-node link map is **unknown**.

## R-brick

**Established** from `007-4579-001` pp.135 to 142 and `007-4377-002` pp.97 to 103: 2U; an eight-port crossbar router
ASIC that "connects any input-link channel to any of the seven possible output-link channels"; one L1 with a display
and an internal USB hub that carries the L2's USB traffic to the attached C-bricks' L1s; two hot-pluggable fans (Bx2 guide p.98). Rear connectors are
labelled 1 to 8 or A to H: ports 1, 6, 7 and 8 (A, F, G, H) are router-to-router; ports 2 to 5 (B to E) take C-bricks and
can also take router links in larger systems (3000 p.140). The 3000 guide describes the 3700 as needing four routers per 32
processors (p.79) and the Bx2 guide lists the R-brick as optional (chapter introduction, p.97).

**Inferred**: the 3000 R-brick uses the NUMAlink 3 router ASIC and the Bx2 R-brick the NL4 router, from the guides' own
generation names ("NUMA 3" in the 3000, "NUMAlink-4" in the Bx2) and the hwperf names `NL3Router` and `NL4Router`
(`v5.3:arch/ia64/include/asm/sn/sn2/sn_hwperf.h`). The R-brick pages do not name the ASIC generation. The Origin 3000
R-brick page ([../bricks/rbrick.md](../bricks/rbrick.md)) describes the same enclosure for the MIPS machines; this
router's register map is not held (README).

## IX-brick and PX-brick

**Established**, from `007-4579-001` pp.112 to 122 and 126 onward, `007-4377-002` pp.76 to 96, `007-4520-006` pp.18 to 20:

- 4U, 12 slots as six two-slot buses. Three PIC ASICs ("PIC (PCI interface chip)"; the driver guide calls them
  "PCI-X Host Bridge Adapters") support two 1200 or 800 MB/s Xtown2 XIO ports and the six buses; the XIO speed is set
  with the L1 command `XIO`. Two buses per PIC is **inferred** from three PICs and six buses; the block diagram shows it but its port labels (A to D, F) are not explained.
- IX-brick: one slot, the leftmost (bus 1 slot 1), is reserved for the IO9 base I/O card in the 3000 guide (a "base I/O
  PCI card" in the Bx2 guide) with IOC4 and IDE for the DVD-ROM, Ethernet, a SCSI controller and serial ports; two SCSI
  system disks and a DVD-ROM; two or four serial ports (two standard, two more on a daughtercard that takes a slot but
  no bus); XIO 10 and XIO 11 connectors, each able to join one C-brick, or both to two C-bricks for a dual-ported brick
  (3000 p.118). The driver guide draws the base I/O card with an IOC4 ATA bus to the DVD-ROM, an Ethernet chipset and
  a SCSI controller (`007-4520-006` p.19).
- PX-brick: the same minus the base I/O card, and it can connect an InfiniteReality pipe to a C-brick (3000 p.126, Bx2
  p.88). The chips-level PIC contract and the PCI wiring of the base I/O card are on
  [the IX-brick page](../bricks/ixbrick.md) and [the PX-brick page](../bricks/pxbrick.md), which cover the Origin 3000
  use of the same enclosures. That a PIC behaves the same under Altix is a hypothesis; the Linux provider (`pcibr`) treats
  it as the same chip (README).

## Power bay and rack

The 3U power bay holds up to six 48 V supplies (five in a compute rack, three in an I/O rack) with eight 48 V outputs
(`007-4579-001` pp.87, 89). The racks are the 17U deskside rack (3300) and the 40U rack (3700); one L2 serves a rack with
C-bricks (p.79). **Established.**

## The Altix 350 modules

All three modules are 2U with one **IP57** node board, and each has an interface board carrying the L1 logic, the
power-supply interface, the NUMAlink connectors and the connectors to the node board and, if present, the PCI riser
(`007-4660-002` pp.130, 140). **Established.**

| | Base compute | CPU expansion | CMPX |
|---|---|---|---|
| Node board | IP57, 12 DIMM slots, serial ID EEPROM | same | same (p.138) |
| Processors | one or two | one or two | one or two, optional |
| PCI riser with PIC | yes, four slots on two buses | none usable | yes, four 64-bit 3.3 V slots on two buses (p.140) |
| Base I/O card | IO10 (IO9 optional) | no | no |
| Disks and DVD | yes | no | no |
| Count in a system | one or more | 0 to 15 (p.124) | may chain to other CMPX modules (p.137) |
| NUMAlink ports | two | two | two |
| Rear labels | not read | NUMALINK 0, NUMALINK 1, CPU, IS1, IS2, REPEAT (Figure 4-6, p.133) | not read |

- The CPU expansion module connects to the base module "via a NUMAlink cable", and can chain to other expansion
  modules, base modules, CMPX modules and routers (pp.120, 124, 133). The CMPX module is the same: it joins base
  modules, expansion modules and other CMPX modules (p.137). Established.
- Its rear-panel Figure 4-6 prints labels "REPEAT", "IS1" and "IS2" next to the NUMAlink connectors; the text does not
  explain them. **Unknown.** They are likely LEDs or jumpers (guessed from position); no source says.
- The SHub block list is the same in every module: crossbar, processor interface, memory and directory interface, two
  network interfaces, one I/O interface and a local block (pp.130, 140). Established. See [the SHub page](../../devices/shub/README.md).
- Each module's L1 has a console DB-9, a USB type B port to an optional L2, a display, and one or two redundant power
  supplies (pp.124, 137). Established.

How the PROM tells these modules apart in its hardware list is not printed. See [brick-identity.md](brick-identity.md).

## The M-brick

A compute brick without processors named "M-brick" appears only in two Linux comments: "C-brick, M-bricks, and TIOs" in
`v5.3:arch/ia64/include/asm/sn/arch.h`, and "C/M bricks" in `build_cnode_tables` (`v5.3:arch/ia64/sn/kernel/setup.c`),
both meaning nodes that count toward the kernel's compact node limit. **Established** that the comments exist. No
`MODULE_*`, `KLTYPE_*` or `L1_BRICKTYPE_*` constant, and no manual in the Library, names an M-brick; a search of the
Linux history tree for `MODULE_MBRICK` and `M-brick` found only that comment. So an Altix 3000 M-brick, if it shipped, is
**unknown**; the 4700 "M2" blade is its documented successor, a memory-only SHub 2 compute blade
(`007-3938-005` p.51; [altix-4700.md](altix-4700.md)). The C-brick's option of "0 or 4 processors" in the 3000 guide
(Figures 3-5, 3-6) means a C-brick with no processors can exist, which is a memory-only node under a different name.
That reading is **inferred**.

## Open

See [../../questions/altix-brick-identity.md](../../questions/altix-brick-identity.md) for the type characters, the
EEPROM and the KLCONFIG contents.
