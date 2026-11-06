# Instruction readings from hostfacts

These entries record instruction facts rendered from the routines below. They describe software behavior, not hardware behavior, and each locator names an address in the identified binary.

- `elsc_lock` in `IP27/usr/cpu/sysgen/IP27boot/elsc.o` at 0xfd0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/elsc.o`.
  Range: 0xfd0-0x10e8 (280 bytes).
  It occupies 280 bytes.
  2 such `ld` accesses load 8 bytes from abs 0x9200000001030100, including `ld` at 0xfdc, `ld` at 0x1048.
  The `jal` at 0x1030 calls sprintf with a0=a0+440, a1=sym(.rodata), a2=a3 at entry (arg3), a3=?, a4=0x3e8.
  The `jal` at 0x1040 calls us_delay with a0=a1 at entry (arg1), a1=?, a2=?, a3=?, a4=0x0, a6=0x30.
  The `jal` at 0x1078 calls elsc_command with a0=a0 at entry (arg0), a1=0x0, a2=?, a3=?.
  The `jal` at 0x1094 calls elsc_parse with a0=a0 at entry (arg0), a1=sp-144, a2=0x0, a3=0x0, a4=ret(elsc_command).
  The `beq` branch at 0x1038 targets 0x1078 and is always taken.
  The `beq` branch at 0x1070 targets 0x10e0, is taken when a4(?) >= s3(?) (unsigned), and falls through when a4(?) < s3(?) (unsigned).
  The `bltz` branch at 0x1080 targets 0x10bc, is taken when v0(=ret(elsc_command)) < 0 (signed), and falls through when v0(=ret(elsc_command)) >= 0 (signed).
  The `bltz` branch at 0x109c targets 0x10bc, is taken when v0(=ret(elsc_parse)) < 0 (signed), and falls through when v0(=ret(elsc_parse)) >= 0 (signed).
  The `beq` branch at 0x10ac targets 0x10bc, is taken when a6(=0x30) == v0(?), and falls through when a6(=0x30) != v0(?).
  The `bne` branch at 0x10b4 targets 0x1040, is taken when s1(=a3) != v0(?), and falls through when s1(=a3) == v0(?).
  The `beq` branch at 0x10e0 targets 0x10bc and is always taken.
  The return at 0x10d8 has v0 = one of ret(elsc_command), ret(elsc_parse), 0x0, -0x79.
- `flash_write_enable` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x2540 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/kernel.o`.
  Range: 0x2540-0x2558 (24 bytes).
  It occupies 24 bytes.
  The `ld` at 0x2544 loads 8 bytes from abs 0xffffffffbf310008.
  The `sd` at 0x2554 stores 8 bytes to abs 0xffffffffbf310008.
  The return at 0x2550 has v0 = 0xffffffffbf310000.
- `flash_write_disable` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x2558 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/kernel.o`.
  Range: 0x2558-0x2574 (28 bytes).
  It occupies 28 bytes.
  The `ld` at 0x255c loads 8 bytes from abs 0xffffffffbf310008.
  The `sd` at 0x2570 stores 8 bytes to abs 0xffffffffbf310008.
  The return at 0x256c has v0 = 0xffffffffbf310000.
- `add_vice` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x8168 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/kernel.o`.
  Range: 0x8168-0x81e4 (124 bytes).
  It occupies 124 bytes.
  The `sw` at 0x8184 stores 4 bytes to abs 0xffffffffb700e014.
  The `sw` at 0x8194 stores 4 bytes to abs 0xffffffffb70001bc.
  The `ld` at 0x81a0 loads 8 bytes from abs 0xffffffffb4000010.
  The `lw` at 0x81bc loads 4 bytes from abs 0xffffffffb7000164.
  The `sw` at 0x81c8 stores 4 bytes to abs 0xffffffffb700e00c.
  The `lw` at 0x81d4 loads 4 bytes from abs 0xffffffffb700000c.
  The `jal` at 0x8180 calls us_delay with a0=0xa, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x8190 calls us_delay with a0=0xa, a1=?, a2=?, a3=?.
  The `jal` at 0x81d0 calls add_to_inventory with a0=0xf, a1=0x3, a2=0x0, a3=0x0, a4=[0xffffffffb700000c], a5=[0xffffffffb7000164], a6=0xffffffffb700e00c.
  The `beq` branch at 0x81ac targets 0x81d8, is taken when (a0(=[0xffffffffb4000010]:8) & a1(=0x80000000)) == 0, and falls through when (a0(=[0xffffffffb4000010]:8) & a1(=0x80000000)) != 0.
  The return at 0x81dc has v0 = one of ret(us_delay), ret(add_to_inventory).
- `crimestray` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x9f20 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/kernel.o`.
  Range: 0x9f20-0x9f54 (52 bytes).
  It occupies 52 bytes.
  The `jal` at 0x9f34 calls cmn_err with a0=0x4, a1=sym(.rodata)+5968, a2=a1 at entry (arg1), a3=a3 at entry (arg3).
  The return at 0x9f4c has v0 = ret(cmn_err).
- `crime_intr` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0xa2cc (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/kernel.o`.
  Range: 0xa2cc-0xa578 (684 bytes).
  It occupies 684 bytes.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x138, including `ld` at 0xa2f8, `ld` at 0xa4d0.
  2 such `ld` accesses load 8 bytes from abs 0xffffffffb4000010, including `ld` at 0xa304, `ld` at 0xa32c.
  The `sw` at 0xa364 stores 4 bytes to (sp-208 + ([sym(.data)+2876]:2 << 0x2)) +0x0.
  The `lh` at 0xa370 loads 2 bytes from sym(.data) +0xb0c.
  The `sw` at 0xa394 stores 4 bytes to (sp-208 + ([sym(.data)+2828]:2 << 0x2)) +0x0.
  The `lh` at 0xa3a0 loads 2 bytes from sym(.data) +0xb3c.
  3 such `lw` accesses load 4 bytes from table(sym(.data)+2816) +0x98, including `lw` at 0xa3d0, `lw` at 0xa44c, `lw` at 0xa4fc.
  5 such `ld` accesses load 8 bytes from table(sym(.data)+2816) +0xa0, including `ld` at 0xa3d8, `ld` at 0xa474, `ld` at 0xa4cc.
  3 such `ld` accesses load 8 bytes from ?, including `ld` at 0xa3f8, `ld` at 0xa480, `ld` at 0xa518.
  3 such `sd` accesses store 8 bytes to ?, including `sd` at 0xa40c, `sd` at 0xa494, `sd` at 0xa52c.
  The `lw` at 0xa42c loads 4 bytes from ?.
  2 such `lh` accesses load 2 bytes from table(sym(.data)+2816) +0x9e, including `lh` at 0xa448, `lh` at 0xa4bc.
  The `lw` at 0xa454 loads 4 bytes from table(sym(.data)+2816) +0xa8.
  The `lw` at 0xa4a8 loads 4 bytes from table(sym(.data)+2816) +0x90.
  The `lw` at 0xa4b8 loads 4 bytes from table(sym(.data)+2816) +0x94.
  2 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x138, including `sd` at 0xa4dc, `sd` at 0xa540.
  The `jal` at 0xa3c8 calls splint with a0=[table(sym(.data)+2816)+152], a1=?, a2=?, a3=?.
  The `jal` at 0xa410 calls vsema with a0=table(sym(.data)+2816)+172, a1=?, a2=?, a3=?.
  The `jal` at 0xa418 calls splx with a0=ret(splint), a1=?, a2=?, a3=?.
  The `jal` at 0xa4a0 calls splint with a0=[table(sym(.data)+2816)+152], a1=?, a2=?, a3=?.
  The `jalr` at 0xa4b4 calls (unknown callee) with a0=a0 at entry (arg0), a1=[table(sym(.data)+2816)+148], a2=?, a3=?.
  The `jal` at 0xa4ec calls splx with a0=ret(splint), a1=?, a2=?, a3=?.
  The `beq` branch at 0xa31c targets 0xa56c and is always taken.
  The `beq` branch at 0xa338 targets 0xa538, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `beq` branch at 0xa34c targets 0xa368 and is always taken.
  The `beq` branch at 0xa360 targets 0xa3c0, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0xa378 targets 0xa3b8, is taken when (a6(?) & v0(?)) == 0, and falls through when (a6(?) & v0(?)) != 0.
  The `beq` branch at 0xa390 targets 0xa3c0, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `bne` branch at 0xa3a8 targets 0xa354, is taken when t0(?) != 0, and falls through when t0(?) == 0.
  The `beq` branch at 0xa3b0 targets 0xa358 and is always taken.
  The `beq` branch at 0xa3b8 targets 0xa388 and is always taken.
  The `beq` branch at 0xa3c0 targets 0xa430 and is always taken.
  The `blez` branch at 0xa3ec targets 0xa410, is taken when a3(?) <= 0 (signed), and falls through when a3(?) > 0 (signed).
  The `bne` branch at 0xa408 targets 0xa3f4, is taken when a6(?) < a3(?) (signed), and falls through when a6(?) >= a3(?) (signed).
  The `beq` branch at 0xa424 targets 0xa324, is taken when s7(?) == 0, and falls through when s7(?) != 0.
  The `beq` branch at 0xa438 targets 0xa420, is taken when v1(?) == s6(=-0x1), and falls through when v1(?) != s6(=-0x1).
  The `beq` branch at 0xa464 targets 0xa498, is taken when (a1(=[table(sym(.data)+2816)+158]:2) & 0x4) == 0, and falls through when (a1(=[table(sym(.data)+2816)+158]:2) & 0x4) != 0.
  The `blez` branch at 0xa46c targets 0xa498, is taken when a3(?) <= 0 (signed), and falls through when a3(?) > 0 (signed).
  The `bne` branch at 0xa490 targets 0xa47c, is taken when a5(?) < a3(?) (signed), and falls through when a5(?) >= a3(?) (signed).
  The `bne` branch at 0xa498 targets 0xa3c8, is taken when a6(?) != 0, and falls through when a6(?) == 0.
  The `beq` branch at 0xa4c4 targets 0xa4fc, is taken when (t1(=[table(sym(.data)+2816)+158]:2) & 0x4) == 0, and falls through when (t1(=[table(sym(.data)+2816)+158]:2) & 0x4) != 0.
  The `beq` branch at 0xa4f4 targets 0xa424 and is always taken.
  The `blez` branch at 0xa508 targets 0xa4ec, is taken when a3(?) <= 0 (signed), and falls through when a3(?) > 0 (signed).
  The `bne` branch at 0xa528 targets 0xa514, is taken when a5(?) < a3(?) (signed), and falls through when a5(?) >= a3(?) (signed).
  The `beq` branch at 0xa530 targets 0xa4ec and is always taken.
  The `beq` branch at 0xa570 targets 0xa344 and is always taken.
  The return at 0xa564 has v0 = ?.
