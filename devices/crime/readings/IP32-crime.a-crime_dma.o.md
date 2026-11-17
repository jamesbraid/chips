# Readings: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_dma.o)`

One entry per routine, filed here from the reading batches by binary.

- `crmpixdma` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_dma.o)` at 0x80 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_dma.o)`.
  Range: 0x80-0x3f8 (888 bytes).
  It occupies 888 bytes.
  2 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x0, including `lw` at 0x80, `lw` at 0x1e4.
  5 such `lbu` accesses load 1 byte from a1 (arg1 at entry) +0x25, including `lbu` at 0x9c, `lbu` at 0x174, `lbu` at 0x254.
  The `lw` at 0xac loads 4 bytes from a1 (arg1 at entry) +0xc.
  4 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x4, including `lw` at 0xcc, `lw` at 0x118, `lw` at 0x178.
  5 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x8, including `lw` at 0xd4, `lw` at 0xf4, `lw` at 0x1b0.
  3 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x18, including `lw` at 0xf0, `lw` at 0x2dc, `lw` at 0x390.
  3 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x20, including `lw` at 0xf8, `lw` at 0x2b8, `lw` at 0x37c.
  2 such `lbu` accesses load 1 byte from a1 (arg1 at entry) +0x24, including `lbu` at 0xfc, `lbu` at 0x24c.
  3 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x10, including `lw` at 0x100, `lw` at 0x270, `lw` at 0x3b4.
  4 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x14, including `lw` at 0x104, `lw` at 0x148, `lw` at 0x258.
  The `sw` at 0x10c stores 4 bytes to a1 (arg1 at entry) +0x10.
  The `sw` at 0x114 stores 4 bytes to a1 (arg1 at entry) +0x14.
  3 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x1c, including `lw` at 0x120, `lw` at 0x25c, `lw` at 0x310.
  The `sw` at 0x128 stores 4 bytes to a1 (arg1 at entry) +0x18.
  The `sw` at 0x138 stores 4 bytes to a1 (arg1 at entry) +0x1c.
  The `sw` at 0x144 stores 4 bytes to a0 (arg0 at entry) +0x20ac.
  The `sd` at 0x2d8 stores 8 bytes to a0 (arg0 at entry) +0x2080.
  The `sd` at 0x2e8 stores 8 bytes to a0 (arg0 at entry) +0x2088.
  The `sw` at 0x2fc stores 4 bytes to (a0+8352 | 0x800) +0x0.
  The `sd` at 0x3b0 stores 8 bytes to a0 (arg0 at entry) +0x2070.
  The `sw` at 0x3c8 stores 4 bytes to a0 (arg0 at entry) +0x20a0.
  The `sw` at 0x3d0 stores 4 bytes to (a0+8368 | 0x800) +0x0.
  The `jal` at 0x208 calls loadLinearTlb with a0=a0 at entry (arg0), a1=?, a2=?, a3=?, a7=[a1+37]:1.
  The `beq` branch at 0xc4 targets 0x3e8, is taken when (at(=[a1+37]:1) & 0x1) == 0, and falls through when (at(=[a1+37]:1) & 0x1) != 0.
  The `beq` branch at 0xe8 targets 0x148, is taken when s7(=a3) == 0, and falls through when s7(=a3) != 0.
  The `blez` branch at 0x158 targets 0x348, is taken when s2(=[a1+12]) <= 0 (signed), and falls through when s2(=[a1+12]) > 0 (signed).
  The `beq` branch at 0x184 targets 0x350, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `beq` branch at 0x190 targets 0x368, is taken when (s3(?) & 0xfff) == 0, and falls through when (s3(?) & 0xfff) != 0.
  The `beq` branch at 0x1b4 targets 0x1c0, is taken when s2(?) >= s1(?) (signed), and falls through when s2(?) < s1(?) (signed).
  The `beq` branch at 0x1cc targets 0x360, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `beq` branch at 0x210 targets 0x24c, is taken when v0(=ret(loadLinearTlb)) == 0, and falls through when v0(=ret(loadLinearTlb)) != 0.
  The `beq` branch at 0x274 targets 0x294, is taken when a0(=[a1+28]) >= v1(=[a1+20]) (signed), and falls through when a0(=[a1+28]) < v1(=[a1+20]) (signed).
  The `beq` branch at 0x284 targets 0x2a8, is taken when v0(?) >= a0(=[a1+28]) (signed), and falls through when v0(?) < a0(=[a1+28]) (signed).
  The `beq` branch at 0x28c targets 0x2a8 and is always taken.
  The `beq` branch at 0x29c targets 0x2a8, is taken when a0(=[a1+28]) >= v0(?) (signed), and falls through when a0(=[a1+28]) < v0(?) (signed).
  The `beq` branch at 0x2a8 targets 0x370, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0x2b0 targets 0x3dc, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x2c0 targets 0x38c, is taken when s7(=a3) == 0, and falls through when s7(=a3) != 0.
  The `beq` branch at 0x2f4 targets 0x3b4, is taken when (a6(=[a1+37]:1) & 0x8) == 0, and falls through when (a6(=[a1+37]:1) & 0x8) != 0.
  The `beq` branch at 0x31c targets 0x3d4, is taken when (a7(=[a1+37]:1) & 0x1) == 0, and falls through when (a7(=[a1+37]:1) & 0x1) != 0.
  The `beq` branch at 0x32c targets 0x33c, is taken when a2(=[a1+28]) >= a3(=[a1+20]) (signed), and falls through when a2(=[a1+28]) < a3(=[a1+20]) (signed).
  The `beq` branch at 0x334 targets 0x340 and is always taken.
  The `bgtz` branch at 0x340 targets 0x184, is taken when s2(?) > 0 (signed), and falls through when s2(?) <= 0 (signed).
  The `beq` branch at 0x348 targets 0x21c and is always taken.
  The `beq` branch at 0x358 targets 0x1a4 and is always taken.
  The `beq` branch at 0x360 targets 0x1d8 and is always taken.
  The `beq` branch at 0x368 targets 0x1a4 and is always taken.
  The `beq` branch at 0x370 targets 0x3f0, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x384 targets 0x2c0 and is always taken.
  The `beq` branch at 0x3ac targets 0x2ec and is always taken.
  The `beq` branch at 0x3cc targets 0x300 and is always taken.
  The `beq` branch at 0x3d4 targets 0x328 and is always taken.
  The `beq` branch at 0x3e0 targets 0x2c0 and is always taken.
  The `beq` branch at 0x3e8 targets 0xe8 and is always taken.
  The `beq` branch at 0x3f0 targets 0x2c0 and is always taken.
  The return at 0x244 has v0 = one of 0x0, 0xe.

