# Origin 300 PCI expansion module

The Origin 300 PCI expansion module adds six PCI buses to an Origin 300 over NUMAlink. Its
NUMAlink end is a Bedrock interface card (BIC). Three XBridge chips, U0, U1 and U2, drive the six
PCI heads. This page records the physical topology, the chip composition, the XBridge modes and
the PCI data width, with what is unknown. It holds no register contract. Register facts for the
chips on the card are in their own pages, linked below. Each fact carries a label as in the rest of
this repository. **Established** means a published guide or specification states it, with the
citation. **Inferred** means reasoned from established facts. **Unknown** means not settled, with
the route that would settle it.

The NUMAlink module that joins base and expansion modules is on [origin300-numalink-module.md](origin300-numalink-module.md).

## Sources

- **PCI Expansion Module User's Guide**, SGI `007-4499-002` (5.0-V and/or 3.3-V support), cited as
  `007-4499-002 p. N` by printed page. Its earlier edition `007-4499-001` is cited by its own number.
- **Origin 300 System with NUMAlink Module User's Guide**, SGI `007-4498-002`, cited as
  `007-4498-002 p. N`.
- **Xbridge ASIC specification rev 0.5**, dated 10/1/98, held here as
  [docs/sources/specs/xbridge-asic-specification-rev0.5.pdf](sources/specs/xbridge-asic-specification-rev0.5.pdf)
  and cited by printed page. It is a design-stage specification, so its statements are plans
  until silicon confirms them.
- **Public Linux SN1 `pcibr.c`**, at commit `7570df54ef8c`, lines 262 to 272, the widget-to-bus
  table. The Linux tree is an uninitialised submodule in this clone, so this table is cited from
  the source record and was not re-read for this page.

The guide pages above are not held in this repository, and their page numbers have not been checked
against the printed guides. The Xbridge pages were read in the held PDF.

## Physical topology

**Established** (`007-4499-002 p. 12`, figure 1-8). A compute module's LINK (NI) connector is cabled
straight to the expansion module's NI connection.

**Established** (`007-4499-001` and `007-4499-002`, printed p. 13). Routed operation is supported on
NUMAlink ports 2 to 5. The module does not work on ports 1, 6, 7 or 8. The guides give no reason for
the port restriction, which is also on the [NUMAlink module page](origin300-numalink-module.md).

## Chip composition and PCI heads

**Inferred.** The BIC carries a Bedrock and three XBridge chips. U0 has two PCI heads inside the
chip, E and F, and four external widgets, `0x8`, `0x9`, `0xc` and `0xd`. U1 and U2 each carry two
PCI heads, E and F, and each connects to two of U0's external widgets. The basis is the guide's
wiring and a public owner inventory that lists six PCI widgets.

The widget-to-bus map below is **inferred** for this product. The Linux table is a software
expectation, which this page rates as inference. The guide wiring and the owner inventory then
place each widget on a head.

| Widget at U0 | PCI bus | Head and connection |
|---|---|---|
| `0x8` | 2 | U1 head E, through U1 head D to U0 widget `0x8` |
| `0x9` | 1 | U1 head F, through U1 widget `0x8` to U0 widget `0x9` |
| `0xc` | 5 | U2 head F, through U2 widget `0x8` to U0 widget `0xc` |
| `0xd` | 6 | U2 head E, through U2 head D to U0 widget `0xd` |
| `0xe` | 4 | U0 head E, internal |
| `0xf` | 3 | U0 head F, internal |

So U1 serves buses 1 and 2, U0 serves buses 3 and 4, and U2 serves buses 5 and 6.

This is a software-derived map, not a scan of six buses on a machine. A register test of the six
heads has to tell U0's crossbar apart from its two internal heads and its four external heads.

## Processors, memory and the BIC's processor interface

**Established** (`007-4499-002 p. 50`). PI0, PI1 and MD are unused, because the module has no
processors and no memory. The BIC's Bedrock therefore has no CPU and no local memory.

The CPU-present registers, PI A and B at offsets `0x40` and `0x48`, are on the
[Bedrock processor interface page](bedrock-processor-interface.md). Whether a remote I/O access to
the BIC reaches those words, and what they read, is unknown (see below).

## Serial ID EEPROM

**Established** (`007-4499-002 p. 46`). A real module has a serial ID EEPROM. Its part, bus address
and contents are not given in the guide, so they are unknown.

## XBridge modes

The Xbridge specification rev 0.5 describes two modes. The mode descriptions are **established** as
the specification's statements. Their use on this module is **inferred**: U0 runs in XBridge mode,
and U1 and U2 run in Super Bridge mode.

- **XBridge mode** (section 3.2, p. 44). The chip works like a Crossbow with two Bridge ASICs on
  ports `0xe` and `0xf`. The LLP config and NIC registers have no effect in this mode. The flash is
  reached through a space provided by the bridge on port `0xf`.
- **Super Bridge mode** (section 3.3, p. 45). The internal crossbar is disabled, and no access to it
  is provided. Both PCI bridges connect to external ports. The bridges power up as `0xe` and `0xf`,
  and the spec says they can be changed. The widget number field is control bits 3:0 (see
  [bridge-family.md](bridge-family.md#xbridge)). The port that powers up as `0xf` has access to the
  NIC register, and the other bridge's NIC register is unused. Each bridge's LLP config register
  configures its own link.

The rev 0.5 plan names the XD and X8 ports as the external ports, and says that may change. This
page does not name them.

## PCI data width

**Inferred.** The guide `007-4499-001`, figure 3-5, labels each 66 MHz bus with a 512 MB/s peak. A
32-bit data path at 66 MHz peaks at about 266 MB/s, so the label suggests 64-bit data phases.

- The guide does not state which slots wire REQ64# and ACK64#. This is **unknown**.
- The guide says the slots support 32-bit or 64-bit addressing. That does not settle the data width.
- The SGI Gigabit Ethernet guide `007-3819-004` identifies its fiber and copper boards as 32/64-bit
  PCI devices and lists Origin 300 support. It does not give the width negotiated in an installed
  slot. The chip on those boards, and the one bus-width flag it reads, are on [tigon.md](tigon.md).

## Unknown

| Open item | Evidence that would settle it |
|---|---|
| The BIC's Bedrock and XBridge silicon revisions, and their reset values | A board specification, or register reads from an installed module that match the chip identification words |
| Which slots wire REQ64# and ACK64# | A board wiring document, or a physical transaction capture |
| Whether a remote I/O access reaches the BIC's CPU-present words, and what it reads | A register capture from a real module |
| The serial ID EEPROM's part, bus address and contents | A board specification, or an inventory of a real module |
| The NI packet commands, discovery and L1 control of this module | A published hardware overview, or a public software consumer that addresses the module |

These items are also listed in [open-questions.md](open-questions.md).

## Related pages

- [origin300-numalink-module.md](origin300-numalink-module.md): the router enclosure that joins base and expansion modules.
- [bedrock-network-interface.md](bedrock-network-interface.md) and [bedrock-io-interface.md](bedrock-io-interface.md): the Bedrock NI and II registers that the BIC's Bedrock uses.
- [bedrock-processor-interface.md](bedrock-processor-interface.md): the PI registers named above.
- [bridge-family.md](bridge-family.md): the Xbridge register facts and its part and revision.
