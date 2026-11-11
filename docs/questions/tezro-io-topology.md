# Tezro: the widget population, per-head PCI devices, the second PROM build, and the graphics board's identity

Question. On a Tezro (IP53 or IP59 node board, IP35 platform), which crossbar widgets exist, what do the PROM and the
operating system print for them, do the PROM discovery routines read the same values in the 6.211 build as in 6.210,
and what do the PROM and kernel read to identify the graphics board at widget 12? This page extends
[tezro-widget-11.md](tezro-widget-11.md) and [tezro-v12-placement.md](tezro-v12-placement.md); it repeats nothing they
already settled.

Method: published PROM `hinv -v` captures of three Tezros (PROM builds dated 26 August 2004 and two captures from
2022), thirteen published IRIX `hinv -mv` records that list widget locations, and static reading of two shipped IP35
CPU PROM payloads with the Capstone-based routine reader (`retools/tools/hostfacts.py`, flat, load address
`0x1fc00000`): SGI Version 6.210 (built Aug 26 2004; image SHA-256
`d74b4b7ef9c11c66692019db9af698104595be7a0573a86feae8a83441921318`, payload SHA-256
`554924380189a03a512156af2faa38344902f251b49fd5c80c253c23ecaff27b`) and SGI Version 6.211 (built Jan 25 2008, from
patch 7208; image SHA-256 `daed215f0e3b4ccd1a654e16a1e810fdf608a13509f51e3706906272ee4e727a`, payload SHA-256
`25f60c7f0bae9cf32611e04205b7d0c8cf08adfddbfc1bfe433facd95b5ce271`). Both images carry a 4096-byte header; addresses
are payload offset plus `0x1fc00000`. The base-I/O monitor nested in the 6.210 image was searched for the graphics
diagnostic only (item 7). Nothing was run.

## Answer

1. **Established** (three of three PROM `hinv -v` captures of a Tezro). The PROM inventory lists one node with a
   Bedrock of revision 2 at 200 MHz, then four bridge entries printed as "ASIC BRIDGE Rev 3": two for widget 11 and two
   for widget 15 (one entry per PIC head, so each PIC prints twice), then one "ASIC XBOW Rev 3, on CBrick" entry
   with no widget number, then one graphics-board entry with no revision and no widget number. The crossbar's widget part
   is not printed. The revision-3 figure is the printed revision field of widget 0, and the bridge revision is the
   printed field of each head. No capture prints a widget at 8, 9, 13 or 14 in the PROM inventory.
2. **Established** (thirteen IRIX records that list widget locations: two- and four-processor IP53 and IP59 nodes). The
   interface board (printed name `WS_INT_53`, assembly `030-1881-006` or `-007`) is listed at widget 11 and at widget 15
   in all thirteen, and in all thirteen the barcode at widget 11 equals the barcode at widget 15. So the two PICs sit
   on one physical board with one identity record, and whatever the PROM reads to name the board returns the same
   answer through both. The graphics board is listed at widget 12 in all thirteen; a digital-video board at widget 13
   in two. No record lists a board at widgets 8, 9, 10 or 14 (the hub widget is the node itself). The hardware-graph
   path of every record names the enclosing brick class as the IX brick, for example
   `/hw/module/<module>/IXbrick/xtalk/15/pci-x/0/1/ioc4`. The PROM inventory prints the same class for the bridge
   entries.
3. **Established** (the same three PROM captures; widget 15, bus index 0, "pci id" as the PROM prints it). A stock
   interface board shows: id 1 the IOC4 (printed revision `0x53` in one capture and `0x4f` in another), id 2 a
   PCI-to-PCI bridge from vendor `0x104c`, device `0xac28`, id 3 a SCSI controller (printed revision 6), id 4 a gigabit
   Ethernet controller (printed revision `0x15`). Bus index 1 of widget 15 and both heads of widget 11 print no
   adapter in the stock capture; in the one capture that carries optional cards, those appear under widget 11 (ids 1 and 2) and under bus index 1 of widget 15 (ids 1 and 3). Which printed "pci id" is the bridge's device-select number is **inferred** (the
   numbering matches the four device slots a PIC head has). What the `0xac28` bridge feeds, and its interrupt route,
   are **unknown**; no capture lists anything behind it.
   Five distinct Tezro postings print a widget 15 entry and all five show the bridge there: the three PROM captures
   (`docs/library/hinv/fresh-prawn/02.hinv`, `mighty-fox/01.hinv`, `immune-raptor/01.hinv`) and two IRIX board lists
   (`docs/library/hinv/model-stork/01.hinv`, `close-bug/01.hinv`), which print `PCI Adapter ID (vendor 0x104c, device
   0xac28) PCI slot 2`. Seven Origin 350 and Onyx 350 captures carry an IO9 board line and none shows the bridge
   (`docs/library/hinv/polite-rat/01.hinv`, `loving-slug/01.hinv`, `fast-oryx/01.hinv`, `living-raptor/01.hinv`,
   `vocal-stag/01.hinv`, `vocal-stag/03.hinv`, `cute-shrimp/02.hinv`). On `cute-shrimp/01.hinv`'s PROM form, widget 15
   pci id 2 holds a USB (OHCI) adapter instead. **Established** for those captures. The cause of the difference is
   **unknown**, and the sample is small (five Tezro, seven Origin 350 and Onyx 350).
