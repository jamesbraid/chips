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
- Census rerun (2026-11-10): `ecpplp.o` is now seeded (its routines load the window pointer from their own record, `ld` at
  record +24, like the attach routines), so the parallel-port DMA registers `0x80` to `0x98` and the parallel-port data
  control and extended control bytes (`0x20152`, `0x2015a`) are census rows and generated defines; the other IOC3 rows
  gain their `ecpplp.o` sites. Still not census-visible, and carried by `include/ioc3_extra.h`: one-wire `0x30`, where
  `nic_access_mcr32` (`nic.o`) receives the register address as an argument, so no window pointer reaches its accesses and
  seeding it with `0x30` would assume the answer (the routine is shared with the Hub and Bridge drivers); and keyboard and
  mouse `0xa0` to `0xac`, where `pckm_pollcmd` (`ioc3_pckm.o`) stores through a per-port pointer chosen at run time.
- Reset values are unknown for every register: no routine reads one before writing it.

## Unresolved window-pointer sites (triaged)

The scan lists each call that passes the window pointer in an argument register when the callee is not seeded
(`unresolved.tsv`, summed into [census.md](census/census.md)). The report's "124 distinct sites" counts rows, one per
argument register that still holds the pointer. The calls are 98: 43 in IP27, 12 in IP30 and 43 in IP35. Each callee
below was read in the IP27 build (the kernel `unix`, or the `nic.o` object for the two `nic_` routines), and in the IP30
build where the same routine exists. The IP35 builds have no kernel in the tree, so a routine named only there rests on
the IP27 body and is inferred.

| callee | calls (IP27 / IP30 / IP35) | what the body does with the pointer | grade |
|---|---|---|---|
| `flushbus` | 4 / 3 / 4 | IP27: `sync` and return; the argument is never read. IP30: two dummy loads, at `0xffffffffaff50000` (the HEART register at offset 0x50000) and `0xffffffffb8000000` (HEART widget 8, offset 0), then `sync`. Neither is an IOC3 access. | established (IP27, IP30); IP35 inferred |
| `spl7` | 10 / 0 / 10 | Reads CP0 Status, ands it with `0x100a5`, returns the old Status in v0. The `mtc0` in the return's delay slot writes the masked value. The argument is never read. | established (IP27); IP35 inferred |
| `us_delay` | 3 / 3 / 3 | Takes a microsecond count in a0. IP27: scales it by 1.25 and busy-waits on a counter doubleword read through a literal-pool pointer. IP30: a calibrated loop (the count times 904 is stepped down by a factor word loaded from the low kernel address `0xffffffffffffc4b8` after each ten-step inner loop), with no counter read. The scan's pointer is in a2, which neither build takes as an argument (the IP30 call sets a0 to 1 in its delay slot). The window is not read. | established (IP27, IP30); IP35 inferred |
| `qprintf` | 1 / 1 / 1 | Saves its argument registers to its frame and calls through a function pointer (`jalr`) with a pointer to them. It does not dereference an argument. | established (IP27); IP30, IP35 inferred |
| `hub_check_pci_equiv` | 2 / 0 / 2 | Takes two addresses. It returns 0 unless `hub_check_window_equiv` accepts them (that routine compares bits 31:24 of both, or accepts when `hub_check_is_widget0` holds for both; the latter was not read) and their low 24 bits are equal; then it passes bits 39:32 of each to `check_nasid_equiv` and returns its answer. It only compares the two values, and its own memory accesses are frame slots, so it never dereferences the window. The IP30 kernel has no such routine. | established (IP27); IP35 inferred |
| `hwgraph_path_add` | 1 / 1 / 1 | Hardware-graph path work through the hwgraph routines. The fact sheet lists its own memory accesses as kernel data words, frame slots and one store to its third argument; the window is not read. | inferred (body not read in full) |
| `sio_unlock_port` | 1 / 0 / 1 | Loads the lock record that the port record's field at `+32` points to, tests bit 1 of the flag byte at record `+28`, clears that bit and calls `mutex_spinunlock` with the saved level from `+24`; when the bit is clear it clears bit 2 and calls `mutex_unlock` on the record `+8`. The window is not read. The IP30 kernel's copy is the same code; the IP32 `serialio.o` copy (84 bytes) reaches a 32-bit lock record at `+16` of the port record, clears the same two flag bits at record `+16` and calls `splx` or `mutex_unlock`, with no `mutex_spinunlock`. | established (IP27, IP30, IP32); IP35 same object bytes as IP27, inferred |
| `nic_ioc3_vertex_info` | 1 / 1 / 1 | Takes the vertex in the first argument and two window pointers: the second is window `0x30` (one-wire control) and the third window `0x34` (GPIO control set). When the third is nonzero it stores `0x200000` through it, a write to the GPIO control-set register that sets bit 21; it then calls `nic_vertex_info_set` with the vertex as the third argument. The second pointer is passed on unchanged to `nic_vertex_info_set`, which was not read. The same bit is set by `nic_get_eaddr` (below), and the public Linux driver writes its one-wire enable bit to the same register before using the one-wire port, so the bit is inferred to be the one-wire enable. | established (IP27, store and arguments); IP30 same code at its address, read; bit meaning inferred |
| `nic_get_eaddr` | 1 / 1 / 1 | Takes the one-wire pointer (window `0x30`) in the first argument, the GPIO control-set pointer (window `0x34`) in the second and an output buffer in the third. When the second is nonzero it stores `0x200000` through it (the same bit as `nic_ioc3_vertex_info`), then calls `nic_eaddr` with the one-wire pointer, up to twice while it returns nonzero, and prints a message on a final failure. The one-wire access lies below `nic_eaddr`, which was not read, so the link to the one-wire register is inferred. | established (IP27 store and call sequence; IP30 same code, read); one-wire link inferred |
| indirect | 19 / 2 / 19 | A call through a function pointer loaded from a driver table: IP27 `ioc3_read` loads `80($2)` into `$6` and calls `jalr $6`, after a compare with the constant `0x53435241`. The target is set at run time and no body is read here. | unknown |

