# Crosstalk packets and the link under them

This page describes what travels on a Crosstalk (SGI's trademark "XIO") link:
the micropackets of the link-level protocol, the request and response packets
built from them, the command word, sizes and byte enables, block transfers,
interrupts, credits, timeouts, errors, and how a switch routes by widget number.
It says nothing about how any program or emulator should model them. The
physical link, the common widget register block and the three host ends are
covered in [crosstalk-link.md](crosstalk-link.md); this page goes deeper on the
packets and does not repeat that page's register tables.

Every fact carries a label from [AGENTS.md](../AGENTS.md): **established**
(read in full from a shipped binary, a published specification page or a public
driver file), **inferred** (a reasoned reading, with the reasoning given) or
**unknown** (with the measurement that would settle it). Section 11 collects the
points only a capture on a real link could settle.

## Names

Crosstalk and XIO are the same link; SGI's manuals use "XIO" far more often. The
endpoints are *widgets*; the switch is the Crossbow (XBOW). Names this page uses
and where they come from:

| Name | Source of the name |
|---|---|
| widget, XIO, Crossbow (XBOW), LLP | SGI manuals: *Origin and Onyx2 Theory of Operations* 007-3439-002 printed pp. 17, 53, 82, 84 |
| Bridge, HEART, Hub, Bedrock | SGI manuals and the *OCTANE Technical Report* (see the naming audit) |
| Little Window, big window | *Origin Family Memory Map* 007-3410-001 printed pp. 23, 25 |
| DIDN, SIDN, PACTYP, TNUM, CT, DS, GBR, VBPM, ERROR, BO | field names in the Crossbow and Bridge ASIC specifications and in the shipped IRIX headers |
| XB_CTRL_*, XBCMDTYP_*, WIDGET_* | symbol names in the shipped IRIX headers and Linux headers, cited as software names |

[interconnect-naming.md](interconnect-naming.md) records which names SGI's own
hardware documents use and which exist only in operating-system software.

## 1. Layers

A transfer crosses three layers. Each has its own error reporting, and a fault
at one layer shows up at the layers above it in a particular way.

1. **Physical link.** Two unidirectional data paths per link, 16 bits wide at
   400 MHz or 8 bits wide, driven source-synchronously from a 100 MHz core.
   Covered in crosstalk-link.md and in 007-3439-002 printed p. 82 (SSD/SSR).
2. **Link-level protocol (LLP).** Cuts a stream into fixed-size micropackets,
   adds check bits and sequence numbers, and retransmits damaged ones. Sections 2
   and 8.
3. **Crosstalk packet.** A command word, usually an address, and zero or more
   data doublewords, carried as one or more micropackets. Sections 3 to 7.

The OCTANE Technical Report describes the same split (packets in section 2.3.1.1,
printed p. 2-14; the LLP in section 2.1.7, printed p. 2-6). The Origin manual
says the XIO link uses "the same physical link technology as CrayLink
Interconnect, but a protocol optimized for I/O traffic" (007-3439-002 printed
p. 17). The LLP is shared with the CrayLink router network (printed pp. 80, 82,
97); the packet layer is XIO's own.

## 2. LLP micropackets

### 2.1 Format

**Established.** One micropacket carries 128 bits of data, 16 check bits, a
4-bit transmit sequence number, a 4-bit receive sequence number and 8 bits of
sideband. Crossbow ASIC Specification rev 12.0, section 1.6.2 and Figure 9,
printed pp. 21-22. The Origin glossary says the same in other words: two 64-bit
data doublewords and two 16-bit halfwords of control (check bits; sequence
numbers plus sideband), 007-3439-002 printed p. 97. US 6,553,446 B1 (SGI, a
later router/bridge ASIC that reuses the Crossbow link controller) repeats the
128 / 16 / 4 / 4 / 8 split. The OCTANE Technical Report says "128-bit
micropackets" tagged with a CRC and a sequence number (section 2.1.7).

Layout in the specification's Figure 9, as a 16-bit control word beside 64-bit
data rows: the control word holds the sideband in its top byte and the two
sequence numbers in its bottom byte; the check bits are the second halfword.
The bit order of the check halfword and which nibble is the transmit number are
not given in a form that can be read off the figure: **unknown**. Settled by: reading Figure 9 from the specification's page image (the held text extraction
loses the figure's bit labels), or a capture of a micropacket with known sequence numbers.

**Check code.** The Origin manual says errors are found with a CCITT CRC code
(007-3439-002 printed p. 82). The 16-bit width matches CRC-16-CCITT. The exact
polynomial, the initial value, which bits it covers (data only, or data plus
sideband and sequence numbers) and its bit order are **unknown**. Settled by: the polynomial in the
published link-controller patent text or an LLP figure in a router specification, or a captured link trace with
known payloads; none is held. The Crossbow
specification says the CRC is computed over "the micropacket", and its receive
logic discards both halves of a micropacket (D0 and D1) when it is bad (pp. 104-105).
Test: a capture of one micropacket with a known payload.

### 2.2 Retry

**Established** (Crossbow spec p. 22; Octane report section 2.1.7;
US 6,553,446 B1). The protocol is a sliding window with go-back-N retry:

- The sender keeps every micropacket in a retry buffer until it is acknowledged.
- The receiver checks the CRC, then checks that the transmit sequence number is
  the next one it expects. A bad CRC or a wrong number makes the receiver stop
  passing micropackets up and stay silent.
- Acknowledgements ride in the receive-sequence-number field of micropackets
  going the other way. An acknowledgement frees every buffered micropacket up to
  and including that number. When there is no return traffic the LLP sends a
  micropacket of its own to carry it (the Crossbow spec p. 123 says this for
  buffer credits, which share the same sideband mechanism; see 5.1).
- After a short silence the sender retransmits the whole unacknowledged buffer,
  repeating until it is acknowledged or the retry count is exhausted.
- On a retry timeout the link shuts down. The Crossbow table of link errors
  calls transmitter max-retry a "fatal error condition": the LLP stops and needs
  a link reset, either from the far widget or by a write to the port's reset
  register (spec printed p. 68). A Bridge says the same (Bridge ASIC
  Specification rev 4.0, printed p. 81, Table 56).

The 4-bit sequence numbers give a window of at most 15 outstanding micropackets
by the usual go-back-N rule. The actual window the hardware uses is **unknown**. Settling test: the Crossbow specification's retry-buffer section for the sequence window (a document read); no software depends on it.
The Crossbow's retry buffer is sized so a full 128-byte packet (9 micropackets)
fits while an 8-bit link drains slowly (spec p. 123-124); that is a lower bound
of 9, not the window.

### 2.3 Tunables

**Established**, dual-sourced (the common widget register at offset 0x48 in IRIX
and Linux headers; Bridge spec Table 16; Crossbow spec Table 21, printed pp.
90-91): maximum retry count (reset `0x3ff`), null-micropacket timeout in clocks
(reset `0x06`, minimum 3 per the Crossbow spec) and maximum burst (reset `0x010`
micropackets sent back to back before the sender inserts a null cycle). A null
micropacket is what a link sends when it has nothing else; it keeps sequence
numbers and acknowledgements moving. What the null micropacket looks like on the
wire is **unknown**.

The Hub has its own link control register with the same three fields; its reset
values are **unknown** (settling test: an early-boot read of the register on a halted Hub). See crosstalk-link.md section 1.

### 2.4 Sideband

**Established that it exists and carries framing and credit; the bit encoding is
unknown.** Eight sideband bits ride with every micropacket. Crossbow spec:

- The receiver scans the sideband for a "start of packet" code to begin
  filling an input packet buffer (spec printed p. 27, section 4.3).
