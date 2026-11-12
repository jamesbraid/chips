# MENET: the four-port Fast Ethernet and asynchronous serial XIO board

The MENET (part 030-0873) is an XIO board for the Origin 2000 and Onyx2. It carries one Bridge and four IOC3s
on the Bridge's PCI bus: four Ethernet interfaces and six asynchronous serial ports. The PROM types it as board
type `0x23`, the Ethernet type, which the [Crosstown page](crosstown-ktown.md) lists with the other classifier
prefixes. The Bridge and IOC3 contracts are on [the Bridge page](../chips/bridge/README.md) and
[the IOC3 page](../chips/ioc3/README.md). This page holds the board's composition, the IRIX words it sets, its
interrupt wiring and its identity record.

Status: draft, imported from published sources. The IRIX routine facts come from a disassembly the source
record cites. This checkout has no IRIX tree, so those routines were not re-read here. Re-read them before
relying on them.

Grades follow [AGENTS.md](../AGENTS.md): **established** means the manual, a real listing or a routine read in
full states it; **inferred** means a reasoned reading, including what a public driver expects; **unknown** means
no held source settles it.

## Composition

| Property | Grade | Evidence |
|---|---|---|
| One XIO board: a Bridge and four IOC3s on the board's PCI bus, 128 KB of SRAM per Ethernet path | established | 108-0151-001 pages 1-6 and 1-7, component figure and block diagram |
| IOC3s at PCI devices 0, 1, 2 and 3, each vendor `0x10a9`, device `0x0003` | established | real `hinv -v` listings: an Origin 2000 under IRIX 6.5.4m with one board, and an owner's Origin 2000 under IRIX 6.5 with two boards (both at devices 0 to 3); an Octane listing with `ef1` to `ef4` at PCI 0 to 3 |
| IOC3s at devices 0 to 2 each drive a serial transceiver with two ports and a 10/100 transceiver; device 3 drives only a 10/100 transceiver | established | 108-0151-001 Figure 1-5, page 1-7 |
| Four RJ-45 Ethernet ports, labelled ef0 to ef3, and six mini-DIN8 serial ports, labelled tty_1 to tty_6 | established | 108-0151-001 pages 1-9 to 1-11 |
| Each Ethernet port has a socketed NIC that holds its MAC address | established | 108-0151-001 Figure 1-4 callout, page 1-6 |
| A MENET adds six serial ports and four Ethernet interfaces to IRIX's inventory | established | 6.5.4m listing: `tty1` to `tty8` with one BaseIO and one MENET; owner's listing: `tty1` to `tty14` with one BaseIO and two MENETs |
| No clock, keyboard, mouse or parallel port | established | the IRIX words below have bits 3, 6 and 7 clear; the manual lists no such connector |
| Fits any XIO slot; the manual recommends odd slots before even, and low before high | established | 108-0151-001 pages 2-4 and 2-5 |
| Interface numbering follows `ioconfig`; `ef0` stays on the master BaseIO | established | 108-0151-001 page 2-2; the owner's listing numbers the two boards' ports non-sequentially |

## IRIX enable words and interrupts

