# Readings: `IP27/usr/cpu/sysgen/IP27boot/elsc.o`

One entry per routine, filed here from the reading batches by binary.

- `get_myid` in `IP27/usr/cpu/sysgen/IP27boot/elsc.o` at 0x0 (16 bytes). Grade: inferred.
  It loads the doubleword at the fixed address 0x9200000001000020 and returns it unchanged in `v0`. Role (from name): an id read. Callers are not visible in this read, so the value's meaning stays open.
  Reviewed: 2026-11-12

- `get_myid` in `IP27/usr/cpu/sysgen/IP27boot/elsc.o` at 0x0
  **Inferred.** Role (from facts): returns the doubleword at the fixed address 0x9200000001000020 [@0x4] as its result [@0x8].
  Reviewed: 2026-11-12

- `elsc_lock` in `IP27/usr/cpu/sysgen/IP27boot/elsc.o` at 0xfd0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/elsc.o`.
  Range: 0xfd0-0x10e8 (280 bytes).
  It occupies 280 bytes.
  2 such `ld` accesses load 8 bytes from abs 0x9200000001030100, including `ld` at 0xfdc, `ld` at 0x1048.
  The `jal` at 0x1030 calls sprintf with a0=a0+440, a1=sym(.rodata), a2=a3 at entry (arg3), a3=?, a4=0x3e8.
  The `jal` at 0x1040 calls us_delay with a0=a1 at entry (arg1), a1=?, a2=?, a3=?, a4=0x0, a6=0x30.
  The `jal` at 0x1078 calls elsc_command with a0=a0 at entry (arg0), a1=0x0, a2=?, a3=?.
  The `jal` at 0x1094 calls elsc_parse with a0=a0 at entry (arg0), a1=sp-144, a2=0x0, a3=0x0, a4=ret(elsc_command).
  The `beq` branch at 0x1038 targets 0x1078 and is always taken.
  The `beq` branch at 0x1070 targets 0x10e0, is taken when a4(?) >= s3(?) (unsigned), and falls through when a4(?) < s3(?) (unsigned).
  The `bltz` branch at 0x1080 targets 0x10bc, is taken when v0(=ret(elsc_command)) < 0 (signed), and falls through when v0(=ret(elsc_command)) >= 0 (signed).
  The `bltz` branch at 0x109c targets 0x10bc, is taken when v0(=ret(elsc_parse)) < 0 (signed), and falls through when v0(=ret(elsc_parse)) >= 0 (signed).
  The `beq` branch at 0x10ac targets 0x10bc, is taken when a6(=0x30) == v0(?), and falls through when a6(=0x30) != v0(?).
  The `bne` branch at 0x10b4 targets 0x1040, is taken when s1(=a3) != v0(?), and falls through when s1(=a3) == v0(?).
  The `beq` branch at 0x10e0 targets 0x10bc and is always taken.
  The return at 0x10d8 has v0 = one of ret(elsc_command), ret(elsc_parse), 0x0, -0x79.
