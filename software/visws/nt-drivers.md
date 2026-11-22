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
| SGI Digital Media Software 5.2.2 for NT 4.0 and Windows 2000 (same item) | software mirror | `sgisound.sys`, `sgilivid.sys`, `sgiust.sys`, `sgijack.sys`, `sgisound.dll`, the audio and video control panels, Video for Windows codecs, QuickTime components |
| SGI Ethernet 4.01.75 (same item) | software mirror | `sgienet.inf`, `sgincen5.sys`, the release note |
| SGI IEEE 1394 (same item) | software mirror | `Sgi1394.sys` 1.0, `RadDVDev.sys` and the DV libraries |

The InstallShield wrapper of each pack is opened with the RE image's `7z` and `unshield` (`7z x` the installer, then `unshield x data1.hdr`); the
symbol trees inside the packs carry `.pdb` files whose CodeView 2.0 symbol records name the routines, which is what the vendor names below come from.
Windows 2000 builds of the graphics and digital-media packages are separate binaries with different sizes from the NT 4.0 ones (for example `sgcomp.sys` is 65,808
bytes there and 62,992 here); see [the Windows 2000 section](#windows-2000-builds-and-the-w2k-only-files).
The NT 4.0 install CDs carry no text-mode OEM override under another name: the HAL and setup changes are made in place in
the stock NT 4.0 tree, as below.

## Text-mode setup and the system tree

The setup files are the stock NT 4.0 ones edited by SGI (every changed line is marked with an "SGI" comment). Established:

- Alpha, MIPS and PowerPC source lists, the old x86 HALs' loader entries and `ntdetect.com`/`setupldr.bin` are commented
  out. The only computer types are `sgiborg_up` and `sgiborg_mp`; the machine identifiers are listed in
  [boot-path.md](boot-path.md). Setup's HAL-load step names `arcsetup.exe`, with a comment saying it is a placeholder. The file is not one: `arcsetup.exe` is the ARC build of NT's text-mode setup loader (its strings carry the stock setup loader's source names `arcdisp.c`, `arcdtect.c`, `oemdisk.c`, `parseini.c` and `setup.c`, it loads `setupreg.hiv`, `sgiusb00.sys` and the storage drivers, and it reaches the firmware only through the vectors listed in [boot-path.md](boot-path.md)); the firmware runs it in place of `arcldr.exe` when booting the install CD (inferred from the setup file's loader table; the CD's boot sequence was not traced).
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

Hardware access is in [devices/lithium](../../devices/lithium/README.md#what-sgis-nt-audio-driver-confirms-sgisoundsys-522), including the DMA control, configuration and counter registers (read in full with SGI's symbols, second reading).
It does not enumerate PCI: it maps three fixed Lithium pages and reports its own resource use. Imports no interrupt-connect
call. Established.

Third reading, of the 5.2.2 build itself (build time 2001-10-29, the Digital Media 5.2.2 pack, unpacked with an InstallShield extractor; the
earlier review could read only the 1999 build). Every register fact in the Lithium page was checked against this build and held: the
three page addresses, the codec command word at `+0x18` and data word at `+0x1c` (a write stores the data first, then the register number;
a read stores the number with `0x80`, waits for bit 15 to clear, reads the data), the busy wait of up to 36,000 ten-microsecond stalls (after
a timeout the driver sets a flag and never waits again), the seven-row register table (the bytes of the table itself were dumped and match
row for row), ring base `address >> 8 | 0x20000000`, configuration bits (bit 2 stereo, bit 3 output, format in bits 1:0), control size code 7 for an
8 KiB ring and 6 otherwise with the enable in bit 27 set last, the silence word before the enable, the output-only zeroing of `+0x98`
and `+0x9c` of the second page, the single-byte pointers (output: software writes control `+0`, hardware read from control `+1`; input the
other way round), and the link check on bit 2. Two details were missing from the page and are added there: the global 64-bit counter used
for the time-stamp pair is read as `+0x204` (high word) before and after the channel's time stamp and re-read until the two highs agree, and
the output counter written to zero at start is the word at `+0x30c`, the input one `+0x304`. The 1999 build (28,720 bytes, build 1999-04-27,
Recovery CD-2 v1.1) carries the same register table at a different address and the same page constants; it was not read function by function.

## Unadjusted system time: `sgiust.sys` 5.2.2

A 3.5 KB driver. It creates `\Device\Sgiust` and the link `\DosDevices\SGIUST`, maps the eight bytes at `0xff001200` (the
Lithium window's `+0x200`, the 64-bit counter Linux calls unadjusted system time), writes zero to both words at load, and
answers three control requests. Read from the 5.2.2 build in full. Established:

| Code | What it does |
|---|---|
| `0x220000` | reads the counter for a kernel caller: the high word at `+4` first, then the low word at `+0` and the high word again, repeated until the two high reads agree; it returns the 64-bit value multiplied by 1000 |
| `0x220004` | maps the page holding the counter into the caller's process through `\Device\PhysicalMemory`, read-write and uncached, and returns the pointer to the eight bytes |
| `0x220008` | unmaps that view |

So the counter is writable and is not reset by anything else at boot. The multiplication by 1000 on the kernel-mode read gives nanoseconds if the counter counts microseconds, as Linux's comment
says (a software expectation of the driver; the rate itself has not been measured). The counter's low half is the first word of the pair; the high half is `ust_high` in the audio driver, at `+0x204`. The
1999 build (2,704 bytes) has the same three codes, the same address and the same factor of 1000 (constants found in its image; not read
function by function).

## Video capture and output: `sgilivid.sys` 5.2.2

Imports connect-interrupt, `HalGetInterruptVector` and `MmMapIoSpace`; no PCI calls. Its set-up routine takes one of four
channel windows and gives each a bus-0 interrupt level and a pair of control words in the Lithium window. Established:

| Channel window (`0x80` bytes) | Lithium control pair (8 bytes) | Interrupt level asked of the HAL |
|---|---|---|
| `0xf8000000` | `0xff001350` | `0x10` (16) |
| `0xf9000000` | `0xff001358` | `0x11` (17) |
| `0xfa000000` | `0xff001340` | `0x12` (18) |
| `0xfb000000` | `0xff001348` | `0x13` (19) |

The windows, control pairs and levels above were checked again in the 5.2.2 build (the same table of four, in the same order). Which window
is which direction is in the driver's own device names: `\Device\sgilivideoout1` is `0xf8000000`, `sgilivideoout2` `0xf9000000`,
`sgilivideoin1` `0xfa000000` and `sgilivideoin2` `0xfb000000` (established), matching the levels 16 and 17 for the two video outputs and 18
and 19 for the two inputs that Linux names. The set-up routine (`0x1044c`, called once per channel) also maps `0xff001200` (the system-time counter above)
for eight bytes, so there are four separate mappings of the one block, not one shared view, and reads it to time-stamp every frame. Established: the driver never writes it
(its only register stores go to the channel window and to the pair; `InitMsc` `0x11668` zeroes the pair's two words).

**The channel window is a register file with an eight-byte stride** (read from the 5.2.2 build with its symbols; register `n` is at window
`+8n`, 32 bits wide; the driver has three helpers named `PIOReadLi` (read and mask), `PIOWriteLiReg` (write) and `PIOWriteLiValue` (read, clear a
mask, set bits)). Established as use; the meaning of each is the driver's naming and the use, so a software expectation:

| Register | Offset | What the driver does |
|---|---|---|
| 0 | `+0x00` | the channel control and enable: written `0x1003` to start an input channel and `3` to start an output channel, `0` to stop (the stop routine also writes register 3 to zero); the interrupt handler reads it first and treats zero as "not mine" |
| 1 | `+0x08` | status: bit 1 means a frame or field event is pending and the handler loops on it; bit `0x1000` is a second event the handler reports; one parity bit (bit 17 on an input, bit 12 on an output) is compared with the driver's own field counter. `InitMsc` reads it once; whether that read clears anything is unknown |
| 2 | `+0x10` | written `0` then `3` when each output channel is created |
| 3 | `+0x18` | the next descriptor address: `ProgramLiNDA` writes the address of the next buffer descriptor with the flag bits `6` or'ed in (`7` when its last argument is non-zero); the handler reads it back to learn where the engine stopped |
| 8 to `0xb` | `+0x40` to `+0x58` | written once with `0x000b408a`, `0x000b408a`, `0x0023f806` and `0x0033f407` when each output channel is created (the five values the earlier reading listed without a register: they go to registers 8, 9, 10 and 11, then register 2) |
| `0x10` | `+0x80` | the genlock delay (`ProgramGenlockDelay` writes it on the two output channels) |
| `0x11` | `+0x88` | a global configuration word, read-modify-written by `ProgramGlobalConfig` from the caller's configuration record: separate bits for each input source, standard and output option (the driver builds it from about fifteen flags). It lies past the `0x80`-byte window the channels map; a separate "global" device maps `0xf8000000` for `0x90` bytes to reach it |

The control pair in the Lithium window is a time stamp and a counter: word 0 is the channel's UST stamp (`ReadUst` reads it and
combines it with the high half of the system-time counter), word 1 is the media stream counter (`ReadMsc`: bits 31:1 are the count, bit 0 a
flag; the driver extends it to 64 bits in software and `InitMsc` writes both words to zero). That is the same pair-of-words shape the audio engine
has at `+0x300` and `+0x304`. The system-time counter is read through `ReadSysUst` (re-reading the high word at `+0x204` until it
agrees) and scaled by 1000 in `ReadSysUst64`, as in `sgiust.sys`.

`ReadSysUst` (`0x11698`; `0x115b8` in the Windows 2000 build) reads the high word, then the low word, then the high word again, and starts again from the low word
when the two high reads differ (against the first high read, which it does not refresh) or when the low word's low 16 bits are `0xffff`. `sgiust.sys`'s kernel read (`0x10489`;
`0x10443` in the Windows 2000 build) uses the same three reads but the opposite exit: it starts again on a changed high word unless the low halfword is `0xffff`, in which case it
keeps the second high word. Neither is explained by a comment in any build; that both drivers single out a low halfword of `0xffff` points to a carry hazard in the hardware's
two-word read, a software expectation only ([open question](../../questions/visws-audio-open.md#9-the-system-time-counter-low-halfword-rule-and-reset)).

The levels 16 to 19 are connected through `IoConnectInterrupt` on the HAL's vectors, and the code computes the highest interrupt priority
over the four levels (`FindMaxInterruptIrql`) to synchronise with all of them. The Lithium window offsets `+0x340` to `+0x35f` are not in Linux's register file
and not documented anywhere else we hold. The windows at `0xf8000000` to `0xfb000000` are decoded by an ASIC that no page
here has placed (Cobalt, Lithium or Arsenic); unknown. Descriptor and buffer layouts, the format records and the meaning of the bits of
registers 1 and `0x11` were not decoded. The 1999 build (17,936 bytes, Recovery CD-2 v1.1) has the same window, pair and first-time
constants (found in its image); it was not read function by function.

## Ethernet: `sgincen5.sys` and `sgienet.inf` (package 4.01.75)

An NDIS miniport (Intel's PRO/100 driver, `E100BNT` in its debug strings, re-labelled by SGI). Read from the package's own files. The
driver registers itself as an **NDIS 5.0** miniport (the characteristics record it hands to `NdisMRegisterMiniport` has major version 5 and the 5.0
size, `0x60`), not NDIS 4 as an earlier version of this page said, and the setup file's upper range is `ndis5`; the INF is dated 27 March 2000
(driver version `1.1.1.001`) though the package is numbered 4.01.75. Established.

The setup file matches `PCI\VEN_8086&DEV_1229` with subsystem `0000` and revision `01` or `02`, and gives the entry the name "Silicon Graphics
320 Integrated 82557 Ethernet". A third line, for revision `08`, names "Silicon Graphics 540 Integrated 82559 Ethernet", but it is commented out
and misspelled (`SYBSYS`), so it can never match as shipped. Established for the strings and the match. So SGI's own setup file says the
320's on-board part is an Intel 82557 (revisions 1 and 2) on the Lithium bridge A, as Linux's header says, and that the 540's is an 82559 at
revision 8 (the setup file's naming, not a measured identity; the row is disabled, so the 540's Ethernet is not covered by this package as
shipped). The service is "SGI Ethernet Driver for Intel 8255x"; its tunables (receive frame descriptors default 48, transmit control blocks 32, coalesce buffers
8) are Intel's.

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

## Analogue video option: `sgijack.sys` 5.2.2 ("Jack Video Interface")

Not in any earlier page. A 19.6 KB driver in the Digital Media 5.2.2 pack (a 15 KB 1999 build is on Recovery CD-2 v1.1), read in Ghidra with
its symbols. It drives an optional analogue video board over I2C; strings and tables are the evidence. Established unless noted:

- It creates a main device and eighteen further control devices, and keeps a table of three I2C chips by 8-bit
  write address: `0x48` ("Video Decoder", registers `0x00` to `0x1f`), `0x88` ("Video Encoder", registers `0x26` to `0x7f`) and `0x40` ("i2c Expander", one register). The
  register names are a long list in the driver: for the decoder a chip version at 0, four analogue-input controls, sync start and stop, luminance
  brightness and contrast, chroma saturation and hue, output controls, a status register and a text slicer; for the encoder subcarrier phase bytes, burst
  amplitude and window, closed-caption, teletext and wide-screen-signalling fields, copy-guard, colour gain and black level. That these two are Philips
  SAA7111-class and SAA7121-class parts is inferred from the register names and the addresses; the driver names no part number.
- The host side is an I2C master at physical `0xff005000`, `0x20` bytes (`MmMapIoSpace`), 32-bit registers; the byte-write path uses `+0x10` (transfer status and
  control, polled for completion with an "Xfer Done timeout" error) and `+0x18` (the data byte), a reset writes `0x80` at `+0x00`, and the control
  get and set calls read and write 32-bit registers at `base + index`. The wait routines report "wait for ack timeout", "Idle Timeout" and "Bus Error".
  That window is not in any Lithium table here and the ASIC that decodes it is unknown.
- The driver asks the firmware whether the board is present: it reads the ARC `SystemBiosDate` and treats a 1998 date with a month of 9 or less and a day of 16 or less as "no board" (a crude test for old firmware), then
  searches the ARC `MultifunctionAdapter` entries for the identifier "SGI REV INFO" and reads the configuration data of adapter 3 (a non-zero word at
  `+0x20` counts as present) (inferred from the decompiled code; not traced against the firmware's tree). Two firmware environment variables override it, read through
  `HalGetEnvironmentVariable`: `ForceOptionBoard` and `AnalogVideo`, each true when the value is `y`. Defaults come from, and board information goes to, the
  registry.

## Hardware error log: `sgielog.sys` (1999 build)

A 6 KB driver on Recovery CD-2 v1.1, read in Ghidra without symbols. It creates `\Device\Sgielog` and `\DosDevices\Sgielog`, queries the HAL
for the callback-registration entry through the HAL dispatch table (information class `0x8100002`, the one the [HAL page](nt-hal.md#the-sgi-specific-hal-interface)
lists as a pointer to `sgixCallbackRegister`), registers a callback with id 1, and turns what the HAL reports into event-log entries. The message texts it carries are:
the system restarted after an uncorrectable memory ECC error at an address, during an operation, from a source; restarted after an access to
invalid memory; a corrected ECC error in a named DIMM; an ECC error with syndrome zero ignored. At start-up it also reads a 12-byte record
from the CMOS (`HalGetBusData` with data type CMOS, offset `0x50`) and, if it is non-zero, reports it and writes zeros back with `HalSetBusData`; that is how an
error recorded before a restart reaches the log on the next boot (inferred from the call pattern; who writes the record is the HAL's side, not read). Established for the texts and the registration; the HAL's side of the record is not read.

## Katmai state saver: `intlfxsr.sys` (Recovery CD-2 v1.1)

A 6.4 KB Intel driver (build time 8 December 1998) that checks for "GenuineIntel" and the FXSR feature, then hooks thread creation and context
switching (`PsSetCreateThreadNotifyRoutine`, `KeSetSwapContextNotifyRoutine`, `PsSetLegoNotifyRoutine`) so that NT 4.0, which does not know the SSE register state of the Pentium III
("Katmai"), saves it per thread. It touches no SGI hardware. Established for the strings and imports, inferred for the behaviour.

## Windows 2000 builds and the W2K-only files

Windows 2000 RTM (build 2195, CD dated 7 December 1999) carries SGI support in its own `\I386\` tree, not in an SGI pack. SP4 (build 2195.6717)
ships byte-identical copies of the files below except `halborg.dll` (SHA-256 prefixes compared). `txtsetup.sif` lists them under the machine type `sgiborg_mp`
(firmware ids `*SGI-3` to `*SGI-6`, see [boot-path.md](boot-path.md)):

| File (size, build time) | Role in `txtsetup.sif` | What it is |
|---|---|---|
| `halborg.dll` (148,672, 1999-10-30) | copied as `hal.dll` | the HAL ([nt-hal.md](nt-hal.md#the-windows-2000-builds)) |
| `sgibvid.dll` (10,176, 1999-11-04) | copied as `bootvid.dll` | boot video driver, below |
| `sglfb.sys` (6,992, 1999-10-11), `sglfb.dll` (9,136, 1999-11-30) | the display type "Cobalt Graphics" | linear frame buffer miniport and display driver, below |
| `sgiu.inf`, `sgiulnt5.sys` (97,808, 1999-10-29), `sgiul50.dll` (493,424, 1999-11-30), in `driver.cab` | none | a Trident PCI display driver with SGI-prefixed names, below |

There is no SGI USB driver on the Windows 2000 CD: `dosnet.inf` describes `sgiusb00` as "(for NT 4.0 only)", so Windows 2000 uses its stock USB stack for the
keyboard and mouse on the PIIX4 function.

**`sgibvid.dll`, `sglfb.sys` and `sglfb.dll`: the Windows 2000 boot video and "Cobalt Graphics" display drivers.** They program only the display back end, so the reading moved to the cobalt repository: [software/windows/w2k-display-drivers.md](https://github.com/jamesbraid/cobalt/blob/main/software/windows/w2k-display-drivers.md).

**`sgiu.inf`, `sgiulnt5.sys`, `sgiul50.dll`: a Trident display driver. Established as identification, unknown as to purpose.** The file named `sgiu.inf` is, in its
header and strings, `Trident.inf` for the "Trident series of graphics adapters" (version `5.00.2029.0023`, 26 May 1999): it installs the miniport `sgiulnt5.sys` and display
driver `sgiul50.dll` and matches `PCI\VEN_1023` with device `9850`, `9750`, `9397`, `939A` and `9520`; devices `9540` and `9880` are commented out. The miniport's own
name table also lists the Cyber9525, Image975 and 985 DVD parts, Blade 3D, Monterey 3D and Carmel 3D, reads the card's ROM through `VideoPortGetRomImage`, and carries Trident's
"TVGA" strings. Nothing in it mentions Cobalt, Lithium, Arsenic or the SGI platform, and the machines' graphics are not on PCI, so it is not a driver for the on-board display. Why Microsoft
renamed a Trident driver with SGI-prefixed names is unknown (a Visual Workstation PCI card option is possible and not documented anywhere held).

## Recovery CD-2 v1.1 (disc 2 of the 540 set, built 5 May 1999)

Held in the software mirror (Internet Archive item `sgi-recovery-2`, 217,341,264 bytes) as a raw CD image with 2,352-byte sectors; the 2,048-byte payload of each of
its 92,407 sectors is an ordinary ISO 9660 image of 189,249,536 bytes (351 files, 40 folders), which compares byte-equal to the first 189,249,536 bytes of
`SGI320WinNT_Disk2.iso` in the `sgi-vw-drivers` item. So the "Disk 2" of the 320 NT 4.0 set and Recovery CD-2 v1.1 are the same disc. Its tag file says "Recovery
CD 2 Installation, version 1.0", and the `Oeminfo.ini` it installs reads "1-4 Processors, SP4 OPK" and "Version 4.0s1.1MR6". It is a software disc: no
firmware, no PROM image, no HAL. Its main cabinet (`data1.cab`, an InstallShield cabinet that `unshield` opens directly; 170 files) holds the SGI Windows software of May 1999.

| Group | Contents | Read |
|---|---|---|
| Graphics drivers | `sgcomp.sys` (65,296), `sgcodd.dll` (334,704), `sgcoicd.dll` (1,245,456), `sgcotab.cpl`; build time 1999-04-27 | `sgcomp.sys` and `sgcodd.dll` are byte-identical to the NT 4.0 install CD's; the escape table of the display driver is read ([graphics-engine.md](../../devices/cobalt-graphics/graphics-engine.md)); the OpenGL driver's call sites were not |
| Audio, video and time drivers | `sgisound.sys` (28,720), `sgilivid.sys` (17,936), `sgijack.sys` (15,216), `sgiust.sys` (2,704), `sgiacp`, `sgivcp` and their control panels; all 1999-04-27 | register constants and the audio register table checked against the 2001 builds (same table and same addresses); not read function by function |
| Hardware error log | `sgielog.sys` (6,256) | read, see above |
| Intel state saver | `intlfxsr.sys` (6,416, built 1998-12-08) in a "Katmai Driver" group | read, see above |
| Flat panel and power | `sgiFP.dll`, `PwrSave.exe`, `PwrSave.sgi`, `cysaver.scr` | strings only: the power saver calls `sgiFP_PowerSave` and keeps its setting under `Software\Silicon Graphics\Control Panel\Display` |
| Colour calibration | the ColorLock tool (`ColorLock.exe`, `ColorLock.cpl`, `SipCal32d.dll`, `CLDetect.exe`) | not read |
| Digital media and codecs | `sgidmedia.dll`, `sgidv.dll`, `sgicolor.dll`, `sgijpeg.dll`, `sgival.dll`, Video for Windows and QuickTime components, `vidcap32.exe`, `viddiag.exe` | not read |
| Documentation | the 320 and 540 owner's guides (PDF), the Audio/Video guide, a ColorLock guide, an HTML 320 overview, release notes | the guides are already held ([sources](../../references/visws-sources.md)); the release notes name only the graphics-memory profile and QLogic SCSI card instructions |
| Option installers | `ifl` (an image-format library with its source, headers and HTML reference), `opt` (the Cosmo 3D and OpenGL Optimizer developer kits), `Quicktime`, `AcrobatReader` (eight languages), `yamaha` (a soft synthesizer), `SGISOUND` (an older `oemsetup.inf` installer for the audio driver), and a `Symbols` tree of `.dbg` files | not read; the symbol tree has no `.pdb`, so the 1999 builds have no routine names |

The 1999 drivers are the same family as the NT 4.0 install CD's `sgcomp.sys` and `sgcodd.dll`, so the disc adds the other half of the 1999 set: the audio, video, time and analogue-video drivers, the
OpenGL driver and the error-log and Katmai drivers. It adds no register fact that the 2001 builds do not already give.

## Still to read

In order: the registry values the SGI 5.2.4 graphics miniport reads and the HAL writes (the HAL's are listed in [nt-hal.md](nt-hal.md#registry-values-the-hal-writes); the miniport's reads are not); the 1999 OpenGL driver's call sites of its escape (to confirm that the numbering of its display driver is the one it sends); the rest of `sgijack.sys` (the control devices, the registry defaults, the I2C register values the decoder and encoder are given); the descriptor and buffer formats and register bits of `sgilivid.sys`; the HAL's side of the CMOS record `sgielog.sys` reads; and the Windows 2000 builds of `sgcomp.sys`, `sgisound.sys`, `sgilivid.sys`, `sgiust.sys` and `sgijack.sys` (separate binaries from the NT 4.0 ones, only the display driver's escape table read). Done since the first reading: the HAL's interrupt-level translation (level is the Cobalt entry), `arcsetup.exe`, the audio driver's DMA registers, the Windows 2000 CD's SGI-specific files and Recovery CD-2 v1.1.
