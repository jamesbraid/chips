# Readings: `IP27/usr/cpu/sysgen/IP27boot/ksync_metered.a(sema.o)`

One entry per routine, filed here from the reading batches by binary.

- `rslog` in `IP27/usr/cpu/sysgen/IP27boot/ksync_metered.a(sema.o)` at 0x16cc
  **Inferred.** A 344-byte routine. It reads the halfword at `a2+2` and tests bit 0x1 (beq at 0x16e8), and the return at 0x16fc yields 0. When `a4` is zero (bne at 0x171c) it calls `wchanmeter` (0x172c, with `syncinfo` in `a1`). It calls `mutex_spinlock` on `histlock` (0x1748) and `mutex_spinunlock` on `histlock` (0x1790). The ten doubleword, two word, two byte and one halfword stores at 0x17b0 to 0x1820 lie at higher addresses than the unlock; the facts do not show whether they run under the lock. They go to a record whose address the facts do not resolve, so the layout of that record is an open sub-fact. Role (from name): a logging routine for a sync event.
  Reviewed: 2026-11-12

- `_mraccess` in `IP27/usr/cpu/sysgen/IP27boot/ksync_metered.a(sema.o)` at 0x3890.
  Role (from name): metered access of a synchronization primitive. It calls wchanmeter (0x38b0) with syncinfo and branches on the result (0x38b8). When the result is zero it calls mr_access (0x38c0) and returns at 0x3958. When it is nonzero, the branch goes to 0x396c, where the facts show a call to mrmeter_entry with class 5 (0x3994). It stores to meter offsets 0x1c0 through 0x1d0 (0x390c to 0x391c), calls mrmeter_getentry (0x392c) and, when that is nonzero, runs a load-linked and store-conditional loop (0x3940 to 0x394c) on the word at +0x198. The primitive it meters is not named in the facts.
  Grade: inferred.
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

- `_mrupdate` in `IP27/usr/cpu/sysgen/IP27boot/ksync_metered.a(sema.o)` at 0x39ec.
  Role (from name): update side of _mraccess in the same archive member. It calls wchanmeter (0x3a0c) with syncinfo. When that returns zero it calls mr_update (0x3a1c) and returns. When it returns a meter it branches to 0x3ab8, which calls mrmeter_entry with class 6 (0x3ac4). With a meter present it stores to meter offsets 0x1a0 through 0x1d8, after a 64-bit load at 0x3a44 (address not resolved in the facts). A bit-0x4 test (0x3a90) on a halfword loaded at 0x3a88 gates a halfword store (0x3a98) and a reload and store of the word at meter offset 0x1a0. The field meanings are inferred from the access routine, not stated.
  Grade: inferred.
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

- `mrtryupdate` in `IP27/usr/cpu/sysgen/IP27boot/ksync_metered.a(sema.o)` at 0x3b9c
  **Inferred.** It calls wchanmeter [call 1]. It then calls mr_tryupdate with a0 at entry [call 2]. When the mr_tryupdate result is zero it takes the branch [@0x3bcc taken zero] and returns 0x0. On the nonzero side, when the wchanmeter result is nonzero [@0x3bd4 fall], it calls mrmeter_entry with a0 = ret(wchanmeter) [call 3, @0x3bd4 fall]. When the mrmeter_entry result is zero it calls mr_unlock with a0 at entry [call 4, @0x3bec taken]. Its return value is one of 0x0 and 0x1 [@0x3c28].
  Role (from facts): a metering call [call 1] around a try-update [call 2], returning one of two constants [@0x3c28].
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

- `mrmeter_entry` in `IP27/usr/cpu/sysgen/IP27boot/ksync_metered.a(sema.o)` at 0x41a0
  **Inferred.** It calls mutex_spinlock with a0 = a0+304 [call 1]. It loads the doubleword at abs 0x9200000001030100 [@0x4234] and the doubleword at abs 0xffffffffffffc020 [@0x4248]. It stores halfwords [@0x421c] and doublewords [@0x4230]. When the s1 value is nonzero it calls kmem_zone_free [call 3, @0x4268 fall]. Its return value is one of 0x0 and a value the facts leave open [@0x4294].
  Role (from facts): a spin-locked record update [call 1] with a conditional free [call 3, @0x4268 fall].
  Reviewed: 2026-11-12

- `mrspinaccess` in `IP27/usr/cpu/sysgen/IP27boot/ksync_metered.a(sema.o)` at 0x5014
  **Inferred.** The metered counterpart of the routine at 0x31f8. It calls `wchanmeter` (0x502c) and takes the bit lock on `a0+4` (0x5044). The bne at 0x5054 tests the bits 0x6000 of the lock word. When they are set the branch goes to 0x5074, which stores to the lock word (sw at 0x5080) and calls `mrpsema` (0x50a8) with `a3` holding the `wchanmeter` result, `a6` holding the lock word plus 65536 and `a7` holding 0x10000. When they are clear it stores to the lock word (sw at 0x505c) and reaches the return at 0x506c, which yields the bit-lock result or -1. The beq at 0x50b0 tests the `mrpsema` result against zero; where it goes is not traced by the facts.
  Reviewed: 2026-11-12

- `mrspinupdate` in `IP27/usr/cpu/sysgen/IP27boot/ksync_metered.a(sema.o)` at 0x50c8
  **Inferred.** Acquires a lock whose state word is at a0, with a bit lock on the word at a0+4 taken through `mutex_bitlock` (0x50f8, bit 0x1). `wchanmeter` (0x50e0) is called once at entry, before the bit lock. It tests the low 15 bits of the state word (mask 0x7fff at 0x5108) and writes that word at 0x5114 and 0x5134, then calls `mrpsema` (0x515c) with a1 the `mutex_bitlock` result and a2 of 0x800 or 0x810. At that call a6 holds the word plus 0x10000, which the facts do not show `mrpsema` reading. The branch at 0x5164 goes to 0x5174 when `mrpsema` returns zero and falls through when it returns nonzero. The return at 0x5124 is the `mutex_bitlock` result or -1. This reads as a spin-then-wait acquire on a counted lock, judged from `wchanmeter` and `mrpsema`.
  Reviewed: 2026-11-12
