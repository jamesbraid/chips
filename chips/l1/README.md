# L1 and ELSC system controllers (host-visible side)

Mode: **no-spec** (see [docs/specs.md](../../docs/specs.md): no specification is held). The L1 (Origin 3000-class bricks, IP35
build) and the ELSC (Origin 2000-class modules, IP27 build) are microcontrollers that sit beside the node controller. They
are not memory-mapped devices of their own; the host sees them through three paths, all read here:

1. a 16550-style UART in a node-local window, used by the IP35 kernel to exchange framed packets with the brick's L1;
2. the same kind of UART on the router chip, reached by vector packets (the console path of a router brick);
3. the IP27 board's I2C master, over which the ELSC takes command packets.

Every fact is read from IRIX 6.5.30 objects: `IP35/usr/cpu/sysgen/IP35boot/l1.o` and `l1_command.o` (relocatable, cited by
offset), and `IP27/usr/cpu/sysgen/IP27boot/elsc.o` (same). The public Linux header `asm-ia64/sn/ksys/l1.h` (the pinned
`linux-2.4.37` submodule) was read afterwards for names and conflicts only.

Census: [census/](census/census.md) (`census.tsv`, `census-sites.tsv`, `fields.tsv`, `context.tsv` for the UART window;
`router-uart-sites.tsv` for the router path; `command-sites.tsv`, `command-values.tsv` for the request codes and
`task-sites.tsv` for the task byte), configs
[`l1.json`](../../tools/configs/l1.json), [`l1-commands.json`](../../tools/configs/l1-commands.json),
[`l1-tasks.json`](../../tools/configs/l1-tasks.json), header [`include/l1.h`](../../include/l1.h).

## What this census covers, and what it does not

- The node-local UART rows come from the window scan: 98 access sites in `l1.o`, plus 20 in the local block window
  (`+0x20`, `+0x30100`, `+0x604200`, `+0x800090`, `+0x800098`; `get_myid` reads `+0x20`). The scan needed one extension, the config key `or_is_add`: the
  controller's registers are reached as a window constant plus a register offset or-ed in, and the stock scan did not follow
  an `ori` on a window pointer. The key is off by default and set only for this chip.
- The router UART path and the request codes are call-argument censuses (see [../router/README.md](../router/README.md)).
- The L1 packet payloads (what each request returns) are not decoded here: only the codes the host sends.
- The L2 and the "L3" are named only by address-type constants in the public header; no held routine addresses them.
- Reset values: unknown for every register (no code reads one before writing it).

## Node-local UART (IP35, `l1.o`)

