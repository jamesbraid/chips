# Visual Workstation 320 and 540: what the firmware hands over

This page records what the firmware does from reset and what it leaves behind for the NT loader and HAL and for the Linux
port. The reset path and the hand-off tables are read from the PROM 1.0006 image ([firmware.md](firmware.md) for its layout);
the rest comes from the NT and Linux side. Only version 1.0006 is held, so later versions (1.1002 onwards, with Windows 2000
support and PCI bridge support) may differ. Grades as in the [README](README.md); "software expectation" means the shipped
software assumes it. Reading was done with objdump over the whole boot block and in Ghidra (x86, 32-bit, base `0xf00000`)
for the main-module routines quoted below.

## Start-up sequence

| Step | What | Grade |
|---|---|---|
| 1 | Reset vector at physical `0xfffffff0` is a near jump into the boot block at flash `0x7c000` | established (image) |
| 2 | Real-mode boot code gives the segments 4 GiB limits, sets up caching, optionally runs a patch record, then runs a table of eight set-up steps (the legacy I/O chip, DMA controller, 8259 pair, PIIX4 and Lithium set-up; [below](#the-boot-block)) | established (image) |
| 3 | The whole 512 KiB flash is copied to RAM at `0x80000`, and 32-bit code in that copy expands the compressed modules to `0xf00000`-`0xff0264` and calls the entry at `0xf00000` | established (image) |
| 4 | The main module reads the Cobalt bank registers to size memory, tests RAM, maps its device windows, sets up Lithium, starts the other processors and writes the processor table, builds the ARC tree and vectors | established for the parts quoted below; order inside the module only partly traced |
| 5 | A progress bar and the first start-up messages appear; Esc enters the firmware menus; otherwise the first boot entry runs | established (guide) |
| 6 | The firmware's own disk and file services load the OS loader named by `OSLoader` from `OSLoadPartition` or `SystemPartition` and pass it the start-up options | established (guide, loader strings) |
| 7 | The loader loads kernel and HAL, passes the loader block, and the HAL takes over devices | established (loader and HAL read) |

The power-on diagnostics level is "quick" or "extensive"; extensive also tests RAM at about 0.1 s per megabyte, and
the firmware can switch itself to extensive after a boot that did not complete (guide).

## The boot block

**Established (flash `0x7c000`-`0x7ffff` read in full).** The code below is 16-bit with 32-bit operand overrides until the
jump to the protected-mode loader.

1. **Entry.** `cli`, `cld`, then the reset-time `EAX` and `EDX` are parked in two MMX registers (so they survive; the
   purpose is inferred: `EDX` holds the processor signature at reset). A flat 4 GiB descriptor table is loaded, protected mode is entered once to
   load the 4 GiB segment limits and left again ("unreal mode"), so real-mode code addresses all of memory. Progress
   is shown as byte writes to I/O port `0x80` (`0xdf`, `0xdd`, `0x4b`, then the step numbers below).
2. **Caches.** Caches are disabled and flushed, every MTRR is cleared, and one variable MTRR is set over the flash window
   (base `0xfff80000`, type 4, write-protect). Cache is then re-enabled (post code `0xdd`). Step `0x02` below clears the whole MTRR set again
   when the processor reports fixed-range MTRRs.
3. **Patch record.** If the 24-byte trailer ending at flash `0x79fc0` has a non-zero, non-`0xffffffff` length word and the
   covered words sum to zero, the code jumps to the start of the record (flash `0x74000`) with a return address in
   the boot block, so a patch can be added without erasing the boot sector. The 1.0006 image carries one.
4. **Set-up steps.** A table of (step number, handler) pairs is walked; each step number is written to port `0x80` first.
   The steps in the image are:

   | Step | Action | Grade |
   |---|---|---|
   | `0x02` | if `MTRRcap` reports fixed-range registers, write zero to 28 MTRR registers listed in a table (`0x2ff`, the fixed and variable ranges) | established |
   | `0x06` | enable the cache (clear `CD` and `NW`, flush) | established |
   | `0x10` | NS87307: 26 index/data writes through ports `0x2e`/`0x2f` activate logical devices 0 to 8, put the GPIO block at `0x0fc0` and the power-management block at `0x0fc8`, then write the power-management register 1 with bit 7 (the GPIO-enable bit Linux also sets) | established; the logical-device meanings are the part's standard layout, inferred |
   | `0x12` | initialise the DMA controllers (writes to ports `0x08`, `0xd0`, `0xd6`, `0x0b`, `0xd2`, `0xd4`) | established |
   | `0x14` | initialise the two 8259s: master vector base `0x08`, slave `0x70`, all inputs masked | established |
   | `0x1a` | write nine (register, value) bytes into the PIIX4 ISA bridge's configuration space (bus 0, device 4, function 0) through Lithium B's configuration window at `0xfd0000f8` and `0xfd0000fc`: register `0x04`=`0x0f`, `0x4e`=`0xf4`, `0x60`=`0x09`, `0x69`=`0xf2`, `0x76`=`0x0c`, `0x77`=`0x0c`, `0xb0`=`0x4d`, `0xb3`=`0x60`, `0xcb`=`0x25` | established; device identity inferred from Linux |
   | `0x1b` | PIIX4 power-management function (device 4, function 3): register `0x40`=`0x0f80` (base `0x0f80`), register `0x80`=`0x01` (enable) | established |
   | `0x2a` | set the low five bits of the dword at `+0x58` in both Lithium bridge windows (`0xfc000000`, `0xfd000000`) | established |

   The PM base `0x0f80`, the GPIO base `0x0fc0` and the NS87307 power-management base `0x0fc8` are the values Linux's
   `setup.c` uses, so Linux repeats work the firmware has already done (Linux does it again without checking).
5. **Shadow and hand-off.** The 512 KiB flash is copied (`rep movsl`) to RAM at `0x80000`, the caches are re-enabled and a
   far jump goes to flash offset `0x7d800` in that copy (physical `0xfd800`), 32-bit flat code compiled from C. It
   loads its own descriptor tables, sets the stack to `0xeffff0`, checks the `SHDR` tag (post code `0xce` and a loop if it is wrong),
   expands the five sections ([firmware.md](firmware.md)) and calls the entry address from the header (an indirect call;
   the target being `0xf00000` is inferred from the header field). **Software expectation:** RAM at least up to 16 MiB works
   at this point, before any memory sizing the main module does.

## The main module

**Established unless marked (Ghidra decompilation and listing of the quoted routines; the module is about 340 KB and was
not read in full).**

1. **Board identification.** Board type is `(inb(0x0fb2) >> 2) & 0xf` and board revision `inb(0x0fc0) & 0x7f`. Linux reads
   the same two places (PIIX4 general-purpose input bit 18, shift 2, and the NS87307 GPIO data register, 7 bits), so
   the firmware and Linux agree on where they are. The firmware also uses the type (zero for the 320) to pick a delay while
   other processors start.
2. **Memory sizing.** The Cobalt revision byte at `0xc2000008` selects where the bank registers are read. The firmware
   first clears bit 0 of the Cobalt memory-controller register at `0xc6000000`, then reads sixteen bank registers at an
   8-byte stride from `0xc6000048` (from `0xc6000050` unless the revision is `0xa0` or `0xa8`, the "Cobalt Lite" values in
   [questions](../../questions/visws-firmware-open.md)). For each: bit 2 set marks the bank as absent or bad, otherwise bit 0
   set means populated, and bit 1 chooses 128 MiB (set) or 32 MiB (clear). The total is the sum. So memory is sized by
   reading what the memory controller reports about populated banks, not by probing writes; a separate RAM test then marks good
   and bad pages ("low 16 MB good", "low 32 MB good", "all 128 MB good" are its outcome strings). How the controller's timing
   and bank registers are programmed before this, and the reset values of those registers, were not found in the part read
   (unknown).
3. **Firmware address map.** The firmware builds page tables (`setup_memory_map`) and maps these windows: Lithium A and B
   (`0xfc000000`, `0xfd000000`), the Cobalt processor, interrupt and memory blocks (`0xc2000000`, `0xc4000000`,
   `0xc6000000`), the retrace register (`0xca000000`) and the display back end (`0xd0000000`, 0x81 pages), the local APIC
   (`0xfee00000`), the flash (`0xfff80000`, 0x80 pages), and several small windows at `0xfe000000`, `0xff000000`,
   `0xff004000`, `0xff018000` and `0xff01c000` that this repository does not describe (unknown).
4. **Lithium set-up.** One routine writes `0xffffffff` to `+0x48` and `0x81f` to `+0x58` of both bridge windows, then does
   a read-modify-write on the five dwords `+0x60` to `+0x70` (mask `0xfffffbc1`, then bits set from a board-revision-
   and variable-dependent value), and finally reads the Lithium A identification dword and prints an error unless it
   equals `0x100210a9` (vendor `0x10a9`, device `0x1002`). A helper writes a byte to `+0x44`, the bus-number register Linux reads;
   its callers were not traced. The meaning of `+0x48`, `+0x58` and `+0x60`-`+0x70` is unknown.
5. **Graphics memory.** The strings `gfxmem_alloc: <128MB of ram and !bad configuration`, `cogfxmem` and `maxpmem` show that
   firmware chooses the graphics reservation (memory type `0x16` in the loader block) and that a variable can steer
   it. The algorithm was not read, so the split chosen on each memory size is unknown.
6. **PCI resources.** No generic PCI bus walk or BAR-sizing loop was found in the main module: configuration mechanism 1
   (`0xcf8`) is used only against the PIIX4 (one diagnostic and a few register accesses). That is a search of the module
   for the usual patterns, not a trace of the SCSI, IDE and network drivers, so whether the firmware assigns resources to
   any PCI device before the OS (for its own boot devices) is unknown; the OS side assigns anyway (see PCI enumeration below).

## Boot into NT

1. **Files and names. Established (guide, Recovery CD-1).** Boot files are `arcldr.exe` (the loader; "ARCx86 OS Loader
   V4.0", SGI build of 1999-01-22; in a directory such as `\os\winnt40\`) and the HAL, copied to the system partition
   as `hal.dll`. For a one- or two-processor NT the HAL is `halbrgup.dll` or `halborg.dll` renamed; the installer lists
   `halborg.dll` and `arcsetup.exe` as added files and removes the stock `hal486c`, `halapic`, `halmca`, `ntdetect.com`
   and `setupldr.bin`. So NT is started by the ARC loader path used on MIPS and Alpha NT, without `ntldr`,
   `boot.ini` or `ntdetect`. Which HAL file, UP or MP, setup copies as `hal.dll` is not recorded (neither name occurs in
   the standard text-mode setup file; the SGI setup program does the copy).
2. **Loader services. Software expectation.** The loader calls firmware vectors for disk and file access (its strings
   carry SCSI read-capacity and sense decoding, a Hitachi CD-ROM drive fix, El Torito CD booting, NTFS, hibernation
   file handling, a TFTP and IPsec network path), and reads these environment variables from the firmware:
   `consoleout`, `consolein`, `systempartition`, `x86systempartition`, `osloader`, `osloadpartition`, `osloadfilename`,
   `osloadoptions`. Its partition names are the ARC forms `multi(0)disk(0)fdisk(0)partition(0)`, the same with
   `eisa(0)`, and `scsi()` for SCSI after firmware 1.1002.
   **The call table. Established (loader code read at file offset `0x790`; firmware code read at `0xf42240` and the
   tables it copies).** Like MIPS and Alpha ARC machines, the firmware keeps an ARC *system parameter block* at physical
   `0x1000`: the signature `ARCS`, length `0x48`, version 1, revision 10, then pointers (restart block, debug block and the
   general-exception and TLB-miss vectors are zero or unused), the firmware vector length `0x8c` and pointer `0x1200`, the
   private vector length `0x3c` and pointer `0x1300`, and an adapter count of zero. At start-up `arcldr.exe` reads those
   fields from `0x100c` to `0x1028` into its own globals; it reaches every firmware service through the vector, and
   prints "Unimplemented Firmware Vector called (FID n)" for an empty slot. The firmware copies its static tables to
   `0x1200` and `0x1300` when the hand-off is prepared. The firmware vector has 35 four-byte entries in the standard ARC
   order: 0 Load, 1 Invoke, 2 Execute, 3 Halt, 4 PowerDown, 5 Restart, 6 Reboot, 7 EnterInteractiveMode, 8 (reserved, points
   at data), 9 GetPeer, 10 GetChild, 11 GetParent, 12 GetConfigurationData, 13 AddChild, 14 DeleteComponent, 15 GetComponent,
   16 SaveConfiguration, 17 GetSystemId, 18 GetMemoryDescriptor, 19 (reserved, zero), 20 GetTime, 21 GetRelativeTime, 22
   GetDirectoryEntry, 23 Open, 24 Close, 25 Read, 26 GetReadStatus, 27 Write, 28 Seek, 29 Mount, 30 GetEnvironmentVariable, 31
   SetEnvironmentVariable, 32 GetFileInformation, 33 SetFileInformation, 34 FlushAllCaches. The names are the ARC
   specification's for those positions (the table has no firmware symbols; entries 0 to 34 are non-null except 19); the last two ARC entries
   (test Unicode character, display status) are not in this version's table. The private vector has 15 entries (one is
   null) whose purpose was not read. Which vector numbers `arcldr.exe` actually calls was not enumerated.
3. **The ARC configuration tree. Established (HAL read, `DumpArcInfo`, `HalpGrabArcRevInfo`).** The HAL requires the NT loader
   block to carry an ARC root with a standard component tree (the HAL prints "LoaderBlock contained no arc root" if it
   does not). It looks up the system component, finds the child "SGI REV INFO", and under it the children "SYS TYPE"
   (a byte: 0 for the 320, 1 for the 540, inferred from the Linux board-type values and the HAL's branches) and
   "BOARD REV" (a byte, see below). It copies the system identifier from the tree and rewrites it into a product name that
   begins "Silicon Graphics", with a `-` in the identifier replaced by a blank and anything from a `_` on dropped. The
   identifier string in 1.0006 is `SGI-000_ARCx86`, next to the strings that name the loader variables (inferred to be the
   system component's identifier: the HAL's rewrite rules, dash to blank and cut at the underscore, fit it; the rewrite then
   gives a product name from the board type, not from this string alone).
   **Text-mode setup's side. Established (`txtsetup.sif` on the SGI NT 4.0 install CDs).** Setup maps the system identifier string to a
   HAL: `SGI-320_ARCx86` and `SGI-540_ARCx86` are the uniprocessor machine types (`sgiborg_up`, which copies `halbrgup.dll` to
   `hal.dll`), and the same strings with `_mp` appended are the multiprocessor types (`sgiborg_mp`, which copies `halborg.dll`).
   So the firmware's system identifier carries the model number and a `_mp` suffix when more than one processor is present;
   the held 1.0006 image's `SGI-000_ARCx86` is then probably a template, not the string a running machine reports (inferred; a 1999 user report of
   `SGI_ARCx86_mp` is the same pattern with the number missing). Setup's HAL-load step names `arcsetup.exe` in place of the
   stock `ntdetect.com`, with the setup file's own comment that this is a placeholder, and the stock `hal486c`, `halapic`,
   `halmca` and `ntdetect` are commented out.
   The HAL also carries code and strings to add MultiFunctionAdapter, Flash, Audio, Video, Raid, SCSI, Keyboard, Mouse and
   processor nodes to the NT registry itself (`HalpAddMultiFunctionNode`, `HalpFixupRegistry`); the 1.0002 notes show
   the firmware creates the floating-point nodes. **Firmware side. Established (strings; the 1.0006 data module).** The
   firmware builds the tree itself: the nodes "SGI REV INFO", "SYS TYPE" and "BOARD REV", a configuration key `CPUMask`, processor
   components with FPU children (`borg_cpu_install`), `video()`, `serial(0)`, `serial(1)`, `console`, `keyboard()`
   and `pointer()`, and the memory descriptor list (`alloc_memdesc`). Component classes, keys and types were not decoded.
4. **Board revision byte. Inferred.** The HAL treats `BOARD REV` below 6 as one hardware generation of the 320, 6 to 11
   as the second and 12 or above as the third; the 540 with revision 0 is a special case and any other 540 revision uses
   the third generation's tables. The thresholds are the same as the ones the Linux port applies to the raw 7-bit value
   it reads from the NS87307 general-purpose I/O port (below 6 revision 4, below 12 revision 5, otherwise 6), so the byte in
   the tree is the raw value. That equality is the only evidence.
5. **Memory descriptors and the graphics banks. Established (HAL read).** The loader block's memory descriptor list
   carries the graphics memory, and the HAL turns it into what the graphics driver reads:
   - `HalpSpliceGfxMemory` walks the list and prints "N MB Memory [G MB Graphics, M MB NT]": descriptors of type 3 (bad
     memory) are ignored, type 22 (`0x16`, a type outside the stock NT set) counts as graphics, type 6 (firmware
     permanent) counts toward the total only, and everything else is NT memory. Pages are 4 KiB.
   - The display start-up picks the first type-`0x16` descriptor big enough for the boot-time frame buffer (the
     visible area rounded up to 512 by 128 tiles of 16 pages each) as the frame buffer base, and keeps up to 32
     type-`0x16` descriptors as banks. If there is none it prints "You need an updated PROM!", takes 256 pages from
     the loader's free memory, and carries on.
   - `HalpAddGbeDisplayToRegistry` publishes them under `SGICtrl\Memory` in the NT control tree as `GraphicsMemory` and
     `GraphicsMemorySize` (base and byte size of the first bank), `NumberOfBanks` and `BankAddr00` to `BankAddr31` and
     `BankSize00` to `BankSize31` (byte address and page count of each); that is the list `sgcomp.sys` reads (see
     [devices/cobalt-graphics/nt-software.md](../../devices/cobalt-graphics/nt-software.md)). Banks must start on a
     4 MiB boundary and be a multiple of 4 MiB (1,024 pages) or the HAL warns "Update the prom for aligned graphics
     memory" and does not remap them.
   So the firmware reserves the graphics memory as one or more type-`0x16` descriptors, aligned to 4 MiB; how it
   chooses the split between NT and graphics is unknown (Linux hard-codes 8 MB by default, see below).
6. **Memory map facts the HAL maps (physical).** The first 4 KiB page of memory (the BIOS data area is touched there: the
   warm-reset vector at `0x467` and the reset flag at `0x472` are written, with CMOS register `0x0f` set to `0x0a` or
   `0x00`); the processor table page at `0x1000` with the table at `+0xe00` (below); the Cobalt CPU register block
   `0xc2000000`; the Cobalt APIC `0xc4000000`; the Cobalt memory controller registers `0xc6000000`; the Lithium
   bridges A at `0xfc000000` and B at `0xfd000000` (one 4 KiB window each); the local APIC at `0xfee00000`; the flash at
   `0xfff80000`. The Cobalt blocks are described in [nt-hal.md](nt-hal.md).
7. **Processor table at physical `0x1e00`. Established (HAL and Linux read; firmware writer read in the main module at
   `0xf03f10`-`0xf0421f`, Ghidra for the entry builder).** A 16-bit processor count, followed by that
   many 20-byte entries. Both the NT HAL and the Linux 2.6 port read it from the same place (Linux: the count at `0x1e00`,
   the table two bytes on, at most four processors). If the count is zero the HAL falls back to a built-in table. The table
   is the only processor description: there is no MP floating pointer and no ACPI. The Linux 2.2 and 2.4 ports instead
   hard-code two processors, ids 0 and 1, with integrated local APICs.
   **Who writes it: the firmware, from every running processor.** The boot processor stores the count 1 at `0x1e00`,
   writes its own entry, copies a 0x210-byte start-up stub to physical `0x50000`, clears the local APIC error status, and sends a startup
   IPI (vector `0x50`) to all other processors, waits (longer on a 540, board type non-zero: `0xe00000` against `0x180000` loop
   counts), then sends an INIT assert and de-assert to the same set (parking them again for the OS). Each other
   processor runs the stub from `0x50000`: it enables its APIC, increments the count at `0x1e00`, writes its entry at
   `0x1e02 + 20 * (count - 1)`, signals through mailbox bytes at `0x504`, `0x505` and `0x506` (physical, below the table) and
   halts. The boot processor's own flag has bit 1 set. An entry is: byte 0 type 0; byte 1 the local APIC id (bits 27:24 of
   the APIC id register, masked with `0xf`); byte 2 the APIC version byte; byte 3 flags (bit 0 enabled, bit 1 boot processor);
   dwords at +4 and +8 the `cpuid(1)` `EAX` and `EDX`; dwords at +12 and +16 the `cpuid(2)` `EAX` and `EDX`. So the
   first twelve bytes are the Intel MP processor entry (type, id, version, flags, signature, feature flags) and the last
   eight are the `cpuid` cache and TLB descriptor registers where the MP layout has reserved bytes. A nonzero APIC version in the first entry tells the HAL to send
   startup interrupts as well as INIT. The firmware itself reads the same table when it builds the ARC processor nodes
   (`0xf02030`, `0xf02140`). One more write during start-up: a read-modify-write of the dword at Cobalt APIC `+0xffc` that sets
   bits 27:24 to 4; the meaning is unknown.
8. **Processor start convention. Established (HAL read; standard MP).** The bootstrap processor writes a real-mode
   stub below 1 MiB, points the warm-reset vector at it, sets CMOS shutdown byte `0x0a`, sends INIT assert and
   deassert through its local APIC, and, if the APIC version is nonzero, two startup IPIs; then waits for the other
   processor to report. The Linux port uses the same warm-reset vector method.

## Boot into Linux

1. **Loader. Observed.** SGI's Linux for the workstations was started from the firmware as an ARC program: the
   firmware boot entry's `OSLoader` is `larc.exe` or `arclx.exe` on a FAT floppy or partition, `OSLoadFilename` names
   the kernel image (`/la2210.vw` for a 2.2.10 kernel built for the workstation), `OSLoadPartition` the ARC path
   (`multi(0)disk(0)fdisk(0)partition(1)`), and `OSLoadOptions` the kernel command line (`root=/dev/fd0 load_ramdisk=1`).
   Reported by users installing Red Hat 6.0 on a 320 and a 540 in 1999 and 2000; neither loader file is held.
   SGI's later Linux releases were unpacked and checked: ProPack 1.3 Visual Workstation Edition and Visual Workstation
   Environment 3.0 (README updated 2000-12-19) name the 230, 330 and 550 (PC-BIOS workstations) only, install through a
   LILO-based installer, and ship kernels 2.2.15, 2.2.16 and 2.3.99 whose configurations read leave the Visual Workstation
   option off. No `larc.exe`, `arclx.exe` or `la2210.vw` turned up in the disc file listings, a byte search of the images,
   or the extracted kernel and boot-disk packages. The kernel source package of 2.2.16 carries the Visual Workstation
   platform code (read: board type and revision, GPIO enable, two fixed processors, Lithium sanity check bypass, as in the
   history tree's 2.2 port); the 2.3.99 package carries the same files and was not read. So the ARC loaders, and how they
   build `boot_params`, are still not held.
2. **Kernel entry state. Established (Linux source).** The kernel reads the standard `boot_params` block and requires the
   loader to have set the memory size field `alt_mem_k`; if it is zero the kernel prints "Bootloader didn't set memory
   size" and assumes 128 MB. It does not use E820 from the loader: the platform code builds the memory map itself, as
   conventional memory below 640 KB, RAM from 1 MB up to the top of memory minus the graphics buffer, and the
   graphics buffer, at the top of memory and 8 MB by default (the size is a boot parameter, trimmed to whole megabytes),
   as a reserved region. The Linux port's boot-time probing is only the PIIX4 board-type bits, the NS87307 GPIO
   revision, the two Lithium device and vendor words (a warning is printed if they do not read as SGI's Lithium),
   and the Cobalt revision and APIC id registers.
3. **Tables the kernel does not get.** No MP table, no E820, no ACPI, no PnP BIOS: established for Linux 2.6 (the
   platform replaces `find_smp_config`, `get_smp_config` and `memory_setup`).
4. **Interrupt set-up the kernel assumes already done.** None: the kernel unmasks the Lithium PCI interrupt-enable
   registers (`+0x46`, all eight bits on both bridges) and enables the Cobalt APIC itself by setting bit 8 of its ID
   register without changing the id ([nt-hal.md](nt-hal.md) for the register map; Linux page for the IRQ table).

## PCI enumeration

1. **Two host bridges. Established (Linux, HAL).** Lithium A (the "Ethernet" side, window `0xfc000000`) and Lithium B (the
   PIIX4 side, `0xfd000000`) are two PCI host bridges with their own bus numbers, read from a 16-bit register at `+0x44`
   (low byte primary bus, high byte subordinate); Linux scans both and reports bridge A's bus as `pci_bus1`. The
   Lithium vendor and device words sit in its window at the ordinary config header offsets. Linux uses configuration
   mechanism 1 only.
2. **The HAL enumerates and assigns resources itself. Established (HAL read).** It walks buses, devices and functions,
   creates sub-buses behind bridges, and gives out I/O and memory base address register ranges (with a note when
   prefetchable memory cannot be provided and non-prefetchable is used instead). It does so through the Lithium window's
   own configuration data and address registers at `+0xfc` and `+0xf8`: the address value has the 32-bit bit 31 set,
   the bus in bits 23:16, the device in bits 15:11, the function in bits 10:8 and the dword-aligned register in the
   low bits, and a read or write of the data register performs the cycle; afterwards the bridge's status word at `+6`
   is written back to clear error bits. Whether firmware also assigns resources before the OS starts is unknown
   (Linux 2.6 calls its usual resource survey, which keeps firmware assignments when present); the 1.0006 main module has no
   generic PCI walk or BAR-sizing loop that a pattern search finds (see the main module section), and the boot block's PIIX4
   writes use the same Lithium window registers (`+0xf8` address, `+0xfc` data) that the HAL uses.
3. **Interrupt pins. Established (HAL and Linux tables).** Per-slot pin-to-Cobalt-entry maps exist for each hardware
   generation: five slots per bridge (the HAL's node names are "Pci A Slot 0..4" and "Pci B Slot 0..4"). The
   PIIX4's USB uses a dedicated entry. See [nt-hal.md](nt-hal.md).

## Graphics and console

The HAL's display path has a text mode on the standard VGA registers and a Cobalt graphics (frame-buffer) mode;
`HalpInitializeGbeDisplay0` can fail and the HAL falls back. The firmware displays its menus and the NT boot screen on
the Cobalt graphics output; console and keyboard devices named `consoleout` and `consolein`, `nogfxkbd` and a `console`
variable exist (a serial console option; debug output goes to COM1 or COM2 with baud rates from the `dbaud` and
`rbaud` options). Graphics initialisation order, display timing tables (the HAL has a Cobalt video timing table
`cobaltVTimings` and an I2C path for flat-panel and monitor identification) belong to
[devices/cobalt-graphics](../../devices/cobalt-graphics/) and are not read here.

## What no source settles

How the memory controller's timing and bank registers are programmed and their reset values; how the graphics reservation is
chosen; whether the firmware assigns PCI resources for any device before the OS; the meanings of the Lithium `+0x48`, `+0x58`
and `+0x60`-`+0x70` writes and the Cobalt APIC `+0xffc` write; where the embedded legacy-BIOS image is mapped and whether any of it
is visible to an OS; the components, classes and keys of the ARC tree beyond the nodes named above; which firmware vectors
`arcldr.exe` calls; the private vector's purpose; later firmware versions; and the Linux ARC loaders. All are in
[questions/visws-firmware-open.md](../../questions/visws-firmware-open.md).
