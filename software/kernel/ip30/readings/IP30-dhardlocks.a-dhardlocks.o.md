# Readings: `IP30/usr/cpu/sysgen/IP30boot/dhardlocks.a(dhardlocks.o)`

One entry per routine, filed here from the reading batches by binary.

- `bitlockdebug` in `IP30/usr/cpu/sysgen/IP30boot/dhardlocks.a(dhardlocks.o)` at 0x1668.
  It works on a lock structure passed in a2. It calls try_bitlock (0x16cc, 0x17f8), updates the lock with plain stores at +0x2a, +0x2c, +0x38, +0x40, +0x50, +0x70, +0x88, +0x90, +0x98 and +0xa0, and with load-linked and store-conditional loops at +0xa8, +0xac, +0xb0, +0xb8 and +0xbc. It calls splx (0x17e0) when a5 is nonzero (0x17d8) and reports through cmn_err (0x18bc) with the value at 0xffffffffaff20000. The "debug" in the name suggests a checking variant, but the facts do not show a debug-only path.
  Grade: inferred.
  Reviewed: 2026-11-12

- `_64bitlockdebug` in `IP30/usr/cpu/sysgen/IP30boot/dhardlocks.a(dhardlocks.o)` at 0x1f0c.
  This is the 64-bit counterpart of bitlockdebug by name. Its facts have the same shape: calls to try_64bitlock (0x1f70, 0x209c), plain stores and load-linked and store-conditional loops at the same lock field offsets, a splx call (0x2084) on the retry path, and a cmn_err report (0x2160). The facts show no layout difference apart from the lock-call name and the addresses.
  Grade: inferred.
  Reviewed: 2026-11-12

- `_64bitunlockdebug` in `IP30/usr/cpu/sysgen/IP30boot/dhardlocks.a(dhardlocks.o)` at 0x21d0.
  It releases the lock in a2. It compares the 16-bit field at +0x2a with the 16-bit value at 0xffffffffffffc3a0, which appears to be the current CPU id given how the lock routines above use it. On a mismatch it branches to 0x22a8 and reports through cmn_err (0x22c0). On the matching path it stores to fields at +0x2a and +0x48 through +0x80 and makes one more 64-bit store (0x2298; its base is not resolved in the facts). The field layout is inferred from the paired lock routines.
  Grade: inferred.
  Reviewed: 2026-11-12
