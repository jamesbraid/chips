# Readings: `IP27/usr/cpu/sysgen/IP27boot/xbmon.o`

One entry per routine, filed here from the reading batches by binary.

- `eq_init` in `IP27/usr/cpu/sysgen/IP27boot/xbmon.o` at 0x0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xbmon.o`.
  Range: 0x0-0x70 (112 bytes).
  It occupies 112 bytes.
  The `sd` at 0x34 stores 8 bytes to a0 (arg0 at entry) +0x0.
  The `sw` at 0x4c stores 4 bytes to a0 (arg0 at entry) +0x24.
  The `sd` at 0x50 stores 8 bytes to a0 (arg0 at entry) +0x8.
  The `sd` at 0x54 stores 8 bytes to a0 (arg0 at entry) +0x18.
  The `sd` at 0x58 stores 8 bytes to a0 (arg0 at entry) +0x10.
  The `sw` at 0x60 stores 4 bytes to a0 (arg0 at entry) +0x20.
  The `jal` at 0x20 calls kmem_zalloc with a0=?, a1=0x801, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `bne` branch at 0x38 targets 0x48, is taken when v0(=ret(kmem_zalloc)) != 0, and falls through when v0(=ret(kmem_zalloc)) == 0.
  The `beq` branch at 0x40 targets 0x64 and is always taken.
  The return at 0x68 has v0 = one of 0x0, 0xc.

- `eq_free` in `IP27/usr/cpu/sysgen/IP27boot/xbmon.o` at 0x70 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xbmon.o`.
  Range: 0x70-0xc0 (80 bytes).
  It occupies 80 bytes.
  The `ld` at 0x70 loads 8 bytes from a0 (arg0 at entry) +0x0.
  The `sd` at 0x9c stores 8 bytes to a0 (arg0 at entry) +0x0.
  The `sd` at 0xa0 stores 8 bytes to a0 (arg0 at entry) +0x8.
  The `sd` at 0xa4 stores 8 bytes to a0 (arg0 at entry) +0x10.
  The `sd` at 0xac stores 8 bytes to a0 (arg0 at entry) +0x18.
  The `sw` at 0xb0 stores 4 bytes to a0 (arg0 at entry) +0x20.
  The `sw` at 0xbc stores 4 bytes to a0 (arg0 at entry) +0x24.
  The `jal` at 0x90 calls kmem_free with a0=[a0]:8, a1=?, a2=a2 at entry (arg2), a3=a1 at entry (arg1), a4=[a0]:8.
  The `beq` branch at 0x80 targets 0x98, is taken when a4(=[a0]:8) == 0, and falls through when a4(=[a0]:8) != 0.
  The return at 0xb8 has v0 = one of ?, ret(kmem_free).

