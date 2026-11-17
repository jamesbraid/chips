# Readings: `IP32/usr/cpu/sysgen/IP32boot/if_me.o`

One entry per routine, filed here from the reading batches by binary.

- `me_txfree_len` in `IP32/usr/cpu/sysgen/IP32boot/if_me.o` at 0x0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/if_me.o`.
  Range: 0x0-0x2c (44 bytes).
  It occupies 44 bytes.
  The `lw` at 0x8 loads 4 bytes from a0 (arg0 at entry) +0xbc.
  The `lw` at 0x1c loads 4 bytes from [a0+188] +0x2b4.
  The `jal` at 0x10 calls mace_ether_transmit_complete with a0=[a0+188], a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x24 has v0 = [[a0+188]+692].

- `me_setstate` in `IP32/usr/cpu/sysgen/IP32boot/if_me.o` at 0x2c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/if_me.o`.
  Range: 0x2c-0x5c (48 bytes).
  It occupies 48 bytes.
  The `lh` at 0x38 loads 2 bytes from sym(.bss) +0x57e.
  2 such `sh` accesses store 2 bytes to sym(.bss) +0x57e, including `sh` at 0x40, `sh` at 0x58.
  The `beq` branch at 0x34 targets 0x4c, is taken when a1 == 0, and falls through when a1 != 0.
  The return at 0x44 has v0 = ?.
  The return at 0x54 has v0 = ?.

- `mace_ether_mdio_rd` in `IP32/usr/cpu/sysgen/IP32boot/if_me.o` at 0x5c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/if_me.o`.
  Range: 0x5c-0x13c (224 bytes).
  It occupies 224 bytes.
  The `lw` at 0x6c loads 4 bytes from a0 (arg0 at entry) +0x2a0.
  The `lb` at 0xbc loads 1 byte from a0 (arg0 at entry) +0x2a9.
  The `jal` at 0x88 calls pciio_pio_read32 with a0=[a0+672]+100, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa0 calls us_delay with a0=0x19, a1=?, a2=?, a3=?.
  The `jal` at 0xa8 calls pciio_pio_read32 with a0=[a0+672]+100, a1=?, a2=?, a3=?.
  The `jal` at 0xcc calls pciio_pio_write32 with a0=?, a1=[a0+672]+108, a2=([a0+681]:1 << 0x5), a3=?.
  The `jal` at 0xdc calls pciio_pio_write32 with a0=a1 at entry (arg1), a1=[a0+672]+116, a2=?, a3=?.
  The `jal` at 0xec calls us_delay with a0=0x19, a1=?, a2=?, a3=?.
  The `jal` at 0xf4 calls pciio_pio_read32 with a0=[a0+672]+100, a1=?, a2=?, a3=?.
  The `jal` at 0x108 calls us_delay with a0=0x19, a1=?, a2=?, a3=?.
  The `jal` at 0x110 calls pciio_pio_read32 with a0=[a0+672]+100, a1=?, a2=?, a3=?.
  The `bgez` branch at 0x98 targets 0xbc, is taken when at(=(ret(pciio_pio_read32) << 0x2f)) >= 0 (signed), and falls through when at(=(ret(pciio_pio_read32) << 0x2f)) < 0 (signed).
  The `bne` branch at 0xb4 targets 0xa0, is taken when (s0(=0x10000) & v0(=ret(pciio_pio_read32))) != 0, and falls through when (s0(=0x10000) & v0(=ret(pciio_pio_read32))) == 0.
  The `beq` branch at 0x100 targets 0x124, is taken when (s0(=0x10000) & v0(=ret(pciio_pio_read32))) == 0, and falls through when (s0(=0x10000) & v0(=ret(pciio_pio_read32))) != 0.
  The `bne` branch at 0x11c targets 0x108, is taken when (s0(=0x10000) & v0(=ret(pciio_pio_read32))) != 0, and falls through when (s0(=0x10000) & v0(=ret(pciio_pio_read32))) == 0.
  The return at 0x134 has v0 = ret(pciio_pio_read32).

- `mace_ether_mdio_wr` in `IP32/usr/cpu/sysgen/IP32boot/if_me.o` at 0x13c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/if_me.o`.
  Range: 0x13c-0x228 (236 bytes).
  It occupies 236 bytes.
  The `lw` at 0x150 loads 4 bytes from a0 (arg0 at entry) +0x2a0.
  The `lb` at 0x1a8 loads 1 byte from a0 (arg0 at entry) +0x2a9.
  The `jal` at 0x170 calls pciio_pio_read32 with a0=[a0+672]+100, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x188 calls us_delay with a0=0x19, a1=?, a2=?, a3=?.
  The `jal` at 0x190 calls pciio_pio_read32 with a0=[a0+672]+100, a1=?, a2=?, a3=?.
  The `jal` at 0x1b8 calls pciio_pio_write32 with a0=?, a1=[a0+672]+108, a2=([a0+681]:1 << 0x5), a3=?.
  The `jal` at 0x1cc calls pciio_pio_write32 with a0=a2 at entry (arg2), a1=[a0+672]+100, a2=?, a3=?.
  The `jal` at 0x1d4 calls us_delay with a0=0x19, a1=?, a2=?, a3=?.
  The `jal` at 0x1dc calls pciio_pio_read32 with a0=[a0+672]+100, a1=?, a2=?, a3=?.
  The `jal` at 0x1f0 calls us_delay with a0=0x19, a1=?, a2=?, a3=?.
  The `jal` at 0x1f8 calls pciio_pio_read32 with a0=[a0+672]+100, a1=?, a2=?, a3=?.
  The `bgez` branch at 0x180 targets 0x1a4, is taken when t8(=(ret(pciio_pio_read32) << 0x2f)) >= 0 (signed), and falls through when t8(=(ret(pciio_pio_read32) << 0x2f)) < 0 (signed).
  The `bne` branch at 0x19c targets 0x188, is taken when (s0(=0x10000) & v0(=ret(pciio_pio_read32))) != 0, and falls through when (s0(=0x10000) & v0(=ret(pciio_pio_read32))) == 0.
  The `beq` branch at 0x1e8 targets 0x20c, is taken when (s0(=0x10000) & v0(=ret(pciio_pio_read32))) == 0, and falls through when (s0(=0x10000) & v0(=ret(pciio_pio_read32))) != 0.
  The `bne` branch at 0x204 targets 0x1f0, is taken when (s0(=0x10000) & v0(=ret(pciio_pio_read32))) != 0, and falls through when (s0(=0x10000) & v0(=ret(pciio_pio_read32))) == 0.
  The return at 0x220 has v0 = a2.

- `mace_ether_mdio_rmw` in `IP32/usr/cpu/sysgen/IP32boot/if_me.o` at 0x228 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/if_me.o`.
  Range: 0x228-0x2c4 (156 bytes).
  It occupies 156 bytes.
  The `lw` at 0x258 loads 4 bytes from a0 (arg0 at entry) +0x14.
  The `lbu` at 0x274 loads 1 byte from a0 (arg0 at entry) +0x580.
  The `jal` at 0x250 calls mace_ether_mdio_rd with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x28c calls printf with a0=([a0+1408]:1 + sym(.rodata)+24), a1=a1 at entry (arg1), a2=ret(mace_ether_mdio_rd), a3=?.
  The `jal` at 0x2a4 calls mace_ether_mdio_wr with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?.
  The `beq` branch at 0x26c targets 0x294, is taken when (t9(=[a0+20]) & 0x4) == 0, and falls through when (t9(=[a0+20]) & 0x4) != 0.
  The return at 0x2bc has v0 = ret(mace_ether_mdio_wr).

- `mace_ether_mdio_errata` in `IP32/usr/cpu/sysgen/IP32boot/if_me.o` at 0x2c4 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/if_me.o`.
  Range: 0x2c4-0x35c (152 bytes).
  It occupies 152 bytes.
  The `lw` at 0x2d0 loads 4 bytes from sym(me_phyerrata) +0x0.
  2 such `lw` accesses load 4 bytes from sym(me_phyerrata) +0xc, including `lw` at 0x2f8, `lw` at 0x340.
  The `lw` at 0x304 loads 4 bytes from a0 (arg0 at entry) +0x2ac.
  The `lh` at 0x310 loads 2 bytes from sym(me_phyerrata) +0x4.
  The `lbu` at 0x31c loads 1 byte from a0 (arg0 at entry) +0x2aa.
  The `lh` at 0x328 loads 2 bytes from sym(me_phyerrata) +0x6.
  The `lh` at 0x32c loads 2 bytes from sym(me_phyerrata) +0x8.
  The `lh` at 0x338 loads 2 bytes from sym(me_phyerrata) +0xa.
  The `jal` at 0x334 calls mace_ether_mdio_rmw with a0=a0 at entry (arg0), a1=[sym(me_phyerrata)+6]:2, a2=[sym(me_phyerrata)+8]:2, a3=[sym(me_phyerrata)+10]:2, a4=[a0+684].
  The `beq` branch at 0x2e8 targets 0x344, is taken when a2(=[sym(me_phyerrata)]) == 0, and falls through when a2(=[sym(me_phyerrata)]) != 0.
  The `beq` branch at 0x2f0 targets 0x304 and is always taken.
  The `beq` branch at 0x2fc targets 0x344, is taken when a2(=[sym(me_phyerrata)+12]) == 0, and falls through when a2(=[sym(me_phyerrata)+12]) != 0.
  The `bne` branch at 0x308 targets 0x2f8, is taken when a4(=[a0+684]) != a2(?), and falls through when a4(=[a0+684]) == a2(?).
  The `beq` branch at 0x314 targets 0x328, is taken when a0(=[sym(me_phyerrata)+4]:2) == s2(=-0x1), and falls through when a0(=[sym(me_phyerrata)+4]:2) != s2(=-0x1).
  The `bne` branch at 0x320 targets 0x2f8, is taken when a0(=[sym(me_phyerrata)+4]:2) != a5(=[a0+682]:1), and falls through when a0(=[sym(me_phyerrata)+4]:2) == a5(=[a0+682]:1).
  The `beq` branch at 0x33c targets 0x2fc and is always taken.
  The return at 0x354 has v0 = ?.

- `mace_ether_mdio_probe` in `IP32/usr/cpu/sysgen/IP32boot/if_me.o` at 0x35c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/if_me.o`.
  Range: 0x35c-0x46c (272 bytes).
  It occupies 272 bytes.
  The `lb` at 0x378 loads 1 byte from a0 (arg0 at entry) +0x2a9.
  The `lw` at 0x3a8 loads 4 bytes from a0 (arg0 at entry) +0x2ac.
  2 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x2a9, including `sb` at 0x3d4, `sb` at 0x42c.
  The `sb` at 0x434 stores 1 byte to a0 (arg0 at entry) +0x2aa.
  The `sw` at 0x438 stores 4 bytes to a0 (arg0 at entry) +0x2ac.
  The `jal` at 0x3d0 calls mace_ether_mdio_rd with a0=a0 at entry (arg0), a1=0x2, a2=?, a3=one of -0x1, 0x2000000.
  The `jal` at 0x3e0 calls mace_ether_mdio_rd with a0=a0 at entry (arg0), a1=0x3, a2=?, a3=?.
  The `bltz` branch at 0x394 targets 0x3ac, is taken when at(=[a0+681]:1) < 0 (signed), and falls through when at(=[a0+681]:1) >= 0 (signed).
  The `beq` branch at 0x39c targets 0x3b0, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x3a4 targets 0x43c and is always taken.
  The `beq` branch at 0x3f8 targets 0x430, is taken when a3(?) == s3(=0x15f41), and falls through when a3(?) != s3(=0x15f41).
  The `beq` branch at 0x400 targets 0x434, is taken when a3(?) == s4(=0x15f42), and falls through when a3(?) != s4(=0x15f42).
  The `beq` branch at 0x408 targets 0x434, is taken when a3(?) == s5(=0x15f43), and falls through when a3(?) != s5(=0x15f43).
  The `beq` branch at 0x410 targets 0x434, is taken when a3(?) == s6(=0x181440), and falls through when a3(?) != s6(=0x181440).
  The `beq` branch at 0x418 targets 0x434, is taken when a3(?) == s7(=0x20005c0), and falls through when a3(?) != s7(=0x20005c0).
  The `bne` branch at 0x420 targets 0x3c8, is taken when a0(?) != 0, and falls through when a0(?) == 0.
  The `beq` branch at 0x428 targets 0x43c and is always taken.
  The return at 0x464 has v0 = one of [a0+684], -0x1, ?.

- `mace_ether_link_update` in `IP32/usr/cpu/sysgen/IP32boot/if_me.o` at 0x46c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/if_me.o`.
  Range: 0x46c-0x9f4 (1416 bytes).
  It occupies 1416 bytes.
  2 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x2ab, including `lbu` at 0x46c, `lbu` at 0x634.
  The `lw` at 0x4bc loads 4 bytes from a0 (arg0 at entry) +0x2a4.
  The `lw` at 0x4cc loads 4 bytes from a0 (arg0 at entry) +0x2ac.
  9 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x14, including `lw` at 0x558, `lw` at 0x5b8, `lw` at 0x6d0.
  The `lbu` at 0x590 loads 1 byte from a0 (arg0 at entry) +0x580.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x14, including `sw` at 0x5c8, `sw` at 0x740.
  The `lw` at 0x5cc loads 4 bytes from sym(me_fullduplex_ipg) +0x0.
  The `lw` at 0x5d8 loads 4 bytes from sym(me_fullduplex_ipg) +0x4.
  The `lw` at 0x5dc loads 4 bytes from sym(me_fullduplex_ipg) +0x8.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x2a0, including `lw` at 0x5f8, `lw` at 0x60c, `lw` at 0x618.
  The `sw` at 0x600 stores 4 bytes to a0 (arg0 at entry) +0x2a4.
  The `lw` at 0x628 loads 4 bytes from a0 (arg0 at entry) +0x24.
  The `sb` at 0x644 stores 1 byte to a0 (arg0 at entry) +0x2ab.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x24, including `sw` at 0x658, `sw` at 0x718.
  2 such `sh` accesses store 2 bytes to a0 (arg0 at entry) +0x57c, including `sh` at 0x664, `sh` at 0x728.
  The `lw` at 0x744 loads 4 bytes from sym(me_halfduplex_ipg) +0x0.
  The `lw` at 0x750 loads 4 bytes from sym(me_halfduplex_ipg) +0x4.
  The `lw` at 0x754 loads 4 bytes from sym(me_halfduplex_ipg) +0x8.
  The `jal` at 0x4b8 calls mace_ether_mdio_rd with a0=a0 at entry (arg0), a1=0x6, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x514 calls mace_ether_mdio_rd with a0=a0 at entry (arg0), a1=0x1f, a2=0x15f42, a3=0x15f43, a4=0x181440.
  The `jal` at 0x53c calls mace_ether_mdio_rd with a0=a0 at entry (arg0), a1=0x4, a2=?, a3=?.
  The `jal` at 0x54c calls mace_ether_mdio_rd with a0=a0 at entry (arg0), a1=0x5, a2=?, a3=?.
  The `jal` at 0x59c calls printf with a0=([a0+1408]:1 + sym(.rodata)+80), a1=one of 0xa, 0x64, a2=?, a3=?, a4=sym(.rodata)+80.
  The `jal` at 0x604 calls pciio_pio_write32 with a0=?, a1=[a0+672]+4, a2=?, a3=?.
  The `jal` at 0x610 calls pciio_pio_read32 with a0=[a0+672]+20, a1=?, a2=?, a3=?.
  The `jal` at 0x620 calls pciio_pio_write32 with a0=(ret(pciio_pio_read32) | 0x2), a1=[a0+672]+20, a2=?, a3=?.
  The `jal` at 0x690 calls ps_reinit with a0=a0 at entry (arg0), a1=sp-64, a2=sym(me_txfree_len), a3=sym(me_setstate), a4=0x80.
  The `jal` at 0x6b0 calls mace_ether_mdio_rd with a0=a0 at entry (arg0), a1=0x11, a2=0x15f42, a3=?.
  The `jal` at 0x7d4 calls mace_ether_mdio_rd with a0=a0 at entry (arg0), a1=0x19, a2=?, a3=?.
  The `beq` branch at 0x484 targets 0x4a4, is taken when (at(=[a0+683]:1) & 0x22) == 0, and falls through when (at(=[a0+683]:1) & 0x22) != 0.
  The `beq` branch at 0x4ac targets 0x6a4, is taken when (a1 & 0x20) == 0, and falls through when (a1 & 0x20) != 0.
  The `bne` branch at 0x4c4 targets 0x53c, is taken when (v0(=ret(mace_ether_mdio_rd)) & 0x1) != 0, and falls through when (v0(=ret(mace_ether_mdio_rd)) & 0x1) == 0.
  The `beq` branch at 0x4d8 targets 0x7d4, is taken when v0(=[a0+684]) == a0(=0x20005c0), and falls through when v0(=[a0+684]) != a0(=0x20005c0).
  The `beq` branch at 0x4e8 targets 0x6ac, is taken when v0(=[a0+684]) == a1(=0x15f41), and falls through when v0(=[a0+684]) != a1(=0x15f41).
  The `beq` branch at 0x4f0 targets 0x6ac, is taken when v0(=[a0+684]) == a2(=0x15f42), and falls through when v0(=[a0+684]) != a2(=0x15f42).
  The `beq` branch at 0x4f8 targets 0x6b0, is taken when v0(=[a0+684]) == a3(=0x15f43), and falls through when v0(=[a0+684]) != a3(=0x15f43).
  The `bne` branch at 0x508 targets 0x53c, is taken when v0(=[a0+684]) != a4(=0x181440), and falls through when v0(=[a0+684]) == a4(=0x181440).
  The `beq` branch at 0x520 targets 0x8bc, is taken when (v0(=ret(mace_ether_mdio_rd)) & 0x8) == 0, and falls through when (v0(=ret(mace_ether_mdio_rd)) & 0x8) != 0.
  The `beq` branch at 0x528 targets 0x8d4, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x530 targets 0x6d0 and is always taken.
  The `beq` branch at 0x560 targets 0x7a4, is taken when (a3(?) & 0x200) == 0, and falls through when (a3(?) & 0x200) != 0.
  The `beq` branch at 0x568 targets 0x784, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x570 targets 0x808, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0x5b0 targets 0x72c, is taken when s3(?) == 0, and falls through when s3(?) != 0.
  The `beq` branch at 0x5d0 targets 0x774, is taken when v0(=[sym(me_fullduplex_ipg)]) == 0, and falls through when v0(=[sym(me_fullduplex_ipg)]) != 0.
  The `beq` branch at 0x640 targets 0x708, is taken when (s2(?) & 0x8) == 0, and falls through when (s2(?) & 0x8) != 0.
  The `beq` branch at 0x69c targets 0x490 and is always taken.
  The `beq` branch at 0x6a4 targets 0x490 and is always taken.
  The `beq` branch at 0x6bc targets 0x81c, is taken when (v0(=ret(mace_ether_mdio_rd)) & 0x8000) == 0, and falls through when (v0(=ret(mace_ether_mdio_rd)) & 0x8000) != 0.
  The `beq` branch at 0x6c4 targets 0x83c, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x6d8 targets 0x788, is taken when (a0(=[a0+20]) & 0x4) == 0, and falls through when (a0(=[a0+20]) & 0x4) != 0.
  The `beq` branch at 0x6e4 targets 0x814, is taken when (s1(?) & 0x8) == 0, and falls through when (s1(?) & 0x8) != 0.
  The `beq` branch at 0x6f4 targets 0x588, is taken when (s1(?) & 0x2) == 0, and falls through when (s1(?) & 0x2) != 0.
  The `beq` branch at 0x700 targets 0x590 and is always taken.
  The `beq` branch at 0x724 targets 0x668 and is always taken.
  The `beq` branch at 0x748 targets 0x82c, is taken when v0(=[sym(me_halfduplex_ipg)]) == 0, and falls through when v0(=[sym(me_halfduplex_ipg)]) != 0.
  The `beq` branch at 0x76c targets 0x5f8 and is always taken.
  The `beq` branch at 0x77c targets 0x5f8 and is always taken.
  The `bne` branch at 0x794 targets 0x5bc, is taken when (s1(?) & 0x2) != 0, and falls through when (s1(?) & 0x2) == 0.
  The `beq` branch at 0x79c targets 0x734 and is always taken.
  The `beq` branch at 0x7a8 targets 0x860, is taken when (a3(?) & 0x100) == 0, and falls through when (a3(?) & 0x100) != 0.
  The `beq` branch at 0x7b0 targets 0x88c, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x7b8 targets 0x8b0, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0x7cc targets 0x6fc and is always taken.
  The `beq` branch at 0x7e4 targets 0x894, is taken when (v0(=ret(mace_ether_mdio_rd)) & 0x40) == 0, and falls through when (v0(=ret(mace_ether_mdio_rd)) & 0x40) != 0.
  The `beq` branch at 0x7ec targets 0x8cc, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x800 targets 0x588 and is always taken.
  The `beq` branch at 0x80c targets 0x580 and is always taken.
  The `beq` branch at 0x814 targets 0x6ec and is always taken.
  The `beq` branch at 0x81c targets 0x8f8, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x824 targets 0x6cc and is always taken.
  The `beq` branch at 0x834 targets 0x5f8 and is always taken.
  The `beq` branch at 0x844 targets 0x91c, is taken when (a0(=[a0+20]) & 0x4) == 0, and falls through when (a0(=[a0+20]) & 0x4) != 0.
  The `beq` branch at 0x858 targets 0x588 and is always taken.
  The `beq` branch at 0x860 targets 0x924, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0x868 targets 0x950, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x870 targets 0x960, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0x884 targets 0x588 and is always taken.
  The `beq` branch at 0x88c targets 0x784 and is always taken.
  The `beq` branch at 0x894 targets 0x958, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x8a8 targets 0x588 and is always taken.
  The `beq` branch at 0x8b4 targets 0x7c8 and is always taken.
  The `beq` branch at 0x8bc targets 0x96c, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x8c4 targets 0x530 and is always taken.
  The `beq` branch at 0x8cc targets 0x784 and is always taken.
  The `beq` branch at 0x8dc targets 0x990, is taken when (a0(=[a0+20]) & 0x4) == 0, and falls through when (a0(=[a0+20]) & 0x4) != 0.
  The `beq` branch at 0x8f0 targets 0x588 and is always taken.
  The `beq` branch at 0x900 targets 0x998, is taken when (a0(=[a0+20]) & 0x4) == 0, and falls through when (a0(=[a0+20]) & 0x4) != 0.
  The `beq` branch at 0x914 targets 0x588 and is always taken.
  The `beq` branch at 0x91c targets 0x784 and is always taken.
  The `beq` branch at 0x924 targets 0x9a0, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0x92c targets 0x9c4, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x934 targets 0x9cc, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0x948 targets 0x6fc and is always taken.
  The `beq` branch at 0x950 targets 0x784 and is always taken.
  The `beq` branch at 0x958 targets 0x784 and is always taken.
  The `beq` branch at 0x964 targets 0x880 and is always taken.
  The `beq` branch at 0x974 targets 0x9d8, is taken when (a0(=[a0+20]) & 0x4) == 0, and falls through when (a0(=[a0+20]) & 0x4) != 0.
  The `beq` branch at 0x988 targets 0x588 and is always taken.
  The `beq` branch at 0x990 targets 0x784 and is always taken.
  The `beq` branch at 0x998 targets 0x784 and is always taken.
  The `beq` branch at 0x9a0 targets 0x9e0, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x9a8 targets 0x9e8, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0x9bc targets 0x588 and is always taken.
  The `beq` branch at 0x9c4 targets 0x784 and is always taken.
  The `beq` branch at 0x9d0 targets 0x944 and is always taken.
  The `beq` branch at 0x9d8 targets 0x784 and is always taken.
  The `beq` branch at 0x9e0 targets 0x784 and is always taken.
  The `beq` branch at 0x9ec targets 0x9b8 and is always taken.
  The return at 0x49c has v0 = one of 0x0, 0x10.
  The instructions from 0x538 to 0x538 are not reached by any path from the entry, and their branches are not listed.

