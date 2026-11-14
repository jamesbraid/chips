# Altix 3000 (3300 and 3700)

The Altix 3000 family is the first IA-64 NUMA generation: C-bricks of two nodes, R-brick routers, IX- and PX-brick I/O
bricks, power bays, in 17U or 40U racks. This page records what the 2003 guide prints about the machine; the I/O
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

## Chips

| Chip | Grade and source |
|---|---|
| SHub, two per C-brick | established. Generation unknown (README) |
| PIC on the IX- and PX-brick | established: IX-brick is a PX-brick plus the base I/O card (IOC4, Ethernet chipset, SCSI), three PIC host bridge adapters, six PCI-X buses (007-4520-006 pp.18 to 19) |
| Router (8-port) | established as a part in the R-brick; its register map is not held |

## Open

- How the guide's "NUMAlink 4" for the C-brick's internal channel relates to the NUMAlink 3 cables of the R-brick
  (README).
- The 3300's layout (p.77, unread). It is a smaller 3000 with fewer bricks, inferred from the name; unread.
- The C-brick L1 type character: not settled (sysco `sn2-brick-packages.md`).