- `crimePixelDma` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_dma.o)` at 0x3f8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_dma.o)`.
  Range: 0x3f8-0x6b4 (700 bytes).
  It occupies 700 bytes.
  The `lw` at 0x40c loads 4 bytes from a1 (arg1 at entry) +0x8.
  The `lw` at 0x410 loads 4 bytes from a1 (arg1 at entry) +0x4.
  The `lw` at 0x418 loads 4 bytes from a0 (arg0 at entry) +0x18.
  The `lw` at 0x42c loads 4 bytes from [a0+24] +0x78.
  The `lw` at 0x448 loads 4 bytes from a1 (arg1 at entry) +0xc.
  The `lbu` at 0x47c loads 1 byte from a1 (arg1 at entry) +0x25.
  The `lw` at 0x490 loads 4 bytes from a0 (arg0 at entry) +0x8.
  The `lw` at 0x494 loads 4 bytes from [a0+8] +0x4.
  5 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x0, including `lw` at 0x498, `lw` at 0x568, `lw` at 0x650.
  The `lw` at 0x4a8 loads 4 bytes from a1 (arg1 at entry) +0x10.
  The `lw` at 0x4ac loads 4 bytes from a1 (arg1 at entry) +0x14.
  The `lw` at 0x4b0 loads 4 bytes from a1 (arg1 at entry) +0x1c.
  The `lw` at 0x4b8 loads 4 bytes from a1 (arg1 at entry) +0x18.
  The `sw` at 0x4c4 stores 4 bytes to a1 (arg1 at entry) +0x1c.
  The `sw` at 0x4cc stores 4 bytes to a1 (arg1 at entry) +0x18.
  The `sw` at 0x4d8 stores 4 bytes to a1 (arg1 at entry) +0x14.
  The `sw` at 0x4e4 stores 4 bytes to a1 (arg1 at entry) +0x10.
  2 such `lw` accesses load 4 bytes from [a0+24] +0x28, including `lw` at 0x5bc, `lw` at 0x628.
  2 such `lw` accesses load 4 bytes from [[a0+24]+40] +0x18, including `lw` at 0x5c0, `lw` at 0x62c.
  2 such `lw` accesses load 4 bytes from [[[a0+24]+40]+24] +0x2c, including `lw` at 0x5c4, `lw` at 0x630.
  2 such `sw` accesses store 4 bytes to [[[a0+24]+40]+24] +0x2c, including `sw` at 0x5cc, `sw` at 0x644.
  The `lw` at 0x5d0 loads 4 bytes from [a0+24] +0x4.
  The `lw` at 0x5e0 loads 4 bytes from [[a0+24]+4] +0x8.
  The `lw` at 0x618 loads 4 bytes from [[[a0+24]+4]+8] +0x10.
  The `sw` at 0x61c stores 4 bytes to [[a0+24]+120] +0x2010.
  The `sw` at 0x620 stores 4 bytes to [[a0+24]+120] +0x4008.
  The `jal` at 0x520 calls fast_userdma with a0=[a1], a1=?, a2=one of 0x0, 0x1, a3=0x0, a5=[a0+24].
  The `jal` at 0x558 calls kern_malloc with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x56c calls crm_curproc_vtop with a0=[a1], a1=?, a2=ret(kern_malloc), a3=?.
  The `jal` at 0x57c calls kern_free with a0=ret(kern_malloc), a1=?, a2=?, a3=?.
  The `jal` at 0x598 calls RRM_CheckValidFault with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x5e8 calls crmpixdma with a0=[[a0+24]+120], a1=a1 at entry (arg1), a2=ret(kern_malloc), a3=?, a4=[[[a0+24]+4]+8], a5=[[[[a0+24]+40]+24]+44]+1, a6=[[[a0+24]+40]+24].
  The `jal` at 0x604 calls crmIdleWait with a0=[[a0+24]+120], a1=0x7a120, a2=?, a3=?.
  The `jal` at 0x64c calls fast_undma with a0=[a1], a1=?, a2=one of 0x0, 0x1, a3=0x0, a4=[[[[a0+24]+40]+24]+44]-1, a5=[[[a0+24]+40]+24].
  The `jal` at 0x658 calls kern_free with a0=ret(kern_malloc), a1=?, a2=?, a3=?.
  The `jal` at 0x66c calls crimeError with a0=[[a0+24]+120], a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x684 calls fast_undma with a0=[a1], a1=?, a2=one of 0x0, 0x1, a3=0x0.
  The `jal` at 0x6a4 calls fast_undma with a0=[a1], a1=?, a2=one of 0x0, 0x1, a3=0x0.
  The `bne` branch at 0x428 targets 0x4e8, is taken when a2(=[a1+4]) < v0(=[a1+8]) (signed), and falls through when a2(=[a1+4]) >= v0(=[a1+8]) (signed).
  The `blez` branch at 0x430 targets 0x4e8, is taken when a2(=[a1+4]) <= 0 (signed), and falls through when a2(=[a1+4]) > 0 (signed).
  The `beq` branch at 0x438 targets 0x4e8, is taken when v1(?) == 0, and falls through when v1(?) != 0.
  The `bltz` branch at 0x440 targets 0x4e8, is taken when v0(=[a1+8]) < 0 (signed), and falls through when v0(=[a1+8]) >= 0 (signed).
  The `beq` branch at 0x450 targets 0x4e8, is taken when a1(=[a1+12]) >= 0x801 (signed), and falls through when a1(=[a1+12]) < 0x801 (signed).
  The `bltz` branch at 0x458 targets 0x4e8, is taken when a1(=[a1+12]) < 0 (signed), and falls through when a1(=[a1+12]) >= 0 (signed).
  The `bne` branch at 0x474 targets 0x538, is taken when a4(=0x180000) < s2(?) (signed), and falls through when a4(=0x180000) >= s2(?) (signed).
  The `beq` branch at 0x484 targets 0x540, is taken when (t9(=[a1+37]:1) & 0x8) == 0, and falls through when (t9(=[a1+37]:1) & 0x8) != 0.
  The `beq` branch at 0x49c targets 0x50c, is taken when ra(=[[a0+8]+4]) == a0, and falls through when ra(=[[a0+8]+4]) != a0.
  The `beq` branch at 0x4e0 targets 0x514 and is always taken.
  The `beq` branch at 0x528 targets 0x548, is taken when v0(=ret(fast_userdma)) == 0, and falls through when v0(=ret(fast_userdma)) != 0.
  The `beq` branch at 0x530 targets 0x4f0 and is always taken.
  The `beq` branch at 0x538 targets 0x4ec and is always taken.
  The `beq` branch at 0x540 targets 0x490 and is always taken.
  The `beq` branch at 0x574 targets 0x598, is taken when v0(=ret(crm_curproc_vtop)) == 0, and falls through when v0(=ret(crm_curproc_vtop)) != 0.
  The `beq` branch at 0x588 targets 0x67c, is taken when (s1(=one of 0x0, 0x2) & 0x1) == 0, and falls through when (s1(=one of 0x0, 0x2) & 0x1) != 0.
  The `beq` branch at 0x590 targets 0x4ec and is always taken.
  The `bgez` branch at 0x5a0 targets 0x5b8, is taken when v0(=ret(RRM_CheckValidFault)) >= 0 (signed), and falls through when v0(=ret(RRM_CheckValidFault)) < 0 (signed).
  The `beq` branch at 0x5a8 targets 0x69c, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0x5b0 targets 0x4ec and is always taken.
  The `beq` branch at 0x5f0 targets 0x600, is taken when v0(=ret(crmpixdma)) == 0, and falls through when v0(=ret(crmpixdma)) != 0.
  The `beq` branch at 0x610 targets 0x624, is taken when (s1(?) & 0x10) == 0, and falls through when (s1(?) & 0x10) != 0.
  The `beq` branch at 0x660 targets 0x694, is taken when s0(=ret(crmIdleWait)) == 0, and falls through when s0(=ret(crmIdleWait)) != 0.
  The `beq` branch at 0x674 targets 0x4ec and is always taken.
  The `beq` branch at 0x68c targets 0x590 and is always taken.
  The `beq` branch at 0x694 targets 0x4ec and is always taken.
  The `beq` branch at 0x6ac targets 0x5b0 and is always taken.
  The return at 0x504 has v0 = one of 0x0, 0x4, 0xe, 0x16, ret(fast_userdma).