- `if_meedtinit` in `IP32/usr/cpu/sysgen/IP32boot/if_me.o` at 0x9f4 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/if_me.o`.
  Range: 0x9f4-0xc44 (592 bytes).
  It occupies 592 bytes.
  The `sw` at 0xa3c stores 4 bytes to sym(.bss) +0x2a0.
  The `sb` at 0xa50 stores 1 byte to sym(.bss) +0x580.
  The `lbu` at 0xa5c loads 1 byte from sym(.bss) +0x580.
  5 such `lw` accesses load 4 bytes from sym(.bss) +0x2a0, including `lw` at 0xa7c, `lw` at 0xa8c, `lw` at 0xa9c.
  The `sd` at 0xab0 stores 8 bytes to sym(.bss) +0x298.
  The `sw` at 0xac0 stores 4 bytes to sym(.bss) +0xbc.
  The `sb` at 0xacc stores 1 byte to sym(.bss) +0x2a9.
  The `sb` at 0xadc stores 1 byte to sym(.bss) +0x2a8.
  The `sw` at 0xae0 stores 4 bytes to sym(.bss) +0x14.
  The `lbu` at 0xb1c loads 1 byte from sym(.bss) +0x2a8.
  The `sw` at 0xbc4 stores 4 bytes to sym(.bss) +0x594.
  The `sw` at 0xbcc stores 4 bytes to sym(.bss) +0x58c.
  The `sw` at 0xbd4 stores 4 bytes to sym(.bss) +0x588.
  The `sw` at 0xbdc stores 4 bytes to sym(.bss) +0x584.
  The `sw` at 0xbe8 stores 4 bytes to sym(.bss) +0x4b8.
  The `jal` at 0xa38 calls bcopy with a0=sym(eaddr), a1=sp-80, a2=0x6, a3=0x1.
  The `jal` at 0xa54 calls ether_sprintf with a0=sp-80, a1=?, a2=?, a3=?, a5=[sym(showconfig)].
  The `jal` at 0xa74 calls printf with a0=([sym(.bss)+1408]:1 + sym(.rodata))+144, a1=0x0, a2=ret(ether_sprintf), a3=?.
  The `jal` at 0xa84 calls pciio_pio_write64 with a0=0x0, a1=[sym(.bss)+672]+160, a2=?, a3=?.
  The `jal` at 0xa94 calls pciio_pio_write64 with a0=0x0, a1=[sym(.bss)+672]+168, a2=?, a3=?.
  The `jal` at 0xaa4 calls pciio_pio_write64 with a0=0x0, a1=[sym(.bss)+672]+176, a2=?, a3=?.
  The `jal` at 0xab4 calls pciio_pio_read32 with a0=[sym(.bss)+672]+4, a1=?, a2=?, a3=?.
  The `jal` at 0xb08 calls ether_attach with a0=sym(.bss), a1=sym(.rodata)+224, a2=0x0, a3=sym(.bss), a4=sym(.data), a5=sp-80, a6=0x0.
  The `jal` at 0xb20 calls add_to_inventory with a0=0x8, a1=0x0, a2=0x0, a3=0x0, a4=[sym(.bss)+680]:1.
  The `jal` at 0xb28 calls mace_hwgraph_lookup with a0=sp-72, a1=?, a2=?, a3=?.
  The `jal` at 0xb40 calls idbg_addfunc with a0=sym(.rodata)+248, a1=sym(mace_ether_dump), a2=?, a3=?.
  The `jal` at 0xb50 calls pciio_pio_write64 with a0=0x80000, a1=[sym(.bss)+672]+88, a2=?, a3=?.
  The `jal` at 0xb6c calls setcrimevector with a0=0x3, a1=0x1, a2=sym(mace_ether_intr), a3=sym(.bss), a4=0x0.
  The `jal` at 0xb8c calls cmn_err_tag with a0=0x10d, a1=0x1, a2=sym(.rodata), a3=?.
  The `jal` at 0xba8 calls timeout_pri with a0=sym(mace_ether_timer), a1=sym(.bss), a2=0x64, a3=[sym(network_intr_pri)]+1.
  The `jal` at 0xbb8 calls contmemall with a0=0x4, a1=0x4, a2=0x101, a3=?.
  The `jal` at 0xbfc calls sprintf with a0=sp-64, a1=sym(.rodata)+228, a2=sym(.rodata)+224, a3=?.
  The `jal` at 0xc18 calls sprintf with a0=sp-32, a1=sym(.rodata)+232, a2=sym(.rodata)+224, a3=0x0.
  The `jal` at 0xc34 calls if_hwgraph_add with a0=?, a1=sp-64, a2=sym(.rodata)+240, a3=sp-32, a4=sp-24.
  The `beq` branch at 0xa00 targets 0xa14, is taken when at(=[sym(.sbss)]) == 0, and falls through when at(=[sym(.sbss)]) != 0.
  The `beq` branch at 0xa4c targets 0xa7c, is taken when a5(=[sym(showconfig)]) == 0, and falls through when a5(=[sym(showconfig)]) != 0.
  The `beq` branch at 0xad8 targets 0xae4, is taken when (a1(=[sym(if_medevflag)]) & 0x1000) == 0, and falls through when (a1(=[sym(if_medevflag)]) & 0x1000) != 0.
  The `beq` branch at 0xb30 targets 0xbec, is taken when v0(=ret(mace_hwgraph_lookup)) == 0, and falls through when v0(=ret(mace_hwgraph_lookup)) != 0.
  The `beq` branch at 0xb74 targets 0xb98, is taken when v0(=ret(setcrimevector)) == 0, and falls through when v0(=ret(setcrimevector)) != 0.
  The `beq` branch at 0xbe4 targets 0xa08 and is always taken.
  The `beq` branch at 0xc3c targets 0xb38 and is always taken.
  The return at 0xa0c has v0 = one of ?, ret(contmemall).

- `mace_hdwrether_init` in `IP32/usr/cpu/sysgen/IP32boot/if_me.o` at 0xc44 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/if_me.o`.
  Range: 0xc44-0xe34 (496 bytes).
  It occupies 496 bytes.
  8 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x2a0, including `lw` at 0xc48, `lw` at 0xc64, `lw` at 0xc74.
  The `lw` at 0xc78 loads 4 bytes from a0 (arg0 at entry) +0x2a4.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x4b8, including `lw` at 0xc8c, `lw` at 0xc94.
  The `sh` at 0xcb4 stores 2 bytes to a0 (arg0 at entry) +0x2b2.
  The `sh` at 0xcb8 stores 2 bytes to a0 (arg0 at entry) +0x2b0.
  The `sw` at 0xcc0 stores 4 bytes to a0 (arg0 at entry) +0x2b4.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0xcd0, `lw` at 0xd34.
  3 such `sw` accesses store 4 bytes to ?, including `sw` at 0xce4, `sw` at 0xd38, `sw` at 0xe00.
  The `sw` at 0xcec stores 4 bytes to a0 (arg0 at entry) +0x528.
  2 such `sh` accesses store 2 bytes to a0 (arg0 at entry) +0x4e6, including `sh` at 0xcf4, `sh` at 0xd84.
  The `sh` at 0xcf8 stores 2 bytes to a0 (arg0 at entry) +0x4e4.
  The `sh` at 0xcfc stores 2 bytes to a0 (arg0 at entry) +0x4be.
  The `sh` at 0xd04 stores 2 bytes to a0 (arg0 at entry) +0x10.
  The `sh` at 0xd10 stores 2 bytes to a0 (arg0 at entry) +0x4bc.
  4 such `lh` accesses load 2 bytes from a0 (arg0 at entry) +0x4e6, including `lh` at 0xd20, `lh` at 0xd3c, `lh` at 0xdb0.
  2 such `lw` accesses load 4 bytes from ret(m_vget) +0x4, including `lw` at 0xdd4, `lw` at 0xde4.
  The `jal` at 0xc5c calls pciio_pio_write32 with a0=0x1, a1=[a0+672]+4, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xc6c calls pciio_pio_write32 with a0=0x0, a1=[a0+672]+4, a2=?, a3=?.
  The `jal` at 0xc7c calls pciio_pio_write32 with a0=[a0+676], a1=[a0+672]+4, a2=?, a3=?.
  The `jal` at 0xc88 calls bzero with a0=[a0+1208], a1=0x4000, a2=?, a3=?.
  The `jal` at 0xc90 calls kvtophys with a0=[a0+1208], a1=?, a2=?, a3=?.
  The `jal` at 0xcac calls pciio_pio_write64 with a0=?, a1=[a0+672]+184, a2=?, a3=?.
  The `jal` at 0xccc calls m_freem with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xd18 calls pciio_pio_write32 with a0=[sym(me_rxdelay)], a1=[a0+672]+28, a2=[sym(me_rxdelay)], a3=0x18, a4=0x10, a5=0x1.
  The `jal` at 0xd30 calls m_freem with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xd68 calls m_vget with a0=0x0, a1=0x1000, a2=0x1, a3=?.
  The `jal` at 0xd94 calls microtime with a0=sp-48, a1=?, a2=?, a3=?.
  The `jal` at 0xda4 calls pciio_pio_write32 with a0=?, a1=[a0+672]+124, a2=?, a3=?.
  The `jal` at 0xdbc calls pciio_pio_write32 with a0=(([a0+1254]:2 << 0x4) | 0xb206), a1=[a0+672]+20, a2=?, a3=?.
  The `jal` at 0xddc calls __vm_dcache_inval with a0=([ret(m_vget)+4] + ret(m_vget)), a1=0x1000, a2=?, a3=?.
  The `jal` at 0xde8 calls kvtophys with a0=([ret(m_vget)+4] + ret(m_vget)), a1=?, a2=?, a3=?.
  The `jal` at 0xdf8 calls pciio_pio_write32 with a0=ret(kvtophys), a1=[a0+672]+260, a2=?, a3=?.
  The `jal` at 0xe24 calls printf with a0=sym(.rodata)+256, a1=?, a2=?, a3=?.
  The `bne` branch at 0xce0 targets 0xccc, is taken when s1(?) < 0x80 (signed), and falls through when s1(?) >= 0x80 (signed).
  The `blez` branch at 0xd28 targets 0xd50, is taken when v0(=[a0+1254]:2) <= 0 (signed), and falls through when v0(=[a0+1254]:2) > 0 (signed).
  The `bne` branch at 0xd48 targets 0xd30, is taken when s1(?) < v0(=[a0+1254]:2) (signed), and falls through when s1(?) >= v0(=[a0+1254]:2) (signed).
  The `blez` branch at 0xd54 targets 0xd88, is taken when v0(=[a0+1254]:2) <= 0 (signed), and falls through when v0(=[a0+1254]:2) > 0 (signed).
  The `bne` branch at 0xd70 targets 0xdd4, is taken when v0(=ret(m_vget)) != 0, and falls through when v0(=ret(m_vget)) == 0.
  The `beq` branch at 0xd80 targets 0xe20, is taken when a7(?) == 0, and falls through when a7(?) != 0.
  The `bne` branch at 0xe10 targets 0xd60, is taken when s1(?) < a2(=[a0+1254]:2) (signed), and falls through when s1(?) >= a2(=[a0+1254]:2) (signed).
  The `beq` branch at 0xe18 targets 0xd8c and is always taken.
  The `beq` branch at 0xe2c targets 0xd8c and is always taken.
  The return at 0xdcc has v0 = ret(pciio_pio_write32).

