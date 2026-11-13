# Tigon Ethernet controller: PCI data width

The Alteon Tigon/PCI is the Ethernet controller on SGI's IRIS Gigabit Ethernet board. This page holds
its PCI data-width rules, the bus-width flag in its PCI State register, the byte-swap rules of its
host DMA channels, the board's bus capability, and what is unknown. The register offsets and bit
fields are in the generated contract, [devices/tigon/registers.md](../devices/tigon/registers.md), from `devices/tigon/registers.toml`.

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

## Byte swapping and DMA

- **Established.** All data going to or from the PCI bus, except the configuration registers, can be
  swapped in groups of four or eight bytes. The swap is selectable separately for each of the two DMA
  channels and for host target accesses (Alteon p. 22, section 2.10.2).
- **Established.** Each DMA channel normally swaps its data in groups of four bytes. A per-operation
  No Swap bit in the channel's state register turns that off. The read channel's state is at offset
  0x0b0 (section 9.6.3, printed p. 82) and the write channel's is at 0x0a0 (section 9.6.4, printed p. 84).
  Word swapping is normally left enabled and is turned off in PCI State bit 18 (sections 9.6.3 and 9.6.4).
- **Established.** Bit 18 of PCI State disables word swapping for all DMA transactions. Before Tigon
  revision 5 it affected only the read channel (Alteon p. 77, Table 31).
- **Established.** Before Tigon revision 5, PCI State bit 19 behaved like bit 18 for the write DMA
  channel only. From revision 5 it reads the bus speed: one for 33 to 66 MHz, zero for 33 MHz or less
  (Alteon p. 77, Table 31). Public drivers name bit 19 as a no-swap bit and as a 66 MHz bit. The manual
  defines it as the second, and records the no-swap meaning only for revisions before 5.
- **Established.** PCI State bits 31 to 28 and 27 to 24 are the default write and read commands. The
  manual says they should normally be initialized to seven and six (Alteon p. 77). Bit 17 selects
  Memory Read Multiple in place of Memory Read Line for DMA reads.
- **Established.** The DMA maximum fields (PCI State bits 7 to 5 for writes, 4 to 2 for reads) use the
  same encodings: disable, 4 or 8, 16, 32, 64, 128, 256 and 1k. Encoding five is 128 bytes (Alteon p. 77).
- **Established.** Writing PCI State bit 20 from revision 5 forces 32-bit PCI operation, as in the
  bus-width section above. The manual says every PCI State bit is zero at reset and that the Miscellaneous
  Host Control reset leaves the register alone (Alteon p. 77).

## Host mailboxes

- **Established.** The mailbox area is 256 bytes at 0x500 to 0x5ff, holding 32 eight-byte locations
  (Alteon p. 62, Table 19; section 2.7, printed pp. 20 to 21). A write to the upper half of a location
  raises an event to the internal processor, naming the location. Each location has its own event bit.
- **Established.** Mailbox 0 is special. Writing it deasserts the PCI interrupt pin at once, so a host can
  clear the interrupt and pass a message in one write. Software need not use it if it does not need that.
- **Established.** The Miscellaneous Host Control register has a read-only interrupt-state bit that reflects
  the PCI IntA pin, and a write-only bit that clears the interrupt. Its gate-array field reads three, four or
  five for the Chip Express, LSI gate array and LSI standard cell releases. The field does not number the
  Tigon revision (Alteon p. 73, Table 28).

## What the manual leaves to other documents

- **Unknown.** The host-side descriptor layout is a software and firmware convention. The manual points to a
  separate Host/NIC software interface definition for it (Alteon p. 21). That document is not held here.
- **Unknown.** The manual does not define the firmware's command and event set, its statistics block, or the
  firmware mode word that holds the descriptor word-swap and jumbo-fragmentation bits. The public driver
  headers name a few of these, but nothing here checks them against the card.
- **Unknown.** Which revision the board's card is. The manual records a second processor first in revision
  5, with revision 6 as the Tigon II, but does not say which revision is on the board.

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
| Which Origin 300 slots supply the 64-bit host indication | A board wiring document, or a physical transaction capture |

These items are also listed in [open-questions.md](open-questions.md).
