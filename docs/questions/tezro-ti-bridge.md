# Tezro: the TI PCI-to-PCI bridge (104c:ac28) on widget 15, head 0, device 2

Question. What is the bridge, what is behind it, does the PROM configure its secondary bus, and does IRIX ever
enumerate devices behind it? This page extends [tezro-io-topology.md](tezro-io-topology.md) and
[ip35-io9-pci-wiring.md](ip35-io9-pci-wiring.md) and repeats nothing they settled.

Method: static reading of the IP35 CPU PROM 6.210 (built Aug 26 2004; payload SHA-256 `554924380189a03a512156af2faa38344902f251b49fd5c80c253c23ecaff27b`)
with the Capstone-based routine reader plus a plain disassembly, including the compressed monitor image nested in it
(gzip stream at payload offset `0x8bbb0`; file offsets below are in the decompressed ELF); static reading of the IRIX
6.5.30 IP35 object `pciio_ppb.o` (SHA-256 `aadca7cfd050b4f2f8cfc5df59c408bd5cd376e748bb2e191eecce29b7591632`), plus
`pciio.o` and `pcibr.o`; the published inventory captures (five Tezro postings that print widget 15, one Onyx 4,
seven Origin 350 and Onyx 350 postings with an IO9 board line); the Tezro guides 007-4564-001 (tower) and 007-4643-003
(rack); the public TI PCI2050 and PCI2050B data manuals. Nothing was run. Addresses are payload offset plus `0x1fc00000`.

## Answer

1. **The printed "subclass 6" is a printing artefact, not hardware. Established.** The monitor's inventory printer for an
   unrecognised PCI function (nested image, call site at `0xa1590`) loads the config word at offset 8 that the scan stored
   per device, shifts it right by 24, and passes that one value as both "class" and "subclass". Every adapter line in
   the captures obeys this: fourteen distinct line shapes, all with class equal to subclass (class 6 for the bridge and
   for the PLX 9030, 3 for the display, 0xc for the QLogic and LSI parts). So the capture shows base class 6 (bridge)
   and says nothing about the subclass. The earlier report that the inventory contradicts both TI manuals (class
   `06:04`) is withdrawn: nothing contradicts them. Likewise `ffff_ffff_ac28_104c` in the PROM's configuration
   diagnostic is the ID word read with a sign-extending load (top bit set), not a hardware oddity. Established for the
   printer; that the hardware class code is `060400h` is **inferred** from the TI manuals, since no raw config bytes
   are published.

2. **The PROM never configures or scans behind the bridge. Established for the 6.210 image.**
   - The discovery routine (`0x1fc47fe8`) loops over device numbers 0 to 7 of one head and function 0 to at most 1,
     reads ID (`0x1fc47d44`), config offset 8 (`0x1fc47c98`) and the header-type byte at offset `0xc`
     (`0x1fc47be0`), dispatches on the ID, and sends every ID it does not know to a generic component creator
     (`0x1fc49e48`, call at `0x1fc4820c`); class 3 goes to the display path. There is no case for `0xac28104c` and no
     recursion.
   - Every one of the 14 callers of the config-address builder (`0x1fc47b04`) goes through a builder that has
     fields for widget, head, device and function only. It forms the type-0 window (`+0x20000`, or `+0x820000` for head
     1, plus device << 12 plus function << 8) and has no bus-number field. No `lui 2`/`lui 0x82` plus `0x8000` pair (the
     type-1 window at `+0x28000`, see [bridge](../../chips/bridge/README.md)) exists in the text of either the outer
     image or the nested monitor.
   - The PROM does know the part by ID in one place only: the configuration-space diagnostic (`0x1fc424d4` to
     `0x1fc42d90`, name table at `0x84ad0` to `0x84bb0`) lists it as a bridge by name and checks only its command/status
     and BAR0 reset values and a BAR write-back. It never touches bus numbers.
   Hence the PROM `hinv -v` of a Tezro lists nothing behind the bridge whatever is fitted there. The empty listing is
   not evidence that the secondary bus is empty. This also settles the earlier question of why no capture shows a
   downstream device: the PROM cannot show one.

