# SGI interconnect naming: every name, from the deepest source

> **Earlier correction (2026-11-10).** The first version of this audit was wrong on
> three points, verified against SGI's own manuals:
>
> - **Ktown is an SGI hardware term.** 007-3439-002 (Origin/Onyx2 Theory of
>   Operations), printed p73: "XIO can also run outside an enclosure, using the
>   Crosstown (KTOWN) conversion board." 007-4264-001 names the **Ktown2** board
>   (it supports two graphics pipes, printed p8) and the **Xtown2** cables that
>   connect each pipe's Ktown2 interface (printed p20). Ktown is the Crosstown
>   conversion board that connects XIO to an InfiniteReality pipe's geometry
>   board in the rackmount Onyx2; Ktown2 is the Onyx 3000 version.
> - **PIC is an SGI hardware term, and it is not Xbridge.** 007-4377-001,
>   printed p67: "Three PIC (PCI interface chip) ASICs are key components of the
>   IX-brick architecture." Xbridge is a different chip (the Origin 300 I/O
>   bridge, 007-4365-002 p10). The earlier claim that SGI's guides call PIC
>   "Xbridge" conflated two chips.
> - **"Software only" was too strong.** XTalk appears in SGI's own software
>   guides (007-0911 series). PXBOW and XXBOW were not found by a Library search
>   of the SGI manuals, which shows only that this search missed them, not that
>   SGI never used the names. Every row below graded "software only" is
>   downgraded to "not found in the SGI manuals searched" until it is checked
>   page by page.

## Corrections (2026-11-10)

A second check of this file against the primary sources found the following.
Seven problems were reported; six were confirmed, one was partly right (the
intro was right that XXBOW is in the headers, wrong about kernel objects), and
none was rejected.

**Facts and grades fixed**

- *Intro overstated where PXBOW, XXBOW and PIC appear (partly right).* Only PXBOW
  is in a shipped kernel object (the IP35 kernel). XXBOW is in no kernel or
  firmware image, which section 3.5 already said. The intro and section 4 now
  match.
- *Crosstown2 and Xtown2 had different machine lists (confirmed).* Both
  spellings label the same port in the same bricks (007-4264-001 uses Xtown2 for
  the I-, P- and X-brick ports; 007-4377-001 p67 prints "Crosstown2 XIO port" in
  the figure and "Xtown2" in the text beside it). They are now one row, and the
  brick table uses both spellings.
- *"Two consecutive widgets" for PIC (confirmed).* No source numbers the two
  widgets. The sources say two widget headers with part ids 0xd102 and 0xd112.
  Adjacency is now marked unknown, with a test.
- *"Hub2" graded established (confirmed).* Two PROM strings plus the
  revision table support the reading "revision 2 and later", but no source
  defines the term. Now graded inferred, with a test.
- *Origin 200 and the Crosstown board.* Checked: `Origin200_MG` does describe a
  Crosstown board and status LEDs, so the Origin 200 stays in the Crosstown row.
- *P-brick chip count conflict.* Re-read: 007-4240-002 p140 says three Xbridge
  ASICs and OpenBSD `xbridge.c` says six; both exist, and the block diagram
  was still not read. The X-brick has one (p152).
- Kernel and firmware text claims (ktown and the VME-over-Xtown string in
  `icrash`, the KTOWN script in `gfxtopology`, 12 CrayLink strings in the 6.5
  base IP27 PROM against 12 NUMAlink and none in 6.5.30, 10 NUMAlink and none
  in the IP35 PROM) were re-checked and hold. The unverified "about 2.77 million
  strings" figure was dropped.
- Public Linux ia64 files for TIOCA, TIOCE, SHub and the Crosstalk Crossbow
  header exist in the 2018 history and carry the ids used here (TIOCA 0xe020,
  TIOCE 0xce00, XXBOW 0xd000, PXBOW 0xd100). The SHub1/SHub2 and
  LB/XB claims were not re-checked and are marked so.
- Section 3.11: the "local block" and "crossbar" expansions for LB and XB rested
  only on header comments and are now unknown. Section 3.12: the TPU expansion
  is likewise dropped.

**Removed because it had no public or shipped-binary basis**

- Internal identifiers: macro, function, flag, enumeration and part-prefix
  names from the shipped headers and kernel objects, and the shipped file and
  object names. Where a claim needed a pointer, it now says what kind of thing was
  found, in plain words.
- Quoted or paraphrased header comments, and the citations of SGI documents
  that only the headers name.
- Facts with no public or shipped-binary basis (the GSN widget ids, the Octane
  Xtown diagnostic), now unknown. The "S only" marker is gone with them.
  Names that public Linux or OpenBSD carry, and part and revision numbers, stay.

---

**This rewrite.** The first audit led with manuals and only glanced at drivers.
This one starts from the kernels, firmware and drivers, because chip, widget and
board names live there, and uses the manuals to confirm and date them. Every
name below was searched for in every source in section 1. What changed:

- PXBOW, XXBOW and PIC are in the shipped 6.5.30 headers, and in public Linux
  and OpenBSD. Of the three, only PXBOW also appears in a shipped kernel object
  (the IP35 kernel, once). XXBOW is in no shipped kernel object or firmware
  image. PIC is also in SGI's IX-brick and PX-brick guide.
- "XTalk" and "xtalk" are SGI's own spelling, in shipped firmware text and in
  the hardware-graph paths SGI's customer guides print.
- KTOWN is in a shipped kernel archive and a shipped script, not only in
  manuals.
- TIO, SHub and TIOCP exist in the shipped 6.5.30 IP35 kernel as names (the
  part numbers for TIOCP are in its bridge accessors). TIOCA and TIOCE are
  Linux and OpenBSD names only.
