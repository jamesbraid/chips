# Tier-2 reading, batch 2 of chips: routine role statements

Each entry names a routine in an IP27 boot-set object and its address. The statements come only from the rendered instruction facts: registers, loads and stores, calls and constants. Roles are inferred unless the facts fully settle them.

- `mrspinupdate` in `IP27/usr/cpu/sysgen/IP27boot/ksync_metered.a(sema.o)` at 0x50c8
  **Inferred.** Acquires a lock whose state word is at a0, with a bit lock on the word at a0+4 taken through `mutex_bitlock` (0x50f8, bit 0x1). It tests the low 15 bits of the state word (mask 0x7fff at 0x5108) and writes that word at 0x5114 and 0x5134, then calls `mrpsema` (0x515c) with a6 set from the word plus 0x10000 and retries from 0x50f8 while `mrpsema` returns nonzero (0x5174). `wchanmeter` (0x50e0) runs before the wait, so this reads as a spin-then-wait acquire on a counted lock. The return at 0x5124 is the `mutex_bitlock` result or -1.

- `mutex_trylock` in `IP27/usr/cpu/sysgen/IP27boot/ksync_named.a(mutex.o)` at 0x5f0
  **Inferred.** A one-shot try-lock on the word at a0. It loads the doubleword at the fixed address 0xffffffffffffc020, calls `compare_and_swap_ptr` (0x5fc) with a1=0 and a2 from the global at -0x3fe0, and branches on the result at 0x604. The return at 0x610 is a plain 0 or 1 flag, and there is no retry loop.

- `mutex_lock` in `IP27/usr/cpu/sysgen/IP27boot/ksync_named.a(mutex.o)` at 0x6e8
  **Inferred.** The blocking form of the same compare-and-swap lock. It loads from the fixed address 0xffffffffffffc020, calls `compare_and_swap_ptr` (0x6fc), and returns on success at 0x70c. On failure it calls `mutex_wait` (0x718) with its own a0 and a1 and jumps back to the return at 0x70c, so the return value is either the compare result or the `mutex_wait` result.

- `mraccessf` in `IP27/usr/cpu/sysgen/IP27boot/ksync_named.a(sema.o)` at 0x2e84
  **Inferred.** The access-acquire path of a lock that keeps holder records. It bit-locks a0+4 (`mutex_bitlock` at 0x2ec4), tests the state word at a0 for bits 0x6000 (0x2ee4) and 0x8000 (0x2ef0), and records the holder with `mrrecordholder` (0x2f08) on success. On the wait path it unlocks, delays with `us_delay`, `min` against 8 and `nano_delay` (0x2fe4), and calls `mrpsema` (0x302c) once the count compared at 0x301c against `mrlock_starve_threshold` reaches its limit. The return at 0x2f40 is either the bit-unlock result or the `mrpsema` result.

- `mrupdatef` in `IP27/usr/cpu/sysgen/IP27boot/ksync_named.a(sema.o)` at 0x304c
  **Inferred.** The update-acquire counterpart of `mraccessf`. It bit-locks a0+4 (`mutex_bitlock` at 0x3088), tests the state word at a0 with mask 0x7fff (0x30a4) and the holder slot at -0x3fe0 (0x30b8), and records a holder with `mrrecordholder` (0x3114). On the wait path it delays with `us_delay`, `min` and `nano_delay` (0x31d8), compares the count at 0x318c against `mrlock_starve_threshold`, and calls `mrpsema` at 0x31a0 with a4=0x800800 and a6=0x800. It releases the bit lock at 0x31c0 with a5=0x10000, and the return at 0x30e8 is the `mutex_bitunlock` or `mrpsema` result.

- `mrunlock` in `IP27/usr/cpu/sysgen/IP27boot/ksync_named.a(sema.o)` at 0x3220
  **Inferred.** The release half for the access and update paths. It bit-locks a0+4 (0x323c), removes the holder record with `mrremoveholder` (0x3250) when the slot at -0x3fe0 is nonzero, rewrites the state word at a0 (stores at 0x3270, 0x3294 and 0x32cc), and unlocks the bit lock (0x3298). It then calls `mrvsema` (0x32c8) with a table constant in a3, which fits a wake-up of waiters. The return at 0x32ac is either the bit-unlock result or the `mrvsema` result.

