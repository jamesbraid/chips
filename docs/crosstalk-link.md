# Crosstalk (XIO): the link, its widgets and its host ends

Overview datasheet of the SGI I/O link called **XIO** (SGI's trademark) or **Crosstalk**
(the protocol and fabric name; the same link). It describes the hardware only: the
physical link, the packets on it, the addressing and the common widget register block,
the switch parts, the three host ends, the chips that sit on the far side, and the cable
products that carry the link outside an enclosure. It is deliberately short on detail.
Each topic has a page that goes deep, and this page says what is settled, what is not and
where to look.

| Topic | Page |
|---|---|
| Every name, where it comes from, part numbers | [interconnect-naming.md](interconnect-naming.md) |
| Crossbow, XXBOW, PXBOW: parts, registers, link bring-up | [xbow-family.md](xbow-family.md) |
| Bridge, Xbridge, PIC as widgets | [bridge-family.md](bridge-family.md) |
| HEART, Hub, Bedrock: windows, interrupts, timeouts, credits | [crosstalk-host-ends.md](crosstalk-host-ends.md) |
| Micropackets, command word, packet types, credits, errors | [crosstalk-packets.md](crosstalk-packets.md) |
| Crosstown, KTOWN, Ktown2, Xtown2 conversion boards and cables | [crosstown-ktown.md](crosstown-ktown.md) |
| How IRIX discovers and drives widgets (software, kept apart) | kudzu `docs/kernel/xtalk-software.md` |
| Per-chip evidence and census | `chips/<chip>/README.md` |

**Status.** All of the component pages above have landed, so the provisional banner this
page carried is gone. That does not make everything settled. The host-ends page still
carries its own provisional label, and several facts here rest on one source (marked
*spec* below). The remaining unknowns are listed with a test in
section 10, and the ones only a bus capture can settle are in section 11.

**Grades.** Every fact is **established** (a binary read in full, a published page, a
public driver file, or a captured value), **inferred** (a reasoned reading, reasoning
given) or **unknown** (with a test). One source tag qualifies a grade. *Spec*: the fact
comes from the Crossbow, Bridge or Xbridge ASIC Specification, which is marked
proprietary and whose publication status is under audit. It is restated in our own words
and never promoted above what a second source supports. A fact that no binary, manual or
public driver supports is **unknown**.

**Provenance.** Written from the component pages, which cite shipped IRIX 6.5 and 6.5.30
kernels, PROMs and headers (by file and offset, as provenance only), public Linux and
OpenBSD drivers, and SGI manuals by document number and printed page. No vendor text,
structure body or comment is reproduced. Anyone who needs a clean-room boundary for a
specific chip should read the exposure note in the relevant component page rather than
assume it from this overview.

---

## Corrections (2026-11-10)

Checked against Linux, OpenBSD, the Origin 200 GIGAchannel guide and the Hub datasheet:

- The Hub has two block-transfer engines at `0x410000` and `0x420000`, as Bedrock does.
- The Hub's link-side reset values (retry, burst, null timeout) were never measured on hardware
  and the page wrongly attributed them to the ASIC tables. They are now unknown.
  The Hub's widget-number and crossbar-credit resets are marked unknown as well.
- The Hub's own-error destination register: Linux's masks and overlay disagree; both
  readings are stated and the wide one is graded inferred.
- Linux `xwidget.h` and OpenBSD both publish manufacturer `0x36` for the Hub and Bedrock;
  the page said unknown. It now says published, not read from hardware.
- Fuel is board IP34; the Bedrock heading now lists it.
- The Hub also has the credit-count timeout register at `0x4001e0`; only its layout is
  unknown.
- Origin 200 GIGAchannel (Crossbow, Crosstown adapter) is now sourced to 007-3708-002.
- Withdrawn: a Linux ia64 header citation for packet types that was not found, the "peered
  crossbar" reading of PXBOW, and the unconfirmed claim that an L1 command selects the
  Xtown2 rate.
- Re-checked and left alone: the Bridge-specific 960 ns request tick (the table already
  scopes it), the Little Window naming, and the absence of the invented timeout macro name.

---

## 1. Physical link

Crosstalk is a point-to-point, full-duplex, source-synchronous link between exactly two
endpoints: a widget and a switch port, or (with no switch) a widget and a host chip
directly. A switch fans one host port out to several widget links.

| Property | Value | Grade | Source |
|---|---|---|---|
| Topology | point-to-point, two endpoints per link | established | 007-3439-002 pp17, 53 |
| Data width | 8 or 16 bits per link, set by negotiation at reset; a Bridge runs its link 8 bits wide only | established | 007-3439-002 pp53, 84; Bridge spec p85 (*spec*) |
| Rate | 16-bit path: 400 MHz on the wire, driven from a nominal 100 MHz core, 64 bits per core clock (800 MB/s each way); 8-bit path half that | established | 007-3439-002 p82; Crossbow spec (*spec*) |
| Signalling in an enclosure | STL, single-ended low-swing CMOS, 2.5 ns cycle; the electrical interface is the same as the CrayLink router network's | established | 007-3439-002 pp53, 57 |
| Link-level protocol (LLP) | 128-bit micropackets with check bits, sequence numbers and go-back-N retry; shared with the router network | established | 007-3439-002 pp80, 82, 97; section 2.1 |
| Negotiation | the two ends alternate 8-bit and 16-bit reset micropackets and settle on the narrower mode; failure within the retry count leaves the link dead | established (*spec*; the wire encoding is unknown) | Crossbow spec p23 |
| Training time | no measured value; software polls bound it at about a millisecond | unknown | [xbow-family.md](xbow-family.md) section 6 |

**LLP tunables** sit in the common widget LLP configuration register (slot `0x48`):
maximum micropacket retry count, null-micropacket timeout, maximum burst. Reset values on
the widget side are retry `0x3ff`, null timeout `0x06`, burst `0x010`. The Hub has its own
link control and status register at hub-relative `0x400128`; its reset values are
**unknown** (no public header, manual or table gives them). Field layout: established
(Bridge and Crossbow register tables, IRIX and Linux headers). The widget-side reset
values rest on the ASIC register tables alone: *spec*. The shipped 6.5.30 header's own
defaults differ from the reset values, so a software default is not a reset value
([xbow-family.md](xbow-family.md) section 5).

**Link error log.** The Hub's I/O interface has an LLP log word at hub-relative
`0x400130` (named in the Linux Hub header). Its field layout is
unknown; register existence at that address: established (Linux). The 6.5.30 kernel reads it and evaluates an error rate (inferred
from the census).

---

## 2. Packets

Full treatment: [crosstalk-packets.md](crosstalk-packets.md). The summary below is the part
other pages depend on.

### 2.1 Micropackets

One micropacket carries 128 bits of data, 16 check bits, a 4-bit transmit sequence
number, a 4-bit receive sequence number and 8 sideband bits. Established: Crossbow spec
pp21-22 (*spec*), the Origin glossary (007-3439-002 p97, two 64-bit doublewords plus
control halfwords), the OCTANE Technical Report section 2.1.7, and US 6,553,446 B1. The
manual says a CCITT CRC finds errors (p82). Retry is a sliding window with go-back-N: the
sender holds everything unacknowledged, the receiver stays silent on a bad CRC or wrong
sequence number, and the sender resends the buffer after a short silence until the retry
count runs out and the link shuts down (needs a link reset). Acknowledgements ride in the
receive-sequence field of returning traffic, or in a micropacket of their own.

Unknown: the bit order of the check halfword, the CRC polynomial, initial value and
coverage, the sideband bit positions (start, stop, invalid, free-buffer credit,
administrative), the real window size, the null-micropacket pattern and the width and
reset encodings. All are bus-capture items (section 11).

### 2.2 Packet layout, command word and types

A packet is a 32-bit command word, a 48-bit address, a 16-bit remote-map field and data
enables (requests), then 8, 32 or 128 bytes of data. Established for write requests with
data (Crossbow spec Tables 1 and 2, *spec*). Unknown: whether a read request has the same
two header doublewords, and whether a response repeats the address.

Command word, 32 bits, established by three agreeing sources (Crossbow and Bridge
error-command-word tables, IRIX 6.5.30 `xwidget.h`, Linux `xwidget.h`):

| Bits | Field |
|---|---|
| 31:28 | destination widget number |
| 27:24 | source widget number |
| 23:20 | packet type |
| 19:15 | transaction number |
| 14 | coherent transaction |
| 13:12 | data size |
| 11 | guaranteed-bandwidth ring |
| 10 | virtual backplane message |
| 9 | error |
| 8 | barrier |
| 7:0 | reserved |

An introductory table in the Crossbow spec disagrees with these positions; it cannot be
right and the register table and both OSes agree with the layout above. Whether the
error-capture registers hold the on-wire word unmodified is inferred.

Packet types: 0 read request, 1 read response, 2 write request wanting a response, 3 write
response, 4 write request with no response, 6 fetch-and-op, 8 store-and-op, E special
request, F special response (the rest reserved). Established as names and values from the
shipped 6.5.30 header; the values also agree with the Linux header. An
earlier version also cited a Linux ia64 header; that file was not found, so the citation is
withdrawn. Data size: 0 is up to 8 bytes
(doubleword), 1 up to 32 (quarter line), 2 is 128 (full line). A packet is 1, 3 or 9
micropackets for a response of those sizes and 2, 3 or 9 for a write request (Crossbow
Table 25, *spec*; the table has gaps, including no row for type 0 or for type 4 above a
doubleword: unknown).

Every register access is a doubleword packet with four data enables, and the 32-bit value
sits in the low half of the 8-byte slot. That is why software and public headers reach
every register at slot offset plus 4. Established. Only doubleword packets reach a
Crossbow or Bridge register; other sizes are errors there. Whether the enable word of that
access is `0x0f` or `0xf0` depends on byte numbering the two specifications state from
opposite ends: unknown.

Fetch-and-op and store-and-op are packet types, not widget operations. Neither a Crossbow
nor a Bridge supports them (logged as invalid packet type). They belong to memory-side
atomic operations; whether they cross a Crossbow toward a Hub is unknown.

### 2.3 Transaction numbers

A response carries the request's transaction number back. A Bridge uses `0x00`-`0x0f` for
the response buffer of a read, `0x10` plus the device number for a PCI write, `0x18` plus
the device number for a pin interrupt and `0x1f` for error interrupts. Established
(Bridge spec section 7.3, *spec*). How a Hub or HEART chooses the number of a processor
request is unknown.

### 2.4 Interrupts are write packets

A widget has no interrupt wire. It sends a doubleword write to an address its host owns.
The data carries the interrupt number in bits 7:0 and, in bit 8, set (1) or clear (0) of
the host's pending bit; the widget's own number is in the source field of the command
word (inferred: an interrupt is an ordinary write). A switch in the path forwards it like
any other write (inferred). Established across the Bridge spec (Chapter 11), Crossbow
spec (section 3.1.1), both public OS drivers and the shipped IRIX kernel.

A widget learns the destination from its interrupt-destination pair (slots `0x30`/`0x38`):
bits 31:24 of the upper word are the vector, 19:16 the target widget, 15:0 address bits
47:32; the lower word is address bits 31:0. A Bridge adds eight per-pin host-address
registers; a PIC keeps the whole address in the per-pin register and ignores the upper
destination word ([bridge-family.md](bridge-family.md)). A pin sends a set packet when it
asserts and a clear packet when it deasserts only if the pin's mode bit is also on.
Error interrupts send set only. The landing register differs per host (section 5).
Unknown: whether a given host honours a clear packet (HEART: inferred only).

### 2.5 Credits: two counters

Both are called a credit and run in opposite directions.

- **Crossbar credit**, stored in the widget's control register: how many packets the
  widget may have in the switch. The Crossbow has four input buffers per link; a sender
  starts with that count and gets one back for each free-buffer signal in the sideband.
  Over-sending drops the packet and sets the link's input-overallocation error. Field:
  bits 15:12 in the Bridge (reset 3, *spec*), bits 15:13 in the Hub and Bedrock (Hub
  reset unknown). Firmware writes 4 behind a Crossbow of revision code above 2
  and 3 behind codes 1 and 2 (IRIX PROM, established; that early silicon has three usable
  buffers is inferred and is a capture item).
- **Widget credit**, stored in the Crossbow link control (bits 22:18, reset 2, *spec*):
  how many requests a destination widget can hold. At the limit the switch passes only
  responses. Firmware writes 3 for a Bridge port and 4 for HEART's port.

Responses are exempt from request credit. A no-response write still takes one (inferred).
A Hub also tracks outstanding processor I/O per target widget with its own credit count
and a fire-and-forget mode; the Crossbow's widget 0 is always fire-and-forget because a
link-reset write never gets a response (code's stated reason: inferred). Bedrock's II
credit-count timeout (`0x4001e0`) interrupts when outbound credits stay below a threshold;
the layout is established from the Bedrock header. The Hub has a register at the same offset
(named "Crosstalk credit count timeout" in the public Linux Hub header), but its layout is
unknown.

### 2.6 Timeouts

Every layer has its own clock, and a missing response is reported at the layer that waits
longest, so the host must give up before the processor does.

| Layer | Register | Unit and reset | Grade |
|---|---|---|---|
| Crossbow packet timeout (destination, source, max request, connection) | widget 0 `0x28`, 19:0 | 1.28 us per tick, reset `0x0fffff` | established (*spec*) |
| Bridge read-response timeout | widget `0x28`, 19:0 | 960 ns per tick (32 PCI clocks), reset `0xf_ffff`; expiry sets interrupt-status bit 9 | established (*spec*) |
| HEART widget request timeout | widget `0x28`; the kernel writes 40000 and 128 (see the host-ends page) | unit unknown; a timed read of an unclaimed widget address at two programmed values would give it | unknown |
| Hub II request-buffer ("CRB") timeout and prescale | `0x4003b8` (7:0), `0x4003c0` (23:0) | IRIX writes `0xff` and `0x1000`; Linux writes `0xff` and `0x800` (a 5 ms intent, below the 10 ms processor-interface timeout) | values established; unit unknown |
| Hub PI request-buffer timeout and scale | PI `0x30`, `0x38` | IRIX writes `0xd0`/`0xd400` or `0xfe`/`0xc000` under conditions not read | values established |
| Hub II tail timeout | `0x4001f0` (25:0) | — | register named in Linux; layout inferred |
| Hub II credit-count timeout | `0x4001e0` | — | register named in Linux; layout unknown |
| Bedrock II | same pair at `0x4003b8`/`0x4003c0`; credit-count `0x4001e0`; tail `0x4001f0` 25:0; read-response prescaler 54:32 and timeout 59:55 | 128-clock ticks for credit-count | layout established |

The Hub and Bedrock `0x4003b8`/`0x4003c0` pair times entries in the I/O interface's
request buffer, the requests a widget makes toward memory. It is not the processor's
PIO-read timeout, and the Hub has no defined common widget request timeout at slot
`0x28`; HEART and the Bridge do. Widget status flags differ too: tail and credit timeout
are bits 6 and 5 on the Hub and bits 5 and 4 on Bedrock. Established
([crosstalk-host-ends.md](crosstalk-host-ends.md) sections 3.4, 4.4, 4.5).

### 2.7 Errors, routing faults and resets

- **First-error latch.** A widget latches the command word and 48-bit address of the first
  failed packet (slots `0x10`/`0x18`/`0x40`) and ignores later ones until software writes
  the command word, which re-arms capture on the Crossbow. A switch also sets a status bit
  and, if enabled, interrupts from its widget 0. Established.
- **Illegal destination.** The switch routes by destination widget number with no
  translation. Widget 0 and numbers 8-F are legal; 1-7 are not ports. A packet naming an
  illegal number is redirected to widget 0, logged there, and the receiving link's
  illegal-destination status bit is set; a repeat sets multiple-error. A link cannot send
  to itself. Established (*spec* plus the IRIX error handler).
- **Destination link failed or stalled (was alive).** The packet waits until the packet
  timeout, then is redirected to widget 0, logged and dropped, and the source link's
  destination-timeout bit is set. Established (*spec*).
- **Destination link that never came up.** Unknown. The packets page says the timeout
  path above applies; an earlier version of this page said nothing is recorded. Test: a
  request to an empty port, then read widget-0 status and the source link status.
- **Warm reset and link reset.** A warm-reset pattern on any Crossbow link resets the
  whole switch core and is sent out of every link; a link reset affects the originating
  port only and also drives the peer's reset input (a Bridge resets its core from it).
  The switch ignores further resets for 1024 core cycles (10.24 us). Established (*spec*).
  Per-destination reset fences on revision-code-5 silicon: existence established by one
  Octane2 PROM-monitor read, independence across a warm reset inferred. Wider Hub effect
  of a received link reset: unknown.
- **Kernel policy.** The shipped 6.5.30 kernel treats every Crossbow link or widget-0
  error bit as fatal except a handled illegal destination and a transmitter retry
  (a Bridge workaround). Established.

### 2.8 Ordering

A barrier bit orders a packet after earlier ones from the same source. A read of a
widget's target-flush register completes only after every earlier access to that widget
has completed. Responses are sent ahead of the widget's own requests. A guaranteed-
bandwidth bit puts a packet in a high-priority class served from per-source counts, the
remainder served round-robin. Established that each exists and who sets it; the wire-level
ordering guarantee and ordering between responses of different transaction numbers are
unknown.

---

## 3. Addressing

### 3.1 Widget numbers

A widget number is 4 bits. Established as a machine property, not a chip property.

| Number | Meaning |
|---|---|
| 0 | the crossbar's own register and error endpoint, and the discovery address; on a switchless host the one attached bridge answers here |
| 1-7 | not switch ports. On a Hub or Bedrock, widget slot 1 of the processor's Little Window is where the node chip keeps its own registers |
| 8-F | the eight external switch links; arbitration groups them as upper (8-B) and lower (C-F) |

A widget's own number is written by firmware into the low four bits of its control register
(slot `0x20`) on the Hub, Bedrock and Bridge-class widgets; HEART instead reports its
number as the low four bits of a processor-interface status register (8 on Octane). On the
Hub and Bedrock that field names **the switch port the node chip occupies**, not the
number 1; the "1" is the Little Window slot. The Hub's reset value is unknown.
Established placements: Octane has the Crossbow at 0, HEART at 8, option quadrants at 9
to 12, a PCI cage Bridge at 13, the base-I/O Bridge at 15; an Origin 2000 or Onyx2
midplane Crossbow has Hubs on links 9 and A; an Origin 200 base board has no Crossbow and
a Bridge directly on the Hub (Bridge at widget 8, Hub master 0xa); Origin 300 and Fuel
have the Bedrock on link `0xa` and Xbridge heads at 14 and 15; Origin 350 and Tezro have
the Bedrock on `0xa` and PICs on `0xb` and `0xf`. The mapping from a physical connector
or slot to a link number is unknown ([xbow-family.md](xbow-family.md) section 6).

### 3.2 Address = widget number + offset

The switch does no address translation: the destination widget number selects the port
and the offset travels unchanged. A host reaches widget space differently:

- **Hub and Bedrock** use SGI's **Little Window (LWin)**: the first 16 MB of each of 16
  widgets, at widget number times 16 MB, in the node's uncached I/O space; and seven **big
  windows (BWin)**, each a programmable 512 MB slice (256 MB in N mode) of some widget's
  space, chosen by a seven-entry table at hub-relative `0x400160 + 8n` (memory-or-device
  select bit 12, widget 11:8, slice 4:0). Names from 007-3410-001 pp23, 27; shipped IRIX
  code also says "small window" and SWIN for the Little Window; that is a software
  spelling and is not used here. Widget 0 short-window access is unreliable on early Hub
  silicon, so the PROM maps it through the last big window (established, OpenBSD and
  Linux).
- **HEART** has no programmable translation. Fixed decodes name the widget in the
  physical address: 16 MB per widget from `0x1000_0000`, 2 GB per widget from
  `0x8_0000_0000` (unknown), and 64 GB per widget at widget number times
  `0x10_0000_0000`, with none for widget 0. SGI's Octane report names none of these;
  the names are IRIX and OpenBSD software names. Established for the 16 MB and 64 GB
  ranges.

### 3.3 Common widget register block

Every widget begins its space with a block that lets firmware identify and configure
whatever is plugged in. Slots are 8 bytes; the 32-bit register is in the low half
(software adds 4). Offsets `0x00` to `0x58` are shared in role by the Crossbow, Bridge,
Xbridge, PIC, HEART, Hub and Bedrock; everything above is chip-specific. Dual-sourced
between the Bridge and Crossbow register tables (*spec*), Linux `xwidget.h`, OpenBSD
`widget.h` and the shipped binaries; individual rows carry the caveat in the last column.

| Slot | Role | Caveat |
|---|---|---|
| `0x00` | Identification: 31:28 revision, 27:12 part, 11:1 manufacturer, bit 0 reads 1 | bit 0 stated for Bridge and Xbridge (*spec*), inferred for PIC (the PROM refuses a clear bit), by convention for the Hub |
| `0x08` | Status | contents differ per chip |
| `0x10`/`0x18` | Error address, upper (47:32) and lower | PIC reads as one 64-bit register |
| `0x20` | Control | own widget number in 3:0 on Hub, Bedrock, Bridge-class widgets; on the Crossbow the same slot holds interrupt enables (the kernel writes bits 5 and 2) |
| `0x28` | Request timeout | Bridge and HEART implement it; Hub and Bedrock do not; the Crossbow's is a packet timeout |
| `0x30`/`0x38` | Interrupt destination, upper and lower | PIC: upper hardwired to zero |
| `0x40` | Error command word | writable on the Crossbow to re-arm capture |
| `0x48` | LLP configuration | |
| `0x50` | Target flush (the read is the operation) | on the Crossbow this slot is the read-and-clear alias of widget-0 status |
| `0x58` | Auxiliary error command word | on the Crossbow this slot is the arbitration reload |

The one-wire board-identity part ("number in a can", NIC) is **not** at a common
offset: Bridge `0xb0` (inert on Xbridge, which moves it to widget 0 slot `0x70`; PIC `0xb0`
may instead be an ATE parity-error register: unknown), Crossbow `0x70` (non-functional per
its errata), the Kona graphics widget `0x98`/`0x9c`, MardiGras graphics `0x011098`.

**Identification words** (revision field varies; part and manufacturer from the shipped
6.5.30 headers, OpenBSD tables and census, [interconnect-naming.md](interconnect-naming.md)
section 2):

| Part | Mfr | Chip |
|---|---|---|
| `0x0000` | 0 | Crossbow (XBOW) |
| `0xd000` | 0 | XXBOW, crossbar section of the Xbridge |
| `0xd100` | 0 | PXBOW, crossbar face of the PIC (meaning inferred) |
| `0xc001` | `0x36` | HEART (an owner read of an Octane2 gave `0x6c00106d`, revision 6) |
| `0xc002` | `0x36` | Bridge |
| `0xd002` | `0x24` | Xbridge |
| `0xd102`, `0xd112` | `0x24` | PIC, bus 0 and bus 1 (`0xd112` unseen in a shipped system) |
| `0xc101` | `0x36` published | Hub (Linux `xwidget.h` and OpenBSD both say `0x36`; one vendor register listing says `0x24`; no hardware read, so not established) |
| `0xc110` | `0x36` published | Bedrock (Linux `xwidget.h` and OpenBSD both say `0x36`; no hardware read; no consumer found that tests it) |
| `0xc003` / `0xc102` | `0x2aa` | MardiGras (HQ4) / Kona (XG) graphics |
| `0xc013` | `0x23` | Odyssey graphics |
| `0xc202` | `0x24` | TPU |

What the manufacturer numbers identify (a design group or a fab) is unknown; test: a
published Crosstalk specification page defining the field.

---

## 4. The switch parts

Full treatment: [xbow-family.md](xbow-family.md).

- **Crossbow (XBOW)**, part 0: an eight-port XIO crossbar; the chip is widget 0 and its
  links are widgets 8-F, so the crossbar is nine-way internally. Up to two host ports; the
  six I/O ports are split statically between two hosts and one host can take all six if
  the other fails. Found on Octane and Octane2, on Origin 2000 and Onyx2 midplanes (two on
  a deskside midplane), and in the Origin 200 GIGAchannel expansion cabinet (007-3708-002
  p7, Figure 1-5). Revision codes 1 to 5
  are 1.0, 1.1, 1.2, 1.3 and 2.0 in IRIX; the Octane PROM labels the same codes 1.2 to 1.4
  (a naming difference or a tool error: unknown, test in section 10). Code 5 adds
  per-destination reset fences and a resource lock.
- **XXBOW**, part `0xd000`: the crossbar section inside the Xbridge, the single I/O chip
  of the Origin 300 and Fuel. Established that Origin 300 has no separate crossbar chip.
  Whether it carries all eight link register sets is unknown.
- **PXBOW**, part `0xd100`: the widget-0 crossbar face on PIC-based Bedrock machines
  (Origin 350, Onyx 350, Tezro; the PROM accepts parts 0, `0xd000` and `0xd100` at widget
  0 and public captures do not print which one a Tezro has). That it is a PIC crossbar
  face is inferred; whether it has all eight links, the fences and the lock is unknown.
  The software special case is established: for part `0xd100`, link F is reported present
  without reading its status.
- The names PXBOW and XXBOW are not in the SGI manuals searched; they are in the shipped
  6.5.30 headers and kernel objects and in the OpenBSD device table.

Register summary (slot offsets, 32-bit access at slot plus 4; established from the
shipped header and kernel): widget 0 holds the common block, performance counters
(`0x60`/`0x68`), the NIC (`0x70`) and, on code-5 parts, reset fences (`0x78`-`0xb8`) and a
lock (`0xc0`/`0xc8`). Per-link sets, eight of them, at `0x100 + 0x40 x (link - 8)`: input
buffer flush, link control, link status, arbitration upper and lower, status clear
alias, link reset (write-only one-shot) and auxiliary status (retry counters, widget
present at bit 5, 8-bit mode at bit 4, failure mode at bit 6).

**Port state.** Software calls a port usable when link status bit 31 (alive) and
auxiliary bit 5 (present) are both set. Present but not alive is skipped; failure mode
tells a port that never left reset from one that failed after coming up. Established.

**Error acknowledgement.** The Crossbow clears by reading a second alias address, the Hub
by write-one-to-clear and per-register clear words, the Bridge by a group-clear register,
HEART by writing back the value read. All four coexist.

**Origin 200.** The base IP29 board has no Crossbow; widget 0 answers with the Bridge
identity. Only the GIGAchannel expansion adds a Crossbow (inferred from the expansion
path, revision unknown).

---

## 5. The three host ends

Full treatment: [crosstalk-host-ends.md](crosstalk-host-ends.md). A host end is the chip
that owns the processors' route into widget space and is the target of every widget's DMA
and interrupt writes.

| Aspect | HEART (Octane, Octane2; IP30) | Hub (Origin 200/2000, Onyx2; IP29/IP27) | Bedrock (Origin 300/350/3000, Fuel, Tezro; IP34/IP35/IP45/IP53) |
|---|---|---|---|
| Identity | `0xc001` / `0x36` | `0xc101`; manufacturer `0x36` in Linux and OpenBSD, no hardware read | `0xc110`; manufacturer `0x36` in Linux and OpenBSD, no hardware read |
| Own widget number | PI status bits 3:0; 8 | widget control bits 3:0, the switch port the Hub occupies | same field; an Origin 350 capture shows port `0xa` |
| Widget face | physical `0x18000000` | hub-relative `0x400000` | hub-relative `0x400000` |
| Processor interfaces | 1 | 1 (two CPUs A, B) | 2 (PI0, PI1), two CPUs each |
| Processor to widget | fixed decodes (section 3.2) | Little Window plus seven big windows | same; node field one bit higher |
| Interrupt landing | widget face `+0x80` | PI interrupt-modify, node-explicit `0x0180_0090` | PI0 `0x0180_0090`, PI1 `0x01A0_0090` |
| Interrupt data | vector 0-63 (6 bits used), bit 8 set/clear | number 0-127 in 6:0, bit 8 | level 0-127 in 6:0, bit 8 |
| Pending model | 64 sources in 5 levels, 4 per-CPU masks | two 64-bit banks, per-CPU masks | same, per PI |
| Host's own error interrupt | HEART vectors 63 and 59-62 | II destination `0x400138`: node 16:8, level 6:0, enable 24, sent 28 (inferred; Linux's own masks say node 15:8, level 5:0, see below) | same, node 16:9, PI-select bit 8, forwarded-pending 32/33 |
| Request-buffer timeout | none visible | `0x4003b8`/`0x4003c0` | same pair |
| Widget request timeout (`0x28`) | implemented | none defined | none defined |
| Credits toward the switch | unknown | widget control 15:13, PROM writes 3, or 4 for Crossbow code 3 and later | same field; PROM writes 4 for an integrated crossbar or code 3 and later |
| Block-transfer engines | not covered | 2 (`0x410000`, `0x420000`) | 2 (same offsets) |

What is common: a widget interrupt is a Crosstalk write the host turns into a pending bit
(established); the host chip's widget face carries the standard identification word;
processor access is uncached and routed by widget number; and the host end, not the
target, times out a processor read and logs the failing address. What is not common: the
landing address and number space, whether the processor-to-widget map is programmable,
who owns the widget request timeout, the timeout flag positions, and whether the host's
widget number is read-only.

The Hub's own-error destination register is described twice in the public Linux Hub
header: four masks give node 15:8 and level 5:0, and a bit-field overlay several hundred
lines later gives node 16:8 and level 6:0 (a reserved bit sits at 7). Enable at 24 and sent
at 28 agree. The table uses the wide layout, which the overlay and the shipped kernel
support; it is **inferred**, and the narrow masks are the competing reading. Test: write
all-ones to the node and level bits on a Hub and read back.

Hub-only or unsettled points worth stating: a Hub's local window form (`0x0100_0000`, node
field unchecked) reaches the local Hub; whether Bedrock's local form reaches the
requester's own PI is unknown. A Hub qualifies widget accesses with outbound and inbound
16-bit masks (`0x400110`, `0x400118`) and a local-access-protection word (`0x400100`);
reset values are unknown.

