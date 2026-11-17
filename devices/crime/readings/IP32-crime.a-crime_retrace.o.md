# Readings: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_retrace.o)`

One entry per routine, filed here from the reading batches by binary.

- `crimeRetraceInit` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_retrace.o)` at 0x0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_retrace.o)`.
  Range: 0x0-0x6c (108 bytes).
  It occupies 108 bytes.
  The `sw` at 0x2c stores 4 bytes to a0 (arg0 at entry) +0x8c.
  The `sb` at 0x40 stores 1 byte to ret(kern_malloc) +0x1c.
  The `sw` at 0x4c stores 4 bytes to ret(kern_malloc) +0x20.
  The `sw` at 0x58 stores 4 bytes to ret(kern_malloc) +0x328.
  The `jal` at 0x10 calls kern_malloc with a0=0x350, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x20 calls bzero with a0=ret(kern_malloc), a1=0x350, a2=?, a3=?.
  The `jal` at 0x54 calls init_mutex with a0=ret(kern_malloc)+840, a1=0x0, a2=0x0, a3=-0x1.
  The return at 0x64 has v0 = ret(init_mutex).

- `gbeCacheVtInfo` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_retrace.o)` at 0x6c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_retrace.o)`.
  Range: 0x6c-0x224 (440 bytes).
  It occupies 440 bytes.
  The `lw` at 0x88 loads 4 bytes from a0 (arg0 at entry) +0x8c.
  The `lw` at 0x90 loads 4 bytes from a0 (arg0 at entry) +0x80.
  The `lw` at 0x94 loads 4 bytes from a0 (arg0 at entry) +0x84.
  The `lw` at 0x98 loads 4 bytes from [a0+132] +0x8.
  The `lw` at 0x9c loads 4 bytes from [a0+132] +0x4.
  The `lw` at 0xa0 loads 4 bytes from [a0+132] +0x0.
  The `lw` at 0xa4 loads 4 bytes from [a0+132] +0x4c.
  The `lw` at 0xa8 loads 4 bytes from [a0+132] +0x50.
  The `lw` at 0xac loads 4 bytes from [a0+132] +0x58.
  The `lw` at 0xb0 loads 4 bytes from [a0+132] +0x54.
  The `sw` at 0xb8 stores 4 bytes to [a0+132] +0x58.
  The `sw` at 0xc0 stores 4 bytes to [a0+132] +0x54.
  The `sw` at 0xc8 stores 4 bytes to [a0+132] +0x50.
  The `sw` at 0xd0 stores 4 bytes to [a0+132] +0x4c.
  The `sw` at 0xd8 stores 4 bytes to [a0+132] +0x0.
  The `sw` at 0xe0 stores 4 bytes to [a0+132] +0x4.
  The `sw` at 0xec stores 4 bytes to [a0+132] +0x8.
  2 such `sh` accesses store 2 bytes to [a0+140] +0x8, including `sh` at 0x100, `sh` at 0x164.
  3 such `sh` accesses store 2 bytes to [a0+140] +0xa, including `sh` at 0x104, `sh` at 0x170, `sh` at 0x194.
  2 such `sw` accesses store 4 bytes to [a0+128] +0x10020, including `sw` at 0x120, `sw` at 0x1a4.
  The `sw` at 0x130 stores 4 bytes to [a0+140] +0x328.
  The `sw` at 0x138 stores 4 bytes to [a0+128] +0x10024.
  The `lh` at 0x158 loads 2 bytes from a1 (arg1 at entry) +0x20.
  The `sh` at 0x15c stores 2 bytes to [a0+140] +0xc.
  The `lh` at 0x174 loads 2 bytes from a1 (arg1 at entry) +0x1e.
  The `lhu` at 0x198 loads 2 bytes from [a0+140] +0x8.
  3 such `sw` accesses store 4 bytes to [a0+140] +0x20, including `sw` at 0x1a8, `sw` at 0x1bc, `sw` at 0x1d0.
  2 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x4, including `lw` at 0x1ac, `lw` at 0x1c0.
  The `lw` at 0x1d4 loads 4 bytes from a0 (arg0 at entry) +0x7c.
  The `lhu` at 0x1d8 loads 2 bytes from [a0+124] +0x22.
  The `sw` at 0x1e4 stores 4 bytes to [a0+140] +0x10.
  The `lhu` at 0x1e8 loads 2 bytes from a1 (arg1 at entry) +0xa.
  The `sb` at 0x1ec stores 1 byte to [a0+140] +0x18.
  The `sh` at 0x1f0 stores 2 bytes to [a0+140] +0xe.
  The `sh` at 0x1fc stores 2 bytes to [a0+140] +0x14.
  The `jal` at 0x11c calls flushbus with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x134 calls flushbus with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x148 calls mutex_unlock with a0=[a0+140]+840, a1=?, a2=?, a3=?.
  The `jal` at 0x214 calls mutex_lock with a0=[a0+140]+840, a1=0x19, a2=?, a3=?, a7=[sym(power_dump_crash)].
  The `beq` branch at 0x80 targets 0x200, is taken when a0 == 0, and falls through when a0 != 0.
  The `bne` branch at 0x8c targets 0x158, is taken when a1 != 0, and falls through when a1 == 0.
  The `beq` branch at 0xe8 targets 0x200, is taken when s0(=[a0+140]) == 0, and falls through when s0(=[a0+140]) != 0.
  The `beq` branch at 0xf4 targets 0x210, is taken when a7(=[sym(power_dump_crash)]) == 0, and falls through when a7(=[sym(power_dump_crash)]) != 0.
  The `bne` branch at 0x140 targets 0x200, is taken when t3(=[sym(power_dump_crash)]) != 0, and falls through when t3(=[sym(power_dump_crash)]) == 0.
  The `beq` branch at 0x150 targets 0x200 and is always taken.
  The `bne` branch at 0x188 targets 0x198, is taken when a4(?) < a3(=[a1+30]:2) (signed), and falls through when a4(?) >= a3(=[a1+30]:2) (signed).
  The `beq` branch at 0x1b4 targets 0x1c8, is taken when (a3(=[a1+4]) & 0x10) == 0, and falls through when (a3(=[a1+4]) & 0x10) != 0.
  The `beq` branch at 0x1c8 targets 0x1d4, is taken when t8(?) == 0, and falls through when t8(?) != 0.
  The `beq` branch at 0x21c targets 0x100 and is always taken.
  The return at 0x208 has v0 = one of ?, [a0+132], ret(flushbus), ret(mutex_unlock).

- `crmInitGbeData` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_retrace.o)` at 0x224 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_retrace.o)`.
  Range: 0x224-0x59c (888 bytes).
  It occupies 888 bytes.
  The `lw` at 0x22c loads 4 bytes from a0 (arg0 at entry) +0x84.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x8c, including `lw` at 0x24c, `lw` at 0x25c.
  2 such `lbu` accesses load 1 byte from sym(crmFrameBuffer) +0x18, including `lbu` at 0x254, `lbu` at 0x26c.
  The `sb` at 0x258 stores 1 byte to [a0+140] +0x1a.
  2 such `lbu` accesses load 1 byte from sym(crmFrameBuffer) +0x19, including `lbu` at 0x260, `lbu` at 0x270.
  The `sb` at 0x264 stores 1 byte to [a0+140] +0x1b.
  2 such `lw` accesses load 4 bytes from sym(crmFrameBuffer) +0x4, including `lw` at 0x278, `lw` at 0x53c.
  5 such `lw` accesses load 4 bytes from sym(crmFrameBuffer) +0x8, including `lw` at 0x2a4, `lw` at 0x2c8, `lw` at 0x2fc.
  11 such `lhu` accesses load 2 bytes from ?, including `lhu` at 0x2b4, `lhu` at 0x2d8, `lhu` at 0x30c.
  12 such `sh` accesses store 2 bytes to ?, including `sh` at 0x2c0, `sh` at 0x2ec, `sh` at 0x318.
  2 such `lw` accesses load 4 bytes from sym(crmOverlayBuffer) +0x4, including `lw` at 0x35c, `lw` at 0x57c.
  5 such `lw` accesses load 4 bytes from sym(crmOverlayBuffer) +0x8, including `lw` at 0x380, `lw` at 0x3a4, `lw` at 0x3dc.
  3 such `lw` accesses load 4 bytes from sym(crmGbeTables) +0x8, including `lw` at 0x43c, `lw` at 0x474, `lw` at 0x490.
  3 such `sw` accesses store 4 bytes to ?, including `sw` at 0x454, `sw` at 0x458, `sw` at 0x468.
  2 such `lhu` accesses load 2 bytes from [sym(crmGbeTables)+8] +0x6, including `lhu` at 0x480, `lhu` at 0x49c.
  The `sw` at 0x4c0 stores 4 bytes to [a0+132] +0x8.
  The `sw` at 0x4cc stores 4 bytes to [a0+132] +0x4.
  The `sw` at 0x4d8 stores 4 bytes to [a0+132] +0x0.
  The `sw` at 0x4e4 stores 4 bytes to [a0+132] +0x4c.
  The `sw` at 0x4f0 stores 4 bytes to [a0+132] +0x50.
  The `sw` at 0x4fc stores 4 bytes to [a0+132] +0x54.
  The `sw` at 0x504 stores 4 bytes to [a0+132] +0x58.
  The `jal` at 0x240 calls bzero with a0=[a0+132], a1=0x600, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x4b0 calls kvtophys with a0=[a0+132]+160, a1=sym(crmGbeTables), a2=?, a3=?.
  The `jal` at 0x4bc calls kvtophys with a0=[a0+132]+288, a1=?, a2=?, a3=?.
  The `jal` at 0x4c8 calls kvtophys with a0=[a0+132]+352, a1=?, a2=?, a3=?.
  The `jal` at 0x4d4 calls kvtophys with a0=[a0+132]+512, a1=?, a2=?, a3=?.
  The `jal` at 0x4e0 calls kvtophys with a0=[a0+132]+768, a1=?, a2=?, a3=?.
  The `jal` at 0x4ec calls kvtophys with a0=[a0+132]+1024, a1=?, a2=?, a3=?.
  The `jal` at 0x4f8 calls kvtophys with a0=[a0+132]+1280, a1=?, a2=?, a3=?.
  The `beq` branch at 0x274 targets 0x518, is taken when a3(=[sym(crm_dual_channel)]) == 0, and falls through when a3(=[sym(crm_dual_channel)]) != 0.
  The `bne` branch at 0x29c targets 0x348, is taken when a4(?) < 0x1 (signed), and falls through when a4(?) >= 0x1 (signed).
  The `beq` branch at 0x2c4 targets 0x2f0, is taken when a2(?) >= a4(?) (signed), and falls through when a2(?) < a4(?) (signed).
  The `bne` branch at 0x2e8 targets 0x2a4, is taken when a2(?) < a4(?) (signed), and falls through when a2(?) >= a4(?) (signed).
  The `beq` branch at 0x2f0 targets 0x348, is taken when a7(?) == 0, and falls through when a7(?) != 0.
  The `beq` branch at 0x31c targets 0x348, is taken when a2(?) >= a4(?) (signed), and falls through when a2(?) < a4(?) (signed).
  The `bne` branch at 0x340 targets 0x2fc, is taken when a2(?) < a4(?) (signed), and falls through when a2(?) >= a4(?) (signed).
  The `beq` branch at 0x358 targets 0x55c, is taken when a3(=[sym(crm_dual_channel)]) == 0, and falls through when a3(=[sym(crm_dual_channel)]) != 0.
  The `bne` branch at 0x378 targets 0x428, is taken when a4(?) < 0x1 (signed), and falls through when a4(?) >= 0x1 (signed).
  The `beq` branch at 0x3a0 targets 0x3cc, is taken when a2(?) >= a4(?) (signed), and falls through when a2(?) < a4(?) (signed).
  The `bne` branch at 0x3c4 targets 0x380, is taken when a2(?) < a4(?) (signed), and falls through when a2(?) >= a4(?) (signed).
  The `beq` branch at 0x3cc targets 0x42c, is taken when a7(?) == 0, and falls through when a7(?) != 0.
  The `beq` branch at 0x3fc targets 0x428, is taken when a2(?) >= a4(?) (signed), and falls through when a2(?) < a4(?) (signed).
  The `bne` branch at 0x420 targets 0x3dc, is taken when a2(?) < a4(?) (signed), and falls through when a2(?) >= a4(?) (signed).
  The `bne` branch at 0x464 targets 0x43c, is taken when a2(?) < 0x4 (signed), and falls through when a2(?) >= 0x4 (signed).
  The `beq` branch at 0x48c targets 0x4b0, is taken when a2(?) >= 0x40 (unsigned), and falls through when a2(?) < 0x40 (unsigned).
  The `bne` branch at 0x4a8 targets 0x474, is taken when a2(?) < 0x40 (unsigned), and falls through when a2(?) >= 0x40 (unsigned).
  The `blez` branch at 0x518 targets 0x34c, is taken when a4(=[sym(crmFrameBuffer)+4]) <= 0 (signed), and falls through when a4(=[sym(crmFrameBuffer)+4]) > 0 (signed).
  The `bne` branch at 0x54c targets 0x528, is taken when a2(?) < t1(=[sym(crmFrameBuffer)+4]) (signed), and falls through when a2(?) >= t1(=[sym(crmFrameBuffer)+4]) (signed).
  The `beq` branch at 0x554 targets 0x34c and is always taken.
  The `blez` branch at 0x55c targets 0x428, is taken when a6(=[sym(crmOverlayBuffer)+4]) <= 0 (signed), and falls through when a6(=[sym(crmOverlayBuffer)+4]) > 0 (signed).
  The `bne` branch at 0x58c targets 0x568, is taken when a2(?) < t3(=[sym(crmOverlayBuffer)+4]) (signed), and falls through when a2(?) >= t3(=[sym(crmOverlayBuffer)+4]) (signed).
  The `beq` branch at 0x594 targets 0x42c and is always taken.
  The return at 0x510 has v0 = ret(kvtophys).

