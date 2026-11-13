# Tier-2 reading, batch 1 of chips: routine role entries

Each entry names a routine in an IP27 boot-set object by its install path and address. The statements
come only from the rendered instruction facts: registers, loads and stores, calls and constants. Entries
are inferred unless the facts settle the role. Where the facts leave a sub-fact open, the entry says so.

- `eccf_recoverable_threshold` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x3ce18
  **Inferred.** A 188-byte routine that takes a record in `a1` and returns 0 or 1. It loads the 64-bit word at `a1+0x2c0` (`ld` at 0x3ce70, 0x3cec0, 0x3cec8) and stores a 64-bit word back to it (`sd` at 0x3ceac). It also loads one doubleword through a register base the facts do not resolve (0x3ce48). The branches at 0x3ce78 and 0x3ce84 test the word at `a1+704` for zero and a value the facts do not resolve, derived from it and that doubleword, against the constant 0x3938700 (unsigned). It loads a halfword at `a1+0x2c8`, `0x2ca`, `0x2cc` or `0x2ce` (`lhu` at 0x3ce8c, the offset picked by the branches at 0x3ce50 to 0x3ce60) and stores a halfword back (`sh` at 0x3ce9c, 0x3ceb8). The return at 0x3cea4 yields 0 or 1 and the return at 0x3ceb4 yields 1. Role (from name): a threshold test for a recoverable error; the facts do not show what the counted events are.
  Reviewed: 2026-11-12

- `ecc_handler` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x3cfcc
  **Inferred.** A 2008-byte routine that takes a record in `a1`. It reads the record fields at `+0x18`, `+0x2b8` and `+0x2bc` among others, and calls `eccf_recoverable_threshold` (0x3d0cc) with the word at `+0x18` in `a2`. It calls `ecc_cacheOp` with first-argument values 0x4, 0x0, 0x1, 0x5, 0x3 and 0x7 (calls at 0x3d144 to 0x3d654) and `ecc_force_cache_line_invalid` (0x3d1b8, 0x3d1c8, 0x3d664). It also calls `save_cache_error` (0x3d298), `memerror_handle_uce` (0x3d63c), `failsoft_panic_check` (0x3d558) and `cmn_err_tag` (0x3d720) with message id 0xb96. Near 0x3d6c4 to 0x3d6e8 it loads from addresses based on `nasid_to_compact_node`; the facts do not show what is mapped. Role (from name): an error handler for cache and memory errors. The meaning of each `ecc_cacheOp` value is not shown by the facts.
  Reviewed: 2026-11-12

- `md_perf_stop_count` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x42858
  **Inferred.** A 24-byte routine that reads the halfword at `a0+0x1a` (`lh` at 0x42858), stores a 64-bit value (`sd` at 0x4286c) at an address the facts do not resolve, and returns the constant 0x9200000001a10000 in `v0` (0x42868). The stored value is not derived in the facts, so what the store does is an open sub-fact.
  Reviewed: 2026-11-12

- `mutex_trylock` in `IP27/usr/cpu/sysgen/IP27boot/ksync.a(mutex.o)` at 0x35c
  **Inferred.** A 48-byte try-lock. It loads the global word at `-0x3fe0` (`ld` at 0x36c) and makes one
  `compare_and_swap_ptr` call on the lock word with 0 in `a1` and that global in `a2` (jal at 0x368). It
  returns 0 or 1 at 0x37c, depending on the swap result (beq at 0x370).
  Reviewed: 2026-11-12

- `mutex_lock` in `IP27/usr/cpu/sysgen/IP27boot/ksync.a(mutex.o)` at 0x454
  **Inferred.** A 64-byte routine that makes the same single `compare_and_swap_ptr` call as the try-lock at 0x35c (jal at 0x468, with 0 in `a1` and the global from `-0x3fe0` in `a2`). When the call returns zero (beq at 0x470) it calls `mutex_wait` (jal at 0x484) with its own `a0` and `a1` and returns that result; when the call returns nonzero it returns the swap result at 0x478. The facts do not say which of the two swap results means the lock was taken.
  Reviewed: 2026-11-12