- `mace_ether_init` in `IP32/usr/cpu/sysgen/IP32boot/if_me.o` at 0xe34 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/if_me.o`.
  Range: 0xe34-0x1310 (1244 bytes).
  It occupies 1244 bytes.
  The `lw` at 0xe3c loads 4 bytes from a0 (arg0 at entry) +0xbc.
  3 such `lw` accesses load 4 bytes from [a0+188] +0x2a0, including `lw` at 0xe48, `lw` at 0xe64, `lw` at 0xe8c.
  5 such `sb` accesses store 1 byte to [a0+188] +0x2ab, including `sb` at 0xe7c, `sb` at 0xf7c, `sb` at 0x1030.
  The `lbu` at 0xeac loads 1 byte from [a0+188] +0xa8.
  The `lbu` at 0xf14 loads 1 byte from ret(kopt_find) +0x0.
  The `lbu` at 0xf4c loads 1 byte from ret(kopt_find) +0x1.
  3 such `lbu` accesses load 1 byte from [a0+188] +0x2ab, including `lbu` at 0xf70, `lbu` at 0x1028, `lbu` at 0x122c.
  4 such `lw` accesses load 4 bytes from [a0+188] +0x14, including `lw` at 0xfac, `lw` at 0xff8, `lw` at 0x10b4.
  3 such `sw` accesses store 4 bytes to [a0+188] +0x14, including `sw` at 0xfbc, `sw` at 0x10c8, `sw` at 0x113c.
  The `lw` at 0xfc0 loads 4 bytes from sym(me_fullduplex_ipg) +0x0.
  The `lw` at 0xfcc loads 4 bytes from sym(me_fullduplex_ipg) +0x4.
  The `lw` at 0xfd0 loads 4 bytes from sym(me_fullduplex_ipg) +0x8.
  The `sw` at 0xfec stores 4 bytes to [a0+188] +0x2a4.
  2 such `lbu` accesses load 1 byte from [a0+188] +0x2a8, including `lbu` at 0x1010, `lbu` at 0x10f8.
  The `lh` at 0x1034 loads 2 bytes from a0 (arg0 at entry) +0xe.
  The `lw` at 0x1044 loads 4 bytes from [a0+188] +0x24.
  2 such `sw` accesses store 4 bytes to [a0+188] +0x24, including `sw` at 0x1060, `sw` at 0x1258.
  2 such `sh` accesses store 2 bytes to [a0+188] +0x57c, including `sh` at 0x106c, `sh` at 0x1268.
  2 such `lh` accesses load 2 bytes from [a0+188] +0x57e, including `lh` at 0x1094, `lh` at 0x1290.
  The `lw` at 0x1140 loads 4 bytes from sym(me_halfduplex_ipg) +0x0.
  The `lw` at 0x114c loads 4 bytes from sym(me_halfduplex_ipg) +0x4.
  The `lw` at 0x1150 loads 4 bytes from sym(me_halfduplex_ipg) +0x8.
  The `lbu` at 0x1198 loads 1 byte from ret(kopt_find) +0x3.
  The `lbu` at 0x11b0 loads 1 byte from ret(kopt_find) +0x2.
  3 such `lbu` accesses load 1 byte from [a0+188] +0x580, including `lbu` at 0x11e8, `lbu` at 0x12d4, `lbu` at 0x12ec.
  The `sh` at 0x129c stores 2 bytes to [a0+188] +0x57e.
  The `jal` at 0xe5c calls pciio_pio_write32 with a0=0x1, a1=[[a0+188]+672]+4, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xe6c calls pciio_pio_write32 with a0=0x0, a1=[[a0+188]+672]+4, a2=?, a3=?.
  The `jal` at 0xe84 calls bcopy with a0=[a0+188]+168, a1=sp-94, a2=0x6, a3=?.
  The `jal` at 0xe94 calls pciio_pio_write64 with a0=0x0, a1=[[a0+188]+672]+160, a2=?, a3=?.
  The `jal` at 0xea4 calls kopt_find with a0=sym(.rodata)+632, a1=?, a2=?, a3=?.
  The `jal` at 0xed8 calls cmn_err_tag with a0=0x10e, a1=0x1, a2=sym(.rodata), a3=?.
  The `jal` at 0xef4 calls mace_ether_mdio_probe with a0=[a0+188], a1=?, a2=?, a3=?.
  The `jal` at 0xf04 calls mace_ether_mdio_errata with a0=[a0+188], a1=?, a2=?, a3=?.
  The `jal` at 0xf64 calls mace_ether_mdio_wr with a0=[a0+188], a1=0x0, a2=?, a3=?.
  The `jal` at 0xff0 calls mace_hdwrether_init with a0=[a0+188], a1=?, a2=one of 0xfffffffffffeffff, 0x10000, a3=?.
  The `jal` at 0x1008 calls printf with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jal` at 0x101c calls mace_ether_mdio_rd with a0=[a0+188], a1=0x1, a2=?, a3=?.
  The `jal` at 0x10a4 calls ps_reinit with a0=a0 at entry (arg0), a1=sp-88, a2=?, a3=?, a4=sym(me_setstate), a5=sym(me_txfree_len), a6=0x80.
  The `jal` at 0x110c calls mace_ether_mdio_wr with a0=[a0+188], a1=0x0, a2=0x1000, a3=?.
  The `jal` at 0x11f4 calls printf with a0=([[a0+188]+1408]:1 + sym(.rodata))+400, a1=sym(.rodata), a2=one of 0xa, 0x64, a3=?.
  The `jal` at 0x1220 calls mace_ether_mdio_wr with a0=[a0+188], a1=0x0, a2=0x2100, a3=?.
  The `jal` at 0x1274 calls cmn_err_tag with a0=0x10f, a1=0x1, a2=sym(.rodata), a3=?.
  The `jal` at 0x1288 calls ps_init with a0=a0 at entry (arg0), a1=sp-88, a2=?, a3=?, a4=sym(me_setstate), a5=sym(me_txfree_len), a6=0x80.
  The `jal` at 0x12dc calls printf with a0=([[a0+188]+1408]:1 + sym(.rodata))+592, a1=?, a2=?, a3=?.
  The `jal` at 0x12f4 calls printf with a0=([[a0+188]+1408]:1 + sym(.rodata))+464, a1=?, a2=?, a3=([[a0+188]+683]:1 | 0x2), a4=[sym(.sbss)+4]:1.
  The `beq` branch at 0xec0 targets 0xee8, is taken when (a1(=[[a0+188]+168]:1) & 0x1) == 0, and falls through when (a1(=[[a0+188]+168]:1) & 0x1) != 0.
  The `beq` branch at 0xee0 targets 0xef4 and is always taken.
  The `bltz` branch at 0xefc targets 0x126c, is taken when v0(=ret(mace_ether_mdio_probe)) < 0 (signed), and falls through when v0(=ret(mace_ether_mdio_probe)) >= 0 (signed).
  The `beq` branch at 0xf0c targets 0x10f8, is taken when s2(=ret(kopt_find)) == 0, and falls through when s2(=ret(kopt_find)) != 0.
  The `beq` branch at 0xf18 targets 0x10f8, is taken when v0(=[ret(kopt_find)]:1) == 0, and falls through when v0(=[ret(kopt_find)]:1) != 0.
  The `beq` branch at 0xf20 targets 0x1174, is taken when v0(=[ret(kopt_find)]:1) == t8(=0x74), and falls through when v0(=[ret(kopt_find)]:1) != t8(=0x74).
  The `beq` branch at 0xf2c targets 0x1174, is taken when v0(=[ret(kopt_find)]:1) == t9(=0x54), and falls through when v0(=[ret(kopt_find)]:1) != t9(=0x54).
  The `beq` branch at 0xf38 targets 0x118c, is taken when v0(=[ret(kopt_find)]:1) == ra(=0x66), and falls through when v0(=[ret(kopt_find)]:1) != ra(=0x66).
  The `beq` branch at 0xf40 targets 0x118c, is taken when v0(=[ret(kopt_find)]:1) == at(=0x46), and falls through when v0(=[ret(kopt_find)]:1) != at(=0x46).
  The `beq` branch at 0xf54 targets 0x1198, is taken when a0(=0x31) == v1(=[ret(kopt_find)+1]:1), and falls through when a0(=0x31) != v1(=[ret(kopt_find)+1]:1).
  The `beq` branch at 0xf5c targets 0x11b0, is taken when a0(=0x31) == v0(=[ret(kopt_find)]:1), and falls through when a0(=0x31) != v0(=[ret(kopt_find)]:1).
  The `beq` branch at 0xf78 targets 0x11cc, is taken when a1(=[sym(.sbss)+4]:1) == 0, and falls through when a1(=[sym(.sbss)+4]:1) != 0.
  The `beq` branch at 0xf84 targets 0xf94, is taken when (s3(=a1) & 0x100) == 0, and falls through when (s3(=a1) & 0x100) != 0.
  The `beq` branch at 0xf94 targets 0xfa4, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0xfa4 targets 0x112c, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0xfc4 targets 0x117c, is taken when v0(=[sym(me_fullduplex_ipg)]) == 0, and falls through when v0(=[sym(me_fullduplex_ipg)]) != 0.
  The `beq` branch at 0x1000 targets 0x1010, is taken when (t9(=[[a0+188]+20]) & 0x4) == 0, and falls through when (t9(=[[a0+188]+20]) & 0x4) != 0.
  The `beq` branch at 0x1014 targets 0x1024, is taken when ra(=[[a0+188]+680]:1) == 0, and falls through when ra(=[[a0+188]+680]:1) != 0.
  The `bne` branch at 0x1024 targets 0x10b4, is taken when s5(=one of 0x0, 0x1, 0x2) != 0, and falls through when s5(=one of 0x0, 0x1, 0x2) == 0.
  The `beq` branch at 0x103c targets 0x12d4, is taken when at(=[a0+14]:2) == v1(=-0x1), and falls through when at(=[a0+14]:2) != v1(=-0x1).
  The `beq` branch at 0x104c targets 0x124c, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x109c targets 0x1284, is taken when (a3(=[[a0+188]+1406]:2) & 0x20) == 0, and falls through when (a3(=[[a0+188]+1406]:2) & 0x20) != 0.
  The `beq` branch at 0x10ac targets 0x10d0 and is always taken.
  The `beq` branch at 0x10fc targets 0x1218, is taken when t2(=[[a0+188]+680]:1) == 0, and falls through when t2(=[[a0+188]+680]:1) != 0.
  The `beq` branch at 0x1114 targets 0x1208, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `beq` branch at 0x111c targets 0xf8c and is always taken.
  The `beq` branch at 0x1144 targets 0x12a0, is taken when v0(=[sym(me_halfduplex_ipg)]) == 0, and falls through when v0(=[sym(me_halfduplex_ipg)]) != 0.
  The `beq` branch at 0x1168 targets 0xfec and is always taken.
  The `beq` branch at 0x1174 targets 0xf4c and is always taken.
  The `beq` branch at 0x1184 targets 0xfec and is always taken.
  The `beq` branch at 0x1190 targets 0xf4c and is always taken.
  The `bne` branch at 0x11a0 targets 0xf5c, is taken when ra(=[ret(kopt_find)+3]:1) != at(=0x30), and falls through when ra(=[ret(kopt_find)+3]:1) == at(=0x30).
  The `beq` branch at 0x11a8 targets 0x11c4 and is always taken.
  The `bne` branch at 0x11b8 targets 0xf64, is taken when v0(=[ret(kopt_find)+2]:1) != v1(=0x30), and falls through when v0(=[ret(kopt_find)+2]:1) == v1(=0x30).
  The `beq` branch at 0x11c4 targets 0xf60 and is always taken.
  The `beq` branch at 0x11d4 targets 0x12b0, is taken when (s1(?) & 0x8) == 0, and falls through when (s1(?) & 0x8) != 0.
  The `beq` branch at 0x11e0 targets 0x12b8, is taken when (s1(?) & 0x2) == 0, and falls through when (s1(?) & 0x2) != 0.
  The `beq` branch at 0x1200 targets 0xf80 and is always taken.
  The `beq` branch at 0x1208 targets 0x1124, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0x1210 targets 0xfa0 and is always taken.
  The `beq` branch at 0x1234 targets 0x12ec, is taken when a4(=[sym(.sbss)+4]:1) == 0, and falls through when a4(=[sym(.sbss)+4]:1) != 0.
  The `beq` branch at 0x123c targets 0x12c4, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `beq` branch at 0x1244 targets 0xf8c and is always taken.
  The `beq` branch at 0x1264 targets 0x1070 and is always taken.
  The `beq` branch at 0x127c targets 0xf04 and is always taken.
  The `beq` branch at 0x1298 targets 0x10cc and is always taken.
  The `beq` branch at 0x12a8 targets 0xfec and is always taken.
  The `beq` branch at 0x12b0 targets 0x11dc and is always taken.
  The `beq` branch at 0x12bc targets 0x11e8 and is always taken.
  The `beq` branch at 0x12c4 targets 0x1308, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0x12cc targets 0xf9c and is always taken.
  The `beq` branch at 0x12e4 targets 0x10d0 and is always taken.
  The `beq` branch at 0x1300 targets 0x123c and is always taken.
  The `beq` branch at 0x1308 targets 0x1128 and is always taken.
  The return at 0x10f0 has v0 = 0x0.
  The instructions from 0x1170 to 0x1170 are not reached by any path from the entry, and their branches are not listed.

- `mace_ether_rx_fifo_error` in `IP32/usr/cpu/sysgen/IP32boot/if_me.o` at 0x1310 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/if_me.o`.
  Range: 0x1310-0x13dc (204 bytes).
  It occupies 204 bytes.
  The `lw` at 0x1330 loads 4 bytes from a0 (arg0 at entry) +0x14.
  The `lbu` at 0x1340 loads 1 byte from a0 (arg0 at entry) +0x580.
  The `lh` at 0x1358 loads 2 bytes from a0 (arg0 at entry) +0x4bc.
  The `lw` at 0x1364 loads 4 bytes from a0 (arg0 at entry) +0x2a0.
  The `sh` at 0x1378 stores 2 bytes to a0 (arg0 at entry) +0x4bc.
  The `lw` at 0x137c loads 4 bytes from a0 (arg0 at entry) +0x534.
  The `lw` at 0x1380 loads 4 bytes from a0 (arg0 at entry) +0x2c.
  The `sw` at 0x1388 stores 4 bytes to a0 (arg0 at entry) +0x534.
  The `sw` at 0x1390 stores 4 bytes to a0 (arg0 at entry) +0x2c.
  The `lw` at 0x13bc loads 4 bytes from a0 (arg0 at entry) +0x530.
  The `sw` at 0x13cc stores 4 bytes to a0 (arg0 at entry) +0x530.
  The `jal` at 0x1350 calls printf with a0=([a0+1408]:1 + sym(.rodata))+640, a1=sym(.rodata), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1374 calls pciio_pio_write32 with a0=?, a1=[a0+672]+28, a2=?, a3=[a0+1212]:2.
  The `jal` at 0x13ac calls cmn_err_tag with a0=0x110, a1=0x1, a2=sym(.rodata), a3=?, a4=sym(.rodata).
  The `jal` at 0x13b4 calls mace_hdwrether_init with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `beq` branch at 0x1328 targets 0x1394, is taken when (a1 & 0x40) == 0, and falls through when (a1 & 0x40) != 0.
  The `beq` branch at 0x1338 targets 0x1358, is taken when (v0(=[a0+20]) & 0x4) == 0, and falls through when (v0(=[a0+20]) & 0x4) != 0.
  The `blez` branch at 0x135c targets 0x137c, is taken when a3(=[a0+1212]:2) <= 0 (signed), and falls through when a3(=[a0+1212]:2) > 0 (signed).
  The `beq` branch at 0x139c targets 0x13bc, is taken when (s8(=a1) & 0x80) == 0, and falls through when (s8(=a1) & 0x80) != 0.
  The return at 0x13d4 has v0 = one of ?, ret(mace_hdwrether_init).

- `mace_ether_tx_emsg` in `IP32/usr/cpu/sysgen/IP32boot/if_me.o` at 0x13dc (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/if_me.o`.
  Range: 0x13dc-0x1444 (104 bytes).
  It occupies 104 bytes.
  The `bgez` branch at 0x13e0 targets 0x13f4, is taken when at(=(a0 << 0x26)) >= 0 (signed), and falls through when at(=(a0 << 0x26)) < 0 (signed).
  The `bltz` branch at 0x1404 targets 0x13ec, is taken when v1(=(a0 << 0x27)) < 0 (signed), and falls through when v1(=(a0 << 0x27)) >= 0 (signed).
  The `bltz` branch at 0x140c targets 0x13ec, is taken when a3(=(a0 << 0x25)) < 0 (signed), and falls through when a3(=(a0 << 0x25)) >= 0 (signed).
  The `bltz` branch at 0x141c targets 0x13ec, is taken when v1(=(a0 << 0x24)) < 0 (signed), and falls through when v1(=(a0 << 0x24)) >= 0 (signed).
  The `bgez` branch at 0x1428 targets 0x143c, is taken when a1(=(a0 << 0x23)) >= 0 (signed), and falls through when a1(=(a0 << 0x23)) < 0 (signed).
  The return at 0x13ec has v0 = one of sym(.rodata)+720, sym(.rodata)+736, sym(.rodata)+752, sym(.rodata)+776.
  The return at 0x1434 has v0 = sym(.rodata)+800.
  The return at 0x143c has v0 = sym(.rodata)+816.

