# Altix 3000 (3300 and 3700)

The Altix 3000 family is the first IA-64 NUMA generation: C-bricks of two nodes, R-brick routers, IX- and PX-brick I/O
bricks and power bays, the 3700 in 40U racks (p.79). This page records what the 2003 guide prints about the machine; the I/O
bricks are on [the Origin 3000 brick pages](../bricks/ixbrick.md) because the same enclosures serve both families. It
holds no register facts.

Sources: SGI, *SGI Altix 3000 User's Guide*, `007-4579-001` (2003), printed pages; SGI, *Linux Device Driver
Programmer's Guide, Porting to SGI Altix Systems*, `007-4520-006` (July 2005); Linux v5.3. Grades: see [the SN2
README](README.md). Cited pages of 007-4579-001: 33, 77, 79, 81, 87, 99, 101, 102, 107, 108, 135 and 140 (the R-brick chapter's
overview and rear panel). Cited pages of 007-4520-006: 13, 16 to 19. Page numbers are printed; the PDF index is 24
pages ahead for 007-4579-001 and 22 for 007-4520-006. The rack chapter and the rest of the brick chapters were not read.

## Established (007-4579-001)

- Two models: the **3300** and the **3700**. The 3700 has up to 512 Itanium 2 processors, at least one IX-brick per 64
  processors and at least four 8-port routers per 32 processors, in 40U racks with a power bay and PDU each (p.79).
- The **3300** has up to 12 Itanium 2 processors, one IX-brick, "no routers", one power bay and an optional L2 with no
  touch display, in a 17U rack that holds up to three C-bricks (p.77; the 17U rack is listed again on p.87).
- A coherent domain is up to 64 processors, and the whole system has one memory space of up to 2 TB (p.81).
- The **C-brick** is 3U and holds two processor nodes joined internally; each node has two processors and 16 DIMM slots
  on one custom ASIC (p.99). Processors in a C-brick must run at one frequency, and DIMMs are added in groups of eight
  (p.108). 48 VDC input, about 1125 W (p.108).
- The **R-brick** is a 2U, 8-port router brick (p.87), an 8-port crossbar. C-bricks join it by "highly specialized
  cables" (p.81).
- Each rack with C-bricks has an L2 controller; rack 001 carries an L2 touch display (p.79).
- The node chip is the **Super-Bedrock ASIC** (p.81; "two Super-Bedrock ASICs" on p.87). The driver guide calls the
  same role "SHub" ("two SHub chipsets", 007-4520-006 p.16).
- Memory: "commodity off-the-shelf memory DIMMs. The DIMM card is a JEDEC standard 184-pin card" (p.107). The driver
  guide's SC-brick figure labels its memory "DDR SDRAM memory" (007-4520-006 p.17, Figure 2-2). Neither guide names DDR2.
- The control cable is a "NUMAlink 3 cable": the L1 USB hub reaches four C-brick L1s over it (p.33, Table 2-1). That
  names the L1 control path, not the internal or external data channels.
- Inside the C-brick the two nodes are joined by one link (established). p.81 says "a single 6.4-GB/s NUMAlink 4
  channel"; Figure 5-2 (p.102, read from the picture) draws exactly one bar between the two node ASICs, labelled
  "6.4 GB/s"; the driver guide's Figure 2-2 (007-4520-006 p.17) draws one link between the two SHubs labelled "6.4 GB/s"
  and "Internal NUMAlink". p.101's "two internal 3.2-GB/s (each direction) NUMAlink channels (one per node)" is read as
  that same link counted from each node's port: 3.2 GB/s each way is 6.4 GB/s in total (inferred reading of p.101).
- Outside the C-brick: "two external 1.6-GB/s (each direction) NUMAlink channels (one per node)" and two Xtown2
  channels per node, 1.2 GB/s each direction (p.101). The guide does not name the external generation on the pages
  read. The driver guide's SC-brick has two "6.4-GB/s (each direction)" NUMAlink channels and two "2.4-GB/s" Xtown2
  channels (007-4520-006 p.17). That differs from p.101 and may be a product or revision difference; not settled.

Brick contents are in [bricks.md](bricks.md); module ids and the hardware map in [brick-identity.md](brick-identity.md).

## Chips

