# Routine role statements, chips batch 2

Each entry below describes one routine from its rendered instruction facts: the registers it reads and writes, the calls it makes, the constants it compares against, and its branches. Names come from the binary's symbols or the function inventory. Every grade here is inferred. The facts record what the code does on the paths they cover, not what the routine is for, and where the facts leave something open the statement says so.

- `heart_intr` in `IP30/usr/cpu/sysgen/IP30boot/heart.o` at 0x1630 (n64).
  Grade: inferred.
  It takes the first pending HEART interrupt index from `ffintr64` and uses it to index a 64-byte table, `heart_ivec`. Indexes at or above 0x3b branch to `buserror_intr` at 0x171c, and the others make an indirect call at 0x1730. It works the entry's semaphore with `cvsema`, `valusema` and `vsema`, and a `ll`/`sc` pair at 0x1774 updates a word near -0x3b78. How the status bits at 0xffffffffaff10038 map to vectors is open.

- `_get_timestamp` in `IP30/usr/cpu/sysgen/IP30boot/kernel.o` at 0x11a8 (n64).
  Grade: inferred.
  It loads a 32-bit word from 0xffffffffaff20004 with `lwu` and returns it, with no calls. The name suggests a time reading, and `__nanotime` and `_ticksper1024inst` read the same 0xaff20000 page, which fits. The facts do not show what the register counts.

- `getcpuid` in `IP30/usr/cpu/sysgen/IP30boot/kernel.o` at 0x11b4 (n64).
  Grade: inferred.
  It returns the full doubleword at 0xffffffffaff50000 with no masking. `mlreset` passes that value to `heart_mp_intr_init` at 0x2350 as a processor number. The bits that hold the number are not shown, so the caller's masking is open.

- `_ticksper1024inst` in `IP30/usr/cpu/sysgen/IP30boot/kernel.o` at 0x1470 (n64).
  Grade: inferred.
  It reads the doubleword at 0xffffffffaff20000 at 0x1480 and 0x1498, and runs two signed loops controlled by `bgtz` at 0x1488 and 0x1490. The name points to a calibration of that counter against instructions. The loop bounds and the return value are not resolved, so the role is partly open.

- `mlreset` in `IP30/usr/cpu/sysgen/IP30boot/kernel.o` at 0x22d0 (n64).
  Grade: inferred.
  It is the per-processor reset path for IP30, as far as the call sites show. It programs performance counters 0 to 3 through `r1nkperf_control_register_set` and `r1nkperf_data_register_set`, takes its processor number from `getcpuid`, and calls `heart_mp_intr_init`. It then flushes the TLB and cache, runs board setup (`init_board_rev`, `ip30_chips_mlreset`, `init_sysid`, `load_nvram_tab`), and initialises the `ip30clocklock` and `ip30ledlock` spin locks. The `arg_heart_invalidate_war` option, read through `is_specified` and `atoi`, appears to enable a workaround loop, and the purpose of the `bzero` calls near the `bcopy` symbol is open.

- `cpu_disable` in `IP30/usr/cpu/sysgen/IP30boot/kernel.o` at 0x2884 (n64).
  Grade: inferred.
  It reads the doubleword at 0xffffffffaff00000, writes a modified value back to it, and stores a word into `processor_enabled` at the argument times four. The sequence reads like a disable, but the bit it changes is not decoded. The name is the only evidence for "disable".

- `cpu_exists` in `IP30/usr/cpu/sysgen/IP30boot/kernel.o` at 0x28b4 (n64).
  Grade: inferred.
  It loads the doubleword at 0xffffffffaff00080 and returns it. The name suggests a presence test, but whether the caller reads one bit or the whole word is open.

- `sendintr` in `IP30/usr/cpu/sysgen/IP30boot/kernel.o` at 0x38ac (n64).
  Grade: inferred.
  It stores a doubleword to 0xffffffffaff10020 and returns 0. `debug_stop_all_cpus` writes the same register, which points to the send side of a processor-to-processor interrupt. The stored value is not decoded, so the target processor is not established.