- `loadLinearTlb` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_dma.o)` at 0x6b4 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_dma.o)`.
  Range: 0x6b4-0x7bc (264 bytes).
  It occupies 264 bytes.
  The `sd` at 0x718 stores 8 bytes to ?.
  The `lw` at 0x734 loads 4 bytes from ?.
  The `sw` at 0x75c stores 4 bytes to ?.
  The `lw` at 0x78c loads 4 bytes from a2 (arg2 at entry) +0x7c.
  The `beq` branch at 0x6bc targets 0x7a4, is taken when a4 == 0, and falls through when a4 != 0.
  The `beq` branch at 0x6e4 targets 0x6f4, is taken when (a1(?) & 0x1) == 0, and falls through when (a1(?) & 0x1) != 0.
  The `beq` branch at 0x6ec targets 0x78c, is taken when a3 == a0(=0x20), and falls through when a3 != a0(=0x20).
  The `blez` branch at 0x6f8 targets 0x770, is taken when a3(?) <= 0 (signed), and falls through when a3(?) > 0 (signed).
  The `beq` branch at 0x700 targets 0x7b4 and is always taken.
  The `beq` branch at 0x728 targets 0x770, is taken when t0(?) == 0, and falls through when t0(?) != 0.
  The `beq` branch at 0x748 targets 0x784, is taken when a7(?) == 0, and falls through when a7(?) != 0.
  The `bne` branch at 0x758 targets 0x708, is taken when a6(?) != 0, and falls through when a6(?) == 0.
  The `bne` branch at 0x760 targets 0x71c, is taken when v0(?) != a3(?), and falls through when v0(?) == a3(?).
  The `beq` branch at 0x768 targets 0x70c and is always taken.
  The `beq` branch at 0x784 targets 0x774 and is always taken.
  The `beq` branch at 0x794 targets 0x7ac, is taken when a0(=[a2+124]) == 0, and falls through when a0(=[a2+124]) != 0.
  The `beq` branch at 0x79c targets 0x6f8 and is always taken.
  The `beq` branch at 0x7a4 targets 0x6c8 and is always taken.
  The `beq` branch at 0x7ac targets 0x774 and is always taken.
  The `beq` branch at 0x7b4 targets 0x734 and is always taken.
  The return at 0x77c has v0 = one of -0x1, 0x0.