4. **Established for the build compared, inferred for behaviour.** The PROM 6.211 build carries the same widget
   discovery code as 6.210. I located twelve routines of the discovery and graphics paths in 6.211 by instruction shape
   (jump targets masked): the identity read of widget 0 (6.210 `0x1fc66b08`, 6.211 `0x1fc66b00`), the widget-0 part
   dispatch (`0x1fc66c48`, `0x1fc66c40`), the crossbar bring-up (`0x1fc4c5e4`, `0x1fc4c5e8`), the per-link test
   (`0x1fc4f3ec`, `0x1fc4f3e4`), the link reset (`0x1fc4bd30`, `0x1fc4bd34`), the walk (`0x1fc4b17c`, `0x1fc4b180`),
   the graphics attach (`0x1fc4ab14`, `0x1fc4ab18`), the board creation (`0x1fc44d7c`, `0x1fc44d80`), the bridge
   diagnostic (`0x1fc421a0`, `0x1fc421a4`), the name test for the PIC (`0x1fc4b748`, `0x1fc4b74c`), the widget-type
   dispatcher (`0x1fc60404`, `0x1fc603fc`) and the explicit link 10 and 11 handling (`0x1fc4d65c`, `0x1fc4d654`). For nine
   of them I compared the access lists and the constants of both builds: the hardware-visible constants (`0xd100`,
   link 15, the `0x100` link-block base and the `0xc000`, `0x8000` and `0x20` values the routines compare or store) are identical, and the only differences are immediates that look like offsets into the PROM's own data pool (`0x6fa8` against `0x6f98` in five of the nine routines, and single pairs such as `0x1618` against `0x1610`, `0x1680` against `0x1678` and `0x10b8` against `0x10b0`). The graphics attach has one more pool-sized immediate in 6.211 (`0x13c8`) that I
   did not trace. That is a comparison of mechanical facts, not a full read of the 6.211 bodies, so "same behaviour" is
   **inferred**; the credit table of item 5 is **established** (byte-identical).
5. **Established** (table read in full; consumer not re-read). The PROM keeps a table of fourteen 16-byte rows (part,
   credit, field mask, field shift) at `0x1fd63ad8` in 6.210 and `0x1fd63a78` in 6.211; the fourteen rows are
   byte-identical in the two builds. [tezro-widget-11.md](tezro-widget-11.md) quotes only the PIC row. All fourteen:

   | part | credit | mask | shift |
   |---|---|---|---|
   | `0xc110` | 4 | `0xe000` | 13 |
   | `0xc002` | 3 | `0xf000` | 12 |
   | `0xd102` | 3 | `0xf000` | 12 |
   | `0xd112` | 3 | `0xf000` | 12 |
   | `0xd002` | 3 | `0xf000` | 12 |
   | `0x0000` | 4 | `0x7c0000` | 18 |
   | `0xd100` | 4 | `0x7c0000` | 18 |
   | `0xd000` | 4 | `0x7c0000` | 18 |
   | `0xc102` | 4 | `0xf000` | 12 |
   | `0xc003` | 4 | `0xf000` | 12 |
   | `0xc104` | 4 | `0xff000000` | 24 |
   | `0xc105` | 4 | `0xff000000` | 24 |
   | `0xc202` | 2 | `0xff000000` | 24 |
   | `0xc013` | 4 | `0xf000` | 12 |

   What this adds: there is a row for the graphics part `0xc013` (credit 4, bits 15:12), for the PXBOW part `0xd100`
   (credit 4, bits 22:18, the same field as the plain crossbar `0x0000` and `0xd000` rows) and for the Bedrock part
   `0xc110` (credit 4, bits 15:13). That the credit goes into the widget's own control word is **inferred** from the
   earlier page's reading of the link-reset routine (control write at `+0x24`); I found no `lui`/`addiu` or pointer
   reference to the table's address in either build, so the consumer's indexing is **unknown** here. That the PROM carries a
   row for `0xc110` shows the PROM knows the part; it does not show that any code reads the hub's identity from hardware
   (no consumer of it was found, as [crosstalk-host-ends.md](../crosstalk-host-ends.md) records).
