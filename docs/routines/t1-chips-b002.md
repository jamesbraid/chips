# Routine role statements, chips batch 2

Each entry below describes one routine from its rendered instruction facts: the registers it reads and writes, the calls it makes, the constants it compares against, and its branches. Names come from the binary's symbols or the function inventory. Every grade here is inferred. The facts record what the code does on the paths they cover, not what the routine is for, and where the facts leave something open the statement says so.

- `heart_intr` in `IP30/usr/cpu/sysgen/IP30boot/heart.o` at 0x1630 (n64).
  Grade: inferred.
  It reads the doubleword at 0xffffffffaff10038, ANDs it with its second argument and, while the result is nonzero, loops: it passes the masked value to `ffintr64` and uses the returned index to pick a 64-byte entry of `heart_ivec`. An index of 0x3b or more goes to `buserror_intr` at 0x171c with the first argument. For a lower index the entry's word at +0x18 decides the path. With bit 0x1000 clear, the indirect call at 0x1730 runs through the doubleword at +0x0, with the doubleword at +0x8 as its first argument. With that bit set, the path runs `valusema` on the entry's +0x20 and then `cvsema` when the result is 0x7001 or more, or `vsema` when it is lower. The loop stores 1 shifted left by the index to 0xffffffffaff10028, before the handler for indexes of 3 and above and after it for lower ones. On exit it adds the pass count less one to the word at offset 0xd0 of whatever the pointer at absolute address -0x3b78 points to, with an `ll`/`sc` loop. How the status bits at 0xffffffffaff10038 map to vectors is open.
  Reviewed: 2026-11-12

- `_get_timestamp` in `IP30/usr/cpu/sysgen/IP30boot/kernel.o` at 0x11a8 (n64).
  Grade: inferred.
  It loads a 32-bit word from 0xffffffffaff20004 with `lwu` and returns it, with no calls. The name suggests a time reading, and `__nanotime` and `_ticksper1024inst` read the same 0xaff20000 page, which fits. The facts do not show what the register counts.
  Reviewed: 2026-11-12

- `getcpuid` in `IP30/usr/cpu/sysgen/IP30boot/kernel.o` at 0x11b4 (n64).
  Grade: inferred.
  It returns the full doubleword at 0xffffffffaff50000 with no masking and makes no calls. `mlreset` passes that value as the first argument of `heart_mp_intr_init` at 0x2350 only on the path where its own first argument is nonzero; on the other path it stores the low halfword of the value to `master_procid`. The name suggests a processor number, and `VEC_dbe`, `VEC_ibe` and `_ecc_errorvec` read the same address and scale the value by 8 to index tables, but the facts do not show which bits hold a number, so the masking the callers apply is open.
  Reviewed: 2026-11-12

- `_ticksper1024inst` in `IP30/usr/cpu/sysgen/IP30boot/kernel.o` at 0x1470 (n64).
  Grade: inferred.
  It reads the doubleword at 0xffffffffaff20000 at 0x1480, runs a nested countdown with an outer count starting at 0x1ff and an inner count starting at 10 (the `bgtz` branches at 0x1488 and 0x1490), reads the doubleword again at 0x1498 and returns the second read minus the first, computed in the return delay slot. The name points to a calibration of that counter against instruction count; the facts do not show what the counter counts.
  Reviewed: 2026-11-12

- `mlreset` in `IP30/usr/cpu/sysgen/IP30boot/kernel.o` at 0x22d0 (n64).
  Grade: inferred.
  It has two paths chosen by its first argument, which it copies to `s0`. Both start by calling `r1nkperf_control_register_set` and `r1nkperf_data_register_set` for counters 0 and 1 with a value of 0, and counters 2 and 3 get the same calls when `get_cpu_irr` shifted right by 8 equals 0xe or 0xf (tests at 0x2320 and 0x2338). With a nonzero first argument it passes the return of `getcpuid` to `heart_mp_intr_init`, then calls `flush_tlb` with 1 and `flush_cache`, and returns. With a zero first argument it stores the `getcpuid` return to `master_procid`, fills the two-entry `processor_enabled` table using the doublewords at 0xffffffffaff00000 and 0xffffffffaff00080, calls `init_board_rev`, `ip30_chips_mlreset`, `init_sysid` and `load_nvram_tab`, reads the `arg_heart_invalidate_war` option through `is_specified` and `atoi`, calls `flush_cache`, initialises the `ip30clocklock` and `ip30ledlock` spin locks and scans `cpu_enabled` downwards. That option selects between a path that stores zero to three words and a path that calls `bzero` twice (the facts label the first operands `bcopy` and `bzero`), and what is cleared is open. The role as a per-processor reset path comes from the name and the call sites.
  Reviewed: 2026-11-12