3. **IRIX does enumerate behind it. Established (kernel object), not observed on a capture.** The 6.5.30 IP35 kernel
   carries a PCI-to-PCI bridge driver (`pciio_ppb.o`; the kernel image's symbol table has `ppb_scan` and
   `ppb_bus_alloc`).
   - The driver's init routine registers it with wildcard vendor and device (`pciio_ppb_init`, call at `0x1b2c`: both arguments -1).
     `pciio_ppb_attach` (`0x1b40`) attaches when config byte `0xb` (class) is 6 and byte `0xa` (subclass) is 0 or 4,
     so a `060400h` device qualifies.
   - `ppb_scan` (`0x0`) holds a semaphore and calls `do_ppb_scan` (`0x2d8`), which allocates a secondary bus number,
     writes primary and secondary bus numbers to config bytes `0x18` and `0x19` and the subordinate number to `0x1a`
     (`0x334`, `0x350`, `0x42c`), adds a hardware-graph vertex named `ppb_<secondary bus>` under the host slot's
     vertex (`0x36c`, `0x37c`; format `ppb_%d`), then reads the vendor ID of each device number on the new
     bus (type-1 addressing, bus in bits 23:16 and device in bits 15:11; `0x458` to `0x47c`) and runs `ppb_device_init`
     for each that answers. Hence behind a bridge the path is `.../pci-x/0/2/ppb_<n>/<slot>`.
   - Bus numbers: `pciio_ppb_init` reserves 0 to 15 and 255, and `ppb_bus_alloc` (`0x1968`) returns the lowest free
     number from a 256-bit map. So the first bridge IRIX attaches gets secondary bus 16 and vertex `ppb_16`, and the
     next one 17. **Inferred** (static read, not executed; the primary-bus input comes from the PCI host's own info).
   - Gate: `ppb_scan` refuses to initialise anything behind a bridge whose host bus is not multi-master (it prints a
     warning naming the host slot and the tunable `pciio_multimaster_override`; `0x23c` to `0x28c`). The PIC bus-info
     routine in `pcibr.o` reports multi-master only for PCI-X mode (see [ioc4](../../chips/ioc4/README.md)). So any
     device found behind the bridge implies head 0 of the IO9 PIC runs in PCI-X mode or the tunable is set.
     **Inferred**; the head's mode is not in any capture.
   - The pcibr object has the matching support: type-1 address and counter accessors (`pcireg_type1_cfg_addr`,
     `pcireg_type1_cntr_*`) and the interrupt route through a bridge (`pciio_ppb_intr_map` in `pciio.o`).

4. **What is behind it on a Tezro. Inferred: the tower's onboard audio function (IC Ensemble ICE1724, 1412:1724).
   Unknown: everything else.** Evidence, all published captures:
   - A device 1412:1724 prints at "PCI slot 2" with a MAD audio line in every Tezro IRIX board list that carries the
     bridge (two in this corpus; the earlier datasheet reports eleven records from the larger archive, which I did not
     re-read). It is at slot 2 every time, so it is fixed hardware rather than a card dropped in a free slot.
   - It cannot be a direct device of head 1, where free slots live: in one list it shares "slot 2" with a TI
     1394 card (head 1 slot 2), and in another a card at hardware-graph path `xtalk/15/pci-x/1/2` (an IOC3
     serial board) is on head 1 slot 2. Two functions cannot hold one device number on one head. It is listed
     directly after head 0's four IO9 entries and before head 1's, which is where a device on a bus behind head 0
     would appear if entries are listed in attach order (that reading of the order is **inferred**, weaker).
   - The tower has the analog audio jacks on its I/O daughtercard (guide 007-4564-001 printed p. 32); the rack
     (007-4643-003 pp. 27, 30) shows audio as an optional card; the rack Tezro captures print no bridge.
   - Onyx 350 inventories print a 1412:1724 at "PCI slot 1" (an option card: the DM8 audio board) with no bridge.
     So the ICE1724 does not imply the bridge in general; it implies it only at slot 2 on the tower.
   - The tower guide's alternative that the bridge's secondary bus carries bus 2's three slots is **contradicted**:
     the capture path `xtalk/15/pci-x/1/2` has no `ppb_` component, and by item 3 a device behind a bridge would.
     The cards in bus 2 sit directly on head 1. (Established for that one path; the other bus 2 slots follow by
     the same driver, inferred.)
   Whether the audio codec or any other chip also hangs off the bridge, how many devices, and their numbers on the
   secondary bus: **unknown**.

5. **Which board carries it. Inferred: the tower's interface board or its I/O daughtercard, not the IO9.**
   - The IO9 part is `030-1771-005` rev A in both Tezro lists that print an IO9 line, and in both Origin 350 lists
     (`030-1771-006` appears only in Onyx 350 lists). Origin 350 lists never show the bridge. The tower's interface
     board is `WS_INT_53` (`030-1881-006` or `-007`); the Origin 350 and Onyx 350 module carries `2U_INT_53`
     (`030-1809-003` or `-006`). The bridge follows the interface-board type in this corpus (both `WS_INT_53`
     systems that have an IRIX adapter list show it, none of the 2U-board systems do); it does not follow the IO9 part.
   - One forum author states that the node board, IO9 and V12 of a deskside Tezro boot in his rack Tezro and Origin 350
     (thread 3613, post of 22 July 2022); no inventory of that is posted. Second-hand, one source.
   - The IO6 and IO8 boards belong to Origin 2000, Onyx2 and Octane-class systems; no Tezro capture carries either.
   Not separable from here: interface board versus daughtercard, and the bridge variant (PCI2050 versus PCI2050B).
   The tower IO9 is a full-length board in bus 1 slot 1 (guide p. 31, p. 38); that the same slot's device 2 select line
   goes to a part on a different board is the inference.

6. **Hot-plug or a second I/O bridge. No evidence for either.** Neither Tezro guide mentions PCI hot-plug or a
   second bridge chip for graphics or USB. PCI2050B has CompactPCI hot-swap registers, which says nothing about this
   board. Graphics is on XIO (widget 12), not behind any PCI bridge. USB on the Tezro is an optional card in the free
   buses (a NEC OHCI function appears on head 1 slot 3). **Unknown** whether any of this changes the answer.

## Grades in one place

| Claim | Grade |
|---|---|
| Printed "class 6 subclass 6" is the base class printed twice | established (printer) |
| PROM scan covers devices 0 to 7 of each head, type 0 only; no secondary-bus handling | established (6.210) |
| IRIX attaches a PCI-to-PCI bridge driver to 104c:ac28 and enumerates behind it | established (kernel objects); not observed in a capture |
| Hardware-graph name `pci-x/0/2/ppb_<n>`, first `n` = 16 | name established; value inferred |
| Secondary bus holds the tower's ICE1724 | inferred |
| Other devices behind it | unknown |
| Bridge sits on the interface board or daughtercard, not the IO9 | inferred |
| Bridge variant (PCI2050 or PCI2050B), raw class and revision bytes | unknown |
| Head 0 of the IO9 PIC is in PCI-X mode | unknown (implied if item 4 is right) |

## What would settle the unknowns

No owned machine can answer these: the only SGI systems on hand are an Origin 350 and an Octane2, and neither carries
the bridge, so a read of either would show only its absence. Documentation, captures and both kernel objects are
exhausted for the topology. The smallest decisive observation needs a Tezro tower with IRIX, as a third party's
posted output:

- `ls /hw/module/*/IXbrick/xtalk/15/pci-x/0/2/` (shows whether a `ppb_<n>` vertex exists and its `<n>`, and what
  is under it), and `hinv -mvv` with the audio entry's location. One command pair settles items 4 and 5's first half.
- A PCI configuration dump of bridge bytes `0x00` to `0x1f` and `0x40` to `0x4f`, read from the IRIX config-space
  access of that vertex, settles the variant, revision, class and the bus numbers.
A photograph of the tower interface board's TI package (marking and neighbours) would place the bridge on a board.
Do not ask for these; wait for a published capture or a photograph of a Tezro opened by its owner.
