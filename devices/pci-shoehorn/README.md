# PCI shoehorn (the single-slot XIO-to-PCI adapter, 030-1275)

The PCI shoehorn is an SGI XIO option board with one Bridge and one PCI slot. It is a separate product from the
three-slot PCI shoebox ([pci-shoebox.md](../pci-shoebox/README.md)) and from the Octane PCI module
([octane-pci-module.md](../octane-pci-module/README.md)). The Bridge's register contract is in
[bridge-family.md](../bridge/family.md) and on [the Bridge page](../../chips/bridge/README.md). This page covers the
board: its identity, where it fits, its slot, its interrupt wiring as software expects it, what the PROM and IRIX
print for it, and what is unknown.

Grades: **established** means a hinv or PROM capture, a photograph of the board's label or ASIC, or a published
specification states the fact. **Inferred** means a reasoned reading, usually of a public driver. **Unknown** means
no held source settles it. The captures are public forum and Usenet transcripts. They are counted here, not quoted.

Status: draft, not independently reviewed.

## Identity

| Fact | Value | Grade |
|---|---|---|
| Board name | `XTALK_PCI`, in the board record and in IRIX's hinv | established |
| Part and revision | `030-1275-002` rev B, `030-1275-003` rev A, `030-1275-004` rev A, `030-1275-005` rev A. The `-002` rev B is on a label photograph and in one Origin 2000 capture. `-003` rev A is in an Origin 2000 capture. `-004` rev A is in an Origin 2000 capture and an Octane capture. `-005` rev A is in two Octane captures | established per specimen; other revisions unknown |
| Silkscreen | "PCI-XTALK ADAPTER", assembly marking `030-1275-002 REV B`, 1997 copyright line | established (label photograph) |
| Bridge ASIC | One Bridge, an LSI L2A0710 part marked `Bridge Rev D` (SGI part 099-0125-007) on the photographed board | the ASIC marking is established from the photograph; that the board reports a Bridge at its widget is inferred from the marking |

## Bridge revision

| Platform | Revision | Grade |
|---|---|---|
| Origin 2000 | 4. The PROM prints `ASIC BRIDGE Rev 4` for every `XTALK_PCI` board in four captures (six listings). Revision 4 is the photographed "Rev D" ASIC, in the naming of [bridge-family.md](../bridge/family.md) | established |
| Octane | unknown. Octane `hinv -mv` prints no ASIC line, and no Octane PROM capture of this board is held. See [open-questions.md](../../questions/README.md) | unknown |

## Where it fits

| Platform | Placement | Grade |
|---|---|---|
| Octane and Octane2 | XIO option ports 9 to 12. Observed at widget 10 in three captures, all dual-R14000 Octane2 systems with a V12 graphics board at widget 11. Ports 9, 11 and 12 are not seen in any capture | established at widget 10; other ports unknown |
| Origin 2000 and Onyx2 | Observed at widgets 13, 14 and 15. In two captures XIO slot io5 is widget 13, and in a third it is widget 14, so the slot-to-widget map differs between captures and one capture's map does not carry over to another | established (captures) |
| Origin 200 (GIGAchannel) | unknown. A `030-1275-004` board appears in a photograph from a reseller lot that included an XBOX cabinet, but no capture shows one fitted in that cabinet's five XIO slots | unknown |
| Origin 3000 and later | unknown. No source addresses an XIO slot there. The PCI carriers on those machines are XBridge-based and separate ([origin300-pci-expansion-module.md](../../platforms/bricks/origin300-pci-expansion-module.md)) | unknown |

## Slot and card

- **One PCI slot, software slot 1.** On Origin 2000, the card behind the board appears in hardware graph paths
  of the form `.../slot/ioN/xtalk_pci/pci/1/`, in more than one capture, including a Cad Duo
  ([cad-duo-pci-card.md](../cad-duo-pci-card/README.md)). Established.
- **Octane.** A card behind the board is listed as `PCI slot 1` in hinv. One Octane capture shows it directly.
  Established for that capture.
- **Configuration device 1 is the software slot.** Inferred from the graph naming, the same step the
  [Octane PCI module](../octane-pci-module/README.md#slots) leaves open. Whether slot N is wired to
  configuration device N is unknown for the module and is not settled here for this board.

## Interrupts

- **Inferred.** A card at device 1 reaches Bridge input 1 on INTA and INTC, and Bridge input 5 on INTB and INTD.
  The software rule is established: IRIX 6.5.30's `pcibr_intr_bits` maps INTA and INTC to the slot's input and
  INTB and INTD to `slot ^ 4`, as [the IP35 IO9 note](../../questions/ip35-io9-pci-wiring.md) records. What this board
  wires to what has not been traced or captured. The [Cad Duo page](../cad-duo-pci-card/README.md#interrupts) rates the same
  wiring question unknown. That grade stands there until a trace or capture settles it.

## Board record, PROM and IRIX output

- **Established, Origin 2000 PROM hinv.** `XTALK_PCI IO Board, Module M, Slot ioN`, then `ASIC BRIDGE Rev 4,
  (widget W)`, then the card as an adapter line with `(pci id 1)` where the PROM prints it.
- **Established, Origin 2000 PROM discovery.** `Found an io Board with nic 030-1275-00x` during local IO discovery.
- **Established, IRIX `hinv -mv`.** `XTALK_PCI Board: barcode ... part 030-1275-00x rev X`, located at
  `/hw/module/M/slot/ioN/xtalk_pci` on Origin 2000 and at `/hw/node/xtalk/10` on Octane.
- **Established, captures.** Plain `hinv` prints no board line for this board. Its card's functions still appear.
- **Established, software.** The IP27 and IP30 kernels test the board's NIC string for the `030-1275-` prefix and
  then call `pcibr_rrb_alloc_init` ([IP27 routines](../../software/kernel/ip27/bridge-routines.md),
  [IP30 routines](../../software/kernel/ip30/bridge-routines.md)).
- **Board record.** The Bridge's one-wire part carries the board name, part number and revision. The name and part
  are established from hinv. The revision letter is inferred from the label. That the record uses the fixed layout
  described on [the BaseIO page](../baseio/README.md#board-identity-on-the-bridge-one-wire-bus) is inferred.

## Unknown

- The Bridge revision on Octane (see the table above).
- Revisions of `030-1275` other than those listed.
- Octane ports 9, 11 and 12: only widget 10 is captured.
- The board's own wiring of its slot's interrupt inputs, including whether a card's INTB reaches Bridge input 5
  here.
- Whether the board fits Origin 200, Origin 3000 or later machines.

## Related products

- [pci-shoebox.md](../pci-shoebox/README.md): the three-slot Origin 2000 PCI carrier, a different board with a different part.
- [octane-pci-module.md](../octane-pci-module/README.md): the three-slot Octane PCI card cage.
- [interconnect-naming.md](../../evidence/interconnect-naming.md): the names the IP27 board list gives the PCI boards.
