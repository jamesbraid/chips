# SN2 SAL calls: what the Altix kernel asks of firmware

Every firmware service the Linux ia64 SN2 (Altix and Prism) kernel calls, with function number, arguments, results and what the kernel does with the answer. Calls marked **boot** below are the ones the kernel needs answered to come up; the kernel tolerates "not implemented" (`-1`) from the rest in most places.

**Source and grade.** The kernel's SN SAL header (`arch/ia64/include/asm/sn/sn_sal.h`, Linux v5.3) and every caller of it in the SN2 platform code, the SN PCI providers, the console, system-controller and cross-partition drivers and the hotplug driver, all at v5.3 (the SN2 platform was removed in v5.4). That is the vendor's software source: the function numbers, argument order, result use and the structures passed by physical address are **established** as definitions of what the kernel does. What the PROM does inside a call is **unknown** except where a kernel comment says. No PROM, SAL image or trace is held ([questions/sn2-sal-open.md](../../questions/sn2-sal-open.md)).

**PROM view.** Four shipped PROM images are now held and read ([software/firmware/snprom](../firmware/snprom/README.md)): the full dispatch tables (which ids each of the four images answers, and in which mode), and the boot-time handlers read in full there, are **established** from the binaries. The paragraph above about what the PROM does inside a call is out of date for those calls: the handlers the kernel needs from boot to multi-user, with their results on a single node and the places the PROM and the kernel disagree, are in [sn2-runtime.md](sn2-runtime.md); the rest are listed by name. The image set also shows ids the kernel header does not name (for example `0x02000008`, `0x0200000a` and `0x0200000b`, which the EFI side uses for flash and the clock).

## Calling convention

