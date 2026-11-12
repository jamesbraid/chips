# Tier-2 reading, batch 2 of chips: routine role statements

Each entry names a routine in an IP27 boot-set object and its address. The statements come only from the rendered instruction facts: registers, loads and stores, calls and constants. Roles are inferred unless the facts fully settle them.

- `mrspinupdate` in `IP27/usr/cpu/sysgen/IP27boot/ksync_metered.a(sema.o)` at 0x50c8
  **Inferred.** Acquires a lock whose state word is at a0, with a bit lock on the word at a0+4 taken through `mutex_bitlock` (0x50f8, bit 0x1). `wchanmeter` (0x50e0) is called once at entry, before the bit lock. It tests the low 15 bits of the state word (mask 0x7fff at 0x5108) and writes that word at 0x5114 and 0x5134, then calls `mrpsema` (0x515c) with a1 the `mutex_bitlock` result and a2 of 0x800 or 0x810. At that call a6 holds the word plus 0x10000, which the facts do not show `mrpsema` reading. The branch at 0x5164 goes to 0x5174 when `mrpsema` returns zero and falls through when it returns nonzero. The return at 0x5124 is the `mutex_bitlock` result or -1. This reads as a spin-then-wait acquire on a counted lock, judged from `wchanmeter` and `mrpsema`.
  Reviewed: 2026-11-12

- `mutex_trylock` in `IP27/usr/cpu/sysgen/IP27boot/ksync_named.a(mutex.o)` at 0x5f0
  **Inferred.** A one-shot try-lock on the word at a0. It loads the doubleword at the fixed address 0xffffffffffffc020, calls `compare_and_swap_ptr` (0x5fc) with a1=0 and a2 from the global at -0x3fe0, and branches on the result at 0x604. The return at 0x610 is a plain 0 or 1 flag, and there is no retry loop.
  Reviewed: 2026-11-12

- `mutex_lock` in `IP27/usr/cpu/sysgen/IP27boot/ksync_named.a(mutex.o)` at 0x6e8
  **Inferred.** The blocking form of the same compare-and-swap lock. It loads from the fixed address 0xffffffffffffc020, calls `compare_and_swap_ptr` (0x6fc), and returns on success at 0x70c. On failure it calls `mutex_wait` (0x718) with its own a0 and a1 and jumps back to the return at 0x70c, so the return value is either the compare result or the `mutex_wait` result.
  Reviewed: 2026-11-12

- `mraccessf` in `IP27/usr/cpu/sysgen/IP27boot/ksync_named.a(sema.o)` at 0x2e84
  **Inferred.** The access-acquire path of a lock that keeps holder records. It bit-locks a0+4 (`mutex_bitlock` at 0x2ec4), tests the state word at a0 for bits 0x6000 (0x2ee4) and 0x8000 (0x2ef0) and writes the word at 0x2ef8. When the global at -0x3fe0 is nonzero it then records a holder with `mrrecordholder` (0x2f08, a1 from that global), and it unlocks with `mutex_bitunlock` (0x2f18). The return at 0x2f40 is either the `mutex_bitunlock` result or the `mrpsema` result. The wait side contains a loop that repeats `us_delay`, `min` against 8 and `mutex_bittrylock` (0x2f80 to 0x2fa4) while the trylock returns zero, a `mutex_bitunlock` (0x2fcc) followed by `nano_delay` (0x2fe4), and a `mrpsema` call (0x302c) whose result is tested at 0x3034. The compare at 0x301c of `mrlock_starve_threshold` with s5 (signed) falls through toward that call when the threshold is greater than or equal; the target of its taken branch (0x3044) is not rendered, so the facts do not show whether `mrpsema` is also reached from there.
  Reviewed: 2026-11-12

- `mrupdatef` in `IP27/usr/cpu/sysgen/IP27boot/ksync_named.a(sema.o)` at 0x304c
  **Inferred.** The update-acquire counterpart of `mraccessf`. It bit-locks a0+4 (`mutex_bitlock` at 0x3088) and tests the state word at a0 with mask 0x7fff (0x30a4). It then tests the global at -0x3fe0 (0x30b8): when it is nonzero the path goes to `mrrecordholder` (0x3114), and when it is zero the path falls to `mutex_bitunlock` (0x30c4) and the return at 0x30e8, which is the `mutex_bitunlock` or `mrpsema` result. The wait side contains a loop of `us_delay`, `min` and `mutex_bittrylock` (0x3124 to 0x3148), a `nano_delay` (0x31d8), a compare at 0x318c of `mrlock_starve_threshold` with s5 (signed), a `mrpsema` call at 0x31a0 whose result is tested at 0x31a8, and a `mutex_bitunlock` at 0x31c0. At the `mrpsema` call a4 holds 0x800800 and a6 holds 0x800, and at the 0x31c0 unlock a5 holds 0x10000; the facts do not show that those callees read these registers.
  Reviewed: 2026-11-12