- `mace_ether_tx_purge` in `IP32/usr/cpu/sysgen/IP32boot/if_me.o` at 0x1444 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/if_me.o`.
  Range: 0x1444-0x14e4 (160 bytes).
  It occupies 160 bytes.
  4 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x2a0, including `lw` at 0x1450, `lw` at 0x1464, `lw` at 0x14a0.
  The `lw` at 0x1488 loads 4 bytes from ?.
  The `sw` at 0x149c stores 4 bytes to ?.
  The `sh` at 0x14bc stores 2 bytes to a0 (arg0 at entry) +0x2b0.
  The `sh` at 0x14c0 stores 2 bytes to a0 (arg0 at entry) +0x2b2.
  The `sw` at 0x14d4 stores 4 bytes to a0 (arg0 at entry) +0x2b4.
  The `jal` at 0x1458 calls pciio_pio_read32 with a0=[a0+672]+20, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1474 calls pciio_pio_write32 with a0=?, a1=[a0+672]+20, a2=?, a3=?.
  The `jal` at 0x1484 calls m_freem with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x14a4 calls pciio_pio_read16 with a0=[a0+672]+52, a1=?, a2=?, a3=?.
  The `jal` at 0x14c4 calls pciio_pio_write16 with a0=?, a1=[a0+672]+54, a2=?, a3=?.
  The `bne` branch at 0x1498 targets 0x1484, is taken when s1(?) < 0x80 (signed), and falls through when s1(?) >= 0x80 (signed).
  The return at 0x14dc has v0 = ret(pciio_pio_write16).

- `mace_ether_tx_error` in `IP32/usr/cpu/sysgen/IP32boot/if_me.o` at 0x14e4 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/if_me.o`.
  Range: 0x14e4-0x1638 (340 bytes).
  It occupies 340 bytes.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x2a0, including `lw` at 0x14f0, `lw` at 0x15f8, `lw` at 0x1604.
  2 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x2ab, including `lbu` at 0x1518, `lbu` at 0x1564.
  The `sb` at 0x157c stores 1 byte to a0 (arg0 at entry) +0x2ab.
  The `lw` at 0x158c loads 4 bytes from a0 (arg0 at entry) +0x14.
  The `lbu` at 0x15a8 loads 1 byte from a0 (arg0 at entry) +0x580.
  The `lbu` at 0x15cc loads 1 byte from a0 (arg0 at entry) +0x2a8.
  The `lw` at 0x1618 loads 4 bytes from a0 (arg0 at entry) +0x52c.
  The `sw` at 0x1628 stores 4 bytes to a0 (arg0 at entry) +0x52c.
  The `jal` at 0x1500 calls pciio_pio_read64 with a0=[a0+672]+88, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1534 calls cmn_err_tag with a0=0x111, a1=0x1, a2=sym(.rodata), a3=?.
  The `jal` at 0x153c calls mace_ether_tx_purge with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x155c calls cmn_err_tag with a0=0x112, a1=0x1, a2=sym(.rodata), a3=?.
  The `jal` at 0x1578 calls mace_ether_tx_purge with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x15a0 calls mace_ether_tx_emsg with a0=(ret(pciio_pio_read64) << 0x0), a1=?, a2=?, a3=?.
  The `jal` at 0x15b8 calls printf with a0=([a0+1408]:1 + sym(.rodata))+896, a1=ret(mace_ether_tx_emsg), a2=(ret(pciio_pio_read64) << 0x0), a3=?.
  The `jal` at 0x15c4 calls mace_ether_transmit_stats with a0=a0 at entry (arg0), a1=(ret(pciio_pio_read64) << 0x0), a2=?, a3=?.
  The `jal` at 0x15dc calls mace_ether_reset with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x15e8 calls mace_ether_init with a0=a0 at entry (arg0), a1=0x0, a2=?, a3=?.
  The `jal` at 0x15fc calls pciio_pio_read32 with a0=[a0+672]+20, a1=?, a2=?, a3=?.
  The `jal` at 0x160c calls pciio_pio_write32 with a0=(ret(pciio_pio_read32) | 0x2), a1=[a0+672]+20, a2=?, a3=?.
  The `beq` branch at 0x1510 targets 0x1544, is taken when (s1(=a1) & 0x4) == 0, and falls through when (s1(=a1) & 0x4) != 0.
  The `beq` branch at 0x1520 targets 0x1544, is taken when (a2(=[a0+683]:1) & 0x8) == 0, and falls through when (a2(=[a0+683]:1) & 0x8) != 0.
  The `beq` branch at 0x154c targets 0x1580, is taken when (s1(=a1) & 0x8) == 0, and falls through when (s1(=a1) & 0x8) != 0.
  The `beq` branch at 0x1584 targets 0x1614, is taken when (s1(=a1) & 0x10) == 0, and falls through when (s1(=a1) & 0x10) != 0.
  The `beq` branch at 0x1598 targets 0x15c4, is taken when (t8(=[a0+20]) & 0x4) == 0, and falls through when (t8(=[a0+20]) & 0x4) != 0.
  The `beq` branch at 0x15d4 targets 0x15f8, is taken when a1(=[a0+680]:1) >= 0x2 (signed), and falls through when a1(=[a0+680]:1) < 0x2 (signed).
  The `beq` branch at 0x15f0 targets 0x1618 and is always taken.
  The return at 0x1630 has v0 = one of ret(mace_ether_init), ?.

- `mace_ether_reset` in `IP32/usr/cpu/sysgen/IP32boot/if_me.o` at 0x1638 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/if_me.o`.
  Range: 0x1638-0x16d0 (152 bytes).
  It occupies 152 bytes.
  The `lw` at 0x1640 loads 4 bytes from a0 (arg0 at entry) +0xbc.
  3 such `lw` accesses load 4 bytes from [a0+188] +0x2a0, including `lw` at 0x1644, `lw` at 0x1658, `lw` at 0x16a8.
  The `sb` at 0x1670 stores 1 byte to [a0+188] +0x2ab.
  The `sh` at 0x1674 stores 2 bytes to [a0+188] +0x10.
  The `sh` at 0x1678 stores 2 bytes to [a0+188] +0x4e4.
  The `lw` at 0x1688 loads 4 bytes from ?.
  The `sw` at 0x169c stores 4 bytes to ?.
  The `jal` at 0x1650 calls pciio_pio_write32 with a0=0x1, a1=[[a0+188]+672]+4, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1668 calls pciio_pio_write32 with a0=0x0, a1=[[a0+188]+672]+4, a2=?, a3=?.
  The `jal` at 0x1684 calls m_freem with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x16a0 calls mace_ether_tx_purge with a0=[a0+188], a1=?, a2=?, a3=?.
  The `jal` at 0x16b8 calls pciio_pio_write64 with a0=0x80000, a1=[[a0+188]+672]+88, a2=?, a3=?.
  The `bne` branch at 0x1698 targets 0x1684, is taken when s1(?) < 0x10 (signed), and falls through when s1(?) >= 0x10 (signed).
  The return at 0x16c8 has v0 = ret(pciio_pio_write64).

- `mace_ether_watchdog` in `IP32/usr/cpu/sysgen/IP32boot/if_me.o` at 0x16d0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/if_me.o`.
  Range: 0x16d0-0x1924 (596 bytes).
  It occupies 596 bytes.
  5 such `lw` accesses load 4 bytes from sym(.bss) +0x2a0, including `lw` at 0x16ec, `lw` at 0x1714, `lw` at 0x1744.
  9 such `lbu` accesses load 1 byte from sym(.bss) +0x2ab, including `lbu` at 0x1704, `lbu` at 0x1738, `lbu` at 0x1798.
  The `lbu` at 0x172c loads 1 byte from sym(.bss) +0x2a8.
  The `lh` at 0x174c loads 2 bytes from sym(.bss) +0x4bc.
  The `sh` at 0x1764 stores 2 bytes to sym(.bss) +0x10.
  The `sh` at 0x1788 stores 2 bytes to sym(.bss) +0x4bc.
  8 such `sb` accesses store 1 byte to sym(.bss) +0x2ab, including `sb` at 0x17a8, `sb` at 0x17dc, `sb` at 0x17fc.
  The `lb` at 0x1800 loads 1 byte from sym(.bss) +0x2a9.
  2 such `lw` accesses load 4 bytes from sym(.bss) +0x2ac, including `lw` at 0x1840, `lw` at 0x1864.
  The `lw` at 0x1880 loads 4 bytes from sym(.bss) +0x2a4.
  The `jal` at 0x16e4 calls mace_ether_transmit_complete with a0=sym(.bss), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x16f0 calls pciio_pio_read8 with a0=[sym(.bss)+672]+70, a1=?, a2=?, a3=?.
  The `jal` at 0x16fc calls mace_ether_receive with a0=sym(.bss), a1=ret(pciio_pio_read8), a2=?, a3=?.
  The `jal` at 0x1718 calls pciio_pio_read32 with a0=[sym(.bss)+672]+100, a1=?, a2=?, a3=?.
  The `jal` at 0x1784 calls pciio_pio_write32 with a0=?, a1=[sym(.bss)+672]+28, a2=?, a3=?, a4=[sym(.bss)+1212]:2.
  The `jal` at 0x17b0 calls mace_ether_link_update with a0=sym(.bss), a1=ret(pciio_pio_read32), a2=-0x5, a3=?.
  The `jal` at 0x180c calls pciio_pio_write32 with a0=(([sym(.bss)+681]:1 << 0x5) | 0x1), a1=[sym(.bss)+672]+108, a2=[sym(.bss)+680]:1, a3=?.
  The `jal` at 0x181c calls pciio_pio_write32 with a0=0x1, a1=[sym(.bss)+672]+116, a2=?, a3=?.
  The `jal` at 0x1848 calls mace_ether_tx_error with a0=sym(.bss), a1=0x4, a2=-0x5, a3=?, a5=[sym(.bss)+684].
  The `jal` at 0x18e4 calls mace_ether_mdio_rmw with a0=sym(.bss), a1=0x1f, a2=0x1, a3=?, a5=[sym(.bss)+684], a6=0x181440.
  The `jal` at 0x18f8 calls cmn_err_tag with a0=0x114, a1=0x1, a2=sym(.rodata), a3=?, a5=sym(.rodata).
  The `jal` at 0x1914 calls cmn_err_tag with a0=0x113, a1=0x1, a2=sym(.rodata), a3=?, a4=0x6, a5=sym(.rodata).
  The `beq` branch at 0x170c targets 0x172c, is taken when (a1(=[sym(.bss)+683]:1) & 0x4) == 0, and falls through when (a1(=[sym(.bss)+683]:1) & 0x4) != 0.
  The `bgez` branch at 0x1724 targets 0x1794, is taken when a1(=(ret(pciio_pio_read32) << 0x2f)) >= 0 (signed), and falls through when a1(=(ret(pciio_pio_read32) << 0x2f)) < 0 (signed).
  The `blez` branch at 0x1730 targets 0x1748, is taken when a2(=[sym(.bss)+680]:1) <= 0 (signed), and falls through when a2(=[sym(.bss)+680]:1) > 0 (signed).
  The `beq` branch at 0x1740 targets 0x1800, is taken when v0(=0x1) == a3(?), and falls through when v0(=0x1) != a3(?).
  The `bne` branch at 0x1754 targets 0x1774, is taken when a4(=[sym(.bss)+1212]:2) < a5(=[sym(me_rxdelay)]) (signed), and falls through when a4(=[sym(.bss)+1212]:2) >= a5(=[sym(me_rxdelay)]) (signed).
  The `beq` branch at 0x178c targets 0x175c and is always taken.
  The `beq` branch at 0x17a4 targets 0x1838, is taken when (v0(=ret(pciio_pio_read32)) & 0x4) == 0, and falls through when (v0(=ret(pciio_pio_read32)) & 0x4) != 0.
  The `beq` branch at 0x17b8 targets 0x18c0, is taken when v0(=ret(mace_ether_link_update)) == 0, and falls through when v0(=ret(mace_ether_link_update)) != 0.
  The `beq` branch at 0x17cc targets 0x1880, is taken when a3(?) == a4(=0x6), and falls through when a3(?) != a4(=0x6).
  The `beq` branch at 0x17e4 targets 0x18b0, is taken when (s1(=ret(pciio_pio_read32)) & 0x10) == 0, and falls through when (s1(=ret(pciio_pio_read32)) & 0x10) != 0.
  The `beq` branch at 0x17ec targets 0x18f4, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x17f8 targets 0x172c and is always taken.
  The `beq` branch at 0x1830 targets 0x1748 and is always taken.
  The `beq` branch at 0x183c targets 0x1868, is taken when (a0(?) & 0x8) == 0, and falls through when (a0(?) & 0x8) != 0.
  The `beq` branch at 0x1870 targets 0x18d4, is taken when a5(=[sym(.bss)+684]) == a6(=0x181440), and falls through when a5(=[sym(.bss)+684]) != a6(=0x181440).
  The `beq` branch at 0x1878 targets 0x17c0 and is always taken.
  The `bne` branch at 0x1888 targets 0x17d8, is taken when (a7(=[sym(.bss)+676]) & 0x8) != 0, and falls through when (a7(=[sym(.bss)+676]) & 0x8) == 0.
  The `beq` branch at 0x1894 targets 0x1908, is taken when (a0(?) & 0x40) == 0, and falls through when (a0(?) & 0x40) != 0.
  The `beq` branch at 0x18a8 targets 0x17e0 and is always taken.
  The `beq` branch at 0x18b8 targets 0x172c and is always taken.
  The `beq` branch at 0x18cc targets 0x17c0 and is always taken.
  The `beq` branch at 0x18ec targets 0x1878 and is always taken.
  The `beq` branch at 0x1900 targets 0x17f4 and is always taken.
  The `beq` branch at 0x191c targets 0x189c and is always taken.
  The return at 0x176c has v0 = 0x1.

- `mace_ether_timer` in `IP32/usr/cpu/sysgen/IP32boot/if_me.o` at 0x1924 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/if_me.o`.
  Range: 0x1924-0x19f8 (212 bytes).
  It occupies 212 bytes.
  The `lbu` at 0x194c loads 1 byte from a0 (arg0 at entry) +0x2ab.
  The `lw` at 0x195c loads 4 bytes from a0 (arg0 at entry) +0x2b4.
  The `lh` at 0x1968 loads 2 bytes from a0 (arg0 at entry) +0x4be.
  The `sh` at 0x1980 stores 2 bytes to a0 (arg0 at entry) +0x4be.
  The `lw` at 0x1984 loads 4 bytes from a0 (arg0 at entry) +0x14.
  The `lbu` at 0x1994 loads 1 byte from a0 (arg0 at entry) +0x580.
  The `lw` at 0x19a8 loads 4 bytes from a0 (arg0 at entry) +0x4c0.
  The `sw` at 0x19b8 stores 4 bytes to a0 (arg0 at entry) +0x4c0.
  The `jal` at 0x193c calls mutex_lock with a0=a0+152, a1=0x19, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1944 calls mace_ether_transmit_complete with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x19a0 calls printf with a0=([a0+1408]:1 + sym(.rodata)+984), a1=sym(.rodata)+984, a2=0x14, a3=?.
  The `jal` at 0x19b4 calls mace_ether_reset with a0=a0 at entry (arg0), a1=?, a2=[a0+1216]+1, a3=?.
  The `jal` at 0x19c0 calls mace_ether_init with a0=a0 at entry (arg0), a1=0x0, a2=?, a3=?.
  The `jal` at 0x19d8 calls itimeout with a0=sym(mace_ether_timer), a1=a0 at entry (arg0), a2=0x14, a3=[sym(plbase)].
  The `jal` at 0x19e4 calls mutex_unlock with a0=a0+152, a1=?, a2=?, a3=?.
  The `beq` branch at 0x1954 targets 0x19c8, is taken when (at(=[a0+683]:1) & 0x8) == 0, and falls through when (at(=[a0+683]:1) & 0x8) != 0.
  The `beq` branch at 0x1960 targets 0x19cc, is taken when v0(=[a0+692]) == v1(=0x80), and falls through when v0(=[a0+692]) != v1(=0x80).
  The `bne` branch at 0x197c targets 0x19c8, is taken when a0(?) < 0x3 (signed), and falls through when a0(?) >= 0x3 (signed).
  The `beq` branch at 0x198c targets 0x19a8, is taken when (a1(=[a0+20]) & 0x4) == 0, and falls through when (a1(=[a0+20]) & 0x4) != 0.
  The return at 0x19f0 has v0 = ret(mutex_unlock).

- `mace_ether_getisr` in `IP32/usr/cpu/sysgen/IP32boot/if_me.o` at 0x19f8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/if_me.o`.
  Range: 0x19f8-0x1ad4 (220 bytes).
  It occupies 220 bytes.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x2a0, including `lw` at 0x1a0c, `lw` at 0x1a70, `lw` at 0x1ad0.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x14, including `lw` at 0x1a3c, `lw` at 0x1a94.
  The `lbu` at 0x1a4c loads 1 byte from a0 (arg0 at entry) +0x580.
  The `lw` at 0x1a60 loads 4 bytes from a0 (arg0 at entry) +0x53c.
  The `sw` at 0x1a6c stores 4 bytes to a0 (arg0 at entry) +0x53c.
  The `lw` at 0x1ab4 loads 4 bytes from a0 (arg0 at entry) +0x538.
  The `sw` at 0x1ac8 stores 4 bytes to a0 (arg0 at entry) +0x538.
  The `jal` at 0x1a18 calls pciio_pio_read64 with a0=[a0+672]+8, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1a58 calls printf with a0=([a0+1408]:1 + sym(.rodata))+1024, a1=ret(pciio_pio_read64), a2=?, a3=?.
  The `jal` at 0x1a68 calls wbflush with a0=?, a1=[a0+1340]+1, a2=?, a3=?.
  The `jal` at 0x1a74 calls pciio_pio_read64 with a0=[a0+672]+8, a1=?, a2=?, a3=?.
  The `jal` at 0x1ac4 calls wbflush with a0=?, a1=ret(pciio_pio_read64), a2=[a0+1336]+1, a3=?.
  The `beq` branch at 0x1a34 targets 0x1a70 and is always taken.
  The `beq` branch at 0x1a44 targets 0x1a60, is taken when (t8(=[a0+20]) & 0x4) == 0, and falls through when (t8(=[a0+20]) & 0x4) != 0.
  The `bne` branch at 0x1a7c targets 0x1ab4, is taken when v0(=ret(pciio_pio_read64)) != s1(=ret(pciio_pio_read64)), and falls through when v0(=ret(pciio_pio_read64)) == s1(=ret(pciio_pio_read64)).
  The `bne` branch at 0x1a88 targets 0x1a3c, is taken when a1(=ret(pciio_pio_read64)) != 0, and falls through when a1(=ret(pciio_pio_read64)) == 0.
  The `bnel` branch at 0x1a90 targets 0x1a40, is taken when a1(?) != 0, and falls through when a1(?) == 0; its branch-likely delay slot `lw t8,20(s0)` at 0x1a94 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x1acc targets 0x1a74 and is always taken.
  The return at 0x1aac has v0 = ?.

