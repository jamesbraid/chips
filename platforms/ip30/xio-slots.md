# IP30 and Octane2: XIO slot letters and Crossbow widget numbers

Question answered: on an Octane (IP30) and an Octane2, which Crossbow widget number does each XIO slot (A, B, C, D) have, which widget does the PCI
module take, and which widget carries a second graphics head. Ratings follow [AGENTS.md](../../AGENTS.md): **established**, **inferred**,
**unknown**. Page numbers are printed page numbers. No IRIX source and no binary were read; the table rests on published manuals and on posted
`hinv` captures.

## The table

Slot letters are the labels on the XIO module. Seen from the back of the chassis, A is upper left, B upper right, D lower left, C lower right.

| Widget | What it is | Octane | Octane2 | Rating | Source |
|---|---|---|---|---|---|
| 8 | HEART ("system module, heart chip") | same | same | established | Octane2 Duo Installation Guide 007-4506-001, Table C-2, p. 63 |
| 9 | XIO slot **C** (lower right) | C | C | established | See "Printed sources" |
| 10 | XIO slot **D** (lower left) | D | D | established | See "Printed sources" |
| 11 | XIO slot **B** (upper right) | B | B | established | See "Printed sources" |
| 12 | XIO slot **A** (upper left) | A | A | established | See "Printed sources" |
| 13 | PCI module (three-slot PCI card cage) | yes | yes | established | See "Printed sources"; every `hinv -m` with a module prints `/hw/node/xtalk/13` `XTALKPCI` |
| 14 | not assigned | none | none | established | 007-4506-001, Table C-2, p. 63; Octane Technical Report, section 2.1, p. 2-3 (seven of the eight Crossbow ports are implemented: HEART, base I/O, PCI, four XIO) |
| 15 | onboard Bridge (base I/O) | same | same | established | 007-4506-001, Figure C-1 p. 62 and Table C-2 p. 63; every IP30 `hinv -m` prints `/hw/node/xtalk/15` `IP30` |

Widget 0 is the Crossbow itself (public Linux `arch/mips/sgi-ip30/ip30-xtalk.c`), inferred as the register block the other widgets sit behind.

### Printed sources for widgets 9 to 13

