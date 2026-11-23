# WD33C93 / WD33C93A SCSI controller on the Indigo

The SCSI controller of the Indigo, both the R3000 board (IP12) and the R4000 board (IP20), is a Western Digital WD33C93-family
part behind the HPC1. The CPU does not map it directly: it sees an address port and a data port in the HPC1 window, and the
HPC1's SCSI DMA channel moves bulk data through the same chip without CPU help. This page covers the chip's register file as
the IRIX R4000 Indigo driver and the 4.0.5D PROM drive it, the reset and detection sequences, the command and status codes
they use, and how the interrupt and the DMA channel meet the chip. The register layout, grades and `ro` masks are in
[`registers.toml`](registers.toml); the generated reference is `registers.md`. The HPC1 side (DMA channel registers,
descriptors, byte order) belongs to the HPC1 page, `devices/hpc1`, when it lands; this page only records what the SCSI
driver does to that channel.

Labels follow [AGENTS.md](../../AGENTS.md): **established** is read in full from a shipped object, the PROM or the data sheet,
**inferred** is reasoned, **unknown** is unsettled. Nothing was measured on a board. Reset values come from the data sheet,
so they hold for the part, not for any board measurement.

## Sources

- **Western Digital, WD33C93A Data Sheet and Application Notes, November 1990** (held in the Library): the register map
  (section 6.1), register descriptions (6.2), reset conditions (6.3), command list (7.1), advanced features (7.3), status codes
  (6.2.19), the Select-and-Transfer command phase table, and application notes E062-B (differences between the 33C93, the 33C93A
  and the 33C93B) and E043-A. Citations below name the section.
- **IRIX 6.5 IP20 boot objects**: `wd93.o` (the driver; function names are its own symbols, addresses are `.text` offsets in the
  object as linked for relocation) and `kernel.o` (`wd93_init`, `wd93_resetbus`, `wd93_go`, `wd93dma_flush`, `wd93_int_present`
  and the `scuzzy` table).
- **PROM 070-8116-004**, SGI Version 4.0.5D Rev A, sha256 `e6e1f1ed...ba97f82f`; addresses in the `0xbfc00000` window. **The
  4.0.5G image (070-8116-005) is not held on the host used for this reading and no 4.0.5G address is cited.** The
  [PROM page](../../platforms/ip20/prom-software.md#405g-differences) reports that the Ethernet, SCSI and serial drivers were not
  diffed function by function, so 4.0.5G's SCSI code is unchecked.
- **NetBSD** `sys/dev/ic/wd33c93.c`, `wd33c93reg.h`, `sys/arch/sgimips/hpc/wdsc.c` and `hpcreg.h` (public drivers, used for
  names, the HPC1 offsets and the revision probe). A public NetBSD boot capture of an R3000 Indigo (IP12) reports "WD33C93A SCSI,
  rev=0" and a 200 ns synchronous period at offset 12 for a disk; nothing equivalent was seen for the R4000 board.
- Notes from other projects were not used for any fact.

## Where it sits and how the CPU reaches it (established)

Both ports are single bytes in the HPC1 window (physical `0x1fb80000`), on a 4-byte stride, in the second least significant byte
lane of the big-endian word. A big-endian CPU addresses them as:

| Port | Offset in the HPC1 window | Physical address | Read | Write |
|---|---|---|---|---|
| address / auxiliary status | `+0x122` | `0x1fb80122` | auxiliary status register | address register |
| data | `+0x126` | `0x1fb80126` | selected register | selected register |

Sources: the `scuzzy` table in `kernel.o` (first two words of entry 0 are the kernel addresses `0xbfb80122` and `0xbfb80126`) and the
same two words in the PROM's own table at `0xbfc52f80`, which the PROM copies into each controller structure (`0xbfc12f88` to `0xbfc12fb4`) at offsets `0x150`
and `0x154` (kernel: `0x188` and `0x18c`); NetBSD maps the same bytes as the HPC1 device register block `0x11f` plus 3 and
plus 4 + 3. NetBSD's controller probe reads the 32-bit word at the address port and takes bits 15:8 on an HPC1 (bits 7:0 on an
HPC3), which fixes the lane. Every shipped access seen is a byte access (`lbu` and `sb` through the two pointers in `wd93.o` and
the PROM); no halfword or word access to either port was seen. The HPC1 endian register at `+0xc0` is the HPC1 page's concern;
the lane above is the one a big-endian CPU uses and the one the PROM and IRIX use.

