# IOC4

Mode: **no-spec** (see [docs/specs.md](../../docs/specs.md): no specification is held). PCI I/O controller of IP35-class
base I/O boards: four serial ports with ring-buffer DMA, an ATA controller, a keyboard and mouse port, general purpose
I/O pins and an external interrupt input and output. It has no Ethernet, parallel port or one-wire port; IOC3 is the
earlier chip of the family ([../ioc3/README.md](../ioc3/README.md)).

Every fact below was read from the IRIX 6.5.30 IP35 driver objects `ioc4.o` (attach, interrupt enable), `sio_ioc4.o`
(serial, a member of `sduart.a`), `ide.o` (the ATA driver, whose IOC4 path is read here and whose other controller paths
are not), `ioc4_pckm.o` (keyboard and mouse) and `ioc4_ei.o` (external interrupt). They are relocatable objects, so a
routine is cited as `name` at its offset in the object. No other build carries IOC4 code. The public Linux drivers were
read afterwards, to report agreement and conflict, never to supply a fact; the register names are the public Linux names for
the offsets the code reached.

Census: [census/](census/census.md) (`census.tsv`, `fields.tsv`, `context.tsv`, `census-sites.tsv`), config
[`tools/configs/ioc4.json`](../../tools/configs/ioc4.json), header [`include/ioc4.h`](../../include/ioc4.h).

## What this census covers, and what it does not

- The drivers keep the window pointer in a per-device record (`ioc4_attach` stores it at record +16); the scan seeds each record
  as a base and follows the pointer fields, as for IOC3. It reaches **31 register rows from 154 access sites**. Configuration
  space rows appear at `0x200000` plus the configuration offset.
- The ATA registers are not in the census: `ide.o` reaches them through accessor routines that take a base, an index and a
  value (`xide_getb`, `xide_putb` and the word forms), so the offsets are read by hand below from every call site that passes
  a constant index.
- Keyboard and mouse data registers are read by hand (the scan loses the join at the port choice, as in IOC3). Serial ports 1
  to 3 repeat port 0 at fixed distances read from `ioc4_serial_attach`.
- Reset values are unknown for every register.

## What identifies the chip (established)

- `ioc4_init` (`ioc4.o` `0x1dc`, read in full) registers the PCI driver for vendor 4265 (`0x10a9`), device 4106 (`0x100a`).
- `ioc4_attach` (`0x204`, read in full; it returns 0, or -1 when either mapping fails) maps configuration space (space argument 7, 84 bytes) and base-address window 0
  (space argument 8, 928 bytes, `0x3a0`). Which spaces 7 and 8 name is inferred from what is stored through each.
- The ATA driver reads the configuration halfword at offset 0 into one record field and at offset 2 into another, and
  `xide_chip_init` (`ide.o` `0x914`) compares the second with `0x10a9` and the first with `0x100a`. Because the mapping is
  big-endian, the halfword at `+0` is the high half of the little-endian identification word: the device id, with the
  vendor id at `+2`. Established.
- Revision: `ioc4_attach` (returns 0 or -1) reads the configuration byte at 8 (`pciio_config_get`) and compares it with 79 (below);
  `device_inventory_add` receives the same byte. Established.

## Register inventory

Offsets are from base-address window 0 unless a row says `cfg`. **E** established (the routine read in full, or the code
constant is itself the fact), **I** inferred, **U** unknown. Widths are 32-bit words except as stated.

### Graded register table