- `mrtryupdate` in `IP27/usr/cpu/sysgen/IP27boot/ksync_named.a(sema.o)` at 0x34c0
  **Inferred.** A non-blocking update attempt. It calls `mutex_bittrylock` (0x34d8) on a0+4, and if that fails it returns 0 at 0x3548. On success it tests the state word against mask 0x3fff7fff (0x34f4), writes the word at 0x3514, records the holder with `mrrecordholder` (0x3524) using the word OR-ed with 0x4000, and unlocks the bit lock at 0x3504 or 0x3534. The return is a 0 or 1 flag.

- `mrpromote_or_unlock` in `IP27/usr/cpu/sysgen/IP27boot/ksync_named.a(sema.o)` at 0x3658
  **Inferred.** Handles a holder leaving the lock. It bit-locks a0+4 (`mutex_bitlock` at 0x3678), branches on whether the value at a0 equals 1 (0x3690), removes the holder with `mrremoveholder` (0x36a4) when the slot at -0x3fe0 is nonzero, and unlocks the bit lock at 0x36c0 or 0x36f4 depending on the branch. The name suggests a promotion step, and the callees fit that reading only loosely.

- `mrspinaccess` in `IP27/usr/cpu/sysgen/IP27boot/ksync_named.a(sema.o)` at 0x3704
  **Inferred.** The spin-then-wait access acquire. It bit-locks a0+4 (`mutex_bitlock` at 0x3724), tests bits 0x6000 of the state word (0x3734), and on the wait path calls `mrpsema` (0x3784) with a2 of 0x8 or 0x18 and a6=0x10000. It loops back to 0x3724 while `mrpsema` returns nonzero (0x378c and 0x3794), and the return at 0x374c is the bit-lock result or -1.

- `mrspinupdate` in `IP27/usr/cpu/sysgen/IP27boot/ksync_named.a(sema.o)` at 0x37a4
  **Inferred.** The update-side spin-then-wait acquire. It bit-locks a0+4 (`mutex_bitlock` at 0x37c4), tests the low 15 bits of the state word at a0 (mask 0x7fff at 0x37d4), and calls `mrpsema` at 0x3824 with a2 of 0x800 or 0x810 and a5 set from the word plus 0x10000. It retries from 0x37c4 while `mrpsema` returns nonzero, and the return at 0x37f0 is the bit-lock result or -1.

- `mutex_trylock` in `IP27/usr/cpu/sysgen/IP27boot/ksync_statistics.a(mutex.o)` at 0x35c
  **Inferred.** The try-lock form with accounting. It loads the doubleword at 0xffffffffffffc020, calls `compare_and_swap_ptr` (0x374) with a2 from the global at -0x3fe0, and charges the outcome with `lstat_update` (0x38c with a2=0x0, and 0x3b0 with a2=0x3). Both `lstat_update` calls pass the caller's return address, which suggests they record the call site. The return at 0x3a0 is a 0 or 1 flag.

- `mutex_lock` in `IP27/usr/cpu/sysgen/IP27boot/ksync_statistics.a(mutex.o)` at 0x484
  **Inferred.** The blocking acquire with the same compare-and-swap as the non-statistics `mutex_lock`, plus accounting. It calls `compare_and_swap_ptr` (0x4a0), records an event with `lstat_update` (0x4bc, a2=0x0), and on contention calls `mutex_wait` (0x4f4) and then `lstat_update_time` (0x520, a2=0x2). Two doublewords are read from the fixed address 0x9200000001030100 (0x4dc and 0x504), which is probably the timing source for those records.

- `mraccessf` in `IP27/usr/cpu/sysgen/IP27boot/ksync_statistics.a(sema.o)` at 0x2a58
  **Inferred.** The access-acquire path with the same shape as the non-statistics `mraccessf`. Its bit locks pass the caller's return address (`mutex_bitlock_ra` at 0x2aa8, `mutex_bittrylock_ra` at 0x2b80 and 0x2bb0). It records a holder with `mrrecordholder` (0x2afc), accounts time with `lstat_update_time` (0x2b40 and 0x2c98), and calls `mrpsema` (0x2c58) when the count compared at 0x2c30 against `mrlock_starve_threshold` reaches its limit. The return at 0x2b60 is the `lstat_update_time` result.

