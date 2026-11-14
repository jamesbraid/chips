# Silicon Graphics Prism, deskside

The Prism is SGI's Linux visualization system on the Altix platform. This page records the deskside system only: the
single-enclosure form. The rackmount and scalable Prism guides (`007-4701`, `007-4774`) were read to their contents and
are not summarised here beyond the rack's "XG2N and compute modules" and NUMAlink cabling chapter titles. It holds no
register facts.

Sources: SGI, *Silicon Graphics Prism Deskside Visualization System Hardware User's Guide*, `007-4772-001`, printed
pages; SGI, *SGI L1 and L2 Controller Software User's Guide*, `007-3938-005` (adds the Prism at revision 004, July
2005). Grades: see [the SN2 README](README.md). Read: contents and pp.19 to 21, 25, 27.

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

## Chips

- Node chip: the guide says "scalable system node board" and no chip name in the pages read. Whether it is a SHub and which
  generation is unknown.
- The AGP slots imply an AGP bridge. In Linux the AGP bridge is the TIOCA (`v5.3:arch/ia64/include/asm/sn/tioca.h`),
  and the L1 firmware names a "TIO Test Card" type. Inferred, not stated by any held manual.

Not covered: the graphics boards and the rackmount
modules.

## Review

Independent review, 2026-11-14, by a reviewer who did not write these pages. Reviewed chips revision 15a5a4e (pages as of 54d699c, db2c26d, 939a0d4; manual index 60a97bd).

Checks against 007-4772-001 (printed pages): p.20 (four to twelve DIMMs, 2 to 24 GB, DDR SDRAM, groups of four), p.21 (group 0 required; DIMMs incompatible with the listed earlier machines; base I/O board with IDE, serial ATA, 36-pin MDR serial connector, RTI/RTO "not supported with Linux", Gigabit Ethernet, NVRAM and clock), p.23 (static I/O daughter card: USB A, L1 USB-B, L1 console DB9, IS IN and IS Repeat), p.25 (two internal disks, disk 1 holds Linux, DVD-ROM bay, graphics slots at centre-rear; the AGP-5 and AGP-6 labels are on the p.23 figure), p.27 (eight 64-bit PCI-X slots on four buses, up to 133 MHz, bus 1 holds the daughter board and base I/O board): all confirmed except as noted.

Findings:
1. The page cites the daughter-card connector list to p.27; the connector list is on p.23 and p.27 names the connectors only in one sentence ("USB, L1 USB, serial console, and Image Sync"). Add p.23 (not edited, harmless).
2. The guide is inconsistent about the base I/O slot: p.21 says "PCI slot 1, (the top PCI slot)" while p.27 puts the daughter board in the top slot (bus 1 slot 2) and the base I/O board in bus 1 slot 1. The page repeats "top slot (bus 1 slot 1)"; this is the guide's own wording conflict and should be noted when a model fixes slot order.
3. No chip claim: the TIOCA inference for AGP is correctly marked inferred.

Cleared scope: all board, slot and memory facts above. Not cleared: the slot-order wording (finding 2).

