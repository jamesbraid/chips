# IOC3

Mode: **no-spec** (see [docs/specs.md](../../docs/specs.md): no specification is held). Builds read: IP27 (the primary build: the offsets cited below are its), IP30 and IP35. PCI I/O controller of the Origin
200/2000 BaseIO, Octane (IP30) and Origin 300-class (IP35) base I/O boards: two serial ports with ring-buffer DMA, a 10/100 Ethernet MAC with an MII, a keyboard and mouse port, a parallel port, a
one-wire port, general purpose I/O pins and an external interrupt input and output. The three carry byte-different copies of
the same driver objects; the IP27 offsets are cited (from the `IP27boot` objects) and the other two agree unless a difference is stated.

Every fact below was read from the IRIX 6.5.30 driver objects `ioc3.o` (attach, interrupt enable, subdevice mask),
`sio_ioc3.o` (serial, a member of `sduart.a`), `if_ef.o` (Ethernet), `ioc3_pckm.o` (keyboard and mouse), `ioc3ei.o`
(external interrupt), `nic.o` (one-wire) and `ecpplp.o` (parallel port). They are relocatable objects, so a routine is
cited as `name` at its offset in the object. The public Linux and OpenBSD drivers were read afterwards, to report
agreement and conflict, never to supply a fact; the register names used here are the public Linux names for the offsets
the code reached (see "Against the public drivers").

Census: [census/](census/census.md) (`census.tsv`, `fields.tsv`, `context.tsv`, `census-sites.tsv`), config
[`tools/configs/ioc3.json`](../../tools/configs/ioc3.json), header [`include/ioc3.h`](../../include/ioc3.h). IOC4, the
later chip of the same family, is in [../ioc4/README.md](../ioc4/README.md).

## What this census covers, and what it does not

