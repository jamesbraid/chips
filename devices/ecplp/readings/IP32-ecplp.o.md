# Readings: `IP32/usr/cpu/sysgen/IP32boot/ecplp.o`

One entry per routine, filed here from the reading batches by binary.

- `plpinit` in `IP32/usr/cpu/sysgen/IP32boot/ecplp.o` at 0x0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/ecplp.o`.
  Range: 0x0-0x8 (8 bytes).
  It occupies 8 bytes.
  The return at 0x0 has v0 = ?.

- `plpstart` in `IP32/usr/cpu/sysgen/IP32boot/ecplp.o` at 0x8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/ecplp.o`.
  Range: 0x8-0x304 (764 bytes).
  It occupies 764 bytes.
  The `ll` at 0x14 loads 4 bytes from sym(plpmversion) +0x8.
  The `sc` at 0x20 stores 4 bytes to sym(plpmversion) +0x8.
  The `lw` at 0x5c loads 4 bytes from sym(hwgraph_root) +0x0.
  The `sw` at 0xf4 stores 4 bytes to ?.
  The `lw` at 0x104 loads 4 bytes from ret(plp_setup) +0x14.
  The `sw` at 0x138 stores 4 bytes to ret(plp_setup) +0x30.
  The `sw` at 0x14c stores 4 bytes to ret(plp_setup) +0x34.
  The `sw` at 0x258 stores 4 bytes to ret(plp_setup) +0x158.
  The `lw` at 0x260 loads 4 bytes from sym(plprtmout) +0x0.
  The `sb` at 0x270 stores 1 byte to ret(plp_setup) +0x0.
  The `sb` at 0x274 stores 1 byte to ret(plp_setup) +0x2.
  The `sw` at 0x278 stores 4 bytes to ret(plp_setup) +0x168.
  The `sw` at 0x280 stores 4 bytes to ret(plp_setup) +0x160.
  The `sb` at 0x28c stores 1 byte to ret(plp_setup) +0x3.
  The `sw` at 0x298 stores 4 bytes to ret(plp_setup) +0x15c.
  The `sd` at 0x2b0 stores 8 bytes to ret(plp_setup) +0x28.
  The `jalr` at 0x60 calls hwgraph_traverse with a0=[sym(hwgraph_root)], a1=sym(.rodata), a2=sp-48, a3=a3 at entry (arg3).
  The `jalr` at 0x88 calls plp_setup with a0=?, a1=?, a2=?, a3=?.
  The `jalr` at 0xa8 calls kvpalloc with a0=0x2, a1=0x111, a2=0x0, a3=sym(kvpalloc).
  The `jalr` at 0xd8 calls dki_dcache_wbinval with a0=?, a1=0x1000, a2=0xffffffff80000000, a3=sym(dki_dcache_wbinval).
  The `jalr` at 0x11c calls kvpalloc with a0=0xa, a1=0x111, a2=0x0, a3=?, a5=[ret(plp_setup)+20], a6=sym(kvpalloc).
  The `jalr` at 0x170 calls init_mutex with a0=ret(plp_setup)+272, a1=0x0, a2=sym(.rodata), a3=-0x1.
  The `jalr` at 0x18c calls init_mutex with a0=ret(plp_setup)+280, a1=0x0, a2=sym(.rodata), a3=-0x1.
  The `jalr` at 0x1a8 calls init_mutex with a0=ret(plp_setup)+288, a1=0x0, a2=sym(.rodata), a3=-0x1.
  The `jalr` at 0x1c4 calls init_mutex with a0=ret(plp_setup)+296, a1=0x0, a2=sym(.rodata), a3=-0x1.
  The `jalr` at 0x1e0 calls init_sema with a0=ret(plp_setup)+304, a1=0x1, a2=sym(.rodata), a3=-0x1.
  The `jalr` at 0x1fc calls init_sema with a0=ret(plp_setup)+312, a1=0x1, a2=sym(.rodata), a3=-0x1.
  The `jalr` at 0x218 calls init_sema with a0=ret(plp_setup)+320, a1=0x1, a2=sym(.rodata), a3=-0x1.
  The `jalr` at 0x234 calls init_sv with a0=ret(plp_setup)+328, a1=0x0, a2=sym(.rodata), a3=-0x1.
  The `jalr` at 0x250 calls init_sv with a0=ret(plp_setup)+332, a1=0x0, a2=sym(.rodata), a3=-0x1.
  The `jalr` at 0x294 calls plp_reset with a0=ret(plp_setup), a1=0x1, a2=?, a3=?.
  The `jalr` at 0x2b4 calls setmaceisavector with a0=0x4, a1=0xf0000, a2=sym(plpintr), a3=sym(setmaceisavector).
  The `jalr` at 0x2d8 calls cmn_err with a0=0x4, a1=sym(.rodata), a2=?, a3=?, a4=sym(cmn_err).
  The `jalr` at 0x2f4 calls cmn_err with a0=0x4, a1=sym(.rodata), a2=?, a3=?, a5=sym(cmn_err).
  The `beql` branch at 0x24 targets 0x14, is taken when a0(=[sym(.data)+8]+1) == 0, and falls through when a0(=[sym(.data)+8]+1) != 0; its branch-likely delay slot `nop` at 0x28 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x3c targets 0x70, is taken when at(=[sym(.data)+8]+1) >= 0x2 (signed), and falls through when at(=[sym(.data)+8]+1) < 0x2 (signed).
  The `beq` branch at 0x68 targets 0x84, is taken when v0(=ret(hwgraph_traverse)) == 0, and falls through when v0(=ret(hwgraph_traverse)) != 0.
  The `beq` branch at 0x90 targets 0x70, is taken when v0(=ret(plp_setup)) == 0, and falls through when v0(=ret(plp_setup)) != 0.
  The `beq` branch at 0xb0 targets 0x2cc, is taken when v0(=ret(kvpalloc)) == 0, and falls through when v0(=ret(kvpalloc)) != 0.
  The `bne` branch at 0xfc targets 0xec, is taken when a1(?) < 0x2 (signed), and falls through when a1(?) >= 0x2 (signed).
  The `beq` branch at 0x108 targets 0x15c, is taken when a5(=[ret(plp_setup)+20]) == 0, and falls through when a5(=[ret(plp_setup)+20]) != 0.
  The `beq` branch at 0x124 targets 0x2e8, is taken when v0(=ret(kvpalloc)) == 0, and falls through when v0(=ret(kvpalloc)) != 0.
  The `beq` branch at 0x140 targets 0x15c and is never taken: its condition can never hold for these operands, so execution always falls through.
  The `bne` branch at 0x154 targets 0x130 and is never taken: its condition can never hold for these operands, so execution always falls through.
  The `beq` branch at 0x264 targets 0x2c4, is taken when v0(=[sym(plprtmout)]) == 0, and falls through when v0(=[sym(plprtmout)]) != 0.
  The `beq` branch at 0x2bc targets 0x74 and is always taken.
  The `beq` branch at 0x2c4 targets 0x26c and is always taken.
  The `beq` branch at 0x2e0 targets 0x74 and is always taken.
  The `beq` branch at 0x2fc targets 0x74 and is always taken.
  The return at 0x7c has v0 = one of ?, ret(setmaceisavector), ret(cmn_err).

- `plpopen` in `IP32/usr/cpu/sysgen/IP32boot/ecplp.o` at 0x304 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/ecplp.o`.
  Range: 0x304-0x754 (1104 bytes).
  It occupies 1104 bytes.
  The `lw` at 0x30c loads 4 bytes from sym(plpinfo) +0x0.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x0, including `lw` at 0x324, `lw` at 0x390, `lw` at 0x39c.
  The `lw` at 0x354 loads 4 bytes from ret(device_info_get) +0x0.
  9 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x380, `lbu` at 0x3ac, `lbu` at 0x3c8.
  The `sw` at 0x394 stores 4 bytes to ?.
  The `lbu` at 0x3a0 loads 1 byte from ret(device_info_get) +0x8.
  13 such `sb` accesses store 1 byte to ?, including `sb` at 0x420, `sb` at 0x444, `sb` at 0x4ec.
  The `lw` at 0x45c loads 4 bytes from sym(plpopmode) +0x0.
  The `jalr` at 0x348 calls device_info_get with a0=[a0], a1=sym(device_info_get), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x398 calls device_info_get with a0=[a0], a1=sym(device_info_get), a2=?, a3=[a0].
  The `jalr` at 0x3fc calls pciio_pio_read8 with a0=0xffffffffbf388200, a1=?, a2=?, a3=?, a7=sym(pciio_pio_read8).
  The `jalr` at 0x418 calls pciio_pio_write8 with a0=?, a1=0xffffffffbf388200, a2=sym(pciio_pio_write8), a3=?.
  The `jalr` at 0x42c calls mutex_unlock with a0=?, a1=?, a2=?, a3=sym(mutex_unlock).
  The `jalr` at 0x474 calls mutex_lock with a0=?, a1=0x19, a2=?, a3=?, a4=[ret(device_info_get)+8]:1, a5=0x60.
  The `jalr` at 0x4bc calls pciio_pio_read8 with a0=0xffffffffbf388200, a1=?, a2=?, a3=?, a4=sym(plp_negotiate), a7=sym(pciio_pio_read8).
  The `jalr` at 0x4dc calls pciio_pio_write8 with a0=?, a1=0xffffffffbf388200, a2=sym(pciio_pio_write8), a3=?.
  The `jalr` at 0x538 calls plp_negotiate with a0=?, a1=0x10, a2=?, a3=?, a7=sym(pciio_pio_read8).
  The `jalr` at 0x554 calls pciio_pio_read8 with a0=0xffffffffbf388200, a1=?, a2=?, a3=?.
  The `jalr` at 0x574 calls pciio_pio_write8 with a0=?, a1=0xffffffffbf388200, a2=sym(pciio_pio_write8), a3=?.
  The `jalr` at 0x5a4 calls pciio_pio_read8 with a0=0xffffffffbf388200, a1=?, a2=?, a3=?, a5=sym(pciio_pio_read8).
  The `jalr` at 0x5c4 calls pciio_pio_write8 with a0=?, a1=0xffffffffbf388200, a2=sym(pciio_pio_write8), a3=?.
  The `jalr` at 0x5e8 calls pciio_pio_read8 with a0=0xffffffffbf388200, a1=?, a2=?, a3=?, a4=sym(pciio_pio_read8), a7=0x20.
  The `jalr` at 0x608 calls pciio_pio_write8 with a0=?, a1=0xffffffffbf388200, a2=sym(pciio_pio_write8), a3=?.
  The `jalr` at 0x624 calls plp_negotiate with a0=?, a1=0x40, a2=?, a3=?, a4=sym(plp_negotiate).
  The `jalr` at 0x644 calls pciio_pio_read8 with a0=0xffffffffbf388200, a1=?, a2=sym(mutex_unlock), a3=?, a5=sym(pciio_pio_read8).
  The `jalr` at 0x664 calls pciio_pio_write8 with a0=?, a1=0xffffffffbf388200, a2=sym(pciio_pio_write8), a3=?.
  The `jalr` at 0x690 calls plp_negotiate with a0=?, a1=0x10, a2=?, a3=?, a5=sym(plp_negotiate), a7=sym(pciio_pio_read8).
  The `jalr` at 0x6ac calls pciio_pio_read8 with a0=0xffffffffbf388200, a1=?, a2=?, a3=?.
  The `jalr` at 0x6cc calls pciio_pio_write8 with a0=?, a1=0xffffffffbf388200, a2=sym(pciio_pio_write8), a3=?.
  The `jalr` at 0x6f4 calls mutex_unlock with a0=?, a1=?, a2=?, a3=sym(mutex_unlock).
  The `jalr` at 0x70c calls pciio_pio_read8 with a0=0xffffffffbf388200, a1=?, a2=?, a3=?, a4=sym(pciio_pio_read8).
  The `jalr` at 0x72c calls pciio_pio_write8 with a0=?, a1=0xffffffffbf388200, a2=sym(pciio_pio_write8), a3=?.
  The `jalr` at 0x744 calls mutex_unlock with a0=?, a1=?, a2=sym(mutex_unlock), a3=?.
  The `beq` branch at 0x31c targets 0x3e0, is taken when v0(=[sym(plpinfo)]) == 0, and falls through when v0(=[sym(plpinfo)]) != 0.
  The `bne` branch at 0x330 targets 0x360, is taken when (v1(?) & 0x1ff) != 0, and falls through when (v1(?) & 0x1ff) == 0.
  The `beq` branch at 0x338 targets 0x378, is taken when a0(=[a0]) == 0, and falls through when a0(=[a0]) != 0.
  The `beq` branch at 0x358 targets 0x380 and is always taken.
  The `beq` branch at 0x388 targets 0x364, is taken when (a2(?) & 0x1) == 0, and falls through when (a2(?) & 0x1) != 0.
  The `beq` branch at 0x3a4 targets 0x458, is taken when a4(=[ret(device_info_get)+8]:1) == 0, and falls through when a4(=[ret(device_info_get)+8]:1) != 0.
  The `beq` branch at 0x3b0 targets 0x434, is taken when s1(?) == v0(?), and falls through when s1(?) != v0(?).
  The `beq` branch at 0x3b8 targets 0x448, is taken when a0(=0x40) == v0(?), and falls through when a0(=0x40) != v0(?).
  The `beq` branch at 0x3c0 targets 0x448, is taken when v0(?) == a5(=0x60), and falls through when v0(?) != a5(=0x60).
  The `beq` branch at 0x3d0 targets 0x468, is taken when (a6(?) & 0x20) == 0, and falls through when (a6(?) & 0x20) != 0.
  The `beq` branch at 0x3d8 targets 0x364 and is always taken.
  The `beq` branch at 0x3e0 targets 0x364 and is always taken.
  The `beq` branch at 0x3e8 targets 0x684, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `beq` branch at 0x440 targets 0x364 and is always taken.
  The `bne` branch at 0x448 targets 0x3c8, is taken when s1(?) != 0, and falls through when s1(?) == 0.
  The `beq` branch at 0x450 targets 0x438 and is always taken.
  The `beq` branch at 0x460 targets 0x3ac and is always taken.
  The `bne` branch at 0x480 targets 0x4fc, is taken when s1(?) < 0x40 (signed), and falls through when s1(?) >= 0x40 (signed).
  The `bne` branch at 0x488 targets 0x594, is taken when ra(?) != 0, and falls through when ra(?) == 0.
  The `bne` branch at 0x490 targets 0x520, is taken when at(?) != 0, and falls through when at(?) == 0.
  The `bne` branch at 0x498 targets 0x61c, is taken when v0(?) != 0, and falls through when v0(?) == 0.
  The `bne` branch at 0x4a4 targets 0x3f0, is taken when s1(?) != v1(=0xc0), and falls through when s1(?) == v1(=0xc0).
  The `beq` branch at 0x4f4 targets 0x424 and is always taken.
  The `bne` branch at 0x500 targets 0x3e8, is taken when s1(?) < 0x10 (signed), and falls through when s1(?) >= 0x10 (signed).
  The `bne` branch at 0x508 targets 0x5d8, is taken when a6(?) != 0, and falls through when a6(?) == 0.
  The `bne` branch at 0x510 targets 0x3f0, is taken when s1(?) != a7(=0x20), and falls through when s1(?) == a7(=0x20).
  The `beq` branch at 0x518 targets 0x530 and is always taken.
  The `bne` branch at 0x524 targets 0x3f0, is taken when s1(?) != t0(=0x60), and falls through when s1(?) == t0(=0x60).
  The `beq` branch at 0x540 targets 0x6ec, is taken when v0(=ret(plp_negotiate)) == 0, and falls through when v0(=ret(plp_negotiate)) != 0.
  The `beq` branch at 0x58c targets 0x424 and is always taken.
  The `beq` branch at 0x5d0 targets 0x424 and is always taken.
  The `beq` branch at 0x614 targets 0x424 and is always taken.
  The `beq` branch at 0x62c targets 0x740, is taken when v0(=ret(plp_negotiate)) == 0, and falls through when v0(=ret(plp_negotiate)) != 0.
  The `beq` branch at 0x67c targets 0x424 and is always taken.
  The `beq` branch at 0x69c targets 0x704, is taken when v0(=ret(plp_negotiate)) == 0, and falls through when v0(=ret(plp_negotiate)) != 0.
  The `beq` branch at 0x6e4 targets 0x424 and is always taken.
  The `beq` branch at 0x6fc targets 0x364 and is always taken.
  The `beq` branch at 0x738 targets 0x424 and is always taken.
  The `beq` branch at 0x74c targets 0x364 and is always taken.
  The return at 0x370 has v0 = one of 0x0, 0x5, 0x6, 0x10.

- `plpclose` in `IP32/usr/cpu/sysgen/IP32boot/ecplp.o` at 0x754 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/ecplp.o`.
  Range: 0x754-0x8d8 (388 bytes).
  It occupies 388 bytes.
  The `lw` at 0x77c loads 4 bytes from ret(device_info_get) +0x0.
  The `lw` at 0x780 loads 4 bytes from sym(plpinfo) +0x0.
  2 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x7d0, `lbu` at 0x8ac.
  2 such `sb` accesses store 1 byte to ?, including `sb` at 0x7e8, `sb` at 0x8c4.
  The `lw` at 0x880 loads 4 bytes from sym(plprtmout) +0x0.
  2 such `sw` accesses store 4 bytes to ?, including `sw` at 0x898, `sw` at 0x8a4.
  The `jalr` at 0x770 calls device_info_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x790 calls plp_prlock with a0=?, a1=0x0, a2=?, a3=?.
  The `jalr` at 0x7c0 calls mutex_lock with a0=?, a1=0x19, a2=?, a3=?.
  The `jalr` at 0x7e4 calls pciio_pio_read64 with a0=0xffffffffbf314010, a1=sym(pciio_pio_read64), a2=?, a3=-0x2f.
  The `jalr` at 0x800 calls pciio_pio_write64 with a0=?, a1=0xffffffffbf314010, a2=sym(pciio_pio_write64), a3=?.
  The `jalr` at 0x814 calls pciio_pio_read8 with a0=0xffffffffbf388200, a1=?, a2=?, a3=sym(pciio_pio_read8).
  The `jalr` at 0x834 calls pciio_pio_write8 with a0=?, a1=0xffffffffbf388200, a2=sym(pciio_pio_write8), a3=?.
  The `jalr` at 0x848 calls pciio_pio_read64 with a0=0xffffffffbf314010, a1=?, a2=?, a3=sym(pciio_pio_read64).
  The `jalr` at 0x864 calls plp_rbflush with a0=?, a1=?, a2=sym(plp_rbflush), a3=sym(plp_unlock).
  The `jalr` at 0x874 calls plp_unlock with a0=?, a1=?, a2=?, a3=sym(plp_unlock).
  The `jalr` at 0x8a0 calls plp_prunlock with a0=?, a1=0x0, a2=?, a3=?.
  The `jalr` at 0x8c0 calls mutex_unlock with a0=?, a1=?, a2=sym(mutex_unlock), a3=-0x41.
  The `beq` branch at 0x760 targets 0x780, is taken when a0 == 0, and falls through when a0 != 0.
  The `beq` branch at 0x778 targets 0x784 and is always taken.
  The `beq` branch at 0x798 targets 0x7b4, is taken when v0(=ret(plp_prlock)) == 0, and falls through when v0(=ret(plp_prlock)) != 0.
  The `beq` branch at 0x854 targets 0x870, is taken when (v0(=ret(pciio_pio_read64)) & 0x1) == 0, and falls through when (v0(=ret(pciio_pio_read64)) & 0x1) != 0.
  The `beq` branch at 0x884 targets 0x8d0, is taken when v0(=[sym(plprtmout)]) == 0, and falls through when v0(=[sym(plprtmout)]) != 0.
  The `beq` branch at 0x8c8 targets 0x7a4 and is always taken.
  The `beq` branch at 0x8d0 targets 0x88c and is always taken.
  The return at 0x7ac has v0 = one of 0x0, 0x10.

