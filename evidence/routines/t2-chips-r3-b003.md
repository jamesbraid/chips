# Tier-2 reading, batch 3 of chips: routine role statements

Each entry names a routine in the IP27 boot-set kernel object and its address. The statements come only from the rendered instruction facts: registers, loads and stores, calls and constants. Grades are inferred, because the rendered facts do not fully settle any of these roles. Where the facts leave something open, the entry says so.

- `counter_intr` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2c620
  **Inferred.** The interrupt handler for the processor's count-compare timer. It reads the count with `_get_count` (0x2c7b8), rearms it with `resetcounter` (0x2c6c4, 0x2c7a0) against a stored value compared with 0xf0000000 (0x2c780), and calls `clock` (0x2c7a8) for the tick. It also dispatches to `frs_handle_counter_intr` (0x2c648), `hwperf_overflowed_intr` (0x2c670), `l2_sbe_intr` (0x2c68c) and `hwperf_intr` (0x2c6a4) on flags read from globals, and logs through `log_tstamp_event` (0x2c834, 0x2c850). Which flag selects each dispatch, and the exact condition for the `cmn_err` warning at 0x2c8d8, are not settled by these facts.
  Reviewed: 2026-11-12

- `init_timebase` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2cae8
  **Inferred.** Sets up the boot time base from the time-of-day clock. It calls `rtodc` at 0x2caf0 with its own arguments, then spins reading the 64-bit counter at 0x9200000001030100 until it passes a base plus the constant 0x2625a0 (branches 0x2cb3c to 0x2cb84), and calls `rtodc` again at 0x2cb8c with that constant. The branch at 0x2cb98 compares the result with the global `time`, and one of its paths reports through `cmn_err` at 0x2cbb0 at level 4. The meaning of 0x2625a0 is not settled.
  Reviewed: 2026-11-12

- `tick_maint` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2cce8
  **Inferred.** A per-tick helper that counts down a counter at `sym(.sbss)+240` and returns the new value. When the decremented count is zero (branch at 0x2cd04), it calls `__nanotime` (0x2cd34), and the return on that path is `__nanotime`'s result. The call's second argument is the counter's value and the third is 1; what `__nanotime` does with them is not settled. It also tests the global `lbolt` against 1 (0x2ccf4) and a processor index at -0x3be0 (0x2cd18). The name suggests a clock refresh, which the countdown and the call together only partly bear out.
  Reviewed: 2026-11-12

- `tick_actions` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2d060
  **Inferred.** The per-clock-tick housekeeping for hardware errors and processor checks. When the byte tested at 0x2d088 is non-zero it calls `ecc_log` (0x2d090). It then calls `tlb_tick_actions` (0x2d098), and `kick_the_hub` and `hub_error_status_war` (0x2d0b0, 0x2d0c8) only when the branches at 0x2d0a8 and 0x2d0c0 do not skip them. It calls `sysctlr_check_reenable` (0x2d10c). Single-bit error polling runs through `capture_hub_stats` (0x2d364), `probe_md_errors` (0x2d37c) and `memerror_sbe_intr` (0x2d288). The path to `memerror_sbe_intr` needs `disable_sbe_polling` clear (branches 0x2d104 and 0x2d274), but the branch at 0x2d0fc also reaches `capture_hub_stats` and `probe_md_errors` without testing it. Progress checks on globals named `r10k_intervene`, `r10k_progress_nmi` and `r10k_progress_diff` report through `cmn_err` at levels 0xc (0x2d3a8) and 0xd (0x2d408).
  Reviewed: 2026-11-12

- `rtc_read` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2d45c
  **Inferred.** Returns the 64-bit value at the fixed address 0x9200000001030100 with no other work. Other routines in this object load the same address directly. Treating it as the real-time clock comes from that use, not from a register map.
  Reviewed: 2026-11-12

- `set_timer_intr` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2d4c8
  **Inferred.** Role (from name): arms the next timer interrupt for the processor index in `a0`. It reads that processor's record through `pdaindr` at `a0 << 4` and then the record's pointer at +8 (fields at offsets 0x424 and 0x520). `timepoke` is called at 0x2d564 and 0x2d594, and a call for another processor is handed to `cpuaction` with `timepoke` as the action (0x2d584, 0x2d5b0). What `timepoke` writes is not shown by these facts. It returns 0 or 1 at 0x2d550, and the meaning of each value is not settled.
  Reviewed: 2026-11-12

- `timeout_get_queuehead` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2d5c0
  **Inferred.** The name says it returns a queue head, but the body does more. It works on the per-processor timeout state reached through `pdaindr` at offsets 0x5e8, 0x5f0, 0x648 and 0x678, and on the record in `a1` (fields at +0 and +0x10). It calls `normalize_RTC_value` with the counter at 0x9200000001030100 (0x2d75c, 0x2d7cc); the two calls differ in `a7` (1 and 3), and what `a7` means to the callee is not settled. The return at 0x2d738 is the address of the per-processor field at offset 1504, not a loaded value, which is consistent with the queue-head reading only if that field is a queue head.
  Reviewed: 2026-11-12

