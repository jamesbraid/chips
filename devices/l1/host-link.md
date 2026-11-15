# L1 host link: UART, framing and message layout

How a node's software talks to the L1 system controller of its brick: the serial port the node chip provides, the byte
framing on it, and the layout of the messages it carries. This page covers the three platforms that share the protocol:
the Origin 3000 family (Bedrock node, MIPS), SN1 on IA-64 (the same Bedrock node with Itanium processors, see
[platforms/sn1-ia64](../../platforms/sn1-ia64/README.md)) and SN2 (Altix, SHub node, see [platforms/sn2](../../platforms/sn2/README.md)).
The register census and the IRIX request codes are in [README.md](README.md); the controller side of the same wire is in
the sysco repository. The L2 and L3 are in [../l2/README.md](../l2/README.md) and [../l3/README.md](../l3/README.md).

## Sources and grades

Grades follow [AGENTS.md](../../AGENTS.md).

- **SGI Linux, SN1 on IA-64**, `arch/ia64/sn/io/l1.c` and `include/asm-ia64/sn/ksys/l1.h`,
  `include/asm-ia64/sn/sn1/uart16550.h` at Linux v2.5.0 (`linux-history` snapshot, commit 381ab1f5). SGI's own platform
  code for the Bedrock node, so what it defines is **established**. It is the only readable source that names the
  fields of the link header and message body.
- **SGI Linux, SN2**, `arch/ia64/include/asm/sn/sn_sal.h`, `intr.h`, `l1.h`, `drivers/char/snsc.c`, `snsc.h`,
  `snsc_event.c` at Linux v5.3: the host side of SN2, which reaches the controller only through PROM calls.
- **IRIX 6.5.30** `l1.o` and `l1_command.o` (see [README.md](README.md)): the shipped objects, which confirm the register
  accesses and the framing on the MIPS Bedrock node.
- **Shipped SN2 PROM and controller firmware**, as read in the sysco repository: `software/firmware/l1/sn2-prom-link-1.62.1.md`,
  `node-link-sn1-vs-sn2.md`, `sn2-controller-host-protocol.md` and the chips page
  [software/firmware/snprom/boot-sequence.md](../../software/firmware/snprom/boot-sequence.md). Cited as written there; no
  binary was re-read for this page.
- **SGI manuals:** *SGI L1 and L2 Controller Software User's Guide* 007-3938-005 (2006) and *SGI Altix 3000 User's Guide*
  007-4579-001, by printed page.

No Ghidra export was made for this page.

## Where the UART is

| Platform | Window | Register spacing | Grade |
|---|---|---|---|
| Origin 3000 (IRIX, MIPS) | node-local special space at offset `0x80` from `0x9000000030000000` plus the node number shifted left 33; the router brick's second UART is reached by vector packets instead | 8 bytes, 64-bit loads and stores of the low byte | established (IRIX `l1.o`, [README.md](README.md)) |
| SN1 on IA-64 (Linux) | the node's remote special space plus `0x80` (`HSPEC_UART_0`); a router's UART through the router's second JBUS bank (`RR_JBUS1`), by vector read and write | 8 bytes (`reg << 3`) | established for the code. Whether the IA-64 port's early console alias is real hardware or a simulator model is open: [questions/sn1-ia64-bedrock-uart-location.md](../../questions/sn1-ia64-bedrock-uart-location.md) |
| SN2, SHub 1 (the generation the SAL 5.04 PROM image in the boot-sequence page serves; which Altix models carry it is not settled) | the SHub junk bus, local offset `0x7_fed4_0000`, global form `0xf_fed4_0000` with the NASID at bit 38 and above, so the UART follows the four LED registers (`0x7_fed0_0000` to `0x7_fed3_0000`, 64 KiB apart) | 8 bytes, index 0 to 7 | established for the PROM's accesses ([boot sequence](../../software/firmware/snprom/boot-sequence.md#l1-controller-dependency)); the register meanings are the 16550 ones, inferred from the same indexing as the Bedrock block |
| SN2, SHub 2 (the Altix 4700 compute blades are SHub 2.x per 007-3938-005 p.50) | not read | not read | unknown. The SHub 2 LED registers sit at `0xf000_0000` (`SH2_REAL_JUNK_BUS_LED0`), so a junk-bus UART is likely nearby, but no source places it. No SHub 2 PROM is held |

