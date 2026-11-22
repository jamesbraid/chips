# Altix 350

The Altix 350 is SGI's entry IA-64 NUMA server: 2U modules that run one Linux image of up to sixteen Itanium 2
processors in a ring of eight modules (first guide) or up to 32 through routers (second guide). It is the smallest SN2 machine with a complete published guide, so it is the
best documented SN2 machine. This page covers the modules, what is on each, the chips, and the
console and interrupt paths. It holds no register facts.

Sources: SGI, *Important Note: SGI IO10 PCI Option for Altix 350*, `007-4374-001`. SGI, *SGI Altix 350 System User's Guide*, `007-4660-001` (2004, cited "-001") and `007-4660-002` (cited "-002"),
printed pages of each. SGI, *SGI L1 and L2 Controller Software User's Guide*, `007-3938-005` (April 2006), whose
revision log adds the Altix 350 at revision 003 (May 2004). Linux v5.3 as `v5.3:path`; the Linux history tree
(Linux history tree 981a2edd) for the IOC4 base driver, which v5.3 no longer has. Grades: see [the SN2 README](README.md).
A page number with no revision tag is a -001 page.

**-001 and -002 differ, and -002 is the later and fuller guide.** -001 describes only the ring of up to eight modules,
16 processors and the IO9 base I/O card, and calls the fabric "NUMAlink". -002 (pages 66 to 72 and 105 to 114 read)
says the standard base I/O card is the **IO10** and the IO9 is optional, names the interconnect "NUMAlink-4" and the
node chip "Super Hub (SHub)", adds one or two NUMAlink-4 routers ("R-bricks") that join eight to sixteen modules into up
to 32 processors and 64 PCI/PCI-X slots (-002 pp.66, 68, 69). The guide prints the memory limit as 192 GB (p.66) and 384 GB (p.68); see the Memory row below. The machine as first shipped (2004)
is described by -001; the later machine by -002.

## Modules

All three module types are 2U and carry the same IP57 node board (007-4660-001 pp.70, 100).

| Module | What it adds | Source |
|---|---|---|
| Base compute module | One or two Itanium 2 processors, up to 24 GB, four PCI/PCI-X slots, a base I/O card (IO9 in -001; IO10 standard and IO9 optional in -002), one or two disks, optional DVD-ROM, one or two 500 W supplies, an L1 controller | -001 pp.69, 96, 106; -002 pp.72, 112 |
| CPU expansion module | Processors and memory only: no usable PCI slots and no disks | p.70 |
| CMPX module | As the base module without the base I/O card and disks; four PCI/PCI-X slots, so more I/O than the expansion module | -001 pp.70, 111 |

All **established** (printed in the guide).

## Smallest configuration

One base compute module is a complete system: one processor, at least four DIMMs (the minimum memory in the guide's
range table is 2 GB; group 0 must always be filled), the factory base I/O card in the bottom slot (IO9 in the 2004 guide, IO10 or IO9 in the later one), one disk, one power
supply. No rack, no L2 controller and no expansion module is required (p.71 Table 2-1: compute rack "None", L2
controller "None" at minimum; -001 p.69: one base I/O card per system or partition; p.102: group 0 required). Established. The
guide says the module "can serve as a standalone Altix 350 system" (p.96).

| Item | Minimum | Maximum | Source |
|---|---|---|---|
| Modules | 1 | 8 in a ring (-001); 16 with routers (-002) | -001 p.71 Table 2-1; -002 p.69 |
| Processors | 1 | 16 (-001); 32 (-002) | -001 p.71; -002 pp.66, 69 |
| Memory | 2 GB | 96 GB, or 192 GB in the text (-001); 192 GB and 384 GB in the text (-002) | -001 p.71 and p.68 disagree with each other. -002 gives 192 GB at one place (p.66) and 384 GB at another (p.68). 24 GB per module times 16 modules is 384 GB. **Unknown** which limit is right; the module limit is 24 GB (-001 p.96) |
| PCI/PCI-X slots | 4, three free after the base I/O card | 32 (-001); 64 (-002) | -001 p.71; -002 p.66 |
| Processor clock | 1.0 GHz | 1.5 GHz | p.101 |

The modules side by side are in [bricks.md](bricks.md); their identity in the hardware map is in
[brick-identity.md](brick-identity.md).

