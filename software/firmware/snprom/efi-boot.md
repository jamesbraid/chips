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
  (`+0xa0`/`+0xa8`/`+0xb0`, reached through `0xffa1c2e0`), which were not decoded; `+0x40`/`+0x48`/`+0x50` are decoded in [PROM variables](#prom-variables) (the clear command erases blocks `0x10` to `0x1f` of the flash, so the store lies inside `0x100000` to `0x1fffff`). Route: read those methods for the sector base, or diff
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
`.../Pci(..)/Ata(Primary,Master)/CDROM(Entry0)`; a disk as `.../Ata(..)/HD(Part,Sig..)`. The generic EFI 1.10 text forms are by the specification; the PROM prints them with its own device-path library.
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
- **The kernel moves by 64 MiB multiples.** `_start` does `mov r3 = ip` and clears the low `KERNEL_TR_PAGE_SHIFT` (26: 64 MiB) bits to get the physical base for its one pinned translation (`arch/ia64/kernel/head.S`, the `itr` block, in the linux-sn2 tree at 7.3-rc3 and in Linux history tree); `KERNEL_TR_PAGE_SHIFT` is `_PAGE_SIZE_64M` and `LOAD_OFFSET = KERNEL_START - KERNEL_TR_PAGE_SIZE` puts `p_paddr` at 64 MiB (`arch/ia64/include/asm/page.h`, `pgtable.h`). The held SLES 9 SN2 kernel does the same ([SN2 early boot](../../linux/sn2-early-boot.md)). So a 256 MiB shift keeps the alignment, and the kernel runs wherever ELILO puts it. This corrects earlier text here that called the kernel immovable.
- **On this PROM's map:** first type 7 starts at B + `0x600_0000`; the next 256 MiB boundary is B + `0x1000_0000`, so `relocatable` loads the held kernel (span `0x4000000` to `0x4d34d60`) at `0x30_1400_0000` with entry `0x30_1400_8320`. Without it, the `gzip.c(447)` stop is the faithful outcome on this PROM.
- **SGI shipped it that way.** SGI's own example `elilo.conf` for Altix has a global `relocatable` line: SGI ProPack for Linux Start Here, `007-4558-014` (PDF page 63, SGI printed manuals root, `library/manuals/4000/007-4558-014/pdf/`) and the Linux Configuration and Operations Guide `007-4633-009` (PDF page 31), both with `prompt`, `timeout=50`, `relocatable`, then the image stanza. ELILO's own `ChangeLog` credits SGI: "kernel relocation on memory error. Based on code from Brent Casavant <bcasavan@sgi.com>" (2001-08-01) and "patch from SGI to fix load offset for relocatable kernels (Jack Steiner, Brent Casavant)" (2002-02-21); `docs/README.txt` documents `relocatable`. That the shipped option exists because SN2 memory does not start at low physical memory is **inferred** (the manuals state the option, not the reason; the map above gives the reason).

**Faithfulness verdict.** The model's report that `0x4000000` is not free matches the PROM: the PROM never describes it as conventional in either address form. The `gzip.c(447)` stop is the PROM's own behaviour for an `elilo.conf` without `relocatable`; no memory-map change is needed. The fix is `relocatable` in `elilo.conf` (or `-r` at the ELILO prompt). The model keeps the PROM's types; conventional memory runs from B + `0x600_0000` to the bank's end, so `find_kernel_memory` finds B + `0x1000_0000` as long as the span fits below the end of the type 7 range.

**Not checked:** the other nodes' banks and the multi-node order; the sort step between the builder and EFI; `AddRange` merging in EFI; what EFI's own allocations and `ExitBootServices` do to the map; whether the SN2 kernel itself needs anything else at its physical base (only its `p_paddr` and `ip` use were read). The kernel was not run.

## PROM variables

The SAL's own environment (`NoACPIIO`, `DisabledCpus` and others) is not the EFI variable store above. It is a small key and value log in the node's boot flash, read by `getenv` (`0xffad6e30`) and written by `setenv` (`0xffad6c40`), the same design the Origin 2000 and Fuel CPU PROMs use for [their flash log](../../../platforms/ip35/prom-environment.md#flash-log-the-cpu-proms-variables). All of it is read from decompiled bodies of `shub1snprom.bin` 10.54 (SAL 5.04) plus a plain listing for call sites and one data table; the flash-chip methods behind the log were read by their decompiled bodies except a few thin wrappers (read, `0xffacef00`) seen in the listing only.

**1. How a user sets one (established that the command exists; the command handler body was not located).** At the POD prompt (the line editor in `0xffa1bdd0`, entered with the banner "POD entered via ...") the commands are, in the PROM's own help text:
- `setenv [n:NASID] KEY ["STRING"]` sets a variable on one node (default: the local one);
- `setallenv KEY STRING` sets it on every node;
- `unsetenv [n:NASID] KEY` and `unsetallenv KEY` remove it;
- `printenv [n:NASID] [KEY]` lists variables; `initlog [n:NASID]` formats an empty log, `clearlog` clears it (`initalllogs`, `clearalllogs` for every node).

There is no EFI shell or L1 command for it. A first `setenv` on blank flash fails with "PROM log appears uninitialized (see initlog command)", so `initlog` comes first (established: `0xffad67c0`, create flag not set by `setenv`). `NoACPIIO` is read for the local NASID by `0xffb5fc90`; the value goes through a C-style integer parser with automatic base (`0xffa154a0`: leading `0x` hex, leading `0` octal, else decimal), and any non-zero result disables the ACPI I/O rebuild: `setenv NoACPIIO 1`. A missing variable, a blank or unformatted log, and an unparsable value all leave ACPI I/O enabled. Variable names are at most 14 characters and values at most 47 (`0xffadb700`). How the POD prompt is reached on a given machine (debug switch bits `0008 global pod` and `0010 local pod`, an exception, or a POD request) is only partly read; the switch-bit names are strings in the image.

**2. Where it is stored (established for the device and block layout; inferred for the offset of the image within it).** The log lives in the node's 8 MiB boot flash, not in the image file and not in L1 or base-I/O NVRAM. Chip class "SHub" (match on part number `0x4363`, vtable `0xffbd7c18`) maps the flash at `(nasid << 38) | 0x8000000fff800000`, uncached (`0xffacea70`); the probe fails unless the CFI size field gives at least 8 MiB (`0xffaceb80`). The PROM also reaches flash in the `0xff80_0000` compatibility window; whether that is the same device is inferred. The SAL image ends at 4 GiB, so the 6 MiB file maps to flash offsets `0x200000` to `0x7fffff`, and the log sits in the 2 MiB below it. Log blocks are 64 KiB: base block 0 (flash offsets `0x00000` and `0x10000`), chosen by the constant 0 the open routine passes (`0xffad67c0`). Other regions the same code erases by 64 KiB block index: blocks 4 to 11 (the error log) and blocks `0x10` to `0x1f` (the EFI variable store, `0xffb0ad60`, a clear command). The EFI store's exact start is therefore flash offset `0x100000` at most; its record format is above.

Read path for a lookup: `getenv` (`0xffad6e30`) -> open the node's flash object (`0xffad6b30`, `0xffa0fa00`) -> read both block headers (`0xffadbe30`, 28 bytes each, through the chip read method in 4 KiB chunks) -> scan entries (`0xffadcd70`, `0xffadcba0`) of the active block. With flags 0, as `NoACPIIO` uses, opening the flash still takes the node flash lock and stores a 16-bit `0xf0` (AMD reset) at the flash base (`0xffad67c0` -> `0xffaceb00`), and reads are aligned 8-byte loads (`0xffad2940`). Only the CFI probe is skipped on a read, so a read-only flash model must accept that store and serve those reads.

**3. Format (established; header write order and generation handling partly inferred).**
- Header, 28 bytes at the start of each 64 KiB block: bytes `0x00` to `0x0f` erased (`0xff`); `0x10` 32-bit magic `0x504c4f49` little-endian, so the bytes are `49 4f 4c 50`; `0x14` version 1; `0x18` generation. Only the magic is tested on read; the version is not.
- Active block: block 0 unless block 0 lacks the magic, or both have it and block 0's generation is smaller than block 1's (unsigned compare of the raw words). Neither has the magic: the log is "uninitialized" and every read fails as not found.
- Entries start at block offset `0x100` and run to `0xffff`, 64 bytes each (1,020 per block). Byte 0 low nibble = type (`0xf` = end of log, i.e. an erased entry; `1` live variable; `2` a second live kind that compaction keeps, inferred; `3` log record, inferred; `0` cancelled), high nibble = writing CPU (inferred). Bytes 1 to 14 name (NUL-terminated, compared over 14 bytes); bytes `0x10` to `0x3e` value (NUL-terminated, up to 47 characters). No per-entry checksum and no header checksum.
- Set (`0xffadceb0`): find the live entry; try an in-place overwrite that only clears bits (validate, `0xffadb700` with the validate method); if that fails, cancel the old entry (clear the type nibble to 0, `0xffadd1e0`) and append at the first erased slot (`0xffadc9a0`). When the block is full, compact (`0xffadb970`): erase the other block, copy every type 1 and 2 entry, write its header, switch. Unset clears the type nibble. `initlog` (`0xffadc090`) erases both blocks and writes a header with magic and version 1 into block 0, leaving the generation word erased.
- A prepared image that carries `NoACPIIO=1`: flash offset `0x0`: 16 bytes `ff`, magic bytes `49 4f 4c 50`, version `01 00 00 00`, generation `ff ff ff ff` (block 0 wins against an erased block 1 or one without the magic), `ff` to offset `0xff`; at `0x100` one entry: byte 0 `0x01` (type 1, CPU 0), `NoACPIIO` and a NUL at bytes 1 to 9, `ff` filler (or zero), value `1` and a NUL at `0x110`, `ff` for the rest of the 64 bytes; all later bytes `ff`. This is a reading of the code, not a captured store (unknown until compared with a real machine's log).

**4. Writes (established for the command sequences; the chip is read only through CFI).** Every write is under the node's flash lock (`0xfface890`). Flash is 16 bits wide in a command-set-2 (AMD-style) part; word addresses below are in 16-bit words from the flash base.
- Probe (`0xffad22f0`): reset `0xf0` at word 0; autoselect (`0xaa` at `0x555`, `0x55` at `0x2aa`, `0x90` at `0x555`) and read manufacturer at word 0 and device at word 1; reset; CFI query `0x98` at word `0x55`; the query must read `Q`, `R`, `Y` at words `0x10` to `0x12` and primary command set 2 at `0x13`; device size, write-buffer size, number of erase regions (at most 4) and region geometry are read from the query data; reset.
- Erase (`0xffad2730`, per 64 KiB block): `0xaa`/`0x55`/`0x80`/`0xaa`/`0x55` unlock at `0x555`/`0x2aa`, then `0x30` at the sector, then poll for the data to read back as `0xff` (toggle and timeout checks in `0xffad1040`), then a blank check. Sector size comes from the query's region table.
- Program: without a write buffer, per word `0xaa`/`0x55`/`0xa0` at `0x555`/`0x2aa`/`0x555`, then the data word, then poll (`0xffad1860`). With a write buffer (query size field non-zero), `0xaa`/`0x55`, then `0x25` at the sector with word count minus 1, the words, `0x29` at the sector (`0xffad1b30`, up to 32 words). Each program is followed by a read-back compare (`0xffad1820`), and programming a 0 over a 1 is refused ("Cannot program a 0 into a 1").
- So a model needs, for a `setenv` that sticks: an 8 MiB, 16-bit, AMD-command-set flash with a CFI table (including `QRY`), at the node window, with persistent contents. A flash that only reads (RAM-backed or read-only) is enough for `getenv` if it accepts the reset store and the 8-byte reads of the read path, so a prepared image with `NoACPIIO=1` needs no command emulation; `setenv`, `initlog` and the EFI store fail with "Flash PROM not writable" when the probe fails. Erase time-outs follow the poll routine; the poll constants were not decoded.

**5. Other variables that matter for boot (established as read sites, unless marked).** The table of settable names (PROM strings) and the decompiled read sites:
- *Memory and CPU disable:* `DisabledCpus` (`0xffad34a0` `main_early_disable`, `0xffa9f2c0`, `0xffaacbd0`) and `DisCpusReason`; `DisabledMem` (`0xffa1b5e0`, `0xffa6f000`, `0xffa7c010`) and `DisMemReason`; `StopOnDisabled` (`0xffad3ed0`). The POD `disable` command writes these and logs "Permanently disabled". `CPULogSeqNum` and `MemLogSeqNum` count the changes.
- *I/O and ACPI:* `NoACPIIO` (`0xffb5fc90`, set 0; also read by the DSDT builder `0xffb58ca0`: when non-zero, the first generation at SAL `0x45` builds a header-only DSDT, length `0x24` and OEM revision `0x20001`, and no SSDTs, where the no-SSDT guard is inferred from the decompiler only), `NoBiosEmu` (`0xffb3eb50`), `PciBusList1` to `3` (`0xffb69d20`), `PciDebugMask` (`0xffb2cbf0`).
- *Topology:* `NASIDOffset`, `NASIDStride`, `RtrRoutes` (`0xffa4d390`), `GlobalMaster` and `force_coarse` (`0xffa46530`).
- *Diagnostics and tuning:* `Verbose` (`0xffa42500`), `SysctlDebug` (`0xffa8b5d0`), `NoTimeouts` (`0xffa5d850`, `0xffa614e0`), `LogErrors`, `MaxOut`, `MfrOverride` (`0xffa3e1b0`), `CacheSize` (`0xffaebf80`), `AttrCheck` (`0xffa23600`), `WrbWARCnt` (`0xffae3160`), `MemoryRefresh` (`0xffa775c0`). Named in the table but with no read site found in the decompiled set: `ShrMode`, `SysFlushInt`, `SysFlushDur`, `PTCTimeout`, `CRBTimeout`, `NASID` (the read sites may be in functions the decompiler did not produce; unknown).
- *Console:* not selected by a variable. The spec string is the constant `rpd` (system controller path, direct UART, in that order, then the EFI callback console), see [the boot sequence](boot-sequence.md#console-path). The EFI side reads `NoVGA` and `VGACons` ([efi.md](efi.md)).
- *Autoboot:* the SAL has no autoboot variable; the EFI boot manager reads `Boot####`, `BootOrder` and `Timeout` from the EFI store (section 1). The L1 debug switch has bits named `2000 no autoboot`, `0020 default env`, `0100 no disable`, `0400 plain cons`, `0800 no NUMAlink`, `4000 no I/O` (strings only; the code that tests each bit was not traced, so what `default env` does to the lookups above is unknown).
- A simulator signature in the CPU ID makes `getenv` answer only `PartitionID` and `NASID` (`0xffad6640`); that path is a fallback after a failed flash open, not a skip of the flash.

## GetTime and the TOD chip

Why EFI `GetTime` can return month 0, and what a model must present so it returns a real date. Read in Ghidra
(`--sn2-prom --no-analysis`, decompile of the named addresses) and re-checked against a flat `ia64-linux-gnu-objdump`
listing for the byte-lane arithmetic and the probe sequence. `shub1snprom.bin` 10.54, SAL_B addresses. No emulator ran;
independently reviewed (see [the review below](#review-gettime-and-the-tod-chip-commits-d26fa73-and-50487ce)). The call chain above the chip (`RtSNGetTime`, SAL `0x0200000b`, the per-node time record) is in
[the runtime services page](../../sal/runtime-services.md#64-the-time-of-day) and is not repeated.

**What the model must present (the answer).** An IOC4 (PCI `10a9:100a`) on a PIC bus whose BAR 0 + `0x80000` is a byte-wide clock
chip. Reads of `0xff` at logical register 6 select the M48T35-style map; anything else selects the DS1286-style map. Every access is one
byte at `BAR0 + 0x80000 + (reg ^ 3)`. Return host UTC as BCD in the map below. Nothing on the L1 link or in the SHub decides this.

### 1. Branch choice (established)

- Slot 23 of the SHub 1 chip table (`0xfface1e0`) is chip-first. It calls the BCD reader `0xffaf36a0` and only when that returns nonzero
  (it returns `-1` only when no chip object exists) calls the L1 request `0x200e` (`0xffa7f190`). Success from the chip path never
  touches the L1. So a model that answers `0x200e` with six integers but still shows a chip object (the default once an IOC4 is scanned,
  below) never has its L1 reply read.
- **What creates the chip object.** `0xffaf2dc0` (first use only, cached; a failure is cached too) allocates 0x18 bytes, calls `0xffaf2d30`, then the probe
  `0xffaf2870`. `0xffaf2d30` calls `0xffaf2960`, which walks the lboards of the node that `0xffb23930` returns (a stored NASID word, with -2 as a sentinel; it does not search boards) for
  a board whose type class (`brd_type` +5, high nibble) is `0x7` (`0x71` to `0x7f`, the I/O boards) and whose `brd_flags` byte (+9) has bit `0x10`. None: no
  chip, L1 fallback. Found: object `+0` = 1 and `+8` = base + `0x80000`.
- **Who sets that flag (the discovery probe).** The PCI scan `0xffb36020`, for each device number on a bus, reads the id dword of function 0 and compares it with
  `0x100a` (device, bits 31:16) and `0x10a9` (vendor, bits 15:0). A match calls `0xffb32680(nasid, bus slot, device number)`: it finds the lboard of that NASID whose `brd_slot`
  (+10) equals the bus slot and whose class is `0x7`, ORs `0x10` into `brd_flags`, and stores the slot in bits 59:56 and the device index (PCI slot + 1) in bits 63:60 of the
  qword at board `+8`. The stored device index is the scan's device number plus one (established: Ghidra `(param_3 & 0xff) + 1 << 0x3c`, listing `adds r34=1`), and all
  window and configuration arithmetic below uses that stored value. (`0xffaed410` already put the second-PIC-bus bit, address bit 23 of the bus's widget address, in bit 48 of that qword.)
  No strap, no PROM variable and no L1 reply is consulted. The chip is believed present exactly when the scan sees an IOC4 under an I/O board. The simulator signature
  (`cpuid[2]` = `0xaeeeeeee8badbeef`, see the driver section) is the one other branch: `0xffaf36a0` then returns 0 at once without writing the caller's buffer. The caller
  `0xffa1c8d0` does not clear that buffer, so the month is whatever was on its stack (**unknown**). The 1998-01-01 default is written only on a negative status.

### 2. Chip access (established, part identity inferred)

- **Address.** `0xffaf2960` takes the board's `+8` qword (device index, slot, bus bit) and builds the IOC4's address in three steps. (a) Widget base of the PIC:
  `(nasid << 38) + widget * 0x1000000 + 0x8_0000_0000` with bit 63 set, for an even NASID (a SHub; the odd, TIO form uses `widget * 0x10000000` and no `0x8_0000_0000`). (b)
  The window of device index (PCI slot + 1), with `d` its low 3 bits: for `d` 0 to 2, `d * 0x200000`, plus `0x800000` on bus B; for `d` 3 to 7,
  `d * 0x100000 + 0x300000` on bus A and `d * 0x100000 + 0xb00000` on bus B. Widget number is the board's slot. (c) The IOC4's BAR 0, a 32-bit read of PCI configuration offset `0x10` at
  `widget base (+0x800000 on bus B) + 0x20000 + d * 0x1000 + 0x10`, masked with `0xfffff0` and ORed into (a) | (b). The chip window is that value plus `0x80000`
  (`0xffaf2d30`). So it is the IOC4's byte-bus window 0 (BAR 0 + `0x80000`; offsets from the public 2.6.5 IOC4 header), **not** a SHub junk-bus device. A model cannot place it on the junk bus.
- **Access path.** Single byte `ld1` or `st1` at a physical address (`psr.dt` and `psr.i` cleared, `mf.a` after, `0xffa0e5f0`/`0xffa0e6e0`) with bit 63 set (uncached). Register `x` is
  addressed at window + `(x & ~3) + 3 - (x & 3)`, that is `x ^ 3`: bytes are lane-swapped within each 32-bit word. All offsets below are logical registers; the physical byte is `x ^ 3`.
- **Probe, once (`0xffaf2870`, established).** Write `0` to register `0xb`, `0xff` to register 6, `0x80` to register `0xb`, read register 6. `0xff` reads back: layout 0. Anything else: layout 1.
  (Physical bytes `8`, `5`, `8`, `5`.) The PROM cannot fail the probe: an absent or dead chip (reads of 0, writes ignored) selects layout 1, it does not fall back to the L1.
- **Layout 0** (M48T35 / DS1742 family map, **inferred** from the register positions: control at `0x7ff8`, clock in the top eight bytes of the part). Write `0x40` to `0x7ff8`
  (freeze for read), read, write `0` to `0x7ff8`. Seconds `0x7ff9`, minutes `0x7ffa`, hours `0x7ffb`, date `0x7ffd`, month `0x7ffe`, year `0x7fff`; the day-of-week byte `0x7ffc` is not read. Physical bytes
  `0x7ffb`, `0x7ffa`, `0x7ff9`, `0x7ff8`, `0x7ffe`, `0x7ffd`, `0x7ffc`. The part's SRAM is only 32 KiB, so the signature registers below at `0xf7e0` alias to `0x77e0`
  on a 32 KiB chip (**inferred**); a model may decode the full window or mirror.
- **Layout 1** (DS1286 map, **inferred** from the positions: command register at `0xb` whose bit 7 is the transfer-enable bit). Write `0` to register `0xb` (freeze), read, write `0x80`. Seconds register 1, minutes 2, hours 4,
  date 8, month 9, year `0xa`; physical bytes 2, 1, 7, `0xb`, `0xa`, 9. The 1/100 second byte, alarms and day register are not used.
- **Decode.** Each BCD register is read twice; both reads are the same byte. The value is `((b >> 4) & 0xf) * 10 + (b & 0xf)`, with no range check and no masking of control bits in the hours, month or date
  bytes, so the model must keep their upper bits clear (24-hour mode). There is no update-in-progress poll and no latch beyond the freeze write.
- **Year.** `year = BCD(year register) + base`, where the base year comes from `0xffaf2f70` (read first): registers `0xf7e0`, `0xf7e1`, `0xf7e2` (layout 1: `0x20`, `0x21`, `0x22`) must read the characters `N`, `B`, `Y`;
  then the two-digit BCD at `0xf7e3` (layout 1 `0x23`) plus 100 times the BCD at `0xf7e4` (layout 1 `0x24`) is the base. Without the signature the base is `0x7b2` (1970). The result is clamped: below `0x7ce` (1998) it becomes 1998.
  `SetTime` (`0xfface390`) writes 1992 there and the year minus 1992 into the register (runtime services page). A model with no signature therefore stores year minus 1970; with the signature it can hold any base. Milliseconds are 0.
- **Why all-zero reads give month 0 (established).** Register 6 reads 0, not `0xff`, so layout 1 is chosen. Registers 1, 2, 4, 8, 9, `0xa` all read 0: second, minute, hour, date and month are 0. No `NBY`, so base 1970 plus year 0 is 1970, which the clamp raises to
  1998. The record becomes 1998-00-00 00:00:00. Nothing checks the month; SAL returns success and `GetTime` passes it on, so Linux 3.2's `rtc_year_days` indexes with month 0 and oopses.

### 3. Real hardware

- **Does a 350 have the chip? Yes for a base I/O card with an IOC4 (established as printed for the IO9, part and layout unknown).** The Altix 350 owner's guide lists the IO9's IOC-4 as providing "NVRAM and time-of-day clock"
  ([base I/O cards](../../../platforms/sn2/altix-350-base-io.md#the-io9); the IO10 also carries an IOC4, but its time-of-day listing was not checked). With an IOC4 under the base I/O board, the PROM above takes the chip path and never
  asks the L1 for the time on `GetTime`. The L1 does keep its own clock (a BCD timekeeper in the ColdFire `O` L1's address space at `0x2000_07f8`,
  [sysco](https://github.com/jamesbraid/sysco) `software/firmware/l1/sn2-power-time-requests-1.62.1.md`) and answers `0x200e` from it, but on a 350 with an IO9 or IO10 that answer is only the fallback. `SetTime`
  writes both. That the L1 path is taken only for a node with no scanned IOC4 is **inferred** from the order of the two calls; it was not run.
- **Which map the real chip uses is unknown.** The PROM probes at run time; the IP35 monitor uses the same probe ([IP35 PROM time-of-day](../../../platforms/ip35/prom-tod-clock.md)) and the Origin 200/2000 base I/O board carries an M48T35 ([base I/O](../../../devices/baseio/README.md)).
  No document or capture for the 350's part was found, so neither layout can be called the 350's. Either is a valid model; layout 0 needs no extra care for the probe.
- **A faithful "probe fails and the PROM falls back to the L1" does not exist.** The code has no failure return after the chip object is created. The only ways to the L1 are an IOC4-less scan (no `10a9:100a` function 0 on any bus
  under a class 7 board) or an unreadable board list. Neither is faithful on a 350 with an IO9/IO10.

### 4. Model behaviour

- **Option A, matches real hardware: present the chip.** Under the IOC4's BAR 0 + `0x80000`, a byte device with 64 KiB of RAM (or 32 KiB mirrored), which the PROM addresses at `window + (reg ^ 3)`:
  1. RAM: bytes read back what was written, so the probe (register 6 = `0xff`) selects layout 0.
  2. Registers `0x7ff9`..`0x7fff` (excluding `0x7ffc`) return host UTC as BCD at read time: seconds, minutes, hours (24 h), date, month, and year `(year - 1970)` (or `year % 100` with `N`,`B`,`Y` and base digits for the century in `0xf7e0`..`0xf7e4`); a write of `0x40` to `0x7ff8` needs no special behaviour for a model that never changes between reads (it should hold the read value until the write of 0).
  3. Back `0xf7e0`..`0xf7e4` with the same RAM so `SetTime` sticks.
  - The PIC's own byte-lane swap on the IOC4 window cancels the PROM's `reg ^ 3`, so the device behind the IOC4 sees the logical register number. Observed on the emulator; inferred for hardware. A 32 KiB device must mirror (decode 15 address bits) rather than drop accesses above `0x7fff`; otherwise `0xf7e0`..`0xf7e4` neither persist nor read back, and the base year stays 1970.
  4. The IOC4 config space must show BAR 0 as assigned by the PROM at offset `0x10` of the device's `0x20000 + d * 0x1000` window, and the PIC's device windows must carry byte accesses to the IOC4 BAR (the IOC4 model does this already for its other registers).
- **Option B, only for a node with no IOC4: leave it out.** Then GetTime uses L1 request `0x200e`: status 0 then six integers (year as four digits, month, day, hour, minute, second), and the PROM stores them unchanged. This is not what a 350 with an IO9 does.
- **Do not** fill the chip window with zeros, and do not hide the IOC4 to reach the L1 path on a machine that has an IO9 or IO10.

### Open

- Which part and layout the IO9 and IO10 IOC4 byte bus carries: needs a capture or a parts list for the base I/O card.
- Byte-bus strobe and chip-select timing on the IOC4 (the PROM writes control `0x20` elsewhere): no effect on the model's byte reads.

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

Independent review of chips commit `c56b321` (the section "EFI memory map on a lone node" here and the edits to the ELILO, early-boot and handoff pages). The reviewer did not write it. Method: Ghidra export of the three builders in `shub1snprom.bin` (snprom 10.54), objdump of the type 5 branch, the EFI ELF inflated from the image at `0x2a5ec0` (`GetMemoryMap` jump table), the ELILO 3.16 source tarball, the linux-sn2 tree (7.3-rc3) and the two SGI manuals through the SGI printed manuals.

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

## Review (PROM variables, commit eae2bb7)

Independent review of chips commit `eae2bb7`, examined at that revision. The reviewer wrote none of it. Method: the PROM `shub1snprom.bin` (SAL 5.04, sha256 `51ccf9ad830b...`) re-read in the Ghidra IA-64 module (`--sn2-prom --no-analysis` over the named addresses), with the flash command sequences, the string references and the chip-class method table checked in a whole-image `ia64-linux-gnu-objdump` listing and in the image bytes. Nothing was run, and no flash image was built.

**Confirmed.**
- `getenv` (`0xffad6e30`) -> open (`0xffad6b30`, `0xffad67c0`) -> header read (`0xffadbe30`, 28 bytes at `block * 0x10000`, through the read method in chunks of at most `0x1000`) -> scan (`0xffadcd70`, `0xffadcba0`). Header: magic `0x504c4f49` at `+0x10`, version at `+0x14`, generation at `+0x18`; only the magic is tested; block 0 wins unless it lacks the magic or both have it and its generation is smaller (unsigned); neither: status -2, "uninitialized". Base block 0 is the constant the open routine passes.
- Entries: first at block offset `0x100`, stride `0x40`, end at `0x10000`; byte 0 low nibble is the type, `0xf` ends the scan, only type 1 matches a lookup, type 0 (cancelled) is skipped; name at `+1` (14 bytes, compared with a `strncmp`-style routine, so an `0xff` filler after the NUL is harmless); value at `+0x10` (up to 47 bytes). Limits: name 14 characters, value 47 (`0xffadb700`). `initlog` (`0xffadc090`) erases both blocks and writes a header with magic and version 1 and the rest `0xff`. Set: look up, overwrite in place when only bits clear, else cancel (`0xffadd1e0` clears the type nibble) and append at the first erased slot (`0xffadc9a0`); full: compact (`0xffadb970`, copies types 1 and 2, erases the other block).
- `NoACPIIO`: read for the local NASID by `0xffb5fc90` (code reference `0xffb5ff30`); the value goes through a `strtol`-style parser (`0xffa154a0`, whitespace, sign, `0x` hex, leading `0` octal, else decimal) and a non-zero result disables the ACPI I/O step.
- Flash mapping `(nasid << 38) | 0x8000000fff800000` (`0xffacea70`); the probe `0xffaceb80` fails unless the CFI size field (`1 << word 0x27`) is at least `0x800000`. CFI probe (`0xffad22f0`): reset `0xf0`; autoselect `0xaa`@`0x555`, `0x55`@`0x2aa`, `0x90`@`0x555` (word addresses, stored at `2 * word`), manufacturer at word 0 and device at word 1; `0x98` at word `0x55`; `Q`, `R`, `Y` at words `0x10` to `0x12`, command set 2 at `0x13`, region count at most 4. Erase: `0xaa`/`0x55`/`0x80`/`0xaa`/`0x55` then `0x30` at the sector. Program with a write buffer: `0x25`, word count minus 1, the words (at most 32), `0x29`.

**Findings.** The first two bear on the prepared-image recipe.
1. **A lookup is not read-only on the bus.** The page says "with flags 0 ... nothing is written and no flash command is issued". `0xffad67c0` calls chip-class slot `+0x48` unconditionally (`0xffaceb00`), which takes the node flash lock and stores the 16-bit value `0xf0` (AMD reset, `0xffad22b0`) at the flash base, word 0. Only slot `+0x50` (the CFI probe, `0xffaceb80`) is skipped when the flags are 0, so the claim that no probe or CFI query is needed for a lookup is right. Reads are aligned 8-byte loads, taken byte by byte (`0xffad2940`), at most `0x1000` bytes per lock. A model that backs the flash with read-only memory must accept a 16-bit store of `0xf0` to the flash base without a machine check or a logged guest error (a pflash-style device in read-array mode does this naturally), and must serve 8-byte reads. Fix: replace the sentence and add both requirements to the recipe.
2. **`NoACPIIO` has a second reader, in the DSDT builder.** `0xffb58ca0` also reads it (string reference `0xffb595d0`); with a non-zero value the first generation, at SAL `0x45` before the kernel, produces only a 0x24-byte DSDT header (OEM revision 0x20001) and no SSDTs, and prints no "generating DSDT" line. The recipe's stated effect is only the feature 2 branch. Fix: say what a model sees with `NoACPIIO=1` (no SSDTs, header-only DSDT in both kernel passes, XSDT of 4 entries, "ACPI IO disabled" at the OS feature call) and cross-link [the second table pass](../../linux/sn2-early-boot.md#second-table-pass-and-the-dsdt).
3. **The two flash addresses are not reconciled.** The page gives the 8 MiB flash window at `0xff80_0000` (processor view) and the PROM's access address `0xf_ff80_0000` (plus the NASID and bit 63) without saying whether they are one device. The arithmetic fits (6 MiB image at `0xffa0_0000` is flash offset `0x200000`), but a model must decode both. Fix: say the PROM variable code uses only the second, and that the two aliases of one flash are inferred.
4. The simulator-signature path (`0xffad6640`) is reached only when the flash open returns a negative status and the CPU ID register matches; it does not "skip the flash". The decompiler lost the open routine's return type here, so the statement is from the decompiled branch only.
5. Type 2 ("a second live kind"), type 3 ("log record") and "high nibble = writing CPU" rest on the compaction test, a special case for type 3 in the scan helpers and a stored `cr.lid` field; they are **inferred**, not established. The page's grade line says "established ... partly inferred"; mark these three.

**Prepared-image recipe.** The bytes as written satisfy the code: header at offset 0 (`0xff` for 16 bytes, `49 4f 4c 50`, `01 00 00 00`, `ff ff ff ff`), `0xff` to `0xff`, entry at `0x100` with byte 0 `0x01`, name and NUL, value and NUL, all other bytes `0xff`; block 1 and everything after stay erased. That image is read as a type 1 entry named `NoACPIIO` with value `1`. The recipe is correct for the lookup once findings 1 and 2 are added; the flash must sit at flash offset 0 of the node's 8 MiB window with the PROM image at offset `0x200000`.

**Verdict.** Accept the format, the lookup and the write-sequence claims; fix findings 1 to 3 before a model session builds from the recipe, and mark finding 5.

**Not verified.** The command handler that parses `setenv` (the page says it was not located); the POD entry paths and debug switch bits; the poll, toggle and blank-check routines and time-outs; the "Cannot program a 0 into a 1" check; the non-buffered program sequence (`0xa0`); the chip-class match on part number `0x4363` and the vtable address; the type of `0xffa14ea0` (assumed to copy up to the NUL); the other variables in section 5 beyond `NoACPIIO` and `AttrCheck`; the early mask-list selection. The recipe was not run against a model.

## Review (GetTime and the TOD chip, commits d26fa73 and 50487ce)

Independent re-read on 2026-11-17 by a reviewer who wrote neither commit. Image `shub1snprom.bin` (SAL 5.04, snprom 10.54, sha256 `51ccf9ad830b...`). Method: a flat `ia64-linux-gnu-objdump` listing of the whole image (used for every address below), Ghidra (`--sn2-prom --no-analysis`) on `0xffaf36a0`, `0xffaf2960`, `0xffb32680` and `0xffaf2f70` as a second reading, and Linux 3.2.78 from kernel.org for the oops. No emulator ran. No IRIX source, restricted result or firmware listing was opened or committed.

**Confirmed (established).**

- Slot 23 (`0xfface1e0`) calls `0xffaf36a0` first and calls `0xffa7f190` (request `0x200e`) only when that returns nonzero. `0xffa7f430` sends `0x200d`.
- Chip object: `0xffaf2dc0` caches the pointer and a zeroed 0x18-byte object, calls `0xffaf2d30`, then the probe `0xffaf2870` only if that did not fail. `0xffaf2d30` stores object `+0` = 1 and `+8` = result + `0x80000`, or leaves `+0` = 0 and fails when `0xffaf2960` returns 0. `0xffaf36a0` returns -1 for `+0` = 0.
- `0xffaf2960` walks the lboards of the given NASID for class `0x70` (`brd_type` +5 masked `0xf0`) with `brd_flags` +9 bit `0x10`.
- Discovery: `0xffb36020` compares the id dword with vendor `0x10a9` (4265) and device `0x100a` (4106) and calls `0xffb32680`, which matches class `0x70` and `brd_slot` +10, ORs `0x10` into `brd_flags`, stores slot in bits 59:56 of `+8`. `0xffaed410` deposits address bit 23 into bits 49:48.
- Window arithmetic, all three steps, including the bus-B offsets (`+0x800000` for the low windows and `+0xb00000` for the high ones), the even/odd NASID forms, bit 63, the `0x20000 + d * 0x1000 + 0x10` configuration read, the `0xfffff0` mask and OR (not add) into the window, and the `+0x80000` in `0xffaf2d30`.
- Accessors `0xffaf2710` / `0xffaf27c0` compute `(reg & ~3) + 3 - (reg & 3)`, which is `reg ^ 3`, for a register below 0x10000. The byte access runs with `psr.i` and `psr.dt` cleared and `mf.a` after (`0xffa0e5f0`, `0xffa0e6e0`).
- Probe order and the layout selection (`0xff` at register 6 gives layout 0). Layout 0 reads year, month, date, hours, minutes, seconds from `0x7fff`, `0x7ffe`, `0x7ffd`, `0x7ffb`, `0x7ffa`, `0x7ff9`, never `0x7ffc`, with `0x40` then `0` at `0x7ff8`. Layout 1 reads `1, 2, 4, 8, 9, 10` between `0` and `0x80` at register `0xb`. Every register is read twice, tens digit from the first read and ones from the second, with no masking.
- `NBY` signature (78, 66, 89) at `0xf7e0` to `0xf7e2` (layout 1: `0x20` to `0x22`), base = BCD at `0xf7e3` + 100 x BCD at `0xf7e4` (`0x23`, `0x24`), else 1970. Clamp: a year not above 1997 becomes 1998. `SetTime` stores year - 1992.
- Simulator signature: `cpuid[2]` equal to `0xaeeeeeee8badbeef` makes `0xffaf36a0` return 0 at once.
- Month 0 from all-zero reads, and the oops: Linux 3.2.78 `rtc-efi.c` calls `rtc_year_days(day - 1, month - 1, year)` with unsigned arguments, so month 0 indexes `rtc_ydays` at 0xffffffff.
- Owner's guide: `007-4660-001` printed p.104 says the IO9 "contains an IOC-4 ASIC that supports ... NVRAM and time-of-day clock". The IO10 listing was not checked.
- 50487ce is labelled "Observed on the emulator (not hardware)".

**Needs correction before a model is built from it.**

1. **Device index is slot + 1.** `0xffb32680` stores the scan's device number plus 1 (the Ghidra read shows `(param_3 & 0xff) + 1 << 0x3c`; the listing shows `adds r34=1`). Everything in the window and configuration arithmetic uses that stored value, so the page's `d` is the configuration window number (slot 0 is window 1, as the [PIC page](../../../devices/pic/README.md) says for `pic_attach2`), not the PCI device or slot. Window 1 is `0x200000` and window 4 is `0x700000` on bus A. Read as a slot number the formulas put the chip one window off. The page says "the device number" in the discovery bullet and "PCI device `d`" in the window bullet; both need "device index (slot + 1)". The values themselves match the PIC page's slot pools.
2. **"Zero month on the simulator path" is not established.** That path returns success without writing the caller's buffer. The caller (`0xffa1c8d0`, call at `0xffa1ca3c`) passes a stack buffer it never clears, so the result is whatever was on the stack. The 1998-01-01 default is written only on a negative status (`0xffa1cd30`). Grade: unknown.
3. **The `0xffb23930` gloss is unsupported.** The page says it returns "the node whose board carries the flag below". As far as read it loads a stored word through the global at `0x1000040` + `0x28`, sign-extends it and treats -2 as a sentinel; it does not search boards. "Master node" is plausible but was not traced here.
4. **The lane-swap note and the recipe now disagree.** Option A still says the model has "a lane-swapped address (`phys = reg ^ 3`)" on the device, while 50487ce says the PIC swaps too and the device sees the logical register. A reader who follows both swaps twice. The cancellation is an observation of this repository's own PIC model only; for hardware it fits the IOC4 page's big-endian lane numbering (inferred), nothing more. State once which component swaps.
5. Minor: `0xffaf36a0` also returns -1 when the allocation fails, and fails the layout check (`-1`, message) for a layout other than 0 or 1 in `0xffaf2f70`; neither can occur with the probe as written.

**Grades.** The established items above hold, except the item 2 claim. Inferred stands for the part identity, both register maps (positions match an M48T35-style top-of-SRAM clock and a DS1286-style command register) and the 32 KiB alias at A15. The "L1 only for a node with no scanned IOC4" statement is inferred, as written.

**Not checked.** Who calls `0xffaf2d30` apart from `0xffaf2dc0`; the SHub 2 image; the IO10's time-of-day listing; whether the real part is 32 KiB or 64 KiB; the L1 clock address in the sysco page.
