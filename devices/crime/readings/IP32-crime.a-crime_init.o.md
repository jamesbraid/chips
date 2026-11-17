# Readings: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_init.o)`

One entry per routine, filed here from the reading batches by binary.

- `gbeProbe` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_init.o)` at 0x0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_init.o)`.
  Range: 0x0-0x44 (68 bytes).
  It occupies 68 bytes.
  The `lw` at 0x0 loads 4 bytes from a0 (arg0 at entry) +0x14.
  The `sw` at 0x20 stores 4 bytes to a0 (arg0 at entry) +0x0.
  The `lw` at 0x28 loads 4 bytes from a0 (arg0 at entry) +0x10000.
  The `sw` at 0x40 stores 4 bytes to a0 (arg0 at entry) +0x10000.
  The `bne` branch at 0xc targets 0x1c, is taken when v0(?) < 0x1 (unsigned), and falls through when v0(?) >= 0x1 (unsigned).
  The `beq` branch at 0x34 targets 0x14, is taken when (v1(=[a0+65536]) & a1(=0xffffffff80000000)) == 0, and falls through when (v1(=[a0+65536]) & a1(=0xffffffff80000000)) != 0.
  The return at 0x14 has v0 = ?.
  The return at 0x3c has v0 = ?.

- `getNvramTiming` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_init.o)` at 0x88 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_init.o)`.
  Range: 0x88-0xec (100 bytes).
  It occupies 100 bytes.
  The `lbu` at 0xb0 loads 1 byte from ret(kopt_find) +0x0.
  The `jal` at 0x94 calls kopt_find with a0=sym(.rodata), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0xa8 targets 0xd0, is taken when v0(=ret(kopt_find)) == 0, and falls through when v0(=ret(kopt_find)) != 0.
  The `beq` branch at 0xb4 targets 0xe4, is taken when a2(=[ret(kopt_find)]:1) == a3(=0x68), and falls through when a2(=[ret(kopt_find)]:1) != a3(=0x68).
  The `beq` branch at 0xbc targets 0xe4, is taken when a2(=[ret(kopt_find)]:1) == a4(=0x48), and falls through when a2(=[ret(kopt_find)]:1) != a4(=0x48).
  The `beq` branch at 0xc4 targets 0xdc, is taken when a2(=[ret(kopt_find)]:1) == a1(=0x6c), and falls through when a2(=[ret(kopt_find)]:1) != a1(=0x6c).
  The `beq` branch at 0xcc targets 0xdc, is taken when a2(=[ret(kopt_find)]:1) == a5(=0x4c), and falls through when a2(=[ret(kopt_find)]:1) != a5(=0x4c).
  The `beq` branch at 0xdc targets 0xd4 and is always taken.
  The `beq` branch at 0xe4 targets 0xd4 and is always taken.
  The return at 0xd4 has v0 = one of 0x0, 0x4, 0x9.

- `crimeInitInfo` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_init.o)` at 0xec (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_init.o)`.
  Range: 0xec-0x498 (940 bytes).
  It occupies 940 bytes.
  2 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x0, including `lw` at 0xec, `lw` at 0x148.
  The `sw` at 0x108 stores 4 bytes to a1 (arg1 at entry) +0x0.
  The `ld` at 0x10c loads 8 bytes from abs 0xffffffffb4000000.
  2 such `sb` accesses store 1 byte to a2 (arg2 at entry) +0x29, including `sb` at 0x118, `sb` at 0x144.
  The `lw` at 0x11c loads 4 bytes from a0 (arg0 at entry) +0x400.
  The `sb` at 0x170 stores 1 byte to a2 (arg2 at entry) +0x2a.
  The `sb` at 0x180 stores 1 byte to a2 (arg2 at entry) +0x28.
  4 such `lh` accesses load 2 bytes from sym(crimeBoards) +0x22, including `lh` at 0x1a4, `lh` at 0x2d0, `lh` at 0x3b0.
  The `lw` at 0x1bc loads 4 bytes from sym(crmFpPrbState) +0x0.
  The `lbu` at 0x1c8 loads 1 byte from a2 (arg2 at entry) +0x2e.
  3 such `sb` accesses store 1 byte to a2 (arg2 at entry) +0x2f, including `sb` at 0x1fc, `sb` at 0x214, `sb` at 0x2e8.
  The `sb` at 0x210 stores 1 byte to a2 (arg2 at entry) +0x2b.
  3 such `lw` accesses load 4 bytes from a2 (arg2 at entry) +0x30, including `lw` at 0x220, `lw` at 0x278, `lw` at 0x300.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0x23c, `lw` at 0x250.
  2 such `sw` accesses store 4 bytes to ?, including `sw` at 0x248, `sw` at 0x25c.
  The `lbu` at 0x27c loads 1 byte from a2 (arg2 at entry) +0x2c.
  The `lh` at 0x280 loads 2 bytes from [a2+48] +0x8.
  The `sh` at 0x284 stores 2 bytes to a2 (arg2 at entry) +0x20.
  The `lh` at 0x288 loads 2 bytes from [a2+48] +0xa.
  The `sw` at 0x290 stores 4 bytes to a2 (arg2 at entry) +0x24.
  2 such `sh` accesses store 2 bytes to a2 (arg2 at entry) +0x22, including `sh` at 0x298, `sh` at 0x2b0.
  The `lbu` at 0x29c loads 1 byte from a2 (arg2 at entry) +0x2d.
  The `lhu` at 0x2a8 loads 2 bytes from a2 (arg2 at entry) +0x22.
  The `lw` at 0x2c0 loads 4 bytes from a2 (arg2 at entry) +0xe4.
  5 such `sw` accesses store 4 bytes to a2 (arg2 at entry) +0x30, including `sw` at 0x2f0, `sw` at 0x31c, `sw` at 0x344.
  12 such `sw` accesses store 4 bytes to a2 (arg2 at entry) +0xe4, including `sw` at 0x2fc, `sw` at 0x318, `sw` at 0x350.
  The `lw` at 0x304 loads 4 bytes from [a2+48] +0x4.
  The `lh` at 0x320 loads 2 bytes from sym(crimeBoards) +0x32.
  The `sb` at 0x36c stores 1 byte to a2 (arg2 at entry) +0x2e.
  The `lbu` at 0x3fc loads 1 byte from a2 (arg2 at entry) +0x88.
  The `lbu` at 0x46c loads 1 byte from a2 (arg2 at entry) +0x87.
  The `jal` at 0x26c calls strncpy with a0=a2 at entry (arg2), a1=sym(.rodata)+8, a2=0x10, a3=[a2+48], a6=a2+52, a7=a2+56.
  The `jal` at 0x334 calls i2cfp_DMI2_KernelEDID with a0=a1 at entry (arg1), a1=a2 at entry (arg2), a2=0x0, a3=sym(crimeBoards), a4=[[a2+48]+4], a5=[sym(crimeBoards)+50]:2, a6=0x84, a7=[sym(crm_fbdepth)].
  The `jal` at 0x354 calls crime_i2cFpProbe with a0=a1 at entry (arg1), a1=[sym(crmFpPrbState)], a2=?, a3=sym(crimeBoards).
  The `jal` at 0x378 calls getNvramTiming with a0=?, a1=?, a2=?, a3=sym(crimeBoards), a4=0xaa000, a5=0x30000000, a7=[a2+228].
  The `beq` branch at 0x138 targets 0x148, is taken when (at(=[a0+1024]) & 0x1) == 0, and falls through when (at(=[a0+1024]) & 0x1) != 0.
  The `beq` branch at 0x188 targets 0x194, is taken when a7(=[sym(gbe_gammawar)]) == 0, and falls through when a7(=[sym(gbe_gammawar)]) != 0.
  The `beq` branch at 0x194 targets 0x2c0, is taken when a3 == 0, and falls through when a3 != 0.
  The `beq` branch at 0x1a8 targets 0x2dc, is taken when a0(=[sym(crimeBoards)+34]:2) == v0(=0x2), and falls through when a0(=[sym(crimeBoards)+34]:2) != v0(=0x2).
  The `beq` branch at 0x1c0 targets 0x354, is taken when a1(=[sym(crmFpPrbState)]) == 0, and falls through when a1(=[sym(crmFpPrbState)]) != 0.
  The `beq` branch at 0x1d0 targets 0x2ec, is taken when a2(?) == a4(=0x82), and falls through when a2(?) != a4(=0x82).
  The `beq` branch at 0x1d8 targets 0x344, is taken when a2(?) == a5(=0x83), and falls through when a2(?) != a5(=0x83).
  The `beq` branch at 0x1e4 targets 0x300, is taken when a2(?) == a6(=0x84), and falls through when a2(?) != a6(=0x84).
  The `beq` branch at 0x1f0 targets 0x2e4, is taken when a7(=[sym(crm_fbdepth)]) == v0(=0x10), and falls through when a7(=[sym(crm_fbdepth)]) != v0(=0x10).
  The `beq` branch at 0x208 targets 0x21c, is taken when t1(=[sym(physmem)]) >= 0x2001 (unsigned), and falls through when t1(=[sym(physmem)]) < 0x2001 (unsigned).
  The `bgtz` branch at 0x258 targets 0x234, is taken when a0(?) > 0 (signed), and falls through when a0(?) <= 0 (signed).
  The `beq` branch at 0x294 targets 0x2b4, is taken when a3(=[a2+44]:1) == 0, and falls through when a3(=[a2+44]:1) != 0.
  The `beq` branch at 0x2a0 targets 0x2b4, is taken when a5(=[a2+45]:1) == 0, and falls through when a5(=[a2+45]:1) != 0.
  The `beq` branch at 0x2c4 targets 0x378, is taken when a7(=[a2+228]) == 0, and falls through when a7(=[a2+228]) != 0.
  The `bne` branch at 0x2d4 targets 0x1b0, is taken when t0(=[sym(crimeBoards)+34]:2) != v0(=0x2), and falls through when t0(=[sym(crimeBoards)+34]:2) == v0(=0x2).
  The `beq` branch at 0x2dc targets 0x1b8 and is always taken.
  The `beq` branch at 0x2e4 targets 0x200 and is always taken.
  The `beq` branch at 0x2f8 targets 0x1e8 and is always taken.
  The `beq` branch at 0x310 targets 0x320, is taken when a4(=[[a2+48]+4]) == a5(=0x400), and falls through when a4(=[[a2+48]+4]) != a5(=0x400).
  The `bne` branch at 0x324 targets 0x1ec, is taken when a5(=[sym(crimeBoards)+50]:2) != 0, and falls through when a5(=[sym(crimeBoards)+50]:2) == 0.
  The `beq` branch at 0x33c targets 0x1ec and is always taken.
  The `beq` branch at 0x34c targets 0x1e8 and is always taken.
  The `beq` branch at 0x370 targets 0x1cc and is always taken.
  The `beq` branch at 0x384 targets 0x3c4, is taken when v0(=ret(getNvramTiming)) == 0, and falls through when v0(=ret(getNvramTiming)) != 0.
  The `bne` branch at 0x3b4 targets 0x1b4, is taken when a2(=[sym(crimeBoards)+34]:2) != a1(=0x2), and falls through when a2(=[sym(crimeBoards)+34]:2) == a1(=0x2).
  The `beq` branch at 0x3bc targets 0x2dc and is always taken.
  The `bne` branch at 0x3f4 targets 0x1b0, is taken when a6(=[sym(crimeBoards)+34]:2) != a1(=0x2), and falls through when a6(=[sym(crimeBoards)+34]:2) == a1(=0x2).
  The `beq` branch at 0x400 targets 0x1b8, is taken when v0(=[a2+136]:1) == 0, and falls through when v0(=[a2+136]:1) != 0.
  The `beq` branch at 0x408 targets 0x41c, is taken when t0(?) == 0, and falls through when t0(?) != 0.
  The `beq` branch at 0x414 targets 0x1b8 and is always taken.
  The `beq` branch at 0x41c targets 0x430, is taken when t2(?) == 0, and falls through when t2(?) != 0.
  The `beq` branch at 0x428 targets 0x1b8 and is always taken.
  The `beq` branch at 0x430 targets 0x444, is taken when t8(?) == 0, and falls through when t8(?) != 0.
  The `beq` branch at 0x43c targets 0x1b8 and is always taken.
  The `beq` branch at 0x444 targets 0x458, is taken when ra(?) == 0, and falls through when ra(?) != 0.
  The `beq` branch at 0x450 targets 0x1b8 and is always taken.
  The `beq` branch at 0x458 targets 0x46c, is taken when v1(?) == 0, and falls through when v1(?) != 0.
  The `beq` branch at 0x464 targets 0x1b8 and is always taken.
  The `beq` branch at 0x474 targets 0x484, is taken when (v0(=[a2+135]:1) & 0x1) == 0, and falls through when (v0(=[a2+135]:1) & 0x1) != 0.
  The `beq` branch at 0x47c targets 0x1b8 and is always taken.
  The `beq` branch at 0x484 targets 0x1bc, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0x490 targets 0x1b8 and is always taken.
  The return at 0x2b8 has v0 = ret(strncpy).

