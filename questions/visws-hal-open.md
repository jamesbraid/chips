# SGI Visual Workstation 320 and 540: open points from the HAL follow-on reading

From [hal-hot-path.md](../software/visws/hal-hot-path.md), [boards-320-540](../platforms/visws/boards-320-540.md) and the
[Cobalt page](../devices/cobalt/README.md). Each entry: question, routes tried, what would settle it.

## Does Cobalt track an in-service state for a level line, and does the local APIC's EOI reach it

[missing source] The HAL never writes the controller when it acknowledges a device interrupt, and for the 8259 cascade it relies on
the level line re-delivering while another IRQ is pending (inferred). Tried: every acknowledge routine in both HAL builds. Settles it:
a trace of a real machine with two simultaneous legacy interrupts, or the Cobalt specification. PROM 1.1005 was also read: it never touches any acknowledge or in-service state ([nt-hal.md](../software/visws/nt-hal.md#what-the-prom-11005-trace-says-about-the-hals-open-points)).

## Meaning of bit 17 of an interrupt entry's low word, and of the remote-IRR bit's writability

[missing source] The HAL aborts NMI set-up if bit 17 reads set after it writes 0, and clears bit 14 of the NMI entry by writing it.
Tried: both HAL builds and PROM 1.1005, which writes entry 29's low word once as all ones (bit 17 included) and never reads it back. Settles it: the specification, or reads of the entry on a real machine.

## What raises Cobalt entry 29 and what ports `0xff0` to `0xff3` are

[missing source] The power-management NMI routine reads bit 2 of port `0xfb0` and writes ports `0xff0` to `0xff3` with fixed values.
Tried: the routine in full; no other HAL code touches them. The PROM never reads `0xfb0`; its only use of `0xff0` is a `0xcafe` word write in a power-off path no board reaches (see the PROM note linked from the first entry above), so the PROM does not settle what raises the NMI. The PIIX4 datasheet lists no such ports, and its power-management
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
real 540 with cards in known slots; the board silkscreen. PROM 1.1005's scan prints bus, device (as "slot") and function but has no slot table, and no PROM driver or node is bound to device 2 of either bridge, so the 540's device 2 stays unknown too.

## Physical layout of the generation-1 boards

[missing source] Generation 1 (320 below revision 6, 540 revision 0) wires five full rows on bridge A, which does not fit the
production 540's two-slot bus. Whether such 540s existed with a different slot layout is unknown. Settles it: a revision 0 board's
owner's guide or a boot log.

## Which local APIC id the bootstrap processor has

[settled for PROM 1.1005, not for a real 540's reset value] Every device interrupt goes to processor id 0. The PROM 1.1005 routine that
runs on every processor takes an ordinal from the byte at `0x504` and writes it into the local APIC ID register, the boot processor
being ordinal 0, before it records the entry ([boot-path.md](../software/visws/boot-path.md#processor-wake-up-and-the-local-apic-identifiers-0x1103c80-0x1103f74)),
so the boot processor's id is 0 on a machine running that firmware (established; that the write takes effect on the part is inferred).
What a real 540 holds at reset is not shown and no longer matters for 1.1005. Older PROMs were not re-read.

## Which board the fourth Windows 2000 interrupt generation is for

[partly settled] The PROM's board type has four values (`320`, `540`, `330`, `530`) and the Windows 2000 HAL selects its fourth table set for
every SYS TYPE other than 0 and 1, so the new set serves the 330 and 530 boards (inferred; [nt-hal.md](../software/visws/nt-hal.md#what-the-prom-11005-trace-says-about-the-hals-open-points)).
Open: what a 330 or 530 is (no held guide names them) and the Windows 2000 selection code. Settles it: decoding the RTM routine that loads the tables, or a guide for those boards.

## Uniprocessor builds of the newer HALs and the Windows 2000 HAL

[missing binary extraction for the uniprocessor builds] The multiprocessor builds of patches SG0020002 and SG0020021 were compared
with 1.3 (same hot path and tables; see [nt-hal.md](../software/visws/nt-hal.md#follow-on-corrections-and-additions)); their
uniprocessor builds were not. The Windows 2000 tables are now compared byte for byte in RTM and SP4
([subsection](../software/visws/nt-hal.md#windows-2000-hal-tables)): the two images agree, and Windows 2000 has one more vector
table, one more pin set and two more ISA tables than NT 4.0. Still open: which table each SYS TYPE and `INTRROUTE` value selects
(the RTM selection code is not decoded), and the Windows 2000 code below the tables, which has no symbols. Settles it: decoding the
RTM routine that loads the tables (its absolute references are listed in the subsection), and comparing the uniprocessor patch
builds with 1.3.
