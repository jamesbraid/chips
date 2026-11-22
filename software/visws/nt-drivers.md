# Visual Workstation 320 and 540: SGI's Windows drivers, at inventory level

What each SGI driver and setup file for the pair carries about the hardware it drives: the buses it finds the device on,
the physical windows it maps, the interrupt levels it asks the HAL for. The HAL itself is in [nt-hal.md](nt-hal.md), the
graphics driver in [devices/cobalt-graphics](../../devices/cobalt-graphics/nt-software.md). Binary names, strings, symbol
names and numbers only; nothing is copied. Grades as in the [README](README.md). Every item below was read in Ghidra from
the shipped binary, with the vendor's symbol names applied where a `.dbg` was shipped (graphics and HAL), and not
otherwise.

## What was read

| Package | Held as | Files used |
|---|---|---|
| SGI Recovery CD-1 v1.1 and SGI 320 Windows NT 4.0 install CD, Disk 1 (the two are the same NT 4.0 Service Pack 4 tree with SGI changes; the HAL, loader and drivers are byte-identical, the text-mode setup files differ in comments) | software mirror | `halborg.dll`, `halbrgup.dll`, `arcldr.exe`, `arcsetup.exe`, `sgcomp.sys` (older build), `sgcodd.dll`, `sgiusb00.sys`, `txtsetup.sif`, `dosnet.inf`, `syssetup.inf`, and the symbol tree |
| SGI Cobalt Graphics 5.2.4 for NT 4.0 and Windows 2000 (Internet Archive item `sgi_320_540_drivers`) | software mirror | `sgcomp.sys` 5.2.4, `sgcodd.dll`, `sgcoicd.dll`, `sgiFP.dll`, `sgcotab.cpl`, symbol files |
| SGI Digital Media Software 5.2.2 for NT 4.0 and Windows 2000 (same item) | software mirror | `sgisound.sys`, `sgilivid.sys`, `sgiust.sys`, `sgisound.dll`, the audio and video control panels, Video for Windows codecs, QuickTime components |
| SGI Ethernet 4.01.75 (same item) | software mirror | `sgienet.inf`, `sgincen5.sys` |
| SGI IEEE 1394 (same item) | software mirror | `Sgi1394.sys` 1.0, `RadDVDev.sys` and the DV libraries |

Windows 2000 builds of the graphics and digital-media packages were unpacked but not read; their file lists broadly match the
NT 4.0 ones.
The NT 4.0 install CDs carry no text-mode OEM override under another name: the HAL and setup changes are made in place in
the stock NT 4.0 tree, as below.

## Text-mode setup and the system tree

The setup files are the stock NT 4.0 ones edited by SGI (every changed line is marked with an "SGI" comment). Established:

- Alpha, MIPS and PowerPC source lists, the old x86 HALs' loader entries and `ntdetect.com`/`setupldr.bin` are commented
  out. The only computer types are `sgiborg_up` and `sgiborg_mp`; the machine identifiers are listed in
  [boot-path.md](boot-path.md). Setup's HAL-load step names `arcsetup.exe`, with a comment saying it is a placeholder.
- `halbrgup.dll` becomes `hal.dll` for the uniprocessor type and `halborg.dll` for the multiprocessor type. A second table lists
  `halborg.dll` for both types (its use was not read).
- Display: `sgcomp` ("Cobalt Graphics") is the only entry in the display map, with `sgcodd.dll`; its registry device
  values add the installed display driver and the `VgaCompatible` marker. Mouse and keyboard: a "USB PS2 Mouse"
  choice that installs `sgiusb00.sys` (the same driver serves keyboard and mouse).
- The `atapi` service gets `DriverParameters = "LevelSensitive=1"`: the IDE channels are wired as level-triggered lines, as
  the HAL's interrupt tables also say ([nt-hal.md](nt-hal.md)).
- SGI shipped its own build of several stock NT 4.0 programs (the symbol tree has SGI-specific `.dbg` files for `atapi.sys`,
  `setupdd.sys`, `ntvdm.exe`, `rdisk.exe`, `winnt32.exe` and `sysdm.cpl`); what each change does was not read.

## Audio: `sgisound.sys` 5.2.2