The 40 indirect calls sit in the serial driver (`ioc3_serial_intr` 19, `ioc3_read` 6, and one or two each in `ioc3_open`,
`ioc3_enable_hfc`, `ioc3_serial_kill`, `ioc3_unmap`, `set_DTRRTS` and `hardware_init`, two each) and in the interrupt dispatcher
(`ioc3_intrd`, 3). Their targets are unknown. A route is to trace each table's store at attach time.

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
  against (the string is not extracted). `ioc3_intb_needed` (`0x13e4`) returns 0 when `mask & 0xfa` is zero and 1 otherwise (and 1 when no mask exists). Which board each
  mask belongs to is unknown.

## Register inventory

Offsets are from base-address window 0 unless a row says `cfg`. Every access in the census is a 32-bit word (`lw`, `sw`)
except the super-I/O byte registers (`lbu`, `sb`). Names are the public Linux names, for comparison only. **E**
established (the routine read in full, or the code constant is itself the fact), **I** inferred, **U** unknown. The grade
is of the role, with the evidence in the row.

### Graded register table

| offset | register | width | access | who touches it, what the code does | grade |
|---|---|---:|---|---|---|
| cfg `0x4` | command | 4 | rw | `ioc3_attach` reads it and writes it back ORed with `0x8146` | established |
| cfg `0x8` | revision | 4 | r | `if_efattach` keeps the low byte | established |
| cfg `0xc` | latency timer word | 4 | w | `ioc3_attach` stores the whole word: `0xff00` on IP27 and IP35, `0x2800` on IP30 | established |
| cfg `0x40`, `0x44` | error address, low and high | 4 | rw, r | `ioc3_error_handler` reads both, tests bit 0 of `0x40` (valid) and selects among 13 cases by bits 4:1 through a jump table, then stores the constant 1 to `0x40`; the cases are not read | inferred |
| `0x1c` | interrupt status | 4 | rw | `ioc3_attach` writes all ones; `ioc3_pending_intrs` reads it; `ioc3_serial_intr` reads it and writes handled bits back | established |
| `0x20` | interrupt enable set | 4 | w | `ioc3_write_ireg` (below) | established |
| `0x24` | interrupt enable clear | 4 | w | `ioc3_write_ireg` (below) | established |
| `0x28` | control | 4 | rw | `ioc3_attach` writes `0x7ae5e`; `hardware_init` polls bit 22 and bits 21:19 | inferred |
| `0x2c` | external interrupt output | 4 | w | `eiattach` writes 0 | inferred |
| `0x30` | one-wire control | 4 | rw | `nic_access_mcr32` (below) | established |
| `0x34` | GPIO control set | 4 | w | `ioc3_attach` writes `0xc0`; `ef_phyunreset` writes `0x20`; `eiattach` writes `0x10000`; `nic_ioc3_vertex_info` and `nic_get_eaddr` store `0x200000` through the pointer they are handed (the window `0x34` address, from the call sites in `ioc3_attach` and `ef_ioc3eaddr`) | inferred |
| `0x38` | GPIO control clear | 4 | w | `eiattach` writes `0x2` | inferred |
| `0x3c` | GPIO data | 4 | | no routine touches it. Settling test: the GPIO data register definition and any user of it in the public Linux driver for this chip (not checked out in this repository, see docs/sources/INDEX.md); absent a user, the end state is unknown with no software dependency in anything held | unknown |
| `0x40 + 4n` | GPIO pin n | 4 | w, rw | `ef_phyunreset` drives pin 5; `ioc3_set_proto` writes 0 or 1 to a pin number kept in the port's record | inferred |
| `0x80` to `0x98` | parallel-port DMA: buffer address high and low, count and flags, control (`0x8c`), the same three for context B | 4 | rw | `plp_dma`, `plp_dma_reset`, `plp_stop_dma`, `plpintr` (`ecpplp.o`), read in full; roles in [docs/coverage-ioc3.md](../../docs/coverage-ioc3.md) | established for `0x80` to `0x88` and `0x90` to `0x98`; inferred for the `0x8c` bits |
| `0x9c` | keyboard and mouse control | 4 | rw | `pckm_attach` stores `0xc00000`; `pckm_sendok` polls bits 0 and 1; `pckm_restart` sets bit 18 or 19 | established |
| `0xa0`, `0xa4` | keyboard, mouse receive | 4 | r | `pckm_pollcmd` reads one by port and tests bits 31:29 | established |
| `0xa8`, `0xac` | keyboard, mouse transmit | 4 | w | `pckm_pollcmd` writes the command byte to one by port | established |
| `0xb0`, `0xb4` | serial ring base, high, low | 4 | w | `hardware_init` | established |
| `0xb8` to `0xcc` | port A control, TX producer, TX consumer, RX producer, RX consumer, RX timer | 4 | rw | `sio_ioc3.o` (below); port B repeats 0x1c higher | established |
| `0xd0` | port A shadow | 4 | rw | `set_DTRRTS`, `ioc3_query_DCD`, `ioc3_query_CTS` | inferred |
| `0xf0` to `0x150` | Ethernet (25 registers) | 4 | rw | `if_ef.o`: graded one by one in "Ethernet" | 19 established, 5 inferred, 1 unknown |
| `0x20151`, `0x20152` | parallel-port status and control | 1 | r, rw | `ecpplp.o` | inferred |
| `0x2015a` | parallel-port extended control (PC ECP layout) | 1 | rw | `plpattach` reads it, tests bits 0 and 1, then stores `0x34`; `plp_dma` sets bit 3 and clears bit 2 | inferred |
| `0x20178` to `0x2017d` | UART A registers 0 to 5 | 1 | rw | `sio_ioc3.o` (below); UART B at `0x20170` | established |
| `0x2017f` | UART A register 7 | 1 | w | `set_baud_ti` stores a computed value | inferred |