Interrupt line: on SHub the pending junk-bus UART interrupt is bit 20 of the event-occurred register (`uart_int`,
[devices/shub](../shub/README.md); Linux v5.3 `shub_mmr.h`), and the vector the Linux kernel reserves for it is `0xe9`
(`SGI_UART_VECTOR`, `intr.h`), shared by the console and the controller subchannels. Established. On Bedrock the IRIX
object tests bit 4 of the local-block word at `+0x800098` ([README.md](README.md)); Linux v2.5.0 `l1.c` has no interrupt
handler for it of its own (receive is polled from `brl1_receive`), so the Bedrock line stays as the README grades it.

**SN2 Linux never touches this UART.** The kernel calls the PROM (`SN_SAL_CONSOLE_*`, `SN_SAL_IROUTER_OP`), and the PROM
owns the wire. Established, `sn_sal.h`, `snsc.c`, `sn_console.c`; the calls are listed in sysco
`software/firmware/l1/sn2-controller-host-protocol.md`. A machine model that runs the real PROM needs the UART; one
that supplies its own SAL needs only the call layer described at the end of this page.

## The register file

Both Bedrock readings agree on a 16550-style file with 8-byte spacing. Offsets are from the UART base; the Origin 3000
base is `0x80` into the local special space, so the first column adds that.

| Index | Origin 3000 offset | Linux name | Use by software | Grade |
|---|---|---|---|---|
| 0 | `+0x80` | `REG_DAT`, `REG_DLL` | transmit and receive byte; low divisor byte while the divisor latch is open | established |
| 1 | `+0x88` | `REG_ICR`, `REG_DLH` | interrupt enable (bit 0 receive data, bit 1 transmit holding empty, bit 2 line status, bit 3 modem status); high divisor byte while the latch is open | established |
| 2 | `+0x90` | `REG_ISR` (read), `REG_FCR` (write) | read: `0x02` transmit ready, `0x04` receive ready, `0x06` line status, `0x00` modem status, `0x0c` FIFO timeout (IRIX tests mask `0x6` then bits 2 and 1). Write: bit 0 FIFO enable, bit 1 clear receive FIFO, bit 2 clear transmit FIFO | established |
| 3 | `+0x98` | `REG_LCR` | bits 1:0 word length (3 is 8 bits), bit 2 stop bits (0 is one), bit 7 divisor latch access | established |
| 4 | `+0xa0` | `REG_MCR` | bit 1 request to send, bit 5 automatic flow control; both software builds write `0x22` | established |
| 5 | `+0xa8` | `REG_LSR` | bit 0 data ready, bit 1 overrun, bit 2 parity error, bit 3 framing error, bit 4 break, bit 5 transmit holding empty, bit 6 transmit shift register empty | established |
| 6 | `+0xb0` | `REG_MSR` | bit 4 clear to send. The Linux v2.5.0 transmit path waits for bit 5 of LSR and bit 4 of MSR before each byte (`UART_PUTC_READY`, `PUTCHAR`). The IRIX `l1.o` census has no access at `+0xb0`, so IRIX does not read it | established for Linux; the IRIX absence is observed from the census, not a statement about IRIX behaviour elsewhere |
| 7 | `+0xb8` | `REG_SCR` | scratch. The SHub 1 PROM uses index 7 as the scratch word of its own UART driver (boot-sequence page); not read by the Bedrock code | inferred |

**Initialisation order** (Linux `uart_init`, matched step for step by IRIX `uart_init`, [README.md](README.md)):

1. Wait for LSR bit 6 (transmitter empty), at most 100000 ticks of the real-time counter.
2. LCR = `0x80` (open the divisor latch).
3. High divisor byte to index 1, low byte to index 0. The divisor is 12,000,000 divided by 16 times the baud rate
   (clock 12 MHz, established from the constant in both builds); at the usual 57,600 baud it is 13.
4. LCR = `0x03` (eight data bits, one stop bit, latch closed).
5. MCR = `0x22`.
6. IER = 0, then FCR = `0x01`, then FCR = `0x07` (Linux; IRIX writes 1 then 7 to the same register). Interrupts are enabled afterwards by `uart_intr_enable`
   (receive bit 0, transmit bit 1); IRIX writes `0x01` to the enable register at the end of `uart_init`.

A delay of 10 microsecond units (`UART_DELAY_SPAN`) separates the writes. The baud rate is 57,600 (`UART_BAUD_RATE`,
`get_L1_baud`). Established.

