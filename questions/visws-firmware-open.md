# SGI Visual Workstation 320 and 540 firmware and NT software: open questions

Open points from [software/visws](../software/visws/README.md). Two firmware images (PROM 1.0006 and PROM 1.1005) are held and read; the rest is
read from NT's HAL and loader, SGI's firmware guide, SGI release notes reposted to Usenet and the public Linux port. The
platform and chip questions are in [visws-open.md](visws-open.md). Each entry: question, routes tried, next route.

## The firmware image and the update package

[settled for 1.0002, 1.0004, 1.0005, 1.0006 and 1.1005; route: missing binary for 1.1002 to 1.1004] SGI's PROM update packages for those five
releases are held; their flash images, the flash tool (`flash_upgrade`, header ranges, boot-block protection, environment
sector preservation) and the differences are in [software/visws/firmware.md](../software/visws/firmware.md). "PROM 1.2" in SGI's notes is
1.0002. Still not held: 1.1002 to 1.1004, and anything after 1.1005. Settled: the word at offset `0x1c` of the `SHDR` header is a
checksum word that makes the table and compressed modules sum to zero (all five images). Open: the compiled floppy-making script of the
1.1005 installer (how it places the image on the floppy), whether the loader tests that word, what Lithium `+0x40` and the
audio host-control store at `0xff001000` (now read) mean, and what the 1.0004 CPU configuration check does on a mismatch. Next: the 1.1xxx packages from SGI's support
site (no stable address on record); decode the installer script.

## Shipping firmware version and early release notes

[route: missing source] The notes held start at 1.0002 (see [firmware.md](../software/visws/firmware.md)); there are no notes
for 1.0000, 1.0001 or 1.0003, and the version the first 320s shipped with is unknown. The first 540s shipped with 1.0004 (the
1.0004 package notes say so). The held 1.0006 package's own ReadMe repeats the 1.0002 to 1.0006 entries and adds nothing earlier. Next: a release-notes file from
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

