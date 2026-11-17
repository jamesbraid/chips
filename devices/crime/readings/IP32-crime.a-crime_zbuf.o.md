# Readings: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_zbuf.o)`

One entry per routine, filed here from the reading batches by binary.

- `crmAddZ` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_zbuf.o)` at 0x0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_zbuf.o)`.
  Range: 0x0-0x304 (772 bytes).
  It occupies 772 bytes.
  The `lw` at 0xc loads 4 bytes from a0 (arg0 at entry) +0x20.
  The `lw` at 0x14 loads 4 bytes from [a0+32] +0x1c.
  6 such `lw` accesses load 4 bytes from [[a0+32]+28] +0x0, including `lw` at 0x1c, `lw` at 0x158, `lw` at 0x208.
  The `lbu` at 0x24 loads 1 byte from [[[a0+32]+28]] +0x19.
  The `lbu` at 0x40 loads 1 byte from [[[a0+32]+28]] +0x18.
  9 such `lhu` accesses load 2 bytes from ?, including `lhu` at 0x60, `lhu` at 0x90, `lhu` at 0x124.
  9 such `sh` accesses store 2 bytes to ?, including `sh` at 0x74, `sh` at 0x88, `sh` at 0xbc.
  2 such `lh` accesses load 2 bytes from ?, including `lh` at 0xe4, `lh` at 0x114.
  The `lw` at 0x16c loads 4 bytes from [[[a0+32]+28]] +0xc.
  The `lbu` at 0x20c loads 1 byte from [[[a0+32]+28]] +0x15.
  The `lh` at 0x220 loads 2 bytes from (sym(crm_tileusage) + ([[[[a0+32]+28]]+21]:1 + [[[[a0+32]+28]]+21]:1)) +0x0.
  The `sh` at 0x228 stores 2 bytes to (sym(crm_tileusage) + ([[[[a0+32]+28]]+21]:1 + [[[[a0+32]+28]]+21]:1)) +0x0.
  The `lh` at 0x22c loads 2 bytes from sym(crm_tileusage) +0x2.
  The `sh` at 0x234 stores 2 bytes to sym(crm_tileusage) +0x2.
  The `lw` at 0x23c loads 4 bytes from [[[a0+32]+28]] +0x4.
  The `sw` at 0x248 stores 4 bytes to [[[a0+32]+28]] +0x4.
  The `sw` at 0x254 stores 4 bytes to [[[a0+32]+28]] +0x10.
  The `lw` at 0x28c loads 4 bytes from [[[a0+32]+28]] +0x8.
  The `jal` at 0x14c calls kern_malloc with a0=?, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x168 calls crmAllocTiles with a0=ret(kern_malloc), a1=?, a2=[[[[a0+32]+28]]+12], a3=0x4.
  The `jal` at 0x1c8 calls crmSubtractZ with a0=a0 at entry (arg0), a1=sp-96, a2=?, a3=?.
  The `jal` at 0x1d0 calls kern_free with a0=ret(kern_malloc), a1=?, a2=?, a3=?.
  The `jal` at 0x244 calls crmNextIncarnation with a0=?, a1=a1 at entry (arg1), a2=?, a3=?.
  The `blez` branch at 0x3c targets 0x200, is taken when s2(=[[[[a0+32]+28]]+25]:1) <= 0 (signed), and falls through when s2(=[[[[a0+32]+28]]+25]:1) > 0 (signed).
  The `beq` branch at 0x54 targets 0x80 and is always taken.
  The `bne` branch at 0x70 targets 0xf4, is taken when (a6(?) & 0xffff) != 0, and falls through when (a6(?) & 0xffff) == 0.
  The `beq` branch at 0x78 targets 0x144, is taken when ra(?) == 0, and falls through when ra(?) != 0.
  The `beq` branch at 0xa4 targets 0x78, is taken when a7(?) == 0, and falls through when a7(?) != 0.
  The `blez` branch at 0xac targets 0x78, is taken when s0(=[[[[a0+32]+28]]+24]:1) <= 0 (signed), and falls through when s0(=[[[[a0+32]+28]]+24]:1) > 0 (signed).
  The `beq` branch at 0xb4 targets 0x2fc and is always taken.
  The `beq` branch at 0xc8 targets 0x78, is taken when t0(?) == 0, and falls through when t0(?) != 0.
  The `beq` branch at 0xdc targets 0xf4, is taken when (a6(?) & a4(?)) == 0, and falls through when (a6(?) & a4(?)) != 0.
  The `beq` branch at 0xe8 targets 0x5c, is taken when t0(?) == 0, and falls through when t0(?) != 0.
  The `beq` branch at 0xfc targets 0x78, is taken when t1(?) == 0, and falls through when t1(?) != 0.
  The `beq` branch at 0x10c targets 0xc0, is taken when (a6(?) & a4(?)) == 0, and falls through when (a6(?) & a4(?)) != 0.
  The `bne` branch at 0x118 targets 0xbc, is taken when t1(?) != 0, and falls through when t1(?) == 0.
  The `bne` branch at 0x134 targets 0xc0, is taken when (a6(?) & 0xffff) != 0, and falls through when (a6(?) & 0xffff) == 0.
  The `beq` branch at 0x13c targets 0x78 and is always taken.
  The `beq` branch at 0x144 targets 0x200, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `beq` branch at 0x170 targets 0x208, is taken when v0(=ret(crmAllocTiles)) == 0, and falls through when v0(=ret(crmAllocTiles)) != 0.
  The `beq` branch at 0x198 targets 0x1c8, is taken when a4(?) >= s2(=[[[[a0+32]+28]]+25]:1) (signed), and falls through when a4(?) < s2(=[[[[a0+32]+28]]+25]:1) (signed).
  The `bne` branch at 0x1bc targets 0x180, is taken when a4(?) < s2(=[[[[a0+32]+28]]+25]:1) (signed), and falls through when a4(?) >= s2(=[[[[a0+32]+28]]+25]:1) (signed).
  The `beq` branch at 0x200 targets 0x1dc and is always taken.
  The `blez` branch at 0x250 targets 0x2f4, is taken when s2(=[[[[a0+32]+28]]+25]:1) <= 0 (signed), and falls through when s2(=[[[[a0+32]+28]]+25]:1) > 0 (signed).
  The `beq` branch at 0x280 targets 0x2dc, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `blez` branch at 0x290 targets 0x2dc, is taken when s0(=[[[[a0+32]+28]]+24]:1) <= 0 (signed), and falls through when s0(=[[[[a0+32]+28]]+24]:1) > 0 (signed).
  The `beq` branch at 0x2a8 targets 0x2cc, is taken when (t0(?) & a7(?)) == 0, and falls through when (t0(?) & a7(?)) != 0.
  The `beq` branch at 0x2c4 targets 0x2dc, is taken when (t3(?) & 0xffff) == 0, and falls through when (t3(?) & 0xffff) != 0.
  The `bne` branch at 0x2d4 targets 0x298, is taken when t1(?) != 0, and falls through when t1(?) == 0.
  The `bne` branch at 0x2ec targets 0x270, is taken when v0(?) < s2(=[[[[a0+32]+28]]+25]:1) (signed), and falls through when v0(?) >= s2(=[[[[a0+32]+28]]+25]:1) (signed).
  The `beq` branch at 0x2f4 targets 0x1dc and is always taken.
  The `beq` branch at 0x2fc targets 0xd4 and is always taken.
  The return at 0x1f8 has v0 = one of 0x0, 0xc.

