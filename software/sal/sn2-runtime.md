# SN2 SAL runtime: what the PROM answers to the calls Linux makes

Each SAL call the 2.6-era Altix kernel makes from early boot to multi-user, matched to the PROM routine that answers it, what that routine touches, and what comes back on a single-node Altix 350. The kernel side (argument order, how results are used) is in [README.md](README.md); this page adds the firmware side and records where the two disagree.

## Sources and grades

- **PROM:** the SAL 5.04 image of the SHub 1 package 10.54 (`shub1snprom.bin`, SHA-256 starts `51ccf9ad`). Two parts were read, both in Ghidra with the IA-64 processor module and cross-checked in places with `ia64-linux-gnu-objdump`:
  - the **SAL runtime** component (FIT entry type 0x12, gzip, inflates to a 918,824-byte IA-64 ELF shared object with a dynamic symbol table, one load segment at virtual address 0). Addresses below written `rt:0xNNNN` are ELF virtual addresses in the inflated file, which is how Ghidra shows them minus its 0x100000 load bias;
  - **SAL_B**, the flat physical-mode image linked to run from flash at `0xffa01000`. Addresses written `0xffNNNNNN` are machine addresses.
- **Linux:** v5.3 `arch/ia64/include/asm/sn/sn_sal.h`, `arch/ia64/sn/kernel/{setup,io_init,io_common,irq,mca,bte}.c`, `arch/ia64/sn/kernel/sn2/{sn2_smp,timer,sn_hwperf,prominfo_proc}.c` and `arch/ia64/include/asm/sn/sn2/sn_hwperf.h`, `arch/ia64/include/asm/sn/intr.h`, `arch/ia64/kernel/sal.c`; and v2.6.12 (the closest public tree to the held 2.6.5 SN2 kernel) `arch/ia64/sn/kernel/{setup,io_init,irq,mca}.c`, `arch/ia64/sn/kernel/sn2/*.c`, `arch/ia64/sn/pci/{pci_dma.c,pcibr/pcibr_provider.c}`, `drivers/serial/sn_console.c`, `arch/ia64/kernel/{time,mca,smpboot}.c`. Vendor platform code, so what it says the kernel does is **established**.
- **Grades** follow [AGENTS.md](../../AGENTS.md). *established*: the whole routine was read in the binary and the fact is what it does. *inferred*: built from a call list, a name or a sibling routine, with the reasoning given. *unknown*: not settled. A fact about hardware (what a register holds on a real machine) is never better than inferred here, because no capture is held; the PROM shows what it reads and writes, not what a node contains.

The registers used here: SHub 1 node id and size register `0x1_1006_0580` ([shub_id](../../devices/shub/registers.md)) and the real-time clock control register `0x1_1006_0280` ([rtc_ctl](../../devices/shub/registers.md)). The PROM reaches them through the uncached window at `0x8000_0081_1006_xxxx` for the local node.

## How a call reaches its routine

- **Virtual-mode entry (established).** `salruntime_entry` (`rt:0x3000`) scans a table of 16-byte entries `{id, handler}` starting at `rt:0xa29f8` for an exact id match and calls the handler with all eight arguments passed through. The scan ends at an id of 0, whose handler (`salruntime_unimplemented_function_code`, `rt:0xe670`) sets the status register to -1 and leaves the other three results as whatever was on its stack. So an id the PROM does not know returns "not implemented" and nothing else.
- **Forwarding to physical mode (established for the mechanism, inferred for the target).** Ids whose runtime handler is `salruntime_phys_call` (`rt:0x60e00`) are not answered in the runtime. The routine drops to physical mode and calls through the descriptor addressed by the word at offset `0x98` of the structure the word at physical `0x1000038` points to ("block A"). That is the SAL_B table below. That the descriptor leads to the SAL_B dispatcher is inferred from the table shape, not from reading the setup of the word.
- **Physical-mode table (established).** SAL_B has 105 rows of 16 bytes `{id, pointer to a {code, gp} descriptor}` at `0xffc25ec8`: 97 SAL ids (rows 0 to 96), four rows with ids `0x8000000000003000`, `5000`, `6000`, `7000` (not SAL ids: they alias two other handlers, a timer and an interrupt-state routine), the three late ids `0x02000067`, `0x02000068`, `0x02000069` (rows 101 to 103), and a zero-id row (104) whose handler is the "not implemented" routine at `0xffb1daf0`. All gp values are `0xffd98000`.
- **Twins (established).** For the handlers read below that exist on both sides (`GET_SN_INFO`, `GET_SAPIC_INFO`, `GET_KLCONFIG_ADDR` twin, `GET_MASTER_NASID`, `GET_MASTER_BASEIO_NASID`, `SAL_FREQ_BASE`, `SET_ERROR_HANDLING_FEATURES`, `GET_ERROR_HANDLING_FEATURES`, `SET_CPU_NUMBER`, `SN_SAL_PROBE`, `SYS_SERIAL_GET`, `PARTITION_SERIAL_GET`, `SYSCTL_PARTITION_GET`) the instruction sequences of the runtime routine and its SAL_B twin are identical when immediates are ignored, so one reading serves both. `SN_SAL_HWPERF_OP` is runtime only; the I/O interface calls, `GET_KLCONFIG_ADDR`, `GET_PROM_FEATURE_SET`, `SET_OS_FEATURE_SET` and `BTE_RECOVER` are physical only.
- **Results.** Every handler returns the SAL result registers r8 (status) to r11. Ghidra's decompiler drops r9 to r11, so the results below were read from the listing: most handlers keep them in four stack slots and load them in one epilogue.