- `mrupdatef` in `IP27/usr/cpu/sysgen/IP27boot/ksync_statistics.a(sema.o)` at 0x2cb8
  **Inferred.** The update-acquire counterpart of the statistics `mraccessf`. It bit-locks through `mutex_bitlock_ra` (0x2d04), records and times the acquire with `mrrecordholder` (0x2dc4) and `lstat_update_time` (0x2d70 and 0x2eb8). On the wait path it retries with `mutex_bittrylock_ra` (0x2dac and 0x2df4), delays with `us_delay`, `min` and `nano_delay` (0x2ee8), and calls `mrpsema` at 0x2e74 with a4=0x800800. The return at 0x2d90 is the `lstat_update_time` result.

- `mrunlock` in `IP27/usr/cpu/sysgen/IP27boot/ksync_statistics.a(sema.o)` at 0x2f30
  **Inferred.** The release half of the statistics variant. It bit-locks through `mutex_bitlock_ra` (0x2f54), removes the holder with `mrremoveholder` (0x2f68) when the slot at -0x3fe0 is nonzero, and rewrites the state word at a0 (stores at 0x2f88, 0x2fac and 0x2fe4). It unlocks at 0x2fb0 and calls `mrvsema` (0x2fe0), which fits a wake-up of waiters. The return at 0x2fc4 is the unlock or `mrvsema` result.

- `mrtryupdate` in `IP27/usr/cpu/sysgen/IP27boot/ksync_statistics.a(sema.o)` at 0x3230
  **Inferred.** The non-blocking update attempt with accounting. It calls `mutex_bittrylock_ra` (0x3260) and returns 0 or 1 at 0x3310 depending on the result. On success it tests the state word against 0x3fff7fff (0x3288), writes it back at 0x32c0, records the holder with `mrrecordholder` (0x32d0), and charges the outcome with `lstat_update` (0x32ac with a2=0x3, and 0x32f4 with a2=0x0).

- `mrpromote_or_unlock` in `IP27/usr/cpu/sysgen/IP27boot/ksync_statistics.a(sema.o)` at 0x3474
  **Inferred.** The holder-leaves path with accounting. It bit-locks through `mutex_bitlock_ra` (0x34a8), branches on whether the value at a0 equals 1 (0x34bc), and removes the holder with `mrremoveholder` (0x34d0) when the slot at -0x3fe0 is nonzero. It unlocks at 0x34ec or 0x3524 and charges the exit with `lstat_update` (0x353c, a2=0x0). As in the non-statistics version, the promotion meaning rests on the name.

- `mrspinaccess` in `IP27/usr/cpu/sysgen/IP27boot/ksync_statistics.a(sema.o)` at 0x354c
  **Inferred.** The spin-then-wait access acquire with accounting. It bit-locks through `mutex_bitlock_ra` (0x3594), tests bits 0x6000 of the state word (0x35a4), and charges the attempt with `lstat_update_time` (0x35cc with a2 of 0x0 or 0x2, and 0x3684 with a2=0x2). On the wait path it calls `mrpsema` (0x3640) with a2 of 0x8 or 0x18 and retries from 0x3590 while it returns nonzero (0x3694). The return at 0x35ec is the bit-lock result or -1.

- `mrspinupdate` in `IP27/usr/cpu/sysgen/IP27boot/ksync_statistics.a(sema.o)` at 0x369c
  **Inferred.** The update-side spin-then-wait acquire with accounting. It bit-locks through `mutex_bitlock_ra` (0x36e4), tests the low 15 bits of the state word (mask 0x7fff at 0x36f4), and charges the attempt with `lstat_update_time` (0x371c and 0x37d4). It waits in `mrpsema` (0x3790) with a2 of 0x800 or 0x810 and retries from 0x3724 while it returns nonzero (0x37bc and 0x37dc). The return at 0x373c is the bit-lock result or -1.