- `mraccessf` in `IP27/usr/cpu/sysgen/IP27boot/ksync.a(sema.o)` at 0x2978
  **Inferred.** A 456-byte routine on the lock record at `a0`. It takes a bit lock on the word at `a0+4` through `mutex_bitlock` (0x29b8), tests bit 0x40 of `a0+4` (bne at 0x29ac) and bits 0x6000 and 0x8000 of `a0` (0x29d8, 0x29e4), and calls `mrrecordholder` (0x29fc) when the global at `-0x3fe0` is nonzero. It calls `mutex_bittrylock` (0x2a4c, 0x2a90), `us_delay` and `min` (0x2a74, 0x2a80) in a retry loop, `mutex_bitunlock` (0x2a0c, 0x2ac0), and `nano_delay` (0x2ad8) with `a4` holding 0x186a0 at the call; the facts do not show whether that value is an argument. It calls `mrpsema` (0x2b20) when the value loaded from `mrlock_starve_threshold` is greater than or equal to a register the facts do not resolve (bne at 0x2b10). Role (from name): a reader-side access to a multiple-reader lock. The `f` in the name is not explained by the facts.
  Reviewed: 2026-11-12

- `mrupdatef` in `IP27/usr/cpu/sysgen/IP27boot/ksync.a(sema.o)` at 0x2b40
  **Inferred.** A 412-byte routine on the lock record at `a0`, shaped like `mraccessf` at 0x2978. It takes the bit lock on `a0+4` (jal at 0x2b7c), tests bit 0x40 of `a0+4` (bne at 0x2b70) and the mask 0x7fff of `a0` (bne at 0x2b98), calls `mrrecordholder` (bne at 0x2bac, call at 0x2c08) when the global at `-0x3fe0` is nonzero, and retries with `us_delay` and `mutex_bittrylock` (0x2c18 to 0x2c34). It calls `nano_delay` (0x2ccc) and `mrpsema` (0x2c94), with `a4` holding 0x800800 and `a6` holding 0x800 at that call; the facts do not show which of those are arguments. The branch at 0x2c80 compares the word loaded from `mrlock_starve_threshold` with a register the facts do not resolve. Role (from name): a write-side access to a multiple-reader lock.
  Reviewed: 2026-11-12

- `mrunlock` in `IP27/usr/cpu/sysgen/IP27boot/ksync.a(sema.o)` at 0x2d14
  **Inferred.** A 184-byte routine on the lock record at `a0`. It takes the bit lock on `a0+4` (jal at 0x2d30). When the global at `-0x3fe0` is nonzero (beq at 0x2d3c) it calls `mrremoveholder` (0x2d44). It stores to the lock word at `a0` (sw at 0x2d64, 0x2d88, 0x2dc0); the stored values are not shown. On one path it calls `mrvsema` (0x2dbc), with `a4` holding 0xffffffffffff0000, and it drops the bit lock with `mutex_bitunlock` (0x2d8c). The branches that select between those paths are at 0x2d58, 0x2d6c and 0x2d74. Role (from name): the release of a multiple-reader lock.
  Reviewed: 2026-11-12

- `mrtryupdate` in `IP27/usr/cpu/sysgen/IP27boot/ksync.a(sema.o)` at 0x2fb4
  **Inferred.** A 152-byte routine. It tries to take the bit lock on `a0+4` with `mutex_bittrylock` (0x2fcc); when that returns zero the beq at 0x2fd4 skips to 0x3044. Otherwise it tests the lock word at `a0` against the mask 0x3fff7fff (0x2fe8). When the masked value is zero it stores to the lock word (sw at 0x3008; the value is not shown); when it is nonzero the path goes to `mutex_bitunlock` (0x2ff8). When the global at `-0x3fe0` is nonzero it calls `mrrecordholder` (0x3018) with `a2` holding the lock word OR 0x4000, and it calls `mutex_bitunlock` (0x3028). The return at 0x303c yields 0 or 1; the facts do not tie each value to a path. Role (from name): a non-blocking attempt to take the lock for update.
  Reviewed: 2026-11-12

- `mrpromote_or_unlock` in `IP27/usr/cpu/sysgen/IP27boot/ksync.a(sema.o)` at 0x314c
  **Inferred.** A 172-byte routine on the lock record at `a0`, running under the bit lock on `a0+4` (jal at 0x316c). It compares a value with 1 (beq at 0x3184) and tests the global at `-0x3fe0` (beq at 0x3190). Depending on those tests it calls `mrremoveholder` (0x3198) or not, and it calls `mutex_bitunlock` at two sites (0x31b4, 0x31e8). Its return is 0 or 1 at 0x31d0. Role (from name): promote the hold or unlock; which outcome is the promotion is not settled by the facts.
  Reviewed: 2026-11-12