- `debug_stop_all_cpus` in `IP30/usr/cpu/sysgen/IP30boot/kernel.o` at 0x38c8 (n64).
  Grade: inferred.
  It loops over processor numbers below the global `maxcpus`, comparing each with halfwords at -0x3c60 and 0xffffffffffffc3a0. For the processors that pass, it writes a doubleword to 0xffffffffaff10020, the register `sendintr` also writes. The facts show no wait after those stores, so whether the other processors actually stop is open.

- `__nanotime` in `IP30/usr/cpu/sysgen/IP30boot/kernel.o` at 0x5eb0 (n64).
  Grade: inferred.
  It takes `timelock` with `mutex_spinlock_spl` at the `splprof` level and reads the counter at 0xffffffffaff20000. It combines that with the per-processor area `pdaindr` (fields at +0x20 and +0x28) and the adjustment globals `adjtime_delta`, `adjtime_RTC` and `adjtime_nanos`, then releases the lock with `mutex_spinunlock` on two return paths. The nanosecond arithmetic is only partly resolved, and the caller's result is open.

- `flushbus` in `IP30/usr/cpu/sysgen/IP30boot/kernel.o` at 0xc044 (n64).
  Grade: inferred.
  It reads 0xffffffffaff50000 and then 0xffffffffb8000000, and returns with no call and no resolved value. The name suggests a barrier that waits for earlier uncached writes to finish. The facts show only the two reads, so that reading is an inference.

- `badaddr` in `IP30/usr/cpu/sysgen/IP30boot/kernel.o` at 0xc080 (n64).
  Grade: inferred.
  It probes an address and reports a failure through `cmn_err` at 0xc144, called with a zero first argument. It touches the 0xffffffffb8000000 window, the HEART CAUSE register at 0xffffffffaff10040, and the 0xaff50000 word, and returns 0 on the path the facts show. The probed access and its width are not fully resolved.

- `badaddr_val` in `IP30/usr/cpu/sysgen/IP30boot/kernel.o` at 0xc1a8 (n64).
  Grade: inferred.
  It is a sized copy version of the bad-address probe. It loads a byte, halfword, word and doubleword from the address in a0 and stores each to the address in a2 (0xc210 to 0xc278), with the same register accesses as `badaddr`. It reports through `cmn_err` at 0xc29c and returns 0 on the success path, and the facts do not show which copy runs for a given size.

- `wbadaddr` in `IP30/usr/cpu/sysgen/IP30boot/kernel.o` at 0xc314 (n64).
  Grade: inferred.
  It is the write probe. It stores a byte, halfword, word and doubleword to the address in a0 (0xc36c to 0xc3b4), then runs the same register checks as `badaddr`. It reports through `cmn_err` at 0xc3d8 and returns 0, and the width it tests is read from the stores rather than a call table.

- `earlybadaddr` in `IP30/usr/cpu/sysgen/IP30boot/kernel.o` at 0xc5c8 (n64).
  Grade: inferred.
  It is a bad-address probe with the same register window accesses as the others. It reports through `cmn_err` at 0xc688 and returns 0 at 0xc6f8. The name suggests early boot use, and the facts do not show what separates it from `badaddr`.

- `baerror` in `IP30/usr/cpu/sysgen/IP30boot/kernel.o` at 0xc788 (n64).
  Grade: inferred.
  It reads and rewrites the word at 0xffffffffaff10040 and copies values through 0xffffffffb8000040 and 0xffffffffb8000060. It also writes a halfword at [-0x3fe0]+0xf6 and a word at 0xffffffffffffc404 when a value read earlier is nonzero, and it returns 1. The role of each register is not established here, and the name is the main evidence that it handles a bus error.

- `_ecc_errorvec` in `IP30/usr/cpu/sysgen/IP30boot/kernel.o` at 0xdbb0 (n64).
  Grade: inferred.
  It reads 0xffffffffaff50000 and uses the value, scaled by 8, to index a table at +0xff0. It stores two doublewords into that entry at +0xc8 and +0x0, then jumps through a register at 0xdc10 with its four arguments passed on. The jump target is not resolved, so the handler it reaches is open.

