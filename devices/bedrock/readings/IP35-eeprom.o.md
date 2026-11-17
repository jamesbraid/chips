# Readings: `IP35/usr/cpu/sysgen/IP35boot/eeprom.o`

One entry per routine, filed here from the reading batches by binary.

- `component_name_lookup` in `IP35/usr/cpu/sysgen/IP35boot/eeprom.o` at 0x0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/eeprom.o`.
  Range: 0x0-0x54 (84 bytes).
  It occupies 84 bytes.
  The `lw` at 0x4 loads 4 bytes from sym(compt_name_map) +0x0.
  The `lw` at 0x24 loads 4 bytes from sym(compt_name_map) +0x10.
  The `ld` at 0x44 loads 8 bytes from sym(compt_name_map) +0x8.
  The `beq` branch at 0x14 targets 0x30, is taken when v0(=[sym(compt_name_map)]) == 0, and falls through when v0(=[sym(compt_name_map)]) != 0.
  The `beq` branch at 0x1c targets 0x40, is taken when v0(?) == a0, and falls through when v0(?) != a0.
  The `bne` branch at 0x28 targets 0x1c, is taken when v0(=[sym(compt_name_map+16)]) != 0, and falls through when v0(=[sym(compt_name_map+16)]) == 0.
  The `beq` branch at 0x30 targets 0x48, is taken when a5(?) == a4(=0x300), and falls through when a5(?) != a4(=0x300).
  The return at 0x38 has v0 = sym(.rodata).
  The return at 0x40 has v0 = sym(.rodata)+1016.
  The return at 0x4c has v0 = sym(.rodata).

- `nicify` in `IP35/usr/cpu/sysgen/IP35boot/eeprom.o` at 0x54 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/eeprom.o`.
  Range: 0x54-0x3b8 (868 bytes).
  It occupies 868 bytes.
  The `ld` at 0x6c loads 8 bytes from a1 (arg1 at entry) +0x8.
  The `lbu` at 0x8c loads 1 byte from sym(.rodata) +0x17c.
  The `lw` at 0x90 loads 4 bytes from sym(.rodata) +0x178.
  The `lbu` at 0x94 loads 1 byte from sym(.rodata) +0x17d.
  The `swl` at 0x98 stores 4 bytes to a0 (arg0 at entry) +0x0.
  The `swr` at 0x9c stores 4 bytes to a0 (arg0 at entry) +0x3.
  The `sb` at 0xa0 stores 1 byte to a0 (arg0 at entry) +0x4.
  The `sb` at 0xa8 stores 1 byte to a0 (arg0 at entry) +0x5.
  The `lbu` at 0xac loads 1 byte from [a1+8]:8 +0x2d.
  The `lbu` at 0xdc loads 1 byte from sym(.rodata) +0x184.
  The `lw` at 0xe0 loads 4 bytes from sym(.rodata) +0x180.
  The `lbu` at 0xe4 loads 1 byte from sym(.rodata) +0x185.
  The `lbu` at 0xec loads 1 byte from sym(.rodata) +0x186.
  The `swl` at 0xf0 stores 4 bytes to ?.
  The `swr` at 0xf4 stores 4 bytes to ?.
  8 such `sb` accesses store 1 byte to ?, including `sb` at 0xf8, `sb` at 0xfc, `sb` at 0x108.
  The `lbu` at 0x10c loads 1 byte from [a1+8]:8 +0x13.
  The `lbu` at 0x138 loads 1 byte from sym(.rodata) +0xd8.
  The `ld` at 0x13c loads 8 bytes from sym(.rodata) +0xd0.
  The `lbu` at 0x140 loads 1 byte from sym(.rodata) +0x168.
  The `ld` at 0x144 loads 8 bytes from sym(.rodata) +0x158.
  The `ld` at 0x148 loads 8 bytes from sym(.rodata) +0x148.
  The `ld` at 0x14c loads 8 bytes from sym(.rodata) +0x140.
  The `ld` at 0x150 loads 8 bytes from sym(.rodata) +0x150.
  The `ld` at 0x154 loads 8 bytes from sym(.rodata) +0x160.
  8 such `sdl` accesses store 8 bytes to ?, including `sdl` at 0x174, `sdl` at 0x1e0, `sdl` at 0x240.
  8 such `sdr` accesses store 8 bytes to ?, including `sdr` at 0x178, `sdr` at 0x1e4, `sdr` at 0x244.
  2 such `lbu` accesses load 1 byte from [a1+8]:8 +0x22, including `lbu` at 0x188, `lbu` at 0x294.
  The `ld` at 0x1a0 loads 8 bytes from sym(.rodata) +0x108.
  The `lbu` at 0x1a4 loads 1 byte from sym(.rodata) +0x112.
  The `lbu` at 0x1a8 loads 1 byte from sym(.rodata) +0x110.
  The `lbu` at 0x1d0 loads 1 byte from sym(.rodata) +0x111.
  The `lbu` at 0x1fc loads 1 byte from [a1+8]:8 +0x42.
  The `ld` at 0x280 loads 8 bytes from sym(.rodata) +0x188.
  The `jal` at 0xa4 calls strlen with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xd0 calls copy_ascii_field with a0=(ret(strlen) + a0), a1=[a1+8]:8+46, a2=?, a3=0x1, a6=[[a1+8]:8+45]:1.
  The `jal` at 0x104 calls strlen with a0=?, a1=0x0, a2=0x3a, a3=0x65, a4=0x3b4e616d.
  The `jal` at 0x12c calls copy_ascii_field with a0=?, a1=[a1+8]:8+20, a2=?, a3=0x0, a6=[[a1+8]:8+19]:1.
  The `jal` at 0x180 calls strlen with a0=?, a1=?, a2=?, a3=?, a6=0x0, a7=0x3b53657269616c3a.
  The `jal` at 0x1c4 calls copy_ascii_field with a0=?, a1=[a1+8]:8+35, a2=?, a3=0x1, a6=[[a1+8]:8+34]:1.
  The `jal` at 0x1f4 calls strlen with a0=?, a1=0x3a, a2=0x0, a3=0x3b5265766973696f.
  The `jal` at 0x224 calls copy_ascii_field with a0=?, a1=[a1+8]:8+67, a2=?, a3=0x1, a6=[[a1+8]:8+66]:1.
  The `jal` at 0x26c calls strlen with a0=?, a1=?, a2=?, a3=?, a5=0x0, a6=0x72696574793a6666, a7=0x6c6974793a666666.
  The `jal` at 0x28c calls strlen with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x2a0 calls generate_unique_id with a0=[a1+8]:8+35, a1=?, a2=?, a3=?.
  The `jal` at 0x2ac calls int64_to_hex_string with a0=?, a1=ret(generate_unique_id), a2=?, a3=?.
  The `jal` at 0x2bc calls strcat with a0=a0 at entry (arg0), a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x2f0 calls component_name_lookup with a0=a2 at entry (arg2), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x308 calls cmn_err with a0=0x4, a1=sym(.rodata), a2=ret(component_name_lookup), a3=sym(.rodata).
  The `jal` at 0x318 calls component_name_lookup with a0=a2 at entry (arg2), a1=?, a2=?, a3=0x1, a6=[[a1+8]:8+45]:1.
  The `jal` at 0x330 calls cmn_err with a0=0x4, a1=sym(.rodata), a2=ret(component_name_lookup), a3=sym(.rodata).
  The `jal` at 0x340 calls component_name_lookup with a0=a2 at entry (arg2), a1=?, a2=?, a3=?, a6=[[a1+8]:8+19]:1.
  The `jal` at 0x358 calls cmn_err with a0=0x4, a1=sym(.rodata), a2=ret(component_name_lookup), a3=sym(.rodata).
  The `jal` at 0x368 calls component_name_lookup with a0=a2 at entry (arg2), a1=?, a2=?, a3=?, a6=[[a1+8]:8+34]:1.
  The `jal` at 0x380 calls cmn_err with a0=0x4, a1=sym(.rodata), a2=ret(component_name_lookup), a3=sym(.rodata).
  The `jal` at 0x390 calls component_name_lookup with a0=a2 at entry (arg2), a1=?, a2=?, a3=?, a6=[[a1+8]:8+66]:1.
  The `jal` at 0x3a8 calls cmn_err with a0=0x4, a1=sym(.rodata), a2=ret(component_name_lookup), a3=sym(.rodata).
  The `beq` branch at 0x80 targets 0x2f0, is taken when s1(=[a1+8]:8) == 0, and falls through when s1(=[a1+8]:8) != 0.
  The `bne` branch at 0xb8 targets 0x318, is taken when s5(=0xc0) != a0(?), and falls through when s5(=0xc0) == a0(?).
  The `bne` branch at 0x114 targets 0x340, is taken when s5(=0xc0) != a5(?), and falls through when s5(=0xc0) == a5(?).
  The `bne` branch at 0x190 targets 0x368, is taken when s5(=0xc0) != ra(?), and falls through when s5(=0xc0) == ra(?).
  The `bne` branch at 0x204 targets 0x390, is taken when s5(=0xc0) != a4(?), and falls through when s5(=0xc0) == a4(?).
  The `beq` branch at 0x310 targets 0x2c8 and is always taken.
  The `beq` branch at 0x338 targets 0x2c8 and is always taken.
  The `beq` branch at 0x360 targets 0x2c8 and is always taken.
  The `beq` branch at 0x388 targets 0x2c8 and is always taken.
  The `beq` branch at 0x3b0 targets 0x2c8 and is always taken.
  The return at 0x2e8 has v0 = one of 0x0, 0x1.