- `crmLoadGbelists` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_retrace.o)` at 0x59c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_retrace.o)`.
  Range: 0x59c-0xae8 (1356 bytes).
  It occupies 1356 bytes.
  2 such `lh` accesses load 2 bytes from a1 (arg1 at entry) +0xa, including `lh` at 0x5a0, `lh` at 0x778.
  The `lh` at 0x5a8 loads 2 bytes from a1 (arg1 at entry) +0x8.
  The `lw` at 0x5c0 loads 4 bytes from sym(crmFrameBuffer) +0x4.
  The `lw` at 0x5c8 loads 4 bytes from a0 (arg0 at entry) +0x84.
  The `lbu` at 0x5dc loads 1 byte from sym(crmFrameBuffer) +0x14.
  4 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x4, including `lw` at 0x5fc, `lw` at 0x6bc, `lw` at 0x7a4.
  4 such `lbu` accesses load 1 byte from sym(crmFrameBuffer) +0x18, including `lbu` at 0x644, `lbu` at 0x6b8, `lbu` at 0x6f0.
  6 such `lw` accesses load 4 bytes from sym(crmFrameBuffer) +0x8, including `lw` at 0x664, `lw` at 0x68c, `lw` at 0x70c.
  9 such `lhu` accesses load 2 bytes from ?, including `lhu` at 0x678, `lhu` at 0x6a0, `lhu` at 0x720.
  9 such `sh` accesses store 2 bytes to ?, including `sh` at 0x684, `sh` at 0x6b0, `sh` at 0x72c.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x8c, including `lw` at 0x768, `lw` at 0x770.
  The `sb` at 0x76c stores 1 byte to [a0+140] +0x1a.
  The `sb` at 0x774 stores 1 byte to [a0+140] +0x1b.
  The `lbu` at 0x798 loads 1 byte from sym(crmOverlayBuffer) +0x14.
  4 such `lbu` accesses load 1 byte from sym(crmOverlayBuffer) +0x18, including `lbu` at 0x80c, `lbu` at 0x85c, `lbu` at 0x8b4.
  3 such `lw` accesses load 4 bytes from sym(crmOverlayBuffer) +0x8, including `lw` at 0x82c, `lw` at 0x8d0, `lw` at 0x9e0.
  The `lw` at 0x914 loads 4 bytes from [a0+132] +0x8.
  The `lw` at 0x918 loads 4 bytes from [a0+132] +0x4.
  The `lw` at 0x91c loads 4 bytes from [a0+132] +0x0.
  The `lw` at 0x920 loads 4 bytes from [a0+132] +0x4c.
  The `lw` at 0x924 loads 4 bytes from [a0+132] +0x50.
  The `lw` at 0x928 loads 4 bytes from [a0+132] +0x58.
  The `lw` at 0x92c loads 4 bytes from [a0+132] +0x54.
  The `sw` at 0x934 stores 4 bytes to [a0+132] +0x58.
  The `sw` at 0x93c stores 4 bytes to [a0+132] +0x54.
  The `sw` at 0x944 stores 4 bytes to [a0+132] +0x50.
  The `sw` at 0x94c stores 4 bytes to [a0+132] +0x4c.
  The `sw` at 0x954 stores 4 bytes to [a0+132] +0x0.
  The `sw` at 0x960 stores 4 bytes to [a0+132] +0x4.
  The `sw` at 0x968 stores 4 bytes to [a0+132] +0x8.
  The `jal` at 0x90c calls bcopy with a0=[a0+132]+288, a1=[sym(gbe_tp_overlay_tiles)], a2=?, a3=0x200, a4=sym(crmOverlayBuffer).
  The `beq` branch at 0x5e0 targets 0x790, is taken when at(=[sym(crmFrameBuffer)+4]) == 0, and falls through when at(=[sym(crmFrameBuffer)+4]) != 0.
  The `beq` branch at 0x610 targets 0x61c, is taken when (a2(=[a1+4]) & 0x2) == 0, and falls through when (a2(=[a1+4]) & 0x2) != 0.
  The `bne` branch at 0x634 targets 0x6c4, is taken when t3(?) < 0x1 (signed), and falls through when t3(?) >= 0x1 (signed).
  The `bltz` branch at 0x658 targets 0x6b4, is taken when a7(?) < 0 (signed), and falls through when a7(?) >= 0 (signed).
  The `bne` branch at 0x688 targets 0x6b4, is taken when a7(?) < a2(?) (signed), and falls through when a7(?) >= a2(?) (signed).
  The `beq` branch at 0x6ac targets 0x664, is taken when a7(?) >= a2(?) (signed), and falls through when a7(?) < a2(?) (signed).
  The `bne` branch at 0x6b4 targets 0x648, is taken when t1(?) != 0, and falls through when t1(?) == 0.
  The `beq` branch at 0x6c8 targets 0xa20, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `blez` branch at 0x6e4 targets 0x768, is taken when t3(?) <= 0 (signed), and falls through when t3(?) > 0 (signed).
  The `beq` branch at 0x700 targets 0x75c, is taken when t9(?) == 0, and falls through when t9(?) != 0.
  The `bne` branch at 0x730 targets 0x75c, is taken when a7(?) < a4(?) (signed), and falls through when a7(?) >= a4(?) (signed).
  The `beq` branch at 0x754 targets 0x70c, is taken when a7(?) >= a4(?) (signed), and falls through when a7(?) < a4(?) (signed).
  The `bne` branch at 0x760 targets 0x6f0, is taken when t2(?) != 0, and falls through when t2(?) == 0.
  The `beq` branch at 0x7b8 targets 0x7c4, is taken when (a2(=[a1+4]) & 0x2) == 0, and falls through when (a2(=[a1+4]) & 0x2) != 0.
  The `bne` branch at 0x7e4 targets 0x868, is taken when t2(?) < 0x1 (signed), and falls through when t2(?) >= 0x1 (signed).
  The `bltz` branch at 0x820 targets 0x858, is taken when a5(?) < 0 (signed), and falls through when a5(?) >= 0 (signed).
  The `beq` branch at 0x850 targets 0x82c, is taken when a5(?) >= a2(?) (signed), and falls through when a5(?) < a2(?) (signed).
  The `bne` branch at 0x858 targets 0x810, is taken when t1(?) != 0, and falls through when t1(?) == 0.
  The `beq` branch at 0x868 targets 0x978, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `blez` branch at 0x888 targets 0xad0, is taken when a7(?) <= 0 (signed), and falls through when a7(?) > 0 (signed).
  The `beq` branch at 0x8c4 targets 0x8fc, is taken when t3(?) == 0, and falls through when t3(?) != 0.
  The `beq` branch at 0x8f4 targets 0x8d0, is taken when a5(?) >= a6(?) (signed), and falls through when a5(?) < a6(?) (signed).
  The `beq` branch at 0x900 targets 0x8b4, is taken when t1(?) == 0, and falls through when t1(?) != 0.
  The `beq` branch at 0x990 targets 0xad8, is taken when a1(=[sym(crm_dual_channel)]) == 0, and falls through when a1(=[sym(crm_dual_channel)]) != 0.
  The `beq` branch at 0x99c targets 0xae0, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0x9d4 targets 0xa0c, is taken when t3(?) == 0, and falls through when t3(?) != 0.
  The `beq` branch at 0xa04 targets 0x9e0, is taken when a5(?) >= a1(?) (signed), and falls through when a5(?) < a1(?) (signed).
  The `bne` branch at 0xa10 targets 0x9c4, is taken when t1(?) != 0, and falls through when t1(?) == 0.
  The `beq` branch at 0xa18 targets 0x90c and is always taken.
  The `beq` branch at 0xa3c targets 0x768, is taken when t9(=[sym(crm_dual_channel)]) == 0, and falls through when t9(=[sym(crm_dual_channel)]) != 0.
  The `beq` branch at 0xa44 targets 0xac8, is taken when at(?) == 0, and falls through when at(?) != 0.
  The `beq` branch at 0xa60 targets 0xabc, is taken when t9(?) == 0, and falls through when t9(?) != 0.
  The `bne` branch at 0xa90 targets 0xabc, is taken when a7(?) < a2(?) (signed), and falls through when a7(?) >= a2(?) (signed).
  The `beq` branch at 0xab4 targets 0xa6c, is taken when a7(?) >= a2(?) (signed), and falls through when a7(?) < a2(?) (signed).
  The `bne` branch at 0xac0 targets 0xa50, is taken when t2(?) != 0, and falls through when t2(?) == 0.
  The `beq` branch at 0xac8 targets 0x768 and is always taken.
  The `beq` branch at 0xad0 targets 0x90c and is always taken.
  The `beq` branch at 0xad8 targets 0x90c and is always taken.
  The `beq` branch at 0xae0 targets 0x908 and is always taken.
  The return at 0x970 has v0 = ([[a0+132]+80] | 0x1).

- `crimeBlankscreen` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_retrace.o)` at 0xae8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_retrace.o)`.
  Range: 0xae8-0xb70 (136 bytes).
  It occupies 136 bytes.
  The `lw` at 0xae8 loads 4 bytes from a0 (arg0 at entry) +0x8c.
  The `sb` at 0xaec stores 1 byte to [a0+140] +0x19.
  The `lw` at 0xaf0 loads 4 bytes from a0 (arg0 at entry) +0x7c.
  The `lbu` at 0xaf4 loads 1 byte from [a0+124] +0x2e.
  The `lhu` at 0xb24 loads 2 bytes from [a0+140] +0xe.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x80, including `lw` at 0xb28, `lw` at 0xb54.
  2 such `sw` accesses store 4 bytes to [a0+128] +0x1002c, including `sw` at 0xb40, `sw` at 0xb6c.
  The `beq` branch at 0xb0c targets 0xb44, is taken when at(=[[a0+124]+46]:1) == v0(=0x84), and falls through when at(=[[a0+124]+46]:1) != v0(=0x84).
  The `beq` branch at 0xb14 targets 0xb4c, is taken when a4(?) == a3(=0x2), and falls through when a4(?) != a3(=0x2).
  The `beq` branch at 0xb1c targets 0xb44, is taken when a2(=[sym(crm_dc_board_installed)]) == 0, and falls through when a2(=[sym(crm_dc_board_installed)]) != 0.
  The `beq` branch at 0xb4c targets 0xb44, is taken when a2(=[sym(crm_dc_board_installed)]) == 0, and falls through when a2(=[sym(crm_dc_board_installed)]) != 0.
  The return at 0xb44 has v0 = one of 0x84, ?.
  The return at 0xb68 has v0 = 0x84.

- `crimeRetraceHandler` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_retrace.o)` at 0xb80 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_retrace.o)`.
  Range: 0xb80-0xfe0 (1120 bytes).
  It occupies 1120 bytes.
  The `lw` at 0xb94 loads 4 bytes from a1 (arg1 at entry) +0x8c.
  The `lw` at 0xb9c loads 4 bytes from a1 (arg1 at entry) +0x80.
  The `ld` at 0xbbc loads 8 bytes from abs 0xffffffffb4000028.
  The `sd` at 0xbd4 stores 8 bytes to abs 0xffffffffb4000028.
  The `lhu` at 0xbd8 loads 2 bytes from [a1+140] +0xa.
  The `lhu` at 0xbe0 loads 2 bytes from [a1+140] +0x8.
  The `sw` at 0xbf4 stores 4 bytes to [a1+128] +0x10020.
  4 such `ld` accesses load 8 bytes from [a1+140] +0x0, including `ld` at 0xbf8, `ld` at 0xc88, `ld` at 0xe48.
  The `sd` at 0xc04 stores 8 bytes to [a1+140] +0x0.
  The `lw` at 0xc10 loads 4 bytes from [sym(gfxinfo)] +0x10.
  The `sw` at 0xc1c stores 4 bytes to [sym(gfxinfo)] +0x10.
  3 such `lw` accesses load 4 bytes from [a1+140] +0x20, including `lw` at 0xc30, `lw` at 0xc7c, `lw` at 0xe64.
  3 such `lbu` accesses load 1 byte from [a1+140] +0x17, including `lbu` at 0xc64, `lbu` at 0xdb8, `lbu` at 0xef0.
  The `lw` at 0xc9c loads 4 bytes from a1 (arg1 at entry) +0x4.
  The `lw` at 0xca0 loads 4 bytes from [a1+140] +0x340.
  10 such `lw` accesses load 4 bytes from ?, including `lw` at 0xcb4, `lw` at 0xd88, `lw` at 0xd98.
  The `sw` at 0xcc0 stores 4 bytes to [a1+140] +0x340.
  The `lw` at 0xcc4 loads 4 bytes from a1 (arg1 at entry) +0x50.
  The `lw` at 0xcc8 loads 4 bytes from a1 (arg1 at entry) +0x54.
  The `lw` at 0xccc loads 4 bytes from a1 (arg1 at entry) +0x4c.
  The `sw` at 0xcd4 stores 4 bytes to a1 (arg1 at entry) +0x50.
  The `sw` at 0xce0 stores 4 bytes to a1 (arg1 at entry) +0x4c.
  The `lbu` at 0xcf0 loads 1 byte from [a1+140] +0x16.
  The `lw` at 0xcfc loads 4 bytes from [a1+140] +0x344.
  2 such `lbu` accesses load 1 byte from [a1+140] +0x18, including `lbu` at 0xd54, `lbu` at 0xf38.
  6 such `lbu` accesses load 1 byte from ?, including `lbu` at 0xd7c, `lbu` at 0xda0, `lbu` at 0xdc4.
  10 such `sw` accesses store 4 bytes to ?, including `sw` at 0xdb4, `sw` at 0xdec, `sw` at 0xe04.
  The `sb` at 0xdc0 stores 1 byte to [a1+140] +0x17.
  4 such `sb` accesses store 1 byte to ?, including `sb` at 0xde0, `sb` at 0xe34, `sb` at 0xe38.
  4 such `sw` accesses store 4 bytes to [a1+128] +0x10018, including `sw` at 0xe58, `sw` at 0xe5c, `sw` at 0xfb8.
  The `lbu` at 0xe68 loads 1 byte from [a1+140] +0x1c.
  3 such `sb` accesses store 1 byte to [a1+140] +0x1c, including `sb` at 0xe84, `sb` at 0xeb0, `sb` at 0xed8.
  The `lbu` at 0xef4 loads 1 byte from a1 (arg1 at entry) +0x99.
  2 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x94, including `lw` at 0xf04, `lw` at 0xf1c.
  2 such `sw` accesses store 4 bytes to [a1+128] +0x70000, including `sw` at 0xf08, `sw` at 0xf58.
  2 such `sb` accesses store 1 byte to a1 (arg1 at entry) +0x99, including `sb` at 0xf10, `sb` at 0xf64.
  The `lw` at 0xf18 loads 4 bytes from [a1+128] +0x70004.
  2 such `sw` accesses store 4 bytes to [a1+128] +0x70004, including `sw` at 0xf34, `sw` at 0xf5c.
  The `lw` at 0xf48 loads 4 bytes from [a1+140] +0x10.
  The `lw` at 0xf68 loads 4 bytes from a1 (arg1 at entry) +0x78.
  The `lw` at 0xf6c loads 4 bytes from [a1+120] +0x4000.
  The `lw` at 0xfa8 loads 4 bytes from a1 (arg1 at entry) +0x0.
  The `lbu` at 0xfdc loads 1 byte from [a1+140] +0x38.
  The `jal` at 0xbb0 calls mutex_lock with a0=[a1+140]+840, a1=0x19, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xbf0 calls flushbus with a0=0xffffffffb4000000, a1=0xfffffffffffeffff, a2=?, a3=?.
  The `jalr` at 0xc20 calls (unknown callee) with a0=[sym(.sbss)+28], a1=[sym(.sbss)+24], a2=[sym(gfxinfo)], a3=?.
  The `jal` at 0xcac calls rrmValidateRetrace with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xd08 calls crime_i2cFpGbeRetrace with a0=[a1+140]+836, a1=[a1+128], a2=?, a3=?.
  The `jal` at 0xd34 calls mutex_unlock with a0=[a1+140]+840, a1=?, a2=?, a3=?.
  The `jal` at 0xdf0 calls rrmValidateVideoSync with a0=a1 at entry (arg1), a1=?, a2=?, a3=?.
  The `jal` at 0xe28 calls rrmValidateBuffer with a0=?, a1=?, a2=?, a3=[[a1+140]+23]:1-1, a7=0x2.
  The `jal` at 0xf54 calls flushbus with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xf90 calls vsema with a0=sym(crmswapsema), a1=?, a2=?, a3=[[a1+140]+23]:1-1.
  The `jal` at 0xfa4 calls rrmValidateMGRSwapBuf with a0=[a1], a1=?, a2=?, a3=[[a1+140]+23]:1-1, a7=0x2.
  The `beq` branch at 0xc18 targets 0xc28, is taken when a1(=[sym(.sbss)+24]) == 0, and falls through when a1(=[sym(.sbss)+24]) != 0.
  The `beq` branch at 0xc4c targets 0xe48, is taken when a3(=0x2) == a1(=[[a1+140]+32]), and falls through when a3(=0x2) != a1(=[[a1+140]+32]).
  The `beq` branch at 0xc5c targets 0xe68, is taken when a1(=[[a1+140]+32]) == a4(=0x10), and falls through when a1(=[[a1+140]+32]) != a4(=0x10).
  The `beq` branch at 0xc74 targets 0xca0, is taken when a5(=[[a1+140]+23]:1) == 0, and falls through when a5(=[[a1+140]+23]:1) != 0.
  The `beq` branch at 0xc80 targets 0xc98, is taken when a6(=[[a1+140]+32]) == 0, and falls through when a6(=[[a1+140]+32]) != 0.
  The `bne` branch at 0xc90 targets 0xca0, is taken when (t0(=[[a1+140]]:8) & 0x1) != 0, and falls through when (t0(=[[a1+140]]:8) & 0x1) == 0.
  The `beq` branch at 0xc98 targets 0xfd4 and is always taken.
  The `beq` branch at 0xca4 targets 0xcc0, is taken when s0(=[[a1+140]+832]) == 0, and falls through when s0(=[[a1+140]+832]) != 0.
  The `bne` branch at 0xcb8 targets 0xcac, is taken when s0(?) != 0, and falls through when s0(?) == 0.
  The `bne` branch at 0xcdc targets 0xdf0, is taken when t2(=[a1+84]) != 0, and falls through when t2(=[a1+84]) == 0.
  The `beq` branch at 0xce8 targets 0xef4, is taken when t8(=[sym(crm_dual_channel)]) == 0, and falls through when t8(=[sym(crm_dual_channel)]) != 0.
  The `beq` branch at 0xcf4 targets 0xf14, is taken when t9(=[[a1+140]+22]:1) == 0, and falls through when t9(=[[a1+140]+22]:1) != 0.
  The `beq` branch at 0xd00 targets 0xd10, is taken when ra(=[[a1+140]+836]) == 0, and falls through when ra(=[[a1+140]+836]) != 0.
  The `beq` branch at 0xd4c targets 0xde8, is taken when a1(=[sym(crm_dual_channel)]) == 0, and falls through when a1(=[sym(crm_dual_channel)]) != 0.
  The `beq` branch at 0xd5c targets 0xde8, is taken when (at(=[[a1+140]+24]:1) & 0x1) == 0, and falls through when (at(=[[a1+140]+24]:1) & 0x1) != 0.
  The `beq` branch at 0xd74 targets 0xca0, is taken when s3(?) >= 0x20 (signed), and falls through when s3(?) < 0x20 (signed).
  The `beq` branch at 0xd80 targets 0xd64, is taken when v1(?) == 0, and falls through when v1(?) != 0.
  The `beq` branch at 0xd90 targets 0xd4c, is taken when a4(?) >= 0x2 (signed), and falls through when a4(?) < 0x2 (signed).
  The `bne` branch at 0xd9c targets 0xdac, is taken when a1(?) != s7(?), and falls through when a1(?) == s7(?).
  The `beq` branch at 0xda4 targets 0xf68, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0xdac targets 0xe00, is taken when s6(=0x1) == a1(?), and falls through when s6(=0x1) != a1(?).
  The `beq` branch at 0xdc8 targets 0xe08, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0xdd4 targets 0xf90, is taken when s8(?) == s6(=0x1), and falls through when s8(?) != s6(=0x1).
  The `beq` branch at 0xddc targets 0xd64 and is always taken.
  The `beq` branch at 0xde8 targets 0xd64 and is always taken.
  The `beq` branch at 0xdf8 targets 0xce8 and is always taken.
  The `beq` branch at 0xe00 targets 0xd64 and is always taken.
  The `beq` branch at 0xe1c targets 0xfa0, is taken when a7(=0x2) == t0(?), and falls through when a7(=0x2) != t0(?).
  The `beq` branch at 0xe40 targets 0xd64 and is always taken.
  The `bne` branch at 0xe50 targets 0xc54, is taken when t3(?) != t8(=0x1), and falls through when t3(?) == t8(=0x1).
  The `beq` branch at 0xe60 targets 0xc54 and is always taken.
  The `beq` branch at 0xe70 targets 0xc64, is taken when t9(=[[a1+140]+28]:1) == 0, and falls through when t9(=[[a1+140]+28]:1) != 0.
  The `beq` branch at 0xe80 targets 0xfb4, is taken when (ra(=[[a1+140]]:8) & 0x1) == 0, and falls through when (ra(=[[a1+140]]:8) & 0x1) != 0.
  The `beq` branch at 0xe98 targets 0xeb4, is taken when at(?) == 0, and falls through when at(?) != 0.
  The `beq` branch at 0xeb4 targets 0xeec, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `beq` branch at 0xec0 targets 0xedc, is taken when v1(?) == 0, and falls through when v1(?) != 0.
  The `bne` branch at 0xee4 targets 0xe94, is taken when a6(?) != 0, and falls through when a6(?) == 0.
  The `beq` branch at 0xeec targets 0xc68 and is always taken.
  The `beq` branch at 0xefc targets 0xcfc, is taken when a2(=[a1+153]:1) == 0, and falls through when a2(=[a1+153]:1) != 0.
  The `beq` branch at 0xf0c targets 0xcfc and is always taken.
  The `beq` branch at 0xf2c targets 0xf60, is taken when (s2(=[[a1+128]+458756]) & 0x1) == 0, and falls through when (s2(=[[a1+128]+458756]) & 0x1) != 0.
  The `beq` branch at 0xf40 targets 0xf54, is taken when (t8(=[[a1+140]+24]:1) & 0x1) == 0, and falls through when (t8(=[[a1+140]+24]:1) & 0x1) != 0.
  The `beq` branch at 0xf60 targets 0xcfc and is always taken.
  The `beq` branch at 0xf78 targets 0xfc8, is taken when (v0(=0x10000000) & v1(=[[a1+120]+16384])) == 0, and falls through when (v0(=0x10000000) & v1(=[[a1+120]+16384])) != 0.
  The `bne` branch at 0xf80 targets 0xd64, is taken when a3(=one of 0x0, 0x1) != 0, and falls through when a3(=one of 0x0, 0x1) == 0.
  The `beq` branch at 0xf88 targets 0xdac and is always taken.
  The `beq` branch at 0xf98 targets 0xddc and is always taken.
  The `beq` branch at 0xfac targets 0xe3c and is always taken.
  The `beq` branch at 0xfc0 targets 0xe88 and is always taken.
  The `beq` branch at 0xfcc targets 0xf80 and is always taken.
  The `beq` branch at 0xfd8 targets 0xd80 and is always taken.
  The return at 0xd44 has v0 = 0x0.
  The instructions from 0xde4 to 0xde4 are not reached by any path from the entry, and their branches are not listed.