Hardware access is in [devices/lithium](../../devices/lithium/README.md#what-sgis-nt-audio-driver-confirms-sgisoundsys-522).
It does not enumerate PCI: it maps three fixed Lithium pages and reports its own resource use. Imports no interrupt-connect
call. Established.

## Unadjusted system time: `sgiust.sys` 5.2.2

A 3.5 KB driver. It creates `\Device\Sgiust` and the link `\DosDevices\SGIUST`, maps the eight bytes at `0xff001200` (the
Lithium window's `+0x200`, the 64-bit counter Linux calls unadjusted system time), writes zero to both words at load, and
answers a control request by mapping that page into the caller's address space through `\Device\PhysicalMemory` so that
user code can read the counter directly. Established. So the counter is writable and is not reset by anything else at
boot; whether it counts microseconds (Linux's comment) is not measured.

## Video capture and output: `sgilivid.sys` 5.2.2

Imports connect-interrupt, `HalGetInterruptVector` and `MmMapIoSpace`; no PCI calls. Its set-up routine takes one of four
channel windows and gives each a bus-0 interrupt level and a pair of control words in the Lithium window. Established:

| Channel window (`0x80` bytes) | Lithium control pair (8 bytes) | Interrupt level asked of the HAL |
|---|---|---|
| `0xf8000000` | `0xff001350` | `0x10` (16) |
| `0xf9000000` | `0xff001358` | `0x11` (17) |
| `0xfa000000` | `0xff001340` | `0x12` (18) |
| `0xfb000000` | `0xff001348` | `0x13` (19) |

It also maps `0xff001200`, the system-time counter above, which it reads to time-stamp frames (inferred from the mapping and
the pairing with the counter's second word at `+4`; the read sites were not followed). The levels 16 to 19 are the Cobalt entries Linux names
as the two video outputs and two video inputs (16 and 17, 18 and 19): the HAL's translation of level to entry was not read,
so equality of level and entry is inferred. The Lithium window offsets `+0x340` to `+0x35f` are not in Linux's register file
and not documented anywhere else we hold. The windows at `0xf8000000` to `0xfb000000` are decoded by an ASIC that no page
here has placed (Cobalt, Lithium or Arsenic); unknown. A first-time set-up of the first channel writes five indexed values
(`0x000b408a`, `0x000b408a`, `0x0023f806`, `0x0033f407` and a two-step enable `0`, `3`) through a helper whose register target was
not followed.

## Ethernet: `sgincen5.sys` 4.01.75 and `sgienet.inf`

An NDIS 4 miniport (Intel's PRO/100 driver, `E100BNT` in its debug strings, re-labelled by SGI). The setup file matches
`PCI\VEN_8086&DEV_1229` with revision `01` and `02` and subsystem `0000`, titled "Integrated 8255x-based PCI integrated
adapter, SGI Visual Workstation 320/540". A third line for revision `08` with the label for the 540 is commented out (and
misspelled `SYBSYS`). Established for the match; so the on-board Ethernet is an Intel 82557 or 82558 class part on the
Lithium bridge A, as Linux's header says, and the 540's part, if different, is not covered by this package.

## USB: `sgiusb00.sys`

A USB host-controller driver that turns a boot-protocol keyboard and mouse into the i8042 events NT's keyboard and mouse stack
expect (its strings include a usage-to-i8042 scan-code translation, a watchdog for missed interrupts, and "USB PS2 Mouse" in
setup). Established:

- It scans PCI buses 0 upward, devices 0 to 31 and functions 0 to 7 by `HalGetBusData`, and accepts vendor `0x8086` with device
  `0x7112` (the PIIX4 USB function) or `0x7020` (the PIIX3 one; revision 0 prints "UNSUPPORTED USB CONTROLLER" but is still used).
  This agrees with Linux's "PIIX4 USB on bus 0, slot 4".
- The controller's registers are used through I/O ports (UHCI-style: command and status halfwords at the base and `+0x02`,
  port status at `+0x10` and `+0x12`).
- It maps Lithium bridge B's window (`0xfd000000`, `0x70` bytes) and writes all ones to the word at `+0x48`, described under
  [Lithium](../../devices/lithium/README.md#the-bridge-window-established); its watchdog prints "PCI Error Status" and the
  address of the error.
- It asks the HAL for the interrupt vector and uses the firmware's environment (`HalGetEnvironmentVariable`) for its
  settings.

## IEEE 1394: `Sgi1394.sys` 1.0 and `RadDVDev.sys`

Built from a project tree named for the Lithium ASIC (the debug strings carry the source paths `Src_SGI_Driver\Lithium\...`,
and a commercial driver-kit banner of 1996-97) with IOCTL names that mention a PCILynx-style isochronous engine
(`IOCTL_LYNX_ISO_*`). It does not look the device up on PCI: its physical base address, size and interrupt come from its
own registry key (the error text "information needed to start device is missing from the registry"), so the hardware's
identity is not in the driver. Whether the 1394 link of these machines is on board or on a card, and which chip it is, is
unknown; the driver says nothing about either. `RadDVDev.sys` and its libraries are a DV camera layer above it.

## Still to read

In order: the audio driver's DMA control and configuration registers (settles the rest of the Lithium audio register file);
the HAL's interrupt-level translation for the internal bus (settles level versus entry for the video lines); the registry
values the graphics miniport reads and the HAL writes for the video and audio hardware (`HalpFixupRegistry`); `arcsetup.exe`,
the setup placeholder; the Windows 2000 builds of all of the above; and the second install CD's driver set when it is
reached.