- `rfscall` in `IP27/usr/cpu/sysgen/IP27boot/nfs.a(nfs_subr.o)` at 0xbd0
  **Inferred.** This reads as a client-side remote call dispatcher, judged from its callees. It gets a transaction id from `krpc_getxid` (0xc18), picks a transport through `rfscall_tcp` (0xd04), takes a client handle with `clget` (0xd54), and issues the call through `KCLNT_CALL` (0xe40). The reply code indexes a jump table at 0xe68 through the indirect jump at 0xe6c, and the jump table's targets are unresolved in these facts, so per-error handling is only partly read. Flags in the structure at a0+304 (masks 0x2000, 0x4000, 0x8000 and 0x20000) and the `is_biod` check at 0xfb0 steer the retry and timeout paths, and `printf` calls at 0xf34, 0x1074, 0x1158 and 0x11cc report errors. The return at 0xc6c is 0x91 on one path and a value the facts leave unresolved on another.

- `mem_tick` in `IP27/usr/cpu/sysgen/IP27boot/numa.a(mem_tick.o)` at 0x498
  **Inferred.** A per-CPU periodic tick. It finds the CPU's PDA record through `pdaindr` indexed by a0<<4 (0x4b4) and calls `get_cpu_cnode` (0x4b0). It updates counters in that record at offsets 0x758, 0x75a, 0x764, 0x768, 0x770, 0x778, 0x788, 0x790, 0x794, 0x79c and 0x7a0. It calls `migr_periodic_bounce_control` (0x570) and `migr_periodic_unpegging_control` (0x6b4), gated by flags at offsets 1892, 1896 and 1952 in a subsidiary record, and it compares two 64-bit values loaded from 0x9200000001030100 at 0x5b4 and 0x5c4 before branching. The likely role is migration or accounting on each tick; the exact counter meanings are guesses from the callee names.

- `enter_panic_mode` in `IP27/usr/cpu/sysgen/IP27boot/os.a(pda.o)` at 0x1cc4
  **Inferred.** Panic entry for the boot-time PDA code. It sets a byte at the fixed address 0xffffffffffffc429 (0x1ce0), takes `panic_lock` (0x1ccc), and tests a global at -0x3d80 (0x1cdc). It loops over the CPU count in `maxcpus` (0x1cf8), stores through pointers it loads (their targets are unresolved in the facts), and calls `log_tstamp_event` (0x1d64) with the tag constant 0x50414e49436d6465, which decodes to the ASCII text "PANICmde". The return at 0x1d50 is a value the facts leave unresolved.

- `do_mprboot` in `IP27/usr/cpu/sysgen/IP27boot/os.a(printf.o)` at 0x26bc
  **Inferred.** A shutdown or reboot helper for a multi-CPU machine, judged from its flow. It takes `mutex_spinlock` on `panicbuf` (0x26f0) and releases it at 0x2708. It checks `maxcpus` at 0x26d8 and the global `power_off_flag` at 0x26e0, and compares a halfword in the master PDA with a value at -0x3be0 (0x2724). It polls a 64-bit timestamp from 0x9200000001030100 while calling `us_delay` with 0x186a0 (0x2754), flushes the console buffer through `conbuf_flush` with a0=3 (0x2774), and reports with `cmn_err` at severity 6 (0x27bc). The name suggests an MP reboot path, and the callees fit that reading only loosely.

- `ktimer_init` in `IP27/usr/cpu/sysgen/IP27boot/os.a(timers.o)` at 0x0
  **Inferred.** Sets up a timer record passed in a0. It writes two 32-bit fields at +0x2e0 and +0x2e4 and a 64-bit field at +0x2d8, and the 64-bit store takes its value from the doubleword loaded from the fixed address 0x9200000001030100 (0x8). The stored 32-bit values are unknown from these facts, so the initial contents of those two fields are a sub-fact. The record layout comes from the offsets alone.

- `ktimer_switch` in `IP27/usr/cpu/sysgen/IP27boot/os.a(timers.o)` at 0x18
  **Inferred.** Advances a timer record's current slot. It reads the 32-bit index at +0x2e0 and uses it to scale an array at +0x280 (the `ld` at 0x34 and `sd` at 0x40 address a0 + index*8 + 0x280). It loads a 64-bit time from 0x9200000001030100 (0x24), writes it into the 64-bit field at +0x2d8 (0x44), and updates the 32-bit field at +0x2e4 (0x2c) and the index at +0x2e0 (0x4c). The save-and-advance reading comes from the offsets and the single time-like load.