- `crimeRetraceHandler` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_retrace.o)` at 0xb80 (n32).
  Inferred: it is the per-board update that runs on the CRIME interrupt path, because it reads the
  CRIME Hardware Interrupt register at offset 0x28 (the `ld` at 0xbbc, linked row CRIME 0x28
  Hardware Interrupt) and works on one record under `mutex_lock` (the `jal` at 0xbb0) and
  `mutex_unlock` (the `jal` at 0xd34). It takes the lock at +0x348 of the record at +0x8c of its
  argument (the `jal` at 0xbb0, with 0x19 as the second argument). It reads the CRIME Hardware
  Interrupt register (the `ld` at 0xbbc), clears the 0x10000 bit with the mask 0xfffffffffffeffff
  (the `ori` at 0xbc4) and stores the result back (the `sd` at 0xbd4). It then writes the word at
  +0x10020 of the block at +0x80 of its argument (the `sw` at 0xbf4, in the delay slot of the
  `flushbus` call at 0xbf0) with the halfword at +0x8 of that record ORed with the halfword at +0xa
  shifted left by 0xc. It adds 1 to the doubleword at +0x0 of the record (the `ld` at 0xbf8 and the
  `sd` at 0xc04) and 1 to the word at +0x10 of the `gfxinfo` record (the `sw` at 0xc1c). When the
  word at `.sbss` +0x18 is nonzero it calls through it (the `jalr` at 0xc20) with the word at
  `.sbss` +0x1c as its argument (the `lw` at 0xc24). Further down it clears the word at +0x340 of
  the record (the `sw` at 0xcc0), calls `rrmValidateRetrace` (the `jal` at 0xcac),
  `crime_i2cFpGbeRetrace` with +0x344 of the record (the `jal` at 0xd08), `rrmValidateVideoSync`
  (the `jal` at 0xdf0), `rrmValidateBuffer` (the `jal` at 0xe28) and `rrmValidateMGRSwapBuf` (the
  `jal` at 0xfa4), and `vsema` on `crmswapsema` (the `jal` at 0xf90), under the conditions its
  branches select; it releases the lock with `mutex_unlock` and returns 0 (the return at 0xd44).
  Unknown: the value of the `.sbss` +0x18 word that the `jalr` at 0xc20 calls, which this routine
  only loads, and the bodies of `mutex_lock`, `mutex_unlock` and the `rrmValidate` callees, since
  the bundle has no notes for them.
  Evidence grade: inferred.

- `crime_i2cFpGbeRetrace` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_retrace.o)` at 0xfe0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_retrace.o)`.
  Range: 0xfe0-0x1098 (184 bytes).
  It occupies 184 bytes.
  The `lw` at 0xfe0 loads 4 bytes from a0 (arg0 at entry) +0x0.
  3 such `sw` accesses store 4 bytes to ?, including `sw` at 0x101c, `sw` at 0x1034, `sw` at 0x1084.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x0, including `sw` at 0x1048, `sw` at 0x108c.
  The `lbu` at 0x1058 loads 1 byte from sym(crmReverseBits) +0x0.
  The `bne` branch at 0xff4 targets 0x104c, is taken when a6(=[a0]) != at(=0x2), and falls through when a6(=[a0]) == at(=0x2).
  The `beq` branch at 0x1024 targets 0x1040, is taken when a3(?) >= 0x100 (signed), and falls through when a3(?) < 0x100 (signed).
  The `bne` branch at 0x1038 targets 0x1014, is taken when a3(?) < 0x100 (signed), and falls through when a3(?) >= 0x100 (signed).
  The `bne` branch at 0x1050 targets 0x1090, is taken when a6(=[a0]) != a7(=0x1), and falls through when a6(=[a0]) == a7(=0x1).
  The `bne` branch at 0x1080 targets 0x1058, is taken when a1(?) < 0x100 (signed), and falls through when a1(?) >= 0x100 (signed).
  The return at 0x1044 has v0 = ?.
  The return at 0x1090 has v0 = ?.

- `crimePreblankHandler` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_retrace.o)` at 0x10d4 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_retrace.o)`.
  Range: 0x10d4-0x19e4 (2320 bytes).
  It occupies 2320 bytes.
  3 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x80, including `lw` at 0x10e8, `lw` at 0x120c, `lw` at 0x153c.
  The `ld` at 0x10f4 loads 8 bytes from abs 0xffffffffb4000028.
  The `lw` at 0x10f8 loads 4 bytes from a1 (arg1 at entry) +0x84.
  The `lw` at 0x110c loads 4 bytes from a1 (arg1 at entry) +0x8c.
  The `sd` at 0x1118 stores 8 bytes to abs 0xffffffffb4000028.
  The `lbu` at 0x111c loads 1 byte from a1 (arg1 at entry) +0x98.
  2 such `lw` accesses load 4 bytes from [a1+140] +0x20, including `lw` at 0x1140, `lw` at 0x13cc.
  20 such `lw` accesses load 4 bytes from ?, including `lw` at 0x1170, `lw` at 0x11b0, `lw` at 0x11d4.
  8 such `sw` accesses store 4 bytes to ?, including `sw` at 0x1194, `sw` at 0x123c, `sw` at 0x1250.
  2 such `lw` accesses load 4 bytes from sym(crmGbeTables) +0x8, including `lw` at 0x1200, `lw` at 0x1254.
  6 such `lhu` accesses load 2 bytes from ?, including `lhu` at 0x1220, `lhu` at 0x1260, `lhu` at 0x1704.
  The `sw` at 0x1234 stores 4 bytes to [a1+128] +0x40004.
  The `lw` at 0x1280 loads 4 bytes from ret(tile_mapin) +0x0.
  2 such `lhu` accesses load 2 bytes from [a1+140] +0x14, including `lhu` at 0x1284, `lhu` at 0x12f4.
  The `sw` at 0x129c stores 4 bytes to ret(tile_mapin) +0x4.
  4 such `lhu` accesses load 2 bytes from [a1+140] +0xe, including `lhu` at 0x12a0, `lhu` at 0x12bc, `lhu` at 0x137c.
  The `sw` at 0x12a8 stores 4 bytes to ret(tile_mapin) +0x0.
  The `sw` at 0x1390 stores 4 bytes to sym(.bss) +0x0.
  The `sw` at 0x13bc stores 4 bytes to sym(.bss) -0x4.
  The `lbu` at 0x13c0 loads 1 byte from [a1+140] +0x17.
  2 such `ld` accesses load 8 bytes from [a1+140] +0x0, including `ld` at 0x13d8, `ld` at 0x17b4.
  10 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x1444, `lbu` at 0x1464, `lbu` at 0x1470.
  2 such `sb` accesses store 1 byte to ?, including `sb` at 0x144c, `sb` at 0x1870.
  2 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x4, including `lw` at 0x14cc, `lw` at 0x1838.
  2 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x78, including `lw` at 0x14d8, `lw` at 0x1848.
  The `lw` at 0x14dc loads 4 bytes from [a1+120] +0x4000.
  The `lw` at 0x1548 loads 4 bytes from [a1+128] +0x10000.
  The `lhu` at 0x154c loads 2 bytes from [a1+140] +0xc.
  The `lhu` at 0x1568 loads 2 bytes from [a1+140] +0x8.
  The `sh` at 0x1580 stores 2 bytes to [a1+140] +0x8.
  2 such `sb` accesses store 1 byte to [a1+140] +0x16, including `sb` at 0x1594, `sb` at 0x15c4.
  7 such `lbu` accesses load 1 byte from [a1+140] +0x18, including `lbu` at 0x15b0, `lbu` at 0x15e0, `lbu` at 0x17b8.
  3 such `sb` accesses store 1 byte to [a1+140] +0x18, including `sb` at 0x15cc, `sb` at 0x17d0, `sb` at 0x18a4.
  The `lw` at 0x1600 loads 4 bytes from table(sym(.sdata)+8) +0x0.
  The `sw` at 0x1604 stores 4 bytes to [a1+128] +0x10030.
  The `lbu` at 0x1608 loads 1 byte from [a1+140] +0x19.
  The `lw` at 0x161c loads 4 bytes from [a1+132] +0x8.
  3 such `sw` accesses store 4 bytes to [a1+128] +0x20008, including `sw` at 0x1620, `sw` at 0x1810, `sw` at 0x187c.
  6 such `sh` accesses store 2 bytes to ?, including `sh` at 0x16dc, `sh` at 0x1708, `sh` at 0x1714.
  4 such `lbu` accesses load 1 byte from [a1+140] +0x1a, including `lbu` at 0x172c, `lbu` at 0x18c4, `lbu` at 0x1920.
  2 such `lbu` accesses load 1 byte from [a1+140] +0x1b, including `lbu` at 0x1764, `lbu` at 0x18bc.
  The `lw` at 0x17f0 loads 4 bytes from ([a1+132] + ([[a1+140]+24]:1 << 0x2)) +0x4c.
  The `sw` at 0x17f4 stores 4 bytes to [a1+128] +0x3000c.
  The `lw` at 0x1808 loads 4 bytes from [a1+132] +0x0.
  The `lw` at 0x1874 loads 4 bytes from [a1+132] +0x4.
  2 such `lbu` accesses load 1 byte from sym(crmFrameBuffer) +0x18, including `lbu` at 0x18e8, `lbu` at 0x195c.
  2 such `lw` accesses load 4 bytes from sym(crmFrameBuffer) +0x8, including `lw` at 0x1908, `lw` at 0x1984.
  The `jal` at 0x126c calls tile_mapout with a0=[sym(.sdata)+4], a1=[sym(.sdata)+4], a2=?, a3=?, a6=[a1+132]+28.
  The `jal` at 0x1278 calls tile_mapin with a0=?, a1=0x10, a2=?, a3=?.
  The `jal` at 0x1350 calls bcopy with a0=ret(tile_mapin), a1=sym(.bss), a2=?, a3=?.
  The `jal` at 0x1528 calls crmNextIncarnation with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1530 calls crmNextIncarnation with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1598 calls mrunlock with a0=a1+484, a1=?, a2=?, a3=?.
  The `jal` at 0x15d8 calls bcopy with a0=sym(.bss), a1=[sym(.sdata)+4], a2=[sym(.sbss)+8], a3=?.
  The `jal` at 0x1630 calls mrunlock with a0=a1+484, a1=?, a2=one of 0x0, 0x1, a3=?.
  The `jal` at 0x1850 calls bcopy with a0=sym(.bss), a1=[sym(.sdata)+4], a2=[sym(.sbss)+8], a3=?.
  The `jal` at 0x1880 calls mrtryaccess with a0=a1+484, a1=?, a2=?, a3=?.
  The `beq` branch at 0x1138 targets 0x1638, is taken when (at(=[a1+152]:1) & 0x4) == 0, and falls through when (at(=[a1+152]:1) & 0x4) != 0.
  The `beq` branch at 0x1148 targets 0x17b4, is taken when s7(=0x2) == a0(=[[a1+140]+32]), and falls through when s7(=0x2) != a0(=[[a1+140]+32]).
  The `beq` branch at 0x1168 targets 0x11b0 and is always taken.
  The `beq` branch at 0x1184 targets 0x16d4, is taken when a7(?) >= a2(?) (unsigned), and falls through when a7(?) < a2(?) (unsigned).
  The `beq` branch at 0x118c targets 0x119c, is taken when a5(?) == t0(=0x3), and falls through when a5(?) != t0(=0x3).
  The `beq` branch at 0x11a8 targets 0x11f0, is taken when a0(?) >= 0x3 (signed), and falls through when a0(?) < 0x3 (signed).
  The `beq` branch at 0x11b4 targets 0x1668, is taken when a2(?) == s5(=0x1), and falls through when a2(?) != s5(=0x1).
  The `beq` branch at 0x11bc targets 0x1698, is taken when a2(?) == s7(=0x2), and falls through when a2(?) != s7(=0x2).
  The `beq` branch at 0x11cc targets 0x11f0, is taken when a0(?) >= 0x3 (signed), and falls through when a0(?) < 0x3 (signed).
  The `beq` branch at 0x11d8 targets 0x1170, is taken when a2(?) == s5(=0x1), and falls through when a2(?) != s5(=0x1).
  The `bne` branch at 0x11e0 targets 0x11a0, is taken when a2(?) != s7(=0x2), and falls through when a2(?) == s7(=0x2).
  The `beq` branch at 0x11e8 targets 0x11a0 and is always taken.
  The `beq` branch at 0x11f0 targets 0x13c0, is taken when a5(?) == t0(=0x3), and falls through when a5(?) != t0(=0x3).
  The `beq` branch at 0x1238 targets 0x1254, is taken when a1(?) == t0(=0x3), and falls through when a1(?) != t0(=0x3).
  The `beq` branch at 0x1264 targets 0x1274, is taken when a1(=[sym(.sdata)+4]) == 0, and falls through when a1(=[sym(.sdata)+4]) != 0.
  The `bne` branch at 0x1294 targets 0x12ac, is taken when t8(?) < t9(=[[a1+140]+20]:2) (unsigned), and falls through when t8(?) >= t9(=[[a1+140]+20]:2) (unsigned).
  The `beq` branch at 0x12b0 targets 0x13c0, is taken when at(=[sym(crm_dual_channel)]) == 0, and falls through when at(=[sym(crm_dual_channel)]) != 0.
  The `beq` branch at 0x12d0 targets 0x16a0, is taken when v0(?) >= a0(=[[a1+140]+14]:2) (unsigned), and falls through when v0(?) < a0(=[[a1+140]+14]:2) (unsigned).
  The `bne` branch at 0x12e0 targets 0x12c4, is taken when a5(?) < 0x800 (signed), and falls through when a5(?) >= 0x800 (signed).
  The `beq` branch at 0x12ec targets 0x16b8, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x12f8 targets 0x1310 and is always taken.
  The `beq` branch at 0x1308 targets 0x16bc, is taken when a5(?) >= 0x800 (signed), and falls through when a5(?) < 0x800 (signed).
  The `bne` branch at 0x131c targets 0x1300, is taken when a4(?) < v0(=[[a1+140]+20]:2) (unsigned), and falls through when a4(?) >= v0(=[[a1+140]+20]:2) (unsigned).
  The `beq` branch at 0x132c targets 0x133c, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `bne` branch at 0x1334 targets 0x1344, is taken when t8(?) != 0, and falls through when t8(?) == 0.
  The `beq` branch at 0x1358 targets 0x13c0, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `bne` branch at 0x1394 targets 0x13c0, is taken when a7(?) < a2(?) (unsigned), and falls through when a7(?) >= a2(?) (unsigned).
  The `beq` branch at 0x13b8 targets 0x137c, is taken when a7(?) >= a2(?) (unsigned), and falls through when a7(?) < a2(?) (unsigned).
  The `beq` branch at 0x13c4 targets 0x17ac, is taken when ra(=[[a1+140]+23]:1) == 0, and falls through when ra(=[[a1+140]+23]:1) != 0.
  The `beq` branch at 0x13d0 targets 0x13e8, is taken when v1(=[[a1+140]+32]) == 0, and falls through when v1(=[[a1+140]+32]) != 0.
  The `beq` branch at 0x13e0 targets 0x1860, is taken when (a0(=[[a1+140]]:8) & 0x1) == 0, and falls through when (a0(=[[a1+140]]:8) & 0x1) != 0.
  The `beq` branch at 0x143c targets 0x1464 and is always taken.
  The `beq` branch at 0x145c targets 0x1518, is taken when s4(?) >= 0x20 (signed), and falls through when s4(?) < 0x20 (signed).
  The `bne` branch at 0x1468 targets 0x1450, is taken when s5(=0x1) != v0(?), and falls through when s5(=0x1) == v0(?).
  The `beq` branch at 0x1474 targets 0x1450, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0x1484 targets 0x1450, is taken when a3(?) >= 0x2 (signed), and falls through when a3(?) < 0x2 (signed).
  The `beq` branch at 0x148c targets 0x1814, is taken when s7(=0x2) == a2(?), and falls through when s7(=0x2) != a2(?).
  The `beq` branch at 0x1498 targets 0x1450, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0x14a4 targets 0x1450, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0x14b8 targets 0x1450, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x14c4 targets 0x1868, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `bne` branch at 0x14d0 targets 0x14f4, is taken when a2(?) != a3(=[a1+4]), and falls through when a2(?) == a3(=[a1+4]).
  The `bne` branch at 0x14ec targets 0x1450, is taken when a4(?) < 0x1 (unsigned), and falls through when a4(?) >= 0x1 (unsigned).
  The `beq` branch at 0x14fc targets 0x1880, is taken when t1(?) == s5(=0x1), and falls through when t1(?) != s5(=0x1).
  The `blez` branch at 0x1504 targets 0x1444, is taken when a5(?) <= 0 (signed), and falls through when a5(?) > 0 (signed).
  The `beq` branch at 0x1510 targets 0x19dc and is always taken.
  The `beq` branch at 0x151c targets 0x153c, is taken when t1(?) == 0, and falls through when t1(?) != 0.
  The `bne` branch at 0x1560 targets 0x15a8, is taken when a7(?) < t0(=[[a1+140]+12]:2-4) (signed), and falls through when a7(?) >= t0(=[[a1+140]+12]:2-4) (signed).
  The `beq` branch at 0x1574 targets 0x1588, is taken when t1(?) >= 0x64 (signed), and falls through when t1(?) < 0x64 (signed).
  The `beq` branch at 0x1588 targets 0x1608, is taken when t3(=[sym(crm_dual_channel)]) == 0, and falls through when t3(=[sym(crm_dual_channel)]) != 0.
  The `beq` branch at 0x1590 targets 0x1638, is taken when t8(=one of 0x0, 0x1) == 0, and falls through when t8(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x15a0 targets 0x163c and is always taken.
  The `beq` branch at 0x15a8 targets 0x1608, is taken when t9(=[sym(crm_dual_channel)]) == 0, and falls through when t9(=[sym(crm_dual_channel)]) != 0.
  The `beq` branch at 0x15c8 targets 0x184c, is taken when (ra(?) & 0x1) == 0, and falls through when (ra(?) & 0x1) != 0.
  The `beq` branch at 0x1614 targets 0x17d4, is taken when a0(=[[a1+140]+25]:1) == 0, and falls through when a0(=[[a1+140]+25]:1) != 0.
  The `beq` branch at 0x1628 targets 0x163c, is taken when a2(=one of 0x0, 0x1) == 0, and falls through when a2(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x167c targets 0x16b0, is taken when a7(?) >= a2(?) (unsigned), and falls through when a7(?) < a2(?) (unsigned).
  The `beq` branch at 0x1684 targets 0x1690, is taken when a5(?) == t0(=0x3), and falls through when a5(?) != t0(=0x3).
  The `beq` branch at 0x1690 targets 0x11c4 and is always taken.
  The `beq` branch at 0x1698 targets 0x11c4 and is always taken.
  The `beq` branch at 0x16a8 targets 0x12ec and is always taken.
  The `beq` branch at 0x16b0 targets 0x11c4 and is always taken.
  The `beq` branch at 0x16bc targets 0x133c, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `beq` branch at 0x16c4 targets 0x133c, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0x16cc targets 0x1344 and is always taken.
  The `beq` branch at 0x16d4 targets 0x11a0 and is always taken.
  The `beq` branch at 0x1720 targets 0x1444, is taken when t0(?) >= at(?) (signed), and falls through when t0(?) < at(?) (signed).
  The `beq` branch at 0x175c targets 0x16e8, is taken when t8(?) >= at(=[[a1+140]+26]:1) (signed), and falls through when t8(?) < at(=[[a1+140]+26]:1) (signed).
  The `beq` branch at 0x1780 targets 0x16e8, is taken when a5(?) >= at(=[[a1+140]+27]:1) (signed), and falls through when a5(?) < at(=[[a1+140]+27]:1) (signed).
  The `bne` branch at 0x1798 targets 0x16dc, is taken when at(?) != 0, and falls through when at(?) == 0.
  The `beq` branch at 0x17a4 targets 0x16e0 and is always taken.
  The `beq` branch at 0x17ac targets 0x153c and is always taken.
  The `beq` branch at 0x17cc targets 0x1150 and is always taken.
  The `beq` branch at 0x1800 targets 0x1874, is taken when (a3(=[[a1+140]+24]:1) & 0x1) == 0, and falls through when (a3(=[[a1+140]+24]:1) & 0x1) != 0.
  The `beq` branch at 0x180c targets 0x1624 and is always taken.
  The `beq` branch at 0x1818 targets 0x1494, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `beq` branch at 0x1824 targets 0x1450, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x1830 targets 0x186c, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `bne` branch at 0x183c targets 0x14f4, is taken when t0(=[a1+4]) != 0, and falls through when t0(=[a1+4]) == 0.
  The `beq` branch at 0x1844 targets 0x14dc and is always taken.
  The `beq` branch at 0x1858 targets 0x15e4 and is always taken.
  The `beq` branch at 0x1860 targets 0x153c and is always taken.
  The `beq` branch at 0x186c targets 0x1450 and is always taken.
  The `beq` branch at 0x1878 targets 0x1624 and is always taken.
  The `beq` branch at 0x188c targets 0x153c, is taken when v0(=ret(mrtryaccess)) == 0, and falls through when v0(=ret(mrtryaccess)) != 0.
  The `beq` branch at 0x18a0 targets 0x19d0, is taken when (a4(?) & 0x2) == 0, and falls through when (a4(?) & 0x2) != 0.
  The `beq` branch at 0x18b8 targets 0x18c4, is taken when v0(=[sym(crm_dual_channel)]) == 0, and falls through when v0(=[sym(crm_dual_channel)]) != 0.
  The `bne` branch at 0x18d8 targets 0x193c, is taken when t0(?) < 0x1 (signed), and falls through when t0(?) >= 0x1 (signed).
  The `blez` branch at 0x18fc targets 0x1934, is taken when a6(=[[a1+140]+26]:1) <= 0 (signed), and falls through when a6(=[[a1+140]+26]:1) > 0 (signed).
  The `bne` branch at 0x192c targets 0x1908, is taken when a2(?) < a6(=[[a1+140]+26]:1) (signed), and falls through when a2(?) >= a6(=[[a1+140]+26]:1) (signed).
  The `bne` branch at 0x1934 targets 0x18e8, is taken when t8(?) != 0, and falls through when t8(?) == 0.
  The `beq` branch at 0x193c targets 0x19bc, is taken when v0(=[sym(crm_dual_channel)]) == 0, and falls through when v0(=[sym(crm_dual_channel)]) != 0.
  The `beq` branch at 0x1948 targets 0x19b8, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `blez` branch at 0x1974 targets 0x19b0, is taken when a6(=[[a1+140]+26]:1) <= 0 (signed), and falls through when a6(=[[a1+140]+26]:1) > 0 (signed).
  The `bne` branch at 0x19a8 targets 0x1984, is taken when v0(?) < a6(=[[a1+140]+26]:1) (signed), and falls through when v0(?) >= a6(=[[a1+140]+26]:1) (signed).
  The `bne` branch at 0x19b0 targets 0x195c, is taken when a1(?) != 0, and falls through when a1(?) == 0.
  The `beq` branch at 0x19c8 targets 0x1504 and is always taken.
  The `beq` branch at 0x19d4 targets 0x18b0 and is always taken.
  The `beq` branch at 0x19dc targets 0x172c and is always taken.
  The return at 0x1660 has v0 = one of ret(mrunlock), [a1+128]+131072, ?.

- `crm_copy_swap_boxes` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_retrace.o)` at 0x19e4 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_retrace.o)`.
  Range: 0x19e4-0x1cdc (760 bytes).
  It occupies 760 bytes.
  The `lw` at 0x1ab8 loads 4 bytes from a1 (arg1 at entry) +0x0.
  The `sw` at 0x1aec stores 4 bytes to ?.
  4 such `lw` accesses load 4 bytes from ?, including `lw` at 0x1af0, `lw` at 0x1af4, `lw` at 0x1af8.
  4 such `lh` accesses load 2 bytes from ?, including `lh` at 0x1b1c, `lh` at 0x1b30, `lh` at 0x1b34.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x3020, including `sw` at 0x1bac, `sw` at 0x1c2c.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x3028, including `sw` at 0x1bb4, `sw` at 0x1c34.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x3030, including `sw` at 0x1bbc, `sw` at 0x1c3c.
  2 such `sw` accesses store 4 bytes to (a0+12344 | 0x800) +0x0, including `sw` at 0x1bc0, `sw` at 0x1c40.
  The `sw` at 0x1c78 stores 4 bytes to a0 (arg0 at entry) +0x3078.
  The `sd` at 0x1c90 stores 8 bytes to a0 (arg0 at entry) +0x2070.
  The `sw` at 0x1c94 stores 4 bytes to (a0+8352 | 0x800) +0x0.
  The `sw` at 0x1c9c stores 4 bytes to a0 (arg0 at entry) +0x21f8.
  The `jal` at 0x1b84 calls crmFifoWait with a0=a0 at entry (arg0), a1=0x4, a2=0xf4240, a3=?.
  The `jal` at 0x1c04 calls crmFifoWait with a0=a0 at entry (arg0), a1=0x4, a2=0xf4240, a3=?.
  The `jal` at 0x1c54 calls crmFifoWait with a0=a0 at entry (arg0), a1=0x4, a2=0xf4240, a3=?.
  The `beq` branch at 0x1a2c targets 0x1ca0, is taken when a7 == 0, and falls through when a7 != 0.
  The `beq` branch at 0x1a58 targets 0x1cd0 and is always taken.
  The `beq` branch at 0x1a70 targets 0x1ca0, is taken when t1(?) >= t8(=a7) (unsigned), and falls through when t1(?) < t8(=a7) (unsigned).
  The `beq` branch at 0x1a78 targets 0x1a88, is taken when t2(?) == 0, and falls through when t2(?) != 0.
  The `beq` branch at 0x1a80 targets 0x1a8c and is always taken.
  The `beq` branch at 0x1a9c targets 0x1aa8, is taken when t3(=a7) >= t2(?) (unsigned), and falls through when t3(=a7) < t2(?) (unsigned).
  The `blez` branch at 0x1aac targets 0x1a64, is taken when ra(=a2) <= 0 (signed), and falls through when ra(=a2) > 0 (signed).
  The `beq` branch at 0x1ab4 targets 0x1af4 and is always taken.
  The `bne` branch at 0x1ad0 targets 0x1b1c, is taken when at(?) < v0(?) (signed), and falls through when at(?) >= v0(?) (signed).
  The `beq` branch at 0x1ae8 targets 0x1a60, is taken when s5(?) >= v1(=a2) (signed), and falls through when s5(?) < v1(=a2) (signed).
  The `blez` branch at 0x1b0c targets 0x1adc, is taken when a1(?) <= 0 (signed), and falls through when a1(?) > 0 (signed).
  The `bne` branch at 0x1b28 targets 0x1ad8, is taken when a2(?) < s1(?) (unsigned), and falls through when a2(?) >= s1(?) (unsigned).
  The `beq` branch at 0x1b5c targets 0x1bc4, is taken when (t1(?) & t2(=-0x8)) == 0, and falls through when (t1(?) & t2(=-0x8)) != 0.
  The `bne` branch at 0x1b8c targets 0x1ad8, is taken when v0(=ret(crmFifoWait)) != 0, and falls through when v0(=ret(crmFifoWait)) == 0.
  The `beq` branch at 0x1bc4 targets 0x1abc, is taken when s4(?) == 0, and falls through when s4(?) != 0.
  The `beq` branch at 0x1be0 targets 0x1c44, is taken when (t2(?) & t3(=a6)) == 0, and falls through when (t2(?) & t3(=a6)) != 0.
  The `bne` branch at 0x1c0c targets 0x1ad8, is taken when v0(=ret(crmFifoWait)) != 0, and falls through when v0(=ret(crmFifoWait)) == 0.
  The `beq` branch at 0x1c44 targets 0x1ac0, is taken when s8(?) == 0, and falls through when s8(?) != 0.
  The `bne` branch at 0x1c5c targets 0x1ad8, is taken when v0(=ret(crmFifoWait)) != 0, and falls through when v0(=ret(crmFifoWait)) == 0.
  The `beq` branch at 0x1c98 targets 0x1abc and is always taken.
  The `beq` branch at 0x1cd4 targets 0x1a78 and is always taken.
  The return at 0x1cc8 has v0 = ?.

- `crmSwapBufd` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_retrace.o)` at 0x1cdc (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_retrace.o)`.
  Range: 0x1cdc-0x20f0 (1044 bytes).
  It occupies 1044 bytes.
  The `lw` at 0x1d2c loads 4 bytes from a0 (arg0 at entry) +0x18.
  The `lw` at 0x1d38 loads 4 bytes from [a0+24] +0x78.
  The `lw` at 0x1d44 loads 4 bytes from [a0+24] +0x8c.
  2 such `lw` accesses load 4 bytes from [a0+24] +0x7c, including `lw` at 0x1d7c, `lw` at 0x1df4.
  The `lbu` at 0x1d88 loads 1 byte from [[a0+24]+124] +0x2f.
  2 such `sw` accesses store 4 bytes to [[a0+24]+120] +0x2000, including `sw` at 0x1da4, `sw` at 0x20b8.
  2 such `sw` accesses store 4 bytes to [[a0+24]+120] +0x2008, including `sw` at 0x1da8, `sw` at 0x20c4.
  The `sw` at 0x1db8 stores 4 bytes to [[a0+24]+120] +0x2018.
  The `sw` at 0x1dc0 stores 4 bytes to [[a0+24]+120] +0x2060.
  The `sw` at 0x1dc8 stores 4 bytes to [[a0+24]+120] +0x21b0.
  The `sw` at 0x1dcc stores 4 bytes to [[a0+24]+120] +0x2050.
  The `sw` at 0x1dd0 stores 4 bytes to [[a0+24]+120] +0x2058.
  The `sw` at 0x1dd4 stores 4 bytes to [[a0+24]+120] +0x2010.
  The `sd` at 0x1dd8 stores 8 bytes to [[a0+24]+120] +0x20a8.
  The `sw` at 0x1ddc stores 4 bytes to [[a0+24]+120] +0x3008.
  The `sw` at 0x1de4 stores 4 bytes to [[a0+24]+120] +0x3000.
  The `sw` at 0x1dec stores 4 bytes to [[a0+24]+120] +0x3040.
  The `sw` at 0x1df0 stores 4 bytes to [[a0+24]+120] +0x3048.
  The `lhu` at 0x1dfc loads 2 bytes from [[a0+24]+124] +0x22.
  The `sw` at 0x1e18 stores 4 bytes to [[a0+24]+120] +0x3078.
  The `lw` at 0x1e40 loads 4 bytes from sym(crmFrameBuffer) +0x4.
  21 such `sw` accesses store 4 bytes to ?, including `sw` at 0x1e84, `sw` at 0x1e94, `sw` at 0x1e98.
  26 such `lw` accesses load 4 bytes from ?, including `lw` at 0x1e8c, `lw` at 0x1ebc, `lw` at 0x1ee4.
  3 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x1eac, `lbu` at 0x1ed0, `lbu` at 0x20ec.
  2 such `sb` accesses store 1 byte to ?, including `sb` at 0x1efc, `sb` at 0x1f44.
  2 such `lw` accesses load 4 bytes from [a0+24] +0x0, including `lw` at 0x1fb0, `lw` at 0x1ff8.
  The `jal` at 0x1d1c calls init_sema with a0=sym(crmswapsema), a1=0x0, a2=sym(.rodata)+40, a3=-0x1.
  The `jal` at 0x1d24 calls semahistoff with a0=sym(crmswapsema), a1=?, a2=?, a3=?.
  The `jal` at 0x1d60 calls crmLoadTlbABC with a0=[a0+24], a1=sym(crmFrameBuffer), a2=0x0, a3=?.
  The `jal` at 0x1d74 calls crmLoadTlbABC with a0=[a0+24], a1=sym(crmbackbuffer), a2=0x1, a3=?.
  The `jal` at 0x1e08 calls crm_copy_swap_boxes with a0=[[a0+24]+120], a1=sp-352, a2=?, a3=one of 0x11, 0x12, a4=one of 0x10000, 0x30000, a5=one of -0x10, -0x8, a6=one of -0x80, -0x40, a7=[[[a0+24]+124]+34]:2-1.
  The `jal` at 0x1e1c calls crmIdleWait with a0=[[a0+24]+120], a1=0xf423f, a2=?, a3=?.
  The `jal` at 0x1e24 calls mrunlock with a0=[a0+24]+484, a1=?, a2=?, a3=?.
  The `jal` at 0x1e34 calls psema with a0=sym(crmswapsema), a1=0x1a, a2=?, a3=?.
  The `jal` at 0x1e4c calls mraccessf with a0=[a0+24]+484, a1=0x0, a2=[sym(crmFrameBuffer)+4], a3=?.
  The `jal` at 0x1e54 calls RRM_CheckValidFault with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x2060 calls rrmValidateMGRSwapBuf with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x208c calls rrmValidateBuffer with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x20c8 calls mrunlock with a0=[a0+24]+484, a1=?, a2=?, a3=?.
  The `jal` at 0x20d8 calls cmn_err with a0=0x1, a1=sym(.rodata), a2=?, a3=?.
  The `beq` branch at 0x1d4c targets 0x1e30 and is always taken.
  The `blez` branch at 0x1d54 targets 0x1e24, is taken when s2(?) <= 0 (signed), and falls through when s2(?) > 0 (signed).
  The `beq` branch at 0x1d9c targets 0x20a4, is taken when a0(=0x20) == a2(=[[[a0+24]+124]+47]:1), and falls through when a0(=0x20) != a2(=[[[a0+24]+124]+47]:1).
  The `bgtz` branch at 0x1e2c targets 0x2054, is taken when s3(?) > 0 (signed), and falls through when s3(?) <= 0 (signed).
  The `beq` branch at 0x1e3c targets 0x2024, is taken when v0(=ret(psema)) == s1(=-0x1), and falls through when v0(=ret(psema)) != s1(=-0x1).
  The `beq` branch at 0x1e44 targets 0x1e30, is taken when a2(=[sym(crmFrameBuffer)+4]) == 0, and falls through when a2(=[sym(crmFrameBuffer)+4]) != 0.
  The `bltz` branch at 0x1e5c targets 0x20c8, is taken when v0(=ret(RRM_CheckValidFault)) < 0 (signed), and falls through when v0(=ret(RRM_CheckValidFault)) >= 0 (signed).
  The `beq` branch at 0x1e7c targets 0x20e8 and is always taken.
  The `beq` branch at 0x1ea4 targets 0x1d54, is taken when t0(?) == 0, and falls through when t0(?) != 0.
  The `beq` branch at 0x1eb4 targets 0x1ec8, is taken when (a5(?) & 0x2) == 0, and falls through when (a5(?) & 0x2) != 0.
  The `blez` branch at 0x1ec0 targets 0x1f38, is taken when t1(?) <= 0 (signed), and falls through when t1(?) > 0 (signed).
  The `beq` branch at 0x1ec8 targets 0x1d54, is taken when t0(?) == 0, and falls through when t0(?) != 0.
  The `beq` branch at 0x1edc targets 0x1e9c, is taken when (a5(?) & 0x2) == 0, and falls through when (a5(?) & 0x2) != 0.
  The `bgtz` branch at 0x1ee8 targets 0x1e9c, is taken when t8(?) > 0 (signed), and falls through when t8(?) <= 0 (signed).
  The `beq` branch at 0x1ef8 targets 0x1fdc, is taken when t1(?) == 0, and falls through when t1(?) != 0.
  The `beq` branch at 0x1f04 targets 0x1e98, is taken when ra(?) == 0, and falls through when ra(?) != 0.
  The `bne` branch at 0x1f28 targets 0x1e84, is taken when at(?) != 0, and falls through when at(?) == 0.
  The `beq` branch at 0x1f30 targets 0x1e9c and is always taken.
  The `beq` branch at 0x1f40 targets 0x1f94, is taken when t1(?) == 0, and falls through when t1(?) != 0.
  The `beq` branch at 0x1f4c targets 0x1f8c, is taken when t3(?) == 0, and falls through when t3(?) != 0.
  The `beq` branch at 0x1f70 targets 0x1f8c, is taken when t8(?) == 0, and falls through when t8(?) != 0.
  The `beq` branch at 0x1f8c targets 0x1ec8 and is always taken.
  The `beq` branch at 0x1f98 targets 0x1ec8, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x1fb8 targets 0x1fd4, is taken when t3(?) == 0, and falls through when t3(?) != 0.
  The `beq` branch at 0x1fd4 targets 0x1ec8 and is always taken.
  The `beq` branch at 0x1fe0 targets 0x1e9c, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x2000 targets 0x201c, is taken when ra(?) == 0, and falls through when ra(?) != 0.
  The `beq` branch at 0x201c targets 0x1e9c and is always taken.
  The `beq` branch at 0x2058 targets 0x2080 and is always taken.
  The `beq` branch at 0x2078 targets 0x209c, is taken when v0(?) >= s3(?) (signed), and falls through when v0(?) < s3(?) (signed).
  The `bne` branch at 0x2084 targets 0x2060, is taken when a1(?) != 0, and falls through when a1(?) == 0.
  The `beq` branch at 0x2094 targets 0x206c and is always taken.
  The `beq` branch at 0x209c targets 0x1e34 and is always taken.
  The `beq` branch at 0x20c0 targets 0x1dac and is always taken.
  The `beq` branch at 0x20e0 targets 0x2028 and is always taken.
  The `beq` branch at 0x20e8 targets 0x1eb0 and is always taken.
  The return at 0x204c has v0 = one of ret(psema), ret(cmn_err).

- `crimeSchedSwapBuf` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_retrace.o)` at 0x20f0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_retrace.o)`.
  Range: 0x20f0-0x22e8 (504 bytes).
  It occupies 504 bytes.
  The `lw` at 0x20f8 loads 4 bytes from a0 (arg0 at entry) +0x8c.
  4 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x2124, `lbu` at 0x21ec, `lbu` at 0x2234.
  The `lw` at 0x2130 loads 4 bytes from a0 (arg0 at entry) +0x7c.
  The `lbu` at 0x2134 loads 1 byte from [a0+124] +0x2f.
  The `lw` at 0x2138 loads 4 bytes from ?.
  5 such `sb` accesses store 1 byte to ?, including `sb` at 0x2160, `sb` at 0x21b0, `sb` at 0x21fc.
  4 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x1c, including `lw` at 0x2164, `lw` at 0x2204, `lw` at 0x2258.
  21 such `sw` accesses store 4 bytes to ?, including `sw` at 0x2178, `sw` at 0x217c, `sw` at 0x2180.
  The `lbu` at 0x21b4 loads 1 byte from [a0+140] +0x17.
  The `sb` at 0x21c4 stores 1 byte to [a0+140] +0x17.
  The `jal` at 0x21a8 calls mutex_lock with a0=[a0+140]+840, a1=0x19, a2=a2 at entry (arg2), a3=?.
  The `jal` at 0x21c0 calls mutex_unlock with a0=[a0+140]+840, a1=[[a0+140]+23]:1+1, a2=?, a3=?.
  The `jal` at 0x22c0 calls cmn_err with a0=0x4, a1=sym(.rodata)+48, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x22d8 calls cmn_err with a0=0x4, a1=sym(.rodata)+104, a2=a2 at entry (arg2), a3=?, a7=0x14.
  The `bltz` branch at 0x2104 targets 0x21e4, is taken when a2 < 0 (signed), and falls through when a2 >= 0 (signed).
  The `beq` branch at 0x2110 targets 0x21e4, is taken when a2 >= 0x20 (signed), and falls through when a2 < 0x20 (signed).
  The `bne` branch at 0x2128 targets 0x22b8, is taken when v0(?) != 0, and falls through when v0(?) == 0.
  The `beq` branch at 0x2144 targets 0x222c, is taken when t8(=[[a0+124]+47]:1) == t9(=0x20), and falls through when t8(=[[a0+124]+47]:1) != t9(=0x20).
  The `beq` branch at 0x2150 targets 0x21ec, is taken when a6(?) == t9(=0x4), and falls through when a6(?) != t9(=0x4).
  The `beq` branch at 0x2158 targets 0x21ec, is taken when a6(?) == ra(=0x10), and falls through when a6(?) != ra(=0x10).
  The `bne` branch at 0x216c targets 0x217c, is taken when a0(=[a1+28]) < 0x2 (signed), and falls through when a0(=[a1+28]) >= 0x2 (signed).
  The `beq` branch at 0x2174 targets 0x2180 and is always taken.
  The `beq` branch at 0x2190 targets 0x2280, is taken when a3 == 0, and falls through when a3 != 0.
  The `beq` branch at 0x21e4 targets 0x21cc and is always taken.
  The `bne` branch at 0x21f4 targets 0x22d0, is taken when (a3(?) & 0x2) != 0, and falls through when (a3(?) & 0x2) == 0.
  The `bne` branch at 0x220c targets 0x221c, is taken when a0(=[a1+28]) < 0x2 (signed), and falls through when a0(=[a1+28]) >= 0x2 (signed).
  The `beq` branch at 0x2214 targets 0x2220 and is always taken.
  The `beq` branch at 0x2224 targets 0x21a0 and is always taken.
  The `beq` branch at 0x222c targets 0x2240, is taken when a6(?) == a7(=0x14), and falls through when a6(?) != a7(=0x14).
  The `beq` branch at 0x2238 targets 0x228c, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `bne` branch at 0x2248 targets 0x22d4, is taken when (a6(?) & 0x2) != 0, and falls through when (a6(?) & 0x2) == 0.
  The `bne` branch at 0x2260 targets 0x2270, is taken when a0(=[a1+28]) < 0x2 (signed), and falls through when a0(=[a1+28]) >= 0x2 (signed).
  The `beq` branch at 0x2268 targets 0x2274 and is always taken.
  The `beq` branch at 0x2278 targets 0x21a0 and is always taken.
  The `beq` branch at 0x2284 targets 0x21a0 and is always taken.
  The `bne` branch at 0x2298 targets 0x22a8, is taken when a0(=[a1+28]) < 0x2 (signed), and falls through when a0(=[a1+28]) >= 0x2 (signed).
  The `beq` branch at 0x22a0 targets 0x22ac and is always taken.
  The `beq` branch at 0x22b0 targets 0x2188 and is always taken.
  The `beq` branch at 0x22c8 targets 0x21cc and is always taken.
  The `beq` branch at 0x22e0 targets 0x21cc and is always taken.
  The return at 0x21dc has v0 = one of 0x0, 0x10, 0x16.

- `crimeUnSchedSwapBuf` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_retrace.o)` at 0x22e8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_retrace.o)`.
  Range: 0x22e8-0x2484 (412 bytes).
  It occupies 412 bytes.
  The `lw` at 0x2300 loads 4 bytes from a0 (arg0 at entry) +0x18.
  The `lw` at 0x2314 loads 4 bytes from [a0+24] +0x8c.
  4 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x2360, `lbu` at 0x2370, `lbu` at 0x2394.
  5 such `sb` accesses store 1 byte to ?, including `sb` at 0x237c, `sb` at 0x23e4, `sb` at 0x2408.
  2 such `lbu` accesses load 1 byte from [[a0+24]+140] +0x17, including `lbu` at 0x2380, `lbu` at 0x240c.
  2 such `sb` accesses store 1 byte to [[a0+24]+140] +0x17, including `sb` at 0x2390, `sb` at 0x241c.
  The `lw` at 0x23a4 loads 4 bytes from [a0+24] +0x4.
  2 such `lw` accesses load 4 bytes from [[a0+24]+4] +0x30, including `lw` at 0x23b0, `lw` at 0x23c8.
  The `lw` at 0x23b4 loads 4 bytes from [a0+24] +0x0.
  The `lw` at 0x23cc loads 4 bytes from [[[a0+24]+4]+48] +0x4.
  6 such `sw` accesses store 4 bytes to ?, including `sw` at 0x23e8, `sw` at 0x23ec, `sw` at 0x23f8.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0x23fc, `lw` at 0x242c.
  The `jal` at 0x2348 calls mutex_lock with a0=[[a0+24]+140]+840, a1=0x19, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x238c calls mutex_unlock with a0=[[a0+24]+140]+840, a1=?, a2=?, a3=?.
  The `jal` at 0x23c0 calls rrmInvalidateRN with a0=[[[a0+24]+4]+48], a1=[[a0+24]+4], a2=0x1, a3=?.
  The `jal` at 0x23dc calls rrmDoUnMapGfx with a0=[[[a0+24]+4]+48], a1=?, a2=?, a3=?.
  The `jal` at 0x2418 calls mutex_unlock with a0=[[a0+24]+140]+840, a1=?, a2=?, a3=?.
  The `jal` at 0x2454 calls mutex_unlock with a0=[[a0+24]+140]+840, a1=?, a2=?, a3=?.
  The `jal` at 0x2464 calls mutex_unlock with a0=[[a0+24]+140]+840, a1=?, a2=?, a3=?.
  The `jal` at 0x2474 calls mutex_unlock with a0=[[a0+24]+140]+840, a1=?, a2=?, a3=?.
  The `bltz` branch at 0x2310 targets 0x2324, is taken when a2 < 0 (signed), and falls through when a2 >= 0 (signed).
  The `bne` branch at 0x231c targets 0x2344, is taken when a2 < 0x20 (signed), and falls through when a2 >= 0x20 (signed).
  The `beq` branch at 0x2364 targets 0x23fc, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x236c targets 0x244c, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x2374 targets 0x2464, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x239c targets 0x23e4, is taken when (t9(?) & 0x2) == 0, and falls through when (t9(?) & 0x2) != 0.
  The `beq` branch at 0x23a8 targets 0x23e4, is taken when s1(=[[a0+24]+4]) == 0, and falls through when s1(=[[a0+24]+4]) != 0.
  The `bne` branch at 0x23b8 targets 0x23e4, is taken when ra(=[[a0+24]]) != a0(=[[[a0+24]+4]+48]), and falls through when ra(=[[a0+24]]) == a0(=[[[a0+24]+4]+48]).
  The `beq` branch at 0x23d4 targets 0x23e4, is taken when (at(=[[[[a0+24]+4]+48]+4]) & 0x1) == 0, and falls through when (at(=[[[[a0+24]+4]+48]+4]) & 0x1) != 0.
  The `beq` branch at 0x23f4 targets 0x2324 and is always taken.
  The `beq` branch at 0x2400 targets 0x2474, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `beq` branch at 0x2430 targets 0x2444, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x2444 targets 0x2328 and is always taken.
  The `bne` branch at 0x244c targets 0x237c, is taken when v0(?) != 0, and falls through when v0(?) == 0.
  The `beq` branch at 0x245c targets 0x2324 and is always taken.
  The `beq` branch at 0x246c targets 0x23e8 and is always taken.
  The `beq` branch at 0x247c targets 0x2324 and is always taken.
  The return at 0x233c has v0 = one of -0x16, 0x0, 0x1.

- `crimeSchedMgrSwapBuf` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_retrace.o)` at 0x2484 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_retrace.o)`.
  Range: 0x2484-0x25b4 (304 bytes).
  It occupies 304 bytes.
  The `lw` at 0x249c loads 4 bytes from a0 (arg0 at entry) +0x18.
  The `lw` at 0x24b0 loads 4 bytes from [a0+24] +0x8c.
  2 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x24d0, `lbu` at 0x2518.
  The `lw` at 0x24e0 loads 4 bytes from [a0+24] +0x7c.
  The `lbu` at 0x24e4 loads 1 byte from [[a0+24]+124] +0x2f.
  3 such `sb` accesses store 1 byte to ?, including `sb` at 0x250c, `sb` at 0x252c, `sb` at 0x2558.
  5 such `sw` accesses store 4 bytes to ?, including `sw` at 0x2524, `sw` at 0x2530, `sw` at 0x2534.
  The `lbu` at 0x255c loads 1 byte from [[a0+24]+140] +0x17.
  The `sb` at 0x256c stores 1 byte to [[a0+24]+140] +0x17.
  The `jal` at 0x24ac calls RRM_CheckValidFault with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x254c calls mutex_lock with a0=[[a0+24]+140]+840, a1=0x19, a2=0x14, a3=?.
  The `jal` at 0x2568 calls mutex_unlock with a0=[[a0+24]+140]+840, a1=?, a2=?, a3=?.
  The `jal` at 0x25a4 calls cmn_err with a0=0x4, a1=sym(.rodata)+144, a2=a2 at entry (arg2), a3=?.
  The `bltz` branch at 0x24b8 targets 0x2590, is taken when v0(=ret(RRM_CheckValidFault)) < 0 (signed), and falls through when v0(=ret(RRM_CheckValidFault)) >= 0 (signed).
  The `bne` branch at 0x24d4 targets 0x2598, is taken when t8(?) != 0, and falls through when t8(?) == 0.
  The `beq` branch at 0x24ec targets 0x2510, is taken when t8(=[[[a0+24]+124]+47]:1) == t9(=0x20), and falls through when t8(=[[[a0+24]+124]+47]:1) != t9(=0x20).
  The `beq` branch at 0x24f8 targets 0x2524, is taken when v0(?) == t9(=0x4), and falls through when v0(?) != t9(=0x4).
  The `beq` branch at 0x2500 targets 0x2524, is taken when v0(?) == a0(=0x10), and falls through when v0(?) != a0(=0x10).
  The `beq` branch at 0x2508 targets 0x2530 and is always taken.
  The `beq` branch at 0x2510 targets 0x2524, is taken when v0(?) == a2(=0x14), and falls through when v0(?) != a2(=0x14).
  The `beq` branch at 0x251c targets 0x2508, is taken when ra(?) == 0, and falls through when ra(?) != 0.
  The `beq` branch at 0x2590 targets 0x2574 and is always taken.
  The `beq` branch at 0x25ac targets 0x2574 and is always taken.
  The return at 0x2588 has v0 = one of -0xe, 0x0, 0x10.

- `crimeSchedRetraceEvent` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_retrace.o)` at 0x25b4 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_retrace.o)`.
  Range: 0x25b4-0x263c (136 bytes).
  It occupies 136 bytes.
  The `lw` at 0x25bc loads 4 bytes from a0 (arg0 at entry) +0x8c.
  The `lw` at 0x25e0 loads 4 bytes from [a0+140] +0x340.
  The `lw` at 0x25f4 loads 4 bytes from ?.
  The `sw` at 0x2600 stores 4 bytes to a1 (arg1 at entry) +0x24.
  The `sw` at 0x2604 stores 4 bytes to [a0+140] +0x340.
  The `jal` at 0x25d8 calls mutex_lock with a0=[a0+140]+840, a1=0x19, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x2608 calls mutex_unlock with a0=[a0+140]+840, a1=?, a2=?, a3=[[a0+140]+832].
  The `jal` at 0x262c calls mutex_unlock with a0=[a0+140]+840, a1=?, a2=?, a3=[[a0+140]+832].
  The `beq` branch at 0x25e4 targets 0x2600, is taken when a3(=[[a0+140]+832]) == 0, and falls through when a3(=[[a0+140]+832]) != 0.
  The `beq` branch at 0x25ec targets 0x262c, is taken when s0(=a1) == v0(?), and falls through when s0(=a1) != v0(?).
  The `bne` branch at 0x25f8 targets 0x25ec, is taken when v0(?) != 0, and falls through when v0(?) == 0.
  The `beq` branch at 0x2634 targets 0x2614 and is always taken.
  The return at 0x2624 has v0 = 0x0.

- `crimeRetraceCloseRN` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_retrace.o)` at 0x263c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_retrace.o)`.
  Range: 0x263c-0x277c (320 bytes).
  It occupies 320 bytes.
  The `lw` at 0x2644 loads 4 bytes from a0 (arg0 at entry) +0x8c.
  2 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x2680, `lbu` at 0x26c4.
  4 such `lw` accesses load 4 bytes from ?, including `lw` at 0x268c, `lw` at 0x26d4, `lw` at 0x2758.
  7 such `sw` accesses store 4 bytes to ?, including `sw` at 0x2698, `sw` at 0x26b4, `sw` at 0x26b8.
  6 such `sb` accesses store 1 byte to ?, including `sb` at 0x269c, `sb` at 0x26ac, `sb` at 0x26b0.
  2 such `lbu` accesses load 1 byte from [a0+140] +0x17, including `lbu` at 0x26a0, `lbu` at 0x26e8.
  2 such `sb` accesses store 1 byte to [a0+140] +0x17, including `sb` at 0x26a8, `sb` at 0x26f0.
  The `lw` at 0x2708 loads 4 bytes from [a0+140] +0x340.
  2 such `lw` accesses load 4 bytes from [[a0+140]+832] +0x24, including `lw` at 0x2714, `lw` at 0x2744.
  The `sw` at 0x2718 stores 4 bytes to [a0+140] +0x340.
  The `jal` at 0x2660 calls mutex_lock with a0=[a0+140]+840, a1=0x19, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x2724 calls mutex_unlock with a0=[a0+140]+840, a1=?, a2=?, a3=?.
  The `beq` branch at 0x266c targets 0x267c and is always taken.
  The `beq` branch at 0x2674 targets 0x2708, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0x2684 targets 0x26bc, is taken when at(?) == 0, and falls through when at(?) != 0.
  The `bne` branch at 0x2690 targets 0x26bc, is taken when v0(?) != s0(=a1), and falls through when v0(?) == s0(=a1).
  The `beq` branch at 0x26bc targets 0x2708, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0x26cc targets 0x2674, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `bne` branch at 0x26d8 targets 0x2674, is taken when a1(?) != s0(=a1), and falls through when a1(?) == s0(=a1).
  The `beq` branch at 0x2700 targets 0x2674 and is always taken.
  The `bne` branch at 0x270c targets 0x273c, is taken when a3(=[[a0+140]+832]) != s0(=a1), and falls through when a3(=[[a0+140]+832]) == s0(=a1).
  The `beq` branch at 0x273c targets 0x2720, is taken when a3(=[[a0+140]+832]) == 0, and falls through when a3(=[[a0+140]+832]) != 0.
  The `beq` branch at 0x2748 targets 0x271c, is taken when a7(=[[[a0+140]+832]+36]) == 0, and falls through when a7(=[[[a0+140]+832]+36]) != 0.
  The `beq` branch at 0x2750 targets 0x2770, is taken when s0(=a1) == a2(?), and falls through when s0(=a1) != a2(?).
  The `bne` branch at 0x2760 targets 0x2750, is taken when t0(?) != 0, and falls through when t0(?) == 0.
  The `beq` branch at 0x2768 targets 0x2720 and is always taken.
  The `beq` branch at 0x2774 targets 0x271c and is always taken.
  The return at 0x2734 has v0 = ret(mutex_unlock).

- `crmRetraceCloseAllRn` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_retrace.o)` at 0x277c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_retrace.o)`.
  Range: 0x277c-0x2820 (164 bytes).
  It occupies 164 bytes.
  The `lw` at 0x2784 loads 4 bytes from a0 (arg0 at entry) +0x8c.
  The `sb` at 0x27a8 stores 1 byte to [a0+140] +0x17.
  3 such `sb` accesses store 1 byte to ?, including `sb` at 0x27b8, `sb` at 0x27c4, `sb` at 0x27d4.
  2 such `sw` accesses store 4 bytes to ?, including `sw` at 0x27bc, `sw` at 0x27cc.
  The `sb` at 0x27d8 stores 1 byte to [a0+140] +0x1c.
  The `lw` at 0x27dc loads 4 bytes from a0 (arg0 at entry) +0x1d0.
  The `sw` at 0x27f0 stores 4 bytes to a0 (arg0 at entry) +0x1d0.
  The `jal` at 0x27a0 calls mutex_lock with a0=[a0+140]+840, a1=0x19, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x27e8 calls untimeout with a0=[a0+464], a1=0x4, a2=?, a3=?.
  The `jal` at 0x27fc calls bzero with a0=[a0+140]+836, a1=0x4, a2=?, a3=?.
  The `jal` at 0x2808 calls mutex_unlock with a0=[a0+140]+840, a1=?, a2=?, a3=?.
  The `bne` branch at 0x27d0 targets 0x27b4, is taken when a2(?) < 0x20 (signed), and falls through when a2(?) >= 0x20 (signed).
  The `beq` branch at 0x27e0 targets 0x27f8, is taken when a0(=[a0+464]) == 0, and falls through when a0(=[a0+464]) != 0.
  The return at 0x2818 has v0 = ret(mutex_unlock).

- `crimeSetDisplayMode` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_retrace.o)` at 0x2820 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_retrace.o)`.
  Range: 0x2820-0x28a0 (128 bytes).
  It occupies 128 bytes.
  The `lw` at 0x2820 loads 4 bytes from a0 (arg0 at entry) +0x18.
  The `lw` at 0x2840 loads 4 bytes from [a0+24] +0x8c.
  The `lw` at 0x284c loads 4 bytes from [a0+24] +0x80.
  The `sw` at 0x2868 stores 4 bytes to ([[a0+24]+128] + (a1 << 0x2)) +0x48000.
  The `sw` at 0x2870 stores 4 bytes to ?.
  2 such `sb` accesses store 1 byte to ?, including `sb` at 0x2878, `sb` at 0x2894.
  The `sb` at 0x289c stores 1 byte to [[a0+24]+140] +0x1c.
  The `bltz` branch at 0x282c targets 0x2888, is taken when a1 < 0 (signed), and falls through when a1 >= 0 (signed).
  The `beq` branch at 0x2834 targets 0x2888, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x2848 targets 0x2854, is taken when a5(=[sym(gbe_gammawar)]) == 0, and falls through when a5(=[sym(gbe_gammawar)]) != 0.
  The `beq` branch at 0x2874 targets 0x2890, is taken when (a2(?) & 0x3) == 0, and falls through when (a2(?) & 0x3) != 0.
  The `beq` branch at 0x2898 targets 0x287c and is always taken.
  The return at 0x2880 has v0 = 0x0.
  The return at 0x2888 has v0 = -0x16.

- `crimeSetGammaRamp` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_retrace.o)` at 0x28a0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_retrace.o)`.
  Range: 0x28a0-0x296c (204 bytes).
  It occupies 204 bytes.
  The `lw` at 0x28a0 loads 4 bytes from a0 (arg0 at entry) +0x18.
  The `lw` at 0x28ac loads 4 bytes from [a0+24] +0x80.
  9 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x28c8, `lbu` at 0x28cc, `lbu` at 0x28d4.
  2 such `sw` accesses store 4 bytes to ?, including `sw` at 0x2914, `sw` at 0x2960.
  The `beq` branch at 0x28b8 targets 0x2924, is taken when a7(=[sym(gbe_gammawar)]) == 0, and falls through when a7(=[sym(gbe_gammawar)]) != 0.
  The `bne` branch at 0x2910 targets 0x28c8, is taken when v0(?) < 0x100 (signed), and falls through when v0(?) >= 0x100 (signed).
  The `bne` branch at 0x295c targets 0x292c, is taken when v0(?) < 0x100 (signed), and falls through when v0(?) >= 0x100 (signed).
  The return at 0x291c has v0 = 0x0.
  The return at 0x2964 has v0 = 0x0.

- `crmFindFreeDidTbl` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_retrace.o)` at 0x296c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_retrace.o)`.
  Range: 0x296c-0x2a64 (248 bytes).
  It occupies 248 bytes.
  The `lw` at 0x296c loads 4 bytes from a0 (arg0 at entry) +0x8c.
  The `lw` at 0x2978 loads 4 bytes from a0 (arg0 at entry) +0x84.
  3 such `lw` accesses load 4 bytes from ?, including `lw` at 0x2994, `lw` at 0x2a00, `lw` at 0x2a14.
  The `sw` at 0x2a58 stores 4 bytes to ?.
  The `jal` at 0x29b4 calls mutex_lock with a0=[a0+140]+840, a1=0x19, a2=a2 at entry (arg2), a3=?.
  The `jal` at 0x2a30 calls mutex_unlock with a0=[a0+140]+840, a1=?, a2=?, a3=?, a6=0x2.
  The `jal` at 0x2a54 calls mutex_unlock with a0=[a0+140]+840, a1=?, a2=?, a3=?, a6=0x2.
  The `beq` branch at 0x2998 targets 0x29d4, is taken when t8(?) == 0, and falls through when t8(?) != 0.
  The `bne` branch at 0x29a8 targets 0x2994, is taken when s0(?) < 0x3 (signed), and falls through when s0(?) >= 0x3 (signed).
  The `beq` branch at 0x29cc targets 0x2a00 and is always taken.
  The `beq` branch at 0x29f8 targets 0x2a40, is taken when s0(?) >= 0x3 (signed), and falls through when s0(?) < 0x3 (signed).
  The `beq` branch at 0x2a04 targets 0x2a30, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0x2a0c targets 0x29f0, is taken when a4(?) == a6(=0x2), and falls through when a4(?) != a6(=0x2).
  The `beq` branch at 0x2a1c targets 0x29f0, is taken when a4(?) >= a5(?) (unsigned), and falls through when a4(?) < a5(?) (unsigned).
  The `beq` branch at 0x2a28 targets 0x29f0 and is always taken.
  The `beq` branch at 0x2a38 targets 0x29d8 and is always taken.
  The `beq` branch at 0x2a5c targets 0x29d4 and is always taken.
  The return at 0x29e8 has v0 = ?.

- `crime_hli_handler` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_retrace.o)` at 0x2a64 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_retrace.o)`.
  Range: 0x2a64-0x2c70 (524 bytes).
  It occupies 524 bytes.
  The `lw` at 0x2a6c loads 4 bytes from a0 (arg0 at entry) +0x8c.
  2 such `lw` accesses load 4 bytes from ([a0+140] + (a1 << 0x2)) +0x32c, including `lw` at 0x2a80, `lw` at 0x2aec.
  8 such `lw` accesses load 4 bytes from ?, including `lw` at 0x2aa4, `lw` at 0x2aa8, `lw` at 0x2ab4.
  The `lw` at 0x2acc loads 4 bytes from [a0+140] +0x33c.
  The `sw` at 0x2af0 stores 4 bytes to ([a0+140] + (a1 << 0x2)) +0x32c.
  The `lw` at 0x2af8 loads 4 bytes from [[a0+140]+828] +0xc.
  The `lw` at 0x2b04 loads 4 bytes from [[a0+140]+828] +0x14.
  2 such `sw` accesses store 4 bytes to ?, including `sw` at 0x2b3c, `sw` at 0x2b60.
  2 such `sw` accesses store 4 bytes to [a0+140] +0x33c, including `sw` at 0x2b40, `sw` at 0x2c00.
  The `ld` at 0x2b68 loads 8 bytes from abs 0xffffffffb4000028.
  The `sd` at 0x2bb0 stores 8 bytes to abs 0xffffffffb4000028.
  2 such `lw` accesses load 4 bytes from [a0+140] +0x328, including `lw` at 0x2bc8, `lw` at 0x2c04.
  2 such `sw` accesses store 4 bytes to [a0+140] +0x328, including `sw` at 0x2be0, `sw` at 0x2c1c.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x80, including `lw` at 0x2be8, `lw` at 0x2c20.
  2 such `sw` accesses store 4 bytes to [a0+128] +0x10024, including `sw` at 0x2bf8, `sw` at 0x2c34.
  The `jalr` at 0x2aa0 calls (unknown callee) with a0=?, a1=?, a2=?, a3=?.
  The `bne` branch at 0x2a90 targets 0x2ab4, is taken when s0(=[([a0+140] + (a1 << 0x2))+812]) != 0, and falls through when s0(=[([a0+140] + (a1 << 0x2))+812]) == 0.
  The `beq` branch at 0x2a98 targets 0x2acc and is always taken.
  The `beq` branch at 0x2aac targets 0x2acc, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `bne` branch at 0x2ab8 targets 0x2aa0, is taken when a3(?) != 0, and falls through when a3(?) == 0.
  The `bne` branch at 0x2ac4 targets 0x2ab4, is taken when s0(?) != 0, and falls through when s0(?) == 0.
  The `beq` branch at 0x2ae4 targets 0x2b64, is taken when a1(=[[a0+140]+828]) == 0, and falls through when a1(=[[a0+140]+828]) != 0.
  The `beq` branch at 0x2af4 targets 0x2bc4, is taken when s1(=a1) == a7(=0x2), and falls through when s1(=a1) != a7(=0x2).
  The `beq` branch at 0x2afc targets 0x2c04, is taken when s1(=a1) == t0(=0x3), and falls through when s1(=a1) != t0(=0x3).
  The `beq` branch at 0x2b0c targets 0x2bfc, is taken when s0(=[[[a0+140]+828]+20]) == 0, and falls through when s0(=[[[a0+140]+828]+20]) != 0.
  The `beq` branch at 0x2b1c targets 0x2b3c, is taken when t9(?) >= a0(=[[[a0+140]+828]+12]+3) (unsigned), and falls through when t9(?) < a0(=[[[a0+140]+828]+12]+3) (unsigned).
  The `bne` branch at 0x2b2c targets 0x2b14, is taken when ra(?) != 0, and falls through when ra(?) == 0.
  The `beq` branch at 0x2b34 targets 0x2b68 and is always taken.
  The `beq` branch at 0x2b48 targets 0x2b60, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `bne` branch at 0x2b58 targets 0x2b50, is taken when a0(?) != 0, and falls through when a0(?) == 0.
  The `beq` branch at 0x2b74 targets 0x2c38, is taken when s1(=a1) == 0, and falls through when s1(=a1) != 0.
  The `beq` branch at 0x2b7c targets 0x2c4c, is taken when s1(=a1) == a5(=0x1), and falls through when s1(=a1) != a5(=0x1).
  The `beq` branch at 0x2b84 targets 0x2c60, is taken when s1(=a1) == a1(=0x2), and falls through when s1(=a1) != a1(=0x2).
  The `beq` branch at 0x2b90 targets 0x2bb4, is taken when s1(=a1) == a1(=0x3), and falls through when s1(=a1) != a1(=0x3).
  The `beq` branch at 0x2bbc targets 0x2b98 and is always taken.
  The `beq` branch at 0x2bf4 targets 0x2b04 and is always taken.
  The `beq` branch at 0x2bfc targets 0x2b64 and is always taken.
  The `beq` branch at 0x2c30 targets 0x2b04 and is always taken.
  The `beq` branch at 0x2c44 targets 0x2b98 and is always taken.
  The `beq` branch at 0x2c58 targets 0x2b98 and is always taken.
  The `beq` branch at 0x2c68 targets 0x2b98 and is always taken.
  The return at 0x2bac has v0 = ?.

- `crime_hli_handler` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_retrace.o)` at 0x2a64 (n32).
  Inferred: it is a CRIME interrupt handler that works on one table slot of the structure at a0,
  since it reads and writes the CRIME Hardware Interrupt register at +0x28 (linked row) and walks
  record lists held in that structure. The entry argument a1 indexes the table that the pointer at
  a0+0x8c points to, and the word at +0x32c from the indexed slot (`lw` at 0x2a80, tested at 0x2a90)
  starts a record list that the walk follows through +0x14 (`lw` at 0x2aa8 and 0x2ac0). For each
  record whose +0x4 word is nonzero (`bne` at 0x2ab8), the walk calls through that word with the
  record's +0x8 word as a0 (`jalr` at 0x2aa0). When the word at +0x33c of the structure is nonzero,
  the slot's list head at +0x32c is replaced by it (`sw` at 0x2af0), the entry argument kept in s1
  is tested against 2 and 3 (0x2af4 and 0x2afc), a second list walk runs, and a word is written to
  +0x33c (`sw` at 0x2b40 and 0x2c00). For entry argument 2 the word at +0x328 of the structure is
  rewritten (`lw` at 0x2bc8, `sw` at 0x2be0) with its bits kept under the 8-byte constant at `.lit8`
  +0x8 (`ld` at 0x2bc4) and the low 0xfff bits of the record's +0xc word (at 0x2bcc) shifted left by
  0xc ORed in. For entry argument 3 the same word is rewritten (`sw` at 0x2c1c) with its low 0xfff
  bits replaced by that field, the rest kept by the mask -0x1000 (at 0x2c08). In both cases the new
  word is also written to 0x10024 past the pointer at a0+0x80 (`sw` at 0x2bf8 and 0x2c34). On every
  path that reaches 0x2b68 the routine loads the 8-byte Hardware Interrupt register at +0x28 into
  a0, then clears one bit of it chosen by the entry argument, one of four consecutive bits starting
  at bit sixteen: it ANDs the word with a mask whose upper half is 0xfffe for argument 0 (at
  0x2c38), 0xfffd for 1 (0x2c4c), 0xfffb for 2 (0x2b88) or 0xfff7 for 3 (0x2b94) and whose lower
  half is 0xffff; the `beq` tests at 0x2b74, 0x2b7c, 0x2b84 and 0x2b90 pick the case, and any other
  argument leaves the word as loaded. The low 32 bits of the result are written back to the Hardware
  Interrupt word in the delay slot of the common return at 0x2bac (`sd` at 0x2bb0).
  Unknown: which device the word at a0+0x80 plus 0x10024 belongs to, since the stores at 0x2bf8 and
  0x2c34 address it through a pointer the bundle does not follow; the route is the reviewed Hardware
  Interrupt field table.
  Unknown: the targets of the call at 0x2aa0, which are whatever the +0x4 words of the records hold.
  Evidence grade: inferred.