- `crimeInitInfo` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_init.o)` at 0xec (n32).
  Inferred: it fills the video-format fields of the record in a2 from the board state, because it
  stores the address of the `crimeVTimings` table at +0x30 (the `sw` at 0x2f0) and picks the word at
  +0xe4 from the byte at +0x2e of that record (the `lbu` at 0x1c8). It reads the first word of the
  block in a1 (the `lw` at 0xec), keeps the bits selected by 0x30000000, ORs in 0xaa000 and stores
  it back (the `sw` at 0x108); it stores the low four bits of the 8-byte CRIME ID-Revision register
  at +0x29 (the `ld` at 0x10c, linked row CRIME 0x0 ID-Revision, the `sb` at 0x118), adding 1 (the
  `sb` at 0x144) when bit 0 of the value loaded from +0x400 of a0 (the `lw` at 0x11c) is set, and
  four-bit fields of the first word of the a1 block at +0x2a and +0x28 (the `sb` at 0x170 and
  0x180); it calls `strncpy` with a2, `.rodata`+16 and 0x10 as its first three arguments (the `jal`
  at 0x26c), and `i2cfp_DMI2_KernelEDID` with a1 and a2 as its first two arguments (the `jal` at
  0x334). It copies two halfwords from the table at the pointer in +0x30 of the record into +0x20
  and +0x22 (the `lh` at 0x280 and 0x288, the `sh` at 0x284 and 0x298), stores 0x1f0 at +0x24 (the
  `sw` at 0x290), and when the bytes at +0x2c and +0x2d are both nonzero, doubles the halfword at
  +0x22 (the `lhu` at 0x2a8 and the `sh` at 0x2b0). The byte at +0x2e picks the word at +0xe4: 0x82
  stores 0x4 (the `sw` at 0x2fc), 0x83 stores 0x9 (the `sw` at 0x350), and 0x84 stores 0xf (the `sw`
  at 0x318) unless the word at +4 of the table is 0x400 (the `beq` at 0x310). The word at
  `crm_fbdepth` picks 0x10 or 0x20 for the byte at +0x2f (the `sb` at 0x2e8 and 0x1fc), and when
  `physmem` is below 0x2001 it stores 0 at +0x2b and 0x10 at +0x2f (the `sb` at 0x210 and 0x214).
  When a3 is zero (the `beq` at 0x194) and the word at +0xe4 is still zero (the `beq` at 0x2c4), it
  calls `getNvramTiming` (the `jal` at 0x378) and stores the result at +0xe4 (the `sw` at 0x388). A
  nonzero result selects the `crimeVTimings` entry at 48 bytes per index and stores its address at
  +0x30 (the `sw` at 0x3ac); a zero result makes the word at +0xe4 `crm_default_vtiming` (the `sw`
  at 0x3d8) and stores the matching table address at +0x30 (the `sw` at 0x3ec). The loop from 0x234
  to 0x25c copies twelve words of the table at +0x30 into the record from +0x34 on, two words a pass
  (the `lw` at 0x23c and 0x250, the `sw` at 0x248 and 0x25c).
  Unknown: the register writes made by `getNvramTiming`, `crime_i2cFpProbe` and
  `i2cfp_DMI2_KernelEDID`, which have no committed entries.
  Evidence grade: inferred.

- `gbeSetTimingRegs` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_init.o)` at 0x498 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_init.o)`.
  Range: 0x498-0x974 (1244 bytes).
  It occupies 1244 bytes.
  The `lw` at 0x4a4 loads 4 bytes from a1 (arg1 at entry) +0x30.
  The `lw` at 0x4b0 loads 4 bytes from a0 (arg0 at entry) +0x4.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x4, including `sw` at 0x4c8, `sw` at 0x840.
  The `sw` at 0x4d4 stores 4 bytes to a0 (arg0 at entry) +0x10004.
  The `lh` at 0x4d8 loads 2 bytes from [a1+48] +0x24.
  The `lh` at 0x4dc loads 2 bytes from [a1+48] +0x26.
  The `sw` at 0x4f0 stores 4 bytes to a0 (arg0 at entry) +0x10008.
  The `lh` at 0x4f4 loads 2 bytes from [a1+48] +0x1a.
  The `lh` at 0x4f8 loads 2 bytes from [a1+48] +0x1c.
  The `sw` at 0x50c stores 4 bytes to a0 (arg0 at entry) +0x1000c.
  4 such `lh` accesses load 2 bytes from [a1+48] +0x20, including `lh` at 0x510, `lh` at 0x5bc, `lh` at 0x5e0.
  3 such `lh` accesses load 2 bytes from [a1+48] +0x22, including `lh` at 0x514, `lh` at 0x5c0, `lh` at 0x6ac.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x10010, including `sw` at 0x528, `sw` at 0x588.
  3 such `lh` accesses load 2 bytes from [a1+48] +0x14, including `lh` at 0x52c, `lh` at 0x6e8, `lh` at 0x724.
  2 such `lh` accesses load 2 bytes from [a1+48] +0x16, including `lh` at 0x530, `lh` at 0x5a0.
  5 such `lh` accesses load 2 bytes from [a1+48] +0x18, including `lh` at 0x540, `lh` at 0x5a4, `lh` at 0x6c8.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x10014, including `sw` at 0x558, `sw` at 0x59c.
  2 such `lbu` accesses load 1 byte from a1 (arg1 at entry) +0x2d, including `lbu` at 0x56c, `lbu` at 0x7a4.
  2 such `lh` accesses load 2 bytes from [a1+48] +0xa, including `lh` at 0x578, `lh` at 0x694.
  2 such `lh` accesses load 2 bytes from [a1+48] +0x8, including `lh` at 0x58c, `lh` at 0x67c.
  The `sw` at 0x5b8 stores 4 bytes to a0 (arg0 at entry) +0x1003c.
  The `sw` at 0x5d4 stores 4 bytes to a0 (arg0 at entry) +0x10040.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x10018, including `sw` at 0x5d8, `sw` at 0x960.
  The `lw` at 0x5dc loads 4 bytes from [a1+48] +0x4.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x1001c, including `sw` at 0x5f8, `sw` at 0x860.
  The `lbu` at 0x5fc loads 1 byte from a1 (arg1 at entry) +0x2e.
  The `lw` at 0x640 loads 4 bytes from [a1+48] +0x10.
  3 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x10028, including `sw` at 0x690, `sw` at 0x8f8, `sw` at 0x924.
  3 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x1002c, including `sw` at 0x6a8, `sw` at 0x904, `sw` at 0x938.
  The `sw` at 0x6f8 stores 4 bytes to a0 (arg0 at entry) +0x10044.
  The `sw` at 0x738 stores 4 bytes to a0 (arg0 at entry) +0x10048.
  The `sw` at 0x74c stores 4 bytes to a0 (arg0 at entry) +0x1004c.
  The `lbu` at 0x750 loads 1 byte from a1 (arg1 at entry) +0x2f.
  The `lhu` at 0x75c loads 2 bytes from a1 (arg1 at entry) +0x20.
  The `sw` at 0x7a0 stores 4 bytes to a0 (arg0 at entry) +0x30000.
  The `lhu` at 0x7a8 loads 2 bytes from a1 (arg1 at entry) +0x22.
  The `sw` at 0x7e8 stores 4 bytes to a0 (arg0 at entry) +0x30004.
  The `sw` at 0x7f8 stores 4 bytes to a0 (arg0 at entry) +0x20000.
  The `lh` at 0x7fc loads 2 bytes from [a1+48] +0x2c.
  The `lh` at 0x800 loads 2 bytes from [a1+48] +0x28.
  The `lh` at 0x808 loads 2 bytes from [a1+48] +0x2a.
  The `sw` at 0x8ec stores 4 bytes to a0 (arg0 at entry) +0x10030.
  The `lbu` at 0x944 loads 1 byte from ret(kopt_find) +0x0.
  The `lw` at 0x950 loads 4 bytes from a0 (arg0 at entry) +0x10018.
  The `jal` at 0x4c4 calls flushbus with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x660 calls i2cfp_DualChannelCommand with a0=a0 at entry (arg0), a1=?, a2=?, a3=one of 0x82, 0x326, a4=one of 0x300, 0x400, 0x401, 0xffe, a5=[sym(crm_dc_board_installed)], a7=[[a1+48]+16].
  The `jal` at 0x83c calls us_delay with a0=0x2af8, a1=[a1+32]:2, a2=?, a3=?, a4=a0+196608.
  The `jal` at 0x934 calls kopt_find with a0=sym(.rodata)+16, a1=one of 0x400, 0x500, 0x640, 0xffe, a2=?, a3=one of 0x82, 0x326, a4=one of 0x300, 0x400, 0x401, 0xffe, a5=0xfff.
  The `beq` branch at 0x564 targets 0x5a0, is taken when v1(=[sym(crm_dc_board_installed)]) >= 0x9 (signed), and falls through when v1(=[sym(crm_dc_board_installed)]) < 0x9 (signed).
  The `beq` branch at 0x570 targets 0x5a0, is taken when t8(=[a1+45]:1) == 0, and falls through when t8(=[a1+45]:1) != 0.
  The `beq` branch at 0x5ec targets 0x858, is taken when (at(=[[a1+48]+4]) & 0x12) == 0, and falls through when (at(=[[a1+48]+4]) & 0x12) != 0.
  The `beq` branch at 0x608 targets 0x8ac, is taken when v0(=[a1+46]:1) == a3(=0x82), and falls through when v0(=[a1+46]:1) != a3(=0x82).
  The `beq` branch at 0x614 targets 0x908, is taken when v0(=[a1+46]:1) == a4(=0x83), and falls through when v0(=[a1+46]:1) != a4(=0x83).
  The `beq` branch at 0x61c targets 0x8a0, is taken when a0(=0x84) == v0(=[a1+46]:1), and falls through when a0(=0x84) != v0(=[a1+46]:1).
  The `beq` branch at 0x62c targets 0x920, is taken when a0(=0x84) == v0(=[a1+46]:1), and falls through when a0(=0x84) != v0(=[a1+46]:1).
  The `beq` branch at 0x638 targets 0x8cc, is taken when a5(=[sym(crm_dc_board_installed)]) == 0, and falls through when a5(=[sym(crm_dc_board_installed)]) != 0.
  The `beq` branch at 0x650 targets 0x65c, is taken when a6(=0x186a0) >= a7(=[[a1+48]+16]) (signed), and falls through when a6(=0x186a0) < a7(=[[a1+48]+16]) (signed).
  The `bne` branch at 0x670 targets 0x67c, is taken when a7(=[sym(crm_dc_board_installed)]) < 0x9 (signed), and falls through when a7(=[sym(crm_dc_board_installed)]) >= 0x9 (signed).
  The `blez` branch at 0x6bc targets 0x6c8, is taken when v0(?) <= 0 (signed), and falls through when v0(?) > 0 (signed).
  The `bne` branch at 0x6d4 targets 0x6e8, is taken when a0(=[[a1+48]+24]:2) < 0x14 (signed), and falls through when a0(=[[a1+48]+24]:2) >= 0x14 (signed).
  The `beq` branch at 0x6e0 targets 0x6f8 and is always taken.
  The `bne` branch at 0x710 targets 0x724, is taken when a0(=[[a1+48]+24]:2) < a4(=[sym(gbemn)]) (signed), and falls through when a0(=[[a1+48]+24]:2) >= a4(=[sym(gbemn)]) (signed).
  The `beq` branch at 0x71c targets 0x734 and is always taken.
  The `beq` branch at 0x758 targets 0x864, is taken when a0(=[a1+47]:1) == a1(=0x20), and falls through when a0(=[a1+47]:1) != a1(=0x20).
  The `beq` branch at 0x7b0 targets 0x7bc, is taken when v1(=[a1+45]:1) == 0, and falls through when v1(=[a1+45]:1) != 0.
  The `beq` branch at 0x85c targets 0x5fc and is always taken.
  The `beq` branch at 0x898 targets 0x798 and is always taken.
  The `beq` branch at 0x8a4 targets 0x62c and is always taken.
  The `beq` branch at 0x8c4 targets 0x62c and is always taken.
  The `beq` branch at 0x900 targets 0x6ac and is always taken.
  The `beq` branch at 0x918 targets 0x62c and is always taken.
  The `beq` branch at 0x93c targets 0x964, is taken when v0(=ret(kopt_find)) == 0, and falls through when v0(=ret(kopt_find)) != 0.
  The `beq` branch at 0x948 targets 0x96c, is taken when a1(=[ret(kopt_find)]:1) == a2(=0x31), and falls through when a1(=[ret(kopt_find)]:1) != a2(=0x31).
  The `beq` branch at 0x95c targets 0x6ac and is always taken.
  The `beq` branch at 0x964 targets 0x950 and is always taken.
  The `beq` branch at 0x96c targets 0x950 and is always taken.
  The return at 0x850 has v0 = ret(us_delay).

- `gbeStartVideoTiming` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_init.o)` at 0x974 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_init.o)`.
  Range: 0x974-0xb90 (540 bytes).
  It occupies 540 bytes.
  The `ld` at 0x98c loads 8 bytes from abs 0xffffffffb4000028.
  The `sd` at 0x9c8 stores 8 bytes to abs 0xffffffffb4000028.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x10038, including `sw` at 0x9e4, `sw` at 0xb6c.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x10034, including `sw` at 0x9ec, `sw` at 0xb68.
  2 such `lh` accesses load 2 bytes from a1 (arg1 at entry) +0x14, including `lh` at 0x9f0, `lh` at 0xa70.
  The `lh` at 0x9f4 loads 2 bytes from a1 (arg1 at entry) +0x1e.
  The `sw` at 0xa0c stores 4 bytes to a0 (arg0 at entry) +0x10004.
  The `lw` at 0xa10 loads 4 bytes from a0 (arg0 at entry) +0x30000.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x30000, including `sw` at 0xa20, `sw` at 0xa28.
  The `lw` at 0xa30 loads 4 bytes from a0 (arg0 at entry) +0x20000.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x20000, including `sw` at 0xa3c, `sw` at 0xa40.
  The `sw` at 0xa48 stores 4 bytes to a0 (arg0 at entry) +0x3000c.
  The `sw` at 0xa50 stores 4 bytes to a0 (arg0 at entry) +0x20008.
  The `sw` at 0xa5c stores 4 bytes to a0 (arg0 at entry) +0x40004.
  The `lh` at 0xa60 loads 2 bytes from a1 (arg1 at entry) +0x18.
  The `lh` at 0xa64 loads 2 bytes from a1 (arg1 at entry) +0x22.
  4 such `lh` accesses load 2 bytes from a1 (arg1 at entry) +0x20, including `lh` at 0xa68, `lh` at 0xb00, `lh` at 0xb20.
  The `lh` at 0xa7c loads 2 bytes from a1 (arg1 at entry) +0x8.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x30008, including `lw` at 0xa98, `lw` at 0xac0.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x20004, including `lw` at 0xad0, `lw` at 0xaf0.
  4 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x10000, including `lw` at 0xb04, `lw` at 0xb24, `lw` at 0xb34.
  The `jal` at 0x9c4 calls flushbus with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x9e8 calls flushbus with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xa1c calls flushbus with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xa38 calls flushbus with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xa58 calls flushbus with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xab8 calls us_delay with a0=0x1, a1=?, a2=?, a3=?.
  The `jal` at 0xae8 calls us_delay with a0=0x1, a1=?, a2=?, a3=?.
  The `jal` at 0xb18 calls us_delay with a0=0x1, a1=?, a2=?, a3=?.
  The `jal` at 0xb44 calls us_delay with a0=0x1, a1=?, a2=?, a3=?.
  The `bltz` branch at 0xa80 targets 0xb88, is taken when s4(=[a1+24]:2-19) < 0 (signed), and falls through when s4(=[a1+24]:2-19) >= 0 (signed).
  The `beq` branch at 0xab0 targets 0xad0, is taken when s5(?) == t9(?), and falls through when s5(?) != t9(?).
  The `bne` branch at 0xac8 targets 0xab8, is taken when s5(?) != v0(?), and falls through when s5(?) == v0(?).
  The `beq` branch at 0xae0 targets 0xb00, is taken when s2(?) == v1(?), and falls through when s2(?) != v1(?).
  The `bne` branch at 0xaf8 targets 0xae8, is taken when s2(?) != a0(?), and falls through when s2(?) == a0(?).
  The `bne` branch at 0xb10 targets 0xb34, is taken when a1(=[a0+65536]) < a0(=[a1+32]:2) (unsigned), and falls through when a1(=[a0+65536]) >= a0(=[a1+32]:2) (unsigned).
  The `beq` branch at 0xb2c targets 0xb18, is taken when a2(=[a0+65536]) >= a0(=[a1+32]:2) (unsigned), and falls through when a2(=[a0+65536]) < a0(=[a1+32]:2) (unsigned).
  The `bne` branch at 0xb3c targets 0xb60, is taken when a0(=[a1+32]:2) < a3(=[a0+65536]) (unsigned), and falls through when a0(=[a1+32]:2) >= a3(=[a0+65536]) (unsigned).
  The `beq` branch at 0xb58 targets 0xb44, is taken when a4(=[a1+32]:2) >= a5(=[a0+65536]) (unsigned), and falls through when a4(=[a1+32]:2) < a5(=[a0+65536]) (unsigned).
  The `beq` branch at 0xb88 targets 0xa88 and is always taken.
  The return at 0xb80 has v0 = one of ?, ret(us_delay).

- `gbeStartVideoTiming` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_init.o)` at 0x974 (n32).
  Inferred: it programs fields of the table at a1 into device blocks at a0+0x10000, a0+0x20000,
  a0+0x30000 and a0+0x40000, because it stores values built from halfwords of that table and
  constants into those blocks and polls status words at +0x30008, +0x20004 and +0x10000 between the
  writes. It reads the 8-byte CRIME register at offset 0x28 at entry (the `ld` at 0x98c), clears the
  0x10000 bit with the mask 0xfffffffffffeffff (the `ori` at 0x9a0) and writes the result back to
  the register in the delay slot of the first `flushbus` call (the `sd` at 0x9c8, after the `jal` at
  0x9c4). It then stores 0xffffff at +0x10038 and +0x10034 (the `sw` at 0x9e4 and 0x9ec) and a word
  built from the halfword at +0x14 of the table masked with 0xfff and the halfword at +0x1e shifted
  left by 0xc at +0x10004 (the `lh` at 0x9f0 and 0x9f4, the `sw` at 0xa0c). Each of the five
  `flushbus` calls (the `jal` at 0x9c4, 0x9e8, 0xa1c, 0xa38 and 0xa58) has one store in its delay
  slot; the stores at 0xa20 and 0xa3c set bit 0x8000 of the word at +0x30000 and bit 0x2000 of the
  word at +0x20000, and the stores at 0xa28 and 0xa40 write the saved words back. It then stores a2,
  a3 and a4 at +0x3000c, +0x20008 and +0x40004 (the `sw` at 0xa48, 0xa50 and 0xa5c), the last in the
  delay slot of the flush at 0xa58. It polls the word at +0x30008 (the `lw` at 0xa98 and 0xac0) with
  `us_delay` of 1 between passes (the `jal` at 0xab8) until its low bit equals the low bit of a2
  (the `andi` at 0xa74 and the `beq` at 0xab0), then the word at +0x20004 (the `lw` at 0xad0 and
  0xaf0) with `us_delay` of 1 (the `jal` at 0xae8) until its low bit equals the low bit of a3 (the
  `andi` at 0xad4 and the `beq` at 0xae0). The last poll reads the word at +0x10000 (the `lw` at
  0xb04, 0xb24, 0xb34 and 0xb4c) and compares it with the halfword at +0x20 of the table (the `lh`
  at 0xb00, 0xb20 and 0xb50): it waits with `us_delay` of 1 (the `jal` at 0xb18) while the word is
  not below that halfword, then waits (the `jal` at 0xb44) while it is not above it. On exit it
  stores two words built from table halfwords at +0x10034 and +0x10038 (the `sw` at 0xb68 and
  0xb6c): the second is the halfword at +0x20 masked with 0xfff ORed with the halfword at +0x22
  masked with 0xfff and shifted left by 0xc, and the first combines the halfword at +0x18 less a
  constant, wrapped by adding the halfword at +0x14 when negative and shifted left by 0xc, with the
  remainder of a division by the halfword at +0x14.
  Unknown: which device the blocks at a0+0x10000, a0+0x20000, a0+0x30000 and a0+0x40000 belong to,
  since the bundle has no linked rows for them.
  Evidence grade: inferred.

