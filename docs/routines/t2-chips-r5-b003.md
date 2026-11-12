# Tier-2 reading, round 5, batch 3 of chips: routine role statements

Each entry names a routine in an IP27 boot-set object and its address. The statements come only from the rendered instruction facts: loads and stores, calls, constants and branch shapes. Every role here is inferred. Where the facts leave the meaning open, the entry says so.

- `md_perf_stop_count` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x42858
  **Inferred.** It loads the halfword at a0+0x1a [@0x42858]. It stores a doubleword to an address built from that halfword [@0x4286c]. Its return value is the constant 0x9200000001a10000 [@0x42868].
  Role (from facts): a halfword read [@0x42858] feeding a doubleword store address [@0x4286c], with a fixed return value [@0x42868].
  Reviewed: 2026-11-12

- `mrspinaccess` in `IP27/usr/cpu/sysgen/IP27boot/ksync.a(sema.o)` at 0x31f8
  **Inferred.** It calls mutex_bitlock with a0 = a0+4 and a1 = 0x1 [call 1]. It then calls mrpsema with a0 at entry [call 2, @0x3228 taken]. When the mrpsema result is zero it takes the branch [@0x3280 taken zero]. Its return value is one of the mutex_bitlock result and -0x1 [@0x3244].
  Role (from facts): a bit lock [call 1] followed by a semaphore call [call 2], with a branch on a zero result [@0x3280 taken zero].
  Reviewed: 2026-11-12

- `mutex_trylock` in `IP27/usr/cpu/sysgen/IP27boot/ksync_metered.a(mutex.o)` at 0x5f0
  **Inferred.** It calls wchanmeter [call 1]. It then calls compare_and_swap_ptr with a0 at entry and a1 = 0x0 [call 2]. When the swap result is zero it takes the branch [@0x620 taken zero] to a separate path. Its return value is one of 0x0 and 0x1 [@0x690].
  Role (from facts): a compare-and-swap attempt [call 2] made after a metering call [call 1], returning one of two values [@0x690].
  Reviewed: 2026-11-12

- `mutex_lock` in `IP27/usr/cpu/sysgen/IP27boot/ksync_metered.a(mutex.o)` at 0x760
  **Inferred.** It calls wchanmeter [call 1]. It then calls compare_and_swap_ptr with a0 at entry and a1 = 0x0 [call 2]. When the swap result is zero it takes the branch [@0x7a4 taken zero] to a path that calls mutex_wait with a0 and a1 at entry [call 3, @0x7a4 taken]. On the nonzero side, when the wchanmeter result is nonzero [@0x7ac fall], it stores a word to the record found through that result [@0x7e8].
  Role (from facts): a lock acquire that meters first [call 1], then tries a compare-and-swap [call 2], and waits [call 3] when the swap result is zero [@0x7a4 taken zero].
  Reviewed: 2026-11-12

- `mrtryupdate` in `IP27/usr/cpu/sysgen/IP27boot/ksync_metered.a(sema.o)` at 0x3b9c
  **Inferred.** It calls wchanmeter [call 1]. It then calls mr_tryupdate with a0 at entry [call 2]. When the mr_tryupdate result is zero it takes the branch [@0x3bcc taken zero] and returns 0x0. On the nonzero side, when the wchanmeter result is nonzero [@0x3bd4 fall], it calls mrmeter_entry with a0 = ret(wchanmeter) [call 3, @0x3bd4 fall]. When the mrmeter_entry result is zero it calls mr_unlock with a0 at entry [call 4, @0x3bec taken]. Its return value is one of 0x0 and 0x1 [@0x3c28].
  Role (from facts): a metering call [call 1] around a try-update [call 2], returning one of two constants [@0x3c28].
  Reviewed: 2026-11-12

- `mrmeter_entry` in `IP27/usr/cpu/sysgen/IP27boot/ksync_metered.a(sema.o)` at 0x41a0
  **Inferred.** It calls mutex_spinlock with a0 = a0+304 [call 1]. It loads the doubleword at abs 0x9200000001030100 [@0x4234] and the doubleword at abs 0xffffffffffffc020 [@0x4248]. It stores halfwords [@0x421c] and doublewords [@0x4230]. When the s1 value is nonzero it calls kmem_zone_free [call 3, @0x4268 fall]. Its return value is one of 0x0 and a value the facts leave open [@0x4294].
  Role (from facts): a spin-locked record update [call 1] with a conditional free [call 3, @0x4268 fall].
  Reviewed: 2026-11-12

- `ktimer_readticks` in `IP27/usr/cpu/sysgen/IP27boot/os.a(timers.o)` at 0x50
  **Inferred.** It loads the word at a0+0x2e0 [@0x6c] and the doubleword at a0+0x2d8 [@0x64]. When the word differs from a1 [@0x70 taken] it returns the doubleword at (a0 + (a1 << 0x3)) + 0x280 [@0xac].
  Role (from facts): a value read from a table indexed by a1 [@0x68], returned directly when the word differs from a1 [@0x70 taken].
  Reviewed: 2026-11-12

- `ktimer_read` in `IP27/usr/cpu/sysgen/IP27boot/os.a(timers.o)` at 0xb4
  **Inferred.** It loads the doubleword at a0+0x2d8 [@0xd4] and the word at a0+0x2e0 [@0xdc]. When the word differs from a1 [@0xe0 taken] it goes to 0x148 [@0xe0 taken]. It stores a word to a2+0x0 [@0x138] and a doubleword to a2+0x8 [@0x144].
  Role (from facts): a per-index read that writes its outputs through the third argument (a2) [@0x138] [@0x144].
  Reviewed: 2026-11-12

