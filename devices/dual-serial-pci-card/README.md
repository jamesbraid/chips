# Dual-serial PCI card (030-1657)

SGI's dual-serial PCI card carries one IOC3 wired for serial ports A and B and nothing else. It is the PCI
counterpart of the serial pair on the [BaseIO](../baseio/README.md), with no Ethernet, keyboard or clock. The
[IOC3 page](../ioc3/README.md) holds the routines that set its subdevice word and choose its interrupt line.
This page holds the rest.

Status: draft, imported from published sources, then re-checked in a verification pass. In the IP27 `ioc3.o`,
`pci_ioc3_sio_vmc` calls `ioc3_subdev_enables` with `0x30`, `ioc3_init` registers it through `nic_vmc_add` for the strings
`030-1657-` and `030-1664-`, and `ioc3_intb_needed` returns true only when the enable word has a bit in `0xfa`. OpenBSD's
`ioc.c` entry (lines 235 to 240) matches. The PROM routines at `0x1fc3f410`, `0x1fc41e5c`, `0x1fc374bc`, `0x1fc27bdc`,
`0x1fc27ae0` and `0x1fc3f1a8` and the line-B reading in `ioc3_attach` were not re-read, so their rows are unverified.

Grades follow [AGENTS.md](../../AGENTS.md): **established** means a routine read in full, a manual, a real listing or
a stock list states the fact; **inferred** means a reasoned reading or a public driver's expectation; **unknown**
means no held source settles it.

## Facts

| Fact | Grade | Evidence |
|---|---|---|
| IRIX enables serial A and B and nothing else: subdevice word `0x30` for prefixes `030-1657-` and `030-1664-` | established | `pci_ioc3_sio_vmc`, registered by `ioc3_init` in IRIX 6.5.30 IP27 `ioc3.o`; see [the IOC3 page](../ioc3/README.md) |
| OpenBSD enables the same two ports for the same prefixes | inferred | OpenBSD `sys/arch/sgi/pci/ioc.c` entry for `030-1657-` and `030-1664-`; a public driver's expectation |
| The interrupt line is B (line 2) of the card's slot when the chip has no Ethernet and its own record holds either prefix. Any other chip without Ethernet takes line A | established | `ioc3_attach`; the rule is stated on [the IOC3 page](../ioc3/README.md) |
| Line B reaches Bridge pin `slot ^ 4` | established for IRIX's `pcibr_intr_bits`, as [the IP35 IO9 note](../../questions/ip35-io9-pci-wiring.md) records. The card's own wiring is unknown | the Bridge's line-B rule |
| The PROM recognises the card by its prefix alone. Its record is found by a substring search of the formatted record text | established | the PROM routine at image address `0x1fc3f410`, which enables the chip's one-wire port, reads its record and searches it for either prefix (the search itself is at `0x1fc41e5c`) |
| The PROM never picks the card as its console IOC3 | established | the console-IOC3 search at `0x1fc374bc` skips the card's set-up path at `0x1fc27bdc`. Another caller skips the IOC3 set-up at `0x1fc27ae0`, and a third leaves the chip out of the IOC3 components it builds at `0x1fc3f1a8` |
| The assembly exists: `030-1657-003`, "SERIAL I/O CARD (UFC), PCI" | established that the assembly exists, not that a guest has used one | a stock list (comp.sys.sgi.marketplace, 26 January 2004) |
| The record name is `PCI_SIO_UFC` | inferred candidate | OpenBSD's comment on the entry calls the board "PCI_SIO_UFC dual serial board". No capture prints the record |
| The record sits on the card's own IOC3 one-wire bus | established | `ioc3_attach` reads the chip's own record unless the hardware-graph path names `baseio` or `menet`. IRIX and OpenBSD both find the prefix there |

Nothing IRIX-visible depends on the unknowns. IRIX and the PROM match the prefix anywhere in the record text, so the
dash number, revision and name reach only the text that `hinv -mv` prints.

## Unknown

- The record's revision. The stock list gives none, and IRIX matches the prefix whatever it is.
- The PCI subsystem ID.
- Whether the card carries any part besides the one-wire record. A one-wire search on a real card would settle it.
- The physical connectors and the card's wiring from the IOC3 to its two connectors. A photograph of a real card
  would settle the connectors. The line B wiring needs a continuity check on a real card.
- Whether a real guest prints the card's record. A `hinv -mv` listing from a system with the card would settle it.

## Sources

- IRIX 6.5.30 IP27 kernel, `ioc3.o`: `ioc3_init`, `pci_ioc3_sio_vmc`, `ioc3_attach` and `ioc3_intb_needed`. Read as
  the [IOC3 page](../ioc3/README.md) records them.
- IP27 PROM payload shipped with IRIX 6.5.30: the one-wire record routine and its three callers.
- Stock list: comp.sys.sgi.marketplace, 26 January 2004, part 030-1657-003.
- OpenBSD `sys/arch/sgi/pci/ioc.c`, a public driver. Software expectation only.