- `cfgify` in `IP35/usr/cpu/sysgen/IP35boot/eeprom.o` at 0x3b8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/eeprom.o`.
  Range: 0x3b8-0x82c (1140 bytes).
  It occupies 1140 bytes.
  The `ld` at 0x3c4 loads 8 bytes from a1 (arg1 at entry) +0x8.
  The `lbu` at 0x3dc loads 1 byte from [a1+8]:8 +0x60.
  The `lbu` at 0x3e8 loads 1 byte from sym(.rodata) +0x1cc.
  The `lbu` at 0x3ec loads 1 byte from sym(.rodata) +0x1cd.
  The `lw` at 0x3f0 loads 4 bytes from sym(.rodata) +0x1c8.
  The `ld` at 0x3f4 loads 8 bytes from sym(.rodata) +0x1c0.
  2 such `sdl` accesses store 8 bytes to a0 (arg0 at entry) +0x0, including `sdl` at 0x3f8, `sdl` at 0x45c.
  2 such `sdr` accesses store 8 bytes to a0 (arg0 at entry) +0x7, including `sdr` at 0x3fc, `sdr` at 0x460.
  2 such `swl` accesses store 4 bytes to a0 (arg0 at entry) +0x8, including `swl` at 0x400, `swl` at 0x464.
  2 such `swr` accesses store 4 bytes to a0 (arg0 at entry) +0xb, including `swr` at 0x404, `swr` at 0x468.
  2 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0xd, including `sb` at 0x408, `sb` at 0x470.
  2 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0xc, including `sb` at 0x40c, `sb` at 0x46c.
  The `lw` at 0x418 loads 4 bytes from sym(.rodata) +0x1e8.
  The `ld` at 0x41c loads 8 bytes from sym(.rodata) +0x1f0.
  The `lbu` at 0x420 loads 1 byte from sym(.rodata) +0x1fc.
  The `lw` at 0x424 loads 4 bytes from sym(.rodata) +0x1f8.
  The `lbu` at 0x428 loads 1 byte from sym(.rodata) +0x1ec.
  The `ld` at 0x42c loads 8 bytes from sym(.rodata) +0x1e0.
  The `lbu` at 0x430 loads 1 byte from sym(.rodata) +0x1dc.
  The `lw` at 0x438 loads 4 bytes from sym(.rodata) +0x1d8.
  The `lbu` at 0x450 loads 1 byte from sym(.rodata) +0x1de.
  The `lbu` at 0x454 loads 1 byte from sym(.rodata) +0x1dd.
  The `ld` at 0x458 loads 8 bytes from sym(.rodata) +0x1d0.
  The `sb` at 0x478 stores 1 byte to a0 (arg0 at entry) +0xe.
  The `sdl` at 0x48c stores 8 bytes to (ret(strlen) + a0) +0x0.
  The `sdr` at 0x490 stores 8 bytes to (ret(strlen) + a0) +0x7.
  The `swl` at 0x494 stores 4 bytes to (ret(strlen) + a0) +0x8.
  The `swr` at 0x498 stores 4 bytes to (ret(strlen) + a0) +0xb.
  The `sb` at 0x4a0 stores 1 byte to (ret(strlen) + a0) +0xc.
  The `lw` at 0x4b4 loads 4 bytes from [a1+8]:8 +0x64.
  The `sdl` at 0x4dc stores 8 bytes to (ret(strlen) + (ret(strlen) + (ret(strlen) + a0))) +0x0.
  The `sdr` at 0x4e0 stores 8 bytes to (ret(strlen) + (ret(strlen) + (ret(strlen) + a0))) +0x7.
  The `swl` at 0x4e4 stores 4 bytes to (ret(strlen) + (ret(strlen) + (ret(strlen) + a0))) +0x8.
  The `swr` at 0x4e8 stores 4 bytes to (ret(strlen) + (ret(strlen) + (ret(strlen) + a0))) +0xb.
  The `sb` at 0x4f0 stores 1 byte to (ret(strlen) + (ret(strlen) + (ret(strlen) + a0))) +0xc.
  The `lw` at 0x504 loads 4 bytes from [a1+8]:8 +0x6c.
  The `lbu` at 0x520 loads 1 byte from sym(.rodata) +0x20c.
  The `lw` at 0x524 loads 4 bytes from sym(.rodata) +0x208.
  The `ld` at 0x528 loads 8 bytes from sym(.rodata) +0x200.
  The `sdl` at 0x52c stores 8 bytes to (ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + a0))))) +0x0.
  The `sdr` at 0x530 stores 8 bytes to (ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + a0))))) +0x7.
  The `swl` at 0x534 stores 4 bytes to (ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + a0))))) +0x8.
  The `swr` at 0x538 stores 4 bytes to (ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + a0))))) +0xb.
  The `sb` at 0x540 stores 1 byte to (ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + a0))))) +0xc.
  The `lbu` at 0x544 loads 1 byte from sym(.rodata) +0x248.
  The `lw` at 0x548 loads 4 bytes from [a1+8]:8 +0x74.
  The `ld` at 0x54c loads 8 bytes from sym(.rodata) +0x270.
  The `lbu` at 0x550 loads 1 byte from sym(.rodata) +0x25c.
  The `lbu` at 0x554 loads 1 byte from sym(.rodata) +0x26c.
  The `ld` at 0x558 loads 8 bytes from sym(.rodata) +0x230.
  The `lbu` at 0x55c loads 1 byte from sym(.rodata) +0x24a.
  The `lw` at 0x560 loads 4 bytes from sym(.rodata) +0x268.
  The `lw` at 0x564 loads 4 bytes from sym(.rodata) +0x258.
  The `lbu` at 0x5ac loads 1 byte from sym(.rodata) +0x21c.
  The `lw` at 0x5b0 loads 4 bytes from sym(.rodata) +0x218.
  The `ld` at 0x5b4 loads 8 bytes from sym(.rodata) +0x210.
  The `sdl` at 0x5b8 stores 8 bytes to (ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + a0))))))) +0x0.
  The `sdr` at 0x5bc stores 8 bytes to (ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + a0))))))) +0x7.
  The `swl` at 0x5c0 stores 4 bytes to (ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + a0))))))) +0x8.
  The `swr` at 0x5c4 stores 4 bytes to (ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + a0))))))) +0xb.
  The `sb` at 0x5cc stores 1 byte to (ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + a0))))))) +0xc.
  The `lw` at 0x5e0 loads 4 bytes from [a1+8]:8 +0x7c.
  The `lbu` at 0x5fc loads 1 byte from sym(.rodata) +0x22c.
  The `lw` at 0x600 loads 4 bytes from sym(.rodata) +0x228.
  The `ld` at 0x604 loads 8 bytes from sym(.rodata) +0x220.
  The `sdl` at 0x608 stores 8 bytes to (ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + a0))))))))) +0x0.
  The `sdr` at 0x60c stores 8 bytes to (ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + a0))))))))) +0x7.
  The `swl` at 0x610 stores 4 bytes to (ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + a0))))))))) +0x8.
  The `swr` at 0x614 stores 4 bytes to (ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + a0))))))))) +0xb.
  The `sb` at 0x61c stores 1 byte to (ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + a0))))))))) +0xc.
  The `lw` at 0x630 loads 4 bytes from [a1+8]:8 +0x84.
  The `lbu` at 0x64c loads 1 byte from sym(.rodata) +0x238.
  The `lbu` at 0x650 loads 1 byte from sym(.rodata) +0x23a.
  The `lbu` at 0x654 loads 1 byte from sym(.rodata) +0x239.
  5 such `sdl` accesses store 8 bytes to ?, including `sdl` at 0x65c, `sdl` at 0x6ac, `sdl` at 0x6f8.
  5 such `sdr` accesses store 8 bytes to ?, including `sdr` at 0x660, `sdr` at 0x6b0, `sdr` at 0x6fc.
  13 such `sb` accesses store 1 byte to ?, including `sb` at 0x664, `sb` at 0x668, `sb` at 0x670.
  The `lw` at 0x684 loads 4 bytes from [a1+8]:8 +0x8c.
  The `lbu` at 0x6a0 loads 1 byte from sym(.rodata) +0x249.
  The `ld` at 0x6a8 loads 8 bytes from sym(.rodata) +0x240.
  The `lw` at 0x6d4 loads 4 bytes from [a1+8]:8 +0x94.
  The `ld` at 0x6f4 loads 8 bytes from sym(.rodata) +0x250.
  2 such `swl` accesses store 4 bytes to ?, including `swl` at 0x700, `swl` at 0x74c.
  2 such `swr` accesses store 4 bytes to ?, including `swr` at 0x704, `swr` at 0x750.
  The `lbu` at 0x718 loads 1 byte from [a1+8]:8 +0x98.
  The `ld` at 0x740 loads 8 bytes from sym(.rodata) +0x260.
  The `lbu` at 0x764 loads 1 byte from [a1+8]:8 +0xa1.
  The `lbu` at 0x780 loads 1 byte from sym(.rodata) +0x27a.
  The `lbu` at 0x784 loads 1 byte from sym(.rodata) +0x278.
  The `lbu` at 0x788 loads 1 byte from sym(.rodata) +0x279.
  The `lbu` at 0x7b4 loads 1 byte from [a1+8]:8 +0xaa.
  The `lbu` at 0x7d8 loads 1 byte from sym(.rodata) +0x191.
  The `lbu` at 0x7e0 loads 1 byte from sym(.rodata) +0x190.
  The `jal` at 0x474 calls strlen with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0x0, a3=0x3b, a4=0x73, a5=0x643a5965, a6=0x4461746156616c69, a7=0x0.
  The `jal` at 0x49c calls strlen with a0=(ret(strlen) + a0), a1=?, a2=?, a3=?.
  The `jal` at 0x4b8 calls sprintf with a0=(ret(strlen) + (ret(strlen) + a0)), a1=sym(.rodata), a2=[[a1+8]:8+100], a3=?.
  The `jal` at 0x4c4 calls strlen with a0=(ret(strlen) + (ret(strlen) + a0)), a1=?, a2=?, a3=?.
  The `jal` at 0x4ec calls strlen with a0=(ret(strlen) + (ret(strlen) + (ret(strlen) + a0))), a1=?, a2=?, a3=?.
  The `jal` at 0x508 calls sprintf with a0=(ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + a0)))), a1=sym(.rodata), a2=[[a1+8]:8+108], a3=?.
  The `jal` at 0x510 calls strlen with a0=(ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + a0)))), a1=?, a2=?, a3=?.
  The `jal` at 0x53c calls strlen with a0=(ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + a0))))), a1=?, a2=?, a3=?.
  The `jal` at 0x594 calls sprintf with a0=(ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + a0)))))), a1=sym(.rodata), a2=[[a1+8]:8+116], a3=0x0, a4=0x0.
  The `jal` at 0x59c calls strlen with a0=(ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + a0)))))), a1=?, a2=?, a3=?.
  The `jal` at 0x5c8 calls strlen with a0=(ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + a0))))))), a1=0x0, a2=0x5265673a, a3=0x3b43707543666732.
  The `jal` at 0x5e4 calls sprintf with a0=(ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + a0)))))))), a1=sym(.rodata), a2=[[a1+8]:8+124], a3=?.
  The `jal` at 0x5ec calls strlen with a0=(ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + a0)))))))), a1=?, a2=?, a3=?.
  The `jal` at 0x618 calls strlen with a0=(ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + (ret(strlen) + a0))))))))), a1=?, a2=?, a3=?.
  The `jal` at 0x634 calls sprintf with a0=?, a1=sym(.rodata), a2=[[a1+8]:8+132], a3=?.
  The `jal` at 0x63c calls strlen with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x66c calls strlen with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x688 calls sprintf with a0=?, a1=sym(.rodata), a2=[[a1+8]:8+140], a3=?.
  The `jal` at 0x690 calls strlen with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x6bc calls strlen with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x6d8 calls sprintf with a0=?, a1=sym(.rodata), a2=[[a1+8]:8+148], a3=?.
  The `jal` at 0x6e4 calls strlen with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x70c calls strlen with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x72c calls copy_ascii_field with a0=?, a1=[a1+8]:8+153, a2=?, a3=0x1.
  The `jal` at 0x758 calls strlen with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x778 calls copy_ascii_field with a0=?, a1=[a1+8]:8+162, a2=?, a3=0x1.
  The `jal` at 0x7a8 calls strlen with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x7cc calls copy_ascii_field with a0=?, a1=[a1+8]:8+171, a2=?, a3=0x1.
  The `jal` at 0x808 calls component_name_lookup with a0=a2 at entry (arg2), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a5=sym(.rodata).
  The `jal` at 0x81c calls cmn_err with a0=0x4, a1=sym(.rodata), a2=ret(component_name_lookup), a3=?.
  The `beq` branch at 0x3d4 targets 0x808, is taken when s1(=[a1+8]:8) == 0, and falls through when s1(=[a1+8]:8) != 0.
  The `bne` branch at 0x3e0 targets 0x418, is taken when at(=[[a1+8]:8+96]:1) != 0, and falls through when at(=[[a1+8]:8+96]:1) == 0.
  The `beq` branch at 0x410 targets 0x7f0 and is always taken.
  The `beq` branch at 0x824 targets 0x7f0 and is always taken.
  The return at 0x800 has v0 = one of 0x0, 0x1.

- `copy_ascii_field` in `IP35/usr/cpu/sysgen/IP35boot/eeprom.o` at 0x82c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/eeprom.o`.
  Range: 0x82c-0x91c (240 bytes).
  It occupies 240 bytes.
  7 such `sb` accesses store 1 byte to ?, including `sb` at 0x854, `sb` at 0x8b0, `sb` at 0x8bc.
  The `lbu` at 0x864 loads 1 byte from ?.
  The `blez` branch at 0x834 targets 0x8d4, is taken when a2 <= 0 (signed), and falls through when a2 > 0 (signed).
  The `beq` branch at 0x84c targets 0x85c and is always taken.
  The `beq` branch at 0x858 targets 0x8d4, is taken when t0(?) == 0, and falls through when t0(?) != 0.
  The `beq` branch at 0x87c targets 0x8c0, is taken when t2(=0x5f) == a5(?), and falls through when t2(=0x5f) != a5(?).
  The `beq` branch at 0x884 targets 0x8b8, is taken when t3(=0x3a) == a5(?), and falls through when t3(=0x3a) != a5(?).
  The `beq` branch at 0x88c targets 0x8b8, is taken when t8(=0x3b) == a5(?), and falls through when t8(=0x3b) != a5(?).
  The `beq` branch at 0x894 targets 0x8fc, is taken when t9(=0xff) == a5(?), and falls through when t9(=0xff) != a5(?).
  The `bne` branch at 0x89c targets 0x854, is taken when t1(?) != 0, and falls through when t1(?) == 0.
  The `beq` branch at 0x8a4 targets 0x854, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x8ac targets 0x858 and is always taken.
  The `beq` branch at 0x8b8 targets 0x858 and is always taken.
  The `bne` branch at 0x8c0 targets 0x884, is taken when a3 != a4(=0x1), and falls through when a3 == a4(=0x1).
  The `beq` branch at 0x8cc targets 0x858 and is always taken.
  The `beq` branch at 0x8e4 targets 0x908, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0x900 targets 0x858 and is always taken.
  The `beq` branch at 0x914 targets 0x8ec and is always taken.
  The return at 0x8f4 has v0 = ?.
  The instructions from 0x8b4 to 0x8b4 are not reached by any path from the entry, and their branches are not listed.

- `int64_to_hex_string` in `IP35/usr/cpu/sysgen/IP35boot/eeprom.o` at 0x91c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/eeprom.o`.
  Range: 0x91c-0x99c (128 bytes).
  It occupies 128 bytes.
  The `ld` at 0x928 loads 8 bytes from sym(.rodata) +0x288.
  The `ld` at 0x92c loads 8 bytes from sym(.rodata) +0x290.
  The `lbu` at 0x930 loads 1 byte from sym(.rodata) +0x298.
  3 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x950, `lbu` at 0x964, `lbu` at 0x980.
  2 such `sb` accesses store 1 byte to ?, including `sb` at 0x974, `sb` at 0x98c.
  The `sb` at 0x990 stores 1 byte to a0 (arg0 at entry) +0x10.
  The `bne` branch at 0x988 targets 0x950, is taken when a3(?) < 0x8 (unsigned), and falls through when a3(?) >= 0x8 (unsigned).
  The return at 0x994 has v0 = 0x3839616263646566.

- `generate_unique_id` in `IP35/usr/cpu/sysgen/IP35boot/eeprom.o` at 0x99c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/eeprom.o`.
  Range: 0x99c-0xad0 (308 bytes).
  It occupies 308 bytes.
  The `lbu` at 0x9fc loads 1 byte from ?.
  The `ld` at 0xa80 loads 8 bytes from abs 0x9200000001030100.
  The `ld` at 0xa84 loads 8 bytes from abs 0x9200000001604200.
  The `lbu` at 0xacc loads 1 byte from a0 (arg0 at entry) +0x0.
  The `jal` at 0x9cc calls char_to_base36 with a0=?, a1=?, a2=?, a3=?.
  The `blez` branch at 0x9b8 targets 0xa78, is taken when a1 <= 0 (signed), and falls through when a1 > 0 (signed).
  The `beq` branch at 0x9c4 targets 0xac4 and is always taken.
  The `beq` branch at 0x9f4 targets 0xa50, is taken when s0(?) >= s2(=a1) (signed), and falls through when s0(?) < s2(=a1) (signed).
  The `bne` branch at 0xa18 targets 0xa28, is taken when a0(?) < 0x30 (signed), and falls through when a0(?) >= 0x30 (signed).
  The `bne` branch at 0xa20 targets 0x9cc, is taken when a6(?) != 0, and falls through when a6(?) == 0.
  The `bne` branch at 0xa28 targets 0xa38, is taken when a4(?) != 0, and falls through when a4(?) == 0.
  The `bne` branch at 0xa30 targets 0x9cc, is taken when a7(?) != 0, and falls through when a7(?) == 0.
  The `bne` branch at 0xa38 targets 0x9ec, is taken when a5(?) != 0, and falls through when a5(?) == 0.
  The `beq` branch at 0xa40 targets 0x9ec, is taken when t0(?) == 0, and falls through when t0(?) != 0.
  The `beq` branch at 0xa48 targets 0x9cc and is always taken.
  The `beq` branch at 0xa50 targets 0xa7c, is taken when s3(?) == 0, and falls through when s3(?) != 0.
  The `beq` branch at 0xabc targets 0xa5c and is always taken.
  The `beq` branch at 0xac8 targets 0xa00 and is always taken.
  The return at 0xa70 has v0 = ?.

- `char_to_base36` in `IP35/usr/cpu/sysgen/IP35boot/eeprom.o` at 0xad0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/eeprom.o`.
  Range: 0xad0-0xb38 (104 bytes).
  It occupies 104 bytes.
  The `bne` branch at 0xaf0 targets 0xb04, is taken when a0 < 0x30 (signed), and falls through when a0 >= 0x30 (signed).
  The `bne` branch at 0xafc targets 0xb30, is taken when a7(?) != 0, and falls through when a7(?) == 0.
  The `bne` branch at 0xb04 targets 0xb14, is taken when a4(?) != 0, and falls through when a4(?) == 0.
  The `bne` branch at 0xb0c targets 0xb30, is taken when t1(?) != 0, and falls through when t1(?) == 0.
  The `bne` branch at 0xb14 targets 0xb30, is taken when a5(?) != 0, and falls through when a5(?) == 0.
  The `beq` branch at 0xb1c targets 0xb30, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The return at 0xb28 has v0 = ?.
  The return at 0xb30 has v0 = one of ?, 0x0.

- `eeprom_xlate_board_mfr_date` in `IP35/usr/cpu/sysgen/IP35boot/eeprom.o` at 0xb38 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/eeprom.o`.
  Range: 0xb38-0xb58 (32 bytes).
  It occupies 32 bytes.
  The `lbu` at 0xb38 loads 1 byte from a0 (arg0 at entry) +0x0.
  The `lbu` at 0xb3c loads 1 byte from a0 (arg0 at entry) +0x1.
  The `lbu` at 0xb40 loads 1 byte from a0 (arg0 at entry) +0x2.
  The return at 0xb50 has v0 = (([a0]:1 + ([a0+1]:1 << 0x8)) + ([a0+2]:1 << 0x10)).

- `_eeprom_str` in `IP35/usr/cpu/sysgen/IP35boot/eeprom.o` at 0xb58 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/eeprom.o`.
  Range: 0xb58-0xcbc (356 bytes).
  It occupies 356 bytes.
  The `jal` at 0xb80 calls bzero with a0=sp-352, a1=0xe4, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xb8c calls bzero with a0=sp-120, a1=0x24, a2=?, a3=?.
  The `jal` at 0xc08 calls gbrick_eeprom_read with a0=sp-80, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=?, a7=0x100.
  The `jal` at 0xc3c calls cbrick_eeprom_read with a0=sp-80, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=?, a7=0x100.
  The `jal` at 0xc68 calls iobrick_eeprom_read with a0=sp-80, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a4 at entry (arg4), a7=0x100.
  The `jal` at 0xc7c calls cfgify with a0=a0 at entry (arg0), a1=sp-80, a2=a2 at entry (arg2), a3=?.
  The `jal` at 0xc9c calls nicify with a0=a0 at entry (arg0), a1=sp-80, a2=a2 at entry (arg2), a3=?.
  The `beq` branch at 0xba4 targets 0xc58, is taken when at(?) == v0(=0x120), and falls through when at(?) != v0(=0x120).
  The `beq` branch at 0xbc4 targets 0xbfc, is taken when (s0(=a2) & 0xf0) == 0, and falls through when (s0(=a2) & 0xf0) != 0.
  The `beq` branch at 0xbd0 targets 0xc38, is taken when a2(?) == a7(=0x100), and falls through when a2(?) != a7(=0x100).
  The `beq` branch at 0xbd8 targets 0xc60, is taken when a2(?) == a1(=0x400), and falls through when a2(?) != a1(=0x400).
  The `beq` branch at 0xbe0 targets 0xc04, is taken when a2(?) == t0(=0x800), and falls through when a2(?) != t0(=0x800).
  The `beq` branch at 0xbfc targets 0xbd0 and is always taken.
  The `bne` branch at 0xc10 targets 0xc50, is taken when v0(=ret(gbrick_eeprom_read)) != 0, and falls through when v0(=ret(gbrick_eeprom_read)) == 0.
  The `beq` branch at 0xc20 targets 0xc94, is taken when a0(=a3) == 0, and falls through when a0(=a3) != 0.
  The `beq` branch at 0xc28 targets 0xc78, is taken when a1(=a3) == v0(=0x1), and falls through when a1(=a3) != v0(=0x1).
  The `beq` branch at 0xc30 targets 0xbe8 and is always taken.
  The `beq` branch at 0xc48 targets 0xc1c, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0xc50 targets 0xbe8 and is always taken.
  The `beq` branch at 0xc58 targets 0xbec and is always taken.
  The `beq` branch at 0xc70 targets 0xc48 and is always taken.
  The `beq` branch at 0xc84 targets 0xcb4, is taken when v0(=ret(cfgify)) == 0, and falls through when v0(=ret(cfgify)) != 0.
  The `beq` branch at 0xc8c targets 0xbe8 and is always taken.
  The `bne` branch at 0xca4 targets 0xc8c, is taken when v0(=ret(nicify)) != 0, and falls through when v0(=ret(nicify)) == 0.
  The `beq` branch at 0xcac targets 0xbe8 and is always taken.
  The `beq` branch at 0xcb4 targets 0xbe8 and is always taken.
  The return at 0xbf4 has v0 = one of ?, 0x6.

- `eeprom_str` in `IP35/usr/cpu/sysgen/IP35boot/eeprom.o` at 0xcbc (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/eeprom.o`.
  Range: 0xcbc-0xcdc (32 bytes).
  It occupies 32 bytes.
  The `jal` at 0xcc8 calls _eeprom_str with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=0x0, a4=a3 at entry (arg3).
  The return at 0xcd4 has v0 = ret(_eeprom_str).