- `crmSubtractZ` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_zbuf.o)` at 0x304 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_zbuf.o)`.
  Range: 0x304-0x47c (376 bytes).
  It occupies 376 bytes.
  The `lw` at 0x32c loads 4 bytes from a0 (arg0 at entry) +0x20.
  The `lw` at 0x330 loads 4 bytes from [a0+32] +0x1c.
  5 such `lw` accesses load 4 bytes from [[a0+32]+28] +0x0, including `lw` at 0x334, `lw` at 0x3e8, `lw` at 0x418.
  The `lbu` at 0x338 loads 1 byte from [[[a0+32]+28]] +0x19.
  The `lbu` at 0x35c loads 1 byte from [[[a0+32]+28]] +0x18.
  The `lh` at 0x38c loads 2 bytes from ?.
  3 such `sh` accesses store 2 bytes to ?, including `sh` at 0x3a0, `sh` at 0x3b4, `sh` at 0x3c0.
  2 such `lhu` accesses load 2 bytes from ?, including `lhu` at 0x3ac, `lhu` at 0x3d8.
  The `lw` at 0x3ec loads 4 bytes from [[[a0+32]+28]] +0x8.
  The `lw` at 0x41c loads 4 bytes from [[[a0+32]+28]] +0x4.
  The `sw` at 0x428 stores 4 bytes to [[[a0+32]+28]] +0x4.
  The `sw` at 0x430 stores 4 bytes to [[[a0+32]+28]] +0x10.
  The `lbu` at 0x43c loads 1 byte from [[[a0+32]+28]] +0x15.
  The `lw` at 0x448 loads 4 bytes from [[[a0+32]+28]] +0xc.
  The `lhu` at 0x478 loads 2 bytes from a1 (arg1 at entry) +0x0.
  The `jal` at 0x324 calls kern_malloc with a0=0x200, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x424 calls crmNextIncarnation with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x444 calls crmFreeTiles with a0=ret(kern_malloc), a1=?, a2=[[[[a0+32]+28]]+12], a3=[[[[a0+32]+28]]+21]:1.
  The `jal` at 0x458 calls kern_free with a0=ret(kern_malloc), a1=?, a2=?, a3=?.
  The `blez` branch at 0x358 targets 0x44c, is taken when s2(=[[[[a0+32]+28]]+25]:1) <= 0 (signed), and falls through when s2(=[[[[a0+32]+28]]+25]:1) > 0 (signed).
  The `beq` branch at 0x360 targets 0x474 and is always taken.
  The `beq` branch at 0x370 targets 0x3c4, is taken when t1(?) == 0, and falls through when t1(?) != 0.
  The `beq` branch at 0x384 targets 0x368, is taken when (t2(?) & a5(?)) == 0, and falls through when (t2(?) & a5(?)) != 0.
  The `bne` branch at 0x39c targets 0x368, is taken when v0(?) != 0, and falls through when v0(?) == 0.
  The `bne` branch at 0x3bc targets 0x368, is taken when (t2(?) & 0xffff) != 0, and falls through when (t2(?) & 0xffff) == 0.
  The `beq` branch at 0x3d0 targets 0x410, is taken when ra(?) >= s2(=[[[[a0+32]+28]]+25]:1) (signed), and falls through when ra(?) < s2(=[[[[a0+32]+28]]+25]:1) (signed).
  The `beq` branch at 0x3e0 targets 0x3c4, is taken when at(?) == 0, and falls through when at(?) != 0.
  The `blez` branch at 0x3f0 targets 0x3c4, is taken when t3(=[[[[a0+32]+28]]+24]:1) <= 0 (signed), and falls through when t3(=[[[[a0+32]+28]]+24]:1) > 0 (signed).
  The `beq` branch at 0x408 targets 0x378 and is always taken.
  The `beq` branch at 0x410 targets 0x450, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0x474 targets 0x3dc and is always taken.
  The return at 0x46c has v0 = ret(kern_free).