The two ports and the lane of the INT2 registers differ (INT2 registers sit in the least significant lane, `+3`), so a model must
not give the HPC1 window one common byte lane.

## Indirect register access (established)

The chip has 28 internal registers behind two external ports (data sheet 6.1 and 6.2.2). Software writes a register index to the
address port, then reads or writes the data port. Rules a model must follow:

- **The index auto-increments** after each data-port access, except that it stays put when the selected register is the data
  register (`0x19`), the command register (`0x18`) or the auxiliary status register. The data sheet states this; IRIX and the PROM
  depend on it in the following places: `handle_intr` (`0x3c70`) selects the target LUN register and reads the data port twice to get
  the LUN and the command phase; it then selects the source ID register and reads twice to get the source ID and the SCSI
  status; `wd93_dma` (`0x51f0`) writes the 24-bit transfer count with one index write and three data writes; `startwd93` (`0x2e90`) loads
  up to 12 CDB bytes the same way; the reset tail writes source ID (`0x16`), then control (`0x01`) and timeout (`0x02`) with one
  more index write between them.
- **A read of the address port returns the auxiliary status register** (data sheet 6.2.1), which may be read at any time. IRIX
  and the PROM poll it for bit 4 (command in progress) clear before every command write and for bit 7 (interrupt) set to wait
  for a command to finish.
- Reading an undefined register returns all ones (data sheet 6.1 note 2); the Indigo software never relies on it.
- Registers `0x00` to `0x16` are cleared by the Reset command (data sheet 6.3.2); a hardware reset (the chip's master-reset
  pin) clears only the own ID register on the A part, plus the status flags (6.3.1, E062-B item 23, which says the original
  33C93 cleared all registers on a hard reset). The own ID register itself is only sampled at a Reset command.
- A qtest can discriminate: a write of index `0x03` followed by three data writes puts the bytes in `cdb[0..2]`; a read of the
  data port after selecting `0x19` twice reads the same register twice (no increment).

## Register summary

Offsets are internal indexes. The toml file has the fields, grades and `from` for each; this list is the one-line role and what a
qtest can check.

| Index | Name | Role | qtest hook |
|---|---|---|---|
| port | `aux_status` | INT, LCI, BSY, CIP, PE, DBR | reset reads `0x80`; INT clears on a status read |
| `0x00` | `own_id` | bus ID, EAF, EHP, EIH/RAF, clock select | all eight bits read back; hard reset clears it |
| `0x01` | `control` | DMA mode, IDI, EDI, HHP, HA, HSP | cleared by Reset command; IRIX writes `0x2d` or `0x8d` |
| `0x02` | `timeout` | selection timeout; 0 disables it | select to an absent target ends with `0x42` only when non-zero |
| `0x03`-`0x0e` | `cdb[12]` | CDB bytes for Select-and-Transfer | auto-increment |
| `0x0f` | `target_lun` | LUN out, target status in | holds the status byte after status `0x16` |
| `0x10` | `command_phase` | progress of Select-and-Transfer | `0x00` after a missed selection |
| `0x11` | `sync_transfer` | offset and period | IRIX loads a per-target value before each command |
| `0x12`-`0x14` | `transfer_count[3]` | MSB first | auto-increment; bytes not transferred after an abort |
| `0x15` | `dest_id` | target to select, data direction | written at each command start |
| `0x16` | `source_id` | reselection enable, who selected | `0x80` after reset when disconnect is on |
| `0x17` | `scsi_status` | interrupt cause | read clears INT; the chip holds it until read |
| `0x18` | `command` | command code, single-byte bit | write with INT set sets LCI and is ignored |
| `0x19` | `data` | FIFO port | polled for DBR in programmed phases |
| `0x1a` | `queue_tag` | WD33C93B only | write sticks only on a B |

Reset values: registers `0x00` to `0x16` read zero after a Reset command, `0x17` reads `0x00` or `0x01` (see below), the command
register reads zero, and the auxiliary status register reads `0x80` after a hardware reset (data sheet 6.3.1 and 6.3.2). These are
**established for the part**. After a power-on hard reset the registers `0x01` to `0x15` are unaffected, so their power-on value is
unknown; the PROM never depends on one because it issues a Reset command before using any of them.

## Controller presence test (established)

