# Readings: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`

One entry per routine, filed here from the reading batches by binary.

- `gbe_too_late` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x0-0x34 (52 bytes).
  It occupies 52 bytes.
  The `lw` at 0x4 loads 4 bytes from abs 0xffffffffb6010000.
  The `bltz` branch at 0x10 targets 0x28, is taken when v0(?) < 0 (signed), and falls through when v0(?) >= 0 (signed).
  The `beq` branch at 0x18 targets 0x2c, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The return at 0x20 has v0 = 0x1.
  The return at 0x2c has v0 = 0x0.

- `mvptransfer_too_many_errors` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x34 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x34-0xb4 (128 bytes).
  It occupies 128 bytes.
  The `lbu` at 0x34 loads 1 byte from a0 (arg0 at entry) +0x46c.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x600, including `lw` at 0x3c, `lw` at 0x74.
  The `sw` at 0x54 stores 4 bytes to a0 (arg0 at entry) +0x600.
  The `lw` at 0x5c loads 4 bytes from table(sym(mvptransfer_stats)) +0x28.
  The `sw` at 0x64 stores 4 bytes to table(sym(mvptransfer_stats)) +0x28.
  The `lw` at 0x68 loads 4 bytes from a0 (arg0 at entry) +0x604.
  The `lw` at 0x94 loads 4 bytes from a0 (arg0 at entry) +0x48c.
  The `sw` at 0xa4 stores 4 bytes to a0 (arg0 at entry) +0x48c.
  The `jalr` at 0xa0 calls mvptransfer_stop with a0=a0 at entry (arg0), a1=?, a2=[a0+1132]:1, a3=?, a4=([a0+1164] | 0x1000), a5=sym(mvptransfer_stop).
  The `beq` branch at 0x6c targets 0x84, is taken when v0(=[a0+1540]) == 0, and falls through when v0(=[a0+1540]) != 0.
  The `beq` branch at 0x7c targets 0x90, is taken when a3(=[a0+1536]) >= v0(=[a0+1540]) (unsigned), and falls through when a3(=[a0+1536]) < v0(=[a0+1540]) (unsigned).
  The `beq` branch at 0xac targets 0x88 and is always taken.
  The return at 0x88 has v0 = one of 0x0, 0x1.

- `mvptransfer_datacount` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0xb4 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0xb4-0x15c (168 bytes).
  It occupies 168 bytes.
  3 such `lw` accesses load 4 bytes from ?, including `lw` at 0xd0, `lw` at 0x118, `lw` at 0x124.
  The `beq` branch at 0xc0 targets 0x138, is taken when a1 >= a2 (signed), and falls through when a1 < a2 (signed).
  The `beq` branch at 0xc8 targets 0x140 and is always taken.
  The `beq` branch at 0xec targets 0x138, is taken when a1(?) >= a2 (signed), and falls through when a1(?) < a2 (signed).
  The `bne` branch at 0x11c targets 0xd8, is taken when a7(=0x2) != a4(?), and falls through when a7(=0x2) == a4(?).
  The `bne` branch at 0x128 targets 0xd0, is taken when t1(?) != 0, and falls through when t1(?) == 0.
  The `beq` branch at 0x130 targets 0xdc and is always taken.
  The `beq` branch at 0x154 targets 0xf8 and is always taken.
  The return at 0x138 has v0 = one of 0x0, ?.

- `mvptransfer_update_path_controls` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x15c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x15c-0x190 (52 bytes).
  It occupies 52 bytes.
  The `jalr` at 0x178 calls bcopy with a0=a1+336, a1=a0+2984, a2=0x78, a3=a3 at entry (arg3).
  The return at 0x188 has v0 = 0x0.

- `mvptransfer_send_changed` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x190 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x190-0x250 (192 bytes).
  It occupies 192 bytes.
  The `lw` at 0x190 loads 4 bytes from a1 (arg1 at entry) +0x148.
  The `lw` at 0x194 loads 4 bytes from a1 (arg1 at entry) +0x13c.
  The `lw` at 0x198 loads 4 bytes from a1 (arg1 at entry) +0x140.
  The `lw` at 0x1a0 loads 4 bytes from a1 (arg1 at entry) +0x144.
  The `sw` at 0x1a8 stores 4 bytes to a1 (arg1 at entry) +0xbc.
  The `sw` at 0x1b0 stores 4 bytes to a1 (arg1 at entry) +0xd8.
  The `sw` at 0x1b4 stores 4 bytes to a1 (arg1 at entry) +0xc0.
  The `sw` at 0x1bc stores 4 bytes to a1 (arg1 at entry) +0xb8.
  The `sw` at 0x1c4 stores 4 bytes to a1 (arg1 at entry) +0xb4.
  The `ld` at 0x1c8 loads 8 bytes from a0 (arg0 at entry) +0x5a8.
  The `sd` at 0x1cc stores 8 bytes to a1 (arg1 at entry) +0xc8.
  The `ld` at 0x1d0 loads 8 bytes from a0 (arg0 at entry) +0x5b0.
  2 such `sd` accesses store 8 bytes to a1 (arg1 at entry) +0xd0, including `sd` at 0x1d4, `sd` at 0x200.
  The `lbu` at 0x1d8 loads 1 byte from a0 (arg0 at entry) +0x47d.
  The `sw` at 0x204 stores 4 bytes to a1 (arg1 at entry) +0x13c.
  The `sw` at 0x20c stores 4 bytes to a1 (arg1 at entry) +0x130.
  The `sh` at 0x214 stores 2 bytes to a1 (arg1 at entry) +0x138.
  The `sw` at 0x21c stores 4 bytes to a1 (arg1 at entry) +0x140.
  The `sw` at 0x224 stores 4 bytes to a1 (arg1 at entry) +0x144.
  The `sw` at 0x234 stores 4 bytes to a1 (arg1 at entry) +0x148.
  The `lw` at 0x240 loads 4 bytes from a0 (arg0 at entry) +0x578.
  The `jalr` at 0x23c calls dms_fifo_enq with a0=[a0+1400], a1=a1+176, a2=0x1, a3=a1 at entry (arg1), a4=[a1+328], a5=a0 at entry (arg0), a7=[a0+1456]:8.
  The `beq` branch at 0x1f8 targets 0x204, is taken when at(=[a0+1149]:1) == 0, and falls through when at(=[a0+1149]:1) != 0.
  The return at 0x248 has v0 = ret(dms_fifo_enq).

- `mvptransfer_nextiep` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x250 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x250-0x3b8 (360 bytes).
  It occupies 360 bytes.
  The `lbu` at 0x284 loads 1 byte from a0 (arg0 at entry) +0xbaa.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x5ec, including `lw` at 0x290, `lw` at 0x394.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x5e4, including `lw` at 0x294, `lw` at 0x39c.
  The `lw` at 0x2ac loads 4 bytes from ?.
  3 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x5e4, including `sw` at 0x2c0, `sw` at 0x350, `sw` at 0x354.
  The `lbu` at 0x358 loads 1 byte from ?.
  The `sb` at 0x38c stores 1 byte to ?.
  The `jalr` at 0x310 calls mvpreg_syncpath_controls with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?, a5=[a0+1516], a6=0xa, a7=0x2.
  The `jalr` at 0x370 calls .text+348 with a0=a0 at entry (arg0), a1=?, a2=?, a3=?, a5=[a0+1516], a6=0xa, a7=0x2.
  The `beq` branch at 0x27c targets 0x290, is taken when a1 == a7(=0x2), and falls through when a1 != a7(=0x2).
  The `bne` branch at 0x288 targets 0x32c, is taken when a1 != at(=[a0+2986]:1), and falls through when a1 == at(=[a0+2986]:1).
  The `beq` branch at 0x29c targets 0x328, is taken when v0(=[a0+1508]) >= a5(=[a0+1516]) (unsigned), and falls through when v0(=[a0+1508]) < a5(=[a0+1516]) (unsigned).
  The `beq` branch at 0x2a4 targets 0x3a8 and is always taken.
  The `beq` branch at 0x2b0 targets 0x354, is taken when a6(=0xa) == a2(?), and falls through when a6(=0xa) != a2(?).
  The `beq` branch at 0x2b8 targets 0x348, is taken when a7(=0x2) == a2(?), and falls through when a7(=0x2) != a2(?).
  The `beq` branch at 0x2d0 targets 0x300, is taken when v0(?) >= a5(=[a0+1516]) (unsigned), and falls through when v0(?) < a5(=[a0+1516]) (unsigned).
  The `beq` branch at 0x2f0 targets 0x2ac, is taken when s2(=a2) == 0, and falls through when s2(=a2) != 0.
  The `bne` branch at 0x2f8 targets 0x2ac, is taken when s2(=a2) != s1(?), and falls through when s2(=a2) == s1(?).
  The `beq` branch at 0x300 targets 0x328, is taken when a1(=one of 0x0, 0x1) == 0, and falls through when a1(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x318 targets 0x328, is taken when v0(=ret(mvpreg_syncpath_controls)) == 0, and falls through when v0(=ret(mvpreg_syncpath_controls)) != 0.
  The `beq` branch at 0x320 targets 0x330 and is always taken.
  The `beq` branch at 0x34c targets 0x2c4 and is always taken.
  The `bne` branch at 0x35c targets 0x2c4, is taken when t1(=0x1) != t9(?), and falls through when t1(=0x1) == t9(?).
  The `beq` branch at 0x378 targets 0x388, is taken when v0(=ret(.text+348)) == 0, and falls through when v0(=ret(.text+348)) != 0.
  The `beq` branch at 0x380 targets 0x330 and is always taken.
  The `beq` branch at 0x3a0 targets 0x2c4 and is always taken.
  The `beq` branch at 0x3b0 targets 0x2dc and is always taken.
  The return at 0x340 has v0 = one of ret(mvpreg_syncpath_controls), 0x0, ret(.text+348).

- `mvptransfer_nextcep` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x3b8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x3b8-0x524 (364 bytes).
  It occupies 364 bytes.
  The `lbu` at 0x3f0 loads 1 byte from a0 (arg0 at entry) +0xbaa.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x5e4, including `lw` at 0x3fc, `lw` at 0x510.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x5e8, including `lw` at 0x400, `lw` at 0x504.
  The `lw` at 0x418 loads 4 bytes from ?.
  3 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x5e8, including `sw` at 0x42c, `sw` at 0x4cc, `sw` at 0x4d0.
  The `lbu` at 0x4d4 loads 1 byte from ?.
  The `sb` at 0x4f8 stores 1 byte to ?.
  The `jalr` at 0x488 calls mvpreg_syncpath_controls with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?, a5=[a0+1508], a6=0xa.
  The `jalr` at 0x4ec calls .text+400 with a0=a0 at entry (arg0), a1=?, a2=?, a3=?, a5=[a0+1508], a6=0xa.
  The `beq` branch at 0x3e8 targets 0x3fc, is taken when a1 == s4(=0x2), and falls through when a1 != s4(=0x2).
  The `bne` branch at 0x3f4 targets 0x4a4, is taken when a1 != at(=[a0+2986]:1), and falls through when a1 == at(=[a0+2986]:1).
  The `beq` branch at 0x408 targets 0x4a0, is taken when v0(=[a0+1512]) >= a5(=[a0+1508]) (unsigned), and falls through when v0(=[a0+1512]) < a5(=[a0+1508]) (unsigned).
  The `beq` branch at 0x410 targets 0x514 and is always taken.
  The `beq` branch at 0x41c targets 0x4d0, is taken when a6(=0xa) == a2(?), and falls through when a6(=0xa) != a2(?).
  The `beq` branch at 0x424 targets 0x4c4, is taken when s4(=0x2) == a2(?), and falls through when s4(=0x2) != a2(?).
  The `beq` branch at 0x43c targets 0x46c, is taken when v0(?) >= a5(=[a0+1508]) (unsigned), and falls through when v0(?) < a5(=[a0+1508]) (unsigned).
  The `beq` branch at 0x45c targets 0x418, is taken when s2(=a2) == 0, and falls through when s2(=a2) != 0.
  The `bne` branch at 0x464 targets 0x418, is taken when s2(=a2) != s1(?), and falls through when s2(=a2) == s1(?).
  The `beq` branch at 0x46c targets 0x4a4, is taken when a1(=one of 0x0, 0x1) == 0, and falls through when a1(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x474 targets 0x4a4, is taken when s3(=a1) == s4(=0x2), and falls through when s3(=a1) != s4(=0x2).
  The `beq` branch at 0x490 targets 0x4a0, is taken when v0(=ret(mvpreg_syncpath_controls)) == 0, and falls through when v0(=ret(mvpreg_syncpath_controls)) != 0.
  The `beq` branch at 0x498 targets 0x4a8 and is always taken.
  The `beq` branch at 0x4c8 targets 0x430 and is always taken.
  The `bne` branch at 0x4d8 targets 0x430, is taken when t0(=0x5) != t9(?), and falls through when t0(=0x5) == t9(?).
  The `beq` branch at 0x50c targets 0x430 and is always taken.
  The `beq` branch at 0x51c targets 0x448 and is always taken.
  The return at 0x4bc has v0 = one of ret(mvpreg_syncpath_controls), 0x0.

- `mvptransfer_start_dma` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x524 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x524-0x87c (856 bytes).
  It occupies 856 bytes.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x48c, including `lw` at 0x584, `lw` at 0x754.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x48c, including `sw` at 0x594, `sw` at 0x764.
  2 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0xba9, including `lbu` at 0x598, `lbu` at 0x63c.
  3 such `sw` accesses store 4 bytes to a1 (arg1 at entry) +0x88, including `sw` at 0x5a4, `sw` at 0x5b8, `sw` at 0x630.
  The `lw` at 0x5a8 loads 4 bytes from a1 (arg1 at entry) +0x8c.
  The `lbu` at 0x5c4 loads 1 byte from a0 (arg0 at entry) +0x474.
  2 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x4a8, including `lbu` at 0x5d4, `lbu` at 0x684.
  The `lbu` at 0x61c loads 1 byte from a0 (arg0 at entry) +0xbb1.
  The `lw` at 0x628 loads 4 bytes from a0 (arg0 at entry) +0x5dc.
  The `lbu` at 0x638 loads 1 byte from a0 (arg0 at entry) +0x473.
  The `ld` at 0x648 loads 8 bytes from a1 (arg1 at entry) +0xd0.
  2 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x88, including `lw` at 0x668, `lw` at 0x6c0.
  The `lbu` at 0x66c loads 1 byte from a1 (arg1 at entry) +0xaa.
  The `lw` at 0x6a0 loads 4 bytes from sym(mvpcontroller_table) +0x0.
  The `lbu` at 0x6a4 loads 1 byte from a0 (arg0 at entry) +0x46c.
  The `lw` at 0x6d8 loads 4 bytes from ([sym(mvpcontroller_table)] + ([a0+1132]:1 << 0x2)) +0xc0.
  The `ld` at 0x6e8 loads 8 bytes from ?.
  The `sd` at 0x6f4 stores 8 bytes to ?.
  The `sd` at 0x6f8 stores 8 bytes to [([sym(mvpcontroller_table)] + ([a0+1132]:1 << 0x2))+192] +0x20.
  The `sd` at 0x70c stores 8 bytes to [([sym(mvpcontroller_table)] + ([a0+1132]:1 << 0x2))+192] +0x18.
  2 such `lbu` accesses load 1 byte from a1 (arg1 at entry) +0xa9, including `lbu` at 0x710, `lbu` at 0x878.
  The `lw` at 0x78c loads 4 bytes from [sym(mvpcontroller_table)] +0xcc.
  The `lw` at 0x798 loads 4 bytes from sym(mvp_umba) +0x8.
  The `lw` at 0x7b8 loads 4 bytes from (ret(kvtophys) | 0xffffffffa0000000) +0x0.
  The `sw` at 0x7bc stores 4 bytes to [[sym(mvpcontroller_table)]+204] +0x10.
  The `lw` at 0x7c0 loads 4 bytes from (ret(kvtophys) | 0xffffffffa0000000) +0x4.
  The `sw` at 0x7c4 stores 4 bytes to [[sym(mvpcontroller_table)]+204] +0x14.
  The `lw` at 0x7c8 loads 4 bytes from (ret(kvtophys) | 0xffffffffa0000000) +0x8.
  The `sw` at 0x7cc stores 4 bytes to [[sym(mvpcontroller_table)]+204] +0x18.
  The `lw` at 0x7d0 loads 4 bytes from (ret(kvtophys) | 0xffffffffa0000000) +0xc.
  The `sw` at 0x7d4 stores 4 bytes to [[sym(mvpcontroller_table)]+204] +0x1c.
  The `lw` at 0x7d8 loads 4 bytes from (ret(kvtophys) | 0xffffffffa0000000) +0x10.
  The `sw` at 0x7e0 stores 4 bytes to [[sym(mvpcontroller_table)]+204] +0x20.
  The `sw` at 0x7e4 stores 4 bytes to [[sym(mvpcontroller_table)]+204] +0xc.
  The `lw` at 0x7e8 loads 4 bytes from [sym(mvpcontroller_table)] +0x320.
  The `sw` at 0x7f8 stores 4 bytes to [sym(mvpcontroller_table)] +0x320.
  The `sw` at 0x7fc stores 4 bytes to [[sym(mvpcontroller_table)]+204] +0x8.
  The `lw` at 0x820 loads 4 bytes from sym(mvp_umba) +0x20.
  The `sb` at 0x860 stores 1 byte to a1 (arg1 at entry) +0xa9.
  The `jalr` at 0x564 calls .text+592 with a0=a0 at entry (arg0), a1=a3 at entry (arg3), a2=a1 at entry (arg1), a3=a3 at entry (arg3).
  The `jalr` at 0x57c calls mvptransfer_stop with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jalr` at 0x65c calls .text+52 with a0=a0 at entry (arg0), a1=?, a2=?, a3=sym(mvptransfer_too_many_errors).
  The `jalr` at 0x67c calls kvtophys with a0=(a0 + ([a1+170]:1 << 0x6)), a1=?, a2=?, a3=?, a4=sym(kvtophys).
  The `jalr` at 0x6dc calls splhi with a0=[sym(mvpcontroller_table)], a1=?, a2=0x2, a3=[a0+1192]:1.
  The `jalr` at 0x708 calls splx with a0=ret(splhi), a1=0x0, a2=?, a3=?.
  The `jalr` at 0x734 calls .text+952 with a0=a0 at entry (arg0), a1=a3 at entry (arg3), a2=a1 at entry (arg1), a3=sym(mvptransfer_nextcep).
  The `jalr` at 0x74c calls mvptransfer_stop with a0=a0 at entry (arg0), a1=?, a2=?, a3=?, a4=sym(mvptransfer_stop).
  The `jalr` at 0x788 calls splhi with a0=[sym(mvpcontroller_table)], a1=?, a2=0x2, a3=[a0+1192]:1, a6=sym(splhi), a7=[sym(mvpcontroller_table)]+792.
  The `jalr` at 0x808 calls .text with a0=ret(splhi), a1=?, a2=[sym(mvpcontroller_table)]+792, a3=([[sym(mvpcontroller_table)]+800] | 0x1), a6=sym(mvp_umba).
  The `jalr` at 0x834 calls .text+52 with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jalr` at 0x848 calls splx with a0=ret(splhi), a1=?, a2=?, a3=?.
  The `jalr` at 0x86c calls splx with a0=ret(splhi), a1=?, a2=?, a3=?.
  The `beq` branch at 0x550 targets 0x598, is taken when a3 == at(=0x3), and falls through when a3 != at(=0x3).
  The `beq` branch at 0x56c targets 0x598, is taken when v0(=ret(.text+592)) == 0, and falls through when v0(=ret(.text+592)) != 0.
  The `beq` branch at 0x590 targets 0x5fc and is always taken.
  The `beq` branch at 0x59c targets 0x61c, is taken when a1(=[a0+2985]:1) == 0, and falls through when a1(=[a0+2985]:1) != 0.
  The `beq` branch at 0x5ac targets 0x5bc, is taken when v0(=[a1+140]) == 0, and falls through when v0(=[a1+140]) != 0.
  The `beq` branch at 0x5bc targets 0x634, is taken when s3(=a2) == 0, and falls through when s3(=a2) != 0.
  The `beq` branch at 0x5cc targets 0x768, is taken when s2(?) == a2(=0xff), and falls through when s2(?) != a2(=0xff).
  The `beq` branch at 0x5d8 targets 0x63c, is taken when a3(=[a0+1192]:1) == 0, and falls through when a3(=[a0+1192]:1) != 0.
  The `beq` branch at 0x5f4 targets 0x66c, is taken when v1(?) == 0, and falls through when v1(?) != 0.
  The `beq` branch at 0x620 targets 0x5a4, is taken when s3(=a2) == a0(=[a0+2993]:1), and falls through when s3(=a2) != a0(=[a0+2993]:1).
  The `beq` branch at 0x62c targets 0x5a8 and is always taken.
  The `beq` branch at 0x634 targets 0x5c8 and is always taken.
  The `beq` branch at 0x640 targets 0x5e0, is taken when a1(=[a0+2985]:1) == 0, and falls through when a1(=[a0+2985]:1) != 0.
  The `beq` branch at 0x650 targets 0x5dc, is taken when s3(=a2) == a2(?), and falls through when s3(=a2) != a2(?).
  The `beq` branch at 0x664 targets 0x5dc and is always taken.
  The `beq` branch at 0x69c targets 0x778, is taken when a2(=0x2) == a3(=[a0+1192]:1), and falls through when a2(=0x2) != a3(=[a0+1192]:1).
  The `beq` branch at 0x6ec targets 0x6fc, is taken when t8(?) == a1(=0x0), and falls through when t8(?) != a1(=0x0).
  The `beq` branch at 0x718 targets 0x858, is taken when v0(=0x2) == v1(=[a1+169]:1), and falls through when v0(=0x2) != v1(=[a1+169]:1).
  The `beq` branch at 0x720 targets 0x770, is taken when s4(=a3) == a0(=0x3), and falls through when s4(=a3) != a0(=0x3).
  The `beq` branch at 0x73c targets 0x770, is taken when v0(=ret(.text+952)) == 0, and falls through when v0(=ret(.text+952)) != 0.
  The `beq` branch at 0x760 targets 0x5fc and is always taken.
  The `beq` branch at 0x768 targets 0x600 and is always taken.
  The `beq` branch at 0x770 targets 0x5fc and is always taken.
  The `beq` branch at 0x7a4 targets 0x7e4, is taken when a7(=[sym(mvptransfer_stuff_dmadescs)]) == 0, and falls through when a7(=[sym(mvptransfer_stuff_dmadescs)]) != 0.
  The `beq` branch at 0x7f0 targets 0x800, is taken when a3(=([[sym(mvpcontroller_table)]+800] | 0x1)) == t1(=[[sym(mvpcontroller_table)]+800]), and falls through when a3(=([[sym(mvpcontroller_table)]+800] | 0x1)) != t1(=[[sym(mvpcontroller_table)]+800]).
  The `beq` branch at 0x810 targets 0x868, is taken when v0(=ret(.text)) == 0, and falls through when v0(=ret(.text)) != 0.
  The `bne` branch at 0x824 targets 0x844, is taken when t3(=[sym(.data)+32]) != 0, and falls through when t3(=[sym(.data)+32]) == 0.
  The `beq` branch at 0x83c targets 0x864, is taken when v0(=ret(.text+52)) == 0, and falls through when v0(=ret(.text+52)) != 0.
  The `beq` branch at 0x850 targets 0x5fc and is always taken.
  The `beq` branch at 0x85c targets 0x71c and is always taken.
  The `beq` branch at 0x874 targets 0x714 and is always taken.
  The return at 0x614 has v0 = one of ?, 0x47.

- `mvptransfer_stop_dma` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x87c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x87c-0x940 (196 bytes).
  It occupies 196 bytes.
  The `lbu` at 0x89c loads 1 byte from a0 (arg0 at entry) +0x467.
  The `lbu` at 0x8b4 loads 1 byte from a0 (arg0 at entry) +0x4a8.
  2 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x467, including `sb` at 0x8b8, `sb` at 0x900.
  The `lw` at 0x8c4 loads 4 bytes from sym(mvpcontroller_table) +0x0.
  The `lbu` at 0x8c8 loads 1 byte from a0 (arg0 at entry) +0x46c.
  The `ld` at 0x8e0 loads 8 bytes from ?.
  The `lw` at 0x8e4 loads 4 bytes from ([sym(mvpcontroller_table)] + ([a0+1132]:1 << 0x2)) +0xc0.
  The `sd` at 0x8ec stores 8 bytes to ?.
  The `sd` at 0x8f0 stores 8 bytes to [([sym(mvpcontroller_table)] + ([a0+1132]:1 << 0x2))+192] +0x0.
  The `lw` at 0x918 loads 4 bytes from [sym(mvpcontroller_table)] +0xcc.
  The `sw` at 0x91c stores 4 bytes to [sym(mvpcontroller_table)] +0x318.
  The `sw` at 0x920 stores 4 bytes to [[sym(mvpcontroller_table)]+204] +0x0.
  The `sw` at 0x924 stores 4 bytes to [sym(mvpcontroller_table)] +0x31c.
  The `sw` at 0x928 stores 4 bytes to [[sym(mvpcontroller_table)]+204] +0x4.
  The `sw` at 0x92c stores 4 bytes to [sym(mvpcontroller_table)] +0x320.
  The `sw` at 0x930 stores 4 bytes to [[sym(mvpcontroller_table)]+204] +0x8.
  The `sw` at 0x934 stores 4 bytes to [sym(mvpcontroller_table)] +0x324.
  The `sw` at 0x93c stores 4 bytes to [[sym(mvpcontroller_table)]+204] +0xc.
  The `jalr` at 0x890 calls splhi with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x8fc calls splx with a0=ret(splhi), a1=0x3, a2=?, a3=0x2, a6=sym(splx).
  The `bne` branch at 0x8ac targets 0x8f4, is taken when v0(=[a0+1127]:1) < 0x3 (signed), and falls through when v0(=[a0+1127]:1) >= 0x3 (signed).
  The `beq` branch at 0x8c0 targets 0x918, is taken when a3(=0x2) == v1(=[a0+1192]:1), and falls through when a3(=0x2) != v1(=[a0+1192]:1).
  The `beq` branch at 0x938 targets 0x8f4 and is always taken.
  The return at 0x910 has v0 = 0x0.

- `mvptransfer_alloc_next_read` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x940 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x940-0x9c4 (132 bytes).
  It occupies 132 bytes.
  The `lw` at 0x940 loads 4 bytes from a1 (arg1 at entry) +0xc0.
  The `lw` at 0x95c loads 4 bytes from a0 (arg0 at entry) +0x58c.
  The `lw` at 0x980 loads 4 bytes from a0 (arg0 at entry) +0x578.
  The `sb` at 0x9a8 stores 1 byte to a1 (arg1 at entry) +0xac.
  The `sw` at 0x9b0 stores 4 bytes to a1 (arg1 at entry) +0xb4.
  The `sw` at 0x9b8 stores 4 bytes to a1 (arg1 at entry) +0xc0.
  The `jalr` at 0x97c calls dms_block_alloc with a0=[a0+1400], a1=sp-80, a2=a2 at entry (arg2), a3=a3 at entry (arg3), a4=a0 at entry (arg0).
  The `beq` branch at 0x948 targets 0x95c, is taken when at(=[a1+192]) == 0, and falls through when at(=[a1+192]) != 0.
  The `beq` branch at 0x968 targets 0x9bc, is taken when v1(=[a0+1420]) == 0, and falls through when v1(=[a0+1420]) != 0.
  The `beq` branch at 0x988 targets 0x998, is taken when v0(=ret(dms_block_alloc)) == a1(=0x1c), and falls through when v0(=ret(dms_block_alloc)) != a1(=0x1c).
  The `beq` branch at 0x990 targets 0x9a0, is taken when v0(=ret(dms_block_alloc)) == 0, and falls through when v0(=ret(dms_block_alloc)) != 0.
  The `beq` branch at 0x998 targets 0x954 and is always taken.
  The `beq` branch at 0x9b4 targets 0x998 and is always taken.
  The `beq` branch at 0x9bc targets 0x954 and is always taken.
  The return at 0x954 has v0 = one of 0x47, ret(dms_block_alloc), 0x1c.

- `mvptransfer_get_next_write` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x9c4 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x9c4-0xaa0 (220 bytes).
  It occupies 220 bytes.
  The `lw` at 0x9c8 loads 4 bytes from a1 (arg1 at entry) +0xc0.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x57c, including `lw` at 0xa10, `lw` at 0xa58.
  The `lw` at 0xa2c loads 4 bytes from a1 (arg1 at entry) +0xb4.
  The `lbu` at 0xa5c loads 1 byte from a0 (arg0 at entry) +0x4a8.
  The `sw` at 0xa6c stores 4 bytes to a1 (arg1 at entry) +0xc0.
  The `jalr` at 0xa0c calls dms_fifo_deq with a0=[a0+1404], a1=a1+176, a2=0x0, a3=a3 at entry (arg3).
  The `jalr` at 0xa54 calls dms_get_nfilled with a0=[a0+1404], a1=sp-32, a2=sym(dms_get_nfilled), a3=?.
  The `jalr` at 0xa7c calls mvperrprintf with a0=0x4, a1=sym(.rodata), a2=[a1+180], a3=sym(mvperrprintf).
  The `beq` branch at 0x9e0 targets 0x9fc, is taken when at(=[a1+192]) == 0, and falls through when at(=[a1+192]) != 0.
  The `beq` branch at 0xa14 targets 0xa2c, is taken when v0(=ret(dms_fifo_deq)) == 0, and falls through when v0(=ret(dms_fifo_deq)) != 0.
  The `beq` branch at 0xa1c targets 0xa4c, is taken when v0(=ret(dms_fifo_deq)) == a0(=0x10), and falls through when v0(=ret(dms_fifo_deq)) != a0(=0x10).
  The `beq` branch at 0xa24 targets 0x9ec and is always taken.
  The `beq` branch at 0xa34 targets 0xa94, is taken when a2(=[a1+180]) == v1(=0xa), and falls through when a2(=[a1+180]) != v1(=0xa).
  The `bne` branch at 0xa3c targets 0xa70, is taken when a2(=[a1+180]) != a0(=0x2), and falls through when a2(=[a1+180]) == a0(=0x2).
  The `beq` branch at 0xa44 targets 0x9e8 and is always taken.
  The `beq` branch at 0xa60 targets 0xa8c, is taken when a3(=[a0+1192]:1) == 0, and falls through when a3(=[a0+1192]:1) != 0.
  The `beq` branch at 0xa68 targets 0x9e8 and is always taken.
  The `beq` branch at 0xa84 targets 0x9e8 and is always taken.
  The `beq` branch at 0xa8c targets 0x9e8 and is always taken.
  The `beq` branch at 0xa98 targets 0x9e8 and is always taken.
  The return at 0x9f4 has v0 = one of ?, ret(dms_fifo_deq).

- `mvptransfer_getbuffs` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0xaa0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0xaa0-0xd80 (736 bytes).
  It occupies 736 bytes.
  The `lbu` at 0xac8 loads 1 byte from a0 (arg0 at entry) +0x467.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x5e0, including `lw` at 0xb00, `lw` at 0xb18, `lw` at 0xc44.
  6 such `sb` accesses store 1 byte to ?, including `sb` at 0xb14, `sb` at 0xb54, `sb` at 0xb98.
  The `sw` at 0xb24 stores 4 bytes to a0 (arg0 at entry) +0x5e0.
  3 such `lbu` accesses load 1 byte from ?, including `lbu` at 0xb44, `lbu` at 0xcf0, `lbu` at 0xd3c.
  The `lw` at 0xb50 loads 4 bytes from a0 (arg0 at entry) +0x594.
  5 such `sw` accesses store 4 bytes to ?, including `sw` at 0xb64, `sw` at 0xbdc, `sw` at 0xbf4.
  8 such `lw` accesses load 4 bytes from ?, including `lw` at 0xba0, `lw` at 0xbac, `lw` at 0xbc4.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x578, including `lw` at 0xbc0, `lw` at 0xc28.
  5 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x478, including `lbu` at 0xbf8, `lbu` at 0xce0, `lbu` at 0xd00.
  3 such `sh` accesses store 2 bytes to ?, including `sh` at 0xccc, `sh` at 0xd0c, `sh` at 0xd24.
  The `jalr` at 0xb60 calls .text+2500 with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jalr` at 0xb88 calls .text+2368 with a0=a0 at entry (arg0), a1=?, a2=sym(mvptransfer_alloc_next_read), a3=?.
  The `jalr` at 0xbbc calls dms_block_info with a0=[a0+1400], a1=sp-152, a2=?, a3=sym(dms_block_info).
  The `jalr` at 0xc24 calls dms_block_get_tile_list with a0=[a0+1400], a1=?, a2=?, a3=?, a5=sym(dms_block_get_tile_list).
  The `jalr` at 0xd50 calls __dcache_wb with a0=?, a1=0x40, a2=?, a3=?.
  The `beq` branch at 0xae8 targets 0xd68, is taken when v0(=[a0+1127]:1) == at(=0x3), and falls through when v0(=[a0+1127]:1) != at(=0x3).
  The `beq` branch at 0xaf4 targets 0xd68, is taken when a6(=0x2) == v0(=[a0+1127]:1), and falls through when a6(=0x2) != v0(=[a0+1127]:1).
  The `beq` branch at 0xb04 targets 0xb28 and is always taken.
  The `bne` branch at 0xb0c targets 0xc98, is taken when v0(=ret(.text+2500)) != s4(=0xffffffffc011eeee), and falls through when v0(=ret(.text+2500)) == s4(=0xffffffffc011eeee).
  The `bne` branch at 0xb20 targets 0xc98, is taken when s5(=one of 0x0, 0x1) != 0, and falls through when s5(=one of 0x0, 0x1) == 0.
  The `bne` branch at 0xb48 targets 0xd70, is taken when s6(=0x6) != a1(?), and falls through when s6(=0x6) == a1(?).
  The `beq` branch at 0xb68 targets 0xb98, is taken when v0(=ret(.text+2500)) == 0, and falls through when v0(=ret(.text+2500)) != 0.
  The `beq` branch at 0xb70 targets 0xc98, is taken when v0(=ret(.text+2500)) == s7(=0x1c), and falls through when v0(=ret(.text+2500)) != s7(=0x1c).
  The `bne` branch at 0xb78 targets 0xb0c, is taken when v0(=ret(.text+2500)) != s8(=0x10), and falls through when v0(=ret(.text+2500)) == s8(=0x10).
  The `bne` branch at 0xb90 targets 0xc98, is taken when v0(=ret(.text+2368)) != 0, and falls through when v0(=ret(.text+2368)) == 0.
  The `beq` branch at 0xbd0 targets 0xbe0, is taken when a0(?) >= v0(?) (signed), and falls through when a0(?) < v0(?) (signed).
  The `beq` branch at 0xc00 targets 0xc14, is taken when a0(=[a0+1144]:1) >= a2(?) (signed), and falls through when a0(=[a0+1144]:1) < a2(?) (signed).
  The `bne` branch at 0xc2c targets 0xc98, is taken when v0(=ret(dms_block_get_tile_list)) != 0, and falls through when v0(=ret(dms_block_get_tile_list)) == 0.
  The `beq` branch at 0xc38 targets 0xc44, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `blez` branch at 0xc5c targets 0xd00, is taken when a7(?) <= 0 (signed), and falls through when a7(?) > 0 (signed).
  The `beq` branch at 0xc84 targets 0xd78, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `beq` branch at 0xc8c targets 0xccc, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `bne` branch at 0xcd8 targets 0xc6c, is taken when v0(?) < t1(?) (signed), and falls through when v0(?) >= t1(?) (signed).
  The `bne` branch at 0xce8 targets 0xd0c, is taken when v0(?) < t2(=[a0+1144]:1) (signed), and falls through when v0(?) >= t2(=[a0+1144]:1) (signed).
  The `beq` branch at 0xcf8 targets 0xd48 and is always taken.
  The `blez` branch at 0xd04 targets 0xd4c, is taken when a1(=[a0+1144]:1) <= 0 (signed), and falls through when a1(=[a0+1144]:1) > 0 (signed).
  The `beq` branch at 0xd1c targets 0xd3c, is taken when v0(?) >= a2(=[a0+1144]:1) (signed), and falls through when v0(?) < a2(=[a0+1144]:1) (signed).
  The `bne` branch at 0xd34 targets 0xd0c, is taken when v0(?) < a3(=[a0+1144]:1) (signed), and falls through when v0(?) >= a3(=[a0+1144]:1) (signed).
  The `beq` branch at 0xd60 targets 0xb18 and is always taken.
  The `beq` branch at 0xd68 targets 0xc98 and is always taken.
  The `beq` branch at 0xd70 targets 0xc98 and is always taken.
  The `beq` branch at 0xd78 targets 0xc98 and is always taken.
  The return at 0xcc4 has v0 = one of ret(.text+2500), ?, ret(.text+2368), ret(dms_block_get_tile_list), 0xe, 0x47.

- `mvptransfer_nextnda` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0xd80 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0xd80-0xf54 (468 bytes).
  It occupies 468 bytes.
  4 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x5ec, including `lw` at 0xd88, `lw` at 0xe80, `lw` at 0xed8.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x5e0, including `lw` at 0xdb0, `lw` at 0xea0.
  3 such `lw` accesses load 4 bytes from ?, including `lw` at 0xe00, `lw` at 0xe10, `lw` at 0xec8.
  The `lw` at 0xe44 loads 4 bytes from a0 (arg0 at entry) +0x498.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x498, including `sw` at 0xe58, `sw` at 0xe88.
  3 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x608, including `sw` at 0xe5c, `sw` at 0xe74, `sw` at 0xf24.
  The `lw` at 0xe60 loads 4 bytes from sym(mvptransfer_cumbuff_errorcount) +0x0.
  3 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x5ec, including `sw` at 0xe9c, `sw` at 0xee8, `sw` at 0xf38.
  The `sb` at 0xecc stores 1 byte to ?.
  The `lbu` at 0xf10 loads 1 byte from ?.
  The `jalr` at 0xe34 calls .text+2720 with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `beq` branch at 0xdb8 targets 0xe28, is taken when s1(?) >= a0(=[a0+1504]) (unsigned), and falls through when s1(?) < a0(=[a0+1504]) (unsigned).
  The `beq` branch at 0xdc0 targets 0xdd4 and is always taken.
  The `beq` branch at 0xdcc targets 0xe24, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `bne` branch at 0xe08 targets 0xdcc, is taken when s2(=0x2) != v0(?), and falls through when s2(=0x2) == v0(?).
  The `bne` branch at 0xe14 targets 0xdc8, is taken when a6(?) != 0, and falls through when a6(?) == 0.
  The `beq` branch at 0xe1c targets 0xdcc and is always taken.
  The `bne` branch at 0xe28 targets 0xe80, is taken when a7(?) != 0, and falls through when a7(?) == 0.
  The `beq` branch at 0xe3c targets 0xdb0, is taken when v0(=ret(.text+2720)) == 0, and falls through when v0(=ret(.text+2720)) != 0.
  The `beq` branch at 0xe54 targets 0xe60, is taken when v0(=ret(.text+2720)) == t1(=0x1c), and falls through when v0(=ret(.text+2720)) != t1(=0x1c).
  The `beq` branch at 0xe64 targets 0xe78, is taken when v0(=[sym(mvptransfer_cumbuff_errorcount)]) == 0, and falls through when v0(=[sym(mvptransfer_cumbuff_errorcount)]) != 0.
  The `beq` branch at 0xe6c targets 0xe78, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0xe78 targets 0xef0 and is always taken.
  The `beq` branch at 0xe8c targets 0xeec, is taken when v0(=[a0+1516]) >= a0(=[a0+1504]) (unsigned), and falls through when v0(=[a0+1516]) < a0(=[a0+1504]) (unsigned).
  The `beq` branch at 0xe94 targets 0xf3c and is always taken.
  The `beq` branch at 0xeb8 targets 0xeec, is taken when v0(=[a0+1516]+1) >= a0(=[a0+1504]) (unsigned), and falls through when v0(=[a0+1516]+1) < a0(=[a0+1504]) (unsigned).
  The `beq` branch at 0xed0 targets 0xf10, is taken when s2(=0x2) == a0(?), and falls through when s2(=0x2) != a0(?).
  The `bne` branch at 0xedc targets 0xe9c, is taken when a5(=0xa) != a0(?), and falls through when a5(=0xa) == a0(?).
  The `beq` branch at 0xee4 targets 0xea0 and is always taken.
  The `beq` branch at 0xf18 targets 0xf28, is taken when s2(=0x2) == v1(?), and falls through when s2(=0x2) != v1(?).
  The `beq` branch at 0xf20 targets 0xef0 and is always taken.
  The `beq` branch at 0xf34 targets 0xef0 and is always taken.
  The `beq` branch at 0xf4c targets 0xec4 and is always taken.
  The return at 0xf08 has v0 = one of 0x0, ?.

- `mvptransfer_nextust` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0xf54 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0xf54-0x103c (232 bytes).
  It occupies 232 bytes.
  The `lw` at 0xf54 loads 4 bytes from a0 (arg0 at entry) +0x5ec.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x5f0, including `lw` at 0xf58, `lw` at 0x1004.
  3 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x5f0, including `sw` at 0xf78, `sw` at 0xfb8, `sw` at 0x1010.
  The `lw` at 0xfa4 loads 4 bytes from ?.
  The `ld` at 0xfe0 loads 8 bytes from a1 (arg1 at entry) +0x8.
  2 such `sd` accesses store 8 bytes to ?, including `sd` at 0xfe4, `sd` at 0xfec.
  The `ld` at 0xfe8 loads 8 bytes from a1 (arg1 at entry) +0x0.
  The `lbu` at 0xff4 loads 1 byte from a0 (arg0 at entry) +0x476.
  The `sb` at 0xffc stores 1 byte to ?.
  The `sw` at 0x1000 stores 4 bytes to ?.
  The `lbu` at 0x1014 loads 1 byte from ?.
  The `beq` branch at 0xf64 targets 0xfc4, is taken when v0(=[a0+1520]) >= a7(=[a0+1516]) (unsigned), and falls through when v0(=[a0+1520]) < a7(=[a0+1516]) (unsigned).
  The `beq` branch at 0xf6c targets 0x102c and is always taken.
  The `beq` branch at 0xf8c targets 0xfc4, is taken when a5(?) >= a7(=[a0+1516]) (unsigned), and falls through when a5(?) < a7(=[a0+1516]) (unsigned).
  The `beq` branch at 0xfa8 targets 0xfd0, is taken when t1(=0x2) == a5(?), and falls through when t1(=0x2) != a5(?).
  The `bne` branch at 0xfb0 targets 0xf74, is taken when t2(=0xa) != a5(?), and falls through when t2(=0xa) == a5(?).
  The `beq` branch at 0xfbc targets 0xf80 and is always taken.
  The `beq` branch at 0xfd0 targets 0x1014, is taken when a2 == 0, and falls through when a2 != 0.
  The `beq` branch at 0xfd8 targets 0xff4, is taken when a1 == 0, and falls through when a1 != 0.
  The `bne` branch at 0x101c targets 0xfc8, is taken when at(?) != v0(=0x3), and falls through when at(?) == v0(=0x3).
  The `beq` branch at 0x1024 targets 0xfd8 and is always taken.
  The `beq` branch at 0x1034 targets 0xf98 and is always taken.
  The return at 0xfc8 has v0 = one of 0x0, 0x47.
  The return at 0x100c has v0 = 0x0.

- `mvptransfer_send_events` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x103c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x103c-0x1150 (276 bytes).
  It occupies 276 bytes.
  The `lw` at 0x1048 loads 4 bytes from a0 (arg0 at entry) +0x484.
  The `sw` at 0x1070 stores 4 bytes to a0 (arg0 at entry) +0x62c.
  The `sw` at 0x1074 stores 4 bytes to a0 (arg0 at entry) +0x638.
  The `sw` at 0x107c stores 4 bytes to a0 (arg0 at entry) +0x650.
  The `lbu` at 0x1080 loads 1 byte from a0 (arg0 at entry) +0x47d.
  The `ld` at 0x1084 loads 8 bytes from a0 (arg0 at entry) +0x5b0.
  The `ld` at 0x1088 loads 8 bytes from a0 (arg0 at entry) +0x5a8.
  The `sd` at 0x108c stores 8 bytes to a0 (arg0 at entry) +0x640.
  2 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x648, including `sd` at 0x1094, `sd` at 0x10a4.
  The `sw` at 0x10b8 stores 4 bytes to a0 (arg0 at entry) +0x6a8.
  The `sh` at 0x10c8 stores 2 bytes to a0 (arg0 at entry) +0x6b0.
  The `sw` at 0x10cc stores 4 bytes to a0 (arg0 at entry) +0x6bc.
  The `lw` at 0x10d0 loads 4 bytes from a0 (arg0 at entry) +0x5b4.
  The `lbu` at 0x10d4 loads 1 byte from a0 (arg0 at entry) +0xba9.
  The `sw` at 0x10d8 stores 4 bytes to a0 (arg0 at entry) +0x6b8.
  The `sw` at 0x10e0 stores 4 bytes to a0 (arg0 at entry) +0x6b4.
  The `sw` at 0x10ec stores 4 bytes to a0 (arg0 at entry) +0x630.
  The `lw` at 0x10f0 loads 4 bytes from a0 (arg0 at entry) +0x578.
  The `jalr` at 0x10f4 calls dms_fifo_enq with a0=[a0+1400], a1=a0+1576, a2=?, a3=?.
  The `beq` branch at 0x1064 targets 0x1130, is taken when (s1(=[a0+1156]) & a1) == 0, and falls through when (s1(=[a0+1156]) & a1) != 0.
  The `beq` branch at 0x1098 targets 0x10a8, is taken when a3(=[a0+1149]:1) == 0, and falls through when a3(=[a0+1149]:1) != 0.
  The `beq` branch at 0x10bc targets 0x10e4, is taken when (s1(?) & 0x200) == 0, and falls through when (s1(?) & 0x200) != 0.
  The `beq` branch at 0x10e4 targets 0x1118 and is always taken.
  The `beq` branch at 0x1108 targets 0x1130, is taken when (s1(?) & t9(?)) == 0, and falls through when (s1(?) & t9(?)) != 0.
  The `beq` branch at 0x1110 targets 0x1130, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `bne` branch at 0x1118 targets 0x10ec, is taken when ra(?) != 0, and falls through when ra(?) == 0.
  The `beq` branch at 0x1120 targets 0x1130, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `bne` branch at 0x1128 targets 0x1118, is taken when a2(?) != 0, and falls through when a2(?) == 0.
  The return at 0x1148 has v0 = one of ?, ret(dms_fifo_enq).

- `mvptransfer_post_event` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x1150 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x1150-0x12a4 (340 bytes).
  It occupies 340 bytes.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x484, including `lw` at 0x1174, `lw` at 0x11ec.
  5 such `ld` accesses load 8 bytes from a1 (arg1 at entry) +0xa0, including `ld` at 0x1180, `ld` at 0x11bc, `ld` at 0x11d4.
  The `ld` at 0x1184 loads 8 bytes from a0 (arg0 at entry) +0x5d0.
  The `lbu` at 0x1188 loads 1 byte from a0 (arg0 at entry) +0x477.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x48c, including `lw` at 0x11ac, `lw` at 0x11f0.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x48c, including `sw` at 0x11b8, `sw` at 0x1208.
  The `sd` at 0x11c0 stores 8 bytes to a0 (arg0 at entry) +0x5d0.
  2 such `ld` accesses load 8 bytes from a1 (arg1 at entry) +0x98, including `ld` at 0x11c4, `ld` at 0x120c.
  The `sd` at 0x11c8 stores 8 bytes to a1 (arg1 at entry) +0xc8.
  The `lbu` at 0x11cc loads 1 byte from a0 (arg0 at entry) +0x47d.
  2 such `sd` accesses store 8 bytes to a1 (arg1 at entry) +0xd0, including `sd` at 0x11e4, `sd` at 0x12a0.
  The `sw` at 0x1214 stores 4 bytes to a1 (arg1 at entry) +0x144.
  The `sd` at 0x1218 stores 8 bytes to a1 (arg1 at entry) +0x150.
  The `sw` at 0x121c stores 4 bytes to a1 (arg1 at entry) +0x14c.
  The `sw` at 0x1224 stores 4 bytes to a1 (arg1 at entry) +0x138.
  The `sw` at 0x122c stores 4 bytes to a1 (arg1 at entry) +0x130.
  The `lw` at 0x1234 loads 4 bytes from a0 (arg0 at entry) +0x5d8.
  The `sw` at 0x1240 stores 4 bytes to a1 (arg1 at entry) +0x148.
  The `lw` at 0x1254 loads 4 bytes from a0 (arg0 at entry) +0x578.
  The `lw` at 0x1278 loads 4 bytes from a1 (arg1 at entry) +0xb8.
  The `jalr` at 0x11a4 calls .text+4156 with a0=a0 at entry (arg0), a1=0x200, a2=?, a3=sym(mvptransfer_send_events).
  The `jalr` at 0x1200 calls .text+4156 with a0=a0 at entry (arg0), a1=[a0+1164], a2=0x0, a3=?, a5=[a1+152]:8, a6=sym(mvptransfer_send_events), a7=[a0+1149]:1.
  The `jalr` at 0x123c calls dms_timestamp with a0=a1+316, a1=?, a2=?, a3=?, a5=[a1+152]:8.
  The `jalr` at 0x1250 calls dms_fifo_enq with a0=[a0+1400], a1=a1+176, a2=?, a3=?.
  The `beq` branch at 0x116c targets 0x1290, is taken when a2 == 0, and falls through when a2 != 0.
  The `beq` branch at 0x117c targets 0x11c0, is taken when (at(=[a0+1156]) & 0x200) == 0, and falls through when (at(=[a0+1156]) & 0x200) != 0.
  The `blez` branch at 0x1198 targets 0x11c0, is taken when a2(?) <= 0 (signed), and falls through when a2(?) > 0 (signed).
  The `beq` branch at 0x11d8 targets 0x1298, is taken when a7(=[a0+1149]:1) == 0, and falls through when a7(=[a0+1149]:1) != 0.
  The `beq` branch at 0x11e8 targets 0x1278, is taken when s8(=a2) == 0, and falls through when s8(=a2) != 0.
  The `beq` branch at 0x11f8 targets 0x1214, is taken when (a1(=[a0+1164]) & a0(=[a0+1156])) == 0, and falls through when (a1(=[a0+1164]) & a0(=[a0+1156])) != 0.
  The `beq` branch at 0x1258 targets 0x1288, is taken when v0(=ret(dms_fifo_enq)) == 0, and falls through when v0(=ret(dms_fifo_enq)) != 0.
  The `bne` branch at 0x1280 targets 0x11f0, is taken when (t9(=[a1+184]) & a0(=[a0+1156])) != 0, and falls through when (t9(=[a1+184]) & a0(=[a0+1156])) == 0.
  The `beq` branch at 0x1288 targets 0x1260 and is always taken.
  The `beq` branch at 0x1290 targets 0x11c0 and is always taken.
  The `beq` branch at 0x129c targets 0x11e8 and is always taken.
  The return at 0x1270 has v0 = one of ret(dms_fifo_enq), 0x0.

- `mvptransfer_bufferdone` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x12a4 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x12a4-0x15bc (792 bytes).
  It occupies 792 bytes.
  The `lw` at 0x12b0 loads 4 bytes from a0 (arg0 at entry) +0x5f0.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x5f4, including `lw` at 0x12b4, `lw` at 0x143c, `lw` at 0x1598.
  4 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x5f4, including `sw` at 0x12e4, `sw` at 0x1324, `sw` at 0x1448.
  9 such `lw` accesses load 4 bytes from ?, including `lw` at 0x1310, `lw` at 0x1378, `lw` at 0x13a8.
  9 such `sw` accesses store 4 bytes to ?, including `sw` at 0x1368, `sw` at 0x137c, `sw` at 0x1434.
  The `lbu` at 0x136c loads 1 byte from a0 (arg0 at entry) +0x4a8.
  The `lbu` at 0x1380 loads 1 byte from a0 (arg0 at entry) +0xbe2.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x578, including `lw` at 0x13b4, `lw` at 0x13fc.
  The `lbu` at 0x13e4 loads 1 byte from ?.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x57c, including `lw` at 0x141c, `lw` at 0x14f4, `lw` at 0x1508.
  2 such `sb` accesses store 1 byte to ?, including `sb` at 0x142c, `sb` at 0x1594.
  The `lbu` at 0x144c loads 1 byte from a0 (arg0 at entry) +0xba9.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x59c, including `lw` at 0x1450, `lw` at 0x14c8.
  The `sw` at 0x145c stores 4 bytes to a0 (arg0 at entry) +0x59c.
  The `lbu` at 0x1464 loads 1 byte from a0 (arg0 at entry) +0x46c.
  The `lw` at 0x1480 loads 4 bytes from table(sym(mvptransfer_stats)) +0x0.
  The `sw` at 0x1488 stores 4 bytes to table(sym(mvptransfer_stats)) +0x0.
  The `lbu` at 0x1494 loads 1 byte from a0 (arg0 at entry) +0x471.
  The `lw` at 0x14bc loads 4 bytes from a0 (arg0 at entry) +0x598.
  The `jalr` at 0x1398 calls mvpmipmap_move_mipmap with a0=a0 at entry (arg0), a1=?, a2=a2 at entry (arg2), a3=a3 at entry (arg3), a4=[a0+1520].
  The `jalr` at 0x13b0 calls dms_block_end_dma with a0=[a0+1400], a1=?, a2=0x1, a3=?.
  The `jalr` at 0x13cc calls .text+4432 with a0=a0 at entry (arg0), a1=?, a2=0x1, a3=?.
  The `jalr` at 0x13f8 calls dms_block_detach with a0=[a0+1400], a1=?, a2=?, a3=?, a4=sym(dms_block_detach).
  The `jalr` at 0x1418 calls dms_block_detach with a0=[a0+1404], a1=?, a2=?, a3=?, a5=sym(dms_block_detach).
  The `jalr` at 0x14f0 calls dms_block_end_dma with a0=[a0+1404], a1=?, a2=0x2, a3=a3 at entry (arg3), a4=[a0+1520].
  The `jalr` at 0x1504 calls dms_block_detach with a0=[a0+1404], a1=?, a2=?, a3=?.
  The `jalr` at 0x1548 calls .text+4432 with a0=a0 at entry (arg0), a1=?, a2=0x0, a3=sym(mvptransfer_post_event).
  The `beq` branch at 0x12cc targets 0x1330, is taken when v0(=[a0+1524]) >= a4(=[a0+1520]) (unsigned), and falls through when v0(=[a0+1524]) < a4(=[a0+1520]) (unsigned).
  The `beq` branch at 0x12d8 targets 0x15a8 and is always taken.
  The `beq` branch at 0x12f8 targets 0x1330, is taken when a0(?) >= a4(=[a0+1520]) (unsigned), and falls through when a0(?) < a4(=[a0+1520]) (unsigned).
  The `beq` branch at 0x1314 targets 0x1354, is taken when s2(=0x2) == a0(?), and falls through when s2(=0x2) != a0(?).
  The `bne` branch at 0x131c targets 0x12e0, is taken when s3(=0xa) != a0(?), and falls through when s3(=0xa) == a0(?).
  The `beq` branch at 0x1328 targets 0x12ec and is always taken.
  The `beq` branch at 0x1358 targets 0x14b4, is taken when (a1 & 0x20) == 0, and falls through when (a1 & 0x20) != 0.
  The `beq` branch at 0x1370 targets 0x1494, is taken when t9(=[a0+1192]:1) == 0, and falls through when t9(=[a0+1192]:1) != 0.
  The `beq` branch at 0x1384 targets 0x13a4, is taken when at(=[a0+3042]:1) == 0, and falls through when at(=[a0+3042]:1) != 0.
  The `beq` branch at 0x13b8 targets 0x13e4, is taken when s4(=one of 0x0, 0x1) == 0, and falls through when s4(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x13d4 targets 0x13e4, is taken when v0(=ret(.text+4432)) == 0, and falls through when v0(=ret(.text+4432)) != 0.
  The `beq` branch at 0x13dc targets 0x1338 and is always taken.
  The `beq` branch at 0x13e8 targets 0x1410, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0x1400 targets 0x1428, is taken when v0(=ret(dms_block_detach)) == 0, and falls through when v0(=ret(dms_block_detach)) != 0.
  The `beq` branch at 0x1408 targets 0x1334 and is always taken.
  The `bne` branch at 0x1420 targets 0x1408, is taken when v0(=ret(dms_block_detach)) != 0, and falls through when v0(=ret(dms_block_detach)) == 0.
  The `beq` branch at 0x1444 targets 0x148c, is taken when s4(=one of 0x0, 0x1) == 0, and falls through when s4(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x1458 targets 0x157c, is taken when t2(=[a0+2985]:1) == 0, and falls through when t2(=[a0+2985]:1) != 0.
  The `beq` branch at 0x148c targets 0x1334 and is always taken.
  The `beq` branch at 0x1498 targets 0x14e0, is taken when ra(=[a0+1137]:1) == 0, and falls through when ra(=[a0+1137]:1) != 0.
  The `bne` branch at 0x14a0 targets 0x14e4, is taken when v0(?) != 0, and falls through when v0(?) == 0.
  The `beq` branch at 0x14ac targets 0x1524 and is always taken.
  The `beq` branch at 0x14b4 targets 0x1584, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x14c0 targets 0x158c, is taken when v0(=[a0+1432]) == 0, and falls through when v0(=[a0+1432]) != 0.
  The `beq` branch at 0x14d0 targets 0x1574, is taken when at(=[a0+1436]) >= v0(=[a0+1432]) (unsigned), and falls through when at(=[a0+1436]) < v0(=[a0+1432]) (unsigned).
  The `beq` branch at 0x14d8 targets 0x1364 and is always taken.
  The `beq` branch at 0x150c targets 0x151c, is taken when v0(=ret(dms_block_detach)) == 0, and falls through when v0(=ret(dms_block_detach)) != 0.
  The `beq` branch at 0x1514 targets 0x1338 and is always taken.
  The `beq` branch at 0x152c targets 0x1554, is taken when s4(=one of 0x0, 0x1) == 0, and falls through when s4(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x1554 targets 0x1594, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `bne` branch at 0x1564 targets 0x144c, is taken when s4(=one of 0x0, 0x1) != 0, and falls through when s4(=one of 0x0, 0x1) == 0.
  The `beq` branch at 0x156c targets 0x148c and is always taken.
  The `beq` branch at 0x1574 targets 0x1364 and is always taken.
  The `beq` branch at 0x157c targets 0x1464 and is always taken.
  The `beq` branch at 0x1584 targets 0x1364 and is always taken.
  The `beq` branch at 0x158c targets 0x1364 and is always taken.
  The `beq` branch at 0x15a0 targets 0x1564 and is always taken.
  The `beq` branch at 0x15b4 targets 0x1304 and is always taken.
  The return at 0x134c has v0 = one of ?, ret(.text+4432), ret(dms_block_detach).

- `mvptransfer_sendbuff` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x15bc (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x15bc-0x17a0 (484 bytes).
  It occupies 484 bytes.
  The `lw` at 0x15bc loads 4 bytes from a0 (arg0 at entry) +0x5f4.
  The `lbu` at 0x15d4 loads 1 byte from a0 (arg0 at entry) +0xba9.
  The `lbu` at 0x15e8 loads 1 byte from ?.
  The `lbu` at 0x164c loads 1 byte from a0 (arg0 at entry) +0x4a8.
  The `lbu` at 0x1664 loads 1 byte from a0 (arg0 at entry) +0xbdf.
  4 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0xbaa, including `lbu` at 0x1670, `lbu` at 0x169c, `lbu` at 0x16ec.
  3 such `sb` accesses store 1 byte to ?, including `sb` at 0x172c, `sb` at 0x1770, `sb` at 0x1780.
  The `jalr` at 0x168c calls .text+4772 with a0=a0 at entry (arg0), a1=?, a2=a2 at entry (arg2), a3=a3 at entry (arg3), a6=0x1, a7=0x2.
  The `jalr` at 0x16c0 calls .text+4772 with a0=a0 at entry (arg0), a1=?, a2=sym(mvptransfer_bufferdone), a3=a3 at entry (arg3), a6=0x1, a7=0x2.
  The `jalr` at 0x16dc calls .text+4772 with a0=a0 at entry (arg0), a1=?, a2=?, a3=sym(mvptransfer_bufferdone).
  The `jalr` at 0x1718 calls .text+4772 with a0=a0 at entry (arg0), a1=?, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x175c calls .text+4772 with a0=a0 at entry (arg0), a1=?, a2=a2 at entry (arg2), a3=a3 at entry (arg3), a6=0x1, a7=0x2.
  The `jalr` at 0x1790 calls .text+4772 with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a6=0x1, a7=0x2.
  The `beq` branch at 0x1600 targets 0x16ec, is taken when v0(=[a0+2985]:1) == 0, and falls through when v0(=[a0+2985]:1) != 0.
  The `beq` branch at 0x160c targets 0x164c, is taken when v0(=[a0+2985]:1) == a6(=0x1), and falls through when v0(=[a0+2985]:1) != a6(=0x1).
  The `beq` branch at 0x1614 targets 0x164c, is taken when v0(=[a0+2985]:1) == a7(=0x2), and falls through when v0(=[a0+2985]:1) != a7(=0x2).
  The `beq` branch at 0x161c targets 0x178c, is taken when v0(=[a0+2985]:1) == t0(=0x4), and falls through when v0(=[a0+2985]:1) != t0(=0x4).
  The `beq` branch at 0x1628 targets 0x169c, is taken when v0(=[a0+2985]:1) == t1(=0x3), and falls through when v0(=[a0+2985]:1) != t1(=0x3).
  The `beq` branch at 0x165c targets 0x1738, is taken when t2(=[a0+1192]:1) == 0, and falls through when t2(=[a0+1192]:1) != 0.
  The `bne` branch at 0x1668 targets 0x1684, is taken when t3(=[a0+3039]:1) != 0, and falls through when t3(=[a0+3039]:1) == 0.
  The `bne` branch at 0x1674 targets 0x1684, is taken when t8(=[a0+2986]:1) != t9(?), and falls through when t8(=[a0+2986]:1) == t9(?).
  The `beq` branch at 0x167c targets 0x1730, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x1694 targets 0x1634 and is always taken.
  The `beq` branch at 0x16a8 targets 0x16b4, is taken when v0(=[a0+2986]:1) == v1(?), and falls through when v0(=[a0+2986]:1) != v1(?).
  The `beq` branch at 0x16b0 targets 0x176c, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `bne` branch at 0x16c8 targets 0x1634, is taken when v0(=ret(.text+4772)) != 0, and falls through when v0(=ret(.text+4772)) == 0.
  The `beq` branch at 0x16e4 targets 0x1634 and is always taken.
  The `beq` branch at 0x16fc targets 0x170c, is taken when a6(=[a0+2986]:1) == a7(?), and falls through when a6(=[a0+2986]:1) != a7(?).
  The `beq` branch at 0x1704 targets 0x1728, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x1720 targets 0x1634 and is always taken.
  The `beq` branch at 0x1728 targets 0x1634 and is always taken.
  The `beq` branch at 0x1730 targets 0x1638 and is always taken.
  The `beq` branch at 0x1744 targets 0x1750, is taken when t1(=[a0+2986]:1) == t2(?), and falls through when t1(=[a0+2986]:1) != t2(?).
  The `beq` branch at 0x174c targets 0x177c, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x1764 targets 0x1634 and is always taken.
  The `beq` branch at 0x1774 targets 0x1634 and is always taken.
  The `beq` branch at 0x1784 targets 0x1634 and is always taken.
  The `beq` branch at 0x1798 targets 0x1634 and is always taken.
  The return at 0x1644 has v0 = one of ?, 0x0.

- `mvptransfer_continuing` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x17a0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x17a0-0x17d8 (56 bytes).
  It occupies 56 bytes.
  The `lw` at 0x17a0 loads 4 bytes from a0 (arg0 at entry) +0x598.
  The `lbu` at 0x17ac loads 1 byte from a0 (arg0 at entry) +0xba9.
  The `lw` at 0x17b0 loads 4 bytes from a0 (arg0 at entry) +0x59c.
  The `beq` branch at 0x17a4 targets 0x17cc, is taken when v0(=[a0+1432]) == 0, and falls through when v0(=[a0+1432]) != 0.
  The `beq` branch at 0x17c4 targets 0x17d0, is taken when at(?) >= v0(=[a0+1432]) (unsigned), and falls through when at(?) < v0(=[a0+1432]) (unsigned).
  The return at 0x17d0 has v0 = one of 0x0, 0x1.

- `mvptransfer_enablechannel` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x17d8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x17d8-0x1884 (172 bytes).
  It occupies 172 bytes.
  The `lbu` at 0x17dc loads 1 byte from a0 (arg0 at entry) +0x4a8.
  The `lbu` at 0x17f4 loads 1 byte from a0 (arg0 at entry) +0x46c.
  The `lw` at 0x1800 loads 4 bytes from sym(mvpcontroller_table) +0x0.
  The `lw` at 0x1818 loads 4 bytes from ([sym(mvpcontroller_table)] + ([a0+1132]:1 << 0x2)) +0xc0.
  The `ld` at 0x1834 loads 8 bytes from ?.
  The `sd` at 0x185c stores 8 bytes to ?.
  The `sd` at 0x1860 stores 8 bytes to [([sym(mvpcontroller_table)] + ([a0+1132]:1 << 0x2))+192] +0x0.
  The `jalr` at 0x1824 calls splhi with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x186c calls splx with a0=ret(splhi), a1=?, a2=?, a3=?, a5=[([sym(mvpcontroller_table)] + ([a0+1132]:1 << 0x2))+192], a6=sym(splx), a7=-0x200.
  The `beq` branch at 0x17ec targets 0x1874, is taken when at(=[a0+1192]:1) == v0(=0x2), and falls through when at(=[a0+1192]:1) != v0(=0x2).
  The `beq` branch at 0x1844 targets 0x1854, is taken when t8(=a1) == t9(=-0x1), and falls through when t8(=a1) != t9(=-0x1).
  The `beq` branch at 0x1854 targets 0x1864, is taken when a5(?) == a4(?), and falls through when a5(?) != a4(?).
  The return at 0x187c has v0 = one of 0x2, ret(splx).

- `mvptransfer_getustmsc` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x1884 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x1884-0x19e0 (348 bytes).
  It occupies 348 bytes.
  4 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x46c, including `lbu` at 0x1890, `lbu` at 0x18e4, `lbu` at 0x190c.
  The `lw` at 0x18b0 loads 4 bytes from sym(mvpcontroller_table) +0x0.
  2 such `lw` accesses load 4 bytes from sym(mvp_umba) +0x0, including `lw` at 0x18bc, `lw` at 0x19cc.
  The `lw` at 0x18f0 loads 4 bytes from ([sym(mvpcontroller_table)] + ([a0+1132]:1 << 0x4)) +0x24.
  The `lw` at 0x1900 loads 4 bytes from ([sym(mvpcontroller_table)] + ([a0+1132]:1 << 0x4)) +0x20.
  The `sw` at 0x1908 stores 4 bytes to ([sym(mvpcontroller_table)] + ([a0+1132]:1 << 0x4)) +0x20.
  The `sw` at 0x1918 stores 4 bytes to ([sym(mvpcontroller_table)] + ([a0+1132]:1 << 0x4)) +0x24.
  The `ld` at 0x1930 loads 8 bytes from ([sym(mvpcontroller_table)] + ([a0+1132]:1 << 0x4)) +0x20.
  2 such `sd` accesses store 8 bytes to a1 (arg1 at entry) +0x8, including `sd` at 0x193c, `sd` at 0x19b8.
  The `lbu` at 0x1988 loads 1 byte from a0 (arg0 at entry) +0xbdf.
  The `lbu` at 0x1994 loads 1 byte from a0 (arg0 at entry) +0xba9.
  The `sd` at 0x19ac stores 8 bytes to a1 (arg1 at entry) +0x0.
  The `lw` at 0x19d0 loads 4 bytes from [sym(mvpcontroller_table)] +0x54.
  The `jalr` at 0x18cc calls pciio_pio_read64 with a0=([sym(mvp_umba)] + ([a0+1132]:1 << 0x3))+56, a1=sym(pciio_pio_read64), a2=([a0+1132]:1 << 0x3), a3=[a0+1132]:1.
  The `jalr` at 0x1938 calls fill_ust_highbits with a0=?, a1=sp-40, a2=?, a3=([sym(mvpcontroller_table)] + ([a0+1132]:1 << 0x4)), a6=[([sym(mvpcontroller_table)] + ([a0+1132]:1 << 0x4))+32]:8, a7=sym(fill_ust_highbits).
  The `jalr` at 0x194c calls ust_to_nano with a0=?, a1=a1 at entry (arg1), a2=?, a3=?, a7=sym(ust_to_nano).
  The `jalr` at 0x1978 calls crime_getustmsc with a0=0x0, a1=sp-80, a2=a2 at entry (arg2), a3=[a0+1132]:1.
  The `jalr` at 0x19c8 calls pciio_pio_read64 with a0=[sym(mvp_umba)], a1=sym(pciio_pio_read64), a2=?, a3=?.
  The `beq` branch at 0x18ac targets 0x196c, is taken when a3(=[a0+1132]:1) == at(=0x3), and falls through when a3(=[a0+1132]:1) != at(=0x3).
  The `beq` branch at 0x18f8 targets 0x1918, is taken when a4(?) >= a1(=[([sym(mvpcontroller_table)] + ([a0+1132]:1 << 0x4))+36]) (unsigned), and falls through when a4(?) < a1(=[([sym(mvpcontroller_table)] + ([a0+1132]:1 << 0x4))+36]) (unsigned).
  The `bne` branch at 0x1980 targets 0x19bc, is taken when v0(=ret(crime_getustmsc)) != 0, and falls through when v0(=ret(crime_getustmsc)) == 0.
  The `beq` branch at 0x198c targets 0x19ac, is taken when t1(=[a0+3039]:1) == 0, and falls through when t1(=[a0+3039]:1) != 0.
  The `beq` branch at 0x19b4 targets 0x1954 and is always taken.
  The `beq` branch at 0x19d8 targets 0x18e4 and is always taken.
  The return at 0x1964 has v0 = one of ret(ust_to_nano), ret(crime_getustmsc).

- `mvptransfer_screen_interrupt` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x19e0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x19e0-0x21cc (2028 bytes).
  It occupies 2028 bytes.
  The `lw` at 0x1a00 loads 4 bytes from sym(mvpcontroller_table) +0x0.
  2 such `lw` accesses load 4 bytes from sym(mvpinterrupt_active) +0x0, including `lw` at 0x1a04, `lw` at 0x1b44.
  The `lw` at 0x1a08 loads 4 bytes from [sym(mvpcontroller_table)] +0xcc.
  2 such `sw` accesses store 4 bytes to sym(mvpinterrupt_active) +0x0, including `sw` at 0x1a10, `sw` at 0x1b58.
  3 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x467, including `lbu` at 0x1a1c, `lbu` at 0x1a70, `lbu` at 0x1a94.
  The `lw` at 0x1a4c loads 4 bytes from [[sym(mvpcontroller_table)]+204] +0xc.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x48c, including `sw` at 0x1a50, `sw` at 0x1b7c.
  The `lw` at 0x1a6c loads 4 bytes from a0 (arg0 at entry) +0x5b4.
  The `lw` at 0x1aa8 loads 4 bytes from [sym(mvpcontroller_table)] +0x320.
  The `lw` at 0x1ab4 loads 4 bytes from (sym(.rodata)+40 + ([a0+1127]:1 << 0x2)) +0x0.
  5 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x48c, including `lw` at 0x1ac4, `lw` at 0x1aec, `lw` at 0x1b70.
  The `lbu` at 0x1acc loads 1 byte from ?.
  The `lw` at 0x1af0 loads 4 bytes from a0 (arg0 at entry) +0x484.
  The `ld` at 0x1af4 loads 8 bytes from a0 (arg0 at entry) +0x5b0.
  The `sd` at 0x1af8 stores 8 bytes to a0 (arg0 at entry) +0x5c0.
  The `ld` at 0x1b00 loads 8 bytes from a0 (arg0 at entry) +0x5a8.
  The `sd` at 0x1b08 stores 8 bytes to a0 (arg0 at entry) +0x5b8.
  The `lbu` at 0x1b6c loads 1 byte from a0 (arg0 at entry) +0x47a.
  The `lw` at 0x1b8c loads 4 bytes from a0 (arg0 at entry) +0x61c.
  The `sb` at 0x1b98 stores 1 byte to a0 (arg0 at entry) +0x47a.
  The `lbu` at 0x1bb0 loads 1 byte from a0 (arg0 at entry) +0xbdf.
  The `lbu` at 0x1bbc loads 1 byte from a0 (arg0 at entry) +0xbaa.
  The `jalr` at 0x1a64 calls .text+6276 with a0=a0 at entry (arg0), a1=a0+1448, a2=0x0, a3=a3 at entry (arg3), a5=0x0, a6=sym(mvpinterrupt_active), a7=[sym(mvpinterrupt_active)]+1.
  Calls (unknown callee) via register with a0=(sym(.rodata)+40 + ([a0+1127]:1 << 0x2)), a1=[(sym(.rodata)+40 + ([a0+1127]:1 << 0x2))], a2=sym(mvptransfer_stop), a3=? (`jr` at 0x1ab8).
  The `jalr` at 0x1b18 calls .text+4156 with a0=a0 at entry (arg0), a1=?, a2=0x0, a3=[a0+1448]:8, a5=[a0+1456]:8, a6=sym(mvptransfer_send_events).
  The `jalr` at 0x1b64 calls mvptransfer_stop with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0x0, a3=a3 at entry (arg3), a5=0x0, a6=sym(mvpinterrupt_active), a7=[sym(mvpinterrupt_active)]+1.
  The `jalr` at 0x1b88 calls sv_signal with a0=[a0+1564], a1=([a0+1164] | 0x100), a2=sym(sv_signal), a3=?.
  The `jalr` at 0x1ba0 calls .text+52 with a0=a0 at entry (arg0), a1=?, a2=?, a3=sym(mvptransfer_too_many_errors).
  The `jalr` at 0x1be8 calls .text+52 with a0=a0 at entry (arg0), a1=?, a2=?, a3=?, a4=[a0+3039]:1, a5=[a0+2986]:1, a7=sym(mvptransfer_too_many_errors).
  The `beq` branch at 0x1a3c targets 0x1b5c, is taken when at(=[a0+1127]:1) == v1(=0x3), and falls through when at(=[a0+1127]:1) != v1(=0x3).
  The `beq` branch at 0x1a80 targets 0x1ac8, is taken when a0(=0xd) == v0(=[a0+1127]:1), and falls through when a0(=0xd) != v0(=[a0+1127]:1).
  The `beq` branch at 0x1a8c targets 0x1acc, is taken when v0(=[a0+1127]:1) == t8(=0xa), and falls through when v0(=[a0+1127]:1) != t8(=0xa).
  The `beq` branch at 0x1aac targets 0x1ac0, is taken when v0(=[a0+1127]:1) >= 0xe (unsigned), and falls through when v0(=[a0+1127]:1) < 0xe (unsigned).
  The `beq` branch at 0x1ac0 targets 0x1af0 and is always taken.
  The `bne` branch at 0x1ad8 targets 0x1b9c, is taken when a2(?) != a3(?), and falls through when a2(?) == a3(?).
  The `bne` branch at 0x1ae4 targets 0x1bb0, is taken when s4(?) < 0x1 (unsigned), and falls through when s4(?) >= 0x1 (unsigned).
  The `beq` branch at 0x1b04 targets 0x1b20, is taken when (a1(?) & a4(=[a0+1156])) == 0, and falls through when (a1(?) & a4(=[a0+1156])) != 0.
  The `beq` branch at 0x1b78 targets 0x1af0, is taken when t2(=[a0+1146]:1) == 0, and falls through when t2(=[a0+1146]:1) != 0.
  The `beq` branch at 0x1b94 targets 0x1af0 and is always taken.
  The `beq` branch at 0x1ba8 targets 0x1ae0 and is always taken.
  The `beq` branch at 0x1bb4 targets 0x1bc8, is taken when a4(=[a0+3039]:1) == 0, and falls through when a4(=[a0+3039]:1) != 0.
  The `bne` branch at 0x1bc0 targets 0x1be0, is taken when a5(=[a0+2986]:1) != s2(?), and falls through when a5(=[a0+2986]:1) == s2(?).
  The `beq` branch at 0x1bc8 targets 0x1aec, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x1bd0 targets 0x1a94, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `beq` branch at 0x1bd8 targets 0x1af0 and is always taken.
  The `beq` branch at 0x1bf8 targets 0x1bc8 and is always taken.
  The return at 0x1b54 has v0 = one of ?, ret(.text+4156).
  The instructions from 0x1c00 to 0x21c8 are not reached by any path from the entry, and their branches are not listed.
  The indirect jump at 0x1ab8 uses a jump table whose successors are unresolved.

- `mvptransfer_fix_output` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x21cc (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x21cc-0x226c (160 bytes).
  It occupies 160 bytes.
  The `lw` at 0x21e8 loads 4 bytes from sym(mvpcontroller_table) +0x0.
  The `lw` at 0x21f4 loads 4 bytes from [sym(mvpcontroller_table)] +0xc8.
  2 such `ld` accesses load 8 bytes from [sym(mvpcontroller_table)] +0x258, including `ld` at 0x2200, `ld` at 0x2220.
  2 such `sd` accesses store 8 bytes to [sym(mvpcontroller_table)] +0x258, including `sd` at 0x2214, `sd` at 0x2230.
  2 such `sd` accesses store 8 bytes to [[sym(mvpcontroller_table)]+200] +0x0, including `sd` at 0x2218, `sd` at 0x2234.
  2 such `sd` accesses store 8 bytes to [[sym(mvpcontroller_table)]+200] +0x18, including `sd` at 0x221c, `sd` at 0x2254.
  The `lw` at 0x223c loads 4 bytes from a0 (arg0 at entry) +0x488.
  The `jalr` at 0x21f8 calls splhi with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x2250 calls splx with a0=ret(splhi), a1=?, a2=?, a3=[[sym(mvpcontroller_table)]+600]:8, a5=[[sym(mvpcontroller_table)]+600]:8, a6=0x0, a7=sym(splx).
  The `beq` branch at 0x220c targets 0x221c, is taken when a4(?) == a3(=[[sym(mvpcontroller_table)]+600]:8), and falls through when a4(?) != a3(=[[sym(mvpcontroller_table)]+600]:8).
  The `beq` branch at 0x2228 targets 0x2238, is taken when a5(=[[sym(mvpcontroller_table)]+600]:8) == v0(=([[sym(mvpcontroller_table)]+600]:8 | 0x1)), and falls through when a5(=[[sym(mvpcontroller_table)]+600]:8) != v0(=([[sym(mvpcontroller_table)]+600]:8 | 0x1)).
  The return at 0x2264 has v0 = ret(splx).

- `mvptransfer_cleardma` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x226c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x226c-0x2310 (164 bytes).
  It occupies 164 bytes.
  The `lbu` at 0x226c loads 1 byte from a0 (arg0 at entry) +0x4a8.
  The `lw` at 0x2288 loads 4 bytes from sym(mvpcontroller_table) +0x0.
  The `lw` at 0x229c loads 4 bytes from [sym(mvpcontroller_table)] +0xc8.
  The `ld` at 0x22ac loads 8 bytes from [sym(mvpcontroller_table)] +0x278.
  The `sd` at 0x22bc stores 8 bytes to [sym(mvpcontroller_table)] +0x278.
  The `sd` at 0x22c0 stores 8 bytes to [[sym(mvpcontroller_table)]+200] +0x20.
  The `ld` at 0x22c4 loads 8 bytes from [sym(mvpcontroller_table)] +0x258.
  3 such `sd` accesses store 8 bytes to [[sym(mvpcontroller_table)]+200] +0x0, including `sd` at 0x22d0, `sd` at 0x22e0, `sd` at 0x22f4.
  The `sd` at 0x22d4 stores 8 bytes to [[sym(mvpcontroller_table)]+200] +0x18.
  The `sd` at 0x22e8 stores 8 bytes to [sym(mvpcontroller_table)] +0x258.
  The `jalr` at 0x22a0 calls splhi with a0=[sym(mvpcontroller_table)]+600, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x22f0 calls pciio_pio_read64 with a0=[[sym(mvpcontroller_table)]+200]+8, a1=?, a2=sym(pciio_pio_read64), a3=[sym(mvpcontroller_table)]+600, a4=[[sym(mvpcontroller_table)]+200], a5=([[sym(mvpcontroller_table)]+600]:8 | 0x1).
  The `jalr` at 0x2300 calls splx with a0=ret(splhi), a1=?, a2=sym(splx), a3=?.
  The `beq` branch at 0x2274 targets 0x2284, is taken when at(=[a0+1192]:1) == 0, and falls through when at(=[a0+1192]:1) != 0.
  The `beq` branch at 0x22b4 targets 0x22c4, is taken when v1(=[[sym(mvpcontroller_table)]+632]:8) == 0, and falls through when v1(=[[sym(mvpcontroller_table)]+632]:8) != 0.
  The `beq` branch at 0x2308 targets 0x227c and is always taken.
  The return at 0x227c has v0 = one of ?, ret(splx).

- `mvptransfer_startup` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x2310 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x2310-0x2464 (340 bytes).
  It occupies 340 bytes.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x48c, including `lw` at 0x2358, `lw` at 0x23dc, `lw` at 0x2444.
  3 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x48c, including `sw` at 0x2364, `sw` at 0x23ec, `sw` at 0x2458.
  The `lbu` at 0x238c loads 1 byte from a0 (arg0 at entry) +0x46d.
  2 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0xba9, including `lbu` at 0x2398, `lbu` at 0x2424.
  2 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x467, including `sb` at 0x23f4, `sb` at 0x2434.
  The `jalr` at 0x233c calls .text+1316 with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=a2 at entry (arg2).
  The `jalr` at 0x2350 calls mvptransfer_stop with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jalr` at 0x2384 calls mvptransfer_enablechannel with a0=a0 at entry (arg0), a1=0x3, a2=?, a3=?.
  The `jalr` at 0x23c0 calls .text+1316 with a0=a0 at entry (arg0), a1=?, a2=?, a3=0x3, a4=sym(mvptransfer_start_dma).
  The `jalr` at 0x23d4 calls mvptransfer_stop with a0=a0 at entry (arg0), a1=?, a2=?, a3=?, a5=sym(mvptransfer_stop).
  The `jalr` at 0x2414 calls .text+3456 with a0=a0 at entry (arg0), a1=0x0, a2=[a0+1133]:1, a3=?.
  The `jalr` at 0x2454 calls mvptransfer_stop with a0=a0 at entry (arg0), a1=ret(.text+3456), a2=?, a3=?.
  The `beq` branch at 0x2344 targets 0x2378, is taken when v0(=ret(.text+1316)) == 0, and falls through when v0(=ret(.text+1316)) != 0.
  The `beq` branch at 0x2390 targets 0x2408, is taken when a2(=[a0+1133]:1) == 0, and falls through when a2(=[a0+1133]:1) != 0.
  The `beq` branch at 0x23a4 targets 0x2400, is taken when a3(=0x1) == a0(=[a0+2985]:1), and falls through when a3(=0x1) != a0(=[a0+2985]:1).
  The `beq` branch at 0x23ac targets 0x2400, is taken when a0(=[a0+2985]:1) == v0(=0x2), and falls through when a0(=[a0+2985]:1) != v0(=0x2).
  The `beq` branch at 0x23c8 targets 0x23f0, is taken when v0(=ret(.text+1316)) == 0, and falls through when v0(=ret(.text+1316)) != 0.
  The `beq` branch at 0x23e8 targets 0x2368 and is always taken.
  The `beq` branch at 0x23f8 targets 0x2368 and is always taken.
  The `beq` branch at 0x2400 targets 0x23b4 and is always taken.
  The `bne` branch at 0x241c targets 0x2398, is taken when v0(=ret(.text+3456)) != 0, and falls through when v0(=ret(.text+3456)) == 0.
  The `beq` branch at 0x242c targets 0x2440, is taken when t1(=[a0+2985]:1) == t2(=0x3), and falls through when t1(=[a0+2985]:1) != t2(=0x3).
  The `beq` branch at 0x2438 targets 0x2368 and is always taken.
  The `beq` branch at 0x245c targets 0x2368 and is always taken.
  The return at 0x2370 has v0 = one of 0x0, 0x1.

- `mvptransfer_timeout` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x2464 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x2464-0x250c (168 bytes).
  It occupies 168 bytes.
  2 such `lw` accesses load 4 bytes from sym(mvpmutex_locked) +0x0, including `lw` at 0x2490, `lw` at 0x24f8.
  2 such `sw` accesses store 4 bytes to sym(mvpmutex_locked) +0x0, including `sw` at 0x2498, `sw` at 0x2508.
  The `lw` at 0x249c loads 4 bytes from a0 (arg0 at entry) +0x610.
  The `sw` at 0x24d0 stores 4 bytes to a0 (arg0 at entry) +0x610.
  The `jalr` at 0x2484 calls mutex_lock with a0=sym(mvpmutex), a1=0x0, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x24b0 calls untimeout with a0=[a0+1552], a1=[sym(mvpmutex_locked)]+1, a2=sym(untimeout), a3=?, a4=sym(mutex_unlock).
  The `jalr` at 0x24cc calls .text+4156 with a0=a0 at entry (arg0), a1=0x40, a2=0x0, a3=sym(mvptransfer_send_events).
  The `jalr` at 0x24e4 calls mutex_unlock with a0=sym(mvpmutex), a1=?, a2=?, a3=?, a4=sym(mutex_unlock).
  The `beq` branch at 0x24a0 targets 0x24d8, is taken when a0(=[a0+1552]) == 0, and falls through when a0(=[a0+1552]) != 0.
  The return at 0x2504 has v0 = ret(mutex_unlock).

- `mvptransfer_interrupt` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x250c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x250c-0x367c (4464 bytes).
  It occupies 4464 bytes.
  4 such `lw` accesses load 4 bytes from sym(mvpcontroller_table) +0x0, including `lw` at 0x2560, `lw` at 0x2a28, `lw` at 0x2a58.
  The `lw` at 0x2578 loads 4 bytes from ([sym(mvpcontroller_table)] + (a1 << 0x2)) +0xc0.
  7 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x467, including `lbu` at 0x2598, `lbu` at 0x262c, `lbu` at 0x2878.
  The `lw` at 0x25b8 loads 4 bytes from a0 (arg0 at entry) +0x610.
  The `lbu` at 0x25d0 loads 1 byte from a0 (arg0 at entry) +0x480.
  The `lw` at 0x2604 loads 4 bytes from sym(mvp_umba) +0x10.
  The `sw` at 0x2608 stores 4 bytes to a0 (arg0 at entry) +0x610.
  8 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x48c, including `sw` at 0x2620, `sw` at 0x267c, `sw` at 0x2798.
  The `ld` at 0x2644 loads 8 bytes from a0 (arg0 at entry) +0x5c0.
  The `ld` at 0x2650 loads 8 bytes from a0 (arg0 at entry) +0x5b8.
  The `ld` at 0x2660 loads 8 bytes from a0 (arg0 at entry) +0x5c8.
  12 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x48c, including `lw` at 0x266c, `lw` at 0x2780, `lw` at 0x27a4.
  The `lbu` at 0x26a8 loads 1 byte from a0 (arg0 at entry) +0x47f.
  2 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x47f, including `sb` at 0x26c0, `sb` at 0x26cc.
  The `lbu` at 0x26d8 loads 1 byte from a0 (arg0 at entry) +0x47d.
  The `lbu` at 0x26e4 loads 1 byte from a0 (arg0 at entry) +0xbaa.
  The `sd` at 0x26f8 stores 8 bytes to a0 (arg0 at entry) +0x5a8.
  The `sd` at 0x2700 stores 8 bytes to a0 (arg0 at entry) +0x5b0.
  2 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x4a8, including `lbu` at 0x2710, `lbu` at 0x281c.
  The `lbu` at 0x2774 loads 1 byte from a0 (arg0 at entry) +0x47e.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x484, including `lw` at 0x27a8, `lw` at 0x280c.
  The `sd` at 0x27b4 stores 8 bytes to a0 (arg0 at entry) +0x5b8.
  The `sd` at 0x27c4 stores 8 bytes to a0 (arg0 at entry) +0x5c0.
  7 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x460, including `lw` at 0x2824, `lw` at 0x2834, `lw` at 0x2a4c.
  The `sb` at 0x2830 stores 1 byte to [a0+1120] +0xa.
  The `lbu` at 0x2838 loads 1 byte from [a0+1120] +0x8.
  The `sb` at 0x2848 stores 1 byte to [a0+1120] +0x8.
  The `lbu` at 0x2890 loads 1 byte from a0 (arg0 at entry) +0x47c.
  The `lbu` at 0x28cc loads 1 byte from a0 (arg0 at entry) +0x47b.
  The `lbu` at 0x28e4 loads 1 byte from a0 (arg0 at entry) +0x47a.
  The `lw` at 0x2904 loads 4 bytes from a0 (arg0 at entry) +0x61c.
  The `sb` at 0x2910 stores 1 byte to a0 (arg0 at entry) +0x47a.
  The `lw` at 0x295c loads 4 bytes from table(sym(mvptransfer_stats)) +0xc.
  The `sw` at 0x296c stores 4 bytes to table(sym(mvptransfer_stats)) +0xc.
  The `lw` at 0x2980 loads 4 bytes from table(sym(mvptransfer_stats)) +0x10.
  The `sw` at 0x2990 stores 4 bytes to table(sym(mvptransfer_stats)) +0x10.
  3 such `lw` accesses load 4 bytes from sym(mvpignore_framing_errors) +0x0, including `lw` at 0x29a0, `lw` at 0x29d0, `lw` at 0x29fc.
  The `lw` at 0x29a8 loads 4 bytes from table(sym(mvptransfer_stats)) +0x14.
  The `sw` at 0x29b4 stores 4 bytes to table(sym(mvptransfer_stats)) +0x14.
  The `lw` at 0x29d8 loads 4 bytes from table(sym(mvptransfer_stats)) +0x18.
  The `sw` at 0x29e4 stores 4 bytes to table(sym(mvptransfer_stats)) +0x18.
  The `lw` at 0x2a04 loads 4 bytes from table(sym(mvptransfer_stats)) +0x1c.
  The `sw` at 0x2a10 stores 4 bytes to table(sym(mvptransfer_stats)) +0x1c.
  The `lbu` at 0x2a20 loads 1 byte from [a0+1120] +0xb.
  The `lbu` at 0x2a30 loads 1 byte from [a0+1120] +0xa.
  The `lw` at 0x2a34 loads 4 bytes from a0 (arg0 at entry) +0xba0.
  The `lw` at 0x2a38 loads 4 bytes from [a0+2976] +0x4.
  2 such `lbu` accesses load 1 byte from [a0+1120] +0x9, including `lbu` at 0x2a50, `lbu` at 0x2a7c.
  The `lw` at 0x2a6c loads 4 bytes from [sym(mvpcontroller_table)] +0xc8.
  3 such `ld` accesses load 8 bytes from ?, including `ld` at 0x2a94, `ld` at 0x2c14, `ld` at 0x2c3c.
  The `lw` at 0x2ac8 loads 4 bytes from table(sym(mvptransfer_stats)) +0x8.
  The `sw` at 0x2ad0 stores 4 bytes to table(sym(mvptransfer_stats)) +0x8.
  The `lw` at 0x2b18 loads 4 bytes from (sym(.rodata)+96 + ([a0+1127]:1 << 0x2)) +0x0.
  The `lbu` at 0x2b2c loads 1 byte from a0 (arg0 at entry) +0xba9.
  The `sd` at 0x2b54 stores 8 bytes to ([sym(mvpcontroller_table)] + (a1 << 0x4)) +0x20.
  The `lw` at 0x2b58 loads 4 bytes from sym(mvp_umba) +0x0.
  The `sw` at 0x2b68 stores 4 bytes to ([sym(mvp_umba)] + (a1 << 0x3)) +0x38.
  The `sb` at 0x2bb0 stores 1 byte to a0 (arg0 at entry) +0x47b.
  2 such `sb` accesses store 1 byte to [a0+1120] +0x70, including `sb` at 0x2c10, `sb` at 0x2c38.
  4 such `sd` accesses store 8 bytes to ?, including `sd` at 0x2c24, `sd` at 0x2c28, `sd` at 0x2c50.
  2 such `sb` accesses store 1 byte to [a0+1120] +0x9, including `sb` at 0x2c34, `sb` at 0x2c60.
  The `lw` at 0x2c6c loads 4 bytes from [sym(mvpcontroller_table)] +0xc0.
  The `jalr` at 0x2588 calls pciio_pio_read64 with a0=[([sym(mvpcontroller_table)] + (a1 << 0x2))+192]+8, a1=(a1 << 0x2), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x25c8 calls untimeout with a0=[a0+1552], a1=0x3, a2=[a0+1127]:1, a3=sym(untimeout).
  The `jalr` at 0x2600 calls itimeout with a0=sym(mvptransfer_timeout), a1=a0 at entry (arg0), a2=[sym(mvptransfer_timeout_len)], a3=sym(mvpdummy_spl), a4=sym(itimeout).
  The `jalr` at 0x2624 calls .text+6276 with a0=a0 at entry (arg0), a1=sp-248, a2=?, a3=?.
  The `jalr` at 0x2794 calls .text+52 with a0=a0 at entry (arg0), a1=sym(mvptransfer_too_many_errors), a2=([a0+1164] | 0x800000), a3=0x800000.
  The `jalr` at 0x27d4 calls .text+4156 with a0=a0 at entry (arg0), a1=?, a2=0x0, a3=?, a5=sym(mvptransfer_send_events).
  The `jalr` at 0x2868 calls mvppath_send_available with a0=a0 at entry (arg0), a1=0x10000, a2=([a0+1164] | 0x10000), a3=sym(mvppath_send_available), a4=0x10000, a5=[a0+1120].
  The `jalr` at 0x28dc calls mvptransfer_stop with a0=a0 at entry (arg0), a1=0x3, a2=[a0+1127]:1, a3=?.
  The `jalr` at 0x2900 calls sv_signal with a0=[a0+1564], a1=([a0+1164] | 0x100), a2=sym(sv_signal), a3=?.
  The `jalr` at 0x2938 calls mvpinterrupt_setup with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0x0, a3=0x0, a4=sym(mvpinterrupt_setup).
  The `jalr` at 0x2a70 calls splhi with a0=?, a1=?, a2=?, a3=?.
  The `jalr` at 0x2aa4 calls splx with a0=ret(splhi), a1=?, a2=?, a3=?, a5=[a0+1120], a7=[[a0+1120]+9]:1.
  The `jalr` at 0x2af4 calls mvptransfer_enablechannel with a0=a0 at entry (arg0), a1=0x3, a2=?, a3=?, a4=sym(mvptransfer_enablechannel), a5=[a0+1148]:1, a6=(ret(pciio_pio_read64) << 0x3d).
  Calls (unknown callee) via register with a0=(sym(.rodata)+96 + ([a0+1127]:1 << 0x2)), a1=([a0+1127]:1 << 0x2), a2=?, a3=[(sym(.rodata)+96 + ([a0+1127]:1 << 0x2))], a4=(ret(pciio_pio_read64) << 0x3d) (`jr` at 0x2b1c).
  The `jalr` at 0x2b9c calls mvptransfer_enablechannel with a0=a0 at entry (arg0), a1=0x2, a2=[a0+1127]:1, a3=sym(mvptransfer_enablechannel).
  The `jalr` at 0x2c70 calls pciio_pio_read64 with a0=[[sym(mvpcontroller_table)]+192]+8, a1=sym(pciio_pio_read64), a2=?, a3=?, a5=[a0+1120], a6=([a0+1156] << 0x2f), a7=[a0+1192]:1.
  The `beq` branch at 0x25b0 targets 0x28c0, is taken when a1(=0x3) == a2(=[a0+1127]:1), and falls through when a1(=0x3) != a2(=[a0+1127]:1).
  The `beq` branch at 0x25bc targets 0x25d0, is taken when a0(=[a0+1552]) == 0, and falls through when a0(=[a0+1552]) != 0.
  The `beq` branch at 0x25d4 targets 0x260c, is taken when a4(=[a0+1152]:1) == 0, and falls through when a4(=[a0+1152]:1) != 0.
  The `beq` branch at 0x2638 targets 0x26a4, is taken when v0(=0x4) >= v1(=[a0+1127]:1) (signed), and falls through when v0(=0x4) < v1(=[a0+1127]:1) (signed).
  The `beq` branch at 0x2658 targets 0x2ae4, is taken when s3(=0x1) == a5(?), and falls through when s3(=0x1) != a5(?).
  The `beq` branch at 0x2680 targets 0x2b24, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `bltz` branch at 0x268c targets 0x2b2c, is taken when a2(=(ret(pciio_pio_read64) << 0x3d)) < 0 (signed), and falls through when a2(=(ret(pciio_pio_read64) << 0x3d)) >= 0 (signed).
  The `beq` branch at 0x2694 targets 0x2b84, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `beq` branch at 0x269c targets 0x26a8 and is always taken.
  The `beq` branch at 0x26c4 targets 0x26d0, is taken when s5(?) == t8(?), and falls through when s5(?) != t8(?).
  The `beq` branch at 0x26d0 targets 0x2708, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x26dc targets 0x26f4, is taken when t9(=[a0+1149]:1) == 0, and falls through when t9(=[a0+1149]:1) != 0.
  The `bne` branch at 0x26e8 targets 0x2708, is taken when ra(=[a0+2986]:1) != s5(?), and falls through when ra(=[a0+2986]:1) == s5(?).
  The `bltz` branch at 0x2708 targets 0x2914, is taken when s7(=(ret(pciio_pio_read64) << 0x3e)) < 0 (signed), and falls through when s7(=(ret(pciio_pio_read64) << 0x3e)) >= 0 (signed).
  The `beq` branch at 0x2714 targets 0x28ac, is taken when v1(=[a0+1192]:1) == 0, and falls through when v1(=[a0+1192]:1) != 0.
  The `beq` branch at 0x2720 targets 0x28b4, is taken when (v0(?) & 0x1f8) == 0, and falls through when (v0(?) & 0x1f8) != 0.
  The `bltz` branch at 0x2728 targets 0x2ab4, is taken when a1(=(ret(pciio_pio_read64) << 0x3c)) < 0 (signed), and falls through when a1(=(ret(pciio_pio_read64) << 0x3c)) >= 0 (signed).
  The `bltz` branch at 0x2738 targets 0x2948, is taken when t8(=(ret(pciio_pio_read64) << 0x37)) < 0 (signed), and falls through when t8(=(ret(pciio_pio_read64) << 0x37)) >= 0 (signed).
  The `bltz` branch at 0x2744 targets 0x2970, is taken when t9(=(ret(pciio_pio_read64) << 0x38)) < 0 (signed), and falls through when t9(=(ret(pciio_pio_read64) << 0x38)) >= 0 (signed).
  The `bltz` branch at 0x2750 targets 0x2994, is taken when ra(=(ret(pciio_pio_read64) << 0x39)) < 0 (signed), and falls through when ra(=(ret(pciio_pio_read64) << 0x39)) >= 0 (signed).
  The `bltz` branch at 0x2760 targets 0x29c4, is taken when at(=(ret(pciio_pio_read64) << 0x3a)) < 0 (signed), and falls through when at(=(ret(pciio_pio_read64) << 0x3a)) >= 0 (signed).
  The `bltz` branch at 0x276c targets 0x29f4, is taken when v0(=(ret(pciio_pio_read64) << 0x3b)) < 0 (signed), and falls through when v0(=(ret(pciio_pio_read64) << 0x3b)) >= 0 (signed).
  The `beq` branch at 0x2778 targets 0x280c, is taken when v1(=[a0+1150]:1) == 0, and falls through when v1(=[a0+1150]:1) != 0.
  The `beq` branch at 0x279c targets 0x280c, is taken when v0(=ret(.text+52)) == 0, and falls through when v0(=ret(.text+52)) != 0.
  The `beq` branch at 0x27c0 targets 0x27dc, is taken when (a1(?) & a3(=[a0+1156])) == 0, and falls through when (a1(?) & a3(=[a0+1156])) != 0.
  The `bgez` branch at 0x2814 targets 0x2a34, is taken when a6(=([a0+1156] << 0x2f)) >= 0 (signed), and falls through when a6(=([a0+1156] << 0x2f)) < 0 (signed).
  The `beq` branch at 0x2820 targets 0x2a20, is taken when a7(=[a0+1192]:1) == 0, and falls through when a7(=[a0+1192]:1) != 0.
  The `beq` branch at 0x283c targets 0x2870, is taken when a1(=[[a0+1120]+8]:1) == a0(?), and falls through when a1(=[[a0+1120]+8]:1) != a0(?).
  The `beq` branch at 0x2844 targets 0x2870, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `bltz` branch at 0x2870 targets 0x2a4c, is taken when s7(=(ret(pciio_pio_read64) << 0x3e)) < 0 (signed), and falls through when s7(=(ret(pciio_pio_read64) << 0x3e)) >= 0 (signed).
  The `bne` branch at 0x2880 targets 0x2928, is taken when v0(=[a0+1127]:1) < 0x3 (signed), and falls through when v0(=[a0+1127]:1) >= 0x3 (signed).
  The `bltz` branch at 0x2888 targets 0x2b04, is taken when s7(=(ret(pciio_pio_read64) << 0x3e)) < 0 (signed), and falls through when s7(=(ret(pciio_pio_read64) << 0x3e)) >= 0 (signed).
  The `beq` branch at 0x2894 targets 0x28a4, is taken when a5(=[a0+1148]:1) == 0, and falls through when a5(=[a0+1148]:1) != 0.
  The `bltz` branch at 0x289c targets 0x2aec, is taken when a6(=(ret(pciio_pio_read64) << 0x3d)) < 0 (signed), and falls through when a6(=(ret(pciio_pio_read64) << 0x3d)) >= 0 (signed).
  The `beq` branch at 0x28a4 targets 0x27a8 and is always taken.
  The `bne` branch at 0x28b0 targets 0x2730, is taken when (v0(?) & 0x1f0) != 0, and falls through when (v0(?) & 0x1f0) == 0.
  The `beq` branch at 0x28b8 targets 0x280c and is always taken.
  The `beq` branch at 0x28c4 targets 0x28d8, is taken when (v0(=ret(pciio_pio_read64)) & 0x1) == 0, and falls through when (v0(=ret(pciio_pio_read64)) & 0x1) != 0.
  The `beq` branch at 0x28d0 targets 0x2b90, is taken when t9(=[a0+1147]:1) == 0, and falls through when t9(=[a0+1147]:1) != 0.
  The `beq` branch at 0x28f0 targets 0x290c, is taken when v0(=[a0+1146]:1) == 0, and falls through when v0(=[a0+1146]:1) != 0.
  The `beq` branch at 0x290c targets 0x27a8 and is always taken.
  The `beq` branch at 0x2914 targets 0x2bb4, is taken when s5(?) == 0, and falls through when s5(?) != 0.
  The `beq` branch at 0x2920 targets 0x2710 and is always taken.
  The `beq` branch at 0x2940 targets 0x27a8 and is always taken.
  The `beq` branch at 0x2968 targets 0x2740 and is always taken.
  The `beq` branch at 0x298c targets 0x274c and is always taken.
  The `bne` branch at 0x29b0 targets 0x2758, is taken when t3(=[sym(mvpignore_framing_errors)]) != 0, and falls through when t3(=[sym(mvpignore_framing_errors)]) == 0.
  The `beq` branch at 0x29bc targets 0x2758 and is always taken.
  The `bne` branch at 0x29e0 targets 0x2768, is taken when ra(=[sym(mvpignore_framing_errors)]) != 0, and falls through when ra(=[sym(mvpignore_framing_errors)]) == 0.
  The `beq` branch at 0x29ec targets 0x2768 and is always taken.
  The `bne` branch at 0x2a0c targets 0x2774, is taken when ra(=[sym(mvpignore_framing_errors)]) != 0, and falls through when ra(=[sym(mvpignore_framing_errors)]) == 0.
  The `beq` branch at 0x2a18 targets 0x2774 and is always taken.
  The `beq` branch at 0x2a24 targets 0x2c64, is taken when t8(=[[a0+1120]+11]:1) == 0, and falls through when t8(=[[a0+1120]+11]:1) != 0.
  The `beq` branch at 0x2a2c targets 0x2838 and is always taken.
  The `bne` branch at 0x2a3c targets 0x281c, is taken when t9(=[[a0+2976]+4]) != 0, and falls through when t9(=[[a0+2976]+4]) == 0.
  The `beq` branch at 0x2a44 targets 0x287c and is always taken.
  The `beq` branch at 0x2a54 targets 0x2878, is taken when ra(=[[a0+1120]+9]:1) == 0, and falls through when ra(=[[a0+1120]+9]:1) != 0.
  The `beq` branch at 0x2a90 targets 0x2c10, is taken when a7(=[[a0+1120]+9]:1) == v0(=0x2), and falls through when a7(=[[a0+1120]+9]:1) != v0(=0x2).
  The `beq` branch at 0x2a98 targets 0x2c38, is taken when s3(=0x1) == a7(=[[a0+1120]+9]:1), and falls through when s3(=0x1) != a7(=[[a0+1120]+9]:1).
  The `beq` branch at 0x2aac targets 0x287c and is always taken.
  The `beq` branch at 0x2adc targets 0x2730 and is always taken.
  The `beq` branch at 0x2ae4 targets 0x26a8 and is always taken.
  The `beq` branch at 0x2b10 targets 0x2b7c, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0x2b24 targets 0x2688 and is always taken.
  The `beq` branch at 0x2b34 targets 0x2694, is taken when a4(=[a0+2985]:1) == a6(=0x4), and falls through when a4(=[a0+2985]:1) != a6(=0x4).
  The `beq` branch at 0x2b74 targets 0x269c and is always taken.
  The `beq` branch at 0x2b7c targets 0x27a8 and is always taken.
  The `beq` branch at 0x2b88 targets 0x2b48 and is always taken.
  The `beq` branch at 0x2bac targets 0x27a8 and is always taken.
  The `beq` branch at 0x2bb8 targets 0x2710 and is always taken.
  The `beq` branch at 0x2c1c targets 0x2c2c, is taken when t9(?) == v0(?), and falls through when t9(?) != v0(?).
  The `beq` branch at 0x2c30 targets 0x2a9c and is always taken.
  The `beq` branch at 0x2c48 targets 0x2c58, is taken when at(?) == v0(?), and falls through when at(?) != v0(?).
  The `beq` branch at 0x2c5c targets 0x2a9c and is always taken.
  The `beq` branch at 0x2c84 targets 0x2838 and is always taken.
  The return at 0x2804 has v0 = one of ?, ret(.text+4156).
  The instructions from 0x2bc0 to 0x2c0c are not reached by any path from the entry, and their branches are not listed.
  The instructions from 0x2c8c to 0x3678 are not reached by any path from the entry, and their branches are not listed.
  The indirect jump at 0x2b1c uses a jump table whose successors are unresolved.

- `mvptransfer_set_callbacks` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x367c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x367c-0x3684 (8 bytes).
  It occupies 8 bytes.
  The return at 0x367c has v0 = ?.

- `mvptransfer_setup_controls` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x3684 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x3684-0x3ab4 (1072 bytes).
  It occupies 1072 bytes.
  The `lbu` at 0x3684 loads 1 byte from a0 (arg0 at entry) +0xbae.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x5dc, including `sw` at 0x3690, `sw` at 0x3774.
  The `lbu` at 0x3694 loads 1 byte from a0 (arg0 at entry) +0xbb0.
  The `sb` at 0x3698 stores 1 byte to a0 (arg0 at entry) +0x470.
  The `sd` at 0x36a0 stores 8 bytes to a0 (arg0 at entry) +0x5c0.
  The `sd` at 0x36a8 stores 8 bytes to a0 (arg0 at entry) +0x5b8.
  4 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x5d8, including `sw` at 0x36b0, `sw` at 0x377c, `sw` at 0x3924.
  2 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x5c8, including `sd` at 0x36c0, `sd` at 0x3790.
  The `lbu` at 0x36c4 loads 1 byte from a0 (arg0 at entry) +0x4a8.
  3 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0xbac, including `lbu` at 0x36c8, `lbu` at 0x3758, `lbu` at 0x3864.
  7 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x47d, including `sb` at 0x36d8, `sb` at 0x380c, `sb` at 0x3814.
  The `lbu` at 0x36f8 loads 1 byte from a0 (arg0 at entry) +0x477.
  The `sb` at 0x3700 stores 1 byte to a0 (arg0 at entry) +0x476.
  4 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x460, including `lw` at 0x3704, `lw` at 0x3718, `lw` at 0x3720.
  3 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x471, including `sb` at 0x3708, `sb` at 0x37b0, `sb` at 0x37f0.
  The `lbu` at 0x370c loads 1 byte from [a0+1120] +0xb.
  The `sb` at 0x3714 stores 1 byte to [a0+1120] +0xb.
  The `sb` at 0x371c stores 1 byte to [a0+1120] +0x8.
  The `sb` at 0x3724 stores 1 byte to [a0+1120] +0xa.
  3 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0xba9, including `lbu` at 0x3728, `lbu` at 0x3798, `lbu` at 0x3838.
  The `lh` at 0x376c loads 2 bytes from a0 (arg0 at entry) +0xbb6.
  The `lbu` at 0x37a0 loads 1 byte from [a0+1120] +0x6d.
  12 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x494, including `sw` at 0x37a4, `sw` at 0x38c0, `sw` at 0x38d8.
  11 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x46d, including `sb` at 0x37d4, `sb` at 0x3804, `sb` at 0x388c.
  14 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x46e, including `sb` at 0x37d8, `sb` at 0x3890, `sb` at 0x38c8.
  14 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x477, including `sb` at 0x37dc, `sb` at 0x3894, `sb` at 0x38cc.
  16 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x474, including `sb` at 0x37e4, `sb` at 0x38a0, `sb` at 0x38b8.
  16 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x473, including `sb` at 0x37ec, `sb` at 0x38a8, `sb` at 0x38bc.
  The `lw` at 0x37f4 loads 4 bytes from sym(mvp_umba) +0x8.
  3 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0xbdf, including `lbu` at 0x3800, `lbu` at 0x39b0, `lbu` at 0x39f4.
  The `lbu` at 0x3818 loads 1 byte from a0 (arg0 at entry) +0xbb1.
  2 such `sb` accesses store 1 byte to (a0 + one of 0x464, 0x465) +0x0, including `sb` at 0x3828, `sb` at 0x387c.
  2 such `sb` accesses store 1 byte to ?, including `sb` at 0x3834, `sb` at 0x3880.
  2 such `lw` accesses load 4 bytes from sym(mvpcapture_any) +0x0, including `lw` at 0x38ac, `lw` at 0x396c.
  The `lw` at 0x3984 loads 4 bytes from a0 (arg0 at entry) +0x5d8.
  The `beq` branch at 0x3688 targets 0x376c, is taken when at(=[a0+2990]:1) == 0, and falls through when at(=[a0+2990]:1) != 0.
  The `beq` branch at 0x36a4 targets 0x3778, is taken when (v1(=[a0+2992]:1) & 0x1) == 0, and falls through when (v1(=[a0+2992]:1) & 0x1) != 0.
  The `beq` branch at 0x36d4 targets 0x3794, is taken when a5(=[a0+1192]:1) == 0, and falls through when a5(=[a0+1192]:1) != 0.
  The `beq` branch at 0x36e0 targets 0x37f0, is taken when a5(=[a0+1192]:1) == a3(=0x2), and falls through when a5(=[a0+1192]:1) != a3(=0x2).
  The `beq` branch at 0x36e8 targets 0x3704, is taken when a5(=[a0+1192]:1) == a2(=0x1), and falls through when a5(=[a0+1192]:1) != a2(=0x1).
  The `beq` branch at 0x36f0 targets 0x3764, is taken when a4(=[a0+2988]:1) == 0, and falls through when a4(=[a0+2988]:1) != 0.
  The `beq` branch at 0x3730 targets 0x38ac, is taken when a4(=[a0+2985]:1) == a7(=0x3), and falls through when a4(=[a0+2985]:1) != a7(=0x3).
  The `beq` branch at 0x3738 targets 0x3968, is taken when a4(=[a0+2985]:1) == 0, and falls through when a4(=[a0+2985]:1) != 0.
  The `beq` branch at 0x3740 targets 0x3a18, is taken when a4(=[a0+2985]:1) == a6(=0x4), and falls through when a4(=[a0+2985]:1) != a6(=0x4).
  The `beq` branch at 0x3748 targets 0x3a38, is taken when a4(=[a0+2985]:1) == a2(=0x1), and falls through when a4(=[a0+2985]:1) != a2(=0x1).
  The `beq` branch at 0x3750 targets 0x3a5c, is taken when a4(=[a0+2985]:1) == a3(=0x2), and falls through when a4(=[a0+2985]:1) != a3(=0x2).
  The `bne` branch at 0x375c targets 0x36f8, is taken when a4(=[a0+2988]:1) != 0, and falls through when a4(=[a0+2988]:1) == 0.
  The `beq` branch at 0x3764 targets 0x36fc and is always taken.
  The `beq` branch at 0x3770 targets 0x3694 and is always taken.
  The `beq` branch at 0x378c targets 0x36c4 and is always taken.
  The `beq` branch at 0x37ac targets 0x388c, is taken when a5(=[a0+2985]:1) == v0(=0x3), and falls through when a5(=[a0+2985]:1) != v0(=0x3).
  The `beq` branch at 0x37b4 targets 0x38f8, is taken when a5(=[a0+2985]:1) == 0, and falls through when a5(=[a0+2985]:1) != 0.
  The `beq` branch at 0x37bc targets 0x3948, is taken when a5(=[a0+2985]:1) == a6(=0x4), and falls through when a5(=[a0+2985]:1) != a6(=0x4).
  The `beq` branch at 0x37c4 targets 0x39d4, is taken when a5(=[a0+2985]:1) == a2(=0x1), and falls through when a5(=[a0+2985]:1) != a2(=0x1).
  The `bne` branch at 0x37cc targets 0x36f0, is taken when a5(=[a0+2985]:1) != a3(=0x2), and falls through when a5(=[a0+2985]:1) == a3(=0x2).
  The `beq` branch at 0x37e8 targets 0x36f0 and is always taken.
  The `beq` branch at 0x37f8 targets 0x3870, is taken when v1(=[sym(mvptransfer_stuff_dmadescs)]) == 0, and falls through when v1(=[sym(mvptransfer_stuff_dmadescs)]) != 0.
  The `beq` branch at 0x3808 targets 0x3868, is taken when a1(=[a0+3039]:1) == 0, and falls through when a1(=[a0+3039]:1) != 0.
  The `beq` branch at 0x3820 targets 0x3878, is taken when a5(=[a0+2993]:1) == 0, and falls through when a5(=[a0+2993]:1) != 0.
  The `beq` branch at 0x3840 targets 0x38d8, is taken when a7(=[a0+2985]:1) == t0(=0x3), and falls through when a7(=[a0+2985]:1) != t0(=0x3).
  The `beq` branch at 0x3848 targets 0x3928, is taken when a7(=[a0+2985]:1) == t1(=0x4), and falls through when a7(=[a0+2985]:1) != t1(=0x4).
  The `beq` branch at 0x3850 targets 0x39ac, is taken when a7(=[a0+2985]:1) == a2(=0x1), and falls through when a7(=[a0+2985]:1) != a2(=0x1).
  The `beq` branch at 0x3858 targets 0x39f0, is taken when a7(=[a0+2985]:1) == a3(=0x2), and falls through when a7(=[a0+2985]:1) != a3(=0x2).
  The `beq` branch at 0x3860 targets 0x36f0 and is always taken.
  The `beq` branch at 0x3868 targets 0x3818 and is always taken.
  The `beq` branch at 0x3870 targets 0x3800 and is always taken.
  The `beq` branch at 0x3884 targets 0x3838 and is always taken.
  The `beq` branch at 0x38a4 targets 0x36f0 and is always taken.
  The `beq` branch at 0x38b0 targets 0x3a80, is taken when t3(=[sym(mvpcapture_any)]) == 0, and falls through when t3(=[sym(mvpcapture_any)]) != 0.
  The `beq` branch at 0x38d0 targets 0x3758 and is always taken.
  The `beq` branch at 0x38f0 targets 0x3860 and is always taken.
  The `beq` branch at 0x3920 targets 0x36f0 and is always taken.
  The `beq` branch at 0x3940 targets 0x3860 and is always taken.
  The `beq` branch at 0x3960 targets 0x36f0 and is always taken.
  The `beq` branch at 0x3970 targets 0x3a94, is taken when t1(=[sym(mvpcapture_any)]) == 0, and falls through when t1(=[sym(mvpcapture_any)]) != 0.
  The `beq` branch at 0x39a4 targets 0x3758 and is always taken.
  The `beq` branch at 0x39c4 targets 0x3aa4, is taken when at(=[a0+3039]:1) == 0, and falls through when at(=[a0+3039]:1) != 0.
  The `beq` branch at 0x39cc targets 0x3860 and is always taken.
  The `beq` branch at 0x39e8 targets 0x36f0 and is always taken.
  The `beq` branch at 0x3a08 targets 0x3aac, is taken when a7(=[a0+3039]:1) == 0, and falls through when a7(=[a0+3039]:1) != 0.
  The `beq` branch at 0x3a10 targets 0x3860 and is always taken.
  The `beq` branch at 0x3a30 targets 0x3758 and is always taken.
  The `beq` branch at 0x3a54 targets 0x3758 and is always taken.
  The `beq` branch at 0x3a78 targets 0x3758 and is always taken.
  The `beq` branch at 0x3a8c targets 0x38c0 and is always taken.
  The `beq` branch at 0x3a9c targets 0x3984 and is always taken.
  The `beq` branch at 0x3aa4 targets 0x3860 and is always taken.
  The `beq` branch at 0x3aac targets 0x3860 and is always taken.
  The return at 0x36fc has v0 = ?.

- `mvptransfer_dummy_dma` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x3ab4 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x3ab4-0x3b58 (164 bytes).
  It occupies 164 bytes.
  3 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x478, including `lbu` at 0x3ae4, `lbu` at 0x3b00, `lbu` at 0x3b18.
  The `lbu` at 0x3ae8 loads 1 byte from a0 (arg0 at entry) +0x473.
  The `sw` at 0x3af8 stores 4 bytes to a0 (arg0 at entry) +0x488.
  2 such `sh` accesses store 2 bytes to ?, including `sh` at 0x3afc, `sh` at 0x3b14.
  The `jalr` at 0x3adc calls kvtophys with a0=a0+1024, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x3b40 calls __dcache_wb with a0=a0+1024, a1=0x40, a2=?, a3=?, a4=sym(__dcache_wb).
  The `beq` branch at 0x3af4 targets 0x3b2c, is taken when v1(=[a0+1144]:1) == 0, and falls through when v1(=[a0+1144]:1) != 0.
  The `beq` branch at 0x3b0c targets 0x3b2c, is taken when a2(?) >= a1(=[a0+1144]:1) (unsigned), and falls through when a2(?) < a1(=[a0+1144]:1) (unsigned).
  The `bne` branch at 0x3b24 targets 0x3afc, is taken when a2(?) < a3(=[a0+1144]:1) (unsigned), and falls through when a2(?) >= a3(=[a0+1144]:1) (unsigned).
  The return at 0x3b50 has v0 = ret(__dcache_wb).

- `mvptransfer_setup` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x3b58 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x3b58-0x3e88 (816 bytes).
  It occupies 816 bytes.
  The `lw` at 0x3b5c loads 4 bytes from a0 (arg0 at entry) +0x61c.
  5 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x4a8, including `lbu` at 0x3b74, `lbu` at 0x3be8, `lbu` at 0x3c84.
  The `sb` at 0x3b84 stores 1 byte to a0 (arg0 at entry) +0x467.
  4 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x46c, including `lbu` at 0x3b88, `lbu` at 0x3bf8, `lbu` at 0x3c94.
  2 such `lw` accesses load 4 bytes from sym(mvpcontroller_table) +0x0, including `lw` at 0x3b94, `lw` at 0x3c08.
  2 such `lw` accesses load 4 bytes from ([sym(mvpcontroller_table)] + ([a0+1132]:1 << 0x2)) +0xc0, including `lw` at 0x3bac, `lw` at 0x3c30.
  3 such `ld` accesses load 8 bytes from ?, including `ld` at 0x3bc0, `ld` at 0x3c18, `ld` at 0x3e20.
  3 such `sd` accesses store 8 bytes to ?, including `sd` at 0x3bd0, `sd` at 0x3c34, `sd` at 0x3e34.
  The `sd` at 0x3bd4 stores 8 bytes to [([sym(mvpcontroller_table)] + ([a0+1132]:1 << 0x2))+192] +0x20.
  2 such `sd` accesses store 8 bytes to [([sym(mvpcontroller_table)] + ([a0+1132]:1 << 0x2))+192] +0x10, including `sd` at 0x3c38, `sd` at 0x3e3c.
  The `lh` at 0x3c9c loads 2 bytes from a0 (arg0 at entry) +0x9ca.
  The `sw` at 0x3ca8 stores 4 bytes to a0 (arg0 at entry) +0x600.
  The `sb` at 0x3cb4 stores 1 byte to a0 (arg0 at entry) +0x478.
  The `lw` at 0x3cbc loads 4 bytes from table(sym(mvptransfer_stats)) +0x2c.
  The `sw` at 0x3cc0 stores 4 bytes to a0 (arg0 at entry) +0x598.
  The `sw` at 0x3cc8 stores 4 bytes to a0 (arg0 at entry) +0xba0.
  The `sb` at 0x3ccc stores 1 byte to a0 (arg0 at entry) +0x47b.
  The `sw` at 0x3cd0 stores 4 bytes to a0 (arg0 at entry) +0x498.
  The `sw` at 0x3cd8 stores 4 bytes to a0 (arg0 at entry) +0x5fc.
  The `sw` at 0x3ce0 stores 4 bytes to a0 (arg0 at entry) +0x608.
  The `sw` at 0x3cec stores 4 bytes to a0 (arg0 at entry) +0x604.
  The `lw` at 0x3d1c loads 4 bytes from a0 (arg0 at entry) +0x484.
  The `lw` at 0x3d40 loads 4 bytes from sym(mvp_umba) +0xc.
  The `lbu` at 0x3d4c loads 1 byte from a0 (arg0 at entry) +0x4a9.
  The `lbu` at 0x3d60 loads 1 byte from ?.
  The `sw` at 0x3e0c stores 4 bytes to a0 (arg0 at entry) +0x61c.
  The `sb` at 0x3e68 stores 1 byte to a0 (arg0 at entry) +0x480.
  The `lw` at 0x3e74 loads 4 bytes from sym(mvp_umba) +0x10.
  The `sw` at 0x3e84 stores 4 bytes to a0 (arg0 at entry) +0x610.
  The `jalr` at 0x3bb8 calls splhi with a0=[a0+1192]:1, a1=?, a2=?, a3=?.
  The `jalr` at 0x3be0 calls splx with a0=ret(splhi), a1=?, a2=?, a3=?.
  The `jalr` at 0x3c48 calls .text+13956 with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jalr` at 0x3c5c calls mvpreg_syncpath_controls with a0=a0 at entry (arg0), a1=0x2, a2=?, a3=?.
  The `jalr` at 0x3ce8 calls mvpbuffer_clear with a0=a0 at entry (arg0), a1=?, a2=[a0+1192]:1, a3=[table(sym(mvptransfer_stats))+44], a4=sym(mvpbuffer_clear), a5=a0+2496, a6=[a0+2506]:2.
  The `jalr` at 0x3d00 calls .text+15028 with a0=a0 at entry (arg0), a1=?, a2=?, a3=?, a6=[a0+1192]:1, a7=sym(mvptransfer_dummy_dma).
  The `jalr` at 0x3d14 calls bzero with a0=a0+1448, a1=0x10, a2=?, a3=?.
  The `jalr` at 0x3d98 calls .text+13948 with a0=a0 at entry (arg0), a1=0x1, a2=?, a3=sym(mvptransfer_set_callbacks).
  The `jalr` at 0x3dc8 calls mvpinterrupt_setup with a0=a0 at entry (arg0), a1=[a0+1132]:1, a2=0x1, a3=?, a4=[a0+1192]:1, a5=sym(mvpinterrupt_setup).
  The `jalr` at 0x3de0 calls mvptransfer_enablechannel with a0=a0 at entry (arg0), a1=0x2, a2=?, a3=?, a6=sym(mvptransfer_enablechannel).
  The `jalr` at 0x3e04 calls sv_alloc with a0=0x0, a1=0x0, a2=sym(.rodata)+152, a3=sym(sv_alloc).
  The `jalr` at 0x3e48 calls mvptransfer_stop with a0=a0 at entry (arg0), a1=sym(mvptransfer_stop), a2=?, a3=?, a6=sym(mvptransfer_enablechannel).
  The `jalr` at 0x3e78 calls itimeout with a0=sym(mvptransfer_timeout), a1=a0 at entry (arg0), a2=[sym(mvptransfer_timeout_len)], a3=sym(mvpdummy_spl), a4=sym(itimeout), a6=sym(mvp_umba), a7=0x1.
  The `beq` branch at 0x3b6c targets 0x3df0, is taken when at(=[a0+1564]) == 0, and falls through when at(=[a0+1564]) != 0.
  The `beq` branch at 0x3b80 targets 0x3c3c, is taken when v1(=0x2) == a0(=[a0+1192]:1), and falls through when v1(=0x2) != a0(=[a0+1192]:1).
  The `beq` branch at 0x3bc4 targets 0x3bd8, is taken when t8(?) == 0, and falls through when t8(?) != 0.
  The `beq` branch at 0x3bf0 targets 0x3e20, is taken when v0(=[a0+1192]:1) == v1(=0x1), and falls through when v0(=[a0+1192]:1) != v1(=0x1).
  The `beq` branch at 0x3c2c targets 0x3c3c, is taken when a1(?) == a2(?), and falls through when a1(?) != a2(?).
  The `beq` branch at 0x3c64 targets 0x3c84, is taken when v0(=ret(mvpreg_syncpath_controls)) == 0, and falls through when v0(=ret(mvpreg_syncpath_controls)) != 0.
  The `beq` branch at 0x3c88 targets 0x3c94, is taken when s1(=0x2) == a2(=[a0+1192]:1), and falls through when s1(=0x2) != a2(=[a0+1192]:1).
  The `beq` branch at 0x3cf4 targets 0x3d08, is taken when s1(=0x2) == a6(=[a0+1192]:1), and falls through when s1(=0x2) != a6(=[a0+1192]:1).
  The `beq` branch at 0x3d3c targets 0x3d8c, is taken when (t1(=[a0+1156]) & 0x40) == 0, and falls through when (t1(=[a0+1156]) & 0x40) != 0.
  The `beq` branch at 0x3d44 targets 0x3d8c, is taken when v0(=[sym(mvptransfer_timeout_enable)]) == 0, and falls through when v0(=[sym(mvptransfer_timeout_enable)]) != 0.
  The `beq` branch at 0x3d64 targets 0x3e58, is taken when v0(?) == a7(=0x1), and falls through when v0(?) != a7(=0x1).
  The `beq` branch at 0x3d6c targets 0x3e58, is taken when v0(?) == a2(=0x4), and falls through when v0(?) != a2(=0x4).
  The `beq` branch at 0x3d74 targets 0x3e58, is taken when v0(?) == a0(=0x5), and falls through when v0(?) != a0(=0x5).
  The `beq` branch at 0x3d7c targets 0x3e5c, is taken when v0(?) == a1(=0x6), and falls through when v0(?) != a1(=0x6).
  The `beq` branch at 0x3d84 targets 0x3e5c, is taken when v0(?) == a3(=0x9), and falls through when v0(?) != a3(=0x9).
  The `beq` branch at 0x3dac targets 0x3db8, is taken when s1(=0x2) == a4(=[a0+1192]:1), and falls through when s1(=0x2) != a4(=[a0+1192]:1).
  The `bltz` branch at 0x3dd0 targets 0x3e40, is taken when v0(=ret(mvpinterrupt_setup)) < 0 (signed), and falls through when v0(=ret(mvpinterrupt_setup)) >= 0 (signed).
  The `beq` branch at 0x3de8 targets 0x3c6c and is always taken.
  The `bne` branch at 0x3e10 targets 0x3b74, is taken when v0(=ret(sv_alloc)) != 0, and falls through when v0(=ret(sv_alloc)) == 0.
  The `beq` branch at 0x3e18 targets 0x3c70 and is always taken.
  The `beq` branch at 0x3e2c targets 0x3c3c, is taken when v0(?) == a4(?), and falls through when v0(?) != a4(?).
  The `beq` branch at 0x3e38 targets 0x3c3c and is always taken.
  The `beq` branch at 0x3e50 targets 0x3c6c and is always taken.
  The `beq` branch at 0x3e80 targets 0x3d8c and is always taken.
  The return at 0x3c7c has v0 = one of ?, 0xc.

- `mvptransfer_stop` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x3e88 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x3e88-0x3f50 (200 bytes).
  It occupies 200 bytes.
  The `lw` at 0x3ea8 loads 4 bytes from a0 (arg0 at entry) +0x610.
  The `sw` at 0x3ec4 stores 4 bytes to a0 (arg0 at entry) +0x610.
  The `lbu` at 0x3efc loads 1 byte from a0 (arg0 at entry) +0x46c.
  The `lbu` at 0x3f08 loads 1 byte from a0 (arg0 at entry) +0x4a8.
  The `lw` at 0x3f3c loads 4 bytes from a0 (arg0 at entry) +0x460.
  The `lbu` at 0x3f40 loads 1 byte from [a0+1120] +0xb.
  The `sb` at 0x3f4c stores 1 byte to [a0+1120] +0xb.
  The `jalr` at 0x3ea0 calls splhi with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x3ebc calls untimeout with a0=[a0+1552], a1=?, a2=?, a3=?.
  The `jalr` at 0x3ed4 calls .text+13948 with a0=a0 at entry (arg0), a1=0x0, a2=?, a3=?.
  The `jalr` at 0x3ee4 calls mvptransfer_stop_dma with a0=a0 at entry (arg0), a1=sym(mvptransfer_stop_dma), a2=?, a3=?.
  The `jalr` at 0x3f00 calls mvpinterrupt_setup with a0=a0 at entry (arg0), a1=[a0+1132]:1, a2=0x0, a3=0x0.
  The `jalr` at 0x3f20 calls splx with a0=ret(splhi), a1=?, a2=?, a3=?, a4=[a0+1192]:1, a5=0x1, a6=sym(splx).
  The `beq` branch at 0x3eac targets 0x3ec8, is taken when a0(=[a0+1552]) == 0, and falls through when a0(=[a0+1552]) != 0.
  The `beq` branch at 0x3f10 targets 0x3f3c, is taken when a4(=[a0+1192]:1) == a5(=0x1), and falls through when a4(=[a0+1192]:1) != a5(=0x1).
  The `beq` branch at 0x3f48 targets 0x3f14 and is always taken.
  The return at 0x3f34 has v0 = 0x0.

- `mvptransfer_shutdown_timeout` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x3f50 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x3f50-0x4018 (200 bytes).
  It occupies 200 bytes.
  2 such `lw` accesses load 4 bytes from sym(mvpmutex_locked) +0x0, including `lw` at 0x3f84, `lw` at 0x4004.
  2 such `sw` accesses store 4 bytes to sym(mvpmutex_locked) +0x0, including `sw` at 0x3f94, `sw` at 0x4014.
  The `lw` at 0x3f98 loads 4 bytes from a0 (arg0 at entry) +0x618.
  The `sw` at 0x3fb4 stores 4 bytes to a0 (arg0 at entry) +0x618.
  The `lw` at 0x3fc4 loads 4 bytes from a0 (arg0 at entry) +0x61c.
  The `sb` at 0x3fd8 stores 1 byte to a0 (arg0 at entry) +0x47a.
  The `jalr` at 0x3f70 calls mutex_lock with a0=sym(mvpmutex), a1=0x0, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x3f90 calls splhi with a0=?, a1=sym(splhi), a2=[sym(mvpmutex_locked)]+1, a3=sym(mvpmutex_locked).
  The `jalr` at 0x3fac calls untimeout with a0=[a0+1560], a1=?, a2=sym(untimeout), a3=?.
  The `jalr` at 0x3fc0 calls sv_signal with a0=[a0+1564], a1=?, a2=?, a3=sym(sv_signal).
  The `jalr` at 0x3fd4 calls splx with a0=ret(splhi), a1=?, a2=?, a3=?, a4=sym(splx).
  The `jalr` at 0x3ff0 calls mutex_unlock with a0=sym(mvpmutex), a1=?, a2=?, a3=?, a5=sym(mutex_unlock).
  The `beq` branch at 0x3f9c targets 0x3fb8, is taken when a0(=[a0+1560]) == 0, and falls through when a0(=[a0+1560]) != 0.
  The return at 0x4010 has v0 = ret(mutex_unlock).

- `mvptransfer_shutdown` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x4018 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x4018-0x41a8 (400 bytes).
  It occupies 400 bytes.
  2 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x467, including `lbu` at 0x4018, `lbu` at 0x416c.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x61c, including `lw` at 0x404c, `lw` at 0x40fc.
  The `sw` at 0x4068 stores 4 bytes to a0 (arg0 at entry) +0x61c.
  The `sb` at 0x40b8 stores 1 byte to a0 (arg0 at entry) +0x467.
  The `sb` at 0x40d4 stores 1 byte to a0 (arg0 at entry) +0x47a.
  3 such `lw` accesses load 4 bytes from sym(mvpmutex_locked) +0x0, including `lw` at 0x410c, `lw` at 0x413c, `lw` at 0x4194.
  3 such `sw` accesses store 4 bytes to sym(mvpmutex_locked) +0x0, including `sw` at 0x4118, `sw` at 0x4144, `sw` at 0x41a4.
  The `lw` at 0x4148 loads 4 bytes from a0 (arg0 at entry) +0x484.
  The `lw` at 0x414c loads 4 bytes from a0 (arg0 at entry) +0x48c.
  The `jalr` at 0x4044 calls mvptransfer_stop with a0=a0 at entry (arg0), a1=?, a2=[a0+1127]:1, a3=sym(mvptransfer_stop).
  The `jalr` at 0x4060 calls sv_destroy with a0=[a0+1564], a1=?, a2=?, a3=?, a4=sym(sv_destroy).
  The `jalr` at 0x4088 calls mutex_mine with a0=sym(mvpmutex), a1=?, a2=[a0+1127]:1, a3=a3 at entry (arg3), a5=sym(mutex_mine).
  The `jalr` at 0x40b4 calls mvptransfer_enablechannel with a0=a0 at entry (arg0), a1=0x2, a2=?, a3=?, a7=0x3.
  The `jalr` at 0x40f8 calls sv_timedwait with a0=[a0+1564], a1=0x0, a2=sym(mvpmutex), a3=0x0, a4=0x0, a5=sp-32, a6=0x0.
  The `jalr` at 0x412c calls mutex_lock with a0=sym(mvpmutex), a1=0x0, a2=?, a3=?.
  The `jalr` at 0x4164 calls .text+4156 with a0=a0 at entry (arg0), a1=[a0+1164], a2=0x0, a3=?, a4=sym(mvptransfer_send_events).
  The `jalr` at 0x4188 calls mutex_lock with a0=sym(mvpmutex), a1=0x0, a2=?, a3=sym(mutex_lock).
  The `bne` branch at 0x4030 targets 0x407c, is taken when a1(=0x2) < a2(=[a0+1127]:1) (signed), and falls through when a1(=0x2) >= a2(=[a0+1127]:1) (signed).
  The `beq` branch at 0x4038 targets 0x404c, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x4050 targets 0x4070, is taken when a0(=[a0+1564]) == 0, and falls through when a0(=[a0+1564]) != 0.
  The `beq` branch at 0x4090 targets 0x417c, is taken when v0(=ret(mutex_mine)) == 0, and falls through when v0(=ret(mutex_mine)) != 0.
  The `beq` branch at 0x4114 targets 0x4148, is taken when t9(?) == 0, and falls through when t9(?) != 0.
  The `beq` branch at 0x4154 targets 0x416c, is taken when (a1(=[a0+1164]) & a3(=[a0+1156])) == 0, and falls through when (a1(=[a0+1164]) & a3(=[a0+1156])) != 0.
  The `beq` branch at 0x4174 targets 0x4038 and is always taken.
  The `beq` branch at 0x41a0 targets 0x40a0 and is always taken.
  The return at 0x4074 has v0 = one of ?, ret(sv_destroy).

- `mvptransfer_ioctl` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x41a8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x41a8-0x4388 (480 bytes).
  It occupies 480 bytes.
  The `lbu` at 0x4218 loads 1 byte from a0 (arg0 at entry) +0x467.
  The `lbu` at 0x4234 loads 1 byte from a0 (arg0 at entry) +0xba9.
  The `lbu` at 0x4244 loads 1 byte from a0 (arg0 at entry) +0x4a8.
  2 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x466, including `lbu` at 0x4248, `lbu` at 0x4370.
  The `sb` at 0x425c stores 1 byte to a0 (arg0 at entry) +0x467.
  The `sd` at 0x427c stores 8 bytes to a0 (arg0 at entry) +0x9b8.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0x428c, `ld` at 0x42a0.
  2 such `sd` accesses store 8 bytes to ?, including `sd` at 0x4298, `sd` at 0x42ac.
  2 such `lw` accesses load 4 bytes from sym(mvpmutex_locked) +0x0, including `lw` at 0x4308, `lw` at 0x4338.
  2 such `sw` accesses store 4 bytes to sym(mvpmutex_locked) +0x0, including `sw` at 0x4318, `sw` at 0x4344.
  The `jalr` at 0x41d0 calls mvpcopyin with a0=a2 at entry (arg2), a1=sp-528, a2=0x1f0, a3=a3 at entry (arg3).
  The `jalr` at 0x42b8 calls mvptransfer_setup with a0=a0 at entry (arg0), a1=?, a2=sym(mvptransfer_setup), a3=?, a4=a0+2488, a5=a0+2496, a6=sp-520, a7=0x10.
  The `jalr` at 0x42d8 calls copyout with a0=sp-528, a1=a2 at entry (arg2), a2=0x1f0, a3=sym(copyout).
  The `jalr` at 0x42f4 calls mutex_lock with a0=sym(mvpmutex), a1=0x0, a2=?, a3=?, a4=sym(mutex_lock).
  The `jalr` at 0x4314 calls mvptransfer_shutdown with a0=a0 at entry (arg0), a1=?, a2=?, a3=?, a5=[sym(mvpmutex_locked)]+1, a6=sym(mvpmutex_locked), a7=sym(mvptransfer_shutdown).
  The `jalr` at 0x4330 calls mutex_unlock with a0=sym(mvpmutex), a1=?, a2=?, a3=?.
  The `jalr` at 0x4360 calls mvpbuffer_register with a0=a0 at entry (arg0), a1=one of 0x2, 0x3, a2=?, a3=0x3, a4=a0+2488.
  The `beq` branch at 0x41d8 targets 0x41f4, is taken when v0(=ret(mvpcopyin)) == 0, and falls through when v0(=ret(mvpcopyin)) != 0.
  The `beq` branch at 0x41fc targets 0x4218, is taken when v0(?) == v1(=0x191), and falls through when v0(?) != v1(=0x191).
  The `beq` branch at 0x4204 targets 0x42e8, is taken when v0(?) == a0(=0x192), and falls through when v0(?) != a0(=0x192).
  The `beq` branch at 0x4210 targets 0x41e0 and is always taken.
  The `beq` branch at 0x4224 targets 0x4210, is taken when v0(=[a0+1127]:1) >= 0x3 (signed), and falls through when v0(=[a0+1127]:1) < 0x3 (signed).
  The `beq` branch at 0x422c targets 0x4264, is taken when a0(=0x1) == v0(=[a0+1127]:1), and falls through when a0(=0x1) != v0(=[a0+1127]:1).
  The `beq` branch at 0x423c targets 0x4348, is taken when a2(=[a0+2985]:1) == a3(=0x3), and falls through when a2(=[a0+2985]:1) != a3(=0x3).
  The `beq` branch at 0x424c targets 0x4350, is taken when v1(=[a0+1192]:1) == 0, and falls through when v1(=[a0+1192]:1) != 0.
  The `beq` branch at 0x4254 targets 0x4380, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `bgtz` branch at 0x42a8 targets 0x4284, is taken when v0(?) > 0 (signed), and falls through when v0(?) <= 0 (signed).
  The `bne` branch at 0x42c4 targets 0x4210, is taken when s1(?) != 0, and falls through when s1(?) == 0.
  The `beq` branch at 0x42e0 targets 0x4210 and is always taken.
  The `beq` branch at 0x4340 targets 0x42c4 and is always taken.
  The `beq` branch at 0x4348 targets 0x4244 and is always taken.
  The `bne` branch at 0x4350 targets 0x425c, is taken when v0(?) != 0, and falls through when v0(?) == 0.
  The `bne` branch at 0x4368 targets 0x42c4, is taken when v0(=ret(mvpbuffer_register)) != 0, and falls through when v0(=ret(mvpbuffer_register)) == 0.
  The `beq` branch at 0x4378 targets 0x4254 and is always taken.
  The `beq` branch at 0x4380 targets 0x41e0 and is always taken.
  The return at 0x41ec has v0 = one of ret(mvpcopyin), ?, 0x13.

- `mvptransfer_init` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x4388 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x4388-0x43a4 (28 bytes).
  It occupies 28 bytes.
  The `sw` at 0x4390 stores 4 bytes to sym(mvptransfer_stats) +0xbc.
  The `sw` at 0x4394 stores 4 bytes to sym(mvptransfer_stats) +0x5c.
  The `sw` at 0x4398 stores 4 bytes to sym(mvptransfer_stats) +0x2c.
  The `sw` at 0x43a0 stores 4 bytes to sym(mvptransfer_stats) +0x8c.
  The return at 0x439c has v0 = ?.

- `mvptransfer_get_ustmsc` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x43a4 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x43a4-0x4470 (204 bytes).
  It occupies 204 bytes.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x5b0, including `ld` at 0x43a4, `ld` at 0x43c8.
  The `ld` at 0x43c0 loads 8 bytes from a0 (arg0 at entry) +0x5a8.
  2 such `sd` accesses store 8 bytes to a1 (arg1 at entry) +0x0, including `sd` at 0x43c4, `sd` at 0x4410.
  2 such `sd` accesses store 8 bytes to a1 (arg1 at entry) +0x8, including `sd` at 0x43cc, `sd` at 0x4424.
  The `lbu` at 0x43d0 loads 1 byte from a0 (arg0 at entry) +0x47d.
  The `lw` at 0x43e4 loads 4 bytes from a1 (arg1 at entry) +0xc.
  The `lbu` at 0x43e8 loads 1 byte from a0 (arg0 at entry) +0xbaa.
  The `lbu` at 0x43f8 loads 1 byte from a0 (arg0 at entry) +0xbb0.
  The `ld` at 0x4404 loads 8 bytes from a1 (arg1 at entry) +0x0.
  The `ld` at 0x4414 loads 8 bytes from a1 (arg1 at entry) +0x8.
  The `lw` at 0x4440 loads 4 bytes from sym(mvpearly_frontiermsc) +0x0.
  The `jalr` at 0x4458 calls .text+6276 with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a7=[sym(mvpearly_frontiermsc)].
  The `beq` branch at 0x43b8 targets 0x443c, is taken when at(=[a0+1456]:8) == 0, and falls through when at(=[a0+1456]:8) != 0.
  The `beq` branch at 0x43dc targets 0x4428, is taken when a0(=[a0+1149]:1) == 0, and falls through when a0(=[a0+1149]:1) != 0.
  The `beq` branch at 0x43f0 targets 0x4414, is taken when a1(=[a0+2986]:1) == a2(?), and falls through when a1(=[a0+2986]:1) != a2(?).
  The `beq` branch at 0x4400 targets 0x440c, is taken when (a3(=[a0+2992]:1) & 0x1) == 0, and falls through when (a3(=[a0+2992]:1) & 0x1) != 0.
  The `beq` branch at 0x4448 targets 0x4468, is taken when a7(=[sym(mvpearly_frontiermsc)]) == 0, and falls through when a7(=[sym(mvpearly_frontiermsc)]) != 0.
  The `beq` branch at 0x4460 targets 0x43d0 and is always taken.
  The `beq` branch at 0x4468 targets 0x4430 and is always taken.
  The return at 0x4434 has v0 = one of -0x1, 0x0.

- `mvptransfer_get_frontier_msc` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x4470 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x4470-0x4624 (436 bytes).
  It occupies 436 bytes.
  The `lw` at 0x44a0 loads 4 bytes from sym(mvpearly_frontiermsc) +0x0.
  The `lbu` at 0x44ac loads 1 byte from a0 (arg0 at entry) +0x47e.
  2 such `sd` accesses store 8 bytes to a1 (arg1 at entry) +0x0, including `sd` at 0x44dc, `sd` at 0x460c.
  3 such `sd` accesses store 8 bytes to a1 (arg1 at entry) +0x8, including `sd` at 0x44e8, `sd` at 0x456c, `sd` at 0x4618.
  The `lbu` at 0x44f4 loads 1 byte from a0 (arg0 at entry) +0x4a8.
  The `lw` at 0x450c loads 4 bytes from a0 (arg0 at entry) +0x578.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x5f0, including `lw` at 0x4520, `lw` at 0x45b4.
  The `lw` at 0x452c loads 4 bytes from a0 (arg0 at entry) +0x5f4.
  2 such `ld` accesses load 8 bytes from a1 (arg1 at entry) +0x8, including `ld` at 0x4554, `ld` at 0x45e0.
  The `lw` at 0x459c loads 4 bytes from a0 (arg0 at entry) +0x57c.
  The `lw` at 0x45c0 loads 4 bytes from a0 (arg0 at entry) +0x5e0.
  The `jalr` at 0x4490 calls splhi with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x44c0 calls .text+17316 with a0=a0 at entry (arg0), a1=sp-64, a2=?, a3=?.
  The `jalr` at 0x44e4 calls splx with a0=ret(splhi), a1=?, a2=0x7fffffffffffffff, a3=sym(splx).
  The `jalr` at 0x4508 calls dms_get_nfilled with a0=[a0+1400], a1=sp-48, a2=?, a3=sym(splx), a4=[a0+1192]:1, a5=sym(dms_get_nfilled).
  The `jalr` at 0x4530 calls .text+180 with a0=a0 at entry (arg0), a1=[a0+1524], a2=[a0+1520]-1, a3=sym(mvptransfer_datacount).
  The `jalr` at 0x454c calls splx with a0=ret(splhi), a1=?, a2=?, a3=?, a5=sym(splx).
  The `jalr` at 0x4598 calls dms_get_nfilled with a0=[a0+1404], a1=sp-48, a2=?, a3=sym(dms_get_nfilled), a4=[a0+1192]:1, a5=sym(dms_get_nfilled).
  The `jalr` at 0x45bc calls .text+180 with a0=a0 at entry (arg0), a1=[a0+1520], a2=[a0+1504], a3=?, a5=sym(mvptransfer_datacount).
  The `jalr` at 0x45d8 calls splx with a0=ret(splhi), a1=?, a2=?, a3=?, a7=sym(splx).
  The `jalr` at 0x4614 calls splx with a0=ret(splhi), a1=sym(mvptransfer_get_ustmsc), a2=0x7fffffffffffffff, a3=sym(splx).
  The `bne` branch at 0x44a4 targets 0x44b8, is taken when v0(=[sym(mvpearly_frontiermsc)]) != 0, and falls through when v0(=[sym(mvpearly_frontiermsc)]) == 0.
  The `beq` branch at 0x44b0 targets 0x45fc, is taken when v1(=[a0+1150]:1) == 0, and falls through when v1(=[a0+1150]:1) != 0.
  The `beq` branch at 0x44c8 targets 0x44f4, is taken when v0(=ret(.text+17316)) == 0, and falls through when v0(=ret(.text+17316)) != 0.
  The `beq` branch at 0x44ec targets 0x4574 and is always taken.
  The `beq` branch at 0x44f8 targets 0x458c, is taken when a4(=[a0+1192]:1) == 0, and falls through when a4(=[a0+1192]:1) != 0.
  The `beq` branch at 0x4510 targets 0x451c, is taken when v0(=ret(dms_get_nfilled)) == 0, and falls through when v0(=ret(dms_get_nfilled)) != 0.
  The `beq` branch at 0x45a0 targets 0x45ac, is taken when v0(=ret(dms_get_nfilled)) == 0, and falls through when v0(=ret(dms_get_nfilled)) != 0.
  The `beq` branch at 0x45f4 targets 0x456c and is always taken.
  The `beq` branch at 0x461c targets 0x4574 and is always taken.
  The return at 0x4584 has v0 = one of 0x0, ?.

- `mvptransfer_get_ustmsc_pair` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x4624 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x4624-0x46cc (168 bytes).
  It occupies 168 bytes.
  2 such `sd` accesses store 8 bytes to a1 (arg1 at entry) +0x0, including `sd` at 0x4678, `sd` at 0x46b8.
  2 such `sd` accesses store 8 bytes to a1 (arg1 at entry) +0x8, including `sd` at 0x4684, `sd` at 0x46c8.
  The `jalr` at 0x4644 calls splhi with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x465c calls .text+17316 with a0=a0 at entry (arg0), a1=sp-48, a2=?, a3=?.
  The `jalr` at 0x4680 calls splx with a0=ret(splhi), a1=sym(splx), a2=?, a3=?.
  The `jalr` at 0x46ac calls splx with a0=ret(splhi), a1=sym(splx), a2=sym(splx), a3=?.
  The `beq` branch at 0x4664 targets 0x46a4, is taken when v0(=ret(.text+17316)) == 0, and falls through when v0(=ret(.text+17316)) != 0.
  The `beq` branch at 0x46c4 targets 0x468c and is always taken.
  The return at 0x469c has v0 = 0x0.

- `mvp_delay_bus` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x46cc (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x46cc-0x46f0 (36 bytes).
  It occupies 36 bytes.
  The `jalr` at 0x46dc calls us_delaybus with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x46e8 has v0 = ret(us_delaybus).

- `av1_sense_sdi` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x46f0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x46f0-0x47bc (204 bytes).
  It occupies 204 bytes.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x10, including `lw` at 0x4730, `lw` at 0x4794.
  The `jalr` at 0x471c calls mvpavio_i2c_reg with a0=sym(.data)+40, a1=0x2, a2=0x0, a3=a3 at entry (arg3).
  The `jalr` at 0x4734 calls mvpi2c_read_reg with a0=[a0+16], a1=sym(.data)+40, a2=ret(mvpavio_i2c_reg), a3=?.
  The `jalr` at 0x4780 calls mvpavio_i2c_reg with a0=sym(.data)+40, a1=0x0, a2=0x0, a3=?, a5=-0x1.
  The `jalr` at 0x4798 calls mvpi2c_read_reg with a0=[a0+16], a1=sym(.data)+40, a2=ret(mvpavio_i2c_reg), a3=?.
  The `beq` branch at 0x4748 targets 0x4770, is taken when v0(=ret(mvpi2c_read_reg)) == a5(=-0x1), and falls through when v0(=ret(mvpi2c_read_reg)) != a5(=-0x1).
  The `beq` branch at 0x4750 targets 0x4774, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0x47a4 targets 0x47b4, is taken when v0(=ret(mvpi2c_read_reg)) == v1(=-0x1), and falls through when v0(=ret(mvpi2c_read_reg)) != v1(=-0x1).
  The `beq` branch at 0x47ac targets 0x4758 and is always taken.
  The `beq` branch at 0x47b4 targets 0x475c and is always taken.
  The return at 0x4768 has v0 = one of ?, -0x1.

- `av1_sense_timing` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x47bc (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x47bc-0x48ec (304 bytes).
  It occupies 304 bytes.
  The `lw` at 0x483c loads 4 bytes from a0 (arg0 at entry) +0x10.
  The `lw` at 0x4860 loads 4 bytes from sym(mvp_umba) +0x930.
  The `jalr` at 0x480c calls .text+18160 with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0x0, a3=a3 at entry (arg3), a5=0x1, a6=0x4, a7=a0 at entry (arg0).
  The `jalr` at 0x4848 calls mvpavio_i2c_reg with a0=sym(.data)+40, a1=0x1f, a2=0x0, a3=sym(mvpavio_i2c_reg), a4=[a0+16], a5=0x1, a6=0x4, a7=a0 at entry (arg0).
  The `jalr` at 0x4888 calls mvpi2c_read_reg with a0=[a0+16], a1=sym(.data)+40, a2=ret(mvpavio_i2c_reg), a3=?, a5=sym(mvpi2c_read_reg).
  The `jalr` at 0x48a8 calls .text+18124 with a0=0x3e8, a1=?, a2=?, a3=sym(mvp_delay_bus).
  The `beq` branch at 0x47d8 targets 0x4828, is taken when a1 == at(=0x2), and falls through when a1 != at(=0x2).
  The `beq` branch at 0x47e0 targets 0x482c, is taken when a1 == a2(=0x3), and falls through when a1 != a2(=0x3).
  The `beq` branch at 0x47e8 targets 0x48cc, is taken when a1 == a5(=0x1), and falls through when a1 != a5(=0x1).
  The `beq` branch at 0x47f0 targets 0x4804, is taken when a1 == a6(=0x4), and falls through when a1 != a6(=0x4).
  The `beq` branch at 0x4818 targets 0x48e4, is taken when v0(=ret(.text+18160)) == v1(=-0x1), and falls through when v0(=ret(.text+18160)) != v1(=-0x1).
  The `beq` branch at 0x4820 targets 0x47f8 and is always taken.
  The `beq` branch at 0x4850 targets 0x48c4, is taken when v0(=ret(mvpavio_i2c_reg)) == 0, and falls through when v0(=ret(mvpavio_i2c_reg)) != 0.
  The `blez` branch at 0x4864 targets 0x48c0, is taken when a4(=[sym(.data)+2352]) <= 0 (signed), and falls through when a4(=[sym(.data)+2352]) > 0 (signed).
  The `beq` branch at 0x489c targets 0x48d4, is taken when (a2(=ret(mvpi2c_read_reg)) & 0x40) == 0, and falls through when (a2(=ret(mvpi2c_read_reg)) & 0x40) != 0.
  The `bgtz` branch at 0x48b8 targets 0x4870, is taken when a4(?) > 0 (signed), and falls through when a4(?) <= 0 (signed).
  The `beq` branch at 0x48c4 targets 0x47f8 and is always taken.
  The `beq` branch at 0x48cc targets 0x47fc and is always taken.
  The `beq` branch at 0x48dc targets 0x48c4 and is always taken.
  The `beq` branch at 0x48e4 targets 0x47f8 and is always taken.
  The return at 0x47fc has v0 = one of ?, 0x6.

- `mvpav1_wiggle_ccen` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x48ec (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x48ec-0x4a24 (312 bytes).
  It occupies 312 bytes.
  5 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x10, including `lw` at 0x495c, `lw` at 0x4978, `lw` at 0x49c4.
  The `jalr` at 0x493c calls mvpavio_i2c_reg with a0=sym(.data)+40, a1=0xe, a2=0x0, a3=a3 at entry (arg3).
  The `jalr` at 0x4958 calls mvpi2c_read_reg with a0=[a0+16], a1=sym(.data)+40, a2=ret(mvpavio_i2c_reg), a3=?.
  The `jalr` at 0x497c calls mvpi2c_write_reg with a0=[a0+16], a1=sym(.data)+40, a2=ret(mvpavio_i2c_reg), a3=?, a4=0x1, a5=sym(mvpi2c_write_reg).
  The `jalr` at 0x49a4 calls mvpavio_i2c_reg with a0=sym(.data)+40, a1=0x6d, a2=0x0, a3=a3 at entry (arg3), a6=sym(mvpavio_i2c_reg).
  The `jalr` at 0x49c0 calls mvpi2c_read_reg with a0=[a0+16], a1=sym(.data)+40, a2=ret(mvpavio_i2c_reg), a3=?, a7=sym(mvpi2c_read_reg).
  The `jalr` at 0x49e8 calls mvpi2c_write_reg with a0=[a0+16], a1=sym(.data)+40, a2=ret(mvpavio_i2c_reg), a3=?, a4=0x0.
  The `jalr` at 0x4a14 calls mvpi2c_write_reg with a0=[a0+16], a1=sym(.data)+40, a2=ret(mvpavio_i2c_reg), a3=?, a4=0x0.
  The `beq` branch at 0x4904 targets 0x498c, is taken when a1 == at(=0x1), and falls through when a1 != at(=0x1).
  The `beq` branch at 0x490c targets 0x4924, is taken when a1 == v0(=0x2), and falls through when a1 != v0(=0x2).
  The `beq` branch at 0x4984 targets 0x4914 and is always taken.
  The `beq` branch at 0x4a1c targets 0x4914 and is always taken.
  The return at 0x491c has v0 = one of 0x2, ret(mvpi2c_write_reg).

- `av1_select_analog_input` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x4a24 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x4a24-0x4b70 (332 bytes).
  It occupies 332 bytes.
  The `lbu` at 0x4a34 loads 1 byte from sym(mvp_umba) +0x25f.
  4 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x10, including `lw` at 0x4ab0, `lw` at 0x4acc, `lw` at 0x4b34.
  The `sb` at 0x4b6c stores 1 byte to sym(mvp_umba) +0x25f.
  The `jalr` at 0x4a80 calls mvpavio_i2c_reg with a0=sym(.data)+40, a1=0x2, a2=0x0, a3=a3 at entry (arg3).
  The `jalr` at 0x4a9c calls mvpavio_i2c_reg with a0=sym(.data)+40, a1=0x9, a2=0x0, a3=?.
  The `jalr` at 0x4ab8 calls mvpi2c_read_reg with a0=[a0+16], a1=sym(.data)+40, a2=ret(mvpavio_i2c_reg), a3=?.
  The `jalr` at 0x4ad4 calls mvpi2c_read_reg with a0=[a0+16], a1=sym(.data)+40, a2=ret(mvpavio_i2c_reg), a3=?.
  The `jalr` at 0x4b38 calls mvpi2c_write_reg with a0=[a0+16], a1=sym(.data)+40, a2=ret(mvpavio_i2c_reg), a3=?, a4=0x0, a5=(ret(mvpi2c_read_reg) | 0x80), a6=0x3.
  The `jalr` at 0x4b5c calls mvpi2c_write_reg with a0=[a0+16], a1=sym(.data)+40, a2=ret(mvpavio_i2c_reg), a3=?, a4=0x0.
  The `bne` branch at 0x4a4c targets 0x4a70, is taken when a1 != at(=[sym(.data)+607]:1), and falls through when a1 == at(=[sym(.data)+607]:1).
  The `beq` branch at 0x4aec targets 0x4b0c, is taken when s2(=a1) == v1(=0x2), and falls through when s2(=a1) != v1(=0x2).
  The `beq` branch at 0x4af4 targets 0x4b04, is taken when s2(=a1) == a6(=0x3), and falls through when s2(=a1) != a6(=0x3).
  The `beq` branch at 0x4afc targets 0x4a58 and is always taken.
  The `beq` branch at 0x4b04 targets 0x4b20 and is always taken.
  The `beq` branch at 0x4b68 targets 0x4a54 and is always taken.
  The return at 0x4a68 has v0 = one of -0x2, 0x0, 0x1.

- `av1_select_input` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x4b70 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x4b70-0x4bcc (92 bytes).
  It occupies 92 bytes.
  The `jalr` at 0x4bbc calls .text+18980 with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a4=0x1.
  The `beq` branch at 0x4b80 targets 0x4bb4, is taken when a1 == at(=0x2), and falls through when a1 != at(=0x2).
  The `beq` branch at 0x4b88 targets 0x4bb8, is taken when a1 == v0(=0x3), and falls through when a1 != v0(=0x3).
  The `beq` branch at 0x4b90 targets 0x4ba8, is taken when a1 == a4(=0x1), and falls through when a1 != a4(=0x1).
  The `beq` branch at 0x4bac targets 0x4b9c and is always taken.
  The `beq` branch at 0x4bc4 targets 0x4b98 and is always taken.
  The return at 0x4ba0 has v0 = one of ?, 0x0.

- `av1_select_output` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x4bcc (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x4bcc-0x4cb0 (228 bytes).
  It occupies 228 bytes.
  The `lbu` at 0x4bdc loads 1 byte from sym(mvp_umba) +0x6bf.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x10, including `lw` at 0x4c28, `lw` at 0x4c70.
  The `sb` at 0x4c88 stores 1 byte to sym(mvp_umba) +0x6bf.
  The `jalr` at 0x4c08 calls mvpavio_i2c_reg with a0=sym(.data)+40, a1=0x3a, a2=0x0, a3=a3 at entry (arg3).
  The `jalr` at 0x4c24 calls mvpi2c_read_reg with a0=[a0+16], a1=sym(.data)+40, a2=ret(mvpavio_i2c_reg), a3=?.
  The `jalr` at 0x4c6c calls mvpi2c_write_reg with a0=[a0+16], a1=sym(.data)+40, a2=ret(mvpavio_i2c_reg), a3=?, a4=0x0, a7=one of 0x1f, 0x80.
  The `jalr` at 0x4c84 calls mvpav1_wiggle_ccen with a0=a0 at entry (arg0), a1=0x1, a2=?, a3=?.
  The `beq` branch at 0x4bf0 targets 0x4c8c, is taken when a1 == at(=[sym(.data)+1727]:1), and falls through when a1 != at(=[sym(.data)+1727]:1).
  The `beq` branch at 0x4c38 targets 0x4c50, is taken when s1(=a1) == ra(=0x1), and falls through when s1(=a1) != ra(=0x1).
  The `beq` branch at 0x4c40 targets 0x4ca8, is taken when s1(=a1) == a0(=0x2), and falls through when s1(=a1) != a0(=0x2).
  The `beq` branch at 0x4c48 targets 0x4c94 and is always taken.
  The `beq` branch at 0x4ca8 targets 0x4c58 and is always taken.
  The return at 0x4ca0 has v0 = one of -0x2, 0x0.

- `av1_select_genlock` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x4cb0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x4cb0-0x4e40 (400 bytes).
  It occupies 400 bytes.
  The `lbu` at 0x4cdc loads 1 byte from sym(mvp_umba) +0x6c0.
  4 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x10, including `lw` at 0x4d54, `lw` at 0x4d70, `lw` at 0x4dc8.
  The `lbu` at 0x4d90 loads 1 byte from sym(mvp_umba) +0x6be.
  The `lbu` at 0x4da4 loads 1 byte from ([sym(.data)+1726]:1 + ret(mvpavio_i2c_reg)) +0x9.
  The `sb` at 0x4e14 stores 1 byte to sym(mvp_umba) +0x6c0.
  The `jalr` at 0x4cf4 calls mvpav1_wiggle_ccen with a0=a0 at entry (arg0), a1=a2 at entry (arg2), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a5=0x2.
  The `jalr` at 0x4d24 calls mvpavio_i2c_reg with a0=sym(.data)+40, a1=0x61, a2=0x0, a3=a3 at entry (arg3), a5=0x2.
  The `jalr` at 0x4d40 calls mvpavio_i2c_reg with a0=sym(.data)+40, a1=0x70, a2=0x0, a3=?.
  The `jalr` at 0x4d5c calls mvpi2c_read_reg with a0=[a0+16], a1=sym(.data)+40, a2=ret(mvpavio_i2c_reg), a3=?.
  The `jalr` at 0x4d78 calls mvpi2c_read_reg with a0=[a0+16], a1=sym(.data)+40, a2=ret(mvpavio_i2c_reg), a3=?.
  The `jalr` at 0x4dcc calls mvpi2c_write_reg with a0=[a0+16], a1=sym(.data)+40, a2=ret(mvpavio_i2c_reg), a3=?, a4=0x0, a5=sym(mvpi2c_write_reg), a7=ret(mvpavio_i2c_reg).
  The `jalr` at 0x4df0 calls mvpi2c_write_reg with a0=[a0+16], a1=sym(.data)+40, a2=ret(mvpavio_i2c_reg), a3=?, a4=0x0, a6=sym(mvpi2c_write_reg).
  The `jalr` at 0x4e04 calls mvpav1_wiggle_ccen with a0=a0 at entry (arg0), a1=0x1, a2=?, a3=?, a4=sym(mvpav1_wiggle_ccen).
  The `jalr` at 0x4e30 calls mvpav1_wiggle_ccen with a0=a0 at entry (arg0), a1=0x2, a2=a2 at entry (arg2), a3=a3 at entry (arg3), a5=0x2, a6=sym(mvpav1_wiggle_ccen).
  The `beq` branch at 0x4cd8 targets 0x4e28, is taken when a2 == a5(=0x2), and falls through when a2 != a5(=0x2).
  The `bne` branch at 0x4ce0 targets 0x4d18, is taken when a1 != v0(=[sym(.data)+1728]:1), and falls through when a1 == v0(=[sym(.data)+1728]:1).
  The `beq` branch at 0x4ce8 targets 0x4cfc, is taken when a2 == 0, and falls through when a2 != 0.
  The `beq` branch at 0x4d94 targets 0x4e18, is taken when s2(=a1) == a1(=0x2), and falls through when s2(=a1) != a1(=0x2).
  The `beq` branch at 0x4e10 targets 0x4d00 and is always taken.
  The `beq` branch at 0x4e20 targets 0x4db4 and is always taken.
  The `beq` branch at 0x4e38 targets 0x4d00 and is always taken.
  The return at 0x4d10 has v0 = one of 0x0, 0x1.

- `av1_change_timing` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x4e40 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x4e40-0x4fe0 (416 bytes).
  It occupies 416 bytes.
  The `sw` at 0x4ec8 stores 4 bytes to ?.
  4 such `lbu` accesses load 1 byte from sym(mvp_umba) +0x3e, including `lbu` at 0x4ed8, `lbu` at 0x4eec, `lbu` at 0x4f80.
  The `lh` at 0x4edc loads 2 bytes from sym(mvp_umba) +0x3c.
  2 such `lh` accesses load 2 bytes from sym(mvp_umba) +0x34, including `lh` at 0x4ef8, `lh` at 0x4f20.
  The `sb` at 0x4efc stores 1 byte to sym(mvp_umba) +0x3e.
  The `lw` at 0x4f1c loads 4 bytes from sym(mvp_umba) +0x934.
  The `lbu` at 0x4f7c loads 1 byte from sym(mvp_umba) +0x25f.
  2 such `lbu` accesses load 1 byte from (ret(mvpavio_i2c_reg) + [sym(.data)+62]:1) +0x9, including `lbu` at 0x4f94, `lbu` at 0x4f9c.
  The `sb` at 0x4fcc stores 1 byte to (ret(mvpavio_i2c_reg) + [sym(.data)+62]:1) +0x9.
  The `sb` at 0x4fdc stores 1 byte to ([sym(.data)+62]:1 + ret(mvpavio_i2c_reg)) +0x9.
  The `jalr` at 0x4f18 calls mvpi2c_init_regs with a0=a0 at entry (arg0), a1=sym(.data)+40, a2=[sym(.data)+2356], a3=?.
  The `jalr` at 0x4f38 calls mvpav1_wiggle_ccen with a0=a0 at entry (arg0), a1=0x1, a2=?, a3=?.
  The `jalr` at 0x4f58 calls mvpavio_i2c_reg with a0=sym(.data)+40, a1=0x2, a2=0x0, a3=sym(mvpavio_i2c_reg), a6=sym(.data)+40, a7=sym(mvpaudio_input_timing).
  The `jalr` at 0x4f74 calls mvpavio_i2c_reg with a0=sym(.data)+40, a1=0x9, a2=0x0, a3=?, a4=sym(mvpavio_i2c_reg).
  The `beq` branch at 0x4e68 targets 0x4eac, is taken when a1 == at(=0xa), and falls through when a1 != at(=0xa).
  The `beq` branch at 0x4e7c targets 0x4ea4, is taken when a1 == v1(=0x2), and falls through when a1 != v1(=0x2).
  The `beq` branch at 0x4e84 targets 0x4ea4, is taken when a1 == t0(=0x3), and falls through when a1 != t0(=0x3).
  The `beq` branch at 0x4ea4 targets 0x4ebc and is always taken.
  The `beq` branch at 0x4ebc targets 0x4e8c, is taken when s0(=sym(.data)+40) == 0, and falls through when s0(=sym(.data)+40) != 0.
  The `beq` branch at 0x4ec4 targets 0x4edc, is taken when v0(?) == t1(=0x1), and falls through when v0(?) != t1(=0x1).
  The `bne` branch at 0x4ecc targets 0x4e8c, is taken when v0(?) != 0, and falls through when v0(?) == 0.
  The `beq` branch at 0x4ed4 targets 0x4ef0 and is always taken.
  The `beq` branch at 0x4ee4 targets 0x4e8c, is taken when (t8(=sym(av1_change_timing)) & 0x4) == 0, and falls through when (t8(=sym(av1_change_timing)) & 0x4) != 0.
  The `beq` branch at 0x4ef0 targets 0x4e8c, is taken when v0(?) == t9(=[sym(.data)+62]:1), and falls through when v0(?) != t9(=[sym(.data)+62]:1).
  The `beq` branch at 0x4f00 targets 0x4f48, is taken when ra(=sym(av1_select_genlock)) == at(=0x1bc7), and falls through when ra(=sym(av1_select_genlock)) != at(=0x1bc7).
  The `bne` branch at 0x4f28 targets 0x4e8c, is taken when v1(=sym(av1_select_genlock)) != a0(=0x1c11), and falls through when v1(=sym(av1_select_genlock)) == a0(=0x1c11).
  The `beq` branch at 0x4f40 targets 0x4e90 and is always taken.
  The `beq` branch at 0x4f98 targets 0x4fbc, is taken when a5(=[sym(.data)+607]:1) == a7(=0x2), and falls through when a5(=[sym(.data)+607]:1) != a7(=0x2).
  The `beq` branch at 0x4fa4 targets 0x4fb4, is taken when a5(=[sym(.data)+607]:1) == a3(=0x3), and falls through when a5(=[sym(.data)+607]:1) != a3(=0x3).
  The `beq` branch at 0x4fac targets 0x4e90 and is always taken.
  The `beq` branch at 0x4fb4 targets 0x4fcc and is always taken.
  The `beq` branch at 0x4fd8 targets 0x4f08 and is always taken.
  The return at 0x4e9c has v0 = one of -0x2, 0x0.

- `av1_set_control` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x4fe0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x4fe0-0x4fe8 (8 bytes).
  It occupies 8 bytes.
  The return at 0x4fe0 has v0 = 0x0.

- `av1_get_control` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x4fe8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x4fe8-0x4ff0 (8 bytes).
  It occupies 8 bytes.
  The return at 0x4fe8 has v0 = 0x0.

- `mvpav1_probe` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x4ff0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x4ff0-0x5038 (72 bytes).
  It occupies 72 bytes.
  The `sb` at 0x5020 stores 1 byte to sym(mvp_umba) +0x25e.
  The `sb` at 0x5024 stores 1 byte to sym(mvp_umba) +0x6be.
  The `jalr` at 0x5000 calls mvpavio_preset_timing with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0x5018 targets 0x5028, is taken when v0(=ret(mvpavio_preset_timing)) == a5(=-0x1), and falls through when v0(=ret(mvpavio_preset_timing)) != a5(=-0x1).
  The return at 0x5030 has v0 = sym(.data)+40.

- `av1_setup` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x5038 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x5038-0x557c (1348 bytes).
  It occupies 1348 bytes.
  The `lw` at 0x5064 loads 4 bytes from a1 (arg1 at entry) +0x10.
  3 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x5b, including `sb` at 0x50a0, `sb` at 0x5448, `sb` at 0x54ac.
  2 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x5a, including `sb` at 0x50a4, `sb` at 0x5450.
  19 such `sb` accesses store 1 byte to ?, including `sb` at 0x513c, `sb` at 0x5140, `sb` at 0x5144.
  5 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x5148, `lbu` at 0x51d4, `lbu` at 0x525c.
  2 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x4, including `lw` at 0x5168, `lw` at 0x5330.
  The `sb` at 0x51b0 stores 1 byte to a0 (arg0 at entry) +0x79.
  The `sb` at 0x51b8 stores 1 byte to a0 (arg0 at entry) +0x78.
  The `lbu` at 0x51bc loads 1 byte from a1 (arg1 at entry) +0xb.
  The `sb` at 0x51cc stores 1 byte to a0 (arg0 at entry) +0x7b.
  3 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x84, including `sb` at 0x5268, `sb` at 0x54a0, `sb` at 0x54fc.
  6 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x61, including `sb` at 0x52a0, `sb` at 0x53ac, `sb` at 0x54d4.
  3 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x6c, including `sb` at 0x52ac, `sb` at 0x53b4, `sb` at 0x5564.
  3 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x6e, including `sb` at 0x52cc, `sb` at 0x540c, `sb` at 0x5428.
  4 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x6f, including `sb` at 0x52d4, `sb` at 0x5420, `sb` at 0x543c.
  The `sb` at 0x52e0 stores 1 byte to a0 (arg0 at entry) +0xc.
  The `lbu` at 0x52e4 loads 1 byte from a0 (arg0 at entry) +0x6e.
  The `sb` at 0x52ec stores 1 byte to a0 (arg0 at entry) +0x58.
  The `sb` at 0x52f8 stores 1 byte to a0 (arg0 at entry) +0x59.
  The `sb` at 0x5300 stores 1 byte to a0 (arg0 at entry) +0x65.
  The `sb` at 0x5304 stores 1 byte to a0 (arg0 at entry) +0x64.
  The `sb` at 0x5308 stores 1 byte to a0 (arg0 at entry) +0x60.
  The `sb` at 0x530c stores 1 byte to a0 (arg0 at entry) +0x63.
  The `sb` at 0x5314 stores 1 byte to a0 (arg0 at entry) +0x62.
  The `lbu` at 0x5324 loads 1 byte from a0 (arg0 at entry) +0x62.
  The `lbu` at 0x5328 loads 1 byte from a0 (arg0 at entry) +0x61.
  The `lbu` at 0x5390 loads 1 byte from a0 (arg0 at entry) +0x87.
  2 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x66, including `sb` at 0x53c4, `sb` at 0x5478.
  2 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x6c, including `lbu` at 0x5404, `lbu` at 0x5424.
  2 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x6d, including `sb` at 0x5414, `sb` at 0x5438.
  The `lbu` at 0x5444 loads 1 byte from a0 (arg0 at entry) +0x6f.
  The `lbu` at 0x54b8 loads 1 byte from a0 (arg0 at entry) +0x83.
  The `lbu` at 0x550c loads 1 byte from a0 (arg0 at entry) +0x7f.
  The `lbu` at 0x5538 loads 1 byte from a0 (arg0 at entry) +0x7b.
  The `jalr` at 0x506c calls mvpi2c_read_reg with a0=[a1+16], a1=sym(.data)+1704, a2=-0x2, a3=a3 at entry (arg3).
  The `jalr` at 0x50b0 calls mvpavio_preset_timing with a0=0x80, a1=?, a2=sym(mvpavio_preset_timing), a3=?.
  The `jalr` at 0x50cc calls mvpavio_preset_input with a0=?, a1=?, a2=?, a3=sym(mvpavio_preset_input).
  The `jalr` at 0x50e8 calls mvpavio_preset_output with a0=?, a1=?, a2=?, a3=?, a5=sym(mvpavio_preset_output).
  The `jalr` at 0x5104 calls mvpavio_preset_genlock with a0=?, a1=?, a2=?, a3=?, a7=sym(mvpavio_preset_genlock).
  The `jalr` at 0x516c calls mvperrprintf with a0=0x7, a1=sym(.rodata)+160, a2=[a1+4], a3=?, a4=sym(.rodata)+160.
  The `jalr` at 0x5204 calls .text+19312 with a0=a1 at entry (arg1), a1=?, a2=sym(av1_select_input), a3=?.
  The `jalr` at 0x5228 calls .text+18124 with a0=0xf4240, a1=?, a2=sym(av1_sense_timing), a3=sym(mvp_delay_bus).
  The `jalr` at 0x523c calls .text+18364 with a0=a1 at entry (arg1), a1=?, a2=sym(av1_sense_timing), a3=?.
  The `jalr` at 0x5334 calls mvperrprintf with a0=0x7, a1=sym(.rodata)+160, a2=[a1+4], a3=[a0+97]:1, a4=[a0+98]:1, a6=one of 0x1, 0x2.
  The `jalr` at 0x5344 calls mvpavio_setupoutput with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jalr` at 0x5358 calls mvpav1_wiggle_ccen with a0=a1 at entry (arg1), a1=0x1, a2=?, a3=?.
  The `jalr` at 0x5488 calls .text+18160 with a0=a1 at entry (arg1), a1=0x1, a2=?, a3=?.
  The `beq` branch at 0x5084 targets 0x54ac, is taken when v0(=ret(mvpi2c_read_reg)) == s0(=-0x1), and falls through when v0(=ret(mvpi2c_read_reg)) != s0(=-0x1).
  The `beq` branch at 0x5094 targets 0x5448, is taken when v1(?) == a0(=0x80), and falls through when v1(?) != a0(=0x80).
  The `beq` branch at 0x50b8 targets 0x5454, is taken when v0(=ret(mvpavio_preset_timing)) == s0(=-0x1), and falls through when v0(=ret(mvpavio_preset_timing)) != s0(=-0x1).
  The `beq` branch at 0x50d4 targets 0x545c, is taken when v0(=ret(mvpavio_preset_input)) == s0(=-0x1), and falls through when v0(=ret(mvpavio_preset_input)) != s0(=-0x1).
  The `beq` branch at 0x50f0 targets 0x5464, is taken when v0(=ret(mvpavio_preset_output)) == s0(=-0x1), and falls through when v0(=ret(mvpavio_preset_output)) != s0(=-0x1).
  The `beq` branch at 0x510c targets 0x546c, is taken when v0(=ret(mvpavio_preset_genlock)) == s0(=-0x1), and falls through when v0(=ret(mvpavio_preset_genlock)) != s0(=-0x1).
  The `beq` branch at 0x5134 targets 0x5184 and is always taken.
  The `beq` branch at 0x514c targets 0x5174, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `bltz` branch at 0x5154 targets 0x5160, is taken when s4(?) < 0 (signed), and falls through when s4(?) >= 0 (signed).
  The `beq` branch at 0x517c targets 0x5280, is taken when s0(?) >= 0xa (signed), and falls through when s0(?) < 0xa (signed).
  The `beq` branch at 0x5188 targets 0x51d8, is taken when s0(?) == s8(=0x3), and falls through when s0(?) != s8(=0x3).
  The `beq` branch at 0x5198 targets 0x51f0, is taken when s0(?) == t9(=0x2), and falls through when s0(?) != t9(=0x2).
  The `beq` branch at 0x51a0 targets 0x5260, is taken when s0(?) == s5(=0x4), and falls through when s0(?) != s5(=0x4).
  The `bne` branch at 0x51a8 targets 0x513c, is taken when s0(?) != ra(=0x1), and falls through when s0(?) == ra(=0x1).
  The `beq` branch at 0x51c4 targets 0x51d0, is taken when (at(=[a1+11]:1) & 0x40) == 0, and falls through when (at(=[a1+11]:1) & 0x40) != 0.
  The `beq` branch at 0x51d0 targets 0x514c and is always taken.
  The `bltz` branch at 0x51d8 targets 0x51f8, is taken when s4(?) < 0 (signed), and falls through when s4(?) >= 0 (signed).
  The `beq` branch at 0x51e8 targets 0x514c and is always taken.
  The `bgez` branch at 0x51f0 targets 0x51e0, is taken when s4(?) >= 0 (signed), and falls through when s4(?) < 0 (signed).
  The `bltz` branch at 0x520c targets 0x54ec, is taken when v0(=ret(.text+19312)) < 0 (signed), and falls through when v0(=ret(.text+19312)) >= 0 (signed).
  The `blez` branch at 0x5214 targets 0x5234, is taken when v0(=ret(.text+19312)) <= 0 (signed), and falls through when v0(=ret(.text+19312)) > 0 (signed).
  The `bltz` branch at 0x5244 targets 0x54e0, is taken when v0(=ret(.text+18364)) < 0 (signed), and falls through when v0(=ret(.text+18364)) >= 0 (signed).
  The `beq` branch at 0x5258 targets 0x514c and is always taken.
  The `bltz` branch at 0x5260 targets 0x5484, is taken when s4(?) < 0 (signed), and falls through when s4(?) >= 0 (signed).
  The `beq` branch at 0x5278 targets 0x514c and is always taken.
  The `beq` branch at 0x5288 targets 0x5390, is taken when a5(?) == a6(=-0x1), and falls through when a5(?) != a6(=-0x1).
  The `beq` branch at 0x529c targets 0x53b0, is taken when a7(?) == t0(=-0x1), and falls through when a7(?) != t0(=-0x1).
  The `beq` branch at 0x52b8 targets 0x53c8, is taken when a2(?) == a3(=-0x1), and falls through when a2(?) != a3(=-0x1).
  The `beq` branch at 0x52c8 targets 0x547c, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0x5310 targets 0x5474, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x531c targets 0x53c0, is taken when v0(?) == t0(=0xf), and falls through when v0(?) != t0(=0xf).
  The `beq` branch at 0x53a0 targets 0x54b8, is taken when (t3(=[a0+135]:1) & 0x2) == 0, and falls through when (t3(=[a0+135]:1) & 0x2) != 0.
  The `bne` branch at 0x53a8 targets 0x52a4, is taken when t8(?) != t9(=-0x1), and falls through when t8(?) == t9(=-0x1).
  The `beq` branch at 0x53b8 targets 0x52b0 and is always taken.
  The `beq` branch at 0x53c0 targets 0x5320 and is always taken.
  The `beq` branch at 0x53d4 targets 0x5424, is taken when at(=0x2) == a0(?), and falls through when at(=0x2) != a0(?).
  The `beq` branch at 0x53dc targets 0x5424, is taken when s8(=0x3) == a0(?), and falls through when s8(=0x3) != a0(?).
  The `beq` branch at 0x53e4 targets 0x5424, is taken when v0(=0x5) == a0(?), and falls through when v0(=0x5) != a0(?).
  The `beq` branch at 0x53ec targets 0x5404, is taken when v1(=0x1) == a0(?), and falls through when v1(=0x1) != a0(?).
  The `beq` branch at 0x53f4 targets 0x5404, is taken when s5(=0x4) == a0(?), and falls through when s5(=0x4) != a0(?).
  The `bne` branch at 0x53fc targets 0x5430, is taken when a2(=0x6) != a0(?), and falls through when a2(=0x6) == a0(?).
  The `bne` branch at 0x5408 targets 0x5438, is taken when a3(=0x1) != a1(=[a0+108]:1), and falls through when a3(=0x1) == a1(=[a0+108]:1).
  The `beq` branch at 0x541c targets 0x5440 and is always taken.
  The `beq` branch at 0x5430 targets 0x5414, is taken when a7(=0x1) == a1(?), and falls through when a7(=0x1) != a1(?).
  The `beq` branch at 0x5440 targets 0x52e4 and is always taken.
  The `beq` branch at 0x544c targets 0x50a8 and is always taken.
  The `beq` branch at 0x5454 targets 0x50c4 and is always taken.
  The `beq` branch at 0x545c targets 0x50e0 and is always taken.
  The `beq` branch at 0x5464 targets 0x50fc and is always taken.
  The `beq` branch at 0x546c targets 0x5118 and is always taken.
  The `beq` branch at 0x5474 targets 0x5320 and is always taken.
  The `beq` branch at 0x547c targets 0x52dc and is always taken.
  The `beq` branch at 0x5498 targets 0x54fc, is taken when v0(=ret(.text+18160)) == t9(=-0x1), and falls through when v0(=ret(.text+18160)) != t9(=-0x1).
  The `beq` branch at 0x54a4 targets 0x5270 and is always taken.
  The `beq` branch at 0x54b0 targets 0x5364 and is always taken.
  The `beq` branch at 0x54c8 targets 0x550c, is taken when (at(=[a0+131]:1) & 0x2) == 0, and falls through when (at(=[a0+131]:1) & 0x2) != 0.
  The `bne` branch at 0x54d0 targets 0x52a4, is taken when v0(?) != v1(=-0x1), and falls through when v0(?) == v1(=-0x1).
  The `beq` branch at 0x54d8 targets 0x53b4 and is always taken.
  The `beq` branch at 0x54e4 targets 0x5258 and is always taken.
  The `beq` branch at 0x54f4 targets 0x5258 and is always taken.
  The `beq` branch at 0x5504 targets 0x5270 and is always taken.
  The `beq` branch at 0x5514 targets 0x5538, is taken when (a2(=[a0+127]:1) & 0x2) == 0, and falls through when (a2(=[a0+127]:1) & 0x2) != 0.
  The `bne` branch at 0x5528 targets 0x52a4, is taken when a3(?) != a4(=-0x1), and falls through when a3(?) == a4(=-0x1).
  The `beq` branch at 0x5530 targets 0x53b4 and is always taken.
  The `beq` branch at 0x5540 targets 0x5570, is taken when (a6(=[a0+123]:1) & 0x2) == 0, and falls through when (a6(=[a0+123]:1) & 0x2) != 0.
  The `bne` branch at 0x555c targets 0x52a4, is taken when t0(?) != t1(=-0x1), and falls through when t0(?) == t1(=-0x1).
  The `beq` branch at 0x5568 targets 0x52b0 and is always taken.
  The `beq` branch at 0x5574 targets 0x5554 and is always taken.
  The return at 0x5388 has v0 = 0x0.

- `av2_sense_timing` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x557c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x557c-0x561c (160 bytes).
  It occupies 160 bytes.
  The `lw` at 0x5584 loads 4 bytes from a0 (arg0 at entry) +0x10.
  The `jalr` at 0x55a0 calls mvpi2c_read_reg with a0=[a0+16], a1=sym(.data)+2408, a2=-0x2, a3=sym(mvpi2c_read_reg).
  The `beq` branch at 0x55c4 targets 0x55f4, is taken when s0(=a1) == a7(=0x5), and falls through when s0(=a1) != a7(=0x5).
  The `beq` branch at 0x55cc targets 0x55e4, is taken when s0(=a1) == a3(=0x6), and falls through when s0(=a1) != a3(=0x6).
  The `beq` branch at 0x55e4 targets 0x5604, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0x55ec targets 0x55d8 and is always taken.
  The `beq` branch at 0x55f4 targets 0x5610, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `beq` branch at 0x55fc targets 0x55d8 and is always taken.
  The `beq` branch at 0x5608 targets 0x55d8 and is always taken.
  The `beq` branch at 0x5614 targets 0x55d8 and is always taken.
  The return at 0x55dc has v0 = one of -0x1, ?.

- `av2_select_input` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x561c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x561c-0x5648 (44 bytes).
  It occupies 44 bytes.
  The `beq` branch at 0x5620 targets 0x5640, is taken when a1 == at(=0x5), and falls through when a1 != at(=0x5).
  The `beq` branch at 0x5628 targets 0x5638, is taken when a1 == v0(=0x6), and falls through when a1 != v0(=0x6).
  The return at 0x5630 has v0 = -0x1.
  The return at 0x5638 has v0 = 0x0.
  The return at 0x5640 has v0 = 0x0.

- `av2_select_output` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x5648 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x5648-0x5660 (24 bytes).
  It occupies 24 bytes.
  The `beq` branch at 0x564c targets 0x5658, is taken when a1 == at(=0x1), and falls through when a1 != at(=0x1).
  The return at 0x5658 has v0 = one of -0x2, 0x0.

- `av2_select_genlock` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x5660 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x5660-0x5668 (8 bytes).
  It occupies 8 bytes.
  The return at 0x5660 has v0 = 0x0.

- `av2_change_timing` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x5668 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x5668-0x5670 (8 bytes).
  It occupies 8 bytes.
  The return at 0x5668 has v0 = 0x0.

- `av2_set_control` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x5670 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x5670-0x5678 (8 bytes).
  It occupies 8 bytes.
  The return at 0x5670 has v0 = 0x0.

- `av2_get_control` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x5678 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x5678-0x5680 (8 bytes).
  It occupies 8 bytes.
  The return at 0x5678 has v0 = 0x0.

- `mvpav2_probe` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x5680 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x5680-0x568c (12 bytes).
  It occupies 12 bytes.
  The return at 0x5684 has v0 = sym(.data)+2440.

- `av2_setup` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x568c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x568c-0x5a58 (972 bytes).
  It occupies 972 bytes.
  The `lbu` at 0x56b0 loads 1 byte from sym(mvp_umba) +0x981.
  2 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x5b, including `sb` at 0x56dc, `sb` at 0x5944.
  The `sb` at 0x56e4 stores 1 byte to a0 (arg0 at entry) +0x5a.
  11 such `sb` accesses store 1 byte to ?, including `sb` at 0x5794, `sb` at 0x5798, `sb` at 0x579c.
  3 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x4, including `lw` at 0x5808, `lw` at 0x58d8, `lw` at 0x59d8.
  4 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x61, including `sb` at 0x583c, `sb` at 0x5930, `sb` at 0x5a20.
  4 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x6c, including `sb` at 0x5844, `sb` at 0x5934, `sb` at 0x5a28.
  3 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x6e, including `sb` at 0x585c, `sb` at 0x59f8, `sb` at 0x5a38.
  4 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x6f, including `sb` at 0x5864, `sb` at 0x596c, `sb` at 0x59a4.
  The `sb` at 0x586c stores 1 byte to a0 (arg0 at entry) +0xc.
  The `lbu` at 0x5870 loads 1 byte from a0 (arg0 at entry) +0x6e.
  The `sb` at 0x5878 stores 1 byte to a0 (arg0 at entry) +0x58.
  The `lbu` at 0x5880 loads 1 byte from ?.
  The `sb` at 0x5884 stores 1 byte to a0 (arg0 at entry) +0x59.
  The `sb` at 0x588c stores 1 byte to a0 (arg0 at entry) +0x65.
  The `sb` at 0x5890 stores 1 byte to a0 (arg0 at entry) +0x64.
  The `sb` at 0x5894 stores 1 byte to a0 (arg0 at entry) +0x60.
  The `sb` at 0x5898 stores 1 byte to a0 (arg0 at entry) +0x63.
  The `sb` at 0x58a0 stores 1 byte to a0 (arg0 at entry) +0x62.
  The `lbu` at 0x58b0 loads 1 byte from a0 (arg0 at entry) +0x62.
  The `lbu` at 0x58c4 loads 1 byte from a0 (arg0 at entry) +0x61.
  The `lbu` at 0x591c loads 1 byte from a0 (arg0 at entry) +0x8b.
  2 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x66, including `sb` at 0x594c, `sb` at 0x599c.
  2 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x6d, including `sb` at 0x5968, `sb` at 0x59fc.
  The `lbu` at 0x5974 loads 1 byte from a0 (arg0 at entry) +0x6f.
  2 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x6c, including `lbu` at 0x59ec, `lbu` at 0x5a2c.
  The `lbu` at 0x5a0c loads 1 byte from a0 (arg0 at entry) +0x8f.
  The `jalr` at 0x56e8 calls mvpavio_preset_timing with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x5704 calls mvpavio_preset_input with a0=sym(mvpavio_preset_input), a1=?, a2=?, a3=?.
  The `jalr` at 0x5720 calls mvpavio_preset_output with a0=?, a1=?, a2=sym(mvpavio_preset_output), a3=?, a4=-0x1.
  The `jalr` at 0x5738 calls mvpavio_preset_genlock with a0=?, a1=?, a2=?, a3=sym(mvpavio_preset_genlock).
  The `jalr` at 0x5804 calls mvperrprintf with a0=0x7, a1=sym(.rodata)+3128, a2=[a1+4], a3=?.
  The `jalr` at 0x58d4 calls mvperrprintf with a0=0x7, a1=sym(.rodata)+3128, a2=[a1+4], a3=[a0+97]:1, a4=[a0+98]:1, a5=one of 0x8, 0xf, a6=sym(mvperrprintf).
  The `jalr` at 0x58e4 calls mvpavio_setupoutput with a0=a0 at entry (arg0), a1=?, a2=sym(mvpavio_setupoutput), a3=?.
  The `jalr` at 0x59dc calls mvperrprintf with a0=0x7, a1=sym(.rodata)+3128, a2=[a1+4], a3=?, a5=sym(mvperrprintf).
  The `beq` branch at 0x56cc targets 0x5940, is taken when s3(=-0x1) == at(=[sym(.data)+2433]:1), and falls through when s3(=-0x1) != at(=[sym(.data)+2433]:1).
  The `beq` branch at 0x56f0 targets 0x5978, is taken when v0(=ret(mvpavio_preset_timing)) == s3(=-0x1), and falls through when v0(=ret(mvpavio_preset_timing)) != s3(=-0x1).
  The `beq` branch at 0x570c targets 0x5980, is taken when v0(=ret(mvpavio_preset_input)) == s3(=-0x1), and falls through when v0(=ret(mvpavio_preset_input)) != s3(=-0x1).
  The `beq` branch at 0x5728 targets 0x5988, is taken when v0(=ret(mvpavio_preset_output)) == s3(=-0x1), and falls through when v0(=ret(mvpavio_preset_output)) != s3(=-0x1).
  The `beq` branch at 0x5740 targets 0x5990, is taken when v0(=ret(mvpavio_preset_genlock)) == s3(=-0x1), and falls through when v0(=ret(mvpavio_preset_genlock)) != s3(=-0x1).
  The `beq` branch at 0x578c targets 0x57b0 and is always taken.
  The `beq` branch at 0x57a8 targets 0x5828, is taken when s1(?) >= 0xa (signed), and falls through when s1(?) < 0xa (signed).
  The `beq` branch at 0x57b0 targets 0x57c8, is taken when s1(?) == s6(=0x5), and falls through when s1(?) != s6(=0x5).
  The `bne` branch at 0x57b8 targets 0x5794, is taken when s1(?) != s4(=0x6), and falls through when s1(?) == s4(=0x6).
  The `beq` branch at 0x57c0 targets 0x57d0 and is always taken.
  The `bltz` branch at 0x57d0 targets 0x5814, is taken when s5(?) < 0 (signed), and falls through when s5(?) >= 0 (signed).
  The `beq` branch at 0x580c targets 0x57a0 and is always taken.
  The `beq` branch at 0x5814 targets 0x59a8, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x5820 targets 0x57a0 and is always taken.
  The `beq` branch at 0x582c targets 0x591c, is taken when a3(?) == s3(=-0x1), and falls through when a3(?) != s3(=-0x1).
  The `beq` branch at 0x5838 targets 0x5934, is taken when s8(?) == s3(=-0x1), and falls through when s8(?) != s3(=-0x1).
  The `beq` branch at 0x584c targets 0x5950, is taken when a1(?) == s3(=-0x1), and falls through when a1(?) != s3(=-0x1).
  The `beq` branch at 0x5858 targets 0x59a0, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0x589c targets 0x5998, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x58a8 targets 0x5948, is taken when v0(?) == a5(=0xf), and falls through when v0(?) != a5(=0xf).
  The `beq` branch at 0x5924 targets 0x5a0c, is taken when (a3(=[a0+139]:1) & 0x2) == 0, and falls through when (a3(=[a0+139]:1) & 0x2) != 0.
  The `bne` branch at 0x592c targets 0x5840, is taken when s8(?) != s3(=-0x1), and falls through when s8(?) == s3(=-0x1).
  The `beq` branch at 0x5938 targets 0x5848 and is always taken.
  The `beq` branch at 0x5940 targets 0x58f4 and is always taken.
  The `beq` branch at 0x5948 targets 0x58ac and is always taken.
  The `beq` branch at 0x5950 targets 0x5a2c, is taken when s6(=0x5) == a0(?), and falls through when s6(=0x5) != a0(?).
  The `beq` branch at 0x5958 targets 0x59ec, is taken when s4(=0x6) == a0(?), and falls through when s4(=0x6) != a0(?).
  The `beq` branch at 0x5960 targets 0x59fc, is taken when a4(=0x1) == a3(?), and falls through when a4(=0x1) != a3(?).
  The `beq` branch at 0x5970 targets 0x5870 and is always taken.
  The `beq` branch at 0x5978 targets 0x56fc and is always taken.
  The `beq` branch at 0x5980 targets 0x5718 and is always taken.
  The `beq` branch at 0x5988 targets 0x5730 and is always taken.
  The `beq` branch at 0x5990 targets 0x574c and is always taken.
  The `beq` branch at 0x5998 targets 0x58ac and is always taken.
  The `beq` branch at 0x59a0 targets 0x586c and is always taken.
  The `beq` branch at 0x59e4 targets 0x57a0 and is always taken.
  The `bne` branch at 0x59f4 targets 0x5968, is taken when a4(=0x1) != a3(=[a0+108]:1), and falls through when a4(=0x1) == a3(=[a0+108]:1).
  The `beq` branch at 0x5a04 targets 0x5970 and is always taken.
  The `beq` branch at 0x5a14 targets 0x5a3c, is taken when (a7(=[a0+143]:1) & 0x2) == 0, and falls through when (a7(=[a0+143]:1) & 0x2) != 0.
  The `bne` branch at 0x5a1c targets 0x5840, is taken when s8(?) != s3(=-0x1), and falls through when s8(?) == s3(=-0x1).
  The `beq` branch at 0x5a24 targets 0x5938 and is always taken.
  The `beq` branch at 0x5a34 targets 0x5960 and is always taken.
  The `bne` branch at 0x5a40 targets 0x5840, is taken when s8(?) != s3(=-0x1), and falls through when s8(?) == s3(=-0x1).
  The `beq` branch at 0x5a50 targets 0x5848 and is always taken.
  The return at 0x5914 has v0 = 0x0.

- `mvpavio_setup` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x5a58 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x5a58-0x5a90 (56 bytes).
  It occupies 56 bytes.
  The `lw` at 0x5a74 loads 4 bytes from a1 (arg1 at entry) +0x14.
  The `lw` at 0x5a78 loads 4 bytes from [a1+20] +0x0.
  The `jalr` at 0x5a7c calls (unknown callee) with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a4=-0x1.
  The `bne` branch at 0x5a60 targets 0x5a74, is taken when a1 != 0, and falls through when a1 == 0.
  The `beq` branch at 0x5a88 targets 0x5a68 and is always taken.
  The return at 0x5a6c has v0 = one of -0x1, ret(?).

- `mvpavio_select_input` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x5a90 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x5a90-0x5acc (60 bytes).
  It occupies 60 bytes.
  The `lw` at 0x5a90 loads 4 bytes from a0 (arg0 at entry) +0x14.
  The `lw` at 0x5ab0 loads 4 bytes from [a0+20] +0x14.
  The `lw` at 0x5ab4 loads 4 bytes from [[a0+20]+20] +0x4.
  The `jalr` at 0x5ab8 calls (unknown callee) with a0=[a0+20], a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a4=-0x1.
  The `bne` branch at 0x5a9c targets 0x5ab0, is taken when v0(=[a0+20]) != 0, and falls through when v0(=[a0+20]) == 0.
  The `beq` branch at 0x5ac4 targets 0x5aa4 and is always taken.
  The return at 0x5aa8 has v0 = one of -0x1, ret(?).

- `mvpavio_select_genlock` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x5acc (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x5acc-0x5b08 (60 bytes).
  It occupies 60 bytes.
  The `lw` at 0x5acc loads 4 bytes from a0 (arg0 at entry) +0x14.
  The `lw` at 0x5aec loads 4 bytes from [a0+20] +0x14.
  The `lw` at 0x5af0 loads 4 bytes from [[a0+20]+20] +0xc.
  The `jalr` at 0x5af4 calls (unknown callee) with a0=[a0+20], a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a5=-0x1.
  The `bne` branch at 0x5ad8 targets 0x5aec, is taken when v0(=[a0+20]) != 0, and falls through when v0(=[a0+20]) == 0.
  The `beq` branch at 0x5b00 targets 0x5ae0 and is always taken.
  The return at 0x5ae4 has v0 = one of -0x1, ret(?).

- `mvpavio_select_output` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x5b08 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x5b08-0x5b44 (60 bytes).
  It occupies 60 bytes.
  The `lw` at 0x5b08 loads 4 bytes from a0 (arg0 at entry) +0x14.
  The `lw` at 0x5b28 loads 4 bytes from [a0+20] +0x14.
  The `lw` at 0x5b2c loads 4 bytes from [[a0+20]+20] +0x8.
  The `jalr` at 0x5b30 calls (unknown callee) with a0=[a0+20], a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a4=-0x1.
  The `bne` branch at 0x5b14 targets 0x5b28, is taken when v0(=[a0+20]) != 0, and falls through when v0(=[a0+20]) == 0.
  The `beq` branch at 0x5b3c targets 0x5b1c and is always taken.
  The return at 0x5b20 has v0 = one of -0x1, ret(?).

- `mvpavio_sense_timing` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x5b44 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x5b44-0x5b80 (60 bytes).
  It occupies 60 bytes.
  The `lw` at 0x5b44 loads 4 bytes from a0 (arg0 at entry) +0x14.
  The `lw` at 0x5b64 loads 4 bytes from [a0+20] +0x14.
  The `lw` at 0x5b68 loads 4 bytes from [[a0+20]+20] +0x10.
  The `jalr` at 0x5b6c calls (unknown callee) with a0=[a0+20], a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `bne` branch at 0x5b4c targets 0x5b64, is taken when v0(=[a0+20]) != 0, and falls through when v0(=[a0+20]) == 0.
  The `beq` branch at 0x5b78 targets 0x5b58 and is always taken.
  The return at 0x5b5c has v0 = one of 0x0, ret(?).

- `mvpavio_change_timing` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x5b80 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x5b80-0x5bbc (60 bytes).
  It occupies 60 bytes.
  The `lw` at 0x5b80 loads 4 bytes from a0 (arg0 at entry) +0x14.
  The `lw` at 0x5ba0 loads 4 bytes from [a0+20] +0x14.
  The `lw` at 0x5ba4 loads 4 bytes from [[a0+20]+20] +0x14.
  The `jalr` at 0x5ba8 calls (unknown callee) with a0=[a0+20], a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a5=-0x1.
  The `bne` branch at 0x5b8c targets 0x5ba0, is taken when v0(=[a0+20]) != 0, and falls through when v0(=[a0+20]) == 0.
  The `beq` branch at 0x5bb4 targets 0x5b94 and is always taken.
  The return at 0x5b98 has v0 = one of -0x1, ret(?).

- `showvalue` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x5bbc (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x5bbc-0x5cac (240 bytes).
  It occupies 240 bytes.
  The `lw` at 0x5bd0 loads 4 bytes from sym(mvp_umba) +0x9d0.
  The `sb` at 0x5bdc stores 1 byte to sym(mvptransfer_stats) +0xd8.
  The `sb` at 0x5be4 stores 1 byte to sym(mvptransfer_stats) +0xd9.
  2 such `lbu` accesses load 1 byte from table(sym(.rodata)+4320) +0x0, including `lbu` at 0x5bf4, `lbu` at 0x5c0c.
  The `sb` at 0x5c00 stores 1 byte to sym(mvptransfer_stats) +0xda.
  The `sb` at 0x5c18 stores 1 byte to sym(mvptransfer_stats) +0xdc.
  The `sb` at 0x5c24 stores 1 byte to sym(mvptransfer_stats) +0xdb.
  2 such `sb` accesses store 1 byte to sym(mvptransfer_stats) +0xbf, including `sb` at 0x5c40, `sb` at 0x5c8c.
  The `lbu` at 0x5c64 loads 1 byte from a0 (arg0 at entry) +0xc.
  2 such `sb` accesses store 1 byte to sym(mvptransfer_stats) +0xc0, including `sb` at 0x5c90, `sb` at 0x5ca8.
  The `sb` at 0x5c9c stores 1 byte to sym(mvptransfer_stats) +0xc1.
  The `beq` branch at 0x5c20 targets 0x5c50 and is always taken.
  The `beq` branch at 0x5c34 targets 0x5c40, is taken when (a5(?) & a1) == 0, and falls through when (a5(?) & a1) != 0.
  The `beq` branch at 0x5c48 targets 0x5c9c, is taken when t0(?) == 0, and falls through when t0(?) != 0.
  The `beq` branch at 0x5c50 targets 0x5c90, is taken when a4(?) == t2(=0x4), and falls through when a4(?) != t2(=0x4).
  The `beq` branch at 0x5c5c targets 0x5c28, is taken when a0 == 0, and falls through when a0 != 0.
  The `bne` branch at 0x5c6c targets 0x5c28, is taken when (a5(?) & v1(=[a0+12]:1)) != 0, and falls through when (a5(?) & v1(=[a0+12]:1)) == 0.
  The `beq` branch at 0x5c7c targets 0x5c88, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0x5c88 targets 0x5c44 and is always taken.
  The `beq` branch at 0x5c94 targets 0x5c54 and is always taken.
  The return at 0x5ca4 has v0 = sym(mvpi2c_default_avb).

- `mvpavio_i2c_chip` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x5cac (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x5cac-0x5d30 (132 bytes).
  It occupies 132 bytes.
  The `lw` at 0x5cc0 loads 4 bytes from sym(mvptransfer_stats) +0xc0.
  The `lbu` at 0x5ccc loads 1 byte from [sym(mvpi2c_default_avb)] +0xa.
  The `lw` at 0x5cdc loads 4 bytes from ?.
  The `lh` at 0x5ce0 loads 2 bytes from ?.
  The `lbu` at 0x5cf0 loads 1 byte from ?.
  The `jalr` at 0x5d18 calls qprintf with a0=sym(.rodata)+3312, a1=a1 at entry (arg1), a2=sym(qprintf), a3=a3 at entry (arg3).
  The `beq` branch at 0x5cb4 targets 0x5d04, is taken when a1 == 0, and falls through when a1 != 0.
  The `beq` branch at 0x5cc4 targets 0x5d04, is taken when a4(=[sym(mvpi2c_default_avb)]) == 0, and falls through when a4(=[sym(mvpi2c_default_avb)]) != 0.
  The `blez` branch at 0x5cd0 targets 0x5d04, is taken when a7(=[[sym(mvpi2c_default_avb)]+10]:1) <= 0 (signed), and falls through when a7(=[[sym(mvpi2c_default_avb)]+10]:1) > 0 (signed).
  The `beq` branch at 0x5ce8 targets 0x5d28, is taken when at(?) == a1, and falls through when at(?) != a1.
  The `beq` branch at 0x5cf4 targets 0x5d28, is taken when v1(?) == t0(?), and falls through when v1(?) != t0(?).
  The `bne` branch at 0x5cfc targets 0x5cdc, is taken when a6(?) != 0, and falls through when a6(?) == 0.
  The `beq` branch at 0x5d04 targets 0x5d20, is taken when a2 == 0, and falls through when a2 != 0.
  The return at 0x5d28 has v0 = one of ?, 0x0.

- `mvpavio_setupoutput` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x5d30 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x5d30-0x5e30 (256 bytes).
  It occupies 256 bytes.
  2 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x62, including `lbu` at 0x5d4c, `lbu` at 0x5de0.
  6 such `sb` accesses store 1 byte to ?, including `sb` at 0x5d50, `sb` at 0x5d58, `sb` at 0x5d60.
  2 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x63, including `lbu` at 0x5d54, `lbu` at 0x5de8.
  2 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x60, including `lbu` at 0x5d5c, `lbu` at 0x5df0.
  2 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x9c, including `lbu` at 0x5dc4, `lbu` at 0x5e04.
  2 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x98, including `sb` at 0x5ddc, `sb` at 0x5e1c.
  The `beq` branch at 0x5d44 targets 0x5d74 and is always taken.
  The `beq` branch at 0x5d6c targets 0x5dfc, is taken when a2(?) >= 0xb (signed), and falls through when a2(?) < 0xb (signed).
  The `beq` branch at 0x5d74 targets 0x5de0, is taken when a2(?) == a4(=0x7), and falls through when a2(?) != a4(=0x7).
  The `beq` branch at 0x5d7c targets 0x5de0, is taken when a2(?) == a5(=0x8), and falls through when a2(?) != a5(=0x8).
  The `beq` branch at 0x5d84 targets 0x5de0, is taken when a2(?) == a6(=0xa), and falls through when a2(?) != a6(=0xa).
  The `beq` branch at 0x5d8c targets 0x5e04, is taken when a2(?) == a7(=0x9), and falls through when a2(?) != a7(=0x9).
  The `beq` branch at 0x5d9c targets 0x5dfc, is taken when a2(?) >= 0xb (signed), and falls through when a2(?) < 0xb (signed).
  The `beq` branch at 0x5da4 targets 0x5d4c, is taken when a2(?) == a4(=0x7), and falls through when a2(?) != a4(=0x7).
  The `beq` branch at 0x5dac targets 0x5d4c, is taken when a2(?) == a5(=0x8), and falls through when a2(?) != a5(=0x8).
  The `beq` branch at 0x5db4 targets 0x5d4c, is taken when a2(?) == a6(=0xa), and falls through when a2(?) != a6(=0xa).
  The `bne` branch at 0x5dbc targets 0x5d64, is taken when a2(?) != a7(=0x9), and falls through when a2(?) == a7(=0x9).
  The `beq` branch at 0x5dcc targets 0x5e28, is taken when (t1(=[a0+156]:1) & 0x1) == 0, and falls through when (t1(=[a0+156]:1) & 0x1) != 0.
  The `beq` branch at 0x5dd8 targets 0x5d64 and is always taken.
  The `beq` branch at 0x5df4 targets 0x5d94 and is always taken.
  The `beq` branch at 0x5e0c targets 0x5e20, is taken when (t9(=[a0+156]:1) & 0x1) == 0, and falls through when (t9(=[a0+156]:1) & 0x1) != 0.
  The `beq` branch at 0x5e18 targets 0x5d94 and is always taken.
  The `beq` branch at 0x5e20 targets 0x5e18 and is always taken.
  The `beq` branch at 0x5e28 targets 0x5dd8 and is always taken.
  The return at 0x5dfc has v0 = ?.

- `mvpavio_preset_status` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x5e30 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x5e30-0x5edc (172 bytes).
  It occupies 172 bytes.
  The `lw` at 0x5e78 loads 4 bytes from sym(mvp_umba) +0x9d4.
  The `jalr` at 0x5e4c calls is_specified with a0=sym(arg_videostatus), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x5e7c calls mvperrprintf with a0=0x7, a1=sym(.rodata)+4344, a2=sym(.rodata)+3312, a3=sym(arg_videostatus).
  The `jalr` at 0x5e90 calls strcasecmp with a0=sym(arg_videostatus), a1=sym(.rodata)+3312, a2=?, a3=?.
  The `jalr` at 0x5ea8 calls strcasecmp with a0=sym(arg_videostatus), a1=sym(.rodata)+3312, a2=?, a3=?.
  The `beq` branch at 0x5e54 targets 0x5eb4, is taken when v0(=ret(is_specified)) == 0, and falls through when v0(=ret(is_specified)) != 0.
  The `beq` branch at 0x5e98 targets 0x5ecc, is taken when v0(=ret(strcasecmp)) == 0, and falls through when v0(=ret(strcasecmp)) != 0.
  The `beq` branch at 0x5eb0 targets 0x5ed4, is taken when v0(=ret(strcasecmp)) == 0, and falls through when v0(=ret(strcasecmp)) != 0.
  The `beq` branch at 0x5ecc targets 0x5eb8 and is always taken.
  The `beq` branch at 0x5ed4 targets 0x5eb8 and is always taken.
  The return at 0x5ec4 has v0 = one of -0x1, 0x1.

- `mvpavio_preset_timing` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x5edc (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x5edc-0x5fa8 (204 bytes).
  It occupies 204 bytes.
  The `lw` at 0x5f24 loads 4 bytes from sym(mvp_umba) +0x9d4.
  The `jalr` at 0x5ef8 calls is_specified with a0=sym(arg_videotiming), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x5f28 calls mvperrprintf with a0=0x7, a1=sym(.rodata)+4344, a2=sym(.rodata)+3312, a3=sym(arg_videotiming).
  The `jalr` at 0x5f3c calls strcasecmp with a0=sym(arg_videotiming), a1=sym(.rodata)+3312, a2=?, a3=?.
  The `jalr` at 0x5f54 calls strcasecmp with a0=sym(arg_videotiming), a1=sym(.rodata)+3312, a2=?, a3=?.
  The `jalr` at 0x5f98 calls cmn_err with a0=0x6, a1=sym(.rodata)+3312, a2=sym(arg_videotiming), a3=?.
  The `beq` branch at 0x5f00 targets 0x5f78, is taken when v0(=ret(is_specified)) == 0, and falls through when v0(=ret(is_specified)) != 0.
  The `beq` branch at 0x5f44 targets 0x5f80, is taken when v0(=ret(strcasecmp)) == 0, and falls through when v0(=ret(strcasecmp)) != 0.
  The `bne` branch at 0x5f5c targets 0x5f88, is taken when v0(=ret(strcasecmp)) != 0, and falls through when v0(=ret(strcasecmp)) == 0.
  The `beq` branch at 0x5f78 targets 0x5f64 and is always taken.
  The `beq` branch at 0x5f80 targets 0x5f64 and is always taken.
  The `beq` branch at 0x5fa0 targets 0x5f64 and is always taken.
  The return at 0x5f70 has v0 = one of -0x1, 0x2, 0x3.

- `mvpavio_preset_input` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x5fa8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x5fa8-0x60ec (324 bytes).
  It occupies 324 bytes.
  The `lw` at 0x5ff4 loads 4 bytes from sym(mvp_umba) +0x9d4.
  The `jalr` at 0x5fc4 calls is_specified with a0=sym(arg_videoinput), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x5ff8 calls mvperrprintf with a0=0x7, a1=sym(.rodata)+4344, a2=sym(.rodata)+3312, a3=sym(arg_videoinput).
  The `jalr` at 0x600c calls strcasecmp with a0=sym(arg_videoinput), a1=sym(.rodata)+3312, a2=?, a3=?.
  The `jalr` at 0x601c calls strcasecmp with a0=sym(arg_videoinput), a1=sym(.rodata)+3312, a2=?, a3=?.
  The `jalr` at 0x602c calls strcasecmp with a0=sym(arg_videoinput), a1=sym(.rodata)+3312, a2=?, a3=?.
  The `jalr` at 0x603c calls strcasecmp with a0=sym(arg_videoinput), a1=sym(.rodata)+3312, a2=?, a3=?.
  The `jalr` at 0x604c calls strcasecmp with a0=sym(arg_videoinput), a1=sym(.rodata)+3312, a2=?, a3=?.
  The `jalr` at 0x605c calls strcasecmp with a0=sym(arg_videoinput), a1=sym(.rodata)+3312, a2=?, a3=?.
  The `jalr` at 0x606c calls strcasecmp with a0=sym(arg_videoinput), a1=sym(.rodata)+3312, a2=?, a3=?.
  The `jalr` at 0x60dc calls cmn_err with a0=0x6, a1=sym(.rodata)+3312, a2=sym(arg_videoinput), a3=?.
  The `beq` branch at 0x5fd0 targets 0x6084, is taken when v0(=ret(is_specified)) == 0, and falls through when v0(=ret(is_specified)) != 0.
  The `beq` branch at 0x6014 targets 0x60a0, is taken when v0(=ret(strcasecmp)) == 0, and falls through when v0(=ret(strcasecmp)) != 0.
  The `beq` branch at 0x6024 targets 0x60a8, is taken when v0(=ret(strcasecmp)) == 0, and falls through when v0(=ret(strcasecmp)) != 0.
  The `beq` branch at 0x6034 targets 0x60b0, is taken when v0(=ret(strcasecmp)) == 0, and falls through when v0(=ret(strcasecmp)) != 0.
  The `beq` branch at 0x6044 targets 0x60b8, is taken when v0(=ret(strcasecmp)) == 0, and falls through when v0(=ret(strcasecmp)) != 0.
  The `beq` branch at 0x6054 targets 0x60c0, is taken when v0(=ret(strcasecmp)) == 0, and falls through when v0(=ret(strcasecmp)) != 0.
  The `beq` branch at 0x6064 targets 0x60c8, is taken when v0(=ret(strcasecmp)) == 0, and falls through when v0(=ret(strcasecmp)) != 0.
  The `bne` branch at 0x6074 targets 0x60d0, is taken when v0(=ret(strcasecmp)) != 0, and falls through when v0(=ret(strcasecmp)) == 0.
  The `beq` branch at 0x607c targets 0x6088 and is always taken.
  The `beq` branch at 0x60a0 targets 0x6088 and is always taken.
  The `beq` branch at 0x60a8 targets 0x6088 and is always taken.
  The `beq` branch at 0x60b0 targets 0x6088 and is always taken.
  The `beq` branch at 0x60b8 targets 0x6088 and is always taken.
  The `beq` branch at 0x60c0 targets 0x6088 and is always taken.
  The `beq` branch at 0x60c8 targets 0x6088 and is always taken.
  The `beq` branch at 0x60e4 targets 0x6088 and is always taken.
  The return at 0x6098 has v0 = one of 0x6, -0x1, 0x2, 0x3, 0x4, 0x1, 0x7, 0x5.

- `mvpavio_preset_output` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x60ec (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x60ec-0x61d0 (228 bytes).
  It occupies 228 bytes.
  The `lw` at 0x6138 loads 4 bytes from sym(mvp_umba) +0x9d4.
  The `jalr` at 0x6108 calls is_specified with a0=sym(arg_videooutput), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x613c calls mvperrprintf with a0=0x7, a1=sym(.rodata)+4344, a2=sym(.rodata)+3312, a3=sym(arg_videooutput).
  The `jalr` at 0x6150 calls strcasecmp with a0=sym(arg_videooutput), a1=sym(.rodata)+3312, a2=?, a3=?.
  The `jalr` at 0x6160 calls strcasecmp with a0=sym(arg_videooutput), a1=sym(.rodata)+3312, a2=?, a3=?.
  The `jalr` at 0x6170 calls strcasecmp with a0=sym(arg_videooutput), a1=sym(.rodata)+3312, a2=?, a3=?.
  The `jalr` at 0x61c0 calls cmn_err with a0=0x6, a1=sym(.rodata)+3312, a2=sym(arg_videooutput), a3=?.
  The `beq` branch at 0x6114 targets 0x619c, is taken when v0(=ret(is_specified)) == 0, and falls through when v0(=ret(is_specified)) != 0.
  The `beq` branch at 0x6158 targets 0x61a4, is taken when v0(=ret(strcasecmp)) == 0, and falls through when v0(=ret(strcasecmp)) != 0.
  The `beq` branch at 0x6168 targets 0x61ac, is taken when v0(=ret(strcasecmp)) == 0, and falls through when v0(=ret(strcasecmp)) != 0.
  The `bne` branch at 0x6178 targets 0x61b4, is taken when v0(=ret(strcasecmp)) != 0, and falls through when v0(=ret(strcasecmp)) == 0.
  The `beq` branch at 0x619c targets 0x6184 and is always taken.
  The `beq` branch at 0x61a4 targets 0x6184 and is always taken.
  The `beq` branch at 0x61ac targets 0x6184 and is always taken.
  The `beq` branch at 0x61c8 targets 0x6184 and is always taken.
  The return at 0x6194 has v0 = one of -0x1, 0x0, 0x1, 0x2.

- `mvpavio_preset_genlock` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x61d0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x61d0-0x62fc (300 bytes).
  It occupies 300 bytes.
  The `lw` at 0x621c loads 4 bytes from sym(mvp_umba) +0x9d4.
  The `jalr` at 0x61ec calls is_specified with a0=sym(arg_videogenlock), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x6220 calls mvperrprintf with a0=0x7, a1=sym(.rodata)+4344, a2=sym(.rodata)+3312, a3=sym(arg_videogenlock).
  The `jalr` at 0x6234 calls strcasecmp with a0=sym(arg_videogenlock), a1=sym(.rodata)+3312, a2=?, a3=?.
  The `jalr` at 0x6244 calls strcasecmp with a0=sym(arg_videogenlock), a1=sym(.rodata)+3312, a2=?, a3=?.
  The `jalr` at 0x6254 calls strcasecmp with a0=sym(arg_videogenlock), a1=sym(.rodata)+3312, a2=?, a3=?.
  The `jalr` at 0x6264 calls strcasecmp with a0=sym(arg_videogenlock), a1=sym(.rodata)+3312, a2=?, a3=?.
  The `jalr` at 0x6274 calls strcasecmp with a0=sym(arg_videogenlock), a1=sym(.rodata)+3312, a2=?, a3=?.
  The `jalr` at 0x6284 calls strcasecmp with a0=sym(arg_videogenlock), a1=sym(.rodata)+3312, a2=?, a3=?.
  The `jalr` at 0x62ec calls cmn_err with a0=0x6, a1=sym(.rodata)+3312, a2=sym(arg_videogenlock), a3=?.
  The `beq` branch at 0x61f8 targets 0x62b0, is taken when v0(=ret(is_specified)) == 0, and falls through when v0(=ret(is_specified)) != 0.
  The `beq` branch at 0x623c targets 0x62b8, is taken when v0(=ret(strcasecmp)) == 0, and falls through when v0(=ret(strcasecmp)) != 0.
  The `beq` branch at 0x624c targets 0x62c0, is taken when v0(=ret(strcasecmp)) == 0, and falls through when v0(=ret(strcasecmp)) != 0.
  The `beq` branch at 0x625c targets 0x62c8, is taken when v0(=ret(strcasecmp)) == 0, and falls through when v0(=ret(strcasecmp)) != 0.
  The `beq` branch at 0x626c targets 0x62d0, is taken when v0(=ret(strcasecmp)) == 0, and falls through when v0(=ret(strcasecmp)) != 0.
  The `beq` branch at 0x627c targets 0x62d8, is taken when v0(=ret(strcasecmp)) == 0, and falls through when v0(=ret(strcasecmp)) != 0.
  The `bne` branch at 0x628c targets 0x62e0, is taken when v0(=ret(strcasecmp)) != 0, and falls through when v0(=ret(strcasecmp)) == 0.
  The `beq` branch at 0x62b0 targets 0x6298 and is always taken.
  The `beq` branch at 0x62b8 targets 0x6298 and is always taken.
  The `beq` branch at 0x62c0 targets 0x6298 and is always taken.
  The `beq` branch at 0x62c8 targets 0x6298 and is always taken.
  The `beq` branch at 0x62d0 targets 0x6298 and is always taken.
  The `beq` branch at 0x62d8 targets 0x6298 and is always taken.
  The `beq` branch at 0x62f4 targets 0x6298 and is always taken.
  The return at 0x62a8 has v0 = one of 0x3, -0x1, 0x0, 0x1, 0x2.

- `mvpavio_setnoav` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x62fc (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x62fc-0x6388 (140 bytes).
  It occupies 140 bytes.
  The `sb` at 0x631c stores 1 byte to a0 (arg0 at entry) +0x61.
  The `sb` at 0x6320 stores 1 byte to a0 (arg0 at entry) +0x58.
  The `sb` at 0x6324 stores 1 byte to a0 (arg0 at entry) +0x6c.
  The `sb` at 0x6328 stores 1 byte to a0 (arg0 at entry) +0x6f.
  The `sb` at 0x6330 stores 1 byte to a0 (arg0 at entry) +0x6e.
  The `sb` at 0x6338 stores 1 byte to a0 (arg0 at entry) +0x6d.
  The `sb` at 0x633c stores 1 byte to a0 (arg0 at entry) +0x66.
  The `sb` at 0x6340 stores 1 byte to a0 (arg0 at entry) +0x59.
  The `sb` at 0x6348 stores 1 byte to a0 (arg0 at entry) +0x65.
  The `sb` at 0x634c stores 1 byte to a0 (arg0 at entry) +0x64.
  The `sb` at 0x6358 stores 1 byte to a0 (arg0 at entry) +0x60.
  The `sb` at 0x6360 stores 1 byte to a0 (arg0 at entry) +0x63.
  The `sb` at 0x636c stores 1 byte to a0 (arg0 at entry) +0x62.
  The `jalr` at 0x6310 calls mvpavio_preset_timing with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x6368 calls mvpavio_setupoutput with a0=a0 at entry (arg0), a1=sym(mvpavio_setupoutput), a2=0x4, a3=?.
  The `beq` branch at 0x6334 targets 0x6380, is taken when v0(=ret(mvpavio_preset_timing)) == v1(=-0x1), and falls through when v0(=ret(mvpavio_preset_timing)) != v1(=-0x1).
  The `beq` branch at 0x6380 targets 0x633c and is always taken.
  The return at 0x6378 has v0 = ret(mvpavio_setupoutput).

- `mvpavio_i2c_reg` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x6388 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x6388-0x63fc (116 bytes).
  It occupies 116 bytes.
  The `lbu` at 0x6394 loads 1 byte from a0 (arg0 at entry) +0xf.
  The `lbu` at 0x6398 loads 1 byte from a0 (arg0 at entry) +0x10.
  The `lw` at 0x63a4 loads 4 bytes from a0 (arg0 at entry) +0x1c.
  The `lbu` at 0x63ac loads 1 byte from ?.
  The `lw` at 0x63d0 loads 4 bytes from a0 (arg0 at entry) +0x8.
  The `lw` at 0x63d8 loads 4 bytes from a0 (arg0 at entry) +0x4.
  The `lh` at 0x63e0 loads 2 bytes from a0 (arg0 at entry) +0xc.
  The `jalr` at 0x63e4 calls qprintf with a0=sym(.rodata)+3736, a1=a1 at entry (arg1), a2=[a0+12]:2, a3=[a0+4], a4=[a0+8], a5=sym(qprintf), a7=[a0+16]:1.
  The `beq` branch at 0x638c targets 0x63f0, is taken when a0 == 0, and falls through when a0 != 0.
  The `bne` branch at 0x63a0 targets 0x63c4, is taken when a7(=[a0+16]:1) < a5(=[a0+15]:1) (signed), and falls through when a7(=[a0+16]:1) >= a5(=[a0+15]:1) (signed).
  The `beq` branch at 0x63b4 targets 0x63f4, is taken when a1 == v1(?), and falls through when a1 != v1(?).
  The `beq` branch at 0x63bc targets 0x63a8, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `beq` branch at 0x63c4 targets 0x63f0, is taken when a2 == 0, and falls through when a2 != 0.
  The return at 0x63f4 has v0 = one of ?, 0x0.

- `mvpavio_unki2c_chipreg` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x63fc (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x63fc-0x6440 (68 bytes).
  It occupies 68 bytes.
  The `sb` at 0x6408 stores 1 byte to sym(mvptransfer_stats) +0xd5.
  The `sb` at 0x640c stores 1 byte to sym(mvptransfer_stats) +0xd2.
  The `sb` at 0x6410 stores 1 byte to sym(mvptransfer_stats) +0xd1.
  The `sb` at 0x6418 stores 1 byte to sym(mvptransfer_stats) +0xd0.
  The `sb` at 0x6424 stores 1 byte to sym(mvptransfer_stats) +0xd4.
  The `sw` at 0x642c stores 4 bytes to sym(mvptransfer_stats) +0xcc.
  The `sw` at 0x643c stores 4 bytes to sym(mvptransfer_stats) +0xc8.
  The return at 0x6438 has v0 = sym(mvpi2c_default_avb).

- `mvpavio_i2c_get` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x6440 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x6440-0x65b8 (376 bytes).
  It occupies 376 bytes.
  The `lw` at 0x64f4 loads 4 bytes from a0 (arg0 at entry) +0x10.
  The `lh` at 0x6520 loads 2 bytes from ret(mvpavio_i2c_chip) +0xc.
  2 such `lw` accesses load 4 bytes from ret(mvpavio_i2c_chip) +0x8, including `lw` at 0x6528, `lw` at 0x6578.
  The `lw` at 0x653c loads 4 bytes from ret(mvpavio_i2c_chip) +0x0.
  The `lw` at 0x6550 loads 4 bytes from [ret(mvpavio_i2c_chip)] +0x10.
  The `lbu` at 0x6570 loads 1 byte from ?.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0x6584, `lw` at 0x658c.
  The `jalr` at 0x6468 calls mvpavio_i2c_chip with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a3 at entry (arg3), a3=a3 at entry (arg3).
  The `jalr` at 0x6490 calls mvpavio_i2c_reg with a0=ret(mvpavio_i2c_chip), a1=a2 at entry (arg2), a2=a3 at entry (arg3), a3=?.
  The `jalr` at 0x64f0 calls mvpi2c_read_reg with a0=[a0+16], a1=ret(mvpavio_i2c_chip), a2=-0x2, a3=sym(mvpi2c_read_reg).
  The `jalr` at 0x650c calls .text+23484 with a0=0x0, a1=?, a2=?, a3=?, a4=sym(showvalue).
  The `jalr` at 0x652c calls qprintf with a0=sym(.rodata)+3808, a1=[ret(mvpavio_i2c_chip)+12]:2, a2=[ret(mvpavio_i2c_chip)+8], a3=ret(.text+23484), a4=sym(qprintf).
  The `jalr` at 0x654c calls mvpi2c_read_reg with a0=[[ret(mvpavio_i2c_chip)]+16], a1=ret(mvpavio_i2c_chip), a2=?, a3=sym(mvpi2c_read_reg).
  The `jalr` at 0x6568 calls .text+23484 with a0=?, a1=?, a2=?, a3=?, a4=sym(showvalue).
  The `jalr` at 0x6590 calls qprintf with a0=sym(.rodata)+3832, a1=?, a2=[ret(mvpavio_i2c_chip)+8], a3=?, a5=ret(.text+23484), a6=sym(qprintf).
  The `jalr` at 0x65a8 calls .text+25596 with a0=a2 at entry (arg2), a1=?, a2=?, a3=?, a7=sym(mvpavio_unki2c_chipreg).
  The `beq` branch at 0x6478 targets 0x64dc, is taken when s1(=a2) == v0(=-0x2), and falls through when s1(=a2) != v0(=-0x2).
  The `beq` branch at 0x6498 targets 0x65a0, is taken when v0(=ret(mvpavio_i2c_reg)) == 0, and falls through when v0(=ret(mvpavio_i2c_reg)) != 0.
  The `beq` branch at 0x64a0 targets 0x64d4, is taken when s0(=ret(mvpavio_i2c_chip)) == 0, and falls through when s0(=ret(mvpavio_i2c_chip)) != 0.
  The `bne` branch at 0x64a8 targets 0x653c, is taken when s2(?) != 0, and falls through when s2(?) == 0.
  The `beq` branch at 0x64d4 targets 0x64b4 and is always taken.
  The `beq` branch at 0x64f8 targets 0x6534, is taken when s3(=a3) == 0, and falls through when s3(=a3) != 0.
  The `beq` branch at 0x6534 targets 0x64b4 and is always taken.
  The `beq` branch at 0x6554 targets 0x64b4, is taken when s3(=a3) == 0, and falls through when s3(=a3) != 0.
  The `beq` branch at 0x6598 targets 0x64b4 and is always taken.
  The `beq` branch at 0x65b0 targets 0x64a0 and is always taken.
  The return at 0x64cc has v0 = ?.

- `mvpavio_i2c_put` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x65b8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x65b8-0x66b0 (248 bytes).
  It occupies 248 bytes.
  The `lbu` at 0x6634 loads 1 byte from ret(mvpavio_i2c_reg) +0x8.
  The `lw` at 0x663c loads 4 bytes from ret(mvpavio_i2c_chip) +0x8.
  The `lw` at 0x6648 loads 4 bytes from ret(mvpavio_i2c_reg) +0x0.
  The `lw` at 0x6650 loads 4 bytes from ret(mvpavio_i2c_reg) +0x4.
  The `lw` at 0x667c loads 4 bytes from a0 (arg0 at entry) +0x10.
  The `jalr` at 0x65e8 calls mvpavio_i2c_chip with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a4 at entry (arg4), a3=a3 at entry (arg3).
  The `jalr` at 0x6604 calls mvpavio_i2c_reg with a0=ret(mvpavio_i2c_chip), a1=a2 at entry (arg2), a2=a4 at entry (arg4), a3=?.
  The `jalr` at 0x662c calls .text+23484 with a0=ret(mvpavio_i2c_reg), a1=a3 at entry (arg3), a2=?, a3=?.
  The `jalr` at 0x6654 calls qprintf with a0=sym(.rodata)+3832, a1=[ret(mvpavio_i2c_reg)+8]:1, a2=[ret(mvpavio_i2c_chip)+8], a3=[ret(mvpavio_i2c_reg)], a4=[ret(mvpavio_i2c_reg)+4], a5=ret(.text+23484), a6=sym(qprintf).
  The `jalr` at 0x6678 calls mvpi2c_write_reg with a0=[a0+16], a1=ret(mvpavio_i2c_chip), a2=ret(mvpavio_i2c_reg), a3=?, a4=0x1, a5=sym(mvpi2c_write_reg).
  The `beq` branch at 0x660c targets 0x6688, is taken when s1(=ret(mvpavio_i2c_chip)) == 0, and falls through when s1(=ret(mvpavio_i2c_chip)) != 0.
  The `beq` branch at 0x6614 targets 0x6688, is taken when v0(=ret(mvpavio_i2c_reg)) == 0, and falls through when v0(=ret(mvpavio_i2c_reg)) != 0.
  The `beq` branch at 0x661c targets 0x665c, is taken when s2(=a4) == 0, and falls through when s2(=a4) != 0.
  The `bltz` branch at 0x6680 targets 0x66a8, is taken when v0(=ret(mvpi2c_write_reg)) < 0 (signed), and falls through when v0(=ret(mvpi2c_write_reg)) >= 0 (signed).
  The `beq` branch at 0x66a8 targets 0x6690 and is always taken.
  The return at 0x66a0 has v0 = one of 0x0, ret(mvpi2c_write_reg).

- `mvpavio_i2c_change` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x66b0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x66b0-0x679c (236 bytes).
  It occupies 236 bytes.
  2 such `lbu` accesses load 1 byte from ret(mvpavio_i2c_chip) +0x16, including `lbu` at 0x671c, `lbu` at 0x676c.
  The `lw` at 0x6728 loads 4 bytes from sym(mvp_umba) +0x9c8.
  The `lbu` at 0x6740 loads 1 byte from ret(mvpavio_i2c_reg) +0x8.
  The `lw` at 0x674c loads 4 bytes from ret(mvpavio_i2c_chip) +0x8.
  The `lw` at 0x6758 loads 4 bytes from ret(mvpavio_i2c_reg) +0x0.
  The `lw` at 0x6760 loads 4 bytes from ret(mvpavio_i2c_reg) +0x4.
  The `sb` at 0x6774 stores 1 byte to ([ret(mvpavio_i2c_chip)+22]:1 + ret(mvpavio_i2c_reg)) +0x9.
  The `lw` at 0x6798 loads 4 bytes from sym(mvp_umba) +0x9cc.
  The `jalr` at 0x66dc calls mvpavio_i2c_chip with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a4 at entry (arg4), a3=a3 at entry (arg3).
  The `jalr` at 0x66f8 calls mvpavio_i2c_reg with a0=ret(mvpavio_i2c_chip), a1=a2 at entry (arg2), a2=a4 at entry (arg4), a3=?.
  The `jalr` at 0x6738 calls .text+23484 with a0=ret(mvpavio_i2c_reg), a1=a3 at entry (arg3), a2=sym(showvalue), a3=?.
  The `jalr` at 0x6764 calls qprintf with a0=sym(.rodata)+3864, a1=[ret(mvpavio_i2c_reg)+8]:1, a2=[ret(mvpavio_i2c_chip)+8], a3=[ret(mvpavio_i2c_reg)], a4=[ret(mvpavio_i2c_reg)+4], a6=ret(.text+23484), a7=sym(qprintf).
  The `beq` branch at 0x6704 targets 0x6778, is taken when s0(=ret(mvpavio_i2c_chip)) == 0, and falls through when s0(=ret(mvpavio_i2c_chip)) != 0.
  The `beq` branch at 0x670c targets 0x6778, is taken when v0(=ret(mvpavio_i2c_reg)) == 0, and falls through when v0(=ret(mvpavio_i2c_reg)) != 0.
  The `beq` branch at 0x6714 targets 0x676c, is taken when s2(=a4) == 0, and falls through when s2(=a4) != 0.
  The `beq` branch at 0x6724 targets 0x6794, is taken when v1(=[ret(mvpavio_i2c_chip)+22]:1) == 0, and falls through when v1(=[ret(mvpavio_i2c_chip)+22]:1) != 0.
  The `beq` branch at 0x6794 targets 0x672c and is always taken.
  The return at 0x678c has v0 = one of ret(mvpavio_i2c_reg), ?.

- `mvpavio_reset` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x679c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x679c-0x6840 (164 bytes).
  It occupies 164 bytes.
  The `lw` at 0x67cc loads 4 bytes from sym(mvp_umba) +0x9c8.
  The `lbu` at 0x67dc loads 1 byte from ret(mvpavio_i2c_chip) +0x16.
  The `lw` at 0x67e8 loads 4 bytes from ret(mvpavio_i2c_chip) +0x8.
  The `lw` at 0x67ec loads 4 bytes from ret(mvpavio_i2c_chip) +0x4.
  The `lw` at 0x67f4 loads 4 bytes from ret(mvpavio_i2c_chip) +0x0.
  The `lh` at 0x67fc loads 2 bytes from ret(mvpavio_i2c_chip) +0xc.
  The `lw` at 0x680c loads 4 bytes from [ret(mvpavio_i2c_chip)] +0x4.
  The `lw` at 0x683c loads 4 bytes from sym(mvp_umba) +0x9cc.
  The `jalr` at 0x67b8 calls mvpavio_i2c_chip with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0x1, a3=a3 at entry (arg3).
  The `jalr` at 0x6808 calls qprintf with a0=sym(.rodata)+3912, a1=[[ret(mvpavio_i2c_chip)]+4], a2=[ret(mvpavio_i2c_chip)+12]:2, a3=[ret(mvpavio_i2c_chip)+4], a4=[ret(mvpavio_i2c_chip)+8], a6=sym(qprintf), a7=sym(mvpi2c_init_regs).
  The `jalr` at 0x6820 calls mvpi2c_init_regs with a0=a0 at entry (arg0), a1=ret(mvpavio_i2c_chip), a2=0x1, a3=?, a7=sym(mvpi2c_init_regs).
  The `beq` branch at 0x67c8 targets 0x6828, is taken when v0(=ret(mvpavio_i2c_chip)) == 0, and falls through when v0(=ret(mvpavio_i2c_chip)) != 0.
  The `beq` branch at 0x67d4 targets 0x6814, is taken when v0(=a2) == 0, and falls through when v0(=a2) != 0.
  The `beq` branch at 0x67e0 targets 0x6838, is taken when v1(=[ret(mvpavio_i2c_chip)+22]:1) == 0, and falls through when v1(=[ret(mvpavio_i2c_chip)+22]:1) != 0.
  The `beq` branch at 0x6838 targets 0x67e8 and is always taken.
  The return at 0x6830 has v0 = one of ret(mvpavio_i2c_chip), ret(mvpi2c_init_regs).

- `mvpavio_i2c_mode` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x6840 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x6840-0x693c (252 bytes).
  It occupies 252 bytes.
  2 such `lw` accesses load 4 bytes from ret(mvpavio_i2c_chip) +0x0, including `lw` at 0x6894, `lw` at 0x6918.
  2 such `lw` accesses load 4 bytes from [ret(mvpavio_i2c_chip)] +0x4, including `lw` at 0x68ac, `lw` at 0x6930.
  The `lh` at 0x68c4 loads 2 bytes from ret(mvpavio_i2c_chip) +0x14.
  The `lbu` at 0x68d4 loads 1 byte from ret(mvpavio_i2c_chip) +0x16.
  2 such `sb` accesses store 1 byte to ret(mvpavio_i2c_chip) +0x16, including `sb` at 0x68e4, `sb` at 0x6900.
  The `lh` at 0x6920 loads 2 bytes from ret(mvpavio_i2c_chip) +0xc.
  The `jalr` at 0x6868 calls mvpavio_i2c_chip with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a3 at entry (arg3), a3=a3 at entry (arg3).
  The `jalr` at 0x68a8 calls qprintf with a0=sym(.rodata)+3960, a1=[[ret(mvpavio_i2c_chip)]+4], a2=0x0, a3=0x1, a4=sym(qprintf).
  The `jalr` at 0x68fc calls mvpavio_reset with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a3 at entry (arg3), a3=?, a7=sym(mvpavio_reset).
  The `jalr` at 0x692c calls qprintf with a0=sym(.rodata)+3992, a1=[[ret(mvpavio_i2c_chip)]+4], a2=[ret(mvpavio_i2c_chip)+12]:2, a3=sym(qprintf).
  The `beq` branch at 0x6870 targets 0x68b0, is taken when v0(=ret(mvpavio_i2c_chip)) == 0, and falls through when v0(=ret(mvpavio_i2c_chip)) != 0.
  The `beq` branch at 0x6878 targets 0x68c4, is taken when s0(=a2) == a2(=0x1), and falls through when s0(=a2) != a2(=0x1).
  The `beq` branch at 0x6880 targets 0x68d4, is taken when s0(=a2) == 0, and falls through when s0(=a2) != 0.
  The `beq` branch at 0x6888 targets 0x68b0, is taken when s1(=a3) == 0, and falls through when s1(=a3) != 0.
  The `beq` branch at 0x68cc targets 0x690c, is taken when (a5(=[ret(mvpavio_i2c_chip)+20]:2) & 0x4) == 0, and falls through when (a5(=[ret(mvpavio_i2c_chip)+20]:2) & 0x4) != 0.
  The `beq` branch at 0x68e0 targets 0x68b0, is taken when (a6(=(a2 | [ret(mvpavio_i2c_chip)+22]:1)) & 0xff) == 0, and falls through when (a6(=(a2 | [ret(mvpavio_i2c_chip)+22]:1)) & 0xff) != 0.
  The `beq` branch at 0x6904 targets 0x68b4 and is always taken.
  The `beq` branch at 0x690c targets 0x68b4, is taken when s1(=a3) == 0, and falls through when s1(=a3) != 0.
  The `beq` branch at 0x6934 targets 0x68b4 and is always taken.
  The return at 0x68bc has v0 = one of ?, ret(mvpavio_reset), ret(mvpavio_i2c_chip), ret(qprintf).

- `mvpavio_resetbus` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x693c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x693c-0x6968 (44 bytes).
  It occupies 44 bytes.
  The `lw` at 0x6950 loads 4 bytes from a0 (arg0 at entry) +0x10.
  The `sw` at 0x6964 stores 4 bytes to sym(mvp_umba) +0x9c0.
  The `jalr` at 0x694c calls mvpi2c_reset with a0=[a0+16], a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x6960 has v0 = sym(.data)+2496.

- `mvpavio_probechip` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x6968 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x6968-0x6a3c (212 bytes).
  It occupies 212 bytes.
  2 such `lh` accesses load 2 bytes from a1 (arg1 at entry) +0x12, including `lh` at 0x696c, `lh` at 0x69c0.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x10, including `lw` at 0x69d8, `lw` at 0x6a24.
  3 such `sb` accesses store 1 byte to a1 (arg1 at entry) +0x19, including `sb` at 0x69e4, `sb` at 0x6a10, `sb` at 0x6a30.
  The `jalr` at 0x69a4 calls mvpavio_i2c_reg with a0=a1 at entry (arg1), a1=[a1+18]:2, a2=0x0, a3=a3 at entry (arg3).
  The `jalr` at 0x69bc calls .text+25596 with a0=[a1+18]:2, a1=?, a2=ret(mvpavio_i2c_reg), a3=?.
  The `jalr` at 0x69d4 calls mvpi2c_read_reg with a0=[a0+16], a1=a1 at entry (arg1), a2=?, a3=?.
  The `jalr` at 0x6a20 calls mvpi2c_read_reg with a0=[a0+16], a1=a1 at entry (arg1), a2=-0x2, a3=sym(mvpi2c_read_reg).
  The `beq` branch at 0x6988 targets 0x6a14, is taken when v0(=[a1+18]:2) == at(=-0x2), and falls through when v0(=[a1+18]:2) != at(=-0x2).
  The `beq` branch at 0x6990 targets 0x6a04, is taken when v0(=[a1+18]:2) == a2(=-0x1), and falls through when v0(=[a1+18]:2) != a2(=-0x1).
  The `bne` branch at 0x69ac targets 0x69c8, is taken when v0(=ret(mvpavio_i2c_reg)) != 0, and falls through when v0(=ret(mvpavio_i2c_reg)) == 0.
  The `beq` branch at 0x6a0c targets 0x69ec and is always taken.
  The `beq` branch at 0x6a34 targets 0x69ec and is always taken.
  The return at 0x69fc has v0 = one of ?, 0x1.

- `mvpavio_probechips` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x6a3c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x6a3c-0x6c74 (568 bytes).
  It occupies 568 bytes.
  3 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0xa, including `lbu` at 0x6a64, `lbu` at 0x6af0, `lbu` at 0x6bc8.
  2 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0xb, including `lbu` at 0x6aac, `lbu` at 0x6b7c.
  2 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0xb, including `sb` at 0x6ab4, `sb` at 0x6b8c.
  10 such `lw` accesses load 4 bytes from ?, including `lw` at 0x6ab8, `lw` at 0x6ad4, `lw` at 0x6ae0.
  7 such `lh` accesses load 2 bytes from ?, including `lh` at 0x6abc, `lh` at 0x6ad0, `lh` at 0x6b20.
  4 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x4, including `lw` at 0x6acc, `lw` at 0x6bb4, `lw` at 0x6c3c.
  The `sh` at 0x6b28 stores 2 bytes to ?.
  2 such `sb` accesses store 1 byte to a1 (arg1 at entry) +0x5e, including `sb` at 0x6b54, `sb` at 0x6c14.
  2 such `sb` accesses store 1 byte to a1 (arg1 at entry) +0x5f, including `sb` at 0x6b5c, `sb` at 0x6c1c.
  The `sb` at 0x6b90 stores 1 byte to a1 (arg1 at entry) +0x5c.
  The `sb` at 0x6b98 stores 1 byte to a1 (arg1 at entry) +0x5d.
  The `lbu` at 0x6bb0 loads 1 byte from a1 (arg1 at entry) +0x5a.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x0, including `lw` at 0x6bbc, `lw` at 0x6c50.
  The `sw` at 0x6bdc stores 4 bytes to sym(mvptransfer_stats) +0xc0.
  The `jalr` at 0x6ae4 calls mvperrprintf with a0=0x7, a1=sym(.rodata)+3312, a2=[a0+4], a3=?, a6=one of 0x0, 0x1.
  The `jalr` at 0x6b0c calls .text+26984 with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jalr` at 0x6ba8 calls mvpi2c_fastmode with a0=a0 at entry (arg0), a1=one of 0x0, 0x1, a2=?, a3=([a0+11]:1 | 0x80), a5=sym(mvpi2c_fastmode).
  The `jalr` at 0x6bc0 calls mvperrprintf with a0=0x8, a1=sym(.rodata)+3312, a2=[a0], a3=[a0+4], a4=[a1+90]:1.
  The `jalr` at 0x6c40 calls mvperrprintf with a0=0x7, a1=sym(.rodata)+3312, a2=[a0+4], a3=?.
  The `jalr` at 0x6c5c calls mvperrprintf with a0=0x7, a1=sym(.rodata)+3312, a2=[a0], a3=[a0+4], a5=[a0+10]:1.
  The `blez` branch at 0x6a84 targets 0x6c6c, is taken when at(=[a0+10]:1) <= 0 (signed), and falls through when at(=[a0+10]:1) > 0 (signed).
  The `beq` branch at 0x6aa4 targets 0x6b08 and is always taken.
  The `beq` branch at 0x6ac4 targets 0x6b6c, is taken when t9(?) == 0, and falls through when t9(?) != 0.
  The `beq` branch at 0x6b00 targets 0x6b74, is taken when ra(?) >= at(=[a0+10]:1) (signed), and falls through when ra(?) < at(=[a0+10]:1) (signed).
  The `beq` branch at 0x6b18 targets 0x6c2c, is taken when v0(=ret(.text+26984)) == 0, and falls through when v0(=ret(.text+26984)) != 0.
  The `beq` branch at 0x6b38 targets 0x6aac, is taken when v0(?) == s8(=0x40), and falls through when v0(?) != s8(=0x40).
  The `beq` branch at 0x6b44 targets 0x6c14, is taken when v0(?) == v1(=0x20), and falls through when v0(?) != v1(=0x20).
  The `bne` branch at 0x6b4c targets 0x6ac4, is taken when v0(?) != a1(=0x60), and falls through when v0(?) == a1(=0x60).
  The `beq` branch at 0x6b64 targets 0x6ac0 and is always taken.
  The `beq` branch at 0x6b6c targets 0x6acc and is always taken.
  The `beq` branch at 0x6b74 targets 0x6c6c, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `beq` branch at 0x6b88 targets 0x6b9c, is taken when (a3(=([a0+11]:1 | 0x80)) & 0x40) == 0, and falls through when (a3(=([a0+11]:1 | 0x80)) & 0x40) != 0.
  The `bne` branch at 0x6bd0 targets 0x6c50, is taken when s2(?) < a5(=[a0+10]:1) (signed), and falls through when s2(?) >= a5(=[a0+10]:1) (signed).
  The `beq` branch at 0x6c24 targets 0x6ac0 and is always taken.
  The `beq` branch at 0x6c48 targets 0x6af0 and is always taken.
  The `beq` branch at 0x6c64 targets 0x6bdc and is always taken.
  The `beq` branch at 0x6c6c targets 0x6be0 and is always taken.
  The return at 0x6c0c has v0 = one of a0, 0x0.

- `mvpavio_probe` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x6c74 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x6c74-0x6d54 (224 bytes).
  It occupies 224 bytes.
  The `lw` at 0x6ca8 loads 4 bytes from ret(mvpav1_probe) +0x10.
  The `lw` at 0x6cf4 loads 4 bytes from ret(mvpav2_probe) +0x10.
  The `sw` at 0x6d50 stores 4 bytes to sym(mvptransfer_stats) +0xc0.
  The `jalr` at 0x6c8c calls mvpav1_probe with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x6ca4 calls mvpi2c_reset with a0=[ret(mvpav1_probe)+16], a1=?, a2=?, a3=?.
  The `jalr` at 0x6cb8 calls .text+27196 with a0=ret(mvpav1_probe), a1=a0 at entry (arg0), a2=?, a3=?.
  The `jalr` at 0x6cd8 calls mvpav2_probe with a0=a0 at entry (arg0), a1=sym(mvpav2_probe), a2=?, a3=?.
  The `jalr` at 0x6cf0 calls mvpi2c_reset with a0=[ret(mvpav2_probe)+16], a1=?, a2=sym(mvpi2c_reset), a3=?.
  The `jalr` at 0x6d04 calls .text+27196 with a0=ret(mvpav2_probe), a1=a0 at entry (arg0), a2=?, a3=sym(mvpavio_probechips).
  The `jalr` at 0x6d3c calls mvperrprintf with a0=0x8, a1=sym(.rodata)+4232, a2=sym(mvperrprintf), a3=?.
  The `beq` branch at 0x6c94 targets 0x6cd0, is taken when v0(=ret(mvpav1_probe)) == 0, and falls through when v0(=ret(mvpav1_probe)) != 0.
  The `beq` branch at 0x6cc0 targets 0x6cd4, is taken when v0(=ret(.text+27196)) == 0, and falls through when v0(=ret(.text+27196)) != 0.
  The `beq` branch at 0x6cc8 targets 0x6d18 and is always taken.
  The `beq` branch at 0x6ce0 targets 0x6d2c, is taken when v0(=ret(mvpav2_probe)) == 0, and falls through when v0(=ret(mvpav2_probe)) != 0.
  The `beq` branch at 0x6d0c targets 0x6d30, is taken when v0(=ret(.text+27196)) == 0, and falls through when v0(=ret(.text+27196)) != 0.
  The `beq` branch at 0x6d4c targets 0x6d14 and is always taken.
  The return at 0x6d24 has v0 = one of ret(mvpav1_probe), ?.

- `mvpavio_init` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x6d54 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x6d54-0x6ec0 (364 bytes).
  It occupies 364 bytes.
  2 such `lw` accesses load 4 bytes from sym(mvp_umba) +0x9c4, including `lw` at 0x6d98, `lw` at 0x6e30.
  2 such `lbu` accesses load 1 byte from ret(.text+27764) +0xa, including `lbu` at 0x6dc0, `lbu` at 0x6df8.
  4 such `lw` accesses load 4 bytes from ?, including `lw` at 0x6dcc, `lw` at 0x6dd0, `lw` at 0x6dec.
  2 such `lh` accesses load 2 bytes from ?, including `lh` at 0x6dd4, `lh` at 0x6e10.
  The `lw` at 0x6ddc loads 4 bytes from ret(.text+27764) +0x4.
  The `lw` at 0x6e54 loads 4 bytes from ret(.text+27764) +0x18.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x14, including `sw` at 0x6e80, `sw` at 0x6eb4.
  The `jalr` at 0x6d6c calls .text+27764 with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x6de0 calls mvperrprintf with a0=0x7, a1=sym(.rodata)+3312, a2=[ret(.text+27764)+4], a3=?.
  The `jalr` at 0x6df0 calls mvpi2c_init_regs with a0=ret(.text+27764), a1=?, a2=0x1, a3=?.
  The `jalr` at 0x6e7c calls mvpavio_setup with a0=a0 at entry (arg0), a1=ret(.text+27764), a2=?, a3=?.
  The `jalr` at 0x6eb0 calls .text+25340 with a0=a0 at entry (arg0), a1=?, a2=?, a3=?, a4=sym(mvpi2c_init_regs).
  The `beq` branch at 0x6d88 targets 0x6ea4, is taken when v0(=ret(.text+27764)) == 0, and falls through when v0(=ret(.text+27764)) != 0.
  The `blez` branch at 0x6da8 targets 0x6e58, is taken when v0(=[sym(.data)+2500]) <= 0 (signed), and falls through when v0(=[sym(.data)+2500]) > 0 (signed).
  The `beq` branch at 0x6dc4 targets 0x6e44 and is always taken.
  The `beq` branch at 0x6e04 targets 0x6e30, is taken when s1(?) >= a1(=[ret(.text+27764)+10]:1) (signed), and falls through when s1(?) < a1(=[ret(.text+27764)+10]:1) (signed).
  The `bne` branch at 0x6e18 targets 0x6dcc, is taken when (t9(?) & 0x80) != 0, and falls through when (t9(?) & 0x80) == 0.
  The `bne` branch at 0x6e28 targets 0x6e0c, is taken when s1(?) < a1(=[ret(.text+27764)+10]:1) (signed), and falls through when s1(?) >= a1(=[ret(.text+27764)+10]:1) (signed).
  The `beq` branch at 0x6e3c targets 0x6e58, is taken when s6(?) >= v0(=[sym(.data)+2500]) (signed), and falls through when s6(?) < v0(=[sym(.data)+2500]) (signed).
  The `blez` branch at 0x6e44 targets 0x6e34, is taken when a1(=[ret(.text+27764)+10]:1) <= 0 (signed), and falls through when a1(=[ret(.text+27764)+10]:1) > 0 (signed).
  The `beq` branch at 0x6e50 targets 0x6e10 and is always taken.
  The `beq` branch at 0x6eb8 targets 0x6e88 and is always taken.
  The return at 0x6e9c has v0 = one of 0x0, 0x13.

- `mvpbuffer_close` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x6ec0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x6ec0-0x6f64 (164 bytes).
  It occupies 164 bytes.
  The `lw` at 0x6f00 loads 4 bytes from a0 (arg0 at entry) +0x58c.
  The `lw` at 0x6f18 loads 4 bytes from a0 (arg0 at entry) +0x578.
  The `sw` at 0x6f2c stores 4 bytes to a0 (arg0 at entry) +0x58c.
  The `lbu` at 0x6f34 loads 1 byte from a0 (arg0 at entry) +0x466.
  The `sb` at 0x6f4c stores 1 byte to a0 (arg0 at entry) +0x466.
  The `jalr` at 0x6ed4 calls mvptransfer_shutdown with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x6ee4 calls splhi with a0=?, a1=?, a2=?, a3=?.
  The `jalr` at 0x6ef8 calls mvpbuffer_clear with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jalr` at 0x6f14 calls dms_pool_detach with a0=[a0+1400], a1=sym(dms_pool_detach), a2=?, a3=sym(splx).
  The `jalr` at 0x6f48 calls splx with a0=ret(splhi), a1=?, a2=?, a3=sym(splx), a4=-0x9.
  The `beq` branch at 0x6f04 targets 0x6f34, is taken when a0(=[a0+1420]) == 0, and falls through when a0(=[a0+1420]) != 0.
  The `beq` branch at 0x6f1c targets 0x6f2c, is taken when v0(=ret(dms_pool_detach)) == 0, and falls through when v0(=ret(dms_pool_detach)) != 0.
  The `beq` branch at 0x6f24 targets 0x6f58 and is always taken.
  The return at 0x6f5c has v0 = one of ret(dms_pool_detach), 0x0.

- `mvpbuffer_attach` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x6f64 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x6f64-0x6fc8 (100 bytes).
  It occupies 100 bytes.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x578, including `lw` at 0x6f7c, `lw` at 0x6fb0.
  The `sw` at 0x6fbc stores 4 bytes to a0 (arg0 at entry) +0x58c.
  The `jalr` at 0x6f84 calls dms_pool_attach with a0=[a0+1400], a1=sp-80, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x6fb8 calls dms_pool_cache_policy with a0=[a0+1400], a1=a1 at entry (arg1), a2=0x0, a3=0x1, a4=a0 at entry (arg0).
  The `beq` branch at 0x6f8c targets 0x6fa0, is taken when v0(=ret(dms_pool_attach)) == 0, and falls through when v0(=ret(dms_pool_attach)) != 0.
  The `beq` branch at 0x6fc0 targets 0x6f94 and is always taken.
  The return at 0x6f98 has v0 = one of ret(dms_pool_attach), 0x0.

- `mvpbuffer_init` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x6fc8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x6fc8-0x6fec (36 bytes).
  It occupies 36 bytes.
  The `sw` at 0x6fc8 stores 4 bytes to a0 (arg0 at entry) +0x600.
  The `sw` at 0x6fcc stores 4 bytes to a0 (arg0 at entry) +0x59c.
  The `sw` at 0x6fd0 stores 4 bytes to a0 (arg0 at entry) +0x5f4.
  The `sw` at 0x6fd4 stores 4 bytes to a0 (arg0 at entry) +0x5f0.
  The `sw` at 0x6fd8 stores 4 bytes to a0 (arg0 at entry) +0x5e8.
  The `sw` at 0x6fdc stores 4 bytes to a0 (arg0 at entry) +0x5e4.
  The `sw` at 0x6fe0 stores 4 bytes to a0 (arg0 at entry) +0x5ec.
  The `sw` at 0x6fe8 stores 4 bytes to a0 (arg0 at entry) +0x5e0.
  The return at 0x6fe4 has v0 = ?.

- `mvpbuffer_clear` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x6fec (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x6fec-0x7114 (296 bytes).
  It occupies 296 bytes.
  The `lbu` at 0x6ffc loads 1 byte from a0 (arg0 at entry) +0x4a8.
  The `lw` at 0x7024 loads 4 bytes from a0 (arg0 at entry) +0x578.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x5e0, including `lw` at 0x7028, `lw` at 0x706c, `lw` at 0x70e8.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x5f4, including `lw` at 0x702c, `lw` at 0x7068, `lw` at 0x70e4.
  3 such `lw` accesses load 4 bytes from ?, including `lw` at 0x7058, `lw` at 0x70b8, `lw` at 0x70d8.
  2 such `sb` accesses store 1 byte to ?, including `sb` at 0x7064, `sb` at 0x70dc.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x5f4, including `sw` at 0x707c, `sw` at 0x70f8.
  The `sw` at 0x70e0 stores 4 bytes to ?.
  The `lw` at 0x7110 loads 4 bytes from a0 (arg0 at entry) +0x57c.
  The `jalr` at 0x7088 calls mvpbuffer_init with a0=a0 at entry (arg0), a1=?, a2=?, a3=?, a4=sym(mvpbuffer_init).
  The `jalr` at 0x70c0 calls dms_block_end_dma with a0=?, a1=?, a2=one of 0x1, 0x2, a3=?, a5=sym(dms_block_end_dma).
  The `jalr` at 0x70d4 calls dms_block_detach with a0=?, a1=?, a2=?, a3=?, a6=sym(dms_block_detach).
  The `beq` branch at 0x7014 targets 0x7104, is taken when at(=[a0+1192]:1) == 0, and falls through when at(=[a0+1192]:1) != 0.
  The `beq` branch at 0x7034 targets 0x7084, is taken when a3(=[a0+1524]) >= v1(=[a0+1504]) (unsigned), and falls through when a3(=[a0+1524]) < v1(=[a0+1504]) (unsigned).
  The `beq` branch at 0x705c targets 0x70b0, is taken when s3(=0x2) == a0(?), and falls through when s3(=0x2) != a0(?).
  The `bne` branch at 0x7078 targets 0x703c, is taken when a3(=[a0+1524]+1) < a5(=[a0+1504]) (unsigned), and falls through when a3(=[a0+1524]+1) >= a5(=[a0+1504]) (unsigned).
  The `bne` branch at 0x70f4 targets 0x703c, is taken when a3(=[a0+1524]+1) < a7(=[a0+1504]) (unsigned), and falls through when a3(=[a0+1524]+1) >= a7(=[a0+1504]) (unsigned).
  The `beq` branch at 0x70fc targets 0x7084 and is always taken.
  The `beq` branch at 0x710c targets 0x7028 and is always taken.
  The return at 0x70a8 has v0 = ret(mvpbuffer_init).

- `mvpbuffer_register` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x7114 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x7114-0x725c (328 bytes).
  It occupies 328 bytes.
  2 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x466, including `lbu` at 0x7114, `lbu` at 0x7234.
  The `lw` at 0x7140 loads 4 bytes from a0 (arg0 at entry) +0x4a0.
  The `lbu` at 0x7154 loads 1 byte from a0 (arg0 at entry) +0x4a8.
  3 such `sb` accesses store 1 byte to ?, including `sb` at 0x71d8, `sb` at 0x71ec, `sb` at 0x7204.
  3 such `sw` accesses store 4 bytes to ?, including `sw` at 0x71dc, `sw` at 0x71f0, `sw` at 0x720c.
  The `sw` at 0x722c stores 4 bytes to a0 (arg0 at entry) +0x5a0.
  The `sw` at 0x7230 stores 4 bytes to a0 (arg0 at entry) +0x590.
  The `sw` at 0x723c stores 4 bytes to a0 (arg0 at entry) +0x594.
  The `sb` at 0x7248 stores 1 byte to a0 (arg0 at entry) +0x466.
  The `jalr` at 0x7194 calls bzero with a0=a0+3104, a1=0x2380, a2=a2 at entry (arg2), a3=[a0+1192]:1, a4=sym(bzero), a5=[a0+1126]:1, a6=0x6.
  The `jalr` at 0x71a8 calls bzero with a0=a0 at entry (arg0), a1=0x440, a2=?, a3=?, a5=sym(bzero).
  The `jalr` at 0x71bc calls __dcache_wb with a0=a0 at entry (arg0), a1=0x440, a2=?, a3=?, a6=sym(__dcache_wb).
  The `jalr` at 0x7218 calls mvpbuffer_init with a0=a0 at entry (arg0), a1=?, a2=?, a3=?, a5=0x6.
  The `beq` branch at 0x712c targets 0x7140, is taken when a6(=0x6) == at(?), and falls through when a6(=0x6) != at(?).
  The `bne` branch at 0x714c targets 0x724c, is taken when v1(=[a0+1184]) < 0x3 (signed), and falls through when v1(=[a0+1184]) >= 0x3 (signed).
  The `beq` branch at 0x7158 targets 0x7170, is taken when a3(=[a0+1192]:1) == 0, and falls through when a3(=[a0+1192]:1) != 0.
  The `beq` branch at 0x7160 targets 0x7170, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x7168 targets 0x7138 and is always taken.
  The `beq` branch at 0x7170 targets 0x7254, is taken when a1 == 0, and falls through when a1 != 0.
  The `beq` branch at 0x7180 targets 0x7254, is taken when a2 == 0, and falls through when a2 != 0.
  The `beq` branch at 0x71e0 targets 0x7210, is taken when v0(?) >= 0x10 (signed), and falls through when v0(?) < 0x10 (signed).
  The `beq` branch at 0x71f4 targets 0x7210, is taken when v0(?) >= 0x10 (signed), and falls through when v0(?) < 0x10 (signed).
  The `bne` branch at 0x7208 targets 0x71d0, is taken when v0(?) < 0x10 (signed), and falls through when v0(?) >= 0x10 (signed).
  The `beq` branch at 0x7244 targets 0x7134 and is always taken.
  The `beq` branch at 0x724c targets 0x7138 and is always taken.
  The `beq` branch at 0x7254 targets 0x7134 and is always taken.
  The return at 0x7138 has v0 = one of 0x0, 0xd, 0x3d, 0x47.

- `mvpbuffer_ioctl` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x725c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x725c-0x7348 (236 bytes).
  It occupies 236 bytes.
  The `lbu` at 0x7318 loads 1 byte from a0 (arg0 at entry) +0x4a8.
  The `jalr` at 0x7280 calls mvpcopyin with a0=a2 at entry (arg2), a1=sp-48, a2=0x10, a3=a3 at entry (arg3).
  The `jalr` at 0x72cc calls copyout with a0=sp-48, a1=a2 at entry (arg2), a2=0x10, a3=?.
  The `jalr` at 0x72e0 calls mvpbuffer_close with a0=a0 at entry (arg0), a1=sym(mvpbuffer_close), a2=?, a3=?.
  The `jalr` at 0x7300 calls mvpbuffer_register with a0=a0 at entry (arg0), a1=?, a2=?, a3=sym(mvpbuffer_register).
  The `jalr` at 0x7338 calls mvpbuffer_attach with a0=a0 at entry (arg0), a1=?, a2=?, a3=?, a4=[a0+1192]:1, a5=sym(mvpbuffer_attach).
  The `beq` branch at 0x7288 targets 0x72a4, is taken when v0(=ret(mvpcopyin)) == 0, and falls through when v0(=ret(mvpcopyin)) != 0.
  The `beq` branch at 0x72ac targets 0x72f0, is taken when a0(?) == v0(=0x12d), and falls through when a0(?) != v0(=0x12d).
  The `beq` branch at 0x72b4 targets 0x72dc, is taken when a0(?) == v0(=0x12e), and falls through when a0(?) != v0(=0x12e).
  The `beq` branch at 0x72d4 targets 0x7290 and is always taken.
  The `beq` branch at 0x72e8 targets 0x72c0 and is always taken.
  The `beq` branch at 0x7308 targets 0x7318, is taken when v0(=ret(mvpbuffer_register)) == 0, and falls through when v0(=ret(mvpbuffer_register)) != 0.
  The `beq` branch at 0x7310 targets 0x7294 and is always taken.
  The `beq` branch at 0x731c targets 0x72c0, is taken when a4(=[a0+1192]:1) == 0, and falls through when a4(=[a0+1192]:1) != 0.
  The `beq` branch at 0x7328 targets 0x72c0, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x7340 targets 0x72c0 and is always taken.
  The return at 0x729c has v0 = one of ?, ret(mvpbuffer_register).

- `mvpprobe` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x7348 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x7348-0x7378 (48 bytes).
  It occupies 48 bytes.
  The `jalr` at 0x735c calls pciio_pio_read64 with a0=0xffffffffbf200058, a1=sym(pciio_pio_read64), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x7370 has v0 = ?.

- `mvpcontrol_init` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x7378 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x7378-0x73f0 (120 bytes).
  It occupies 120 bytes.
  The `lw` at 0x738c loads 4 bytes from sym(mvpcontroller_table) +0x0.
  The `sb` at 0x73c8 stores 1 byte to [sym(mvpcontroller_table)] +0x6d.
  The `jalr` at 0x739c calls mvpavio_init with a0=[sym(mvpcontroller_table)], a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x73ac calls mvpreg_init with a0=[sym(mvpcontroller_table)], a1=?, a2=?, a3=?.
  The `jalr` at 0x73c4 calls mvpinterrupt_init with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jalr` at 0x73d8 calls mvptransfer_init with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The return at 0x73e8 has v0 = ret(mvptransfer_init).

- `mvpcontrol_unload` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x73f0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x73f0-0x7434 (68 bytes).
  It occupies 68 bytes.
  The `lw` at 0x7410 loads 4 bytes from sym(mvpcontroller_table) +0x0.
  The `jalr` at 0x740c calls mvpreg_unload with a0=[sym(mvpcontroller_table)], a1=sym(mvpreg_unload), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x741c calls mvpinterrupt_unload with a0=a0 at entry (arg0), a1=?, a2=sym(mvpinterrupt_unload), a3=?.
  The return at 0x742c has v0 = ret(mvpinterrupt_unload).

- `mvpcontrol_setup_output` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x7434 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x7434-0x75d0 (412 bytes).
  It occupies 412 bytes.
  The `lbu` at 0x7438 loads 1 byte from a0 (arg0 at entry) +0x9c.
  The `lbu` at 0x7460 loads 1 byte from a0 (arg0 at entry) +0x6c.
  4 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0xc, including `lbu` at 0x747c, `lbu` at 0x7580, `lbu` at 0x75b0.
  The `lw` at 0x7490 loads 4 bytes from a0 (arg0 at entry) +0xc8.
  The `ld` at 0x74a0 loads 8 bytes from a0 (arg0 at entry) +0x268.
  The `sd` at 0x74cc stores 8 bytes to a0 (arg0 at entry) +0x268.
  The `sd` at 0x74d0 stores 8 bytes to [a0+200] +0x10.
  The `sb` at 0x7524 stores 1 byte to a0 (arg0 at entry) +0x9c.
  The `lbu` at 0x7590 loads 1 byte from a0 (arg0 at entry) +0x61.
  The `jalr` at 0x7494 calls splhi with a0=sym(splhi), a1=[a0+200], a2=?, a3=sym(mvpreg_setup_timing).
  The `jalr` at 0x74dc calls splx with a0=ret(splhi), a1=?, a2=?, a3=sym(splx), a5=[a0+616]:8, a6=-0x19.
  The `jalr` at 0x74f4 calls mvpavio_select_genlock with a0=a0 at entry (arg0), a1=0x0, a2=0x2, a3=?, a4=sym(mvpavio_select_genlock).
  The `jalr` at 0x753c calls mvpreg_setup_timing with a0=a0 at entry (arg0), a1=0x2, a2=?, a3=sym(mvpreg_setup_timing).
  The `jalr` at 0x7554 calls mvpreg_setpassthru with a0=a0 at entry (arg0), a1=?, a2=0x0, a3=?, a4=sym(mvpreg_setpassthru).
  The `jalr` at 0x7574 calls mvpavio_select_output with a0=a0 at entry (arg0), a1=0x2, a2=?, a3=a3 at entry (arg3), a5=sym(mvpavio_select_output).
  The `jalr` at 0x758c calls mvpavio_select_input with a0=a0 at entry (arg0), a1=[a0+97]:1, a2=?, a3=a3 at entry (arg3), a5=0x1, a6=sym(mvpavio_select_input).
  The `jalr` at 0x75a4 calls mvpavio_select_output with a0=a0 at entry (arg0), a1=0x1, a2=?, a3=?, a7=sym(mvpavio_select_output).
  The `jalr` at 0x75c0 calls mvpavio_select_output with a0=a0 at entry (arg0), a1=0x1, a2=?, a3=a3 at entry (arg3), a5=0x1, a6=sym(mvpavio_select_input).
  The `beq` branch at 0x7458 targets 0x7520, is taken when at(=[a0+156]:1) == v0(=0x11), and falls through when at(=[a0+156]:1) != v0(=0x11).
  The `beq` branch at 0x7464 targets 0x7564, is taken when v0(=[a0+108]:1) == a1(=0x2), and falls through when v0(=[a0+108]:1) != a1(=0x2).
  The `beq` branch at 0x746c targets 0x7584, is taken when v0(=[a0+108]:1) == a5(=0x1), and falls through when v0(=[a0+108]:1) != a5(=0x1).
  The `beq` branch at 0x7474 targets 0x75b4, is taken when v0(=[a0+108]:1) == 0, and falls through when v0(=[a0+108]:1) != 0.
  The `beq` branch at 0x7480 targets 0x7530, is taken when v1(=[a0+12]:1) == 0, and falls through when v1(=[a0+12]:1) != 0.
  The `beq` branch at 0x74ac targets 0x7510, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `beq` branch at 0x74c0 targets 0x74d8, is taken when a5(=[a0+616]:8) == a1(?), and falls through when a5(=[a0+616]:8) != a1(?).
  The `beq` branch at 0x7518 targets 0x74c0 and is always taken.
  The `beq` branch at 0x7528 targets 0x7460 and is always taken.
  The `beq` branch at 0x755c targets 0x7500 and is always taken.
  The `beq` branch at 0x757c targets 0x7480 and is always taken.
  The `beq` branch at 0x75ac targets 0x7480 and is always taken.
  The `beq` branch at 0x75c8 targets 0x7480 and is always taken.
  The return at 0x7508 has v0 = one of ret(mvpavio_select_genlock), ret(mvpreg_setpassthru).

- `mvpcontrol_check_output` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x75d0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x75d0-0x768c (188 bytes).
  It occupies 188 bytes.
  The `lw` at 0x760c loads 4 bytes from sym(mvppath_table) +0x0.
  The `lbu` at 0x761c loads 1 byte from [sym(mvppath_table)] +0x466.
  The `lw` at 0x762c loads 4 bytes from [sym(mvppath_table)] +0x4a0.
  The `lbu` at 0x763c loads 1 byte from [sym(mvppath_table)] +0x46c.
  The `lw` at 0x7680 loads 4 bytes from a0 (arg0 at entry) +0x460.
  The `jalr` at 0x75e0 calls splhi with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x7654 calls splx with a0=ret(splhi), a1=?, a2=?, a3=[sym(mvppath_table)], a5=sym(mvppath_table), a7=0x2.
  The `jalr` at 0x767c calls .text+29748 with a0=[a0+1120], a1=sym(mvpcontrol_setup_output), a2=?, a3=?.
  The `beq` branch at 0x75fc targets 0x7608 and is always taken.
  The `beq` branch at 0x7604 targets 0x764c, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `beq` branch at 0x7614 targets 0x7604, is taken when a3(=[sym(mvppath_table)]) == 0, and falls through when a3(=[sym(mvppath_table)]) != 0.
  The `beq` branch at 0x7624 targets 0x7604, is taken when (t0(=[[sym(mvppath_table)]+1126]:1) & 0x4) == 0, and falls through when (t0(=[[sym(mvppath_table)]+1126]:1) & 0x4) != 0.
  The `bne` branch at 0x7634 targets 0x7604, is taken when t1(=[[sym(mvppath_table)]+1184]) < 0x3 (signed), and falls through when t1(=[[sym(mvppath_table)]+1184]) >= 0x3 (signed).
  The `bne` branch at 0x7640 targets 0x7604, is taken when a7(=0x2) != t2(=[[sym(mvppath_table)]+1132]:1), and falls through when a7(=0x2) == t2(=[[sym(mvppath_table)]+1132]:1).
  The `beq` branch at 0x765c targets 0x7674, is taken when s0(=one of 0x0, 0x1) == 0, and falls through when s0(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x7684 targets 0x7668 and is always taken.
  The return at 0x766c has v0 = one of ret(splx), ret(.text+29748).

- `mvpcontrol_resetustmsc` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x768c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x768c-0x7694 (8 bytes).
  It occupies 8 bytes.
  The return at 0x768c has v0 = ?.

- `mvpcontrol_send_changed` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x7694 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x7694-0x7824 (400 bytes).
  It occupies 400 bytes.
  The `sw` at 0x7694 stores 4 bytes to a0 (arg0 at entry) +0x630.
  The `sw` at 0x7698 stores 4 bytes to a0 (arg0 at entry) +0x638.
  The `sw` at 0x76a0 stores 4 bytes to a0 (arg0 at entry) +0x650.
  The `sw` at 0x76a8 stores 4 bytes to a0 (arg0 at entry) +0x62c.
  The `sw` at 0x76b0 stores 4 bytes to a0 (arg0 at entry) +0x6a8.
  2 such `lw` accesses load 4 bytes from [sym(mvppath_table)] +0x578, including `lw` at 0x772c, `lw` at 0x77a8.
  The `lw` at 0x7748 loads 4 bytes from sym(mvppath_table) +0x0.
  The `lbu` at 0x775c loads 1 byte from [sym(mvppath_table)] +0x466.
  The `lw` at 0x776c loads 4 bytes from [sym(mvppath_table)] +0x484.
  2 such `lbu` accesses load 1 byte from [sym(mvppath_table)] +0x4ab, including `lbu` at 0x7784, `lbu` at 0x77ac.
  The `lbu` at 0x7794 loads 1 byte from [sym(mvppath_table)] +0x4b5.
  The `lw` at 0x7798 loads 4 bytes from ?.
  The `sw` at 0x779c stores 4 bytes to a1 (arg1 at entry) +0x4.
  The `lbu` at 0x77c0 loads 1 byte from ?.
  The `jalr` at 0x76f0 calls splhi with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x7730 calls dms_fifo_enq with a0=[[sym(mvppath_table)]+1400], a1=a0+1576, a2=?, a3=?.
  The `jalr` at 0x77a4 calls dms_fifo_enq with a0=[[sym(mvppath_table)]+1400], a1=a0+1576, a2=?, a3=?, a6=[[sym(mvppath_table)]+1195]:1.
  The `jalr` at 0x77ec calls splx with a0=ret(splhi), a1=?, a2=?, a3=sym(splx).
  The `beq` branch at 0x7724 targets 0x7748 and is always taken.
  The `beq` branch at 0x7740 targets 0x77e4, is taken when s5(?) >= 0x40 (signed), and falls through when s5(?) < 0x40 (signed).
  The `beq` branch at 0x7754 targets 0x7738, is taken when s1(=[sym(mvppath_table)]) == 0, and falls through when s1(=[sym(mvppath_table)]) != 0.
  The `beq` branch at 0x7764 targets 0x7738, is taken when (t9(=[[sym(mvppath_table)]+1126]:1) & 0x4) == 0, and falls through when (t9(=[[sym(mvppath_table)]+1126]:1) & 0x4) != 0.
  The `beq` branch at 0x7774 targets 0x7738, is taken when (s7(=a3) & ra(=[[sym(mvppath_table)]+1156])) == 0, and falls through when (s7(=a3) & ra(=[[sym(mvppath_table)]+1156])) != 0.
  The `bne` branch at 0x777c targets 0x772c, is taken when at(?) != 0, and falls through when at(?) == 0.
  The `blez` branch at 0x7788 targets 0x7738, is taken when a6(=[[sym(mvppath_table)]+1195]:1) <= 0 (signed), and falls through when a6(=[[sym(mvppath_table)]+1195]:1) > 0 (signed).
  The `beq` branch at 0x7790 targets 0x77c4 and is always taken.
  The `beq` branch at 0x77b8 targets 0x7738, is taken when s2(?) >= a6(=[[sym(mvppath_table)]+1195]:1) (signed), and falls through when s2(?) < a6(=[[sym(mvppath_table)]+1195]:1) (signed).
  The `beq` branch at 0x77c4 targets 0x7798, is taken when s4(=a2) == a1(?), and falls through when s4(=a2) != a1(?).
  The `bne` branch at 0x77d4 targets 0x77c0, is taken when s2(?) < a6(=[[sym(mvppath_table)]+1195]:1) (signed), and falls through when s2(?) >= a6(=[[sym(mvppath_table)]+1195]:1) (signed).
  The `beq` branch at 0x77dc targets 0x773c and is always taken.
  The return at 0x781c has v0 = ret(splx).

- `mvpcontrol_item_set` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x7824 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x7824-0x7bd0 (940 bytes).
  It occupies 940 bytes.
  The `lw` at 0x7828 loads 4 bytes from a0 (arg0 at entry) +0x4a4.
  The `sh` at 0x785c stores 2 bytes to a0 (arg0 at entry) +0x6b0.
  The `lw` at 0x7860 loads 4 bytes from a2 (arg2 at entry) +0x18.
  The `lw` at 0x7888 loads 4 bytes from (sym(.rodata)+4380 + ([a2+24]-50102 << 0x2)) +0x0.
  Calls (unknown callee) via register with a0=?, a1=0x14, a2=[(sym(.rodata)+4380 + ([a2+24]-50102 << 0x2))], a3=a3 at entry (arg3), a7=sym(mvpframelock_enable) (`jr` at 0x788c).
  The `beq` branch at 0x7848 targets 0x7858, is taken when at(=[a0+1188]) >= 0x3 (signed), and falls through when at(=[a0+1188]) < 0x3 (signed).
  The `beq` branch at 0x7850 targets 0x78b8 and is always taken.
  The `beq` branch at 0x7880 targets 0x78d0, is taken when v1(=[a2+24]-50102) >= 0x10 (unsigned), and falls through when v1(=[a2+24]-50102) < 0x10 (unsigned).
  The `beq` branch at 0x78d0 targets 0x78b8 and is always taken.
  The return at 0x78c8 has v0 = one of 0xd, 0x47.
  The instructions from 0x7894 to 0x78b4 are not reached by any path from the entry, and their branches are not listed.
  The instructions from 0x78d8 to 0x7bcc are not reached by any path from the entry, and their branches are not listed.
  The indirect jump at 0x788c uses a jump table whose successors are unresolved.

- `mvpcontrol_item_get` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x7bd0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x7bd0-0x7d5c (396 bytes).
  It occupies 396 bytes.
  The `lw` at 0x7bd0 loads 4 bytes from a2 (arg2 at entry) +0x18.
  The `lw` at 0x7c04 loads 4 bytes from (sym(.rodata)+4444 + ([a2+24]-50102 << 0x2)) +0x0.
  Calls (unknown callee) via register with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=[(sym(.rodata)+4444 + ([a2+24]-50102 << 0x2))] (`jr` at 0x7c0c).
  The `beq` branch at 0x7bfc targets 0x7c14, is taken when v1(=[a2+24]-50102) >= 0x11 (unsigned), and falls through when v1(=[a2+24]-50102) < 0x11 (unsigned).
  The return at 0x7c1c has v0 = 0x47.
  The instructions from 0x7c24 to 0x7d58 are not reached by any path from the entry, and their branches are not listed.
  The indirect jump at 0x7c0c uses a jump table whose successors are unresolved.

- `mvpcontrol_video_set` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x7d5c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x7d5c-0x7e5c (256 bytes).
  It occupies 256 bytes.
  The `lw` at 0x7d5c loads 4 bytes from a0 (arg0 at entry) +0x4a4.
  The `sh` at 0x7d84 stores 2 bytes to a0 (arg0 at entry) +0x6b0.
  The `lw` at 0x7d88 loads 4 bytes from a2 (arg2 at entry) +0x4.
  The `sw` at 0x7d8c stores 4 bytes to a0 (arg0 at entry) +0x6b8.
  The `lw` at 0x7d90 loads 4 bytes from a2 (arg2 at entry) +0x8.
  The `sw` at 0x7d94 stores 4 bytes to a0 (arg0 at entry) +0x6bc.
  The `lw` at 0x7d98 loads 4 bytes from a2 (arg2 at entry) +0xc.
  The `sw` at 0x7d9c stores 4 bytes to a0 (arg0 at entry) +0x6c0.
  The `lw` at 0x7da0 loads 4 bytes from a2 (arg2 at entry) +0x18.
  3 such `lbu` accesses load 1 byte from a2 (arg2 at entry) +0x24, including `lbu` at 0x7dc8, `lbu` at 0x7df0, `lbu` at 0x7df4.
  4 such `lw` accesses load 4 bytes from a2 (arg2 at entry) +0x1c, including `lw` at 0x7dd4, `lw` at 0x7de8, `lw` at 0x7e2c.
  The `sb` at 0x7de4 stores 1 byte to (a1 + ([a2+36]:1 << 0x2)) +0x74.
  The `lbu` at 0x7e10 loads 1 byte from a2 (arg2 at entry) +0x25.
  The `lbu` at 0x7e30 loads 1 byte from a1 (arg1 at entry) +0xc.
  The `sb` at 0x7e34 stores 1 byte to a1 (arg1 at entry) +0x90.
  The `sb` at 0x7e40 stores 1 byte to a1 (arg1 at entry) +0x94.
  The `jalr` at 0x7dec calls mvpavio_change_timing with a0=a1 at entry (arg1), a1=[a2+36]:1, a2=[a2+28], a3=[a2+8], a4=[a2+4], a5=sym(mvpavio_change_timing), a6=[a2+28], a7=(a1 + ([a2+36]:1 << 0x2)).
  The `jalr` at 0x7e14 calls .text+30356 with a0=a0 at entry (arg0), a1=a0+1712, a2=[a2+37]:1, a3=0x400.
  The `jalr` at 0x7e4c calls mvpcontrol_check_output with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `bne` branch at 0x7d7c targets 0x7db8, is taken when at(=[a0+1188]) < 0x3 (signed), and falls through when at(=[a0+1188]) >= 0x3 (signed).
  The `beq` branch at 0x7db0 targets 0x7dc8, is taken when v1(=[a2+24]) == a0(=0xc3b7), and falls through when v1(=[a2+24]) != a0(=0xc3b7).
  The `beq` branch at 0x7dfc targets 0x7e28, is taken when t0(=[a2+36]:1) == t1(=0xa), and falls through when t0(=[a2+36]:1) != t1(=0xa).
  The `beq` branch at 0x7e20 targets 0x7db8 and is always taken.
  The `bne` branch at 0x7e3c targets 0x7e00, is taken when t9(=[a1+12]:1) != 0, and falls through when t9(=[a1+12]:1) == 0.
  The `beq` branch at 0x7e54 targets 0x7e04 and is always taken.
  The return at 0x7dc0 has v0 = one of 0x0, 0xd, 0x47.

- `mvpcontrol_video_get` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x7e5c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x7e5c-0x7e90 (52 bytes).
  It occupies 52 bytes.
  The `lw` at 0x7e5c loads 4 bytes from a2 (arg2 at entry) +0x18.
  The `lbu` at 0x7e74 loads 1 byte from a2 (arg2 at entry) +0x24.
  The `lbu` at 0x7e80 loads 1 byte from (a1 + ([a2+36]:1 << 0x2)) +0x74.
  The `sw` at 0x7e8c stores 4 bytes to a2 (arg2 at entry) +0x1c.
  The `beq` branch at 0x7e64 targets 0x7e74, is taken when at(=[a2+24]) == v0(=0xc3b7), and falls through when at(=[a2+24]) != v0(=0xc3b7).
  The return at 0x7e6c has v0 = 0x47.
  The return at 0x7e88 has v0 = 0x0.

- `mvpcontrol_i2c_set` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x7e90 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x7e90-0x8010 (384 bytes).
  It occupies 384 bytes.
  The `lw` at 0x7eac loads 4 bytes from a0 (arg0 at entry) +0x4a4.
  2 such `lh` accesses load 2 bytes from ?, including `lh` at 0x7ef0, `lh` at 0x7efc.
  2 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x14, including `lw` at 0x7f08, `lw` at 0x7f44.
  2 such `lhu` accesses load 2 bytes from ?, including `lhu` at 0x7f24, `lhu` at 0x7f28.
  The `lbu` at 0x7f7c loads 1 byte from a2 (arg2 at entry) +0x24.
  The `sh` at 0x7f94 stores 2 bytes to a0 (arg0 at entry) +0x6b0.
  The `lw` at 0x7f98 loads 4 bytes from a2 (arg2 at entry) +0x4.
  The `sw` at 0x7f9c stores 4 bytes to a0 (arg0 at entry) +0x6b8.
  The `lw` at 0x7fa0 loads 4 bytes from a2 (arg2 at entry) +0x8.
  The `sw` at 0x7fa8 stores 4 bytes to a0 (arg0 at entry) +0x6bc.
  The `lw` at 0x7fb0 loads 4 bytes from a2 (arg2 at entry) +0xc.
  The `sw` at 0x7fb8 stores 4 bytes to a0 (arg0 at entry) +0x6c0.
  The `lbu` at 0x7fc4 loads 1 byte from a2 (arg2 at entry) +0x25.
  The `jalr` at 0x7f0c calls mvpavio_i2c_get with a0=[a1+20], a1=?, a2=?, a3=0x0.
  The `jalr` at 0x7f4c calls mvpavio_i2c_put with a0=[a1+20], a1=?, a2=?, a3=?, a4=0x0.
  The `jalr` at 0x7fc0 calls .text+30356 with a0=a0 at entry (arg0), a1=a0+1712, a2=[a2+37]:1, a3=0x400, a4=[a2+36]:1, a5=-0x1, a6=sym(mvpcontrol_send_changed), a7=[a2+12].
  The `bne` branch at 0x7ed8 targets 0x8000, is taken when at(=[a0+1188]) < 0x3 (signed), and falls through when at(=[a0+1188]) >= 0x3 (signed).
  The `beq` branch at 0x7ef4 targets 0x7f7c, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `bltz` branch at 0x7f1c targets 0x7ff8, is taken when a1(?) < 0 (signed), and falls through when a1(?) >= 0 (signed).
  The `bltz` branch at 0x7f60 targets 0x8008, is taken when a2(?) < 0 (signed), and falls through when a2(?) >= 0 (signed).
  The `bne` branch at 0x7f74 targets 0x7ef0, is taken when s0(?) < 0x5 (signed), and falls through when s0(?) >= 0x5 (signed).
  The `beq` branch at 0x7f84 targets 0x7fcc, is taken when a4(=[a2+36]:1) == a5(=-0x1), and falls through when a4(=[a2+36]:1) != a5(=-0x1).
  The `beq` branch at 0x7ff8 targets 0x7fcc and is always taken.
  The `beq` branch at 0x8000 targets 0x7fd0 and is always taken.
  The `beq` branch at 0x8008 targets 0x7fcc and is always taken.
  The return at 0x7ff0 has v0 = one of ?, 0xd.

- `mvpcontrol_i2c_get` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x8010 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x8010-0x8094 (132 bytes).
  It occupies 132 bytes.
  3 such `lhu` accesses load 2 bytes from ?, including `lhu` at 0x803c, `lhu` at 0x804c, `lhu` at 0x805c.
  The `lw` at 0x8048 loads 4 bytes from a1 (arg1 at entry) +0x14.
  The `sh` at 0x8070 stores 2 bytes to ?.
  The `jalr` at 0x8050 calls mvpavio_i2c_get with a0=[a1+20], a1=?, a2=?, a3=0x0.
  The `beq` branch at 0x8040 targets 0x8074, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `bne` branch at 0x806c targets 0x803c, is taken when s1(?) < 0x5 (signed), and falls through when s1(?) >= 0x5 (signed).
  The return at 0x808c has v0 = 0x0.

- `mvpcontrol_path_set` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x8094 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x8094-0x80c8 (52 bytes).
  It occupies 52 bytes.
  The `jalr` at 0x80b0 calls bcopy with a0=a1+24, a1=a0+2984, a2=0x78, a3=a3 at entry (arg3).
  The return at 0x80c0 has v0 = 0x0.

- `mvpcontrol_ioctl` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x80c8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x80c8-0x836c (676 bytes).
  It occupies 676 bytes.
  The `lbu` at 0x8114 loads 1 byte from a0 (arg0 at entry) +0x466.
  The `lw` at 0x8124 loads 4 bytes from a0 (arg0 at entry) +0x460.
  The `lw` at 0x814c loads 4 bytes from table(sym(.rodata)+4512) +0x0.
  The `jalr` at 0x80f0 calls mvpcopyin with a0=a2 at entry (arg2), a1=sp-208, a2=0x90, a3=a3 at entry (arg3).
  The `beq` branch at 0x80f8 targets 0x8114, is taken when v0(=ret(mvpcopyin)) == 0, and falls through when v0(=ret(mvpcopyin)) != 0.
  The `beq` branch at 0x811c targets 0x8164, is taken when (v0(=[a0+1126]:1) & 0x4) == 0, and falls through when (v0(=[a0+1126]:1) & 0x4) != 0.
  The `beq` branch at 0x8128 targets 0x816c, is taken when v0(=[a0+1120]) == 0, and falls through when v0(=[a0+1120]) != 0.
  The `beq` branch at 0x8144 targets 0x8158, is taken when a1(?) >= 0xb (unsigned), and falls through when a1(?) < 0xb (unsigned).
  The `beq` branch at 0x815c targets 0x8100 and is always taken.
  The `beq` branch at 0x8164 targets 0x8100 and is always taken.
  The `beq` branch at 0x816c targets 0x8100 and is always taken.
  The return at 0x810c has v0 = one of ret(mvpcopyin), 0x16, 0xd, 0x47.
  The instructions from 0x8174 to 0x8368 are not reached by any path from the entry, and their branches are not listed.
  The indirect jump at 0x8150 uses a jump table whose successors are unresolved.

- `mvperrprintf` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x836c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x836c-0x8438 (204 bytes).
  It occupies 204 bytes.
  The `lw` at 0x83a8 loads 4 bytes from (sym(.rodata)+4560 + (a0 << 0x2)) +0x0.
  Calls (unknown callee) via register with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3) (`jr` at 0x83ac).
  The `jalr` at 0x83c0 calls icmn_err with a0=0x1, a1=a1 at entry (arg1), a2=sp-48, a3=a3 at entry (arg3).
  The `beq` branch at 0x83a0 targets 0x83b4, is taken when a0 >= 0x9 (unsigned), and falls through when a0 < 0x9 (unsigned).
  The return at 0x83cc has v0 = ret(icmn_err).
  The instructions from 0x83d4 to 0x8434 are not reached by any path from the entry, and their branches are not listed.
  The indirect jump at 0x83ac uses a jump table whose successors are unresolved.

- `mvpass_break` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x8438 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x8438-0x8440 (8 bytes).
  It occupies 8 bytes.
  The return at 0x8438 has v0 = ?.

- `mvpass_fail` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x8440 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x8440-0x848c (76 bytes).
  It occupies 76 bytes.
  The `jalr` at 0x8468 calls mvperrprintf with a0=0x6, a1=sym(.rodata)+4600, a2=a0 at entry (arg0), a3=a1 at entry (arg1), a4=a2 at entry (arg2), a5=sym(mvperrprintf), a6=a0 at entry (arg0).
  The `jalr` at 0x8478 calls mvpass_break with a0=?, a1=?, a2=?, a3=?, a6=sym(mvpass_break).
  The return at 0x8484 has v0 = ret(mvpass_break).

- `mvpdebug_init` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x848c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x848c-0x84e4 (88 bytes).
  It occupies 88 bytes.
  The `lw` at 0x84c8 loads 4 bytes from sym(mvp_umba) +0x9d8.
  The `sw` at 0x84d0 stores 4 bytes to sym(mvp_umba) +0x9d8.
  The `jalr` at 0x84a0 calls is_specified with a0=sym(arg_showconfig), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x84bc calls atoi with a0=sym(arg_showconfig), a1=sym(atoi), a2=?, a3=?.
  The `beq` branch at 0x84a8 targets 0x84d8, is taken when v0(=ret(is_specified)) == 0, and falls through when v0(=ret(is_specified)) != 0.
  The return at 0x84dc has v0 = 0x0.

- `mvpdebug_unload` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x84e4 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x84e4-0x84ec (8 bytes).
  It occupies 8 bytes.
  The return at 0x84e4 has v0 = ?.

- `mvpi2c_printerror` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x84ec (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x84ec-0x8520 (52 bytes).
  It occupies 52 bytes.
  The `lw` at 0x84f8 loads 4 bytes from sym(mvptransfer_stats) +0xf8.
  The `jalr` at 0x850c calls qprintf with a0=sym(.rodata)+4648, a1=[sym(.bss)+248], a2=[sym(.bss)+248], a3=a3 at entry (arg3).
  The return at 0x8518 has v0 = ret(qprintf).

- `mvpi2c_register_av` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x8520 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x8520-0x856c (76 bytes).
  It occupies 76 bytes.
  The `lw` at 0x8524 loads 4 bytes from sym(mvp_umba) +0xa18.
  The `jalr` at 0x8558 calls mvperrprintf with a0=0x5, a1=sym(.rodata)+4672, a2=[sym(.data)+2584]+1, a3=sym(mvperrprintf).
  The `beq` branch at 0x8530 targets 0x8544, is taken when v0(=[sym(.data)+2584]) >= 0x2 (signed), and falls through when v0(=[sym(.data)+2584]) < 0x2 (signed).
  The `beq` branch at 0x8564 targets 0x853c and is always taken.
  The return at 0x853c has v0 = one of -0x1, 0x0.

- `mvpi2c_config` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x856c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x856c-0x8638 (204 bytes).
  It occupies 204 bytes.
  The `sd` at 0x8628 stores 8 bytes to a0 (arg0 at entry) +0x0.
  The `jalr` at 0x8590 calls pciio_pio_read64 with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0x85b4 targets 0x85cc, is taken when (s0(=a1) & 0x1) == 0, and falls through when (s0(=a1) & 0x1) != 0.
  The `beq` branch at 0x85d0 targets 0x85dc, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x85e4 targets 0x8600, is taken when (s0(=a1) & 0x4) == 0, and falls through when (s0(=a1) & 0x4) != 0.
  The `beq` branch at 0x8604 targets 0x8624, is taken when (s0(=a1) & 0x8) == 0, and falls through when (s0(=a1) & 0x8) != 0.
  The return at 0x8630 has v0 = 0x0.

- `mvpi2c_read_config` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x8638 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x8638-0x8660 (40 bytes).
  It occupies 40 bytes.
  The `jalr` at 0x8648 calls pciio_pio_read64 with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x8658 has v0 = 0x0.

- `mvpi2c_reset` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x8660 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x8660-0x8718 (184 bytes).
  It occupies 184 bytes.
  The `lw` at 0x8668 loads 4 bytes from sym(mvp_umba) +0x9fc.
  2 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x0, including `sd` at 0x8690, `sd` at 0x8704.
  2 such `lw` accesses load 4 bytes from sym(mvpi2c_default_avb) +0x0, including `lw` at 0x8698, `lw` at 0x86e4.
  The `lh` at 0x86a8 loads 2 bytes from [sym(mvpi2c_default_avb)] +0xc.
  The `lw` at 0x86ac loads 4 bytes from sym(mvp_umba) +0xa04.
  The `lw` at 0x86b0 loads 4 bytes from sym(mvp_umba) +0xa00.
  The `lbu` at 0x86f4 loads 1 byte from [sym(mvpi2c_default_avb)] +0xb.
  The `jalr` at 0x86d4 calls us_delay with a0=?, a1=sym(us_delay), a2=?, a3=?, a4=sym(mvpi2c_autoincr_disable), a5=[sym(.data)+2560], a6=[sym(.data)+2564].
  The `beq` branch at 0x8678 targets 0x868c, is taken when at(=[sym(.data)+2556]) == 0, and falls through when at(=[sym(.data)+2556]) != 0.
  The `beq` branch at 0x86a0 targets 0x86ac, is taken when v0(=[sym(mvpi2c_default_avb)]) == 0, and falls through when v0(=[sym(mvpi2c_default_avb)]) != 0.
  The `beq` branch at 0x86ec targets 0x8710, is taken when v0(=[sym(mvpi2c_default_avb)]) == 0, and falls through when v0(=[sym(mvpi2c_default_avb)]) != 0.
  The `beq` branch at 0x86fc targets 0x8710, is taken when (v1(=[[sym(mvpi2c_default_avb)]+11]:1) & 0x8) == 0, and falls through when (v1(=[[sym(mvpi2c_default_avb)]+11]:1) & 0x8) != 0.
  The `beq` branch at 0x8708 targets 0x8680 and is always taken.
  The `beq` branch at 0x8710 targets 0x8704 and is always taken.
  The return at 0x8684 has v0 = 0x0.

- `mvpi2c_fastmode` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x8718 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x8718-0x8770 (88 bytes).
  It occupies 88 bytes.
  The `lw` at 0x8720 loads 4 bytes from a0 (arg0 at entry) +0x10.
  The `lw` at 0x8724 loads 4 bytes from sym(mvpi2c_fastmode_disable) +0x0.
  2 such `sd` accesses store 8 bytes to [a0+16] +0x0, including `sd` at 0x8730, `sd` at 0x8754.
  2 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0xb, including `lbu` at 0x8734, `lbu` at 0x8758.
  2 such `sh` accesses store 2 bytes to a0 (arg0 at entry) +0xc, including `sh` at 0x873c, `sh` at 0x8760.
  2 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0xb, including `sb` at 0x8744, `sb` at 0x876c.
  The `beq` branch at 0x871c targets 0x872c, is taken when a1 == 0, and falls through when a1 != 0.
  The `beq` branch at 0x8728 targets 0x8750, is taken when at(=[sym(mvpi2c_fastmode_disable)]) == 0, and falls through when at(=[sym(mvpi2c_fastmode_disable)]) != 0.
  The return at 0x8748 has v0 = ?.
  The return at 0x8768 has v0 = ?.

- `mvpi2c_check` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x8770 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x8770-0x8814 (164 bytes).
  It occupies 164 bytes.
  The `lw` at 0x8784 loads 4 bytes from sym(mvp_umba) +0x9f0.
  The `lw` at 0x8788 loads 4 bytes from sym(mvp_umba) +0x9e0.
  The `lw` at 0x878c loads 4 bytes from sym(mvp_umba) +0x9e4.
  The `lw` at 0x8798 loads 4 bytes from sym(mvp_umba) +0x9f4.
  The `sw` at 0x879c stores 4 bytes to [sym(.data)+2544] +0x0.
  2 such `sw` accesses store 4 bytes to sym(mvp_umba) +0x9e4, including `sw` at 0x87a8, `sw` at 0x87fc.
  The `jalr` at 0x87b4 calls mvpi2c_reset with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a4=[sym(.data)+2548], a5=[sym(.data)+2544], a6=sym(mvpi2c_autoincr_disable), a7=sym(mvpi2c_reset).
  The `jalr` at 0x87d4 calls mvperrprintf with a0=0x5, a1=sym(.rodata)+4704, a2=sym(mvperrprintf), a3=sym(pciio_pio_read64).
  The `jalr` at 0x8804 calls pciio_pio_read64 with a0=a0+16, a1=?, a2=?, a3=sym(pciio_pio_read64).
  The `beq` branch at 0x8794 targets 0x87a0, is taken when a5(=[sym(.data)+2544]) == 0, and falls through when a5(=[sym(.data)+2544]) != 0.
  The `beq` branch at 0x87a0 targets 0x87f0, is taken when v0(=[sym(.data)+2528]) == 0, and falls through when v0(=[sym(.data)+2528]) != 0.
  The `beq` branch at 0x87bc targets 0x8800, is taken when v0(=ret(mvpi2c_reset)) == 0, and falls through when v0(=ret(mvpi2c_reset)) != 0.
  The `beq` branch at 0x87f0 targets 0x87b0, is taken when a7(=[sym(.data)+2532]) == a2, and falls through when a7(=[sym(.data)+2532]) != a2.
  The `beq` branch at 0x87f8 targets 0x87ac and is always taken.
  The `beq` branch at 0x880c targets 0x87e0 and is always taken.
  The return at 0x87e8 has v0 = one of 0x0, 0x5.

- `_mvpi2c_wait_for_xfer_done` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x8814 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x8814-0x895c (328 bytes).
  It occupies 328 bytes.
  2 such `lw` accesses load 4 bytes from sym(mvpi2c_default_avb) +0x0, including `lw` at 0x8874, `lw` at 0x88dc.
  The `lh` at 0x88a8 loads 2 bytes from [sym(mvpi2c_default_avb)] +0xc.
  The `lw` at 0x88ac loads 4 bytes from sym(mvp_umba) +0xa08.
  The `lw` at 0x88b0 loads 4 bytes from sym(mvp_umba) +0xa00.
  The `lw` at 0x8928 loads 4 bytes from sym(mvptransfer_stats) +0xfc.
  The `sw` at 0x8938 stores 4 bytes to sym(mvptransfer_stats) +0xfc.
  The `jalr` at 0x8864 calls pciio_pio_read64 with a0=a0+16, a1=?, a2=?, a3=?.
  The `jalr` at 0x88cc calls us_delay with a0=?, a1=?, a2=?, a3=?, a4=[sym(mvpi2c_default_avb)].
  The `jalr` at 0x890c calls mvpi2c_check with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0x2, a3=sym(.rodata)+4648.
  The `jalr` at 0x894c calls qprintf with a0=sym(.rodata)+4648, a1=sym(.bss)+248, a2=sym(qprintf), a3=?.
  The `bltz` branch at 0x8870 targets 0x88a0, is taken when t8(=(ret(pciio_pio_read64) << 0x3b)) < 0 (signed), and falls through when t8(=(ret(pciio_pio_read64) << 0x3b)) >= 0 (signed).
  The `beq` branch at 0x88a0 targets 0x88ac, is taken when a4(=[sym(mvpi2c_default_avb)]) == 0, and falls through when a4(=[sym(mvpi2c_default_avb)]) != 0.
  The `bgtz` branch at 0x88d8 targets 0x8864, is taken when s1(?) > 0 (signed), and falls through when s1(?) <= 0 (signed).
  The `bne` branch at 0x88e0 targets 0x88f0, is taken when v0(=[sym(mvpi2c_default_avb)]) != 0, and falls through when v0(=[sym(mvpi2c_default_avb)]) == 0.
  The `beq` branch at 0x88e8 targets 0x8880 and is always taken.
  The `beq` branch at 0x8914 targets 0x8924, is taken when v0(=ret(mvpi2c_check)) == 0, and falls through when v0(=ret(mvpi2c_check)) != 0.
  The `beq` branch at 0x891c targets 0x887c and is always taken.
  The `beq` branch at 0x8934 targets 0x8944, is taken when a0(=[sym(.bss)+252]+1) == a2(=0xa), and falls through when a0(=[sym(.bss)+252]+1) != a2(=0xa).
  The `beq` branch at 0x893c targets 0x887c and is always taken.
  The `beq` branch at 0x8954 targets 0x893c and is always taken.
  The return at 0x8898 has v0 = one of 0x0, 0x5, 0xb, 0x13.

- `_mvpi2c_wait_for_ack` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x895c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x895c-0x8ae0 (388 bytes).
  It occupies 388 bytes.
  The `lw` at 0x89ac loads 4 bytes from sym(mvp_umba) +0x9ec.
  3 such `lw` accesses load 4 bytes from sym(mvpi2c_default_avb) +0x0, including `lw` at 0x89d4, `lw` at 0x8a54, `lw` at 0x8a58.
  The `lh` at 0x89e0 loads 2 bytes from [sym(mvpi2c_default_avb)] +0xc.
  The `lw` at 0x89ec loads 4 bytes from sym(mvp_umba) +0xa00.
  The `lw` at 0x89f0 loads 4 bytes from sym(mvp_umba) +0xa0c.
  The `jalr` at 0x8988 calls pciio_pio_read64 with a0=a0+16, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x8a14 calls us_delay with a0=?, a1=?, a2=sym(us_delay), a3=?, a4=[sym(.data)+2560], a5=[sym(.data)+2572].
  The `jalr` at 0x8a1c calls pciio_pio_read64 with a0=a0+16, a1=?, a2=?, a3=?.
  The `jalr` at 0x8a7c calls mvpi2c_check with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0x1, a3=sym(.rodata)+4776, a4=sym(mvpi2c_check), a6=(ret(pciio_pio_read64) << 0x3a), a7=[sym(mvpi2c_default_avb)].
  The `jalr` at 0x8aa8 calls .text+34836 with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?, a5=sym(_mvpi2c_wait_for_xfer_done).
  The `jalr` at 0x8ad0 calls pciio_pio_read64 with a0=a0+16, a1=?, a2=?, a3=?.
  The `beq` branch at 0x8994 targets 0x89a4, is taken when s0(=a2) == 0, and falls through when s0(=a2) != 0.
  The `bltz` branch at 0x89a0 targets 0x8a9c, is taken when t9(=(ret(pciio_pio_read64) << 0x3b)) < 0 (signed), and falls through when t9(=(ret(pciio_pio_read64) << 0x3b)) >= 0 (signed).
  The `beq` branch at 0x89c0 targets 0x8a94, is taken when ra(=[sym(.data)+2540]) == 0, and falls through when ra(=[sym(.data)+2540]) != 0.
  The `bgez` branch at 0x89cc targets 0x8a94, is taken when a1(=(ret(pciio_pio_read64) << 0x3a)) >= 0 (signed), and falls through when a1(=(ret(pciio_pio_read64) << 0x3a)) < 0 (signed).
  The `beq` branch at 0x89d8 targets 0x89e4, is taken when a2(=[sym(mvpi2c_default_avb)]) == 0, and falls through when a2(=[sym(mvpi2c_default_avb)]) != 0.
  The `bltz` branch at 0x8a28 targets 0x8a50, is taken when a6(=(ret(pciio_pio_read64) << 0x3a)) < 0 (signed), and falls through when a6(=(ret(pciio_pio_read64) << 0x3a)) >= 0 (signed).
  The `bne` branch at 0x8a50 targets 0x89d8, is taken when s0(?) != 0, and falls through when s0(?) == 0.
  The `beq` branch at 0x8a5c targets 0x8ac0, is taken when a7(=[sym(mvpi2c_default_avb)]) == 0, and falls through when a7(=[sym(mvpi2c_default_avb)]) != 0.
  The `beq` branch at 0x8a84 targets 0x8ac8, is taken when v0(=ret(mvpi2c_check)) == 0, and falls through when v0(=ret(mvpi2c_check)) != 0.
  The `beq` branch at 0x8a8c targets 0x8a34 and is always taken.
  The `beq` branch at 0x8a94 targets 0x8a38 and is always taken.
  The `beq` branch at 0x8ab0 targets 0x8ad0, is taken when v0(=ret(.text+34836)) == 0, and falls through when v0(=ret(.text+34836)) != 0.
  The `beq` branch at 0x8ab8 targets 0x8a38 and is always taken.
  The `beq` branch at 0x8ac0 targets 0x8a38 and is always taken.
  The `beq` branch at 0x8ac8 targets 0x8a34 and is always taken.
  The `beq` branch at 0x8ad8 targets 0x89a4 and is always taken.
  The return at 0x8a48 has v0 = one of 0x0, 0x5, 0xb, ret(.text+34836), 0x13.

- `_mvpi2c_force_bus_idle` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x8ae0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x8ae0-0x8cbc (476 bytes).
  It occupies 476 bytes.
  2 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x10, including `sd` at 0x8b44, `sd` at 0x8c80.
  2 such `lw` accesses load 4 bytes from sym(mvpi2c_default_avb) +0x0, including `lw` at 0x8b48, `lw` at 0x8be0.
  2 such `lh` accesses load 2 bytes from [sym(mvpi2c_default_avb)] +0xc, including `lh` at 0x8b54, `lh` at 0x8b98.
  2 such `lw` accesses load 4 bytes from sym(mvp_umba) +0xa10, including `lw` at 0x8b60, `lw` at 0x8b9c.
  2 such `lw` accesses load 4 bytes from sym(mvp_umba) +0xa00, including `lw` at 0x8b64, `lw` at 0x8ba0.
  The `jalr` at 0x8b14 calls pciio_pio_read64 with a0=a0+16, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x8b88 calls us_delay with a0=?, a1=sym(mvpi2c_default_avb), a2=?, a3=?.
  The `jalr` at 0x8bbc calls us_delay with a0=?, a1=?, a2=?, a3=?.
  The `jalr` at 0x8bc4 calls pciio_pio_read64 with a0=a0+16, a1=?, a2=?, a3=?.
  The `jalr` at 0x8c0c calls mvpi2c_check with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0x3, a3=sym(.rodata)+4808, a4=sym(mvpi2c_check).
  The `jalr` at 0x8c50 calls pciio_pio_read64 with a0=a0+16, a1=?, a2=?, a3=?.
  The `jalr` at 0x8c9c calls mvpi2c_check with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0x4, a3=sym(.rodata)+4832, a4=sym(mvpi2c_check), a6=0x1.
  The `beq` branch at 0x8b38 targets 0x8c7c, is taken when (v0(=ret(pciio_pio_read64)) & 0x1) == 0, and falls through when (v0(=ret(pciio_pio_read64)) & 0x1) != 0.
  The `beq` branch at 0x8b4c targets 0x8b58, is taken when v0(=[sym(mvpi2c_default_avb)]) == 0, and falls through when v0(=[sym(mvpi2c_default_avb)]) != 0.
  The `beq` branch at 0x8b90 targets 0x8be0 and is always taken.
  The `beq` branch at 0x8bd0 targets 0x8c48, is taken when (v0(=ret(pciio_pio_read64)) & 0x1) == 0, and falls through when (v0(=ret(pciio_pio_read64)) & 0x1) != 0.
  The `beq` branch at 0x8bdc targets 0x8bf4, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `bne` branch at 0x8be4 targets 0x8b98, is taken when v0(=[sym(mvpi2c_default_avb)]) != 0, and falls through when v0(=[sym(mvpi2c_default_avb)]) == 0.
  The `beq` branch at 0x8bec targets 0x8b9c and is always taken.
  The `beq` branch at 0x8c14 targets 0x8c74, is taken when v0(=ret(mvpi2c_check)) == 0, and falls through when v0(=ret(mvpi2c_check)) != 0.
  The `beq` branch at 0x8c48 targets 0x8bf8, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0x8c64 targets 0x8c84, is taken when a5(?) == a6(=0x1), and falls through when a5(?) != a6(=0x1).
  The `beq` branch at 0x8c6c targets 0x8c20 and is always taken.
  The `beq` branch at 0x8c74 targets 0x8c1c and is always taken.
  The `beq` branch at 0x8c7c targets 0x8c1c and is always taken.
  The `beq` branch at 0x8ca4 targets 0x8cb4, is taken when v0(=ret(mvpi2c_check)) == 0, and falls through when v0(=ret(mvpi2c_check)) != 0.
  The `beq` branch at 0x8cac targets 0x8c1c and is always taken.
  The `beq` branch at 0x8cb4 targets 0x8c1c and is always taken.
  The return at 0x8c40 has v0 = one of 0x0, 0x5, 0xb.

- `mvpi2c_read_reg` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x8cbc (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x8cbc-0x8f90 (724 bytes).
  It occupies 724 bytes.
  2 such `lw` accesses load 4 bytes from sym(mvpmutex_locked) +0x0, including `lw` at 0x8cfc, `lw` at 0x8d7c.
  2 such `sw` accesses store 4 bytes to sym(mvpmutex_locked) +0x0, including `sw` at 0x8d08, `sw` at 0x8d94.
  The `lw` at 0x8d10 loads 4 bytes from sym(mvp_umba) +0x9f8.
  The `lh` at 0x8d1c loads 2 bytes from a1 (arg1 at entry) +0x14.
  7 such `sw` accesses store 4 bytes to sym(mvptransfer_stats) +0xf8, including `sw` at 0x8d50, `sw` at 0x8dc4, `sw` at 0x8e0c.
  The `lbu` at 0x8dc8 loads 1 byte from a2 (arg2 at entry) +0xd.
  The `lbu` at 0x8ddc loads 1 byte from a2 (arg2 at entry) +0xb.
  3 such `lbu` accesses load 1 byte from a1 (arg1 at entry) +0xe, including `lbu` at 0x8dec, `lbu` at 0x8e14, `lbu` at 0x8f30.
  4 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x18, including `sd` at 0x8df8, `sd` at 0x8e2c, `sd` at 0x8e64.
  4 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x10, including `sd` at 0x8e4c, `sd` at 0x8e94, `sd` at 0x8eb8.
  2 such `lbu` accesses load 1 byte from a2 (arg2 at entry) +0x8, including `lbu` at 0x8e58, `lbu` at 0x8ee8.
  The `lbu` at 0x8ec4 loads 1 byte from a2 (arg2 at entry) +0xc.
  The `jalr` at 0x8cec calls mutex_lock with a0=sym(mvpmutex), a1=0x0, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x8d38 calls .text+35552 with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0x5, a3=sym(_mvpi2c_force_bus_idle).
  The `jalr` at 0x8d68 calls mutex_unlock with a0=sym(mvpmutex), a1=?, a2=?, a3=?, a5=sym(mutex_unlock).
  The `jalr` at 0x8da8 calls .text+35552 with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0x5, a3=sym(_mvpi2c_force_bus_idle).
  The `jalr` at 0x8df4 calls .text+35164 with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0x1, a3=?, a6=[a1+14]:1, a7=sym(_mvpi2c_wait_for_ack).
  The `jalr` at 0x8e28 calls .text+35164 with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0x1, a3=?.
  The `jalr` at 0x8e60 calls .text+35164 with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0x1, a3=?.
  The `jalr` at 0x8e90 calls .text+34836 with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?.
  The `jalr` at 0x8eac calls pciio_pio_read64 with a0=a0+24, a1=?, a2=?, a3=?.
  The `jalr` at 0x8eec calls mvperrprintf with a0=0x5, a1=sym(.rodata)+4848, a2=[a2+8]:1, a3=[a2+12]:1, a4=(ret(pciio_pio_read64) << 0x0), a5=sym(mvperrprintf).
  The `jalr` at 0x8f0c calls .text+35552 with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0x5, a3=?, a6=sym(_mvpi2c_force_bus_idle).
  The `jalr` at 0x8f44 calls .text+35164 with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0x1, a3=?, a7=sym(.bss)+248.
  The `jalr` at 0x8f74 calls .text+34836 with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?.
  The `beq` branch at 0x8d04 targets 0x8d98, is taken when v0(=-0x2) == s2(=a2), and falls through when v0(=-0x2) != s2(=a2).
  The `beq` branch at 0x8d14 targets 0x8dc8, is taken when a0(=[sym(.data)+2552]) == 0, and falls through when a0(=[sym(.data)+2552]) != 0.
  The `beq` branch at 0x8d24 targets 0x8d98, is taken when (a1(=[a1+20]:2) & 0x2) == 0, and falls through when (a1(=[a1+20]:2) & 0x2) != 0.
  The `beq` branch at 0x8d40 targets 0x8de0, is taken when v0(=ret(.text+35552)) == 0, and falls through when v0(=ret(.text+35552)) != 0.
  The `beq` branch at 0x8db0 targets 0x8e10, is taken when v0(=ret(.text+35552)) == 0, and falls through when v0(=ret(.text+35552)) != 0.
  The `beq` branch at 0x8dc0 targets 0x8d54 and is always taken.
  The `bne` branch at 0x8dd0 targets 0x8d1c, is taken when (a5(=[a2+13]:1) & 0x2) != 0, and falls through when (a5(=[a2+13]:1) & 0x2) == 0.
  The `beq` branch at 0x8dd8 targets 0x8d54 and is always taken.
  The `beq` branch at 0x8dfc targets 0x8e44, is taken when v0(=ret(.text+35164)) == 0, and falls through when v0(=ret(.text+35164)) != 0.
  The `beq` branch at 0x8e08 targets 0x8d54 and is always taken.
  The `beq` branch at 0x8e30 targets 0x8e7c, is taken when v0(=ret(.text+35164)) == 0, and falls through when v0(=ret(.text+35164)) != 0.
  The `beq` branch at 0x8e3c targets 0x8d54 and is always taken.
  The `beq` branch at 0x8e68 targets 0x8efc, is taken when v0(=ret(.text+35164)) == 0, and falls through when v0(=ret(.text+35164)) != 0.
  The `beq` branch at 0x8e74 targets 0x8d54 and is always taken.
  The `bne` branch at 0x8e9c targets 0x8d54, is taken when 0 < v0(=ret(.text+34836)) (unsigned), and falls through when 0 >= v0(=ret(.text+34836)) (unsigned).
  The `beq` branch at 0x8ebc targets 0x8d54, is taken when a1(=-0x2) == s2(=a2), and falls through when a1(=-0x2) != s2(=a2).
  The `beq` branch at 0x8ed4 targets 0x8d54, is taken when (s0(=(ret(pciio_pio_read64) << 0x0)) & a2(?)) == 0, and falls through when (s0(=(ret(pciio_pio_read64) << 0x0)) & a2(?)) != 0.
  The `beq` branch at 0x8ef4 targets 0x8d58 and is always taken.
  The `beq` branch at 0x8f14 targets 0x8f28, is taken when v0(=ret(.text+35552)) == 0, and falls through when v0(=ret(.text+35552)) != 0.
  The `beq` branch at 0x8f20 targets 0x8d54 and is always taken.
  The `beq` branch at 0x8f4c targets 0x8f64, is taken when v0(=ret(.text+35164)) == 0, and falls through when v0(=ret(.text+35164)) != 0.
  The `beq` branch at 0x8f5c targets 0x8d54 and is always taken.
  The `bne` branch at 0x8f80 targets 0x8d54, is taken when 0 < v0(=ret(.text+34836)) (unsigned), and falls through when 0 >= v0(=ret(.text+34836)) (unsigned).
  The `beq` branch at 0x8f88 targets 0x8ea8 and is always taken.
  The return at 0x8d90 has v0 = ?.

- `_mvpi2c_write_adrs` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x8f90 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x8f90-0x9098 (264 bytes).
  It occupies 264 bytes.
  The `lw` at 0x8fcc loads 4 bytes from sym(mvp_umba) +0x9e8.
  The `lbu` at 0x9024 loads 1 byte from a1 (arg1 at entry) +0xe.
  2 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x18, including `sd` at 0x9030, `sd` at 0x906c.
  The `jalr` at 0x8fe0 calls .text+35552 with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0x4, a3=?.
  The `jalr` at 0x902c calls .text+35164 with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0x1, a3=?.
  The `jalr` at 0x9068 calls .text+35164 with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0x1, a3=a2 at entry (arg2), a4=sym(_mvpi2c_wait_for_ack).
  The `beq` branch at 0x8fc8 targets 0x8fd8 and is always taken.
  The `bltz` branch at 0x8fd0 targets 0x8ff8, is taken when t8(?) < 0 (signed), and falls through when t8(?) >= 0 (signed).
  The `beq` branch at 0x8fe8 targets 0x9018, is taken when v0(=ret(.text+35552)) == 0, and falls through when v0(=ret(.text+35552)) != 0.
  The `beq` branch at 0x8ff0 targets 0x8fd0, is taken when v0(=ret(.text+35552)) == s4(=0xb), and falls through when v0(=ret(.text+35552)) != s4(=0xb).
  The `beq` branch at 0x9034 targets 0x9054, is taken when v0(=ret(.text+35164)) == 0, and falls through when v0(=ret(.text+35164)) != 0.
  The `bne` branch at 0x903c targets 0x904c, is taken when v0(=ret(.text+35164)) != s4(=0xb), and falls through when v0(=ret(.text+35164)) == s4(=0xb).
  The `bgez` branch at 0x9044 targets 0x8fd8, is taken when v1(?) >= 0 (signed), and falls through when v1(?) < 0 (signed).
  The `beq` branch at 0x904c targets 0x8ffc and is always taken.
  The `beq` branch at 0x9070 targets 0x9090, is taken when v0(=ret(.text+35164)) == 0, and falls through when v0(=ret(.text+35164)) != 0.
  The `bne` branch at 0x9078 targets 0x9088, is taken when v0(=ret(.text+35164)) != s4(=0xb), and falls through when v0(=ret(.text+35164)) == s4(=0xb).
  The `bgez` branch at 0x9080 targets 0x8fd8, is taken when a5(?) >= 0 (signed), and falls through when a5(?) < 0 (signed).
  The `beq` branch at 0x9088 targets 0x8ffc and is always taken.
  The `beq` branch at 0x9090 targets 0x8ff8 and is always taken.
  The return at 0x9010 has v0 = one of ?, ret(.text+35164).

- `mvpi2c_write_reg` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x9098 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x9098-0x92ec (596 bytes).
  It occupies 596 bytes.
  The `lw` at 0x90e4 loads 4 bytes from sym(mvp_umba) +0x9e8.
  2 such `lw` accesses load 4 bytes from sym(mvp_umba) +0xa14, including `lw` at 0x90f0, `lw` at 0x91b0.
  2 such `sw` accesses store 4 bytes to sym(mvp_umba) +0xa14, including `sw` at 0x9100, `sw` at 0x91c4.
  2 such `lw` accesses load 4 bytes from sym(mvpmutex_locked) +0x0, including `lw` at 0x9120, `lw` at 0x9198.
  2 such `sw` accesses store 4 bytes to sym(mvpmutex_locked) +0x0, including `sw` at 0x9128, `sw` at 0x91a8.
  2 such `lbu` accesses load 1 byte from a2 (arg2 at entry) +0xd, including `lbu` at 0x912c, `lbu` at 0x9218.
  3 such `lbu` accesses load 1 byte from a2 (arg2 at entry) +0x8, including `lbu` at 0x9140, `lbu` at 0x9204, `lbu` at 0x9260.
  The `lw` at 0x9148 loads 4 bytes from a1 (arg1 at entry) +0x4.
  The `lbu` at 0x9154 loads 1 byte from a1 (arg1 at entry) +0xe.
  The `lbu` at 0x91e0 loads 1 byte from a2 (arg2 at entry) +0xc.
  The `lbu` at 0x9228 loads 1 byte from a1 (arg1 at entry) +0x16.
  The `lbu` at 0x9230 loads 1 byte from ([a1+22]:1 + a2) +0x9.
  The `lbu` at 0x9280 loads 1 byte from a2 (arg2 at entry) +0xb.
  The `sd` at 0x92a8 stores 8 bytes to a0 (arg0 at entry) +0x10.
  The `sd` at 0x92b4 stores 8 bytes to a0 (arg0 at entry) +0x18.
  The `sb` at 0x92e8 stores 1 byte to a2 (arg2 at entry) +0xb.
  The `jalr` at 0x90e0 calls splhi with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x90fc calls splx with a0=ret(splhi), a1=?, a2=?, a3=?.
  The `jalr` at 0x9114 calls mutex_lock with a0=sym(mvpmutex), a1=0x0, a2=?, a3=?.
  The `jalr` at 0x9158 calls mvperrprintf with a0=0x5, a1=sym(.rodata)+4920, a2=[a1+14]:1, a3=[a1+4], a4=[a2+8]:1, a5=a3 at entry (arg3), a6=sym(mvperrprintf).
  The `jalr` at 0x9170 calls mutex_unlock with a0=sym(mvpmutex), a1=?, a2=?, a3=?, a7=sym(mutex_unlock).
  The `jalr` at 0x91a4 calls splhi with a0=?, a1=[sym(mvpmutex_locked)]-1, a2=sym(mvpmutex_locked), a3=sym(splhi).
  The `jalr` at 0x91c0 calls splx with a0=ret(splhi), a1=?, a2=?, a3=sym(splx), a4=[sym(.data)+2580]-1.
  The `jalr` at 0x9208 calls mvperrprintf with a0=0x5, a1=sym(.rodata)+5008, a2=[a2+8]:1, a3=[a2+12]:1, a4=a3 at entry (arg3), a5=sym(mvperrprintf), a6=sym(mvperrprintf).
  The `jalr` at 0x925c calls .text+36752 with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=[a2+8]:1, a3=?.
  The `jalr` at 0x92b0 calls .text+35164 with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0x1, a3=sym(_mvpi2c_wait_for_ack), a4=0x1.
  The `beq` branch at 0x9134 targets 0x91e0, is taken when (a0(=[a2+13]:1) & 0x4) == 0, and falls through when (a0(=[a2+13]:1) & 0x4) != 0.
  The `beq` branch at 0x91ec targets 0x9210, is taken when (s1(=a3) & a5(?)) == 0, and falls through when (s1(=a3) & a5(?)) != 0.
  The `beq` branch at 0x9210 targets 0x9280, is taken when s3(=a4) == 0, and falls through when s3(=a4) != 0.
  The `beq` branch at 0x9220 targets 0x923c, is taken when (a6(=[a2+13]:1) & 0x10) == 0, and falls through when (a6(=[a2+13]:1) & 0x10) != 0.
  The `beq` branch at 0x923c targets 0x9250 and is always taken.
  The `bltz` branch at 0x9244 targets 0x9164, is taken when t9(?) < 0 (signed), and falls through when t9(?) >= 0 (signed).
  The `beq` branch at 0x9264 targets 0x9294, is taken when v0(=ret(.text+36752)) == 0, and falls through when v0(=ret(.text+36752)) != 0.
  The `beq` branch at 0x9270 targets 0x9244, is taken when s3(=ret(.text+36752)) == v0(=0xb), and falls through when s3(=ret(.text+36752)) != v0(=0xb).
  The `beq` branch at 0x9278 targets 0x9168 and is always taken.
  The `bne` branch at 0x9284 targets 0x9218, is taken when v1(=[a2+11]:1) != s1(=a3), and falls through when v1(=[a2+11]:1) == s1(=a3).
  The `beq` branch at 0x928c targets 0x9168 and is always taken.
  The `beq` branch at 0x92c0 targets 0x92e4, is taken when v0(=ret(.text+35164)) == 0, and falls through when v0(=ret(.text+35164)) != 0.
  The `bne` branch at 0x92c8 targets 0x9168, is taken when v0(=ret(.text+35164)) != a5(=0xb), and falls through when v0(=ret(.text+35164)) == a5(=0xb).
  The `bgez` branch at 0x92d4 targets 0x9250, is taken when a1(?) >= 0 (signed), and falls through when a1(?) < 0 (signed).
  The `beq` branch at 0x92dc targets 0x9168 and is always taken.
  The `beq` branch at 0x92e4 targets 0x9164 and is always taken.
  The return at 0x91d8 has v0 = ?.

- `mvpi2c_init_regs` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x92ec (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x92ec-0x95b4 (712 bytes).
  It occupies 712 bytes.
  The `lbu` at 0x92ec loads 1 byte from a1 (arg1 at entry) +0x16.
  The `lw` at 0x92f8 loads 4 bytes from a0 (arg0 at entry) +0x10.
  The `lw` at 0x9304 loads 4 bytes from a1 (arg1 at entry) +0x1c.
  4 such `lbu` accesses load 1 byte from a1 (arg1 at entry) +0x10, including `lbu` at 0x9318, `lbu` at 0x93b8, `lbu` at 0x94b4.
  The `lw` at 0x9324 loads 4 bytes from sym(mvp_umba) +0x9dc.
  The `lbu` at 0x9330 loads 1 byte from a1 (arg1 at entry) +0xf.
  11 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x938c, `lbu` at 0x9398, `lbu` at 0x93c4.
  3 such `sd` accesses store 8 bytes to [a0+16] +0x10, including `sd` at 0x93b4, `sd` at 0x94d4, `sd` at 0x9560.
  The `sd` at 0x94f4 stores 8 bytes to [a0+16] +0x18.
  The `sb` at 0x950c stores 1 byte to ?.
  The `lh` at 0x9518 loads 2 bytes from a1 (arg1 at entry) +0x14.
  The `lw` at 0x9548 loads 4 bytes from ?.
  The `jalr` at 0x9418 calls .text+36752 with a0=[a0+16], a1=a1 at entry (arg1), a2=?, a3=?.
  The `jalr` at 0x94a0 calls mvperrprintf with a0=0x5, a1=sym(.rodata)+4648, a2=?, a3=?, a5=sym(mvperrprintf).
  The `jalr` at 0x94f0 calls .text+35164 with a0=[a0+16], a1=a1 at entry (arg1), a2=0x1, a3=[a1+16]:1, a5=0x1, a7=sym(_mvpi2c_wait_for_ack).
  The `jalr` at 0x954c calls mvperrprintf with a0=0x5, a1=sym(.rodata)+4648, a2=one of 0x0, 0x1, a3=?, a5=sym(mvpi2c_write_reg).
  The `jalr` at 0x9578 calls mvperrprintf with a0=0x4, a1=sym(.rodata)+4648, a2=?, a3=?, a4=sym(mvperrprintf).
  The `jalr` at 0x959c calls mvpi2c_write_reg with a0=[a0+16], a1=a1 at entry (arg1), a2=?, a3=?, a4=a2 at entry (arg2), a5=sym(mvpi2c_write_reg).
  The `beq` branch at 0x9344 targets 0x9518, is taken when at(=[sym(mvpi2c_autoincr_disable)]) == 0, and falls through when at(=[sym(mvpi2c_autoincr_disable)]) != 0.
  The `bne` branch at 0x9354 targets 0x9438, is taken when v1(?) != 0, and falls through when v1(?) == 0.
  The `beq` branch at 0x9360 targets 0x9384 and is always taken.
  The `bne` branch at 0x937c targets 0x9430, is taken when v0(=[a1+16]:1) < s1(?) (signed), and falls through when v0(=[a1+16]:1) >= s1(?) (signed).
  The `beq` branch at 0x9384 targets 0x93c4, is taken when s6(=a2) == 0, and falls through when s6(=a2) != 0.
  The `bne` branch at 0x9390 targets 0x9564, is taken when s1(?) != a3(?), and falls through when s1(?) == a3(?).
  The `beq` branch at 0x93a0 targets 0x93dc, is taken when (t8(?) & 0xd) == 0, and falls through when (t8(?) & 0xd) != 0.
  The `bne` branch at 0x93a8 targets 0x936c, is taken when s3(=one of 0x0, 0x1) != 0, and falls through when s3(=one of 0x0, 0x1) == 0.
  The `beq` branch at 0x93bc targets 0x9368 and is always taken.
  The `bne` branch at 0x93cc targets 0x9388, is taken when ra(?) != at(?), and falls through when ra(?) == at(?).
  The `beq` branch at 0x93d4 targets 0x9390 and is always taken.
  The `beq` branch at 0x93e0 targets 0x9588, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `bne` branch at 0x93e8 targets 0x9530, is taken when s3(=one of 0x0, 0x1) != s4(=one of 0x0, 0x1), and falls through when s3(=one of 0x0, 0x1) == s4(=one of 0x0, 0x1).
  The `beq` branch at 0x93f8 targets 0x9470, is taken when s4(=one of 0x0, 0x1) == 0, and falls through when s4(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x9400 targets 0x9470, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x9420 targets 0x946c, is taken when v0(=ret(.text+36752)) == 0, and falls through when v0(=ret(.text+36752)) != 0.
  The `beq` branch at 0x9428 targets 0x9440 and is always taken.
  The `beq` branch at 0x9430 targets 0x955c, is taken when s3(=one of 0x0, 0x1) == 0, and falls through when s3(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x9480 targets 0x94ac, is taken when (a4(?) & a0(?)) == 0, and falls through when (a4(?) & a0(?)) != 0.
  The `beq` branch at 0x94ac targets 0x9508, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0x94b8 targets 0x94d0, is taken when a3(=[a1+16]:1) == s1(?), and falls through when a3(=[a1+16]:1) != s1(?).
  The `beq` branch at 0x94c8 targets 0x94dc, is taken when (a4(?) & 0xd) == 0, and falls through when (a4(?) & 0xd) != 0.
  The `beq` branch at 0x94f8 targets 0x9508, is taken when v0(=ret(.text+35164)) == 0, and falls through when v0(=ret(.text+35164)) != 0.
  The `beq` branch at 0x9500 targets 0x9440 and is always taken.
  The `beq` branch at 0x9510 targets 0x936c and is always taken.
  The `beq` branch at 0x9520 targets 0x934c, is taken when (t1(=[a1+20]:2) & 0x1) == 0, and falls through when (t1(=[a1+20]:2) & 0x1) != 0.
  The `beq` branch at 0x9528 targets 0x9354 and is always taken.
  The `beq` branch at 0x9554 targets 0x93f4 and is always taken.
  The `beq` branch at 0x955c targets 0x9438 and is always taken.
  The `beq` branch at 0x9580 targets 0x943c and is always taken.
  The `beq` branch at 0x95a4 targets 0x9510, is taken when v0(=ret(mvpi2c_write_reg)) == 0, and falls through when v0(=ret(mvpi2c_write_reg)) != 0.
  The `beq` branch at 0x95ac targets 0x9440 and is always taken.
  The return at 0x9464 has v0 = one of ret(.text+36752), 0x0, 0x5, ret(.text+35164), ret(mvpi2c_write_reg).

- `mvpdummy_spl` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x95b4 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x95b4-0x95bc (8 bytes).
  It occupies 8 bytes.
  The return at 0x95b4 has v0 = 0x0.

- `mvpdummy_splx` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x95bc (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x95bc-0x95c4 (8 bytes).
  It occupies 8 bytes.
  The return at 0x95bc has v0 = ?.

- `mvpinterrupt_clear` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x95c4 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x95c4-0x9600 (60 bytes).
  It occupies 60 bytes.
  The `lw` at 0x95cc loads 4 bytes from sym(mvpcontroller_table) +0x0.
  The `lw` at 0x95e0 loads 4 bytes from ([sym(mvpcontroller_table)] + (a0 << 0x2)) +0xc0.
  The `ld` at 0x95e4 loads 8 bytes from ?.
  The `ld` at 0x95ec loads 8 bytes from [([sym(mvpcontroller_table)] + (a0 << 0x2))+192] +0x8.
  The `sd` at 0x95f4 stores 8 bytes to ?.
  The `sd` at 0x95fc stores 8 bytes to [([sym(mvpcontroller_table)] + (a0 << 0x2))+192] +0x0.
  The return at 0x95f8 has v0 = [([sym(mvpcontroller_table)] + (a0 << 0x2))+192].

- `mvpinterrupt` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x9600 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x9600-0x982c (556 bytes).
  It occupies 556 bytes.
  The `lw` at 0x9640 loads 4 bytes from sym(mvpcontroller_table) +0x0.
  2 such `lw` accesses load 4 bytes from sym(mvptransfer_stats) +0x110, including `lw` at 0x9658, `lw` at 0x97e4.
  2 such `lw` accesses load 4 bytes from sym(mvp_umba) +0xa1c, including `lw` at 0x9668, `lw` at 0x97b8.
  2 such `sw` accesses store 4 bytes to sym(mvptransfer_stats) +0x110, including `sw` at 0x9674, `sw` at 0x97f4.
  2 such `sw` accesses store 4 bytes to sym(mvp_umba) +0xa1c, including `sw` at 0x9680, `sw` at 0x97d0.
  2 such `lw` accesses load 4 bytes from sym(mvp_umba) +0xa20, including `lw` at 0x969c, `lw` at 0x9828.
  The `ld` at 0x96a0 loads 8 bytes from [sym(.data)+2592] +0x10.
  The `lw` at 0x96cc loads 4 bytes from [sym(mvpcontroller_table)] +0xa0.
  The `lw` at 0x96d8 loads 4 bytes from [sym(mvpcontroller_table)] +0xb0.
  The `lw` at 0x96f8 loads 4 bytes from [sym(mvpcontroller_table)] +0xa8.
  The `lw` at 0x9704 loads 4 bytes from [sym(mvpcontroller_table)] +0xb8.
  The `lw` at 0x9724 loads 4 bytes from [sym(mvpcontroller_table)] +0xa4.
  The `lw` at 0x9730 loads 4 bytes from [sym(mvpcontroller_table)] +0xb4.
  The `lw` at 0x9764 loads 4 bytes from sym(mvptransfer_stats) +0x100.
  The `lw` at 0x978c loads 4 bytes from table(sym(mvptransfer_stats)) +0x24.
  The `sw` at 0x9798 stores 4 bytes to table(sym(mvptransfer_stats)) +0x24.
  The `sw` at 0x97a0 stores 4 bytes to sym(mvptransfer_stats) +0x100.
  The `lw` at 0x97c0 loads 4 bytes from sym(mvptransfer_stats) +0x104.
  The `sw` at 0x97dc stores 4 bytes to sym(mvptransfer_stats) +0x104.
  The `jalr` at 0x9644 calls mutex_lock with a0=sym(mvpinterrupt_spurious), a1=0x0, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x9684 calls (unknown callee) with a0=[[sym(mvpcontroller_table)]+160], a1=0x0, a2=?, a3=[[sym(mvpcontroller_table)]+176].
  The `jalr` at 0x96e8 calls .text+38340 with a0=0x0, a1=?, a2=?, a3=?.
  The `jalr` at 0x9710 calls (unknown callee) with a0=[[sym(mvpcontroller_table)]+168], a1=0x2, a2=?, a3=[[sym(mvpcontroller_table)]+184].
  The `jalr` at 0x973c calls (unknown callee) with a0=[[sym(mvpcontroller_table)]+164], a1=0x1, a2=?, a3=[[sym(mvpcontroller_table)]+180].
  The `jalr` at 0x97d8 calls mutex_unlock with a0=sym(mvpinterrupt_spurious), a1=?, a2=sym(mutex_unlock), a3=[sym(mvpinterrupt_active)]-1.
  The `jalr` at 0x9808 calls .text+38340 with a0=0x2, a1=?, a2=?, a3=?.
  The `jalr` at 0x981c calls .text+38340 with a0=0x1, a1=?, a2=?, a3=?.
  The `beq` branch at 0x967c targets 0x969c and is always taken.
  The `bltz` branch at 0x9698 targets 0x9724, is taken when t8(=([[sym(.data)+2592]+16]:8 << 0x3e)) < 0 (signed), and falls through when t8(=([[sym(.data)+2592]+16]:8 << 0x3e)) >= 0 (signed).
  The `beq` branch at 0x96b4 targets 0x9750, is taken when (t9(?) & 0x7) == 0, and falls through when (t9(?) & 0x7) != 0.
  The `bltz` branch at 0x96bc targets 0x96f8, is taken when a0(=([[sym(.data)+2592]+16]:8 << 0x3d)) < 0 (signed), and falls through when a0(=([[sym(.data)+2592]+16]:8 << 0x3d)) >= 0 (signed).
  The `beq` branch at 0x96c4 targets 0x9698, is taken when t8(?) == 0, and falls through when t8(?) != 0.
  The `beq` branch at 0x96d0 targets 0x96e4, is taken when a0(=[[sym(mvpcontroller_table)]+160]) == 0, and falls through when a0(=[[sym(mvpcontroller_table)]+160]) != 0.
  The `bne` branch at 0x96dc targets 0x9684, is taken when a3(=[[sym(mvpcontroller_table)]+176]) != 0, and falls through when a3(=[[sym(mvpcontroller_table)]+176]) == 0.
  The `beq` branch at 0x96f0 targets 0x9698 and is always taken.
  The `beq` branch at 0x96fc targets 0x9804, is taken when a0(=[[sym(mvpcontroller_table)]+168]) == 0, and falls through when a0(=[[sym(mvpcontroller_table)]+168]) != 0.
  The `beq` branch at 0x9708 targets 0x9804, is taken when a3(=[[sym(mvpcontroller_table)]+184]) == 0, and falls through when a3(=[[sym(mvpcontroller_table)]+184]) != 0.
  The `beq` branch at 0x971c targets 0x96c0 and is always taken.
  The `beq` branch at 0x9728 targets 0x9818, is taken when a0(=[[sym(mvpcontroller_table)]+164]) == 0, and falls through when a0(=[[sym(mvpcontroller_table)]+164]) != 0.
  The `beq` branch at 0x9734 targets 0x9818, is taken when a3(=[[sym(mvpcontroller_table)]+180]) == 0, and falls through when a3(=[[sym(mvpcontroller_table)]+180]) != 0.
  The `beq` branch at 0x9748 targets 0x969c and is always taken.
  The `bne` branch at 0x9760 targets 0x97a4, is taken when (s3(?) & t9(?)) != 0, and falls through when (s3(?) & t9(?)) == 0.
  The `bltz` branch at 0x9768 targets 0x97a0, is taken when s7(=a1) < 0 (signed), and falls through when s7(=a1) >= 0 (signed).
  The `beq` branch at 0x9770 targets 0x979c, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x9794 targets 0x97a4 and is always taken.
  The `beq` branch at 0x9810 targets 0x96c4 and is always taken.
  The `beq` branch at 0x9824 targets 0x96a0 and is always taken.
  The return at 0x97fc has v0 = ret(mutex_unlock).

- `mvpinterrupt_setup` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x982c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x982c-0x9924 (248 bytes).
  It occupies 248 bytes.
  The `lw` at 0x9868 loads 4 bytes from sym(mvpcontroller_table) +0x0.
  The `sw` at 0x9878 stores 4 bytes to ([sym(mvpcontroller_table)] + (a1 << 0x2)) +0xb0.
  2 such `sw` accesses store 4 bytes to ([sym(mvpcontroller_table)] + (a1 << 0x2)) +0xa0, including `sw` at 0x987c, `sw` at 0x98ec.
  The `lw` at 0x98dc loads 4 bytes from ([sym(mvpcontroller_table)] + (a1 << 0x2)) +0xa0.
  The `jalr` at 0x9864 calls splhi with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x9888 calls splx with a0=ret(splhi), a1=?, a2=?, a3=?, a6=([sym(mvpcontroller_table)] + (a1 << 0x2)), a7=sym(splx).
  The `jalr` at 0x98b0 calls crime_retrace_callback with a0=0x0, a1=a3 at entry (arg3), a2=a0 at entry (arg0), a3=?.
  The `jalr` at 0x98f4 calls splx with a0=ret(splhi), a1=?, a2=?, a3=?, a6=([sym(mvpcontroller_table)] + (a1 << 0x2)).
  The `jalr` at 0x9914 calls crime_retrace_callback with a0=0x0, a1=0x0, a2=0x0, a3=?.
  The `beq` branch at 0x9870 targets 0x98dc, is taken when s2(=a2) == 0, and falls through when s2(=a2) != 0.
  The `bne` branch at 0x9894 targets 0x98bc, is taken when s0(=a1) != t0(=0x3), and falls through when s0(=a1) == t0(=0x3).
  The `beq` branch at 0x989c targets 0x9904, is taken when s2(=a2) == 0, and falls through when s2(=a2) != 0.
  The `bne` branch at 0x98e0 targets 0x98f0, is taken when t2(=[([sym(mvpcontroller_table)] + (a1 << 0x2))+160]) != s1(=a0), and falls through when t2(=[([sym(mvpcontroller_table)] + (a1 << 0x2))+160]) == s1(=a0).
  The `beq` branch at 0x98e8 targets 0x9880 and is always taken.
  The `beq` branch at 0x98fc targets 0x98bc and is always taken.
  The `beq` branch at 0x991c targets 0x98bc and is always taken.
  The return at 0x98d4 has v0 = 0x0.

- `mvpinterrupt_init` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x9924 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x9924-0x9a14 (240 bytes).
  It occupies 240 bytes.
  The `sw` at 0x9978 stores 4 bytes to sym(mvptransfer_stats) +0x110.
  The `lw` at 0x99cc loads 4 bytes from sym(mvp_umba) +0xa20.
  The `ld` at 0x99d4 loads 8 bytes from [sym(.data)+2592] +0x18.
  The `jalr` at 0x9958 calls init_mutex with a0=sym(mvpinterrupt_spurious), a1=0x0, a2=sym(.rodata)+5232, a3=-0x1, a4=sym(init_mutex).
  The `jalr` at 0x9990 calls mvpinterrupt_setup with a0=0x0, a1=?, a2=0x0, a3=0x0, a4=sym(mvpinterrupt_setup).
  The `jalr` at 0x99b4 calls setcrimevector with a0=?, a1=0x1, a2=sym(mvpinterrupt), a3=?, a4=0x0, a5=sym(setcrimevector).
  The `beq` branch at 0x9974 targets 0x99d8 and is always taken.
  The `beq` branch at 0x99d0 targets 0x99fc, is taken when s0(?) >= 0x5 (signed), and falls through when s0(?) < 0x5 (signed).
  The `beq` branch at 0x99d8 targets 0x9980, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0x99e0 targets 0x9980, is taken when s0(?) == s1(=0x1), and falls through when s0(?) != s1(=0x1).
  The `beq` branch at 0x99e8 targets 0x9980, is taken when s0(?) == s2(=0x2), and falls through when s0(?) != s2(=0x2).
  The `bne` branch at 0x99f8 targets 0x99d8, is taken when s0(?) < 0x5 (signed), and falls through when s0(?) >= 0x5 (signed).
  The return at 0x9a0c has v0 = ?.
  The instructions from 0x997c to 0x997c are not reached by any path from the entry, and their branches are not listed.

- `mvpinterrupt_unload` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x9a14 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x9a14-0x9acc (184 bytes).
  It occupies 184 bytes.
  The `lw` at 0x9a60 loads 4 bytes from sym(mvp_umba) +0xa20.
  The `ld` at 0x9a68 loads 8 bytes from [sym(.data)+2592] +0x18.
  The `sw` at 0x9ac8 stores 4 bytes to sym(mvptransfer_stats) +0x110.
  The `jalr` at 0x9a48 calls unsetcrimevector with a0=?, a1=sym(mvpinterrupt), a2=sym(unsetcrimevector), a3=?.
  The `jalr` at 0x9aa0 calls mutex_destroy with a0=sym(mvpinterrupt_spurious), a1=sym(mutex_destroy), a2=?, a3=?.
  The `beq` branch at 0x9a30 targets 0x9a6c and is always taken.
  The `beq` branch at 0x9a64 targets 0x9a90, is taken when s0(?) >= 0x5 (signed), and falls through when s0(?) < 0x5 (signed).
  The `beq` branch at 0x9a6c targets 0x9a3c, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0x9a74 targets 0x9a3c, is taken when s0(?) == s1(=0x1), and falls through when s0(?) != s1(=0x1).
  The `beq` branch at 0x9a7c targets 0x9a3c, is taken when s0(?) == s2(=0x2), and falls through when s0(?) != s2(=0x2).
  The `bne` branch at 0x9a8c targets 0x9a6c, is taken when s0(?) < 0x5 (signed), and falls through when s0(?) >= 0x5 (signed).
  The return at 0x9ac4 has v0 = ret(mutex_destroy).
  The instructions from 0x9a38 to 0x9a38 are not reached by any path from the entry, and their branches are not listed.

- `mvpinit` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x9acc (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x9acc-0x9b0c (64 bytes).
  It occupies 64 bytes.
  The `jalr` at 0x9adc calls .text+40708 with a0=0xffffffffbf100000, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x9af4 calls mvperrprintf with a0=0x8, a1=sym(.rodata)+5248, a2=sym(mvperrprintf), a3=?.
  The return at 0x9b04 has v0 = 0x0.

- `mvpopen` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x9b0c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x9b0c-0x9b88 (124 bytes).
  It occupies 124 bytes.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x0, including `lw` at 0x9b0c, `lw` at 0x9b58.
  The `sw` at 0x9b84 stores 4 bytes to a0 (arg0 at entry) +0x0.
  The `jalr` at 0x9b44 calls .text+41536 with a0=0x0, a1=sp-32, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0x9b28 targets 0x9b38, is taken when (at(=0x3ffff) & v0(=[a0])) == 0, and falls through when (at(=0x3ffff) & v0(=[a0])) != 0.
  The `bne` branch at 0x9b4c targets 0x9b30, is taken when v0(=ret(.text+41536)) != 0, and falls through when v0(=ret(.text+41536)) == 0.
  The `beq` branch at 0x9b80 targets 0x9b30 and is always taken.
  The return at 0x9b30 has v0 = one of 0x13, ret(.text+41536), 0x0.

- `mvpclose` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x9b88 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x9b88-0x9c60 (216 bytes).
  It occupies 216 bytes.
  2 such `lw` accesses load 4 bytes from sym(mvpmutex_locked) +0x0, including `lw` at 0x9bbc, `lw` at 0x9c48.
  2 such `sw` accesses store 4 bytes to sym(mvpmutex_locked) +0x0, including `sw` at 0x9bc8, `sw` at 0x9c5c.
  The `lw` at 0x9bfc loads 4 bytes from table(sym(mvppath_table)) +0x0.
  The `jalr` at 0x9ba8 calls mutex_lock with a0=sym(mvpmutex), a1=0x0, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x9bc4 calls splhi with a0=?, a1=[sym(mvpmutex_locked)]+1, a2=sym(mvpmutex_locked), a3=sym(splhi).
  The `jalr` at 0x9bf8 calls mvppath_close with a0=entry(sym(mvppath_table)), a1=sym(mvppath_close), a2=?, a3=?.
  The `jalr` at 0x9c0c calls .text+41784 with a0=?, a1=?, a2=sym(mvpreleasepath), a3=?.
  The `jalr` at 0x9c1c calls splx with a0=ret(splhi), a1=?, a2=?, a3=sym(splx).
  The `jalr` at 0x9c34 calls mutex_unlock with a0=sym(mvpmutex), a1=?, a2=?, a3=?, a4=sym(mutex_unlock).
  The return at 0x9c58 has v0 = 0x0.

- `mvpioctl` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x9c60 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x9c60-0x9e58 (504 bytes).
  It occupies 504 bytes.
  The `lw` at 0x9ca0 loads 4 bytes from sym(mvptransfer_stats) +0x220.
  5 such `lw` accesses load 4 bytes from table(sym(mvplock)) +0x8, including `lw` at 0x9d58, `lw` at 0x9db8, `lw` at 0x9de8.
  The `jalr` at 0x9d54 calls mvpsystem_ioctl with a0=[table(sym(mvplock))+8], a1=a4 at entry (arg4), a2=a2 at entry (arg2), a3=a5 at entry (arg5), a5=sym(mvpsystem_ioctl).
  The `jalr` at 0x9d80 calls .text+41856 with a0=0x0, a1=?, a2=a4 at entry (arg4), a3=a2 at entry (arg2), a5=sym(mvpiostatus).
  The `jalr` at 0x9db4 calls mvppath_ioctl with a0=[table(sym(mvplock))+8], a1=a4 at entry (arg4), a2=a2 at entry (arg2), a3=a5 at entry (arg5), a5=sym(mvppath_ioctl).
  The `jalr` at 0x9de4 calls mvpbuffer_ioctl with a0=[table(sym(mvplock))+8], a1=a4 at entry (arg4), a2=a2 at entry (arg2), a3=a5 at entry (arg5), a5=sym(mvpbuffer_ioctl).
  The `jalr` at 0x9e14 calls mvptransfer_ioctl with a0=[table(sym(mvplock))+8], a1=a4 at entry (arg4), a2=a2 at entry (arg2), a3=a5 at entry (arg5), a5=sym(mvptransfer_ioctl).
  The `jalr` at 0x9e48 calls mvpcontrol_ioctl with a0=[table(sym(mvplock))+8], a1=a4 at entry (arg4), a2=a2 at entry (arg2), a3=a5 at entry (arg5), a5=sym(mvpcontrol_ioctl).
  The `beq` branch at 0x9cc0 targets 0x9d28, is taken when at(=[sym(mvpcontroller_table)]) == 0, and falls through when at(=[sym(mvpcontroller_table)]) != 0.
  The `bne` branch at 0x9ccc targets 0x9d20, is taken when t8(?) != a3(=0x6d767000), and falls through when t8(?) == a3(=0x6d767000).
  The `beq` branch at 0x9cd8 targets 0x9d64, is taken when v0(?) == t9(=0x1), and falls through when v0(?) != t9(=0x1).
  The `beq` branch at 0x9ce4 targets 0x9d90, is taken when v0(?) == v1(=0x2), and falls through when v0(?) != v1(=0x2).
  The `beq` branch at 0x9cec targets 0x9dc4, is taken when v0(?) == a0(=0x3), and falls through when v0(?) != a0(=0x3).
  The `beq` branch at 0x9cf4 targets 0x9df4, is taken when v0(?) == a1(=0x4), and falls through when v0(?) != a1(=0x4).
  The `beq` branch at 0x9d00 targets 0x9e24, is taken when v0(?) == a2(=0x5), and falls through when v0(?) != a2(=0x5).
  The `beq` branch at 0x9d08 targets 0x9d30, is taken when v0(?) == a3(=0x6), and falls through when v0(?) != a3(=0x6).
  The `beq` branch at 0x9d20 targets 0x9d14 and is always taken.
  The `beq` branch at 0x9d28 targets 0x9d14 and is always taken.
  The `beq` branch at 0x9d5c targets 0x9d10 and is always taken.
  The `beq` branch at 0x9d88 targets 0x9d10 and is always taken.
  The `beq` branch at 0x9dbc targets 0x9d10 and is always taken.
  The `beq` branch at 0x9dec targets 0x9d10 and is always taken.
  The `beq` branch at 0x9e1c targets 0x9d10 and is always taken.
  The `beq` branch at 0x9e50 targets 0x9d10 and is always taken.
  The return at 0x9d18 has v0 = one of ?, 0x16, 0x13.

- `mvpaddtoinvent` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x9e58 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x9e58-0x9f04 (172 bytes).
  It occupies 172 bytes.
  The `jalr` at 0x9e94 calls find_inventory with a0=0x0, a1=0xc, a2=0x6, a3=a0 at entry (arg0), a4=a1 at entry (arg1), a5=-0x1.
  The `jalr` at 0x9ec0 calls replace_in_inventory with a0=ret(find_inventory), a1=0xc, a2=0x6, a3=a0 at entry (arg0), a4=a1 at entry (arg1), a5=a2 at entry (arg2).
  The `jalr` at 0x9ee4 calls add_to_inventory with a0=0xc, a1=0x6, a2=a0 at entry (arg0), a3=a1 at entry (arg1), a4=a2 at entry (arg2).
  The `beq` branch at 0x9e9c targets 0x9ed0, is taken when v0(=ret(find_inventory)) == 0, and falls through when v0(=ret(find_inventory)) != 0.
  The `beq` branch at 0x9ec8 targets 0x9eec and is always taken.
  The return at 0x9efc has v0 = one of ret(replace_in_inventory), ret(add_to_inventory).

- `mvpdriverinit` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x9f04 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x9f04-0xa1ec (744 bytes).
  It occupies 744 bytes.
  The `lw` at 0x9f60 loads 4 bytes from sym(mvp_umba) +0xa34.
  The `lw` at 0x9f74 loads 4 bytes from sym(mvptransfer_stats) +0x220.
  The `lw` at 0x9f7c loads 4 bytes from [sym(mvpcontroller_table)] +0x0.
  3 such `lw` accesses load 4 bytes from sym(showconfig) +0x0, including `lw` at 0x9fa0, `lw` at 0x9fdc, `lw` at 0xa088.
  The `sw` at 0xa008 stores 4 bytes to sym(mvp_umba) +0xa34.
  2 such `lw` accesses load 4 bytes from sym(mvp_umba) +0xa2c, including `lw` at 0xa038, `lw` at 0xa160.
  The `sw` at 0xa0e0 stores 4 bytes to sym(mvptransfer_stats) +0x220.
  The `sb` at 0xa0e4 stores 1 byte to ret(kmem_alloc) +0x67.
  The `sh` at 0xa0ec stores 2 bytes to ret(kmem_alloc) +0x4.
  The `lbu` at 0xa104 loads 1 byte from ret(kmem_alloc) +0x5b.
  The `lbu` at 0xa110 loads 1 byte from ret(kmem_alloc) +0x5a.
  The `lbu` at 0xa120 loads 1 byte from ret(kmem_alloc) +0x5d.
  The `lbu` at 0xa12c loads 1 byte from ret(kmem_alloc) +0x5c.
  The `lbu` at 0xa13c loads 1 byte from ret(kmem_alloc) +0x5f.
  The `lbu` at 0xa148 loads 1 byte from ret(kmem_alloc) +0x5e.
  The `sw` at 0xa190 stores 4 bytes to ret(kmem_alloc) +0x10.
  The `lw` at 0xa198 loads 4 bytes from sym(mvpinitialized) +0x0.
  The `sw` at 0xa1ac stores 4 bytes to sym(mvpinitialized) +0x0.
  The `jalr` at 0x9f18 calls mvpdebug_init with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x9f44 calls mvpprobe with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jalr` at 0x9fcc calls mvperrprintf with a0=0x4, a1=sym(.rodata)+5304, a2=[sym(mvpnumcontrollers)], a3=0x1, a4=sym(mvperrprintf), a6=sym(showconfig).
  The `jalr` at 0x9ff8 calls mvperrprintf with a0=0x2, a1=sym(.rodata)+5272, a2=?, a3=sym(mvperrprintf), a5=[sym(showconfig)].
  The `jalr` at 0xa03c calls mvperrprintf with a0=0x2, a1=sym(.rodata)+5248, a2=[sym(mvpnumcontrollers)], a3=ret(mvpprobe), a4=[sym(mvprevision)], a5=sym(mvperrprintf), a6=sym(showconfig).
  The `jalr` at 0xa058 calls mvperrprintf with a0=0x2, a1=sym(.rodata)+5248, a2=?, a3=?, a6=sym(mvperrprintf).
  The `jalr` at 0xa070 calls kmem_alloc with a0=0x498, a1=0x0, a2=sym(kmem_alloc), a3=?.
  The `jalr` at 0xa0ac calls mvperrprintf with a0=0x4, a1=sym(.rodata)+5248, a2=[sym(mvpnumcontrollers)], a3=[sym(showconfig)], a4=sym(mvperrprintf).
  The `jalr` at 0xa0c8 calls bzero with a0=ret(kmem_alloc), a1=0x498, a2=sym(bzero), a3=?.
  The `jalr` at 0xa0fc calls mvpcontrol_init with a0=[sym(mvpnumcontrollers)], a1=a0 at entry (arg0), a2=?, a3=?, a6=sym(mvpcontrol_init).
  The `jalr` at 0xa18c calls mvpaddtoinvent with a0=[sym(mvpnumcontrollers)], a1=0x0, a2=?, a3=?.
  The `jalr` at 0xa1dc calls bzero with a0=sym(mvplock), a1=0x100, a2=sym(bzero), a3=0x1, a4=ret(mvpprobe), a5=sym(mvplock).
  The `beq` branch at 0x9f20 targets 0x9f3c, is taken when v0(=ret(mvpdebug_init)) == 0, and falls through when v0(=ret(mvpdebug_init)) != 0.
  The `beq` branch at 0x9f50 targets 0x9f28, is taken when v0(=ret(mvpprobe)) == v1(=-0x1), and falls through when v0(=ret(mvpprobe)) != v1(=-0x1).
  The `blez` branch at 0x9f64 targets 0x9f98, is taken when s0(=[sym(mvpnumcontrollers)]) <= 0 (signed), and falls through when s0(=[sym(mvpnumcontrollers)]) > 0 (signed).
  The `beq` branch at 0x9f80 targets 0x9fdc, is taken when a0(=[[sym(mvpcontroller_table)]]) == s1(=a0), and falls through when a0(=[[sym(mvpcontroller_table)]]) != s1(=a0).
  The `bne` branch at 0x9f90 targets 0x9f80, is taken when a2(?) < s0(=[sym(mvpnumcontrollers)]) (signed), and falls through when a2(?) >= s0(=[sym(mvpnumcontrollers)]) (signed).
  The `bne` branch at 0x9fa4 targets 0xa008, is taken when s0(=[sym(mvpnumcontrollers)]) < 0x2 (signed), and falls through when s0(=[sym(mvpnumcontrollers)]) >= 0x2 (signed).
  The `beq` branch at 0x9fac targets 0x9f2c, is taken when a0(=[sym(showconfig)]) == 0, and falls through when a0(=[sym(showconfig)]) != 0.
  The `beq` branch at 0x9fd4 targets 0x9f2c and is always taken.
  The `beq` branch at 0x9fe0 targets 0x9f2c, is taken when a5(=[sym(showconfig)]) == 0, and falls through when a5(=[sym(showconfig)]) != 0.
  The `beq` branch at 0xa000 targets 0x9f2c and is always taken.
  The `beq` branch at 0xa00c targets 0xa060, is taken when a0(=[sym(showconfig)]) == 0, and falls through when a0(=[sym(showconfig)]) != 0.
  The `bne` branch at 0xa078 targets 0xa0bc, is taken when v0(=ret(kmem_alloc)) != 0, and falls through when v0(=ret(kmem_alloc)) == 0.
  The `beq` branch at 0xa08c targets 0x9f28, is taken when a3(=[sym(showconfig)]) == 0, and falls through when a3(=[sym(showconfig)]) != 0.
  The `beq` branch at 0xa0b4 targets 0x9f2c and is always taken.
  The `beq` branch at 0xa0e8 targets 0xa1c8, is taken when s0(=[sym(mvpnumcontrollers)]) == a3(=0x1), and falls through when s0(=[sym(mvpnumcontrollers)]) != a3(=0x1).
  The `beq` branch at 0xa108 targets 0xa1b0, is taken when a0(=[ret(kmem_alloc)+91]:1) == 0, and falls through when a0(=[ret(kmem_alloc)+91]:1) != 0.
  The `beq` branch at 0xa124 targets 0xa1b8, is taken when a0(=[ret(kmem_alloc)+93]:1) == 0, and falls through when a0(=[ret(kmem_alloc)+93]:1) != 0.
  The `beq` branch at 0xa140 targets 0xa1c0, is taken when a0(=[ret(kmem_alloc)+95]:1) == 0, and falls through when a0(=[ret(kmem_alloc)+95]:1) != 0.
  The `bne` branch at 0xa1a0 targets 0x9f28, is taken when v0(=[sym(mvpinitialized)]) != 0, and falls through when v0(=[sym(mvpinitialized)]) == 0.
  The `beq` branch at 0xa1a8 targets 0x9f28 and is always taken.
  The `beq` branch at 0xa1b0 targets 0xa120 and is always taken.
  The `beq` branch at 0xa1b8 targets 0xa13c and is always taken.
  The `beq` branch at 0xa1c0 targets 0xa158 and is always taken.
  The `beq` branch at 0xa1e4 targets 0xa0f4 and is always taken.
  The return at 0x9f34 has v0 = one of ?, sym(mvpdevflag), ret(mvperrprintf).

- `mvpcopyin` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0xa1ec (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0xa1ec-0xa240 (84 bytes).
  It occupies 84 bytes.
  The `lh` at 0xa224 loads 2 bytes from a1 (arg1 at entry) +0x2.
  The `jalr` at 0xa200 calls copyin with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0xa208 targets 0xa21c, is taken when v0(=ret(copyin)) == 0, and falls through when v0(=ret(copyin)) != 0.
  The `beq` branch at 0xa228 targets 0xa238, is taken when v0(=[a1+2]:2) == v1(=a2), and falls through when v0(=[a1+2]:2) != v1(=a2).
  The `beq` branch at 0xa230 targets 0xa214 and is always taken.
  The `beq` branch at 0xa238 targets 0xa214 and is always taken.
  The return at 0xa214 has v0 = one of 0x0, 0x7, 0xe.

- `mvpgetpath` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0xa240 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0xa240-0xa338 (248 bytes).
  It occupies 248 bytes.
  The `lw` at 0xa27c loads 4 bytes from sym(mvptransfer_stats) +0x118.
  The `sw` at 0xa304 stores 4 bytes to sym(mvptransfer_stats) +0x118.
  The `sb` at 0xa310 stores 1 byte to ret(kmem_contig_alloc) +0x466.
  The `lw` at 0xa320 loads 4 bytes from sym(mvptransfer_stats) +0x220.
  The `sh` at 0xa324 stores 2 bytes to ret(kmem_contig_alloc) +0x468.
  The `sw` at 0xa328 stores 4 bytes to ret(kmem_contig_alloc) +0x460.
  The `sw` at 0xa334 stores 4 bytes to a1 (arg1 at entry) +0x0.
  The `jalr` at 0xa25c calls splhi with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0xa2a0 calls splx with a0=ret(splhi), a1=?, a2=?, a3=sym(splx).
  The `jalr` at 0xa2d4 calls kmem_contig_alloc with a0=0x2fa0, a1=0x1000, a2=0x101, a3=?, a4=sym(kmem_contig_alloc).
  The `jalr` at 0xa2f0 calls bzero with a0=ret(kmem_contig_alloc), a1=0x2fa0, a2=?, a3=?, a5=sym(bzero).
  The `jalr` at 0xa30c calls splx with a0=ret(splhi), a1=?, a2=?, a3=?, a6=0x1, a7=sym(splx).
  The `beq` branch at 0xa280 targets 0xa2c8, is taken when a1(=[sym(mvplock)]) == 0, and falls through when a1(=[sym(mvplock)]) != 0.
  The `bne` branch at 0xa290 targets 0xa27c, is taken when s1(?) < 0x40 (signed), and falls through when s1(?) >= 0x40 (signed).
  The `beq` branch at 0xa2dc targets 0xa298, is taken when v0(=ret(kmem_contig_alloc)) == 0, and falls through when v0(=ret(kmem_contig_alloc)) != 0.
  The `beq` branch at 0xa330 targets 0xa2ac and is always taken.
  The return at 0xa2c0 has v0 = one of 0x0, 0x1c.

- `mvpreleasepath` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0xa338 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0xa338-0xa380 (72 bytes).
  It occupies 72 bytes.
  The `lw` at 0xa364 loads 4 bytes from (sym(mvppath_table) + (a0 << 0x2)) +0x0.
  The `sw` at 0xa370 stores 4 bytes to (sym(mvppath_table) + (a0 << 0x2)) +0x0.
  The `jalr` at 0xa360 calls kmem_contig_free with a0=[(sym(mvppath_table) + (a0 << 0x2))], a1=0x2fa0, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xa378 has v0 = 0x0.

- `mvpiostatus` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0xa380 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0xa380-0xa450 (208 bytes).
  It occupies 208 bytes.
  The `lw` at 0xa3ac loads 4 bytes from sym(mvptransfer_stats) +0x220.
  The `lw` at 0xa3e8 loads 4 bytes from (sym(mvplock) + (a1 << 0x2)) +0x8.
  The `sh` at 0xa3f0 stores 2 bytes to [(sym(mvplock) + (a1 << 0x2))+8] +0x46a.
  The `lw` at 0xa400 loads 4 bytes from ?.
  The `lh` at 0xa40c loads 2 bytes from ?.
  The `lbu` at 0xa418 loads 1 byte from [(sym(mvplock) + (a1 << 0x2))+8] +0x466.
  The `lbu` at 0xa428 loads 1 byte from [(sym(mvplock) + (a1 << 0x2))+8] +0x467.
  The `jalr` at 0xa3b4 calls mvpcopyin with a0=a3 at entry (arg3), a1=sp-80, a2=0x20, a3=a3 at entry (arg3).
  The `jalr` at 0xa430 calls copyout with a0=sp-80, a1=a3 at entry (arg3), a2=0x20, a3=0x4.
  The `beq` branch at 0xa3bc targets 0xa3d0, is taken when v0(=ret(mvpcopyin)) == 0, and falls through when v0(=ret(mvpcopyin)) != 0.
  The `beq` branch at 0xa438 targets 0xa448, is taken when v0(=ret(copyout)) == 0, and falls through when v0(=ret(copyout)) != 0.
  The `beq` branch at 0xa440 targets 0xa3c4 and is always taken.
  The `beq` branch at 0xa448 targets 0xa3c4 and is always taken.
  The return at 0xa3c8 has v0 = one of ret(mvpcopyin), 0xe, 0x0.

- `mvpunload` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0xa450 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0xa450-0xa584 (308 bytes).
  It occupies 308 bytes.
  The `lw` at 0xa4ac loads 4 bytes from sym(mvptransfer_stats) +0x118.
  The `lbu` at 0xa4b8 loads 1 byte from [sym(mvplock)] +0x466.
  2 such `lw` accesses load 4 bytes from sym(mvptransfer_stats) +0x220, including `lw` at 0xa520, `lw` at 0xa53c.
  The `sw` at 0xa548 stores 4 bytes to sym(mvptransfer_stats) +0x220.
  The `jalr` at 0xa470 calls splhi with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0xa498 calls .text+41784 with a0=?, a1=?, a2=?, a3=[sym(mvplock)].
  The `jalr` at 0xa4c8 calls splx with a0=ret(splhi), a1=?, a2=?, a3=[sym(mvplock)].
  The `jalr` at 0xa508 calls splx with a0=ret(splhi), a1=?, a2=?, a3=?.
  The `jalr` at 0xa52c calls mvpcontrol_unload with a0=?, a1=?, a2=?, a3=?.
  The `jalr` at 0xa538 calls kmem_free with a0=[sym(mvpcontroller_table)], a1=0x498, a2=?, a3=?.
  The `jalr` at 0xa574 calls mvperrprintf with a0=0x8, a1=sym(.rodata)+5480, a2=sym(mvperrprintf), a3=?.
  The `beq` branch at 0xa490 targets 0xa4ac and is always taken.
  The `bltz` branch at 0xa4a4 targets 0xa500, is taken when s1(?) < 0 (signed), and falls through when s1(?) >= 0 (signed).
  The `beq` branch at 0xa4b0 targets 0xa4f4, is taken when a3(=[sym(mvplock)]) == 0, and falls through when a3(=[sym(mvplock)]) != 0.
  The `beq` branch at 0xa4bc targets 0xa498, is taken when t8(=[[sym(mvplock)]+1126]:1) == 0, and falls through when t8(=[[sym(mvplock)]+1126]:1) != 0.
  The `bgez` branch at 0xa4f8 targets 0xa4ac, is taken when s1(?) >= 0 (signed), and falls through when s1(?) < 0 (signed).
  The `beq` branch at 0xa524 targets 0xa554 and is always taken.
  The `blez` branch at 0xa54c targets 0xa564, is taken when t8(?) <= 0 (signed), and falls through when t8(?) > 0 (signed).
  The `bne` branch at 0xa554 targets 0xa52c, is taken when v0(?) != 0, and falls through when v0(?) == 0.
  The `bgtz` branch at 0xa55c targets 0xa554, is taken when t9(?) > 0 (signed), and falls through when t9(?) <= 0 (signed).
  The `beq` branch at 0xa57c targets 0xa4d4 and is always taken.
  The return at 0xa4ec has v0 = one of 0x0, 0x10.

- `mvppath_attach` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0xa584 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0xa584-0xa6f8 (372 bytes).
  It occupies 372 bytes.
  2 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x466, including `lbu` at 0xa584, `lbu` at 0xa6dc.
  The `lw` at 0xa5c0 loads 4 bytes from a1 (arg1 at entry) +0x8.
  The `lw` at 0xa5cc loads 4 bytes from a1 (arg1 at entry) +0x4.
  6 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x578, including `lw` at 0xa5f8, `lw` at 0xa610, `lw` at 0xa648.
  The `sw` at 0xa630 stores 4 bytes to a0 (arg0 at entry) +0x588.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x57c, including `lw` at 0xa674, `lw` at 0xa68c, `lw` at 0xa6bc.
  The `sw` at 0xa6d4 stores 4 bytes to a0 (arg0 at entry) +0x584.
  The `lw` at 0xa6e0 loads 4 bytes from a1 (arg1 at entry) +0x0.
  The `sb` at 0xa6e8 stores 1 byte to a0 (arg0 at entry) +0x466.
  The `sw` at 0xa6f4 stores 4 bytes to a0 (arg0 at entry) +0x580.
  The `jalr` at 0xa5d4 calls dms_open with a0=a0+1400, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0xa5f4 calls dms_fifo_attach with a0=[a0+1400], a1=sp-128, a2=sym(dms_fifo_attach), a3=?.
  The `jalr` at 0xa60c calls dms_close with a0=[a0+1400], a1=?, a2=?, a3=?, a4=sym(dms_close).
  The `jalr` at 0xa62c calls dms_open with a0=a0+1404, a1=?, a2=?, a3=?, a6=sym(dms_open).
  The `jalr` at 0xa644 calls dms_fifo_detach with a0=[a0+1400], a1=?, a2=?, a3=?.
  The `jalr` at 0xa654 calls dms_close with a0=[a0+1400], a1=?, a2=?, a3=?.
  The `jalr` at 0xa670 calls dms_fifo_attach with a0=[a0+1404], a1=sp-88, a2=?, a3=?.
  The `jalr` at 0xa688 calls dms_close with a0=[a0+1404], a1=?, a2=?, a3=?.
  The `jalr` at 0xa698 calls dms_fifo_detach with a0=[a0+1400], a1=?, a2=?, a3=?.
  The `jalr` at 0xa6a8 calls dms_close with a0=[a0+1400], a1=?, a2=?, a3=?.
  The `jalr` at 0xa6d0 calls dms_fifo_cache_policy with a0=[a0+1404], a1=?, a2=0x2, a3=0x0.
  The `beq` branch at 0xa5a0 targets 0xa5b8, is taken when (at(=[a0+1126]:1) & 0x2) == 0, and falls through when (at(=[a0+1126]:1) & 0x2) != 0.
  The `beq` branch at 0xa5dc targets 0xa5ec, is taken when v0(=ret(dms_open)) == 0, and falls through when v0(=ret(dms_open)) != 0.
  The `beq` branch at 0xa5e4 targets 0xa5ac and is always taken.
  The `beq` branch at 0xa5fc targets 0xa61c, is taken when v0(=ret(dms_fifo_attach)) == 0, and falls through when v0(=ret(dms_fifo_attach)) != 0.
  The `beq` branch at 0xa614 targets 0xa5a8 and is always taken.
  The `beq` branch at 0xa634 targets 0xa664, is taken when v0(=ret(dms_open)) == 0, and falls through when v0(=ret(dms_open)) != 0.
  The `beq` branch at 0xa65c targets 0xa5a8 and is always taken.
  The `beq` branch at 0xa678 targets 0xa6b8, is taken when v0(=ret(dms_fifo_attach)) == 0, and falls through when v0(=ret(dms_fifo_attach)) != 0.
  The `beq` branch at 0xa6b0 targets 0xa5a8 and is always taken.
  The `beq` branch at 0xa6f0 targets 0xa5a8 and is always taken.
  The return at 0xa5b0 has v0 = one of ?, ret(dms_open).

- `mvppath_close` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0xa6f8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0xa6f8-0xa85c (356 bytes).
  It occupies 356 bytes.
  2 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x466, including `lbu` at 0xa724, `lbu` at 0xa760.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x578, including `lw` at 0xa740, `lw` at 0xa82c.
  The `sw` at 0xa764 stores 4 bytes to a0 (arg0 at entry) +0x57c.
  The `sw` at 0xa768 stores 4 bytes to a0 (arg0 at entry) +0x578.
  The `sw` at 0xa76c stores 4 bytes to a0 (arg0 at entry) +0x584.
  The `sw` at 0xa770 stores 4 bytes to a0 (arg0 at entry) +0x588.
  The `sb` at 0xa78c stores 1 byte to a0 (arg0 at entry) +0x466.
  The `lw` at 0xa790 loads 4 bytes from a0 (arg0 at entry) +0x4a0.
  The `lw` at 0xa794 loads 4 bytes from a0 (arg0 at entry) +0x4a4.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x57c, including `lw` at 0xa7f0, `lw` at 0xa848.
  The `jalr` at 0xa70c calls mvpbuffer_close with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0xa71c calls splhi with a0=?, a1=?, a2=?, a3=?.
  The `jalr` at 0xa73c calls dms_fifo_detach with a0=[a0+1400], a1=[a0+1126]:1, a2=?, a3=?.
  The `jalr` at 0xa788 calls splx with a0=ret(splhi), a1=?, a2=sym(splx), a3=-0x7.
  The `jalr` at 0xa7c8 calls mvppath_send_available with a0=a0 at entry (arg0), a1=one of 0x20, 0x100000, 0x100020, a2=sym(mvppath_send_available), a3=?.
  The `jalr` at 0xa7d8 calls mvpcontrol_check_output with a0=a0 at entry (arg0), a1=?, a2=?, a3=sym(mvpcontrol_check_output).
  The `jalr` at 0xa7ec calls dms_fifo_detach with a0=[a0+1404], a1=?, a2=?, a3=?, a4=sym(dms_fifo_detach).
  The `jalr` at 0xa828 calls dms_close with a0=[a0+1400], a1=?, a2=?, a3=?, a5=sym(dms_close).
  The `jalr` at 0xa844 calls dms_close with a0=[a0+1404], a1=?, a2=?, a3=?, a6=sym(dms_close).
  The `beq` branch at 0xa72c targets 0xa774, is taken when (a1(=[a0+1126]:1) & 0x2) == 0, and falls through when (a1(=[a0+1126]:1) & 0x2) != 0.
  The `beq` branch at 0xa744 targets 0xa7e8, is taken when v0(=ret(dms_fifo_detach)) == 0, and falls through when v0(=ret(dms_fifo_detach)) != 0.
  The `bne` branch at 0xa7a4 targets 0xa804, is taken when a1(=[a0+1184]) < 0x3 (signed), and falls through when a1(=[a0+1184]) >= 0x3 (signed).
  The `beq` branch at 0xa7ac targets 0xa818, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0xa7b8 targets 0xa7d4, is taken when a1(=one of 0x100000, 0x100020) == 0, and falls through when a1(=one of 0x100000, 0x100020) != 0.
  The `beq` branch at 0xa7e0 targets 0xa74c and is always taken.
  The `beq` branch at 0xa7f4 targets 0xa824, is taken when v0(=ret(dms_fifo_detach)) == 0, and falls through when v0(=ret(dms_fifo_detach)) != 0.
  The `beq` branch at 0xa7fc targets 0xa750 and is always taken.
  The `beq` branch at 0xa804 targets 0xa7d4, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0xa810 targets 0xa7b8 and is always taken.
  The `beq` branch at 0xa81c targets 0xa7c4 and is always taken.
  The `beq` branch at 0xa830 targets 0xa840, is taken when v0(=ret(dms_close)) == 0, and falls through when v0(=ret(dms_close)) != 0.
  The `beq` branch at 0xa838 targets 0xa750 and is always taken.
  The `beq` branch at 0xa84c targets 0xa75c, is taken when v0(=ret(dms_close)) == 0, and falls through when v0(=ret(dms_close)) != 0.
  The `beq` branch at 0xa854 targets 0xa750 and is always taken.
  The return at 0xa754 has v0 = one of ?, ret(dms_fifo_detach), ret(dms_close).

- `mvppath_send_events` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0xa85c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0xa85c-0xa918 (188 bytes).
  It occupies 188 bytes.
  The `lw` at 0xa86c loads 4 bytes from a0 (arg0 at entry) +0x484.
  The `sw` at 0xa8a8 stores 4 bytes to a0 (arg0 at entry) +0x62c.
  The `sw` at 0xa8ac stores 4 bytes to a0 (arg0 at entry) +0x630.
  The `sw` at 0xa8b0 stores 4 bytes to a0 (arg0 at entry) +0x638.
  The `lw` at 0xa8b4 loads 4 bytes from a0 (arg0 at entry) +0x578.
  The `jalr` at 0xa8b8 calls dms_fifo_enq with a0=[a0+1400], a1=a0+1576, a2=?, a3=?.
  The `beq` branch at 0xa898 targets 0xa8f4, is taken when (s1(=[a0+1156]) & a1) == 0, and falls through when (s1(=[a0+1156]) & a1) != 0.
  The `beq` branch at 0xa8a0 targets 0xa8dc and is always taken.
  The `beq` branch at 0xa8cc targets 0xa8f4, is taken when (s1(?) & t8(?)) == 0, and falls through when (s1(?) & t8(?)) != 0.
  The `beq` branch at 0xa8d4 targets 0xa8f4, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `bne` branch at 0xa8dc targets 0xa8a8, is taken when t9(?) != 0, and falls through when t9(?) == 0.
  The `beq` branch at 0xa8e4 targets 0xa8f4, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `bne` branch at 0xa8ec targets 0xa8dc, is taken when a3(?) != 0, and falls through when a3(?) == 0.
  The return at 0xa910 has v0 = one of ?, ret(dms_fifo_enq).

- `mvppath_send_available` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0xa918 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0xa918-0xaba8 (656 bytes).
  It occupies 656 bytes.
  2 such `lbu` accesses load 1 byte from [sym(mvppath_table)] +0x4ab, including `lbu` at 0xa990, `lbu` at 0xaa14.
  2 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x4ab, including `lbu` at 0xa99c, `lbu` at 0xaae4.
  4 such `lbu` accesses load 1 byte from ?, including `lbu` at 0xa9cc, `lbu` at 0xa9d0, `lbu` at 0xa9e8.
  The `lh` at 0xaa48 loads 2 bytes from a0 (arg0 at entry) +0x468.
  The `lw` at 0xaa54 loads 4 bytes from sym(mvppath_table) +0x0.
  The `lbu` at 0xaa60 loads 1 byte from [sym(mvppath_table)] +0x466.
  The `lw` at 0xaa84 loads 4 bytes from [sym(mvppath_table)] +0x4a0.
  3 such `lw` accesses load 4 bytes from [sym(mvppath_table)] +0x4a4, including `lw` at 0xaa9c, `lw` at 0xab08, `lw` at 0xab2c.
  The `jalr` at 0xa958 calls splhi with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0xaac8 calls mvppath_send_events with a0=[sym(mvppath_table)], a1=?, a2=?, a3=sym(mvppath_send_events), a6=[a0+1195]:1.
  The `jalr` at 0xab4c calls splx with a0=ret(splhi), a1=?, a2=?, a3=?.
  The `jalr` at 0xab90 calls mvppath_send_events with a0=[sym(mvppath_table)], a1=0x10000, a2=?, a3=?.
  The `beq` branch at 0xa948 targets 0xab54, is taken when a1 == 0, and falls through when a1 != 0.
  The `beq` branch at 0xa988 targets 0xaa48 and is always taken.
  The `blez` branch at 0xa994 targets 0xaa30, is taken when a4(=[[sym(mvppath_table)]+1195]:1) <= 0 (signed), and falls through when a4(=[[sym(mvppath_table)]+1195]:1) > 0 (signed).
  The `blez` branch at 0xa9ac targets 0xaa1c, is taken when a6(=[a0+1195]:1) <= 0 (signed), and falls through when a6(=[a0+1195]:1) > 0 (signed).
  The `beq` branch at 0xa9c4 targets 0xa9e0, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `bne` branch at 0xa9d4 targets 0xa9e0, is taken when a2(?) != a3(?), and falls through when a2(?) == a3(?).
  The `beq` branch at 0xa9e0 targets 0xa9fc, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `bne` branch at 0xa9f0 targets 0xa9fc, is taken when a7(?) != t0(?), and falls through when a7(?) == t0(?).
  The `bne` branch at 0xa9fc targets 0xaac0, is taken when s1(?) != 0, and falls through when s1(?) == 0.
  The `bne` branch at 0xaa0c targets 0xa9c4, is taken when s2(?) < a6(=[a0+1195]:1) (signed), and falls through when s2(?) >= a6(=[a0+1195]:1) (signed).
  The `bne` branch at 0xaa28 targets 0xa9ac, is taken when t2(?) < a4(=[[sym(mvppath_table)]+1195]:1) (signed), and falls through when t2(?) >= a4(=[[sym(mvppath_table)]+1195]:1) (signed).
  The `beq` branch at 0xaa40 targets 0xab44, is taken when s8(?) >= 0x40 (signed), and falls through when s8(?) < 0x40 (signed).
  The `beq` branch at 0xaa4c targets 0xaa30, is taken when t9(=[a0+1128]:2) == s8(?), and falls through when t9(=[a0+1128]:2) != s8(?).
  The `beq` branch at 0xaa58 targets 0xaa30, is taken when s6(=[sym(mvppath_table)]) == 0, and falls through when s6(=[sym(mvppath_table)]) != 0.
  The `beq` branch at 0xaa68 targets 0xaa30, is taken when (t8(=[[sym(mvppath_table)]+1126]:1) & 0x4) == 0, and falls through when (t8(=[[sym(mvppath_table)]+1126]:1) & 0x4) != 0.
  The `beq` branch at 0xaa74 targets 0xab84, is taken when t9(=a1) == ra(=0x10000), and falls through when t9(=a1) != ra(=0x10000).
  The `beq` branch at 0xaa7c targets 0xab00, is taken when at(?) == 0, and falls through when at(?) != 0.
  The `beq` branch at 0xaa8c targets 0xab20, is taken when v0(=[[sym(mvppath_table)]+1184]) == v1(=0x2), and falls through when v0(=[[sym(mvppath_table)]+1184]) != v1(=0x2).
  The `beq` branch at 0xaa94 targets 0xaa30, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `bne` branch at 0xaaa4 targets 0xaa30, is taken when a1(=[[sym(mvppath_table)]+1188]) != a2(=0x2), and falls through when a1(=[[sym(mvppath_table)]+1188]) == a2(=0x2).
  The `bne` branch at 0xaab0 targets 0xa990, is taken when s5(?) != 0, and falls through when s5(?) == 0.
  The `beq` branch at 0xaab8 targets 0xaa34 and is always taken.
  The `beq` branch at 0xaadc targets 0xaa30, is taken when (s5(?) & a4(?)) == 0, and falls through when (s5(?) & a4(?)) != 0.
  The `bne` branch at 0xaaf0 targets 0xa9bc, is taken when a4(?) < a6(=[a0+1195]:1) (signed), and falls through when a4(?) >= a6(=[a0+1195]:1) (signed).
  The `beq` branch at 0xaaf8 targets 0xaa14 and is always taken.
  The `beq` branch at 0xab00 targets 0xaa30, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `bne` branch at 0xab10 targets 0xaa30, is taken when a7(=[[sym(mvppath_table)]+1188]) != t0(=0x2), and falls through when a7(=[[sym(mvppath_table)]+1188]) == t0(=0x2).
  The `beq` branch at 0xab18 targets 0xaaac and is always taken.
  The `beq` branch at 0xab24 targets 0xab3c, is taken when t1(?) == 0, and falls through when t1(?) != 0.
  The `beq` branch at 0xab34 targets 0xaba0, is taken when t2(=[[sym(mvppath_table)]+1188]) == t3(=0x2), and falls through when t2(=[[sym(mvppath_table)]+1188]) != t3(=0x2).
  The `beq` branch at 0xab3c targets 0xa990 and is always taken.
  The `beq` branch at 0xab98 targets 0xaa34 and is always taken.
  The `beq` branch at 0xaba0 targets 0xaaac and is always taken.
  The return at 0xab7c has v0 = one of ?, ret(splx).

- `mvppath_add_preempt` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0xaba8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0xaba8-0xac0c (100 bytes).
  It occupies 100 bytes.
  The `lw` at 0xaba8 loads 4 bytes from a0 (arg0 at entry) +0x7b0.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0xabbc, `lw` at 0xabf4.
  3 such `sw` accesses store 4 bytes to ?, including `sw` at 0xabdc, `sw` at 0xabe0, `sw` at 0xac00.
  The `sw` at 0xabe8 stores 4 bytes to a0 (arg0 at entry) +0x7b0.
  The `blez` branch at 0xabb0 targets 0xac04, is taken when a7(=[a0+1968]) <= 0 (signed), and falls through when a7(=[a0+1968]) > 0 (signed).
  The `beq` branch at 0xabc4 targets 0xabf4, is taken when at(?) == a1, and falls through when at(?) != a1.
  The `bne` branch at 0xabcc targets 0xabbc, is taken when a6(?) != 0, and falls through when a6(?) == 0.
  The `beq` branch at 0xac04 targets 0xabd8 and is always taken.
  The return at 0xabec has v0 = one of ?, 0x1.
  The return at 0xabfc has v0 = ?.

- `mvppath_free_memnode` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0xac0c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0xac0c-0xb01c (1040 bytes).
  It occupies 1040 bytes.
  The `lh` at 0xac0c loads 2 bytes from a0 (arg0 at entry) +0x468.
  The `lbu` at 0xac34 loads 1 byte from a1 (arg1 at entry) +0xe.
  The `lbu` at 0xac40 loads 1 byte from a1 (arg1 at entry) +0xd.
  21 such `lbu` accesses load 1 byte from ?, including `lbu` at 0xac78, `lbu` at 0xac8c, `lbu` at 0xacd8.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0xaccc, `lw` at 0xacec.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x460, including `lw` at 0xae00, `lw` at 0xaea8, `lw` at 0xafe8.
  The `sb` at 0xae08 stores 1 byte to [a0+1120] +0x68.
  The `lbu` at 0xafec loads 1 byte from [a0+1120] +0x68.
  The `jalr` at 0xae9c calls .text+43944 with a0=a0 at entry (arg0), a1=?, a2=0x8, a3=?.
  The `jalr` at 0xaf64 calls .text+43944 with a0=a0 at entry (arg0), a1=?, a2=0x8, a3=?, a5=sym(mvppath_add_preempt), a6=0xc.
  The `beq` branch at 0xac84 targets 0xacb8 and is always taken.
  The `beq` branch at 0xac90 targets 0xaeac, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0xac98 targets 0xaee4, is taken when ra(=0x1) == a0(?), and falls through when ra(=0x1) != a0(?).
  The `beq` branch at 0xaca8 targets 0xad50, is taken when v0(?) >= 0x40 (signed), and falls through when v0(?) < 0x40 (signed).
  The `beq` branch at 0xacb0 targets 0xad54, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `beq` branch at 0xacb8 targets 0xac9c, is taken when t0(=[a0+1128]:2) == v0(?), and falls through when t0(=[a0+1128]:2) != v0(?).
  The `beq` branch at 0xacd0 targets 0xaca0, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `beq` branch at 0xace0 targets 0xaca0, is taken when (at(?) & 0x4) == 0, and falls through when (at(?) & 0x4) != 0.
  The `beq` branch at 0xacf0 targets 0xac8c, is taken when a0(?) == v1(=0x3), and falls through when a0(?) != v1(=0x3).
  The `bne` branch at 0xacf8 targets 0xaca0, is taken when a0(?) != a1(=0x4), and falls through when a0(?) == a1(=0x4).
  The `beq` branch at 0xad04 targets 0xaf1c, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `bne` branch at 0xad0c targets 0xaca0, is taken when ra(=0x1) != a0(?), and falls through when ra(=0x1) == a0(?).
  The `beq` branch at 0xad14 targets 0xb014, is taken when t1(?) == ra(=0x1), and falls through when t1(?) != ra(=0x1).
  The `beq` branch at 0xad48 targets 0xac9c and is always taken.
  The `beq` branch at 0xad58 targets 0xae90, is taken when a5(?) == a6(=0xc), and falls through when a5(?) != a6(=0xc).
  The `beq` branch at 0xad60 targets 0xae28, is taken when t1(?) == 0, and falls through when t1(?) != 0.
  The `beq` branch at 0xad68 targets 0xae74, is taken when t1(?) == ra(=0x1), and falls through when t1(?) != ra(=0x1).
  The `beq` branch at 0xad70 targets 0xae7c, is taken when t0(?) == 0, and falls through when t0(?) != 0.
  The `beq` branch at 0xad78 targets 0xadec, is taken when a7(?) == 0, and falls through when a7(?) != 0.
  The `bne` branch at 0xad88 targets 0xadec, is taken when t1(?) != t8(?), and falls through when t1(?) == t8(?).
  The `beq` branch at 0xad98 targets 0xadec, is taken when t9(?) == ra(?), and falls through when t9(?) != ra(?).
  The `beq` branch at 0xada4 targets 0xadd4, is taken when (s0(?) & 0x4) == 0, and falls through when (s0(?) & 0x4) != 0.
  The `beq` branch at 0xadac targets 0xae0c and is always taken.
  The `beq` branch at 0xadb4 targets 0xaf74, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0xadbc targets 0xaf7c, is taken when s0(?) == ra(=0x1), and falls through when s0(?) != ra(=0x1).
  The `beq` branch at 0xadc4 targets 0xaf84, is taken when s0(?) == v0(=0x2), and falls through when s0(?) != v0(=0x2).
  The `beq` branch at 0xadcc targets 0xaf8c, is taken when s0(?) == v1(=0x3), and falls through when s0(?) != v1(=0x3).
  The `beq` branch at 0xadd4 targets 0xadec, is taken when a7(?) == 0, and falls through when a7(?) != 0.
  The `beq` branch at 0xade0 targets 0xaf58, is taken when (s0(?) & 0x4) == 0, and falls through when (s0(?) & 0x4) != 0.
  The `beq` branch at 0xadec targets 0xae00, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `beq` branch at 0xadf8 targets 0xae98, is taken when (s0(?) & 0x8) == 0, and falls through when (s0(?) & 0x8) != 0.
  The `beq` branch at 0xae28 targets 0xadd4, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `bne` branch at 0xae38 targets 0xae64, is taken when a1(?) != a2(?), and falls through when a1(?) == a2(?).
  The `beq` branch at 0xae4c targets 0xae64, is taken when a3(?) == a4(?), and falls through when a3(?) != a4(?).
  The `beq` branch at 0xae54 targets 0xadd4, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0xae5c targets 0xae10 and is always taken.
  The `beq` branch at 0xae64 targets 0xae00, is taken when a7(?) == 0, and falls through when a7(?) != 0.
  The `beq` branch at 0xae6c targets 0xaddc and is always taken.
  The `beq` branch at 0xae74 targets 0xad78 and is always taken.
  The `beq` branch at 0xae80 targets 0xadb4, is taken when (s0(?) & 0x8) == 0, and falls through when (s0(?) & 0x8) != 0.
  The `beq` branch at 0xae88 targets 0xae28 and is always taken.
  The `beq` branch at 0xae90 targets 0xae10 and is always taken.
  The `beq` branch at 0xaea4 targets 0xae04 and is always taken.
  The `beq` branch at 0xaedc targets 0xac9c and is always taken.
  The `beq` branch at 0xaf14 targets 0xac9c and is always taken.
  The `beq` branch at 0xaf1c targets 0xb00c, is taken when t1(?) == 0, and falls through when t1(?) != 0.
  The `beq` branch at 0xaf50 targets 0xac9c and is always taken.
  The `beq` branch at 0xaf6c targets 0xadec and is always taken.
  The `beq` branch at 0xaf74 targets 0xae28 and is always taken.
  The `beq` branch at 0xaf7c targets 0xad78 and is always taken.
  The `beq` branch at 0xaf84 targets 0xae28 and is always taken.
  The `bne` branch at 0xafc0 targets 0xafd8, is taken when a0(?) != v1(?), and falls through when a0(?) == v1(?).
  The `beq` branch at 0xafc8 targets 0xafe8, is taken when a0(?) == v0(?), and falls through when a0(?) != v0(?).
  The `beq` branch at 0xafd0 targets 0xad78 and is always taken.
  The `bne` branch at 0xafd8 targets 0xafe8, is taken when a0(?) != v0(?), and falls through when a0(?) == v0(?).
  The `beq` branch at 0xafe0 targets 0xae28 and is always taken.
  The `beq` branch at 0xaff4 targets 0xae28, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `bne` branch at 0xaffc targets 0xadd4, is taken when s1(?) != ra(=0x1), and falls through when s1(?) == ra(=0x1).
  The `beq` branch at 0xb004 targets 0xad78 and is always taken.
  The `beq` branch at 0xb00c targets 0xae0c and is always taken.
  The `beq` branch at 0xb014 targets 0xae0c and is always taken.
  The return at 0xae20 has v0 = one of ?, -0x1.

- `mvppath_check_conflicts` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0xb01c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0xb01c-0xb268 (588 bytes).
  It occupies 588 bytes.
  The `lw` at 0xb034 loads 4 bytes from a1 (arg1 at entry) +0x4.
  The `lbu` at 0xb058 loads 1 byte from a1 (arg1 at entry) +0xc.
  2 such `lh` accesses load 2 bytes from a0 (arg0 at entry) +0x468, including `lh` at 0xb080, `lh` at 0xb14c.
  2 such `lw` accesses load 4 bytes from sym(mvppath_table) +0x0, including `lw` at 0xb0a4, `lw` at 0xb158.
  2 such `lbu` accesses load 1 byte from [sym(mvppath_table)] +0x466, including `lbu` at 0xb0b0, `lbu` at 0xb164.
  The `lbu` at 0xb0c0 loads 1 byte from [sym(mvppath_table)] +0x46c.
  The `lw` at 0xb0cc loads 4 bytes from [sym(mvppath_table)] +0x4a0.
  The `sb` at 0xb0f0 stores 1 byte to a0 (arg0 at entry) +0x46c.
  The `lw` at 0xb0f4 loads 4 bytes from a1 (arg1 at entry) +0x8.
  2 such `lw` accesses load 4 bytes from [sym(mvppath_table)] +0x4a4, including `lw` at 0xb128, `lw` at 0xb17c.
  The `lbu` at 0xb188 loads 1 byte from [sym(mvppath_table)] +0x4ab.
  The `lbu` at 0xb198 loads 1 byte from a1 (arg1 at entry) +0xf.
  2 such `lbu` accesses load 1 byte from ?, including `lbu` at 0xb1a8, `lbu` at 0xb1b0.
  The `lbu` at 0xb244 loads 1 byte from a1 (arg1 at entry) +0xe.
  The `sb` at 0xb25c stores 1 byte to ?.
  The `jalr` at 0xb0e8 calls .text+43944 with a0=a0 at entry (arg0), a1=[sym(mvppath_table)], a2=0x8, a3=a3 at entry (arg3).
  The `jalr` at 0xb134 calls .text+43944 with a0=a0 at entry (arg0), a1=[sym(mvppath_table)], a2=0x80000, a3=?, a7=[a1+15]:1.
  The `jalr` at 0xb230 calls .text+44044 with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=sym(mvppath_free_memnode).
  The `bne` branch at 0xb050 targets 0xb0f4, is taken when at(=[a1+4]) < 0x3 (signed), and falls through when at(=[a1+4]) >= 0x3 (signed).
  The `beq` branch at 0xb060 targets 0xb228, is taken when a0(=[a1+12]:1) == v0(=0x1), and falls through when a0(=[a1+12]:1) != v0(=0x1).
  The `beq` branch at 0xb068 targets 0xb210, is taken when v0(=0x2) == a0(=[a1+12]:1), and falls through when v0(=0x2) != a0(=[a1+12]:1).
  The `beq` branch at 0xb084 targets 0xb09c and is always taken.
  The `beq` branch at 0xb094 targets 0xb0f0, is taken when s0(?) >= 0x40 (signed), and falls through when s0(?) < 0x40 (signed).
  The `beq` branch at 0xb09c targets 0xb08c, is taken when a0(=[a0+1128]:2) == s0(?), and falls through when a0(=[a0+1128]:2) != s0(?).
  The `beq` branch at 0xb0a8 targets 0xb08c, is taken when a1(=[sym(mvppath_table)]) == 0, and falls through when a1(=[sym(mvppath_table)]) != 0.
  The `beq` branch at 0xb0b8 targets 0xb08c, is taken when (t9(=[[sym(mvppath_table)]+1126]:1) & 0x4) == 0, and falls through when (t9(=[[sym(mvppath_table)]+1126]:1) & 0x4) != 0.
  The `bne` branch at 0xb0c4 targets 0xb08c, is taken when s4(=one of 0x2, 0x3) != ra(=[[sym(mvppath_table)]+1132]:1), and falls through when s4(=one of 0x2, 0x3) == ra(=[[sym(mvppath_table)]+1132]:1).
  The `beq` branch at 0xb0d0 targets 0xb220, is taken when v0(=[[sym(mvppath_table)]+1184]) == s3(=0x4), and falls through when v0(=[[sym(mvppath_table)]+1184]) != s3(=0x4).
  The `bne` branch at 0xb0d8 targets 0xb08c, is taken when v0(=[[sym(mvppath_table)]+1184]) != a2(=0x3), and falls through when v0(=[[sym(mvppath_table)]+1184]) == a2(=0x3).
  The `bne` branch at 0xb108 targets 0xb1e0, is taken when v0(=[a1+8]) < 0x3 (signed), and falls through when v0(=[a1+8]) >= 0x3 (signed).
  The `beq` branch at 0xb120 targets 0xb14c and is always taken.
  The `beq` branch at 0xb12c targets 0xb218, is taken when t8(=[[sym(mvppath_table)]+1188]) == s3(=0x4), and falls through when t8(=[[sym(mvppath_table)]+1188]) != s3(=0x4).
  The `beq` branch at 0xb144 targets 0xb1e0, is taken when s0(?) >= 0x40 (signed), and falls through when s0(?) < 0x40 (signed).
  The `beq` branch at 0xb150 targets 0xb13c, is taken when ra(=[a0+1128]:2) == s0(?), and falls through when ra(=[a0+1128]:2) != s0(?).
  The `beq` branch at 0xb15c targets 0xb13c, is taken when a1(=[sym(mvppath_table)]) == 0, and falls through when a1(=[sym(mvppath_table)]) != 0.
  The `beq` branch at 0xb16c targets 0xb13c, is taken when (at(=[[sym(mvppath_table)]+1126]:1) & 0x4) == 0, and falls through when (at(=[[sym(mvppath_table)]+1126]:1) & 0x4) != 0.
  The `bne` branch at 0xb174 targets 0xb188, is taken when s4(?) != 0, and falls through when s4(?) == 0.
  The `bne` branch at 0xb180 targets 0xb13c, is taken when v0(=[[sym(mvppath_table)]+1188]) != s3(=0x4), and falls through when v0(=[[sym(mvppath_table)]+1188]) == s3(=0x4).
  The `blez` branch at 0xb190 targets 0xb13c, is taken when t2(=[[sym(mvppath_table)]+1195]:1) <= 0 (signed), and falls through when t2(=[[sym(mvppath_table)]+1195]:1) > 0 (signed).
  The `blez` branch at 0xb19c targets 0xb1c8, is taken when a7(=[a1+15]:1) <= 0 (signed), and falls through when a7(=[a1+15]:1) > 0 (signed).
  The `beq` branch at 0xb1b8 targets 0xb128, is taken when v1(?) == t0(?), and falls through when v1(?) != t0(?).
  The `bne` branch at 0xb1c0 targets 0xb1b0, is taken when a6(?) != 0, and falls through when a6(?) == 0.
  The `bne` branch at 0xb1d0 targets 0xb19c, is taken when t1(?) < t2(=[[sym(mvppath_table)]+1195]:1) (signed), and falls through when t1(?) >= t2(=[[sym(mvppath_table)]+1195]:1) (signed).
  The `beq` branch at 0xb1d8 targets 0xb140 and is always taken.
  The `beq` branch at 0xb210 targets 0xb074 and is always taken.
  The `beq` branch at 0xb218 targets 0xb1e4 and is always taken.
  The `beq` branch at 0xb220 targets 0xb1e4 and is always taken.
  The `beq` branch at 0xb23c targets 0xb260, is taken when v0(=ret(.text+44044)) == a4(=-0x1), and falls through when v0(=ret(.text+44044)) != a4(=-0x1).
  The `beq` branch at 0xb258 targets 0xb0f0 and is always taken.
  The `beq` branch at 0xb260 targets 0xb1e4 and is always taken.
  The return at 0xb208 has v0 = one of -0x1, 0x0.

- `mvppath_setup` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0xb268 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0xb268-0xb4fc (660 bytes).
  It occupies 660 bytes.
  2 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x4, including `lw` at 0xb2a8, `lw` at 0xb3e8.
  2 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x8, including `lw` at 0xb2c0, `lw` at 0xb3e0.
  The `lw` at 0xb2d4 loads 4 bytes from a0 (arg0 at entry) +0x4a4.
  The `lw` at 0xb2e0 loads 4 bytes from a0 (arg0 at entry) +0x4a0.
  The `sw` at 0xb2f0 stores 4 bytes to a1 (arg1 at entry) +0x0.
  The `lbu` at 0xb30c loads 1 byte from a0 (arg0 at entry) +0x466.
  The `sb` at 0xb324 stores 1 byte to a0 (arg0 at entry) +0x466.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x7b0, including `lw` at 0xb328, `lw` at 0xb37c.
  3 such `sw` accesses store 4 bytes to ?, including `sw` at 0xb34c, `sw` at 0xb358, `sw` at 0xb364.
  3 such `lw` accesses load 4 bytes from ?, including `lw` at 0xb350, `lw` at 0xb390, `lw` at 0xb39c.
  The `lbu` at 0xb3ac loads 1 byte from ?.
  The `sw` at 0xb4ec stores 4 bytes to a1 (arg1 at entry) +0x8.
  The `sw` at 0xb4f0 stores 4 bytes to a1 (arg1 at entry) +0x4.
  The `sw` at 0xb4f8 stores 4 bytes to a0 (arg0 at entry) +0x7b0.
  The `jalr` at 0xb290 calls bzero with a0=a0+1968, a1=0x204, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0xb2a0 calls splhi with a0=?, a1=?, a2=?, a3=?.
  The `jalr` at 0xb2f8 calls bcopy with a0=a1 at entry (arg1), a1=a0+1180, a2=0xdc, a3=?.
  The `jalr` at 0xb320 calls splx with a0=ret(splhi), a1=?, a2=?, a3=?.
  The `jalr` at 0xb344 calls splhi with a0=?, a1=?, a2=?, a3=?.
  The `jalr` at 0xb360 calls splx with a0=ret(splhi), a1=?, a2=?, a3=?.
  The `jalr` at 0xb374 calls mvppath_send_events with a0=?, a1=?, a2=?, a3=sym(mvppath_send_events).
  The `jalr` at 0xb3c0 calls mvptransfer_shutdown with a0=?, a1=?, a2=?, a3=sym(mvppath_send_events), a4=[a0+1968].
  The `jalr` at 0xb460 calls mvppath_send_available with a0=a0 at entry (arg0), a1=one of 0x20, 0x100000, 0x100020, a2=?, a3=sym(mvppath_send_available), a4=0x100000.
  The `jalr` at 0xb4a8 calls .text+45084 with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?, a4=sym(mvppath_check_conflicts).
  The `beq` branch at 0xb2b8 targets 0xb49c, is taken when t8(=[a1+4]) >= 0x3 (signed), and falls through when t8(=[a1+4]) < 0x3 (signed).
  The `beq` branch at 0xb2c8 targets 0xb4a0, is taken when t9(=[a1+8]) >= 0x3 (signed), and falls through when t9(=[a1+8]) < 0x3 (signed).
  The `blez` branch at 0xb334 targets 0xb3e0, is taken when a4(=[a0+1968]) <= 0 (signed), and falls through when a4(=[a0+1968]) > 0 (signed).
  The `beq` branch at 0xb33c targets 0xb390 and is always taken.
  The `beq` branch at 0xb388 targets 0xb3e0, is taken when s2(?) >= a4(=[a0+1968]) (signed), and falls through when s2(?) < a4(=[a0+1968]) (signed).
  The `beq` branch at 0xb394 targets 0xb3d0, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `beq` branch at 0xb3a4 targets 0xb36c, is taken when (s7(?) & 0x8) == 0, and falls through when (s7(?) & 0x8) != 0.
  The `bne` branch at 0xb3b4 targets 0xb344, is taken when a7(?) < 0x4 (signed), and falls through when a7(?) >= 0x4 (signed).
  The `beq` branch at 0xb3c8 targets 0xb344 and is always taken.
  The `bne` branch at 0xb3d8 targets 0xb390, is taken when s2(?) < a4(=[a0+1968]) (signed), and falls through when s2(?) >= a4(=[a0+1968]) (signed).
  The `beq` branch at 0xb404 targets 0xb434, is taken when a2(=[a1+4]) >= 0x3 (signed), and falls through when a2(=[a1+4]) < 0x3 (signed).
  The `bne` branch at 0xb40c targets 0xb4c4, is taken when a1(?) != 0, and falls through when a1(?) == 0.
  The `beq` branch at 0xb414 targets 0xb4dc, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `bne` branch at 0xb424 targets 0xb4dc, is taken when a2(=[a0+1188]) < 0x3 (signed), and falls through when a2(=[a0+1188]) >= 0x3 (signed).
  The `beq` branch at 0xb42c targets 0xb44c and is always taken.
  The `beq` branch at 0xb434 targets 0xb46c, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `bne` branch at 0xb43c targets 0xb46c, is taken when a5(?) != 0, and falls through when a5(?) == 0.
  The `beq` branch at 0xb44c targets 0xb46c, is taken when s2(=one of 0x100000, 0x100020) == 0, and falls through when s2(=one of 0x100000, 0x100020) != 0.
  The `beq` branch at 0xb4b4 targets 0xb4e4, is taken when v0(=ret(.text+45084)) == a5(=-0x1), and falls through when v0(=ret(.text+45084)) != a5(=-0x1).
  The `beq` branch at 0xb4bc targets 0xb2d4 and is always taken.
  The `beq` branch at 0xb4c4 targets 0xb46c, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `bne` branch at 0xb4cc targets 0xb468, is taken when a5(?) != 0, and falls through when a5(?) == 0.
  The `beq` branch at 0xb4d4 targets 0xb44c and is always taken.
  The `beq` branch at 0xb4dc targets 0xb454 and is always taken.
  The `beq` branch at 0xb4f4 targets 0xb2d4 and is always taken.
  The return at 0xb494 has v0 = one of 0x0, 0xd.

- `mvppath_ioctl` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0xb4fc (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0xb4fc-0xb6a8 (428 bytes).
  It occupies 428 bytes.
  The `lw` at 0xb574 loads 4 bytes from table(sym(.rodata)+5524) +0x0.
  The `jalr` at 0xb524 calls mvpcopyin with a0=a2 at entry (arg2), a1=sp-272, a2=0xe8, a3=a3 at entry (arg3).
  The `jalr` at 0xb590 calls copyout with a0=sp-272, a1=a2 at entry (arg2), a2=0xe8, a3=sym(copyout).
  The `beq` branch at 0xb52c targets 0xb54c, is taken when v0(=ret(mvpcopyin)) == 0, and falls through when v0(=ret(mvpcopyin)) != 0.
  The `beq` branch at 0xb56c targets 0xb580, is taken when v1(?) >= 0x8 (unsigned), and falls through when v1(?) < 0x8 (unsigned).
  The `beq` branch at 0xb598 targets 0xb538 and is always taken.
  The return at 0xb544 has v0 = one of ret(mvpcopyin), 0x16.
  The instructions from 0xb5a0 to 0xb6a4 are not reached by any path from the entry, and their branches are not listed.
  The indirect jump at 0xb578 uses a jump table whose successors are unresolved.

- `mvpreg_initmace` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0xb6a8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0xb6a8-0xb8c0 (536 bytes).
  It occupies 536 bytes.
  3 such `lw` accesses load 4 bytes from sym(mvpcontroller_table) +0x0, including `lw` at 0xb720, `lw` at 0xb7c0, `lw` at 0xb81c.
  The `lw` at 0xb73c loads 4 bytes from ([sym(mvpcontroller_table)] + (a1 << 0x2)) +0xc0.
  14 such `ld` accesses load 8 bytes from ?, including `ld` at 0xb750, `ld` at 0xb764, `ld` at 0xb770.
  9 such `sd` accesses store 8 bytes to ?, including `sd` at 0xb754, `sd` at 0xb75c, `sd` at 0xb768.
  The `sd` at 0xb758 stores 8 bytes to [([sym(mvpcontroller_table)] + (a1 << 0x2))+192] +0x30.
  The `sd` at 0xb760 stores 8 bytes to [([sym(mvpcontroller_table)] + (a1 << 0x2))+192] +0x48.
  The `sd` at 0xb76c stores 8 bytes to [([sym(mvpcontroller_table)] + (a1 << 0x2))+192] +0x38.
  The `sd` at 0xb778 stores 8 bytes to [([sym(mvpcontroller_table)] + (a1 << 0x2))+192] +0x50.
  The `sd` at 0xb784 stores 8 bytes to [([sym(mvpcontroller_table)] + (a1 << 0x2))+192] +0x28.
  The `sd` at 0xb790 stores 8 bytes to [([sym(mvpcontroller_table)] + (a1 << 0x2))+192] +0x40.
  The `sd` at 0xb798 stores 8 bytes to [([sym(mvpcontroller_table)] + (a1 << 0x2))+192] +0x58.
  The `sd` at 0xb7a8 stores 8 bytes to [([sym(mvpcontroller_table)] + (a1 << 0x2))+192] +0x20.
  The `sd` at 0xb7b8 stores 8 bytes to [([sym(mvpcontroller_table)] + (a1 << 0x2))+192] +0x10.
  The `lw` at 0xb7c4 loads 4 bytes from [sym(mvpcontroller_table)] +0xcc.
  The `sw` at 0xb7c8 stores 4 bytes to [sym(mvpcontroller_table)] +0x318.
  The `sw` at 0xb7cc stores 4 bytes to [[sym(mvpcontroller_table)]+204] +0x0.
  The `sw` at 0xb7d0 stores 4 bytes to [sym(mvpcontroller_table)] +0x31c.
  The `sw` at 0xb7d4 stores 4 bytes to [[sym(mvpcontroller_table)]+204] +0x4.
  The `sw` at 0xb7d8 stores 4 bytes to [sym(mvpcontroller_table)] +0x320.
  The `sw` at 0xb7dc stores 4 bytes to [[sym(mvpcontroller_table)]+204] +0x8.
  The `sw` at 0xb7e0 stores 4 bytes to [sym(mvpcontroller_table)] +0x324.
  The `sw` at 0xb7e4 stores 4 bytes to [[sym(mvpcontroller_table)]+204] +0xc.
  The `sw` at 0xb7e8 stores 4 bytes to [sym(mvpcontroller_table)] +0x328.
  The `sw` at 0xb7ec stores 4 bytes to [[sym(mvpcontroller_table)]+204] +0x10.
  The `sw` at 0xb7f0 stores 4 bytes to [sym(mvpcontroller_table)] +0x32c.
  The `sw` at 0xb7f4 stores 4 bytes to [[sym(mvpcontroller_table)]+204] +0x14.
  The `sw` at 0xb7f8 stores 4 bytes to [sym(mvpcontroller_table)] +0x330.
  The `sw` at 0xb7fc stores 4 bytes to [[sym(mvpcontroller_table)]+204] +0x18.
  The `sw` at 0xb800 stores 4 bytes to [sym(mvpcontroller_table)] +0x334.
  The `sw` at 0xb804 stores 4 bytes to [[sym(mvpcontroller_table)]+204] +0x1c.
  The `sw` at 0xb808 stores 4 bytes to [sym(mvpcontroller_table)] +0x338.
  The `sw` at 0xb810 stores 4 bytes to [[sym(mvpcontroller_table)]+204] +0x20.
  The `lw` at 0xb834 loads 4 bytes from [sym(mvpcontroller_table)] +0xc8.
  The `sd` at 0xb83c stores 8 bytes to [sym(mvpcontroller_table)] +0x288.
  The `sd` at 0xb840 stores 8 bytes to [[sym(mvpcontroller_table)]+200] +0x30.
  The `sd` at 0xb844 stores 8 bytes to [sym(mvpcontroller_table)] +0x298.
  The `sd` at 0xb848 stores 8 bytes to [[sym(mvpcontroller_table)]+200] +0x40.
  The `sd` at 0xb850 stores 8 bytes to [sym(mvpcontroller_table)] +0x290.
  The `sd` at 0xb854 stores 8 bytes to [[sym(mvpcontroller_table)]+200] +0x38.
  The `sd` at 0xb85c stores 8 bytes to [sym(mvpcontroller_table)] +0x2a0.
  The `sd` at 0xb860 stores 8 bytes to [[sym(mvpcontroller_table)]+200] +0x48.
  The `sd` at 0xb868 stores 8 bytes to [sym(mvpcontroller_table)] +0x280.
  The `sd` at 0xb86c stores 8 bytes to [[sym(mvpcontroller_table)]+200] +0x28.
  The `sd` at 0xb874 stores 8 bytes to [sym(mvpcontroller_table)] +0x278.
  The `sd` at 0xb87c stores 8 bytes to [[sym(mvpcontroller_table)]+200] +0x20.
  The `sd` at 0xb888 stores 8 bytes to [sym(mvpcontroller_table)] +0x2a8.
  The `sd` at 0xb88c stores 8 bytes to [[sym(mvpcontroller_table)]+200] +0x50.
  The `lhu` at 0xb890 loads 2 bytes from [sym(mvpcontroller_table)] +0x2ae.
  The `sh` at 0xb894 stores 2 bytes to a0 (arg0 at entry) +0x72.
  The `sd` at 0xb89c stores 8 bytes to [sym(mvpcontroller_table)] +0x268.
  The `sd` at 0xb8a4 stores 8 bytes to [[sym(mvpcontroller_table)]+200] +0x10.
  The `jalr` at 0xb6c8 calls splhi with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0xb6fc calls splx with a0=ret(splhi), a1=?, a2=?, a3=?.
  The `beq` branch at 0xb6d8 targets 0xb710, is taken when s0(=a1) == 0, and falls through when s0(=a1) != 0.
  The `beq` branch at 0xb6e0 targets 0xb710, is taken when s0(=a1) == a1(=0x1), and falls through when s0(=a1) != a1(=0x1).
  The `beq` branch at 0xb6e8 targets 0xb814, is taken when s0(=a1) == v0(=0x2), and falls through when s0(=a1) != v0(=0x2).
  The `beq` branch at 0xb6f0 targets 0xb7bc, is taken when s0(=a1) == a6(=0x3), and falls through when s0(=a1) != a6(=0x3).
  The `beq` branch at 0xb740 targets 0xb8a8, is taken when (a1(=a2) & 0x1) == 0, and falls through when (a1(=a2) & 0x1) != 0.
  The `bne` branch at 0xb7a4 targets 0xb6f4, is taken when a2(=a3) != 0, and falls through when a2(=a3) == 0.
  The `beq` branch at 0xb7b4 targets 0xb6f4 and is always taken.
  The `beq` branch at 0xb80c targets 0xb6f4 and is always taken.
  The `beq` branch at 0xb830 targets 0xb8b4, is taken when (t9(=a2) & 0x1) == 0, and falls through when (t9(=a2) & 0x1) != 0.
  The `bne` branch at 0xb878 targets 0xb6f4, is taken when at(=a3) != 0, and falls through when at(=a3) == 0.
  The `beq` branch at 0xb8a0 targets 0xb6f4 and is always taken.
  The `beq` branch at 0xb8ac targets 0xb750 and is always taken.
  The `beq` branch at 0xb8b8 targets 0xb838 and is always taken.
  The return at 0xb708 has v0 = ret(splx).

- `mvpreg_setup_timing` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0xb8c0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0xb8c0-0xb8e4 (36 bytes).
  It occupies 36 bytes.
  The `jalr` at 0xb8d0 calls .text+46760 with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=0x1.
  The return at 0xb8dc has v0 = ret(.text+46760).

- `mvpreg_cdto_wait` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0xb8e4 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0xb8e4-0xb910 (44 bytes).
  It occupies 44 bytes.
  The `lw` at 0xb8fc loads 4 bytes from sym(mvpcdto_wait_time) +0x0.
  The `jalr` at 0xb8f8 calls delay with a0=[sym(mvpcdto_wait_time)], a1=sym(delay), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xb908 has v0 = 0x1.

- `mvpreg_setpassthru` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0xb910 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0xb910-0xbdb0 (1184 bytes).
  It occupies 1184 bytes.
  The `lw` at 0xb918 loads 4 bytes from a0 (arg0 at entry) +0xc8.
  The `lbu` at 0xb920 loads 1 byte from a0 (arg0 at entry) +0x61.
  3 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x268, including `ld` at 0xb984, `ld` at 0xbb1c, `ld` at 0xbb4c.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x2b0, including `ld` at 0xb9ac, `ld` at 0xbb38.
  The `lbu` at 0xb9d0 loads 1 byte from (a0 + ([a0+97]:1 << 0x2)) +0x74.
  The `lw` at 0xba44 loads 4 bytes from (sym(.rodata)+5556 + ([a0+97]:1 << 0x2)) +0x0.
  The `sb` at 0xba94 stores 1 byte to a0 (arg0 at entry) +0x6b.
  The `sb` at 0xba98 stores 1 byte to a0 (arg0 at entry) +0x6a.
  The `lbu` at 0xbab0 loads 1 byte from a0 (arg0 at entry) +0x9c.
  The `ld` at 0xbb14 loads 8 bytes from a0 (arg0 at entry) +0x258.
  The `sd` at 0xbb30 stores 8 bytes to a0 (arg0 at entry) +0x258.
  The `sd` at 0xbb34 stores 8 bytes to [a0+200] +0x0.
  The `sd` at 0xbb44 stores 8 bytes to a0 (arg0 at entry) +0x2b0.
  The `sd` at 0xbb48 stores 8 bytes to [a0+200] +0x58.
  The `sd` at 0xbb58 stores 8 bytes to a0 (arg0 at entry) +0x268.
  The `sd` at 0xbb5c stores 8 bytes to [a0+200] +0x10.
  The `sb` at 0xbd0c stores 1 byte to a0 (arg0 at entry) +0x6e.
  The `jalr` at 0xb954 calls mvpavio_preset_genlock with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0xb978 calls splhi with a0=?, a1=?, a2=?, a3=?.
  The `jalr` at 0xb9d8 calls mvpavio_select_input with a0=a0 at entry (arg0), a1=[a0+97]:1, a2=?, a3=?.
  The `jalr` at 0xb9f0 calls mvpavio_change_timing with a0=a0 at entry (arg0), a1=[a0+97]:1, a2=[(a0 + ([a0+97]:1 << 0x2))+116]:1, a3=?.
  Calls (unknown callee) via register with a0=?, a1=?, a2=?, a3=?, a6=0x800000 (`jr` at 0xba48).
  The `jalr` at 0xba70 calls mvpavio_preset_output with a0=-0x7, a1=-0x19, a2=?, a3=?.
  The `jalr` at 0xbb70 calls splx with a0=ret(splhi), a1=0xffffffffff87ffff, a2=?, a3=0x1.
  The `jalr` at 0xbb80 calls mvpavio_change_timing with a0=a0 at entry (arg0), a1=0xa, a2=[a0+156]:1, a3=?.
  The `jalr` at 0xbba8 calls mvpavio_select_genlock with a0=a0 at entry (arg0), a1=?, a2=one of 0x0, 0x1, a3=?.
  The `jalr` at 0xbbc8 calls mvpavio_select_output with a0=a0 at entry (arg0), a1=one of -0x1, 0x1, 0x2, a2=-0x1, a3=sym(mvpavio_select_output).
  The `jalr` at 0xbbf4 calls .text+47332 with a0=a0 at entry (arg0), a1=?, a2=?, a3=?, a4=sym(mvpreg_cdto_wait).
  The `jalr` at 0xbc18 calls mvpavio_select_genlock with a0=a0 at entry (arg0), a1=?, a2=0x2, a3=sym(mvpavio_select_genlock).
  The `jalr` at 0xbc8c calls splx with a0=ret(splhi), a1=?, a2=?, a3=?.
  The `beq` branch at 0xb944 targets 0xb964, is taken when a2 == 0, and falls through when a2 != 0.
  The `beq` branch at 0xb95c targets 0xb968 and is always taken.
  The `beq` branch at 0xb9b4 targets 0xba50, is taken when s7(=a1) == 0, and falls through when s7(=a1) != 0.
  The `beq` branch at 0xba20 targets 0xbd10, is taken when a7(?) == t0(=0x1), and falls through when a7(?) != t0(=0x1).
  The `beq` branch at 0xba3c targets 0xbc3c, is taken when s3(=[a0+97]:1) >= 0x8 (unsigned), and falls through when s3(=[a0+97]:1) < 0x8 (unsigned).
  The `beq` branch at 0xba60 targets 0xba9c, is taken when s4(=a2) == 0, and falls through when s4(=a2) != 0.
  The `beq` branch at 0xba7c targets 0xbd18, is taken when v0(=ret(mvpavio_preset_output)) == t9(=0x1), and falls through when v0(=ret(mvpavio_preset_output)) != t9(=0x1).
  The `beq` branch at 0xba84 targets 0xbd3c, is taken when v0(=ret(mvpavio_preset_output)) == 0, and falls through when v0(=ret(mvpavio_preset_output)) != 0.
  The `beq` branch at 0xba8c targets 0xbd5c, is taken when v0(=ret(mvpavio_preset_output)) == a0(=0x2), and falls through when v0(=ret(mvpavio_preset_output)) != a0(=0x2).
  The `beq` branch at 0xba9c targets 0xbc74, is taken when s7(=a1) == 0, and falls through when s7(=a1) != 0.
  The `beq` branch at 0xbacc targets 0xbc9c, is taken when a2(?) == a3(=0x1), and falls through when a2(?) != a3(=0x1).
  The `beq` branch at 0xbae0 targets 0xbb14, is taken when s4(=a2) == 0, and falls through when s4(=a2) != 0.
  The `beq` branch at 0xbb28 targets 0xbb38, is taken when t9(=[a0+600]:8) == 0, and falls through when t9(=[a0+600]:8) != 0.
  The `beq` branch at 0xbb3c targets 0xbb4c, is taken when t9(=[a0+688]:8) == s2(?), and falls through when t9(=[a0+688]:8) != s2(?).
  The `beq` branch at 0xbb50 targets 0xbb64, is taken when ra(=[a0+616]:8) == s0(?), and falls through when ra(=[a0+616]:8) != s0(?).
  The `beq` branch at 0xbb90 targets 0xbcac, is taken when (t8(?) & 0xf) == 0, and falls through when (t8(?) & 0xf) != 0.
  The `beq` branch at 0xbbb4 targets 0xbbd4, is taken when s3(=one of -0x1, 0x1, 0x2) == a2(=-0x1), and falls through when s3(=one of -0x1, 0x1, 0x2) != a2(=-0x1).
  The `beq` branch at 0xbbfc targets 0xbc24, is taken when v0(=ret(.text+47332)) == 0, and falls through when v0(=ret(.text+47332)) != 0.
  The `beq` branch at 0xbc40 targets 0xbd00, is taken when s6(?) == t8(=-0x1), and falls through when s6(?) != t8(=-0x1).
  The `beq` branch at 0xbc6c targets 0xba60 and is always taken.
  The `bne` branch at 0xbc74 targets 0xbaa4, is taken when s4(=a2) != 0, and falls through when s4(=a2) == 0.
  The `beq` branch at 0xbc80 targets 0xbbb0, is taken when s8(=ret(splhi)) == s2(=-0x1), and falls through when s8(=ret(splhi)) != s2(=-0x1).
  The `beq` branch at 0xbc94 targets 0xbbb4 and is always taken.
  The `beq` branch at 0xbca4 targets 0xbae0 and is always taken.
  The `bne` branch at 0xbcb8 targets 0xbb94, is taken when (t8(?) & 0xf) != 0, and falls through when (t8(?) & 0xf) == 0.
  The `bltz` branch at 0xbcc0 targets 0xbb98, is taken when v0(?) < 0 (signed), and falls through when v0(?) >= 0 (signed).
  The `bltz` branch at 0xbcc8 targets 0xbb94, is taken when a0(?) < 0 (signed), and falls through when a0(?) >= 0 (signed).
  The `bne` branch at 0xbcd4 targets 0xbb98, is taken when (t9(?) & 0x3) != 0, and falls through when (t9(?) & 0x3) == 0.
  The `beq` branch at 0xbcdc targets 0xbb98 and is always taken.
  The `beq` branch at 0xbd08 targets 0xbc58 and is always taken.
  The `beq` branch at 0xbd10 targets 0xba2c and is always taken.
  The `beq` branch at 0xbd34 targets 0xba94 and is always taken.
  The `beq` branch at 0xbd54 targets 0xba94 and is always taken.
  The `beq` branch at 0xbd74 targets 0xba94 and is always taken.
  The return at 0xbc2c has v0 = one of ret(.text+47332), ret(mvpavio_select_genlock).
  The instructions from 0xbc34 to 0xbc38 are not reached by any path from the entry, and their branches are not listed.
  The instructions from 0xbce4 to 0xbcfc are not reached by any path from the entry, and their branches are not listed.
  The instructions from 0xbd7c to 0xbdac are not reached by any path from the entry, and their branches are not listed.
  The indirect jump at 0xba48 uses a jump table whose successors are unresolved.

- `mvpreg_init` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0xbdb0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0xbdb0-0xbe6c (188 bytes).
  It occupies 188 bytes.
  The `sw` at 0xbdb4 stores 4 bytes to a0 (arg0 at entry) +0xc0.
  The `sw` at 0xbdbc stores 4 bytes to a0 (arg0 at entry) +0xc4.
  The `sw` at 0xbdc4 stores 4 bytes to a0 (arg0 at entry) +0xc8.
  The `sw` at 0xbdcc stores 4 bytes to a0 (arg0 at entry) +0xcc.
  The `sw` at 0xbdd8 stores 4 bytes to a0 (arg0 at entry) +0xd0.
  The `lbu` at 0xbe2c loads 1 byte from a0 (arg0 at entry) +0x62.
  The `jalr` at 0xbdec calls mvpavio_preset_status with a0=a0 at entry (arg0), a1=0xffffffffbf180000, a2=0xffffffffbf100000, a3=a3 at entry (arg3).
  The `jalr` at 0xbe14 calls mvpreg_setpassthru with a0=a0 at entry (arg0), a1=0x1, a2=0x1, a3=?, a4=sym(mvpreg_setpassthru).
  The `jalr` at 0xbe4c calls .text+46760 with a0=a0 at entry (arg0), a1=?, a2=[a0+98]:1, a3=0x0, a6=sym(mvpreg_initmace).
  The `beq` branch at 0xbdf8 targets 0xbe2c, is taken when v0(=ret(mvpavio_preset_status)) == a3(=-0x1), and falls through when v0(=ret(mvpavio_preset_status)) != a3(=-0x1).
  The `bne` branch at 0xbe5c targets 0xbe3c, is taken when s0(?) < 0x4 (signed), and falls through when s0(?) >= 0x4 (signed).
  The `beq` branch at 0xbe64 targets 0xbe04 and is always taken.
  The return at 0xbe24 has v0 = ret(mvpreg_setpassthru).

- `mvpreg_unload` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0xbe6c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0xbe6c-0xbe74 (8 bytes).
  It occupies 8 bytes.
  The return at 0xbe6c has v0 = ?.

- `mvpreg_syncpath_controls` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0xbe74 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0xbe74-0xc564 (1776 bytes).
  It occupies 1776 bytes.
  The `lbu` at 0xbe74 loads 1 byte from a0 (arg0 at entry) +0x46c.
  2 such `lw` accesses load 4 bytes from sym(mvpcontroller_table) +0x0, including `lw` at 0xbe98, `lw` at 0xbed0.
  The `lbu` at 0xbeb4 loads 1 byte from a0 (arg0 at entry) +0x4a8.
  5 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0xbe8, including `ld` at 0xbedc, `ld` at 0xc104, `ld` at 0xc1ec.
  2 such `ld` accesses load 8 bytes from [sym(mvpcontroller_table)] +0x268, including `ld` at 0xbee4, `ld` at 0xc028.
  2 such `lw` accesses load 4 bytes from [sym(mvpcontroller_table)] +0xc8, including `lw` at 0xbefc, `lw` at 0xc098.
  The `lbu` at 0xbf2c loads 1 byte from [sym(mvpcontroller_table)] +0x69.
  3 such `lbu` accesses load 1 byte from [sym(mvpcontroller_table)] +0x66, including `lbu` at 0xbf40, `lbu` at 0xc3a4, `lbu` at 0xc3cc.
  The `lbu` at 0xbf5c loads 1 byte from [sym(mvpcontroller_table)] +0x6a.
  The `ld` at 0xbf64 loads 8 bytes from [sym(mvpcontroller_table)] +0x280.
  The `lbu` at 0xbf78 loads 1 byte from [sym(mvpcontroller_table)] +0x6b.
  4 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0xbf0, including `ld` at 0xbf7c, `ld` at 0xbfa0, `ld` at 0xc118.
  The `sd` at 0xbf9c stores 8 bytes to [sym(mvpcontroller_table)] +0x280.
  The `sd` at 0xbfa4 stores 8 bytes to [[sym(mvpcontroller_table)]+200] +0x28.
  2 such `ld` accesses load 8 bytes from [sym(mvpcontroller_table)] +0x288, including `ld` at 0xbfb0, `ld` at 0xc2e8.
  11 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0xbf8, including `ld` at 0xbfb4, `ld` at 0xbfc4, `ld` at 0xbff4.
  The `sd` at 0xbfc0 stores 8 bytes to [sym(mvpcontroller_table)] +0x288.
  The `sd` at 0xbfc8 stores 8 bytes to [[sym(mvpcontroller_table)]+200] +0x30.
  2 such `ld` accesses load 8 bytes from [sym(mvpcontroller_table)] +0x290, including `ld` at 0xbfcc, `ld` at 0xc304.
  6 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0xc00, including `ld` at 0xbfd0, `ld` at 0xbfe0, `ld` at 0xc0c4.
  The `sd` at 0xbfdc stores 8 bytes to [sym(mvpcontroller_table)] +0x290.
  The `sd` at 0xbfe4 stores 8 bytes to [[sym(mvpcontroller_table)]+200] +0x38.
  2 such `ld` accesses load 8 bytes from [sym(mvpcontroller_table)] +0x298, including `ld` at 0xbff0, `ld` at 0xc2f8.
  The `sd` at 0xc000 stores 8 bytes to [sym(mvpcontroller_table)] +0x298.
  The `sd` at 0xc008 stores 8 bytes to [[sym(mvpcontroller_table)]+200] +0x40.
  2 such `ld` accesses load 8 bytes from [sym(mvpcontroller_table)] +0x2a0, including `ld` at 0xc00c, `ld` at 0xc314.
  6 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0xc08, including `ld` at 0xc010, `ld` at 0xc020, `ld` at 0xc0ec.
  The `sd` at 0xc01c stores 8 bytes to [sym(mvpcontroller_table)] +0x2a0.
  The `sd` at 0xc024 stores 8 bytes to [[sym(mvpcontroller_table)]+200] +0x48.
  2 such `sd` accesses store 8 bytes to [sym(mvpcontroller_table)] +0x268, including `sd` at 0xc034, `sd` at 0xc418.
  2 such `sd` accesses store 8 bytes to [[sym(mvpcontroller_table)]+200] +0x10, including `sd` at 0xc038, `sd` at 0xc41c.
  The `lbu` at 0xc08c loads 1 byte from a0 (arg0 at entry) +0xbe3.
  The `lw` at 0xc0a4 loads 4 bytes from ([sym(mvpcontroller_table)] + ([a0+1132]:1 << 0x2)) +0xc0.
  14 such `ld` accesses load 8 bytes from ?, including `ld` at 0xc0b0, `ld` at 0xc0c0, `ld` at 0xc0d8.
  10 such `sd` accesses store 8 bytes to ?, including `sd` at 0xc124, `sd` at 0xc148, `sd` at 0xc164.
  The `sd` at 0xc12c stores 8 bytes to [([sym(mvpcontroller_table)] + ([a0+1132]:1 << 0x2))+192] +0x28.
  The `sd` at 0xc150 stores 8 bytes to [([sym(mvpcontroller_table)] + ([a0+1132]:1 << 0x2))+192] +0x30.
  The `sd` at 0xc16c stores 8 bytes to [([sym(mvpcontroller_table)] + ([a0+1132]:1 << 0x2))+192] +0x38.
  4 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0xc10, including `ld` at 0xc174, `ld` at 0xc184, `ld` at 0xc1d0.
  The `sd` at 0xc188 stores 8 bytes to [([sym(mvpcontroller_table)] + ([a0+1132]:1 << 0x2))+192] +0x40.
  The `sd` at 0xc1ac stores 8 bytes to [([sym(mvpcontroller_table)] + ([a0+1132]:1 << 0x2))+192] +0x48.
  The `sd` at 0xc1c8 stores 8 bytes to [([sym(mvpcontroller_table)] + ([a0+1132]:1 << 0x2))+192] +0x50.
  The `sd` at 0xc1e4 stores 8 bytes to [([sym(mvpcontroller_table)] + ([a0+1132]:1 << 0x2))+192] +0x58.
  2 such `sd` accesses store 8 bytes to [([sym(mvpcontroller_table)] + ([a0+1132]:1 << 0x2))+192] +0x10, including `sd` at 0xc200, `sd` at 0xc4ac.
  2 such `ld` accesses load 8 bytes from [sym(mvpcontroller_table)] +0x2b0, including `ld` at 0xc210, `ld` at 0xc448.
  The `sd` at 0xc21c stores 8 bytes to [sym(mvpcontroller_table)] +0x2b0.
  The `sd` at 0xc220 stores 8 bytes to [[sym(mvpcontroller_table)]+200] +0x58.
  The `sd` at 0xc234 stores 8 bytes to [([sym(mvpcontroller_table)] + ([a0+1132]:1 << 0x2))+192] +0x20.
  2 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0xbb0, including `lbu` at 0xc260, `lbu` at 0xc374.
  The `lw` at 0xc280 loads 4 bytes from a0 (arg0 at entry) +0xbf0.
  The `lw` at 0xc284 loads 4 bytes from [sym(mvpcontroller_table)] +0x320.
  The `lw` at 0xc2a0 loads 4 bytes from [sym(mvpcontroller_table)] +0xcc.
  The `sw` at 0xc2a4 stores 4 bytes to [sym(mvpcontroller_table)] +0x320.
  The `sw` at 0xc2a8 stores 4 bytes to [[sym(mvpcontroller_table)]+204] +0x8.
  The `lw` at 0xc2ac loads 4 bytes from [sym(mvpcontroller_table)] +0x318.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0xbe8, including `lw` at 0xc2b0, `lw` at 0xc2c0.
  The `sw` at 0xc2bc stores 4 bytes to [sym(mvpcontroller_table)] +0x318.
  The `sw` at 0xc2c4 stores 4 bytes to [[sym(mvpcontroller_table)]+204] +0x0.
  The `lw` at 0xc2c8 loads 4 bytes from [sym(mvpcontroller_table)] +0x31c.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0xbec, including `lw` at 0xc2cc, `lw` at 0xc2dc.
  The `sw` at 0xc2d8 stores 4 bytes to [sym(mvpcontroller_table)] +0x31c.
  The `sw` at 0xc2e4 stores 4 bytes to [[sym(mvpcontroller_table)]+204] +0x4.
  The `ld` at 0xc338 loads 8 bytes from [sym(mvpcontroller_table)] +0x278.
  The `sd` at 0xc344 stores 8 bytes to [sym(mvpcontroller_table)] +0x278.
  The `sd` at 0xc348 stores 8 bytes to [[sym(mvpcontroller_table)]+200] +0x20.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x460, including `lw` at 0xc3b0, `lw` at 0xc3d8.
  The `lbu` at 0xc444 loads 1 byte from a0 (arg0 at entry) +0xbe5.
  2 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0xbe4, including `lbu` at 0xc51c, `lbu` at 0xc540.
  The `jalr` at 0xbeac calls splhi with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0xc054 calls splx with a0=ret(splhi), a1=-0x1, a2=sym(splx), a3=?.
  The `jalr` at 0xc240 calls splx with a0=ret(splhi), a1=-0x1, a2=?, a3=?, a4=[sym(mvpcontroller_table)]+600, a6=[[sym(mvpcontroller_table)]+200].
  The `jalr` at 0xc254 calls mvpavio_select_input with a0=[sym(mvpcontroller_table)], a1=[a0+3043]:1, a2=?, a3=?.
  The `jalr` at 0xc270 calls mvpavio_change_timing with a0=[sym(mvpcontroller_table)], a1=[a0+3043]:1, a2=?, a3=sym(mvpavio_change_timing).
  The `jalr` at 0xc354 calls splx with a0=ret(splhi), a1=-0x1, a2=?, a3=[[sym(mvpcontroller_table)]+640]:8, a4=[sym(mvpcontroller_table)]+600, a6=[[sym(mvpcontroller_table)]+200].
  The `jalr` at 0xc368 calls mvpavio_select_output with a0=[sym(mvpcontroller_table)], a1=0x1, a2=?, a3=?.
  The `jalr` at 0xc384 calls mvpavio_change_timing with a0=[sym(mvpcontroller_table)], a1=0xa, a2=?, a3=sym(mvpavio_change_timing).
  The `jalr` at 0xc3ac calls mvpavio_select_genlock with a0=[a0+1120], a1=[[sym(mvpcontroller_table)]+102]:1, a2=?, a3=?.
  The `jalr` at 0xc3bc calls .text+47332 with a0=[sym(mvpcontroller_table)], a1=?, a2=?, a3=?.
  The `jalr` at 0xc3d4 calls mvpavio_select_genlock with a0=[a0+1120], a1=[[sym(mvpcontroller_table)]+102]:1, a2=0x2, a3=?.
  The `beq` branch at 0xbecc targets 0xc080, is taken when t9(=0x1) == a0(=[a0+1192]:1), and falls through when t9(=0x1) != a0(=[a0+1192]:1).
  The `beq` branch at 0xbed4 targets 0xc280, is taken when t1(=0x2) == a0(=[a0+1192]:1), and falls through when t1(=0x2) != a0(=[a0+1192]:1).
  The `bltz` branch at 0xbf00 targets 0xbf14, is taken when t3(?) < 0 (signed), and falls through when t3(?) >= 0 (signed).
  The `beq` branch at 0xbf10 targets 0xc42c, is taken when (ra(?) & 0x7) == 0, and falls through when (ra(?) & 0x7) != 0.
  The `beq` branch at 0xbf18 targets 0xc2e8, is taken when s1(=a1) == t1(=0x2), and falls through when s1(=a1) != t1(=0x2).
  The `bltz` branch at 0xbf24 targets 0xc3e4, is taken when at(=([a0+3048]:8 << 0x1f)) < 0 (signed), and falls through when at(=([a0+3048]:8 << 0x1f)) >= 0 (signed).
  The `beq` branch at 0xbf94 targets 0xbfa8, is taken when a3(=[[sym(mvpcontroller_table)]+640]:8) == a0(=[a0+3056]:8), and falls through when a3(=[[sym(mvpcontroller_table)]+640]:8) != a0(=[a0+3056]:8).
  The `beq` branch at 0xbfa8 targets 0xbfe8, is taken when s1(=a1) == t9(=0x1), and falls through when s1(=a1) != t9(=0x1).
  The `beq` branch at 0xbfb8 targets 0xbfcc, is taken when t0(=[[sym(mvpcontroller_table)]+648]:8) == a7(=[a0+3064]:8), and falls through when t0(=[[sym(mvpcontroller_table)]+648]:8) != a7(=[a0+3064]:8).
  The `beq` branch at 0xbfd4 targets 0xbfe8, is taken when t3(=[[sym(mvpcontroller_table)]+656]:8) == a0(=[a0+3072]:8), and falls through when t3(=[[sym(mvpcontroller_table)]+656]:8) != a0(=[a0+3072]:8).
  The `blez` branch at 0xbfe8 targets 0xc028, is taken when s1(=a1) <= 0 (signed), and falls through when s1(=a1) > 0 (signed).
  The `beq` branch at 0xbff8 targets 0xc00c, is taken when t9(=[[sym(mvpcontroller_table)]+664]:8) == a7(=[a0+3064]:8), and falls through when t9(=[[sym(mvpcontroller_table)]+664]:8) != a7(=[a0+3064]:8).
  The `beq` branch at 0xc014 targets 0xc028, is taken when at(=[[sym(mvpcontroller_table)]+672]:8) == a0(=[a0+3080]:8), and falls through when at(=[[sym(mvpcontroller_table)]+672]:8) != a0(=[a0+3080]:8).
  The `beq` branch at 0xc02c targets 0xc03c, is taken when a0(=[[sym(mvpcontroller_table)]+616]:8) == a1(?), and falls through when a0(=[[sym(mvpcontroller_table)]+616]:8) != a1(?).
  The `beq` branch at 0xc03c targets 0xc338, is taken when s1(=a1) == t1(=0x2), and falls through when s1(=a1) != t1(=0x2).
  The `beq` branch at 0xc044 targets 0xc060, is taken when v0(=ret(splhi)) == a1(=-0x1), and falls through when v0(=ret(splhi)) != a1(=-0x1).
  The `beq` branch at 0xc0a8 targets 0xc43c, is taken when s1(=a1) == t9(=0x1), and falls through when s1(=a1) != t9(=0x1).
  The `bne` branch at 0xc0b8 targets 0xc0d0, is taken when a1(?) != a2(=[a0+3064]:8), and falls through when a1(?) == a2(=[a0+3064]:8).
  The `beq` branch at 0xc0c8 targets 0xc434, is taken when a3(?) == t2(=[a0+3072]:8), and falls through when a3(?) != t2(=[a0+3072]:8).
  The `blez` branch at 0xc0d0 targets 0xc0fc, is taken when s1(=a1) <= 0 (signed), and falls through when s1(=a1) > 0 (signed).
  The `bne` branch at 0xc0e0 targets 0xc0f8, is taken when t3(?) != t8(=[a0+3064]:8), and falls through when t3(?) == t8(=[a0+3064]:8).
  The `beq` branch at 0xc0f0 targets 0xc0fc, is taken when ra(?) == at(=[a0+3080]:8), and falls through when ra(?) != at(=[a0+3080]:8).
  The `beq` branch at 0xc0fc targets 0xc444, is taken when s1(=a1) == t1(=0x2), and falls through when s1(=a1) != t1(=0x2).
  The `bltz` branch at 0xc10c targets 0xc470, is taken when v1(=([a0+3048]:8 << 0x1f)) < 0 (signed), and falls through when v1(=([a0+3048]:8 << 0x1f)) >= 0 (signed).
  The `beq` branch at 0xc11c targets 0xc130, is taken when a1(?) == a0(=[a0+3056]:8), and falls through when a1(?) != a0(=[a0+3056]:8).
  The `beq` branch at 0xc130 targets 0xc18c, is taken when s1(=a1) == t9(=0x1), and falls through when s1(=a1) != t9(=0x1).
  The `beq` branch at 0xc140 targets 0xc154, is taken when a3(?) == a7(=[a0+3064]:8), and falls through when a3(?) != a7(=[a0+3064]:8).
  The `beq` branch at 0xc15c targets 0xc170, is taken when t3(?) == a0(=[a0+3072]:8), and falls through when t3(?) != a0(=[a0+3072]:8).
  The `beq` branch at 0xc178 targets 0xc18c, is taken when t9(?) == a0(=[a0+3088]:8), and falls through when t9(?) != a0(=[a0+3088]:8).
  The `blez` branch at 0xc18c targets 0xc1e8, is taken when s1(=a1) <= 0 (signed), and falls through when s1(=a1) > 0 (signed).
  The `beq` branch at 0xc19c targets 0xc1b0, is taken when at(?) == a7(=[a0+3064]:8), and falls through when at(?) != a7(=[a0+3064]:8).
  The `beq` branch at 0xc1b8 targets 0xc1cc, is taken when a1(?) == a0(=[a0+3080]:8), and falls through when a1(?) != a0(=[a0+3080]:8).
  The `beq` branch at 0xc1d4 targets 0xc1e8, is taken when a3(?) == a0(=[a0+3088]:8), and falls through when a3(?) != a0(=[a0+3088]:8).
  The `beq` branch at 0xc1f0 targets 0xc204, is taken when t2(?) == a0(=[a0+3048]:8), and falls through when t2(?) != a0(=[a0+3048]:8).
  The `bne` branch at 0xc204 targets 0xc044, is taken when s1(=a1) != t1(=0x2), and falls through when s1(=a1) == t1(=0x2).
  The `beq` branch at 0xc214 targets 0xc224, is taken when t8(=[[sym(mvpcontroller_table)]+688]:8) == t3(?), and falls through when t8(=[[sym(mvpcontroller_table)]+688]:8) != t3(?).
  The `beq` branch at 0xc228 targets 0xc23c, is taken when t9(?) == 0, and falls through when t9(?) != 0.
  The `beq` branch at 0xc278 targets 0xc060 and is always taken.
  The `beq` branch at 0xc29c targets 0xc2ac, is taken when a5(=[[sym(mvpcontroller_table)]+800]) == a4(?), and falls through when a5(=[[sym(mvpcontroller_table)]+800]) != a4(?).
  The `beq` branch at 0xc2b4 targets 0xc2c8, is taken when a7(=[[sym(mvpcontroller_table)]+792]) == a4(=[a0+3048]), and falls through when a7(=[[sym(mvpcontroller_table)]+792]) != a4(=[a0+3048]).
  The `beq` branch at 0xc2d0 targets 0xc040, is taken when t1(=[[sym(mvpcontroller_table)]+796]) == a4(=[a0+3052]), and falls through when t1(=[[sym(mvpcontroller_table)]+796]) != a4(=[a0+3052]).
  The `beq` branch at 0xc2e0 targets 0xc040 and is always taken.
  The `bne` branch at 0xc2f0 targets 0xc324, is taken when ra(=[[sym(mvpcontroller_table)]+648]:8) != a5(=[a0+3064]:8), and falls through when ra(=[[sym(mvpcontroller_table)]+648]:8) == a5(=[a0+3064]:8).
  The `bne` branch at 0xc2fc targets 0xc324, is taken when at(=[[sym(mvpcontroller_table)]+664]:8) != a5(=[a0+3064]:8), and falls through when at(=[[sym(mvpcontroller_table)]+664]:8) == a5(=[a0+3064]:8).
  The `bne` branch at 0xc30c targets 0xc324, is taken when v1(=[[sym(mvpcontroller_table)]+656]:8) != a2(=[a0+3072]:8), and falls through when v1(=[[sym(mvpcontroller_table)]+656]:8) == a2(=[a0+3072]:8).
  The `beq` branch at 0xc31c targets 0xbf24, is taken when a3(=[[sym(mvpcontroller_table)]+672]:8) == a5(=[a0+3080]:8), and falls through when a3(=[[sym(mvpcontroller_table)]+672]:8) != a5(=[a0+3080]:8).
  The `bgez` branch at 0xc328 targets 0xbf2c, is taken when t3(=([a0+3048]:8 << 0x1f)) >= 0 (signed), and falls through when t3(=([a0+3048]:8 << 0x1f)) < 0 (signed).
  The `beq` branch at 0xc330 targets 0xc3f0 and is always taken.
  The `beq` branch at 0xc33c targets 0xc350, is taken when t8(=[[sym(mvpcontroller_table)]+632]:8) == 0, and falls through when t8(=[[sym(mvpcontroller_table)]+632]:8) != 0.
  The `beq` branch at 0xc394 targets 0xc4b0, is taken when (a4(?) & 0xf) == 0, and falls through when (a4(?) & 0xf) != 0.
  The `beq` branch at 0xc3c4 targets 0xc060, is taken when v0(=ret(.text+47332)) == 0, and falls through when v0(=ret(.text+47332)) != 0.
  The `beq` branch at 0xc3dc targets 0xc060 and is always taken.
  The `bne` branch at 0xc3e4 targets 0xbf2c, is taken when s1(=a1) != t1(=0x2), and falls through when s1(=a1) == t1(=0x2).
  The `beq` branch at 0xc3ec targets 0xc424, is taken when t3(?) == 0, and falls through when t3(?) != 0.
  The `beq` branch at 0xc3f8 targets 0xc4ec, is taken when (ra(?) & 0xf) == 0, and falls through when (ra(?) & 0xf) != 0.
  The `beq` branch at 0xc410 targets 0xc424, is taken when t2(=[[sym(mvpcontroller_table)]+616]:8) == a5(?), and falls through when t2(=[[sym(mvpcontroller_table)]+616]:8) != a5(?).
  The `beq` branch at 0xc424 targets 0xbf2c and is always taken.
  The `beq` branch at 0xc42c targets 0xbf18 and is always taken.
  The `beq` branch at 0xc434 targets 0xc0d0 and is always taken.
  The `beq` branch at 0xc43c targets 0xc0d0 and is always taken.
  The `beq` branch at 0xc44c targets 0xc540, is taken when a1(=[a0+3045]:1) == 0, and falls through when a1(=[a0+3045]:1) != 0.
  The `beq` branch at 0xc454 targets 0xc51c, is taken when t9(=0x1) == a1(=[a0+3045]:1), and falls through when t9(=0x1) != a1(=[a0+3045]:1).
  The `beq` branch at 0xc460 targets 0xc104, is taken when t8(=[[sym(mvpcontroller_table)]+688]:8) == t3(?), and falls through when t8(=[[sym(mvpcontroller_table)]+688]:8) != t3(?).
  The `beq` branch at 0xc468 targets 0xc104 and is always taken.
  The `beq` branch at 0xc470 targets 0xc114, is taken when t2(=one of 0x0, 0x1) == 0, and falls through when t2(=one of 0x0, 0x1) != 0.
  The `bne` branch at 0xc478 targets 0xc114, is taken when s1(=a1) != t1(=0x2), and falls through when s1(=a1) == t1(=0x2).
  The `beq` branch at 0xc49c targets 0xc114, is taken when t2(?) == a7(?), and falls through when t2(?) != a7(?).
  The `beq` branch at 0xc4a8 targets 0xc114 and is always taken.
  The `bne` branch at 0xc4b8 targets 0xc39c, is taken when (t8(?) & 0xf) != 0, and falls through when (t8(?) & 0xf) == 0.
  The `bltz` branch at 0xc4c4 targets 0xc39c, is taken when t9(?) < 0 (signed), and falls through when t9(?) >= 0 (signed).
  The `bltz` branch at 0xc4d0 targets 0xc398, is taken when ra(?) < 0 (signed), and falls through when ra(?) >= 0 (signed).
  The `bne` branch at 0xc4dc targets 0xc39c, is taken when (at(?) & 0x3) != 0, and falls through when (at(?) & 0x3) == 0.
  The `beq` branch at 0xc4e4 targets 0xc39c and is always taken.
  The `bne` branch at 0xc4f0 targets 0xc400, is taken when (v1(?) & 0xf) != 0, and falls through when (v1(?) & 0xf) == 0.
  The `bltz` branch at 0xc4f8 targets 0xc400, is taken when a2(?) < 0 (signed), and falls through when a2(?) >= 0 (signed).
  The `bltz` branch at 0xc500 targets 0xc400, is taken when a3(?) < 0 (signed), and falls through when a3(?) >= 0 (signed).
  The `bne` branch at 0xc50c targets 0xc400, is taken when (a5(?) & 0x3) != 0, and falls through when (a5(?) & 0x3) == 0.
  The `beq` branch at 0xc514 targets 0xc40c and is always taken.
  The `beq` branch at 0xc538 targets 0xc460 and is always taken.
  The `beq` branch at 0xc55c targets 0xc460 and is always taken.
  The return at 0xc078 has v0 = 0x0.

- `mvpreg_gettiming` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0xc564 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0xc564-0xc5f4 (144 bytes).
  It occupies 144 bytes.
  2 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x3, including `lbu` at 0xc594, `lbu` at 0xc5b0.
  The `lbu` at 0xc5d0 loads 1 byte from a0 (arg0 at entry) +0x44.
  The `lbu` at 0xc5d8 loads 1 byte from a0 (arg0 at entry) +0x30.
  The `lbu` at 0xc5e0 loads 1 byte from a0 (arg0 at entry) +0x34.
  The `lbu` at 0xc5e8 loads 1 byte from a0 (arg0 at entry) +0x24.
  The `lbu` at 0xc5f0 loads 1 byte from a0 (arg0 at entry) +0x2c.
  The `beq` branch at 0xc574 targets 0xc594, is taken when a1 == a6(=0x2), and falls through when a1 != a6(=0x2).
  The `beq` branch at 0xc57c targets 0xc5b0, is taken when a1 == v0(=0x3), and falls through when a1 != v0(=0x3).
  The `beq` branch at 0xc584 targets 0xc5cc, is taken when a1 == 0, and falls through when a1 != 0.
  The `beq` branch at 0xc598 targets 0xc5e4, is taken when v0(=[a0+3]:1) == a4(=0x1), and falls through when v0(=[a0+3]:1) != a4(=0x1).
  The `beq` branch at 0xc5a0 targets 0xc5d4, is taken when a6(=0x2) == v0(=[a0+3]:1), and falls through when a6(=0x2) != v0(=[a0+3]:1).
  The `beq` branch at 0xc5a8 targets 0xc58c and is always taken.
  The `beq` branch at 0xc5b4 targets 0xc5ec, is taken when v0(=[a0+3]:1) == a5(=0x1), and falls through when v0(=[a0+3]:1) != a5(=0x1).
  The `beq` branch at 0xc5bc targets 0xc5dc, is taken when a6(=0x2) == v0(=[a0+3]:1), and falls through when a6(=0x2) != v0(=[a0+3]:1).
  The `beq` branch at 0xc5c4 targets 0xc58c and is always taken.
  The `beq` branch at 0xc5cc targets 0xc58c and is always taken.
  The `beq` branch at 0xc5d4 targets 0xc58c and is always taken.
  The `beq` branch at 0xc5dc targets 0xc58c and is always taken.
  The `beq` branch at 0xc5e4 targets 0xc58c and is always taken.
  The `beq` branch at 0xc5ec targets 0xc58c and is always taken.
  The return at 0xc58c has v0 = one of ?, [a0+68]:1, [a0+48]:1, [a0+52]:1, [a0+36]:1, [a0+44]:1.

- `mvpreg_syncdevice_controls` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0xc5f4 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0xc5f4-0xc9b4 (960 bytes).
  It occupies 960 bytes.
  4 such `lw` accesses load 4 bytes from sym(mvpcontroller_table) +0x0, including `lw` at 0xc61c, `lw` at 0xc6cc, `lw` at 0xc7a8.
  The `lw` at 0xc638 loads 4 bytes from [sym(mvpcontroller_table)] +0xc8.
  3 such `lbu` accesses load 1 byte from [sym(mvpcontroller_table)] +0x64, including `lbu` at 0xc644, `lbu` at 0xc6b4, `lbu` at 0xc6ec.
  The `lbu` at 0xc648 loads 1 byte from [sym(mvpcontroller_table)] +0x65.
  The `lbu` at 0xc654 loads 1 byte from [sym(mvpcontroller_table)] +0x70.
  3 such `ld` accesses load 8 bytes from [sym(mvpcontroller_table)] +0x2b0, including `ld` at 0xc65c, `ld` at 0xc684, `ld` at 0xc744.
  The `sb` at 0xc680 stores 1 byte to [sym(mvpcontroller_table)] +0x65.
  2 such `lbu` accesses load 1 byte from [sym(mvpcontroller_table)] +0x59, including `lbu` at 0xc68c, `lbu` at 0xc72c.
  2 such `sd` accesses store 8 bytes to [sym(mvpcontroller_table)] +0x2b0, including `sd` at 0xc6ac, `sd` at 0xc75c.
  2 such `sd` accesses store 8 bytes to [[sym(mvpcontroller_table)]+200] +0x58, including `sd` at 0xc6b0, `sd` at 0xc760.
  The `lbu` at 0xc780 loads 1 byte from [sym(mvpcontroller_table)] +0x6a.
  3 such `ld` accesses load 8 bytes from [sym(mvpcontroller_table)] +0x268, including `ld` at 0xc784, `ld` at 0xc824, `ld` at 0xc854.
  The `lbu` at 0xc794 loads 1 byte from [sym(mvpcontroller_table)] +0x6b.
  The `lbu` at 0xc7b4 loads 1 byte from [sym(mvpcontroller_table)] +0x69.
  3 such `lbu` accesses load 1 byte from [sym(mvpcontroller_table)] +0x66, including `lbu` at 0xc7c8, `lbu` at 0xc88c, `lbu` at 0xc8e0.
  2 such `sd` accesses store 8 bytes to [sym(mvpcontroller_table)] +0x268, including `sd` at 0xc84c, `sd` at 0xc864.
  2 such `sd` accesses store 8 bytes to [[sym(mvpcontroller_table)]+200] +0x10, including `sd` at 0xc850, `sd` at 0xc868.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x460, including `lw` at 0xc894, `lw` at 0xc8ec.
  The `lhu` at 0xc898 loads 2 bytes from [sym(mvpcontroller_table)] +0x72.
  The `ld` at 0xc8ac loads 8 bytes from [sym(mvpcontroller_table)] +0x2a8.
  The `sd` at 0xc8b8 stores 8 bytes to [sym(mvpcontroller_table)] +0x2a8.
  The `sd` at 0xc8bc stores 8 bytes to [[sym(mvpcontroller_table)]+200] +0x50.
  The `jalr` at 0xc63c calls splhi with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0xc6d4 calls .text+50532 with a0=[sym(mvpcontroller_table)]+88, a1=[[sym(mvpcontroller_table)]+100]:1, a2=[[sym(mvpcontroller_table)]+688]:8, a3=?.
  The `jalr` at 0xc76c calls splx with a0=ret(splhi), a1=?, a2=?, a3=?.
  The `jalr` at 0xc778 calls splhi with a0=?, a1=?, a2=?, a3=?.
  The `jalr` at 0xc7f0 calls .text+50532 with a0=[sym(mvpcontroller_table)]+88, a1=[[sym(mvpcontroller_table)]+102]:1, a2=?, a3=?.
  The `jalr` at 0xc870 calls splx with a0=ret(splhi), a1=[[sym(mvpcontroller_table)]+616]:8, a2=?, a3=0x1.
  The `jalr` at 0xc890 calls mvpavio_select_genlock with a0=[a0+1120], a1=[[sym(mvpcontroller_table)]+102]:1, a2=one of 0x0, 0x1, a3=?.
  The `jalr` at 0xc8a0 calls splhi with a0=?, a1=?, a2=?, a3=?.
  The `jalr` at 0xc8c0 calls splx with a0=ret(splhi), a1=0x0, a2=?, a3=?.
  The `jalr` at 0xc8d0 calls .text+47332 with a0=[sym(mvpcontroller_table)], a1=?, a2=?, a3=?.
  The `jalr` at 0xc8e8 calls mvpavio_select_genlock with a0=[a0+1120], a1=[[sym(mvpcontroller_table)]+102]:1, a2=0x2, a3=?.
  The `beq` branch at 0xc678 targets 0xc68c, is taken when t8(=[[sym(mvpcontroller_table)]+101]:1) == a1(=[[sym(mvpcontroller_table)]+100]:1), and falls through when t8(=[[sym(mvpcontroller_table)]+101]:1) != a1(=[[sym(mvpcontroller_table)]+100]:1).
  The `beq` branch at 0xc698 targets 0xc6a4, is taken when t8(=[[sym(mvpcontroller_table)]+89]:1) == t9(?), and falls through when t8(=[[sym(mvpcontroller_table)]+89]:1) != t9(?).
  The `beq` branch at 0xc6a4 targets 0xc6b4, is taken when a2(=[[sym(mvpcontroller_table)]+688]:8) == s0(?), and falls through when a2(=[[sym(mvpcontroller_table)]+688]:8) != s0(?).
  The `bne` branch at 0xc6bc targets 0xc6cc, is taken when a1(=[[sym(mvpcontroller_table)]+100]:1) != ra(=0x8), and falls through when a1(=[[sym(mvpcontroller_table)]+100]:1) == ra(=0x8).
  The `beq` branch at 0xc6c4 targets 0xc72c and is always taken.
  The `beq` branch at 0xc718 targets 0xc9a4, is taken when a4(=0x1) == a5(?), and falls through when a4(=0x1) != a5(?).
  The `beq` branch at 0xc754 targets 0xc768, is taken when t8(=[[sym(mvpcontroller_table)]+688]:8) == v0(?), and falls through when t8(=[[sym(mvpcontroller_table)]+688]:8) != v0(?).
  The `beq` branch at 0xc810 targets 0xc924, is taken when a3(=0x1) == a4(?), and falls through when a3(=0x1) != a4(?).
  The `beq` branch at 0xc834 targets 0xc934, is taken when (t8(?) & 0xf) == 0, and falls through when (t8(?) & 0xf) != 0.
  The `beq` branch at 0xc844 targets 0xc85c, is taken when a1(=[[sym(mvpcontroller_table)]+616]:8) == s0(?), and falls through when a1(=[[sym(mvpcontroller_table)]+616]:8) != s0(?).
  The `beq` branch at 0xc85c targets 0xc870, is taken when a1(=[[sym(mvpcontroller_table)]+616]:8) == a2(?), and falls through when a1(=[[sym(mvpcontroller_table)]+616]:8) != a2(?).
  The `beq` branch at 0xc878 targets 0xc96c, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0xc8b0 targets 0xc8c0, is taken when t9(=[[sym(mvpcontroller_table)]+680]:8) == a1(=0x0), and falls through when t9(=[[sym(mvpcontroller_table)]+680]:8) != a1(=0x0).
  The `beq` branch at 0xc8d8 targets 0xc8f4, is taken when v0(=ret(.text+47332)) == 0, and falls through when v0(=ret(.text+47332)) != 0.
  The `beq` branch at 0xc92c targets 0xc824 and is always taken.
  The `bne` branch at 0xc940 targets 0xc83c, is taken when (t8(?) & 0xf) != 0, and falls through when (t8(?) & 0xf) == 0.
  The `bltz` branch at 0xc948 targets 0xc840, is taken when a2(?) < 0 (signed), and falls through when a2(?) >= 0 (signed).
  The `bltz` branch at 0xc950 targets 0xc83c, is taken when a5(?) < 0 (signed), and falls through when a5(?) >= 0 (signed).
  The `bne` branch at 0xc95c targets 0xc840, is taken when (t9(?) & 0x3) != 0, and falls through when (t9(?) & 0x3) == 0.
  The `beq` branch at 0xc964 targets 0xc85c and is always taken.
  The `bne` branch at 0xc974 targets 0xc880, is taken when (ra(?) & 0xf) != 0, and falls through when (ra(?) & 0xf) == 0.
  The `bltz` branch at 0xc97c targets 0xc884, is taken when v0(?) < 0 (signed), and falls through when v0(?) >= 0 (signed).
  The `bltz` branch at 0xc984 targets 0xc884, is taken when a0(?) < 0 (signed), and falls through when a0(?) >= 0 (signed).
  The `bne` branch at 0xc994 targets 0xc884, is taken when (at(?) & 0x3) != 0, and falls through when (at(?) & 0x3) == 0.
  The `beq` branch at 0xc99c targets 0xc884 and is always taken.
  The `beq` branch at 0xc9ac targets 0xc72c and is always taken.
  The return at 0xc91c has v0 = 0x0.

- `mvp_pio_read64` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0xc9b4 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0xc9b4-0xca34 (128 bytes).
  It occupies 128 bytes.
  The `lw` at 0xc9ec loads 4 bytes from sym(mvp_umba) +0xb28.
  The `ld` at 0xc9fc loads 8 bytes from a0 (arg0 at entry) +0x0.
  The `lw` at 0xca08 loads 4 bytes from sym(mvp_umba) +0xb2c.
  The `jalr` at 0xc9cc calls spl7 with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0xc9e8 calls us_delay with a0=[sym(.data)+2856], a1=sym(us_delay), a2=?, a3=?.
  The `jalr` at 0xca04 calls us_delay with a0=[sym(.data)+2860], a1=?, a2=sym(us_delay), a3=?.
  The `jalr` at 0xca18 calls splx with a0=ret(spl7), a1=sym(splx), a2=?, a3=?.
  The return at 0xca2c has v0 = [a0]:8.

- `mvpsystem_ioctl` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0xca34 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0xca34-0xcb90 (348 bytes).
  It occupies 348 bytes.
  The `lbu` at 0xcab0 loads 1 byte from a0 (arg0 at entry) +0x479.
  The `sw` at 0xcad0 stores 4 bytes to sym(mvptransfer_stats) +0x2c.
  The `sw` at 0xcae0 stores 4 bytes to sym(mvptransfer_stats) +0x5c.
  2 such `sw` accesses store 4 bytes to sym(mvptransfer_stats) -0x4, including `sw` at 0xcaf8, `sw` at 0xcb78.
  The `sw` at 0xcb8c stores 4 bytes to a0 (arg0 at entry) +0x604.
  The `jalr` at 0xca5c calls mvpcopyin with a0=a2 at entry (arg2), a1=sp-240, a2=0xc4, a3=a3 at entry (arg3).
  The `jalr` at 0xcb10 calls copyout with a0=sp-240, a1=a2 at entry (arg2), a2=0xc4, a3=?, a4=sym(copyout).
  The `jalr` at 0xcb34 calls bcopy with a0=sym(mvptransfer_stats), a1=sp-236, a2=0xc0, a3=sym(bcopy), a4=0x25b.
  The `jalr` at 0xcb54 calls bzero with a0=sym(mvptransfer_stats), a1=0xc0, a2=?, a3=?, a4=sym(bzero).
  The `bne` branch at 0xca68 targets 0xca9c, is taken when v0(=ret(mvpcopyin)) != 0, and falls through when v0(=ret(mvpcopyin)) == 0.
  The `beq` branch at 0xca7c targets 0xcb20, is taken when v0(?) == v1(=0x259), and falls through when v0(?) != v1(=0x259).
  The `beq` branch at 0xca84 targets 0xcb44, is taken when v0(?) == a0(=0x25a), and falls through when v0(?) != a0(=0x25a).
  The `beq` branch at 0xca8c targets 0xcab0, is taken when v0(?) == a4(=0x25b), and falls through when v0(?) != a4(=0x25b).
  The `beq` branch at 0xcac0 targets 0xcb84, is taken when (v1(=[a0+1145]:1) & 0x1) == 0, and falls through when (v1(=[a0+1145]:1) & 0x1) != 0.
  The `beq` branch at 0xcad4 targets 0xcafc, is taken when a0(?) >= 0x4 (signed), and falls through when a0(?) < 0x4 (signed).
  The `beq` branch at 0xcae4 targets 0xcafc, is taken when a0(?) >= 0x4 (signed), and falls through when a0(?) < 0x4 (signed).
  The `bne` branch at 0xcaf4 targets 0xcac8, is taken when a0(?) < 0x4 (signed), and falls through when a0(?) >= 0x4 (signed).
  The `bne` branch at 0xcafc targets 0xca98, is taken when s1(=ret(mvpcopyin)) != 0, and falls through when s1(=ret(mvpcopyin)) == 0.
  The `beq` branch at 0xcb18 targets 0xca98 and is always taken.
  The `beq` branch at 0xcb3c targets 0xcafc and is always taken.
  The `bne` branch at 0xcb74 targets 0xcb68, is taken when v0(?) < 0x4 (signed), and falls through when v0(?) >= 0x4 (signed).
  The `beq` branch at 0xcb7c targets 0xcafc and is always taken.
  The `beq` branch at 0xcb88 targets 0xcafc and is always taken.
  The return at 0xcaa8 has v0 = one of ret(mvpcopyin), ?.

- `move_mipmap` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0xcb90 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0xcb90-0xce2c (668 bytes).
  It occupies 668 bytes.
  The `lw` at 0xcb9c loads 4 bytes from a1 (arg1 at entry) +0x4.
  The `lw` at 0xcbbc loads 4 bytes from a1 (arg1 at entry) +0x0.
  10 such `lhu` accesses load 2 bytes from ?, including `lhu` at 0xcc04, `lhu` at 0xcc08, `lhu` at 0xcc0c.
  The `lw` at 0xcc1c loads 4 bytes from a0 (arg0 at entry) +0x0.
  The `lw` at 0xcc24 loads 4 bytes from ?.
  12 such `ld` accesses load 8 bytes from ?, including `ld` at 0xcc3c, `ld` at 0xcc44, `ld` at 0xcc58.
  12 such `sd` accesses store 8 bytes to ?, including `sd` at 0xcc40, `sd` at 0xcc50, `sd` at 0xcc60.
  The `lhu` at 0xce28 loads 2 bytes from [a1+4] +0x8.
  The `jalr` at 0xcd68 calls bcopy with a0=?, a1=?, a2=?, a3=?.
  The `jalr` at 0xcda0 calls bcopy with a0=?, a1=?, a2=?, a3=?.
  The `blez` branch at 0xcbdc targets 0xcde0, is taken when a5(=[a1]) <= 0 (signed), and falls through when a5(=[a1]) > 0 (signed).
  The `beq` branch at 0xcbe4 targets 0xce20 and is always taken.
  The `blez` branch at 0xcbfc targets 0xcde0, is taken when a7(?) <= 0 (signed), and falls through when a7(?) > 0 (signed).
  The `blez` branch at 0xcc2c targets 0xcbec, is taken when t9(?) <= 0 (signed), and falls through when t9(?) > 0 (signed).
  The `beq` branch at 0xcc34 targets 0xce14 and is always taken.
  The `beq` branch at 0xcc88 targets 0xcbec, is taken when s4(?) >= a3(?) (signed), and falls through when s4(?) < a3(?) (signed).
  The `beq` branch at 0xcca0 targets 0xcd54, is taken when a2(?) >= 0x21 (signed), and falls through when a2(?) < 0x21 (signed).
  The `beq` branch at 0xcca8 targets 0xcd20, is taken when s7(=0x20) == a2(?), and falls through when s7(=0x20) != a2(?).
  The `beq` branch at 0xccb0 targets 0xcd38, is taken when t0(=0x10) == a2(?), and falls through when t0(=0x10) != a2(?).
  The `beq` branch at 0xccb8 targets 0xcd48, is taken when t1(=0x8) == a2(?), and falls through when t1(=0x8) != a2(?).
  The `beq` branch at 0xccc0 targets 0xcdbc, is taken when t2(=0x4) == a2(?), and falls through when t2(=0x4) != a2(?).
  The `beq` branch at 0xccc8 targets 0xcdc8, is taken when t3(=0x2) == a2(?), and falls through when t3(=0x2) != a2(?).
  The `beq` branch at 0xccd0 targets 0xcc6c, is taken when s8(=a2) == 0, and falls through when s8(=a2) != 0.
  The `beq` branch at 0xccec targets 0xcc3c, is taken when a4(?) == s7(=0x20), and falls through when a4(?) != s7(=0x20).
  The `beq` branch at 0xccf4 targets 0xcc54, is taken when a4(?) == t0(=0x10), and falls through when a4(?) != t0(=0x10).
  The `beq` branch at 0xccfc targets 0xcc64, is taken when a4(?) == t1(=0x8), and falls through when a4(?) != t1(=0x8).
  The `beq` branch at 0xcd04 targets 0xcdd4, is taken when a4(?) == t2(=0x4), and falls through when a4(?) != t2(=0x4).
  The `bne` branch at 0xcd0c targets 0xcc6c, is taken when a4(?) != t3(=0x2), and falls through when a4(?) == t3(=0x2).
  The `beq` branch at 0xcd18 targets 0xcc6c and is always taken.
  The `beq` branch at 0xcd4c targets 0xccd0 and is always taken.
  The `beq` branch at 0xcd7c targets 0xcc6c, is taken when s8(=a2) == 0, and falls through when s8(=a2) != 0.
  The `beq` branch at 0xcdb4 targets 0xcc6c and is always taken.
  The `beq` branch at 0xcdc0 targets 0xccd0 and is always taken.
  The `beq` branch at 0xcdcc targets 0xccd0 and is always taken.
  The `beq` branch at 0xcdd8 targets 0xcc6c and is always taken.
  The `beq` branch at 0xce18 targets 0xcc94 and is always taken.
  The `beq` branch at 0xce24 targets 0xcc08 and is always taken.
  The return at 0xce0c has v0 = 0x0.

- `mvpmipmap_move_mipmap` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0xce2c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0xce2c-0xd0a4 (632 bytes).
  It occupies 632 bytes.
  The `lbu` at 0xce34 loads 1 byte from a0 (arg0 at entry) +0xbe2.
  4 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0xbdf, including `lbu` at 0xce94, `lbu` at 0xcf38, `lbu` at 0xcf9c.
  4 such `lw` accesses load 4 bytes from (a1 + ([a0+3039]:1 << 0x2)) +0x0, including `lw` at 0xceb0, `lw` at 0xcf54, `lw` at 0xcfb8.
  3 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0xbe0, including `lbu` at 0xceb8, `lbu` at 0xcfc0, `lbu` at 0xd044.
  3 such `lw` accesses load 4 bytes from (a1 + ([a0+3040]:1 << 0x2)) +0x0, including `lw` at 0xcecc, `lw` at 0xcfd4, `lw` at 0xd058.
  The `lbu` at 0xced4 loads 1 byte from a0 (arg0 at entry) +0xbe1.
  The `lw` at 0xcee8 loads 4 bytes from (a1 + ([a0+3041]:1 << 0x2)) +0x0.
  The `jalr` at 0xceac calls tile_mapin with a0=[(a1 + ([a0+3039]:1 << 0x2))], a1=0x11, a2=a2 at entry (arg2), a3=a3 at entry (arg3), a4=[a0+3042]:1.
  The `jalr` at 0xcec8 calls tile_mapin with a0=[(a1 + ([a0+3040]:1 << 0x2))], a1=0x11, a2=?, a3=?.
  The `jalr` at 0xcee4 calls tile_mapin with a0=[(a1 + ([a0+3041]:1 << 0x2))], a1=0x11, a2=?, a3=?.
  The `jalr` at 0xcf04 calls .text+52112 with a0=sp-48, a1=sym(.data)+3232, a2=0x0, a3=sym(move_mipmap).
  The `jalr` at 0xcf18 calls tile_mapout with a0=?, a1=?, a2=?, a3=?.
  The `jalr` at 0xcf20 calls tile_mapout with a0=?, a1=?, a2=?, a3=?.
  The `jalr` at 0xcf28 calls tile_mapout with a0=?, a1=?, a2=?, a3=?.
  The `jalr` at 0xcf50 calls tile_mapin with a0=[(a1 + ([a0+3039]:1 << 0x2))], a1=0x11, a2=sym(tile_mapin), a3=a3 at entry (arg3), a4=[a0+3042]:1.
  The `jalr` at 0xcf78 calls .text+52112 with a0=sp-48, a1=sym(.data)+3208, a2=0x1, a3=sym(move_mipmap).
  The `jalr` at 0xcf8c calls tile_mapout with a0=?, a1=?, a2=?, a3=?, a4=sym(tile_mapout).
  The `jalr` at 0xcfb4 calls tile_mapin with a0=[(a1 + ([a0+3039]:1 << 0x2))], a1=0x11, a2=a2 at entry (arg2), a3=a3 at entry (arg3), a4=[a0+3042]:1.
  The `jalr` at 0xcfd0 calls tile_mapin with a0=[(a1 + ([a0+3040]:1 << 0x2))], a1=0x11, a2=?, a3=?.
  The `jalr` at 0xcff4 calls .text+52112 with a0=sp-48, a1=sym(.data)+3216, a2=0x1, a3=sym(move_mipmap).
  The `jalr` at 0xd008 calls tile_mapout with a0=?, a1=?, a2=?, a3=?.
  The `jalr` at 0xd010 calls tile_mapout with a0=?, a1=?, a2=?, a3=?.
  The `jalr` at 0xd038 calls tile_mapin with a0=[(a1 + ([a0+3039]:1 << 0x2))], a1=0x11, a2=a2 at entry (arg2), a3=a3 at entry (arg3), a4=[a0+3042]:1.
  The `jalr` at 0xd054 calls tile_mapin with a0=[(a1 + ([a0+3040]:1 << 0x2))], a1=0x11, a2=?, a3=?.
  The `jalr` at 0xd078 calls .text+52112 with a0=sp-48, a1=sym(.data)+3224, a2=0x0, a3=sym(move_mipmap).
  The `jalr` at 0xd08c calls tile_mapout with a0=?, a1=?, a2=?, a3=?.
  The `jalr` at 0xd094 calls tile_mapout with a0=?, a1=?, a2=?, a3=?.
  The `beq` branch at 0xce50 targets 0xcf38, is taken when a4(=[a0+3042]:1) == at(=0x2), and falls through when a4(=[a0+3042]:1) != at(=0x2).
  The `beq` branch at 0xce5c targets 0xcf9c, is taken when a4(=[a0+3042]:1) == v0(=0x1), and falls through when a4(=[a0+3042]:1) != v0(=0x1).
  The `beq` branch at 0xce64 targets 0xd020, is taken when a4(=[a0+3042]:1) == v1(=0x3), and falls through when a4(=[a0+3042]:1) != v1(=0x3).
  The `beq` branch at 0xce70 targets 0xce94, is taken when a4(=[a0+3042]:1) == a0(=0x4), and falls through when a4(=[a0+3042]:1) != a0(=0x4).
  The `beq` branch at 0xcf30 targets 0xce7c and is always taken.
  The `beq` branch at 0xcf94 targets 0xce7c and is always taken.
  The `beq` branch at 0xd018 targets 0xce7c and is always taken.
  The `beq` branch at 0xd09c targets 0xce7c and is always taken.
  The return at 0xce8c has v0 = one of 0x16, ret(.text+52112).
