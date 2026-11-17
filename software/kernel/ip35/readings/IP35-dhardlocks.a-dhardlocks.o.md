# Readings: `IP35/usr/cpu/sysgen/IP35boot/dhardlocks.a(dhardlocks.o)`

One entry per routine, filed here from the reading batches by binary.

- `bitlockdebug` in `IP35/usr/cpu/sysgen/IP35boot/dhardlocks.a(dhardlocks.o)` at 0x1668
  It reads the doubleword at 0x9200000001030100 twice and calls `try_bitlock` at 0x16cc with its own arguments. The `ll`/`sc` pairs on the words at a2+0xb8 and a2+0xbc update the lock record. A second path calls `splx`, makes an indirect call at 0x17e8 whose target is not resolved, retries `try_bitlock` at 0x17f8, and reports through `cmn_err` at 0x18bc with the doubleword at 0x9200000001030100 as an argument.
  Grade: inferred.
  Reviewed: 2026-11-12

- `_64bitlockdebug` in `IP35/usr/cpu/sysgen/IP35boot/dhardlocks.a(dhardlocks.o)` at 0x1f0c
  It has the same calls as `bitlockdebug`, with `try_64bitlock` at 0x1f70 and 0x209c in place of `try_bitlock`, `splx` at 0x2084, an indirect call at 0x208c, and a `cmn_err` report at 0x2160. The lock fields it updates are known only by their offsets from a2. The name suggests the 64-bit form of the debug lock acquire, which matches the call pattern.
  Grade: inferred.
  Reviewed: 2026-11-12

- `_64bitunlockdebug` in `IP35/usr/cpu/sysgen/IP35boot/dhardlocks.a(dhardlocks.o)` at 0x21d0
  It compares the halfword at a2+0x2a with the processor number at -0x3bd8 (branch at 0x2208), and on a mismatch goes to 0x22a8. There the value at a2+0x40 is read, a store to a2+0x40 follows (the stored value is not shown), and `cmn_err` at 0x22c0 reports the value plus one. The match path updates fields at a2+0x2a and a2+0x48 through a2+0x80, and a second `cmn_err` at 0x22d8 is reached from the branch at 0x2244. The name suggests the unlock side of the debug lock, but the facts do not show what the field offsets mean.
  Grade: inferred.
  Reviewed: 2026-11-12