Both the PROM (`0xbfc13084`) and `wd93_earlyinit` (`0x10e8`) confirm the chip is present before touching it otherwise: for
`n` = 0 to 7, write index `0x00`, write `n` to the data port, write index `0x00` again, read the data port, and require it to
equal `n`. Any mismatch means no controller. IRIX then prints "wd93: controller %d not present at addr %x" (only when its
`showconfig` flag is set) and the PROM prints "sc%d: controller not present at addr %x". The values only exercise the ID field,
bits 2:0, so a model that stores all eight bits or masks to the defined bits passes. The test runs with the chip in whatever
state it powered up in: the address port write alone selects own ID.

## Reset sequence and the reset-complete status (established)

IRIX `wd93reset` (`0x2a74`) and the PROM's reset routine (`0xbfc147e4`) are the same sequence. In order:

1. Poll the auxiliary status register until CIP (bit 4) is clear.
2. **First call only:** select index `0x11` and read the sync-transfer register. IRIX discards the byte. The PROM saves it and the
   destination-ID register into its RAM if the sync value was non-zero (`0xbfc14850` to `0xbfc14898`); that keeps a boot
   device's negotiated setting across the reset (inferred from the code; no string says it).
3. Write own ID (index `0x00`): clock select 2 in bits 7:6, plus bits `0x28` (EAF and bit 5) when the caller wants advanced
   features, ORed with the host SCSI ID (environment variable `scsihostid`, 0 to 7; IRIX defaults to 0). The value is `0xa8 | id`, or `0x80 | id`
   when the caller asks for a plain reset. EAF is what makes the Reset command return status `0x01` instead of `0x00`.
4. If the auxiliary status register shows INT, select index `0x17` and read it (clears the pending interrupt).
5. Write index `0x18` and the Reset command code (0).
6. Wait for INT: first for CIP to clear (up to 1000 steps of 1 microsecond), then poll bit 7 up to 125 times with an 8 microsecond
   delay between polls, about 1 ms in all (IRIX `wait_scintr` at `0x5070`, PROM `0xbfc168cc`). When INT arrives, select
   `0x17` and read the status. If it does not, read the status anyway and set bit `0x1000` in the returned value.
7. **Error message.** If the returned value has `0x1000` set, i.e. INT never rose within the 1 ms window, print
   "sc%d controller didn't reset correctly" (PROM, string at `0xbfc4d6d0`, printed at `0xbfc14940`) or "wd93 controller %d
   didn't reset correctly" (IRIX, string at `.rodata+0x180`, printed at `0x2b58`). It is the only condition that prints it. The
   status value is not compared against anything before the message; the message does not mean a wrong status.
8. Compare the status (with the `0x1000` flag removed) with **`0x01`**. If equal, the chip has advanced features: it is a
   WD33C93A or B. The driver picks Control `0x2d` (burst DMA; `0x8d` if its burst flag is clear), reads index `0x03` and stores
   the byte. A byte below 11 records chip type 4, otherwise 8; both types turn on the advanced CDB-size mode. Anything other than
   `0x01` (including `0x00`, and a timeout) is treated as a plain WD33C93: Control `0x8d`, chip type 2, no advanced
   features afterwards.
9. Write source ID (index `0x16`) with `0x80` if disconnects are allowed for the controller, otherwise `0`. Select index `0x01` and
   write Control; IRIX then writes the timeout register (`0x40`; `0x20` if its clock-select byte is zero) as the next data write,
   using the auto-increment. The PROM writes timeout through a helper at `0xbfc126fc`, which writes `0x40`, or `0x08` when
   its flag argument is nonzero (the reset routine passes zero).

What a model must do: complete the Reset command with INT set and status `0x01` when own ID bit 3 was set at the time of the
command, `0x00` when it was clear, within about 1 ms of guest time. A model that never raised INT would send both programs to
the error message; one that returned another status would silently demote the chip to plain mode. A qtest can discriminate:
own ID `0xa8`, command 0, INT set, status 1; own ID `0x80`, command 0, status 0.

Index `0x03` after the Reset reads back zero on an A part (data sheet 6.3.2: registers `0x01`-`0x16` are cleared), which is below 11,
so IRIX records type 4. NetBSD's driver comment says the byte "is valid with RAF on wd33c93b", i.e. a 33C93B with bit 5 of own ID
set returns a revision code there (the IRIX writes bit 5 in `0xa8`). That the revision code on a B is 11 or more is **inferred**
from the IRIX compare and the NetBSD comment together; no B part is documented as fitted to an Indigo.

## Chip revision detection (established for the sequence; revision values inferred)

