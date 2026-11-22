# SGI Visual Workstation 320 and 540 firmware and NT software: open questions

Open points from [software/visws](../software/visws/README.md). One firmware image (PROM 1.0006) is held and read; the rest is
read from NT's HAL and loader, SGI's firmware guide, SGI release notes reposted to Usenet and the public Linux port. The
platform and chip questions are in [visws-open.md](visws-open.md). Each entry: question, routes tried, next route.

## The firmware image and the update package

[settled for 1.0006; route: missing binary for the other versions] The Recovery CD-2 v1.0 route failed: unpacking its
InstallShield 3 archives (unshield reads them) shows drivers, help and documentation and no firmware item; the cabinets are
dated 1999-05-27, before the first update package. The image was found elsewhere: SGI's PROM 1.0006 update package is in a
public driver archive already mirrored, and its 512 KiB flash image is read in [software/visws/firmware.md](../software/visws/firmware.md)
and [boot-path.md](../software/visws/boot-path.md). Still not held: any other version (1.0002 to 1.0005, 1.1002 to 1.1005), the
update utility's flashing code path (`flash_upgrade` was named, not read), and how it treats the 0x200-byte file header, the
erased environment sector and the boot block. Next: the 1.1xxx update packages from SGI's support site (no stable address on
record), then read `flash_upgrade` in the held image.

## Shipping firmware version and early release notes

[route: missing source] The notes held start at 1.0002 (see [firmware.md](../software/visws/firmware.md)); there are no notes
for 1.0000, 1.0001 or 1.0003, and the version the first units shipped with is unknown. The held 1.0006 package's own
ReadMe repeats the 1.0002 to 1.0006 entries and adds nothing earlier. Next: a release-notes file from
the support site, or a hardware-inventory capture from an early unit.

## The environment block: HAL side and defaults

[route: software now] The firmware side is read ([firmware.md](../software/visws/firmware.md)): validity test, `NAME=value`
entries, 24-byte trailer, zero-sum checksum. Open: whether the HAL's rewrite (`HalpCreateShadowTable`, `HalpMakeNewImage`,
`HalpStringCksum`, `HalpGenerateChecksum`) produces the same bytes, the factory default variables (the default table the
firmware loads on an invalid block), the multiple spellings of the loader variable names, the format of the repair floppy's
`BOOTVARS._`, and the meaning of the trailer's first dword. Next: read the default table in the main module and the HAL
routines.

## Flash sector map and the rest of the flash

[route: missing source] The part name `M29F400T` is a HAL symbol and the image layout fits a top-boot four-megabit part; no
datasheet is held, so the sector map is inferred. The patch record, the module table and the boot block are mapped; not yet
read: the Pentium II and III microcode tables, the disk, network and SCSI drivers and the diagnostics in the main module.
Next: the part's datasheet; read those parts of the main module.

## The ARC tree and the loader's firmware calls

[route: software now] Settled: the system parameter block at `0x1000`, the 35-entry firmware vector at `0x1200` (standard ARC
order) and the 15-entry private vector at `0x1300`, the loader's reading of the block, the tree nodes the firmware builds by
name. Open: component classes, types and keys of every node, the private vector's purpose, which vector numbers `arcldr.exe`
calls, and the exact way the firmware builds the identifier (text-mode setup expects `SGI-320_ARCx86`, `SGI-540_ARCx86` and the `_mp` forms; the image's `SGI-000_ARCx86` is probably a template). Next: read the tree builder (`borg_cpu_install`,
`cpu_makecfgroot`) and enumerate the loader's `call *` sites through the vector.

## Memory programming, graphics split and PCI resources

[route: software now] Settled: memory is sized from sixteen Cobalt bank registers; who writes the processor table; the boot-block
PIIX4, NS87307 and Lithium set-up. Open: how the Cobalt memory controller is programmed and its reset values (not found in the
code read); how `cogfxmem` and `gfxmem_alloc` choose the graphics split; whether the firmware assigns PCI resources for any
device (no generic walk found, boot-device drivers not traced); the meanings of the Lithium `+0x48`, `+0x58`, `+0x60`-`+0x70`
and Cobalt APIC `+0xffc` writes; the small windows at `0xfe000000`, `0xff000000`, `0xff004000`, `0xff018000` and `0xff01c000`;
where the embedded legacy-BIOS image is mapped. Next: read the memory-controller programming and the graphics allocator in the
main module; a capture of the Cobalt and Lithium registers after the firmware's initialisation is not a reset value.

## Cobalt revision values and the older boards

[route: missing source] Revisions `0xa0` and `0xa8` ("Cobalt Lite") disable ECC, memory error reporting and cache-operation
invalidation and move the clock and NMI interrupt entries; which products carried them, and the meaning of the cache
operation interrupt, are not stated. The oldest 320 generation (board revision below 6) uses the primary IDE entry 1 per the HAL
and entry 4 per Linux. Next: a hardware-inventory capture or board photographs; the Cobalt specification.

## HAL names with unknown meaning

[route: software now] Settled by reading the HAL's option routine ([nt-hal.md](../software/visws/nt-hal.md)): the boot options
are `ONECPU`, `PCILOCK`, `INTAFFINITY`, `BREAK`, `ARCINFO`, `SYSCLOCK=`, `PAGEOPENPOLICY=`, `MEMERR=`, `ECC=`,
`BLOCKINTS=`, `INTRROUTE=` and `CACHEOPPOLL=`; `HUGH006` is an `INTRROUTE` value that gives a middle-generation 320 the
newest board's interrupt tables; `TIMERRES` and `CLOCKLEVEL` are not in this HAL. Open: which board or product "Hugh" names, the
use of "Twibble" and the bare strings "Borg" and "Hugh" in the HAL's data, what `PCILOCK`, `INTAFFINITY` and `BLOCKINTS`
change in the routines that read them, which register `PAGEOPENPOLICY` programs, and who sets the flag that makes the
performance counter use the 8254. Next: trace the readers of those flags.

## The uniprocessor HAL and the unread HAL routines

[route: software now] Only `halborg.dll` was decompiled, and only the routines listed in
[nt-hal.md](../software/visws/nt-hal.md); `halbrgup.dll` was compared by symbol list. Not read: PCI resource
assignment, DMA adapters, the V86 BIOS-call path, the display routines and the I2C layers. Next: read them as the platform
and graphics pages need them.

## Linux's ARC loaders

[route: missing binary] Settled negative for the held discs: Visual Workstation Environment 3.0 and ProPack 1.3 Visual Workstation
Edition target the 230, 330 and 550, ship kernels 2.2.15, 2.2.16 and 2.3.99 with the Visual Workstation option off, and contain no
`larc.exe`, `arclx.exe` or `la2210.vw` and no ARC loader source ([boot-path.md](../software/visws/boot-path.md)). Open: the loaders,
how they build `boot_params` (memory size, command line), and the older SGI Linux for the 320 and 540 (Red Hat 6.0 era) that used
them. Next: an SGI Linux 2.2.10-era workstation release or its install floppy images.
