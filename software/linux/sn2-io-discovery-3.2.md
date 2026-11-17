# SN2 I/O discovery in the Debian 7.11 ia64 kernel (Linux 3.2.78)

How the Linux 3.2 kernel that Debian 7.11 ships for ia64 finds the PCI buses and devices of an SN2 machine (Altix 350), which SAL calls and firmware-built records it needs for that, and what a lone-node Altix 350 base I/O card should produce. It is the 3.2 counterpart of the "I/O discovery in SN2 kernels" section of [SN2 early boot](sn2-early-boot.md#io-discovery-in-sn2-kernels), which was written from the 7.x tree. The firmware side (what the SNPROM 10.54 handlers return) is on [SN2 SAL runtime](../sal/sn2-runtime.md#the-structures-behind-0x55-to-0x58); this page does not repeat it.

## Sources and grades

- **The kernel.** Debian 7.11 ("wheezy") ships ia64 images `linux-image-3.2.0-4-itanium` and `linux-image-3.2.0-4-mckinley`, version `3.2.78-1`, read from the archive's wheezy index (release version 7.11, released 2016-06-04). There is no `3.2.0-6` image in wheezy. Source read: the upstream 3.2.78 tarball from kernel.org (`https://cdn.kernel.org/pub/linux/kernel/v3.x/linux-3.2.78.tar.xz`). Citations below are `3.2.78:path:line`.
- **Debian changes.** The patch series of `linux_3.2.78-1.debian.tar.xz` was searched: no patch touches `arch/ia64/sn/`, `arch/ia64/pci/`, `drivers/acpi/` table or resource code, or `drivers/pci/probe.c` setup of the paths read here. The series also carries a cpu-devices patch, a Makefile patch, a PCI-PM patch and a one-line probe.c patch; none of these touches `arch/ia64/sn/` or the ACPI table code. Line numbers are the upstream ones, except that the probe.c patch may shift lines in that file.
- **Build configuration.** Read from `/boot/config-3.2.0-4-mckinley` inside `linux-image-3.2.0-4-mckinley_3.2.78-1_ia64.deb` (SHA-256 `80be9bf2...c29fe`): `CONFIG_IA64_GENERIC=y` (so the SN2 machine vector is compiled in and selected at run time; `CONFIG_IA64_SGI_SN2` is not set), `CONFIG_SGI_SN=y`, `CONFIG_ACPI=y`, `CONFIG_ACPI_NUMA=y`, `CONFIG_PCI_DOMAINS=y`, 16 KiB pages, `CONFIG_NR_CPUS=64`, `CONFIG_DEBUG_SPINLOCK` unset, `CONFIG_HOTPLUG_PCI_SGI=y`, `CONFIG_SGI_TIOCX=y`, `CONFIG_SERIAL_SGI_L1_CONSOLE=y`, and as modules `SGI_IOC4`, `BLK_DEV_SGIIOC4`, `SCSI_QLOGIC_1280`, `TIGON3`, `SGI_XP`, `SERIAL_SGI_IOC4`. The `-itanium` flavour differs only in the CPU option.
- **Structure offsets** are computed for ia64 (LP64, 4-byte `int`, 8-byte `long` and pointer, no spinlock debugging) from the headers cited, and checked by compiling the structures with a host compiler. The values that the SNPROM image's own stores can be compared with agree with [the SAL runtime page](../sal/sn2-runtime.md#the-structures-behind-0x55-to-0x58): `hubdev_info` is `0x2f0` bytes with `hdi_nasid` at `+0xc`, the `pcibus_info` bridge-type halfword is at `+0x34`, `pcidev_info` has the interrupt pointer at `+0x58`.
- **Grades.** *Established*: read at the cited source line. *Software expectation*: what this kernel needs of the firmware or the platform, stated from its code (it says nothing about what the hardware does). *Inferred*: a reasoned reading, with the reasoning. *Unknown*: not settled, with the route. PROM facts are cited to chips pages, with the grade those pages give. Nothing here comes from a guest run.

## Short answers

| Question | Answer | Grade |
|---|---|---|
| Which I/O path | The kernel reads the DSDT's OEM revision once, at `arch_initcall` time, and takes the ACPI path (`sn_io_acpi_init`) when it is `>= 0x20101`, the direct SAL walk (`sn_io_init`) otherwise | established |
| Which path PROM 10.54 selects | The ACPI path, provided the rebuilt DSDT carries `0x20101`: the PROM stamps that only when OS feature 2 was accepted (`NoACPIIO` unset) and the DSDT has a body. A header-only DSDT is `0x20001` and would select the direct path | established for the kernel; the PROM rule is as graded on [SN2 early boot](sn2-early-boot.md#io-discovery-in-sn2-kernels) |
| Does 3.2 fail like 7.0 | No. The compaction that loses the DSDT index does not exist in 3.2, and the second table pass resets the table count | established by source for the table code; that a 3.2 guest therefore reaches the namespace is inferred (not run) |
| SAL calls on the ACPI path | `0x66` x4, `0x65` x2, then per hub possibly `0x5a` x512, then `0x5f` once, then `0x01000010`/`0x11` config cycles, later `0x50`/`0x04` for the late-init near-node search. No `0x55`, `0x56` or `0x57` | established |
| Per-device records | Not returned by SAL on the ACPI path. The kernel follows 8-byte physical pointers found in vendor resources in each ACPI device's `_CRS` and copies `hubdev_info` (`0x2f0`), `pcibus_info` (184), `pcidev_info` (128) and `sn_irq_info` (112) out of PROM memory | established |

## 1. Which path runs

`sn_io_early_init` is an `arch_initcall` (`3.2.78:arch/ia64/sn/kernel/io_common.c:511`). It returns at once unless the platform is SN2 and the PROM is not the fake one (`:461`). Then:

1. `acpi_get_table(ACPI_SIG_DSDT, 1, &header)` with `BUG_ON(header == NULL)`, and `sn_acpi_rev = header->oem_revision` (`:468-470`). A kernel whose second table pass found no DSDT dies here.
2. It primes `sn_pci_provider[]` (PIC, TIOCP, TIOCE, TIOCA), `sn_irq_lh_init()`, and prints `ACPI  DSDT OEM Rev 0x%x` (`:500-502`). **That line is the one to read first in a guest log.**
3. `if (SN_ACPI_BASE_SUPPORT()) sn_io_acpi_init(); else sn_io_init();` (`:504-507`). `SN_ACPI_BASE_SUPPORT()` is `sn_acpi_rev >= 0x20101` (`3.2.78:arch/ia64/include/asm/sn/acpi.h:13`). The same macro also picks `sn_acpi_bus_fixup` or `sn_bus_fixup` per bus (`io_common.c:443`) and changes `iomv.c:41`.

The DSDT the kernel sees is the one from the **second** `acpi_table_init`, which runs inside `sn_setup` after the four OS-feature calls (section 2). The PROM's DSDT before that is absent (its FADT `X_DSDT` is 0, [os-handoff tables](../firmware/snprom/os-handoff-tables.md)); the ACPI builder runs on OS features 3 and 2 and stamps `0x20101` only when feature 2 is accepted ([SN2 early boot](sn2-early-boot.md#io-discovery-in-sn2-kernels): header writer's OEM revision, decoder at `0xffb58ca0`). So with PROM 10.54 and the kernel's call order (0, 1, 3, 2, section 3) the kernel sees `0x20101` and takes the ACPI path. Setting the PROM's `NoACPIIO` variable to non-zero leaves the DSDT header-only at `0x20001` and sends 3.2 down the direct path of section 6 (inferred from the two PROM facts; no run).

The ordering that matters, all established: `setup_arch` runs the first `acpi_table_init()` (`3.2.78:arch/ia64/kernel/setup.c:540`), the machine vector's `platform_setup` runs `sn_setup` (`:606`), `sn_setup` makes the feature calls and the second `acpi_table_init()` (`arch/ia64/sn/kernel/setup.c:378-390`), `start_kernel` runs `acpi_early_init()` (`init/main.c:639`, after `setup_arch` at `:500`) which loads the namespace, and `sn_io_early_init` runs later still as an `arch_initcall`.

## 2. Does 3.2 lose the DSDT as 7.0 does

No, by source. The 7.0 failure described on [SN2 early boot](sn2-early-boot.md#io-discovery-in-sn2-kernels) needs three things; 3.2 has the double `acpi_table_init` but not the other two.

- **Double init: present.** `acpi_table_init()` (`3.2.78:drivers/acpi/tables.c:338-348`) calls `acpi_initialize_tables(initial_tables, ACPI_MAX_TABLES, 0)` with a static 128-entry `__initdata` array (`:38`, `:43`, `:342`). It runs from `setup_arch` and again from `sn_setup`. Established.
- **Stale table count: absent.** `acpi_initialize_tables` clears the static array (`3.2.78:drivers/acpi/acpica/tbxface.c:129-135`) and `acpi_tb_parse_root_table` then sets `current_table_count = 2` before reading the XSDT entries (`tbutils.c:705`). The second pass therefore starts from an empty list; no zeroed holes from the first pass remain. Established.
- **DSDT index: fixed.** In this ACPICA (`ACPI_CA_VERSION 0x20110623`, `3.2.78:include/acpi/acpixf.h:50`) slots 0 and 1 of the root table list are reserved for the DSDT and FACS (`tbutils.c:699-705`). `acpi_tb_parse_fadt` installs them at `ACPI_TABLE_INDEX_DSDT` and `ACPI_TABLE_INDEX_FACS` (`tbfadt.c:253-257`) and `acpi_tb_load_namespace` reads `tables[ACPI_TABLE_INDEX_DSDT]` (`tbxface.c:532-543`, `:578`). There is no `acpi_gbl_dsdt_index` to go stale. Established.
- **Reallocation: no compaction.** `acpi_reallocate_root_table` (called from `acpi_early_init`, `3.2.78:drivers/acpi/bus.c:882`) allocates `current_table_count + increment` entries and `ACPI_MEMCPY`s the whole array (`tbxface.c:172-215`). `acpi_tb_resize_root_table_list` likewise copies the whole array (`tbinstal.c:276-320`). Neither drops entries with a zero address. Established.

Consequences, all inferred from the above (no run): the first pass logs `Null physical address for ACPI table [DSDT]` (`tbutils.c:452-457`) because the FADT's `X_DSDT` is 0 then, and carries on; the second pass finds the rebuilt DSDT and the SSDTs; `acpi_load_tables` loads the namespace; `sn_io_early_init` reads `0x20101`. What could still stop a 3.2 guest is not table handling but the content of the PROM's AML (section 5), which no chips page has read: the PNP0A03 root devices, `_CRS` windows and the vendor resources. Unknown; the route is the PROM's DSDT and SSDT bytes from a run or a dump of the tables.

A reading consequence: 3.2 and 7.x share `sn_io_acpi_init`, the vendor UUID, the `_ADR`/`_BBN` matching and every structure below. They differ in the table code only. A guest that takes the ACPI path on 3.2 and fails later would be failing on PROM content that 7.x would reject too.

## 3. SAL calls, in the order the 3.2 kernel makes them

Calls use the kernel's `SAL_CALL_NOLOCK` wrapper except the PCI configuration calls, which use the locked `SAL_CALL`; results are `status` in r8 and `v0` in r9.

| # | Where | Call | Arguments | What the kernel does with the reply |
|---|---|---|---|---|
| 1 | `sn_setup`, `arch/ia64/sn/kernel/setup.c:378-387` | `SN_SAL_SET_OS_FEATURE_SET` `0x02000066` | a1 = feature 0, 1, 3, 2 in that order (`OSF_MCA_SLV_TO_OS_INIT_SLV`, `OSF_FEAT_LOG_SBES`, `OSF_PCISEGMENT_ENABLE`, `OSF_ACPI_ENABLE`; `sn_feature_sets.h:52-55`) | status ignored (`sn_sal.h:1157-1163`). Features 3 and 2 make the PROM rebuild the DSDT before the second table pass |
| 2 | `sn_cpu_init`, boot CPU second pass, `setup.c:614` (called from `sn_setup`, `:481`) | `SN_SAL_GET_PROM_FEATURE_SET` `0x02000065` | a1 = set 0, then 1 | the loop stops at the first non-zero status; v0 saved in `sn_prom_features[]` (`sn_sal.h:1145-1154`). Bit 1 (`PRF_DEVICE_FLUSH_LIST`) selects call 4 over `0x58`; bit 3 (`PRF_CPU_DISABLE_SUPPORT`) is SHub 2 only |
| 3 | `sn_io_acpi_init`, `io_acpi_init.c:503-504` | none: `acpi_get_devices("SGIHUB")` and `("SGITIO")` evaluate AML | | per matching device `sn_acpi_hubdev_init` (section 5) |
| 4 | `sn_common_hubdev_init` per hub, `io_common.c:172-203` | `SN_SAL_IOIF_GET_DEVICE_DMAFLUSH_LIST` `0x0200005a` | a1 = NASID, a2 = widget 0..15, a3 = device 0..31, a4 = **kernel virtual address** of a zeroed `sn_flush_device_common` (152 bytes) | status non-zero is `panic("SAL call failed")` (`:201-203`). Made 16 x 32 = 512 times per hub, **only if the PROM's `hubdev_info.hdi_flush_nasid_list.widget_p` is non-null** (`:172-173`); with a null `widget_p` the kernel makes no flush-list call at all and its DMA flush code returns early (`pcibr_dma.c:262-264`). If `PRF_DEVICE_FLUSH_LIST` is clear it makes `0x58` instead (`:197-200`, `sn_device_fixup_war`: a1 NASID, a2 widget, a3 physical address of 32 `0xa0`-byte entries; status non-zero is a panic) |
| 5 | `sn_io_acpi_init`, `io_acpi_init.c:506-509` | `SN_SAL_IOIF_INIT` `0x0200005f` | all arguments 0 | `panic("sal_ioif_init failed")` unless status and v0 are both 0 |
| 6 | PCI core, once per root bus, for every device slot it probes | `SAL_PCI_CONFIG_READ` `0x01000010` and `SAL_PCI_CONFIG_WRITE` `0x01000011` | read: a1 = address, a2 = size, a3 = type; write: a1 = address, a2 = size, a3 = value, a4 = type (`sal.h:756-773`). Address `seg<<24 \| bus<<16 \| devfn<<8 \| reg` with type 0 when `(seg \| reg) <= 255`, else `seg<<28 \| bus<<20 \| devfn<<12 \| reg` with type 1, only when the SAL revision is at least 3.2 (`arch/ia64/pci/pci.c:44-97`) | a non-zero status becomes `-EINVAL`, and `pci_scan_device` then treats the device as absent (`probe.c:1136-1137`); a read of `0xffffffff`, `0`, `0x0000ffff` or `0xffff0000` is also absent (`:1140-1142`). One dword read of register 0 per device number 0..31 of each bus, then header type and the rest of configuration space for devices found |
| 7 | `sn_io_late_init`, `fs_initcall`, `io_common.c:518-560` | for each PIC, TIOCP or TIOCE root bus: `sn_hwperf_get_nearest_node` (`sn_hwperf.c:963-977`), which on first use runs `sn_hwperf_init` (`GET_MASTER_NASID` `0x02000004` through `ia64_sn_get_console_nasid`, then `HWPERF_OP` `0x02000050`) and `ENUM_OBJECTS`, `ENUM_PORTS` | see [HWPERF_OP](../sal/sn2-runtime.md#hwperf_op-0x02000050) | failure only logs `sn_io_late_init: failed to find near node` and sets the bus's node to -1 (`:543-552`); it does not stop discovery |
| 8 | run time | `SN_SAL_IOIF_INTERRUPT` `0x0200004a` op 1 (alloc, MSI), 2 (free), 3 (redirect, `set_affinity`) | `irq.c:33-75` | not part of discovery. INTx devices arrive with their `sn_irq_info` already filled in (section 4) |

Not called on the 3.2 ACPI path (established, by reading both files): `SN_SAL_IOIF_GET_HUBDEV_INFO` `0x55`, `GET_PCIBUS_INFO` `0x56`, `GET_PCIDEV_INFO` `0x57`. `SN_SAL_IOIF_SLOT_ENABLE`/`DISABLE` (`0x53`/`0x54`) are hotplug only (`pcibr_provider.c:25-63`). `SN_SAL_IOIF_ERROR_INTERRUPT` `0x51` and `HUB_ERROR_INTERRUPT` `0x60` run from error handlers registered by `request_irq` during fixup (`pcibr_provider.c:145`, `huberror.c:189`), not at discovery.

**Order hazard for call 4 (unknown).** The kernel makes the flush-list calls (4) before `0x5f` (5). The PROM's per-device records are built by the first I/O call or by feature 3's segment-enable re-initialisation ([SN2 SAL runtime](../sal/sn2-runtime.md#io-interface-calls-0x51-to-0x5f-0x60-0x64)), and `0x5a` returns the PROM's own copy. Whether the PROM answers `0x5a` with status 0 for every (widget, device) on a lone node before `0x5f` has run is not settled in chips. A model that supplies the `hubdev_info` itself avoids the question by setting `widget_p = 0`.

## 4. The records the kernel copies, with offsets

All offsets are ia64, bytes. "Read" means the kernel consults the field after the copy; "kept" is copied and never inspected on this path.

### `hubdev_info`, `0x2f0` (752) bytes (`3.2.78:arch/ia64/sn/include/xtalk/hubdev.h:71-84`)

The kernel does `*hubdev = *hubdev_ptr` from the PROM's copy (`io_acpi_init.c:107-110`), so every byte is copied; `max_*` are not prefilled on this path.

| Offset | Field | Read by the kernel |
|---|---|---|
| `0x00` | `hdi_geoid` (12 bytes: module `u32`, type byte, slab (low nibble) and slot (high nibble) byte, then the union padding for the PCI-card member's bus and slot bytes) | `cnodeid_get_geoid` returns it (`io_common.c:404-410`); `geo_module`, `geo_slot` feed `sn_generate_path` (`:412-437`), the hotplug and system-controller device names |
| `0x0c` | `hdi_nasid` (`short`) | **Read, required**: `nasid_to_cnodeid(hdi_nasid)` picks the node's `NODEPDA` slot to copy into (`io_acpi_init.c:107-109`); bit 0 set means TIO (`io_common.c:164`); used by every REMOTE_HUB access in `huberror.c` |
| `0x0e` | `hdi_peer_nasid` | kept |
| `0x10` | `hdi_flush_nasid_list.widget_p` (pointer) | **Read**: non-null starts the 512 `0x5a` calls and the flush lists (section 3); the kernel replaces it with its own allocation (`io_common.c:177-179`) |
| `0x18` | `hdi_flush_nasid_list.iio_itte[8]` (64 bytes) | read at run time by the DMA flush code when `widget_p` is non-null (`pcibr_dma.c:278`) |
| `0x58` | `hdi_xwidget_info[16]`, `0x28` bytes each: `xwi_hwid` {mfg, rev, part} at +0 (12 bytes), `xwi_masterxid` at +12, `xwi_hubinfo` at +16, `xwi_hub_provider` at +24, `xwi_vertex` at +32 | `xwi_hubinfo` is overwritten for all 16 (`io_common.c:169-170`); `hdi_xwidget_info[bs_xid]` is linked into the bus soft (`:331-332`); `xwi_hwid.part_num` is read only by the TIOCX code (`tiocx.c:510-521`) |
| `0x2d8` | `hdi_nodepda` | overwritten by the kernel's own pointer later; kept |
| `0x2e0` | `hdi_node_vertex` | kept |
| `0x2e8`, `0x2ec` | `max_segment_number`, `max_pcibus_number` | not read on the ACPI path (only `io_init.c:109-114`) |

### `pcibus_bussoft` and `pcibus_info` (`pcibus_provider_defs.h:31-40`, `pcibr_provider.h:100-118`)

The ACPI path takes a pointer from the bus's `_CRS` vendor resource and `__va`s it (`io_acpi_init.c:157-158`). For a PIC or TIOCP bridge `pcibr_bus_fixup` then `memcpy`s `sizeof(struct pcibus_info)` = **184 bytes** from there (`pcibr_provider.c:130-135`); the PROM's bus object must therefore be at least that long. Other asic types copy nothing.

| Offset | Field | Read by the kernel |
|---|---|---|
| `0x00` | `bs_asic_type` (`u32`: 1 PPB, 2 PIC, 3 TIOCP, 4 TIOCA, 5 TIOCE) | **Read, required**: `>= 6` is "unsupported asic type" and the bus is not set up; 1 (PPB) returns early; otherwise selects `sn_pci_provider[]` (`io_common.c:296-312`). 2 for the PIC |
| `0x04` | `bs_xid` | **Read**: index into `hdi_xwidget_info[]` and `widget_p[]`; must be 0..15 (`io_common.c:331-332`, `pcibr_provider.c:165-167`). The PIC's widget number (15 on the base I/O PIC, [PIC page](../../devices/pic/README.md)) |
| `0x08` | `bs_persist_busnum` | passed back to SAL in `0x51` and matched against `sfdl_persistent_busnum` (`pcibr_provider.c:174-177`) |
| `0x0c` | `bs_persist_segment` | same; also the PCI domain the PROM numbered the bus |
| `0x10` | `bs_legacy_io` | **Read**: `sn_pci_get_legacy_mem` and the legacy port accessors add the uncached offset (`pci_dma.c:363`, `:397`, `:446`) |
| `0x18` | `bs_legacy_mem` | same |
| `0x20` | `bs_base` | **Read, required**: `NASID_GET(bs_base)` gives the node (`io_common.c:328`); `ioremap(REGION_OFFSET(bs_base), sizeof(struct pic))` becomes the register base (`pcibr_provider.c:136-138`); `SWIN_WIDGETNUM(bs_base)` for MSI (`msi_sn.c:55-58`). It is the node's small-window address of the widget: `(nasid << 38) \| 0x8_0000_0000 \| (widget << 24)` on SHub 1 ([SHub PIO windows](../../devices/shub_ii/README.md#pio-windows)) |
| `0x28` | `bs_xwidget_info` | overwritten by the kernel |
| `0x30` | `pbi_moduleid` | kept |
| `0x34` | `pbi_bridge_type` (`short`: 2 PIC, 3 TIOCP) | **Read, required**: every `pcireg_*` accessor panics for any other value (`pcibr_reg.c:30-42`) |
| `0x36` | `pbi_bridge_mode` | kept |
| `0x38` | `pbi_int_ate_resource` (`ate` pointer, `num_ate`, `lowest_free_index`) | reset by the kernel (`pcibr_provider.c:185-187`) |
| `0x50` | `pbi_int_ate_size` | **Read**: `kzalloc(size * 8)` for the ATE map; a failed allocation makes `bus_fixup` return NULL and the next line (`io_common.c:328`) dereferences it (`pcibr_provider.c:186-192`). Size is the PIC's internal ATE count: unknown here |
| `0x58` | `pbi_dir_xbase` | DMA mapping (`pcibr_dma.c:191`) |
| `0x60` | `pbi_hub_xid` (`char`) | DMA mapping: the SHub widget id the bridge targets (`pcibr_dma.c:96`, `:152`) |
| `0x68` | `pbi_devreg[8]` | DMA mapping: `PCIBR_DEV_SWAP_DIR` test (`pcibr_dma.c:120`) |
| `0xa8`, `0xac` | `pbi_valid_devices`, `pbi_enabled_devices` | kept |
| `0xb0` | `pbi_lock` | `spin_lock_init` by the kernel |

After the copy `bus_fixup` also: registers the shared error interrupt `SGI_PCIASIC_ERROR` (0x33) (`:145-150`), read-modify-writes the PIC widget control register at `bs_base + 0x20` to set `PCIBR_CTRL_PAGE_SIZE` (bit 21) because the pages are 16 KiB (`:155-159`, `pcibr_provider.h:89`, `io.h:42-45`), and links `sfdl_pcibus_info` in matching flush entries when `widget_p` is non-null (`:165-182`). These are PIC register accesses a model must accept; the register is [the PIC widget control register](../../devices/pic/README.md).

### `pcidev_info`, 128 bytes (`3.2.78:arch/ia64/include/asm/sn/pcidev.h:55-67`)

Copied whole from the pointer in the device's `_CRS` vendor resource (`io_acpi_init.c:213-219`; the PROM's record has only the first `0x60` bytes meaningful, the rest is overwritten).

| Offset | Field | Read by the kernel |
|---|---|---|
| `0x00` | `pdi_pio_mapped_addr[7]` (six BARs and the ROM) | ACPI path: **only element 6 (the ROM)** is read; non-zero means the PROM shadowed the ROM, and the kernel maps it and sets `IORESOURCE_ROM_BIOS_COPY` (`io_acpi_init.c:439-453`). BAR resources come from configuration space and the root bridge's `_CRS` windows, not from this array (the direct path uses it, section 6) |
| `0x38` | `pdi_slot_host_handle` | **Overwritten** on the ACPI path by `(domain << 40) \| host_devfn` (`io_acpi_init.c:407-412`), where `host_devfn` is the `_ADR` of the root bus's direct child that contains the device. `sn_pci_fixup_slot` then needs the host device to exist: `pci_find_bus(segment, 0)` and `pci_get_slot(bus, devfn)` (`io_common.c:245-248`), else a NULL dereference |
| `0x40`..`0x58` | `pdi_pcibus_info`, `pdi_host_pcidev_info`, `pdi_linux_pcidev` | set by the kernel (`io_common.c:250-254`) |
| `0x58` | `pdi_sn_irq_info` | **Read**: non-zero means the kernel `__va`s it and copies an `sn_irq_info` (`io_acpi_init.c:226-229`) |
| `0x60`, `0x68`, `0x70` | `pdi_provider`, `host_pci_dev`, `pdi_list` | set by the kernel |

### `sn_irq_info`, 112 bytes (`3.2.78:arch/ia64/include/asm/sn/intr.h:37-55`)

Copied whole when `pdi_sn_irq_info` is non-zero, else left zeroed. The kernel uses the record only if `irq_irq` is non-zero (`io_common.c:263`); a zero `irq_irq` frees it and the device has no SN interrupt.

| Offset | Field | Read by the kernel |
|---|---|---|
| `0x08` | `irq_nasid` (`short`) | **Read**: with `irq_slice`, `nasid_slice_to_cpuid` picks the target CPU (`irq.c:341-343`); a pair that maps to no CPU is a problem for `set_irq_affinity_info` |
| `0x0c` | `irq_slice` | same |
| `0x10` | `irq_cpuid` | set by the kernel |
| `0x14` | `irq_irq` | **Read**: `0x3c..0xe6` (`IA64_SN2_FIRST/LAST_DEVICE_VECTOR`, `intr.h:29-30`); `dev->irq`, the index into `sn_irq_lh[]` and `reserve_irq_vector` (`io_common.c:265`, `irq.c:354-355`) |
| `0x18` | `irq_int_bit` | **Read**: the PIC interrupt pin; negative means MSI (`pcibr_provider.c:201`, `irq.c:193`) |
| `0x20` | `irq_xtalkaddr` | **Read** when the interrupt is retargeted (`pcibr_provider.c:220`) |
| `0x28` | `irq_bridge_type` | **Read**: indexes `sn_pci_provider[]` for force and retarget (`irq.c:402`); 2 for the PIC |
| `0x30` | `irq_bridge` | **Read**: null skips the force-interrupt path (`pcibr_provider.c:203`); expected to be the bridge's `bs_base` |
| `0x38` | `irq_pciioinfo` | set by the kernel |
| `0x44`, `0x48`, `0x4c` | `irq_cookie`, `irq_flags`, `irq_share_cnt` | kept; `irq_cookie` is passed back to `0x4a` op 2 |

### `sn_flush_device_common`, 152 (`0x98`) bytes (`hubdev.h:32-46`)

Filled by the PROM into the buffer the kernel hands to `0x5a`; the `0x58` array is 32 entries of `0xa0` (this struct plus a `u32` filler, `hubdev.h:58-61`). Fields: `sfdl_bus` `+0`, `sfdl_slot` `+4` (-1 marks an unused entry; `pcibr_bus_fixup` skips it, `:172`), `sfdl_pin` `+8`, `sfdl_bar_list[6]` `+0x10`, `sfdl_force_int_addr` `+0x70`, `sfdl_flush_value` `+0x78`, `sfdl_flush_addr` `+0x80`, `sfdl_persistent_busnum` `+0x88`, `sfdl_persistent_segment` `+0x8c`, `sfdl_pcibus_info` `+0x90` (set by the kernel). Used at run time by the PIO-read DMA flush code (`pcibr_dma.c:255-300`) and not by discovery.

## 5. ACPI objects the ACPI path needs from the PROM

Established from the kernel code; whether SNPROM 10.54's tables supply each one is **unknown** (the PROM's AML has not been read; chips has only the namespace names `SGIHUB`, `SGITIO`, `_HID`, `_SEG`, `_BBN`, `_CRS`, `_PRT`, `_ADR`, `_SUN` from the builder's strings, [os-handoff tables](../firmware/snprom/os-handoff-tables.md)).

- **Hub devices.** A device with `_HID` `SGIHUB` (SHub, even NASID) or `SGITIO` (TIO) per node. Its `_CRS` must contain a large vendor-defined descriptor (tag `0x84`) whose body is 25 bytes: subtype 0, the 16 UUID bytes `2c c6 a6 fe 9c 44 da 11 a2 7c 08 00 69 13 ea 51` (`io_acpi_init.c:30-34`), then an 8-byte little-endian **physical address** of the `hubdev_info`. The length test is `byte_length - 17 == 8` (`:93-94`, `acpi_get_vendor_resource` at `3.2.78:drivers/acpi/acpica/rsxface.c:392-420`, match rule `:458-461`). A hub whose resource is missing or the wrong length is logged and skipped (`:79-102`), leaving the kernel's zeroed `hubdev_info` for that node (no NASID, so a later NULL path).
- **Root bridges.** One `PNP0A03` device per PIC bus (`pci_root.c:58`), with `_SEG` (the PCI domain; absent defaults to 0, a failing evaluation fails the bridge, `:466-473`), a bus range in `_CRS` or `_BBN` (`:475-499`), `_CRS` address windows that the ia64 scan turns into `pci_window`s and I/O port spaces (`arch/ia64/pci/pci.c:362-383`, `add_io_space` `:168-`), optionally `_PXM` for the node (`:356-360`) and `_PRT`. The root device's `_CRS` must also carry the vendor resource with the 8-byte pointer to the `pcibus_bussoft` (`io_acpi_init.c:136-158`); without it the bus is scanned but `sn_acpi_bus_fixup` logs "Unable to obtain prom_bussoft_ptr" and returns before the per-device fixup (`:471-478`).
- **Device nodes.** For every PCI **function** the root bus's scan finds, a child device whose `_ADR` is `(device << 16) | function`, found by walking the namespace under the root bridge and comparing `devfn` and the parent's `_BBN` against the `pci_dev` (`:299-345`), and whose `_CRS` has the vendor resource pointing at that function's `pcidev_info` (`:188-219`). **A function with no matching node is a `panic`** (`sn_acpi_slot_fixup`, `:434-437`); a segment mismatch between the root's `_SEG` and the domain, or a missing `_SEG`, is also a panic through the same path (`:364-383`). This matters for the PROM note that it builds one SSDT per function-0 device ([SN2 early boot](sn2-early-boot.md#io-discovery-in-sn2-kernels)): every device on the base I/O card is single-function, so the base I/O card is not affected, but a multi-function add-in card would be unless the PROM also names its other functions (inferred; that the PROM does not is itself unread).
- **The fixup runs for every bus**, not only the roots: `pcibios_fixup_bus` calls `platform_pci_fixup_bus` for each bus after its slots are scanned (`3.2.78:drivers/pci/probe.c:1512`, `arch/ia64/pci/pci.c:499-515`), and `sn_acpi_bus_fixup` applies `sn_acpi_slot_fixup` to every device on it (`:482-484`). A bridge behind which another bus exists has devices that match `_BBN` of their parent only if the PROM named them under the right parent; the base I/O card has no bridge, so this is not exercised.

## 6. The direct path (the fallback, 3.2.78 `io_init.c`)

Taken when `sn_acpi_rev < 0x20101`, for instance with `NoACPIIO` set. Calls, all `SAL_CALL_NOLOCK`:

1. `sn_fixup_ionodes` (`io_init.c:86-118`): per node `SN_SAL_IOIF_GET_HUBDEV_INFO` `0x55` with a1 = NASID, a2 = physical address of the node's `hubdev_info` (`sal_get_hubdev_info`, `:34-44`). The kernel first stores `max_segment_number = 0xffffffff` and `max_pcibus_number = 0xff` into the buffer. **The result it tests is v0, not status**: non-zero skips the node. On success, a non-zero `max_segment_number` in the reply means "the PROM supports segments" and both maxima become the loop bounds; zero keeps the defaults (segment 0, buses 0..255). A PROM that leaves the prefilled `0xffffffff` untouched yields `-1` as an `int` bound and an empty loop. Then `sn_common_hubdev_init`, with the flush-list calls of section 3 (call 4).
2. `sn_io_init` (`:367-377`): for each segment `0..max_segment_number` and bus `0..max_pcibus_number` (up to 256 per segment), `sn_pci_controller_fixup` (`:295-330`): `SN_SAL_IOIF_GET_PCIBUS_INFO` `0x56`, a1 = segment, a2 = bus, a3 = physical address of an 8-byte slot. v0 `> 0` means no such bus, the kernel moves on; v0 = 0 means the slot holds the physical address of a `pcibus_bussoft`. The kernel then calls `pci_scan_bus(busnum, &pci_root_ops, controller)`, which makes the config cycles of call 6.
3. Per found device, `sn_io_slot_fixup` (`:199-286`): `SN_SAL_IOIF_GET_PCIDEV_INFO` `0x57`, a1 = segment, a2 = bus, a3 = `devfn`, a4 = physical address of a zeroed `pcidev_info`, a5 = physical address of a zeroed `sn_irq_info`. Non-zero v0 is a `BUG_ON`. Here the kernel **does** use `pdi_pio_mapped_addr[0..6]`: each non-zero element with a non-empty BAR replaces `dev->resource[idx].start` with `((addr << 4) >> 4) | __IA64_UNCACHED_OFFSET` and builds a `pci_window` (`:229-283`). The bus gets two legacy windows from `bs_legacy_io` (64 KiB) and `bs_legacy_mem` (1 MiB) (`sn_legacy_pci_window_fixup`, `:127-149`).

The direct path takes `pdi_slot_host_handle` from the PROM as `segment << 40 | bus << 32 | devfn` (`io_common.c:245-246`, [SN2 SAL runtime](../sal/sn2-runtime.md#the-structures-behind-0x55-to-0x58)); the ACPI path rewrites it.

## 7. Lone-node Altix 350 base I/O: what the kernel will do

Setting: one node, one PIC on the riser (widget 15) with two buses, the IO9 base I/O card in the first slot. The card's devices, from [the base I/O page](../../platforms/sn2/altix-350-base-io.md): IOC4 (`10a9:100a`), QLogic ISP 12160 (`1077:1216`) at device 3 (established there, from the kernel's own variant test), and a gigabit Ethernet controller that the page infers to be a BCM5701 (`14e4:1645`) at device 4. Device numbers below are Linux device numbers (PIC configuration window `n` is device `n`). Only the ISP 12160's device number is established; the IOC4 at 1 and the Ethernet part at 4 are inferred from an Origin 350 capture ([base I/O page](../../platforms/sn2/altix-350-base-io.md#devices-on-the-pics-buses)).

**ACPI path (the one PROM 10.54 should select), call by call:**

1. Four `0x66` calls (0, 1, 3, 2), then two `0x65` calls (sets 0, 1). Expected replies: [SN2 SAL runtime](../sal/sn2-runtime.md#set_os_feature_set-0x02000066): status -1 for 0 and 1 (ignored), 0 for 3 and 2; set 0 returns `0xf`, set 1 returns -2 (the loop stops there). So `PRF_DEVICE_FLUSH_LIST` (bit 1) is set. Established for the kernel's reaction; the PROM values are as graded on the linked pages.
2. `ACPI  DSDT OEM Rev 0x20101` in the log.
3. For the one SHub (even NASID): the `SGIHUB` device is found, `hubdev_info` copied. Required values: `hdi_nasid` = the node's NASID; geoid for the node; `widget_p` either null (no flush calls) or non-null (then 512 `0x5a` calls, each status 0).
4. `0x5f` once, status 0, v0 0.
5. `acpi_init` (`subsys_initcall`) scans the namespace: one `PNP0A03` root per PIC bus (two on the base I/O PIC) and per root bus 32 device-number probes, each a `0x01000010` read of register 0 (size 4). Per bus, expected:
   - Bus 0 of the PIC (first scanned; the base I/O card's bus): devices 1 (IOC4), 3 (ISP 12160) and 4 (Ethernet) answer with their vendor and device ids; every other device number must answer all-ones or a non-zero SAL status. Each present device then gets the usual configuration reads (header type, class, BARs by write-all-ones-and-read, and so on) through `0x10`/`0x11`; the PROM has already sized and assigned the BARs ([PIC page](../../devices/pic/README.md#bar-sizing-and-window-assignment-0xffb36020-0xffb37520-0xffb37e70)), so the kernel reads assigned addresses and checks them against the `_CRS` windows.
   - Bus 1: add-in slots; empty is accepted.
   - Per found function, one `pcidev_info` (128 bytes read) whose `pdi_sn_irq_info` is non-null, with `irq_irq` in `0x3c..0xe6`, `irq_nasid` = the node, `irq_slice` = 0..3 (a CPU that exists), `irq_int_bit` in 0..7, `irq_bridge_type` 2, `irq_bridge` = the PIC base. The sibling-card pins (IOC4 pin 0, ISP 12160 pin 2, BCM5701 pin 3) are inferred, not established, for the Altix.
6. Per root bus: a `pcibus_info` of at least 184 bytes with `bs_asic_type` 2, `pbi_bridge_type` 2, `bs_xid` 15, `bs_base` the widget's small-window address (`bs_base + 0x20` is read and written), plausible `pbi_int_ate_size`, and `bs_persist_segment`/`bs_persist_busnum` matching what the `_SEG` and `_BBN` say (in segment mode the PROM gives each PIC bus its own segment, bus 0; [SN2 SAL runtime](../sal/sn2-runtime.md#the-structures-behind-0x55-to-0x58)). The numeric values the PROM uses on a 350 are unknown.
7. `sn_io_late_init`: one near-node search per bus, which may fail harmlessly.
8. Drivers: `ioc4` (module) binds `10a9:100a` and reads its variant by scanning the same bus (`ioc4_variant`: `1077:1216` at device 3 is an IO9); `qla1280` binds `1077:1216`; `tg3` binds the Ethernet controller.

**Direct path (fallback), the sequence:** `0x55` for NASID n (the `hubdev_info` of section 4, reply v0 = 0 with `max_segment_number` and `max_pcibus_number` set to the PROM's maxima); `0x56` for each (segment, bus) from (0, 0) up to the maxima, v0 = 0 and a pointer for the PROM's two PIC buses and v0 = 1 for every other number (so a model must return v0 = 1, not an error status, for a missing bus); config cycles as above; `0x57` for each (segment, bus, devfn) the scan found, v0 = 0 with a 96-byte `pcidev_info` (BAR PIO addresses non-zero for every implemented BAR so the kernel maps them) and a 80-byte `sn_irq_info` copy.

## Unknowns and routes

- Whether PROM 10.54's DSDT and SSDTs satisfy section 5 (UUID bytes, vendor resource length 25, `_SEG`/`_BBN`/`_ADR` values, `_CRS` windows). Route: dump the PROM's tables from a guest run (`/sys/firmware/acpi/tables`, or the `acpidump` equivalent) and decode the AML; or read the builder `0xffb58ca0` and `0xffb5c940` for the vendor-resource writer.
- Whether `0x5a` succeeds before `0x5f` (section 3). Route: the first `0x5a` status in a run, or `widget_p` in the dumped `hubdev_info`.
- The values the PROM puts in `bs_base`, `bs_xid`, `bs_legacy_*`, `pbi_int_ate_size` and the persistent bus and segment numbers for one PIC ([SN2 SAL runtime](../sal/sn2-runtime.md#the-structures-behind-0x55-to-0x58) lists these as unread).
- That a 3.2 guest reaches the namespace and PCI scan (section 2 is source reading only). Route: the guest's early log for `ACPI  DSDT OEM Rev`, the absence of `AE_NO_ACPI_TABLES`, and one `PCI: ...` root bridge line per PIC bus.
- Which device numbers the base I/O card's Ethernet controller and IOC4 use on an Altix 350 ([open questions](../../questions/altix-base-io-cards.md)).
- Not read: the MSI path (`msi_sn.c`), the hotplug driver, `tioce`/`tioca` and the TIOCX code, none of which a base I/O boot needs.

## Review

Independent review of chips commits `dafbf66` (this page), `fdcff0a` (the I/O discovery section of [SN2 early boot](sn2-early-boot.md#review)), `623bb57` ([HWPERF_OP and the console ring](../sal/runtime-services.md#review-of-the-hwperf-and-console-input-commits)), `ddbdaf7` ([IOC4 ATA](../../devices/ioc4/ata.md#review)) and `514d6e8` ([distribution install](altix-distro-install.md#review)), by a reader who wrote none of them, on 2026-11-16 at chips `c221eae` plus those commits. Kernel sources read: upstream Linux 3.2.78 and 2.6.5 from kernel.org, and the community linux-sn2 tree at 7.3-rc3 (read-only). The Debian archive was checked for the 3.2.78-1 image, its configuration and its patch series. The PROM addresses were not re-read: no Ghidra pass was run for this review, so every PROM-side grade in the five commits is unchecked here.

**Confirmed (this page).** Structure offsets and sizes, computed by hand from the 3.2.78 headers: `hubdev_info` `0x2f0` (xwidget entries 40 bytes, array at `0x58`, nodepda `0x2d8`), `pcibus_info` 184 (bridge type at `0x34`, `pbi_lock` at `0xb0`), `pcidev_info` 128 (`pdi_sn_irq_info` at `0x58`), `sn_irq_info` 112 (every row offset matches), `sn_flush_device_common` `0x98` and the `0xa0` war stride. `acpi_initialize_tables` clears the static array and `acpi_tb_parse_root_table` sets `current_table_count = 2` each pass (`tbutils.c:705`); DSDT and FACS sit in slots 0 and 1 (`tbfadt.c:253-257`, `tbxface.c:532-578`); `acpi_reallocate_root_table` and the resize copy the whole array; `ACPI_CA_VERSION 0x20110623`. The call order 0, 1, 3, 2 (`setup.c:378-387`), the DSDT OEM-revision gate `>= 0x20101`, the vendor `_CRS` descriptor (UUID bytes, `byte_length - 17 == 8`, tag `0x84`), the `0x5a` guard on `widget_p`, the `0x5f` panic, and the absence of any `0x55`, `0x56`, `0x57` call on the ACPI path (the only callers are in `io_init.c`; `0x64` is reached only from `/proc` reads in `sn_hwperf.c`). The IRQ range constants (`intr.h:29-30`). The direct-path rules (`0xffffffff` and `0xff` prefill, v0 tested, `0x56` v0 above 0 means no bus). The Debian 3.2.78-1 mckinley image SHA-256 and every `CONFIG_` value the page lists. ISP12160 at slot 3 on the IOC4's bus (`drivers/misc/ioc4.c:240-247`).

**Findings.**
1. Wrong sentence, not a blocker. "The only ACPI and ia64 patches are in the real-time feature set" is false. The 3.2.78-1 series also carries `features/all/cpu-devices` (`arch/ia64/kernel/topology.c` and the ACPI processor driver), `bugfix/ia64/hardcode-arch-script-output.patch`, `bugfix/all/PCI-PM-Runtime-make-PCI-traces-quieter.patch` (`drivers/acpi/pci_irq.c`) and `PCI-Add-pcie_flags_reg-to-cache-PCIe-capabilities-re.patch` (one line in `probe.c`, so `probe.c` line numbers are one off in the Debian build). None touches `arch/ia64/sn`, `arch/ia64/pci` or the table code. Fix: state that, and say the cited `probe.c` lines are upstream.
2. Overstated grade, not a blocker. Section 4 marks `irq_irq` "Read, required" for `0x3c..0xe6`. The kernel indexes `sn_irq_lh[]` with the value unchecked and `reserve_irq_vector` returns -EINVAL for an out-of-range vector, ignored by `sn_irq_fixup`. The range is the platform's vector window (`irq.c:275-276`). Fix: say the value must be non-zero and below `NR_IRQS`, and that the window is what the PROM's allocator is expected to use.
3. Consistency, not a blocker. [Distribution install](altix-distro-install.md) still grades Debian's `IA64_GENERIC` "inferred"; this page establishes it from the shipped config.

**Verdict.** Accept. No blockers.

**Not checked.** All PROM-side facts (SAL return values per feature set, `0x5a` and `0x5f` handler behaviour, the DSDT stamp rule); the first-pass table count and the FADT `X_DSDT` value; `pcibr_provider.c`, `io_common.c` and `irq.c` line numbers other than those quoted; the MSI, hotplug and TIO paths (the page does not claim them).