- `crime_schedule_hli` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_retrace.o)` at 0x2c70 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_retrace.o)`.
  Range: 0x2c70-0x2e1c (428 bytes).
  It occupies 428 bytes.
  The `lw` at 0x2c74 loads 4 bytes from a0 (arg0 at entry) +0x8c.
  11 such `lw` accesses load 4 bytes from ?, including `lw` at 0x2c90, `lw` at 0x2c9c, `lw` at 0x2cc4.
  3 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0xc, including `lw` at 0x2ca0, `lw` at 0x2da0, `lw` at 0x2de0.
  2 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x10, including `lw` at 0x2cd0, `lw` at 0x2d04.
  6 such `sw` accesses store 4 bytes to ?, including `sw` at 0x2ce0, `sw` at 0x2d44, `sw` at 0x2d84.
  The `lw` at 0x2cf4 loads 4 bytes from [a0+140] +0x33c.
  The `lw` at 0x2cf8 loads 4 bytes from [[a0+140]+828] +0x14.
  2 such `sw` accesses store 4 bytes to a1 (arg1 at entry) +0x14, including `sw` at 0x2d4c, `sw` at 0x2d8c.
  2 such `lw` accesses load 4 bytes from [a0+140] +0x328, including `lw` at 0x2da4, `lw` at 0x2de4.
  2 such `sw` accesses store 4 bytes to [a0+140] +0x328, including `sw` at 0x2db8, `sw` at 0x2df8.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x80, including `lw` at 0x2dbc, `lw` at 0x2dfc.
  2 such `sw` accesses store 4 bytes to [a0+128] +0x10024, including `sw` at 0x2dd0, `sw` at 0x2e10.
  The `sw` at 0x2dd8 stores 4 bytes to [a0+140] +0x33c.
  The `beq` branch at 0x2c80 targets 0x2c90 and is always taken.
  The `beq` branch at 0x2c88 targets 0x2cf4, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `beq` branch at 0x2c94 targets 0x2cdc, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `bne` branch at 0x2cb4 targets 0x2c88, is taken when t0(=[a1+12]) < a7(?) (unsigned), and falls through when t0(=[a1+12]) >= a7(?) (unsigned).
  The `beq` branch at 0x2cbc targets 0x2c88, is taken when a7(?) == 0, and falls through when a7(?) != 0.
  The `beq` branch at 0x2cc8 targets 0x2d98, is taken when t1(?) == 0, and falls through when t1(?) != 0.
  The `beq` branch at 0x2cd4 targets 0x2d64 and is always taken.
  The `beq` branch at 0x2cdc targets 0x2ddc, is taken when t3(=0x2) == a4(?), and falls through when t3(=0x2) != a4(?).
  The `beq` branch at 0x2ce4 targets 0x2da0, is taken when a4(?) == t2(=0x3), and falls through when a4(?) != t2(=0x3).
  The `beq` branch at 0x2cfc targets 0x2d90, is taken when a6(=[[[a0+140]+828]+20]) == 0, and falls through when a6(=[[[a0+140]+828]+20]) != 0.
  The `beq` branch at 0x2d08 targets 0x2d24 and is always taken.
  The `beq` branch at 0x2d1c targets 0x2d90, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `beq` branch at 0x2d34 targets 0x2d10, is taken when a4(=([a1+12] + [a1+16])) >= a7(?) (unsigned), and falls through when a4(=([a1+12] + [a1+16])) < a7(?) (unsigned).
  The `beq` branch at 0x2d3c targets 0x2dd4, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x2d5c targets 0x2d98, is taken when t1(?) == 0, and falls through when t1(?) != 0.
  The `beq` branch at 0x2d74 targets 0x2d50, is taken when a4(=([a1+12] + [a1+16])) >= t2(?) (unsigned), and falls through when a4(=([a1+12] + [a1+16])) < t2(?) (unsigned).
  The `beq` branch at 0x2d7c targets 0x2e14, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x2dd4 targets 0x2d48 and is always taken.
  The `beq` branch at 0x2e14 targets 0x2d88 and is always taken.
  The return at 0x2cec has v0 = ?.
  The return at 0x2d48 has v0 = ?.
  The return at 0x2d88 has v0 = ?.
  The return at 0x2d90 has v0 = ?.
  The return at 0x2d98 has v0 = ?.
  The return at 0x2dcc has v0 = ?.
  The return at 0x2e0c has v0 = [a0+128].