- `ecc_fixmem` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0xddec (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/kernel.o`.
  Range: 0xddec-0xde60 (116 bytes).
  It occupies 116 bytes.
  The `ld` at 0xde18 loads 8 bytes from table(sym(.bss)+6144) +0x68.
  The `lw` at 0xde1c loads 4 bytes from table(sym(.bss)+6144) +0x7c.
  2 such `sd` accesses store 8 bytes to a2 (arg2 at entry) +0x8, including `sd` at 0xde28, `sd` at 0xde5c.
  The `lw` at 0xde2c loads 4 bytes from table(sym(.bss)+6144) +0x80.
  The `sw` at 0xde30 stores 4 bytes to table(sym(.bss)+6144) +0x84.
  The `sw` at 0xde34 stores 4 bytes to table(sym(.bss)+6144) +0x88.
  The `ld` at 0xde3c loads 8 bytes from abs 0xffffffffb4000260.
  The `sw` at 0xde48 stores 4 bytes to table(sym(.bss)+6144) +0x8c.
  The `lw` at 0xde4c loads 4 bytes from table(sym(.bss)+6144) +0x78.
  The `bgez` branch at 0xde14 targets 0xde4c, is taken when v0(=([sym(r4000_config)] << 0x2e)) >= 0 (signed), and falls through when v0(=([sym(r4000_config)] << 0x2e)) < 0 (signed).
  The `beq` branch at 0xde58 targets 0xde2c and is always taken.
  The return at 0xde44 has v0 = 0x1.
- `err_save_regs` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0xff08 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/kernel.o`.
  Range: 0xff08-0xff50 (72 bytes).
  It occupies 72 bytes.
  The `ld` at 0xff0c loads 8 bytes from abs 0xffffffffb4000048.
  The `ld` at 0xff14 loads 8 bytes from abs 0xffffffffb4000040.
  The `ld` at 0xff1c loads 8 bytes from abs 0xffffffffb4000250.
  The `ld` at 0xff24 loads 8 bytes from abs 0xffffffffb4000258.
  The `ld` at 0xff2c loads 8 bytes from abs 0xffffffffb4000058.
  The `ld` at 0xff34 loads 8 bytes from abs 0xffffffffb4000268.
  The `ld` at 0xff3c loads 8 bytes from abs 0xffffffffb4000260.
  The `sd` at 0xff44 stores 8 bytes to abs 0xffffffffb4000048.
  The `sd` at 0xff4c stores 8 bytes to abs 0xffffffffb4000250.
  The return at 0xff48 has v0 = [0xffffffffb4000260]:8.
- `rtc_init` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x121f4 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/kernel.o`.
  Range: 0x121f4-0x122b4 (192 bytes).
  It occupies 192 bytes.
  2 such `lbu` accesses load 1 byte from abs 0xffffffffbf3a0b07, including `lbu` at 0x12218, `lbu` at 0x12228.
  2 such `sb` accesses store 1 byte to abs 0xffffffffbf3a0b07, including `sb` at 0x12224, `sb` at 0x12230.
  2 such `lbu` accesses load 1 byte from abs 0xffffffffbf3a0a07, including `lbu` at 0x12234, `lbu` at 0x12278.
  2 such `sb` accesses store 1 byte to abs 0xffffffffbf3a0a07, including `sb` at 0x1223c, `sb` at 0x12290.
  The `lbu` at 0x12240 loads 1 byte from abs 0xffffffffbf3a4a07.
  The `sb` at 0x1224c stores 1 byte to abs 0xffffffffbf3a4a07.
  2 such `lbu` accesses load 1 byte from abs 0xffffffffbf3a4b07, including `lbu` at 0x12250, `lbu` at 0x12260.
  2 such `sb` accesses store 1 byte to abs 0xffffffffbf3a4b07, including `sb` at 0x1225c, `sb` at 0x1226c.
  The `jal` at 0x1220c calls splhi with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1228c calls pciio_pio_read64 with a0=0xffffffffbf310018, a1=-0x20, a2=([0xffffffffbf3a4b07]:1 | 0x9), a3=?, a4=-0x53, a6=-0x4, a7=([0xffffffffbf3a0a07]:1 | 0x10).
  The `jal` at 0x1229c calls pciio_pio_write64 with a0=(ret(pciio_pio_read64) | 0x100), a1=0xffffffffbf310018, a2=?, a3=?.
  The `jal` at 0x122a4 calls splx with a0=ret(splhi), a1=?, a2=?, a3=?.
  The `beq` branch at 0x121fc targets 0x1220c, is taken when at(=[sym(.sdata)+252]) == 0, and falls through when at(=[sym(.sdata)+252]) != 0.
  The `beq` branch at 0x122ac targets 0x12204 and is always taken.
  The return at 0x12204 has v0 = one of ?, ret(splx).
- `_clock_func` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x129e8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/kernel.o`.
  Range: 0x129e8-0x12c28 (576 bytes).
  It occupies 576 bytes.
  The `sb` at 0x12a94 stores 1 byte to a1 (arg1 at entry) +0x0.
  The `sb` at 0x12aa0 stores 1 byte to a1 (arg1 at entry) +0x1.
  The `sb` at 0x12ab4 stores 1 byte to a1 (arg1 at entry) +0x2.
  The `sb` at 0x12ac4 stores 1 byte to a1 (arg1 at entry) +0x3.
  The `sb` at 0x12ad4 stores 1 byte to a1 (arg1 at entry) +0x4.
  The `sb` at 0x12ae0 stores 1 byte to a1 (arg1 at entry) +0x5.
  The `sb` at 0x12af0 stores 1 byte to a1 (arg1 at entry) +0x6.
  The `sb` at 0x12b00 stores 1 byte to a1 (arg1 at entry) +0x7.
  The `lbu` at 0x12b50 loads 1 byte from a1 (arg1 at entry) +0x0.
  The `lbu` at 0x12b60 loads 1 byte from a1 (arg1 at entry) +0x1.
  The `lbu` at 0x12b6c loads 1 byte from a1 (arg1 at entry) +0x2.
  The `lbu` at 0x12b84 loads 1 byte from a1 (arg1 at entry) +0x3.
  The `lbu` at 0x12b90 loads 1 byte from a1 (arg1 at entry) +0x4.
  The `lbu` at 0x12b9c loads 1 byte from a1 (arg1 at entry) +0x5.
  The `lbu` at 0x12ba8 loads 1 byte from a1 (arg1 at entry) +0x6.
  The `lbu` at 0x12bb4 loads 1 byte from a1 (arg1 at entry) +0x7.
  The `jal` at 0x129f8 calls splhi with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x12a58 calls pciio_pio_read8 with a0=0xffffffffbf3a0b07, a1=?, a2=?, a3=?.
  The `jal` at 0x12a68 calls pciio_pio_write8 with a0=?, a1=0xffffffffbf3a0b07, a2=?, a3=?.
  The `jal` at 0x12a70 calls pciio_pio_read8 with a0=0xffffffffbf3a0a07, a1=?, a2=?, a3=?.
  The `jal` at 0x12a80 calls pciio_pio_write8 with a0=?, a1=0xffffffffbf3a0a07, a2=?, a3=?.
  The `jal` at 0x12a88 calls pciio_pio_read8 with a0=0xffffffffbf3a0007, a1=?, a2=?, a3=?.
  The `jal` at 0x12a98 calls pciio_pio_read8 with a0=0xffffffffbf3a0207, a1=?, a2=?, a3=?.
  The `jal` at 0x12aa4 calls pciio_pio_read8 with a0=0xffffffffbf3a0407, a1=?, a2=?, a3=?.
  The `jal` at 0x12ab8 calls pciio_pio_read8 with a0=0xffffffffbf3a0707, a1=?, a2=?, a3=?.
  The `jal` at 0x12ac8 calls pciio_pio_read8 with a0=0xffffffffbf3a0807, a1=?, a2=?, a3=?.
  The `jal` at 0x12ad8 calls pciio_pio_read8 with a0=0xffffffffbf3a0907, a1=?, a2=?, a3=?.
  The `jal` at 0x12ae4 calls pciio_pio_read8 with a0=0xffffffffbf3a0607, a1=?, a2=?, a3=?.
  The `jal` at 0x12af4 calls pciio_pio_read8 with a0=0xffffffffbf3a4807, a1=?, a2=?, a3=?.
  The `jal` at 0x12b04 calls pciio_pio_read8 with a0=0xffffffffbf3a0a07, a1=?, a2=?, a3=?.
  The `jal` at 0x12b14 calls pciio_pio_write8 with a0=?, a1=0xffffffffbf3a0a07, a2=?, a3=?.
  The `jal` at 0x12b1c calls pciio_pio_read8 with a0=0xffffffffbf3a0a07, a1=?, a2=?, a3=?.
  The `jal` at 0x12b30 calls pciio_pio_write8 with a0=?, a1=0xffffffffbf3a0a07, a2=?, a3=?.
  The `jal` at 0x12b38 calls pciio_pio_read8 with a0=0xffffffffbf3a0b07, a1=?, a2=?, a3=?.
  The `jal` at 0x12b48 calls pciio_pio_write8 with a0=?, a1=0xffffffffbf3a0b07, a2=?, a3=?.
  The `jal` at 0x12b54 calls pciio_pio_write8 with a0=[a1]:1, a1=0xffffffffbf3a0007, a2=?, a3=?.
  The `jal` at 0x12b64 calls pciio_pio_write8 with a0=[a1+1]:1, a1=0xffffffffbf3a0207, a2=?, a3=?.
  The `jal` at 0x12b78 calls pciio_pio_write8 with a0=?, a1=0xffffffffbf3a0407, a2=?, a3=?.
  The `jal` at 0x12b88 calls pciio_pio_write8 with a0=[a1+3]:1, a1=0xffffffffbf3a0707, a2=?, a3=?.
  The `jal` at 0x12b94 calls pciio_pio_write8 with a0=[a1+4]:1, a1=0xffffffffbf3a0807, a2=?, a3=?.
  The `jal` at 0x12ba0 calls pciio_pio_write8 with a0=[a1+5]:1, a1=0xffffffffbf3a0907, a2=?, a3=?.
  The `jal` at 0x12bac calls pciio_pio_write8 with a0=[a1+6]:1, a1=0xffffffffbf3a0607, a2=?, a3=?.
  The `jal` at 0x12bb8 calls pciio_pio_write8 with a0=[a1+7]:1, a1=0xffffffffbf3a4807, a2=?, a3=?.
  The `jal` at 0x12be0 calls pciio_pio_read8 with a0=0xffffffffbf3a0b07, a1=?, a2=?, a3=?.
  The `jal` at 0x12bf4 calls pciio_pio_write8 with a0=?, a1=0xffffffffbf3a0b07, a2=?, a3=?.
  The `jal` at 0x12c00 calls splx with a0=ret(splhi), a1=?, a2=?, a3=?.
  The `jal` at 0x12c18 calls rtc_init [0x121f4] with a0=?, a1=?, a2=?, a3=?.
  The `beq` branch at 0x12a24 targets 0x12c18, is taken when at(=[sym(.sdata)+252]) == 0, and falls through when at(=[sym(.sdata)+252]) != 0.
  The `bne` branch at 0x12a50 targets 0x12b04, is taken when t8(=a0) != 0, and falls through when t8(=a0) == 0.
  The `beq` branch at 0x12afc targets 0x12bc0 and is always taken.
  The `beq` branch at 0x12c20 targets 0x12a30 and is always taken.
  The return at 0x12c10 has v0 = ret(splx).
- `setbadclock` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x12dd8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/kernel.o`.
  Range: 0x12dd8-0x12e48 (112 bytes).
  It occupies 112 bytes.
  The `jal` at 0x12de0 calls splhi with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x12df0 calls pciio_pio_read8 with a0=0xffffffffbf3a0a07, a1=?, a2=?, a3=?.
  The `jal` at 0x12e08 calls pciio_pio_write8 with a0=?, a1=0xffffffffbf3a0a07, a2=?, a3=?.
  The `jal` at 0x12e14 calls pciio_pio_read8 with a0=0xffffffffbf3a0e07, a1=?, a2=?, a3=?.
  The `jal` at 0x12e28 calls pciio_pio_write8 with a0=?, a1=0xffffffffbf3a0e07, a2=?, a3=?.
  The `jal` at 0x12e30 calls splx with a0=ret(splhi), a1=?, a2=?, a3=?.
  The return at 0x12e40 has v0 = ret(splx).
- `clearbadclock` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x12e48 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/kernel.o`.
  Range: 0x12e48-0x12ebc (116 bytes).
  It occupies 116 bytes.
  The `jal` at 0x12e50 calls splhi with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x12e60 calls pciio_pio_read8 with a0=0xffffffffbf3a0a07, a1=?, a2=?, a3=?.
  The `jal` at 0x12e78 calls pciio_pio_write8 with a0=?, a1=0xffffffffbf3a0a07, a2=?, a3=?.
  The `jal` at 0x12e84 calls pciio_pio_read8 with a0=0xffffffffbf3a0e07, a1=?, a2=?, a3=?.
  The `jal` at 0x12e9c calls pciio_pio_write8 with a0=?, a1=0xffffffffbf3a0e07, a2=?, a3=?.
  The `jal` at 0x12ea4 calls splx with a0=ret(splhi), a1=?, a2=?, a3=?.
  The return at 0x12eb4 has v0 = ret(splx).
- `isbadclock` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x12ebc (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/kernel.o`.
  Range: 0x12ebc-0x12f20 (100 bytes).
  It occupies 100 bytes.
  The `jal` at 0x12ec4 calls splhi with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x12ed4 calls pciio_pio_read8 with a0=0xffffffffbf3a0a07, a1=?, a2=?, a3=?.
  The `jal` at 0x12eec calls pciio_pio_write8 with a0=?, a1=0xffffffffbf3a0a07, a2=?, a3=?.
  The `jal` at 0x12ef8 calls pciio_pio_read8 with a0=0xffffffffbf3a0e07, a1=?, a2=?, a3=?.
  The `jal` at 0x12f04 calls splx with a0=ret(splhi), a1=?, a2=?, a3=?.
  The return at 0x12f18 has v0 = ?.
- `sn00_vmc` in `IP27/unix` at 0xc000000000025998 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/unix`.
  Range: 0xc000000000025998-0xc000000000025a60 (200 bytes).
  It occupies 200 bytes.
  The `ld` at 0xc000000000025998 loads 8 bytes from abs 0xffffffffffffc400.
  The `lh` at 0xc00000000002599c loads 2 bytes from abs 0xffffffffffffc422.
  The `ld` at 0xc0000000000259a0 loads 8 bytes from [-0x3c00]:8 +0x0.
  The `ld` at 0xc0000000000259b4 loads 8 bytes from (([-0x3bde]:2 << 0x3) + [[-0x3c00]:8]:8) +0x0.
  The `lh` at 0xc0000000000259c8 loads 2 bytes from [(([-0x3bde]:2 << 0x3) + [[-0x3c00]:8]:8)]:8 +0x49aa.
  The `lbu` at 0xc0000000000259d4 loads 1 byte from [(([-0x3bde]:2 << 0x3) + [[-0x3c00]:8]:8)]:8 +0x49a8.
  4 such `sd` accesses store 8 bytes to abs 0x9200000001220050, including `sd` at 0xc000000000025a34, `sd` at 0xc000000000025a38, `sd` at 0xc000000000025a54.
  The `jal` at 0xc0000000000259d0 calls device_inventory_add [0xc0000000001c7988] with a0=a0 at entry (arg0), a1=0xb, a2=0x3, a3=[[(([-0x3bde]:2 << 0x3) + [[-0x3c00]:8]:8)]:8+18858]:2, a4=[[(([-0x3bde]:2 << 0x3) + [[-0x3c00]:8]:8)]:8+18856]:1, a5=0x0.
  The `jal` at 0xc0000000000259e0 calls pcibr_hints_dualslot [0xc000000000077e98] with a0=a0 at entry (arg0), a1=0x2, a2=0x3, a3=?.
  The `jal` at 0xc0000000000259f0 calls pcibr_hints_subdevs [0xc000000000077fb4] with a0=a0 at entry (arg0), a1=0x2, a2=0xff, a3=?.
  The `jal` at 0xc0000000000259f8 calls pcibr_hints_fix_rrbs [0xc000000000077e7c] with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xc000000000025a04 calls pcibr_set_rrb_callback [0xc000000000077f40] with a0=a0 at entry (arg0), a1=0xc000000000025794, a2=?, a3=?.
  The `jal` at 0xc000000000025a10 calls spl65 [0xc00000000003b3a4] with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xc000000000025a18 calls get_my_slotid [0xc00000000003cd64] with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xc000000000025a3c calls splx [0xc00000000003b3f4] with a0=ret(spl65), a1=?, a2=?, a3=0x9200000001220050, a4=0x1.
  The `beq` branch at 0xc000000000025a2c targets 0xc000000000025a54, is taken when a4(=0x1) == a6(?), and falls through when a4(=0x1) != a6(?).
  The `beq` branch at 0xc000000000025a58 targets 0xc000000000025a3c and is always taken.
  The return at 0xc000000000025a4c has v0 = ret(splx).
- `do_powerfail_wars` in `IP27/unix` at 0xc00000000003eb4c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/unix`.
  Range: 0xc00000000003eb4c-0xc00000000003ebf0 (164 bytes).
  It occupies 164 bytes.
  The `ll` at 0xc00000000003eb54 loads 4 bytes from abs 0xc0000000014ca280.
  The `sc` at 0xc00000000003eb60 stores 4 bytes to abs 0xc0000000014ca280.
  The `lh` at 0xc00000000003ebac loads 2 bytes from ?.
  The `ld` at 0xc00000000003ebb8 loads 8 bytes from ?.
  2 such `sd` accesses store 8 bytes to ?, including `sd` at 0xc00000000003ebc4, `sd` at 0xc00000000003ebcc.
  The `jal` at 0xc00000000003eb80 calls llp_pfail_switch [0xc00000000003e73c] with a0=0x8, a1=[0xc0000000014cafc8], a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beql` branch at 0xc00000000003eb64 targets 0xc00000000003eb54, is taken when a0(=[0xc0000000014ca280]+1) == 0, and falls through when a0(=[0xc0000000014ca280]+1) != 0; its branch-likely delay slot `nop` at 0xc00000000003eb68 runs only when taken and is annulled on fall-through.
  The `bne` branch at 0xc00000000003eb70 targets 0xc00000000003ebe8, is taken when at(=[0xc0000000014ca280]+1) != v0(=0x1), and falls through when at(=[0xc0000000014ca280]+1) == v0(=0x1).
  The `beq` branch at 0xc00000000003eb78 targets 0xc00000000003eb88, is taken when a1(=[0xc0000000014cafc8]) == 0, and falls through when a1(=[0xc0000000014cafc8]) != 0.
  The `blez` branch at 0xc00000000003eb98 targets 0xc00000000003ebe8, is taken when a1(=[0xc0000000014d3e1c]) <= 0 (signed), and falls through when a1(=[0xc0000000014d3e1c]) > 0 (signed).
  The `bne` branch at 0xc00000000003ebe0 targets 0xc00000000003eba8, is taken when a1(?) < a5(=[0xc0000000014d3e1c]) (signed), and falls through when a1(?) >= a5(=[0xc0000000014d3e1c]) (signed).
  The return at 0xc00000000003ebe8 has v0 = one of 0x1, ?.
- `do_reset_wars` in `IP27/unix` at 0xc00000000003ebf0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/unix`.
  Range: 0xc00000000003ebf0-0xc00000000003ece8 (248 bytes).
  It occupies 248 bytes.
  2 such `lh` accesses load 2 bytes from ?, including `lh` at 0xc00000000003ec4c, `lh` at 0xc00000000003ec60.
  The `sd` at 0xc00000000003ec5c stores 8 bytes to table(0x9200000001e38100) +0x0.
  The `sd` at 0xc00000000003ec74 stores 8 bytes to table(0x9200000001e38000) +0x0.
  The `jal` at 0xc00000000003ec04 calls part_id [0xc0000000003c2220] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xc00000000003eca4 calls nasid_to_partid [0xc0000000003c2238] with a0=?, a1=?, a2=?, a3=?.
  The `blez` branch at 0xc00000000003ec20 targets 0xc00000000003ecc8, is taken when s4(?) <= 0 (signed), and falls through when s4(?) > 0 (signed).
  The `beq` branch at 0xc00000000003ec28 targets 0xc00000000003eca4 and is always taken.
  The `bne` branch at 0xc00000000003ec88 targets 0xc00000000003ec48, is taken when a2(?) < a5(=[0xc0000000014d3e24]) (signed), and falls through when a2(?) >= a5(=[0xc0000000014d3e24]) (signed).
  The `beq` branch at 0xc00000000003ec9c targets 0xc00000000003ecc8, is taken when s3(?) >= 0x100 (signed), and falls through when s3(?) < 0x100 (signed).
  The `beq` branch at 0xc00000000003ecb0 targets 0xc00000000003ec90, is taken when v0(=ret(nasid_to_partid)) == s4(?), and falls through when v0(=ret(nasid_to_partid)) != s4(?).
  The `bgtz` branch at 0xc00000000003ecb8 targets 0xc00000000003ec30, is taken when a3(=[0xc0000000014d3e24]) > 0 (signed), and falls through when a3(=[0xc0000000014d3e24]) <= 0 (signed).
  The `beq` branch at 0xc00000000003ecc0 targets 0xc00000000003ec94 and is always taken.
  The return at 0xc00000000003ece0 has v0 = one of ret(part_id), ret(nasid_to_partid).
- `msc_intr` in `IP27/unix` at 0xc00000000003f564 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/unix`.
  Range: 0xc00000000003f564-0xc00000000003f720 (444 bytes).
  It occupies 444 bytes.
  The `ld` at 0xc00000000003f584 loads 8 bytes from abs 0xffffffffffffc400.
  The `lh` at 0xc00000000003f58c loads 2 bytes from [-0x3c00]:8 +0x49aa.
  2 such `lw` accesses load 4 bytes from ret(module_lookup) +0x2ec, including `lw` at 0xc00000000003f590, `lw` at 0xc00000000003f5a4.
  The `sw` at 0xc00000000003f5a0 stores 4 bytes to (ret(module_lookup) + ([ret(module_lookup)+748] << 0x2)) +0x2ac.
  The `sw` at 0xc00000000003f5c4 stores 4 bytes to ret(module_lookup) +0x2ec.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0xc00000000003f5e8, `lw` at 0xc00000000003f618.
  The `lw` at 0xc00000000003f648 loads 4 bytes from ret(module_lookup) +0x314.
  The `sw` at 0xc00000000003f680 stores 4 bytes to ret(module_lookup) +0x318.
  The `ll` at 0xc00000000003f690 loads 4 bytes from ret(module_lookup) +0x18.
  The `sc` at 0xc00000000003f69c stores 4 bytes to ret(module_lookup) +0x18.
  The `ll` at 0xc00000000003f6a8 loads 4 bytes from abs 0xc0000000014d2b1c.
  The `sc` at 0xc00000000003f6b4 stores 4 bytes to abs 0xc0000000014d2b1c.
  The `ld` at 0xc00000000003f6d0 loads 8 bytes from table(0xc0000000014d5028) +0x0.
  The `lh` at 0xc00000000003f6d4 loads 2 bytes from entry(0xc0000000014d5028) +0x424.
  The `sd` at 0xc00000000003f6f0 stores 8 bytes to ([entry(0xc0000000014d5028)+1060]:2 << 0x20) -0x6dfffffffe7fff70.
  2 such `lh` accesses load 2 bytes from ret(module_lookup) +0x0, including `lh` at 0xc00000000003f6f8, `lh` at 0xc00000000003f70c.
  The `jal` at 0xc00000000003f588 calls module_lookup [0xc000000000040370] with a0=[[-0x3c00]:8+18858]:2, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xc00000000003f654 calls msc_owner_cpu [0xc00000000003e150] with a0=ret(module_lookup), a1=?, a2=?, a3=?.
  The `jal` at 0xc00000000003f660 calls intr_block_bit [0xc0000000000389a0] with a0=ret(msc_owner_cpu), a1=0x7f, a2=?, a3=?.
  The `jal` at 0xc00000000003f6fc calls cmn_err [0xc0000000001fcbd4] with a0=0x401, a1=0xc00000000140d110, a2=[ret(module_lookup)]:2, a3=?, a5=[0xc0000000014d39e8], a7=[ret(module_lookup)+788].
  The `jal` at 0xc00000000003f710 calls cmn_err [0xc0000000001fcbd4] with a0=0x401, a1=0xc00000000140d148, a2=[ret(module_lookup)]:2, a3=?.
  The `beq` branch at 0xc00000000003f570 targets 0xc00000000003f584, is taken when at(=[0xc0000000014cafd4]) == 0, and falls through when at(=[0xc0000000014cafd4]) != 0.
  The `beq` branch at 0xc00000000003f604 targets 0xc00000000003f610, is taken when a5(=[0xc0000000014d39e8]) >= a4(?) (signed), and falls through when a5(=[0xc0000000014d39e8]) < a4(?) (signed).
  The `beq` branch at 0xc00000000003f610 targets 0xc00000000003f638, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0xc00000000003f624 targets 0xc00000000003f630, is taken when a5(=[0xc0000000014d39e8]) >= a6(?) (signed), and falls through when a5(=[0xc0000000014d39e8]) < a6(?) (signed).
  The `bne` branch at 0xc00000000003f630 targets 0xc00000000003f5e4, is taken when v0(?) != 0, and falls through when v0(?) == 0.
  The `bne` branch at 0xc00000000003f638 targets 0xc00000000003f688, is taken when a0(?) != a7(=0x10), and falls through when a0(?) == a7(=0x10).
  The `bne` branch at 0xc00000000003f640 targets 0xc00000000003f688, is taken when t0(=[0xc0000000014cafd0]) != 0, and falls through when t0(=[0xc0000000014cafd0]) == 0.
  The `beq` branch at 0xc00000000003f64c targets 0xc00000000003f6f4, is taken when a7(=[ret(module_lookup)+788]) == 0, and falls through when a7(=[ret(module_lookup)+788]) != 0.
  The `beql` branch at 0xc00000000003f6a0 targets 0xc00000000003f690, is taken when a0(=[ret(module_lookup)+24]+1) == 0, and falls through when a0(=[ret(module_lookup)+24]+1) != 0; its branch-likely delay slot `nop` at 0xc00000000003f6a4 runs only when taken and is annulled on fall-through.
  The `beql` branch at 0xc00000000003f6b8 targets 0xc00000000003f6a8, is taken when v0(=[0xc0000000014d2b1c]+1) == 0, and falls through when v0(=[0xc0000000014d2b1c]+1) != 0; its branch-likely delay slot `nop` at 0xc00000000003f6bc runs only when taken and is annulled on fall-through.
  The `beq` branch at 0xc00000000003f6ec targets 0xc00000000003f578 and is always taken.
  The `beq` branch at 0xc00000000003f718 targets 0xc00000000003f654 and is always taken.
  The return at 0xc00000000003f57c has v0 = one of ?, [0xc0000000014d2b1c]+1.
- `nic_access` in `IP27/unix` at 0xc000000000099fa0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/unix`.
  Range: 0xc000000000099fa0-0xc00000000009a034 (148 bytes).
  It occupies 148 bytes.
  The `jal` at 0xc000000000099fcc calls sprintf [0xc0000000001fd9d0] with a0=a0+440, a1=0xc0000000003c8160, a2=a1 at entry (arg1), a3=a2 at entry (arg2), a4=a3 at entry (arg3).
  The `jal` at 0xc000000000099fd8 calls elsc_command [0xc000000000098d50] with a0=a0 at entry (arg0), a1=0x0, a2=?, a3=?.
  The `jal` at 0xc000000000099ff4 calls elsc_parse [0xc000000000098ee0] with a0=a0 at entry (arg0), a1=sp-112, a2=0x0, a3=0x0.
  The `jal` at 0xc00000000009a014 calls strtoull [0xc000000000142cc4] with a0=sp-112, a1=0x0, a2=0x10, a3=?.
  The `bltz` branch at 0xc000000000099fe0 targets 0xc00000000009a020, is taken when v0(=ret(elsc_command)) < 0 (signed), and falls through when v0(=ret(elsc_command)) >= 0 (signed).
  The `bgez` branch at 0xc000000000099ffc targets 0xc00000000009a00c, is taken when v0(=ret(elsc_parse)) >= 0 (signed), and falls through when v0(=ret(elsc_parse)) < 0 (signed).
  The `beq` branch at 0xc00000000009a004 targets 0xc00000000009a024 and is always taken.
  The return at 0xc00000000009a02c has v0 = one of ret(elsc_parse), ?.
- `heartbeat` in `IP27/unix` at 0xc00000000009b9b4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/unix`.
  Range: 0xc00000000009b9b4-0xc00000000009baa0 (236 bytes).
  It occupies 236 bytes.
  The `lw` at 0xc00000000009b9cc loads 4 bytes from a0 (arg0 at entry) +0x38.
  The `lh` at 0xc00000000009b9dc loads 2 bytes from abs 0xffffffffffffc420.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x34, including `sw` at 0xc00000000009b9f8, `sw` at 0xc00000000009b9fc.
  3 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x40, including `ld` at 0xc00000000009ba00, `ld` at 0xc00000000009ba14, `ld` at 0xc00000000009ba24.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x30, including `lw` at 0xc00000000009ba34, `lw` at 0xc00000000009ba5c.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x8, including `ld` at 0xc00000000009ba44, `ld` at 0xc00000000009ba6c.
  The `ld` at 0xc00000000009ba50 loads 8 bytes from [a0+8]:8 +0x8.
  The `ld` at 0xc00000000009ba78 loads 8 bytes from [a0+8]:8 +0x0.
  The `jal` at 0xc00000000009b9c4 calls sio_lock_port [0xc000000000179458] with a0=a0 at entry (arg0), a1=0x0, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xc00000000009b9ec calls dtimeout [0xc0000000001b373c] with a0=0xc00000000009b9b4, a1=a0 at entry (arg0), a2=0x64, a3=[0xc0000000014cb6d0]:8, a4=[-0x3be0]:2.
  The `jal` at 0xc00000000009ba0c calls mutex_spinlock_spl [0xc000000000286360] with a0=[a0+64]:8+680, a1=0xc00000000003b3bc, a2=?, a3=?.
  The `jal` at 0xc00000000009ba1c calls elsc_process [0xc0000000000991c4] with a0=[a0+64]:8+48, a1=?, a2=?, a3=?.
  The `jal` at 0xc00000000009ba2c calls mutex_spinunlock [0xc000000000286400] with a0=[a0+64]:8+680, a1=ret(mutex_spinlock_spl), a2=?, a3=?.
  The `jalr` at 0xc00000000009ba54 calls (unknown callee) with a0=a0 at entry (arg0), a1=?, a2=[[a0+8]:8+8]:8, a3=?.
  The `jalr` at 0xc00000000009ba7c calls (unknown callee) with a0=a0 at entry (arg0), a1=?, a2=?, a3=?, a4=[[a0+8]:8]:8.
  The `jal` at 0xc00000000009ba88 calls sio_unlock_port [0xc000000000179580] with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `beq` branch at 0xc00000000009b9d4 targets 0xc00000000009b9fc, is taken when (at(=[a0+56]) & 0x1) == 0, and falls through when (at(=[a0+56]) & 0x1) != 0.
  The `beq` branch at 0xc00000000009b9f4 targets 0xc00000000009ba00 and is always taken.
  The `beq` branch at 0xc00000000009ba3c targets 0xc00000000009ba64, is taken when (a0(=[a0+48]) & 0x2) == 0, and falls through when (a0(=[a0+48]) & 0x2) != 0.
  The `beq` branch at 0xc00000000009ba48 targets 0xc00000000009ba64, is taken when v0(=[a0+8]:8) == 0, and falls through when v0(=[a0+8]:8) != 0.
  The `beq` branch at 0xc00000000009ba64 targets 0xc00000000009ba88, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0xc00000000009ba70 targets 0xc00000000009ba88, is taken when v0(=[a0+8]:8) == 0, and falls through when v0(=[a0+8]:8) != 0.
  The return at 0xc00000000009ba98 has v0 = ret(sio_unlock_port).
- `tg_free` in `IP27/unix` at 0xc0000000000db4f0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/unix`.
  Range: 0xc0000000000db4f0-0xc0000000000db6bc (460 bytes).
  It occupies 460 bytes.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x74, including `lw` at 0xc0000000000db4fc, `lw` at 0xc0000000000db620.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x100, including `ld` at 0xc0000000000db530, `ld` at 0xc0000000000db55c.
  3 such `ld` accesses load 8 bytes from ?, including `ld` at 0xc0000000000db544, `ld` at 0xc0000000000db598, `ld` at 0xc0000000000db5ec.
  3 such `sd` accesses store 8 bytes to ?, including `sd` at 0xc0000000000db574, `sd` at 0xc0000000000db5c8, `sd` at 0xc0000000000db61c.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x90, including `ld` at 0xc0000000000db584, `ld` at 0xc0000000000db5b0.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x98, including `ld` at 0xc0000000000db5d8, `ld` at 0xc0000000000db604.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x58, including `ld` at 0xc0000000000db670, `ld` at 0xc0000000000db6a4.
  The `jal` at 0xc0000000000db554 calls m_freem [0xc0000000001821c8] with a0=?, a1=?, a2=?, a3=?, a5=[a0+256]:8.
  The `jal` at 0xc0000000000db5a8 calls m_freem [0xc0000000001821c8] with a0=?, a1=?, a2=?, a3=?, a6=[a0+144]:8.
  The `jal` at 0xc0000000000db5fc calls m_freem [0xc0000000001821c8] with a0=?, a1=?, a2=?, a3=?, a7=[a0+152]:8.
  The `jal` at 0xc0000000000db678 calls ftrc_event [0xc0000000000defd0] with a0=[a0+88]:8, a1=0x3, a2=0xc0000000003d1558, a3=?, a6=0x0, a7=0x0.
  The `jal` at 0xc0000000000db6ac calls ftrc_event [0xc0000000000defd0] with a0=[a0+88]:8, a1=0x0, a2=0xc0000000003d1540, a3=0x0, a4=0x0, a5=0x0, a6=0x0, a7=0x0.
  The `beq` branch at 0xc0000000000db518 targets 0xc0000000000db688, is taken when at(=0x40) == v0(?), and falls through when at(=0x40) != v0(?).
  The `beq` branch at 0xc0000000000db52c targets 0xc0000000000db53c and is always taken.
  The `beq` branch at 0xc0000000000db534 targets 0xc0000000000db578, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0xc0000000000db54c targets 0xc0000000000db534, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `bne` branch at 0xc0000000000db570 targets 0xc0000000000db52c, is taken when s0(?) < 0x200 (signed), and falls through when s0(?) >= 0x200 (signed).
  The `beq` branch at 0xc0000000000db580 targets 0xc0000000000db590 and is always taken.
  The `beq` branch at 0xc0000000000db588 targets 0xc0000000000db5cc, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `beq` branch at 0xc0000000000db5a0 targets 0xc0000000000db588, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `bne` branch at 0xc0000000000db5c4 targets 0xc0000000000db580, is taken when s0(?) < 0x200 (signed), and falls through when s0(?) >= 0x200 (signed).
  The `beq` branch at 0xc0000000000db5d4 targets 0xc0000000000db5e4 and is always taken.
  The `beq` branch at 0xc0000000000db5dc targets 0xc0000000000db620, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `beq` branch at 0xc0000000000db5f4 targets 0xc0000000000db5dc, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `bne` branch at 0xc0000000000db618 targets 0xc0000000000db5d4, is taken when s0(?) < 0x100 (signed), and falls through when s0(?) >= 0x100 (signed).
  The `beq` branch at 0xc0000000000db62c targets 0xc0000000000db658, is taken when a2(=0x40) == a3(?), and falls through when a2(=0x40) != a3(?).
  The `beq` branch at 0xc0000000000db680 targets 0xc0000000000db638 and is always taken.
  The `beq` branch at 0xc0000000000db6b4 targets 0xc0000000000db524 and is always taken.
  The return at 0xc0000000000db650 has v0 = one of ?, ret(ftrc_event).
- `eg_st_bid_notify` in `IP27/unix` at 0xc0000000000e171c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/unix`.
  Range: 0xc0000000000e171c-0xc0000000000e1848 (300 bytes).
  It occupies 300 bytes.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x330, including `ld` at 0xc0000000000e172c, `ld` at 0xc0000000000e1758.
  2 such `sw` accesses store 4 bytes to [a0+816]:8 +0x67c, including `sw` at 0xc0000000000e1744, `sw` at 0xc0000000000e1780.
  The `lw` at 0xc0000000000e1774 loads 4 bytes from [a0+816]:8 +0x67c.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x4cc, including `lw` at 0xc0000000000e1784, `lw` at 0xc0000000000e17f0.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x4d0, including `lw` at 0xc0000000000e1794, `lw` at 0xc0000000000e1800.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x20, including `lw` at 0xc0000000000e17a4, `lw` at 0xc0000000000e1810.
  2 such `lh` accesses load 2 bytes from a0 (arg0 at entry) +0x1a, including `lh` at 0xc0000000000e17b8, `lh` at 0xc0000000000e1824.
  The `jal` at 0xc0000000000e1740 calls eg_docmd [0xc0000000000e4bd8] with a0=a0 at entry (arg0), a1=0xf1, a2=a1 at entry (arg1), a3=0x0.
  The `jal` at 0xc0000000000e17bc calls printf [0xc0000000001fda70] with a0=0xc0000000003d3a68, a1=[a0+26]:2, a2=?, a3=?, a4=[[a0+816]:8+1660].
  The `jal` at 0xc0000000000e17d0 calls printf [0xc0000000001fda70] with a0=0xc0000000003d3d20, a1=?, a2=[[a0+816]:8+1660], a3=?.
  The `jal` at 0xc0000000000e1828 calls printf [0xc0000000001fda70] with a0=0xc0000000003d3a68, a1=[a0+26]:2, a2=?, a3=?, a4=[[a0+816]:8+1660].
  The `jal` at 0xc0000000000e1838 calls printf [0xc0000000001fda70] with a0=0xc0000000003d3cf0, a1=a1 at entry (arg1), a2=?, a3=?.
  The `beq` branch at 0xc0000000000e1748 targets 0xc0000000000e1758, is taken when v0(=ret(eg_docmd)) == 0, and falls through when v0(=ret(eg_docmd)) != 0.
  The `beq` branch at 0xc0000000000e1750 targets 0xc0000000000e17dc and is always taken.
  The `beq` branch at 0xc0000000000e175c targets 0xc0000000000e1774 and is always taken.
  The `beq` branch at 0xc0000000000e176c targets 0xc0000000000e17f0, is taken when s1(?) >= 0x2711 (signed), and falls through when s1(?) < 0x2711 (signed).
  The `beq` branch at 0xc0000000000e1778 targets 0xc0000000000e1764, is taken when a4(=[[a0+816]:8+1660]) == 0, and falls through when a4(=[[a0+816]:8+1660]) != 0.
  The `beq` branch at 0xc0000000000e178c targets 0xc0000000000e17dc, is taken when (a0(=[a0+1228]) & 0x20) == 0, and falls through when (a0(=[a0+1228]) & 0x20) != 0.
  The `bne` branch at 0xc0000000000e179c targets 0xc0000000000e17dc, is taken when a1(=[a0+1232]) < 0x9 (unsigned), and falls through when a1(=[a0+1232]) >= 0x9 (unsigned).
  The `beq` branch at 0xc0000000000e17ac targets 0xc0000000000e17d8, is taken when (a2(=[a0+32]) & 0x4) == 0, and falls through when (a2(=[a0+32]) & 0x4) != 0.
  The `beq` branch at 0xc0000000000e17f8 targets 0xc0000000000e1840, is taken when (a1(=[a0+1228]) & 0x20) == 0, and falls through when (a1(=[a0+1228]) & 0x20) != 0.
  The `bne` branch at 0xc0000000000e1808 targets 0xc0000000000e1840, is taken when a2(=[a0+1232]) < 0x4 (unsigned), and falls through when a2(=[a0+1232]) >= 0x4 (unsigned).
  The `beq` branch at 0xc0000000000e1818 targets 0xc0000000000e1840, is taken when (a3(=[a0+32]) & 0x4) == 0, and falls through when (a3(=[a0+32]) & 0x4) != 0.
  The `beq` branch at 0xc0000000000e1840 targets 0xc0000000000e17dc and is always taken.
  The return at 0xc0000000000e17e8 has v0 = one of 0x0, 0x1.
- `random_write_internal` in `IP27/unix` at 0xc00000000018d394 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/unix`.
  Range: 0xc00000000018d394-0xc00000000018d474 (224 bytes).
  It occupies 224 bytes.
  2 such `ld` accesses load 8 bytes from abs 0x9200000001030100, including `ld` at 0xc00000000018d3d8, `ld` at 0xc00000000018d438.
  The `jal` at 0xc00000000018d3dc calls random_harvest_internal [0xc00000000018d26c] with a0=[0x9200000001030100]:8, a1=?, a2=0x10, a3=0x10, a4=0x0, a5=0x0.
  The `jal` at 0xc00000000018d434 calls random_harvest_internal [0xc00000000018d26c] with a0=[0x9200000001030100]:8, a1=?, a2=?, a3=0x0, a4=0x0, a5=0x0.
  The `blez` branch at 0xc00000000018d3b8 targets 0xc00000000018d458, is taken when a1 <= 0 (signed), and falls through when a1 > 0 (signed).
  The `bne` branch at 0xc00000000018d3ec targets 0xc00000000018d3cc, is taken when s0(?) < s2(=a1) (signed), and falls through when s0(?) >= s2(=a1) (signed).
  The `beq` branch at 0xc00000000018d3f8 targets 0xc00000000018d408, is taken when s2(=a1) >= s0(?) (signed), and falls through when s2(=a1) < s0(?) (signed).
  The `beq` branch at 0xc00000000018d41c targets 0xc00000000018d43c, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `bltz` branch at 0xc00000000018d458 targets 0xc00000000018d468, is taken when a1 < 0 (signed), and falls through when a1 >= 0 (signed).
  The `beq` branch at 0xc00000000018d460 targets 0xc00000000018d408 and is always taken.
  The `beq` branch at 0xc00000000018d46c targets 0xc00000000018d404 and is always taken.
  The return at 0xc00000000018d450 has v0 = one of ?, ret(random_harvest_internal).
- `do_mprboot` in `IP27/unix` at 0xc0000000001ff290 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/unix`.
  Range: 0xc0000000001ff290-0xc0000000001ff3a0 (272 bytes).
  It occupies 272 bytes.
  2 such `lw` accesses load 4 bytes from abs 0xc00000000153f7e0, including `lw` at 0xc0000000001ff2d0, `lw` at 0xc0000000001ff330.
  The `sw` at 0xc0000000001ff2e0 stores 4 bytes to abs 0xc00000000153f7e0.
  2 such `lh` accesses load 2 bytes from abs 0xffffffffffffc420, including `lh` at 0xc0000000001ff2e8, `lh` at 0xc0000000001ff38c.
  The `lh` at 0xc0000000001ff2ec loads 2 bytes from [0xc0000000014d3e10]:8 +0x420.
  2 such `ld` accesses load 8 bytes from abs 0x9200000001030100, including `ld` at 0xc0000000001ff30c, `ld` at 0xc0000000001ff350.
  The `ld` at 0xc0000000001ff364 loads 8 bytes from abs 0xc00000000153f7e8.
  The `jal` at 0xc0000000001ff2c4 calls mutex_spinlock [0xc0000000002863b4] with a0=0xc00000000153f7f0, a1=?, a2=?, a3=?.
  The `jal` at 0xc0000000001ff2dc calls mutex_spinunlock [0xc000000000286400] with a0=0xc00000000153f7f0, a1=ret(mutex_spinlock), a2=?, a3=?.
  The `jal` at 0xc0000000001ff328 calls us_delay [0xc000000000047c0c] with a0=0x186a0, a1=?, a2=?, a3=?, a5=[0x9200000001030100]:8.
  The `jal` at 0xc0000000001ff348 calls conbuf_flush [0xc0000000001fed68] with a0=0x3, a1=?, a2=[one of 0xc0000000014d2b74, 0xc00000000153f7e0], a3=[0xc0000000014cb9fc].
  The `jalr` at 0xc0000000001ff370 calls (unknown callee) with a0=a0 at entry (arg0), a1=?, a2=?, a3=?, a6=[0xc00000000153f7e8]:8.
  The `jal` at 0xc0000000001ff390 calls cmn_err [0xc0000000001fcbd4] with a0=0x6, a1=0xc0000000003e75a8, a2=[-0x3be0]:2, a3=a3 at entry (arg3).
  The `bne` branch at 0xc0000000001ff2ac targets 0xc0000000001ff2bc, is taken when at(=[0xc0000000014d2aa0]) < 0x2 (signed), and falls through when at(=[0xc0000000014d2aa0]) >= 0x2 (signed).
  The `beq` branch at 0xc0000000001ff2b4 targets 0xc0000000001ff388, is taken when a2(=[0xc0000000014d4350]) == 0, and falls through when a2(=[0xc0000000014d4350]) != 0.
  The `bne` branch at 0xc0000000001ff2f8 targets 0xc0000000001ff364, is taken when v1(=[-0x3be0]:2) != a0(=[[0xc0000000014d3e10]:8+1056]:2), and falls through when v1(=[-0x3be0]:2) == a0(=[[0xc0000000014d3e10]:8+1056]:2).
  The `beq` branch at 0xc0000000001ff320 targets 0xc0000000001ff33c and is always taken.
  The `beq` branch at 0xc0000000001ff334 targets 0xc0000000001ff364, is taken when a2(=[0xc00000000153f7e0]) == 0, and falls through when a2(=[0xc00000000153f7e0]) != 0.
  The `beq` branch at 0xc0000000001ff340 targets 0xc0000000001ff350, is taken when a3(=[0xc0000000014cb9fc]) == 0, and falls through when a3(=[0xc0000000014cb9fc]) != 0.
  The `beq` branch at 0xc0000000001ff35c targets 0xc0000000001ff328, is taken when a4(?) >= a5(=[0x9200000001030100]:8) (unsigned), and falls through when a4(?) < a5(=[0x9200000001030100]:8) (unsigned).
  The `beq` branch at 0xc0000000001ff398 targets 0xc0000000001ff2c0 and is always taken.
  The return at 0xc0000000001ff380 has v0 = ret(?).
- `hub_set_fire_n_forget` in `IP27/unix` at 0xc000000000377dfc (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/unix`.
  Range: 0xc000000000377dfc-0xc000000000377e50 (84 bytes).
  It occupies 84 bytes.
  The `ld` at 0xc000000000377e28 loads 8 bytes from table(0x9200000001c00198) +0x0.
  The `sd` at 0xc000000000377e4c stores 8 bytes to table(0x9200000001c00198) +0x0.
  The `beq` branch at 0xc000000000377e0c targets 0xc000000000377e18, is taken when a1 >= 0x8 (signed), and falls through when a1 < 0x8 (signed).
  The `bne` branch at 0xc000000000377e24 targets 0xc000000000377e30, is taken when a7(?) != 0, and falls through when a7(?) == 0.
  The return at 0xc000000000377e48 has v0 = ?.
- `gfx_flow_init` in `IP27/unix` at 0xc000000000395efc (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/unix`.
  Range: 0xc000000000395efc-0xc0000000003960a8 (428 bytes).
  It occupies 428 bytes.
  3 such `lh` accesses load 2 bytes from ?, including `lh` at 0xc000000000395f28, `lh` at 0xc000000000395f58, `lh` at 0xc000000000396054.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0xc000000000395f34, `ld` at 0xc000000000396060.
  3 such `sd` accesses store 8 bytes to ?, including `sd` at 0xc000000000395f54, `sd` at 0xc000000000395f68, `sd` at 0xc000000000396084.
  The `jal` at 0xc000000000395fb0 calls cpu_enabled [0xc000000000027228] with a0=?, a1=?, a2=?, a3=?, a4=[0xc0000000014d3e24].
  The `jal` at 0xc000000000395fc8 calls install_gfxintr [0xc000000000039b44] with a0=?, a1=0x0, a2=0xc000000000395e6c, a3=0x0.
  The `jal` at 0xc000000000396004 calls kmem_zalloc [0xc00000000017e344] with a0=?, a1=0x0, a2=?, a3=?, a4=[0xc0000000014d3e24].
  The `jal` at 0xc000000000396024 calls kmem_zalloc [0xc00000000017e344] with a0=?, a1=0x0, a2=?, a3=?.
  The `blez` branch at 0xc000000000395f10 targets 0xc000000000395f84, is taken when a4(=[0xc0000000014d3e24]) <= 0 (signed), and falls through when a4(=[0xc0000000014d3e24]) > 0 (signed).
  The `bne` branch at 0xc000000000395f7c targets 0xc000000000395f24, is taken when a0(?) < a4(=[0xc0000000014d3e24]) (signed), and falls through when a0(?) >= a4(=[0xc0000000014d3e24]) (signed).
  The `beq` branch at 0xc000000000395f94 targets 0xc00000000039603c, is taken when a2(=[0xc0000000014cbf30]) == 0, and falls through when a2(=[0xc0000000014cbf30]) != 0.
  The `blez` branch at 0xc000000000395fa4 targets 0xc000000000395fec, is taken when a3(=[0xc0000000014d2aa0]) <= 0 (signed), and falls through when a3(=[0xc0000000014d2aa0]) > 0 (signed).
  The `beq` branch at 0xc000000000395fb8 targets 0xc000000000395fd0, is taken when v0(=ret(cpu_enabled)) == 0, and falls through when v0(=ret(cpu_enabled)) != 0.
  The `bne` branch at 0xc000000000395fe4 targets 0xc000000000395fb0, is taken when s0(?) < a4(=[0xc0000000014d2aa0]) (signed), and falls through when s0(?) >= a4(=[0xc0000000014d2aa0]) (signed).
  The `blez` branch at 0xc00000000039603c targets 0xc000000000395f9c, is taken when a4(=[0xc0000000014d3e24]) <= 0 (signed), and falls through when a4(=[0xc0000000014d3e24]) > 0 (signed).
  The `bne` branch at 0xc00000000039607c targets 0xc000000000396090, is taken when t1(?) < 0x4 (unsigned), and falls through when t1(?) >= 0x4 (unsigned).
  The `bne` branch at 0xc000000000396098 targets 0xc000000000396054, is taken when a0(?) < a4(=[0xc0000000014d3e24]) (signed), and falls through when a0(?) >= a4(=[0xc0000000014d3e24]) (signed).
  The `beq` branch at 0xc0000000003960a0 targets 0xc000000000395fa0 and is always taken.
  The return at 0xc000000000396034 has v0 = ret(kmem_zalloc).
- `kona_fc_attach` in `IP27/unix` at 0xc00000000039ba34 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/unix`.
  Range: 0xc00000000039ba34-0xc00000000039bb68 (308 bytes).
  It occupies 308 bytes.
  The `lh` at 0xc00000000039ba34 loads 2 bytes from abs 0xffffffffffffc420.
  The `ld` at 0xc00000000039ba4c loads 8 bytes from table(0xc0000000014d5028) +0x0.
  The `lbu` at 0xc00000000039ba54 loads 1 byte from entry(0xc0000000014d5028) +0x520.
  The `lh` at 0xc00000000039ba58 loads 2 bytes from entry(0xc0000000014d5028) +0x424.
  3 such `sd` accesses store 8 bytes to table(0x9200000001000000) +0x0, including `sd` at 0xc00000000039bb24, `sd` at 0xc00000000039bb30, `sd` at 0xc00000000039bb3c.
  The `sd` at 0xc00000000039bb44 stores 8 bytes to table(0x9200000001c00140) +0x0.
  The `ld` at 0xc00000000039bb50 loads 8 bytes from table(0x9200000001c00140) +0x0.
  The `sw` at 0xc00000000039bb58 stores 4 bytes to [0xc0000000014d48d8]:8 +0x7c.
  The `lw` at 0xc00000000039bb5c loads 4 bytes from [0xc0000000014d48d8]:8 +0x7c.
  The `jal` at 0xc00000000039ba68 calls err_int_block_mask [0xc000000000035604] with a0=0x8, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xc00000000039bb60 has v0 = ret(err_int_block_mask).
- `kona_fc_detach` in `IP27/unix` at 0xc00000000039bb68 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/unix`.
  Range: 0xc00000000039bb68-0xc00000000039bbf8 (144 bytes).
  It occupies 144 bytes.
  The `lh` at 0xc00000000039bb68 loads 2 bytes from abs 0xffffffffffffc420.
  The `ld` at 0xc00000000039bb78 loads 8 bytes from table(0xc0000000014d5028) +0x0.
  The `lbu` at 0xc00000000039bb7c loads 1 byte from entry(0xc0000000014d5028) +0x520.
  2 such `sd` accesses store 8 bytes to table(0x9200000001000000) +0x0, including `sd` at 0xc00000000039bba4, `sd` at 0xc00000000039bbd4.
  The `sw` at 0xc00000000039bbc0 stores 4 bytes to [0xc0000000014d48d8]:8 +0x7c.
  The `lw` at 0xc00000000039bbcc loads 4 bytes from [0xc0000000014d48d8]:8 +0x7c.
  The `jal` at 0xc00000000039bbe0 calls err_int_unblock_mask [0xc000000000035648] with a0=0x8, a1=0x1, a2=?, a3=0xdeadbabe, a4=table(0x9200000001000000).
  The return at 0xc00000000039bbf0 has v0 = ret(err_int_unblock_mask).
- `cpu_disable` in `IP30/unix` at 0xa800000020012a04 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020012a04-0xa800000020012a34 (48 bytes).
  It occupies 48 bytes.
  The `ld` at 0xa800000020012a14 loads 8 bytes from abs 0xffffffffaff00000.
  The `sd` at 0xa800000020012a28 stores 8 bytes to abs 0xffffffffaff00000.
  The `sw` at 0xa800000020012a30 stores 4 bytes to table(0xa8000000204ae380) +0x0.
  The return at 0xa800000020012a2c has v0 = ?.
- `cpu_exists` in `IP30/unix` at 0xa800000020012a34 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020012a34-0xa800000020012a54 (32 bytes).
  It occupies 32 bytes.
  The `ld` at 0xa800000020012a40 loads 8 bytes from abs 0xffffffffaff00080.
  The return at 0xa800000020012a4c has v0 = ?.
- `ip30_early_piotrans_addr` in `IP30/unix` at 0xa8000000200136b4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa8000000200136b4-0xa800000020013808 (340 bytes).
  It occupies 340 bytes.
  The `ld` at 0xa8000000200136b8 loads 8 bytes from abs 0xffffffffaff00080.
  The `lw` at 0xa8000000200136d8 loads 4 bytes from (0x9000000000000000 | table(0x10000000)) +0x4.
  The `lw` at 0xa800000020013714 loads 4 bytes from abs 0x9000000010000004.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0xa800000020013754, `lw` at 0xa80000002001376c.
  The `jal` at 0xa80000002001379c calls heart_addr_xio_to_kva [0xa80000002003f290] with a0=?, a1=a3 at entry (arg3), a2=a4 at entry (arg4), a3=a3 at entry (arg3).
  The `jal` at 0xa8000000200137e0 calls heart_addr_xio_to_kva [0xa80000002003f290] with a0=?, a1=a3 at entry (arg3), a2=a4 at entry (arg4), a3=a3 at entry (arg3).
  The `jal` at 0xa8000000200137f8 calls heart_addr_xio_to_kva [0xa80000002003f290] with a0=0x0, a1=a3 at entry (arg3), a2=a4 at entry (arg4), a3=a3 at entry (arg3).
  The `bne` branch at 0xa8000000200136fc targets 0xa800000020013714, is taken when a0 != at(?), and falls through when a0 == at(?).
  The `bne` branch at 0xa800000020013704 targets 0xa800000020013714, is taken when a1 != a7(?), and falls through when a1 == a7(?).
  The `beq` branch at 0xa80000002001370c targets 0xa8000000200137d8, is taken when a2 == 0, and falls through when a2 != 0.
  The `bne` branch at 0xa800000020013724 targets 0xa800000020013744, is taken when a0 != t9(?), and falls through when a0 == t9(?).
  The `beq` branch at 0xa80000002001372c targets 0xa8000000200137c0 and is always taken.
  The `bne` branch at 0xa80000002001373c targets 0xa8000000200137ac, is taken when v0(?) < 0x8 (signed), and falls through when v0(?) >= 0x8 (signed).
  The `beq` branch at 0xa800000020013744 targets 0xa800000020013734, is taken when v0(?) == t0(?), and falls through when v0(?) != t0(?).
  The `beq` branch at 0xa80000002001375c targets 0xa800000020013734, is taken when (at(?) & 0x20) == 0, and falls through when (at(?) & 0x20) != 0.
  The `bne` branch at 0xa80000002001377c targets 0xa800000020013734, is taken when a0 != t8(?), and falls through when a0 == t8(?).
  The `bne` branch at 0xa800000020013784 targets 0xa800000020013734, is taken when a1 != a7(?), and falls through when a1 == a7(?).
  The `bne` branch at 0xa80000002001378c targets 0xa800000020013734, is taken when a2(?) != 0, and falls through when a2(?) == 0.
  The `beq` branch at 0xa8000000200137a4 targets 0xa8000000200137b0 and is always taken.
  The `bne` branch at 0xa8000000200137c0 targets 0xa800000020013744, is taken when a1 != a7(?), and falls through when a1 == a7(?).
  The `beq` branch at 0xa8000000200137c8 targets 0xa8000000200137f0, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0xa8000000200137d0 targets 0xa800000020013744 and is always taken.
  The `beq` branch at 0xa8000000200137e8 targets 0xa8000000200137b0 and is always taken.
  The `beq` branch at 0xa800000020013800 targets 0xa8000000200137b0 and is always taken.
  The return at 0xa8000000200137b8 has v0 = one of ret(heart_addr_xio_to_kva), 0x0.
- `find_pclk_freq` in `IP30/unix` at 0xa800000020018014 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020018014-0xa800000020018134 (288 bytes).
  It occupies 288 bytes.
  11 such `ld` accesses load 8 bytes from abs 0xffffffffaff20000, including `ld` at 0xa80000002001803c, `ld` at 0xa800000020018040, `ld` at 0xa80000002001804c.
  The `jal` at 0xa800000020018030 calls spl65 [0xa80000002001bb14] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa800000020018070 calls _get_count [0xa800000020026a90] with a0=?, a1=?, a2=?, a3=[0xffffffffaff20000]:8.
  The `jal` at 0xa8000000200180e0 calls _get_count [0xa800000020026a90] with a0=?, a1=?, a2=?, a3=[0xffffffffaff20000]:8+12500.
  The `jal` at 0xa8000000200180ec calls splx [0xa80000002001bb64] with a0=ret(spl65), a1=?, a2=?, a3=?.
  The `beq` branch at 0xa80000002001801c targets 0xa80000002001802c, is taken when v0(=[0xa8000000204ae430]) == 0, and falls through when v0(=[0xa8000000204ae430]) != 0.
  The `bne` branch at 0xa800000020018044 targets 0xa800000020018070, is taken when s1(=[0xffffffffaff20000]:8) != a3(=[0xffffffffaff20000]:8), and falls through when s1(=[0xffffffffaff20000]:8) == a3(=[0xffffffffaff20000]:8).
  The `bne` branch at 0xa800000020018050 targets 0xa800000020018070, is taken when s1(=[0xffffffffaff20000]:8) != a3(=[0xffffffffaff20000]:8), and falls through when s1(=[0xffffffffaff20000]:8) == a3(=[0xffffffffaff20000]:8).
  The `bne` branch at 0xa80000002001805c targets 0xa800000020018070, is taken when s1(=[0xffffffffaff20000]:8) != a3(=[0xffffffffaff20000]:8), and falls through when s1(=[0xffffffffaff20000]:8) == a3(=[0xffffffffaff20000]:8).
  The `beq` branch at 0xa800000020018068 targets 0xa80000002001804c, is taken when s1(=[0xffffffffaff20000]:8) == a3(=[0xffffffffaff20000]:8), and falls through when s1(=[0xffffffffaff20000]:8) != a3(=[0xffffffffaff20000]:8).
  The `beq` branch at 0xa800000020018084 targets 0xa8000000200180dc, is taken when at(=[0xffffffffaff20000]:8) >= a3(=[0xffffffffaff20000]:8+12500) (unsigned), and falls through when at(=[0xffffffffaff20000]:8) < a3(=[0xffffffffaff20000]:8+12500) (unsigned).
  The `beq` branch at 0xa800000020018094 targets 0xa8000000200180dc, is taken when v0(=[0xffffffffaff20000]:8) >= a3(=[0xffffffffaff20000]:8+12500) (unsigned), and falls through when v0(=[0xffffffffaff20000]:8) < a3(=[0xffffffffaff20000]:8+12500) (unsigned).
  The `beq` branch at 0xa8000000200180a4 targets 0xa8000000200180dc, is taken when v1(=[0xffffffffaff20000]:8) >= a3(=[0xffffffffaff20000]:8+12500) (unsigned), and falls through when v1(=[0xffffffffaff20000]:8) < a3(=[0xffffffffaff20000]:8+12500) (unsigned).
  The `beq` branch at 0xa8000000200180b4 targets 0xa8000000200180dc, is taken when a0(=[0xffffffffaff20000]:8) >= a3(=[0xffffffffaff20000]:8+12500) (unsigned), and falls through when a0(=[0xffffffffaff20000]:8) < a3(=[0xffffffffaff20000]:8+12500) (unsigned).
  The `beq` branch at 0xa8000000200180c4 targets 0xa8000000200180dc, is taken when a1(=[0xffffffffaff20000]:8) >= a3(=[0xffffffffaff20000]:8+12500) (unsigned), and falls through when a1(=[0xffffffffaff20000]:8) < a3(=[0xffffffffaff20000]:8+12500) (unsigned).
  The `bne` branch at 0xa8000000200180d4 targets 0xa80000002001808c, is taken when a2(=[0xffffffffaff20000]:8) < a3(=[0xffffffffaff20000]:8+12500) (unsigned), and falls through when a2(=[0xffffffffaff20000]:8) >= a3(=[0xffffffffaff20000]:8+12500) (unsigned).
  The `beq` branch at 0xa80000002001812c targets 0xa800000020018024 and is always taken.
  The return at 0xa800000020018024 has v0 = one of [0xa8000000204ae430], ?.
- `tg_free` in `IP30/unix` at 0xa8000000200b37c4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa8000000200b37c4-0xa8000000200b3990 (460 bytes).
  It occupies 460 bytes.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x74, including `lw` at 0xa8000000200b37d0, `lw` at 0xa8000000200b38f4.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x100, including `ld` at 0xa8000000200b3804, `ld` at 0xa8000000200b3830.
  3 such `ld` accesses load 8 bytes from ?, including `ld` at 0xa8000000200b3818, `ld` at 0xa8000000200b386c, `ld` at 0xa8000000200b38c0.
  3 such `sd` accesses store 8 bytes to ?, including `sd` at 0xa8000000200b3848, `sd` at 0xa8000000200b389c, `sd` at 0xa8000000200b38f0.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x90, including `ld` at 0xa8000000200b3858, `ld` at 0xa8000000200b3884.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x98, including `ld` at 0xa8000000200b38ac, `ld` at 0xa8000000200b38d8.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x58, including `ld` at 0xa8000000200b3944, `ld` at 0xa8000000200b3978.
  The `jal` at 0xa8000000200b3828 calls m_freem [0xa80000002014bae4] with a0=?, a1=?, a2=?, a3=?, a5=[a0+256]:8.
  The `jal` at 0xa8000000200b387c calls m_freem [0xa80000002014bae4] with a0=?, a1=?, a2=?, a3=?, a6=[a0+144]:8.
  The `jal` at 0xa8000000200b38d0 calls m_freem [0xa80000002014bae4] with a0=?, a1=?, a2=?, a3=?, a7=[a0+152]:8.
  The `jal` at 0xa8000000200b394c calls ftrc_event [0xa8000000200b72ac] with a0=[a0+88]:8, a1=0x3, a2=0xa8000000203c0f68, a3=?, a6=0x0, a7=0x0.
  The `jal` at 0xa8000000200b3980 calls ftrc_event [0xa8000000200b72ac] with a0=[a0+88]:8, a1=0x0, a2=0xa8000000203c0f50, a3=0x0, a4=0x0, a5=0x0, a6=0x0, a7=0x0.
  The `beq` branch at 0xa8000000200b37ec targets 0xa8000000200b395c, is taken when at(=0x40) == v0(?), and falls through when at(=0x40) != v0(?).
  The `beq` branch at 0xa8000000200b3800 targets 0xa8000000200b3810 and is always taken.
  The `beq` branch at 0xa8000000200b3808 targets 0xa8000000200b384c, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0xa8000000200b3820 targets 0xa8000000200b3808, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `bne` branch at 0xa8000000200b3844 targets 0xa8000000200b3800, is taken when s0(?) < 0x200 (signed), and falls through when s0(?) >= 0x200 (signed).
  The `beq` branch at 0xa8000000200b3854 targets 0xa8000000200b3864 and is always taken.
  The `beq` branch at 0xa8000000200b385c targets 0xa8000000200b38a0, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `beq` branch at 0xa8000000200b3874 targets 0xa8000000200b385c, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `bne` branch at 0xa8000000200b3898 targets 0xa8000000200b3854, is taken when s0(?) < 0x200 (signed), and falls through when s0(?) >= 0x200 (signed).
  The `beq` branch at 0xa8000000200b38a8 targets 0xa8000000200b38b8 and is always taken.
  The `beq` branch at 0xa8000000200b38b0 targets 0xa8000000200b38f4, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `beq` branch at 0xa8000000200b38c8 targets 0xa8000000200b38b0, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `bne` branch at 0xa8000000200b38ec targets 0xa8000000200b38a8, is taken when s0(?) < 0x100 (signed), and falls through when s0(?) >= 0x100 (signed).
  The `beq` branch at 0xa8000000200b3900 targets 0xa8000000200b392c, is taken when a2(=0x40) == a3(?), and falls through when a2(=0x40) != a3(?).
  The `beq` branch at 0xa8000000200b3954 targets 0xa8000000200b390c and is always taken.
  The `beq` branch at 0xa8000000200b3988 targets 0xa8000000200b37f8 and is always taken.
  The return at 0xa8000000200b3924 has v0 = one of ?, ret(ftrc_event).
- `eg_st_bid_notify` in `IP30/unix` at 0xa8000000200b99e8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa8000000200b99e8-0xa8000000200b9b14 (300 bytes).
  It occupies 300 bytes.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x330, including `ld` at 0xa8000000200b99f8, `ld` at 0xa8000000200b9a24.
  2 such `sw` accesses store 4 bytes to [a0+816]:8 +0x67c, including `sw` at 0xa8000000200b9a10, `sw` at 0xa8000000200b9a4c.
  The `lw` at 0xa8000000200b9a40 loads 4 bytes from [a0+816]:8 +0x67c.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x4cc, including `lw` at 0xa8000000200b9a50, `lw` at 0xa8000000200b9abc.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x4d0, including `lw` at 0xa8000000200b9a60, `lw` at 0xa8000000200b9acc.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x20, including `lw` at 0xa8000000200b9a70, `lw` at 0xa8000000200b9adc.
  2 such `lh` accesses load 2 bytes from a0 (arg0 at entry) +0x1a, including `lh` at 0xa8000000200b9a84, `lh` at 0xa8000000200b9af0.
  The `jal` at 0xa8000000200b9a0c calls eg_docmd [0xa8000000200bcea4] with a0=a0 at entry (arg0), a1=0xf1, a2=a1 at entry (arg1), a3=0x0.
  The `jal` at 0xa8000000200b9a88 calls printf [0xa8000000201c78ec] with a0=0xa8000000203c3478, a1=[a0+26]:2, a2=?, a3=?, a4=[[a0+816]:8+1660].
  The `jal` at 0xa8000000200b9a9c calls printf [0xa8000000201c78ec] with a0=0xa8000000203c3730, a1=?, a2=[[a0+816]:8+1660], a3=?.
  The `jal` at 0xa8000000200b9af4 calls printf [0xa8000000201c78ec] with a0=0xa8000000203c3478, a1=[a0+26]:2, a2=?, a3=?, a4=[[a0+816]:8+1660].
  The `jal` at 0xa8000000200b9b04 calls printf [0xa8000000201c78ec] with a0=0xa8000000203c3700, a1=a1 at entry (arg1), a2=?, a3=?.
  The `beq` branch at 0xa8000000200b9a14 targets 0xa8000000200b9a24, is taken when v0(=ret(eg_docmd)) == 0, and falls through when v0(=ret(eg_docmd)) != 0.
  The `beq` branch at 0xa8000000200b9a1c targets 0xa8000000200b9aa8 and is always taken.
  The `beq` branch at 0xa8000000200b9a28 targets 0xa8000000200b9a40 and is always taken.
  The `beq` branch at 0xa8000000200b9a38 targets 0xa8000000200b9abc, is taken when s1(?) >= 0x2711 (signed), and falls through when s1(?) < 0x2711 (signed).
  The `beq` branch at 0xa8000000200b9a44 targets 0xa8000000200b9a30, is taken when a4(=[[a0+816]:8+1660]) == 0, and falls through when a4(=[[a0+816]:8+1660]) != 0.
  The `beq` branch at 0xa8000000200b9a58 targets 0xa8000000200b9aa8, is taken when (a0(=[a0+1228]) & 0x20) == 0, and falls through when (a0(=[a0+1228]) & 0x20) != 0.
  The `bne` branch at 0xa8000000200b9a68 targets 0xa8000000200b9aa8, is taken when a1(=[a0+1232]) < 0x9 (unsigned), and falls through when a1(=[a0+1232]) >= 0x9 (unsigned).
  The `beq` branch at 0xa8000000200b9a78 targets 0xa8000000200b9aa4, is taken when (a2(=[a0+32]) & 0x4) == 0, and falls through when (a2(=[a0+32]) & 0x4) != 0.
  The `beq` branch at 0xa8000000200b9ac4 targets 0xa8000000200b9b0c, is taken when (a1(=[a0+1228]) & 0x20) == 0, and falls through when (a1(=[a0+1228]) & 0x20) != 0.
  The `bne` branch at 0xa8000000200b9ad4 targets 0xa8000000200b9b0c, is taken when a2(=[a0+1232]) < 0x4 (unsigned), and falls through when a2(=[a0+1232]) >= 0x4 (unsigned).
  The `beq` branch at 0xa8000000200b9ae4 targets 0xa8000000200b9b0c, is taken when (a3(=[a0+32]) & 0x4) == 0, and falls through when (a3(=[a0+32]) & 0x4) != 0.
  The `beq` branch at 0xa8000000200b9b0c targets 0xa8000000200b9aa8 and is always taken.
  The return at 0xa8000000200b9ab4 has v0 = one of 0x0, 0x1.
- `random_write_internal` in `IP30/unix` at 0xa800000020156254 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa800000020156254-0xa800000020156334 (224 bytes).
  It occupies 224 bytes.
  2 such `ld` accesses load 8 bytes from abs 0xffffffffaff20000, including `ld` at 0xa800000020156298, `ld` at 0xa8000000201562f8.
  The `jal` at 0xa80000002015629c calls random_harvest_internal [0xa80000002015612c] with a0=[0xffffffffaff20000]:8, a1=?, a2=0x10, a3=0x10, a4=0x0, a5=0x0.
  The `jal` at 0xa8000000201562f4 calls random_harvest_internal [0xa80000002015612c] with a0=[0xffffffffaff20000]:8, a1=?, a2=?, a3=0x0, a4=0x0, a5=0x0.
  The `blez` branch at 0xa800000020156278 targets 0xa800000020156318, is taken when a1 <= 0 (signed), and falls through when a1 > 0 (signed).
  The `bne` branch at 0xa8000000201562ac targets 0xa80000002015628c, is taken when s0(?) < s2(=a1) (signed), and falls through when s0(?) >= s2(=a1) (signed).
  The `beq` branch at 0xa8000000201562b8 targets 0xa8000000201562c8, is taken when s2(=a1) >= s0(?) (signed), and falls through when s2(=a1) < s0(?) (signed).
  The `beq` branch at 0xa8000000201562dc targets 0xa8000000201562fc, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `bltz` branch at 0xa800000020156318 targets 0xa800000020156328, is taken when a1 < 0 (signed), and falls through when a1 >= 0 (signed).
  The `beq` branch at 0xa800000020156320 targets 0xa8000000201562c8 and is always taken.
  The `beq` branch at 0xa80000002015632c targets 0xa8000000201562c4 and is always taken.
  The return at 0xa800000020156310 has v0 = one of ?, ret(random_harvest_internal).
- `do_mprboot` in `IP30/unix` at 0xa8000000201c8f44 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa8000000201c8f44-0xa8000000201c9060 (284 bytes).
  It occupies 284 bytes.
  2 such `lw` accesses load 4 bytes from abs 0xa8000000204fe5f0, including `lw` at 0xa8000000201c8f84, `lw` at 0xa8000000201c8fe8.
  The `sw` at 0xa8000000201c8f94 stores 4 bytes to abs 0xa8000000204fe5f0.
  2 such `lh` accesses load 2 bytes from abs 0xffffffffffffc3a0, including `lh` at 0xa8000000201c8f9c, `lh` at 0xa8000000201c904c.
  The `lh` at 0xa8000000201c8fa0 loads 2 bytes from [0xa8000000204af8c0]:8 +0x3a0.
  2 such `ld` accesses load 8 bytes from abs 0xffffffffaff20000, including `ld` at 0xa8000000201c8fc4, `ld` at 0xa8000000201c9010.
  The `ld` at 0xa8000000201c9020 loads 8 bytes from abs 0xa8000000204fe5f8.
  The `jal` at 0xa8000000201c8f78 calls mutex_spinlock [0xa80000002022d954] with a0=0xa8000000204fe600, a1=?, a2=?, a3=?.
  The `jal` at 0xa8000000201c8f90 calls mutex_spinunlock [0xa80000002022d9a0] with a0=0xa8000000204fe600, a1=ret(mutex_spinlock), a2=?, a3=?.
  The `jal` at 0xa8000000201c8fe0 calls us_delay [0xa800000020011640] with a0=0x186a0, a1=?, a2=?, a3=?, a6=[0xffffffffaff20000]:8.
  The `jal` at 0xa8000000201c9000 calls conbuf_flush [0xa8000000201c8af4] with a0=0x3, a1=?, a2=?, a3=?, a4=[0xa8000000204a81e4].
  The `jalr` at 0xa8000000201c9028 calls (unknown callee) with a0=a0 at entry (arg0), a1=?, a2=?, a3=?, a7=[0xa8000000204fe5f8]:8.
  The `jal` at 0xa8000000201c9050 calls cmn_err [0xa8000000201c6b00] with a0=0x6, a1=0xa8000000203d5cf8, a2=[-0x3c60]:2, a3=a3 at entry (arg3).
  The `bne` branch at 0xa8000000201c8f64 targets 0xa8000000201c8f70, is taken when at(=[0xa8000000204a6814]) < 0x2 (signed), and falls through when at(=[0xa8000000204a6814]) >= 0x2 (signed).
  The `beq` branch at 0xa8000000201c8f6c targets 0xa8000000201c9044, is taken when a2(=[0xa8000000204afb30]) == 0, and falls through when a2(=[0xa8000000204afb30]) != 0.
  The `bne` branch at 0xa8000000201c8fb0 targets 0xa8000000201c9020, is taken when v1(=[-0x3c60]:2) != a1(=[[0xa8000000204af8c0]:8+928]:2), and falls through when v1(=[-0x3c60]:2) == a1(=[[0xa8000000204af8c0]:8+928]:2).
  The `beq` branch at 0xa8000000201c8fd8 targets 0xa8000000201c8ff4 and is always taken.
  The `beq` branch at 0xa8000000201c8fec targets 0xa8000000201c9020, is taken when a3(=[0xa8000000204fe5f0]) == 0, and falls through when a3(=[0xa8000000204fe5f0]) != 0.
  The `beq` branch at 0xa8000000201c8ff8 targets 0xa8000000201c900c, is taken when a4(=[0xa8000000204a81e4]) == 0, and falls through when a4(=[0xa8000000204a81e4]) != 0.
  The `beq` branch at 0xa8000000201c9018 targets 0xa8000000201c8fe0, is taken when a5(?) >= a6(=[0xffffffffaff20000]:8) (unsigned), and falls through when a5(?) < a6(=[0xffffffffaff20000]:8) (unsigned).
  The `beq` branch at 0xa8000000201c9058 targets 0xa8000000201c8f74 and is always taken.
  The return at 0xa8000000201c903c has v0 = ret(?).
- `gfx_flow_init` in `IP30/unix` at 0xa80000002038f230 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002038f230-0xa80000002038f270 (64 bytes).
  It occupies 64 bytes.
  The `sd` at 0xa80000002038f258 stores 8 bytes to abs 0xffffffffaff00040.
  The `jal` at 0xa80000002038f23c calls kmem_zalloc [0xa8000000201486a4] with a0=0x18, a1=0x0, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa80000002038f25c calls spinlock_init [0xa80000002022d728] with a0=0xa8000000204b0024, a1=0xa80000002041c9b0, a2=0x45, a3=0xffffffffaff00000.
  The return at 0xa80000002038f268 has v0 = ret(spinlock_init).
- `gfx_flow_pipe_head_init` in `IP30/unix` at 0xa80000002038f270 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/unix`.
  Range: 0xa80000002038f270-0xa80000002038f318 (168 bytes).
  It occupies 168 bytes.
  The `lh` at 0xa80000002038f278 loads 2 bytes from abs 0xffffffffffffc3a0.
  The `sw` at 0xa80000002038f27c stores 4 bytes to a0 (arg0 at entry) +0x58.
  The `sd` at 0xa80000002038f290 stores 8 bytes to ([0xa8000000204a8620]:8 + ([-0x3c60]:2 << 0x3)) +0x0.
  The `lwu` at 0xa80000002038f298 loads 4 bytes from a0 (arg0 at entry) +0x20.
  The `sd` at 0xa80000002038f2a0 stores 8 bytes to abs 0xffffffffaff00048.
  The `lwu` at 0xa80000002038f2a8 loads 4 bytes from a0 (arg0 at entry) +0x1c.
  The `sd` at 0xa80000002038f2ac stores 8 bytes to ([-0x3c60]:2 << 0x3) -0x500fffa0.
  The `ld` at 0xa80000002038f2b4 loads 8 bytes from a0 (arg0 at entry) +0x10.
  The `ld` at 0xa80000002038f2bc loads 8 bytes from a0 (arg0 at entry) +0x8.
  The `sd` at 0xa80000002038f2dc stores 8 bytes to ([-0x3c60]:2 << 0x3) -0x500fffb0.
  The `ld` at 0xa80000002038f2f0 loads 8 bytes from abs 0xffffffffaff00040.
  The `sd` at 0xa80000002038f304 stores 8 bytes to abs 0xffffffffaff00040.
  The `jal` at 0xa80000002038f2d8 calls mutex_spinlock [0xa80000002022d954] with a0=0xa8000000204b0024, a1=0xffffffff80, a2=0xffffe0, a3=[a0+28], a4=([0xa8000000204a8620]:8 + ([-0x3c60]:2 << 0x3)).
  The `jal` at 0xa80000002038f300 calls mutex_spinunlock [0xa80000002022d9a0] with a0=0xa8000000204b0024, a1=ret(mutex_spinlock), a2=?, a3=?, a6=0xffffffffaff00000.
  The return at 0xa80000002038f310 has v0 = ret(mutex_spinunlock).
- `configurePort` in `sbin/stand/symmon.IP32` at 0xa0020734 (n32).
  Evidence grade: inferred.
  Exact binary: `sbin/stand/symmon.IP32`.
  Range: 0xa0020734-0xa0020854 (288 bytes).
  It occupies 288 bytes.
  The `sd` at 0xa0020768 stores 8 bytes to abs 0xffffffffbf310000.
  2 such `lw` accesses load 4 bytes from (((a0 << 0x3) + a0) << 0x2) -0x5ffc554c, including `lw` at 0xa0020780, `lw` at 0xa00207dc.
  2 such `sb` accesses store 1 byte to [(((a0 << 0x3) + a0) << 0x2)-1610372428] +0x0, including `sb` at 0xa002078c, `sb` at 0xa00207e8.
  The `lw` at 0xa0020794 loads 4 bytes from (((a0 << 0x3) + a0) << 0x2) -0x5ffc553c.
  The `sb` at 0xa00207a0 stores 1 byte to [(((a0 << 0x3) + a0) << 0x2)-1610372412] +0x0.
  2 such `lw` accesses load 4 bytes from (a0 << 0x2) -0x5ffa73a8, including `lw` at 0xa00207a8, `lw` at 0xa00207b8.
  The `lw` at 0xa00207ac loads 4 bytes from (((a0 << 0x3) + a0) << 0x2) -0x5ffc5558.
  The `sb` at 0xa00207b0 stores 1 byte to [(((a0 << 0x3) + a0) << 0x2)-1610372440] +0x0.
  2 such `lw` accesses load 4 bytes from (((a0 << 0x3) + a0) << 0x2) -0x5ffc5554, including `lw` at 0xa00207c8, `lw` at 0xa00207f0.
  2 such `sb` accesses store 1 byte to [(((a0 << 0x3) + a0) << 0x2)-1610372436] +0x0, including `sb` at 0xa00207d4, `sb` at 0xa00207fc.
  The `lw` at 0xa0020804 loads 4 bytes from (((a0 << 0x3) + a0) << 0x2) -0x5ffc5548.
  The `sb` at 0xa0020810 stores 1 byte to [(((a0 << 0x3) + a0) << 0x2)-1610372424] +0x0.
  The `lw` at 0xa0020818 loads 4 bytes from (((a0 << 0x3) + a0) << 0x2) -0x5ffc5550.
  The `sb` at 0xa0020824 stores 1 byte to [(((a0 << 0x3) + a0) << 0x2)-1610372432] +0x0.
  The `sw` at 0xa0020828 stores 4 bytes to table(0xffffffffa0058444) +0x0.
  The `sw` at 0xa0020830 stores 4 bytes to table(0xffffffffa0058448) +0x0.
  The `jal` at 0xa00207a4 calls mapBaud [0xa00208e0] with a0=[(a0 << 0x2)-1610249128], a1=0x18, a2=[(((a0 << 0x3) + a0) << 0x2)-1610372412], a3=[(((a0 << 0x3) + a0) << 0x2)-1610372428].
  The `jal` at 0xa00207b4 calls mapBaud [0xa00208e0] with a0=[(a0 << 0x2)-1610249128], a1=[(((a0 << 0x3) + a0) << 0x2)-1610372440], a2=?, a3=?.
  The `jal` at 0xa0020844 calls __assert [0xa0027fc8] with a0=0xffffffffa0036360, a1=0xffffffffa0036300, a2=0x19c, a3=a3 at entry (arg3).
  The `bltz` branch at 0xa0020748 targets 0xa0020834, is taken when a0 < 0 (signed), and falls through when a0 >= 0 (signed).
  The `beq` branch at 0xa0020754 targets 0xa0020834, is taken when a0 >= 0x2 (signed), and falls through when a0 < 0x2 (signed).
  The `beq` branch at 0xa002084c targets 0xa002075c and is always taken.
  The return at 0xa002082c has v0 = ret(mapBaud).
- `flashEnable` in `sbin/stand/symmon.IP32` at 0xa00277cc (n32).
  Evidence grade: inferred.
  Exact binary: `sbin/stand/symmon.IP32`.
  Range: 0xa00277cc-0xa0027800 (52 bytes).
  It occupies 52 bytes.
  2 such `ld` accesses load 8 bytes from abs 0xffffffffbf310008, including `ld` at 0xa00277d8, `ld` at 0xa00277ec.
  2 such `sd` accesses store 8 bytes to abs 0xffffffffbf310008, including `sd` at 0xa00277e0, `sd` at 0xa00277fc.
  The `beq` branch at 0xa00277d0 targets 0xa00277ec, is taken when a0 == 0, and falls through when a0 != 0.
  The return at 0xa00277e4 has v0 = ?.
  The return at 0xa00277f8 has v0 = ?.
- `clockAccess` in `sbin/stand/symmon.IP32` at 0xa002a4b4 (n32).
  Evidence grade: inferred.
  Exact binary: `sbin/stand/symmon.IP32`.
  Range: 0xa002a4b4-0xa002a5c4 (272 bytes).
  It occupies 272 bytes.
  5 such `lbu` accesses load 1 byte from abs 0xffffffffbf3a0a07, including `lbu` at 0xa002a4b8, `lbu` at 0xa002a4d8, `lbu` at 0xa002a4e8.
  The `lbu` at 0xa002a520 loads 1 byte from a1 (arg1 at entry) +0x7.
  The `lbu` at 0xa002a524 loads 1 byte from a1 (arg1 at entry) +0x6.
  The `lbu` at 0xa002a528 loads 1 byte from a1 (arg1 at entry) +0x5.
  The `lbu` at 0xa002a52c loads 1 byte from a1 (arg1 at entry) +0x4.
  The `lbu` at 0xa002a530 loads 1 byte from a1 (arg1 at entry) +0x3.
  The `lbu` at 0xa002a534 loads 1 byte from a1 (arg1 at entry) +0x0.
  The `lbu` at 0xa002a538 loads 1 byte from a1 (arg1 at entry) +0x1.
  The `lbu` at 0xa002a53c loads 1 byte from a1 (arg1 at entry) +0x2.
  The `sb` at 0xa002a540 stores 1 byte to abs 0xffffffffbf3a0007.
  The `sb` at 0xa002a544 stores 1 byte to abs 0xffffffffbf3a0207.
  The `sb` at 0xa002a548 stores 1 byte to abs 0xffffffffbf3a0407.
  The `sb` at 0xa002a54c stores 1 byte to abs 0xffffffffbf3a0707.
  The `sb` at 0xa002a550 stores 1 byte to abs 0xffffffffbf3a0807.
  The `sb` at 0xa002a554 stores 1 byte to abs 0xffffffffbf3a0907.
  The `sb` at 0xa002a558 stores 1 byte to abs 0xffffffffbf3a4807.
  The `sb` at 0xa002a55c stores 1 byte to abs 0xffffffffbf3a0607.
  The `lbu` at 0xa002a568 loads 1 byte from abs 0xffffffffbf3a0007.
  The `lbu` at 0xa002a56c loads 1 byte from abs 0xffffffffbf3a0207.
  The `lbu` at 0xa002a570 loads 1 byte from abs 0xffffffffbf3a0407.
  The `sb` at 0xa002a574 stores 1 byte to a1 (arg1 at entry) +0x1.
  The `sb` at 0xa002a578 stores 1 byte to a1 (arg1 at entry) +0x2.
  The `lbu` at 0xa002a57c loads 1 byte from abs 0xffffffffbf3a0707.
  The `sb` at 0xa002a580 stores 1 byte to a1 (arg1 at entry) +0x0.
  The `lbu` at 0xa002a584 loads 1 byte from abs 0xffffffffbf3a0807.
  The `sb` at 0xa002a588 stores 1 byte to a1 (arg1 at entry) +0x3.
  The `lbu` at 0xa002a58c loads 1 byte from abs 0xffffffffbf3a0907.
  The `sb` at 0xa002a590 stores 1 byte to a1 (arg1 at entry) +0x4.
  The `lbu` at 0xa002a594 loads 1 byte from abs 0xffffffffbf3a4807.
  The `sb` at 0xa002a598 stores 1 byte to a1 (arg1 at entry) +0x5.
  The `lbu` at 0xa002a59c loads 1 byte from abs 0xffffffffbf3a0607.
  The `sb` at 0xa002a5a0 stores 1 byte to a1 (arg1 at entry) +0x6.
  The `sb` at 0xa002a5a8 stores 1 byte to a1 (arg1 at entry) +0x7.
  The `sb` at 0xa002a5b8 stores 1 byte to abs 0xffffffffbf3a0a07.
  The `beq` branch at 0xa002a4c4 targets 0xa002a4d8, is taken when at(?) == v1(=0x20), and falls through when at(?) != v1(=0x20).
  The `beq` branch at 0xa002a4e0 targets 0xa002a5ac, is taken when (v1(=[0xffffffffbf3a0a07]:1) & 0x10) == 0, and falls through when (v1(=[0xffffffffbf3a0a07]:1) & 0x10) != 0.
  The `beq` branch at 0xa002a4f4 targets 0xa002a518, is taken when (a2(=[0xffffffffbf3a0a07]:1) & 0x80) == 0, and falls through when (a2(=[0xffffffffbf3a0a07]:1) & 0x80) != 0.
  The `beq` branch at 0xa002a500 targets 0xa002a5bc, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `bne` branch at 0xa002a510 targets 0xa002a500, is taken when (v1(=[0xffffffffbf3a0a07]:1) & 0x80) != 0, and falls through when (v1(=[0xffffffffbf3a0a07]:1) & 0x80) == 0.
  The `beq` branch at 0xa002a518 targets 0xa002a568, is taken when a0 == 0, and falls through when a0 != 0.
  The `beq` branch at 0xa002a5a4 targets 0xa002a560 and is always taken.
  The `beq` branch at 0xa002a5b4 targets 0xa002a4e8 and is always taken.
  The return at 0xa002a4d0 has v0 = 0x1.
  The return at 0xa002a560 has v0 = 0x0.
  The return at 0xa002a5bc has v0 = 0x1.
- `resetClock` in `sbin/stand/symmon.IP32` at 0xa002a5c4 (n32).
  Evidence grade: inferred.
  Exact binary: `sbin/stand/symmon.IP32`.
  Range: 0xa002a5c4-0xa002a65c (152 bytes).
  It occupies 152 bytes.
  2 such `lbu` accesses load 1 byte from abs 0xffffffffbf3a0b07, including `lbu` at 0xa002a5fc, `lbu` at 0xa002a62c.
  2 such `sb` accesses store 1 byte to abs 0xffffffffbf3a0b07, including `sb` at 0xa002a610, `sb` at 0xa002a640.
  The `lbu` at 0xa002a614 loads 1 byte from abs 0xffffffffbf3a0a07.
  The `sb` at 0xa002a628 stores 1 byte to abs 0xffffffffbf3a0a07.
  The `jal` at 0xa002a63c calls clockAccess [0xa002a4b4] with a0=0x1, a1=sp-16, a2=0x1, a3=?, a4=-0x41, a6=-0x5, a7=0x2.
  The `jal` at 0xa002a648 calls printf [0xa002e620] with a0=0xffffffffa0037678, a1=?, a2=?, a3=?.
  The return at 0xa002a654 has v0 = ret(printf).

Skipped no routines.