- `mace_ether_intr` in `IP32/usr/cpu/sysgen/IP32boot/if_me.o` at 0x1ad4 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/if_me.o`.
  Range: 0x1ad4-0x1c8c (440 bytes).
  It occupies 440 bytes.
  The `lw` at 0x1afc loads 4 bytes from sym(.bss) +0x594.
  2 such `sw` accesses store 4 bytes to sym(.bss) +0x594, including `sw` at 0x1b10, `sw` at 0x1c64.
  2 such `sw` accesses store 4 bytes to sym(.bss) +0x584, including `sw` at 0x1b18, `sw` at 0x1c40.
  The `lw` at 0x1b1c loads 4 bytes from sym(.bss) +0x578.
  The `sw` at 0x1b20 stores 4 bytes to sym(.bss) +0x588.
  2 such `lh` accesses load 2 bytes from sym(.bss) +0x2b0, including `lh` at 0x1b40, `lh` at 0x1bec.
  5 such `lw` accesses load 4 bytes from sym(.bss) +0x2a0, including `lw` at 0x1b58, `lw` at 0x1b7c, `lw` at 0x1ba0.
  The `lh` at 0x1b8c loads 2 bytes from sym(.bss) +0x57e.
  The `lw` at 0x1bac loads 4 bytes from sym(.bss) +0x2b4.
  2 such `lh` accesses load 2 bytes from sym(.bss) +0x4e4, including `lh` at 0x1bfc, `lh` at 0x1c38.
  The `jal` at 0x1af4 calls mutex_lock with a0=sym(.bss), a1=0x19, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1b24 calls mace_ether_getisr with a0=sym(.bss), a1=?, a2=?, a3=?.
  The `jal` at 0x1b50 calls mace_ether_rx_fifo_error with a0=sym(.bss), a1=?, a2=?, a3=?.
  The `jal` at 0x1b60 calls pciio_pio_write32 with a0=0xc0, a1=[sym(.bss)+672]+12, a2=?, a3=?.
  The `jal` at 0x1b74 calls mace_ether_tx_error with a0=sym(.bss), a1=?, a2=?, a3=?.
  The `jal` at 0x1b84 calls pciio_pio_write32 with a0=0x1c, a1=[sym(.bss)+672]+12, a2=?, a3=?.
  The `jal` at 0x1ba8 calls ps_txq_stat with a0=sym(.bss), a1=[sym(.bss)+692], a2=?, a3=?.
  The `jal` at 0x1bb8 calls pciio_pio_write32 with a0=0x2, a1=[sym(.bss)+672]+12, a2=?, a3=?.
  The `jal` at 0x1bd0 calls pciio_pio_write32 with a0=0x0, a1=[sym(.bss)+672]+36, a2=?, a3=?.
  The `jal` at 0x1bd8 calls mace_ether_getisr with a0=sym(.bss), a1=?, a2=?, a3=?.
  The `jal` at 0x1c10 calls mace_ether_receive with a0=sym(.bss), a1=?, a2=?, a3=?, a5=[sym(.bss)+1252]:2.
  The `jal` at 0x1c2c calls mace_ether_transmit_complete with a0=sym(.bss), a1=?, a2=?, a3=[sym(.bss)+688]:2, a5=[sym(.bss)+1252]:2.
  The `jal` at 0x1c44 calls mutex_unlock with a0=sym(.bss), a1=?, a2=?, a3=?.
  The `jal` at 0x1c60 calls absolute_rtc_current_time with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1c7c calls randproc_input with a0=?, a1=0x500000000, a2=?, a3=?.
  The `beq` branch at 0x1b0c targets 0x1c60, is taken when t9(=[sym(.bss)+1428]+1) >= 0x63 (unsigned), and falls through when t9(=[sym(.bss)+1428]+1) < 0x63 (unsigned).
  The `beq` branch at 0x1b34 targets 0x1c3c, is taken when (v0(=ret(mace_ether_getisr)) & 0xff) == 0, and falls through when (v0(=ret(mace_ether_getisr)) & 0xff) != 0.
  The `beq` branch at 0x1b3c targets 0x1bf0 and is always taken.
  The `beq` branch at 0x1b48 targets 0x1b68, is taken when v1(?) == 0, and falls through when v1(?) != 0.
  The `beq` branch at 0x1b6c targets 0x1b8c, is taken when (s1(=ret(mace_ether_getisr)) & 0x1c) == 0, and falls through when (s1(=ret(mace_ether_getisr)) & 0x1c) != 0.
  The `beq` branch at 0x1b94 targets 0x1bc0, is taken when (s1(=ret(mace_ether_getisr)) & 0x2) == 0, and falls through when (s1(=ret(mace_ether_getisr)) & 0x2) != 0.
  The `beq` branch at 0x1b9c targets 0x1bb4, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x1bc4 targets 0x1bd8, is taken when (s1(=ret(mace_ether_getisr)) & 0x1) == 0, and falls through when (s1(=ret(mace_ether_getisr)) & 0x1) != 0.
  The `beq` branch at 0x1be4 targets 0x1c3c, is taken when (v0(=ret(mace_ether_getisr)) & 0xff) == 0, and falls through when (v0(=ret(mace_ether_getisr)) & 0xff) != 0.
  The `bne` branch at 0x1bf8 targets 0x1c2c, is taken when a3(=[sym(.bss)+688]:2) != a4(?), and falls through when a3(=[sym(.bss)+688]:2) == a4(?).
  The `beq` branch at 0x1c08 targets 0x1b48, is taken when a5(=[sym(.bss)+1252]:2) == a1(?), and falls through when a5(=[sym(.bss)+1252]:2) != a1(?).
  The `bne` branch at 0x1c1c targets 0x1bd8, is taken when 0 < v0(=ret(mace_ether_receive)) (unsigned), and falls through when 0 >= v0(=ret(mace_ether_receive)) (unsigned).
  The `beq` branch at 0x1c24 targets 0x1b48 and is always taken.
  The `beq` branch at 0x1c34 targets 0x1c00 and is always taken.
  The `beq` branch at 0x1c84 targets 0x1b18 and is always taken.
  The return at 0x1c58 has v0 = ret(mutex_unlock).
  The instructions from 0x1b44 to 0x1b44 are not reached by any path from the entry, and their branches are not listed.

- `mace_ether_hdwrcksum` in `IP32/usr/cpu/sysgen/IP32boot/if_me.o` at 0x1c8c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/if_me.o`.
  Range: 0x1c8c-0x1e18 (396 bytes).
  It occupies 396 bytes.
  The `lw` at 0x1c8c loads 4 bytes from a1 (arg1 at entry) +0x4.
  The `lhu` at 0x1c94 loads 2 bytes from ([a1+4] + a1) +0x26.
  The `lhu` at 0x1ca4 loads 2 bytes from ([a1+4] + a1) +0x2e.
  The `lbu` at 0x1cb4 loads 1 byte from ([a1+4] + a1) +0x31.
  The `lhu` at 0x1cdc loads 2 bytes from ([a1+4] + a1) +0x1e.
  The `lhu` at 0x1ce0 loads 2 bytes from ([a1+4] + a1) +0x20.
  The `lbu` at 0x1ce4 loads 1 byte from ([a1+4] + a1) +0x28.
  The `lw` at 0x1ce8 loads 4 bytes from ([a1+4] + a1) +0x34.
  The `lhu` at 0x1cec loads 2 bytes from ([a1+4] + a1) +0x2a.
  The `lhu` at 0x1cf4 loads 2 bytes from ([a1+4] + a1) +0x1c.
  The `lhu` at 0x1d04 loads 2 bytes from ([a1+4] + a1) +0x1a.
  The `lhu` at 0x1d0c loads 2 bytes from ([a1+4] + a1) +0x22.
  The `lhu` at 0x1d18 loads 2 bytes from ([a1+4] + a1) +0x24.
  The `lw` at 0x1d28 loads 4 bytes from ([a1+4] + a1) +0x38.
  The `lbu` at 0x1d54 loads 1 byte from (a2 + ([a1+4] + a1)) +0x18.
  The `lbu` at 0x1d60 loads 1 byte from (a2 + ([a1+4] + a1)) +0x17.
  The `lbu` at 0x1d70 loads 1 byte from (a2 + ([a1+4] + a1)) +0x16.
  The `lbu` at 0x1d78 loads 1 byte from (a2 + ([a1+4] + a1)) +0x19.
  The `lbu` at 0x1dd0 loads 1 byte from a1 (arg1 at entry) +0xe.
  The `sb` at 0x1dd8 stores 1 byte to a1 (arg1 at entry) +0xe.
  The `lw` at 0x1ddc loads 4 bytes from a0 (arg0 at entry) +0x568.
  The `sw` at 0x1de8 stores 4 bytes to a0 (arg0 at entry) +0x568.
  The `bne` branch at 0x1c9c targets 0x1cd4, is taken when a6(=[([a1+4] + a1)+38]:2) != at(=0x800), and falls through when a6(=[([a1+4] + a1)+38]:2) == at(=0x800).
  The `bne` branch at 0x1cac targets 0x1cd4, is taken when (a7(=[([a1+4] + a1)+46]:2) & 0x3fff) != 0, and falls through when (a7(=[([a1+4] + a1)+46]:2) & 0x3fff) == 0.
  The `beq` branch at 0x1cc4 targets 0x1cdc, is taken when a7(=[([a1+4] + a1)+49]:1) == t0(=0x6), and falls through when a7(=[([a1+4] + a1)+49]:1) != t0(=0x6).
  The `beq` branch at 0x1ccc targets 0x1cdc, is taken when a7(=[([a1+4] + a1)+49]:1) == t0(=0x11), and falls through when a7(=[([a1+4] + a1)+49]:1) != t0(=0x11).
  The `beq` branch at 0x1d7c targets 0x1dec, is taken when t8(?) == 0, and falls through when t8(?) != 0.
  The `bne` branch at 0x1dc8 targets 0x1cd4, is taken when a5(?) != a6(=0xffff), and falls through when a5(?) == a6(=0xffff).
  The `beq` branch at 0x1e10 targets 0x1dac and is always taken.
  The return at 0x1cd4 has v0 = ?.
  The return at 0x1de4 has v0 = ?.

- `mace_ether_input` in `IP32/usr/cpu/sysgen/IP32boot/if_me.o` at 0x1e18 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/if_me.o`.
  Range: 0x1e18-0x2040 (552 bytes).
  It occupies 552 bytes.
  The `lw` at 0x1e74 loads 4 bytes from a0 (arg0 at entry) +0x560.
  The `sw` at 0x1e7c stores 4 bytes to a0 (arg0 at entry) +0x560.
  The `lw` at 0x1e8c loads 4 bytes from a0 (arg0 at entry) +0x564.
  The `sw` at 0x1e94 stores 4 bytes to a0 (arg0 at entry) +0x564.
  The `lw` at 0x1eac loads 4 bytes from a0 (arg0 at entry) +0x14.
  The `lw` at 0x1eb0 loads 4 bytes from a0 (arg0 at entry) +0x2c.
  The `sw` at 0x1ec0 stores 4 bytes to a0 (arg0 at entry) +0x2c.
  The `lbu` at 0x1ec4 loads 1 byte from a0 (arg0 at entry) +0x580.
  The `lw` at 0x1f04 loads 4 bytes from a0 (arg0 at entry) +0x56c.
  The `sw` at 0x1f10 stores 4 bytes to a0 (arg0 at entry) +0x56c.
  The `lw` at 0x1f20 loads 4 bytes from a0 (arg0 at entry) +0x570.
  The `sw` at 0x1f28 stores 4 bytes to a0 (arg0 at entry) +0x570.
  The `lw` at 0x1f38 loads 4 bytes from a0 (arg0 at entry) +0x574.
  The `sw` at 0x1f44 stores 4 bytes to a0 (arg0 at entry) +0x574.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x3c, including `lw` at 0x1f48, `lw` at 0x1fd8.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x28, including `lw` at 0x1f50, `lw` at 0x1fd4.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x3c, including `sw` at 0x1f58, `sw` at 0x1fec.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x28, including `sw` at 0x1f60, `sw` at 0x1fe0.
  2 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x4, including `lw` at 0x1f64, `lw` at 0x1ff0.
  2 such `sh` accesses store 2 bytes to a1 (arg1 at entry) +0xc, including `sh` at 0x1f70, `sh` at 0x1ff8.
  2 such `sh` accesses store 2 bytes to ([a1+4] + a1) +0x4, including `sh` at 0x1f74, `sh` at 0x2004.
  2 such `sw` accesses store 4 bytes to ([a1+4] + a1) +0x0, including `sw` at 0x1f7c, `sw` at 0x2010.
  The `jal` at 0x1ed8 calls printf with a0=([a0+1408]:1 + sym(.rodata)+1056), a1=a2 at entry (arg2), a2=?, a3=?.
  The `jal` at 0x1f98 calls ether_input with a0=a0 at entry (arg0), a1=?, a2=a1 at entry (arg1), a3=?.
  The `jal` at 0x2030 calls mace_ether_hdwrcksum with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=?.
  The `beq` branch at 0x1e50 targets 0x1e60, is taken when a2 >= 0x801 (signed), and falls through when a2 < 0x801 (signed).
  The `beq` branch at 0x1e58 targets 0x1fcc, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `bgez` branch at 0x1e6c targets 0x1e84, is taken when v1(?) >= 0 (signed), and falls through when v1(?) < 0 (signed).
  The `bgez` branch at 0x1e84 targets 0x1e9c, is taken when a2(?) >= 0 (signed), and falls through when a2(?) < 0 (signed).
  The `beq` branch at 0x1ea4 targets 0x1fd4, is taken when t8(?) == 0, and falls through when t8(?) != 0.
  The `beq` branch at 0x1ebc targets 0x1ee0, is taken when (t9(=[a0+20]) & 0x4) == 0, and falls through when (t9(=[a0+20]) & 0x4) != 0.
  The `beq` branch at 0x1ef0 targets 0x1fb8, is taken when s3(=a2) >= 0x40 (signed), and falls through when s3(=a2) < 0x40 (signed).
  The `bgez` branch at 0x1efc targets 0x1f18, is taken when a0(?) >= 0 (signed), and falls through when a0(?) < 0 (signed).
  The `bgez` branch at 0x1f18 targets 0x1f30, is taken when a4(?) >= 0 (signed), and falls through when a4(?) < 0 (signed).
  The `bgez` branch at 0x1f30 targets 0x1f48, is taken when a6(?) >= 0 (signed), and falls through when a6(?) < 0 (signed).
  The `bne` branch at 0x1f78 targets 0x1f84, is taken when s5(?) != 0, and falls through when s5(?) == 0.
  The `bne` branch at 0x1fb8 targets 0x1efc, is taken when t3(?) != 0, and falls through when t3(?) == 0.
  The `beq` branch at 0x1fc4 targets 0x1efc and is always taken.
  The `beq` branch at 0x1fcc targets 0x1e6c and is always taken.
  The `beq` branch at 0x200c targets 0x2018, is taken when s5(?) == 0, and falls through when s5(?) != 0.
  The `bne` branch at 0x2018 targets 0x1f84, is taken when at(?) != 0, and falls through when at(?) == 0.
  The `beq` branch at 0x2020 targets 0x1f84, is taken when a0(=[sym(me_hdwrcksum_enable)]) == 0, and falls through when a0(=[sym(me_hdwrcksum_enable)]) != 0.
  The `beq` branch at 0x2038 targets 0x1f88 and is always taken.
  The return at 0x1fb0 has v0 = ret(ether_input).

- `pioflush` in `IP32/usr/cpu/sysgen/IP32boot/if_me.o` at 0x2040 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/if_me.o`.
  Range: 0x2040-0x206c (44 bytes).
  It occupies 44 bytes.
  2 such `sw` accesses store 4 bytes to abs 0xffffffffbf304018, including `sw` at 0x2058, `sw` at 0x205c.
  The `lw` at 0x2060 loads 4 bytes from abs 0xffffffffbf304018.
  The `jal` at 0x2048 calls wbflush with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x2064 has v0 = [0xffffffffbf304018].