**Transmit pacing.** Linux counts characters it may send as a software FIFO budget of `0xf0` (240) after it sees
LSR bit 5 and CTS set (`UART_FIFO_DEPTH`), and re-checks the UART only when the budget is spent; a router UART is
checked before every byte. The budget is the kernel's assumption, not a measured depth, so the hardware FIFO depth stays
**unknown**. The IRIX census infers a 16-byte transmit FIFO from a count of 16 stored after LSR bit 5; the two
assumptions disagree and neither is a measurement.

**Console lock.** The Bedrock UART is shared by all processors of a node. Linux v2.5.0 serialises it with a software lock:
level 16 is a bit in the memory-unit performance counter 0 register, itself guarded by a test-and-set read of the local
block's third scratch register (`lock_console`, `hub_lock_timeout` in `l1.c`, about 30 seconds before it steals the
lock). Established for the code; the lock is software convention over ordinary registers, not UART behaviour.

## Framing

Established at both ends of the link: Linux v2.5.0 `brl1_send` and `brl1_receive`, IRIX `brl1_send` (`l1.o` `0xf0c`) and
`crc16_calc` (`0xc4c`), the ARM and ColdFire L1 writers and the SN1 and SN2 PROM writers (sysco
`node-link-sn1-vs-sn2.md`, which compares them byte by byte).

| Element | Value |
|---|---|
| Frame delimiter | `0x7e` before and after. Several flags in a row are allowed; a flag after a complete frame can also open the next |
| Escape | `0x7d`; the escaped byte is xored with `0x20`. Only `0x7e` and `0x7d` are escaped on the node link, in the body and in the check bytes |
| Check | 16-bit reflected CRC, polynomial `0x8408`, initial `0xffff`, table-driven (`crc = (crc >> 8) ^ table[(crc ^ byte) & 0xff]`, first entries `0x0000, 0x1189, 0x2312, 0x329b`), complemented, sent low byte first. The receiver runs the same update over header byte, body and check bytes and expects the residue `0xf0b8` |
| Covered bytes | the type and subchannel byte and the body, before escaping |
| Address and control prefix | none: the byte after the opening flag is the header byte |
| Payload limit | the Linux sender clamps the body to 127 bytes; its buffer is 264 bytes, enough for two flags, an escaped check and an escaped body. The ColdFire and ARM L1 senders count the header byte inside 127 or 128, so a body of 127 is the safe limit; see sysco for the exact edge |

**Receive state machine** (Linux `brl1_receive`):

| State | On flag | On escape | On another byte |
|---|---|---|---|
| idle (after reset or an error) | go to flag | stay | stay |
| flag | stay (repeated flags are fine) | error: protocol, go to idle | a valid header goes to header; an invalid one is a protocol error, go to idle |
| header | (transient: picks the subchannel queue; for a non-console frame it reserves one length byte and keeps the header byte as the first body byte; if the queue has less than two bytes of room it waits) | | go to body |
| body | end of frame: a body of fewer than two bytes is discarded as a protocol error; check the CRC against the residue and discard on a mismatch; otherwise drop the two CRC bytes, store the length, commit the frame, notify the owner, go to flag | go to escape | store the byte |
| escape | error: protocol, go to flag | error: protocol, go to idle | xor with `0x20` and store, go to body |

Error codes returned by `brl1_receive`: valid 0, queue full -1, bad CRC -2, protocol -3, no message -4, link error -5
(UART parity or framing error in LSR), busy -6. Queue full stops reading the UART, which is the only backpressure
the link has. Established.

## The type and subchannel byte

The first byte inside the frame. Bits 7:5 are the packet type, bits 4:0 the subchannel (`BRL1_PKT_TYPE_MASK`,
`BRL1_SUBCH_MASK`). Established, Linux v2.5.0 `l1.h` and `l1.c`.

| Type value | Name | Direction in the code |
|---|---|---|
| `0x00` | request | node to L1 for message subchannels; L1 to node for the console subchannels (console input arrives with this type) |
| `0x20` | response | L1 to node, on the subchannel the request used |
| `0x40` | event | L1 to node for message subchannels; node to L1 for console output (`l1_serial_out` sends system console text as `0x40 | SC_CONS_SYSTEM`, byte `0x44`) |

Receive validity (`VALID_HDR`): on a console subchannel (0 to 4) the type must be request; on any other subchannel it
must be response or event. The SN2 L1 firmware compares byte 0 of what it receives from the node against `0x44`
(sysco `node-link-sn1-vs-sn2.md`, from two immediates, inferred), the same value.