- `crimeInitHW` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_init.o)` at 0xb90 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_init.o)`.
  Range: 0xb90-0xde4 (596 bytes).
  It occupies 596 bytes.
  The `sw` at 0xbe4 stores 4 bytes to a0 (arg0 at entry) +0x408.
  The `sw` at 0xbf4 stores 4 bytes to a1 (arg1 at entry) +0x70004.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x400, including `sw` at 0xc08, `sw` at 0xd4c.
  13 such `sd` accesses store 8 bytes to ?, including `sd` at 0xc10, `sd` at 0xc14, `sd` at 0xc1c.
  4 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x4008, including `sw` at 0xca0, `sw` at 0xce4, `sw` at 0xd8c.
  The `sh` at 0xd74 stores 2 bytes to sym(crimeBoards) +0x38.
  The `jal` at 0xbf0 calls gbeGmapInit with a0=a1 at entry (arg1), a1=a1 at entry (arg1), a2=0x3f, a3=0x7e, a4=0x7f.
  The `jal` at 0xc94 calls crmFifoWait with a0=a0 at entry (arg0), a1=[sym(ib_full)], a2=0x1000, a3=?.
  The `jal` at 0xce8 calls get_cpu_irr with a0=?, a1=?, a2=?, a3=a3 at entry (arg3).
  The `jal` at 0xd3c calls crmIdleWait with a0=a0 at entry (arg0), a1=0x1000, a2=?, a3=one of 0x0, 0x18.
  The `jal` at 0xd48 calls flushbus with a0=?, a1=[sym(ibctl)], a2=?, a3=?.
  The `jal` at 0xd80 calls crmFifoWait with a0=a0 at entry (arg0), a1=[sym(ib_full)], a2=0x1000, a3=?.
  The `jal` at 0xd98 calls crmFifoWait with a0=a0 at entry (arg0), a1=[sym(ib_full)], a2=0x1000, a3=?.
  The `jal` at 0xda8 calls get_cpu_irr with a0=?, a1=?, a2=?, a3=0x0, a4=[sym(r10kfifohigh)].
  The `beq` branch at 0xc18 targets 0xd78, is taken when s3(=0x7) == a6(?), and falls through when s3(=0x7) != a6(?).
  The `beq` branch at 0xc28 targets 0xc54, is taken when s0(?) >= 0x40 (signed), and falls through when s0(?) < 0x40 (signed).
  The `beq` branch at 0xc38 targets 0xd90, is taken when s3(=0x7) == a0(?), and falls through when s3(=0x7) != a0(?).
  The `bne` branch at 0xc4c targets 0xc10, is taken when s0(?) < 0x40 (signed), and falls through when s0(?) >= 0x40 (signed).
  The `beq` branch at 0xc6c targets 0xc90, is taken when a2(?) >= 0x10 (signed), and falls through when a2(?) < 0x10 (signed).
  The `bne` branch at 0xc84 targets 0xc5c, is taken when a2(?) < 0x10 (signed), and falls through when a2(?) >= 0x10 (signed).
  The `beq` branch at 0xcb8 targets 0xce0, is taken when a2(?) >= 0x1c (signed), and falls through when a2(?) < 0x1c (signed).
  The `beq` branch at 0xcc8 targets 0xce0, is taken when a2(?) >= 0x1c (signed), and falls through when a2(?) < 0x1c (signed).
  The `bne` branch at 0xcd8 targets 0xcac, is taken when a2(?) < 0x1c (signed), and falls through when a2(?) >= 0x1c (signed).
  The `beq` branch at 0xce0 targets 0xd50, is taken when a3 == 0, and falls through when a3 != 0.
  The `beq` branch at 0xcfc targets 0xda8, is taken when ra(?) >= 0x23 (signed), and falls through when ra(?) < 0x23 (signed).
  The `beq` branch at 0xd88 targets 0xc20 and is always taken.
  The `beq` branch at 0xda0 targets 0xc40 and is always taken.
  The `beq` branch at 0xdb8 targets 0xdd0, is taken when a4(?) == a5(=0x27), and falls through when a4(?) != a5(=0x27).
  The `beq` branch at 0xdc8 targets 0xd0c and is always taken.
  The `beq` branch at 0xddc targets 0xd0c and is always taken.
  The return at 0xd70 has v0 = one of ret(crmFifoWait), ret(flushbus).

