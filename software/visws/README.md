# Visual Workstation 320 and 540: firmware and NT support software

What the SGI Visual Workstation 320 and 540 (Linux name `visws`; x86, Pentium II or III, Cobalt and Lithium chipset) run
below the operating system: the system firmware, the boot files it hands over to, the Windows NT 4.0 hardware abstraction
layer SGI wrote for the pair, and the public Linux boot code. The chips themselves are described elsewhere: the board
and its address map in [platforms/visws](../../platforms/visws/), Cobalt and Lithium under
[devices/cobalt](../../devices/cobalt/) and [devices/lithium](../../devices/lithium/), the graphics engine under
[devices/cobalt-graphics](../../devices/cobalt-graphics/). This directory only covers the software that programs them, and
what an emulator has to provide in place of the firmware. The platform pages hold the Linux-side view
([model-needs.md](../../platforms/visws/model-needs.md), [boot-and-detection.md](../../platforms/visws/boot-and-detection.md),
[interrupts.md](../../platforms/visws/interrupts.md)); where this directory's HAL reading settles a point they leave open, it says so.

Nothing here is copied from the binaries. Names are function, symbol, string and file names the shipped files carry;
addresses, offsets and numbers are quoted as facts.

**Grades.** *established*: read in full from a shipped binary (the whole routine or table), from the public Linux
source, or stated by a published document. *observed*: seen in a public first-hand report (a Usenet post, a console
capture), not independently confirmed. *software expectation*: what shipped software assumes of the hardware or
firmware; it says what must be provided, not that the hardware does it. *inferred*: a reasoned reading, reasoning
given. *unknown*: not settled; the route that would settle it is in
[questions/visws-firmware-open.md](../../questions/visws-firmware-open.md).

## Pages

| Page | Covers |
|---|---|
| [firmware.md](firmware.md) | What the firmware is (an ARC-style system, not a PC BIOS), the PROM 1.0006 image layout and module table, the version history, the flash part and its environment block, the update procedure |
| [boot-path.md](boot-path.md) | What the firmware leaves behind for NT and Linux: boot files, the ARC configuration tree, memory descriptors, the processor table, the memory and device map; what is not provided (no MP table, no E820) |
| [nt-hal.md](nt-hal.md) | The NT 4.0 HAL read function by function: Cobalt interrupt routing, timers, processor start, Lithium PCI access, error and power handling, flash environment access |
| [nt-drivers.md](nt-drivers.md) | SGI's other Windows drivers at inventory level: audio, system time, video capture, Ethernet, USB, IEEE 1394, and text-mode setup's HAL selection |
| [emulator-requirements.md](emulator-requirements.md) | What an emulator must provide to boot Linux and NT, and what is still unknown |

## What was read

