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
- The guide names the interconnect "NUMAlink-4" (p.57); the first 350 guide (-001) does not number it, the second (-002) does.

## Differences from the 350

| Item | 330 | 350 |
|---|---|---|
| Enclosure | 1U | 2U |
| PCI slots | 1 | 4 |
| Disks | SATA or SAS | -001: SCSI through the IO9. -002: serial ATA through the standard IO10, SCSI only with the optional IO9 |
| Base I/O | two Ethernet, two USB, SAS/SATA connector on the module | -001: the IO9 PCI card. -002: the IO10 PCI card as standard, the IO9 optional |
| NUMAlink ports | 1 | 2 |
| Routerless topology | module to module (two) or router | ring |

All established from the 330 guide and the two 350 guides (007-4660-001 and -002; see [the 350 page](altix-350.md)). The 330 guide does not name an IO9 or IOC4; the base I/O chips of the 330 are
**unknown** (route: the 330 guide's internal-components pages, printed pp.75 to 80, read in full, or a PCI tree from a
330). Whether the 330's SHub, PIC and L1 firmware match the 350's is unknown; the L1 packages that name an IP node
board for it are not tied to the 330 (sysco `sn2-brick-packages.md`).

## Review

Independent review, 2026-11-14, by a reviewer who did not write these pages. Reviewed chips revision 15a5a4e (pages as of 54d699c, db2c26d, 939a0d4; manual index 60a97bd).

Checks against 007-4790-001 (printed pages): p.57 (NUMAlink-4, Super Hub, up to 16 processors in one image), p.58 (module-to-module or single-plane router, up to eight modules, 16 processors), p.70 (one or two processors, up to 16 GB on 4 or 8 DIMMs, one PCI/PCI-X slot with 33/66 PCI and 66/100/133 PCI-X, one or two SATA or SAS disks, slim DVD-ROM, one power supply, one NUMAlink-4 port, one USB L1 port, two Ethernet, two USB type A, external SAS/SATA), p.79 (SHub blocks identical to the 350): all confirmed. The contents entry at p.61 was not opened. The 2005 date and contributor page confirmed.

Findings:
1. The comparison table's 350 column uses only the first 350 guide (SCSI through the IO9). The second guide (-002) makes the IO10 (serial ATA) the standard base I/O card, so the "Disks" and "Base I/O" rows are right only for the 2004 machine; the closing line "All established from the two guides" should say that. Not edited (a content change).
2. The statement that the 350 guide does not number NUMAlink was true only of -001; fixed (mechanical).
3. "Up to seven others" in the introduction follows from eight modules (p.70) but with one NUMAlink port beyond two modules needs the router (p.58); the Established list says so.

Cleared scope: the 330 facts in "What is established" and the NUMAlink wording. Not cleared: the 350 comparison column for the later machine (finding 1).

Findings addressed in 9995be1; renewed review needed for the changed claims.

### Renewed review

Renewed review of the changed claims only, 2026-11-14, by a reviewer who wrote none of them. Reviewed chips commit f5ab671 (contains 1d4f24f and 9995be1). Grading rule: sgi-retools `tools/README-analysis.md` "Evidence order" at c50bfeb. Checked against the printed pages in our holdings (SGI printed manuals); PDF page = printed page plus the offset noted per document. 

**Checked.** The comparison rows now split the 350 column by guide. 007-4660-002 printed p.112 (PDF page 140): the Altix 350 "is available with either the standard IO10 base I/O card or the optional IO9"; IO10 modules "do not support SCSI internal hard drives" and IO9 cards "do not support SATA drives". The -001 half (IO9, SCSI) was cleared in the first review (-001 p.104). The closing sentence now names the 330 guide and both 350 guides.

**Findings.** None.

**Cleared:** the 350 comparison rows for both revisions.