- `mrunlock` in `IP27/usr/cpu/sysgen/IP27boot/ksync_named.a(sema.o)` at 0x3220
  **Inferred.** The release half for the access and update paths. It bit-locks a0+4 (`mutex_bitlock` at 0x323c) and removes the holder record with `mrremoveholder` (0x3250) when the global at -0x3fe0 is nonzero. It rewrites the state word at a0 (stores at 0x3270, 0x3294 and 0x32cc, each on a different path), after tests of the word against masks 0x3fff and 0x3fff0000 (0x3264 and 0x3278). One path unlocks the bit lock with `mutex_bitunlock` (0x3298) and returns at 0x32ac. Another, entered from the branch at 0x3280 (target 0x32b4), calls `mrvsema` (0x32c8) with a1 the bit-lock result, which fits a wake-up of waiters. The return at 0x32ac is either the `mutex_bitunlock` result or the `mrvsema` result.
  Reviewed: 2026-11-12

- `mrtryupdate` in `IP27/usr/cpu/sysgen/IP27boot/ksync_named.a(sema.o)` at 0x34c0
  **Inferred.** A non-blocking update attempt. It calls `mutex_bittrylock` (0x34d8) on a0+4. When that returns zero the branch at 0x34e0 goes to 0x3550; the return at 0x3548 is a 0 or 1 flag. Otherwise it tests the state word against mask 0x3fff7fff (0x34f4). When the masked value is nonzero it falls to `mutex_bitunlock` (0x3504). When it is zero it writes the state word at 0x3514, calls `mrrecordholder` (0x3524) if the global at -0x3fe0 is nonzero, and unlocks with `mutex_bitunlock` (0x3534). The word OR-ed with 0x4000 is in a2 at the `mrrecordholder` call, and the facts do not show that the callee reads it.
  Reviewed: 2026-11-12

- `mrpromote_or_unlock` in `IP27/usr/cpu/sysgen/IP27boot/ksync_named.a(sema.o)` at 0x3658
  **Inferred.** Handles a holder leaving the lock. It bit-locks a0+4 (`mutex_bitlock` at 0x3678) and loads the state word at a0 (0x3680). The branch at 0x3690 compares a register derived from that load with 1; the facts do not show what masking is applied first. On the not-equal path it calls `mrremoveholder` (0x36a4) when the global at -0x3fe0 is nonzero and then unlocks the bit lock at 0x36c0. On the equal path it unlocks at 0x36f4. The return at 0x36dc is a 0 or 1 flag. The name suggests a promotion step, and the callees fit that reading only loosely.
  Reviewed: 2026-11-12

- `mrspinaccess` in `IP27/usr/cpu/sysgen/IP27boot/ksync_named.a(sema.o)` at 0x3704
  **Inferred.** The spin-then-wait access acquire. It bit-locks a0+4 (`mutex_bitlock` at 0x3724), tests bits 0x6000 of the state word (0x3734), and on the wait path calls `mrpsema` (0x3784) with a1 the bit-lock result and a2 of 0x8 or 0x18. At that call a5 holds the word plus 0x10000 and a6 holds 0x10000, and the facts do not show that `mrpsema` reads them. The branch at 0x378c goes to 0x379c when `mrpsema` returns zero and falls through when it returns nonzero. The return at 0x374c is the bit-lock result or -1.
  Reviewed: 2026-11-12

- `mrspinupdate` in `IP27/usr/cpu/sysgen/IP27boot/ksync_named.a(sema.o)` at 0x37a4
  **Inferred.** The update-side spin-then-wait acquire. It bit-locks a0+4 (`mutex_bitlock` at 0x37c4), tests the low 15 bits of the state word at a0 (mask 0x7fff at 0x37d4), and calls `mrpsema` at 0x3824 with a1 the bit-lock result and a2 of 0x800 or 0x810. At that call a5 holds the word plus 0x10000, and the facts do not show that `mrpsema` reads it. The branch at 0x382c goes to 0x383c when `mrpsema` returns zero and falls through when it returns nonzero. The return at 0x37f0 is the bit-lock result or -1.
  Reviewed: 2026-11-12

