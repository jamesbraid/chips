# Runtime services Linux IA-64 calls on an Altix 350, and what an SN2 kernel needs from the platform

One table per layer (SAL, PAL, EFI runtime) of every firmware call a Linux IA-64 SN2 kernel makes from `start_kernel` to multi-user, with the PROM routine that answers it
(SAL 5.04 of snprom 10.54, `shub1snprom.bin`), the platform hardware behind it and what happens if it fails. The last section lists what the kernel reads from the platform
directly (registers, PCI discovery, interrupts, console, timers) in the order it does so. The call arguments and result handling are in [README.md](README.md); the handler
behaviour is in [sn2-runtime.md](sn2-runtime.md); the loader hand-off is in [elilo-ia64.md](../boot/elilo-ia64.md) and the held kernel's early path in
[sn2-early-boot.md](../linux/sn2-early-boot.md).

**Sources and grades.** PROM side: the dispatch tables of the image (SAL_B table at `0xffc25ec8`, runtime table at `rt:0xa29f8`) and the handlers read in Ghidra, as
cited by [sn2-runtime.md](sn2-runtime.md), [os-handoff-tables.md](../firmware/snprom/os-handoff-tables.md) and [efi.md](../firmware/snprom/efi.md); the handlers added here
(`0x01000006`, `0x01000009`, `0x01000010`, `0x01000011`, `0x01000013`, `0x01000020`, `0x02000008`, callbacks `0x6000` and `0x7000`) were decompiled this round from their SAL_B
addresses. Kernel side: a mainline Linux source snapshot of the 2.6.3x era (`arch/ia64/kernel/{sal,efi,time,smpboot,setup}.c`, `arch/ia64/mm/tlb.c`,
`arch/ia64/include/asm/{pal,sal,system}.h`, `arch/ia64/sn/kernel/{setup,irq,io_init}.c`, `arch/ia64/sn/kernel/sn2/{timer,sn2_smp}.c`, `ptc_deadlock.S`,
`arch/ia64/sn/pci/pcibr/pcibr_provider.c`, `drivers/serial/sn_console.c`), plus the v5.3 and v2.6.12 reads already recorded in the pages above. *Established* here is what the
kernel source does or the PROM routine does; **inferred** and **unknown** are marked. No emulator ran. The kernel's 2.6.3x tree is not the held 2.6.5-7.244 kernel; the
differences that matter are named where they occur ([sn2-early-boot.md](../linux/sn2-early-boot.md#differences-from-v53)).

Failure column: **stops** = the kernel panics, BUGs or hangs; **degrades** = it prints a message and continues with a default or without the feature.

## 1. SAL

Handler addresses: `0xffb......` is the SAL_B (physical-mode) handler; `rt:0x....` is the virtual-mode runtime handler (ELF address; Ghidra adds `0x100000000`); "SAL_B only" ids
are forwarded from the runtime table to SAL_B in physical mode. A call to an id in neither table returns -1 (not implemented).

| Id | Name | Linux caller | PROM handler | Platform hardware it needs | If it fails |
|---|---|---|---|---|---|
| `0x01000000` | SET_VECTORS | `ia64_mca_init` (types 0, 1), `init_smp_config` (type 2) | `0xffb129e0`, `rt:0x3740` | stores entry points into every node's record through the node windows | degrades (message) |
| `0x01000001`/`02`/`03` | GET_STATE_INFO, _SIZE, CLEAR_STATE_INFO | MCA/CPE logging | `0xffb12ad0`/`0xffb12c00`/`0xffb12ce0`; rt `0x3830`, `0x3960` | PROM error log | degrades |
| `0x01000004`/`05` | MC_RENDEZ, MC_SET_PARAMS | `ia64_mca_init` | `0xffb12fb0`, `0xffb12dd0`; rt `0x3d10`, `0x3b30` | none (r9 = `0xbf68` from `0x05`) | degrades |
| `0x01000006` | REGISTER_PHYSICAL_ADDR | not called on the boot path | `0xffb94970`, a thunk to the "not implemented" routine `0xffb1daf0` | none | returns -1 (established for SAL_B; the runtime row was not read) |
| `0x01000008` | CACHE_FLUSH | kexec, KVM; not on the boot path | `0xffb16340`, `rt:0x6ea0` | PAL_CACHE_FLUSH, SHub MMR `0x9_1000_0380` per node | n/a |
| `0x01000009` | CACHE_INIT | not on the boot path | `0xffb165f0` (calls `0xffb204c0(1)`, -3 on failure) | PAL cache init | n/a |
| `0x01000010`/`11` | PCI_CONFIG_READ/WRITE | **the SN PCI bus scan**: `pci_scan_bus(..., &pci_root_ops)` uses `pci_sal_read`/`pci_sal_write` (`arch/ia64/pci/pci.c`) | `0xffb1e300`, `0xffb1e4b0` (SAL_B; runtime forwards) | segment/bus/dev/fn lookup into the bus objects, then the bridge's config space (PIC type 0/1 config) | status is 0 even for a missing device and the routine writes no data result then (read), so what the kernel sees in that case is whatever the return register held (**unknown**); a model should return all-ones. **Stops the PCI scan** if wrong |
| `0x01000012` | FREQ_BASE | `sn_setup` (type 2, RTC), `ia64_init_itm` (type 0, ITC) | `0xffb60270`, `rt:0x61410` | RTC period from the SHub `rtc_ctl` register | degrades (guesses 33.3 MHz) |
| `0x01000013` | PHYSICAL_ID_INFO | `identify_siblings` (`smpboot.c`) | `0xffb1b880` (calls `0xffa0dcf0`, returns status 0; r9 is not written by this routine, **unknown**) | CPU id | degrades |
| `0x01000020` | UPDATE_PAL | no caller | `0xffb94a80`, a thunk to `0xffb1daf0` | none | returns -1 (established) |

SN-specific ids (the `SN_SAL_*` of `sn_sal.h`). Every id here is established present in both PROM tables unless "SAL_B only"; the third column gives the first use.

| Id | Name | Kernel use | PROM handler | Platform hardware | If it fails |
|---|---|---|---|---|---|
| `0x0200001e` | GET_SN_INFO | `sn_cpu_init` (twice on the boot CPU) | `0xffb60640`, `rt:0x31d0` | SHub NASID register `0x1_1006_0580` | -1 selects SHub 1 defaults; < -1 **stops** (BUG) |
| `0x02000068` | SET_CPU_NUMBER | `sn_cpu_init` (v5.3 only) | `0xffb13a70`, `rt:0x47d0` | per-CPU record at `0x1000000` | ignored |
| `0x0200001a` | SET_ERROR_HANDLING_FEATURES | `sn_setup` | `0xffb13890`, `rt:0x45f0` | none | ignored |
| `0x02000066` | SET_OS_FEATURE_SET | `sn_setup`: 2.6.3x calls 0, 1, then `PCISEGMENT_ENABLE`, `ACPI_ENABLE` before `acpi_table_init`; the held 2.6.5 calls 0 and 1 only | `0xffb5fc90` | block B `+0xc8` flag word | ignored; features 2 and 3 make the PROM rebuild the DSDT |
| `0x02000005` | GET_KLCONFIG_ADDR | `sn_setup` per node | `0xffb19c20` | KLCONFIG in block A (64 KiB into the hwcfg block) | 0 or a bad board list **stops** (BUG) |
| `0x02000065` | GET_PROM_FEATURE_SET | `sn_cpu_init` pass 2 | `0xffb60170` | none | read until the first non-zero status; set 1 answers -2 |
| `0x0200001d` | GET_SAPIC_INFO | `sn_cpu_init`, IPI sends | `0xffb196c0`, `rt:0x85f0` | arithmetic only | -1 selects a fixed decode; < -1 **stops** |
| `0x02000004` | GET_MASTER_NASID | `sn_hwperf_init` | `0xffb60a40`, `rt:0x35d0` | block B `+0x100` | degrades |
| `0x02000021` to `0x0200002c` | console PUTC, GETC, PUTS, GETS, GETS_TIMEOUT, POLL, INTR, PUTB, (`29` read bytes), XMIT_CHARS, READC, (`2c` flush) | `sn_console.c`, EFI, early printk | `0xffb16d50` (`21`) through `0xffb178a0` (`2c`): `22` `0xffb16e30`, `23` `0xffb16f40`, `28` `0xffb170a0`, `24` `0xffb17190`, `25` `0xffb17270`, `29` `0xffb17360`, `26` `0xffb17480`, `2a` `0xffb17560`, `2b` `0xffb17650`, `27` `0xffb17760`; rt rows from `rt:0x78b0` | the system-controller (L1) UART on the SHub junk bus; no IOC4 | no console only |
| `0x0200002d` | console callback register | EFI only | `0xffb179b0` (SAL_B only; stores the pointer, returns 0) | none | n/a |
| `0x02000008` | flash and variable store (EFI only) | `PlInitNvVarStoreFlash`, EFI variable services | `0xffb182c0` | node flash | EFI starts with no variables; Linux unaffected ([efi-boot.md](../firmware/snprom/efi-boot.md#1-boot-options-and-the-variables)) |
| `0x0200000a`/`0b` | clock set / get | EFI `SetTime`/`GetTime` | `0xffb14200`, `0xffb14300`, via `0xffa1d1e0`/`0xffa1cef0` | SHub RTC `0x81_101c_0000` and a chip base-time method (`+0xb8`, unread: 1998-01-01 if it fails) | `GetTime` always returns success to the kernel |
| `0x02000013` | go virtual (EFI `SetVirtualAddressMap`) | EFI only | `0xffb14450` (case 0 walks the node table and rewrites the node-record pointers at `0x1000038` and block A `+0x50`/`+0xa0`; read as a pointer re-base, **inferred**) | none | the kernel tolerates a failed `SetVirtualAddressMap` |
| `0x02000002` | SYSTEM_RESET (and callback `0x5000`) | EFI `ResetSystem`, `machine_restart` paths | `0xffb1ba90` | L1 reset request | n/a |
| `0x02000045` | start I/O (EFI only) | EFI start-up | `0xffb20350` | pool buffer for I/O | ignored |
| `0x02000051` to `0x0200005f`, `0x64` | IOIF: error interrupt, `PCI_SAFE`, slot enable/disable, `GET_HUBDEV_INFO` (`55`), `GET_PCIBUS_INFO` (`56`), `GET_PCIDEV_INFO` (`57`), flush lists (`58`, `5a`), `IOIF_INIT` (`5f`), PCI topology (`64`) | I/O discovery (section 5) | one dispatcher, `0xffb1e660` (the `0x...5e` case is the exported label), SAL_B only | SHub/xtalk widget registers, the bridge objects in the PROM's pcfg | `0x55`/`0x57` errors **stop** (BUG); `0x56` v0 = 1 means "no such bus" |
| `0x0200004a` | IOIF_INTERRUPT (alloc, free, redirect) | `sn_intr_alloc` and friends | `0xffb1f970`, SAL_B only | SHub II interrupt routing, the bridge's interrupt registers | device without interrupt |
| `0x02000003` | PROBE | PCI-safe fallback | `0xffb23cb0`, `rt:0x1d570` | protected read | n/a |
| `0x0200001b` | GET_FIT_COMPT | `/proc/sgi_sn/prominfo` | `0xffb18d50` | flash window | n/a |
| `0x02000030`, `0x02000043`, `0x02000044` | SYSCTL_OP (board lookups), IROUTER_OP, SYSCTL_EVENT | `sn_ioboard_to_pci_bus`, hwperf, topology | `0xffb1d910`, `0xffb19720`, `0xffb1d710` | system-controller tables | degrades |
| `0x02000038`/`39`/`3a`/`3b` | SYS_SERIAL_GET, PARTITION_SERIAL_GET, SYSCTL_PARTITION_GET, SYSTEM_POWER_DOWN | `/proc`, old-PROM fallback, power-off | `0xffb1c6c0`, `0xffb1c7a0`, `0xffb1cdd0`, `0xffb1bf10` | block B strings, L1 | degrades |
| `0x02000012`/`06`, `0x02000060`, `0x02000061` | PRINT_ERROR, LOG_CE, HUB_ERROR_INTERRUPT, BTE_RECOVER | error paths | `0xffb13570`, `0xffb13070`, (IOIF dispatcher), `0xffb5fb50` | none | n/a |
| `0x02000050` | HWPERF_OP | `sn_hwperf_init` | runtime only, `rt:0x8650` | pcfg objects | degrades |

Callbacks that are not SAL ids (EFI only): `0x8000000000003000` (variable store, descriptor of `0x02000008`), `0x5000` (reset, descriptor of `0x02000002`: ops 1 warm, 2 cold or shutdown),
`0x6000` (EFI timer, `0xffb140a0`) and `0x7000` (interrupt state, `0xffb607f0`). **`0x6000` op 1 records EFI's handler and period in the per-CPU block and arms the processor interval timer on
vector `0xef`** (`0xffa9ef10`; op 3 is a second timer operation, other ops return -2). So EFI's countdowns and event timeouts need a working interval timer (`cr.itm`, `ar.itc`) and the
external interrupt path, not an SHub timer. This replaces the "inferred" delivery note in [efi.md](../firmware/snprom/efi.md#6-what-an-emulated-machine-must-provide-for-efi-to-reach-the-boot-manager-prompt) item 6 for the arming half; the handler-side path is still unread.

## 2. PAL

PAL is not part of the PROM's SAL: it is the PAL_A and PAL_B code of the same image run by the processor ([pal-msrs.md](../firmware/snprom/pal-msrs.md)); `PAL_PROC` is `0x01ff_f800` in the SAL
system table's entry-point descriptor ([os-handoff-tables.md](../firmware/snprom/os-handoff-tables.md#3-the-sal-system-table)). A model that runs the shipped PAL images answers all of this itself; one
that replaces PAL must answer these indexes (numbering from Linux `asm/pal.h`, which follows the Itanium architecture manual rev 2.2; the calls the PROM's own SAL_B makes are in
[boot-sequence.md](../firmware/snprom/boot-sequence.md)).

| Index | Procedure | Linux caller | Also called by SAL_B | If it fails |
|---|---|---|---|---|
| 8 | VM_SUMMARY | `cpu_init` (RID width) | no | degrades: "assuming 18 RID bits" |
| 19 | RSE_INFO | `setup.c` (physical stacked registers) | no | degrades: assumes 96 |
| 6, 34 | PTCE_INFO, VM_PAGE_SIZE | `ia64_tlb_init` (`mm/tlb.c`), hugetlb | no | degrades: the local TLB purge loop and TR page sizes are missing |
| 4, 2 | CACHE_SUMMARY, CACHE_INFO | cache size probing (`setup.c`, `topology.c`, `pci/pci.c`) | yes (`0xffb0eb7c`, `0xffaec15c`) | degrades |
| 14 | FREQ_RATIOS | `ia64_init_itm` (`time.c`) | yes (`0xffa9edbc`) | degrades (invents ratios) but the ITC rate then comes from `SAL_FREQ_BASE`; the two must agree |
| 13 | FREQ_BASE | `ia64_init_itm` | no | degrades |
| 17, 18 | PROC_GET/SET_FEATURES | `cpu_init` | yes | degrades |
| 15 | PERF_MON_INFO | perfmon | no | degrades |
| 42 | LOGICAL_TO_PHYSICAL | `setup_arch`, `identify_siblings` (`smpboot.c`) | yes | degrades: single thread, single core assumed |
| 27 | MC_REGISTER_MEM and the MCA calls (21 CLEAR_LOG, 22 DRAIN, 25 ERROR_INFO, 26 RESUME) | `ia64_mca_init` | yes (21, 22, 25, 26) | degrades |
| 29 | HALT_LIGHT | idle loop (`safe_halt`) | yes (`0xffa9acd0`) | the CPU spins instead of halting |
| 1, 3 | CACHE_FLUSH, CACHE_INIT | kexec, `SAL_CACHE_FLUSH` | yes | n/a |
| 20 | VERSION | `palinfo` | yes | n/a |

Every virtual-mode PAL call also needs the `PAL_CODE` translation register: `efi_map_pal_code` maps the first type 13 (`EfiPalCode`) descriptor (a second one is ignored, over 16 MiB panics) and the
SAL system table's type 3 entry; with no descriptor the kernel prints a warning and the first virtual PAL call faults ([sn2-early-boot.md](../linux/sn2-early-boot.md#efi-what-efi_init-and-the-memory-map-need)).

## 3. EFI runtime services

The kernel keeps `efi.get_time`, `set_time`, `get_wakeup_time`, `set_wakeup_time`, `get_variable`, `get_next_variable`, `set_variable`, `get_next_high_mono_count` and `reset_system` pointing at
physical-mode wrappers until `efi_enter_virtual_mode` calls `SetVirtualAddressMap` (the arguments are the boot-parameter block's map size, descriptor size, version and map pointer), then
switches to the virtual wrappers (`efi.c`, established). The PROM's implementations (addresses are Ghidra-export EFI addresses; the table `RuntimeServices` is at `0x1fe2e0`, the system table at
`0x1fe268`):

| Service | Kernel use | PROM implementation | Platform hardware | If it fails |
|---|---|---|---|---|
| `SetVirtualAddressMap` | once, in `efi_enter_virtual_mode` | `RtPlSetVirtualAddressMap` `0x121800` (and `0x12d0e0`); calls SAL `0x02000013` | none | degrades (prints "unable to switch EFI into virtual mode"; physical wrappers stay) |
| `GetTime` | once at boot for the wall clock | `RtSNGetTime`: SAL `0x0200000b` (seven u16 fields; returns success whatever SAL returned; accuracy 50 ppm) | SHub RTC `0x81_101c_0000` plus the chip base-time method; if that fails the base is 1998-01-01 | degrades (clock at the base) |
| `SetTime` | `hwclock`, ntp | SAL `0x0200000a` | same | degrades |
| `GetVariable`, `GetNextVariableName`, `SetVariable` | `efivars`, elilo (`EDD30`) | sample variable engine (`RtVarFind`, `RtSetVariable`, `RtVarGarbageCollect`) over the callback `0x3000` | node flash (64 KiB store) | degrades |
| `GetWakeupTime`, `SetWakeupTime` | RTC alarm | stubs returning `EFI_UNSUPPORTED` (`0x8000000000000003`) | none | degrades |
| `GetNextHighMonotonicCount` | none | real | none | n/a |
| `ResetSystem` | `machine_restart`, `machine_halt` | `RtPlResetSystem` `0x122950`: cold and shutdown send callback `0x5000` op 2, warm op 1; other types `EFI_UNSUPPORTED` | L1 reset request | degrades (no reboot) |
| `ConvertPointer` | internal | loops forever on an address outside every known range | none | hang if a runtime descriptor was not mapped |

**Time source summary.** Wall clock: SHub RTC counter (`0x81_101c_0000`) and the chip's base time (probably the system controller's clock, **inferred**; the method was not read). Kernel
timekeeping after boot: the processor ITC/ITM for the tick (period from `SAL_FREQ_BASE` type 0 and `PAL_FREQ_RATIOS`) and the SHub RTC as the SN clock source (section 5.6).

## 4. Calls that stop a Linux boot if they fail

1. Entry-point descriptor in the SAL system table (type 0 first, at `+0x60`) and an EFI system table with the `IBI SYST` signature and a readable (or null) vendor string ([os-handoff-tables.md](../firmware/snprom/os-handoff-tables.md)).
2. `GET_SN_INFO` with a status below -1 (BUG), `GET_KLCONFIG_ADDR` with a null result or bad board list, `GET_SAPIC_INFO` with a status below -1.
3. The I/O discovery calls (`0x55`, `0x57`) with an error; `0x56` must put 1 in r9 for a missing bus.
4. `SAL_PCI_CONFIG_READ` that does not return all-ones for a missing device (the generic scan sees a phantom device) or never returns data.
5. The ACPI 2.0 tables: an SRAT with a processor entry, a MADT ([sn2-early-boot.md](../linux/sn2-early-boot.md#where-a-model-that-implements-only-what-chips-documents-today-fails)).
6. The SHub registers in section 5.2 below: a frozen RTC or a wrong `PIO_WRITE_STATUS` value hangs the kernel.

Everything else listed above degrades. Console output is not needed to boot, but it is the only way to see a failure.

## 5. What an SN2 kernel needs

The order is the boot CPU's order. "Kernel expects" is what the kernel source tests or assumes; the stop column says whether a wrong answer ends the boot.

### 5.1 Before there is a console

- **EFI and SAL tables (`early_sn_setup`, `arch/ia64/sn/kernel/setup.c`).** It walks `ia64_boot_param->efi_systab`'s configuration table for `SAL_SYSTEM_TABLE_GUID`, takes
  the SAL table pointer, walks the entries for the type 0 (entry point) descriptor and installs `sal_proc` and `gp` as the SAL entry. Nothing else is read first. No descriptor prints
  "failed to find SAL entry point" and every SAL call (including the console) is dead. **Stops** console output; the boot continues blind and then fails at the first fatal SAL call. Established (read).
- **Early console.** `sn_serial_console_early_setup` registers the "sn_sal" boot console whose writes are `ia64_sn_console_putb` (`0x02000028`) calls (buffered by the PROM). Established (read).

### 5.2 `sn_setup`: direct register accesses

| Where | Register or call | Kernel expects | Stop? |
|---|---|---|---|
| `sn_setup` (first line) `sn2_rtc_initial = rtc_time()` | SHub RTC counter at `LOCAL_MMR_ADDR(SH_RTC)` (`0x1_101c_0000` SHub 1 in the local window) | readable | a bus error here **stops** |
| `sn_check_for_wars` / `is_shub_1_1` | SHub ID register `SH1_SHUB_ID` (`0x1_1006_0580` family), read once per node | revision field readable; revision <= 2 only sets a workaround flag | stops only on a bus error |
| `sn_cpu_init` | `pda->pio_write_status_addr` = `SH_PIO_WRITE_STATUS_0/1` (slice select), `pio_write_status_val` = **`SH_PIO_WRITE_STATUS_PENDING_WRITE_COUNT_MASK` on SHub 1, 0 on SHub 2** | `mmiowb()` and `sn_migrate` spin until `(*addr & PENDING_WRITE_COUNT_MASK) == val`: on SHub 1 the idle register must read with the count field **all ones** | a wrong idle value **hangs** at the first `mmiowb` |
| `sn_cpu_init` | `pi_cam_control` workaround address, `junk_bus_led` addresses (LED writes from the idle/timer code), `ipi_int` | stored only; written later | LED and IPI writes need accepting stores |
| `GET_SN_INFO`, `SET_CPU_NUMBER`, `GET_PROM_FEATURE_SET`, `GET_SAPIC_INFO` | SAL (section 1) | see table | see table |
| `sn_setup` | `acpi_table_init`, SRAT/MADT/SLIT/FADT from [os-handoff-tables.md](../firmware/snprom/os-handoff-tables.md) | NASID-addressed memory ranges (`nasid << 38`) | **stops** (NASID -1 BUG) |
| `sn_setup` | `sn_scan_pcdp` (HCDP table revision 3 or later) | optional; no VGA device disables the VGA console | degrades |
| `sn_setup` | `SAL_FREQ_BASE` type 2 | at least 100 kHz | degrades (33.3 MHz) |

### 5.3 PCI discovery

Order (established from `io_init.c` and the earlier pages): `sn_fixup_ionodes` calls `GET_HUBDEV_INFO` (`0x55`) per node and the flush-list calls (`0x58`); `sn_io_init` then loops over
`segment <= max_segment_number` and `bus <= max_pcibus_number` from that structure and `sn_pci_controller_fixup` calls `GET_PCIBUS_INFO` (`0x56`): a **positive status means the bus does not exist** and
is skipped; otherwise a `pcibus_bussoft` (asic type, xtalk widget id, persistent segment and bus numbers, `bs_base`, legacy I/O and memory) is returned by physical address. It then
scans the bus with `pci_scan_bus(busnum, &pci_root_ops, controller)`, whose config access is **SAL `0x01000010`/`0x01000011`** (not a memory-mapped config window). `sn_bus_fixup` runs per root bus and
`sn_io_slot_fixup` per device: `GET_PCIDEV_INFO` (`0x57`) returns a `pcidev_info` with up to six BAR PIO addresses and the ROM; the kernel rewrites `dev->resource[]` from them as
uncached addresses (`(addr << 4 >> 4) | __IA64_UNCACHED_OFFSET`) and, for the ROM resource, **ioremaps the ROM and reads its header** (`pci_get_rom_size`), so the ROM BAR address must be backed. Then
`pcibr_bus_fixup` (`pcibr_provider.c`) ioremaps the bridge (`bs_base`, `sizeof(struct pic)`), registers the error interrupt (`SGI_PCIASIC_ERROR`, the PROM's `IOIF_ERROR_INTERRUPT` call is made from
the handler), writes the PIC control register's page-size bit, and sets up the PMU ATE map (`pbi_int_ate_size` from the PROM's structure). DMA mapping later programs the PIC's ATEs. The structure
layouts are in [sn2-runtime.md](sn2-runtime.md#the-structures-behind-0x55-to-0x58) and [README.md](README.md#structures-the-prom-fills). Failure: `0x55` or `0x57` errors BUG; a missing bus is skipped; with no
PIC model the PROM structures can still be fabricated, but any bridge register write after `ioremap` needs a backing device. The kernel's direct-path I/O, not the ACPI `IOIF_INIT` path, is what the held 2.6.5 uses; the 2.6.3x tree also has `io_acpi_init.c` (ACPI `SGIHUB` DSDT) and picks it from the DSDT's OEM revision.

### 5.4 Interrupts

- **Allocation (SAL).** `sn_intr_alloc` calls `IOIF_INTERRUPT` (`0x0200004a`) with `SAL_INTR_ALLOC` and the physical address of a `sn_irq_info`, the widget and the requested NASID/slice; the PROM fills
  `irq_irq` (the IA-64 vector), `irq_nasid`, `irq_slice`, `irq_xtalkaddr` (the SHub address the bridge writes to raise the interrupt), `irq_int_bit` (bridge pin, negative for MSI), `irq_bridge_type`, `irq_bridge`, flags. A non-zero status leaves the device without an interrupt (degrades). `SAL_INTR_FREE` and `SAL_INTR_REDIRECT` are used by `sn_set_affinity_irq`; `REDIRECT` failure falls back to free plus alloc.
- **Delivery (hardware).** The PIC turns a pin change into a write of the programmed `irq_xtalkaddr` (`pcibr_target_interrupt` sets the INT_ADDR register of that bit and enables the bit), which the SHub II presents as an external interrupt of that vector to the target CPU: the "interrupt as write" path, established from the kernel side; the SH_II_INT register contract is in [devices/shub](../../devices/shub/interrupts.md).
- **Acknowledge (`sn_ack_irq`).** Reads `SH_EVENT_OCCURRED` at `LOCAL_MMR_ADDR`, masks it with `SH_ALL_INT_MASK` and **writes the mask to `SH_EVENT_OCCURRED_ALIAS`** (write-one-to-clear); `sn_end_irq` re-reads it for `SGI_UART_VECTOR` (an UART bit still set re-sends an IPI to self) and, because `sn_force_interrupt_flag` defaults to 1, calls the bus provider's `force_interrupt`: for a PIC device that sets the bridge's force-interrupt bit (`pcireg_force_intr_set`, a PIC register write) after every device interrupt. A missing `EVENT_OCCURRED` or alias, or a PIC without the force register, makes the first interrupt hang or fault. **Stops** at the first interrupt. Established (read).
- **IPIs.** `sn2_send_IPI` writes the SHub `SH_IPI_INT` register of the target node (first write when a second CPU starts or an IPI is sent; the address is in [sn2-early-boot.md](../linux/sn2-early-boot.md#shub-registers-touched-first); the send routine itself was not re-read this round, **inferred** from that page); needed only with a second CPU.
- **TLB purges (SMP only).** `sn2_global_tlb_purge` writes `SH1_PTC_0` and `SH1_PTC_1` of each node in `mm_cpumask` (PIO, `pio_atomic_phys_write_mmrs`) after taking a global lock, then polls `PIO_WRITE_STATUS` for completion; the deadlock bit (`WRITE_DEADLOCK`) makes it call the physical-mode recovery routine in `ptc_deadlock.S`, which clears the status bits by writing 7 to the alias at `+8` (SHub 1) and rewrites the PTC pair with translation off. Single-CPU boot with one active mm (`mm_users == 1` or the local-only case) uses `ptc.l` and never reaches the SHub. An SMP model must make the PTC writes purge every TLB and let `PIO_WRITE_STATUS` read idle (all-ones count on SHub 1).

### 5.5 Console

The serial console is **SAL, not a UART the kernel drives**: early output is `CONSOLE_PUTB`; after `console_initcall`, `sn_sal_switch_to_asynch` buffers output and sends it through SAL (PUTB, and XMIT_CHARS `0x0200002a` in the held 2.6.5 kernel's call list) from a timer or from the UART interrupt; input is `CONSOLE_GETC`
(`0x02000022`) and `CONSOLE_POLL` (`0x02000026`, the status in the first return word and the pending flag in the second), and `CONSOLE_INTR` (`0x02000027`) enables the receive interrupt, which arrives on
`SGI_UART_VECTOR` from the SHub's UART event bit in `SH_EVENT_OCCURRED`. The PROM answers from its system-controller objects over the junk-bus UART ([sn2-runtime.md](sn2-runtime.md#console-0x02000021-to-0x0200002c)); **no IOC4 serial is involved** in the console (the IOC4 UARTs are separate PCI devices for a different driver). A model can answer PUTB/GETC/POLL itself; interrupts are optional because the driver falls back to its polling ops when the interrupt is not enabled. Stops: console only.

### 5.6 Timers

- **Tick:** the processor's ITM/ITC (vector from the CPU), rate from `SAL_FREQ_BASE` type 0 (200 MHz) and `PAL_FREQ_RATIOS` (section 2).
- **Clock source `sn2_rtc`** (`timer.c`): `readq(RTC_COUNTER_ADDR)` of the SHub RTC, 55-bit mask, rating 450 (preferred over the ITC), `mult` from `SAL_FREQ_BASE` type 2 (20 MHz). It must be monotonic, readable at any time from any CPU and run at that rate; a frozen counter freezes time and hangs `udelay`. `ia64_sn_udelay` busy-waits on the same counter, so every driver delay depends on it. **Stops** if it does not advance.
- **Wall clock:** EFI `GetTime` once (section 3).
- **Heartbeat LEDs:** 16-bit writes to the junk-bus LED address from the timer and idle paths; accept and ignore the stores.

### 5.7 What these sections do not settle

- The PIC register contract after `ioremap` (control, ATE, interrupt enable/address, force-interrupt) and the DMA address translation the PROM sets up: [devices/pic](../../devices/pic/README.md) and the open questions in [questions/sn2-sal-open.md](../../questions/sn2-sal-open.md).
- The runtime-side handlers of `0x01000006`, `0x01000009`, `0x01000020` and the physical-id r9, and the SAL_B side of `0x02000013` beyond case 0.
- A second source for the 2.6.3x-era SAL list: a Linux tree from a third-party SN2 fork was not read this round.
