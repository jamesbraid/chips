# Readings: `IP27/usr/cpu/sysgen/IP27boot/ksync.a(sema.o)`

One entry per routine, filed here from the reading batches by binary.

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

- `mrspinaccess` in `IP27/usr/cpu/sysgen/IP27boot/ksync.a(sema.o)` at 0x31f8
  **Inferred.** It calls mutex_bitlock with a0 = a0+4 and a1 = 0x1 [call 1]. It then calls mrpsema with a0 at entry [call 2, @0x3228 taken]. When the mrpsema result is zero it takes the branch [@0x3280 taken zero]. Its return value is one of the mutex_bitlock result and -0x1 [@0x3244].
  Role (from facts): a bit lock [call 1] followed by a semaphore call [call 2], with a branch on a zero result [@0x3280 taken zero].
  Reviewed: 2026-11-12

- `mrspinupdate` in `IP27/usr/cpu/sysgen/IP27boot/ksync.a(sema.o)` at 0x3298
  **Inferred.** A 160-byte routine on the lock record at `a0`, the write-side counterpart of `mrspinaccess` by name. It takes the bit lock on `a0+4` (jal at 0x32b8) and loads the lock word (0x32c0). The bne at 0x32c8 tests the mask 0x7fff of the lock word; when it is nonzero the branch goes to 0x32ec, which stores to the lock word (sw at 0x32f4) and calls `mrpsema` (0x3318) with `a2` holding 0x800 and `a4` holding 0x810 and `a5` holding the lock word plus 65536; the facts do not show which of those registers are arguments. When it is zero the code stores to the lock word (sw at 0x32d4) and reaches the return at 0x32e4, which yields the `mutex_bitlock` result or -1. The beq at 0x3320 tests the `mrpsema` result against zero; where it goes is not traced by the facts. Role (from name): a spinning write-side update of a multiple-reader lock.
  Reviewed: 2026-11-12