- `mutex_trylock` in `IP27/usr/cpu/sysgen/IP27boot/ksync_statistics.a(mutex.o)` at 0x35c
  **Inferred.** The try-lock form with accounting. It loads the doubleword at 0xffffffffffffc020, calls `compare_and_swap_ptr` (0x374) with a2 from the global at -0x3fe0, and charges the outcome with `lstat_update` (0x38c with a2=0x0, and 0x3b0 with a2=0x3). Both `lstat_update` calls pass the caller's return address, which suggests they record the call site. The return at 0x3a0 is a 0 or 1 flag.
  Reviewed: 2026-11-12

- `mutex_lock` in `IP27/usr/cpu/sysgen/IP27boot/ksync_statistics.a(mutex.o)` at 0x484
  **Inferred.** The blocking acquire with the same compare-and-swap as the non-statistics `mutex_lock`, plus accounting. It calls `compare_and_swap_ptr` (0x4a0). When the result is nonzero it records an event with `lstat_update` (0x4bc, a2=0x0). When the result is zero it reads a doubleword from the fixed address 0x9200000001030100 (0x4dc), calls `mutex_wait` (0x4f4), reads a second doubleword (0x504) and calls `lstat_update_time` (0x520, a2=0x2). The return at 0x4d0 is the `lstat_update` or `lstat_update_time` result. The two reads probably bracket the wait with a time, judging only from the `lstat_update_time` name.
  Reviewed: 2026-11-12

- `mraccessf` in `IP27/usr/cpu/sysgen/IP27boot/ksync_statistics.a(sema.o)` at 0x2a58
  **Inferred.** The access-acquire path with the same shape as the non-statistics `mraccessf`. Its bit locks pass the caller's return address (`mutex_bitlock_ra` at 0x2aa8, `mutex_bittrylock_ra` at 0x2b80 and 0x2bb0). It records a holder with `mrrecordholder` (0x2afc) when the global at -0x3fe0 is nonzero, accounts time with `lstat_update_time` (0x2b40 and 0x2c98), and calls `mrpsema` (0x2c58). The compare at 0x2c30 of `mrlock_starve_threshold` with s8 (signed) falls through toward that call when the threshold is greater than or equal; the target of its taken branch (0x2ca8) is not rendered, so the facts do not show whether `mrpsema` is also reached from there. The return at 0x2b60 is the `lstat_update_time` result.
  Reviewed: 2026-11-12

- `mrupdatef` in `IP27/usr/cpu/sysgen/IP27boot/ksync_statistics.a(sema.o)` at 0x2cb8
  **Inferred.** The update-acquire counterpart of the statistics `mraccessf`. It bit-locks through `mutex_bitlock_ra` (0x2d04), records a holder with `mrrecordholder` (0x2dc4) when the global at -0x3fe0 is nonzero, and times the acquire with `lstat_update_time` (0x2d70 and 0x2eb8). On the wait path it retries with `mutex_bittrylock_ra` (0x2dac and 0x2df4), delays with `us_delay`, `min` and `nano_delay` (0x2ee8), and calls `mrpsema` at 0x2e74 with a3 the caller's return address. At that call a4 holds 0x800800, and the facts do not show that `mrpsema` reads it. The return at 0x2d90 is the `lstat_update_time` result.
  Reviewed: 2026-11-12

- `mrunlock` in `IP27/usr/cpu/sysgen/IP27boot/ksync_statistics.a(sema.o)` at 0x2f30
  **Inferred.** The release half of the statistics variant. It bit-locks through `mutex_bitlock_ra` (0x2f54) and removes the holder with `mrremoveholder` (0x2f68) when the global at -0x3fe0 is nonzero. It rewrites the state word at a0 (stores at 0x2f88, 0x2fac and 0x2fe4, each on a different path). One path unlocks with `mutex_bitunlock` (0x2fb0). Another, entered from the branch at 0x2f98 (target 0x2fcc), calls `mrvsema` (0x2fe0), which fits a wake-up of waiters. The return at 0x2fc4 is the unlock or `mrvsema` result.
  Reviewed: 2026-11-12