- `plpread` in `IP32/usr/cpu/sysgen/IP32boot/ecplp.o` at 0x8d8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/ecplp.o`.
  Range: 0x8d8-0x9bc (228 bytes).
  It occupies 228 bytes.
  The `lw` at 0x910 loads 4 bytes from ret(device_info_get) +0x0.
  The `lw` at 0x914 loads 4 bytes from sym(plpinfo) +0x0.
  The `lw` at 0x918 loads 4 bytes from a1 (arg1 at entry) +0x20.
  The `lbu` at 0x924 loads 1 byte from ?.
  The `jalr` at 0x904 calls device_info_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x940 calls plp_prlock with a0=?, a1=0x0, a2=sym(plp_prlock), a3=?.
  The `jalr` at 0x994 calls uiophysio with a0=sym(plp_io), a1=0x0, a2=a0 at entry (arg0), a3=0x1, a4=a1 at entry (arg1), a5=sym(uiophysio).
  The `jalr` at 0x9ac calls plp_prunlock with a0=?, a1=0x0, a2=?, a3=?, a6=sym(plp_prunlock).
  The `beq` branch at 0x8f4 targets 0x914, is taken when a0 == 0, and falls through when a0 != 0.
  The `beq` branch at 0x90c targets 0x918 and is always taken.
  The `beq` branch at 0x91c targets 0x970, is taken when v0(=[a1+32]) == 0, and falls through when v0(=[a1+32]) != 0.
  The `beq` branch at 0x92c targets 0x968, is taken when (v1(?) & 0x4) == 0, and falls through when (v1(?) & 0x4) != 0.
  The `beq` branch at 0x948 targets 0x978, is taken when v0(=ret(plp_prlock)) == 0, and falls through when v0(=ret(plp_prlock)) != 0.
  The `beq` branch at 0x968 targets 0x954 and is always taken.
  The `beq` branch at 0x970 targets 0x950 and is always taken.
  The `beq` branch at 0x9b4 targets 0x950 and is always taken.
  The return at 0x960 has v0 = one of ?, 0x5.

- `plpwrite` in `IP32/usr/cpu/sysgen/IP32boot/ecplp.o` at 0x9bc (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/ecplp.o`.
  Range: 0x9bc-0xa84 (200 bytes).
  It occupies 200 bytes.
  The `lw` at 0x9f4 loads 4 bytes from ret(device_info_get) +0x0.
  The `lw` at 0x9f8 loads 4 bytes from sym(plpinfo) +0x0.
  The `lw` at 0x9fc loads 4 bytes from a1 (arg1 at entry) +0x20.
  The `jalr` at 0x9e8 calls device_info_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0xa10 calls plp_prlock with a0=?, a1=0x0, a2=?, a3=?.
  The `jalr` at 0xa5c calls uiophysio with a0=sym(plp_io), a1=0x0, a2=a0 at entry (arg0), a3=0x0, a4=a1 at entry (arg1), a5=sym(uiophysio).
  The `jalr` at 0xa74 calls plp_prunlock with a0=?, a1=0x0, a2=?, a3=?, a6=sym(plp_prunlock).
  The `beq` branch at 0x9d8 targets 0x9f8, is taken when a0 == 0, and falls through when a0 != 0.
  The `beq` branch at 0x9f0 targets 0x9fc and is always taken.
  The `beq` branch at 0xa00 targets 0xa38, is taken when v0(=[a1+32]) == 0, and falls through when v0(=[a1+32]) != 0.
  The `beq` branch at 0xa18 targets 0xa40, is taken when v0(=ret(plp_prlock)) == 0, and falls through when v0(=ret(plp_prlock)) != 0.
  The `beq` branch at 0xa38 targets 0xa20 and is always taken.
  The `beq` branch at 0xa7c targets 0xa20 and is always taken.
  The return at 0xa30 has v0 = one of 0x10, 0x0, ret(uiophysio).

- `plpioctl` in `IP32/usr/cpu/sysgen/IP32boot/ecplp.o` at 0xa84 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/ecplp.o`.
  Range: 0xa84-0xf80 (1276 bytes).
  It occupies 1276 bytes.
  The `lw` at 0xac0 loads 4 bytes from ret(device_info_get) +0x0.
  The `lw` at 0xac8 loads 4 bytes from sym(plpinfo) +0x0.
  The `lw` at 0xb40 loads 4 bytes from (sym(.rodata)+176 + (a1-28673 << 0x2)) +0x0.
  The `jalr` at 0xab4 calls device_info_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0xad8 calls plp_prlock with a0=?, a1=0x0, a2=?, a3=?.
  The `jalr` at 0xb00 calls plp_prunlock with a0=?, a1=0x0, a2=?, a3=?.
  Calls (unknown callee) via register with a0=?, a1=?, a2=?, a3=?, a7=(a2 << 0x2) (`jr` at 0xb44).
  The `beq` branch at 0xaa4 targets 0xac4, is taken when a0 == 0, and falls through when a0 != 0.
  The `beq` branch at 0xabc targets 0xacc and is always taken.
  The `beq` branch at 0xae0 targets 0xb28, is taken when v0(=ret(plp_prlock)) == 0, and falls through when v0(=ret(plp_prlock)) != 0.
  The `beq` branch at 0xae8 targets 0xb08 and is always taken.
  The `beq` branch at 0xb38 targets 0xaf0, is taken when v1(=a1-28673) >= 0x12 (unsigned), and falls through when v1(=a1-28673) < 0x12 (unsigned).
  The return at 0xb20 has v0 = one of 0x10, 0x16.
  The instructions from 0xb4c to 0xf7c are not reached by any path from the entry, and their branches are not listed.
  The indirect jump at 0xb44 uses a jump table whose successors are unresolved.

- `plpintr` in `IP32/usr/cpu/sysgen/IP32boot/ecplp.o` at 0xf80 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/ecplp.o`.
  Range: 0xf80-0x11a0 (544 bytes).
  It occupies 544 bytes.
  The `lw` at 0xfa8 loads 4 bytes from sym(plpinfo) +0x0.
  5 such `lbu` accesses load 1 byte from [sym(plpinfo)] +0x1f, including `lbu` at 0xfe4, `lbu` at 0x1010, `lbu` at 0x1024.
  3 such `lw` accesses load 4 bytes from ?, including `lw` at 0x1000, `lw` at 0x1004, `lw` at 0x100c.
  2 such `lbu` accesses load 1 byte from [sym(plpinfo)] +0x1d, including `lbu` at 0x1014, `lbu` at 0x106c.
  2 such `sb` accesses store 1 byte to [sym(plpinfo)] +0x1d, including `sb` at 0x1020, `sb` at 0x1080.
  2 such `sb` accesses store 1 byte to [sym(plpinfo)] +0x1f, including `sb` at 0x1030, `sb` at 0x1074.
  The `lbu` at 0x104c loads 1 byte from [sym(plpinfo)] +0x20.
  2 such `ld` accesses load 8 bytes from [sym(plpinfo)] +0x28, including `ld` at 0x1054, `ld` at 0x1108.
  The `sd` at 0x1064 stores 8 bytes to [sym(plpinfo)] +0x28.
  2 such `lw` accesses load 4 bytes from [sym(plpinfo)] +0x50, including `lw` at 0x1168, `lw` at 0x1178.
  The `jalr` at 0xfc4 calls mutex_lock with a0=[sym(plpinfo)]+288, a1=0x19, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x1008 calls bcopy with a0=?, a1=?, a2=?, a3=?.
  The `jalr` at 0x108c calls sv_signal with a0=[sym(plpinfo)]+328, a1=?, a2=?, a3=?, a5=sym(sv_signal).
  The `jalr` at 0x10a8 calls mutex_unlock with a0=[sym(plpinfo)]+288, a1=?, a2=?, a3=?, a6=sym(mutex_unlock).
  The `jalr` at 0x10d4 calls pciio_pio_read64 with a0=0xffffffffbf310010, a1=?, a2=?, a3=sym(mace_mask_update).
  The `jalr` at 0x10f0 calls pciio_pio_write64 with a0=?, a1=0xffffffffbf310010, a2=sym(pciio_pio_write64), a3=?.
  The `jalr` at 0x110c calls mace_mask_update with a0=0xf0000, a1=[[sym(plpinfo)]+40]:8, a2=?, a3=sym(mace_mask_update).
  The `jalr` at 0x1138 calls cmn_err with a0=0x4, a1=sym(.rodata), a2=?, a3=?, a4=sym(cmn_err).
  The `jalr` at 0x1150 calls plp_reset_dmacntxts with a0=[sym(plpinfo)], a1=?, a2=sym(plp_reset_dmacntxts), a3=?, a7=(a1 << 0x2c).
  The `jalr` at 0x1164 calls bioerror with a0=[[sym(plpinfo)]+80], a1=0x5, a2=?, a3=sym(bioerror).
  The `jalr` at 0x1174 calls biodone with a0=[[sym(plpinfo)]+80], a1=?, a2=?, a3=?, a4=sym(biodone).
  The `jalr` at 0x1190 calls cmn_err with a0=0x4, a1=sym(.rodata), a2=?, a3=?, a5=sym(cmn_err).
  The `beq` branch at 0xfa4 targets 0x10b0, is taken when (s1(?) & 0x3) == 0, and falls through when (s1(?) & 0x3) != 0.
  The `beq` branch at 0xfdc targets 0x1084, is taken when (s1(?) & 0xff) == 0, and falls through when (s1(?) & 0xff) != 0.
  The `beq` branch at 0xfe8 targets 0x1034 and is always taken.
  The `beq` branch at 0x102c targets 0x1084, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `beq` branch at 0x1044 targets 0x1124, is taken when (a5(?) & s1(?)) == 0, and falls through when (a5(?) & s1(?)) != 0.
  The `bne` branch at 0x1060 targets 0xff0, is taken when t0(=[[sym(plpinfo)]+32]:1) != 0, and falls through when t0(=[[sym(plpinfo)]+32]:1) == 0.
  The `bne` branch at 0x107c targets 0x1034, is taken when s1(?) != 0, and falls through when s1(?) == 0.
  The `bltz` branch at 0x10b4 targets 0x1148, is taken when a7(=(a1 << 0x2c)) < 0 (signed), and falls through when a7(=(a1 << 0x2c)) >= 0 (signed).
  The `bgez` branch at 0x10bc targets 0x10fc, is taken when t0(=(a1 << 0x2f)) >= 0 (signed), and falls through when t0(=(a1 << 0x2f)) < 0 (signed).
  The `beq` branch at 0x1140 targets 0x1028 and is always taken.
  The `beq` branch at 0x1198 targets 0x10bc and is always taken.
  The return at 0x111c has v0 = ret(mace_mask_update).

- `plp_tmout` in `IP32/usr/cpu/sysgen/IP32boot/ecplp.o` at 0x11a0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/ecplp.o`.
  Range: 0x11a0-0x1328 (392 bytes).
  It occupies 392 bytes.
  The `lw` at 0x11a4 loads 4 bytes from a0 (arg0 at entry) +0x168.
  The `sw` at 0x11d0 stores 4 bytes to a0 (arg0 at entry) +0x168.
  The `lbu` at 0x1240 loads 1 byte from a0 (arg0 at entry) +0x1d.
  The `sw` at 0x1244 stores 4 bytes to a0 (arg0 at entry) +0x178.
  The `sd` at 0x1260 stores 8 bytes to a0 (arg0 at entry) +0x170.
  The `lw` at 0x1274 loads 4 bytes from a0 (arg0 at entry) +0x50.
  The `sw` at 0x127c stores 4 bytes to [a0+80] +0x30.
  The `lbu` at 0x1280 loads 1 byte from a0 (arg0 at entry) +0x20.
  The `lbu` at 0x128c loads 1 byte from a0 (arg0 at entry) +0x1f.
  3 such `lw` accesses load 4 bytes from ?, including `lw` at 0x12b8, `lw` at 0x12c0, `lw` at 0x12cc.
  The `sb` at 0x12e4 stores 1 byte to a0 (arg0 at entry) +0x1c.
  The `jalr` at 0x11cc calls mutex_trylock with a0=a0+288, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x11e4 calls pciio_pio_read64 with a0=0xffffffffbf314010, a1=?, a2=?, a3=?.
  The `jalr` at 0x1200 calls pciio_pio_write64 with a0=?, a1=0xffffffffbf314010, a2=sym(pciio_pio_write64), a3=?.
  The `jalr` at 0x1214 calls pciio_pio_read8 with a0=0xffffffffbf388200, a1=?, a2=?, a3=sym(pciio_pio_read8).
  The `jalr` at 0x1234 calls pciio_pio_write8 with a0=?, a1=0xffffffffbf388200, a2=sym(pciio_pio_write8), a3=?.
  The `jalr` at 0x1248 calls pciio_pio_read64 with a0=0xffffffffbf314018, a1=[a0+29]:1, a2=?, a3=?.
  The `jalr` at 0x125c calls plp_reset_dmacntxts with a0=a0 at entry (arg0), a1=?, a2=sym(plp_reset_dmacntxts), a3=?.
  The `jalr` at 0x126c calls plp_unlock with a0=a0+320, a1=?, a2=?, a3=sym(plp_unlock).
  The `jalr` at 0x12ac calls pciio_pio_read64 with a0=0xffffffffbf314018, a1=?, a2=[a0+31]:1, a3=?, a4=[a0+32]:1, a5=sym(sv_signal), a6=[a0+80].
  The `jalr` at 0x12d8 calls bcopy with a0=?, a1=?, a2=?, a3=sym(bcopy).
  The `jalr` at 0x12f4 calls sv_signal with a0=a0+328, a1=?, a2=?, a3=?, a5=sym(sv_signal).
  The `jalr` at 0x130c calls mutex_unlock with a0=a0+288, a1=?, a2=?, a3=?, a6=sym(mutex_unlock).
  The `beq` branch at 0x11b4 targets 0x1314, is taken when at(=[a0+360]) == 0, and falls through when at(=[a0+360]) != 0.
  The `beq` branch at 0x1284 targets 0x12ec, is taken when a4(=[a0+32]:1) == 0, and falls through when a4(=[a0+32]:1) != 0.
  The `beq` branch at 0x12fc targets 0x1318, is taken when s1(=ret(mutex_trylock)) == 0, and falls through when s1(=ret(mutex_trylock)) != 0.
  The return at 0x1320 has v0 = one of ret(sv_signal), ?.

- `plp_setup` in `IP32/usr/cpu/sysgen/IP32boot/ecplp.o` at 0x1328 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/ecplp.o`.
  Range: 0x1328-0x15ac (644 bytes).
  It occupies 644 bytes.
  2 such `sw` accesses store 4 bytes to sym(plpinfo) +0x0, including `sw` at 0x13bc, `sw` at 0x1538.
  The `sw` at 0x13c0 stores 4 bytes to ret(kmem_zalloc) +0xc.
  The `sw` at 0x13d0 stores 4 bytes to ret(kmem_zalloc) +0x10.
  The `lw` at 0x13fc loads 4 bytes from ?.
  The `lw` at 0x1450 loads 4 bytes from sym(plpinfo) +0x0.
  The `lw` at 0x1454 loads 4 bytes from sym(hwgraph_root) +0x0.
  The `lw` at 0x1460 loads 4 bytes from [sym(plpinfo)] +0x10.
  The `sb` at 0x14d4 stores 1 byte to ?.
  The `lbu` at 0x154c loads 1 byte from ?.
  The `sw` at 0x1554 stores 4 bytes to ret(kmem_zalloc) +0x0.
  The `sb` at 0x1560 stores 1 byte to ret(kmem_zalloc) +0x8.
  The `sw` at 0x1568 stores 4 bytes to ret(kmem_zalloc) +0x4.
  The `sw` at 0x15a8 stores 4 bytes to ?.
  The `jalr` at 0x1350 calls hwgraph_traverse with a0=a0 at entry (arg0), a1=sym(.rodata), a2=sp-80, a3=a3 at entry (arg3).
  The `jalr` at 0x1370 calls hwgraph_path_add with a0=a0 at entry (arg0), a1=sym(.rodata), a2=sp-80, a3=?, a6=sym(device_info_get).
  The `jalr` at 0x13a4 calls kmem_zalloc with a0=0x188, a1=0x0, a2=?, a3=?.
  The `jalr` at 0x13d8 calls device_info_set with a0=?, a1=ret(kmem_zalloc), a2=sym(device_info_set), a3=?, a4=sym(plpinfo).
  The `jalr` at 0x1418 calls hwgraph_char_device_add with a0=?, a1=?, a2=sym(.rodata), a3=sp-64, a5=sym(hwgraph_char_device_add), a6=0x80, a7=sym(.rodata).
  The `jalr` at 0x145c calls hwgraph_edge_add with a0=[sym(hwgraph_root)], a1=[[sym(plpinfo)]+16], a2=sym(.rodata), a3=sym(hwgraph_edge_add).
  The `jalr` at 0x148c calls device_inventory_add with a0=?, a1=0x5, a2=0x6, a3=0x0, a4=0x0, a5=0x1, a6=sym(device_inventory_add).
  The `jalr` at 0x14a0 calls pciio_pio_read8 with a0=0xffffffffbf388200, a1=?, a2=?, a3=?, a7=sym(pciio_pio_read8).
  The `jalr` at 0x14c0 calls pciio_pio_write8 with a0=?, a1=0xffffffffbf388200, a2=sym(pciio_pio_write8), a3=?.
  The `jalr` at 0x14d8 calls plpfdc_cpp with a0=0x0, a1=0x0, a2=?, a3=sym(plpfdc_cpp).
  The `jalr` at 0x14ec calls plpfdc_cpp with a0=0x20, a1=0x0, a2=?, a3=?, a4=sym(plpfdc_cpp).
  The `jalr` at 0x1508 calls hwgraph_path_add with a0=?, a1=sym(.rodata), a2=sp-64, a3=?, a5=sym(hwgraph_path_add).
  The `jalr` at 0x1524 calls device_info_get with a0=?, a1=?, a2=?, a3=?, a6=sym(device_info_get).
  The `jalr` at 0x1544 calls kmem_zalloc with a0=0xc, a1=0x0, a2=?, a3=?.
  The `jalr` at 0x1570 calls device_info_set with a0=?, a1=ret(kmem_zalloc), a2=?, a3=?.
  The `jalr` at 0x1598 calls device_inventory_add with a0=?, a1=0x5, a2=0x7, a3=0x0, a4=0x0, a5=0x0.
  The `beq` branch at 0x1358 targets 0x1520, is taken when v0(=ret(hwgraph_traverse)) == 0, and falls through when v0(=ret(hwgraph_traverse)) != 0.
  The `beq` branch at 0x1378 targets 0x1398, is taken when v0(=ret(hwgraph_path_add)) == 0, and falls through when v0(=ret(hwgraph_path_add)) != 0.
  The `beq` branch at 0x1420 targets 0x153c, is taken when v0(=ret(hwgraph_char_device_add)) == 0, and falls through when v0(=ret(hwgraph_char_device_add)) != 0.
  The `bne` branch at 0x1434 targets 0x13ec, is taken when s3(?) < 0x2 (signed), and falls through when s3(?) >= 0x2 (signed).
  The `beq` branch at 0x14f4 targets 0x1518, is taken when v0(=ret(plpfdc_cpp)) == 0, and falls through when v0(=ret(plpfdc_cpp)) != 0.
  The `beq` branch at 0x1510 targets 0x1580, is taken when v0(=ret(hwgraph_path_add)) == 0, and falls through when v0(=ret(hwgraph_path_add)) != 0.
  The `beq` branch at 0x1518 targets 0x1380 and is always taken.
  The `beq` branch at 0x1534 targets 0x1380 and is always taken.
  The `beq` branch at 0x1578 targets 0x142c and is always taken.
  The `beq` branch at 0x15a4 targets 0x1518 and is always taken.
  The return at 0x1390 has v0 = one of 0x0, ?, ret(device_info_get).