- `crmInitTp` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_init.o)` at 0xde4 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_init.o)`.
  Range: 0xde4-0x1144 (864 bytes).
  It occupies 864 bytes.
  The `lw` at 0xdec loads 4 bytes from a2 (arg2 at entry) +0x30.
  The `sw` at 0xe68 stores 4 bytes to a1 (arg1 at entry) +0x3000c.
  3 such `sw` accesses store 4 bytes to a1 (arg1 at entry) +0x20008, including `sw` at 0xe74, `sw` at 0xea4, `sw` at 0x1008.
  6 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x20004, including `lw` at 0xe78, `lw` at 0xe90, `lw` at 0xea8.
  2 such `lbu` accesses load 1 byte from a3 (arg3 at entry) +0x19, including `lbu` at 0xec8, `lbu` at 0xef0.
  3 such `lbu` accesses load 1 byte from a3 (arg3 at entry) +0x18, including `lbu` at 0xee0, `lbu` at 0xf24, `lbu` at 0xf88.
  The `sd` at 0xf20 stores 8 bytes to ?.
  3 such `lw` accesses load 4 bytes from a3 (arg3 at entry) +0x8, including `lw` at 0xf44, `lw` at 0xf5c, `lw` at 0x1140.
  2 such `lhu` accesses load 2 bytes from ?, including `lhu` at 0xf4c, `lhu` at 0xf78.
  2 such `sh` accesses store 2 bytes to ?, including `sh` at 0xf54, `sh` at 0xf84.
  2 such `lw` accesses load 4 bytes from a3 (arg3 at entry) +0x4, including `lw` at 0xfa0, `lw` at 0x1128.
  The `sw` at 0xfc8 stores 4 bytes to a1 (arg1 at entry) +0x48000.
  2 such `sw` accesses store 4 bytes to a1 (arg1 at entry) +0x10038, including `sw` at 0xfd0, `sw` at 0x10f0.
  2 such `sw` accesses store 4 bytes to a1 (arg1 at entry) +0x10034, including `sw` at 0xfd4, `sw` at 0x10e8.
  The `lw` at 0xfd8 loads 4 bytes from a1 (arg1 at entry) +0x30000.
  2 such `sw` accesses store 4 bytes to a1 (arg1 at entry) +0x30000, including `sw` at 0xfe4, `sw` at 0xfe8.
  The `lw` at 0xfec loads 4 bytes from a1 (arg1 at entry) +0x20000.
  2 such `sw` accesses store 4 bytes to a1 (arg1 at entry) +0x20000, including `sw` at 0xff8, `sw` at 0xffc.
  The `lh` at 0x1038 loads 2 bytes from [a2+48] +0x18.
  3 such `lh` accesses load 2 bytes from [a2+48] +0x20, including `lh` at 0x1040, `lh` at 0x1098, `lh` at 0x10c8.
  The `lh` at 0x1048 loads 2 bytes from [a2+48] +0x14.
  The `lh` at 0x104c loads 2 bytes from [a2+48] +0x8.
  The `lh` at 0x1064 loads 2 bytes from [a2+48] +0x22.
  4 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x10000, including `lw` at 0x106c, `lw` at 0x109c, `lw` at 0x10ac.
  The `jal` at 0xe48 calls kvtophys with a0=table(sym(.bss)), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a6=sym(.bss), a7=0x40.
  The `jal` at 0xe70 calls flushbus with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xe88 calls us_delay with a0=0xa, a1=?, a2=?, a3=?.
  The `jal` at 0xeb4 calls us_delay with a0=0xa, a1=?, a2=?, a3=?.
  The `jal` at 0xfa8 calls dki_dcache_wb with a0=[sym(gbe_tp_overlay_tiles)], a1=([a3+4] + [a3+4]), a2=?, a3=[a3+25]:1.
  The `jal` at 0xfe0 calls flushbus with a0=?, a1=?, a2=([a1+196608] | 0x8000), a3=0xffffff, a4=a1+294912.
  The `jal` at 0xff4 calls flushbus with a0=?, a1=?, a2=?, a3=?, a5=([a1+131072] | 0x2000).
  The `jal` at 0x1004 calls flushbus with a0=?, a1=?, a2=?, a3=?, a6=(ret(kvtophys) | 0x1).
  The `jal` at 0x1020 calls us_delay with a0=0x1, a1=?, a2=?, a3=?.
  The `jal` at 0x1090 calls us_delay with a0=0x1, a1=?, a2=?, a3=?.
  The `jal` at 0x10bc calls us_delay with a0=0x1, a1=?, a2=?, a3=?.
  The `jal` at 0x10f4 calls crmIdleWait with a0=a0 at entry (arg0), a1=0x186a0, a2=?, a3=?.
  The `beq` branch at 0xe20 targets 0xe30, is taken when (a6(=sym(.bss)) & 0x3f) == 0, and falls through when (a6(=sym(.bss)) & 0x3f) != 0.
  The `beq` branch at 0xe80 targets 0xea4, is taken when (t8(=[a1+131076]) & 0x1) == 0, and falls through when (t8(=[a1+131076]) & 0x1) != 0.
  The `bne` branch at 0xe98 targets 0xe88, is taken when (t9(=[a1+131076]) & 0x1) != 0, and falls through when (t9(=[a1+131076]) & 0x1) == 0.
  The `beq` branch at 0xeac targets 0xec8, is taken when ra(=[a1+131076]) == s1(?), and falls through when ra(=[a1+131076]) != s1(?).
  The `bne` branch at 0xec0 targets 0xeb4, is taken when at(=[a1+131076]) != s1(?), and falls through when at(=[a1+131076]) == s1(?).
  The `blez` branch at 0xed8 targets 0x1124, is taken when a3(=[a3+25]:1) <= 0 (signed), and falls through when a3(=[a3+25]:1) > 0 (signed).
  The `beq` branch at 0xee8 targets 0xf04 and is always taken.
  The `beq` branch at 0xefc targets 0xfa0, is taken when a0(?) >= a3(=[a3+25]:1) (signed), and falls through when a0(?) < a3(=[a3+25]:1) (signed).
  The `blez` branch at 0xf04 targets 0xef4, is taken when a6(=[a3+24]:1) <= 0 (signed), and falls through when a6(=[a3+24]:1) > 0 (signed).
  The `beq` branch at 0xf10 targets 0x112c and is always taken.
  The `beq` branch at 0xf3c targets 0xef0, is taken when a5(?) >= a6(=[a3+24]:1) (signed), and falls through when a5(?) < a6(=[a3+24]:1) (signed).
  The `beq` branch at 0xf80 targets 0xf18, is taken when t3(?) == s2(=0x3), and falls through when t3(?) != s2(=0x3).
  The `bne` branch at 0xf90 targets 0xf28, is taken when a5(?) != t3(=[a3+24]:1-1), and falls through when a5(?) == t3(=[a3+24]:1-1).
  The `beq` branch at 0xf98 targets 0xf1c and is always taken.
  The `beq` branch at 0x1018 targets 0x1038, is taken when s1(?) == a7(?), and falls through when s1(?) != a7(?).
  The `bne` branch at 0x1030 targets 0x1020, is taken when s1(?) != t0(?), and falls through when s1(?) == t0(?).
  The `bltz` branch at 0x1050 targets 0x111c, is taken when s1(=[[a2+48]+24]:2-19) < 0 (signed), and falls through when s1(=[[a2+48]+24]:2-19) >= 0 (signed).
  The `bne` branch at 0x1088 targets 0x10ac, is taken when t9(=[a1+65536]) < v0(=[[a2+48]+32]:2) (unsigned), and falls through when t9(=[a1+65536]) >= v0(=[[a2+48]+32]:2) (unsigned).
  The `beq` branch at 0x10a4 targets 0x1090, is taken when ra(=[a1+65536]) >= v0(=[[a2+48]+32]:2) (unsigned), and falls through when ra(=[a1+65536]) < v0(=[[a2+48]+32]:2) (unsigned).
  The `bne` branch at 0x10b4 targets 0x10dc, is taken when v0(=[[a2+48]+32]:2) < at(=[a1+65536]) (unsigned), and falls through when v0(=[[a2+48]+32]:2) >= at(=[a1+65536]) (unsigned).
  The `beq` branch at 0x10d0 targets 0x10bc, is taken when v0(=[[a2+48]+32]:2) >= v1(=[a1+65536]) (unsigned), and falls through when v0(=[[a2+48]+32]:2) < v1(=[a1+65536]) (unsigned).
  The `beq` branch at 0x111c targets 0x1058 and is always taken.
  The `beq` branch at 0x1124 targets 0xfa4 and is always taken.
  The `beq` branch at 0x113c targets 0xf48 and is always taken.
  The return at 0x1114 has v0 = ret(crmIdleWait).

