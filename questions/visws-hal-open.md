# SGI Visual Workstation 320 and 540: open points from the HAL follow-on reading

From [hal-hot-path.md](../software/visws/hal-hot-path.md), [boards-320-540](../platforms/visws/boards-320-540.md) and the
[Cobalt page](../devices/cobalt/README.md). Each entry: question, routes tried, what would settle it.

## Does Cobalt track an in-service state for a level line, and does the local APIC's EOI reach it

[missing source] The HAL never writes the controller when it acknowledges a device interrupt, and for the 8259 cascade it relies on
the level line re-delivering while another IRQ is pending (inferred). Tried: every acknowledge routine in both HAL builds. Settles it:
a trace of a real machine with two simultaneous legacy interrupts, or the Cobalt specification.

## Meaning of bit 17 of an interrupt entry's low word, and of the remote-IRR bit's writability

[missing source] The HAL aborts NMI set-up if bit 17 reads set after it writes 0, and clears bit 14 of the NMI entry by writing it.
Tried: both HAL builds. Settles it: the specification, or reads of the entry on a real machine.

## What raises Cobalt entry 29 and what ports `0xff0` to `0xff3` are

[missing source] The power-management NMI routine reads bit 2 of port `0xfb0` and writes ports `0xff0` to `0xff3` with fixed values.
Tried: the routine in full; no other HAL code touches them. The PIIX4 datasheet lists no such ports, and its power-management
block is the 64-byte window at `0xf80` (base in PMBA bits 15:6, p. 120), so they are not its registers (inferred). Settles it: the
firmware's use of the same ports (a search of the held PROM images for those port numbers was not done), or the Lithium specification.

## Which pins carry the board-type bits of port `0xfb2`

[missing schematic] The PIIX4 datasheet is now held and settles the register layout: GPIREG at `+0x30` and GPOREG at `+0x34`, bits
5:2 of `0xfb2` are GPI18 to GPI21 (non-multiplexed), and `0xfb5` bit 0 is GPO8 ([boards-320-540.md](../platforms/visws/boards-320-540.md#the-byte-at-port-0xfb2)).
Which pins SGI wired to carry the board type, and what bits 1:0 and 7:6 carry, is unknown: the datasheet gives pin functions, not
board wiring. Settles it: the board schematic, or a strap measurement of GPI18 to GPI21 on a real machine (a last resort, and only
with the owner's approval).

## Which physical PCI slot is which device number

[missing source] The guides number slots 1 to 4 and 5 and 6 by group only. Settles it: a boot log or Device Manager listing from a
real 540 with cards in known slots; the board silkscreen.

## Physical layout of the generation-1 boards

[missing source] Generation 1 (320 below revision 6, 540 revision 0) wires five full rows on bridge A, which does not fit the
production 540's two-slot bus. Whether such 540s existed with a different slot layout is unknown. Settles it: a revision 0 board's
owner's guide or a boot log.

## Which local APIC id the bootstrap processor has

[missing source] Every device interrupt goes to processor id 0. The firmware's table at `0x1e00` says which ids exist; whether the
bootstrap entry always carries 0 on a 540 with four processors is not shown. Settles it: a dump of the table from a real machine or a
read of the firmware routine that writes it ([boot-path.md](../software/visws/boot-path.md), not edited here).

## Uniprocessor builds of the newer HALs and the Windows 2000 HAL

[missing binary extraction for the uniprocessor builds] The multiprocessor builds of patches SG0020002 and SG0020021 were compared
with 1.3 (same hot path and tables; see [nt-hal.md](../software/visws/nt-hal.md#follow-on-corrections-and-additions)); their
uniprocessor builds were not. The Windows 2000 tables are now compared byte for byte in RTM and SP4
([subsection](../software/visws/nt-hal.md#windows-2000-hal-tables)): the two images agree, and Windows 2000 has one more vector
table, one more pin set and two more ISA tables than NT 4.0. Still open: which table each SYS TYPE and `INTRROUTE` value selects
(the RTM selection code is not decoded), and the Windows 2000 code below the tables, which has no symbols. Settles it: decoding the
RTM routine that loads the tables (its absolute references are listed in the subsection), and comparing the uniprocessor patch
builds with 1.3.
