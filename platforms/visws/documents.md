# Visual Workstation 320 and 540: what the published documents say about the chips

The documents that talk about the chip set at all, set against what the shipped Windows software and firmware show.
None of them has a register, an address or a pin: SGI never released the chip specifications
([sources](../../references/visws-sources.md)). Document statements are **established** as statements of that document (what
it says, not that the hardware does it); where a statement is a journalist's relay, that is said. Page numbers are the
printed ones. Grades for the cross-check column follow the [README](README.md).

## The documents

| Short name | Title, number, date |
|---|---|
| MPR article | Peter N. Glaskowsky, "SGI Chip Set Powers NT Workstations", *Microprocessor Report*, MicroDesign Resources, 15 February 1999 (pp. 1 to 3) |
| Tech Monitor piece | William Fellows, "SGI mixes Lithium, Cobalt, Arsenic in NT workstations", Computer Business Review (Tech Monitor), 5 January 1999; the text relays an unnamed enthusiast site |
| 320 guide | *Silicon Graphics 320 Visual Workstation Owner's Guide*, 007-3701-001 |
| 540 guide | *Silicon Graphics 540 Visual Workstation Owner's Guide*, 007-3882-001 |
| Install guide | *Silicon Graphics Visual Workstations Software Installation Guide for Windows NT*, 007-3703-003 (1999) |
| A/V guide | *Silicon Graphics 320 and 540 Visual Workstation Audio/Video User's Guide*, 007-3870-001 |
| PIIX4 datasheet | Intel, *82371AB PCI-to-ISA/IDE Xcelerator (PIIX4)* Technical Product Specification, 290562-001, April 1997 (an Intel part, not an SGI document) |
| PIIX4 spec update | Intel, *82371AB, 82371EB, 82371MB PIIX4 Specification Update*, 297738-017, January 2002 |

## What they say about the chips