| offset | register | width | access | who touches it, what the code does | grade |
|---|---|---:|---|---|---|
| cfg `0x0` | device and vendor id | 2 | r | `xide_attach`, `xide_chip_init` compare the halves with `0x100a` and `0x10a9` | E |
| cfg `0x4` | command and status | 2, 4 | rw | `ioc4_attach` reads the word and writes it back ORed with `0x146` | E |
| cfg `0x8` | revision | 4, 1 | r | `ioc4_attach` compares the byte with 79 | E |
| `0x0` | PCI error address, low | 4 | rw | `ioc4_dma_error_intr` reads it: bit 0 valid, bit 1 chooses the word RX or TX in the message, bit 5 multiple errors, bits 31:6 address, bits 4:2 serial port number; `ioc4_error_handler` reads and writes it | E |
| `0x4` | PCI error address, high | 4 | r | `ioc4_dma_error_intr` joins it to the low word | E |
| `0x8` | serial interrupt status | 4 | rw | `ioc4_attach` writes all ones; `ioc4_pending_intrs` and `ioc4_serial_intr` read it | E |
| `0xc` | other interrupt status | 4 | rw | `ioc4_attach` writes all ones; `ioc4_dma_error_intr` writes a port's bit; `xide_intr_clear` reads and writes it | E |
| `0x10`, `0x14` | serial, other interrupt enable set | 4 | w | `ioc4_write_ireg` | E |
| `0x18`, `0x1c` | serial, other interrupt enable clear | 4 | w | `ioc4_write_ireg` | E |
| `0x20` | control | 4 | rw | `ioc4_attach` writes `0xf`; `hardware_init` polls bit 7 | I |
| `0x24` | miscellaneous control: bits 3:0 PCI bus speed (0 is 33 MHz, 1 is 66 MHz) | 4 | rw | `ioc4_attach` read-modify-write (below) | I (role from a shipped development header; see [docs/coverage-ioc4.md](../../docs/coverage-ioc4.md)) |
| `0x28` | external interrupt output | 4 | w | `ioc4_eiattach` writes 0 | I |
| `0x30`, `0x34` | GPIO control set, clear | 4 | w | `ioc4_attach` writes `0x30` to `0x30`; `ioc4_eiattach` writes `0x200` or `0xff00` to `0x30` and 2 to `0x34` | I |
| `0x38` | GPIO data | 4 | | no routine touches it | U |
| `0x40 + 4n` | GPIO pin n | 4 | w | `ioc4_set_proto` writes 0 or 1 to a pin number kept in the port's record | I |
| `0x100` to `0x11c` | ATA command block, 8 words | 4 | rw | `ide.o` (below), index n at `0x100 + 4n` | I |
| `0x120` | ATA control block | 4 | w | `ide.o` (below) | I |
| `0x140` to `0x160` | ATA DMA block, 9 words | 4 | rw | `ide.o` (below), index n at `0x140 + 4n` | 6 I (indices 1, 2, 5, 6, 7, 8), 3 U (0, 3, 4) |
| `0x200` | keyboard and mouse control | 4 | rw | `ioc4_pckm_attach` stores `0xc00000`; `pckm_sendok` polls bits 0 and 1; `pckm_restart` sets bit 18 or 19 | E |
| `0x204`, `0x208` | keyboard, mouse receive | 4 | r | `pckm_pollcmd` reads one by port | E |
| `0x20c`, `0x210` | keyboard, mouse transmit | 4 | w | `pckm_pollcmd` writes one by port | E |
| `0x300` to `0x30c` | serial ring bases: ports 0 and 1 low, high; ports 2 and 3 low, high | 4 | w | `hardware_init` | E |
| `0x310` to `0x324` | port 0 control, TX producer, TX consumer, RX producer, RX consumer, RX timer | 4 | rw | `sio_ioc4.o` (below); ports 1 to 3 at `+0x1c`, `+0x38`, `+0x54` | E |
| `0x328` | port 0 shadow | 4 | rw | `set_DTRRTS`, `ioc4_query_DCD`, `ioc4_query_CTS` | I |
| `0x380` to `0x385` | UART 0 registers 0 to 5 | 1 | rw | `sio_ioc4.o`; UARTs 1 to 3 at `+8`, `+0x10`, `+0x18` | E |
| `0x387` | UART 0 register 7 | 1 | w | `set_baud_ti` stores a computed value | I |

