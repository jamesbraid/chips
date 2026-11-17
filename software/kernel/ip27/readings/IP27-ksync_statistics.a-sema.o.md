# Readings: `IP27/usr/cpu/sysgen/IP27boot/ksync_statistics.a(sema.o)`

One entry per routine, filed here from the reading batches by binary.

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