**64 register kinds** (the parallel-port DMA words count as one family, the GPIO pins as one family): **45 established, 15
inferred, 4 unknown** as graded by the code alone; the coverage pass ([docs/coverage-ioc3.md](../../docs/coverage-ioc3.md)) moves the parallel-port DMA family and `0x2015a` out of unknown. The unknowns left are `0x3c` and `0x124`.

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
- **Mode select**: `ioc3_set_proto` (returns 0 or 1) writes 0 or 1 to `0x40 + 4 * pin`, the pin number being the byte at +0x20 of the port's configuration record (`ioc3_set_proto` is at `0x2f54` in the IP35 6.5.30
  `sio_ioc3.o`; the record pointer is at port +0x70). The records are the two 0x24-byte elements at the start of the object's `.data`
  and the pin byte is **7** for element 0 and **6** for element 1 (established as data; that element 0 is port A is inferred from order). Inferred: transceiver select.
- **UART registers**: the code uses the 16550 register index as the byte offset from the UART base, so register 3 (line
  control, DLAB in bit 7) is at `0x2017b`, 0 and 1 (divisor low and high when DLAB is set) at `0x20178` and `0x20179`, 2 at
  `0x2017a`, 4 (modem control) at `0x2017c` and 5 (line status) at `0x2017d`. `set_baud_ti` (`0x6cc`, returns 0 or 1) also stores a value it
  searches from 6 to 63 for the closest baud rate to UART register 7 (UART offset +0x7); inferred: a clock prescaler.

### Serial port count and names by board (Origin 2000, Onyx2)

Which boards carry serial ports, and what the guest calls them. The driver half is read from the IP27 `sio_ioc3.o` and
`serialio.o` objects; the board half comes from published SGI documents and published `hinv` captures, which were read afterwards
and agree.

- **Port names come from a controller number** (established: `ioc3_serial_attach` `0xa58` in `sio_ioc3.o`, `sio_make_hwgraph_nodes` `0x2500`
  in `serialio.o`). Each IOC3 gives its two UARTs the hardware-graph edges `tty/1` and `tty/2`. When the IOC3 is the console
  device (`ioc3_is_console` true) the attach calls `device_controller_num_set` with 1 for port A and 2 for port B, and
  `sio_make_hwgraph_nodes` then adds, under the `ttys` directory, one edge per port variant named `tty` + variant suffix + controller number
  (the object carries the suffixes `d`, `m`, `f`, `4d` and `4f`). So the console IOC3's ports are `ttyd1` and `ttyd2`
  (established that the numbers are 1 and 2 and that the edge pattern is `tty%s%d`; that the plain-`d` node is the one `/dev/ttyd1`
  names is inferred from the Origin 200 and Origin 2000 hardware documents using `ttyd1` and `ttyd2` for the first two ports). The attach
  sets no number on an IOC3 that is not the console device. The numbers for those ports come from elsewhere (see Open).
  Controller numbers outside 1 to 1000 get no nodes.
- **Origin 2000 BaseIO (IO6, server)**: two ports, both on the board's single IOC3 (established, published: the installation instructions
  for the Origin 2000 and Onyx2 deskside and rackmount systems, 108-0155-003, sections "Origin2000 BaseIO Board" and "BaseIO Board
  (Server Version)": two 460-kilobaud serial ports with dual independent UARTs, panel labels `tty_1` (marked Console) and `tty_2`; the
  Origin and Onyx2 theory of operations, 007-3439-002, "BaseIO Board": same count; the Hardware Quick-reference Booklet,
  HMQ-380-C, lists one external serial console port on the deskside rear panel and the alternate console port in addition). A published `hinv`
  from a one-module Origin 2000 with a server BaseIO (part 030-1124-002, named PCA IO6 Server in the illustrated parts catalog
  HMM-408-B) lists exactly `tty1` and `tty2` for that board. **`ttyd3` and `ttyd4` do not exist on a stock Origin 2000 server.**