- `cpu_disable` in `IP30/usr/cpu/sysgen/IP30boot/kernel.o` at 0x2884 (n64).
  Grade: inferred.
  It reads the doubleword at 0xffffffffaff00000, ORs in 1 shifted left by the argument plus 0x3c, writes it back, and stores a zero word into `processor_enabled` at the argument times four (the relocation at 0x2898 names that symbol). The name is the only evidence for "disable", and what that bit does in the register is open.
  Reviewed: 2026-11-12

- `cpu_exists` in `IP30/usr/cpu/sysgen/IP30boot/kernel.o` at 0x28b4 (n64).
  Grade: inferred.
  It loads the doubleword at 0xffffffffaff00080, ANDs it with 1 shifted left by the argument plus 4 and returns the result, so it returns that one bit in place rather than the whole word. The name suggests a presence test, and what the register holds is open.
  Reviewed: 2026-11-12

- `sendintr` in `IP30/usr/cpu/sysgen/IP30boot/kernel.o` at 0x38ac (n64).
  Grade: inferred.
  It stores a doubleword of 1 shifted left by the argument plus 0x2e to 0xffffffffaff10020 and returns 0. `debug_stop_all_cpus` writes the same register, which points to the send side of a processor-to-processor interrupt, but the facts do not show what the bit numbers address, so the target processor is not established.
  Reviewed: 2026-11-12

- `debug_stop_all_cpus` in `IP30/usr/cpu/sysgen/IP30boot/kernel.o` at 0x38c8 (n64).
  Grade: inferred.
  It loops over numbers from 0 below the global `maxcpus`. For each number that differs from the halfword at absolute address 0xffffffffffffc3a0 (-0x3c60, one address) it stores a doubleword with only bit 0x2a plus the number set to 0xffffffffaff10020, the register `sendintr` also writes. The facts show no wait after those stores, so whether the other processors actually stop is open, and the name is the only evidence for that purpose.
  Reviewed: 2026-11-12

- `__nanotime` in `IP30/usr/cpu/sysgen/IP30boot/kernel.o` at 0x5eb0 (n64).
  Grade: inferred.
  It takes `timelock` with `mutex_spinlock_spl` at the `splprof` level, increments a word in `.sbss`, and reads the doubleword at 0xffffffffaff20000. It combines that with the globals `adjtime_delta`, `adjtime_RTC`, `adjtime_nanos` and `timetrim` and with an object in `.bss` at offset 0x20 (a word at +0x20 and a doubleword at +0x28). The symbol table names nothing at that offset: `pdaindr` is the 32 bytes before it, so the earlier attribution to `pdaindr` does not hold. A loop subtracts 1,000,000,000 from the nanosecond total and adds each carry to the +0x20 word and to `time`. It releases the lock with `mutex_spinunlock` on two return paths. The rest of the arithmetic is only partly resolved, and the caller's result is open.
  Reviewed: 2026-11-12

- `flushbus` in `IP30/usr/cpu/sysgen/IP30boot/kernel.o` at 0xc044 (n64).
  Grade: inferred.
  It reads 0xffffffffaff50000 and then 0xffffffffb8000000, and returns with no call and no resolved value. The name suggests a barrier that waits for earlier uncached writes to finish. The facts show only the two reads, so that reading is an inference.
  Reviewed: 2026-11-12

- `badaddr` in `IP30/usr/cpu/sysgen/IP30boot/kernel.o` at 0xc080 (n64).
  Grade: inferred.
  It probes the address in its first argument with the size in its second. It saves CP0 register 12 and sets it to 0xa0, reads 0xffffffffb8000060, stores 0 to 0xffffffffb8000040, reads 0xffffffffb8000000 and writes the first value back, reads 0xffffffffaff10040 and writes the value back, and reads 0xffffffffaff50000. It stores 1 to the halfword at +0xf6 of the structure the pointer at absolute address -0x3fe0 points to, then loads a byte, halfword, word or doubleword from the address for a size of 1, 2, 4 or 8, and discards the value. The `cmn_err` call at 0xc144, with a first argument of 0, runs only for any other size. It then re-reads 0xaff50000 and 0xb8000000, executes `sync`, and tests bit 0x4000 of CP0 register 13 and bit 0x10000 of the word at 0xffffffffaff10040. If either is set it continues at `baerror`, which returns 1. Otherwise it clears the halfword, restores register 12 and returns 0. What the registers in the 0xb8000000 window and at 0xaff10040 are is open.
  Reviewed: 2026-11-12