- `ktimer_slptime` in `IP27/usr/cpu/sysgen/IP27boot/os.a(timers.o)` at 0x150
  **Inferred.** It loads the word at a0+0x2e0 [@0x150]. When that word is zero [@0x15c taken zero], or equals 1 [@0x164 taken], or equals 2 [@0x16c taken], its return value is 0x0 [@0x190].
  Role (from facts): a three-case test on the word at +0x2e0 whose first three values all return 0x0 [@0x15c taken zero] [@0x190].
  Reviewed: 2026-11-12

- `uuid_create` in `IP27/usr/cpu/sysgen/IP27boot/os.a(uuid.o)` at 0x28
  **Inferred.** It calls mutex_lock with a0 = sym(.bss) and a1 = 0x19 [call 1]. It stores a word at a0+0x0 [@0x64] and halfwords at a0+0x4, a0+0x6 and a0+0x8 [@0x78] [@0x88] [@0x5c]. When the byte at sym(.sbss) is zero [@0x54 taken] it first calls nanotime [call 5, @0x54 taken] and then reads the doubleword at abs 0x9200000001030100 [@0x138].
  Role (from facts): a locked record update [call 1] that, on the first-use path [@0x54 taken], also calls nanotime [call 5] and reads a doubleword at a constant address [@0x138].
  Reviewed: 2026-11-12

- `xthread_periodic_timeout` in `IP27/usr/cpu/sysgen/IP27boot/os.a(xthread.o)` at 0x72c
  **Inferred.** It tests a flag bit in the word at a4+0x0 [@0x74c]. On the taken side of that test [@0x74c taken] it stores a word at +0x0 of the fifth argument (a4) [@0x764]. It stores doublewords at a4+0x28, a4+0x30 and a4+0x38 [@0x768] [@0x76c] [@0x774]. It then calls xthread_table_name_get_property with a0 at entry and a1 = 0x2 [call 1, @0x74c taken]. It stores a halfword at a4+0x4a [@0x78c]. The branch on a -1 value [@0x790 taken] tests a register rebuilt from the call 1 result, not the a2 argument.
  Role (from facts): a record setup on a4 [@0x764] that runs only when a flag bit of its first word is clear [@0x74c taken], followed by a property lookup [call 1].
  Reviewed: 2026-11-12

- `pcibr_open` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x570
  **Inferred.** It calls cap_able_cred with a1 = 0x2000000000 [call 1]. When its result is zero it takes the branch [@0x588 taken zero] to a separate path. Its return value is one of 0x0 and 0x1 [@0x594].
  Role (from facts): one call [call 1] followed by a return of one of two values [@0x594].
  Reviewed: 2026-11-12

- `pcibr_bridge_ptr_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x42ec
  **Inferred.** It calls xtalk_piotrans_addr with a1 = 0x0, a2 = 0x0, a3 = 0x8 and a4 = 0x0 [call 1]. It loads words at +0x4 of that result [@0x430c] [@0x432c] [@0x4340]. It compares a value with 0xd102 [@0x4324 taken]. Its return value is one of the xtalk_piotrans_addr result and that result plus 0x800000 [@0x4368].
  Role (from facts): one call [call 1] whose result is returned either as is or plus 0x800000 [@0x4368].
  Reviewed: 2026-11-12

- `pcireg_id_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xddec
  **Inferred.** When a0 is zero it takes the branch [@0xddf4 taken] to a call to panic [call 1, @0xdf3c]. It loads the halfword at a0+0x72 [@0xde10]. It loads the doubleword at a0+0x8 [@0xde1c]. Its return value is one of 0x0 and a value the facts leave open [@0xde48].
  Role (from facts): a halfword read [@0xde10] that feeds a chain of compare branches [@0xde18 taken], with a panic call [call 1] on a zero a0 [@0xddf4 taken].
  Reviewed: 2026-11-12

- `pcireg_stat_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xdf4c
  **Inferred.** When a0 is zero it takes the branch [@0xdf54 taken] to a call to panic [call 1, @0xe0a0]. It loads the halfword at a0+0x72 [@0xdf70]. It loads the doubleword at a0+0x8 [@0xdf7c]. Its return value is one of 0x0 and a value the facts leave open [@0xdfa8].
  Role (from facts): a halfword read [@0xdf70] that feeds a chain of compare branches [@0xdf78 taken], with a panic call [call 1] on a zero a0 [@0xdf54 taken].
  Reviewed: 2026-11-12

- `pcireg_bus_err_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xe0b0
  **Inferred.** When a0 is zero it takes the branch [@0xe0b8 taken] to a call to panic [call 1, @0xe210]. It loads the halfword at a0+0x72 [@0xe0d4]. It loads the doubleword at a0+0x8 [@0xe0e0]. Its return value is one of 0x0 and a value the facts leave open [@0xe10c].
  Role (from facts): a halfword read [@0xe0d4] that feeds a chain of compare branches [@0xe0dc taken], with a panic call [call 1] on a zero a0 [@0xe0b8 taken].
  Reviewed: 2026-11-12

- `pcireg_control_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xe220
  **Inferred.** When a0 is zero it takes the branch [@0xe228 taken] to a call to panic [call 1, @0xe378]. It loads the halfword at a0+0x72 [@0xe244]. It loads the doubleword at a0+0x8 [@0xe250]. Its return value is one of 0x0 and a value the facts leave open [@0xe280].
  Role (from facts): a halfword read [@0xe244] that feeds a chain of compare branches [@0xe24c taken], with a panic call [call 1] on a zero a0 [@0xe228 taken].
  Reviewed: 2026-11-12