## Node: IP57

Each module has one **IP57** node board holding the SHub, one or two Itanium 2 sockets (CPU A and CPU B), twelve DIMM
slots in three groups of four (DDR SDRAM, groups must match, group 0 always present), a serial ID EEPROM and two voltage
regulators (pp.100 to 103). Established. The board name is the only SGI identifier the guide prints for the node; the
same string names functions in the L1 firmware (`IP57_Init`, `IP57_Probe`, `IP57_Set_MemCfg` among others, in the ARM
Linux L1 packages: see sysco `software/firmware/l1/arm-ip57-configuration-control-1.40.5.md`), established there.

The Itanium 2 caches are one 32 KB level-1 data and one instruction cache, 256 KB level 2, and a level 3 of 1.5, 3 or
6 MB by clock speed (p.101 Table 3-1). The FSB peak is 6.4 GB/s and main memory up to 10.8 GB/s (p.112 Table 3-2).
Established.

The guide text on page 101 says the board protects "commands sent between the Bedrock ASIC and a processor". The
manual's own block list names no Bedrock; the sentence is carried over from an Origin guide, so it is **not** evidence
for a Bedrock on the 350.

## Chips

| Chip | Where | Grade and source |
|---|---|---|
| SHub | On the IP57 board. Blocks: crossbar (XN), processor interface (PI), memory and directory interface (MD), two network interfaces (NI), I/O interface (II), local block (LB) (-001 p.104; -002 p.112 and the "Super Hub" name in -002 p.68) | established as listed. Generation 1 or 2: **unknown** (README) |
| PIC | On the PCI riser card; two buses of two slots (-001 p.105, p.99 diagram; the -002 logic diagram p.107 is the same). It sits behind an "XIO" link from the SHub in the diagram. | established that a PIC is present and that the buses are two with two slots each (-001 pp.96, 109); the XIO link is drawn, not described |
| IOC4 on the IO9 | One IDE channel for the DVD-ROM, NVRAM and the time-of-day clock (-001 p.104; -002 p.114) | established |
| IOC4 on the IO10 | The Linux IOC4 base driver treats the IO10 as an IOC4 card: it lists three variants, IO9, IO10 and PCI-RT, "each brings out different combinations of IOC4 signals" (Linux history tree, drivers/misc/ioc4.c, function `ioc4_variant`, line 225) | established that an IOC4 is on the IO10; **unknown** which of its functions the IO10 uses: the guide says serial ports come out on the 36-pin MDR connector (-002 p.112) and says nothing about the IOC4 |
| SATA controller on the IO10 | A Vitesse VSC 7174 at PCI slot 3 on the IO10's bus, as the driver finds it (same `ioc4_variant`); a 2008 mailing-list post (list not recorded, not retrieved) says IO10 boards cannot boot without the Vitesse SATA driver | established from the driver; the guide says only "serial ATA" (-002 pp.112 to 113); the boot claim is unknown (not retrieved) |
| SCSI controller on the IO9 | A QLogic ISP 12160 at PCI slot 3 on the IO9's bus (same function) | established from the driver; the guide says Ultra160 SCSI (-001 p.99 diagram and p.197) |
| Ethernet on the IO9 and IO10 | One 10/100/1000 BaseT port | established as a port (-001 p.104; -002 p.72); the controller part is **unknown** (not named in either guide, not searched in the Linux sources yet) |
| NUMAlink | Two ports per module, 3.2 GB/s each direction (-001 pp.109, 112) | established. -002 calls it NUMAlink-4 (pp.66, 69), so for the later machine the router generation is known by name; -001 left it unnumbered |
| L1 controller | On the interface board with the power-supply interface and NUMAlink connectors (-001 p.105; -002 p.114) | established |

The base I/O cards have [their own page](altix-350-base-io.md): PCI devices, riser, console and interrupt route.

### IO10 against IO9 (established, -002 pp.72, 112 to 114)

| | IO10 (standard) | IO9 (optional) |
|---|---|---|
| Disks | serial ATA; no SCSI internal drives | SCSI; no SATA drives |
| DVD-ROM | served by the card ("connects to ... DVD-ROM drive") | IDE channel on the IOC4 |
| External | an Ethernet port and optional serial ports through a 36-pin MDR connector and a cable to four DB-9; the connector carries four full modem-control ports S0 to S3 (007-4374-001 p.2) | VHDCI 68-pin SCSI, Ethernet, RTI and RTO |
| NVRAM and time-of-day | not stated for the IO10 | IOC4 |
| RTI and RTO | not supported under Linux ProPack either way | same |

