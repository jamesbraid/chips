# Readings: `IP27/usr/cpu/sysgen/IP27boot/ksync.a(mutex.o)`

One entry per routine, filed here from the reading batches by binary.

- `mutex_trylock` in `IP27/usr/cpu/sysgen/IP27boot/ksync.a(mutex.o)` at 0x35c
  **Inferred.** A 48-byte try-lock. It loads the global word at `-0x3fe0` (`ld` at 0x36c) and makes one
  `compare_and_swap_ptr` call on the lock word with 0 in `a1` and that global in `a2` (jal at 0x368). It
  returns 0 or 1 at 0x37c, depending on the swap result (beq at 0x370).
  Reviewed: 2026-11-12

- `mutex_lock` in `IP27/usr/cpu/sysgen/IP27boot/ksync.a(mutex.o)` at 0x454
  **Inferred.** A 64-byte routine that makes the same single `compare_and_swap_ptr` call as the try-lock at 0x35c (jal at 0x468, with 0 in `a1` and the global from `-0x3fe0` in `a2`). When the call returns zero (beq at 0x470) it calls `mutex_wait` (jal at 0x484) with its own `a0` and `a1` and returns that result; when the call returns nonzero it returns the swap result at 0x478. The facts do not say which of the two swap results means the lock was taken.
  Reviewed: 2026-11-12
