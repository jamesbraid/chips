# Tier-2 reading, batch 3 of chips: routine role statements

Each entry names a routine in the IP27 boot-set kernel object and its address. The statements come only from the rendered instruction facts: registers, loads and stores, calls and constants. Grades are inferred, because the rendered facts do not fully settle any of these roles. Where the facts leave something open, the entry says so.

- `counter_intr` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2c620
  **Inferred.** The interrupt handler for the processor's count-compare timer. It reads the count with `_get_count` (0x2c7b8), rearms it with `resetcounter` (0x2c6c4, 0x2c7a0) against a stored value compared with 0xf0000000 (0x2c780), and calls `clock` (0x2c7a8) for the tick. It also dispatches to `frs_handle_counter_intr` (0x2c648), `hwperf_overflowed_intr` (0x2c670), `l2_sbe_intr` (0x2c68c) and `hwperf_intr` (0x2c6a4) on flags read from globals, and logs through `log_tstamp_event` (0x2c834, 0x2c850). Which flag selects each dispatch, and the exact condition for the `cmn_err` warning at 0x2c8d8, are not settled by these facts.

- `init_timebase` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2cae8
  **Inferred.** Sets up the boot time base from the time-of-day clock. It calls `rtodc` at 0x2caf0 with its own arguments, then spins reading the 64-bit counter at 0x9200000001030100 until it passes a base plus the constant 0x2625a0 (branches 0x2cb3c to 0x2cb84), and calls `rtodc` again at 0x2cb8c with that constant. The branch at 0x2cb98 compares the result with the global `time`, and one of its paths reports through `cmn_err` at 0x2cbb0 at level 4. The meaning of 0x2625a0 is not settled.

- `tick_maint` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2cce8
  **Inferred.** A per-tick helper that counts down a counter at `sym(.sbss)+240` and returns the new value. When the decremented count is zero (branch at 0x2cd04), it calls `__nanotime` (0x2cd34) on that counter's storage, and the return is then `__nanotime`'s result. It also tests the global `lbolt` against 1 (0x2ccf4) and a processor index at -0x3be0 (0x2cd18). The name suggests a clock refresh, which the countdown and the call together only partly bear out.

- `tick_actions` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2d060
  **Inferred.** The per-clock-tick housekeeping for hardware errors and processor checks. It calls `ecc_log` (0x2d090), `tlb_tick_actions` (0x2d098), `kick_the_hub` and `hub_error_status_war` (0x2d0b0, 0x2d0c8), and `sysctlr_check_reenable` (0x2d10c). Single-bit error polling runs through `capture_hub_stats` (0x2d364), `probe_md_errors` (0x2d37c) and `memerror_sbe_intr` (0x2d288), and only when `disable_sbe_polling` is clear (branches 0x2d104 and 0x2d274). Progress checks on globals named `r10k_intervene`, `r10k_progress_nmi` and `r10k_progress_diff` report through `cmn_err` at levels 0xc (0x2d3a8) and 0xd (0x2d408).

- `rtc_read` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2d45c
  **Inferred.** Returns the 64-bit value at the fixed address 0x9200000001030100 with no other work. Other routines in this object load the same address directly. Treating it as the real-time clock comes from that use, not from a register map.

- `set_timer_intr` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2d4c8
  **Inferred.** Arms the next timer interrupt for the processor index in `a0`. It reads that processor's record through `pdaindr` at `a0 << 4` and then the record's pointer at +8 (fields at offsets 0x424 and 0x520). The write to the hub registers goes through `timepoke` (0x2d564, 0x2d594), and a write for another processor is handed to `cpuaction` with `timepoke` as the action (0x2d584, 0x2d5b0). It returns 0 or 1 at 0x2d550, and the meaning of each value is not settled.

- `timeout_get_queuehead` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2d5c0
  **Inferred.** The name says it returns a queue head, but the body does more. It works on the per-processor timeout state reached through `pdaindr` at offsets 0x5e8, 0x5f0, 0x648 and 0x678, and on the record in `a1` (fields at +0 and +0x10). It converts the counter at 0x9200000001030100 with `normalize_RTC_value` (0x2d75c, 0x2d7cc), once with each of two flag arguments. The return at 0x2d738 is a load from per-processor offset 1504, so the queue-head reading is only partly supported.