One card per module, in PCI slot 1. The guide lists an Ethernet port among the base I/O features for both cards
(-002 p.72). The IO10 cards' internals (which chips, which PCI device numbers) are not printed in either guide;
the three facts above about its chips come from the Linux driver and are the only silicon claims here.

PCI/PCI-X slot speeds: 33 and 66 MHz PCI, 66 and 100 MHz PCI-X, 64-bit, 3.3 V; mixed cards on a bus run at the slower
speed, PCI-X in PCI mode (pp.96, 105, 109). The base I/O card sits in bus 1 slot 1, the lowest slot (-001 p.104; -002 p.114). A PCI-X card
and a PCI card on one bus both run in PCI mode.

## Topology

**Ring (-001, -002).** Each module has two NUMAlink ports and connects to two neighbours; a message passes through
intermediate modules, and the ring has a second path if one link fails (-001 pp.69, 72). Bisection bandwidth falls from
3.2 GB/s at two modules to 800 MB/s at eight (-001 p.72 Table 2-2). The cabling lists which port joins which
module are in the cabling chapter (printed pp.46 to 48 of -001), not read for this page.

### Ring cabling

Source: 007-4660-002, Figures 2-5 to 2-11 (printed pp.75 to 80), read as the PDF's vector paths and checked by eye at
300 dpi. Every cable below is **established as drawn**: each figure joins every module port to exactly one other port.

`n.p` is module n, NUMAlink p. Figure 1-27 (p.48) labels the left rear connector "NUMALINK 0" and the right one
"NUMALINK 1", so p=0 is the left connector. The ring order is the schematic at the left of each figure.

| Modules | Figure (printed page) | Ring order (schematic) | Cables |
|---|---|---|---|
| 2 | 2-5 (p.75) | 1-2 | 1.0 to 2.0; 1.1 to 2.1 |
| 3 | 2-6 (p.75) | 1-2-3 | 1.0 to 3.1; 1.1 to 2.0; 2.1 to 3.0 |
| 4 | 2-7 (p.76) | 1-2-4-3 | 1.0 to 2.0; 1.1 to 3.1; 2.1 to 4.1; 3.0 to 4.0 |
| 5 | 2-8 (p.77) | 1-2-4-5-3 | 1.0 to 3.1; 1.1 to 2.0; 2.1 to 4.0; 3.0 to 5.1; 4.1 to 5.0 |
| 6 | 2-9 (p.78) | 1-2-4-6-5-3 | 1.0 to 3.1; 1.1 to 2.0; 2.1 to 4.0; 3.0 to 5.1; 4.1 to 6.0; 5.0 to 6.1 |
| 7 | 2-10 (p.79) | 1-2-4-6-7-5-3 | 1.0 to 3.1; 1.1 to 2.0; 2.1 to 4.0; 3.0 to 5.1; 4.1 to 6.0; 5.0 to 7.1; 6.1 to 7.0 |
| 8 | 2-11 (p.80) | 1-2-4-6-8-7-5-3 | 1.0 to 3.1; 1.1 to 2.0; 2.1 to 4.0; 3.0 to 5.1; 4.1 to 6.0; 5.0 to 7.1; 6.1 to 8.0; 7.0 to 8.1 |

Established from the printed text:

- Ring sizes 2 to 8 are all printed, one figure each, including 3, 5, 6 and 7.
- The figures print no port numbers and no numerals beside the ports. The small numbers are module numbers at each
  rear and box numbers in the schematic.
- Module 1 port 0 goes to module 2 at 2 and 4 modules, and to module 3 at 3 and at 5 to 8 modules. The pattern is not
  the same across sizes.
- The guide states no rule for the ring. It calls the figures "some examples" (p.74). No port rule and no rule for
  choosing a size is printed.
- Pages 46 to 48 print no ring port list. Page 46 gives one cable between two modules, "connect the NUMAlink cable to
  the NUMAlink connectors on both compute modules", with no port numbers. Page 47 (Figure 1-26) shows one base module
  and one expansion module with the L2, console and TP900 links, and no ring. Page 48 is the router intro and the power
  connector figure. The port list that the -001 text mentions (pp.46 to 48 of -001) was not read.