- `crime_load_linear_tlb` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_dma.o)` at 0x7bc (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_dma.o)`.
  Range: 0x7bc-0xb3c (896 bytes).
  It occupies 896 bytes.
  The `lw` at 0x7cc loads 4 bytes from a1 (arg1 at entry) +0x4c.
  The `lw` at 0x7d4 loads 4 bytes from a2 (arg2 at entry) +0x78.
  6 such `lw` accesses load 4 bytes from a3 (arg3 at entry) +0x8, including `lw` at 0x7e4, `lw` at 0x89c, `lw` at 0x944.
  4 such `lw` accesses load 4 bytes from ([a1+76] + one of 0x30, 0x40) +0x0, including `lw` at 0x810, `lw` at 0xa00, `lw` at 0xa14.
  3 such `lw` accesses load 4 bytes from ([a1+76] + one of 0x2c, 0x3c) +0x0, including `lw` at 0x81c, `lw` at 0x868, `lw` at 0xb10.
  3 such `lw` accesses load 4 bytes from ([a1+76] + one of 0x28, 0x38) +0x0, including `lw` at 0x820, `lw` at 0x86c, `lw` at 0xb14.
  3 such `lw` accesses load 4 bytes from ([a1+76] + one of 0x24, 0x34) +0x0, including `lw` at 0x828, `lw` at 0x874, `lw` at 0xb18.
  4 such `sw` accesses store 4 bytes to ([a1+76] + one of 0x24, 0x34) +0x0, including `sw` at 0x82c, `sw` at 0x87c, `sw` at 0x9bc.
  4 such `sw` accesses store 4 bytes to ([a1+76] + one of 0x30, 0x40) +0x0, including `sw` at 0x830, `sw` at 0x878, `sw` at 0x9b4.
  4 such `lw` accesses load 4 bytes from a3 (arg3 at entry) +0x4, including `lw` at 0x834, `lw` at 0x958, `lw` at 0x9c4.
  6 such `lw` accesses load 4 bytes from a3 (arg3 at entry) +0x0, including `lw` at 0x840, `lw` at 0x95c, `lw` at 0x9b8.
  The `lw` at 0x890 loads 4 bytes from a2 (arg2 at entry) +0x4.
  2 such `sd` accesses store 8 bytes to ?, including `sd` at 0x8d4, `sd` at 0x8f0.
  2 such `sw` accesses store 4 bytes to [a2+120] +0x4008, including `sw` at 0x8f4, `sw` at 0xb38.
  The `lw` at 0x8f8 loads 4 bytes from [a1+76] +0x24.
  The `lw` at 0x904 loads 4 bytes from [a1+76] +0x34.
  2 such `sw` accesses store 4 bytes to a2 (arg2 at entry) +0xb4, including `sw` at 0x910, `sw` at 0xacc.
  2 such `sw` accesses store 4 bytes to ([a1+76] + one of 0x2c, 0x3c) +0x0, including `sw` at 0x954, `sw` at 0x990.
  The `sw` at 0x9cc stores 4 bytes to ([a1+76] + one of 0x28, 0x38) +0x0.
  The `lw` at 0xa64 loads 4 bytes from ?.
  The `sw` at 0xa78 stores 4 bytes to ?.
  The `sw` at 0xb00 stores 4 bytes to ([a2+120]+8688 | 0x800) +0x0.
  The `jal` at 0x824 calls undma with a0=[([a1+76] + one of 0x24, 0x34)], a1=?, a2=?, a3=a3 at entry (arg3).
  The `jal` at 0x870 calls undma with a0=[([a1+76] + one of 0x24, 0x34)], a1=?, a2=?, a3=?.
  The `jal` at 0x884 calls bzero with a0=([a1+76] + one of 0x50, 0xd0), a1=0x80, a2=?, a3=?.
  The `jal` at 0x8ac calls RRM_CheckValidFault with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x960 calls fast_userdma with a0=[a3], a1=[a3+4], a2=one of 0x0, 0x1, a3=0x0.
  The `jal` at 0x9c8 calls kern_malloc with a0=?, a1=?, a2=?, a3=?, a5=[a3+4], a6=[a3].
  The `jal` at 0x9dc calls crm_curproc_vtop with a0=[a3], a1=[a3+4], a2=ret(kern_malloc), a3=?.
  The `jal` at 0xa04 calls kern_free with a0=ret(kern_malloc), a1=?, a2=?, a3=?.
  The `jal` at 0xa20 calls bzero with a0=([a1+76] + one of 0x50, 0xd0), a1=0x80, a2=?, a3=?.
  The `jal` at 0xa7c calls RRM_CheckValidFault with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xaa4 calls loadLinearTlb with a0=[a2+120], a1=[a3], a2=ret(kern_malloc), a3=?.
  The `jal` at 0xad0 calls kern_free with a0=ret(kern_malloc), a1=?, a2=?, a3=?.
  The `jal` at 0xafc calls crmIdleWait with a0=[a2+120], a1=0x7a120, a2=?, a3=?, a7=([a2+120]+8688 | 0x800).
  The `jal` at 0xb1c calls fast_undma with a0=?, a1=?, a2=?, a3=0x0.
  The `beq` branch at 0x800 targets 0x978, is taken when (at(=[a3+8]) & 0x4) == 0, and falls through when (at(=[a3+8]) & 0x4) != 0.
  The `beq` branch at 0x814 targets 0x830, is taken when v1(?) == 0, and falls through when v1(?) != 0.
  The `beq` branch at 0x838 targets 0x984, is taken when a2(=[a3+4]) == 0, and falls through when a2(=[a3+4]) != 0.
  The `bne` branch at 0x858 targets 0x944, is taken when s7(?) < 0x21 (signed), and falls through when s7(?) >= 0x21 (signed).
  The `beq` branch at 0x860 targets 0x884, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `bne` branch at 0x894 targets 0x918, is taken when t8(=[a2+4]) != t9(=a1), and falls through when t8(=[a2+4]) == t9(=a1).
  The `beq` branch at 0x8a4 targets 0x99c, is taken when (ra(=[a3+8]) & 0x4) == 0, and falls through when (ra(=[a3+8]) & 0x4) != 0.
  The `bltz` branch at 0x8b4 targets 0xa18, is taken when v0(=ret(RRM_CheckValidFault)) < 0 (signed), and falls through when v0(=ret(RRM_CheckValidFault)) >= 0 (signed).
  The `beq` branch at 0x8d8 targets 0x8f4, is taken when a3(?) >= 0x10 (signed), and falls through when a3(?) < 0x10 (signed).
  The `bne` branch at 0x8ec targets 0x8c4, is taken when a3(?) < 0x10 (signed), and falls through when a3(?) >= 0x10 (signed).
  The `bne` branch at 0x8fc targets 0x910, is taken when a1(=[[a1+76]+36]) != 0, and falls through when a1(=[[a1+76]+36]) == 0.
  The `beq` branch at 0x908 targets 0x9a4, is taken when a2(=[[a1+76]+52]) == 0, and falls through when a2(=[[a1+76]+52]) != 0.
  The `beq` branch at 0x94c targets 0x98c, is taken when (a3(=[a3+8]) & 0x8) == 0, and falls through when (a3(=[a3+8]) & 0x8) != 0.
  The `beq` branch at 0x968 targets 0x9ac, is taken when v0(=ret(fast_userdma)) == 0, and falls through when v0(=ret(fast_userdma)) != 0.
  The `beq` branch at 0x970 targets 0x91c and is always taken.
  The `beq` branch at 0x97c targets 0x810 and is always taken.
  The `beq` branch at 0x984 targets 0x860 and is always taken.
  The `beq` branch at 0x994 targets 0x958 and is always taken.
  The `beq` branch at 0x99c targets 0x8ac and is always taken.
  The `beq` branch at 0x9a4 targets 0x910 and is always taken.
  The `beq` branch at 0x9e4 targets 0xa20, is taken when v0(=ret(crm_curproc_vtop)) == 0, and falls through when v0(=ret(crm_curproc_vtop)) != 0.
  The `bne` branch at 0x9f0 targets 0xa04, is taken when s8(=ret(kern_malloc)) != 0, and falls through when s8(=ret(kern_malloc)) == 0.
  The `beq` branch at 0x9fc targets 0x860 and is always taken.
  The `beq` branch at 0xa10 targets 0x860 and is always taken.
  The `beq` branch at 0xa18 targets 0x918 and is always taken.
  The `blez` branch at 0xa2c targets 0xa7c, is taken when s7(?) <= 0 (signed), and falls through when s7(?) > 0 (signed).
  The `bne` branch at 0xa74 targets 0xa40, is taken when a2(?) < s7(?) (signed), and falls through when a2(?) >= s7(?) (signed).
  The `bgez` branch at 0xa84 targets 0xa94, is taken when v0(=ret(RRM_CheckValidFault)) >= 0 (signed), and falls through when v0(=ret(RRM_CheckValidFault)) < 0 (signed).
  The `beq` branch at 0xa8c targets 0x9f0 and is always taken.
  The `beq` branch at 0xaac targets 0xabc, is taken when v0(=ret(loadLinearTlb)) == 0, and falls through when v0(=ret(loadLinearTlb)) != 0.
  The `beq` branch at 0xab4 targets 0x9f0 and is always taken.
  The `beq` branch at 0xac4 targets 0xb34, is taken when (a5(=[a3+8]) & 0x40) == 0, and falls through when (a5(=[a3+8]) & 0x40) != 0.
  The `beq` branch at 0xae0 targets 0xb2c, is taken when (a6(=[a3+8]) & 0x40) == 0, and falls through when (a6(=[a3+8]) & 0x40) != 0.
  The `beq` branch at 0xb08 targets 0xb2c, is taken when t0(?) == 0, and falls through when t0(?) != 0.
  The `beq` branch at 0xb2c targets 0x918 and is always taken.
  The `beq` branch at 0xb34 targets 0xacc and is always taken.
  The return at 0x93c has v0 = one of 0x0, 0x4, 0xe, 0x16, ret(fast_userdma).

