# Readings: `IP35/usr/cpu/sysgen/IP35boot/os.a(pda.o)`

One entry per routine, filed here from the reading batches by binary.

- `doacvec` in `IP35/usr/cpu/sysgen/IP35boot/os.a(pda.o)` at 0x1c00 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/os.a(pda.o)`.
  Range: 0x1c00-0x1c74 (116 bytes).
  It occupies 116 bytes.
  The `lbu` at 0x1c00 loads 1 byte from abs 0xffffffffffffc080.
  The `ld` at 0x1c14 loads 8 bytes from abs 0x92000000017a0038.
  The `lbu` at 0x1c2c loads 1 byte from abs 0xffffffffffffc081.
  The `sb` at 0x1c38 stores 1 byte to abs 0xffffffffffffc04e.
  The `sb` at 0x1c3c stores 1 byte to abs 0xffffffffffffc081.
  The `lw` at 0x1c40 loads 4 bytes from abs 0xffffffffffffc084.
  The `ld` at 0x1c54 loads 8 bytes from abs 0xffffffffffffc0d0.
  The `sd` at 0x1c64 stores 8 bytes to abs 0xffffffffffffc0d0.
  The `jal` at 0x1c24 calls panicspin with a0=0x92000000017a0038, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1c4c calls tlbflush_rand with a0=[-0x3f7c], a1=?, a2=?, a3=?.
  The `jal` at 0x1c60 calls tlbflush with a0=[-0x3f30]:8, a1=?, a2=?, a3=?.
  The `bne` branch at 0x1c0c targets 0x1c24, is taken when at(=[-0x3f80]:1) != 0, and falls through when at(=[-0x3f80]:1) == 0.
  The `beq` branch at 0x1c1c targets 0x1c2c, is taken when (v0(=[0x92000000017a0038]:8) & 0x1) == 0, and falls through when (v0(=[0x92000000017a0038]:8) & 0x1) != 0.
  The `beq` branch at 0x1c30 targets 0x1c40, is taken when v1(=[-0x3f7f]:1) == 0, and falls through when v1(=[-0x3f7f]:1) != 0.
  The `beq` branch at 0x1c44 targets 0x1c54, is taken when a0(=[-0x3f7c]) == 0, and falls through when a0(=[-0x3f7c]) != 0.
  The `beq` branch at 0x1c58 targets 0x1c6c, is taken when a0(=[-0x3f30]:8) == 0, and falls through when a0(=[-0x3f30]:8) != 0.
  The return at 0x1c6c has v0 = one of ?, ret(tlbflush).
