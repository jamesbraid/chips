# Altix 350 boot path: processor reset to multi-user, against what is reverse-engineered

A map for planning the remaining reverse-engineering of the SN2 boot path on the Altix 350 (SHub 1, IP57 node board, base
I/O card on a PIC). For each stage it says what happens, the hardware touched, the interface to the next stage, where our
evidence is and how it is graded, and what is still unknown. It does not re-derive anything: the owning page carries the
reading and its review. Binaries are listed in [the IA-64 inventory](../../references/ia64-binaries.md).

**Grades** follow [AGENTS.md](../../AGENTS.md): **established**, **inferred**, **unknown**. A page's review state is one of
*reviewed* (an independent review section names the cleared scope), *written-unreviewed*, *in progress* or *not started*.
Linux is cited as `v5.3:path` (line numbers are those of the v5.3 file); SGI's Linux platform code counts as vendor source
under the evidence order. The PROM image read is `shub1snprom.bin`, SAL 5.04, snprom 10.54 (sha256 `51ccf9ad...3a34617`),
which SGI's README for the package names as the image for the Altix 350 ([holdings](../../references/sn2-holdings.md#system-firmware)).
Whether that image boots a real 350 has not been shown. Everything about the node board (IP57) is inferred from the manual, because
the PROM names only IP41 ([boot-sequence](../../software/firmware/snprom/boot-sequence.md#node-board-identification-ip41-ip57-others)).

## The path at a glance

| # | Stage | Runs from | Hands over through |
|---|---|---|---|
| 1 | Processor reset, PAL_A, PAL_B | flash, no RAM | PAL_A to SAL_A entry (registers `r20`, `r33` to `r37`) |
| 2 | SAL_A, SAL_B (`main`, jump to RAM, `main_two`, `main_three`) | flash, then RAM | SAL system table, SAL entry points, EFI image |
| 3 | PAL and SAL runtime interfaces the OS uses | RAM (virtual and physical mode) | SAL procedure ids, PAL procedure indexes |
| 4 | EFI firmware | RAM | EFI tables, memory map, EFI runtime services, console ([read](../../software/firmware/snprom/efi.md)) |
| 5 | Boot loader (ELILO) | EFI application | `ia64_boot_param`, kernel entry |
| 6 | Linux early boot (SN2 platform) | RAM | SAL calls, ACPI, klconfig, PROM-built structures |
| 7 | Initrd and userland to multi-user | RAM | `/dev` and `/proc` nodes the SN2 drivers expose |

## 1. Processor reset and PAL_A

**What happens.** The processor starts executing in the firmware address space below 4 GiB. A model needs `0xFFFFFFF0` (IA-32
reset code), `0xFFFFFFE8` (SALE_ENTRY), `0xFFFFFFE0` (FIT pointer) and `0xFFFFFFD0` (the PAL_A FIT entry) from the image's top
32 bytes ([boot-sequence](../../software/firmware/snprom/boot-sequence.md#processor-reset-entry); architecture from the Intel
Software Developer's Manual vol. 2 rev 2.3, section 11.1.6). The generic PAL_A at `0xffff8000` to `0xffffffbf` walks the FIT
for the best processor-specific PAL_A by `cpuid[3]` family and model, calls the candidate through `br.ia` with the image
address and size in `r2` and `r3`, and reads `r1` back as accept or reject. It then branches to image offset `0x300`.
The processor-specific PAL_A and PAL_B are entered by SAL_A's reason-3 call, then PAL enters SAL_A with reason 0.

**Hardware touched.** None of the SHub. The PAL code writes processor model-specific registers only
([pal-msrs](../../software/firmware/snprom/pal-msrs.md)): the generic PAL_A has 52 `msr` sites; the reset and hand-off path writes
`msr[212]`, `msr[1225]`, `msr[0]` and `msr[1641]` to `msr[1643]` and tests `msr[1640]` bit 56.

**Evidence.**
- Image top, FIT, PAL_A search, hand-off to offset `0x300`: established, reviewed.
- `br.ia` as an accept/reject call (arguments, result in `r1`): established as code behaviour, reviewed. That it
  authenticates the PAL image is **inferred** from the accept/reject use, the `msr[1225]` write before it and the checksum
  walk at `0xFFFF9120`; the image carries no signature name for PAL (the SAL runtime has `main_verify_elf_signature`, role
  unknown).
- First instruction fetched at `0xFFFFFFB0` (PALE_RESET): **inferred**, from Intel's patent US 6,542,981, a published
  third-party trace and the image's vector layout. The manual gives no address. `0xFFFFFF70` is the only vector whose
  code reaches the processor-specific PAL_A and so SAL_A (established).
- Intel's PAL_A and PAL_B for the same steppings were compared by bundle: generic PAL_A 2043 of 2048 bundles match, specific
  PAL_A 1.27 and 5.37 are byte-identical to Intel's (reviewed, [pal-msrs](../../software/firmware/snprom/pal-msrs.md#review)).

**Gaps.**
1. What the reset-time `br.ia` does and whether control returns from it. Needs an Itanium 2 processor reference that names
   the reset sequence, or a hardware trace; neither is held.
2. Whether PAL_A checks anything more than the accept/reject result, and whether any shipped PAL is signed. Route: read the
   processor-specific PAL_A at its `0x300` entry beyond the first MSR write, and the `main_verify_elf_signature` caller in the SAL runtime.
3. What any MSR does. No public document names them; the page grades none established for hardware meaning.
4. Processor reset state (PSR, ITC, IP) for a model.

## 2. SAL_A and SAL_B

**What happens.** In order, as the PROM's own progress codes name them ([boot-sequence](../../software/firmware/snprom/boot-sequence.md#the-path-in-one-table)):

| Step | Code | Content | Where read |
|---|---|---|---|
| SAL_A reasons 3, 0 | 48 | SHub 1 local MMRs, no RAM, no L1 | [prom-reset](../../devices/shub/prom-reset.md) section 1 |
| SAL_B reset entry | 0x31, 0x35 | cache-preloaded 256 KB at physical `0x1000000` | prom-reset section 2 |
| `main()` in flash | 8 to 0x19 | L1 link, election, debug switches, DIMM discovery, memory init and test | [node-bringup](../../software/firmware/snprom/node-bringup.md), [memory-init](../../devices/shub/memory-init.md) |
| jump to RAM, `main_two` | 0x19 to 0x23 | PAL shadow, SAL copy, NUMAlink discovery or skip, NASID and routes | boot-sequence, static reading section 1 |
| `main_three` | 0x24 to 0x27 | I/O discovery (II, XIO widget 0, PIC), klconfig | boot-sequence, static reading section 2 |
| load and jump to EFI | 0x44 to 0x48 | FIT EFI component expanded to RAM | boot-sequence, static reading section 5 |

**Hardware touched, and where each is graded.**
- *SHub 1 register accesses from reset to console start*: every access, with the value it must return, in
  [prom-reset](../../devices/shub/prom-reset.md). Established as accesses; hardware meaning mostly unknown. Reviewed twice.
  Reset values: none established; the page says a read after firmware initialisation is not a reset value.
- *Election.* The node lock and the claim-bit protocol on `0x81_5003_1540`, the local-master arbitration pair and the
  `0x1_2002_0080` accesses: established, reviewed (prom-reset review sections).
- *L1 link start.* A 16550-style UART in the SHub junk bus at local offset `0x7_fed4_0000 + 8n`, a request frame, ids from
  `0x1005` ("Prom starting...") onward. PROM side established ([boot-sequence](../../software/firmware/snprom/boot-sequence.md#l1-controller-dependency)),
  controller side in sysco: the sysco repository's `software/firmware/l1/sn2-prom-link-1.62.1.md` (the link) and `sn2-l1-settings-defaults-1.62.1.md` (debug switches, bit 11 skip). Reviewed. Without an answering L1 the
  PROM stops at 0x8d before memory (established for the transaction path).
- *Memory init and test.* Memory and directory (MD) register programming and the memory-test engine contract
  ([memory-init](../../devices/shub/memory-init.md)): established as code, **written-unreviewed**. The older single-node reading
  ([node-bringup](../../software/firmware/snprom/node-bringup.md)) is reviewed.
- *SPD.* DIMM identity only through the L1 (request `0x0006`, selector 4), the id formula, parser and 2 GiB worked example:
  reviewed ([node-bringup](../../software/firmware/snprom/node-bringup.md#spd-contents-for-a-2-gib-node)); the L1 reply from the
  controller side in sysco `software/firmware/l1/sn2-dimm-spd-request.md`, reviewed.
- *NASID.* `chipset_get_nasid` reads bits 42:32 of `0x81_1006_0580`; a write routine sets NASID and size fields. Established, reviewed.
  Not cleared: the NASID reset behaviour.
- *No-link NUMAlink route.* Skip bit 11 of the debug word, or with the skip clear and no link: a node whose two NI ports do
  not read 9 in the low nibble of `0x1_5000_0000 + p * 0x2000` skips the crawl. Established, reviewed
  ([boot-sequence](../../software/firmware/snprom/boot-sequence.md#numalink-discovery-with-the-skip-bit-clear-and-no-link)).
- *Interrupt delivery.* In progress, no page. The PROM's PIC interrupt set-up (`0xffabfa80`, writes to PIC `0x108`, `0x110`,
  `0x128`) is read; how the PROM allocates a bridge-to-SHub path for `SN_SAL_IOIF_INTERRUPT` is not.
- *I/O: II, PIC, IOC4.* Static reading of `main` and `main_three` (`0xffab1cc0` II register set-up in `main`; widget 0 id read, PIC initialiser
  `0xffab0c00`, riser EEPROM): **written-unreviewed**. PIC part `0xd102` with manufacturer 36 and the register offsets match
  `v5.3:arch/ia64/include/asm/sn/pic.h` ([devices/pic](../../devices/pic/README.md#against-sgis-altix-linux-code-linux-53-pin-4d856f72c10e)).
  No PCI walk and no IOC4 register read happen before EFI on this path (inferred from reachability).

**Interface out.** SAL system table (signature `SST_`, OEM id `SGI`, product id `SN2`), the SAL entry points, the SAL
runtime component (type 0x12, expands to an ELF) and the klconfig graph the kernel fetches by `SN_SAL_GET_KLCONFIG_ADDR`.
Built before the jump to EFI (established that the PROM builds them; entry types and klconfig contents: unknown).

**Gaps.**
1. L1 command ids and the module-type reply the real L1 gives for each request in `main`; the interpreter run the page
   describes stalled in the route-table walk (`0xffa5b5d0`) because the jump to RAM was skipped. Route: re-run with the
   jump or a hand-built layout, then the L1 notes in sysco.
2. `main` (call `0xffa1a40c`): the II set-up `0xffab1cc0` and brick presence read `0xffab2e60`. `main_three`: link-credit writes `0xffab0130` and the
   widget ids a one-node 350 must return (`0xd000` or `0xd100` at widget 0, `0xd102` PIC). Unreviewed, partly static.
3. Interrupt allocation for PIC pins: which SHub register a bridge interrupt store names.
4. What differs for an IP57 board: the PROM has no IP57 string. A captured board EEPROM area from a real 350 would settle
   whether the L1 EEPROM or the SHub ID is the discriminator.
5. PAL calls 99, 520, 528, 530 (implementation-specific).
6. Reset values of the SHub registers (all unknown).

## 3. PAL and SAL interfaces the OS uses

**What happens.** After handoff the OS calls SAL through the entry point in the SAL system table, and PAL through the
procedure entry the SAL tells it about. The SN-specific calls are ids `0x02000000` upward.

**Evidence.**
- *Kernel side of every SN SAL call*, with arguments, results, which calls are fatal, and the first-use order:
  [software/sal](../../software/sal/README.md). Established (Linux v5.3 `sn_sal.h` and all callers), reviewed twice.
- *PROM side*: which ids each of four PROM images answers, in which mode, and the handlers read in full
  (`SN_SAL_GET_SN_INFO`, `SN_SAL_GET_SAPIC_INFO`): [snprom README](../../software/firmware/snprom/README.md#sal-dispatch).
  Established for the tables, reviewed. Most handlers are named, not read.
- *PAL procedures SAL_B calls* (indexes 1 to 260 plus four implementation-specific): in progress, in
  [boot-sequence](../../software/firmware/snprom/boot-sequence.md#pal-procedures-sal_b-calls). Names are from the `pal.h`
  numbering and are established for the call sites, inferred for effect. The PAL procedures the *OS* calls (the generic IA-64
  set: `PAL_CACHE_FLUSH`, `PAL_MC_*`, `PAL_HALT_LIGHT`, and so on) are public architecture and not mapped here.

**Gaps.**
1. PROM behaviour inside each SN SAL call the kernel needs: `GET_KLCONFIG_ADDR`, `GET_SN_INFO` (SHub 1 read, SHub 2 value V at
   `0x2_2011_0000` is open), `IOIF_*`, console, `IOIF_INTERRUPT`. [sn2-sal-open](../../questions/sn2-sal-open.md).
2. The structures the PROM fills (`hubdev_info`, `pcibus_bussoft`, `sn_irq_info`, klconfig): layouts are
   established from the kernel headers; which pointers are physical is not. `klconfig.h` was fetched but not read for the SAL page.
3. Which ACPI or older direct I/O path a 2.6.5 PROM serves (below).
4. PAL procedure effect for the implementation-specific indexes.

## 4. EFI

**What happens.** The FIT EFI component (type 0x1f) is a gzip-compressed IA-64 ELF of 2.5 MB (SAL 5.04 image). It is an EFI
1.10 firmware built from the Intel sample framework with SGI additions: an Altix PCI root bridge, an IOC4 ATA/ATAPI pass-through,
a system-controller console, SATA, USB, shell, boot manager, a BIOS emulator interface. A separate FIT component (type 0x22)
is a tar of three EFI drivers, `drv_fpswa.efi` among them (the floating-point software assist IA-64 operating systems need).

**Evidence.**
- Components, sizes, symbols: established ([snprom README](../../software/firmware/snprom/README.md#image-layout)), reviewed.
- Hand-off (`0xffaf8c50`: loads the SAL runtime, the BIOS emulator, then "Loading EFI ...", builds an 88-byte record
  printed as "SAL->EFI handoff at", enters EFI with `r32` = 1 and `r33` = the record): the record fields, the entry and what EFI reads are in
  [efi.md](../../software/firmware/snprom/efi.md#2-the-hand-off-from-sal_b), **written-unreviewed**.
- *Console, the `rpd` switch.* The PROM's console specification string is `rpd` (data at `0xffbba0a0`); `console_probe` walks it,
  calling each console object's probe: `d` the direct junk-bus UART (scratch test `0x55` then `0xaa` at `0xf_fed4_0038`, master
  node only), `p` and `r` the system-controller path, `e` the EFI callback console (not in the string). Read in full,
  established, unreviewed. Which of `p`, `r` is which controller route, and how the EFI console
  text output reaches the user: EFI's console is SAL console calls (`0x02000023` and others) with a serial-I/O layer on top, no IOC4 or UART access of its own
  ([efi.md](../../software/firmware/snprom/efi.md#4-the-console), established). No IOC4 UART is selected on the reset-to-EFI path (inferred).
- EFI configuration tables: it installs the SAL system table, the ACPI 2.0 RSDP (the ACPI 1.0 slot is 0 and adds nothing), an HCDP table and the debug image table, and the PCI option ROM table
  when its count is nonzero; MPS is not installed and nothing installs SMBIOS (established,
  [efi.md](../../software/firmware/snprom/efi.md#3-configuration-tables-and-where-sn2-specific-data-lives)). The tables themselves (ACPI, memory map, SAL system table, runtime services) are in [os-handoff-tables.md](../../software/firmware/snprom/os-handoff-tables.md).
- Variable store: a flash-backed store at the top of the address space, "Syncing EFI var. store" at `0xffaf6640` and `0xffaf6d10`.
  Role inferred; contents and layout unknown. EFI runtime time calls go through SAL ids `0x0a` and `0x0b`, variable calls through `0x08` (established from the EFI image's constants, per the snprom README).
- Boot manager and variables: the Intel sample boot manager with `Boot####`, `BootOrder`, `BootNext`, `Timeout` (default 7 s) and a default
  option per removable block device, file system, network and shell; the store is read and written through SAL
  ([efi.md](../../software/firmware/snprom/efi.md#5-boot-manager-variables-and-finding-the-boot-loader), established). No capture of the 350's EFI shell is held.

**Interface out.** An EFI system table with the configuration tables above, the EFI memory map, the console devices, the
Simple File System on the boot partition (the PROM carries SATA and ATA pass-through drivers for IOC4).

**Gaps.**
1. The SAL_B handlers behind EFI's flash variable store (`0x02000008`) and callbacks (`0x3000`, `0x5000`, `0x6000`), and the flash format.
2. Whether the 350 PROM publishes an ACPI 2.0 DSDT with `SGIHUB` devices or the older direct I/O description (the RSDP builders are unread).
3. Which of the console routes `p` and `r` the SAL console calls take.
4. Flash variable-store format and what survives power loss.

## 5. Boot loader (ELILO)

**What happens.** ELILO is an EFI application on the boot partition. Read from the public source (the pinned `elilo`
repository, commit `4e5817767696`, files `elilo.c`, `bootparams.c`, `ia64/system.c`, `ia64/plain_loader.c`; the index calls
the pin 3.16 but the repository has no tags, so which release SGI shipped is unverified): it reads its configuration file from a
list of default names, loads the kernel ELF (gzip or plain) and optional initrd with the EFI file protocol, allocates a
16 KiB boot-parameter block, queries FPSWA, takes the memory map, writes `efi_systab`, `efi_memmap` (with size, descriptor size
and version), `command_line`, `initrd_start`, `initrd_size`, `vmcode_start`, `vmcode_size` and the console geometry, calls
`ExitBootServices` with the map key, and branches to the ELF entry point (`start_kernel(kentry, bp)`). The entry point must be a
physical address: a region-bits virtual address is rejected.

**Hardware touched.** None directly; it uses the EFI file protocol (so IOC4 ATA or a SCSI HBA through EFI drivers) and the EFI console.

**Evidence.** Two ELILO builds (3.16 and Debian 3.4-7.sarge.1) and the 3.16 source are now read: the boot-parameter layout, the memory-map
hand-off, the kernel load address and entry, and the register state at the jump (`r28` only) are on
[ELILO on IA-64](../../software/boot/elilo-ia64.md), established. **Unknown**: which release SGI shipped, and its `elilo.conf` and boot partition
image ([inventory](../../references/ia64-binaries.md#boot-path-coverage)). The kernel side of the interface, `ia64_boot_param` use at
`v5.3:arch/ia64/kernel/setup.c` (lines 312 to 360, 407 to 412, 533), is established.

**Gaps.**
1. The command line SGI shipped (`console=`, `root=`, `machvec=`), and whether any option selects the machine vector
   (below: the kernel normally chooses by itself).
2. The boot partition layout (`efi/sgi/snprom/`, ELILO config) and how the PROM flash update tool places images.
   [snprom images](../../software/firmware/snprom/images.md) notes the install script's behaviour; the partition itself is not held.
3. FPSWA load: the PROM carries `drv_fpswa.efi`; whether ELILO loads another copy.

## 6. Linux early boot on SN2

Tree and version: Linux v5.3 is the last release with SN2; the ProPack 2.6.5 kernel held (SLES 9 SP3 SN2 2.6.5-7.244, row 9
of the inventory) is read in Ghidra on [SN2 early boot](../../software/linux/sn2-early-boot.md): its entry state, the order of
`setup_arch`, the EFI, SAL-table and ACPI requirements, the SAL and PAL calls and the first SHub registers. It differs from v5.3
(direct I/O calls, two `SET_OS_FEATURE_SET` calls, no `SET_CPU_NUMBER`). The sequence below is v5.3, graded **established** for
what the kernel does; every PROM-side effect is unknown unless a page above says otherwise.

| Step | v5.3 code | SAL or hardware |
|---|---|---|
| `efi_init` | `arch/ia64/kernel/setup.c` 536 | EFI configuration table: SAL system table, ACPI 2.0, SMBIOS, HCDP |
| Machine vector | `machvec_init_from_cmdline` 545, `acpi_get_sysname` (`arch/ia64/kernel/acpi.c` 62 to 100): XSDT OEM id "SGI" selects `sn2` (OEM table id ending "UV" selects `uv`) | ACPI XSDT from the PROM |
| `early_acpi_boot_init`, `ia64_sal_init` | `setup.c` 556, 575 | SAL system table entry point and revision |
| `platform_setup` = `sn_setup` | `setup.c` 617; `arch/ia64/include/asm/machvec_sn2.h` 73; `arch/ia64/sn/kernel/setup.c` 370 | |
| in `sn_setup` | `SET_ERROR_HANDLING_FEATURES`, `SET_OS_FEATURE_SET` x4 (before `acpi_table_init`, so an ACPI-capable PROM rebuilds the DSDT), `build_cnode_tables` (`GET_KLCONFIG_ADDR` per node, line 745), `SAL_FREQ_BASE`, `sn_init_pdas`, `sn_cpu_init`, `sn_timer_init` | SAL, klconfig |
| `sn_cpu_init` | `GET_SN_INFO` 594, `SET_CPU_NUMBER` 611 and 615, `GET_PROM_FEATURE_SET` 625, `GET_SAPIC_INFO` 630 | SAL |
| `arch_initcall` `sn_io_early_init` | `arch/ia64/sn/kernel/io_common.c` 457 to 506: reads DSDT OEM revision; ACPI path `sn_io_acpi_init` (`io_acpi_init.c` 497: `acpi_get_devices("SGIHUB")`, `SN_SAL_IOIF_INIT`, panic on failure) or direct `sn_io_init` (`io_init.c` 298: `GET_HUBDEV_INFO` per node, `GET_PCIBUS_INFO` per segment and bus); registers the PIC/TIOCP, TIOCA and TIOCE providers (481 to 483) | SAL, PROM-built structures |
| `fs_initcall` `sn_io_late_init` | `io_common.c` 555: nearest node for each PCI bridge, then `sn_ioif_inited = 1` | |

**6a. Machine vector, `sn_setup`, SAL calls.** README of this directory (SHub generation, `is_shub1()` at `setup.c` 195 to 225
and 681 to 695), [software/sal](../../software/sal/README.md#calls-needed-to-boot). Established, reviewed. Gap: the DSDT OEM revision threshold (0x20101) that selects the ACPI path
is quoted by the SAL page and was not re-verified there; the 350 PROM's DSDT is unknown.

**6b. klconfig and discovery.** `io_init.c`, `io_acpi_init.c`, `klconfig.h` (246 lines at v5.3: `kl_config_hdr`, `lboard_s`, `klinfo_s`, `KLTYPE_SNIA`
and `KLTYPE_TIO`, brick types). The kernel walks the board list in `build_cnode_tables` only to find nodes that need a compact
node number. SAL and structure facts: [software/sal](../../software/sal/README.md#structures-the-prom-fills), reviewed. The layout of the klconfig graph, what the PROM
writes on a one-node 350 and which three fields Linux reads are on [klconfig](klconfig.md): layouts established from v5.3 and v2.6.12
and cross-checked against the PROM's stores; the PROM builder read; the I/O board type for a 350 and the heap address of the
area unknown. The ProPack 2.6.5 kernel has no DWARF, so only its scan loads (offsets 20, 5, 48) confirm the layout.

**6c. SHub MMRs Linux touches.** [devices/shub](../../devices/shub/README.md), [registers](../../devices/shub/registers.md), [devices/shub_ii](../../devices/shub_ii/README.md),
[address map](address-map.md). Offsets and field positions of the registers the kernel names: established, reviewed. Meaning of
registers the PROM programs and the kernel does not name: unknown ([shub-registers-unnamed](../../questions/shub-registers-unnamed.md)).

**6d. Interrupts, timer, mmtimer.** `arch/ia64/sn/kernel/irq.c`: `sn_irq_init` (270) sets the device vector range 0x3c to 0xe6;
`sn_intr_alloc` (33) calls `SN_SAL_IOIF_INTERRUPT` (`0x0200004a`) so firmware picks the target and Crosstalk address;
the lost-interrupt scan runs from the timer. `arch/ia64/sn/kernel/sn2/timer.c`: the clocksource `sn2_rtc` reads the 55-bit
real-time counter, frequency from `SAL_FREQ_BASE`, udelay on the RTC. mmtimer (`drivers/char/mmtimer.c`) is gone by v5.3, so it is cited at v4.9.
IPIs and comparator programming: [devices/shub](../../devices/shub/README.md#interrupts-and-ipis) and
[real-time clock](../../devices/shub/README.md#real-time-clock-and-comparators). Established, reviewed. Gap: which SHub register a PIC pin's
store lands in (unknown; the kernel comment says PIC interrupts target a SHub interrupt register, TIO ones do not).

**6e. PCI through PIC and the providers.** `arch/ia64/sn/pci/pcibr/pcibr_provider.c` (PIC and TIOCP share one provider, 255 to 258;
`pcibr_bus_fixup` 114), `pcibr_dma.c`, `pcibr_ate.c`, `pci_dma.c`. PIC: [devices/pic](../../devices/pic/README.md), including its comparison against v5.3;
TIOCP: [devices/tiocp](../../devices/tiocp/README.md). The kernel does not walk configuration space itself for the bridge setup:
bus soft state comes from the PROM. Established for the kernel, reviewed. Gap: nothing yet shows the PROM's `SN_SAL_IOIF_*`
handlers filling these structures for a 350.

**6f. Console and disk.** Console: `sn_console` (`drivers/tty/serial/sn_console.c`) registers `ttySG0` and requests vector
`SGI_UART_VECTOR` (0xe9, line 706); all I/O is SAL console calls (`0x02000021` to `0x0200002b`). The system-controller
driver `snsc.c` shares the vector. Both are in sysco `software/firmware/l1/sn2-controller-host-protocol.md`
(established, reviewed). The IOC4 serial driver (`drivers/tty/serial/ioc4_serial.c`, nodes `ttyIOC*`) exists in v5.3 but is not the console path.
Disk: IOC4 ([devices/ioc4](../../devices/ioc4/README.md), `drivers/misc/ioc4.c` `ioc4_variant` at line 231, IO9 / IO10 / PCI-RT; IDE in
`drivers/ide/sgiioc4.c`), SCSI on the IO9 (QLogic ISP12160, [devices/isp12160](../../devices/isp12160/README.md)) and SATA on the IO10
(Vitesse VSC 7174, no device page). Grades as in [README](README.md). Gap: the IO10 SATA path, since the IO10 is the later 350's standard card and a 2008 patch
says it cannot boot without the Vitesse driver; no VSC 7174 contract exists.

## 7. Initrd and userland to multi-user

**What happens.** The kernel mounts the initrd ELILO loaded, then the root file system, and runs init. For SN2 the
machine-specific userland is what talks to the drivers above: `/dev/snsc/*` (system-controller subchannels), `ttySG0`, the
`/proc` nodes the platform code registers (including PROM information from `SN_SAL_GET_FIT_COMPT`; the hardware performance interface
was not checked), and the L1/L2 command-line tools.

**Evidence.** **Not started.** No ProPack RPM, initrd, root file system, or user-space tool is held (inventory: "zero standalone ...
initrd, userland or library files"). The `snxsc_firmware` package is controller firmware with host-side flash tools, listed
in [the inventory](../../references/ia64-binaries.md) and read on the controller side in sysco. Hardware userland touches
directly: unknown; the kernel mediates everything through the SAL, so the only direct hardware access found is `mmtimer`'s
user-mapped RTC counter at v4.9.

**Gaps.**
1. Which SGI hardware daemons and tools ProPack installs and starts at boot. Route: the ProPack manual 007-3844-001 ("Start
   Here") and driver guide 007-4520-006 are in our holdings, not read for this; ProPack media is not held.
2. The shipped initrd's module list (IDE, SCSI, IOC4, `sgi-xp` is irrelevant on one node).
3. Console for init: `console=ttySG0` on the kernel line, not yet confirmed from a shipped bootloader configuration.

## Where the evidence stands

| Stage | Evidence status | Next RE item | Binaries it needs |
|---|---|---|---|
| 1 PAL reset, `br.ia`, PAL image check | in progress (reset entry reviewed; `br.ia` effect and PAL authentication unknown) | read the processor-specific PAL_A past its entry; find the callers of `main_verify_elf_signature` | inventory rows 7 (PROM 10.54 SAL 5.04) and 4 for comparison |
| 2a SAL_A, SAL_B reset path, SHub accesses, election, L1 link | reviewed | none beyond reset values | row 7 |
| 2b Memory init and test, SPD, NASID, no-link route | memory init written-unreviewed; SPD, NASID, no-link reviewed | independent review of memory-init; route-table initialisation (item 1 of the stage 2 gaps) | row 7 |
| 2c Interrupt delivery in the PROM | in progress | trace `SN_SAL_IOIF_INTERRUPT` handler and PIC interrupt set-up | row 7 |
| 2d I/O: II, PIC, IOC4 | written-unreviewed (static); IOC4 PROM reads not started | `0xffab1cc0` II set-up (in `main`), `main_three` run, then the IOC4 probe in the SAL I/O handlers | row 7 |
| 3 SAL and PAL runtime interfaces | kernel side reviewed; PROM handlers for the boot-time calls read ([sn2-runtime](../../software/sal/sn2-runtime.md), written-unreviewed); PAL procedures in progress | independent review of the SAL runtime page; read the provider methods behind `IOIF_INTERRUPT` and the console device backends | rows 7 and 8 (SHub 2, SAL not read); row 9 for the shipped caller set |
| 4 EFI | read, written-unreviewed ([efi.md](../../software/firmware/snprom/efi.md): container, hand-off record, tables, console calls, boot manager, variable store) | PROM-side builders of the SAL and ACPI tables, SAL handlers for the variable store and timer callbacks, the PCI root bridge calls | row 7 (EFI component inside it); see inventory |
| 5 ELILO | read: two builds and the 3.16 source ([elilo-ia64](../../software/boot/elilo-ia64.md)) | the shipped release, `elilo.conf` and boot partition layout | not held: see inventory |
| 6a-b Linux platform setup, SAL calls, klconfig | 6a reviewed; 6b [written-unreviewed](klconfig.md); held 2.6.5 kernel read ([sn2-early-boot](../../software/linux/sn2-early-boot.md), written-unreviewed) | independent review of klconfig; read `0xffa7e3b0` for the 350's I/O board type | row 9 (symbols, no DWARF); row 7 |
| 6c SHub MMRs | reviewed (kernel-named registers) | name the PROM-programmed registers | row 7 |
| 6d Interrupts, timer | reviewed (kernel side) | PROM side of interrupt allocation (2c) | row 7 |
| 6e PCI, PIC and TIOCP | reviewed (kernel side) | PROM side of `IOIF_*` structure fill | row 7 |
| 6f Console and disk | console reviewed; disk (IOC4, ISP12160) reviewed against Linux; IO10 SATA not started | VSC 7174 device page | none; see inventory |
| 7 Initrd and userland | not started | find ProPack media or a shipped root file system | not held: see inventory |

## Top gaps in boot order

1. Stage 1: the reset-time `br.ia` and whether PAL_A authenticates anything.
2. Stage 2: the route-table initialisation and the L1 reply set the real controller gives, so the PROM can be run past `main_two` (blocked now on the skipped jump to RAM).
3. Stage 2: `main_three` I/O discovery and PIC interrupt allocation, which decide whether a PROM reaches "Loading EFI" on a 350.
4. Stage 4: the PROM-side builders of the SAL and ACPI tables and the SAL handlers behind EFI's variable store, timer and root-bridge calls (the EFI component itself is read: [efi.md](../../software/firmware/snprom/efi.md)).
5. Stages 5 and 7: no shipped loader, configuration, initrd or userland is held, so the last two stages have only the public Linux and ELILO source to go on.

## Sources

PROM: snprom 10.54 (SAL 5.04) read in the pages linked above. Linux: v5.3 single files from `raw.githubusercontent.com/torvalds/linux/v5.3/`
(`arch/ia64/kernel/{setup,acpi,efi,sal,machvec}.c`, `arch/ia64/sn/kernel/{setup,irq,io_init,io_acpi_init,io_common,klconflib}.c`,
`arch/ia64/sn/kernel/sn2/{timer,sn2_smp}.c`, `arch/ia64/sn/pci/`, `arch/ia64/include/asm/sn/{klconfig,sn_sal,intr,addrs}.h`,
`arch/ia64/include/asm/machvec_sn2.h`, `drivers/tty/serial/{sn_console,ioc4_serial}.c`, `drivers/ide/sgiioc4.c`, `drivers/misc/ioc4.c`,
`drivers/char/snsc.c`); `drivers/char/mmtimer.c` at v4.9. ELILO: `spinl0ck/elilo` commit `4e5817767696`. Manuals: Altix 350 user's guide
007-4660-001 (printed pp. 58 to 60: console and L1 boot commands) and 007-4660-002; the driver porting guide 007-4520-006 was not
re-read for this page. No ELILO, EFI shell or elilo.conf text from a 350 was available.