| Chip | Grade and source |
|---|---|
| Node chip, two per C-brick: "Super-Bedrock ASIC" (user guide) or SHub (driver guide) | role established by both guides; the one-part identity inferred. Generation: SHub 1 (see [SHub generation](#shub-generation)); the exact stepping is unknown |
| PIC on the IX- and PX-brick | established: IX-brick is a PX-brick plus the base I/O card (IOC4, Ethernet chipset, SCSI), three host bridge adapters, six PCI-X buses (007-4520-006 pp.18 to 19). The driver guide's Figure 2-3 (007-4520-006 p.19) labels the adapters "PCI-X Host Bridge Adapter"; the name PIC comes from the IX-brick and PX-brick addenda, which label them "PIC ASIC" (007-4604-001 p.4, 007-4605-001 p.3) |
| Router (8-port) | established as a part in the R-brick (p.81, p.87). The guide does not name its family, so neither the NUMAlink 3 nor the NUMAlink 4 register map is established for this brick |

## SHub generation

Verdict: the 3300 and 3700 C-brick use **SHub 1**, not SHub 2. The 3300 is an extension of the Altix 350 (SHub 1)
work, not of the SHub 2 stream. Checked 2026-11-21 against the snprom packages held in the chips root.

- **Established** (shipped package text): `README.snprom` in snprom 10.54 build 70399 says `shub1snprom.bin` supports
  the Altix 330, 350, 3300, 3700, 3700 Bx2 and both Prism models, and `shub2snprom.bin` supports the Altix 4700 and 450
  only. The 3300 and the 3700 are named for the SHub 1 image. This is the vendor's statement of which image to flash
  on an Altix 3000 series system ("flash -a shub1snprom.bin"), not a boot capture.
- **Established** (string in the SHub 2 image): `shub2snprom.bin` (10.54, SAL 1.54 for board `IP65`) carries
  "SHUB2 does not support XIO I/O." The C-brick reaches its IX- and PX-bricks over two NODE XIO (II) connectors
  (007-4579-001 pp.105 to 106, quoted above), so a SHub 2 C-brick would have no I/O path. This is the second,
  independent reason; it is inferred as a rule about the hardware, because the string is a PROM refusal and not a
  register fact.
- **Established**: the three first-generation Altix 3000 PROM builds held, `snprom.bin` 3.32 (build 30085, "SAL 3.32
  rel040406 IP41", 6 April 2004), 4.20 (build 40503, "rel050614 IP41") and 4.43 (build 44607, "rel051202 IP41"), name no
  SHub 2 board and no `IP65`; 4.20 and 4.43 also carry "SHUB 1.1 present" interrupt-targeting workarounds. All three
  predate the SHub 2 line: the Altix 3700 Bx2 guide is dated November 2004 and the Linux SHub 2 patch series
  1 December 2004 (see the README). The 2.4.21 ProPack 3 kernel map held has no SHub 2 symbol, and the 2.6.5 SN2 kernel
  map names `shub1_bte_error_handler` and no SHub 2 one (symbol lists, not source).
- **Inferred**: the SHub 1 images are named `snprom.bin` before 10.20 and `shub1snprom.bin` after (the README
  says the file "has been renamed"), so the first-generation Altix 3000 and every later SHub 1 machine share one image
  line. Reasoning: the README rename sentence and the identical `IP41` banner across 3.32 to 5.04.
- **Established**: the L1 firmware (`l1-1.62.1.bin`) has a brick-type name table with `C (IP35)`, `C (IP37)`,
  `C (IP41)`, `C (IP45)`, `C (Twister)`, `C (Vortix)`, `Opus`, `Gemini`, `Dorado`, `Opus TIO`, `Opus IP65` and `NL4R`
  (strings at file offsets `0x5908b` to `0x59173`). `Opus IP65` is the only name carrying the board of the SHub 2
  PROM. IP41 code in the L1 prints "SH%d NI0 always NL4 on IP41 brick" and handles several SHubs per brick.
  **Unknown**: which of `C (IP37)`, `C (IP41)` and `C (IP45)` is the 3000 C-brick; the L1 table does not name a
  product, and the PROM images know only `IP41`. The type table gives no SHub generation.
- **Unknown**: no register read from a 3300 or 3700 exists. The SHub 1 identity part word at `0x1_0000_0000` would
  settle the stepping (1.1 or 1.2), and the generation flag `SN_SAL_GET_SN_INFO` returns would confirm it. The Bx2
  is listed for the SHub 1 image by the same README, which conflicts with the README's inference that it is SHub 2;
  not settled here (see [the Bx2 page](altix-3700-bx2.md)).

SHub 2 board values, checked in `shub2snprom.bin` 10.54 (function at `0xff4824e0`, read in Ghidra): the board value is
stored at `0x5003_1240` of the node window, then compared; `0x7b` and `0x200` take the stacked-DIMM adjacency check
(fatal "4GB or larger stacked DIMMs cannot be installed in adjacent slots" error, node-dependent), `0xa00` and `0xe00`
return with no check, and anything else prints "UNABLE TO VERIFY DIMM CONFIGURATION: unknown board type". All four
are established as accepted values; the images name no product for them, so the mapping to a blade is unknown. This
finds `0xa00`, which the SHub 2 page lists as not located.

## Open

- Inferred: the Super-Bedrock ASIC and the SHub are one part, from the same role in both guides. Neither guide gives a
  chip generation; the firmware packages do (next section).
- Inferred: the driver guide's SC-brick is this brick (3U, two nodes, 16 DIMM slots per node).
- Inferred: 3.2 GB/s each way is the 6.4 GB/s total of p.81, so the two rates agree and only the channel count differs.
- The NUMAlink generation of the external cables. The guide prints their rate (p.101) and no name. Settling test: a
  page of the guide or its cabling guide that names the cable.
- Node chip clock: unknown. The pages read give none. The driver guide's "900 MHz" (007-4520-006 p.13) is the Itanium 2
  processor, not the chip.
- DDR or DDR2: the guides say DDR SDRAM (driver p.17) and a 184-pin JEDEC card (p.107). The 184-pin count is the DDR
  DIMM form factor; that reading is inferred from the pin count, not stated by either guide.
- Plan conflict, not settled here: a plan elsewhere treats the Altix 3000 external fabric as NUMAlink 3 ("same
  R-brick") and cites 007-4579-001 p.80, which this page did not read. The guide does not contradict that for the
  external fabric, because it names no generation for the external cable (p.101). It does name NUMAlink 4 for the
  internal channel (p.81). The plan's NUMAlink 3 claim needs its own source.
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

### Changes of 2026-11-20

Not reviewed. The 17U rack is restored: it is on p.77 and p.87, which the 2026-11-14 check did not read. Changed
claims: the 3300 bullet and its 17U figure, the node-chip naming and identity, the internal and external channel
rates and counts, the SC-brick rates against p.101, and the Router row. Renewed independent review is needed before
these are cleared.

### Review of the changes of 2026-11-20

Independent review, 2026-11-21, by a reviewer who wrote none of these pages. Reviewed chips revision fee9859. Read
007-4579-001 printed pp.77, 79, 81, 87, 99 and 101 from the held PDF (PDF index is printed page plus 24).

Confirmed: p.77 (3300: up to 12 processors, one IX-brick, "no routers", one power bay, 17U rack, optional L2 and no
touch display, up to three C-bricks in the model list); p.79 (3700 figures, L2 touch display on rack 001); p.81
(Super-Bedrock ASIC, "single 6.4-GB/s NUMAlink 4 channel", 8-port router ASIC, "highly specialized cables", 2 TB); p.87
(17U rack for the 3300, 2U 8-port R-brick, "two Super-Bedrock ASICs"); p.99 (two nodes, 16 DIMM slots each, one custom
ASIC); p.101 (two internal 3.2-GB/s channels, two external 1.6-GB/s channels, two 1.2-GB/s Xtown2 channels; the page does
not name NUMAlink 4). The one-versus-two channel conflict is real and recorded as open. The 3300 index row, the
snprom image paragraph and the references index row agree with the guide. Grades are right: the node-chip identity is
inferred, the NUMAlink 4 label is the guide's statement for the internal channel only.

Findings: none. Cleared: the 3300 bullet, node-chip naming, channel counts and rates, and the Router row.

### Changes of 2026-11-21

Not reviewed. Changed claims: the sources line, the memory and NUMAlink 3 cable bullets, the Figure 5-2 reading and the
channel, clock and DDR open items. Renewed independent review is needed before these are cleared.