**59 register kinds** (the GPIO pins as one family; the four serial ports' repeats are not counted again; the ATA command
block counts eight kinds and the DMA block nine): **32 established, 22 inferred, 5 unknown** as graded by the code alone. The coverage pass
([docs/coverage-ioc4.md](../../docs/coverage-ioc4.md)) moves `0x24` to inferred and the DMA block roles (indices 1, 2, 5, 6, 7, 8) to
established by a public driver; the unknowns left are `0x38` (no routine touches it) and DMA indices 0, 3 and 4 (named by the
public driver as timing and the current memory address, which no IOC4 path reaches).

### Interrupt registers (`0x8` to `0x1c`): established

- `ioc4_write_ireg` (`0x94`, read in full) is the only writer of the four enable registers. `ioc4_write_ireg(record, bits, op,
  type)`: type 0 selects the serial pair, type 1 the other pair; op 0 stores `bits` to the enable-set register (`0x10`, `0x14`) and
  op 1 to the enable-clear register (`0x18`, `0x1c`). It holds the record's lock throughout. No shadow, no polling mode: IOC4
  has none of the IOC3 enable logic.
- `ioc4_attach` (returns 0 or -1) clears every enable (`ioc4_write_ireg(record, 0xffffffff, 1, type)` for both types) and then writes all ones to `0x8`
  and `0xc` (the acknowledge pattern, inferred as for IOC3).
- `ioc4_pending_intrs` (`0x14c`) reads `0x8`, `0xc`, `0x10` and `0x14`; read for its accesses only.
- `ioc4_dma_error_intr` (`sio_ioc4.o` `0x734`, read in full) writes the port's mask word to `0xc` first, reads `0x0`, and if bit 0 is set
  prints the port and address (bits 31:6 of the low word with the high word as bits 63:32; the port character is `'1'` plus twice
  the value in bits 4:2, and bit 1 picks the word RX or TX printed after it, inferred from the order of the two strings) and, when bit 5 is
  set, a second message; then it re-enables the port's bit through `ioc4_write_ireg(record, mask, 0, 1)`.
- `xide_intr_clear` (`IP35/usr/cpu/sysgen/IP35boot/ide.o` at 0x1634, 524 bytes, read in full) clears and reports an ATA interrupt. It takes the
  controller record and returns 0, 1 or 2. The first test is the vendor halfword at +286 of the record. For 4245 (0x1095, the CMD649-class
  controller) it reads the configuration byte at 0x50, prints it ("cmd649 BEFORE intr"), writes the same byte back, reads it again, prints it
  ("AFTER intr") and returns 0. For any other vendor than 4245 and 4265 it returns 0 at once. For 4265 (0x10a9, this part) it reads index 3 of
  the interrupt block (`0xc`, a byte access through the accessor, which for this vendor loads the word) and masks bits 1:0. With both clear it
  prints "interrupt NOT from IDE device...returning" and returns 1. Otherwise it prints "interrupt from IDE device", and when bit 1 is set it
  also: stores 1 in the byte at +271 of the record, prints "Other IR Reg ... gives ATA_MEMERR", reads index 0 (`0x0`) and index 4 (`0x10`) of
  the block and the PCI command and status word at configuration offset 4, prints the three values labelled "err_addr_low", "err_addr_high" and
  "status_cmd_reg", prints "ATA Error (from PCI Regs)" when `(low word & 0x1e) == 8`, writes `0x146` to configuration offset 4 (whatever that test
  gave) and stores 1 to index 0 of the block. When bit 1 is clear it stores 0 in the byte at +271 instead. Both ways it then stores 3 to index 3,
  reads index 3 back, prints it and returns 2. Established. The value read from index 4 is only printed, never tested, and index 4 is `0x10`,
  which the table above gives as the serial interrupt enable set register, not the high half of the error address: the shipped message names it
  the high word, the public driver puts that word at `0x4`, and the difference changes nothing but a debug line. Inferred: that the
  `0x146` write is the same command-register restore `ioc4_attach` performs, and that the store of 1 to index 0 acknowledges the error latch
  (no routine reads it back).