- `dobuserr_common` in `IP30/usr/cpu/sysgen/IP30boot/kernel.o` at 0x13df4 (n64).
  Grade: inferred.
  It is the common bus-error handler on IP30, and it carries most of the error logic. It takes a lock with `compare_and_swap_int` on `heart_error_cpumap`, calls `heart_intr` at 0x14160, and classifies the fault with `heart_paddr_to_port` and `heart_error_refine`, the latter called with several codes. Reports go through `hem_add_ioe`, the interrupt mask is re-armed with `heart_imr_bits_rmw`, memory errors go to `log_dimmerr`, and output goes through `cmn_err_tag`. The branches are too many to decode here, so the full set of error classes is open.

- `VEC_dbe` in `IP30/usr/cpu/sysgen/IP30boot/kernel.o` at 0x167e0 (n64).
  Grade: inferred.
  It is the data bus error exception vector. It reads 0xffffffffaff50000 and uses the value to index and update a table, and it reads 0xffffffffb8000000 and the halfword at 0xffffffffffffc3a0. It stores a doubleword to a0+0x140, which is probably the saved exception frame, then jumps to `VEC_trap` at 0x16830 with the same four arguments. The table layout is open.

- `ecc_handler` in `IP30/usr/cpu/sysgen/IP30boot/kernel.o` at 0x17e54 (n64).
  Grade: inferred.
  It is the ECC error handler for the IP30 cache and memory. It reads and writes fields of the error record at a1 (offsets 0x0 to 0x23c), formats text with `cer_to_hex` and `sprintf`, and maps the physical address to a DIMM with `maddr_to_dimm`. It works on cache lines through `ecc_cacheOp` and `ecc_force_cache_line_invalid`, and the operation codes passed to `ecc_cacheOp` are not decoded.

- `VEC_ibe` in `IP30/usr/cpu/sysgen/IP30boot/kernel.o` at 0x1bdf0 (n64).
  Grade: inferred.
  It is the instruction bus error exception vector, and its shape matches `VEC_dbe`. It reads 0xffffffffaff50000 and updates a table entry through it, reads 0xffffffffb8000000 and the halfword at 0xffffffffffffc3a0, and stores a doubleword to a0+0x140. It jumps to `VEC_trap` at 0x1be58, and the facts do not show what differs from `VEC_dbe`.

- `_mraccess` in `IP30/usr/cpu/sysgen/ksync_metered.a(sema.o)` at 0x3890 (n64).
  Grade: inferred.
  It is the metered access path for a kernel synchronisation object. It calls `wchanmeter` on `syncinfo`, then either `mr_access` or `mrmeter_getentry`, and when metering applies it records a class 5 entry with `mrmeter_entry`. The time it passes is the doubleword at 0xffffffffaff20000, and the meaning of class 5 is inferred from the callee names.

- `_mrupdate` in `IP30/usr/cpu/sysgen/ksync_metered.a(sema.o)` at 0x39cc (n64).
  Grade: inferred.
  It is the update counterpart of `_mraccess`. It calls `wchanmeter` on `syncinfo` and `mr_update`, then records a class 6 entry through `mrmeter_entry` at 0x3a94. Its return value is either the result of `mr_update` or an unresolved value, and the names are the main evidence for what it measures.

- `mlreset` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x8738 (n32).
  Grade: inferred.
  It is the IP32 bring-up path, as far as the call sites show, and it resembles the IP30 `mlreset`. It checks the `arg_triton_invall` option with `is_enabled`, reads the CRIME revision through `get_crimerev`, and calls `flushbus`. It installs handlers with `setkgvector`, `setcrimevector` (vectors 0x1c, 0x1d, 0x15 and 0x14, the last two using `buserror_intr`) and `setmaceisavector` (vector 0x5, `powerintr`), then calls `setup_ip32_flags`, `init_sysid` and `load_nvram_tab`. The reasons for each vector are inferred from the handler names.

- `ecc_handler` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0xd894 (n32).
  Grade: inferred.
  It is the ECC error handler on IP32, and it works with the R4600 secondary cache. It disables that cache with `_r4600sc_disable_scache` on entry and re-enables it with `_r4600sc_enable_scache` before returning. It fetches the failing address through `ecc_get_perr_addr`, logs with `ecc_log_error` and `ecc_assign_msg`, and repairs with `ecc_fixmem` and `ecc_fixcache`, and it schedules `ecc_cleanup` with `timeout`. The codes passed to the log calls are not decoded, so the error classes it recognises are open.