- `mrspinaccess` in `IP27/usr/cpu/sysgen/IP27boot/ksync.a(sema.o)` at 0x31f8
  **Inferred.** A 160-byte routine on the lock record at `a0`. It takes the bit lock on `a0+4` (jal at 0x3218) and loads the lock word (0x3220). The bne at 0x3228 tests the bits 0x6000 of the lock word. When they are set the branch goes to 0x324c, which stores to the lock word (sw at 0x3254) and calls `mrpsema` (0x3278) with `a5` holding the lock word plus 65536 and `a6` holding 0x10000. When they are clear it stores to the lock word (sw at 0x3234) and reaches the return at 0x3244, which yields the `mutex_bitlock` result or -1. The beq at 0x3280 tests the `mrpsema` result against zero; where it goes is not traced by the facts. Role (from name): a spinning reader access to a multiple-reader lock.
  Reviewed: 2026-11-12

- `mrspinupdate` in `IP27/usr/cpu/sysgen/IP27boot/ksync.a(sema.o)` at 0x3298
  **Inferred.** A 160-byte routine on the lock record at `a0`, the write-side counterpart of `mrspinaccess` by name. It takes the bit lock on `a0+4` (jal at 0x32b8) and loads the lock word (0x32c0). The bne at 0x32c8 tests the mask 0x7fff of the lock word; when it is nonzero the branch goes to 0x32ec, which stores to the lock word (sw at 0x32f4) and calls `mrpsema` (0x3318) with `a2` holding 0x800 and `a4` holding 0x810 and `a5` holding the lock word plus 65536; the facts do not show which of those registers are arguments. When it is zero the code stores to the lock word (sw at 0x32d4) and reaches the return at 0x32e4, which yields the `mutex_bitlock` result or -1. The beq at 0x3320 tests the `mrpsema` result against zero; where it goes is not traced by the facts. Role (from name): a spinning write-side update of a multiple-reader lock.
  Reviewed: 2026-11-12

- `mutex_trylock` in `IP27/usr/cpu/sysgen/IP27boot/ksync_metered.a(mutex.o)` at 0x5f0
  **Inferred.** The metered counterpart of the try-lock at 0x35c. It calls `wchanmeter` (0x604, with `mutexinfolist` in `a1`) and makes the same single `compare_and_swap_ptr` call on the lock word (0x618). When `wchanmeter` returns nonzero it updates the word at `meter+0x38` with an `ll`/`sc` pair (0x638, 0x6a4) on both paths of the swap result. On the path where the swap result is nonzero it also stores to `meter+0x3c`, `+0x40`, `+0x48`, `+0x50` and `+0x70`. The facts do not state what the meter fields hold; reading `wchanmeter` as a per-wait-channel lookup is from its name.
  Reviewed: 2026-11-12

- `mutex_lock` in `IP27/usr/cpu/sysgen/IP27boot/ksync_metered.a(mutex.o)` at 0x760
  **Inferred.** The metered counterpart of the lock at 0x454. It gets the meter from `wchanmeter` (0x778) and calls `compare_and_swap_ptr` on the lock word (0x79c). The two outcomes of that call take different paths. When it returns nonzero and the meter is not null, the routine increments `meter+0x28` with an `ll`/`sc` pair (0x7c4) and stores to `+0x30`, `+0x40`, `+0x48`, `+0x50` and `+0x70`; it loads from `+0x60` and `+0x5c`. When the compare at 0x828 falls through it also stores to `+0x60`, `+0x68` and `+0x5c`. When the swap returns zero and the meter is not null (0x84c), it increments `meter+0x28` with a second `ll`/`sc` pair (0x858) and then calls `mutex_wait` (0x874) with its own `a0` and `a1`. The value returned at 0x844 is the `compare_and_swap_ptr` result, the `mutex_wait` result or a value the facts leave unresolved, not a fixed 0 or 1. Which outcome means the lock was taken, and what the meter fields hold, are not established.
  Reviewed: 2026-11-12