### Two data blocks the handlers use

The PROM keeps two pointers at fixed physical addresses. They are how every routine below finds its data; offsets are as the code uses them.

| Block | Seen use (offset: meaning, grade) |
|---|---|
| A, the structure the word at `0x1000038` points to | `+0x10`: pointer to a table whose first halfword is a count and then one halfword per NASID slot, -1 for an absent node (inferred from `GET_HUBDEV_INFO`, I/O init). `+0x18`: a table the simulator path of `SAL_FREQ_BASE` walks. `+0x20`: pointer to the node's firmware inventory block; the `GET_KLCONFIG_ADDR` result is this plus `0x10000` (established as the arithmetic, inferred as meaning). `+0x40`: pointer to the hardware-performance object table. `+0x50`: the offset `main_ptov` adds when data translation is on. `+0x98`: the physical-mode dispatch descriptor. Remote nodes' copies are read through the uncached remote window at `((nasid << 38) + 0x30_0000_0000)`, masked, or `0x8000_0030_0100_0038` (established). |
| B, the structure the word at `0x1000040` points to | `+0x28`: master base I/O NASID (word). `+0x40`: pointer to the I/O interface state (hub list, bus lists, per-NASID node records at `+0x70`, per-irq list heads at `+0x78`, one-time-init flag at `+0x18`). `+0x88`: index of the console device. `+0x98`: pointer to the system serial string; `+0xa0`: partition-serial field. `+0xc8`: OS-feature flags, bit 2 ACPI enabled, bit 3 PCI segments enabled (established). `+0x100`: pointer to the master console NASID (halfword). |

## Boot-time calls in the order a 2.6-era kernel makes them

Linux caller names are from v5.3 unless a 2.6.12 difference is stated. "Single node" means one SHub, NASID not further assumed. Every call here is **established** for the PROM logic named; what a register contains on hardware is called out where a result depends on one.

| Order | Call | Linux caller | PROM routine (SAL_B row `@address`; runtime row `rt:`) | Returns on a single node |
|---|---|---|---|---|
| 1 | `0x02000068` `SET_CPU_NUMBER` | `sn_cpu_init`, boot CPU, first pass (v5.3 only) | row 102 `@0xffb13a70`; `rt:0x47d0` | r8 = 0 |
| 2 | `0x0200001e` `GET_SN_INFO` | `sn_cpu_init` (twice on the boot CPU), `sn_topology_show` | row 26 `@0xffb60640`; `rt:0x31d0` | r8 = 0, r9, r10 below |
| 3 | `0x0200001a` `SET_ERROR_HANDLING_FEATURES` | `sn_setup` | row 41 `@0xffb13890`; `rt:0x45f0` | r8..r11 = 0 |
| 4 | `0x02000066` `SET_OS_FEATURE_SET` | `sn_setup`, four times (v5.3 only) | row 89 `@0xffb5fc90` | r8 = 0 for 2 and 3, -1 for 0 and 1 |
| 5 | `0x02000005` `GET_KLCONFIG_ADDR` | `build_cnode_tables` | row 18 `@0xffb19c20` (helper twin `rt:0xb4f0`) | r8 = 0, r9 = address |
| 6 | `0x01000012` `SAL_FREQ_BASE` | `sn_setup` (type 2), `ia64_init_itc` (type 0) | row 11 `@0xffb60270`; `rt:0x61410` | r9 = 20 MHz (type 2), 200 MHz (type 0) |
| 7 | `0x02000065` `GET_PROM_FEATURE_SET` | `sn_cpu_init`, second pass (v5.3 only) | row 90 `@0xffb60170` | set 0: r9 = 0xf; set 1: r8 = -2 |
| 8 | `0x0200001d` `GET_SAPIC_INFO` | `sn_cpu_init`, `sn2_send_IPI` | row 27 `@0xffb196c0`; `rt:0x85f0` | r8 = 0, r9 nasid, r10 0, r11 slice |
| 9 | `0x02000055` / `56` / `57` / `5a` (direct path) or `5f` (ACPI path) | `sn_fixup_ionodes`, `sn_pci_controller_fixup`, `sn_io_slot_fixup` | rows 82 to 86, 91 `@0xffb1e660` (one dispatcher) | see I/O section |
| 10 | console calls `0x02000021` to `2c` | `sn_console.c` | rows 43 to 54 `@0xffb16d50`...; `rt:0x78b0`... | r8 = 0 |
| 11 | `0x0200004a` `IOIF_INTERRUPT` | `sn_intr_alloc`, `sn_intr_free`, `sn_intr_redirect` | row 77 `@0xffb1f970` | r8 = 0, or -3 |

