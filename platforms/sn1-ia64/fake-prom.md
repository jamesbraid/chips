# SN1 IA-64: SGI's simulator fake PROM and the kernel that ran on it

This page records the firmware SGI's Linux tree used for an SN1 IA-64 node under its Medusa simulator (the fake PROM),
the kernel tags and configuration it was built for, and what the kernel and the simulator supplied around it. It takes no
measurement; every statement is read from SGI's published Linux sources or the mail and press cited. Platform background is in [README.md](README.md) and the processor-bus ASIC is in
[synergy.md](synergy.md).

Firmware. No SN1 IA-64 PROM image is held anywhere; the fake PROM is the one firmware the sources let us read in full, and
the Linux tree's own README says it was to be replaced by the real PROM. Everything below treats the fake PROM as the
firmware the simulated node ran and records what it needs underneath it. It says nothing about any shipped SN2 machine,
whose firmware is the PROM images in [software/firmware/snprom](../../software/firmware/snprom/README.md).

Grades follow the repository rules (see [AGENTS.md](../../AGENTS.md)): `established` means read in SGI's Linux platform
code at the version named, `inferred` means a reasoned reading, `unknown` means no source settles it. A line that rests
only on how the simulator was driven is marked "simulator" because it says what the simulator did, not what silicon does.

Source snapshots. All paths are in the Library's `linux-history` root. "v2.5.0" is commit `381ab1f5`, "v2.5.72" is
`1eba1937`. Both open with `read_library` by commit id.

## 1. Kernel and configuration

| Choice | Value | Why | Grade |
|---|---|---|---|
| Kernel | Linux v2.5.0 (`381ab1f5`) | The only snapshot whose SN1 kernel, fake PROM, static I/O inventory and run script were all read in full for this page. It is the tree the SN1 code was written against: the first mail to carry SN1 updates is the ia64 patch of 2000-12-14, and the Medusa options already sit in the 2.4.2 `config.in` (patch of 2001-02-10, `ratatoskr.run/lkml/2001/02/369465`). | established that it carries the code; inferred that it boots |
| Last tag with the option | probably v2.5.72 | The ia64 tree removed the SN1 menu entries on 2003-05-19 (mail "remove SN1 options from KConfig", `marc-linux-ia64-105590723705952`), but Linus's tree still held the SN1 directories at v2.5.72 and lost them in 2.5.73 with the ia64 pull of 2003-06-18. Whether v2.5.72's menu still offered SN1 was not probed. | inferred |
| System type | `CONFIG_IA64_SGI_SN1` (menu text "SGI-SN1") | `arch/ia64/config.in`, v2.5.0. `CONFIG_IA64_SGI_SN2` sits beside it in the same menu. | established |
| Processor | `CONFIG_ITANIUM`, not `CONFIG_MCKINLEY` | SGI's own account is that prototype hardware ran first-generation Itanium (see [README.md](README.md#product-or-prototype)). The config also offers `CONFIG_ITANIUM_BSTEP_SPECIFIC`; the simulator control file says `cpu_stepping A`. Which workaround set the simulated node ran with is unknown. | established for the choice; unknown for the stepping option |
| Cache line | 128 bytes (`CONFIG_IA64_L1_CACHE_SHIFT 7`) | Set under the SN1 branch of `config.in`. | established |
| Simulator support | `CONFIG_IA64_SGI_SN_SIM` in v2.5.0 `config.in` (named `..._SN1_SIM` in `setup.c`, `mmzone_sn1.h` and the 2.4.2 patch) | Turns on the simulator tests `IS_RUNNING_ON_SIMULATOR()` and the 8, 16 and 32 MB memory banks. The two spellings in one tree is a defect in the tree, not a choice. | established |
| Console | `CONFIG_SERIAL_SGI_L1_PROTOCOL` off | With it on (the default), the kernel speaks the L1 packet protocol to a system controller and `sc_command` returns "no message" under the simulator test, so no console path was read. With it off, `sn1_setup` registers a 16550 at the node's remote register space plus `0x80`, register stride 8 (`reg_shift 3`), baud base 124800. Whether the first choice has any working console under the simulator is unknown. | established for the code; unknown for the L1 path |
| Memory model | `CONFIG_DISCONTIGMEM`, `CONFIG_NUMA`, `CONFIG_PERCPU_IRQ`, `CONFIG_DEVFS_FS` forced on by the SN branch | `config.in`. | established |
| Boot disk | first IDE drive | `ROOT_DEV = 0x0301` in `sn1_setup`. | established |
| Command line | empty, unless the fake PROM was built with `BRINGUP` | Then `init=/bin/bash`. Whether the build defined it is not stated. | established for both branches; unknown which was used |

