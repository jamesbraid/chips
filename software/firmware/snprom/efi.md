# The PROM's EFI component (SAL 5.04, SHub 1)

What the FIT's EFI component is, how SAL_B enters it, which configuration tables it installs, how its console reaches
the system controller, where its variables live, how it finds a boot loader on disk, and what an emulated machine has to
provide for it to reach the boot manager menu. It closes stage 4 of [the Altix 350 boot path](../../../platforms/sn2/boot-path.md#4-efi).

Image: `shub1snprom.bin` from snprom 10.54 build 70399, SAL 5.04 rel081111, sha256
`51ccf9ad830b85ee6c88d6d73d2512322a86454e63db51c57454679283a34617`. Container layout is in [README.md](README.md#image-layout),
the call that loads it in [boot-sequence.md](boot-sequence.md#hand-off-to-efi).

**Grades.** *established*: read in the shipped binary (function or table read in full, constants decoded). *inferred*: a
reading from names, call shape or a sibling, with the reasoning. *unknown*: not settled, with the route that would settle it.
Decompiler output was used for navigation and every constant quoted here was re-read from the image bytes or the
disassembly. Function addresses other than `MainEntry` (`0x5000`) are Ghidra-export addresses, the ELF address plus `0x100000`; section bounds, symbol values and data addresses are ELF addresses. The EFI component is a little-endian IA-64 ELF; the retools Ghidra export reads it directly (`re-run
--ghidra-export`, IA-64 ELF support). It refuses non-ELF input, so the three PE32+ drivers in the type 0x22 archive were
checked with a header parser only; **gap:** the export has no PE32+ import, and those drivers are not read beyond their headers.

Sources besides the image: the SAL specification rev 3.4 (Intel 245359-009) section 3.2.3 step 18 and section 3.2.6 with
Tables 3-3 to 3-5; the UEFI PI specification 1.8 volume III section 2 (firmware volume format) and volume I section 16 (Itanium
boot paths) for what the component is not; Linux v5.3 `arch/ia64/sn/kernel/setup.c` and `arch/ia64/include/asm/sn/sn_sal.h`.

## 1. The container

**What it is (established).** FIT entry 11 of the 5.04 `shub1snprom.bin`: type `0x1f`, version 0.01, address
`0xffca5ec0`, length `0xc2510`, gzip. It expands to 2,495,544 bytes: one monolithic IA-64 ELF shared object (type DYN, little
endian, entry `0x5000`, one `RWE` load segment of file size `0x25005d` and memory size `0x255fe8`, 64 KiB aligned, stripped, with
a dynamic symbol table of 2,701 entries and 6,294 relocations in `.rela`). SAL_B's own ELF loader parses, places and
relocates it; nothing about it is a PI firmware volume (no `_FVH` signature anywhere, no file system header, no PE32+ core).
The PI 1.8 firmware-volume format therefore does not apply to the container. Sections: `.text` `0x5000`-`0x1883e0`,
`.rtcode` and `rtcode` (runtime-service code, `0x1883e0`-`0x188550`), `.sdata` `0x189000`, `.data` `0x1a7000`, `.rela`
`0x20f000`, `.dynsym`, `.dynstr`, `.bss` `0x251000` (`0x4fe8`). All addresses are ELF addresses before relocation.

**Modules.** There is no module table. Every driver is linked in, with its own `*DriverEntryPoint` or `Initialize*` function, and
`MainEntry` installs them by name at start-up (section 3). The image carries 166 distinct assert-string source names, in these
groups (counts of files named, not of functions): the core and platform layer `corefw/fw` (38: events, handles, memory pool
and pages, loader with a PE32+ loader, variables with garbage collection, boot manager, a platform tree named for the Altix
board), the EFI Driver Kit layer `edk/Drivers` (80) and `edk/Lib` (3), the shared library `lib` (6) and the EFI shell
`shell` (about 40 commands: `ls`, `cp`, `bcfg`, `flash`, `edit`, `hexedit`, `memmap`, `iomod` and others). A few examples of the
SGI-specific modules, with the size of their registration function: `InitializeAltixPciRootBridge` (4,224 bytes),
`SNSerialConsole` and `SNPlainConsole` (the two consoles, section 4), `Ioc4PassThru`, `QlogicPassThru`, `Sil0680PassThru`,
`sata` (a SATA bus driver), `PciVgaMiniPort`, and the shell command `flash` (SGI PROM flashing utility).

**The type 0x22 component (established).** FIT entry 12, address `0xffd683d0`, length `0x58450`, gzip, expands to a 860,160-byte
tar of three PE32+ images, all machine `0x200` (IA-64), optional-header magic `0x20b`:

| Member | Bytes | Subsystem | Entry RVA | Role (from strings) |
|---|---|---|---|---|
| `drv_fpswa.efi` | 328,192 | 12 (runtime driver) | `0x4c020` | floating-point software assist, source `fpswaefi.c` |
| `drv_lsisas.efi` | 367,616 | 11 (boot-service driver) | `0x46010` | LSI Logic SAS driver, copyright 2001-2006 |
| `drv_b57undi64.efi` | 161,280 | 12 (runtime driver) | `0x22230` | Broadcom NetXtreme UNDI driver, copyright 2000-2005 |

`PlLoadDrivers` (`0x2455b0`) walks the FIT from the pointer at `0xffffffe0`, picks every type-`0x22` entry, gunzips it into an
0x80000-byte buffer, parses the tar and loads each regular file as an image (`PlLoadImage`). The type `0x13` component
(`Bios Emulator`, FIT entry 10, 0x16ab0 bytes) is loaded by SAL_B before EFI (boot-sequence); EFI reaches it through
the `Bios Emulator` interface and the `PciVgaMiniPort`/`VgaClass` drivers for option-ROM video. Not read further.

**The implementation (established for what is named, inferred for the release).** The source names are rooted at a tree
called `efi1_10`, with the layout of Intel's EFI 1.10 Sample Implementation (`corefw/fw/efi`, `corefw/fw/platform`, `shell`,
`lib`) and the driver layer of the EFI Driver Kit (`edk/Drivers`). The system table header carries signature `IBI SYST` and
revision `0x0001000a`, i.e. EFI 1.10, as does the shell's own `ver` text ("EFI Specification Revision : 1.10"). The start-up
banner formats are "`EFI version %d.%02d [%d.%d]`", "`EFI64 Running on Intel(R) Itanium Processor`" and the logon line "`EFI IA-64 SDV/FDK
(No BIOS ) [Nov 11 2008 07:23:32]`", and the image holds the string "Intel EPG Lion BIOS Team - NO EXTRA CHARGE". The build time
matches the SAL banner (rel081111, 07:25:21: the EFI is built two minutes earlier). So this is an **SGI build of Intel's EFI
1.10 sample firmware for IA-64** (SDV/FDK is Intel's name for that firmware set) with SGI platform and driver
code added. The firmware revision words are not set in the system table template (zero in the data) and the code that fills
them was not found, so the sample's build number is **unknown**. The shell's `ver` help text contains the example "EFI Revision : 14.5"; that
is sample output in the help page, not a measurement of this image.

**Cross-check against public trees (the pinned `references/code` trees).**
- EDK I (`edk`, 321b15a, 2010): the driver layer matches by name and, where tested, by string. SGI `edk/Drivers/Console/Terminal`,
  `ConSplitter`, `GraphicsConsole`, `VgaClass`, `DiskIo`, `Partition`, `Snp32_64`, `PxeBc`, `PxeDhcp4`, `ScsiBus`, `ScsiDisk`, `pcibus`
  and `Usb/UsbBus`, `UsbKb`, `UsbMouse` have same-named files under `Sample/Universal/{Console,Disk,Network}`, `Sample/Bus/{Scsi,Usb}`
  and `Sample/Bus/Pci/PciBus`. Strings found in both: "Could not create transmit timeout event" and "Unsupported BIS revision"
  (`Sample/Universal/Network/PxeBc/Dxe/bc.c`), "PXE-E18: Timeout" (`.../PxeBc/Dxe/pxe_loadfile.c`), and the terminal driver GUID
  `10634d8e-1c05-46cb-bb0c-5afdc829a8c8` (`Sample/Universal/Console/Terminal/Dxe/Terminal.c`). The PC-ANSI, VT100 and VT-UTF8 GUIDs the
  image carries are in `Foundation/Efi/Guid/pcansi/PcAnsi.h` and `Foundation/Efi/Include/EfiDevicePath.h`.
- Not in EDK I, EDK II (ba6037f8, the last commit with IPF support) or gnu-efi (3.0.18) by name: the `corefw` core and boot manager (`BmSetDefaultBootOptions`,
  `InitializeBootMaintenance`, "EFI Boot Manager ver", `RtVarGarbageCollect`: no hits in any of the three trees), the shell
  commands, the old FAT driver (`openvol.c`, `dirent.c`, `fspace.c`: EDK I carries a different, "Enhanced" FAT under
  `Other/Maintained/Universal/Disk/FileSystem/EnhancedFat`) and the OHCI USB host driver (EDK I has UHCI and EHCI). Also SGI-only:
  `AltixPciRootBridge`, `SNPlainConsole`, `SNSerialConsole`, `Ioc4PassThru`, `QlogicPassThru`, `Sil0680PassThru`, `sata`.
  EDK I's generic boot manager (`Sample/Platform/Generic/Dxe/GenericBds`, `BmMachine.h`) is a later redesign, not the one in
  this image. EDK II and gnu-efi are not clean: both share text with the driver, core and `lib` layers (counts in the review), so only the layers named above are absent.
- The conclusion (the EFI 1.10 Sample Implementation core, boot manager and shell are not in the public trees) means
  the core's behaviour in this page comes from the image only.

## 2. The hand-off from SAL_B

**Path (established).** `main_three` calls `0xffaf8c50`, which loads the SAL runtime and the BIOS emulator, then prints "Loading EFI
..." (FIT type `0x1f`), loads the ELF with the loader at `0xffaf8690` (parse, allocate RAM with the ELF's alignment on the boot
node, copy and relocate; failure prints "Could not load EFI!  Panic..." and calls the stop routine `0xffa1b940` with arguments `0xbe`, 2), then builds the hand-off
record with `0xffafc140`, writes progress `0x48` and calls the entry with the C calling convention through a function
descriptor `{entry, gp}` (the ELF entry and the loader's gp). The record address is printed as "SAL->EFI handoff at 0x%llx". If EFI
returns, SAL_B calls the same stop routine.

**Arguments (established).** `r32` (first argument) is the value 1; EFI's `MainEntry` (`0x5000`) returns zero at once if it is 0.
`r33` is a pointer to the record. EFI does not use the SAL system table address or the EFI system table address as an
argument: the EFI system table is the one inside the EFI image (`SystemTable`, ELF address `0x1fe268`, 120 bytes), and the SAL system table pointer is
a record field. This is the EFI hand-off the SAL specification delegates to the EFI specification (SAL 3.2.3 step 18; section 3.2.6).

**The record (written by SAL_B at `0xffafc140`, read by EFI `MainEntry`).** SAL_B allocates 0x58 bytes and zeroes them. Offsets are bytes
from the record:

| Offset | Value written by SAL_B | EFI use |
|---|---|---|
| `0x00` | count of memory descriptors | `PlInstallMemoryMap` count |
| `0x08` | pointer to the descriptor array (built by `0xffac8120`) | array of 0x28-byte `EFI_MEMORY_DESCRIPTOR` entries: type (4), physical start (+8), pages (+0x18), attribute (+0x20) |
| `0x10` | `0x1fffc00` | not read by `MainEntry` (unknown) |
| `0x18` | pointer to the SAL system table (built by `0xffafca90`) | installed under the SAL system table GUID `eb9d2d32-2d88-11d3-9a16-0090273fc14d`; read back for the SAL entry points |
| `0x20` | 0 | MPS table slot, GUID `eb9d2d2f-...`; zero, so nothing is installed |
| `0x28` | ACPI 1.0 RSDP pointer (`0xffb5c9b0`) | GUID `eb9d2d30-...` |
| `0x30` | ACPI 2.0 RSDP pointer (`0xffb5a2f0`), also stored in SAL's own data | GUID `8868e871-e4f1-11d3-bc22-0080c73c8881` |
| `0x38`, `0x40` | `0x1fffc00`, `0x1fffc00` | the SAL callback entry pair EFI keeps as `RtGlobalSALCallBack` and calls for flash, timer and reset (below) |
| `0x48`, `0x50` | `0x10`, `0x10000` | passed to `PlInitNvVarStoreFlash` as flash id (`0x10`) and store size in bytes (`0x10000`) |
| `0x58` to `0x70` | not written | EFI reads four more words here (below) |

**Words beyond the record.** `MainEntry` also reads `0x58` and `0x60` (PCI option ROM table count and descriptor pointer; it
installs GUID `7462660f-1cbd-48da-ad11-91717913831c` only when the count is nonzero) and `0x68` and `0x70` (passed to `BuildEfiCoreImageHandle`,
inferred to be the EFI image's own base and size). SAL_B allocates and clears only 0x58 bytes (the wrapper at `0xffafc350` zeroes exactly the requested size from the handoff arena at `0xffac30c0`), so these four words are whatever
follows the record in memory (**unknown**: the arena's own contents were not read). An emulator that jumps to
EFI directly should supply zeros there: that gives no option ROM table and a null core-image record.

**Memory state (established from `PlInstallMemoryMap`).** EFI takes the descriptor with type 7 (conventional) and the most pages,
adds it first to its pool, then adds every other descriptor with a nonzero page count; it asserts if no conventional region exists.
For descriptors of type 9 or 10 (ACPI reclaim, ACPI NVS) or with attribute bit 63 set it first adjusts an adjoining conventional
region by one page. EFI then takes its working memory (a 16 MiB buffer for `SnStartIo`, a 128 KiB variable
store image) from that pool as runtime-data allocations. The SAL system table address `0x18` is the physical address the kernel will later find; the
EFI system table address is the relocated `SystemTable` symbol, not a handed-over value. The Linux kernel reads
`efi_systab` from the boot loader's parameter block, not from the PROM (boot-path stage 5).

**Register and mode state at entry (inferred).** Not decoded: SAL_B's `br.call` leaves the stack, backing store, `psr` and region
registers as the PROM had them (physical mode with no translation is assumed; EFI's `RtPlReadStore` tests `psr.dt` to decide whether to
translate its buffer, so the code runs in both modes at run time). The SAL specification states what SAL
hands an OS loader (section 3.2.4), not what it hands EFI.

## 3. Configuration tables and where SN2 data lives

| Table | GUID | Installed by the PROM's EFI? | Source |
|---|---|---|---|
| SAL system table | `eb9d2d32-2d88-11d3-9a16-0090273fc14d` | yes (record `0x18`); EFI also reads it back | `MainEntry` (established) |
| ACPI 1.0 RSDP | `eb9d2d30-2d88-11d3-9a16-0090273fc14d` | yes (record `0x28`) | `MainEntry` (established) |
| ACPI 2.0 RSDP | `8868e871-e4f1-11d3-bc22-0080c73c8881` | yes (record `0x30`) | `MainEntry` (established) |
| MPS | `eb9d2d2f-2d88-11d3-9a16-0090273fc14d` | no: the slot is written zero | `MainEntry` and `0xffafc140` (established) |
| SMBIOS | `eb9d2d31-2d88-11d3-9a16-0090273fc14d` | no installer exists: the GUID is only read, by shell code | all references to its address read (established) |
| HCDP/PCDP | `f951938d-620b-42ef-8279-a84b79617898` | yes, by `PcdpSetup` (`0x120e60`) unless the `NoVGA` variable is set; entries are added only for PCI VGA devices (class 3, subclass 0): a 2 KiB table, signature `HCDP`, revision 3, OEM id `SGI`, length 0x28 before devices | read; table body unread (inferred) |
| Debug image info | `49152e77-1ada-4764-b7a2-7afefed95e8b` | yes, `InitializeDebugImageInfoTable` | read |
| PCI option ROM table | `7462660f-1cbd-48da-ad11-91717913831c` | only if the record's count word is nonzero | `MainEntry` (established) |

So the PROM builds the SAL system table and both ACPI RSDPs in SAL_B (`0xffafca90`, `0xffb5c9b0`, `0xffb5a2f0`); EFI itself only registers them.
What the ACPI tables contain (an XSDT with OEM id "SGI", the `SGIHUB` DSDT devices that v5.3 `sn_io_acpi_init` needs) is **unknown**: the
three builders were not read. The SAL system table's first entry must be the entry-point descriptor: EFI reads fixed
offsets (the table header is 0x60 bytes in the specification; Tables 3-3 and 3-5), checks the type byte at `+0x60` is 0, takes PAL_PROC from `+0x68`,
SAL_PROC from `+0x70` and the SAL global pointer from `+0x78` (`LibInitSalAndPalProc` `0x1cc800`, established; it does not walk the table).

**What Linux v5.3 `arch/ia64/sn/kernel/setup.c` reads:**
- `early_sn_setup` (line 154): the EFI system table from `ia64_boot_param`, the configuration table array, the entry for the SAL
  system table GUID, then walks its entries for type 0 and takes `sal_proc` and `gp` (this is the only table the SN code reads itself). Matches section 2: type 0 must be present and
  its pointers valid.
- `sn_scan_pcdp` (line 316, only with `CONFIG_VT` and `CONFIG_VGA_CONSOLE`): `efi.hcdp`, the HCDP/PCDP table; skipped if absent or
  revision below 3 (the PROM writes 3); it looks for a primary-console VGA descriptor on PCI. So the PCDP carries the VGA choice made by `SnSelectVGAConsole`.
- `sn_setup` (line 370 on): calls `ia64_sn_set_os_feature(OSF_PCISEGMENT_ENABLE)` and `OSF_ACPI_ENABLE` (SN SAL calls) before
  `acpi_table_init()`, because an ACPI-capable PROM rebuilds the DSDT as a result. That the 5.04 PROM does so is **unknown**.
- ACPI itself is read through the generic `efi.c` and `acpi.c`; SMBIOS and MPS are not used by the SN code.

**Where SN2-specific data lives (inferred from the kernel and the call list).** Not in any EFI table: the klconfig address, node/NASID
maps, I/O and interrupt routing come from SN SAL calls (`GET_KLCONFIG_ADDR`, `IOIF_INIT` and so on) and from the DSDT in ACPI. EFI's own SN data: the SAL
callbacks and the SN console protocol `7ef64632-c950-11d8-b540-08006913e67d` (section 4).

## 4. The console

**Two providers, chosen by a debug switch (established).** `MainEntry` reads debug-switch bit 10 with `chipset_dipsw_get(10)`, a
64-bit load of SHub register `0x81_5003_1560` (the address `0x8000_0081_5003_1560` in the code): bit 10 of the 16-bit
debug-switch word that SAL_B stores there from the L1's reply ([boot-sequence.md](boot-sequence.md), the paragraph on the debug switches). The same bit gates the boot manager (section 5).

- **Bit 10 clear (the normal case): the full driver set.** SNSerialConsole presents the system controller as an EFI serial port
  (`gEfiSerialIoProtocolGuid`), and the generic Terminal driver runs PC-ANSI, VT100, VT100+, VT-UTF8 or xterm over it (the strings
  "SN Serial Console", "PC-ANSI Serial Console", "VT-100 Serial Console", "Xterm Serial Console"). `ConPlatform`, `ConSplitter` and,
  if a VGA device was picked, `GraphicsConsole` complete `ConIn`, `ConOut` and `StdErr`. `SetConsoleVariables` fills `ConIn`, `ConOut`,
  `ErrOut` and their `*Dev` variables when they are empty or lack the SN device.
- **Bit 10 set: a minimal console.** Only `SNPlainConsole` loads: `SimpleTextIn` and `SimpleTextOut` directly over SAL calls with no terminal emulation,
  and the shell (`nshell`) runs instead of the boot manager.

**SAL calls the console uses (established, constants read).** The EFI never touches the UART, the IOC4 or the L1 itself:

| SN SAL id | Used by | Reading (kernel header `sn_sal.h`) |
|---|---|---|
| `0x02000023` | `SNPlainConsoleConOutOutputString`, `early_output` | `SN_SAL_CONSOLE_PUTS`: NUL-terminated ASCII (the EFI narrows UTF-16 to bytes, 1,023 at a time) |
| `0x02000026` | `SNPlainConsoleCheckForKey`, `SerialGetControl` | `SN_SAL_CONSOLE_POLL`: key waiting (second return word nonzero) |
| `0x0200002b` | `SNPlainConsoleConInReadKeyStroke` | `SN_SAL_CONSOLE_READC` |
| `0x02000028` | `SerialWrite` | `SN_SAL_CONSOLE_PUTB`, arguments buffer and length |
| `0x02000029` | `SerialRead` | read bytes: arguments buffer, length and the SerialIo mode's timeout word; the count comes back in the second return word and SAL_B returns -3 when nothing was read (EFI maps that to a timeout); **not named in the v5.3 header** (the header jumps `0x28`, `0x2a`) |
| `0x0200002c` | `console_flush` | not named in v5.3; the firmware page lists `0x21`-`0x2c` as the console range |
| `0x02000021`, `0x02000022` | `console_putc`, `console_getc` | `SN_SAL_CONSOLE_PUTC`, `GETC` |
| `0x0200002d` | `SNConsoleCallbackRegister(1)` at the end of device bring-up | registers EFI's three console callbacks (`SNConsoleCallbackPutb`, `Readc`, `Poll`, which call `ConOut->OutputString`, `ConIn->ReadKeyStroke` and `WaitForKey`) with SAL |

The PROM-side handlers of the console range are in [the SAL runtime page](../../sal/sn2-runtime.md#console-0x02000021-to-0x0200002c).
A SAL call returns its status in the first return word (zero for success); `SerialGetControl` reports `EFI_SERIAL_INPUT_BUFFER_EMPTY`
(`0x100`) when POLL's second word is 0 and `0x20` otherwise.

**Relation to the `rpd` console objects (inferred).** [boot-sequence.md](boot-sequence.md#console-path) lists the PROM's own console
specification string `rpd` and an EFI callback console `e`. The SAL console calls above land in that SAL console layer, which routes the
text to the object `console_probe` selected (the L1 path `p` or `r`, or the junk-bus UART `d`). The `0x2d` registration is the other direction: it
arms the `e` object, so that after EFI is up the PROM's own console traffic is carried by `ConOut`. No IOC4 UART or PCI path is involved
in either direction (established for EFI: no register access outside the SHub; the L1 or UART side is the SAL runtime's and was not
re-read here). Which of `p` and `r` is which route stays **unknown**.

## 5. Boot manager, variables and finding the boot loader

**Order of start-up in `MainEntry` (established, from the registration strings and call order):** `PlInitializeTables`, memory map,
configuration tables, `PlInitSalPalProc`, `PlTimer` (SAL callback `0x6000`, period 10), library init, the core image handle, a watchdog,
`SnStartIo` (SN SAL `0x02000045` with a 16 MiB pool buffer), `PlInstallBaseDevices` (console bus device carrying the SN console protocol,
default I/O, root bridge list, the flash variable store, the unicode device), variable `LangCodes`/`Lang` set to `eng`, drivers
`AltixPciRootBridge` and `PciBus`, the optional VGA choice (`NoVGA`, `VGACons`), then, when bit 10 is clear: `USBOhciHC`, `UsbBusDriver`, `UsbKeyboardDriver`,
`UsbMouseDriver`, `USBMassStorageDriver`, `PciVgaMiniPort`/`VgaClass` (if VGA), `GraphicsConsole`, `SNSerialConsole`,
`Terminal`, `ConPlatform`, `ConSplitter`, connect all drivers, set the console variables, connect the consoles. After the console callback
registration and the banner: `SataBus`, `ScsiBus`, `ScsiDisk`, `Ioc4AtapiScsiPassThru`, `QlogicScsiPassThru`, `Sil0680ScsiPassThru`, `DiskIo`,
`Partition`, `Fat`, `Snp3264`, `PxeBc`, `PxeDhcp4`; the three drivers of the archive (section 1); then `PlInitializeInternalLoad` and, with bit
10 clear, an endless loop that runs the internal commands `bootmgr` and `bmaint` (`InitializeBootManager`, `InitializeBootMaintenance`). With bit 10 set it
prints the hardware report (`BmPlatBanner` calls `HinvReport`), connects everything and starts the shell `nshell`.

**Variables (established mechanism, inferred layout).** A flash-backed store. `PlInitNvVarStoreFlash` (`0x121d60`) allocates 0x20000
bytes of runtime memory, installs the variable store protocol (`f088cd91-a046-11d2-8e42-00a0c969723b`), then calls SN SAL
`0x02000008` with function 4, `0x10` and `0x10000` (the record's `0x48` and `0x50`), the buffer and 0x20000. SAL_B's function 4 only
bounds-checks the first two (at most `0x10` and `0x10000`), fills the buffer header and probes each node's flash for writability; it copies no store data to EFI (reviewed).
Reads, updates and erases go to SAL by the callback pair at `0x38`/`0x40` of the record: `RtSalCallBack(0x8000000000003000, op, ...)` with
op 1 to clear, 2 to read and 3 to update a byte range, after a bounds check against the store size. Time uses SN SAL `0x0a` (set) and `0x0b` (get); reset uses
callback id `0x5000` and the timer callback id `0x6000`. The variable engine (`RtVarFind`, `RtSetVariable`,
`RtVarGarbageCollect`, two banks with transaction state, a CRC-32) is the sample implementation's. "Syncing EFI var. store" is printed by SAL_B
(`0xffaf6640`, `0xffaf6d10`, boot-sequence). The flash chip, sector map and which SAL_B routine implements op 4 and the callbacks were **not read**; with the
store absent or the SAL call failing, `PlInitNvVarStoreFlash` ignores the status, so EFI would start with an empty variable set (inferred).

**Default boot options (established).** With no `Boot####` variable, `BmReadVariables` builds the list: one option per removable
Block I/O handle, then one per non-removable block or file-system handle, one per Simple Network handle (a PXE load) and one per
`InternalShell` handle, numbered from 0 (`BmSetDefaultBootOptions` `0x245e60`); it writes `BootOrder` as 0, 1, 2, ... and `Timeout` as 7 seconds.
The file-system options boot `\EFI\BOOT\BOOTIA64.EFI`, found by `BmDefaultBootImage` (`0x10aad0`) on each handle. Boot options are stored under the global
variable GUID `8be4df61-93ca-11d2-aa0d-00e098032b8c` as `Boot%04x`, with `BootNext`, `BootCurrent`, `BootOrder`, `Timeout`, `Driver%04x`
and `DriverOrder`. The menu text is the sample's: "EFI Boot Manager ver %d.%02d [%d.%d]", "Boot option maintenance menu",
"Default boot selection will be booted in %d seconds", "Boot from a File", "Add a Boot Option", "Change Boot Order" and "Set Auto Boot TimeOut".

**How ELILO is found (inferred for the shipped loader, established for the mechanism).** ELILO is an EFI application on the FAT system partition. A `Boot####`
option written by the installer (a device path to the partition plus a file such as `\EFI\...\elilo.efi`), or `\EFI\BOOT\BOOTIA64.EFI`
through the default option, loads it; the image carries neither an ELILO path nor an SGI-specific default (no ELILO binary or boot
partition is held, boot-path stage 5). Devices reach it through this driver chain: PCI bus driver (config accesses through SAL `0x01000010`/`0x01000011`, the generic
`SAL_PCI_CONFIG_READ`/`WRITE`, SAL spec section 9.3; memory and I/O through SN SAL `0x02000052`, `IOIF_PCI_SAFE`), then a block driver, then `ScsiBus`
and `ScsiDisk` (Block I/O), `Partition` (GPT and MBR: `PartitionCheckGptEntry`, the EFI system partition type GUID), `Fat` (Simple File System):

| Controller | PCI id checked (established) | Driver | Machine |
|---|---|---|---|
| SGI IOC4 IDE (ATA and ATAPI as a SCSI pass-through) | `10a9:100a`; Start enables PCI attributes `0x700` (I/O, memory, bus master) | `Ioc4AtapiScsiPassThru`, message "SGI IOC4 ATA detected" | IO9 and IO10 base I/O cards (IOC4 on the card, manuals via [images.md](images.md#2-machines-the-shub-1-images-serve)) |
| QLogic ISP12160 SCSI | `1077:1216` | `QlogicScsiPassThru` | IO9 |
| SATA | class `0x01`, subclass `0x06` (any vendor); vendor only picks the message: `1725` Vitesse, `8086` Intel, `fffe` simulated, else "VendorId %x". `1725:7174` is special-cased in `AltixPciDeviceInit` | `SataBus` ("Vitesse Serial ATA detected" and others) | IO10 |
| Silicon Image Sil0680 PATA | `1095:0680` | `Sil0680ScsiPassThru` | add-in |
| USB mass storage | OHCI host | `USBOhciHC`, `USBMassStorageDriver` | any |
| LSI SAS | not read | `drv_lsisas.efi` from the archive | add-in |
| Network (PXE) | not read | `Snp3264`, `PxeBc`, `PxeDhcp4`, `drv_b57undi64.efi` | any |

The IOC4, QLogic and Sil0680 drivers return "unsupported" when the processor ID register `cpuid[2]` equals `0xaeeeeeee8badbeef`; the code treats that value as a
simulator signature. The same constant makes `chipset_rtc_sleep` (behind `Stall`) shift its tick count right by 7 and skip its spin delay, shrinks the PCI bus scan to buses 0 to 3,
and makes the SATA driver accept only vendor and device `fffe:fffe` (read; see the review).

## 6. What an emulated machine must provide for EFI to reach the boot manager prompt

Items are graded **established** when the code requires them, **inferred** when they follow from a call shape. All of it assumes the
PROM is bypassed or already ran to `0xffaf8c50`; a synthetic SAL_B must supply what its own record builder supplies.

1. A relocated EFI image entered at its ELF entry through a function descriptor, `r32` = 1, `r33` = a record as in section 2 (**established**).
2. In that record: a nonzero memory descriptor array with at least one conventional (type 7) region, 0x28-byte entries (**established**).
3. A SAL system table whose header is 0x60 bytes and whose first entry is the type 0 entry-point descriptor with PAL_PROC at `+0x68`, SAL_PROC at `+0x70` and its
   global pointer at `+0x78`. A table without it leaves every SAL call a no-op: no console, no variables, no time (**established**).
4. SAL_PROC answering the console calls `0x02000021`-`0x0200002d` of section 4, at least PUTS (`0x23`), POLL (`0x26`), READC (`0x2b`),
   PUTB (`0x28`), the byte read (`0x29`), flush (`0x2c`) and the callback registration (`0x2d`), with status 0 in the first return word and the character or ready flag in the second (**established** for the calls and
   arguments, **inferred** for the exact return layout beyond status and the poll flag).
5. SN SAL `0x02000008` (variable store, op 4) and `0x02000045` (start I/O), `0x02000056` (`GET_PCIBUS_INFO`, from `InitializeAltixPciRootBridge`), `0x02000057` (`GET_PCIDEV_INFO`, from
   `AltixPciDeviceInit`), `0x0200005d` (VGA selector, from `SnSelectVGAConsole`), `0x02000052` (`IOIF_PCI_SAFE`, from the root bridge load and store) and `0x0200000a`/`0x0200000b`
   (clock). The call numbers and their PROM-side behaviour are in [the SAL runtime page](../../sal/sn2-runtime.md); EFI ignores the status of the first two. Whether
   `InitializeAltixPciRootBridge` tolerates "no such bus" from `0x56` was not read (**unknown**); the boot manager needs no PCI device.
6. A SAL callback pair at record `0x38`/`0x40`; timer callback `0x6000` op 1 must deliver periodic interrupts to EFI's timer handler, or the boot
   manager's countdown and every EFI event timeout never fire (**inferred**: the call is made at start-up with period 10; the handler path was not read).
7. The SHub debug-switch register `0x81_5003_1560` readable with bit 10 clear. Bit 10 set sends EFI to the shell and plain console. When the L1 does not answer, SAL_B asks on the console and offers `0000` or `0405` by CPU signature
   (boot-sequence); `0405` has bit 10 set (**established** for the test and the two defaults; which one a given CPU gets is **unknown**).
8. The SHub RTC counter at `0x81_101c_0000` advancing and its period register `0x81_1006_0280` readable: `Stall` busy-waits on them and
   loops forever on a frozen counter (**established**).
9. `cpuid[2]` not equal to `0xaeeeeeee8badbeef` if disks are wanted (otherwise the IOC4, QLogic and Sil0680 drivers decline and the SATA driver wants `fffe:fffe`) (**established**).
10. For a disk boot: PCI config and BAR access through SAL `0x01000010`/`0x01000011`, an IOC4 (`10a9:100a`) with working IDE registers or one of the controllers in
    the table of section 5, a GPT or MBR disk with a FAT partition, and a `Boot####` variable or `\EFI\BOOT\BOOTIA64.EFI` (**established** for the driver checks;
    the register-level contract of the IOC4 pass-through was not read).
11. PAL: EFI calls PAL for cache flushing (`RtPlCacheFlush`) and cache preload ("cache preloading PAL call failed" is a message, not a stop);
    exact calls and their tolerance were not read (**unknown**).

## Unknowns and routes

- Builders of the SAL system table, both ACPI RSDPs and the memory descriptor array (`0xffafca90`, `0xffb5c9b0`, `0xffb5a2f0`, `0xffac8120`) and the
  allocator behind the record (`0xffac30c0`): read to settle the words beyond `0x58`, the ACPI contents and the descriptor types the PROM passes.
- The SAL_B side of `0x02000008` and the callbacks `0x3000`, `0x5000`, `0x6000`: settle the variable store format, flash sectors and what a timer needs to deliver.
- `InitializeAltixPciRootBridge`, `AltixPciDeviceInit` and how they treat the answers of `0x56`, `0x57` and `0x52`: settle the PCI root bridge contract for the emulator.
- The system table's firmware vendor and revision: find the writer, or read them from a running capture. The product release of the sample is unknown.
- Which of `p`, `r` in the PROM console string is which controller route, and whether a PCDP table is filled for a serial console.
- PE32+ import in the retools Ghidra export, to read the three archive drivers.

## Review

Independent re-read of the page against the same image (sha256 `51ccf9ad...`), with the EFI ELF re-extracted from FIT type `0x1f`
and exported through the retools Ghidra path (2,339 of 2,344 functions decompiled), and SAL_B read through the `--sn2-prom` export.
The ELF headers, section table, `.dynsym` and `.rela` sizes, the three PE32+ headers and the FIT addresses and lengths of both components match section 1. objdump
has no IA-64 target on this host, so no disassembler cross-check was possible; every number below comes from the Ghidra export and raw bytes.

**1. Identity: confirmed, with a correction to the public-tree comparison.**
- Confirmed: `efi1_10` source names (166 distinct, in the groups the page counts: 38 `corefw`, 80 `edk/Drivers`, 3 `edk/Lib`, 6 `lib`, 39 `shell`), `IBI SYST` revision `0x1000a`, the "EFI version %01d.%02d [%d.%d]", "EFI64 Running on Intel(R) Itanium Processor", "EFI IA-64 SDV/FDK (No BIOS )", "Intel EPG Lion BIOS Team - NO EXTRA CHARGE" and `INTEL` vendor strings (all UTF-16), the build stamp "Nov 11 2008" and "07:23:32", and the `ver` example text "EFI Revision : 14.5".
- EDK I at 321b15a: seven matches checked by file and string. `Sample/Universal/Network/PxeBc/Dxe/bc.c` ("Could not create transmit timeout event", "Unsupported BIS revision"), `.../PxeBc/Dxe/pxe_loadfile.c` ("PXE-E18: Timeout"), `Sample/Universal/Disk/Partition/Dxe/Gpt.c` ("Restore backup partition table by the primary"), `Sample/Bus/Pci/PciBus/Dxe/PciDeviceSupport.c` ("ActiveVGADeviceOnTheRootBridge"), `Sample/Universal/Console/Terminal/Dxe/Terminal.c` (GUID `10634d8e-...`), and, outside the driver layer, `Foundation/Core/Dxe/Mem/Page.c`, `Event/event.c` and `Hand/DriverSupport.c` ("ConvertPages: Incompatible memory types", "EventQueueLock.OwnerTpl == Priority", "AddSortedDriverBindingProtocol"). The same-named files the page lists exist (`DiskIo` is `Sample/Universal/Disk/DiskIo/Dxe/diskio.c`; `UsbMassStorage` is also there, so it matches too).
- **Corrected.** The page said EDK II and gnu-efi have no code in common. Of 961 distinct image strings of 28 to 70 characters, 391 occur in EDK I's `.c` and `.h`, 239 in EDK II (ba6037f8) and 29 in gnu-efi (74bd9b6). EDK II shares the Partition, PciBus, ConSplitter, ConPlatform and core text it inherited from EDK I (e.g. `MdeModulePkg/Core/Dxe/Mem/Page.c`). gnu-efi's `lib/` is the same Intel library as the image's `efi1_10/lib` (`dpath.c`, `event.c`, `misc.c`, `sread.c`): `lib/crc.c`, `lib/hand.c`, and `lib/ia64/salpal.c` define `LibInitSalAndPalProc`, `LibSalProc` and the "Crc check failed" text. What the three trees really lack is as the page said: `corefw` boot manager, variable engine and platform names, the shell, `nshell`, the SGI drivers (zero hits in each for `BmSetDefaultBootOptions`, `InitializeBootMaintenance`, "EFI Boot Manager ver", `RtVarGarbageCollect`, `PcdpSetup`, `BmDefaultBootImage`, `AltixPciRootBridge`, `SNPlainConsole`, `Ioc4PassThru`). The core's boot-services text (memory, events, handles) is therefore not image-only: EDK I's `Foundation/Core/Dxe` is a close relative and can be used to read it.
- Grade stays *established* for the name and release, *inferred* for "SGI build of the sample" (the sample's own build number is still unknown).

**2. Hand-off: confirmed except two record words.**
- SAL_B `0xffafc140` allocates 0x58 bytes, zeroes them, fills the descriptor array (`0xffac8120`, which prints "%d memory descriptors at 0x%llx"), and writes `*param_1 = 1` and `*param_2 = record`. `0xffaf8c50` calls the loader's `{entry, gp}` out-pair with (1, record) after progress `0x48`; failure prints "Could not load EFI!  Panic..." and "ERROR: failed to set up exit state" if the record builder fails; both and the return path call `0xffa1b940(0xbe, 2)`.
- Fields: `0x00` count, `0x08` array, `0x10` = `0x1fffc00`, `0x18` SAL table, `0x20` = 0, `0x28` ACPI 1.0, `0x30` ACPI 2.0, `0x38` = `0x1fffc00`, `0x40` = `0x1fffc00`, `0x48` = `0x10`, `0x50` = `0x10000`. **Corrected:** the page had `0x40` = `0x10`; `0x10` is at `0x48`. The `0x38`/`0x40` pair is read by `PlInitSalPalProc` into a descriptor at ELF `0x1fe178` that `RtSalCallBack` calls. The ACPI 2.0 pointer is also stored at `*(0x1000040 + 0xc0)`.
- EFI side: `MainEntry` returns 0 when `r32` is 0 and otherwise only passes it on unused, so any nonzero value works. It reads exactly the words the page lists (`0x00` to `0x50`, plus `0x58`, `0x60`, `0x68`, `0x70`). Nonzero `0x58`/`0x60` become the PCI option ROM table (32-byte entries); `0x68`/`0x70` are the core image base and size in `BuildEfiCoreImageHandle`, so zeros give a harmless null-base image handle (inferred).
- The four words past the record are still **unknown**: `0xffafc350` zeroes only the requested size from an arena (`sal_efi_malloc.c`, magic `ARNA`), so what follows is arena memory. Zero is safe for EFI.

**3. Tables: confirmed.** GUID values were read from the image. `MainEntry` installs SAL (`0x18`), MPS (`0x20`), ACPI 1.0 (`0x28`) and ACPI 2.0 (`0x30`) with `InstallConfigurationTable`; a NULL table for an absent GUID returns NOT_FOUND without adding an entry, so MPS (and any zero pointer) installs nothing. The SMBIOS GUID is referenced only from `DumpSystemTable` (no installer). `0x58` gives the option ROM table. `FUN_0011fa40` builds the HCDP: 0x800 bytes of runtime data, signature `HCDP`, length `0x28`, revision 3, OEM `SGI`, and `FUN_00120510` appends entries up to 0x800 bytes. `InitializeDebugImageInfoTable` installs `49152e77-...`. `LibInitSalAndPalProc` checks the type byte at `+0x60` is 0, then reads PAL_PROC from `+0x68`, SAL_PROC from `+0x70` and the gp from `+0x78`; SAL_B (`0xffafca90`) sets header length `0x60`, entry count 5 and builds the first entry at `+0x60` with `0xffafc600` (that entry's type byte was not decoded). Refinement: the HCDP only gets entries from `FUN_001207c0`, which accepts PCI class 3 subclass 0; there is no serial entry.

**4. Console: confirmed, with call details added.**
- Only `0x21`, `0x22`, `0x23`, `0x26`, `0x28`, `0x29`, `0x2b`, `0x2c`, `0x2d` are used for the console path. `SerialRead` (`0x29`) takes three arguments (buffer, length, the SerialIo timeout word) and returns the byte count in the second return word; SAL_B returns -3 for zero bytes, which EFI turns into EFI_TIMEOUT. `SerialWrite` (`0x28`) is buffer then length. `0x26` returns the ready flag in word 2; `0x2b` returns the character in word 2; `0x2c` takes no arguments.
- The switch is `chipset_dipsw_get(10)`: a plain 64-bit load of `0x8000008150031560`, tested against `1 << 10`. Clear loads the serial console set and the boot-manager loop (`bootmgr`, `bmaint`); set loads `SNPlainConsole` only, then `BmPlatBanner` (which calls `HinvReport`), `ConnectAll` and `PlStartShell`.
- `0x2d`: `SNConsoleCallbackRegister(1)` passes ELF address `0x1fe1a0` after the console connect; `ExitBootServices` calls it with 0. The table at `0x1fe1a0` holds, by relocation, `SNConsoleCallbackPoll` (`0x1fe1b0`), `Readc` (`0x1fe1b8`) and `Putb` (`0x1fe1d0`). SAL_B's `0x2d` handler just stores the pointer and returns 0.

**5. Variables and boot: confirmed except what op 4 does.**
- `PlInitNvVarStoreFlash` calls `LibSalProc(0x2000008, 4, record[0x48], record[0x50], buffer, 0x20000)`. SAL_B's function 4 (decompiled) accepts arg 1 at most `0x10` and arg 2 at most `0x10000`, writes an int, a short and a pointer into the buffer header, and checks each node's flash for writability; it does not copy store data (corrected above). Store reads and writes later go through the callback pair with id `0x3000` and the buffer pointer, with ops 1, 2 and 3 (clear, read, update), after a size bound check.
- `BmReadVariables` builds the defaults only when it finds no `Boot####` or `Driver####` variable under the global GUID. `BmSetDefaultBootOptions` makes options in four passes: removable Block I/O handles, then file-system handles that are non-removable or lack Block I/O, then Simple Network handles, then internal shell handles; it writes `BootOrder` as 0..n-1 and `Timeout` = 7. `BmDefaultBootImage` tries `\EFI\BOOT\BOOTIA64.EFI` and, when that fails, loads the first `*.EFI` file it finds in `\EFI\BOOT` (added; the page omitted the fallback).

**6. Block drivers: confirmed, SATA and IDs corrected.** IOC4 `10a9:100a`, QLogic `1077:1216`, Sil0680 `1095:0680` are exact vendor and device checks; each also needs `cpuid[2]` not equal to the simulator value. SATA matches class and subclass only (see the table fix). Stack order and names confirmed from the registration list in `MainEntry`: `SataBus`, `ScsiBus`, `ScsiDisk`, the three pass-throughs, `DiskIo`, `Partition`, `Fat`, then `Snp3264`, `PxeBc`, `PxeDhcp4`.

**Section 6 requirements and grades.**
1. Entry through descriptor, `r32` nonzero (SAL_B passes 1), `r33` the record: established.
2. Descriptor array with a type 7 region: established. The PROM's array also carries types 9 and `0xb` (the `0xff800000` window), inferred from the builder's call arguments, not decoded.
3. SAL table entry: established. Detail: with no entry, `SalProc` silently does nothing and `LibSalProc` returns -3; it is not "every call a no-op" for the pool calls that check status.
4. Console calls: established; added the `0x29` argument and return contract above. `0x2d` and `0x2c` can return 0 without a model.
5. Established. Unlisted calls EFI makes: PCI config `0x01000010`/`0x01000011` (from `Ia64PCIRead`/`Write` and the root bridge), and `0x02000013`, which `RtPlSetVirtualAddressMap` sends through the runtime SAL_PROC, so an OS loader's `SetVirtualAddressMap` needs it. `0x01` (called from the shell's POD command), `0x1f` and `0x08` ops 0, 5, 6, 7 (from `InitializeFlash`) and `0x1b` (callers unnamed) were not seen on the boot path. `0x52`, `0x56`, `0x57`, `0x5d` all land in one SAL_B I/O dispatcher (case of `id - 0x02000051`), which is why the export has no separate `sal_0200005x` names.
6. Timer: the call `SalCallBack(0x6000, 1, 10, handler)` is established; delivery is still inferred.
7. Debug switch: established.
8. RTC: established, with the formula. The tick period is `((reg[0x81_1006_0280] >> 4) & 0x3ff) * 10 + 10`, and `Stall(n)` waits `n * 1000 / period` ticks of `0x81_101c_0000`.
9. **Changed.** The simulator signature is tested by `Ioc4AtapiScsiPassThruDriverBindingSupported`, `QlogicScsiPassThruDriverBindingSupported` and `Sil0680ScsiPassThruDriverBindingSupported` (all decline), by the SATA driver (accepts only `fffe:fffe`), by `InitializePciRootBusList` (scans buses 0 to 3 instead of 0 to `0xff`), `FatLoadFatEntry`, `AltixPciDeviceInit` (skips the Vitesse quirk) and the RTC helpers, where it shifts the tick count right by 7 and skips the 100-count spin: a shift, not "halves". An emulator must leave `cpuid[2]` at its real value.
10. Disk boot: established for the checks listed; the register contract of the IOC4 pass-through was not read. Added: `InitializePciRootBusList` does config reads of every bus 0 to `0xff` through the root bridge protocol and treats vendor `0xffff` as absent.
11. PAL: unchanged, unknown.

**Not checked.** The three PE32+ drivers beyond their headers; PAL calls; the SAL_B side of callbacks `0x3000`, `0x5000`, `0x6000` and the L1 store of the debug-switch word; ACPI table contents; descriptor-type decoding in `0xffac8120`; EDK II "last commit with IPF" and the `ver` fields beyond the strings; the arena contents behind the record.
