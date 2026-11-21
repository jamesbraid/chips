# Visual Workstation 320 and 540: the system firmware

The firmware image itself is not held (see [README.md](README.md)). What is known comes from SGI's firmware guide, SGI's
own release notes as posted to Usenet, and the NT software that reads the firmware's data. Grades as in the README.

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
3. **It does carry some PC-compatible pieces. Software expectation.** The HAL contains real-mode and V86 thunks
   (`HalpBiosCall`), a VGA text display path next to the Cobalt graphics display path, and the legacy chips (PIIX4,
   NS87307, 8259, CMOS RTC) are programmed directly. Whether the PROM exposes int 10h or other BIOS entry points is
   unknown.
4. **Product names.** The HAL carries the strings "Silicon Graphics 320" and "Silicon Graphics 540" and two ARC
   configuration nodes under the system node: "SGI REV INFO", with children "SYS TYPE" and "BOARD REV". HAL reads
   both as single bytes. Established. The hardware names "Borg" (the Cobalt platform, from the HAL's file name and
   string) and "Twibble" (an unexplained node string) also occur; "Hugh" appears as the name of an interrupt routing
   mode (see [nt-hal.md](nt-hal.md)). What these denote is unknown.

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

## The flash part and its contents

1. **Flash size and address. Software expectation (HAL).** The HAL maps 512 KiB at physical `0xfff80000`, the top of the
   4 GiB space, for the flash, and its table name for the part is `M29F400T`, a symbol in the HAL's debug file. By the
   usual naming that is a four-megabit, 16-bit-wide, top-boot flash whose top sectors are small; the HAL erases and
   reprograms the 8 KiB sector at offsets 0x7a000 to 0x7bfff, which fits that layout. No datasheet is held, so the
   sector map is not confirmed. That the firmware code lives in the same device is inferred.
2. **Command sequence. Established (HAL read).** Programming uses 16-bit writes to word-addressed command cycles
   `0xaa` at byte offset `0xaaaa`, `0x55` at `0x5554`, then `0xa0` for a program, `0x80` followed by the same two cycles
   and `0x30` at the sector address for a sector erase. Completion polling uses the data-toggle and error bits (bit 7
   data polling, bit 5 time-out for programming; the two toggle bits 6 and 2, with bit 5, for erase), up to 30,000
   polls for a program. Reading the signature is stubbed out (always reports present); a flash read-array command `0xf0`
   returns the array to read mode. This is standard AMD-compatible command-set behaviour.
3. **NVRAM environment block. Established (HAL read).** The HAL keeps the ARC environment in the last 8 KiB sector of
   the flash: `0x2000` bytes at offset `0x7a000`. The variable area is the first `0x1fe8` bytes and a 24-byte trailer
   follows; the HAL compares a stored checksum, the dword at block offset `0x1ff8` (inferred from the shadow offset it
   reads), with one it computes over the segment, and a mismatch is reported but not fatal. Entries are parsed into a
   RAM shadow; a change builds a fresh image, erases the sector, programs the image back and recomputes the checksum.
   The variable names the HAL knows are `console`, `TimeZone`, `AutoLoad`, `OSLoadFilename`,
   `OSLoader`, `OSLoadPartition`, `SystemPartition`, `OSLoadOptions`, `diagmode`, `diskless`, `nogfxkbd`,
   `scsiretries`, `scsihostid`, `pagecolor`, `volume`, `sgilogo`, `netaddr`, `passwd_key`, `netpasswd_key`,
   `videotiming`, `videooutput`, `videoinput`, `videostatus`, `videogenlock` and `audiopass`. The entry layout inside
   the variable area (separators, terminator, whether names and values are NUL-separated strings) and the checksum
   algorithm were not recorded; see the questions page.
4. **What lives in the rest of the flash.** Unknown. The user guide's PROM menus (below) and the loader services imply
   a monitor with a graphical front end, a disk partitioning utility (from 1.1002), a DHCP/TFTP network boot client
   (the 1.0004 notes mention DHCP; the loader strings carry TFTP and a UDP client), SCSI and IDE drivers and the
   microcode patches for Pentium II and III processors. Those are inferred from the notes and from loader strings.

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
should go through this menu and not through the password override jumper. The image file format on the floppy is
unknown.

## Open

The shipping firmware version, the flash part for the code area, the environment block's entry layout, and whether any
BIOS-style entry points are exposed are listed in [questions/visws-firmware-open.md](../../questions/visws-firmware-open.md).