- `eq_enqueue` in `IP27/usr/cpu/sysgen/IP27boot/xbmon.o` at 0xc0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xbmon.o`.
  Range: 0xc0-0x16c (172 bytes).
  It occupies 172 bytes.
  The `ld` at 0xe4 loads 8 bytes from a1 (arg1 at entry) +0x10.
  The `ld` at 0xe8 loads 8 bytes from a1 (arg1 at entry) +0x8.
  The `ld` at 0xf4 loads 8 bytes from a1 (arg1 at entry) +0x18.
  The `ld` at 0xf8 loads 8 bytes from a1 (arg1 at entry) +0x0.
  The `lw` at 0x104 loads 4 bytes from a1 (arg1 at entry) +0x24.
  The `sw` at 0x118 stores 4 bytes to a1 (arg1 at entry) +0x24.
  The `ld` at 0x124 loads 8 bytes from a2 (arg2 at entry) +0x0.
  The `sd` at 0x128 stores 8 bytes to [a1+16]:8 +0x0.
  The `ld` at 0x12c loads 8 bytes from a2 (arg2 at entry) +0x8.
  The `sd` at 0x130 stores 8 bytes to [a1+16]:8 +0x8.
  The `ld` at 0x134 loads 8 bytes from a2 (arg2 at entry) +0x10.
  The `sd` at 0x138 stores 8 bytes to [a1+16]:8 +0x10.
  The `ld` at 0x13c loads 8 bytes from a2 (arg2 at entry) +0x18.
  The `sd` at 0x144 stores 8 bytes to [a1+16]:8 +0x18.
  The `sd` at 0x148 stores 8 bytes to a1 (arg1 at entry) +0x10.
  The `jal` at 0xdc calls mutex_spinlock with a0=a0+64, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x114 calls mutex_spinunlock with a0=a0+64, a1=ret(mutex_spinlock), a2=?, a3=?, a6=[a1+16]:8.
  The `jal` at 0x14c calls mutex_spinunlock with a0=a0+64, a1=ret(mutex_spinlock), a2=[a2+8]:8, a3=[a2]:8, a6=[a1+16]:8.
  The `bne` branch at 0xf0 targets 0xfc, is taken when at(=[a1+8]:8) != a5(=[a1+16]:8+32), and falls through when at(=[a1+8]:8) == a5(=[a1+16]:8+32).
  The `bne` branch at 0xfc targets 0x124, is taken when a0(=[a1+24]:8) != a5(?), and falls through when a0(=[a1+24]:8) == a5(?).
  The `beq` branch at 0x11c targets 0x158 and is always taken.
  The return at 0x164 has v0 = one of 0x0, 0x1.

- `eq_deqmulti` in `IP27/usr/cpu/sysgen/IP27boot/xbmon.o` at 0x16c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xbmon.o`.
  Range: 0x16c-0x2f0 (388 bytes).
  It occupies 388 bytes.
  The `ld` at 0x180 loads 8 bytes from a2 (arg2 at entry) +0x20.
  The `ld` at 0x1b0 loads 8 bytes from a1 (arg1 at entry) +0x10.
  The `ld` at 0x1b4 loads 8 bytes from a1 (arg1 at entry) +0x18.
  2 such `ld` accesses load 8 bytes from a1 (arg1 at entry) +0x8, including `ld` at 0x228, `ld` at 0x284.
  The `sd` at 0x278 stores 8 bytes to a1 (arg1 at entry) +0x18.
  3 such `ld` accesses load 8 bytes from a1 (arg1 at entry) +0x0, including `ld` at 0x298, `ld` at 0x2a4, `ld` at 0x2e4.
  The `jal` at 0x1a4 calls mutex_spinlock with a0=a0+64, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1b8 calls mutex_spinunlock with a0=a0+64, a1=ret(mutex_spinlock), a2=?, a3=?.
  The `jal` at 0x1f8 calls uiomove with a0=[a1+24]:8, a1=?, a2=0x0, a3=a2 at entry (arg2).
  The `jal` at 0x254 calls uiomove with a0=[a1+24]:8, a1=?, a2=0x0, a3=a2 at entry (arg2).
  The `jal` at 0x2c8 calls uiomove with a0=[a1]:8, a1=?, a2=0x0, a3=a2 at entry (arg2), a4=[a1+8]:8.
  The `beq` branch at 0x1c4 targets 0x26c, is taken when s2(=[a1+16]:8) == s0(=[a1+24]:8), and falls through when s2(=[a1+16]:8) != s0(=[a1+24]:8).
  The `beq` branch at 0x1d0 targets 0x228, is taken when s0(=[a1+24]:8) >= s2(=[a1+16]:8) (unsigned), and falls through when s0(=[a1+24]:8) < s2(=[a1+16]:8) (unsigned).
  The `beq` branch at 0x200 targets 0x274, is taken when v0(=ret(uiomove)) == 0, and falls through when v0(=ret(uiomove)) != 0.
  The `beq` branch at 0x25c targets 0x284, is taken when v0(=ret(uiomove)) == 0, and falls through when v0(=ret(uiomove)) != 0.
  The `beq` branch at 0x264 targets 0x20c and is always taken.
  The `beq` branch at 0x26c targets 0x20c and is always taken.
  The `beq` branch at 0x27c targets 0x208 and is always taken.
  The `bne` branch at 0x290 targets 0x29c, is taken when a4(=[a1+8]:8) != s0(?), and falls through when a4(=[a1+8]:8) == s0(?).
  The `beq` branch at 0x29c targets 0x278, is taken when s3(?) == 0, and falls through when s3(?) != 0.
  The `beq` branch at 0x2d0 targets 0x2e0, is taken when v0(=ret(uiomove)) == 0, and falls through when v0(=ret(uiomove)) != 0.
  The `beq` branch at 0x2d8 targets 0x20c and is always taken.
  The `beq` branch at 0x2e8 targets 0x278 and is always taken.
  The return at 0x220 has v0 = one of ?, ret(uiomove), 0x0.