- Inside the Crossbow the packet bus carries three sideband bits, packet start,
  packet stop and "invalid packet", plus a data-valid control (spec pp. 97-98).
  The text does not say how those map onto the 8 wire bits.
- The wire sideband also carries a free-buffer credit signal (spec pp. 112, 120,
  123) and an "administrative" bit. A micropacket that carries only a credit has
  the administrative bit set and its 128 data bits are ignored (spec p. 123).
- The Bridge's receive logic speaks of "the head and tail sideband bits" that
  frame a data segment (Bridge spec pp. 78-79), and HEART's error text speaks of
  head and non-head micropackets. So the framing marks the first and last
  micropacket of a packet. **Inferred** from those names.
- "Invalid sideband" is set on padding the Crossbow adds to finish a packet
  whose source stalled (section 8.1, source timeout).

The position of each bit in the 8-bit field, and what distinguishes a head
micropacket from a continuation one, are **unknown**; only the signals are read.

### 2.5 Link widths and modes

An LLP runs 16 bits wide or 8 bits wide. At reset the two ends alternate
8-bit and 16-bit reset micropackets (crosstalk-link.md section 1) and settle on
the narrower mode both support (Crossbow spec p. 23: "the least common
denominator of the two modes"; 007-3439-002 printed pp. 53 and 84: a port is
programmed for 8 or 16 bits). A Bridge
operates its link in 8-bit mode only (Bridge spec printed p. 85, section 7.1).
A link control bit forces 8-bit mode; it survives a link reset so software can
change it, then reset the link (Crossbow spec p. 78). A 16-bit link moves 64 bits
per 100 MHz core clock (800 MB/s); an 8-bit one half that. The wire format of the
width negotiation is **unknown**; its software effect (a width bit and a
presence bit per port) is in crosstalk-link.md.

### 2.6 Reset micropatterns

Two special patterns exist on the wire, a **warm reset** and a **link reset**
(Crossbow spec pp. 132-133, 99). A warm reset reaching any Crossbow port resets
the whole switch core and is sent out of every link; a link reset affects the
originating port only. Receivers of either can report it: HEART's widget error
type register has separate bits for a received warm reset and a received link
reset (bits 18 and 17 in the IRIX 6.5 base-release HEART header; the header is not in
the 6.5.30 media). Behaviour
detail is in crosstalk-link.md section 2.7. The bit patterns themselves are
**unknown**.

## 3. Packets

### 3.1 What a packet is

A Crosstalk packet is a **command word**, then, depending on type, a 48-bit
**address**, a 16-bit **remote map field**, a set of **data enables**, and a data
field of 8, 32 or 128 bytes (Crossbow spec section 1.6.3, printed pp. 23-25;
OCTANE report section 2.3.1.1 gives the three sizes as doubleword, quarter cache
line and full cache line). Special packets may use other lengths; their total
must not exceed 140 bytes including the command word (OCTANE report p. 2-14).
**Established.**

The Crossbow's Table 1 and 2 (printed pp. 24-25) draw a request as two header
doublewords followed by data:

| Doubleword | Bits 63:32 | Bits 31:16 | Bits 15:0 |
|---|---|---|---|
| 0 | command word | remote map field | address 47:32 |

| Doubleword | Bits 63:32 | Bits 31:0 |
|---|---|---|
| 1 | address 31:0 | data enables 31:0 |

Doubleword 1 holds the low address word in its upper half and the data-enable
word in its lower half. Data doublewords follow, lowest address first
(Table 2 shows a quarter-line write with four). The figure labels the address
"48:32", but the field is 16 bits wide and the text says 48-bit address, so it is
bits 47:32. **Established** for write
requests with data; **unknown** (settling test: the Hub or Bridge request-packet table in a specification, or a capture) whether a read request with no data carries the
same two header doublewords, a shorter header, or the same header with unused
enables (see 4.2).

Response packets carry a command word and, for reads, data. Whether a response
carries the address back is **unknown** (settling test: a response-packet field table in a Crosstalk specification page) (the Bridge's response logic keys on the
transaction number, not an address: 3.4).

### 3.2 Command word

The command word is 32 bits. Its layout appears in three places that agree: the
Crossbow and Bridge error-command-word register tables (Crossbow spec Table 12,
printed pp. 85-86; Bridge spec section 3.2, error command word), the shipped
IRIX 6.5.30 `<sys/xtalk/xwidget.h>`, and Linux mainline
`arch/mips/include/asm/xtalk/xwidget.h`. **Established.**

| Bits | Field | Meaning | Grade |
|---|---|---|---|
| 31:28 | DIDN | destination widget number | established |
| 27:24 | SIDN | source widget number | established |
| 23:20 | PACTYP | packet type (3.3) | established |
| 19:15 | TNUM | transaction number (3.4) | established |
| 14 | CT | coherent transaction | established |
| 13:12 | DS | data size (3.5) | established |
| 11 | GBR | the packet is on the guaranteed-bandwidth ring (priority class) | established |
| 10 | VBPM | virtual backplane message | established |
| 9 | ERROR | the sender marks the packet as carrying an error | established |
| 8 | BO | barrier operation | established |
| 7:0 | reserved | | established |

**The introductory table in the Crossbow specification disagrees.** Table 1 on
printed p. 24 lists TNUM at 23:19 (five bits) and the packet type at 18:15 (four
bits), with a caption on the type row that reads "Write Request w/ Response".
Table 1 is self-consistent: every field still fits above the reserved bits 7:0.
The disagreement is only the order of the two fields. Table 12 (the error
command word register, pp. 85-86), the Bridge spec's error command word table
(PACTYP 23:20, TNUM 19:15) and both operating systems' masks put the packet type
above the transaction number. Three sources against one, so this page follows
Table 12 and the headers; Table 1's order is probably a documentation slip, which
is **inferred**. The same bit positions appear independently in the SHub II
spurious-response capture register (Linux ia64 `shubio.h`, `ii_ixsm`: DIDN,
SIDN, PACTYP, TNUM, CT, DS, GBR, VBPM, ERROR, BO from the top of a 64-bit header
word, in that order and with those widths). Grade: **established** for the
layout, **inferred** that the capture registers store the on-wire word
unmodified.

**Where a software-visible copy exists.**

- Crossbow, Bridge and HEART latch the command word of the first failed packet
  in the common widget error command word register (offset 0x40 of the 8-byte
  slot, so `+0x44` as software addresses it), together with its 48-bit address
  (`0x10`/`0x18`). It is part of the common widget block, so any widget has one.
- The Origin Hub keeps a per-request record for each incoming widget request,
  with the source widget (4 bits), the transaction number (5 bits), an
  error-bit-set flag, a barrier flag, a response-required flag, a GBR flag and a
  size field (IRIX 6.5.30 `<sys/SN/SN0/hubio.h>`, request buffer entries A to C).
  The Hub's records give "needs a response" and "size" as separate fields, so
  they are decoded from, but not identical to, the PACTYP bits. **Inferred.**

### 3.3 Packet types

The 4-bit PACTYP field. Rows 0 to 4, 6, 8, E and F are named in the shipped
IRIX 6.5.30 `<sys/xtalk/xbow.h>` (symbols `XBCMDTYP_*`) and in a Linux 2.5.0
ia64 header (`include/asm-ia64/sn/xtalk/xbow.h`, tag `v2.5.0`); the other
values are named "Reserved" in that Linux header's decoder table
(`arch/ia64/sn/io/pcibr.c`, lines 192-216).