| Subchannel | Use | Grade |
|---|---|---|
| 0 to 3 | console for processor 0 to 3 of the node (`SC_CONS_CPU0` to `3`) | established |
| 4 | system console (`SC_CONS_SYSTEM`, equal to `CPUS_PER_NODE`) | established |
| 5 to 15 | reserved; incoming packets are discarded | established |
| 16 | the first command subchannel (`BRL1_CMD_SUBCH`); `sc_open` hands out the first free one from 16 up, 17 to 30 are the rest | established |
| 31 | event subchannel (`BRL1_EVENT_SUBCH`) | established for the name; no code in v2.5.0 opens it. The SN2 kernel's event path uses a subchannel it opens through the PROM (below) |

Console data packets carry plain bytes with no message body; the header byte is stripped on receive and the bytes go to
the console queue. Message packets keep the header byte and a prepended length in the receive queue. The queues are 128
bytes (`BRL1_QSIZE`), 32 input queues (`BRL1_IQS`) and 4 output queues (`BRL1_OQS`) per link. Established.

## Message body

Request, response and event bodies carry big-endian integers and typed arguments. Established from Linux v2.5.0
`sc_construct_msg` and `sc_interpret_resp`; the same layout is read in the shipped SN1 and SN2 PROMs and L1s
(sysco `node-link-sn1-vs-sn2.md` items 3 and 4).

### Request

| Offset | Size | Field |
|---|---|---|
| 0 | 4 | target address word (below) with the task number in its low five bits |
| 4 | 2 | request code |
| 6 | 1 | argument count; written only when there is at least one argument |
| 7 | n | arguments |

When a request has no arguments Linux's builder returns after the request code and writes no count byte. The shipped
SN2 PROM's builder (sysco: `sysctl_cmd_construct_req`) and the L1 receivers read a count byte unconditionally
(sysco: the L1 returns -100 for a count of zero in one path). Whether a short body is accepted as "no arguments" is
**unknown**; see [../../questions/l1-l2-l3-host-protocol.md](../../questions/l1-l2-l3-host-protocol.md).

### Target address word

| Bits | Field | Values |
|---|---|---|
| 31:28 | controller type | 0 L1, 1 L2, 2 L3, 3 attached C-brick, 4 attached I/O brick |
| 27:18 | rack | `0x3ff` means the local brick |
| 17:12 | bay (slot) | `0x3f` means the local brick |
| 4:0 | task | 0 invalid, 1 iRouter, 2 system management port, 3 command interpreter (ASCII text commands), 4 environment monitor, 5 Bedrock (the node link), 6 general requests |

`L1_ADDR_LOCAL` is type 0 with both fields all ones, `0x0ffff000`; the local I/O brick is `0x4ffff000`. Both are the
targets the IRIX kernel and the SN1 and SN2 PROMs open. Established (Linux v2.5.0 `l1.h`; IRIX targets resolved in the
[README.md](README.md) request table). The L1 firmware's own task registry has more tasks than the header names
(sysco: tasks 14, 18, 20, 21, 23, 24 on the ARM L1); those are not in this table.

The SN2 PROM trace in the chips boot-sequence page shows one request with address word `0x5000_1006` (type 5, bay 1,
task 6) where every other request uses `0x0ffff006`. Type 5 is not in the Linux header. Role **unknown**.

### Argument encoding

| Type byte | Meaning |
|---|---|
| `0x00` | a 4-byte big-endian integer follows |
| `0x01` | a NUL-terminated ASCII string follows |
| `0x80` plus `n` | `n` raw bytes follow, `n` at most 127 |

### Response

| Offset | Size | Field |
|---|---|---|
| 0 | 4 | status, big-endian; 0 is success, negative is an error |
| 4 | 1 | field count |
| 5 | n | fields, in the same typed encoding |

There is no echoed address or request code. The sender recovers the matching request from the subchannel. Status
codes named in the Linux header: 0 OK, -1 iRouter error, -100 argument count mismatch, -101 bad request code, -104
requested data not available, -105 argument out of range, -107 requested data invalid. The shipped firmware adds
more (-102, -106 and -108 are read in sysco; their text is in the sysco request notes). Established for the named ones.

### Request codes