- `crime_hli_sched` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_retrace.o)` at 0x2e1c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_retrace.o)`.
  Range: 0x2e1c-0x2ee0 (196 bytes).
  It occupies 196 bytes.
  The `lw` at 0x2e4c loads 4 bytes from (sym(crimeBoards) + (a0 << 0x6)) +0xc.
  The `lw` at 0x2e5c loads 4 bytes from [(sym(crimeBoards) + (a0 << 0x6))+12] +0x8c.
  The `lw` at 0x2e78 loads 4 bytes from [[(sym(crimeBoards) + (a0 << 0x6))+12]+140] +0x324.
  The `sw` at 0x2e84 stores 4 bytes to [[(sym(crimeBoards) + (a0 << 0x6))+12]+140] +0x324.
  The `sw` at 0x2e88 stores 4 bytes to ret(kern_malloc) +0x8.
  The `sw` at 0x2e94 stores 4 bytes to ret(kern_malloc) +0x4.
  2 such `sw` accesses store 4 bytes to ret(kern_malloc) +0xc, including `sw` at 0x2e9c, `sw` at 0x2edc.
  The `sw` at 0x2ea8 stores 4 bytes to ret(kern_malloc) +0x0.
  The `sw` at 0x2eb4 stores 4 bytes to ret(kern_malloc) +0x10.
  The `sw` at 0x2eb8 stores 4 bytes to ret(kern_malloc) +0x14.
  The `lw` at 0x2ec8 loads 4 bytes from ret(kern_malloc) +0x0.
  The `jal` at 0x2e64 calls kern_malloc with a0=0x18, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x2ebc calls crime_schedule_hli with a0=[(sym(crimeBoards) + (a0 << 0x6))+12], a1=ret(kern_malloc), a2=a4 at entry (arg4), a3=a5 at entry (arg5), a4=0x1.
  The `beq` branch at 0x2ea4 targets 0x2ed8, is taken when a3(=a5) == a4(=0x1), and falls through when a3(=a5) != a4(=0x1).
  The `beq` branch at 0x2ed8 targets 0x2eac and is always taken.
  The return at 0x2ed0 has v0 = [ret(kern_malloc)].

