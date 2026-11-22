# Visual Workstation 320 and 540: sources read and sources missing

What the pages under [platforms/visws/](../platforms/visws/README.md), [devices/cobalt/](../devices/cobalt/README.md)
and [devices/lithium/](../devices/lithium/README.md) rest on, and what could not be found. This page lists the Linux code and posts that
the platform pages first rested on. Since then SGI's shipped Windows NT 4.0 software and PROM 1.0002, 1.0004, 1.0005, 1.0006 and 1.1005 have been read
([software/visws](../software/visws/README.md)); they rank above Linux for this machine, and
[Sources by origin](../platforms/visws/README.md#sources-by-origin) says which facts each supports. No manual or specification
for the Cobalt, Lithium or Arsenic chips has been found, so Linux plus the shipped binaries are the register-level evidence.

## Public Linux code read

SGI's own Linux platform code for the machine ranks as the vendor's software source, as for the SN2 pages: a fact it
defines is **established**, as a software definition. The code is partly SGI's (the Lithium audio driver is copyrighted
1999 by SGI; the interrupt code carries SGI and Ingo Molnar names and a 2000 update by an SGI engineer) and partly
community work (the PCI interrupt map, the 2.5 port). Where a file's author matters it is said on the page.

| Tree and version | Files | Used for |
|---|---|---|
| Linux 2.2, linux-mips 2.2 branch, `5e3bc539e2dd` | `include/asm-i386/cobalt.h` and an earlier copy `sgi-cobalt.h`, `include/asm-i386/lithium.h`, `arch/i386/kernel/{visws_apic,setup,traps,time,bios32}.c` | The first form: per-board-revision wiring tables, the legacy-device direct wiring of early boards, the 307 interrupt fix-up, the timer acknowledge, the board-revision probe. |
| Linux 2.4, linux-mips 2.4 branch, `8ef7d46c94d5` | `include/asm-i386/cobalt.h`, `arch/i386/kernel/pci-visws.c`, `drivers/sound/vwsnd.c` and `Documentation/sound/vwsnd` | The intermediate header and PCI scan; the audio driver's first form. |
| Linux 2.6.20 (kernel.org tag, fetched) | `arch/i386/mach-visws/{setup,traps,reboot,mpparse,visws_apic}.c`, `include/asm-i386/mach-visws/*.h`, `arch/i386/pci/visws.c` | The `mach-visws` layout, before the code moved. Same register facts as the later tree; adds the power-off special cycle that names the PIIX4 bus. |
| Linux 2.6.33-rc5, kernel history tree `981a2edd1922` | `arch/x86/kernel/visws_quirks.c`, `arch/x86/include/asm/visws/{cobalt,lithium,piix4}.h`, `arch/x86/pci/visws.c`, `sound/oss/vwsnd.c`, `Documentation/sgi-visws.txt`, `include/linux/pci_ids.h` | The main reading: the whole platform file in one piece. |
| Linux 3.14 (kernel.org tag, fetched) | `arch/x86/platform/visws/visws_quirks.c`, `arch/x86/include/asm/visws/{cobalt,sgivw}.h`, `arch/x86/pci/visws.c` | The last release with the code. Compared against 2.6.33: the register facts, the PCI interrupt map and the board probe are unchanged. |

When the code went: it began as a 2.2-era `CONFIG_VISWS`, moved to a split-out unmaintained file in December 2001, was
`arch/i386/mach-visws` from 2.5.63 to 2.6.23, became `visws_quirks.c` (and a kernel that also boots on ordinary PCs)
with Ingo Molnar's "turn x86 VISWS into a generic architecture" patch of 10 July 2008 (2.6.24 to 2.6.27, LWN article
289879; LKDDb lists the option in `arch/x86/Kconfig` for 2.6.24 to 3.14), and was deleted by H. Peter Anvin's commit
`10f032c61d12` ("x86, platforms: Remove SGI Visual Workstation", 25 February 2014, "seems to be dead"), merged for v3.15.
The 12 files it touched are the ones in the table. The LKDDb and LWN pages and the removal message were fetched from the
public web; the tag files were fetched from the public GitHub mirror of the kernel tree because the trees held here have
the 2.6.33 tree and the 2.2 and 2.4 branches but not the 2.5 to 2.6.23 `mach-visws` tree.

Not read, because it is not in any tree held: the framebuffer driver and the graphics driver side (covered by the
graphics pages), the 2.2 `irq.c`/`smp.c` hooks (only their `#ifdef` lines were seen).