- `xbmon_init` in `IP27/usr/cpu/sysgen/IP27boot/xbmon.o` at 0x2f0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xbmon.o`.
  Range: 0x2f0-0x340 (80 bytes).
  It occupies 80 bytes.
  The `jal` at 0x304 calls xwidget_driver_register with a0=0xd000, a1=0x0, a2=sym(.rodata), a3=0x0.
  The `jal` at 0x318 calls xwidget_driver_register with a0=0xd100, a1=0x0, a2=sym(.rodata), a3=0x0.
  The `jal` at 0x32c calls xwidget_driver_register with a0=0x0, a1=0x0, a2=sym(.rodata), a3=0x0.
  The return at 0x338 has v0 = ret(xwidget_driver_register).

- `xbmon_attach` in `IP27/usr/cpu/sysgen/IP27boot/xbmon.o` at 0x340 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xbmon.o`.
  Range: 0x340-0x428 (232 bytes).
  It occupies 232 bytes.
  The `sw` at 0x37c stores 4 bytes to ret(kmem_zalloc) +0xf4.
  The `sw` at 0x380 stores 4 bytes to ret(kmem_zalloc) +0xf0.
  The `sw` at 0x388 stores 4 bytes to ret(kmem_zalloc) +0x50.
  The `sw` at 0x38c stores 4 bytes to ret(kmem_zalloc) +0x4c.
  The `sw` at 0x394 stores 4 bytes to ret(kmem_zalloc) +0x48.
  The `sh` at 0x398 stores 2 bytes to ret(kmem_zalloc) +0x44.
  The `sd` at 0x39c stores 8 bytes to ret(kmem_zalloc) +0x8.
  The `lw` at 0x3a0 loads 4 bytes from ret(kmem_zalloc) +0x10.
  The `sw` at 0x3a8 stores 4 bytes to ret(kmem_zalloc) +0x0.
  The `sw` at 0x3b4 stores 4 bytes to ret(kmem_zalloc) +0x10.
  The `lwu` at 0x3c0 loads 4 bytes from ret(kmem_zalloc) +0x40.
  The `sw` at 0x3ec stores 4 bytes to ret(kmem_zalloc) +0x4.
  The `jal` at 0x360 calls xtalk_piotrans_addr with a0=a0 at entry (arg0), a1=0x0, a2=0x0, a3=0x300, a4=0x0.
  The `jal` at 0x374 calls kmem_zalloc with a0=0xf8, a1=0x0, a2=?, a3=?.
  The `jal` at 0x3dc calls hwgraph_char_device_add with a0=a0 at entry (arg0), a1=sym(.rodata), a2=sym(.rodata), a3=sp-48.
  The `jal` at 0x3f4 calls hwgraph_fastinfo_set with a0=?, a1=ret(kmem_zalloc), a2=?, a3=?.
  The `jal` at 0x418 calls spinlock_init with a0=ret(kmem_zalloc)+64, a1=sym(.rodata), a2=?, a3=?.
  The `beq` branch at 0x3c4 targets 0x410, is taken when v0(=[ret(kmem_zalloc)+64]) == 0, and falls through when v0(=[ret(kmem_zalloc)+64]) != 0.
  The `beq` branch at 0x420 targets 0x3d0 and is always taken.
  The return at 0x408 has v0 = 0x0.

