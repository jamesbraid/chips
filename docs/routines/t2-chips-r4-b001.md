# Tier-2 reading, batch 1 of chips: routine role entries

Each entry names a routine in an IP27 boot-set object by its install path and address. The statements
come only from the rendered instruction facts: registers, loads and stores, calls and constants. Entries
are inferred unless the facts settle the role. Where the facts leave a sub-fact open, the entry says so.

- `eccf_recoverable_threshold` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x3ce18
  **Inferred.** A 188-byte check on a counter record passed in `a1`. It loads and stores the 64-bit word at
  `a1+0x2c0` (`ld` at 0x3ce70, 0x3cec0, 0x3cec8; `sd` at 0x3ceac), reads halfwords at `a1+0x2c8`..`0x2ce`
  (`lhu` at 0x3ce8c), and compares a value loaded from `a1+704` against the constant 0x3938700 (0x3ce84).
  It returns 0 or 1 at 0x3cea4 and 1 at 0x3ceb4. The threshold is applied to the count in that record, but
  which error class the count belongs to is not shown by these facts.

- `ecc_handler` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x3cfcc
  **Inferred.** A 2008-byte error handler that takes an error record in `a1`. It reads the record fields at
  `+0x18`, `+0x2b8` and `+0x2bc`, calls `eccf_recoverable_threshold` (0x3d0cc), and runs cache maintenance
  through the indirect `ecc_cacheOp` with op numbers 0x0, 0x1, 0x3, 0x4, 0x5 and 0x7 (calls at 0x3d144 to
  0x3d664). It also calls `save_cache_error` (0x3d298), `memerror_handle_uce` (0x3d63c), `failsoft_panic_check`
  (0x3d558) and `cmn_err_tag` (0x3d720) with message id 0xb96, and maps the node through the table
  `nasid_to_compact_node` (0x3d6c4 to 0x3d6e8). The meaning of each op number is not shown by the facts.

- `md_perf_stop_count` in `IP27/usr/cpu/sysgen/IP27boot/kernel.o` at 0x42858
  **Inferred.** A 24-byte routine that reads the halfword at `a0+0x1a` (`lh` at 0x42858), stores a 64-bit value
  to an address built from that halfword (`sd` at 0x4286c), and returns the constant 0x9200000001a10000 in
  `v0`. The stored value is not derived in the facts, so the routine's effect on the counter is an open
  sub-fact.

- `mutex_trylock` in `IP27/usr/cpu/sysgen/IP27boot/ksync.a(mutex.o)` at 0x35c
  **Inferred.** A 48-byte try-lock. It loads the global word at `-0x3fe0` (`ld` at 0x36c) and makes one
  `compare_and_swap_ptr` call on the lock word with 0 in `a1` and that global in `a2` (jal at 0x368). It
  returns 0 or 1 at 0x37c, depending on the swap result (beq at 0x370).

- `mutex_lock` in `IP27/usr/cpu/sysgen/IP27boot/ksync.a(mutex.o)` at 0x454
  **Inferred.** A 64-byte blocking lock. It makes the same single `compare_and_swap_ptr` attempt as the
  try-lock at 0x35c (jal at 0x468, with 0 in `a1` and the global from `-0x3fe0` in `a2`). On failure it calls `mutex_wait`
  with its own arguments (jal at 0x484) and returns that result, or the swap result on success.

- `mraccessf` in `IP27/usr/cpu/sysgen/IP27boot/ksync.a(sema.o)` at 0x2978
  **Inferred.** A 456-byte reader-side access on the lock record at `a0`. It takes a bit lock on the word at
  `a0+4` through `mutex_bitlock` (0x29b8), tests the state bits 0x40 of `a0+4` and 0x6000 and 0x8000 of `a0`,
  and records the holder with `mrrecordholder` (0x29fc). When the bit lock is contended it spins with
  `mutex_bittrylock` and `us_delay` (0x2a74), and it calls `nano_delay` with 0x186a0 in `a4` (0x2ad8). On the
  slow path it calls `mrpsema` (0x2b20) and compares the holder count with `mrlock_starve_threshold`
  (0x2b10). The `f` in the name is not explained by the facts.

