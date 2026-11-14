# Silicon Graphics Prism, deskside

The Silicon Graphics Prism Deskside is the single-enclosure Prism: one node board in a tower with one or two AGP graphics
boards. The rackmount guides are on [Power and Team](prism-power-team.md) and [Extreme](prism-extreme.md); the product
line, graphics attachment, firmware and Linux side are on [the Prism overview](prism.md). The page holds no register facts.

Sources: SGI, *Silicon Graphics Prism Deskside Visualization System Hardware User's Guide*, `007-4772-001` (Apr 2005),
printed pages, and its second edition `007-4772-002` (Oct 2005, ProPack 4 Service Pack 2) for the diagnostics and XF86Config
chapter; SGI, *SGI L1 and L2 Controller Software User's Guide*, `007-3938-005` (adds the Prism at revision 004, July
2005). Grades: see [the SN2 README](README.md). Read: contents and pp.7 to 10, 17, 19 to 21, 25 to 27, 32, 33; -002 pp.120 to 122, 166.

## Established (007-4772-001)

- One scalable **system node board** holds one or two 64-bit Intel processors and memory: at least four DIMMs (2 GB),
  at most twelve (24 GB), DDR SDRAM in groups of four, group 0 required (pp.19 to 21). The same group structure as the
  [Altix 350](altix-350.md); the guide says these DIMMs do not fit the earlier SGI machines.
- A **base I/O board**, a full-length PCI card in bus 1 slot 1, provides IDE for the DVD-ROM, serial ATA
  for the disks, an external serial connector, real-time interrupt in and out (not supported under Linux), 10/100/1000
  Ethernet, and the NVRAM and time-of-day clock (p.21). The guide is inconsistent about the slot: p.21 calls it "PCI slot 1, (the top PCI slot)" while p.27 puts the daughter board in the top slot (bus 1 slot 2) and this card in bus 1 slot 1. Take bus 1 slot 1 from p.27; the p.21 wording is the guide's own conflict.
- A **static I/O daughter board** in bus 1 slot 2 carries USB, an L1 USB uplink, the serial console and the ImageSync
  ports (pp.23, 27; the connector list is on p.23; the rear view shows "L1 UPLINK", "CONSOLE", "IS IN" and "IS REPEAT", p.19).
- Eight 64-bit PCI-X slots on four buses; bus 1 has no free slot, buses 2 to 4 have two each, up to 133 MHz (p.27).
- Two AGP slots, AGP-5 and AGP-6, for the graphics boards at the centre rear (pp.19, 25).
- Two internal disks (disk 1 holds Linux), one DVD-ROM bay (p.25).
- Processors: "one or two 64-bit Intel processors" in different clock speeds and cache sizes; an upgrade replaces the whole
  node board (pp.17, 20, 32). The guide never says Itanium; the `-002` diagnostics example runs `ia64` Linux 2.4.21-sgi305a8
  (p.120), so Itanium 2 is inferred. No SHub is named; that is unknown, see [the open questions](../../questions/prism-open.md).
- The rear view (Figure 2-2, p.19) shows no NUMAlink connector; the node board "connects to the interface board via two
  connectors on its underside" (p.19). So the deskside is not cabled into a ring or router: established as the absence of any
  NUMAlink label or text in the pages read; whether the node board has NUMAlink ports that are not brought out is unknown.
- Graphics: "one or (optionally) two graphics boards (pipes)" at the centre rear (p.7, 25). The board has dual DVI-I
  connectors, DDR memory, full-scene anti-aliasing and AGP 4X/8X (p.26); the Linux side offers 8x only (see the overview). Some
  boards bring an Image Sync connection for optional Image Sync PCI cards (p.26), while the static I/O daughter card provides
  `IS IN` and `IS REPEAT` (p.19). The guide gives no board name; the XF86Config chapter of -002 lists the same sections (stereo,
  anti-aliasing, dual channel, genlock, multiple X servers) as the [Power and Team](prism-power-team.md) guide (-002 contents). Displays offered: a flat panel with DVI-D, or a CRT with a DVI-I to VGA
  cable (p.33). An optional compositor needs its cable on the left connector as seen from the rear (p.10).

