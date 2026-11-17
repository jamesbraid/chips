# Readings: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_tp.o)`

One entry per routine, filed here from the reading batches by binary.

- `crime_mapcolor` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_tp.o)` at 0x2c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_tp.o)`.
  Range: 0x2c-0xd0 (164 bytes).
  It occupies 164 bytes.
  The `lw` at 0x30 loads 4 bytes from sym(crimeBoards) +0x4.
  2 such `lw` accesses load 4 bytes from [sym(crimeBoards)+4] +0x58000, including `lw` at 0x3c, `lw` at 0x7c.
  The `sw` at 0xcc stores 4 bytes to ([sym(crimeBoards)+4] + (a1 << 0x2)) +0x54404.
  The `jal` at 0x6c calls us_delay with a0=0x1, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a5=[[sym(crimeBoards)+4]+360448], a6=[sym(crimeBoards)+4].
  The `beq` branch at 0x48 targets 0x98, is taken when (a5(=[[sym(crimeBoards)+4]+360448]) & 0x3f) == 0, and falls through when (a5(=[[sym(crimeBoards)+4]+360448]) & 0x3f) != 0.
  The `bne` branch at 0x64 targets 0x98, is taken when a5(=[[sym(crimeBoards)+4]+360448]) != 0, and falls through when a5(=[[sym(crimeBoards)+4]+360448]) == 0.
  The `bne` branch at 0x90 targets 0x54, is taken when (a5(=[[sym(crimeBoards)+4]+360448]) & 0x3f) != 0, and falls through when (a5(=[[sym(crimeBoards)+4]+360448]) & 0x3f) == 0.
  The return at 0xc8 has v0 = one of ?, ret(us_delay).

- `crime_sboxfi` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_tp.o)` at 0xd0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_tp.o)`.
  Range: 0xd0-0x1f8 (296 bytes).
  It occupies 296 bytes.
  The `lw` at 0xfc loads 4 bytes from sym(crimeBoards) +0x10.
  The `lw` at 0x114 loads 4 bytes from [sym(crimeBoards)+16] +0x4.
  The `lw` at 0x128 loads 4 bytes from sym(.bss) +0x8.
  The `lw` at 0x12c loads 4 bytes from sym(.bss) +0x10.
  The `sw` at 0x134 stores 4 bytes to [[sym(crimeBoards)+16]+4] +0x18.
  The `sw` at 0x138 stores 4 bytes to a0 (arg0 at entry) +0x2018.
  The `sw` at 0x14c stores 4 bytes to [[sym(crimeBoards)+16]+4] +0xd0.
  The `sw` at 0x150 stores 4 bytes to a0 (arg0 at entry) +0x20d0.
  2 such `sw` accesses store 4 bytes to [[sym(crimeBoards)+16]+4] +0x60, including `sw` at 0x168, `sw` at 0x184.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x2060, including `sw` at 0x170, `sw` at 0x188.
  The `sw` at 0x1b0 stores 4 bytes to [[sym(crimeBoards)+16]+4] +0x70.
  The `sd` at 0x1b8 stores 8 bytes to a0 (arg0 at entry) +0x2070.
  The `sw` at 0x1c4 stores 4 bytes to (a0+8688 | 0x800) +0x0.
  The `sw` at 0x1d0 stores 4 bytes to a0 (arg0 at entry) +0x21f8.
  The `jal` at 0x110 calls crmFifoWait with a0=a0 at entry (arg0), a1=0x7, a2=0xabcde, a3=a3 at entry (arg3).
  The `jal` at 0x1cc calls crmIdleWait with a0=a0 at entry (arg0), a1=0xabcde, a2=(a0+8688 | 0x800), a3=?, a6=(a1 << 0x10).
  The `beq` branch at 0x154 targets 0x174, is taken when s1(?) == a6(=0x1), and falls through when s1(?) != a6(=0x1).
  The `beq` branch at 0x160 targets 0x184, is taken when t9(?) == 0, and falls through when t9(?) != 0.
  The `beq` branch at 0x16c targets 0x18c and is always taken.
  The `bne` branch at 0x174 targets 0x160, is taken when s0(?) != a6(=0x1), and falls through when s0(?) == a6(=0x1).
  The `bltz` branch at 0x17c targets 0x1f0, is taken when s0(?) < 0 (signed), and falls through when s0(?) >= 0 (signed).
  The `beq` branch at 0x1f0 targets 0x168 and is always taken.
  The return at 0x1e8 has v0 = ret(crmIdleWait).