- **Onyx2 BaseIO-G (IO6G) with MIO**: four ports on the panel, labelled `tty_1` to `tty_4` (established, published: 108-0155-003
  "BaseIO Board (Graphics Version)"). The extra two are on the Media I/O (MIO) daughterboard plugged into the IO6G's PCI
  bus (established, published: 007-3439-002, "MediaIO (MIO) Board" and its block diagram: its own IOC3 with a super-I/O part giving two
  serial ports, a parallel port, a keyboard and a mouse; an MIO is standard in every graphics configuration per the Onyx2
  technical report and optional in server ones). Two published Onyx2 deskside `hinv` captures with InfiniteReality graphics list `tty1` to
  `tty4` and nothing higher; one of them shows an MIO board (part 030-0880-003) beside the BaseIO (part 030-0734-002) and two PCI
  adapters with the IOC3 identifier on that board's bridge. **`ttyd3` and `ttyd4` exist on a stock Onyx2 deskside with graphics, served by
  a second IOC3 (the MIO's)**, not a separate UART part. Inferred: the second IOC3 is the one that is not the Ethernet-bearing
  device on the bridge; the captures list two IOC3 identifiers there but do not say which serves tty3 and tty4.
- **Conflict in the published count for the MIO.** The theory of operations and the technical report say the MIO adds two serial ports;
  the installation instructions' list says the MIO adds four. The panel drawing in the same installation instructions shows four ports in
  total on the graphics BaseIO, and the product guides list four asynchronous serial ports for an Onyx2 deskside, which agrees with two
  on the BaseIO plus two on the MIO and with the captures. Read as 2 + 2; the "four" is a total counted as an addition (inferred).
- **Optional ports on an Origin 2000 server.** The four-port Fast Ethernet adapter with asynchronous serial XIO board (MENET/MSER,
  installation instructions 108-0151-001) adds six asynchronous serial ports and four Ethernet ports from IOC3 chips behind a Bridge
  (established, published: its block diagram has three IOC3 chips each with a serial transceiver pair, S1 to S6, and a fourth
  without; the document says the IOC3 also sits on the BaseIO). A published `hinv` from an eight-processor Origin 2000 with a server
  BaseIO and two such boards lists 14 ports `tty1` to `tty14`: 2 from the BaseIO and 6 from each board (established count; which
  board holds which numbers is not shown). The same capture has a PCI adapter board with part number 030-1155-002 (PCA PCI IOC3 in
  HMM-408-B) on a crosstalk-to-PCI bridge, listed as Fast Ethernet and adding no serial port, so a PCI IOC3 card in that
  form is an Ethernet option, not a serial one (established for that card as captured). No published document or capture reviewed names a serial XIO or PCI card
  that is the usual source of `ttyd3` on a server; the MENET/MSER board is the only published option found.
- **Discreet note.** For `TabletDriver dlwacom, ttyd2` the second port of the BaseIO IOC3 exists on every Origin 2000 and Onyx2 deskside
  (inferred for the name; established for the port). `Security /dev/ttyd3`, on a graphics Onyx2, is the first MIO port; on a server it
  exists only with an option board or an MIO.

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
- Grades: established `0xf0`, `0xf8`, `0xfc`, `0x100`, `0x104`, `0x110`, `0x118`, `0x120`, `0x128`, `0x12c`, `0x130`, `0x134`, `0x138`, `0x13c`,
  `0x140`, `0x144`, `0x148`, `0x14c`, `0x150`. inferred `0xf4` (acknowledge by write: from the read-back pattern), `0x108`, `0x10c`
  (stored 0 at reset only), `0x114`, `0x11c`. unknown `0x124` (read only by the register dump routine).

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

On the Onyx 3000 and Origin 3000 I-brick the IOC3 serves serial, Ethernet and the real-time interrupt jacks, and the
keyboard and mouse are USB devices on a separate OHCI controller; the panel has no PS/2 connector
([docs/onyx3000-graphics-topology.md](../../docs/onyx3000-graphics-topology.md) question 3).

## Routines in the IP27 `ioc3.o` build

One entry per routine, read in full from the IRIX 6.5.30 IP27 `ioc3.o` (`IP27/usr/cpu/sysgen/IP27boot/ioc3.o`). Addresses are
offsets in the object's `.text`. The per-slot record is the 2888-byte block `ioc3_attach` allocates. Its fields, as the routines
below use them: +0, +4 and +8 hold the three vertex handles (the `ioc3` child, the host and the guest), +16 the
configuration-space pointer, +24 the window-0 pointer, +32 the interrupt handle, +40 and +42 two halfword processor numbers,
+48 the first of 32 connection entries of 88 bytes each (48 + 32 x 88 is +2864), +2864 the number of entries handed out, +2868 the bits claimed by
connections, +2872 a bitmap of released entries, +2876 a spinlock, +2880 the shadow of the enabled interrupt bits and +2884
and +2885 two flag bytes. Within a connection entry, +0 is the interrupt-bit mask, +8 the handler, +16 its argument, +24 the
owner vertex, +32 the record, +40 a flags word, +48 a semaphore and +80 an optional pre-handler. The string and function-pointer
slots of `.srdata` are `spl7`, `ioc3_poll`, the `.rodata` base, `pci_ioc3_enet_vmc`, `pci_ioc3_sio_vmc`, `ioc3_error_handler`,
`ioc3_intr`, `ioc3_intrd_setup` and `ioc3_intrd`, in that order.

- `ioc3_intr_cpu_get` (`IP27/usr/cpu/sysgen/IP27boot/ioc3.o` at 0x0, 8 bytes)
  returns the halfword at +40 of the record in `a0`, the processor number `ioc3_attach` stored there after it connected the
  interrupt. It touches no register. Established.
- `ioc3_mlreset` (`IP27/usr/cpu/sysgen/IP27boot/ioc3.o` at 0x8, 32 bytes)
  stores `a0` to the global `console_cfg` and `a1` to the global `console_mem` (the second store sits in the delay slot of
  the call), then calls `ioc3_sio_mlreset` with both arguments unchanged. It touches no register itself. Established.
  Inferred: the two arguments are the configuration and window pointers of the console chip, because `ioc3_attach` later
  compares its own pointers with these two globals.
- `ioc3_poll` (`IP27/usr/cpu/sysgen/IP27boot/ioc3.o` at 0x28, 140 bytes)
  takes the record in `a0`. It calls `ioc3_handle_intr` with the record and a1 0, takes the spinlock at +2876 with
  `mutex_spinlock_spl` and the `spl7` function, and tests bit 1 of the flag byte at +2884. With the bit set it releases the
  lock and re-arms itself with `prtimeout_nothrd` (the processor in the global `master_procid`, the routine `ioc3_poll`, the
  record, one tick). With the bit clear it releases the lock and clears bit 2 of the flag byte in the delay slot of the
  unlock. Established. This is the polling path of the interrupt bits that `ioc3_write_ireg` keeps out of the hardware
  enable register.
- `ioc3_write_ireg` (`IP27/usr/cpu/sysgen/IP27boot/ioc3.o` at 0xb4, 408 bytes)
  takes the record, a bit mask and an operation in `a0` to `a2`. Under the lock at +2876 it updates the shadow at +2880
  (operation 0 ORs the mask in, operation 1 removes it), then writes the enable-set register `0x20` and enable-clear
  register `0x24` through the window pointer at +24 as described in "Interrupt registers". Any other operation value leaves
  the shadow alone and only releases the lock. The shadow and flag rules are the ones listed under that heading; this entry
  adds that in operation 0 only bits 31:23 of the mask reach `0x20` while bit 0 of the flag byte is set, and that the store
  of `0x7fffff` to `0x24` happens each time bit 0 of the flag byte goes from clear to set. Established.
- `ioc3_pending_intrs` (`IP27/usr/cpu/sysgen/IP27boot/ioc3.o` at 0x24c, 92 bytes)
  takes the lock at +2876, loads the word at +28 of the window pointer (register `0x1c`, interrupt status) and the shadow at
  +2880, releases the lock and returns the two ANDed. Established.
- `ioc3_init` (`IP27/usr/cpu/sysgen/IP27boot/ioc3.o` at 0x2a8, 88 bytes)
  registers the PCI driver with `pciio_driver_register` for vendor 4265 and device 3, with the name string `ioc3_` at
  `.rodata` +0x30, and makes three `nic_vmc_add` calls: the string `030-1155-` with `pci_ioc3_enet_vmc`, then `030-1657-`
  and `030-1664-` each with `pci_ioc3_sio_vmc`. It touches no register. Established.
- `pci_ioc3_enet_vmc` (`IP27/usr/cpu/sysgen/IP27boot/ioc3.o` at 0x300, 28 bytes)
  calls `ioc3_subdev_enables` with the vertex in `a0` and the mask 9 (bits 0 and 3) and returns. Established. Bit 3 is the
  keyboard bit that `pckm_attach` tests; no routine of the build tests bit 0, which `ioc3_intb_needed` leaves out of its
  `0xfa` mask. Inferred: bit 0 is the Ethernet function, from this routine's name alone.
- `pci_ioc3_sio_vmc` (`IP27/usr/cpu/sysgen/IP27boot/ioc3.o` at 0x31c, 28 bytes)
  is the same body with the mask `0x30` (bits 4 and 5, the two serial ports that `ioc3_serial_attach` tests). Established.
- `ioc3_attach` (`IP27/usr/cpu/sysgen/IP27boot/ioc3.o` at 0x338, 1208 bytes)
  is read in full; it returns 0, or -1 after the two mapping failures below. It maps configuration space with
  `pciio_pio_addr` (space 7, length 72) and window 0 (space 8, length `0x20180`); a failed first map prints a message naming
  the configuration space with `cmn_err` level 1, and a failed second map frees the first piomap and prints the message for
  the memory space. It looks up the `.host` edge of its vertex (the vertex itself when there is none), then the `.guest`
  edge of that (the host when there is none), adds an `ioc3` child with `hwgraph_path_add` and an edge named `ioc3` to it
  from host and guest, allocates the 2888-byte record with `kmem_zalloc`, initialises the spinlock at +2876 with the name
  `is_ir_lock`, fills +0 to +24, attaches the record to the `ioc3` child with `hwgraph_fastinfo_set`, and registers
  `ioc3_error_handler` with `pciio_error_register` on host and guest. When `hub_check_pci_equiv` reports the configuration
  pointer equivalent to `console_cfg` and the window pointer equivalent to `console_mem`, the record becomes the console
  record (the global it stores to is the one `ioc3_is_console` and `ioc3_console_vhdl_get` read). The stores to the chip
  are, in order: configuration word `0x4` ORed with `0x8146`, window `0x28` set to `0x7ae5e`, configuration word `0xc` set
  to `0xff00`, window `0x34` set to `0xc0`, `ioc3_write_ireg` with all ones and operation 1, and window `0x1c` set to all
  ones. The path name from `vertex_to_name` then selects the subdevice mask: a path containing `Ibrick/xtalk/15/pci/4` sets
  the mask `0x91` with `ioc3_subdev_enables` and byte +2885 to 1; `baseio` and `menet` keep the default; any other path
  calls `nic_ioc3_vertex_info` with the window addresses `0x30` and `0x34`. If `ioc3_intb_needed` is false it clears +32,
  stores the processor number from the process page into +40 and returns 0. Otherwise it duplicates the guest's device
  descriptor (flag 4 added, software level 0, name `IOC3 UART`) and makes it the guest's default. The interrupt line is 2
  when host and guest are the same vertex and function bit 0 is enabled; otherwise it is 2 when the identity string from
  `nic_vertex_info_get` contains `030-1657-` or `030-1664-`, and 1 when the string is absent or holds neither. It then calls
  `pciio_intr_alloc`; a null result prints the `unable to allocate interrupt` message at level 0 and the routine goes on
  with the null handle. It connects `ioc3_intr` with the record as argument using `pciio_intr_connect`, stores the connected
  processor at +40 and the processor the descriptor requested (or the connected one, when none or an invalid one is
  requested) at +42, and prints the level 4 message with both numbers when they differ. It ends with `ioc3_serial_attach`
  and `pckm_attach` on the guest and sets `console_device_attached` to 1 when this record is the console record (otherwise
  it stores the old value back). Established. Inferred: lines 1 and 2 are the two interrupt pins of the slot, because the
  `030-1657-` and `030-1664-` boards are the ones given line 2.
- `ioc3_intr_connect` (`IP27/usr/cpu/sysgen/IP27boot/ioc3.o` at 0x7f0, 632 bytes)
  takes the lookup vertex, the bit mask, the handler, its argument, the owner vertex, the device vertex and a pre-handler in
  `a0` to `a6`. It finds the record through the `ioc3` child (a missing child prints the `ioc3_attach not yet called`
  message at level 1 and returns). It takes the lowest set bit of the released-entry bitmap at +2872 and clears it with a
  load-linked and store-conditional pair; with an empty bitmap it takes the next number from the counter at +2864 with the
  same pair. It fills the entry with the mask, handler, argument, owner, record and pre-handler, then ORs the mask into the
  claimed bits at +2868 and, if any bit was already claimed, prints `trying to share ioc3 intr bits` at level 6 and calls
  `panic` with `ioc3_intr_connect: no IOC3 interrupt source sharing allowed`. The software priority comes from the device's
  descriptor (`device_desc_intr_swlevel_get`), else from the global `default_intr_pri`. The thread name is `ioc3[%d]%s` with
  the entry number and the driver's name from `device_driver_getbydev`, or `ioc3[%d]` with the entry number alone when no
  driver is found. The routine ORs `0x300` into the thread block at entry +40 and calls `xthread_setup` with the name, the
  priority, that block, `ioc3_intrd_setup` and the entry. It does not set `v0`. Established.
- `ioc3_intr_disconnect` (`IP27/usr/cpu/sysgen/IP27boot/ioc3.o` at 0xa68, 356 bytes)
  takes the lookup vertex, a bit mask, the handler, its argument and the owner vertex in `a0` to `a4`. It finds the record
  as `ioc3_intr_connect` does (a missing child prints a level 1 message and returns), then walks the entries up to the count
  at +2864. For each whose handler, argument and owner equal the three given and whose mask overlaps, it clears the overlap
  from that entry's mask and from the claimed bits at +2868 with load-linked pairs. An entry whose mask is now zero gets
  owner -1, handler 0 and argument 0 and its bit is set in the released-entry bitmap at +2872. The walk does not stop at the
  first match. Established.
- `ioc3_intr` (`IP27/usr/cpu/sysgen/IP27boot/ioc3.o` at 0xbcc, 28 bytes)
  calls `ioc3_handle_intr` with its own first argument and `a1` 1. It is the handler `ioc3_attach` connects with
  `pciio_intr_connect`. Established.
- `ioc3_handle_intr` (`IP27/usr/cpu/sysgen/IP27boot/ioc3.o` at 0xbe8, 468 bytes)
  takes a record (or, for 0, the console record) in `a0` and a flag in `a1`. It reads the pending bits with
  `ioc3_pending_intrs`, returns when none are set, and with the flag 0 removes bits 28:27 (`0xe7ffffff`); with the flag 1
  and bit 0 of the flag byte at +2884 set it keeps only bits 31:23. For each entry up to the count at +2864 whose mask meets
  the pending bits it calls the handler with the argument and the shared bits, except for an entry with bit `0x1000` set in
  its flags word: that one first runs the pre-handler if there is one, and when there is none (or it returns nonzero) the
  routine disables the entry's mask with `ioc3_write_ireg` (operation 1) and wakes the entry's thread with `vsema` on its
  semaphore. Handled bits leave the pending set. When the loop ends the routine adds the number of entries run, less one, to
  the word at offset 208 of the block that the pointer at absolute address `0xffffffffffffc508` holds. Bits nobody handled
  print `unknown IOC3 interrupt 0x%x` at level 1, and the pending bits are read again until none remain. No routine of this
  object sets bit `0x1000`. Established.
- `ioc3_is_console` (`IP27/usr/cpu/sysgen/IP27boot/ioc3.o` at 0xdbc, 88 bytes)
  returns 0 when no console record exists. Otherwise it looks up the `ioc3` child of the vertex in `a0`, returns 0 when that
  fails, and returns whether its record is the console record. Established.
- `ioc3_is_io7` (`IP27/usr/cpu/sysgen/IP27boot/ioc3.o` at 0xe14, 64 bytes)
  looks up the `ioc3` child of the vertex in `a0` and returns byte +2885 of its record, or 0 when there is no child. Byte
  +2885 is set only by the path match in `ioc3_attach`. Established. Inferred: the `Ibrick` path means an I/O brick board,
  from the path text alone.
- `ioc3_error_handler` (`IP27/usr/cpu/sysgen/IP27boot/ioc3.o` at 0xe54, 756 bytes)
  takes the record in `a0`; the configuration pointer is at +16. It reads the word at configuration `0x4` and selects text
  by bit: bits 31 and 24 give `parity error`, bit 30 or bit 16 gives `SERR`, bit 27 `signalled target abort`, bit 28
  `received target abort` and bit 29 `issued master abort`. Each match overwrites the text, so the last one in that order is
  printed with `cmn_err` level 5 as `IOC3 %s`; the print is unconditional, so with none of those bits set it shows whatever
  the local buffer held. It then reads configuration word `0x40`; if bit 0 is clear it returns 0. Otherwise bits 4:1 index a
  13-entry table: 0 `serial port A transmiter`, 1 `serial port A receiver`, 2 `serial port B transmitter`, 3 `serial port B
  receiver`, 4 `parallel port`, 5 to 7 `unknown address unit`, 8 `enet tx descriptor read`, 9 `enet tx buf1 read`, 10 `enet
  tx buf2 read`, 11 `enet rx descriptor read` and 12 `enet rx buffer write`; larger values use the default. It prints `IOC3
  Error ID %s Error Addr 0x%x` at level 5 with the address made of the bits of word `0x40` above bit 5 and the word at
  `0x44` as the high half, writes 1 to word `0x40` and returns 0. Established. Inferred: the write of 1 clears the error
  latch, from the read-then-write pattern alone.
- `ioc3_intrd` (`IP27/usr/cpu/sysgen/IP27boot/ioc3.o` at 0x1148, 72 bytes)
  is the body of an entry's interrupt thread. Its argument is the entry. It loads the window pointer through the entry's
  record, reads register `0x1c`, ANDs it with the entry's mask, calls the entry's handler with the entry's argument and that
  value, then waits on the entry's semaphore with `ipsema`. Established.
- `ioc3_intrd_setup` (`IP27/usr/cpu/sysgen/IP27boot/ioc3.o` at 0x1190, 128 bytes)
  runs in a new thread with the entry in `a0`. It calls `setmustrun` with the halfword at +42 of the record (the requested
  processor), points the thread's function at `ioc3_intrd` with `xthread_set_func` (first argument the pointer at absolute
  address `0xffffffffffffc020`), copies the name that `fetch_kname` returns for the entry's handler to offset 832 of the
  block that pointer holds with `strncpy` (16 bytes), ORs `0x400` into the entry's flags word and calls `ipsema` on the
  entry's semaphore. Established.