### SET_CPU_NUMBER (`0x02000068`)

- **Linux.** `sn_cpu_init` passes the logical CPU number and ignores the status.
- **PROM (established, `rt:0x47d0`).** Stores twice the logical number at offset `+0x110` of the per-processor record whose pointer sits at physical `0x1000000 + 8 * (n + 2)`, where n is bits 26:23 of `cr.lid` (the same pointer table the reset path uses for stacks). For logical CPU 0 it also runs `sal_event_boot_master`, clears the OS-feature word at block B `+0xc8`, and issues an internal physical-mode call for id `0x0200005b`. That case of the I/O interface dispatcher sets a flag at offset `0x20` of the I/O interface state; if the flag was already set it first runs a hub and bus re-initialisation (inferred from the callee names being the same helpers `IOIF_INIT` uses).
- **Consequence.** Linux must call this for CPU 0 before `SET_OS_FEATURE_SET`; it does, in that order. A kernel that reversed them would lose the ACPI and segment flags.
- **Returns.** r8 = 0.

### GET_SN_INFO (`0x0200001e`)

- **Linux.** Unpacks r9 into chip type, log2 system size, log2 sharing-domain size, partition id, coherency domain id, region size; r10 into NASID mask (bits 15:0) and shift (bits 23:16). Old PROMs answering "not implemented" get the kernel's built-in SHub 1 defaults.
- **PROM (established, `rt:0x31d0`).** Reads the local NASID from `0x1_1006_0580` bits 42:32, builds the chip record, then:
  - bits 7:0 (chip) = 0 (SHub 1; zero is never overwritten in this image);
  - bits 15:8 = 11 (log2 of 0x800 maximum NASIDs), bits 23:16 = 9 (log2 of 0x200), both constants;
  - bits 31:24 = one byte at offset 5 of the chip record (the kernel treats it as the partition id; where the record gets it is not read);
  - bits 39:32 = NASID divided by 512 (signed);
  - bits 47:40 = bits 52:48 of the same `0x1_1006_0580` register read;
  - r10 = `0x2607ff` (mask 0x7ff, shift 38), a constant; r11 = an uninitialised stack word, which the kernel ignores.
- **Single node.** NASID below 512 gives coherency id 0. The region-size byte and partition byte follow the register and the chip record, unknown on hardware; the PROM does write the node id and size fields of `0x1_1006_0580` itself ([prom-reset](../../devices/shub/prom-reset.md)).
- **Agreement.** Mask 0x7ff, shift 38, log2 sizes 11 and 9 and the region-size source (SHub 1 `SH_SHUB_ID` bits 52:48) are what the kernel's old-PROM fallback uses; the two agree.

### SET_ERROR_HANDLING_FEATURES (`0x0200001a`) and GET_ERROR_HANDLING_FEATURES (`0x02000063`)

- **Linux.** `sn_setup` calls `ia64_sn_plat_set_error_handling_features`, which passes `SAL_ERR_FEAT_LOG_SBES` (0x2, marked obsolete in the header) and ignores the status.
- **PROM (established that it walks the node list and records the request; inferred that this is "which error features the OS handles").** `sal_event_set_error_handling_features` (`rt:0x3fa80`) reads bits 0, 1, 2, 4 and 5 of the argument, walks the halfword node list in block A `+0x10`, and for each present node stores the decoded flags into that node's block through the remote window. The `GET` routine reads them back as r9, r10, r11 with r8 = 0 (`rt:0x46c0`; the `GET` call has no kernel caller in the files read).
- **Returns.** r8..r11 = 0.

### SET_OS_FEATURE_SET (`0x02000066`)