- `crime_pnt2i` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_tp.o)` at 0x1f8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_tp.o)`.
  Range: 0x1f8-0x2b0 (184 bytes).
  It occupies 184 bytes.
  The `lw` at 0x20c loads 4 bytes from sym(crimeBoards) +0x10.
  The `lw` at 0x220 loads 4 bytes from [sym(crimeBoards)+16] +0x4.
  The `sw` at 0x238 stores 4 bytes to [[sym(crimeBoards)+16]+4] +0x18.
  The `sw` at 0x23c stores 4 bytes to a0 (arg0 at entry) +0x2018.
  The `sw` at 0x240 stores 4 bytes to [[sym(crimeBoards)+16]+4] +0x60.
  The `sw` at 0x244 stores 4 bytes to a0 (arg0 at entry) +0x2060.
  The `lw` at 0x258 loads 4 bytes from sym(.bss) +0x10.
  The `lw` at 0x25c loads 4 bytes from sym(.bss) +0x8.
  The `sw` at 0x260 stores 4 bytes to [[sym(crimeBoards)+16]+4] +0xd0.
  The `sw` at 0x26c stores 4 bytes to a0 (arg0 at entry) +0x20d0.
  The `sw` at 0x27c stores 4 bytes to [[sym(crimeBoards)+16]+4] +0x70.
  The `sw` at 0x284 stores 4 bytes to a0 (arg0 at entry) +0x2070.
  The `sw` at 0x290 stores 4 bytes to (a0+8688 | 0x800) +0x0.
  The `sw` at 0x29c stores 4 bytes to a0 (arg0 at entry) +0x21f8.
  The `jal` at 0x228 calls crmFifoWait with a0=a0 at entry (arg0), a1=0x6, a2=0xabcde, a3=a3 at entry (arg3).
  The `jal` at 0x298 calls crmIdleWait with a0=a0 at entry (arg0), a1=0xabcde, a2=(a0+8688 | 0x800), a3=?, a4=[[sym(crimeBoards)+16]+4], a6=[sym(.bss)+8], a7=a2 at entry (arg2).
  The return at 0x2a8 has v0 = ret(crmIdleWait).