- `chktimeout_tick` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2d804
  **Inferred.** Runs the timeout expiry check for each processor. It calls `do_chktimeout_tick` for the current processor's list (0x2d864), then walks processor numbers up to `maxcpus` (loop ending at 0x2d974), testing `cpu_enabled` (0x2d888) and calling `do_chktimeout_tick` again (0x2d8c0). A state value in `s2` is compared with 0, 1, 3 and 4 (0x2d8e4 to 0x2d8fc), selecting actions the render does not name. The return at 0x2d958 is unresolved.

- `callout_time_to_hz` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2da70
  **Inferred.** From the name, it converts a callout time to a count in clock ticks. The body loads the counter at 0x9200000001030100 once and returns a value the render does not resolve (the return at 0x2da98 has `v0 = ?`). The conversion itself is not shown, so the meaning rests on the name.

- `timein_body` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2daa0
  **Inferred.** The body of the timer-expiry delivery path for the object in `a0`. It takes the lock at `a0+8` (`mutex_spinlock_spl` at 0x2db40 and 0x2dc30, `mutex_spinunlock` at 0x2db1c, 0x2db80, 0x2dbc8, 0x2dc48). It claims a flag at `a0+88` with `test_and_set_int64` (0x2db30), calls `timein_entry` (0x2db24) or `timein_entry_ithrd` (0x2dc04) on the record at `a0+24`, and calls `set_timer_intr` (0x2db70) on one path chosen by the counter test at 0x2db60. It wakes waiters with `sv_broadcast` on `a0+112` (0x2dc3c). The names of the lock and the claimed flag are not settled.

- `migrate_timeouts` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2dd28
  **Inferred.** Moves one processor's timeout list to another, judging by the two identifiers in `a0` and `a1`. When they are equal (branch at 0x2dd58), the routine goes straight to its return. Otherwise it locks the per-processor list at offset 1496, allocates a record with `allocate_migrate_timeout` (0x2ddec), and calls `clock_prtimeout_nothrd` (0x2ddd4), `add_migrated_timeout` (0x2de74) and `free_migrate_timeout` (0x2ded4), with `callout_free` (0x2de54) on one path. It returns `a0` or the free's result (0x2df04).

- `__nanotime` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2e194
  **Inferred.** Computes the current time as seconds and nanoseconds from the counter at 0x9200000001030100, under `timelock` (`mutex_spinlock_spl` at 0x2e1a0, `mutex_spinunlock` at 0x2e340 and 0x2e3c0). It adds the adjustment fields `adjtime_delta` and `adjtime_RTC` (0x2e1f0), checks `adjtime_nanos` (0x2e228), and carries nanoseconds into seconds against the constant 0x3b9aca00, one billion (0x2e2b8, 0x2e2f8). It updates the stored time words reached at 0x2e318 and 0x2e3ac. The exact time base is not settled.

- `nanotime_syscall` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2e3d0
  **Inferred.** The syscall-facing version of the time read. It raises the interrupt level with `splprof` (0x2e3dc), takes `timelock` (0x2e508), and computes the time the same way as `__nanotime`, with the adjustment fields and the constant 0x3b9aca00 (0x2e4b4 to 0x2e4e4). It then unlocks, restores the level with `splx` (0x2e530), and returns its result. It writes a word at the caller's buffer offset 0 (0x2e4f4) and a doubleword at offset 8 (0x2e4ec), which suggests a seconds and nanoseconds pair.

- `nanotime` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2e548
  **Inferred.** Writes the current time into the caller's buffer at `a0`: a word at offset 0 (0x2e608, 0x2e638) and a doubleword at offset 8 (0x2e604, 0x2e640). It computes from the counter at 0x9200000001030100 and the constant 0x3b9aca00 (0x2e5b0, 0x2e5ec), and a branch on `sym(.sbss)+208` (0x2e54c) picks between two paths. The render shows no lock call, unlike `__nanotime`, so whether this path is safe without `timelock` is not settled.

- `local_settime` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2e6cc
  **Inferred.** Sets the local time base under `timelock`: it locks with `mutex_spinlock_spl` (0x2e6e8), then carries the value in `a1` into whole seconds against the constant 0xf4240, one million (branches 0x2e704, 0x2e718, 0x2e728). It reads the counter at 0x9200000001030100 (0x2e748), stores the new base as a word and a doubleword (0x2e760, 0x2e76c), and unlocks with `mutex_spinunlock` (0x2e788), returning its value. The argument meanings are inferred from these uses.