The SN calls are OEM SAL procedures: function ids in the range `0x02000000` upward, passed through the ordinary SAL entry point (the entry point comes from the SAL system table's entry point descriptor, found through the EFI configuration table with the SAL system table GUID; the kernel parses it very early so console output through SAL works). The wrappers pass the function id and up to seven 64-bit arguments, and read back four values:

| Name | Meaning |
|---|---|
| `status` | first return value; 0 is success unless a call says otherwise; negative values are the standard SAL errors: `-1` not implemented, `-2` invalid argument, `-3` error; `1` is "more passes" for the one iterative call |
| `v0`, `v1`, `v2` | the other three return values |

Three flavours exist only for locking in the kernel: `SAL_CALL` takes a global lock, `SAL_CALL_NOLOCK` takes none, `SAL_CALL_REENTRANT` allows nesting; and `ia64_sal_oemcall*` is the same with the OEM entry. They do not change what the PROM sees. Pointer arguments are of two kinds, and a table says which: the discovery, interrupt, hotplug and flush-list calls pass **physical** addresses (`__pa`), while the console, system controller, serial number, hardware performance, FIT, probe and error-print calls pass **kernel virtual** addresses in the identity-mapped region, so the PROM must be able to dereference them in virtual mode.

## Calls needed to boot

In order of first use. A failure of the ones marked *fatal* stops the kernel.

| # | Call | Failure |
|---|---|---|
| 1 | SAL system table entry point (not an SN call) | `failed to find SAL entry point` printed; console dead |
| 2 | `SN_SAL_GET_SN_INFO` and `SN_SAL_SET_CPU_NUMBER` (first processor initialisation of the boot CPU, before platform setup) | `GET_SN_INFO`: *fatal* (BUG) unless "not implemented", which selects SHub 1 defaults; `SET_CPU_NUMBER` ignored |
| 3 | `SN_SAL_SET_ERROR_HANDLING_FEATURES`, then `SN_SAL_SET_OS_FEATURE_SET` x4 (start of platform setup) | ignored |
| 4 | `SN_SAL_GET_KLCONFIG_ADDR` per node (building the compact node tables) | *fatal* (BUG on NULL) unless the PROM answers `SN_SAL_FAKE_PROM` |
| 5 | generic `SAL_FREQ_BASE` for the real-time clock | guesses 33.3 MHz (1e12/30000) if it fails or reports under 100 kHz |
| 6 | second processor initialisation of the boot CPU, after platform setup: `SN_SAL_GET_SN_INFO` again, `SN_SAL_GET_PROM_FEATURE_SET` set 0, 1, then `SN_SAL_GET_SAPIC_INFO` | `GET_SN_INFO` as row 2; feature sets stop at the first failure and absent features read false; `GET_SAPIC_INFO` *fatal* (BUG) unless "not implemented", which selects a fixed decoding |
| 7 | `SN_SAL_IOIF_INIT` (ACPI-capable PROM) or `SN_SAL_IOIF_GET_HUBDEV_INFO`, `GET_PCIBUS_INFO`, `GET_PCIDEV_INFO` (older PROM) | ACPI path: panic; older path: BUG |
| 8 | console calls (`SN_SAL_CONSOLE_*`) | no console |
| 9 | `SN_SAL_IOIF_INTERRUPT` per interrupt | device without interrupt |

The boot CPU runs the per-processor routine twice (the architecture calls processor initialisation twice on CPU 0): once early, which makes the `GET_SN_INFO` and `SET_CPU_NUMBER` calls, and once after platform setup, which repeats `GET_SN_INFO` and adds the feature-set and SAPIC calls. Other CPUs make all of them once. Order checked against `sn_setup` and `sn_cpu_init` in `arch/ia64/sn/kernel/setup.c`, Linux v5.3.

Which I/O path the kernel takes (ACPI or the older direct path) is decided by the DSDT's OEM revision: 0x20101 or higher selects the ACPI path. The PROM hands the kernel its data structures through ACPI "vendor typed" resources (below).

## Calls

### Platform and topology

| Number | Name | Arguments | Results | Kernel use |
|---|---|---|---|---|
| `0x0200001e` | `SN_SAL_GET_SN_INFO` | a1 = 0 (other values reserved) | v0: bits 7:0 chip (0 SHub 1, 1 SHub 2); 15:8 log2 maximum nodes in the system (C-bricks, I-bricks and so on); 23:16 log2 nodes per sharing domain; 31:24 partition id; 39:32 coherency domain id; 47:40 region size. v1: bits 15:0 NASID mask (0x7ff for 11 bits); bits 23:16 the NASID field's low bit (the header comment says 23:15; the code uses 23:16). | Once per CPU, and a second time on the boot CPU after platform setup. Fills the per-CPU chip record and the system size, sharing domain, partition, coherency and region values. Fallback when the call returns not implemented: SHub 1, mask 0x7ff, shift 38, system size 10, sharing size 8, partition from `SN_SAL_SYSCTL_PARTITION_GET`, coherency = NASID >> 9, region size from the SHub 1 identification register ([shub](../../devices/shub/README.md)). |
| `0x0200001d` | `SN_SAL_GET_SAPIC_INFO` | a1 = SAPIC id (the local id register's id and eid, `lid >> 16`) | v0 NASID, v1 subnode, v2 slice | Once per CPU (the boot CPU calls it in its second processor initialisation, after platform setup), and at early start of secondary CPUs when the NASID is not yet known. Fallback if not implemented: NASID = id & 0xfff, slice = (id >> 12) & 3, subnode = (id >> 13) & 1. |
| `0x02000005` | `SN_SAL_GET_KLCONFIG_ADDR` | a1 = NASID | v0 = physical address of that node's firmware hardware inventory header (KLCONFIG), 0 if none | The kernel walks the board list from it to find TIOs and headless or memoryless nodes, and gives each a compact node number. |
| `0x02000004` | `SN_SAL_GET_MASTER_NASID` | none | v0 = NASID of the node with the master console | Console routing and the hardware performance interface. status < 0 means the call failed, the kernel then uses the negative value as an invalid NASID. |
| `0x0200003c` | `SN_SAL_GET_MASTER_BASEIO_NASID` | none | v0 = NASID of the master base I/O node | Wrapper defined, no caller in the files read. |
| `0x02000068` | `SN_SAL_SET_CPU_NUMBER` | a1 = logical CPU number | status only | Tells the PROM which logical number a physical processor has; status ignored ("not supported on all PROMs but a failure is harmless"). Called for CPU 0 once. |
| `0x02000065` | `SN_SAL_GET_PROM_FEATURE_SET` | a1 = set number (0, 1) | v0 = 64-bit feature word | The kernel stops at the first set that fails and keeps the words as a bit string; a feature is available when its bit is set. Feature ids: 0 PAL cache flush safe, 1 per-device DMA flush list, 2 hotplug support, 3 CPU disable support. |
| `0x02000066` | `SN_SAL_SET_OS_FEATURE_SET` | a1 = feature id | status | Tells the PROM which kernel features exist: 0 MCA slave to OS INIT slave, 1 log SBEs, 2 ACPI enabled, 3 PCI segments enabled. A PROM that supports ACPI rebuilds its DSDT in response to 2 and 3, so the kernel calls these before it loads ACPI tables. Cannot be undone. |
| `0x02009999` | `SN_SAL_FAKE_PROM` | none | status 0 means a fake PROM | Only on the SGI simulator ("medusa"), to detect the fake PROM; a fake PROM has no KLCONFIG graph. |
| `0x0200001b` | `SN_SAL_GET_FIT_COMPT` | a1 NASID, a2 index, a3 pointer to a 16-byte buffer for the FIT entry, a4 pointer to a banner buffer (optional), a5 banner buffer length | status: 0 ok, `-2` index too big, `-1` older PROM | `/proc` PROM information: the kernel walks the firmware interface table of the PROM chips. |
| `0x02000038` | `SN_SAL_SYS_SERIAL_GET` | a1 = pointer to a buffer | status; buffer filled with the system serial number as ASCII | `/proc` and licensing; serial cached. |
| `0x02000039` | `SN_SAL_PARTITION_SERIAL_GET` | none | v0 = a unique id of system and partition | `/proc`. status != 0 gives 0. |
| `0x0200003a` | `SN_SAL_SYSCTL_PARTITION_GET` | a1 = NASID | v0 = partition id | Used on the old-PROM fallback of GET_SN_INFO. status != 0 gives -1. |
| `0x02000030` | `SN_SAL_SYSCTL_OP` | a1 = operation: 1 `SAL_SYSCTL_OP_IOBOARD` (return board type), 2 `SAL_SYSCTL_OP_TIO_JLCK_RST` (reset the CX corelet clock on a TIO); a2 = NASID | IOBOARD: board type in v0, or v1 if v0 is 0. TIO_JLCK_RST: status 0 and v0 0 for success | I/O board type of a bridge's node (PCI bridge and TIOCX code); clock reset when starting a TIOCX corelet. |
| `0x02000033` | `SN_SAL_SYSCTL_IOBRICK_MODULE_GET` | a1 = NASID | v0 = the I/O brick's module id | Wrapper defined, no caller in the files read. |
| `0x0200003f` | `SN_SAL_SYSCTL_FRU_CAPTURE` | none | v0 | Tells the system controller to capture the registers of every SHub; no caller in the files read. |
| `0x02000001` | `SN_SAL_POD_MODE` | a1 = 0 | v0 | Wrapper defined, no caller in the files read. |

### Console

Console I/O on an Altix is through SAL (the "ttySG" console), not a serial port the kernel owns.

| Number | Name | Arguments | Results | Notes |
|---|---|---|---|---|
| `0x02000021` | `CONSOLE_PUTC` | a1 = character | status | one character out; wrapper defined, no caller in the files read (output uses `PUTB` and `XMIT_CHARS`) |
| `0x02000022` | `CONSOLE_GETC` | none | v0 = character | one character in |
| `0x0200002b` | `CONSOLE_READC` | none | v0 = character | read after a poll or interrupt said one is there |
| `0x02000026` | `CONSOLE_POLL` | none | v0 = nonzero if input is available | |
| `0x02000027` | `CONSOLE_INTR` | a1 = interrupt mask (1 transmit, 2 receive), a2 = action (0 off, 1 on, 2 status) | status; for status, v0 = mask of interrupts pending | the console driver enables and disables the receive and transmit interrupts and polls the status |
| `0x02000028` | `CONSOLE_PUTB` | a1 = pointer to a buffer, a2 = length | v0 = bytes taken (if status is 0) | early and panic output, synchronous |
| `0x0200002a` | `CONSOLE_XMIT_CHARS` | a1 = pointer to a buffer, a2 = length | v0 = bytes taken | asynchronous output; the driver keeps a 64 KiB buffer and a 120-byte chunk size |

The numbers `0x02000023` (PUTS), `0x02000024` (GETS), `0x02000025` (GETS_TIMEOUT) are defined and not called.

### Interrupts and I/O interface

| Number | Name | Arguments | Results | Kernel use |
|---|---|---|---|---|
| `0x0200004a` | `SN_SAL_IOIF_INTERRUPT` | a1 = op, a2 = NASID of the bridge, a3 = widget. **Alloc** (op 1): a4 = pointer to the `sn_irq_info` record, a5 = requested irq (vector), a6 = requested target NASID, a7 = requested slice. **Free** (op 2): a4 = irq, a5 = cookie. **Redirect** (op 3): a4 = pointer to the record, a5 = target NASID, a6 = target slice | status; the record is filled by the PROM on alloc and redirect | The kernel's only way to wire a bridge interrupt (including a TIOCX corelet's) to a CPU. On redirect failure the kernel falls back to free followed by alloc, so a PROM may return an error for redirect. |
| `0x02000060` | `SN_SAL_HUB_ERROR_INTERRUPT` | a1 = NASID | v0 non-zero is fatal | Called from the SHub error interrupt on SHub 1 (all nodes) and on SHub 2 (TIO nodes only). The kernel panics if v0 is non-zero; on SHub 1 and a non-TIO it then scans the CRBs itself ([shub_ii](../../devices/shub_ii/README.md)). |
| `0x02000051` | `SN_SAL_IOIF_ERROR_INTERRUPT` | a1 = segment, a2 = bus number | v0: PIC bridge, negative means fatal (panic); TIOCE, non-zero is fatal; TIOCA, ignored | Called from a bridge's error interrupt. The PROM decodes and clears the bridge's error state. |
| `0x02000052` | `SN_SAL_IOIF_PCI_SAFE` | a1 = segment, a2 = bus, a3 = 0 for I/O space, a4 = 0 for read and 1 for write, a5 = port, a6 = size in bytes, a7 = pointer to the data | status 0 on success | Legacy I/O port access (the VGA ports), done by the PROM so that it can work round bridge defects. If it fails the kernel falls back to a protected read through `SN_SAL_PROBE`. Older PROMs (before 4.10) lack it. |
| `0x02000061` | `SN_SAL_BTE_RECOVER` | a1 = NASID | status; `-1` (not implemented) is treated as success | BTE error recovery on SHub 2; the kernel panics on any other non-zero status. |
| `0x02000003` | `SN_SAL_PROBE` | a1 = address, a2 = size (1, 2, 4, 8) | status 0 ok, 1 the read machine-checked, 2 bad argument, negative PAL error; v0 = the data | Read an I/O address without crashing on a machine check. |
| `0x02000050` | `SN_SAL_HWPERF_OP` | a1 = NASID, a2 = opcode, a3 to a7 = operation arguments | status (`SN_HWPERF_OP_*`, 0 ok, 1 no memory, 2 no permission, 3 I/O error, 4 busy, 253 reconfigure, 254 invalid), v0 | Hardware performance and topology interface. Opcodes in the SN2 hwperf header: object count 10, distance 11, enumerate objects 12, enumerate ports 13, set MMRs 14, get MMRs 15, acquire 16, release 17, force release 18, get CPU info 100, object to node 101, node to NASID 102; bit 0x1000 means "copy data in", 0x2000 "copy data out". The topology report in `/proc/sgi_sn` is built from it. A synthetic SAL may return `-1`; the report is then empty. |
| `0x02000064` | `SN_SAL_IOIF_GET_PCI_TOPOLOGY` | a1 = pointer to a buffer, a2 = length | status | PCI topology for the performance interface. |

### I/O discovery (older direct path)

Used only when the DSDT revision is below 0x20101.

| Number | Name | Arguments | Results |
|---|---|---|---|
| `0x02000055` | `SN_SAL_IOIF_GET_HUBDEV_INFO` | a1 = NASID, a2 = pointer to a `hubdev_info` | v0 = 0 on success; the kernel pre-fills `max_segment_number = 0xffffffff`, `max_pcibus_number = 0xff` and a PROM that supports segments overwrites them |
| `0x02000056` | `SN_SAL_IOIF_GET_PCIBUS_INFO` | a1 = segment, a2 = bus number, a3 = pointer to a pointer to a `pcibus_bussoft` | v0 = 0 success, > 0 the bus does not exist |
| `0x02000057` | `SN_SAL_IOIF_GET_PCIDEV_INFO` | a1 = segment, a2 = bus, a3 = devfn, a4 = pointer to a `pcidev_info`, a5 = pointer to an `sn_irq_info` | v0 = 0 success; the kernel BUGs otherwise |
| `0x0200005a` | `SN_SAL_IOIF_GET_DEVICE_DMAFLUSH_LIST` | a1 = NASID, a2 = widget, a3 = device, a4 = pointer to a `sn_flush_device_common` | status; an older PROM (before 4.50) lacks it |
| `0x02000058` | `SN_SAL_IOIF_GET_WIDGET_DMAFLUSH_LIST` | a1 = NASID, a2 = widget, a3 = pointer to an array of 32 flush records | status; deprecated; failure panics |

### I/O discovery (ACPI path)

| Number | Name | Arguments | Results |
|---|---|---|---|
| `0x0200005f` | `SN_SAL_IOIF_INIT` | none | status and v0 both must be 0 or the kernel panics. The PROM performs its early I/O setup and builds the ACPI namespace. |

The PROM supplies a DSDT whose devices include `SGIHUB` (one per SHub), `SGITIO` (one per TIO), each PCI root bus and each device on them. The kernel reads a "vendor typed" resource out of each device's `_CRS` with the vendor UUID bytes `2c c6 a6 fe 9c 44 da 11 a2 7c 08 00 69 13 ea 51` (subtype 0). The payload after the UUID is exactly one 8-byte physical pointer: to a `hubdev_info` for a hub or TIO, to a `pcibus_bussoft` for a root bus, to a `pcidev_info` (which in turn holds a pointer to an `sn_irq_info`) for a device. A length other than eight bytes is rejected. The kernel also reads `_BBN` of the parent for the bus number and `_ADR` for the devfn to match a PCI device to its descriptor, and the hotplug driver calls slot enable and disable that return an SSDT.

### Hotplug

| Number | Name | Arguments | Results |
|---|---|---|---|
| `0x02000053` | `SN_SAL_IOIF_SLOT_ENABLE` | a1 = segment, a2 = bus, a3 = device, a4 = pointer to a response buffer, a5 = pointer to a pointer for an SSDT | v0 = result |
| `0x02000054` | `SN_SAL_IOIF_SLOT_DISABLE` | a1 = segment, a2 = bus, a3 = device, a4 = action, a5 = pointer to a response buffer | v0 = result |
| `0x02000042` | `SN_SAL_SYSCTL_IOBRICK_PCI_OP` | a1 = connection type, a2 = NASID, a3 = action (power up, power down, reset), a4 = bus, a5 = slot | v0 = result; wrapper defined, no caller in the files read |

Only when the PROM feature "hotplug support" is advertised does the kernel load the hotplug driver.

### System controller

| Number | Name | Arguments | Results |
|---|---|---|---|
| `0x02000043` | `SN_SAL_IROUTER_OP` | a1 = op, then per op below | per op |
| `0x02000044` | `SN_SAL_SYSCTL_EVENT` | a1 = NASID | v0 = subchannel for environmental events |

`SN_SAL_IROUTER_OP` ops (all with a2 = NASID of the node whose controller is used):

| a1 | Op | Further arguments | Result |
|---|---|---|---|
| 0 | open | none | v0 = new subchannel, or a negative error |
| 1 | close | a3 = subchannel | status |
| 2 | send | a3 = subchannel, a4 = pointer to buffer, a5 = length | v0 = bytes written (may be 0), or a negative error |
| 3 | receive | a3 = subchannel, a4 = pointer to buffer, a5 = pointer to a length (capacity in, bytes read out) | status 0 ok, `-3` error or no data |
| 4 | interrupt status | a3 = subchannel | v0 = mask pending (1 transmit, 2 receive) |
| 5 | interrupt on | a3 = subchannel, a4 = mask | v0 |
| 6 | interrupt off | a3 = subchannel, a4 = mask | v0 |
| 7 | init | a3 = pointer to a buffer, a4 = its length (for subchannel queues) | status |

These carry the driver of the system controller (L1/L2), which opens one subchannel to talk to it and one for events. The protocol over them is the controller's own; the sysco repository holds the controller side.

### Error handling, machine check and memory

| Number | Name | Arguments | Results | Kernel use |
|---|---|---|---|---|
| `0x02000006` | `SN_SAL_LOG_CE` | none | status | corrected platform error handler; the PROM polls and logs |
| `0x02000012` | `SN_SAL_PRINT_ERROR` | a1 = pointer to a print routine, a2 = pointer to an error section | status | printing an SGI platform error record section from the machine check log |
| `0x0200001a` | `SN_SAL_SET_ERROR_HANDLING_FEATURES` | a1 = feature bits (the kernel passes 2, log single-bit errors) | status | obsolete; superseded by the OS feature call |
| `0x02000067` | `SN_SAL_INJECT_ERROR` | a1 = physical address, a2 = pointer to data, a3 = pointer to ECC | status | error injection; no caller in the files read |
| `0x0200000f` | `SN_SAL_XP_ADDR_REGION` | a1 = physical address, a2 = length, a3 = 1 register or 0 unregister | status = reference count after the call, or negative | marks an address range that is read across a partition boundary, so that SAL errors from it are cleaned up and ignored |
| `0x02000010` virtual, `0x02000011` physical | `SN_SAL_NO_FAULT_ZONE_VIRTUAL`, `SN_SAL_NO_FAULT_ZONE_PHYSICAL` | a1 = first instruction address, a2 = last, a3 = address to resume at when an error is ignored, a4 = 1 | status | Registers an instruction range for which SAL errors are ignored; the cross-partition driver registers the range around a protected remote read, whose target is the IPI access register of the local node (the driver comment says no special reason for that choice). The kernel wrapper has an operation argument (register or unregister) that it never sends: a4 is always 1, so what unregister does, if anything, is unknown. |
| `0x02000014` | `SN_SAL_REGISTER_PMI_HANDLER` | a1 = handler, a2 = global pointer | status | wrapper defined, no caller in the files read |
| `0x0200003d` | `SN_SAL_COHERENCE` | a1 = pointer to the new coherence domain, a2 = pointer to the old one (bit arrays, one bit per CPU NASID) | status | wrapper defined, no caller |
| `0x0200003e` | `SN_SAL_MEMPROTECT` | a1 = physical address, a2 = length, a3 = pointer (unused on Altix), a4 = access class | status | cross-partition code opens and closes a memory range to other partitions: class 1 (`0x2520c2`) opens, class 0 (`0x14a080`) closes; other defined classes: 2 `0x14a1ca`, 3 `0x14a290`, 6 `0x084080`, 7 `0x021080` |
| `0x02000009` | `SN_SAL_GET_PARTITION_ADDR` | a1 = cookie, a2 = address (first call: the NASID of the partition), a3 = buffer, a4 = length | status 1 means call again; v0 cookie, v1 address, v2 length, which are passed back unchanged on the next call; at status 0 `addr` is the physical address of the partition's reserved page | cross-partition code, iterating until done |
| `0x02000070` | `SN_SAL_WATCHLIST_ALLOC` | a1 = address of a message queue, a2 = blade (bits 15:0) and size (bits 47:16), a3 = pointer to receive the interrupt MMR offset, a4 = pointer to receive the watchlist number | status >= 0 means ok | message queue watch lists; the only callers are `sn_mq_watchlist_alloc` and `_free` in `xpc_uv.c`, built only for the UV platform (the driver Makefile builds `xpc_uv.o` for `CONFIG_IA64_SGI_UV` and x86-64, and `xpc_sn2.o` for the SN2 and generic ia64 configurations), so no caller on an SN2 SHub machine |
| `0x02000071` | `SN_SAL_WATCHLIST_FREE` | a1 = blade, a2 = watchlist number | status | called only from the UV-only `xpc_uv.c` (see `WATCHLIST_ALLOC`); no caller on SN2 |
| `0x02000069` | `SN_SAL_KERNEL_LAUNCH_EVENT` | none | status | told to PROM when kexec starts a new kernel; non-zero prints a "KEXEC not supported" message |
| `0x0200003b` | `SN_SAL_SYSTEM_POWER_DOWN` | none | none (does not return) | power off |

### Defined, never called in the files read

`SN_SAL_SYSTEM_RESET` (0x02000002), `SN_SAL_REGISTER_CE` (0x02000007), `SN_SAL_SYSCTL_MODID_GET` (0x02000031), `SN_SAL_SYSCTL_GET` (0x02000032), `SN_SAL_SYSCTL_IO_PORTSPEED_GET` (0x02000035), `SN_SAL_SYSCTL_SLAB_GET` (0x02000036), `SN_SAL_BUS_CONFIG` (0x02000037), `SN_SAL_RESERVED_DO_NOT_USE` (0x02000062), console PUTS, GETS and GETS_TIMEOUT.

## Generic SAL and EFI the kernel also uses

Not SN-specific; the public IA-64 SAL specification governs them. Seen in the files read: `SAL_FREQ_BASE` for the real-time clock, `SAL_MC_SET_PARAMS` for the corrected platform error interrupt and rendezvous vector, `SAL_SET_VECTORS` for the OS machine check and INIT entry points, `SAL_GET_STATE_INFO`, `SAL_GET_STATE_INFO_SIZE`, `SAL_CLEAR_STATE_INFO`, `SAL_MC_RENDEZ`. The kernel parses the SAL system table for its entry point and for the PROM revision (`sal_b_rev_major` and minor, printed as "SGI SAL version"). The EFI side supplies the memory map, the ACPI 2.0 tables and, for a VGA console, the HCDP/PCDP table.

## Structures the PROM fills

`sn_irq_info` (kernel header `intr.h`): next pointer (deprecated), `irq_nasid` (short), `irq_slice`, `irq_cpuid`, `irq_irq`, `irq_int_bit` (bridge pin, negative for MSI), `irq_xtalkaddr` (address the bridge writes), `irq_bridge_type` (1 PPB, 2 PIC, 3 TIOCP, 4 TIOCA, 5 TIOCE), `irq_bridge`, `irq_pciioinfo`, `irq_last_intr`, `irq_cookie`, `irq_flags` (1 reserved, 2 connected, 4 shared), `irq_share_cnt`, then list and RCU members the kernel owns.

`pcibus_bussoft`: `bs_asic_type` (u32), `bs_xid` (widget id), `bs_persist_busnum`, `bs_persist_segment`, `bs_legacy_io`, `bs_legacy_mem`, `bs_base` (widget register base), `bs_xwidget_info`.

`hubdev_info`: `hdi_geoid`, `hdi_nasid`, `hdi_peer_nasid`, the flush list head and an array of `xwidget_info` for widgets 0 to 15, node pointers, `max_segment_number`, `max_pcibus_number`.

`sn_flush_device_common`: bus, slot, pin, six BAR ranges, the force-interrupt address, the flush value and address, the persistent bus and segment numbers and a bridge info pointer.

`pcidev_info`: seven mapped BAR addresses (six BARs and the ROM), host handle, pointers to bus soft state, host pcidev, the kernel's `pci_dev`, the irq info and provider.

`geoid_t` is an 8-byte union (`GEOID_SIZE`). Its common part is the module id (unsigned 32 bits), a type byte (1 module, 2 node, 3 router, 4 I/O controller, 5 I/O card, 6 CPU, 7 memory), then one byte holding the slab (4 bits) and the slot (4 bits), with the type-specific bytes after it: a PCI card adds bus and slot bytes, a CPU adds the slice, memory adds memory bus and slot. Whether the slab or the slot takes the low four bits of that byte depends on the compiler's bitfield order, which the sources do not fix (the ia64 kernel is little-endian, so slab is the low nibble).

`xwidget_info` is: widget hardware id (three ints: manufacturer, revision, part), the hub's widget port number (one char), then three pointers (hub info, hub provider functions, vertex). With natural alignment on LP64 that is 12 bytes, a char at 12, padding to 16 and three pointers, 40 bytes in all.

`nasid_t` is a signed 16-bit short, `partid_t` a signed char, `cnodeid_t` a short.

The headers give C struct definitions, which on ia64 are LP64 with natural alignment, and the PROM writes them as raw memory, so a synthetic PROM has to match field widths and padding exactly. The pointers inside them are physical or PROM-virtual addresses the kernel converts with `__va`; which kind each is, is not written down ([questions/sn2-sal-open.md](../../questions/sn2-sal-open.md)). KLCONFIG's layout is in a header not read for this page.

## Review

Independent review of this page at chips commit 40866b2 against Linux v5.3 `sn_sal.h` and every SN2 file that includes it that could be fetched: `arch/ia64/sn/kernel/` (all files), `arch/ia64/sn/kernel/sn2/` (all), `arch/ia64/sn/pci/` (all), the SN headers, `drivers/char/snsc*.c`, `drivers/tty/serial/sn_console.c`, `drivers/pci/hotplug/sgi_hotplug.c`, `drivers/misc/sgi-xp/` and `sgi-gru/`, `drivers/char/mspec.c`, and the ia64 `setup.c`, `mca.c` and `machine_kexec.c`. The reviewer did not write the page.

**Checked.**
- All 57 function numbers in the call tables, and the eight in the "never called" list, were compared by script with the `#define` values: all match. Every `SN_SAL_` define in the header is on the page (the three console string calls are named in the "defined, not called" sentence).
- Arguments, results and use were read for 28 calls: `GET_SN_INFO` (bit positions, fallback values, status handling), `GET_SAPIC_INFO` (fallback decode), `GET_KLCONFIG_ADDR` (physical address, zero means none), `GET_MASTER_NASID`, `SET_CPU_NUMBER`, `GET_PROM_FEATURE_SET` and its four feature ids, `SET_OS_FEATURE_SET` (four calls, four ids), `SET_ERROR_HANDLING_FEATURES` (argument 2), `FAKE_PROM`, `SYSCTL_PARTITION_GET`, `SYSCTL_OP` (both ops), `IROUTER_OP` (all eight ops), `IOIF_INTERRUPT` (alloc, free, redirect argument orders), `IOIF_PCI_SAFE` (argument order, the 4.10 comment), `PROBE`, `HUB_ERROR_INTERRUPT` (SHub 1 versus SHub 2 behaviour), `BTE_RECOVER` (not-implemented treated as success), `GET_PARTITION_ADDR` (cookie protocol), `XP_ADDR_REGION`, `NO_FAULT_ZONE_*` (the operation argument that is never sent: a4 is always 1), `MEMPROTECT` (argument order and the six access classes), `COHERENCE`, `HWPERF_OP` (all opcodes and result codes), `IOIF_INIT` (panic on failure), the dma flush list calls (including the "before 4.50" and panic behaviour in `io_common.c`), `KERNEL_LAUNCH_EVENT`, and the ACPI vendor-resource UUID bytes and eight-byte payload rule.
- The "defined, wrapper present, no caller" and "never called" lists were re-derived by script over every fetched file: `SYSTEM_RESET`, `REGISTER_CE`, `SYSCTL_MODID_GET`, `SYSCTL_GET`, `IO_PORTSPEED_GET`, `SLAB_GET`, `BUS_CONFIG`, `RESERVED_DO_NOT_USE`, console `PUTS`, `GETS`, `GETS_TIMEOUT` have no wrapper and no use; `POD_MODE`, `GET_MASTER_BASEIO_NASID`, `SYSCTL_IOBRICK_MODULE_GET`, `FRU_CAPTURE`, `SYSCTL_IOBRICK_PCI_OP`, `COHERENCE`, `INJECT_ERROR`, `REGISTER_PMI_HANDLER` have a wrapper and no caller. All as the page says.
- SHub 1 versus SHub 2 is decided only by bits 7:0 of the first result of `SN_SAL_GET_SN_INFO` (the not-implemented fallback sets 0); no register is read to decide it. The claim holds.

**Grades.** Function numbers, argument order and result use are definitions of kernel behaviour and are established as stated. PROM-side behaviour is unknown and is marked so. No grade is too high.

**Findings (not changed).**
1. The "Calls needed to boot" table is not in order of first use. In v5.3 the boot processor does: SAL entry point; `GET_SN_INFO` and `SET_CPU_NUMBER` (processor initialisation, before platform setup); the error-handling-features call and the four OS feature calls (start of platform setup); `GET_KLCONFIG_ADDR` per node (cnode table build); `SAL_FREQ_BASE`; then a second `GET_SN_INFO`, `GET_PROM_FEATURE_SET`, `GET_SAPIC_INFO` (second processor initialisation). The page puts the frequency and SAPIC calls before the KLCONFIG call and the PROM feature call after SAPIC. The set of calls and their failure behaviour are right; only the order is wrong.
2. `GET_SN_INFO` and `GET_SAPIC_INFO` are called more than once on the boot processor; "once per CPU" holds for the others.
3. `SN_SAL_WATCHLIST_ALLOC` is described as having "no caller in the files read", and `WATCHLIST_FREE` has no note. Both are called through `sn_mq_watchlist_alloc` and `_free` from `xpc_uv.c`, but only in builds for the UV platform (`CONFIG_IA64_SGI_UV` or generic), not on an SN2 SHub machine. The row should say that.
4. The `CONSOLE_PUTC` wrapper has no caller in the files read (console output uses `PUTB` and `XMIT_CHARS`); the page lists it without saying so.
5. The page quotes one source comment ("not supported on all PROMs but a failure is harmless") and a few short phrases; nothing longer is copied. No internal names or private paths were found in this page, the SHub pages, the address map or the register files.
6. Not verified: that the kernel passes kernel-virtual addresses for the hardware performance and probe calls and physical addresses for the discovery calls, beyond the ones read (`IOIF_INTERRUPT`, `PCI_SAFE`, discovery calls use `__pa`); and the code that sets the DSDT OEM revision which selects the ACPI path (only the 0x20101 threshold was found).

**Cleared:** the call numbers (all), the arguments and results of the 28 calls read, the never-called and no-caller lists against the fetched files, and the chip-type test. **Not cleared:** the boot order (finding 1); the claim that no file outside the fetched set calls these (a full tree search was not run, as Linux was not cloned); the structures section (`sn_irq_info`, `hubdev_info`, `geoid_t`, the LP64 layout arithmetic), which was not re-derived; what the PROM does in any call.

Findings 1-8 addressed in the commit "docs: address the SN2 SHub review findings"; renewed review needed for the changed claims.

### Renewed review

Renewed review of the changed claims only, 2026-11-14, by a reviewer who wrote none of them. Reviewed chips commit f5ab671 (contains 1d4f24f and 9995be1). Grading rule: sgi-retools `tools/README-analysis.md` "Evidence order" at c50bfeb. Sources were fetched as single files from Linux v5.3 into scratch and compared with the changed text. 

**Checked.**
- Boot order: first `sn_cpu_init` (from `cpu_init`, before `platform_setup`): `GET_SN_INFO`, then `SET_CPU_NUMBER` (CPU 0 once only). `sn_setup`: `ia64_sn_plat_set_error_handling_features`, then four `ia64_sn_set_os_feature` calls (MCA slave, log SBES, PCI segment, ACPI), `acpi_table_init`, `build_cnode_tables` (per-node `GET_KLCONFIG_ADDR`, skipped on the fake PROM), `SAL_FREQ_BASE`, `sn_init_pdas`, then the second `sn_cpu_init`, which repeats `GET_SN_INFO` and, because the node data now exists, goes on to `GET_PROM_FEATURE_SET` (loop, stop at first failure) and `GET_SAPIC_INFO`. The table's rows 2 to 6 and the paragraph below it match. "After platform setup" for row 6 means the end of `sn_setup`, after the frequency and KLCONFIG calls; the order is right.
- `WATCHLIST_ALLOC` and `_FREE`: the only callers found are `sn_mq_watchlist_alloc` and `_free` in `drivers/misc/sgi-xp/xpc_uv.c`. The file's own conditionals admit `CONFIG_IA64_GENERIC`, but the driver Makefile builds `xpc_uv.o` only for `CONFIG_IA64_SGI_UV` and `CONFIG_X86_64` and `xpc_sn2.o` for the SN2 and generic configurations, so the page's "or generic" was wrong about what is built. Corrected (mechanical). Callers outside the fetched files were not searched for.
- `CONSOLE_PUTC`: `ia64_sn_console_putc` is defined in `sn_sal.h` and has no caller in the files fetched (`sn_console.c` uses `PUTB` and `XMIT_CHARS`). Match, limited to those files.

**Findings.** One mechanical fix (watchlist build condition), made.

**Cleared:** the boot-order table and its note, the `GET_SN_INFO` and `GET_SAPIC_INFO` call-count wording, the watchlist and `CONSOLE_PUTC` notes. **Not cleared:** as in the first review (the tree-wide no-caller claim, the structures section, PROM behaviour).