- `ioc3_console_vhdl_get` (`IP27/usr/cpu/sysgen/IP27boot/ioc3.o` at 0x1210, 24 bytes)
  returns the word at +0 of the console record (its `ioc3` child vertex), or -1 when there is no console record.
  Established.
- `ioc3_subdev_ptr` (`IP27/usr/cpu/sysgen/IP27boot/ioc3.o` at 0x1228, 188 bytes)
  takes a vertex and a create flag. It replaces the vertex with its `.host` edge if there is one, then looks up the label
  `_subdevs` on it and returns the stored pointer. With the label missing and the flag set it allocates 8 bytes with
  `kmem_zalloc`, stores 255, adds the label with `hwgraph_info_add_LBL`, reads it back and frees its own block with
  `kmem_free` if the label now holds a different one. With the flag clear it returns 0 for a missing label. Established.
- `ioc3_subdev_enabled` (`IP27/usr/cpu/sysgen/IP27boot/ioc3.o` at 0x12e4, 72 bytes)
  returns the mask word from `ioc3_subdev_ptr` (create 0), or 255 when there is none, ANDed with 1 shifted left by the bit
  number in `a1`. Established.
- `ioc3_subdev_enables` (`IP27/usr/cpu/sysgen/IP27boot/ioc3.o` at 0x132c, 44 bytes)
  stores the doubleword in `a1` into the mask `ioc3_subdev_ptr` returns with create 1. It does nothing when no pointer comes
  back. Established.