- `get_realtime_ticks` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2e828
  **Inferred.** Returns the raw 64-bit counter at 0x9200000001030100 as the real-time tick count. The body is one load and a return, with no scaling, so any conversion is left to callers. The render does not show the register copy into `v0`, so the reading rests on the load and the name.

- `tstoclock` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2e850
  **Inferred.** Converts a timestamp record at `a0` to a clock value. It reads a 32-bit word at offset 0 and a doubleword at offset 8 (0x2e850, 0x2e860). When `a1` equals 1 (branch at 0x2e87c), it also loads the counter at 0x9200000001030100 (0x2e890). The two returns (0x2e884, 0x2e894) yield values the render does not resolve, so the output is not settled.

- `tvtoclock` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2e89c
  **Inferred.** The same shape as `tstoclock` for a different record: a 32-bit word at `a0+4` and a doubleword at `a0+8` (0x2e89c, 0x2e8ac). When `a1` equals 1 (branch at 0x2e8dc), it loads the counter at 0x9200000001030100 (0x2e8f0). The returns (0x2e8e4, 0x2e8f4) are unresolved, and whether the record is a timeval is inferred from the name.

- `findcpufreq_cycles` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2e924
  **Inferred.** Measures the processor clock against the counter. It disables interrupts with `splhi` (0x2e93c), zeroes the cycle count with `_set_count` (0x2e954), and spins reading the counter at 0x9200000001030100 until it has advanced by 0x1312d0, which is 1,250,000 ticks (branches 0x2e974 to 0x2e9c4). It then reads the cycle count with `_get_count` (0x2e9cc), passes it to `cpu_cycles_adjust` (0x2e9d4), and restores the level with `splx` (0x2e9e4). The flag word at 0xffffffffffffc744 is read at entry and rewritten at 0x2e9e0; its meaning is not settled.

- `early_counter_intr` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2ea34
  **Inferred.** A short early counter interrupt entry. It calls `resetcounter` (0x2ea3c) with the constant 0xfffffffff0000000 and returns that call's result (0x2ea48). The name suggests it runs before the full counter handler is installed, but nothing in this 28-byte body shows that.

- `us_delay` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2ea8c
  **Inferred.** A busy-wait for a caller-given interval. It polls the counter at 0x9200000001030100 in an unrolled loop of seven loads (0x2eabc to 0x2eb20) and leaves when the counter reaches the deadline held in `a3` (branches 0x2ead0 to 0x2eb10). The caller computes that deadline, so the unit `a3` counts is not settled from this routine.

- `hub_rtc_init` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2f378
  **Inferred.** Initialises the hub clock registers for one node. It calls `get_compact_nodeid` (0x2f384) with its argument and compares the answer with `a0` (branch at 0x2f38c). On a match it writes four doublewords into that node's hub register block (0x2f3b4 to 0x2f3c0), with the base found through `compact_to_nasid_node` at index `a0*2`. It returns the compact id or 1 (0x2f3c8). What the four registers hold is not settled.

- `acktmoclock` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2f3d0
  **Inferred.** Acknowledges the timer interrupt for the current processor. It reads the processor index at -0x3be0 and takes that processor's record from `pdaindr` at index times 16. If a byte at offset 0x520 of the structure at the record's +8 is clear (branch at 0x2f3ec), it writes two doublewords to 0x9200000001000128 and 0x9200000001000120 (0x2f3f4, 0x2f404). The return is index times 16, and the meaning of the two registers is inferred from the name.

- `ackkgclock` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2f408
  **Inferred.** The same shape as `acktmoclock` for the profiling clock. It reads the same processor index and per-processor record, tests the same byte at offset 0x520 (branch at 0x2f424), and writes two doublewords to 0x9200000001000130 and 0x9200000001000138 (0x2f42c, 0x2f43c). The name suggests acknowledging a profiling tick, which only the name supports.

- `startkgclock` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2f440
  **Inferred.** Starts the profiling clock, under the lock at `sym(.sbss)+288` (`mutex_spinlock_spl` at 0x2f44c, `mutex_spinunlock` at 0x2f50c and 0x2f548). It picks the target processor with `cnodetocpu` (0x2f4c4), writes two doublewords at 0x9200000001000150 and 0x9200000001000158 (0x2f4b0, 0x2f528), and installs `prof_intr` with `setkgvector` (0x2f52c) when the global at `sdata+392` is zero (branch at 0x2f45c). The constant 0x4e2 in the compare at 0x2f470 and in the call at 0x2f4c4 is not explained by these facts.