| Value | Name | Direction | Notes |
|---|---|---|---|
| 0 | read request | toward the target | **established** (names above) |
| 1 | read response | back to the requester | |
| 2 | write request, response wanted | toward the target | |
| 3 | write response | back to the requester | no data |
| 4 | write request, no response ("fire and forget") | toward the target | |
| 5 | reserved | | |
| 6 | fetch-and-op | toward the target | atomic memory operation |
| 7 | reserved | | |
| 8 | store-and-op | toward the target | |
| 9-D | reserved | | |
| E | special request | | length set by the sender, at most 140 bytes total |
| F | special response | | |

**Established** that these are the values; **inferred** that the names in the
Crossbow spec's Table 25 are the same list. The OCTANE report names the same
eight classes (read request and response, write request and response,
fetch-and-op, store-and-op, special request and response) and groups them as four
basic packets, two memory-operation packets and two special packets (section
2.3.1.1).

**What the endpoints accept.** Neither the Crossbow nor a Bridge supports fetch,
store or special packets. Both log them as an "invalid packet type" error,
together with reserved values and, at the Crossbow's widget 0, any response
packet (the Crossbow "never issues requests which result in responses", so none
is expected there). Crossbow spec Table 5, printed p. 69; Bridge spec Table 54,
pp. 79-80. The
fetch-and-op and store-and-op packets are for memory-side atomic operations;
whether they cross a Crossbow toward a Hub is **unknown** (settling test: the Hub specification's list of packet types a Crossbow port accepts, or a Hub-side error log from such a packet) (the Crossbow forwards
by destination and size without decoding the operation, Table 25, but the
operations go to a memory special region, not a widget; see crosstalk-link.md
section 2.2).

**Write response.** A Bridge never asks for write responses, so receiving one is
an error there (Bridge spec Table 53, p. 78). A Hub can ask for one: the Hub's
PIO tracking has a "fire and forget" mode that launches writes without a
response and a conveyor mode that waits (IRIX 6.5.30 `<sys/SN/SN0/hubio.h>`
PIO read-tracking (PRB) fields and mode values). Which PACTYP the Hub emits in
each mode is **inferred** to be 4 and 2; the response-wanted choice is a
separate flag in the Hub's own records. Test: a capture of a Hub PIO write.

### 3.4 Transaction numbers

A 5-bit TNUM ties a response to a request and, at a Hub or Bridge, carries a
source identity. **Established for the Bridge** (Bridge spec section 7.3, printed
p. 88):

| TNUM | Used by Bridge for | Grade |
|---|---|---|
| `0x00`-`0x0f` | read requests: the number of the response buffer assigned to the read | established (Bridge spec rev 4.0, section 7.3, p. 88: "valid value are 0x0-0xf"; the Xbridge spec rev 0.5 repeats the tnum 0 to 15 limit for read responses) |
| `0x10`-`0x17` | PCI write requests: `0x10` plus the PCI device number | established (same passage: "valid value are 0x10-0x17") |
| `0x18`-`0x1f` | interrupt writes from device pins: `0x18` plus the device number | established (same passage: pin interrupts plus `0x18`, range `0x18`-`0x1f`) |
| `0x1f` | error interrupts | established (same passage) |

Device numbers 0 to 7 would give 0x18 to 0x1f, so device 7's pin interrupt would
share `0x1f` with the error interrupt; the specification does not say how that
is resolved (**unknown**, settling test a specification page on device-7 arbitration, and moot if the Bridge never uses device 7 for an
interrupting pin). The device number is the bus-request/bus-grant pair in use,
"usually but not always" the configuration-space number (Bridge spec p. 118). Receiving a read response whose TNUM is above 15, or whose buffer is not
armed for a response, raises the "unexpected response" error and stores the
command word in the auxiliary error command word register (Table 53, p. 78).

A response carries the request's TNUM back. **Established** for the Bridge (its
response buffers are indexed by it); **inferred** generally, that DIDN and SIDN
are swapped on the way back. A Hub keeps the TNUM of an incoming request
(`tnum` in its request buffer entry). How a Hub chooses the TNUM of a PIO request it launches is
**unknown**: the Hub header and error handler describe only incoming-side fields. Settling test: the Hub specification's outgoing request-buffer description; no held code sets it.

### 3.5 Data size and byte enables

**DS values** (Crossbow spec Table 12 field; IRIX `XBCMDSZ_*` symbols):

| DS | Data field | Name |
|---|---|---|
| 0 | up to 8 bytes | doubleword |
| 1 | up to 32 bytes | quarter cache line |
| 2 | 128 bytes | full cache line |
| 3 | reserved | the Crossbow's micropacket-count table treats 3 like 2 for read response and write request (Table 25, p. 94), but nothing uses it |

The Hub's incoming-request record uses the same encoding for its size field
(0 = 8 bytes, 1 = 32 bytes, 2 = 128 bytes, 3 reserved). **Established.**

**Data enables.** Only doubleword and quarter-line packets carry a data-enable
word (Bridge spec section 7.2, printed pp. 86-87): a doubleword packet uses the
low 8 bits to pick bytes of its one data doubleword; a quarter-line write uses 32
bits, one per byte of its four doublewords. A full-line packet has no enables and
transfers all 128 bytes. The enabled bytes need not be adjacent. **Established**
(Bridge). Whether a quarter-line *read* request carries enables, and what the
enables of a read mean to the responder, is **unknown** (settling test: the Crossbow request-packet table for read packets): the Bridge spec
describes enables for "the double-word read/write packets and the quarter
cache-line write packets" only.

**Byte numbering.** The Crosstalk specification, as quoted in the Bridge spec,
names bytes by *Data Section* (DS), counting from the most significant byte of
the doubleword: DS0 is bits 63:56, DS1 is 55:48, and so on, whatever the
processor's endianness. DEn enables DSn; for the second doubleword of a quarter
line DE8 enables its DS0, DE16 the third doubleword's DS0 and DE24 the fourth's
(Bridge spec p. 87). **Established** for the Bridge spec's statement. In big-endian
mode DS n is byte n; in little-endian mode DS n is byte 7 minus n.

