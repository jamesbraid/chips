# Tier-1 routine roles, chips batch 1

Role statements for batch 1 of the tier-1 reading round. Each statement comes only from the rendered facts for that routine: registers, calls, constants and branch structure in the named binary. Names of routines and the purpose they suggest come from the symbol names, and every entry says where that reading is a guess.

- `handle_cac_buserr` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1dcd0.
  Role (from name): handler for a cached-access bus error. It finds the matching spool record (get_matching_spool_addr, 0x1dd08), compares node partitions (nasid_to_partid, part_id) and calls nasid_to_region, and runs checks (error_check_part_page, error_check_memory_access, error_check_poisoned_state, memory_iscalias). Its outcomes are partition_handle_error calls with codes 0x1, 0x2, 0x4, 0x5, 0x6 and 0x9, a page discard (error_page_discard, 0x1df78), a CRB dump (dump_crb, 0x1e320), or kl_panic at 0x1ddb4. What the codes mean is not stated in the facts.
  Grade: inferred.
  Reviewed: 2026-11-12 (sonnet)

- `intpend0` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x1ff0c.
  It tests a bit word at 0x9200000001000098 against a mask (and at 0x1ff4c and 0x20014). It picks a table record with ms1bit and works on the semaphore at record +32 (cvsema, valusema, vsema). The loop at 0x1fff0 compares the semaphore value with hub_intr_wakeup_cnt, and two indirect calls through record +16 (0x1ffc8, 0x2005c) do the per-record work. The dispatch rule that decides which record runs is not established.
  Grade: inferred.
  Reviewed: 2026-11-12 (sonnet)

- `intpend1` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2006c.
  It has a similar shape to intpend0 but reads a different bit word, at 0x92000000010000a0, masked against s2 (0x200a0). It uses a second record table selected by ms1bit (0x200b8) and makes an indirect call through record +16 (0x200f0). A cmn_err report at 0x20148 sits on a path whose condition the facts do not establish.
  Grade: inferred.
  Reviewed: 2026-11-12 (sonnet)

- `cpuintr` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x20508.
  It indexes pdaindr with a 16-bit value from 0xffffffffffffc420 (16-byte entries), follows the pointer at entry +8 and reads a flag byte at offset 0x520 from it. It branches on bit 0x20 of the word at -0x3d80. It calls bcopy with length 0x168 only when the byte at -0x3f80 and the word nmied are both nonzero (0x20554, 0x2055c), then calls doacvec and doactions (0x205b4, 0x205bc). When bit 0x20 of -0x3d80 is set it also calls log_tstamp_event with 0x71 (0x205f0) and again with 0x65 and 0x71 as its second argument (0x2060c). The facts do not say what the events mean.
  Grade: inferred.
  Reviewed: 2026-11-12 (sonnet)

- `dbgintr` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2067c.
  It reads the same per-CPU block as cpuintr: the 16-bit CPU id, the pdaindr entry, and the flag byte at +0x520. It makes one store (0x206ac; its target is not resolved in the facts) and calls debug (0x206b4) with a format string from .rodata+32520, the flag byte plus 118, and the constant 0x9200000001000090, then returns the result of debug. The meaning of that byte is not established.
  Grade: inferred.
  Reviewed: 2026-11-12 (sonnet)

- `chkdebug` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x20974.
  It appears to gate the debug entry. It reads the CPU id, the per-CPU flag byte at +0x520, and the word at 0x92000000010000a0, then calls dbgintr (0x209b0) only when a bit test at 0x209a8 is nonzero. The value tested against is listed as unknown in the facts, so the gating condition is only partly understood.
  Grade: inferred.
  Reviewed: 2026-11-12 (sonnet)

- `get_my_slotid` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x23be4.
  This is a thin wrapper. It does one 64-bit load (0x23be8; the address is not resolved in the facts) and passes the incoming a1 through a3 to hub_slotbits_to_slot (0x23bf4), returning that result. The facts do not show the loaded word as an argument, so its role in the slot lookup is open.
  Grade: inferred.
  Reviewed: 2026-11-12 (sonnet)

