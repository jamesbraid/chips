# SN2 early boot: what the 2.6.5-7.244 Altix kernel needs from firmware

From the kernel entry point through `start_kernel`, `setup_arch`, `sn_setup` and `sn_cpu_init`: every table, memory-map type, SAL call, PAL call and SHub register the SLES 9 SP3 SN2 kernel touches before the platform is up, checked against what the [PROM](../firmware/snprom/README.md) and the [SAL runtime page](../sal/sn2-runtime.md) provide. Stage 6 of the [Altix 350 boot path](../../platforms/sn2/boot-path.md#6-linux-early-boot-on-sn2); the loader that precedes it is [ELILO on IA-64](../boot/elilo-ia64.md).

## Sources and grades

- **The kernel:** `ia64-boot/sn2-kernel/2.6.5-7.244-sn2/` (`vmlinuz-2.6.5-7.244-sn2`, `System.map-2.6.5-7.244-sn2`, `config-2.6.5-7.244-sn2`; SLES 9 SP3 `kernel-sn2`). `vmlinuz` is a gzip of an IA-64 ELF64 `ET_EXEC` with symbols. Read in Ghidra with the IA-64 processor module (`--ghidra-export` inflates it), 42 functions decompiled and 26 more for the ACPI and EFI helpers, plus an `ia64-linux-gnu-objdump` listing of the whole text segment used for the call-site scan of every SAL and PAL id. The decompiler output is navigation; each claim below was checked in the listing or in a constant the decompiler shows unchanged. Addresses are kernel virtual (`0xa000000100...`) or ELF file facts.
- **Linux source** (public, by version): v2.6.5 (`arch/ia64/kernel/{head.S,setup.c,efi.c,sal.c,acpi.c}`, `include/asm-ia64/system.h`, `include/asm-ia64/pgtable.h`) and v2.6.14 (`arch/ia64/sn/kernel/{setup,io_init,irq}.c`, `include/asm-ia64/sn/{sn_sal,sn_feature_sets}.h`), from the Library `linux-history` root. **A finding that changes how to read the old notes:** the SN platform code in this kernel is not the SN code of mainline v2.6.5 (which still builds a hardware-graph and reads klconfig directly for I/O). It matches mainline's later SN code in structure and SAL use (a version after v2.6.12 and before the `SET_CPU_NUMBER` and ACPI/PCI-segment OS-feature additions; **v2.6.14 as the exact match is inferred, the review could not pin the tag**), plus SHub 2 branches, so the later SN source names the SN functions and v2.6.5 names the generic ia64 ones. Evidence: the symbols `sn_prom_feature_available`, `hubdev_init_node`, `cnodeid_get_geoid`, `sn_pci_controller_fixup` exist, `sn_cpu_init` calls `GET_SN_INFO` with a SHub-2 flag, and no v2.6.5-only SN symbol (`init_hcl`, `sgi_master_io_infr_init`) is present. **Established** from `System.map` and the decompiled bodies; three functions re-checked in the review against the newest copy of the file in the Library (`sn_cpu_init`'s `GET_SN_INFO` handling and cpu-0 simulator check, `sn_setup`'s `SAL_FREQ_BASE` type 2 fallback of 33,333,333 Hz, `sn_pcdp_setup` against `sn_scan_pcdp`) agree in shape. The kernel also has `sn_pcdp_setup`, an SGI function with no mainline equivalent (mainline later has `sn_scan_pcdp`).
- **Chips pages** cross-checked: [sn2-runtime](../sal/sn2-runtime.md), [SAL calls](../sal/README.md), [klconfig](../../platforms/sn2/klconfig.md), [efi.md](../firmware/snprom/efi.md), [SHub registers](../../devices/shub/registers.md).
- **Config facts** (`config-2.6.5-7.244-sn2`): `CONFIG_IA64_SGI_SN2=y` (not `GENERIC`: the machine vector is fixed to `sn2`, there is no ACPI OEM-id lookup), 16 KiB pages, `CONFIG_NUMA`/`DISCONTIGMEM`/`VIRTUAL_MEM_MAP`, `CONFIG_SMP`, `NR_CPUS=512`, `CONFIG_ACPI=y` with `ACPI_NUMA=y`, `CONFIG_EFI=y`.

Grades follow [AGENTS.md](../../AGENTS.md). "Differs from v5.3" notes compare with the Linux v5.3 behaviour the chips SAL pages were written from.

## The kernel entry state

Established from the ELF header, `_start` in the listing at `0xa000000100008320` (physical `0x4008320`), and v2.6.5 `head.S`:

- **Image:** entry point physical `0x4008320`; `PT_LOAD` segments at physical `0x4000000` (virtual `0xa000000100000000`, 7.1 MB), `0x4720000` and `0x4730000` (data and bss), ending at `0x4d34d60`. The kernel is not relocatable: `_start` finds its own physical base with `mov r3 = ip` and clears the low 26 bits (`KERNEL_TR_PAGE_SHIFT` = 64 MiB), so it only works loaded at a 64 MiB aligned physical address, here `0x4000000`, and with `ip` physical when it starts. The loader uses `p_paddr` as the address ([ELILO](../boot/elilo-ia64.md#loading-the-kernel-entry-point-and-physical-load-address)).
- **What `_start` does with the machine:** `rsm psr.i | psr.ic` first (the listing shows `rsm 0x6000`), sets region registers 5, 6 and 7, pins one 64 MiB instruction and data translation register entry at `KERNEL_START` (`0xa000000100000000`), then `rfi`s into virtual mode. It then maps the boot task's stack, loads the RSE, and on the boot processor executes `dep r28 = -1, r28, 61, 3` and stores `r28` into `ia64_boot_param`: the loader's pointer is **physical** and the kernel turns it into a region-7 (identity-mapped, cached) address by setting the top three bits. Nothing else from the loader is read: `r28` only.
- **Therefore the entry contract is:** physical-mode execution at `0x4008320` with `r28` = physical address of a readable `struct ia64_boot_param` in write-back memory. Grade **established**.
- The first boot-processor call out of `_start` is `start_kernel`; non-boot processors take `start_secondary` (SMP) instead. Neither needs firmware before `setup_arch`.

## Order: `start_kernel` to `sn_cpu_init`

`start_kernel` calls `setup_arch` (generic ia64, `0xa00000010068e560`). The listing and decompiler give this order (**established**); everything outside it is untouched until later initcalls.

| # | Step | Needs from firmware |
|---|---|---|
| 1 | `ia64_patch_vtop`, command line: `cmdline_p = ia64_boot_param->command_line` as a region-7 address, copied by `strlcpy` into `saved_command_line` (512 bytes) | the command line NUL-terminated in readable memory |
| 2 | `efi_init` | EFI system table, configuration tables, runtime services, memory map ([below](#efi-what-efi_init-and-the-memory-map-need)) |
| 3 | `efi_get_iobase` | the first memory-map descriptor of type 12 (`EfiMemoryMappedIOPortSpace`) whose attribute has bit 0 (`EFI_MEMORY_UC`) set; its physical address becomes the I/O base. None: falls back to `ar.k0` |
| 4 | `sn_pcdp_setup` | optional HCDP/PCDP table |
| 5 | `sn_serial_console_early_setup` -> `early_sn_setup` | the SAL system table entry point, found a second time through the EFI configuration table; registers an early console that writes with SAL |
| 6 | `acpi_table_init`, `acpi_numa_init` | the ACPI 2.0 RSDP, XSDT and the SRAT and SLIT tables ([below](#acpi)) |
| 7 | `find_memory` | memory descriptors; reserves boot parameters, memory map, command line, initrd and the kernel image |
| 8 | `ia64_sal_init(efi.sal_systab)` | the SAL system table ([below](#the-sal-system-table)) |
| 9 | `PAL_LOGICAL_TO_PHYSICAL` (42) | PAL |
| 10 | `cpu_init` -> `sn_cpu_init` (pass 1, boot CPU) | `SAL GET_SN_INFO`, nothing else; returns early because no node data exists yet |
| 11 | `acpi_boot_init` | MADT, FADT |
| 12 | `setup_serial_hcdp` (if an HCDP table exists), the VGA check `efi_mem_type(0xa0000) != EfiConventionalMemory` selects the VGA console | PCDP, memory map |
| 13 | `ia64_mca_init` | SAL `SET_VECTORS`, `MC_SET_PARAMS` |
| 14 | `sn_setup` ([platform_setup]) | SAL calls listed below; calls `sn_cpu_init` (pass 2) and `init_smp_config`, `sn_timer_init` |
| 15 | `paging_init` | none |

Later in `start_kernel`: `time_init` (EFI `GetTime`, then SAL `SAL_FREQ_BASE` type 0 and PAL `FREQ_RATIOS`), `sn_irq_init` and the rest of the initcalls.

## EFI: what `efi_init` and the memory map need

All **established** from `efi_init` (`0xa00000010068c240`), `efi_enter_virtual_mode`, `efi_map_pal_code` and v2.6.5 `efi.c`.

- **Boot parameter block:** only the fields up to `initrd_size` (`0x50` bytes) are read; the block, the memory map and the command line are reserved and so must stay readable ([ELILO](../boot/elilo-ia64.md#the-structure-elilo-builds)).
- **System table:** `ia64_boot_param->efi_systab`, read as a region-7 address. The signature must be `IBI SYST` (a mismatch is a `panic`, as is a null system-table pointer); a header revision (`+8`) with a major number other than 1 only warns, and the header revision is what is printed. The firmware vendor string pointer at `+0x18` (UCS-2, up to 100 characters copied) is printed; **a non-null vendor pointer must be readable**. `RuntimeServices` at `+0x58` (kept, used for `GetTime` and `SetVirtualAddressMap`), `NumberOfTableEntries` at `+0x68`, `ConfigurationTable` at `+0x70` (24-byte entries, 16-byte GUID then pointer).
- **Configuration tables the kernel looks for** (matched by GUID in a loop; absent ones are simply left null): MPS, ACPI 1.0, **ACPI 2.0**, SMBIOS, **SAL system table**, HCDP. Of these the SN2 boot needs the SAL system table and the ACPI 2.0 RSDP; `acpi_find_rsdp` returns only the ACPI 2.0 pointer and prints "ACPI v1.0 r0.71 tables no longer supported" for a machine that has only the 1.0 one.
- **Memory-map types and attributes used:**
  - *Available RAM:* descriptors with attribute **write-back (bit 3)** and type `EfiLoaderCode`, `EfiLoaderData`, `EfiBootServicesCode`, `EfiBootServicesData` or `EfiConventionalMemory` (v2.6.5 `is_available_memory`). Everything else is not given to the allocator. After trimming to 16 MiB granules (16 KiB page config), partial granules are dropped with a notice. The kernel image, the boot-parameter block, the map buffer and the initrd sit in loader types, so the kernel reserves them explicitly and nothing else relies on the distinction.
  - *Runtime descriptors:* any descriptor with attribute bit 63 gets a `virt_addr` (`efi_enter_virtual_mode`): region 7 (`0xe...`) if write-back, otherwise region 6 (`0xc...`) if uncached, write-combining or write-through; then `RuntimeServices->SetVirtualAddressMap(map_size, desc_size, version, map)` is called through a physical-mode wrapper. On failure the kernel prints "unable to switch EFI to virtual mode" and **continues** with physical-mode wrappers.
  - *PAL code:* `efi_get_pal_addr` takes the first `EfiPalCode` (type 13) descriptor; a second one only prints "Too many EFI Pal Code memory ranges" and is not used. A descriptor longer than 16 MiB is a `panic`. `efi_map_pal_code` installs an instruction translation register for it (the mapping the later virtual-mode PAL calls need); with none the kernel prints a warning and installs nothing. A PAL range inside the kernel's own 64 MiB mapping needs no register.
  - *I/O port space:* the first descriptor of type 12 with `EFI_MEMORY_UC` (bit 0) set; the test in `efi_get_iobase` looks at that bit only, so the runtime bit (63) is not required, although the PROM's `0x8000000000000001` satisfies it. `ia64_iobase` is its physical address OR'd with region 6. Without it the kernel prints "No I/O port range found" and uses `ar.k0` (what the firmware left there; zero if untouched).
  - *Legacy VGA hole:* `efi_mem_type(0xa0000)` is compared with `EfiConventionalMemory`; anything else selects the VGA console driver (the later `sn_setup` check then disables it unless PCDP named a VGA device).
- **Runtime services used by the kernel before userspace:** `SetVirtualAddressMap` (above), `GetTime` (once, in `time_init`: a failure leaves the wall clock at 1970), and later the EFI variable and reset routines through the kernel's wrappers. [efi.md](../firmware/snprom/efi.md) lists the PROM's runtime services as reachable through SAL (`0x0a`, `0x0b`, `0x08`).
- **HCDP/PCDP:** `efi.hcdp` is optional. `sn_pcdp_setup` requires table revision 3 or later; it walks the device list after the UART entries (each `0x2d` bytes from `+0x28`) for a primary-console VGA device and records its I/O and memory bases; with none, `sn_setup` prints "SGI: Disabling VGA console". The PROM installs a revision-3 table ([efi.md](../firmware/snprom/efi.md#3-configuration-tables-and-where-sn2-specific-data-lives)).

## The SAL system table

`ia64_sal_init` and `early_sn_setup` (**established**):

- Signature `SST_` (a mismatch only prints). Header `0x60` bytes: SAL revision (u16) at `+8`, entry count (u16) at `+0x0a`, SAL_B version at `+0x16` (used as the version), OEM id at `+0x18`, product id at `+0x38`. A revision/version pair of `0x4929`/`0x4929` is rewritten to SAL 2.08. Entries start at `+0x60`.
- Entry type 0, the entry point: `+8` PAL_PROC, `+0x10` SAL_PROC, `+0x18` SAL global pointer. All three are converted to region-7 addresses (`ia64_sal` becomes a two-word descriptor `{SAL_PROC, gp}`). Both `early_sn_setup` (which walks only until it finds this entry, from the EFI table) and `ia64_sal_init` use it; **without it the early console is dead and the kernel prints "failed to find SAL entry point"**.
- Type 2, platform features: byte at `+1`: bit 0 bus lock, bit 1 IRQ redirection (turns on the kernel's redirect), bit 2 IPI redirection, bit 3 ITC drift.
- Type 4, PTC domain info: pointer kept. Type 5, AP wakeup: byte `+1` must be 0 (external interrupt), vector at `+8`; any other value prints "AP wakeup mechanism unsupported".
- Types 1 and 3 (memory descriptor, translation registers) are skipped by length (entry sizes 48, 32, 16, 32, 16, 16 for types 0-5).
- SAL is called through `ia64_sal(id, a1..a7)` with all of the kernel's scratch FP registers saved around it (`ia64_save_scratch_fpregs`), under a spinlock `sal_lock` for the calls the kernel marks non-reentrant, in **virtual mode with translation on** (`psr.dt/it/rt` set, region-7 identity addresses), interrupts possibly enabled. So the SAL runtime must answer in virtual mode ([sn2-runtime](../sal/sn2-runtime.md#how-a-call-reaches-its-routine)); `PAL_PROC` is called the same way with the `ia64_pal_call_*` wrappers.

## ACPI

ACPI is **used**, not absent: `CONFIG_ACPI_BOOT=y`, `ACPI_NUMA=y`. What the kernel needs from tables (**established** from `acpi_table_init`, `acpi_numa_init`, `acpi_boot_init`, `acpi_numa_memory_affinity_init`, `acpi_numa_processor_affinity_init`, `acpi_parse_madt`, and the `sn_setup` loop below):

| Table | Used for | If missing |
|---|---|---|
| RSDP 2.0 (via `efi.acpi20`) and XSDT | root of everything | warning, then nothing below parses |
| **SRAT** (type 14 in the kernel's table enum) | processor affinity entries (proximity domain byte at `+2`, APIC id `+3`, EID `+8`; no enable flag is tested) and **memory affinity entries** (proximity domain byte at `+2`, base `+8`, length `+0x10`, flags `+0x1c` bit 0 = enabled; disabled entries are skipped) fill `node_memblk` and `node_cpuid`. **At least one processor entry is required:** `acpi_numa_arch_fixup` builds the proximity-to-node maps and `numnodes` only when `srat_num_cpus` is non-zero; with none it marks node 0 online and leaves memory ranges unmapped. Nodes are numbered in ascending proximity domain over every domain any entry names | `find_memory` prints "node info missing!" and sets `numnodes` to 1; `sn_setup` then finds no memory range, computes NASID `-1` and calls `GET_KLCONFIG_ADDR(-1)`; the kernel stops with a `BUG` only if that call returns r9 = 0 (**established** from `find_memory` and `sn_setup`) |
| **SLIT** (type 12) | NUMA distances | warning only |
| **MADT** (type 1) | local APIC address (stored as `ipi_base_addr` in region 6 when non-zero; SN sends IPIs through the SHub, so it is not used for them: inferred), **LSAPIC entries (type 7)** give the CPU ids; IOSAPIC, interrupt source overrides, platform interrupt sources and NMI entries are parsed if present | "Can't find MADT" and the kernel assumes one CPU: it uses the id in `cr.lid` |
| FADT (type 7) | power and legacy flags | "Can't find FADT", boot continues |

The XSDT OEM id "SGI" is **not** used by this kernel (a fixed `sn2` build, no OEM-id lookup). The DSDT and the `SGIHUB` namespace of the v5.3 ACPI I/O path are not used either: this kernel does not set the OS ACPI or PCI-segment features, and its I/O path is the direct SAL one (`0x55` to `0x58`, below). The contents of the PROM's ACPI tables are **unknown** in chips; this is the table of what they must contain ([questions](../../questions/sn2-sal-open.md)).

## SAL calls

**Established** from `sn_setup`, `sn_cpu_init`, `init_smp_config`, `ia64_mca_init`, `time_init`/`ia64_init_itm` (decompiler plus the constant scan of the listing). The table is grouped by caller, not in time order. The boot CPU's actual sequence is: early console writes (`CONSOLE_PUTB`, from `setup_arch` step 5 on); `SN_SAL_FAKE_PROM` (simulator only) and `GET_SN_INFO` (`sn_cpu_init` pass 1, from `cpu_init`); `MC_SET_PARAMS` types 1 then 2, then `SET_VECTORS` types 0 and 1 (`ia64_mca_init`); in `sn_setup`, `SET_ERROR_HANDLING_FEATURES`, `SET_OS_FEATURE_SET` 0 then 1, `GET_KLCONFIG_ADDR` per node, `SAL_FREQ_BASE` type 2; then `sn_cpu_init` pass 2 (`GET_SN_INFO`, `GET_PROM_FEATURE_SET` 0 and 1, `GET_SAPIC_INFO`); then `SET_VECTORS` type 2 (`init_smp_config`); later `SAL_FREQ_BASE` type 0 (`time_init`). The last column checks [sn2-runtime](../sal/sn2-runtime.md) and the [SAL page](../sal/README.md).

| # | Id | Name | Caller | Arguments | How the result is used | Matches chips |
|---|---|---|---|---|---|---|
| 1 | `0x0200001e` | `GET_SN_INFO` | `sn_cpu_init` pass 1 (in `cpu_init`) and pass 2 | a1 = 0 | r8 = -1: fall back to SHub 1 defaults and call `SYSCTL_PARTITION_GET`; r8 < -1: `BUG`. Else r9 bytes: [7:0] SHub 2 flag, [15:8] system size, [23:16] sharing-domain size, [31:24] partition id, [39:32] coherency id, [47:40] region size; r10: [15:0] NASID mask, [23:16] NASID shift. AS shift = shift - 2 | yes: r10 = `0x2607ff` (mask `0x7ff`, shift 38) |
| 2 | `0x0200001a` | `SET_ERROR_HANDLING_FEATURES` | `sn_setup` | a1 = 3 | result ignored | yes |
| 3 | `0x02000066` | `SET_OS_FEATURE_SET` | `sn_setup` | a1 = 0, then a1 = 1 | result ignored | partial: **this kernel calls it twice (0, 1), not four times** |
| 4 | `0x02000005` | `GET_KLCONFIG_ADDR` | `sn_setup`, once per node | a1 = NASID | r9 = klconfig address (region-7'd); **0 is a `BUG`**; the kernel then walks the board list (below) | yes |
| 5 | `0x01000012` | `SAL_FREQ_BASE` | `sn_setup`; `ia64_init_itm` | a1 = 2 (RTC); 0 (ITC) | RTC: r8 = 0 and r9 >= 100000 else warning and default 33,333,333 Hz; ITC: base clock for the interval timer | yes (20 MHz, 200 MHz) |
| 6 | `0x02000065` | `GET_PROM_FEATURE_SET` | `sn_cpu_init` pass 2 | a1 = 0, 1 (stops at the first non-zero r8) | r9 stored in `sn_prom_features[i]` | yes, **but chips says v5.3 only: this kernel calls it** |
| 7 | `0x0200001d` | `GET_SAPIC_INFO` | `sn_cpu_init` pass 2 | a1 = `cr.lid >> 16 & 0xffff` | r8 = -1: fall back to bit-slicing the id; r8 < -1: `BUG`. Else r9 NASID, r10 subnode, r11 slice | yes |
| 8 | `0x01000000` | `SET_VECTORS` | `init_smp_config`; `ia64_mca_init` | type 2 (OS boot rendezvous) with physical entry and gp; types 0 (MCA) and 1 (INIT) | negative result: "Can't set SAL AP Boot Rendezvous" or MCA setup failure, boot continues | listed |
| 9 | `0x01000005` | `MC_SET_PARAMS` | `ia64_mca_init` | (1, 1, vector `0xe8`, timeout, 1) rendezvous interrupt; (2, 1, vector `0xf0`) wakeup | chips: r9 = `0xbf68`; failure only prints | listed |
| 10 | `0x0200003a` | `SYSCTL_PARTITION_GET` | `sn_cpu_init` only on the `GET_SN_INFO` fallback | NASID from `cr.lid` | r9 partition | yes |
| 11 | `0x02009999` | `SN_SAL_FAKE_PROM` | `sn_cpu_init` pass 1, **only when `cpuid[2] == 0xaeeeeeee8badbeef`** (the simulator) | none | non-zero: real simulator PROM | not called on hardware |
| 12 | console | `CONSOLE_PUTB` (`0x02000028`) | the early console registered in step 5 of the order table | bytes | used before the real console; the table entry is chosen through the `poll_ops` table (symbol names, **inferred**) | yes |

Calls the kernel makes **after** `sn_cpu_init` and so outside this page's scope, from the same scan (callers by symbol): console `0x21`-`0x2b` (`sn_sal_module_init` uses `CONSOLE_INTR` `0x27`), `0x55 GET_HUBDEV_INFO`, `0x56 GET_PCIBUS_INFO`, `0x57 GET_PCIDEV_INFO`, `0x58 GET_WIDGET_DMAFLUSH_LIST` (`sn_pci_init`, `sn_pci_controller_fixup`, `sn_pci_fixup_slot`), `0x4a IOIF_INTERRUPT`, `0x51 IOIF_ERROR_INTERRUPT`, `0x52 IOIF_PCI_SAFE`, `0x53`/`0x54` slot enable/disable, `0x50 HWPERF_OP` and `0x04 GET_MASTER_NASID` (`sn_hwperf_init`), `0x64 GET_PCI_TOPOLOGY` (topology `/proc` show), `0x60 HUB_ERROR_INTERRUPT`, `0x61 BTE_RECOVER`, `0x06 LOG_CE`, `0x12 PRINT_ERROR`, `0x1b GET_FIT_COMPT`, `0x38`/`0x39` serial numbers, `0x3b SYSTEM_POWER_DOWN`, `0x43`/`0x44` system-controller router and event, and the standard SAL ids `0x01000001`-`0x01000003` (state info), `0x01000010`/`0x11` (PCI config), `0x01000013` (`PHYSICAL_ID_INFO`, from `identify_siblings`). Not present anywhere in the kernel: `0x02000068 SET_CPU_NUMBER`, `0x02000067`, `0x02000069`, `0x0200005f IOIF_INIT` (the constant scan found no site).

### Differences from v5.3

- No `SET_CPU_NUMBER` call (chips lists it first; v5.3 only).
- `SET_OS_FEATURE_SET` twice (ids 0, 1: MCA slave to OS INIT slave, log single-bit errors), not four times; so no ACPI or PCI-segment OS feature is announced and the PROM is **not** asked to rebuild its DSDT.
- `GET_PROM_FEATURE_SET` **is** called (chips records that mainline v2.6.12 does not call it; this kernel's SN code is newer in this respect).
- I/O is discovered by the direct calls `0x55` to `0x58`, never by `IOIF_INIT` and the ACPI `SGIHUB` namespace.
- The node-table build is embedded in `sn_setup`, driven by `numnodes` from the SRAT; the klconfig scan loads the word at `+20` of the SAL result, the byte at `+5` of each board (`0x11` or `0x12`: `KLTYPE_SNIA`, `KLTYPE_TIO`), the halfword at `+48` (its NASID) and the word at `+0` (next board), as [klconfig](../../platforms/sn2/klconfig.md) already records.
- v5.3 has no `sn_pcdp_setup`; mainline later has the equivalent `sn_scan_pcdp`.
- SHub 2 code paths exist in this kernel (`GET_SN_INFO` SHub-2 flag, `pio_write_status` tables for slices 0 to 3), so an Altix 4700 PROM is a possible peer; the Altix 350 uses the SHub 1 branches.

## How `sn_setup` finds the nodes

(**established**, `sn_setup` listing.) For each node `n` counted by `acpi_numa_arch_fixup` (`nid_to_pxm_map`), it looks up the memory range whose proximity domain matches (no match gives `0xffffffff`, i.e. NASID `-1`) and computes `NASID = (range_start >> nasid_shift) & nasid_mask`, using the shift and mask from `GET_SN_INFO` (38 and `0x7ff`: **the SRAT memory ranges must be NASID-addressed**, `nasid << 38`). It stores the pair in `sn_cnodeid_to_nasid` and `physical_node_map`. Then, unless it is running on the simulator (`sn_prom_type` 2), for every node it calls `GET_KLCONFIG_ADDR(nasid)` and walks that node's `lboard` list for boards of type `0x11` or `0x12`, adding the NASID in each such board to the node tables if not yet known (this is how headless and I/O-only hubs get a compact node number). Only then does it allocate the per-node data, run `hubdev_init_node` and call `sn_cpu_init` again.

## PAL calls

Static PAL calls found by scanning every `ia64_pal_call_*` call site for its procedure index, matched to the early-boot functions (**inferred** for indexes taken from the scan alone; **established** where a printed message or the v2.6.5 source names the call):

| Index | Procedure | Caller | Grade |
|---|---|---|---|
| 42 | `PAL_LOGICAL_TO_PHYSICAL` | `setup_arch`; `identify_siblings` | established (index 42 in the listing; the "No logical to physical processor mapping" message; failure is tolerated: single-threaded, single-core assumed) |
| 8 | `PAL_VM_SUMMARY` | `cpu_init` | established (index 8 in the listing; message "PAL VM summary failed, assuming 18 RID bits") |
| 19 | `PAL_RSE_INFO` | `cpu_init` | established (message "PAL RSE info failed; assuming 96 physical stacked regs") |
| 4, 2 | `PAL_CACHE_SUMMARY`, `PAL_CACHE_INFO` | `cpu_init` (before `sn_cpu_init`) | established (indexes in the listing) |
| 6, 34 | `PAL_PTCE_INFO`, `PAL_VM_PAGE_SIZE` | `ia64_tlb_init` | established (indexes 6 and 34 loaded before the calls in the listing) |
| 14, 13 | `PAL_FREQ_RATIOS`, `PAL_FREQ_BASE` | `ia64_init_itm` (index 14 in the listing); 13 not located | 14 established, 13 inferred |
| 17, 18 | `PAL_PROC_GET_FEATURES`, `PAL_PROC_SET_FEATURES` | `cpu_init` (physical-mode wrappers) | established (indexes in the listing) |
| 7 | `PAL_VM_INFO` | `vm_info` (`/proc/pal`) and `ia64_tlb_init` | inferred |
| 29, 28 | `PAL_HALT_LIGHT`, `PAL_HALT` | idle loop; `cpu_halt` | inferred |
| 27 | `PAL_MC_REGISTER_MEM` and related MCA procedures | `ia64_mca_init`, `ia64_mca_cpu_init` | not scanned individually |

Every PAL call in virtual mode relies on the translation `efi_map_pal_code` installs. A model that runs the real PAL_A and PAL_B images (chips found them to match Intel's, [pal-msrs](../firmware/snprom/pal-msrs.md)) needs no PAL emulation here; a model that replaces PAL must answer the indexes above.

## SHub registers touched first

By the boot CPU before the platform is up (**established** as addresses in the listing; names from [registers](../../devices/shub/registers.md)):

1. Nothing at all through the early console, `cpu_init` pass 1, `acpi_*`, `ia64_mca_init` (all SAL, PAL and memory).
2. `sn_setup` -> `sn_cpu_init` pass 2: the **`shub_id`** register (`0x1_1006_0580`, read through the global window `0xc000000910060580` of each node, field bits 31:28 compared with 3) once per node on SHub 1 to detect SHub 1.1 (`shub_1_1_found`); only when `GET_SN_INFO` took the fallback is it also read locally (`0xc000008110060580`) for the region size.
3. Addresses stored, not yet accessed: `rtc` (`0x1_101c_0000`, SHub 2 `0x2_101c_0000`, set in `sn_timer_init`; accessed whenever the time interpolator reads it, first in `register_time_interpolator`); `pio_write_status` (`0x1_2007_0200` and `0x1_2007_0280` for slices 0 and 2 on SHub 1, `0x2007_0200`... on SHub 2; read by the first `mmiowb`), `pi_cam_control` (`0x1_2005_0300`, the SHub 1 write-workaround address kept for later); `junk_bus_led` (`0x7_fed0_0000 + slice * 0x10000`, 16-bit writes by the heartbeat/idle LED code from the first timer ticks); `ipi_int` (`0x1_1000_0380`; SHub 2 `0x1000_0380`; first write when a second CPU is started or an IPI is sent).
4. Everything else (II, PIC, interrupt target registers, the error-interrupt enables `hub_error_init`) comes from `sn_pci_init` and later initcalls and is outside this page.

## Where a model that implements only what chips documents today fails

Assume the minimum of [sn2-runtime](../sal/sn2-runtime.md#what-a-synthetic-sal-for-one-node-must-do) and [efi.md section 6](../firmware/snprom/efi.md#6-what-an-emulated-machine-must-provide-for-efi-to-reach-the-boot-manager-prompt), plus an unreviewed ELILO. In boot order:

1. **ELILO load:** nothing in chips fixes the kernel's load region. The model must leave `EfiConventionalMemory` at physical `0x4000000` up to `0x4d34d60` (plus the 64 MiB translation granule) and the loader's own allocations elsewhere. (Hard stop: the kernel is not movable.)
2. **ACPI tables:** the PROM's own tables, which meet everything below, are in [os-handoff-tables.md](../firmware/snprom/os-handoff-tables.md). The kernel needs an ACPI 2.0 RSDP in the EFI configuration table, an XSDT, an **SRAT with at least one processor affinity entry (without one `numnodes` is never derived) and one enabled memory affinity range per proximity domain, each NASID-addressed** (`nasid << 38`), a MADT with LSAPIC entries and ideally a FADT. Without an SRAT, or with memory ranges but no processor entries, `sn_setup` derives NASID -1 and stops with a `BUG` unless the SAL answers `GET_KLCONFIG_ADDR(-1)` with a non-zero r9. Without a MADT the kernel survives with one CPU.
3. **EFI memory map content:** chips' EFI page requires one conventional region; the kernel additionally needs write-back attributes on all RAM, one `EfiPalCode` descriptor, at most 16 MiB (larger is a `panic`; the PAL lookup does not test attributes), a type-12 port-space descriptor with the UC bit set (`0x8000000000000001` is accepted; or a non-garbage `ar.k0`), runtime attribute bits on the runtime descriptors, and the legacy `0xa0000` range typed so the VGA decision is intended.
4. **EFI runtime services:** `SetVirtualAddressMap` must exist (failure is tolerated, but a crash or a hang is not), `GetTime` should return a plausible time, and the firmware-vendor pointer in the system table must be null or readable. The PROM's runtime services are in [os-handoff-tables.md](../firmware/snprom/os-handoff-tables.md).
5. **SAL system table:** exactly the layout above, with the type-0 entry first at `+0x60` and an AP-wakeup entry (type 5) only with byte 0 equal to zero; the platform-features entry (type 2) changes kernel behaviour. The PROM's complete table is in [os-handoff-tables.md](../firmware/snprom/os-handoff-tables.md).
6. **SAL runtime in virtual mode:** every call is made with translation on through region-7 addresses; chips documents the runtime component for virtual-mode entry, but a model that answers SAL only in physical mode (as SAL_B does) would fault.
7. **Calls missing from chips' minimum list:** `GET_MASTER_NASID` (`0x02000004`, hwperf init), `PRINT_ERROR` (`0x12`), `LOG_CE` (`0x06`), `GET_FIT_COMPT` (`0x1b`), `HUB_ERROR_INTERRUPT`, `IOIF_ERROR_INTERRUPT`, the I/O slot enable/disable calls, `PHYSICAL_ID_INFO` (`0x01000013`) and the PCI config calls (`0x01000010`, `0x01000011`) are all made after `sn_cpu_init` and tolerate `-1`; the early set is covered. Chips marks `SET_CPU_NUMBER`, `GET_PROM_FEATURE_SET` and `SET_OS_FEATURE_SET` as v5.3 only (and says v2.6.12 calls none of the three). This kernel calls the last two but not `SET_CPU_NUMBER`; answering set 1 with -2 and OS features 0 and 1 with -1, as chips records, is right for them.
8. **Klconfig and the I/O hand-off:** `GET_KLCONFIG_ADDR` must return a non-null region-7-reachable address whose header word at `+20` leads to an `lboard` of type `0x11` carrying the node's NASID at `+48`. The PROM-side content for a 350 is now in [klconfig](../../platforms/sn2/klconfig.md#what-a-one-node-altix-350-with-an-io10-gets-summary) (node board `0x11`, midplane `0x42`, per-bus I/O boards; the heap address is bounded, not exact). The kernel's later `0x55` to `0x58` calls need the `hubdev_info`, `pcibus_bussoft`, `pcidev_info` and flush-list layouts in [sn2-runtime](../sal/sn2-runtime.md#the-structures-behind-0x55-to-0x58); a model must also return v0 = 1 from `0x56` for a missing bus. Open: BAR PIO addresses, `bs_legacy_*`, `bs_base` and `bs_xid` values, and the 350's I/O board type letter.
9. **Time and interrupts:** the RTC at `0x1_101c_0000` must count at the `SAL_FREQ_BASE` type-2 rate; the timer interrupt vector `0xef` comes from the processor's own interval timer (no SHub register), and `PAL_FREQ_RATIOS` must be coherent with `SAL_FREQ_BASE` type 0.
10. **Console:** the early console writes with `CONSOLE_PUTB`; the kernel prints nothing visible if the SAL console routes nowhere. The PROM routes it through `candidate_dev[block B +0x88]` to the system-controller objects, which send one framed L1 message per character over the junk-bus UART ([sn2-runtime](../sal/sn2-runtime.md#console-0x02000021-to-0x0200002c)). A model without an L1 can answer `PUTB` itself with status 0 and the count; the kernel uses only the count.

## Unknowns and routes

- The PROM's ACPI tables, memory map, SAL system table and runtime services are now read in [os-handoff-tables.md](../firmware/snprom/os-handoff-tables.md) (items 2 to 5). The klconfig content for a real 350 (item 8) is now read except for the exact heap address and the I/O board type letter.
- The exact PAL index list: only the call sites in the early-boot functions were matched; the MCA registration calls were not decoded.
- Which `candidate_dev` index the PROM stores in block B `+0x88` on a 350 (item 10), and the writers of the node and CPU tables in block A.

## Review

Independent review of chips commit `a4bfcf2`, examined at that revision. The reviewer wrote none of it. Method: the held `vmlinuz` inflated and read in Ghidra (setup_arch, efi_init, efi_get_iobase, efi_get_pal_addr, efi_enter_virtual_mode, efi_map_pal_code, the ACPI NUMA and MADT parsers, ia64_sal_init, early_sn_setup, sn_setup, sn_cpu_init, ia64_mca_init, init_smp_config, cpu_init), a whole-text `ia64-linux-gnu-objdump` listing for the entry state, the SAL-id constants and the PAL index loads, and the newest copy of the SN setup file from the Library `linux-history` root (tags are not addressable there).

**Confirmed.**

- Entry: ELF `e_entry` `0x4008320`, first `PT_LOAD` `p_paddr` `0x4000000`, the third segment ends at `0x4d34d60`; `_start` opens with `rsm 0x6000` (`psr.ic` and `psr.i`); `dep r28 = -1, r28, 61, 3` on the boot CPU only, then the store to `ia64_boot_param`.
- The `setup_arch` order in the table (steps 1 to 15) matches the decompiled body, including `acpi_boot_init` after `cpu_init` and the VGA test against type 7.
- SAL system-table parsing (signature message only, `0x4929` rewrite, entry types 0, 2, 4, 5, byte `+1` rule for type 5) and `early_sn_setup` (walks the EFI table, takes the type-0 entry, "failed to find SAL entry point" otherwise).
- SAL calls, ids and arguments in the table: `0x1a` with 3; `0x66` with 0 then 1; `0x05` per node; `0x01000012` type 2 with the 100000 floor and 33,333,333 Hz fallback; `0x1e`, `0x65` (sets 0 and 1, stop on non-zero r8), `0x1d` (`cr.lid >> 16 & 0xffff`), `0x3a`, `0x2009999` (only for `cpuid[2] == 0xaeeeeeee8badbeef` on CPU 0); `MC_SET_PARAMS` (1, 1, `0xe8`, timeout, 1) and (2, 1, `0xf0`); `SET_VECTORS` types 0, 1 (`ia64_mca_init`) and 2 (`init_smp_config`). No `SET_CPU_NUMBER` call exists.
- The EFI runtime descriptor handling (bit 63, write-back to region 7, UC to region 6, WC/WT message), `SetVirtualAddressMap` at `RT+0x38` with the physical wrapper, and the failure message that does not stop boot.
- MADT only supplies extra CPUs: with no MADT the kernel prints "Found 0 CPUS, assuming 1" and uses `cr.lid`. The klconfig walk reads the word at `+0x14` of the SAL result, board byte `+5` (`0x11`/`0x12`), NASID halfword `+48` and next pointer `+0`.
- No `init_hcl` or `sgi_master_io_infr_init` symbol; `sn_prom_feature_available`, `hubdev_init_node`, `pcibr_init_provider` and `sn_pci_controller_fixup` are present.

**Fixed in this review.**

1. Port space: `efi_get_iobase` tests type 12 and attribute bit 0 only, not the exact value `0x8000000000000001`. The PROM's value passes.
2. SRAT: `acpi_numa_arch_fixup` builds the node maps only when the SRAT has at least one processor affinity entry. Memory ranges alone leave NASID `-1`. The stop is a `BUG` only when `GET_KLCONFIG_ADDR` returns r9 = 0; the no-SRAT path prints "node info missing!" first. Entry field offsets and the enabled-flag rule added.
3. System table: the printed revision is the header revision at `+8`, not a field at `+0x20`; a null table pointer also panics.
4. PAL code: only the first type-13 descriptor is used; one longer than 16 MiB panics.
5. MADT: the local APIC address is stored, not ignored.
6. SAL table is grouped by caller; the real time order is now written above it (`MC_SET_PARAMS` and `SET_VECTORS` 0/1 precede `sn_setup`).
7. PAL list: `PAL_CACHE_SUMMARY` (4) and `PAL_CACHE_INFO` (2) added; indexes 42, 34, 6, 14, 8, 19, 17, 18 upgraded to established from the listing.
8. The kernel's SN code is "later mainline SN code", not provably v2.6.14; the tag could not be retrieved, so the exact version is inferred.

**Gaps.** Added: SRAT processor entries are mandatory; PAL code size limit; the NASID -1 stop depends on the SAL's r9. Items 9 (RTC counting) and 10 (console routing) of the failure list are not needed to reach `sn_setup`; they matter from the first timer read and the first console write, and `GET_MASTER_NASID`, `LOG_CE`, `PRINT_ERROR` and `GET_FIT_COMPT` are in [sn2-runtime](../sal/sn2-runtime.md)'s "other calls" table (only absent from its minimum list). Not in chips at all: `PHYSICAL_ID_INFO` (`0x01000013`) and the PCI config calls (`0x01000010`/`0x11`), all after `sn_setup`. The claim that those later calls tolerate -1 was not checked. Missing from the kernel's post-`sn_cpu_init` list: `PROBE` (`0x03`, legacy PCI reads) and `SYSCTL_OP` (`0x30`, `tiocx_init`).

**Not checked.** The 26 helper functions of the ACPI and EFI parsers beyond those named; the SHub register addresses in the last section; how an early-console write reaches `CONSOLE_PUTB` (`sn_func` indirection, still inferred); the `v5.3` comparison rows.