---

## 6. Chips on the far side of a link

Full treatment: [bridge-family.md](bridge-family.md). Three different chips turn a widget
port into PCI; they are not one chip at three revisions.

| Chip | Machines | Buses | Registers |
|---|---|---|---|
| Bridge `0xc002` | Octane, Origin 200 (IP29), Origin 2000 and Onyx2 I/O boards, GIGAchannel; also hosts a GIO adapter on Octane | one PCI bus, 8 device slots | 32-bit at slot plus 4 |
| Xbridge `0xd002` | Origin 300, Fuel, Origin 3000 P-brick and other bricks | two Bridge-style PCI sections plus a crossbar section (XXBOW) in one chip | 32-bit at slot plus 4 |
| PIC `0xd102` | Origin 350, Onyx 350, Tezro, IX-brick, PX-brick | two PCI-X buses, 4 slots each | 64-bit, full-width writes only |

**PIC is the PCI interface chip of the IX-brick** (007-4377-001 p67) and is not the
Xbridge. Three PICs make an IX-brick or PX-brick: two Xtown2 XIO ports and six PCI-X
buses. Graphics widgets (HQ4/MardiGras, XG/Kona, Odyssey) and the TPU plug into a widget
port directly. TIO-family parts (TIOCP and others) belong to the later Altix generation
and are outside this page. Established.