- `crime_hli_unsched` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_retrace.o)` at 0x2ee0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_retrace.o)`.
  Range: 0x2ee0-0x3048 (360 bytes).
  It occupies 360 bytes.
  The `lw` at 0x2ef0 loads 4 bytes from (sym(crimeBoards) + (a0 << 0x6)) +0xc.
  The `lw` at 0x2ef8 loads 4 bytes from [(sym(crimeBoards) + (a0 << 0x6))+12] +0x8c.
  The `lw` at 0x2f04 loads 4 bytes from (sym(crimeBoards) + (a0 << 0x6)) +0x4.
  10 such `lw` accesses load 4 bytes from ?, including `lw` at 0x2f10, `lw` at 0x2f24, `lw` at 0x2f28.
  3 such `sw` accesses store 4 bytes to ?, including `sw` at 0x2f4c, `sw` at 0x2f98, `sw` at 0x3024.
  The `lw` at 0x2f78 loads 4 bytes from [[(sym(crimeBoards) + (a0 << 0x6))+12]+140] +0x33c.
  The `lw` at 0x2f84 loads 4 bytes from [[[(sym(crimeBoards) + (a0 << 0x6))+12]+140]+828] +0x14.
  2 such `lw` accesses load 4 bytes from [[(sym(crimeBoards) + (a0 << 0x6))+12]+140] +0x328, including `lw` at 0x2fb8, `lw` at 0x2fdc.
  2 such `sw` accesses store 4 bytes to [[(sym(crimeBoards) + (a0 << 0x6))+12]+140] +0x328, including `sw` at 0x2fc8, `sw` at 0x2ff0.
  2 such `sw` accesses store 4 bytes to [(sym(crimeBoards) + (a0 << 0x6))+4] +0x10024, including `sw` at 0x2fd4, `sw` at 0x2ff8.
  The `sw` at 0x3044 stores 4 bytes to [[(sym(crimeBoards) + (a0 << 0x6))+12]+140] +0x33c.
  The `jal` at 0x2f50 calls kern_free with a0=?, a1=?, a2=?, a3=a3 at entry (arg3), a6=[[(sym(crimeBoards) + (a0 << 0x6))+12]+140], a7=[(sym(crimeBoards) + (a0 << 0x6))+4].
  The `jal` at 0x3028 calls kern_free with a0=?, a1=?, a2=?, a3=?, a6=[[(sym(crimeBoards) + (a0 << 0x6))+12]+140], a7=[(sym(crimeBoards) + (a0 << 0x6))+4].
  The `beq` branch at 0x2f18 targets 0x2f68, is taken when t1(?) == 0, and falls through when t1(?) != 0.
  The `beq` branch at 0x2f20 targets 0x2f3c and is always taken.
  The `beq` branch at 0x2f30 targets 0x2f68, is taken when t2(?) == 0, and falls through when t2(?) != 0.
  The `bne` branch at 0x2f3c targets 0x2f28, is taken when t3(?) != a1, and falls through when t3(?) == a1.
  The `beq` branch at 0x2f44 targets 0x2f98, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `bne` branch at 0x2f70 targets 0x2f10, is taken when a5(?) < 0x4 (unsigned), and falls through when a5(?) >= 0x4 (unsigned).
  The `beq` branch at 0x2f7c targets 0x3038, is taken when a0(=[[[(sym(crimeBoards) + (a0 << 0x6))+12]+140]+828]) == 0, and falls through when a0(=[[[(sym(crimeBoards) + (a0 << 0x6))+12]+140]+828]) != 0.
  The `beq` branch at 0x2f88 targets 0x3038, is taken when t9(=[[[[(sym(crimeBoards) + (a0 << 0x6))+12]+140]+828]+20]) == 0, and falls through when t9(=[[[[(sym(crimeBoards) + (a0 << 0x6))+12]+140]+828]+20]) != 0.
  The `beq` branch at 0x2f90 targets 0x3010 and is always taken.
  The `bne` branch at 0x2fa0 targets 0x2f50, is taken when ra(?) != 0, and falls through when ra(?) == 0.
  The `beq` branch at 0x2fa8 targets 0x2fd8, is taken when t0(=0x2) == a5(?), and falls through when t0(=0x2) != a5(?).
  The `bne` branch at 0x2fb0 targets 0x2f50, is taken when a5(?) != v0(=0x3), and falls through when a5(?) == v0(=0x3).
  The `beq` branch at 0x2fd0 targets 0x2f50 and is always taken.
  The `beq` branch at 0x2ff4 targets 0x2f50 and is always taken.
  The `beq` branch at 0x3008 targets 0x3038, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `bne` branch at 0x3014 targets 0x2ffc, is taken when a3(?) != a1, and falls through when a3(?) == a1.
  The `beq` branch at 0x301c targets 0x3040, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x3030 targets 0x2f5c and is always taken.
  The `beq` branch at 0x3038 targets 0x2f5c and is always taken.
  The `beq` branch at 0x3040 targets 0x3028 and is always taken.
  The return at 0x2f60 has v0 = one of 0x0, 0x6.