- `ioc3_subdev_enable` (`IP27/usr/cpu/sysgen/IP27boot/ioc3.o` at 0x1358, 68 bytes)
  sets bit `a1` of that mask with a load-linked and store-conditional doubleword pair; the bit is formed with a 32-bit
  `sllv`, so numbers from 32 up wrap. Established.
- `ioc3_subdev_disable` (`IP27/usr/cpu/sysgen/IP27boot/ioc3.o` at 0x139c, 72 bytes)
  clears bit `a1` of the same mask with the same pair and the same 32-bit shift. Established.
- `ioc3_intb_needed` (`IP27/usr/cpu/sysgen/IP27boot/ioc3.o` at 0x13e4, 60 bytes)
  returns 1 when `ioc3_subdev_ptr` (create 0) finds no mask, and otherwise 1 when the mask ANDed with `0xfa` is nonzero and
  0 when it is zero. Only bit 0 and bit 2 of the mask lie outside `0xfa`, and `ioc3_attach` skips the interrupt allocation
  when this returns 0. Established. Inferred: the `intb` in its symbol means the second interrupt pin, so a board whose
  enabled functions are only 0 and 2 would not need it.
- `ioc3_mem_ptr` (`IP27/usr/cpu/sysgen/IP27boot/ioc3.o` at 0x1420, 8 bytes)
  returns the doubleword at +24 of the record in `a0`, the window-0 pointer. Established.