- `crime_drawbitmap` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_tp.o)` at 0x2c4 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_tp.o)`.
  Range: 0x2c4-0x944 (1664 bytes).
  It occupies 1664 bytes.
  The `lw` at 0x2d0 loads 4 bytes from a1 (arg1 at entry) +0x0.
  The `lh` at 0x2d8 loads 2 bytes from a1 (arg1 at entry) +0x6.
  The `lh` at 0x2e0 loads 2 bytes from a1 (arg1 at entry) +0x4.
  The `lh` at 0x2e8 loads 2 bytes from a1 (arg1 at entry) +0x8.
  The `lh` at 0x2f0 loads 2 bytes from a1 (arg1 at entry) +0xa.
  2 such `lw` accesses load 4 bytes from sym(.bss) +0x0, including `lw` at 0x30c, `lw` at 0x4c8.
  The `lw` at 0x31c loads 4 bytes from sym(.bss) +0x10.
  2 such `lw` accesses load 4 bytes from sym(.bss) +0x4, including `lw` at 0x328, `lw` at 0x4c4.
  The `lw` at 0x334 loads 4 bytes from sym(crimeBoards) +0x10.
  The `lw` at 0x338 loads 4 bytes from sym(.bss) +0x8.
  The `lw` at 0x344 loads 4 bytes from [sym(crimeBoards)+16] +0x4.
  The `sw` at 0x368 stores 4 bytes to [[sym(crimeBoards)+16]+4] +0x18.
  The `sw` at 0x370 stores 4 bytes to a0 (arg0 at entry) +0x2018.
  The `sw` at 0x378 stores 4 bytes to [[sym(crimeBoards)+16]+4] +0x60.
  The `sw` at 0x37c stores 4 bytes to a0 (arg0 at entry) +0x2060.
  The `sw` at 0x380 stores 4 bytes to [[sym(crimeBoards)+16]+4] +0xd0.
  The `sw` at 0x384 stores 4 bytes to a0 (arg0 at entry) +0x20d0.
  The `sw` at 0x390 stores 4 bytes to [[sym(crimeBoards)+16]+4] +0xc0.
  The `sw` at 0x398 stores 4 bytes to a0 (arg0 at entry) +0x20c0.
  10 such `lhu` accesses load 2 bytes from ?, including `lhu` at 0x3d8, `lhu` at 0x460, `lhu` at 0x53c.
  8 such `sw` accesses store 4 bytes to [[sym(crimeBoards)+16]+4] +0x70, including `sw` at 0x3e4, `sw` at 0x468, `sw` at 0x550.
  8 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x2070, including `sd` at 0x3ec, `sd` at 0x470, `sd` at 0x55c.
  8 such `sw` accesses store 4 bytes to [[sym(crimeBoards)+16]+4] +0xc4, including `sw` at 0x3f8, `sw` at 0x47c, `sw` at 0x568.
  7 such `sw` accesses store 4 bytes to (a0+8388 | 0x800) +0x0, including `sw` at 0x404, `sw` at 0x488, `sw` at 0x574.
  The `sw` at 0x4a0 stores 4 bytes to a0 (arg0 at entry) +0x21f8.
  The `lh` at 0x4ac loads 2 bytes from a1 (arg1 at entry) +0xe.
  The `lh` at 0x4b0 loads 2 bytes from a1 (arg1 at entry) +0xc.
  The `sw` at 0x4d0 stores 4 bytes to sym(.bss) +0x4.
  The `sw` at 0x4d8 stores 4 bytes to sym(.bss) +0x0.
  The `sw` at 0x5f8 stores 4 bytes to a0 (arg0 at entry) +0x20c4.
  The `sw` at 0x604 stores 4 bytes to (a0+8688 | 0x800) +0x0.
  The `jal` at 0x348 calls crmFifoWait with a0=a0 at entry (arg0), a1=0x14, a2=0xabcde, a3=a3 at entry (arg3).
  The `jal` at 0x410 calls crmFifoWait with a0=a0 at entry (arg0), a1=0x10, a2=0xabcde, a3=?.
  The `jal` at 0x4a4 calls crmIdleWait with a0=a0 at entry (arg0), a1=0xabcde, a2=?, a3=?.
  The `jal` at 0x580 calls crmFifoWait with a0=a0 at entry (arg0), a1=0x10, a2=0xabcde, a3=?.
  The `jal` at 0x6cc calls crmFifoWait with a0=a0 at entry (arg0), a1=0x10, a2=0xabcde, a3=?.
  The `jal` at 0x790 calls crmFifoWait with a0=a0 at entry (arg0), a1=0x10, a2=0xabcde, a3=?.
  The `jal` at 0x918 calls crmFifoWait with a0=a0 at entry (arg0), a1=0x10, a2=0xabcde, a3=?.
  The `beq` branch at 0x394 targets 0x4fc, is taken when s0(=[a1+4]:2) >= 0x11 (signed), and falls through when s0(=[a1+4]:2) < 0x11 (signed).
  The `beq` branch at 0x3a0 targets 0x428, is taken when v1(?) == 0, and falls through when v1(?) != 0.
  The `bne` branch at 0x400 targets 0x3cc, is taken when a0(?) < 0x10 (signed), and falls through when a0(?) >= 0x10 (signed).
  The `beq` branch at 0x420 targets 0x3cc, is taken when s8(?) >= 0x11 (signed), and falls through when s8(?) < 0x11 (signed).
  The `beq` branch at 0x428 targets 0x48c, is taken when s8(?) == 0, and falls through when s8(?) != 0.
  The `bne` branch at 0x484 targets 0x454, is taken when a0(?) != a1(=-0x1), and falls through when a0(?) == a1(=-0x1).
  The `beq` branch at 0x500 targets 0x610, is taken when s0(=[a1+4]:2) >= 0x21 (signed), and falls through when s0(=[a1+4]:2) < 0x21 (signed).
  The `beq` branch at 0x50c targets 0x598, is taken when t9(?) == 0, and falls through when t9(?) != 0.
  The `bne` branch at 0x570 targets 0x534, is taken when a0(?) < 0x10 (signed), and falls through when a0(?) >= 0x10 (signed).
  The `beq` branch at 0x590 targets 0x534, is taken when s8(?) >= 0x11 (signed), and falls through when s8(?) < 0x11 (signed).
  The `beq` branch at 0x598 targets 0x48c, is taken when s8(?) == 0, and falls through when s8(?) != 0.
  The `bne` branch at 0x600 targets 0x5c4, is taken when a0(?) != a1(=-0x1), and falls through when a0(?) == a1(=-0x1).
  The `beq` branch at 0x608 targets 0x490 and is always taken.
  The `beq` branch at 0x634 targets 0x87c, is taken when a0(?) >= v0(?) (signed), and falls through when a0(?) < v0(?) (signed).
  The `beq` branch at 0x658 targets 0x7a8 and is always taken.
  The `bne` branch at 0x6b8 targets 0x670, is taken when a0(?) < 0x10 (signed), and falls through when a0(?) >= 0x10 (signed).
  The `beq` branch at 0x6e8 targets 0x66c, is taken when a4(?) >= 0x11 (signed), and falls through when a4(?) < 0x11 (signed).
  The `beq` branch at 0x6f0 targets 0x764, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `blez` branch at 0x6f8 targets 0x764, is taken when a4(?) <= 0 (signed), and falls through when a4(?) > 0 (signed).
  The `bgez` branch at 0x75c targets 0x718, is taken when a0(?) >= 0 (signed), and falls through when a0(?) < 0 (signed).
  The `beq` branch at 0x7a0 targets 0x7d0, is taken when s2(?) >= ra(?) (signed), and falls through when s2(?) < ra(?) (signed).
  The `bne` branch at 0x7bc targets 0x660, is taken when at(?) != 0, and falls through when at(?) == 0.
  The `beq` branch at 0x7c8 targets 0x6f0 and is always taken.
  The `bne` branch at 0x7d4 targets 0x89c, is taken when a2(?) != 0, and falls through when a2(?) == 0.
  The `beq` branch at 0x7ec targets 0x490, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `blez` branch at 0x7f8 targets 0x48c, is taken when t8(?) <= 0 (signed), and falls through when t8(?) > 0 (signed).
  The `bgez` branch at 0x86c targets 0x82c, is taken when a0(?) >= 0 (signed), and falls through when a0(?) < 0 (signed).
  The `beq` branch at 0x874 targets 0x490 and is always taken.
  The `beq` branch at 0x880 targets 0x7dc, is taken when at(?) == 0, and falls through when at(?) != 0.
  The `bne` branch at 0x908 targets 0x8c4, is taken when a0(?) < 0x10 (signed), and falls through when a0(?) >= 0x10 (signed).
  The `beq` branch at 0x934 targets 0x8c0, is taken when v0(?) >= 0x11 (signed), and falls through when v0(?) < 0x11 (signed).
  The `beq` branch at 0x93c targets 0x7ec and is always taken.
  The return at 0x4f4 has v0 = ret(crmIdleWait).

