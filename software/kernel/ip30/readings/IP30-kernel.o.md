# Readings: `IP30/usr/cpu/sysgen/IP30boot/kernel.o`

One entry per routine, filed here from the reading batches by binary.

- `dummy_func` in `IP30/usr/cpu/sysgen/IP30boot/kernel.o` at 0x1180 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/kernel.o`.
  Range: 0x1180-0x1188 (8 bytes).
  It occupies 8 bytes.
  The return at 0x1180 has v0 = ?.

- `dummyret0_func` in `IP30/usr/cpu/sysgen/IP30boot/kernel.o` at 0x11a0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/kernel.o`.
  Range: 0x11a0-0x11a8 (8 bytes).
  It occupies 8 bytes.
  The return at 0x11a0 has v0 = 0x0.

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

- `heart_intr_low` in `IP30/usr/cpu/sysgen/IP30boot/kernel.o` at 0x14fc (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/kernel.o`.
  Range: 0x14fc-0x152c (48 bytes).
  It occupies 48 bytes.
  Calls heart_intr via direct with a0=a0 at entry (arg0), a1=0xffff, a2=a2 at entry (arg2), a3=a3 at entry (arg3) (`j` at 0x14fc).
  The instructions from 0x1504 to 0x1528 are not reached by any path from the entry, and their branches are not listed.

- `heart_intr_med` in `IP30/usr/cpu/sysgen/IP30boot/kernel.o` at 0x1504 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/kernel.o`.
  Range: 0x1504-0x1510 (12 bytes).
  It occupies 12 bytes.
  Calls heart_intr via direct with a0=a0 at entry (arg0), a1=0xffff0000, a2=a2 at entry (arg2), a3=a3 at entry (arg3) (`j` at 0x1508).

- `heart_intr_hi` in `IP30/usr/cpu/sysgen/IP30boot/kernel.o` at 0x1510 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/kernel.o`.
  Range: 0x1510-0x1520 (16 bytes).
  It occupies 16 bytes.
  Calls heart_intr via direct with a0=a0 at entry (arg0), a1=0x3ffff00000000, a2=a2 at entry (arg2), a3=a3 at entry (arg3) (`j` at 0x1518).

- `heart_intr_err` in `IP30/usr/cpu/sysgen/IP30boot/kernel.o` at 0x1520 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/kernel.o`.
  Range: 0x1520-0x152c (12 bytes).
  It occupies 12 bytes.
  Calls heart_intr via direct with a0=a0 at entry (arg0), a1=0xfff8000000000000, a2=a2 at entry (arg2), a3=a3 at entry (arg3) (`j` at 0x1524).

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

- `early_nic_access_mcr32` in `IP30/usr/cpu/sysgen/IP30boot/kernel.o` at 0x2f50 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/kernel.o`.
  Range: 0x2f50-0x3050 (256 bytes).
  It occupies 256 bytes.
  The `sw` at 0x2f6c stores 4 bytes to a0 (arg0 at entry) +0x0.
  5 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x0, including `lw` at 0x2f70, `lw` at 0x2f80, `lw` at 0x2f90.
  7 such `ld` accesses load 8 bytes from abs 0xffffffffaff20000, including `ld` at 0x2fd8, `ld` at 0x2fdc, `ld` at 0x2ff8.
  The `bne` branch at 0x2f78 targets 0x2fc0, is taken when (a4(=[a0]) & 0x2) != 0, and falls through when (a4(=[a0]) & 0x2) == 0.
  The `bne` branch at 0x2f88 targets 0x2fc0, is taken when (a4(=[a0]) & 0x2) != 0, and falls through when (a4(=[a0]) & 0x2) == 0.
  The `bne` branch at 0x2f98 targets 0x2fc0, is taken when (a4(=[a0]) & 0x2) != 0, and falls through when (a4(=[a0]) & 0x2) == 0.
  The `bne` branch at 0x2fa8 targets 0x2fc0, is taken when (a4(=[a0]) & 0x2) != 0, and falls through when (a4(=[a0]) & 0x2) == 0.
  The `beq` branch at 0x2fb8 targets 0x2f70, is taken when (a4(=[a0]) & 0x2) == 0, and falls through when (a4(=[a0]) & 0x2) != 0.
  The `beq` branch at 0x2ff0 targets 0x3048, is taken when t8(=[0xffffffffaff20000]:8) >= a0(?) (unsigned), and falls through when t8(=[0xffffffffaff20000]:8) < a0(?) (unsigned).
  The `beq` branch at 0x3000 targets 0x3048, is taken when a3(=[0xffffffffaff20000]:8) >= a0(?) (unsigned), and falls through when a3(=[0xffffffffaff20000]:8) < a0(?) (unsigned).
  The `beq` branch at 0x3010 targets 0x3048, is taken when a6(=[0xffffffffaff20000]:8) >= a0(?) (unsigned), and falls through when a6(=[0xffffffffaff20000]:8) < a0(?) (unsigned).
  The `beq` branch at 0x3020 targets 0x3048, is taken when a7(=[0xffffffffaff20000]:8) >= a0(?) (unsigned), and falls through when a7(=[0xffffffffaff20000]:8) < a0(?) (unsigned).
  The `beq` branch at 0x3030 targets 0x3048, is taken when t0(=[0xffffffffaff20000]:8) >= a0(?) (unsigned), and falls through when t0(=[0xffffffffaff20000]:8) < a0(?) (unsigned).
  The `bne` branch at 0x3040 targets 0x2ff8, is taken when t1(=[0xffffffffaff20000]:8) < a0(?) (unsigned), and falls through when t1(=[0xffffffffaff20000]:8) >= a0(?) (unsigned).
  The return at 0x3048 has v0 = ?.

- `sendintr` in `IP30/usr/cpu/sysgen/IP30boot/kernel.o` at 0x38ac (n64).
  Grade: inferred.
  It stores a doubleword of 1 shifted left by the argument plus 0x2e to 0xffffffffaff10020 and returns 0. `debug_stop_all_cpus` writes the same register, which points to the send side of a processor-to-processor interrupt, but the facts do not show what the bit numbers address, so the target processor is not established.
  Reviewed: 2026-11-12

- `debug_stop_all_cpus` in `IP30/usr/cpu/sysgen/IP30boot/kernel.o` at 0x38c8 (n64).
  Grade: inferred.
  It loops over numbers from 0 below the global `maxcpus`. For each number that differs from the halfword at absolute address 0xffffffffffffc3a0 (-0x3c60, one address) it stores a doubleword with only bit 0x2a plus the number set to 0xffffffffaff10020, the register `sendintr` also writes. The facts show no wait after those stores, so whether the other processors actually stop is open, and the name is the only evidence for that purpose.
  Reviewed: 2026-11-12

- `intr_spray_heuristic` in `IP30/usr/cpu/sysgen/IP30boot/kernel.o` at 0x3cd0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/kernel.o`.
  Range: 0x3cd0-0x3d90 (192 bytes).
  It occupies 192 bytes.
  The `ld` at 0x3d4c loads 8 bytes from table(sym(pdaindr)) +0x8.
  The `lw` at 0x3d50 loads 4 bytes from [table(sym(pdaindr))+8]:8 +0x48.
  The `lw` at 0x3d74 loads 4 bytes from table(sym(.sdata)+80) +0x0.
  The `sw` at 0x3d8c stores 4 bytes to table(sym(.sdata)+80) +0x0.
  The `jal` at 0x3ce0 calls device_desc_intr_target_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x3cf4 calls cpuvertex_to_cpuid with a0=ret(device_desc_intr_target_get), a1=[sym(.sdata)+80], a2=?, a3=?.
  The `jal` at 0x3d04 calls cpu_enabled with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x3d34 calls cpu_enabled with a0=?, a1=[sym(.sdata)+80], a2=?, a3=?.
  The `beq` branch at 0x3cd8 targets 0x3d28, is taken when a0 == 0, and falls through when a0 != 0.
  The `beq` branch at 0x3cec targets 0x3d2c, is taken when v0(=ret(device_desc_intr_target_get)) == at(=-0x1), and falls through when v0(=ret(device_desc_intr_target_get)) != at(=-0x1).
  The `beq` branch at 0x3d20 targets 0x3d64 and is always taken.
  The `beq` branch at 0x3d3c targets 0x3d60, is taken when v0(=ret(cpu_enabled)) == 0, and falls through when v0(=ret(cpu_enabled)) != 0.
  The `beq` branch at 0x3d58 targets 0x3d68, is taken when (a2(=[[table(sym(pdaindr))+8]:8+72]) & 0x80) == 0, and falls through when (a2(=[[table(sym(pdaindr))+8]:8+72]) & 0x80) != 0.
  The return at 0x3d88 has v0 = ?.

- `heart_set_cpu_intr` in `IP30/usr/cpu/sysgen/IP30boot/kernel.o` at 0x3d90 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/kernel.o`.
  Range: 0x3d90-0x3da4 (20 bytes).
  It occupies 20 bytes.
  The `sd` at 0x3da0 stores 8 bytes to abs 0xffffffffaff10020.
  The return at 0x3d9c has v0 = 0xffffffffaff10000.

- `heart_invalidate_war` in `IP30/usr/cpu/sysgen/IP30boot/kernel.o` at 0x3f24 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/kernel.o`.
  Range: 0x3f24-0x3fb8 (148 bytes).
  It occupies 148 bytes.
  2 such `ld` accesses load 8 bytes from abs 0xffffffffffffc020, including `ld` at 0x3f34, `ld` at 0x3f6c.
  2 such `lbu` accesses load 1 byte from abs 0xffffffffffffc04f, including `lbu` at 0x3f48, `lbu` at 0x3f78.
  The `jal` at 0x3f54 calls splhi with a0=0x2, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x3f64 calls __heart_invalidate_war with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0x3f84 calls splx with a0=?, a1=[-0x3fe0]:8, a2=?, a3=0x2.
  The `jal` at 0x3f98 calls rt_unpin_thread with a0=?, a1=[-0x3fe0]:8, a2=[-0x3fb1]:1, a3=0x2.
  The `jal` at 0x3fa8 calls rt_pin_thread with a0=0x2, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0x3f2c targets 0x3f8c, is taken when at(=[sym(_heart_invalidate_war)]) == 0, and falls through when at(=[sym(_heart_invalidate_war)]) != 0.
  The `beq` branch at 0x3f40 targets 0x3f54, is taken when v0(=[-0x3fe0]:8) == 0, and falls through when v0(=[-0x3fe0]:8) != 0.
  The `beq` branch at 0x3f4c targets 0x3fa8, is taken when v1(=[-0x3fb1]:1) == a0(=0x2), and falls through when v1(=[-0x3fb1]:1) != a0(=0x2).
  The `beq` branch at 0x3f70 targets 0x3f84, is taken when a1(=[-0x3fe0]:8) == 0, and falls through when a1(=[-0x3fe0]:8) != 0.
  The `beq` branch at 0x3f7c targets 0x3f98, is taken when a2(=[-0x3fb1]:1) == a3(=0x2), and falls through when a2(=[-0x3fb1]:1) != a3(=0x2).
  The `beq` branch at 0x3fa0 targets 0x3f90 and is always taken.
  The `beq` branch at 0x3fb0 targets 0x3f60 and is always taken.
  The return at 0x3f90 has v0 = one of ?, ret(rt_unpin_thread).

- `__nanotime` in `IP30/usr/cpu/sysgen/IP30boot/kernel.o` at 0x5eb0 (n64).
  Grade: inferred.
  It takes `timelock` with `mutex_spinlock_spl` at the `splprof` level, increments a word in `.sbss`, and reads the doubleword at 0xffffffffaff20000. It combines that with the globals `adjtime_delta`, `adjtime_RTC`, `adjtime_nanos` and `timetrim` and with an object in `.bss` at offset 0x20 (a word at +0x20 and a doubleword at +0x28). The symbol table names nothing at that offset: `pdaindr` is the 32 bytes before it, so the earlier attribution to `pdaindr` does not hold. A loop subtracts 1,000,000,000 from the nanosecond total and adds each carry to the +0x20 word and to `time`. It releases the lock with `mutex_spinunlock` on two return paths. The rest of the arithmetic is only partly resolved, and the caller's result is open.
  Reviewed: 2026-11-12

- `heartclock_intr` in `IP30/usr/cpu/sysgen/IP30boot/kernel.o` at 0x80bc (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/kernel.o`.
  Range: 0x80bc-0x80d0 (20 bytes).
  It occupies 20 bytes.
  The `sd` at 0x80cc stores 8 bytes to abs 0xffffffffaff10028.
  The return at 0x80c8 has v0 = 0xffffffffaff10000.

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