- `chktimeout_tick` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2d804
  **Inferred.** Runs the timeout expiry check for each processor. It calls `do_chktimeout_tick` for the current processor's list (0x2d864), then walks processor numbers up to `maxcpus` (loop ending at 0x2d974), testing `cpu_enabled` (0x2d888) and calling `do_chktimeout_tick` again (0x2d8c0). A state value in `s2` is compared with 0, 1, 3 and 4 (0x2d8e4 to 0x2d8fc), selecting actions the render does not name. The return at 0x2d958 is unresolved.
  Reviewed: 2026-11-12

- `callout_time_to_hz` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2da70
  **Inferred.** From the name, it converts a callout time to a count in clock ticks. The body loads the counter at 0x9200000001030100 once and returns a value the render does not resolve (the return at 0x2da98 has `v0 = ?`). The conversion itself is not shown, so the meaning rests on the name.
  Reviewed: 2026-11-12

- `timein_body` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2daa0
  **Inferred.** The body of the timer-expiry delivery path for the object in `a0`. It takes the lock at `a0+8` (`mutex_spinlock_spl` at 0x2db40 and 0x2dc30, `mutex_spinunlock` at 0x2db1c, 0x2db80, 0x2dbc8, 0x2dc48). It claims a flag at `a0+88` with `test_and_set_int64` (0x2db30). It calls `timein_entry` with the record at `a0+24` (0x2db24) or `timein_entry_ithrd` with `a0` and that record (0x2dc04), and calls `set_timer_intr` (0x2db70) on one path chosen by the counter test at 0x2db60. It wakes waiters with `sv_broadcast` on `a0+112` (0x2dc3c). The names of the lock and the claimed flag are not settled.
  Reviewed: 2026-11-12

- `migrate_timeouts` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2dd28
  **Inferred.** Moves one processor's timeout list to another, judging by the two identifiers in `a0` and `a1`. When they are equal (branch at 0x2dd58), the routine goes straight to its return. Otherwise it calls `clock_prtimeout_nothrd` (0x2ddd4), allocates a record with `allocate_migrate_timeout` (0x2ddec), and only then locks the per-processor list at offset 1496 with `mutex_spinlock_spl` (0x2de04). It calls `add_migrated_timeout` (0x2de74) and `free_migrate_timeout` (0x2ded4), with `callout_free` (0x2de54) on one path. It returns `a0` or the free's result (0x2df04).
  Reviewed: 2026-11-12

- `__nanotime` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2e194
  **Inferred.** Computes the current time as seconds and nanoseconds from the counter at 0x9200000001030100, under `timelock` (`mutex_spinlock_spl` at 0x2e1a0, `mutex_spinunlock` at 0x2e340 and 0x2e3c0). It adds the adjustment fields `adjtime_delta` and `adjtime_RTC` (0x2e1f0), checks `adjtime_nanos` (0x2e228), and carries nanoseconds into seconds against the constant 0x3b9aca00, one billion (0x2e2b8, 0x2e2f8). It updates the stored time words reached at 0x2e318 and 0x2e3ac. The exact time base is not settled.
  Reviewed: 2026-11-12

- `nanotime_syscall` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2e3d0
  **Inferred.** The syscall-facing version of the time read. It raises the interrupt level with `splprof` (0x2e3dc) and computes the time the same way as `__nanotime`, with the adjustment fields and the constant 0x3b9aca00 (0x2e4b4 to 0x2e4e4). It takes `timelock` (0x2e508) only when the branch at 0x2e500 does not skip it, and unlocks at 0x2e528 on that path. It restores the level with `splx` (0x2e530) and returns the result of `splx`. It writes a word at the caller's buffer offset 0 (0x2e4f4) and a doubleword at offset 8 (0x2e4ec), which suggests a seconds and nanoseconds pair.
  Reviewed: 2026-11-12

- `nanotime` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2e548
  **Inferred.** Writes the current time into the caller's buffer at `a0`: a word at offset 0 (0x2e608, 0x2e638) and a doubleword at offset 8 (0x2e604, 0x2e640). It computes from the counter at 0x9200000001030100 and the constant 0x3b9aca00 (0x2e5b0, 0x2e5ec), and a branch on `sym(.sbss)+208` (0x2e54c) picks between two paths. The render shows no lock call, unlike `__nanotime`, so whether this path is safe without `timelock` is not settled.
  Reviewed: 2026-11-12

- `local_settime` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2e6cc
  **Inferred.** Sets the local time base under `timelock`: it locks with `mutex_spinlock_spl` (0x2e6e8), then carries the value in `a1` into whole seconds against the constant 0xf4240, one million (branches 0x2e704, 0x2e718, 0x2e728). It reads the counter at 0x9200000001030100 (0x2e748), stores the new base as a word and a doubleword (0x2e760, 0x2e76c), and unlocks with `mutex_spinunlock` (0x2e788), returning its value. The argument meanings are inferred from these uses.
  Reviewed: 2026-11-12

