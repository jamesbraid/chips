# Onyx 3000 graphics bricks: where the pipe and the V12 sit

Three questions about the Onyx 3000 family (IP35 platform, Bedrock hosts, Xbridge I/O bricks): which Crosstalk
widget an InfiniteReality pipe in a G-brick answers at and what is between it and the compute brick, what a
V-brick (InfinitePerformance, V12 boards) looks like to a host, and what keyboard the graphics console uses. Labels follow [AGENTS.md](../AGENTS.md):
**established**, **inferred**, **unknown**. Manuals are cited by SGI document number and printed page. The
Onyx 3000 graphics owner's guide is 007-4264-002 (November 2001, the revision that adds the V-brick). The family
reference guide is "SGI 3000 Family Reference Guide". Binaries are named by IRIX release, object and routine.

Sources not used: no IRIX source tree, no emulator's topology or behaviour, and none of the Bridge, XBridge or
Crossbow specification scans. The classroom "SGI 3000 Series Systems Cabling" course book (document 108-xxxx-PR2,
preliminary, 2000) was text-searched for G-brick, V-brick, pipe, Ktown and InfinitePerformance and has no text
about either brick; it is not cited.

## The one real capture

Public forum post "Onyx 3000, 12x600MHz, 6GB, dual-pipe IR3 with HD-GVO", Nekonomicon, thread 16719632, posted
2008-12-05 (<https://nekonomicon.irixnet.org/forum/14/16719632/1.html>): an Onyx 3000 with three C-bricks, an
I-brick, an X-brick, two routers and a two-pipe InfiniteReality3 G-brick; `hinv -vm`. Reduced to the lines that
matter here:

| Location | Boards listed |
|---|---|
| `/hw/module/001c07/node` | `IP35` node board, with `cpubus/0` and `cpubus/1` `IP35PIMM` boards |
| `/hw/module/001c07/Ibrick/xtalk/11` | `GE16-4` (030-1398-002) and `KTOWN2` (030-1593-001) |
| `/hw/module/001c07/Ibrick/xtalk/14` and `/15` | `IBRICK` (030-1557-007), the same barcode at both |
| `/hw/module/001c10/node` | `IP35` node board and two `IP35PIMM` boards |
| `/hw/module/001c10/Xbrick/xtalk/11` | `GE16-4` (030-1398-002), second pipe; no `KTOWN2` line |
| `/hw/module/001c10/Xbrick/xtalk/12` | `HIPPI_SERIAL` (an XIO card) |
| `/hw/module/001c10/Xbrick/xtalk/14` and `/15` | `XBRICK` (030-1710-002), the same barcode at both |
| `/hw/module/001c13/node` | a third `IP35` node board, no I/O brick |
| `/hw/module/001r20/router`, `001r26/router` | `ROUTER` |

Each C-brick has one `node` with two PIMMs and CPUs on `Slot 0`, slices A to D (12 processors, three nodes).
**Established** for this machine. It is the only Onyx 3000 graphics inventory found: a search of the held public `hinv` captures and the
mailing-list and forum archives turned up no other G-brick or V-brick listing.

## Question 1: the G-brick pipe

| # | Claim | Grade | Basis |
|---|---|---|---|
| 1 | A pipe's widget is the pipe itself (XG, part `0xc102`), reported under the I/O brick's `xtalk` directory; the Ktown2 and the cable add no widget. | **established** that the pipe is listed at `<I/X brick>/xtalk/<n>`; the no-widget half is **inferred** from there being no separate line and no part of its own ([crosstown-ktown.md](crosstown-ktown.md)) | capture above |
| 2 | On an Onyx 3000 the pipe is at **widget 11** of the I-brick's Xbridge (pipe 0) and of the X-brick's Xbridge (pipe 1). | **established** for those two bricks on that machine (two pipes, two bricks, same number) | capture above |
| 3 | The brick's other cable connector (labelled `XIO 10`) faces the C-brick. No widget is listed at `xtalk/10` on either brick. | connector labels `XIO 10` and `XIO 11`: **established** for the V-brick (007-4264-002 pp55-56) and for the I-brick (007-4240-002 p135). That the label equals the widget number, and that `XIO 10` is the host-facing port: **inferred** from the absent `xtalk/10` line and the Onyx 350 pipe at `IXbrick/xtalk/10` | manuals, capture |
| 4 | Between the C-brick and the G-brick sits an I-, X- or N-brick: the G-brick's Ktown2 is cabled straight (one Xtown2 cable, no router, no further brick) to a Crosstown2 port of that brick, and the C-brick is cabled to that brick's other port. The C-brick never cables to the G-brick directly. | **established** as printed: the C-brick "connects through an I-, X-, or N-brick to the G-brick" and the Ktown2's two connectors go "to an I-, X-, or N-brick (which is in turn connected to a C-brick)" (007-4264-002 pp8, 10); Figures 1-4 and 1-5 (pp15-16) draw pipe 0 on an I-brick Xbridge port and pipe 1 on an X-brick's | manual, capture |
| 5 | A router is not in the XIO path. Routers carry NUMAlink between C-bricks; the Onyx 3200 with a G-brick is defined as having no routers (p22) and still reaches its pipe. In the capture the routers appear as separate `001r..` modules. | **established** (p22); the inference that no larger system puts one on the XIO path is **inferred** | manual, capture |
| 6 | An N-brick stands in for the I- or X-brick: "up to four C-bricks to up to four InfiniteReality pipes", four pairs of 800 MB/s connectors, no PCI or XIO slots (007-4424-001 p1, 007-4264-002 p27). Its widget number for a pipe is not known. | brick role **established** as printed; the pipe's `xtalk/<n>` on an N-brick **unknown** | manuals |
| 7 | The hardware graph puts the I/O brick and its pipe under the C-brick's module number (`001c07/Ibrick/...`), and the G-brick has no hardware-graph module of its own: the IP35 kernel's brick-type name table (type values 113 to 120) has Ibrick, Pbrick, Xbrick, Nbrick, PEbrick, PXbrick, IXbrick and CGbrick, and no G-brick or V-brick entry. | **established** (IRIX 6.5.30 IP35 `kernel.o`, `board_to_path`; capture) | binary, capture |
| 8 | A pipe needs its own C-brick: "requires both one C-brick and one I/O brick for each pipeline" (family reference guide p11); "each InfiniteReality graphics pipe requires a connection to a C-brick through an I/O brick" (007-4264-002 p26). The capture's second pipe is on a different C-brick (001c10). | **established** | manuals, capture |

### Smallest real configuration

**Established** (007-4264-002 pp15, 22; family reference guide p18). Onyx 3200 with a G-brick: one G-brick with
one InfiniteReality pipe (one Raster Manager, one geometry board, one display generator), one C-brick, one I-brick,
one power bay, no R-brick, one 39U rack, an L2 controller with its touch display (the L2 is "optional" but its
display is not). The cabling is C-brick to I-brick, I-brick to G-brick (Figure 1-4). It is the smallest because
the Onyx 3200 is the smallest Onyx 3000 model and the graphics guide calls this "the most basic InfiniteReality
single-rack graphics system".

The smallest **Onyx 3400** (the 3200's routed sibling) is one C-brick, one I-brick, two six-port R-bricks, one
G-brick in a second 39U rack, one pipe (007-4264-002 p26; family reference guide p23). **Established** as
printed. The G-brick 3400 minimum is one C-brick; the V-brick 3400 needs at least two (p28).

## Question 2: the V-brick

A V-brick is the 4U brick for InfinitePerformance: one or two V12 boards, each in two of four slots; a midplane
Xbridge ASIC; its own L1 on the power board; XIO connectors `XIO 11` and `XIO 10` (ports A and B, 800 MB/s) that go
to a C-brick (007-4264-002 pp10, 52 to 56). A system has G-bricks or V-bricks, not both (pp10, 21).
**Established** as printed. No capture of a V-brick, of an Onyx 3000 with InfinitePerformance, or of an Onyx 3000
V12 was found, so everything below that goes beyond the manual is not observed on a V-brick.

| # | Proposed fact | Grade | Basis |
|---|---|---|---|
| 1 | The V-brick is an XBridge. | **established** as printed: "The V-brick midplane contains an Xbridge ASIC that is the interface between the V-brick's two ports and the V12 boards" (007-4264-002 pp52, 54, Figure 2-14) | manual |
| 2 | ...with no PCI devices. | **inferred**: Figure 2-14 draws four board-slot links and no PCI device, and the V12 is an XIO widget (part `0xc013`, per the odsy repository), not a PCI card. The manual never says "no PCI". Whether the two Xbridge PCI-bridge heads (widgets 14 and 15) answer on an empty V-brick is **unknown**. The X-brick, which the capture shows, lists both heads (`XBRICK` records at `xtalk/14` and `/15`) and no PCI device | manual, capture |
| 3 | The V12 sits at port (widget) 8. | **unknown**. No manual, capture or shipped routine gives a V-brick widget. The candidates are **inferred**: the IP35 kernel carries a per-brick-letter widget-to-slot table, and for `X` and `Y` (X-brick, X2-brick) it maps slot 1 to widget 8, slot 2 to widget 12, slot 3 to widget 9, slot 4 to widget 13 (6.5.30 `kernel.o`, data table of 17-word records, one per letter; the X-brick capture shows an XIO card at widget 12). A V12 spans slots 1 and 2, so widget 8 or widget 12 for the first pipe and 9 or 13 for the second, **if** the V-brick midplane wires like an X-brick's, which nothing read says. Port 8 is one of two equally good candidates, not a finding. Widgets 10 and 11 are not candidates: they are the cable connectors | binary, capture |
| 4 | It attaches on node 1's XIO port. | **refuted as stated, established**: a C-brick has one node (one Bedrock, the `node` plus two PIMMs and slices A to D in the capture) and one external `XIO (II)` connector (007-4240-002 p125), so there is no "node 1" inside a C-brick. The V-brick is cabled straight to a C-brick's XIO connector, no I/O brick between (007-4264-002 p8, Figure 1-7 p20) and each pipe needs its own C-brick (p19). Which C-brick (node number) serves which pipe is assigned at discovery and is **unknown**. If "node 1" meant the second C-brick, that is not a property of the hardware | manual, capture |
| 5 | Its L1 answers with the X-brick board records. | **unknown**; X-brick is an **inferred** candidate. Facts: the L1 firmware (IRIX 6.5.30 `l1.bin`, 1.44.0) knows the board names `IBRICK`, `XBRICK`, `X2BRICK`, `PXBRICK` and `KCARL1` (G-brick) and no V-brick name (the sysco repository's L1 notes); its type letter `V` is the name "CG Voyager". The IP35 kernel's type-to-name routine (6.5.30 `l1_command.o`) turns `V` (and `0`) into "CGbrick", and its slot table gives `V` widgets 10 and 11 as slot 1. That is the CG-brick (the AGP, `.../CGbrick/xtalk/*/agp/*` graphics brick), not the InfinitePerformance V-brick, whose connectors are 10 and 11 and whose V12 is not on an AGP bus. So a V-brick cannot be told apart by the letter `V`; it must answer with one of the existing names, and by elimination the X-brick records are the likelier (same 4U chassis and midplane Xbridge, no PCI) but I-brick records are not excluded | firmware, binary |

What would settle each unknown: `hinv -vm` and the PROM `hinv -v` of an Onyx 3000 with a V-brick (the widget
number, the heads' board records, the hardware-graph brick name); `l1cmd` or `cfg v` from the rack's L2 against the
V-brick (the type letter); the V-brick midplane identity EEPROM name; a read of the V-brick Xbridge's per-link status
registers from the PROM monitor (widgets 8 to 15 alive and present bits). For the N-brick pipe widget: the same
listing from an Onyx 3000 with an N-brick.

## Question 3: the graphics console keyboard

A graphics console (`console=g`) needs a keyboard. The I-brick's base I/O (the board the Origin 3000 architecture
guide calls IO7) carries an IOC3, so the question is whether the keyboard is the IOC3's PS/2 port, a USB keyboard on
the I-brick's USB controller, or something on the G-brick or the L2. Sources: the Onyx 3000 graphics owner's guide
007-4264-002; the preliminary "SGI 3000 Series Systems Cabling" course book (108-xxxx-PR2); a public `hinv -mv`
of an Origin 3200 (two C-bricks, one I-brick each, PROM 6.210; forum thread 16723604, posted 2010-06-18, an Origin
3200 and not an Onyx, but the I-brick part number 030-1557-007 is the one the Onyx 3000 capture above lists);
the nested I-brick PROM inside the IP35 PROM 6.210 container (segment `io7prom`, load address
0xc000000013000000, sha256 `f903b3ce33b86c286f168ba43395f36a0073c24b1d4e703adce240f683b8c2d7`; addresses below
are into that segment) and the unpacked CPU PROM (segment `ip35prom`, sha256
`554924380189a03a512156af2faa38344902f251b49fd5c80c253c23ecaff27b`, address = 0x1fc00000 + offset); IRIX 6.5.30
IP35 kernel objects `ioc3_pckm.o` and `usb_pckm.o` (present, not read for this question). No IRIX source
and no emulator behaviour used.

| # | Claim | Grade | Basis |
|---|---|---|---|
| 1 | An Onyx 3000 graphics system's keyboard and mouse are USB devices plugged into the I-brick's rear panel. The owner's guide ships "a standard 101-key USB keyboard and a USB mouse", labels two I-brick rear-panel USB connectors "Keyboard" (1) and "Mouse" (2), and says "The SGI Onyx 3000 series graphics systems use USB to provide keyboard and mouse input". | **established** as printed | 007-4264-002 pp11, 76 to 77, Figure 3-10 |
| 2 | The I-brick panel has no PS/2 connector, and nothing separate (a keyboard and mouse adapter, a "KBM" option) is listed. The cabling book's I-brick connector table (Table 1-5, printed pp1-10 to 1-11) lists PCI slots, an SVGA-labelled DB9 ("Not Used. Used with future products."), serial (via U715, U714, U701), USB 1 and USB 2 (both from U702), 1394 (U707, U706), the two real-time interrupt jacks, ENET (U708 through U701) and the two XIO connectors; no keyboard or mouse connector. The graphics guide's I-brick figure and text name none either. Absence in two documents: not proof that no PS/2 pins exist on the board. | connector set **established** as printed; "no PS/2 anywhere on the board" **inferred** | 108-xxxx-PR2; 007-4264-002 |
| 3 | The USB controller is OHCI, behind the I-brick's Xbridge on widget 15, at IRIX PCI slot 5. The guide's own example hardware path is `/hw/module/001c13/Ibrick/xtalk/15/pci/5/usb/1/1/keyboard` (keyboard) and `.../usb/1/2/mouse`, "a USB controller at PCI slot 5 on the I-brick connected to C-brick 001c13". The Origin 3200 capture lists `USB controller: type OHCI` and a PCI adapter with vendor 0x11c1, device 0x5802 at PCI slot 5, the IOC3 (vendor 0x10a9, device 0x0003; `ef0` at pci 4) at slot 4 and a vendor 0x104c, device 0x8009 part at slot 6 beside `IEEE 1394 ... Type: OHCI`. That the 0x11c1:0x5802 part is the USB controller is **inferred** from the slot agreeing with the guide's path (the capture does not label it). Both USB connectors hang off one controller behind U702 on Xbridge port F, per the cabling book. | path and slot: **established** as printed; part identity **inferred** | 007-4264-002 p78; 108-xxxx-PR2 Table 1-5; capture |
| 4 | The IOC3 on the I-brick serves the serial port, the Ethernet and the real-time interrupt jacks (U701 in the cabling book's connector table), not a keyboard. | connection list **established** as printed; that its keyboard and mouse registers go unused is **inferred** from there being no connector | 108-xxxx-PR2 Table 1-5 |
| 5 | Nothing on the G-brick or the L2 provides the keyboard. The L2 and the rack's USB hub carry L1 and L2 traffic (USB signals between bricks), and the guide's USB local and remote extenders re-extend the I-brick's keyboard and mouse ports by up to 100 m; the G-brick pipe is an XIO widget with no keyboard function in anything read. | **inferred** (absence in the guides) | 007-4264-002 pp76 to 78; cabling book |
| 6 | The I-brick PROM understands both input paths. It carries KLCONFIG component names for the PS/2 route (`IOC3-PCKBD` at 0x130f4de8, name `ioc3pckm` at 0x13101350, `ioc3ms` at 0x13101378, with IOC4 equivalents at 0x130f4f18 and 0x131013e0) and for the USB route (`USB (OHCI interface)` at 0x130f4e90, `USB (KeyBoard)` at 0x130f4ea8, `USB (Mouse)` at 0x130f4eb8, `usbkbd` at 0x13101398, `usbms` at 0x131013a0); a USB HID keyboard driver (`usb_pckm_init():  init pckm driver ...` at 0x130fdce8) with the device paths `/dev/input/usb/keyboard` at 0x130fe370 and `/dev/input/usb/mouse` at 0x130fe388; the PS/2 device paths `/dev/input/ioc3pckm0` at 0x130f1f40, `/dev/input/ioc4pckm0` at 0x130f1f70, `/dev/input/ioc3ms0` at 0x130f1f88; the message `Cannot connect to keyboard -- check the cable.` at 0x130f8278; `pckbd_install: Keyboard/mouse not attached to an IOC3 or IOC4` at 0x13102470; and `graphics install: searching for pipe %d` at 0x1310a080. The CPU PROM carries `init_klcfg_usb: Cannot add component. Node %d` (0x1fc7e460) and `%s: No USB found on BASEIO.` (0x1fc84da8). | string and table presence **established**. Which of the two a given machine's console install picks, and on what test: **unknown** (no reference to these strings was resolved; the PROM reaches them through a literal pool the scan did not follow) | PROM images |
| 7 | The IRIX 6.5.30 IP35 kernel set has both drivers: `ioc3_pckm.o` and `ioc4_pckm.o` (PS/2 over IOC3 and IOC4) and `usb_pckm.o`, `usb_comp.o` and `usb.a` (the 6.5.22 IP35 install also lists an `ohci.o`). | presence **established** (file names); behaviour not read here | IP35boot object listing |

What the Onyx 3000 keyboard answer rests on: rows 1 and 3, printed in the owner's guide, plus a real I-brick listing
whose slot 5 agrees. A PS/2 keyboard on an I-brick is not something either manual describes.

What would settle the unknowns. Which input the PROM's graphics console binds when both could exist: resolve the
literal-pool references to the strings in row 6 (the install routine reached through `graphics install: searching
for pipe %d`) and read the branch that chooses `ioc3pckm0` over `usb/keyboard`. Whether the I-brick board has PS/2
pins on the IOC3: the IO7 schematic or a bare-board photograph, neither held. The identity of the 0x11c1:0x5802
part: a `hinv -vm` or `gfxinfo` of an Onyx 3000 printing the USB controller's PCI id, or the 007-4264-002 hardware
path of that machine's keyboard resolved against its `/hw` listing.

## Corrections this page makes

- [crosstown-ktown.md](crosstown-ktown.md) cites the capture above by its title and says "second public Origin
  3000 capture". The claim stands; the thread, date and the second pipe at `Xbrick/xtalk/11` are added there.
- The Sysco repository labelled L1 letter `V` "V-brick". The letter is the CG-brick (Onyx 4), see question 2 row 5.
