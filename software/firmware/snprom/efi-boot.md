# The EFI boot path: boot options, device paths and what the shell needs

How the SAL 5.04 PROM's EFI (SHub 1, snprom 10.54) finds something to boot: the variables it reads, where they are stored,
the device paths its disk drivers build, whether it boots by itself or stops at the shell, and what it takes for the shell to
run an `.efi` loader such as ELILO from an IOC4 ATA CD or a disk. It extends [efi.md](efi.md) (container, hand-off, console,
the boot-manager mechanism) and ends the question stage 5 of [the Altix 350 boot path](../../../platforms/sn2/boot-path.md#5-boot-loader-elilo) leaves open.

Image: `shub1snprom.bin`, snprom 10.54 build 70399, sha256 `51ccf9ad830b85ee6c88d6d73d2512322a86454e63db51c57454679283a34617`. The EFI
component is the gzip ELF of FIT type `0x1f`. EFI function addresses are Ghidra-export addresses (ELF address plus `0x100000`, as in efi.md);
`0xff......` addresses are SAL_B machine addresses. Read in Ghidra with the IA-64 processor module (decompile of all 2,344 EFI functions, and
SAL_B read without auto-analysis from the dispatch table's handler addresses); decompiler output was navigation, and every constant quoted
here is a literal in the decompile or the table bytes. No emulator was run.

**Grades.** *established*: the function or table was read and the constant decoded. *inferred*: reasoned from call shape, strings or a
sibling. *unknown*: not settled, with the route.

## 1. Boot options and the variables

**Variables (established).** All boot-manager state lives under the global variable GUID `8be4df61-93ca-11d2-aa0d-00e098032b8c`
(EFI 1.10 `EFI_GLOBAL_VARIABLE`): `Boot0000`..`BootFFFF` (name `Boot%04x`), `BootOrder` (array of u16), `BootNext`, `BootCurrent`,
`Timeout` (u16 seconds), `Driver%04x` and `DriverOrder`, `Lang` and `LangCodes`, and `ConIn`, `ConOut`, `ErrOut` with their `*Dev` forms
(`SetConsoleVariables`). The boot manager's `BmReadVariables` (`0x10cbd0`) enumerates every variable with `GetNextVariableName`, keeps those under
this GUID, parses `Boot####` and `Driver####` into option lists, then orders them by `BootOrder` and `DriverOrder` (`BmOrderOptions`).
**SGI-specific variables read by the PROM's EFI:** `NoVGA` and `VGACons` (VGA choice, efi.md section 3 and 5). No other SGI variable
name was found in the boot manager; the `bcfg`, `dmpstore` and `set` shell commands read and write the same store (strings of the shell help).
Shell aliases and `set` values are stored in the same variable store (shell help text: "stored in EFI NVRAM").

**Where the store lives (established for the access path, unknown for the flash address).**
- EFI reads and writes the store only through SAL callback id `0x8000000000003000` (`RtPlReadStore` `0x122450`, `RtPlUpdateStore` `0x1226d0`,
  `RtPlClearStore` `0x1222d0`): operation 1 clears a byte range, 2 reads one and 3 updates one, after a bounds check against the store size.
  Each passes the request to `RtSalCallBack` (`0x122c80`) with the offset, length, buffer (physical when `psr.dt` is on) and the store's cookie.
- The callback table row for id `0x...3000` in SAL_B (row 99 of the table at `0xffc25ec8`) points at the descriptor of SAL id `0x02000008` (handler `0xffb182c0`),
  so one SAL_B routine serves both the set-up call and the store traffic. Its operations (established, switch on the second argument):
  0 (`0xffad4ec0`, a per-node bitmap walk; role not decoded), **1, 2, 3 (clear, read, update: all one helper, `0xffb17e40`)**, 4 (set-up), 5, 6, 7 (three
  chip-object methods at `+0xa0`, `+0xa8`, `+0xb0` of the node chip's method table: flash chip operations, not decoded). Any other operation returns -2.
- **Operation 4 (established).** Called once from `PlInitNvVarStoreFlash` (`0x121d60`) with flash id (`<= 0x10`), store size (`<= 0x10000` bytes), the buffer and
  its length (0x20000). It writes the buffer header: an int count of request slots that fit (each slot is `0x2020` bytes), a short **index of the first node whose
  flash answers as writable** (`-1` if none), and a pointer at `+8` to the work area that follows the slots (the request queue the helpers use; the slots themselves start `0x2010` into the buffer); it probes each present node by calling chip methods `+0x40` then `+0x50`.
  It copies no store contents. So the variable store is a flash region of at most **64 KiB** (`0x10000`), reached on the **first node with writable flash**,
  moved in 8 KiB (`0x2000`) chunks by a request queue (reads go to the first writable node only; clear and update requests are issued for every present node, **inferred** from the helper's loop, whose arguments the decompiler did not name) (helpers `0xffaf49a0`, `0xffaf49d0`, `0xffaf5540`); EFI keeps a 0x20000-byte runtime copy of the header and slots.
- **Flash address range: unknown.** The 8 MiB flash window at `0xff80_0000` ([os-handoff-tables.md](os-handoff-tables.md#2-the-efi-memory-map)) holds the
  FIT and images; the region offset of the 64 KiB store inside the node flash is set by the chip-object flash methods
  (`+0x40`/`+0x48`/`+0x50`/`+0xa0`/`+0xa8`/`+0xb0`, reached through `0xffa1c2e0`), which were not decoded. Route: read those methods for the sector base, or diff
  the flash of a machine before and after `bcfg boot add`. A model may back the store with 64 KiB of RAM; EFI cannot tell, provided `0x02000008` ops 1 to 3 behave as below.
- **Contract a model must meet (established as the caller's contract):** op 4 returns status 0 for a flash id `<= 0x10` and size `<= 0x10000` (otherwise it zeroes the count and returns -2) and writes a buffer header;
  EFI's callers pass op 1 = clear, 2 = read, 3 = update with (offset, length, buffer) and read the status back. With a first-writable-node short of -1, PROM op 2 does not fail: it fills the buffer with `0xff` and returns 0, so a model
  that never reports a writable node still gets an empty, readable (but not persistent) store. `PlInitNvVarStoreFlash` ignores the op 4 status. A store that always reads back all `0xff` (erased) is a valid empty store.

**Record format (inferred from `RtVarParseStore` `0x131be0`, the sample engine's parser, plus the two-bank layout in efi.md).** The store is a sequence of 4-byte aligned
records; `0xffff` in the first u16 ends the log. A record starts with a u16 whose low 12 bits are the record length from the header and whose bit pattern
`(w & 0x8200) == 0x8000` marks it valid and not deleted; a second u16 holds the attributes; the vendor GUID follows (16 bytes) so the name starts `0x14` bytes in;
the name is UCS-2 and NUL-terminated, then the data; the last byte of the record is stored complemented as a commit marker. A CRC-32 and garbage collection
(`RtVarGarbageCollect`, two banks) are the engine's own. Grade **inferred**: the field meanings come from the parser's arithmetic, not from a writer, and the bit
meanings are not confirmed against a captured store. An emulator never needs this layout unless it wants to read variables host-side.

**Auto-boot or Shell (established mechanism, inferred outcome with nothing installed).**
- `InitializeBootManager` (`0x109760`) reads variables, loads drivers (`BmLoadDrivers`), looks for `BootNext` (`BmBootNextOption`), then loops forever on `BmBootMenu` (`0x247da0`).
- With **no `Boot####` and no `Driver####` variable**, `BmReadVariables` calls `BmSetDefaultDriverOptions` and `BmSetDefaultBootOptions` (`0x245e60`) and the defaults get written back:
  one option for each Block I/O handle with `RemovableMedia` set (an ATAPI CD or USB stick), then each file-system handle that is not removable or has no Block I/O, then each
  Simple Network handle (PXE), then each internal-shell handle; `BootOrder` = 0, 1, 2, ... and `Timeout` = 7 (seconds). The boot manager therefore always has options: the `Shell`
  appears last as an option, it is not a fallback of an empty list.
- `BmBootMenu` shows the menu; when `Timeout` is set and the first `BootOrder` entry exists it **auto-boots that entry after the timeout**. If `BmLoad` of an option fails, the loop
  advances to the next option in order (`plVar1` next-pointer step), and the last default option is the internal shell. So: with a bootable CD or disk, it auto-boots it after 7 s; with
  nothing bootable, every failing option is tried and the machine ends at the shell option or, with a console key press, the menu. Grade **inferred** for the fall-through to the
  shell (the loop step was read, the end state was not run).
- Debug-switch bit 10 set bypasses the boot manager entirely and starts the shell directly (efi.md section 4 and 5).

**Boot option contents (established).** A `Boot####` value is the EFI 1.10 load option: attributes, device-path length, description (UCS-2) and a device path, plus optional data.
`BmBootOptionFromHandle` (`0x246730`) builds the default ones from a handle's device path. A file-system option boots `\EFI\BOOT\BOOTIA64.EFI` found by `BmDefaultBootImage`
(`0x10aad0`), and when that file is absent the first `*.EFI` in `\EFI\BOOT`.

## 2. Device paths the disk drivers build

The pass-through drivers create the child handles' paths through their `BuildDevicePath` member; the generic `ScsiBus` driver appends that node to the controller's PCI path
and `ScsiDisk` installs Block I/O. The full path of a disk is `<AltixPciRootBridge ACPI node>/Pci(device,function)/<messaging node>`, then `Partition` adds
a media node. Established from the decompiled `BuildDevicePath` and `GetTargetLun` functions.

| Controller (PCI id) | Messaging node written (bytes) | Valid targets |
|---|---|---|
| SGI IOC4 IDE `10a9:100a` (`Ioc4AtapiScsiPassThruBuildDevicePath` `0x159590`) | type 3, subtype 1 (**ATAPI**), length 8; byte 4 = target >> 1 (primary or secondary), byte 5 = target & 1 (master or slave), bytes 6 and 7 = LUN (u16) | target 0 or 1 only and LUN 0: one channel with a master and a slave. Anything else returns `EFI_NOT_FOUND`. `GetTargetLun` (`0x159870`) decodes the same node. |
| Silicon Image Sil0680 `1095:0680` (`0x195bb0`) | the same ATAPI node | target 0 only (a single device per controller) |
| QLogic ISP12160 `1077:1216` (`0x1893a0`) | type 3, subtype 2 (**SCSI**), length 10; u16 target (Pun) at `+4`, u16 LUN at `+6` | target below `0x20`, LUN 0 |
| SATA (`SataBus`, class 1 subclass 6) | not read | not read |

Media nodes added by the `Partition` driver (`PartitionDriverBindingStart` `0x15bac0`): a hard-drive node (type 4, subtype 1) for an MBR or GPT partition
(`PartitionInstallMbrChildHandles` `0x161260`, `PartitionInstallGptChildHandles` `0x15d880`) and, for a CD, a **CD-ROM node** (type 4, subtype 2, length `0x18`: boot entry number, start and size
of the boot image in 512-byte units; display `CDROM(Entry%x)`) from `PartitionInstallElToritoChildHandles` (`0x15cf10`). An ATAPI CD therefore appears as
`.../Pci(..)/Ata(Primary,Master)/CDROM(Entry0)`; a disk as `.../Ata(..)/HD(Part,Sig..)`. The generic EFI 1.10 text forms are by the specification; the PROM prints them with its own device-path library (`lib/dpath.c`).
The PCI root node is built by `AltixRootBridgeDevicePathConstructor`; its ACPI HID/UID values were not decoded (**unknown**: whether the UID is the SAL bus number or a bus index).

## 3. What the Shell needs to run ELILO from a CD or a disk

**Drivers present (established, from the registration list in `MainEntry` and the assert-string source names).** `AltixPciRootBridge`, `PciBus`, `SataBus`, `ScsiBus`, `ScsiDisk`,
`Ioc4AtapiScsiPassThru`, `QlogicScsiPassThru`, `Sil0680ScsiPassThru`, `DiskIo`, `Partition` ("Partition Driver (MBR/GPT/El Torito)"), `Fat`, `Snp3264`, `PxeBc`, `PxeDhcp4`, USB
(`USBOhciHC`, `UsbBusDriver`, `UsbKeyboard`, `UsbMouse`, `USBMassStorage`), and from the type `0x22` archive `drv_lsisas.efi`, `drv_b57undi64.efi`, `drv_fpswa.efi`.
**No ISO 9660 file-system driver exists** (the only `edk/Drivers/FileSystem` source is `Fat`; no strings for `CD001` file reading, Joliet or Rock Ridge outside the El Torito parser).

**IOC4 ATA CD, El Torito.**
- ATAPI CD media: `ScsiDisk` gives Block I/O with a 2048-byte block. `PartitionInstallElToritoChildHandles` requires block size `0x800`, scans volume descriptors from LBA 16 for a
  boot record (type 0) carrying `CD001` and the 23-byte `EL TORITO SPECIFICATION` id at `+7`, reads the boot catalog at the LBA stored at `+0x47`, validates its header
  (id 1, key `0x55aa`, 16-bit checksum zero) and, for every **bootable entry (byte 0x88)** with a nonzero start, installs a child Block I/O handle on that image. The media type is switched on
  `entry byte 1 & 0xf`: values above 4 print "unsupported El Torito boot media type" (the unsigned compare of 4 against the type at ELF `0x5d410`, so 0 to 4 are accepted: established); the per-type handling of 0 to 4 (no emulation, 1.2/1.44/2.88 MB floppy, hard disk) was **not decoded**.
- The `Fat` driver then mounts the child handle if the image holds a FAT file system, which is how a stock ELILO CD works: the boot catalog's image is a FAT volume holding `\EFI\BOOT\BOOTIA64.EFI` (ELILO) and its config. **A bare ISO 9660 file tree with
  no FAT El Torito image is unreachable from this EFI**: there is nothing to read ISO files. (Inferred from the absence of a driver; established that no ISO 9660 reader is among the 166 source names.)
- Boot: the default CD option boots `\EFI\BOOT\BOOTIA64.EFI` on that handle; from the shell, `fsN:` then the file name runs it.

**Disk (FAT ESP).** `Partition` finds GPT (`PartitionCheckGptEntry` and the EFI system-partition type GUID) or MBR partitions, `Fat` mounts a FAT12/16/32 partition. A bootable-by-default file system needs
`\EFI\BOOT\BOOTIA64.EFI` or a `Boot####` option naming the partition's HD node and the loader path.

**PCI devices and option ROMs.** The IOC4 needs no option ROM and no BIOS emulator: its driver (`Ioc4AtapiScsiPassThruDriverBindingSupported` `0x1584c0`) tests the PCI config
vendor/device (`10a9:100a`) through the PciIo protocol, `Start` enables PCI attributes `0x700` (I/O, memory and bus master), and the pass-through then talks to the IDE task-file registers (`Ioc4WritePortB` writes
through a register-offset table in the image's data at `0x200880`; resets wait for BSY to clear with a 31,000-unit bound). The BIOS emulator and `PciVgaMiniPort`/`VgaClass` exist only to run a VGA option ROM (efi.md section 1); an IDE or SCSI
**option ROM is not run**. What a model must supply: a PCI root bridge answering config reads for vendor/device and class through SAL `0x01000010`/`0x01000011` (and I/O or memory BAR access through SN SAL `0x02000052`),
an IOC4 whose IDE registers behave like an ATA task file with BSY/DRQ and PIO data transfer (established: the register contract is read in [the IOC4 ATA page](../../../devices/ioc4/ata.md)), and `cpuid[2]` not equal to
`0xaeeeeeee8badbeef` (the simulator signature that makes the three pass-throughs decline, efi.md section 5).
No interrupt or DMA is needed by the pass-through (it sets nIEN and polls with `Stall`; read in full, see [the IOC4 ATA page](../../../devices/ioc4/ata.md#6-what-each-consumer-reads-or-needs)).

## EFI memory map on a lone node

What the PROM's memory-descriptor builder (`0xffac8120`, with `0xffacf560` doing the carve-outs and `0xffac7ff0` appending one descriptor) puts in the map for node 0 with N GiB in bank 0, what EFI's `GetMemoryMap` adds, and whether a kernel linked at 64 MiB can load. Read on 2026-11-16 in a flat `ia64-linux-gnu-objdump` listing of `shub1snprom.bin` (sha256 `51ccf9ad...`) and the EFI ELF (`GetMemoryMap`, `AllocatePages`, `FindFreePagesI`, `PlInstallMemoryMap`, with the runtime-type jump table read from the ELF bytes). Nothing was run. [os-handoff-tables.md](os-handoff-tables.md#2-the-efi-memory-map) has the builder's inputs; this section is the resulting map.

**Map for NASID 0, bank 0 of N GiB, N at least 2 (established).** B = `0x30_0000_0000`. The usable length is 31/32 of the bank record (the top 1/32 never appears); for a record under 2 GiB the last `64 MiB - len/31` of it is a type 8 descriptor of attribute 8 (32 MiB for a 1 GiB record). Attributes: 1 UC, 8 WB, 9 WB+UC, `0x1000` WP; bit 63 RUNTIME. "GetMemoryMap" is what EFI returns (descriptor size `0x30`, version 1): its switch on the type (jump table at ELF `0x1a72f8`) ORs bit 63 into types 5, 6 and 13 and passes every other attribute through.

| Start | Size | Type | PROM attribute | GetMemoryMap attribute |
|---|---|---|---|---|
| `0x0100_0000` (AS 0) | 16 MiB | 13 PAL code | `0x8000000000000009` | same |
| B | 64 KiB | 8 unusable | 9 | 9 |
| B + `0x1_0000` | 448 KiB | 6 runtime data | `0x1001` | `0x8000000000001001` |
| B + `0x8_0000` | 3.5 MiB | 4 boot data | 1 | 1 |
| B + `0x40_0000` | 28 MiB (to `+0x200_0000`) | 6 | `0x1009` | `0x8000000000001009` |
| B + `0x200_0000` | 16 MiB (to `+0x300_0000`) | 6 | 9 | `0x8000000000000009` |
| B + `0x300_0000` | 48 MiB (to `+0x600_0000`) | 4 boot data | 9 | 9 |
| B + `0x600_0000` | to B + 31N/32 GiB | 7 conventional | 9 | 9 |
| `0xff80_0000` | 8 MiB | 11 MMIO | `0x8000000000000001` | same |
| `0x1fff_ffff_fc00_0000` | 64 MiB | 12 port space | `0x8000000000000001` | same |
| `0x8_0000_0000` | 32 GiB | 11 MMIO (SHub 1) | `0x8000000000000001` | same |

- **No type 5 descriptor on bank 0 (code path established; the value it tests inferred).** The type 5 start is node base + `0xa0_0000` (block A `+0x28` masked, see [the shadow copy](boot-sequence.md#the-sal-shadow-copy-and-its-destination)); the builder emits a type 5 range only when that start is above the running offset, and after the carve-outs the offset is B + `0x600_0000`. The compare and skip at `0xffacf9f6` (branch to `0xffacfb30`) and the type 5 emitter at `0xffacfa90` were followed, so this is read from the code, not only from the arithmetic. The branch depends on block A `+0x28` being the layout-table constant `0x40_0000`; that nothing rewrites it stays **inferred** ([os-handoff-tables.md](os-handoff-tables.md#2-the-efi-memory-map)). The 64 MiB conclusion below does not depend on it. The 6 MiB SAL shadow lies inside the `0x1009` type 6 range.
- **What covers `0x0..0x100_0000`.** Nothing in AS 0, and nothing at low physical addresses at all, except the PAL descriptor at `0x100_0000` (which is also where the pointer table lives; the PROM reads that RAM through the AS 0 alias, [address map](../../../platforms/sn2/address-map.md#as--0-local-resources-mmrs-and-compatibility)) and the flash and port-space windows. Every RAM descriptor is in the AS 3 window. The pointer table at AS 0 `0x100_0000` is the same RAM as B + `0x100_0000`, inside the `0x1009` type 6 range; the SAL shadow at B + `0xa0_0000` is inside the same range.
- **Block A (B + `0x240_0000`, 6 MiB), block B (B + `0x2a0_0000`, 2 MiB) and the four 1 MiB per-slot regions (B + `0x200_0000` to `+0x240_0000`)** all lie in the type 6, attribute 9 range, as does the PROM's heap behind block A. SAL_B loads the EFI image (memory size `0x255fe8`, 64 KiB aligned) with an arena allocation from the pointer at block A `+0x1f8` (`0xffaf883c` calls `0xffac3da0` with it), so the image is **inferred** to sit in that heap, also inside the same type 6 range. The exact address was not computed.
- **EFI's own allocations (inferred placement, established mechanism).** `PlInstallMemoryMap` hands EFI the largest type 7 range first, then the rest. `AllocatePages` with `AllocateAnyPages` calls `FindFreePagesI`, which keeps the highest-ending type 7 descriptor that fits and takes pages from its top, so EFI's pools, the 16 MiB `SnStartIo` buffer and the 128 KiB variable-store image come off the **top of bank 0**, not the bottom; the bottom of the conventional range stays free. Runtime types (5, 6, 9, 10) are 8 KiB aligned. Sizes and order of EFI's allocations were not enumerated, so the exact end of conventional memory is **not checked**.
- **Where conventional memory starts: B + `0x600_0000`** (96 MiB into the node window), established above.

**What covers 64 MiB (`0x400_0000`).**
- AS 0 form `0x400_0000`: **no descriptor** (established; the PAL range ends at `0x200_0000` and the next AS 0 descriptor is the flash window at `0xff80_0000`). `AllocatePages(AllocateAddress)` there fails, because the EFI page code needs the whole range to be type 7.
- AS 3 form B + `0x400_0000` = `0x30_0400_0000`: **type 4 (boot services data), attribute 9**, inside B + `0x300_0000` to `+0x600_0000` (established). Also not free: EFI only reuses boot data after `ExitBootServices`.
- AS 0 node-4 alias `0x100_0400_0000` is never in the map.

**Where a kernel loads (established for the code, inferred that this machine follows it).**
- **ELILO.** The loader takes `p_paddr` of the lowest `PT_LOAD` as a physical address and calls `AllocatePages(AllocateAddress)` for the span (`alloc_kmem`, ELILO 3.16 `alloc.c`). If that fails and relocation is off it prints `gzip.c(447): relocation is disabled, cannot load kernel` (`ia64/gzip.c:446-447`; the plain loader has the same at `ia64/plain_loader.c:293-294`). With `relocatable` (global or per image) or `-r`, `find_kernel_memory` (`util.c`) takes the lowest `EfiConventionalMemory` descriptor with a 256 MiB-aligned address inside it that still holds the whole span, and the loader shifts every address by `new_addr - ROUNDDOWN(low_addr, 256 MiB)`.
- **The kernel moves by 64 MiB multiples.** `_start` does `mov r3 = ip` and clears the low `KERNEL_TR_PAGE_SHIFT` (26: 64 MiB) bits to get the physical base for its one pinned translation (`arch/ia64/kernel/head.S`, the `itr` block, in the linux-sn2 mirror at 7.3-rc3 and in `linux-history`); `KERNEL_TR_PAGE_SHIFT` is `_PAGE_SIZE_64M` and `LOAD_OFFSET = KERNEL_START - KERNEL_TR_PAGE_SIZE` puts `p_paddr` at 64 MiB (`arch/ia64/include/asm/page.h`, `pgtable.h`). The held SLES 9 SN2 kernel does the same ([SN2 early boot](../../linux/sn2-early-boot.md)). So a 256 MiB shift keeps the alignment, and the kernel runs wherever ELILO puts it. This corrects earlier text here that called the kernel immovable.
- **On this PROM's map:** first type 7 starts at B + `0x600_0000`; the next 256 MiB boundary is B + `0x1000_0000`, so `relocatable` loads the held kernel (span `0x4000000` to `0x4d34d60`) at `0x30_1400_0000` with entry `0x30_1400_8320`. Without it, the `gzip.c(447)` stop is the faithful outcome on this PROM.
- **SGI shipped it that way.** SGI's own example `elilo.conf` for Altix has a global `relocatable` line: SGI ProPack for Linux Start Here, `007-4558-014` (PDF page 63, techpubs root, `library/manuals/4000/007-4558-014/pdf/`) and the Linux Configuration and Operations Guide `007-4633-009` (PDF page 31), both with `prompt`, `timeout=50`, `relocatable`, then the image stanza. ELILO's own `ChangeLog` credits SGI: "kernel relocation on memory error. Based on code from Brent Casavant <bcasavan@sgi.com>" (2001-08-01) and "patch from SGI to fix load offset for relocatable kernels (Jack Steiner, Brent Casavant)" (2002-02-21); `docs/README.txt` documents `relocatable`. That the shipped option exists because SN2 memory does not start at low physical memory is **inferred** (the manuals state the option, not the reason; the map above gives the reason).

**Faithfulness verdict.** The model's report that `0x4000000` is not free matches the PROM: the PROM never describes it as conventional in either address form. The `gzip.c(447)` stop is the PROM's own behaviour for an `elilo.conf` without `relocatable`; no memory-map change is needed. The fix is `relocatable` in `elilo.conf` (or `-r` at the ELILO prompt). The model keeps the PROM's types; conventional memory runs from B + `0x600_0000` to the bank's end, so `find_kernel_memory` finds B + `0x1000_0000` as long as the span fits below the end of the type 7 range.

**Not checked:** the other nodes' banks and the multi-node order; the sort step between the builder and EFI; `AddRange` merging in EFI; what EFI's own allocations and `ExitBootServices` do to the map; whether the SN2 kernel itself needs anything else at its physical base (only its `p_paddr` and `ip` use were read). The kernel was not run.

## 4. Unknowns and routes

- The flash offset and sector map of the 64 KiB variable store, and the chip-object flash methods behind `0x02000008` ops 5 to 7: decode the node chip object's methods
  at `+0x40`/`+0x48`/`+0x50`/`+0xa0` to `+0xb0` (reached through `0xffa1c2e0`), or compare flash before and after `bcfg`.
- The El Torito per-media-type handling and the exact no-emulation sector count: finish the jump table of `PartitionInstallElToritoChildHandles` (the decompiler truncates it; disassembly at `0x5d410`).
- The ACPI root-bridge node values in device paths, and whether `BootOrder` auto-boot reaches the shell option on an empty machine (a model run).
- Whether SGI shipped media use a FAT El Torito image or a different layout: no SGI install medium is held (stage 5 of the boot path).

## Review

Independent re-read on 2026-11-16 against `shub1snprom.bin` 10.54 (sha256 `51ccf9ad...`). EFI ELF re-extracted from FIT type `0x1f` (gzip at `0xffca5ec0`) and read in Ghidra with `--no-analysis` and `@address` lists (24 EFI functions); SAL_B read through `--sn2-prom --no-analysis` (the dispatch table's `sal_<id>` names, plus `0xffb182c0`, `0xffb17e40`, `0xffb140a0`, `0xffb607f0`, `0xffa9ef10`). `ia64-linux-gnu-objdump` was the cross-check for the constants the decompiler hid. No emulator ran.

**Confirmed.**
- Variable GUID `8be4df61-93ca-11d2-aa0d-00e098032b8c` present as bytes in the ELF; `Boot%04x`, `BootOrder`, `BootNext`, `Timeout`, `NoVGA`, `VGACons` present as UCS-2 strings. "No other SGI variable" was not searched exhaustively (not checked).
- Callback id `0x...3000`: row 99 of the table at `0xffc25ec8` points at descriptor `0xffc4b1f0`, entry `0xffb182c0` (same entry as SAL `0x02000008`); `0x...5000` is `0xffb1ba90` (SAL `0x02000002`), `0x...7000` is `0xffb607f0`, `0x...6000` is `0xffb140a0`. EFI side: clear, read and update pass ops 1, 2, 3 to `RtSalCallBack` (disassembly), and the bounds check against the store size is in `RtPlReadStore`.
- `0x02000008`: ops 1, 2, 3 share the helper `0xffb17e40`; op 4 bounds (`<= 0x10`, `<= 0x10000`), slot size `0x2020`, header short = first writable node, chip methods `+0x40`/`+0x50` (and `+0x48`) in the probe loop; ops 5, 6, 7 call methods `+0xa0`, `+0xa8`, `+0xb0`; any other op returns -2. Op 0 calls `0xffad4ec0` (role not read).
- Default options: `BmSetDefaultBootOptions` makes options in this order: Block I/O handles with RemovableMedia set, then file-system handles whose Block I/O is missing or not removable (GUID offsets `0x201908`, `0x201928` read as Block I/O and file system), then Simple Network (`0x201978`), then the fourth handle class. It writes `BootOrder` as 0, 1, 2, ... and then **`Timeout` = 7 as a 2-byte value** (disassembly: `mov r14=7; st2`, name pointer resolves to the UCS-2 string "Timeout"). `BmBootMenu` auto-boots only when `Timeout` is present, tries the next option when `BmLoad` fails, and stops at the entry whose type is 8 (the internal shell); the fall-through to the shell is therefore read, not just inferred, but no run was made (kept **inferred** for the end state).
- `\EFI\BOOT\BOOTIA64.EFI` and `\EFI\BOOT\%s` strings; `BmDefaultBootImage` iterates files and calls `BmIsEfiImageName`.
- Device paths: IOC4 and Sil0680 build type 3, subtype 1, length 8 with bytes 4 and 5 from target and LUN in `+6`; IOC4 accepts target `< 2` and LUN 0, Sil0680 target 0; QLogic builds subtype 2, length 10, target `< 0x20`, LUN 0. El Torito: block size `0x800`, header id 1 and key `0xaa55` (bytes `55 aa`), bootable byte `0x88`, boot catalog LBA at `+0x47`, media type `> 4` rejected (`cmp4.ltu 4,r16`, so 0 to 4 accepted: now **established**, no longer inferred), CD-ROM media node type 4 subtype 2 length 24, `CDROM(Entry%x)` and `Ata(Primary,Master)` strings. No ISO 9660 file-system source name among the strings.
- `0x6000` op 1 calls `0xffa9ef10`, which stores the handler and period in a per-CPU block and arms a timer with vector argument `0xef`; op 3 calls `0xffaebf30`; other ops return -2. (That `0xffaebe90` programs the interval timer vector register was not read.)

**Changed.**
- Op 4's pointer at `+8` points at a work area after the slot array, not at the slot array.
- The model contract for a missing writable node: the PROM does not return an error for it; read returns an erased buffer and success. The earlier text said store errors were returned.
- The store is read from the first writable node only; clear and update visit every present node (inferred).
- El Torito media types 0 to 4 are all accepted (comparison read).

**Not checked.** The record format of `RtVarParseStore`; the Ioc4 ATA register contract; the `Partition` GPT and MBR paths; `BmBootOptionFromHandle` option contents beyond the file path; the SATA bus driver; the PE32+ drivers; the debug-switch bypass; op 0 of `0x02000008`.

## Review (EFI memory map and kernel load address, commit c56b321)

Independent review of chips commit `c56b321` (the section "EFI memory map on a lone node" here and the edits to the ELILO, early-boot and handoff pages). The reviewer did not write it. Method: Ghidra export of the three builders in `shub1snprom.bin` (snprom 10.54), objdump of the type 5 branch, the EFI ELF inflated from the image at `0x2a5ec0` (`GetMemoryMap` jump table), the ELILO 3.16 source tarball, the linux-sn2 tree (7.3-rc3) and the two SGI manuals through the Library `techpubs` root.

**Confirmed.**
- Builders: `0xffac7ff0` appends a 0x28-byte descriptor (type, start masked to 4 KiB, pages = size >> 12, attribute). `0xffacf560` emits, for bank 0, exactly the carve-out table (type 8 attribute 9 to `+0x1_0000`, type 6 `0x1001` to `+0x8_0000`, type 4 attribute 1 for 3.5 MiB, type 6 `0x1009` to `+0x200_0000`, type 6 attribute 9 to `+0x300_0000`, type 4 attribute 9 for 48 MiB) and the PAL descriptor (type 13, `0x1000000`, 16 MiB, `0x8000000000000009`) for the first descriptor. `0xffac8120` sizes a bank as 31/32 of the record in MiB, capped at 16 GiB, emits type 8 attribute 9 for a disabled bank, and the flash (type 11, `0xff800000`, 8 MiB) and port-space (type 12) descriptors. The 64 MiB minus `len/31` type 8 tail is `0xffacf560`'s `xma_hu` by `0x0842108421084211`.
- Type 5: the compare at `0xffacf9f6` (`cmp.ltu`, running offset against the type 5 start) and the skip to `0xffacfb30` are as cited; the emitter at `0xffacfa90` writes type 5, attribute 9, `0x600000`. After the carve-outs the running offset is B + `0x600_0000`, so bank 0 gets no type 5 descriptor when the start is B + `0xa0_0000`. Other banks fail the other half of the test (the start is below the bank).
- `0x4000000` is in the type 4 range B + `0x300_0000` to B + `0x600_0000`; in AS 0 form nothing covers it.
- `GetMemoryMap` (jump table at ELF `0x1a72f8`, 14 relative entries): types 5, 6 and 13 go to `0x2b9d0`, which ORs `0x8000000000000000` into the attribute; all other types go to `0x2b8f0`, which copies it.
- ELILO 3.16: `gzip.c` line 446 is `if (ia64_can_relocate() == 0)` and 447 the message; `plain_loader.c` 293 to 294; `find_kernel_memory` takes `EfiConventionalMemory` only, rounds the start up to 256 MiB, needs `addr + span <= end`; the shift is `new_addr - ROUNDDOWN(low_addr, 256 MiB)`; `relocatable` is a global and per-image option in `ia64/config.c`; the ChangeLog entries credit SGI as quoted. The computed load address `0x30_1400_0000` and entry `0x30_1400_8320` follow.
- Linux: `head.S` does `mov r3=ip` then `dep r2=0,r3,0,KERNEL_TR_PAGE_SHIFT`; `_PAGE_SIZE_64M` is 26; `LOAD_OFFSET = KERNEL_START - KERNEL_TR_PAGE_SIZE`.
- Manuals: `007-4558-014` PDF page 63 (printed 41) and `007-4633-009` PDF page 31 (printed 11) both show the example `elilo.conf` with `prompt`, `timeout=50`, `relocatable`, then the image stanza.

**Changed (fixed above and in [os-handoff-tables.md](os-handoff-tables.md)).**
- The "no type 5 on bank 0" outcome was written as established; the branch is read, but the value it tests (block A `+0x28`) is still inferred. Graded as such; the 64 MiB result is independent of it. The handoff page had lost that caveat in the same commit.
- The handoff page's closing note said the runtime bit is set only on PAL, port-space, flash and MMIO descriptors. `GetMemoryMap` also sets it on type 6 (and 5), so `SetVirtualAddressMap` sees the runtime data ranges too; corrected.
- The `find_kernel_memory` span check starts at the aligned address, not at the kernel's `+64 MiB` placement; both fit in any bank this page models, so the verdict stands.

**Not checked.** The `FindFreePagesI` top-down allocation claim and EFI's own allocation sizes; `AddRange` merging and the sort step; the multi-node and other-bank paths; that a 7.x or SLES kernel boots when shifted (only `head.S` was read); the reason SGI shipped the option.