The base is the 64-bit literal `0x9000000030000000` plus the node number shifted left 33 (the halfword at +0 of the port
record, `dsll32` by 1). The scan lists the offsets from that base. Every access is a 64-bit load or store of the low byte
(`ld`/`sd` with `andi 0xff` after a read), at an 8-byte stride; the bytes behave like a 16550 register file indexed 0 to 5
(inferred from the tests below; the 16550 names are the public part's, a hypothesis for this chip).

| offset | 16550 role (inferred) | access | what the code does | grade |
|---|---|---|---|---|
| `+0x80` | data, divisor latch low | rw | `uart_putc` (`0x24`, 40 bytes) stores one byte from the port record's output buffer; `uart_getc` (`0x4c`, 92 bytes) returns the low byte; `uart_init` writes the divisor low byte here while `+0x98` bit 7 is set. | E |
| `+0x88` | interrupt enable, divisor latch high | rw | `uart_init` writes the divisor high byte, later the constant 1; `uart_intr_enable` (`0x374`) ors in its second argument; `uart_intr_disable` (`0x4d4`) ands with its second argument. Both clear bit 7 of `+0x98` first. | E |
| `+0x90` | FIFO control (write), interrupt identity (read) | rw | `uart_init` writes 1 then 7; `brl1_intr_poll` and `brl1_intrd` read it and test mask 0x6, then bit 2 (calls `brl1_receive`) and bit 1 (calls `brl1_send_cont`). | E for the access, I for the 16550 encoding |
| `+0x98` | line control | rw | `uart_init` writes 0x80, later 3. | E |
| `+0xa0` | modem control | w | `uart_init` writes 0x22 once. | E |
| `+0xa8` | line status | r | `uart_getc` masks 0xd and 0x1 and 0xc; `brl1_send_chars` and `brl1_send_console_packet` test bit 5; `uart_init` tests bit 6 before reprogramming, with a timeout. | E |
| `+0x800090` (local block) | interrupt clear | w | `brl1_intr_poll` (`0x1de4`) writes 4 | E for the access, I for the role |
| `+0x800098` (local block) | interrupt pending | r | `brl1_intr_poll` tests bit 4 (mask 0x10) before servicing; `brl1_intrd` unblocks interrupt bit 4 on exit. | E for the access, I for the role |

- Other offsets the same routines touch are Bedrock registers, not controller registers: the real-time counter `+0x30100`
  and the clock period `+0x604200` (bits 13:4) are read by `uart_init`, `rtr_uart_putc` and `rtr_uart_init` to build a timeout. They are described in [../bedrock/README.md](../bedrock/README.md).
- `per_hub_init` (see [../bedrock/README.md](../bedrock/README.md)) stores 15 at `0x9000000030000000` plus `8 * slice + 192`;
  that block sits above the UART registers and is not touched by `l1.o`.

## Baud rate and programming sequence (established)

- `get_L1_baud` (`l1.o` `0x0`, 8 bytes) returns the constant 57600 (`dli 0xe100`). `uart_init` (`0xa8`, 716 bytes, read in
  full) takes the baud as its second argument and divides the constant 12,000,000 (`0xb71b00`) by the baud shifted left 4,
  which is the 16550 divisor formula for a 12 MHz clock (inferred as the clock, from the constant).
- `uart_init` order: poll line-status bit 6 (transmitter empty, by the 16550 reading) until it is set or a deadline of 100000
  past the converted real-time counter passes; write `+0x98` = 0x80; write `+0x88` = divisor bits 15:8; write `+0x80` = divisor bits 7:0; write `+0x98` = 3;
  write `+0xa0` = 0x22; write `+0x88` = 1; write `+0x90` = 1, then 7. Ten units of `uart_delay` (a call to `us_delay`)
  separate each write.
- `uart_getc` return values: -3 when none of line-status bits 3, 2 and 0 is set; the received byte when bit 0 is set; -2 when
  bit 0 is clear and bit 2 or 3 is set.

## Router-side UART (IP35, `rtr_uart_*` in `l1.o`)

A router brick has no node-local window to the L1, so `rtr_uart_putc` (`0x634`), `rtr_uart_getc` (`0x784`) and
`rtr_uart_init` (`0x818`) use `vector_read_node` and `vector_write_node` with the register numbers below. The numbers are
the router's second JBUS bank (the public router header names `RR_JBUS1(_D)` at `0x240 + 8 * D`) and follow the same
16550 indexing. The register numbers and access are established from the call arguments; the roles in the table's last column are
inferred from that indexing and from `uart_init`, which the routine mirrors. `rtr_uart_init` (`0x818`, read at its call sites) follows the
order of `uart_init` with one difference: the interrupt-enable index receives 0 where the node-local routine writes 1.

| router register | index | access | use |
|---|---:|---|---|
| `0x240` | 0 | rw | data / divisor low |
| `0x248` | 1 | w | divisor high, then 0 |
| `0x250` | 2 | w | 1, then 7 (FIFO control by the 16550 reading) |
| `0x258` | 3 | w | 0x80, then 3 (line control) |
| `0x260` | 4 | w | 0x22 |
| `0x268` | 5 | r | line status; `rtr_uart_putc` tests bit 5, `rtr_uart_init` bit 6 |

## Packet framing (established, `brl1_send` `0xf0c` and `crc16_calc` `0xc4c`, read in full)

- A frame starts and ends with the byte 0x7e (126). Inside the frame a byte equal to 0x7e or 0x7d (125) is sent as 0x7d
  followed by the byte xor 0x20. The first byte after the opening flag is the caller's type byte (a3 of `brl1_send`); up to
  127 payload bytes follow (`brl1_send` returns the count it took, at most 127).
- The check is a 16-bit CRC: `crc16_calc` (a0 the running value, a1 the next byte) returns
  `table[(a0 ^ a1) & 0xff] ^ (a0 >> 8)` masked to 16 bits. The table is the first 256 halfwords of the object's `.data`;
  all 256 entries equal the standard reflected table for the polynomial `0x8408` (compared entry by entry, the first
  entries being 0x0000, 0x1189, 0x2312, 0x329b). The initial value is 0xffff, the type byte and the payload bytes feed it
  in order, and the complement is sent low byte first, with the same escaping. This is the CRC-16 of the HDLC family.
- `brl1_send_chars` (`0xce8`) drains the staged frame. When the doubleword at record +8 equals 15 it calls `uart_putc`
  directly; otherwise it calls the routine whose address is the doubleword at record +24 (`brl1_init` stores it; that it is
  `rtr_uart_putc` is inferred from the `.srdata` relocations, which hold `uart_getc`, `uart_putc`, `rtr_uart_getc` and a
  fourth routine pointer). On the direct path, when the byte at record +55 is zero it reads line-status bit 5 and stores 16
  there if the bit is set; each byte sent decrements the byte (inferred: bit 5 means a 16-byte transmit FIFO is empty).


`brl1_connect_intr` (`0x2070`) records the CPU in the halfword at +52 of the port record, calls `intr_connect_level`
with level 4 and the interrupt routine, prints a diagnostic on failure and in either case calls `uart_intr_enable` with 1.
`brl1_intrd` ends by calling `intr_unblock_bit` with that CPU and 4. Level 4 and bit 4 of `+0x800098` agree; that they are
the same line is inferred.

## Request codes sent to the brick controller (IP35, `l1_command.o`)

Every request is built by `sc_construct_msg` and sent through `sc_command_kern`. The census reads the request code
(sixth argument) and task (fifth argument) at each of 29 call sites; the target address at each `sc_open` is
`0x0ffff000` in 21 calls and `0x4ffff000` in two (the I/O brick path), both resolved. The public header encodes the
address as type, rack, bay and task fields with type 0 for an L1 and 4 for an attached I/O brick: `0x4ffff000` has type 4,
and `0x0ffff000` has type 0 with both rack and bay fields set to all ones, which the header calls "local" (inferred).
All sites use task 6 except `sc_command_interp`, which uses task 3; the header names task 3 the command interpreter and
task 6 general requests (agreement).

| request | caller (`l1_command.o`) | header name | grade |
|---|---|---|---|
| `0x0` | `sc_command_interp` | `L1_REQ_EXEC_CMD` (interpret an ASCII command) | E for the code, header names the role |
| `0x1` | `elsc_debug_get` | `L1_REQ_RDBG` (read debug switches) | E / agreement |
| `0x3` | `_elsc_rack_bay_type_get`, `elsc_cbrick_type_get`, `iobrick_rack_bay_type_get`, `peer_iobrick_type_get` | `L1_REQ_RRBT` | E / agreement |
| `0x5` | `sc_version`, `iobrick_sc_version` | `L1_REQ_FW_REV` | E / agreement |
| `0x8` | `iobrick_get_sys_snum` | `L1_REQ_SYS_SERIAL` | E / agreement |
| `0x9` | `elsc_partition_get`, `peer_iobrick_partition_get` | `L1_REQ_PARTITION_GET` | E / agreement |
| `0xa` | `sc_portspeed_get`, `peer_iobrick_portspeed_get` | `L1_REQ_PORTSPEED` | E / agreement |
| `0xc` | `iobrick_attached_bricks` | none | E; role from the routine name (I) |
| `0xe` | `elsc_slab_get` | none | E; role from the routine name (I) |
| `0x1002` | `elsc_cons_subch` | `L1_REQ_CONS_SUBCH` | E / agreement |
| `0x1003` | `elsc_cons_node` | `L1_REQ_CONS_NODE` | E / agreement |
| `0x1004`, `0x1005` | `elsc_display_line` (line number plus 4100) | `L1_REQ_DISP1`, `L1_REQ_DISP2` | E / agreement |
| `0x1006` | `elsc_partition_set`, `peer_iobrick_partition_set` | `L1_REQ_PARTITION_SET` | E / agreement |
| `0x1009` | `elsc_led_set` | none (the header has `0x1007` for the event subchannel) | E; role I |
| `0x100a` | `elsc_evt_unreg` | none | E; role from the name (I) |
| `0x100c` | `sc_set_system_state` | none | E; role from the name (I) |
| `0x2001` | `elsc_system_reset` | header: `0x2001` is `L1_REQ_PCI_UP`, `0x2000` is `L1_REQ_RESET` | E that this routine sends `0x2001`; role I from the routine name; the header's meaning is for another firmware generation (I), so the conflict is not settled here, see below |
| `0x2005` | `elsc_pwr_off` | none | E; role from the name (I) |
| `0x2006` | `elsc_pwr_cycle` | none | E; role from the name (I) |
| `0x2007`, `0x2008` | `elsc_ody_expander_get`, `elsc_ody_expander_set` | none | E; role from the names (I) |

Conflict: the shipped IP35 code uses `0x2001` for a system reset; the public header, which comes from the later
Altix-class tree, gives `0x2001` to PCI power-up and `0x2000` to reset. The request numbering changed between the two
firmware generations (inferred), so the header cannot serve as the request map for IP35 bricks. Not in the header and
not in the census: the PCI power requests of the IP35 I/O brick (`iobrick_pci_pwr`, `iobrick_pci_slot_pwr`,
`iobrick_pci_bus_pwr`, `iobrick_pci_slot_rst`, `iobrick_pci_bus_rst` and the `peer_` forms): their request codes
come from a table the pass cannot follow and are an open question.

## IP27 ELSC: command packets over the I2C master (`elsc.o`)

- `elsc_command` (`elsc.o` `0x464`) builds a packet in a local buffer: a length byte n (the length of the command string),
  the n command bytes, and a final byte equal to the negated sum of the length byte and the command bytes. It sends the n+2
  bytes with `i2c_master_xmit_recv`, passing the node number (the halfword at record +0) and the constant 8 as the next
  argument (inferred: the controller's bus address; the I2C master routines are the Hub junk-bus ones described in
  [../hub/README.md](../hub/README.md)), and a receive buffer of 96 bytes. The response is accepted only when its length
  byte plus 2 equals the received count, the count is at least 2 and the length byte is below 96; the data bytes plus the
  length byte plus the trailing byte must sum to zero modulo 256.
- Return values: -100 when the transfer count differs from the request length (read from the first check after the call),
  -112 for a response length or format fault, -111 for a checksum fault, 0 otherwise. The shipped message table lists "Response
  packet checksum error" and "Response format error" for the last two; which index each code selects was not read.
- The `_elscuart_*` and `elscuart_*` routines do not touch a device: they keep a 128-byte ring in the record and call
  `elsc_command` and `elsc_parse` to carry console text (read: `_elscuart_flush` `0x1e34` formats the pending bytes with
  `sprintf` and sends them through `elsc_command`).

## Open

See [../../docs/open-questions.md](../../docs/open-questions.md): the PCI power request codes, the meaning of the local-block
interrupt registers, and the L2 addressing.