- `mace_ether_receive` in `IP32/usr/cpu/sysgen/IP32boot/if_me.o` at 0x206c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/if_me.o`.
  Range: 0x206c-0x2360 (756 bytes).
  It occupies 756 bytes.
  The `lh` at 0x2074 loads 2 bytes from a0 (arg0 at entry) +0x4e6.
  The `lh` at 0x2090 loads 2 bytes from a0 (arg0 at entry) +0x4e4.
  12 such `lw` accesses load 4 bytes from ?, including `lw` at 0x20bc, `lw` at 0x20c8, `lw` at 0x20d8.
  The `sd` at 0x20c4 stores 8 bytes to ?.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x2a0, including `lw` at 0x20f4, `lw` at 0x22c8.
  The `sw` at 0x2128 stores 4 bytes to ?.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x528, including `lw` at 0x2180, `lw` at 0x21c4.
  The `lw` at 0x21bc loads 4 bytes from ret(m_get) +0x4.
  2 such `sh` accesses store 2 bytes to a0 (arg0 at entry) +0x4e4, including `sh` at 0x21e4, `sh` at 0x2220.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x14, including `lw` at 0x2238, `lw` at 0x230c.
  The `lw` at 0x22e0 loads 4 bytes from a0 (arg0 at entry) +0x584.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x578, including `lw` at 0x22e4, `lw` at 0x2350.
  The `sw` at 0x22f0 stores 4 bytes to a0 (arg0 at entry) +0x578.
  The `lw` at 0x22f4 loads 4 bytes from a0 (arg0 at entry) +0x588.
  The `lw` at 0x22f8 loads 4 bytes from a0 (arg0 at entry) +0x58c.
  The `lbu` at 0x231c loads 1 byte from a0 (arg0 at entry) +0x580.
  The `lw` at 0x2330 loads 4 bytes from a0 (arg0 at entry) +0x590.
  The `sw` at 0x2340 stores 4 bytes to a0 (arg0 at entry) +0x590.
  The `sw` at 0x235c stores 4 bytes to a0 (arg0 at entry) +0x588.
  The `jal` at 0x20d0 calls __vm_dcache_wb_inval with a0=?, a1=0x8, a2=?, a3=?.
  The `jal` at 0x20e0 calls __vm_dcache_inval with a0=?, a1=0x680, a2=?, a3=?.
  The `jal` at 0x20ec calls kvtophys with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x20fc calls pciio_pio_write32 with a0=ret(kvtophys), a1=[a0+672]+260, a2=?, a3=?.
  The `jal` at 0x2104 calls pioflush with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x2148 calls xdki_dcache_validate with a0=?, a1=0x680, a2=?, a3=?.
  The `jal` at 0x2158 calls __dcache_inval with a0=?, a1=0x80, a2=?, a3=?.
  The `jal` at 0x21a8 calls m_get with a0=0x0, a1=0x1, a2=?, a3=?.
  The `jal` at 0x21d4 calls bcopy with a0=?, a1=([ret(m_get)+4] + ret(m_get)), a2=?, a3=?.
  The `jal` at 0x2230 calls mace_ether_reset with a0=a0 at entry (arg0), a1=?, a2=[sym(me_qfull_delay)], a3=?.
  The `jal` at 0x224c calls itimeout with a0=sym(mace_ether_init), a1=a0 at entry (arg0), a2=[sym(me_qfull_delay)], a3=[sym(plbase)], a4=[a0+20].
  The `jal` at 0x2268 calls m_vget with a0=0x0, a1=0x1000, a2=0x1, a3=?.
  The `jal` at 0x228c calls __dcache_inval with a0=?, a1=0x600, a2=?, a3=?.
  The `jal` at 0x22a4 calls mace_ether_input with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x22c0 calls __vm_dcache_inval with a0=?, a1=0x680, a2=?, a3=?.
  The `jal` at 0x22d0 calls pciio_pio_write32 with a0=0x20, a1=[a0+672]+12, a2=?, a3=?.
  The `jal` at 0x22d8 calls wbflush with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x2328 calls printf with a0=([a0+1408]:1 + sym(.rodata)+1104), a1=sym(.rodata)+1104, a2=[a0+1412], a3=?.
  The `jal` at 0x233c calls mace_ether_reset with a0=a0 at entry (arg0), a1=?, a2=[a0+1424]+1, a3=?.
  The `jal` at 0x2348 calls mace_ether_init with a0=a0 at entry (arg0), a1=0x0, a2=?, a3=?.
  The `beq` branch at 0x20a8 targets 0x21e4, is taken when s7(?) == s3(=[a0+1252]:2), and falls through when s7(?) != s3(=[a0+1252]:2).
  The `beq` branch at 0x20b0 targets 0x212c and is always taken.
  The `beq` branch at 0x2124 targets 0x221c, is taken when s7(?) == s3(?), and falls through when s7(?) != s3(?).
  The `beq` branch at 0x2170 targets 0x22c0, is taken when (s4(=0xffffffff80000000) & v0(?)) == 0, and falls through when (s4(=0xffffffff80000000) & v0(?)) != 0.
  The `bne` branch at 0x2178 targets 0x20b8, is taken when s5(=one of 0x0, 0x1) != 0, and falls through when s5(=one of 0x0, 0x1) == 0.
  The `bne` branch at 0x2198 targets 0x225c, is taken when a1(?) < a2(?) (signed), and falls through when a1(?) >= a2(?) (signed).
  The `beq` branch at 0x21b0 targets 0x20bc, is taken when v0(=ret(m_get)) == 0, and falls through when v0(=ret(m_get)) != 0.
  The `beq` branch at 0x21dc targets 0x2294 and is always taken.
  The `beq` branch at 0x221c targets 0x21e8, is taken when s5(=one of 0x0, 0x1) == 0, and falls through when s5(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x2228 targets 0x21ec, is taken when a2(=[sym(me_qfull_delay)]) == 0, and falls through when a2(=[sym(me_qfull_delay)]) != 0.
  The `beq` branch at 0x2254 targets 0x21ec and is always taken.
  The `bne` branch at 0x2270 targets 0x2280, is taken when v0(=ret(m_vget)) != 0, and falls through when v0(=ret(m_vget)) == 0.
  The `beq` branch at 0x2278 targets 0x20bc and is always taken.
  The `bne` branch at 0x22b0 targets 0x20bc, is taken when v0(=ret(mace_ether_input)) != a1(=0x84), and falls through when v0(=ret(mace_ether_input)) == a1(=0x84).
  The `beq` branch at 0x22b8 targets 0x20bc and is always taken.
  The `beq` branch at 0x22ec targets 0x221c, is taken when a2(=[a0+1412]) == 0, and falls through when a2(=[a0+1412]) != 0.
  The `beq` branch at 0x2304 targets 0x221c, is taken when v1(=[a0+1420]) >= a0(?) (signed), and falls through when v1(=[a0+1420]) < a0(?) (signed).
  The `beq` branch at 0x2314 targets 0x2330, is taken when (a1(=[a0+20]) & 0x4) == 0, and falls through when (a1(=[a0+20]) & 0x4) != 0.
  The `beq` branch at 0x2358 targets 0x21ec and is always taken.
  The return at 0x2214 has v0 = one of 0x0, 0x1.

- `mace_ether_transmit_stats` in `IP32/usr/cpu/sysgen/IP32boot/if_me.o` at 0x2360 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/if_me.o`.
  Range: 0x2360-0x2464 (260 bytes).
  It occupies 260 bytes.
  The `lw` at 0x2368 loads 4 bytes from a0 (arg0 at entry) +0x40.
  The `lw` at 0x2370 loads 4 bytes from a0 (arg0 at entry) +0x38.
  The `sw` at 0x2380 stores 4 bytes to a0 (arg0 at entry) +0x40.
  The `sw` at 0x238c stores 4 bytes to a0 (arg0 at entry) +0x38.
  The `lw` at 0x2390 loads 4 bytes from a0 (arg0 at entry) +0x548.
  The `sw` at 0x2398 stores 4 bytes to a0 (arg0 at entry) +0x548.
  The `lw` at 0x23b4 loads 4 bytes from a0 (arg0 at entry) +0x540.
  The `sw` at 0x23bc stores 4 bytes to a0 (arg0 at entry) +0x540.
  The `lw` at 0x23c8 loads 4 bytes from a0 (arg0 at entry) +0x544.
  The `sw` at 0x23d0 stores 4 bytes to a0 (arg0 at entry) +0x544.
  The `lw` at 0x23e8 loads 4 bytes from a0 (arg0 at entry) +0x54c.
  The `sw` at 0x23f0 stores 4 bytes to a0 (arg0 at entry) +0x54c.
  The `lw` at 0x23fc loads 4 bytes from a0 (arg0 at entry) +0x550.
  The `sw` at 0x2404 stores 4 bytes to a0 (arg0 at entry) +0x550.
  The `lw` at 0x2410 loads 4 bytes from a0 (arg0 at entry) +0x554.
  The `sw` at 0x2418 stores 4 bytes to a0 (arg0 at entry) +0x554.
  The `lw` at 0x2428 loads 4 bytes from a0 (arg0 at entry) +0x558.
  The `sw` at 0x2430 stores 4 bytes to a0 (arg0 at entry) +0x558.
  The `lw` at 0x243c loads 4 bytes from a0 (arg0 at entry) +0x55c.
  The `sw` at 0x2444 stores 4 bytes to a0 (arg0 at entry) +0x55c.
  The `lw` at 0x2450 loads 4 bytes from a0 (arg0 at entry) +0x34.
  The `sw` at 0x2458 stores 4 bytes to a0 (arg0 at entry) +0x34.
  The `bgez` branch at 0x2388 targets 0x239c, is taken when v0(=(a1 << 0x29)) >= 0 (signed), and falls through when v0(=(a1 << 0x29)) < 0 (signed).
  The `bltz` branch at 0x23a4 targets 0x245c, is taken when a3(=(a1 << 0x28)) < 0 (signed), and falls through when a3(=(a1 << 0x28)) >= 0 (signed).
  The `bgez` branch at 0x23ac targets 0x23c0, is taken when a5(=(a1 << 0x2b)) >= 0 (signed), and falls through when a5(=(a1 << 0x2b)) < 0 (signed).
  The `bgez` branch at 0x23c0 targets 0x23d8, is taken when a4(=(a1 << 0x2a)) >= 0 (signed), and falls through when a4(=(a1 << 0x2a)) < 0 (signed).
  The `bgez` branch at 0x23e0 targets 0x23f4, is taken when a6(=(a1 << 0x27)) >= 0 (signed), and falls through when a6(=(a1 << 0x27)) < 0 (signed).
  The `bgez` branch at 0x23f4 targets 0x2408, is taken when a3(=(a1 << 0x26)) >= 0 (signed), and falls through when a3(=(a1 << 0x26)) < 0 (signed).
  The `bgez` branch at 0x2408 targets 0x2420, is taken when a4(=(a1 << 0x25)) >= 0 (signed), and falls through when a4(=(a1 << 0x25)) < 0 (signed).
  The `bgez` branch at 0x2420 targets 0x2434, is taken when t8(=(a1 << 0x24)) >= 0 (signed), and falls through when t8(=(a1 << 0x24)) < 0 (signed).
  The `bgez` branch at 0x2434 targets 0x2448, is taken when a5(=(a1 << 0x23)) >= 0 (signed), and falls through when a5(=(a1 << 0x23)) < 0 (signed).
  The `beq` branch at 0x2448 targets 0x245c, is taken when a7(?) == 0, and falls through when a7(?) != 0.
  The return at 0x245c has v0 = one of (a1 << 0x29), [a0+52]+1.

- `mace_ether_transmit_complete` in `IP32/usr/cpu/sysgen/IP32boot/if_me.o` at 0x2464 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/if_me.o`.
  Range: 0x2464-0x2570 (268 bytes).
  It occupies 268 bytes.
  The `lh` at 0x2480 loads 2 bytes from a0 (arg0 at entry) +0x2b2.
  The `lh` at 0x2490 loads 2 bytes from a0 (arg0 at entry) +0x2b0.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x4b8, including `lw` at 0x249c, `lw` at 0x250c.
  The `ld` at 0x24b8 loads 8 bytes from ([a0+1208] + ([a0+688]:2 << 0x7)) +0x0.
  The `lw` at 0x24e8 loads 4 bytes from ?.
  The `sw` at 0x24f0 stores 4 bytes to ?.
  The `sd` at 0x24f8 stores 8 bytes to ?.
  The `sh` at 0x24fc stores 2 bytes to a0 (arg0 at entry) +0x4be.
  The `ld` at 0x2514 loads 8 bytes from ?.
  The `sh` at 0x2524 stores 2 bytes to a0 (arg0 at entry) +0x2b0.
  The `ll` at 0x252c loads 4 bytes from a0 (arg0 at entry) +0x2b4.
  The `sc` at 0x2538 stores 4 bytes to a0 (arg0 at entry) +0x2b4.
  The `jal` at 0x24d4 calls mace_ether_transmit_stats with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x24e4 calls m_freem with a0=?, a1=?, a2=?, a3=?.
  The `beq` branch at 0x24b0 targets 0x2544, is taken when s1(=[a0+688]:2) == s7(=[a0+690]:2), and falls through when s1(=[a0+688]:2) != s7(=[a0+690]:2).
  The `beq` branch at 0x24c4 targets 0x2524, is taken when (a3(=[([a0+1208] + ([a0+688]:2 << 0x7))]:8) & s4(=0x8000000000000000)) == 0, and falls through when (a3(=[([a0+1208] + ([a0+688]:2 << 0x7))]:8) & s4(=0x8000000000000000)) != 0.
  The `beq` branch at 0x2504 targets 0x2524, is taken when s1(?) == s7(=[a0+690]:2), and falls through when s1(?) != s7(=[a0+690]:2).
  The `bne` branch at 0x251c targets 0x24d4, is taken when (a3(?) & s4(=0x8000000000000000)) != 0, and falls through when (a3(?) & s4(=0x8000000000000000)) == 0.
  The `beql` branch at 0x253c targets 0x252c, is taken when at(?) == 0, and falls through when at(?) != 0; its branch-likely delay slot `nop` at 0x2540 runs only when taken and is annulled on fall-through.
  The return at 0x2568 has v0 = ?.

- `mace_valid_txcmd` in `IP32/usr/cpu/sysgen/IP32boot/if_me.o` at 0x2570 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/if_me.o`.
  Range: 0x2570-0x2720 (432 bytes).
  It occupies 432 bytes.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x0, including `ld` at 0x2574, `ld` at 0x25bc.
  The `ld` at 0x25c8 loads 8 bytes from a0 (arg0 at entry) +0x8.
  The `ld` at 0x25d4 loads 8 bytes from a0 (arg0 at entry) +0x10.
  The `ld` at 0x25e0 loads 8 bytes from a0 (arg0 at entry) +0x18.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0x25f8, `ld` at 0x26cc.
  The `jal` at 0x25b4 calls printf with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jal` at 0x25c0 calls printf with a0=sym(.rodata), a1=[a0]:8, a2=?, a3=?.
  The `jal` at 0x25cc calls printf with a0=sym(.rodata), a1=[a0+8]:8, a2=?, a3=?.
  The `jal` at 0x25d8 calls printf with a0=sym(.rodata), a1=[a0+16]:8, a2=?, a3=?.
  The `jal` at 0x25e4 calls printf with a0=sym(.rodata), a1=[a0+24]:8, a2=?, a3=?.
  The `jal` at 0x25fc calls printf with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `bne` branch at 0x25a0 targets 0x2630, is taken when a3(?) < 0x5ea (unsigned), and falls through when a3(?) >= 0x5ea (unsigned).
  The `bne` branch at 0x260c targets 0x25f4, is taken when s0(?) < 0x10 (unsigned), and falls through when s0(?) >= 0x10 (unsigned).
  The `beq` branch at 0x2638 targets 0x2648, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0x2640 targets 0x25b0 and is always taken.
  The `beq` branch at 0x264c targets 0x265c, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `beq` branch at 0x2654 targets 0x25b0 and is always taken.
  The `bne` branch at 0x2660 targets 0x2670, is taken when a7(?) != 0, and falls through when a7(?) == 0.
  The `beq` branch at 0x2668 targets 0x25b0 and is always taken.
  The `beq` branch at 0x2674 targets 0x2684, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `beq` branch at 0x267c targets 0x25b0 and is always taken.
  The `beq` branch at 0x2698 targets 0x26a4, is taken when (t9(?) & 0x1) == 0, and falls through when (t9(?) & 0x1) != 0.
  The `bne` branch at 0x26a4 targets 0x2688, is taken when a1(?) != 0, and falls through when a1(?) == 0.
  The `bne` branch at 0x26b0 targets 0x26c0, is taken when a0(?) < 0x4 (unsigned), and falls through when a0(?) >= 0x4 (unsigned).
  The `beq` branch at 0x26b8 targets 0x25ac and is always taken.
  The `beq` branch at 0x26c0 targets 0x2614, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x26d4 targets 0x26e4, is taken when (a3(?) & 0x7) == 0, and falls through when (a3(?) & 0x7) != 0.
  The `beq` branch at 0x26dc targets 0x25ac and is always taken.
  The `beq` branch at 0x26e4 targets 0x26f4, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x26ec targets 0x25ac and is always taken.
  The `beq` branch at 0x26fc targets 0x2718, is taken when v1(?) >= 0x5ea (unsigned), and falls through when v1(?) < 0x5ea (unsigned).
  The `beq` branch at 0x2708 targets 0x26cc, is taken when a0(?) >= a4(?) (unsigned), and falls through when a0(?) < a4(?) (unsigned).
  The `beq` branch at 0x2710 targets 0x2618 and is always taken.
  The `beq` branch at 0x2718 targets 0x25ac and is always taken.
  The return at 0x2628 has v0 = ?.

- `mace_tx_catlist` in `IP32/usr/cpu/sysgen/IP32boot/if_me.o` at 0x2720 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/if_me.o`.
  Range: 0x2720-0x29c4 (676 bytes).
  It occupies 676 bytes.
  The `lbu` at 0x2720 loads 1 byte from a0 (arg0 at entry) +0x2a8.
  The `lbu` at 0x2784 loads 1 byte from ?.
  2 such `lhu` accesses load 2 bytes from ?, including `lhu` at 0x2790, `lhu` at 0x27c8.
  4 such `lw` accesses load 4 bytes from ?, including `lw` at 0x27a4, `lw` at 0x27d8, `lw` at 0x2828.
  2 such `sw` accesses store 4 bytes to a3 (arg3 at entry) +0x0, including `sw` at 0x2848, `sw` at 0x295c.
  The `lw` at 0x284c loads 4 bytes from a0 (arg0 at entry) +0x4e0.
  The `sw` at 0x285c stores 4 bytes to a0 (arg0 at entry) +0x4e0.
  The `lw` at 0x2860 loads 4 bytes from a0 (arg0 at entry) +0x4d4.
  The `sw` at 0x286c stores 4 bytes to a0 (arg0 at entry) +0x4d4.
  The `lw` at 0x28c0 loads 4 bytes from a0 (arg0 at entry) +0x4d8.
  The `sw` at 0x28d0 stores 4 bytes to a0 (arg0 at entry) +0x4d8.
  2 such `sd` accesses store 8 bytes to ?, including `sd` at 0x2930, `sd` at 0x29c0.
  The `lw` at 0x2934 loads 4 bytes from a0 (arg0 at entry) +0x4dc.
  The `sw` at 0x2944 stores 4 bytes to a0 (arg0 at entry) +0x4dc.
  The `jal` at 0x28d8 calls dki_dcache_wb with a0=?, a1=?, a2=?, a3=?, a7=0x8.
  The `jal` at 0x28fc calls kvtophys with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x2988 calls kvtophys with a0=?, a1=?, a2=?, a3=?.
  The `beq` branch at 0x276c targets 0x2870, is taken when at(=[sym(me_hdwrgather_enable)]) == 0, and falls through when at(=[sym(me_hdwrgather_enable)]) != 0.
  The `beq` branch at 0x277c targets 0x27b8, is taken when a2 == 0, and falls through when a2 != 0.
  The `bne` branch at 0x2788 targets 0x27c0, is taken when t0(=0x2) != v0(?), and falls through when t0(=0x2) == v0(?).
  The `beq` branch at 0x279c targets 0x27c0, is taken when v0(?) >= 0x61 (signed), and falls through when v0(?) < 0x61 (signed).
  The `bne` branch at 0x27a8 targets 0x2784, is taken when s0(?) != 0, and falls through when s0(?) == 0.
  The `beq` branch at 0x27b0 targets 0x27c0 and is always taken.
  The `beq` branch at 0x27c0 targets 0x2948, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0x27d0 targets 0x2828, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x27e8 targets 0x28a0, is taken when (a6(?) & 0x7) == 0, and falls through when (a6(?) & 0x7) != 0.
  The `bne` branch at 0x27f0 targets 0x2860, is taken when s4(?) != s8(=0x1), and falls through when s4(?) == s8(=0x1).
  The `bne` branch at 0x27f8 targets 0x280c, is taken when t0(?) != 0, and falls through when t0(?) == 0.
  The `beq` branch at 0x2804 targets 0x2820 and is always taken.
  The `beq` branch at 0x2820 targets 0x28a4, is taken when a1(=one of 0x0, 0x1) == 0, and falls through when a1(=one of 0x0, 0x1) != 0.
  The `bne` branch at 0x282c targets 0x27c8, is taken when s0(?) != 0, and falls through when s0(?) == 0.
  The `beq` branch at 0x2844 targets 0x2960, is taken when t9(?) >= ra(?) (unsigned), and falls through when t9(?) < ra(?) (unsigned).
  The `beq` branch at 0x2858 targets 0x2870 and is always taken.
  The `bne` branch at 0x28a4 targets 0x28d8, is taken when v0(=[a0+680]:1) != 0, and falls through when v0(=[a0+680]:1) == 0.
  The `beq` branch at 0x28b0 targets 0x28d4, is taken when v1(?) == 0, and falls through when v1(?) != 0.
  The `beq` branch at 0x28b8 targets 0x28d8, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x28cc targets 0x2870 and is always taken.
  The `bne` branch at 0x28f4 targets 0x2968, is taken when a1(?) != a2(?), and falls through when a1(?) == a2(?).
  The `bne` branch at 0x292c targets 0x2828, is taken when s4(?) < 0x5 (signed), and falls through when s4(?) >= 0x5 (signed).
  The `beq` branch at 0x2940 targets 0x2870 and is always taken.
  The `beq` branch at 0x2958 targets 0x284c, is taken when a7(?) >= 0x79 (unsigned), and falls through when a7(?) < 0x79 (unsigned).
  The `beq` branch at 0x2960 targets 0x2870 and is always taken.
  The `beq` branch at 0x29bc targets 0x28fc and is always taken.
  The return at 0x2898 has v0 = one of -0x1, ?.

