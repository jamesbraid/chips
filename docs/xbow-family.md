# Crossbow (XBOW), XXBOW and PXBOW: the XIO switch family

What each of the three switch parts is, which machines carry it, how software tells
them apart, the register set software drives, and how a port comes up. It is a
hardware description of the switch only; the host ends (HEART, Hub, Bedrock), the
widgets behind the ports, and the shared widget register block are covered in
[crosstalk-link.md](crosstalk-link.md), and the per-register evidence is in
[`chips/xbow/README.md`](../chips/xbow/README.md) and its census.

Labels follow [AGENTS.md](../AGENTS.md): **established** (a binary read in full, a
published page, or a public driver file), **inferred** (reasoned; the reasoning is
given), **unknown** (with the test that would settle it). Everything is in this
file's author's words. Nothing here is taken from the proprietary Crossbow ASIC
Specification: reset values and link-training behaviour are listed as unknown rather than
reproduced from it.

Names, with the source of each:

| Name | Used by | Kind |
|---|---|---|
| Crossbow, `xbow` | the shipped header's own comment ("crossbow"); `xbow` in every kernel, PROM and driver symbol; `hinv` prints "XBOW" | SGI's own, hardware and software |
| XIO, Crosstalk, widget | Theory of Operations 007-3439-002 (printed p17, p53) | SGI manual |
| Xbridge | A separate chip, the Origin 300 I/O bridge (007-4365-002 p10) | SGI manual |
| PIC | "PCI interface chip", the IX-brick part (007-4377-001 p67) | SGI manual |
| XXBOW | Shipped IRIX 6.5.30 crossbar header glosses part `0xd000` only as "Xbridge"; the public Linux IP35 file says "Xbow in Xbridge"; OpenBSD calls it "XXBow" | header and driver name |
| PXBOW | Same header, part `0xd100`, glossed there "PIC"; OpenBSD calls it "PXBow" | header and driver name |

PXBOW and XXBOW were not found in the SGI manuals searched; they are software-header
and driver names. Whether SGI used them in hardware documents is **unknown**; the
test is a page-by-page read of the Origin 300 and Origin 350 service manuals.

## 1. Three parts that answer at widget 0

All three present the Crosstalk widget identification word at offset 0 of widget 0
(32-bit access at +4; bits 31:28 revision, 27:12 part, 11:1 manufacturer, bit 0
always set). The part and manufacturer values are what distinguish them.