**Routers (-002 only).** Eight to sixteen modules use one or two NUMAlink-4 routers, the "R-brick" (-002 pp.48, 66,
69, 81, 149). Single plane is one router; dual plane is two. The guide prints cable tables for both: single plane in
Table 2-3 (pp.81 to 82) with Figure 2-12 (p.83), dual plane in Table 2-4 (p.84) with Figure 2-13 (p.85). Block diagrams
are Figures 2-3 (p.70) and 2-4 (p.71). Its cable tables cover only the 16-module layouts, so no layout is printed for
8 to 15 modules, and no rule chooses single or dual plane. Ring figures 2-5 to 2-11 (pp.75 to 80) cover two to eight
modules; -001 p.70 says the base module connects to seven more, "a total of eight modules".

The router has eight NUMAlink-4 connectors, A to H, which are ports 1 to 8 (Figure 6-2 p.151; Figure 6-3 p.153; Table
2-4 "From 1st router port 1(A)"). Each link runs at 3.2 GB/s each direction (Table 6-2 p.154). Established.
Dual plane is established from Table 2-4 (p.84) and Figures 2-4 (p.71) and 2-13 (p.85): each router connector goes to
port 1 (NUMAlink 1) of one module. The single-plane column is inferred from Table 2-3 and Figure 2-12, because the
prose on p.69 conflicts with them (below):

| Router connector (port) | Single plane (Table 2-3, inferred) | Dual plane, router 1 (Table 2-4) | Dual plane, router 2 (Table 2-4) |
|---|---|---|---|
| A (1) | module 5 | module 5 | module 1 |
| B (2) | module 6 | module 6 | module 2 |
| C (3) | module 7 | module 7 | module 3 |
| D (4) | module 8 | module 8 | module 4 |
| E (5) | module 9 | module 9 | module 13 |
| F (6) | module 10 | module 10 | module 14 |
| G (7) | module 11 | module 11 | module 15 |
| H (8) | module 12 | module 12 | module 16 |

The port 0 links (NUMAlink 0) are 1 with 5, 2 with 6, 3 with 7, 4 with 8, 9 with 13, 10 with 14, 11 with 15 and 12 with
16. Table 2-4 prints them (established); Table 2-3 prints the same pairs (inferred for single plane). Single plane leaves
port 1 of modules 1 to 4 and 13 to 16 unused (inferred: the tables and Figure 2-12 show no link there), so those modules
reach the single-plane router through one module-to-module link (inferred). Dual plane puts all 16 modules on a router.

**The single-plane conflict (open).** The prose on p.69 says "a single NUMAlink-4 connection is made to the port 0
connector on the back of (up to) eight Altix 350 modules. Additional modules (9 thru 16) are connected to the open
NUMAlink-4 port (port 1) on the modules already connected to the router." Table 2-3 (p.81) pairs connector (A) with
"module 5 NUMAlink 1" through connector (H) with "module 12 NUMAlink 1", and Table 2-3 (p.82) pairs modules 9 to 16 on
NUMAlink 0. Figure 2-12 (p.83) and Figure 2-3 (p.70) draw the table's wiring. The prose and the tables disagree on which
port the router uses and which modules it reaches. The tables, both figures and the dual-plane table agree with each
other, so this page uses the table reading (inferred). The prose stays unresolved. The dual-plane prose at p.69 matches
Table 2-4. Open item: [questions/numalink4-router-open.md](../../questions/numalink4-router-open.md).

-001 has no router: its ring text and configuration table name none, and it has no router chapter. No -003 or -004 was
located. Full cabling, port use and the PROM side:
[../../devices/router_nl4/global-config.md](../../devices/router_nl4/global-config.md).

