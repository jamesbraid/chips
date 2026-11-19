# Altix 3000 (3300 and 3700)

The Altix 3000 family is the first IA-64 NUMA generation: C-bricks of two nodes, R-brick routers, IX- and PX-brick I/O
bricks and power bays, the 3700 in 40U racks (p.79). This page records what the 2003 guide prints about the machine; the I/O
bricks are on [the Origin 3000 brick pages](../bricks/ixbrick.md) because the same enclosures serve both families. It
holds no register facts.

Sources: SGI, *SGI Altix 3000 User's Guide*, `007-4579-001` (2003), printed pages; SGI, *Linux Device Driver
Programmer's Guide, Porting to SGI Altix Systems*, `007-4520-006` (July 2005); Linux v5.3. Grades: see [the SN2
README](README.md). Read: contents, pp.79 to 82 (models and architecture), pp.99 and 108 (C-brick). The 3300 model text
(p.77), the rack chapter and the rest of the brick chapters were not read.

## Established (007-4579-001)

- Two models: the **3300** and the **3700**. The 3700 has up to 512 Itanium 2 processors, at least one IX-brick per 64
  processors and at least four 8-port routers per 32 processors, in 40U racks with a power bay and PDU each (p.79).
- A coherent domain is up to 64 processors, and the whole system has one memory space of up to 2 TB (p.81).
- The **C-brick** is 3U and holds two processor nodes joined internally; each node has two processors and 16 DIMM slots
  on one custom ASIC (p.99). Processors in a C-brick must run at one frequency, and DIMMs are added in groups of eight
  (p.108). 48 VDC input, about 1125 W (p.108).
- The **R-brick** router is an 8-port crossbar, joined to C-bricks by "highly specialized cables" (p.81).
- Each rack with C-bricks has an L2 controller; rack 001 carries an L2 touch display (p.79).
- The SC-brick of the driver guide is the same brick: "two SHub chipsets", sixteen DIMM slots per SHub, one L1 and a
  console port, two NUMAlink channels and two Xtown2 (Crosstown) channels (007-4520-006 pp.16 to 17), with the node
  chip named SHub there and "Super-Bedrock" in the user's guide. Inferred that SC-brick and C-brick are one brick (same
  node count, DIMM slots and ports).

Brick contents are in [bricks.md](bricks.md); module ids and the hardware map in [brick-identity.md](brick-identity.md).

## Chips

| Chip | Grade and source |
|---|---|
| SHub, two per C-brick | established. Generation unknown (README) |
| PIC on the IX- and PX-brick | established: IX-brick is a PX-brick plus the base I/O card (IOC4, Ethernet chipset, SCSI), three host bridge adapters, six PCI-X buses (007-4520-006 pp.18 to 19). The Altix guide's figure labels the adapters "PCI-X Host Bridge Adapter"; the name PIC comes from the IX-brick and PX-brick addenda, which label them "PIC ASIC" (007-4604-001 p.4, 007-4605-001 p.3) |
| Router (8-port) | established as a part in the R-brick; its register map is not held |

## Open

- How the guide's "NUMAlink 4" for the C-brick's internal channel relates to the NUMAlink 3 cables of the R-brick
  (README).
- The 3300's layout (p.77, unread). It is a smaller 3000 with fewer bricks, inferred from the name; unread.
- The C-brick L1 type character: not settled (sysco `sn2-brick-packages.md`).

## Review

Independent review, 2026-11-14, by a reviewer who did not write these pages. Reviewed chips revision 15a5a4e (pages as of 54d699c, db2c26d, 939a0d4; manual index 60a97bd).

Checks against 007-4579-001: p.79 (3700: up to 512 processors, one IX-brick per 64, four 8-port routers per 32, 40U rack, L2 per rack with C-bricks, touch display on rack 001), p.81 (third-generation NUMAflex "NUMA 3", Super-Bedrock, 6.4-GB/s "NUMAlink 4" internal channel, 8-port router ASIC, up to 2 TB, 64 processors per coherent domain), p.99 (3U C-brick, two nodes, 16 DIMM slots each), p.108 (same frequency, DIMMs in groups of eight, 48 VDC about 1125 W): all confirmed. 007-4520-006 pp.16 to 19: SC-brick with two SHubs, sixteen DIMM slots per SHub, two 6.4-GB/s NUMAlink and two 2.4-GB/s Xtown2 channels, one L1, DB9 console; IX-brick IOC4 contents and the three-adapter figure: confirmed.

Findings:
1. The chips table says "three PIC host bridge adapters ... established". The driver guide's figure (p.19) says "PCI-X Host Bridge Adapter" and never PIC. The PIC identification is from the chips repository's IX-brick page; on this page it is `inferred` (not edited).
2. "Crosstown" is the page's gloss of "Xtown2"; the guide does not spell it. Labelled by the page as inferred in the SC-brick paragraph; acceptable.
3. The "17U or 40U racks" in the introduction was not found in the pages read (p.79 gives 40U only for the 3700); the 17U figure is unverified.

Cleared scope: the C-brick, R-brick, model-limit and SC-brick facts as cited. Not cleared: the PIC grade (finding 1) and the 17U rack figure.

Findings addressed in 9995be1; renewed review needed for the changed claims.

### Renewed review

Renewed review of the changed claims only, 2026-11-14, by a reviewer who wrote none of them. Reviewed chips commit f5ab671 (contains 1d4f24f and 9995be1). Grading rule: sgi-retools `tools/README-analysis.md` "Evidence order" at c50bfeb. Checked against the printed pages in our holdings (SGI printed manuals); PDF page = printed page plus the offset noted per document. 

**Checked.** 007-4579-001 printed p.79: the 3700 "requires a minimum of one 40U tall rack"; no 17U figure appears on the page, and the intro now says only "the 3700 in 40U racks (p.79)". The 3300's rack is not claimed. PIC row: 007-4604-001 p.4 and 007-4605-001 p.3 label "PIC ASIC"; the row now says the Altix guide's figure uses "PCI-X Host Bridge Adapter" and the name PIC comes from the addenda. Right.

**Findings.** None.

**Cleared:** the 17U removal and the PIC row. The first review's other cleared scope stands.
