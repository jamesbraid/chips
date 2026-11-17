# Readings: `IP27/usr/cpu/sysgen/IP27boot/nic.o`

One entry per routine, filed here from the reading batches by binary.

- `nic_get_phase_bits` in `IP27/usr/cpu/sysgen/IP27boot/nic.o` at 0x68 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/nic.o`.
  Range: 0x68-0x9c (52 bytes).
  It occupies 52 bytes.
  The `ld` at 0x70 loads 8 bytes from abs 0x9000000010000078.
  The return at 0x94 has v0 = ?.

- `nic_next_scan` in `IP27/usr/cpu/sysgen/IP27boot/nic.o` at 0x210 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/nic.o`.
  Range: 0x210-0x3f4 (484 bytes).
  It occupies 484 bytes.
  The `lw` at 0x210 loads 4 bytes from a0 (arg0 at entry) +0x14.
  3 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x1c, including `sw` at 0x260, `sw` at 0x384, `sw` at 0x3b8.
  3 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x18, including `sw` at 0x26c, `sw` at 0x2b8, `sw` at 0x33c.
  7 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x18, including `lw` at 0x280, `lw` at 0x28c, `lw` at 0x2a8.
  3 such `sb` accesses store 1 byte to ([a0+24] + a0) +0x1f, including `sb` at 0x288, `sb` at 0x30c, `sb` at 0x378.
  5 such `lbu` accesses load 1 byte from ([a0+24] + a0) +0x1f, including `lbu` at 0x29c, `lbu` at 0x318, `lbu` at 0x38c.
  The `lw` at 0x2fc loads 4 bytes from a0 (arg0 at entry) +0x10.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x1c, including `lw` at 0x340, `lw` at 0x390.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x10, including `sw` at 0x348, `sw` at 0x398.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x14, including `sw` at 0x3cc, `sw` at 0x3e8.
  The `jal` at 0x23c calls nic_presence with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x268 calls nic_write_byte with a0=a0 at entry (arg0), a1=0xf0, a2=?, a3=?.
  The `jal` at 0x298 calls nic_write with a0=a0 at entry (arg0), a1=[([a0+24] + a0)+31]:1, a2=([a0+24] + a0), a3=?, a4=ret(nic_read).
  The `jal` at 0x2bc calls nic_read with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x2d0 calls nic_read with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x31c calls nic_write with a0=a0 at entry (arg0), a1=[([a0+24] + a0)+31]:1, a2=?, a3=?, a4=[a0+24].
  The `beq` branch at 0x224 targets 0x23c, is taken when at(=[a0+20]) == 0, and falls through when at(=[a0+20]) != 0.
  The `bltz` branch at 0x244 targets 0x354, is taken when v0(=ret(nic_presence)) < 0 (signed), and falls through when v0(=ret(nic_presence)) >= 0 (signed).
  The `beq` branch at 0x24c targets 0x25c, is taken when v0(=ret(nic_presence)) == 0, and falls through when v0(=ret(nic_presence)) != 0.
  The `beq` branch at 0x254 targets 0x22c and is always taken.
  The `bgez` branch at 0x270 targets 0x2bc, is taken when v0(=ret(nic_write_byte)) >= 0 (signed), and falls through when v0(=ret(nic_write_byte)) < 0 (signed).
  The `beq` branch at 0x278 targets 0x230 and is always taken.
  The `bltz` branch at 0x2a0 targets 0x3d8, is taken when v0(=ret(nic_write)) < 0 (signed), and falls through when v0(=ret(nic_write)) >= 0 (signed).
  The `beq` branch at 0x2b4 targets 0x390, is taken when a3(=[a0+24]) >= 0x40 (signed), and falls through when a3(=[a0+24]) < 0x40 (signed).
  The `bltz` branch at 0x2c8 targets 0x3a4, is taken when v0(=ret(nic_read)) < 0 (signed), and falls through when v0(=ret(nic_read)) >= 0 (signed).
  The `bltz` branch at 0x2dc targets 0x3d0, is taken when v0(=ret(nic_read)) < 0 (signed), and falls through when v0(=ret(nic_read)) >= 0 (signed).
  The `beq` branch at 0x2e4 targets 0x35c, is taken when a4(=ret(nic_read)) == a0(=0x1), and falls through when a4(=ret(nic_read)) != a0(=0x1).
  The `bne` branch at 0x2ec targets 0x280, is taken when a4(=ret(nic_read)) != 0, and falls through when a4(=ret(nic_read)) == 0.
  The `bne` branch at 0x2f4 targets 0x280, is taken when v0(=ret(nic_read)) != 0, and falls through when v0(=ret(nic_read)) == 0.
  The `bne` branch at 0x304 targets 0x36c, is taken when a1(=[a0+16]) != a4(=[a0+24]), and falls through when a1(=[a0+16]) == a4(=[a0+24]).
  The `bltz` branch at 0x324 targets 0x3ec, is taken when v0(=ret(nic_write)) < 0 (signed), and falls through when v0(=ret(nic_write)) >= 0 (signed).
  The `bne` branch at 0x338 targets 0x2bc, is taken when a2(=[a0+24]) < 0x40 (signed), and falls through when a2(=[a0+24]) >= 0x40 (signed).
  The `beq` branch at 0x344 targets 0x3e0, is taken when a3(=[a0+28]) == 0, and falls through when a3(=[a0+28]) != 0.
  The `beq` branch at 0x34c targets 0x22c and is always taken.
  The `beq` branch at 0x354 targets 0x230 and is always taken.
  The `bne` branch at 0x35c targets 0x2ec, is taken when v0(=ret(nic_read)) != a0(=0x1), and falls through when v0(=ret(nic_read)) == a0(=0x1).
  The `beq` branch at 0x364 targets 0x22c and is always taken.
  The `beq` branch at 0x370 targets 0x3ac, is taken when a1(=[a0+16]) >= a4(=[a0+24]) (signed), and falls through when a1(=[a0+16]) < a4(=[a0+24]) (signed).
  The `beq` branch at 0x388 targets 0x31c and is always taken.
  The `beq` branch at 0x394 targets 0x3c4, is taken when a3(=[a0+28]) == 0, and falls through when a3(=[a0+28]) != 0.
  The `beq` branch at 0x39c targets 0x22c and is always taken.
  The `beq` branch at 0x3a4 targets 0x230 and is always taken.
  The `bne` branch at 0x3b0 targets 0x31c, is taken when a1(=[([a0+24] + a0)+31]:1) != 0, and falls through when a1(=[([a0+24] + a0)+31]:1) == 0.
  The `beq` branch at 0x3bc targets 0x31c and is always taken.
  The `beq` branch at 0x3c8 targets 0x39c and is always taken.
  The `beq` branch at 0x3d0 targets 0x230 and is always taken.
  The `beq` branch at 0x3d8 targets 0x230 and is always taken.
  The `beq` branch at 0x3e4 targets 0x34c and is always taken.
  The `beq` branch at 0x3ec targets 0x230 and is always taken.
  The return at 0x234 has v0 = one of 0x0, 0x1, 0x2, 0x4, ret(nic_write_byte), ret(nic_presence), ret(nic_read), ret(nic_write).