- `llp_pfail_intr` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x252a4.
  Role (from name): link-level power-failure interrupt. It calls msc_owner_cpu (callee at 0x24fd0) and compares the result with a 16-bit value (0x2530c), calls llp_pfail_barrier (0x25344), and runs vector_read and vector_write calls (a0 of 0x0 or 0x6, a2 of 0x0, 0x30, 0x8 or 0x600110) with us_delay waits of 0x64 and 0x12c units. It tests the bit 0x2000000000 repeatedly in the word at 0x9200000001608088 (0x253a8 to 0x253f8). A link retrain or quiesce is a guess from the call pattern; the register meanings and the unit of us_delay are not stated.
  Grade: inferred.
  Reviewed: 2026-11-12 (sonnet)

- `force_system_shutdown` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x26ad4.
  It logs a message through cmn_err (0x26ae4), waits 0x7a120 units with us_delay (0x26af0), and calls elsc_system_reset (0x26af8). If that call returns a negative value, it prints through printf (0x26b14) and waits 0xf4240 units (0x26b20), then makes one store (0x26b34); otherwise it returns at 0x26b08. The branch at 0x26b30 goes to the return sequence at 0x26b04, so it is not a loop around the reset call. What the store writes is not resolved in the facts.
  Grade: inferred.
  Reviewed: 2026-11-12 (sonnet)

- `bootstrap` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2a5b8.
  This is a short early-boot routine. It does one 64-bit load (0x2a5e4; the address is not resolved in the facts), calls mapped_kernel_setup_tlb (0x2a60c) with its incoming a2 and a3, and then tail-jumps to .text+173620 (0x2a62c). The name and the TLB call suggest a handoff into the mapped kernel. The jump target is not named in the facts.
  Grade: inferred.
  Reviewed: 2026-11-12 (sonnet)

- `__nanotime` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2e194.
  It takes the timelock spinlock (mutex_spinlock_spl at 0x2e1a0) and reads a 64-bit counter at 0x9200000001030100. It combines that with the adjtime_delta, adjtime_RTC and adjtime_nanos values, and normalizes the result with loops that compare against 0x3b9aca00. The lock is released at 0x2e340 or 0x2e3c0. Reading 0x3b9aca00 as a count of nanoseconds per second is an inference from the constant alone.
  Grade: inferred.
  Reviewed: 2026-11-12 (sonnet)

- `acktmoclock` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2f3d0.
  It reads the 16-bit CPU id from 0xffffffffffffc420, follows the pdaindr entry and tests the flag byte at +0x520. A nonzero flag leads to one store (0x2f3f4) and a zero flag to another (0x2f404); the store addresses are not resolved in the facts. Both paths return a value derived from the CPU index (id << 4). The name suggests a timer acknowledge, but the facts do not show the timeout semantics.
  Grade: inferred.
  Reviewed: 2026-11-12 (sonnet)

- `ackkgclock` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2f408.
  This is a close sibling of acktmoclock. It reads the same CPU id and per-CPU flag byte; a nonzero flag leads to one store (0x2f42c) and a zero flag to another (0x2f43c), and the store addresses are not resolved in the facts. It returns a value derived from the CPU index. Its use as the clock acknowledge is inferred from the name and from the call in slowkgclock (0x2f5fc).
  Grade: inferred.
  Reviewed: 2026-11-12 (sonnet)

- `startkgclock` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2f440.
  It runs under the spinlock at sym(.sbss)+288 (mutex_spinlock_spl at 0x2f44c, unlocks at 0x2f50c and 0x2f548). When the word at sym(.sdata)+392 is zero, it jumps to a setkgvector call (0x2f52c) with prof_intr as its first argument. When the word at -0x3acc equals 0x4e2 it skips ahead to the unlock at 0x2f548. Otherwise it tests the per-CPU flag byte at +0x520, does a series of loads and stores, and on one path calls cnodetocpu (0x2f4c4). The store targets are not resolved in the facts, and the 0x4e2 comparisons and the role of the flag are not established.
  Grade: inferred.
  Reviewed: 2026-11-12 (sonnet)

