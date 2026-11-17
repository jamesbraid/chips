# Readings: `IP27/usr/cpu/sysgen/IP27boot/os.a(uuid.o)`

One entry per routine, filed here from the reading batches by binary.

- `uuid_create` in `IP27/usr/cpu/sysgen/IP27boot/os.a(uuid.o)` at 0x28
  **Inferred.** Calls `mutex_lock` at 0x44 (a0 = sym(.bss), a1 = 0x19) and `mutex_unlock` at 0x8c or 0xf4. It stores a halfword at +0x8 (0x5c), a word at +0x0 (0x64), and halfwords at +0x4 (0x78) and +0x6 (0x88); the facts do not name the base register. The byte at sym(.sbss) is tested at 0x54: when it is zero the `beq` goes to 0x104, which calls `nanotime` (a2 = the halfword at sym(.sbss)+16, a3 = the doubleword at sym(.sbss)+8). `get_eaddr` at 0xd4 (a0 = sym(.sbss)+2) is reached from the `beq` at 0x84 when the byte at sym(.sbss)+1 is zero, and a nonzero low byte of its result (the `bne` at 0xe0) goes to the `mutex_unlock` at 0x8c. Role (from name): builds a UUID; the stores at +0x0, +0x4, +0x6 and +0x8 resemble time and clock-sequence fields but the facts do not establish that.
  Reviewed: 2026-11-12

- `uuid_create` in `IP27/usr/cpu/sysgen/IP27boot/os.a(uuid.o)` at 0x28
  **Inferred.** It calls mutex_lock with a0 = sym(.bss) and a1 = 0x19 [call 1]. It stores a word at a0+0x0 [@0x64] and halfwords at a0+0x4, a0+0x6 and a0+0x8 [@0x78] [@0x88] [@0x5c]. When the byte at sym(.sbss) is zero [@0x54 taken] it first calls nanotime [call 5, @0x54 taken] and then reads the doubleword at abs 0x9200000001030100 [@0x138].
  Role (from facts): a locked record update [call 1] that, on the first-use path [@0x54 taken], also calls nanotime [call 5] and reads a doubleword at a constant address [@0x138].
  Reviewed: 2026-11-12