- `nic_setup` in `IP27/usr/cpu/sysgen/IP27boot/nic.o` at 0x3f4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/nic.o`.
  Range: 0x3f4-0x41c (40 bytes).
  It occupies 40 bytes.
  The `sd` at 0x3f4 stores 8 bytes to a0 (arg0 at entry) +0x0.
  The `sd` at 0x3f8 stores 8 bytes to a0 (arg0 at entry) +0x8.
  The `sw` at 0x3fc stores 4 bytes to a0 (arg0 at entry) +0x10.
  The `sw` at 0x40c stores 4 bytes to a0 (arg0 at entry) +0x14.
  The `jal` at 0x408 calls nic_presence with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x414 has v0 = ret(nic_presence).

- `nic_next` in `IP27/usr/cpu/sysgen/IP27boot/nic.o` at 0x41c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/nic.o`.
  Range: 0x41c-0x5ac (400 bytes).
  It occupies 400 bytes.
  4 such `sb` accesses store 1 byte to ?, including `sb` at 0x478, `sb` at 0x48c, `sb` at 0x4a4.
  3 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x4c0, `lbu` at 0x4cc, `lbu` at 0x4fc.
  The `lw` at 0x510 loads 4 bytes from ?.
  The `sb` at 0x554 stores 1 byte to a1 (arg1 at entry) +0x4.
  The `sb` at 0x558 stores 1 byte to a1 (arg1 at entry) +0x0.
  The `sb` at 0x56c stores 1 byte to a1 (arg1 at entry) +0x1.
  The `sb` at 0x570 stores 1 byte to a1 (arg1 at entry) +0x2.
  The `sb` at 0x574 stores 1 byte to a1 (arg1 at entry) +0x3.
  The `sb` at 0x57c stores 1 byte to a1 (arg1 at entry) +0x5.
  The `sb` at 0x588 stores 1 byte to a3 (arg3 at entry) +0x0.
  The `sb` at 0x5a0 stores 1 byte to a2 (arg2 at entry) +0x0.
  The `jal` at 0x43c calls nic_next_scan with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0x448 targets 0x464, is taken when v0(=ret(nic_next_scan)) == 0, and falls through when v0(=ret(nic_next_scan)) != 0.
  The `beq` branch at 0x47c targets 0x4a8, is taken when a6(?) >= 0x8 (signed), and falls through when a6(?) < 0x8 (signed).
  The `beq` branch at 0x490 targets 0x4a8, is taken when a6(?) >= 0x8 (signed), and falls through when a6(?) < 0x8 (signed).
  The `bne` branch at 0x4a0 targets 0x46c, is taken when a6(?) < 0x8 (signed), and falls through when a6(?) >= 0x8 (signed).
  The `bne` branch at 0x4e0 targets 0x4ac, is taken when a6(?) < 0x40 (signed), and falls through when a6(?) >= 0x40 (signed).
  The `bne` branch at 0x52c targets 0x4f8, is taken when a7(?) < 0x8 (signed), and falls through when a7(?) >= 0x8 (signed).
  The `beq` branch at 0x534 targets 0x544, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `beq` branch at 0x53c targets 0x454 and is always taken.
  The `beq` branch at 0x548 targets 0x594, is taken when t8(=a1) == 0, and falls through when t8(=a1) != 0.
  The `bne` branch at 0x578 targets 0x59c, is taken when s2(=a2) != 0, and falls through when s2(=a2) == 0.
  The `beq` branch at 0x580 targets 0x58c, is taken when s1(=a3) == 0, and falls through when s1(=a3) != 0.
  The `beq` branch at 0x58c targets 0x450 and is always taken.
  The `beq` branch at 0x594 targets 0x580, is taken when s2(=a2) == 0, and falls through when s2(=a2) != 0.
  The `bne` branch at 0x59c targets 0x584, is taken when s1(=a3) != 0, and falls through when s1(=a3) == 0.
  The `beq` branch at 0x5a4 targets 0x58c and is always taken.
  The return at 0x45c has v0 = one of ?, 0x3.