- `mace_ether_output` in `IP32/usr/cpu/sysgen/IP32boot/if_me.o` at 0x29c4 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/if_me.o`.
  Range: 0x29c4-0x2e1c (1112 bytes).
  It occupies 1112 bytes.
  The `lw` at 0x29e4 loads 4 bytes from a0 (arg0 at entry) +0xbc.
  The `lbu` at 0x29ec loads 1 byte from [a0+188] +0x2ab.
  5 such `lh` accesses load 2 bytes from [a0+188] +0x2b2, including `lh` at 0x29f0, `lh` at 0x2a9c, `lh` at 0x2b28.
  The `lw` at 0x29f4 loads 4 bytes from [a0+188] +0x4b8.
  2 such `lw` accesses load 4 bytes from [a0+188] +0x50, including `lw` at 0x2a14, `lw` at 0x2e00.
  2 such `sw` accesses store 4 bytes to [a0+188] +0x50, including `sw` at 0x2a24, `sw` at 0x2e10.
  The `lw` at 0x2a58 loads 4 bytes from [a0+188] +0x2b4.
  3 such `lw` accesses load 4 bytes from [a0+188] +0x14, including `lw` at 0x2a7c, `lw` at 0x2bdc, `lw` at 0x2dfc.
  The `lw` at 0x2a80 loads 4 bytes from [a0+188] +0x4c4.
  The `sw` at 0x2a94 stores 4 bytes to [a0+188] +0x4c4.
  The `lh` at 0x2ab8 loads 2 bytes from [a0+188] +0x57e.
  The `lh` at 0x2acc loads 2 bytes from [a0+188] +0x57c.
  3 such `sd` accesses store 8 bytes to ([[a0+188]+1208] + ([[a0+188]+690]:2 << 0x7)) +0x0, including `sd` at 0x2b24, `sd` at 0x2cc0, `sd` at 0x2d78.
  3 such `sw` accesses store 4 bytes to ([a0+188] + ([[a0+188]+690]:2 << 0x2)) +0x2b8, including `sw` at 0x2b34, `sw` at 0x2cd4, `sw` at 0x2d6c.
  The `lw` at 0x2b38 loads 4 bytes from [a0+188] +0x4c8.
  The `sw` at 0x2b44 stores 4 bytes to [a0+188] +0x4c8.
  The `lwl` at 0x2b4c loads 4 bytes from a1 (arg1 at entry) +0x0.
  The `lwr` at 0x2b54 loads 4 bytes from a1 (arg1 at entry) +0x3.
  2 such `swl` accesses store 4 bytes to ?, including `swl` at 0x2b58, `swl` at 0x2b7c.
  2 such `swr` accesses store 4 bytes to ?, including `swr` at 0x2b5c, `swr` at 0x2b80.
  The `lbu` at 0x2b60 loads 1 byte from a1 (arg1 at entry) +0x4.
  6 such `sb` accesses store 1 byte to ?, including `sb` at 0x2b64, `sb` at 0x2b6c, `sb` at 0x2b88.
  The `lbu` at 0x2b68 loads 1 byte from a1 (arg1 at entry) +0x5.
  The `lwl` at 0x2b70 loads 4 bytes from a2 (arg2 at entry) +0x0.
  The `lwr` at 0x2b78 loads 4 bytes from a2 (arg2 at entry) +0x3.
  The `lbu` at 0x2b84 loads 1 byte from a2 (arg2 at entry) +0x4.
  The `lbu` at 0x2b8c loads 1 byte from a2 (arg2 at entry) +0x5.
  The `lbu` at 0x2ba0 loads 1 byte from [a0+188] +0x13e.
  The `ll` at 0x2bfc loads 4 bytes from [a0+188] +0x2b4.
  The `sc` at 0x2c08 stores 4 bytes to [a0+188] +0x2b4.
  The `lw` at 0x2c20 loads 4 bytes from [a0+188] +0x2a0.
  The `sh` at 0x2c28 stores 2 bytes to [a0+188] +0x2b2.
  The `lw` at 0x2c98 loads 4 bytes from table(sym(.data)+24) +0x0.
  The `lw` at 0x2cd8 loads 4 bytes from [a0+188] +0x4cc.
  The `sw` at 0x2cf0 stores 4 bytes to [a0+188] +0x4cc.
  The `lw` at 0x2cf4 loads 4 bytes from [a0+188] +0x84.
  The `sw` at 0x2cfc stores 4 bytes to [a0+188] +0x84.
  The `lw` at 0x2d80 loads 4 bytes from ret(m_vget) +0x4.
  The `lhu` at 0x2d8c loads 2 bytes from ret(m_vget) +0xc.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0x2d9c, `lw` at 0x2db0.
  2 such `lhu` accesses load 2 bytes from ?, including `lhu` at 0x2da0, `lhu` at 0x2dc0.
  The `sd` at 0x2dd8 stores 8 bytes to ([[a0+188]+1208] + ([[a0+188]+690]:2 << 0x7)) +0x8.
  The `lw` at 0x2ddc loads 4 bytes from [a0+188] +0x4d0.
  The `sw` at 0x2dec stores 4 bytes to [a0+188] +0x4d0.
  The `jal` at 0x2a20 calls m_freem with a0=a4 at entry (arg4), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x2a50 calls mace_ether_transmit_complete with a0=[a0+188], a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x2a68 calls m_length with a0=a4 at entry (arg4), a1=?, a2=?, a3=?.
  The `jal` at 0x2b20 calls m_datacopy with a0=a4 at entry (arg4), a1=0x0, a2=ret(m_length), a3=?.
  The `jal` at 0x2bb0 calls bcopy with a0=?, a1=sp-136, a2=0xe, a3=?.
  The `jal` at 0x2bc8 calls ether_selfsnoop with a0=[a0+188], a1=sp-136, a2=a4 at entry (arg4), a3=0x0, a4=ret(m_length).
  The `jal` at 0x2bec calls mace_valid_txcmd with a0=([[a0+188]+1208] + ([[a0+188]+690]:2 << 0x7)), a1=?, a2=?, a3=?, a6=[a0+188]+692.
  The `jal` at 0x2c14 calls wbflush with a0=?, a1=?, a2=?, a3=?, a5=[[a0+188]+692]-1, a6=[a0+188]+692, a7=-0x1.
  The `jal` at 0x2c2c calls pciio_pio_write16 with a0=?, a1=[[a0+188]+672]+54, a2=?, a3=?.
  The `jal` at 0x2c48 calls mace_tx_catlist with a0=[a0+188], a1=([[a0+188]+1208] + ([[a0+188]+690]:2 << 0x7)), a2=a4 at entry (arg4), a3=sp-144.
  The `jal` at 0x2c70 calls m_datacopy with a0=a4 at entry (arg4), a1=0x0, a2=?, a3=?.
  The `jal` at 0x2d00 calls m_freem with a0=a4 at entry (arg4), a1=?, a2=?, a3=?.
  The `jal` at 0x2d18 calls m_freem with a0=a4 at entry (arg4), a1=?, a2=?, a3=?.
  The `jal` at 0x2d34 calls m_vget with a0=0x0, a1=ret(m_length), a2=0x1, a3=?.
  The `jal` at 0x2d90 calls m_datacopy with a0=a4 at entry (arg4), a1=0x0, a2=[ret(m_vget)+12]:2, a3=([ret(m_vget)+4] + ret(m_vget)), a4=ret(m_vget), a6=([a0+188] + ([[a0+188]+690]:2 << 0x2)), a7=0x720000.
  The `jal` at 0x2da4 calls dki_dcache_wb with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x2db4 calls kvtophys with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x2df0 calls m_freem with a0=a4 at entry (arg4), a1=?, a2=?, a3=?.
  The `jal` at 0x2e0c calls m_freem with a0=a4 at entry (arg4), a1=?, a2=?, a3=?, a5=[[a0+188]+80]+1.
  The `beq` branch at 0x2a0c targets 0x2a50, is taken when (at(=[[a0+188]+683]:1) & 0x10) == 0, and falls through when (at(=[[a0+188]+683]:1) & 0x10) != 0.
  The `bne` branch at 0x2a60 targets 0x2cf4, is taken when v1(=[[a0+188]+692]) < 0x2 (signed), and falls through when v1(=[[a0+188]+692]) >= 0x2 (signed).
  The `beq` branch at 0x2a74 targets 0x2d18, is taken when v0(=ret(m_length)) >= 0x5dd (signed), and falls through when v0(=ret(m_length)) < 0x5dd (signed).
  The `beq` branch at 0x2a90 targets 0x2a9c, is taken when (a2(=[[a0+188]+20]) & 0x4) == 0, and falls through when (a2(=[[a0+188]+20]) & 0x4) != 0.
  The `beq` branch at 0x2ab0 targets 0x2d10, is taken when (a3(?) & 0x1f) == 0, and falls through when (a3(?) & 0x1f) != 0.
  The `beq` branch at 0x2ac0 targets 0x2ae0, is taken when (a4(=[[a0+188]+1406]:2) & 0x10) == 0, and falls through when (a4(=[[a0+188]+1406]:2) & 0x10) != 0.
  The `beq` branch at 0x2ad4 targets 0x2d28, is taken when (a5(=[[a0+188]+1404]:2) & a6(?)) == 0, and falls through when (a5(=[[a0+188]+1404]:2) & a6(?)) != 0.
  The `beq` branch at 0x2ae4 targets 0x2c3c, is taken when a7(=ret(m_length)+14) >= 0x78 (unsigned), and falls through when a7(=ret(m_length)+14) < 0x78 (unsigned).
  The `beq` branch at 0x2ba4 targets 0x2bd0, is taken when t8(=[[a0+188]+318]:1) == 0, and falls through when t8(=[[a0+188]+318]:1) != 0.
  The `beq` branch at 0x2bd4 targets 0x2df0, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0x2be4 targets 0x2bf8, is taken when (a4(=[[a0+188]+20]) & 0x4) == 0, and falls through when (a4(=[[a0+188]+20]) & 0x4) != 0.
  The `beql` branch at 0x2c0c targets 0x2bfc, is taken when t0(=[[a0+188]+692]-1) == 0, and falls through when t0(=[[a0+188]+692]-1) != 0; its branch-likely delay slot `nop` at 0x2c10 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x2c34 targets 0x2a2c and is always taken.
  The `blez` branch at 0x2c50 targets 0x2d30, is taken when v0(=ret(mace_tx_catlist)) <= 0 (signed), and falls through when v0(=ret(mace_tx_catlist)) > 0 (signed).
  The `beq` branch at 0x2cec targets 0x2b48 and is always taken.
  The `beq` branch at 0x2d08 targets 0x2a2c and is always taken.
  The `beq` branch at 0x2d10 targets 0x2adc and is always taken.
  The `beq` branch at 0x2d20 targets 0x2a2c and is always taken.
  The `beq` branch at 0x2d28 targets 0x2adc and is always taken.
  The `beq` branch at 0x2d3c targets 0x2e00, is taken when v0(=ret(m_vget)) == 0, and falls through when v0(=ret(m_vget)) != 0.
  The `beq` branch at 0x2de8 targets 0x2b48 and is always taken.
  The `beq` branch at 0x2df8 targets 0x2be0 and is always taken.
  The `beq` branch at 0x2e14 targets 0x2a2c and is always taken.
  The return at 0x2a48 has v0 = one of 0x0, 0x5, 0x7, 0x84.

- `CrcGen` in `IP32/usr/cpu/sysgen/IP32boot/if_me.o` at 0x2e1c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/if_me.o`.
  Range: 0x2e1c-0x2e94 (120 bytes).
  It occupies 120 bytes.
  The `lbu` at 0x2e38 loads 1 byte from ?.
  The `blez` branch at 0x2e1c targets 0x2e88, is taken when a1 <= 0 (signed), and falls through when a1 > 0 (signed).
  The `beq` branch at 0x2e58 targets 0x2e68, is taken when at(?) == 0, and falls through when at(?) != 0.
  The `bne` branch at 0x2e6c targets 0x2e44, is taken when a6(?) != 0, and falls through when a6(?) == 0.
  The `bgez` branch at 0x2e78 targets 0x2e38, is taken when a1(?) >= 0 (signed), and falls through when a1(?) < 0 (signed).
  The return at 0x2e80 has v0 = ?.
  The return at 0x2e8c has v0 = -0x1.

- `mace_laf_hash` in `IP32/usr/cpu/sysgen/IP32boot/if_me.o` at 0x2e94 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/if_me.o`.
  Range: 0x2e94-0x2eb4 (32 bytes).
  It occupies 32 bytes.
  The `jal` at 0x2e9c calls CrcGen with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x2eac has v0 = ?.

- `mace_ether_ioctl` in `IP32/usr/cpu/sysgen/IP32boot/if_me.o` at 0x2eb4 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/if_me.o`.
  Range: 0x2eb4-0x3014 (352 bytes).
  It occupies 352 bytes.
  The `lw` at 0x2eb4 loads 4 bytes from a2 (arg2 at entry) +0x0.
  The `lw` at 0x2edc loads 4 bytes from a0 (arg0 at entry) +0xbc.
  2 such `lhu` accesses load 2 bytes from a2 (arg2 at entry) +0x4, including `lhu` at 0x2f18, `lhu` at 0x2fb4.
  The `sh` at 0x2f38 stores 2 bytes to a2 (arg2 at entry) +0x4.
  2 such `ld` accesses load 8 bytes from [a0+188] +0x298, including `ld` at 0x2f3c, `ld` at 0x2fc0.
  2 such `lw` accesses load 4 bytes from [a0+188] +0x28c, including `lw` at 0x2f58, `lw` at 0x2f7c.
  2 such `sw` accesses store 4 bytes to [a0+188] +0x28c, including `sw` at 0x2f60, `sw` at 0x2f88.
  2 such `lw` accesses load 4 bytes from [a0+188] +0x2a0, including `lw` at 0x2f8c, `lw` at 0x2fb8.
  2 such `sd` accesses store 8 bytes to [a0+188] +0x298, including `sd` at 0x2f94, `sd` at 0x2fd8.
  3 such `lw` accesses load 4 bytes from [a0+188] +0x290, including `lw` at 0x2fa0, `lw` at 0x2fdc, `lw` at 0x3010.
  2 such `sw` accesses store 4 bytes to [a0+188] +0x290, including `sw` at 0x2fb0, `sw` at 0x2fe8.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x14, including `lw` at 0x2fec, `lw` at 0x3000.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x14, including `sw` at 0x2ffc, `sw` at 0x3008.
  The `jal` at 0x2f10 calls mace_laf_hash with a0=[a2]+2, a1=0x6, a2=a2 at entry (arg2), a3=a3 at entry (arg3), a5=0x16, a6=0xffffffff80206932.
  The `jal` at 0x2f30 calls mace_laf_hash with a0=[a2]+2, a1=0x6, a2=a2 at entry (arg2), a3=a3 at entry (arg3), a5=0x16, a6=0xffffffff80206932.
  The `jal` at 0x2f6c calls mfhasvalue with a0=a0+204, a1=[a2+4]:2, a2=?, a3=?, a5=0x16.
  The `jal` at 0x2f98 calls pciio_pio_write64 with a0=?, a1=[[a0+188]+672]+176, a2=?, a3=?, a5=[[a0+188]+664]:8.
  The `jal` at 0x2fd4 calls pciio_pio_write64 with a0=?, a1=[[a0+188]+672]+176, a2=?, a3=[a2+4]:2.
  The `beq` branch at 0x2ee4 targets 0x2f2c, is taken when a1 == at(=0xffffffff80206931), and falls through when a1 != at(=0xffffffff80206931).
  The `beq` branch at 0x2eec targets 0x2f10, is taken when a1 == a6(=0xffffffff80206932), and falls through when a1 != a6(=0xffffffff80206932).
  The `beq` branch at 0x2f1c targets 0x2f6c, is taken when v0(=ret(mace_laf_hash)) == a1(=[a2+4]:2), and falls through when v0(=ret(mace_laf_hash)) != a1(=[a2+4]:2).
  The `beq` branch at 0x2f24 targets 0x2ef8 and is always taken.
  The `beq` branch at 0x2f50 targets 0x2f8c, is taken when (a5(=[[a0+188]+664]:8) & a2(?)) == 0, and falls through when (a5(=[[a0+188]+664]:8) & a2(?)) != 0.
  The `beq` branch at 0x2f64 targets 0x2ef4 and is always taken.
  The `beq` branch at 0x2f74 targets 0x2fb4, is taken when v0(=ret(mfhasvalue)) == 0, and falls through when v0(=ret(mfhasvalue)) != 0.
  The `beq` branch at 0x2f84 targets 0x2f64 and is always taken.
  The `beq` branch at 0x2fa4 targets 0x3000, is taken when v0(=[[a0+188]+656]) == 0, and falls through when v0(=[[a0+188]+656]) != 0.
  The `beq` branch at 0x2fac targets 0x2f64 and is always taken.
  The `bne` branch at 0x2fe4 targets 0x2f64, is taken when a4(=[[a0+188]+656]-1) != 0, and falls through when a4(=[[a0+188]+656]-1) == 0.
  The `beq` branch at 0x2ff8 targets 0x2f64 and is always taken.
  The `beq` branch at 0x300c targets 0x2fa8 and is always taken.
  The return at 0x2f08 has v0 = one of 0x0, 0x16.

