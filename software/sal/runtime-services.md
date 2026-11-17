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
| `0x02000068` | SET_CPU_NUMBER | `sn_cpu_init` (v5.3, the linux-history tree and linux-sn2 7.3; result ignored) | `0xffb13a70`, `rt:0x47d0` | per-CPU record at `0x1000000` | ignored |
| `0x0200001a` | SET_ERROR_HANDLING_FEATURES | `sn_setup` | `0xffb13890`, `rt:0x45f0` | none | ignored |
| `0x02000066` | SET_OS_FEATURE_SET | `sn_setup`: 2.6.3x calls 0, 1, then `PCISEGMENT_ENABLE`, `ACPI_ENABLE` before `acpi_table_init`; the held 2.6.5 calls 0 and 1 only | `0xffb5fc90` | block B `+0xc8` flag word | ignored; features 2 and 3 make the PROM rebuild the DSDT |
| `0x02000005` | GET_KLCONFIG_ADDR | `sn_setup` per node | `0xffb19c20` | KLCONFIG in block A (64 KiB into the hwcfg block) | 0 or a bad board list **stops** (BUG) |
| `0x02000065` | GET_PROM_FEATURE_SET | `sn_cpu_init` pass 2 | `0xffb60170` | none | read until the first non-zero status; set 1 answers -2 |
| `0x0200001d` | GET_SAPIC_INFO | `sn_cpu_init`, IPI sends | `0xffb196c0`, `rt:0x85f0` | arithmetic only | -1 selects a fixed decode; < -1 **stops** |
| `0x02000004` | GET_MASTER_NASID | `sn_hwperf_init` | `0xffb60a40`, `rt:0x35d0` | block B `+0x100` | degrades |
| `0x02000021` to `0x0200002c` | console PUTC, GETC, PUTS, GETS, GETS_TIMEOUT, POLL, INTR, PUTB, (`29` read bytes), XMIT_CHARS, READC, (`2c` flush) | `sn_console.c`, EFI, early printk | `0xffb16d50` (`21`) through `0xffb178a0` (`2c`): `22` `0xffb16e30`, `23` `0xffb16f40`, `28` `0xffb170a0`, `24` `0xffb17190`, `25` `0xffb17270`, `29` `0xffb17360`, `26` `0xffb17480`, `2a` `0xffb17560`, `2b` `0xffb17650`, `27` `0xffb17760`; rt rows from `rt:0x78b0` | the system-controller (L1) UART on the SHub junk bus; no IOC4 | no console only |
| `0x0200002d` | console callback register | EFI only | `0xffb179b0` (SAL_B only; stores the pointer, returns 0) | none | n/a |
| `0x02000008` | flash and variable store (EFI only) | `PlInitNvVarStoreFlash`, EFI variable services | `0xffb182c0` | node flash | EFI starts with no variables; Linux unaffected ([efi-boot.md](../firmware/snprom/efi-boot.md#1-boot-options-and-the-variables)) |
| `0x0200000a`/`0b` | clock set / get | EFI `SetTime`/`GetTime` | `0xffb14200`, `0xffb14300`, via `0xffa1d1e0`/`0xffa1cef0` | SHub RTC `0x81_101c_0000` plus a base time from a time-of-day chip or L1 request `0x200e` (section 6; 1998-01-01 if both fail) | `GetTime` always returns success to the kernel |
| `0x02000013` | go virtual (EFI `SetVirtualAddressMap`) | EFI only | `0xffb14450` (case 0 walks the node table and rewrites the node-record pointers at `0x1000038` and block A `+0x50`/`+0xa0`; read as a pointer re-base, **inferred**) | none | the kernel tolerates a failed `SetVirtualAddressMap` |
| `0x02000002` | SYSTEM_RESET (and callback `0x5000`) | EFI `ResetSystem`, `machine_restart` paths | `0xffb1ba90` | INIT IPIs, then L1 text command `* rst` (section 6) | n/a |
| `0x02000045` | start I/O (EFI only) | EFI start-up | `0xffb20350` | pool buffer for I/O | ignored |
| `0x02000051` to `0x0200005f`, `0x64` | IOIF: error interrupt, `PCI_SAFE`, slot enable/disable, `GET_HUBDEV_INFO` (`55`), `GET_PCIBUS_INFO` (`56`), `GET_PCIDEV_INFO` (`57`), flush lists (`58`, `5a`), `IOIF_INIT` (`5f`), PCI topology (`64`) | I/O discovery (section 5) | one dispatcher, `0xffb1e660` (the `0x...5e` case is the exported label), SAL_B only | SHub/xtalk widget registers, the bridge objects in the PROM's pcfg | `0x57` errors **stop** (`BUG_ON`); a `0x55` error only skips that node's set-up (`continue`, in both trees read); `0x56` with a positive status means "no such bus" |
| `0x0200004a` | IOIF_INTERRUPT (alloc, free, redirect) | `sn_intr_alloc` and friends | `0xffb1f970`, SAL_B only | SHub II interrupt routing, the bridge's interrupt registers | device without interrupt |
| `0x02000003` | PROBE | PCI-safe fallback | `0xffb23cb0`, `rt:0x1d570` | protected read | n/a |
| `0x0200001b` | GET_FIT_COMPT | `/proc/sgi_sn/prominfo` | `0xffb18d50` | flash window | n/a |
| `0x02000030` | SYSCTL_OP (board lookups) | `sn_ioboard_to_pci_bus`, hwperf, topology | `0xffb1d910`, `rt:0xe490` | system-controller tables | degrades |
| `0x02000043` | IROUTER_OP (open, close, send, receive, interrupt status, on, off, init) | `scdrv_init` and the `/dev/snsc` driver | `0xffb19720`, `rt:0xaff0` | UART interrupt enable (`IER` bit 0); `OPEN` and `SEND` use the request slots and L1 frames | init and interrupt on send no frame; a missing driver or PROM only loses `/dev/snsc` |
| `0x02000044` | SYSCTL_EVENT: L1 request `0x1007` naming subchannel 19 as the event channel | `scdrv_event_init` (snsc_event.c), console nasid only | `0xffb1d710`, `rt:0xe290` -> `sysctl_event_init` `rt:0x4cb80` | one L1 request, frame in [the 0x1007 section](../firmware/snprom/l1-requests.md#request-0x1007-and-the-kernel-console) | status 0 reply returns r9 = 19; an error status returns it in r9 and the driver gives up on events; **no reply at all (3,000,000 ticks) takes the node-die path (`ERR 8d`) and stops the machine** |
| `0x02000038`/`39`/`3a`/`3b` | SYS_SERIAL_GET, PARTITION_SERIAL_GET, SYSCTL_PARTITION_GET, SYSTEM_POWER_DOWN | `/proc`, old-PROM fallback, power-off | `0xffb1c6c0`, `0xffb1c7a0`, `0xffb1cdd0`, `0xffb1bf10` | block B strings, L1; `0x3b` does nothing unless the module type is `l` (section 6) | degrades |
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
| `GetTime` | once at boot for the wall clock | `RtSNGetTime` (EFI `0x1093c0`): SAL `0x0200000b` (seven u16 fields, the last in milliseconds; returns success whatever SAL returned; accuracy 50 ppm) | SHub RTC `0x81_101c_0000` plus a base time from a chip or L1 request `0x200e` (section 6); if that fails the base is 1998-01-01 | degrades (clock at the base) |
| `SetTime` | `hwclock`, ntp | SAL `0x0200000a` | same | degrades |
| `GetVariable`, `GetNextVariableName`, `SetVariable` | `efivars`, elilo (`EDD30`) | sample variable engine (`RtVarFind`, `RtSetVariable`, `RtVarGarbageCollect`) over the callback `0x3000` | node flash (64 KiB store) | degrades |
| `GetWakeupTime`, `SetWakeupTime` | RTC alarm | stubs returning `EFI_UNSUPPORTED` (`0x8000000000000003`) | none | degrades |
| `GetNextHighMonotonicCount` | none | real | none | n/a |
| `ResetSystem` | `machine_restart` (warm) | `RtPlResetSystem` `0x122950`: types 0, 1 and 2 all call callback `0x5000`; other types `EFI_UNSUPPORTED` | L1 text command `* rst` (section 6); shutdown resets too | degrades (no reboot) |
| `ConvertPointer` | internal | loops forever on an address outside every known range | none | hang if a runtime descriptor was not mapped |

**Time source summary.** Wall clock: SHub RTC counter (`0x81_101c_0000`) and the chip's base time (probably the system controller's clock, **inferred**; the method was not read). Kernel
timekeeping after boot: the processor ITC/ITM for the tick (period from `SAL_FREQ_BASE` type 0 and `PAL_FREQ_RATIOS`) and the SHub RTC as the SN clock source (section 5.6).

## 4. Calls that stop a Linux boot if they fail

1. Entry-point descriptor in the SAL system table (type 0 first, at `+0x60`) and an EFI system table with the `IBI SYST` signature and a readable (or null) vendor string ([os-handoff-tables.md](../firmware/snprom/os-handoff-tables.md)).
2. `GET_SN_INFO` with a status below -1 (BUG), `GET_KLCONFIG_ADDR` with a null result or bad board list, `GET_SAPIC_INFO` with a status below -1.
3. `GET_PCIDEV_INFO` (`0x57`) with an error (`BUG_ON`); a `0x55` error skips the node and leaves it half set up; a missing bus is a positive `0x56` status in linux-sn2 (the page earlier said r9 = 1; linux-sn2 tests the returned status; linux-history was not read for this call).
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

Order (established from `io_init.c` and the earlier pages): `sn_fixup_ionodes` calls `GET_HUBDEV_INFO` (`0x55`) per node, and `sn_common_hubdev_init` the device flush-list call (`0x5a`; `0x58` only for a PROM older than 4.50); `sn_io_init` then loops over
`segment <= max_segment_number` and `bus <= max_pcibus_number` from that structure and `sn_pci_controller_fixup` calls `GET_PCIBUS_INFO` (`0x56`): a **positive status means the bus does not exist** (linux-sn2 7.3 scans with `pci_scan_root_bus`, 2.6.3x with `pci_scan_bus`; the SAL config calls are the same) and
is skipped; otherwise a `pcibus_bussoft` (asic type, xtalk widget id, persistent segment and bus numbers, `bs_base`, legacy I/O and memory) is returned by physical address. It then
scans the bus with `pci_scan_bus(busnum, &pci_root_ops, controller)`, whose config access is **SAL `0x01000010`/`0x01000011`** (not a memory-mapped config window). `sn_bus_fixup` runs per root bus and
`sn_io_slot_fixup` per device: `GET_PCIDEV_INFO` (`0x57`) returns a `pcidev_info` with up to six BAR PIO addresses and the ROM; the kernel rewrites `dev->resource[]` from them as
uncached addresses (`(addr << 4 >> 4) | __IA64_UNCACHED_OFFSET`) and, for the ROM resource, 2.6.3x **ioremaps the ROM and reads its header** (`pci_get_rom_size`), so the ROM BAR address must be backed. In linux-sn2 7.3 the same code instead marks the ROM `IORESOURCE_ROM_SHADOW` and calls `pci_disable_rom`; nothing maps it at fixup, only a later ROM read (sysfs, VGA) does. Then
`pcibr_bus_fixup` (`pcibr_provider.c`) ioremaps the bridge (`bs_base`, `sizeof(struct pic)`), registers the error interrupt (`SGI_PCIASIC_ERROR`, the PROM's `IOIF_ERROR_INTERRUPT` call is made from
the handler), writes the PIC control register's page-size bit, and sets up the PMU ATE map (`pbi_int_ate_size` from the PROM's structure). DMA mapping later programs the PIC's ATEs. The structure
layouts are in [sn2-runtime.md](sn2-runtime.md#the-structures-behind-0x55-to-0x58) and [README.md](README.md#structures-the-prom-fills). Failure: `0x55` or `0x57` errors BUG; a missing bus is skipped; with no
PIC model the PROM structures can still be fabricated, but any bridge register write after `ioremap` needs a backing device. The kernel's direct-path I/O, not the ACPI `IOIF_INIT` path, is what the held 2.6.5 uses; the 2.6.3x tree also has `io_acpi_init.c` (ACPI `SGIHUB` DSDT) and picks it from the DSDT's OEM revision.

### 5.4 Interrupts

- **Allocation (SAL).** `sn_intr_alloc` calls `IOIF_INTERRUPT` (`0x0200004a`) with `SAL_INTR_ALLOC` and the physical address of a `sn_irq_info`, the widget and the requested NASID/slice; the PROM fills
  `irq_irq` (the IA-64 vector), `irq_nasid`, `irq_slice`, `irq_xtalkaddr` (the SHub address the bridge writes to raise the interrupt), `irq_int_bit` (bridge pin, negative for MSI), `irq_bridge_type`, `irq_bridge`, flags. A non-zero status leaves the device without an interrupt (degrades). `SAL_INTR_FREE` and `SAL_INTR_REDIRECT` are used by `sn_set_affinity_irq`; `REDIRECT` failure falls back to free plus alloc.
- **Delivery (hardware).** The PIC turns a pin change into a write of the programmed `irq_xtalkaddr` (`pcibr_target_interrupt` sets the INT_ADDR register of that bit and enables the bit), which the SHub II presents as an external interrupt of that vector to the target CPU: the "interrupt as write" path, established from the kernel side; the SH_II_INT register contract is in [devices/shub](../../devices/shub/interrupts.md).
- **Acknowledge (`sn_ack_irq`).** Reads `SH_EVENT_OCCURRED` at `LOCAL_MMR_ADDR`, masks it with `SH_ALL_INT_MASK` and **writes the mask to `SH_EVENT_OCCURRED_ALIAS`** (write-one-to-clear); `sn_end_irq` re-reads it for `SGI_UART_VECTOR` (an UART bit still set re-sends an IPI to self) and, because `sn_force_interrupt_flag` defaults to 1 (linux-sn2 7.3 dropped the flag and forces unless the irq is disabled), calls the bus provider's `force_interrupt`: for a PIC device that sets the bridge's force-interrupt bit (`pcireg_force_intr_set`, a PIC register write) after every device interrupt. A missing `EVENT_OCCURRED` or alias, or a PIC without the force register, makes the first interrupt hang or fault. **Stops** at the first interrupt. Established (read).
- **IPIs.** `sn2_send_IPI` writes the SHub `SH_IPI_INT` register of the target node (first write when a second CPU starts or an IPI is sent; the address is in [sn2-early-boot.md](../linux/sn2-early-boot.md#shub-registers-touched-first); the send routine itself was not re-read this round, **inferred** from that page); needed only with a second CPU.
- **TLB purges (SMP only).** `sn2_global_tlb_purge` writes `SH1_PTC_0` and `SH1_PTC_1` of each node in `mm_cpumask` (PIO, `pio_atomic_phys_write_mmrs`) after taking a global lock, then polls `PIO_WRITE_STATUS` for completion; the deadlock bit (`WRITE_DEADLOCK`) makes it call the physical-mode recovery routine in `ptc_deadlock.S`, which clears the status bits by writing 7 to the alias at `+8` (SHub 1) and rewrites the PTC pair with translation off. Single-CPU boot with one active mm (`mm_users == 1` or the local-only case) uses `ptc.l` and never reaches the SHub. An SMP model must make the PTC writes purge every TLB and let `PIO_WRITE_STATUS` read idle (all-ones count on SHub 1).

### 5.5 Console

The serial console is **SAL, not a UART the kernel drives**: early output is `CONSOLE_PUTB`; after `console_initcall`, `sn_sal_switch_to_asynch` buffers output and sends it through SAL (PUTB, and XMIT_CHARS `0x0200002a` in the held 2.6.5 kernel's call list) from a timer or from the UART interrupt; input is `CONSOLE_GETC`
(`0x02000022`) and `CONSOLE_POLL` (`0x02000026`, the status in the first return word and the pending flag in the second), and `CONSOLE_INTR` (`0x02000027`) enables the receive interrupt, which arrives on
`SGI_UART_VECTOR` from the SHub's UART event bit in `SH_EVENT_OCCURRED`. The PROM answers from its system-controller objects over the junk-bus UART ([sn2-runtime.md](sn2-runtime.md#console-0x02000021-to-0x0200002c)); **no IOC4 serial is involved** in the console (the IOC4 UARTs are separate PCI devices for a different driver). A model can answer PUTB/GETC/POLL itself; interrupts are optional because the driver falls back to its polling ops when the interrupt is not enabled. The runtime-side call table, the exact `INTR` semantics, the UART registers the PROM touches and the 16550 interrupt identification values the transmit and receive paths need are in [the console section of the L1 request page](../firmware/snprom/l1-requests.md#how-input-and-output-travel). Note the interrupt-mode output path (`XMIT_CHARS`) only drains from the UART transmit interrupt, so a model that enables the receive interrupt without modelling the transmit one stalls output once the kernel switches to interrupts. Stops: console only.

### 5.6 Timers

- **Tick:** the processor's ITM/ITC (vector from the CPU), rate from `SAL_FREQ_BASE` type 0 (200 MHz) and `PAL_FREQ_RATIOS` (section 2).
- **Clock source `sn2_rtc`** (`timer.c`): `readq(RTC_COUNTER_ADDR)` of the SHub RTC, 55-bit mask, rating 450 (preferred over the ITC), `mult` from `SAL_FREQ_BASE` type 2 (20 MHz). It must be monotonic, readable at any time from any CPU and run at that rate; a frozen counter freezes time and hangs `udelay`. `ia64_sn_udelay` busy-waits on the same counter, so every driver delay depends on it. **Stops** if it does not advance.
- **Wall clock:** EFI `GetTime` once (section 3).
- **Heartbeat LEDs:** 16-bit writes to the junk-bus LED address from the timer and idle paths; accept and ignore the stores.

### 5.7 What these sections do not settle

- The PIC register contract after `ioremap` (control, ATE, interrupt enable/address, force-interrupt) and the DMA address translation the PROM sets up: [devices/pic](../../devices/pic/README.md) and the open questions in [questions/sn2-sal-open.md](../../questions/sn2-sal-open.md).
- The runtime-side handlers of `0x01000006`, `0x01000009`, `0x01000020` and the physical-id r9, and the SAL_B side of `0x02000013` beyond case 0.

## 6. Power-down, reset and the time of day

Read in Ghidra on `shub1snprom.bin` 10.54 (SAL_B, no analysis for the EFI ELF) with `ia64-linux-gnu-objdump` for the constants the decompiler hid; Linux from the community tree `nsafran1217/linux-sn2` (mirror head `69571599c5`) and `linux-history`. No emulator ran. Request frames, the reply parser and the identity cache are in [l1-requests.md](../firmware/snprom/l1-requests.md); the L1 side is in sysco `software/firmware/l1/sn2-power-time-requests-1.62.1.md`.

### 6.1 What the kernel calls

| Action | Kernel path (established) | Firmware call |
|---|---|---|
| `poweroff` | `machine_power_off` runs the legacy `pm_power_off`, which `sn_setup` set to `ia64_sn_power_down` (`arch/ia64/sn/kernel/setup.c:529`, `sn_sal.h:751`); that issues SAL `0x0200003b` with no arguments and then spins forever | SAL `SYSTEM_POWER_DOWN`; no EFI call (the EFI power-off handler is registered only where `efi_poweroff_required()` is true, which the default is not) |
| `reboot` | `machine_restart` calls `efi_reboot(REBOOT_WARM)`, which calls `efi.reset_system(EFI_RESET_WARM)` | EFI `ResetSystem` |
| `halt` | `machine_halt` calls `cpu_halt` (`arch/ia64/kernel/process.c:572`): `PAL_HALT_INFO`, then `PAL_HALT` | PAL only; no SAL, EFI or L1 traffic |
| clock at boot | `timekeeping_init` -> `read_persistent_clock64` -> `efi_gettimeofday` (`efi.c:254`): one `efi.get_time` call; an error gives 0 | EFI `GetTime` |
| clock afterwards | clocksource `sn2_rtc`, the SHub RTC at `0x1_101c_0000` (55 bits, rating 450); `hwclock` through `rtc-efi` calls `efi.get_time`/`set_time` | the SHub RTC counts from boot only |

### 6.2 SAL `SYSTEM_POWER_DOWN` (`0x0200003b`, `0xffb1bf10`)

- **Gate (established).** The handler counts the node list (node block `+0x10`) and returns 0 at once when two or more nodes are present. It then reads the identity cache (the `0x0003` reply, module word and type letter, folded to lowercase) and returns status 0 **unless the type is `l` (0x6c, `cmp4.eq` at `0xffb1c276`)**; if the identity read fails it returns -3 instead (the kernel ignores the status). For the Altix 350's `f` (Opus TIO, inferred) or `o` (ColdFire Opus) the call sends no L1 frame, writes no register and returns 0, so Linux spins with the machine on. `l` is the ColdFire parser's `dorado` letter (sysco `personalities.md`).
- **Type `l` path (established, not reachable on a 350).** L1 request `0x100a` with no arguments (`0xffa7efe0`; destination `0x0ffff006`, see l1-requests.md), then for each node the flag write below, an INIT IPI to every other CPU, then `0xffa0d610`: with an L2 present, text `p <partition> pwr d` to the L2; without one and with a partition number, a warning "system is partitioned but L2 is unreachable" and a spin; otherwise text `* pwr d` to the L1; then it spins.
- **What real hardware does (unknown).** No capture of an Altix 350 shutting down is held. The kernel's `pm_power_off` is the only power-off call, and the PROM does nothing for the 350's type letters, so a real 350 either stays powered at "Power down." or this PROM build is not the one that powers off (inferred, not established).

### 6.3 SAL `SYSTEM_RESET` (`0x02000002`, `0xffb1ba90`; also EFI callback `0x5000`)

EFI `RtPlResetSystem` (EFI export address `0x122950`) accepts types 0, 1 and 2 and calls `RtSalCallBack`; the SAL handler stores its arguments and never branches on them, so cold, warm and shutdown behave the same (established from the code read).

1. For each node: set bit 59 in the node's state word `0x1_5003_1550` (the code forms `node << 38 | 0x8_0000_0000 | offset`, so the same register is `0x9_5003_1550` in a node window, as `ipi_int` below) through the node window (`0xffa0e880`, bracketed by a lock pair at `0x1_101d_0200`/`0x1_101d_0208`; the lock reading is inferred).
2. For each other CPU in the CPU list: write `0x8000_0000_0000_0005 | (cpu id << 4)` to `0x9_1000_0380` of that CPU's node, the `ipi_int` register with type 5 (INIT) and the send bit (established; [shub registers](../../devices/shub/registers.md)).
3. Master node, `0xffa0d3d0` (established): partition number by request `0x0009` (cached); a text probe `version` (task 3, destination word `0x1ffff003`) decides whether an L2 exists: the probe is true only when the reply status is exactly 0, and a nonzero status, a failed send or a timeout all count as no L2. A silent probe waits 20,000,000 us, runs the `0x8d` die routine (`0xffad2cb0`: error code to the diagnostic registers, clears bits 26 to 29 of the state word, sets a bit in `0x1_101d_0080`, waits 300 ms) which **returns**, and the reset goes on down the L1 path. The ColdFire `O` L1 does not answer the probe with status 0: it does not deliver `0x1ffff003` to its task 3 (the router compares the destination shifted right 12 against its own id and `0xffff`, and `0x1ffff` is neither) and a brick with no L2 sends a routing-error reply (see sysco `sn2-power-time-requests-1.62.1.md`). With an L2 (status 0), text `p <partition> rst` goes to it. Without one: partition 0 sends text `* rst` to the L1 (target `0x0ffff000`); a partition number prints "WARNING: system is partitioned but L2 is unreachable ... This reset may not fully reset the partition" and falls through. After a successful send the code spins until the L1 resets the node. If the send fails, or in the fall-through case, it writes 1 to SHub `0x1_1006_0300` (not in the register map, role unknown) and spins.

The text command is request code `0x0000` on task 3 with one string argument (l1-requests.md, "Requests after boot"). The PROM waits for any valid reply frame and does not read it; silence for 3,000,000 ticks takes the `0x8d` die path.

### 6.4 The time of day

- **PROM entry (established).** EFI `RtSNGetTime` (`0x1093c0`) calls SAL `0x0200000b` (`sal_0b`, `0xffb14300`) with a 14-byte buffer of seven u16: year, month, day, hour, minute, second, milliseconds. EFI copies them into `EFI_TIME` (milliseconds times 1,000,000 is the nanosecond field), zeroes the time zone, ignores the SAL status and reports accuracy 50 ppm. `RtSNSetTime` (`0x109250`) reverses the copy and calls SAL `0x0200000a`.
- **Per-node time record (established, `0xffa1cef0`, `0xffa1c8d0`).** The node block holds a pointer (`+0x48`) to a record with the base time (seven u16), the SHub RTC value in microseconds at capture (`+0x10`; counter times the period in ns from `rtc_ctl`, divided by 1000, `0xffa0da70`), the previous result (`+0x18`, `+0x28` packed) and a valid word (`+0x30`). `GetTime` returns the base plus elapsed seconds (`0xffa1c570` carries into minutes to years) and refetches the base when more than 300,000,000 microseconds have passed. A result earlier than the previous one is replaced by the previous one.
- **Base source, method slot 23 of the SHub 1 chip table (`0xfface1e0`, established).**
  1. A BCD time-of-day chip, `0xffaf36a0`: an 8-bit device at the base of a type `0x70` component of the master node's I/O plus `0x80000` (`0xffaf2960`). It is probed once by writing register `0xb`, `6` and reading `6` back: `0xff` selects layout 0 (registers `0x7ff8` to `0x7fff`, a timekeeper SRAM), anything else layout 1 (registers `1, 2, 4, 8, 9, 10`). The year is the BCD year plus a base year read from the chip's NVRAM: signature `NBY` at `0xf7e0` (layout 1: `0x20`) followed by base-year BCD digits; **without the signature the base year is 1970**. A year below 1998 becomes 1998. The read fails (-1) when no chip object exists. Whether an Altix 350 has this chip is unknown.
  2. Otherwise L1 request `0x200e` (`0xffa7f190`): no arguments, destination `0x0ffff006`, reply status 0 then six integers year, month, day, hour, minute, second. The PROM stores them as they are: no century offset, no clamp, milliseconds 0. A reply without the six arguments is `-33`; no reply parks the node (`0x8d`).
  3. If the method fails, the base is 1998-01-01 00:00:00. The RTC value is captured only when the record had no capture yet (`+0x10` zero, `0xffa1cd30`); on a later failure the capture word is not written by this routine and the record copy takes whatever was on the stack (**inferred**). This default and the year clamp are the only fixed dates; the constant 1997 appears in the code only as the "year below 1998" compare.
- **SetTime (established, slot 24 `0xfface390`).** It writes the chip when one exists (year as BCD of year minus 1992, and 1992 into the NVRAM base) and always sends L1 request `0x200d` (six integers in the same order, `0xffa7f430`); a failure prints "NOTE: Unable to set system controller time of day clock". It then refreshes the record. Linux `hwclock --systohc` therefore reaches the L1 or the chip, never the SHub.
- **Why a model prints 1997 (unknown).** The PROM does not produce 1997 from a zero or unset source: no source gives 1998-01-01 as the default, and a zero L1 reply gives year 0. A chip without the `NBY` signature gives 1970 plus the year register, so a host-time chip returning `yy = 27` would print 1997. Check which path the model takes: a `0x200e` frame on the L1 link proves the L1 path.

### 6.5 What a model must provide

- **Power-off.** Nothing on the link: the PROM sends no frame for a 350. The only trace is SAL `0x0200003b` entering `0xffb1bf10` and the kernel's "Power down." line, so a machine-level power-off needs a hook outside the device model (SAL entry or console text), or the run is ended by the host.
- **Reboot.** Answer the `0x0009` partition request with 0, do **not** answer the `version` probe to `0x1ffff003` with status 0 (give a routing-error reply or nothing; silence costs 20 s plus a 300 ms die delay), then answer the `* rst` text command (task 3, request code `0x0000`) with any valid frame, for example status 0, header `0x20 | handle`, argument count 0, then issue the machine reset (`qemu_system_reset_request`). Reset needs no SHub write. A partition number other than 0 prints the partitioned warning and never sends `* rst`.
- **Halt.** Nothing.
- **Time.** Answer `0x200e` with the host UTC from QEMU's standard RTC clock as six big-endian integers (four-digit year first); answer `0x200d` with status 0. The ColdFire `O` L1 does nothing else (its shell helper is a stub), so a faithful model keeps no offset. Do not give the node a time-of-day chip unless it also carries the `NBY` signature and base year.

## 7. SN_SAL_HWPERF_OP and sn_topology

What `cat /proc/sgi_sn/sn_topology` makes the PROM do, read on 2026-11-16 in Ghidra (`shub1snprom.bin` 10.54, SAL runtime mapped with `--sn2-prom --sal-runtime --no-analysis`, address
lists) and in the linux-sn2 tree (`arch/ia64/sn/kernel/sn2/sn_hwperf.c`, `sn_proc_fs.c`, `arch/ia64/include/asm/sn/sn_sal.h`, `sn2/sn_hwperf.h`,
`drivers/tty/serial/sn_console.c`). Grades as in [AGENTS.md](../../AGENTS.md). Nothing was run.

**Why this was read.** A model boot to a shell printed the two header lines of the file and then stopped, with the host CPU idle.

### The kernel side (established)

- **Open** (`sn_topology_open`, `sn_hwperf_enum_objects`): `sn_hwperf_init` runs once under a mutex: `GET_MASTER_NASID` (`0x02000004`), then `HWPERF_OP` with opcode 1 (heap size, size
  argument 8), the kernel's own `vmalloc` of that size, opcode 2 (install heap), and `0x200a` (object count). Then `HWPERF_OP` `0x200c` (enumerate objects) fills a `vmalloc`ed array of
  `count * 0x120` bytes. Any status other than 0 becomes `-EINVAL` and `open` fails; nothing waits.
- **Show** (`sn_topology_show`, once per object): on the first object it calls `GET_SN_INFO` (a nonzero status is a `BUG`), prints the `partition` line, and calls `GET_PCI_TOPOLOGY`
  (`0x02000064`) with a page-sized buffer, retrying with larger buffers up to 15 pages only while the status is neither 0 nor -1. For each object it formats a line from the object
  record, and for an object with ports calls `HWPERF_OP` `0x200d` (enumerate ports) with `ports * 12` bytes. A node or TIO object also gets a nearest-node search that calls `0x200d`
  for the node and for its router.
- **No wait.** There is no completion, retry on a "busy" status, `smp_call_function_single` or `work_on_cpu`: those are only in `sn_hwperf_op_cpu`, which the ioctl path reaches, not
  `/proc`. Every call is a plain `SAL_CALL_NOLOCK` on the reading CPU. The loops are bounded by the object count, the port count (a `BUG_ON` above 16 ports) and 15 buffer sizes.
- **seq_file buffers a whole read (standard behaviour, inferred: the generic code was not re-read).** The first `read` collects every object's output before copying any of it to the reader, so the file's text cannot reach `cat` in pieces from a
  stuck `show`. Two header lines on the screen therefore came through the console after `show` had finished, which points at the console path, not at `sn_topology`.

### The PROM side (`salruntime_hwperf_op`, `rt:0x8650`)

The object table is the pcfg object list: record `0x48` bytes per object of type 7 (SHub, TIO, router), pointer to it at block A `+0x40`. Opcodes carry the kernel's copy flag bits.

| Opcode | What the PROM does | Status |
|---|---|---|
| `1` | Counts type-7 pcfg objects, stores the count, writes `count * 0x48` through the pointer. Needs a size argument of at least 8 | 0, or 1 |
| `2` | Zeroes the buffer and fills one 9-word record per object (index, lock, chip identity, chip-function table). Sets this and the shared flag per object from its partition byte | 0; 1 if short; `0xfe` if no objects |
| `0x200a` | Stores the object count. Needs opcode 2 to have run (the object table pointer is zero before) | 0; `0xfe` before opcode 2; 1 if size under 8 |
| `0x200b` | Chip-function `+0x350` (distance), stores one word | 0, `0xfe`, 1 |
| `0x200c` | A size argument of exactly 8 returns `count * 0x120`. Otherwise per object: chip-function `+0x340` fills name and location, then the id (the object's index in the pcfg list) and the flag bits | 0; 1 if the buffer is under `count * 0x120` |
| `0x200d` | Chip-function `+0x348` for the object index in a0; a size of 8 returns the required size (`0x18` for SHub and TIO, `0x60` for the NUMAlink routers) | 0, or `0xfe` when the function is negative |

Everything else returns `0xfe`. The chip-function routines read memory only: `shub_hwperf_object_info` (`rt:0x19550`) and the TIO and router twins copy a name and format the geoid with
`hwcfg_format_geoid`; `shub_hwperf_port_info` (`rt:0x19630`) reads two port records of the pcfg entry; `shub_hwperf_object_distance` (`rt:0x198b0`) compares geoids. **None of them sends an
L1 request, touches a SHub register, takes a lock that can be held elsewhere or loops on a status.** The only statuses the call returns are 0, 1 and `0xfe` (and a negated chip-function result);
**it never returns 4 ("busy")**, so there is no PROM path the kernel's retry code could be answering. The record layout the kernel reads is `0x120` bytes: id at `+0`, flag bits at `+8`,
name at `+0x18`, location at `+0x98`, port count at `+0x118` (2 for SHub and TIO). The name is "SHub 1.1", "SHub 1.2" or "SHub 1.x" by chip revision byte, or "TIO 1.x"; the kernel finds the kind
by the substrings "SHub", "TIO" and "Router".

`GET_PCI_TOPOLOGY` (`0xffb44bf0`, SAL_B, case `0x64` of the I/O dispatcher) was read in full: it clears the buffer, then for each segment up to the I/O state's maximum and each of 256 bus numbers
looks the bus up in the bus lists (`0xffb2a140`), formats one text line per bus object and appends it. It sends no L1 request, ignores the buffer length except for the clear, and always returns 0.
So the kernel's retry loop ends at the first buffer size. (Established for the control flow; the text format was not decoded.)

### The type-0 geoid cannot make the walk loop

With a type-0 hubdev geoid (see [klconfig.md](../../platforms/sn2/klconfig.md#geoid-and-module-id)) the object's location string is the PROM's placeholder for an invalid geoid (`<invalid>`,
selected when `geo_valid` fails; inferred that type 0 is invalid, the test was not decoded). The kernel's `sscanf` of it fails, `sn_hwperf_geoid_to_cnode` returns -1 and `show` prints
one `node -1 <invalid> ...` line with no nasid, distance or CPU lines and skips the nearest-node search. No loop or wait: it only makes the topology file wrong.

### What does stall: console transmit after 127 bytes (inferred from the read code)

The file's text is well over 127 bytes (the `partition` line alone is about 150), written by one `write` from `cat`. In interrupt mode the kernel's `sn_transmit_chars` sends it with `XMIT_CHARS` (`0x0200002a`), which takes **at most 127
bytes, one send buffer**, and returns the count taken or 0 when the previous buffer has not drained. It then stops and waits. The kernel never enables the transmit interrupt itself
(`sn_console.c` only enables receive and disables transmit). The PROM turns the UART transmit interrupt on in `l1sc_send_async`, pushes the buffer out from `l1sc_send_intr` when the status
call sees the transmit-ready bit of the interrupt identification register, and reports "transmit" to the kernel only on the next pass, when that bit is set again and nothing is pending
(`l1sc_intr_status`, `rt:0x52a00`). A UART model that raises the transmit-holding-register-empty interrupt once and does not raise it again after the data-register writes lets
a write of up to 127 bytes finish and stalls every longer one: the first 127 bytes (the two header lines and the start of the `partition` line) appear and the rest never leaves. The host
CPU is idle because the guest is waiting for an interrupt. A **model must** set the transmit-holding-register-empty condition again after each write to the data register while
interrupt-enable bit 1 is set, cleared by reading the interrupt identification register. The test that tells this from a topology fault: `cat /proc/sgi_sn/sn_topology > /tmp/x` finishes, and any
command with more than 127 bytes of output stalls. Not run.

### What a model must provide for `/proc/sgi_sn/sn_topology`

- `HWPERF_OP` opcodes 1, 2, `0x200a`, `0x200c`, `0x200d` as above (status 0). `0x200b` and the acquire and MMR opcodes are not used by `/proc`.
- One record per object with name containing "SHub" (and "TIO" for a TIO), flag bit 0 set for the local partition, a location in the `RRRtBB#S` or `RRRtBB^SS#S` form and a port count of 2 for a node.
  The port records (port, connected object id, connected port) with an id that matches no record print "endpoint disconnected". An object with no flag bits is skipped.
- A valid geoid for the node, or the topology line carries `node -1`.
- `GET_PCI_TOPOLOGY` status 0 with text, or status -1 (kernel skips the section).

## Review

Independent re-read on 2026-11-16: PROM side in Ghidra (`--sn2-prom --no-analysis` on `shub1snprom.bin` 10.54, plus the EFI ELF from FIT type `0x1f`), kernel side against the Library `linux-history` tree (the `arch/ia64/include/asm` layout, the era this page cites) and the public community tree `nsafran1217/linux-sn2` (Linux 7.3-rc3 with an ia64 revert, read from the holdings mirror, commit `69571599c5`). No emulator ran.

**Confirmed.**
- Every SAL_B handler address in the two SAL tables of this page matches the dispatch table (`sal_<id>` entries, about 70 ids compared, including `0x01000010` `0xffb1e300`, `0x01000011` `0xffb1e4b0`, `0x01000012` `0xffb60270`, `0x0200000a`/`0b`, `0x02000013`, `0x0200002d`, `0x02000066` `0xffb5fc90`, `0x02000068` `0xffb13a70`, console `0x21`..`0x2c`). `0x01000006` and `0x01000020` thunk to `0xffb1daf0`, which returns -1; `0x01000009` returns -3 on failure of `0xffb204c0(1)`; `0x01000013` calls `0xffa0dcf0` and returns 0.
- `PCI_CONFIG_READ/WRITE`: both look the device up (`0xffb2aeb0`) and call the config accessor only when the lookup is non-zero; the return value is 0 either way, so for an absent device no data register is written (the page's "unknown what r9 holds" stands; the kernel's `pci_sal_read` in `arch/ia64/pci/pci.c` was not re-read).
- Callback `0x6000` is `0xffb140a0`; op 1 arms with vector `0xef`. Callbacks `0x3000`, `0x5000`, `0x7000` descriptors match.
- The Linux SAL ids in `sn_sal.h` (console `0x21`..`0x2b`, `0x1e`, `0x1d`, `0x65`, `0x66`, `0x68`, `0x5`, `0x4a`, `0x51`..`0x57`, `0x60`, `0x61`, `0x64`) match this page; `sn_setup` calls `SET_OS_FEATURE_SET` with 0, 1, then `PCISEGMENT_ENABLE` (3), then `ACPI_ENABLE` (2) before `acpi_table_init` in linux-sn2 too; `GET_SN_INFO`/`GET_SAPIC_INFO` map `-1` (not implemented) to a fixed decode and any other negative status is returned (and the caller `BUG()`s); `sn2_rtc` rating 450, 55-bit mask; `sn_ack_irq` reads `SH_EVENT_OCCURRED` and writes the alias; PTC path (`mm_users == 1` local purge, `SH1_PTC_0/1`, `PIO_WRITE_STATUS` pending-count idle value all ones on SHub 1).

**Differences between trees (linux-history 2.6.3x vs linux-sn2 7.3).**
- ROM BAR: 2.6.3x maps and sizes it at device fixup; 7.3 marks it shadowed and does not map it (section 5.3). A model that backs the ROM address is safe for both.
- `sn_force_interrupt_flag`: present in 2.6.3x (`irq.c`), removed in 7.3; both force an interrupt after each PIC device interrupt.
- `pci_scan_bus` (2.6.3x) against `pci_scan_root_bus` (7.3); the PCI error interrupt is handled in the SAL (`IOIF_ERROR_INTERRUPT`) in both, and 7.3 panics ("Fatal Bridge Error") when that call returns negative.
- `SET_CPU_NUMBER` is called in all three trees, not only v5.3; the held 2.6.5 call list was not re-read.
- A `0x55` error is a skip in both, not a BUG (corrected above). The flush-list call is `0x5a`; `0x58` is a PROM-older-than-4.50 workaround.
- 7.3 `ia64_sn_plat_set_error_handling_features` is still called and marked obsolete.

**Changed.** The rows and bullets named above (SET_CPU_NUMBER, 0x55 handling, flush-list id, ROM mapping, force-interrupt flag, `0x56` status); the closing "second source" bullet is now answered by this review.

**Not checked.** Every `rt:` runtime address and the runtime table at `rt:0xa29f8` (the SAL runtime component was not mapped; only SAL_B and the EFI ELF were read); the PAL table's SAL_B call addresses; the IPI send path; the EFI-side handlers of `RtSNGetTime` and `ConvertPointer`; the held 2.6.5 kernel; the older 2.4 SN2 tree for the runtime-service list.

### Review of section 6 (power-down, reset, time of day)

Independent re-read on 2026-11-16: PROM in Ghidra (`--sn2-prom`, SAL_B of `shub1snprom.bin` 10.54 and the EFI ELF inflated from FIT type `0x1f`), `ia64-linux-gnu-objdump` cross-check of `0xffb1c276`, `0xffa82a10` and `0xffa1cd30`; ColdFire `O` package 3 (1.62.1) in Ghidra; Linux from the `nsafran1217/linux-sn2` mirror (head `69571599c5`). No emulator ran.

**Confirmed.** SAL `0x3b` at `0xffb1bf10`: node-count gate, `l` compare at `0xffb1c276`, `0x100a` (`0xffa7efe0`) then bit 59, INIT IPIs and `0xffa0d610` with the `pwr d` texts and the partitioned warning; `0xffb1ba90` (INIT IPI value `0x8000_0000_0000_0005 | id << 4`, text strings `p %d rst`, `* rst`, `version`, the `0x1_1006_0300` write is `0x81_1006_0300` with the local bit); EFI `RtPlResetSystem` accepts types 0 to 2 and calls the callback; `RtSNGetTime`/`RtSNSetTime` field copies, milliseconds times 1,000,000, accuracy 50 ppm; SAL `0x0b` (`0xffb14300`) returns -3 when the record read fails (EFI ignores it); the 300 s refresh and the monotonic clamp; slot 23 (`0xfface1e0`, chip first, then `0x200e`) and slot 24 (`0xfface390`, chip write then `0x200d`, the NOTE text); `0x200e` six-integer parse with -33 otherwise; the BCD chip layouts, `NBY` signature, 1970 default, 1998 clamp, year minus 1992 on write; 1998-01-01 fallback. Linux: `pm_power_off = ia64_sn_power_down` (`setup.c:529`), `machine_restart` to `efi_reboot(REBOOT_WARM)`, `machine_halt` to `cpu_halt` (PAL only), `efi_gettimeofday` zeroes on error.

**Changed.** The `version` probe: it is true only for status exactly 0 and the L1 does not give that (above). A silent probe was "unknown": it waits 20,000,000 us, takes the die routine, which returns, and the reset continues (the 3,000,000-tick wait of the reset text takes the same path). SAL `0x3b` returns -3 on an identity read failure. Capture of the RTC on a failed base read. The kernel path to `pm_power_off` in 7.3 is `do_kernel_power_off`, which registers `pm_power_off` as a legacy sys-off handler; older trees call it directly. The reply and time rows of 6.5 as edited. Address notation for the state word.

**Not checked.** The callback `0x5000` descriptor from `RtSalCallBack` to `0xffb1ba90` (taken from the earlier review); the chip probe `0xffaf2870` (write 6 to register `0xb`, read back); whether an Altix 350 has the time-of-day chip; the `linux-history` Library tree (only the community tree was read); `0x0009` caching in `0xffa7db00`; what the die routine's bit in `0x1_101d_0080` does at the L1.