- `nic_match_rom` in `IP27/usr/cpu/sysgen/IP27boot/nic.o` at 0x5ac (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/nic.o`.
  Range: 0x5ac-0x6e8 (316 bytes).
  It occupies 316 bytes.
  The `lbu` at 0x618 loads 1 byte from a1 (arg1 at entry) +0x0.
  The `lbu` at 0x628 loads 1 byte from a2 (arg2 at entry) +0x5.
  The `lbu` at 0x638 loads 1 byte from a2 (arg2 at entry) +0x4.
  The `lbu` at 0x648 loads 1 byte from a2 (arg2 at entry) +0x3.
  The `lbu` at 0x658 loads 1 byte from a2 (arg2 at entry) +0x2.
  The `lbu` at 0x668 loads 1 byte from a2 (arg2 at entry) +0x1.
  The `lbu` at 0x678 loads 1 byte from a2 (arg2 at entry) +0x0.
  The `lbu` at 0x68c loads 1 byte from a3 (arg3 at entry) +0x0.
  The `jal` at 0x5c8 calls nic_presence with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x5e0 calls printf with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jal` at 0x600 calls nic_write_byte with a0=a0 at entry (arg0), a1=0x55, a2=?, a3=?.
  The `jal` at 0x614 calls nic_write_byte with a0=a0 at entry (arg0), a1=[a1]:1, a2=?, a3=?.
  The `jal` at 0x624 calls nic_write_byte with a0=a0 at entry (arg0), a1=[a2+5]:1, a2=?, a3=?.
  The `jal` at 0x634 calls nic_write_byte with a0=a0 at entry (arg0), a1=[a2+4]:1, a2=?, a3=?.
  The `jal` at 0x644 calls nic_write_byte with a0=a0 at entry (arg0), a1=[a2+3]:1, a2=?, a3=?.
  The `jal` at 0x654 calls nic_write_byte with a0=a0 at entry (arg0), a1=[a2+2]:1, a2=?, a3=?.
  The `jal` at 0x664 calls nic_write_byte with a0=a0 at entry (arg0), a1=[a2+1]:1, a2=?, a3=?.
  The `jal` at 0x674 calls nic_write_byte with a0=a0 at entry (arg0), a1=[a2]:1, a2=?, a3=?.
  The `jal` at 0x688 calls nic_write_byte with a0=a0 at entry (arg0), a1=[a3]:1, a2=?, a3=?.
  The `bltz` branch at 0x5d0 targets 0x5ec, is taken when v0(=ret(nic_presence)) < 0 (signed), and falls through when v0(=ret(nic_presence)) >= 0 (signed).
  The `beq` branch at 0x5d8 targets 0x600, is taken when v0(=ret(nic_presence)) == 0, and falls through when v0(=ret(nic_presence)) != 0.
  The `bltz` branch at 0x608 targets 0x6a0, is taken when v0(=ret(nic_write_byte)) < 0 (signed), and falls through when v0(=ret(nic_write_byte)) >= 0 (signed).
  The `bltz` branch at 0x61c targets 0x6a8, is taken when v0(=ret(nic_write_byte)) < 0 (signed), and falls through when v0(=ret(nic_write_byte)) >= 0 (signed).
  The `bltz` branch at 0x62c targets 0x6b0, is taken when v0(=ret(nic_write_byte)) < 0 (signed), and falls through when v0(=ret(nic_write_byte)) >= 0 (signed).
  The `bltz` branch at 0x63c targets 0x6b8, is taken when v0(=ret(nic_write_byte)) < 0 (signed), and falls through when v0(=ret(nic_write_byte)) >= 0 (signed).
  The `bltz` branch at 0x64c targets 0x6c0, is taken when v0(=ret(nic_write_byte)) < 0 (signed), and falls through when v0(=ret(nic_write_byte)) >= 0 (signed).
  The `bltz` branch at 0x65c targets 0x6c8, is taken when v0(=ret(nic_write_byte)) < 0 (signed), and falls through when v0(=ret(nic_write_byte)) >= 0 (signed).
  The `bltz` branch at 0x66c targets 0x6d0, is taken when v0(=ret(nic_write_byte)) < 0 (signed), and falls through when v0(=ret(nic_write_byte)) >= 0 (signed).
  The `bltz` branch at 0x67c targets 0x6d8, is taken when v0(=ret(nic_write_byte)) < 0 (signed), and falls through when v0(=ret(nic_write_byte)) >= 0 (signed).
  The `bltz` branch at 0x690 targets 0x6e0, is taken when v0(=ret(nic_write_byte)) < 0 (signed), and falls through when v0(=ret(nic_write_byte)) >= 0 (signed).
  The `beq` branch at 0x698 targets 0x5ec and is always taken.
  The `beq` branch at 0x6a0 targets 0x5f0 and is always taken.
  The `beq` branch at 0x6a8 targets 0x5f0 and is always taken.
  The `beq` branch at 0x6b0 targets 0x5f0 and is always taken.
  The `beq` branch at 0x6b8 targets 0x5f0 and is always taken.
  The `beq` branch at 0x6c0 targets 0x5f0 and is always taken.
  The `beq` branch at 0x6c8 targets 0x5f0 and is always taken.
  The `beq` branch at 0x6d0 targets 0x5f0 and is always taken.
  The `beq` branch at 0x6d8 targets 0x5f0 and is always taken.
  The `beq` branch at 0x6e0 targets 0x5f0 and is always taken.
  The return at 0x5f8 has v0 = one of ?, ret(nic_write_byte).

- `nic_read_one_page` in `IP27/usr/cpu/sysgen/IP27boot/nic.o` at 0x6e8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/nic.o`.
  Range: 0x6e8-0x878 (400 bytes).
  It occupies 400 bytes.
  The `lbu` at 0x700 loads 1 byte from (a4 + a5) +0x0.
  2 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x73c, `lbu` at 0x7f8.
  The `lbu` at 0x7b8 loads 1 byte from a1 (arg1 at entry) +0x0.
  The `sb` at 0x7e0 stores 1 byte to ?.
  The `jal` at 0x74c calls nic_match_rom with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x778 calls nic_write_byte with a0=a0 at entry (arg0), a1=0xf0, a2=?, a3=?.
  The `jal` at 0x790 calls nic_write_byte with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x7a8 calls nic_write_byte with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x7c4 calls nic_read_byte with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x7f4 calls crc16 with a0=?, a1=sp-64, a2=?, a3=?.
  The `jal` at 0x828 calls printf with a0=sym(.rodata), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x848 calls nic_read_byte with a0=a0 at entry (arg0), a1=?, a2=[a1]:1, a3=0x9.
  The `beq` branch at 0x720 targets 0x748, is taken when t1(=0xff) == t2(=[(a4 + a5)]:1), and falls through when t1(=0xff) != t2(=[(a4 + a5)]:1).
  The `beq` branch at 0x730 targets 0x824, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `bne` branch at 0x740 targets 0x72c, is taken when t1(=0xff) != t0(?), and falls through when t1(=0xff) == t0(?).
  The `beq` branch at 0x754 targets 0x778, is taken when v0(=ret(nic_match_rom)) == 0, and falls through when v0(=ret(nic_match_rom)) != 0.
  The `bltz` branch at 0x780 targets 0x838, is taken when v0(=ret(nic_write_byte)) < 0 (signed), and falls through when v0(=ret(nic_write_byte)) >= 0 (signed).
  The `bltz` branch at 0x798 targets 0x840, is taken when v0(=ret(nic_write_byte)) < 0 (signed), and falls through when v0(=ret(nic_write_byte)) >= 0 (signed).
  The `bltz` branch at 0x7b0 targets 0x870, is taken when v0(=ret(nic_write_byte)) < 0 (signed), and falls through when v0(=ret(nic_write_byte)) >= 0 (signed).
  The `beq` branch at 0x7bc targets 0x848, is taken when a2(=[a1]:1) == a3(=0x9), and falls through when a2(=[a1]:1) != a3(=0x9).
  The `bltz` branch at 0x7cc targets 0x860, is taken when v0(=ret(nic_read_byte)) < 0 (signed), and falls through when v0(=ret(nic_read_byte)) >= 0 (signed).
  The `bne` branch at 0x7dc targets 0x7c4, is taken when s0(?) < 0x20 (signed), and falls through when s0(?) >= 0x20 (signed).
  The `bne` branch at 0x804 targets 0x7f0, is taken when s0(?) < 0x20 (signed), and falls through when s0(?) >= 0x20 (signed).
  The `beq` branch at 0x814 targets 0x868, is taken when a2(?) == a3(=0xb001), and falls through when a2(?) != a3(=0xb001).
  The `beq` branch at 0x81c targets 0x760 and is always taken.
  The `beq` branch at 0x830 targets 0x75c and is always taken.
  The `beq` branch at 0x838 targets 0x760 and is always taken.
  The `beq` branch at 0x840 targets 0x760 and is always taken.
  The `bgez` branch at 0x850 targets 0x7c4, is taken when v0(=ret(nic_read_byte)) >= 0 (signed), and falls through when v0(=ret(nic_read_byte)) < 0 (signed).
  The `beq` branch at 0x858 targets 0x760 and is always taken.
  The `beq` branch at 0x860 targets 0x760 and is always taken.
  The `beq` branch at 0x868 targets 0x75c and is always taken.
  The `beq` branch at 0x870 targets 0x760 and is always taken.
  The return at 0x770 has v0 = one of ?, 0x3, ret(nic_write_byte), ret(nic_read_byte).

- `nic_read_mfg` in `IP27/usr/cpu/sysgen/IP27boot/nic.o` at 0x878 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/nic.o`.
  Range: 0x878-0xb8c (788 bytes).
  It occupies 788 bytes.
  The `lbu` at 0x89c loads 1 byte from a1 (arg1 at entry) +0x0.
  6 such `sb` accesses store 1 byte to ?, including `sb` at 0x8dc, `sb` at 0x8f4, `sb` at 0x90c.
  3 such `lbu` accesses load 1 byte from ?, including `lbu` at 0xa20, `lbu` at 0xa64, `lbu` at 0xa84.
  The `jal` at 0x928 calls nic_read_one_page with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a4=0x0, a5=sp-208, a6=a4 at entry (arg4).
  The `jal` at 0x968 calls nic_match_rom with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x998 calls nic_read_one_page with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a4=0x1, a5=sp-208, a6=a5 at entry (arg5).
  The `jal` at 0x9b0 calls nic_write_byte with a0=a0 at entry (arg0), a1=0xaa, a2=?, a3=?.
  The `jal` at 0x9c4 calls nic_write_byte with a0=a0 at entry (arg0), a1=0x0, a2=?, a3=?.
  The `jal` at 0x9d8 calls nic_write_byte with a0=a0 at entry (arg0), a1=0x1, a2=?, a3=?.
  The `jal` at 0x9fc calls crc16 with a0=0x0, a1=sp-112, a2=?, a3=?.
  The `jal` at 0xa08 calls crc16 with a0=0x1, a1=sp-112, a2=?, a3=?.
  The `jal` at 0xa1c calls crc16 with a0=?, a1=sp-112, a2=?, a3=?.
  The `jal` at 0xaa8 calls nic_read_byte with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xadc calls crc16 with a0=0xaa, a1=sp-112, a2=?, a3=?.
  The `jal` at 0xb0c calls printf with a0=sym(.rodata), a1=?, a2=0xb001, a3=?.
  The `jal` at 0xb34 calls nic_read_one_page with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a4=0x0, a5=sp-208, a6=a4 at entry (arg4).
  The `jal` at 0xb5c calls nic_read_one_page with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a4=0x1, a5=sp-208, a6=a5 at entry (arg5).
  The `bne` branch at 0x8bc targets 0x968, is taken when at(=[a1]:1) != v0(=0x9), and falls through when at(=[a1]:1) == v0(=0x9).
  The `beq` branch at 0x8e0 targets 0x914, is taken when v0(?) >= 0x40 (signed), and falls through when v0(?) < 0x40 (signed).
  The `beq` branch at 0x8f8 targets 0x910, is taken when v0(?) >= 0x40 (signed), and falls through when v0(?) < 0x40 (signed).
  The `bne` branch at 0x908 targets 0x8d0, is taken when v0(?) < 0x40 (signed), and falls through when v0(?) >= 0x40 (signed).
  The `beq` branch at 0x930 targets 0x980, is taken when v0(=ret(nic_read_one_page)) == 0, and falls through when v0(=ret(nic_read_one_page)) != 0.
  The `beq` branch at 0x970 targets 0x9ac, is taken when v0(=ret(nic_match_rom)) == 0, and falls through when v0(=ret(nic_match_rom)) != 0.
  The `beq` branch at 0x978 targets 0x93c and is always taken.
  The `beq` branch at 0x9a4 targets 0x938 and is always taken.
  The `bltz` branch at 0x9b8 targets 0xaf4, is taken when v0(=ret(nic_write_byte)) < 0 (signed), and falls through when v0(=ret(nic_write_byte)) >= 0 (signed).
  The `bltz` branch at 0x9cc targets 0xafc, is taken when v0(=ret(nic_write_byte)) < 0 (signed), and falls through when v0(=ret(nic_write_byte)) >= 0 (signed).
  The `bltz` branch at 0x9e4 targets 0xb74, is taken when v0(=ret(nic_write_byte)) < 0 (signed), and falls through when v0(=ret(nic_write_byte)) >= 0 (signed).
  The `beq` branch at 0x9f4 targets 0xaa4 and is always taken.
  The `bne` branch at 0xa2c targets 0xa14, is taken when s2(?) < 0xa (signed), and falls through when s2(?) >= 0xa (signed).
  The `bne` branch at 0xa38 targets 0xb04, is taken when a2(=0xb001) != a3(?), and falls through when a2(=0xb001) == a3(?).
  The `beq` branch at 0xa70 targets 0xa94, is taken when v0(?) >= 0x8 (signed), and falls through when v0(?) < 0x8 (signed).
  The `bne` branch at 0xa8c targets 0xa54, is taken when v0(?) < 0x8 (signed), and falls through when v0(?) >= 0x8 (signed).
  The `beq` branch at 0xa9c targets 0xb1c, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `bltz` branch at 0xab4 targets 0xaec, is taken when v0(=ret(nic_read_byte)) < 0 (signed), and falls through when v0(=ret(nic_read_byte)) >= 0 (signed).
  The `bne` branch at 0xac4 targets 0xaa8, is taken when s2(?) < 0xa (signed), and falls through when s2(?) >= 0xa (signed).
  The `bne` branch at 0xad0 targets 0xa10, is taken when t0(?) != 0, and falls through when t0(?) == 0.
  The `beq` branch at 0xae4 targets 0x9fc and is always taken.
  The `beq` branch at 0xaec targets 0x93c and is always taken.
  The `beq` branch at 0xaf4 targets 0x93c and is always taken.
  The `beq` branch at 0xafc targets 0x93c and is always taken.
  The `beq` branch at 0xb14 targets 0x938 and is always taken.
  The `bltz` branch at 0xb3c targets 0xb7c, is taken when v0(=ret(nic_read_one_page)) < 0 (signed), and falls through when v0(=ret(nic_read_one_page)) >= 0 (signed).
  The `bltz` branch at 0xb64 targets 0xb84, is taken when v0(=ret(nic_read_one_page)) < 0 (signed), and falls through when v0(=ret(nic_read_one_page)) >= 0 (signed).
  The `beq` branch at 0xb6c targets 0x938 and is always taken.
  The `beq` branch at 0xb74 targets 0x93c and is always taken.
  The `beq` branch at 0xb7c targets 0x93c and is always taken.
  The `beq` branch at 0xb84 targets 0x93c and is always taken.
  The return at 0x960 has v0 = one of ?, ret(nic_match_rom), ret(nic_read_byte), ret(nic_write_byte), ret(nic_read_one_page).

- `char2hex` in `IP27/usr/cpu/sysgen/IP27boot/nic.o` at 0xb8c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/nic.o`.
  Range: 0xb8c-0xc0c (128 bytes).
  It occupies 128 bytes.
  The `ld` at 0xb94 loads 8 bytes from sym(.rodata) +0xb8.
  The `ld` at 0xba0 loads 8 bytes from sym(.rodata) +0xc0.
  The `lbu` at 0xba8 loads 1 byte from sym(.rodata) +0xc8.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0xbc8, `lw` at 0xbf0.
  The `sb` at 0xbe8 stores 1 byte to a0 (arg0 at entry) +0x0.
  The `sb` at 0xc08 stores 1 byte to a0 (arg0 at entry) +0x1.
  The return at 0xc04 has v0 = ?.

- `chars2hex` in `IP27/usr/cpu/sysgen/IP27boot/nic.o` at 0xc0c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/nic.o`.
  Range: 0xc0c-0xc98 (140 bytes).
  It occupies 140 bytes.
  The `lbu` at 0xc58 loads 1 byte from ?.
  The `sb` at 0xc94 stores 1 byte to ((ret(strlen) + a0) + (a2 + a2)) +0x0.
  The `jal` at 0xc28 calls strlen with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xc54 calls char2hex with a0=?, a1=?, a2=?, a3=?.
  The `blez` branch at 0xc3c targets 0xc6c, is taken when s3(=a2) <= 0 (signed), and falls through when s3(=a2) > 0 (signed).
  The `bne` branch at 0xc64 targets 0xc48, is taken when s1(?) < s3(=a2) (signed), and falls through when s1(?) >= s3(=a2) (signed).
  The return at 0xc90 has v0 = one of ret(strlen), ret(char2hex).

- `chars2print` in `IP27/usr/cpu/sysgen/IP27boot/nic.o` at 0xc98 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/nic.o`.
  Range: 0xc98-0xda4 (268 bytes).
  It occupies 268 bytes.
  6 such `sb` accesses store 1 byte to ?, including `sb` at 0xd04, `sb` at 0xd48, `sb` at 0xd58.
  2 such `lbu` accesses load 1 byte from ?, including `lbu` at 0xd1c, `lbu` at 0xd4c.
  The `lbu` at 0xda0 loads 1 byte from a1 (arg1 at entry) +0x0.
  The `jal` at 0xcb4 calls strlen with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `blez` branch at 0xce0 targets 0xd70, is taken when s1(=a2) <= 0 (signed), and falls through when s1(=a2) > 0 (signed).
  The `beq` branch at 0xce8 targets 0xd98 and is always taken.
  The `bne` branch at 0xcf4 targets 0xd04, is taken when at(?) != 0, and falls through when at(?) == 0.
  The `bne` branch at 0xcfc targets 0xd10, is taken when a5(?) != 0, and falls through when a5(?) == 0.
  The `beq` branch at 0xd14 targets 0xd70, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0xd20 targets 0xd58, is taken when a2(=0x3a) == a3(?), and falls through when a2(=0x3a) != a3(?).
  The `beq` branch at 0xd28 targets 0xd58, is taken when a7(=0x3b) == a3(?), and falls through when a7(=0x3b) != a3(?).
  The `beq` branch at 0xd30 targets 0xd64, is taken when a1(=0xff) == a3(?), and falls through when a1(=0xff) != a3(?).
  The `bne` branch at 0xd38 targets 0xcf0, is taken when v1(?) != 0, and falls through when v1(?) == 0.
  The `beq` branch at 0xd40 targets 0xcf4, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `beq` branch at 0xd50 targets 0xcf0 and is always taken.
  The `beq` branch at 0xd5c targets 0xd30 and is always taken.
  The `beq` branch at 0xd68 targets 0xd34 and is always taken.
  The `bne` branch at 0xd74 targets 0xd88, is taken when t3(=(ret(strlen) + a0)) != s0(?), and falls through when t3(=(ret(strlen) + a0)) == s0(?).
  The `beq` branch at 0xd9c targets 0xd20 and is always taken.
  The return at 0xd90 has v0 = ?.

- `nic_eaddr` in `IP27/usr/cpu/sysgen/IP27boot/nic.o` at 0xda4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/nic.o`.
  Range: 0xda4-0x1018 (628 bytes).
  It occupies 628 bytes.
  2 such `sb` accesses store 1 byte to ?, including `sb` at 0xee8, `sb` at 0xf9c.
  3 such `lbu` accesses load 1 byte from ?, including `lbu` at 0xf04, `lbu` at 0xf58, `lbu` at 0xf94.
  The `jal` at 0xdc8 calls nic_setup with a0=sp-176, a1=a0 at entry (arg0), a2=a1 at entry (arg1), a3=a3 at entry (arg3), a5=a1 at entry (arg1).
  The `jal` at 0xde0 calls printf with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jal` at 0xde8 calls printf with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jal` at 0xe0c calls printf with a0=sym(.rodata), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a5=a1 at entry (arg1).
  The `jal` at 0xe28 calls nic_next with a0=sp-176, a1=sp-48, a2=sp-42, a3=sp-41.
  The `jal` at 0xe98 calls nic_write_byte with a0=sp-176, a1=0xf0, a2=?, a3=?.
  The `jal` at 0xea8 calls nic_write_byte with a0=sp-176, a1=0x0, a2=?, a3=?.
  The `jal` at 0xeb8 calls nic_write_byte with a0=sp-176, a1=0x0, a2=?, a3=?.
  The `jal` at 0xec8 calls nic_read_byte with a0=sp-176, a1=?, a2=?, a3=?.
  The `jal` at 0xf00 calls crc16 with a0=?, a1=sp-40, a2=?, a3=?.
  The `jal` at 0xf54 calls crc16 with a0=?, a1=sp-40, a2=?, a3=?.
  The `beq` branch at 0xdb8 targets 0xe08, is taken when a2 == 0, and falls through when a2 != 0.
  The `beq` branch at 0xdd0 targets 0xe1c, is taken when v0(=ret(nic_setup)) == 0, and falls through when v0(=ret(nic_setup)) != 0.
  The `blez` branch at 0xdd8 targets 0xdf4, is taken when v0(=ret(nic_setup)) <= 0 (signed), and falls through when v0(=ret(nic_setup)) > 0 (signed).
  The `beq` branch at 0xe14 targets 0xdf8 and is always taken.
  The `beq` branch at 0xe30 targets 0xe40, is taken when v0(=ret(nic_next)) == 0, and falls through when v0(=ret(nic_next)) != 0.
  The `beq` branch at 0xe38 targets 0xdfc and is always taken.
  The `bne` branch at 0xe48 targets 0xe78, is taken when v0(?) < 0xa (signed), and falls through when v0(?) >= 0xa (signed).
  The `bne` branch at 0xe50 targets 0xe94, is taken when a2(?) != 0, and falls through when a2(?) == 0.
  The `bne` branch at 0xe58 targets 0xfc4, is taken when a3(?) != 0, and falls through when a3(?) == 0.
  The `bne` branch at 0xe60 targets 0xe94, is taken when a4(?) != 0, and falls through when a4(?) == 0.
  The `bne` branch at 0xe68 targets 0xe20, is taken when a5(=0x91) != v0(?), and falls through when a5(=0x91) == v0(?).
  The `beq` branch at 0xe70 targets 0xe98 and is always taken.
  The `bne` branch at 0xe7c targets 0xfa8, is taken when v0(?) < 0x8 (signed), and falls through when v0(?) >= 0x8 (signed).
  The `bne` branch at 0xe84 targets 0xe94, is taken when a7(?) != 0, and falls through when a7(?) == 0.
  The `bne` branch at 0xe8c targets 0xe20, is taken when t0(=0x9) != v0(?), and falls through when t0(=0x9) == v0(?).
  The `bltz` branch at 0xea0 targets 0x1000, is taken when v0(=ret(nic_write_byte)) < 0 (signed), and falls through when v0(=ret(nic_write_byte)) >= 0 (signed).
  The `bltz` branch at 0xeb0 targets 0x1008, is taken when v0(=ret(nic_write_byte)) < 0 (signed), and falls through when v0(=ret(nic_write_byte)) >= 0 (signed).
  The `bltz` branch at 0xec0 targets 0x1010, is taken when v0(=ret(nic_write_byte)) < 0 (signed), and falls through when v0(=ret(nic_write_byte)) >= 0 (signed).
  The `bltz` branch at 0xed4 targets 0xff8, is taken when v0(=ret(nic_read_byte)) < 0 (signed), and falls through when v0(=ret(nic_read_byte)) >= 0 (signed).
  The `bne` branch at 0xee4 targets 0xec8, is taken when s0(?) < 0xe (signed), and falls through when s0(?) >= 0xe (signed).
  The `bne` branch at 0xf10 targets 0xef8, is taken when s0(?) < 0xe (signed), and falls through when s0(?) >= 0xe (signed).
  The `bne` branch at 0xf20 targets 0xe20, is taken when a2(=0x8d) != a3(?), and falls through when a2(=0x8d) == a3(?).
  The `bne` branch at 0xf30 targets 0xe1c, is taken when a4(=0xb001) != a5(?), and falls through when a4(=0xb001) == a5(?).
  The `bne` branch at 0xf3c targets 0xe1c, is taken when a6(=0xa) != a7(?), and falls through when a6(=0xa) == a7(?).
  The `bne` branch at 0xf64 targets 0xf48, is taken when s0(?) < 0xe (signed), and falls through when s0(?) >= 0xe (signed).
  The `bne` branch at 0xf70 targets 0xe20, is taken when a2(=0xb001) != a3(?), and falls through when a2(=0xb001) == a3(?).
  The `bne` branch at 0xf98 targets 0xf7c, is taken when v0(?) < 0x6 (signed), and falls through when v0(?) >= 0x6 (signed).
  The `beq` branch at 0xfa0 targets 0xdf8 and is always taken.
  The `bne` branch at 0xfac targets 0xfe4, is taken when v0(?) < 0x6 (signed), and falls through when v0(?) >= 0x6 (signed).
  The `beq` branch at 0xfb4 targets 0xe20, is taken when a7(?) == 0, and falls through when a7(?) != 0.
  The `beq` branch at 0xfbc targets 0xe98 and is always taken.
  The `bne` branch at 0xfc8 targets 0xe20, is taken when v0(?) < 0xc (signed), and falls through when v0(?) >= 0xc (signed).
  The `beq` branch at 0xfd4 targets 0xe20, is taken when v0(?) >= 0xd (signed), and falls through when v0(?) < 0xd (signed).
  The `beq` branch at 0xfdc targets 0xe98 and is always taken.
  The `bne` branch at 0xfe8 targets 0xe20, is taken when t2(=0x4) != v0(?), and falls through when t2(=0x4) == v0(?).
  The `beq` branch at 0xff0 targets 0xe98 and is always taken.
  The `beq` branch at 0xff8 targets 0xdfc and is always taken.
  The `beq` branch at 0x1000 targets 0xdfc and is always taken.
  The `beq` branch at 0x1008 targets 0xdfc and is always taken.
  The `beq` branch at 0x1010 targets 0xdfc and is always taken.
  The return at 0xe00 has v0 = one of ?, ret(nic_next), ret(nic_read_byte), ret(nic_write_byte).

- `nic_get_eaddr` in `IP27/usr/cpu/sysgen/IP27boot/nic.o` at 0x10a0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/nic.o`.
  Range: 0x10a0-0x1158 (184 bytes).
  It occupies 184 bytes.
  The `sw` at 0x10d0 stores 4 bytes to a1 (arg1 at entry) +0x0.
  The `jal` at 0x10e8 calls nic_eaddr with a0=sym(nic_access_mcr32), a1=a0 at entry (arg0), a2=a2 at entry (arg2), a3=?.
  The `jal` at 0x110c calls printf with a0=sym(.rodata), a1=ret(nic_eaddr), a2=?, a3=?.
  The `jal` at 0x1140 calls printf with a0=sym(.rodata), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a5=0x200000.
  The `beq` branch at 0x10c8 targets 0x113c, is taken when a1 == 0, and falls through when a1 != 0.
  The `beq` branch at 0x10f4 targets 0x1150, is taken when v0(=ret(nic_eaddr)) == 0, and falls through when v0(=ret(nic_eaddr)) != 0.
  The `bne` branch at 0x10fc targets 0x10e4, is taken when s0(?) != s5(=-0x1), and falls through when s0(?) == s5(=-0x1).
  The `beq` branch at 0x1148 targets 0x10d8 and is always taken.
  The `beq` branch at 0x1150 targets 0x1118 and is always taken.
  The return at 0x1134 has v0 = ret(nic_eaddr).

- `nic_mfg_next` in `IP27/usr/cpu/sysgen/IP27boot/nic.o` at 0x1158 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/nic.o`.
  Range: 0x1158-0x15f8 (1184 bytes).
  It occupies 1184 bytes.
  The `ld` at 0x11c4 loads 8 bytes from (sym(.rodata) + (ret(nic_next) << 0x3)) +0x0.
  The `ld` at 0x1444 loads 8 bytes from sym(.rodata) +0x360.
  The `ld` at 0x1448 loads 8 bytes from sym(.rodata) +0x358.
  The `ld` at 0x144c loads 8 bytes from sym(.rodata) +0x350.
  The `ld` at 0x1450 loads 8 bytes from sym(.rodata) +0x348.
  The `ld` at 0x1454 loads 8 bytes from sym(.rodata) +0x340.
  The `sdl` at 0x1458 stores 8 bytes to (ret(strlen) + a1) +0x0.
  The `sdr` at 0x145c stores 8 bytes to (ret(strlen) + a1) +0x7.
  The `sdl` at 0x1460 stores 8 bytes to (ret(strlen) + a1) +0x8.
  The `sdr` at 0x1464 stores 8 bytes to (ret(strlen) + a1) +0xf.
  The `sdl` at 0x1468 stores 8 bytes to (ret(strlen) + a1) +0x10.
  The `sdr` at 0x146c stores 8 bytes to (ret(strlen) + a1) +0x17.
  The `sdl` at 0x1470 stores 8 bytes to (ret(strlen) + a1) +0x18.
  The `sdr` at 0x1474 stores 8 bytes to (ret(strlen) + a1) +0x1f.
  The `sdl` at 0x1478 stores 8 bytes to (ret(strlen) + a1) +0x20.
  The `sdr` at 0x1480 stores 8 bytes to (ret(strlen) + a1) +0x27.
  The `jal` at 0x118c calls strlen with a0=a1 at entry (arg1), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x11a4 calls nic_next with a0=a0 at entry (arg0), a1=sp-96, a2=sp-90, a3=sp-89.
  Calls (unknown callee) via register with a0=(sym(.rodata) + (ret(nic_next) << 0x3)), a1=sym(.rodata), a2=(ret(nic_next) << 0x3), a3=?, a4=[(sym(.rodata) + (ret(nic_next) << 0x3))]:8 (`jr` at 0x11c8).
  The `bne` branch at 0x116c targets 0x118c, is taken when a1 != 0, and falls through when a1 == 0.
  The `beq` branch at 0x11bc targets 0x1444, is taken when v0(=ret(nic_next)) >= 0x7 (unsigned), and falls through when v0(=ret(nic_next)) < 0x7 (unsigned).
  The `beq` branch at 0x147c targets 0x1178 and is always taken.
  The return at 0x1184 has v0 = ?.
  The instructions from 0x11d0 to 0x1440 are not reached by any path from the entry, and their branches are not listed.
  The instructions from 0x1484 to 0x15f4 are not reached by any path from the entry, and their branches are not listed.
  The indirect jump at 0x11c8 uses a jump table whose successors are unresolved.

- `nic_info_get` in `IP27/usr/cpu/sysgen/IP27boot/nic.o` at 0x15f8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/nic.o`.
  Range: 0x15f8-0x1650 (88 bytes).
  It occupies 88 bytes.
  The `sb` at 0x1600 stores 1 byte to a2 (arg2 at entry) +0x0.
  The `jal` at 0x161c calls nic_setup with a0=sp-112, a1=a0 at entry (arg0), a2=a1 at entry (arg1), a3=a3 at entry (arg3).
  The `jal` at 0x1630 calls nic_mfg_next with a0=sp-112, a1=a2 at entry (arg2), a2=?, a3=?.
  The `bltz` branch at 0x1624 targets 0x1640, is taken when v0(=ret(nic_setup)) < 0 (signed), and falls through when v0(=ret(nic_setup)) >= 0 (signed).
  The `beq` branch at 0x1638 targets 0x1630, is taken when v0(=ret(nic_mfg_next)) == 0, and falls through when v0(=ret(nic_mfg_next)) != 0.
  The return at 0x1648 has v0 = one of ret(nic_setup), ret(nic_mfg_next).

- `nic_vertex_info_get` in `IP27/usr/cpu/sysgen/IP27boot/nic.o` at 0x1650 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/nic.o`.
  Range: 0x1650-0x167c (44 bytes).
  It occupies 44 bytes.
  The `jal` at 0x1664 calls hwgraph_info_get_LBL with a0=a0 at entry (arg0), a1=sym(.rodata), a2=sp-16, a3=a3 at entry (arg3).
  The return at 0x1674 has v0 = ?.

- `nic_vertex_info_set` in `IP27/usr/cpu/sysgen/IP27boot/nic.o` at 0x167c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/nic.o`.
  Range: 0x167c-0x1788 (268 bytes).
  It occupies 268 bytes.
  The `jal` at 0x1694 calls nic_vertex_info_get with a0=a2 at entry (arg2), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x16bc calls kern_malloc with a0=0x800, a1=?, a2=?, a3=?.
  The `jal` at 0x16e0 calls nic_info_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=ret(kern_malloc), a3=?.
  The `jal` at 0x16e8 calls strlen with a0=ret(kern_malloc), a1=?, a2=?, a3=?.
  The `jal` at 0x16f8 calls kern_malloc with a0=(ret(strlen)+1 << 0x0), a1=?, a2=?, a3=?.
  The `jal` at 0x171c calls hwgraph_info_add_LBL with a0=a2 at entry (arg2), a1=sym(.rodata), a2=ret(kern_malloc), a3=?.
  The `jal` at 0x1724 calls nic_vertex_info_get with a0=a2 at entry (arg2), a1=?, a2=?, a3=?.
  The `jal` at 0x1734 calls kern_free with a0=ret(kern_malloc), a1=?, a2=?, a3=?.
  The `jal` at 0x1750 calls hwgraph_info_export_LBL with a0=a2 at entry (arg2), a1=sym(.rodata), a2=(ret(strlen)+1 << 0x0), a3=?.
  The `jal` at 0x175c calls nic_vmc_check with a0=a2 at entry (arg2), a1=ret(kern_malloc), a2=?, a3=?.
  The `jal` at 0x1770 calls strcpy with a0=ret(kern_malloc), a1=ret(kern_malloc), a2=?, a3=?.
  The `jal` at 0x1778 calls kern_free with a0=ret(kern_malloc), a1=?, a2=?, a3=?.
  The `beq` branch at 0x169c targets 0x16b8, is taken when v0(=ret(nic_vertex_info_get)) == 0, and falls through when v0(=ret(nic_vertex_info_get)) != 0.
  The `bne` branch at 0x16c4 targets 0x16d8, is taken when v0(=ret(kern_malloc)) != 0, and falls through when v0(=ret(kern_malloc)) == 0.
  The `beq` branch at 0x16d0 targets 0x16a4 and is always taken.
  The `bne` branch at 0x1700 targets 0x176c, is taken when v0(=ret(kern_malloc)) != 0, and falls through when v0(=ret(kern_malloc)) == 0.
  The `beq` branch at 0x172c targets 0x1744, is taken when v0(=ret(nic_vertex_info_get)) == s0(=ret(kern_malloc)), and falls through when v0(=ret(nic_vertex_info_get)) != s0(=ret(kern_malloc)).
  The `beq` branch at 0x173c targets 0x16a4 and is always taken.
  The `beq` branch at 0x1764 targets 0x16a4 and is always taken.
  The `beq` branch at 0x1780 targets 0x1710 and is always taken.
  The return at 0x16b0 has v0 = one of ret(nic_vertex_info_get), 0x0, ret(kern_malloc).

- `nic_vertex_info_match` in `IP27/usr/cpu/sysgen/IP27boot/nic.o` at 0x1788 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/nic.o`.
  Range: 0x1788-0x17c4 (60 bytes).
  It occupies 60 bytes.
  The `jal` at 0x1790 calls nic_vertex_info_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x17b4 calls strstr with a0=ret(nic_vertex_info_get), a1=a1 at entry (arg1), a2=?, a3=?.
  The `bne` branch at 0x1798 targets 0x17b0, is taken when v0(=ret(nic_vertex_info_get)) != 0, and falls through when v0(=ret(nic_vertex_info_get)) == 0.
  The `beq` branch at 0x17bc targets 0x17a0 and is always taken.
  The return at 0x17a8 has v0 = one of 0x0, ?.

- `nic_access_hub` in `IP27/usr/cpu/sysgen/IP27boot/nic.o` at 0x17c4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/nic.o`.
  Range: 0x17c4-0x18c8 (260 bytes).
  It occupies 260 bytes.
  2 such `lh` accesses load 2 bytes from abs 0xffffffffffffc420, including `lh` at 0x17e8, `lh` at 0x1830.
  2 such `ld` accesses load 8 bytes from (sym(pdaindr) + ([-0x3be0]:2 << 0x4)) +0x8, including `ld` at 0x17f8, `ld` at 0x183c.
  2 such `lh` accesses load 2 bytes from [(sym(pdaindr) + ([-0x3be0]:2 << 0x4))+8]:8 +0x422, including `lh` at 0x17fc, `lh` at 0x1840.
  2 such `lh` accesses load 2 bytes from (sym(compact_to_nasid_node) + ([[(sym(pdaindr) + ([-0x3be0]:2 << 0x4))+8]:8+1058]:2 + [[(sym(pdaindr) + ([-0x3be0]:2 << 0x4))+8]:8+1058]:2)) +0x0, including `lh` at 0x1810, `lh` at 0x184c.
  The `sd` at 0x182c stores 8 bytes to ?.
  5 such `ld` accesses load 8 bytes from ?, including `ld` at 0x1858, `ld` at 0x1868, `ld` at 0x1878.
  The `jal` at 0x17e0 calls nic_get_phase_bits with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x18a8 calls us_delay with a0=a3 at entry (arg3), a1=?, a2=?, a3=?, a7=([(sym(compact_to_nasid_node) + ([[(sym(pdaindr) + ([-0x3be0]:2 << 0x4))+8]:8+1058]:2 + [[(sym(pdaindr) + ([-0x3be0]:2 << 0x4))+8]:8+1058]:2))]:2 << 0x20).
  The `bne` branch at 0x1860 targets 0x18a8, is taken when (s0(?) & 0x2) != 0, and falls through when (s0(?) & 0x2) == 0.
  The `bne` branch at 0x1870 targets 0x18a8, is taken when (s0(?) & 0x2) != 0, and falls through when (s0(?) & 0x2) == 0.
  The `bne` branch at 0x1880 targets 0x18a8, is taken when (s0(?) & 0x2) != 0, and falls through when (s0(?) & 0x2) == 0.
  The `bne` branch at 0x1890 targets 0x18a8, is taken when (s0(?) & 0x2) != 0, and falls through when (s0(?) & 0x2) == 0.
  The `beq` branch at 0x18a0 targets 0x1858, is taken when (s0(?) & 0x2) == 0, and falls through when (s0(?) & 0x2) != 0.
  The return at 0x18c0 has v0 = ?.

- `nic_hub_vertex_info` in `IP27/usr/cpu/sysgen/IP27boot/nic.o` at 0x18c8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/nic.o`.
  Range: 0x18c8-0x18ec (36 bytes).
  It occupies 36 bytes.
  The `jal` at 0x18d8 calls nic_vertex_info_set with a0=sym(nic_access_hub), a1=0x0, a2=a0 at entry (arg0), a3=a3 at entry (arg3).
  The return at 0x18e4 has v0 = ret(nic_vertex_info_set).

- `nic_bridge_vertex_info` in `IP27/usr/cpu/sysgen/IP27boot/nic.o` at 0x18ec (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/nic.o`.
  Range: 0x18ec-0x190c (32 bytes).
  It occupies 32 bytes.
  The `jal` at 0x18f8 calls nic_vertex_info_set with a0=sym(nic_access_mcr32), a1=a1 at entry (arg1), a2=a0 at entry (arg0), a3=a3 at entry (arg3).
  The return at 0x1904 has v0 = ret(nic_vertex_info_set).

- `nic_hq4_vertex_info` in `IP27/usr/cpu/sysgen/IP27boot/nic.o` at 0x190c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/nic.o`.
  Range: 0x190c-0x192c (32 bytes).
  It occupies 32 bytes.
  The `jal` at 0x1918 calls nic_vertex_info_set with a0=sym(nic_access_mcr32), a1=a1 at entry (arg1), a2=a0 at entry (arg0), a3=a3 at entry (arg3).
  The return at 0x1924 has v0 = ret(nic_vertex_info_set).

- `nic_ioc3_vertex_info` in `IP27/usr/cpu/sysgen/IP27boot/nic.o` at 0x192c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/nic.o`.
  Range: 0x192c-0x195c (48 bytes).
  It occupies 48 bytes.
  The `sw` at 0x1940 stores 4 bytes to a2 (arg2 at entry) +0x0.
  The `jal` at 0x1948 calls nic_vertex_info_set with a0=sym(nic_access_mcr32), a1=a1 at entry (arg1), a2=a0 at entry (arg0), a3=a3 at entry (arg3), a4=a0 at entry (arg0), a5=0x200000.
  The `beq` branch at 0x1938 targets 0x1944, is taken when a2 == 0, and falls through when a2 != 0.
  The return at 0x1954 has v0 = ret(nic_vertex_info_set).

- `nic_vmc_add` in `IP27/usr/cpu/sysgen/IP27boot/nic.o` at 0x195c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/nic.o`.
  Range: 0x195c-0x19b4 (88 bytes).
  It occupies 88 bytes.
  The `sd` at 0x197c stores 8 bytes to ret(kern_malloc) +0x0.
  The `sd` at 0x1980 stores 8 bytes to ret(kern_malloc) +0x8.
  The `sd` at 0x1994 stores 8 bytes to ret(kern_malloc) +0x10.
  The `sd` at 0x19a8 stores 8 bytes to ret(swap_ptr) +0x0.
  The `jal` at 0x1970 calls kern_malloc with a0=0x18, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1990 calls swap_ptr with a0=sym(.sdata)+8, a1=ret(kern_malloc), a2=?, a3=?.
  The return at 0x19ac has v0 = ret(kern_malloc).

- `nic_vmc_del` in `IP27/usr/cpu/sysgen/IP27boot/nic.o` at 0x19b4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/nic.o`.
  Range: 0x19b4-0x19c0 (12 bytes).
  It occupies 12 bytes.
  The `sd` at 0x19b4 stores 8 bytes to a0 (arg0 at entry) +0x10.
  The `sd` at 0x19bc stores 8 bytes to a0 (arg0 at entry) +0x8.
  The return at 0x19b8 has v0 = ?.

- `nic_vmc_check` in `IP27/usr/cpu/sysgen/IP27boot/nic.o` at 0x19c0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/nic.o`.
  Range: 0x19c0-0x1a60 (160 bytes).
  It occupies 160 bytes.
  5 such `ld` accesses load 8 bytes from ?, including `ld` at 0x1a04, `ld` at 0x1a10, `ld` at 0x1a1c.
  The `jal` at 0x19f4 calls strstr with a0=a1 at entry (arg1), a1=?, a2=?, a3=?.
  The `jalr` at 0x1a50 calls (unknown callee) with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `bne` branch at 0x19e4 targets 0x1a10, is taken when at(=[sym(.sdata)]:8) != 0, and falls through when at(=[sym(.sdata)]:8) == 0.
  The `beq` branch at 0x19ec targets 0x1a34 and is always taken.
  The `bne` branch at 0x19fc targets 0x1a50, is taken when v0(=ret(strstr)) != 0, and falls through when v0(=ret(strstr)) == 0.
  The `beq` branch at 0x1a08 targets 0x1a34, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0x1a14 targets 0x1a28, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `bne` branch at 0x1a20 targets 0x19f4, is taken when a1(?) != 0, and falls through when a1(?) == 0.
  The `bne` branch at 0x1a2c targets 0x1a10, is taken when s0(?) != 0, and falls through when s0(?) == 0.
  The `beq` branch at 0x1a58 targets 0x1a08 and is always taken.
  The return at 0x1a48 has v0 = ?.