- `get_realtime_ticks` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2e828
  **Inferred.** Role (from name): returns a real-time tick count. It loads the 64-bit counter at 0x9200000001030100 (0x2e830), and the return at 0x2e848 has `v0 = ?`, so the render does not show what is returned. Whether the counter is scaled or offset before the return is not shown by these facts.
  Reviewed: 2026-11-12

- `tstoclock` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2e850
  **Inferred.** Converts a timestamp record at `a0` to a clock value. It reads a 32-bit word at offset 0 and a doubleword at offset 8 (0x2e850, 0x2e860). When `a1` equals 1 (branch at 0x2e87c), it also loads the counter at 0x9200000001030100 (0x2e890). The two returns (0x2e884, 0x2e894) yield values the render does not resolve, so the output is not settled.
  Reviewed: 2026-11-12

- `tvtoclock` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2e89c
  **Inferred.** The same shape as `tstoclock` for a different record: a 32-bit word at `a0+4` and a doubleword at `a0+8` (0x2e89c, 0x2e8ac). When `a1` equals 1 (branch at 0x2e8dc), it loads the counter at 0x9200000001030100 (0x2e8f0). The returns (0x2e8e4, 0x2e8f4) are unresolved, and whether the record is a timeval is inferred from the name.
  Reviewed: 2026-11-12

- `findcpufreq_cycles` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2e924
  **Inferred.** Measures the processor clock against the counter. It reads a flag word at 0xffffffffffffc744 at entry; when it is non-zero the routine returns at once (0x2e934) with that word. Otherwise it disables interrupts with `splhi` (0x2e93c), zeroes the cycle count with `_set_count` (0x2e954), and spins reading the counter at 0x9200000001030100 until it has advanced by 0x1312d0, which is 1,250,000 ticks (branches 0x2e974 to 0x2e9c4). It then reads the cycle count with `_get_count` (0x2e9cc), passes it to `cpu_cycles_adjust` (0x2e9d4), rewrites the flag word at 0x2e9e0 and restores the level with `splx` (0x2e9e4). The meaning of the flag word is not settled.
  Reviewed: 2026-11-12

- `early_counter_intr` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2ea34
  **Inferred.** A short early counter interrupt entry. It calls `resetcounter` (0x2ea3c) with the constant 0xfffffffff0000000 and returns that call's result (0x2ea48). The name suggests it runs before the full counter handler is installed, but nothing in this 28-byte body shows that.
  Reviewed: 2026-11-12

- `us_delay` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2ea8c
  **Inferred.** A busy-wait. It polls the counter at 0x9200000001030100 in an unrolled loop of seven loads (0x2eabc to 0x2eb20) and leaves when the counter reaches the deadline held in `a3` (branches 0x2ead0 to 0x2eb10). How `a3` is derived is not shown by these facts, so the unit it counts is not settled from them.
  Reviewed: 2026-11-12

- `hub_rtc_init` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2f378
  **Inferred.** Role (from name): initialises clock registers of one node's hub; the facts do not show what they are. It calls `get_compact_nodeid` (0x2f384) with its argument and compares the answer with `a0` (branch at 0x2f38c). On a match it writes four doublewords into a block reached through a halfword table indexed by `a0*2` (0x2f3b4 to 0x2f3c0); the facts do not name that table. It returns the compact id or 1 (0x2f3c8). What the four registers hold is not settled.
  Reviewed: 2026-11-12

- `acktmoclock` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2f3d0
  **Inferred.** Role (from name): acknowledges the timer interrupt for the current processor. It reads the processor index at -0x3be0 and takes that processor's record from `pdaindr` at index times 16. It tests a byte at offset 0x520 of the structure at the record's +8 (branch at 0x2f3ec). Each path stores one doubleword: one at 0x2f404 when the byte is clear and the other at 0x2f3f4 when it is set. The facts do not show the target addresses. The return is index times 16, and the meaning of the stores is inferred from the name.
  Reviewed: 2026-11-12

- `ackkgclock` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2f408
  **Inferred.** Role (from name): the same shape as `acktmoclock` for the profiling clock. It reads the same processor index and per-processor record and tests the same byte at offset 0x520 (branch at 0x2f424). Each path stores one doubleword, at 0x2f43c when the byte is clear and at 0x2f42c when it is set. The facts do not show the target addresses. The name suggests acknowledging a profiling tick, which only the name supports.
  Reviewed: 2026-11-12

- `startkgclock` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2f440
  **Inferred.** Role (from name): starts the profiling clock, under the lock at `sym(.sbss)+288` (`mutex_spinlock_spl` at 0x2f44c, `mutex_spinunlock` at 0x2f50c and 0x2f548). On the path that does not skip it (branch at 0x2f4bc) it picks a processor with `cnodetocpu` (0x2f4c4), and it stores doublewords at 0x2f4b0 and 0x2f528 (the facts do not show the target addresses). It installs `prof_intr` with `setkgvector` (0x2f52c) when the global at `sdata+392` is zero (branch at 0x2f45c). The constant 0x4e2 appears in the compare at 0x2f470 and as an argument at the unlock at 0x2f548; these facts do not explain it.
  Reviewed: 2026-11-12
