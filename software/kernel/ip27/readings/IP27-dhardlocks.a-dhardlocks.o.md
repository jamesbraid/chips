# Readings: `IP27/usr/cpu/sysgen/IP27boot/dhardlocks.a(dhardlocks.o)`

One entry per routine, filed here from the reading batches by binary.

- `spinlockdebug` in `IP27/usr/cpu/sysgen/IP27boot/dhardlocks.a(dhardlocks.o)` at 0xcbc
  **Inferred.** Role (from name): the debug form of a spin-lock acquire on the lock record in `a1`. It calls `try_spinlock` at 0xd20 and 0xe44 inside a retry loop, and on the retry path it calls `splx` at 0xe30 and an unknown callee at 0xe38. Load-linked and store-conditional pairs at 0xd00/0xd0c, 0xd64/0xd70 and 0xe64/0xe70 update record fields at offsets 0xa8 through 0xbc. `cmn_err` at 0xf04 is called with level 0 and a `.rodata` string; what it reports is not derived.
  Reviewed: 2026-11-12

- `tryspinlockdebug` in `IP27/usr/cpu/sysgen/IP27boot/dhardlocks.a(dhardlocks.o)` at 0xf14
  **Inferred.** The single-attempt form of the debug lock acquire. It calls `try_spinlock` at 0xf24 with the caller's four arguments, then branches on the result at 0xf2c: a zero result goes to 0xf6c, and the rest of the body writes record fields at offsets 0x2a, 0x2c, 0x38, 0x40 and 0x50 (stores from 0xf44 to 0xf7c). The routine returns 0 or 1 at 0xf64. Which return value means "acquired" is not settled by the facts.
  Reviewed: 2026-11-12

- `spinunlockdebug` in `IP27/usr/cpu/sysgen/IP27boot/dhardlocks.a(dhardlocks.o)` at 0xf80
  **Inferred.** Role (from name): the debug release of a spin lock, working on the record in `a1`. It compares a halfword at offset 0x2a with a halfword global at -0x3be0 (branch at 0xfb0 and 0xfcc), updates fields at offsets 0x40, 0x48, 0x58, 0x60, 0x68 and 0x80, and calls `cmn_err` at 0x1074, 0x108c and 0x10a4 with `.rodata` strings. The calls at 0x1074 and 0x108c are reached from the branches at 0xfb0 and 0xfcc when the two halfwords differ; the call at 0x10a4 is reached from the unsigned comparison at 0xffc. The return value at 0x1054 is not derived.
  Reviewed: 2026-11-12

- `spinunlockdebug` in `IP27/usr/cpu/sysgen/IP27boot/dhardlocks.a(dhardlocks.o)` at 0xf80
  **Inferred.** Role (from name): a debug variant of a spin lock release. It compares a halfword at `a1+0x2a` with a halfword global at `-0x3be0`. A mismatch at 0xfb0 leads to `cmn_err` at 0x1074 (level 4), and a mismatch at 0xfcc leads to `cmn_err` at 0x108c (level 4). A third `cmn_err` at 0x10a4 has level 0 and an argument of -1; the facts do not show what reaches it. The routine also stores halfwords, words and doublewords at offsets such as `+0x2a`, `+0x40`, `+0x58`, `+0x60`, `+0x64`, `+0x68`, `+0x78` and `+0x80`; the stored values and the field meanings are not shown by these facts.
  Reviewed: 2026-11-12

- `bitlockdebug` in `IP27/usr/cpu/sysgen/IP27boot/dhardlocks.a(dhardlocks.o)` at 0x1668 (612 bytes). Grade: inferred.
  Role (from name): a debug variant of a bit-lock acquire. It takes a lock record in `a2` and calls `try_bitlock` at 0x16cc and again at 0x17f8 inside a loop, passing `a0` and `a1` through. It uses `ll`/`sc` pairs on the record offsets 0xa8, 0xac, 0xb0, 0xb8 and 0xbc. Inside the retry loop it calls `splx` (0x17e0) and then an unresolved callee (0x17e8) only when `a5` is nonzero. It calls `cmn_err` (0x18bc) with level 0 and a constant format string. What the record fields mean, and which `try_bitlock` result is success, is not established by these facts.
  Reviewed: 2026-11-12