- The drivers reach the chip through pointers kept in per-device records, not through accessor routines. The scan seeds
  each record as a base (the record's own fields are not registers; `record_skip_above` in the config drops them) and
  follows the pointer fields the attach routines store: `ioc3_attach` (returns 0 or -1) keeps the window pointer at record +24 and the
  configuration-space pointer at +16, and the serial, Ethernet and keyboard objects keep their own copies. The census
  reaches **56 register rows from 637 access sites** (the three builds summed). Configuration-space rows appear at
  `0x200000` plus the configuration offset.
- Read by hand below because the scan does not follow them: the keyboard and mouse data registers (`pckm_pollcmd` picks
  one of four offsets by port and the scan loses the join), the parallel-port registers (`ecpplp.o` adds the `0x20000`
  window offset in a register-to-register add), the one-wire register (its pointer arrives as an argument), and the
  second serial port, which repeats the first at fixed distances (see "Serial ports"). Per-port families are recorded at
  port A.
- Reset values are unknown for every register: no routine reads one before writing it.

## What identifies the chip (established)

- `ioc3_init` (`ioc3.o` `0x2a8`, read in full) registers the PCI driver for vendor 4265 (`0x10a9`), device 3, and makes
  three `nic_vmc_add` calls (one-wire identity tables). No driver probes an identification word: they are attached by
  that registration.
- `ioc3_attach` (`0x338`, read in full; it returns 0, or -1 when either mapping fails) maps configuration space (the PIO call's space argument is 7, length 72 bytes) and
  base-address window 0 (space argument 8, offset 0, length `0x20180`). The first covers the PCI header and the words at
  `0x40` and `0x44`; the second covers the registers below and the super-I/O byte registers at `0x20000` and up. Which
  spaces the numbers 7 and 8 name is inferred from what the code stores through each pointer (the standard PCI command
  and latency words through the first).
- Revision: `if_efattach` (`if_ef.o` `0x2fc`) reads the configuration word at `0x8` and keeps its low byte. No routine
  compares it with a constant. `if_efattach` returns 0, -1 or 12 in all three builds; the 12 is loaded just before a return
  on the path that follows its `ef_detach` call.
- The driver keeps a per-slot software mask of enabled subdevices, default `0xff` (`ioc3_subdev_enabled`, `ioc3.o`
  `0x12e4`). Bit 3 is tested by `pckm_attach`, bits 4 and 5 by `ioc3_serial_attach` (ports A and B) and bit 6 by
  `plpattach` (`ecpplp.o`). `ioc3_attach` (returns 0 or -1) sets the mask to `0x91` when the PCI path name contains a string it compares
  against (the string is not extracted). `ioc3_intb_needed` (`0x13e4`) is true when `mask & 0xfa` is zero. Which board each
  mask belongs to is unknown.

## Register inventory

Offsets are from base-address window 0 unless a row says `cfg`. Every access in the census is a 32-bit word (`lw`, `sw`)
except the super-I/O byte registers (`lbu`, `sb`). Names are the public Linux names, for comparison only. **E**
established (the routine read in full, or the code constant is itself the fact), **I** inferred, **U** unknown. The grade
is of the role, with the evidence in the row.

### Graded register table

| offset | register | width | access | who touches it, what the code does | grade |
|---|---|---:|---|---|---|
| cfg `0x4` | command | 4 | rw | `ioc3_attach` reads it and writes it back ORed with `0x8146` | E |
| cfg `0x8` | revision | 4 | r | `if_efattach` keeps the low byte | E |
| cfg `0xc` | latency timer word | 4 | w | `ioc3_attach` stores the whole word: `0xff00` on IP27 and IP35, `0x2800` on IP30 | E |
| cfg `0x40`, `0x44` | error address, low and high | 4 | rw, r | `ioc3_error_handler` reads both, tests bit 0 of `0x40` (valid) and selects among 13 cases by bits 4:1 through a jump table, then stores the constant 1 to `0x40`; the cases are not read | I |
| `0x1c` | interrupt status | 4 | rw | `ioc3_attach` writes all ones; `ioc3_pending_intrs` reads it; `ioc3_serial_intr` reads it and writes handled bits back | E |
| `0x20` | interrupt enable set | 4 | w | `ioc3_write_ireg` (below) | E |
| `0x24` | interrupt enable clear | 4 | w | `ioc3_write_ireg` (below) | E |
| `0x28` | control | 4 | rw | `ioc3_attach` writes `0x7ae5e`; `hardware_init` polls bit 22 and bits 21:19 | I |
| `0x2c` | external interrupt output | 4 | w | `eiattach` writes 0 | I |
| `0x30` | one-wire control | 4 | rw | `nic_access_mcr32` (below) | E |
| `0x34` | GPIO control set | 4 | w | `ioc3_attach` writes `0xc0`; `ef_phyunreset` writes `0x20`; `eiattach` writes `0x10000` | I |
| `0x38` | GPIO control clear | 4 | w | `eiattach` writes `0x2` | I |
| `0x3c` | GPIO data | 4 | | no routine touches it | U |
| `0x40 + 4n` | GPIO pin n | 4 | w, rw | `ef_phyunreset` drives pin 5; `ioc3_set_proto` writes 0 or 1 to a pin number kept in the port's record | I |
| `0x84` to `0x98` | parallel-port DMA family | 4 | rw | `ecpplp.o` touches `0x84`, `0x88`, `0x8c`, `0x90`, `0x94`, `0x98`; `plp_dma`, `plpintr` not read | U |
| `0x9c` | keyboard and mouse control | 4 | rw | `pckm_attach` stores `0xc00000`; `pckm_sendok` polls bits 0 and 1; `pckm_restart` sets bit 18 or 19 | E |
| `0xa0`, `0xa4` | keyboard, mouse receive | 4 | r | `pckm_pollcmd` reads one by port and tests bits 31:29 | E |
| `0xa8`, `0xac` | keyboard, mouse transmit | 4 | w | `pckm_pollcmd` writes the command byte to one by port | E |
| `0xb0`, `0xb4` | serial ring base, high, low | 4 | w | `hardware_init` | E |
| `0xb8` to `0xcc` | port A control, TX producer, TX consumer, RX producer, RX consumer, RX timer | 4 | rw | `sio_ioc3.o` (below); port B repeats 0x1c higher | E |
| `0xd0` | port A shadow | 4 | rw | `set_DTRRTS`, `ioc3_query_DCD`, `ioc3_query_CTS` | I |
| `0xf0` to `0x150` | Ethernet (25 registers) | 4 | rw | `if_ef.o`: graded one by one in "Ethernet" | 19 E, 5 I, 1 U |
| `0x20151`, `0x20152` | parallel-port status and control | 1 | r, rw | `ecpplp.o` | I |
| `0x2015a` | parallel-port configuration | 1 | rw | `plpattach` reads it, tests bits 0 and 1, then stores `0x34` | U |
| `0x20178` to `0x2017d` | UART A registers 0 to 5 | 1 | rw | `sio_ioc3.o` (below); UART B at `0x20170` | E |
| `0x2017f` | UART A register 7 | 1 | w | `set_baud_ti` stores a computed value | I |

**64 register kinds** (the parallel-port DMA words count as one family, the GPIO pins as one family): **45 established, 15
inferred, 4 unknown.** The unknowns are `0x3c`, the parallel-port DMA family, `0x124` and `0x2015a`.

### Interrupt registers (`0x1c`, `0x20`, `0x24`): established

- `ioc3_write_ireg` (`0xb4`, read in full) is the only writer of `0x20` and `0x24`. The record keeps a lock, a 32-bit shadow
  of the enabled bits (record +2880) and a flag byte (+2884). `ioc3_write_ireg(record, bits, op)` does the following.
  - `op` 0 (enable): the shadow becomes `shadow | bits`. If flag bit 0 is clear and `shadow & 0x18000000` is now non-zero,
    it sets flag bit 0 and stores `0x7fffff` to `0x24`. With flag bit 0 set, only `bits & 0xff800000` is stored to `0x20`;
    and if `shadow & 0x7fffff` is non-zero it sets flag bit 1 and, when flag bit 2 is clear, sets it and arms `ioc3_poll`
    with `prtimeout_nothrd` (one tick, master processor). With flag bit 0 clear, `bits` is stored to `0x20` unchanged.
  - `op` 1 (disable): the shadow loses `bits`. With flag bit 0 set, flag bit 1 is cleared when `shadow & 0x7fffff` is zero,
    and flag bits 0 and 1 are both cleared when `shadow & 0x18000000` is zero, in which case the whole shadow is stored to
    `0x20`. `bits` is stored to `0x24` last, unconditionally.
  - So while either of the two top interrupt bits (27 and 28, the mask `0x18000000` that `eiattach` connects) is enabled,
    the driver keeps bits 22:0 out of the hardware enable register and services them by polling every tick. Why:
    **unknown**; no routine or string says. Open question.
- `ioc3_pending_intrs` (`0x24c`) returns register `0x1c` ANDed with the shadow. `ioc3_poll` (`0x28`) calls `ioc3_handle_intr`
  and re-arms itself while flag bit 1 is set.
- `ioc3_attach` (returns 0 or -1) writes the control and GPIO registers, clears the enables with `ioc3_write_ireg(record, 0xffffffff, 1)`,
  then writes all ones to `0x1c`. That a written 1 clears a status bit is inferred from the acknowledge pattern in
  `ioc3_serial_intr` (read `0x1c`, store the handled bits back).

### Control register `0x28`, GPIO (`0x34` to `0x54`)

- `ioc3_attach` (returns 0 or -1) writes `0x7ae5e` to `0x28` (`lui 7`, `ori 0xae5e`) in all three builds (established).
- `hardware_init` reads `0x28` in a loop and leaves it when bit 22 (`0x400000`) is set or when bits 21:19 hold a value of 4
  or more; it loops while they hold 0 to 3. Established. Inferred: a requester field and an idle bit, the loop waiting for
  the serial DMA engine to drop off the bus after the port reset described below.
- `ef_phyunreset` (`if_ef.o` `0xeb0`, read in full) writes 0 to pin 5 (`0x54`), writes `0x20` to `0x34`, waits 10
  microseconds, writes 1 to pin 5 and waits 500 microseconds (established). That this is a PHY reset line is inferred from
  the routine's name.
- `eiattach` (`ioc3ei.o` `0x4a8`, returns 0 or -1) writes 2 to `0x38`, `0x10000` to `0x34` and 0 to `0x2c`, then connects an interrupt handler
  with mask `0x18000000` (established). Inferred: an input on pin 1, edge sensitive, with the output held low.

### Serial ports (established: `hardware_init`, `set_baud_ti`, `ioc3_serial_attach`, `ioc3_enable_tx`, `ioc3_read`)

Each port record keeps pointers to the port's register block (record +64), its UART (+72), the chip window (+56) and the
super-I/O window (+80). `ioc3_serial_attach` (`0xa58`, read in full) allocates both port records together (336 bytes, 168
each) and builds port B's pointers from port A's: the register block moves from `0xb8` to `0xd4` (+0x1c) and the UART from
`0x20178` to `0x20170`. The tables are port A.

- **Block**, in order from `0xb8`: control, TX producer index, TX consumer index, RX producer index, RX consumer index, RX
  timer, shadow. The role of each is established by the sequences below.
- **Reset** (`hardware_init` `0x7b4`, read in full): store `0x80000000` to the control register; wait on `0x28` as above; store 0;
  read the TX consumer, mask `0xff8` and store it to the TX producer and to a record copy; read the RX producer, mask
  `0xff8` and store it to the RX consumer and a record copy. Then the UART: 0 to registers 3 and 1, `set_baud_ti`, 3 to
  register 3, 1 then 7 to register 2, 0 to register 4. Then 0 to the shadow and `0xa0` to the RX timer, and the record's
  control word `0x10180` to the control register. Before the first control write it waits for UART register 5 bit 5 to be set,
  3 microseconds a try (established).
- **Ring base** (`hardware_init`, only for port A's configuration record): `ring_dmatrans` returns the bus address of the 4 KB
  ring buffer. `hardware_init` stores the high word at window offset +0xb0 and the low word ORed with 1 at +0xb4. Inferred: bit 0 selects 4 KB rings (a
  4096 stride and a 16384-byte clear in `ioc3_serial_attach` agree).
- **Pause**: before it touches the indices, each of `ioc3_enable_tx`, `ioc3_read`, `ioc3_config`, `ioc3_break` and `set_DTRRTS`
  stores `0x20000000` (alone or with the record's control word) to the control register and polls bit 30 of it, up to 1,000,000
  tries with `us_delay`. `ioc3_read` also sets bit 27 and polls it clear before it reads the RX producer. Inferred: bit 29
  pauses DMA, bit 30 reports the pause took effect, bit 27 drains the receive packer.
- **TX and RX**: `ioc3_enable_tx` (returns 0 or -1) stores the producer index (mask `0xff8`) at block +0x4; the consumer is read from block +0x8.
  The RX producer is read from block +0xc. `ioc3_read` stores `consumer | 0x80000000` at block +0x10. `ioc3_rx_timeout` (returns 0 or 1) stores the smaller
  of the requested count and 4095 at block +0x14.
- **Shadow**: `ioc3_query_DCD` and `ioc3_query_CTS` read block +0x18 (the shadow); `set_DTRRTS` (returns 0 or -1) ORs bits into it and writes UART register 4. The
  bit positions are inferred from the routine names.
- **Mode select**: `ioc3_set_proto` (`0x2f00`, returns 0 or 1) writes 0 or 1 to `0x40 + 4 * pin`, the pin number being a byte of a static
  per-port table (not read). Inferred: transceiver select.
- **UART registers**: the code uses the 16550 register index as the byte offset from the UART base, so register 3 (line
  control, DLAB in bit 7) is at `0x2017b`, 0 and 1 (divisor low and high when DLAB is set) at `0x20178` and `0x20179`, 2 at
  `0x2017a`, 4 (modem control) at `0x2017c` and 5 (line status) at `0x2017d`. `set_baud_ti` (`0x6cc`, returns 0 or 1) also stores a value it
  searches from 6 to 63 for the closest baud rate to UART register 7 (UART offset +0x7); inferred: a clock prescaler.

### Ethernet (established: `ef_ioc3init`, `ef_ioc3reset`, `ef_phyget`, `ef_phyput`, `ssram_discovery`)

The driver holds the register block base `0xf0` (record +816) and the chip window (+920).

- **Reset** (`ef_ioc3reset` `0x1bec`, read in full): store `0x80000000` to `0xf0` and poll bit 21 until set (1,000,000 tries at one
  microsecond); then store 0 to `0xf0`, `0x130`, `0x10c`, `0x134` and `0x110`. Established.
- **Setup** (`ef_ioc3init` `0xba8`, read in full): `0x118` takes three table bytes at bit offsets 0, 8 and 16; `0x11c` takes a
  microsecond clock value; `0x108` takes `0x1000000`; `0xfc` takes the buffer count divided by a tunable, masked `0x1ff`; `0x114`
  takes 0; the station address goes to `0x13c` (four low bytes) and then `0x138` (two high bytes); the hash filter to `0x144` and
  then `0x140` (all ones for promiscuous or multicast-all); the RX ring bus address to `0x104` (low) and `0x100` (high); the TX
  ring address to `0x12c` (low, with bit 0 set) and `0x128` (high). The last two stores are `0xf0`, which takes `0xac` ORed with
  bit 0 from the record's full-duplex field and bit 1 from bit 8 of the caller's flags, and then, after `flushbus`, `0xf8`, which
  takes `0x7fe003f`. All established.
- **MII** (`ef_phyget` `0x16fc`, `ef_phyput` `0x1794`, read in full): wait while bit 11 of `0x148` is set. A read stores
  `(phy << 5) | register | 0x400` to `0x148`, waits for bit 11 clear and returns the low 16 bits of `0x14c`. A write stores the
  data to `0x150`, then `(phy << 5) | register` to `0x148`, and waits for bit 11 clear.
- **Run time** (offsets are from the register block, `0xf0`): `ef_intr` (`0x1e14`) reads block +0x4 and stores the same value back; `ef_fill` (`0x1964`) stores `index << 3` to block +0x20;
  `ef_transmit` (`0x2868`, returns 0, 7, 127 or 132) stores `index << 7` to block +0x44; `ef_reclaim` (`0x904`) reads block +0x40 and shifts it right 7; `ef_getcdc`
  (`0x1de8`) splits block +0x30 into its low and high 16 bits.
- **Buffer RAM** (`ssram_discovery` `0x790`): ORs `0x1200` into `0xf0`, writes the patterns `0x5555` and `0xaaaa` to two words
  of the buffer-RAM window (offset `0x40000`, mapped 128 KB), reads them back and records the result. Established for the
  accesses; the meaning of bits 12 and 9 is inferred.
- Grades: **E** `0xf0`, `0xf8`, `0xfc`, `0x100`, `0x104`, `0x110`, `0x118`, `0x120`, `0x128`, `0x12c`, `0x130`, `0x134`, `0x138`, `0x13c`,
  `0x140`, `0x144`, `0x148`, `0x14c`, `0x150`. **I** `0xf4` (acknowledge by write: from the read-back pattern), `0x108`, `0x10c`
  (stored 0 at reset only), `0x114`, `0x11c`. **U** `0x124` (read only by the register dump routine).

### One-wire port (`0x30`, established: `nic_access_mcr32`)

`nic_access_mcr32` (`nic.o` `0x1018`, read in full) stores `(a1 << 10) | (a2 << 2)` to `0x30`, polls it until bit 1 is set, waits
`a3` microseconds and returns bit 0. `nic_presence` (`0x9c`), `nic_write` (`0xc8`) and `nic_read` (`0x10c`) call through the
accessor pointer in their first argument, which is how `nic_access_mcr32` is reached (inferred). Arguments: presence
`(520, 65, 500)`; write a 1 `(6, 110, 0)`; write a 0 `(80, 30, 0)`; read `(6, 13, 100)`. Inferred: `a1` pulse length and `a2`
sample point in microseconds, bit 1 done, bit 0 the sampled line.

### One-wire bit and byte routines (IP30 `nic.o` build, established unless marked)

The IP30 `nic.o` lays these routines out differently from the IP27 and IP35 copies cited above; the addresses here are the IP30
build's.

- `nic_presence` (`IP30/usr/cpu/sysgen/IP30boot/nic.o` at `0x68`, read in full, established): loads the accessor pointer from the
  doubleword at `a0` and the cookie from the doubleword at `a0 + 8`, calls the accessor through a register with `a1` 520, `a2` 65 and
  `a3` 500, and returns the accessor's result. Its only control transfers are that call and the return.
- `nic_write` (`IP30/usr/cpu/sysgen/IP30boot/nic.o` at `0x94`, read in full, established): takes one bit in `a1`. A nonzero bit sets the
  accessor's `a1` to 6 and `a2` to 110; a zero bit sets them to 80 and 30. The `movn` in the call's delay slot takes the `v0` value 110
  into `a2` when the bit is set. It sets `a3` to 0, calls the accessor loaded from the doubleword at `a0`, with the cookie from `a0 + 8`,
  and returns the accessor's result.
- `nic_read` (`IP30/usr/cpu/sysgen/IP30boot/nic.o` at `0xd8`, read in full, established): calls the accessor loaded from the doubleword at
  `a0`, with the cookie from `a0 + 8`, `a1` 6, `a2` 13 and `a3` 100 (the delay slot sets `a3`), and returns the accessor's result.
- `nic_write_byte` (`IP30/usr/cpu/sysgen/IP30boot/nic.o` at `0x104`, read in full, established): writes the eight bits of `a1`, least
  significant first. Each pass calls `nic_write` (the call at `0x138` is relocated to `nic_write`) with `a0` unchanged and `a1` set to the
  byte ANDed with `1 << i`, which is nonzero exactly when bit `i` is set. A negative return from `nic_write` stops the loop and is returned
  as it is. After the eighth pass it returns 0.
- `nic_read_byte` (`IP30/usr/cpu/sysgen/IP30boot/nic.o` at `0x178`, read in full, established): reads eight bits, least significant first.
  Each pass calls `nic_read` (the call at `0x198` is relocated to `nic_read`) with `a0` unchanged, shifts the result left by the pass index
  and ORs it into the byte. A negative result from `nic_read` stops the loop and is returned as it is; otherwise it returns the byte after
  eight passes.
- `crc16` (`IP30/usr/cpu/sysgen/IP30boot/nic.o` at `0x0`, read in full, inferred): updates the halfword at `a1` in place from the byte
  in `a0`. It loads the halfword `h`, forms `x = (a0 ^ (h & 0xff)) & 0xff`, reads two words from one table at `.data` offset 256, indexed
  by the low nibble and the high nibble of `x`, and stores `h >> 8` at `a1`. When the two words differ it stores `(h >> 8) ^ 0xc001` at
  `a1` as well. The last store is `a3 ^ (x << 6) ^ (x << 7)`, issued in the delay slot of the return. The table contents are not read,
  so reading the step as a 16-bit CRC is inferred from the shifts and the polynomial constant.

### Keyboard and mouse (established: `pckm_attach`, `pckm_sendok`, `pckm_restart`, `pckm_pollcmd`)

`pckm_attach` (`ioc3_pckm.o` `0x5c`) stores `0xc00000` to `0x9c`. `pckm_sendok` (`0x1ba8`) reads `0x9c` up to 250 times at 50
microseconds and returns when bit 0 (port 0) or bit 1 (port 1) is clear. `pckm_restart` (`0x2320`) ORs bit 18 (port 0) or 19
(port 1) into `0x9c`, stores it back, reads it and stores it back again (inferred: the second pair clears sticky bits).
`pckm_pollcmd` (`0x1810`) writes the command byte to `0xa8` (port 0) or `0xac` (port 1), then reads `0xa0` or `0xa4` up to 250
times at 50 microseconds until any of bits 31:29 is set. Port 0 is the keyboard by the routine names; inferred.

## Against the public drivers (reported after the reading above)

Sources: Linux `arch/mips/include/asm/sn/ioc3.h`, `drivers/mfd/ioc3.c`, `drivers/net/ethernet/sgi/ioc3-eth.c` and
`drivers/tty/serial/8250/8250_ioc3.c` (current pin), and OpenBSD `sys/arch/sgi/pci/ioc.c`, `iocreg.h`, `sys/arch/sgi/dev/if_iec.c`
and `ioc(4)` (pins in [docs/sources/INDEX.md](../../docs/sources/INDEX.md)). The linux-2.4.37 and linux-2.5.40 trees carry
older `ioc3-eth.c` copies that were not compared line by line.

| point | IRIX reading | public drivers | result |
|---|---|---|---|
| offsets `0x1c` to `0x150` | as in the table | Linux header and OpenBSD `iocreg.h` agree on every offset the census reached, including port A at `0xb8` to `0xd0` and port B at `0xd4` to `0xec` | agree |
| command write | ORs `0x8146` | Linux names `0x8000` (drop on parity error), `0x100` (SERR), `0x40` (parity response) plus standard bits | agree |
| control `0x28` | writes `0x7ae5e` at attach | neither driver writes it | IRIX-only; the Linux field layout (bit 0 reset, 7:1 and 14:8 DMA poll bases) is not checked against the value |
| UART byte lane | register 3 at UART+3, registers 0 and 1 at +0 and +1 | Linux uses `offset ^ 3`, so line control at +0; OpenBSD gives the UART bases `0x20178` and `0x20170` | **differ** for byte accesses. Which lane the hardware presents is unknown; a host-bridge byte-swap setting is a hypothesis |
| PHY reset | pin 5 low 10 microseconds, high, 500 microseconds | both name pin 5 PHY reset (mask `0x20`) | agree |
| MII | busy `0x800`, read trigger `0x400`, phy at bit 5 | same in both | agree |
| Ethernet setup | `0xfc` threshold, `0x108` = `0x1000000`, `0x114` = 0, bit 0 of `0x12c` set | Linux: threshold 15, barrier `0x100 << 16` (equal to `0x1000000`), `ertr` 0, ring size bit 0 | agree on `0x108`, `0x114`; the threshold is a tunable here |
| `emcr` start | `0xac` (field 8:3 = `0x15`, padding enable) plus duplex and promiscuous | Linux: `(RX_OFFSET / 2) << 3` plus DMA and MAC enables and padding | the receive-offset field differs by design; `ef_ioc3init` sets neither DMA nor MAC enable (a later routine does; not read) |
| inter-frame gaps `0x118` | from a table | Linux 21/21/21 full duplex, 17/11/21 half | table values not extracted: unknown |
| one-wire `0x30` | `(pulse << 10) | (sample << 2)`, done bit 1, data bit 0; 6/110, 80/30, 520/65 | OpenBSD `iocow_pulse` identical, 6/110 for a 1 and 80/30 for a 0 | agree |
| parallel port | reads `0x20151`, read-modify-writes `0x20152` | Linux header names `0x20151` control and `0x20152` status | **differ** in order; a PC-style port has status then control |
| enable polling | low bits polled while bit 27 or 28 is enabled | no equivalent | IRIX-only; reason unknown |
| external interrupt | input pin 1, edge, output low | Linux has `GPCR_EDGE` and `INT_OUT_MODE`; `eiattach` sets edge bit 16, clears direction bit 1 | agree |

## Reset expectations

No routine reads a reset value. The attach writes every register it relies on before use (command, latency, control, GPIO
control, enables and status); the rest are unknown.

## Open

- **Why interrupts are polled while the top interrupt bits are enabled** (`ioc3_write_ireg`): the mechanism is read in full; the
  reason is in no string or comment the binary carries. Route: a hardware note.
- **Ethernet inter-frame gap table**: `ef_ioc3init` loads three words from tables in the object's data. Next: resolve the data
  section's relocations and read the words.
- **UART byte lane** and the **register 7 prescaler**: see the comparison.
- **Parallel port**: roles of `0x84` to `0x98` and bit meanings at `0x20151` to `0x2015a`; `plp_dma`, `plpintr` and `plp_reset` are not read.
- **Error address words** (cfg `0x40`, `0x44`): `ioc3_error_handler` is read only for its accesses and the shape above (valid-bit test, jump table on bits 4:1, constant 1 stored to `0x40`); the table targets are not read. The routine cannot be run through `scripts/facts.py` (it fails on a literal tuple); the objdump listing was used.
- **Keyboard and mouse bit meanings** in `0x9c` and `0xa0` to `0xac`: from the routines' masks only.
- **Per-slot subdevice masks**: which board string selects `0x91`.