| Statement | Source | What the Windows side shows | Result |
|---|---|---|---|
| The two machines share one chip set implementing a unified memory architecture; the 3D engine reads all of main memory; "your system RAM is your video RAM" | MPR article p. 1 and p. 2; Tech Monitor piece | The HAL gets graphics memory as firmware memory descriptors of one special type carved from the same banks as NT's memory ([nt-hal.md](../../software/visws/nt-hal.md#memory-banks-and-the-graphics-split)); the miniport asks for the split with the `cogfxmem` variable | Agree |
| Main-memory bandwidth 3.2 GB/s from a 100 MHz, non-interleaved, 256-bit SDRAM array; 800 MB/s to the processors, 1.6 GB/s to the I/O side, the rest for graphics | MPR article p. 1 | The HAL does not program memory timing or width; the only memory-controller registers it uses are ECC enable and error status. The firmware sizes memory from sixteen bank registers (not a Windows fact) | Not testable from Windows; consistent with the 32-bank registry layout (an array of banks) |
| Memory: 100 MHz SDRAM, 320 up to 1 GB, 540 up to 2 GB | MPR article p. 1 and p. 2; 320 guide ch. 3 and appendix A; 540 guide ch. 3 and appendix A | Nothing in the HAL limits memory below that; its bank list holds up to 32 entries | Agree |
| The processor bus is a P6 front-side bus; multiprocessor arbitration is Intel's | MPR article p. 1 | The HAL starts processors with the standard local APIC INIT and start-up IPIs and an MP-style processor table at `0x1e00` | Agree |
| Cobalt "optimizes the performance of OpenGL and GDI under NT, provides multi-processor rendering and enables dynamic allocation of graphics memory in system memory" | Tech Monitor piece | The rendering engine is driven from packet buffers in main memory by per-context scheduling ([graphics-engine.md](../../devices/cobalt-graphics/graphics-engine.md)); the graphics memory split is per boot, set in a control panel and applied after a restart (install guide pp. 35 to 38), not dynamic at run time | Agree, except that "dynamic" means changed by restart |
| The graphics geometry hardware does transforms and lighting for up to four lights; 7.4 Mtriangles/s and 176 Mpixels/s with trilinear texturing | MPR article p. 2 (vendor claims) | The context-shadow table has four packets of the same kind repeated four times, which matches four lights ([graphics-engine.md](../../devices/cobalt-graphics/graphics-engine.md)); the OpenGL driver clips on the host | The four-light structure agrees (inferred); where transform and lighting run is open |
| Arsenic "handles generating the display signal" (standard monitors, HDTV 1080P; stereo viewing due 2Q99) | Tech Monitor piece | The HAL's display back end block at `0xd0000000` uses `As` names (`_HalpAsBase`) and the miniport's pixel-format table carries `Arsenic` in its name | Agree; the display back end being Arsenic stays **inferred**, now with a document that says Arsenic produces the display signal |
| Lithium is "an implementation of the cross-bar chip used in SGI's Octane and Origin lines" with a 1.6 Gb/s crossbar that gives I/O, networking, video, audio, disk, IEEE 1394 and USB "a dedicated pipe" | Tech Monitor piece (relayed) | Lithium is two PCI bridges and the audio engine; the video capture driver pairs each of four video windows with control words in Lithium's audio page; no Windows code shows a crossbar | The crossbar claim has no support in any code and is not repeated as fact; the video words in Lithium's page agree with video passing through Lithium (inferred) |
| The Ethernet, audio and IEEE 1394 have "direct-access ports" to the memory controller; the video I/O ports likewise; some I/O is conventional PCI (the 33 MB/s Ultra-IDE; the 540's 64-bit Ultra2 SCSI) | MPR article p. 1 | Ethernet is found by its PCI id (Intel 8086:1229); IDE is the PIIX4's; the 1394 driver does not look on PCI at all but takes its resources from the registry; audio and video capture use fixed Lithium pages | The Ethernet is a PCI device on Lithium's bus in the driver's view (the "direct port" is the bridge's own memory path); the 1394 link is not PCI-enumerated, which fits a direct port (inferred) |
| The PCI bus is 3.3 V (3.3 V or Universal cards only) and 64-bit; 320 has three slots, 540 six | MPR article p. 2 and figure 1 | 540 guide table A-5: slots 1 to 4 take 5 V and Universal cards, slots 5 and 6 take 3.3 V and Universal; 320 guide appendix A | Conflict on voltage for the 540; the guide, written for the shipping machine, governs |
| The machine boots from a PROM, "instead of dragging the old BIOS dog" | Tech Monitor piece | ARC firmware: system parameter block and vector at `0x1000`/`0x1200`; both loaders call it only through ARC vectors ([boot-path.md](../../software/visws/boot-path.md)) | Agree |
| Boot files (`arcldr.exe`, `hal.dll`, `arcsetup.exe`) must sit in a FAT partition of at least 20 MB, the firmware cannot read NTFS; boot devices are named in the firmware's hardware inventory as "IDE 0, Disk 0, Partition n" and "SCSI 2, Disk 0, Partition n" | Install guide pp. 32 to 34 | The loaders read ARC names such as `multi(0)disk(0)fdisk(0)partition(0)` and, after 1.1002, `scsi()`; the HAL and loaders carry a FAT/NTFS path | Agree; "SCSI 2" shows the firmware numbers its IDE channels and SCSI buses in one list, its rule unknown |
| Graphics memory: Display control panel, "Silicon Graphics Settings", a memory reservation profile (up to the installed memory minus the 64 MB NT keeps); a restart applies a change | Install guide pp. 35 to 38 | The control panel's profile reaches the miniport as up to twelve bank sizes and goes to firmware as the `cogfxmem` variable ([nt-hal.md](../../software/visws/nt-hal.md#memory-banks-and-the-graphics-split)) | Agree |
| "Hardware support for audio and video synchronization"; an Audio/Video Sync panel; genlock source and delay controls; framelock | A/V guide ch. 1 (p. 2), ch. 2 (Audio/Video Sync panel) and ch. 3 (genlock, framelock) | Lithium carries a 64-bit microsecond counter (read by the system-time driver), a time stamp and media stream counter per audio channel, and video control pairs | Agree (same counters; the video-side meaning of the control words is unknown) |
| The audio hardware is a codec with no MIDI synthesis (a software synthesiser is bundled); CD-quality stereo line in and out, microphone, headphone; sample rates 44.1 kHz and 48 kHz offered | A/V guide ch. 1 and 2 | An Analog Devices AD1843 codec behind the Lithium serial link; the DMA engine moves 8- or 16-bit mono or stereo only | Agree; the guides do not name the codec |
| Two USB and two IEEE 1394 ports; "Windows NT 4.0 does not support IEEE 1394 devices" and the USB keyboard and mouse combination is the only supported USB device (320 guide); the 540 guide repeats the 1394 note | 320 guide ch. 1 (p. 8); 540 guide ch. 1 (p. 9) | The USB driver matches the PIIX4's controller and turns a USB keyboard and mouse into i8042 events; a 1394 driver (`Sgi1394.sys`) exists only in the later SGI package | Agree; the guides predate the 1394 driver |

## What the documents do not say

None names a register, a bus width other than "64-bit PCI", a chip revision, an interrupt number, a physical address,
the flash part or the number of DMA channels; none says how the memory controller decodes banks, how the Lithium bridges
split PCI memory, what ECC covers, or which board revision each model carries. The Windows 2000 setup file's four firmware machine
ids (`*SGI-3` to `*SGI-6`) and the NT 4.0 ids (`SGI-320_ARCx86[_mp]`, `SGI-540_ARCx86[_mp]`) are the only place the product line appears next to a
firmware identifier ([nt-hal.md](../../software/visws/nt-hal.md#the-windows-2000-builds)).