| Part (bits 27:12) | Manufacturer | Name | Where | Grade |
|---|---|---|---|---|
| `0x0000` | 0 | Crossbow, XBOW | Octane and Octane2 motherboard; Origin 2000 and Onyx2 midplane (two per deskside midplane); the Origin 200 GIGAchannel expansion | established |
| `0xd000` | 0 | XXBOW, the crossbar of the Xbridge (Linux: "Xbow in Xbridge") | Origin 300, Fuel (a single Xbridge is the node's I/O chip) | part: established; "crossbar section of the Xbridge": established only as Linux's comment, the rest inferred; machines: see below |
| `0xd100` | 0 | PXBOW, the crossbar face of the PIC | Origin 350, Onyx 350, Tezro (Bedrock-based, PIC-based I/O) | part: established; "this is a PIC crossbar face": inferred |

Sources for the table:

- The Linux ia64 SN xtalk header and the IP35 MIPS xtalk file define the same three
  part numbers (`0`, `0xd000` "Xbow in Xbridge", `0xd100`, the last commented "used in O350
  (IP35)"); the IP35 file registers all three against one probe routine, named "XBow",
  "XBridge XBow" and "PIC XBow". Established (public Linux).
- The shipped IRIX 6.5.30 crossbar header defines the same three, with manufacturer 0
  for each, and tests them with `IS_XBRIDGE_XBOW` and `IS_PIC_XBOW`. Established. That one
  release wraps the Crossbow and Xbridge numbers in a simulator-only conditional (`0xc111`,
  `0xc112`); the non-simulator branch is the real silicon. Established (header read).
- OpenBSD `xbowdevs` lists `XBOW` 0x0000, `XXBOW` 0xd000, `PXBOW` 0xd100 under vendor 0.
  Established.
- The IP27, IP30 and IP35 `xbow.o` objects of IRIX 6.5.30 all register their driver for
  exactly three widget identities, in this order: part `0xd100`, part `0xd000`, part `0`,
  each with manufacturer 0 (the driver's initialisation routine, disassembled in the IP35 object). Established.
- The 6.5.30 header annotates two workarounds against the PIC part: one about the presence
  indication for widget `0xf`, one about processor access to the PIC's own registers, both
  tied to the PIC revision field. Established as header content; what the PIC hardware does
  is unknown. The same shape appears in the code: see PXBOW below.

### Where each part is found, by machine

| Machine (board) | Part | Revision code seen | How seen | Grade |
|---|---|---|---|---|
| Octane, Octane2 (IP30) | `0` | PROM banner "Xbow ASIC: Revision 1.2", "1.3", "1.4" in public boot captures (5, 5, 7 held); an Octane2 identification word read `0x5000_0001`, code 5, whose banner is 1.4 | public boot captures; PROM Command Monitor read, 2026-10-02 | established |
| Origin 2000, Onyx2 (IP27) midplane | `0` | `hinv -v` prints "ASIC XBOW Rev 2" (once), "Rev 4" (twice) and "Rev 5" (three times) "on midplane of Module 1" in public captures | public `hinv` captures | established that these codes occur; what each silicon stepping fixed is unknown |
| Origin 200 base (IP29) | none; widget 0 answers with the Bridge identity | | Origin 200 captures and OpenBSD's probe | established |
| Origin 200 GIGAchannel | `0` (external Crossbow on the expansion path) | not captured | | inferred from the product's expansion path; revision unknown |
| Origin 300 (IP45), Fuel (IP34) | `0xd000` | "ASIC XBOW Rev 2, on CBrick", printed beside "ASIC BRIDGE Rev 2"; OpenBSD prints "XXBow revision 2" with Xbridges at widgets 14 and 15 | public `hinv` and OpenBSD captures | revision: established; part number: established by OpenBSD's own match |
| Origin 350, Onyx 350, Tezro (IP53, IP35 platform) | `0xd100` (inferred) | "ASIC XBOW Rev 3, on CBrick" in multiple public captures | public `hinv` captures | revision: established; part: the PROM accepts parts `0`, `0xd000`, `0xd100` at widget 0 and the captures do not print the part, so which one is inferred |
| IX-brick (and, by the same PIC generation, PX-brick) | PIC (`0xd102`/`0xd112` heads); crossbar part not read | | 007-4377-001 p67 (three PICs in an IX-brick) | the crossbar part of these bricks is **unknown**; test: a verbose PROM capture of an IX-brick |
| I-brick, V-brick (Origin 300/3000 generation) | Xbridge (`0xd002`) at widget 0, not a PIC | | the repo's L1 controller datasheet; OpenBSD's `xbridge.c` header comment puts Origin 300/3000 on the Xbridge and Origin 350/3500 on the PIC | the Xbridge generation is established; no crossbar part was read there |

The IP53 identification line is covered by the Tezro PROM discovery note in
[questions/tezro-widget-11.md](questions/tezro-widget-11.md): the PROM runs its crossbar
check for parts `0`, `0xd000` and `0xd100` at widget 0 of the node's XIO port, and parts
`0xc002` and `0xd002` there mean a Bridge directly at widget 0.

## 2. Revision codes

Established from the IRIX 6.5.30 header and objects:

| Code (bits 31:28) | Header name | `xbow.o` name table | Linux header |
|---|---|---|---|
| 1 | 1.0 | "1.0" | `XBOW_REV_1_0` |
| 2 | 1.1 | none (no entry for code 2) | `XBOW_REV_1_1` |
| 3 | 1.2 | "1.2" | `XBOW_REV_1_2` |
| 4 | 1.3 | "1.3" | `XBOW_REV_1_3` |
| 5 | 2.0 | "2.0" | `XBOW_REV_2_0` |

The IP30 PROM banner uses a different labelling; see the code 5 note below.

- The attach routine builds `revision | (part << 4)`, prints a down-revision warning only for a
  value below 2 (part 0, revision 0 or 1), and then reaches the name table only on that
  warning path. Its table also compares the values `0xd0001` and `0xd0002` and labels them
  "Xbridge 1.0" and "Xbridge 2.0". Because the test is below 2, only revisions 0 and 1 of
  part 0 can reach those arms, so the arms for codes 3, 4 and 5 are unreachable. Established
  (the attach routine of the IP27/IP30/IP35 `xbow.o`, read in full by the census, except
  that the exact print path and the IP27/IP30 variants were not re-read in full on this
  pass). Why the Xbridge arms are there is unknown.
- Nothing in the attach path rejects a part or revision; the driver attaches to whatever
  answers. Established.
- The header defines `XXBOW_PART_REV_1_0` and `XXBOW_PART_REV_2_0` as part `0xd000` with
  revision 1 and 2. Established. Real Origin 300 and Fuel captures show revision 2.
- **Labels disagree on code 5, and the disagreement is settled.** The header and kernel call
  it 2.0. The IP30 PROM banner shows 1.4 for the same code on an Octane2. The PROM builds
  its label from the raw code: for any code up to and including 5 it prints major 1 and
  minor code minus 1; only for codes above 5 does it print major 2 and minor code minus 5.
  Code 5 therefore prints 1.4, codes 3 and 4 print 1.2 and 1.3, and 2.x labels would start
  at code 6 as 2.1; the PROM never prints 2.0. Established from the 4.17 PROM image's two format strings and the Octane2 banner capture. The PROM's
  comparison is off by one against the kernel's table, so this is a labelling slip in the
  PROM, not a different naming of the same silicon. The register behaviour follows the raw
  code, not the label.
- Code 5 is the first revision with the reset fences and the resource lock (section 4).
  Established by measurement on one Octane2 (below); that the registers are absent on
  earlier codes is not independently shown.
- The Linux header and the header's `XBOW_WAR_ENABLED` test whether a workaround applies
  by `1 << revision` against a bitmask. Established as code; the workaround list for the
  Crossbow itself is empty in the shipped header, and for the PIC it is "all revisions".
  The PIC-part comments in the header are the only workaround text.
- SGI chip or board order numbers (030-xxxx) for the Crossbow ASIC itself were not found
  in the manuals searched (007-3439-002, 007-3499-001, 007-4114-001, 007-4365-002,
  007-4377-001). **Unknown.** The test is the Octane and Origin 2000 service parts lists.

## 3. What each part is

### Crossbow (part 0)

An eight-port XIO crossbar. Established (007-3439-002, printed p53 and p84): it
expands a node's single XIO port; six ports serve I/O devices and two serve node boards
(hosts); at least one port connects to a host and at most two connect to each host;
every port runs the XIO protocol at 8 or 16 bits with rate-matching buffers; there are two
Crossbows on a deskside Origin 2000 midplane, one shared by nodes 1 and 3 and one by nodes
2 and 4 (p9), and the six I/O ports are statically split between the two hosts, with the
second host able to take them all over if the first is out of service (p85).

Software view: the chip itself is widget 0; its eight link controllers are decoded as
widgets 8 through 15 (the "ports"). Widgets 1 to 7 are not ports. The crossbar does no
address translation; widgets address each other by widget number in the packet header
(shared Crosstalk addressing in [crosstalk-link.md](crosstalk-link.md)).

**Two port vocabularies exist.** The manual's block diagram labels the two host-facing
connections "host port 1" and "host port 3" and leaves the other six unnumbered
(007-3439-002 p85); the registers and the software number the same eight links 8 to 15.
No source read here ties a physical connector to a link number; do not infer one.
Unknown; test: a midplane continuity map or a PROM trace that prints both.

### XXBOW (part `0xd000`)

The crossbar of the Xbridge, the Origin 300 / Fuel I/O chip. Established that
the part number `0xd000` is used for it (the shipped header glosses it only "Xbridge"; the
public Linux IP35 file says "Xbow in Xbridge"). That it is a crossbar section inside the
Xbridge rather than a separate die is inferred from those glosses and the repo's component
taxonomy, so the Origin 300 having no separate crossbar chip is inferred. The two PCI
bus sections appear as widgets 14 and 15 (OpenBSD attaches `xbridge` at widgets 14 and
15 on an Origin 300 and calls them part `0xd002`), the Bedrock is port `0xa`
(OpenBSD and the Fuel and Origin 300 captures), and the crossbar is widget 0.
Register layout is the Crossbow's with the Xbridge-only additions the header marks
(section 4: status and control bits, and the fence and lock block). Whether the crossbar section has the full eight-link register set or only
the links to its two bus sections is **unknown** (the header does not distinguish);
test: read link registers 8 to 13 on an Origin 300 through the PROM monitor and see which
decode.

### PXBOW (part `0xd100`)

The crossbar face found at widget 0 on Bedrock-based machines whose I/O is PIC. What is
established is software behaviour only:

- The kernel and PROM treat widget 0 as a crossbar when its part is `0`, `0xd000` or
  `0xd100` (IP35 PROM `0x1fc66c48` path; the driver's initialisation routine).
- Link `0xf` is special-cased on part `0xd100`: the kernel's widget-presence routine in all
  three `xbow.o` builds returns "present" for port 15 without reading the link's auxiliary
  status, when the part is `0xd100` and the manufacturer is 0. The IP27 and IP35 PROM
  routines (`0x1fc44bbc`, `0x1fc4f3ec`) do the same for the status and auxiliary bits
  but test only the part. Established (all read in full). It matches the header's
  workaround note about widget `0xf` presence on a PIC-class part.
- On the Tezro the Bedrock is port `0xa`, one PIC is port `0xb` (part `0xd102` or
  `0xd112`, manufacturer `0x24`) and another is port `0xf`; port `0xf` is the one the
  waiver covers. From the PROM discovery trace and public deskside captures; inferred
  rather than established, because the hub-link pairing for the Bedrock family pairs
  ports `0xa` and `0xb`, so that `0xb` is a PIC and not the peer hub link was not
  independently confirmed. OpenBSD says one PIC is a single chip with two widget heads and
  nothing read says which two ports a PIC's heads occupy.
- The PROM's own checks of widget 0 (identity, `0xdeadbeef` into the read-only error
  address registers, then the clearing alias, then the status read-back) run for part
  `0xd100` and require the widget 0 status read to return the requester's widget number
  in bits 9:6 on an integrated crossbar. Established as PROM behaviour; the register-level
  detail is in [`chips/xbow/README.md`](../chips/xbow/README.md).

Not established: whether PXBOW is a separate die, a section of the PIC, or a reused
Crossbow core; whether it has all eight link controllers; whether it has the fences and
lock. No register offset is specific to part `0xd100` in any consumer read (the census has
two `pxbow` rows, slots `0x0` and `0x138`). **Unknown**; test: a register dump of widget 0
from an Origin 350 PROM monitor, reading the reserved range `0x78..0xc8` and every link set.

## 4. Register map

The identification, status, control, interrupt, error and per-link registers are common to
all three parts as far as any consumer shows; the fence and lock block is not (see below).
Slot offsets are on an 8-byte
grid; software issues a 32-bit access at slot + 4 (the data sits in the low, big-endian
second word), which is why the shipped header names registers at +4. Every access in every
scanned routine in the IP27, IP30 and IP35 kernel objects and the four PROMs is a 32-bit
load or store at slot + 4. Established.

### Widget 0 (the switch itself)

| Slot | Register | Access in software | Grade |
|---|---|---|---|
| `0x00` | Identification | read | established |
| `0x08` | Status | read, printed raw | established |
| `0x10`, `0x18` | Error address, upper (47:32) and lower (31:0) | read; the PROM writes `0xdeadbeef` to the lower on purpose and expects a register-access error | established |
| `0x20` | Control | the kernel writes `0x24` (bits 5 and 2) at attach | established |
| `0x28` | Packet timeout | read for printing only | inferred (shipped header names it the request timeout) |
| `0x30`, `0x38` | Interrupt destination upper and lower | written by the interrupt layer (vector 31:24, target widget 19:16, address 47:32 in 15:0; address 31:0) | established |
| `0x40` | Error command word | read; a write re-arms capture (the kernel writes 0 right after reading) | established |
| `0x48` | LLP control | read for printing only | inferred |
| `0x50` | Status, read-and-clear alias | read once per interrupt | established |
| `0x58` | Arbitration reload | read for printing only | inferred |
| `0x60`, `0x68` | Performance counters A and B (bits 22:20 link select, 19:0 count) | read and written | established |
| `0x70` | NIC (one-wire identity line) | untouched | unknown; test: a PROM read of it on an Octane |
| `0x78` | Widget 0 reset fence | code-5 chips only | existence and read value measured on one Octane2; reset value unknown |
| `0x80`..`0xb8` | Reset fences for links 8..F | as above | as above |
| `0xc0`, `0xc8` | Resource lock; lock clear | as above | read value measured on one Octane2; acquire and release inferred |

Fields of the status word, established from the shipped header (a field list, not a
register-by-register copy): link-interrupt request bits 31:24 for links F down to 8, a
widget 0 request at 23, register-access error at 5, Crosstalk packet error at 2, a
connection-timeout field at 1, multiple-error at 0. Control carries the matching
interrupt enables at 5, 2 and 1 (the Crossbow set). The shipped header and Linux both mark
further bits as Xbridge-only: in status, the source-ID field at 9:6, a receive-timeout error
at 4, an arbiter-timeout error at 3 and the connection-timeout error at 1; in control, the
matching interrupt enables at 4 and 3, a widget-0 timeout counter enable at 6 and a
watchdog enable at 7. The Crossbow itself reserves them. Established as header content,
so an XXBOW implementation needs these in addition to the Crossbow set. Whether a code-5
Crossbow reports the connection timeout is **unknown**; test: provoke a connection timeout
on code 5 and read status.

Fence and lock layout: one fence register per link plus one for widget 0, stride 8,
starting at slot `0x78`; the lock at `0xc0` and its clear alias at `0xc8`. The shipped
and Linux headers define these only inside Xbridge-only blocks, so for the Xbridge
(XXBOW) they are established as header definitions. Nothing in a header or consumer shows
them on a Crossbow or on PXBOW: the only evidence they exist on a Crossbow is the single
Octane2 measurement, and whether PXBOW has them is unknown (section 3). On that Octane2
(identification word `0x5000_0001`), read from the PROM Command Monitor on 2026-10-02:
widget 0 fence `0xf7`, link F fence `0xf7`, lock `0`. No bus error. Established as a
measurement of one machine. Bit 3 of each fence is clear; bit 3 corresponds to link
`0xb`. That this is the graphics port is unconfirmed: other captures place Octane
graphics at widget `0xd`. Whether the PROM cleared that bit, or the power-on value
already had it clear, is unknown, as is the power-on fence value.

### Per-link set (one per port, eight of them)

The set for link *n* (8 to 15) starts at slot `0x100 + 0x40 × (n − 8)`. Every accessor in
every build builds the offset as `(port & 7) << 6`. Established.

| +Slot | Register | Software use | Grade |
|---|---|---|---|
| `+0x00` | Input buffer flush | not reached by any scanned routine | unknown role in software; header names it |
| `+0x08` | Link control | attach: replaces the word by `(old & 0xfffffe2f) \| 0x3002b` for each alive, present port; link reset saves and restores it | established |
| `+0x10` | Link status | bit 31 is "alive"; error bits printed | established |
| `+0x18`, `+0x20` | Arbitration upper (sources 8..B), lower (C..F) | four 8-bit lanes: a 5-bit guaranteed-bandwidth count in 4:0, a 3-bit round-robin weight above | established |
| `+0x28` | Link status, read-and-clear alias | read to consume errors | established |
| `+0x30` | Link reset | write, value 0 | established |
| `+0x38` | Link auxiliary status | retry counters, widget present, width | established |

Field layout, taken from the shipped 6.5.30 header and confirmed by the strings and tests
in the kernel object:

- **Link control**: 31 interrupt when the link comes alive; 29:28 performance monitor mode;
  27:25 input buffer level; 24 force eight-bit mode; 23 force a bad link micropacket;
  22:18 widget credit; 17 illegal destination; 16 input overallocation; 8 bandwidth
  allocation; 7 receive-count overflow; 6 transmit-count overflow; 5 maximum transmit
  retry; 4 receive error; 3 transmit retry; 1 maximum request timeout; 0 source timeout
  (all the bits from 17 downward are interrupt enables; bit 2 unused). Established. What
  the kernel sets at attach: bits 17, 16, 5, 3, 1, 0 on; 8, 7, 6, 4 off; 22:18 untouched.
- **Link status**: 31 alive; 18 multiple error; 17 illegal destination; 16 input
  overallocation; 15:8 bandwidth-allocation error source, one bit per port; 7 receive-count
  overflow; 6 transmit-count overflow; 5 maximum transmit retry; 4 receive error; 3
  transmit retry; 2, 1, 0 packet timeouts. The shipped 6.5.30 header names bit 2 a
  destination packet timeout, bit 1 a connection packet timeout, and bit 0 a source packet
  timeout; the Linux header reserves bit 2, and the kernel's interrupt handler tests none
  of bit 2 and prints "Maximum Request Timeout" for bit 1 and "Source Timeout Error" for
  bit 0. Established as naming. Whether any consumer acts on bit 2 is **unknown**: the
  shipped fault-analysis object keeps its crossbar rules in tables not decoded here.
- **Link auxiliary status**: 31:24 receive error count; 23:16 transmit retry count; 15:8
  timed-out source (one bit per port); 6 link failure mode; 5 widget present; 4 eight-bit
  mode (0 = sixteen). Established. The kernel sums bits 31:24 and 23:16 into two running
  totals, warns when either counter overflows, and warns on any bit in `0x7fffffe7`.

### The error path

Established from the kernel's crossbar error interrupt handler (read in full):
it reads control, the clearing alias, error command word, error upper and lower, writes 0
to the command word at once, forms the 48-bit address, takes the source number from
command bits 27:24, and for a link-request bit with the illegal-destination flag compares
that source with the port; equal means a DMA error blamed on the widget attached to that
port. The command word fields (shipped header): destination ID 31:28, source ID 27:24,
packet type 23:20, transaction number 19:15, coherent 14, data size 13:12, GBR 11, virtual
backplane message 10, error 9, barrier 8.

## 5. Reset values

No shipped binary and no public header reads a Crossbow register before writing it, except
link control (read-modify-write) and the measured fences and lock. Power-on values of the
registers are therefore **unknown** from the evidence this file may cite; they are not
reproduced from the proprietary specification. What is known:

| Register | Value | Grade |
|---|---|---|
| Identification | part 0, manufacturer 0 for the Crossbow; revision silicon-dependent | established (OpenBSD, header) |
| Link control | the IP27 PROM's link bring-up writes `0x0008_0000` (widget credit 2, all else clear): a deliberate write, not evidence of the reset value | established as a write; reset value unknown |
| Performance counters A, B | the kernel clears exactly bits 22:20 and stores port minus 8 there | established as software behaviour |
| Fences (code 5) | `0xf7` measured on one Octane2 after the PROM ran | measured; power-on value unknown |
| Lock (code 5) | 0, measured on one Octane2 | measured |
| Everything else (packet timeout, arbitration reload, interrupt destination, LLP control, NIC) | none | unknown; test: read each from a PROM monitor immediately after reset, on a halted early boot |

## 6. Link-up, reset and port mapping

### What "up" means to software

Established (the kernel's link-alive and widget-present routines, PROM routines):

- **Alive** is link status bit 31. **Widget present** is link auxiliary status bit 5. A
  port is usable when both are set. The IP30 PROM tests the pair; the IP27 and IP35 PROMs
  and the kernel do too, with the part-`0xd100` port-F waiver above. A port that is present
  but not alive is reported as such and skipped.
- The auxiliary failure-mode bit (6) distinguishes a port that never came out of reset
  (1) from one that came up and then failed (0), meaningful only when present is set and
  alive is clear. Established from the kernel's two diagnostic messages, one for each case.
- Width is auxiliary bit 4. Control bit 24 forces eight-bit mode and the kernel's reset
  routine preserves the control word across the reset, which is how software can choose a
  width and re-run training. Established (reset routine); whether the chip itself
  clears bit 24 on a link reset is unknown.

### Reset sequences software issues

- **Kernel** (the link reset routine, IP27 offset `0x21f4`, IP30 `0x1e3c`, IP35 `0x1dfc`): read
  link control; write 0 to the link reset register; wait the kernel's reset delay; poll
  status bit 31 with a short delay until alive or a limit; on success restore the control
  word and return 0, on timeout return -1 and leave the control word. The delay variable
  is 20 units in the initial data of the IP27 and IP35 objects; the unit is taken to be
  microseconds (the delay routine was not read). The give-up bound is the time of 1000 of
  those units measured at the first call, a little over a millisecond if the unit is a
  microsecond. Established for the sequence, inferred for the unit.
- **IP27 PROM** (`0x1fc43758` family, IP35 PROM `0x1fc4bd30`): read the clearing alias,
  write link control `0x0008_0000`, write both arbitration registers 0, write the link
  reset register (IP27 PROM only), then poll status bit 31 up to 100 times with a 10-unit
  delay. The IP35 routine does not write the reset register. The IP30 PROM routine reads
  status once, writes control 0, both arbitration registers 0 and the reset register 0,
  and does not poll. Established (small routines read in full).
- **The switch is one host's, then the other's.** The IP27 PROM's messages distinguish a
  master and a slave Crossbow, report a peer Hub detected on the Crossbow without a
  NUMAlink connection, and report hubs found on Crossbow links 9 and 10 (the last also in
  SGI's own transcript, see below), so a dual-host midplane has a master node that does
  the bring-up and updates the second node's records. Inferred from message presence, not
  from a full read of the PROM routine; the arbitration rule that
  picks the master is the Linux IP27 probe rule (the enabled hub on the lowest, or with a
  build switch the highest, hub link): established as public Linux code, and the Linux
  probe returns "not mine" on the other host.
- **After a link reset** a Bridge on that link loses its widget control and LLP
  configuration; the IP30 GIO Bridge object saves the two registers before the reset,
  waits 100 microseconds, restores them and reinitialises the rest. Established (object
  read in full); the IP27 set has no GIO Bridge object.

### Training and timing

What the hardware does between reset release and alive is **unknown to software
evidence**. The only timing bounds in shipped software are the polling limits above
(about a millisecond) and the 100 microsecond Bridge wait. The handshake, the retry rule
for declaring a link dead, and the width of a link-reset pulse are not established here.
Test: a logic-analyser capture of a link reset on an Octane, or a published errata sheet
giving the training time.

### Which widget sits behind which port

Established where marked; a mapping rule is not stated anywhere read.

- **Octane, Octane2**: link 8 is HEART (public Linux IP30 file: "HEART is always 8");
  link 15 is the on-board BaseIO Bridge ("always 15"); the four XIO option quadrants are
  links 9, 10, 11 and 12 (SGI Octane PCI Module Installation Guide 007-3547-001, Figure
  3-1, printed p67, labels the rear quadrants A, B, C, D as widgets 12, 11, 9, 10); the
  PCI cage is widget 13 in public captures; widget 14 is empty in the captures read.
  OpenBSD's Octane probe order is `8, f, 9, a, b, c, d, e`. Established.
- **Origin 2000, Onyx2 (midplane Crossbow)**: hubs on links 9 and A (the IP27 PROM
  prints "Found hub on xbow link 9" and "link 10" in SGI's own diagnostic roadmap
  appendix, 108-0164-002, PDF pp47-50); everything else, links 8 and B to F, is XIO.
  BaseIO has been seen as widget 8 and as widget 15 in public `hinv`, with other boards at
  11, 12, 13, 14. No rule ties an XIO slot (io1..io12) to a link. Established for hubs on 9
  and A (from the SGI transcript; that the IP27 PROM itself prints those strings was not
  checked in the image); the slot-to-link rule is **unknown**; test: `hinv -v` with a known board in each
  of the twelve slots of one module, noting which Crossbow's links appear.
  The Linux IP27 code treats an enabled link flagged "hub" as host and flagged "I/O" as a
  bridge to probe, from the system's configuration records (type 4, one per Crossbow, with
  sixteen port records; midplane board type `KLTYPE_MIDPLANE8`, I/O-brick Crossbow board
  type `KLTYPE_PBRICK_XBOW` in Linux).
  Established.
- **Origin 200 GIGAchannel**: Crossbow link A to the Hub, link 9 to the IP29 Bridge, link
  8 to the cabinet Bridge, B to F optional. Taken from the repo's own datasheet only; no
  independent source was found, so inferred (the physical A/B cable per link is
  **unknown**).
- **Origin 300 and Fuel**: Bedrock on link `0xa`; Xbridge bus sections at widgets 14 and
  15; the VPro graphics widget on Fuel is 13 in the captures. Established.
- **Origin 350, Tezro**: Bedrock link `0xa`; PICs on links `0xb` and `0xf`. Inferred; see
  the PXBOW caveat on port `0xb`.
- OpenBSD's per-brick probe orders (I-brick `f e 8 9 a b c d`, P-brick
  `9 8 f e c d a b`, X-brick `8 9 c d a b e f`, base I/O `f 8 9 a b c d e`) show the order
  software prefers, not the wiring.

### Credits and bandwidth

- Kernel arbitration code: the field for source *s* in a destination link's arbitration
  registers is 5 bits at `8 × (s & 3)`; the routine refuses a grant that would take the
  count to 32 or more or would exceed a per-port budget. The registers are `+0x1c` (upper,
  sources 8 to 11) and `+0x24` (lower, 12 to 15) in the header's +4 convention. Established.
  A 32 or more rejection and a bytes-to-units division by four million (4 MB/s units) are
  the conversion code's. Inferred: the units are 4 MB per second per count.
- The PROM sets the Hub's per-destination credits (bits 15:13 of the Hub I/O interface
  widget control) to 4 or 3 depending on a comparison involving the widget revision, for
  parts `0xd000` and `0xd100`. Established, IP35 PROM (the exact comparison, written
  earlier as "revision + 5 >= 3", was not re-checked); the Crossbow link control's own
  widget-credit field is separate.
- The shipped headers define a default credit of 4 for the generic case and a different
  value for the SN0 case, the latter carrying a note by its authors that it is expected to
  change. Established as header content; which value reaches hardware on which machine is
  unknown.

## 7. Open questions with discriminating tests

| Question | Test |
|---|---|
| Does PXBOW have all eight link sets, the fences and the lock? | PROM-monitor dump of widget 0 on an Origin 350 over `0x00..0x2ff`, noting which decode and which raise a register-access error |
| Is part `0xd000` or `0xd100` at widget 0 of a Tezro? | PROM monitor read of the identification word at offset 4 |
| Does the Xbridge's crossbar section carry all eight link sets? | Read links 8 to 13 on an Origin 300 |
| Power-on fence value | Read the fences from a PROM monitor before the PROM clears any bit, i.e. on a halted early boot, or from the PROM image's earliest write |
| Fence and lock behaviour across a warm reset, lock acquire and release | Write and read back the lock and one fence on a code-5 Crossbow, then trigger a warm reset from a second host or Hub and re-read |
| What link status bit 2 reports | Provoke a request to a legal but dead destination and read the status |
| Training time and handshake predicate | Logic-analyser capture; or a published errata |
| Which physical connector is which link | Midplane continuity |
| Which SGI part number the Crossbow, Xbridge and PIC chips carry | Octane, Origin 300 and Origin 350 service parts lists |
| Vector number chosen for the Crossbow error interrupt | The interrupt allocation in the Hub and HEART drivers; not in `xbow.o` |
| What a refused register write leaves in the error address and command registers | Deliberate bad write then a read of `0x10`, `0x18`, `0x40` on a real Octane |

## Sources

- Shipped IRIX 6.5.30: the `xbow.o` and `xswitch.o` objects of the IP27, IP30 and IP35 boot
  directories; the IP35 kernel object; the installed crossbar and system configuration
  headers; the IP27, IP30 and IP35 PROM images and the I/O-board PROM (routines at the
  addresses given).
- Linux: `arch/ia64/sn/include/xtalk/xbow.h`, `arch/mips/sgi-ip27/ip27-xtalk.c`,
  `arch/mips/sgi-ip30/ip30-xtalk.c`, `arch/mips/sgi-ip35/ip35-xtalk.c`,
  `arch/mips/include/asm/sn/klconfig.h`.
- OpenBSD sgi: `sys/arch/sgi/xbow/xbow.c`, `xbow.h`, `xbowdevs`, and the `xbow(4)` manual
  page.
- SGI manuals: Origin and Onyx2 Theory of Operations 007-3439-002 (printed pp9, 17, 53-54,
  73, 75-79, 84-85); Octane PCI Module Installation Guide 007-3547-001 p67; IX-brick
  007-4377-001 p67; Origin 300 007-4365-002 p10; Origin 2000 and Onyx2 diagnostic roadmap
  108-0164-002 (PDF pp47-50, the power-on transcript).
- OpenBSD `sys/arch/sgi/xbow/xbridge.c` (header comment on which chip each machine
  generation uses); the repo's L1 controller datasheet (I-brick and V-brick widget 0).
- Captures: public `hinv -v` outputs and PROM transcripts of Octane, Origin 2000, Origin
  300, Fuel, Origin 350, Onyx 350 and Tezro systems, and one PROM Command Monitor session
  on an Octane2 (2026-10-02), described by counts, not reproduced.

## Corrections (2026-11-10)

An independent check found problems; each was re-verified against the primary source.

- Confirmed: the machine table put every Origin 3000 I/O brick under the PIC. The Origin
  300/3000 generation (I-brick, V-brick) uses the Xbridge; only the IX/PX-class bricks and
  the Origin 350/3500 generation are PIC. Split the row.
- Confirmed: the code 5 label conflict is closed, not unknown. The IP30 PROM prints 1.4 for
  code 5 because its comparison is off by one against the kernel table. Rewritten as
  established; the matching open question removed.
- Confirmed: XXBOW's Xbridge-only additions were understated. Added the receive-timeout and
  arbiter-timeout status bits, the matching control interrupt enables, and the watchdog and
  widget-0 timeout counter enables.
- Confirmed: "crossbar section of the Xbridge" is not the shipped header's wording (it says
  only "Xbridge"). Attributed to the public Linux comment and regraded to inferred.
- Confirmed: link auxiliary status 31:24 is a receive error count, not a receive retry
  count.
- Confirmed: the fence and lock block is Xbridge-only in the headers. No longer called
  common to all three parts; for the Crossbow the Octane2 measurement is the only evidence.
  Also noted that the "graphics port's bit" explanation of fence bit 3 is unconfirmed.
- Confirmed: removed internal routine, macro and string names taken from IRIX binaries and
  headers, quoted header comments, and PROM message strings; the facts are restated in
  prose.
- Confirmed: removed all content taken from the proprietary Crossbow ASIC Specification
  (reset values, training handshake, errata remarks, the "Crossbow 2.0" statement). The
  reset-value section now lists only measured or software-observed values.
- Unchecked items followed up: the Tezro/Origin 350 port `0xb` PIC claim, the Origin 200
  GIGAchannel link map and the master/slave Crossbow claim are regraded to inferred; the
  Hub credit comparison and the IP27 PROM hub-link strings are flagged as not re-checked.