### Control, GPIO and the unnamed `0x24`

- `ioc4_attach` (returns 0 or -1) stores `0xf` to `0x20` and `0x30` to `0x30` (established). `hardware_init` reads `0x20` repeatedly and leaves the loop
  when bit 7 is set (established); inferred: no serial channel is the current bus requester.
- `ioc4_attach` reads the configuration byte at 8 (`pciio_config_get`, offset 8, width 1: the revision byte) and compares it unsigned with 79 (`sltiu` at `0x35c`).
  **If it is 79 or more** (the `beqz` at `0x360` on the `sltiu` result jumps to `0x538`; an earlier reading of this page had the sense reversed) it calls `pciio_businfo_get` and `pciio_businfo_bus_speed_get` (both in `pciio.o`: the second returns the word at +12 of the record the first returns) and,
  when the result is exactly 1, ANDs the 32-bit word at `0x24` with `0xfffffffffffffff0` (`lw` at `0x554`, `sw` at `0x564`), clearing bits 3:0 (established, read in full; no other routine of the IP35
  objects touches `0x24`). A revision below 79, or any other speed value, skips the clear and the word is never written.
  **What the speed value is (established, read in full: `pcibr_businfo_get` `pcibr.o` `0x44ec`, 232 bytes, and `pic_attach2` `pic.o` `0x888` to `0x8a8`).** For a PIC the bus-information record is the
  16 bytes at the bridge record +2728: words for multiple masters (+0), ASIC type (+4), bus type (+8) and bus speed (+12). `pic_attach2` stores a halfword at record +116
  built as the mode value (`pcireg_mode_get`, 1 for PCI-X) in bit 0 and the speed value (`pcireg_speed_get`, bits 5:4 of the control register) shifted left one in bits 2:1.
  `pcibr_businfo_get` then, for chip type 2: stores ASIC type 4; bus type 2 and multiple masters 1 when halfword bit 0 is set (PCI-X), bus type 1 and multiple masters 0 otherwise;
  and stores bus speed 1 for halfword 0 (speed field 0, conventional PCI), 2 for halfwords 2 and 3 (speed field 1, PCI or PCI-X), 3 for halfword 5 (speed field 2, PCI-X) and 4 for halfword 7 (speed field 3, PCI-X);
  for halfwords 1, 4 and 6 it stores no speed and the word keeps the zero the record was allocated with. So the clear happens on a conventional-PCI bus whose speed field is 0, on an IOC4 of revision 79 or later.
  For chip type 1 (XBridge) the same routine stores bus speed 1 when the halfword at record +116 is zero and 2 otherwise; how that halfword is set for an XBridge was not read.
  Inferred: speed field 0 is the 33 MHz setting (the values 1 to 4 line up with 33, 66, 100 and 133 MHz); the code stores only the numbers. Unknown: what bits 3:0 of `0x24` do and why the
  attach clears them only on later IOC4 revisions on a slow bus; no string in the object or the pciio objects explains it, and a guess at the reason would rest on the two tests alone.
- `ioc4_eiattach` (`ioc4_ei.o` `0x4b4`, returns 0 or -1) stores 2 to `0x34`, `0x200` to `0x30`, then `0xff00` to `0x30`, writes `0xff800000` to `0xc`, 0 to
  `0x28`, and connects its handler (established). The two stores to `0x30` are on one path in sequence. Inferred: edge select
  bits and the output held low.

### Serial ports (established: `hardware_init`, `ioc4_serial_attach`, `ioc4_enable_tx`)

