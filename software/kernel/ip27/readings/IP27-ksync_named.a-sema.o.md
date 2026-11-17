# Readings: `IP27/usr/cpu/sysgen/IP27boot/ksync_named.a(sema.o)`

One entry per routine, filed here from the reading batches by binary.

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