- `mrtryupdate` in `IP27/usr/cpu/sysgen/IP27boot/ksync_statistics.a(sema.o)` at 0x3230
  **Inferred.** The non-blocking update attempt with accounting. It calls `mutex_bittrylock_ra` (0x3260) and branches on the result at 0x326c; the return at 0x3310 is a 0 or 1 flag. When the result is nonzero it tests the state word against 0x3fff7fff (0x3288). When the masked value is nonzero it unlocks with `mutex_bitunlock` (0x3298) and charges `lstat_update` with a2=0x3 (0x32ac). When it is zero it writes the state word at 0x32c0, calls `mrrecordholder` (0x32d0) if the global at -0x3fe0 is nonzero, unlocks at 0x32e0, and charges `lstat_update` with a2=0x0 (0x32f4). The word OR-ed with 0x4000 is in a5 at the unlock and `mrrecordholder` calls; the facts do not show that those callees read it.
  Reviewed: 2026-11-12

- `mrpromote_or_unlock` in `IP27/usr/cpu/sysgen/IP27boot/ksync_statistics.a(sema.o)` at 0x3474
  **Inferred.** The holder-leaves path with accounting. It bit-locks through `mutex_bitlock_ra` (0x34a8), loads the state word at a0, and branches at 0x34bc on a comparison of a register derived from it with 1; the facts do not show what masking is applied first. On the not-equal path it removes the holder with `mrremoveholder` (0x34d0) when the global at -0x3fe0 is nonzero, unlocks at 0x34ec, and returns a 0 or 1 flag at 0x3508. On the equal path it unlocks at 0x3524 and charges the exit with `lstat_update` (0x353c, a2=0x0); the facts show no `lstat_update` on the not-equal path. As in the non-statistics version, the promotion meaning rests on the name.
  Reviewed: 2026-11-12

- `mrspinaccess` in `IP27/usr/cpu/sysgen/IP27boot/ksync_statistics.a(sema.o)` at 0x354c
  **Inferred.** The spin-then-wait access acquire with accounting. It bit-locks through `mutex_bitlock_ra` (0x3594), tests bits 0x6000 of the state word (0x35a4), and charges the attempt with `lstat_update_time` (0x35cc with a2 of 0x0 or 0x2, and 0x3684 with a2=0x2). On the wait path it calls `mrpsema` (0x3640) with a1 the bit-lock result, a2 of 0x8 (the facts list it as one of several values) and a3 the caller's return address. The branch at 0x366c goes to 0x3694 when `mrpsema` returns zero and falls through when it returns nonzero. The return at 0x35ec is the bit-lock result or -1.
  Reviewed: 2026-11-12

- `mrspinupdate` in `IP27/usr/cpu/sysgen/IP27boot/ksync_statistics.a(sema.o)` at 0x369c
  **Inferred.** The update-side spin-then-wait acquire with accounting. It bit-locks through `mutex_bitlock_ra` (0x36e4), tests the low 15 bits of the state word (mask 0x7fff at 0x36f4), and charges the attempt with `lstat_update_time` (0x371c and 0x37d4). It waits in `mrpsema` (0x3790) with a1 the bit-lock result, a2 of 0x800 (the facts list it as one of several values) and a3 the caller's return address. The branch at 0x37bc goes to 0x37e4 when `mrpsema` returns zero and falls through when it returns nonzero. The return at 0x373c is the bit-lock result or -1.
  Reviewed: 2026-11-12

- `rfscall` in `IP27/usr/cpu/sysgen/IP27boot/nfs.a(nfs_subr.o)` at 0xbd0
  **Inferred.** This reads as a client-side remote call dispatcher, judged from its callees. It gets a transaction id from `krpc_getxid` (0xc18), calls `rfscall_tcp` (0xd04) only when flag 0x2000 in the word at a0+304 is set, takes a client handle with `clget` (0xd54), and issues the call through `KCLNT_CALL` (0xe40). When the `KCLNT_CALL` result is below 0x13 (unsigned), a load at 0xe68 and the indirect jump at 0xe6c index a table in `.rodata` by that result. The jump table's targets are unresolved in these facts, so per-error handling is only partly read. Flags in the structure at a0+304 (masks 0x2000, 0x4000, 0x8000 and 0x20000) and the `is_biod` call at 0xfb0 appear in branches on the later paths, and `printf` calls at 0xf34, 0x1074, 0x1158 and 0x11cc take a format string from `.rodata`, probably diagnostics. The return at 0xc6c is 0x91 on one path and a value the facts leave unresolved on another.
  Reviewed: 2026-11-12