- "Hub II" is not a chip; "II" is the I/O interface block of Hub and Bedrock.

---

## 1. Sources, and how far each reaches

Each source gets a tag used below. Facts are in my own words. Only product
names, part numbers, revision numbers and user-visible output text are taken
from the shipped files; no source text, structure bodies, comments or
internal identifiers are reproduced.

| Tag | Source | What was done |
|---|---|---|
| **K** | Shipped IRIX kernel relocatables and archives, `usr/cpu/sysgen/IP*boot/`, both releases: 6.5 base (June 1998: IP19 IP20 IP21 IP22 IP25 IP26 IP27 IP28 IP30 IP32) and 6.5.30 (2006: IP22 IP27 IP30 IP32 IP35) | `strings -a -n 4` over every file (compiler command lines excluded), the ELF symbol tables and the debug-info name tables of the 6.5.30 objects. The 6.5-base kernel directory list was confirmed in the 2026-11-10 re-check; the per-object coverage statements below were not re-verified then |
| **H** | Shipped headers of both releases (`usr/include/sys`: the Crosstalk, PCI, RACER and node-architecture headers) | read for part numbers, revisions and enumerations; compared 6.5 base with 6.5.30 |
| **F** | Shipped firmware, `usr/cpu/firmware/`: `ip27prom.img` (both releases), `ip35prom.img`, `IP30prom.bin`, `ip32prom.image`, `io6prom.img` | `strings -a`. The IO6 image gave no interconnect names (it may be packed; unverified). The IO4 image is a different bus and was not searched here |
| **U** | Shipped userland, 6.5.30: `sbin/hinv`, `usr/gfx/gfxtopology`, `usr/bin/icrash` | `strings -a` |
| **I** | IRIS InSight books on the 6.5.30 media (SGI's own hardware guides as HTML): `OrOn2_Theops`, `OrOn2_ProgRef`, `OrOn2_SitePrep`, `Or2000_Rack_OG`, `Or2000_Desk_OG`, `Onyx2_Rack_OG`, `Origin200_OG`, `Origin200_MG`, `Origin300_UG`, `Origin300_SP_UG`, `Origin_3K_OG`, `Onyx_3K_OG`, `Onyx300_UG`, `Fuel_UG`, `L1andL2Con_UG`, `DevDriver_PG` | full-text search for every name, then read the hit |
| **M** | Library TechPubs PDFs, by document number and printed page: 007-3410-001, 007-3439-002, 007-3938-006, 007-4240-002, 007-4264-001, 007-4365-002, 007-4377-001, 007-4520-007, 007-4633-017 | `tools/library-pdf find` and `text` |
| **C** | This repository's census of the shipped binaries (`chips/<chip>/README.md`, `include/*.h`) | read for the part numbers the kernel code compares against |
| **L** | Public Linux: `arch/mips` in v7.2-rc7; `arch/ia64/sn` and `arch/mips/include/asm/xtalk` in the 2018 `linux-mips` history, which still has the Altix tree | grepped for every name |
| **O** | OpenBSD `sgi` port, `sys/arch/sgi/xbow/` and `sys/arch/sgi/{include,sgi}/` | grepped for every name |

A local, unpublished Linux working branch sits in the reference tree. It is not
a source here because it is not public.

**Basis.** Everything in this file rests on shipped files, public drivers or
manuals. An earlier revision recorded a few facts without such a basis (widget
ids for one graphics device and the layout of an Octane diagnostic). They have
been removed, and the shipped 6.5.30 material is the deepest source for the
Origin 300 generation names.

**Grades.** *Established*: read as text in the cited source. *Inferred*: a
reasoned reading, reasoning given. *Unknown*: not settled, with a test that would
settle it. These grade the **naming claim**, meaning what the thing is called
and what the name denotes. Register behaviour is graded in the datasheets and
`chips/<chip>/README.md`.

---

## 2. The widget identification word

Every widget presents an identification word at widget offset 0x04 (H; the same
layout in L `arch/ia64/sn/include/xtalk/xwidgetdev.h` and O `xbow/widget.h`):
revision in bits 31:28, part number in bits 27:12, manufacturer in bits 11:1.
IRIX compares revisions as `part << 4 | rev`. The part number is what drivers
dispatch on, so it is the best stable key for a name.

| Part | Mfr | Name | Where the number comes from | Grade |
|---|---|---|---|---|
| 0x0000 | 0x000 | XBOW (Crossbow) | H (both releases); O `xbowdevs` | established |
| 0xd000 | 0x000 | XXBOW | H (6.5.30 only); L `arch/mips/sgi-ip27/ip27-xtalk.c` and `arch/ia64/sn/include/xtalk/xbow.h`; O | established |
| 0xd100 | 0x000 | PXBOW | H (6.5.30 only); L `arch/ia64/sn/include/xtalk/xbow.h`; O | established |
| 0xc001 | 0x036 | HEART | H; O | established |
| 0xc002 | 0x036 | Bridge | H; O | established |
| 0xd002 | 0x024 | Xbridge | H (6.5.30 only); O | established |
| 0xd102 / 0xd112 | 0x024 | PIC, bus 0 / bus 1 | H (6.5.30 only); O gives the second id | established (0xd102); inferred (0xd112) |
| 0xe000 / 0xe010 | 0x024 | TIOCP, head 0 / head 1 | C `chips/tiocp/README.md` (the IP35 kernel's bridge accessors branch on both, manufacturer 36 decimal); O | inferred (not re-read here; the TIOCP page holds the reading) |
| 0xe020 | 0x024 | TIOCA | L `arch/ia64/include/asm/sn/tioca.h`; O | inferred |
| 0xce00 | not read | TIOCE | L `arch/ia64/include/asm/sn/tioce.h`, `tiocx.h` | inferred |
| 0xc101 | 0x036 (O) | Hub | H | inferred |
| 0xc110 | 0x036 (O) | Bedrock | H | inferred |
| 0xc120 | not read | SHub | L `arch/ia64/include/asm/sn/shubio.h` | inferred |
| 0xc003 | 0x2aa | HQ4 (MardiGras / Impact graphics) | H (6.5 base) | inferred |
| 0xc102 | 0x2aa | XG (Kona / InfiniteReality graphics) | H (6.5 base) | inferred |
| 0xc013 | 0x023 (O) | Odyssey | O `xbowdevs` | inferred |
| 0xc202 | 0x024 | TPU | H; O `xbowdevs` | inferred |

Grades: established means a shipped kernel routine that registers a driver for the part was read and passes that part and
manufacturer number (`xbow_init` and `xbridge_init` in the IP27 kernel, the HEART initialiser in the IP30 kernel,
`pic_init` in the IP35 object); the other rows are inferred, resting on published headers or tables with no binary read.
The "H" source column records where a number is also printed, for provenance only; no text from it is reproduced.

No widget ids for the GSN graphics boards are given here: the only source
found for them is not public.

**Unknown: what the manufacturer numbers identify.** 0x024 is shared by Xbridge,
PIC, TPU and the TIO parts; 0x036 by Bridge, HEART, Hub and Bedrock; 0x2aa by
the two graphics interface chips. No source reached says whether this names a
design group or a fab. Test: a published Crosstalk specification page that
defines the field, or the ID register of a part whose maker is known from its
package marking.

---

## 3. Names, one by one

### 3.1 XIO, Crosstalk, XTalk, xtalk

- **What.** XIO is SGI's trademark for the I/O link and slot standard.
  Crosstalk is the protocol and fabric name of the same link. XTalk/xtalk is
  the abbreviation.
- **Machines.** Octane family (HEART host); Origin 200/2000 and Onyx2 (Hub
  host); Origin 300/350/3000/3500, Onyx 300/350/3000 and Fuel (Bedrock host);
  Tezro by OpenBSD's reading; Altix (SHub host, TIO in some bricks).
- **Sources.**
  - XIO: M 007-4365-002 p2 (trademark list); 007-3439-002 ("XIO Protocol and
    Devices"); 007-4240-002 p125 (the C-brick connector labelled "XIO (II)");
    007-4377-001 p78 (an L1 command named `XIO` sets the port speed); I
    `Octane_OG`, `Octane2_OG`, `Origin_3K_OG` (dozens of hits); K IP35 (a fault
    message about the XIO link from Bedrock to Xbridge being down).
  - Crosstalk: M 007-3439-002 p28; F both `ip27prom` releases (a PCI-to-Crosstalk
    read timeout message and a Crosstalk error message); I `OrOn2_Theops` ch02.
  - XTalk/xtalk: F `ip27prom` 6.5 base (a debug command that dumps XTalk credits;
    Hub register dump text mentioning XTalk requests); I `Or2000_Desk_OG` ch07,
    `Origin200_OG` ch04 and `Onyx_3K_OG` ch03 print hardware-graph paths with an
    `xtalk` directory (`/hw/module/1/slot/n4/node/link/xtalk`,
    `/hw/module/001c13/Ibrick/xtalk/15/pci/5/...`); K: the IP27 and IP30 kernels
    of both releases and the 6.5.30 IP35 kernel contain Crosstalk and Crosstalk
    switch driver objects; L and O `xtalk` directories.
- **Grade.** XIO and Crosstalk: established as SGI hardware terms. XTalk and
  xtalk: **established as SGI's own spelling**, in shipped firmware text and in
  customer guides. The first audit called it a spelling used only by operating
  system software; it is SGI's software, and customers saw it.

### 3.2 Widget, Little Window, Big Window, SWIN

- **What.** A widget is an XIO device with a 4-bit widget number (0 to 15; the
  Crossbow is 0, its ports 8 to 15, H). Each widget has a 16 MB
  directly mapped window; larger views go through seven big windows.
- **Sources.** M 007-3410-001 p23 ("little window (LWin)", "big windows", seven
  512 MB spaces) and p25 ("called widgets"); I `OrOn2_ProgRef` ch02 and ch03
  ("Little Window (LWin) Map", "Big Windows (BWin)"). Shipped IRIX code names the
  16 MB region SWIN (and the large views BWIN); public L
  `arch/mips/include/asm/sn/addrs.h` uses the same SWIN prefix, and O
  `ip27_machdep.c` follows IRIX. O `xbridge.c`: a big window is 28 or 29 bits
  depending on model and N or M mode.
- **Grade.** Established. SGI's hardware documentation says **Little Window
  (LWin)**. Software uses the prefix SWIN for the same region. What "S" stands
  for in SWIN: **unknown** from any public source reached (the earlier claim
  that it means "small" came from a shipped header comment and is dropped). Use
  Little Window in hardware text; name SWIN only when pointing at the Linux
  macro prefix.

### 3.3 LLP, credits, STL, PECL, CrayLink, NUMAlink

- **What.** LLP is the link-level protocol of both the router network and the
  XIO link; credits are its flow control; STL (SGI Transistor Logic) and PECL
  are signalling levels. CrayLink Interconnect is the Origin 2000-era name of
  the router network; NUMAlink is the later name.
- **Sources.** M 007-3439-002 p22, p80, p82; I `OrOn2_Theops` glossary. F
  `ip27prom`: the 6.5 base image has 12 strings naming CrayLink; the 6.5.30
  image has 12 strings naming NUMAlink and none naming CrayLink; F `ip35prom`
  has 10 NUMAlink strings and none naming CrayLink. M 007-4240-002 p125
  ("NUMAlink3", 1.6 GB/s each direction); 007-4520-007 p13 (Altix: NUMAlink 4).
- **Grade.** Established. The rename falls between the 6.5 base and 6.5.30
  releases.

### 3.4 XBOW (Crossbow)

- **What.** The 8-port crossbar ASIC that fans one or two Hubs out to XIO
  widgets. It is itself widget 0. External ports are 8 to 15. The two ports
  facing Hubs are 9 and 10 in the Origin 2000 generation's header and 10 and 11
  in the IP35 header. Revisions 1.0, 1.1, 1.2, 1.3 and 2.0 are stored as 1 to 5.
- **Machines.** Octane and Octane2; Origin 2000 and Onyx2 (one or two on the
  midplane). Whether an Origin 200 board has one: unknown. IP35 machines
  normally do not use a discrete Crossbow (see 3.5 and 3.6).
- **Identity.** Part 0x0000, mfr 0x000.
- **Sources.**
  - M 007-3439-002 p84 ("Crossbow (XBOW) ASIC") and the fabric figure; I
    `OrOn2_Theops` ch01 to ch03 ("Crossbow (XBOW) ASIC"; glossary "Crossbow
    chip: an 8-port ASIC"), `Onyx2_Rack_OG` ch01 ("Crossbow (XBOW) ASICs on the
    midplane"), `SGI_2100_OG` ch07 (a `hinv` line "ASIC XBOW Rev 2, on midplane
    of Module 1").
  - U `hinv` 6.5.30 ("Xbow ASIC: Revision 1.%d", "2.%d"); H (an inventory
    class for the Crossbow, spelled "cross bow").
  - K: a Crossbow driver object in IP27 and IP30 of 6.5 base and IP27, IP30 and
    IP35 of 6.5.30, covering link reset, LLP monitoring, performance counters
    and bandwidth allocation.
  - F `IP30prom.bin` ("xbow(rev 1.%d)", "xbow(rev 2.%d)", a widget status
    register line); `ip27prom` (an "XBow Diagnostic", a failed-hardware-test
    message and a bad-id message); `ip35prom` (an "XBow signalled following
    errors" message).
  - O and L `xbow.c`, `xbow.h`.
- **Grade.** Established. Capitalisation in shipped text varies (XBOW, XBow,
  Xbow, "cross bow"); SGI's manuals print "Crossbow" with "(XBOW)" as the short
  form.

### 3.5 XXBOW

- **What.** The widget-0 personality of an Xbridge-based I/O brick: a
  Crossbow-class part sitting in front of the Xbridge widgets. No manual
  reached uses the name.
- **Machines.** The bricks that carry Xbridge: Origin 300, Fuel, Onyx 300 and
  the Origin 3000 I-, P-, X- and V-bricks.
- **Identity.** Part 0xd000, mfr 0x000.
- **Sources.**
  - H 6.5.30 Crosstalk header: the name, part number 0xd000 and revisions 1.0
    and 2.0, with an Xbridge association. Absent from the 6.5 base header.
  - L `arch/mips/sgi-ip27/ip27-xtalk.c` (comment: "Xbow in Xbridge"), L
    `arch/ia64/sn/include/xtalk/xbow.h`; O `xbowdevs` (`XXBOW 0xd000 XXBow`) and
    `xbow.c`.
  - F `ip27prom` 6.5.30 accepts three widget-0 ids where the 6.5 base image
    accepts one.
  - The string XXBOW is in no K or F image (searched all of them; a
    case-insensitive grep over the whole 6.5 base and 6.5.30 media also finds it
    only in the 6.5.30 Crosstalk header, plus a false match on an Octane
    diagnostic string that merely contains "xXBOW"). The name lives in headers
    and in OS drivers.
- **Grade.** Name and number: established (shipped header; public Linux and
  OpenBSD). Meaning "the crossbow function of Xbridge": **inferred** from the
  Linux comment and the manuals' description of one Xbridge ASIC with two
  Crosstown2 ports in front of several slots (I `Origin_3K_OG` ch07,
  `Onyx_3K_OG` ch02; the L1 `ioport` text shows an Xbridge with "port A" and
  "port B", I `L1andL2Con_UG` ch03). **Unknown:** whether widget 0 is on the
  same die as the bridge widgets. Test: read widget 0 and the bridge widget IDs
  on an X-brick and a P-brick and compare with the guide's block diagram.

### 3.6 PXBOW

- **What.** The same role as XXBOW for PIC-based bricks.
- **Machines.** IX- and PX-bricks: Origin 350/3500 and Onyx 350 under IRIX (the
  6.5.30 IP35 kernel and PROM carry PIC and the brick types, F `ip35prom`
  "IXbrick" "PXbrick"; the machine names are OpenBSD's reading), and the
  Altix 3700 Bx2 (007-4377-001).
- **Identity.** Part 0xd100, manufacturer 0x000 (the same constant as XXBOW).
- **Sources.** H 6.5.30 Crosstalk header (name and part number 0xd100, with a PIC
  association; absent from 6.5 base); K: the name occurs once in the IP35
  kernel's debug name table, in a function name about checking a port's I/O
  enable, and in no other kernel object of either release; L
  `arch/ia64/sn/include/xtalk/xbow.h` (name, 0xd100, and a PIC remark); O
  `xbowdevs` (`PXBOW 0xd100 PXBow`). No F string.
- **Grade.** Name and number: established. Meaning "crossbow function of PIC":
  inferred (Linux's PIC remark; 007-4377-001 p78 shows three PIC ASICs giving
  two Xtown2 ports and six PCI-X buses, which needs a switching function). Same
  unknown and test as XXBOW.

### 3.7 Bridge, Xbridge, and the GIO adapter

- **What.** Bridge is the XIO-to-PCI bridge ASIC of Octane and the Origin
  2000 generation (on Octane it also hosts a GIO adapter). Xbridge is a later,
  different chip. SGI customer text writes "Xbridge"; the L1 `ioport` command
  prints "XBridge".
- **Machines.** Bridge: Octane (IP30), Origin 2000, Onyx2 base I/O. Xbridge:
  Origin 300, Fuel, Onyx 300 and the Origin 3000 I-, P-, X- and V-bricks (M, I).
  O adds "later Origin 200/2000". The shipped 6.5.30 IP27 and IP30 kernels also
  contain an Xbridge driver.
- **Identity.** Bridge 0xc002, mfr 0x036, revisions A to D (1 to 4). Xbridge
  0xd002, mfr 0x024, revisions A and B. H; the 6.5 base header has no Xbridge
  constants. The 6.5.30 IP27 PROM accepts four bridge IDs.
- **Sources.**
  - M 007-3439-002 p86 ("Bridge ASIC"); 007-4365-002 p10 ("Xbridge ASIC ... the
    interface between the Bedrock ASIC and the PCI slots"); 007-4240-002 p140
    (three Xbridge ASICs in the P-brick), p152 (one in the X-brick).
  - I `Origin300_UG` ch01; `Fuel_UG` ch05 (power-on test order: CPU, Bedrock
    ASIC, PROM, memory, secondary cache, Xbridge ASIC, PCI slots);
    `Origin_3K_OG` ch06 and ch07; `Onyx_3K_OG` ch02 (V-brick midplane);
    `L1andL2Con_UG` ch03 and 007-4240-002 p248 (the `ioport` output labels
    "XBridge" and the text calls it the "crosstown ASIC" of the I-, P-, PE-, X-
    and V-brick).
  - U `hinv` ("ASIC Bridge Revision %d").
  - K: Xbridge driver objects in 6.5.30 IP27, IP30 and IP35; Bridge driver
    objects in 6.5 base IP27 and IP30 and in all three 6.5.30 kernels; a GIO
    adapter driver in IP30 only (both releases); H has an ASIC-type enumeration
    with Bridge and Xbridge values.
  - F `ip35prom` brick strings "Xbridge", "Bridge"; `ip27prom` (failed-bridge
    test message, a Bridge-revision-A arbitration note, "Found GIO board");
    `IP30prom.bin` ("bridge(rev %c)").
  - O `xbridge.c` header comment (Bridge on Octane and maybe early Origin
    200/2000; XBridge on later Origin 200/2000 and Origin 300/3000); L
    `arch/mips/include/asm/pci/bridge.h`.
- **Grade.** Names and numbers: established. **Unknown:** which Origin
  2000-era and Octane2-era boards carry Xbridge rather than Bridge. Test: the
  part number in the bridge widget ID of such a board (a `hinv` prints "ASIC
  Bridge Revision" for Bridge). **Conflict:** O `xbridge.c` says a P-brick can
  have six Xbridge chips on one Crossbow; 007-4240-002 p140 and `Origin_3K_OG`
  ch06 say three Xbridge ASICs. Both statements were confirmed to exist; the
  P-brick block diagram was not read. Resolve with that diagram against a widget
  enumeration.
- **GIO.** The Octane kernel has a GIO adapter driver behind Bridge; the
  Origin PROM also prints "Found GIO board". Established that the name exists in
  K and F. It is not a Crosstalk widget.

### 3.8 PIC

- **What.** The PCI interface chip: one ASIC with two bus heads, each
  presenting its own widget header (O: "a single chip but with two widgets
  headers"). The part ids differ by 0x10. Whether the two widget numbers are
  adjacent is **unknown**: no source reached numbers them. The shipped header's
  device-numbering note allows four device numbers per bus; the IX- and
  PX-bricks put two card slots on each bus.
- **Machines.** IX- and PX-bricks (007-4377-001, the Altix 3700 Bx2 guide; the
  IRIX IP35 kernel has the driver, so IRIX Origin 350/Onyx 350 systems use
  them).
- **Identity.** Part 0xd102 (bus 0) and 0xd112 (bus 1), mfr 0x024, revisions A
  to C (H, 6.5.30 only).
- **Sources.** M 007-4377-001 printed p67 ("Three PIC (PCI interface chip) ASICs
  are key components of the IX-brick architecture"; two Xtown2 XIO ports and six
  PCI-X buses; the figure labels PIC ports) and p78 (PX-brick, same chip, "can
  connect an InfiniteReality graphics pipe to a CR-brick"). K: the IP35 kernel
  has a PIC driver object, a PIC register-dump debug routine and a PIC asic-type
  value. O `xbowdevs` and `xbridge.c`. C `chips/pic/README.md`. The shipped
  header refers to an SGI "PIC manual"; it was not found in the Library.
- **Grade.** Established as SGI's own name and as a part number. **Not
  Xbridge.** Two-widget structure: established (O); adjacency of the widget
  numbers: unknown. Test: enumerate widgets on a PIC brick.

### 3.9 TIO, TIOCP, TIOCA, TIOCE

- **What.** TIO is the Altix-generation I/O ASIC family. TIOCP is the PCI-X
  bridge variant (same register layout as PIC in the IRIX accessors, C
  `chips/tiocp/README.md`); TIOCA an AGP bridge (L); TIOCE a variant Linux
  names "CE", with two ports and address translation entries (L `tioce.h`). L's
  address comments call TIO's address space "coretalk"; how that relates to
  Crosstalk is unknown.
- **Machines.** Altix (L, M 007-4633-017 p20: "each TIO ASIC" is a root bridge
  in a PA-brick). Not an Origin or Octane part.
- **Identity.** TIOCP 0xe000 and 0xe010; TIOCA 0xe020; TIOCE 0xce00.
- **Sources.**
  - K 6.5.30: the ASIC-type enumeration in the kernel code shared by IP27,
    IP30, IP32 and IP35 has a TIOCP value; the PCI bridge drivers include a
    TIOCP header; the IP35 kernel's debug name table has TIO-prefixed
    widget-setup functions. H has the TIOCP type as the last ASIC type; C
    `chips/tiocp/README.md` (the accessors branch on part 0xe000 and 0xe010,
    manufacturer 36).
  - L `arch/ia64/include/asm/sn/{tioca,tioce,tiocp,tio,tiocx}.h`,
    `arch/ia64/sn/pci/tioc{a,e}_provider.c`; O `xbowdevs` (comment: TIO
    "apparently is a next-generation XIO framework", on SN2 only); M
    007-4633-017 p7 and p20.
  - TIOCA and TIOCE: in no shipped IRIX file.
- **Grade.** The names TIO and TIOCP: established in shipped IRIX 6.5.30. That
  IRIX can drive a TIO part: **unknown**; the shipped names show shared code
  that tolerates the type. The expansion of "TIO": **unknown** (not in
  007-4520-007 or 007-4633-017). Test: an Altix-era document or commit message
  that spells it out.

### 3.10 HEART

- **What.** The Octane's memory controller, CPU interface and XIO host, the
  Crosstalk host chip of IP30.
- **Machines.** Octane, Octane2.
- **Identity.** Part 0xc001, mfr 0x036, revisions A to D (H).
- **Sources.** H (6.5 base and 6.5.30); K: a HEART driver object in IP30 of
  both releases; F `IP30prom.bin` ("HEART ISR", "heart(rev %c)", "Widget Err
  Cmd"); U `hinv` ("Heart ASIC: Revision %c"); M OCTANE Technical Report §2.3.2
  "Heart ASIC"; L `asm/sgi/heart.h`; O `xheartreg.h`, `xheart.c`.
- **Grade.** Established. **Unresolved labels:** "UXHEART", "GHBridge" and
  "HXBOW" occur only in `IP30prom.bin` (once each, in register-dump text), in no
  kernel, header or manual reached. What the U, GH and H prefixes mean is
  unknown. Test: disassemble the PROM routines that print them and read the
  adjacent register-group names.

### 3.11 Hub, Hub2, Bedrock, SHub, and their blocks

- **Hub.** The node ASIC of Origin 200, Origin 2000 and Onyx2: it joins the
  processors, a distributed memory with directory, the CrayLink router port and
  the XIO port. Part 0xc101 (H); revisions 1.0 and 2.0 to 2.4 (H, values 1 to
  6). Sources: M 007-3439-002 p11, p21, p33 ("Hub ASIC and Interfaces"), p77;
  007-3410-001 p30; I `OrOn2_Theops` ch03; F `ip27prom` ("Hub Rev: %lld", "Hub
  chip failed abist test"); U `hinv` ("HUB in Module %d/Slot %d: Revision %d
  Speed ..."); H (an inventory class for the Hub); K: Hub driver objects in the
  IP27 and IP35 kernels.
- **Hub2.** "Hub2" is **inferred** to mean hub revision 2 and later, not a
  separate chip. The only evidence is a PROM message that begins "HUB2:" and
  concerns a NACK-count setting, a build-flag name in the same image that
  carries "HUB2", and the revision table (1.0 is revision 1, 2.0 to 2.4 are 2
  to 6). No source reached defines "Hub2" or states its range. Test: a Hub
  errata or revision-history page that uses the term.
- **Bedrock.** The node ASIC of the IP35 family: Origin 300/350/3000/3500,
  Onyx 300/350/3000, Fuel; Tezro by OpenBSD's reading. SGI writes "Bedrock ASIC
  (or hub ASIC)". Part 0xc110 (H); revisions 1.0 and 1.1 (H). Sources: M
  007-4365-002 p10 ("enables communication between the processors, memory, and
  I/O devices"); 007-4240-002 p116 ("a crossbar switch ...") and p246 (an L1
  `bedrock` debug command); I `Fuel_UG` ch05, `Origin300_UG`, `Origin_3K_OG`; F
  `ip35prom` ("Bedrock Rev: %lld", "built for bedrock rev. 1.1 or greater",
  and per-block error-dump lines); K IP35 kernel (the same lines); H (a
  Bedrock register header). The headers cite an SGI interface specification
  for the Bedrock; it was not found in the Library searches made.
- **Hub II.** No chip has this name in any source. "II" is the I/O interface
  block of Hub and Bedrock, the Crosstalk side. Evidence: panel label `XIO (II)`
  (M 007-4240-002 p125); the PROM's Hub and Bedrock error-dump text labels this
  block "II". Established.
- **Blocks.** PI processor interface (two PIs per Bedrock, two CPUs each, H),
  MD memory/directory, NI network interface (panel label `LINK (NI)`), II I/O
  interface. PI, MD, NI and II are established (M 007-3410-001 p30: "the four
  interfaces of the Hub (NI, PI, MD, II)"). The Bedrock error dumps also name
  two further blocks, LB and XB; their expansions are **unknown** (not defined
  in any manual reached; the earlier "local block" and "crossbar" readings came
  from header comments and are dropped). Test: a Bedrock block-diagram page.
- **Junkbus.** The slow-device bus of Hub and Bedrock. SGI's L1 text uses it
  as a name: `L1andL2Con_UG` ch03 says "Junkbus" refers to the hub ASIC in the
  C-brick in the `ioport` output, where `Origin_3K_OG` appendix B prints
  "Bedrock" for the same output; 007-3938-006 p53 and p74 list `junkbus`, `jb`
  and `bedrockbrick` as L1 command targets (p53 and p74 beyond the one search
  hit were not read in full). Established as an SGI term; which edition is
  older: unknown.
- **SHub.** The Altix hub: "scalable hub (SHub) ASIC ... acts as a crossbar
  between the processors, local SDRAM memory, the network interface, and the I/O
  interface" (M 007-4520-007 p13). Part 0xc120 (L `shubio.h`); SHub1 and SHub2
  (L `arch.h`, `shub_mmr.h`; not re-checked in this pass). IRIX shows one name:
  a SHub-prefixed piomap function in the 6.5.30 IP35 kernel's debug name table,
  next to the Hub equivalents. Established as SGI's Altix name. That IRIX
  drives an SHub: not shown; **inferred** not, from a single name. Test: any
  shipped IRIX object that compares a widget part against 0xc120 (none found).
- Component names transfer between machines; topology does not.

### 3.12 Graphics and other XIO widgets

- **HQ4.** The XIO interface chip of MardiGras (MGRAS, Impact) graphics. 0xc003,
  mfr 0x2aa; NIC at widget offset 0x011098 (H, 6.5 base). O names the product
  "ImpactSR". K: MGRAS driver symbols.
- **XG.** The XIO interface chip of Kona (HILO, HILOLITE; InfiniteReality)
  graphics. 0xc102, mfr 0x2aa; NIC at widget offset 0x98 (H). K: a Kona
  driver archive in 6.5 base IP19, IP25, IP27 and 6.5.30 IP27, IP35; O names
  the device KONA.
- **Odyssey.** Octane-generation VPro graphics. 0xc013, mfr 0x023 (O); K: an
  Odyssey driver archive in 6.5.30 IP30 and IP35.
- **TPU.** The shipped kernel's board-type list has a TPU entry; widget 0xc202,
  mfr 0x024 (H); O `TPU`. The expansion of TPU: **unknown** from public sources
  (a shipped header comment expands it, but that text is not reproduced here).
- **GSN.** The shipped kernel's board-type list has two GSN entries, a main and
  an auxiliary board. No widget ids are recorded here.
- **Grade.** Part numbers established. The expansions of HQ4, XG, GSN and TPU
  are in no public source reached; HQ4 and XG are described by role only.

### 3.13 Crosstown, KTOWN, Ktown2, Xtown, Crosstown2 / Xtown2

The cable family that carries XIO signals out of a chassis. "Crosstown2" and
"Xtown2" are two spellings of one port and cable. SGI's manuals use both for the
same bricks, so the machine list does not separate them.

| Name | What | Machines | Sources |
|---|---|---|---|
| **Crosstown** | The cable link and protocol, and the XIO board that ends it: a converter from STL to 3.45 V PECL plus a cable attachment | Origin 2000, Origin 200, Onyx2 | M 007-3439-002 p53, p73 ("Crosstown (KTOWN) conversion board"), figure 2-28; I `OrOn2_Theops` ch02, `Onyx2_Rack_OG` ch02 (figure "Crosstown and CrayLink Interconnect Cables"), `Origin200_MG` ch04 and ch05 (Crosstown status LEDs, Crosstown board replacement) |
| **KTOWN** | The graphics-module end: the interface board that joins an InfiniteReality pipe of a rackmount Onyx2 to a compute module's Crosstown cable (one per pipe) | Onyx2 graphics module | I `Onyx2_Rack_OG` ch01, ch02, index ("KTOWN interface board"); K: the string KTOWN in the Kona driver archive of 6.5.30 IP27 and IP35, beside part, name and serial labels (absent from the 6.5 base archive); U `gfxtopology` (a script that lists KTOWN, GE and Odyssey boards by part, revision, serial) and `icrash` (a `ktown` string) |
| **Ktown2** | The Onyx 3000 / Onyx 300 version: one board with two connectors, one per pipe, between the pipes of the G-brick | Onyx 300, Onyx 3000 | M 007-4264-001 p8, p20; I `Onyx300_UG` ch01 ("Ktown2 board ... provides two Crosstown2 (Xtown2) connections"), `Onyx_3K_OG` ch01 to ch03 |
| **Crosstown2 / Xtown2** | The IP35-generation XIO port and cable, 1.2 GB/s each direction (800 MB/s selectable on PIC bricks) | C-, I-, P-, X-, IX-, PX- and G-brick; Origin 300/3000/350, Onyx 300/3000/350 | M 007-4240-002 p71, p125, p135, p140; 007-4264-001 printed p2, p4, p5 and p20 ("Xtown2" for the I-, P- and X-brick ports); 007-4365-002 p1, p8; 007-4377-001 printed p67 (the figure label "Crosstown2 XIO port" beside the IX-brick PIC ports, while the text beside it says "Xtown2 XIO ports"), p78; I `Onyx300_UG` ch01 states the two are equal |
| **Xtown** | Short spelling of Crosstown, cable and card | Origin 2000 era | I `OrOn2_SitePrep` ch02, ch05, appendix B (cable grounding warnings), `Onyx2_Rack_OG` ("XTOWN cable"), `DevDriver_PG` ch04, ch12, ch13 (a VME option cabled to an XIO slot); U `icrash` (a VME-over-Xtown string) |

Grades. Crosstown, KTOWN, Ktown2, Crosstown2, Xtown2, Xtown: established. The
first audit's statement that ktown is unconfirmed in public OS source is
reversed: it is in shipped IRIX kernel text and a shipped script.

- **Unknown:** what the K in KTOWN stands for. Test: a Kona or InfiniteReality
  hardware guide (none reached).

### 3.14 Bricks that carry the chips

Module types are SGI's (K board-type enumeration, F brick-type strings: Ibrick,
IXbrick, Pbrick, PEbrick, PXbrick, Xbrick, Nbrick, CGbrick).

| Brick | Interconnect content | Source |
|---|---|---|
| C-brick | Bedrock; NUMAlink (NI) and Crosstown2 (II) ports | M 007-4240-002 p125 |
| I-brick | Xbridge, two Crosstown2 (Xtown2) ports | M 007-4264-001 p2; I `L1andL2Con_UG` ch03 |
| IX-brick | three PIC, two Xtown2 ports, six PCI-X buses | M 007-4377-001 p67 |
| P-brick | Xbridge (three or six, see 3.7), two Crosstown2 (Xtown2) ports, 12 PCI slots | M 007-4240-002 p140; I `Origin_3K_OG` ch06 |
| PX-brick | three PIC, two Xtown2 ports | M 007-4377-001 p78 |
| X-brick | Xbridge, two Crosstown2 ports, XIO slots | M 007-4240-002 p152; I `Origin_3K_OG` ch07 |
| V-brick | Xbridge, V12 graphics boards | I `Onyx_3K_OG` ch02 |
| G-brick | InfiniteReality pipes plus a Ktown2 | I `Onyx_3K_OG` ch01, ch02 |
| PE-, N-, CG-brick | types in the kernel and F `ip35prom`; chip content not read | K, F |
| XBOX, PCI shoebox | Origin 2000 PCI expansion with an "xbox dual xtown" card | F `ip27prom` ("XBOX Flashprom", "HAROLD(PCI SHOEBOX)"); I `DevDriver_PG` |

A brick letter does not imply a chip outside this table.

---

## 4. Name audit, corrected

| Name | SGI term? Where | Grade |
|---|---|---|
| XIO | trademark; manuals, panel labels, L1 command | established |
| Crosstalk | manuals, firmware text | established |
| XTalk / xtalk | firmware text; hardware-graph paths in manuals | established |
| widget | manuals, headers | established |
| Little Window (LWin), Big Window (BWin) | manuals | established |
| SWIN | shipped software; Linux, OpenBSD | established as a software prefix; expansion unknown |
| LLP, credit | manuals, firmware | established |
| CrayLink, NUMAlink | firmware (1998, later), manuals | established |
| XBOW / Crossbow | manuals, firmware, headers, `hinv` | established |
| XXBOW | shipped 6.5.30 header; Linux, OpenBSD; no kernel or firmware | name established, meaning inferred |
| PXBOW | shipped 6.5.30 header, one name in the IP35 kernel; Linux, OpenBSD | name established, meaning inferred |
| Bridge | manuals, firmware, `hinv` | established |
| Xbridge | manuals, firmware, L1 text ("XBridge") | established |
| PIC | 007-4377-001; shipped header and kernel | established; widget adjacency unknown. Settling test: the widget numbers that published hinv or hardware-graph captures of a PIC brick give its three PICs (007-4377-001 p67 says three make an IX-brick or PX-brick); the numbers in several captures show which widgets are adjacent |
| TIO, TIOCP | shipped 6.5.30 IP35 kernel; Linux, OpenBSD | name established; expansion unknown |
| TIOCA, TIOCE | Linux, OpenBSD only | established as OS names |
| HEART | OCTANE Technical Report; firmware; headers | established |
| Hub | manuals, firmware | established |
| Hub2 | one PROM message and a build-flag name | inferred (revision 2 and later) |
| Hub II | no such chip; II is the I/O interface block | established (negative) |
| Bedrock | manuals, firmware | established |
| SHub | Altix manual 007-4520-007; Linux; one IRIX name | established |
| Junkbus | L1 text | established |
| Crosstown, KTOWN, Ktown2, Crosstown2, Xtown, Xtown2 | manuals, kernel archive, script | established |
| HQ4, XG | shipped headers | name established; expansion unknown. Settling test: search the Library for the spelled-out names in the graphics manuals and board guides; no held source spells either out, so until one does the expansion stays unknown |
| UXHEART, GHBridge, HXBOW | one IP30 PROM only | unknown. A byte search of the held firmware images, the IP30 and IP27 kernels, the IP32 and IP35 kernel objects and `sbin/` finds the three strings in `IP30prom.bin` alone. Settling test: a second occurrence in another PROM revision, a shipped manual or a public PROM listing; absent that, no software dependency is recorded |

## 5. What this means for the datasheets

- The Crosstalk datasheet (`docs/crosstalk-link.md`) may use PXBOW, XXBOW, PIC,
  XTalk and KTOWN as SGI names. It should write "Little Window" in hardware
  text and name SWIN only to point at the Linux macro prefix.
- It should call XXBOW and PXBOW "the crossbow function of Xbridge and of PIC"
  only with the inferred label from 3.5 and 3.6.
- It should not treat the two PIC widgets as consecutive, or "Hub2" as a
  defined revision range, without new evidence.
- Any claim about TIO or SHub register layout is a Linux claim, not an IRIX
  one.

## 6. Not reached

- A published Crosstalk specification page for the manufacturer field and for
  the expansions of HQ4, XG, GSN, TPU, TIO, the Bedrock LB and XB blocks, and
  SWIN.
- SGI's own ASIC specifications for PIC, Bedrock and Crossbow as readable
  pages.
- Octane service documentation for the Xtown diagnostic cards.
- `io6prom.img` text (it may be packed) and the Everest-era names in the IO4
  firmware; that is a different bus.