- `xbmon_unload` in `IP27/usr/cpu/sysgen/IP27boot/xbmon.o` at 0x428 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xbmon.o`.
  Range: 0x428-0x434 (12 bytes).
  It occupies 12 bytes.
  The return at 0x42c has v0 = 0x0.

- `xbmon_open` in `IP27/usr/cpu/sysgen/IP27boot/xbmon.o` at 0x434 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xbmon.o`.
  Range: 0x434-0x604 (464 bytes).
  It occupies 464 bytes.
  The `lw` at 0x484 loads 4 bytes from a0 (arg0 at entry) +0x0.
  2 such `lw` accesses load 4 bytes from ret(hwgraph_fastinfo_get) +0x10, including `lw` at 0x488, `lw` at 0x504.
  The `ld` at 0x494 loads 8 bytes from ret(hwgraph_fastinfo_get) +0x8.
  The `sw` at 0x4b8 stores 4 bytes to ret(hwgraph_fastinfo_get) +0x50.
  The `sw` at 0x4cc stores 4 bytes to ret(hwgraph_fastinfo_get) +0x68.
  The `sw` at 0x4d0 stores 4 bytes to ret(hwgraph_fastinfo_get) +0x64.
  The `sw` at 0x4d4 stores 4 bytes to ret(hwgraph_fastinfo_get) +0x5c.
  The `sw` at 0x4d8 stores 4 bytes to ret(hwgraph_fastinfo_get) +0x58.
  The `sh` at 0x4e0 stores 2 bytes to ret(hwgraph_fastinfo_get) +0x44.
  The `sw` at 0x4e8 stores 4 bytes to ret(hwgraph_fastinfo_get) +0x4c.
  The `sw` at 0x4f4 stores 4 bytes to ret(hwgraph_fastinfo_get) +0x48.
  The `sd` at 0x4fc stores 8 bytes to ret(hwgraph_fastinfo_get) +0xc8.
  The `sw` at 0x514 stores 4 bytes to ret(hwgraph_fastinfo_get) +0x10.
  2 such `sw` accesses store 4 bytes to ret(hwgraph_fastinfo_get) +0xf0, including `sw` at 0x528, `sw` at 0x5c4.
  The `sd` at 0x530 stores 8 bytes to ret(hwgraph_fastinfo_get) +0xc0.
  The `sd` at 0x544 stores 8 bytes to ret(hwgraph_fastinfo_get) +0xb8.
  4 such `sw` accesses store 4 bytes to ?, including `sw` at 0x550, `sw` at 0x558, `sw` at 0x5d0.
  2 such `ld` accesses load 8 bytes from ret(hwgraph_fastinfo_get) +0xc8, including `ld` at 0x560, `ld` at 0x598.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0x574, `ld` at 0x5a0.
  2 such `sd` accesses store 8 bytes to ?, including `sd` at 0x584, `sd` at 0x5a8.
  3 such `lw` accesses load 4 bytes from ?, including `lw` at 0x588, `lw` at 0x5c8, `lw` at 0x5d4.
  2 such `lw` accesses load 4 bytes from ret(hwgraph_fastinfo_get) +0xf0, including `lw` at 0x5ac, `lw` at 0x5bc.
  The `sw` at 0x5b8 stores 4 bytes to (ret(hwgraph_fastinfo_get) + ([ret(hwgraph_fastinfo_get)+240] << 0x2)) +0xd0.
  The `jal` at 0x480 calls hwgraph_fastinfo_get with a0=[a0], a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=0x16, a4=a0 at entry (arg0), a5=0x1.
  The `jal` at 0x4b4 calls eq_init with a0=ret(hwgraph_fastinfo_get)+24, a1=0x2710, a2=?, a3=0x10.
  The `jal` at 0x4f0 calls kmem_zalloc with a0=0x4000, a1=0x800, a2=0x1, a3=?.
  The `jal` at 0x524 calls nanotime with a0=sp-48, a1=?, a2=?, a3=(0xffffffff80000000 | [ret(hwgraph_fastinfo_get)+16]).
  The `beq` branch at 0x450 targets 0x470, is taken when a5(=0x1) == at(=[sym(.sdata)+12]:2), and falls through when a5(=0x1) != at(=[sym(.sdata)+12]:2).
  The `beq` branch at 0x470 targets 0x480, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x478 targets 0x460 and is always taken.
  The `beq` branch at 0x49c targets 0x4ac, is taken when v1(?) == 0, and falls through when v1(?) != 0.
  The `beq` branch at 0x4a4 targets 0x460 and is always taken.
  The `beq` branch at 0x4bc targets 0x4cc, is taken when v0(=ret(eq_init)) == 0, and falls through when v0(=ret(eq_init)) != 0.
  The `beq` branch at 0x4c4 targets 0x45c and is always taken.
  The `beq` branch at 0x4f8 targets 0x5fc, is taken when v0(=ret(kmem_zalloc)) == 0, and falls through when v0(=ret(kmem_zalloc)) != 0.
  The `bne` branch at 0x510 targets 0x520, is taken when a4(?) != 0, and falls through when a4(?) == 0.
  The `beq` branch at 0x518 targets 0x45c and is always taken.
  The `beq` branch at 0x590 targets 0x5e4, is taken when (a5(=0xffffffff80000000) & a7(?)) == 0, and falls through when (a5(=0xffffffff80000000) & a7(?)) != 0.
  The `bne` branch at 0x5ec targets 0x54c, is taken when v0(?) < 0x8 (signed), and falls through when v0(?) >= 0x8 (signed).
  The `beq` branch at 0x5f4 targets 0x45c and is always taken.
  The `beq` branch at 0x5fc targets 0x45c and is always taken.
  The return at 0x468 has v0 = one of 0x0, 0x5, 0xc, 0x16, 0x10.