- `mem_tick` in `IP27/usr/cpu/sysgen/IP27boot/numa.a(mem_tick.o)` at 0x498
  **Inferred.** A per-CPU periodic tick. It calls `get_cpu_cnode` (0x4b0), then loads a record pointer from offset 8 of the `pdaindr` entry indexed by a0<<4 (0x4b4). In that record it stores halfwords at 0x758 and 0x75a, words at 0x764, 0x794 and 0x7a0 and doublewords at 0x770, 0x778, 0x780 and 0x788; it only loads from 0x768, 0x76c, 0x790 and 0x79c. A test of the word at 0x768 (offset 1896, at 0x4c4) selects between two paths. It calls `migr_periodic_bounce_control` (0x570, a1 from offset 1940) and `migr_periodic_unpegging_control` (0x6b4, a1 from offset 1952); the facts show branches before each call, on loaded bytes and fields. The branch at 0x5b4 compares two 64-bit values loaded from 0x9200000001030100. The branch at 0x5c4 compares the doubleword at offset 1904 with the doubleword loaded from +0x770, not a timestamp. The likely role is migration or accounting on each tick; the callee names only suggest what the counters mean.
  Reviewed: 2026-11-12

- `enter_panic_mode` in `IP27/usr/cpu/sysgen/IP27boot/os.a(pda.o)` at 0x1cc4
  **Inferred.** Panic entry for the boot-time PDA code. It takes `panic_lock` (0x1ccc), tests a global at -0x3d80 (0x1cdc), and sets a byte at the fixed address 0xffffffffffffc429 (0x1ce0, listed right after that branch). It loops over the CPU count in `maxcpus` (0x1cf8) and stores through pointers it loads (their targets are unresolved in the facts). `log_tstamp_event` (0x1d64) is called with a1 from the global at -0x3d80 and the tag constant 0x50414e49436d6465, which decodes to the ASCII text "PANICmde"; the branch at 0x1cdc is taken when the global is nonzero, and the facts do not show that call on the other path. The return at 0x1d50 is a value the facts leave unresolved.
  Reviewed: 2026-11-12

- `do_mprboot` in `IP27/usr/cpu/sysgen/IP27boot/os.a(printf.o)` at 0x26bc
  **Inferred.** A shutdown or reboot helper for a multi-CPU machine, judged from its flow. It takes `mutex_spinlock` on `panicbuf` (0x26f0) and releases it at 0x2708. It checks `maxcpus` at 0x26d8 and the global `power_off_flag` at 0x26e0, and compares a halfword in the master PDA with a value at -0x3be0 (0x2724). It polls a 64-bit timestamp from 0x9200000001030100 while calling `us_delay` with 0x186a0 (0x2754), flushes the console buffer through `conbuf_flush` with a0=3 (0x2774), and reports with `cmn_err` at severity 6 (0x27bc). The name suggests an MP reboot path, and the callees fit that reading only loosely.
  Reviewed: 2026-11-12

- `ktimer_init` in `IP27/usr/cpu/sysgen/IP27boot/os.a(timers.o)` at 0x0
  **Inferred.** Sets up a timer record passed in a0. It writes two 32-bit fields at +0x2e0 and +0x2e4 and a 64-bit field at +0x2d8, and the 64-bit store takes its value from the doubleword loaded from the fixed address 0x9200000001030100 (0x8). The stored 32-bit values are unknown from these facts, so the initial contents of those two fields are a sub-fact. The record layout comes from the offsets alone.
  Reviewed: 2026-11-12

- `ktimer_switch` in `IP27/usr/cpu/sysgen/IP27boot/os.a(timers.o)` at 0x18
  **Inferred.** Advances a timer record's current slot. It reads the 32-bit index at +0x2e0 and uses it to scale an array at +0x280 (the `ld` at 0x34 and `sd` at 0x40 address a0 + index*8 + 0x280). It loads a 64-bit time from 0x9200000001030100 (0x24), writes it into the 64-bit field at +0x2d8 (0x44), and updates the 32-bit field at +0x2e4 (0x2c) and the index at +0x2e0 (0x4c). The save-and-advance reading comes from the offsets and the single time-like load.
  Reviewed: 2026-11-12