- `badaddr_val` in `IP30/usr/cpu/sysgen/IP30boot/kernel.o` at 0xc1a8 (n64).
  Grade: inferred.
  It is the `badaddr` probe with a copy. It loads a byte, halfword, word or doubleword from the address in its first argument for a size of 1, 2, 4 or 8 and stores it with the same width to the address in its third argument. Any other size calls `cmn_err` at 0xc29c with a first argument of 0. It makes the same register accesses and error tests as `badaddr` and returns 0 at 0xc30c, or continues at `baerror` when either test fires. It differs in that, when the pointer at absolute address -0x3fe0 is zero, it uses the word at 0xffffffffffffc404 as the flag instead of the halfword at +0xf6 of that structure.
  Reviewed: 2026-11-12

- `wbadaddr` in `IP30/usr/cpu/sysgen/IP30boot/kernel.o` at 0xc314 (n64).
  Grade: inferred.
  It is the write probe. It sets CP0 register 12 to 0xa0, makes the same register accesses as `badaddr`, stores 1 to the halfword at +0xf6 of the structure the pointer at absolute address -0x3fe0 points to, then stores a zero to the address in its first argument with the width its second argument selects: a byte, halfword, word or doubleword for 1, 2, 4 or 8. Any other size calls `cmn_err` at 0xc3d8 with a first argument of 0. It then reads 0xffffffffaff50000 and 0xffffffffb8000000 twice with a `sync` after each pair, loads a word from 0x9000000000000000, runs the same two error tests as `badaddr` and continues at `baerror` if either fires. Otherwise it clears the halfword, restores register 12 and returns 0 at 0xc458.
  Reviewed: 2026-11-12

- `earlybadaddr` in `IP30/usr/cpu/sysgen/IP30boot/kernel.o` at 0xc5c8 (n64).
  Grade: inferred.
  It is a read probe with the same device accesses as `badaddr`. It differs in three ways. It stores 9 to the word `nofault` instead of 1 to a halfword in a structure, and stores 0 back at 0xc6e8. It probes only sizes 1, 2 and 4, loading a byte, halfword or word from its first argument and discarding it, and any other size calls `cmn_err` at 0xc688. When either error test fires it continues at 0xc7e4 rather than at `baerror`. It returns 0 at 0xc6f8. The name suggests early boot use, which the facts do not show.
  Reviewed: 2026-11-12

- `baerror` in `IP30/usr/cpu/sysgen/IP30boot/kernel.o` at 0xc788 (n64).
  Grade: inferred.
  It is the error tail the probes branch to. It reads 0xffffffffb8000060, stores 0 to 0xffffffffb8000040, reads 0xffffffffb8000000, writes the first value back to +0x60, reads 0xffffffffaff10040 and writes the value back, and reads 0xffffffffaff50000. It restores CP0 register 12 from `t4`, which the calling probe saved. It clears the halfword at +0xf6 of the structure the pointer at absolute address -0x3fe0 points to when that pointer is nonzero, and otherwise clears the word at 0xffffffffffffc404, then returns 1. What each register is for is open, and the name is the main evidence that it handles a bus error.
  Reviewed: 2026-11-12

- `_ecc_errorvec` in `IP30/usr/cpu/sysgen/IP30boot/kernel.o` at 0xdbb0 (n64).
  Grade: inferred.
  It reads 0xffffffffaff50000, scales the value by 8 and loads a pointer at that offset plus 0xff0. It stores `k0` at +0xc8 and `at` at +0x0 of what that pointer points to. It then builds the address of `ecc_exception` (the relocation at 0xdbf4 names it), masks the address to 24 bits, ORs in 0x9000000000000000 and jumps to it at 0xdc10 with its four arguments unchanged. The facts show an unresolved tail call; the relocation resolves it.
  Reviewed: 2026-11-12

- `dobuserr_common` in `IP30/usr/cpu/sysgen/IP30boot/kernel.o` at 0x13df4 (n64).
  Grade: inferred.
  It is the common bus-error handler on IP30, judged from the name and its callees. It sets a bit for its processor in `heart_error_cpumap`, with an `ll`/`sc` loop or with `compare_and_swap_int` after waiting for the low four bits to clear, calls `heart_intr` at 0x14160, and classifies the fault with `heart_paddr_to_port` and `heart_error_refine`, the latter called with several codes. It reports through `hem_add_ioe` and `hem_add_sync` and through many `cmn_err` calls, most with a first argument of 6, and `cmn_err_tag` is called at 0x14434. It calls `heart_imr_bits_rmw` and `log_dimmerr` (at 0x14e80), and clears its bit in `heart_error_cpumap` again with an `ll`/`sc` loop. The facts do not show what the bit in `heart_error_cpumap` is for or on what condition `log_dimmerr` runs. The branches are too many to decode here, so the full set of error classes is open.
  Reviewed: 2026-11-12

