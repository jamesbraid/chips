# Visual Workstation 320 and 540: the system firmware

The firmware images of PROM 1.0006 (July 1999) and PROM 1.1005 (July 2000) are held and read: SGI's update packages for the
320 and 540, each an InstallShield self-extractor that unpacks to a 512 KiB flash image. 1.1005 is the version a real
320's registry reports ([board data](https://github.com/jamesbraid/cobalt/blob/main/devices/cobalt-graphics/board-data.md)).
The versions between them are not held, so the version history below still rests on SGI's release notes. What the images
do at reset is in [boot-path.md](boot-path.md); this page covers what they are, how the image and its environment block are
laid out, how it is updated and [what changed from 1.0006 to 1.1005](#from-10006-to-11005). Grades as in the README.
Image offsets are flash offsets: the flash is mapped at `0xfff80000`, so flash offset `0x7c000` is physical `0xffffc000`.

**Citation form.** `1.0006@0xf04a70` and `1.1005@0x1104840` are virtual addresses of the main module as the boot block
loads it (1.0006 at `0xf00000`, 1.1005 at `0x1100000`; the three data sections follow the table below). `1.0006:flash+0x7c000`
is a flash offset. `1.0006:test+0x96f7` is an offset in the self-test module (see [below](#the-self-test-module)), which
runs from flash at `0xffff0000` plus that offset. Tools: the container's Ghidra for the main module (language x86 32-bit
flat, base as above), x86 32-bit flat for the self-test module past its first `0x2c` bytes, which are 16-bit code run as in
the boot block (listed with objdump, `i8086`); objdump `i386` cross-checked every register constant quoted.

## What it is

1. **An ARC-style firmware, not a PC BIOS. Established (guide; HAL and loader read).** The firmware guide speaks of
   "the PROM", "the system firmware" and its "Hardware Inventory" panel, and names the NT boot files by their ARC roles:
   the OS loader, `arcldr.exe`, and `hal.dll`, kept on a "system partition" (partition 2 by default) with the kernel on
   an "OSLoad partition" (partition 1). The loader (`arcldr.exe`, banner "ARCx86 OS Loader V4.0") and the HAL both
   speak ARC: the loader names its environment variables `systempartition`, `osloader`, `osloadpartition`,
   `osloadfilename` and `osloadoptions` and complains about "unimplemented firmware vector" calls; the HAL builds its
   configuration from an ARC tree found in the NT loader block. A Usenet hardware-inventory screen from a 540
   (1999-09-23) reports the system as `SGI_ARCx86_mp` with firmware `1.006`. Observed.
2. **No BIOS tables. Established (Linux source).** The Linux port states that the machine is Intel MP compliant in
   the hardware sense "but it doesn't have a BIOS(-configuration table)", and takes no memory map from firmware
   ([boot-path.md](boot-path.md)). So the firmware does not provide an MP table, an E820 call or the usual
   BIOS services to the OS.
3. **It does carry some PC-compatible pieces. Established (PROM 1.0006 strings and code; HAL read).** The HAL has
   real-mode and V86 thunks (`HalpBiosCall`), a VGA text path next to the Cobalt graphics path, and programs the legacy
   chips (PIIX4, NS87307, 8259, CMOS RTC) directly. The 1.0006 image carries a legacy-BIOS image in its data module (a
   "Main BIOS" banner, an "IBM COMPATIBLE" signature string and the usual PC fatal-error messages), 8042 keyboard-controller
   emulation strings, and names for a V86 BIOS layer and the variables `DosBoot`, `Vx86DoNotRunBIOS`
   and `Vx86DebugLevel`. They suggest the firmware runs real-mode code under a V86 layer (inferred from the names); where the BIOS image is mapped, and whether any
   of it is visible to NT or Linux, was not traced (unknown). It also embeds an SMBIOS (DMI) table reader and a monitor
   command set (below).
4. **Product names.** The HAL carries the strings "Silicon Graphics 320" and "Silicon Graphics 540" and two ARC
   configuration nodes under the system node: "SGI REV INFO", with children "SYS TYPE" and "BOARD REV". HAL reads
   both as single bytes. Established. The hardware names "Borg" (the Cobalt platform, from the HAL's file name and
   string) and "Twibble" (an unexplained node string) also occur; "Hugh" appears as the name of an interrupt routing
   mode (see [nt-hal.md](nt-hal.md)). What these denote is unknown.

## The PROM 1.0006 update package

**Source. Observed (the held file).** SGI's PROM 1.0006 release for the 320 and 540, `PROM1_0006.exe`, 480,058 bytes,
sha256 `a6afea4cd49595127c73b7bd912250bd5a0dadb67638c1a4ff173a602dbd9d78`, from a public Internet
Archive item of 320/540 drivers (`sgi_320_540_drivers`). It is an InstallShield self-extractor wrapping one Microsoft
cabinet (MSZIP) with three files: `ReadMe.txt` (the release notes quoted in the version history), `upgrade.cmd`, and
`prom0006.bin`. The command file formats a floppy as `SGISETUP`, copies `prom<serial>.bin` (serial defaults to 0006) and
`README.TXT` to it. The image is not committed.

**The image file. Established (read in full).** `prom0006.bin` is 524,800 bytes, sha256
`b59e7ee0105fcac585e4804bf96cda7702f9a4b5fa20a15cf85f78a8639df143`: a 0x200-byte text header followed by the 0x80000-byte
flash image (flash image sha256 `e33af79a9111568e1e4b8f31d4810c46cd38408fa04f54426d2c34eff288d69d`). The header is CR/LF text:
the serial `0006`, four hex-pair lines (`0x06 0xFF`, `0x00 0xFF`, `0xa3 0xFF`, `0x03 0xFF`), "Firmware Version 0006", the
date 07/07/1999, a build user and SGI's 1999 copyright, then a DOS end-of-file byte and zero padding. The four pairs are
the minimum and maximum hardware revisions the image accepts, and the update code skips the header ([the flash tool](#the-flash-tool)).

**Flash layout. Established (read in full; arithmetic checked).**

| Flash offset | Content |
|---|---|
| `0x00000`-`0x6aa0f` | `SHDR` module table and compressed firmware modules (next section) |
| `0x6aa10`-`0x73fff` | erased (0xff) |
| `0x74000`-`0x79fc0` | the self-test module (`0x5fc0` bytes; the earlier reading called it a patch record, see [below](#the-self-test-module)); the boot block runs it if its checksum is good |
| `0x79fc0`-`0x79fe7` | the module's description text: "Experimental Bug Fixes to NTFS Driver" in 1.0006, "Windows 2000 Compatible" in 1.1005; a label, not what the code does |
| `0x79fe8`-`0x79fff` | trailer of the whole image: covers `0x00000`-`0x79fff` |
| `0x7a000`-`0x7bfff` | ARC environment sector; erased (all 0xff) in this image |
| `0x7c000`-`0x7ffff` | boot block: real-mode entry and tables at `0x7c000`-`0x7c69f`, protected-mode loader and unpacker at `0x7d800`-`0x7f81e`, reset vector at `0x7fff0` |

This fits a top-boot four-megabit part: seven 64 KiB sectors, then 32 KiB, 8 KiB, 8 KiB and a 16 KiB boot sector, whose
two 8 KiB sectors would be the environment sector and the one below it. The part's datasheet is still not held, but the
firmware carries the sector table itself (`1.0006@0xfcbef0`: eleven offset and length pairs, `0x00000` to `0x60000` by
`0x10000`, then `0x70000` by `0x8000`, `0x78000` and `0x7a000` by `0x2000`, `0x7c000` by `0x4000`), so the map is
established as the firmware's view; the part name is the HAL's.

**Record trailers. Established (code read at flash `0x7d800`+ and in the main module; checksums verified on the image).**
Both the patch record and the whole-image record end in the same 24-byte trailer: a 32-bit build time (Unix seconds; the
two trailers decode to 1999-07-07 10:05:34 and 10:06:35 UTC, matching the header date), eight bytes of build user text, four
ASCII version digits (`0001` for the patch, `0006` for the image), a 32-bit checksum, and a 32-bit length whose low 24 bits are
the covered byte count and whose top byte is a flag (0x01 on the whole image, 0 on the patch). The checksum makes the
32-bit little-endian word sum of the covered bytes zero. The whole image (`0x00000`-`0x7a000`, the covered count 0x7a000)
sums to zero. The boot block checks only the patch record (below); nothing read checks the whole-image record.

**The module table. Established (header, boot-block loader and a reimplemented unpacker agree to the byte).** The image
starts with `SHDR`: a 32-bit length (0x6a9a0; with the 0x70-byte header the module data ends at flash `0x6aa10`), a type tag `firm`, a word whose low byte is the section count (5), a reserved word, the entry address
`0x00f00000`, the version digits `0006`, one more word, then 16-byte section entries `{type, source address, destination,
length}`. The boot block walks them: type 1 copies bytes from the flash shadow, type 2 zero-fills the destination, types
3 and 4 run the same decompressor (the build does not use the difference). The five entries:

| Type | Flash source | Destination | Length | What |
|---|---|---|---|---|
| 3 | `0x00070` | `0x00f00000` | `0x530a0` | main module: start-up, memory, Cobalt and Lithium, processors, flash, environment, ARC vectors |
| 2 | (none) | `0x00f53400` | `0x487c4` | zero-filled data |
| 4 | `0x3b684` | `0x00f9bc00` | `0x0b924` | first data module: strings, command help, diagnostics, ARC names |
| 4 | `0x41f6c` | `0x00fa7800` | `0x48554` | second data module: pointer tables, ARC vector tables, the legacy-BIOS image |
| 1 | `0x6a7ac` | `0x00ff0000` | `0x00264` | small copied block |

**The compression. Established (decompressor read, then reimplemented and run).** Byte-pair encoding in blocks: each block
has a table of replaced byte pairs (run-length coded as a count byte, with counts above 127 skipping unused codes), a
big-endian 16-bit block size, then the data, expanded with a stack. The three compressed sections expand to exactly their
stated lengths and end at the next section's source, which is the check that the scheme was read right.

**The monitor. Established (strings).** The data module carries a command-line monitor: `boot`, `auto`, `go`, `printenv`,
`setenv`, `unsetenv`, `resetenv`, `recover_nvram`, `passwd`, `resetpw`, `flash_upgrade` (needs the update floppy),
`fwfloppy` (shows the floppy's PROM version), `hinv`, `version`, `cpuid`, `rdmsr`, `ioread`, `iowrite`, `dump`, `get`,
`put`, `fill`, `copy`, `checksum`, `ls`/`dir`, `fd` (SCSI format), `ping`, `smbios`, `date`, `ac` (AC power-loss policy
and statistics), `fan`, `spread` and `ics` (spread-spectrum clock and clock-generator control), `ethphy`, `dlfw`
(download microcontroller firmware to the Lithium), and `l2cache`, `l2cache_ecc` and `coherentdma` settings. It also has
a power-on diagnostics report (RAM sizing, ECC and bus-noise tests, DIMM speed check, PIIX4, Cobalt and PCI bus B
checks) with "Quick", "Diagnostic" and "Extended" boot modes. The command names and the update-floppy flow are what the
user guide describes as the PROM menus.

## Version history

From SGI's release notes for PROM 1.1005 dated 2000-07-11, posted in full to comp.sys.sgi.hardware on 2001-02-22
(message-id `973u7b$jjr$03$1@news.t-online.com`). Observed (a public repost of the vendor text, not the vendor
original).

| Version | Change |
|---|---|
| 1.0002 | Creates the floating-point registry nodes earlier versions left out (MATLAB needs them) |
| 1.0004 | Removable SCSI drive no longer hides the floppy; fix for exceptions with long OS-loader names; QLogic adapter limit 4 to 8; DHCP uses the router option; new microcode update for Pentium II and III; AC-power-restore policy added; "Advanced Settings" panel (power-on diagnostics level, power loss recovery, CPU serial number); "Restore settings" restores boot variables from the emergency repair disk |
| 1.0005 | QLogic 2100 Fibre Channel card |
| 1.0006 | 600 MHz Katmai processors; slot 2 processors with 2 MB L2 |
| 1.1002 | Windows 2000 support; F8 boot-options key; Windows 2000 IDE and SCSI factory boot entries; disk partitioning utility; ARC path of SCSI controllers changes from `multi()` to `scsi()`, with existing boot entries rewritten on upgrade; PCI bridge support |
| 1.1003 | Secondary IDE channel on Borg disabled correctly for Windows 2000; menu button swap; debug output to the serial port removed |
| 1.1004 | Partitioning utility fix |
| 1.1005 | Partitioning fix; 800 and 850 MHz Coppermine processors |

Other facts from the notes: 1.1000 or newer is required for Windows 2000; the 1.0004 change to power-loss recovery makes
newer firmware shut a machine back off when wall power returns after 5 to 10 seconds or more (the older behaviour was
always to power on); upgrading with the password jumper fitted can power the machine off before the flash completes. A
second Usenet report (1999-09-23) shows firmware 1.006 on a 540; the 1.1xxx scheme appears from Windows 2000 onwards.
The notes also say a 320 needs system board revision 007 or later for Pentium III upgrades, and that a 540 is validated
only with one, two or four processors. No 1.0000, 1.0001 or 1.0003 notes are held. The shipping version of the first
320 and 540 units is unknown. Neither the guide nor the notes name the flash part.

First-hand check of one row: the held 1.0006 image is dated 07/07/1999 in its header and trailers, its own `ReadMe.txt`
lists the same 1.0002 to 1.0006 changes as the 1.1005 notes (established), and the image's version strings print as
"1." followed by the four digits `0006`, which fits the 1.006 a Usenet poster saw on a 540 on 1999-09-23 (inferred from
the format string; the screen was not seen).

## The flash part and its contents

1. **Flash size and address. Established (HAL read; image layout).** The HAL maps 512 KiB at physical `0xfff80000`, the top
   of the 4 GiB space, and its table name for the part is `M29F400T`, a symbol in the HAL's debug file. The firmware maps
   the same 0x80 pages for its own flash driver and its reset code uses the same window. By the usual naming that is a
   four-megabit, 16-bit-wide, top-boot flash whose top sectors are small; the layout in the table above (environment
   sector `0x7a000`-`0x7bfff`, boot block `0x7c000`-`0x7ffff`) is consistent with it. No datasheet is held, so the sector
   map is not confirmed. That the code lives in the same device is established by the image.
2. **Command sequence. Established (HAL read).** Programming uses 16-bit writes to word-addressed command cycles
   `0xaa` at byte offset `0xaaaa`, `0x55` at `0x5554`, then `0xa0` for a program, `0x80` followed by the same two cycles
   and `0x30` at the sector address for a sector erase. Completion polling uses the data-toggle and error bits (bit 7
   data polling, bit 5 time-out for programming; the two toggle bits 6 and 2, with bit 5, for erase), up to 30,000
   polls for a program. Reading the signature is stubbed out (always reports present); a flash read-array command `0xf0`
   returns the array to read mode. This is standard AMD-compatible command-set behaviour. The firmware's own flash
   driver in the main module addresses the same sector (`0x7a000`, last byte `0x7bfff`) and the sector below.
3. **NVRAM environment block. Established (firmware code read; HAL read for the place).** The ARC environment is the last
   8 KiB sector but one of the flash: `0x2000` bytes at flash offset `0x7a000`.
   - *Validity.* At start-up the firmware treats the block as valid only if its first byte is neither `0x00` nor `0xff` and
     the 32-bit little-endian sum of all 0x800 words is zero; otherwise it loads a built-in default table (inferred from a short read of that path). An erased
     (all-0xff) block, as in the update image, is therefore "empty".
   - *Entries.* The variable area is the first `0x1fe8` bytes: NUL-terminated `NAME=value` strings packed back to back,
     ended by an empty string, the rest filled with `0xff` (the writer pads to a 4-byte boundary with `0xff` and then
     fills with `0xffffffff`). Lookup compares the string before the `=`.
   - *Trailer.* The last 24 bytes use the same trailer as the image records: a 32-bit word at `0x1fe8` (in the writer, a caller-supplied
     value, probably a time stamp as in the image records; its low byte is repeated eight times at `0x1fec`-`0x1ff3`), the ASCII digits `0001` at
     `0x1ff4`, a checksum at `0x1ff8` and the length `0x2000` at `0x1ffc`. The checksum is the two's complement of the
     sum of the other words, so the whole block sums to zero. The writer builds the image in RAM, erases the sector,
     programs it, and returns error code 6 if the erase fails or a post-write check does not match.
   - *The HAL.* The HAL's own checksum comparison at `0x1ff8` (see [nt-hal.md](nt-hal.md)) agrees with the checksum
     position. The routines `HalpCreateShadowTable`, `HalpMakeNewImage` and `HalpStringCksum` were not read, so whether
     the HAL rewrites the block byte-for-byte the way the firmware does is unknown.
   The variable names the HAL knows are `console`, `TimeZone`, `AutoLoad`, `OSLoadFilename`,
   `OSLoader`, `OSLoadPartition`, `SystemPartition`, `OSLoadOptions`, `diagmode`, `diskless`, `nogfxkbd`,
   `scsiretries`, `scsihostid`, `pagecolor`, `volume`, `sgilogo`, `netaddr`, `passwd_key`, `netpasswd_key`,
   `videotiming`, `videooutput`, `videoinput`, `videostatus`, `videogenlock` and `audiopass`. The firmware's own list of
   names carries the ARC ones in several spellings (upper-case `OSLOADOPTIONS`, `LOADIDENTIFIER`, `OSLOADFILENAME`,
   `OSLOADPARTITION`, `OSLOADER`, `SYSTEMPARTITION`, and mixed-case forms), `AutoLoad`, `ConsoleIn`, `diagmode`, `netaddr`,
   `passwd_key`, `l2cache`, `l2cache_ecc`, `coherentdma`, `cogfxmem`, `maxpmem`, `DosBoot` and `ignorehughid`. Factory
   defaults and the multi-name behaviour were not read. The restore path ("restore NVRAM boot variables to factory
   settings") reads a repair-floppy file named `BOOTVARS._`, so that is, inferred, the emergency repair disk's variable
   file; its format is unknown.
4. **What lives in the rest of the flash. Established (image read).** A boot block (real-mode reset code, the
   protected-mode loader and unpacker), the compressed main module, two data modules (monitor, diagnostics, SMBIOS reader,
   ARC names, vector tables, the legacy-BIOS image) and the NTFS-fix patch record; see the update package section.
   The drivers the strings name are inferred from the notes and the loader: the user-visible SCSI and IDE boot paths, a
   DHCP/TFTP client, an NTFS reader, the partitioning utility (1.1002 onwards) and the Pentium II and III microcode
   updates (1.0004). Not traced: the microcode patch tables and the SCSI, IDE and network drivers.

## The firmware user interface (established, guide 007-4225-001)

Pressing Esc within a few seconds of the first start-up messages (a progress bar shows the time) opens a graphical
Welcome screen with: Start System; Startup Settings (boot entries with load identifier, `OSLoader` path, `OSLoad`
filename, `OSLoad` partition, system partition, options; the defaults are `\os\winnt40\arcldr.exe`, `\WINNT`, partition 1
for the kernel, partition 2 for the boot files, on `IDE 0 Disk 0` or `SCSI 2 Disk 0`); System Settings (system time,
"Advanced Settings": power-on diagnostics level quick (default) or extensive, which tests RAM at about a tenth of a second
per megabyte; recovery from power loss, three policies; CPU serial number enable or disable, Pentium III only;
password: none, for set-up, or for set-up and boot, overridable by a jumper; keyboard language, used only by the
firmware; parallel port mode: ECP (default), EPP, SPP extended, SPP compatible; L2 cache ECC off by default; restore
settings); Install System Software (from Recovery CDs 1 and 2); Run System Utilities (flash the PROM, or run utilities);
Hardware Inventory.

## Updating the firmware (established, guide 007-4225-001 and the notes)

From Windows NT with Recovery CD 2: Install, "SGI Firmware", which writes the PROM image to a formatted floppy and asks
for a restart. At the next start, Esc, Run System Utilities, Upgrade System Firmware, Accept; the firmware scans the
floppy for an image, confirms it detects one, flashes, reports success, and restarts. The notes add that upgrades
should go through this menu and not through the password override jumper. The floppy gets `prom<serial>.bin` as built by
`upgrade.cmd` (layout above). Recovery CD-2 v1.0 does not contain this payload: its cabinets (dated 1999-05-27, earlier
than the first update package) hold drivers and utilities but no firmware item, so the "SGI Firmware" installer entry
the guide describes is not on this disc (inferred: it came on a later CD-2 or only as a downloadable package). The flasher's own code is read in [The flash tool](#the-flash-tool).

## The PROM 1.1005 update package

**Source. Observed (the held file).** `PROM1_1005.exe`, 1,450,371 bytes, sha256
`4c15e871404bc22dfb7d93a6752d90d4bccd72d75fce4b6d2ab9b507e28c35e3`: an InstallShield self-extractor (engine 6, an
`ikernel.ex_` and a compiled script `setup.inx` whose debug path names SGI's own build tree for "sgifw"; `Setup.ini`
gives the application name "SGI Firmware"). It wraps `data1.cab` and `data2.cab`, which unshield reads, and the files in
`data1.cab` are `PROM/prom1005.bin` and `ReadMe/Readme.txt` plus InstallShield engine files. The image is not committed.
Unlike the 1.0006 package this one has no `upgrade.cmd`: the floppy is made by the installer script, whose strings show
`format a: /v:sgiprom /q`, a delete of everything on the floppy, and a copy of `README.TXT` to `a:\`; it shows the
messages "Insert a floppy disk" and "FLASH_PROM_INSTRUCTIONS" ("MUST_RESTART_COMPUTER"). The script is compiled; its copy of
the image to the floppy was not decoded (unknown), but the firmware's flash tool finds the file by its name (below).

**The image file. Established (read in full).** `prom1005.bin` is 524,800 bytes, sha256
`3ee2ca7ba883e91fb7d91f789b49fb6d197f78bb83f1466972273e574f921464`: the same `0x200`-byte text header (serial `1005`, the
same four revision pairs as 1.0006, "Firmware Version 1005", "Thu 07/06/2000", a personal login as build user (1.0006 has `builder`), SGI's 2000
copyright) and a flash image of sha256 `9367dc0b496b78283acee7201405c7871f2ec24e957917f6affbbc927a1b2ec3`. The date is five days
before the release notes' 07/11/2000, which is the date of the package. The package's `Readme.txt` is the text of the SGI PROM 1.1005 release notes (2000-07-11), identical to the separately
published copy once line ends are ignored (established).

**Flash layout. Established (read in full).** Same map as 1.0006 with a shorter module area: `SHDR` module table and
compressed modules at `0x00000`-`0x61f6f`, erased `0x61f70`-`0x73fff`, self-test module `0x74000`-`0x79fc0`, trailer
(build time 2000-07-06 18:13:36 UTC, a personal login as user, digits `1005`, length `0x7a000` with flag `0x01`) at `0x79fe8`,
environment sector `0x7a000`-`0x7bfff` erased, boot block `0x7c000`-`0x7ffff`. The self-test module's own trailer is dated
18:13:20 UTC, version digits `0001`. Both trailers sum to zero by the same rule as 1.0006. **The boot block
(`0x7c000`-`0x7ffff`, sha256 `b17838450a3b341500937c2c0826ed811f1140a2b8590d70cd2a6aec8e952457`) and the erased environment
sector are byte-identical in the two versions.** The reset vector (`0x7fff0`) is `e9 0d c0`: a 16-bit near jump to
offset `0xc000` of the segment at `0xffff0000`, flash offset `0x7c000`; behind it the words `0x56781234` and
`0x5555aaaa` and a run of `0xff` (their purpose is unknown).

| Type | Flash source | Destination | Length | What |
|---|---|---|---|---|
| 3 | `0x00070` | `0x01100000` | `0x472d6` | main module (compressed length `0x36d52`) |
| 2 | (none) | `0x01147400` | `0x484c4` | zero-filled data |
| 4 | `0x36dc4` | `0x0118fc00` | `0x0c07c` | first data module (compressed `0x6e12`) |
| 4 | `0x3dbd8` | `0x0119c000` | `0x42cbc` | second data module (compressed `0x24131`) |
| 1 | `0x61d0c` | `0x011df000` | `0x00264` | small copied block |

Header: length `0x61f00`, entry `0x01100000`, version digits `1005`, section count 5, the same decompressor (byte-pair
encoding; it expands each section to exactly its stated length and ends at the next section's source, the same check as
for 1.0006). The word at header offset `0x1c` is `0x21b64a13` here and `0x01011e6d` in 1.0006; the loader's use of it was not
read (unknown). The destination of everything moved up by 2 MiB (`0xf00000` to `0x1100000`), so no `1.0006@` address equals the
same code at `1.1005@`.

## The flash tool

**Established (`1.0006@0xf3de70`, `0xf19980` and `0xf191f0` read in full, Ghidra; the 1.1005 counterparts `1.1005@0x1130e1b`,
`0x111525f` and `0x1114d55` have the same shape, compared by decompiler output, not read line by line).**

1. **Procedure.** From the firmware menus (Esc at start-up, Run System Utilities, Upgrade System Firmware) or the monitor
   command `flash_upgrade`: ask for the upgrade floppy ("Insert Upgrade Floppy and Press Continue"), scan the floppy's
   root of `multi(0)disk(0)fdisk(0)partition(0)` (opened up to five times) for a file whose twelve-character name is `PROM`,
   four free characters and `.BIN`, not a directory, read the text header, check the hardware ranges, warn when the
   build time in the image's trailer is older than the running flash's ("Warning: Downgrading Prom"), ask "Firmware Upgrade Image
   detected. Start Upgrade Process?", then "Flashing Prom ...", then "Upgrade Successful. Eject the Floppy... and press
   Continue" and restart. The monitor command `fwfloppy` shows the floppy image's version.
2. **Header.** `1.0006@0xf19580` (the parser and range check; the 1.1005 equivalent was not located by address) reads the first line of the `0x200`-byte header as the serial and each of the next four lines as a pair of hex numbers
   (minimum, maximum), comparing them with the running board's values. In order: board revision of the 320 ("Hugh"; the running board's revision byte must lie in
   `0x06` to `0xff`), board revision of the 540 ("Borg", `0x00` to `0xff`), Cobalt revision (`0xa3` to `0xff`) and
   Lithium generation (`0x03` to `0xff`, see [boot-path.md](boot-path.md#pci-bus-numbering-and-windows); the message prints
   the minimum plus one). The messages are
   "cannot use on Hugh", "cannot use on Borg", "Needs board rev at least ...", "Cannot use on board rev > ...", "Needs at
   least Cobalt ...", "Cannot use Cobalt > ...", "Needs at least Lithium ..." and "Cannot use Lithium > ...", and a
   malformed header prints "bad prom image header". 1.0006 and 1.1005 carry identical pairs, so a 1.1005 image runs on every board a
   1.0006 image does. Which of the two board names is the 320: board type 0 (`(inb(0xfb2) >> 2) & 0xf`) reports "Hugh" in this
   check and "320" in the monitor prompt, type 1 "Borg" and "540".
3. **Writing.** The tool skips the `0x200` header bytes and reads the rest into a RAM buffer in five chunks. If the image
   is longer than `0x7a000` and its environment sector (`0x7a000`) starts with `0x00` or `0xff`, the tool copies the
   running flash's environment sector into the buffer so that the stored variables survive. It then tests whether the boot
   sector is write-protected (an AMD-style autoselect cycle, command bytes `0xaa` to byte offset `0xaaaa`, `0x55` to `0x5554`,
   `0x90`, then a read of the protection word at `0x7c004`); if it is, the image is cut to `0x7c000` bytes and the boot block
   is not written. The tool erases the sectors covering the image through the sector table, programs the buffer in
   16-bit words (skipping words that are `0xffff`), polls status after each word (that routine was not read in full), reads
   everything back and compares ("unable to write flash", "unable to verify flash"). The flash is not accessible at its
   mapped window until the firmware's page tables exist; before that the tool uses the physical address. The autoselect
   test for the part reads manufacturer word `0x20` and device word `0xd5`; those codes are the usual ones for an
   STMicroelectronics M29F400T (inferred: no datasheet is held).
4. **What the tool does not do.** It does not check the checksums in the trailers: the code read compares only the
   trailers' time stamps. The compiled floppy-making script of the 1.1005 package was not decoded.

## The self-test module

**Established (read as code and data; module bytes at flash `0x74000`-`0x79fc0`).** The module the first version of this page
called a patch record is SGI's power-on self-test and "Serial Test Manager" (the string `SaltLake` names it; a monitor
command list below and the strings "Verbose build" and "Dongle was detected on COM1" belong to it). The boot block
runs it before it copies the flash to RAM, so it runs from flash with the stack held in MMX registers.

- **Entry.** `1.0006:test+0x00`: `mov esp,esi` (return link), `cr0.PE` set, `lgdt cs:[0x98f8]` (1.1005: `0x9970`), selectors `0x10` for
  data, then a far jump to selector `0x40` offset `0x98fe`, where the two bytes `ff e0` jump to the address left in `eax`
  (`0x402c`, the first 32-bit instruction). The GDT in the module (limit `0x47`, base `0xffff98b0`; 1.1005 `0xffff9928`)
  holds flat segments at base 0 and selector `0x40`, a flat 32-bit code segment at base `0xffff0000`. Every
  instruction address in the module is therefore the offset used here.
- **What it does, in order (1.0006; established for the parts read, the rest named from strings).** Reads the CPU signature
  (`cpuid` values `0x672` to `0x67f`, family 6 model 7) and, when MSR `0x17` carries platform id 2, rewrites the L2 cache
  control MSR `0x11e` and restores it; writes the PIIX4's command register through Lithium B's window (`0xfd0000f8 = 0x80002004`,
  `0xfd0000fc = 9`); sets up the PIIX4 power-management and the NS87307 blocks and the real-time clock (ports `0x70`/`0x71` and the extended bank at `0x72`/`0x73`); sets variable MTRR 0 to a 64 KiB write-protect range at `0xffff0000`; programs COM1 (`0x3f8`, divisor 12, 8N1) and tests for a loop-back dongle; then runs the register tests and RAM tests described below. Results go into the
  CMOS (standard bytes `0x40`-`0x4f` hold the sixteen bank codes the main module prints as "Slot Group A" to "D"; the extended bank at ports
  `0x72`/`0x73` holds test state). If the dongle is present it starts the manager's command loop (`hp`, `sa`, `sc`, `ga`, `gc`, `dc`, `dd`, `da`,
  `ul`, `ua`, `uh`, `go`, `ss`, `rt`, `r_`, `w_`, `ds`, `rs`, `ri`, `wi`, `ms`, `rc`, `wc`, `rl`, `wl`, `wh`). Strings in the module name the tested
  units: "Cobalt-I/O Bus", "Cobalt Display ASIC", "Cobalt I/O ASIC", "Cobalt-Graphics Bus", "RAM Sizing", "Test Valid RAM Banks" and
  an infinite loop RAM test for 128, 256 and 512 MB single, double and stacked modules in slots A and B.
- **Register tests. Established (table and loop read).** One loop (`1.0006:test+0x95d0`; nothing in either image references it directly, so how it is reached was not traced) walks a table of (address, mask,
  expected value) triples and fails the test with the address in `ebx` when `(*address & mask) != expected`; a second loop
  (`test+0x95f4`) walks (address, mask) pairs and for each runs a bit-walk (`test+0x9147`): set the masked bits, read
  back, clear them, read back, then write `0x55555555` and `0xaaaaaaaa` through the mask and compare. The Cobalt display
  table is quoted on the [cobalt repository's page for the PROM's display set-up](https://github.com/jamesbraid/cobalt/blob/main/devices/cobalt-graphics/prom-init.md).
  The display-ASIC `bist` routine (`1.0006:test+0x966a`, 1.1005 `test+0x96e4`) likewise has no direct reference in either image; how it is reached was not traced. A separate test reads `0xfc000000` and `0xfd000000` and compares both with `0x100210a9` (the Lithium identification).
- **What the module programs in the memory controller.** See [boot-path.md](boot-path.md#memory-controller-and-graphics-memory).

## From 1.0006 to 1.1005

Method: both images unpacked with the same decompressor, all functions decompiled, then compared by normalised decompiler
output and by string and table differences. Of about 1,300 main-module functions in 1.0006 and 1,550 found in 1.1005, 457 have
identical normalised text; the rest differ in layout, addresses or content, so the list below is what was confirmed by reading both
sides, not a full diff. Consistent with SGI's notes (SGI PROM 1.1005 release notes, 2000-07-11) where it is stated; the
notes name only the features marked "(notes)". Grades: established where both sides were read, inferred where only strings or
the decompiler's shape back it.

| Area | 1.0006 | 1.1005 | Grade |
|---|---|---|---|
| Build | 1999-07-07 10:05 UTC, user `builder`, "Jul  7 1999" | 2000-07-06 18:13 UTC, a personal login, "Jul  6 2000" | established (headers, trailers, strings) |
| Main module | `0x530a0` bytes at `0xf00000` | `0x472d6` bytes at `0x1100000`; 1,555 functions found against 1,328 | established |
| Boot block, environment sector, reset vector | `0x7c000`-`0x7ffff` | byte-identical | established |
| Revision ranges in the image header | `0x06`/`0x00`/`0xa3`/`0x03` minimums | the same | established |
| Self-test module | label "Experimental Bug Fixes to NTFS Driver", display table with a BIST row (`test+0x9703`, address `0xd000001c`, mask `0x0ff0ffff`, expected 0) | label "Windows 2000 Compatible", the display table's BIST row removed (the BIST code at `test+0x966a`, now `test+0x96e4`, stays); the self-test listing gains 45 `or $0x80,%al` (1 in 1.0006, 46 in 1.1005) and 21 `and $0x7f,%al` (none before) in extended-CMOS accesses (linear listing counts), most of them no-ops on the values used | established (table, listing); the reason is unknown |
| Board types | names "SG320" and "SG540" for the ARC system type | adds "SG330", "SG530", "330 fab" and "530 fab"; the name routine (`1.1005@0x1139989`) maps board type 1 to "SG540", 2 to "SG330", 3 to "SG530" and anything else to "SG320" | inferred (names and a branch; no board of types 2 or 3 is described anywhere else) |
| ACPI | none | `acpi_install` (`1.1005@0x111a293`) builds an ACPI root table and a fixed description table, with an ARC node "ACPI-BIOS"; the table, OEM id `SGI___`, OEM table id `320/640`, revision 1, length `0x74`, has SCI interrupt 9, SMI command port `0xb2`, enable and disable bytes `0x10` and `0x11`, PM1 event block `0xf80` (length 4), PM1 control `0xf84` (length 2), PM timer `0xf88` (length 4), GPE0 `0xf8c` (length 4), flags `0x25`; there is a root table with no further entries read (`1.1005@0x113edec`, `0x113eed0`) | established for the field values read; what Windows 2000 does with them is the HAL's side |
| PCI bridge support (notes: 1.1002) | PCI-PCI bridge assignment code present (`1.0006@0xf1fe70`, "assign 1 bus") | present; debug printing for it, the option-ROM scan messages and the ql1240 debug text are gone (71 strings removed from the first data module and 154 added) | inferred from strings and shape |
| New commands and utilities (notes: 1.1002) | none of these | `dump_pci`, `env {save\|restore\|debug}`, the disk partitioning utility (messages "Partition Disk(s)", "Partitions created successfully", partition 2 fixed at 200 MB), `ignore_pci_card`, `DriveDelay`, a USB hub and keyboard/mouse probe (`init_hub`), the F8 "Advanced Boot Options" menu with the Windows 2000 safe-mode choices, Windows 2000 default start entries on `scsi()` paths | established as strings; the partition utility's boot sector strings ("Invalid partition table", "Error loading operating system") show a master boot record is written |
| ARC path of SCSI (notes: 1.1002) | `multi()` | `scsi()` | established (strings) |
| Debug output (notes: 1.1003) | prints PCI and QLogic debug messages | the PCI, option-ROM and ql1240 messages removed | established (strings) |
| Memory descriptor list at start-up | nine fixed descriptors `1.0006@0xf01ee0`: page 0 type 6, `0x1000` 1 page type 1 (unchanged), `0x2000` `0x9d` pages type 5, `0x9f000` `0x61` type 6, `0xe80000` `0x80` type 5, `0xf00000` `0x80` type 6, `0xf80000` `0x80` type 5, `0xa00000` `0x200` type 5, `0xc00000` `0x280` type `0x14` | `1.1005@0x1101e30`: `0x2000` `0x60` type 5, `0x2ff000` 1 page type 5, `0xf50000` `0xb0` type 5, `0x1100000` `0x80` type 6, `0x1180000` `0x80` type 5, `0xd00000` `0x250` type `0x14`, the first, second (`0x1000`, 1 page, type 1) and fourth entries of the old list unchanged | established; the types `0x14` and 6 are not named by any shipped text |
| Memory bank to descriptor step (`1.0006@0xf02e30`, `1.1005@0x1102d90`) | handles banks of `0x10` (32 MiB) and `0x40` (128 MiB) units; first 16 MiB type 2, the rest of each bank type 5 | counts only `0x40` banks, merges adjacent banks into at most eight segments ("init_memory_descriptors: too many memsegs"), first 32 MiB type 2, the rest type 5; `maxpmem` ignored below 128 MiB | established |
| Graphics memory allocator (`1.0006@0xf04a70`, `1.1005@0x1104840`) | one entry's size limit `0x1000` pages (16 MiB) | limit `0xc00` pages (12 MiB); a descriptor start that is not 4 MiB-aligned is rounded up and the piece trimmed to a multiple of 4 MiB, where 1.0006 skips it | established (both read); the alignment change plausibly answers the HAL's "Update the prom for aligned graphics memory" warning (inferred) |
| Lithium and Cobalt set-up | `1.0006@0xf20620` | same writes and values; the "Vendor and Device ID is incorrect" report removed | established |
| Text console frame buffer | physical `0xa00000`, 2 MiB, descriptor type 5 | physical `0x2000000` (32 MiB), 2 MiB, no descriptor in the fixed list | established (`1.0006@0xf3e700`, `0xf3eac0`; `1.1005@0x11314f8`, `0x11317f6`) |
| Display mode table | 24 rows (`1.0006@0xfe36a0`) | 26 rows (`1.1005@0x11d1ea0`): adds two 1600 by 1000 rows (75 and 85 Hz), replaces the 800 by 600 row at 119.8 Hz with one at 119.85 Hz and changes values in nine others | established; list in [the display set-up page](https://github.com/jamesbraid/cobalt/blob/main/devices/cobalt-graphics/prom-init.md) |
| Display register sequence | `1.0006@0xf3ec30` | same writes and values in the same order (the compiler reordered operands) | established |
| Flash tool | `1.0006@0xf191f0` | same procedure | inferred (decompiler shape) |

Against SGI's notes: the notes say "Support for PCI bridges", Windows 2000, F8 boot options, the partitioning utility, the
`scsi()` path change, removal of serial-port debug output (1.1003) and 800 and 850 MHz Coppermine processors (1.1005).
Confirmed in the image: the F8 menu, the partition utility, the `scsi()` strings, the removed debug messages. Not
separately confirmed: the Coppermine support (the processor-signature tables were not compared) and the "PCI bridge
support" as a distinct change (the assignment code exists in 1.0006 and appears unchanged in outline). In the image and not in the notes: the
ACPI tables, the board types 2 and 3 strings, the lower 12 MiB graphics limit, the 32 MiB frame buffer address, the
rewritten bank-descriptor step and the changed display mode table rows. Not compared: the microcode update tables, the SCSI, IDE and
network drivers, and the monitor commands outside those named.

## Open

The shipping firmware version, the microcode tables and the driver code in the main module, the 1.1005 package's
floppy-making script, the purpose of the `SHDR` word at offset `0x1c` and the factory defaults are listed in
[questions/visws-firmware-open.md](../../questions/visws-firmware-open.md).
