# SN2 PROM: starting the other processors, the clocks, and machine checks

How the SHub 1 PROM (snprom 10.54, `shub1snprom.bin`: SAL_B 5.04 at `0xffa00000`, PAL_B 5.73 at `0xffe78000`, SAL runtime component read as `rt:0x...`) brings up more than one processor, which clock values it reports, and what happens on a machine check or INIT. What Linux ia64 asks of it at each step is tied to the handler that answers. Linux is the public `linux-history` tree (`arch/ia64/kernel/smpboot.c`, `sal.c`, `mca.c`, `arch/ia64/sn/kernel/{setup.c,sn2/sn2_smp.c,sn2/timer.c}`, `asm/sal.h`); it has the SN2 platform code and is a later tree than v5.3, which matters only where noted.

Method: Ghidra (`--sn2-prom --no-analysis`, address ranges, plus `--sal-runtime` for the runtime's own symbol names), cross-checked against a flat `ia64-linux-gnu-objdump` listing of the same image and of the inflated runtime ELF. Grades: **established** = the whole routine was read; **inferred** = a reasoned reading, reasoning given; **unknown** = not settled. No run of any model backs a grade. Register-level interrupt facts are in [interrupts.md](../../../devices/shub/interrupts.md), the `cpu_bits` word and node lock in [prom-reset.md](../../../devices/shub/prom-reset.md#the-node-lock-used-by-a28-a29-a34-and-a37).

## 1. Starting the other processors, in the PROM

### Two different things are called "slave"

| Meaning | Who | Mechanism |
|---|---|---|
| **Slave thread**: a second hardware thread of one core | `cpu_launch_slave_threads` (`0xffa10f40`) wakes it | IPI vector 0 |
| **Slave processor**: another slice or socket that is not the boot processor | the slave loop (`0xffafcdd0`) holds it | busy poll for vector `0x12` |

Other slices are **not** woken by an IPI at all on the way up. Every present slice runs the same code from reset, in step, and is told apart by `cr.lid` and by the `cpu_bits` flag word. The wake IPI exists for threads. (established)

### Slice rendezvous (all established)

Every processor starts at the PAL, enters SAL_A, and runs the SAL_B reset entry (`0xffa01000` to `0xffa1de00`) and `main` (`0xffa19a20`). They differ only in `cr.lid` bits 26:23 (slice, called `n` below).

| Step | Site | What it does |
|---|---|---|
| Election in SAL_A | `0xffc4e970`, `0xffc4ea6c` | `0x81_101d_0088` <- n+1, read back `0x81_101d_0080`; the winner zeroes `cpu_bits` and sets `SH1_IPI_ACCESS`. See [boot-sequence.md](boot-sequence.md#sal_a-on-shub-1) |
| Present flag | `0xffa1e61c` (A28) | each slice sets `cpu_bits` bit 21+n (`0x1_5003_1550`, under the node lock `0x1_101d_0200/0208`) |
| Local master | `0xffa99cf0` (in `main`) | sets bit 26+n; slice n reads `0x1_2002_0080` for slices 0 and 1 to count present processors; the master (below) polls bits 29:26 every 500 microseconds up to 5 s |
| Barrier | `0xffa9a130`, called at `0xffa19ba0`, many more places in `main`, `main_two` and `main_three` | bits 30+n, 34 and 26+i; exits when bit 30+i equals bit 26+i for all four i |
| Master test | `0xffa0ff30` | returns 1 when no lower slice has bit 26+i set. "Master" is therefore the lowest present slice. It guards the once-per-node work (memory, PAL shadow rebuild, I/O) |

`cpu_bits` bit meanings used by the sequencing: 21+n present-at-jump (cleared by `0xffacd2b0` for the node-ID change, set again in `main_three`), 26+n present/ready, 30+n barrier phase, 34 barrier exit, 13 to 15 record flags (set by `0xffa44ba0`), 1 and 0 partition and global master. The bit meanings are inferred from use; the sequences are established. All bits are plain storage plus the lock.

### PAL per-processor work, in order (established unless marked)

1. PAL_A/PAL_B reset: self-test and cache init are PAL's own, before SAL_A ([pal-b-halts.md](pal-b-halts.md)). SAL_A then reports to PAL (reason 0) and SAL_B starts.
2. SAL_B reset entry, `0xffa1de00`: progress 0x31, 0x35. **First thing a non-zero thread does:** `0xffa1e180` calls `0xffa9ac80` (below).
3. `main`: slice rendezvous above, memory and node set-up on the master.
4. Jump to RAM `0xffac6bb0` (progress 0x19, 0x40 to 0x45): **PAL_COPY_INFO (PAL 30) then PAL_COPY_PAL (PAL 256) on each processor, master first, node barrier between**, store the copy as that processor's PAL entry (`0xffa1d690`, per-CPU record `[0x1000000 + 8*(2+n)]` field `+0x88`); PAL_MEM_FOR_TEST (37) and PAL_TEST_PROC (258) run the CPU test from `0xffaf5c80` on each processor ([the jump to RAM](boot-sequence.md#pal-boundary)). Family-0x20 CPUs skip the shadow.
5. `main_two` `0xffa1ade0` (progress 0x1a to 0x1e), then `0xffacd2b0` / `main_three` `0xffad7280` (0x21 to 0x27). The cache init the SAL does itself is PAL_CACHE_INIT (3) only in the halt routine `0xffaeb7c0` and the cache-flush SAL call.

### Slave threads: wake and park (established)

- **Count and identity.** `0xffa9ad80` = number of logical processors = PAL_LOGICAL_TO_PHYSICAL(-1) bits 15:0, or 1 if PAL answers -1 (unimplemented). `0xffa9af30` = PAL_FIXED_ADDR (12). `0xffa9b050` finds the logical entry whose PAL r11 low 16 bits equal the fixed address; `0xffa9b110` returns that entry's thread field (PAL r10 bits 15:0; "thread id" by the string `logical thread id: %x`, inferred). With PAL_LOGICAL_TO_PHYSICAL unimplemented every processor is thread 0.
- **Park.** `0xffa9ac80` (call at `0xffa1e180`): if the thread field is 0, return at once. Otherwise loop on PAL_HALT_LIGHT (PAL 29) until `cr.irr0` bit 0 (vector 0) is pending. A PAL image whose halt returns for any interrupt is fine; only vector 0 ends the loop. This is the only "wait for IPI" in the pre-EFI path.
- **Wake.** `main_two` calls `0xffa11330` (true when thread field is 0) and then `0xffa10f40`, the runtime's `cpu_launch_slave_threads`. It writes 1 to `0x1_1000_0400` (`SH_IPI_INT_ENABLE`) of its own node, then for every logical entry i whose PAL r10 field equals this processor's (same core) **and whose thread field is non-zero** writes `0x8000_0000_0000_0000 | (pid << 4)` (type 0, vector 0) to `0x8_0000_0000 + (nasid << 38) + 0x1_1000_0380`. pid is rebuilt from the entry's id/eid as in [interrupts.md](../../../devices/shub/interrupts.md#processor-id-and-message-layout-the-prom-uses). The earlier statement there that the sender is not visibly excluded is settled: thread 0 is skipped by the non-zero test.
- **Not Madison.** On a processor without threads (PAL_LOGICAL_TO_PHYSICAL = -1) nothing is sent at all.
- **What a model must give:** a store of type 0, vector 0 must set `cr.irr0` bit 0 on the target even though vector 0 is architecturally reserved (software expectation; whether hardware latches it: **unknown**).

### Where the other slices park while EFI runs (established as code)

1. All slices run `main_three` to its end. There, `main_three` picks the boot processor: if `cpu_bits` bit 14 is clear, `0xffae77a0` is true for exactly the present processor with the lowest (NASID, slice) key in the block A `+0x18` processor table (halfword pid, flags bit 0 present; the key orders by NASID then slice). If bit 14 is set an indirect hook (`0xffa1f7b0`, through a function pointer found via `0xffae10f0`, record `+80`) decides instead; what it points to is **unknown**.
2. Every other processor calls `0xffafd310` (`0xffad77dc`, `0xffad785c`): it loads a fresh stack from its per-CPU record (`[0x1000000 + 8*(2+n)] + 0xc0`, sp at +0x3ff0), and runs `0xffaf5c80` with packed argument `0xfffe` (no PAL test) into the slave loop `0xffafcdd0` (descriptor `0xffc4be10`, table slot `0xffc4d978`).
3. The slave loop (progress 0x46 "In slave loop"): finds its record `rec = main_ptov([block A + 0x90])`, publishes a mailbox in its per-CPU record `+0xd8` (signature `0x43505543616c6c53`, flags and fields at +8, +16, +20, +48, +56), **sets its boot state to 1**, then polls `cr.irr` for vectors `0x12` and `0x13` (`0xffafcd00`: `cpu_interrupt_pending` `0xffa100e0`, then `cpu_interrupt_clear` `0xffa101e0`). It does not halt; it busy-polls.
4. The boot processor goes on to `0xffaf8c50` (progress 0x27 to 0x48, "Jumping to EFI").

The boot state is the 2-bit field at bits 51:50 of a per-slice SHub register (`mcrz_flg`, table indexed by slice; its register offsets were not decoded: **unknown**). Values: 1 parked, 2 awake or boot master, 3 dropped. Writers: `0xffa03eb0` (local), `0xffa03f20` (remote). Runtime twins `sal_event_set_boot_state` `rt:0x3b2c0`, `_remote` `rt:0x3b330`, reader `rt:0x3b3d0`.

### What releases a parked processor (established as code)

- **Vector `0x12`** (type 0, external interrupt; the SAL system table's AP wake-up descriptor names it, [os-handoff-tables.md](os-handoff-tables.md#3-the-sal-system-table) row `0xd0`): the loop clears the mailbox word at `+16`, sets boot state 2, progress 0x47 "Waking up slave CPU", loads `gp = [rec + 80]` and `entry = [rec + 72]` and calls `entry` through `0xffb55c60`. `rec + 72, 80, 88` is where `SAL_SET_VECTORS` type 2 (OS boot rendezvous) stores the OS entry, gp and length (below). If the entry returns, `0xffb55c60` resets the register stack and re-enters the slave loop. Nothing else is set up for the entry: `r1` is the gp, the return address is in the PROM, translation and interrupt state are whatever the slave loop runs in (physical mode by its `rsm 0x24000` pattern: inferred).
- **Vector `0x13`**: a call-on-processor request with a signature check: the loop calls `0xffb035e0` with the five mailbox fields and stores the result in the mailbox (`+56`), then re-polls. Used by SAL services that need code run on another processor.
- **The SAL's own cross call reuses `rec + 72/80` and vector 0x12.** Sender `0xffafd120(descriptor, arg, pid)` (call site `0xffb0914c`) writes the descriptor's entry at `rec+72` and the argument at `rec+80` **of the target's record** and sends type 0, vector `0x12` (`0x8120_0000_0000_0000 | pid << 4`, store to `0x8_0000_0000 + nasid<<38 + 0x1_1000_0380`). So the OS boot-rendezvous storage and the SAL's internal wake share one slot: after `SET_VECTORS` type 2 the entry is the OS's, and a SAL cross call overwrites it.
- **Boot-master check.** `SN_SAL_SET_CPU_NUMBER(0)` (`rt:0x47d0`) runs `sal_event_boot_master` (`rt:0x40830`): sets its own state to 2, then for every other present processor whose state is not 1 sets state 3 and clears its `cpu_bits` present bit 26+slice. A processor that has not parked by the time CPU 0 enters Linux's `sn_cpu_init` is dropped. Every processor stores `2 * n` at `+0x110` of its own per-CPU record on its own `SET_CPU_NUMBER(n)`.

## 2. Linux SN2 start-up, step by step

| # | Linux (file, function) | Call or access | PROM handler | Result |
|---|---|---|---|---|
| 1 | `sal.c` `ia64_sal_init` | SAL system table, AP wake-up descriptor (type 5): `ap_wakeup_vector = vector` | table builder, `0xd0` row | mechanism 0, vector `0x12` (established) |
| 2 | `sal.c` | platform features descriptor: `sal_platform_features` | `0x90` row | byte 8 = ITC drift only |
| 3 | `sn/kernel/setup.c` `sn_cpu_init`, CPU 0 (once) | `SN_SAL_GET_SN_INFO` then `SN_SAL_SET_CPU_NUMBER(0)` (`0x0200_0068`) | row `rt:0x47d0` | `sal_event_boot_master` (section 1) |
| 4 | `smpboot.c` `init_smp_config` | `SAL_SET_VECTORS(2, fp, gp, 0, 0, 0, 0)` with physical `start_ap` | `0xffb129e0`, `rt:0x3740` -> `rt:0x3f360` | stores entry, gp, len at `rec+72/80/88` of **every** present node's record (block A +0x90 of each node, remote window), nothing else; status 0 |
| 5 | `mca.c` `ia64_mca_init` | `SAL_MC_SET_PARAMS`, `SAL_SET_VECTORS` 0 and 1 | see section 4 | |
| 6 | `smpboot.c` `do_boot_cpu` (BSP, per AP) | `set_brendez_area`, then `platform_send_ipi(cpu, ap_wakeup_vector, IA64_IPI_DM_INT, 0)` | none (SHub hardware) | |
| 6a | `sn2_smp.c` `sn2_send_IPI` -> `sn_send_IPI_phys` | `nasid = cpuid_to_nasid` (or `SN_SAL_GET_SAPIC_INFO(physid)` if still -1 during boot), one 64-bit PIO store to `GLOBAL_MMR_PHYS_ADDR(nasid, SH_IPI_INT)` = `0x1_1000_0380` of that node: `1<<63 | physid << 4 | type << 0 | vector << 52 | 0xfee << 21`; vector `0x12`, type 0 | the parked processor's slave loop polling `cr.irr` for `0x12` | the target pid must be the PROM's own encoding (`cr.lid` bits 31:16). Linux's base field `0xfee` is ignored by the PROM-side code |
| 7 | AP, `0xffb55c60` | jumps to `start_ap` with gp from `rec+80` | | |
| 8 | AP `start_secondary` -> `cpu_init` -> `sn_cpu_init` | `GET_SN_INFO`, `SET_CPU_NUMBER(cpuid)` (every non-boot CPU, `rt:0x47d0`: store `2*cpuid` at `rec+0x110`), feature-set and `GET_SAPIC_INFO` calls | as [sn2-runtime.md](../../sal/sn2-runtime.md) | `rt:0x47d0` does not call `sal_event_boot_master` for n != 0 |
| 9 | AP `smp_callin` | `ia64_sync_itc` **skipped** because the ITC-drift feature bit is set; `ia64_init_itm` asks `SAL_FREQ_BASE`, `PAL_FREQ_RATIOS` | section 3 | |
| 10 | AP | sets `cpu_callin_map`; BSP's 10 s timeout ends | | |

**Not established:** the exact processor state at entry to `start_ap`. SAL spec says physical mode, `psr.ic` 0 and interrupts disabled; this PROM's slave loop sets none of it explicitly. **Unknown** until the loop's own PSR is read.

## 3. Clocks

All three come from one decision: the PROM exposes a fixed 200 MHz platform base, derives the ITC from a PAL ratio, and runs the real-time clock off a separate period register.

| Quantity | Value | Source (all established unless noted) |
|---|---|---|
| `SAL_FREQ_BASE` type 0 (platform base) | **200,000,000** Hz (`chipset_fsb_freq` returns the constant) | `0xffb60270` row 11, `rt:0x61410` / `rt:0x61c40`; with `cpuid[2] == 0xaeeeeeee8badbeef` (simulator signature) it counts table entries instead |
| `SAL_FREQ_BASE` type 1 (ITC) | status 0, r9 = -1 | same routine |
| `SAL_FREQ_BASE` type 2 (RTC) | `1e9 / (10 * N + 10)`, N = bits 13:4 of `0x1_1006_0280` (`rtc_ctl`); PROM writes `0x1_0000_0041` so N = 4, period 50 ns, **20,000,000** Hz | `rt:0x61780` `chipset_rtc_period`, reset write A24 in [prom-reset.md](../../../devices/shub/prom-reset.md) |
| `PAL_FREQ_BASE` (13) | **-1, not implemented** (PAL_B 5.73 `0xffea1e40`) | Linux then uses the SAL value |
| `PAL_FREQ_RATIOS` (14), PAL_B 5.73 `0xffea1e60` (table `0xffe9f6e0`, entry for index 14) | needs r29, r30, r31 = 0 (static call) else -2. Reads `msr[1559]`, field bits 26:22 = M. If M is 8 to 24: **r9 = r11 = (M << 32) \| 2** (processor and ITC ratio M/2), **r10 = 0x1_0000_0001** (bus ratio 1:1). Any other M: status -3 | read from the PAL_B code; the msr is not decoded further (what it holds on hardware: **unknown**) |
| ITC frequency | 200 MHz x M / 2 = 100 MHz x M (for example M = 13 is 1.3 GHz) | what Linux computes in `ia64_init_itm`; the runtime does the same in `cpu_itc_frequency` (`rt:0x12a70`: `(r11 >> 32) * 200e6 / (r11 & 0xffff)`) |
| Interval timer vector | `0xef` from the processor's own `cr.itv` | [interrupts.md](../../../devices/shub/interrupts.md) |

- **The PROM writes `ar.itc`: yes, per processor, never to synchronise.** `cpu_set_interval_timer` (`0xffaebe90`, `rt:0x12980`) and `cpu_reset_interval_timer` (`0xffaebef0`, `rt:0x129e0`) each write `ar.itc = 0`, then `cr.itm` and `cr.itv`. Each processor therefore has its own ITC origin. No code in SAL_B or the runtime copies an ITC between processors (the only other `ar.itc` uses are reads). The platform features descriptor has the ITC-drift bit (feature byte 8), so Linux's `smp_callin` skips `ia64_sync_itc` (the `!(sal_platform_features & IA64_SAL_PLATFORM_FEATURE_ITC_DRIFT)` test in `smpboot.c`).
- **Linux uses the SHub RTC, not the ITC, as the clock on SN2.** `sn2/timer.c` registers clocksource `sn2_rtc`, rating 450, 55-bit mask, reading the local MMR `SH_RTC` (`0x1_101c_0000`), with mult from `sn_rtc_cycles_per_second`, which `sn_setup` fills from `SAL_FREQ_BASE` type 2 (fallback 33.3 MHz if the call fails or the value is under 100 kHz). It also sets `ia64_udelay` to an RTC-based loop. `mmtimer` reads the same counter.
- **What must agree.** (1) RTC counter rate = type 2 value = `1e9 / (10 N + 10)` from the `rtc_ctl` the PROM wrote: a model that changes the counter's step must change `rtc_ctl` and the call together. The PROM's own timeouts read the same counter ([the node lock](../../../devices/shub/prom-reset.md#the-node-lock-used-by-a28-a29-a34-and-a37) deadline is in microseconds from `chipset_rtc_time` = counter x period). (2) ITC rate = 100 MHz x M must equal the real rate of `ar.itc`, because `cr.itm` deadlines and `ia64_init_itm`'s tick computation use it; M comes from `msr[1559]` (the PAL), the 200 MHz base from the SAL. (3) Per-CPU ITCs may start at different times: the ITC-drift bit makes that legal; `ar.itc` need only be monotonic per CPU and run at the same rate. (4) The three clocks need no phase relation. (inferred from the Linux code, which treats the RTC as the shared timebase)
- **Unknown.** The meaning of `msr[1559]` bits 26:22 on hardware beyond "the multiplier PAL reports"; whether a real node's `rtc_ctl` still holds `0x1_0000_0041` when Linux asks (inferred yes).

## 4. Machine check, INIT and rendezvous

### What Linux registers (public `mca.c`, `ia64_mca_init`)

1. `SAL_MC_SET_PARAMS(RENDEZ_INT = 1, mechanism interrupt, IA64_MCA_RENDEZ_VECTOR, timeout 20000, RZ_ALWAYS)`. The PROM **rejects any timeout under 49000** with status -2 and r9 = `0xbf68` (49000); Linux loops and retries with 49000 and prints "Increasing MCA rendezvous timeout". (`rt:0x3b30`; `sal_event_register_rendez_ivn` `rt:0x3f7b0`; established)
2. `SAL_MC_SET_PARAMS(RENDEZ_WAKEUP = 2, interrupt, IA64_MCA_WAKEUP_VECTOR)`: mechanism 1 (interrupt) -> `sal_event_register_wake_up_ivn` `rt:0x3ff70`; other mechanism -> `_wake_up_memloc` `rt:0x40210`.
3. `SAL_SET_VECTORS(OS_MCA = 0, handler fp, gp, size 0)` -> stored at `rec + 0, 8, 16`. This also sets this processor's boot state to 2.
4. `SAL_SET_VECTORS(OS_INIT = 1, monarch fp, gp, 0, slave fp, gp, 0)` -> `rec + 24, 32, 40` (monarch) and `rec + 48, 56, 64` (slave).
5. Type 2 (boot rendezvous) -> `rec + 72, 80, 88` (section 2). Other types are ignored.
6. Later: `CPE` interrupt `SAL_MC_SET_PARAMS(3)` -> `sal_event_register_cpe_ivn`; `SAL_GET_STATE_INFO`, `GET_STATE_INFO_SIZE`, `CLEAR_STATE_INFO` on error. Their handlers are in [sn2-runtime.md](../../sal/sn2-runtime.md#standard-sal-calls). `SAL_MC_RENDEZ` (`rt:0x3d10`, row 4 `0xffb12fb0`): `sal_event_rendez_slave` (`rt:0x40770`): if an MCA rendezvous is in progress (`mcrz_in_progress`) it makes a static PAL call, sets the rendezvous flag (`mcrz_set_rz(1)`), sleeps (`mcrz_sleep`), clears the flag and returns 0; otherwise returns 0 at once.

All six stores land in the per-node record `rec = main_ptov([block A + 0x90])`; a registration writes every present node's record, not only the caller's. The record layout (12 words: three triples for MCA, INIT-monarch, INIT-slave, then boot rendezvous) is established from `rt:0x3f360`.

### How a CPU-detected machine check reaches the OS (established as code; PAL side from [images.md](images.md#4-reset-entry-and-pal-requirements))

1. The processor takes a machine check; PAL_A's `PALE_CHECK` runs, then calls SAL_A with reason 1 (INIT is reason 2). SAL_A branches to the SAL_B entry at offset `0x20` (`0xffa01020`) for a machine check, offset `0x10` (`0xffa01010`) for INIT; a `br` at each leads to `0xffa01080` (MCA) or `0xffa01b80` (INIT).
2. **MCA entry `0xffa01080`**: stores the PAL-supplied registers and the whole processor state (branch registers, control registers `cr.dcr..cr.lrr1`, `ar.k0..k7`, `ar.ccv`, `ar.pfs`, `ar.bspstore`, region registers, floating-point registers) into a per-slice save area at physical `0x58000 + (slice << 13)` (slice from `cr.lid` bits 26:23), copies 58 words of the PAL state (pointer in `r8`) to the save area `+8`, sets a per-slice stack `0x18000 + (slice << 16)` for the register stack and `+0xfff0` for `sp`, switches to bank 1, loads `gp = 0xffd98000` and calls the C routine `0xffa02ff0(save_area)` (progress 0x38 "SAL entered due to MCA").
3. `0xffa02ff0` (the SAL check handler): `0xffa03c60`, event logging, `0xffa0a4c0`, `0xffa07230` (error classification: status 2 and 4 are tested), PMI and bus-error handling (`0xffa0b0f0`), and, for a recovered or monarch case, `0xffa02710` (INIT-class sequencing) and the rendezvous routine `0xffa04220` which interrupts the other present processors with the registered rendezvous vector, waits `timeout * 1000` clock units, then sends INIT (type 5) to any processor still not reporting a rendezvous state (bits 19:18 = 2 and bit 9 clear). "SAL_CHECK waiting for OS_MCA lock" (progress 0x56) is the wait if another processor is already past the lock.
4. When the OS is to handle it, `0xffa02e00(r32, r33)` loads `rec`, prints progress 0x39 "SAL calling OS_MCA" (`0xffa0e3f0`), reads the OS_MCA entry `[rec+0]` and gp `[rec+8]` and the words at `rec + 112` and `rec + 120`, and calls `0xffa35e10`, which **restores the saved processor state from the save area and branches to the return address handed in (`b0`) back toward PAL**. The OS is entered by PAL's `PAL_MC_RESUME`/return path using the registered entry (inferred: this routine returns to PAL with the OS_MCA entry in the state it restores; the PAL side of the hand-over is not traced).
5. Progress 0x3a "SAL resuming after MCA" is written at `0xffa17e66`; what resumes it was not read.
6. INIT: entry `0xffa01b80`, progress 0x3b, then the monarch/slave split by `rec + 24` and `rec + 48` entries ("SAL isn't monarch, so drop to POD" 0x3d when none is registered; progress 0x3c "SAL calling OS_INIT" at `0xffa028d6`, `0xffa1c1c0`). Not read past the entry.
7. PMI (progress 0x57) is a separate PAL entry and PMI type 2 interrupt vector 1 to the node's slices; see [interrupts.md](../../../devices/shub/interrupts.md).

### The empty-PCI-slot recovery

The runtime services `SAL_PROBE`/`sal_probe_resume_on_mca` (`rt:0x83c50`), `register_no_fault_zone_virtual` and `_physical` (`rt:0x3f70`, `0x4050`) and the `sal_event_*_mc_region` family (`rt:0x3a6e0`, `0x3a8a0`, `0x3abc0`) are the names of the machinery that lets an MCA during a protected PIO read return to the OS instead of dying. They hang off the path above: the SAL check handler consults the registered no-fault regions before choosing to hand over to OS_MCA or to resume. The decisions inside `0xffa07230` and the region walk were **not** read in this pass (**unknown**), so the exact condition that turns a read of an empty slot into "return to the probe" is open; [the probe call](../../sal/sn2-runtime.md) has the PROM-side result values (r8 = 1 and r9 = -1 when the protected read faulted).

## Unknowns

- Per-slice register behind the boot state (`mcrz_flg`), and what a write of 1 to its field is needed to look like on hardware.
- The hook at `0xffa1f7b0` that can override the boot-processor choice.
- Processor state at `start_ap` entry (PSR, RSE).
- Whether hardware sets `cr.irr0` bit 0 for a vector-0 external interrupt (the PROM's thread park depends on it; irrelevant on a processor without threads).
- The region-walk and classification inside `0xffa07230` and `0xffa03c60`; the PAL half of the machine-check hand-over (`PALE_CHECK` to the SAL return and `PAL_MC_RESUME`).
- `msr[1559]` bits 26:22 on hardware.

## Sources

Shipped PROM image only plus the public Linux files named at the top (`linux-history` mirror; no other URLs were opened). The SGI-held SN2 kernel-tools mirror was not opened.