- `mutex_wake_r` in `IP27/usr/cpu/sysgen/IP27boot/ksync_metered.a(mutex.o)` at 0x13c8
  **Inferred.** A 684-byte routine on a mutex record passed in `a0`. It calls `wchanmeter` (0x13ec). It takes the nested bit lock at offset 132 of the record at `[a0+8]` (`nested_bitlock` at 0x14cc), calls `thread_unblock` on `[a0+8]` with 2 (0x150c) and calls `mutex_bitunlock` on the same address (0x151c). Later it takes `nested_bitlock` at offset 132 of the record named by the global at `-0x3fe0` (0x1608), calls `drop_inheritance` (0x1618) with that global in `a2`, and calls `nested_bitunlock` (0x1624). It calls `getsr`, `isspl0`, `splhi`, `kpswtch` and `splx` (0x1530 to 0x1558) on one path and `splx` again (0x15f4); the facts do not show what the calls return or why. The `_r` suffix and the meaning of the meter updates are not shown by the facts. Role (from name): waking a thread blocked on a mutex.
  Reviewed: 2026-11-12

- `rslog` in `IP27/usr/cpu/sysgen/IP27boot/ksync_metered.a(sema.o)` at 0x16cc
  **Inferred.** A 344-byte routine. It reads the halfword at `a2+2` and tests bit 0x1 (beq at 0x16e8), and the return at 0x16fc yields 0. When `a4` is zero (bne at 0x171c) it calls `wchanmeter` (0x172c, with `syncinfo` in `a1`). It calls `mutex_spinlock` on `histlock` (0x1748) and `mutex_spinunlock` on `histlock` (0x1790). The ten doubleword, two word, two byte and one halfword stores at 0x17b0 to 0x1820 lie at higher addresses than the unlock; the facts do not show whether they run under the lock. They go to a record whose address the facts do not resolve, so the layout of that record is an open sub-fact. Role (from name): a logging routine for a sync event.
  Reviewed: 2026-11-12

- `_mraccess` in `IP27/usr/cpu/sysgen/IP27boot/ksync_metered.a(sema.o)` at 0x3890
  **Inferred.** The metered reader access. It gets the meter from `wchanmeter` (0x38b0), calls `mr_access`
  (0x38c0), and when the meter exists it fetches an entry with `mrmeter_getentry` (0x392c) and records type 5
  through `mrmeter_entry` (0x3994). The surrounding stores update meter fields at +0x1c0, +0x1c8, +0x1cc, +0x1d0
  and an `ll`/`sc` counter at +0x198 (0x3940, 0x394c).
  Reviewed: 2026-11-12

- `mraccessf` in `IP27/usr/cpu/sysgen/IP27boot/ksync_metered.a(sema.o)` at 0x39ac
  **Inferred.** A 32-byte forwarder. It calls `_mraccess` (jal at 0x39b8) with its own `a0`, `a2` and `a3` and the return address in `a1`, so its own `a1` is not passed on, and returns the value `_mraccess` returns (0x39c4). It adds no logic of its own.
  Reviewed: 2026-11-12

- `mrupdatef` in `IP27/usr/cpu/sysgen/IP27boot/ksync_metered.a(sema.o)` at 0x39cc
  **Inferred.** A 32-byte forwarder, the write-side twin of `mraccessf` by name. It calls `_mrupdate` (jal at 0x39d8) with its own `a0`, `a2` and `a3` and the return address in `a1`, so its own `a1` is not passed on, and returns that result (0x39e4).
  Reviewed: 2026-11-12

- `_mrupdate` in `IP27/usr/cpu/sysgen/IP27boot/ksync_metered.a(sema.o)` at 0x39ec
  **Inferred.** The metered write-side update, shaped like `_mraccess`. It gets the meter from `wchanmeter`
  (0x3a0c), calls `mr_update` (0x3a1c), and on the metered path calls `mrmeter_entry` with type 6 (0x3ac4). It
  stores meter fields at +0x1a0, +0x1a8, +0x1b0, +0x1b4, +0x1b8 and +0x1d8, and compares the field at +0x1b0
  against a second value (beq at 0x3a6c). The meaning of those fields is not stated in the facts.
  Reviewed: 2026-11-12