- `mrupdatef` in `IP27/usr/cpu/sysgen/IP27boot/ksync.a(sema.o)` at 0x2b40
  **Inferred.** A 412-byte write-side access on the lock record at `a0`, shaped like `mraccessf` at 0x2978.
  It takes the bit lock on `a0+4` (jal at 0x2b7c), tests the holder bits with the mask 0x7fff of `a0`
  (0x2b98), records the holder with `mrrecordholder` (0x2c08), and spins with `us_delay` and `nano_delay`.
  It takes the slow path through `mrpsema` (0x2c94), which is passed the masks 0x800800 and 0x800, and
  compares the wait count with `mrlock_starve_threshold` (0x2c80).

- `mrunlock` in `IP27/usr/cpu/sysgen/IP27boot/ksync.a(sema.o)` at 0x2d14
  **Inferred.** A 184-byte release. It takes the bit lock on `a0+4` (jal at 0x2d30), removes the caller from the
  holder record with `mrremoveholder` (0x2d44), and clears bits in the lock word at `a0` (sw at 0x2d64,
  0x2d88, 0x2dc0). On one path it calls `mrvsema` (0x2dbc) with the mask 0xffffffffffff0000, and it drops
  the bit lock with `mutex_bitunlock` (0x2d8c). The branches that select between those paths are at 0x2d58
  and 0x2d74.

- `mrtryupdate` in `IP27/usr/cpu/sysgen/IP27boot/ksync.a(sema.o)` at 0x2fb4
  **Inferred.** A 152-byte non-blocking write attempt. It takes the bit lock on `a0+4` with `mutex_bittrylock`
  (0x2fcc) and returns 0 if that fails (beq at 0x2fd4). Otherwise it tests the lock word at `a0` against the
  mask 0x3fff7fff (0x2fe8) and stores the word back (sw at 0x3008) when the test passes. It records the holder
  with bit 0x4000 set in the word (0x3018), drops the bit lock, and returns 1. It returns 0 when the lock word
  is busy.

- `mrpromote_or_unlock` in `IP27/usr/cpu/sysgen/IP27boot/ksync.a(sema.o)` at 0x314c
  **Inferred.** A 172-byte routine that ends a hold on the lock record at `a0`, under the bit lock on `a0+4`
  (jal at 0x316c). It compares a value with 1 (beq at 0x3184) and checks the holder global at `-0x3fe0`
  (beq at 0x3190). Depending on those tests it either removes the holder with
  `mrremoveholder` (0x3198) or drops the bit lock twice with `mutex_bitunlock` (0x31b4, 0x31e8). Its return
  is 0 or 1 at 0x31d0. Which of the two outcomes is the promotion is not settled by the facts.

- `mrspinaccess` in `IP27/usr/cpu/sysgen/IP27boot/ksync.a(sema.o)` at 0x31f8
  **Inferred.** A 160-byte reader spin-access. It takes the bit lock on `a0+4` (jal at 0x3218). If the writer
  bits 0x6000 of the lock word are clear (bne at 0x3228), it calls `mrpsema` (0x3278) with the reader count
  incremented by 65536 in the lock word. On a failed `mrpsema` it returns to the spin loop at 0x3218 and
  otherwise returns the bit-lock result, or -1 on the exit path.

- `mrspinupdate` in `IP27/usr/cpu/sysgen/IP27boot/ksync.a(sema.o)` at 0x3298
  **Inferred.** A 160-byte writer spin-update, the write-side twin of `mrspinaccess`. It takes the bit lock on
  `a0+4` (jal at 0x32b8) and tests the holder bits with mask 0x7fff of the lock word (bne at 0x32c8). It
  calls `mrpsema` (0x3318) with the masks 0x800 or 0x810 and the lock word incremented by 65536, and loops
  back to 0x32b8 when `mrpsema` fails (beq at 0x3320 and 0x3330).

