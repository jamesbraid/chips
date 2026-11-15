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
- Which blades carry a TIO. The kernel gives each TIO its own node number and NASID (established, [discovery](altix-4700-discovery.md#the-configuration-graph)); which blade holds one is unknown, see [the open questions](../../questions/altix-4700-open.md).

Further pages: [the IRU, blades and routers](altix-4700-iru.md), [how Linux discovers them](altix-4700-discovery.md), and [graphics attachment](graphics-attachment.md).

## Review

Independent review, 2026-11-14, by a reviewer who did not write these pages. Reviewed chips revision 15a5a4e (pages as of 54d699c, db2c26d, 939a0d4; manual index 60a97bd).

Checks against 007-4823-001: p.44 (10U IRU, ten single-wide or two double-wide plus eight single-wide blades, four routers each with two external NUMAlink 4 ports, 42U rack, 64 processors per rack, 512 maximum, one IA blade per 512 cores), p.46 and p.47 (fourth-generation NUMAflex, NUMAlink 4, SHub and one or two processors per node), p.53 (rack holds four IRUs plus a 2U router space; blade list including the IA blade; PCI Express "may not be immediately available"), p.87 (PCIe "will be available as an option"), p.116 (20.6 kW per rack): all confirmed. 007-4857-001 pp.64 and 66 (five blades, two internal routers, 5U, four IRUs in a rack, 76 cores, NUMAlink 4, Super-Hub with one or two processors): confirmed. "SHub 2.x based" for C1 and C2 and the blade list with the misprinted "14E" confirmed at 007-3938-005 pp.50 to 51; the claim covers the 4700 compute blades only and the page limits it that way. The L2-as-application statement (p.3 of the L1 guide) was not re-read.

Findings:
1. "Established" for SHub generation 2 rests on a controller guide, a published manual (fourth step), not on Linux platform code; that is a fair grade for a manual statement but the page should keep saying the generation is the 4700 blades' only.
2. The IA blade is "double-wide" on p.53 and "double-height" in the L1 guide (p.51); the page uses the first. Fine.

Cleared scope: the 4700 and 450 population, topology and blade facts as cited; the SHub 2 claim for the 4700 compute blades. Not cleared: anything about the 450's SHub generation (correctly left unknown).

Findings addressed in 9995be1; renewed review needed for the changed claims.

### Renewed review

Renewed review of the changed claims only, 2026-11-14, by a reviewer who wrote none of them. Reviewed chips commit f5ab671 (contains 1d4f24f and 9995be1). Grading rule: sgi-retools `tools/README-analysis.md` "Evidence order" at c50bfeb. Checked against the printed pages in the Library (`techpubs` root); PDF page = printed page plus the offset noted per document. 

**Checked.** No claim on this page changed in 9995be1; the page is untouched by the fixing commit. Nothing to renew.

**Findings.** None.

**Cleared:** nothing new; the first review's scope stands.