- `ioc3_get_mem` (`IP27/usr/cpu/sysgen/IP27boot/ioc3.o` at 0x1428, 32 bytes)
  calls `hwgraph_fastinfo_get` on the vertex in `a0` and returns the doubleword at +24 of the record it returns.
  Established.

## Against the public drivers (reported after the reading above)

Sources: Linux `arch/mips/include/asm/sn/ioc3.h`, `drivers/mfd/ioc3.c`, `drivers/net/ethernet/sgi/ioc3-eth.c` and
`drivers/tty/serial/8250/8250_ioc3.c` (current pin), and OpenBSD `sys/arch/sgi/pci/ioc.c`, `iocreg.h`, `sys/arch/sgi/dev/if_iec.c`
and `ioc(4)` (pins in [docs/sources/INDEX.md](../../docs/sources/INDEX.md)). The linux-2.4.37 and linux-2.5.40 trees carry
older `ioc3-eth.c` copies that were not compared line by line.

| point | IRIX reading | public drivers | result |
|---|---|---|---|
| offsets `0x1c` to `0x150` | as in the table | Linux header and OpenBSD `iocreg.h` agree on every offset the census reached, including port A at `0xb8` to `0xd0` and port B at `0xd4` to `0xec` | agree |
| command write | ORs `0x8146` | Linux names `0x8000` (drop on parity error), `0x100` (SERR), `0x40` (parity response) plus standard bits | agree |
| control `0x28` | writes `0x7ae5e` at attach | neither driver writes it | IRIX-only; the Linux field layout (bit 0 reset, 7:1 and 14:8 DMA poll bases) is not checked against the value. Grade: established that `ioc3_attach` stores `0x7ae5e` to `0x28` (re-read in the IP35 `ioc3.o`, sha256 `5e69438504a0ae29b9076f965733428688412611a0ec55cfc086d4036d689035`, store at 0x544; the same value is read in the other two builds); inferred for every field reading of the value, which rests on the Linux header alone and is unchecked in this pass because the Linux tree is not checked out; settled by reading the Linux `ioc3.h` control-register field list against the value, bit by bit |
| UART byte lane | register 3 at UART+3, registers 0 and 1 at +0 and +1 | Linux uses `offset ^ 3`, so line control at +0; OpenBSD gives the UART bases `0x20178` and `0x20170` and applies the same `^ 3` | **agree after the exclusive-or**: the IRIX order is the natural register order seen through a swapped path (see [docs/coverage-ioc3.md](../../docs/coverage-ioc3.md)); which routine sets the swap is unknown |
| PHY reset | pin 5 low 10 microseconds, high, 500 microseconds | both name pin 5 PHY reset (mask `0x20`) | agree |
| MII | busy `0x800`, read trigger `0x400`, phy at bit 5 | same in both | agree |
| Ethernet setup | `0xfc` threshold, `0x108` = `0x1000000`, `0x114` = 0, bit 0 of `0x12c` set | Linux: threshold 15, barrier `0x100 << 16` (equal to `0x1000000`), `ertr` 0, ring size bit 0 | agree on `0x108`, `0x114`; the threshold is a tunable here |
| `emcr` start | `0xac` (field 8:3 = `0x15`, padding enable) plus duplex and promiscuous | Linux: `(RX_OFFSET / 2) << 3` plus DMA and MAC enables and padding | the receive-offset field differs by design; `ef_ioc3init` sets neither DMA nor MAC enable (a later routine does; not read) |
| inter-frame gaps `0x118` | from a table whose values are 21/21/21 full duplex and 21/11/17 half (shipped tunable file) | Linux 21/21/21 full duplex, 17/11/21 half | agree field for field |
| one-wire `0x30` | `(pulse << 10) | (sample << 2)`, done bit 1, data bit 0; 6/110, 80/30, 520/65 | OpenBSD `iocow_pulse` identical, 6/110 for a 1 and 80/30 for a 0 | agree |
| parallel port | reads `0x20151`, read-modify-writes `0x20152` | Linux header names `0x20151` control and `0x20152` status | **agree after the exclusive-or with 3**: IRIX status `0x20151` is Linux `0x20152`, IRIX control `0x20152` is Linux `0x20151` |
| enable polling | low bits polled while bit 27 or 28 is enabled | no equivalent | IRIX-only; reason unknown |
| external interrupt | input pin 1, edge, output low | Linux has `GPCR_EDGE` and `INT_OUT_MODE`; `eiattach` sets edge bit 16, clears direction bit 1 | agree |