- `mrtryupdate` in `IP27/usr/cpu/sysgen/IP27boot/ksync_metered.a(sema.o)` at 0x3b9c
  **Inferred.** The metered try-update. It gets the meter from `wchanmeter` (0x3bb8), calls `mr_tryupdate` (0x3bc4), and returns 0 or 1 (0x3c28). When `mr_tryupdate` returns nonzero (beq at 0x3bcc) and the meter is not null (beq at 0x3bd4), it calls `mrmeter_entry` with `a1` equal to 2 (0x3be4). When that entry result is zero (beq at 0x3bec) it calls `mr_unlock` (0x3c38). The cause of that branch is not shown by the facts.
  Reviewed: 2026-11-12

- `mrunlock` in `IP27/usr/cpu/sysgen/IP27boot/ksync_metered.a(sema.o)` at 0x3c48
  **Inferred.** The metered release. It gets the meter from `wchanmeter` (0x3c64) and calls `mr_unlock` (0x3d08). When bit 0x4 of `a0+4` is set (beq at 0x3c74) and the word at `a0+104` is nonzero (bne at 0x3c80) it calls `bhv_try_deferred_ucalloutp` (0x3d24). On the metered path it calls `mrmeter_getentry` (0x3cf4 with `a2` equal to 2 and `a3` to 0, and 0x3d48 with `a2` equal to 1 and `a3` to 1). The branch at 0x3d94 on the field at `ret(wchanmeter)+520` skips the stores to `+0x1f8`, `+0x200`, `+0x208` and `+0x20c`; the `mraccunlock` call at 0x3dac follows either way. Meter fields from +0x1a4 to +0x20c are updated with plain stores; their meanings are not stated in the facts.
  Reviewed: 2026-11-12

- `mrpromote_or_unlock` in `IP27/usr/cpu/sysgen/IP27boot/ksync_metered.a(sema.o)` at 0x3ee4
  **Inferred.** The metered counterpart of the routine at 0x314c. It gets the meter from `wchanmeter` (0x3f00) and calls `mr_promote_or_unlock` (0x3f0c). It calls `mrmeter_getentry` on three paths, always with `a2` equal to 1 and with `a3` equal to 2 (0x3f2c), 1 (0x3f7c) and 0 (0x3fec). It updates meter fields at +0x19c and +0x1a0 with loads and stores (0x3f3c to 0x3f50) and with `ll`/`sc` on +0x19c (0x3ffc, 0x4008), and stores to +0x1f8, +0x200, +0x208 and +0x20c. The branch on the return of `mr_promote_or_unlock` (beq at 0x3f14) selects the path, and the meaning of each meter field is not stated.
  Reviewed: 2026-11-12

- `mrmeter_entry` in `IP27/usr/cpu/sysgen/IP27boot/ksync_metered.a(sema.o)` at 0x41a0
  **Inferred.** A 384-byte routine. It takes a spin lock on the pool at `a0+304` (`mutex_spinlock` at 0x41d0) and calls `mutex_spinunlock` at two sites (0x4260, 0x42bc). It calls `kmem_zone_free` (0x4274) on the zone pointer at `sym(.sbss)+32` and `kmem_zone_zalloc` (0x42c8) on the same pointer, passing its own `a3` as the second argument. The branch at 0x42f0 goes back to 0x41d0. Halfword and doubleword stores fill a record at 0x421c to 0x425c. The values that select free or allocate are not shown by the facts. Role (from name): a metering entry that allocates or frees through a zone allocator.
  Reviewed: 2026-11-12

- `mrspinaccess` in `IP27/usr/cpu/sysgen/IP27boot/ksync_metered.a(sema.o)` at 0x5014
  **Inferred.** The metered counterpart of the routine at 0x31f8. It calls `wchanmeter` (0x502c) and takes the bit lock on `a0+4` (0x5044). The bne at 0x5054 tests the bits 0x6000 of the lock word. When they are set the branch goes to 0x5074, which stores to the lock word (sw at 0x5080) and calls `mrpsema` (0x50a8) with `a3` holding the `wchanmeter` result, `a6` holding the lock word plus 65536 and `a7` holding 0x10000. When they are clear it stores to the lock word (sw at 0x505c) and reaches the return at 0x506c, which yields the bit-lock result or -1. The beq at 0x50b0 tests the `mrpsema` result against zero; where it goes is not traced by the facts.
  Reviewed: 2026-11-12
