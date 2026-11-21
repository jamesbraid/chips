# SGI Visual Workstation 320 and 540 firmware and NT software: open questions

Open points from [software/visws](../software/visws/README.md). The firmware is not held; everything known about it is
read from NT's HAL and loader, SGI's firmware guide, SGI release notes reposted to Usenet and the public Linux port. The
platform and chip questions are in [visws-open.md](visws-open.md). Each entry: question, routes tried, next route.

## The firmware image and the update package

[route: software now for the first step; then missing binary] No PROM image, update floppy or flash dump is held. Routes
tried: Library search (all roots, mail, text and artifact modes) for the 320 and 540 firmware; the Origami firmware registry
(no entry); a file listing of both held Recovery CD ISOs (CD-1 v1.1 and CD-2 v1.0). The CD-2 installer has an "SGI
Firmware" item that copies a PROM image to a floppy, but its payload sits in InstallShield 3 archives (`data1.cab` and
friends) whose file tables were not unpacked. Next: write an extractor for that archive format (the compression is the
PKWARE implode scheme) and list the files; if a PROM image is inside, it becomes the first firmware held. If not, the
only source is SGI's support downloads, of which no copy is mirrored.

## Shipping firmware version and early release notes

[route: missing source] The notes held start at 1.0002 (see [firmware.md](../software/visws/firmware.md)); there are no notes
for 1.0000, 1.0001 or 1.0003, and the version the first units shipped with is unknown. Next: a release-notes file from
the support site, or a hardware-inventory capture from an early unit.

## The environment block: entry layout and checksum

[route: software now] The block's place (last 8 KiB sector, 24-byte trailer, checksum dword) is read; how entries are
laid out and how the checksum is computed are not. Next: read `HalpCreateShadowTable`, `HalpCopyShadowVariableName`,
`HalpMakeNewImage`, `HalpCheckSumSegment`, `HalpStringCksum` and `HalpGenerateChecksum` in `halborg.dll` (all located by the
debug file, not yet read).

## Flash sector map and the rest of the flash

[route: missing source] The part name `M29F400T` is a HAL symbol; no datasheet is held, so the sector map, and the size of the
firmware code area, are inferred. Next: the part's datasheet; a flash dump.

## The ARC tree and the loader's firmware calls

[route: software now] Only the nodes the HAL looks for are known ("SGI REV INFO", "SYS TYPE", "BOARD REV"), plus that the
system node carries a product identifier; the identifier string, the processor, memory, disk and adapter nodes, and the
firmware-call table `arcldr.exe` uses ("unimplemented firmware vector" with an id) are not decoded. Next: read
`DumpArcInfo`, `HalpFixupCpuRegistryNode` and the registry-node code of `halborg.dll`, and the firmware-vector use in
`arcldr.exe`, to list the calls and the tree.

## Whether firmware assigns PCI resources and sizes memory

[route: missing binary] The HAL enumerates PCI buses and assigns base address registers itself; Linux accepts firmware
assignments if present. Whether the firmware does so first, how it sizes memory, programs the Cobalt memory block and
chooses the graphics buffer split (the HAL only reads the descriptors), and the reset order are not recoverable
without a firmware image. Next: the firmware image (first entry), or a capture of the Cobalt and Lithium registers
after the firmware's initialisation (a post-initialisation read is not a reset value).

## Cobalt revision values and the older boards

[route: missing source] Revisions `0xa0` and `0xa8` ("Cobalt Lite") disable ECC, memory error reporting and cache-operation
invalidation and move the clock and NMI interrupt entries; which products carried them, and the meaning of the cache
operation interrupt, are not stated. The oldest 320 generation (board revision below 6) uses the primary IDE entry 1 per the HAL
and entry 4 per Linux. Next: a hardware-inventory capture or board photographs; the Cobalt specification.

## HAL names and options with unknown meaning

[route: software now] "Hugh" (an interrupt routing mode and a boot option `HUGH006`), "Twibble" (a node string) and the
effects of `BREAK`, `PCILOCK`, `TIMERRES`, `CLOCKLEVEL` and `INTERRUPTAFFINITY` are inferred from names only. Next: read
the option-parsing code and each use (`HalpXtractOptionString` callers) and the `EnableHughInts` consumers.

## The uniprocessor HAL and the unread HAL routines

[route: software now] Only `halborg.dll` was decompiled, and only the routines listed in
[nt-hal.md](../software/visws/nt-hal.md); `halbrgup.dll` was compared by symbol list. Not read: PCI resource
assignment, DMA adapters, the V86 BIOS-call path, the display routines and the I2C layers. Next: read them as the platform
and graphics pages need them.

## Linux's ARC loaders

[route: missing binary] The loaders `larc.exe` and `arclx.exe` and the `la2210.vw` kernel image name are known from
installation reports only. Whether they are in the held SGI Linux CDs, how they build the `boot_params` block (memory size,
command line) from the firmware's descriptors, and who writes the processor table at `0x1e00` are not read. Next: unpack
the held Visual Workstation Environment 3.0 and ProPack 1.3 images and look for the loader and its install notes.