- **Linux.** Four calls from `sn_setup`: 0 (MCA slave to OS INIT slave), 1 (log SBEs), 2 (ACPI enabled), 3 (PCI segments enabled). Status ignored.
- **PROM (established, `0xffb5fc90`).** Only feature 2 and 3 do anything.
  - **2:** looks up the POD environment variable `NoACPIIO` for the local NASID. If it is unset, sets bit 2 of block B `+0xc8` and issues the internal physical call with id `0x0200005c` (the I/O dispatcher's "build the ACPI namespace" case, which hands block B `+0xc0` to a builder). If it is set, prints "SAL ACPI: ACPI IO disabled via NoACPIIO POD env variable" and does not set the bit. Status 0 either way.
  - **3:** calls a segment-enable routine (`0xffb20230`); if it returns 0 sets bit 3 of block B `+0xc8`. Status is the routine's result.
  - **0 and 1:** status -1 (not implemented), r9..r11 unset.
- **Single node.** Status 0 for 2 and 3, assuming `NoACPIIO` unset and the segment routine succeeds (unknown on hardware).

### GET_KLCONFIG_ADDR (`0x02000005`)

- **Linux.** `build_cnode_tables` calls it per NASID, `__va`s the address, walks the board list for TIO and headless nodes; it BUGs on a null address unless `SN_SAL_FAKE_PROM` answers.
- **PROM (established, `0xffb19c20`; the runtime has the same code as a helper at `rt:0xb4f0`).** Builds the chip record for the requested NASID, then asks whether that node has memory (`chipset_memless_node`: always "has memory" for the local NASID, otherwise a per-chip method at offset `0x168` decides). If not, status -2 and r9 = 0. Otherwise r8 = 0 and r9 = the word at block A `+0x20` of *that node's* block A (the local one for the local NASID, the remote one through the window otherwise), converted by `main_ptov` (identity in physical mode, which a physical-only SAL call always is), plus `0x10000`. r10 and r11 are unset stack words.
- **Single node.** Local NASID: r8 = 0, r9 = a node-local physical address 64 KiB into the PROM's reserved block. Whether the structure there matches `klconfig.h` is outside this page: [klconfig](../../platforms/sn2/klconfig.md) covers the layout.

### SAL_FREQ_BASE (`0x01000012`)

- **Linux.** `sn_setup` asks for type 2 (real-time clock) and falls back to 33.3 MHz (`1e12 / 30000`) if the call fails or the rate is under 100 kHz; the generic time code asks for type 0 (platform base) to derive the interval-timer frequency.
- **PROM (established, `rt:0x61410`).** The argument a1 picks the case; r10 comes back as -1 in all cases and r11 as 0.
  - **0:** r9 = 200,000,000 (`chipset_fsb_freq` returns the constant `0xbebc200`). If `cpuid[2]` equals `0xaeeeeeee8badbeef`, the value instead comes from counting entries of a table the simulation setup supplies at block A `+0x18` (not an Altix path).
  - **1:** status 0, r9 = -1.
  - **2:** r9 = `1,000,000,000 / (10 * (N + 1))` where N is bits 13:4 of `0x1_1006_0280`.
  - **Any other:** status -2.
- **Single node.** The PROM's reset path writes `0x1_0000_0041` there ([rtc_ctl](../../devices/shub/registers.md)), so N is 4, period 50 ns and type 2 returns 20,000,000. That a node still holds that value when Linux asks is inferred.
- **Disagreement (benign).** The kernel's fallback rate (33.3 MHz) is not what the PROM returns (20 MHz), so the fallback is never taken on a PROM that answers.

### GET_PROM_FEATURE_SET (`0x02000065`)

- **Linux.** Reads sets 0 and 1, stops at the first failure, keeps the words as a bit string; bit 0 PAL cache flush is safe, 1 per-device DMA flush lists, 2 hotplug, 3 CPU disable.
- **PROM (established, `0xffb60170`).** a1 = 0: status 0, r9 = the constant word at `0xffba20d8`, which holds `0xf` in the image (all four features offered). Any other set: status -2, r9 = 0. The word sits in the flash image; whether anything rewrites it at run time was not checked.
- **Single node.** Set 0: r9 = 0xf. Set 1: -2, so the kernel keeps only one word.

### GET_SAPIC_INFO (`0x0200001d`)

- **Linux.** `sn_cpu_init` (second pass) and `sn2_send_IPI` call it with the SAPIC id; v0 = NASID, v1 = subnode, v2 = slice. Kernel BUGs on a negative status unless "not implemented", which selects a fixed decoding (`nasid = id & 0xfff`, `subnode = (id >> 13) & 1`, `slice = (id >> 12) & 3`).
- **PROM (established, `rt:0x85f0`).** Pure arithmetic on the 16-bit id, no register access: r8 = 0, r9 = `(id & 0x7f) | ((id >> 11) << 7)` (a 12-bit NASID), r10 = 0, r11 = `(id >> 7) & 0xf`.
- **Disagreement.** The PROM's decoding is not the kernel's fallback: slice sits in bits 10:7 here and the NASID's top five bits in 15:11, against slice in 13:12 in the fallback. They only coincide for ids the fallback was not written for. The earlier [firmware page](../firmware/snprom/README.md) records a different decoding for the 4.43 and 1.40 images (a doubled NASID, slice in bits 9:7); those builds were not re-read here, so the three decodings are different builds, not a contradiction. Which is right for a given CPU id format depends on how the SHub 1 board lays out `cr.lid`, which is unknown.

### Console (`0x02000021` to `0x0200002c`)

- **Linux.** `sn_console.c` (and the early console) uses `PUTB` and `XMIT_CHARS` for output, `POLL`, `READC`, `GETC` for input and `INTR` for interrupt masks. Status 0 means the call worked.
- **PROM (established as the dispatch, inferred for the device).** The runtime handlers (`salruntime_console_*`, `rt:0x78b0` to `0x8400`) call `console_rt_*`, which look up the active device record from block B `+0x88` and a table at `rt:0xa8f70`, and call function pointers from the device (offset `0x18` for `READC`, `0x40` for `XMIT_CHARS`, `0x48` for `INTR`). `PUTB` and `POLL` go to a shared routine. The device backends in the runtime are an L1/L2 controller transport (`l1sc_*`, `sc_tdr_*`) and per-chip UART front ends (`sc_nl4r_*`, `sc_tio_*`); which one the Altix 350 selects is not read.
- **Returns.** `PUTB`, `XMIT_CHARS`, `POLL`: r8 = 0 with r9 the count taken or the input-available flag. `READC`: r8 = 0 or -3 when the device returns a negative value, r9 the character. `INTR`: r8 = 0 or -1, r9 the pending mask.
- **Grade.** Established that these routes exist and what each returns when the device routine succeeds; inferred which device an Altix 350 console is.

### I/O interface calls (`0x51` to `0x5f`, `0x60`, `0x64`)

All of them share one SAL_B routine (`0xffb1e660`, named in its own diagnostic `salruntime_sn_pciio`), a switch on `id - 0x02000051` over 20 cases. A case it does not handle prints "Unhandled SN_SAL_IOIF call" and returns -3. The PROM's I/O object model: block B `+0x40` holds a per-NASID table of node records at `+0x70`; each node record carries up to 16 widget provider entries of 0x30 bytes starting at `+0x940`, and a hub operations table at `+0x2d8`. A bus object type picks its operations table from `0xffc2afa0`.

- **`0x55` `GET_HUBDEV_INFO`.** Linux (direct path) passes the NASID and a `hubdev_info` buffer that it prefilled with `max_segment_number = 0xffffffff`, `max_pcibus_number = 0xff`; reads v0 and treats non-zero as failure. *PROM (established):* the first I/O-interface call after a clear performs the deferred hub and bus initialisation (the same work `0x5f` does), then copies the node's `0x2f0`-byte record into the buffer, fills the widget table from the node record, and overwrites the two maxima (`+0x2e8`, `+0x2ec`) from block B state. r8 = 0, v0 (r9) = 0 if the NASID is on the node list, 1 if not. *Single node:* v0 = 0 for the local NASID.
- **`0x56` `GET_PCIBUS_INFO`.** Linux passes a segment, a bus number and the physical address of a pointer, and treats v0 > 0 as "no such bus". *PROM (established, `0xffb1f2f6` region):* looks the pair up in two PROM lists, stores the match (or null) through the pointer, r8 = 0, r9 = 1 when nothing matched, else 0. This agrees with the kernel's use.
- **`0x57` `GET_PCIDEV_INFO`.** Segment, bus, devfn, a `pcidev_info` buffer and an `sn_irq_info` buffer; the kernel BUGs if it fails. *PROM:* routine at `0xffb3dbc0` fills both; r9 is its result. The fields were not read (unknown).
- **`0x58` `GET_WIDGET_DMAFLUSH_LIST`, `0x5a` `GET_DEVICE_DMAFLUSH_LIST`.** Helpers at `0xffb3d290` and `0xffb3d5d0`; `0x5a` converts its buffer address with `tpa` first. r9 is the helper result. Fields unknown. These are the "per-device DMA flush" feature (PROM feature bit 1).
- **`0x5f` `IOIF_INIT`.** Linux (ACPI path) requires status and v0 both 0. *PROM (established):* runs two helpers and returns r8 = r9 = 0. The first (`0xffb29390`) calls the late-initialisation method (hub operations `+0x20`) of every hub on the node list. The second (`0xffb2c370`) calls the late-init method (`+0x88`) of every bus object in three lists in block B state (`+0x88`, `+0x98`, `+0x90`) and then runs `0xffb2c2e0` on every object that has a resource block, which builds the per-device data the kernel later reads. This is also what the first `0x55` call does on a direct-path kernel.
- **`0x51` `IOIF_ERROR_INTERRUPT`.** Segment and bus; *PROM (established):* finds the bus object and calls its operation at `+0x90`; v0 = the result. Single node: depends on the bridge, not read.
- **`0x52` `IOIF_PCI_SAFE`.** *PROM (established):* finds the bus object, picks its I/O or memory window by a3, adds the port number and calls its `+0x30` operation with size and data pointer. status 0.
- **`0x53` `SLOT_ENABLE`, `0x54` `SLOT_DISABLE`.** Bus operations at `+0xa0` and `+0xa8`; with the ACPI flag set (block B `+0xc8` bit 2) enable also builds an SSDT through `0xffb52330`. Not called at boot.
- **`0x59`.** Returns 0 with no effect. **`0x5b`, `0x5c`, `0x5d`, `0x5e`.** Internal ids: `0x5b` allows re-initialisation (set by `SET_CPU_NUMBER` 0), `0x5c` builds the ACPI namespace (set by `SET_OS_FEATURE_SET` 2), `0x5d` is the VGA-console selector the firmware's EFI side calls, `0x5e` takes a NASID and runs one method. No kernel caller.
- **`0x60` `HUB_ERROR_INTERRUPT`.** NASID; *PROM (established):* calls the node's hub operation at (record `+0x2d8`) `+0x40`; v0 = its result, which the kernel treats as fatal when non-zero. Unknown on hardware.
- **`0x64` `GET_PCI_TOPOLOGY`.** `0xffb44bf0(buffer, length)`; r9 its result. Content unknown.
- **`0x61` `BTE_RECOVER`.** Own routine (`0xffb5fb50`): calls a stub at `0xffa95970` that only returns -1 and maps that to status -1. The kernel's SHub 2 code treats -1 as success (established; stub body one instruction).

### IOIF_INTERRUPT (`0x0200004a`)

- **Linux.** `sn_intr_alloc`, `sn_intr_redirect`, `sn_intr_free` pass: a1 op (1 alloc, 2 free, 3 redirect), a2 NASID of the bridge, a3 widget, a4 physical address of an `sn_irq_info`, a5 to a7 (requested irq, target NASID, target slice) for alloc; free passes the irq in a4 and the cookie in a5.
- **PROM (established, `0xffb1f970`).** Finds the provider for (NASID, widget) through block B state `+0x70` and the widget table at `+0x958 + 0x30 * widget`; a null provider prints "salruntime_sn_xtalk: NULL provider pointer" and returns -3. Then:
  - **alloc:** calls the provider's operation at `+0x28` with the NASID, requested irq, requested target NASID (16 bits) and slice (32 bits), and an out-pointer; a negative result gives -3. On success copies seven fields of the PROM's interrupt record into the kernel's record: `irq_nasid` (+0x08), `irq_slice` (+0x0c), `irq_irq` (+0x14), `irq_xtalkaddr` (+0x20), `irq_cookie` (+0x44), `irq_flags` (+0x48), `irq_share_cnt` (+0x4c) (offsets from `struct sn_irq_info`, v5.3 `intr.h`). Status 0.
  - **free:** looks up the record in the per-irq list at block B state `+0x78` (indexed by irq) by cookie, calls the provider's `+0x30`; -3 if not found.
  - **redirect:** same lookup keyed on the record's irq and cookie, provider `+0x38` with the new NASID and slice; on 0 copies back NASID, slice and xtalk address.
  - Anything else prints "Invalid provider_call" and returns -3.
- **What the provider does inside** (the SHub interrupt-target and PIC/TIO interrupt-address programming) is not read here; see [interrupts.md](../../devices/shub/interrupts.md) for what the first-stage code does and the open item in [../../questions/sn2-sal-open.md](../../questions/sn2-sal-open.md).

## Other calls the kernel makes after boot

| Call | Linux caller | PROM routine | Reads or writes | Returns (single node) | Grade |
|---|---|---|---|---|---|
| `0x02000004` `GET_MASTER_NASID` | `sn_hwperf_init` (via the console NASID), console routing | row 17 `@0xffb60a40`; `rt:0x35d0` | halfword at the address in block B `+0x100` | r8 = 0, r9 = master NASID (sign-extended 16 bits) | established; value unknown |
| `0x0200003c` `GET_MASTER_BASEIO_NASID` | no caller in the files read | row 67 `@0xffb60910`; `rt:0x34a0` | block B `+0x28` | r8 = 0, r9 = that word | established; value unknown |
| `0x02000003` `PROBE` | `pci_dma.c` (2.6.12), PCI-safe fallback | row 16 `@0xffb23cb0`; `rt:0x1d570` | `sal_event_probe`: a protected read of the I/O address, size 1 to 8 | r8 = 1 when the helper `sal_event_probe` returns 0, else 0; r9 = the data word. Which helper result means "machine-checked" was not resolved (the kernel expects 1 for a fault) | established (mapping); polarity unknown |
| `0x0200001b` `GET_FIT_COMPT` | `prominfo_proc.c` `get_fit_entry` | row 25 `@0xffb18d50`; runtime wrapper `rt:0x61050` | reads the firmware interface table through the node's flash window (`0x8000_000f_ff80_0000` plus NASID shift); pointer at flash offset `0x7fffe0` | r8 = 0 and the 16-byte entry written to the a3 buffer; r8 = -2 if the index is past the table or the pointer is outside `0xff000000..0xffffffff`; index -2 returns the lowest component address, index -1 finds a type match; an optional banner copy to a4 (limited by a5) | established |
| `0x02000038` `SYS_SERIAL_GET` | `/proc` and licence code | row 62 `@0xffb1c6c0`; `rt:0xd240` | copies the string block B `+0x98` points to into the a1 buffer | r8 = 0 | established; string unknown |
| `0x02000039` `PARTITION_SERIAL_GET` | `/proc` | row 63 `@0xffb1c7a0`; `rt:0xd320` | same string plus block B `+0xa0` | r8 = 0, r9 = `(type letter & 0xf) << 28 | (field & 0x3f) << 22 | atoi(digits) & 0x3fffff`, with a module flag mixed into the low nibble when the first character is `N` or `R` | established as arithmetic; meaning of the fields inferred |
| `0x0200003a` `SYSCTL_PARTITION_GET` | old-PROM fallback of `GET_SN_INFO` | row 64 `@0xffb1cdd0`; `rt:0xd950` | system-controller table lookup by NASID | r8 = -3 when the lookup returns -1, else 0; r9 = partition byte | established mapping; lookup internals not read |
| `0x02000030` `SYSCTL_OP` | PCI bridge and TIO code | row 56 `@0xffb1d910`; `rt:0xe490` | op 1: board-type lookup by NASID (`0xffac0420`), -3 if it fails; ops 2 and `0x200f`: TIO clock reset helper (`0xffa80580`), -3 if non-zero; other ops -1 | r8 = 0, -3 or -1 | established mapping; helpers inferred |
| `0x02000050` `HWPERF_OP` | `sn_hwperf.c` | runtime only, row 75 `rt:0x8650` | pcfg object table in block A `+0x40`, 0x48 bytes per object | see below | established for the opcodes; payloads inferred |
| `0x02000061` `BTE_RECOVER` | `bte.c`, SHub 2 only | row 75 `@0xffb5fb50` | nothing (stub) | r8 = -1 | established |
| `0x02000006` `LOG_CE` | `sn_cpei_handler` | row 19 `@0xffb13070`; `rt:0x3dd0` | calls `plat_poll` | r8..r11 = 0 | established |
| `0x02000012` `PRINT_ERROR` | `sn_platform_plat_specific_err_print` | row 21 `@0xffb13570`; `rt:0x42d0` | `sal_log_print_section(record, length, 1)` | r8..r11 = 0 | established |

### HWPERF_OP (`0x02000050`)

The PROM tests the opcode with the copy-in and copy-out flag bits left in (`0x1000`, `0x2000`, `0x3000` are the kernel's flags and the kernel passes them through). Handled ids: `1` (get heap size), `2` (install heap), `0x10`, `0x11`, `0x12` (acquire, release, force release), `0x100e` (set MMRs), `0x200a`, `0x200b`, `0x200c`, `0x200d` (object count, object distance, enumerate objects, enumerate ports) and `0x300f` (get MMRs). Every other value returns 254 (invalid).

- **`1`:** requires a size argument of at least 8 bytes (else status 1, "no memory"); counts the type-7 objects in the platform configuration, stores that count in the object table, writes `count * 0x48` through the pointer. Status 0.
- **`2`:** status 254 if there are no objects, 1 if the buffer is smaller than `count * 0x48`; otherwise zeroes it and fills one 9-word record per object (index, a lock word, the chip identity words, the chip-function pointer). Status 0.
- **`0x11`, `0x12`, `0x100e`:** need the object table (254 if the count is zero or the object index is out of range), then call an operation of the object's chip-function table: `+0x370` for release, `+0x378` for force release, `+0x358` for set MMRs. Status = 0, or the operation's result negated if it is negative. **`0x10`** (acquire), **`0x200a` to `0x200d`** and **`0x300f`** take other branches that were read for their error returns only (254 for a bad object, 1 for a short buffer, 0 on success).
- **Single node:** object count is the number of type-7 pcfg objects (SHub, any TIO or router the PROM discovers), which the kernel exposes in `/proc/sgi_sn/sn_topology`. The count itself is hardware-dependent: unknown.

## Standard SAL calls

All are in both tables unless noted. Linux callers: `mca.c`, `smpboot.c`, `time.c`, `salinfo.c`.

| Call | Linux caller and use | PROM routine | What it does | Returns |
|---|---|---|---|---|
| `0x01000000` `SET_VECTORS` | `ia64_mca_init` (MCA, INIT) and `smp_callin` setup (boot rendezvous) | row 0 `@0xffb129e0`; `rt:0x3740` | `sal_event_register_os_handler` (`rt:0x3f360`): walks the node list in block A `+0x10` and stores the entry point, gp and length into each node's own record through the remote window; a bad type is ignored | r8..r11 = 0 |
| `0x01000001` `GET_STATE_INFO` | MCA, CPE and INIT logging | row 1 `@0xffb12ad0`; `rt:0x3830` | `sal_log_get_record` copies the pending record into the buffer | r8 = status from the log layer, -5 when the log call reports success with a zero status; r9 = record length (inferred) |
| `0x01000002` `GET_STATE_INFO_SIZE` | the same, to size buffers | row 2 `@0xffb12c00`; `rt:0x3960` | helper `rt:0x419c0` returns the record size | r8 = a status word the helper may set (0 at entry), r9 = the helper's result sign-extended from 32 bits |
| `0x01000003` `CLEAR_STATE_INFO` | after reading a record | row 3 `@0xffb12ce0`; physical only | not read | not read |
| `0x01000005` `MC_SET_PARAMS` | `ia64_mca_init`: a1 = 1 rendezvous interrupt, 2 wakeup, 3 CPE interrupt | row 5 `@0xffb12dd0`; `rt:0x3b30` | 1: registers the rendezvous vector (rejected, -2, above `0xbf67`); 2: wakeup by vector (mechanism 1) or memory location (mechanism 2); 3: CPE interrupt vector; other types -2 | r8 = 0 or -2, r9 = `0xbf68` always |
| `0x01000004` `MC_RENDEZ` | `ia64_mca_rendez_int_handler` | row 4 `@0xffb12fb0`; `rt:0x3d10` | rendezvous entry | r8..r11 = 0 |
| `0x01000008` `CACHE_FLUSH` | not on the boot path in the files read | row 7 `@0xffb16340`; `rt:0x6ea0` | loops on `PAL_CACHE_FLUSH`; when PAL returns 1 it writes the node's MMR at offset `0x9_1000_0380` (window `0x8000_0009_1000_0380`, node id from `cr.lid`) with a value built from `cr.lid` and the PAL result, then retries; afterwards it flushes the chip's caches unless the cache type is 4 | r8 = 0, or -3 if the chip flush fails; r9 to r11 from stack |

## Where Linux and the PROM disagree

1. **`GET_SAPIC_INFO` decoding.** PROM 5.04: NASID bits 6:0 plus 15:11, slice bits 10:7; kernel's old-PROM fallback: NASID 11:0, slice 13:12, subnode bit 13. Different formats; the kernel uses the fallback only when the PROM answers "not implemented", which this PROM does not.
2. **`SAL_FREQ_BASE` real-time clock rate.** PROM: 20 MHz (from `rtc_ctl`); kernel fallback 33.3 MHz. The fallback is a failure default, not a claim.
3. **`GET_PROM_FEATURE_SET`.** The kernel loops over sets until one fails; this PROM has exactly one (set 0) and answers set 1 with -2. Not a conflict, but a model must return -2, not zero, for set 1 or the loop never ends.
4. **`SET_OS_FEATURE_SET` 0 and 1.** The kernel says they tell the PROM about MCA slave handling and SBE logging; the PROM returns -1 and does nothing, so the hardware's MCA behaviour does not depend on them.
5. **`GET_PCIBUS_INFO` result register.** The kernel reads v0 (r9) for "no such bus"; the PROM sets r9, not r8, for that. A model that signals missing buses only in status would break the PCI scan.
6. **`BTE_RECOVER`.** Kernel comment: SHub 2 BTE recovery. SHub 1 PROM: stub, status -1. The kernel treats -1 as success.
7. **Memory-less node and `GET_KLCONFIG_ADDR`.** The kernel expects a non-null address for every node it asks about except under the fake PROM; the PROM answers -2 with r9 = 0 for a NASID whose node it cannot find memory for, and the kernel BUGs on null. A model must not be asked about absent NASIDs.
8. **v2.6.12 versus v5.3.** The 2.6.12 kernel does not call `SET_CPU_NUMBER`, `GET_PROM_FEATURE_SET`, `SET_OS_FEATURE_SET`, `BTE_RECOVER`, `HUB_ERROR_INTERRUPT` or `IOIF_INIT`; its I/O path is `0x55`, `0x56`, `0x57`, `0x58`. The held 2.6.5-7.244 kernel's call list is on the [firmware page](../firmware/snprom/README.md#sal-dispatch).

## What a synthetic SAL for one node must do

The minimum answer set for an Altix 350 kernel to reach multi-user, in the order above:

1. `SET_CPU_NUMBER`: status 0.
2. `GET_SN_INFO`: r8 = 0; r9 with chip 0, log2 sizes 11 and 9, a partition byte, coherency id NASID/512, a region byte; r10 = `0x2607ff`.
3. `SET_ERROR_HANDLING_FEATURES`: status 0. `SET_OS_FEATURE_SET`: status 0 for 2 and 3, -1 otherwise.
4. `GET_KLCONFIG_ADDR`: status 0 and a physical address of a valid board list for the local NASID; -2 for others.
5. `SAL_FREQ_BASE`: type 0 = 200,000,000; type 2 = 20,000,000.
6. `GET_PROM_FEATURE_SET`: set 0 = 0xf, set 1 = -2.
7. `GET_SAPIC_INFO`: the formulas above.
8. `GET_HUBDEV_INFO`, `GET_PCIBUS_INFO` (with r9 = 1 for a missing bus), `GET_PCIDEV_INFO`, DMA flush lists, or `IOIF_INIT` plus the ACPI namespace.
9. Console `PUTB`, `XMIT_CHARS`, `READC`, `POLL`, `INTR`.
10. `IOIF_INTERRUPT` alloc, free, redirect with the seven copy-back fields.
11. `SET_VECTORS`, `MC_SET_PARAMS` (r9 = `0xbf68`), `GET_STATE_INFO_SIZE`, `GET_STATE_INFO`.

Everything else the kernel tolerates as "not implemented" (-1); the unknown-id path of the PROM returns exactly that.

## Not read

- The provider operations behind `IOIF_INTERRUPT` and the bus object's methods (SHub interrupt targets, PIC and TIO interrupt address programming, bridge error decode), and the bodies of `GET_PCIDEV_INFO`, the DMA flush lists and `GET_PCI_TOPOLOGY`: the question stays open in [questions/sn2-sal-open.md](../../questions/sn2-sal-open.md).
- The console device backends, which one the Altix 350 picks, and the L1 requests behind them.
- `CLEAR_STATE_INFO`, `SAL_PCI_CONFIG_*`, `REGISTER_PHYSICAL_ADDR`, `UPDATE_PAL`, `PHYSICAL_ID_INFO`, `SN_SAL_COHERENCE`, `MEMPROTECT`, `XP_ADDR_REGION`, the `SYSCTL_*` calls other than the ones above, `IROUTER_OP`, `SYSCTL_EVENT`, `BUS_CONFIG`: handlers named on the [firmware page](../firmware/snprom/README.md#sal-dispatch), not read here.
- Any SHub 2 image: this page reads only the SHub 1 SAL 5.04 build.
