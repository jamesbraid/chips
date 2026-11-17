# Readings: `IP27/usr/cpu/sysgen/IP27boot/os.a(timers.o)`

One entry per routine, filed here from the reading batches by binary.

- `ktimer_init` in `IP27/usr/cpu/sysgen/IP27boot/os.a(timers.o)` at 0x0
  **Inferred.** Sets up a timer record passed in a0. It writes two 32-bit fields at +0x2e0 and +0x2e4 and a 64-bit field at +0x2d8, and the 64-bit store takes its value from the doubleword loaded from the fixed address 0x9200000001030100 (0x8). The stored 32-bit values are unknown from these facts, so the initial contents of those two fields are a sub-fact. The record layout comes from the offsets alone.
  Reviewed: 2026-11-12

- `ktimer_switch` in `IP27/usr/cpu/sysgen/IP27boot/os.a(timers.o)` at 0x18
  **Inferred.** Advances a timer record's current slot. It reads the 32-bit index at +0x2e0 and uses it to scale an array at +0x280 (the `ld` at 0x34 and `sd` at 0x40 address a0 + index*8 + 0x280). It loads a 64-bit time from 0x9200000001030100 (0x24), writes it into the 64-bit field at +0x2d8 (0x44), and updates the 32-bit field at +0x2e4 (0x2c) and the index at +0x2e0 (0x4c). The save-and-advance reading comes from the offsets and the single time-like load.
  Reviewed: 2026-11-12

- `ktimer_readticks` in `IP27/usr/cpu/sysgen/IP27boot/os.a(timers.o)` at 0x50
  **Inferred.** The 4-byte word at a0+0x2e0 is compared with a1 at 0x70 (the `bne`). When they differ, the routine returns at 0xac the 8-byte value at (a0 + (a1 << 3)) + 0x280. On the other side it goes on to an 8-byte load at 0x78 whose address the facts do not resolve. A retry `bne` at 0x94 goes back to 0x64 while the 8-byte word at a0+0x2d8 differs from t1 (t1 is not resolved). The return at 0xa4 has no constant value in these facts. Role (from name): a tick-count read; the facts do not show what the load at 0x78 reads.
  Reviewed: 2026-11-12

- `ktimer_readticks` in `IP27/usr/cpu/sysgen/IP27boot/os.a(timers.o)` at 0x50
  **Inferred.** It loads the word at a0+0x2e0 [@0x6c] and the doubleword at a0+0x2d8 [@0x64]. When the word differs from a1 [@0x70 taken] it returns the doubleword at (a0 + (a1 << 0x3)) + 0x280 [@0xac].
  Role (from facts): a value read from a table indexed by a1 [@0x68], returned directly when the word differs from a1 [@0x70 taken].
  Reviewed: 2026-11-12

- `ktimer_read` in `IP27/usr/cpu/sysgen/IP27boot/os.a(timers.o)` at 0xb4
  **Inferred.** The same shape as `ktimer_readticks`: 8-byte loads at +0x2d8 (0xd4, 0xec) and +0x280 (0xd8), a 4-byte word at +0x2e0 compared with a1 at 0xe0 (the `bne` goes to 0x148 when they differ), an 8-byte load at 0xe8 whose address is not resolved, and a retry `bne` at 0x104 back to 0xd4 while the 8-byte word at a0+0x2d8 differs from t8 (not resolved). It stores a 4-byte word at offset +0x0 (the `sw` at 0x138) and an 8-byte word at offset +0x8 (the `sd` at 0x144); the facts do not name the base register of these stores. The return at 0x140 has no constant value. Role (from name): a timer read.
  Reviewed: 2026-11-12

- `ktimer_read` in `IP27/usr/cpu/sysgen/IP27boot/os.a(timers.o)` at 0xb4
  **Inferred.** It loads the doubleword at a0+0x2d8 [@0xd4] and the word at a0+0x2e0 [@0xdc]. When the word differs from a1 [@0xe0 taken] it goes to 0x148 [@0xe0 taken]. It stores a word to a2+0x0 [@0x138] and a doubleword to a2+0x8 [@0x144].
  Role (from facts): a per-index read that writes its outputs through the third argument (a2) [@0x138] [@0x144].
  Reviewed: 2026-11-12

- `ktimer_slptime` in `IP27/usr/cpu/sysgen/IP27boot/os.a(timers.o)` at 0x150
  **Inferred.** Reads the 4-byte state word at a0+0x2e0 (the `lw` at 0x150) and returns 0 at 0x190 when it equals 0, 1 or 2 (the `beq` branches at 0x15c, 0x164 and 0x16c all go to 0x190). Otherwise it loads the 8-byte word at a0+0x2d8 (the `ld` at 0x174) and an 8-byte word at offset 0 of an address the facts do not resolve (the `ld` at 0x178), and returns through 0x188 with no constant value in these facts. Role (from name): a sleep-time query; the branch structure is compatible with that but does not establish it.
  Reviewed: 2026-11-12

- `ktimer_slptime` in `IP27/usr/cpu/sysgen/IP27boot/os.a(timers.o)` at 0x150
  **Inferred.** It loads the word at a0+0x2e0 [@0x150]. When that word is zero [@0x15c taken zero], or equals 1 [@0x164 taken], or equals 2 [@0x16c taken], its return value is 0x0 [@0x190].
  Role (from facts): a three-case test on the word at +0x2e0 whose first three values all return 0x0 [@0x15c taken zero] [@0x190].
  Reviewed: 2026-11-12
