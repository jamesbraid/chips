# Visual Workstation 320 and 540: the system firmware

The firmware image of PROM 1.0006 (July 1999) is held and read: SGI's update package for the 320 and 540, found in a public
driver archive, unpacks to a 512 KiB flash image. Older and newer versions are not held, so the version history below
still rests on SGI's release notes as posted to Usenet. What the image does at reset is in [boot-path.md](boot-path.md);
this page covers what it is, how the image and its environment block are laid out and how it is updated. Grades as in the
README. Image offsets are flash offsets: the flash is mapped at `0xfff80000`, so flash offset `0x7c000` is physical
`0xffffc000`.

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
the serial `0006`, four hex-pair lines (`0x06 0xFF`, `0x00 0xFF`, `0xa3 0xFF`, `0x03 0xFF`; meaning unknown, the pairs look
like value and mask), "Firmware Version 0006", the date 07/07/1999, a build user and SGI's 1999 copyright, then a DOS
end-of-file byte and zero padding. Whether the update utility strips the header or flashes the file as is was not read.

**Flash layout. Established (read in full; arithmetic checked).**

| Flash offset | Content |
|---|---|
| `0x00000`-`0x6aa0f` | `SHDR` module table and compressed firmware modules (next section) |
| `0x6aa10`-`0x73fff` | erased (0xff) |
| `0x74000`-`0x79fc0` | a patch record, 0x5fc0 bytes, described as "Experimental Bug Fixes to NTFS Driver"; the boot block runs it if its checksum is good |
| `0x79fc0`-`0x79fe7` | the patch record's description text |
| `0x79fe8`-`0x79fff` | trailer of the whole image: covers `0x00000`-`0x79fff` |
| `0x7a000`-`0x7bfff` | ARC environment sector; erased (all 0xff) in this image |
| `0x7c000`-`0x7ffff` | boot block: real-mode entry and tables at `0x7c000`-`0x7c69f`, protected-mode loader and unpacker at `0x7d800`-`0x7f81e`, reset vector at `0x7fff0` |

This fits a top-boot four-megabit part: seven 64 KiB sectors, then 32 KiB, 8 KiB, 8 KiB and a 16 KiB boot sector, whose
two 8 KiB sectors would be the environment sector and the one below it. The part's datasheet is still not held, so the
sector map itself stays an inference from the part name and from the HAL erasing exactly the 8 KiB at `0x7a000`.

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
the guide describes is not on this disc (inferred: it came on a later CD-2 or only as a downloadable package). The flasher's own code (`flash_upgrade`,
`fwfloppy`) and how it treats the 0x200-byte header, the erased environment sector and the boot block were not read.

## Open

The shipping firmware version, the flash part's sector map, the microcode tables and the driver code in the main module,
the update utility's handling of the header, the environment sector and the boot block, and the factory defaults are
listed in [questions/visws-firmware-open.md](../../questions/visws-firmware-open.md).