6. **Established** (code, both builds). The widget 0 part accepted by the dispatcher, the link-15 waiver for part
   `0xd100` and the PIC name test (`0xd102` or `0xd112` with manufacturer `0x24`) read the same constants in 6.211 as in
   6.210 (item 4). Nothing in either build lets this page decide between parts `0`, `0xd000` and `0xd100` for a Tezro's
   widget 0. The inventory captures settle only its revision (3). The link-15 waiver exists for part `0xd100`
   alone, and on a Tezro link 15 is the IO9's PIC; that fits `0xd100` and is **inferred** to be why the waiver exists. The
   conflicting public report (a 2009 OpenBSD console log that names the part Bedrock) stays open.
7. **Graphics board identification.** Part `0xc013`, manufacturer `0x23`, is the Odyssey identity in the public OpenBSD
   widget table, and the PROM's graphics path keys on `0xc013` (established in [tezro-v12-placement.md](tezro-v12-placement.md); the credit table of item 5 also has a row for it). The revision nibble of the identity word is what differs between boards. What the
   evidence says:
   - **Established.** Published Tezro IRIX `gfxinfo` captures: six records, all 128 MB; five print BUZZ version B.2 and
     one B.1.
   - **Established.** Three published base-I/O PROM diagnostic transcripts of IP35 hosts with a 128 MB board print "Board version 1 - Buzz revision" 3B, 3B and 2B (from a Tezro forum post and an Origin 350 notes page; which digit belongs to which source is not recorded here).
   - **Inferred.** The two-way agreement (B.2 with 3B, B.1 with 2B) fits "printed minor number = widget revision nibble minus 9" and "Buzz revision digit = nibble minus 8", but the pairs come from different boards. The IRIX side's A.1 for nibble 2 and B.1 for nibble 10 is established in
     the Odyssey driver's board-info code (datasheet page for the Odyssey); B.2 for nibble 11 follows the same rule and is not
     measured.
   - **Unknown.** Which input the base-I/O monitor uses for the digit after "Buzz revision" (the widget revision nibble,
     the strap word at `+0x106c`, or a Buzz register). I tried to find the code in the nested base-I/O image: the format
     string's address is built by pool offsets and the two direct address pairs I found in the image are table entries, not code, so the
     reader was not located. A single shipped version of that image is held.
8. **Not settled by this pass; not changed.** One-processor widget placement (widget 12, one PIC or two); whether the
   second PIC has its own crossbar; the second PIC's part; link-status values beyond alive and present at widgets 11, 12 and
   15; whether PXBOW has all eight link blocks and the Crossbow revision-5 fences and lock. Each keeps its existing
   test in the two pages above.

## What would settle the unknowns

| Unknown | Test |
|---|---|
| Source of the PROM's "Buzz revision" digit | Run the base-I/O PROM against a model of widget 12 with revision nibble `0xb` and compare the printed digit with `0xa`; keep the strap word fixed. A hardware read of widget 12 `+4` on a board that prints 3B settles the nibble directly. |
| Consumer of the credit table | Find the routine that indexes the table (it must load a part and compare); candidate route: the gp-relative literal pool of the link-reset routine's caller, read with the pool-aware scanner. |
| Behaviour of 6.211's graphics attach beyond constants | Full read of `0x1fc4ab18` and a diff of its blocks against `0x1fc4ab14`. |
| What the `0xac28` bridge carries | See [tezro-ti-bridge.md](tezro-ti-bridge.md): the PROM cannot show anything behind it; an IRIX `/hw` listing of `pci-x/0/2/` on a Tezro, or a board photograph, settles it. |
