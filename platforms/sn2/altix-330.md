# Altix 330

The Altix 330 is a 1U Itanium 2 server module that can run alone or be cabled to up to seven others. This page records
what the user's guide prints. It holds no register facts.

Sources: SGI, *SGI Altix 330 System User's Guide*, `007-4790-001` (2005), printed pages; Linux v5.3 as `v5.3:path`.
Grades: see [the SN2 README](README.md). Only the contents, the architecture text (pp.57 to 58), the system features
(p.70) and the SHub description (p.79) were read. A console note, `007-4805-001`, was not.

## What is established (007-4790-001)

- One or two Itanium 2 processors, up to 16 GB on 4 or 8 DIMMs, one full-length 64-bit PCI/PCI-X slot (33 and 66 MHz
  PCI, 66, 100 and 133 MHz PCI-X), one or two SATA or SAS system disks, a slim DVD-ROM, one power supply, two Ethernet
  ports, two USB type A ports, an external SAS/SATA connector, one NUMAlink-4 port and one L1 USB port (p.70).
- Up to eight modules, 16 processors in one image, joined either module to module or through an optional NUMAlink-4
  router in a "single-plane" configuration (p.58, and the contents' "Optional Router Configurations", p.61).
- SHub blocks as on the 350: XN, PI, MD, two NI, II and LB (p.79).
- The guide names the interconnect "NUMAlink-4" (p.57); the 350 guide does not number it.

## Differences from the 350 that matter for a model

| Item | 330 | 350 |
|---|---|---|
| Enclosure | 1U | 2U |
| PCI slots | 1 | 4 |
| Disks | SATA or SAS | SCSI through the IO9 |
| Base I/O | two Ethernet, two USB, SAS/SATA connector on the module | the IO9 PCI card |
| NUMAlink ports | 1 | 2 |
| Routerless topology | module to module (two) or router | ring |

All established from the two guides. The 330 guide does not name an IO9 or IOC4; the base I/O chips of the 330 are
**unknown** (route: the 330 guide's internal-components pages, printed pp.75 to 80, read in full, or a PCI tree from a
330). Whether the 330's SHub, PIC and L1 firmware match the 350's is unknown; the L1 packages that name an IP node
board for it are not tied to the 330 (sysco `sn2-brick-packages.md`).