## Chips

- Node chip: the guide says "scalable system node board" and no chip name in the pages read. Whether it is a SHub and which
  generation is unknown.
- The AGP slots imply an AGP bridge. In Linux the AGP bridge is the TIOCA (`v5.3:arch/ia64/include/asm/sn/tioca.h`),
  and the L1 firmware names a "TIO Test Card" type. Inferred, not stated by any held manual.

The Linux AGP bridge (TIOCA) for the two AGP slots, the part number `0xE020` and the 8x-only backend are on
[the overview](prism.md#graphics-attachment). Whether the deskside's four PCI-X buses sit behind one PIC (two buses) and a
second part, or something else, is unknown: the Altix 350 module has a PIC with two buses of two slots
([altix-350.md](altix-350.md)).

Not covered: the maintenance chapter (pp.35 to 89), the cooling and power sections, and the -002 regulatory chapters.

## Review

Independent review, 2026-11-14, by a reviewer who did not write these pages. Reviewed chips revision 15a5a4e (pages as of 54d699c, db2c26d, 939a0d4; manual index 60a97bd).

Checks against 007-4772-001 (printed pages): p.20 (four to twelve DIMMs, 2 to 24 GB, DDR SDRAM, groups of four), p.21 (group 0 required; DIMMs incompatible with the listed earlier machines; base I/O board with IDE, serial ATA, 36-pin MDR serial connector, RTI/RTO "not supported with Linux", Gigabit Ethernet, NVRAM and clock), p.23 (static I/O daughter card: USB A, L1 USB-B, L1 console DB9, IS IN and IS Repeat), p.25 (two internal disks, disk 1 holds Linux, DVD-ROM bay, graphics slots at centre-rear; the AGP-5 and AGP-6 labels are on the p.23 figure), p.27 (eight 64-bit PCI-X slots on four buses, up to 133 MHz, bus 1 holds the daughter board and base I/O board): all confirmed except as noted.

Findings:
1. The page cites the daughter-card connector list to p.27; the connector list is on p.23 and p.27 names the connectors only in one sentence ("USB, L1 USB, serial console, and Image Sync"). Add p.23 (not edited, harmless).
2. The guide is inconsistent about the base I/O slot: p.21 says "PCI slot 1, (the top PCI slot)" while p.27 puts the daughter board in the top slot (bus 1 slot 2) and the base I/O board in bus 1 slot 1. The page repeats "top slot (bus 1 slot 1)"; this is the guide's own wording conflict and should be noted when a model fixes slot order.
3. No chip claim: the TIOCA inference for AGP is correctly marked inferred.

Cleared scope: all board, slot and memory facts above. Not cleared: the slot-order wording (finding 2).

Findings addressed in 9995be1; renewed review needed for the changed claims.

### Renewed review

Renewed review of the changed claims only, 2026-11-14, by a reviewer who wrote none of them. Reviewed chips commit f5ab671 (contains 1d4f24f and 9995be1). Grading rule: sgi-retools `tools/README-analysis.md` "Evidence order" at c50bfeb. Checked against the printed pages in the Library (`techpubs` root); PDF page = printed page plus the offset noted per document. 

**Checked.** 007-4772-001 (PDF page = printed page + 22). p.21 (PDF 43): "installed in PCI slot 1, (the top PCI slot)". p.27 (PDF 49): "The system's base I/O board always occupies bus 1, slot 1, and the static I/O daughter board is permanently installed in the top slot (bus 1, slot 2)". The page records both and takes bus 1 slot 1; right. p.23 (PDF 45): the daughter-card connector list (four USB A, L1 diagnostic USB-B, L1 console DB9, IS IN and IS Repeat). The page now cites pp.23, 27. Right.

**Findings.** None.

**Cleared:** the slot conflict note and the connector citation.
