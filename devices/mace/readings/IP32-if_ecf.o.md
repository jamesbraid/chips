# Readings: `IP32/usr/cpu/sysgen/IP32boot/if_ecf.o`

One entry per routine, filed here from the reading batches by binary.

- `ecf_init` in `IP32/usr/cpu/sysgen/IP32boot/if_ecf.o` at 0x0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/if_ecf.o`.
  Range: 0x0-0xb4 (180 bytes).
  It occupies 180 bytes.
  The `lw` at 0x10 loads 4 bytes from a0 (arg0 at entry) +0xbc.
  The `lw` at 0x14 loads 4 bytes from [a0+188] +0x2f8.
  The `lw` at 0x44 loads 4 bytes from [a0+188] +0x2b4.
  The `sh` at 0x48 stores 2 bytes to [a0+188] +0x28a.
  The `sh` at 0x54 stores 2 bytes to [a0+188] +0x10.
  The `sw` at 0x5c stores 4 bytes to [a0+188] +0x3b0.
  The `jal` at 0xc calls ecf_reset with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1c calls ecf_new_rcvbuf with a0=[a0+188], a1=[[a0+188]+760], a2=[sym(ecf_max_rxds)], a3=?.
  The `jal` at 0x3c calls tlan_init with a0=[a0+188], a1=?, a2=?, a3=?.
  The `jal` at 0x94 calls ps_reinit with a0=[a0+188], a1=sp-48, a2=[sym(ecf_max_txds)], a3=sym(ecf_txfree_len), a4=sym(ecf_setstate).
  The `beq` branch at 0x24 targets 0x3c, is taken when v0(=ret(ecf_new_rcvbuf)) == 0, and falls through when v0(=ret(ecf_new_rcvbuf)) != 0.
  The `beq` branch at 0x60 targets 0xa4, is taken when (v1(=[[a0+188]+692]) & 0x2000) == 0, and falls through when (v1(=[[a0+188]+692]) & 0x2000) != 0.
  The `beq` branch at 0x9c targets 0x2c and is always taken.
  The `beq` branch at 0xac targets 0x6c and is always taken.
  The return at 0x34 has v0 = one of 0x0, 0x84.

- `ecf_reset` in `IP32/usr/cpu/sysgen/IP32boot/if_ecf.o` at 0xb4 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/if_ecf.o`.
  Range: 0xb4-0xfc (72 bytes).
  It occupies 72 bytes.
  The `lw` at 0xbc loads 4 bytes from a0 (arg0 at entry) +0xbc.
  The `sh` at 0xc4 stores 2 bytes to [a0+188] +0x10.
  The `lw` at 0xd0 loads 4 bytes from [a0+188] +0x370.
  The `jal` at 0xcc calls pciio_pio_write32 with a0=0x8000, a1=[[a0+188]+880], a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xd8 calls ecf_reset_fdr with a0=[a0+188], a1=0x0, a2=?, a3=?.
  The `jal` at 0xe4 calls ecf_reset_fdr with a0=[a0+188], a1=0x1, a2=?, a3=?.
  The return at 0xf4 has v0 = ret(ecf_reset_fdr).