- `crmInvalidVideoTiming` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_init.o)` at 0x1144 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_init.o)`.
  Range: 0x1144-0x119c (88 bytes).
  It occupies 88 bytes.
  The `lh` at 0x1144 loads 2 bytes from a0 (arg0 at entry) +0x2c.
  The `lh` at 0x1148 loads 2 bytes from a0 (arg0 at entry) +0x28.
  The `lh` at 0x1150 loads 2 bytes from a0 (arg0 at entry) +0x2a.
  The `blez` branch at 0x1154 targets 0x1184, is taken when a3(=[a0+40]:2) <= 0 (signed), and falls through when a3(=[a0+40]:2) > 0 (signed).
  The `beq` branch at 0x1160 targets 0x1184, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `blez` branch at 0x1168 targets 0x1188, is taken when v0(=[a0+42]:2) <= 0 (signed), and falls through when v0(=[a0+42]:2) > 0 (signed).
  The `beq` branch at 0x1170 targets 0x1188, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `bltz` branch at 0x1178 targets 0x1188, is taken when a4(=[a0+44]:2) < 0 (signed), and falls through when a4(=[a0+44]:2) >= 0 (signed).
  The `bne` branch at 0x1180 targets 0x1190, is taken when a5(?) != 0, and falls through when a5(?) == 0.
  The return at 0x1188 has v0 = 0x1.
  The return at 0x1194 has v0 = 0x0.