| Probe | WD33C93 | WD33C93A | WD33C93B |
|---|---|---|---|
| Reset status | `0x00` | `0x00` with EAF clear, `0x01` with EAF set | same as the A |
| Index `0x03` after Reset with own ID bit 5 set | zero | zero | a revision code, inferred 11 or more by the IRIX test |
| Queue tag register (`0x1a`) write/read-back (NetBSD only) | n/a | does not stick | sticks |
| Status `0x01` after Reset | not reachable | yes | yes |

IRIX and the PROM test only the first two rows. They do not use the queue-tag test, the B's fast SCSI bit or its tag
messages. A model should answer as a WD33C93A (status `0x01`, index `0x03` zero, no queue tag register); that is what a public
NetBSD capture of an R3000 Indigo reports ("WD33C93A, rev=0"). Which part the R4000 board carries is **unknown**; the 4.0.5D PROM
and IRIX run on both an A and a plain part, and the IRIX driver chooses its CDB-size mode from status `0x01` alone (`startwd93`
writes the CDB length into own ID only when the chip type has bit 2 or 3 set).

## Commands the IRIX driver and the PROM issue

All commands are written to index `0x18`. Established unless noted; the others in the data sheet's list were never seen issued.

| Code | Command | Where |
|---|---|---|
| `0x00` | Reset | both, reset sequence |
| `0x04` | Disconnect | IRIX `handle_intr` after status `0x41` (`0x40b4`) |
| `0x06` | Select with ATN | IRIX `do_select` (`0x4fc4`), PROM `0xbfc167e4`; device probe: expects status `0x11`, then `0x8e` |
| `0x08` | Select with ATN and Transfer | IRIX `setdest` (`0x2df4`), `wd93_transfer` (`0x2d8c`); PROM `0xbfc14c58` and `0xbfc14cdc` |
| `0x20`, `0xa0` | Transfer Info, optionally single byte | IRIX `ack_msgin`, `do_trinfo`, PROM `0xbfc164e0` |
| `0x03` | Negate ACK | IRIX, through the last-command-ignored retry routine (inferred from the argument) |
| `0x02` | Assert ATN | IRIX extended-message handling (inferred) |
| `0x01` | Abort | IRIX abort and timeout paths (inferred) |

The PROM and IRIX always use the combination command; the initiator-only driver never uses the target-mode commands, Translate
Address, Reselect, or Select without ATN. A model needs the commands above to boot; the rest can be errors (status `0x40`) until a guest needs them.

**Last-command-ignored.** The data sheet says the chip needs about 7 microseconds between a read of the SCSI status register
and a write of a command. IRIX's `wd93cmd_lci` (`0x53b8`) writes the command, waits for CIP, tests LCI, and on a set LCI with INT
pending reads the status register and writes the command again; `wait_scintr` has the same recovery. A model that sets LCI when a
command is written while INT is set will exercise it; one that does not will never take the path (harmless).

## Select-and-Transfer in the driver, step by step

For a normal command `startwd93` (`0x2e90`) does, in order: transfer count to zero (index `0x12`, three zero writes) for no data, or
`wd93_dma` loads the count; sync transfer register (the per-target value, initially `0x20`); own ID with the CDB length
when the chip has advanced features; CDB bytes into index `0x03` onward; command phase `0x00`; the HPC1 DMA channel is programmed
and started when there is data (see below); then `setdest` writes the destination ID (target, with bit 6 for data in), the target
LUN register, and finally command `0x08`.

The interrupt handler `handle_intr` (`0x3c70`) then waits for CIP and BSY clear, reads LUN, command phase, source ID and status
(by auto-increment as above) and acts on the status. The values it compares are in the toml `STATUS_` constants; the main ones
are `0x16` (complete; the target status is in the LUN register), `0x21` (save data pointers, resume with command phase `0x41`),
`0x85` (disconnect), `0x81`/`0x80` (reselect), `0x41` (unexpected disconnect), `0x42` (select timeout), `0x43`/`0x44` (parity),
`0x47` (bad status), `0x48` to `0x4f` (unexpected phase) and `0x8f`/`0x8e` (REQ for message in or out). A status of `0x00` after a
command is treated as a spurious controller reset and sends the driver through `handle_reset`.

## Interrupt path