The IRIX request map and its conflict with the later header are already in [README.md](README.md#request-codes-sent-to-the-brick-controller-ip35-l1_commando). Linux v2.5.0 `l1.h` adds the names `L1_REQ_RRACK` 2, `L1_REQ_SER_NUM` 4, `L1_REQ_EEPROM` 6
(the same code the SN2 PROM uses for its DIMM and board reads), `L1_REQ_EEPROM_FMT` 7, `L1_REQ_EVENT_SUBCH` `0x1007`,
`L1_REQ_RESET` `0x2000`, `L1_REQ_PCI_UP` `0x2001`, `L1_REQ_PCI_DOWN` `0x2002`, `L1_REQ_PCI_RESET` `0x2003`. The
catalogue of codes the ARM and ColdFire firmware accept is in the sysco repository (`request-codes.tsv`,
`request-code-names.md`). The shipped IP35 kernel uses `0x2001` for system reset, so the v2.5.0 meaning and the
IRIX meaning disagree for that code; the README keeps the conflict open.

### Events

On SN2 the kernel parses a pushed event as: source address (4 bytes), event code (4 bytes), argument count 2, an integer
argument (the ESP code), then an ASCII argument (the text); class, severity and component are the bit fields of the
code. Established, `snsc_event.c` and `snsc.h` at Linux v5.3. The layout differs from a request body: the code is four
bytes where a request has two, so the count sits at offset 8, not 6. How the event relates to the request body on the
wire (the source address replacing the target, the code widened) is **unknown**: the SN2 kernel sees the bytes after the
PROM has handled them. The class values are power `0x1000`, fan `0x2000`, temperature `0x3000`, environment `0x4000`,
test fault `0x5000`, test warning `0x6000`, power-down notify `0x8000`; sysco
`sn2-controller-host-protocol.md` lists the severities.

### Longer messages

Messages that do not fit one frame use request codes `0x3001` (start), `0x3002` (next segment) and `0x3003`
(continuation). The ColdFire layout (segment count in byte 7 of the framed packet, data length in bytes 8 and 9, error
codes -1623 to -1626) is read in full in sysco `chunked-request-frames.md`; the ARM L1 uses the same codes with a layout
not read. Linux v2.5.0 `l1.c` has no chunking. Established for the ColdFire side only.

## The SN2 host path

The kernel's side is a PROM call layer, one SAL function with eight operations for message subchannels
(`SN_SAL_IROUTER_OP`, open, close, send, receive, interrupt status, interrupt on and off, init) and a set of console calls.
The calls, the 127-byte chunk, the interrupt masks and the device naming are written out in sysco
`software/firmware/l1/sn2-controller-host-protocol.md`, reviewed there against Linux v5.3. This page adds three
facts.

- The `send` and `receive` payload is a message body in the layout above (target word, request code, arguments),
  inferred: Linux calls it an "IRouter packet", the SN1 header names task 1 "iRouter", and the SN2 PROM's own request
  builder uses the same body. No v5.3 code builds one; user programs do. Grade inferred.
- The subchannel number the SAL returns from `open` is a SAL handle. That it equals the link subchannel in the header
  byte is not read. Unknown.
- Console characters on SN2 do not go through message bodies for the kernel; the PROM turns SAL console calls into the
  console subchannel packets above (inferred from the PROM's UART driver naming, sysco).

## What a model of the link needs

From the node side: a 16550-style register file at the window above, with LSR bits 0, 5 and 6, MSR bit 4 (Linux
only), divisor latch, FCR and an interrupt on receive data; the framing above; a responder for the requests the
firmware sends at start-up. The first ten requests the SN2 PROM sends before memory initialisation, with their
expected replies, are tabulated in [software/firmware/snprom/boot-sequence.md](../../software/firmware/snprom/boot-sequence.md).
Whether a running PROM needs the model to answer within a deadline is established there for the transaction path.

## Cross-links to the controller side (sysco repository)

- `software/firmware/l1/sn2-prom-link-1.62.1.md`: the ARM L1's accepted requests and the node link.
- `software/firmware/l1/node-link-sn1-vs-sn2.md`: the byte-for-byte comparison of the two links.
- `software/firmware/l1/sn2-controller-host-protocol.md`: the kernel's SAL calls and event parser.
- `software/firmware/l1/chunked-request-frames.md` and `packet-chunks-and-l2-attach.md`: the chunk codes.
- `software/firmware/l1/quad-uart-and-serial-links.md`: the L1's own UART channels.
- `formats/l1_link_framing/`: the framing constants as a machine-readable format.

## Open

Listed in [../../questions/l1-l2-l3-host-protocol.md](../../questions/l1-l2-l3-host-protocol.md): the SHub 2 UART location, the
no-argument request, the event frame, the subchannel mapping and the hardware FIFO depth.