- `plp_io` in `IP32/usr/cpu/sysgen/IP32boot/ecplp.o` at 0x15ac (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/ecplp.o`.
  Range: 0x15ac-0x1c04 (1624 bytes).
  It occupies 1624 bytes.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x2c, including `lw` at 0x15b0, `lw` at 0x1648.
  The `lw` at 0x15dc loads 4 bytes from ret(device_info_get) +0x0.
  The `lw` at 0x15e4 loads 4 bytes from sym(plpinfo) +0x0.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x44, including `lw` at 0x15e8, `lw` at 0x18b0, `lw` at 0x18c8.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x48, including `sw` at 0x15ec, `sw` at 0x1a80.
  3 such `sw` accesses store 4 bytes to ?, including `sw` at 0x15f0, `sw` at 0x1778, `sw` at 0x1b28.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x8, including `ld` at 0x15f4, `ld` at 0x163c.
  10 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x15fc, `lbu` at 0x169c, `lbu` at 0x16bc.
  4 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x30, including `sw` at 0x1624, `sw` at 0x1698, `sw` at 0x1958.
  3 such `sb` accesses store 1 byte to ?, including `sb` at 0x162c, `sb` at 0x175c, `sb` at 0x182c.
  The `lw` at 0x1630 loads 4 bytes from a0 (arg0 at entry) +0x30.
  The `sd` at 0x1644 stores 8 bytes to a0 (arg0 at entry) +0x8.
  4 such `lw` accesses load 4 bytes from ?, including `lw` at 0x1770, `lw` at 0x19a0, `lw` at 0x1aa0.
  The `lw` at 0x18a0 loads 4 bytes from sym(cachewrback) +0x0.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x58, including `lw` at 0x18b8, `lw` at 0x18cc.
  The `lw` at 0x1900 loads 4 bytes from sym(plpRetryDelay1) +0x0.
  The `lw` at 0x1904 loads 4 bytes from sym(plpNumRetries1) +0x0.
  The `lw` at 0x1a78 loads 4 bytes from a0 (arg0 at entry) +0x48.
  2 such `lw` accesses load 4 bytes from sym(plpStrobeDelay) +0x0, including `lw` at 0x1a98, `lw` at 0x1aa8.
  The `lw` at 0x1b80 loads 4 bytes from sym(plpwardelay) +0x0.
  The `lw` at 0x1bf8 loads 4 bytes from sym(plpRetryDelay2) +0x0.
  The `jalr` at 0x15d0 calls device_info_get with a0=[a0+44], a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x1614 calls plp_lock with a0=?, a1=?, a2=?, a3=?.
  The `jalr` at 0x1658 calls iodone with a0=a0 at entry (arg0), a1=?, a2=[a0+44], a3=sym(iodone).
  The `jalr` at 0x1684 calls plp_lock with a0=?, a1=?, a2=?, a3=?, a4=sym(plp_lock).
  The `jalr` at 0x16d0 calls plp_fwd2rvs with a0=?, a1=?, a2=?, a3=?, a6=0x60, a7=0x80.
  The `jalr` at 0x177c calls pciio_pio_read8 with a0=0xffffffffbf380200, a1=?, a2=?, a3=?.
  The `jalr` at 0x1798 calls pciio_pio_write8 with a0=?, a1=0xffffffffbf380200, a2=?, a3=?.
  The `jalr` at 0x17b0 calls pciio_pio_read64 with a0=0xffffffffbf314010, a1=sym(pciio_pio_read64), a2=?, a3=?.
  The `jalr` at 0x17c4 calls pciio_pio_write64 with a0=(ret(pciio_pio_read64) | 0x1), a1=0xffffffffbf314010, a2=?, a3=?.
  The `jalr` at 0x17d0 calls pciio_pio_read8 with a0=0xffffffffbf388200, a1=?, a2=?, a3=?.
  The `jalr` at 0x17ec calls pciio_pio_write8 with a0=?, a1=0xffffffffbf388200, a2=?, a3=?.
  The `jalr` at 0x17fc calls pciio_pio_read64 with a0=0xffffffffbf314010, a1=sym(pciio_pio_read64), a2=?, a3=?.
  The `jalr` at 0x1810 calls pciio_pio_write64 with a0=(ret(pciio_pio_read64) | 0x2), a1=0xffffffffbf314010, a2=sym(pciio_pio_write64), a3=?.
  The `jalr` at 0x1824 calls plp_dmaxfr with a0=?, a1=a0 at entry (arg0), a2=?, a3=sym(plp_dmaxfr).
  The `jalr` at 0x1830 calls pciio_pio_read8 with a0=0xffffffffbf380200, a1=?, a2=?, a3=?.
  The `jalr` at 0x1848 calls pciio_pio_write8 with a0=?, a1=0xffffffffbf380200, a2=?, a3=?.
  The `jalr` at 0x1860 calls pciio_pio_read64 with a0=0xffffffffbf314010, a1=sym(pciio_pio_read64), a2=?, a3=?.
  The `jalr` at 0x1878 calls pciio_pio_write64 with a0=?, a1=0xffffffffbf314010, a2=sym(pciio_pio_write64), a3=?.
  The `jalr` at 0x188c calls plp_unlock with a0=?, a1=sym(plp_unlock), a2=?, a3=?.
  The `jalr` at 0x18b4 calls dki_dcache_wb with a0=[a0+88], a1=[a0+68], a2=[sym(cachewrback)], a3=sym(dki_dcache_wb), a5=0x4.
  The `jalr` at 0x1914 calls pciio_pio_read8 with a0=0xffffffffbf380100, a1=[sym(plpRetryDelay1)], a2=[sym(plpNumRetries1)], a3=?.
  The `jalr` at 0x1948 calls plp_sigdelay with a0=?, a1=?, a2=?, a3=?, a4=-0x1, a6=sym(plp_sigdelay).
  The `jalr` at 0x1964 calls plp_unlock with a0=?, a1=?, a2=?, a3=?.
  The `jalr` at 0x19e8 calls pciio_pio_read8 with a0=0xffffffffbf380100, a1=?, a2=?, a3=?, a7=0x4.
  The `jalr` at 0x1a0c calls pciio_pio_write8 with a0=?, a1=0xffffffffbf380000, a2=sym(pciio_pio_write8), a3=?.
  The `jalr` at 0x1a1c calls us_delaybus with a0=0x1, a1=sym(us_delaybus), a2=?, a3=?.
  The `jalr` at 0x1a24 calls pciio_pio_read8 with a0=0xffffffffbf380200, a1=?, a2=?, a3=?.
  The `jalr` at 0x1a3c calls pciio_pio_write8 with a0=?, a1=0xffffffffbf380200, a2=sym(pciio_pio_write8), a3=?.
  The `jalr` at 0x1a4c calls us_delaybus with a0=0x1, a1=sym(us_delaybus), a2=?, a3=?.
  The `jalr` at 0x1a54 calls pciio_pio_read8 with a0=0xffffffffbf380200, a1=?, a2=?, a3=?.
  The `jalr` at 0x1a70 calls pciio_pio_write8 with a0=?, a1=0xffffffffbf380200, a2=sym(pciio_pio_write8), a3=?.
  The `jalr` at 0x1a94 calls us_delaybus with a0=[sym(plpStrobeDelay)], a1=sym(us_delaybus), a2=?, a3=?.
  The `jalr` at 0x1b24 calls pciio_pio_read8 with a0=0xffffffffbf388200, a1=?, a2=?, a3=sym(pciio_pio_read8).
  The `jalr` at 0x1b48 calls pciio_pio_write8 with a0=?, a1=0xffffffffbf388200, a2=sym(pciio_pio_write8), a3=?.
  The `jalr` at 0x1b5c calls pciio_pio_read64 with a0=0xffffffffbf314010, a1=?, a2=?, a3=sym(pciio_pio_read64).
  The `jalr` at 0x1b74 calls pciio_pio_write64 with a0=(ret(pciio_pio_read64) | 0x2), a1=0xffffffffbf314010, a2=?, a3=?, a4=sym(pciio_pio_write64).
  The `jalr` at 0x1b90 calls plp_war_delay with a0=?, a1=[sym(plpwardelay)], a2=sym(plp_war_delay), a3=?.
  The `jalr` at 0x1ba4 calls plp_dmaxfr with a0=?, a1=a0 at entry (arg0), a2=?, a3=sym(plp_dmaxfr).
  The `jalr` at 0x1bb4 calls plp_unlock with a0=?, a1=?, a2=?, a3=?, a4=sym(plp_unlock).
  The `jalr` at 0x1bd8 calls plp_rvs2fwd with a0=?, a1=?, a2=sym(cachewrback), a3=?, a6=0x6, a7=sym(plp_rvs2fwd).
  The `beq` branch at 0x15c0 targets 0x15e0, is taken when v0(=[a0+44]) == 0, and falls through when v0(=[a0+44]) != 0.
  The `beq` branch at 0x15d8 targets 0x15e8 and is always taken.
  The `beq` branch at 0x1600 targets 0x1678, is taken when (t8(=[a0+8]:8) & 0x1) == 0, and falls through when (t8(=[a0+8]:8) & 0x1) != 0.
  The `beq` branch at 0x161c targets 0x169c, is taken when v0(=ret(plp_lock)) == 0, and falls through when v0(=ret(plp_lock)) != 0.
  The `beq` branch at 0x1634 targets 0x1648, is taken when v1(=[a0+48]) == 0, and falls through when v1(=[a0+48]) != 0.
  The `beq` branch at 0x164c targets 0x1660, is taken when a2(=[a0+44]) == 0, and falls through when a2(=[a0+44]) != 0.
  The `beq` branch at 0x168c targets 0x1710, is taken when v0(=ret(plp_lock)) == 0, and falls through when v0(=ret(plp_lock)) != 0.
  The `beq` branch at 0x1694 targets 0x1628 and is always taken.
  The `beq` branch at 0x16a4 targets 0x16bc, is taken when v0(?) == a6(=0x60), and falls through when v0(?) != a6(=0x60).
  The `beq` branch at 0x16ac targets 0x16f4, is taken when a7(=0x80) == v0(?), and falls through when a7(=0x80) != v0(?).
  The `beq` branch at 0x16b4 targets 0x1664 and is always taken.
  The `beq` branch at 0x16c4 targets 0x16e4, is taken when t0(?) == t1(=0xa), and falls through when t0(?) != t1(=0xa).
  The `beq` branch at 0x16d8 targets 0x1708, is taken when v0(=ret(plp_fwd2rvs)) == 0, and falls through when v0(=ret(plp_fwd2rvs)) != 0.
  The `bne` branch at 0x16ec targets 0x1758, is taken when t3(=0x80) != v0(?), and falls through when t3(=0x80) == v0(?).
  The `beq` branch at 0x1700 targets 0x1758, is taken when t8(?) == t9(=0x2), and falls through when t8(?) != t9(=0x2).
  The `beq` branch at 0x1708 targets 0x1664 and is always taken.
  The `beq` branch at 0x1714 targets 0x189c, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x171c targets 0x189c, is taken when v0(?) == ra(=0xc0), and falls through when v0(?) != ra(=0xc0).
  The `beq` branch at 0x1724 targets 0x18a0, is taken when v0(?) == at(=0x10), and falls through when v0(?) != at(=0x10).
  The `beq` branch at 0x1730 targets 0x1bc4, is taken when v0(?) == v1(=0x60), and falls through when v0(?) != v1(=0x60).
  The `bne` branch at 0x1738 targets 0x1b14, is taken when v0(?) != a0(=0x80), and falls through when v0(?) == a0(=0x80).
  The `beq` branch at 0x1748 targets 0x1b14, is taken when a1(?) == a2(=0x2), and falls through when a1(?) != a2(=0x2).
  The `beq` branch at 0x1750 targets 0x1664 and is always taken.
  The `beq` branch at 0x1894 targets 0x162c and is always taken.
  The `beq` branch at 0x18a4 targets 0x18bc, is taken when a2(=[sym(cachewrback)]) == 0, and falls through when a2(=[sym(cachewrback)]) != 0.
  The `beq` branch at 0x18d4 targets 0x1b08, is taken when a4(=[a0+68]) == 0, and falls through when a4(=[a0+68]) != 0.
  The `bne` branch at 0x1920 targets 0x1a00, is taken when (v0(=ret(pciio_pio_read8)) & 0x80) != 0, and falls through when (v0(=ret(pciio_pio_read8)) & 0x80) == 0.
  The `beq` branch at 0x1934 targets 0x1bf0, is taken when a4(=-0x1) == a5(?), and falls through when a4(=-0x1) != a5(?).
  The `beq` branch at 0x1950 targets 0x197c, is taken when v0(=ret(plp_sigdelay)) == 0, and falls through when v0(=ret(plp_sigdelay)) != 0.
  The `beq` branch at 0x1974 targets 0x1628 and is always taken.
  The `blez` branch at 0x19b0 targets 0x19e4, is taken when v0(?) <= 0 (signed), and falls through when v0(?) > 0 (signed).
  The `bne` branch at 0x19e0 targets 0x195c, is taken when t9(?) < s4(?) (unsigned), and falls through when t9(?) >= s4(?) (unsigned).
  The `beq` branch at 0x19f4 targets 0x192c, is taken when (v0(=ret(pciio_pio_read8)) & 0x80) == 0, and falls through when (v0(=ret(pciio_pio_read8)) & 0x80) != 0.
  The `blez` branch at 0x1ab4 targets 0x1aec, is taken when v0(?) <= 0 (signed), and falls through when v0(?) > 0 (signed).
  The `bne` branch at 0x1ae4 targets 0x1960, is taken when ra(?) < s4(=table(0x2)) (unsigned), and falls through when ra(?) >= s4(=table(0x2)) (unsigned).
  The `bne` branch at 0x1b00 targets 0x18f0, is taken when a1(?) != 0, and falls through when a1(?) == 0.
  The `beq` branch at 0x1b08 targets 0x195c and is always taken.
  The `beq` branch at 0x1b84 targets 0x1b98, is taken when a1(=[sym(plpwardelay)]) == 0, and falls through when a1(=[sym(plpwardelay)]) != 0.
  The `beq` branch at 0x1bbc targets 0x162c and is always taken.
  The `beq` branch at 0x1bcc targets 0x1734, is taken when a5(?) == a6(=0x6), and falls through when a5(?) != a6(=0x6).
  The `beq` branch at 0x1be0 targets 0x1750, is taken when v0(=ret(plp_rvs2fwd)) == 0, and falls through when v0(=ret(plp_rvs2fwd)) != 0.
  The `beq` branch at 0x1be8 targets 0x1734 and is always taken.
  The `beq` branch at 0x1bfc targets 0x193c and is always taken.
  The return at 0x1670 has v0 = one of 0x0, 0x5.
  The instructions from 0x1b10 to 0x1b10 are not reached by any path from the entry, and their branches are not listed.

- `plp_dmaxfr` in `IP32/usr/cpu/sysgen/IP32boot/ecplp.o` at 0x1c04 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/ecplp.o`.
  Range: 0x1c04-0x2300 (1788 bytes).
  It occupies 1788 bytes.
  4 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x168, including `lw` at 0x1c68, `lw` at 0x1d64, `lw` at 0x212c.
  The `lw` at 0x1c80 loads 4 bytes from a0 (arg0 at entry) +0x164.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x168, including `sw` at 0x1cac, `sw` at 0x1d80.
  The `lw` at 0x1cb0 loads 4 bytes from a1 (arg1 at entry) +0x58.
  The `lw` at 0x1cb4 loads 4 bytes from a1 (arg1 at entry) +0x44.
  2 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x48, including `lw` at 0x1cb8, `lw` at 0x1d94.
  4 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x30, including `lw` at 0x1ccc, `lw` at 0x1d44, `lw` at 0x1e08.
  8 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x1d, including `lbu` at 0x1cf0, `lbu` at 0x1cfc, `lbu` at 0x1d38.
  8 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x1e, including `lbu` at 0x1e40, `lbu` at 0x1e64, `lbu` at 0x1e7c.
  2 such `sw` accesses store 4 bytes to ?, including `sw` at 0x1e78, `sw` at 0x1e90.
  2 such `lw` accesses load 4 bytes from sym(cachewrback) +0x0, including `lw` at 0x1e9c, `lw` at 0x1fa0.
  The `lw` at 0x1eb0 loads 4 bytes from ?.
  The `sw` at 0x1ef8 stores 4 bytes to a0 (arg0 at entry) +0x180.
  The `ld` at 0x1f34 loads 8 bytes from a0 (arg0 at entry) +0x28.
  The `sd` at 0x1f50 stores 8 bytes to a0 (arg0 at entry) +0x28.
  2 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x1e, including `sb` at 0x1f64, `sb` at 0x22ac.
  The `lbu` at 0x1f80 loads 1 byte from a0 (arg0 at entry) +0x20.
  The `sb` at 0x1f98 stores 1 byte to a0 (arg0 at entry) +0x1d.
  The `sw` at 0x1fc0 stores 4 bytes to a0 (arg0 at entry) +0x17c.
  5 such `sw` accesses store 4 bytes to a1 (arg1 at entry) +0x30, including `sw` at 0x2010, `sw` at 0x20ac, `sw` at 0x20c8.
  4 such `sw` accesses store 4 bytes to a1 (arg1 at entry) +0x48, including `sw` at 0x2088, `sw` at 0x20b4, `sw` at 0x2134.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x178, including `lw` at 0x2094, `lw` at 0x2138.
  4 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x170, including `ld` at 0x216c, `ld` at 0x2198, `ld` at 0x21c8.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x17c, including `lw` at 0x218c, `lw` at 0x21e8.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x180, including `lw` at 0x21bc, `lw` at 0x2218.
  The `jalr` at 0x1c28 calls plp_lock with a0=a0+320, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x1c60 calls mutex_lock with a0=a0+288, a1=0x19, a2=?, a3=?.
  The `jalr` at 0x1c78 calls untimeout with a0=[a0+360], a1=?, a2=?, a3=?.
  The `jalr` at 0x1c98 calls timeout with a0=sym(plp_tmout), a1=a0 at entry (arg0), a2=[a0+356], a3=?.
  The `jalr` at 0x1d20 calls sv_wait_sig with a0=a0+328, a1=0x19, a2=a0+288, a3=0x0.
  The `jalr` at 0x1d30 calls mutex_lock with a0=a0+288, a1=0x19, a2=?, a3=?.
  The `jalr` at 0x1d5c calls mutex_unlock with a0=a0+288, a1=?, a2=?, a3=?.
  The `jalr` at 0x1d78 calls untimeout with a0=[a0+360], a1=?, a2=?, a3=?.
  The `jalr` at 0x1d8c calls plp_unlock with a0=a0+320, a1=?, a2=?, a3=?.
  The `jalr` at 0x1de0 calls sv_wait_sig with a0=a0+328, a1=0x19, a2=a0+288, a3=0x0.
  The `jalr` at 0x1df4 calls mutex_lock with a0=a0+288, a1=0x19, a2=?, a3=?, a6=sym(pciio_pio_read64).
  The `jalr` at 0x1ec0 calls dki_dcache_inval with a0=?, a1=?, a2=sym(dki_dcache_inval), a3=?, a5=[a0+32]:1.
  The `jalr` at 0x1ed0 calls kvtophys with a0=?, a1=?, a2=?, a3=sym(kvtophys).
  The `jalr` at 0x1f24 calls pciio_pio_write64 with a0=?, a1=one of 0xffffffffbf314000, 0xffffffffbf314008, a2=?, a3=(table(-0x1) << 0x20), a4=-0x1, a5=[a0+30]:1.
  The `jalr` at 0x1f4c calls mace_mask_update with a0=0xf0000, a1=?, a2=?, a3=[a0+30]:1.
  The `jalr` at 0x1fe0 calls dki_dcache_wb with a0=?, a1=?, a2=sym(dki_dcache_wb), a3=sym(kvtophys), a5=[a0+32]:1.
  The `jalr` at 0x2014 calls pciio_pio_read64 with a0=0xffffffffbf314010, a1=?, a2=?, a3=sym(pciio_pio_read64), a4=0x4.
  The `jalr` at 0x202c calls pciio_pio_write64 with a0=?, a1=0xffffffffbf314010, a2=?, a3=?, a4=sym(pciio_pio_write64).
  The `jalr` at 0x2044 calls pciio_pio_read8 with a0=0xffffffffbf388200, a1=sym(pciio_pio_read8), a2=?, a3=?.
  The `jalr` at 0x2060 calls pciio_pio_write8 with a0=?, a1=0xffffffffbf388200, a2=sym(pciio_pio_write8), a3=?.
  The `jalr` at 0x2070 calls plp_reset_dmacntxts with a0=a0 at entry (arg0), a1=?, a2=?, a3=sym(plp_reset_dmacntxts).
  The `jalr` at 0x20cc calls pciio_pio_read64 with a0=0xffffffffbf314010, a1=?, a2=?, a3=?, a6=sym(pciio_pio_read64), a7=0x4.
  The `jalr` at 0x20dc calls pciio_pio_write64 with a0=?, a1=0xffffffffbf314010, a2=?, a3=?.
  The `jalr` at 0x20f4 calls pciio_pio_read8 with a0=0xffffffffbf388200, a1=sym(pciio_pio_read8), a2=?, a3=?.
  The `jalr` at 0x2110 calls pciio_pio_write8 with a0=?, a1=0xffffffffbf388200, a2=sym(pciio_pio_write8), a3=?.
  The `jalr` at 0x2120 calls plp_reset_dmacntxts with a0=a0 at entry (arg0), a1=?, a2=?, a3=sym(plp_reset_dmacntxts).
  The `jalr` at 0x215c calls mutex_unlock with a0=a0+288, a1=?, a2=?, a3=?, a5=sym(mutex_unlock).
  The `jalr` at 0x2294 calls cmn_err with a0=0x4, a1=sym(.rodata), a2=?, a3=?.
  The `jalr` at 0x22cc calls cmn_err with a0=0x4, a1=sym(.rodata)+344, a2=?, a3=?, a4=sym(cmn_err).
  The `jalr` at 0x22f0 calls cmn_err with a0=0x4, a1=sym(.rodata), a2=?, a3=?, a5=sym(cmn_err).
  The `bne` branch at 0x1c48 targets 0x22b8, is taken when v0(=ret(plp_lock)) != 0, and falls through when v0(=ret(plp_lock)) == 0.
  The `beq` branch at 0x1c6c targets 0x1c80, is taken when a0(=[a0+360]) == 0, and falls through when a0(=[a0+360]) != 0.
  The `beq` branch at 0x1c84 targets 0x1ca8, is taken when a2(=[a0+356]) == 0, and falls through when a2(=[a0+356]) != 0.
  The `beq` branch at 0x1ca0 targets 0x1cac and is always taken.
  The `beq` branch at 0x1cc4 targets 0x2080, is taken when a0(=[a1+72]) == 0, and falls through when a0(=[a1+72]) != 0.
  The `bne` branch at 0x1cd0 targets 0x1cfc, is taken when a4(=[a1+48]) != 0, and falls through when a4(=[a1+48]) == 0.
  The `beq` branch at 0x1cf4 targets 0x1e2c and is always taken.
  The `beq` branch at 0x1d08 targets 0x1d44, is taken when s4(=0x3) == v0(=[a0+29]:1), and falls through when s4(=0x3) != v0(=[a0+29]:1).
  The `bltz` branch at 0x1d28 targets 0x1ffc, is taken when v0(=ret(sv_wait_sig)) < 0 (signed), and falls through when v0(=ret(sv_wait_sig)) >= 0 (signed).
  The `bne` branch at 0x1d3c targets 0x1d18, is taken when s4(=0x3) != t8(=[a0+29]:1), and falls through when s4(=0x3) == t8(=[a0+29]:1).
  The `beq` branch at 0x1d48 targets 0x2130, is taken when a1(=[a1+48]) == 0, and falls through when a1(=[a1+48]) != 0.
  The `beq` branch at 0x1d50 targets 0x2094, is taken when a1(=[a1+48]) == t9(=0xb), and falls through when a1(=[a1+48]) != t9(=0xb).
  The `beq` branch at 0x1d70 targets 0x1d84, is taken when a0(=[a0+360]) == 0, and falls through when a0(=[a0+360]) != 0.
  The `bne` branch at 0x1d98 targets 0x22dc, is taken when a0(=[a1+72]) != 0, and falls through when a0(=[a1+72]) == 0.
  The `bne` branch at 0x1dcc targets 0x1e08, is taken when v0(=[a0+29]:1) != 0, and falls through when v0(=[a0+29]:1) == 0.
  The `bltz` branch at 0x1de8 targets 0x20b8, is taken when v0(=ret(sv_wait_sig)) < 0 (signed), and falls through when v0(=ret(sv_wait_sig)) >= 0 (signed).
  The `beq` branch at 0x1e00 targets 0x1dd8, is taken when v0(=[a0+29]:1) == 0, and falls through when v0(=[a0+29]:1) != 0.
  The `beq` branch at 0x1e0c targets 0x2088, is taken when a1(=[a1+48]) == 0, and falls through when a1(=[a1+48]) != 0.
  The `beq` branch at 0x1e14 targets 0x2138, is taken when a1(=[a1+48]) == a2(=0xb), and falls through when a1(=[a1+48]) != a2(=0xb).
  The `beq` branch at 0x1e1c targets 0x1d00, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `bne` branch at 0x1e24 targets 0x1d00, is taken when a1(=[a1+48]) != 0, and falls through when a1(=[a1+48]) == 0.
  The `beq` branch at 0x1e2c targets 0x1dd4, is taken when v0(=[a0+29]:1) == 0, and falls through when v0(=[a0+29]:1) != 0.
  The `beq` branch at 0x1e34 targets 0x1dcc, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `beq` branch at 0x1e3c targets 0x1f6c and is always taken.
  The `bne` branch at 0x1e54 targets 0x1fb4, is taken when s1(?) < s2(?) (unsigned), and falls through when s1(?) >= s2(?) (unsigned).
  The `beq` branch at 0x1e5c targets 0x1fd0, is taken when a5(=[a0+32]:1) == 0, and falls through when a5(=[a0+32]:1) != 0.
  The `beq` branch at 0x1eac targets 0x1ec8, is taken when t8(=[sym(cachewrback)]) == 0, and falls through when t8(=[sym(cachewrback)]) != 0.
  The `beq` branch at 0x1ee4 targets 0x1ff0, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `beq` branch at 0x1eec targets 0x1fbc, is taken when a5(=[a0+30]:1) == 0, and falls through when a5(=[a0+30]:1) != 0.
  The `beq` branch at 0x1ef4 targets 0x1fc4, is taken when a5(=[a0+30]:1) == 0, and falls through when a5(=[a0+30]:1) != 0.
  The `beq` branch at 0x1f60 targets 0x1dd4, is taken when v0(=[a0+29]:1) == 0, and falls through when v0(=[a0+29]:1) != 0.
  The `beq` branch at 0x1f68 targets 0x1dcc, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `beq` branch at 0x1f78 targets 0x2284, is taken when (a2(?) & v0(=[a0+29]:1)) == 0, and falls through when (a2(?) & v0(=[a0+29]:1)) != 0.
  The `beq` branch at 0x1fa4 targets 0x1e44, is taken when a5(=[a0+32]:1) == 0, and falls through when a5(=[a0+32]:1) != 0.
  The `beq` branch at 0x1fac targets 0x1e5c, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `beq` branch at 0x1fb4 targets 0x1e5c and is always taken.
  The `bne` branch at 0x1fbc targets 0x1efc, is taken when a5(=[a0+30]:1) != 0, and falls through when a5(=[a0+30]:1) == 0.
  The `beq` branch at 0x1fc8 targets 0x1f04 and is always taken.
  The `beq` branch at 0x1fd0 targets 0x1ecc, is taken when a1(=[sym(cachewrback)]) == 0, and falls through when a1(=[sym(cachewrback)]) != 0.
  The `beq` branch at 0x1fe8 targets 0x1ecc and is always taken.
  The `beq` branch at 0x1ff4 targets 0x1eec and is always taken.
  The `beq` branch at 0x2078 targets 0x1d48 and is always taken.
  The `beq` branch at 0x2080 targets 0x1d00 and is always taken.
  The `beq` branch at 0x208c targets 0x1e1c and is always taken.
  The `beq` branch at 0x209c targets 0x216c, is taken when (a1(=[a0+376]) & 0x1) == 0, and falls through when (a1(=[a0+376]) & 0x1) != 0.
  The `beq` branch at 0x20a4 targets 0x2198, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `beq` branch at 0x20b0 targets 0x1d54 and is always taken.
  The `beq` branch at 0x2128 targets 0x1d68 and is always taken.
  The `beq` branch at 0x2130 targets 0x1d54 and is always taken.
  The `beq` branch at 0x2140 targets 0x21c8, is taken when (a1(=[a0+376]) & 0x1) == 0, and falls through when (a1(=[a0+376]) & 0x1) != 0.
  The `beq` branch at 0x2148 targets 0x21f4, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0x2164 targets 0x1d68 and is always taken.
  The `beq` branch at 0x2174 targets 0x218c, is taken when (v0(=[a0+368]:8) & 0x2) == 0, and falls through when (v0(=[a0+368]:8) & 0x2) != 0.
  The `beq` branch at 0x2184 targets 0x2224, is taken when a2(=0x1) == a7(?), and falls through when a2(=0x1) != a7(?).
  The `beq` branch at 0x2190 targets 0x20a0 and is always taken.
  The `beq` branch at 0x21a0 targets 0x21bc, is taken when (v0(=[a0+368]:8) & 0x2) == 0, and falls through when (v0(=[a0+368]:8) & 0x2) != 0.
  The `beq` branch at 0x21b4 targets 0x223c, is taken when t2(?) == t3(=0x2), and falls through when t2(?) != t3(=0x2).
  The `beq` branch at 0x21c0 targets 0x20ac and is always taken.
  The `beq` branch at 0x21d0 targets 0x21e8, is taken when (v0(=[a0+368]:8) & 0x2) == 0, and falls through when (v0(=[a0+368]:8) & 0x2) != 0.
  The `beq` branch at 0x21e0 targets 0x2254, is taken when t9(=0x1) == ra(?), and falls through when t9(=0x1) != ra(?).
  The `beq` branch at 0x21ec targets 0x2148 and is always taken.
  The `beq` branch at 0x21fc targets 0x2218, is taken when (v0(=[a0+368]:8) & 0x2) == 0, and falls through when (v0(=[a0+368]:8) & 0x2) != 0.
  The `beq` branch at 0x2210 targets 0x226c, is taken when a0(?) == a1(=0x2), and falls through when a0(?) != a1(=0x2).
  The `beq` branch at 0x221c targets 0x214c and is always taken.
  The `beq` branch at 0x2234 targets 0x20a0 and is always taken.
  The `beq` branch at 0x224c targets 0x20ac and is always taken.
  The `beq` branch at 0x2264 targets 0x2148 and is always taken.
  The `beq` branch at 0x227c targets 0x214c and is always taken.
  The `beq` branch at 0x22b0 targets 0x1f80 and is always taken.
  The `beq` branch at 0x22d4 targets 0x1da0 and is always taken.
  The `beq` branch at 0x22f8 targets 0x1da0 and is always taken.
  The return at 0x1dc4 has v0 = one of ret(plp_unlock), ret(cmn_err).

- `plp_reset_dmacntxts` in `IP32/usr/cpu/sysgen/IP32boot/ecplp.o` at 0x2300 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/ecplp.o`.
  Range: 0x2300-0x2390 (144 bytes).
  It occupies 144 bytes.
  The `sb` at 0x236c stores 1 byte to a0 (arg0 at entry) +0x1e.
  The `sb` at 0x2370 stores 1 byte to a0 (arg0 at entry) +0x1f.
  The `sb` at 0x237c stores 1 byte to a0 (arg0 at entry) +0x1d.
  The `sb` at 0x2380 stores 1 byte to a0 (arg0 at entry) +0x1c.
  The `jalr` at 0x2324 calls pciio_pio_read64 with a0=0xffffffffbf314010, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x2338 calls pciio_pio_write64 with a0=(ret(pciio_pio_read64) | 0x4), a1=0xffffffffbf314010, a2=?, a3=?.
  The `jalr` at 0x2348 calls pciio_pio_read64 with a0=0xffffffffbf314010, a1=sym(pciio_pio_read64), a2=?, a3=?.
  The `jalr` at 0x2360 calls pciio_pio_write64 with a0=?, a1=0xffffffffbf314010, a2=sym(pciio_pio_write64), a3=?.
  The return at 0x2388 has v0 = ret(pciio_pio_write64).

- `plp_sigdelay` in `IP32/usr/cpu/sysgen/IP32boot/ecplp.o` at 0x2390 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/ecplp.o`.
  Range: 0x2390-0x2460 (208 bytes).
  It occupies 208 bytes.
  The `jalr` at 0x23b8 calls mutex_lock with a0=a0+296, a1=0x19, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x23d4 calls timeout with a0=sym(plp_sigdelay_tmout), a1=a0 at entry (arg0), a2=a1 at entry (arg1), a3=sym(timeout).
  The `jalr` at 0x23f4 calls sv_wait_sig with a0=a0+332, a1=0x19, a2=a0+296, a3=0x0, a4=sym(sv_wait_sig).
  The `jalr` at 0x2428 calls mutex_lock with a0=a0+288, a1=0x19, a2=?, a3=?, a5=sym(mutex_lock).
  The `jalr` at 0x2440 calls untimeout with a0=ret(timeout), a1=?, a2=?, a3=?, a6=sym(untimeout), a7=sym(mutex_unlock).
  The `jalr` at 0x2450 calls mutex_unlock with a0=a0+288, a1=?, a2=?, a3=?, a7=sym(mutex_unlock).
  The `bltz` branch at 0x23fc targets 0x2418, is taken when v0(=ret(sv_wait_sig)) < 0 (signed), and falls through when v0(=ret(sv_wait_sig)) >= 0 (signed).
  The `beq` branch at 0x2430 targets 0x244c, is taken when s2(=ret(timeout)) == 0, and falls through when s2(=ret(timeout)) != 0.
  The `beq` branch at 0x2458 targets 0x2404 and is always taken.
  The return at 0x2410 has v0 = one of 0x0, 0x1.

- `plp_sigdelay_tmout` in `IP32/usr/cpu/sysgen/IP32boot/ecplp.o` at 0x2460 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/ecplp.o`.
  Range: 0x2460-0x24b8 (88 bytes).
  It occupies 88 bytes.
  The `jalr` at 0x2480 calls mutex_lock with a0=a0+296, a1=0x19, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x2490 calls sv_signal with a0=a0+332, a1=?, a2=?, a3=?.
  The `jalr` at 0x24a4 calls mutex_unlock with a0=a0+296, a1=?, a2=?, a3=?.
  The return at 0x24b0 has v0 = ret(mutex_unlock).

- `plp_prlock` in `IP32/usr/cpu/sysgen/IP32boot/ecplp.o` at 0x24b8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/ecplp.o`.
  Range: 0x24b8-0x2558 (160 bytes).
  It occupies 160 bytes.
  The `lbu` at 0x24f0 loads 1 byte from a0 (arg0 at entry) +0x0.
  The `lw` at 0x2514 loads 4 bytes from a0 (arg0 at entry) +0x158.
  The `sb` at 0x2518 stores 1 byte to a0 (arg0 at entry) +0x0.
  The `sw` at 0x2524 stores 4 bytes to a0 (arg0 at entry) +0x158.
  The `jalr` at 0x24e8 calls mutex_lock with a0=a0+280, a1=0x19, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x2538 calls mutex_unlock with a0=a0+280, a1=([a0]:1 | (a1 | 0x10)), a2=sym(mutex_unlock), a3=(a1 | 0x10).
  The `beq` branch at 0x2504 targets 0x2514, is taken when (a0(=[a0]:1) & 0x10) == 0, and falls through when (a0(=[a0]:1) & 0x10) != 0.
  The `bne` branch at 0x250c targets 0x2528, is taken when s0(=a1) != v0(?), and falls through when s0(=a1) == v0(?).
  The return at 0x2550 has v0 = one of 0x0, 0x5.

- `plp_prunlock` in `IP32/usr/cpu/sysgen/IP32boot/ecplp.o` at 0x2558 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/ecplp.o`.
  Range: 0x2558-0x25e8 (144 bytes).
  It occupies 144 bytes.
  The `lbu` at 0x258c loads 1 byte from a0 (arg0 at entry) +0x0.
  The `lw` at 0x259c loads 4 bytes from a0 (arg0 at entry) +0x158.
  The `sw` at 0x25a8 stores 4 bytes to a0 (arg0 at entry) +0x158.
  The `sb` at 0x25e4 stores 1 byte to a0 (arg0 at entry) +0x0.
  The `jalr` at 0x2584 calls mutex_lock with a0=a0+280, a1=0x19, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x25bc calls mutex_unlock with a0=a0+280, a1=sym(mutex_unlock), a2=?, a3=?.
  The `bne` branch at 0x2594 targets 0x25b0, is taken when s1(=a1) != v0(?), and falls through when s1(=a1) == v0(?).
  The `beq` branch at 0x25a4 targets 0x25d4, is taken when v1(=[a0+344]-1) == 0, and falls through when v1(=[a0+344]-1) != 0.
  The `beq` branch at 0x25e0 targets 0x25ac and is always taken.
  The return at 0x25cc has v0 = ret(mutex_unlock).

- `plp_lock` in `IP32/usr/cpu/sysgen/IP32boot/ecplp.o` at 0x25e8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/ecplp.o`.
  Range: 0x25e8-0x261c (52 bytes).
  It occupies 52 bytes.
  The `jalr` at 0x25f8 calls psema with a0=a0 at entry (arg0), a1=0x1a, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `bltz` branch at 0x2600 targets 0x2614, is taken when v0(=ret(psema)) < 0 (signed), and falls through when v0(=ret(psema)) >= 0 (signed).
  The `beq` branch at 0x2614 targets 0x260c and is always taken.
  The return at 0x260c has v0 = one of 0x0, 0x1.

- `plp_unlock` in `IP32/usr/cpu/sysgen/IP32boot/ecplp.o` at 0x261c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/ecplp.o`.
  Range: 0x261c-0x2640 (36 bytes).
  It occupies 36 bytes.
  The `jalr` at 0x262c calls vsema with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x2638 has v0 = ret(vsema).

- `plp_rbflush` in `IP32/usr/cpu/sysgen/IP32boot/ecplp.o` at 0x2640 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/ecplp.o`.
  Range: 0x2640-0x2718 (216 bytes).
  It occupies 216 bytes.
  The `lbu` at 0x2684 loads 1 byte from a0 (arg0 at entry) +0x1c.
  The `sb` at 0x2694 stores 1 byte to a0 (arg0 at entry) +0x1e.
  The `sb` at 0x26ac stores 1 byte to a0 (arg0 at entry) +0x1c.
  4 such `lw` accesses load 4 bytes from ?, including `lw` at 0x26c8, `lw` at 0x26e0, `lw` at 0x26e4.
  The `sw` at 0x26d8 stores 4 bytes to ?.
  The `jalr` at 0x2668 calls pciio_pio_read64 with a0=0xffffffffbf314018, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x267c calls pciio_pio_read64 with a0=0xffffffffbf314018, a1=?, a2=?, a3=?.
  The `jalr` at 0x26a8 calls pciio_pio_read64 with a0=0xffffffffbf314018, a1=?, a2=?, a3=?.
  The `jalr` at 0x26e8 calls bcopy with a0=?, a1=?, a2=?, a3=sym(bcopy).
  The `jalr` at 0x26f8 calls sv_signal with a0=a0+328, a1=?, a2=?, a3=?, a4=sym(sv_signal).
  The `beq` branch at 0x2674 targets 0x2704, is taken when (v0(=ret(pciio_pio_read64)) & 0x2) == 0, and falls through when (v0(=ret(pciio_pio_read64)) & 0x2) != 0.
  The return at 0x2710 has v0 = one of ret(pciio_pio_read64), ret(sv_signal).

- `plp_reset` in `IP32/usr/cpu/sysgen/IP32boot/ecplp.o` at 0x2718 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/ecplp.o`.
  Range: 0x2718-0x280c (244 bytes).
  It occupies 244 bytes.
  The `jalr` at 0x2734 calls plp_lock with a0=a0+320, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x275c calls pciio_pio_write8 with a0=0x8, a1=0xffffffffbf380200, a2=?, a3=?.
  The `jalr` at 0x276c calls delay with a0=0x1, a1=?, a2=?, a3=?.
  The `jalr` at 0x2784 calls pciio_pio_write8 with a0=0xe, a1=0xffffffffbf380200, a2=sym(pciio_pio_write8), a3=?.
  The `jalr` at 0x2794 calls plp_reset_dmacntxts with a0=a0 at entry (arg0), a1=?, a2=sym(plp_reset_dmacntxts), a3=?.
  The `jalr` at 0x27a8 calls pciio_pio_read64 with a0=0xffffffffbf314010, a1=?, a2=?, a3=sym(pciio_pio_read64).
  The `jalr` at 0x27c4 calls pciio_pio_write64 with a0=?, a1=0xffffffffbf314010, a2=?, a3=?, a4=sym(pciio_pio_write64).
  The `jalr` at 0x27d4 calls pciio_pio_read64 with a0=0xffffffffbf310000, a1=?, a2=?, a3=?, a5=sym(pciio_pio_read64).
  The `jalr` at 0x27ec calls pciio_pio_write64 with a0=?, a1=0xffffffffbf310000, a2=?, a3=?, a6=sym(pciio_pio_write64).
  The `jalr` at 0x27fc calls plp_unlock with a0=a0+320, a1=sym(plp_unlock), a2=?, a3=?.
  The `beq` branch at 0x273c targets 0x2750, is taken when v0(=ret(plp_lock)) == 0, and falls through when v0(=ret(plp_lock)) != 0.
  The `beq` branch at 0x2804 targets 0x2748 and is always taken.
  The return at 0x2748 has v0 = one of ret(plp_lock), ret(plp_unlock).

- `plp_negotiate` in `IP32/usr/cpu/sysgen/IP32boot/ecplp.o` at 0x280c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/ecplp.o`.
  Range: 0x280c-0x2b78 (876 bytes).
  It occupies 876 bytes.
  The `lbu` at 0x2814 loads 1 byte from a0 (arg0 at entry) +0x2.
  2 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x2, including `sb` at 0x2a68, `sb` at 0x2b50.
  The `jalr` at 0x2858 calls pciio_pio_write8 with a0=a1 at entry (arg1), a1=0xffffffffbf380000, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x2870 calls pciio_pio_read8 with a0=0xffffffffbf380200, a1=?, a2=?, a3=?.
  The `jalr` at 0x288c calls pciio_pio_write8 with a0=?, a1=0xffffffffbf380200, a2=?, a3=?.
  The `jalr` at 0x289c calls pciio_pio_read8 with a0=0xffffffffbf380100, a1=?, a2=?, a3=?.
  The `jalr` at 0x28cc calls pciio_pio_read8 with a0=0xffffffffbf380100, a1=?, a2=?, a3=?.
  The `jalr` at 0x28f8 calls delay with a0=0x1, a1=?, a2=?, a3=?.
  The `jalr` at 0x2910 calls pciio_pio_read8 with a0=0xffffffffbf380200, a1=?, a2=?, a3=?.
  The `jalr` at 0x2920 calls pciio_pio_write8 with a0=?, a1=0xffffffffbf380200, a2=?, a3=?.
  The `jalr` at 0x2930 calls us_delaybus with a0=0x1, a1=sym(us_delaybus), a2=?, a3=?.
  The `jalr` at 0x2938 calls pciio_pio_read8 with a0=0xffffffffbf380200, a1=?, a2=?, a3=?.
  The `jalr` at 0x294c calls pciio_pio_write8 with a0=?, a1=0xffffffffbf380200, a2=?, a3=?.
  The `jalr` at 0x2954 calls pciio_pio_read8 with a0=0xffffffffbf380100, a1=?, a2=?, a3=?.
  The `jalr` at 0x2984 calls pciio_pio_read8 with a0=0xffffffffbf380100, a1=?, a2=?, a3=?.
  The `jalr` at 0x29a8 calls delay with a0=0x1, a1=?, a2=?, a3=?.
  The `jalr` at 0x29d8 calls pciio_pio_read8 with a0=0xffffffffbf380100, a1=?, a2=?, a3=?.
  The `jalr` at 0x2a00 calls plp_phase_reset with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?.
  The `jalr` at 0x2aa8 calls pciio_pio_read8 with a0=0xffffffffbf380100, a1=?, a2=?, a3=?.
  The `jalr` at 0x2acc calls delay with a0=0x1, a1=?, a2=?, a3=?.
  The `jalr` at 0x2adc calls pciio_pio_read8 with a0=0xffffffffbf380100, a1=?, a2=?, a3=?.
  The `jalr` at 0x2afc calls pciio_pio_read8 with a0=0xffffffffbf380100, a1=?, a2=?, a3=?.
  The `jalr` at 0x2b20 calls delay with a0=0x1, a1=?, a2=?, a3=?.
  The `jalr` at 0x2b30 calls pciio_pio_read8 with a0=0xffffffffbf380200, a1=?, a2=?, a3=?.
  The `jalr` at 0x2b44 calls pciio_pio_write8 with a0=?, a1=0xffffffffbf380200, a2=?, a3=?.
  The `beq` branch at 0x2828 targets 0x2844, is taken when at(=[a0+2]:1) == 0, and falls through when at(=[a0+2]:1) != 0.
  The `beq` branch at 0x28b0 targets 0x2908, is taken when a0(=0x38) == t8(?), and falls through when a0(=0x38) != t8(?).
  The `beq` branch at 0x28c0 targets 0x2b5c and is always taken.
  The `beq` branch at 0x28e0 targets 0x2908, is taken when a0(=0x38) == t8(?), and falls through when a0(=0x38) != t8(?).
  The `beq` branch at 0x28e8 targets 0x29f8, is taken when t9(?) == 0, and falls through when t9(?) != 0.
  The `bne` branch at 0x28f0 targets 0x28c8, is taken when v0(?) != 0, and falls through when v0(?) == 0.
  The `beq` branch at 0x2900 targets 0x28cc and is always taken.
  The `beq` branch at 0x295c targets 0x2a40, is taken when v0(=ret(pciio_pio_read8)) == 0, and falls through when v0(=ret(pciio_pio_read8)) != 0.
  The `beq` branch at 0x2964 targets 0x2a48, is taken when a1(=0x10) == s4(=a1), and falls through when a1(=0x10) != s4(=a1).
  The `beq` branch at 0x2970 targets 0x2a90, is taken when a2(=0x40) == s4(=a1), and falls through when a2(=0x40) != s4(=a1).
  The `beq` branch at 0x2978 targets 0x2998 and is always taken.
  The `bne` branch at 0x298c targets 0x29b8, is taken when v0(=ret(pciio_pio_read8)) != 0, and falls through when v0(=ret(pciio_pio_read8)) == 0.
  The `beq` branch at 0x2998 targets 0x29f4, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `bne` branch at 0x29a0 targets 0x2980, is taken when v0(?) != 0, and falls through when v0(?) == 0.
  The `beq` branch at 0x29b0 targets 0x2984 and is always taken.
  The `beq` branch at 0x29bc targets 0x2a2c, is taken when a4(=0x10) == s4(=a1), and falls through when a4(=0x10) != s4(=a1).
  The `bne` branch at 0x29c4 targets 0x2998, is taken when a5(=0x40) != s4(=a1), and falls through when a5(=0x40) == s4(=a1).
  The `beq` branch at 0x29d0 targets 0x2998, is taken when (v0(=ret(pciio_pio_read8)) & 0x10) == 0, and falls through when (v0(=ret(pciio_pio_read8)) & 0x10) != 0.
  The `bne` branch at 0x29e4 targets 0x2a60, is taken when (v0(=ret(pciio_pio_read8)) & 0x40) != 0, and falls through when (v0(=ret(pciio_pio_read8)) & 0x40) == 0.
  The `beq` branch at 0x29ec targets 0x2b6c and is always taken.
  The `beq` branch at 0x2a24 targets 0x2834 and is always taken.
  The `bne` branch at 0x2a30 targets 0x29c4, is taken when t1(=0x90) != t2(?), and falls through when t1(=0x90) == t2(?).
  The `beq` branch at 0x2a38 targets 0x29d8 and is always taken.
  The `beq` branch at 0x2a40 targets 0x2978 and is always taken.
  The `bne` branch at 0x2a4c targets 0x2970, is taken when t3(?) != t8(=0x90), and falls through when t3(?) == t8(=0x90).
  The `beq` branch at 0x2a54 targets 0x29d8 and is always taken.
  The `beq` branch at 0x2a60 targets 0x2adc, is taken when t9(=0x10) == s4(=a1), and falls through when t9(=0x10) != s4(=a1).
  The `beq` branch at 0x2a88 targets 0x2834 and is always taken.
  The `bne` branch at 0x2a94 targets 0x29d8, is taken when (v0(=ret(pciio_pio_read8)) & 0x10) != 0, and falls through when (v0(=ret(pciio_pio_read8)) & 0x10) == 0.
  The `beq` branch at 0x2a9c targets 0x2978 and is always taken.
  The `bne` branch at 0x2ab4 targets 0x2a5c, is taken when (v0(=ret(pciio_pio_read8)) & 0x40) != 0, and falls through when (v0(=ret(pciio_pio_read8)) & 0x40) == 0.
  The `beq` branch at 0x2abc targets 0x29f4, is taken when v1(?) == 0, and falls through when v1(?) != 0.
  The `bne` branch at 0x2ac4 targets 0x2aa4, is taken when v0(?) != 0, and falls through when v0(?) == 0.
  The `beq` branch at 0x2ad4 targets 0x2aa8 and is always taken.
  The `bne` branch at 0x2ae8 targets 0x2b30, is taken when (v0(=ret(pciio_pio_read8)) & 0x20) != 0, and falls through when (v0(=ret(pciio_pio_read8)) & 0x20) == 0.
  The `beq` branch at 0x2af0 targets 0x2b0c and is always taken.
  The `bne` branch at 0x2b08 targets 0x2b30, is taken when (v0(=ret(pciio_pio_read8)) & 0x20) != 0, and falls through when (v0(=ret(pciio_pio_read8)) & 0x20) == 0.
  The `beq` branch at 0x2b10 targets 0x29f4, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `bne` branch at 0x2b18 targets 0x2af8, is taken when a3(?) != 0, and falls through when a3(?) == 0.
  The `beq` branch at 0x2b28 targets 0x2afc and is always taken.
  The `beq` branch at 0x2b54 targets 0x2a70 and is always taken.
  The `beq` branch at 0x2b64 targets 0x28e8 and is always taken.
  The `beq` branch at 0x2b70 targets 0x2abc and is always taken.
  The return at 0x283c has v0 = one of 0x0, 0x2, 0x6.

- `plp_phase_reset` in `IP32/usr/cpu/sysgen/IP32boot/ecplp.o` at 0x2b78 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/ecplp.o`.
  Range: 0x2b78-0x2da4 (556 bytes).
  It occupies 556 bytes.
  The `lbu` at 0x2bac loads 1 byte from a0 (arg0 at entry) +0x2.
  The `sb` at 0x2bd4 stores 1 byte to a0 (arg0 at entry) +0x2.
  The `jalr` at 0x2bf8 calls pciio_pio_read8 with a0=0xffffffffbf380200, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=0x6, a4=0x40, a5=0x2.
  The `jalr` at 0x2c18 calls pciio_pio_write8 with a0=?, a1=0xffffffffbf380200, a2=?, a3=?.
  The `jalr` at 0x2c28 calls pciio_pio_read8 with a0=0xffffffffbf380100, a1=?, a2=?, a3=?.
  The `jalr` at 0x2c50 calls pciio_pio_read8 with a0=0xffffffffbf380100, a1=?, a2=?, a3=?.
  The `jalr` at 0x2c80 calls delay with a0=0x1, a1=0x8, a2=?, a3=?.
  The `jalr` at 0x2ca0 calls pciio_pio_read8 with a0=0xffffffffbf380200, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=0x6, a4=0x40, a5=0x2.
  The `jalr` at 0x2cbc calls pciio_pio_write8 with a0=?, a1=0xffffffffbf380200, a2=?, a3=?.
  The `jalr` at 0x2cc4 calls pciio_pio_read8 with a0=0xffffffffbf380200, a1=?, a2=?, a3=?.
  The `jalr` at 0x2cd4 calls pciio_pio_write8 with a0=?, a1=0xffffffffbf380200, a2=?, a3=?.
  The `jalr` at 0x2ce4 calls pciio_pio_read8 with a0=0xffffffffbf380200, a1=0x8, a2=?, a3=?.
  The `jalr` at 0x2cfc calls pciio_pio_write8 with a0=?, a1=0xffffffffbf380200, a2=?, a3=?.
  The `jalr` at 0x2d04 calls pciio_pio_read8 with a0=0xffffffffbf380100, a1=?, a2=?, a3=?.
  The `jalr` at 0x2d24 calls pciio_pio_read8 with a0=0xffffffffbf380100, a1=?, a2=?, a3=?.
  The `jalr` at 0x2d50 calls delay with a0=0x1, a1=?, a2=?, a3=?, a4=sym(delay).
  The `jalr` at 0x2d60 calls pciio_pio_read8 with a0=0xffffffffbf380200, a1=?, a2=?, a3=?.
  The `jalr` at 0x2d7c calls pciio_pio_write8 with a0=?, a1=0xffffffffbf380200, a2=?, a3=?, a5=sym(pciio_pio_write8).
  The `beq` branch at 0x2ba4 targets 0x2be8, is taken when a1 == at(=0x10), and falls through when a1 != at(=0x10).
  The `beq` branch at 0x2bb0 targets 0x2bec, is taken when a0(=[a0+2]:1) == a3(=0x6), and falls through when a0(=[a0+2]:1) != a3(=0x6).
  The `beq` branch at 0x2bb8 targets 0x2c94, is taken when a1 == a4(=0x40), and falls through when a1 != a4(=0x40).
  The `beq` branch at 0x2bc0 targets 0x2c90, is taken when a0(=[a0+2]:1) == a5(=0x2), and falls through when a0(=[a0+2]:1) != a5(=0x2).
  The `beq` branch at 0x2c3c targets 0x2ce4, is taken when a1(=0x8) == t8(?), and falls through when a1(=0x8) != t8(?).
  The `beq` branch at 0x2c44 targets 0x2d8c and is always taken.
  The `beq` branch at 0x2c64 targets 0x2ce4, is taken when a1(=0x8) == t9(?), and falls through when a1(=0x8) != t9(?).
  The `beq` branch at 0x2c6c targets 0x2bc4, is taken when ra(?) == 0, and falls through when ra(?) != 0.
  The `bne` branch at 0x2c74 targets 0x2c4c, is taken when a0(?) != 0, and falls through when a0(?) == 0.
  The `beq` branch at 0x2c88 targets 0x2c50 and is always taken.
  The `beq` branch at 0x2cdc targets 0x2bc8 and is always taken.
  The `bne` branch at 0x2d10 targets 0x2d60, is taken when (v0(=ret(pciio_pio_read8)) & 0x40) != 0, and falls through when (v0(=ret(pciio_pio_read8)) & 0x40) == 0.
  The `beq` branch at 0x2d18 targets 0x2d98 and is always taken.
  The `bne` branch at 0x2d34 targets 0x2d60, is taken when (v0(=ret(pciio_pio_read8)) & 0x40) != 0, and falls through when (v0(=ret(pciio_pio_read8)) & 0x40) == 0.
  The `beq` branch at 0x2d3c targets 0x2bc4, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `bne` branch at 0x2d44 targets 0x2d20, is taken when a0(?) != 0, and falls through when a0(?) == 0.
  The `beq` branch at 0x2d58 targets 0x2d24 and is always taken.
  The `beq` branch at 0x2d84 targets 0x2bc8 and is always taken.
  The `beq` branch at 0x2d90 targets 0x2c6c and is always taken.
  The `beq` branch at 0x2d9c targets 0x2d3c and is always taken.
  The return at 0x2be0 has v0 = one of ?, ret(pciio_pio_write8).

- `plp_fwd2rvs` in `IP32/usr/cpu/sysgen/IP32boot/ecplp.o` at 0x2da4 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/ecplp.o`.
  Range: 0x2da4-0x2e78 (212 bytes).
  It occupies 212 bytes.
  The `lbu` at 0x2da4 loads 1 byte from a0 (arg0 at entry) +0x2.
  The `sb` at 0x2e74 stores 1 byte to a0 (arg0 at entry) +0x2.
  The `jalr` at 0x2dd4 calls pciio_pio_read8 with a0=0xffffffffbf380200, a1=sym(pciio_pio_read8), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x2df0 calls pciio_pio_write8 with a0=?, a1=0xffffffffbf380200, a2=sym(pciio_pio_write8), a3=?.
  The `jalr` at 0x2e00 calls us_delaybus with a0=0x1, a1=?, a2=?, a3=sym(us_delaybus).
  The `jalr` at 0x2e14 calls pciio_pio_read8 with a0=0xffffffffbf380200, a1=?, a2=?, a3=?, a4=sym(pciio_pio_read8).
  The `jalr` at 0x2e34 calls pciio_pio_write8 with a0=?, a1=0xffffffffbf380200, a2=sym(pciio_pio_write8), a3=?.
  The `jalr` at 0x2e48 calls pciio_pio_read8 with a0=0xffffffffbf380100, a1=sym(pciio_pio_read8), a2=?, a3=?.
  The `beq` branch at 0x2db4 targets 0x2dc8, is taken when at(=[a0+2]:1) == v0(=0x6), and falls through when at(=[a0+2]:1) != v0(=0x6).
  The `beq` branch at 0x2e58 targets 0x2e68, is taken when (v0(=ret(pciio_pio_read8)) & 0x20) == 0, and falls through when (v0(=ret(pciio_pio_read8)) & 0x20) != 0.
  The `beq` branch at 0x2e60 targets 0x2dc0 and is always taken.
  The `beq` branch at 0x2e70 targets 0x2dc0 and is always taken.
  The return at 0x2dc0 has v0 = one of 0x0, 0xa.

- `plp_rvs2fwd` in `IP32/usr/cpu/sysgen/IP32boot/ecplp.o` at 0x2e78 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/ecplp.o`.
  Range: 0x2e78-0x2f50 (216 bytes).
  It occupies 216 bytes.
  The `lbu` at 0x2e78 loads 1 byte from a0 (arg0 at entry) +0x2.
  The `sb` at 0x2f3c stores 1 byte to a0 (arg0 at entry) +0x2.
  The `jalr` at 0x2eb8 calls pciio_pio_read8 with a0=0xffffffffbf380200, a1=[a0+2]:1, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x2ed4 calls pciio_pio_write8 with a0=?, a1=0xffffffffbf380200, a2=sym(pciio_pio_write8), a3=?.
  The `jalr` at 0x2ee8 calls pciio_pio_read8 with a0=0xffffffffbf380100, a1=?, a2=?, a3=sym(pciio_pio_read8).
  The `jalr` at 0x2f04 calls us_delaybus with a0=0x1, a1=?, a2=sym(us_delaybus), a3=?.
  The `jalr` at 0x2f18 calls pciio_pio_read8 with a0=0xffffffffbf380100, a1=?, a2=?, a3=sym(pciio_pio_read8).
  The `beq` branch at 0x2e8c targets 0x2eac, is taken when a1(=[a0+2]:1) == at(=0xa), and falls through when a1(=[a0+2]:1) != at(=0xa).
  The `beq` branch at 0x2e94 targets 0x2eb0, is taken when a1(=[a0+2]:1) == v0(=0xb), and falls through when a1(=[a0+2]:1) != v0(=0xb).
  The `beq` branch at 0x2ef4 targets 0x2f40, is taken when (v0(=ret(pciio_pio_read8)) & 0x40) == 0, and falls through when (v0(=ret(pciio_pio_read8)) & 0x40) != 0.
  The `beq` branch at 0x2f2c targets 0x2f48, is taken when (v0(=ret(pciio_pio_read8)) & 0x20) == 0, and falls through when (v0(=ret(pciio_pio_read8)) & 0x20) != 0.
  The `beq` branch at 0x2f38 targets 0x2ea0 and is always taken.
  The `beq` branch at 0x2f40 targets 0x2ea4 and is always taken.
  The `beq` branch at 0x2f48 targets 0x2ea4 and is always taken.
  The return at 0x2ea4 has v0 = one of 0x0, 0x6.

- `plp_war_delay` in `IP32/usr/cpu/sysgen/IP32boot/ecplp.o` at 0x2f50 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/ecplp.o`.
  Range: 0x2f50-0x2fd0 (128 bytes).
  It occupies 128 bytes.
  The `lbu` at 0x2f64 loads 1 byte from a0 (arg0 at entry) +0x3.
  The `jalr` at 0x2f94 calls pciio_pio_read8 with a0=0xffffffffbf380100, a1=sym(pciio_pio_read8), a2=?, a3=?.
  The `jalr` at 0x2fac calls nano_delay with a0=sp-32, a1=?, a2=sym(nano_delay), a3=?.
  The `bne` branch at 0x2f78 targets 0x2fc0, is taken when at(=[a0+3]:1) != v0(=0x40), and falls through when at(=[a0+3]:1) == v0(=0x40).
  The `beq` branch at 0x2f84 targets 0x2fc0, is taken when s0(?) == a1(=-0x1), and falls through when s0(?) != a1(=-0x1).
  The `bne` branch at 0x2fa0 targets 0x2fc0, is taken when (v0(=ret(pciio_pio_read8)) & 0x80) != 0, and falls through when (v0(=ret(pciio_pio_read8)) & 0x80) == 0.
  The `beq` branch at 0x2fb8 targets 0x2f84 and is always taken.
  The return at 0x2fc8 has v0 = one of 0x40, ?, ret(pciio_pio_read8).

- `plpfdc_cpp` in `IP32/usr/cpu/sysgen/IP32boot/ecplp.o` at 0x2fd0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/ecplp.o`.
  Range: 0x2fd0-0x3294 (708 bytes).
  It occupies 708 bytes.
  The `jalr` at 0x3004 calls pciio_pio_write8 with a0=0xfe, a1=0xffffffffbf380000, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x3014 calls us_delaybus with a0=0x4, a1=?, a2=?, a3=?.
  The `jalr` at 0x3020 calls pciio_pio_write8 with a0=0xaa, a1=0xffffffffbf380000, a2=?, a3=?.
  The `jalr` at 0x3028 calls us_delaybus with a0=0x4, a1=?, a2=?, a3=?.
  The `jalr` at 0x3034 calls pciio_pio_write8 with a0=0x55, a1=0xffffffffbf380000, a2=?, a3=?.
  The `jalr` at 0x303c calls us_delaybus with a0=0x4, a1=?, a2=?, a3=?.
  The `jalr` at 0x3048 calls pciio_pio_write8 with a0=0x0, a1=0xffffffffbf380000, a2=?, a3=?.
  The `jalr` at 0x3050 calls us_delaybus with a0=0x4, a1=?, a2=?, a3=?.
  The `jalr` at 0x305c calls pciio_pio_write8 with a0=0xff, a1=0xffffffffbf380000, a2=?, a3=?.
  The `jalr` at 0x3064 calls us_delaybus with a0=0x4, a1=?, a2=?, a3=?.
  The `jalr` at 0x3084 calls pciio_pio_read8 with a0=0xffffffffbf380100, a1=sym(pciio_pio_read8), a2=?, a3=?.
  The `jalr` at 0x30d8 calls pciio_pio_write8 with a0=0x87, a1=0xffffffffbf380000, a2=?, a3=?.
  The `jalr` at 0x30e0 calls us_delaybus with a0=0x4, a1=?, a2=?, a3=?.
  The `jalr` at 0x30f4 calls pciio_pio_read8 with a0=0xffffffffbf380100, a1=?, a2=?, a3=?.
  The `jalr` at 0x311c calls pciio_pio_write8 with a0=0x78, a1=0xffffffffbf380000, a2=?, a3=?.
  The `jalr` at 0x3124 calls us_delaybus with a0=0x4, a1=?, a2=?, a3=?.
  The `jalr` at 0x314c calls pciio_pio_write8 with a0=0xff, a1=0xffffffffbf380000, a2=?, a3=?.
  The `jalr` at 0x3154 calls us_delaybus with a0=0x4, a1=?, a2=?, a3=?.
  The `jalr` at 0x316c calls pciio_pio_read8 with a0=0xffffffffbf380100, a1=?, a2=?, a3=?.
  The `jalr` at 0x3184 calls pciio_pio_write8 with a0=?, a1=0xffffffffbf380000, a2=?, a3=?.
  The `jalr` at 0x318c calls us_delaybus with a0=0x4, a1=?, a2=?, a3=?.
  The `jalr` at 0x319c calls pciio_pio_write8 with a0=0x5, a1=0xffffffffbf380200, a2=?, a3=?.
  The `jalr` at 0x31a4 calls us_delaybus with a0=0x4, a1=?, a2=?, a3=?.
  The `jalr` at 0x31b4 calls pciio_pio_write8 with a0=0x4, a1=0xffffffffbf380200, a2=?, a3=?.
  The `jalr` at 0x31bc calls us_delaybus with a0=0x4, a1=?, a2=?, a3=?.
  The `jalr` at 0x31fc calls pciio_pio_read8 with a0=0xffffffffbf380100, a1=?, a2=?, a3=0x20.
  The `jalr` at 0x3218 calls pciio_pio_read8 with a0=0xffffffffbf380100, a1=?, a2=?, a3=?.
  The `jalr` at 0x323c calls pciio_pio_write8 with a0=?, a1=0xffffffffbf380000, a2=?, a3=?.
  The `jalr` at 0x3244 calls us_delaybus with a0=0x4, a1=?, a2=?, a3=?.
  The `jalr` at 0x3254 calls pciio_pio_write8 with a0=0x5, a1=0xffffffffbf380200, a2=?, a3=?.
  The `jalr` at 0x325c calls us_delaybus with a0=0x4, a1=?, a2=?, a3=?.
  The `jalr` at 0x3264 calls pciio_pio_read8 with a0=0xffffffffbf380100, a1=?, a2=?, a3=?.
  The `jalr` at 0x327c calls pciio_pio_write8 with a0=0x4, a1=0xffffffffbf380200, a2=?, a3=?.
  The `jalr` at 0x3284 calls us_delaybus with a0=0x4, a1=?, a2=?, a3=?.
  The `beq` branch at 0x3070 targets 0x30cc, is taken when s3(=a0) == 0, and falls through when s3(=a0) != 0.
  The `beq` branch at 0x3094 targets 0x30c8, is taken when a2(?) == a3(=0xb0), and falls through when a2(?) != a3(=0xb0).
  The `beq` branch at 0x30e8 targets 0x311c, is taken when s3(=a0) == 0, and falls through when s3(=a0) != 0.
  The `beq` branch at 0x3104 targets 0x3114, is taken when a1(?) == a2(=0x58), and falls through when a1(?) != a2(=0x58).
  The `beq` branch at 0x310c targets 0x30a0 and is always taken.
  The `beq` branch at 0x312c targets 0x3164, is taken when s3(=a0) == 0, and falls through when s3(=a0) != 0.
  The `beq` branch at 0x3138 targets 0x31f8, is taken when s3(=a0) == a3(=0x20), and falls through when s3(=a0) != a3(=0x20).
  The `beq` branch at 0x3140 targets 0x31f4, is taken when s3(=a0) == v0(=0x30), and falls through when s3(=a0) != v0(=0x30).
  The `beq` branch at 0x315c targets 0x30a0 and is always taken.
  The `bne` branch at 0x31dc targets 0x3148, is taken when (a2(?) & 0x40) != 0, and falls through when (a2(?) & 0x40) == 0.
  The `bne` branch at 0x31e4 targets 0x3168, is taken when a5(?) != 0, and falls through when a5(?) == 0.
  The `beq` branch at 0x31ec targets 0x314c and is always taken.
  The `beq` branch at 0x3208 targets 0x3218, is taken when (v0(=ret(pciio_pio_read8)) & 0x8) == 0, and falls through when (v0(=ret(pciio_pio_read8)) & 0x8) != 0.
  The `beq` branch at 0x3210 targets 0x30a0 and is always taken.
  The `beq` branch at 0x3228 targets 0x3238, is taken when t9(?) == ra(=0xb0), and falls through when t9(?) != ra(=0xb0).
  The `beq` branch at 0x3230 targets 0x30a0 and is always taken.
  The `beq` branch at 0x328c targets 0x314c and is always taken.
  The return at 0x30c0 has v0 = one of 0x0, ?, 0x2.

- `plpfdc_open` in `IP32/usr/cpu/sysgen/IP32boot/ecplp.o` at 0x3294 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/ecplp.o`.
  Range: 0x3294-0x351c (648 bytes).
  It occupies 648 bytes.
  The `lw` at 0x32a0 loads 4 bytes from sym(plpinfo) +0x0.
  2 such `lbu` accesses load 1 byte from [sym(plpinfo)] +0x0, including `lbu` at 0x32ac, `lbu` at 0x34b0.
  The `sb` at 0x32cc stores 1 byte to [sym(plpinfo)] +0x1.
  2 such `lbu` accesses load 1 byte from [sym(plpinfo)] +0x3, including `lbu` at 0x32f0, `lbu` at 0x32f4.
  The `sb` at 0x3300 stores 1 byte to [sym(plpinfo)] +0x4.
  3 such `sb` accesses store 1 byte to [sym(plpinfo)] +0x3, including `sb` at 0x3354, `sb` at 0x3488, `sb` at 0x34fc.
  The `sb` at 0x34a8 stores 1 byte to [sym(plpinfo)] +0x1c.
  The `sw` at 0x34ac stores 4 bytes to [sym(plpinfo)] +0x84.
  The `sb` at 0x34b8 stores 1 byte to [sym(plpinfo)] +0x2.
  2 such `sb` accesses store 1 byte to [sym(plpinfo)] +0x0, including `sb` at 0x34c8, `sb` at 0x34f0.
  The `lbu` at 0x34e8 loads 1 byte from [sym(plpinfo)] +0x4.
  The `lbu` at 0x34ec loads 1 byte from [sym(plpinfo)] +0x1.
  The `jalr` at 0x32c8 calls plp_prlock with a0=[sym(plpinfo)], a1=0x80, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x3324 calls pciio_pio_read8 with a0=0xffffffffbf388200, a1=sym(pciio_pio_read8), a2=?, a3=?.
  The `jalr` at 0x3340 calls pciio_pio_write8 with a0=?, a1=0xffffffffbf388200, a2=?, a3=?.
  The `jalr` at 0x3358 calls plpfdc_cpp with a0=0x0, a1=0x0, a2=sym(plpfdc_cpp), a3=?.
  The `jalr` at 0x336c calls plpfdc_cpp with a0=0x20, a1=0x0, a2=?, a3=sym(plpfdc_cpp).
  The `jalr` at 0x3380 calls pciio_pio_write8 with a0=0x2, a1=0xffffffffbf380000, a2=?, a3=?.
  The `jalr` at 0x3394 calls us_delaybus with a0=0x4, a1=?, a2=?, a3=?.
  The `jalr` at 0x33a8 calls pciio_pio_write8 with a0=0x5, a1=0xffffffffbf380200, a2=?, a3=?.
  The `jalr` at 0x33b0 calls us_delaybus with a0=0x4, a1=?, a2=?, a3=?.
  The `jalr` at 0x33bc calls pciio_pio_write8 with a0=0xd, a1=0xffffffffbf380200, a2=?, a3=?.
  The `jalr` at 0x33c4 calls us_delaybus with a0=0x4, a1=?, a2=?, a3=?.
  The `jalr` at 0x33d0 calls pciio_pio_write8 with a0=0x5, a1=0xffffffffbf380200, a2=?, a3=?.
  The `jalr` at 0x33d8 calls us_delaybus with a0=0x4, a1=?, a2=?, a3=?.
  The `jalr` at 0x33e4 calls pciio_pio_write8 with a0=0x4, a1=0xffffffffbf380200, a2=?, a3=?.
  The `jalr` at 0x33f0 calls pciio_pio_write8 with a0=0x5, a1=0xffffffffbf380000, a2=?, a3=?.
  The `jalr` at 0x33f8 calls us_delaybus with a0=0x4, a1=?, a2=?, a3=?.
  The `jalr` at 0x3404 calls pciio_pio_write8 with a0=0x5, a1=0xffffffffbf380200, a2=?, a3=?.
  The `jalr` at 0x340c calls us_delaybus with a0=0x4, a1=?, a2=?, a3=?.
  The `jalr` at 0x3418 calls pciio_pio_write8 with a0=0x7, a1=0xffffffffbf380200, a2=?, a3=?.
  The `jalr` at 0x3420 calls us_delaybus with a0=0x4, a1=?, a2=?, a3=?.
  The `jalr` at 0x342c calls pciio_pio_write8 with a0=0x5, a1=0xffffffffbf380200, a2=?, a3=?.
  The `jalr` at 0x3434 calls us_delaybus with a0=0x4, a1=?, a2=?, a3=?.
  The `jalr` at 0x3444 calls pciio_pio_write8 with a0=0x4, a1=0xffffffffbf380200, a2=?, a3=?.
  The `jalr` at 0x3458 calls pciio_pio_read8 with a0=0xffffffffbf388200, a1=?, a2=?, a3=?.
  The `jalr` at 0x3470 calls pciio_pio_write8 with a0=?, a1=0xffffffffbf388200, a2=?, a3=?.
  The `jalr` at 0x348c calls pciio_pio_write8 with a0=0x3, a1=0xffffffffbf380300, a2=0x80, a3=?.
  The `jalr` at 0x349c calls pciio_pio_write8 with a0=0x0, a1=0xffffffffbf380400, a2=?, a3=?.
  The `jalr` at 0x34e0 calls plp_prunlock with a0=[sym(plpinfo)], a1=0x80, a2=?, a3=?, a4=sym(plp_prunlock).
  The `jalr` at 0x350c calls plp_phase_reset with a0=[sym(plpinfo)], a1=0x0, a2=?, a3=?, a7=sym(plp_phase_reset).
  The `beq` branch at 0x32a4 targets 0x32e8, is taken when s1(=[sym(plpinfo)]) == 0, and falls through when s1(=[sym(plpinfo)]) != 0.
  The `beq` branch at 0x32b4 targets 0x32e8, is taken when (v0(=[[sym(plpinfo)]]:1) & 0x1) == 0, and falls through when (v0(=[[sym(plpinfo)]]:1) & 0x1) != 0.
  The `beq` branch at 0x32d0 targets 0x32f0, is taken when v0(=ret(plp_prlock)) == 0, and falls through when v0(=ret(plp_prlock)) != 0.
  The `beq` branch at 0x32e8 targets 0x32d8 and is always taken.
  The `beq` branch at 0x32fc targets 0x3500, is taken when v0(=[[sym(plpinfo)]+3]:1) == at(=0x60), and falls through when v0(=[[sym(plpinfo)]+3]:1) != at(=0x60).
  The `beq` branch at 0x3308 targets 0x3500, is taken when v0(=[[sym(plpinfo)]+3]:1) == v1(=0x80), and falls through when v0(=[[sym(plpinfo)]+3]:1) != v1(=0x80).
  The `beq` branch at 0x3374 targets 0x34cc, is taken when v0(=ret(plpfdc_cpp)) == 0, and falls through when v0(=ret(plpfdc_cpp)) != 0.
  The `beq` branch at 0x34c4 targets 0x32d8 and is always taken.
  The `beq` branch at 0x34f8 targets 0x32d8 and is always taken.
  The `beq` branch at 0x3514 targets 0x3310 and is always taken.
  The return at 0x32e0 has v0 = one of 0x0, 0x6, 0x10.

- `plpfdc_close` in `IP32/usr/cpu/sysgen/IP32boot/ecplp.o` at 0x351c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/ecplp.o`.
  Range: 0x351c-0x36b4 (408 bytes).
  It occupies 408 bytes.
  The `lw` at 0x3540 loads 4 bytes from sym(plpinfo) +0x0.
  The `lbu` at 0x3590 loads 1 byte from [sym(plpinfo)] +0x4.
  2 such `sb` accesses store 1 byte to [sym(plpinfo)] +0x3, including `sb` at 0x35a8, `sb` at 0x36a0.
  2 such `lbu` accesses load 1 byte from [sym(plpinfo)] +0x3, including `lbu` at 0x35c8, `lbu` at 0x3654.
  The `lbu` at 0x3600 loads 1 byte from [sym(plpinfo)] +0x1.
  The `sb` at 0x360c stores 1 byte to [sym(plpinfo)] +0x0.
  The `lw` at 0x3664 loads 4 bytes from [sym(plpinfo)] +0x8.
  The `jalr` at 0x353c calls plpfdc_cpp with a0=0x30, a1=0x0, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x3554 calls plp_phase_reset with a0=[sym(plpinfo)], a1=0x0, a2=?, a3=?.
  The `jalr` at 0x356c calls pciio_pio_read8 with a0=0xffffffffbf388200, a1=?, a2=?, a3=?.
  The `jalr` at 0x3588 calls pciio_pio_write8 with a0=?, a1=0xffffffffbf388200, a2=?, a3=?.
  The `jalr` at 0x35c0 calls pciio_pio_read8 with a0=0xffffffffbf388200, a1=?, a2=?, a3=?, a4=sym(pciio_pio_read8).
  The `jalr` at 0x35e4 calls pciio_pio_write8 with a0=?, a1=0xffffffffbf388200, a2=?, a3=?, a5=sym(pciio_pio_write8).
  The `jalr` at 0x35f8 calls plp_prunlock with a0=[sym(plpinfo)], a1=0x80, a2=sym(plp_prunlock), a3=?.
  The `jalr` at 0x3640 calls plp_negotiate with a0=[sym(plpinfo)], a1=?, a2=one of 0x10, 0x40, a3=0xff, a5=sym(plp_negotiate).
  The `jalr` at 0x3660 calls plpclose with a0=[[sym(plpinfo)]+8], a1=?, a2=?, a3=[[sym(plpinfo)]+1]:1, a6=sym(plpclose).
  The `jalr` at 0x3690 calls cmn_err with a0=0x4, a1=sym(.rodata), a2=sym(.rodata), a3=?, a4=sym(.rodata), a5=sym(cmn_err), a7=0x60.
  The `beq` branch at 0x35a4 targets 0x35ec, is taken when a0(=[[sym(plpinfo)]+4]:1) == a3(=0xff), and falls through when a0(=[[sym(plpinfo)]+4]:1) != a3(=0xff).
  The `beq` branch at 0x35ac targets 0x3628, is taken when a4(=0x60) == a0(=[[sym(plpinfo)]+4]:1), and falls through when a4(=0x60) != a0(=[[sym(plpinfo)]+4]:1).
  The `beq` branch at 0x35b4 targets 0x3630, is taken when a0(=[[sym(plpinfo)]+4]:1) == a1(=0x80), and falls through when a0(=[[sym(plpinfo)]+4]:1) != a1(=0x80).
  The `beq` branch at 0x3608 targets 0x3658, is taken when (a3(=[[sym(plpinfo)]+1]:1) & 0x60) == 0, and falls through when (a3(=[[sym(plpinfo)]+1]:1) & 0x60) != 0.
  The `beq` branch at 0x3628 targets 0x3638 and is always taken.
  The `bne` branch at 0x3648 targets 0x35bc, is taken when v0(=ret(plp_negotiate)) != 0, and falls through when v0(=ret(plp_negotiate)) == 0.
  The `beq` branch at 0x3650 targets 0x3670 and is always taken.
  The `beq` branch at 0x3668 targets 0x3614 and is always taken.
  The `beq` branch at 0x3674 targets 0x36a4, is taken when a7(=0x60) == t0(=[[sym(plpinfo)]+3]:1), and falls through when a7(=0x60) != t0(=[[sym(plpinfo)]+3]:1).
  The `beq` branch at 0x369c targets 0x35b8 and is always taken.
  The `beq` branch at 0x36ac targets 0x3684 and is always taken.
  The return at 0x3620 has v0 = 0x0.

- `plpfdc_fifo_ctrl` in `IP32/usr/cpu/sysgen/IP32boot/ecplp.o` at 0x36b4 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/ecplp.o`.
  Range: 0x36b4-0x3a34 (896 bytes).
  It occupies 896 bytes.
  The `jalr` at 0x3750 calls pciio_pio_write8 with a0=0x3, a1=0xffffffffbf380300, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x3768 calls pciio_pio_write8 with a0=?, a1=0xffffffffbf380400, a2=?, a3=?.
  The `jalr` at 0x37a0 calls pciio_pio_write8 with a0=0x8, a1=0xffffffffbf380300, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x37ac calls pciio_pio_write8 with a0=0x9, a1=0xffffffffbf380300, a2=?, a3=?.
  The `jalr` at 0x37b8 calls pciio_pio_write8 with a0=0xa, a1=0xffffffffbf380300, a2=?, a3=?.
  The `jalr` at 0x37d0 calls pciio_pio_read8 with a0=0xffffffffbf380400, a1=?, a2=?, a3=?.
  The `jalr` at 0x37dc calls pciio_pio_read8 with a0=0xffffffffbf380400, a1=?, a2=?, a3=?.
  The `jalr` at 0x37e8 calls pciio_pio_read8 with a0=0xffffffffbf380400, a1=?, a2=?, a3=?.
  The `jalr` at 0x3804 calls pciio_pio_write8 with a0=0x8, a1=0xffffffffbf380300, a2=?, a3=?.
  The `jalr` at 0x3810 calls pciio_pio_write8 with a0=0x9, a1=0xffffffffbf380300, a2=?, a3=?.
  The `jalr` at 0x381c calls pciio_pio_write8 with a0=0xa, a1=0xffffffffbf380300, a2=?, a3=?.
  The `jalr` at 0x3824 calls pciio_pio_read8 with a0=0xffffffffbf380400, a1=?, a2=?, a3=?.
  The `jalr` at 0x3830 calls pciio_pio_read8 with a0=0xffffffffbf380400, a1=?, a2=?, a3=?.
  The `jalr` at 0x383c calls pciio_pio_read8 with a0=0xffffffffbf380400, a1=?, a2=?, a3=?.
  The `jalr` at 0x3874 calls delay with a0=0x1, a1=?, a2=?, a3=?.
  The `jalr` at 0x3880 calls pciio_pio_write8 with a0=0x8, a1=0xffffffffbf380300, a2=?, a3=?.
  The `jalr` at 0x388c calls pciio_pio_write8 with a0=0x9, a1=0xffffffffbf380300, a2=?, a3=?.
  The `jalr` at 0x3898 calls pciio_pio_write8 with a0=0xa, a1=0xffffffffbf380300, a2=?, a3=?.
  The `jalr` at 0x38a0 calls pciio_pio_read8 with a0=0xffffffffbf380400, a1=?, a2=?, a3=?.
  The `jalr` at 0x38ac calls pciio_pio_read8 with a0=0xffffffffbf380400, a1=?, a2=?, a3=?.
  The `jalr` at 0x38b8 calls pciio_pio_read8 with a0=0xffffffffbf380400, a1=?, a2=?, a3=?.
  The `jalr` at 0x38e0 calls pciio_pio_write8 with a0=0x8, a1=0xffffffffbf380300, a2=?, a3=?.
  The `jalr` at 0x38f0 calls pciio_pio_write8 with a0=0x9, a1=0xffffffffbf380300, a2=?, a3=?.
  The `jalr` at 0x38fc calls pciio_pio_write8 with a0=0xa, a1=0xffffffffbf380300, a2=?, a3=?.
  The `jalr` at 0x3904 calls pciio_pio_read8 with a0=0xffffffffbf380400, a1=?, a2=?, a3=?.
  The `jalr` at 0x3910 calls pciio_pio_read8 with a0=0xffffffffbf380400, a1=?, a2=?, a3=?.
  The `jalr` at 0x391c calls pciio_pio_read8 with a0=0xffffffffbf380400, a1=?, a2=?, a3=?.
  The `jalr` at 0x395c calls pciio_pio_write8 with a0=0x3, a1=0xffffffffbf380300, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x396c calls pciio_pio_write8 with a0=0x0, a1=0xffffffffbf380400, a2=?, a3=?.
  The `jalr` at 0x39a8 calls nano_delay with a0=sp-112, a1=?, a2=?, a3=?.
  The `jalr` at 0x39b4 calls pciio_pio_write8 with a0=0x8, a1=0xffffffffbf380300, a2=?, a3=?.
  The `jalr` at 0x39c0 calls pciio_pio_write8 with a0=0x9, a1=0xffffffffbf380300, a2=?, a3=?.
  The `jalr` at 0x39cc calls pciio_pio_write8 with a0=0xa, a1=0xffffffffbf380300, a2=?, a3=?.
  The `jalr` at 0x39d4 calls pciio_pio_read8 with a0=0xffffffffbf380400, a1=?, a2=?, a3=?.
  The `jalr` at 0x39e0 calls pciio_pio_read8 with a0=0xffffffffbf380400, a1=?, a2=?, a3=?.
  The `jalr` at 0x39ec calls pciio_pio_read8 with a0=0xffffffffbf380400, a1=?, a2=?, a3=?.
  The `beq` branch at 0x36e8 targets 0x3778, is taken when a0 == at(=0x4), and falls through when a0 != at(=0x4).
  The `beq` branch at 0x36f4 targets 0x3738, is taken when a0 == v0(=0x2), and falls through when a0 != v0(=0x2).
  The `beq` branch at 0x36fc targets 0x394c, is taken when a0 == v1(=0x1), and falls through when a0 != v1(=0x1).
  The `beq` branch at 0x3738 targets 0x397c, is taken when a1 == 0, and falls through when a1 != 0.
  The `beq` branch at 0x3770 targets 0x3708 and is always taken.
  The `bne` branch at 0x3854 targets 0x38e0, is taken when s4(=((ret(pciio_pio_read8) | (ret(pciio_pio_read8) << 0x8)) | (ret(pciio_pio_read8) << 0x10))) != t8(=((ret(pciio_pio_read8) | (ret(pciio_pio_read8) << 0x8)) | (ret(pciio_pio_read8) << 0x10))), and falls through when s4(=((ret(pciio_pio_read8) | (ret(pciio_pio_read8) << 0x8)) | (ret(pciio_pio_read8) << 0x10))) == t8(=((ret(pciio_pio_read8) | (ret(pciio_pio_read8) << 0x8)) | (ret(pciio_pio_read8) << 0x10))).
  The `beq` branch at 0x3868 targets 0x3a2c, is taken when s5(?) == s7(=-0x1), and falls through when s5(?) != s7(=-0x1).
  The `beq` branch at 0x38d4 targets 0x3868, is taken when s4(=((ret(pciio_pio_read8) | (ret(pciio_pio_read8) << 0x8)) | (ret(pciio_pio_read8) << 0x10))) == t8(=((ret(pciio_pio_read8) | (ret(pciio_pio_read8) << 0x8)) | (ret(pciio_pio_read8) << 0x10))), and falls through when s4(=((ret(pciio_pio_read8) | (ret(pciio_pio_read8) << 0x8)) | (ret(pciio_pio_read8) << 0x10))) != t8(=((ret(pciio_pio_read8) | (ret(pciio_pio_read8) << 0x8)) | (ret(pciio_pio_read8) << 0x10))).
  The `beq` branch at 0x3930 targets 0x3988, is taken when s8(=a1) == 0, and falls through when s8(=a1) != 0.
  The `bne` branch at 0x393c targets 0x3990, is taken when s4(=((ret(pciio_pio_read8) | (ret(pciio_pio_read8) << 0x8)) | (ret(pciio_pio_read8) << 0x10))) < s6(=a2) (signed), and falls through when s4(=((ret(pciio_pio_read8) | (ret(pciio_pio_read8) << 0x8)) | (ret(pciio_pio_read8) << 0x10))) >= s6(=a2) (signed).
  The `beq` branch at 0x3944 targets 0x3708 and is always taken.
  The `beq` branch at 0x3974 targets 0x3704 and is always taken.
  The `beq` branch at 0x3980 targets 0x3740 and is always taken.
  The `beq` branch at 0x3988 targets 0x3944, is taken when s4(=((ret(pciio_pio_read8) | (ret(pciio_pio_read8) << 0x8)) | (ret(pciio_pio_read8) << 0x10))) == 0, and falls through when s4(=((ret(pciio_pio_read8) | (ret(pciio_pio_read8) << 0x8)) | (ret(pciio_pio_read8) << 0x10))) != 0.
  The `beq` branch at 0x3990 targets 0x39a0 and is always taken.
  The `beq` branch at 0x3998 targets 0x3944, is taken when s4(?) == 0, and falls through when s4(?) != 0.
  The `beq` branch at 0x3a0c targets 0x3944, is taken when s5(?) == t9(=-0x1), and falls through when s5(?) != t9(=-0x1).
  The `beq` branch at 0x3a14 targets 0x3998, is taken when s8(=a1) == 0, and falls through when s8(=a1) != 0.
  The `bne` branch at 0x3a1c targets 0x39a0, is taken when t8(?) != 0, and falls through when t8(?) == 0.
  The `beq` branch at 0x3a24 targets 0x3944 and is always taken.
  The `beq` branch at 0x3a2c targets 0x3708 and is always taken.
  The return at 0x3730 has v0 = one of 0x0, ?, ((ret(pciio_pio_read8) | (ret(pciio_pio_read8) << 0x8)) | (ret(pciio_pio_read8) << 0x10)).

- `plpfdc_read` in `IP32/usr/cpu/sysgen/IP32boot/ecplp.o` at 0x3a34 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/ecplp.o`.
  Range: 0x3a34-0x3ddc (936 bytes).
  It occupies 936 bytes.
  The `lw` at 0x3a90 loads 4 bytes from sym(plpinfo) +0x0.
  The `sd` at 0x3ad8 stores 8 bytes to [sym(plpinfo)] +0x60.
  4 such `sw` accesses store 4 bytes to [sym(plpinfo)] +0x88, including `sw` at 0x3ae0, `sw` at 0x3b74, `sw` at 0x3c2c.
  2 such `sw` accesses store 4 bytes to [sym(plpinfo)] +0xb0, including `sw` at 0x3ae8, `sw` at 0x3c38.
  The `sw` at 0x3af0 stores 4 bytes to [sym(plpinfo)] +0x9c.
  3 such `lw` accesses load 4 bytes from [sym(plpinfo)] +0x88, including `lw` at 0x3afc, `lw` at 0x3bd8, `lw` at 0x3c80.
  2 such `sw` accesses store 4 bytes to a3 (arg3 at entry) +0x0, including `sw` at 0x3b10, `sw` at 0x3b7c.
  10 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x3ba8, `lbu` at 0x3bac, `lbu` at 0x3c98.
  2 such `lw` accesses load 4 bytes from [sym(plpinfo)] +0x30, including `lw` at 0x3bd4, `lw` at 0x3c6c.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0x3c28, `lw` at 0x3c44.
  2 such `lw` accesses load 4 bytes from [sym(plpinfo)] +0x9c, including `lw` at 0x3c3c, `lw` at 0x3c8c.
  The `lw` at 0x3c94 loads 4 bytes from [sym(plpinfo)] +0x34.
  The `sb` at 0x3da4 stores 1 byte to a1 (arg1 at entry) +0x0.
  The `jalr` at 0x3a8c calls plpfdc_fifo_ctrl with a0=0x4, a1=0x1, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x3ab8 calls pciio_pio_write8 with a0=0x6, a1=0xffffffffbf380300, a2=?, a3=?.
  The `jalr` at 0x3ad4 calls min with a0=a2 at entry (arg2), a1=ret(plpfdc_fifo_ctrl), a2=?, a3=?.
  The `jalr` at 0x3af4 calls plp_io with a0=[sym(plpinfo)]+88, a1=?, a2=?, a3=?.
  The `jalr` at 0x3b58 calls pciio_pio_write8 with a0=0x1, a1=0xffffffffbf380300, a2=?, a3=?.
  The `jalr` at 0x3b68 calls pciio_pio_write8 with a0=0x0, a1=0xffffffffbf380400, a2=?, a3=?.
  The `jalr` at 0x3be8 calls pciio_pio_write8 with a0=0x3, a1=0xffffffffbf380300, a2=?, a3=?.
  The `jalr` at 0x3bf4 calls pciio_pio_write8 with a0=0x0, a1=0xffffffffbf380400, a2=?, a3=?.
  The `jalr` at 0x3c00 calls pciio_pio_write8 with a0=0x3, a1=0xffffffffbf380300, a2=?, a3=?.
  The `jalr` at 0x3c0c calls pciio_pio_write8 with a0=0x1a, a1=0xffffffffbf380400, a2=?, a3=?.
  The `jalr` at 0x3c20 calls pciio_pio_write8 with a0=0x6, a1=0xffffffffbf380300, a2=?, a3=?.
  The `jalr` at 0x3c34 calls plp_io with a0=[sym(plpinfo)]+88, a1=?, a2=?, a3=?.
  The `jalr` at 0x3c70 calls bcopy with a0=[[sym(plpinfo)]+48], a1=a1 at entry (arg1), a2=[[sym(plpinfo)]+156], a3=?.
  The `jalr` at 0x3d4c calls pciio_pio_write8 with a0=0x3, a1=0xffffffffbf380300, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x3d64 calls pciio_pio_write8 with a0=?, a1=0xffffffffbf380400, a2=?, a3=?.
  The `jalr` at 0x3d70 calls pciio_pio_write8 with a0=0x1, a1=0xffffffffbf380300, a2=?, a3=?.
  The `jalr` at 0x3d7c calls pciio_pio_write8 with a0=a0 at entry (arg0), a1=0xffffffffbf380400, a2=?, a3=?.
  The `jalr` at 0x3d88 calls pciio_pio_write8 with a0=0x0, a1=0xffffffffbf380300, a2=?, a3=?.
  The `jalr` at 0x3d98 calls pciio_pio_read8 with a0=0xffffffffbf380400, a1=?, a2=?, a3=?.
  The `jalr` at 0x3da8 calls pciio_pio_write8 with a0=0x1, a1=0xffffffffbf380300, a2=?, a3=?.
  The `jalr` at 0x3db4 calls pciio_pio_write8 with a0=0x2, a1=0xffffffffbf380400, a2=?, a3=?.
  The `jalr` at 0x3dc0 calls pciio_pio_write8 with a0=0x3, a1=0xffffffffbf380300, a2=?, a3=?.
  The `jalr` at 0x3dcc calls pciio_pio_write8 with a0=a5 at entry (arg5), a1=0xffffffffbf380400, a2=?, a3=?.
  The `beq` branch at 0x3a70 targets 0x3d38, is taken when a4 == 0, and falls through when a4 != 0.
  The `bne` branch at 0x3a98 targets 0x3b48, is taken when v0(=ret(plpfdc_fifo_ctrl)) < s1(=a2) (signed), and falls through when v0(=ret(plpfdc_fifo_ctrl)) >= s1(=a2) (signed).
  The `beq` branch at 0x3aa4 targets 0x3b14, is taken when s6(=ret(plpfdc_fifo_ctrl)) == 0, and falls through when s6(=ret(plpfdc_fifo_ctrl)) != 0.
  The `beq` branch at 0x3b04 targets 0x3b80, is taken when v0(=[[sym(plpinfo)]+136]) == 0, and falls through when v0(=[[sym(plpinfo)]+136]) != 0.
  The `beq` branch at 0x3b78 targets 0x3aa0 and is always taken.
  The `beq` branch at 0x3b94 targets 0x3be4 and is always taken.
  The `beq` branch at 0x3ba0 targets 0x3c50, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `beq` branch at 0x3bb4 targets 0x3b9c, is taken when t8(?) == t9(?), and falls through when t8(?) != t9(?).
  The `blez` branch at 0x3bbc targets 0x3c50, is taken when s1(?) <= 0 (signed), and falls through when s1(?) > 0 (signed).
  The `beq` branch at 0x3bd0 targets 0x3c80, is taken when a0(?) >= 0x2 (signed), and falls through when a0(?) < 0x2 (signed).
  The `bne` branch at 0x3bdc targets 0x3c84, is taken when v0(=[[sym(plpinfo)]+136]) != 0, and falls through when v0(=[[sym(plpinfo)]+136]) == 0.
  The `beq` branch at 0x3c48 targets 0x3ba0 and is always taken.
  The `bne` branch at 0x3c5c targets 0x3bc4, is taken when a0(?) < 0x2 (signed), and falls through when a0(?) >= 0x2 (signed).
  The `beq` branch at 0x3c78 targets 0x3bc4 and is always taken.
  The `blez` branch at 0x3c84 targets 0x3d0c, is taken when s1(?) <= 0 (signed), and falls through when s1(?) > 0 (signed).
  The `beq` branch at 0x3c90 targets 0x3d0c, is taken when s1(=[[sym(plpinfo)]+156]) == 0, and falls through when s1(=[[sym(plpinfo)]+156]) != 0.
  The `bne` branch at 0x3ca0 targets 0x3d0c, is taken when v1(?) != a0(?), and falls through when v1(?) == a0(?).
  The `beq` branch at 0x3cac targets 0x3d0c, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `bne` branch at 0x3cbc targets 0x3d0c, is taken when a1(?) != a2(?), and falls through when a1(?) == a2(?).
  The `beq` branch at 0x3cc8 targets 0x3d0c, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `bne` branch at 0x3cd8 targets 0x3d0c, is taken when a3(?) != a4(?), and falls through when a3(?) == a4(?).
  The `beq` branch at 0x3ce4 targets 0x3d0c, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `bne` branch at 0x3cf8 targets 0x3d0c, is taken when a6(?) != a7(?), and falls through when a6(?) == a7(?).
  The `bne` branch at 0x3d04 targets 0x3c98, is taken when s1(?) != 0, and falls through when s1(?) == 0.
  The `bne` branch at 0x3d0c targets 0x3b10, is taken when v0(=[[sym(plpinfo)]+136]) != 0, and falls through when v0(=[[sym(plpinfo)]+136]) == 0.
  The `bne` branch at 0x3d18 targets 0x3d2c, is taken when t0(?) != 0, and falls through when t0(?) == 0.
  The `blez` branch at 0x3d20 targets 0x3b10, is taken when s1(?) <= 0 (signed), and falls through when s1(?) > 0 (signed).
  The `beq` branch at 0x3d30 targets 0x3b0c and is always taken.
  The `beq` branch at 0x3dd4 targets 0x3b14 and is always taken.
  The return at 0x3b40 has v0 = one of ret(plpfdc_fifo_ctrl), 0x1.

- `plpfdc_write` in `IP32/usr/cpu/sysgen/IP32boot/ecplp.o` at 0x3ddc (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/ecplp.o`.
  Range: 0x3ddc-0x3f14 (312 bytes).
  It occupies 312 bytes.
  The `lw` at 0x3e2c loads 4 bytes from sym(plpinfo) +0x0.
  The `sw` at 0x3e30 stores 4 bytes to [sym(plpinfo)] +0x88.
  The `sw` at 0x3e38 stores 4 bytes to [sym(plpinfo)] +0xb0.
  The `sw` at 0x3e40 stores 4 bytes to [sym(plpinfo)] +0x9c.
  The `sd` at 0x3e4c stores 8 bytes to [sym(plpinfo)] +0x60.
  The `lw` at 0x3e54 loads 4 bytes from [sym(plpinfo)] +0x88.
  The `sw` at 0x3e58 stores 4 bytes to a3 (arg3 at entry) +0x0.
  The `lbu` at 0x3ed0 loads 1 byte from a1 (arg1 at entry) +0x0.
  The `jalr` at 0x3e28 calls pciio_pio_write8 with a0=0x6, a1=0xffffffffbf380300, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x3e48 calls plp_io with a0=[sym(plpinfo)]+88, a1=?, a2=?, a3=?.
  The `jalr` at 0x3e88 calls pciio_pio_write8 with a0=0x3, a1=0xffffffffbf380300, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x3ea4 calls pciio_pio_write8 with a0=?, a1=0xffffffffbf380400, a2=?, a3=?.
  The `jalr` at 0x3eb0 calls pciio_pio_write8 with a0=0x1, a1=0xffffffffbf380300, a2=?, a3=?.
  The `jalr` at 0x3ebc calls pciio_pio_write8 with a0=a0 at entry (arg0), a1=0xffffffffbf380400, a2=?, a3=?.
  The `jalr` at 0x3ec8 calls pciio_pio_write8 with a0=0x0, a1=0xffffffffbf380300, a2=?, a3=?.
  The `jalr` at 0x3ed4 calls pciio_pio_write8 with a0=[a1]:1, a1=0xffffffffbf380400, a2=?, a3=?.
  The `jalr` at 0x3ee0 calls pciio_pio_write8 with a0=0x1, a1=0xffffffffbf380300, a2=?, a3=?.
  The `jalr` at 0x3eec calls pciio_pio_write8 with a0=0x2, a1=0xffffffffbf380400, a2=?, a3=?.
  The `jalr` at 0x3ef8 calls pciio_pio_write8 with a0=0x3, a1=0xffffffffbf380300, a2=?, a3=?.
  The `jalr` at 0x3f04 calls pciio_pio_write8 with a0=a5 at entry (arg5), a1=0xffffffffbf380400, a2=?, a3=?.
  The `beq` branch at 0x3e0c targets 0x3e7c, is taken when a4 == 0, and falls through when a4 != 0.
  The `beq` branch at 0x3f0c targets 0x3e5c and is always taken.
  The return at 0x3e74 has v0 = one of a2, 0x1.

- `plpfdc_chkirq` in `IP32/usr/cpu/sysgen/IP32boot/ecplp.o` at 0x3f14 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/ecplp.o`.
  Range: 0x3f14-0x40e8 (468 bytes).
  It occupies 468 bytes.
  The `jalr` at 0x3f3c calls pciio_pio_read8 with a0=0xffffffffbf388200, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x3f5c calls pciio_pio_write8 with a0=?, a1=0xffffffffbf388200, a2=?, a3=?.
  The `jalr` at 0x3f70 calls pciio_pio_write8 with a0=0x2, a1=0xffffffffbf380000, a2=?, a3=?.
  The `jalr` at 0x3f84 calls us_delaybus with a0=0x4, a1=?, a2=?, a3=?.
  The `jalr` at 0x3f98 calls pciio_pio_write8 with a0=0x5, a1=0xffffffffbf380200, a2=?, a3=?.
  The `jalr` at 0x3fa0 calls us_delaybus with a0=0x4, a1=?, a2=?, a3=?.
  The `jalr` at 0x3fac calls pciio_pio_write8 with a0=0xd, a1=0xffffffffbf380200, a2=?, a3=?.
  The `jalr` at 0x3fb4 calls us_delaybus with a0=0x4, a1=?, a2=?, a3=?.
  The `jalr` at 0x3fc0 calls pciio_pio_write8 with a0=0x5, a1=0xffffffffbf380200, a2=?, a3=?.
  The `jalr` at 0x3fc8 calls us_delaybus with a0=0x4, a1=?, a2=?, a3=?.
  The `jalr` at 0x3fd4 calls pciio_pio_write8 with a0=0x4, a1=0xffffffffbf380200, a2=?, a3=?.
  The `jalr` at 0x3fe0 calls pciio_pio_write8 with a0=0x4, a1=0xffffffffbf380000, a2=?, a3=?.
  The `jalr` at 0x3fe8 calls us_delaybus with a0=0x4, a1=?, a2=?, a3=?.
  The `jalr` at 0x3ff4 calls pciio_pio_write8 with a0=0x5, a1=0xffffffffbf380200, a2=?, a3=?.
  The `jalr` at 0x3ffc calls us_delaybus with a0=0x4, a1=?, a2=?, a3=?.
  The `jalr` at 0x4008 calls pciio_pio_write8 with a0=0x7, a1=0xffffffffbf380200, a2=?, a3=?.
  The `jalr` at 0x4010 calls us_delaybus with a0=0x4, a1=?, a2=?, a3=?.
  The `jalr` at 0x401c calls pciio_pio_write8 with a0=0x5, a1=0xffffffffbf380200, a2=?, a3=?.
  The `jalr` at 0x4024 calls us_delaybus with a0=0x4, a1=?, a2=?, a3=?.
  The `jalr` at 0x4030 calls pciio_pio_write8 with a0=0x4, a1=0xffffffffbf380200, a2=?, a3=?.
  The `jalr` at 0x403c calls pciio_pio_read8 with a0=0xffffffffbf380100, a1=?, a2=?, a3=?.
  The `jalr` at 0x404c calls pciio_pio_write8 with a0=0x5, a1=0xffffffffbf380000, a2=?, a3=?.
  The `jalr` at 0x4058 calls us_delaybus with a0=0x4, a1=?, a2=?, a3=?.
  The `jalr` at 0x4064 calls pciio_pio_write8 with a0=0x5, a1=0xffffffffbf380200, a2=?, a3=?.
  The `jalr` at 0x406c calls us_delaybus with a0=0x4, a1=?, a2=?, a3=?.
  The `jalr` at 0x4078 calls pciio_pio_write8 with a0=0x7, a1=0xffffffffbf380200, a2=?, a3=?.
  The `jalr` at 0x4080 calls us_delaybus with a0=0x4, a1=?, a2=?, a3=?.
  The `jalr` at 0x408c calls pciio_pio_write8 with a0=0x5, a1=0xffffffffbf380200, a2=?, a3=?.
  The `jalr` at 0x4094 calls us_delaybus with a0=0x4, a1=?, a2=?, a3=?.
  The `jalr` at 0x40a4 calls pciio_pio_write8 with a0=0x4, a1=0xffffffffbf380200, a2=?, a3=?.
  The `jalr` at 0x40b0 calls pciio_pio_read8 with a0=0xffffffffbf388200, a1=?, a2=?, a3=?.
  The `jalr` at 0x40c4 calls pciio_pio_write8 with a0=?, a1=0xffffffffbf388200, a2=?, a3=?.
  The return at 0x40e0 has v0 = ?.

- `plpfdc_hdout` in `IP32/usr/cpu/sysgen/IP32boot/ecplp.o` at 0x40e8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/ecplp.o`.
  Range: 0x40e8-0x41a0 (184 bytes).
  It occupies 184 bytes.
  The `jalr` at 0x4110 calls pciio_pio_write8 with a0=0x2, a1=0xffffffffbf380300, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x4124 calls pciio_pio_write8 with a0=0x9, a1=0xffffffffbf380400, a2=?, a3=?.
  The `jalr` at 0x4130 calls pciio_pio_write8 with a0=0x0, a1=0xffffffffbf380300, a2=?, a3=?.
  The `jalr` at 0x4140 calls pciio_pio_read8 with a0=0xffffffffbf380400, a1=?, a2=?, a3=?.
  The `jalr` at 0x414c calls pciio_pio_write8 with a0=0x0, a1=0xffffffffbf380300, a2=?, a3=?.
  The `jalr` at 0x415c calls pciio_pio_read8 with a0=0xffffffffbf380400, a1=?, a2=?, a3=?.
  The `jalr` at 0x416c calls pciio_pio_write8 with a0=0x2, a1=0xffffffffbf380300, a2=?, a3=?.
  The `jalr` at 0x417c calls pciio_pio_write8 with a0=0x5, a1=0xffffffffbf380400, a2=?, a3=?.
  The return at 0x4198 has v0 = ?.

- `plpfdc_dmatc` in `IP32/usr/cpu/sysgen/IP32boot/ecplp.o` at 0x41a0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/ecplp.o`.
  Range: 0x41a0-0x42a8 (264 bytes).
  It occupies 264 bytes.
  The `jalr` at 0x41d8 calls pciio_pio_write8 with a0=0x2, a1=0xffffffffbf380300, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x41e4 calls pciio_pio_write8 with a0=0x9, a1=0xffffffffbf380400, a2=?, a3=?.
  The `jalr` at 0x41f0 calls pciio_pio_write8 with a0=0x0, a1=0xffffffffbf380300, a2=?, a3=?.
  The `jalr` at 0x41fc calls pciio_pio_write8 with a0=?, a1=0xffffffffbf380400, a2=?, a3=?.
  The `jalr` at 0x4208 calls pciio_pio_write8 with a0=0x0, a1=0xffffffffbf380300, a2=?, a3=?.
  The `jalr` at 0x4218 calls pciio_pio_write8 with a0=?, a1=0xffffffffbf380400, a2=?, a3=?.
  The `jalr` at 0x4224 calls pciio_pio_write8 with a0=0x2, a1=0xffffffffbf380300, a2=?, a3=?.
  The `jalr` at 0x4230 calls pciio_pio_write8 with a0=0x5, a1=0xffffffffbf380400, a2=?, a3=?.
  The `jalr` at 0x4250 calls pciio_pio_write8 with a0=0x1, a1=0xffffffffbf380300, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x425c calls pciio_pio_write8 with a0=0x2, a1=0xffffffffbf380400, a2=?, a3=?.
  The `jalr` at 0x428c calls pciio_pio_write8 with a0=0x1, a1=0xffffffffbf380300, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x4298 calls pciio_pio_write8 with a0=0x42, a1=0xffffffffbf380400, a2=?, a3=?.
  The `blez` branch at 0x41c4 targets 0x4240, is taken when a0 <= 0 (signed), and falls through when a0 > 0 (signed).
  The `beq` branch at 0x4238 targets 0x4268 and is always taken.
  The `bltz` branch at 0x4240 targets 0x4280, is taken when a0 < 0 (signed), and falls through when a0 >= 0 (signed).
  The `beq` branch at 0x42a0 targets 0x4268 and is always taken.
  The return at 0x4278 has v0 = ret(pciio_pio_write8).
