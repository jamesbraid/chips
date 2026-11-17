# Readings: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_debug.o)`

One entry per routine, filed here from the reading batches by binary.

- `crmFindPP` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_debug.o)` at 0x38 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_debug.o)`.
  Range: 0x38-0x160 (296 bytes).
  It occupies 296 bytes.
  4 such `lw` accesses load 4 bytes from ?, including `lw` at 0x64, `lw` at 0x68, `lw` at 0xd8.
  The `jal` at 0x98 calls crmIsGlobalRegWrite with a0=?, a1=?, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x114 calls crmIsGlobalRegWrite with a0=?, a1=?, a2=?, a3=?.
  The `beq` branch at 0x50 targets 0x13c, is taken when a1 == 0, and falls through when a1 != 0.
  The `bltz` branch at 0x7c targets 0xa8, is taken when at(?) < 0 (signed), and falls through when at(?) >= 0 (signed).
  The `beq` branch at 0xa0 targets 0xc0, is taken when v0(=ret(crmIsGlobalRegWrite)) == 0, and falls through when v0(=ret(crmIsGlobalRegWrite)) != 0.
  The `beq` branch at 0xc0 targets 0x14c, is taken when s0(?) == s1(=a1), and falls through when s0(?) != s1(=a1).
  The `beq` branch at 0xc8 targets 0x154, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `bltz` branch at 0xf8 targets 0x124, is taken when a1(?) < 0 (signed), and falls through when a1(?) >= 0 (signed).
  The `beq` branch at 0x11c targets 0x144, is taken when v0(=ret(crmIsGlobalRegWrite)) == 0, and falls through when v0(=ret(crmIsGlobalRegWrite)) != 0.
  The `beq` branch at 0x128 targets 0x134, is taken when a0(?) == a1(=0x3f), and falls through when a0(?) != a1(=0x3f).
  The `beq` branch at 0x134 targets 0xac and is always taken.
  The `beq` branch at 0x13c targets 0x5c and is always taken.
  The `bne` branch at 0x144 targets 0xc8, is taken when a0(?) != s1(=a1), and falls through when a0(?) == s1(=a1).
  The `beq` branch at 0x14c targets 0xa8 and is always taken.
  The `beq` branch at 0x158 targets 0xd0 and is always taken.
  The return at 0xb8 has v0 = one of -0x1, ?.