The IRIX 6.5.30 IP27 kernel routine `menet_vmc` is the Bridge-record callback for the prefix `030-0873-`. It
sets the subdevice word for each IOC3 and declares a second slot for each of devices 0 to 3. The word's bits are
the ones the [IOC3 page](../chips/ioc3/README.md) and the [BaseIO page](baseio.md#subdevice-enable-word-irix)
list: bit 0 Ethernet, bit 3 keyboard and mouse, bits 4 and 5 serial A and B.

| PCI device | Word | Functions | Second slot (SuperIO interrupt) | Grade |
|---|---|---|---|---|
| 0 | `0x31` | Ethernet, serial A and B | slot 4 | established (word and slot, from `menet_vmc`) |
| 1 | `0x31` | Ethernet, serial A and B | slot 5 | established |
| 2 | `0x31` | Ethernet, serial A and B | slot 6 | established |
| 3 | `0x01` | Ethernet only | slot 7 declared, but no SuperIO interrupt is needed | established (word); inferred (no interrupt) |

The interrupt rows follow from the table.

- The SuperIO interrupt of device `d` (0 to 2) reaches Bridge pin `d + 4`. **Inferred.** IRIX declares slots 4 to 7
  as the second slots of devices 0 to 3, and it takes a dual-slot chip's second interrupt from that slot's line.
  Linux's default mapping, `slot ^ 4`, gives the same pins for all four devices. No capture shows a MENET interrupt
  register.
- Device 3 raises no SuperIO interrupt. **Inferred.** `ioc3_intb_needed` returns true only when the word has a bit
  set in `0xfa`, and `0x01` has none. The rule that line B reaches pin `slot ^ 4` is established for IRIX's
  `pcibr_intr_bits` in [the IP35 IO9 note](questions/ip35-io9-pci-wiring.md).
- Each IOC3's Ethernet interrupt uses its own line A, Bridge pin `d`. **Inferred**, from the Bridge's ordinary
  per-slot rule.

The manual's serial test example names `.../menet/pci/4`. Under the second-slot rule above, device 0's serial
functions hang on `pci/4`, so the example and the device numbers agree. No real listing shows the serial vertices.
**Inferred.**

## Board identity

| Property | Grade | Evidence |
|---|---|---|
| The board's one-wire record names `MENET`, part `030-0873-003`, with board revisions `C` and `J` seen | established | owner's `hinv -vm` on an Origin 2000: `MENET Board: ... part 030-0873-003 rev J` at `/hw/module/1/slot/io8/menet`, and `rev C` at io7 |
| Part `030-0873-004`, rev A, also seen | established | an Onyx2 deskside `hinv -m` (comp.sys.sgi.hardware, 5 June 2004) |
| The record prints at the board's slot location, not under a `pci/N` vertex | established | the owner's listing above; a Cad Duo record prints under its PCI vertex (see [the Cad Duo page](cad-duo-pci-card.md)) |
| The record uses the 64-byte, two-page layout described on [the BaseIO page](baseio.md#board-identity-on-the-bridge-one-wire-bus) | inferred | layout inherited from the BaseIO records; not checked byte by byte for this board |
| The PROM types the board `0x23` (`KLTYPE_MENET`) | established | [the Crosstown page](crosstown-ktown.md#prom-classification-of-the-origin-200-crosstown-board), prefix `030-0873-` |
| `hinv` prints `Origin MENET board, module N slot M: Revision R`, with R 3 or 4 on three real boards | established | 6.5.4m listing (slot 6, revision 3); owner's listings (slot 7, revision 3; slot 8, revision 4) |
| The hardware-graph slot name is `menet` | established | owner's `Location:` lines; the manual's example path `/hw/module/1/slot/io9/menet/...` |

## Other software's view

- **Linux** takes each chip's subsystem identity from the Bridge record, as `0xc305` for devices 0 to 2 and `0xc306`
  for device 3. The subsystem list is on [the IOC3 page](../chips/ioc3/README.md). **Inferred**, from the driver.
  The value the chip itself returns at configuration offset `0x2c` is **unknown**.
- **OpenBSD** looks for a DS2505-family record on each IOC3's own one-wire bus and tests it for `030-0873-`. **Inferred**
  for the driver's behaviour. Whether a real MENET carries such a record on its IOC3 buses is **unknown**. IRIX never
  reads those buses for a MENET chip, and no real listing shows a per-chip record.

## Unknown

- Whether each IOC3 on a MENET carries its own one-wire record, as the OpenBSD test assumes. A dmesg from a real
  MENET under OpenBSD, or a one-wire search of the board, would settle it.
- The configuration-space subsystem value a real IOC3 returns on a MENET. A read-only configuration read on a real
  board would settle it.
- Whether the `0x31` and `0x01` words hold for every board revision. Three boards are documented.

## Sources

- SGI 108-0151-001, *IRIS 4-Port Fast Ethernet Adapter with Asynchronous Serial XIO Board Installation Instructions*,
  pages 1-6 to 1-12 and 2-2 to 2-5.
- Real listings: an owner's `hinv -vm` on an Origin 2000 under IRIX 6.5 with two boards (a public owner's page);
  an Origin 2000 `hinv -v` under IRIX 6.5.4m with one board (comp.sys.sgi.admin, 23 August 1999); an Onyx2 deskside
  `hinv -m` (comp.sys.sgi.hardware, 5 June 2004); an Octane `hinv` with a MENET (comp.sys.sgi.hardware, 16 October
  2006); an SGI engineer's statement that GIGAchannel XIO slots take MENET boards (comp.sys.sgi.admin, 18 June 2001).
- IRIX 6.5.30 IP27 kernel: `menet_vmc`, `ioc3_attach` and `ioc3_intb_needed`, as the [IOC3 page](../chips/ioc3/README.md)
  and [the Bridge page](../chips/bridge/README.md) record them. Re-read before relying on it.
- Linux `arch/mips/pci/pci-xtalk-bridge.c` and `drivers/mfd/ioc3.c`; OpenBSD `sys/arch/sgi/pci/ioc.c`. Software
  expectations only.
