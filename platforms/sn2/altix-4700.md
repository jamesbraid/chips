# Altix 4700 and Altix 450

Both machines are built from blades in an "individual rack unit" (IRU) with routers on a backplane, instead of bricks
joined by cables. The 4700 uses a 10U IRU, the 450 a 5U one. This page records what the guides print. It holds no
register facts.

Sources: SGI, *SGI Altix 4700 System User's Guide*, `007-4823-001` (March 2006), printed pages; SGI, *SGI Altix 450
System User's Guide*, `007-4857-001`; SGI, *SGI L1 and L2 Controller Software User's Guide*, `007-3938-005` (April 2006);
Linux v5.3. Grades: see [the SN2 README](README.md). Read: 4700 contents and pp.44 to 47, 53 to 55, 87, 116; 450
contents and pp.64, 66; the L1 guide's blade table. Revisions 002 and 003 of the 4700 guide and revisions 002 and 003
of the 450 guide were not read.

## Altix 4700

Established (007-4823-001):

- The IRU is 10U and holds up to ten single-wide blades, or two double-wide and eight single-wide, and **four
  routers**; each router has two ports brought out to external NUMAlink 4 connectors. A 42U rack holds up to four IRUs
  and a 2U space for an optional router. A rack has up to 64 processors; one image goes to 512, with at least one IA
  blade (base I/O) for every 512 cores (pp.44, 46, 53).
- A processor node is a SHub and one or two Itanium processors on a front-side bus; the SHub is a crossbar between the
  processors, memory and the network interface (p.47).
- Blades (p.53): compute/memory (two sockets, 4, 8 or 12 DIMMs), memory-only (4, 8 or 12 DIMMs), PCI-X expansion (three
  slots, double wide), PCIe expansion (two cards), PCIe plus PCI-X (two and two), and the **IA blade**, the double-wide
  base I/O blade with one or two disks, a DVD, two low-profile PCI slots, two Ethernet ports, one SAS/SATA II port and
  four USB ports.
- Rack power is 20.6 kW (p.116). PCI Express is described as "available as an option" and not necessarily at launch
  (p.53, p.87).
- There is no hardware L2: the L2 is an application that controls several L1s and talks to other L2s (007-3938-005
  p.3). L1 operation, L1 firmware upgrade and blade identification have 4700-specific sections (contents).
- The controller's blade types: C1 (one processor, "SHub 2.x based"), C2 (two processors, "SHub 2.x based"), M2 (memory
  only), IA (base I/O), I2E (PCIe or graphics expansion), I3X (three-slot PCI-X, hot-pluggable), I4E (four-slot
  double-height PCI-X, PCIe or graphics), RC (FPGA compute) (007-3938-005 pp.50 to 51; the table prints "14E", an
  evident misprint of I4E).

## Altix 450

Established (007-4857-001): the IRU is 5U and holds five blades with two internal routers; four IRUs go in a rack, up
to 76 cores per rack. The system is NUMAlink 4, a processor node is a SHub and one or two processors (pp.64, 66). The
contents list a "System Controller Network" and L1 and L2 power control (Chapter 2). Not read: the blade list, the
node details.

Not established for the 450: which SHub generation it uses (README) and whether the 450's blades are the 4700's (the
shared graphics option guide `007-4954-001` covers both, not read).

## Chips

| Chip | Grade and source |
|---|---|
| SHub generation 2 on the compute blades | established for the 4700 (007-3938-005 p.50) |
| NUMAlink 4 router ASIC, four per 4700 IRU, two per 450 IRU | established as a part; registers not held |
| TIO PCI-X and PCIe bridges on the expansion blades | inferred (README) |
| PIC, IOC4 on the IA blade | unknown: the guide lists connectors, not chips |

## Open

- The IA blade's chips and the way its SAS/SATA and Ethernet attach (guide prints connectors only).
- Whether the 4700 and 450 carry TIO nodes as separate NASIDs in the hardware map the kernel reads (Linux can show it;
  README).