A second candidate tree is the 2.4 series. `linux-2.4.18-ia64-020722.diff.gz`, applied to vanilla 2.4.18, carries a fake
PROM and a Medusa defconfig (`arch/ia64/sn/configs/sn1/defconfig-prom-medusa`). It is the later of the two by patch
date: v2.5.0 predates the 2.5.2 ia64 patch of 2002-01-16, while 020722 is dated 2002-07-22. Its fake PROM is dated
later, but its contents have not been compared with the v2.5.0 copy described in [the fake PROM section](#2-the-fake-prom).
Neither tree is shown to boot in the sources read. The two have not been compared. Details and patch names are in
[the source evidence](../../evidence/sn1-ia64-sources.md#24-series-patches).

## 2. The fake PROM

### Which one, and how it is built and loaded

Use the v2.5.0 copy, directory `arch/ia64/sn/fprom/` (nine files: `README`, `Makefile`, `fpmem.c`, `fpmem.h`, `fprom.lds`,
`fpromasm.S`, `fw-emu.c`, `main.c`, `runsim`). It was renamed `arch/ia64/sn/fakeprom/` in v2.5.7. By v2.5.72 it has grown a
common SN1 and SN2 build, ACPI 2.0 tables (XSDT, SRAT, SLIT, MADT) in place of the RSDT-plus-SPIC pair, a `klgraph_init.c`
that can write a one-node KLCONFIG image, a `make fprom` target and a `vmlinux.sym` rule. The v2.5.72 copy was read
for what changed, not in full; use it only if a later kernel is chosen, because the tables it builds must match what that
kernel parses.

| Step | Fact | Source | Grade |
|---|---|---|---|
| Build | `make` in the directory builds `fprom` from `fpromasm.o main.o fw-emu.o fpmem.o` linked against the ia64 `lib.a`. The link script emits `elf64-ia64-little`, entry `_start`, text at `0x100000` (node 0 physical), `__gp` 2 MB above the end of data. | `fprom/Makefile`, `fprom/fprom.lds` | established |
| Position | It runs where it is loaded. It computes the node base from its own `ip` (`ip >> 33`), adds it to `gp`, every `movl` address it uses and every `.got` entry, so a copy loaded at offset `0x100000` of any node works. The text and the pointer tables it builds carry the node number. | `fpromasm.S` header comment and `_start` | established |
| Load | Place the `fprom` image at node physical `0x100000`, the kernel `vmlinux` at its own link addresses, and the node configuration table (below) at the node base. | `fprom/README`, `runsim` (`load fprom`, `load vmlinux`, `setenv LOADPC 0x00100000`) | established (simulator) |
| Entry | Every processor that exists starts at physical `0x100000` of the boot node. `r8` = index of the boot processor (0 for the first present one; the `fpromasm.S` header calls it "BSP cpu" and `sys_fw_init` counts it down over the present processors, while the fake PROM's `README` still says "GR[8] = # of cpus", which the code contradicts). `r9` = the kernel's entry address (the README example is `0xe000000000520000`), set on one processor only; the others leave the stored value alone. | `README` ("GR[9]"), `fpromasm.S` header, `fw-emu.c` `sys_fw_init`, `runsim` | established (simulator) |
| Why `r8` and `r9` | Medusa let the control file preset registers. A machine that cannot preset registers has to get the same values some other way. | `runsim` (`sr g 9 ...`, `sr pc ...`) | inferred |

### What it initialises, in order

All processors run `fpromasm.S` at once. In order:

1. Clear `psr.l`, flush the register stack, invalidate the ALAT (`invala`).
2. Write 0 to the processor interface's cached-alias size register, at `0x80000a0001000028` (`BR_PI_CALIAS_SIZE`; offset `0x28`
   in [devices/bedrock_pi](../../devices/bedrock_pi/registers.toml), field set there as `calias_size`).
3. Read the processor-number register at `0x80000a0001000020` (`BR_PI_SELF_CPU_NUM`, PI offset `0x20`, `cpu_num` in the same unit;
   result 0 to 3) and the Bedrock revision/identity register at `0x80000a0001600000` (the local block's `rev_id`, offset
   `0x600000` in [devices/bedrock_lb](../../devices/bedrock_lb/registers.toml); the fake PROM takes bits 39:32, the `node_id` field).
4. Build `cr.lid` = `node_id << 24 | cpu_num << 16`. So the `eid` field carries the processor number 0 to 3 and its bit 1 is the
   Synergy, bit 0 the bus slot, as [README.md](README.md) already records.
5. Set `ar.fpsr`, the stack and the `.got` (one processor does the `.got` fix-up under an `xchg8` lock, the others spin on it).
6. Set `ar.k0` (the I/O port base) to `0x00000a0000000000`, labelled in the source as the "inverse swizzled" I/O-space base. The same
   comment notes that on the Intel 460GX chipset the value would be `0x00000ffffc000000`.
7. Call `fmain(lid, bsp)` in `main.c`, which:
   - picks, per Synergy, one processor to run `synergy_init`: it writes all-ones to the eight 64-bit words at offsets `0x2a0` to
     `0x2d8` (the vector masks, "enable all FSB flashed interrupts"), then writes `(nasid << 16) | (synergy << 9)` to offset
     `0x450` of the same space, which the comment calls `FSB_CONFIG`. The base is `0x80000e0000000000`, which is physical `0xe0000000000`
     (`SSPEC_BASE`). Recorded in [synergy.md](synergy.md).
   - picks, per node, one processor to run `bedrock_init`, which is an empty function in v2.5.0 (and in v2.5.72, where a
     disabled call to `klgraph_init` sits inside it).
   - picks one processor overall to run `sys_fw_init`, which builds the tables below; the others wait on a flag.
8. Set the eight region registers: regions 0 to 6 with the VHPT-walker enable bit set, region 7 clear, page-size code 13, region id equal to the region number.
9. Clear `cr.tpr`. A processor that `fmain` says is not the boot processor jumps to the `slave` loop (below).
10. On the boot processor: protection keys 1 to 15 cleared, key 0 valid; insert one 256 MB instruction translation and one data
    translation mapping virtual `0xe000000000000000` to the physical base of the node it was loaded on, write-back, with
    `psr` bits BN, AC, IT, DB, DA, RT, DT, IC; load `cr.ipsr`, put `bsp_entry_pc` (from `r9`) in `cr.iip`, and `rfi` into the kernel.

Established: all of the above, `fprom/fpromasm.S` and `fprom/main.c`, v2.5.0.

Not done by the fake PROM, so absent unless the simulator or the kernel supplies it: no Bedrock register other than the one PI write, no
Crosstalk, XBow, Bridge or IOC3 setup, no router or network setup, no UART programming, no memory controller setup, no clock
setup, no KLCONFIG or KLDIR build (v2.5.0), no flash, no NVRAM, no L1 contact.

### Tables it builds (boot processor, `sys_fw_init` in `fw-emu.c`)

All inside one static buffer in the fake PROM's own bss, with node numbers folded into every pointer.

| Table | Content | Grade |
|---|---|---|
| `ia64_bootparam` | At the zero page of the boot node (`ZERO_PAGE_ADDR + nasid << 33`; v2.5.72 names the address `BOOT_PARAM_ADDR 0x40000`, v2.5.0's value was not opened, so `0x40000` is inferred for v2.5.0): EFI system table, memory map pointer, descriptor size 16-byte aligned, descriptor version `0x101`, command line pointer, console 80 by 25 at row 24, no PCI vectors, `fpswa` 0. | established |
| EFI system table | Revision constants from the headers, `fw_vendor` "Silicon-Graphics" (UTF-16), firmware revision 1, two configuration tables: the SAL system table GUID and the ACPI table GUID. | established |
| EFI runtime services | `get_time` returns the fixed time 2000-02-13 10:11:12 (resolution 10, accuracy 12); `set_virtual_address_map` converts the services' pointers to region 7 addresses; `reset_system` spins forever; `set_time`, `get_wakeup_time`, `set_wakeup_time`, `get_variable`, `get_next_variable`, `set_variable`, `get_next_high_mono_count` return "unsupported". | established |
| EFI memory map | For each node and each of its 8 banks that is present: a descriptor of type conventional memory, write-back, physical address `nasid << 33 \| bank << 30`, size from the bank's size nibble. Bank 0 is first split: its first 4 MB on node 0 (1 MB on every other node) become a `runtime services data` descriptor, to hide the kernel and the fake PROM. A bank that ends exactly at 4 GB loses its top 20 MB (the "node 0 hole"). The descriptor buffer holds `8 * 32` (256) descriptors and `build_efi_memmap` does not check the count. | established |
| ACPI | RSDP "RSD PTR ", RSDT with OEM id "SGI", OEM table id "SN1", revision `0x00010001`, one entry pointing at a table signed "SPIC " that holds one local-SAPIC entry per present processor: enabled and present, processor id `cnode * 4 + cpu`, `eid` = cpu, `id` = nasid. | established |
| SAL system table | Signature "SST_", SAL revision 0.1, OEM "SGI", product "SN1", three descriptors: entry point (PAL and SAL procedures, gp), PTC coherence domains, AP wake-up. | established |
| SAL PTC domains | One domain per two present processors of a node (`cnode * 4 + cpu / 2`), each listing `id`=nasid, `eid`=cpu. The kernel reads it only to decide whether to force uniprocessor mode (the `PTC_NOTYET` path that would use it is compiled out). | established |
| SAL AP wake-up | Mechanism: external interrupt, vector 18. | established |

### Services it answers

PAL, through `pal_emulator_static` (called by static convention, index in `r28`):

| PAL call | Returns | Grade |
|---|---|---|
| `PAL_PTCE_INFO` (6) | status 0; `base 0x500000000`; counts `0x0000000200000003`; strides `0x1000000000002000` | established (values); inferred (field packing) |
| `PAL_FREQ_RATIOS` (14) | status 0; processor `0x100000064`, bus `0x100000100`, ITC `0x10000000a` | established (values) |
| `PAL_MC_DRAIN` (22), `PAL_MC_EXPECTED` (23) | status 0 | established |
| everything else | status -1 | established |

Inferred, from the HP pal header layout (denominator in the low word, numerator in the high word): the ITC ratio is 1/10, so the
kernel's interval-timer frequency is the SAL platform base times 1/10, which is 50 MHz. This was not traced through
`arch/ia64/kernel/time.c`.

SAL, through `sal_emulator`:

| SAL call | Returns | Grade |
|---|---|---|
| `SAL_FREQ_BASE` (platform) | 500,000,000 | established |
| `SAL_FREQ_BASE` (interval timer) | 700,000,000 | established |
| `SAL_FREQ_BASE` (real-time clock) | 1 | established |
| `SAL_SET_VECTORS` with `SAL_VECTOR_OS_BOOT_RENDEZ` | stores the entry point and gp for the AP; any other vector id returns -1 | established |
| `GET_STATE_INFO`, `GET_STATE_INFO_SIZE`, `CLEAR_STATE_INFO`, `MC_RENDEZ`, `MC_SET_PARAMS`, `CACHE_FLUSH`, `CACHE_INIT`, `UPDATE_PAL` | status 0, no outputs | established |
| any other index, including the three SGI calls (`0x02000001` to `0x02000003`) | status -1 | established |

The last row matters: the kernel's I/O probe call returns "bad argument" from this firmware. The simulator path never needed it
(see section 4).

### Secondary processors

A processor that is not the boot processor loops in `slave:`: it executes a `nop.i 0x8beef` (a Medusa-only hint that puts the
simulated processor to sleep until an interrupt arrives), reads `cr.irr0` until non-zero, reads `cr.ivr`, writes `cr.eoi`, loads
`ap_entry` (pc, gp) as set by `SAL_SET_VECTORS`, and branches to it. It does not check that the interrupt was vector 18.
On any other machine the hint is a plain no-operation and the loop spins on `cr.irr0`.
Established, `fpromasm.S` v2.5.0. Established as simulator-only: the hint's meaning, from the comment.

### The node configuration table

The fake PROM does not read hardware to learn the topology. A table at the node base is read by `build_init`
(`fpmem.c`), written by the simulator's `sm` memory-write command from the control file (`runsim`):

```
node base + 0     : 32-bit processor count, 32-bit node count
node base + 8 + 8n: for node n: 16-bit nasid, 16-bit processor mask, 32-bit bank descriptor
```

The bank descriptor is the same bit layout as the SN1 memory-configuration register word the kernel header describes
("Medusa supports this reg config", `mmzone_sn1.h`): per bank pair, bits `[0]` and `[1]` bank present, size nibble in
bits 7:4 (and likewise 8-9/15:12, 16-17/23:20, 24-25/31:28 for the next pairs). Size nibble 1 to 5 is 64 MB to 1 GB;
under the simulator build `0xc`, `0xd`, `0xe` mean 8, 16, 32 MB. `runsim` documents the same word as `0xBSBSBSBS` and defaults
node 0 to `0xe1` (one 32 MB bank 0) with processor mask 1 for the kernel case. The fake PROM's own README describes memory
passed in `GR[20]` to `GR[23]` as hex digits of 8 MB times a power of two; the code reads the table, so that README paragraph
is out of date for v2.5.0. Established, `fpmem.c`, `fpmem.h`, `runsim`; the README discrepancy is a reading of the two files.

### What Medusa supplied that silicon would have to

| Item | What the simulator did | Source | Grade |
|---|---|---|---|
| Topology table | Wrote it into node memory before the first instruction. | `runsim` `sm` lines | established |
| Start state | Set `pc` to `0x100000` on each present processor (a `setnode`/`setcpu` pair per processor) and `r9` on the first. | `runsim` | established |
| Console | `tsconsole on`, `uart_echo on`. A simulated UART whose register stride and base were decided by the simulator. | `runsim` header | established (settings); unknown (model) |
| Disk | IDE drive, 611 cylinders, 16 heads, 63 sectors per track, `diskPath idedisk`, boot drive C. | `runsim` | established |
| Partial Intel chipset | `partialIntelChipSet on` and `printIntelMessages off`. The ia64 port reaches the disk through legacy port numbers (below), so the simulator modelled enough of an Intel IA-64 reference chipset for IDE and probably PCI configuration. How much is not stated. | `runsim`, `sn1/iomv.c` | established (setting); unknown (extent) |
| Cache and coherence model | `coherency_type nasid`, `cpu_cache_type default`, `synergy_cache_type syn_cac_64m_8w` (a 64 MB, 8-way Synergy cache by the setting's name). | `runsim` | established (settings); inferred (reading of the name) |
| Network | `network_type xbar` with `route_enable on`: nodes joined by a plain crossbar, no routers modelled. | `runsim` | established |
| CPU | `cpu_stepping A`, `low_power_mode on`, `swizzling on`. | `runsim` | established |
| Simulator identity | `mov r=cpuid[2]` returns a magic value (`SNMAGIC`), the switch behind `IS_RUNNING_ON_SIMULATOR()` (`sn1/setup.c`). The constant is defined in a header the Library's v2.5.0 index does not hold. The later SN2 `simulator.h` gives `0xaeeeeeee8badbeef`. | `sn1/setup.c`; `arch/ia64/include/asm/sn/simulator.h` | established that the test exists; inferred that the v2.5.0 value equals the later one |

The real PROM's reset vector and image placement (`0x80000000ff800000` for 8 MB, `0x80000000ffc00000` for 4 MB images, load
pc `0x80000000ffffffb0`) appear in the same script for the PROM runs. Those PROM images (`SN1IA` builds) are not held and are
not needed for the fake-PROM target.

## 3. What the kernel does under the simulator test

The simulator flag changes three things on the path to a shell, all established in v2.5.0:

- `sn1_io_addr` (`sn1/iomv.c`): legacy port numbers `0x1f0` to `0x1f7`, `0x3f6`, `0x3f7` (the first IDE channel) become uncached memory
  accesses at `0x00000FFFFC000000 | ((port >> 2) << 12) | (port & 0xfff)`. Examples: port `0x1f0` is `0xffffc07c1f0`, `0x1f7` is
  `0xffffc07d1f7`, `0x3f6` is `0xffffc0fd3f6` (offsets from node 0; the kernel adds the uncached region base). Every other port is
  the I/O port base (`ar.k0`, `0x0a0000000000`) OR the port with the low two bits cleared. On hardware the same code uses
  `port | uncached offset`.
- `sn1_pci_find_bios` (`io/pci.c`): after running the whole SGI I/O infrastructure (section 4) it returns without installing the
  SN PCI configuration operations, so Linux's default configuration path is used. `sn1_pci_fixup` prints "not supported on
  simulator" and returns. So PCI bus enumeration is outside SGI's Bridge code in a simulator run.
- Crosstalk probing (`io/xbow.c`): `xbow_widget_present` answers yes for ports 14 and 15 and no for the rest, without reading the
  crossbar. L1 calls (`sc_command`) return "no message" and `hubspc_init` does not start the L1 link.

None of this changes the processor start path or the interrupt path.

## 4. What the kernel touches at boot

The order is the order in `sn1_setup`, `init_smp_config`, `sn1_pci_fixup(0)` and `sgi_master_io_infr_init`. "Held" means a unit
in this repository documents it.

| Unit and access | Where | Held in chips | Not settled by the sources read |
|---|---|---|---|
| Itanium CPU: PAL and SAL calls, `cr.lid`, `cr.ivr/irr/eoi`, `cpuid[2]`, TLB, region registers | fake PROM; `sn1/setup.c` | no (architecture manual territory) | the SN1 `cpuid[2]` value and `cr.lid` behaviour, which the fake PROM and the simulator supplied |
| Memory: 8 banks per node, 64 MB to 1 GB, node at `nasid << 33`, kernel text at node 0 | EFI map; `sn1/mm.c`, `sn1/discontig.c` | yes: [devices/bedrock_md](../../devices/bedrock_md/registers.toml), memory-bank encoding | none, the kernel reads no memory-controller register for this; the descriptor comes from the EFI map |
| PI: cpu number (`0x20`), cached-alias size (`0x28`), interrupt pending bits `PI_INT_PEND0/1` and the set/clear register (`PI_INT_PEND_MOD`, set = `0x100 \| level`), IPI stores at `+0x80/+0x88` of each PI | fake PROM; `sn1/error.c`, `sn1/irq.c`, `sn1/smp.c`, `intr.h` | yes: [devices/bedrock_pi](../../devices/bedrock_pi/registers.toml) | IPI registers `ipi_a`, `ipi_b` are recorded there with source named; the delivery path to an Itanium (delivery mode, vector) is not described anywhere |
| LB: revision and node id (`0x600000`), the local-block registers `hubmd`/`hublb` | fake PROM; `ml_SN_init.c` | yes: [devices/bedrock_lb](../../devices/bedrock_lb/registers.toml) | none for the fake PROM's read |
| Synergy: eight vector-mask registers (`0x2a0` to `0x2d8`), `FSB_CONFIG` at `0x450`, optional performance registers (`0xab0` to `0xaf8`) | fake PROM; `sn1/synergy.c` | partial: [synergy.md](synergy.md) | `FSB_CONFIG` field layout beyond the two written fields, behaviour on read of every other offset, reset values, how a local access chooses its Synergy (solved by construction: it is the one on the issuing bus, [synergy.md](synergy.md)) |
| Interrupt delivery: pending bit `b` becomes vector `b + 64` for the processor whose Synergy mask bit is set | `sn1/irq.c`, `sn1/synergy.c` | partly: the bit meanings are in the PI page | the delivery rule from pending bit to Itanium vector, priority, which slot is chosen when both are enabled |
| Hub per-node init, interrupt clear-all, hub devices (memory reference counters), hub error interrupt | `sn_mp_setup`, `per_hub_init`, `intr_clear_all`, `hubspc_init`, `huberror.c` | yes for the MIPS view | the exact registers these functions touch under this kernel were not enumerated; route: read `ml_SN_init.c`, `ml_SN_intr.c`, `hubspc.c`, `mem_refcnt.c`, `huberror.c` in v2.5.0 |
| Console: 16550 at remote register space `+0x80`, stride 8, or L1 | `sn1_setup`; serial driver | UART block yes (hub offset `0x220080`), L1 yes in sysco | the relationship of the two addresses, see the [question](../../questions/sn1-ia64-bedrock-uart-location.md); the serial-driver hack that reads `master_node_bedrock_address` was not opened (that driver is not in the Library's index) |
| Disk: IDE legacy ports (above) | `sn1/iomv.c` | no | the IDE controller behind the port window, which the simulator's partial Intel chipset supplied; the 460GX-style window base is in the fake PROM comment, not a hardware fact |
| Crosstalk: XBow widget id and link registers, Bridge and XBridge on widgets 14 and 15 | `sgi_master_io_infr_init`, `xbow.c`, `pcibr.c` | yes: [devices/xbow](../../devices/xbow/registers.toml), [devices/bridge](../../devices/bridge/registers.xbridge.toml) | **open**: the widget attach path runs before the simulator early return (`sgi_master_io_infr_init` is called first), and a Bridge is selected by widget part number read from the widget. The simulator must therefore have answered that read and the register traffic of `pcibr_attach`. Which registers were touched was not enumerated |
| IOC3 | `klgraph_hack.c`, `sgi_io_sim.c`, `pci.c` | yes: [devices/ioc3](../../devices/ioc3/registers.toml) | on the simulator path `ioc3_init` is an empty function and the IOC3 fix-up is under `REAL_HARDWARE`, so it is expected not to be touched. Inferred |
| KLCONFIG | `klgraph_hack.c` reads physical `0x30000` of node 0 for magic `0xbeedbabe`; if absent it builds a one-node static inventory | structure in [README.md](README.md) (the KLDIR and KLCONFIG paragraph) | With v2.5.0 the fake PROM writes none, so the kernel's stand-in is used. The stand-in: a node board (hub, memory, UART, two processors), an I/O brick with a crossbar, and at least a board with an XBridge (part `0xd002`, widget 14); the remaining components were not read |

The smallest configuration the sources describe is one node: `runsim` defaults to one node, 32 MB, processor
mask 1 (one processor). A second processor takes a second `cr.lid`, a wake-up path (PI `+0x80` or `+0x88` store, vector 18) and
a second slice. The kernel stand-in lists two processors on its node board.

## 5. Open points

1. What the simulator answered for the Bridge and XBridge on widgets 14 and 15 during the kernel's I/O init, which runs before
   the simulator early return. Without this the kernel's attach routines may spin or fault. Route: read `pcibr_attach`,
   `xbow_init`, `init_all_devices` and their callees in v2.5.0 for the register list; no run is needed.
2. Whether and how the PCI configuration access that Linux's default code uses is served (the partial Intel chipset). Route: read
   `arch/ia64/kernel/pci.c` and `arch/ia64/pci` at the v2.5.0 commit.
3. The serial path the early console and the 16550 hack take (`drivers/char/serial.c`, `kernel/printk.c` at v2.5.0, not in the
   Library's index). Route: open them by commit id.
4. The meaning of the written `FSB_CONFIG` fields and the rest of the Synergy register file. No source; see the
   [question](../../questions/sn1-ia64-synergy-registers.md).
5. The exact registers `per_hub_init`, `mlreset`, `intr_clear_all` and `hubspc_init` touch. Route: read them.
6. Whether the fake PROM build defined `BRINGUP` and which compiler could build it. The 1999-era egcs workaround in `fw-emu.c`
   ("`id`") suggests an early ia64 egcs; the build host the sources need is unknown.

## Review

The page originally also carried an assessment of what an emulated node would need and a list of 15 numbered checks; those were removed from this page, and the review's remarks on the checks below record which source facts they rested on.

Independent review, 2026-11-14, by a reviewer who wrote none of these pages. Reviewed chips revision a399d6d (pages from 842b367, 55a5bcc, f5ab671 and the earlier SN1 IA-64 commits through 15a5a4e). Sources read from the Library root `linux-history` at commit 381ab1f5 (v2.5.0) with `read_library`: `arch/ia64/sn/fprom/{main.c,fpromasm.S,fpmem.c,fw-emu.c,README,fprom.lds}`, `include/asm-ia64/sn/{synergy.h,sn_cpuid.h}`, `arch/ia64/sn/sn1/{smp.c,irq.c}`, `arch/ia64/config.in`, `arch/ia64/sn/io/klgraph_hack.c`. Tag commit ids checked with `git ls-remote --tags` on kernel.org's history.git (v2.5.0 381ab1f5, v2.5.6 50b1b006, v2.5.7 085c9a18, v2.5.40 7570df54, v2.5.72 1eba1937, v2.5.73 6c7a48fb). Press pages fetched 2026-11-14.

Checks, confirmed: fake PROM linked at `0x100000` (`fprom.lds`), runs relocated by node base (`fpromasm.S` header and `_start`); `r8` and `r9` entry state; the exact `_start` order (CALIAS size `0x80000a0001000028` written 0 first, then `BR_PI_SELF_CPU_NUM` `...20` and revision register `...1600000` with `extr.u 32,8`, LID = `nasid<<24 | cpu<<16`, `ar.k0` `0x00000a0000000000`, `fmain`, region registers with the walker bit set for 0 to 6 only, `cr.tpr` clear, 256 MB translations at `0xe000000000000000`, `rfi`); `fmain` and `synergy_init`; the slave loop; `sys_fw_init` tables (vendor string, SAL 0.1, `SGI`/`SN1`, `SPIC`, AP wake-up external interrupt vector 18, PTC domain `cnode*4+cpu/2`, boot parameter block 80 by 25, row 24, `fpswa` 0, version `0x101`); `build_efi_memmap` (bank paddr `nasid<<33 | bank<<30`, 4 MB then 1 MB runtime-services hole in bank 0, the 20 MB hole under 4 GB), so check 5 (a `0xe1` node: 4 MB runtime data then 28 MB conventional) holds; `SAL_FREQ_BASE` values; SAL and EFI return values; the `klgraph_hack.c` read of `0xe000000000030000` for `0xbeedbabe`, falling back to a built header; `CONFIG_IA64_SGI_SN1` and the other config rows. The PI offsets `0x20` and `0x28` and `node_id` bits 39:32 match `devices/bedrock_pi` and `devices/bedrock_lb`. Of the 15 checks, 1, 2, 3, 5, 6, 7 (value arithmetic), 11, 13, 14 and 15 each tie to a source fact that was read; 4 ties to `sys_fw_init`. Checks 8, 9, 10 and 12 cite `io/pci_bus_cvlink.c`, `xbow.c`, `l1.c`, `iomv.c` and `synergy.c`, which were not re-read; they are marked as simulator-dependent or pointers by the page itself.

Findings:
1. Mechanical, fixed: the "Entry" row cited the fake PROM `README` for `r8`, but the README says `GR[8] = # of cpus`, the code and the `fpromasm.S` header say it is the boot processor; the row also gave `r9` to every processor while `runsim` and the code set and use it on one. The row now says both.
2. Mechanical, fixed: the memory-map row said "at most `1 + 8 * 128`" descriptors; the code's buffer is `8 * 32` descriptors with no bound check.
3. Not edited: the README's "memory in GR[20] to GR[23]" paragraph is already noted as out of date; its `GR[8]` line is the same kind of stale text.
4. Not edited: `bit_pos_to_irq` and `irq_to_bit_pos` (see the Synergy review, finding 2) bear on check 11.

Cleared scope: the fake PROM build, load and entry facts, its register writes (PI `0x20` and `0x28`, Synergy `0x2a0..0x2d8` and `0x450`), the tables it builds, services it answers, and checks 1 to 3, 5 to 7, 11 and 13 to 15. Not cleared: checks 4, 8 to 10 and 12 until their source files are re-read; the section 4 "unit and access" table where it says what the kernel touches without opening `ml_SN_init.c` and friends (the page says so).
