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

The runtime services `SAL_PROBE`/`sal_probe_resume_on_mca` (`rt:0x83c50`), `register_no_fault_zone_virtual` and `_physical` (`rt:0x3f70`, `0x4050`) and the `sal_event_*_mc_region` family (`rt:0x3a6e0`, `0x3a8a0`, `0x3abc0`) are the names of the machinery that lets an MCA during a protected PIO read return to the OS instead of dying. They hang off the path above: the SAL check handler consults the registered no-fault regions before choosing to hand over to OS_MCA or to resume. The decisions inside `0xffa07230` and the region walk were **not** read in this pass (**unknown**), so the exact condition that turns a read of an empty slot into "return to the probe" is open; [the probe call](../../sal/sn2-runtime.md) has the PROM-side result values (r8 = 1 and r9 = -1 when the protected read faulted).

## 5. Processor ids (cr.lid) and IPI pids

How `cr.lid`, the 16-bit processor id (the PROM calls it the pid, Linux the SAPIC id or physical id), the SAL tables and the `SH_IPI_INT` message fit together. PROM facts are from `shub1snprom.bin` 10.54 (Ghidra and objdump); Linux is `linux-history` plus the local `linux-sn2` mirror (`arch/ia64/include/asm/sn/sn_cpuid.h`, `sn_sal.h`, `shub_mmr.h`, `arch/ia64/sn/kernel/{setup.c,sn2/sn2_smp.c}`, `arch/ia64/kernel/acpi.c`).

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

**Which slices this PROM produces (established arithmetic, inferred consequence).** SAL_A takes the slice from `r33 & 3`, where `r33` is PALE_RESET's processor-id word. Every PAL_A in the image (7.31 `0xfffc4dd0`, 5.37 `0xfffcb9d0`, 1.27 `0xfffd2180`) builds it as `msr[1559]` bits 21:19 shifted left by one, so bit 0 is always 0 and the slice is 0 or 2 (one processor per front-side bus, matching SAL_B reading the agent-status register only for slices 0 and 2). `msr[1559]` bit 21 set makes `r33` bit 3 set and SAL_A spins. PAL_FIXED_ADDR (PAL_B 5.73 `0xffea1df0`) returns the same value. The PROM never makes slice 1 or 3 on SHub 1; the format and the four-slice code in SAL_B reserve them. A two-processor Altix 350 on NASID 0 is `cr.lid` `0x0000_0000` and `0x0100_0000`. What `msr[1559]` bits 21:19 hold on hardware (presumably the bus agent position): **unknown**.

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

with pid = the target's `cr.lid >> 16` as above. The NASID is not in the message: the store goes to `0x8_0000_0000 + (nasid << 38) + 0x1_1000_0380`, and `nasid` is rebuilt from the pid (`pid[6:0]`, then `pid[15:11]` shifted to `[11:7]`), by the PROM and (through `GET_SAPIC_INFO`) by Linux. The PROM's own messages use the same pid with base 0. Examples for NASID 0: IPI vector `0x12` to slice 2 is `0x8120_0000_0000_0000 | 0x0100 << 4` = `0x8120_0000_0000_1000`; the PMI message to slice 2 is `0x8010_0000_0000_1002`.

