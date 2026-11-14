# SGI SN1 on IA-64: where the Linux source lives and how long it lasted

The Library root `linux-history` holds SGI's Linux port to the Bedrock-based IA-64 node ("SN1", also spelled SNIA
or SNI64 in the code). This page lists every file of that port the Library can show, the kernel versions each lived in,
and what hardware it describes. SGI's own Linux platform code ranks with the IRIX source as vendor source, so a fact it
defines is `established` (rule: the SN2 program's evidence rule, confirmed for SN1 as well). The hardware reading is in
[platforms/sn1-ia64/README.md](../platforms/sn1-ia64/README.md).

## How the files were found

- `linux-history` carries two snapshots the full-text index can search: a v2.5.0 tree (repository name `linux-2.5.0`)
  and the tip of kernel.org's history repository (about v2.6.12, where only SN2 remains). Any other revision opens
  with `read_library` or `resolve_library` given a commit id, but is not searchable. Tag-to-commit ids came from
  `git ls-remote --tags` on the public `history.git` (ref names only, nothing cloned).
- The 157 files below are every file under `arch/ia64/sn/` and `include/asm-ia64/sn/` in the v2.5.0 snapshot. The index
  of that snapshot holds only those two directories. Files elsewhere that name SN1 are not enumerated. One was found by
  name and checked: `include/asm-ia64/machvec_sn1.h`. Others (`arch/ia64/config.in`, `arch/ia64/Makefile`) were opened
  directly. A kernel-wide list of SN1 touch points is unknown.
- `history.git` starts at v2.5.0, so anything older than that is dated from mail only.
- File contents were read from the Library's own text-search service for the v2.5.0 snapshot. Line counts below are
  from that snapshot.

## Version range (established unless marked)

Probes are `resolve_library` results for a path at a tag's commit.

| Tag (commit) | What exists | Source |
|---|---|---|
| before v2.5.0 | SN1 code is in the ia64 patch series by 2000-12-14 ("various SGI SN1 updates" in the 2.4.0-test12 patch). File headers carry 1999 and 2000 copyrights. No earlier history is held. | mail `marc-linux-ia64-105590678205848` (2000-12-15) |
| v2.5.0 (`381ab1f5`) to v2.5.6 (`50b1b006`) | Original layout: `arch/ia64/sn/sn1/`, `arch/ia64/sn/io/pcibr.c`, `arch/ia64/sn/fprom/`, `include/asm-ia64/sn/` with `sn1/`. `arch/ia64/sn/sn1/setup.c` is 6938 bytes at v2.5.0, v2.5.5 and v2.5.6. | probe |
| v2.5.7 (`085c9a18`) | Reorganised, not removed. `arch/ia64/sn/sn1/` and `io/pcibr.c` are gone; `arch/ia64/sn/kernel/sn1/` exists; `include/asm-ia64/sn/synergy.h` has moved to `include/asm-ia64/sn/sn1/synergy.h`. | probe |
| v2.5.40 (`7570df54`) | `arch/ia64/sn/io/sn1/pcibr.c` (232773 bytes), `include/asm-ia64/sn/sn1/` (the 27-header set the chips pages cite), `arch/ia64/sn/kernel/sn1/`. `arch/ia64/sn/sn1/` absent. | probe |
| v2.5.60 to v2.5.72 (`1eba1937`) | Still present: `io/sn1/pcibr.c` (225239 bytes at v2.5.70-71), `include/asm-ia64/sn/sn1/hubio.h` (167922 bytes, same as v2.5.40), `kernel/sn1/synergy.c` (13165 bytes), `arch/ia64/sn/fakeprom/` (the renamed `fprom`). | probe |
| v2.5.73 (`6c7a48fb`) | SN1 gone: no `io/sn1/pcibr.c`, no `kernel/sn1/`, no `include/asm-ia64/sn/sn1/`. Only the shared headers that SN2 reused (for example `klconfig.h`) and `include/asm-ia64/machvec_sn1.h` remain. | probe |
| 2003-05-19 | "remove SN1 options from KConfig". | mail `marc-linux-ia64-105590723705952` |
| 2003-06-18 | The ia64 maintainer's "initial sync with 2.5.72" pull lists `arch/ia64/sn/io/sn1/pcibr.c` (7704 lines removed) and other `io/sn1/` files as deleted from the ia64 tree. | mail `marc-linux-ia64-105592269615698` |
| 2003-08-31 | An SGI engineer, against the 2.4 tree: "delete some remnants of support for the SGI SN1 platform" in `config.in`. So the 2.4-line ia64 tree kept an SN1 option until then. | mail `marc-linux-ia64-106233674100576` |
| 2003-09-27 to 2004-01-27 | Last SN1 file `include/asm-ia64/machvec_sn1.h` removed ("SN1 support was removed from the tree a long time ago", a kernel developer, 2003-09-27; resent 2003-11-03 and 2004-01-22; merged in the pull of 2004-01-27). | mail `marc-linux-ia64-106467195826288`, `marc-linux-ia64-106788416532540`, `20040122181150.GZ15871@localhost`, `200401270137.i0R1bEqF012062@napali.hpl.hp.com` |
| tip of `linux-history` (about v2.6.12) | None of the SN1-only paths exist. `arch/ia64/sn/` holds SN2 only. | search of the tip repository |

Not settled: the exact mainline commit that removed the SN1 directories (between v2.5.72 and v2.5.73; the Library
holds no log), and the first mainline version that carried SN1 (the 2.4 series was the ia64 patch tree's, and
`history.git` does not reach back that far).

Per-file ranges: only the directories and files named above were probed at each tag. The table below gives the
v2.5.0 path of every file. Treat each as present from v2.5.0 (or earlier) to v2.5.72, with the v2.5.7 move of SN1-only
code into `sn1/` subdirectories. Files that SN2 reused kept existing after v2.5.73 in changed form; which ones was not
checked file by file.

## Files (v2.5.0 paths)

| Path | Lines | Hardware or role |
|---|---|---|
| `arch/ia64/sn/Makefile` | 20 | Kbuild glue for arch/ia64/sn (builds io, sn1, fprom). |
| `arch/ia64/sn/fprom/Makefile` | 32 | Builds the fake PROM image. |
| `arch/ia64/sn/fprom/README` | 86 | How to build and boot the fake PROM under SGI's Medusa simulator; GR8 CPU count, GR20-23 per-node memory config. |
| `arch/ia64/sn/fprom/fpmem.c` | 201 | Builds the EFI memory map from the node/bank table (8 banks per node, node address bit 33). |
| `arch/ia64/sn/fprom/fpmem.h` | 36 | Layout of the CPU and memory configuration handed to the fake PROM. |
| `arch/ia64/sn/fprom/fprom.lds` | 97 | Linker script for the fake PROM. |
| `arch/ia64/sn/fprom/fpromasm.S` | 315 | Fake PROM entry code and AP rendezvous. |
| `arch/ia64/sn/fprom/fw-emu.c` | 525 | PAL, SAL and EFI emulation for the simulator (SAL frequency base 500 MHz, interval timer 700 MHz). |
| `arch/ia64/sn/fprom/main.c` | 111 | Boot-master pick and fake PROM bring-up. |
| `arch/ia64/sn/fprom/runsim` | 373 | Shell helper that sets up a Medusa run. |
| `arch/ia64/sn/io/Makefile` | 33 | Kbuild for the I/O infrastructure. |
| `arch/ia64/sn/io/alenlist.c` | 901 | Address/length list code for DMA scatter lists (platform-neutral). |
| `arch/ia64/sn/io/cdl.c` | 203 | Connection/driver list for bus drivers (platform-neutral). |
| `arch/ia64/sn/io/devsupport.c` | 1290 | Bus-independent device driver support routines. |
| `arch/ia64/sn/io/eeprom.c` | 1475 | Reads Atmel EEPROMs on bricks through the L1 controller. |
| `arch/ia64/sn/io/hcl.c` | 1550 | Hardware graph compatibility layer (devfs-backed vertices). |
| `arch/ia64/sn/io/hcl_util.c` | 174 | Hardware graph helpers (master vertex lookup). |
| `arch/ia64/sn/io/hubdev.c` | 127 | Per-hub device list helpers. |
| `arch/ia64/sn/io/huberror.c` | 476 | Hub error interrupt handling (PI, MD, II, NI, LB error registers). |
| `arch/ia64/sn/io/hubspc.c` | 442 | Hub memory-space manager (counters and special regions). |
| `arch/ia64/sn/io/invent.c` | 226 | Hardware inventory list. |
| `arch/ia64/sn/io/io.c` | 1315 | Hub-based I/O set-up: widget windows, PIO maps, interrupt targets. |
| `arch/ia64/sn/io/ip37.c` | 122 | IP35/IP37 specific code: NI reset-port handling. |
| `arch/ia64/sn/io/klconflib.c` | 1055 | Walks KLCONFIG, the PROM's hardware inventory (boards, components, routers). |
| `arch/ia64/sn/io/klgraph.c` | 941 | Builds the hardware graph from KLCONFIG. |
| `arch/ia64/sn/io/klgraph_hack.c` | 797 | Static KLCONFIG stand-in for the simulator. |
| `arch/ia64/sn/io/l1.c` | 2798 | L1 system controller serial protocol: console, power, brick queries. |
| `arch/ia64/sn/io/l1_command.c` | 1461 | ELSC/L1 command layer: serial number, power, LEDs. |
| `arch/ia64/sn/io/labelcl.c` | 666 | Label-and-info layer under the hardware graph. |
| `arch/ia64/sn/io/mem_refcnt.c` | 223 | Page-migration reference counter thresholds (MD counters). |
| `arch/ia64/sn/io/ml_SN_init.c` | 645 | Machine-level SN init: node data, region setup. |
| `arch/ia64/sn/io/ml_SN_intr.c` | 1729 | Hub interrupt allocation and connection (PI interrupt pending bits, targets). |
| `arch/ia64/sn/io/ml_iograph.c` | 1655 | Builds the I/O half of the hardware graph per node. |
| `arch/ia64/sn/io/module.c` | 287 | Module (brick) identity table. |
| `arch/ia64/sn/io/pci.c` | 299 | SNIA PCI config access glue (snia64_read/write_config). |
| `arch/ia64/sn/io/pci_bus_cvlink.c` | 685 | Links the hardware graph to Linux PCI buses and devices. |
| `arch/ia64/sn/io/pci_dma.c` | 433 | PCI DMA mapping through the Bridge/XBridge ATE and direct maps. |
| `arch/ia64/sn/io/pciba.c` | 1717 | User-space PCI base-address access device. |
| `arch/ia64/sn/io/pcibr.c` | 9825 | Bridge and XBridge PCI bridge driver (Crosstalk to PCI). About 9800 lines; no PIC. |
| `arch/ia64/sn/io/pciio.c` | 1628 | Platform-neutral PCI I/O layer. |
| `arch/ia64/sn/io/sgi_if.c` | 71 | Small SGI interface shims. |
| `arch/ia64/sn/io/sgi_io_init.c` | 314 | SGI I/O init: calls the PROM-built KLCONFIG walk, sets up widgets. |
| `arch/ia64/sn/io/sgi_io_sim.c` | 131 | Simulator-only I/O init helpers. |
| `arch/ia64/sn/io/stubs.c` | 179 | Stubs for IRIX services the ported code expects. |
| `arch/ia64/sn/io/xbow.c` | 1808 | XBow crossbar driver: link state, error handling, widget enumeration. |
| `arch/ia64/sn/io/xswitch.c` | 268 | Crosstalk switch provider layer. |
| `arch/ia64/sn/io/xtalk.c` | 1137 | Crosstalk provider operations (PIO/DMA/interrupt). |
| `arch/ia64/sn/sn1/Makefile` | 32 | Kbuild for the SN1 platform directory. |
| `arch/ia64/sn/sn1/discontig.c` | 160 | NUMA memory zones for SN-IA64 (node and bank layout). |
| `arch/ia64/sn/sn1/error.c` | 150 | Hub error and UART interrupt demux using PI_INT_PEND0/1 bits. |
| `arch/ia64/sn/sn1/iomv.c` | 98 | I/O port access; a simulator path remaps legacy IDE ports into Bedrock local space. |
| `arch/ia64/sn/sn1/irq.c` | 184 | SN1 interrupt type: IRQ = Bedrock interrupt bit + 64. |
| `arch/ia64/sn/sn1/llsc4.c` | 953 | LL/SC cache stress autotest (CONFIG_IA64_SGI_AUTOTEST). |
| `arch/ia64/sn/sn1/llsc4.h` | 105 | Parameters for the LL/SC autotest. |
| `arch/ia64/sn/sn1/machvec.c` | 19 | Instantiates the SN1 machine vector. |
| `arch/ia64/sn/sn1/mm.c` | 395 | Memory init: node bank discovery and page-table set-up. |
| `arch/ia64/sn/sn1/probe.c` | 63 | SAL call that probes an I/O address, survives bus error. |
| `arch/ia64/sn/sn1/setup.c` | 255 | Platform setup: master node register base, early serial on the Bedrock UART, IVT fix for partitioned systems, simulator detection. |
| `arch/ia64/sn/sn1/smp.c` | 187 | IPI send by store to PI+0x80/0x88; PTC domain lookup. |
| `arch/ia64/sn/sn1/sn1_asm.S` | 150 | Autotest MCA triggers and speculation probes. |
| `arch/ia64/sn/sn1/sn1_ksyms.c` | 40 | Exported symbols. |
| `arch/ia64/sn/sn1/sv.c` | 552 | Synchronization variables ported from IRIX. |
| `arch/ia64/sn/sn1/synergy.c` | 430 | Synergy ASIC interrupt-mask programming and optional perf counters. |
| `arch/ia64/sn/tools/make_textsym` | 139 | Script that builds a symbol file for the simulator debugger. |
| `include/asm-ia64/sn/addrs.h` | 538 | Node address-space macros: node offset, HSPEC/LREG/LBOOT windows, KLDIR slots. |
| `include/asm-ia64/sn/agent.h` | 48 | Hub and SNAC interface definitions. |
| `include/asm-ia64/sn/alenlist.h` | 205 | Address/length list API. |
| `include/asm-ia64/sn/arc/hinv.h` | 187 | ARCS hardware inventory types. |
| `include/asm-ia64/sn/arc/types.h` | 42 | ARCS pointer types. |
| `include/asm-ia64/sn/arch.h` | 186 | SN architecture constants (nasid helpers, cpu counts). |
| `include/asm-ia64/sn/cdl.h` | 197 | Connection/driver list API. |
| `include/asm-ia64/sn/clksupport.h` | 65 | Real-time clock support (carried over from MIPS). |
| `include/asm-ia64/sn/dmamap.h` | 91 | DMA map allocation API. |
| `include/asm-ia64/sn/driver.h` | 151 | Driver handle management. |
| `include/asm-ia64/sn/eeprom.h` | 399 | EEPROM-over-L1 interface. |
| `include/asm-ia64/sn/gda.h` | 109 | Global data area structure from the PROM. |
| `include/asm-ia64/sn/hack.h` | 73 | Compatibility shims. |
| `include/asm-ia64/sn/hcl.h` | 115 | Hardware graph API. |
| `include/asm-ia64/sn/hcl_util.h` | 25 | Hardware graph helper prototypes. |
| `include/asm-ia64/sn/hubspc.h` | 26 | Hub special-space counters. |
| `include/asm-ia64/sn/hwcntrs.h` | 98 | Hub counter structures. |
| `include/asm-ia64/sn/intr.h` | 254 | Hub interrupt levels: INT_PEND bit assignments (UART, graphics, TLB, error bits, PROM-reserved). |
| `include/asm-ia64/sn/intr_public.h` | 60 | Interrupt structures shared with the PROM. |
| `include/asm-ia64/sn/invent.h` | 747 | Kernel hardware inventory records. |
| `include/asm-ia64/sn/io.h` | 68 | I/O accessor selection for SN. |
| `include/asm-ia64/sn/iobus.h` | 186 | I/O bus abstraction. |
| `include/asm-ia64/sn/ioc3.h` | 672 | IOC3 register map for the Linux driver (the IA-64 node uses IOC3, not IOC4). |
| `include/asm-ia64/sn/ioerror.h` | 197 | I/O error classes. |
| `include/asm-ia64/sn/ioerror_handling.h` | 306 | I/O error handling types. |
| `include/asm-ia64/sn/iograph.h` | 220 | Hardware graph naming for I/O. |
| `include/asm-ia64/sn/klconfig.h` | 967 | KLCONFIG board and component structures (KLTYPE_IP35, KLTYPE_IP37 alias, routers, I/O bricks, XBow, Bridge). |
| `include/asm-ia64/sn/kldir.h` | 165 | Kernel directory slots in each node's low memory. |
| `include/asm-ia64/sn/ksys/elsc.h` | 165 | ELSC (early system controller) interface. |
| `include/asm-ia64/sn/ksys/i2c.h` | 78 | I2C helper definitions. |
| `include/asm-ia64/sn/ksys/l1.h` | 362 | L1 controller protocol: packets, tasks, commands. |
| `include/asm-ia64/sn/labelcl.h` | 94 | Label layer API. |
| `include/asm-ia64/sn/mem_refcnt.h` | 27 | Page-migration counter API. |
| `include/asm-ia64/sn/mmzone.h` | 114 | NUMA zone definitions. |
| `include/asm-ia64/sn/mmzone_default.h` | 16 | Generic memory-zone defaults. |
| `include/asm-ia64/sn/mmzone_sn1.h` | 106 | SN1 memory geometry: 8 banks per node, 64 MB to 1 GB, node = 8 GB. |
| `include/asm-ia64/sn/module.h` | 209 | Brick/module structures. |
| `include/asm-ia64/sn/nic.h` | 129 | Dallas NIC (serial number) interface. |
| `include/asm-ia64/sn/nodemask.h` | 331 | Node bitmask helpers. |
| `include/asm-ia64/sn/nodepda.h` | 459 | Per-node data area, includes Synergy perf state. |
| `include/asm-ia64/sn/pci/bridge.h` | 1730 | Bridge and XBridge register map (part numbers 0xc002 and 0xd002). |
| `include/asm-ia64/sn/pci/pci_bus_cvlink.h` | 49 | Hardware graph to PCI bus link. |
| `include/asm-ia64/sn/pci/pci_defs.h` | 245 | PCI constants. |
| `include/asm-ia64/sn/pci/pciba.h` | 104 | PCI base-address device ioctls. |
| `include/asm-ia64/sn/pci/pcibr.h` | 461 | pcibr public constants. |
| `include/asm-ia64/sn/pci/pcibr_private.h` | 438 | pcibr private structures. |
| `include/asm-ia64/sn/pci/pciio.h` | 737 | Platform-neutral PCI I/O interface. |
| `include/asm-ia64/sn/pci/pciio_private.h` | 97 | pciio private structures. |
| `include/asm-ia64/sn/pio.h` | 160 | Programmed I/O map API. |
| `include/asm-ia64/sn/prio.h` | 39 | Priority I/O prototypes. |
| `include/asm-ia64/sn/router.h` | 20 | Router include stub. |
| `include/asm-ia64/sn/sgi.h` | 242 | SGI compatibility types. |
| `include/asm-ia64/sn/slotnum.h` | 26 | Slot-number space. |
| `include/asm-ia64/sn/sn1/addrs.h` | 309 | IP35 address map for the IA-64 build: region bases 0xc000... and 0xe000..., 8 GB nodes, 7-bit NASID. |
| `include/asm-ia64/sn/sn1/arch.h` | 80 | Limits: 128 NASIDs, 512 CPUs, two PIs per Bedrock, two CPUs per PI. |
| `include/asm-ia64/sn/sn1/bedrock.h` | 84 | Bedrock umbrella header and protection override key. |
| `include/asm-ia64/sn/sn1/hubdev.h` | 23 | Hub device structure. |
| `include/asm-ia64/sn/sn1/hubio.h` | 5018 | Bedrock II (I/O interface) registers, 0x400000 block and BTEs. |
| `include/asm-ia64/sn/sn1/hubio_next.h` | 762 | II friendlier names, BTE offsets, graphics flow-control encoding, widget part 0xc110. |
| `include/asm-ia64/sn/sn1/hublb.h` | 1609 | Bedrock LB (local block) registers. |
| `include/asm-ia64/sn/sn1/hublb_next.h` | 111 | LB masks: revision, system size, vector status. |
| `include/asm-ia64/sn/sn1/hubmd.h` | 2478 | Bedrock MD (memory and directory) registers. |
| `include/asm-ia64/sn/sn1/hubmd_next.h` | 816 | MD masks and shifts carried over from the MIPS tree. |
| `include/asm-ia64/sn/sn1/hubni.h` | 1783 | Bedrock NI (network interface) registers. |
| `include/asm-ia64/sn/sn1/hubni_next.h` | 176 | NI masks and bit definitions. |
| `include/asm-ia64/sn/sn1/hubpi.h` | 4265 | Bedrock PI (processor interface) registers. |
| `include/asm-ia64/sn/sn1/hubpi_next.h` | 333 | PI error bits and remote PI_1 window. |
| `include/asm-ia64/sn/sn1/hubxb.h` | 1290 | Bedrock XB (crossbar) registers. |
| `include/asm-ia64/sn/sn1/hubxb_next.h` | 34 | XB first-error source encoding. |
| `include/asm-ia64/sn/sn1/ip27config.h` | 659 | PROM configuration block structure. |
| `include/asm-ia64/sn/sn1/kldir.h` | 223 | SN1 kernel directory layout. |
| `include/asm-ia64/sn/sn1/leds.h` | 36 | LED control stub. |
| `include/asm-ia64/sn/sn1/promlog.h` | 86 | PROM log entry format. |
| `include/asm-ia64/sn/sn1/router.h` | 671 | SN1 router registers (port block, tables). |
| `include/asm-ia64/sn/sn1/slotnum.h` | 89 | SN1 slot numbering. |
| `include/asm-ia64/sn/sn1/sn1.h` | 35 | SN1-specific prototypes (chip revision, region helpers). |
| `include/asm-ia64/sn/sn1/uart16550.h` | 229 | 16550 UART register and bit definitions. |
| `include/asm-ia64/sn/sn_cpuid.h` | 242 | CPU id decode: LID id=NASID, eid bit 1 = Synergy, bit 0 = FSB slot. |
| `include/asm-ia64/sn/sn_fru.h` | 47 | Field-replaceable-unit record. |
| `include/asm-ia64/sn/sn_private.h` | 303 | Private SN helpers. |
| `include/asm-ia64/sn/sn_sal.h` | 26 | SAL extensions: POD mode, system reset, I/O probe (three calls). |
| `include/asm-ia64/sn/sv.h` | 154 | Synchronization variables. |
| `include/asm-ia64/sn/synergy.h` | 169 | Synergy ASIC register addresses (interrupt vector masks, perf counters) and remote access helpers. |
| `include/asm-ia64/sn/systeminfo.h` | 73 | sysinfo command numbers. |
| `include/asm-ia64/sn/types.h` | 33 | Node mask type. |
| `include/asm-ia64/sn/vector.h` | 120 | Vector (PIO to remote hub registers) operation definitions. |
| `include/asm-ia64/sn/xtalk/xbow.h` | 896 | XBow crossbar registers and part numbers (0x0 XBow, 0xd000 XBridge crossbar). |
| `include/asm-ia64/sn/xtalk/xbow_info.h` | 68 | XBow info structure. |
| `include/asm-ia64/sn/xtalk/xswitch.h` | 60 | Crosstalk switch vertex data. |
| `include/asm-ia64/sn/xtalk/xtalk.h` | 407 | Crosstalk provider interface. |
| `include/asm-ia64/sn/xtalk/xtalk_private.h` | 86 | Crosstalk private structures. |
| `include/asm-ia64/sn/xtalk/xtalkaddrs.h` | 114 | Crosstalk-to-Hub address mapping. |
| `include/asm-ia64/sn/xtalk/xwidget.h` | 309 | Generic widget header. |
| `include/asm-ia64/machvec_sn1.h` | 85 | SN1 machine vector declarations. Present at v2.5.73 (3342 bytes); removed by January 2004. |

## What the set does not contain

- No Bedrock PIC or TIO and no IOC4: the I/O code handles Bridge (`0xc002`) and XBridge (`0xd002`) only, and the SN1
  hub I/O interface's part number `0xc110`. See the platform page.
- No register header for Synergy beyond `synergy.h` (four interrupt-mask pairs and four performance control and counter
  pairs).
- The files are SGI's. They carry GPL notices and 1999 to 2000 copyrights of Silicon Graphics staff.