| Source | Held | Use |
|---|---|---|
| System Firmware User's Guide for Windows NT, 007-4225-001 | yes (techpubs mirror) | Firmware identity, settings screens, update procedure |
| Silicon Graphics 320 and 540 owner's and installation guides (007-3701-001, 007-3882-001, 007-3703-003) | yes (techpubs mirror) | listed; not read |
| SGI Recovery CD-1 v1.1 (NT 4.0 SP4 image with SGI files; 497,657,856 bytes, sha256 `041f74f9…e0a40`) | yes (software mirror) | `halborg.dll`, `halbrgup.dll`, `arcldr.exe`, `arcsetup.exe`, `sgcomp.sys`, `sgiusb00.sys`, and the CodeView symbol files `halborg.dbg` and `halbrgup.dbg` |
| SGI 320 Windows NT 4.0 install CD, Disk 1 (Internet Archive item `sgi-vw-drivers`; same NT 4.0 SP4 tree as Recovery CD-1 with SGI setup changes) | yes (software mirror) | Byte-identical HAL, loader and driver files; `txtsetup.sif` HAL and machine-type entries ([nt-drivers.md](nt-drivers.md)) |
| Windows 2000 RTM (build 2195, English) and Windows 2000 SP4 install CDs (Internet Archive items) | yes (software mirror) | `\I386\halborg.dll`, `arcldr.exe`, `arcsetup.exe`, `txtsetup.sif` (SGI machine type `sgiborg_mp`, firmware ids `*SGI-3` to `*SGI-6`); compared with the NT 4.0 HAL and loaders in [nt-hal.md](nt-hal.md#the-windows-2000-builds) and [boot-path.md](boot-path.md). The CDs also carry the SGI-specific `sgibvid.dll` (boot video), `sglfb.sys` and `sglfb.dll` (the "Cobalt Graphics" display driver) and a Trident driver set under SGI-prefixed names (`sgiu.inf`, `sgiulnt5.sys`, `sgiul50.dll`), all read: [nt-drivers.md](nt-drivers.md#windows-2000-builds-and-the-w2k-only-files) |
| SGI Cobalt Graphics 5.2.4, Digital Media 5.2.2, Ethernet 4.01.75, IEEE 1394 driver packs (Internet Archive item `sgi_320_540_drivers`) | yes (software mirror) | The drivers in [nt-drivers.md](nt-drivers.md) and the graphics pages |
| SGI Recovery CD-2 v1.1 (217,341,264 bytes raw; the same disc as Disk 2 of the 320 NT 4.0 install set) | yes (software mirror, item `sgi-recovery-2`) | The 1999-04-27 builds of the SGI drivers, including the OpenGL driver, the audio, video, time and analogue-video drivers, an error-log driver and Intel's SSE state saver; inventoried in [nt-drivers.md](nt-drivers.md#recovery-cd-2-v11-disc-2-of-the-540-set-built-5-may-1999) |
| SGI Recovery CD-2 v1.0 (216,895,488 bytes; 547 files) | yes (software mirror) | Installer for the SGI drivers and utilities. Unpacked: its main cabinet (440 files, 24 file groups) holds drivers, DLLs, help, art work and documentation, and the two option installers hold an image-format library and a second development kit; there is no firmware item and no PROM image |
| SGI PROM 1.0006 update package for the 320 and 540 (`PROM1_0006.exe`, 480,058 bytes) | yes (software mirror of a public Internet Archive driver item) | The 512 KiB flash image, read in Ghidra and with objdump: [firmware.md](firmware.md), [boot-path.md](boot-path.md) |
| Public Linux source: Documentation/sgi-visws.txt, `visws_quirks.c`, `arch/x86/pci/visws.c`, the `asm/visws` headers, `smpboot_hooks.h` (history tree); 2.4 `arch/i386/kernel` (linux-mips tree) | yes | Linux boot expectations, graded established |
| SGI Linux for the workstations: Visual Workstation Environment 3.0, ProPack 1.3 Visual Workstation Edition (CD images) | yes | Unpacked: both target the 230, 330 and 550 (PC-BIOS) workstations, ship LILO-based installers and kernels built with the Visual Workstation option off, and carry no ARC loader; the kernel source packages carry the public visws platform code |
| Usenet: PROM release notes 1.0002 to 1.1005 (comp.sys.sgi.hardware, 2001-02-22, message `973u7b$jjr$03$1@news.t-online.com`); Linux install attempts (1999-09-23, `A7C09CFCAF83D2119C5000104B416CCF091C7D@theta.holmes.nl`; 2000-04-10, `8csntq$vku$1@nnrp1.deja.com`) | yes | Version history, firmware naming, Linux loader names |

**Found, and not found.** Only one firmware image is held, PROM 1.0006 (July 1999). Recovery CD-2 v1.0 was unpacked and
does not carry the firmware. No other PROM version, flash dump or ARC loader for Linux is held in the Library, the software
mirrors or the firmware registry. A 2005 Usenet thread (message
`1114131220.292399.255710@g14g2000cwa.googlegroups.com`) says the update files were downloadable from SGI's support site;
no stable address is on record. Facts about later versions (1.1002 to 1.1005) still come from the release notes and from
the software that talks to the firmware. Recovery CD v1.0 (1 to 2 processors) is not held; v1.1 (1 to 4 processors) is.

## Scope boundaries

The graphics driver `sgcomp.sys` and the Cobalt graphics engine belong to [devices/cobalt-graphics](../../devices/cobalt-graphics/).
Here the driver appears only where it interacts with firmware-reserved memory. The 230, 330 and 550 workstations use a
different (PC BIOS) platform and are not covered.