Five SGI guides print the same quadrant-to-number map, a figure plus, in two of them, the rule in words ("quadrant A = 12, quadrant B = 11,
quadrant D = 10, and quadrant C = 9"; "The PCI module ... Its number is 13"):

- OCTANE PCI Module Installation Guide 007-3547-001, Figure 3-1, p. 67.
- OCTANE Ultra SCSI XIO Option Board Installation Guide 007-3581-001, Figure 3-1 and the rule, p. 32.
- OCTANE IRIS 4-Port Fast Ethernet Adapter 007-3582-001, Figure 2-4 and the rule, p. 33.
- OCTANE Duo Installation Guide 007-3652-002, Figure D-1, p. 160.
- Octane2 Duo Installation Guide 007-4506-001, Figure C-1 p. 62 and Table C-2 p. 63, the only one that is for Octane2 and the one that also lists 8, 14 and 15.

The slot letters and layout (A and D on one side, B and C on the other) are on p. 12 of the OCTANE Dual Head Installation Guide 007-3531-002 and
p. 133 of the Octane Workstation Owner's Guide 007-3435-004. The Octane2 Workstation Owner's Guide 007-4207-002 (p. 108 and Figure 5-10, p. 116)
prints the letters for the Tri-Module but no widget numbers.

## Octane2 XIO Tri-Module: slots A/B, C, D

| Physical slot | Widget | Content | Rating | Source |
|---|---|---|---|---|
| A/B (top two quadrants) | **11** | the VPro graphics board. It spans A and B but only the connector in B carries the link, so it reports at 11 and nothing reports at 12 | established | 007-4506-001, p. 62 ("only uses the XIO connector in slot B ... XIO Slot ID 11"); 007-4207-002 p. 108 (VPro in "slot A/B", B is a daughterboard slot) |
| widget 12 (A connector) | 12 | unused when a VPro is fitted | inferred | follows from the p. 62 statement; no Octane2 capture shows a board at 12 |
| C | 9 | option board | established (number); observed (an XT-DIGVID digital video board in the capture below) | 007-4506-001, Table C-2 |
| D | 10 | option board or second VPro head | established (number); observed (a PCI-XTALK adapter in the capture below) | 007-4506-001, Table C-2 |
| PCI module | 13 | | established | as above |

An Octane2 dual-head system uses C and D for the second VPro board, which uses only the D connector and reports at **10** (007-4506-001, p. 63).
The Octane2 Dual Head Installation Guide 007-4493-001 (pp. 1 and 2) says the Dual Head XIO module has no free slot for another XIO board, so a
dual-head Octane2 has neither a PCI-XTALK adapter nor an option board.

## Octane XIO module: slots A, B, C, D

| Slot | Widget | Content | Rating | Source |
|---|---|---|---|---|
| A | 12 | primary graphics: SI, SE; SSI, SSE, MXI and MXE use A and D together | established for SI and MXI (captures), inferred for SSI/SSE | 007-3435-004 p. 133; 007-3531-002 p. 12; captures below |
| B | 11 | option board with flex cables to the graphics board (Personal Video); the second head when B is free; a V6 or V8 fitted as an upgrade | established | 007-3531-002 p. 12; OCTANE Dual Head: Secondary Head Information flier 007-3613-001; captures below |
| C | 9 | second head when B holds a flex-cable option board; other options | established | 007-3613-001 |
| D | 10 | other options; the second half of SSI and MXI, which does not report as 10 | established for the rule; observed for the number | 007-3613-001 ("Do not place a secondary graphics board in slot D"); captures below |

A double-slot MXI (hinv `GM20`) or EMXI (`MOT20`) reports one widget, 12, in every capture below. No SSI or ESSI capture lists a location, so 12 for
those is inferred.

## Second head, PCI module and PCI-XTALK adapter

- Octane second head: B (11), or C (9) when B holds a flex-cable option board, never D (007-3531-002 p. 12; 007-3613-001). A double-slot primary
  already uses D, so the second head is in B or C.
- Octane2 second head: widget 10, as above.
- PCI module: widget 13 on its own link. It uses no XIO slot, so it never competes with a head.
- PCI-XTALK adapter (single-slot, `hinv` name `XTALK_PCI`, part 030-1275): fits one XIO slot. In the one Octane2 capture below it sits at 10 (slot
  D) beside the module at 13 and a V12 at 11. No manual names its slot. The Origin 2000 "PCI shoebox" is another board.

## Captures

All are `hinv` text from posted listings; locations are the `/hw/node/xtalk/N` lines.

| Machine | Widgets seen | Source |
|---|---|---|
| Octane, 2x600 MHz R14000 | 15 IP30; 13 XTALKPCI; 12 MOT10; 11 EVO; 10 MSCSI; 9 MOT10 (all five at once) | Usenet comp.sys.sgi.admin, 2004-01-10, `<pan.2004.01.10.21.17.41.116971@j3iss.com>` |
| Octane, 2x250 MHz R10000 | 15; 13 XTALKPCI; 12 MOT20; 11 EVO; 9 MOT10 | Usenet `<3F9C83FE.1632F316@comcast.net>` |
| Octane, 2x250 MHz R10000 | 15; 12 MOT20; 11 GM10 (a second head) | Usenet `<WV%C8.46771$2G1.14973489@typhoon.nyroc.rr.com>`, 2002-05-11 |
| Octane, 2x250 MHz R10000, two ESI heads | 15; 13 XTALKPCI; 12 MOT10; 11 EVO; 10 MOT10 | Nekonomicon forum 14, thread 16726610 |
| Octane, 2x195 MHz, MXI | 15; 12 GM20 | Nekonomicon forum 14, thread 16972 |
| the same Octane with a V6 instead | 15; 11 ODY32; nothing at 12 | Nekonomicon forum 14, thread 16972 |
| Octane, 2x300 MHz R12000, EMXI | 15; 13 XTALKPCI; 12 MOT20 | Nekonomicon forum 14, thread 12262 |
| Octane with a V8 | 15; 11 ODY128 | Usenet `<3FEF80F1.F00A6CFE@comcast.net>` |
| Octane2, 2x600 MHz R14000, V12 | 15; 13 XTALKPCI; 11 ODY128VERSIONB; 10 XTALK_PCI; 9 XT-DIGVID | https://just.graphica.com.au/tips/what-is-inside-that-box-sgi-hinv/ ("Octane2 with dual 600 MHz CPU and V12") |

Every VPro capture reports at 11 and no SI or MXI capture reports anywhere but 12 (as a primary).

## The "9 to 12" and "10 to 13" readings

A widget appears in `hinv -m` only when a board sits behind it. The Octane captures with the second head in C show 9 to 13 (the first row above shows all
five), while the ones with C empty show 10 to 13 or 11 to 13, and a plain Octane2 shows 9, 10, 11 and 13. These are subsets of one assignment: XIO slots
9 to 12 and the PCI module at 13. The printed guides settle it; the captures only agree.

## Public driver expectations

- Linux `arch/mips/sgi-ip30/ip30-xtalk.c` (db2ddb87143519e20a95aa36c60b36107b736a58): HEART is widget 8 and the base-I/O Bridge is 15, matching Table C-2. It
  probes widgets 15 down to 9 (so it would also try 14) and skips any whose Crossbow link-alive bit is clear. Inferred as the driver's reading.
- OpenBSD `sys/arch/sgi/sgi/ip30_machdep.c` (`sgi-is-alive-at-7.9`): widget range 8 to 15, same link-alive test; graphics heads are numbered by
  walking widgets from 15 down, so the highest widget is head 0. Inferred.
- Neither driver knows the slot letters.

## Unknown

- SSI, SSE and ESSI: which widget they report. No capture with locations. An `hinv -m` from such a board would settle it.
- PCI-XTALK adapter in a slot other than D, or on an original Octane: no capture. An `hinv -m` with the adapter in A, B or C would settle it.
- A board at widget 12 on a VPro Octane2: inferred unused; an Octane2 `hinv -m` showing one would settle it.
- A second head in D on an Octane: the two-ESI capture above shows one at 10, which the flier forbids. A second capture would show whether it is a one-off.
- The order in which the IP30 PROM probes widgets 9 to 15 was not examined. A trace or disassembly of the PROM scan would settle it.
