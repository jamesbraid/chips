# QLogic ISP1040 SCSI host adapter

The ISP1040 is the single-channel QLogic SCSI adapter on the BaseIO and BaseIO-G boards, PCI vendor
`0x1077`, device `0x1020`. The `hinv` listing calls it QL1040B. Its register offsets, bit fields,
mailbox opcodes and status-entry offsets are in [devices/isp1040/registers.md](registers.md),
generated from [devices/isp1040/registers.toml](registers.toml). Each item there carries its grade and its
driver or standard source.

## What the contract rests on

No QLogic programming manual for this part is held in this repository, so the register and mailbox
contract comes from the public drivers. Two drivers agreeing is the strongest evidence available.
Where only one driver names a value, the entry is inferred. The sources are pinned in
[sources/INDEX.md](../../references/documents/INDEX.md): the Linux `qla1280` driver, the OpenBSD `qlw` driver and the
NetBSD `isp` driver. The SCSI-2 timing values come from the public copy of ANSI X3.131-1994.

No source states a reset value for any register. Every reset value is unknown.

## Identity and revision

- Device `0x1020` is shared with the ISP1020 family. The Linux driver's ISP1040 test matches that
  device ID, and OpenBSD's PCI attach matches it for the whole family.
- OpenBSD's PCI attach maps the PCI revision ID to the variant: 0 and 1 are the ISP1020 and 1020A,
  2 the ISP1040, 3 the 1040A, 4 the 1040B, and 5 or more the 1040C. It sets the clock to 60 MHz from
  revision 2 up, and gives the chip one bus.
- The `hinv` label "QL1040B (rev. 2)" cannot be the PCI revision if that table is right, because
  revision 2 is the plain ISP1040 there. The "rev. 2" is a version name. This is inferred from the
  OpenBSD table, which is the only public source held for the mapping.
- Linux reads the hardware revision field of configuration register 0 only to decide the FIFO
  threshold for the 1040A. It does not use the field to name the part.

## Bus interface

The eight 16-bit registers at `0x00` to `0x0e` are identity, configuration 0 and 1, bus interface
control, interface status, semaphore and NVRAM. Mailboxes 0 to 7 sit at `0x70` to `0x7e`, and mailbox
0 carries the opcode of each command.

The flash BIOS data and address words at `0x10` and `0x12` are named by Linux and OpenBSD. The NetBSD
driver gives the same offsets to request-queue pointers for a later chip. The naming therefore rests on
two drivers that agree, not on a manual, and the entry says so.

Bus interface control (`0x08`) holds the soft reset bit, which the driver sets and then polls until it
clears, the interrupt enable and RISC interrupt enable bits, and the flash BIOS enable and upper bank
select bits. The flash bits are named by Linux alone.

## Mailbox commands

Operands are per opcode. Grades are in the generated page.

- `0x31` sets the selection timeout. Mailbox 1 carries bus 0's value and mailbox 2 bus 1's. A one-bus
  part needs mailbox 1 only.
- `0x32` sets the retry count and delay. Mailbox 1 and 2 carry bus 0's pair and mailboxes 6 and 7 bus
  1's. NetBSD sets the count to zero so that selection failures reach the driver at once, which
  implies that a non-zero count makes the firmware retry on its own. How many attempts a count gives is
  unknown.
- `0x18` resets a bus. Mailbox 1 carries a delay and mailbox 2 the bus. Linux and OpenBSD sleep for the
  delay after the reset completes, so the unit is taken as seconds. NetBSD raises any delay below two to
  two. Whether the firmware holds bus activity for that time is inferred from the drivers waiting it out
  before they issue commands. No firmware document states it.
- `0x28` reads a target's negotiated parameters. Linux packs the target into the high byte of mailbox 1
  and sets bit 7 for bus 1. NetBSD's output mask names mailboxes 0 to 3 and 6 as results. The meaning of
  each result mailbox is inferred from the set-target layout.
- `0x38` sets target parameters. `0x3a` sets the reset-delay parameters; no source here states its
  operands.
- `0x09` and `0x0a` load and dump RAM with 64-bit DMA addresses. Linux selects them in builds that use
  64-bit DMA addresses.

The selection-timeout unit is inferred to be milliseconds. No driver states it. All three drivers default
the value to 250, which is the SCSI-2 recommended selection time-out delay, and the SCSI-2 timing is in
milliseconds. The drivers use 250 when the NVRAM is not valid. Every driver programs the value, so no
source shows what the chip does when it is never programmed.

## Completions and events

- A status entry keeps its completion status at offset `0x0a`, state flags at `0x0c`, status flags at
  `0x0e` and sense length at `0x12`. The entry header is four bytes. Linux and OpenBSD agree on these
  offsets.
- Completion `0x0001` is incomplete. Completion `0x0004` is a reset: a bus reset destroyed the command.
  The drivers treat it as a destroyed command. Whether the firmware sends it for a command that had not
  yet been selected is inferred, not stated.
- State flags: got-bus `0x0100`, got-target `0x0200`, got-sense `0x2000`. The got-sense bit is named by
  two drivers, and the conditions that set it are not stated.
- A command to an absent target completes incomplete with got-bus set and got-target clear. Linux then
  reports `DID_BAD_TARGET` and NetBSD reports a selection timeout. Status flag `0x0040` is named only by
  the NetBSD header, and that driver reads it for a transport error, not for a missing target. Whether
  the firmware sets it for an absent target is not established.
- Asynchronous event `0x8001` reports a bus reset. Linux reads the bus number from bit 0 of mailbox 6.
  Whether the firmware posts this event for a reset the host requested is unknown.

## Timing context

The SCSI-2 standard, ANSI X3.131-1994, recommends 250 ms from a hard reset until a target can answer
selection. Its selection time-out delay is also 250 ms: a device should wait that long for a BSY
response before it starts the time-out procedure. The selection abort time is 200 microseconds. These
are recommendations for targets and initiators. The ISP1040's selection timeout and bus-reset delay are
the driver's requests, and this page does not treat them as measured chip behaviour.

## Not known

- The reset value of every register.
- Whether the firmware retries a selection by itself under a non-zero retry count, and how many attempts
  a count gives.
- The unit of the bus-reset delay (inferred seconds) and whether the firmware holds bus activity for it.
- The chip's selection timeout when it is never programmed.
- The operands of the reset-delay opcode `0x3a`.
- The chip's own bus order for DMA. The byte-lane rules for the host side belong with the Bridge pages.
- Interrupt sources and status bits, and the request and response queue layout.
