# Readings: `IP30/usr/cpu/sysgen/IP30boot/nic.o`

One entry per routine, filed here from the reading batches by binary.

- `nic_next_scan` in `IP30/usr/cpu/sysgen/IP30boot/nic.o` at 0x1dc (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/nic.o`.
  Range: 0x1dc-0x3c0 (484 bytes).
  It occupies 484 bytes.
  The `lw` at 0x1dc loads 4 bytes from a0 (arg0 at entry) +0x14.
  3 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x1c, including `sw` at 0x22c, `sw` at 0x350, `sw` at 0x384.
  3 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x18, including `sw` at 0x238, `sw` at 0x284, `sw` at 0x308.
  7 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x18, including `lw` at 0x24c, `lw` at 0x258, `lw` at 0x274.
  3 such `sb` accesses store 1 byte to ([a0+24] + a0) +0x1f, including `sb` at 0x254, `sb` at 0x2d8, `sb` at 0x344.
  5 such `lbu` accesses load 1 byte from ([a0+24] + a0) +0x1f, including `lbu` at 0x268, `lbu` at 0x2e4, `lbu` at 0x358.
  The `lw` at 0x2c8 loads 4 bytes from a0 (arg0 at entry) +0x10.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x1c, including `lw` at 0x30c, `lw` at 0x35c.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x10, including `sw` at 0x314, `sw` at 0x364.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x14, including `sw` at 0x398, `sw` at 0x3b4.
  The `jal` at 0x208 calls nic_presence with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x234 calls nic_write_byte with a0=a0 at entry (arg0), a1=0xf0, a2=?, a3=?.
  The `jal` at 0x264 calls nic_write with a0=a0 at entry (arg0), a1=[([a0+24] + a0)+31]:1, a2=([a0+24] + a0), a3=?, a4=ret(nic_read).
  The `jal` at 0x288 calls nic_read with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x29c calls nic_read with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x2e8 calls nic_write with a0=a0 at entry (arg0), a1=[([a0+24] + a0)+31]:1, a2=?, a3=?, a4=[a0+24].
  The `beq` branch at 0x1f0 targets 0x208, is taken when at(=[a0+20]) == 0, and falls through when at(=[a0+20]) != 0.
  The `bltz` branch at 0x210 targets 0x320, is taken when v0(=ret(nic_presence)) < 0 (signed), and falls through when v0(=ret(nic_presence)) >= 0 (signed).
  The `beq` branch at 0x218 targets 0x228, is taken when v0(=ret(nic_presence)) == 0, and falls through when v0(=ret(nic_presence)) != 0.
  The `beq` branch at 0x220 targets 0x1f8 and is always taken.
  The `bgez` branch at 0x23c targets 0x288, is taken when v0(=ret(nic_write_byte)) >= 0 (signed), and falls through when v0(=ret(nic_write_byte)) < 0 (signed).
  The `beq` branch at 0x244 targets 0x1fc and is always taken.
  The `bltz` branch at 0x26c targets 0x3a4, is taken when v0(=ret(nic_write)) < 0 (signed), and falls through when v0(=ret(nic_write)) >= 0 (signed).
  The `beq` branch at 0x280 targets 0x35c, is taken when a3(=[a0+24]) >= 0x40 (signed), and falls through when a3(=[a0+24]) < 0x40 (signed).
  The `bltz` branch at 0x294 targets 0x370, is taken when v0(=ret(nic_read)) < 0 (signed), and falls through when v0(=ret(nic_read)) >= 0 (signed).
  The `bltz` branch at 0x2a8 targets 0x39c, is taken when v0(=ret(nic_read)) < 0 (signed), and falls through when v0(=ret(nic_read)) >= 0 (signed).
  The `beq` branch at 0x2b0 targets 0x328, is taken when a4(=ret(nic_read)) == a0(=0x1), and falls through when a4(=ret(nic_read)) != a0(=0x1).
  The `bne` branch at 0x2b8 targets 0x24c, is taken when a4(=ret(nic_read)) != 0, and falls through when a4(=ret(nic_read)) == 0.
  The `bne` branch at 0x2c0 targets 0x24c, is taken when v0(=ret(nic_read)) != 0, and falls through when v0(=ret(nic_read)) == 0.
  The `bne` branch at 0x2d0 targets 0x338, is taken when a1(=[a0+16]) != a4(=[a0+24]), and falls through when a1(=[a0+16]) == a4(=[a0+24]).
  The `bltz` branch at 0x2f0 targets 0x3b8, is taken when v0(=ret(nic_write)) < 0 (signed), and falls through when v0(=ret(nic_write)) >= 0 (signed).
  The `bne` branch at 0x304 targets 0x288, is taken when a2(=[a0+24]) < 0x40 (signed), and falls through when a2(=[a0+24]) >= 0x40 (signed).
  The `beq` branch at 0x310 targets 0x3ac, is taken when a3(=[a0+28]) == 0, and falls through when a3(=[a0+28]) != 0.
  The `beq` branch at 0x318 targets 0x1f8 and is always taken.
  The `beq` branch at 0x320 targets 0x1fc and is always taken.
  The `bne` branch at 0x328 targets 0x2b8, is taken when v0(=ret(nic_read)) != a0(=0x1), and falls through when v0(=ret(nic_read)) == a0(=0x1).
  The `beq` branch at 0x330 targets 0x1f8 and is always taken.
  The `beq` branch at 0x33c targets 0x378, is taken when a1(=[a0+16]) >= a4(=[a0+24]) (signed), and falls through when a1(=[a0+16]) < a4(=[a0+24]) (signed).
  The `beq` branch at 0x354 targets 0x2e8 and is always taken.
  The `beq` branch at 0x360 targets 0x390, is taken when a3(=[a0+28]) == 0, and falls through when a3(=[a0+28]) != 0.
  The `beq` branch at 0x368 targets 0x1f8 and is always taken.
  The `beq` branch at 0x370 targets 0x1fc and is always taken.
  The `bne` branch at 0x37c targets 0x2e8, is taken when a1(=[([a0+24] + a0)+31]:1) != 0, and falls through when a1(=[([a0+24] + a0)+31]:1) == 0.
  The `beq` branch at 0x388 targets 0x2e8 and is always taken.
  The `beq` branch at 0x394 targets 0x368 and is always taken.
  The `beq` branch at 0x39c targets 0x1fc and is always taken.
  The `beq` branch at 0x3a4 targets 0x1fc and is always taken.
  The `beq` branch at 0x3b0 targets 0x318 and is always taken.
  The `beq` branch at 0x3b8 targets 0x1fc and is always taken.
  The return at 0x200 has v0 = one of 0x0, 0x1, 0x2, 0x4, ret(nic_write_byte), ret(nic_presence), ret(nic_read), ret(nic_write).

- `nic_setup` in `IP30/usr/cpu/sysgen/IP30boot/nic.o` at 0x3c0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/nic.o`.
  Range: 0x3c0-0x3e8 (40 bytes).
  It occupies 40 bytes.
  The `sd` at 0x3c0 stores 8 bytes to a0 (arg0 at entry) +0x0.
  The `sd` at 0x3c4 stores 8 bytes to a0 (arg0 at entry) +0x8.
  The `sw` at 0x3c8 stores 4 bytes to a0 (arg0 at entry) +0x10.
  The `sw` at 0x3d8 stores 4 bytes to a0 (arg0 at entry) +0x14.
  The `jal` at 0x3d4 calls nic_presence with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x3e0 has v0 = ret(nic_presence).

- `nic_next` in `IP30/usr/cpu/sysgen/IP30boot/nic.o` at 0x3e8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/nic.o`.
  Range: 0x3e8-0x578 (400 bytes).
  It occupies 400 bytes.
  4 such `sb` accesses store 1 byte to ?, including `sb` at 0x444, `sb` at 0x458, `sb` at 0x470.
  3 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x48c, `lbu` at 0x498, `lbu` at 0x4c8.
  The `lw` at 0x4dc loads 4 bytes from ?.
  The `sb` at 0x520 stores 1 byte to a1 (arg1 at entry) +0x4.
  The `sb` at 0x524 stores 1 byte to a1 (arg1 at entry) +0x0.
  The `sb` at 0x538 stores 1 byte to a1 (arg1 at entry) +0x1.
  The `sb` at 0x53c stores 1 byte to a1 (arg1 at entry) +0x2.
  The `sb` at 0x540 stores 1 byte to a1 (arg1 at entry) +0x3.
  The `sb` at 0x548 stores 1 byte to a1 (arg1 at entry) +0x5.
  The `sb` at 0x554 stores 1 byte to a3 (arg3 at entry) +0x0.
  The `sb` at 0x56c stores 1 byte to a2 (arg2 at entry) +0x0.
  The `jal` at 0x408 calls nic_next_scan with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0x414 targets 0x430, is taken when v0(=ret(nic_next_scan)) == 0, and falls through when v0(=ret(nic_next_scan)) != 0.
  The `beq` branch at 0x448 targets 0x474, is taken when a6(?) >= 0x8 (signed), and falls through when a6(?) < 0x8 (signed).
  The `beq` branch at 0x45c targets 0x474, is taken when a6(?) >= 0x8 (signed), and falls through when a6(?) < 0x8 (signed).
  The `bne` branch at 0x46c targets 0x438, is taken when a6(?) < 0x8 (signed), and falls through when a6(?) >= 0x8 (signed).
  The `bne` branch at 0x4ac targets 0x478, is taken when a6(?) < 0x40 (signed), and falls through when a6(?) >= 0x40 (signed).
  The `bne` branch at 0x4f8 targets 0x4c4, is taken when a7(?) < 0x8 (signed), and falls through when a7(?) >= 0x8 (signed).
  The `beq` branch at 0x500 targets 0x510, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `beq` branch at 0x508 targets 0x420 and is always taken.
  The `beq` branch at 0x514 targets 0x560, is taken when t8(=a1) == 0, and falls through when t8(=a1) != 0.
  The `bne` branch at 0x544 targets 0x568, is taken when s2(=a2) != 0, and falls through when s2(=a2) == 0.
  The `beq` branch at 0x54c targets 0x558, is taken when s1(=a3) == 0, and falls through when s1(=a3) != 0.
  The `beq` branch at 0x558 targets 0x41c and is always taken.
  The `beq` branch at 0x560 targets 0x54c, is taken when s2(=a2) == 0, and falls through when s2(=a2) != 0.
  The `bne` branch at 0x568 targets 0x550, is taken when s1(=a3) != 0, and falls through when s1(=a3) == 0.
  The `beq` branch at 0x570 targets 0x558 and is always taken.
  The return at 0x428 has v0 = one of ?, 0x3.

- `nic_match_rom` in `IP30/usr/cpu/sysgen/IP30boot/nic.o` at 0x578 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/nic.o`.
  Range: 0x578-0x6b4 (316 bytes).
  It occupies 316 bytes.
  The `lbu` at 0x5e4 loads 1 byte from a1 (arg1 at entry) +0x0.
  The `lbu` at 0x5f4 loads 1 byte from a2 (arg2 at entry) +0x5.
  The `lbu` at 0x604 loads 1 byte from a2 (arg2 at entry) +0x4.
  The `lbu` at 0x614 loads 1 byte from a2 (arg2 at entry) +0x3.
  The `lbu` at 0x624 loads 1 byte from a2 (arg2 at entry) +0x2.
  The `lbu` at 0x634 loads 1 byte from a2 (arg2 at entry) +0x1.
  The `lbu` at 0x644 loads 1 byte from a2 (arg2 at entry) +0x0.
  The `lbu` at 0x658 loads 1 byte from a3 (arg3 at entry) +0x0.
  The `jal` at 0x594 calls nic_presence with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x5ac calls printf with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jal` at 0x5cc calls nic_write_byte with a0=a0 at entry (arg0), a1=0x55, a2=?, a3=?.
  The `jal` at 0x5e0 calls nic_write_byte with a0=a0 at entry (arg0), a1=[a1]:1, a2=?, a3=?.
  The `jal` at 0x5f0 calls nic_write_byte with a0=a0 at entry (arg0), a1=[a2+5]:1, a2=?, a3=?.
  The `jal` at 0x600 calls nic_write_byte with a0=a0 at entry (arg0), a1=[a2+4]:1, a2=?, a3=?.
  The `jal` at 0x610 calls nic_write_byte with a0=a0 at entry (arg0), a1=[a2+3]:1, a2=?, a3=?.
  The `jal` at 0x620 calls nic_write_byte with a0=a0 at entry (arg0), a1=[a2+2]:1, a2=?, a3=?.
  The `jal` at 0x630 calls nic_write_byte with a0=a0 at entry (arg0), a1=[a2+1]:1, a2=?, a3=?.
  The `jal` at 0x640 calls nic_write_byte with a0=a0 at entry (arg0), a1=[a2]:1, a2=?, a3=?.
  The `jal` at 0x654 calls nic_write_byte with a0=a0 at entry (arg0), a1=[a3]:1, a2=?, a3=?.
  The `bltz` branch at 0x59c targets 0x5b8, is taken when v0(=ret(nic_presence)) < 0 (signed), and falls through when v0(=ret(nic_presence)) >= 0 (signed).
  The `beq` branch at 0x5a4 targets 0x5cc, is taken when v0(=ret(nic_presence)) == 0, and falls through when v0(=ret(nic_presence)) != 0.
  The `bltz` branch at 0x5d4 targets 0x66c, is taken when v0(=ret(nic_write_byte)) < 0 (signed), and falls through when v0(=ret(nic_write_byte)) >= 0 (signed).
  The `bltz` branch at 0x5e8 targets 0x674, is taken when v0(=ret(nic_write_byte)) < 0 (signed), and falls through when v0(=ret(nic_write_byte)) >= 0 (signed).
  The `bltz` branch at 0x5f8 targets 0x67c, is taken when v0(=ret(nic_write_byte)) < 0 (signed), and falls through when v0(=ret(nic_write_byte)) >= 0 (signed).
  The `bltz` branch at 0x608 targets 0x684, is taken when v0(=ret(nic_write_byte)) < 0 (signed), and falls through when v0(=ret(nic_write_byte)) >= 0 (signed).
  The `bltz` branch at 0x618 targets 0x68c, is taken when v0(=ret(nic_write_byte)) < 0 (signed), and falls through when v0(=ret(nic_write_byte)) >= 0 (signed).
  The `bltz` branch at 0x628 targets 0x694, is taken when v0(=ret(nic_write_byte)) < 0 (signed), and falls through when v0(=ret(nic_write_byte)) >= 0 (signed).
  The `bltz` branch at 0x638 targets 0x69c, is taken when v0(=ret(nic_write_byte)) < 0 (signed), and falls through when v0(=ret(nic_write_byte)) >= 0 (signed).
  The `bltz` branch at 0x648 targets 0x6a4, is taken when v0(=ret(nic_write_byte)) < 0 (signed), and falls through when v0(=ret(nic_write_byte)) >= 0 (signed).
  The `bltz` branch at 0x65c targets 0x6ac, is taken when v0(=ret(nic_write_byte)) < 0 (signed), and falls through when v0(=ret(nic_write_byte)) >= 0 (signed).
  The `beq` branch at 0x664 targets 0x5b8 and is always taken.
  The `beq` branch at 0x66c targets 0x5bc and is always taken.
  The `beq` branch at 0x674 targets 0x5bc and is always taken.
  The `beq` branch at 0x67c targets 0x5bc and is always taken.
  The `beq` branch at 0x684 targets 0x5bc and is always taken.
  The `beq` branch at 0x68c targets 0x5bc and is always taken.
  The `beq` branch at 0x694 targets 0x5bc and is always taken.
  The `beq` branch at 0x69c targets 0x5bc and is always taken.
  The `beq` branch at 0x6a4 targets 0x5bc and is always taken.
  The `beq` branch at 0x6ac targets 0x5bc and is always taken.
  The return at 0x5c4 has v0 = one of ?, ret(nic_write_byte).

- `nic_read_one_page` in `IP30/usr/cpu/sysgen/IP30boot/nic.o` at 0x6b4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/nic.o`.
  Range: 0x6b4-0x844 (400 bytes).
  It occupies 400 bytes.
  The `lbu` at 0x6cc loads 1 byte from (a4 + a5) +0x0.
  2 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x708, `lbu` at 0x7c4.
  The `lbu` at 0x784 loads 1 byte from a1 (arg1 at entry) +0x0.
  The `sb` at 0x7ac stores 1 byte to ?.
  The `jal` at 0x718 calls nic_match_rom with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x744 calls nic_write_byte with a0=a0 at entry (arg0), a1=0xf0, a2=?, a3=?.
  The `jal` at 0x75c calls nic_write_byte with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x774 calls nic_write_byte with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x790 calls nic_read_byte with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x7c0 calls crc16 with a0=?, a1=sp-64, a2=?, a3=?.
  The `jal` at 0x7f4 calls printf with a0=sym(.rodata), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x814 calls nic_read_byte with a0=a0 at entry (arg0), a1=?, a2=[a1]:1, a3=0x9.
  The `beq` branch at 0x6ec targets 0x714, is taken when t1(=0xff) == t2(=[(a4 + a5)]:1), and falls through when t1(=0xff) != t2(=[(a4 + a5)]:1).
  The `beq` branch at 0x6fc targets 0x7f0, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `bne` branch at 0x70c targets 0x6f8, is taken when t1(=0xff) != t0(?), and falls through when t1(=0xff) == t0(?).
  The `beq` branch at 0x720 targets 0x744, is taken when v0(=ret(nic_match_rom)) == 0, and falls through when v0(=ret(nic_match_rom)) != 0.
  The `bltz` branch at 0x74c targets 0x804, is taken when v0(=ret(nic_write_byte)) < 0 (signed), and falls through when v0(=ret(nic_write_byte)) >= 0 (signed).
  The `bltz` branch at 0x764 targets 0x80c, is taken when v0(=ret(nic_write_byte)) < 0 (signed), and falls through when v0(=ret(nic_write_byte)) >= 0 (signed).
  The `bltz` branch at 0x77c targets 0x83c, is taken when v0(=ret(nic_write_byte)) < 0 (signed), and falls through when v0(=ret(nic_write_byte)) >= 0 (signed).
  The `beq` branch at 0x788 targets 0x814, is taken when a2(=[a1]:1) == a3(=0x9), and falls through when a2(=[a1]:1) != a3(=0x9).
  The `bltz` branch at 0x798 targets 0x82c, is taken when v0(=ret(nic_read_byte)) < 0 (signed), and falls through when v0(=ret(nic_read_byte)) >= 0 (signed).
  The `bne` branch at 0x7a8 targets 0x790, is taken when s0(?) < 0x20 (signed), and falls through when s0(?) >= 0x20 (signed).
  The `bne` branch at 0x7d0 targets 0x7bc, is taken when s0(?) < 0x20 (signed), and falls through when s0(?) >= 0x20 (signed).
  The `beq` branch at 0x7e0 targets 0x834, is taken when a2(?) == a3(=0xb001), and falls through when a2(?) != a3(=0xb001).
  The `beq` branch at 0x7e8 targets 0x72c and is always taken.
  The `beq` branch at 0x7fc targets 0x728 and is always taken.
  The `beq` branch at 0x804 targets 0x72c and is always taken.
  The `beq` branch at 0x80c targets 0x72c and is always taken.
  The `bgez` branch at 0x81c targets 0x790, is taken when v0(=ret(nic_read_byte)) >= 0 (signed), and falls through when v0(=ret(nic_read_byte)) < 0 (signed).
  The `beq` branch at 0x824 targets 0x72c and is always taken.
  The `beq` branch at 0x82c targets 0x72c and is always taken.
  The `beq` branch at 0x834 targets 0x728 and is always taken.
  The `beq` branch at 0x83c targets 0x72c and is always taken.
  The return at 0x73c has v0 = one of ?, 0x3, ret(nic_write_byte), ret(nic_read_byte).

- `nic_read_mfg` in `IP30/usr/cpu/sysgen/IP30boot/nic.o` at 0x844 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/nic.o`.
  Range: 0x844-0xb58 (788 bytes).
  It occupies 788 bytes.
  The `lbu` at 0x868 loads 1 byte from a1 (arg1 at entry) +0x0.
  6 such `sb` accesses store 1 byte to ?, including `sb` at 0x8a8, `sb` at 0x8c0, `sb` at 0x8d8.
  3 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x9ec, `lbu` at 0xa30, `lbu` at 0xa50.
  The `jal` at 0x8f4 calls nic_read_one_page with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a4=0x0, a5=sp-208, a6=a4 at entry (arg4).
  The `jal` at 0x934 calls nic_match_rom with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x964 calls nic_read_one_page with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a4=0x1, a5=sp-208, a6=a5 at entry (arg5).
  The `jal` at 0x97c calls nic_write_byte with a0=a0 at entry (arg0), a1=0xaa, a2=?, a3=?.
  The `jal` at 0x990 calls nic_write_byte with a0=a0 at entry (arg0), a1=0x0, a2=?, a3=?.
  The `jal` at 0x9a4 calls nic_write_byte with a0=a0 at entry (arg0), a1=0x1, a2=?, a3=?.
  The `jal` at 0x9c8 calls crc16 with a0=0x0, a1=sp-112, a2=?, a3=?.
  The `jal` at 0x9d4 calls crc16 with a0=0x1, a1=sp-112, a2=?, a3=?.
  The `jal` at 0x9e8 calls crc16 with a0=?, a1=sp-112, a2=?, a3=?.
  The `jal` at 0xa74 calls nic_read_byte with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xaa8 calls crc16 with a0=0xaa, a1=sp-112, a2=?, a3=?.
  The `jal` at 0xad8 calls printf with a0=sym(.rodata), a1=?, a2=0xb001, a3=?.
  The `jal` at 0xb00 calls nic_read_one_page with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a4=0x0, a5=sp-208, a6=a4 at entry (arg4).
  The `jal` at 0xb28 calls nic_read_one_page with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a4=0x1, a5=sp-208, a6=a5 at entry (arg5).
  The `bne` branch at 0x888 targets 0x934, is taken when at(=[a1]:1) != v0(=0x9), and falls through when at(=[a1]:1) == v0(=0x9).
  The `beq` branch at 0x8ac targets 0x8e0, is taken when v0(?) >= 0x40 (signed), and falls through when v0(?) < 0x40 (signed).
  The `beq` branch at 0x8c4 targets 0x8dc, is taken when v0(?) >= 0x40 (signed), and falls through when v0(?) < 0x40 (signed).
  The `bne` branch at 0x8d4 targets 0x89c, is taken when v0(?) < 0x40 (signed), and falls through when v0(?) >= 0x40 (signed).
  The `beq` branch at 0x8fc targets 0x94c, is taken when v0(=ret(nic_read_one_page)) == 0, and falls through when v0(=ret(nic_read_one_page)) != 0.
  The `beq` branch at 0x93c targets 0x978, is taken when v0(=ret(nic_match_rom)) == 0, and falls through when v0(=ret(nic_match_rom)) != 0.
  The `beq` branch at 0x944 targets 0x908 and is always taken.
  The `beq` branch at 0x970 targets 0x904 and is always taken.
  The `bltz` branch at 0x984 targets 0xac0, is taken when v0(=ret(nic_write_byte)) < 0 (signed), and falls through when v0(=ret(nic_write_byte)) >= 0 (signed).
  The `bltz` branch at 0x998 targets 0xac8, is taken when v0(=ret(nic_write_byte)) < 0 (signed), and falls through when v0(=ret(nic_write_byte)) >= 0 (signed).
  The `bltz` branch at 0x9b0 targets 0xb40, is taken when v0(=ret(nic_write_byte)) < 0 (signed), and falls through when v0(=ret(nic_write_byte)) >= 0 (signed).
  The `beq` branch at 0x9c0 targets 0xa70 and is always taken.
  The `bne` branch at 0x9f8 targets 0x9e0, is taken when s2(?) < 0xa (signed), and falls through when s2(?) >= 0xa (signed).
  The `bne` branch at 0xa04 targets 0xad0, is taken when a2(=0xb001) != a3(?), and falls through when a2(=0xb001) == a3(?).
  The `beq` branch at 0xa3c targets 0xa60, is taken when v0(?) >= 0x8 (signed), and falls through when v0(?) < 0x8 (signed).
  The `bne` branch at 0xa58 targets 0xa20, is taken when v0(?) < 0x8 (signed), and falls through when v0(?) >= 0x8 (signed).
  The `beq` branch at 0xa68 targets 0xae8, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `bltz` branch at 0xa80 targets 0xab8, is taken when v0(=ret(nic_read_byte)) < 0 (signed), and falls through when v0(=ret(nic_read_byte)) >= 0 (signed).
  The `bne` branch at 0xa90 targets 0xa74, is taken when s2(?) < 0xa (signed), and falls through when s2(?) >= 0xa (signed).
  The `bne` branch at 0xa9c targets 0x9dc, is taken when t0(?) != 0, and falls through when t0(?) == 0.
  The `beq` branch at 0xab0 targets 0x9c8 and is always taken.
  The `beq` branch at 0xab8 targets 0x908 and is always taken.
  The `beq` branch at 0xac0 targets 0x908 and is always taken.
  The `beq` branch at 0xac8 targets 0x908 and is always taken.
  The `beq` branch at 0xae0 targets 0x904 and is always taken.
  The `bltz` branch at 0xb08 targets 0xb48, is taken when v0(=ret(nic_read_one_page)) < 0 (signed), and falls through when v0(=ret(nic_read_one_page)) >= 0 (signed).
  The `bltz` branch at 0xb30 targets 0xb50, is taken when v0(=ret(nic_read_one_page)) < 0 (signed), and falls through when v0(=ret(nic_read_one_page)) >= 0 (signed).
  The `beq` branch at 0xb38 targets 0x904 and is always taken.
  The `beq` branch at 0xb40 targets 0x908 and is always taken.
  The `beq` branch at 0xb48 targets 0x908 and is always taken.
  The `beq` branch at 0xb50 targets 0x908 and is always taken.
  The return at 0x92c has v0 = one of ?, ret(nic_match_rom), ret(nic_read_byte), ret(nic_write_byte), ret(nic_read_one_page).

- `char2hex` in `IP30/usr/cpu/sysgen/IP30boot/nic.o` at 0xb58 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/nic.o`.
  Range: 0xb58-0xbd8 (128 bytes).
  It occupies 128 bytes.
  The `ld` at 0xb60 loads 8 bytes from sym(.rodata) +0xb8.
  The `ld` at 0xb6c loads 8 bytes from sym(.rodata) +0xc0.
  The `lbu` at 0xb74 loads 1 byte from sym(.rodata) +0xc8.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0xb94, `lw` at 0xbbc.
  The `sb` at 0xbb4 stores 1 byte to a0 (arg0 at entry) +0x0.
  The `sb` at 0xbd4 stores 1 byte to a0 (arg0 at entry) +0x1.
  The return at 0xbd0 has v0 = ?.

- `chars2hex` in `IP30/usr/cpu/sysgen/IP30boot/nic.o` at 0xbd8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/nic.o`.
  Range: 0xbd8-0xc64 (140 bytes).
  It occupies 140 bytes.
  The `lbu` at 0xc24 loads 1 byte from ?.
  The `sb` at 0xc60 stores 1 byte to ((ret(strlen) + a0) + (a2 + a2)) +0x0.
  The `jal` at 0xbf4 calls strlen with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xc20 calls char2hex with a0=?, a1=?, a2=?, a3=?.
  The `blez` branch at 0xc08 targets 0xc38, is taken when s3(=a2) <= 0 (signed), and falls through when s3(=a2) > 0 (signed).
  The `bne` branch at 0xc30 targets 0xc14, is taken when s1(?) < s3(=a2) (signed), and falls through when s1(?) >= s3(=a2) (signed).
  The return at 0xc5c has v0 = one of ret(strlen), ret(char2hex).

- `chars2print` in `IP30/usr/cpu/sysgen/IP30boot/nic.o` at 0xc64 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/nic.o`.
  Range: 0xc64-0xd70 (268 bytes).
  It occupies 268 bytes.
  6 such `sb` accesses store 1 byte to ?, including `sb` at 0xcd0, `sb` at 0xd14, `sb` at 0xd24.
  2 such `lbu` accesses load 1 byte from ?, including `lbu` at 0xce8, `lbu` at 0xd18.
  The `lbu` at 0xd6c loads 1 byte from a1 (arg1 at entry) +0x0.
  The `jal` at 0xc80 calls strlen with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `blez` branch at 0xcac targets 0xd3c, is taken when s1(=a2) <= 0 (signed), and falls through when s1(=a2) > 0 (signed).
  The `beq` branch at 0xcb4 targets 0xd64 and is always taken.
  The `bne` branch at 0xcc0 targets 0xcd0, is taken when at(?) != 0, and falls through when at(?) == 0.
  The `bne` branch at 0xcc8 targets 0xcdc, is taken when a5(?) != 0, and falls through when a5(?) == 0.
  The `beq` branch at 0xce0 targets 0xd3c, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0xcec targets 0xd24, is taken when a2(=0x3a) == a3(?), and falls through when a2(=0x3a) != a3(?).
  The `beq` branch at 0xcf4 targets 0xd24, is taken when a7(=0x3b) == a3(?), and falls through when a7(=0x3b) != a3(?).
  The `beq` branch at 0xcfc targets 0xd30, is taken when a1(=0xff) == a3(?), and falls through when a1(=0xff) != a3(?).
  The `bne` branch at 0xd04 targets 0xcbc, is taken when v1(?) != 0, and falls through when v1(?) == 0.
  The `beq` branch at 0xd0c targets 0xcc0, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `beq` branch at 0xd1c targets 0xcbc and is always taken.
  The `beq` branch at 0xd28 targets 0xcfc and is always taken.
  The `beq` branch at 0xd34 targets 0xd00 and is always taken.
  The `bne` branch at 0xd40 targets 0xd54, is taken when t3(=(ret(strlen) + a0)) != s0(?), and falls through when t3(=(ret(strlen) + a0)) == s0(?).
  The `beq` branch at 0xd68 targets 0xcec and is always taken.
  The return at 0xd5c has v0 = ?.

- `nic_eaddr` in `IP30/usr/cpu/sysgen/IP30boot/nic.o` at 0xd70 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/nic.o`.
  Range: 0xd70-0xfe4 (628 bytes).
  It occupies 628 bytes.
  2 such `sb` accesses store 1 byte to ?, including `sb` at 0xeb4, `sb` at 0xf68.
  3 such `lbu` accesses load 1 byte from ?, including `lbu` at 0xed0, `lbu` at 0xf24, `lbu` at 0xf60.
  The `jal` at 0xd94 calls nic_setup with a0=sp-176, a1=a0 at entry (arg0), a2=a1 at entry (arg1), a3=a3 at entry (arg3), a5=a1 at entry (arg1).
  The `jal` at 0xdac calls printf with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jal` at 0xdb4 calls printf with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jal` at 0xdd8 calls printf with a0=sym(.rodata), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a5=a1 at entry (arg1).
  The `jal` at 0xdf4 calls nic_next with a0=sp-176, a1=sp-48, a2=sp-42, a3=sp-41.
  The `jal` at 0xe64 calls nic_write_byte with a0=sp-176, a1=0xf0, a2=?, a3=?.
  The `jal` at 0xe74 calls nic_write_byte with a0=sp-176, a1=0x0, a2=?, a3=?.
  The `jal` at 0xe84 calls nic_write_byte with a0=sp-176, a1=0x0, a2=?, a3=?.
  The `jal` at 0xe94 calls nic_read_byte with a0=sp-176, a1=?, a2=?, a3=?.
  The `jal` at 0xecc calls crc16 with a0=?, a1=sp-40, a2=?, a3=?.
  The `jal` at 0xf20 calls crc16 with a0=?, a1=sp-40, a2=?, a3=?.
  The `beq` branch at 0xd84 targets 0xdd4, is taken when a2 == 0, and falls through when a2 != 0.
  The `beq` branch at 0xd9c targets 0xde8, is taken when v0(=ret(nic_setup)) == 0, and falls through when v0(=ret(nic_setup)) != 0.
  The `blez` branch at 0xda4 targets 0xdc0, is taken when v0(=ret(nic_setup)) <= 0 (signed), and falls through when v0(=ret(nic_setup)) > 0 (signed).
  The `beq` branch at 0xde0 targets 0xdc4 and is always taken.
  The `beq` branch at 0xdfc targets 0xe0c, is taken when v0(=ret(nic_next)) == 0, and falls through when v0(=ret(nic_next)) != 0.
  The `beq` branch at 0xe04 targets 0xdc8 and is always taken.
  The `bne` branch at 0xe14 targets 0xe44, is taken when v0(?) < 0xa (signed), and falls through when v0(?) >= 0xa (signed).
  The `bne` branch at 0xe1c targets 0xe60, is taken when a2(?) != 0, and falls through when a2(?) == 0.
  The `bne` branch at 0xe24 targets 0xf90, is taken when a3(?) != 0, and falls through when a3(?) == 0.
  The `bne` branch at 0xe2c targets 0xe60, is taken when a4(?) != 0, and falls through when a4(?) == 0.
  The `bne` branch at 0xe34 targets 0xdec, is taken when a5(=0x91) != v0(?), and falls through when a5(=0x91) == v0(?).
  The `beq` branch at 0xe3c targets 0xe64 and is always taken.
  The `bne` branch at 0xe48 targets 0xf74, is taken when v0(?) < 0x8 (signed), and falls through when v0(?) >= 0x8 (signed).
  The `bne` branch at 0xe50 targets 0xe60, is taken when a7(?) != 0, and falls through when a7(?) == 0.
  The `bne` branch at 0xe58 targets 0xdec, is taken when t0(=0x9) != v0(?), and falls through when t0(=0x9) == v0(?).
  The `bltz` branch at 0xe6c targets 0xfcc, is taken when v0(=ret(nic_write_byte)) < 0 (signed), and falls through when v0(=ret(nic_write_byte)) >= 0 (signed).
  The `bltz` branch at 0xe7c targets 0xfd4, is taken when v0(=ret(nic_write_byte)) < 0 (signed), and falls through when v0(=ret(nic_write_byte)) >= 0 (signed).
  The `bltz` branch at 0xe8c targets 0xfdc, is taken when v0(=ret(nic_write_byte)) < 0 (signed), and falls through when v0(=ret(nic_write_byte)) >= 0 (signed).
  The `bltz` branch at 0xea0 targets 0xfc4, is taken when v0(=ret(nic_read_byte)) < 0 (signed), and falls through when v0(=ret(nic_read_byte)) >= 0 (signed).
  The `bne` branch at 0xeb0 targets 0xe94, is taken when s0(?) < 0xe (signed), and falls through when s0(?) >= 0xe (signed).
  The `bne` branch at 0xedc targets 0xec4, is taken when s0(?) < 0xe (signed), and falls through when s0(?) >= 0xe (signed).
  The `bne` branch at 0xeec targets 0xdec, is taken when a2(=0x8d) != a3(?), and falls through when a2(=0x8d) == a3(?).
  The `bne` branch at 0xefc targets 0xde8, is taken when a4(=0xb001) != a5(?), and falls through when a4(=0xb001) == a5(?).
  The `bne` branch at 0xf08 targets 0xde8, is taken when a6(=0xa) != a7(?), and falls through when a6(=0xa) == a7(?).
  The `bne` branch at 0xf30 targets 0xf14, is taken when s0(?) < 0xe (signed), and falls through when s0(?) >= 0xe (signed).
  The `bne` branch at 0xf3c targets 0xdec, is taken when a2(=0xb001) != a3(?), and falls through when a2(=0xb001) == a3(?).
  The `bne` branch at 0xf64 targets 0xf48, is taken when v0(?) < 0x6 (signed), and falls through when v0(?) >= 0x6 (signed).
  The `beq` branch at 0xf6c targets 0xdc4 and is always taken.
  The `bne` branch at 0xf78 targets 0xfb0, is taken when v0(?) < 0x6 (signed), and falls through when v0(?) >= 0x6 (signed).
  The `beq` branch at 0xf80 targets 0xdec, is taken when a7(?) == 0, and falls through when a7(?) != 0.
  The `beq` branch at 0xf88 targets 0xe64 and is always taken.
  The `bne` branch at 0xf94 targets 0xdec, is taken when v0(?) < 0xc (signed), and falls through when v0(?) >= 0xc (signed).
  The `beq` branch at 0xfa0 targets 0xdec, is taken when v0(?) >= 0xd (signed), and falls through when v0(?) < 0xd (signed).
  The `beq` branch at 0xfa8 targets 0xe64 and is always taken.
  The `bne` branch at 0xfb4 targets 0xdec, is taken when t2(=0x4) != v0(?), and falls through when t2(=0x4) == v0(?).
  The `beq` branch at 0xfbc targets 0xe64 and is always taken.
  The `beq` branch at 0xfc4 targets 0xdc8 and is always taken.
  The `beq` branch at 0xfcc targets 0xdc8 and is always taken.
  The `beq` branch at 0xfd4 targets 0xdc8 and is always taken.
  The `beq` branch at 0xfdc targets 0xdc8 and is always taken.
  The return at 0xdcc has v0 = one of ?, ret(nic_next), ret(nic_read_byte), ret(nic_write_byte).

- `nic_get_eaddr` in `IP30/usr/cpu/sysgen/IP30boot/nic.o` at 0x106c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/nic.o`.
  Range: 0x106c-0x1124 (184 bytes).
  It occupies 184 bytes.
  The `sw` at 0x109c stores 4 bytes to a1 (arg1 at entry) +0x0.
  The `jal` at 0x10b4 calls nic_eaddr with a0=sym(nic_access_mcr32), a1=a0 at entry (arg0), a2=a2 at entry (arg2), a3=?.
  The `jal` at 0x10d8 calls printf with a0=sym(.rodata), a1=ret(nic_eaddr), a2=?, a3=?.
  The `jal` at 0x110c calls printf with a0=sym(.rodata), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a5=0x200000.
  The `beq` branch at 0x1094 targets 0x1108, is taken when a1 == 0, and falls through when a1 != 0.
  The `beq` branch at 0x10c0 targets 0x111c, is taken when v0(=ret(nic_eaddr)) == 0, and falls through when v0(=ret(nic_eaddr)) != 0.
  The `bne` branch at 0x10c8 targets 0x10b0, is taken when s0(?) != s5(=-0x1), and falls through when s0(?) == s5(=-0x1).
  The `beq` branch at 0x1114 targets 0x10a4 and is always taken.
  The `beq` branch at 0x111c targets 0x10e4 and is always taken.
  The return at 0x1100 has v0 = ret(nic_eaddr).

- `nic_mfg_next` in `IP30/usr/cpu/sysgen/IP30boot/nic.o` at 0x1124 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/nic.o`.
  Range: 0x1124-0x15c8 (1188 bytes).
  It occupies 1188 bytes.
  The `ld` at 0x1194 loads 8 bytes from (sym(.rodata) + (ret(nic_next) << 0x3)) +0x0.
  The `ld` at 0x1414 loads 8 bytes from sym(.rodata) +0x360.
  The `ld` at 0x1418 loads 8 bytes from sym(.rodata) +0x358.
  The `ld` at 0x141c loads 8 bytes from sym(.rodata) +0x350.
  The `ld` at 0x1420 loads 8 bytes from sym(.rodata) +0x348.
  The `ld` at 0x1424 loads 8 bytes from sym(.rodata) +0x340.
  The `sdl` at 0x1428 stores 8 bytes to (ret(strlen) + a1) +0x0.
  The `sdr` at 0x142c stores 8 bytes to (ret(strlen) + a1) +0x7.
  The `sdl` at 0x1430 stores 8 bytes to (ret(strlen) + a1) +0x8.
  The `sdr` at 0x1434 stores 8 bytes to (ret(strlen) + a1) +0xf.
  The `sdl` at 0x1438 stores 8 bytes to (ret(strlen) + a1) +0x10.
  The `sdr` at 0x143c stores 8 bytes to (ret(strlen) + a1) +0x17.
  The `sdl` at 0x1440 stores 8 bytes to (ret(strlen) + a1) +0x18.
  The `sdr` at 0x1444 stores 8 bytes to (ret(strlen) + a1) +0x1f.
  The `sdl` at 0x1448 stores 8 bytes to (ret(strlen) + a1) +0x20.
  The `sdr` at 0x1450 stores 8 bytes to (ret(strlen) + a1) +0x27.
  The `jal` at 0x1158 calls strlen with a0=a1 at entry (arg1), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1170 calls nic_next with a0=a0 at entry (arg0), a1=sp-96, a2=sp-90, a3=sp-89.
  Calls (unknown callee) via register with a0=(sym(.rodata) + (ret(nic_next) << 0x3)), a1=sym(.rodata), a2=(ret(nic_next) << 0x3), a3=?, a4=[(sym(.rodata) + (ret(nic_next) << 0x3))]:8, a5=0xb (`jr` at 0x1198).
  The `bne` branch at 0x1138 targets 0x1158, is taken when a1 != 0, and falls through when a1 == 0.
  The `beq` branch at 0x118c targets 0x1414, is taken when v0(=ret(nic_next)) >= 0x7 (unsigned), and falls through when v0(=ret(nic_next)) < 0x7 (unsigned).
  The `beq` branch at 0x144c targets 0x1144 and is always taken.
  The return at 0x1150 has v0 = ?.
  The instructions from 0x11a0 to 0x1410 are not reached by any path from the entry, and their branches are not listed.
  The instructions from 0x1454 to 0x15c4 are not reached by any path from the entry, and their branches are not listed.
  The indirect jump at 0x1198 uses a jump table whose successors are unresolved.

- `nic_info_get` in `IP30/usr/cpu/sysgen/IP30boot/nic.o` at 0x15c8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/nic.o`.
  Range: 0x15c8-0x1620 (88 bytes).
  It occupies 88 bytes.
  The `sb` at 0x15d0 stores 1 byte to a2 (arg2 at entry) +0x0.
  The `jal` at 0x15ec calls nic_setup with a0=sp-112, a1=a0 at entry (arg0), a2=a1 at entry (arg1), a3=a3 at entry (arg3).
  The `jal` at 0x1600 calls nic_mfg_next with a0=sp-112, a1=a2 at entry (arg2), a2=?, a3=?.
  The `bltz` branch at 0x15f4 targets 0x1610, is taken when v0(=ret(nic_setup)) < 0 (signed), and falls through when v0(=ret(nic_setup)) >= 0 (signed).
  The `beq` branch at 0x1608 targets 0x1600, is taken when v0(=ret(nic_mfg_next)) == 0, and falls through when v0(=ret(nic_mfg_next)) != 0.
  The return at 0x1618 has v0 = one of ret(nic_setup), ret(nic_mfg_next).

- `nic_vertex_info_get` in `IP30/usr/cpu/sysgen/IP30boot/nic.o` at 0x1620 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/nic.o`.
  Range: 0x1620-0x164c (44 bytes).
  It occupies 44 bytes.
  The `jal` at 0x1634 calls hwgraph_info_get_LBL with a0=a0 at entry (arg0), a1=sym(.rodata), a2=sp-16, a3=a3 at entry (arg3).
  The return at 0x1644 has v0 = ?.

- `nic_vertex_info_set` in `IP30/usr/cpu/sysgen/IP30boot/nic.o` at 0x164c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/nic.o`.
  Range: 0x164c-0x1758 (268 bytes).
  It occupies 268 bytes.
  The `jal` at 0x1664 calls nic_vertex_info_get with a0=a2 at entry (arg2), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x168c calls kern_malloc with a0=0x800, a1=?, a2=?, a3=?.
  The `jal` at 0x16b0 calls nic_info_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=ret(kern_malloc), a3=?.
  The `jal` at 0x16b8 calls strlen with a0=ret(kern_malloc), a1=?, a2=?, a3=?.
  The `jal` at 0x16c8 calls kern_malloc with a0=(ret(strlen)+1 << 0x0), a1=?, a2=?, a3=?.
  The `jal` at 0x16ec calls hwgraph_info_add_LBL with a0=a2 at entry (arg2), a1=sym(.rodata), a2=ret(kern_malloc), a3=?.
  The `jal` at 0x16f4 calls nic_vertex_info_get with a0=a2 at entry (arg2), a1=?, a2=?, a3=?.
  The `jal` at 0x1704 calls kern_free with a0=ret(kern_malloc), a1=?, a2=?, a3=?.
  The `jal` at 0x1720 calls hwgraph_info_export_LBL with a0=a2 at entry (arg2), a1=sym(.rodata), a2=(ret(strlen)+1 << 0x0), a3=?.
  The `jal` at 0x172c calls nic_vmc_check with a0=a2 at entry (arg2), a1=ret(kern_malloc), a2=?, a3=?.
  The `jal` at 0x1740 calls strcpy with a0=ret(kern_malloc), a1=ret(kern_malloc), a2=?, a3=?.
  The `jal` at 0x1748 calls kern_free with a0=ret(kern_malloc), a1=?, a2=?, a3=?.
  The `beq` branch at 0x166c targets 0x1688, is taken when v0(=ret(nic_vertex_info_get)) == 0, and falls through when v0(=ret(nic_vertex_info_get)) != 0.
  The `bne` branch at 0x1694 targets 0x16a8, is taken when v0(=ret(kern_malloc)) != 0, and falls through when v0(=ret(kern_malloc)) == 0.
  The `beq` branch at 0x16a0 targets 0x1674 and is always taken.
  The `bne` branch at 0x16d0 targets 0x173c, is taken when v0(=ret(kern_malloc)) != 0, and falls through when v0(=ret(kern_malloc)) == 0.
  The `beq` branch at 0x16fc targets 0x1714, is taken when v0(=ret(nic_vertex_info_get)) == s0(=ret(kern_malloc)), and falls through when v0(=ret(nic_vertex_info_get)) != s0(=ret(kern_malloc)).
  The `beq` branch at 0x170c targets 0x1674 and is always taken.
  The `beq` branch at 0x1734 targets 0x1674 and is always taken.
  The `beq` branch at 0x1750 targets 0x16e0 and is always taken.
  The return at 0x1680 has v0 = one of ret(nic_vertex_info_get), 0x0, ret(kern_malloc).

- `nic_vertex_info_match` in `IP30/usr/cpu/sysgen/IP30boot/nic.o` at 0x1758 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/nic.o`.
  Range: 0x1758-0x1794 (60 bytes).
  It occupies 60 bytes.
  The `jal` at 0x1760 calls nic_vertex_info_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1784 calls strstr with a0=ret(nic_vertex_info_get), a1=a1 at entry (arg1), a2=?, a3=?.
  The `bne` branch at 0x1768 targets 0x1784, is taken when v0(=ret(nic_vertex_info_get)) != 0, and falls through when v0(=ret(nic_vertex_info_get)) == 0.
  The `beq` branch at 0x178c targets 0x1774 and is always taken.
  The return at 0x177c has v0 = one of 0x0, ?.

- `nic_bridge_vertex_info` in `IP30/usr/cpu/sysgen/IP30boot/nic.o` at 0x1794 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/nic.o`.
  Range: 0x1794-0x17b4 (32 bytes).
  It occupies 32 bytes.
  The `jal` at 0x17a0 calls nic_vertex_info_set with a0=sym(nic_access_mcr32), a1=a1 at entry (arg1), a2=a0 at entry (arg0), a3=a3 at entry (arg3).
  The return at 0x17ac has v0 = ret(nic_vertex_info_set).

- `nic_hq4_vertex_info` in `IP30/usr/cpu/sysgen/IP30boot/nic.o` at 0x17b4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/nic.o`.
  Range: 0x17b4-0x17d4 (32 bytes).
  It occupies 32 bytes.
  The `jal` at 0x17c0 calls nic_vertex_info_set with a0=sym(nic_access_mcr32), a1=a1 at entry (arg1), a2=a0 at entry (arg0), a3=a3 at entry (arg3).
  The return at 0x17cc has v0 = ret(nic_vertex_info_set).

- `nic_ioc3_vertex_info` in `IP30/usr/cpu/sysgen/IP30boot/nic.o` at 0x17d4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/nic.o`.
  Range: 0x17d4-0x1804 (48 bytes).
  It occupies 48 bytes.
  The `sw` at 0x17e8 stores 4 bytes to a2 (arg2 at entry) +0x0.
  The `jal` at 0x17f0 calls nic_vertex_info_set with a0=sym(nic_access_mcr32), a1=a1 at entry (arg1), a2=a0 at entry (arg0), a3=a3 at entry (arg3), a4=a0 at entry (arg0), a5=0x200000.
  The `beq` branch at 0x17e0 targets 0x17ec, is taken when a2 == 0, and falls through when a2 != 0.
  The return at 0x17fc has v0 = ret(nic_vertex_info_set).

- `nic_vmc_add` in `IP30/usr/cpu/sysgen/IP30boot/nic.o` at 0x1804 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/nic.o`.
  Range: 0x1804-0x185c (88 bytes).
  It occupies 88 bytes.
  The `sd` at 0x1824 stores 8 bytes to ret(kern_malloc) +0x0.
  The `sd` at 0x1828 stores 8 bytes to ret(kern_malloc) +0x8.
  The `sd` at 0x183c stores 8 bytes to ret(kern_malloc) +0x10.
  The `sd` at 0x1850 stores 8 bytes to ret(swap_ptr) +0x0.
  The `jal` at 0x1818 calls kern_malloc with a0=0x18, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1838 calls swap_ptr with a0=sym(.sdata)+8, a1=ret(kern_malloc), a2=?, a3=?.
  The return at 0x1854 has v0 = ret(kern_malloc).

- `nic_vmc_del` in `IP30/usr/cpu/sysgen/IP30boot/nic.o` at 0x185c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/nic.o`.
  Range: 0x185c-0x1868 (12 bytes).
  It occupies 12 bytes.
  The `sd` at 0x185c stores 8 bytes to a0 (arg0 at entry) +0x10.
  The `sd` at 0x1864 stores 8 bytes to a0 (arg0 at entry) +0x8.
  The return at 0x1860 has v0 = ?.

- `nic_vmc_check` in `IP30/usr/cpu/sysgen/IP30boot/nic.o` at 0x1868 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/nic.o`.
  Range: 0x1868-0x1908 (160 bytes).
  It occupies 160 bytes.
  5 such `ld` accesses load 8 bytes from ?, including `ld` at 0x18ac, `ld` at 0x18b8, `ld` at 0x18c4.
  The `jal` at 0x189c calls strstr with a0=a1 at entry (arg1), a1=?, a2=?, a3=?.
  The `jalr` at 0x18f8 calls (unknown callee) with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `bne` branch at 0x188c targets 0x18b8, is taken when at(=[sym(.sdata)]:8) != 0, and falls through when at(=[sym(.sdata)]:8) == 0.
  The `beq` branch at 0x1894 targets 0x18dc and is always taken.
  The `bne` branch at 0x18a4 targets 0x18f8, is taken when v0(=ret(strstr)) != 0, and falls through when v0(=ret(strstr)) == 0.
  The `beq` branch at 0x18b0 targets 0x18dc, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0x18bc targets 0x18d0, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `bne` branch at 0x18c8 targets 0x189c, is taken when a1(?) != 0, and falls through when a1(?) == 0.
  The `bne` branch at 0x18d4 targets 0x18b8, is taken when s0(?) != 0, and falls through when s0(?) == 0.
  The `beq` branch at 0x1900 targets 0x18b0 and is always taken.
  The return at 0x18f0 has v0 = ?.