- `crime_hli_update` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_retrace.o)` at 0x3048 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_retrace.o)`.
  Range: 0x3048-0x316c (292 bytes).
  It occupies 292 bytes.
  The `lw` at 0x3058 loads 4 bytes from (sym(crimeBoards) + (a0 << 0x6)) +0xc.
  The `lw` at 0x305c loads 4 bytes from [(sym(crimeBoards) + (a0 << 0x6))+12] +0x8c.
  11 such `lw` accesses load 4 bytes from ?, including `lw` at 0x3074, `lw` at 0x3080, `lw` at 0x3090.
  7 such `sw` accesses store 4 bytes to ?, including `sw` at 0x30bc, `sw` at 0x30c0, `sw` at 0x30c4.
  The `lw` at 0x30f0 loads 4 bytes from [[(sym(crimeBoards) + (a0 << 0x6))+12]+140] +0x33c.
  The `lw` at 0x30fc loads 4 bytes from [[[(sym(crimeBoards) + (a0 << 0x6))+12]+140]+828] +0x14.
  The `sw` at 0x3168 stores 4 bytes to [[(sym(crimeBoards) + (a0 << 0x6))+12]+140] +0x33c.
  The `jal` at 0x30c8 calls crime_schedule_hli with a0=[(sym(crimeBoards) + (a0 << 0x6))+12], a1=?, a2=a2 at entry (arg2), a3=a3 at entry (arg3), a7=a1 at entry (arg1).
  The `jal` at 0x314c calls crime_schedule_hli with a0=[(sym(crimeBoards) + (a0 << 0x6))+12], a1=?, a2=a2 at entry (arg2), a3=a3 at entry (arg3), a7=a1 at entry (arg1).
  The `beq` branch at 0x3078 targets 0x30e0, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x3084 targets 0x30e0, is taken when t3(?) == 0, and falls through when t3(?) != 0.
  The `beq` branch at 0x308c targets 0x30ac and is always taken.
  The `beq` branch at 0x30a0 targets 0x30e0, is taken when t8(?) == 0, and falls through when t8(?) != 0.
  The `bne` branch at 0x30ac targets 0x3094, is taken when t9(?) != a7(=a1), and falls through when t9(?) == a7(=a1).
  The `beq` branch at 0x30b4 targets 0x3110, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `bne` branch at 0x30e8 targets 0x3074, is taken when t0(?) < 0x4 (unsigned), and falls through when t0(?) >= 0x4 (unsigned).
  The `beq` branch at 0x30f4 targets 0x315c, is taken when a1(=[[[(sym(crimeBoards) + (a0 << 0x6))+12]+140]+828]) == 0, and falls through when a1(=[[[(sym(crimeBoards) + (a0 << 0x6))+12]+140]+828]) != 0.
  The `beq` branch at 0x3100 targets 0x315c, is taken when at(=[[[[(sym(crimeBoards) + (a0 << 0x6))+12]+140]+828]+20]) == 0, and falls through when at(=[[[[(sym(crimeBoards) + (a0 << 0x6))+12]+140]+828]+20]) != 0.
  The `beq` branch at 0x3108 targets 0x312c and is always taken.
  The `beq` branch at 0x3110 targets 0x30c0 and is always taken.
  The `beq` branch at 0x3124 targets 0x315c, is taken when v1(?) == 0, and falls through when v1(?) != 0.
  The `bne` branch at 0x3130 targets 0x3118, is taken when a0(?) != a7(=a1), and falls through when a0(?) == a7(=a1).
  The `beq` branch at 0x3138 targets 0x3164, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x3154 targets 0x30d4 and is always taken.
  The `beq` branch at 0x315c targets 0x30d4 and is always taken.
  The `beq` branch at 0x3164 targets 0x3144 and is always taken.
  The return at 0x30d8 has v0 = one of 0x0, 0x6.