[route: software now] Settled for PROM 1.1005 ([boot-path.md](../software/visws/boot-path.md#arc-firmware-services-tree-and-descriptors-at-byte-level-11005)): the parameter block
writer, all 35 firmware vector entries and the thunk and target of each, the file table and the Open, Read, Write and Seek rules, the
tree nodes' classes, types, keys, identifiers and data, the identifier builder (`SGI-<model>_ARCx86_mp`), the memory descriptors, and the layout behind Windows 2000 setup's PROM check. Open: the private vector's targets,
the direction of setup's PROM comparison, the PIIX4/82557/UHCI/ISP1080/FDC register sequences, the RAM probe values that feed the descriptor builder, the merge and trim rules in the graphics
memory allocator, the setter of the flag at `0x114cd44`, and everything above for PROM 1.0006 and older (not re-read). Next: read the drivers' attach and strategy routines one by one.

## Memory programming, graphics split and PCI resources

[route: software now] Settled: the memory controller's bank registers are written by the self-test module's RAM probe and read by the main
module; which probe outcome stores bank value 3, 2 or 0; `gfxmem_alloc` and the `cogfxmem` parsing; the Lithium `+0x48`/`+0x58`/`+0x60`-`+0x70` values and what selects them; the Lithium bus numbering
(B is bus 0); the PCI-PCI bridge assignment code and that the firmware assigns every BAR and bridge window itself; where the embedded legacy-BIOS image goes
([boot-path.md](../software/visws/boot-path.md#memory-controller-and-graphics-memory), [prom-console-path.md](../software/visws/prom-console-path.md)). Open: the
memory controller's reset values and the meaning of its `+0x08`, `+0x10`, `+0x18`, `+0x28` and `+0x30` registers (named by use only); whether the firmware reads DIMM SPD data (none found); the bit meanings of the Lithium writes; what the windows at
`0xf8000000` to `0xfb000000`, `0xfc800000`, `0xfd800000`, `0xfe000000`, `0xff000000`, `0xff004000` and `0xff018000` are for; what the word at
`0xff01c004` is (the registry's "Serial I/O"); whether ports `0xcf8`/`0xcfc` and the
Lithium windows are the same configuration route (the PROM's scan uses the ports, its set-up the window); the factory default of `cogfxmem` (none found).
Next: trace the SCSI, IDE and network drivers' use of the PCI code.

## What the PROM console needs: points the access-level reading left open

[route: software now unless stated] From [prom-console-path.md](../software/visws/prom-console-path.md), 1.1005 only.

- **The register at `0xc6000048` on revisions other than `0xa0` and `0xa8`.** The "DIMM Speed Check" reads it as a fixed address and wants
  bit 16 set; its other bits and its reset value are unknown. Settled by the Cobalt specification, or a read on a machine the owner names.
- **Which boot mode a second start with persistent CMOS takes.** Extended CMOS byte `0x8b` bit 0 is tested and cleared by the self-test and
  set by nothing in the three modules; the path through "reset for BIST" and the extended set depends on it, and on whether the write to
  the Cobalt processor block's `+0x18` resets. Next: the serial manager's `wc` and `rs` commands, and a run with a persistent CMOS image.
- **The retry around the extended set.** Extended bytes `0x85` and `0x86` are set on a soft failure in extended mode and a loop at
  `test+0x44f6` re-runs the first pass; the exit condition was not decoded.
- **Whether PIIX4 function 0 registers `0x90` (bytes 0 and 3), `0x95` and `0xb2` hold written values, and whether the Lithium window ignores the low two address bits.** The "PCI Bus B" test walks them; the PIIX4
  datasheet's register map and the Lithium specification settle it.
- **How the V86 monitor treats the embedded BIOS's port accesses** (keyboard controller, speaker, 8259 and DMA, the interrupt
  redirection and I/O bitmaps of the V86 task), whether a VGA text mode is ever visible to an operating system, and whether the
  scan of `0xc0000` to `0xe0000` finds ROM images copied to `0xc0100`. Next: read `1.1005@0x1108c70`, `0x1109510` onwards and
  `0x11076d0` callers, and the BIOS start-up code at `0xf8000`.
- **Other processors' local vector tables.** Inferred from the absence of writes; the microcode and cache hook routines were scanned,
  not read. Settled by reading `1.1005@0x1131239`, `0x1131410`, `0x1103160`, `0x110404d`.
- **A20GATE.** What drives the PIIX4's A20GATE input on this board stays open; the PROM never sets A20 itself.
- **Earlier releases.** 1.0002 to 1.0006 were not re-read for this page; the RAM probe is the same through the shared boot block and
  self-test, the main-module addresses are not.

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

[route: loaders read] Settled negative for the held discs: Visual Workstation Environment 3.0 and ProPack 1.3 Visual Workstation
Edition target the 230, 330 and 550, ship kernels 2.2.15, 2.2.16 and 2.3.99 with the Visual Workstation option off, and contain no
`larc.exe`, `arclx.exe` or `la2210.vw` and no ARC loader source ([boot-path.md](../software/visws/boot-path.md)). Two loaders, the SGI
2.2.10 kernel with its two patches and a visws 2.6.0-test2 vmlinux are held and read in
[Linux loader handoff](../software/visws/boot-path.md#linux-loader-handoff). Settled: both loaders' firmware calls and load paths, the
boot block each writes and the registers each leaves, which kernels each can serve, the SGI image's uniprocessor build, early
GDT and paging steps (SGI image), its 112 MB of memory and the source of its build flag. Settled by the 1.1005 trace: the processor state at the loader
call ([boot-path.md](../software/visws/boot-path.md#processor-state-at-the-loader-call)): selector `0x18` is a flat DPL 3 code segment (loads into DS and ES
succeed, stores and the load of SS fault), all RAM is identity-mapped with PG set and CR3 at `0xd00000`, nothing maps virtual `0xc0100000`, IF is clear, and
the NT loader and a Linux loader are loaded by the same COFF path and get the same state; so the SGI 2.2.10 image's opening `lgdt` works and an
unmodified 2.2 or 2.4 kernel stops at its first store.
Open: whether the second loader (`arclx2`, no source or licence held) was used with the held 2.6.0-test2 vmlinux; whether an SMP build of
SGI's 2.2.10 existed; what `larc.exe` is; and whether any loader (`larc.exe` is not held) installed a writable `0x18` before a mainline kernel. Next: a copy of `larc.exe`.

## Reset-to-console trace: what is still open

[route: software now] Read for the 1.1005 image: the boot block, the self-test entry and its CMOS, power-management, serial and processor set-up, the main module's start-up order, the processor wake-up, console selection, the ACPI tables and the load and execute path
([boot-path.md](../software/visws/boot-path.md#reset-to-console-in-order-1005)). Open:

- **PIIX4 reset decode of the flash.** Partly settled by the PIIX4 datasheet (XBCS at `0x4e`, reset `0x0003`, p. 57; BIOS memory
  decode, p. 155): at reset BIOSCS# is always generated for `0xffff0000` to `0xffffffff`, but not for `0xfff80000` to `0xfffeffff`,
  which need XBCS bits 7 and 6, both clear at reset. The firmware writes `0xf4` to `0x4e` in its PIIX4 set-up (boot-path step `0x1a`).
  Open: whether other board logic selects the flash before that write, and whether any flash read in that range comes before it.
  Settles with: a trace of the first flash reads against that write, or the board schematic.
- **The self-test's RAM probe outcomes.** Which probe result stores bank code 3, 2 or 0, and the register tests of Cobalt, Lithium and the display (`test+0x7000` to `0x9600`). Settles with: reading those loops access by access.
- **Self-test exit and BIST re-entry.** The path back to the boot block (`test+0x46b3`) and the extended-CMOS state bytes `0x8a` to `0x8f` that decide whether the self-test resets the processor once. Settles with: reading `test+0x4300` to `0x4700` and `0x6e00` to `0x6fa0`.
- **The meaning of audio host-control bit 8 (`0x100`)** and why only generation 5 gets the `0x4100` store. Settles with: the Lithium specification or the vwsnd register comments.
- **Page `0x00fff000`.** What the idle loop's first dword is. Settles with: reading `1.1005@0x11197aa` and its callers.
- **Panel LED or beeper line** (port `0xfb7` bit 4). The PIIX4 datasheet makes this pin GPO28, a non-multiplexed output (p. 38); what SGI drives it for is unknown. Settles with: the 320/540 service manual or a board trace.
- **Main-module serial line settings** (baud, FIFO) and the `console` value `r`. Settles with: reading the serial driver (`1.1005@0x1127400` and callees).
- **Local APIC LINT0/LINT1 on the other processors** and whether anything restores them before the loader. The boot processor is settled: the V86 case leaves them masked and nothing restores or unmasks them ([boot-path.md](../software/visws/boot-path.md#processor-state-at-the-loader-call)). Settles with: reading the stub's hook list (`1.1005@0x11313xx`).
- **Processor state at the loader call, other releases.** Only 1.1005's main module was read for the GDT relocation, IDT, page tables and the entry state; the boot block's descriptor template is byte-identical in all five held images. Settles with: the same trace of the 1.0006 main module, if a model targets it.
- **A20 at reset.** Partly settled by the PIIX4 datasheet (A20GATE and A20M#, pp. 21 and 26; port `0x92` resets to `0x00`, p. 87): with
  bit 1 clear, A20M# follows the board's A20GATE input and the chip has no fixed reset state. The boot processor reaches above 1 MiB
  with no write to port `0x92`, so on this board A20GATE is high or something else holds A20M# high (inferred). Open: what drives
  A20GATE here (no keyboard controller is identified in the held sources), and whether A20M# has a pull-up. Settles with: the board
  schematic, or a bus capture of A20M# and A20GATE.
- **Exception from a loader before its own IDT.** The stubs enter the V86 monitor's dispatcher, which prints "Unexpected exception" with the frame and, for the vectors traced, halts; the path for vector `0x0d` from a non-V86 task was not traced to its end. Settles with: reading `1.1005@0x1105328` to `0x1105377` against the dispatcher's return values.
- **Whether a stock 320 or 540 runs the V86 task.** It runs only when the PCI scan finds a device with an x86 expansion ROM or `DosBoot` begins with `y`; no scan of the shipped cards was run. It decides whether page 0 is mapped and the local APIC is programmed at the loader call. Settles with: a hardware-inventory capture with the PROM's debug output, or the card list of a shipped configuration.
- **ACPI use.** Whether a Windows 2000 loader or HAL uses the "ACPI-BIOS" node. The pointer, root table and one fixed table exist; no DSDT, FACS or MADT. Settles with: the Windows 2000 loader's handling of that node, or a boot with an ACPI HAL.
- **VGA from the legacy-BIOS image.** Whether the "Main BIOS" image provides a VGA service. Settles with: disassembling that real-mode image.
- **PCI access order and drivers.** The driver registry (PCI ids and attach routines) is read; the configuration cycles of the device scan in order and the 82557, UHCI, ISP1080 and floppy controller register use are not. Settles with: reading the attach routines listed in [boot-path.md](../software/visws/boot-path.md#boot-devices-and-drivers-11005) and their strategy routines.
- **Floppy recovery to the last cluster**, including what `SGISETUP.EXE` is expected to do with mode 8. Settles with: reading `0xffffe0xx` onwards in the boot block and a recovery floppy image.
