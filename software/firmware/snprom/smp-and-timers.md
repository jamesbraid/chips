# SN2 PROM: starting the other processors, the clocks, and machine checks

How the SHub 1 PROM (snprom 10.54, `shub1snprom.bin`: SAL_B 5.04 at `0xffa00000`, PAL_B 5.73 at `0xffe78000`, SAL runtime component read as `rt:0x...`) brings up more than one processor, which clock values it reports, and what happens on a machine check or INIT. What Linux ia64 asks of it at each step is tied to the handler that answers. Linux is the public Linux history tree tree (`arch/ia64/kernel/smpboot.c`, `sal.c`, `mca.c`, `arch/ia64/sn/kernel/{setup.c,sn2/sn2_smp.c,sn2/timer.c}`, `asm/sal.h`); it has the SN2 platform code and is a later tree than v5.3, which matters only where noted.

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
4. Jump to RAM `0xffac6bb0` (progress 0x19, 0x40 to 0x45): **PAL_COPY_INFO (PAL 30) then PAL_COPY_PAL (PAL 256) on each processor, master first, node barrier between**, store the copy as that processor's PAL entry (`0xffa1d690`, per-CPU record `[0x1000000 + 8*(2+n)]` field `+0x88`); PAL_TEST_INFO (37) and PAL_TEST_PROC (258) run the CPU test from `0xffaf5c80` on each processor ([the jump to RAM](boot-sequence.md#pal-boundary)). Family-0x20 CPUs skip the shadow.
5. `main_two` `0xffa1ade0` (progress 0x1a to 0x1e), then `0xffacd2b0` / `main_three` `0xffad7280` (0x21 to 0x27). The cache init the SAL does itself is PAL_CACHE_INIT (3) only in the halt routine `0xffaeb7c0` and the cache-flush SAL call.

### Slave threads: wake and park (established)

- **Count and identity.** `0xffa9ad80` = number of logical processors = PAL_LOGICAL_TO_PHYSICAL (42) with proc_number 0, r9 bits 15:0, or 1 if PAL answers -1 (unimplemented); `0xffa9af90` makes the same call with the entry index in r29. `0xffa9af30` = PAL_FIXED_ADDR (12). `0xffa9b050` finds the logical entry whose PAL r11 low 16 bits equal the fixed address; `0xffa9b110` returns that entry's thread field (PAL r10 bits 15:0; "thread id" by the string `logical thread id: %x`, inferred). With PAL_LOGICAL_TO_PHYSICAL unimplemented every processor is thread 0.
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
| 2 | `sal.c` | platform features descriptor: `sal_platform_features` | `0x90` row | feature mask byte (type byte 2, then the mask) = 8, bit 3 = ITC drift, no other bit |
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

