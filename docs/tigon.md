# Tigon Ethernet controller: PCI data width

The Alteon Tigon/PCI is the Ethernet controller on SGI's IRIS Gigabit Ethernet board. This page holds
its PCI data-width rules, the bus-width flag in its PCI State register, the board's bus capability,
and what is unknown. It holds no register contract. The PCI State register is named here, but the
sources do not give its offset, so there is no `defs/` unit yet.

Each fact carries a label as in the rest of this repository. **Established** means a published
manual or specification states it, with the citation. **Inferred** means reasoned from established
facts. **Unknown** means not settled, with the route that would settle it.

## Sources

- **Tigon/PCI Ethernet Controller**, Alteon Networks, revision 1.04, part 020016, August 1997. Cited
  as `Alteon p. N` by printed page. Its PDF page numbers match the printed pages for the cited pages.
- **SGI IRIS Gigabit Ethernet Board User's Guide**, 007-3819-004. Cited as `007-3819-004 p. N` by
  printed page. The page numbers for the board facts below are the ones the source citation gives for
  the group.

Neither source carries a confidentiality marking.

## Data width on the bus

- **Established.** Tigon is a 32- or 64-bit conventional PCI interface. The host and the card use a
  protocol to determine which width the host supports (Alteon p. 17).
- **Established.** 64-bit data operations are limited to PCI memory commands. I/O and configuration
  commands stay narrow (Alteon p. 17). This concerns the data phase only.
- **Established.** Tigon can generate 64-bit addresses as a bus master, using dual address cycles,
  but its own memory aperture must lie below 4 GiB (Alteon p. 17). Address width does not set the
  data-phase width.

## PCI State bit 20

For Tigon revision 5 and later:

- **Established.** Bit 20 of the PCI State register is named "32-bit PCI bus". A one means a 32-bit
  bus. A zero means a 64-bit bus (Alteon p. 77, Table 31).
- **Established.** Software that sets the bit forces 32-bit PCI operation, even when the host
  indicated 64-bit operation. The manual warns that setting it on a true 64-bit bus causes PCI
  problems (Alteon p. 77).
- **Established.** All PCI State bits are zero during reset. The Miscellaneous Host Control reset
  function does not change this register (Alteon p. 77).
- **Unknown.** The manual does not say when after reset the host-selected width appears in bit 20.
  A read taken after firmware has run does not show the reset-time value. The settling route is a
  revision-specific manual that defines the point, or a capture that names the reset sequence it
  follows.

## SGI IRIS Gigabit Ethernet board

- **Established.** The fiber and copper boards each have a 32/64-bit, 33/66 MHz PCI interface
  (007-3819-004 pp. 1, 2, 4, 27).
- **Established.** The board's specification table lists PCI data and address as 32 and 64 bits
  (007-3819-004 pp. 1, 2, 4, 27). These are capabilities of the board. They do not give the width
  used in a given slot.
- **Established.** The same table gives a 132 MB/s PCI data burst rate, with a 66 MHz maximum clock
  and 64-bit capability (007-3819-004 pp. 1, 2, 4, 27). The rate is a board specification. It is not
  a measure of the bus width.
- **Established.** The guide lists Origin 300 among the systems the board supports
  (007-3819-004 pp. 1, 2, 4, 27).

## Origin 300 slot

Whether an installed Origin 300 expansion slot supplies the host indication for 64-bit data phases is
**unknown**. The bus-level evidence for the expansion module, and the open question of which slots
wire REQ64# and ACK64#, are on
[origin300-pci-expansion-module.md](origin300-pci-expansion-module.md#pci-data-width).

## Unknown

| Open item | Evidence that would settle it |
|---|---|
| When after reset bit 20 shows the host-selected width | A manual revision that defines the point, or a capture with a stated reset sequence |
| The PCI State register offset in the Tigon register map | The register map of a Tigon manual revision. The offset is not in the sources used here |
| Which Origin 300 slots supply the 64-bit host indication | A board wiring document, or a physical transaction capture |

These items are also listed in [open-questions.md](open-questions.md).