IRIX registers `wd93intr` as the handler for INT2 local 0 bit 2, vector 2 (`wd93_init` in `kernel.o`; see
[platforms/ip20/interrupts.md](../../platforms/ip20/interrupts.md) and [devices/int2](../int2/README.md)). The handler reads the
auxiliary status register and calls `handle_intr` only if bit 7 is set. It acknowledges by reading the SCSI status register, which drops INT
and so the INTRQ line. No shipped code writes an INT2 register to acknowledge the SCSI interrupt (established by the INT2 page); the
level therefore follows the chip's INT bit (inferred; the HPC1's part in gating or latching the line is HPC1-page material and
unread). HPC1's SCSI DMA channel raises no separate interrupt for IRIX: wd93.o registers only vector 2. DMA completion shows up as the
chip's own status (`0x16`, a transfer count of zero, or a phase change).

The PROM does not use interrupts for SCSI; it polls bit 7 of the auxiliary status register.

## The HPC1 SCSI DMA channel (what the SCSI driver does to it)

Offsets are from the HPC1 window; names are NetBSD's `hpcreg.h`. The kernel's `scuzzy` table holds the channel register addresses in
this order: address port, data port, then `+0x94` (control), `+0x88` (byte count and flags), `+0x8c` (current buffer pointer),
`+0x90` (next descriptor pointer), `+0x98` (DMA config), `+0x9c` (device FIFO pointer). The PROM table at `0xbfc52f80` has the same
entries.

- **Start** (`wd93_go`, `kernel.o 0x4550`): write the physical address of the first descriptor to `+0x90`, then write `0x90` (active
  and data in, device to memory) or `0x80` (active, data out) to `+0x94`. `wd93_dma` loads the chip's transfer count first, so
  the chip is armed before the channel runs; the chip itself starts the data phase after the Select-and-Transfer command.
  Control bits per NetBSD: `0x01` reset (channel and external controller), `0x02` flush, `0x10` direction, `0x80` active.
- **Chip side:** Control register DMA mode field is 1 (burst demand-mode) when IRIX's burst flag is set and 4 (single-byte) otherwise.
  In burst mode the chip raises DRQ while its 12-byte FIFO has data or room, and the HPC1 answers with DACK and a read or write cycle on
  the data register. A model only needs the HPC1 channel to move bytes between memory and the data register at the rate the chip
  asks; the datasheet and the HPC1 page decide the handshake.
- **Stop and flush** (`wd93dma_flush`, `kernel.o 0x46e4`): for a read, set `+0x94` bit 1 and poll `+0x94` bit 7 until it clears
  (up to 512 reads), warn if it does not; the stop path writes zero to `+0x94`, and the driver then repairs its descriptor list
  from the residue (the transfer count read back from the chip). The PROM's version (`0xbfc2780c`) is the same loop and prints "SCSI DMA in progress bit never cleared"
  on failure.
- **Reset the chip and the bus** (`wd93_resetbus`, `kernel.o 0x4500`; PROM `0xbfc275d8`): write 1 to `+0x94`, wait 25 microseconds,
  write 0. NetBSD describes bit 0 as "reset DMA channel and external controller" and its controller probe, after the same pulse,
  reads the auxiliary status register and expects exactly `0x80`. So the pulse acts as the chip's master reset (own ID zero, status
  zero, INT set); whether it also drives SCSI RST on the bus is **inferred** from the driver name and the data sheet's suggestion
  to wire RST into the reset, and is not shown by any shipped read.
- The descriptors are 16-byte entries; the words at entry offsets `+0` and `+4` are the count (low 13 bits, flags above) and the
  buffer address, which `wd93dma_flush` edits to account for the residue. The HPC1 page owns the descriptor layout.

## What a model needs to boot the PROM and IRIX

- The two ports with the lane and auto-increment above, byte access only.
- Reset (command and hardware): status `0x01` with EAF, `0x00` without, INT within about 1 ms, registers cleared as listed.
- Select-with-ATN against a present and an absent target: `0x11` then `0x8e` for a present one; for an absent one, with the timeout
  register zero no interrupt (the PROM's probe times out after 250 ms and gives up), with a non-zero timeout status `0x42`.
  The PROM writes timeout `0x40` after its reset, so absent targets give `0x42` on a real part.
- Select-with-ATN-and-Transfer with phase tracking, the command phase register, the transfer count and the HPC1 DMA channel; status
  `0x16` with the status byte in the LUN register.
- Disconnect and reselect (`0x85`, `0x81`) so IRIX's overlapped I/O works; the PROM does not need them.
- LCI behaviour for a command written with INT set.

## Open

See [questions/ip20-wd33c93.md](../../questions/ip20-wd33c93.md): the clock frequency of the board, which chip revision the R4000 board
fits, the byte lane under little-endian access, what the revision code on a B is, how the HPC1 gates the interrupt line, and what the
4.0.5G PROM does differently (not read).
