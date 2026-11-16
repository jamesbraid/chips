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
  flash answers as writable** (`-1` if none), and a pointer to the slot array at `+8`; it probes each present node by calling chip methods `+0x40` then `+0x50`.
  It copies no store contents. So the variable store is a flash region of at most **64 KiB** (`0x10000`), reached on the **first node with writable flash**,
  moved in 8 KiB (`0x2000`) chunks by a request queue (helpers `0xffaf49a0`, `0xffaf49d0`, `0xffaf5540`); EFI keeps a 0x20000-byte runtime copy of the header and slots.
- **Flash address range: unknown.** The 8 MiB flash window at `0xff80_0000` ([os-handoff-tables.md](os-handoff-tables.md#2-the-efi-memory-map)) holds the
  FIT and images; the region offset of the 64 KiB store inside the node flash is set by the chip-object flash methods
  (`+0x40`/`+0x48`/`+0x50`/`+0xa0`/`+0xa8`/`+0xb0`, reached through `0xffa1c2e0`), which were not decoded. Route: read those methods for the sector base, or diff
  the flash of a machine before and after `bcfg boot add`. A model may back the store with 64 KiB of RAM; EFI cannot tell, provided `0x02000008` ops 1 to 3 behave as below.
- **Contract a model must meet (established as the caller's contract):** op 4 returns status 0 and a buffer header whose first-writable-node short is not -1
  (otherwise `0x8000...` store errors are returned and EFI starts with an empty set: `PlInitNvVarStoreFlash` ignores the status); ops 1/2/3 take
  (offset, length, buffer) and return 0. A store that always reads back all `0xff` (erased) is a valid empty store.

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
  `entry byte 1 & 0xf`: values above 4 print "unsupported El Torito boot media type" (the `cmp ltu 4` test at `0x5d410`); the per-type handling of 0 to 4 (no emulation, 1.2/1.44/2.88 MB floppy, hard disk) was **not decoded**
  (inferred: all five accepted).
- The `Fat` driver then mounts the child handle if the image holds a FAT file system, which is how a stock ELILO CD works: the boot catalog's image is a FAT volume holding `\EFI\BOOT\BOOTIA64.EFI` (ELILO) and its config. **A bare ISO 9660 file tree with
  no FAT El Torito image is unreachable from this EFI**: there is nothing to read ISO files. (Inferred from the absence of a driver; established that no ISO 9660 reader is among the 166 source names.)
- Boot: the default CD option boots `\EFI\BOOT\BOOTIA64.EFI` on that handle; from the shell, `fsN:` then the file name runs it.

**Disk (FAT ESP).** `Partition` finds GPT (`PartitionCheckGptEntry` and the EFI system-partition type GUID) or MBR partitions, `Fat` mounts a FAT12/16/32 partition. A bootable-by-default file system needs
`\EFI\BOOT\BOOTIA64.EFI` or a `Boot####` option naming the partition's HD node and the loader path.

**PCI devices and option ROMs.** The IOC4 needs no option ROM and no BIOS emulator: its driver (`Ioc4AtapiScsiPassThruDriverBindingSupported` `0x1584c0`) tests the PCI config
vendor/device (`10a9:100a`) through the PciIo protocol, `Start` enables PCI attributes `0x700` (I/O, memory and bus master), and the pass-through then talks to the IDE task-file registers (`Ioc4WritePortB` writes
through a register-offset table in the image's data at `0x200880`; resets wait for BSY to clear with a 31,000-unit bound). The BIOS emulator and `PciVgaMiniPort`/`VgaClass` exist only to run a VGA option ROM (efi.md section 1); an IDE or SCSI
**option ROM is not run**. What a model must supply: a PCI root bridge answering config reads for vendor/device and class through SAL `0x01000010`/`0x01000011` (and I/O or memory BAR access through SN SAL `0x02000052`),
an IOC4 whose IDE registers behave like an ATA task file with BSY/DRQ and PIO data transfer (**unknown**: the register-level contract of the IOC4 ATA pass-through was not read), and `cpuid[2]` not equal to
`0xaeeeeeee8badbeef` (the simulator signature that makes the three pass-throughs decline, efi.md section 5).
No interrupt is needed by the pass-through as read (it polls: the `Stall` calls and BSY loops); that is **inferred**, since the interrupt path was not traced.

## 4. Unknowns and routes

- The flash offset and sector map of the 64 KiB variable store, and the chip-object flash methods behind `0x02000008` ops 5 to 7: decode the node chip object's methods
  at `+0x40`/`+0x48`/`+0x50`/`+0xa0` to `+0xb0` (reached through `0xffa1c2e0`), or compare flash before and after `bcfg`.
- The El Torito per-media-type handling and the exact no-emulation sector count: finish the jump table of `PartitionInstallElToritoChildHandles` (the decompiler truncates it; disassembly at `0x5d410`).
- The IOC4 ATA pass-through register contract (`Ioc4WritePortB`, `Ioc4StatusWaitForBSYClear`, PIO read path) and whether interrupts or DMA are used.
- The ACPI root-bridge node values in device paths, and whether `BootOrder` auto-boot reaches the shell option on an empty machine (a model run).
- Whether SGI shipped media use a FAT El Torito image or a different layout: no SGI install medium is held (stage 5 of the boot path).

**Reviewer status.** Not yet reviewed by a second reader.