## Posts and documents

- Usenet, `37697150.79B89176@-aw-dot-sgi.com` (Ian Ameline, 17 June 1999, writing as a user who owned a 320 and "poked
  around"): memory banks, DIMM count, CPU slots, PCI voltage. Treated as inferred.
- Usenet, `376F6A70.CD8128B@brussels.sgi.com` (Alexis Cousein, SGI Belgium, 22 June 1999, "personal views"): USB
  routing, "second PCI bus, normally bus one", NT's HAL, the Bit3 expansion box. Treated as inferred.
- Usenet, `36B07AB2.7435F105@brussels.sgi.com` (Alexis Cousein, 28 January 1999): two 3.3 V PCI buses, 320 versus 540
  upgrade path.
- Usenet, `Pine.SGI.4.21.0008110042220.232700-100000@tantrik.engr.sgi.com` and `20000821225520.A25330@mr-happy.com`
  (August 2000): SGI never released the hardware specifications and said they "do not exist in a releasable form".
- The Lithium specification, revision of 15 December 1998, section 5.6.8, is quoted by name in the audio driver's
  comments. It is not held anywhere we can reach.

## SGI manuals held (read for this work)

- *Silicon Graphics 320 Visual Workstation Owner's Guide*, 007-3701-001, 152 pages: DIMM slot groups, the processor bus, ports and PCI bus summary (table A-3).
- *Silicon Graphics 540 Visual Workstation Owner's Guide*, 007-3882-001, 210 pages: DIMM slot groups A to D, one to four Xeons, two PCI buses of 4 and 2 slots with their voltages (table A-5).
- *Silicon Graphics Visual Workstations Software Installation Guide for Windows NT*, 007-3703-003 (1999, 40 pages): the boot partition rules and the graphics memory profile (pp. 31 to 38) read; the rest not used.
- *Silicon Graphics 320 and 540 Visual Workstation Audio/Video User's Guide*, 007-3870-001: held and read for the hardware features, audio and sync controls (chapters 1 to 3).
- Intel *82371AB PIIX4* Technical Product Specification, 290562-001 (April 1997), and Specification Update 297738-017 (January 2002): not SGI's, but the PIIX4 is the board's ISA bridge. Held and read for the port map, GPIO, A20 and CMOS routing; see [platforms/visws/boards-320-540.md](../platforms/visws/boards-320-540.md#the-byte-at-port-0xfb2).
- Not held: *SD1100* 007-3866-001 (a public web PDF).
- Articles read for the second Windows pass: the Microprocessor Report piece (15 February 1999) and the Tech Monitor piece (5 January 1999). What they and the guides say about the chips is set out in [platforms/visws/documents.md](../platforms/visws/documents.md).

Both owner's guides are user documents: no register, chip name or interrupt wiring appears in what was read. Page numbers are the printed ones.

## Missing

| Wanted | Why it matters | Route |
|---|---|---|
| The NT driver kit the guides name | Possible chip names for the audio and video paths | The Audio/Video User's Guide (007-3870-001) is held now and names no chips; the driver kit's site is gone. |
| A PROM or BIOS image other than 1.0002, 1.0004, 1.0005, 1.0006 and 1.1005 | PROM 1.1002 to 1.1004 and anything after 1.1005; a 540 image | Those five are held and compared ([firmware.md](../software/visws/firmware.md)); the rest are not held. |
| The NT HAL and miniport drivers | The interrupt map the Linux code gets wrong or never uses; Cobalt memory and error registers | Held now (Recovery CD-1 v1.1, install CD Disk 1, driver archive item; Windows 2000 RTM and SP4 CDs for the 2000 HAL and loaders); read in [nt-hal.md](../software/visws/nt-hal.md) and [nt-drivers.md](../software/visws/nt-drivers.md). Bank decoding (a Cobalt register fact the HAL never touches) and the 2000 drivers other than the HAL are unread. |
| The Cobalt, Lithium and Arsenic specifications | Everything the Linux code does not touch | SGI said none releasable. |
| A real boot log from a 320 or 540 under Linux 2.4 or 2.6 | The values the kernel prints: Lithium bus numbers, Cobalt revision, APIC ID, board type and revision | A search of the held mail and news archives found none. |
| NetBSD, OpenBSD or FreeBSD ports | A second reading | None exists as far as the held trees show: a text search of the NetBSD, OpenBSD and OpenBSD/sgi trees finds only a line in an ACPICA change log that says not to use ACPI on a VISWS. |