- `mutex_trylock` in `IP27/usr/cpu/sysgen/IP27boot/ksync_metered.a(mutex.o)` at 0x5f0
  **Inferred.** The metered try-lock. It calls `wchanmeter` (0x604) to get a per-channel meter record and makes
  the same single `compare_and_swap_ptr` attempt on the lock word as the unmetered `mutex_trylock` (0x618).
  Around that it updates the meter fields with `ll`/`sc` on `meter+0x38` (0x638, 0x6a4) and plain stores to
  `+0x3c`, `+0x40`, `+0x48`, `+0x50` and `+0x70`. Those stores count attempts and results. The meter field
  meanings are not stated in the facts.

- `mutex_lock` in `IP27/usr/cpu/sysgen/IP27boot/ksync_metered.a(mutex.o)` at 0x760
  **Inferred.** The metered blocking lock. It gets the meter from `wchanmeter` (0x778), attempts the
  `compare_and_swap_ptr` on the lock word (0x79c), and on failure updates the meter with `ll`/`sc` on
  `meter+0x28` (0x7c4, 0x858) and stores to `+0x30`, `+0x40`, `+0x48`, `+0x50`, `+0x5c`, `+0x60` and `+0x68`.
  It then calls `mutex_wait` (0x874) with its own arguments and returns 0 or 1 at 0x844.

- `mutex_wake_r` in `IP27/usr/cpu/sysgen/IP27boot/ksync_metered.a(mutex.o)` at 0x13c8
  **Inferred.** A 684-byte wake routine for a mutex. It takes the nested bit lock at the record offset 132 of
  the owner (`nested_bitlock` at 0x14cc and 0x1608), unblocks a waiting thread with `thread_unblock` (0x150c),
  and drops priority inheritance with `drop_inheritance` (0x1618). Interrupt level is read with `getsr` and `isspl0`,
  raised with `splhi` (0x1548), and restored with `splx` (0x1558, 0x15f4). On one path it yields through
  `kpswtch` (0x1550). The `_r` suffix and the meaning of its meter updates are not shown by the facts.

- `rslog` in `IP27/usr/cpu/sysgen/IP27boot/ksync_metered.a(sema.o)` at 0x16cc
  **Inferred.** A 344-byte logging routine for a sync event. It reads the halfword at `a2+2` and tests bit 0x1
  (beq at 0x16e8), gets the meter from `wchanmeter` (0x172c), and brackets the log update with
  `mutex_spinlock` and `mutex_spinunlock` on the history lock `histlock` (0x1748, 0x1790). It writes ten
  doubleword fields and several word and byte fields into a record whose address the facts do not resolve, so
  the layout of that record is an open sub-fact.

- `_mraccess` in `IP27/usr/cpu/sysgen/IP27boot/ksync_metered.a(sema.o)` at 0x3890
  **Inferred.** The metered reader access. It gets the meter from `wchanmeter` (0x38b0), calls `mr_access`
  (0x38c0), and when the meter exists it fetches an entry with `mrmeter_getentry` (0x392c) and records type 5
  through `mrmeter_entry` (0x3994). The surrounding stores update meter fields at +0x1c0, +0x1c8, +0x1cc, +0x1d0
  and an `ll`/`sc` counter at +0x198 (0x3940, 0x394c).

- `mraccessf` in `IP27/usr/cpu/sysgen/IP27boot/ksync_metered.a(sema.o)` at 0x39ac
  **Inferred.** A 32-byte forwarder. It calls `_mraccess` (jal at 0x39b8) with its own four argument registers
  and the return address, and returns the value `_mraccess` returns (0x39c4). It adds no logic of its own.

- `mrupdatef` in `IP27/usr/cpu/sysgen/IP27boot/ksync_metered.a(sema.o)` at 0x39cc
  **Inferred.** A 32-byte forwarder, the write-side twin of `mraccessf`. It calls `_mrupdate` (jal at 0x39d8)
  with its own arguments and the return address, and returns that result (0x39e4).