Common to all three: they deliver interrupts and DMA as Crosstalk write packets, present
the common widget block, and offer three DMA views (translated 1 GB page-mapped window,
direct 2 GB window, 64-bit direct). Byte swapping and several reset values differ and
remain unknown for the chip's reset state. IRIX serves all three with one set of
accessors, picking by part and manufacturer.

---

## 7. XIO over a cable: Crosstown, KTOWN, Ktown2, Xtown2

Full treatment: [crosstown-ktown.md](crosstown-ktown.md). None of these is a new
protocol. Crosstown and Xtown2 carry Crosstalk unchanged; the difference is the physical
layer.

- **Crosstown** (first generation): the XIO protocol on a cable of up to 3 m, STL
  converted to differential 3.45 V PECL by an XC chip on an XIO board. The host-side board
  is called XTOWN in the Onyx2 rack guide; the board that ends the cable in the graphics
  module and feeds an InfiniteReality pipe is **KTOWN** (the Crosstown conversion board,
  007-3439-002 p73). Origin 2000, Onyx2 and Origin 200 GIGAchannel, whose main board carries a Crosstown
  adapter board and two XIO cable connectors (007-3708-002 p9).
- **Crosstown2 / Xtown2** (Origin 300 and 3000 generation; both spellings are SGI's): a
  differential channel carrying Crosstalk at 800 or 1200 MB/s each way (both rates
  appear in 007-4240-002 p135; how the rate is chosen, including by an L1 command, was not
  found), on the C-, I-, P-, X-brick ports, and between those and a G-brick.
  **Ktown2** is the G-brick board with two connectors, one per pipe (007-4264-001 pp8,
  20); the IX- and PX-bricks use Xtown2 ports on PIC.
- **What software sees.** The pipe widget, not the converter, appears in the hardware
  graph. No register of the XC chip, XTOWN, KTOWN or Ktown2 is named in any source read;
  only their one-wire identity records (part 030-1067 for KTOWN, 030-1593 for Ktown2) are
  read. Whether the converters are transparent, retimed or have any state is unknown.

---

## 8. Software

How the IRIX kernel binds drivers by part and manufacturer, probes and numbers widgets,
and allocates interrupts is a software contract and is kept out of this datasheet. See
kudzu `docs/kernel/xtalk-software.md`. Hardware-relevant facts from it: the kernel
re-reads each widget's identification word from the widget rather than trusting the
PROM's board list; the provider (Hub or HEART) is fixed at link time; and one Hub of
those wired to a Crossbow becomes the master that registers the first widget.

---

## 9. Names

Settled in [interconnect-naming.md](interconnect-naming.md) from SGI manuals, kernel,
firmware and header strings. Used here: XIO, Crosstalk (and XTalk/xtalk in SGI's own
firmware text and hardware-graph paths), widget, Crossbow/XBOW, XXBOW and PXBOW (header
and kernel names; not found in the manuals searched), Bridge, Xbridge, PIC, HEART, Hub,
Bedrock, Little Window and big window (BWin), LLP, Crosstown, KTOWN, Ktown2, Xtown,
Xtown2, Crosstown2. "Hub II" is not a chip: II is the I/O interface block of the Hub
and Bedrock. "Small window" is a software spelling of the Little Window. What the K in
KTOWN, and the letters in HQ4, XG and TIO, stand for is unknown.

---

## 10. Grade summary and discriminating tests

### Established

- The link: point-to-point, 8 or 16 bits, 128-bit micropackets with check bits, sequence
  numbers and go-back-N retry, nominal 100 MHz core.
- The command word layout, packet type values, data sizes, the doubleword-with-four-
  enables register access, and that interrupts are write packets with the vector in data
  7:0 and set/clear in bit 8.
- Routing by destination widget number with no translation, and the illegal-destination
  and alive-link-failure handling.
- The common block roles at `0x00`-`0x58`, the part and manufacturer table, the switch
  family and where each part is found, the three host ends' windows, landing registers
  and timeout registers, and the Bridge, Xbridge and PIC split.
- Crosstown, KTOWN, Ktown2 and Xtown2 as XIO over a cable, and their one-wire identities.

### Inferred

| Claim | Discriminating test |
|---|---|
| Part `0xd100` is a PIC crossbar face; the Tezro and Origin 350 widget 0 reports it | PROM-monitor read of the identification word at slot `0x00` (offset 4) on an Origin 350; read links 8-F and `0x78`-`0xc8` |
| HEART honours a deassert interrupt packet | Bridge pin with clear mode on; watch HEART's pending bit when the pin drops |
| HEART request timeout is 1.28 us per count | timed uncached read to an unclaimed widget at two programmed values |
| Early Crossbow revisions have three usable input buffers | four back-to-back packets with crossbar credit 4; watch input overallocation |
| Fences and lock are independent across a warm reset on code 5 | write the lock and a fence, warm-reset from a second host, re-read |
| Converters in Crosstown are transparent | `hinv` and port status of a rack slot with an XTOWN, cable attached and detached |

### Unknown

| Unknown | Test |
|---|---|
| Whether the Hub and Bedrock really read manufacturer `0x36` (published in Linux and OpenBSD) | read the local identification word at `0x400000` on each |
| Hub widget-control reset value and who writes it | read `0x400020` before any firmware write |
| Units of the Hub and Bedrock timeouts | program two values and time a forced timeout |
| Whether the Hub's request timeout slot `0x28` exists in silicon | read it on a Hub |
| IP30 PROM revision-label arithmetic (codes 3-5 labelled 1.2-1.4) | disassemble the banner routine in the IP30 PROM |
| Whether PXBOW or XXBOW has all eight link sets | PROM-monitor dump of widget 0 on an Origin 350 and an Origin 300 |
| Whether Bedrock's local window reaches the requester's own PI | PIO from a PI1 processor to the local form; see which pending bank changes |
| Reset values of most host and widget registers | register dump at power-on before firmware writes |
| Packet to an empty port that never came up | request to an empty port; read widget-0 and source-link status |
| Whether the second PIC head is a separate widget or an offset in one widget | walk the widget table on an Origin 350 |
| Physical connector to link number mapping | midplane continuity, or a PROM trace printing both |
| What the manufacturer field and the letters K, X, HQ4, XG, TIO denote | a published Crosstalk or ASIC specification page |

---

## 11. Items only a bus capture can settle

1. Micropacket bit order, CRC parameters and the LLP window.
2. Sideband encoding (start, stop, invalid, credit, administrative) and head/tail marking.
3. Null-micropacket and idle patterns.
4. Warm-reset and link-reset patterns and the width negotiation exchange.
5. Whether a read request has one or two header doublewords, and whether a response
   repeats the address and swaps source and destination.
6. The packet type and size of Bridge DMA writes and Hub block writes.
7. Whether the enable word of a 32-bit register access is `0x0f` or `0xf0`.
8. How a Hub chooses transaction number, coherent, barrier and response flags for a
   processor request.
9. Ordering between responses of different transaction numbers, and the exact barrier
   guarantee.
10. What a switch or host does with a packet that arrives inside a link-reset pulse.
11. Whether fetch-and-op and store-and-op cross a Crossbow toward a Hub.
12. The interrupt write as a widget really emits it: data, source field position, and the
    set/clear pair.
13. Whether PXBOW forwards packets between host ports at all (its role beyond being the
    PIC's widget-0 face is inferred).

---

## Sources

- Component pages: [interconnect-naming.md](interconnect-naming.md),
  [xbow-family.md](xbow-family.md), [crosstown-ktown.md](crosstown-ktown.md),
  [bridge-family.md](bridge-family.md), [crosstalk-host-ends.md](crosstalk-host-ends.md),
  [crosstalk-packets.md](crosstalk-packets.md); kudzu `docs/kernel/xtalk-software.md`.
  Each lists its own binaries by release, file and offset.
- SGI manuals: *Origin and Onyx2 Theory of Operations* 007-3439-002; *Origin Family
  Memory Map* 007-3410-001; *OCTANE Technical Report*; *Origin 300 Server* 007-4365-002;
  *Origin 3000 Series* 007-4240-002; IX-brick guide 007-4377-001; Onyx 3000 guide
  007-4264-001; *Origin200 GIGAchannel* guide 007-3708-002 (pp7, 9, 20).
- Public drivers: Linux `arch/mips/include/asm/xtalk/xwidget.h`,
  `asm/sn/sn0/hubio.h` (LLP log at `0x400130`, block-transfer engines at `0x410000` and
  `0x420000`, credit-count and tail timeouts at `0x4001e0` and `0x4001f0`), `asm/sgi/heart.h`, `sgi-ip27`, `sgi-ip30`
  and `sgi-ip35` xtalk files; OpenBSD `sys/arch/sgi/xbow/`.
- Restricted, restated in own words: Crossbow ASIC Specification rev 12.0, Bridge ASIC
  Specification rev 4.0, Xbridge ASIC Specification rev 0.5 (all *spec*).