**Router L1.** One L1 controller with a two-line display of 12 characters a line, a USB "L1 port" on the rear, and a DB-9
console (-002 pp.150, 152 to 154). Figure 6-2 (p.151) puts the L1 console and the L2 host USB on the system control
board. Table 6-2 gives one L1 port at 12 Mbit/s. Established. The guide gives no L1 address for the router. Page 56 describes
the L2 `cfg` listing as showing each module's "system controller addresses", but the guide prints no listing, so
whether the router appears in one is unknown. In a dual-plane system a
USB-to-Ethernet adapter on each router's USB port links it to an Ethernet switch (-002 p.86, Figure 2-14 p.87). The L1
and L2 guide 007-3938-005 addresses a brick by USB port, L1 index, then rack, type character and slot (pp.10, 49, 69).
Its type character `r` is the R-brick (Table 3-1, p.70), and its router command set (pp.108 to 109) is "valid only for
R-bricks and NUMAlink modules". That guide shows no Altix 350 router, so the router's L1 index and its entry in the L2
list are unknown.

## Console and controller path

- The base compute module has a DB-9 **console port**, a **USB type B L1 port** that joins its L1 to an optional L2
  controller, and an L1 front display (pp.96, 109). Without an L2, a console on the module's port reaches the L1 and
  boots the system (p.58). Established.
- The L1 and L2 command sets and addressing are in 007-3938-005; the guide uses L1 command targeting and a
  brick name such as `003c01` (007-3938-005 p.49). The Altix 350 L1 type character in the firmware is inferred to be
  the one for the 2U Itanium node (see sysco `sn2-brick-packages.md`).
- The guest console is a different path. Linux does not touch the L1's port: it asks the PROM through SAL console calls
  and gets a character stream, with an interrupt on vector 0xe9 (`v5.3:drivers/tty/serial/sn_console.c`;
  `v5.3:arch/ia64/include/asm/sn/sn_sal.h` lines 40 to 49). Established for the kernel; the 350 PROM that implements
  those calls is not held, so what the PROM does below the call is **unknown**.
- The base I/O (IDE or SATA, SCSI on the IO9, Ethernet, serial on the IO10) reaches the guest through the base I/O card on PIC, not through the L1.

## Interrupts

Established from Linux v5.3: PCI device interrupts come through the bridge provider and the shared vector space (0x3c to
0xe6) allocated by the PROM (`sn_intr_alloc` in `v5.3:arch/ia64/sn/kernel/irq.c`; the vector layout is in the
README). A PIC raises an error on 0x33 (`SGI_PCIASIC_ERROR`) and the SHub I/O interface on 0x31 (`SGI_II_ERROR`).
Which SHub interrupt register a given PIC pin lands in is not settled here.

## The smallest configuration

One base compute module is a complete system: an Itanium 2 CPU (one or two), one SHub node with local memory (4,
8 or 12 DIMMs) and the IP57 memory groups, a PIC with two PCI-X buses of two slots, a base I/O card in bus 1 slot 1 (for the 2004 machine an IO9: IOC4 with IDE and RTC, QLogic SCSI, Ethernet;
for the later machine an IO10: IOC4, Vitesse SATA, Ethernet), and firmware that provides at least the console and system-controller
calls. A single module has no router and uses no network ports. Its SHub generation is the first thing to settle.

## Unknowns

- SHub generation of the 350 (README).
- The memory limit (96, 192 or 384 GB) and the DIMM size options (-001 printed p.173 and the -002 equivalent, not read).
- The Ethernet controller on the IO9 and the IO10, and the chips behind the IO10's serial ports and DVD-ROM connection.
- The cabling chapter of -001 (the router chapter and cable tables of -002 are read, see Topology).
- The router or link chip, if any, between the two NUMAlink connectors and the SHub (the guide draws two NUMAlink
  blocks beside the SHub on -001 p.99 and -002 p.107 and says nothing about a router).
- The single-plane cabling conflict (Routers above) and the router's L1 index in an Altix 350 L2 list (Router L1 above).

## Review

Independent review, 2026-11-14, by a reviewer who did not write these pages. Reviewed chips revision 15a5a4e (pages as of 54d699c, db2c26d, 939a0d4; manual index 60a97bd).