- `crime_setvideotiming` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_init.o)` at 0x119c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_init.o)`.
  Range: 0x119c-0x1478 (732 bytes).
  It occupies 732 bytes.
  7 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x30, including `lw` at 0x11c8, `lw` at 0x12e4, `lw` at 0x12f8.
  The `lw` at 0x11e0 loads 4 bytes from sym(crimeBoards) +0x4.
  11 such `lw` accesses load 4 bytes from ?, including `lw` at 0x11ec, `lw` at 0x11f8, `lw` at 0x12a0.
  7 such `sw` accesses store 4 bytes to ?, including `sw` at 0x1204, `sw` at 0x1210, `sw` at 0x12ac.
  The `lw` at 0x1214 loads 4 bytes from sym(crimeBoards) +0x0.
  The `lw` at 0x1218 loads 4 bytes from a2 (arg2 at entry) +0x0.
  The `lw` at 0x1224 loads 4 bytes from a1 (arg1 at entry) +0xe4.
  The `lw` at 0x1248 loads 4 bytes from sym(crimeVTimings) +0x30.
  2 such `sw` accesses store 4 bytes to a1 (arg1 at entry) +0x30, including `sw` at 0x12c4, `sw` at 0x1384.
  3 such `sw` accesses store 4 bytes to a1 (arg1 at entry) +0xe4, including `sw` at 0x12c8, `sw` at 0x1350, `sw` at 0x138c.
  The `lh` at 0x1378 loads 2 bytes from sym(crimeVTimings) +0x44.
  The `lbu` at 0x1398 loads 1 byte from a0 (arg0 at entry) +0x98.
  The `lbu` at 0x13a8 loads 1 byte from a1 (arg1 at entry) +0x2b.
  The `lw` at 0x13c4 loads 4 bytes from a0 (arg0 at entry) +0x1c4.
  2 such `lhu` accesses load 2 bytes from ?, including `lhu` at 0x13d8, `lhu` at 0x1434.
  4 such `sh` accesses store 2 bytes to ?, including `sh` at 0x13e0, `sh` at 0x13fc, `sh` at 0x140c.
  The `lh` at 0x13f8 loads 2 bytes from [a1+48] +0x8.
  The `lh` at 0x1408 loads 2 bytes from [a1+48] +0xa.
  The `lw` at 0x1418 loads 4 bytes from [a1+48] +0xc.
  The `lw` at 0x1424 loads 4 bytes from [a1+48] +0x4.
  The `jal` at 0x1264 calls crmInvalidVideoTiming with a0=a2 at entry (arg2), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x12d8 calls crimeInitInfo with a0=[sym(crimeBoards)], a1=[sym(crimeBoards)+4], a2=a1 at entry (arg1), a3=0x1.
  The `jal` at 0x12e0 calls crmResizeFb with a0=[a1+48], a1=?, a2=?, a3=?.
  The `jal` at 0x134c calls crimeInitInfo with a0=[sym(crimeBoards)], a1=[sym(crimeBoards)+4], a2=a1 at entry (arg1), a3=0x1, a6=sp-112, a7=[a1+48].
  The `jal` at 0x144c calls gbeRun with a0=[sym(crimeBoards)+4], a1=a1 at entry (arg1), a2=a0 at entry (arg0), a3=?.
  The `jal` at 0x1468 calls cmn_err with a0=0x4, a1=sym(.rodata)+32, a2=a2 at entry (arg2), a3=a3 at entry (arg3), a6=sp-108, a7=0x8.
  The `bgtz` branch at 0x120c targets 0x11e8, is taken when a5(?) > 0 (signed), and falls through when a5(?) <= 0 (signed).
  The `beq` branch at 0x1228 targets 0x1390, is taken when v0(=[a2]) == t9(=0xd), and falls through when v0(=[a2]) != t9(=0xd).
  The `blez` branch at 0x1230 targets 0x1264, is taken when v0(=[a2]) <= 0 (signed), and falls through when v0(=[a2]) > 0 (signed).
  The `beq` branch at 0x1238 targets 0x1264, is taken when v1(?) == 0, and falls through when v1(?) != 0.
  The `beq` branch at 0x124c targets 0x1378, is taken when a7(=[sym(crimeVTimings+48)]) == v0(=[a2]), and falls through when a7(=[sym(crimeVTimings+48)]) != v0(=[a2]).
  The `bne` branch at 0x125c targets 0x1248, is taken when a6(?) < 0x10 (unsigned), and falls through when a6(?) >= 0x10 (unsigned).
  The `beq` branch at 0x126c targets 0x127c, is taken when v0(=ret(crmInvalidVideoTiming)) == 0, and falls through when v0(=ret(crmInvalidVideoTiming)) != 0.
  The `beq` branch at 0x1274 targets 0x1358 and is always taken.
  The `bgtz` branch at 0x12bc targets 0x1298, is taken when v0(?) > 0 (signed), and falls through when v0(?) <= 0 (signed).
  The `beq` branch at 0x12e8 targets 0x13bc, is taken when v0(=ret(crmResizeFb)) == 0, and falls through when v0(=ret(crmResizeFb)) != 0.
  The `bgtz` branch at 0x1330 targets 0x130c, is taken when a5(?) > 0 (signed), and falls through when a5(?) <= 0 (signed).
  The `beq` branch at 0x137c targets 0x145c, is taken when t9(=[sym(crimeVTimings+68)]:2) == 0, and falls through when t9(=[sym(crimeVTimings+68)]:2) != 0.
  The `beq` branch at 0x1388 targets 0x12cc and is always taken.
  The `beq` branch at 0x1390 targets 0x13a8, is taken when s2(=a0) == 0, and falls through when s2(=a0) != 0.
  The `beq` branch at 0x13a0 targets 0x1464, is taken when (ra(=[a0+152]:1) & 0x2) == 0, and falls through when (ra(=[a0+152]:1) & 0x2) != 0.
  The `beq` branch at 0x13ac targets 0x1230, is taken when at(=[a1+43]:1) == 0, and falls through when at(=[a1+43]:1) != 0.
  The `beq` branch at 0x13b4 targets 0x1358 and is always taken.
  The `beq` branch at 0x13bc targets 0x1448, is taken when s2(=a0) == 0, and falls through when s2(=a0) != 0.
  The `beq` branch at 0x13c8 targets 0x1448, is taken when v0(=[a0+452]) == 0, and falls through when v0(=[a0+452]) != 0.
  The `beq` branch at 0x13d0 targets 0x13f0 and is always taken.
  The `beq` branch at 0x13e8 targets 0x1444, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `bne` branch at 0x142c targets 0x13d8, is taken when (a0(=[[a1+48]+4]) & 0x2) != 0, and falls through when (a0(=[[a1+48]+4]) & 0x2) == 0.
  The `beq` branch at 0x143c targets 0x13e4 and is always taken.
  The `beq` branch at 0x1454 targets 0x1358 and is always taken.
  The `beq` branch at 0x145c targets 0x135c and is always taken.
  The `beq` branch at 0x1470 targets 0x1358 and is always taken.
  The return at 0x1370 has v0 = one of ?, 0x16.