- `slowkgclock` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x2f558.
  It takes the same spinlock as startkgclock and compares the master_procid value with the current CPU index (0x2f588). It calls ackkgclock (0x2f5fc) on one path and calls spinlock_init (0x2f61c) on the path taken when the word at sym(.sdata)+400 is zero. The name "slow" is a label only; the facts do not show a rate.
  Grade: inferred.
  Reviewed: 2026-11-12 (sonnet)

- `prof_intr` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x301e0.
  Role (from name): profiling clock interrupt. It calls fastick_maint (0x301f8), calls cnode_subnode_to_cpu (0x30248) on one path, and compares the counter at 0x9200000001030100 with a stored value at [[-0x3c00]+18728] (0x30284). It tests bit 0x20 of the word at -0x3d80, the same test cpuintr makes, and when it is set logs timestamp events: log_tstamp_event with 0x6e at 0x302b0, then with 0x65 and a1 of 0x6e at 0x302cc.
  Grade: inferred.
  Reviewed: 2026-11-12 (sonnet)

- `mdir_xlate_addr_mem` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x307f4.
  It formats text into a0 with sprintf, at four call sites (0x30890 to 0x3095c) that share one format string (.rodata+44192). It does a 64-bit load at 0x30810 (address not resolved in the facts) and tests a word at 0x9000000010000090 against zero (0x30834). It also tests the incoming a2 for negative and against 0x36. The argument values 0x48 and 0x58 appear in the sprintf calls; the facts do not show what is printed, so a role as a memory-directory translation rendering comes from the name only.
  Grade: inferred.
  Reviewed: 2026-11-12 (sonnet)

- `ecc_handler` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x3cfcc.
  It works on a structure passed in a1, reading fields from offset 0x0 up to 0x2bc and writing several of them back. It passes the error word at a1+24 to cer_to_hex (0x3d028), tests its top bits and several field masks, and calls eccf_recoverable_threshold (0x3d0cc); when that returns zero it goes to failsoft_panic_check (0x3d558). It calls ecc_cacheOp (callee at 0x3c820) with codes 0, 1, 3, 4, 5 and 7, calls ecc_force_cache_line_invalid, calls save_cache_error (0x3d298) and memerror_handle_uce (0x3d63c), and ends with a cmn_err_tag call at 0x3d720. The mapping from mask bits to error classes is not established.
  Grade: inferred.
  Reviewed: 2026-11-12 (sonnet)

- `_mraccess` in `IP27/usr/cpu/sysgen/IP27boot/ksync_metered.a(sema.o)` at 0x3890.
  Role (from name): metered access of a synchronization primitive. It calls wchanmeter (0x38b0) with syncinfo and branches on the result (0x38b8). When the result is zero it calls mr_access (0x38c0) and returns at 0x3958. When it is nonzero, the branch goes to 0x396c, where the facts show a call to mrmeter_entry with class 5 (0x3994). It stores to meter offsets 0x1c0 through 0x1d0 (0x390c to 0x391c), calls mrmeter_getentry (0x392c) and, when that is nonzero, runs a load-linked and store-conditional loop (0x3940 to 0x394c) on the word at +0x198. The primitive it meters is not named in the facts.
  Grade: inferred.
  Reviewed: 2026-11-12 (sonnet)