- `crime_clear_buffer` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_dma.o)` at 0xb3c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_dma.o)`.
  Range: 0xb3c-0xf40 (1028 bytes).
  It occupies 1028 bytes.
  The `lw` at 0xb40 loads 4 bytes from a1 (arg1 at entry) +0x4c.
  The `lw` at 0xb64 loads 4 bytes from a1 (arg1 at entry) +0x8.
  The `lw` at 0xb80 loads 4 bytes from [a1+76] +0xc.
  The `lh` at 0xb84 loads 2 bytes from [[a1+76]+12] +0x10.
  The `lh` at 0xb90 loads 2 bytes from [[a1+76]+12] +0x12.
  The `lw` at 0xb9c loads 4 bytes from [a1+8] +0x10.
  2 such `lbu` accesses load 1 byte from a3 (arg3 at entry) +0x8, including `lbu` at 0xbd8, `lbu` at 0xdd0.
  2 such `lbu` accesses load 1 byte from a3 (arg3 at entry) +0xa, including `lbu` at 0xc14, `lbu` at 0xd0c.
  The `lbu` at 0xc1c loads 1 byte from a3 (arg3 at entry) +0x9.
  4 such `lw` accesses load 4 bytes from [a1+8] +0x58, including `lw` at 0xc40, `lw` at 0xc48, `lw` at 0xc50.
  4 such `ld` accesses load 8 bytes from [a1+8] +0x48, including `ld` at 0xc44, `ld` at 0xc4c, `ld` at 0xc54.
  4 such `ld` accesses load 8 bytes from ?, including `ld` at 0xcf0, `ld` at 0xcf4, `ld` at 0xcf8.
  The `sw` at 0xe00 stores 4 bytes to [a1+8] +0x230.
  The `sw` at 0xe08 stores 4 bytes to a2 (arg2 at entry) +0x3030.
  The `sw` at 0xe14 stores 4 bytes to [a1+8] +0x238.
  The `sw` at 0xe20 stores 4 bytes to (a2+12344 | 0x800) +0x0.
  2 such `lw` accesses load 4 bytes from a3 (arg3 at entry) +0x0, including `lw` at 0xe78, `lw` at 0xe80.
  The `sw` at 0xe7c stores 4 bytes to [a1+8] +0x218.
  The `sw` at 0xe84 stores 4 bytes to a2 (arg2 at entry) +0x3018.
  2 such `lw` accesses load 4 bytes from a3 (arg3 at entry) +0x4, including `lw` at 0xe88, `lw` at 0xe90.
  The `sw` at 0xe8c stores 4 bytes to [a1+8] +0x208.
  The `sw` at 0xe94 stores 4 bytes to a2 (arg2 at entry) +0x3008.
  The `sw` at 0xe9c stores 4 bytes to [a1+8] +0x248.
  The `sw` at 0xea0 stores 4 bytes to a2 (arg2 at entry) +0x3048.
  The `sw` at 0xea4 stores 4 bytes to [a1+8] +0x200.
  The `sw` at 0xeac stores 4 bytes to a2 (arg2 at entry) +0x3000.
  The `sw` at 0xec4 stores 4 bytes to a2 (arg2 at entry) +0x3078.
  The `jal` at 0xb60 calls RRM_CheckValidFault with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xec8 calls crmIdleWait with a0=a2 at entry (arg2), a1=0x7a120, a2=(a2+12344 | 0x800), a3=?.
  The `bltz` branch at 0xb74 targets 0xee0, is taken when v0(=ret(RRM_CheckValidFault)) < 0 (signed), and falls through when v0(=ret(RRM_CheckValidFault)) >= 0 (signed).
  The `beq` branch at 0xb88 targets 0xccc, is taken when v1(=[[[a1+76]+12]+16]:2) == 0, and falls through when v1(=[[[a1+76]+12]+16]:2) != 0.
  The `beq` branch at 0xb94 targets 0xccc, is taken when v1(=[[[a1+76]+12]+18]:2) == 0, and falls through when v1(=[[[a1+76]+12]+18]:2) != 0.
  The `beq` branch at 0xba4 targets 0xbd4, is taken when (ra(=[[a1+8]+16]) & 0x800) == 0, and falls through when (ra(=[[a1+8]+16]) & 0x800) != 0.
  The `beq` branch at 0xbec targets 0xc10, is taken when a1(=0x1) == a0(=[a3+8]:1), and falls through when a1(=0x1) != a0(=[a3+8]:1).
  The `beq` branch at 0xbf8 targets 0xc10, is taken when a0(=[a3+8]:1) == a3(=0x2), and falls through when a0(=[a3+8]:1) != a3(=0x2).
  The `beq` branch at 0xc00 targets 0xc10, is taken when a0(=[a3+8]:1) == a4(=0x4), and falls through when a0(=[a3+8]:1) != a4(=0x4).
  The `beq` branch at 0xc08 targets 0xbb0 and is always taken.
  The `beq` branch at 0xc38 targets 0xf08, is taken when (a6(=[a3+10]:1) & 0x1) == 0, and falls through when (a6(=[a3+10]:1) & 0x1) != 0.
  The `beq` branch at 0xc9c targets 0xee8, is taken when a3(?) >= s4(?) (signed), and falls through when a3(?) < s4(?) (signed).
  The `beq` branch at 0xcac targets 0xef8, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0xcc4 targets 0xf2c and is always taken.
  The `beq` branch at 0xccc targets 0xbac and is always taken.
  The `beq` branch at 0xce0 targets 0xeb0, is taken when t3(?) == 0, and falls through when t3(?) != 0.
  The `bne` branch at 0xce8 targets 0xcd4, is taken when a5(?) != a7(?), and falls through when a5(?) == a7(?).
  The `beq` branch at 0xd28 targets 0xdc4, is taken when (at(=[a3+10]:1) & 0x1) == 0, and falls through when (at(=[a3+10]:1) & 0x1) != 0.
  The `beq` branch at 0xd30 targets 0xcd4, is taken when a7(?) == 0, and falls through when a7(?) != 0.
  The `beq` branch at 0xd3c targets 0xe3c, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0xd50 targets 0xd5c, is taken when s5(?) == 0, and falls through when s5(?) != 0.
  The `beq` branch at 0xd5c targets 0xd6c, is taken when s8(?) == 0, and falls through when s8(?) != 0.
  The `beq` branch at 0xd74 targets 0xe54, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0xd80 targets 0xda4, is taken when s5(?) == 0, and falls through when s5(?) != 0.
  The `beq` branch at 0xd88 targets 0xd98, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0xd98 targets 0xda4, is taken when at(?) == 0, and falls through when at(?) != 0.
  The `beq` branch at 0xda4 targets 0xcd4, is taken when a7(?) == 0, and falls through when a7(?) != 0.
  The `bne` branch at 0xdac targets 0xcd4, is taken when v1(?) != 0, and falls through when v1(?) == 0.
  The `bne` branch at 0xdb4 targets 0xcd4, is taken when s8(?) != 0, and falls through when s8(?) == 0.
  The `bne` branch at 0xdbc targets 0xcd4, is taken when a0(?) != 0, and falls through when a0(?) == 0.
  The `beq` branch at 0xdc4 targets 0xe74, is taken when s7(=one of 0x0, 0x1) == 0, and falls through when s7(=one of 0x0, 0x1) != 0.
  The `bne` branch at 0xdf0 targets 0xcd4, is taken when v0(?) < a5(?) (unsigned), and falls through when v0(?) >= a5(?) (unsigned).
  The `beq` branch at 0xdf8 targets 0xf20 and is always taken.
  The `bne` branch at 0xe24 targets 0xcd4, is taken when v0(?) < a5(=table(0x10000)) (unsigned), and falls through when v0(?) >= a5(=table(0x10000)) (unsigned).
  The `bne` branch at 0xe2c targets 0xe00, is taken when a1(?) != 0, and falls through when a1(?) == 0.
  The `beq` branch at 0xe34 targets 0xe00 and is always taken.
  The `beq` branch at 0xe3c targets 0xcd4, is taken when a7(?) == 0, and falls through when a7(?) != 0.
  The `beq` branch at 0xe44 targets 0xcd4, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0xe4c targets 0xdc4 and is always taken.
  The `beq` branch at 0xe54 targets 0xcd4, is taken when a7(?) == 0, and falls through when a7(?) != 0.
  The `bne` branch at 0xe5c targets 0xcd4, is taken when a4(?) != 0, and falls through when a4(?) == 0.
  The `beq` branch at 0xe64 targets 0xcd4, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0xe6c targets 0xdc4 and is always taken.
  The `beq` branch at 0xea8 targets 0xdcc and is always taken.
  The `beq` branch at 0xeb0 targets 0xed0, is taken when s7(=one of 0x0, 0x1) == 0, and falls through when s7(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0xed8 targets 0xbac and is always taken.
  The `beq` branch at 0xee0 targets 0xbac and is always taken.
  The `bne` branch at 0xee8 targets 0xcac, is taken when s4(?) != a3(?), and falls through when s4(?) == a3(?).
  The `beq` branch at 0xef0 targets 0xbac and is always taken.
  The `bne` branch at 0xef8 targets 0xcbc, is taken when s6(?) != a4(?), and falls through when s6(?) == a4(?).
  The `beq` branch at 0xf00 targets 0xbac and is always taken.
  The `beq` branch at 0xf18 targets 0xcb8 and is always taken.
  The `beq` branch at 0xf24 targets 0xe2c and is always taken.
  The `beq` branch at 0xf38 targets 0xce8 and is always taken.
  The return at 0xbcc has v0 = one of -0x1, 0x0, 0x4, 0x16.