- **The PROM writes `ar.itc`: yes, per processor, never to synchronise.** `cpu_set_interval_timer` (`0xffaebe90`, `rt:0x12980`) writes `ar.itc = 0`, then `cr.itm` (first argument) and `cr.itv` (second argument, low 8 bits); `cpu_reset_interval_timer` (`0xffaebef0`, `rt:0x129e0`) writes only `ar.itc = 0`. Each processor therefore has its own ITC origin. No code in SAL_B or the runtime copies an ITC between processors (the only other `ar.itc` uses are reads). The platform features descriptor has the ITC-drift bit (feature mask 0x08, bit 3), so Linux's `smp_callin` skips `ia64_sync_itc` (the `!(sal_platform_features & IA64_SAL_PLATFORM_FEATURE_ITC_DRIFT)` test in `smpboot.c`).
- **Linux uses the SHub RTC, not the ITC, as the clock on SN2.** `sn2/timer.c` registers clocksource `sn2_rtc`, rating 450, 55-bit mask, reading the local MMR `SH_RTC` (`0x1_101c_0000`), with mult from `sn_rtc_cycles_per_second`, which `sn_setup` fills from `SAL_FREQ_BASE` type 2 (fallback 33.3 MHz if the call fails or the value is under 100 kHz). It also sets `ia64_udelay` to an RTC-based loop. `mmtimer` reads the same counter.
- **What must agree.** (1) RTC counter rate = type 2 value = `1e9 / (10 N + 10)` from the `rtc_ctl` the PROM wrote: a model that changes the counter's step must change `rtc_ctl` and the call together. The PROM's own timeouts read the same counter ([the node lock](../../../devices/shub/prom-reset.md#the-node-lock-used-by-a28-a29-a34-and-a37) deadline is in microseconds from `chipset_rtc_time` = counter x period). (2) ITC rate = 100 MHz x M must equal the real rate of `ar.itc`, because `cr.itm` deadlines and `ia64_init_itm`'s tick computation use it; M comes from `msr[1559]` (the PAL), the 200 MHz base from the SAL. (3) Per-CPU ITCs may start at different times: the ITC-drift bit makes that legal; `ar.itc` need only be monotonic per CPU and run at the same rate. (4) The three clocks need no phase relation. (inferred from the Linux code, which treats the RTC as the shared timebase)
- **Unknown.** The meaning of `msr[1559]` bits 26:22 on hardware beyond "the multiplier PAL reports"; whether a real node's `rtc_ctl` still holds `0x1_0000_0041` when Linux asks (inferred yes).

## 4. Machine check, INIT and rendezvous

### What Linux registers (public `mca.c`, `ia64_mca_init`)

1. `SAL_MC_SET_PARAMS(RENDEZ_INT = 1, mechanism interrupt, IA64_MCA_RENDEZ_VECTOR, timeout 20000, RZ_ALWAYS)`. A timeout under 49000 returns status -2, but the registration is **still made** with the timeout clamped to 49000 (vector at `rec+0x80`, timeout at `+0x88`, flags at `+0x90`); r9 is 49000 on every return path. Linux loops and retries with 49000 and prints "Increasing MCA rendezvous timeout". (`rt:0x3b30`; `sal_event_register_rendez_ivn` `rt:0x3f7b0`; established)
2. `SAL_MC_SET_PARAMS(RENDEZ_WAKEUP = 2, interrupt, IA64_MCA_WAKEUP_VECTOR)`: mechanism 1 (interrupt) -> `sal_event_register_wake_up_ivn` `rt:0x3ff70`; other mechanism -> `_wake_up_memloc` `rt:0x40210`.
3. `SAL_SET_VECTORS(OS_MCA = 0, handler fp, gp, size 0)` -> stored at `rec + 0, 8, 16`. This also sets this processor's boot state to 2.
4. `SAL_SET_VECTORS(OS_INIT = 1, monarch fp, gp, 0, slave fp, gp, 0)` -> `rec + 24, 32, 40` (monarch) and `rec + 48, 56, 64` (slave).
5. Type 2 (boot rendezvous) -> `rec + 72, 80, 88` (section 2). Other types are ignored.
6. Later: `CPE` interrupt `SAL_MC_SET_PARAMS(3)` -> `sal_event_register_cpe_ivn`; `SAL_GET_STATE_INFO`, `GET_STATE_INFO_SIZE`, `CLEAR_STATE_INFO` on error. Their handlers are in [sn2-runtime.md](../../sal/sn2-runtime.md#standard-sal-calls). `SAL_MC_RENDEZ` (`rt:0x3d10`, row 4 `0xffb12fb0`): `sal_event_rendez_slave` (`rt:0x40770`): if an MCA rendezvous is in progress (`mcrz_in_progress`) it makes a static PAL call, sets the rendezvous flag (`mcrz_set_rz(1)`), sleeps (`mcrz_sleep`), clears the flag and returns 0; otherwise returns 0 at once.

All six stores land in the per-node record `rec = main_ptov([block A + 0x90])`; a registration writes every present node's record, not only the caller's. The record holds, from `rt:0x3f360` and `rt:0x3f7b0`: three triples for MCA (`+0`), INIT-monarch (`+24`), INIT-slave (`+48`), the boot rendezvous triple (`+72`), the rendezvous vector, timeout and flags (`+0x80`, `+0x88`, `+0x90`), and the two words at `+112` and `+120` that the OS_MCA hand-over passes in r9 and r8 (writer not traced).

### How a CPU-detected machine check reaches the OS (established as code; PAL side from [images.md](images.md#4-reset-entry-and-pal-requirements))

1. The processor takes a machine check; PAL_A's `PALE_CHECK` runs, then calls SAL_A with reason 1 (INIT is reason 2). SAL_A branches to the SAL_B entry at offset `0x20` (`0xffa01020`) for a machine check, offset `0x10` (`0xffa01010`) for INIT; a `br` at each leads to `0xffa01080` (MCA) or `0xffa01b80` (INIT).
2. **MCA entry `0xffa01080`**: stores the PAL-supplied registers and the whole processor state (branch registers, control registers `cr.dcr..cr.lrr1`, `ar.k0..k7`, `ar.ccv`, `ar.pfs`, `ar.bspstore`, region registers, floating-point registers) into a per-slice save area at physical `0x58000 + (slice << 13)` (slice from `cr.lid` bits 26:23), copies 58 words of the PAL state (pointer in `r8`) to the save area `+8`, sets a per-slice stack `0x18000 + (slice << 16)` for the register stack and `+0xfff0` for `sp`, switches to bank 1, loads `gp = 0xffd98000` and calls the C routine `0xffa02ff0(save_area)` (progress 0x38 "SAL entered due to MCA").
3. `0xffa02ff0` (the SAL check handler): `0xffa03c60`, event logging, `0xffa0a4c0`, `0xffa07230` (error classification: status 2 and 4 are tested), PMI and bus-error handling (`0xffa0b0f0`), and then, if an OS_MCA entry is registered (`rec+0` nonzero) and the lock test passes (`0xffa03e50`, `0xffa03e00`): when the rendezvous flag (`rec+0x90` bit 0) and vector are set, `0xffa05280(vector)` is asked, and if bit 10 of the high half of its result is set the rendezvous routine `0xffa04220` runs; otherwise, with `rec+0x90` bit 3 set, `0xffa09f60` and `0xffa02710` (INIT-class sequencing) run. `0xffa04220` sends the registered vector (type 0) to every other present processor, sets its output word to 1, computes a deadline of now + `timeout * 1000` clock units (`0xffa0da70`), collects each processor's state word (`0xffa040e0`; the wait is presumably there, not read), then sends INIT (type 5) to each other processor whose state word has bits 19:18 = 2 and bit 9 clear and sets the output word to 2. What those state bits mean is not decoded; "still not reporting" in the earlier text was a guess. Then `0xffa02e00` runs (item 4). "SAL_CHECK waiting for OS_MCA lock" (progress 0x56) is the wait if another processor is already past the lock.
4. **Hand-over to the OS.** `0xffa02e00(rendezvous word, save area)` loads `rec`, prints progress 0x39 "SAL calling OS_MCA" (`0xffa0e3f0`) and calls `0xffa35e10` with `[rec+120]`, `[rec+112]`, the save area, the rendezvous word, the OS entry `[rec+0]`, the OS gp `[rec+8]` and a SAL global. `0xffa35e10` restores region registers 0 to 7 from the save area, `b2` to `b7`, `ar.k0` to `ar.k7`, `ar.ccv`, `ar.fpsr`, `ar.pfs`, `ar.lc`, `ar.ec` and the register stack, executes `bsw.0` and then **branches to the OS entry** (`br b0` with `b0 = [rec+0]`). It does not return to PAL. Registers at that branch: `r1` = `[rec+8]` (OS gp), `r8` = `[rec+120]`, `r9` = `[rec+112]`, `r10` = the SAL gp, `r11` = the rendezvous word (0, 1 or 2 as `0xffa04220` leaves it), `r12` = a SAL global value. These are the registers Linux's `ia64_os_mca_dispatch` documents as inputs (r8 pal_proc entry, r9 sal_proc entry, r10 SAL gp, r11 rendezvous state, r12 SAL return address), so `[rec+120]`, `[rec+112]` and the r12 value are **inferred** to be PAL_PROC, SAL_PROC and the SAL_CHECK return address; their writers were not traced. If the OS entry ever returned the path runs on to progress 0x3d and the POD/halt handling of `0xffa02ff0`.
5. Progress 0x3a "SAL resuming after MCA" is written at `0xffa17e66`; what resumes it was not read.
6. INIT: entry `0xffa01b80`, progress 0x3b, then the monarch/slave split by `rec + 24` and `rec + 48` entries ("SAL isn't monarch, so drop to POD" 0x3d when none is registered; progress 0x3c "SAL calling OS_INIT" at `0xffa028d6`, `0xffa1c1c0`). Not read past the entry.
7. PMI (progress 0x57) is a separate PAL entry and PMI type 2 interrupt vector 1 to the node's slices; see [interrupts.md](../../../devices/shub/interrupts.md).

### The empty-PCI-slot recovery

Read in `shub1snprom.bin` 10.54 (SAL 5.04) from the flat-image listing and Ghidra with the SAL runtime mapped (`rt:` addresses are runtime-ELF offsets). The PAL half is in [pal-b-halts.md](pal-b-halts.md#pale_check-and-the-machine-check-hand-off). What this section settles is the SAL decision; what the processor latches for an empty-slot read stays open.

**Verdict.** The PROM does not halt on this machine check by design. If PAL hands SAL a processor state with us = 0 and cm = 0 and the interrupted instruction pointer lies inside the range `SAL_PROBE` registered, SAL rewrites the saved instruction pointer and calls `PAL_MC_RESUME` (index 26) with new_context 0. The probe then returns to its caller with an error status. Whether the real or modelled PAL builds that state for an empty-slot bus error is **unknown** (below).

**The probe side (established).** `sal_event_probe` (`rt:0x79cc0`, SAL call `0x02000003`; size must be 1, 2, 4 or 8, else it returns 2 at once) does, in order: add a no-fault region `[sal_probe, sal_probe_end]` = `rt:0x83be0` to `rt:0x83c40` with resume address `rt:0x83c50` (`sal_probe_resume_on_mca`) to the node's region table; store the probed address at `[block + slice*8 + 0x5308]` (no reader found by immediate search); `mcrz_set_probe(1)`; call `sal_probe`; `mcrz_set_probe(0)`; remove the region. `sal_probe` is one load of the size asked, a dependent `add` and `srlz.i` (so a late machine check lands inside the range), then `r8 = 0`, `r9` = data. The resume stub sets `r8 = 1`, `r9 = 0` and returns through the same epilogue. The wrapper maps this to the SAL status ([sn2-runtime.md](../../sal/sn2-runtime.md)). The region entry's flags bit 16 is the caller's `psr.dt`.

**The region table (established).** Per node block `B` (`0xffa1c2e0` of the pointer at `[0x1000038] + 0x90`): lock at `B+0xb0`; up to 32 entries from `B+0xb8`, 32 bytes each: flags (bit 16 = data translation), start, end, resume address; an entry with start 0 ends the table. `0xffa05610` walks it with the saved `XIP` (record `+0x1b8`) and `IIP` (`+0x1a0`): a match is `start <= ip <= end` (end inclusive). A match replaces that slot with the resume address, clears the status slot's bits 42:41 (`psr.ri`) and sets bit 17 (`psr.dt`) from the flags. The result is per slice (`B+0x4d8+slice`, slice = `cr.lid` bits 26:23); if this slice did not match, the other slices' flags are read, and if any matched, every slice's flag is set (`0xffa10920` iterator, 100000-tick lock timeout). A lock timeout skips the sharing.

**The decision (`0xffa07230(type, PSP, record)`, established).** For type 0 (machine check):
1. If saved `IPSR` bit 13 (`psr.ic`) is clear and `0xffa31aa0` finds bit 3 of `0x1_2001_0100` set, and the node word at `B+0x53c8` is zero (it is set only by a SAL error-handling-features call; Linux is not seen to make it), SAL sets PSP us (bit 9) and clears sy, co, ci (bits 6 to 8) and cm (bit 18): uncontained.
2. PSP us set: not recovered. PSP cm set: not recovered here. Otherwise `0xffa05610` must return non-zero: result 4. A zero result takes the per-type record byte at `+10` of `0xffa07e90(type)` (its writer was not traced; **unknown**).
3. Before returning, `PAL_MC_CLEAR_LOG` (21) is called at `0xffa0742c`, and `0xffa3e640` copies the error record out. For type 0 or 1 `0xffa06370` takes the first valid-bit-3 section of the `PAL_MC_ERROR_INFO` record and stores its word at `+0x20` (the bus transaction's target in Linux's `sal_log_mod_error_info_t`; inferred) at `[B + slice*8 + 0x5328]`. It does not affect recovery.
Result 4 (or 2) then runs `0xffa02f40`, which calls `PAL_MC_RESUME` (`0xffa37ff6`, `r28 = 0x1a`, `r29` = new_context, `r30` = min-state pointer, `r31` = 0) and does not return on success (software expectation from the SDM; the code after it only runs on failure). That failure path goes on to `0xffa217c0`, the platform error handler, which reads the SHub and bus error state (PI `0x1_2006_0100/0180/0200`, `0x1_2005_0300`, and each chip's error method); on a recovered probe none of that runs, so the PIC error status is left for Linux's own error interrupt. The OS_MCA entry is not called on the recovered path.

**Linux caller (software expectation).** `SN_SAL_PROBE` is defined in the Library's Linux `sn_sal.h` trees but no caller was found in them by text search; the earlier page cites a 2.6.12 PCI-DMA fallback as the user. Whether the Linux used for S4 issues it at all is **unknown**: log the SAL call id.

### What to log in an S4 run (machine check on an empty slot)

Every value is read, not asserted. "Expected" is what the recovered path needs; a value outside it names the branch the PAL or SAL takes instead.

| Where | What | Expected for recovery | Grade |
|---|---|---|---|
| SAL entry | procedure id `0x02000003`, address, size | size 1/2/4/8 | established |
| `sal_event_probe` | region table at `B+0xb8..` (start, end, resume, flags) | start `rt:0x83be0`, end `rt:0x83c40`, resume `rt:0x83c50` | established |
| PALE_CHECK `0xffffff90` | `msr[1640]` | bit 56 = 1; bit 57 = 0; bit 4 = 0; bit 53 = 0; bits 49:9 = min-state pointer, non-zero | established (tests), inferred (meaning of the bits) |
| same | `msr[1643]`, `msr[0]`, `msr[1641]`, `msr[1642]` | PAL scratch for `r29`, `r30`, `r31`, predicates | established (stores), inferred (role) |
| same | `msr[1715]` bits 15:8, `cpuid[3]` bits 31:24 and 23:16 | each compared with a byte of the PAL_B image header (not with each other); a header revision below `msr[1715]` bits 15:8, or a family or model that differs, skips that image | established |
| PAL_B `0xffeca570` | `cr.ipsr` bit 13; `msr[1283]` bit 63 | ipsr.ic = 1 for `sal_probe` (virtual SAL call), taking `0xffed3920` | established (branch), inferred (that sal_probe runs with ic = 1) |
| same | `msr[1237]` bits 2, 3, 4, 7; `msr[1152]` bit 18; `msr[1572]` bit 18; `msr[1728]`, `msr[1730]` | meaning unknown; log them | established (reads), unknown (meaning) |
| classifier `0xffec9b50` | `msr[1505]` to `msr[1512]` | `(w & 0xc00001) == 0x400001` (1505 to 1508) or `(w & 0x30001) == 0x10001` (1509 to 1512) requests a rendezvous | established (tests), unknown (meaning) |
| decoders `0xffe99bc0` | `msr[1558]` bit 13 (valid), bits 20:16 (cause), 25:21 (structure), bit 30 (expected), bit 41, bit 5 | all unknown; the cause code decides cm and us | established (reads), unknown (values) |
| same | `msr[1417]`, `msr[1087]`, `msr[1039]`, `msr[1537]` bit 0, `msr[1282]`, `msr[1279]` bit 23, `msr[1779]`, `msr[1168]` | bus bits of `msr[1417]` (51 to 54 and the masks `0x7ff00000`, `0xff00000000`, `0x3de00000`, `0x2100000`, `0x40100`, `0x3c0f0`, `0x80200`, `0x7f00000000`) feed bc, me and the cm/us counters | established (reads), unknown (values) |
| PAL to SAL | `r20` = 1, `r16`, `r17`, PSP `r18`, `r19` | PSP us (9) = 0, cm (18) = 0, bc (61) = 1, mn (5) = 1, mi (12) as the model decides | established (layout), inferred (bc/mi for this fault) |
| SAL record | `+0x568..+0x588` (`r16`..`r19`/PSP at `+0x578`), `+0x1a0` IIP, `+0x1a8` IPSR, `+0x1b8` XIP, `+0x1c0` XPSR; IIP inside `[rt:0x83be0, rt:0x83c40]` | IIP before and after rewrite to `rt:0x83c50` | established |
| SAL | return of `0xffa07230` (4 = resume, 2 = resume new context), `B+0x4d8+slice`, `B+0x53c8` (0), `B+0x5308+slice*8` (probe address), `B+0x5328+slice*8` | 4; flag 1; 0 | established |
| SAL to PAL | `PAL_MC_ERROR_INFO` (25) summary in `r9`, then per-structure calls; `PAL_MC_CLEAR_LOG` (21); `PAL_MC_RESUME` (26) with `r29` = 0, `r30` bit 63 set, `r31` = 0 | status 0 from the first two; resume never returns | established |
| PAL resume `0xffea84c0` | `msr[1664]` bit 0, `msr[1640]` bit 6 to `msr[1416]` bit 16 (poll bit 40), `msr[1776]`, `msr[1464]`, `msr[1283]` | restored from the min-state area | established |
| SHub, handler | per-slice scratch word `0x1_5003_15e0` (slice 0) or `0x1_5003_1590` (slice 2), bit 44, read and written by `0xffa03c60` (slices 1 and 3 have a zero table entry; form unknown); RTC counter `0x1_101c_0000` and period `0x1_1006_0280` (timestamps, `0xffa0a4c0`) | plain storage; counter advancing | established |
| SHub, conditional | `0x1_2001_0100` bit 3 (read only if ipsr.ic = 0) | 0 | established |
| SHub, not expected | PI error state, `0x1_101d_0080` (scratch1 bit 41), the rendezvous IPI `0x1_1000_0380` | only on the failure path (`0xffa217c0`, handler tail) or rendezvous | established (code shape) |

Reading the log: `msr[1640]` bit 56 clear ends in PAL's common error exit (r30 = 2); bit 57 set is a check inside PAL; bit 53 set forces uncontained; a zero pointer in bits 49:9 ends with r13 = 10; PSP us = 1 or cm = 1 or an IIP outside the range means SAL does not resume and hands the check to the OS_MCA entry or its fatal path.

## 5. Processor ids (cr.lid) and IPI pids

How `cr.lid`, the 16-bit processor id (the PROM calls it the pid, Linux the SAPIC id or physical id), the SAL tables and the `SH_IPI_INT` message fit together. PROM facts are from `shub1snprom.bin` 10.54 (Ghidra and objdump); Linux is Linux history tree plus the `linux-sn2` tree (`arch/ia64/include/asm/sn/sn_cpuid.h`, `sn_sal.h`, `shub_mmr.h`, `arch/ia64/sn/kernel/{setup.c,sn2/sn2_smp.c}`, `arch/ia64/kernel/acpi.c`).

### Layout (established from the PROM code)

SDM rev 2.3 vol 2 part 1 section 5.8.3.1 (p. 2:122, Figure 5-6, Table 5-10) puts `id` in `cr.lid` bits 31:24 and `eid` in 23:16, "initialized by platform firmware", and says the two fields correspond to bits 19:4 of the interrupt message. SN2 gives those sixteen bits a meaning of its own, and the byte split is only where the architecture's boundary happens to fall:

| `cr.lid` bits | pid bits | Meaning | Where it shows |
|---|---|---|---|
| 22:16 | 6:0 | NASID bits 6:0 | SAL_B `0xffaec240`; `chipset_get_nasid` extr 0..6 |
| 26:23 | 10:7 | slice (4-bit field; only bits 24:23 are ever set) | `extr.u cr.lid,23,4` at every use (progress history `0x81_5003_1500 + 16 * slice`, per-CPU record `[0x1000000 + 8*(2 + slice)]`, save area `0x58000 + (slice << 13)`) |
| 31:27 | 15:11 | NASID bits 11:7 | same routine |
| 15:0 | | zero | |

In SDM terms `eid` = NASID[6:0] | slice[0] << 7 and `id` = slice[3:1] | NASID[11:7] << 3. The pages that say "slice is `cr.lid` bits 26:23" and the SDM id/eid split therefore agree; the NASID is not in bits 26:23. `cr.lid = (((nasid >> 7) & 0x1f) << 11 | slice << 7 | (nasid & 0x7f)) << 16`.

### Values for NASID 0

| slice | `cr.lid` | pid | SDM (id, eid) |
|---|---|---|---|
| 0 | `0x0000_0000` | `0x0000` | (`0x00`, `0x00`) |
| 1 | `0x0080_0000` | `0x0080` | (`0x00`, `0x80`) |
| 2 | `0x0100_0000` | `0x0100` | (`0x01`, `0x00`) |
| 3 | `0x0180_0000` | `0x0180` | (`0x01`, `0x80`) |

In general pid = `cr.lid >> 16`. NASID 2, slice 2 is pid `0x0102`.

**Which slices this PROM produces (established arithmetic, inferred consequence).** SAL_A takes the slice from `r33 & 3`, where `r33` is PALE_RESET's processor-id word. Every PAL_A in the image (7.31 `0xfffc4dd0`, 5.37 `0xfffcb9d0`, 1.27 `0xfffd2180`) builds it as `msr[1559]` bits 21:19 shifted left by one, so bit 0 is always 0 and the slice is 0 or 2 (one processor per front-side bus, matching SAL_B reading the agent-status register only for slices 0 and 2). `msr[1559]` bit 21 set makes `r33` bit 3 set; SAL_A then spins, but only on reason 3 (the recovery-check entry, `0xffc4ed16` to `0xffc4ed3c`). On reason 0, which writes `cr.lid`, only `r33 & 3` is used. PAL_FIXED_ADDR (PAL_B 5.73 `0xffea1df0`) returns the same value. The PROM never makes slice 1 or 3 on SHub 1; the format and the four-slice code in SAL_B reserve them. A two-processor Altix 350 on NASID 0 is `cr.lid` `0x0000_0000` and `0x0100_0000`. What `msr[1559]` bits 21:19 hold on hardware (presumably the bus agent position): **unknown**.

### What writes `cr.lid` (established)

1. Nothing before SAL_A reads or writes it except PAL's own self-test (PAL_B sub-test 4 writes patterns and restores, [pal-b-halts.md](pal-b-halts.md#3-what-the-groups-test-and-what-a-healthy-processor-returns)). The reset value is **unknown**; the SDM says firmware loads it (p. 2:122).
2. **SAL_A, reason 0 only** (`0xffc4edc0`, call at `0xffc4e386`): `cr.lid = (r33 & 3) << 23`, then `srlz.d`. NASID bits are zero. PALE_RESET's mask fields (SDM 11.2.2, p. 2:289, and Figure 11-8, p. 2:293: `id_mask` and `eid_mask`, `r33` bits 47:32) are zero in this PAL, so every bit of 31:16 is programmable.
3. **SAL_B node-id install** (`0xffaec240`, from `0xffad7aa0`, every CPU): keeps the slice from the current `cr.lid`, merges the NASID as above, writes, `srlz.d`, reads back; a mismatch writes progress `0xc3` and halts. On a lone node the NASID is 0 and the value does not change.

A model needs `cr.lid` bits 31:16 read/write with exact readback (the halt in step 3 and the PAL self-test both depend on it), and an interrupt-delivery path keyed on the same 16 bits.

### What SAL tells Linux (established)

- The CPU table the SAL system tables are built from holds `{u16 pid, u16 flags}` per present slice ([os-handoff-tables.md](os-handoff-tables.md)). The MADT local-SAPIC entry carries SAPIC id = `pid >> 8` and EID = `pid & 0xff`, so Linux's `cpu_physical_id` = `(id << 8) | eid` = pid (`acpi.c`), and `get_sapicid()` = `(cr.lid >> 16) & 0xffff` (`sn_cpuid.h`) is the same number.
- `SN_SAL_GET_SAPIC_INFO(pid)` (`rt:0x85f0`): nasid = `(pid & 0x7f) | ((pid >> 11) << 7)`, subnode 0, slice = `(pid >> 7) & 0xf`. `sn_cpu_init` stores them in `phys_cpuid[]`, so `get_nasid()` and `get_slice()` come from this call. Linux's own fallback (`nasid = pid & 0xfff`, slice from bits 13:12) runs only if SAL says "not implemented", which this PROM does not, so it never applies here.

### The IPI pid (established for the sender, inferred for the hardware)

`SH_IPI_INT` is `0x1_1000_0380` of the target node. The message Linux sends (`sn_send_IPI_phys`, `shub_mmr.h`: type shift 0, agent 3, pid 4, base 21, vector 52, send 63) is

`1 << 63 | vector << 52 | 0xfee << 21 | pid << 4 | type`

with pid = the target's `cr.lid >> 16` as above. The NASID is not in the message: the store goes to `0x8_0000_0000 + (nasid << 38) + 0x1_1000_0380`, and `nasid` is rebuilt from the pid (`pid[6:0]`, then `pid[15:11]` shifted to `[11:7]`), by the PROM and (through `GET_SAPIC_INFO`) by Linux. The PROM's own messages use the same pid with base 0. Examples for NASID 0, PROM style (base 0): IPI vector `0x12` to slice 2 is `0x8120_0000_0000_0000 | 0x0100 << 4` = `0x8120_0000_0000_1000`; the PMI message to slice 2 is `0x8010_0000_0000_1002`. Linux's version of the first adds `0xfee << 21`: `0x8120_0001_fdc0_1000`. The PROM's self-sent "bus error" message (`0xffa31a50`) also sets the agent bit (bit 3), which Linux never does; see [interrupts.md](../../../devices/shub/interrupts.md).

The SHub's own rule for choosing the slice from the pid, and whether it compares pid bits 15:11 and 6:0 at all after the address has chosen the node, is not in any read code: **unknown**. The inference that it uses pid bits 10:7 rests on the PROM's per-slice comparator and `SH_LOCAL_INT*_CONFIG` values, which carry the slice in the same bits ([interrupts.md](../../../devices/shub/interrupts.md#processor-id-and-message-layout-the-prom-uses)).

## Unknowns

- Per-slice register behind the boot state (`mcrz_flg`), and what a write of 1 to its field is needed to look like on hardware.
- The hook at `0xffa1f7b0` that can override the boot-processor choice.
- Processor state at `start_ap` entry (PSR, RSE).
- Whether hardware sets `cr.irr0` bit 0 for a vector-0 external interrupt (the PROM's thread park depends on it; irrelevant on a processor without threads).
- The `0xffa07e90` per-type record byte used when the region match fails. The PAL half of the machine-check hand-over (`PALE_CHECK` to `PAL_MC_RESUME`) is read in [pal-b-halts.md](pal-b-halts.md#pale_check-and-the-machine-check-hand-off); what an empty-slot bus error latches for PAL to call it contained is still open there.
- What the SHub does with the pid to pick a slice, and what `msr[1559]` bits 21:19 hold on hardware ([Processor ids](#5-processor-ids-crlid-and-ipi-pids)).
- `msr[1559]` bits 26:22 on hardware.

## Sources

Shipped PROM image only plus the public Linux files named at the top (Linux history tree mirror; no other URLs were opened). The SGI-held SN2 kernel-tools mirror was not opened.

## Review

Independent re-read on 2026-11-16 of commit `9265099`. PROM side: Ghidra (`--sn2-prom --sal-runtime`, full analysis) on `shub1snprom.bin` 10.54, with the inflated runtime ELF and a flat `ia64-linux-gnu-objdump` of the image as a cross-check. Ghidra's decompile is empty or a thunk for `0xffaebe90`, `0xffaebef0` and the PAL_B body at `0xffea1e60` (it does not model `ar.itc` writes or `msr` reads there), so those three were read from objdump only. Linux side: Linux history tree through our holdings, and the `linux-sn2` tree (7.3-rc3). The quarantined SGI kernel-tools mirror was not opened.

**Confirmed.**

- Thread wake `0xffa10f40`: PAL 42, the write of 1 to `0x1_1000_0400` (`0x8000000910000400 | nasid << 38`), then per logical entry with the same core field and a nonzero thread field a store to `0x1_1000_0380` of `0x8000000000000000 | pid << 4` (type 0, vector 0). Park loop `0xffa9ac80`: returns at once for thread 0, else PAL_HALT_LIGHT (29) until `cr.irr0` bit 0. `0xffa11330` is true for thread 0. A PAL that answers -1 gives count 1 and thread 0 for everything, so nothing is sent.
- Boot-processor choice `0xffae77a0`: lowest present entry in the block A `+0x18` table (halfword pid, flags bit 0), ordered by `(pid >> 11, pid & 0x7f)` and then `(pid >> 7) & 0xf` (the slice); true when it is the caller. The IPI sender builds the same NASID from the pid fields, so "NASID then slice" is a fair reading (inferred).
- Slave loop: `0xffafd310` (fresh stack, `0xfffe`), `0xffafcdd0` (mailbox signature `0x43505543616c6c53` at `+0xd8` of the per-CPU record, boot state 1 via `0xffa03eb0`, progress 0x46, busy-poll of vectors 0x12 and 0x13); vector 0x12 clears the word at `+16`, sets state 2, progress 0x47 and calls `[rec+72]` with gp `[rec+80]` through `0xffb55c60`, which re-enters the loop if the entry returns; vector 0x13 calls `0xffb035e0` with five mailbox fields and stores the result at `+56`. The boot state is bits 51:50 of a per-slice register.
- `SAL_SET_VECTORS` slots: type 0 at `+0/8/16` (and caller state 2), type 1 at `+24..+64`, type 2 at `+72/80/88`, written for every present NASID in the table; `SET_CPU_NUMBER` stores `2n` at `+0x110`, and for n = 0 only runs `sal_event_boot_master`, which sets state 3 and clears present bit 26+slice for each other present processor whose state is not 1.
- PAL_FREQ_RATIOS: `msr[1559]` bits 26:22 = M, M from 8 to 24 gives r9 = r11 = `(M << 32) | 2` and r10 = `0x1_0000_0001`; other M gives -3; r29..r31 nonzero gives -2. PAL_FREQ_BASE gives -1 with r9..r11 = 0. SAL_FREQ_BASE: type 0 = 200,000,000 (simulator signature branch aside), type 1 = status 0 with r9 = -1, type 2 = `1e9 / ((rtc_ctl[13:4]) * 10 + 10)`. Other types give -2. Linux asks types 0 and 2 as the page says, and its fallback for a bad RTC value is 33.3 MHz.
- `ar.itc = 0` at `0xffaebea0` and `0xffaebf00`. The ITC-drift bit is bit 3 of the platform-features mask (value 8), and both Linux history tree and 7.3-rc3 `smp_callin` skip `ia64_sync_itc` when it is set. `init_smp_config`, `ia64_mca_init`, `sn_cpu_init` and `sn_send_IPI_phys` match the table in section 2, including the `0x12` AP wake vector in the type 5 SAL descriptor.
- MCA entry: SAL_A offset 0x20 branches to `0xffa01080`; save area `0x58000 + (slice << 13)`, 58 PAL words copied to `+8`, stack `0x18000 + (slice << 16)` with sp `+0xfff0`, `bsw.1`, `gp = 0xffd98000`, call `0xffa02ff0`; progress 0x39 in `0xffa02e00`. The 49000 minimum is as described, with the correction below.

**Changed (fixed above).**

- **The OS_MCA hand-over is a direct branch to the OS entry, not a return to PAL.** `0xffa35e10` restores state and does `br b0` with `b0 = [rec+0]`. Registers at the branch are listed in section 4 item 4; r8, r9 and r12 are graded inferred.
- **A rendezvous timeout under 49000 is registered, clamped to 49000, as well as returning -2**, and r9 is 49000 on every return. The record also holds the rendezvous vector, timeout and flags at `+0x80`, `+0x88`, `+0x90`; the earlier "12 words" count was too small.
- **PAL_LOGICAL_TO_PHYSICAL is called with proc_number 0 (count) or the entry index**, not -1.
- `cpu_reset_interval_timer` writes only `ar.itc`; `cr.itm` and `cr.itv` belong to `cpu_set_interval_timer`.
- The `0xffa02ff0` path: the rendezvous and OS hand-over are conditioned as now written; INIT is sent to processors whose state word has bits 19:18 = 2 and bit 9 clear, and what those bits mean is unknown (the earlier "not reporting" was a guess). The deadline is computed in `0xffa04220`; where it is waited on was not read.
- The "byte 8" wording for the feature descriptor now says mask byte 0x08.

**Not checked.** The A24 write of `rtc_ctl = 0x1_0000_0041` (cited from the reset page), the Linux-side `ia64_mca_init` ordering beyond the calls named, the writers of `rec+112/120`, the `0xffa1f7b0` hook, `msr[1559]` on hardware, and the INIT path past its entry.

### Review of section 5 (processor ids)

Independent re-read of `66008b4` against `shub1snprom.bin` 10.54: flat objdump listing plus Ghidra (`--sn2-prom --no-analysis`), SDM rev 2.3 vol 2 sections 5.8.3.1 and 11.2.2.2, the `linux-sn2` tree (`sn_cpuid.h`, `addrs.h`, `shub_mmr.h`, `sn_sal.h`, `setup.c`, `sn2_smp.c`).

**Confirmed.**
- The `cr.lid` layout: SAL_B `0xffaec240` computes pid = `(nasid & 0x7f) | slice << 7 | (nasid >> 7 & 0x1f) << 11`, writes `pid << 16`, `srlz.d`, reads back and on mismatch writes progress `0xc3` (195). SAL_A `0xffc4edc0` writes `(r32 & 15) << 23` with `r32 = r33 & 3` from `0xffc4ea70`. SDM p. 2:122 (id 31:24, eid 23:16, bits 19:4 of the message) and the id/eid translation in the page. The NASID 0 table and `pid = 0x0102` for NASID 2 slice 2.
- Slices 0 and 2 only: PAL_A 7.31 `0xfffc4dd0`, 5.37 `0xfffcb9d0` and 1.27 `0xfffd2180` all do `extr.u r33=r33,19,3` then `shl r33=r33,1` on msr[1559]; PAL_FIXED_ADDR `0xffea1df0` returns the same value. These three are the only `mov r33=msr[r2]` sites with that shape.
- Reason 0 is the only SAL_A path to the `cr.lid` writer (`0xffc4e386`); the SDM mask fields (`r33` bits 47:32, 0 = programmable) are zero here.
- `GET_SAPIC_INFO` at `0xffb196c0`: nasid `(id & 0x7f) | (id >> 11) << 7`, slice `(id >> 7) & 15`. Linux: `get_sapicid()` is `(cr.lid >> 16) & 0xffff`; `cpu_physical_id` is `id << 8 | eid`; the fallback decode runs only on "not implemented"; the `SH_IPI_INT` field shifts and `0xfee << 21`; the target address `GLOBAL_MMR_PHYS_ADDR(nasid, SH1_IPI_INT = 0x110000380)`.

**Changed (fixed above).** The SAL_A spin on `r33` bit 3 is reason 3 only. The IPI examples were PROM style (base 0) without saying so; Linux's value is given.

**Not checked.** The PROM-side rebuild of the NASID in the thread-wake sender beyond the existing page text, the SHub's own pid decode (unknown, as stated), and the `msr[1559]` bit meanings on hardware.

## 6. Multi-CPU entry and the per-slice table

Why a second processor (slice 2, `cr.lid` `0x0100_0000`) faults in the SAL_B reset path of SAL 5.04 when it shares the early RAM at `0x1000000` with slice 0. Read from a flat `ia64-linux-gnu-objdump` listing of `shub1snprom.bin` (PAL_B 5.73 for procedure 520); Itanium SDM rev 2.3 vol 2 (245318) and vol 3 (323207); Itanium 2 reference manual 251110-003 Table 2-5 for the L3 geometry. The fault values quoted are from a model that runs both processors over one shared RAM; they are model behaviour, used here only to check the reading.

**Summary.** The early table and everything it points to are built at the same physical addresses by every processor, and the builder then swaps the one record into the running processor's own slot. That only works if each processor has a private copy of `0x1000000` to `0x103ffff`. PAL procedure 520 provides it on hardware by installing that range as lines of one L3 way in the calling processor's own cache, and the PROM leaves that mode in the jump to RAM, after saving what it needs to a per-slice area in node memory. A model with one shared RAM there lets two builders and two swaps interleave on one table, so a processor reads `0xfe` from its own slot.

### 1. The extract (established)

`0xffba000c`: `extr.u r26=r26,23,4` takes `cr.lid` bits 26:23, four bits, zero-extended. SDM vol 3 `extr`: the field starts at `pos6` and runs `len6` bits to the left. Vol 2 section 5.8.3.1: `cr.lid` has eid in 23:16 and id in 31:24, so the field is id[2:0] plus eid[7]. CPU 0 (lid 0) gives 0, CPU 1 (lid `0x01000000`) gives 2. With `+2` the entries read are slot 2 (`0x1000010`) and slot 4 (`0x1000020`). The PROM sets lid itself: SAL_A `0xffc4edc0` writes `dep.z r2=r32,23,4` (`0xffc4edd0`), with r32 = PAL `r33 & 3` (`0xffc4ea7c`, called at `0xffc4e37c`), and PAL_B 5.73 builds `r33` as msr[1559] bits 21:19 shifted left by one (`0xffed7bd8`, `0xffed7bde`). The model's `0x01000000` and msr bits = slice >> 1 therefore agree with the PROM. The id/eid split is not the PROM's view: it treats bits 26:23 as one slice number, and the node-id install `0xffaec2b0` later writes `cr.lid` again.

`0xffba0000` itself is the common interruption stub, not a reset entry: the vector stubs at `0xffb98000` set `r28=pr`, `r30` = handler, `r31` = vector and branch to it; it loads the per-slice record and its save area at `+0x80`, so a fault taken with a bad slot faults again here (`ld8 [0xfe + 0x80]` at `0xffba0060`).

### 2. The builder is slice-dependent (established)

`0xffac42d0(layout, nasid, flag)`, called by every processor at `0xffa1e1b6` as `(0, 0, 0)`, right after PAL 520:

- **Base.** It reads the local NASID from `SH_SHUB_ID` (`0x8000_0081_1006_0580`, the PROM's form with bits 63 and 39 set; bare `0x1_1006_0580` is the node-local MMR offset), bits 42:32, and compares it with `nasid`. When they match the table base is plain `0x1000000`; otherwise it is the node window `0x8000_0030_0100_0000 | nasid << 38`.
- **Carves.** The carver `0xffac4230(in, out, next, flag)` walks a size list in flash: an odd entry is a marker stored with bit 0 cleared (skipped when `flag` is non-zero), an even entry stores `next` and adds the size, a zero entry stores `0x7f`, `-1` ends the list and stores the final `next`. Layout 0 uses `0xffbe6b28` (into slots 0 to 9 from `0x1000100`), `0xffbe6bc8` (slots 9 to 15 from `0x101a900`), then fills the record named by slot 2 from `0xffbe6c48` (headed `CPUPDATA`, offsets array at `+0x200`) and the arena named by slot 9 (headed `CPUTDATA`, offsets at `+0x180`). Layout 0 then skips the per-slice blocks that follow (`(p1) br` at `0xffac49f0`; the first of them reads slot 3). Before the swap the table is: slot 0 = 0, slot 1 = 2, slot 2 = `0x1000100`, slots 3 to 5 = `0xfe`, slot 6 = `0x7f`, slot 7 = `0x100a100`, slot 8 = `0x101a100`, slot 9 = `0x101a900`, slots 10 to 12 = `0xfe`, slot 13 = `0x7f`, slot 14 = `0x1024900`.
- **The swap (`0xffac6080` to `0xffac6100`, layout 0 on the local node only).** It reads `cr.lid` bits 26:23 = n and exchanges slot 9 with slot 9+n, then slot 2 with slot 2+n, with plain loads and stores (no lock, no `cmpxchg`). Then it writes `SAL-DATA` to slot 0 (`0xffac6206`).
- **Result for one processor.** Slice 0: no change. Slice 2 alone: slot 2 = `0xfe`, slot 4 = `0x1000100`, slot 9 = `0xfe`, slot 11 = `0x101a900`. Every slice gets its record at `0x1000100` and its stack arena at `0x101a900`, in its own slot.
- **Layout 1 (node window, `0xffac7a50` and `main_three`).** Uses `0xffbe6b78` and `0xffbe6c08`: four 1 MiB records and four 1 MiB arenas, one per slot 2 to 5 and 9 to 12, at `(nasid << 38) + 0x30_0200_0000` and `+0x30_0300_0000`, and no swap. Only the master runs it.

The earlier reading on this page ("only slice 0 has a record early"; "nothing else writes the early table") missed the swap; it is withdrawn.

### 3. Why the range must be private (established as code; the hardware mechanism inferred)

- Every processor's early record is `0x1000100`, its arena `0x101a900`, its backing store `[[slot 9+n] + 16]` and its stack that plus `0x7ff0` (`0xffa1e360` to `0xffa1e3ac`). Two processors on one memory there would share a record, a stack and an RSE backing store, whatever the order.
- The swap moves the record out of slot 2 when n is not 0. On shared memory a later slice-0 reader then finds `0xfe` in slot 2; a later builder run on slice 0 puts `0xfe` back in slot 4.
- Nothing in SAL_A or the SAL_B reset path holds a slice back before the builder (`0xffc4e970` returns either way; `0xffa1de00` has no slice test; `0xffa9ac80` holds only a non-zero hardware thread). Every present slice runs this code at once, as section 1 says.

So the PROM depends on `0x1000000` to `0x103ffff` being per processor from the PAL 520 call until it leaves that mode. On hardware no DRAM is configured at this point (the master sets memory up later in `main`), and the range is held in each processor's own L3 (PAL 520 below). Graded inferred for the hardware: the code shows the dependency and what 520 writes, not what the silicon does with it.

### 4. PAL 520 sets the private range up (handler established as code; meaning inferred)

Details in [pal-msrs.md](pal-msrs.md#pal-520-0x208). In short: SAL_B calls it at `0xffa9b586` with `r29 = 0x1000000`, `r30 = 0x40000`, `r31 = 0`. The PAL_B 5.73 handler (`0xffea42a0`) counts enabled L3 ways from msr[1536] bits 59:48 at 256 KiB a way, returns -4 if `r30 + r31` is larger and -5 if `r29` is not 256 KiB aligned, sets a group of msr bits (among them msr[1504] bits 24, 32 and 33, or 16, 40 and 41, chosen by `cpuid[3]` bits 15:8 against 3), and for each 256 KiB chunk issues one command with tag `r29 >> 18`, state 3 and a set range of 2048 entries, then one with sixteen zero data words (`0xffea4ad0`, `0xffea4fb0`). Read as an L3 tag-array write over one whole way followed by a zero data write (inferred from the field layout: tag shifted by 22, seven ECC bits computed over it, a 2048-entry range per way). With 128-byte lines and 4 ways per MB for parts up to 6 MB (251110-003 Table 2-5), one Madison L3 way is 256 KiB: 2048 sets × 128 bytes, with 24 ways = 6 MB. The up-to-9 MB row has 2 ways per MB, so a way is 512 KiB there; the PAL arithmetic fits parts up to 6 MB. The SHub is not touched.

### 5. Leaving the private range (established as code)

- **Save.** In the jump to RAM (`0xffac6bb0`), before any barrier, each processor copies the parts of its early records it keeps into a 16 KiB transfer area in node memory, sized per slice by `0xffadff10(..., n)` from `(nasid << 38) + 0x30_0300_0000` (`0xffac6d50` to `0xffac6ebc`; the per-slice offset is inferred from the slice argument).
- **Exit.** The first `0xffaf5c80` call (low 16 bits not `0xfffe`) runs `0xffa9bdb0`: progress `0x42`, `ptr.d` and `ptr.i` of the translation for `0x1000000` with page size 2^18 (`0xffaebb30`) and four further data purges (`0xffb20710`), then **PAL 520 with `r29 = r30 = r31 = 0`** (`0xffa9c046`), which takes the handler's disable path (`0xffea4900`): it clears the msr bits the enable set and writes no tags. Then PAL 530 and the processor test.
- **After.** In `0xffac7400` the master rebuilds the table at plain `0x1000000` with layout 1 (`0xffac7a50`, records in node memory, no swap); every processor then passes the barrier `0xffa9a130` at `0xffac745c` and reads its slot 9+n there (`0xffac7460`). From here `0x1000000` is ordinary shared node memory, written by the master only. What hardware does with the L3 lines at the disable (drop or write back) is **unknown**; the code never reads them again and does not depend on a write-back.

### 6. The faults, explained (established arithmetic on the reading above; the interleavings inferred)

| Fault | Read | Why the slot held `0xfe` |
|---|---|---|
| cpu0 `0xffa1e286` `st8 [rec+0x88]`, ifa `0x186` | slot 2 at `0xffa1e230` | cpu0 finished its builder with slot 2 = `0x1000100` (r41 to r43 at the fault, `0x1000000`, `0x1000010` and `0x1000100`, are the builder's last values: the `SAL-DATA` base, the slot-2 address and the swap's load of it), then cpu1's swap stored `0xfe` into slot 2 and the record into slot 4. The table dumped at that fault is exactly slice 2's single-processor result above. |
| cpu1 `0xffa80680` `ld8 [rec+0x188]`, ifa `0x286` | slot 4 at `0xffa80640` | cpu1 passed its own reset path, then cpu0's builder rewrote slots 3 to 5 with `0xfe`. |
| `0xffa86f90` `ld8 [rec+0x18]`, ifa `0x116` | own slot at `0xffa86f50` | Same, in another routine. |
| `0xffa1bec0` `st4.rel [0x7f+16]`, ifa `0x8f` | own record `+0xd8` | Both builders carve the same record `0x1000100`; a second run puts the carve's `0x7f` back in a field the first processor had already set (inferred; the setter of `+0xd8` was not traced). |

`0x106` and `0x206` in the table, reported earlier, are consistent with two processors spilling register frames into one backing store; not shown.

### What the model must provide

1. **A per-processor overlay of the L3-installed range.** While a processor is in this mode, its loads and stores to the range PAL 520 installed (`0x1000000` to `0x103ffff` here) go to memory private to that processor, zero-filled, and are never seen by other processors or by DMA.
   - Entry: the PAL 520 tag-install commands. The handler writes msr[1545] = `tag << 22 | ecc << 3 | 3` and msr[1546] with command bits 63:52 = `0x94c` and the set range, then the undecodable slot; tag `0x40` = address `0x1000000`, one way = 256 KiB. A model that keys on the range from these writes needs nothing guest-specific; one that keys on the PAL 520 arguments at PAL entry is an approximation and needs that stated and reviewed.
   - Exit: the disable path of the same handler, the msr[1504] write that clears bits 24, 32 and 33 (or 16, 40 and 41 on the other path). At exit drop the overlay without writing it to memory.
   - The per-CPU copy block runs only when `cpuid[3]`'s family is not 0x20, so the model must present Madison's family.
   - Whether the PROM's accesses through the 2^18 translation are write-back was not checked, so an overlay should accept any memory attribute.
2. Nothing in the SHub. The election, `cpu_bits`, node lock and progress registers stay shared and lock-correct as already modelled.
3. When the fault recurs, capture `cr.iip`, `cr.ipsr`, `cr.isr` and `0x1000000` to `0x1000060`. With `psr.ic` = 0, IPSR, IIP, IFA, IIM and IHA are left unchanged (SDM vol 2 section 5.5, pp. 2:101 to 2:102). ISR is overwritten on every interruption except a Data Nested TLB fault, and ISR.ni is set to 1. Separately, `cr.isr` `0x0000_0802_0000_0000` for the `st8` in slot 1 of `0xffa1e280` has `ei` (bits 42:41) = 0; SDM vol 2 Table 3-7 (p. 2:37) gives `ei` = `ipsr.ri` for faults, so it should be 1. Not checked against the model.

### Unknown

- What the L3 does with the installed lines on the 520 disable path, and which msr[1504] bits stop write-back or replacement. Settle by an Itanium 2 microarchitecture document that defines msr[1504] and the msr[1546] `0x94c` and `0x949` commands (none of the held revisions does), or a captured boot from a two-processor system with progress readout.
- The meaning of the undecodable slot that commits each command (see [pal-instructions.md](pal-instructions.md)).
- Whether the transfer area is per slice on hardware layouts (sized by slice argument; the sizer body was not read).
- How two CPUs holding the same address in L3 state 3 avoid each other's bus snoops.

### Counting CPUs ("%d CPUs on %d nodes found.")

Why a model that runs two processors still prints `1 CPUs on 1 nodes found.` Read from the same flat listing and the 10.54 image; no run backs a grade. The line is printed by `number_cpus_and_nodes` (`0xffaeedf0`, message at `0xffbbcc90`, print at `0xffaef340`; the name is the PROM's own string at `0xffbbcc58`). Its only caller is `hwcfg_node_probe` (`0xffaf1350`, from `0xffaa7090` at `0xffaa713c`), run by `main_three` on the master processor once the global-master bit (`cpu_bits` bit 1) is set (`0xffad765c` to `0xffaa048c`).

**Where the counts come from (established as code).** Neither `cpu_bits` nor a processor's own progress word is read there. The routine walks the node list the probe built, and for each node fetches the CPU-class board (class `0x10`, `0xffaa9530(nasid, 16)`; the board type the hub builder stores is `0x11`) in the KLCONFIG block in node memory. For every component of type 1 on that board it takes the slice (byte `+24`) and the flag byte (`+2`). Flag bit 0 set counts the CPU (it gets the next CPU number in `+28`); flag value 2 is the routine's marker for flag bit 0 clear (a disabled CPU, numbered after the enabled ones and not counted), not a flag byte it compares. The walk also handles type-2 components; their handling is not decoded. The second number is the node count the probe returns, not recomputed. A node with no CPU-class board prints `number_cpus_and_nodes: Error:No cpu brd on nasid %d` and adds nothing.

**Who creates the CPU components (established as code).** `init_klcfg_hub` (`0xffaa1ea0`, from `0xffa9fe80` at `0xffa1b3dc` in `main_two`'s master test, so before the probe) calls `0xffaa1da0` for slices `4*slab` to `4*slab + 3`. A slice gets a component only if all of these hold:

| # | Condition | Site | What the model provides |
|---|---|---|---|
| 1 | bit `slice` of the L1 processor-presence word is set | `0xffae8660` (L1 request `0x0010`, [l1-requests.md](l1-requests.md#8-0x0010-processor-presence-progress-0x10)) at `0xffaa207c`, tested at `0xffaa1e06` | presence AND enable word with bits 0 and 2 for CPUs 0 and 1 (`0x5`). A negative return (a bad count, `-100`) is replaced by `0xf`, which passes this row |
| 2 | the front-side-bus status bit for the slice is set | `0xffa11710` to `0xffa115e0` to `0xffa11560`: one `ld8` of `0x8000_0009_2002_0080 + (nasid << 38)`, returns bit `slice / 2`; slices 1 and 3 return 0 without a read unless `cpuid[2]` is the simulator value | bit 0 for CPU 0 and **bit 1 for CPU 1** (value `0x3`). The master reads bit 0 here too, for its own slice |
| 3 | then `init_klcfg_cpu` (`0xffaacbd0`, from `0xffaa1e8c`) creates the component and sets the enabled flag only if `cpu_bits` bit `26 + slice` reads 1 (`0xffa99870(obj, 26 + slice)` at `0xffaacda8`, global window of the node) | CPU 1: bit 28 | CPU 1 has set its own bit 28 before the master runs `0xffa1b3dc`; nothing clears it before the probe. A clear bit makes flag 2, reason 253 unless `DisCpusReason` names one, and the CPU is not counted |

Rows 1 and 2 decide whether a component exists at all; row 3 only decides enabled or disabled. The CPU table at block A `+0x18` that the SAL tables and the boot-processor choice use is written by `0xfface0b0` under rows 2 and 3 as well (entry iff the front-side-bus bit is set; flag word 1 iff `cpu_bits` bit `26 + slice` is set), so a CPU invisible to row 2 is missing from the MADT too.

**What the master waits for in `main` (established as code).** `main` calls `0xffa99cf0` on every processor, before the table writer and the KLCONFIG build.

1. Each processor takes its socket from PAL_FIXED_ADDR bit 1 (`0xffa9b1f0` to `0xffa9ae80`; the Madison PAL answers PAL_LOGICAL_TO_PHYSICAL with -1 and the fixed address is `msr[1559]` bits 21:19 shifted left by one, so CPU 1 is socket 1, slice 2, `cr.lid` field 2). It stores a 3-bit field at bit `47 + 3 * socket` of `cpu_bits` (`0xffa99dcc`; value `r9[39:32]` of PAL_LOGICAL_TO_PHYSICAL, or 1 on -1: bits 52:50 hold 1 for CPU 1) and sets its own bit `26 + slice` (`0xffa99dfc`).
2. It counts the present sockets: itself without a read, the other one by the front-side-bus bit (`0xffa11560`, row 2). Then it polls every 500 microseconds until every present socket's 3-bit field is non-zero (`0xffa99ea0` to `0xffa99f50`), and sums the fields into the expected CPU total.
3. It then polls `cpu_bits` bits 29:26 every 500 microseconds until the number set equals that total (`0xffa99f70` to `0xffa99fd6`).
4. For each slice whose bit 26+i is still clear it calls `0xffa9fba0`, which halts only when the slice is the caller's own. Nothing is printed and nothing fails.

So a socket the front-side-bus bit does not show is not waited for and not counted, even when the CPU runs and sets bit 28; and a socket it does show but whose CPU never writes its field costs the full timeout below and is still counted if bit 28 is set later (the build is after the wait).

**Timeouts.**

| Wait | Site | Deadline | Units | On expiry |
|---|---|---|---|---|
| socket fields non-zero | `0xffa99f30` to `0xffa99f5c` | `0x4c4b3f` = 4,999,999, compared with a running sum | microseconds requested from the delay `0xffa0db90` (500 per round), not measured time | falls through (established) |
| ready bits 29:26 equal the expected total | `0xffa99fb6` to `0xffa99fdc` | same | same | falls through (established) |
| slice barrier `0xffa9a130` | | none found: the loop reads `cpu_bits` and has no counter | | never (inferred from the absence of a counter in the listing) |

The delay (`0xffa0db90`) converts microseconds to nanoseconds and then to ticks of the SHub real-time counter `0x81_101c_0000`, with the period from `0x1_1006_0280` bits 13:4 (`0xffa0da00`, inferred), and spins on the counter. A model whose counter does not advance spins forever instead of timing out.

**Disabling (question of a separate result).**

- The L1 report is request `0x0010`, sent three times: `main_early_disable` (`0xffad34a0`, via `0xffad3a7c`), `init_klcfg_hub` (`0xffaa207c`) and the probe step of `main_three` (`0xffad3ed0`, called at `0xffaa047c`). Only `main_early_disable` acts on it per processor: each processor tests bit `cr.lid[26:23]` of the presence-and-enable word and the letter `A + slice` in `DisabledCpus`; a clear bit or a listed letter gives progress `0x87` (135), `0xffa9f750` (clears that CPU's flag word in the block A `+0x18` table) and `0xffa9fba0`, which for the caller's own slice halts at `0xffaeb7c0`. So CPU 1 (`C`) needs bit 2 in the L1 word or it halts before it is counted (established as code).
- `DisabledCpus` (letters `A` to `D`, slices 0 to 3) and `DisCpusReason` are SAL environment strings read by `0xffad6e30` ([efi-boot.md](efi-boot.md)); blank means nothing disabled. They also clear the table flag of a listed CPU for every entry (`0xffad39c0`), and set the reason code in the KLCONFIG component (`0xffaace6c`). The `disable` and `enable` shell commands (`0xffa9f2c0`) edit them. If the scan finds no CPU that is both present and not listed, `0xffa0af70` runs; what it does was not read (unknown).
- There is no separate "CPU disabled" result beyond these: the OS sees it as the table flag (MADT local-SAPIC flag bit 0) and, for the SAL runtime, the boot state of [SN_SAL_SET_CPU_NUMBER](#what-releases-a-parked-processor-established-as-code). The string `CPU disabled from POD.` (`0xffba7608`) is only in a pointer table (`0xffbd7838`); its user was not read (unknown). Whether the SAL runtime carries any other presence service was not searched (unknown).

**What the model must provide for CPU 1 to be counted** (all three are needed; the first is the likely miss when two processors run but one is reported):

1. `0x1_2002_0080` of the node (`0x8000_0009_2002_0080` global form) reads with bit 1 set (and bit 0 set): established that the code needs it; that the register is a per-FSB agent-present word is inferred from the name and use.
2. The L1 `0x0010` reply (or an error, which becomes `0xf`) has presence and enable bit 2 set, and CPU count and node count within the limits (4, 16).
3. CPU 1 sets `cpu_bits` bit 28 before the master builds KLCONFIG, and the 3-bit field at bits 52:50 (value 1 on this PAL), which needs only the plain shared word and node lock already modelled.

Unknown: the meaning of bits 4 and 5 and the full register layout on hardware; whether `0xffa0af70` (all CPUs disabled) changes the count; the `update_klcfg_cpuinfo` routine (strings at `0xffbb64a0` to `0xffbb6510`), which fills per-CPU data after the components exist and was not located.

### Secondary CPU at the switch to RAM

Why a model with two processors can end with CPU 0 at `0xffaf5f20` and CPU 1 at `0xffe7f100` after "Switching to RAM and testing CPU". Read from a flat `ia64-linux-gnu-objdump` listing of `shub1snprom.bin` (SAL 5.04); nothing was run. [pal-b-halts.md](pal-b-halts.md) has the PAL_B 5.73 stop itself.

**What releases CPU 1: nothing.** *Established.* `0xffe7f100` is `br.few` to itself with `psr.ic` and `psr.i` clear. It reads no register or memory, so it waits for no SHub value, memory flag, IPI, or halt wake-up, and the PAL never re-enables interrupts there. No value the master or the SHub could deliver continues it. The model has to keep CPU 1 from getting there. Whether hardware INIT or reset still reaches it is **unknown**; that code was not read.

**Where CPU 1 is in the boot (inferred from static order).**
- Both processors run the jump to RAM at `0xffac6bb0`, before the master loop `0xffa99cf0`. The loop has not run on either processor, which fits CPU 1 not having written its `cpu_bits` field. CPU 0 is not waiting for CPU 1.
- The order in `0xffac6bb0` (established): save to the transfer area; barrier `0xffa9a130` (call at `0xffac6edc`); test on `0xffa0ff30`'s result (`0xffac6ef0`); the prints at `0xffac6f4c` ("Switching to RAM %s", gp-relative `-1962456`; gp is `0xffd98000`, derived from the "number_cpus_and_nodes" message address); PAL 37 (PAL_TEST_INFO, `0xffac701c`); a per-slice test address `base + n * size` with `n = cr.lid[26:23]` (`0xffac70b0` to `0xffac7140`; the unit was not decoded); then `0xffaf5c80` at `0xffac723c`. Which processors print was not decoded (**unknown**).
- `0xffaf5c80` runs `0xffa9bdb0` (progress `0x42`, PAL 520 with zeros), `0xffaeb560` (PAL 530, returns -1) and then the processor test, PAL_TEST_PROC (`0xffb208b0`, progress `0x36`). PAL 520 and 530 are skipped when the low 16 bits of the packed argument equal `0xfffe`, and the whole test is skipped when `r34` is 0. The master does not test slaves. Each processor tests itself, on its own buffer, with no cross-CPU access (established as code). The only per-CPU state the group 1 pattern test touches is `buffer + 1024 * msr[1559][21:19]` (`0xffeffa6c` to `0xffeffaac`).

**CPU 0 at `0xffaf5f20` (established).** This is not a wait on CPU 1. It is the fourth store of the failure tail of `0xffaf5c80`: after `0xffb208b0` returns a non-zero `r8` (`0xffaf5da0`), the code shifts `r8` into a per-slice progress word (`0xffaf5e76`), a history of progress bytes rather than one byte, clears `cpu_bits` bits 29:26 at `0x81_5003_1550` (`0xffaf5ec0`), ORs `0x28000000000` into `0x81_101d_0080` (`0xffaf5ef6`), stores `0x0001000100000000` to `0x81_2000_0000` (`0xffaf5f20`) and spins at `0xffaf5f30`. So CPU 0 is reporting a failed PAL_TEST_PROC, the decode in [pal-b-halts.md](pal-b-halts.md#6-pal_test_proc-phase-two-and-the-failure-bits). Why the sampled PC is `0xffaf5f20` and not `0xffaf5f30` is **unknown**; a translated block that starts at the store and ends in the self-branch would explain it (inferred). Note the tail clears the ready bits of every slice.

**How CPU 1 gets to `0xffe7f100`: a sixth entry the stop page missed (established).** `0xffe7ec10` is the shared "unexpected interruption" target of PAL_B 5.73's vectors. It reads `cr.isr` into `r18`, `cr.iip` into `r21` and `cr.ipsr` into `r22`, then runs through 61 nop bundles to `0xffe7f000` with no branch. Fifty sites branch to it: the VHPT, ITLB, DTLB, alternate TLB, key-miss, dirty, access, page-not-present, key-permission, access-rights, general-exception, disabled-FP, NaT, speculation (when `r14` is not 111), unaligned, FP fault and trap, lower-privilege, taken-branch, single-step and IA-32 stubs at `0xffe78000 + offset`, and the break vector for an unknown immediate. So any fault in a PAL self-test that the test did not expect ends at `0xffe7f100` with `psr` low bits kept (here `0x30`, the FP dirty bits) and nothing reported. The other five ways in are in [pal-b-halts.md](pal-b-halts.md#1-what-0xffe7f100-is).

Which one CPU 1 took is **unknown** without a capture. Candidates from the code (inferred):
1. An unexpected fault through `0xffe7ec10` during PAL_TEST_PROC, PAL 520 or PAL 37. The phase-two groups that switch translation on (the VHPT and region-register tests around `0xffeff7a8`, group 6 at `0xffeff020`, group 7 at `0xffefc680`) are where a missing TLB, key or access-rights vector would show.
2. The failure arm of `0xffebf000` with `r8 < 0` and `r9[1:0] = 3`. In phase two only group 1 (`0xffeffa40`, test-buffer read-back, constant `0x100000003` at `0xfff00358`) calls it with low bits 3; every other phase-two group uses low bits 2 or 1 and returns `-3` to SAL (call-site constants read by scan, not a full flow trace). A memory test failure on CPU 1's buffer would take this route. CPU 0's failure tail above comes from the non-fatal groups (4, 8 and 10 in the earlier decode).
3. The four event-handler routes (machine-check and INIT entry code), unlikely at this point.

**What the model must provide (inferred).** CPU 1 must pass PAL_TEST_PROC without a fault or a group 1 mismatch: the same instruction behaviour as CPU 0 plus a real, private-per-slot test buffer at its per-slice address, and `msr[1559]` bits 21:19 equal to 1 for CPU 1. Nothing in the SHub, no IPI. CPU 0 will still stop at `0xffaf5f30` until groups 4, 8 and 10 pass.

**Capture requests for CPU 1 (exact).** Break on CPU 1 at each address and dump `r8`, `r9`, `r18`, `r21`, `r22`, `r30`, `b0`, `b7`, `ar.k7`, `cr.iva`, `cr.isr`, `cr.ifa`, `cr.iim`, `cr.iipa` and `cr.ipsr` (the stop leaves `r18`, `r21`, `r22`, `cr.isr`, `cr.ifa` and `cr.iim` as the interruption set them; the helper at `0xffe96bd0` overwrites `cr.iip`, `cr.ipsr`, `cr.ifs`, `r2`, `r8`, `r9`, `r10` and `r28`):
- `0xffe7ec10`: which vector (the previous PC) and the faulting `cr.iip`, `cr.ifa`, `cr.isr`. It fires only on route 1.
- `0xffebf2a0`: route 2; `ar.k7` bits 63:32 hold the failing group's second argument and `r9` its constant.
- `0xffe880ac`, `0xffeba1fc`, `0xffed41ec`, `0xffed47ec`: the event-handler routes; `r30` is the reason (3, 5, 6, 9).
- Group entries in `0xffeaa190`'s table, to see the last group entered: `0xffeffa40`, `0xffefc530`, `0xffefe0f0`, `0xffef9160`, `0xfff0acb0`, `0xffeff020`, `0xffefc680`, `0xffefd2f0`, `0xffef98f0`, `0xfff003b0`, `0xfff04ff0`.
- A call trace from `0xffac6edc` of CPU 1 through `0xffa9a130`, `0xffa9bdb0`, `0xffa1da50` (PAL 520), `0xffaeb560`, `0xffb208b0` and `0xffaf5da0`.
For CPU 0, `r8` and `r9` at `0xffaf5da0` give the failing-group decode.

### CPU 0 taking repeated external interrupts in RAM

Read from the same flat listing and SDM rev 2.3 vol 2 (`cpu/itanium/`); nothing was run. A model trace showed CPU 0 delivering vector offset `0x3000` hundreds of times, from three RAM
addresses (`0x30027e41c0`, `0x30027e4da0`, `0x300255de10`) with an unchanged `cr.ifa`.

- **`0x3000` is the External Interrupt vector (established).** Table 5-7, pp. 2:113 to 2:114, and the vector description, p. 2:186. Its defined parameters are IIP, IPSR, IIPA, IFS, IVR and ISR, not IFA,
  so a stale `cr.ifa` there means nothing. `cr.ivr` names the vector that was taken, and 15 is "spurious".
- **PAL's own handler at that offset (established).** With `cr.iva` at PAL_B (`0xffe78000`) the handler is `0xffe7b000`: it reads `cr.ivr`; for a vector other than 255 it writes `cr.eoi` and does
  `rfi` back to the interrupted instruction. It also sets `r30` to `0x3000` and toggles bit 3 of `r14`; for vector 255 with msr[1640] bit 57 set it takes a longer path at `0xffe7b070`. An interrupt source that stays asserted is then taken again at once, so the interrupted address repeats. Whether `cr.iva` still points at PAL
  there is **unknown**; the SAL and EFI tables were not read for this.
- **The three addresses are not in the SAL shadow copy (established as code).** They are node-window addresses (`0x30_0000_0000` plus offsets `0x255de10`, `0x27e41c0`, `0x27e4da0`). The shadow copy
  of the flash is at offsets `0xa00000` to `0xffffff` ([the SAL shadow copy](boot-sequence.md#the-sal-shadow-copy-and-its-destination)), and the other RAM images the PROM makes are the SAL runtime and the EFI
  ELF, which its loader (`0xffaf8690`) places at run-time-chosen addresses. No static offset maps these three back to PROM addresses; the load base is **unknown** until a run reports it. To settle it,
  read 16 bytes at each address and search the inflated EFI and runtime images for them.
- **A likely source (inferred).** SAL call `0x6000` op 1 arms the interval timer on vector `0xef` for EFI's countdowns ([runtime-services.md](../../sal/runtime-services.md)), so an EFI idle loop takes
  timer interrupts for as long as it waits, and taking `0x3000` repeatedly there is expected. What would be a defect: an interrupt that fires while `ar.itc` is past `cr.itm` instead of once when they are
  equal (SDM vol 2, section 3.3.4.2, p. 2:33), or one whose handler never clears the source. Capture at each delivery `cr.ivr`, `cr.iva`, `cr.itm`, `ar.itc` and `cr.itv`: `0xef` with `itc` moving past `itm` and `itm` being
  rewritten is the tick; the same `itm` reprogrammed never, or a vector that is not `0xef`, `0x12` or `0x13`, is not.
- **A CPU 0 that is running here did not take SAL's failure tail (established as code).** SAL keeps any non-zero `r8` from PAL_TEST_PROC as fatal for that processor (`0xffb20a40`, then `0xffaf5da0`
  falling to the spin at `0xffaf5f30`). A group's `-3` is non-fatal only inside PAL (`0xffebf000`). So a CPU 0 in RAM means `r8` was 0 at `0xffaf5da0`, or the test was skipped (`r34` = 0 at `0xffaf5d60`, or the
  low nibble of `r45` = 1 at `0xffaf5d70`). Groups 4, 8 and 10 failing and the shell still being reached do not fit that code; check `r8` there.

## Review (independent, chips c669e77 and fbb3bc7: per-slice table, PAL 520 and the overlay recipe)

Independent re-read of the section "5. Multi-CPU entry and the per-slice table" as it stands after `c669e77`, against a flat `ia64-linux-gnu-objdump` listing of `shub1snprom.bin` SAL 5.04 loaded at `0xffa00000` (binutils 2.44, re-run toolchain image), the Itanium SDM rev 2.3 vol 2 text and Itanium 2 reference manual 251110-001 to -003. The reviewer wrote none of it and used no restricted source. `fbb3bc7` is the earlier version of the same section; its "only slice 0 has a record" reading is withdrawn by `c669e77`, and the review covers the final text. The fault values and the 12-word table dump are model output and were checked only for arithmetic against the code.

**Verdict.** The reading of the table builder, the swap, PAL 520 and the exit holds. The per-CPU overlay recipe is not made wrong by anything found. Three wording defects need fixing (a wrong SDM citation that changes advice, an over-general cache-way claim, a duplicated section number); none changes the recipe.

**Confirmed (established, read from the listing).**

- **Builder `0xffac42d0`.** `SH_SHUB_ID` is read by an uncached load and `extr.u ..,32,11` (bits 42:32) is compared with the `nasid` argument; match gives base `0x1000000`, otherwise `0x8000_0030_0100_0000` with the NASID deposited at bit 38. Called by every processor at `0xffa1e1b6` as `(0, 0, 0)`, after the hold routine `0xffa9ac80` and after PAL 520 (`0xffa1e19c` calls `0xffa94b10`, which calls `0xffa9bce0`, which makes the PAL call at `0xffa9b5cc`).
- **Carver `0xffac4230` and the two lists.** Flash lists `0xffbe6b28` (`1, 3, 0xa000, 0xff x3, 0, 0x10000, 0x800, -1`) and `0xffbe6bc8` (`0xa000, 0xff x3, 0, 0x4000, 0, -1`) give, with the carver's rules, exactly the page's pre-swap table. The second list starts at slot 9 and runs to slot 15 (a zero entry gives `0x7f`), and its final `next` goes to slot 16; the page says "slots 9 to 15" and omits slots 15 and 16. Immaterial to the recipe. The gp is `0xffd98000` (`0xffa1e0e6`), which fixes the list addresses.
- **Swap `0xffac6080` to `0xffac6100`.** `extr.u cr.lid,23,4`; exchange of the words at `0x1000048` and `0x1000048 + 8n`, then at `0x1000010` and `0x1000010 + 8n`; plain `ld8`/`st8`, no lock. Skipped when the layout argument is non-zero or the NASID is not local (`0xffac6070` branches to `0xffac6110`). `SAL-DATA` is the `movl` at `0xffac6206`, stored at `0xffac6210` into slot 0 of whichever base was chosen.
- **The 12-word capture.** Working the carve and the n = 2 swap by hand from the flash lists gives every word of the capture (slot 0 `SAL-DATA`, slot 1 `2`, slots 2 and 3 `0xfe`, slot 4 `0x1000100`, slot 5 `0xfe`, slot 6 `0x7f`, slots 7 and 8 `0x100a100` and `0x101a100`, slots 9 and 10 `0xfe`, slot 11 `0x101a900`). Word for word.
- **Readers use slot 2 + n.** `0xffa1e1f6` to `0xffa1e230` (record), `0xffa1e310` to `0xffa1e360` (slot 9 + n, backing store at `+16`, stack at `+0x7ff0`). The four fault reads decode as the table says: `st8 [rec+0x88]` (ifa `0x186`), `ld8 [rec+0x188]` (`0x286`), `ld8 [rec+0x18]` (`0x116`), `st4.rel [0x7f+16]` (`0x8f`).
- **Exit.** `0xffac723c` calls `0xffaf5c80` with a packed first argument whose low 16 bits are `0xffff` (not `0xfffe`), so `0xffaf5d4c` calls `0xffa9bdb0`: progress 66 (`0x42`) written at `0xffa9be86`, `0xffaebb30` purges `0x1000000` at page size 18 (and a second, larger page) through `ptr.d`/`ptr.i` at `0xffaeb9e0`, `0xffb20710` purges four data translations, then `movl r28=0x208` with `r29 = r30 = r31 = 0` at `0xffa9c046`. This runs before the continuation `0xffac7400`, which the existing [boot sequence](boot-sequence.md) already reads as entered through `0xffaf5c80`. The master test, layout-1 rebuild (`0xffac7a50` calls the builder with `(1, local nasid, 0)` and returns to `0xffac7450`) and the barrier call at `0xffac745c` are as stated. The call at `0xffac745c` is `0xffa9a130`, which [prom-reset.md](../../../devices/shub/prom-reset.md) already reads as a four-slice barrier.

**Corrections needed.**

1. **Wrong SDM section and a wrong consequence (item 3 of "What the model must provide").** The page says that with `psr.ic` clear "a nested fault leaves IFA, ISR and IIP from the first one (SDM vol 2 section 5.8, p. 2:101)". The text is section 5.5, "IVA-based Interruption Handling", pages 2:101 to 2:102. With `psr.ic` = 0, IPSR, IIP, IIPA, IFS.v, IFA, IIM and IHA are unchanged, but **ISR is overwritten on every interruption except a Data Nested TLB fault, and ISR.ni is set to 1** (2:102, item 2). So a dumped ISR is the last fault's, not the first; ISR.ni = 0 in the quoted `0x0000_0802_0000_0000` means either `psr.ic` was 1 or the model leaves ni clear. That value also decodes as w (bit 33) and ed (bit 43) set, ni clear, ei = 0.
2. **Cache-way size "at any cache size".** Table 2-5 of 251110-003 gives 4 ways per MB for the three smaller Itanium 2 rows (up to 6 MB) but **2 ways per MB for the up-to-9 MB row**, where one way is 512 KiB. The 256 KiB way, 2048 sets of 128 bytes and the 24-way ceiling (6 MB) hold for parts up to 6 MB, which is what the PAL code assumes. Qualify the sentence in section 4; the PROM's own arithmetic is consistent.
3. **Two sections numbered 5.** The file already has "## 5. Processor ids (cr.lid) and IPI pids"; the new section is also "## 5", with sub-headings "### 1." to "### 6." The anchor `#5-multi-cpu-entry-and-the-per-slice-table` is unique and the links resolve, but the numbering collides.

**ISR.ei side note: confirmed.** SDM vol 2 Table 3-7 (p. 2:37): "For faults and external interrupts, ISR.ei is equal to IPSR.ri". The `st8` at `0xffa1e286` is slot 1 of the `[MMI]` bundle at `0xffa1e280` (`srlz.d; st8; nop.i`), so a fault there has ei = 1, and the model's ei = 0 is a model defect. Caveat from correction 1: this holds only if the dumped ISR belongs to that fault.

**The overlay recipe (item 4).** Entry and exit are as the page states and are keyed on observable writes:

- Enter on the msr[1545]/msr[1546] tag install (`0xffea5100`, `0xffea5126`, `0xffea52a6`). The msr[1504] enable bits are set earlier, at `0xffea4840`, before any tag is written, so keying on msr[1504] set would enter too early. Tag is `address >> 18`; for the PROM's call (`r30 = 0x40000`) it is one way at tag `0x40`.
- Zero fill is supported by one more fact: the second command is preceded by 16 zero msr writes (msr 1600 to 1603, 1608 to 1611, 1616 to 1619, 1624 to 1627), 16 x 8 bytes = one 128-byte line, issued over the same 2048-entry range.
- Exit on the msr[1504] write that clears bits 24, 32 and 33 (or 16, 40 and 41) at `0xffea4a00`. Other PAL code also read-modify-writes msr[1504] (for example bit 48 at `0xffe9a9bc`), so key on those bits going from set to clear.
- The disable path also writes msr[1040] = 4 (`0xffea4a80`); it does not restore the value from before.
- I found no PROM site that reaches another processor's early range between entry and exit: the hundreds of references to `0x1000038` and `0x1000070` are plain local physical addresses; the only use of the `0x8000_0030_0100_0000 | nasid << 38` form is the builder with a non-local NASID or layout 1, after the exit. This is a read of the sites found, not an exhaustive trace. Nothing in the SHub is involved.
- After the exit nothing reads the overlay: each processor copies its records to node memory before it (`0xffac6d50` to `0xffac6ebc`), the exit comes before the master's rebuild, and slaves read the rebuilt table only after the barrier.
- Two conditions the recipe should state. (a) The copy block (`0xffac6c10` to `0xffac6ebc`) is on the path for `cpuid[3]` family other than 0x20 (`0xffac6c00` sends family 0x20 to `0xffac7380`, which rejoins at `0xffac6ed0` after the copy); the model must present Madison's family. (b) The accesses in the early stage are physical and cacheable (`rsm 0x24000`, bit 63 clear). Whether the PROM's virtual-mode accesses (the page-size 2^18 translation for `0x1000000` purged at exit) carry a write-back attribute was not checked; an overlay that takes any attribute is the permissive choice.

**What the hardware does is still unknown, as the page says.** Two points the page could add to its unknowns: how the state-3 lines of two processors holding the same address stay out of the front-side bus snoop, and whether the line is dropped or written back at exit.

**Not checked.** The fault interleavings (model runs, not reproducible here); the `0xffba0000` stub body; `0xffadff10`'s per-slice sizing; the PAL_B 5.73 five-routine prologue at `0xffe88250` to `0xffe89040`; whether the Itanium revision split at 3 matches any real part; PAL_B image identity (5.73) was taken from the page.

## Review (independent, chips f2ee812, 1c8da93 and 2809cf5: secondary CPU at the switch to RAM, repeated external interrupts, counting CPUs)

Re-read of "Counting CPUs", "Secondary CPU at the switch to RAM" and "CPU 0 taking repeated external interrupts in RAM" against a flat `ia64-linux-gnu-objdump` listing of `shub1snprom.bin` (SAL 5.04, sha256 `51ccf9ad...`) and SDM rev 2.3 vol 2. The reviewer wrote none of it and read no restricted source. Nothing ran.

**Verdict: all three hold. Established claims were each found in the listing; five wording or completeness fixes.**

**Secondary CPU at the switch to RAM (f2ee812).**
- Confirmed: `0xffe7f100` is `br.few` to itself with `mov r7=0xcccc` and no other read. `0xffe7ec10` reads `cr.isr`, `cr.iip`, `cr.ipsr` into `r18`, `r21`, `r22` and falls through 61 nop bundles (`0xffe7ec30` to `0xffe7eff0`) into `0xffe7f000`. Exactly 50 branches to `0xffe7ec10` exist, all `br.*`, between `0xffe7804c` and `0xffe7ec0c`.
- Confirmed order in `0xffac6bb0`: barrier call `0xffac6edc`, the `0xffa0ff30` test at `0xffac6ef0`, the print call `0xffac6f4c`, PAL 37 call `0xffac701c` (index loaded into `r47` at `0xffac6fc0`, `test_phase` 0), the per-slice `xma` at `0xffac713c` (`aligned_size * lid[26:23] + aligned_base`), then `0xffaf5c80` at `0xffac723c`.
- Confirmed failure tail: non-zero `r8` at `0xffaf5da0`; `0xffaf5e76` stores into the per-slice word at `0x81_5003_1500 + 16 * lid[26:23]`; `0xffaf5ec0` clears bits 29:26 of `0x81_5003_1550`; `0xffaf5ef6` ORs `0x28000000000` into `0x81_101d_0080`; `0xffaf5f20` stores `0x0001000100000000` to `0x81_2000_0000`; `0xffaf5f30` spins.
- Fix 1: `0xffa9bdb0` (PAL 520) and `0xffaeb560` (PAL 530) are not unconditional. `0xffaf5d40` compares the sign-extended low 16 bits of the packed first argument with `0xfffe`; equal skips both. The call at `0xffac722e` passes `0xffff`, so they run. The test is also skipped when `r34` = 0 (`0xffaf5d0c`, `0xffaf5d60`). Fix: add both conditions (pal-b-halts.md already states the `0xfffe` test).
- Fix 2: the write at `0xffaf5e76` shifts `r8`'s low byte into a 64-bit per-slice word (`shl r11,8` then `dep r11 = r10,..,0,8`); it is a history of progress bytes, not one byte. Fix: say "progress word" and that the last byte is the latest.
- Fix 3: the page names PAL 37 PAL_MEM_FOR_TEST (as does boot-sequence.md line 290). SDM rev 2.3 calls index 37 PAL_TEST_INFO (p. 2:461), and the PAL_TEST_PROC page uses that name. Fix: use PAL_TEST_INFO and note the older name once.

**CPU 0 taking repeated external interrupts (1c8da93).**
- Confirmed: vector `0x3000` is External Interrupt (Table 5-7, pp. 2:113 to 2:114; vector text p. 2:186; parameters IIP, IPSR, IIPA, IFS, IVR, ISR; IVR 15 is spurious). ITC equal to ITM raises the timer interrupt (section 3.3.4.2, p. 2:33). The offset `0xffe7b000` handler reads `cr.ivr`, and for a vector other than 255 writes `cr.eoi` and does `rfi`. The addresses `0x30_027e41c0` and the other two are node-window addresses (`0x30_0000_0000` plus the offsets given).
- Confirmed: SAL keeps non-zero `r8` from PAL_TEST_PROC (`0xffb20a40`) and `0xffaf5da0` then takes the failure tail; the skip routes are `r34` = 0 and `r45` low nibble 1 (`0xffaf5d70`).
- Fix 4: "reads `cr.ivr`... writes `cr.eoi` and does `rfi` back, nothing else" is incomplete. The handler also sets `r30 = 0x3000` and toggles bit 3 of `r14`, and for vector 255 with msr[1640] bit 57 set it takes a longer path at `0xffe7b070` (reads msr[1558], msr[1505], msr[1506]). Fix: say so, since `r30` is what the stop-page capture uses.

**Counting CPUs (2809cf5).**
- Confirmed: strings at `0xffbbcc90` and `0xffbbcc58`; the function at `0xffaeedf0` runs to the next `alloc` at `0xffaef430` (its first part de-duplicates the node list); the print call is `0xffaef36c`. The KLCONFIG walk calls `0xffaa9530(nasid, 16)` at `0xffaef07c`, reads the component type at +0, the slice at +24, the flag at +2 and stores the CPU number at +28.
- Confirmed: `0xffa11560` loads `0x8000_0009_2002_0080 | nasid << 38` and returns bit `r33`. The wrapper `0xffa115e0` (called via `0xffa11710`) passes `slice / 2` for slices 0 and 2, returns 0 for slices 1 and 3, and passes `4 + slice / 2` for them only when `cpuid[2]` is the simulator value `0xaeeeeeee8badbeef`. That explains the "bits 4 and 5" unknown.
- Confirmed: `init_klcfg_hub` slice loop `0xffaa1da0` tests the presence bit (`0xffaa1e06`), calls the FSB wrapper (`0xffaa1e5c`) and creates the component (`0xffaa1e8c`); a negative L1 reply becomes 15 (`0xffaa20a0`).
- Confirmed: `main` writes the 3-bit field at `47 + 3 * socket` (`0xffa99dc0` to `0xffa99dcc`) and its own bit `26 + lid[26:23]` (`0xffa99df0` to `0xffa99dfc`). The two waits start at `0xffa99ea0` and `0xffa99f70`; each adds 500 per round, calls the delay with 500, and falls through once the sum exceeds `0x4c4b3f`, so 10,000 rounds and 5,000,000 microseconds requested, silently. The delay `0xffa0db90` converts microseconds to nanoseconds (times 1000), passes that and a period computed from `0x1_1006_0280` bits 13:4 (`x * 10 + 10`, inferred as the page says) to a helper (`0xffa14c00`, not read) and spins on `0x81_101c_0000`. The `DisabledCpus` and `DisCpusReason` strings exist; `main_early_disable` calls `0xffa9f750` then `0xffa9fba0` (`0xffad37bc`, `0xffad37dc`), and `0xffa9fba0` halts only when `lid[26:23]` equals its argument.
- Fix 5: the walk also handles type-2 components (`0xffaef1b0` stores `r38` into +28 for them; not decoded). The page says "every component of type 1" and is right about CPUs, but "flag value 2" is the table marker the routine uses for a CPU whose flag bit 0 is clear, not a flag byte compared at +2. Fix: say "flag bit 0 clear (the routine marks it 2)".

**Not verified.** The letter `A + slice` test and progress `0x87` in `main_early_disable`; PAL_FIXED_ADDR and PAL_LOGICAL_TO_PHYSICAL answers; the -100 L1 value; the shadow-copy range and loader `0xffaf8690`; SAL call `0x6000` op 1 and vector `0xef`; `0xffa0af70`; whether `0xffa99f30` waits are measured by the RTC (the code accumulates requested time, so no).

## Review (independent, chips 5616723: machine check on an empty-slot probe)

Independent re-read of `5616723` against `shub1snprom.bin` 10.54 (sha256 `51ccf9ad...`): a flat `ia64-linux-gnu-objdump` listing of the image at `0xffa00000` plus the SAL runtime ELF gunzipped from FIT entry 9 (`0xffc52000`) and listed on its own (binutils 2.44, re-run toolchain image). The reviewer wrote none of it and used no restricted source.

**Confirmed.**
- Decision routine `0xffa07230`: called with type 0 from `0xffa030bc` and a return of 4 or 2 selects the resume (`0xffa030d0`). For type 0: PSP bit 9 set returns the not-recovered status; PSP bit 18 set likewise; otherwise `0xffa05610` is called and a non-zero result stores 32, which later returns 4 (`0xffa07550`); zero falls to the per-type byte at `+10` of `0xffa07e90`. The IPSR bit 13 test (`+0x1a8`), the `0xffa31aa0` read of bit 3 of `0x8000008120010100` (`0x1_2001_0100` plus the `0x80_0000_0000` window) and the `B+0x53c8` word (`21448`) gate the uncontained override as written; `PAL_MC_CLEAR_LOG` (21) is called at `0xffa0742c`.
- PAL_MC_RESUME: the stub at `0xffa37ff6` sets `r28 = 0x1a`, `r29`, `r30`, `r31` from `r9`, `r10`, `r11`. It is reached through `0xffa02f40` and the register restore at `0xffa37890`, not by a direct call to `0xffa37ff6`. `r29` is the new context (0 from the call at `0xffa0348c`), `r30` is the record word at `+0x570` (the min-state pointer) and `r31` is 0.
- Region walk `0xffa05610`: entries 32 bytes apart from `B+0xb8` (flags, start `+0xc0`, end `+0xc8`, resume `+0xd0`), ended by a zero start, match `start <= ip <= end`, tested on `XIP` (`+0x1b8`) and `IIP` (`+0x1a0`), replacing the instruction pointer with the resume address, clearing status bits 42:41 and copying flags bit 16 into bit 17; per-slice flag at `B+0x4d8+slice`, slice from `cr.lid` bits 26:23, lock timeout 100000. The add routine `sal_event_add_mc_region` (`rt:0x3a6e0`) takes the lock at `B+0xb0` and refuses an index above 31.
- Runtime: `sal_probe` `rt:0x83be0` to `rt:0x83c40`, `sal_probe_end` `rt:0x83c40`, resume stub `rt:0x83c50` (`r8 = 1`, `r9 = 0`); `sal_event_probe` `rt:0x79cc0` accepts only sizes 1, 2, 4 and 8 (else returns 2), registers those three function descriptors (relocations at `rt:0x84008`, `0x84010`, `0x84030`), stores the address at `+0x5308 + slice*8`, brackets the call with `mcrz_set_probe(1)` and `(0)`, and removes the region.
- PALE_CHECK: `0xffffff90` branches to `0xffff8a80`; the stub saves `r29` to `r31` and the predicates, reads msr[1640] and goes to the common error exit `0xffff8120` with `r30 = 2` when bit 56 is clear. In PAL_B 5.73, `0xffeca8b6` and `0xffeca8d6` send `cr.ipsr` bit 13 set, or msr[1283] bit 63 clear, to `0xffed3920`.

**Changed (fixed above).**
- The uncontained override clears four PSP bits, not three: `sy` (bit 6), `co`, `ci` and `cm` (the mask is `0x401c0`).
- The log table row for msr[1715] compared it with `cpuid[3]`. The code compares `msr[1715]` bits 15:8, and separately the `cpuid[3]` family and model bytes, with bytes of the PAL_B image header (`0xffff8c90` to `0xffff8d6c`).

**Not checked.** `0xffa06370` and the section it reads, `0xffa217c0` and what it reads, the per-slice scratch word and RTC addresses in the SHub rows, the PAL_B `0xffeca570` rows other than the `cr.ipsr` and msr[1283] branch, and the msr[1640] bit meanings. What the processor latches for an empty-slot read, and whether PAL then builds the recovered state, stays **unknown**, as the page says.