- `crime_setvideotiming` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_init.o)` at 0x119c (n32).
  Before the key test it copies twelve words of the table at +0x30 of the record at a1 into its
  frame (the loop at 0x11e8 to 0x1210) and saves the +0xe4 value there as a doubleword (the `sd` at
  0x122c). Takes the word at [a2] as a key, and when the key is 0xd (the `beq` at 0x1228) the path
  at 0x1390 returns 0x16 after a `cmn_err` call (the `jal` at 0x1468) when a0 is nonzero and bit 0x2
  of the byte at +0x98 of a0 is clear (the `lbu` at 0x1398), and otherwise returns 0x16 when the
  byte at +0x2b of a1 is nonzero (the `lbu` at 0x13a8) and goes on to the range test when it is
  zero. When the key is above zero and below 0x10 (`blez` at 0x1230, `slti` at 0x1234), the routine
  scans the 0x30-byte entries of `crimeVTimings` from +0x60, comparing each entry's first word with
  the key while the pass count in a6 is below 0x10 (`bne` at 0x125c). A match whose entry has a
  nonzero halfword at +0x14 (`lh` at 0x1378, `beq` at 0x137c) stores the entry pointer at +0x30 and
  the pass count at +0xe4 of the record at a1 (`sw` at 0x1384 and 0x138c). A match with a zero
  halfword at +0x14 returns 0x16 at 0x145c without those two stores. A key outside that range, or a
  key with no match, calls crmInvalidVideoTiming (`jal` at 0x1264), and the routine returns 0x16
  when that call returns nonzero (`beq` at 0x126c, `addiu` at 0x1278). When that call returns zero,
  a loop of loads and stores at 0x1298 to 0x12c0 copies twelve words of the key block at a2 into the
  record at a1 from +0x34, and the routine stores the address a1+0x34 at +0x30 and 0x10 at +0xe4
  (`sw` at 0x12c4 and 0x12c8). The matched and the unmatched paths then call crimeInitInfo with the
  words at `crimeBoards` +0 and +4 and a1, with a3 set to 1 (`jal` at 0x12d8), and call crmResizeFb
  with the word at +0x30 of a1 as its first argument (`jal` at 0x12e0). When crmResizeFb returns
  nonzero (the `beq` at 0x12e8 falls through), the routine copies the twelve saved words back over
  the table at +0x30 (the loop at 0x130c to 0x1334), calls crimeInitInfo again with the saved +0xe4
  word stored in its delay slot (the `sw` at 0x1350, the `jal` at 0x134c) and returns the
  crmResizeFb result. When crmResizeFb returns zero (0x13bc), and a0 and the word at +0x1c4 of a0
  are nonzero, it walks the list that starts at that word through +0x14 of each element and, for
  each element, writes into the record at +0x4c the halfword at +0x27c from the halfword at +0x8 of
  the table at +0x30 (the `sh` at 0x13fc), the halfword at +0x27e from the halfword at +0xa (the
  `sh` at 0x140c) and the word at +0x280 from the word at +0xc (the `sw` at 0x141c). It sets or
  clears bit 0x1 of the halfword at +0x284 (the `sh` at 0x13e0 and 0x1440) according to bit 0x2 of
  the table's +0x4 field. It then calls gbeRun with the word at `crimeBoards` +4, a1 and a2 (`jal`
  at 0x144c) and returns 0.
  Unknown: the register writes of crimeInitInfo, crmResizeFb, gbeRun and crmInvalidVideoTiming (no
  committed entries).
  Evidence grade: established.

- `gbeGmapInit` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_init.o)` at 0x1478 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_init.o)`.
  Range: 0x1478-0x1510 (152 bytes).
  It occupies 152 bytes.
  The `lbu` at 0x1494 loads 1 byte from sym(crimeVTimings) +0x300.
  3 such `sw` accesses store 4 bytes to ?, including `sw` at 0x14c0, `sw` at 0x14e4, `sw` at 0x14fc.
  The `beq` branch at 0x148c targets 0x14cc, is taken when a4(=[sym(gbe_gammawar)]) == 0, and falls through when a4(=[sym(gbe_gammawar)]) != 0.
  The `bne` branch at 0x14bc targets 0x1494, is taken when a1(?) < 0x100 (signed), and falls through when a1(?) >= 0x100 (signed).
  The `beq` branch at 0x14ec targets 0x14c4, is taken when a1(?) >= 0x100 (signed), and falls through when a1(?) < 0x100 (signed).
  The `bne` branch at 0x1500 targets 0x14dc, is taken when a1(?) < 0x100 (signed), and falls through when a1(?) >= 0x100 (signed).
  The `beq` branch at 0x1508 targets 0x14c4 and is always taken.
  The return at 0x14c4 has v0 = ?.

- `gbeRun` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_init.o)` at 0x1510 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_init.o)`.
  Range: 0x1510-0x15d0 (192 bytes).
  It occupies 192 bytes.
  3 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x30, including `lw` at 0x155c, `lw` at 0x1570, `lw` at 0x157c.
  The `lw` at 0x1578 loads 4 bytes from a2 (arg2 at entry) +0x84.
  The `lw` at 0x1580 loads 4 bytes from [a2+132] +0x4.
  The `lw` at 0x158c loads 4 bytes from [a2+132] +0x4c.
  The `jal` at 0x1530 calls crm_callvideo with a0=a0 at entry (arg0), a1=0x1, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1544 calls gbeStop with a0=a0 at entry (arg0), a1=sp-48, a2=sp-44, a3=sp-40.
  The `jal` at 0x1550 calls gbeSetTimingRegs with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0x1560 calls crmLoadGbelists with a0=a2 at entry (arg2), a1=[a1+48], a2=?, a3=?.
  The `jal` at 0x156c calls gbeCacheVtInfo with a0=a2 at entry (arg2), a1=[a1+48], a2=?, a3=?.
  The `jal` at 0x1588 calls gbeStartVideoTiming with a0=a0 at entry (arg0), a1=[a1+48], a2=[[a2+132]+76], a3=[[a2+132]+4].
  The `jal` at 0x159c calls crm_callvideo with a0=a0 at entry (arg0), a1=0x2, a2=?, a3=?.
  The `jal` at 0x15c0 calls gbeStartVideoTiming with a0=a0 at entry (arg0), a1=[a1+48], a2=?, a3=?.
  The `beq` branch at 0x1558 targets 0x15b4, is taken when s2(=a2) == 0, and falls through when s2(=a2) != 0.
  The `beq` branch at 0x15c8 targets 0x1594 and is always taken.
  The return at 0x15ac has v0 = ret(crm_callvideo).

- `gbeRun` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_init.o)` at 0x1510 (n32).
  Does not touch the device through its own loads and stores, which use only its frame and the
  records at a1 and a2; it sequences the calls to crm_callvideo, gbeStop, gbeSetTimingRegs,
  crmLoadGbelists, gbeCacheVtInfo and gbeStartVideoTiming. On every path it calls crm_callvideo with
  0x1 in a1 (`jal` at 0x1530), gbeStop with three pointers into its frame at sp-48, sp-44 and sp-40
  (`jal` at 0x1544), and gbeSetTimingRegs with a0 and a1 passed through (`jal` at 0x1550). When a2
  is nonzero (the `beq` at 0x1558 falls through), it calls crmLoadGbelists with a2 (`jal` at 0x1560)
  and gbeCacheVtInfo with a2 and the word at +0x30 of a1 (`jal` at 0x156c). It then loads the
  pointer at +0x84 of a2 (`lw` at 0x1578) and calls gbeStartVideoTiming with a0, the word at +0x30
  of a1, the words at +0x4c and +0x4 of that pointer as its third and fourth arguments and the frame
  word at sp-40 as its fifth (`lw` at 0x1574, `jal` at 0x1588). When a2 is zero, the branch at
  0x1558 goes to 0x15b4, which calls gbeStartVideoTiming with a0, the word at +0x30 of a1, and the
  frame words at sp-48, sp-44 and sp-40 as its third, fourth and fifth arguments (`lw` at 0x15b4,
  0x15b8 and 0x15c4, `jal` at 0x15c0). Both paths then reach 0x1594, which calls crm_callvideo with
  0x2 (`jal` at 0x159c) and returns the value of that call (`jr ra` at 0x15ac).
  Unknown: the values that gbeStop writes into sp-48, sp-44 and sp-40, since gbeStop has no
  committed entry; its entry would settle the values gbeStartVideoTiming receives on the zero path.
  Evidence grade: established.