- `crime_clearfb` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_tp.o)` at 0x9bc (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_tp.o)`.
  Range: 0x9bc-0xad8 (284 bytes).
  It occupies 284 bytes.
  The `lw` at 0x9d8 loads 4 bytes from sym(crimeBoards) +0x8.
  The `lw` at 0x9e4 loads 4 bytes from sym(crimeBoards) +0x10.
  The `sh` at 0x9ec stores 2 bytes to sym(crimeBoards) +0x3c.
  The `lw` at 0x9f0 loads 4 bytes from [sym(crimeBoards)+16] +0x4.
  The `lbu` at 0xa00 loads 1 byte from [sym(crimeBoards)+8] +0x2d.
  The `lhu` at 0xa04 loads 2 bytes from [sym(crimeBoards)+8] +0x22.
  The `lhu` at 0xa10 loads 2 bytes from [sym(crimeBoards)+8] +0x20.
  The `sw` at 0xa2c stores 4 bytes to sym(.bss) +0xc.
  The `sw` at 0xa38 stores 4 bytes to sym(.bss) +0x10.
  The `sw` at 0xa3c stores 4 bytes to sym(.bss) +0x8.
  The `sw` at 0xa5c stores 4 bytes to [[sym(crimeBoards)+16]+4] +0x50.
  The `sw` at 0xa60 stores 4 bytes to a0 (arg0 at entry) +0x2050.
  The `sw` at 0xa64 stores 4 bytes to [[sym(crimeBoards)+16]+4] +0x58.
  The `sw` at 0xa68 stores 4 bytes to a0 (arg0 at entry) +0x2058.
  The `sw` at 0xa70 stores 4 bytes to [[sym(crimeBoards)+16]+4] +0x10.
  The `sw` at 0xa78 stores 4 bytes to a0 (arg0 at entry) +0x2010.
  The `sd` at 0xa80 stores 8 bytes to [[sym(crimeBoards)+16]+4] +0x20.
  The `sd` at 0xa84 stores 8 bytes to a0 (arg0 at entry) +0x2020.
  The `sw` at 0xa8c stores 4 bytes to [[sym(crimeBoards)+16]+4] +0x1b0.
  The `sw` at 0xa90 stores 4 bytes to a0 (arg0 at entry) +0x21b0.
  The `sw` at 0xa98 stores 4 bytes to [[sym(crimeBoards)+16]+4] +0x0.
  The `sw` at 0xa9c stores 4 bytes to a0 (arg0 at entry) +0x2000.
  The `sw` at 0xaa8 stores 4 bytes to [[sym(crimeBoards)+16]+4] +0x8.
  The `sw` at 0xaac stores 4 bytes to a0 (arg0 at entry) +0x2008.
  The `jal` at 0x9f8 calls bzero with a0=[[sym(crimeBoards)+16]+4], a1=0x288, a2=sym(crimeBoards), a3=a3 at entry (arg3).
  The `jal` at 0xa40 calls crime_mapcolor with a0=a0 at entry (arg0), a1=0x0, a2=0x0, a3=0x0, a4=0x0, a6=0x1.
  The `jal` at 0xa50 calls crmIdleWait with a0=a0 at entry (arg0), a1=0xabcde, a2=?, a3=?.
  The `jal` at 0xab8 calls crime_sboxfi with a0=a0 at entry (arg0), a1=0x0, a2=0x0, a3=[[sym(crimeBoards)+8]+32]:2, a6=0x21.
  The `beq` branch at 0xa0c targets 0xa18, is taken when a3(=[[sym(crimeBoards)+8]+45]:1) == 0, and falls through when a3(=[[sym(crimeBoards)+8]+45]:1) != 0.
  The return at 0xad0 has v0 = ret(crime_sboxfi).