- `crm_getustmsc` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_retrace.o)` at 0x316c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_retrace.o)`.
  Range: 0x316c-0x3274 (264 bytes).
  It occupies 264 bytes.
  The `lw` at 0x316c loads 4 bytes from a2 (arg2 at entry) +0xc.
  The `sh` at 0x3198 stores 2 bytes to a3 (arg3 at entry) +0x14.
  The `lw` at 0x319c loads 4 bytes from a2 (arg2 at entry) +0x4.
  The `sw` at 0x31a0 stores 4 bytes to a3 (arg3 at entry) +0x10.
  The `lh` at 0x31a4 loads 2 bytes from a2 (arg2 at entry) +0x1e.
  The `sh` at 0x31a8 stores 2 bytes to a3 (arg3 at entry) +0x16.
  The `ld` at 0x31ac loads 8 bytes from a1 (arg1 at entry) +0x0.
  The `sd` at 0x31b8 stores 8 bytes to a3 (arg3 at entry) +0x8.
  The `lw` at 0x31d4 loads 4 bytes from a0 (arg0 at entry) +0x10000.
  2 such `sh` accesses store 2 bytes to a3 (arg3 at entry) +0x18, including `sh` at 0x31e8, `sh` at 0x3264.
  The `lh` at 0x31f0 loads 2 bytes from a3 (arg3 at entry) +0x18.
  2 such `lh` accesses load 2 bytes from a2 (arg2 at entry) +0x24, including `lh` at 0x31f4, `lh` at 0x325c.
  The `lh` at 0x31f8 loads 2 bytes from a2 (arg2 at entry) +0x14.
  The `lh` at 0x3204 loads 2 bytes from a2 (arg2 at entry) +0x2c.
  The `lh` at 0x3208 loads 2 bytes from a2 (arg2 at entry) +0x2a.
  The `lh` at 0x3234 loads 2 bytes from a2 (arg2 at entry) +0x28.
  The `ld` at 0x3248 loads 8 bytes from a3 (arg3 at entry) +0x0.
  The `sd` at 0x3258 stores 8 bytes to a3 (arg3 at entry) +0x0.
  The `jal` at 0x31b4 calls splprof with a0=?, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a4=[a2+12]+500, a5=0x3e8.
  The `jal` at 0x31bc calls update_ust with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x31c4 calls get_ust_nano with a0=a3 at entry (arg3), a1=?, a2=?, a3=?.
  The `jal` at 0x31e4 calls splx with a0=ret(splprof), a1=?, a2=?, a3=?.
  The return at 0x326c has v0 = ?.

- `crimeFrameInfo` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_retrace.o)` at 0x32b8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_retrace.o)`.
  Range: 0x32b8-0x3380 (200 bytes).
  It occupies 200 bytes.
  The `lw` at 0x32c0 loads 4 bytes from a0 (arg0 at entry) +0x8c.
  2 such `sb` accesses store 1 byte to a2 (arg2 at entry) +0x1a, including `sb` at 0x32c4, `sb` at 0x337c.
  2 such `sb` accesses store 1 byte to a2 (arg2 at entry) +0x1b, including `sb` at 0x32c8, `sb` at 0x332c.
  The `lw` at 0x3308 loads 4 bytes from ?.
  The `lw` at 0x331c loads 4 bytes from a1 (arg1 at entry) +0x4c.
  The `lbu` at 0x3328 loads 1 byte from [a1+76] +0x550.
  The `lw` at 0x3334 loads 4 bytes from a0 (arg0 at entry) +0x7c.
  The `lw` at 0x3338 loads 4 bytes from a0 (arg0 at entry) +0x80.
  The `lw` at 0x3348 loads 4 bytes from [a0+124] +0x30.
  The `lbu` at 0x336c loads 1 byte from ?.
  The `jal` at 0x32f0 calls mutex_lock with a0=[a0+140]+840, a1=0x19, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x3344 calls crm_getustmsc with a0=[a0+128], a1=[a0+140], a2=[[a0+124]+48], a3=a2 at entry (arg2).
  The `jal` at 0x3358 calls mutex_unlock with a0=[a0+140]+840, a1=?, a2=?, a3=?.
  The `beq` branch at 0x330c targets 0x336c, is taken when at(?) == s0(=a1), and falls through when at(?) != s0(=a1).
  The `bne` branch at 0x3314 targets 0x3304, is taken when a7(?) != 0, and falls through when a7(?) == 0.
  The `beq` branch at 0x3320 targets 0x3334, is taken when a1(=[a1+76]) == 0, and falls through when a1(=[a1+76]) != 0.
  The `beq` branch at 0x3370 targets 0x331c, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0x3378 targets 0x331c and is always taken.
  The return at 0x3364 has v0 = ret(mutex_unlock).