- `VEC_dbe` in `IP30/usr/cpu/sysgen/IP30boot/kernel.o` at 0x167e0 (n64).
  Grade: inferred.
  It is the data bus error exception vector. It reads 0xffffffffaff50000 and uses the value to index and update a table, and it reads 0xffffffffb8000000 and the halfword at 0xffffffffffffc3a0. It stores a doubleword to a0+0x140, which is probably the saved exception frame, then jumps to `VEC_trap` at 0x16830 with the same four arguments. The table layout is open.
  Reviewed: 2026-11-12

- `ecc_handler` in `IP30/usr/cpu/sysgen/IP30boot/kernel.o` at 0x17e54 (n64).
  Grade: inferred.
  It is the ECC error handler for the IP30 cache and memory. It reads and writes fields of the error record at a1 (offsets 0x0 to 0x23c), formats text with `cer_to_hex` and `sprintf`, and maps the physical address to a DIMM with `maddr_to_dimm`. It works on cache lines through `ecc_cacheOp` and `ecc_force_cache_line_invalid`, and the operation codes passed to `ecc_cacheOp` are not decoded.
  Reviewed: 2026-11-12

- `VEC_ibe` in `IP30/usr/cpu/sysgen/IP30boot/kernel.o` at 0x1bdf0 (n64).
  Grade: inferred.
  It is the instruction bus error exception vector, and its second half matches `VEC_dbe`. It starts differently: it loads doublewords from +0x118 and +0x120 of register `k1`, adds 4 to the second when the first is negative, and stores the result at +0x110. It then reads 0xffffffffaff50000 and updates the doubleword at 0xffffffffaff10000 plus 8 times that value, reads 0xffffffffb8000000, executes `sync`, reads the halfword at 0xffffffffffffc3a0 and jumps to `VEC_trap` at 0x1be58, storing that halfword at a0+0x140 in the delay slot.
  Reviewed: 2026-11-12

- `_mraccess` in `IP30/usr/cpu/sysgen/IP30boot/ksync_metered.a(sema.o)` at 0x3890 (n64).
  Grade: inferred.
  It looks like a metered access path for a kernel synchronisation object, judged from the callee names. It calls `wchanmeter` on `syncinfo`. When that call returns nonzero it first calls `mrmeter_entry` (0x3974) with the constant 5 and the doubleword at 0xffffffffaff20000 among its arguments. Every path then calls `mr_access` (0x38c0), and when the meter pointer is nonzero it follows with `mrmeter_getentry` (0x391c, constants 5 and 1). The meaning of class 5 and of the doubleword is inferred from the callee names.
  Reviewed: 2026-11-12

- `_mrupdate` in `IP30/usr/cpu/sysgen/IP30boot/ksync_metered.a(sema.o)` at 0x39cc (n64).
  Grade: inferred.
  It is the update counterpart of `_mraccess`. It calls `wchanmeter` on `syncinfo`. When that returns nonzero it first calls `mrmeter_entry` (0x3a94) with class 6, then reads the doubleword at 0xffffffffaff20000 and saves its low word. It then calls `mr_update`, and when the meter pointer is nonzero it updates fields from +0x1a0 to +0x1d8 of the meter record. Its return value is either the result of `mr_update` or an unresolved value, and the names are the main evidence for what it measures.
  Reviewed: 2026-11-12

- `mlreset` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x8738 (n32).
  Grade: inferred.
  It is the IP32 bring-up path, as far as the call sites show, and it resembles the IP30 `mlreset`. It checks the `arg_triton_invall` option with `is_enabled`, reads the CRIME revision through `get_crimerev`, and calls `flushbus`. It installs handlers with `setkgvector`, `setcrimevector` (vectors 0x1c, 0x1d, 0x15 and 0x14, the last two using `buserror_intr`) and `setmaceisavector` (vector 0x5, `powerintr`), then calls `setup_ip32_flags`, `init_sysid` and `load_nvram_tab`. The reasons for each vector are inferred from the handler names.
  Reviewed: 2026-11-12

- `ecc_handler` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0xd894 (n32).
  Grade: inferred.
  It is the ECC error handler on IP32, and it works with the R4600 secondary cache, judged from its callees. It calls `_r4600sc_disable_scache` only when `two_set_pcaches` and the word at absolute address -0x5d50 are both nonzero. It calls `_r4600sc_enable_scache` at 0xdddc only when the disable call ran and returned zero, and the path that returns at 0xd9ac does not call it. It fetches the failing address through `ecc_get_perr_addr`, logs with `ecc_log_error` and `ecc_assign_msg`, repairs with `ecc_fixmem` and `ecc_fixcache`, and schedules `ecc_cleanup` with `timeout`. The codes passed to the log calls are not decoded, so the error classes it recognises are open.
  Reviewed: 2026-11-12
