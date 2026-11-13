# PCI shoebox: the Origin 2000 PCI carrier assembly

The PCI shoebox is an XIO board for the Origin 2000 and Onyx2. It takes one XIO slot and gives three PCI slots,
built around one Bridge. The PROM types it as board type `0x26`, the PCI shoebox type, through the `030-1062-`
prefix ([the Crosstown page](../crosstown-ktown/README.md#prom-classification-of-the-origin-200-crosstown-board)). The Bridge
contract is on [the Bridge page](../bridge/README.md), and the PROM's `pciiox` routine that registers the
prefix is in the same page's kernel-routine section.

The Octane's three-slot PCI card cage is a different assembly. It has its own Crossbow port and its own IRIX name.
Its page is [the Octane PCI module page](../octane-pci-module/README.md).

Status: draft, imported from published sources, not independently reviewed. It adds no register contract.

Grades follow [AGENTS.md](../../AGENTS.md): **established** means a manual, a real listing or a routine read in full
states it; **inferred** means a reasoned reading; **unknown** means no held source settles it.

## Composition and identity

| Property | Grade | Evidence |
|---|---|---|
| The carrier assembly houses up to three third-party PCI boards, two full-size and one half-size, with up to 75 watts of power | established | SGI 007-3456-003, *Origin2000 Rackmount Owner's Guide*, "PCI Carrier Assembly" and Figure 2-11 (printed page 34), re-read. The page calls it the "PCI carrier assembly", not the shoebox. |
| The carrier takes one XIO slot and is built around one Bridge | inferred | the same page does not say either. The Bridge follows from the PROM's `pciiox` routine and the real `hinv` listings cited elsewhere in this repository; the single XIO slot follows from the board being an XIO board. |
| The PROM types the board as `0x26` through the `030-1062-` prefix | established | [the Crosstown page](../crosstown-ktown/README.md#prom-classification-of-the-origin-200-crosstown-board); the IP27 `pciiox_init` routine registers the same prefix ([the Bridge page](../bridge/README.md)) |
| Part `030-1062-002` is the Origin 2000 PCI cardcage, named `PCI_XIO` | inferred | third-party part list only. The community PCA table transcribes it (see [the Crosstown page](../crosstown-ktown/README.md#prom-classification-of-the-origin-200-crosstown-board)). The import source calls this "SGI's part-number table", but no SGI primary part list was held here. |
| SGI's manual calls the Origin 2000 board at `io2/pci_xio` the "PCI shoebox" | established | SGI 007-0911-180, *IRIX Device Driver Programmer's Guide*, printed page 83, Example 4-1: the comment reads "Path assumes O2000/Onyx2 PCI shoebox installed in first CPU module" above `/hw/module/1/slot/io2/pci_xio/pci/2/base/0`. Re-read: the page and the comment match, and the example's own text puts the device in PCI slot 1 of an Origin200, so the path is not an Origin 2000 capture. |
| The IP27 kernel's board list names PCI shoebox for `IP27_BRD_PCI1` and PCI shoehorn for `IP27_BRD_PCI3` | software expectation | OpenBSD `sys/arch/sgi/include/mnode.h` comments. The shoehorn is a separate product; see [the interconnect naming page](../../evidence/interconnect-naming.md) for the names. |
| A card read at PCI device 2 behind the carrier is addressable | inferred | the same Example 4-1 reads one card's configuration space at `pci/2`. It is a programming example, not a capture, so it shows only that device 2 is reachable. |

## Not the Octane PCI module

The Octane module and this carrier share a shape (three slots, one Bridge) and not an attachment.

| Property | Grade | Evidence |
|---|---|---|
| Part `030-0952-005` is the Octane PCI card cage, named `XTALKPCI`, on Crossbow port 13 | inferred for the part; observed for the port and name | part number from the third-party list only. The port and `XTALKPCI` name are from the public Nekonomicon and IRIXnet listings the import source cites (threads 12262, 16726610 and 3227). Those listings were not re-read in this import. |
| The two assemblies carry different hinv names | observed | the same listings: `XTALKPCI` for the Octane module, `PCI_XIO` for the Origin 2000 carrier. Cited from the import source; not re-read here. |
| Components transfer between machines, topology does not | established | the project's component rule, stated in the import source's terminology. Nothing here transfers the carrier's Bridge revision or device wiring to the Octane module. |

## Not yet settled

- **Device-number wiring.** Which Bridge configuration device each carrier slot uses is not in any held source.
  The three-slot device 0 to 2 layout is a model choice, so it is not a hardware fact here. What would settle it: a
  configuration read or `hinv -v` capture from a real carrier that names the device of each slot.
- **Real `hinv` listing of the carrier.** The `PCI_XIO` lines above come from the listings the import source cites,
  not from a capture held here. A real carrier `hinv -v` with each card's `pci id` would settle the slot map.