- `eeprom_config_str` in `IP35/usr/cpu/sysgen/IP35boot/eeprom.o` at 0xcdc (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/eeprom.o`.
  Range: 0xcdc-0xcfc (32 bytes).
  It occupies 32 bytes.
  The `jal` at 0xce8 calls _eeprom_str with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=0x1, a4=a3 at entry (arg3).
  The return at 0xcf4 has v0 = ret(_eeprom_str).

- `vector_eeprom_str` in `IP35/usr/cpu/sysgen/IP35boot/eeprom.o` at 0xcfc (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/eeprom.o`.
  Range: 0xcfc-0xd8c (144 bytes).
  It occupies 144 bytes.
  The `jal` at 0xd40 calls vector_eeprom_read with a0=sp-320, a1=a1 at entry (arg1), a2=a3 at entry (arg3), a3=a2 at entry (arg2), a7=a3 at entry (arg3).
  The `jal` at 0xd6c calls nicify with a0=a0 at entry (arg0), a1=sp-320, a2=a2 at entry (arg2), a3=?.
  The `beq` branch at 0xd24 targets 0xd60, is taken when (a2 & 0xf0) == 0, and falls through when (a2 & 0xf0) != 0.
  The `beq` branch at 0xd30 targets 0xd50, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `beq` branch at 0xd48 targets 0xd68, is taken when v0(=ret(vector_eeprom_read)) == 0, and falls through when v0(=ret(vector_eeprom_read)) != 0.
  The `beq` branch at 0xd60 targets 0xd30 and is always taken.
  The `beq` branch at 0xd74 targets 0xd84, is taken when v0(=ret(nicify)) == 0, and falls through when v0(=ret(nicify)) != 0.
  The `beq` branch at 0xd7c targets 0xd50 and is always taken.
  The `beq` branch at 0xd84 targets 0xd50 and is always taken.
  The return at 0xd58 has v0 = one of 0x6, ret(vector_eeprom_read), 0x0, 0x4.

- `l1_mfg_string` in `IP35/usr/cpu/sysgen/IP35boot/eeprom.o` at 0xd8c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/eeprom.o`.
  Range: 0xd8c-0xe50 (196 bytes).
  It occupies 196 bytes.
  The `jal` at 0xdf0 calls iobrick_sc_version with a0=a1 at entry (arg1), a1=sp-32, a2=a3 at entry (arg3), a3=a3 at entry (arg3), a7=0x1.
  The `jal` at 0xe14 calls sprintf with a0=a0 at entry (arg0), a1=sym(.rodata), a2=sp-32, a3=?.
  The `jal` at 0xe28 calls elsc_version with a0=a1 at entry (arg1), a1=sp-32, a2=a2 at entry (arg2), a3=a3 at entry (arg3), a7=0x1.
  The `jal` at 0xe40 calls printf with a0=sym(.rodata), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a7=0x1.
  The `beq` branch at 0xdb4 targets 0xe24, is taken when (a6(?) & 0xf) == 0, and falls through when (a6(?) & 0xf) != 0.
  The `beq` branch at 0xdbc targets 0xe40, is taken when a6(?) == a7(=0x1), and falls through when a6(?) != a7(=0x1).
  The `beq` branch at 0xdc4 targets 0xdec, is taken when a6(?) == t0(=0x2), and falls through when a6(?) != t0(=0x2).
  The `beq` branch at 0xdcc targets 0xdec, is taken when a6(?) == t1(=0x4), and falls through when a6(?) != t1(=0x4).
  The `beq` branch at 0xdd4 targets 0xdec, is taken when a6(?) == t2(=0x6), and falls through when a6(?) != t2(=0x6).
  The `bgez` branch at 0xdf8 targets 0xe0c, is taken when v0(=ret(iobrick_sc_version)) >= 0 (signed), and falls through when v0(=ret(iobrick_sc_version)) < 0 (signed).
  The `beq` branch at 0xe00 targets 0xde0 and is always taken.
  The `beq` branch at 0xe1c targets 0xddc and is always taken.
  The `bgez` branch at 0xe30 targets 0xe0c, is taken when v0(=ret(elsc_version)) >= 0 (signed), and falls through when v0(=ret(elsc_version)) < 0 (signed).
  The `beq` branch at 0xe38 targets 0xde0 and is always taken.
  The `beq` branch at 0xe48 targets 0xddc and is always taken.
  The return at 0xde0 has v0 = one of 0x0, 0x1, 0x6, ret(iobrick_sc_version), ret(elsc_version).
  The instructions from 0xde8 to 0xde8 are not reached by any path from the entry, and their branches are not listed.
  The instructions from 0xe08 to 0xe08 are not reached by any path from the entry, and their branches are not listed.

- `is_iobrick` in `IP35/usr/cpu/sysgen/IP35boot/eeprom.o` at 0xe50 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/eeprom.o`.
  Range: 0xe50-0xf30 (224 bytes).
  It occupies 224 bytes.
  The `lw` at 0xe7c loads 4 bytes from ?.
  The `beq` branch at 0xe68 targets 0xeec, is taken when a1 == 0, and falls through when a1 != 0.
  The `beq` branch at 0xe90 targets 0xef8, is taken when v0(?) == t1(=0xd000), and falls through when v0(?) != t1(=0xd000).
  The `beq` branch at 0xe9c targets 0xf08, is taken when v0(?) == a4(=0xd100), and falls through when v0(?) != a4(=0xd100).
  The `beq` branch at 0xea4 targets 0xed4, is taken when v0(?) == a5(=0xd002), and falls through when v0(?) != a5(=0xd002).
  The `beq` branch at 0xeac targets 0xf18, is taken when v0(?) == a6(=0xd102), and falls through when v0(?) != a6(=0xd102).
  The `bne` branch at 0xeb4 targets 0xec8, is taken when v0(?) != a7(=0xd112), and falls through when v0(?) == a7(=0xd112).
  The `beq` branch at 0xec4 targets 0xee4, is taken when a4(?) == a5(=0x24), and falls through when a4(?) != a5(=0x24).
  The `bne` branch at 0xedc targets 0xeac, is taken when a5(?) != t0(=0x24), and falls through when a5(?) == t0(=0x24).
  The `beq` branch at 0xef0 targets 0xe7c and is always taken.
  The `bne` branch at 0xef8 targets 0xe9c, is taken when t0(?) != 0, and falls through when t0(?) == 0.
  The `beq` branch at 0xf00 targets 0xf10 and is always taken.
  The `bne` branch at 0xf08 targets 0xea4, is taken when a3(?) != 0, and falls through when a3(?) == 0.
  The `bne` branch at 0xf20 targets 0xeb4, is taken when a4(?) != a5(=0x24), and falls through when a4(?) == a5(=0x24).
  The `beq` branch at 0xf28 targets 0xee4 and is always taken.
  The return at 0xecc has v0 = 0x0.
  The return at 0xee4 has v0 = 0x1.
  The return at 0xf10 has v0 = 0x1.

- `cbrick_uid_get` in `IP35/usr/cpu/sysgen/IP35boot/eeprom.o` at 0xf30 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/eeprom.o`.
  Range: 0xf30-0x10c0 (400 bytes).
  It occupies 400 bytes.
  2 such `sd` accesses store 8 bytes to a1 (arg1 at entry) +0x0, including `sd` at 0xf84, `sd` at 0x10a0.
  The `jal` at 0xf40 calls get_nasid with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xf60 calls ip27log_getenv with a0=a0 at entry (arg0), a1=sym(.rodata), a2=sp-2592, a3=0x0, a4=0x0.
  The `jal` at 0xf7c calls strtoull with a0=sp-2592, a1=0x0, a2=0x0, a3=?.
  The `jal` at 0xf9c calls get_elsc with a0=?, a1=?, a2=0xf, a3=?.
  The `jal` at 0xfb0 calls sc_init with a0=sp-2560, a1=a0 at entry (arg0), a2=0xf, a3=?.
  The `jal` at 0xfc0 calls bzero with a0=sp-176, a1=0x80, a2=?, a3=?.
  The `jal` at 0xfd0 calls sc_open with a0=?, a1=0xffff000, a2=?, a3=?.
  The `jal` at 0xffc calls sc_construct_msg with a0=?, a1=ret(sc_open), a2=sp-176, a3=0x80, a4=0x6, a5=0x4, a6=0x0.
  The `jal` at 0x101c calls sc_command_kern with a0=?, a1=ret(sc_open), a2=sp-176, a3=sp-176, a4=sp-48.
  The `jal` at 0x1030 calls sc_close with a0=?, a1=ret(sc_open), a2=?, a3=?.
  The `jal` at 0x105c calls sc_close with a0=?, a1=ret(sc_open), a2=?, a3=?.
  The `jal` at 0x1070 calls sc_interpret_resp with a0=sp-176, a1=0x2, a2=0x1, a3=sp-2592.
  The `jal` at 0x1088 calls strlen with a0=sp-2592, a1=?, a2=?, a3=?.
  The `jal` at 0x1098 calls generate_unique_id with a0=sp-2592, a1=(ret(strlen) << 0x0), a2=?, a3=?.
  The `jal` at 0x10b0 calls sc_close with a0=?, a1=ret(sc_open), a2=?, a3=?.
  The `bltz` branch at 0xf68 targets 0xf90, is taken when v0(=ret(ip27log_getenv)) < 0 (signed), and falls through when v0(=ret(ip27log_getenv)) >= 0 (signed).
  The `beq` branch at 0xf88 targets 0x103c and is always taken.
  The `bne` branch at 0xf94 targets 0xfac, is taken when s0(=a0) != a2(?), and falls through when s0(=a0) == a2(?).
  The `beq` branch at 0xfa4 targets 0xfbc and is always taken.
  The `bltz` branch at 0xfdc targets 0x1054, is taken when v0(=ret(sc_open)) < 0 (signed), and falls through when v0(=ret(sc_open)) >= 0 (signed).
  The `bltz` branch at 0x1004 targets 0x10ac, is taken when v0(=ret(sc_construct_msg)) < 0 (signed), and falls through when v0(=ret(sc_construct_msg)) >= 0 (signed).
  The `beq` branch at 0x1024 targets 0x105c, is taken when v0(=ret(sc_command_kern)) == 0, and falls through when v0(=ret(sc_command_kern)) != 0.
  The `beq` branch at 0x1054 targets 0x1040 and is always taken.
  The `bgez` branch at 0x1078 targets 0x1088, is taken when v0(=ret(sc_interpret_resp)) >= 0 (signed), and falls through when v0(=ret(sc_interpret_resp)) < 0 (signed).
  The `beq` branch at 0x1080 targets 0x103c and is always taken.
  The `beq` branch at 0x10a4 targets 0x103c and is always taken.
  The `beq` branch at 0x10b8 targets 0x103c and is always taken.
  The return at 0x104c has v0 = one of 0x0, 0x1.

- `peer_iobrick_uid_get` in `IP35/usr/cpu/sysgen/IP35boot/eeprom.o` at 0x10c0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/eeprom.o`.
  Range: 0x10c0-0x11ec (300 bytes).
  It occupies 300 bytes.
  The `sd` at 0x11cc stores 8 bytes to a2 (arg2 at entry) +0x0.
  The `jal` at 0x10dc calls get_elsc with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x10ec calls bzero with a0=sp-208, a1=0x80, a2=?, a3=?.
  The `jal` at 0x1100 calls sc_open with a0=ret(get_elsc), a1=((a0 << 0x12) | (a1 << 0xc)), a2=(a1 << 0xc), a3=?.
  The `jal` at 0x1130 calls sc_construct_msg with a0=ret(get_elsc), a1=ret(sc_open), a2=sp-208, a3=0x80, a4=0x6, a5=0x4, a6=0x0.
  The `jal` at 0x1150 calls sc_command_kern with a0=ret(get_elsc), a1=ret(sc_open), a2=sp-208, a3=sp-208, a4=sp-80.
  The `jal` at 0x1164 calls sc_close with a0=ret(get_elsc), a1=ret(sc_open), a2=?, a3=?.
  The `jal` at 0x1188 calls sc_close with a0=ret(get_elsc), a1=ret(sc_open), a2=?, a3=?.
  The `jal` at 0x119c calls sc_interpret_resp with a0=sp-208, a1=0x2, a2=0x1, a3=sp-72.
  The `jal` at 0x11b4 calls strlen with a0=sp-72, a1=?, a2=?, a3=?.
  The `jal` at 0x11c4 calls generate_unique_id with a0=sp-72, a1=(ret(strlen) << 0x0), a2=?, a3=?.
  The `jal` at 0x11dc calls sc_close with a0=ret(get_elsc), a1=ret(sc_open), a2=?, a3=?.
  The `bltz` branch at 0x1110 targets 0x1170, is taken when v0(=ret(sc_open)) < 0 (signed), and falls through when v0(=ret(sc_open)) >= 0 (signed).
  The `bltz` branch at 0x1138 targets 0x11d8, is taken when v0(=ret(sc_construct_msg)) < 0 (signed), and falls through when v0(=ret(sc_construct_msg)) >= 0 (signed).
  The `beq` branch at 0x1158 targets 0x1188, is taken when v0(=ret(sc_command_kern)) == 0, and falls through when v0(=ret(sc_command_kern)) != 0.
  The `bgez` branch at 0x11a4 targets 0x11b4, is taken when v0(=ret(sc_interpret_resp)) >= 0 (signed), and falls through when v0(=ret(sc_interpret_resp)) < 0 (signed).
  The `beq` branch at 0x11ac targets 0x1170 and is always taken.
  The `beq` branch at 0x11d0 targets 0x1170 and is always taken.
  The `beq` branch at 0x11e4 targets 0x1170 and is always taken.
  The return at 0x1180 has v0 = one of 0x0, 0x1.

- `rbrick_uid_get` in `IP35/usr/cpu/sysgen/IP35boot/eeprom.o` at 0x11ec (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/eeprom.o`.
  Range: 0x11ec-0x130c (288 bytes).
  It occupies 288 bytes.
  The `sd` at 0x12ec stores 8 bytes to a2 (arg2 at entry) +0x0.
  The `jal` at 0x1208 calls sc_init with a0=sp-2576, a1=a0 at entry (arg0), a2=a1 at entry (arg1), a3=a3 at entry (arg3).
  The `jal` at 0x1214 calls bzero with a0=sp-192, a1=0x80, a2=?, a3=?.
  The `jal` at 0x1228 calls sc_open with a0=sp-2576, a1=0xffff000, a2=?, a3=?.
  The `jal` at 0x1254 calls sc_construct_msg with a0=sp-2576, a1=ret(sc_open), a2=sp-192, a3=0x80, a4=0x6, a5=0x4, a6=0x0.
  The `jal` at 0x1274 calls sc_command_kern with a0=sp-2576, a1=ret(sc_open), a2=sp-192, a3=sp-192, a4=sp-64.
  The `jal` at 0x1284 calls sc_close with a0=sp-2576, a1=ret(sc_open), a2=?, a3=?.
  The `jal` at 0x12a8 calls sc_close with a0=sp-2576, a1=ret(sc_open), a2=?, a3=?.
  The `jal` at 0x12bc calls sc_interpret_resp with a0=sp-192, a1=0x2, a2=0x1, a3=sp-56.
  The `jal` at 0x12d4 calls strlen with a0=sp-56, a1=?, a2=?, a3=?.
  The `jal` at 0x12e4 calls generate_unique_id with a0=sp-56, a1=(ret(strlen) << 0x0), a2=?, a3=?.
  The `jal` at 0x12fc calls sc_close with a0=sp-2576, a1=ret(sc_open), a2=?, a3=?.
  The `bltz` branch at 0x1234 targets 0x1290, is taken when v0(=ret(sc_open)) < 0 (signed), and falls through when v0(=ret(sc_open)) >= 0 (signed).
  The `bltz` branch at 0x125c targets 0x12f8, is taken when v0(=ret(sc_construct_msg)) < 0 (signed), and falls through when v0(=ret(sc_construct_msg)) >= 0 (signed).
  The `beq` branch at 0x127c targets 0x12a4, is taken when v0(=ret(sc_command_kern)) == 0, and falls through when v0(=ret(sc_command_kern)) != 0.
  The `bgez` branch at 0x12c4 targets 0x12d4, is taken when v0(=ret(sc_interpret_resp)) >= 0 (signed), and falls through when v0(=ret(sc_interpret_resp)) < 0 (signed).
  The `beq` branch at 0x12cc targets 0x1290 and is always taken.
  The `beq` branch at 0x12f0 targets 0x1290 and is always taken.
  The `beq` branch at 0x1304 targets 0x1290 and is always taken.
  The return at 0x129c has v0 = one of 0x0, 0x1.

- `nonpeer_iobrick_uid_get` in `IP35/usr/cpu/sysgen/IP35boot/eeprom.o` at 0x130c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/eeprom.o`.
  Range: 0x130c-0x13c8 (188 bytes).
  It occupies 188 bytes.
  The `ld` at 0x1358 loads 8 bytes from abs 0x9200000001030100.
  The `ld` at 0x135c loads 8 bytes from abs 0x9200000001604200.
  2 such `sd` accesses store 8 bytes to a1 (arg1 at entry) +0x0, including `sd` at 0x1394, `sd` at 0x13bc.
  The `jal` at 0x133c calls iobrick_eeprom_read with a0=sp-88, a1=a0 at entry (arg0), a2=0x400, a3=a2 at entry (arg2).
  The `jal` at 0x13b4 calls generate_unique_id with a0=sp-285, a1=?, a2=ret(iobrick_eeprom_read), a3=0x9200000001030100.
  The `beq` branch at 0x1348 targets 0x13ac, is taken when v0(=ret(iobrick_eeprom_read)) == 0, and falls through when v0(=ret(iobrick_eeprom_read)) != 0.
  The `beq` branch at 0x13c0 targets 0x1398 and is always taken.
  The return at 0x13a4 has v0 = one of ret(iobrick_eeprom_read), 0x0.

- `iobrick_uid_get` in `IP35/usr/cpu/sysgen/IP35boot/eeprom.o` at 0x13c8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/eeprom.o`.
  Range: 0x13c8-0x1444 (124 bytes).
  It occupies 124 bytes.
  The `ld` at 0x13d4 loads 8 bytes from (a0 << 0x21) -0x6fffffffcc000000.
  The `jal` at 0x13f8 calls peer_iobrick_rack_bay_get with a0=a0 at entry (arg0), a1=sp-32, a2=sp-28, a3=a3 at entry (arg3).
  The `jal` at 0x1410 calls nonpeer_iobrick_uid_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1434 calls peer_iobrick_uid_get with a0=?, a1=?, a2=a1 at entry (arg1), a3=?.
  The `bne` branch at 0x13ec targets 0x1410, is taken when at(?) != v0(=0xc000), and falls through when at(?) == v0(=0xc000).
  The `beq` branch at 0x1400 targets 0x1430, is taken when v0(=ret(peer_iobrick_rack_bay_get)) == 0, and falls through when v0(=ret(peer_iobrick_rack_bay_get)) != 0.
  The `beq` branch at 0x1408 targets 0x141c and is always taken.
  The `beq` branch at 0x143c targets 0x141c and is always taken.
  The return at 0x1428 has v0 = one of 0x2, ret(nonpeer_iobrick_uid_get), ret(peer_iobrick_uid_get).

- `ibrick_mac_addr_get` in `IP35/usr/cpu/sysgen/IP35boot/eeprom.o` at 0x1444 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/eeprom.o`.
  Range: 0x1444-0x150c (200 bytes).
  It occupies 200 bytes.
  2 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x14ac, `lbu` at 0x14cc.
  3 such `sb` accesses store 1 byte to ?, including `sb` at 0x14b0, `sb` at 0x14d0, `sb` at 0x14f0.
  The `jal` at 0x1474 calls iobrick_eeprom_read with a0=sp-88, a1=a0 at entry (arg0), a2=0x400, a3=0x0.
  The `bne` branch at 0x147c targets 0x14fc, is taken when v0(=ret(iobrick_eeprom_read)) != 0, and falls through when v0(=ret(iobrick_eeprom_read)) == 0.
  The `beq` branch at 0x1494 targets 0x14fc, is taken when v1(?) == 0, and falls through when v1(?) != 0.
  The `beq` branch at 0x149c targets 0x1500, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `blez` branch at 0x14a4 targets 0x14f0, is taken when a3(?) <= 0 (signed), and falls through when a3(?) > 0 (signed).
  The `beq` branch at 0x14c8 targets 0x14f0, is taken when v0(?) >= a3(?) (signed), and falls through when v0(?) < a3(?) (signed).
  The `bne` branch at 0x14e8 targets 0x14ac, is taken when v0(?) < a5(?) (signed), and falls through when v0(?) >= a5(?) (signed).
  The `beq` branch at 0x14f4 targets 0x1500 and is always taken.
  The return at 0x1504 has v0 = one of 0x0, 0x1.

- `eeprom_vertex_info_set` in `IP35/usr/cpu/sysgen/IP35boot/eeprom.o` at 0x150c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/eeprom.o`.
  Range: 0x150c-0x166c (352 bytes).
  It occupies 352 bytes.
  The `jal` at 0x152c calls nic_vertex_info_get with a0=a2 at entry (arg2), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x155c calls kern_malloc with a0=0x800, a1=?, a2=?, a3=?.
  The `jal` at 0x1588 calls vector_eeprom_str with a0=ret(kern_malloc), a1=?, a2=0x200, a3=a3 at entry (arg3).
  The `jal` at 0x15b0 calls eeprom_str with a0=ret(kern_malloc), a1=?, a2=a0 at entry (arg0), a3=a4 at entry (arg4).
  The `jal` at 0x15c0 calls kern_free with a0=ret(kern_malloc), a1=?, a2=?, a3=?.
  The `jal` at 0x15d0 calls strlen with a0=ret(kern_malloc), a1=?, a2=?, a3=?.
  The `jal` at 0x15e0 calls kern_malloc with a0=(ret(strlen)+1 << 0x0), a1=?, a2=?, a3=?.
  The `jal` at 0x1600 calls hwgraph_info_add_LBL with a0=a2 at entry (arg2), a1=sym(.rodata), a2=ret(kern_malloc), a3=?.
  The `jal` at 0x1608 calls nic_vertex_info_get with a0=a2 at entry (arg2), a1=?, a2=?, a3=?.
  The `jal` at 0x1618 calls kern_free with a0=ret(kern_malloc), a1=?, a2=?, a3=?.
  The `jal` at 0x1634 calls hwgraph_info_export_LBL with a0=a2 at entry (arg2), a1=sym(.rodata), a2=(ret(strlen)+1 << 0x0), a3=?.
  The `jal` at 0x1640 calls nic_vmc_check with a0=a2 at entry (arg2), a1=ret(kern_malloc), a2=?, a3=?.
  The `jal` at 0x1654 calls strcpy with a0=ret(kern_malloc), a1=ret(kern_malloc), a2=?, a3=?.
  The `jal` at 0x165c calls kern_free with a0=ret(kern_malloc), a1=?, a2=?, a3=?.
  The `beq` branch at 0x1538 targets 0x1558, is taken when v0(=ret(nic_vertex_info_get)) == 0, and falls through when v0(=ret(nic_vertex_info_get)) != 0.
  The `beq` branch at 0x156c targets 0x15a0, is taken when v0(=ret(kern_malloc)) == 0, and falls through when v0(=ret(kern_malloc)) != 0.
  The `beq` branch at 0x1578 targets 0x15a8, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x1590 targets 0x15d0, is taken when v0(=ret(vector_eeprom_str)) == 0, and falls through when v0(=ret(vector_eeprom_str)) != 0.
  The `beq` branch at 0x1598 targets 0x1540 and is always taken.
  The `beq` branch at 0x15a0 targets 0x1540 and is always taken.
  The `beq` branch at 0x15b8 targets 0x15d0, is taken when v0(=ret(eeprom_str)) == 0, and falls through when v0(=ret(eeprom_str)) != 0.
  The `beq` branch at 0x15c8 targets 0x1540 and is always taken.
  The `bne` branch at 0x15e8 targets 0x1650, is taken when v0(=ret(kern_malloc)) != 0, and falls through when v0(=ret(kern_malloc)) == 0.
  The `beq` branch at 0x1610 targets 0x1628, is taken when v0(=ret(nic_vertex_info_get)) == s1(=ret(kern_malloc)), and falls through when v0(=ret(nic_vertex_info_get)) != s1(=ret(kern_malloc)).
  The `beq` branch at 0x1620 targets 0x1540 and is always taken.
  The `beq` branch at 0x1648 targets 0x1540 and is always taken.
  The `beq` branch at 0x1664 targets 0x15f8 and is always taken.
  The return at 0x1550 has v0 = one of ret(nic_vertex_info_get), 0x0, ret(kern_malloc).

- `random_eeprom_ch` in `IP35/usr/cpu/sysgen/IP35boot/eeprom.o` at 0x166c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/eeprom.o`.
  Range: 0x166c-0x170c (160 bytes).
  It occupies 160 bytes.
  The `ld` at 0x1674 loads 8 bytes from abs 0x9200000001030100.
  The `ld` at 0x1678 loads 8 bytes from abs 0x9200000001604200.
  The `bne` branch at 0x16dc targets 0x1700, is taken when v0(?) < 0xa (signed), and falls through when v0(?) >= 0xa (signed).
  The `beq` branch at 0x16e4 targets 0x16f8, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The return at 0x16f0 has v0 = ?.
  The return at 0x16f8 has v0 = a0.
  The return at 0x1704 has v0 = ?.

- `fake_a_part_number` in `IP35/usr/cpu/sysgen/IP35boot/eeprom.o` at 0x170c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/eeprom.o`.
  Range: 0x170c-0x1900 (500 bytes).
  It occupies 500 bytes.
  2 such `sb` accesses store 1 byte to ?, including `sb` at 0x1758, `sb` at 0x1780.
  2 such `ld` accesses load 8 bytes from abs 0x9000000014000000, including `ld` at 0x17ac, `ld` at 0x17c0.
  The `lbu` at 0x1844 loads 1 byte from sym(.rodata) +0x33c.
  The `lw` at 0x1848 loads 4 bytes from sym(.rodata) +0x338.
  The `ld` at 0x184c loads 8 bytes from sym(.rodata) +0x330.
  5 such `sdl` accesses store 8 bytes to a0 (arg0 at entry) +0x0, including `sdl` at 0x1850, `sdl` at 0x1878, `sdl` at 0x189c.
  5 such `sdr` accesses store 8 bytes to a0 (arg0 at entry) +0x7, including `sdr` at 0x1854, `sdr` at 0x187c, `sdr` at 0x18a0.
  5 such `swl` accesses store 4 bytes to a0 (arg0 at entry) +0x8, including `swl` at 0x1858, `swl` at 0x1880, `swl` at 0x18a4.
  5 such `swr` accesses store 4 bytes to a0 (arg0 at entry) +0xb, including `swr` at 0x185c, `swr` at 0x1884, `swr` at 0x18a8.
  5 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0xc, including `sb` at 0x1864, `sb` at 0x188c, `sb` at 0x18b0.
  The `lbu` at 0x186c loads 1 byte from sym(.rodata) +0x32c.
  The `lw` at 0x1870 loads 4 bytes from sym(.rodata) +0x328.
  The `ld` at 0x1874 loads 8 bytes from sym(.rodata) +0x320.
  The `lbu` at 0x1890 loads 1 byte from sym(.rodata) +0x30c.
  The `lw` at 0x1894 loads 4 bytes from sym(.rodata) +0x308.
  The `ld` at 0x1898 loads 8 bytes from sym(.rodata) +0x300.
  The `lbu` at 0x18b4 loads 1 byte from sym(.rodata) +0x31c.
  The `lw` at 0x18b8 loads 4 bytes from sym(.rodata) +0x318.
  The `ld` at 0x18bc loads 8 bytes from sym(.rodata) +0x310.
  The `lbu` at 0x18dc loads 1 byte from sym(.rodata) +0x2fc.
  The `lw` at 0x18e0 loads 4 bytes from sym(.rodata) +0x2f8.
  The `ld` at 0x18e4 loads 8 bytes from sym(.rodata) +0x2f0.
  The `jal` at 0x1750 calls random_eeprom_ch with a0=0x0, a1=?, a2=?, a3=?.
  The `jal` at 0x17d0 calls get_nasid with a0=0x9000000014000000, a1=?, a2=0x8000, a3=a3 at entry (arg3).
  The `jal` at 0x17d8 calls get_chimera_type with a0=ret(get_nasid), a1=?, a2=?, a3=?.
  The `jal` at 0x17ec calls get_nasid with a0=?, a1=?, a2=0x3, a3=?.
  The `jal` at 0x17f4 calls get_chimera_type with a0=ret(get_nasid), a1=?, a2=?, a3=?.
  The `jal` at 0x1808 calls get_nasid with a0=?, a1=?, a2=?, a3=0x1.
  The `jal` at 0x1810 calls get_chimera_type with a0=ret(get_nasid), a1=?, a2=?, a3=?.
  The `jal` at 0x1824 calls get_nasid with a0=?, a1=?, a2=?, a3=?, a4=0x2.
  The `jal` at 0x182c calls get_chimera_type with a0=ret(get_nasid), a1=?, a2=?, a3=?.
  The `bne` branch at 0x1740 targets 0x176c, is taken when a1 != at(=0x100), and falls through when a1 == at(=0x100).
  The `beq` branch at 0x1748 targets 0x17a8 and is always taken.
  The `beq` branch at 0x1764 targets 0x1784, is taken when s0(?) >= 0xc (signed), and falls through when s0(?) < 0xc (signed).
  The `beq` branch at 0x176c targets 0x177c, is taken when s0(?) == s3(=0x3), and falls through when s0(?) != s3(=0x3).
  The `bne` branch at 0x1774 targets 0x1750, is taken when s0(?) != s4(=0x8), and falls through when s0(?) == s4(=0x8).
  The `beq` branch at 0x177c targets 0x175c and is always taken.
  The `beq` branch at 0x17b8 targets 0x18d8, is taken when v1(?) == a1(=0x4000), and falls through when v1(?) != a1(=0x4000).
  The `beq` branch at 0x17c8 targets 0x1890, is taken when a1(?) == a2(=0x8000), and falls through when a1(?) != a2(=0x8000).
  The `beq` branch at 0x17e4 targets 0x18b4, is taken when v0(=ret(get_chimera_type)) == a2(=0x3), and falls through when v0(=ret(get_chimera_type)) != a2(=0x3).
  The `beq` branch at 0x1800 targets 0x186c, is taken when v0(=ret(get_chimera_type)) == a3(=0x1), and falls through when v0(=ret(get_chimera_type)) != a3(=0x1).
  The `beq` branch at 0x181c targets 0x186c, is taken when v0(=ret(get_chimera_type)) == a4(=0x2), and falls through when v0(=ret(get_chimera_type)) != a4(=0x2).
  The `beq` branch at 0x1838 targets 0x186c, is taken when v0(=ret(get_chimera_type)) == a5(=0x5), and falls through when v0(=ret(get_chimera_type)) != a5(=0x5).
  The `beq` branch at 0x1860 targets 0x1784 and is always taken.
  The `beq` branch at 0x1888 targets 0x1784 and is always taken.
  The `beq` branch at 0x18ac targets 0x1784 and is always taken.
  The `beq` branch at 0x18d0 targets 0x1784 and is always taken.
  The `beq` branch at 0x18f8 targets 0x1784 and is always taken.
  The return at 0x17a0 has v0 = one of ?, ret(get_chimera_type), 0x2d303031.
  The instructions from 0x1868 to 0x1868 are not reached by any path from the entry, and their branches are not listed.

- `fake_a_serial_number` in `IP35/usr/cpu/sysgen/IP35boot/eeprom.o` at 0x1900 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/eeprom.o`.
  Range: 0x1900-0x1984 (132 bytes).
  It occupies 132 bytes.
  The `lbu` at 0x1934 loads 1 byte from table(sym(.rodata)) +0x0.
  2 such `sb` accesses store 1 byte to ?, including `sb` at 0x193c, `sb` at 0x1978.
  The `jal` at 0x1960 calls random_eeprom_ch with a0=0x0, a1=?, a2=?, a3=?.
  The `beq` branch at 0x1914 targets 0x1954, is taken when a1 == 0, and falls through when a1 != 0.
  The `bgez` branch at 0x1938 targets 0x1920, is taken when a3(?) >= 0 (signed), and falls through when a3(?) < 0 (signed).
  The `bne` branch at 0x1974 targets 0x1958, is taken when s1(?) < 0x6 (signed), and falls through when s1(?) >= 0x6 (signed).
  The `beq` branch at 0x197c targets 0x1944 and is always taken.
  The return at 0x194c has v0 = one of ?, ret(random_eeprom_ch).

- `fake_a_product_name` in `IP35/usr/cpu/sysgen/IP35boot/eeprom.o` at 0x1984 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/eeprom.o`.
  Range: 0x1984-0x1b8c (520 bytes).
  It occupies 520 bytes.
  The `lbu` at 0x19dc loads 1 byte from sym(.rodata) +0x34a.
  The `lbu` at 0x19e0 loads 1 byte from sym(.rodata) +0x348.
  The `ld` at 0x19e4 loads 8 bytes from sym(.rodata) +0x340.
  6 such `sdl` accesses store 8 bytes to a1 (arg1 at entry) +0x0, including `sdl` at 0x19e8, `sdl` at 0x1a28, `sdl` at 0x1a54.
  6 such `sdr` accesses store 8 bytes to a1 (arg1 at entry) +0x7, including `sdr` at 0x19ec, `sdr` at 0x1a2c, `sdr` at 0x1a58.
  2 such `sb` accesses store 1 byte to a1 (arg1 at entry) +0x8, including `sb` at 0x19f0, `sb` at 0x1b14.
  The `sb` at 0x19f4 stores 1 byte to a1 (arg1 at entry) +0xa.
  The `lbu` at 0x19f8 loads 1 byte from sym(.rodata) +0x349.
  The `sb` at 0x19fc stores 1 byte to a1 (arg1 at entry) +0x9.
  8 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x0, including `sb` at 0x1a00, `sb` at 0x1a40, `sb` at 0x1a68.
  The `lbu` at 0x1a1c loads 1 byte from sym(.rodata) +0x35c.
  The `lw` at 0x1a20 loads 4 bytes from sym(.rodata) +0x358.
  The `ld` at 0x1a24 loads 8 bytes from sym(.rodata) +0x350.
  3 such `swl` accesses store 4 bytes to a1 (arg1 at entry) +0x8, including `swl` at 0x1a30, `swl` at 0x1a5c, `swl` at 0x1a84.
  3 such `swr` accesses store 4 bytes to a1 (arg1 at entry) +0xb, including `swr` at 0x1a34, `swr` at 0x1a60, `swr` at 0x1a88.
  The `sb` at 0x1a38 stores 1 byte to a1 (arg1 at entry) +0xc.
  The `lw` at 0x1a4c loads 4 bytes from sym(.rodata) +0x388.
  The `ld` at 0x1a50 loads 8 bytes from sym(.rodata) +0x380.
  The `lw` at 0x1a74 loads 4 bytes from sym(.rodata) +0x378.
  The `ld` at 0x1a78 loads 8 bytes from sym(.rodata) +0x370.
  2 such `ld` accesses load 8 bytes from abs 0x9000000014000000, including `ld` at 0x1aa4, `ld` at 0x1ab8.
  The `lbu` at 0x1aec loads 1 byte from sym(.rodata) +0x3ac.
  The `lw` at 0x1af0 loads 4 bytes from sym(.rodata) +0x3a8.
  4 such `swl` accesses store 4 bytes to a1 (arg1 at entry) +0x0, including `swl` at 0x1af4, `swl` at 0x1b48, `swl` at 0x1b64.
  4 such `swr` accesses store 4 bytes to a1 (arg1 at entry) +0x3, including `swr` at 0x1af8, `swr` at 0x1b4c, `swr` at 0x1b68.
  4 such `sb` accesses store 1 byte to a1 (arg1 at entry) +0x4, including `sb` at 0x1b00, `sb` at 0x1b54, `sb` at 0x1b70.
  The `lbu` at 0x1b04 loads 1 byte from sym(.rodata) +0x368.
  The `ld` at 0x1b08 loads 8 bytes from sym(.rodata) +0x360.
  The `ld` at 0x1b24 loads 8 bytes from sym(.rodata) +0x390.
  The `lbu` at 0x1b40 loads 1 byte from sym(.rodata) +0x3a4.
  The `lw` at 0x1b44 loads 4 bytes from sym(.rodata) +0x3a0.
  The `lbu` at 0x1b5c loads 1 byte from sym(.rodata) +0x3b4.
  The `lw` at 0x1b60 loads 4 bytes from sym(.rodata) +0x3b0.
  The `lbu` at 0x1b74 loads 1 byte from sym(.rodata) +0x39c.
  The `lw` at 0x1b78 loads 4 bytes from sym(.rodata) +0x398.
  The `jal` at 0x1ac8 calls get_nasid with a0=0x9000000014000000, a1=0xc4, a2=a2 at entry (arg2), a3=a3 at entry (arg3), a5=0x400, a6=sym(.rodata).
  The `jal` at 0x1ad0 calls get_chimera_type with a0=ret(get_nasid), a1=?, a2=?, a3=?.
  The `beq` branch at 0x19bc targets 0x1a44, is taken when a4(?) == at(=0x100), and falls through when a4(?) != at(=0x100).
  The `beq` branch at 0x19cc targets 0x1a6c, is taken when a4(?) == v0(=0x200), and falls through when a4(?) != v0(=0x200).
  The `beq` branch at 0x19d4 targets 0x1a14, is taken when a4(?) == a5(=0x400), and falls through when a4(?) != a5(=0x400).
  The `beq` branch at 0x1a14 targets 0x1b04, is taken when t1(?) == 0, and falls through when t1(?) != 0.
  The `beq` branch at 0x1a3c targets 0x1a04 and is always taken.
  The `beq` branch at 0x1a44 targets 0x1a98, is taken when t1(?) == 0, and falls through when t1(?) != 0.
  The `beq` branch at 0x1a64 targets 0x1a04 and is always taken.
  The `beq` branch at 0x1a6c targets 0x1b24, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x1a90 targets 0x1a04 and is always taken.
  The `beq` branch at 0x1ab0 targets 0x1b74, is taken when at(?) == v0(=0x4000), and falls through when at(?) != v0(=0x4000).
  The `beq` branch at 0x1ac0 targets 0x1b3c, is taken when v0(?) == v1(=0x8000), and falls through when v0(?) != v1(=0x8000).
  The `beq` branch at 0x1adc targets 0x1b58, is taken when v0(=ret(get_chimera_type)) == 0, and falls through when v0(=ret(get_chimera_type)) != 0.
  The `beq` branch at 0x1afc targets 0x1a04 and is always taken.
  The `beq` branch at 0x1b1c targets 0x1a04 and is always taken.
  The `beq` branch at 0x1b34 targets 0x1a04 and is always taken.
  The `beq` branch at 0x1b50 targets 0x1a04 and is always taken.
  The `beq` branch at 0x1b6c targets 0x1a04 and is always taken.
  The `beq` branch at 0x1b84 targets 0x1a04 and is always taken.
  The return at 0x1a0c has v0 = one of 0x200, ?, ret(get_chimera_type), 0x4000.

- `fake_an_eeprom_record` in `IP35/usr/cpu/sysgen/IP35boot/eeprom.o` at 0x1b8c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/eeprom.o`.
  Range: 0x1b8c-0x1f18 (908 bytes).
  It occupies 908 bytes.
  The `ld` at 0x1b94 loads 8 bytes from a0 (arg0 at entry) +0x8.
  The `ld` at 0x1b9c loads 8 bytes from a0 (arg0 at entry) +0x0.
  The `sb` at 0x1be4 stores 1 byte to [a0+8]:8 +0x8.
  The `sb` at 0x1be8 stores 1 byte to [a0+8]:8 +0x2.
  The `sb` at 0x1bec stores 1 byte to [a0+8]:8 +0x0.
  The `sb` at 0x1bf4 stores 1 byte to [a0+8]:8 +0x1.
  The `sw` at 0x1c04 stores 4 bytes to [a0+8]:8 +0x4.
  The `lw` at 0x1c08 loads 4 bytes from sym(.rodata) +0x3b8.
  The `swl` at 0x1c14 stores 4 bytes to [a0+8]:8 +0x9.
  The `swr` at 0x1c20 stores 4 bytes to [a0+8]:8 +0xc.
  The `sb` at 0x1c2c stores 1 byte to [a0+8]:8 +0x22.
  The `sb` at 0x1c3c stores 1 byte to [a0+8]:8 +0x2d.
  The `sb` at 0x1c50 stores 1 byte to [a0+8]:8 +0x49.
  The `sb` at 0x1c58 stores 1 byte to [a0+8]:8 +0x48.
  The `sb` at 0x1c60 stores 1 byte to [a0+8]:8 +0x47.
  The `lbu` at 0x1c64 loads 1 byte from [a0+8]:8 +0x8.
  The `lw` at 0x1c68 loads 4 bytes from [a0+8]:8 +0x4.
  The `lbu` at 0x1c6c loads 1 byte from [a0+8]:8 +0x1.
  The `lbu` at 0x1c74 loads 1 byte from [a0+8]:8 +0x0.
  The `sb` at 0x1c78 stores 1 byte to [a0+8]:8 +0x46.
  The `lbu` at 0x1c84 loads 1 byte from [a0+8]:8 +0x2.
  The `lbu` at 0x1c90 loads 1 byte from [a0+8]:8 +0x13.
  The `lbu` at 0x1c9c loads 1 byte from [a0+8]:8 +0x22.
  The `sb` at 0x1ca8 stores 1 byte to [a0+8]:8 +0x45.
  The `lbu` at 0x1cb4 loads 1 byte from [a0+8]:8 +0x2d.
  The `sb` at 0x1cc0 stores 1 byte to [a0+8]:8 +0x44.
  The `sb` at 0x1ccc stores 1 byte to [a0+8]:8 +0x43.
  The `sb` at 0x1cd8 stores 1 byte to [a0+8]:8 +0x42.
  12 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x1cf0, `lbu` at 0x1d04, `lbu` at 0x1d30.
  The `sb` at 0x1e00 stores 1 byte to [a0+8]:8 +0xe2.
  The `sb` at 0x1e14 stores 1 byte to [a0]:8 +0x0.
  The `sb` at 0x1e1c stores 1 byte to [a0]:8 +0x1.
  The `sb` at 0x1e24 stores 1 byte to [a0]:8 +0x2.
  The `sb` at 0x1e34 stores 1 byte to [a0]:8 +0x3.
  The `sb` at 0x1e3c stores 1 byte to [a0]:8 +0x18.
  The `lbu` at 0x1e4c loads 1 byte from [a0]:8 +0x18.
  The `lbu` at 0x1e50 loads 1 byte from [a0]:8 +0x3.
  The `lbu` at 0x1e54 loads 1 byte from [a0]:8 +0x1.
  The `lbu` at 0x1e5c loads 1 byte from [a0]:8 +0x0.
  The `lbu` at 0x1e64 loads 1 byte from [a0]:8 +0x2.
  The `sb` at 0x1f14 stores 1 byte to [a0]:8 +0x23.
  The `jal` at 0x1c1c calls fake_a_product_name with a0=[a0+8]:8+19, a1=[a0+8]:8+20, a2=a1 at entry (arg1), a3=?.
  The `jal` at 0x1c30 calls fake_a_serial_number with a0=[a0+8]:8+35, a1=a2 at entry (arg2), a2=?, a3=?.
  The `jal` at 0x1c44 calls fake_a_part_number with a0=[a0+8]:8+46, a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0x1e30 calls fake_a_part_number with a0=[a0]:8+4, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1e44 calls fake_a_serial_number with a0=[a0]:8+25, a1=a2 at entry (arg2), a2=?, a3=?.
  The `beq` branch at 0x1bb4 targets 0x1e04, is taken when (a1 & 0xf0) == 0, and falls through when (a1 & 0xf0) != 0.
  The `bne` branch at 0x1bbc targets 0x1be4, is taken when s0(=[a0+8]:8) != 0, and falls through when s0(=[a0+8]:8) == 0.
  The `bltz` branch at 0x1cdc targets 0x1d14, is taken when a2(?) < 0 (signed), and falls through when a2(?) >= 0 (signed).
  The `bne` branch at 0x1cf8 targets 0x1d14, is taken when a2(?) < v0(?) (signed), and falls through when a2(?) >= v0(?) (signed).
  The `beq` branch at 0x1d0c targets 0x1ce4, is taken when a2(?) >= v0(?) (signed), and falls through when a2(?) < v0(?) (signed).
  The `bltz` branch at 0x1d1c targets 0x1d54, is taken when a2(?) < 0 (signed), and falls through when a2(?) >= 0 (signed).
  The `bne` branch at 0x1d38 targets 0x1d54, is taken when a2(?) < v0(?) (signed), and falls through when a2(?) >= v0(?) (signed).
  The `beq` branch at 0x1d4c targets 0x1d24, is taken when a2(?) >= v0(?) (signed), and falls through when a2(?) < v0(?) (signed).
  The `bltz` branch at 0x1d64 targets 0x1d9c, is taken when a4(?) < 0 (signed), and falls through when a4(?) >= 0 (signed).
  The `bne` branch at 0x1d80 targets 0x1d9c, is taken when a4(?) < v0(?) (signed), and falls through when a4(?) >= v0(?) (signed).
  The `beq` branch at 0x1d94 targets 0x1d6c, is taken when a4(?) >= v0(?) (signed), and falls through when a4(?) < v0(?) (signed).
  The `bltz` branch at 0x1d9c targets 0x1ddc, is taken when a2(?) < 0 (signed), and falls through when a2(?) >= 0 (signed).
  The `bne` branch at 0x1dbc targets 0x1dd8, is taken when a2(?) < v0(?) (signed), and falls through when a2(?) >= v0(?) (signed).
  The `beq` branch at 0x1dd0 targets 0x1da8, is taken when a2(?) >= v0(?) (signed), and falls through when a2(?) < v0(?) (signed).
  The `beq` branch at 0x1dfc targets 0x1bc8 and is always taken.
  The `bne` branch at 0x1e04 targets 0x1e14, is taken when s1(=[a0]:8) != 0, and falls through when s1(=[a0]:8) == 0.
  The `beq` branch at 0x1e0c targets 0x1bc8 and is always taken.
  The `bltz` branch at 0x1e80 targets 0x1eb8, is taken when a2(?) < 0 (signed), and falls through when a2(?) >= 0 (signed).
  The `bne` branch at 0x1e9c targets 0x1eb8, is taken when a2(?) < a4(?) (signed), and falls through when a2(?) >= a4(?) (signed).
  The `beq` branch at 0x1eb0 targets 0x1e88, is taken when a2(?) >= a4(?) (signed), and falls through when a2(?) < a4(?) (signed).
  The `bltz` branch at 0x1eb8 targets 0x1ef0, is taken when a1(?) < 0 (signed), and falls through when a1(?) >= 0 (signed).
  The `bne` branch at 0x1ed4 targets 0x1ef0, is taken when a1(?) < a4(?) (signed), and falls through when a1(?) >= a4(?) (signed).
  The `beq` branch at 0x1ee8 targets 0x1ec0, is taken when a1(?) >= a4(?) (signed), and falls through when a1(?) < a4(?) (signed).
  The `beq` branch at 0x1f10 targets 0x1bbc and is always taken.
  The return at 0x1bdc has v0 = one of 0x0, 0x6.

- `read_ia` in `IP35/usr/cpu/sysgen/IP35boot/eeprom.o` at 0x1f18 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/eeprom.o`.
  Range: 0x1f18-0x2058 (320 bytes).
  It occupies 320 bytes.
  The `jal` at 0x1f54 calls bzero with a0=sp-200, a1=0x80, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1fa4 calls sc_construct_msg with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=sp-200, a3=0x80, a4=0x6, a5=0x6, a6=0x8, a7=0x0.
  The `jal` at 0x1fc8 calls sc_command_kern with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=sp-200, a3=sp-200, a4=sp-72, a6=ret(sc_construct_msg).
  The `jal` at 0x2014 calls sc_interpret_resp with a0=sp-200, a1=0x5, a2=0x0, a3=sp-208, a4=0x80, a5=sp-72.
  The `beq` branch at 0x1f60 targets 0x2040, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `bltz` branch at 0x1fac targets 0x2048, is taken when v0(=ret(sc_construct_msg)) < 0 (signed), and falls through when v0(=ret(sc_construct_msg)) >= 0 (signed).
  The `beq` branch at 0x1fd0 targets 0x1ffc, is taken when v0(=ret(sc_command_kern)) == 0, and falls through when v0(=ret(sc_command_kern)) != 0.
  The `bltz` branch at 0x201c targets 0x2050, is taken when v0(=ret(sc_interpret_resp)) < 0 (signed), and falls through when v0(=ret(sc_interpret_resp)) >= 0 (signed).
  The `bne` branch at 0x2038 targets 0x1f6c, is taken when v0(?) != 0, and falls through when v0(?) == 0.
  The `beq` branch at 0x2040 targets 0x1fd8 and is always taken.
  The `beq` branch at 0x2048 targets 0x1fd8 and is always taken.
  The `beq` branch at 0x2050 targets 0x1fd8 and is always taken.
  The return at 0x1ff4 has v0 = one of 0x0, 0x1.

- `read_spd` in `IP35/usr/cpu/sysgen/IP35boot/eeprom.o` at 0x2058 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/eeprom.o`.
  Range: 0x2058-0x21a8 (336 bytes).
  It occupies 336 bytes.
  The `jal` at 0x208c calls bzero with a0=sp-184, a1=0x80, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x20e0 calls sc_construct_msg with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=sp-184, a3=0x80, a4=0x6, a5=0x6, a6=0x8, a7=0x0.
  The `jal` at 0x2104 calls sc_command_kern with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=sp-184, a3=sp-184, a4=sp-56, a6=ret(sc_construct_msg).
  The `jal` at 0x214c calls sc_interpret_resp with a0=sp-184, a1=0x5, a2=0x0, a3=sp-192, a4=0x80, a5=sp-56.
  The `beq` branch at 0x2098 targets 0x217c, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `bltz` branch at 0x20e8 targets 0x2184, is taken when v0(=ret(sc_construct_msg)) < 0 (signed), and falls through when v0(=ret(sc_construct_msg)) >= 0 (signed).
  The `beq` branch at 0x210c targets 0x2138, is taken when v0(=ret(sc_command_kern)) == 0, and falls through when v0(=ret(sc_command_kern)) != 0.
  The `bltz` branch at 0x2154 targets 0x218c, is taken when v0(=ret(sc_interpret_resp)) < 0 (signed), and falls through when v0(=ret(sc_interpret_resp)) >= 0 (signed).
  The `bne` branch at 0x2174 targets 0x20a4, is taken when v0(?) != 0, and falls through when v0(?) == 0.
  The `beq` branch at 0x217c targets 0x2118 and is always taken.
  The `beq` branch at 0x2184 targets 0x2118 and is always taken.
  The `beq` branch at 0x21a0 targets 0x2118 and is always taken.
  The return at 0x2130 has v0 = one of 0x0, 0x1, 0x3.

- `read_chassis_ia` in `IP35/usr/cpu/sysgen/IP35boot/eeprom.o` at 0x21a8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/eeprom.o`.
  Range: 0x21a8-0x22b4 (268 bytes).
  It occupies 268 bytes.
  The `sb` at 0x21e0 stores 1 byte to a3 (arg3 at entry) +0x0.
  The `sb` at 0x21f0 stores 1 byte to a3 (arg3 at entry) +0x1.
  The `sb` at 0x21f8 stores 1 byte to a3 (arg3 at entry) +0x2.
  The `sb` at 0x2208 stores 1 byte to a3 (arg3 at entry) +0x3.
  The `lbu` at 0x2214 loads 1 byte from a3 (arg3 at entry) +0x3.
  3 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x2224, `lbu` at 0x2264, `lbu` at 0x227c.
  The `sb` at 0x222c stores 1 byte to a3 (arg3 at entry) +0x18.
  The `lbu` at 0x2238 loads 1 byte from a3 (arg3 at entry) +0x1.
  The `lbu` at 0x2250 loads 1 byte from (([a3+1]:1 << 0x3) + sp-528) -0x1.
  The `sb` at 0x225c stores 1 byte to a3 (arg3 at entry) +0x23.
  The `jal` at 0x21bc calls read_ia with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=0x1, a4=sp-528.
  The `jal` at 0x220c calls bcopy with a0=sp-524, a1=a3+4, a2=?, a3=?.
  The `jal` at 0x2230 calls bcopy with a0=?, a1=a3+25, a2=?, a3=?.
  The `beq` branch at 0x21c4 targets 0x21e0, is taken when v0(=ret(read_ia)) == 0, and falls through when v0(=ret(read_ia)) != 0.
  The `beq` branch at 0x21ec targets 0x22a4, is taken when at(?) == 0, and falls through when at(?) != 0.
  The `bltz` branch at 0x2258 targets 0x22ac, is taken when a4(=([a3+1]:1 << 0x3)-1) < 0 (signed), and falls through when a4(=([a3+1]:1 << 0x3)-1) >= 0 (signed).
  The `bne` branch at 0x2270 targets 0x2294, is taken when a4(=([a3+1]:1 << 0x3)-1) < a2(?) (signed), and falls through when a4(=([a3+1]:1 << 0x3)-1) >= a2(?) (signed).
  The `beq` branch at 0x2288 targets 0x2260, is taken when a4(=([a3+1]:1 << 0x3)-1) >= a2(?) (signed), and falls through when a4(=([a3+1]:1 << 0x3)-1) < a2(?) (signed).
  The `beq` branch at 0x2294 targets 0x22ac, is taken when t2(?) == 0, and falls through when t2(?) != 0.
  The `beq` branch at 0x229c targets 0x21d4 and is always taken.
  The `beq` branch at 0x22a4 targets 0x21d4 and is always taken.
  The `beq` branch at 0x22ac targets 0x21d0 and is always taken.
  The return at 0x21d8 has v0 = one of 0x0, 0x1, 0x3.

- `eeprom_decode_ipmi_fields` in `IP35/usr/cpu/sysgen/IP35boot/eeprom.o` at 0x22b4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/eeprom.o`.
  Range: 0x22b4-0x23a4 (240 bytes).
  It occupies 240 bytes.
  The `ld` at 0x22c4 loads 8 bytes from a0 (arg0 at entry) +0x0.
  The `lbu` at 0x22d4 loads 1 byte from [a0]:8 +0x0.
  The `sb` at 0x22e0 stores 1 byte to a1 (arg1 at entry) +0x2.
  The `sw` at 0x22e4 stores 4 bytes to a1 (arg1 at entry) +0x4.
  The `lbu` at 0x22e8 loads 1 byte from [a0]:8 +0x4.
  The `sb` at 0x22f4 stores 1 byte to a1 (arg1 at entry) +0x8.
  The `lbu` at 0x2300 loads 1 byte from a1 (arg1 at entry) +0x8.
  3 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x2310, `lbu` at 0x2338, `lbu` at 0x2360.
  The `sb` at 0x231c stores 1 byte to a1 (arg1 at entry) +0x13.
  The `lbu` at 0x2328 loads 1 byte from a1 (arg1 at entry) +0x13.
  The `sb` at 0x2344 stores 1 byte to a1 (arg1 at entry) +0x22.
  The `lbu` at 0x2350 loads 1 byte from a1 (arg1 at entry) +0x22.
  The `sb` at 0x236c stores 1 byte to a1 (arg1 at entry) +0x2d.
  The `lbu` at 0x2378 loads 1 byte from a1 (arg1 at entry) +0x2d.
  The `sd` at 0x2394 stores 8 bytes to a0 (arg0 at entry) +0x0.
  The `jal` at 0x22dc calls eeprom_xlate_board_mfr_date with a0=[a0]:8+1, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x22f8 calls bcopy with a0=[a0]:8+5, a1=a1+9, a2=?, a3=?.
  The `jal` at 0x2320 calls bcopy with a0=?, a1=a1+20, a2=?, a3=?.
  The `jal` at 0x2348 calls bcopy with a0=?, a1=a1+35, a2=?, a3=?.
  The `jal` at 0x2370 calls bcopy with a0=?, a1=a1+46, a2=?, a3=?.
  The return at 0x239c has v0 = ret(bcopy).

- `eeprom_decode_sgi_fields` in `IP35/usr/cpu/sysgen/IP35boot/eeprom.o` at 0x23a4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/eeprom.o`.
  Range: 0x23a4-0x2440 (156 bytes).
  It occupies 156 bytes.
  The `ld` at 0x23b0 loads 8 bytes from a0 (arg0 at entry) +0x0.
  The `lbu` at 0x23c0 loads 1 byte from [a0]:8 +0x0.
  The `sb` at 0x23d0 stores 1 byte to a1 (arg1 at entry) +0x42.
  The `lbu` at 0x23dc loads 1 byte from a1 (arg1 at entry) +0x42.
  3 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x23e8, `lbu` at 0x23f0, `lbu` at 0x23fc.
  The `sb` at 0x23ec stores 1 byte to a1 (arg1 at entry) +0x45.
  The `sb` at 0x23f4 stores 1 byte to a1 (arg1 at entry) +0x46.
  The `sb` at 0x2408 stores 1 byte to a1 (arg1 at entry) +0x47.
  The `lbu` at 0x2414 loads 1 byte from a1 (arg1 at entry) +0x47.
  The `sd` at 0x2430 stores 8 bytes to a0 (arg0 at entry) +0x0.
  The `jal` at 0x23d4 calls bcopy with a0=[a0]:8+1, a1=a1+67, a2=?, a3=a3 at entry (arg3).
  The `jal` at 0x240c calls bcopy with a0=?, a1=a1+72, a2=?, a3=?.
  The return at 0x2438 has v0 = ret(bcopy).

- `eeprom_decode_crypt_fields` in `IP35/usr/cpu/sysgen/IP35boot/eeprom.o` at 0x2440 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/eeprom.o`.
  Range: 0x2440-0x24f4 (180 bytes).
  It occupies 180 bytes.
  The `ld` at 0x244c loads 8 bytes from a0 (arg0 at entry) +0x0.
  The `lbu` at 0x245c loads 1 byte from [a0]:8 +0x0.
  The `sb` at 0x246c stores 1 byte to a1 (arg1 at entry) +0x4b.
  The `lbu` at 0x2478 loads 1 byte from a1 (arg1 at entry) +0x4b.
  2 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x2488, `lbu` at 0x24b0.
  The `sb` at 0x2494 stores 1 byte to a1 (arg1 at entry) +0x50.
  The `lbu` at 0x24a0 loads 1 byte from a1 (arg1 at entry) +0x50.
  The `sb` at 0x24bc stores 1 byte to a1 (arg1 at entry) +0x58.
  The `lbu` at 0x24c8 loads 1 byte from a1 (arg1 at entry) +0x58.
  The `sd` at 0x24e4 stores 8 bytes to a0 (arg0 at entry) +0x0.
  The `jal` at 0x2470 calls bcopy with a0=[a0]:8+1, a1=a1+76, a2=?, a3=a3 at entry (arg3).
  The `jal` at 0x2498 calls bcopy with a0=?, a1=a1+84, a2=?, a3=?.
  The `jal` at 0x24c0 calls bcopy with a0=?, a1=a1+92, a2=?, a3=?.
  The return at 0x24ec has v0 = ret(bcopy).

- `eeprom_decode_net_fields` in `IP35/usr/cpu/sysgen/IP35boot/eeprom.o` at 0x24f4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/eeprom.o`.
  Range: 0x24f4-0x2580 (140 bytes).
  It occupies 140 bytes.
  The `ld` at 0x2500 loads 8 bytes from a0 (arg0 at entry) +0x0.
  The `lbu` at 0x2510 loads 1 byte from [a0]:8 +0x0.
  The `sb` at 0x2520 stores 1 byte to a1 (arg1 at entry) +0xb4.
  The `lbu` at 0x252c loads 1 byte from a1 (arg1 at entry) +0xb4.
  The `lbu` at 0x253c loads 1 byte from ?.
  The `sb` at 0x2548 stores 1 byte to a1 (arg1 at entry) +0xc1.
  The `lbu` at 0x2554 loads 1 byte from a1 (arg1 at entry) +0xc1.
  The `sd` at 0x2570 stores 8 bytes to a0 (arg0 at entry) +0x0.
  The `jal` at 0x2524 calls bcopy with a0=[a0]:8+1, a1=a1+181, a2=?, a3=a3 at entry (arg3).
  The `jal` at 0x254c calls bcopy with a0=?, a1=a1+194, a2=?, a3=?.
  The return at 0x2578 has v0 = ret(bcopy).

- `eeprom_decode_config_fields` in `IP35/usr/cpu/sysgen/IP35boot/eeprom.o` at 0x2580 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/eeprom.o`.
  Range: 0x2580-0x274c (460 bytes).
  It occupies 460 bytes.
  The `ld` at 0x258c loads 8 bytes from a0 (arg0 at entry) +0x0.
  The `lbu` at 0x259c loads 1 byte from [a0]:8 +0x0.
  The `sb` at 0x25ac stores 1 byte to a1 (arg1 at entry) +0x61.
  The `lbu` at 0x25b8 loads 1 byte from a1 (arg1 at entry) +0x61.
  9 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x25c8, `lbu` at 0x25f0, `lbu` at 0x2618.
  The `sb` at 0x25d4 stores 1 byte to a1 (arg1 at entry) +0x68.
  The `lbu` at 0x25e0 loads 1 byte from a1 (arg1 at entry) +0x68.
  The `sb` at 0x25fc stores 1 byte to a1 (arg1 at entry) +0x70.
  The `lbu` at 0x2608 loads 1 byte from a1 (arg1 at entry) +0x70.
  The `sb` at 0x2624 stores 1 byte to a1 (arg1 at entry) +0x78.
  The `lbu` at 0x2630 loads 1 byte from a1 (arg1 at entry) +0x78.
  The `sb` at 0x264c stores 1 byte to a1 (arg1 at entry) +0x80.
  The `lbu` at 0x2658 loads 1 byte from a1 (arg1 at entry) +0x80.
  The `sb` at 0x2674 stores 1 byte to a1 (arg1 at entry) +0x88.
  The `lbu` at 0x2680 loads 1 byte from a1 (arg1 at entry) +0x88.
  The `sb` at 0x269c stores 1 byte to a1 (arg1 at entry) +0x90.
  The `lbu` at 0x26a8 loads 1 byte from a1 (arg1 at entry) +0x90.
  The `sb` at 0x26c4 stores 1 byte to a1 (arg1 at entry) +0x98.
  The `lbu` at 0x26d0 loads 1 byte from a1 (arg1 at entry) +0x98.
  The `sb` at 0x26ec stores 1 byte to a1 (arg1 at entry) +0xa1.
  The `lbu` at 0x26f8 loads 1 byte from a1 (arg1 at entry) +0xa1.
  The `sb` at 0x2714 stores 1 byte to a1 (arg1 at entry) +0xaa.
  The `lbu` at 0x2720 loads 1 byte from a1 (arg1 at entry) +0xaa.
  The `sd` at 0x273c stores 8 bytes to a0 (arg0 at entry) +0x0.
  The `jal` at 0x25b0 calls bcopy with a0=[a0]:8+1, a1=a1+100, a2=?, a3=a3 at entry (arg3).
  The `jal` at 0x25d8 calls bcopy with a0=?, a1=a1+108, a2=?, a3=?.
  The `jal` at 0x2600 calls bcopy with a0=?, a1=a1+116, a2=?, a3=?.
  The `jal` at 0x2628 calls bcopy with a0=?, a1=a1+124, a2=?, a3=?.
  The `jal` at 0x2650 calls bcopy with a0=?, a1=a1+132, a2=?, a3=?.
  The `jal` at 0x2678 calls bcopy with a0=?, a1=a1+140, a2=?, a3=?.
  The `jal` at 0x26a0 calls bcopy with a0=?, a1=a1+148, a2=?, a3=?.
  The `jal` at 0x26c8 calls bcopy with a0=?, a1=a1+153, a2=?, a3=?.
  The `jal` at 0x26f0 calls bcopy with a0=?, a1=a1+162, a2=?, a3=?.
  The `jal` at 0x2718 calls bcopy with a0=?, a1=a1+171, a2=?, a3=?.
  The return at 0x2744 has v0 = ret(bcopy).

- `read_board_ia` in `IP35/usr/cpu/sysgen/IP35boot/eeprom.o` at 0x274c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/eeprom.o`.
  Range: 0x274c-0x29b8 (620 bytes).
  It occupies 620 bytes.
  The `sb` at 0x27c4 stores 1 byte to a3 (arg3 at entry) +0x0.
  The `sb` at 0x27e0 stores 1 byte to a3 (arg3 at entry) +0x1.
  The `lbu` at 0x27fc loads 1 byte from a3 (arg3 at entry) +0x0.
  3 such `sb` accesses store 1 byte to a3 (arg3 at entry) +0xb3, including `sb` at 0x2800, `sb` at 0x2850, `sb` at 0x2990.
  4 such `sb` accesses store 1 byte to a3 (arg3 at entry) +0x4a, including `sb` at 0x2804, `sb` at 0x282c, `sb` at 0x297c.
  2 such `sb` accesses store 1 byte to a3 (arg3 at entry) +0x60, including `sb` at 0x280c, `sb` at 0x2964.
  5 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x281c, `lbu` at 0x283c, `lbu` at 0x289c.
  8 such `lbu` accesses load 1 byte from a3 (arg3 at entry) +0x1, including `lbu` at 0x285c, `lbu` at 0x2874, `lbu` at 0x2890.
  The `lbu` at 0x2868 loads 1 byte from (sp-576 + ([a3+1]:1 << 0x3)) -0x1.
  The `sb` at 0x286c stores 1 byte to a3 (arg3 at entry) +0xe2.
  The `jal` at 0x2778 calls bzero with a0=a3 at entry (arg3), a1=0xe4, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x2790 calls read_ia with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=0x2, a4=sp-576.
  The `jal` at 0x27e8 calls eeprom_decode_ipmi_fields with a0=sp-64, a1=a3 at entry (arg3), a2=?, a3=?.
  The `jal` at 0x27f4 calls eeprom_decode_sgi_fields with a0=sp-64, a1=a3 at entry (arg3), a2=?, a3=?.
  The `jal` at 0x2830 calls eeprom_decode_crypt_fields with a0=sp-64, a1=a3 at entry (arg3), a2=?, a3=0x1.
  The `jal` at 0x2854 calls eeprom_decode_net_fields with a0=sp-64, a1=a3 at entry (arg3), a2=?, a3=?, a4=0xc1, a6=0x1.
  The `jal` at 0x2904 calls bcopy with a0=?, a1=sp-56, a2=?, a3=?.
  The `jal` at 0x294c calls printf with a0=sym(.rodata), a1=0x3, a2=?, a3=0x1.
  The `jal` at 0x2968 calls eeprom_decode_config_fields with a0=sp-64, a1=a3 at entry (arg3), a2=?, a3=0x1.
  The `jal` at 0x2980 calls eeprom_decode_crypt_fields with a0=sp-64, a1=a3 at entry (arg3), a2=?, a3=0x1.
  The `jal` at 0x299c calls eeprom_decode_crypt_fields with a0=sp-64, a1=a3 at entry (arg3), a2=?, a3=0x1.
  The `jal` at 0x29a8 calls eeprom_decode_net_fields with a0=sp-64, a1=a3 at entry (arg3), a2=?, a3=?.
  The `beq` branch at 0x279c targets 0x27b8, is taken when v0(=ret(read_ia)) == 0, and falls through when v0(=ret(read_ia)) != 0.
  The `beq` branch at 0x27dc targets 0x28e8, is taken when at(?) == 0, and falls through when at(?) != 0.
  The `beq` branch at 0x2814 targets 0x28f0, is taken when a1(=[a3]:1) >= 0x2 (signed), and falls through when a1(=[a3]:1) < 0x2 (signed).
  The `beq` branch at 0x2820 targets 0x285c, is taken when v0(=0xc1) == a2(?), and falls through when v0(=0xc1) != a2(?).
  The `beq` branch at 0x2844 targets 0x285c, is taken when a4(=0xc1) == a5(?), and falls through when a4(=0xc1) != a5(?).
  The `blez` branch at 0x2880 targets 0x295c, is taken when a7(=[a3+1]:1) <= 0 (signed), and falls through when a7(=[a3+1]:1) > 0 (signed).
  The `beq` branch at 0x28a8 targets 0x28d8, is taken when a0(?) >= t2(=([a3+1]:1 << 0x3)) (signed), and falls through when a0(?) < t2(=([a3+1]:1 << 0x3)) (signed).
  The `bne` branch at 0x28cc targets 0x2888, is taken when a0(?) < t8(=([a3+1]:1 << 0x3)) (signed), and falls through when a0(?) >= t8(=([a3+1]:1 << 0x3)) (signed).
  The `beq` branch at 0x28d8 targets 0x295c, is taken when t9(?) == 0, and falls through when t9(?) != 0.
  The `beq` branch at 0x28e0 targets 0x27ac and is always taken.
  The `beq` branch at 0x28e8 targets 0x27ac and is always taken.
  The `beq` branch at 0x2928 targets 0x2978, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x2930 targets 0x2990, is taken when a3(=0x1) == v0(?), and falls through when a3(=0x1) != v0(?).
  The `beq` branch at 0x2938 targets 0x285c, is taken when v0(?) == a0(=0x2), and falls through when v0(?) != a0(=0x2).
  The `beq` branch at 0x2940 targets 0x2964, is taken when v0(?) == a1(=0x3), and falls through when v0(?) != a1(=0x3).
  The `beq` branch at 0x2954 targets 0x2860 and is always taken.
  The `beq` branch at 0x295c targets 0x27a8 and is always taken.
  The `beq` branch at 0x2970 targets 0x2860 and is always taken.
  The `beq` branch at 0x2988 targets 0x2860 and is always taken.
  The `beq` branch at 0x29b0 targets 0x2860 and is always taken.
  The return at 0x27b0 has v0 = one of 0x0, 0x1, 0x3.

- `_cbrick_eeprom_read` in `IP35/usr/cpu/sysgen/IP35boot/eeprom.o` at 0x29b8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/eeprom.o`.
  Range: 0x29b8-0x2c94 (732 bytes).
  It occupies 732 bytes.
  3 such `lh` accesses load 2 bytes from a1 (arg1 at entry) +0x0, including `lh` at 0x29dc, `lh` at 0x29e0, `lh` at 0x2b14.
  3 such `ld` accesses load 8 bytes from ([a1]:2 << 0x21) -0x6fffffffcc000000, including `ld` at 0x29f0, `ld` at 0x2b24, `ld` at 0x2b44.
  The `ld` at 0x2acc loads 8 bytes from a0 (arg0 at entry) +0x8.
  The `ld` at 0x2b80 loads 8 bytes from a0 (arg0 at entry) +0x10.
  3 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x0, including `ld` at 0x2bcc, `ld` at 0x2bf8, `ld` at 0x2c08.
  The `sb` at 0x2c10 stores 1 byte to [a0]:8 +0x18.
  The `jal` at 0x29d8 calls get_chimera_type with a0=[a1]:2, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x2a28 calls ip27log_getenv with a0=[a1]:2, a1=sym(.rodata), a2=sp-96, a3=0x0, a4=0x0.
  The `jal` at 0x2a40 calls strtoull with a0=sp-96, a1=0x0, a2=0x0, a3=?.
  The `jal` at 0x2a58 calls sc_open with a0=a1 at entry (arg1), a1=0xffff000, a2=?, a3=?.
  The `jal` at 0x2aa0 calls sc_close with a0=a1 at entry (arg1), a1=ret(sc_open), a2=?, a3=0x120, a4=0x100, a5=0x110, a6=0x111.
  The `jal` at 0x2ac8 calls read_board_ia with a0=a1 at entry (arg1), a1=ret(sc_open), a2=?, a3=[a0+8]:8.
  The `jal` at 0x2ad8 calls sc_close with a0=a1 at entry (arg1), a1=ret(sc_open), a2=?, a3=?.
  The `jal` at 0x2b7c calls read_spd with a0=a1 at entry (arg1), a1=ret(sc_open), a2=?, a3=[a0+16]:8, a4=one of 0x100, 0x4000.
  The `jal` at 0x2b8c calls sc_close with a0=a1 at entry (arg1), a1=ret(sc_open), a2=?, a3=?.
  The `jal` at 0x2bc8 calls read_chassis_ia with a0=a1 at entry (arg1), a1=ret(sc_open), a2=0x0, a3=[a0]:8, a4=0x100.
  The `jal` at 0x2be0 calls sc_close with a0=a1 at entry (arg1), a1=ret(sc_open), a2=?, a3=?.
  The `jal` at 0x2c00 calls fake_a_serial_number with a0=[a0]:8+25, a1=?, a2=?, a3=?.
  The `jal` at 0x2c5c calls sc_close with a0=a1 at entry (arg1), a1=ret(sc_open), a2=?, a3=([a1]:2 << 0x21), a4=0x4000.
  The `jal` at 0x2c70 calls sc_close with a0=a1 at entry (arg1), a1=ret(sc_open), a2=?, a3=?, a4=0x100.
  The `jal` at 0x2c84 calls sc_close with a0=a1 at entry (arg1), a1=ret(sc_open), a2=([a1]:2 << 0x21)+0x9000000034000000, a3=?, a4=0x4000.
  The `beq` branch at 0x2a10 targets 0x2b0c, is taken when (s1(=a2) & 0x100) == 0, and falls through when (s1(=a2) & 0x100) != 0.
  The `bltz` branch at 0x2a30 targets 0x2a4c, is taken when v0(=ret(ip27log_getenv)) < 0 (signed), and falls through when v0(=ret(ip27log_getenv)) >= 0 (signed).
  The `bltz` branch at 0x2a64 targets 0x2bb8, is taken when v0(=ret(sc_open)) < 0 (signed), and falls through when v0(=ret(sc_open)) >= 0 (signed).
  The `beq` branch at 0x2a74 targets 0x2b14, is taken when a2(?) == a3(=0x120), and falls through when a2(?) != a3(=0x120).
  The `beq` branch at 0x2a7c targets 0x2bc0, is taken when s1(=a2) == a4(=0x100), and falls through when s1(=a2) != a4(=0x100).
  The `beq` branch at 0x2a88 targets 0x2ab4, is taken when s1(=a2) == a5(=0x110), and falls through when s1(=a2) != a5(=0x110).
  The `beq` branch at 0x2a94 targets 0x2ab4, is taken when s1(=a2) == a6(=0x111), and falls through when s1(=a2) != a6(=0x111).
  The `beq` branch at 0x2aa8 targets 0x2aec and is always taken.
  The `beq` branch at 0x2ab4 targets 0x2ba4, is taken when a7(?) == 0, and falls through when a7(?) != 0.
  The `beq` branch at 0x2ae0 targets 0x2b9c, is taken when s1(=ret(read_board_ia)) == 0, and falls through when s1(=ret(read_board_ia)) != 0.
  The `beq` branch at 0x2b0c targets 0x2aec and is always taken.
  The `beq` branch at 0x2b3c targets 0x2c1c, is taken when t1(?) == t2(=0x8000), and falls through when t1(?) != t2(=0x8000).
  The `beq` branch at 0x2b58 targets 0x2c38, is taken when a4(=0x4000) == a7(?), and falls through when a4(=0x4000) != a7(?).
  The `beq` branch at 0x2b60 targets 0x2c50, is taken when t1(?) == 0, and falls through when t1(?) != 0.
  The `beq` branch at 0x2b68 targets 0x2c58, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `beq` branch at 0x2b94 targets 0x2aec and is always taken.
  The `beq` branch at 0x2b9c targets 0x2af0 and is always taken.
  The `beq` branch at 0x2bb0 targets 0x2ac0 and is always taken.
  The `beq` branch at 0x2bb8 targets 0x2af0 and is always taken.
  The `beq` branch at 0x2bd4 targets 0x2bf0, is taken when v0(=ret(read_chassis_ia)) == 0, and falls through when v0(=ret(read_chassis_ia)) != 0.
  The `beq` branch at 0x2be8 targets 0x2aec and is always taken.
  The `beq` branch at 0x2bf0 targets 0x2c14, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `beq` branch at 0x2c14 targets 0x2ac0 and is always taken.
  The `beq` branch at 0x2c20 targets 0x2c6c, is taken when t0(?) >= 0x4 (signed), and falls through when t0(?) < 0x4 (signed).
  The `beq` branch at 0x2c30 targets 0x2b74 and is always taken.
  The `beq` branch at 0x2c3c targets 0x2c80, is taken when t0(?) >= 0x4 (signed), and falls through when t0(?) < 0x4 (signed).
  The `beq` branch at 0x2c48 targets 0x2b74 and is always taken.
  The `beq` branch at 0x2c50 targets 0x2b74 and is always taken.
  The `beq` branch at 0x2c64 targets 0x2aec and is always taken.
  The `beq` branch at 0x2c78 targets 0x2aec and is always taken.
  The `beq` branch at 0x2c8c targets 0x2aec and is always taken.
  The return at 0x2b04 has v0 = one of ?, 0x0, 0x1.
  The instructions from 0x2ab0 to 0x2ab0 are not reached by any path from the entry, and their branches are not listed.

- `cbrick_eeprom_read` in `IP35/usr/cpu/sysgen/IP35boot/eeprom.o` at 0x2c94 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/eeprom.o`.
  Range: 0x2c94-0x2d1c (136 bytes).
  It occupies 136 bytes.
  The `ld` at 0x2cc4 loads 8 bytes from abs 0xffffffffffffc400.
  The `lh` at 0x2ccc loads 2 bytes from (sym(nasid_to_compact_node) + (a1 + a1)) +0x0.
  The `ld` at 0x2cd0 loads 8 bytes from [-0x3c00]:8 +0x0.
  The `ld` at 0x2cdc loads 8 bytes from ([[-0x3c00]:8]:8 + ([(sym(nasid_to_compact_node) + (a1 + a1))]:2 << 0x3)) +0x0.
  The `ld` at 0x2ce4 loads 8 bytes from [([[-0x3c00]:8]:8 + ([(sym(nasid_to_compact_node) + (a1 + a1))]:2 << 0x3))]:8 +0x8620.
  The `jal` at 0x2cac calls get_nasid with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x2cf4 calls _cbrick_eeprom_read with a0=a0 at entry (arg0), a1=?, a2=a2 at entry (arg2), a3=?.
  The `jal` at 0x2d0c calls get_elsc with a0=?, a1=0x8620, a2=?, a3=?.
  The `beq` branch at 0x2cb4 targets 0x2d0c, is taken when s0(=a1) == v0(=ret(get_nasid)), and falls through when s0(=a1) != v0(=ret(get_nasid)).
  The `beq` branch at 0x2d14 targets 0x2cec and is always taken.
  The return at 0x2d04 has v0 = ret(_cbrick_eeprom_read).

- `nonpeer_iobrick_eeprom_read` in `IP35/usr/cpu/sysgen/IP35boot/eeprom.o` at 0x2d1c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/eeprom.o`.
  Range: 0x2d1c-0x3050 (820 bytes).
  It occupies 820 bytes.
  The `ld` at 0x2dd4 loads 8 bytes from abs 0xffffffffffffc400.
  The `lh` at 0x2ddc loads 2 bytes from (sym(nasid_to_compact_node) + (a1 + a1)) +0x0.
  The `ld` at 0x2de0 loads 8 bytes from [-0x3c00]:8 +0x0.
  The `ld` at 0x2dec loads 8 bytes from ([[-0x3c00]:8]:8 + ([(sym(nasid_to_compact_node) + (a1 + a1))]:2 << 0x3)) +0x0.
  The `ld` at 0x2df8 loads 8 bytes from [([[-0x3c00]:8]:8 + ([(sym(nasid_to_compact_node) + (a1 + a1))]:2 << 0x3))]:8 +0x8620.
  4 such `lh` accesses load 2 bytes from ?, including `lh` at 0x2e00, `lh` at 0x2e40, `lh` at 0x2eb8.
  4 such `ld` accesses load 8 bytes from ?, including `ld` at 0x2e10, `ld` at 0x2e4c, `ld` at 0x2ec4.
  The `ld` at 0x2f40 loads 8 bytes from a0 (arg0 at entry) +0x8.
  2 such `ld` accesses load 8 bytes from abs 0x9000000014000000, including `ld` at 0x2fbc, `ld` at 0x2fdc.
  The `ld` at 0x3010 loads 8 bytes from a0 (arg0 at entry) +0x0.
  The `jal` at 0x2d44 calls get_nasid with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x2d60 calls iobrick_real_l1type_get_nasid with a0=a1 at entry (arg1), a1=a3 at entry (arg3), a2=?, a3=?.
  The `jal` at 0x2db0 calls get_elsc with a0=0x38, a1=?, a2=?, a3=?, a6=0x1.
  The `jal` at 0x2e24 calls get_chimera_type with a0=?, a1=0xfff0000, a2=?, a3=?.
  The `jal` at 0x2e7c calls get_chimera_type with a0=?, a1=one of 0xe, 0xfff0000, a2=0xf, a3=?.
  The `jal` at 0x2ed4 calls get_chimera_type with a0=?, a1=0xfff0000, a2=?, a3=?.
  The `jal` at 0x2ee8 calls sc_open with a0=?, a1=one of 0xffff000, 0x4ffff000, a2=?, a3=?.
  The `jal` at 0x2f20 calls sc_close with a0=?, a1=ret(sc_open), a2=0x430, a3=0x400, a4=0x410.
  The `jal` at 0x2f3c calls read_board_ia with a0=?, a1=ret(sc_open), a2=one of 0x0, 0x1, 0x2, 0x4, a3=[a0+8]:8.
  The `jal` at 0x2f4c calls sc_close with a0=?, a1=ret(sc_open), a2=?, a3=?.
  The `jal` at 0x300c calls read_chassis_ia with a0=?, a1=ret(sc_open), a2=one of 0x0, 0x1, 0x4, a3=[a0]:8.
  The `jal` at 0x3020 calls sc_close with a0=?, a1=ret(sc_open), a2=?, a3=?.
  The `beq` branch at 0x2d54 targets 0x2f88, is taken when (s2(=a2) & 0x400) == 0, and falls through when (s2(=a2) & 0x400) != 0.
  The `beq` branch at 0x2d6c targets 0x2dc0, is taken when v0(=ret(iobrick_real_l1type_get_nasid)) == v1(=0x37), and falls through when v0(=ret(iobrick_real_l1type_get_nasid)) != v1(=0x37).
  The `beq` branch at 0x2d74 targets 0x2dc0, is taken when v0(=ret(iobrick_real_l1type_get_nasid)) == a0(=0x38), and falls through when v0(=ret(iobrick_real_l1type_get_nasid)) != a0(=0x38).
  The `beq` branch at 0x2d7c targets 0x2dc0, is taken when v0(=ret(iobrick_real_l1type_get_nasid)) == a1(=0x39), and falls through when v0(=ret(iobrick_real_l1type_get_nasid)) != a1(=0x39).
  The `beq` branch at 0x2d84 targets 0x2dc0, is taken when v0(=ret(iobrick_real_l1type_get_nasid)) == a2(=0x51), and falls through when v0(=ret(iobrick_real_l1type_get_nasid)) != a2(=0x51).
  The `beq` branch at 0x2d8c targets 0x2dc4, is taken when v0(=ret(iobrick_real_l1type_get_nasid)) == a3(=0x56), and falls through when v0(=ret(iobrick_real_l1type_get_nasid)) != a3(=0x56).
  The `beq` branch at 0x2d98 targets 0x2dc0, is taken when v0(=ret(iobrick_real_l1type_get_nasid)) == a4(=0x30), and falls through when v0(=ret(iobrick_real_l1type_get_nasid)) != a4(=0x30).
  The `beq` branch at 0x2da0 targets 0x2dc4, is taken when v0(=ret(iobrick_real_l1type_get_nasid)) == a5(=0x45), and falls through when v0(=ret(iobrick_real_l1type_get_nasid)) != a5(=0x45).
  The `bne` branch at 0x2da8 targets 0x2dcc, is taken when s3(=a1) != s0(=ret(get_nasid)), and falls through when s3(=a1) == s0(=ret(get_nasid)).
  The `beq` branch at 0x2db8 targets 0x2e00 and is always taken.
  The `beq` branch at 0x2dc4 targets 0x2db0, is taken when s3(=a1) == s0(=ret(get_nasid)), and falls through when s3(=a1) != s0(=ret(get_nasid)).
  The `beq` branch at 0x2e1c targets 0x2ee4, is taken when at(=0x4000) == v0(?), and falls through when at(=0x4000) != v0(?).
  The `beq` branch at 0x2e30 targets 0x2ee4, is taken when v0(=ret(get_chimera_type)) == v1(=0x3), and falls through when v0(=ret(get_chimera_type)) != v1(=0x3).
  The `beq` branch at 0x2e38 targets 0x2eb8, is taken when s1(=a3) == 0, and falls through when s1(=a3) != 0.
  The `bne` branch at 0x2e5c targets 0x2e7c, is taken when s3(=0x8000) != a1(?), and falls through when s3(=0x8000) == a1(?).
  The `beq` branch at 0x2e64 targets 0x2e7c, is taken when s1(=a3) == v0(=0x1), and falls through when s1(=a3) != v0(=0x1).
  The `beq` branch at 0x2e6c targets 0x2ee4, is taken when s1(=a3) == a1(=0xe), and falls through when s1(=a3) != a1(=0xe).
  The `beq` branch at 0x2e74 targets 0x2ee4, is taken when s1(=a3) == a2(=0xf), and falls through when s1(=a3) != a2(=0xf).
  The `beq` branch at 0x2e84 targets 0x2eac, is taken when v0(=ret(get_chimera_type)) == 0, and falls through when v0(=ret(get_chimera_type)) != 0.
  The `beq` branch at 0x2e90 targets 0x2eb0, is taken when s1(=a3) == a2(=0x1), and falls through when s1(=a3) != a2(=0x1).
  The `beq` branch at 0x2e98 targets 0x2ee4, is taken when s1(=a3) == a0(=0xc), and falls through when s1(=a3) != a0(=0xc).
  The `beq` branch at 0x2ea4 targets 0x2ee4, is taken when s1(=a3) == a3(=0xf), and falls through when s1(=a3) != a3(=0xf).
  The `beq` branch at 0x2eb0 targets 0x2ee8 and is always taken.
  The `beq` branch at 0x2ecc targets 0x2ee4, is taken when s3(=0x8000) == a2(?), and falls through when s3(=0x8000) != a2(?).
  The `beq` branch at 0x2edc targets 0x2e40, is taken when v0(=ret(get_chimera_type)) == 0, and falls through when v0(=ret(get_chimera_type)) != 0.
  The `bltz` branch at 0x2ef4 targets 0x3038, is taken when v0(=ret(sc_open)) < 0 (signed), and falls through when v0(=ret(sc_open)) >= 0 (signed).
  The `beq` branch at 0x2f00 targets 0x2f90, is taken when s2(=a2) == a2(=0x430), and falls through when s2(=a2) != a2(=0x430).
  The `beq` branch at 0x2f08 targets 0x2fdc, is taken when s2(=a2) == a3(=0x400), and falls through when s2(=a2) != a3(=0x400).
  The `beq` branch at 0x2f14 targets 0x2f30, is taken when s2(=a2) == a4(=0x410), and falls through when s2(=a2) != a4(=0x410).
  The `beq` branch at 0x2f28 targets 0x2f60 and is always taken.
  The `beq` branch at 0x2f54 targets 0x3030, is taken when s1(=ret(read_board_ia)) == 0, and falls through when s1(=ret(read_board_ia)) != 0.
  The `beq` branch at 0x2f88 targets 0x2f60 and is always taken.
  The `beq` branch at 0x2fb4 targets 0x3048, is taken when a5(?) == a6(=0x8000), and falls through when a5(?) != a6(=0x8000).
  The `beq` branch at 0x2fcc targets 0x3048, is taken when a6(=0x4000) == a7(?), and falls through when a6(=0x4000) != a7(?).
  The `beq` branch at 0x2fd4 targets 0x2f34 and is always taken.
  The `beq` branch at 0x2ff0 targets 0x3040, is taken when t2(=0x4000) == t3(?), and falls through when t2(=0x4000) != t3(?).
  The `beq` branch at 0x3014 targets 0x2f30, is taken when v0(=ret(read_chassis_ia)) == 0, and falls through when v0(=ret(read_chassis_ia)) != 0.
  The `beq` branch at 0x3028 targets 0x2f60 and is always taken.
  The `beq` branch at 0x3030 targets 0x2f64 and is always taken.
  The `beq` branch at 0x3038 targets 0x2f64 and is always taken.
  The `beq` branch at 0x3040 targets 0x3000 and is always taken.
  The `beq` branch at 0x3048 targets 0x2f60 and is always taken.
  The return at 0x2f80 has v0 = one of ?, 0x0, 0x1.

- `peer_iobrick_eeprom_read` in `IP35/usr/cpu/sysgen/IP35boot/eeprom.o` at 0x3050 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/eeprom.o`.
  Range: 0x3050-0x3194 (324 bytes).
  It occupies 324 bytes.
  The `ld` at 0x3104 loads 8 bytes from a0 (arg0 at entry) +0x8.
  The `ld` at 0x3168 loads 8 bytes from a0 (arg0 at entry) +0x0.
  The `jal` at 0x3070 calls get_elsc with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x30a0 calls sc_open with a0=ret(get_elsc), a1=((a1 << 0x12) | (a2 << 0xc)), a2=(a2 << 0xc), a3=?, a6=0x6.
  The `jal` at 0x30e0 calls sc_close with a0=ret(get_elsc), a1=ret(sc_open), a2=0x410, a3=0x420, a6=0x1.
  The `jal` at 0x3100 calls read_board_ia with a0=ret(get_elsc), a1=ret(sc_open), a2=?, a3=[a0+8]:8.
  The `jal` at 0x3110 calls sc_close with a0=ret(get_elsc), a1=ret(sc_open), a2=?, a3=?.
  The `jal` at 0x3164 calls read_chassis_ia with a0=ret(get_elsc), a1=ret(sc_open), a2=0x1, a3=[a0]:8, a6=0x1.
  The `jal` at 0x317c calls sc_close with a0=ret(get_elsc), a1=ret(sc_open), a2=0x1, a3=?.
  The `beq` branch at 0x3084 targets 0x3120, is taken when (s1(=a3) & 0x400) == 0, and falls through when (s1(=a3) & 0x400) != 0.
  The `bltz` branch at 0x30bc targets 0x3154, is taken when v0(=ret(sc_open)) < 0 (signed), and falls through when v0(=ret(sc_open)) >= 0 (signed).
  The `beq` branch at 0x30c8 targets 0x315c, is taken when v0(?) == a1(=0x400), and falls through when v0(?) != a1(=0x400).
  The `beq` branch at 0x30d0 targets 0x3140, is taken when v0(?) == a2(=0x410), and falls through when v0(?) != a2(=0x410).
  The `beq` branch at 0x30d8 targets 0x30f0, is taken when v0(?) == a3(=0x420), and falls through when v0(?) != a3(=0x420).
  The `beq` branch at 0x30e8 targets 0x3120 and is always taken.
  The `beq` branch at 0x3118 targets 0x3148, is taken when s1(=ret(read_board_ia)) == 0, and falls through when s1(=ret(read_board_ia)) != 0.
  The `beq` branch at 0x3140 targets 0x30f8 and is always taken.
  The `beq` branch at 0x314c targets 0x3124 and is always taken.
  The `beq` branch at 0x3154 targets 0x3124 and is always taken.
  The `beq` branch at 0x3170 targets 0x318c, is taken when v0(=ret(read_chassis_ia)) == 0, and falls through when v0(=ret(read_chassis_ia)) != 0.
  The `beq` branch at 0x3184 targets 0x3120 and is always taken.
  The `beq` branch at 0x318c targets 0x30fc and is always taken.
  The return at 0x3138 has v0 = one of ?, 0x0, 0x1.

- `iobrick_eeprom_read` in `IP35/usr/cpu/sysgen/IP35boot/eeprom.o` at 0x3194 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/eeprom.o`.
  Range: 0x3194-0x3228 (148 bytes).
  It occupies 148 bytes.
  The `ld` at 0x31a0 loads 8 bytes from (a1 << 0x21) -0x6fffffffcc000000.
  The `jal` at 0x31d4 calls peer_iobrick_rack_bay_get with a0=a1 at entry (arg1), a1=sp-32, a2=sp-28, a3=a3 at entry (arg3).
  The `jal` at 0x31ec calls nonpeer_iobrick_eeprom_read with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x3218 calls peer_iobrick_eeprom_read with a0=a0 at entry (arg0), a1=?, a2=?, a3=a2 at entry (arg2).
  The `bne` branch at 0x31c4 targets 0x31ec, is taken when at(?) != v1(=0xc000), and falls through when at(?) == v1(=0xc000).
  The `beq` branch at 0x31dc targets 0x3210, is taken when v0(=ret(peer_iobrick_rack_bay_get)) == 0, and falls through when v0(=ret(peer_iobrick_rack_bay_get)) != 0.
  The `beq` branch at 0x31e4 targets 0x31f8 and is always taken.
  The `beq` branch at 0x3220 targets 0x31f8 and is always taken.
  The return at 0x3208 has v0 = one of 0x2, ret(nonpeer_iobrick_eeprom_read), ret(peer_iobrick_eeprom_read).

- `gbrick_eeprom_read` in `IP35/usr/cpu/sysgen/IP35boot/eeprom.o` at 0x3228 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/eeprom.o`.
  Range: 0x3228-0x3354 (300 bytes).
  It occupies 300 bytes.
  The `ld` at 0x327c loads 8 bytes from abs 0xffffffffffffc400.
  The `lh` at 0x3280 loads 2 bytes from (sym(nasid_to_compact_node) + (a1 + a1)) +0x0.
  The `ld` at 0x3284 loads 8 bytes from [-0x3c00]:8 +0x0.
  The `ld` at 0x3290 loads 8 bytes from ([[-0x3c00]:8]:8 + ([(sym(nasid_to_compact_node) + (a1 + a1))]:2 << 0x3)) +0x0.
  The `ld` at 0x3298 loads 8 bytes from [([[-0x3c00]:8]:8 + ([(sym(nasid_to_compact_node) + (a1 + a1))]:2 << 0x3))]:8 +0x8620.
  The `ld` at 0x32c4 loads 8 bytes from abs 0x9000000014000000.
  The `ld` at 0x32f0 loads 8 bytes from a0 (arg0 at entry) +0x8.
  The `jal` at 0x3244 calls get_chimera_type with a0=a1 at entry (arg1), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x324c calls get_nasid with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x32a8 calls sc_open with a0=?, a1=0xffff000, a2=?, a3=?.
  The `jal` at 0x32ec calls read_board_ia with a0=?, a1=ret(sc_open), a2=?, a3=[a0+8]:8, a5=0x1.
  The `jal` at 0x32fc calls sc_close with a0=?, a1=ret(sc_open), a2=?, a3=?.
  The `jal` at 0x3328 calls get_elsc with a0=(a1 + a1), a1=sym(nasid_to_compact_node), a2=?, a3=?, a5=0x6.
  The `beq` branch at 0x326c targets 0x330c, is taken when (s0(=a2) & 0x800) == 0, and falls through when (s0(=a2) & 0x800) != 0.
  The `beq` branch at 0x3274 targets 0x3328, is taken when s1(=a1) == v0(=ret(get_nasid)), and falls through when s1(=a1) != v0(=ret(get_nasid)).
  The `bltz` branch at 0x32bc targets 0x334c, is taken when v0(=ret(sc_open)) < 0 (signed), and falls through when v0(=ret(sc_open)) >= 0 (signed).
  The `beq` branch at 0x32cc targets 0x3338, is taken when a2(?) == a3(=0x4000), and falls through when a2(?) != a3(=0x4000).
  The `beq` branch at 0x3304 targets 0x3340, is taken when s2(=ret(read_board_ia)) == 0, and falls through when s2(=ret(read_board_ia)) != 0.
  The `beq` branch at 0x3330 targets 0x32a0 and is always taken.
  The `beq` branch at 0x3338 targets 0x32e0 and is always taken.
  The `beq` branch at 0x3344 targets 0x3310 and is always taken.
  The `beq` branch at 0x334c targets 0x3310 and is always taken.
  The return at 0x3320 has v0 = one of ?, 0x0, 0x1.

- `vector_eeprom_read` in `IP35/usr/cpu/sysgen/IP35boot/eeprom.o` at 0x3354 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/eeprom.o`.
  Range: 0x3354-0x34a0 (332 bytes).
  It occupies 332 bytes.
  The `ld` at 0x3424 loads 8 bytes from a0 (arg0 at entry) +0x8.
  The `ld` at 0x346c loads 8 bytes from a0 (arg0 at entry) +0x0.
  The `jal` at 0x33ac calls sc_init with a0=sp-2416, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a6=0x6.
  The `jal` at 0x33c0 calls sc_open with a0=sp-2416, a1=0xffff000, a2=?, a3=?.
  The `jal` at 0x33e8 calls sc_close with a0=sp-2416, a1=ret(sc_open), a2=0x1, a3=?.
  The `jal` at 0x33fc calls sc_init with a0=sp-2416, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a6=0x6.
  The `jal` at 0x340c calls _cbrick_eeprom_read with a0=a0 at entry (arg0), a1=sp-2416, a2=a3 at entry (arg3), a3=?.
  The `jal` at 0x3428 calls read_board_ia with a0=sp-2416, a1=ret(sc_open), a2=one of 0x0, 0x1, a3=[a0+8]:8.
  The `jal` at 0x3438 calls sc_close with a0=sp-2416, a1=ret(sc_open), a2=?, a3=?.
  The `jal` at 0x3470 calls read_chassis_ia with a0=sp-2416, a1=ret(sc_open), a2=0x1, a3=[a0]:8.
  The `jal` at 0x3484 calls sc_close with a0=sp-2416, a1=ret(sc_open), a2=?, a3=?.
  The `beq` branch at 0x3374 targets 0x3394, is taken when (a3 & 0x300) == 0, and falls through when (a3 & 0x300) != 0.
  The `beq` branch at 0x3384 targets 0x33ac, is taken when a0(?) == v1(=0x200), and falls through when a0(?) != v1(=0x200).
  The `beq` branch at 0x338c targets 0x33fc, is taken when a0(?) == v0(=0x100), and falls through when a0(?) != v0(=0x100).
  The `bltz` branch at 0x33d0 targets 0x345c, is taken when v0(=ret(sc_open)) < 0 (signed), and falls through when v0(=ret(sc_open)) >= 0 (signed).
  The `beq` branch at 0x33d8 targets 0x3468, is taken when s0(=a3) == a2(=0x200), and falls through when s0(=a3) != a2(=0x200).
  The `beq` branch at 0x33e0 targets 0x341c, is taken when s0(=a3) == a0(=0x210), and falls through when s0(=a3) != a0(=0x210).
  The `beq` branch at 0x33f4 targets 0x3394 and is always taken.
  The `beq` branch at 0x3414 targets 0x3394 and is always taken.
  The `beq` branch at 0x3444 targets 0x3454, is taken when s0(=ret(read_board_ia)) == 0, and falls through when s0(=ret(read_board_ia)) != 0.
  The `beq` branch at 0x344c targets 0x3398 and is always taken.
  The `beq` branch at 0x3454 targets 0x3394 and is always taken.
  The `beq` branch at 0x3460 targets 0x3394 and is always taken.
  The `beq` branch at 0x3478 targets 0x3498, is taken when v0(=ret(read_chassis_ia)) == 0, and falls through when v0(=ret(read_chassis_ia)) != 0.
  The `beq` branch at 0x3490 targets 0x3394 and is always taken.
  The `beq` branch at 0x3498 targets 0x3420 and is always taken.
  The return at 0x33a4 has v0 = one of ?, ret(read_board_ia).