Checks, against 007-4660-001 and -002 at the cited printed pages:
- IO10 standard, IO9 optional: -002 p.112 ("standard IO10 ... or the optional IO9"), p.113 (standard IO10 card), p.114 (optional IO9) confirmed. -001 p.104 says the IO9 "is required" at initial release and p.69 calls it factory-installed. The page's -001 and -002 split is right. IO10 disks serial ATA, no SCSI drives; IO9 no SATA (p.112) confirmed. 007-4374-001 pp.1 to 2: 36-pin MDR connector, four modem-control ports S0 to S3, Ethernet port, no SCSI disks, no chips named: confirmed.
- Memory: -001 p.71 Table 2-1 says 96 GB; -001 p.68 says "up to 192 GB"; -002 p.66 says 192 GB and p.68 says 384 GB. The page records exactly this conflict and marks the limit unknown. Per-module 24 GB (-001 pp.70, 96, 102) confirmed. Note: the introduction's "up to 384 GB" for -002 gives only one of the two printed figures; the Memory row is the accurate statement.
- NUMAlink: -001 never numbers it (pp.69, 109, 112 say "NUMAlink", 3.2 GB/s each direction per port, 6.4 GB/s full duplex); -002 pp.68, 69 say "NUMAlink-4" and "Super Hub (SHub)". Confirmed. -002 pp.66 to 69: routers join eight to sixteen modules, up to 32 processors, 64 slots, single-plane and dual-plane port wording confirmed.
- Table 2-1 (p.71) minimums and maximums (modules 8, processors 16, slots 32, compute rack and L2 "None"), ring and Table 2-2 (p.72), base module contents (pp.96, 99, 100 to 106), SHub block list (-001 p.104; -002 p.112), PCI riser with PIC ASIC (p.105), IOC-4 on the IO9 with IDE, NVRAM and time-of-day (p.104; -002 p.114), IP57 board with twelve DIMM slots in groups of four and group 0 required (pp.100, 102 to 103), caches (p.101 Table 3-1), bandwidths (p.112 Table 3-2): all confirmed.
- Chips on the IO10 and IO9: the only silicon claims beyond the guides are the IOC4 (all three card variants), the Vitesse VSC 7174 and the QLogic ISP 12160, all taken from the IOC4 driver's `ioc4_variant` and labelled as such; no other chip is claimed. The Ethernet controller is correctly `unknown`. The 2008 patch message cited for the IO10 SATA driver was not retrieved.
- "Bedrock" sentence on -001 p.101 is correctly treated as not evidence of a Bedrock.
- Linux v5.3: `sn_sal.h` lines 40 to 49 (console calls), `sn_console.c` ttySG0, `intr.h` vectors, `sn_intr_alloc` in `arch/ia64/sn/kernel/irq.c`: confirmed.

Findings:
1. Grade finding (not edited, owner to decide): the grading rule in the shared tooling's evidence order puts SGI's Linux platform code (`arch/ia64/sn/`, `arch/ia64/include/asm/sn/`) first. `drivers/misc/ioc4.c` is outside those trees, so facts taken only from it (an IOC4 on the IO10, the Vitesse VSC 7174 on the IO10, the QLogic ISP 12160 on the IO9) sit at the public-driver step and are `inferred` until IRIX or platform source confirms them, not `established`.
2. The "Interrupts" section's sentence about "a stream A and B question" was internal process wording and was removed (mechanical).
3. The module table row for the CPU expansion module cites p.70; the statement is also on -002 p.100. No correction needed.

Cleared scope: every manual-derived fact on this page (modules, limits, IP57, SHub block list, IO10 versus IO9, ring and router topology, console and L1 ports). Not cleared: the `established` grade on the IO10 and IO9 chip rows (finding 1) until relabelled or confirmed.

Findings addressed in 9995be1; renewed review needed for the changed claims.

### Renewed review

Renewed review of the changed claims only, 2026-11-14, by a reviewer who wrote none of them. Reviewed chips commit f5ab671 (contains 1d4f24f and 9995be1). Grading rule: sgi-retools `tools/README-analysis.md` "Evidence order" at c50bfeb. Checked against the printed pages in our holdings (SGI printed manuals); PDF page = printed page plus the offset noted per document. 

**Checked.** 007-4660-002 printed p.66 (PDF 94): "up to 192 GB of memory" with 32 processors, one or two routers and 64 slots; p.68 (PDF 96): the NUMAlink "create a single contiguous memory in the system of up to 384 GB". The introduction now gives both figures and points to the Memory row, which already marks the limit unknown. Right. (p.66 also mentions 17U and 39U racks; the page does not use them.)

**Findings.** None.

**Cleared:** the memory wording. The IOC4, VSC 7174 and ISP 12160 rows stay established under the rule, as recorded in the SN2 README's renewed review.