**A conflict about the register half.** Every widget register is 32 bits, placed
on data bits 31:0 of its 8-byte slot, and accessed with a doubleword packet and
four data enables (Bridge spec printed p. 14: "double-word packet type with 4
data enables only"; Crossbow spec p. 72 section 3.2: "Crosstalk Data_Enable =
0x0f"). By the Bridge's own DS numbering, bits 31:0 are DS4 to DS7 and the enable
word would be `0xf0`, not `0x0f`. Either the two specifications number the
enables from opposite ends, or "0x0f" is shorthand for the four enables in the
low word. **Unknown.** Test: capture the enable word of any 32-bit register read
and see whether its set bits are the low four or the high four of the byte field.
Established either way: the 32-bit register is in the low half of the doubleword,
which is why software reaches every register at the 8-byte slot offset plus 4.

Only doubleword packets reach a Crossbow or Bridge register. Any other packet
size aimed at them is an error (Crossbow spec Table 5, p. 70; Bridge spec p. 14).

### 3.6 Packet sizes in micropackets

The Crossbow forwards a packet knowing in advance how many micropackets it has,
by decoding the type and size fields and ignoring the tail marker (Crossbow spec
section 3.4.5 and Table 25, printed pp. 93-94, checked against the page image).
**Established** for the rows given; the table has gaps (below).

| PACTYP | DS 00 | DS 01 | DS 10 | DS 11 | Grade |
|---|---|---|---|---|---|
| 0001 read response | 1 | 3 | 9 | 9 | established |
| 0010 write request, response | 2 | 3 | 9 | 9 | established |
| 0011 write response | 1 (any DS) | | | | established |
| 0100 write request, no response | 2 | not listed | not listed | not listed | established |
| 0101 | 1 | not listed | | | established |
| 0110 fetch-and-op | 1 (any DS) | | | | established |
| 0111 | 1 | | | | established |
| 1000 store-and-op | 2 | | | | established |
| 1001-1101 | 1 | | | | established |
| 1110, 1111 special | 9 (any DS) | | | | established |

The counts agree with a header of two doublewords plus data: a doubleword
response is a 64-bit header plus one data doubleword (1 micropacket of 128 bits);
a quarter-line response is 8 + 32 = 40 bytes (3 micropackets); a full line is 8 +
128 = 136 bytes (9 micropackets). A write request is 16 + 8 = 24 bytes (2), 16 +
32 = 48 (3) and 16 + 128 = 144 (9). That supports the two-doubleword request
header of 3.1 and a one-doubleword response header. **Inferred** (the
arithmetic fits; the table does not state the header sizes).

The OCTANE report's 140-byte ceiling for a special packet does not match a
9-micropacket maximum of 144 bytes (a full-line write with two header doublewords).
Either the report rounds loosely or the headers are shorter than 3.1 draws them;
**unknown**. Settling test: the micropacket-count table in the specification, or a link capture.

**Gaps in the table.** There is no row for PACTYP 0000 (read request), although
that value is named in the software headers. There is no row for type 0100
(no-response write) with a quarter-line or full-line size, although a Bridge's
posted DMA writes are 32-byte or 128-byte packets and never ask for a response
(Bridge spec p. 72; 5.3). Either Table 25 is incomplete, or those writes use a
different encoding than the software names suggest. **Unknown.** An earlier
research note warned that this table must not be used to reject type 0; that
caution stands. Test: capture a Bridge DMA write and read its PACTYP and DS.

## 4. Transfers

### 4.1 Doubleword access

A processor load or store of up to 8 bytes to widget space, and every register
access, travels as a doubleword packet with data enables. The Bridge and
Crossbow specifications describe register access this way (Bridge spec p. 14;
Crossbow spec p. 72), and SGI's Bridge text describes the whole 16 MB widget
space as reached by doubleword packets. What a 1-, 2- or 4-byte store to a
*device window* becomes (the enables chosen) follows from the same packet; the
processor-side rules differ per host. **Inferred** for the device windows,
**established** for registers.

### 4.2 Reads of a block

The three read sizes are 8 bytes, 32 bytes and 128 bytes (OCTANE report 2.1.6
and 2.3.1.1). A Bridge picks the size by the kind of PCI read:

- A "precise" read (an attribute bit in the device register, page-table entry or
  64-bit PCI address) asks for just the enabled bytes as a doubleword;
- an ordinary read fetches the whole 128-byte cache line and holds it in a read
  response buffer;
- a "prefetch" read fetches the line and then following lines, up to the free
  buffers assigned to the device, stopping at a page boundary unless the device
  allows crossing.

Bridge spec printed pp. 72-74 (read buffers and prefetch) and 88; the
precise-read shape and the attribute bits come from the XBridge specification
0.5 section 9.3 (pp. 210-214) and the Linux Bridge header (`BRIDGE_DEV_PRECISE`,
`BRIDGE_DEV_BARRIER`). **Established** for Bridge prefetch and buffers;
precise reads are **established** for XBridge and **inferred** for the Bridge
from the shared device-register bit.

A response for a block read comes back as a read response of the same DS. Its
data are in address order. Responses of several outstanding reads can arrive
interleaved by request but each in one piece; the Bridge allows sixteen
outstanding reads and expects "responses arriving back to back" (Bridge spec p.
88). Ordering between responses of different TNUMs is **unknown**. Test: capture
two overlapped Bridge reads.

### 4.3 Writes of a block

A Bridge holds up to three cache-line or quarter-line write requests, or fifteen
read or doubleword-write requests, in its inbound request buffer (Bridge spec
section 5.2, printed p. 72). For PCI writes it gathers data in 128-byte buffers
and sends a full-line write when one fills, or a smaller write with enables for
partial fills or non-adjacent bytes (XBridge spec section 9.3.2, pp. 213-214, as
read for the Bridge datasheet; **established** for XBridge, **inferred** for the
Bridge). It never asks for a response to a write: receiving a write response is an
error there (Bridge spec Table 53, p. 78). The PACTYP of the 32- and 128-byte
writes is a gap in the Crossbow table (3.6).

The Hub block-transfer engine (BTE) moves 128-byte cache lines between nodes
and into widget space; its requests are tracked as "BTE" initiators in the Hub's
records and are distinct from processor PIO (IRIX 6.5.30 `hubio.h`, request-type
list: block read, BTE read, BTE exclusive read, write invalidate, PIO read, PIO
write, fetch-and-op, store-and-op, peer-to-peer write). The request-type list is
the Hub's internal vocabulary; how each one maps onto PACTYP on the Crosstalk
side is **inferred** only for the PIO read and write and **unknown** for the rest (settling test: the Hub specification's packet-type mapping table).
A "peer to peer write" entry means one widget writing to another through the Hub
and Crossbow without touching memory; the patent US 5,991,824 describes the peer
I/O mechanism.

### 4.4 Ordering, barriers and flush

A **barrier** bit (BO) in the command word orders the packet after earlier ones
from the same source; the Hub keeps a bit vector of earlier request-buffer entries
that must retire before a barrier operation is processed (IRIX 6.5.30 `hubio.h`,
CRB register D). The Bridge sets the barrier bit from a per-device, per-page-entry
or 64-bit-address attribute (Bridge spec Device(x) register; XBridge Tables 86-93).
**Established** that the bit exists and who sets it; its precise ordering
guarantee on the wire is **unknown** (settling test: the specification's ordering-rules section).

A read of a widget's **target flush** register (offset 0x50) completes only after
every earlier access to that widget has completed; that is how software makes a
posted write visible (crosstalk-link.md section 3.3). A Crossbow also has a
per-link **input-buffer flush** read: it marks every packet in that link's
input buffer, and its response waits until all marked packets leave (Crossbow
spec pp. 70-71, section 3.1.2). **Established.**

Responses are sent ahead of the widget's own requests. The Bridge spec says so
as a rule for all widgets ("As in all Crosstalk widgets, the Bridge will always
send Crosstalk responses ahead of Bridge requests", printed p. 89), and the
Crossbow lets responses through a destination that is out of request credits
(spec p. 120). **Established** for the rule; that it is the protocol's deadlock
avoidance is **inferred** (the spec says the packet-count rules exist "to avoid
deadlock conditions", p. 25).

### 4.5 Priority: the guaranteed-bandwidth ring

The command word's GBR bit puts a packet in a high-priority class. Each source
gets a programmable count of GBR packets per fixed interval at each destination;
when it is spent the packet drops to the normal "remainder ring", which is served
round-robin with a per-source weight of 1 to 8 packets (Crossbow spec section 3.1.3, pp. 71-72, and the arbiter text, pp. 119-120; OCTANE report 2.1.4; US 5,909,594 and US 5,784,569). This is arbitration
inside a switch; it changes order and latency but not packet contents.
**Established.**

## 5. Interrupts are write packets

**Established**, from the Bridge spec (Chapter 11, printed pp. 117-118), the
Crossbow spec (section 3.1.1, printed pp. 64-65), the OpenBSD and Linux drivers
and the shipped IRIX kernel.

A widget has no interrupt wire. It sends a **doubleword write request** to an
address its host owns. The data word carries the interrupt number in bits 7:0
and, in bit 8, whether to set the host's pending bit (1) or clear it (0). The
widget's own number is in the command word SIDN field of the packet; it is not
repeated in the data (**inferred**: an interrupt is an ordinary write packet).

- **Crossbow.** When an error needs reporting, widget 0 sends two packets: a *set*
  packet when the condition appears and a *clear* packet when software clears the
  condition in the status register. Only one interrupt is outstanding at a time;
  further events are folded into status bits until the first is cleared
  (spec pp. 64-65). The address is taken from the interrupt destination register
  pair (`0x30`/`0x38`): bits 31:24 of the upper word are the vector, 19:16 the
  target widget (DIDN), 15:0 address bits 47:32; the lower word is address bits
  31:0 (spec; confirmed by IRIX 6.5.30 `xbow.o`, `xbow_intr_preset`, offset
  0x9b0, which writes exactly that composition).
- **Bridge.** Eight pins. Each pin has a host-address register with the vector
  in its low byte and, in higher bits, an address overlay and the node number.
  Enabling a pin sends the *set* packet when the pin asserts; a second enable (in
  the interrupt mode register) sends a *clear* packet when it deasserts. Both
  enables must be on for a clear packet. Error interrupts send *set* only, use the
  main interrupt destination with no overlay, and use one level for all errors
  (Bridge spec printed pp. 116-118; INT_MODE register, printed p. 39). The
  per-pin register layout (vector in 7:0, host field in 17:8) is in the Linux
  Bridge header (`BRIDGE_INT_ADDR_FLD`, `BRIDGE_INT_ADDR_HOST`).
  An interrupt pin assigned to a device also flushes that device's write buffers
  first, so the interrupt packet follows the data on the wire (Bridge spec p.
  118). **Established.**
- **Interrupt TNUM.** A Bridge's interrupt packets carry `0x18` + device number,
  or `0x1f` for errors (3.4).

**Where the packet lands depends on the host.**

| Host | Address the widget is told to write | Source |
|---|---|---|
| HEART (Octane, Octane2) | offset `0x80` of HEART's own widget space, where the IRIX 6.5 base-release HEART header places an interrupt status register | OpenBSD `sys/arch/sgi/xbow/xheart.c` (`xbow_intr_address = 0x80`); Linux `arch/mips/sgi-ip30/ip30-xtalk.c` (`HEART_INTR_ADDR 0x80`) |
| Hub (Origin 200/2000/Onyx2) | address bit 47 set, plus `0x0180_0000`, plus offset `0x90`, the processor interface's "write to set pending interrupts" register; the node number is merged in through each Bridge pin register | Linux `arch/mips/sgi-ip27/ip27-xtalk.c` (`BIT_ULL(47) + 0x01800000 + PI_INT_PEND_MOD`), `arch/mips/pci/pci-xtalk-bridge.c`, `asm/sn/sn0/hubpi.h` |
| Bedrock | not examined for this page | |

**Established** for the three rows above as software settings. What the host does
with the packet (decode vector, set a pending bit, raise a processor interrupt)
is host-specific.

Software that wants an interrupt cleared after servicing it must do so at both
ends: the widget's clear packet clears the host's pending bit. The Crossbow spec
warns the programmer not to disable the interrupt enable bit once set
(spec p. 64). **Established** (text).

**Switches do not interpret interrupts.** A Crossbow in the middle of a path
forwards an interrupt packet like any other write: the Bridge spec calls it "a
crosstalk double word write packet" (Chapter 11) and the Crossbow routes by DIDN
only (section 7). **Inferred** from those two statements.

## 6. Credits and flow control

Three separate mechanisms limit the traffic. They share the sideband and the
word "credit", which causes mix-ups.

### 6.1 Packet buffers at the next hop (sideband credits)

**Established** from the Crossbow spec (sections 1.6.5, 4.3.11, printed pp. 27-28,
112 and 123).

- The Crossbow has **four input packet buffers** per link. A widget may not send
  a packet into the Crossbow unless it holds a credit. It starts with a count
  equal to the number of buffers (programmed into the widget's own control
  register, field "crossbar credit"), subtracts one for each packet it sends, and
  adds one for each "free buffer" signal received in the sideband of micropackets
  coming back. The Crossbow raises that signal when it has finished dispatching
  a packet out of the buffer.
- The credit return travels in the sideband of ordinary reverse traffic, or, with
  no traffic, in a micropacket of its own with an administrative bit set (spec p.
  123).
- Over-sending (a packet arriving when no buffer is free) drops the packet and
  sets the link's "input overallocation" error (spec Table 4, p. 68). The cause
  is a widget believing the Crossbow has more than four buffers.

This count is stored by each widget in its control register ("crossbar credit"):
bits 15:12 in the common widget block and in a Bridge (reset 3), bits 15:13 in a
Hub (reset 2). The IRIX PROM and kernel write 4 into widgets behind a Crossbow
whose revision code is above 2, and 3 behind revision codes 1 and 2 (Crossbow
revisions 1.0 and 1.1); a Hub writes 3 or 4 by the same rule, and the Hub header
says 3 is required by Crossbow 1.1 (IRIX 6.5.30 `<sys/xtalk/xbow.h>` and
`<sys/SN/SN0/hubio.h>`, the Crossbow credit constants of 4, 3 and 4).
**Established** for the values. That the early revisions have three usable input
buffers rather than four is **inferred** from the "required by" comment; the
Crossbow spec describes four.

### 6.2 Request buffers in the widget (widget credits)

**Established** (Crossbow spec p. 78 and 120; IRIX header `XB_CTRL_WIDGET_CR_*`).

A destination widget has a number of request buffers. The Crossbow's link control
register has a 5-bit "widget credit" field (bits 22:18, reset 2) giving that
number. The Crossbow counts request packets forwarded to the widget; when the
count reaches the field it stops forwarding requests to that destination (the
"MAX_REQ" condition) and lets only responses through. The widget returns a credit
by a "free buffer" signal in its sideband when it frees a request buffer. Values the IRIX
PROM writes into that field: 3 for a Bridge port (`BRIDGE_CREDIT`; the Bridge
holds "three" cache-line or quarter-line writes or "up to fifteen" reads or
doubleword writes, and the Crossbow "should be programmed for 3 bridge buffer
locations", Bridge spec p. 72) and 4 for HEART's port (`HEART_CREDIT`).

These are two counters with opposite directions: **widget credit** (in the
Crossbow) is the number of requests the widget can hold; **crossbar credit** (in
the widget) is the number of packets the Crossbow can hold. Mixing them up, or
mis-programming either, produces the over-allocation error above or the Bridge's
"request FIFO overflow" (Bridge spec Table 54, p. 80: "the credit counters in the
crossbow or heart are not programmed correctly") or HEART's crossbar-credit
overflow and underflow bits (IRIX 6.5 base-release `<sys/RACER/heart.h>`, widget error type bits 29 and 28;
the header is not in the 6.5.30 media). Whether the operating system treats them
as signs of a broken credit scheme is not stated in any shipped file.

### 6.3 Responses and credit-less traffic

Response packets are exempt from the request credit; they are always accepted
by the destination's link controller (Crossbow spec p. 120: "link controllers will
only send response packets to this target" once MAX_REQ is set). A write without a
response ("fire and forget") still consumes a request credit at the destination
and returns it when the request buffer frees. **Established** (spec); that the
no-response write uses the same request credit is **inferred** (no sentence states
otherwise).

### 6.4 Hub-side PIO credit

A Hub tracks outstanding processor I/O requests per target widget in a "PRB" with
a credit count and a mode: a plain mode in which writes wait for responses
("conveyor belt") and a "fire and forget" mode that does not wait (IRIX 6.5.30
`<sys/SN/SN0/hubio.h>`, PRB register entries). **Established** that the
mechanism and its two modes exist. Which credit counts and modes software
programs for which widgets, and why, is **unknown** here: no shipped header or
manual states it. Whether a write to a Crossbow's link-reset control returns a
response is likewise **unknown** (settling test: the Crossbow specification's link-reset description, or a capture of a reset write).

The SN0 Hub also has a credit **timeout**: a counter increments every 128 Hub I/O
clocks while outbound credits are below a threshold (1 in direct-connect mode, 2
behind a Crossbow) and raises one interrupt when it reaches the programmed value
(register at `0x4001e0`, name in Linux `sn0/hubio.h` and the later SHub header
`ii_ixcc`). The threshold text is from the SHub header, so for SN0 it is
**inferred**.

### 6.5 Graphics credits

A graphics widget that is driven by uncached processor stores returns **write
responses as credits** to the issuing processor, through a per-node node/widget
map in the Hub (`IIO_IGFX_0/1`, offsets `0x400140` and `0x400148`; Linux
`sn0/hubio.h`; the later SHub II header describes its analogue as "matching up
the incoming responses from the graphics widget to the processor that initiated
the graphics operation"). Whether the widget identifies the stream by a transaction number is
**unknown**: no shipped header or manual states which TNUM a graphics pipe uses.
**Established** that the registers exist and what software writes; **inferred**
that the response is the credit.

## 7. Routing by widget number

**Established** (Crossbow spec pp. 23-24, 99; crosstalk-link.md sections 2.7, 2.8
and 3).

- A packet's DIDN selects the destination. The Crossbow does **no address
  translation**: the 48-bit address passes through unchanged and the DIDN alone
  chooses the output port. A widget address is therefore a widget number plus an
  offset (the Linux `XIO_PACKED` macros keep the number in bits 63:60 above a
  48-bit address).
- A Crossbow has nine ports on its 9-way, 68-bit crossbar: eight external link
  controllers and widget 0, its own register and error endpoint. The external
  ports have widget numbers 8 to F. Numbers 1 to 7 are not ports.
- **A link cannot send to itself.** The crossbar has no loopback and no broadcast
  (spec p. 99, and the arbitration note that link A's own slot in its arbitration
  register "has no meaning").
- **Packets that reach a switch but name no legal port.** The Crossbow maps the
  destination to widget 0, sets the packet's error indication, and handles it like
  a destination timeout: widget 0 records it in the global error registers (command
  word, address) and the receiving link's "illegal destination" status bit is set
  (spec p. 116-117). An interrupt follows if the link's illegal-destination enable
  is on. Only the first erroneous packet is recorded; later ones are suppressed
  until software writes the error command word (spec p. 66, 116). A repeat sets the
  "multiple error" bit.
- **A packet for a legal port whose link has failed or is stalled.** It waits in
  the source link's input buffer until the packet timeout expires (a packet is
  marked at one timeout tick and counts as timed out if still queued at the next).
  The Crossbow then sets the packet's error bit, redirects it to widget 0, which
  logs its command word and address and consumes it, and the packet is lost. The
  source link's destination-timeout bit is set. When a link has hit max retry, its
  stall is released so queued packets flush the same way; when a destination is out
  of request credits, the "max request timeout" bit is set and the port then takes
  requests so the backlog drains (spec pp. 66-67, 115-117). Software sees which
  sources were hurt in the target link's auxiliary status register (timed-out
  source location field). **Established** for a link that was alive. For a port
  that never came up the existing contract in crosstalk-link.md says the request
  is dropped with nothing recorded at the switch, which does not match this
  timeout path; which is right is **unknown** (item 15 in section 11).
- **Where the error is attributed.** The *receiving* link records an
  illegal destination; the source widget number in the retained command word is
  supporting information, not the register selector. IRIX (6.5.30 `xbow.o`,
  `xbow_errintr_handler`, offset 0xd1c) hands such an error to the DMA error path
  only when the command word's SIDN equals the port number it is examining, and
  otherwise prints a generic report.
- **Widget numbers are assigned by software.** The firmware writes each widget's
  own number into its control register bits 3:0 (the control register's widget-number field, mask `0x0000000f` in the IRIX 6.5.30
  and Linux widget headers; the Hub's own is in its widget control). A widget places that
  number in the SIDN of every packet it sends. A widget that has been given the
  wrong number will have its responses mis-routed or its interrupts sent from the
  wrong source; no source states what hardware does. **Inferred.**
- **A Hub or HEART receiving a packet it did not ask for.** The receiving widget
  checks the packet against what it expects. HEART has error-type bits for an
  unexpected response, a request or response in a bad format, a non-head
  micropacket, an overflow of its I/O request buffer, and command and
  interrupt-vector warnings (IRIX 6.5 base-release `heart.h`). A Bridge raises "unexpected
  response" for a response with no armed buffer or a TNUM over 15 (Table 53) and
  "invalid address" for a request to an unsupported address (Table 54). A Hub
  stores the header of a bad incoming network packet in a capture register pair
  and the SHub II adds a "spurious read response" header capture (SHub
  `ii_ixsm`, `ii_ixss`). The wire format of what these capture is partly visible in
  `ii_ixsm` (byte enables in the low 32 bits, then the command word fields from
  bit 59 upward); **inferred** to match the SN0 Hub.
- **Switchless hosts.** With one Bridge directly on a Hub or HEART and no
  Crossbow, the widget number is a convention, not a route: the host presents
  whatever widget identity it is configured for and the Bridge answers every
  address (crosstalk-link.md section 2.8). **Established** for the base Origin 200
  design; Linux's IP27 and IP30 code treats both cases through the same paths.
- **Two hosts on one Crossbow.** Two host ports can share a Crossbow, with its six
  device ports split statically; one host can be reconfigured to own all six if
  the other fails (007-3439-002 printed pp. 84-85). Peer-to-peer packets from one
  widget to another need no host (patent US 5,991,824). The bytes of such a packet
  look like any other; only the DIDN differs. **Inferred.**

## 8. Timeouts and the errors they raise

### 8.1 Timeout ladder

Every layer has its own clock, so a missing response is reported at the layer
that waits longest last. Values below are **established** unless noted; tick sizes
that appear in crosstalk-link.md are not repeated.

| Layer | What waits | Where | Result when it expires | Grade |
|---|---|---|---|---|
| LLP | one micropacket, retries counted | max retry field, widget `0x48` | link fatal error, needs link reset (2.2) | established |
| Crossbow | a packet received but not delivered | packet timeout register `0x28`, 1.28 µs per tick, reset `0xfffff` (Crossbow spec p. 88; the first interval after reset is shorter, 2.56 µs) | destination timeout, packet dropped, error logged | established |
| Crossbow | a packet being received stalls | same register | source timeout: the packet is completed with filler data marked "sideband invalid" (spec pp. 67, 113) | established |
| Crossbow | a destination out of request credit | same register | "max request timeout", port begins taking requests to drain (spec pp. 66-67) | established |
| Crossbow widget 0 | its own response or interrupt packet is not accepted | same | "connection timeout" in widget-0 status (spec p. 69) | established |
| Bridge | a read response | request timeout value register `0x28`, one tick per 960 ns (32 PCI clocks) | interrupt status bit 9 "PCI to Crosstalk read request timeout"; PCI address, buffer number, device saved (Bridge spec printed p. 23 and Table 30) | established |
| Hub | a request-buffer entry | CRB timeout and prescaler (`0x4003b8`, `0x4003c0`) | request-buffer error code "timeout" (IRIX `hubio.h`) | established |
| HEART | a processor I/O read | widget error type "PIO read timeout" bit 3 | bus error to the processor, with the failing address saved (IRIX 6.5 base-release `heart.h`) | established |
| Hub | credits below threshold | `0x4001e0` | credit-timeout interrupt (6.4) | established |

Linux sets the Hub request timeout to 5 ms, below the processor interface timeout
of 10 ms (`arch/mips/sgi-ip27/ip27-init.c`): the requester must give up before
the processor does so the failure can be attributed. **Established** (a
comment in the Linux code, a software choice, not a hardware constant).

The width of the widget request timeout field in a widget other than a Bridge (20
bits at `0x28`) and its tick size outside the Bridge are **unknown** (settling test: the timed unclaimed-widget read at two programmed values on each widget type; hardware, not assumed).

### 8.2 What a receiver does with a bad packet

**Established** from the Bridge (Tables 53, 54, printed pp. 78-80), the Crossbow
(Tables 4 and 5, pp. 67-70), and IRIX handlers.

| Fault | Bridge | Crossbow widget 0 | Grade |
|---|---|---|---|
| Write response where none was asked | unexpected response; command word saved | "invalid packet type": register-access error | established |
| Fetch, store, special request, or a response aimed at it | "unsupported operation"; address and command word saved | register-access error; address and command word saved | established |
| Response with TNUM above 15, or buffer not armed | unexpected response | n/a | established |
| Data size disagrees with the head and tail framing | bad request packet (request) or a flag in the read buffer, later bad response packet when the PCI device reads it (response) | register-access error | established |
| Command-word ERROR bit set, or sideband invalid during data | request: "request crosstalk error", and a write is **not performed**; reads do not check it. Response: flag in the buffer, "response crosstalk error" when read | "crosstalk error" in widget-0 status | established |
| Request address the widget does not support | "invalid address" | register-access error | established |
| Request arrives when the request FIFO is full | request FIFO overflow (credit misprogramming) | n/a (input overallocation on the link) | established |
| Request to a read-only register | n/a | register-access error | established |

The ERROR bit in a command word is how a responder reports "I could not do it";
the Bridge sets it on a response when its SSRAM has a parity error (Bridge spec
section 6.3, printed p. 82), and the Bridge's own table gives "a memory read with
an unrecoverable error" as the example of a response that arrives with it set, so
the memory-side host sets it (**inferred**). The receiving side then raises its
own error. In the
Hub it becomes the request-buffer error code "incoming crosstalk packet had its
error bit set" (code 7 in IRIX `hubio.h`; the kernel prints "Xtalk Packet with
error bit set to hub %d", IP27 `kernel.o`, string at file offset 0x49508). A
sideband-invalid indication means "the data after this point is not valid"; it is
what a switch asserts on padding after a stalled source, and the Bridge table
gives the same example (a failure after the command word was sent) for it.
Both indications (error bit, invalid sideband) are **established** as distinct
signals that a Bridge handles alike: each raises the crosstalk-error status bit of
its direction.

First-error-latch semantics for the saved command word and address, and how each
chip clears them, are in crosstalk-link.md sections 2.7 and 4; they are not
repeated.

### 8.3 Error reporting by the shipped IRIX kernel

The IRIX 6.5.30 IP27 `xbow.o` carries, as strings, a report for each Crossbow
link status bit (file offsets 0x50e0 to 0x5218): "Invalid Packet Destination",
"Input Overallocation Error", "LLP receive error counter overflow", "LLP
transmit retry counter overflow", "LLP Max Transmitter Retry", "LLP Receiver
error", "LLP Transmitter Retry", "Maximum Request Timeout" and "Source Timeout
Error"; and for widget 0 "Multiple Error", "XIO Error" and "Register Access Error"
(0x5288 to 0x52b0). These match the status bits of the Crossbow link status and
widget 0 status registers (bit positions in the shipped `<sys/xtalk/xbow.h>`).
The kernel treats every one of them except a handled illegal destination and a
transmitter retry (a Bridge/Xbridge workaround) as fatal and panics with "XIO Bus
Error". **Established.**

## 9. A worked example

A processor reads a 32-bit register on a Bridge at widget A behind a Crossbow
(Octane-style layout; host at widget 8), from the point of view of the wire.
Each line below is the layer that handles it; the details of the first two
steps are host-specific and are only sketched.

1. The host emits a read request, PACTYP 0 (read request, **inferred** from the
   software names), DIDN = A, SIDN = 8, DS = 0 (doubleword), address = the
   register's slot offset in the Bridge's 16 MB widget space, enables = the four
   bytes of the low word (3.5), a TNUM of the host's choosing (3.4: how a Hub or
   HEART chooses is unknown). The packet is one or two micropackets (3.6: read
   request count missing from the table).
2. The LLP cuts it into 128-bit micropackets, adds check bits and sequence
   numbers, sends them over a 16-bit path at 400 MHz.
3. The Crossbow's receive logic sees the start code, fills one of four input
   buffers, pushes the destination, priority and type into its request queue,
   wins a connection to port A when it can, streams the packet through the crossbar
   to the destination LLP and returns a free-buffer credit to the host in sideband
   (6.1).
4. Port A's LLP delivers it to the Bridge (8-bit link). The Bridge decodes the
   address, reads the register, returns a read response PACTYP 1, DIDN = 8,
   SIDN = A, DS = 0, the same TNUM and data on bits 31:0 (3.4, inferred).
5. The response crosses the Crossbow, which keeps the request-credit count for
   port A and lowers it when the Bridge returns a free-buffer credit
   (6.2).
6. The host matches the response to its request by TNUM and returns the data to
   the processor.

If the Bridge never answers, the host's own timeout fires (8.1). If the Crossbow
meets a bad destination number at step 3, widget 0 records an error and the host
gets no response either.

## 10. Where the facts live: concordance

| Point | Primary source | Corroboration |
|---|---|---|
| micropacket fields | Crossbow ASIC Spec 12.0, printed pp. 21-22 | 007-3439-002 p. 97; US 6,553,446; OCTANE report 2.1.7 |
| go-back-N retry | Crossbow spec p. 22 | OCTANE report 2.1.7; Bridge spec Table 56 |
| command word | Crossbow spec Table 12, pp. 85-86 | Linux `xtalk/xwidget.h`; IRIX 6.5.30 `<sys/xtalk/xwidget.h>`; SHub `ii_ixsm` |
| packet types, sizes | IRIX 6.5.30 `<sys/xtalk/xbow.h>`; Linux 2.5.0 ia64 `xbow.h` | OCTANE report 2.3.1.1; Crossbow Table 25 p. 94 |
| quarter-line write header | Crossbow Table 2, p. 25 | Bridge spec p. 86-87 |
| TNUM allocation | Bridge spec section 7.3, p. 88 | Hub request-buffer record (IRIX `hubio.h`) |
| interrupts as writes | Crossbow spec pp. 64-65; Bridge Chapter 11 | Linux `ip27-xtalk.c`, `ip30-xtalk.c`; OpenBSD `xheart.c`; IRIX `xbow.o` offset 0x9b0 |
| credits | Crossbow spec pp. 27-28, 112, 120, 123; Bridge spec p. 72 | IRIX 6.5.30 `xbow.h`, `hubio.h` credit constants |
| timeouts, errors | Crossbow Tables 4, 5 pp. 67-70; Bridge Tables 53, 54 pp. 78-80 | IRIX `xbow.o` strings 0x50e0-0x52b0; `kernel.o` strings 0x46af0-0x49680 |
| routing | Crossbow spec pp. 23-24, 99, 116-117 | 007-3439-002 pp. 84-85 |

## 11. Only a bus capture could settle these

Each is **unknown** now. The test names what to record on a real link.

1. **Micropacket bit order.** Which halfword holds the check bits, where the
   transmit and receive sequence numbers sit, and the CRC polynomial, initial value
   and coverage. *Capture* one micropacket with known data; compare candidate CRC-16
   settings.
2. **Sideband encoding.** The position of start, stop, invalid, free-buffer credit
   and administrative bits within the 8 sideband bits, and the head/tail marking of
   multi-micropacket packets. *Capture* a read of each size and a credit-only
   micropacket.
3. **Null micropacket and idle behaviour.** What a link sends when idle and
   whether it is distinguishable from a credit-only micropacket. *Capture* an
   idle link.
4. **Reset micropatterns.** The warm-reset and link-reset encodings and the width
   negotiation exchange (the alternating 8-bit and 16-bit reset micropackets).
   *Capture* a link reset from reset to alive.
5. **Read request header.** Whether a read request has one or two header
   doublewords and whether it carries a data-enable word at each DS. *Capture* a
   read at DS 0, 1 and 2.
6. **PACTYP and DS of block writes.** Table 25 has no row for type 4 above DS 0
   and none for type 0; the real PACTYP of a Bridge's 32- and 128-byte DMA writes
   and the Hub's block writes is unknown. *Capture* a Bridge DMA write.
7. **Byte-enable numbering.** Whether the enable word of a 32-bit register access
   is `0x0f` or `0xf0` in the word's low bits, i.e. whether DE0 is the most or
   least significant byte. *Capture* any 32-bit register read.
8. **Response header.** Whether a response carries the address, and whether DIDN
   and SIDN are swapped back. *Capture* a read and its response.
9. **Hub-chosen TNUM, flags and response choice.** How the Hub picks TNUM for a
   PIO read and write, and the CT, GBR, BO flags and the response-wanted choice
   for the same. *Capture* Hub PIO traffic in conveyor and fire-and-forget mode.
10. **LLP window.** The real window size (the 4-bit sequence numbers allow up to
    15) and retry timing. *Capture* a link with injected bad micropackets (the
    force-bad-LLP bit on a Crossbow link or widget control register injects one;
    the Crossbow spec calls it a one-shot, spec p. 78).
11. **Ordering between responses of different TNUMs** and the exact barrier
    guarantee on the wire.
12. **Misrouted packets inside a link reset.** What happens to a packet that
    arrives while a link reset is in progress (crosstalk-link.md section 11 has
    the same question).
13. **Whether fetch-and-op and store-and-op packets cross a Crossbow toward a Hub,**
    and what a Hub does with one.
14. **Whether a Crossbow of revision code 2 or below really has three usable input
    buffers** (6.1) rather than four. *Measure* by sending four back-to-back packets
    with a crossbar credit of 4 and watching for the input overallocation bit.
15. **What happens to a packet addressed to a legal port that never came up.** The
    timeout path (7) logs and consumes it; the existing sheet says nothing is
    recorded. *Capture* a request to an empty port and read widget-0 status and the
    source link status afterward.

## Sources

Published SGI documents:

- *Crossbow ASIC Specification*, revision 12.0, 14 November 1996 (printed dates 11/14/96 and 11/18/96 appear on
  its pages), 134 pages, held by this project as a scan; pages cited by printed number. Marked proprietary;
  facts restated in our own words with page numbers. The OCR of the scan is unreliable for digits; every
  numeric value used here was cross-checked against another source or read from the page image (Tables 1, 2, 12
  and 25 were read from images).
- *Bridge ASIC Specification*, revision 4.0 (27 March 1997 on its pages), cited by printed page.
- *XBridge ASIC Specification*, revision 0.5, for the read and write shapes in 4.2.
- *Origin and Onyx2 Theory of Operations*, 007-3439-002; *Origin Family Memory Map*, 007-3410-001; the
  *OCTANE Technical Report* (first-party architecture report).
- US 6,553,446 B1 (modular I/O controller, SGI), US 6,683,876 B1 (packet-switched router), US 5,909,594 and US
  5,784,569 (bandwidth allocation), US 5,991,824 (peer-to-peer I/O). Cited for the micropacket field widths, the
  8-to-128-byte packet range, the guaranteed-bandwidth ring and the peer-to-peer mechanism only. US 5,974,456 and
  US 5,604,866 were not read (image-only scans).

Shipped IRIX binaries and headers (IRIX 6.5.30, as installed under `/usr/cpu/sysgen/IP27boot/` and `/usr/include/sys/`):

- `xbow.o` strings at file offsets 0x50e0-0x52b0; `xbow_intr_preset` at 0x9b0; `xbow_errintr_handler` at 0xd1c.
- `kernel.o` strings at file offsets 0x46a30-0x49680 (Hub widget status, request-buffer fields, error reports).
- Header symbols in `<sys/xtalk/xwidget.h>`, `<sys/xtalk/xbow.h>`, `<sys/SN/SN0/hubio.h>`, `<sys/PCI/bridge.h>`.
  Values are stated in our own words; no header text or comments are reproduced.
- IRIX 6.5 base-release `<sys/RACER/heart.h>` for the HEART error-type bits (not present in the 6.5.30 media).

Public drivers:

- Linux mainline (checkout at `db2ddb87143519e20a95aa36c60b36107b736a58`): `arch/mips/include/asm/xtalk/xwidget.h`,
  `arch/mips/include/asm/xtalk/xtalk.h`, `arch/mips/include/asm/pci/bridge.h`, `arch/mips/sgi-ip27/ip27-xtalk.c`,
  `arch/mips/sgi-ip27/ip27-init.c`, `arch/mips/sgi-ip30/ip30-xtalk.c`, `arch/mips/pci/pci-xtalk-bridge.c`,
  `arch/mips/include/asm/sn/sn0/hubio.h`.
- Linux 2.5.0 (tag `v2.5.0`): `include/asm-ia64/sn/xtalk/xbow.h`, `arch/ia64/sn/io/pcibr.c`.
- Linux ia64 SHub header `arch/ia64/include/asm/sn/shubio.h` (removed from mainline with the SN2 platform; read from the parent of commit `cf07cb1ff4ea`), for the later chip's capture registers (a later
  generation than the Hub and Bedrock, used as supporting evidence only).
- OpenBSD `sys/arch/sgi/xbow/{widget.h,xheart.c}` on branch `sgi-is-alive-at-7.9`.

## Corrections (2026-11-10)

- 3.2: the Crossbow Table 1 discussion said five TNUM bits plus four type bits
  would not fit. They fit. The real difference is only the field order (Table 1
  puts TNUM above the type; Table 12, the Bridge spec and both operating systems
  put the type above TNUM). Reworded.
- 2.3: the Hub burst, retry and null-timeout values were presented as defaults.
  They are modelling choices in the project's Hub datasheet; regraded unknown.
- 3.4 and 6.5: removed the claim that software uses a constant transaction
  number for a graphics pipe's credit stream. Nothing shipped supports it; the
  stream's TNUM is now unknown.
- 6.2, 7, 8.1 and the HEART rows: the HEART header exists only in the 6.5
  base-release media, not 6.5.30; citations fixed. The "design flaw" wording
  has no support in the shipped header or either public driver, removed.
- 6.4: removed the PIO credit counts and the fire-and-forget rationale, which
  nothing shipped supports; only the mechanism shipped in the Hub header is kept.
- 6.1, 7, concordance and Sources: credit constants now cite the shipped 6.5.30
  headers; dropped the statement that kernel and PROM source was read.
- Not re-checked (unchanged): page numbers, Table 25 counts, patents, the
  OCTANE and Theory of Operations citations, XBridge claims.