- `_mrupdate` in `IP27/usr/cpu/sysgen/IP27boot/ksync_metered.a(sema.o)` at 0x39ec.
  Role (from name): update side of _mraccess in the same archive member. It calls wchanmeter (0x3a0c) with syncinfo. When that returns zero it calls mr_update (0x3a1c) and returns. When it returns a meter it branches to 0x3ab8, which calls mrmeter_entry with class 6 (0x3ac4). With a meter present it stores to meter offsets 0x1a0 through 0x1d8, after a 64-bit load at 0x3a44 (address not resolved in the facts). A bit-0x4 test (0x3a90) on a halfword loaded at 0x3a88 gates a halfword store (0x3a98) and a reload and store of the word at meter offset 0x1a0. The field meanings are inferred from the access routine, not stated.
  Grade: inferred.
  Reviewed: 2026-11-12 (sonnet)

- `sn0drv_ioctl` in `IP27/usr/cpu/sysgen/IP27boot/sn0drv.o` at 0x2a4.
  This is the ioctl entry of the sn0drv object. It compares the command, a1-8, with 0xf, unsigned (0x2dc). Commands at or above 0xf go to sndrv_ioctl_common (0x2f8) with the same four arguments and return its result. Commands below 0xf load a handler address (0x2e4) and tail-call it through a register (0x2e8) with the same four arguments; the facts do not resolve the table or the targets. The facts show nothing between 0x324 and 0xb6c.
  Grade: inferred.
  Reviewed: 2026-11-12 (sonnet)

- `bitlockdebug` in `IP30/usr/cpu/sysgen/IP30boot/dhardlocks.a(dhardlocks.o)` at 0x1668.
  It works on a lock structure passed in a2. It calls try_bitlock (0x16cc, 0x17f8), updates the lock with plain stores at +0x2a, +0x2c, +0x38, +0x40, +0x50, +0x70, +0x88, +0x90, +0x98 and +0xa0, and with load-linked and store-conditional loops at +0xa8, +0xac, +0xb0, +0xb8 and +0xbc. It calls splx (0x17e0) when a5 is nonzero (0x17d8) and reports through cmn_err (0x18bc) with the value at 0xffffffffaff20000. The "debug" in the name suggests a checking variant, but the facts do not show a debug-only path.
  Grade: inferred.
  Reviewed: 2026-11-12 (sonnet)

- `_64bitlockdebug` in `IP30/usr/cpu/sysgen/IP30boot/dhardlocks.a(dhardlocks.o)` at 0x1f0c.
  This is the 64-bit counterpart of bitlockdebug by name. Its facts have the same shape: calls to try_64bitlock (0x1f70, 0x209c), plain stores and load-linked and store-conditional loops at the same lock field offsets, a splx call (0x2084) on the retry path, and a cmn_err report (0x2160). The facts show no layout difference apart from the lock-call name and the addresses.
  Grade: inferred.
  Reviewed: 2026-11-12 (sonnet)

- `_64bitunlockdebug` in `IP30/usr/cpu/sysgen/IP30boot/dhardlocks.a(dhardlocks.o)` at 0x21d0.
  It releases the lock in a2. It compares the 16-bit field at +0x2a with the 16-bit value at 0xffffffffffffc3a0, which appears to be the current CPU id given how the lock routines above use it. On a mismatch it branches to 0x22a8 and reports through cmn_err (0x22c0). On the matching path it stores to fields at +0x2a and +0x48 through +0x80 and makes one more 64-bit store (0x2298; its base is not resolved in the facts). The field layout is inferred from the paired lock routines.
  Grade: inferred.
  Reviewed: 2026-11-12 (sonnet)

- `heart_mlreset` in `IP30/usr/cpu/sysgen/IP30boot/heart.o` at 0x4c8.
  Role (from name): HEART chip reset. It calls getcpuid (0x4d0) first with its own arguments, makes ten stores (0x4e8 to 0x554 and 0x568; their addresses are not resolved in the facts), and returns the base address 0xffffffffaff10000 (0x564). The facts do not show what the stores write, and the name "mlreset" is not explained by them.
  Grade: inferred.
  Reviewed: 2026-11-12 (sonnet)