- **Layout** (`ioc4_serial_attach` `0xbdc`, read through the four ports' pointer setup): each port record keeps a pointer to its register
  block (record +64), its UART (+72) and the chip window (+56). Port 0: block `0x310`, UART `0x380`. Port 1: `0x32c`, `0x388`. Port
  2: `0x348`, `0x390`. Port 3: `0x364`, `0x398`. The records are allocated together (672 bytes, 168 each).
- **Reset** (`hardware_init` `0x8f8`, read in full): store `0x80000000` to the port's control register; wait until `0x20` bit 7 is set;
  store 0; read the TX consumer (`+8`), mask `0xff8`, store to the TX producer (`+4`) and a record copy; read the RX producer
  (`+12`), mask `0xff8`, store to the RX consumer (`+16`) and a record copy; then the UART: 0 to registers 3 and 1, `set_baud_ti`, 3 to
  register 3, 1 then 7 to register 2, 0 to register 4; `0xa0` to the RX timer (`+20`) and the control word `0x180` last. Before the
  first control write it waits for UART register 5 bit 5, 3 microseconds a try. The sequence matches IOC3's except for the control
  word (IOC3 stores `0x10180`) and the wait (bit 7 here, bit 22 and a requester field there). Established.
- **Ring base**: `hardware_init` stores the ring's bus address as high word then low word ORed with 1, to `0x304` and `0x300` when the
  port is the first of its pair, or to `0x30c` and `0x308` for the pair that starts at port 2; the other two ports write nothing
  (the first pair's configuration entry compares with the table start, the second with the start plus 80 bytes). Established.
- **Pause and indices**: as for IOC3 (`ioc4_enable_tx` `0x22ec` stores `0x20000000` to the control register and polls bit 30).
- **Mode select**: `ioc4_set_proto` (`0x33c4`, returns 0 or 1) writes 0 or 1 to `0x40 + 4 * pin`, the pin from a static table (not read).
- **UART registers**: line control at UART+3, divisor latch at +0 and +1, FIFO control at +2, modem control at +4, line status at +5
  (established, from `hardware_init` and `set_baud_ti`), register 7 as IOC3.

### ATA controller (established offsets; inferred roles)

`xide_attach` (`ide.o` `0x264`, read for the IOC4 path) maps four pieces of the window and keeps their pointers in the controller
record: record +504 for offset `0x0`, 32 bytes (the interrupt block); +480 for offset `0x100`, 32 bytes; +488 for `0x120`, 4 bytes;
+496 for `0x140`, 36 bytes. Established. The register accessors (`xide_getb` `0x9154`, `xide_putb` `0x905c`, `xide_getw` `0x91b4`,
`xide_putw` `0x90b0`, `xide_getdw` `0x9218`, `xide_putdw` `0x9104`) test the controller's vendor halfword against `0x10a9`; for IOC4
they address `base + 4 * index` with a 32-bit load or store (the byte and halfword forms mask the loaded word and store the
value as a whole word); for the other vendors they address `base + index` with byte lane swapping (`index ^ 3`, `index ^ 2`).
Established.

- **Interrupt block** (record +504): `xide_chip_init` (`0x914`) and `xide_attach` store 3 to index 5 (`0x14`, interrupt enable set
  for the other group) and read it back; `xide_intr_clear` (returns 0, 1 or 2) and `xide_interrupt_check` (`0x1840`) read index 3 (`0xc`) and test bits 1:0;
  `xide_intr_clear` writes index 3 and index 0 back. Roles inferred: bit 0 ATA interrupt, bit 1 ATA memory error.
- **Command block** (`0x100`, record +480): `xide_piocommand`, `xide_device_reset`, `xide_bus_reset` and `xide_execute_device_diagnostic`
  read and write indices 0 to 7 as byte or word accesses (index 0 as a halfword in `xide_piocommand` and `xide_send_pktbytes`, index 7 read
  as status in `xide_get_status` and `xide_bus_reset`, index 6 written four times by `xide_bus_reset`). Inferred: the eight ATA task
  file registers in their usual order.
- **Control block** (`0x120`, record +488): accessed by `xide_bus_reset`, `xide_piocommand` and `xide_execute_device_diagnostic`, mostly
  writes; inferred: the ATA device control register. (The index arguments the call-site pass could recover for this base are
  stale values of an earlier argument, so no index is claimed.)
- **DMA block** (`0x140`, record +496; established: `xide_pktDMA_start` `0x2d30`, 892 bytes, `xide_pktDMA_complete` `0x30ac`, 612 bytes and `xide_dma_init` `0x6290`, 908 bytes, read in full; these three and `xide_attach`'s pointer stores are the only routines of `ide.o` that load the record's DMA pointer).
  Each routine first compares the controller's vendor halfword (record +286) with `0x1095` (another vendor's controller, which gets its own path) and `0x10a9` (this chip); any other value returns 0. Index n is the 32-bit word at `0x140 + 4n`.
  Earlier text on this page credited the other vendor's path accesses to this chip; they are removed here.
  - `xide_dma_init` touches no register on this chip: the `0x10a9` case falls through to `return 0` (its other path computes a transfer-mode value from the drive's identify words and writes the other controller's registers and PCI configuration bytes 81 and 83 to 86).
  - `xide_pktDMA_start`, this chip's path, in order: read index 7; if bit 3 is set, write 2 to index 7 and re-read it up to 100 times (a `delay` call before each read) until bit 1 reads clear, printing a message on the 100th failure; read index 7 again, and if bit 4 is set write 2 to it and poll bit 1 up to 100 times without the delay call (same message on failure);
    write the low 32 bits of the 64-bit bus address held at request +32 to index 1 and the high 32 bits to index 2; clear 128 bytes at controller +392 (`bzero`, a table in memory); write the 32-bit word at controller +388 to index 8; set the byte at request +224 to 64; write 1, or 5 when bit 0 of the halfword at +18 of the request's command record is set, to index 7 (the last access, the start).
  - `xide_pktDMA_complete`, this chip's path: write 2 to index 7 and poll bit 1 clear up to 100 times; read index 7 (byte), index 5 and index 6 (both read as 32-bit words and masked to 16 bits by the halfword accessor); print them and their bits 4:1; return 16 (an error code) when index 7 bit 4 is set or the byte at controller +271 (the latch `xide_intr_clear` sets on a memory error) is nonzero; otherwise return 0. The only other effect is a warning, printed when index 6 plus 8 (the whole values) is below index 5, and skipped when both values have zero in their low 9 bits (whole-value compare, then the return 0 is the same either way). Return values for the other vendor's path are not read here.
  - Roles (inferred; no spec and no string names them): 1 and 2 are the low and high halves of the transfer's bus address (what the start writes there); 8 is the bus address of the 128-byte table (what the start stores from +388 after clearing the table at +392); 7 is a control and status byte, written 2 to clear or abort, 1 or 5 to start (bit 2 is set for one transfer direction), with bit 1 busy while it clears, and bits 3 and 4 tested before a new transfer, bit 4 an error; 5 and 6 are counters (their low 9 bits are what the completion compares).
    Indices 0, 3 and 4 are not accessed on this chip by any `ide.o` routine; the other vendor's path writes 0, 2, 3 and 4 of the same base with its own meaning, which does not carry over.

### Keyboard and mouse (established)

`ioc4_pckm_attach` (`ioc4_pckm.o` `0x5c`) stores `0xc00000` to `0x200`. `pckm_sendok` (`0x1b20`) reads it and waits for bit 0 (port 0) or
bit 1 (port 1) to clear; `pckm_restart` (`0x2298`) ORs bit 18 or 19 into it, stores the value back, reads and stores it back again. The
receive words are `0x204` (port 0) and `0x208` (port 1), the transmit words `0x20c` and `0x210`, by the displacements `pckm_pollcmd`
adds. Same structure and constants as IOC3's `0x9c` to `0xac`, at `0x200` to `0x210`.

## Routines in the IP35 `ioc4.o` build

The four routines below have the same instruction words as copies in the IP27 `ioc3.o` build, which is described on
[the IOC3 page](../ioc3/README.md#routines-in-the-ip27-ioc3o-build). Each is read here from its own body. Relocations
come from `objdump -dr` on the object.

- `ioc4_console_vhdl_get` (`IP35/usr/cpu/sysgen/IP35boot/ioc4.o` at 0x1014, 24 bytes) loads the pointer in the small-data slot at
  -30720 from `gp` (a relocation against `.sbss`). It returns the word at +0 of that pointer. With a null pointer it returns -1: the
  `li v0,-1` in the delay slot of the `beqz` at 0x1018 runs before the branch, so the -1 stands on that path, and the `lw` at
  0x1020 is skipped. Established: the six words and the `.sbss` relocation match the IP27 `ioc3.o` copy at 0x1210.
- `ioc4_subdev_enables` (`IP35/usr/cpu/sysgen/IP35boot/ioc4.o` at 0x1124, 44 bytes)
  keeps its doubleword argument in its frame and calls `ioc4_subdev_ptr` with `a0` unchanged and the create flag set in
  the delay slot. A non-null pointer gets the saved doubleword at +0; a null return skips the store.
  The 11 words match the IP27 build, except that the call reloc names
  `ioc4_subdev_ptr` where the IP27 copy names `ioc3_subdev_ptr`. Established.
- `ioc4_subdev_enable` (`IP35/usr/cpu/sysgen/IP35boot/ioc4.o` at 0x1150, 68 bytes)
  calls `ioc4_subdev_ptr` with `a0` and the create flag, as the enables routine does.
  On a non-null pointer it ORs bit `a1` into the doubleword at +0.
  The bit is 1 shifted left by the low five bits of `a1` (a 32-bit `sllv`).
  The update is a load-linked, OR and store-conditional loop, repeated through a branch-likely (`beqzl`) while the store fails.
  The 17 words match the IP27 build except the call reloc (`ioc4_subdev_ptr` where the IP27 copy names `ioc3_subdev_ptr`). Established.
- `ioc4_subdev_disable` (`IP35/usr/cpu/sysgen/IP35boot/ioc4.o` at 0x1194, 72 bytes)
  is the clear-bit form of the enable routine. It calls `ioc4_subdev_ptr` the same way, with `a0` and the create flag.
  On a non-null pointer it inverts the 32-bit `sllv` mask with `nor` and ANDs it into the doubleword at +0 through the
  same load-linked and store-conditional loop. The 18 words match the IP27 `ioc3_subdev_disable` copy except the call reloc. Established.

## Against the public drivers (reported after the reading above)

Sources: Linux v5.3 `include/linux/ioc4.h`, `drivers/misc/ioc4.c`, `drivers/tty/serial/ioc4_serial.c`, `drivers/ide/sgiioc4.c`
(the `linux-ia64` pin) and the 2.4 `arch/ia64/sn/io/sn2/ioc4` code (the `linux-2.4.37` pin). No OpenBSD or NetBSD IOC4 driver
exists. The PIC and Bedrock side of IP35 is in [../pic/README.md](../pic/README.md).

| point | IRIX reading | public drivers | result |
|---|---|---|---|
| interrupt registers `0x0` to `0x1c` | as in the table | `ioc4_misc_regs`: error address low and high, serial and other status, enable set and clear pairs in the same order | agree |
| `other_ir` bits 1:0 | ATA interrupt and memory error written as 3 to the enable set | `ioc4_other_int`: `ata_int` bit 0, `ata_memerr` bit 1 | agree |
| error address low | bit 0 valid, bit 1 RX or TX word, bits 4:2 port number, bit 5 multiple, bits 31:6 address | `ioc4_pci_err_addr_l`: valid, `master_id:4` (bits 4:1), `mul_err`, address 31:6 | agree on valid, multiple and address; IRIX splits bits 4:1 into bit 1 (RX or TX word) and bits 4:2 (port number), Linux calls bits 4:1 one master identifier |
| control `0x20` | stores `0xf`, waits for bit 7 | `cmd_pulse:4` (bits 3:0) and `sio_diag_idle` at bit 7 | agree on the polled bit; the stored `0xf` is a four-bit field, equal to the public `cmd_pulse` width |
| `0x24` | bits 3:0 cleared at revision 79 or later on a conventional-PCI bus with speed field 0 (bus speed value 1) | `unused1` | **differ**: IRIX uses it; a shipped development header names it a PCI bus speed field (inferred) |
| serial layout | ring bases `0x300` to `0x30c` (pair order low then high), ports at `0x310` and every `0x1c`, UARTs at `0x380` and every 8 | `struct ioc4_serial`: `sbbr01_l`, `sbbr01_h`, `sbbr23_l`, `sbbr23_h`, then four 7-word ports, then four UARTs | agree |
| ring base write | high word, then low word ORed with 1 | `IOC4_SBBR_L_SIZE` 1 means 4 KB rings; the driver writes high then low plus the size bit | agree |
| reset wait | `0x20` bit 7 | `IOC4_SIO_CR_SIO_DIAG_IDLE` | agree |
| UART byte lane | line control at UART+3 | `ioc4_uartregs` puts line control first | differ in lane, as expected: IRIX is big-endian and Linux ia64 little-endian, so the lane order mirrors; inferred |
| ATA windows | `0x0` (32 bytes), `0x100` (32), `0x120` (4), `0x140` (36) | `IOC4_INTR_OFFSET 0`, `IOC4_CMD_OFFSET 0x100`, `IOC4_CTRL_OFFSET 0x120`, `IOC4_DMA_OFFSET 0x140`, `IOC4_CMD_CTL_BLK_SIZE 0x20` | agree |
| ATA interrupt indices | block indices 3 (status) and 5 (enable set) | `IOC4_INTR_REG 3`, `IOC4_INTR_SET 5`, `IOC4_INTR_CLEAR 7` | agree; and the four-byte stride |
| ATA DMA words | 32-bit stores at indices 1, 2 and 8 and at 7 (the accessor is named for a byte, but on this part it stores the whole word) in `xide_pktDMA_start`; reads of 5, 6 and 7 in `xide_pktDMA_complete` | `IOC4_DMA_PTR_L 1`, `PTR_H 2`, `DMA_CTRL 7`, `BC_DEV 5`, `BC_MEM 6`, `ADDR_H 4`, `TIMING 0` | agree on 1, 2, 5, 6 and 7; IRIX also writes index 8, which is not in the names read; indices 0 and 4 are not touched on this chip |
| DMA error read of index 4 | `xide_intr_clear` reads index 4 after index 0 and only prints it, labelled the high word | high word is at `0x4` (index 1) | **differ**; the read has no effect except a debug line, so the contract is unaffected (the routine is read in full) |

## Reset expectations

None read. `ioc4_attach` writes the control, GPIO control, enables and both status registers before use; everything else is unknown.

## Open

- **`0x24`**: the role is inferred (bus speed field). Open: why the clear is gated on revision 79 and what values above 1 mean.
- **ATA DMA block**: roles are established by the Linux driver and the IRIX accesses agree ([docs/coverage-ioc4.md](../../docs/coverage-ioc4.md));
  index 8 is the end-of-transfer flag area, not a second table. Open: whether IRIX waits on that area, and the request's list layout.
- **ATA error line**: `xide_intr_clear` compares the masked error address with 8 where the driver's table puts ATA at 8 in a field that masks to `0x10`.
- **Ports 1 to 3 GPIO pins and the per-port tables** are static data not extracted.
- **`ioc4_error_handler` and `ioc4_intr`/`ioc4_intrd`** are read for their accesses only.
- **Interrupt dispatch**: which `sio_ir` and `other_ir` bits each handler claims is not read.
