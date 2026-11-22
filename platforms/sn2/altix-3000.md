# Altix 3000 (3300 and 3700)

The Altix 3000 family is the first IA-64 NUMA generation: C-bricks of two nodes, R-brick routers, IX- and PX-brick I/O
bricks and power bays, the 3700 in 40U racks (p.79). This page records what the 2003 guide prints about the machine; the I/O
bricks are on [the Origin 3000 brick pages](../bricks/ixbrick.md) because the same enclosures serve both families. It
holds no register facts.

Sources: SGI, *SGI Altix 3000 User's Guide*, `007-4579-001` (2003), printed pages; SGI, *Linux Device Driver
Programmer's Guide, Porting to SGI Altix Systems*, `007-4520-006` (July 2005); Linux v5.3. Grades: see [the SN2
README](README.md). Cited pages of 007-4579-001: 33, 77, 79, 81, 87, 99, 101, 102, 105, 107, 108, 112 to 121, 123, 135 and 140
(the R-brick chapter's overview and rear panel; the IX-brick chapter in the wiring section). Cited pages of 007-4520-006: 13,
16 to 19, 38, 52, 54 and 55. Cited pages of the IX addendum 007-4604-001: 2, 4 and 10. Cited page of the PX addendum
007-4605-001: 3. Page numbers are printed; the PDF index is 24 pages ahead for 007-4579-001 and 22 for 007-4520-006. The
addenda's printed and PDF numbers agree.
The rack chapter, the PX-brick chapter and the other brick chapters were not read.

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

## IX-brick wiring

Read 2026-11-21 from the IX-brick chapter of 007-4579-001 (printed pp.112 to 121), the IX addendum 007-4604-001 (pp.2, 4,
10) and the driver guide (007-4520-006 pp.18, 19, 38, 52, 54, 55). Only Figure 6-2 (p.113) was checked on a page image,
an existing 2026-10-26 render kept in the evidence store; the Figure 6-3, 6-6 and driver figures were checked on their text
layer only, so their box shapes and connector placement are not confirmed. The same PIC drawing appears in the PX
addendum (007-4605-001 p.3). These are Altix 3000 IX-bricks; the Origin 3000 IX chapter is not used.

- **Three PICs (established).** "Three PIC (PCI interface chip) ASICs are key components of the IX-brick architecture"
  (007-4579-001 p.113; 007-4604-001 p.2). Each PIC drives two PCI-X buses.
- **The middle PIC faces the C-brick (established as drawn).** It is widget 15 and drives buses 3 and 4. Its Port A and
  Port B go to the two "Crosstown2 XIO port" boxes (007-4579-001 Figure 6-2, p.113; 007-4604-001 Figure 2, p.4). Driver
  Figure 5-1 (p.52) puts "Widget 15" in the middle of the rear panel.
- **The other two PICs hang off the middle one (established as drawn).** Middle Port D joins top PIC Port D (widget 13,
  buses 5 and 6). Middle Port C joins bottom PIC Port D (widget 12, buses 1 and 2). Both links are double-headed.
- **Port F (drawing established; meaning inferred).** Each PIC has one Port F, and the drawing gives it one line to each of
  its two buses, each bus feeding its two slots. Port F is therefore the PCI-X side that carries both of a PIC's buses
  (inferred from the drawing and driver p.55, which says each host bridge adapter has two PCI-X buses). The letter F is
  not defined in any held text.
- **XIO 10 is Node 0, Port A (established as drawn).** Driver Figure 5-1 (p.52) links the C-brick's "NODE 0 XIO (II)" to
  "XIO link to Port 'A'", with "XIO 10" over "XIO 'A'". Node 0 is slab 0 (driver p.54 and p.55 example). Figure 5-1 is
  drawn on the PX-brick back panel; the IX and PX addenda show the same PIC ports (IX Figure 2, p.4; PX Figure 2, p.3), so
  the IX reading carries it across (inferred). The rear placement of XIO 10 (007-4579-001 Figure 6-6, p.120) is not
  checked: the text layer gives the label only.
- **XIO 11 is Node 1, Port B (established as drawn).** Same figure: "NODE 1 XIO (II)" to "XIO link to Port 'B'", with "XIO 11"
  over "XIO 'B'". The same caveats apply, and its rear placement (Figure 6-6) is not checked.
- **Which crosstown box is XIO 10 (inferred).** The drawing puts the upper box on Port A and the lower on Port B. The
  label match then makes the upper box XIO 10. No held text names the boxes.
- **Rear position is not wiring.** Connector placement shows where the cable enters, not which PIC it reaches. The
  drawings above are the only held source for the PIC each connector reaches.
- **Widget numbers (established as drawn).** The three PICs are host bridge adapters 12, 13 and 15, "stamped at the back"
  of the brick (007-4520-006 p.54). Figure 3-1 (p.38) and Figure 5-1 (p.52) place widget 12 on buses 1 and 2, widget 15 on
  buses 3 and 4, and widget 13 on buses 5 and 6; the hwgraph listing (p.54) gives the same pairs for 12 and 15. The IO9
  base I/O card is behind widget 12, not 15.

| PIC (widget) | Bus | Slots | Speed | Contents |
|---|---|---|---|---|
| Bottom (12) | 1 | Slot 1: IO9 base I/O card. Slot 2: serial daughtercard slot (007-4604-001 p.2), no bus connection | 66 MHz PCI (the IO9 is a 66 MHz PCI card, 007-4520-006 p.38) | IO9: IOC4, Ethernet, SCSI, DVD-ROM |
| Bottom (12) | 2 | Slots 1 and 2 | 133 MHz with one card; 100 MHz with two | Cards |
| Middle (15) | 3 | Slots 1 and 2 | 133 MHz with one card; 100 MHz with two | Cards |
| Middle (15) | 4 | Slots 1 and 2 | 133 MHz with one card; 100 MHz with two | Cards |
| Top (13) | 5 | Slots 1 and 2 | 133 MHz with one card; 100 MHz with two | Cards |
| Top (13) | 6 | Slots 1 and 2 | 133 MHz with one card; 100 MHz with two | Slot 2: four-port USB card (preinstalled on Onyx 3000; optional on Origin 3000, 007-4604-001 p.2) |

The 133 MHz figures are each bus's ceiling, reached only with one card on the bus (driver Note 2, p.38). Two 133 MHz
PCI-X cards on one bus run at 100 MHz, and a bus runs at the speed of its slowest card (007-4579-001 p.121), so the table
gives a ceiling, not a measured speed.

- **Base I/O on bus 1, slot 1 (established as drawn, driver Figure 2-3 p.19).** The card is a set of three PCI functions:
  IOC4 (labelled "Bus 1 Slot 1"), an Ethernet chipset (Broadcom BCM5701 in 007-4579-001 Figure 6-3, p.115; labelled
  "Bus 1 Slot 3" in Figure 2-3) and a SCSI controller (QLogic in Figure 6-3; labelled "Bus 1 Slot 4" in Figure 2-3).
  Reading those labels as PCI device numbers 1, 3 and 4 is inferred, and it conflicts with the other readings of the
  same card. The Origin 350 IO9 capture puts the ISP 12160 (SCSI) at device 3 and the BCM5701 (Ethernet) at device 4
  when its logical numbers are read with the one-device offset ([the Origin 350 IO9 page](io9-board.md#pci-position)).
  The Altix NG-HINV listing puts the QLogic at `pci01.03.0` and the BCM5701 at `pci01.04.0`
  ([the IX-brick page](../bricks/ixbrick.md)). Both put SCSI at 3 and Ethernet at 4, the reverse of Figure 2-3. Neither
  reading is chosen; a PCI listing from an IX-brick would settle it. The IOC4 carries the RS-232 ports, PS/2 keyboard
  and mouse, the real-time jacks, NVRAM and the real-time clock, and an ATA bus to the DVD-ROM (driver p.18; Figure 6-3
  p.115). Figure 6-3 also
  shows an "FPGA ASIC" between the IOC4 and the IDE interface; its role is not stated.
- **Not settled.** The reason for the letter F; whether the XIO 10 cable reaches Port A by the upper box as drawn (a
  capture from an IX-brick with one C-brick cabled to XIO 11 alone would settle the hardware graph side); the FPGA's role;
  and the chip part numbers inside the IO9 (see [the IX-brick page](../bricks/ixbrick.md)).

## Multi-C-brick cabling

Sources: 007-4579-001 printed pp.77 to 101 (text layer), with pp.105, 106 and 108 for the connectors and the C-brick
restrictions; 007-4520-006 printed pp.13, 17, 38, 52 and 54. The figures were not rendered: the Library serves the PDFs
only through an authenticated viewer. So no cable line in any figure was read from a picture. **Established** means
printed in the text; **unknown** means not printed in the pages read.

**Counts (established).**

- The 3300 has up to 12 processors, one IX-brick, "no routers" and up to three C-bricks in a 17U rack (p.77; Figure 3-5,
  p.88, "1 to 3 per system").
- The 3700 needs a minimum of one IX-brick per 64 processors and four 8-port routers per 32 processors (p.79).
- The Figure 3-3 example (p.80, 32 processors) has eight C-brick labels, four R-brick labels and one IX-brick. These are
  label counts from the text layer; the cables are not read.

**Joining C-bricks.**

- Each C-brick has one LINK (NI) connector per node: "Node 0 LINK (NI)" and "Node 1 LINK (NI)" (Figure 5-4, p.106).
  They "connect the C-brick to an R-brick or to another C-brick" by NUMAlink cable at 1.6 GB/s each direction (p.105).
- A 3300 has no routers (p.77), so two or three C-bricks in one are joined only through these connectors. (inferred
  from p.77 and p.105)
- C-bricks in one system may run at different processor speeds (p.108). Processors inside one C-brick must match.
- Two C-bricks: which node joins which, and how many cables: **unknown** (not printed).
- Three C-bricks: **unknown** (not printed). Figure 3-2 (p.78) draws one 3300 example with three C-bricks and an IX-brick,
  but its cable lines are not in the text layer.
- Four or six C-bricks: **unknown** (not printed). Neither the 3300 limit nor the 3700 example gives either count.

**Attaching the IX-brick.**

- A C-brick's Node 0 and Node 1 XIO (II) connectors "connect a C-brick to an I/O-brick (IX-brick or PX-brick)" by NUMAlink
  cable at 1.2 GB/s each direction (p.105).
- The IX-brick has two I/O ports, labelled XIO 10 and XIO 11 (Figure 3-5, p.88). The PX-brick has the same two labels
  (Figure 3-6, p.89). Its other connections are PCI slots.
- The driver guide's one drawing (007-4520-006 p.52, Figure 5-1) shows one C-brick, module 001c27 (p.54), with Node 0 XIO
  to "XIO link to Port 'A'" and Node 1 XIO to "XIO link to Port 'B'". It gives no count for two or three C-bricks.
- Which C-brick the XIO 10 and XIO 11 cables reach when there is more than one C-brick: **unknown** (not printed). The
  node-to-port wiring for one C-brick is in [the IX-brick wiring section](#ix-brick-wiring).

**Driver guide.**

- The SC-brick has two nodes, each with one NUMAlink and one Xtown2 link (Figure 2-2, p.17). The rates there are 6.4 GB/s
  and 2.4 GB/s; the user guide gives 1.6 GB/s and 1.2 GB/s for the same connectors (p.105). That conflict is the open
  item above.
- The driver guide says the system scales to 512 processors "in a cache-coherent domain" (p.13). The user guide gives 64
  processors per coherent domain (p.81). Not settled.
- A PX-brick's two 1200 MB/s Xtown2 ports "connect SC-bricks" (p.38). The count of SC-bricks per port is not printed.

**Not printed.** Two-, three-, four- and six-C-brick layouts; the node pairs and cable counts for each; the C-brick that
each XIO cable reaches in a multi-C-brick system; the cable lines of Figures 3-2 and 3-3; and the NUMAlink generation
of the LINK cables (p.105 says only "NUMAlink cable"; p.81 names NUMAlink 4 for the internal channel only). A rendered
Figure 3-2 or 3-3, or a cabling guide for the 3300, would settle the layouts.

## SHub generation

Verdict: the 3300 and 3700 C-brick use **SHub 1**, not SHub 2. The 3300 is an extension of the Altix 350 (SHub 1)
work, not of the SHub 2 stream. Checked 2026-11-21 against the snprom packages held in the chips root. Grades: that
SGI assigns these machines to the `shub1snprom.bin` image is established; that the image name means the chip generation
is inferred, since the README names images, not chips.

- **Established** (shipped package text): `README.snprom` in snprom 10.54 build 70399 says `shub1snprom.bin` supports
  the Altix 330, 350, 3300, 3700, 3700 Bx2 and both Prism models, and `shub2snprom.bin` supports the Altix 4700 and 450
  only. The 3300 and the 3700 are named for the SHub 1 image. This is the vendor's statement of which image to flash
  on an Altix 3000 series system ("flash -a shub1snprom.bin"), not a boot capture.
- **Established** (string in the SHub 2 image): `shub2snprom.bin` (10.54, SAL 1.54 for board `IP65`) carries
  "SHUB2 does not support XIO I/O." The C-brick reaches its IX- and PX-bricks over two NODE XIO (II) connectors
  (007-4579-001 pp.105 to 106: they "connect a C-brick to an I/O-brick (IX-brick or PX-brick)"), so a SHub 2 C-brick would have no I/O path. This is the second,
  independent reason; it is inferred as a rule about the hardware, because the string is a PROM refusal and not a
  register fact.
- **Established**: the three first-generation Altix 3000 PROM builds held, `snprom.bin` 3.32 (build 30085, "SAL 3.32
  rel040406 IP41", 6 April 2004), 4.20 (build 40503, "rel050614 IP41") and 4.43 (build 44607, "rel051202 IP41"), name no
  SHub 2 board and no `IP65`; 4.20 and 4.43 also carry "SHUB 1.1 present" interrupt-targeting workarounds.
  **Inferred**: that they predate the SHub 2 line, from dates alone (the Altix 3700 Bx2 guide is dated November 2004
  and the Linux SHub 2 patch series 1 December 2004, see the README). Not a clean test: the 3.32 and 4.43 embedded
  build command lines already define `HWREGS_SHUB_II`, `CONFIG_TIO` and `CONFIG_NL4R`, and the 4.43 and 10.54 SHub 1
  images carry `TIO_` strings, so SHub 2 and TIO register headers were in the source tree for the SHub 1 image
  line. The 2.4.21 ProPack 3 kernel map held has no SHub 2 symbol, and the 2.6.5 SN2 kernel
  map names `shub1_bte_error_handler` and no SHub 2 one (symbol lists, not source).
- **Inferred**: the SHub 1 images are named `snprom.bin` before 10.20 and `shub1snprom.bin` after (the README
  says the file "has been renamed"), so the first-generation Altix 3000 and every later SHub 1 machine share one image
  line. Reasoning: the README rename sentence and the identical `IP41` banner across 3.32 to 5.04.
- **Established**: the L1 firmware (`l1-1.62.1.bin`) has a brick-type name table with `C (IP35)`, `C (IP37)`,
  `C (IP41)`, `C (IP45)`, `C (Twister)`, `C (Vortix)`, `Opus`, `Gemini`, `Dorado`, `Opus TIO`, `Opus IP65` and `NL4R`
  (strings at file offsets `0x5908b` to `0x59173`). `Opus IP65` is the only name carrying the board of the SHub 2
  PROM. IP41 code in the L1 prints "SH%d NI0 always NL4 on IP41 brick" and handles several SHubs per brick.
  **Established** (L1 1.62.1 `2MB image`, read in sysco `software/firmware/l1/sn2-l1-1.62.1-packages.md`; the identity
  routine at image `0xffe7b404`, the name tables at `0xffe7ff50` and `0xffe80220`): an `IP41` product name in record `0xfe`
  gives type `5` (0x35): established for the L1 and PROM logic, inferred that a real Altix 3000 C-brick's record holds `IP41`
  (support: the PROM's built-in default string, the banner, and `5` being the only candidate in the supported-brick string).
  The 3000 C-brick is therefore `C (IP41)`. The L1 takes it from the product name of its board record `0xfe` (prefix
  `IP41`), with a stored setting only as a fallback and no strap or pin read. `C (IP45)` is the Origin 300 board and
  `C (IP37)` has no identity route in any package; only `5` is in a supported-brick string of the 1.62.1 container
  (`O5#=?` in both 2 MB packages), and the SHub 1 PROM names its compute board `IP41` (banner, klconfig board name,
  build flag). The `IP41` module in those two packages probes four processors and discovers NUMAlink 4 neighbours
  ("SH%d NI0 always NL4 on IP41 brick"). Established for the L1 and PROM sides; no captured `config` line from a real
  brick exists. The type table itself gives no SHub generation.
- **Established** (SAL 5.04 `shub1snprom.bin`, `0xffa7d510`, Ghidra and `ia64-linux-gnu-objdump`): the L1's
  `0x0003` reply for this brick is status 0, `rack << 6 | bay`, then `0x35`. The PROM does not keep `5`: it folds
  `5`, `o`, `m` and `@` to `c` (99) before packing the module word, so the word the kernel is later given carries `c` (the SAL call that returns it was not
  traced; inferred). A reply of `C` would
  lower-case to the same `c`. See [the L1 request page](../../software/firmware/snprom/l1-requests.md#3-0x0003-rack-bay-type).
- **Unknown**: no register read from a 3300 or 3700 exists. The SHub 1 identity part word at `0x1_0000_0000` would
  settle the stepping (1.1 or 1.2), and the generation flag `SN_SAL_GET_SN_INFO` returns would confirm it. The Bx2
  is listed for the SHub 1 image by the same README, which conflicts with the README's inference that it is SHub 2;
  not settled here (see [the Bx2 page](altix-3700-bx2.md)).

SHub 2 board values, checked in `shub2snprom.bin` 10.54 (function at `0xff4824e0`, read in Ghidra): the board value is
stored at `0x5003_1240` of the node window, then compared; `0x7b` and `0x200` take the stacked-DIMM adjacency check
(fatal "4GB or larger stacked DIMMs cannot be installed in adjacent slots" error, node-dependent), `0xa00` and `0xe00`
return with no check, and anything else prints "UNABLE TO VERIFY DIMM CONFIGURATION: unknown board type". All four
are established as accepted values; the images name no product for them, so the mapping to a blade is unknown. The
board value is fetched by a call earlier in the routine (`0xffff` if that call reports failure) and is the one stored.

## Open

- Inferred: the Super-Bedrock ASIC and the SHub are one part, from the same role in both guides. Neither guide gives a
  chip generation; the firmware packages do ([above](#shub-generation)).
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

### Review of the SHub generation section (2026-11-21)

Independent review, 2026-11-21, by a reviewer who wrote none of it. Reviewed chips revision c7b162e. Checked in the held
snprom 10.54, 4.43, 4.20 and 3.32 packages and `l1-1.62.1.bin`, and in Ghidra (`shub2snprom.bin`, function `0xff4824e0`).

Confirmed: `README.snprom` lists the 3300, 3700 and 3700 Bx2 (and 330, 350, Prism) for `shub1snprom.bin` and only the
4700 and 450 for `shub2snprom.bin`; `shub2snprom.bin` carries "SHUB2 does not support XIO I/O." and "SAL 1.54 ... IP65",
the SHub 1 images do not; the 3.32, 4.20 and 4.43 banners and the "SHUB 1.1 present" strings; the `l1-1.62.1.bin` brick
type names (table at `0x5908b`, `Opus IP65` the only name with the SHub 2 board); the C-brick XIO text (007-4579-001 PDF 129, printed
p.105). The board-value routine takes `0x7b`, `0x200`, `0xa00`, `0xe00` as the commit says: the value is stored to
`0x5003_1240` (a store helper, not a read), `0x7b` and `0x200` run the stacked-DIMM check, `0xa00` and `0xe00` return,
others print "unknown board type".

Corrected: the "predate the SHub 2 line" bullet was labelled established but rests on dates, and the build command lines
of 3.32 and 4.43 already carry `HWREGS_SHUB_II`, `CONFIG_TIO` and `CONFIG_NL4R`; it is now inferred with that caveat. The
verdict now states that the image-to-chip step is inferred. Fixed a "quoted above" reference with no quote, a "next
section" that is the previous one, and the claim that `0xa00` was newly found (the SHub 2 pages already list it).

Not settled: whether the Bx2 is SHub 1 or 2; the 3000 C-brick's L1 type; the SHub 1 stepping.

### IX-brick wiring (2026-11-21)

Not reviewed. Changed claims: the IX-brick wiring section, the sources line and the open items in the IX-brick page's
unknowns table that this section now answers. Renewed independent review is needed before these are cleared.