- `gbeBlankScreen` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_init.o)` at 0x15d0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_init.o)`.
  Range: 0x15d0-0x16fc (300 bytes).
  It occupies 300 bytes.
  The `lbu` at 0x1610 loads 1 byte from a1 (arg1 at entry) +0x2e.
  2 such `lbu` accesses load 1 byte from a1 (arg1 at entry) +0x2d, including `lbu` at 0x1620, `lbu` at 0x166c.
  The `lh` at 0x162c loads 2 bytes from sym(crimeBoards) +0x38.
  2 such `sw` accesses store 4 bytes to a2 (arg2 at entry) +0x0, including `sw` at 0x1668, `sw` at 0x16d0.
  The `jal` at 0x1658 calls i2cfp_PanelOff with a0=a2 at entry (arg2), a1=?, a2=?, a3=?.
  The `jal` at 0x16a0 calls mutex_unlock with a0=a0+468, a1=?, a2=?, a3=?.
  The `jal` at 0x16b0 calls mutex_lock with a0=a0+468, a1=0x19, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x16ec calls i2cfp_PanelOn with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=?.
  The `beq` branch at 0x1608 targets 0x1620, is taken when a1 == 0, and falls through when a1 != 0.
  The `beq` branch at 0x1614 targets 0x1620, is taken when at(=[a1+46]:1) == 0, and falls through when at(=[a1+46]:1) != 0.
  The `beq` branch at 0x1628 targets 0x1638, is taken when t8(=[a1+45]:1) == 0, and falls through when t8(=[a1+45]:1) != 0.
  The `bne` branch at 0x1630 targets 0x16b0, is taken when s0(=a0) != 0, and falls through when s0(=a0) == 0.
  The `beq` branch at 0x1638 targets 0x16c0, is taken when s7(=a3) == 0, and falls through when s7(=a3) != 0.
  The `beq` branch at 0x1640 targets 0x1664, is taken when s4(=a4) == 0, and falls through when s4(=a4) != 0.
  The `beq` branch at 0x1648 targets 0x1664, is taken when s3(=one of 0x0, 0x1) == 0, and falls through when s3(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x1650 targets 0x1664, is taken when s5(=[sym(crimeBoards)+56]:2) == 0, and falls through when s5(=[sym(crimeBoards)+56]:2) != 0.
  The `beq` branch at 0x1670 targets 0x167c, is taken when ra(=[a1+45]:1) == 0, and falls through when ra(=[a1+45]:1) != 0.
  The `bne` branch at 0x1678 targets 0x16a0, is taken when s0(=a0) != 0, and falls through when s0(=a0) == 0.
  The `beq` branch at 0x16a8 targets 0x1680 and is always taken.
  The `beq` branch at 0x16b8 targets 0x1638 and is always taken.
  The `beq` branch at 0x16c0 targets 0x16d4, is taken when s4(=a4) == 0, and falls through when s4(=a4) != 0.
  The `beq` branch at 0x16cc targets 0x166c and is always taken.
  The `beq` branch at 0x16d4 targets 0x16c8, is taken when s3(=one of 0x0, 0x1) == 0, and falls through when s3(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x16dc targets 0x16c8, is taken when s5(=[sym(crimeBoards)+56]:2) == 0, and falls through when s5(=[sym(crimeBoards)+56]:2) != 0.
  The `beq` branch at 0x16f4 targets 0x16c8 and is always taken.
  The return at 0x1698 has v0 = one of ?, ret(mutex_unlock).

- `gbeStop` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_init.o)` at 0x16fc (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_init.o)`.
  Range: 0x16fc-0x18a0 (420 bytes).
  It occupies 420 bytes.
  The `lw` at 0x1738 loads 4 bytes from sym(crimeBoards) +0xc.
  The `lw` at 0x1748 loads 4 bytes from a0 (arg0 at entry) +0x3000c.
  The `sw` at 0x1750 stores 4 bytes to a1 (arg1 at entry) +0x0.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x3000c, including `sw` at 0x175c, `sw` at 0x183c.
  The `lw` at 0x176c loads 4 bytes from a0 (arg0 at entry) +0x20008.
  The `sw` at 0x1770 stores 4 bytes to a2 (arg2 at entry) +0x0.
  The `sw` at 0x177c stores 4 bytes to a0 (arg0 at entry) +0x20008.
  The `lw` at 0x178c loads 4 bytes from a0 (arg0 at entry) +0x40004.
  The `sw` at 0x1794 stores 4 bytes to a3 (arg3 at entry) +0x0.
  The `sw` at 0x17a0 stores 4 bytes to a0 (arg0 at entry) +0x40004.
  The `lw` at 0x17a4 loads 4 bytes from a2 (arg2 at entry) +0x0.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x30008, including `lw` at 0x17dc, `lw` at 0x1864.
  The `lw` at 0x17ec loads 4 bytes from a0 (arg0 at entry) +0x20004.
  The `lw` at 0x180c loads 4 bytes from a0 (arg0 at entry) +0x40000.
  2 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x0, including `lw` at 0x182c, `lw` at 0x1860.
  The `jal` at 0x1734 calls gbeCacheVtInfo with a0=[sym(crimeBoards)+12], a1=0x0, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1758 calls flushbus with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1778 calls flushbus with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x179c calls flushbus with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x17c4 calls us_delay with a0=0xa, a1=?, a2=?, a3=?.
  The `jal` at 0x17fc calls us_delay with a0=0xa, a1=?, a2=?, a3=?.
  The `jal` at 0x181c calls us_delay with a0=0xa, a1=?, a2=?, a3=?.
  The `jal` at 0x1838 calls flushbus with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1848 calls us_delay with a0=0xa, a1=[a0+196616], a2=?, a3=?.
  The `bne` branch at 0x17b4 targets 0x17dc, is taken when (t8(=[a2]) & 0x1) != 0, and falls through when (t8(=[a2]) & 0x1) == 0.
  The `beq` branch at 0x17bc targets 0x1878 and is always taken.
  The `beq` branch at 0x17d4 targets 0x182c, is taken when s0(?) >= 0x4e20 (signed), and falls through when s0(?) < 0x4e20 (signed).
  The `bne` branch at 0x17e4 targets 0x17c4, is taken when (ra(=[a0+196616]) & 0x1) != 0, and falls through when (ra(=[a0+196616]) & 0x1) == 0.
  The `beq` branch at 0x17f4 targets 0x180c, is taken when (at(=[a0+131076]) & 0x1) == 0, and falls through when (at(=[a0+131076]) & 0x1) != 0.
  The `beq` branch at 0x1804 targets 0x17d0 and is always taken.
  The `beq` branch at 0x1814 targets 0x182c, is taken when (s5(=0x10000) & v0(=[a0+262144])) == 0, and falls through when (s5(=0x10000) & v0(=[a0+262144])) != 0.
  The `beq` branch at 0x1824 targets 0x17d0 and is always taken.
  The `beq` branch at 0x1840 targets 0x1860 and is always taken.
  The `beq` branch at 0x1858 targets 0x1878, is taken when s0(?) >= 0x4e20 (signed), and falls through when s0(?) < 0x4e20 (signed).
  The `bne` branch at 0x1870 targets 0x1848, is taken when a1(=[a0+196616]) != a2(?), and falls through when a1(=[a0+196616]) == a2(?).
  The return at 0x1898 has v0 = one of ret(flushbus), ret(us_delay), ?.