- `_mrupdate` in `IP27/usr/cpu/sysgen/IP27boot/ksync_metered.a(sema.o)` at 0x39ec
  **Inferred.** The metered write-side update, shaped like `_mraccess`. It gets the meter from `wchanmeter`
  (0x3a0c), calls `mr_update` (0x3a1c), and on the metered path calls `mrmeter_entry` with type 6 (0x3ac4). It
  stores meter fields at +0x1a0, +0x1a8, +0x1b0, +0x1b4, +0x1b8 and +0x1d8, and compares the field at +0x1b0
  against a second value (beq at 0x3a6c). The meaning of those fields is not stated in the facts.

- `mrtryupdate` in `IP27/usr/cpu/sysgen/IP27boot/ksync_metered.a(sema.o)` at 0x3b9c
  **Inferred.** The metered try-update. It gets the meter from `wchanmeter` (0x3bb8), calls `mr_tryupdate`
  (0x3bc4), and returns 0 or 1 (0x3c28). When the try succeeds it records a type 2 entry with `mrmeter_entry`
  (0x3be4). On one branch, when that entry result is zero, it calls `mr_unlock` (0x3c38). The cause of that
  branch is not shown by the facts.

- `mrunlock` in `IP27/usr/cpu/sysgen/IP27boot/ksync_metered.a(sema.o)` at 0x3c48
  **Inferred.** The metered release. It gets the meter from `wchanmeter` (0x3c64), fetches entries twice with
  `mrmeter_getentry` (0x3cf4 with type 2, 0x3d48 with type 1), and calls `mr_unlock` (0x3d08). It calls
  `bhv_try_deferred_ucalloutp` (0x3d24) when the word at `a0+104` is nonzero, and a later branch on the
  record at `ret(wchanmeter)+520` may reach `mraccunlock` (0x3dac). Meter fields from +0x1a4 to +0x20c are
  updated with plain stores; their meanings are not stated in the facts.

- `mrpromote_or_unlock` in `IP27/usr/cpu/sysgen/IP27boot/ksync_metered.a(sema.o)` at 0x3ee4
  **Inferred.** The metered promote-or-unlock. It gets the meter from `wchanmeter` (0x3f00), calls
  `mr_promote_or_unlock` (0x3f0c), and records an entry with `mrmeter_getentry` on one of three branches, of type 2 (0x3f2c), type 1 (0x3f7c)
  or type 0 (0x3fec). It updates meter fields at +0x19c and +0x1a0 with `ll`/`sc` on +0x19c (0x3ffc, 0x4008)
  and stores to +0x1f8, +0x200, +0x208 and +0x20c. The branch on the return of `mr_promote_or_unlock`
  (beq at 0x3f14) selects the path, and the meaning of each meter field is not stated.

- `mrmeter_entry` in `IP27/usr/cpu/sysgen/IP27boot/ksync_metered.a(sema.o)` at 0x41a0
  **Inferred.** A 384-byte allocator for meter entries. It takes a spin lock on the pool at `a0+304`
  (`mutex_spinlock` at 0x41d0) and either frees an entry with `kmem_zone_free` (0x4274) or allocates one with
  `kmem_zone_zalloc` (0x42c8) from the zone pointer at `sym(.sbss)+32`. It then fills the entry with halfword
  and doubleword stores and releases the lock (0x4260, 0x42bc). The argument `a3` is passed to the allocator
  as its second argument. The mode values that select free or allocate are not named by the facts.

- `mrspinaccess` in `IP27/usr/cpu/sysgen/IP27boot/ksync_metered.a(sema.o)` at 0x5014
  **Inferred.** The metered reader spin-access. It calls `wchanmeter` (0x502c), takes the bit lock on `a0+4`
  (0x5044), and tests the writer bits 0x6000 of the lock word (0x5054). When they are clear it calls `mrpsema`
  (0x50a8) with the reader count incremented by 65536, retries on failure (beq at 0x50c0 back to 0x5044), and
  returns the bit-lock result or -1 (0x506c).
