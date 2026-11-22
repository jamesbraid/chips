# SGI Visual Workstation 320 and 540 firmware and NT software: open questions

Open points from [software/visws](../software/visws/README.md). Two firmware images (PROM 1.0006 and PROM 1.1005) are held and read; the rest is
read from NT's HAL and loader, SGI's firmware guide, SGI release notes reposted to Usenet and the public Linux port. The
platform and chip questions are in [visws-open.md](visws-open.md). Each entry: question, routes tried, next route.

## The firmware image and the update package

[settled for 1.0006 and 1.1005; route: missing binary for the others] SGI's PROM 1.0006 and 1.1005 update packages are in a public
driver archive already mirrored; their flash images, the flash tool (`flash_upgrade`, header ranges, boot-block protection, environment
sector preservation) and the differences are in [software/visws/firmware.md](../software/visws/firmware.md). Still not held: the versions
between (1.0002 to 1.0005, 1.1002 to 1.1004). Open: the compiled floppy-making script of the 1.1005 installer (how it places the image
on the floppy), and the purpose of the word at offset `0x1c` of the `SHDR` header (`0x01011e6d` in 1.0006, `0x21b64a13` in 1.1005; the loader's
use of it was not read). Next: the 1.1xxx packages from SGI's support site (no stable address on record); decode the installer script.

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

[route: software now] Settled: the sector map is the table in the firmware (`1.0006@0xfcbef0`, eleven sectors), the part id words the code
tests are `0x20` and `0xd5` (the usual codes for an M29F400T; no datasheet is held, so the part is inferred), and the module table, boot
block and self-test module are mapped. Not yet read: the Pentium II and III microcode tables, the disk, network and SCSI drivers and the
diagnostics in the main module. Next: the part's datasheet; read those parts of the main module.

## The ARC tree and the loader's firmware calls

[route: software now] Settled: the system parameter block at `0x1000`, the 35-entry firmware vector at `0x1200` (standard ARC
order) and the 15-entry private vector at `0x1300`, the loader's reading of the block, the tree nodes the firmware builds by
name. Settled since: the vectors both loaders call (fourteen, [boot-path.md](../software/visws/boot-path.md)) and what `ARCINFO` prints. Open: component classes, types and keys of every node, the private vector's purpose, what firmware revision Windows 2000 setup's PROM check expects of a PROM, and the exact way the firmware builds the identifier (text-mode setup expects `SGI-320_ARCx86`, `SGI-540_ARCx86` and the `_mp` forms; the image's `SGI-000_ARCx86` is probably a template). Next: read the tree builder (`borg_cpu_install`,
`cpu_makecfgroot`).

## Memory programming, graphics split and PCI resources

[route: software now] Settled: the memory controller's bank registers are written by the self-test module's RAM probe and read by the main
module; `gfxmem_alloc` and the `cogfxmem` parsing; the Lithium `+0x48`/`+0x58`/`+0x60`-`+0x70` values and what selects them; the Lithium bus numbering
(B is bus 0); the PCI-PCI bridge assignment code ([boot-path.md](../software/visws/boot-path.md#memory-controller-and-graphics-memory)). Open: the
memory controller's reset values and the meaning of its `+0x08`, `+0x10`, `+0x18`, `+0x28` and `+0x30` registers (named by use only); which probe outcome
stores bank value 3, 2 or 0; whether the firmware reads DIMM SPD data (none found); the bit meanings of the Lithium writes; what the windows at
`0xf8000000` to `0xfb000000`, `0xfc800000`, `0xfd800000`, `0xfe000000`, `0xff000000`, `0xff004000` and `0xff018000` are for; what the word at
`0xff01c004` is (the registry's "Serial I/O"); whether the firmware assigns resources to endpoint devices; whether ports `0xcf8`/`0xcfc` and the
Lithium windows are the same configuration route; where the embedded legacy-BIOS image is mapped; the factory default of `cogfxmem` (none found).
Next: trace the SCSI, IDE and network drivers' use of the PCI code; read the self-test module's remaining tests.

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