- `xbmon_close` in `IP27/usr/cpu/sysgen/IP27boot/xbmon.o` at 0x604 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xbmon.o`.
  Range: 0x604-0x678 (116 bytes).
  It occupies 116 bytes.
  The `lw` at 0x614 loads 4 bytes from ret(hwgraph_fastinfo_get) +0x4c.
  The `lhu` at 0x618 loads 2 bytes from ret(hwgraph_fastinfo_get) +0x44.
  The `sh` at 0x62c stores 2 bytes to ret(hwgraph_fastinfo_get) +0x44.
  The `lw` at 0x644 loads 4 bytes from ret(hwgraph_fastinfo_get) +0x50.
  The `lw` at 0x650 loads 4 bytes from ret(hwgraph_fastinfo_get) +0x10.
  The `sw` at 0x668 stores 4 bytes to ret(hwgraph_fastinfo_get) +0x10.
  The `jal` at 0x60c calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x630 calls untimeout with a0=[ret(hwgraph_fastinfo_get)+76], a1=?, a2=?, a3=?.
  The `jal` at 0x63c calls xb_disable_cntr with a0=ret(hwgraph_fastinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0x648 calls eq_free with a0=ret(hwgraph_fastinfo_get)+24, a1=[ret(hwgraph_fastinfo_get)+80], a2=?, a3=?.
  The `beq` branch at 0x628 targets 0x638, is taken when a0(=[ret(hwgraph_fastinfo_get)+76]) == 0, and falls through when a0(=[ret(hwgraph_fastinfo_get)+76]) != 0.
  The return at 0x670 has v0 = 0x0.

- `xbmon_read` in `IP27/usr/cpu/sysgen/IP27boot/xbmon.o` at 0x678 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xbmon.o`.
  Range: 0x678-0x6ac (52 bytes).
  It occupies 52 bytes.
  The `jal` at 0x684 calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x694 calls eq_deqmulti with a0=ret(hwgraph_fastinfo_get), a1=ret(hwgraph_fastinfo_get)+24, a2=a1 at entry (arg1), a3=?.
  The return at 0x6a4 has v0 = ret(eq_deqmulti).