- `mace_hexconv` in `IP32/usr/cpu/sysgen/IP32boot/if_me.o` at 0x3014 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/if_me.o`.
  Range: 0x3014-0x30e4 (208 bytes).
  It occupies 208 bytes.
  4 such `sb` accesses store 1 byte to sym(.bss) +0x0, including `sb` at 0x3058, `sb` at 0x3070, `sb` at 0x309c.
  3 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x3060, `lbu` at 0x3074, `lbu` at 0x30d4.
  2 such `lbu` accesses load 1 byte from table(sym(.rodata)) +0x0, including `lbu` at 0x306c, `lbu` at 0x308c.
  The `sb` at 0x3098 stores 1 byte to sym(.bss) -0x1.
  The `beq` branch at 0x302c targets 0x3048, is taken when a1 >= 0x20 (signed), and falls through when a1 < 0x20 (signed).
  The `bgtz` branch at 0x3034 targets 0x3050, is taken when a1 > 0 (signed), and falls through when a1 <= 0 (signed).
  The `beq` branch at 0x3040 targets 0x30d8 and is always taken.
  The `beq` branch at 0x3050 targets 0x30a8 and is always taken.
  The `beq` branch at 0x3094 targets 0x30a4, is taken when a2 == 0, and falls through when a2 != 0.
  The `beq` branch at 0x30a4 targets 0x30d8, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `bne` branch at 0x30c0 targets 0x3060, is taken when t9(?) != 0, and falls through when t9(?) == 0.
  The `bne` branch at 0x30c8 targets 0x3058, is taken when a4(?) != 0, and falls through when a4(?) == 0.
  The `beq` branch at 0x30d0 targets 0x3064 and is always taken.
  The return at 0x30dc has v0 = sym(.bss).

- `mace_hexdump` in `IP32/usr/cpu/sysgen/IP32boot/if_me.o` at 0x30e4 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/if_me.o`.
  Range: 0x30e4-0x3128 (68 bytes).
  It occupies 68 bytes.
  The `jal` at 0x30fc calls mace_hexconv with a0=a1 at entry (arg1), a1=a2 at entry (arg2), a2=0x1, a3=a3 at entry (arg3).
  The `jal` at 0x3110 calls qprintf with a0=sym(.rodata)+1352, a1=a0 at entry (arg0), a2=ret(mace_hexconv), a3=?.
  The return at 0x3120 has v0 = ret(qprintf).

- `mace_dumpif` in `IP32/usr/cpu/sysgen/IP32boot/if_me.o` at 0x3128 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/if_me.o`.
  Range: 0x3128-0x31b8 (144 bytes).
  It occupies 144 bytes.
  The `lw` at 0x3128 loads 4 bytes from a0 (arg0 at entry) +0x0.
  The `lh` at 0x312c loads 2 bytes from a0 (arg0 at entry) +0xe.
  The `lw` at 0x3130 loads 4 bytes from a0 (arg0 at entry) +0x1c.
  The `lw` at 0x3134 loads 4 bytes from a0 (arg0 at entry) +0x14.
  The `lh` at 0x3138 loads 2 bytes from a0 (arg0 at entry) +0x10.
  The `lw` at 0x3160 loads 4 bytes from a0 (arg0 at entry) +0x84.
  The `lw` at 0x3164 loads 4 bytes from a0 (arg0 at entry) +0x80.
  The `lw` at 0x3168 loads 4 bytes from a0 (arg0 at entry) +0x7c.
  The `lw` at 0x3174 loads 4 bytes from a0 (arg0 at entry) +0x34.
  The `lw` at 0x3178 loads 4 bytes from a0 (arg0 at entry) +0x30.
  The `lw` at 0x317c loads 4 bytes from a0 (arg0 at entry) +0x2c.
  The `lw` at 0x3180 loads 4 bytes from a0 (arg0 at entry) +0x28.
  The `lw` at 0x318c loads 4 bytes from a0 (arg0 at entry) +0x50.
  The `lw` at 0x3190 loads 4 bytes from a0 (arg0 at entry) +0x40.
  The `lw` at 0x3194 loads 4 bytes from a0 (arg0 at entry) +0x3c.
  The `lw` at 0x3198 loads 4 bytes from a0 (arg0 at entry) +0x38.
  The `jal` at 0x3158 calls qprintf with a0=sym(.rodata), a1=[a0], a2=[a0+14]:2, a3=[a0+28], a4=[a0+20], a5=[a0+16]:2.
  The `jal` at 0x316c calls qprintf with a0=sym(.rodata), a1=[a0+124], a2=[a0+128], a3=[a0+132].
  The `jal` at 0x3184 calls qprintf with a0=sym(.rodata), a1=[a0+40], a2=[a0+44], a3=[a0+48], a4=[a0+52].
  The `jal` at 0x319c calls qprintf with a0=sym(.rodata), a1=[a0+56], a2=[a0+60], a3=[a0+64], a4=[a0+80].
  The return at 0x31b0 has v0 = ret(qprintf).

- `mace_phystr` in `IP32/usr/cpu/sysgen/IP32boot/if_me.o` at 0x31b8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/if_me.o`.
  Range: 0x31b8-0x322c (116 bytes).
  It occupies 116 bytes.
  The `beq` branch at 0x31d0 targets 0x321c, is taken when a0 == at(=0x181440), and falls through when a0 != at(=0x181440).
  The `beq` branch at 0x31e8 targets 0x3224, is taken when a0 == v0(=0x15f41), and falls through when a0 != v0(=0x15f41).
  The `beq` branch at 0x31f0 targets 0x3224, is taken when a0 == a6(=0x15f42), and falls through when a0 != a6(=0x15f42).
  The `beq` branch at 0x3200 targets 0x3224, is taken when a0 == t1(=0x15f43), and falls through when a0 != t1(=0x15f43).
  The `beq` branch at 0x3208 targets 0x3224, is taken when a0 == t2(=0x20005c0), and falls through when a0 != t2(=0x20005c0).
  The return at 0x3214 has v0 = sym(.rodata)+112.
  The return at 0x3224 has v0 = one of sym(.rodata)+1616, sym(.rodata)+1608, sym(.rodata)+1600, sym(.rodata)+1592, sym(.rodata)+1624.

- `mace_dumpei` in `IP32/usr/cpu/sysgen/IP32boot/if_me.o` at 0x322c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/if_me.o`.
  Range: 0x322c-0x33c8 (412 bytes).
  It occupies 412 bytes.
  The `lw` at 0x3268 loads 4 bytes from a0 (arg0 at entry) +0x28c.
  The `lw` at 0x326c loads 4 bytes from a0 (arg0 at entry) +0x290.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x2ac, including `lw` at 0x3290, `lw` at 0x32ac.
  The `lb` at 0x3294 loads 1 byte from a0 (arg0 at entry) +0x2a9.
  The `lbu` at 0x3298 loads 1 byte from a0 (arg0 at entry) +0x2aa.
  The `lbu` at 0x32a0 loads 1 byte from a0 (arg0 at entry) +0x2ab.
  The `lw` at 0x32b0 loads 4 bytes from a0 (arg0 at entry) +0x2a4.
  The `lw` at 0x32b4 loads 4 bytes from a0 (arg0 at entry) +0x4b8.
  The `lw` at 0x32c0 loads 4 bytes from a0 (arg0 at entry) +0x530.
  The `lw` at 0x32c4 loads 4 bytes from a0 (arg0 at entry) +0x4c0.
  The `lw` at 0x32c8 loads 4 bytes from a0 (arg0 at entry) +0x52c.
  The `lw` at 0x32d4 loads 4 bytes from a0 (arg0 at entry) +0x53c.
  The `lw` at 0x32d8 loads 4 bytes from a0 (arg0 at entry) +0x538.
  The `lw` at 0x32dc loads 4 bytes from a0 (arg0 at entry) +0x534.
  The `lw` at 0x32e8 loads 4 bytes from a0 (arg0 at entry) +0x2b4.
  The `lh` at 0x32ec loads 2 bytes from a0 (arg0 at entry) +0x2b2.
  The `lh` at 0x32f0 loads 2 bytes from a0 (arg0 at entry) +0x2b0.
  The `lw` at 0x32fc loads 4 bytes from a0 (arg0 at entry) +0x548.
  The `lw` at 0x3300 loads 4 bytes from a0 (arg0 at entry) +0x544.
  The `lw` at 0x3304 loads 4 bytes from a0 (arg0 at entry) +0x540.
  The `lw` at 0x3310 loads 4 bytes from a0 (arg0 at entry) +0x550.
  The `lw` at 0x3314 loads 4 bytes from a0 (arg0 at entry) +0x54c.
  The `lw` at 0x3320 loads 4 bytes from a0 (arg0 at entry) +0x558.
  The `lw` at 0x3324 loads 4 bytes from a0 (arg0 at entry) +0x554.
  The `lw` at 0x3330 loads 4 bytes from a0 (arg0 at entry) +0x55c.
  The `lw` at 0x333c loads 4 bytes from a0 (arg0 at entry) +0x4dc.
  The `lw` at 0x3340 loads 4 bytes from a0 (arg0 at entry) +0x4d8.
  The `lw` at 0x3344 loads 4 bytes from a0 (arg0 at entry) +0x4d4.
  The `lw` at 0x3348 loads 4 bytes from a0 (arg0 at entry) +0x4d0.
  The `lw` at 0x334c loads 4 bytes from a0 (arg0 at entry) +0x4cc.
  The `lw` at 0x3350 loads 4 bytes from a0 (arg0 at entry) +0x4c8.
  The `lw` at 0x3354 loads 4 bytes from a0 (arg0 at entry) +0x4c4.
  The `lw` at 0x3358 loads 4 bytes from a0 (arg0 at entry) +0x4e0.
  The `lw` at 0x3368 loads 4 bytes from a0 (arg0 at entry) +0x578.
  The `lw` at 0x336c loads 4 bytes from a0 (arg0 at entry) +0x528.
  The `lh` at 0x3370 loads 2 bytes from a0 (arg0 at entry) +0x4e6.
  The `lh` at 0x3374 loads 2 bytes from a0 (arg0 at entry) +0x4e4.
  The `lw` at 0x3380 loads 4 bytes from a0 (arg0 at entry) +0x574.
  The `lw` at 0x3384 loads 4 bytes from a0 (arg0 at entry) +0x570.
  The `lw` at 0x3388 loads 4 bytes from a0 (arg0 at entry) +0x56c.
  The `lw` at 0x3394 loads 4 bytes from a0 (arg0 at entry) +0x564.
  The `lw` at 0x3398 loads 4 bytes from a0 (arg0 at entry) +0x560.
  The `lw` at 0x339c loads 4 bytes from a0 (arg0 at entry) +0x568.
  The `lw` at 0x33a8 loads 4 bytes from a0 (arg0 at entry) +0x590.
  The `jal` at 0x3240 calls ether_sprintf with a0=a0+168, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x3254 calls qprintf with a0=sym(.rodata), a1=ret(ether_sprintf), a2=?, a3=?.
  The `jal` at 0x3260 calls qprintf with a0=sym(.rodata), a1=a0+256, a2=?, a3=?.
  The `jal` at 0x3270 calls qprintf with a0=sym(.rodata), a1=[a0+656], a2=[a0+652], a3=?.
  The `jal` at 0x3284 calls mace_hexdump with a0=sym(.rodata)+2392, a1=a0+664, a2=0x8, a3=?.
  The `jal` at 0x328c calls mace_phystr with a0=[a0+684], a1=?, a2=?, a3=?.
  The `jal` at 0x32a8 calls qprintf with a0=sym(.rodata), a1=[a0+681]:1, a2=[a0+682]:1, a3=[a0+683]:1, a4=[a0+684], a5=ret(mace_phystr).
  The `jal` at 0x32b8 calls qprintf with a0=sym(.rodata), a1=[a0+1208], a2=[a0+676], a3=?.
  The `jal` at 0x32cc calls qprintf with a0=sym(.rodata), a1=[a0+1324], a2=[a0+1216], a3=[a0+1328].
  The `jal` at 0x32e0 calls qprintf with a0=sym(.rodata), a1=[a0+1332], a2=[a0+1336], a3=[a0+1340].
  The `jal` at 0x32f4 calls qprintf with a0=sym(.rodata), a1=[a0+688]:2, a2=[a0+690]:2, a3=[a0+692].
  The `jal` at 0x3308 calls qprintf with a0=sym(.rodata), a1=[a0+1344], a2=[a0+1348], a3=[a0+1352].
  The `jal` at 0x3318 calls qprintf with a0=sym(.rodata), a1=[a0+1356], a2=[a0+1360], a3=?.
  The `jal` at 0x3328 calls qprintf with a0=sym(.rodata), a1=[a0+1364], a2=[a0+1368], a3=?.
  The `jal` at 0x3334 calls qprintf with a0=sym(.rodata), a1=[a0+1372], a2=?, a3=?.
  The `jal` at 0x3360 calls qprintf with a0=sym(.rodata), a1=[a0+1220], a2=[a0+1224], a3=[a0+1228], a4=[a0+1232], a5=[a0+1236], a6=[a0+1240], a7=[a0+1244].
  The `jal` at 0x3378 calls qprintf with a0=sym(.rodata), a1=[a0+1252]:2, a2=[a0+1254]:2, a3=[a0+1320], a4=[a0+1400].
  The `jal` at 0x338c calls qprintf with a0=sym(.rodata), a1=[a0+1388], a2=[a0+1392], a3=[a0+1396].
  The `jal` at 0x33a0 calls qprintf with a0=sym(.rodata), a1=[a0+1384], a2=[a0+1376], a3=[a0+1380].
  The `jal` at 0x33ac calls qprintf with a0=sym(.rodata), a1=[a0+1424], a2=?, a3=?.
  The return at 0x33c0 has v0 = ret(qprintf).

- `mace_dumpregs` in `IP32/usr/cpu/sysgen/IP32boot/if_me.o` at 0x33c8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/if_me.o`.
  Range: 0x33c8-0x3510 (328 bytes).
  It occupies 328 bytes.
  The `lw` at 0x33e4 loads 4 bytes from a0 (arg0 at entry) +0x2a0.
  The `jal` at 0x33f8 calls qprintf with a0=sym(.rodata), a1=[a0+672], a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x3418 calls qprintf with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jal` at 0x3428 calls mace_hexconv with a0=?, a1=0x8, a2=0x0, a3=?.
  The `jal` at 0x3438 calls qprintf with a0=sym(.rodata)+2444, a1=ret(mace_hexconv), a2=?, a3=?.
  The `jal` at 0x3448 calls mace_hexconv with a0=?, a1=0x8, a2=0x0, a3=?.
  The `jal` at 0x3458 calls qprintf with a0=sym(.rodata)+2444, a1=ret(mace_hexconv), a2=?, a3=?.
  The `jal` at 0x3468 calls mace_hexconv with a0=?, a1=0x8, a2=0x0, a3=?.
  The `jal` at 0x3478 calls qprintf with a0=sym(.rodata)+2444, a1=ret(mace_hexconv), a2=?, a3=?.
  The `jal` at 0x3488 calls mace_hexconv with a0=?, a1=0x8, a2=0x0, a3=?.
  The `jal` at 0x3498 calls qprintf with a0=sym(.rodata)+2448, a1=ret(mace_hexconv), a2=?, a3=?.
  The `beq` branch at 0x340c targets 0x34fc and is always taken.
  The `beq` branch at 0x34c0 targets 0x34d8, is taken when s0(?) >= 0x20 (signed), and falls through when s0(?) < 0x20 (signed).
  The `bne` branch at 0x34c8 targets 0x3414, is taken when a3(?) != 0, and falls through when a3(?) == 0.
  The `beq` branch at 0x34d0 targets 0x3414 and is always taken.
  The `beq` branch at 0x3508 targets 0x34c8 and is always taken.
  The return at 0x34f4 has v0 = ret(qprintf).

- `mace_dumpphy` in `IP32/usr/cpu/sysgen/IP32boot/if_me.o` at 0x3510 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/if_me.o`.
  Range: 0x3510-0x3618 (264 bytes).
  It occupies 264 bytes.
  The `lbu` at 0x3520 loads 1 byte from a0 (arg0 at entry) +0x2ab.
  The `sb` at 0x353c stores 1 byte to a0 (arg0 at entry) +0x2ab.
  The `jal` at 0x3540 calls qprintf with a0=sym(.rodata), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x3570 calls mace_ether_mdio_rd with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x3584 calls mace_hexconv with a0=sp-48, a1=0x2, a2=0x0, a3=?.
  The `jal` at 0x3594 calls qprintf with a0=sym(.rodata)+2472, a1=ret(mace_hexconv), a2=?, a3=?.
  The `jal` at 0x35ac calls qprintf with a0=sym(.rodata)+2480, a1=?, a2=?, a3=?.
  The `jal` at 0x35e0 calls qprintf with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jal` at 0x35f8 calls qprintf with a0=sym(.rodata)+2480, a1=?, a2=?, a3=?.
  The `beq` branch at 0x354c targets 0x3564 and is always taken.
  The `beq` branch at 0x355c targets 0x35f0, is taken when s1(?) >= 0x20 (signed), and falls through when s1(?) < 0x20 (signed).
  The `beq` branch at 0x3564 targets 0x35bc, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `bne` branch at 0x35a4 targets 0x3554, is taken when s0(?) < 0x8 (signed), and falls through when s0(?) >= 0x8 (signed).
  The `beq` branch at 0x35b4 targets 0x3554 and is always taken.
  The `beq` branch at 0x35c0 targets 0x35d0, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x35c8 targets 0x35d4 and is always taken.
  The `beq` branch at 0x35e8 targets 0x3570 and is always taken.
  The `beq` branch at 0x35f0 targets 0x3600, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The return at 0x3610 has v0 = one of ?, ret(qprintf).

- `mace_ether_dump` in `IP32/usr/cpu/sysgen/IP32boot/if_me.o` at 0x3618 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/if_me.o`.
  Range: 0x3618-0x368c (116 bytes).
  It occupies 116 bytes.
  The `jal` at 0x3628 calls qprintf with a0=sym(.rodata)+2488, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x3638 calls mace_dumpif with a0=sym(.bss), a1=?, a2=?, a3=?.
  The `jal` at 0x3644 calls qprintf with a0=sym(.rodata)+2480, a1=?, a2=?, a3=?.
  The `jal` at 0x364c calls mace_dumpei with a0=sym(.bss), a1=?, a2=?, a3=?.
  The `jal` at 0x3658 calls qprintf with a0=sym(.rodata)+2480, a1=?, a2=?, a3=?.
  The `jal` at 0x3660 calls mace_dumpregs with a0=sym(.bss), a1=?, a2=?, a3=?.
  The `jal` at 0x366c calls qprintf with a0=sym(.rodata)+2480, a1=?, a2=?, a3=?.
  The `jal` at 0x3674 calls mace_dumpphy with a0=sym(.bss), a1=?, a2=?, a3=?.
  The return at 0x3684 has v0 = ret(mace_dumpphy).