- `crime_tpinit` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_tp.o)` at 0xad8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_tp.o)`.
  Range: 0xad8-0xbc0 (232 bytes).
  It occupies 232 bytes.
  The `lw` at 0xaf0 loads 4 bytes from sym(crimeBoards) +0x4.
  The `lw` at 0xb04 loads 4 bytes from sym(crimeBoards) +0x8.
  The `sw` at 0xb14 stores 4 bytes to [sym(crimeBoards)+4] +0x70008.
  The `sw` at 0xb20 stores 4 bytes to [sym(crimeBoards)+4] +0x7000c.
  The `sw` at 0xb2c stores 4 bytes to [sym(crimeBoards)+4] +0x70000.
  The `lw` at 0xb3c loads 4 bytes from sym(crmCursor) -0x4.
  4 such `sw` accesses store 4 bytes to ?, including `sw` at 0xb40, `sw` at 0xb58, `sw` at 0xb6c.
  The `sw` at 0xb94 stores 4 bytes to [sym(crimeBoards)+4] +0x70004.
  The `jal` at 0xb98 calls gbeBlankScreen with a0=0x0, a1=[sym(crimeBoards)+8], a2=[sym(crimeBoards)+4], a3=0x0, a4=0x0, a5=sym(crmCursor).
  The `jal` at 0xba8 calls crmIdleWait with a0=a0 at entry (arg0), a1=0xabcde, a2=?, a3=?.
  The `bne` branch at 0xb44 targets 0xb30, is taken when a6(?) < 0x20 (signed), and falls through when a6(?) >= 0x20 (signed).
  The `beq` branch at 0xb5c targets 0xb8c, is taken when a7(?) >= 0x40 (signed), and falls through when a7(?) < 0x40 (signed).
  The `beq` branch at 0xb70 targets 0xb88, is taken when a7(?) >= 0x40 (signed), and falls through when a7(?) < 0x40 (signed).
  The `bne` branch at 0xb80 targets 0xb50, is taken when a7(?) < 0x40 (signed), and falls through when a7(?) >= 0x40 (signed).
  The return at 0xbb8 has v0 = ret(crmIdleWait).