- `xbmon_write` in `IP27/usr/cpu/sysgen/IP27boot/xbmon.o` at 0x6ac (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xbmon.o`.
  Range: 0x6ac-0x72c (128 bytes).
  It occupies 128 bytes.
  The `jal` at 0x6b8 calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x6d0 calls uiomove with a0=sp-80, a1=0x20, a2=0x1, a3=a1 at entry (arg1).
  The `jal` at 0x6ec calls nanotime with a0=sp-48, a1=?, a2=?, a3=?.
  The `jal` at 0x70c calls eq_enqueue with a0=?, a1=?, a2=sp-80, a3=?.
  The `beq` branch at 0x6d8 targets 0x6ec, is taken when v0(=ret(uiomove)) == 0, and falls through when v0(=ret(uiomove)) != 0.
  The `beq` branch at 0x714 targets 0x724, is taken when v0(=ret(eq_enqueue)) == 0, and falls through when v0(=ret(eq_enqueue)) != 0.
  The `beq` branch at 0x71c targets 0x6e0 and is always taken.
  The `beq` branch at 0x724 targets 0x6e0 and is always taken.
  The return at 0x6e4 has v0 = one of ret(uiomove), 0x0, 0xc.

- `xbtrace` in `IP27/usr/cpu/sysgen/IP27boot/xbmon.o` at 0x72c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xbmon.o`.
  Range: 0x72c-0x780 (84 bytes).
  It occupies 84 bytes.
  The `jal` at 0x744 calls nanotime with a0=sp-32, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x764 calls eq_enqueue with a0=a0 at entry (arg0), a1=a0+24, a2=sp-64, a3=?.
  The return at 0x778 has v0 = 0x0.

- `xbmon_ioctl` in `IP27/usr/cpu/sysgen/IP27boot/xbmon.o` at 0x780 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xbmon.o`.
  Range: 0x780-0xc18 (1176 bytes).
  It occupies 1176 bytes.
  The `ld` at 0x7c4 loads 8 bytes from ret(hwgraph_fastinfo_get) +0x8.
  The `ld` at 0x7d0 loads 8 bytes from (sym(.rodata) + (a1-282625 << 0x3)) +0x0.
  The `jal` at 0x79c calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  Calls (unknown callee) via register with a0=(sym(.rodata) + (a1-282625 << 0x3)), a1=(a1-282625 << 0x3), a2=[(sym(.rodata) + (a1-282625 << 0x3))]:8, a3=? (`jr` at 0x7d4).
  The `beq` branch at 0x7c8 targets 0x7dc, is taken when a1(=a1-282625) >= 0xe (unsigned), and falls through when a1(=a1-282625) < 0xe (unsigned).
  The return at 0x7f4 has v0 = 0x16.
  The instructions from 0x7fc to 0xc14 are not reached by any path from the entry, and their branches are not listed.
  The indirect jump at 0x7d4 uses a jump table whose successors are unresolved.

- `xbmon_map` in `IP27/usr/cpu/sysgen/IP27boot/xbmon.o` at 0xc18 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xbmon.o`.
  Range: 0xc18-0xc68 (80 bytes).
  It occupies 80 bytes.
  The `ld` at 0xc2c loads 8 bytes from ret(hwgraph_fastinfo_get) +0xc8.
  The `jal` at 0xc24 calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xc58 calls v_mapphys with a0=a1 at entry (arg1), a1=[ret(hwgraph_fastinfo_get)+200]:8, a2=?, a3=-0x4000, a5=0x16.
  The `bne` branch at 0xc30 targets 0xc48, is taken when a1(=[ret(hwgraph_fastinfo_get)+200]:8) != 0, and falls through when a1(=[ret(hwgraph_fastinfo_get)+200]:8) == 0.
  The `beq` branch at 0xc60 targets 0xc38 and is always taken.
  The return at 0xc40 has v0 = one of 0x16, ret(v_mapphys).

- `xbmon_unmap` in `IP27/usr/cpu/sysgen/IP27boot/xbmon.o` at 0xc68 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xbmon.o`.
  Range: 0xc68-0xc70 (8 bytes).
  It occupies 8 bytes.
  The return at 0xc68 has v0 = 0x0.

- `xb_enable_cntr` in `IP27/usr/cpu/sysgen/IP27boot/xbmon.o` at 0xc70 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xbmon.o`.
  Range: 0xc70-0xcfc (140 bytes).
  It occupies 140 bytes.
  2 such `lw` accesses load 4 bytes from a2 (arg2 at entry) +0x0, including `lw` at 0xc94, `lw` at 0xca4.
  The `sw` at 0xca0 stores 4 bytes to (a0 + one of 0x64, 0x6c) +0x0.
  The `lw` at 0xca8 loads 4 bytes from a2 (arg2 at entry) +0x4.
  The `lw` at 0xccc loads 4 bytes from ?.
  The `lw` at 0xcd4 loads 4 bytes from table(sym(.data)) +0x0.
  The `lw` at 0xce4 loads 4 bytes from a2 (arg2 at entry) +0x8.
  The `sw` at 0xcf0 stores 4 bytes to ?.
  The `beq` branch at 0xc70 targets 0xc8c, is taken when a1 == 0, and falls through when a1 != 0.
  The `bne` branch at 0xc7c targets 0xcf4, is taken when a1 != a5(=0x1), and falls through when a1 == a5(=0x1).
  The `beq` branch at 0xc84 targets 0xc94 and is always taken.
  The `bne` branch at 0xcdc targets 0xcf0, is taken when a6(=[a2+4]) != a7(=0x3), and falls through when a6(=[a2+4]) == a7(=0x3).
  The return at 0xcf4 has v0 = ?.

- `xb_disable_cntr` in `IP27/usr/cpu/sysgen/IP27boot/xbmon.o` at 0xcfc (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xbmon.o`.
  Range: 0xcfc-0xd60 (100 bytes).
  It occupies 100 bytes.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0xf0, including `lw` at 0xcfc, `lw` at 0xd44.
  The `ld` at 0xd00 loads 8 bytes from a0 (arg0 at entry) +0x8.
  The `lw` at 0xd18 loads 4 bytes from sym(.data) +0x0.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0xd24, `lw` at 0xd34.
  The `sw` at 0xd40 stores 4 bytes to ?.
  The `blez` branch at 0xd10 targets 0xd58, is taken when a5(=[a0+240]) <= 0 (signed), and falls through when a5(=[a0+240]) > 0 (signed).
  The `bne` branch at 0xd50 targets 0xd20, is taken when a2(?) < a6(=[a0+240]) (signed), and falls through when a2(?) >= a6(=[a0+240]) (signed).
  The return at 0xd58 has v0 = ?.

- `xb_timeout_rtn` in `IP27/usr/cpu/sysgen/IP27boot/xbmon.o` at 0xd60 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xbmon.o`.
  Range: 0xd60-0x1084 (804 bytes).
  It occupies 804 bytes.
  The `ld` at 0xd68 loads 8 bytes from a0 (arg0 at entry) +0x8.
  The `lhu` at 0xd70 loads 2 bytes from a0 (arg0 at entry) +0x44.
  The `ld` at 0xd98 loads 8 bytes from a0 (arg0 at entry) +0xb8.
  The `ld` at 0xda0 loads 8 bytes from a0 (arg0 at entry) +0xc0.
  2 such `lw` accesses load 4 bytes from [a0+8]:8 +0x64, including `lw` at 0xdbc, `lw` at 0x1028.
  2 such `lw` accesses load 4 bytes from [a0+8]:8 +0x6c, including `lw` at 0xdc0, `lw` at 0x103c.
  The `lw` at 0xdc8 loads 4 bytes from a0 (arg0 at entry) +0x5c.
  The `ld` at 0xdcc loads 8 bytes from a0 (arg0 at entry) +0xc8.
  The `lw` at 0xdf0 loads 4 bytes from a0 (arg0 at entry) +0x58.
  The `lw` at 0xe08 loads 4 bytes from a0 (arg0 at entry) +0x70.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x70, including `sw` at 0xe20, `sw` at 0x1038.
  4 such `lw` accesses load 4 bytes from ?, including `lw` at 0xe30, `lw` at 0xef4, `lw` at 0xfec.
  The `lw` at 0xe34 loads 4 bytes from (a0 + ([a0+88] << 0x2)) +0x98.
  The `sw` at 0xe4c stores 4 bytes to (a0 + ([a0+88] << 0x2)) +0x98.
  The `lwu` at 0xe50 loads 4 bytes from a0 (arg0 at entry) +0x58.
  The `sd` at 0xe64 stores 8 bytes to ([a0+200]:8 + ((([a0+88] << 0x3) + [a0+88]) << 0x3)) +0x10.
  The `sd` at 0xe68 stores 8 bytes to ([a0+200]:8 + ((([a0+88] << 0x3) + [a0+88]) << 0x3)) +0x18.
  The `sd` at 0xe70 stores 8 bytes to ([a0+200]:8 + ((([a0+88] << 0x3) + [a0+88]) << 0x3)) +0x0.
  The `ld` at 0xe74 loads 8 bytes from ([a0+200]:8 + ((([a0+88] << 0x3) + [a0+88]) << 0x3)) +0x40.
  The `ld` at 0xe80 loads 8 bytes from ([a0+200]:8 + ((([a0+88] << 0x3) + [a0+88]) << 0x3)) +0x8.
  The `sd` at 0xe8c stores 8 bytes to ([a0+200]:8 + ((([a0+88] << 0x3) + [a0+88]) << 0x3)) +0x40.
  The `sd` at 0xe98 stores 8 bytes to ([a0+200]:8 + ((([a0+88] << 0x3) + [a0+88]) << 0x3)) +0x8.
  The `lw` at 0xe9c loads 4 bytes from a0 (arg0 at entry) +0x68.
  The `lw` at 0xeb4 loads 4 bytes from a0 (arg0 at entry) +0x64.
  The `lw` at 0xecc loads 4 bytes from a0 (arg0 at entry) +0x74.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x74, including `sw` at 0xeec, `sw` at 0x1048.
  The `lw` at 0xef8 loads 4 bytes from (a0 + ([a0+100] << 0x2)) +0x78.
  The `sw` at 0xf0c stores 4 bytes to (a0 + ([a0+100] << 0x2)) +0x78.
  The `lwu` at 0xf10 loads 4 bytes from a0 (arg0 at entry) +0x64.
  The `sd` at 0xf24 stores 8 bytes to ([a0+200]:8 + ((([a0+100] << 0x3) + [a0+100]) << 0x3)) +0x28.
  The `sd` at 0xf28 stores 8 bytes to ([a0+200]:8 + ((([a0+100] << 0x3) + [a0+100]) << 0x3)) +0x30.
  The `ld` at 0xf2c loads 8 bytes from ([a0+200]:8 + ((([a0+100] << 0x3) + [a0+100]) << 0x3)) +0x38.
  The `ld` at 0xf38 loads 8 bytes from ([a0+200]:8 + ((([a0+100] << 0x3) + [a0+100]) << 0x3)) +0x20.
  The `sd` at 0xf44 stores 8 bytes to ([a0+200]:8 + ((([a0+100] << 0x3) + [a0+100]) << 0x3)) +0x38.
  The `sd` at 0xf50 stores 8 bytes to ([a0+200]:8 + ((([a0+100] << 0x3) + [a0+100]) << 0x3)) +0x20.
  The `lw` at 0xf54 loads 4 bytes from a0 (arg0 at entry) +0x54.
  The `lwu` at 0xf64 loads 4 bytes from a0 (arg0 at entry) +0x48.
  The `sw` at 0xf78 stores 4 bytes to a0 (arg0 at entry) +0x4c.
  The `lw` at 0xfb0 loads 4 bytes from a0 (arg0 at entry) +0xf0.
  The `lw` at 0xfbc loads 4 bytes from a0 (arg0 at entry) +0xf4.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0xf4, including `sw` at 0xfcc, `sw` at 0xfd4.
  The `sw` at 0xff8 stores 4 bytes to a0 (arg0 at entry) +0x58.
  The `sw` at 0x1014 stores 4 bytes to a0 (arg0 at entry) +0x64.
  The `jal` at 0xd90 calls nanotime with a0=sp-112, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xe94 calls eq_enqueue with a0=a0 at entry (arg0), a1=a0+24, a2=sp-96, a3=?, a5=(a0 + ([a0+88] << 0x2)), a7=([a0+200]:8 + ((([a0+88] << 0x3) + [a0+88]) << 0x3)).
  The `jal` at 0xf4c calls eq_enqueue with a0=a0 at entry (arg0), a1=a0+24, a2=sp-96, a3=[a0+104], a5=(a0 + ([a0+100] << 0x2)).
  The `jal` at 0xf6c calls timeout with a0=sym(xb_timeout_rtn), a1=a0 at entry (arg0), a2=[a0+72], a3=?.
  The `jal` at 0x1010 calls xb_enable_cntr with a0=[a0+8]:8, a1=0x0, a2=a0+88, a3=?, a4=[a0+240].
  The `jal` at 0x1020 calls xb_enable_cntr with a0=[a0+8]:8, a1=0x1, a2=a0+100, a3=?.
  The `jal` at 0x1074 calls cmn_err with a0=0x5, a1=sym(.rodata), a2=?, a3=?.
  The `beq` branch at 0xd88 targets 0xf7c, is taken when (at(=[a0+68]:2) & 0x1) == 0, and falls through when (at(=[a0+68]:2) & 0x1) != 0.
  The `bltz` branch at 0xdac targets 0xf9c, is taken when s3(?) < 0 (signed), and falls through when s3(?) >= 0 (signed).
  The `beq` branch at 0xde8 targets 0xe9c, is taken when a5(=[a0+92]) == 0, and falls through when a5(=[a0+92]) != 0.
  The `bltz` branch at 0xe24 targets 0x104c, is taken when a4(?) < 0 (signed), and falls through when a4(?) >= 0 (signed).
  The `bltz` branch at 0xe44 targets 0x1054, is taken when a6(?) < 0 (signed), and falls through when a6(?) >= 0 (signed).
  The `beq` branch at 0xeac targets 0xf54, is taken when a3(=[a0+104]) == 0, and falls through when a3(=[a0+104]) != 0.
  The `bltz` branch at 0xee8 targets 0x105c, is taken when a4(?) < 0 (signed), and falls through when a4(?) >= 0 (signed).
  The `bltz` branch at 0xf04 targets 0x1064, is taken when a6(?) < 0 (signed), and falls through when a6(?) >= 0 (signed).
  The `beq` branch at 0xf5c targets 0xfb0, is taken when t3(=[a0+84]) == t8(=0x1), and falls through when t3(=[a0+84]) != t8(=0x1).
  The `beq` branch at 0xf74 targets 0x106c, is taken when v0(=ret(timeout)) == 0, and falls through when v0(=ret(timeout)) != 0.
  The `beq` branch at 0xfa8 targets 0xdb4 and is always taken.
  The `blez` branch at 0xfb4 targets 0xf64, is taken when a4(=[a0+240]) <= 0 (signed), and falls through when a4(=[a0+240]) > 0 (signed).
  The `bne` branch at 0xfc8 targets 0xfd8, is taken when a5(=[a0+244]+1) < a4(=[a0+240]) (signed), and falls through when a5(=[a0+244]+1) >= a4(=[a0+240]) (signed).
  The `beq` branch at 0x1044 targets 0xf64 and is always taken.
  The `beq` branch at 0x104c targets 0xe2c and is always taken.
  The `beq` branch at 0x1054 targets 0xe4c and is always taken.
  The `beq` branch at 0x105c targets 0xef0 and is always taken.
  The `beq` branch at 0x1064 targets 0xf0c and is always taken.
  The `beq` branch at 0x107c targets 0xf80 and is always taken.
  The return at 0xf94 has v0 = one of ?, ret(cmn_err).