## Reset expectations

No routine reads a reset value. The attach writes every register it relies on before use (command, latency, control, GPIO
control, enables and status); the rest are unknown.

## Open

Items settled by the coverage pass are in [docs/coverage-ioc3.md](../../docs/coverage-ioc3.md): the byte lane, the inter-frame
gap values, the parallel-port DMA registers `0x80` to `0x98` and the error address decode.

- **Why interrupts are polled while the top interrupt bits are enabled** (`ioc3_write_ireg`): the mechanism is read in full; the
  reason is in no string or comment the binary carries. Route: a hardware note.
- **`0x8c` bit 29** (parallel-port DMA control). The device swap bit question is answered in docs/coverage-ioc3.md: IRIX clears it for the IOC3 window; the remaining question there is why the byte lanes mirror Linux's.
- **Keyboard and mouse bit meanings** in `0x9c` and `0xa0` to `0xac`: from the routines' masks only.
- **Per-slot subdevice masks**: which board string selects `0x91`.
- **How a non-console IOC3's serial ports get their numbers.** `ioc3_serial_attach` sets numbers only on the console IOC3, and the
  published captures show contiguous numbering across boards (`tty1` to `tty14` on one system). The assigning routine is in the user-space
  device configuration tool (`ioconfig` reports finding a serial controller and keeps persistent numbers), not read. Route: read its serial
  branch, or a published `ls -l /dev/ttyd*` and `/etc/ioconfig.conf` from a system with an MIO or MENET/MSER board. Also unsettled: which of the two IOC3s on
  an IO6G bridge serves `tty3` and `tty4` (route: a `hinv -v` with hardware-graph paths from an Onyx2 with an MIO).
