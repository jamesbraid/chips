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
Tried: the routine in full; no other HAL code touches them. Settles it: the firmware's use of the same ports (a search of the held
PROM images for those port numbers was not done), or the Lithium and PIIX4 specifications.

## PIIX4 general-purpose input and output register offsets

[missing source] The PIIX4 datasheet is not held, so the offsets `0x30` and `0x34` of the power-management block (hence the meaning
of ports `0xfb0`, `0xfb2`, `0xfb5`) rest on the datasheet from memory and are inferred. Which pins carry the board-type bits 5:2
of `0xfb2` and what its other bits carry is unknown. Settles it: the PIIX4 datasheet (a search of the reference holdings found nothing).

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

## Newer HAL builds and the Windows 2000 HAL

[missing binary extraction] The patches SG0020002 (28 April 1999) and SG0020021 (28 July 1999) replace the HAL with later builds;
they are held as InstallShield packages and were not unpacked, so differences in the hot path are unknown. The Windows 2000 HAL
below its tables was not read. Settles it: unpack the packages, apply the symbols they carry, compare by symbol as for the
1.3 builds.