The SHub's own rule for choosing the slice from the pid, and whether it compares pid bits 15:11 and 6:0 at all after the address has chosen the node, is not in any read code: **unknown**. The inference that it uses pid bits 10:7 rests on the PROM's per-slice comparator and `SH_LOCAL_INT*_CONFIG` values, which carry the slice in the same bits ([interrupts.md](../../../devices/shub/interrupts.md#processor-id-and-message-layout-the-prom-uses)).

## Unknowns

- Per-slice register behind the boot state (`mcrz_flg`), and what a write of 1 to its field is needed to look like on hardware.
- The hook at `0xffa1f7b0` that can override the boot-processor choice.
- Processor state at `start_ap` entry (PSR, RSE).
- Whether hardware sets `cr.irr0` bit 0 for a vector-0 external interrupt (the PROM's thread park depends on it; irrelevant on a processor without threads).
- The region-walk inside `0xffa07230` and `0xffa03c60`. The PAL half of the machine-check hand-over (`PALE_CHECK` to `PAL_MC_RESUME`) is read in [pal-b-halts.md](pal-b-halts.md#pale_check-and-the-machine-check-hand-off); what an empty-slot bus error latches for PAL to call it contained is still open there.
- What the SHub does with the pid to pick a slice, and what `msr[1559]` bits 21:19 hold on hardware ([Processor ids](#5-processor-ids-crlid-and-ipi-pids)).
- `msr[1559]` bits 26:22 on hardware.

## Sources

Shipped PROM image only plus the public Linux files named at the top (`linux-history` mirror; no other URLs were opened). The SGI-held SN2 kernel-tools mirror was not opened.

## Review

Independent re-read on 2026-11-16 of commit `9265099`. PROM side: Ghidra (`--sn2-prom --sal-runtime`, full analysis) on `shub1snprom.bin` 10.54, with the inflated runtime ELF and a flat `ia64-linux-gnu-objdump` of the image as a cross-check. Ghidra's decompile is empty or a thunk for `0xffaebe90`, `0xffaebef0` and the PAL_B body at `0xffea1e60` (it does not model `ar.itc` writes or `msr` reads there), so those three were read from objdump only. Linux side: `linux-history` through the Library, and the local `linux-sn2` mirror (7.3-rc3). The quarantined SGI kernel-tools mirror was not opened.

**Confirmed.**

- Thread wake `0xffa10f40`: PAL 42, the write of 1 to `0x1_1000_0400` (`0x8000000910000400 | nasid << 38`), then per logical entry with the same core field and a nonzero thread field a store to `0x1_1000_0380` of `0x8000000000000000 | pid << 4` (type 0, vector 0). Park loop `0xffa9ac80`: returns at once for thread 0, else PAL_HALT_LIGHT (29) until `cr.irr0` bit 0. `0xffa11330` is true for thread 0. A PAL that answers -1 gives count 1 and thread 0 for everything, so nothing is sent.
- Boot-processor choice `0xffae77a0`: lowest present entry in the block A `+0x18` table (halfword pid, flags bit 0), ordered by `(pid >> 11, pid & 0x7f)` and then `(pid >> 7) & 0xf` (the slice); true when it is the caller. The IPI sender builds the same NASID from the pid fields, so "NASID then slice" is a fair reading (inferred).
- Slave loop: `0xffafd310` (fresh stack, `0xfffe`), `0xffafcdd0` (mailbox signature `0x43505543616c6c53` at `+0xd8` of the per-CPU record, boot state 1 via `0xffa03eb0`, progress 0x46, busy-poll of vectors 0x12 and 0x13); vector 0x12 clears the word at `+16`, sets state 2, progress 0x47 and calls `[rec+72]` with gp `[rec+80]` through `0xffb55c60`, which re-enters the loop if the entry returns; vector 0x13 calls `0xffb035e0` with five mailbox fields and stores the result at `+56`. The boot state is bits 51:50 of a per-slice register.
- `SAL_SET_VECTORS` slots: type 0 at `+0/8/16` (and caller state 2), type 1 at `+24..+64`, type 2 at `+72/80/88`, written for every present NASID in the table; `SET_CPU_NUMBER` stores `2n` at `+0x110`, and for n = 0 only runs `sal_event_boot_master`, which sets state 3 and clears present bit 26+slice for each other present processor whose state is not 1.
- PAL_FREQ_RATIOS: `msr[1559]` bits 26:22 = M, M from 8 to 24 gives r9 = r11 = `(M << 32) | 2` and r10 = `0x1_0000_0001`; other M gives -3; r29..r31 nonzero gives -2. PAL_FREQ_BASE gives -1 with r9..r11 = 0. SAL_FREQ_BASE: type 0 = 200,000,000 (simulator signature branch aside), type 1 = status 0 with r9 = -1, type 2 = `1e9 / ((rtc_ctl[13:4]) * 10 + 10)`. Other types give -2. Linux asks types 0 and 2 as the page says, and its fallback for a bad RTC value is 33.3 MHz.
- `ar.itc = 0` at `0xffaebea0` and `0xffaebf00`. The ITC-drift bit is bit 3 of the platform-features mask (value 8), and both linux-history and 7.3-rc3 `smp_callin` skip `ia64_sync_itc` when it is set. `init_smp_config`, `ia64_mca_init`, `sn_cpu_init` and `sn_send_IPI_phys` match the table in section 2, including the `0x12` AP wake vector in the type 5 SAL descriptor.
- MCA entry: SAL_A offset 0x20 branches to `0xffa01080`; save area `0x58000 + (slice << 13)`, 58 PAL words copied to `+8`, stack `0x18000 + (slice << 16)` with sp `+0xfff0`, `bsw.1`, `gp = 0xffd98000`, call `0xffa02ff0`; progress 0x39 in `0xffa02e00`. The 49000 minimum is as described, with the correction below.

**Changed (fixed above).**

- **The OS_MCA hand-over is a direct branch to the OS entry, not a return to PAL.** `0xffa35e10` restores state and does `br b0` with `b0 = [rec+0]`. Registers at the branch are listed in section 4 item 4; r8, r9 and r12 are graded inferred.
- **A rendezvous timeout under 49000 is registered, clamped to 49000, as well as returning -2**, and r9 is 49000 on every return. The record also holds the rendezvous vector, timeout and flags at `+0x80`, `+0x88`, `+0x90`; the earlier "12 words" count was too small.
- **PAL_LOGICAL_TO_PHYSICAL is called with proc_number 0 (count) or the entry index**, not -1.
- `cpu_reset_interval_timer` writes only `ar.itc`; `cr.itm` and `cr.itv` belong to `cpu_set_interval_timer`.
- The `0xffa02ff0` path: the rendezvous and OS hand-over are conditioned as now written; INIT is sent to processors whose state word has bits 19:18 = 2 and bit 9 clear, and what those bits mean is unknown (the earlier "not reporting" was a guess). The deadline is computed in `0xffa04220`; where it is waited on was not read.
- The "byte 8" wording for the feature descriptor now says mask byte 0x08.

**Not checked.** The A24 write of `rtc_ctl = 0x1_0000_0041` (cited from the reset page), the Linux-side `ia64_mca_init` ordering beyond the calls named, `0xffa07230` and `0xffa03c60`, the writers of `rec+112/120`, the `0xffa1f7b0` hook, `msr[1559]` on hardware, and the INIT path past its entry.
