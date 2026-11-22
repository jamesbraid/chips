# Altix 330

The Altix 330 is a 1U Itanium 2 server module that can run alone or be cabled to up to seven others. This page records
what the user's guide prints. It holds no register facts.

Sources: SGI, *SGI Altix 330 System User's Guide*, `007-4790-001` (2005), printed pages; Linux v5.3 as `v5.3:path`.
Grades: see [the SN2 README](README.md). Read: the contents, pp.47, 57 to 61, 69, 70, 75, 76, 78, 79 and 81. Not read:
p.80 (power supply) and the console note, `007-4805-001`. Printed page = PDF page minus 24.

## What is established (007-4790-001)

- One or two Itanium 2 processors, up to 16 GB on 4 or 8 DIMMs, one full-length 64-bit PCI/PCI-X slot (33 and 66 MHz
  PCI, 66, 100 and 133 MHz PCI-X), one or two SATA or SAS system disks, a slim DVD-ROM, one power supply, two Ethernet
  ports, two USB type A ports, an external SAS/SATA connector, one NUMAlink-4 port and one L1 USB port (p.70).
- Up to eight modules, 16 processors in one image, joined either module to module or through an optional NUMAlink-4
  router in a "single-plane" configuration (p.58, and the contents' "Optional Router Configurations", p.61).
- SHub blocks as on the 350: XN, PI, MD, two NI, II and LB (p.79).
- The guide names the interconnect "NUMAlink-4" (p.57); the first 350 guide (-001) does not number it, the second (-002) does.
- Node board: eight DIMM slots (p.75). Figure 3-4 (p.76) labels it "IP67 node board" and its node chip "SHub 1.2 ASIC".
  The text calls the chip "Super Hub (SHub)" (p.79) and gives no generation. SGI's `README.snprom` lists the 330 for
  `shub1snprom.bin`, the SHub 1 image: established as SGI's statement ([the SHub table](README.md#which-chip-where)).
- Memory: DIMMs of "double data rate synchronous dynamic random-access memory (DDR1 SDRAM)", four or eight per module, in
  groups of four, up to 16 GB (p.78).
- Base I/O is on the node board, not on a card: the base module has "factory-installed disk drive(s), base I/O, and
  memory" (p.70). Figure 3-4 (p.76) labels an LSI SAS/SATA controller, a Broadcom dual GigE, a NEC USB host controller, a
  Silicon Image PCI-to-IDE bridge for the DVD-ROM, a PIC, a 133 MHz PCI-X bus and 66 MHz and 33 MHz PCI buses. The picture
  matches these labels (checked 2026-11-21; the drawn label reads "Silcon Image"). The 133 MHz PCI-X bus (B0) carries the
  internal PCI-X slot and the LSI controller. The 66 MHz PCI bus (B1) carries the Broadcom and two PCI bridges. One bridge
  leads to a 33 MHz segment with the NEC USB host controller, the other to a 33 MHz segment with the Silicon Image bridge
  that feeds the DVD-ROM. The contents list no riser card and no add-in base I/O card.
- L2: "The Altix 330 system L1 operates in (emulated) L2 mode. Need for a separate optional hardware L2 system controller
  has been eliminated" (p.47).

## Differences from the 350

| Item | 330 | 350 |
|---|---|---|
| Enclosure | 1U | 2U |
| PCI slots | 1 | 4 |
| Disks | SATA or SAS | -001: SCSI through the IO9. -002: serial ATA through the standard IO10, SCSI only with the optional IO9 |
| Base I/O | two Ethernet, two USB, SAS/SATA connector on the module | -001: the IO9 PCI card. -002: the IO10 PCI card as standard, the IO9 optional |
| Node board | IP67 (Figure 3-4, p.76), eight DIMM slots (p.75) | IP57 (-001 contents) |
| Memory | DDR1 SDRAM, 4 or 8 DIMMs (p.78) | DDR SDRAM, 4, 8 or 12 DIMMs (-002 p.110) |
| PCI riser | none described | four PCI/PCI-X slots on a riser with a PIC ASIC (-001 p.105) |
| L2 controller | none; the L1 runs in emulated L2 mode (p.47) | up to one (-001 p.71, Table 2-1) |
| NUMAlink ports | 1 | 2 |
| Routerless topology | module to module (two) or router | ring |

The 350 column is from the two 350 guides (007-4660-001 and -002; see [the 350 page](altix-350.md)). The 330 guide does
not name an IO9, IO10 or IOC4. Its base I/O chips are read from Figure 3-4, checked against the picture; a PCI tree
from a 330 would add the PCI ids. Whether the 330's SHub, PIC and L1 firmware match the 350's is unknown;
the L1 packages that name an IP node board for it are not tied to the 330 (sysco `sn2-brick-packages.md`).

## Base I/O parts

Figure 3-4 (p.76, PDF page 100) is the only place the guide names the base I/O chips. It prints no part number and no
PCI ID for any of them. The vendor IDs below come from the public PCI ID list (`pci.ids`), matched by name.

| Name in Figure 3-4 | Where the figure puts it | Part number | PCI vendor:device | Grade |
|---|---|---|---|---|
| LSI SAS/SATA Controller | bus B0, 133 MHz PCI-X; the SAS/SATA II port and the internal disks | unknown without a capture | vendor 1000 (LSI Logic); device unknown | name and bus established; vendor inferred; part and device unknown |
| Broadcom Dual GigE | bus B1, 66 MHz PCI; the two GigE ports | unknown without a capture | vendor 14e4 (Broadcom); device unknown | name and bus established; vendor inferred; part and device unknown |
| NEC USB Host Controller | 33 MHz PCI behind a bridge on B1; the two USB 2.0 ports | unknown without a capture | vendor 1033 (NEC); device unknown | name and bus established; vendor inferred; part and device unknown |
| Silicon Image PCI to IDE | 33 MHz PCI behind the other bridge; feeds the DVD-ROM drive | unknown without a capture | vendor 1095 (Silicon Image); device unknown | name and bus established; vendor inferred; part and device unknown |

The drawn label on the Silicon Image chip reads "Silcon". No driver binding is stated: no Linux v5.3 tree is held
here, so the driver ID tables were not checked. The 350's IOC4, ISP 12160, VSC 7174 and klconfig Tigon 3 IDs are the
350's parts, not these, and do not transfer.

Searches that found no part number or capture for these chips:

- The full text of 007-4790-001 (pdftotext): the four labels, the chip families (LSI, SAS, Broadcom, BCM, NEC, uPD,
  Silicon Image, SiI, IDE) and "part number". The only part-number table is the service-tool list.
- Figure 3-4 rendered at 130 dpi: the same labels as the text layer, no numbers.
- Library search: LSI SAS1064/1068 with mptsas; BCM5704 with Altix; NEC uPD720100 with 1033; SiI 3112 with Altix; Altix 330
  with lspci, with ProPack release notes, and with base I/O. No 330 part or capture. The BCM5704 hits were an OpenBSD
  story and another project's BCM5701 note, neither about a 330.
- Held evidence: `sn2-holdings-inventory-20261114.md` and `sn2-bringup-material-20261114.md` name no 330 part. A text
  search of the evidence notes for "altix 330" matched notes, not captures; the other matches were not opened.

Open: a boot log or `lspci` from a 330 with these cards would settle the part and device IDs. Not yet independently
reviewed.

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

### Changes of 2026-11-21

Not reviewed. Changed claims: the sources line, the node-board, memory, base I/O and L2 bullets, and the comparison rows
for node board, memory, riser and L2. Renewed independent review is needed before these are cleared. The figure's bus
wiring was reviewed below; the other claims were checked in the review that follows.

### Review of the changes of 2026-11-21

Independent review, 2026-11-21, by a reviewer who wrote none of these pages. Reviewed chips revision 1c3917d. Read
007-4790-001 printed pp.47, 70, 75, 76, 78 and 79 from the held PDF (PDF index is printed page plus 24); the Altix 350
guides 007-4660-001 (offset 24) and -002 (offset 28) for the comparison column. Figure 3-4 was viewed as a picture
(PDF page 100, rendered at 130 and 300 dpi).

Confirmed against the picture: every label the base I/O bullet names. The 133 MHz PCI-X bus B0 runs to the internal
PCI-X slot and the LSI SAS/SATA controller; the 66 MHz PCI bus B1 runs to the Broadcom dual GigE and to two PCI bridges;
one bridge leads over a 33 MHz PCI line to the NEC USB host controller, the other over a 33 MHz line to the Silicon
Image PCI-to-IDE chip, which connects to the DVD-ROM drive. The label reads "Silcon Image". The figure also labels a
1200 MB/s link between the SHub's II block and the PIC and "NUMAlink 3/4" on the port; the page records neither.
Confirmed in the text: p.47 L2 quote, p.70 base I/O sentence, p.75 eight DIMM slots, p.78 DDR1 SDRAM and groups of four,
p.79 "Super Hub (SHub)" with no generation. The 350 column: IP57 in the -001 contents, DDR SDRAM on 4, 8 or 12 DIMMs
(-002 printed p.110), the riser with a PIC ASIC (-001 printed p.105), "L2 controller: None to 1" (-001 printed p.71).

Corrected: the "IP67" label is on the figure (p.76), not on p.75; a paragraph under the comparison table still said the
chips were read from the text layer only and the picture was unchecked.

Findings: none other. Cleared: the sources line, node-board, memory, base I/O and L2 bullets and the four comparison
rows.
