# Cad Duo PCI card (030-1155-002)

The Cad Duo is an SGI option board, part 030-1155-002. It is a PCI card with its own IOC3, which gives it one Ethernet
interface and one PS/2 keyboard and mouse pair, and no serial ports. The chip's side of the card is on the
[IOC3 page](../ioc3/README.md): the `CAD DUO` population, the `030-1155-` callback that sets subdevice mask
`0x09`, and the absence of serial ports are all established there from IRIX and the public drivers. This page holds
what that page does not.

Grades: **established** means a capture or a published specification states the fact. **Inferred** means a software
expectation (IRIX or a public driver) or arithmetic on one. **Unknown** means no source here settles it.

## Identity and board record

- **Established.** A real card reports the board name `PCI_ENET`, part `030-1155-002`, revision `D`. An owner's
  `hinv -vm` listing from an Origin 2000 prints it at `/hw/module/1/slot/io3/xtalk_pci/pci/1`, which is PCI device 1
  behind a crosstalk-to-PCI adapter, and lists the card's Ethernet interface on the same slot. Source: the owner's
  listing on the mimgfx Origin 2000 page (formerly mimgfx.homeunix.net). The barcode on that listing names one unit
  and is not recorded here.
- **Inferred.** The card's IOC3 one-wire bus holds two parts: the station-address part, family code `0x91`, which
  IRIX skips when it formats the board line, and the board record, family `0x0b` or `0x09`. IRIX formats a record only
  from those two families. The family is inferred, not captured. The reader for a family `0x0b` part is described in
  [the one-wire NIC note](../../questions/v12-nic.md), and the 64-byte record layout is the one in
  [the BaseIO page](../baseio/README.md#board-identity-on-the-bridge-one-wire-bus). The note's reading comes from the IP30 and
  IP35 builds, not the IP27 build this card's IOC3 uses, which was not compared line by line.
- **Unknown.** Whether the card carries exactly these two parts. An IRIX `hinv -mvvv` listing or a one-wire search on
  a real card would settle it.

## Interrupts

- **Inferred.** The card's keyboard and mouse interrupt leaves the card on PCI pin INTB. OpenBSD's IOC3 driver takes
  an add-in IOC3's SuperIO interrupt from INTB and an on-board IOC3's from INTD. That fits the BaseIO page, which puts
  the system-board IOC3's SuperIO sources on pin D. Source: OpenBSD `sys/arch/sgi/pci/ioc.c` at `2df91d80c104`, a
  software expectation. The file was not re-read for this page.
- **Derived from an established routine.** IRIX's `ioc3_intb_needed` returns 1 for any subdevice mask with a bit
  outside bits 0 and 2 (see the IOC3 page). Mask `0x09` has bit 3 set, so IRIX asks for the second interrupt line.
- **Unknown.** Which Bridge input a card's INTB reaches. Software that treats INTB as Bridge input `slot ^ 4` is
  described in [the IP35 IO9 note](../../questions/ip35-io9-pci-wiring.md), and that rule is a software convention, not board
  wiring. No capture of a Cad Duo in an option slot shows the wiring.

## Unknown

- The card's PCI subsystem ID. No capture of one was found, so the IOC3 page's population table covers it only by
  name.
- Whether a real PROM prints the card's board record. No PROM listing or capture that names a Cad Duo part is cited
  here.
- The card's physical connectors, silkscreen and bill of materials.