- `bitlockdebug` in `IP27/usr/cpu/sysgen/IP27boot/dhardlocks.a(dhardlocks.o)` at 0x1668
  **Inferred.** The debug form of a bit-lock acquire on the record in `a2`, the bit-lock counterpart of `spinlockdebug`. It calls `try_bitlock` at 0x16cc and 0x17f8, with `splx` at 0x17e0 and an indirect callee at 0x17e8 between attempts. The load-linked and store-conditional pairs at 0x16b4/0x16c0, 0x1710/0x171c, 0x1818/0x1824 and 0x1850/0x185c use the same record offsets 0xa8 through 0xbc as the spin-lock form.
  Reviewed: 2026-11-12

- `trybitlockdebug` in `IP27/usr/cpu/sysgen/IP27boot/dhardlocks.a(dhardlocks.o)` at 0x18cc
  **Inferred.** The single-attempt bit-lock acquire. It calls `try_bitlock` at 0x18dc and branches on its result at 0x18e4: a zero result goes to 0x1924. The body writes record fields at offsets 0x2a, 0x2c, 0x38, 0x40 and 0x50 (stores from 0x18fc to 0x1934) and returns 0 or 1 at 0x191c. This mirrors `tryspinlockdebug`, and the mapping of return values to acquired or not is not settled by the facts.
  Reviewed: 2026-11-12

- `bitunlockdebug` in `IP27/usr/cpu/sysgen/IP27boot/dhardlocks.a(dhardlocks.o)` at 0x1938
  **Inferred.** Role (from name): the debug release of a bit lock on the record in `a2`. It compares the halfword at offset 0x2a with the global at -0x3be0 (branch at 0x1970), then rewrites record fields at offsets 0x40, 0x48, 0x58, 0x60, 0x64, 0x68, 0x78 and 0x80 (stores from 0x19a8 to 0x1a24). `cmn_err` is called at 0x1a28 and 0x1a40 with `.rodata` strings; what it reports is not derived.
  Reviewed: 2026-11-12

- `_64bitlockdebug` in `IP27/usr/cpu/sysgen/IP27boot/dhardlocks.a(dhardlocks.o)` at 0x1f0c (612 bytes). Grade: inferred.
  The same control shape as `bitlockdebug`, at the same record offsets, with `try_64bitlock` (0x1f70, 0x209c) in place of `try_bitlock`. The `ll`/`sc` accesses at 0xa8, 0xac, 0xb0, 0xb8 and 0xbc are the same width as in the 32-bit routine, so these facts show no 64-bit access in this routine itself; any 64-bit difference is outside what this read covers. Role (from name): the 64-bit counterpart of `bitlockdebug`.
  Reviewed: 2026-11-12

- `_64bitunlockdebug` in `IP27/usr/cpu/sysgen/IP27boot/dhardlocks.a(dhardlocks.o)` at 0x21d0 (280 bytes). Grade: inferred.
  Role (from name): the release side of the debug lock. It compares the halfword at `-0x3be0` with the halfword at `a2+0x2a`. When they are equal it stores to offsets 0x2a, 0x48, 0x60, 0x68, 0x80, 0x78, 0x64 and 0x58 and a doubleword at +0x0, then returns. When they differ it loads and stores a doubleword at +0x40 (the stored value is not shown), then calls `cmn_err` at 0x22c0 with level 4 and at 0x22d8 with level 0. The branch at 0x2244 compares two unresolved registers unsigned and goes to 0x22d0 when the first is below the second. The facts show no backward branch in this routine. The reason for the mismatch is open.
  Reviewed: 2026-11-12