- `ecf_reset_fdr` in `IP32/usr/cpu/sysgen/IP32boot/if_ecf.o` at 0xfc (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/if_ecf.o`.
  Range: 0xfc-0x330 (564 bytes).
  It occupies 564 bytes.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x2f8, including `lw` at 0x12c, `lw` at 0x1cc, `lw` at 0x1d4.
  16 such `sw` accesses store 4 bytes to ?, including `sw` at 0x150, `sw` at 0x16c, `sw` at 0x178.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x3a8, including `lw` at 0x160, `lw` at 0x264.
  4 such `sh` accesses store 2 bytes to ?, including `sh` at 0x170, `sh` at 0x174, `sh` at 0x274.
  The `lw` at 0x180 loads 4 bytes from a0 (arg0 at entry) +0x2fc.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0x18c, `lw` at 0x2bc.
  The `sw` at 0x1e0 stores 4 bytes to a0 (arg0 at entry) +0x2fc.
  The `sw` at 0x1e8 stores 4 bytes to a0 (arg0 at entry) +0x314.
  The `sw` at 0x200 stores 4 bytes to (a0 + one of 0x2d8, 0x30c) +0x0.
  The `sw` at 0x204 stores 4 bytes to (a0 + one of 0x2d4, 0x308) +0x0.
  The `sw` at 0x208 stores 4 bytes to (a0 + one of 0x2d0, 0x304) +0x0.
  The `sw` at 0x20c stores 4 bytes to (a0 + one of 0x2cc, 0x300) +0x0.
  The `sw` at 0x210 stores 4 bytes to (a0 + one of 0x2e4, 0x318) +0x0.
  The `lw` at 0x218 loads 4 bytes from (a0 + one of 0x2c4, 0x2f8) +0x0.
  The `sw` at 0x21c stores 4 bytes to (a0 + one of 0x2dc, 0x310) +0x0.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x2c4, including `lw` at 0x238, `lw` at 0x2fc, `lw` at 0x304.
  The `lw` at 0x2b0 loads 4 bytes from a0 (arg0 at entry) +0x2c8.
  The `sw` at 0x310 stores 4 bytes to a0 (arg0 at entry) +0x2c8.
  The `sw` at 0x31c stores 4 bytes to a0 (arg0 at entry) +0x2e0.
  The `jal` at 0x14c calls kvtophys with a0=?, a1=[sym(ecf_max_rxds)]-1, a2=?, a3=?.
  The `jal` at 0x164 calls pciio_dmatrans_addr with a0=[a0+936], a1=0x0, a2=ret(kvtophys), a3=0x4, a4=0x2000.
  The `jal` at 0x198 calls m_freem with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x250 calls kvtophys with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x268 calls pciio_dmatrans_addr with a0=[a0+936], a1=0x0, a2=ret(kvtophys), a3=0x4, a4=0x2000.
  The `jal` at 0x2c8 calls m_freem with a0=?, a1=?, a2=?, a3=?.
  The `beq` branch at 0x120 targets 0x22c, is taken when a1 == at(=0x1), and falls through when a1 != at(=0x1).
  The `beq` branch at 0x13c targets 0x1d0, is taken when a0(=[sym(ecf_max_rxds)]) == 0, and falls through when a0(=[sym(ecf_max_rxds)]) != 0.
  The `beq` branch at 0x144 targets 0x320 and is always taken.
  The `beq` branch at 0x184 targets 0x1a0, is taken when v0(=[a0+764]) == 0, and falls through when v0(=[a0+764]) != 0.
  The `beq` branch at 0x190 targets 0x1a0, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x1b8 targets 0x1d0, is taken when s2(?) >= a0(=[sym(ecf_max_rxds)]) (unsigned), and falls through when s2(?) < a0(=[sym(ecf_max_rxds)]) (unsigned).
  The `bne` branch at 0x1c0 targets 0x14c, is taken when s2(?) != a1(=[sym(ecf_max_rxds)]-1), and falls through when s2(?) == a1(=[sym(ecf_max_rxds)]-1).
  The `beq` branch at 0x1c8 targets 0x14c and is always taken.
  The `beq` branch at 0x23c targets 0x300, is taken when a0(=[sym(ecf_max_txds)]) == 0, and falls through when a0(=[sym(ecf_max_txds)]) != 0.
  The `beq` branch at 0x248 targets 0x328 and is always taken.
  The `beq` branch at 0x294 targets 0x2b0, is taken when a3(?) >= 0xa (unsigned), and falls through when a3(?) < 0xa (unsigned).
  The `bne` branch at 0x2a8 targets 0x284, is taken when a3(?) < 0xa (unsigned), and falls through when a3(?) >= 0xa (unsigned).
  The `beq` branch at 0x2b4 targets 0x2d0, is taken when t0(=[a0+712]) == 0, and falls through when t0(=[a0+712]) != 0.
  The `beq` branch at 0x2c0 targets 0x2d0, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x2e8 targets 0x300, is taken when s2(?) >= a0(=[sym(ecf_max_txds)]) (unsigned), and falls through when s2(?) < a0(=[sym(ecf_max_txds)]) (unsigned).
  The `bne` branch at 0x2f0 targets 0x250, is taken when s2(?) != t2(=[sym(ecf_max_txds)]-1), and falls through when s2(?) == t2(=[sym(ecf_max_txds)]-1).
  The `beq` branch at 0x2f8 targets 0x250 and is always taken.
  The `beq` branch at 0x318 targets 0x1ec and is always taken.
  The `beq` branch at 0x320 targets 0x1c0 and is always taken.
  The `beq` branch at 0x328 targets 0x2f0 and is always taken.
  The return at 0x224 has v0 = ?.

- `if_ecfintr` in `IP32/usr/cpu/sysgen/IP32boot/if_ecf.o` at 0x330 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/if_ecf.o`.
  Range: 0x330-0xb8c (2140 bytes).
  It occupies 2140 bytes.
  The `lw` at 0x360 loads 4 bytes from a1 (arg1 at entry) +0x3b0.
  The `sw` at 0x378 stores 4 bytes to a1 (arg1 at entry) +0x3b0.
  2 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x14, including `lw` at 0x37c, `lw` at 0xb88.
  The `lw` at 0x390 loads 4 bytes from a1 (arg1 at entry) +0x2c4.
  7 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x370, including `lw` at 0x3f4, `lw` at 0x400, `lw` at 0x41c.
  The `lw` at 0x444 loads 4 bytes from table(sym(.rodata)+312) +0x0.
  The `jal` at 0x358 calls mutex_lock with a0=a1+152, a1=0x19, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x39c calls ether_stop with a0=a1 at entry (arg1), a1=[a1+20], a2=0x41, a3=?.
  The `jal` at 0x3a4 calls mutex_unlock with a0=a1+152, a1=?, a2=?, a3=?.
  The `jal` at 0x3f8 calls pciio_pio_write32 with a0=0x800, a1=[a1+880], a2=0x41, a3=[a1+708].
  The `jal` at 0x404 calls pciio_pio_read16 with a0=[a1+880]+8, a1=?, a2=?, a3=?.
  The `jal` at 0x424 calls pciio_pio_write16 with a0=?, a1=[a1+880]+8, a2=[a1+880], a3=?.
  The `jal` at 0x464 calls pciio_pio_write32 with a0=((ret(pciio_pio_read16) << 0x10) | 0x20000000), a1=[a1+880], a2=0x20000000, a3=?.
  The `jal` at 0x46c calls pciio_pio_read32 with a0=[a1+880], a1=?, a2=?, a3=?.
  The `jal` at 0x478 calls pciio_pio_write32 with a0=(ret(pciio_pio_read32) | 0x400), a1=[a1+880], a2=?, a3=?.
  The `jal` at 0x480 calls mutex_unlock with a0=a1+152, a1=?, a2=?, a3=?.
  The `jal` at 0x490 calls pciio_pio_read32 with a0=[a1+880], a1=?, a2=[a1+880], a3=?.
  The `jal` at 0x49c calls pciio_pio_write32 with a0=(ret(pciio_pio_read32) | 0x400), a1=[a1+880], a2=?, a3=?.
  The `jal` at 0x4a4 calls mutex_unlock with a0=a1+152, a1=?, a2=?, a3=?.
  The `jal` at 0x4d0 calls nano_delay with a0=sym(.sbss), a1=?, a2=?, a3=?, a5=[sym(ecf_intr_count)].
  The `jal` at 0xb60 calls absolute_rtc_current_time with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xb7c calls randproc_input with a0=?, a1=0x500000000, a2=?, a3=?.
  The `beq` branch at 0x374 targets 0xb60, is taken when v1(=[a1+944]+1) >= 0x63 (unsigned), and falls through when v1(=[a1+944]+1) < 0x63 (unsigned).
  The `bne` branch at 0x388 targets 0x39c, is taken when a0(?) != a2(=0x41), and falls through when a0(?) == a2(=0x41).
  The `bne` branch at 0x394 targets 0x3f4, is taken when a3(=[a1+708]) != 0, and falls through when a3(=[a1+708]) == 0.
  The `beq` branch at 0x3b0 targets 0x3dc, is taken when a1(=[sym(ecf_intr_sleep_delay)]) == 0, and falls through when a1(=[sym(ecf_intr_sleep_delay)]) != 0.
  The `beq` branch at 0x3bc targets 0x3dc, is taken when v0(=[sym(ecf_intr_sleep_interval)]) == 0, and falls through when v0(=[sym(ecf_intr_sleep_interval)]) != 0.
  The `beq` branch at 0x3d0 targets 0x4b4, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0x418 targets 0x490, is taken when (s1(?) & 0x7) == 0, and falls through when (s1(?) & 0x7) != 0.
  The `beq` branch at 0x43c targets 0x450, is taken when s1(?) >= 0x8 (unsigned), and falls through when s1(?) < 0x8 (unsigned).
  The `beq` branch at 0x488 targets 0x3b0 and is always taken.
  The `beq` branch at 0x4ac targets 0x3b0 and is always taken.
  The `beq` branch at 0x4d8 targets 0x3dc and is always taken.
  The `beq` branch at 0xb84 targets 0x380 and is always taken.
  The return at 0x3ec has v0 = one of ret(mutex_unlock), [sym(ecf_intr_sleep_interval)], ret(nano_delay).
  The instructions from 0x4e0 to 0xb5c are not reached by any path from the entry, and their branches are not listed.
  The indirect jump at 0x448 uses a jump table whose successors are unresolved.

- `ecf_new_rcvbuf` in `IP32/usr/cpu/sysgen/IP32boot/if_ecf.o` at 0xb8c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/if_ecf.o`.
  Range: 0xb8c-0xd18 (396 bytes).
  It occupies 396 bytes.
  7 such `sw` accesses store 4 bytes to ?, including `sw` at 0xbe8, `sw` at 0xc04, `sw` at 0xc1c.
  3 such `lw` accesses load 4 bytes from ?, including `lw` at 0xbf4, `lw` at 0xc8c, `lw` at 0xc90.
  3 such `sh` accesses store 2 bytes to ?, including `sh` at 0xc00, `sh` at 0xc0c, `sh` at 0xc10.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x3a8, including `lw` at 0xc2c, `lw` at 0xc70.
  The `jal` at 0xc18 calls kvtophys with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xc30 calls pciio_dmatrans_addr with a0=[a0+936], a1=0x0, a2=ret(kvtophys), a3=0x4, a4=0x1000.
  The `jal` at 0xc40 calls __vm_dcache_wb_inval with a0=?, a1=0x28, a2=?, a3=?.
  The `jal` at 0xc4c calls __vm_dcache_inval with a0=?, a1=0x5dc, a2=?, a3=?.
  The `jal` at 0xc5c calls kvtophys with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xc74 calls pciio_dmatrans_addr with a0=[a0+936], a1=0x0, a2=ret(kvtophys), a3=0x4, a4=0x2000.
  The `jal` at 0xca8 calls m_vget with a0=0x0, a1=0x604, a2=0x1, a3=?.
  The `beq` branch at 0xbc8 targets 0xccc, is taken when a2 == 0, and falls through when a2 != 0.
  The `beq` branch at 0xbe0 targets 0xc90 and is always taken.
  The `beq` branch at 0xc54 targets 0xc80, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `beq` branch at 0xc88 targets 0xcd4, is taken when s4(?) == 0, and falls through when s4(?) != 0.
  The `beq` branch at 0xc94 targets 0xca0, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `bne` branch at 0xc9c targets 0xbf4, is taken when s7(=0x1) != s6(=a2), and falls through when s7(=0x1) == s6(=a2).
  The `bne` branch at 0xcb4 targets 0xbf4, is taken when v0(=ret(m_vget)) != 0, and falls through when v0(=ret(m_vget)) == 0.
  The `beq` branch at 0xcbc targets 0xbe8, is taken when s7(=0x1) == s6(=a2), and falls through when s7(=0x1) != s6(=a2).
  The `beq` branch at 0xcc4 targets 0xce8 and is always taken.
  The `beq` branch at 0xcdc targets 0xce8, is taken when t8(=one of 0x0, 0x1) == 0, and falls through when t8(=one of 0x0, 0x1) != 0.
  The return at 0xd10 has v0 = one of 0x0, 0x84.

- `ecf_transmit` in `IP32/usr/cpu/sysgen/IP32boot/if_ecf.o` at 0xd18 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/if_ecf.o`.
  Range: 0xd18-0x11c4 (1196 bytes).
  It occupies 1196 bytes.
  The `lw` at 0xd38 loads 4 bytes from a0 (arg0 at entry) +0xbc.
  2 such `lw` accesses load 4 bytes from [a0+188] +0x2e0, including `lw` at 0xd40, `lw` at 0x102c.
  The `lbu` at 0xd60 loads 1 byte from a4 (arg4 at entry) +0xe.
  The `lw` at 0xd64 loads 4 bytes from [a0+188] +0x2dc.
  The `lw` at 0xd80 loads 4 bytes from a4 (arg4 at entry) +0x4.
  The `lhu` at 0xd94 loads 2 bytes from a4 (arg4 at entry) +0xc.
  The `sw` at 0xd9c stores 4 bytes to a4 (arg4 at entry) +0x4.
  The `sh` at 0xda8 stores 2 bytes to a4 (arg4 at entry) +0xc.
  The `lw` at 0xdc0 loads 4 bytes from ret(m_get) +0x4.
  The `sh` at 0xdd0 stores 2 bytes to ret(m_get) +0xc.
  The `sw` at 0xdd4 stores 4 bytes to ret(m_get) +0x0.
  The `lwl` at 0xde0 loads 4 bytes from a1 (arg1 at entry) +0x0.
  The `lwr` at 0xdec loads 4 bytes from a1 (arg1 at entry) +0x3.
  2 such `swl` accesses store 4 bytes to ?, including `swl` at 0xdf0, `swl` at 0xe14.
  2 such `swr` accesses store 4 bytes to ?, including `swr` at 0xdf4, `swr` at 0xe18.
  The `lbu` at 0xdf8 loads 1 byte from a1 (arg1 at entry) +0x4.
  4 such `sb` accesses store 1 byte to ?, including `sb` at 0xdfc, `sb` at 0xe04, `sb` at 0xe20.
  The `lbu` at 0xe00 loads 1 byte from a1 (arg1 at entry) +0x5.
  The `lwl` at 0xe08 loads 4 bytes from a2 (arg2 at entry) +0x0.
  The `lwr` at 0xe10 loads 4 bytes from a2 (arg2 at entry) +0x3.
  The `lbu` at 0xe1c loads 1 byte from a2 (arg2 at entry) +0x4.
  The `lbu` at 0xe24 loads 1 byte from a2 (arg2 at entry) +0x5.
  2 such `sh` accesses store 2 bytes to ?, including `sh` at 0xe28, `sh` at 0xe48.
  8 such `lw` accesses load 4 bytes from ?, including `lw` at 0xe30, `lw` at 0xe78, `lw` at 0xee0.
  6 such `lhu` accesses load 2 bytes from ?, including `lhu` at 0xe34, `lhu` at 0xee4, `lhu` at 0xef0.
  6 such `sw` accesses store 4 bytes to ?, including `sw` at 0xe50, `sw` at 0xe9c, `sw` at 0xed8.
  3 such `lw` accesses load 4 bytes from [a0+188] +0x3a8, including `lw` at 0xeb4, `lw` at 0x1064, `lw` at 0x1150.
  The `lw` at 0xf64 loads 4 bytes from ret(m_vget) +0x4.
  The `lbu` at 0xfa0 loads 1 byte from [a0+188] +0x13e.
  The `sh` at 0xffc stores 2 bytes to [[a0+188]+732] +0x4.
  The `sh` at 0x1004 stores 2 bytes to [[a0+188]+732] +0x6.
  The `sw` at 0x1008 stores 4 bytes to [[a0+188]+732] +0x5c.
  The `lw` at 0x101c loads 4 bytes from [[a0+188]+732] +0x58.
  The `sw` at 0x1020 stores 4 bytes to [[a0+188]+732] +0x0.
  The `sw` at 0x1024 stores 4 bytes to [a0+188] +0x2dc.
  The `lw` at 0x1028 loads 4 bytes from [a0+188] +0x40.
  The `sw` at 0x1034 stores 4 bytes to [a0+188] +0x40.
  The `sw` at 0x1040 stores 4 bytes to [a0+188] +0x2e0.
  2 such `lw` accesses load 4 bytes from [a0+188] +0x2d4, including `lw` at 0x1044, `lw` at 0x111c.
  The `lw` at 0x1070 loads 4 bytes from [a0+188] +0x2d8.
  The `sw` at 0x1078 stores 4 bytes to [[a0+188]+728] +0x0.
  2 such `sw` accesses store 4 bytes to [a0+188] +0x2d4, including `sw` at 0x1080, `sw` at 0x112c.
  The `sw` at 0x1090 stores 4 bytes to [a0+188] +0x2d8.
  The `lw` at 0x1094 loads 4 bytes from [a0+188] +0x2e4.
  The `sw` at 0x1128 stores 4 bytes to [a0+188] +0x2e4.
  The `sw` at 0x1130 stores 4 bytes to [a0+188] +0x2cc.
  The `sw` at 0x1138 stores 4 bytes to abs 0xffffffffbf08000c.
  The `lw` at 0x1140 loads 4 bytes from [a0+188] +0x2cc.
  2 such `lw` accesses load 4 bytes from [a0+188] +0x370, including `lw` at 0x115c, `lw` at 0x116c.
  The `lw` at 0x11a8 loads 4 bytes from [a0+188] +0x360.
  The `sw` at 0x11b8 stores 4 bytes to [a0+188] +0x360.
  The `jal` at 0xdb0 calls m_get with a0=0x0, a1=0x1, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xe90 calls min with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xea0 calls kvtophys with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xeb8 calls pciio_dmatrans_addr with a0=[[a0+188]+936], a1=0x0, a2=ret(kvtophys), a3=0x4, a4=0x1000.
  The `jal` at 0xee8 calls __dcache_wb with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xf50 calls m_vget with a0=0x0, a1=?, a2=0x1, a3=?.
  The `jal` at 0xf70 calls m_datacopy with a0=?, a1=0x0, a2=?, a3=([ret(m_vget)+4] + ret(m_vget)).
  The `jal` at 0xf7c calls m_freem with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xfbc calls snoop_match with a0=[a0+188]+256, a1=?, a2=?, a3=?, a5=[[a0+188]+318]:1.
  The `jal` at 0x103c calls splhi with a0=?, a1=?, a2=?, a3=?, a5=[[a0+188]+736]-1, a7=[[[a0+188]+732]+88].
  The `jal` at 0x1050 calls kvtophys with a0=[[a0+188]+732], a1=?, a2=?, a3=?.
  The `jal` at 0x1068 calls pciio_dmatrans_addr with a0=[[a0+188]+936], a1=0x0, a2=ret(kvtophys), a3=0x4, a4=0x2000.
  The `jal` at 0x108c calls splx with a0=ret(splhi), a1=?, a2=?, a3=?.
  The `jal` at 0x10ec calls ether_selfsnoop with a0=[a0+188], a1=?, a2=?, a3=0xe.
  The `jal` at 0x10fc calls m_freem with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x110c calls splhi with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x113c calls kvtophys with a0=[[a0+188]+716], a1=0xffffffffbf080000, a2=?, a3=?.
  The `jal` at 0x1154 calls pciio_dmatrans_addr with a0=[[a0+188]+936], a1=0x0, a2=ret(kvtophys), a3=0x4, a4=0x2000.
  The `jal` at 0x1164 calls pciio_pio_write32 with a0=ret(pciio_dmatrans_addr), a1=[[a0+188]+880]+4, a2=?, a3=?.
  The `jal` at 0x1170 calls pciio_pio_write32 with a0=0xffffffff80100000, a1=[[a0+188]+880], a2=?, a3=?.
  The `jal` at 0x1178 calls splx with a0=ret(splhi), a1=?, a2=?, a3=?.
  The `jal` at 0x1188 calls m_freem with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1198 calls m_freem with a0=a4 at entry (arg4), a1=?, a2=?, a3=?.
  The `jal` at 0x11b4 calls m_freem with a0=a4 at entry (arg4), a1=a1 at entry (arg1), a2=[[a0+188]+864]+1, a3=a3 at entry (arg3), a7=a2 at entry (arg2).
  The `beq` branch at 0xd54 targets 0x11a8, is taken when at(=[[a0+188]+736]) == 0, and falls through when at(=[[a0+188]+736]) != 0.
  The `bne` branch at 0xd74 targets 0xdac, is taken when (v1(=[a4+14]:1) & 0x1) != 0, and falls through when (v1(=[a4+14]:1) & 0x1) == 0.
  The `bne` branch at 0xd88 targets 0xdb0, is taken when a7(=[a4+4]) < 0x20 (signed), and falls through when a7(=[a4+4]) >= 0x20 (signed).
  The `beq` branch at 0xda4 targets 0xdd8 and is always taken.
  The `beq` branch at 0xdb8 targets 0x1198, is taken when v0(=ret(m_get)) == 0, and falls through when v0(=ret(m_get)) != 0.
  The `beq` branch at 0xe54 targets 0xf98, is taken when t3(?) == 0, and falls through when t3(?) != 0.
  The `beq` branch at 0xe70 targets 0xf08 and is always taken.
  The `beq` branch at 0xe80 targets 0xee0, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `bne` branch at 0xed4 targets 0xe88, is taken when s1(?) != 0, and falls through when s1(?) == 0.
  The `beq` branch at 0xf00 targets 0xfa0, is taken when s7(?) == 0, and falls through when s7(?) != 0.
  The `beq` branch at 0xf10 targets 0xefc, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `bne` branch at 0xf1c targets 0xf88, is taken when s3(?) < 0x9 (unsigned), and falls through when s3(?) >= 0x9 (unsigned).
  The `beq` branch at 0xf28 targets 0xf88, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0xf30 targets 0x10d0, is taken when s7(?) == 0, and falls through when s7(?) != 0.
  The `bne` branch at 0xf40 targets 0xf38, is taken when s7(?) != 0, and falls through when s7(?) == 0.
  The `beq` branch at 0xf58 targets 0x10fc, is taken when v0(=ret(m_vget)) == 0, and falls through when v0(=ret(m_vget)) != 0.
  The `bne` branch at 0xf88 targets 0xe78, is taken when a4(?) != s7(?), and falls through when a4(?) == s7(?).
  The `beq` branch at 0xf90 targets 0xe80 and is always taken.
  The `beq` branch at 0xfa4 targets 0xfc8, is taken when a5(=[[a0+188]+318]:1) == 0, and falls through when a5(=[[a0+188]+318]:1) != 0.
  The `bne` branch at 0xfc4 targets 0x10dc, is taken when v0(=ret(snoop_match)) != 0, and falls through when v0(=ret(snoop_match)) == 0.
  The `beq` branch at 0xfcc targets 0x1188, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `blez` branch at 0xfd8 targets 0xff4, is taken when a3(?) <= 0 (signed), and falls through when a3(?) > 0 (signed).
  The `beq` branch at 0x1048 targets 0x107c, is taken when t9(=[[a0+188]+724]) == 0, and falls through when t9(=[[a0+188]+724]) != 0.
  The `beq` branch at 0x1074 targets 0x1084 and is always taken.
  The `beq` branch at 0x1098 targets 0x110c, is taken when v1(=[[a0+188]+740]) == 0, and falls through when v1(=[[a0+188]+740]) != 0.
  The `beq` branch at 0x10d4 targets 0xf48 and is always taken.
  The `beq` branch at 0x10f4 targets 0xfcc and is always taken.
  The `beq` branch at 0x1104 targets 0x10a0 and is always taken.
  The `beq` branch at 0x1114 targets 0x109c, is taken when v0(=ret(splhi)) == 0, and falls through when v0(=ret(splhi)) != 0.
  The `beq` branch at 0x1120 targets 0x1178, is taken when a1(=[[a0+188]+724]) == 0, and falls through when a1(=[[a0+188]+724]) != 0.
  The `beq` branch at 0x1180 targets 0x10a0 and is always taken.
  The `beq` branch at 0x1190 targets 0x10a0 and is always taken.
  The `beq` branch at 0x11a0 targets 0x10a0 and is always taken.
  The `beq` branch at 0x11bc targets 0x10a0 and is always taken.
  The return at 0x10c8 has v0 = one of 0x0, 0x84.

- `ecf_lafhash` in `IP32/usr/cpu/sysgen/IP32boot/if_ecf.o` at 0x11c4 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/if_ecf.o`.
  Range: 0x11c4-0x1250 (140 bytes).
  It occupies 140 bytes.
  The `lbu` at 0x11c4 loads 1 byte from a0 (arg0 at entry) +0x3.
  The `lbu` at 0x11c8 loads 1 byte from a0 (arg0 at entry) +0x4.
  The `lbu` at 0x11cc loads 1 byte from a0 (arg0 at entry) +0x2.
  The `lbu` at 0x11e0 loads 1 byte from a0 (arg0 at entry) +0x1.
  The `lbu` at 0x11ec loads 1 byte from a0 (arg0 at entry) +0x0.
  The `lbu` at 0x1210 loads 1 byte from a0 (arg0 at entry) +0x5.
  The return at 0x1248 has v0 = ?.

- `ecf_ioctl` in `IP32/usr/cpu/sysgen/IP32boot/if_ecf.o` at 0x1250 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/if_ecf.o`.
  Range: 0x1250-0x13d8 (392 bytes).
  It occupies 392 bytes.
  The `lw` at 0x1250 loads 4 bytes from a2 (arg2 at entry) +0x0.
  The `lw` at 0x1278 loads 4 bytes from a0 (arg0 at entry) +0xbc.
  2 such `lhu` accesses load 2 bytes from a2 (arg2 at entry) +0x4, including `lhu` at 0x12b4, `lhu` at 0x1364.
  The `sh` at 0x12dc stores 2 bytes to a2 (arg2 at entry) +0x4.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0x12e8, `lw` at 0x137c.
  2 such `lw` accesses load 4 bytes from [a0+188] +0x3a0, including `lw` at 0x12fc, `lw` at 0x1320.
  2 such `sw` accesses store 4 bytes to [a0+188] +0x3a0, including `sw` at 0x1304, `sw` at 0x132c.
  2 such `sw` accesses store 4 bytes to ?, including `sw` at 0x1330, `sw` at 0x1388.
  2 such `lw` accesses load 4 bytes from [a0+188] +0x390, including `lw` at 0x1334, `lw` at 0x138c.
  2 such `lw` accesses load 4 bytes from [a0+188] +0x14, including `lw` at 0x1338, `lw` at 0x1394.
  2 such `sw` accesses store 4 bytes to [a0+188] +0x390, including `sw` at 0x134c, `sw` at 0x139c.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x14, including `lw` at 0x1358, `lw` at 0x13b0.
  2 such `sw` accesses store 4 bytes to [a0+188] +0x14, including `sw` at 0x13c4, `sw` at 0x13d4.
  The `jal` at 0x12ac calls ecf_lafhash with a0=[a2]+2, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a5=0x16, a6=0xffffffff80206932.
  The `jal` at 0x12c8 calls ecf_lafhash with a0=[a2]+2, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a5=0x16, a6=0xffffffff80206932.
  The `jal` at 0x1310 calls mfhasvalue with a0=a0+204, a1=[a2+4]:2, a2=?, a3=?, a5=0x16.
  The `jal` at 0x1354 calls ecf_init with a0=a0 at entry (arg0), a1=[a0+20], a2=?, a3=?, a5=[[a0+188]+912], a6=[[a0+188]+912]+1.
  The `jal` at 0x13ac calls ecf_init with a0=a0 at entry (arg0), a1=[a0+20], a2=?, a3=?.
  The `beq` branch at 0x1280 targets 0x12c8, is taken when a1 == at(=0xffffffff80206931), and falls through when a1 != at(=0xffffffff80206931).
  The `beq` branch at 0x1288 targets 0x12ac, is taken when a1 == a6(=0xffffffff80206932), and falls through when a1 != a6(=0xffffffff80206932).
  The `beq` branch at 0x12b8 targets 0x1310, is taken when v0(=ret(ecf_lafhash)) == a1(=[a2+4]:2), and falls through when v0(=ret(ecf_lafhash)) != a1(=[a2+4]:2).
  The `beq` branch at 0x12c0 targets 0x1294 and is always taken.
  The `beq` branch at 0x12f4 targets 0x1330, is taken when (a2(?) & a0(?)) == 0, and falls through when (a2(?) & a0(?)) != 0.
  The `beq` branch at 0x1308 targets 0x1290 and is always taken.
  The `beq` branch at 0x1318 targets 0x1364, is taken when v0(=ret(mfhasvalue)) == 0, and falls through when v0(=ret(mfhasvalue)) != 0.
  The `beq` branch at 0x1328 targets 0x1308 and is always taken.
  The `beq` branch at 0x133c targets 0x13bc, is taken when a5(=[[a0+188]+912]) == 0, and falls through when a5(=[[a0+188]+912]) != 0.
  The `bne` branch at 0x1348 targets 0x1308, is taken when (v0(?) & 0x300) != 0, and falls through when (v0(?) & 0x300) == 0.
  The `beq` branch at 0x135c targets 0x1308 and is always taken.
  The `beq` branch at 0x1398 targets 0x13c8, is taken when t0(=[[a0+188]+912]-1) == 0, and falls through when t0(=[[a0+188]+912]-1) != 0.
  The `bne` branch at 0x13a4 targets 0x1308, is taken when (v0(?) & 0x300) != 0, and falls through when (v0(?) & 0x300) == 0.
  The `beq` branch at 0x13b4 targets 0x1308 and is always taken.
  The `beq` branch at 0x13c0 targets 0x1344 and is always taken.
  The `beq` branch at 0x13d0 targets 0x13a0 and is always taken.
  The return at 0x12a4 has v0 = one of 0x0, 0x16.

- `ecf_watchdog` in `IP32/usr/cpu/sysgen/IP32boot/if_ecf.o` at 0x13d8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/if_ecf.o`.
  Range: 0x13d8-0x14b0 (216 bytes).
  It occupies 216 bytes.
  The `lw` at 0x13e0 loads 4 bytes from a0 (arg0 at entry) +0xbc.
  The `lw` at 0x1400 loads 4 bytes from [a0+188] +0x2bc.
  2 such `sw` accesses store 4 bytes to [a0+188] +0x2bc, including `sw` at 0x1410, `sw` at 0x1498.
  The `lh` at 0x143c loads 2 bytes from [a0+188] +0x28a.
  The `lw` at 0x1450 loads 4 bytes from [a0+188] +0x380.
  The `sh` at 0x145c stores 2 bytes to [a0+188] +0x28a.
  The `sh` at 0x1468 stores 2 bytes to [a0+188] +0x10.
  The `lh` at 0x1488 loads 2 bytes from [a0+188] +0xe.
  The `lw` at 0x14a4 loads 4 bytes from [a0+188] +0x14.
  The `jal` at 0x13f0 calls tlan_statistics with a0=[a0+188], a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x13f8 calls tlan_phystatus with a0=[a0+188], a1=?, a2=?, a3=?.
  The `jal` at 0x1418 calls mutex_unlock with a0=a0+152, a1=?, a2=?, a3=?.
  The `jal` at 0x1428 calls if_ecfintr with a0=0x0, a1=[a0+188], a2=?, a3=?.
  The `jal` at 0x1434 calls mutex_lock with a0=a0+152, a1=0x19, a2=?, a3=?.
  The `jal` at 0x148c calls cmn_err_tag with a0=0xc4, a1=0x1, a2=sym(.rodata), a3=sym(.rodata), a4=[[a0+188]+14]:2, a5=[[a0+188]+700].
  The `jal` at 0x14a0 calls ecf_init with a0=[a0+188], a1=[[a0+188]+20], a2=?, a3=?.
  The `beq` branch at 0x1408 targets 0x1478, is taken when a5(=[[a0+188]+700]) >= 0x2 (unsigned), and falls through when a5(=[[a0+188]+700]) < 0x2 (unsigned).
  The `beq` branch at 0x1448 targets 0x149c, is taken when a1(=[[a0+188]+650]:2) >= 0x2 (signed), and falls through when a1(=[[a0+188]+650]:2) < 0x2 (signed).
  The `beq` branch at 0x1454 targets 0x1464, is taken when v1(=[[a0+188]+896]) == 0, and falls through when v1(=[[a0+188]+896]) != 0.
  The `beq` branch at 0x1494 targets 0x1414 and is always taken.
  The `beq` branch at 0x14a8 targets 0x1464 and is always taken.
  The return at 0x1470 has v0 = one of ?, ret(ecf_init).

- `tlan_init` in `IP32/usr/cpu/sysgen/IP32boot/if_ecf.o` at 0x14b0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/if_ecf.o`.
  Range: 0x14b0-0x18bc (1036 bytes).
  It occupies 1036 bytes.
  35 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x370, including `lw` at 0x14c8, `lw` at 0x14d0, `lw` at 0x14d4.
  The `sw` at 0x14e4 stores 4 bytes to a0 (arg0 at entry) +0x2c0.
  The `sw` at 0x14f0 stores 4 bytes to a0 (arg0 at entry) +0x2ac.
  The `lw` at 0x14f8 loads 4 bytes from a0 (arg0 at entry) +0x2a8.
  2 such `lh` accesses load 2 bytes from a0 (arg0 at entry) +0xe, including `lh` at 0x1524, `lh` at 0x18a8.
  The `sw` at 0x153c stores 4 bytes to a0 (arg0 at entry) +0x2b8.
  The `sw` at 0x1540 stores 4 bytes to a0 (arg0 at entry) +0x2b4.
  3 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x2af, including `lbu` at 0x15a8, `lbu` at 0x15c4, `lbu` at 0x15dc.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x14, including `lw` at 0x1660, `lw` at 0x1694.
  The `sw` at 0x16a4 stores 4 bytes to a0 (arg0 at entry) +0x394.
  The `sw` at 0x16a8 stores 4 bytes to a0 (arg0 at entry) +0x398.
  The `lw` at 0x16c0 loads 4 bytes from a0 (arg0 at entry) +0x394.
  The `lw` at 0x16e0 loads 4 bytes from a0 (arg0 at entry) +0x398.
  The `lbu` at 0x1758 loads 1 byte from a0 (arg0 at entry) +0x378.
  The `lbu` at 0x175c loads 1 byte from a0 (arg0 at entry) +0x377.
  The `lbu` at 0x1760 loads 1 byte from a0 (arg0 at entry) +0x379.
  The `lbu` at 0x1768 loads 1 byte from a0 (arg0 at entry) +0x375.
  The `lbu` at 0x1770 loads 1 byte from a0 (arg0 at entry) +0x376.
  The `lbu` at 0x1784 loads 1 byte from a0 (arg0 at entry) +0x374.
  The `lw` at 0x1830 loads 4 bytes from a0 (arg0 at entry) +0x2f8.
  The `sw` at 0x1838 stores 4 bytes to a0 (arg0 at entry) +0x300.
  The `lw` at 0x1864 loads 4 bytes from a0 (arg0 at entry) +0x3a8.
  The `jal` at 0x14c4 calls pciio_pio_write32 with a0=0x8000, a1=[a0+880], a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x14cc calls pciio_pio_read32 with a0=[a0+880], a1=?, a2=?, a3=?.
  The `jal` at 0x14d8 calls pciio_pio_write32 with a0=(ret(pciio_pio_read32) | 0x800), a1=[a0+880], a2=?, a3=?.
  The `jal` at 0x14e8 calls tlan_phydev with a0=a0 at entry (arg0), a1=0x0, a2=?, a3=?.
  The `jal` at 0x1528 calls cmn_err_tag with a0=0xc6, a1=0x4, a2=sym(.rodata), a3=sym(.rodata), a4=[a0+14]:2, a5=[a0+680].
  The `jal` at 0x1544 calls pciio_pio_write16 with a0=0x1, a1=[a0+880]+10, a2=?, a3=?.
  The `jal` at 0x1550 calls pciio_pio_read8 with a0=[a0+880]+14, a1=?, a2=?, a3=?.
  The `jal` at 0x1564 calls pciio_pio_write8 with a0=?, a1=[a0+880]+14, a2=?, a3=?.
  The `jal` at 0x1574 calls pciio_pio_write16 with a0=0x3, a1=[a0+880]+10, a2=?, a3=?.
  The `jal` at 0x1580 calls pciio_pio_read8 with a0=[a0+880]+12, a1=?, a2=?, a3=?.
  The `jal` at 0x1594 calls pciio_pio_write8 with a0=?, a1=[a0+880]+12, a2=?, a3=?.
  The `jal` at 0x15ac calls tlan_mii_io with a0=0x10, a1=a0 at entry (arg0), a2=[a0+687]:1, a3=0x11, a4=0x0.
  The `jal` at 0x15c8 calls tlan_mii_io with a0=0x1, a1=a0 at entry (arg0), a2=[a0+687]:1, a3=0x11.
  The `jal` at 0x15e0 calls tlan_mii_io with a0=0x1, a1=a0 at entry (arg0), a2=[a0+687]:1, a3=0x0, a4=0x0.
  The `jal` at 0x15f4 calls tlan_autonego with a0=a0 at entry (arg0), a1=?, a2=sym(.rodata), a3=?, a5=[a0+680].
  The `jal` at 0x1604 calls pciio_pio_write16 with a0=0x4, a1=[a0+880]+10, a2=?, a3=?.
  The `jal` at 0x1618 calls pciio_pio_write8 with a0=?, a1=[a0+880]+15, a2=?, a3=?.
  The `jal` at 0x1628 calls pciio_pio_write16 with a0=0x3, a1=[a0+880]+10, a2=?, a3=?.
  The `jal` at 0x1634 calls pciio_pio_read8 with a0=[a0+880]+12, a1=?, a2=?, a3=?.
  The `jal` at 0x1648 calls pciio_pio_write8 with a0=?, a1=[a0+880]+12, a2=?, a3=?.
  The `jal` at 0x1658 calls pciio_pio_write16 with a0=0x0, a1=[a0+880]+10, a2=?, a3=?.
  The `jal` at 0x168c calls pciio_pio_write8 with a0=?, a1=[a0+880]+15, a2=?, a3=one of 0x0, 0x10.
  The `jal` at 0x16b4 calls pciio_pio_write16 with a0=0x28, a1=[a0+880]+10, a2=?, a3=?.
  The `jal` at 0x16c4 calls pciio_pio_write32 with a0=[a0+916], a1=[a0+880]+12, a2=?, a3=?.
  The `jal` at 0x16d4 calls pciio_pio_write16 with a0=0x2c, a1=[a0+880]+10, a2=?, a3=?.
  The `jal` at 0x16e4 calls pciio_pio_write32 with a0=[a0+920], a1=[a0+880]+12, a2=?, a3=?.
  The `jal` at 0x16f4 calls pciio_pio_write16 with a0=0x45, a1=[a0+880]+10, a2=?, a3=?.
  The `jal` at 0x1704 calls pciio_pio_write8 with a0=0x44, a1=[a0+880]+14, a2=?, a3=?.
  The `jal` at 0x1710 calls pciio_pio_write32 with a0=0x400, a1=[a0+880], a2=?, a3=?.
  The `jal` at 0x1720 calls pciio_pio_write16 with a0=0x0, a1=[a0+880]+10, a2=?, a3=?.
  The `jal` at 0x172c calls pciio_pio_read8 with a0=[a0+880]+15, a1=?, a2=?, a3=?.
  The `jal` at 0x1750 calls pciio_pio_write8 with a0=?, a1=[a0+880]+15, a2=?, a3=?.
  The `jal` at 0x17bc calls pciio_pio_write16 with a0=?, a1=[a0+880]+10, a2=?, a3=?.
  The `jal` at 0x17cc calls pciio_pio_write32 with a0=(([a0+884]:1 | ([a0+885]:1 << 0x8)) | (([a0+886]:1 << 0x10) | ([a0+887]:1 << 0x18))), a1=[a0+880]+12, a2=?, a3=?.
  The `jal` at 0x17e0 calls pciio_pio_write16 with a0=?, a1=[a0+880]+10, a2=?, a3=?.
  The `jal` at 0x17f0 calls pciio_pio_write32 with a0=?, a1=[a0+880]+12, a2=?, a3=?.
  The `jal` at 0x1804 calls pciio_pio_write16 with a0=?, a1=[a0+880]+10, a2=?, a3=?.
  The `jal` at 0x1814 calls pciio_pio_write32 with a0=(([a0+886]:1 | ([a0+887]:1 << 0x8)) | (([a0+888]:1 << 0x10) | ([a0+889]:1 << 0x18))), a1=[a0+880]+12, a2=?, a3=?.
  The `jal` at 0x1834 calls kvtophys with a0=[a0+760], a1=?, a2=?, a3=?.
  The `jal` at 0x1860 calls pciio_dmatrans_addr with a0=[a0+936], a1=0x0, a2=ret(kvtophys), a3=0x4, a4=0x2000.
  The `jal` at 0x1870 calls pciio_pio_write32 with a0=ret(pciio_dmatrans_addr), a1=[a0+880]+4, a2=?, a3=?.
  The `jal` at 0x187c calls pciio_pio_write32 with a0=0xffffffff80080000, a1=[a0+880], a2=?, a3=?.
  The `jal` at 0x18ac calls cmn_err_tag with a0=0xc5, a1=0x0, a2=sym(.rodata), a3=sym(.rodata), a4=[a0+14]:2, a5=[a0+680].
  The `beq` branch at 0x1504 targets 0x1894, is taken when v0(=ret(tlan_phydev)) >= 0x20 (unsigned), and falls through when v0(=ret(tlan_phydev)) < 0x20 (unsigned).
  The `bne` branch at 0x150c targets 0x15f0, is taken when a5(=[a0+680]) != a0(=0x40005010), and falls through when a5(=[a0+680]) == a0(=0x40005010).
  The `beq` branch at 0x15e8 targets 0x1600 and is always taken.
  The `beq` branch at 0x1668 targets 0x1674, is taken when (a2(=[a0+20]) & 0x100) == 0, and falls through when (a2(=[a0+20]) & 0x100) != 0.
  The `beq` branch at 0x169c targets 0x16ac, is taken when (a1(=[a0+20]) & 0x200) == 0, and falls through when (a1(=[a0+20]) & 0x200) != 0.
  The `bne` branch at 0x1828 targets 0x17b4, is taken when s2(?) < 0x2 (signed), and falls through when s2(?) >= 0x2 (signed).
  The `beq` branch at 0x18b4 targets 0x15fc and is always taken.
  The return at 0x188c has v0 = ret(pciio_pio_write32).

- `tlan_mii_sync` in `IP32/usr/cpu/sysgen/IP32boot/if_ecf.o` at 0x18bc (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/if_ecf.o`.
  Range: 0x18bc-0x1a50 (404 bytes).
  It occupies 404 bytes.
  19 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x370, including `lw` at 0x18cc, `lw` at 0x18e8, `lw` at 0x18f4.
  The `jal` at 0x18e0 calls pciio_pio_write16 with a0=0x1, a1=[a0+880]+10, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x18ec calls pciio_pio_read8 with a0=[a0+880]+14, a1=?, a2=?, a3=?.
  The `jal` at 0x1900 calls pciio_pio_write16 with a0=0x1, a1=[a0+880]+10, a2=?, a3=?.
  The `jal` at 0x1918 calls pciio_pio_write8 with a0=?, a1=[a0+880]+14, a2=?, a3=?.
  The `jal` at 0x1928 calls pciio_pio_write16 with a0=0x1, a1=[a0+880]+10, a2=?, a3=?.
  The `jal` at 0x1940 calls pciio_pio_write8 with a0=?, a1=[a0+880]+14, a2=?, a3=?.
  The `jal` at 0x1950 calls pciio_pio_write16 with a0=0x1, a1=[a0+880]+10, a2=?, a3=?.
  The `jal` at 0x195c calls pciio_pio_read8 with a0=[a0+880]+14, a1=?, a2=?, a3=?.
  The `jal` at 0x196c calls pciio_pio_write16 with a0=0x1, a1=[a0+880]+10, a2=?, a3=?.
  The `jal` at 0x1984 calls pciio_pio_write8 with a0=?, a1=[a0+880]+14, a2=?, a3=?.
  The `jal` at 0x1994 calls pciio_pio_write16 with a0=0x1, a1=[a0+880]+10, a2=?, a3=?.
  The `jal` at 0x19a0 calls pciio_pio_read8 with a0=[a0+880]+14, a1=?, a2=?, a3=?.
  The `jal` at 0x19b0 calls pciio_pio_write16 with a0=0x1, a1=[a0+880]+10, a2=?, a3=?.
  The `jal` at 0x19cc calls pciio_pio_write8 with a0=?, a1=[a0+880]+14, a2=?, a3=?.
  The `jal` at 0x19e4 calls pciio_pio_write16 with a0=0x1, a1=[a0+880]+10, a2=?, a3=?.
  The `jal` at 0x19f4 calls pciio_pio_write8 with a0=?, a1=[a0+880]+14, a2=?, a3=?.
  The `jal` at 0x1a04 calls pciio_pio_write16 with a0=0x1, a1=[a0+880]+10, a2=?, a3=?.
  The `jal` at 0x1a1c calls pciio_pio_write8 with a0=?, a1=[a0+880]+14, a2=?, a3=?.
  The `bnel` branch at 0x1a2c targets 0x19e0, is taken when s2(?) < 0x20 (signed), and falls through when s2(?) >= 0x20 (signed); its branch-likely delay slot `lw a1,880(s0)` at 0x1a30 runs only when taken and is annulled on fall-through.
  The return at 0x1a48 has v0 = ret(pciio_pio_write8).

- `tlan_mii_init` in `IP32/usr/cpu/sysgen/IP32boot/if_ecf.o` at 0x1a50 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/if_ecf.o`.
  Range: 0x1a50-0x1b08 (184 bytes).
  It occupies 184 bytes.
  The `jal` at 0x1a60 calls tlan_mii_sync with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1a7c calls tlan_mii_io with a0=0x1, a1=a0 at entry (arg0), a2=?, a3=0x0, a4=0x4c00.
  The `jal` at 0x1ab0 calls tlan_mii_io with a0=0x1, a1=a0 at entry (arg0), a2=?, a3=0x0, a4=0xcc00.
  The `jal` at 0x1ab8 calls tlan_mii_sync with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x1ad0 calls tlan_mii_io with a0=0x1, a1=a0 at entry (arg0), a2=?, a3=0x0, a4=0x4c00.
  The `jal` at 0x1ae8 calls tlan_mii_sync with a0=a0 at entry (arg0), a1=?, a2=?, a3=?, a4=0xcc00.
  The `bne` branch at 0x1a8c targets 0x1a70, is taken when s0(?) < 0x20 (signed), and falls through when s0(?) >= 0x20 (signed).
  The `bne` branch at 0x1ae0 targets 0x1aa0, is taken when s0(?) < 0x20 (signed), and falls through when s0(?) >= 0x20 (signed).
  The return at 0x1b00 has v0 = ret(tlan_mii_sync).

- `tlan_mii_io` in `IP32/usr/cpu/sysgen/IP32boot/if_ecf.o` at 0x1b08 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/if_ecf.o`.
  Range: 0x1b08-0x2444 (2364 bytes).
  It occupies 2364 bytes.
  109 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x370, including `lw` at 0x1b2c, `lw` at 0x1b48, `lw` at 0x1b6c.
  The `jal` at 0x1b40 calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1b54 calls pciio_pio_read8 with a0=[a1+880]+14, a1=?, a2=?, a3=?.
  The `jal` at 0x1b74 calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=?, a3=?.
  The `jal` at 0x1b84 calls pciio_pio_write8 with a0=?, a1=[a1+880]+14, a2=?, a3=?.
  The `jal` at 0x1b94 calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=?, a3=?.
  The `jal` at 0x1bac calls pciio_pio_write8 with a0=?, a1=[a1+880]+14, a2=?, a3=?.
  The `jal` at 0x1bcc calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=?, a3=?.
  The `jal` at 0x1be4 calls pciio_pio_write8 with a0=?, a1=[a1+880]+14, a2=?, a3=?.
  The `jal` at 0x1bf8 calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=?, a3=?.
  The `jal` at 0x1c0c calls pciio_pio_write8 with a0=?, a1=[a1+880]+14, a2=?, a3=?.
  The `jal` at 0x1c1c calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=?, a3=?.
  The `jal` at 0x1c30 calls pciio_pio_write8 with a0=?, a1=[a1+880]+14, a2=?, a3=?.
  The `jal` at 0x1c40 calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=?, a3=?.
  The `jal` at 0x1c50 calls pciio_pio_write8 with a0=?, a1=[a1+880]+14, a2=?, a3=?.
  The `jal` at 0x1c60 calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=?, a3=?.
  The `jal` at 0x1c70 calls pciio_pio_write8 with a0=?, a1=[a1+880]+14, a2=?, a3=?.
  The `jal` at 0x1c80 calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=?, a3=?.
  The `jal` at 0x1c90 calls pciio_pio_write8 with a0=?, a1=[a1+880]+14, a2=?, a3=?.
  The `jal` at 0x1ca0 calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=?, a3=?.
  The `jal` at 0x1cb8 calls pciio_pio_write8 with a0=?, a1=[a1+880]+14, a2=?, a3=?.
  The `jal` at 0x1cd8 calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=0x10, a3=a0 at entry (arg0).
  The `jal` at 0x1cec calls pciio_pio_write8 with a0=?, a1=[a1+880]+14, a2=?, a3=?.
  The `jal` at 0x1cfc calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=?, a3=?.
  The `jal` at 0x1d10 calls pciio_pio_write8 with a0=?, a1=[a1+880]+14, a2=?, a3=?.
  The `jal` at 0x1d20 calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=?, a3=?.
  The `jal` at 0x1d34 calls pciio_pio_write8 with a0=?, a1=[a1+880]+14, a2=?, a3=?.
  The `jal` at 0x1d44 calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=?, a3=?.
  The `jal` at 0x1d58 calls pciio_pio_write8 with a0=?, a1=[a1+880]+14, a2=?, a3=?.
  The `jal` at 0x1d68 calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=?, a3=?.
  The `jal` at 0x1d7c calls pciio_pio_write8 with a0=?, a1=[a1+880]+14, a2=?, a3=?.
  The `jal` at 0x1d8c calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=?, a3=?.
  The `jal` at 0x1da4 calls pciio_pio_write8 with a0=?, a1=[a1+880]+14, a2=?, a3=?.
  The `jal` at 0x1dc0 calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=?, a3=?.
  The `jal` at 0x1dd0 calls pciio_pio_write8 with a0=?, a1=[a1+880]+14, a2=?, a3=?.
  The `jal` at 0x1de0 calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=?, a3=?.
  The `jal` at 0x1df4 calls pciio_pio_write8 with a0=?, a1=[a1+880]+14, a2=?, a3=?.
  The `jal` at 0x1e04 calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=?, a3=?.
  The `jal` at 0x1e1c calls pciio_pio_write8 with a0=?, a1=[a1+880]+14, a2=?, a3=?.
  The `jal` at 0x1e58 calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=?, a3=?.
  The `jal` at 0x1e68 calls pciio_pio_write8 with a0=?, a1=[a1+880]+14, a2=?, a3=?.
  The `jal` at 0x1e78 calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=?, a3=?.
  The `jal` at 0x1e8c calls pciio_pio_write8 with a0=?, a1=[a1+880]+14, a2=?, a3=?.
  The `jal` at 0x1e9c calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=?, a3=?.
  The `jal` at 0x1eb4 calls pciio_pio_write8 with a0=?, a1=[a1+880]+14, a2=?, a3=?.
  The `jal` at 0x1ef4 calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=0x10, a3=a0 at entry (arg0).
  The `jal` at 0x1f08 calls pciio_pio_write8 with a0=?, a1=[a1+880]+14, a2=?, a3=?.
  The `jal` at 0x1f18 calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=?, a3=?.
  The `jal` at 0x1f2c calls pciio_pio_write8 with a0=?, a1=[a1+880]+14, a2=?, a3=?.
  The `jal` at 0x1f3c calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=?, a3=?.
  The `jal` at 0x1f50 calls pciio_pio_write8 with a0=?, a1=[a1+880]+14, a2=?, a3=?.
  The `jal` at 0x1f60 calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=?, a3=?.
  The `jal` at 0x1f74 calls pciio_pio_write8 with a0=?, a1=[a1+880]+14, a2=?, a3=?.
  The `jal` at 0x1f84 calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=?, a3=?.
  The `jal` at 0x1f98 calls pciio_pio_write8 with a0=?, a1=[a1+880]+14, a2=?, a3=?.
  The `jal` at 0x1fa8 calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=?, a3=?.
  The `jal` at 0x1fc0 calls pciio_pio_write8 with a0=?, a1=[a1+880]+14, a2=?, a3=?.
  The `jal` at 0x1fdc calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=?, a3=?.
  The `jal` at 0x1fec calls pciio_pio_write8 with a0=?, a1=[a1+880]+14, a2=?, a3=?.
  The `jal` at 0x1ffc calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=?, a3=?.
  The `jal` at 0x2010 calls pciio_pio_write8 with a0=?, a1=[a1+880]+14, a2=?, a3=?.
  The `jal` at 0x2020 calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=?, a3=?.
  The `jal` at 0x2038 calls pciio_pio_write8 with a0=?, a1=[a1+880]+14, a2=?, a3=?.
  The `jal` at 0x2068 calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=?, a3=?.
  The `jal` at 0x207c calls pciio_pio_write8 with a0=?, a1=[a1+880]+14, a2=?, a3=?.
  The `jal` at 0x208c calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=?, a3=?.
  The `jal` at 0x20a0 calls pciio_pio_write8 with a0=?, a1=[a1+880]+14, a2=?, a3=?.
  The `jal` at 0x20b0 calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=?, a3=?.
  The `jal` at 0x20c4 calls pciio_pio_write8 with a0=?, a1=[a1+880]+14, a2=?, a3=?.
  The `jal` at 0x20f4 calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=?, a3=?.
  The `jal` at 0x2100 calls pciio_pio_read8 with a0=[a1+880]+14, a1=?, a2=?, a3=?.
  The `jal` at 0x2114 calls pciio_pio_write8 with a0=?, a1=[a1+880]+14, a2=?, a3=?.
  The `jal` at 0x2134 calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=0x10, a3=a0 at entry (arg0).
  The `jal` at 0x2148 calls pciio_pio_write8 with a0=?, a1=[a1+880]+14, a2=?, a3=?.
  The `jal` at 0x2158 calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=?, a3=?.
  The `jal` at 0x216c calls pciio_pio_write8 with a0=?, a1=[a1+880]+14, a2=?, a3=?.
  The `jal` at 0x217c calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=?, a3=?.
  The `jal` at 0x2190 calls pciio_pio_write8 with a0=?, a1=[a1+880]+14, a2=?, a3=?.
  The `jal` at 0x21a0 calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=?, a3=?.
  The `jal` at 0x21b4 calls pciio_pio_write8 with a0=?, a1=[a1+880]+14, a2=?, a3=?.
  The `jal` at 0x21c4 calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=?, a3=?.
  The `jal` at 0x21d8 calls pciio_pio_write8 with a0=?, a1=[a1+880]+14, a2=?, a3=?.
  The `jal` at 0x21e8 calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=?, a3=?.
  The `jal` at 0x2200 calls pciio_pio_write8 with a0=?, a1=[a1+880]+14, a2=?, a3=?.
  The `jal` at 0x2210 calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=0x10, a3=a0 at entry (arg0).
  The `jal` at 0x2224 calls pciio_pio_write8 with a0=?, a1=[a1+880]+14, a2=?, a3=?.
  The `jal` at 0x2234 calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=?, a3=?.
  The `jal` at 0x224c calls pciio_pio_write8 with a0=?, a1=[a1+880]+14, a2=?, a3=?.
  The `jal` at 0x225c calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=?, a3=?.
  The `jal` at 0x2270 calls pciio_pio_write8 with a0=?, a1=[a1+880]+14, a2=?, a3=?.
  The `jal` at 0x2280 calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=?, a3=?.
  The `jal` at 0x2294 calls pciio_pio_write8 with a0=?, a1=[a1+880]+14, a2=?, a3=?.
  The `jal` at 0x22a4 calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=?, a3=?.
  The `jal` at 0x22b0 calls pciio_pio_read8 with a0=[a1+880]+14, a1=?, a2=?, a3=?.
  The `jal` at 0x22cc calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=?, a3=?.
  The `jal` at 0x22dc calls pciio_pio_write8 with a0=?, a1=[a1+880]+14, a2=?, a3=?.
  The `jal` at 0x22ec calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=?, a3=?.
  The `jal` at 0x2304 calls pciio_pio_write8 with a0=?, a1=[a1+880]+14, a2=?, a3=?.
  The `jal` at 0x2328 calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=?, a3=?.
  The `jal` at 0x2338 calls pciio_pio_write8 with a0=?, a1=[a1+880]+14, a2=?, a3=?.
  The `jal` at 0x2348 calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=?, a3=?.
  The `jal` at 0x2358 calls pciio_pio_write8 with a0=?, a1=[a1+880]+14, a2=?, a3=?.
  The `jal` at 0x2370 calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=?, a3=?.
  The `jal` at 0x2388 calls pciio_pio_write8 with a0=?, a1=[a1+880]+14, a2=?, a3=?.
  The `jal` at 0x23a0 calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=?, a3=?.
  The `jal` at 0x23b0 calls pciio_pio_write8 with a0=?, a1=[a1+880]+14, a2=?, a3=?.
  The `jal` at 0x23c0 calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=?, a3=?.
  The `jal` at 0x23cc calls pciio_pio_read8 with a0=[a1+880]+14, a1=?, a2=?, a3=?.
  The `jal` at 0x23ec calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=?, a3=?.
  The `jal` at 0x2404 calls pciio_pio_write8 with a0=?, a1=[a1+880]+14, a2=?, a3=?.
  The `bnel` branch at 0x1bbc targets 0x1b70, is taken when s2(?) < 0x20 (signed), and falls through when s2(?) >= 0x20 (signed); its branch-likely delay slot `lw a1,880(s0)` at 0x1bc0 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x1cd0 targets 0x2134, is taken when a2(=0x10) == a3(=a0), and falls through when a2(=0x10) != a3(=a0).
  The `beq` branch at 0x1dac targets 0x2420 and is always taken.
  The `beq` branch at 0x1e28 targets 0x1e44, is taken when s4(?) == 0, and falls through when s4(?) != 0.
  The `bne` branch at 0x1e34 targets 0x1db4, is taken when t8(?) != 0, and falls through when t8(?) == 0.
  The `beq` branch at 0x1e3c targets 0x1db8 and is always taken.
  The `beq` branch at 0x1e44 targets 0x242c and is always taken.
  The `beq` branch at 0x1ec0 targets 0x1edc, is taken when s4(?) == 0, and falls through when s4(?) != 0.
  The `bne` branch at 0x1ecc targets 0x1e4c, is taken when t8(?) != 0, and falls through when t8(?) == 0.
  The `beq` branch at 0x1ed4 targets 0x1e50 and is always taken.
  The `beq` branch at 0x1eec targets 0x2210, is taken when a2(=0x10) == a3(=a0), and falls through when a2(=0x10) != a3(=a0).
  The `beq` branch at 0x1fc8 targets 0x2438 and is always taken.
  The `beq` branch at 0x2044 targets 0x2060, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `bne` branch at 0x2050 targets 0x1fd0, is taken when t8(?) != 0, and falls through when t8(?) == 0.
  The `beq` branch at 0x2058 targets 0x1fd4 and is always taken.
  The `beq` branch at 0x2208 targets 0x1dac and is always taken.
  The `beq` branch at 0x22bc targets 0x2368, is taken when (v0(=ret(pciio_pio_read8)) & 0x1) == 0, and falls through when (v0(=ret(pciio_pio_read8)) & 0x1) != 0.
  The `bne` branch at 0x2314 targets 0x22c4, is taken when s2(?) < 0x11 (signed), and falls through when s2(?) >= 0x11 (signed).
  The `beq` branch at 0x2360 targets 0x20d4 and is always taken.
  The `beq` branch at 0x23d8 targets 0x23e4, is taken when (v0(=ret(pciio_pio_read8)) & 0x1) == 0, and falls through when (v0(=ret(pciio_pio_read8)) & 0x1) != 0.
  The `bne` branch at 0x2410 targets 0x2398, is taken when s4(?) != 0, and falls through when s4(?) == 0.
  The `beq` branch at 0x2418 targets 0x2324 and is always taken.
  The `beq` branch at 0x2424 targets 0x1e34 and is always taken.
  The `beq` branch at 0x2430 targets 0x1ecc and is always taken.
  The `beq` branch at 0x243c targets 0x2050 and is always taken.
  The return at 0x212c has v0 = ?.

- `tlan_eeprom_seldev` in `IP32/usr/cpu/sysgen/IP32boot/if_ecf.o` at 0x2444 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/if_ecf.o`.
  Range: 0x2444-0x263c (504 bytes).
  It occupies 504 bytes.
  24 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x370, including `lw` at 0x247c, `lw` at 0x248c, `lw` at 0x249c.
  The `jal` at 0x2474 calls pciio_pio_write16 with a0=0x1, a1=[a0+880]+10, a2=?, a3=?.
  The `jal` at 0x2480 calls pciio_pio_read8 with a0=[a0+880]+14, a1=?, a2=?, a3=?.
  The `jal` at 0x2494 calls pciio_pio_write8 with a0=?, a1=[a0+880]+14, a2=?, a3=?.
  The `jal` at 0x24a4 calls pciio_pio_write16 with a0=0x1, a1=[a0+880]+10, a2=?, a3=?.
  The `jal` at 0x24b0 calls pciio_pio_read8 with a0=[a0+880]+14, a1=?, a2=?, a3=?.
  The `jal` at 0x24c4 calls pciio_pio_write8 with a0=?, a1=[a0+880]+14, a2=?, a3=?.
  The `jal` at 0x24d4 calls pciio_pio_write16 with a0=0x1, a1=[a0+880]+10, a2=?, a3=?.
  The `jal` at 0x24e0 calls pciio_pio_read8 with a0=[a0+880]+14, a1=?, a2=?, a3=?.
  The `jal` at 0x24f4 calls pciio_pio_write8 with a0=?, a1=[a0+880]+14, a2=?, a3=?.
  The `jal` at 0x251c calls pciio_pio_write16 with a0=0x1, a1=[a0+880]+10, a2=?, a3=?.
  The `jal` at 0x2528 calls pciio_pio_read8 with a0=[a0+880]+14, a1=?, a2=?, a3=?.
  The `jal` at 0x2540 calls pciio_pio_write8 with a0=?, a1=[a0+880]+14, a2=?, a3=?.
  The `jal` at 0x2564 calls pciio_pio_write16 with a0=0x1, a1=[a0+880]+10, a2=a1 at entry (arg1), a3=0x1.
  The `jal` at 0x2570 calls pciio_pio_read8 with a0=[a0+880]+14, a1=?, a2=?, a3=?.
  The `jal` at 0x2584 calls pciio_pio_write8 with a0=?, a1=[a0+880]+14, a2=?, a3=?.
  The `jal` at 0x2594 calls pciio_pio_write16 with a0=0x1, a1=[a0+880]+10, a2=a1 at entry (arg1), a3=0x1.
  The `jal` at 0x25a0 calls pciio_pio_read8 with a0=[a0+880]+14, a1=?, a2=?, a3=?.
  The `jal` at 0x25b8 calls pciio_pio_write8 with a0=?, a1=[a0+880]+14, a2=?, a3=?.
  The `jal` at 0x25c8 calls pciio_pio_write16 with a0=0x1, a1=[a0+880]+10, a2=?, a3=?.
  The `jal` at 0x25d4 calls pciio_pio_read8 with a0=[a0+880]+14, a1=?, a2=?, a3=?.
  The `jal` at 0x25e8 calls pciio_pio_write8 with a0=?, a1=[a0+880]+14, a2=?, a3=?.
  The `jal` at 0x25f8 calls pciio_pio_write16 with a0=0x1, a1=[a0+880]+10, a2=?, a3=?.
  The `jal` at 0x2604 calls pciio_pio_read8 with a0=[a0+880]+14, a1=?, a2=?, a3=?.
  The `jal` at 0x2618 calls pciio_pio_write8 with a0=?, a1=[a0+880]+14, a2=?, a3=?.
  The `beq` branch at 0x246c targets 0x250c and is always taken.
  The `beq` branch at 0x2504 targets 0x2550, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `bne` branch at 0x2514 targets 0x2474, is taken when (s1(?) & 0x50) != 0, and falls through when (s1(?) & 0x50) == 0.
  The `beq` branch at 0x2548 targets 0x24a0 and is always taken.
  The `bne` branch at 0x255c targets 0x2594, is taken when a2(=a1) != a3(=0x1), and falls through when a2(=a1) == a3(=0x1).
  The `beq` branch at 0x258c targets 0x25c4 and is always taken.
  The return at 0x2634 has v0 = ret(pciio_pio_write8).

- `tlan_eeprom_ack` in `IP32/usr/cpu/sysgen/IP32boot/if_ecf.o` at 0x263c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/if_ecf.o`.
  Range: 0x263c-0x2724 (232 bytes).
  It occupies 232 bytes.
  11 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x370, including `lw` at 0x2644, `lw` at 0x2660, `lw` at 0x266c.
  The `jal` at 0x2658 calls pciio_pio_write16 with a0=0x1, a1=[a0+880]+10, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x2664 calls pciio_pio_read8 with a0=[a0+880]+14, a1=?, a2=?, a3=?.
  The `jal` at 0x267c calls pciio_pio_write8 with a0=?, a1=[a0+880]+14, a2=?, a3=?.
  The `jal` at 0x268c calls pciio_pio_write16 with a0=0x1, a1=[a0+880]+10, a2=?, a3=?.
  The `jal` at 0x2698 calls pciio_pio_read8 with a0=[a0+880]+14, a1=?, a2=?, a3=?.
  The `jal` at 0x26ac calls pciio_pio_write8 with a0=?, a1=[a0+880]+14, a2=?, a3=?.
  The `jal` at 0x26bc calls pciio_pio_write16 with a0=0x1, a1=[a0+880]+10, a2=?, a3=?.
  The `jal` at 0x26c8 calls pciio_pio_read8 with a0=[a0+880]+14, a1=?, a2=?, a3=?.
  The `jal` at 0x26dc calls pciio_pio_write16 with a0=0x1, a1=[a0+880]+10, a2=?, a3=?.
  The `jal` at 0x26e8 calls pciio_pio_read8 with a0=[a0+880]+14, a1=?, a2=?, a3=?.
  The `jal` at 0x2700 calls pciio_pio_write8 with a0=?, a1=[a0+880]+14, a2=?, a3=?.
  The return at 0x271c has v0 = ?.

- `tlan_eeprom_sendbyte` in `IP32/usr/cpu/sysgen/IP32boot/if_ecf.o` at 0x2724 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/if_ecf.o`.
  Range: 0x2724-0x2880 (348 bytes).
  It occupies 348 bytes.
  15 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x370, including `lw` at 0x273c, `lw` at 0x2758, `lw` at 0x2768.
  The `jal` at 0x2750 calls pciio_pio_write16 with a0=0x1, a1=[a0+880]+10, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x275c calls pciio_pio_read8 with a0=[a0+880]+14, a1=?, a2=?, a3=?.
  The `jal` at 0x2770 calls pciio_pio_write8 with a0=?, a1=[a0+880]+14, a2=?, a3=?.
  The `jal` at 0x2788 calls pciio_pio_write16 with a0=0x1, a1=[a0+880]+10, a2=?, a3=?.
  The `jal` at 0x2794 calls pciio_pio_read8 with a0=[a0+880]+14, a1=?, a2=?, a3=?.
  The `jal` at 0x27a8 calls pciio_pio_write8 with a0=?, a1=[a0+880]+14, a2=?, a3=?.
  The `jal` at 0x27b8 calls pciio_pio_write16 with a0=0x1, a1=[a0+880]+10, a2=?, a3=?.
  The `jal` at 0x27c4 calls pciio_pio_read8 with a0=[a0+880]+14, a1=?, a2=?, a3=?.
  The `jal` at 0x27d8 calls pciio_pio_write8 with a0=?, a1=[a0+880]+14, a2=?, a3=?.
  The `jal` at 0x27e8 calls pciio_pio_write16 with a0=0x1, a1=[a0+880]+10, a2=?, a3=?.
  The `jal` at 0x27f4 calls pciio_pio_read8 with a0=[a0+880]+14, a1=?, a2=?, a3=?.
  The `jal` at 0x2808 calls pciio_pio_write8 with a0=?, a1=[a0+880]+14, a2=?, a3=?.
  The `jal` at 0x282c calls pciio_pio_write16 with a0=0x1, a1=[a0+880]+10, a2=?, a3=?.
  The `jal` at 0x2838 calls pciio_pio_read8 with a0=[a0+880]+14, a1=?, a2=?, a3=?.
  The `jal` at 0x2850 calls pciio_pio_write8 with a0=?, a1=[a0+880]+14, a2=?, a3=?.
  The `beq` branch at 0x2780 targets 0x281c and is always taken.
  The `beq` branch at 0x2814 targets 0x2860, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `bne` branch at 0x2824 targets 0x2788, is taken when (s1(?) & s3(=a1)) != 0, and falls through when (s1(?) & s3(=a1)) == 0.
  The `beq` branch at 0x2858 targets 0x27b4 and is always taken.
  The return at 0x2878 has v0 = ret(pciio_pio_write8).

- `tlan_eeprom_io` in `IP32/usr/cpu/sysgen/IP32boot/if_ecf.o` at 0x2880 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/if_ecf.o`.
  Range: 0x2880-0x2f8c (1804 bytes).
  It occupies 1804 bytes.
  2 such `sw` accesses store 4 bytes to a5 (arg5 at entry) +0x0, including `sw` at 0x2894, `sw` at 0x2c74.
  86 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x370, including `lw` at 0x28a8, `lw` at 0x28c4, `lw` at 0x28d4.
  4 such `lw` accesses load 4 bytes from a5 (arg5 at entry) +0x0, including `lw` at 0x2c80, `lw` at 0x2cc0, `lw` at 0x2cd0.
  The `jal` at 0x28bc calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x28c8 calls pciio_pio_read8 with a0=[a1+880]+14, a1=?, a2=?, a3=?.
  The `jal` at 0x28dc calls pciio_pio_write8 with a0=?, a1=[a1+880]+14, a2=?, a3=?.
  The `jal` at 0x28ec calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=?, a3=?.
  The `jal` at 0x28f8 calls pciio_pio_read8 with a0=[a1+880]+14, a1=?, a2=?, a3=?.
  The `jal` at 0x290c calls pciio_pio_write8 with a0=?, a1=[a1+880]+14, a2=?, a3=?.
  The `jal` at 0x291c calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=?, a3=?.
  The `jal` at 0x2928 calls pciio_pio_read8 with a0=[a1+880]+14, a1=?, a2=?, a3=?.
  The `jal` at 0x293c calls pciio_pio_write8 with a0=?, a1=[a1+880]+14, a2=?, a3=?.
  The `jal` at 0x294c calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=?, a3=?.
  The `jal` at 0x295c calls pciio_pio_read8 with a0=[a1+880]+14, a1=?, a2=?, a3=?.
  The `jal` at 0x2974 calls pciio_pio_write8 with a0=?, a1=[a1+880]+14, a2=?, a3=?.
  The `jal` at 0x2984 calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=?, a3=?.
  The `jal` at 0x2994 calls pciio_pio_read8 with a0=[a1+880]+14, a1=?, a2=?, a3=?.
  The `jal` at 0x29ac calls pciio_pio_write8 with a0=?, a1=[a1+880]+14, a2=?, a3=?.
  The `jal` at 0x29b8 calls tlan_eeprom_seldev with a0=a1 at entry (arg1), a1=0x0, a2=?, a3=?.
  The `jal` at 0x29c0 calls tlan_eeprom_ack with a0=a1 at entry (arg1), a1=?, a2=?, a3=?.
  The `jal` at 0x29d8 calls tlan_eeprom_sendbyte with a0=a1 at entry (arg1), a1=a2 at entry (arg2), a2=?, a3=?.
  The `jal` at 0x29e0 calls tlan_eeprom_ack with a0=a1 at entry (arg1), a1=?, a2=?, a3=?.
  The `jal` at 0x2a10 calls tlan_eeprom_sendbyte with a0=a1 at entry (arg1), a1=?, a2=?, a3=?.
  The `jal` at 0x2a18 calls tlan_eeprom_ack with a0=a1 at entry (arg1), a1=?, a2=?, a3=?.
  The `jal` at 0x2a48 calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=0x1, a3=?.
  The `jal` at 0x2a54 calls pciio_pio_read8 with a0=[a1+880]+14, a1=?, a2=?, a3=?.
  The `jal` at 0x2a68 calls pciio_pio_write8 with a0=?, a1=[a1+880]+14, a2=?, a3=?.
  The `jal` at 0x2a78 calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=?, a3=?.
  The `jal` at 0x2a84 calls pciio_pio_read8 with a0=[a1+880]+14, a1=?, a2=?, a3=?.
  The `jal` at 0x2a98 calls pciio_pio_write8 with a0=?, a1=[a1+880]+14, a2=?, a3=?.
  The `jal` at 0x2aa8 calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=?, a3=?.
  The `jal` at 0x2ab4 calls pciio_pio_read8 with a0=[a1+880]+14, a1=?, a2=?, a3=?.
  The `jal` at 0x2ac8 calls pciio_pio_write8 with a0=?, a1=[a1+880]+14, a2=?, a3=?.
  The `jal` at 0x2ad8 calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=?, a3=?.
  The `jal` at 0x2ae4 calls pciio_pio_read8 with a0=[a1+880]+14, a1=?, a2=?, a3=?.
  The `jal` at 0x2af8 calls pciio_pio_write8 with a0=?, a1=[a1+880]+14, a2=?, a3=?.
  The `jal` at 0x2b08 calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=?, a3=?.
  The `jal` at 0x2b14 calls pciio_pio_read8 with a0=[a1+880]+14, a1=?, a2=?, a3=?.
  The `jal` at 0x2b28 calls pciio_pio_write8 with a0=?, a1=[a1+880]+14, a2=?, a3=?.
  The `jal` at 0x2b38 calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=?, a3=?.
  The `jal` at 0x2b44 calls pciio_pio_read8 with a0=[a1+880]+14, a1=?, a2=?, a3=?.
  The `jal` at 0x2b5c calls pciio_pio_write8 with a0=?, a1=[a1+880]+14, a2=?, a3=?.
  The `jal` at 0x2b6c calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=?, a3=?.
  The `jal` at 0x2b78 calls pciio_pio_read8 with a0=[a1+880]+14, a1=?, a2=?, a3=?.
  The `jal` at 0x2b8c calls pciio_pio_write8 with a0=?, a1=[a1+880]+14, a2=?, a3=?.
  The `jal` at 0x2b9c calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=?, a3=?.
  The `jal` at 0x2ba8 calls pciio_pio_read8 with a0=[a1+880]+14, a1=?, a2=?, a3=?.
  The `jal` at 0x2bbc calls pciio_pio_write8 with a0=?, a1=[a1+880]+14, a2=?, a3=?.
  The `jal` at 0x2bcc calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=?, a3=?.
  The `jal` at 0x2bd8 calls pciio_pio_read8 with a0=[a1+880]+14, a1=?, a2=?, a3=?.
  The `jal` at 0x2bec calls pciio_pio_write8 with a0=?, a1=[a1+880]+14, a2=?, a3=?.
  The `jal` at 0x2bfc calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=?, a3=?.
  The `jal` at 0x2c08 calls pciio_pio_read8 with a0=[a1+880]+14, a1=?, a2=?, a3=?.
  The `jal` at 0x2c1c calls pciio_pio_write8 with a0=?, a1=[a1+880]+14, a2=?, a3=?.
  The `jal` at 0x2c2c calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=?, a3=?.
  The `jal` at 0x2c38 calls pciio_pio_read8 with a0=[a1+880]+14, a1=?, a2=?, a3=?.
  The `jal` at 0x2c4c calls pciio_pio_write8 with a0=?, a1=[a1+880]+14, a2=?, a3=?.
  The `jal` at 0x2c58 calls tlan_eeprom_seldev with a0=a1 at entry (arg1), a1=0x0, a2=?, a3=?.
  The `jal` at 0x2c60 calls tlan_eeprom_ack with a0=a1 at entry (arg1), a1=?, a2=?, a3=?.
  The `jal` at 0x2cd8 calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=a0 at entry (arg0), a3=?.
  The `jal` at 0x2ce4 calls pciio_pio_read8 with a0=[a1+880]+14, a1=?, a2=?, a3=?.
  The `jal` at 0x2cf8 calls pciio_pio_write8 with a0=?, a1=[a1+880]+14, a2=?, a3=?.
  The `jal` at 0x2d08 calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=?, a3=?.
  The `jal` at 0x2d14 calls pciio_pio_read8 with a0=[a1+880]+14, a1=?, a2=?, a3=?.
  The `jal` at 0x2d28 calls pciio_pio_write8 with a0=?, a1=[a1+880]+14, a2=?, a3=?.
  The `jal` at 0x2d38 calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=?, a3=?.
  The `jal` at 0x2d44 calls pciio_pio_read8 with a0=[a1+880]+14, a1=?, a2=?, a3=?.
  The `jal` at 0x2d58 calls pciio_pio_write8 with a0=?, a1=[a1+880]+14, a2=?, a3=?.
  The `jal` at 0x2d68 calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=?, a3=?.
  The `jal` at 0x2d74 calls pciio_pio_read8 with a0=[a1+880]+14, a1=?, a2=?, a3=?.
  The `jal` at 0x2d88 calls pciio_pio_write8 with a0=?, a1=[a1+880]+14, a2=?, a3=?.
  The `jal` at 0x2d98 calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=?, a3=?.
  The `jal` at 0x2da4 calls pciio_pio_read8 with a0=[a1+880]+14, a1=?, a2=?, a3=?.
  The `jal` at 0x2db8 calls pciio_pio_write8 with a0=?, a1=[a1+880]+14, a2=?, a3=?.
  The `jal` at 0x2dc8 calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=?, a3=?.
  The `jal` at 0x2dd4 calls pciio_pio_read8 with a0=[a1+880]+14, a1=?, a2=?, a3=?.
  The `jal` at 0x2de8 calls pciio_pio_write8 with a0=?, a1=[a1+880]+14, a2=?, a3=?.
  The `jal` at 0x2df4 calls tlan_eeprom_seldev with a0=a1 at entry (arg1), a1=0x1, a2=?, a3=?.
  The `jal` at 0x2dfc calls tlan_eeprom_ack with a0=a1 at entry (arg1), a1=?, a2=?, a3=?.
  The `jal` at 0x2e20 calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=?, a3=?.
  The `jal` at 0x2e2c calls pciio_pio_read8 with a0=[a1+880]+14, a1=?, a2=?, a3=?.
  The `jal` at 0x2e40 calls pciio_pio_write8 with a0=?, a1=[a1+880]+14, a2=?, a3=?.
  The `jal` at 0x2e50 calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=?, a3=?.
  The `jal` at 0x2e5c calls pciio_pio_read8 with a0=[a1+880]+14, a1=?, a2=?, a3=?.
  The `jal` at 0x2e7c calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=?, a3=?.
  The `jal` at 0x2e88 calls pciio_pio_read8 with a0=[a1+880]+14, a1=?, a2=?, a3=?.
  The `jal` at 0x2e9c calls pciio_pio_write8 with a0=?, a1=[a1+880]+14, a2=?, a3=?.
  The `jal` at 0x2ec0 calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=?, a3=?.
  The `jal` at 0x2ecc calls pciio_pio_read8 with a0=[a1+880]+14, a1=?, a2=?, a3=?.
  The `jal` at 0x2ee0 calls pciio_pio_write8 with a0=?, a1=[a1+880]+14, a2=?, a3=?.
  The `jal` at 0x2ef0 calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=?, a3=?.
  The `jal` at 0x2efc calls pciio_pio_read8 with a0=[a1+880]+14, a1=?, a2=?, a3=?.
  The `jal` at 0x2f10 calls pciio_pio_write8 with a0=?, a1=[a1+880]+14, a2=?, a3=?.
  The `jal` at 0x2f20 calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=?, a3=?.
  The `jal` at 0x2f2c calls pciio_pio_read8 with a0=[a1+880]+14, a1=?, a2=?, a3=?.
  The `jal` at 0x2f40 calls pciio_pio_write8 with a0=?, a1=[a1+880]+14, a2=?, a3=?.
  The `jal` at 0x2f50 calls pciio_pio_write16 with a0=0x1, a1=[a1+880]+10, a2=?, a3=?.
  The `jal` at 0x2f5c calls pciio_pio_read8 with a0=[a1+880]+14, a1=?, a2=?, a3=?.
  The `jal` at 0x2f74 calls pciio_pio_write8 with a0=?, a1=[a1+880]+14, a2=?, a3=?.
  The `beq` branch at 0x29cc targets 0x2c80, is taken when v0(=ret(tlan_eeprom_ack)) == 0, and falls through when v0(=ret(tlan_eeprom_ack)) != 0.
  The `beq` branch at 0x29e8 targets 0x2ccc, is taken when v0(=ret(tlan_eeprom_ack)) == 0, and falls through when v0(=ret(tlan_eeprom_ack)) != 0.
  The `beq` branch at 0x29f4 targets 0x2cd4, is taken when a0(=0x1) == a2(=a0), and falls through when a0(=0x1) != a2(=a0).
  The `blez` branch at 0x29fc targets 0x2a38, is taken when s3(=a4) <= 0 (signed), and falls through when s3(=a4) > 0 (signed).
  The `beq` branch at 0x2a20 targets 0x2cbc, is taken when v0(=ret(tlan_eeprom_ack)) == 0, and falls through when v0(=ret(tlan_eeprom_ack)) != 0.
  The `bne` branch at 0x2a30 targets 0x2a0c, is taken when s2(?) < s3(=a4) (signed), and falls through when s2(?) >= s3(=a4) (signed).
  The `beq` branch at 0x2c68 targets 0x2b64, is taken when v0(=ret(tlan_eeprom_ack)) == 0, and falls through when v0(=ret(tlan_eeprom_ack)) != 0.
  The `beq` branch at 0x2c78 targets 0x2c8c and is always taken.
  The `beq` branch at 0x2c84 targets 0x2cc4, is taken when a1(=[a5]) == 0, and falls through when a1(=[a5]) != 0.
  The `beq` branch at 0x2cbc targets 0x2c84 and is always taken.
  The `beq` branch at 0x2cc4 targets 0x2c8c and is always taken.
  The `beq` branch at 0x2ccc targets 0x2c84 and is always taken.
  The `beq` branch at 0x2e04 targets 0x2f7c, is taken when v0(=ret(tlan_eeprom_ack)) == 0, and falls through when v0(=ret(tlan_eeprom_ack)) != 0.
  The `beq` branch at 0x2e68 targets 0x2e74, is taken when (v0(=ret(pciio_pio_read8)) & 0x10) == 0, and falls through when (v0(=ret(pciio_pio_read8)) & 0x10) != 0.
  The `bne` branch at 0x2eac targets 0x2e18, is taken when s2(?) != 0, and falls through when s2(?) == 0.
  The `beq` branch at 0x2f7c targets 0x2c74, is taken when s5(?) == 0, and falls through when s5(?) != 0.
  The `beq` branch at 0x2f84 targets 0x2c84 and is always taken.
  The return at 0x2cb4 has v0 = one of ?, 0x0.

- `tlan_phydev` in `IP32/usr/cpu/sysgen/IP32boot/if_ecf.o` at 0x2f8c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/if_ecf.o`.
  Range: 0x2f8c-0x30d4 (328 bytes).
  It occupies 328 bytes.
  The `sw` at 0x3060 stores 4 bytes to a0 (arg0 at entry) +0x2a8.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x370, including `lw` at 0x3094, `lw` at 0x30a4, `lw` at 0x30b4.
  The `jal` at 0x2fa8 calls tlan_mii_init with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x3010 calls tlan_mii_io with a0=0x10, a1=a0 at entry (arg0), a2=?, a3=0x3, a4=0x0.
  The `jal` at 0x3030 calls tlan_mii_io with a0=0x10, a1=a0 at entry (arg0), a2=?, a3=0x2, a4=0x0.
  The `jal` at 0x309c calls pciio_pio_write16 with a0=0x4, a1=[a0+880]+10, a2=?, a3=?.
  The `jal` at 0x30a8 calls pciio_pio_read8 with a0=[a0+880]+15, a1=?, a2=?, a3=?.
  The `jal` at 0x30bc calls pciio_pio_write8 with a0=?, a1=[a0+880]+15, a2=?, a3=?.
  The `jal` at 0x30c4 calls tlan_mii_sync with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `beq` branch at 0x2fd0 targets 0x3064, is taken when s0(=a1) >= 0x20 (signed), and falls through when s0(=a1) < 0x20 (signed).
  The `beq` branch at 0x2fe0 targets 0x2ff8 and is always taken.
  The `beq` branch at 0x2ff0 targets 0x3064, is taken when s0(?) >= 0x20 (signed), and falls through when s0(?) < 0x20 (signed).
  The `beq` branch at 0x2ff8 targets 0x3094, is taken when s0(?) == s7(=0x1f), and falls through when s0(?) != s7(=0x1f).
  The `beq` branch at 0x3018 targets 0x2fe8, is taken when v0(=ret(tlan_mii_io)) == 0, and falls through when v0(=ret(tlan_mii_io)) != 0.
  The `beq` branch at 0x3038 targets 0x2fe8, is taken when v0(=ret(tlan_mii_io)) == 0, and falls through when v0(=ret(tlan_mii_io)) != 0.
  The `beq` branch at 0x3048 targets 0x3060, is taken when a0(?) == s4(=0x15f420), and falls through when a0(?) != s4(=0x15f420).
  The `beq` branch at 0x3050 targets 0x3060, is taken when a0(?) == s5(=0x20005c00), and falls through when a0(?) != s5(=0x20005c00).
  The `bnel` branch at 0x3058 targets 0x2fec, is taken when a0(?) != s6(=0x40005010), and falls through when a0(?) == s6(=0x40005010); its branch-likely delay slot `addiu s0,s0,1` at 0x305c runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x30cc targets 0x3000 and is always taken.
  The return at 0x308c has v0 = one of a1, ?.

- `tlan_autonego` in `IP32/usr/cpu/sysgen/IP32boot/if_ecf.o` at 0x30d4 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/if_ecf.o`.
  Range: 0x30d4-0x3328 (596 bytes).
  It occupies 596 bytes.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x2b4, including `sw` at 0x3100, `sw` at 0x3314.
  5 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x2af, including `lbu` at 0x3134, `lbu` at 0x3254, `lbu` at 0x326c.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x2b8, including `sw` at 0x3140, `sw` at 0x3308.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x370, including `lw` at 0x314c, `lw` at 0x3168.
  2 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x36b, including `lbu` at 0x3150, `lbu` at 0x316c.
  The `sb` at 0x3164 stores 1 byte to a0 (arg0 at entry) +0x36b.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x14, including `lw` at 0x3178, `lw` at 0x31b8.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x2b4, including `lw` at 0x3188, `lw` at 0x31bc.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x2b8, including `lw` at 0x3194, `lw` at 0x31e4.
  2 such `lh` accesses load 2 bytes from a0 (arg0 at entry) +0xe, including `lh` at 0x31b4, `lh` at 0x32f4.
  The `lw` at 0x31c4 loads 4 bytes from a0 (arg0 at entry) +0x24.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x24, including `sw` at 0x31e0, `sw` at 0x3220.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x14, including `sw` at 0x31fc, `sw` at 0x3230.
  The `jal` at 0x3144 calls tlan_mii_io with a0=0x1, a1=a0 at entry (arg0), a2=[a0+687]:1, a3=0x0, a6=one of 0x0, 0x2000, a7=one of 0x0, 0x100.
  The `jal` at 0x3160 calls pciio_pio_write16 with a0=0x44, a1=[a0+880]+10, a2=?, a3=?, a5=([a0+875]:1 | 0x1).
  The `jal` at 0x3170 calls pciio_pio_write8 with a0=[a0+875]:1, a1=[a0+880]+15, a2=?, a3=?.
  The `jal` at 0x31b0 calls printf with a0=sym(.rodata), a1=sym(.rodata), a2=[a0+14]:2, a3=sym(.rodata), a4=sym(.rodata), a6=sym(.rodata).
  The `jal` at 0x3258 calls tlan_mii_io with a0=0x1, a1=a0 at entry (arg0), a2=[a0+687]:1, a3=0x0, a4=0x1200, a6=0x2000.
  The `jal` at 0x3270 calls tlan_mii_io with a0=0x10, a1=a0 at entry (arg0), a2=[a0+687]:1, a3=0x1, a4=0x0.
  The `jal` at 0x329c calls us_delaybus with a0=0xa, a1=0x493e0, a2=?, a3=?.
  The `jal` at 0x32b4 calls tlan_mii_io with a0=0x10, a1=a0 at entry (arg0), a2=[a0+687]:1, a3=0x1, a4=0x0.
  The `jal` at 0x32d0 calls tlan_setspdpx with a0=a0 at entry (arg0), a1=0x493e0, a2=?, a3=?.
  The `jal` at 0x32f8 calls cmn_err_tag with a0=0xc7, a1=0x1, a2=sym(.rodata), a3=sym(.rodata), a4=[a0+14]:2.
  The `jal` at 0x3318 calls tlan_mii_io with a0=0x1, a1=a0 at entry (arg0), a2=[a0+687]:1, a3=0x0, a4=0x0.
  The `beq` branch at 0x30e8 targets 0x3248, is taken when a1(=[sym(ecf_spdpx)]) == 0, and falls through when a1(=[sym(ecf_spdpx)]) != 0.
  The `beq` branch at 0x30f4 targets 0x3100, is taken when a1(=[sym(ecf_spdpx)]) >= 0x3 (signed), and falls through when a1(=[sym(ecf_spdpx)]) < 0x3 (signed).
  The `beq` branch at 0x3120 targets 0x312c, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x3180 targets 0x31bc, is taken when (a0(=[a0+20]) & 0x4) == 0, and falls through when (a0(=[a0+20]) & 0x4) != 0.
  The `beq` branch at 0x3190 targets 0x3234, is taken when a3(=[a0+692]) == 0, and falls through when a3(=[a0+692]) != 0.
  The `beq` branch at 0x31a0 targets 0x323c, is taken when a0(=[a0+696]) == 0, and falls through when a0(=[a0+696]) != 0.
  The `beq` branch at 0x31d4 targets 0x3210, is taken when a4(=[a0+692]) == a5(=0x2000), and falls through when a4(=[a0+692]) != a5(=0x2000).
  The `beq` branch at 0x31f4 targets 0x3224, is taken when a2(=[a0+696]) == a3(=0x100), and falls through when a2(=[a0+696]) != a3(=0x100).
  The `beq` branch at 0x321c targets 0x31e4 and is always taken.
  The `beq` branch at 0x322c targets 0x3200 and is always taken.
  The `beq` branch at 0x3234 targets 0x31a0 and is always taken.
  The `beq` branch at 0x3240 targets 0x31a8 and is always taken.
  The `bne` branch at 0x3284 targets 0x32d0, is taken when (v0(=ret(tlan_mii_io)) & 0x20) != 0, and falls through when (v0(=ret(tlan_mii_io)) & 0x20) == 0.
  The `bne` branch at 0x3294 targets 0x32e0, is taken when a1(=0x493e0) < a0(?) (signed), and falls through when a1(=0x493e0) >= a0(?) (signed).
  The `beq` branch at 0x32c8 targets 0x328c, is taken when (v0(=ret(tlan_mii_io)) & 0x20) == 0, and falls through when (v0(=ret(tlan_mii_io)) & 0x20) != 0.
  The `beq` branch at 0x32d8 targets 0x3204 and is always taken.
  The `beq` branch at 0x3320 targets 0x3204 and is always taken.
  The return at 0x3208 has v0 = one of ?, ret(tlan_setspdpx), ret(tlan_mii_io).

- `tlan_setspdpx` in `IP32/usr/cpu/sysgen/IP32boot/if_ecf.o` at 0x3328 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/if_ecf.o`.
  Range: 0x3328-0x3584 (604 bytes).
  It occupies 604 bytes.
  2 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x36b, including `lbu` at 0x3330, `lbu` at 0x3358.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x370, including `lw` at 0x3338, `lw` at 0x3354.
  The `sb` at 0x3340 stores 1 byte to a0 (arg0 at entry) +0x36b.
  The `lw` at 0x3364 loads 4 bytes from a0 (arg0 at entry) +0x2a8.
  The `lw` at 0x336c loads 4 bytes from a0 (arg0 at entry) +0x2ac.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x14, including `lw` at 0x3398, `lw` at 0x3454, `lw` at 0x34c4.
  7 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x2b4, including `sw` at 0x33b4, `sw` at 0x3468, `sw` at 0x34a4.
  7 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x2b8, including `sw` at 0x33c4, `sw` at 0x3460, `sw` at 0x34b8.
  3 such `lh` accesses load 2 bytes from a0 (arg0 at entry) +0xe, including `lh` at 0x33e0, `lh` at 0x3498, `lh` at 0x356c.
  The `lbu` at 0x3424 loads 1 byte from a0 (arg0 at entry) +0x2af.
  The `lw` at 0x34d4 loads 4 bytes from a0 (arg0 at entry) +0x2b4.
  The `lw` at 0x34dc loads 4 bytes from a0 (arg0 at entry) +0x2b8.
  The `jal` at 0x334c calls pciio_pio_write16 with a0=0x44, a1=[a0+880]+10, a2=([a0+875]:1 | 0x1), a3=a3 at entry (arg3).
  The `jal` at 0x335c calls pciio_pio_write8 with a0=[a0+875]:1, a1=[a0+880]+15, a2=?, a3=?.
  The `jal` at 0x338c calls tlan_mii_io with a0=0x10, a1=a0 at entry (arg0), a2=?, a3=0x1, a4=0x0.
  The `jal` at 0x33e4 calls printf with a0=sym(.rodata), a1=sym(.rodata), a2=[a0+14]:2, a3=sym(.rodata), a4=sym(.rodata), a5=sym(.rodata).
  The `jal` at 0x340c calls tlan_mii_io with a0=0x10, a1=a0 at entry (arg0), a2=?, a3=0x4, a4=0x0.
  The `jal` at 0x3428 calls tlan_mii_io with a0=0x10, a1=a0 at entry (arg0), a2=[a0+687]:1, a3=0x5, a4=0x0.
  The `jal` at 0x34a8 calls cmn_err_tag with a0=0xc8, a1=0x4, a2=sym(.rodata), a3=sym(.rodata), a4=[a0+14]:2, a7=0x2000.
  The `jal` at 0x34bc calls tlan_autonego with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x3570 calls cmn_err_tag with a0=0xc9, a1=0x4, a2=sym(.rodata), a3=sym(.rodata), a4=[a0+14]:2.
  The `bne` branch at 0x3378 targets 0x3400, is taken when a3(=[a0+680]) != a4(=0x20005c00), and falls through when a3(=[a0+680]) == a4(=0x20005c00).
  The `beq` branch at 0x33a8 targets 0x33b4, is taken when (v0(=ret(tlan_mii_io)) & 0x2) == 0, and falls through when (v0(=ret(tlan_mii_io)) & 0x2) != 0.
  The `beq` branch at 0x33c0 targets 0x33ec, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x33c8 targets 0x34f4, is taken when a0(=one of 0x0, 0x2000) == 0, and falls through when a0(=one of 0x0, 0x2000) != 0.
  The `beq` branch at 0x33d0 targets 0x34e8, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x344c targets 0x3474, is taken when (a0(?) & 0x200) == 0, and falls through when (a0(?) & 0x200) != 0.
  The `beq` branch at 0x3464 targets 0x33ec, is taken when (a5(=[a0+20]) & 0x4) == 0, and falls through when (a5(=[a0+20]) & 0x4) != 0.
  The `beq` branch at 0x346c targets 0x33dc and is always taken.
  The `beq` branch at 0x3480 targets 0x3504, is taken when (a0(?) & 0x100) == 0, and falls through when (a0(?) & 0x100) != 0.
  The `beq` branch at 0x34cc targets 0x33ec, is taken when (t9(=[a0+20]) & 0x4) == 0, and falls through when (t9(=[a0+20]) & 0x4) != 0.
  The `bne` branch at 0x34d8 targets 0x33d0, is taken when ra(=[a0+692]) != 0, and falls through when ra(=[a0+692]) == 0.
  The `beq` branch at 0x34e0 targets 0x3518 and is always taken.
  The `beq` branch at 0x34ec targets 0x33e0 and is always taken.
  The `beq` branch at 0x34fc targets 0x33d0 and is always taken.
  The `beq` branch at 0x3504 targets 0x3520, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x3510 targets 0x34c4 and is always taken.
  The `beq` branch at 0x3518 targets 0x33d0 and is always taken.
  The `beq` branch at 0x3520 targets 0x353c, is taken when t8(?) == 0, and falls through when t8(?) != 0.
  The `beq` branch at 0x3534 targets 0x34c4 and is always taken.
  The `beq` branch at 0x3540 targets 0x355c, is taken when (a0(?) & 0x20) == 0, and falls through when (a0(?) & 0x20) != 0.
  The `beq` branch at 0x3554 targets 0x34c4 and is always taken.
  The `beq` branch at 0x357c targets 0x34c4 and is always taken.
  The return at 0x33f8 has v0 = one of 0x0, ret(printf), ret(tlan_mii_io), ?.

- `tlan_phystatus` in `IP32/usr/cpu/sysgen/IP32boot/if_ecf.o` at 0x3584 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/if_ecf.o`.
  Range: 0x3584-0x380c (648 bytes).
  It occupies 648 bytes.
  2 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x2af, including `lbu` at 0x35ac, `lbu` at 0x37f8.
  4 such `lhu` accesses load 2 bytes from a0 (arg0 at entry) +0x368, including `lhu` at 0x35b0, `lhu` at 0x3638, `lhu` at 0x36b8.
  6 such `sh` accesses store 2 bytes to a0 (arg0 at entry) +0x368, including `sh` at 0x35d8, `sh` at 0x36c8, `sh` at 0x36d8.
  2 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x36a, including `sb` at 0x35dc, `sb` at 0x37cc.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x2c0, including `lw` at 0x35ec, `lw` at 0x3738, `lw` at 0x373c.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x2b4, including `lw` at 0x35f8, `lw` at 0x3670.
  The `lw` at 0x3610 loads 4 bytes from a0 (arg0 at entry) +0x2b8.
  4 such `lh` accesses load 2 bytes from a0 (arg0 at entry) +0xe, including `lh` at 0x362c, `lh` at 0x36e0, `lh` at 0x3708.
  The `sw` at 0x3644 stores 4 bytes to a0 (arg0 at entry) +0x2c0.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x370, including `lw` at 0x376c, `lw` at 0x378c.
  2 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x36b, including `lbu` at 0x3774, `lbu` at 0x3790.
  The `sb` at 0x3788 stores 1 byte to a0 (arg0 at entry) +0x36b.
  The `lbu` at 0x37a4 loads 1 byte from a0 (arg0 at entry) +0x36a.
  The `lw` at 0x37d0 loads 4 bytes from a0 (arg0 at entry) +0x2a8.
  The `jal` at 0x35a8 calls tlan_mii_io with a0=0x10, a1=a0 at entry (arg0), a2=[a0+687]:1, a3=0x1, a4=0x0.
  The `jal` at 0x3630 calls cmn_err_tag with a0=0xcb, a1=0x1, a2=sym(.rodata), a3=sym(.rodata), a4=[a0+14]:2, a5=sym(.rodata), a6=sym(.rodata).
  The `jal` at 0x36f0 calls cmn_err_tag with a0=0xcd, a1=0x1, a2=sym(.rodata), a3=sym(.rodata), a4=[a0+14]:2.
  The `jal` at 0x3718 calls cmn_err_tag with a0=0xcc, a1=0x1, a2=sym(.rodata), a3=sym(.rodata), a4=[a0+14]:2, a5=[a0+872]:2.
  The `jal` at 0x372c calls tlan_setspdpx with a0=a0 at entry (arg0), a1=?, a2=?, a3=?, a5=[a0+872]:2.
  The `jal` at 0x3764 calls cmn_err_tag with a0=0xca, a1=0x1, a2=sym(.rodata), a3=sym(.rodata), a4=[a0+14]:2, a5=[a0+872]:2.
  The `jal` at 0x3784 calls pciio_pio_write16 with a0=0x44, a1=[a0+880]+10, a2=?, a3=?, a4=-0x2.
  The `jal` at 0x3794 calls pciio_pio_write8 with a0=[a0+875]:1, a1=[a0+880]+15, a2=?, a3=?.
  The `jal` at 0x37e4 calls tlan_mii_init with a0=a0 at entry (arg0), a1=?, a2=?, a3=[a0+680], a4=0x15f420.
  The `jal` at 0x37fc calls tlan_mii_io with a0=0x1, a1=a0 at entry (arg0), a2=[a0+687]:1, a3=0x0, a4=0x1200.
  The `beq` branch at 0x35c0 targets 0x36a0, is taken when (v0(=ret(tlan_mii_io)) & 0x4) == 0, and falls through when (v0(=ret(tlan_mii_io)) & 0x4) != 0.
  The `beq` branch at 0x35c8 targets 0x3640, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x35e4 targets 0x372c, is taken when v0(=[sym(ecf_spdpx)]) == 0, and falls through when v0(=[sym(ecf_spdpx)]) != 0.
  The `beq` branch at 0x35f0 targets 0x3638, is taken when a0(=[a0+704]) == 0, and falls through when a0(=[a0+704]) != 0.
  The `beq` branch at 0x3600 targets 0x3610, is taken when a1(=[a0+692]) == 0, and falls through when a1(=[a0+692]) != 0.
  The `beq` branch at 0x3614 targets 0x3620, is taken when a2(=[a0+696]) == 0, and falls through when a2(=[a0+696]) != 0.
  The `beq` branch at 0x3650 targets 0x36bc, is taken when (s8(=ret(tlan_mii_io)) & 0x10) == 0, and falls through when (s8(=ret(tlan_mii_io)) & 0x10) != 0.
  The `beq` branch at 0x365c targets 0x3700, is taken when (a5(=[a0+872]:2) & 0x10) == 0, and falls through when (a5(=[a0+872]:2) & 0x10) != 0.
  The `beq` branch at 0x3668 targets 0x36d0, is taken when (v0(=ret(tlan_mii_io)) & 0x2) == 0, and falls through when (v0(=ret(tlan_mii_io)) & 0x2) != 0.
  The `beq` branch at 0x3678 targets 0x36cc, is taken when v0(=[a0+692]) == v1(=0x2000), and falls through when v0(=[a0+692]) != v1(=0x2000).
  The `beq` branch at 0x3680 targets 0x36dc, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x36a0 targets 0x373c, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x36ac targets 0x37a4, is taken when t8(=[sym(ecf_spdpx)]) == 0, and falls through when t8(=[sym(ecf_spdpx)]) != 0.
  The `beq` branch at 0x36b4 targets 0x364c and is always taken.
  The `beq` branch at 0x36c4 targets 0x3664 and is always taken.
  The `beq` branch at 0x36d4 targets 0x3688 and is always taken.
  The `beq` branch at 0x36f8 targets 0x368c and is always taken.
  The `beq` branch at 0x3724 targets 0x3664 and is always taken.
  The `beq` branch at 0x3734 targets 0x35f0 and is always taken.
  The `beq` branch at 0x3744 targets 0x376c, is taken when t9(=[a0+704]) == 0, and falls through when t9(=[a0+704]) != 0.
  The `beq` branch at 0x379c targets 0x36a8 and is always taken.
  The `bne` branch at 0x37c8 targets 0x36b4, is taken when (a2(?) & 0xff) != 0, and falls through when (a2(?) & 0xff) == 0.
  The `bne` branch at 0x37dc targets 0x36b4, is taken when a3(=[a0+680]) != a4(=0x15f420), and falls through when a3(=[a0+680]) == a4(=0x15f420).
  The `beq` branch at 0x3804 targets 0x36b4 and is always taken.
  The return at 0x3698 has v0 = one of ?, ret(cmn_err_tag).

- `tlan_statistics` in `IP32/usr/cpu/sysgen/IP32boot/if_ecf.o` at 0x380c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/if_ecf.o`.
  Range: 0x380c-0x3a38 (556 bytes).
  It occupies 556 bytes.
  6 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x370, including `lw` at 0x3810, `lw` at 0x382c, `lw` at 0x3840.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x334, including `lw` at 0x3848, `lw` at 0x39cc.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x32c, including `lw` at 0x3850, `lw` at 0x39d0.
  The `sw` at 0x3860 stores 4 bytes to a0 (arg0 at entry) +0x334.
  The `sw` at 0x3870 stores 4 bytes to a0 (arg0 at entry) +0x32c.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x338, including `lw` at 0x3880, `lw` at 0x39e8.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x330, including `lw` at 0x3888, `lw` at 0x39ec.
  The `sw` at 0x3898 stores 4 bytes to a0 (arg0 at entry) +0x338.
  The `sw` at 0x38a8 stores 4 bytes to a0 (arg0 at entry) +0x330.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x340, including `lw` at 0x38b8, `lw` at 0x39e4.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x344, including `lw` at 0x38bc, `lw` at 0x39e0.
  The `sw` at 0x38cc stores 4 bytes to a0 (arg0 at entry) +0x344.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x33c, including `lw` at 0x38d4, `lw` at 0x39c8.
  The `sw` at 0x38e0 stores 4 bytes to a0 (arg0 at entry) +0x340.
  The `sw` at 0x38ec stores 4 bytes to a0 (arg0 at entry) +0x33c.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x34c, including `lw` at 0x3900, `lw` at 0x3a00.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x348, including `lw` at 0x3908, `lw` at 0x3a04.
  The `sw` at 0x3914 stores 4 bytes to a0 (arg0 at entry) +0x34c.
  The `sw` at 0x3920 stores 4 bytes to a0 (arg0 at entry) +0x348.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x360, including `lw` at 0x3924, `lw` at 0x39c4.
  The `sw` at 0x392c stores 4 bytes to a0 (arg0 at entry) +0x50.
  The `lw` at 0x3930 loads 4 bytes from a0 (arg0 at entry) +0x38.
  The `sw` at 0x393c stores 4 bytes to a0 (arg0 at entry) +0x2c.
  The `lw` at 0x3944 loads 4 bytes from a0 (arg0 at entry) +0x34.
  The `lw` at 0x3948 loads 4 bytes from a0 (arg0 at entry) +0x14.
  The `sw` at 0x3950 stores 4 bytes to a0 (arg0 at entry) +0x34.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x358, including `lw` at 0x3954, `lw` at 0x3a10.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x354, including `lw` at 0x395c, `lw` at 0x39f8.
  The `sw` at 0x396c stores 4 bytes to a0 (arg0 at entry) +0x358.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x350, including `lw` at 0x3984, `lw` at 0x39fc.
  The `sw` at 0x398c stores 4 bytes to a0 (arg0 at entry) +0x354.
  The `sw` at 0x3998 stores 4 bytes to a0 (arg0 at entry) +0x350.
  The `sw` at 0x39a8 stores 4 bytes to a0 (arg0 at entry) +0x38.
  The `lh` at 0x39b8 loads 2 bytes from a0 (arg0 at entry) +0xe.
  The `lw` at 0x39dc loads 4 bytes from a0 (arg0 at entry) +0x364.
  The `jal` at 0x3824 calls pciio_pio_write16 with a0=0x8030, a1=[a0+880]+10, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x3834 calls pciio_pio_read32 with a0=[a0+880]+12, a1=?, a2=?, a3=?.
  The `jal` at 0x386c calls pciio_pio_read32 with a0=[a0+880]+12, a1=?, a2=?, a3=?.
  The `jal` at 0x38a4 calls pciio_pio_read32 with a0=[a0+880]+12, a1=?, a2=?, a3=?.
  The `jal` at 0x38e8 calls pciio_pio_read32 with a0=[a0+880]+12, a1=?, a2=?, a3=?.
  The `jal` at 0x391c calls pciio_pio_read32 with a0=[a0+880]+12, a1=?, a2=?, a3=?.
  The `jal` at 0x39bc calls printf with a0=sym(.rodata), a1=sym(.rodata), a2=[a0+14]:2, a3=?.
  The `jal` at 0x39d4 calls printf with a0=sym(.rodata), a1=[a0+812], a2=[a0+820], a3=[a0+828], a4=[a0+864].
  The `jal` at 0x39f0 calls printf with a0=sym(.rodata), a1=[a0+816], a2=[a0+824], a3=[a0+832], a4=[a0+836], a5=[a0+868].
  The `jal` at 0x3a08 calls printf with a0=sym(.rodata), a1=[a0+840], a2=[a0+844], a3=[a0+848], a4=[a0+852].
  The `jal` at 0x3a14 calls printf with a0=sym(.rodata), a1=[a0+856], a2=?, a3=?.
  The `beq` branch at 0x39a4 targets 0x3a1c, is taken when (a2(=[a0+20]) & 0x4) == 0, and falls through when (a2(=[a0+20]) & 0x4) != 0.
  The return at 0x3a30 has v0 = one of ret(pciio_pio_read32), ret(printf).

- `if_ecfinit` in `IP32/usr/cpu/sysgen/IP32boot/if_ecf.o` at 0x3a38 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/if_ecf.o`.
  Range: 0x3a38-0x3a84 (76 bytes).
  It occupies 76 bytes.
  The `jal` at 0x3a54 calls pciio_driver_register with a0=0xe11, a1=0xae32, a2=sym(.rodata), a3=0x0.
  The `jal` at 0x3a70 calls pciio_driver_register with a0=0x104c, a1=0x500, a2=sym(.rodata), a3=0x0.
  The return at 0x3a7c has v0 = ret(pciio_driver_register).

- `if_ecfattach` in `IP32/usr/cpu/sysgen/IP32boot/if_ecf.o` at 0x3a84 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/if_ecf.o`.
  Range: 0x3a84-0x3f4c (1224 bytes).
  It occupies 1224 bytes.
  The `sw` at 0x3b24 stores 4 bytes to ret(kmem_zalloc) +0x3a8.
  The `sw` at 0x3b28 stores 4 bytes to ret(kmem_zalloc) +0x3a4.
  The `sh` at 0x3b38 stores 2 bytes to ret(kmem_zalloc) +0xe.
  The `sw` at 0x3b50 stores 4 bytes to ret(kmem_zalloc) +0x3ac.
  3 such `lw` accesses load 4 bytes from ret(kmem_zalloc) +0x3ac, including `lw` at 0x3b58, `lw` at 0x3b64, `lw` at 0x3dc0.
  The `sw` at 0x3ba0 stores 4 bytes to ret(kmem_zalloc) +0x28c.
  The `sw` at 0x3bac stores 4 bytes to ret(kmem_zalloc) +0x370.
  The `sw` at 0x3bb8 stores 4 bytes to ret(kmem_zalloc) +0x290.
  6 such `lh` accesses load 2 bytes from ret(kmem_zalloc) +0xe, including `lh` at 0x3bd4, `lh` at 0x3db0, `lh` at 0x3de4.
  The `sw` at 0x3bf4 stores 4 bytes to ret(kmem_zalloc) +0x294.
  The `sw` at 0x3c00 stores 4 bytes to ret(kmem_zalloc) +0x298.
  The `sb` at 0x3c0c stores 1 byte to ret(kmem_zalloc) +0x29c.
  5 such `lw` accesses load 4 bytes from ret(kmem_zalloc) +0x28c, including `lw` at 0x3c24, `lw` at 0x3c3c, `lw` at 0x3c50.
  The `sb` at 0x3c28 stores 1 byte to ret(kmem_zalloc) +0x29d.
  5 such `sw` accesses store 4 bytes to abs 0xffffffffbf080cf8, including `sw` at 0x3c34, `sw` at 0x3c4c, `sw` at 0x3c58.
  3 such `lw` accesses load 4 bytes from abs 0xffffffffbf080cfc, including `lw` at 0x3c38, `lw` at 0x3c5c, `lw` at 0x3c88.
  The `sw` at 0x3c44 stores 4 bytes to ret(kmem_zalloc) +0x2a0.
  2 such `sw` accesses store 4 bytes to abs 0xffffffffbf080cfc, including `sw` at 0x3c6c, `sw` at 0x3ca0.
  2 such `sb` accesses store 1 byte to ?, including `sb` at 0x3ccc, `sb` at 0x3cd8.
  The `sw` at 0x3d1c stores 4 bytes to ret(kmem_zalloc) +0x2fc.
  The `sw` at 0x3d28 stores 4 bytes to ret(kmem_zalloc) +0x2f8.
  The `sw` at 0x3d64 stores 4 bytes to ret(kmem_zalloc) +0x2c8.
  The `sw` at 0x3d78 stores 4 bytes to ret(kmem_zalloc) +0x2c4.
  The `sw` at 0x3d90 stores 4 bytes to ret(kmem_zalloc) +0x14.
  The `sw` at 0x3dd4 stores 4 bytes to ret(kmem_zalloc) +0x2a4.
  2 such `lw` accesses load 4 bytes from ret(kmem_zalloc) +0x294, including `lw` at 0x3e2c, `lw` at 0x3e30.
  The `lw` at 0x3e34 loads 4 bytes from ret(kmem_zalloc) +0x298.
  The `lbu` at 0x3e38 loads 1 byte from ret(kmem_zalloc) +0x29d.
  The `lbu` at 0x3e40 loads 1 byte from ret(kmem_zalloc) +0x29c.
  The `lw` at 0x3e4c loads 4 bytes from ret(kmem_zalloc) +0x2a0.
  The `lw` at 0x3ebc loads 4 bytes from ret(kmem_zalloc) +0x2b4.
  The `jal` at 0x3ab0 calls hwgraph_char_device_add with a0=a0 at entry (arg0), a1=sym(.rodata), a2=sym(.rodata), a3=sp-128.
  The `jal` at 0x3ad8 calls cmn_err_tag with a0=0xce, a1=0x4, a2=sym(.rodata), a3=sym(.rodata), a4=[sym(ecf_no)].
  The `jal` at 0x3b04 calls kmem_zalloc with a0=0x3b8, a1=0x0, a2=?, a3=?.
  The `jal` at 0x3b18 calls device_info_set with a0=a0 at entry (arg0), a1=ret(kmem_zalloc), a2=?, a3=?.
  The `jal` at 0x3b3c calls device_desc_dup with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x3b4c calls device_desc_intr_name_set with a0=ret(device_desc_dup), a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x3b5c calls device_desc_intr_swlevel_set with a0=[ret(kmem_zalloc)+940], a1=sym(splimp), a2=?, a3=?.
  The `jal` at 0x3b68 calls device_desc_default_set with a0=a0 at entry (arg0), a1=[ret(kmem_zalloc)+940], a2=?, a3=?.
  The `jal` at 0x3b84 calls pciio_piotrans_addr with a0=a0 at entry (arg0), a1=0x0, a2=0x7, a3=0x0, a4=0x40, a5=0x0.
  The `jal` at 0x3ba4 calls pciio_piotrans_addr with a0=a0 at entry (arg0), a1=0x0, a2=0x9, a3=0x0, a4=0x400, a5=0x0.
  The `jal` at 0x3bbc calls pciio_endian_set with a0=a0 at entry (arg0), a1=0x1, a2=0x0, a3=?.
  The `jal` at 0x3bd8 calls cmn_err_tag with a0=0xd0, a1=0x4, a2=sym(.rodata), a3=sym(.rodata), a4=[ret(kmem_zalloc)+14]:2.
  The `jal` at 0x3be0 calls pciio_info_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x3bec calls pciio_info_device_id_get with a0=ret(pciio_info_get), a1=?, a2=?, a3=?.
  The `jal` at 0x3bf8 calls pciio_info_vendor_id_get with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x3c04 calls pciio_info_bus_get with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x3c1c calls pciio_info_slot_get with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x3cb8 calls tlan_eeprom_io with a0=0x1, a1=ret(kmem_zalloc), a2=?, a3=0x0, a4=0x1, a5=sp-124.
  The `jal` at 0x3cfc calls contig_memalloc with a0=?, a1=0x1, a2=0x111, a3=?.
  The `jal` at 0x3d4c calls contig_memalloc with a0=?, a1=0x1, a2=0x111, a3=?.
  The `jal` at 0x3d74 calls spinlock_init with a0=ret(kmem_zalloc)+748, a1=0x0, a2=?, a3=(ret(contig_memalloc)+655360 << 0xc).
  The `jal` at 0x3db4 calls ether_attach with a0=ret(kmem_zalloc), a1=sym(.rodata), a2=[ret(kmem_zalloc)+14]:2, a3=ret(kmem_zalloc), a4=sym(.data), a5=ret(kmem_zalloc)+884, a6=0x19, a7=-0x1.
  The `jal` at 0x3dc8 calls pciio_intr_alloc with a0=a0 at entry (arg0), a1=[ret(kmem_zalloc)+940], a2=0x1, a3=a0 at entry (arg0).
  The `jal` at 0x3de8 calls cmn_err_tag with a0=0xd1, a1=0x4, a2=sym(.rodata), a3=sym(.rodata), a4=[ret(kmem_zalloc)+14]:2.
  The `jal` at 0x3e0c calls pciio_intr_connect with a0=ret(pciio_intr_alloc), a1=sym(if_ecfintr), a2=ret(kmem_zalloc), a3=0x0.
  The `jal` at 0x3e28 calls find_inventory with a0=0x0, a1=0x8, a2=0x0, a3=0x19, a4=[ret(kmem_zalloc)+14]:2, a5=[ret(kmem_zalloc)+660].
  The `jal` at 0x3e78 calls device_inventory_add with a0=a0 at entry (arg0), a1=0x8, a2=0x0, a3=0x19, a4=(([ret(kmem_zalloc)+672] | ([ret(kmem_zalloc)+669]:1 << 0x8)) | (([ret(kmem_zalloc)+14]:2 << 0x18) | ([ret(kmem_zalloc)+668]:1 << 0x10))), a5=([ret(kmem_zalloc)+660] | ([ret(kmem_zalloc)+664] << 0x10)), a6=(([ret(kmem_zalloc)+14]:2 << 0x18) | ([ret(kmem_zalloc)+668]:1 << 0x10)), a7=([ret(kmem_zalloc)+668]:1 << 0x10).
  The `jal` at 0x3e94 calls replace_in_inventory with a0=ret(find_inventory), a1=0x8, a2=0x0, a3=0x19, a4=(([ret(kmem_zalloc)+672] | ([ret(kmem_zalloc)+669]:1 << 0x8)) | (([ret(kmem_zalloc)+14]:2 << 0x18) | ([ret(kmem_zalloc)+668]:1 << 0x10))), a5=([ret(kmem_zalloc)+660] | ([ret(kmem_zalloc)+664] << 0x10)), a6=(([ret(kmem_zalloc)+14]:2 << 0x18) | ([ret(kmem_zalloc)+668]:1 << 0x10)), a7=([ret(kmem_zalloc)+668]:1 << 0x10).
  The `jal` at 0x3ea8 calls sprintf with a0=sp-120, a1=sym(.rodata), a2=sym(.rodata), a3=[ret(kmem_zalloc)+14]:2.
  The `jal` at 0x3eb4 calls if_hwgraph_alias_add with a0=a0 at entry (arg0), a1=sp-120, a2=?, a3=?.
  The `jal` at 0x3efc calls ps_init with a0=ret(kmem_zalloc), a1=sp-112, a2=?, a3=?.
  The `jal` at 0x3f1c calls cmn_err_tag with a0=0xcf, a1=0x1, a2=sym(.rodata), a3=sym(.rodata), a4=[sym(ecf_no)].
  The `beq` branch at 0x3ac0 targets 0x3b00, is taken when v0(=ret(hwgraph_char_device_add)) == 0, and falls through when v0(=ret(hwgraph_char_device_add)) != 0.
  The `beq` branch at 0x3b0c targets 0x3f0c, is taken when v0(=ret(kmem_zalloc)) == 0, and falls through when v0(=ret(kmem_zalloc)) != 0.
  The `beq` branch at 0x3bc4 targets 0x3be0, is taken when v0(=ret(pciio_endian_set)) == 0, and falls through when v0(=ret(pciio_endian_set)) != 0.
  The `bne` branch at 0x3cd4 targets 0x3ca4, is taken when s5(?) < 0x6 (signed), and falls through when s5(?) >= 0x6 (signed).
  The `beq` branch at 0x3d10 targets 0x3f2c, is taken when v0(=ret(contig_memalloc)) == 0, and falls through when v0(=ret(contig_memalloc)) != 0.
  The `beq` branch at 0x3d54 targets 0x3f34, is taken when v0(=ret(contig_memalloc)) == 0, and falls through when v0(=ret(contig_memalloc)) != 0.
  The `beq` branch at 0x3d84 targets 0x3d98, is taken when (a4(=[sym(if_ecfdevflag)]) & 0x1000) == 0, and falls through when (a4(=[sym(if_ecfdevflag)]) & 0x1000) != 0.
  The `bne` branch at 0x3dd0 targets 0x3dfc, is taken when v0(=ret(pciio_intr_alloc)) != 0, and falls through when v0(=ret(pciio_intr_alloc)) == 0.
  The `beq` branch at 0x3df4 targets 0x3f04 and is always taken.
  The `bne` branch at 0x3e64 targets 0x3e88, is taken when v0(=ret(find_inventory)) != 0, and falls through when v0(=ret(find_inventory)) == 0.
  The `beq` branch at 0x3e80 targets 0x3e9c and is always taken.
  The `beq` branch at 0x3ec4 targets 0x3f3c, is taken when (t2(=[ret(kmem_zalloc)+692]) & 0x2000) == 0, and falls through when (t2(=[ret(kmem_zalloc)+692]) & 0x2000) != 0.
  The `beq` branch at 0x3f04 targets 0x3ae4 and is always taken.
  The `beq` branch at 0x3f24 targets 0x3ae4 and is always taken.
  The `beq` branch at 0x3f2c targets 0x3ae8 and is always taken.
  The `beq` branch at 0x3f34 targets 0x3ae8 and is always taken.
  The `beq` branch at 0x3f44 targets 0x3ed4 and is always taken.
  The return at 0x3af8 has v0 = one of ?, 0xc.

- `if_ecfdetach` in `IP32/usr/cpu/sysgen/IP32boot/if_ecf.o` at 0x3f4c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/if_ecf.o`.
  Range: 0x3f4c-0x408c (320 bytes).
  It occupies 320 bytes.
  The `sh` at 0x3fd0 stores 2 bytes to ret(device_info_get) +0x10.
  The `sw` at 0x3fdc stores 4 bytes to ret(device_info_get) +0x5c.
  The `sw` at 0x3fe0 stores 4 bytes to ret(device_info_get) +0x60.
  The `sw` at 0x3fe4 stores 4 bytes to ret(device_info_get) +0x64.
  The `lw` at 0x3ff0 loads 4 bytes from ret(device_info_get) +0x14.
  The `sw` at 0x3ffc stores 4 bytes to ret(device_info_get) +0x68.
  The `sw` at 0x4008 stores 4 bytes to ret(device_info_get) +0x14.
  The `lh` at 0x401c loads 2 bytes from ret(device_info_get) +0xe.
  2 such `lw` accesses load 4 bytes from ret(device_info_get) +0x2a4, including `lw` at 0x403c, `lw` at 0x4044.
  The `lw` at 0x404c loads 4 bytes from ret(device_info_get) +0x3ac.
  The `jal` at 0x3f6c calls hwgraph_traverse with a0=a0 at entry (arg0), a1=sym(.rodata), a2=sp-64, a3=a3 at entry (arg3).
  The `jal` at 0x3f80 calls device_info_get with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x3f98 calls cmn_err_tag with a0=0xd2, a1=0x4, a2=sym(.rodata), a3=?.
  The `jal` at 0x3fb0 calls pciio_error_register with a0=a0 at entry (arg0), a1=0x0, a2=0x0, a3=?.
  The `jal` at 0x3fc0 calls mutex_lock with a0=ret(device_info_get)+152, a1=0x19, a2=?, a3=?.
  The `jal` at 0x3fc8 calls if_down with a0=[sym(ifnet)], a1=?, a2=?, a3=?.
  The `jal` at 0x4004 calls hwgraph_edge_remove with a0=a0 at entry (arg0), a1=sym(.rodata), a2=0x0, a3=?.
  The `jal` at 0x400c calls hwgraph_vertex_destroy with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x4020 calls sprintf with a0=sp-56, a1=sym(.rodata), a2=sym(.rodata), a3=[ret(device_info_get)+14]:2.
  The `jal` at 0x4028 calls if_hwgraph_alias_remove with a0=sp-56, a1=?, a2=?, a3=?.
  The `jal` at 0x4030 calls spinlock_destroy with a0=ret(device_info_get)+748, a1=?, a2=?, a3=?.
  The `jal` at 0x4038 calls pciio_intr_disconnect with a0=[ret(device_info_get)+676], a1=?, a2=?, a3=?.
  The `jal` at 0x4040 calls pciio_intr_free with a0=[ret(device_info_get)+676], a1=?, a2=?, a3=?.
  The `jal` at 0x4048 calls device_desc_free with a0=[ret(device_info_get)+940], a1=?, a2=?, a3=?.
  The `jal` at 0x4054 calls ecf_reset with a0=ret(device_info_get), a1=?, a2=?, a3=?.
  The `jal` at 0x405c calls mutex_unlock with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x4068 calls kmem_free with a0=ret(device_info_get), a1=0x3b8, a2=?, a3=?.
  The `beq` branch at 0x3f78 targets 0x3f90, is taken when v0(=ret(hwgraph_traverse)) == t8(=0x2), and falls through when v0(=ret(hwgraph_traverse)) != t8(=0x2).
  The `bne` branch at 0x3f88 targets 0x3fa8, is taken when v0(=ret(device_info_get)) != 0, and falls through when v0(=ret(device_info_get)) == 0.
  The `beq` branch at 0x3fa0 targets 0x4074 and is always taken.
  The return at 0x4084 has v0 = one of 0x0, 0x5.

- `ecf_txfree_len` in `IP32/usr/cpu/sysgen/IP32boot/if_ecf.o` at 0x408c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/if_ecf.o`.
  Range: 0x408c-0x4094 (8 bytes).
  It occupies 8 bytes.
  The `lw` at 0x4090 loads 4 bytes from a0 (arg0 at entry) +0x2e0.
  The return at 0x408c has v0 = [a0+736].

- `ecf_setstate` in `IP32/usr/cpu/sysgen/IP32boot/if_ecf.o` at 0x4094 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/if_ecf.o`.
  Range: 0x4094-0x40bc (40 bytes).
  It occupies 40 bytes.
  The `lw` at 0x4098 loads 4 bytes from a0 (arg0 at entry) +0x36c.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x36c, including `sw` at 0x40a0, `sw` at 0x40b8.
  The `beq` branch at 0x4094 targets 0x40ac, is taken when a1 == 0, and falls through when a1 != 0.
  The return at 0x40a4 has v0 = ?.
  The return at 0x40b4 has v0 = ?.
