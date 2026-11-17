# Readings: `IP35/usr/cpu/sysgen/IP35boot/ioc4_pckm.o`

One entry per routine, filed here from the reading batches by binary.

- `ioc4_pckm_mlreset` in `IP35/usr/cpu/sysgen/IP35boot/ioc4_pckm.o` at 0x0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc4_pckm.o`.
  Range: 0x0-0x4c (76 bytes).
  It occupies 76 bytes.
  The `jal` at 0x38 calls pckm_console_register with a0=sp-64, a1=sym(ioc4_pckm_kbdexists), a2=sym(ioc4_early_pckminit), a3=a3 at entry (arg3).
  The return at 0x44 has v0 = ret(pckm_console_register).

- `ioc4_early_pckminit` in `IP35/usr/cpu/sysgen/IP35boot/ioc4_pckm.o` at 0x4c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc4_pckm.o`.
  Range: 0x4c-0x54 (8 bytes).
  It occupies 8 bytes.
  The return at 0x4c has v0 = ?.

- `ioc4_pckminit` in `IP35/usr/cpu/sysgen/IP35boot/ioc4_pckm.o` at 0x54 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc4_pckm.o`.
  Range: 0x54-0x5c (8 bytes).
  It occupies 8 bytes.
  The return at 0x54 has v0 = ?.

- `ioc4_pckm_attach` in `IP35/usr/cpu/sysgen/IP35boot/ioc4_pckm.o` at 0x5c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc4_pckm.o`.
  Range: 0x5c-0x5ec (1424 bytes).
  It occupies 1424 bytes.
  The `sw` at 0xe0 stores 4 bytes to ret(kmem_zalloc) +0x0.
  The `sd` at 0xe4 stores 8 bytes to ret(kmem_zalloc) +0x10.
  The `sd` at 0xe8 stores 8 bytes to ret(kmem_zalloc) +0x60.
  The `sd` at 0x104 stores 8 bytes to ret(kmem_zalloc) +0x68.
  The `sd` at 0x10c stores 8 bytes to ret(kmem_zalloc) +0x18.
  The `sd` at 0x128 stores 8 bytes to ret(kmem_zalloc) +0x20.
  6 such `ld` accesses load 8 bytes from ret(kmem_zalloc) +0x18, including `ld` at 0x134, `ld` at 0x13c, `ld` at 0x160.
  The `sw` at 0x138 stores 4 bytes to [ret(kmem_zalloc)+24]:8 +0x4.
  The `sd` at 0x140 stores 8 bytes to [ret(kmem_zalloc)+24]:8 +0x48.
  6 such `ld` accesses load 8 bytes from ret(kmem_zalloc) +0x20, including `ld` at 0x144, `ld` at 0x14c, `ld` at 0x154.
  The `sw` at 0x148 stores 4 bytes to [ret(kmem_zalloc)+32]:8 +0x4.
  The `sd` at 0x150 stores 8 bytes to [ret(kmem_zalloc)+32]:8 +0x48.
  The `sw` at 0x15c stores 4 bytes to [ret(kmem_zalloc)+32]:8 +0x54.
  The `sw` at 0x164 stores 4 bytes to [ret(kmem_zalloc)+24]:8 +0x54.
  The `sw` at 0x168 stores 4 bytes to ret(kmem_zalloc) +0x38.
  The `sw` at 0x174 stores 4 bytes to ret(ioc4_mem_ptr) +0x200.
  5 such `lw` accesses load 4 bytes from ret(kmem_zalloc) +0x28, including `lw` at 0x184, `lw` at 0x1ac, `lw` at 0x2c0.
  2 such `ld` accesses load 8 bytes from (ret(kmem_zalloc) + ([ret(kmem_zalloc)+40] << 0x3)) +0x18, including `ld` at 0x198, `ld` at 0x2d4.
  6 such `sw` accesses store 4 bytes to ?, including `sw` at 0x1a0, `sw` at 0x1a8, `sw` at 0x228.
  The `lw` at 0x214 loads 4 bytes from ?.
  The `sw` at 0x240 stores 4 bytes to ret(kmem_zalloc) +0x4.
  The `lw` at 0x2d8 loads 4 bytes from [(ret(kmem_zalloc) + ([ret(kmem_zalloc)+40] << 0x3))+24]:8 +0x4.
  5 such `lw` accesses load 4 bytes from ret(kmem_zalloc) +0x2c, including `lw` at 0x2e8, `lw` at 0x308, `lw` at 0x3f8.
  3 such `ld` accesses load 8 bytes from (ret(kmem_zalloc) + ([ret(kmem_zalloc)+44] << 0x3)) +0x18, including `ld` at 0x2f8, `ld` at 0x31c, `ld` at 0x40c.
  The `lw` at 0x350 loads 4 bytes from ret(kmem_zalloc) +0x5c.
  2 such `sw` accesses store 4 bytes to [(ret(kmem_zalloc) + ([ret(kmem_zalloc)+44] << 0x3))+24]:8 +0x8, including `sw` at 0x368, `sw` at 0x530.
  2 such `lw` accesses load 4 bytes from [(ret(kmem_zalloc) + ([ret(kmem_zalloc)+44] << 0x3))+24]:8 +0x4, including `lw` at 0x378, `lw` at 0x410.
  The `sw` at 0x38c stores 4 bytes to [(ret(kmem_zalloc) + ([ret(kmem_zalloc)+44] << 0x3))+24]:8 +0x4.
  The `sw` at 0x3a0 stores 4 bytes to [(ret(kmem_zalloc) + ([ret(kmem_zalloc)+44] << 0x3))+24]:8 +0x0.
  The `sw` at 0x3a4 stores 4 bytes to ret(kmem_zalloc) +0x8.
  3 such `ld` accesses load 8 bytes from ret(kmem_zalloc) +0x10, including `ld` at 0x460, `ld` at 0x484, `ld` at 0x4ac.
  The `sw` at 0x468 stores 4 bytes to [ret(kmem_zalloc)+16]:8 +0xc.
  The `lw` at 0x474 loads 4 bytes from [ret(kmem_zalloc)+32]:8 +0x4.
  The `lw` at 0x47c loads 4 bytes from [ret(kmem_zalloc)+24]:8 +0x4.
  2 such `lw` accesses load 4 bytes from [ret(kmem_zalloc)+16]:8 +0x200, including `lw` at 0x494, `lw` at 0x4bc.
  2 such `sw` accesses store 4 bytes to [ret(kmem_zalloc)+16]:8 +0x200, including `sw` at 0x4a8, `sw` at 0x4c8.
  The `jal` at 0x6c calls ioc4_subdev_enabled with a0=a0 at entry (arg0), a1=0x1, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x88 calls hwgraph_traverse with a0=a0 at entry (arg0), a1=sym(.rodata), a2=sp-80, a3=?.
  The `jal` at 0x94 calls hwgraph_fastinfo_get with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xac calls ioc4_write_ireg with a0=ret(hwgraph_fastinfo_get), a1=0x40, a2=0x1, a3=0x1.
  The `jal` at 0xb4 calls ioc4_mem_ptr with a0=ret(hwgraph_fastinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0xc4 calls ioc4_is_console with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xd8 calls kmem_zalloc with a0=0x70, a1=0x0, a2=?, a3=?.
  The `jal` at 0x100 calls kmem_zalloc with a0=0x58, a1=0x0, a2=[sym(.sdata)+8]:8, a3=?.
  The `jal` at 0x110 calls kmem_zalloc with a0=0x58, a1=0x0, a2=?, a3=?.
  The `jal` at 0x12c calls init_mutex with a0=ret(kmem_zalloc)+72, a1=0x0, a2=sym(.rodata), a3=0x0.
  The `jal` at 0x170 calls initkbdtype with a0=?, a1=?, a2=?, a3=0xc00000, a4=-0x1, a5=[ret(kmem_zalloc)+24]:8, a6=[ret(kmem_zalloc)+32]:8, a7=[ret(kmem_zalloc)+32]:8.
  The `jal` at 0x17c calls set_ports with a0=ret(kmem_zalloc), a1=?, a2=?, a3=?.
  The `jal` at 0x1b8 calls pckm_flushinp with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1c4 calls pckm_pollcmd with a0=?, a1=0xf5, a2=?, a3=?.
  The `jal` at 0x1d0 calls data_check with a0=ret(pckm_pollcmd), a1=0xfa, a2=?, a3=?.
  The `jal` at 0x1e4 calls default_kbd_setting with a0=?, a1=0x1, a2=0x0, a3=?.
  The `jal` at 0x1f0 calls pckm_pollcmd with a0=?, a1=0xf4, a2=?, a3=?.
  The `jal` at 0x1fc calls data_check with a0=ret(pckm_pollcmd), a1=0xfa, a2=?, a3=?.
  The `jal` at 0x224 calls hwgraph_char_device_add with a0=a0 at entry (arg0), a1=sym(.rodata), a2=sym(.rodata), a3=sp-76.
  The `jal` at 0x230 calls hwgraph_chmod with a0=?, a1=0x1b6, a2=?, a3=?.
  The `jal` at 0x248 calls hwgraph_fastinfo_set with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x264 calls device_inventory_add with a0=?, a1=0xe, a2=0x1, a3=-0x1, a4=0x0, a5=0x1.
  The `jal` at 0x270 calls kopt_find with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jal` at 0x320 calls pckm_flushinp with a0=[(ret(kmem_zalloc) + ([ret(kmem_zalloc)+44] << 0x3))+24]:8, a1=?, a2=[ret(kmem_zalloc)+44], a3=?, a5=[sym(showconfig)].
  The `jal` at 0x32c calls pckm_pollcmd with a0=[(ret(kmem_zalloc) + ([ret(kmem_zalloc)+44] << 0x3))+24]:8, a1=0xf6, a2=?, a3=?.
  The `jal` at 0x338 calls data_check with a0=ret(pckm_pollcmd), a1=0xfa, a2=?, a3=?.
  The `jal` at 0x348 calls default_ms_setting with a0=[(ret(kmem_zalloc) + ([ret(kmem_zalloc)+44] << 0x3))+24]:8, a1=?, a2=?, a3=?, a5=[sym(showconfig)].
  The `jal` at 0x388 calls hwgraph_char_device_add with a0=a0 at entry (arg0), a1=sym(.rodata), a2=sym(.rodata), a3=sp-72.
  The `jal` at 0x394 calls hwgraph_chmod with a0=?, a1=0x1b6, a2=?, a3=?.
  The `jal` at 0x3ac calls hwgraph_fastinfo_set with a0=?, a1=[(ret(kmem_zalloc) + ([ret(kmem_zalloc)+44] << 0x3))+24]:8, a2=?, a3=?.
  The `jal` at 0x3c8 calls device_inventory_add with a0=?, a1=0xe, a2=0x1, a3=-0x1, a4=0x0, a5=0x0.
  The `jal` at 0x458 calls ioc4_intr_connect with a0=a0 at entry (arg0), a1=0x1, a2=0x40, a3=sym(pckm_intr), a4=ret(kmem_zalloc), a7=0x0.
  The `jal` at 0x4c4 calls ioc4_write_ireg with a0=ret(hwgraph_fastinfo_get), a1=0x40, a2=0x0, a3=0x1.
  The `jal` at 0x538 calls strstr with a0=ret(kopt_find), a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x558 calls ioc4_pckm_mlreset with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x590 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=a0 at entry (arg0), a3=?, a5=[sym(showconfig)], a7=[sym(.sbss)]:8.
  The `jal` at 0x5ac calls cmn_err with a0=0x6, a1=sym(.rodata), a2=a0 at entry (arg0), a3=[sym(showconfig)].
  The `jal` at 0x5c4 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=?, a3=?, a4=[sym(showconfig)], a5=[sym(showconfig)].
  The `jal` at 0x5dc calls cmn_err with a0=0x6, a1=sym(.rodata), a2=?, a3=[sym(showconfig)].
  The `beq` branch at 0x74 targets 0x4ec, is taken when v0(=ret(ioc4_subdev_enabled)) == 0, and falls through when v0(=ret(ioc4_subdev_enabled)) != 0.
  The `beq` branch at 0x18c targets 0x504, is taken when v0(=[ret(kmem_zalloc)+40]) == s4(=0x13), and falls through when v0(=[ret(kmem_zalloc)+40]) != s4(=0x13).
  The `beq` branch at 0x1b0 targets 0x2a8, is taken when t8(=[ret(kmem_zalloc)+40]) == s4(=0x13), and falls through when t8(=[ret(kmem_zalloc)+40]) != s4(=0x13).
  The `beq` branch at 0x1d8 targets 0x4f4, is taken when v0(=ret(data_check)) == 0, and falls through when v0(=ret(data_check)) != 0.
  The `beq` branch at 0x204 targets 0x4fc, is taken when v0(=ret(data_check)) == 0, and falls through when v0(=ret(data_check)) != 0.
  The `beq` branch at 0x27c targets 0x558, is taken when a1(=[sym(kbd_console_initialized)]) == 0, and falls through when a1(=[sym(kbd_console_initialized)]) != 0.
  The `bne` branch at 0x284 targets 0x534, is taken when v0(=ret(kopt_find)) != 0, and falls through when v0(=ret(kopt_find)) == 0.
  The `beq` branch at 0x290 targets 0x2b0, is taken when a2(=[sym(showconfig)]) == 0, and falls through when a2(=[sym(showconfig)]) != 0.
  The `beq` branch at 0x298 targets 0x2b0, is taken when s3(=ret(ioc4_is_console)) == 0, and falls through when s3(=ret(ioc4_is_console)) != 0.
  The `beq` branch at 0x2a0 targets 0x5d4 and is always taken.
  The `beq` branch at 0x2b0 targets 0x2e8, is taken when a3(=[sym(showconfig)]) == 0, and falls through when a3(=[sym(showconfig)]) != 0.
  The `beq` branch at 0x2b8 targets 0x2e8, is taken when s3(=ret(ioc4_is_console)) == 0, and falls through when s3(=ret(ioc4_is_console)) != 0.
  The `beq` branch at 0x2c4 targets 0x5a4, is taken when v0(=[ret(kmem_zalloc)+40]) == s4(=0x13), and falls through when v0(=[ret(kmem_zalloc)+40]) != s4(=0x13).
  The `beq` branch at 0x2e0 targets 0x5a4, is taken when (a4(=[[(ret(kmem_zalloc) + ([ret(kmem_zalloc)+40] << 0x3))+24]:8+4]) & 0x1) == 0, and falls through when (a4(=[[(ret(kmem_zalloc) + ([ret(kmem_zalloc)+40] << 0x3))+24]:8+4]) & 0x1) != 0.
  The `beq` branch at 0x2ec targets 0x518, is taken when a2(=[ret(kmem_zalloc)+44]) == s4(=0x13), and falls through when a2(=[ret(kmem_zalloc)+44]) != s4(=0x13).
  The `beq` branch at 0x30c targets 0x3e8, is taken when a2(=[ret(kmem_zalloc)+44]) == s4(=0x13), and falls through when a2(=[ret(kmem_zalloc)+44]) != s4(=0x13).
  The `beq` branch at 0x340 targets 0x3e8, is taken when v0(=ret(data_check)) == 0, and falls through when v0(=ret(data_check)) != 0.
  The `beq` branch at 0x358 targets 0x52c, is taken when v0(=[ret(kmem_zalloc)+92]) == t8(=0x3), and falls through when v0(=[ret(kmem_zalloc)+92]) != t8(=0x3).
  The `beq` branch at 0x360 targets 0x52c, is taken when v0(=[ret(kmem_zalloc)+92]) == a0(=0x4), and falls through when v0(=[ret(kmem_zalloc)+92]) != a0(=0x4).
  The `beq` branch at 0x3d4 targets 0x3e8, is taken when a4(=[sym(showconfig)]) == 0, and falls through when a4(=[sym(showconfig)]) != 0.
  The `bne` branch at 0x3dc targets 0x5bc, is taken when s3(=ret(ioc4_is_console)) != 0, and falls through when s3(=ret(ioc4_is_console)) == 0.
  The `beq` branch at 0x3e8 targets 0x424, is taken when a5(=[sym(showconfig)]) == 0, and falls through when a5(=[sym(showconfig)]) != 0.
  The `beq` branch at 0x3f0 targets 0x424, is taken when s3(=ret(ioc4_is_console)) == 0, and falls through when s3(=ret(ioc4_is_console)) != 0.
  The `beq` branch at 0x3fc targets 0x588, is taken when a2(=[ret(kmem_zalloc)+44]) == s4(=0x13), and falls through when a2(=[ret(kmem_zalloc)+44]) != s4(=0x13).
  The `beq` branch at 0x418 targets 0x588, is taken when (a6(=[[(ret(kmem_zalloc) + ([ret(kmem_zalloc)+44] << 0x3))+24]:8+4]) & 0x1) == 0, and falls through when (a6(=[[(ret(kmem_zalloc) + ([ret(kmem_zalloc)+44] << 0x3))+24]:8+4]) & 0x1) != 0.
  The `beq` branch at 0x4ec targets 0x4d8 and is always taken.
  The `beq` branch at 0x4f4 targets 0x2ac and is always taken.
  The `beq` branch at 0x4fc targets 0x2ac and is always taken.
  The `beq` branch at 0x508 targets 0x56c, is taken when a0(=[ret(kmem_zalloc)+44]) == 0, and falls through when a0(=[ret(kmem_zalloc)+44]) != 0.
  The `beq` branch at 0x510 targets 0x19c and is always taken.
  The `beq` branch at 0x51c targets 0x574, is taken when a1(=[ret(kmem_zalloc)+40]) == s2(=0x1), and falls through when a1(=[ret(kmem_zalloc)+40]) != s2(=0x1).
  The `beq` branch at 0x524 targets 0x2fc and is always taken.
  The `beq` branch at 0x52c targets 0x36c and is always taken.
  The `beq` branch at 0x540 targets 0x57c, is taken when v0(=ret(strstr)) == 0, and falls through when v0(=ret(strstr)) != 0.
  The `bne` branch at 0x548 targets 0x558, is taken when s3(=ret(ioc4_is_console)) != 0, and falls through when s3(=ret(ioc4_is_console)) == 0.
  The `beq` branch at 0x550 targets 0x28c and is always taken.
  The `beq` branch at 0x564 targets 0x28c and is always taken.
  The `beq` branch at 0x56c targets 0x19c and is always taken.
  The `beq` branch at 0x574 targets 0x2fc and is always taken.
  The `beq` branch at 0x57c targets 0x28c and is always taken.
  The `beq` branch at 0x598 targets 0x424 and is always taken.
  The `beq` branch at 0x5b4 targets 0x2ec and is always taken.
  The `beq` branch at 0x5cc targets 0x3e8 and is always taken.
  The `beq` branch at 0x5e4 targets 0x2b0 and is always taken.
  The return at 0x4e4 has v0 = one of -0x1, 0x0.
  The instructions from 0x584 to 0x584 are not reached by any path from the entry, and their branches are not listed.
  The instructions from 0x5a0 to 0x5a0 are not reached by any path from the entry, and their branches are not listed.

- `pckm_open` in `IP35/usr/cpu/sysgen/IP35boot/ioc4_pckm.o` at 0x5ec (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc4_pckm.o`.
  Range: 0x5ec-0x7a0 (436 bytes).
  It occupies 436 bytes.
  The `lw` at 0x628 loads 4 bytes from a1 (arg1 at entry) +0x0.
  3 such `lw` accesses load 4 bytes from ret(hwgraph_fastinfo_get) +0x50, including `lw` at 0x65c, `lw` at 0x6c8, `lw` at 0x794.
  2 such `lw` accesses load 4 bytes from ret(hwgraph_fastinfo_get) +0x4, including `lw` at 0x668, `lw` at 0x71c.
  The `sd` at 0x698 stores 8 bytes to a0 (arg0 at entry) +0x28.
  The `sd` at 0x69c stores 8 bytes to ret(WR) +0x28.
  7 such `ld` accesses load 8 bytes from ret(hwgraph_fastinfo_get) +0x48, including `ld` at 0x6a0, `ld` at 0x6b8, `ld` at 0x6c0.
  The `sd` at 0x6a8 stores 8 bytes to ret(hwgraph_fastinfo_get) +0x20.
  The `sd` at 0x6ac stores 8 bytes to ret(hwgraph_fastinfo_get) +0x28.
  The `sw` at 0x6bc stores 4 bytes to [ret(hwgraph_fastinfo_get)+72]:8 +0x34.
  The `lw` at 0x6c4 loads 4 bytes from [ret(hwgraph_fastinfo_get)+72]:8 +0x28.
  The `lw` at 0x6d4 loads 4 bytes from [ret(hwgraph_fastinfo_get)+72]:8 +0x2c.
  The `lw` at 0x6ec loads 4 bytes from [ret(hwgraph_fastinfo_get)+72]:8 +0x5c.
  3 such `sw` accesses store 4 bytes to ret(hwgraph_fastinfo_get) +0x8, including `sw` at 0x704, `sw` at 0x788, `sw` at 0x79c.
  2 such `sw` accesses store 4 bytes to ret(hwgraph_fastinfo_get) +0xc, including `sw` at 0x70c, `sw` at 0x77c.
  The `sw` at 0x72c stores 4 bytes to ret(hwgraph_fastinfo_get) +0x4.
  The `lw` at 0x76c loads 4 bytes from [ret(hwgraph_fastinfo_get)+72]:8 +0x34.
  The `jal` at 0x600 calls WR with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x648 calls hwgraph_fastinfo_get with a0=[a1], a1=?, a2=?, a3=ret(WR), a5=-0x1.
  The `jal` at 0x6b0 calls mutex_lock with a0=[ret(hwgraph_fastinfo_get)+72]:8+72, a1=0x19, a2=ret(WR), a3=a0 at entry (arg0).
  The `jal` at 0x6e0 calls default_ms_setting with a0=ret(hwgraph_fastinfo_get), a1=?, a2=?, a3=?, a6=[[ret(hwgraph_fastinfo_get)+72]:8+44].
  The `jal` at 0x710 calls pckm_reinit_lock with a0=ret(hwgraph_fastinfo_get), a1=0x3, a2=?, a3=?.
  The `jal` at 0x728 calls mutex_unlock with a0=[ret(hwgraph_fastinfo_get)+72]:8+72, a1=([ret(hwgraph_fastinfo_get)+4] | 0x2), a2=?, a3=?.
  The `jal` at 0x758 calls pckm_pollcmd with a0=ret(hwgraph_fastinfo_get), a1=0xed, a2=?, a3=?, a4=[[ret(hwgraph_fastinfo_get)+72]:8+40], a5=[ret(hwgraph_fastinfo_get)+72]:8.
  The `jal` at 0x768 calls pckm_pollcmd with a0=ret(hwgraph_fastinfo_get), a1=[[ret(hwgraph_fastinfo_get)+72]:8+52], a2=?, a3=?.
  The `jal` at 0x784 calls pckm_pollcmd with a0=ret(hwgraph_fastinfo_get), a1=0xf8, a2=0xc, a3=0x2.
  The `beq` branch at 0x608 targets 0x624, is taken when s3(=a3) == 0, and falls through when s3(=a3) != 0.
  The `bne` branch at 0x638 targets 0x680, is taken when (at(?) & 0x1ff) != 0, and falls through when (at(?) & 0x1ff) == 0.
  The `beq` branch at 0x640 targets 0x688, is taken when a0(=[a1]) == a5(=-0x1), and falls through when a0(=[a1]) != a5(=-0x1).
  The `beq` branch at 0x650 targets 0x73c, is taken when v0(=ret(hwgraph_fastinfo_get)) == 0, and falls through when v0(=ret(hwgraph_fastinfo_get)) != 0.
  The `beq` branch at 0x660 targets 0x748, is taken when a1(=[ret(hwgraph_fastinfo_get)+80]) == a2(=0x13), and falls through when a1(=[ret(hwgraph_fastinfo_get)+80]) != a2(=0x13).
  The `beq` branch at 0x670 targets 0x690, is taken when (a3(=[ret(hwgraph_fastinfo_get)+4]) & 0x2) == 0, and falls through when (a3(=[ret(hwgraph_fastinfo_get)+4]) & 0x2) != 0.
  The `beq` branch at 0x678 targets 0x614 and is always taken.
  The `beq` branch at 0x680 targets 0x614 and is always taken.
  The `beq` branch at 0x688 targets 0x618 and is always taken.
  The `beq` branch at 0x6cc targets 0x754, is taken when a4(=[[ret(hwgraph_fastinfo_get)+72]:8+40]) == a0(=[ret(hwgraph_fastinfo_get)+80]), and falls through when a4(=[[ret(hwgraph_fastinfo_get)+72]:8+40]) != a0(=[ret(hwgraph_fastinfo_get)+80]).
  The `bne` branch at 0x6d8 targets 0x71c, is taken when a6(=[[ret(hwgraph_fastinfo_get)+72]:8+44]) != a0(=[ret(hwgraph_fastinfo_get)+80]), and falls through when a6(=[[ret(hwgraph_fastinfo_get)+72]:8+44]) == a0(=[ret(hwgraph_fastinfo_get)+80]).
  The `beq` branch at 0x6f4 targets 0x798, is taken when v0(=[[ret(hwgraph_fastinfo_get)+72]:8+92]) == a1(=0x3), and falls through when v0(=[[ret(hwgraph_fastinfo_get)+72]:8+92]) != a1(=0x3).
  The `beq` branch at 0x6fc targets 0x798, is taken when v0(=[[ret(hwgraph_fastinfo_get)+72]:8+92]) == a0(=0x4), and falls through when v0(=[[ret(hwgraph_fastinfo_get)+72]:8+92]) != a0(=0x4).
  The `beq` branch at 0x734 targets 0x614 and is always taken.
  The `beq` branch at 0x740 targets 0x614 and is always taken.
  The `beq` branch at 0x74c targets 0x614 and is always taken.
  The `beq` branch at 0x790 targets 0x6d4 and is always taken.
  The `beq` branch at 0x798 targets 0x708 and is always taken.
  The return at 0x61c has v0 = one of 0x0, 0x6, 0x10, 0x13.

- `pckm_close` in `IP35/usr/cpu/sysgen/IP35boot/ioc4_pckm.o` at 0x7a0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc4_pckm.o`.
  Range: 0x7a0-0x884 (228 bytes).
  It occupies 228 bytes.
  The `ld` at 0x7a8 loads 8 bytes from a0 (arg0 at entry) +0x28.
  4 such `ld` accesses load 8 bytes from [a0+40]:8 +0x48, including `ld` at 0x7b0, `ld` at 0x828, `ld` at 0x840.
  2 such `lw` accesses load 4 bytes from [a0+40]:8 +0x4, including `lw` at 0x7c4, `lw` at 0x7dc.
  The `lw` at 0x7d8 loads 4 bytes from [a0+40]:8 +0x10.
  2 such `sw` accesses store 4 bytes to [a0+40]:8 +0x4, including `sw` at 0x7f0, `sw` at 0x804.
  The `ld` at 0x80c loads 8 bytes from [a0+40]:8 +0x30.
  The `ld` at 0x810 loads 8 bytes from [a0+40]:8 +0x40.
  The `sd` at 0x818 stores 8 bytes to [a0+40]:8 +0x30.
  The `lw` at 0x81c loads 4 bytes from [a0+40]:8 +0x50.
  The `sd` at 0x820 stores 8 bytes to [a0+40]:8 +0x20.
  The `sd` at 0x824 stores 8 bytes to [a0+40]:8 +0x28.
  The `sd` at 0x82c stores 8 bytes to [a0+40]:8 +0x40.
  The `lw` at 0x830 loads 4 bytes from [[a0+40]:8+72]:8 +0x2c.
  The `sw` at 0x83c stores 4 bytes to [[a0+40]:8+72]:8 +0x34.
  The `lw` at 0x850 loads 4 bytes from [[a0+40]:8+72]:8 +0x34.
  The `jal` at 0x7bc calls mutex_lock with a0=[[a0+40]:8+72]:8+72, a1=0x19, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x7d4 calls untimeout with a0=[[a0+40]:8+16], a1=?, a2=[[a0+40]:8+4], a3=?, a5=-0x13.
  The `jal` at 0x800 calls str_unbcall with a0=a0 at entry (arg0), a1=?, a2=?, a3=?, a5=-0x13.
  The `jal` at 0x808 calls freemsg with a0=[[a0+40]:8+48]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x814 calls freemsg with a0=[[a0+40]:8+64]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x84c calls default_kbd_setting with a0=[a0+40]:8, a1=0x0, a2=[[[a0+40]:8+72]:8+52], a3=?, a4=[[a0+40]:8+72]:8, a7=[[[a0+40]:8+72]:8+44].
  The `jal` at 0x85c calls pckm_pollcmd with a0=[a0+40]:8, a1=0xff, a2=?, a3=?, a4=[[a0+40]:8+72]:8, a7=[[[a0+40]:8+72]:8+44].
  The `jal` at 0x868 calls mutex_unlock with a0=[[a0+40]:8+72]:8+72, a1=?, a2=?, a3=?.
  The `beq` branch at 0x7cc targets 0x7e4, is taken when (a2(=[[a0+40]:8+4]) & 0x10) == 0, and falls through when (a2(=[[a0+40]:8+4]) & 0x10) != 0.
  The `beq` branch at 0x7ec targets 0x808, is taken when (a2(?) & 0x8) == 0, and falls through when (a2(?) & 0x8) != 0.
  The `beq` branch at 0x834 targets 0x85c, is taken when a7(=[[[a0+40]:8+72]:8+44]) == t0(=[[a0+40]:8+80]), and falls through when a7(=[[[a0+40]:8+72]:8+44]) != t0(=[[a0+40]:8+80]).
  The `beq` branch at 0x854 targets 0x864 and is always taken.
  The return at 0x87c has v0 = 0x0.

- `pckm_wput` in `IP35/usr/cpu/sysgen/IP35boot/ioc4_pckm.o` at 0x884 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc4_pckm.o`.
  Range: 0x884-0xc40 (956 bytes).
  It occupies 956 bytes.
  The `ld` at 0x88c loads 8 bytes from a0 (arg0 at entry) +0x28.
  18 such `ld` accesses load 8 bytes from [a0+40]:8 +0x48, including `ld` at 0x898, `ld` at 0x8dc, `ld` at 0x960.
  2 such `ld` accesses load 8 bytes from a1 (arg1 at entry) +0x28, including `ld` at 0x8b4, `ld` at 0xb84.
  The `lbu` at 0x8b8 loads 1 byte from [a1+40]:8 +0x1e.
  9 such `ld` accesses load 8 bytes from a1 (arg1 at entry) +0x18, including `ld` at 0x8fc, `ld` at 0x920, `ld` at 0x988.
  6 such `lbu` accesses load 1 byte from [a1+24]:8 +0x0, including `lbu` at 0x900, `lbu` at 0x924, `lbu` at 0x99c.
  The `sb` at 0x944 stores 1 byte to [a1+24]:8 +0x0.
  4 such `ld` accesses load 8 bytes from a1 (arg1 at entry) +0x20, including `ld` at 0x98c, `ld` at 0xa28, `ld` at 0xae4.
  5 such `lw` accesses load 4 bytes from [[a0+40]:8+72]:8 +0x28, including `lw` at 0x9c8, `lw` at 0xa3c, `lw` at 0xae0.
  The `ld` at 0x9e4 loads 8 bytes from ([[a0+40]:8+72]:8 + ([[[a0+40]:8+72]:8+40] << 0x3)) +0x18.
  3 such `lw` accesses load 4 bytes from [[a0+40]:8+72]:8 +0x2c, including `lw` at 0xa00, `lw` at 0xa4c, `lw` at 0xa98.
  The `ld` at 0xa18 loads 8 bytes from ([[a0+40]:8+72]:8 + ([[[a0+40]:8+72]:8+44] << 0x3)) +0x18.
  3 such `sd` accesses store 8 bytes to a1 (arg1 at entry) +0x18, including `sd` at 0xa24, `sd` at 0xa6c, `sd` at 0xb64.
  4 such `lw` accesses load 4 bytes from [a0+40]:8 +0x50, including `lw` at 0xa50, `lw` at 0xa9c, `lw` at 0xc00.
  The `lbu` at 0xa60 loads 1 byte from ?.
  The `lw` at 0xa84 loads 4 bytes from [a1+24]:8 +0x0.
  3 such `sd` accesses store 8 bytes to a1 (arg1 at entry) +0x20, including `sd` at 0xaf4, `sd` at 0xb30, `sd` at 0xba4.
  The `lw` at 0xafc loads 4 bytes from [[a0+40]:8+72]:8 +0x58.
  3 such `sb` accesses store 1 byte to [a1+32]:8 +0x0, including `sb` at 0xb00, `sb` at 0xb3c, `sb` at 0xbac.
  The `lw` at 0xb38 loads 4 bytes from [[a0+40]:8+72]:8 +0x5c.
  2 such `lw` accesses load 4 bytes from [a0+40]:8 +0x0, including `lw` at 0xb74, `lw` at 0xc28.
  The `lw` at 0xb78 loads 4 bytes from [a0+40]:8 +0x54.
  The `sb` at 0xb98 stores 1 byte to [a1+40]:8 +0x1e.
  The `sw` at 0xc3c stores 4 bytes to [a0+40]:8 +0x54.
  The `jal` at 0x8ac calls mutex_lock with a0=[[a0+40]:8+72]:8+72, a1=0x19, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x8e0 calls mutex_unlock with a0=[[a0+40]:8+72]:8+72, a1=0x86, a2=?, a3=?.
  The `jal` at 0x8ec calls sdrv_error with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0x918 calls flushq with a0=a0 at entry (arg0), a1=0x0, a2=?, a3=?.
  The `jal` at 0x940 calls RD with a0=a0 at entry (arg0), a1=[[a1+24]:8]:1, a2=?, a3=?.
  The `jal` at 0x94c calls flushq with a0=ret(RD), a1=0x1, a2=?, a3=?.
  The `jal` at 0x958 calls qreply with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0x964 calls mutex_unlock with a0=[[a0+40]:8+72]:8+72, a1=?, a2=?, a3=?.
  The `jal` at 0x9e0 calls pckm_reinit_lock with a0=[([[a0+40]:8+72]:8 + ([[[a0+40]:8+72]:8+40] << 0x3))+24]:8, a1=[[a1+24]:8]:1, a2=?, a3=0xfa, a4=[[[a0+40]:8+72]:8+40], a5=[[a0+40]:8+72]:8, a6=0x13.
  The `jal` at 0xa14 calls pckm_reinit_lock with a0=[([[a0+40]:8+72]:8 + ([[[a0+40]:8+72]:8+44] << 0x3))+24]:8, a1=[[a0+40]:8+72]:8, a2=?, a3=0x13, a4=[[[a0+40]:8+72]:8+44].
  The `jal` at 0xa5c calls ioc4_lcl_pckm_setleds_lock with a0=[a0+40]:8, a1=?, a2=?, a3=?, a5=[[[a0+40]:8+72]:8+40], a6=0x13, a7=[[[a0+40]:8+72]:8+44].
  The `jal` at 0xa70 calls freemsg with a0=a1 at entry (arg1), a1=?, a2=?, a3=?.
  The `jal` at 0xab8 calls freemsg with a0=a1 at entry (arg1), a1=?, a2=?, a3=?.
  The `jal` at 0xb08 calls qreply with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0xb18 calls freemsg with a0=a1 at entry (arg1), a1=[[a1+24]:8]:1, a2=?, a3=?.
  The `jal` at 0xb44 calls qreply with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=[a1+32]:8+1, a3=?.
  The `jal` at 0xb70 calls device_controller_num_get with a0=[[a0+40]:8], a1=?, a2=?, a3=?.
  The `jal` at 0xb94 calls qreply with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?, a5=0x81, a6=[a1+40]:8.
  The `jal` at 0xbb0 calls pckm_pollcmd with a0=[a0+40]:8, a1=0xfa, a2=0xfc, a3=0xfa, a5=[a1+32]:8.
  The `jal` at 0xbbc calls pckm_pollcmd with a0=[a0+40]:8, a1=0xfc, a2=?, a3=?.
  The `jal` at 0xbc8 calls pckm_pollcmd with a0=[a0+40]:8, a1=0x14, a2=?, a3=?.
  The `jal` at 0xbd4 calls pckm_pollcmd with a0=[a0+40]:8, a1=0xfc, a2=?, a3=?.
  The `jal` at 0xbe0 calls pckm_pollcmd with a0=[a0+40]:8, a1=0x76, a2=?, a3=?.
  The `jal` at 0xbec calls pckm_pollcmd with a0=[a0+40]:8, a1=0xf4, a2=?, a3=?.
  The `jal` at 0xc0c calls pckm_rmalias with a0=[[a0+40]:8+84], a1=?, a2=[[a0+40]:8+80], a3=?.
  The `jal` at 0xc2c calls ioc_pckm_add_hwgraph_alias with a0=[[a0+40]:8], a1=ret(device_controller_num_get), a2=?, a3=[[a0+40]:8+80].
  The `beq` branch at 0x8bc targets 0x988, is taken when v0(=[[a1+40]:8+30]:1) == 0, and falls through when v0(=[[a1+40]:8+30]:1) != 0.
  The `beq` branch at 0x8c4 targets 0xa80, is taken when v0(=[[a1+40]:8+30]:1) == v1(=0xe), and falls through when v0(=[[a1+40]:8+30]:1) != v1(=0xe).
  The `beq` branch at 0x8cc targets 0xac8, is taken when v0(=[[a1+40]:8+30]:1) == a0(=0xd), and falls through when v0(=[[a1+40]:8+30]:1) != a0(=0xd).
  The `beq` branch at 0x8d4 targets 0x8fc, is taken when v0(=[[a1+40]:8+30]:1) == a1(=0x86), and falls through when v0(=[[a1+40]:8+30]:1) != a1(=0x86).
  The `beq` branch at 0x8f4 targets 0x970 and is always taken.
  The `beq` branch at 0x90c targets 0x930, is taken when (a0(=[[a1+24]:8]:1) & 0x2) == 0, and falls through when (a0(=[[a1+24]:8]:1) & 0x2) != 0.
  The `beq` branch at 0x930 targets 0xb18, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0x994 targets 0xa30, is taken when a0(=[a1+24]:8) >= a5(=[a1+32]:8) (unsigned), and falls through when a0(=[a1+24]:8) < a5(=[a1+32]:8) (unsigned).
  The `beq` branch at 0x9a4 targets 0xb54, is taken when a1(=[[a1+24]:8]:1) == a2(=0xfc), and falls through when a1(=[[a1+24]:8]:1) != a2(=0xfc).
  The `beq` branch at 0x9b0 targets 0xbb0, is taken when a1(=[[a1+24]:8]:1) == a3(=0xfa), and falls through when a1(=[[a1+24]:8]:1) != a3(=0xfa).
  The `beq` branch at 0x9bc targets 0x9f4, is taken when (a1(=[[a1+24]:8]:1) & 0x1) == 0, and falls through when (a1(=[[a1+24]:8]:1) & 0x1) != 0.
  The `beq` branch at 0x9d0 targets 0x9f4, is taken when a4(=[[[a0+40]:8+72]:8+40]) == a6(=0x13), and falls through when a4(=[[[a0+40]:8+72]:8+40]) != a6(=0x13).
  The `beq` branch at 0x9f4 targets 0xa20, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0xa08 targets 0xa20, is taken when a4(=[[[a0+40]:8+72]:8+44]) == a3(=0x13), and falls through when a4(=[[[a0+40]:8+72]:8+44]) != a3(=0x13).
  The `beq` branch at 0xa30 targets 0xa70, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0xa44 targets 0xa70, is taken when a5(=[[[a0+40]:8+72]:8+40]) == a6(=0x13), and falls through when a5(=[[[a0+40]:8+72]:8+40]) != a6(=0x13).
  The `beq` branch at 0xa54 targets 0xa70, is taken when a7(=[[[a0+40]:8+72]:8+44]) == t0(=[[a0+40]:8+80]), and falls through when a7(=[[[a0+40]:8+72]:8+44]) != t0(=[[a0+40]:8+80]).
  The `beq` branch at 0xa78 targets 0x964 and is always taken.
  The `beq` branch at 0xa8c targets 0xb70, is taken when t2(=[[a1+24]:8]) == t3(=0x7001), and falls through when t2(=[[a1+24]:8]) != t3(=0x7001).
  The `bne` branch at 0xaa0 targets 0xab8, is taken when t8(=[[[a0+40]:8+72]:8+44]) != t9(=[[a0+40]:8+80]), and falls through when t8(=[[[a0+40]:8+72]:8+44]) == t9(=[[a0+40]:8+80]).
  The `beq` branch at 0xab0 targets 0xb28, is taken when t9(=[[a1+24]:8]:1) == ra(=0x12), and falls through when t9(=[[a1+24]:8]:1) != ra(=0x12).
  The `beq` branch at 0xac0 targets 0x964 and is always taken.
  The `bne` branch at 0xad4 targets 0x960, is taken when at(=[[a1+24]:8]:1) != v0(=0xde), and falls through when at(=[[a1+24]:8]:1) == v0(=0xde).
  The `beq` branch at 0xaec targets 0xba4, is taken when v0(=[[[a0+40]:8+72]:8+40]) == a1(=0x13), and falls through when v0(=[[[a0+40]:8+72]:8+40]) != a1(=0x13).
  The `beq` branch at 0xb10 targets 0x964 and is always taken.
  The `beq` branch at 0xb20 targets 0x964 and is always taken.
  The `beq` branch at 0xb4c targets 0x964 and is always taken.
  The `bne` branch at 0xb58 targets 0xa30, is taken when a3(?) < 0x2 (signed), and falls through when a3(?) >= 0x2 (signed).
  The `beq` branch at 0xb68 targets 0xa30 and is always taken.
  The `bne` branch at 0xb7c targets 0xbfc, is taken when v0(=ret(device_controller_num_get)) != a0(=[[a0+40]:8+84]), and falls through when v0(=ret(device_controller_num_get)) == a0(=[[a0+40]:8+84]).
  The `beq` branch at 0xb9c targets 0x964 and is always taken.
  The `beq` branch at 0xba8 targets 0xb04 and is always taken.
  The `beq` branch at 0xbf4 targets 0xa28 and is always taken.
  The `beq` branch at 0xc38 targets 0xb84 and is always taken.
  The return at 0x980 has v0 = 0x0.

- `pckm_getbp` in `IP35/usr/cpu/sysgen/IP35boot/ioc4_pckm.o` at 0xc40 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc4_pckm.o`.
  Range: 0xc40-0xd4c (268 bytes).
  It occupies 268 bytes.
  The `ld` at 0xc4c loads 8 bytes from a0 (arg0 at entry) +0x40.
  2 such `ld` accesses load 8 bytes from [a0+64]:8 +0x20, including `ld` at 0xc6c, `ld` at 0xcbc.
  The `ld` at 0xc70 loads 8 bytes from [a0+64]:8 +0x18.
  2 such `ld` accesses load 8 bytes from [a0+64]:8 +0x28, including `ld` at 0xc80, `ld` at 0xcc0.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x8, including `lw` at 0xc88, `lw` at 0xc98, `lw` at 0xd28.
  The `ld` at 0xcc4 loads 8 bytes from [[a0+64]:8+40]:8 +0x10.
  2 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x40, including `sd` at 0xd08, `sd` at 0xd48.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x4, including `lw` at 0xd0c, `lw` at 0xd34.
  The `ld` at 0xd1c loads 8 bytes from a0 (arg0 at entry) +0x20.
  The `sw` at 0xd40 stores 4 bytes to a0 (arg0 at entry) +0x4.
  The `jal` at 0xc9c calls allocb with a0=[a0+8], a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0xcfc calls str_conmsg with a0=a0+48, a1=a0+56, a2=[a0+64]:8, a3=?.
  The `jal` at 0xd24 calls str_allocb with a0=[a0+8], a1=[a0+32]:8, a2=0x3, a3=?.
  The `beq` branch at 0xc64 targets 0xc84, is taken when s2(=[a0+64]:8) == 0, and falls through when s2(=[a0+64]:8) != 0.
  The `bne` branch at 0xc74 targets 0xc84, is taken when at(=[[a0+64]:8+24]:8) != v0(=[[a0+64]:8+32]:8), and falls through when at(=[[a0+64]:8+24]:8) == v0(=[[a0+64]:8+32]:8).
  The `beq` branch at 0xc7c targets 0xcc4 and is always taken.
  The `beq` branch at 0xc84 targets 0xc9c and is always taken.
  The `bne` branch at 0xc90 targets 0xd0c, is taken when v0(=0x3) != s3(=a1), and falls through when v0(=0x3) == s3(=a1).
  The `beq` branch at 0xca4 targets 0xc8c, is taken when v0(=ret(allocb)) == 0, and falls through when v0(=ret(allocb)) != 0.
  The `beq` branch at 0xcac targets 0xd44, is taken when s2(=[a0+64]:8) == 0, and falls through when s2(=[a0+64]:8) != 0.
  The `bne` branch at 0xcb4 targets 0xcf8, is taken when s1(?) != 0, and falls through when s1(?) == 0.
  The `beq` branch at 0xccc targets 0xcf8, is taken when v0(=[[a0+64]:8+32]:8) >= v1(=[[[a0+64]:8+40]:8+16]:8) (unsigned), and falls through when v0(=[[a0+64]:8+32]:8) < v1(=[[[a0+64]:8+40]:8+16]:8) (unsigned).
  The `beq` branch at 0xd04 targets 0xcd4 and is always taken.
  The `bne` branch at 0xd14 targets 0xcac, is taken when (a0(=[a0+4]) & 0x8) != 0, and falls through when (a0(=[a0+4]) & 0x8) == 0.
  The `bne` branch at 0xd2c targets 0xcac, is taken when v0(=ret(str_allocb)) != 0, and falls through when v0(=ret(str_allocb)) == 0.
  The `bne` branch at 0xd3c targets 0xcb4, is taken when s2(=[a0+64]:8) != 0, and falls through when s2(=[a0+64]:8) == 0.
  The `beq` branch at 0xd44 targets 0xcd4 and is always taken.
  The return at 0xcec has v0 = ?.
  The instructions from 0xcf4 to 0xcf4 are not reached by any path from the entry, and their branches are not listed.

- `pckm_rsrv_timer` in `IP35/usr/cpu/sysgen/IP35boot/ioc4_pckm.o` at 0xd4c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc4_pckm.o`.
  Range: 0xd4c-0xd90 (68 bytes).
  It occupies 68 bytes.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x48, including `ld` at 0xd58, `ld` at 0xd74.
  The `jal` at 0xd64 calls mutex_lock with a0=[a0+72]:8+72, a1=0x19, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xd6c calls pckm_rsrv_timer_lock with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xd78 calls mutex_unlock with a0=[a0+72]:8+72, a1=?, a2=?, a3=?.
  The return at 0xd88 has v0 = ret(mutex_unlock).

- `pckm_rsrv_timer_lock` in `IP35/usr/cpu/sysgen/IP35boot/ioc4_pckm.o` at 0xd90 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc4_pckm.o`.
  Range: 0xd90-0xe14 (132 bytes).
  It occupies 132 bytes.
  The `lw` at 0xd90 loads 4 bytes from a0 (arg0 at entry) +0x4.
  The `ld` at 0xdac loads 8 bytes from a0 (arg0 at entry) +0x20.
  The `ld` at 0xdb0 loads 8 bytes from [a0+32]:8 +0x38.
  The `lw` at 0xdd0 loads 4 bytes from a0 (arg0 at entry) +0xc.
  The `sw` at 0xddc stores 4 bytes to a0 (arg0 at entry) +0x10.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x4, including `sw` at 0xdf8, `sw` at 0xe10.
  The `jal` at 0xdd4 calls streams_timeout with a0=sym(streams_monp), a1=sym(pckm_rsrv_timer), a2=[a0+12], a3=a0 at entry (arg0), a4=0x0, a5=0x0.
  The `jal` at 0xdf4 calls qenable with a0=[a0+32]:8, a1=a1 at entry (arg1), a2=[a0+4], a3=a3 at entry (arg3).
  The `beq` branch at 0xda4 targets 0xe04, is taken when (a2(=[a0+4]) & 0x2) == 0, and falls through when (a2(=[a0+4]) & 0x2) != 0.
  The `beq` branch at 0xdb8 targets 0xdf0, is taken when (v0(=[[a0+32]:8+56]:8) & 0x40) == 0, and falls through when (v0(=[[a0+32]:8+56]:8) & 0x40) != 0.
  The `beq` branch at 0xdfc targets 0xde4 and is always taken.
  The `beq` branch at 0xe0c targets 0xde0 and is always taken.
  The return at 0xde8 has v0 = one of ?, ret(qenable).

- `pckm_rsrv` in `IP35/usr/cpu/sysgen/IP35boot/ioc4_pckm.o` at 0xe14 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc4_pckm.o`.
  Range: 0xe14-0xf64 (336 bytes).
  It occupies 336 bytes.
  The `ld` at 0xe1c loads 8 bytes from a0 (arg0 at entry) +0x28.
  6 such `ld` accesses load 8 bytes from [a0+40]:8 +0x48, including `ld` at 0xe28, `ld` at 0xebc, `ld` at 0xee0.
  The `ld` at 0xe40 loads 8 bytes from a0 (arg0 at entry) +0x18.
  2 such `lw` accesses load 4 bytes from [a0+40]:8 +0x4, including `lw` at 0xe54, `lw` at 0xe9c.
  The `sw` at 0xe70 stores 4 bytes to [a0+40]:8 +0x4.
  2 such `ld` accesses load 8 bytes from [a0+40]:8 +0x40, including `ld` at 0xe74, `ld` at 0xf10.
  The `ld` at 0xe80 loads 8 bytes from [[a0+40]:8+64]:8 +0x20.
  The `ld` at 0xe84 loads 8 bytes from [[a0+40]:8+64]:8 +0x18.
  3 such `ld` accesses load 8 bytes from [a0+40]:8 +0x30, including `ld` at 0xe90, `ld` at 0xf18, `ld` at 0xf60.
  The `sd` at 0xee4 stores 8 bytes to [a0+40]:8 +0x30.
  The `sd` at 0xf54 stores 8 bytes to [a0+40]:8 +0x40.
  The `jal` at 0xe34 calls mutex_lock with a0=[[a0+40]:8+72]:8+72, a1=0x19, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xe3c calls canput with a0=[a0+24]:8, a1=?, a2=?, a3=?.
  The `jal` at 0xe4c calls enableok with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xe6c calls str_unbcall with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xec0 calls mutex_unlock with a0=[[a0+40]:8+72]:8+72, a1=?, a2=?, a3=?.
  The `jal` at 0xee8 calls mutex_unlock with a0=[[a0+40]:8+72]:8+72, a1=[[a0+40]:8+48]:8, a2=?, a3=?.
  The `jal` at 0xef4 calls putnext with a0=a0 at entry (arg0), a1=[[a0+40]:8+48]:8, a2=?, a3=?.
  The `jal` at 0xf04 calls mutex_lock with a0=[[a0+40]:8+72]:8+72, a1=0x19, a2=?, a3=?.
  The `jal` at 0xf1c calls noenable with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xf28 calls mutex_unlock with a0=[[a0+40]:8+72]:8+72, a1=?, a2=?, a3=?.
  The `jal` at 0xf38 calls pckm_getbp with a0=[a0+40]:8, a1=0x1, a2=?, a3=?.
  The `jal` at 0xf4c calls str_conmsg with a0=[a0+40]:8+48, a1=[a0+40]:8+56, a2=[[a0+40]:8+64]:8, a3=?, a4=[[[a0+40]:8+64]:8+32]:8.
  The `beq` branch at 0xe44 targets 0xf1c, is taken when v0(=ret(canput)) == 0, and falls through when v0(=ret(canput)) != 0.
  The `beq` branch at 0xe5c targets 0xe74, is taken when (v0(=[[a0+40]:8+4]) & 0x8) == 0, and falls through when (v0(=[[a0+40]:8+4]) & 0x8) != 0.
  The `beq` branch at 0xe78 targets 0xf14, is taken when a2(=[[a0+40]:8+64]:8) == 0, and falls through when a2(=[[a0+40]:8+64]:8) != 0.
  The `beq` branch at 0xe8c targets 0xeac, is taken when a3(=[[[a0+40]:8+64]:8+24]:8) >= a4(=[[[a0+40]:8+64]:8+32]:8) (unsigned), and falls through when a3(=[[[a0+40]:8+64]:8+24]:8) < a4(=[[[a0+40]:8+64]:8+32]:8) (unsigned).
  The `beq` branch at 0xe94 targets 0xf4c, is taken when a1(=[[a0+40]:8+48]:8) == 0, and falls through when a1(=[[a0+40]:8+48]:8) != 0.
  The `beq` branch at 0xea4 targets 0xf4c, is taken when (a5(=[[a0+40]:8+4]) & 0x10) == 0, and falls through when (a5(=[[a0+40]:8+4]) & 0x10) != 0.
  The `bne` branch at 0xeac targets 0xee0, is taken when a1(=[[a0+40]:8+48]:8) != 0, and falls through when a1(=[[a0+40]:8+48]:8) == 0.
  The `beq` branch at 0xeb4 targets 0xf38, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0xf0c targets 0xeb4 and is always taken.
  The `beq` branch at 0xf14 targets 0xeac and is always taken.
  The `beq` branch at 0xf30 targets 0xecc and is always taken.
  The `beq` branch at 0xf40 targets 0xec0 and is always taken.
  The `beq` branch at 0xf5c targets 0xeac and is always taken.
  The return at 0xed8 has v0 = 0x0.
  The instructions from 0xf48 to 0xf48 are not reached by any path from the entry, and their branches are not listed.

- `pckm_reinit` in `IP35/usr/cpu/sysgen/IP35boot/ioc4_pckm.o` at 0xf64 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc4_pckm.o`.
  Range: 0xf64-0xfa8 (68 bytes).
  It occupies 68 bytes.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x48, including `ld` at 0xf70, `ld` at 0xf8c.
  The `jal` at 0xf7c calls mutex_lock with a0=[a0+72]:8+72, a1=0x19, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xf84 calls pckm_reinit_lock with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xf90 calls mutex_unlock with a0=[a0+72]:8+72, a1=?, a2=?, a3=?.
  The return at 0xfa0 has v0 = ret(mutex_unlock).

- `pckm_reinit_lock` in `IP35/usr/cpu/sysgen/IP35boot/ioc4_pckm.o` at 0xfa8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc4_pckm.o`.
  Range: 0xfa8-0x100c (100 bytes).
  It occupies 100 bytes.
  3 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x48, including `ld` at 0xfb4, `ld` at 0xfd8, `ld` at 0xfe8.
  2 such `ld` accesses load 8 bytes from [a0+72]:8 +0x60, including `ld` at 0xfcc, `ld` at 0xff8.
  The `ld` at 0xfdc loads 8 bytes from [a0+72]:8 +0x10.
  The `sw` at 0xfe4 stores 4 bytes to [[a0+72]:8+16]:8 +0xc.
  The `jal` at 0xfc8 calls ioc4_write_ireg with a0=[[a0+72]:8+96]:8, a1=0x40, a2=0x1, a3=0x1.
  The `jal` at 0xfd0 calls pckm_reinit_core with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xff4 calls ioc4_write_ireg with a0=[[a0+72]:8+96]:8, a1=0x40, a2=0x0, a3=0x1.
  The return at 0x1004 has v0 = ret(ioc4_write_ireg).

- `pckm_reinit_core` in `IP35/usr/cpu/sysgen/IP35boot/ioc4_pckm.o` at 0x100c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc4_pckm.o`.
  Range: 0x100c-0x1080 (116 bytes).
  It occupies 116 bytes.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x48, including `ld` at 0x100c, `ld` at 0x1034.
  The `lw` at 0x1010 loads 4 bytes from a0 (arg0 at entry) +0x50.
  The `lw` at 0x1014 loads 4 bytes from [a0+72]:8 +0x28.
  The `lw` at 0x1044 loads 4 bytes from [a0+72]:8 +0x34.
  The `lw` at 0x1048 loads 4 bytes from a0 (arg0 at entry) +0x4.
  The `jal` at 0x102c calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xf5, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1040 calls default_kbd_setting with a0=a0 at entry (arg0), a1=0x0, a2=[[a0+72]:8+52], a3=?.
  The `jal` at 0x1058 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xf8, a2=?, a3=?.
  The `jal` at 0x1068 calls default_ms_setting with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `bne` branch at 0x1024 targets 0x1068, is taken when at(=[[a0+72]:8+40]) != v0(=[a0+80]), and falls through when at(=[[a0+72]:8+40]) == v0(=[a0+80]).
  The `beq` branch at 0x1050 targets 0x1070, is taken when (a3(=[a0+4]) & 0x2) == 0, and falls through when (a3(=[a0+4]) & 0x2) != 0.
  The `beq` branch at 0x1060 targets 0x1074 and is always taken.
  The return at 0x1078 has v0 = one of ret(pckm_pollcmd), ?.

- `default_kbd_setting` in `IP35/usr/cpu/sysgen/IP35boot/ioc4_pckm.o` at 0x1080 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc4_pckm.o`.
  Range: 0x1080-0x1138 (184 bytes).
  It occupies 184 bytes.
  The `jal` at 0x109c calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xed, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x10a8 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=a2 at entry (arg2), a2=?, a3=?.
  The `jal` at 0x10b4 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xf0, a2=?, a3=?.
  The `jal` at 0x10c0 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0x3, a2=?, a3=?.
  The `jal` at 0x10cc calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xfa, a2=?, a3=?.
  The `jal` at 0x10d8 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xfc, a2=?, a3=?.
  The `jal` at 0x10e4 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0x14, a2=?, a3=?.
  The `jal` at 0x10f0 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xfc, a2=?, a3=?.
  The `jal` at 0x1100 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0x76, a2=?, a3=?.
  The `jal` at 0x1128 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xf4, a2=?, a3=?.
  The `beq` branch at 0x110c targets 0x1128, is taken when (s8(=a1) & 0x1) == 0, and falls through when (s8(=a1) & 0x1) != 0.
  The `beq` branch at 0x1130 targets 0x1118 and is always taken.
  The return at 0x1120 has v0 = ret(pckm_pollcmd).

- `default_ms_setting` in `IP35/usr/cpu/sysgen/IP35boot/ioc4_pckm.o` at 0x1138 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc4_pckm.o`.
  Range: 0x1138-0x12ec (436 bytes).
  It occupies 436 bytes.
  5 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x48, including `ld` at 0x1188, `ld` at 0x1248, `ld` at 0x1250.
  3 such `sw` accesses store 4 bytes to [a0+72]:8 +0x5c, including `sw` at 0x118c, `sw` at 0x124c, `sw` at 0x12c8.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x50, including `lw` at 0x1244, `lw` at 0x12c0.
  2 such `lw` accesses load 4 bytes from [a0+72]:8 +0x5c, including `lw` at 0x1254, `lw` at 0x12d0.
  The `jal` at 0x1148 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xe8, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1154 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0x3, a2=?, a3=?.
  The `jal` at 0x1160 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xf4, a2=?, a3=?.
  The `jal` at 0x1194 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xf6, a2=?, a3=?.
  The `jal` at 0x11a0 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xe6, a2=?, a3=?.
  The `jal` at 0x11ac calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xf3, a2=?, a3=?.
  The `jal` at 0x11b8 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0x64, a2=?, a3=?.
  The `jal` at 0x11c4 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xe8, a2=?, a3=?.
  The `jal` at 0x11d0 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0x3, a2=?, a3=?.
  The `jal` at 0x11dc calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xf4, a2=?, a3=?.
  The `jal` at 0x11f8 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xf3, a2=0x2, a3=?.
  The `jal` at 0x1204 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xc8, a2=?, a3=?.
  The `jal` at 0x1210 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xf3, a2=?, a3=?.
  The `jal` at 0x121c calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0x64, a2=?, a3=?.
  The `jal` at 0x1228 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xf3, a2=?, a3=?.
  The `jal` at 0x1234 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0x50, a2=?, a3=?.
  The `jal` at 0x1240 calls check_port with a0=a0 at entry (arg0), a1=[a0+80], a2=?, a3=?.
  The `jal` at 0x1274 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xf3, a2=0x2, a3=?.
  The `jal` at 0x1280 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xc8, a2=?, a3=?.
  The `jal` at 0x128c calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xf3, a2=?, a3=?.
  The `jal` at 0x1298 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xc8, a2=?, a3=?.
  The `jal` at 0x12a4 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xf3, a2=?, a3=?.
  The `jal` at 0x12b0 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0x50, a2=?, a3=?.
  The `jal` at 0x12bc calls check_port with a0=a0 at entry (arg0), a1=[a0+80], a2=?, a3=?.
  The `beq` branch at 0x1170 targets 0x1270, is taken when a0(=[sym(pcmouse_mode)]) == a2(=0x2), and falls through when a0(=[sym(pcmouse_mode)]) != a2(=0x2).
  The `beq` branch at 0x1178 targets 0x11f4, is taken when a0(=[sym(pcmouse_mode)]) == at(=0x1), and falls through when a0(=[sym(pcmouse_mode)]) != at(=0x1).
  The `beq` branch at 0x1180 targets 0x11f8, is taken when a0(=[sym(pcmouse_mode)]) == a2(=0x2), and falls through when a0(=[sym(pcmouse_mode)]) != a2(=0x2).
  The `beq` branch at 0x1260 targets 0x118c, is taken when v0(?) >= 0x1 (unsigned), and falls through when v0(?) < 0x1 (unsigned).
  The `beq` branch at 0x1268 targets 0x1194 and is always taken.
  The `bne` branch at 0x12dc targets 0x1190, is taken when a0(?) < 0x1 (unsigned), and falls through when a0(?) >= 0x1 (unsigned).
  The `beq` branch at 0x12e4 targets 0x1174 and is always taken.
  The return at 0x11ec has v0 = ret(pckm_pollcmd).

- `pckm_rx` in `IP35/usr/cpu/sysgen/IP35boot/ioc4_pckm.o` at 0x12ec (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc4_pckm.o`.
  Range: 0x12ec-0x1600 (788 bytes).
  It occupies 788 bytes.
  6 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x48, including `ld` at 0x12ec, `ld` at 0x1418, `ld` at 0x1430.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x50, including `lw` at 0x12f0, `lw` at 0x15a8, `lw` at 0x15fc.
  The `lw` at 0x12f8 loads 4 bytes from [a0+72]:8 +0x2c.
  The `lw` at 0x1320 loads 4 bytes from [a0+72]:8 +0x28.
  6 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x4, including `lw` at 0x1340, `lw` at 0x134c, `lw` at 0x13d4.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x18, including `ld` at 0x1354, `ld` at 0x1424.
  The `sd` at 0x136c stores 8 bytes to a0 (arg0 at entry) +0x18.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x40, including `ld` at 0x1380, `ld` at 0x14b8.
  2 such `ld` accesses load 8 bytes from [a0+64]:8 +0x28, including `ld` at 0x138c, `ld` at 0x13a8.
  2 such `ld` accesses load 8 bytes from [[a0+64]:8+40]:8 +0x10, including `ld` at 0x1390, `ld` at 0x13b4.
  3 such `ld` accesses load 8 bytes from [a0+64]:8 +0x20, including `ld` at 0x1394, `ld` at 0x13a4, `ld` at 0x14c0.
  The `sb` at 0x13a0 stores 1 byte to [[a0+64]:8+32]:8 +0x0.
  The `sd` at 0x13b0 stores 8 bytes to [a0+64]:8 +0x20.
  The `lw` at 0x13e4 loads 4 bytes from a0 (arg0 at entry) +0xc.
  The `sw` at 0x13fc stores 4 bytes to a0 (arg0 at entry) +0x4.
  The `sw` at 0x140c stores 4 bytes to a0 (arg0 at entry) +0x10.
  The `lw` at 0x1468 loads 4 bytes from a0 (arg0 at entry) +0x10.
  The `ll` at 0x1498 loads 4 bytes from [a0+72]:8 +0x3c.
  The `sc` at 0x14a4 stores 4 bytes to [a0+72]:8 +0x3c.
  2 such `lh` accesses load 2 bytes from abs 0xffffffffffffc428, including `lh` at 0x1550, `lh` at 0x1594.
  The `lw` at 0x15c4 loads 4 bytes from [a0+72]:8 +0x34.
  The `jal` at 0x1400 calls streams_timeout with a0=sym(streams_monp), a1=sym(pckm_rsrv_timer), a2=[a0+12], a3=a0 at entry (arg0), a4=0x0, a5=0x0, a6=0x76, a7=[a0+4].
  The `jal` at 0x141c calls mutex_unlock with a0=[a0+72]:8+72, a1=?, a2=?, a3=?.
  The `jalr` at 0x1428 calls (unknown callee) with a0=?, a1=[a0+24]:8, a2=?, a3=?.
  The `jal` at 0x1438 calls mutex_lock with a0=[a0+72]:8+72, a1=0x19, a2=?, a3=?.
  The `jal` at 0x1464 calls untimeout with a0=[a0+16], a1=a0 at entry (arg0), a2=?, a3=?, a5=0x14, a6=0x76.
  The `jal` at 0x1478 calls streams_interrupt with a0=sym(pckm_rsrv_timer), a1=a0 at entry (arg0), a2=0x0, a3=0x0.
  The `jal` at 0x14b0 calls pckm_getbp with a0=a0 at entry (arg0), a1=0x3, a2=[[a0+72]:8+60]+1, a3=[a0+72]:8+60, a4=0x1, a5=[[a0+72]:8+60]+1.
  The `jal` at 0x14c4 calls pckm_getbp with a0=a0 at entry (arg0), a1=0x1, a2=?, a3=[[[a0+64]:8+40]:8+16]:8, a4=[[a0+64]:8+32]:8+1.
  The `jal` at 0x14d8 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xf0, a2=?, a3=[a0+80], a4=[a0+72]:8.
  The `jal` at 0x14e8 calls data_check with a0=ret(pckm_pollcmd), a1=0xfa, a2=?, a3=?.
  The `jal` at 0x14fc calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0x0, a2=?, a3=?.
  The `jal` at 0x150c calls data_check with a0=ret(pckm_pollcmd), a1=0xfa, a2=?, a3=?.
  The `jal` at 0x1520 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=-0x2, a2=?, a3=ret(pckm_pollcmd).
  The `jal` at 0x1530 calls data_check with a0=ret(pckm_pollcmd), a1=0x2, a2=?, a3=ret(pckm_pollcmd).
  The `jal` at 0x154c calls dtimeout with a0=sym(pckm_reinit), a1=a0 at entry (arg0), a2=0x1, a3=[sym(plbase)]:8, a4=[-0x3bd8]:2.
  The `jal` at 0x155c calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xe9, a2=a2 at entry (arg2), a3=[a0+80], a4=[a0+72]:8.
  The `jal` at 0x1568 calls data_check with a0=ret(pckm_pollcmd), a1=0xfa, a2=?, a3=?.
  The `jal` at 0x1578 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=-0x2, a2=?, a3=?.
  The `jal` at 0x1584 calls data_check with a0=ret(pckm_pollcmd), a1=0x0, a2=?, a3=?.
  The `jal` at 0x15a0 calls dtimeout with a0=sym(pckm_reinit), a1=a0 at entry (arg0), a2=0x1, a3=[sym(plbase)]:8, a4=[-0x3bd8]:2.
  The `jal` at 0x15c0 calls default_kbd_setting with a0=a0 at entry (arg0), a1=0x0, a2=[[a0+72]:8+52], a3=?.
  The `jal` at 0x15dc calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xf8, a2=?, a3=?.
  The `jal` at 0x15f0 calls default_ms_setting with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `bne` branch at 0x130c targets 0x1320, is taken when at(=[[a0+72]:8+44]) != a3(=[a0+80]), and falls through when at(=[[a0+72]:8+44]) == a3(=[a0+80]).
  The `beq` branch at 0x1318 targets 0x155c, is taken when a1 == v0(=0xaa), and falls through when a1 != v0(=0xaa).
  The `bne` branch at 0x1324 targets 0x134c, is taken when v1(=[[a0+72]:8+40]) != a3(=[a0+80]), and falls through when v1(=[[a0+72]:8+40]) == a3(=[a0+80]).
  The `beq` branch at 0x132c targets 0x14d8, is taken when s1(=a1) == a1(=0xaa), and falls through when s1(=a1) != a1(=0xaa).
  The `beq` branch at 0x1338 targets 0x14d8, is taken when s1(=a1) == a2(=0xfc), and falls through when s1(=a1) != a2(=0xfc).
  The `beq` branch at 0x1344 targets 0x1354 and is always taken.
  The `beq` branch at 0x1358 targets 0x1370, is taken when a1(=[a0+24]:8) == 0, and falls through when a1(=[a0+24]:8) != 0.
  The `beq` branch at 0x1360 targets 0x1410, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x1370 targets 0x1410, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `bne` branch at 0x1378 targets 0x1418, is taken when a1(?) != 0, and falls through when a1(?) == 0.
  The `beq` branch at 0x1384 targets 0x1488, is taken when a0(=[a0+64]:8) == 0, and falls through when a0(=[a0+64]:8) != 0.
  The `beq` branch at 0x1398 targets 0x1488, is taken when a2(=[[[a0+64]:8+40]:8+16]:8) == a1(=[[a0+64]:8+32]:8), and falls through when a2(=[[[a0+64]:8+40]:8+16]:8) != a1(=[[a0+64]:8+32]:8).
  The `beq` branch at 0x13b8 targets 0x14c4, is taken when a3(=[[[a0+64]:8+40]:8+16]:8) == a4(=[[a0+64]:8+32]:8+1), and falls through when a3(=[[[a0+64]:8+40]:8+16]:8) != a4(=[[a0+64]:8+32]:8+1).
  The `beq` branch at 0x13c4 targets 0x1454, is taken when s1(=a1) == a5(=0x14), and falls through when s1(=a1) != a5(=0x14).
  The `beq` branch at 0x13cc targets 0x1454, is taken when s1(=a1) == a6(=0x76), and falls through when s1(=a1) != a6(=0x76).
  The `bne` branch at 0x13dc targets 0x1444, is taken when (a7(=[a0+4]) & 0x10) != 0, and falls through when (a7(=[a0+4]) & 0x10) == 0.
  The `beq` branch at 0x1408 targets 0x1440 and is always taken.
  The `beq` branch at 0x1410 targets 0x1444, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x145c targets 0x1470, is taken when (a1(=[a0+4]) & 0x10) == 0, and falls through when (a1(=[a0+4]) & 0x10) != 0.
  The `beq` branch at 0x1480 targets 0x1444 and is always taken.
  The `beql` branch at 0x14a8 targets 0x1498, is taken when a5(=[[a0+72]:8+60]+1) == 0, and falls through when a5(=[[a0+72]:8+60]+1) != 0; its branch-likely delay slot `nop` at 0x14ac runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x14bc targets 0x13a0 and is always taken.
  The `beq` branch at 0x14cc targets 0x13c4 and is always taken.
  The `beq` branch at 0x14f0 targets 0x150c, is taken when v0(=ret(data_check)) == 0, and falls through when v0(=ret(data_check)) != 0.
  The `beq` branch at 0x1514 targets 0x152c, is taken when v0(=ret(data_check)) == 0, and falls through when v0(=ret(data_check)) != 0.
  The `beq` branch at 0x1538 targets 0x15b4, is taken when v0(=ret(data_check)) == 0, and falls through when v0(=ret(data_check)) != 0.
  The `beq` branch at 0x1554 targets 0x1444 and is always taken.
  The `beq` branch at 0x1570 targets 0x15f0, is taken when v0(=ret(data_check)) == 0, and falls through when v0(=ret(data_check)) != 0.
  The `beq` branch at 0x158c targets 0x15a8, is taken when v0(=ret(data_check)) == 0, and falls through when v0(=ret(data_check)) != 0.
  The `beq` branch at 0x15ac targets 0x1320 and is always taken.
  The `beq` branch at 0x15d0 targets 0x1354, is taken when (a0(=[a0+4]) & 0x2) == 0, and falls through when (a0(=[a0+4]) & 0x2) != 0.
  The `beq` branch at 0x15e8 targets 0x1354 and is always taken.
  The `beq` branch at 0x15f8 targets 0x15ac and is always taken.
  The return at 0x144c has v0 = one of ?, ret(streams_interrupt), ret(dtimeout).
  The instructions from 0x14d4 to 0x14d4 are not reached by any path from the entry, and their branches are not listed.

- `pckm_intr` in `IP35/usr/cpu/sysgen/IP35boot/ioc4_pckm.o` at 0x1600 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc4_pckm.o`.
  Range: 0x1600-0x1640 (64 bytes).
  It occupies 64 bytes.
  The `jal` at 0x1618 calls mutex_lock with a0=a0+72, a1=0x19, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1620 calls pckm_intr_lock with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x162c calls mutex_unlock with a0=a0+72, a1=?, a2=?, a3=?.
  The return at 0x1638 has v0 = ret(mutex_unlock).

- `pckm_intr_lock` in `IP35/usr/cpu/sysgen/IP35boot/ioc4_pckm.o` at 0x1640 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc4_pckm.o`.
  Range: 0x1640-0x1788 (328 bytes).
  It occupies 328 bytes.
  10 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x10, including `ld` at 0x1640, `ld` at 0x16ac, `ld` at 0x16ec.
  9 such `lw` accesses load 4 bytes from [a0+16]:8 +0x200, including `lw` at 0x1644, `lw` at 0x16f0, `lw` at 0x1700.
  The `ld` at 0x1698 loads 8 bytes from ?.
  The `sw` at 0x16b8 stores 4 bytes to [a0+16]:8 +0xc.
  The `ld` at 0x16c4 loads 8 bytes from a0 (arg0 at entry) +0x60.
  8 such `sw` accesses store 4 bytes to [a0+16]:8 +0x200, including `sw` at 0x16f8, `sw` at 0x170c, `sw` at 0x1720.
  The `jal` at 0x1694 calls valid_data with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x16c0 calls ioc4_write_ireg with a0=[a0+96]:8, a1=0x40, a2=0x0, a3=0x1, a4=[a0+16]:8.
  The `jal` at 0x16e4 calls cmn_err with a0=0x4, a1=sym(.rodata), a2=[[a0+16]:8+512], a3=([[a0+16]:8+512] << 0x2f).
  The `jal` at 0x1708 calls us_delay with a0=0x640, a1=?, a2=[[a0+16]:8+512], a3=[a0+16]:8, a4=([[a0+16]:8+512] | 0x80), a5=[a0+16]:8.
  The `jal` at 0x1738 calls cmn_err with a0=0x4, a1=sym(.rodata), a2=[[a0+16]:8+512], a3=sym(.rodata), a4=([[a0+16]:8+512] << 0x2c).
  The `jal` at 0x175c calls us_delay with a0=0x640, a1=?, a2=?, a3=?.
  The `bgez` branch at 0x1660 targets 0x1670, is taken when at(=([[a0+16]:8+512] << 0x2d)) >= 0 (signed), and falls through when at(=([[a0+16]:8+512] << 0x2d)) < 0 (signed).
  The `bltz` branch at 0x1668 targets 0x16dc, is taken when a3(=([[a0+16]:8+512] << 0x2f)) < 0 (signed), and falls through when a3(=([[a0+16]:8+512] << 0x2f)) >= 0 (signed).
  The `bgez` branch at 0x1678 targets 0x1688, is taken when a4(=([[a0+16]:8+512] << 0x2c)) >= 0 (signed), and falls through when a4(=([[a0+16]:8+512] << 0x2c)) < 0 (signed).
  The `bltz` branch at 0x1680 targets 0x1738, is taken when a0(=([[a0+16]:8+512] << 0x2e)) < 0 (signed), and falls through when a0(=([[a0+16]:8+512] << 0x2e)) >= 0 (signed).
  The `bne` branch at 0x16a4 targets 0x1690, is taken when s0(?) < 0x2 (signed), and falls through when s0(?) >= 0x2 (signed).
  The `beq` branch at 0x1730 targets 0x1670 and is always taken.
  The `beq` branch at 0x1780 targets 0x1688 and is always taken.
  The return at 0x16d4 has v0 = ret(ioc4_write_ireg).

- `pckm_pollcmd` in `IP35/usr/cpu/sysgen/IP35boot/ioc4_pckm.o` at 0x1788 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc4_pckm.o`.
  Range: 0x1788-0x1864 (220 bytes).
  It occupies 220 bytes.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x50, including `lw` at 0x17b4, `lw` at 0x17e8.
  The `sw` at 0x17c8 stores 4 bytes to ?.
  The `lw` at 0x1800 loads 4 bytes from ?.
  4 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x48, including `ld` at 0x1824, `ld` at 0x1834, `ld` at 0x1844.
  4 such `ld` accesses load 8 bytes from [a0+72]:8 +0x10, including `ld` at 0x1828, `ld` at 0x1838, `ld` at 0x1848.
  The `jal` at 0x17ac calls pckm_sendok with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x17e0 calls us_delay with a0=0x32, a1=?, a2=?, a3=?.
  The `beq` branch at 0x17a4 targets 0x17cc, is taken when a1 == at(=-0x2), and falls through when a1 != at(=-0x2).
  The `beq` branch at 0x17b8 targets 0x1844, is taken when v0(=[a0+80]) == 0, and falls through when v0(=[a0+80]) != 0.
  The `beq` branch at 0x17c0 targets 0x1854, is taken when v0(=[a0+80]) == v1(=0x1), and falls through when v0(=[a0+80]) != v1(=0x1).
  The `beq` branch at 0x17d0 targets 0x17e0 and is always taken.
  The `beq` branch at 0x17d8 targets 0x1810, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `beq` branch at 0x17f0 targets 0x1824, is taken when v0(=[a0+80]) == 0, and falls through when v0(=[a0+80]) != 0.
  The `beq` branch at 0x17f8 targets 0x1834, is taken when v0(=[a0+80]) == a0(=0x1), and falls through when v0(=[a0+80]) != a0(=0x1).
  The `beq` branch at 0x1808 targets 0x17d8, is taken when (s2(=0xffffffffe0000000) & v0(?)) == 0, and falls through when (s2(=0xffffffffe0000000) & v0(?)) != 0.
  The `beq` branch at 0x182c targets 0x1800 and is always taken.
  The `beq` branch at 0x183c targets 0x1800 and is always taken.
  The `beq` branch at 0x184c targets 0x17c8 and is always taken.
  The `beq` branch at 0x185c targets 0x17c8 and is always taken.
  The return at 0x181c has v0 = ?.

- `ioc4_pckm_kbdexists` in `IP35/usr/cpu/sysgen/IP35boot/ioc4_pckm.o` at 0x1864 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc4_pckm.o`.
  Range: 0x1864-0x18a0 (60 bytes).
  It occupies 60 bytes.
  The `lw` at 0x1870 loads 4 bytes from [sym(.sbss)]:8 +0x28.
  The `ld` at 0x1880 loads 8 bytes from ([sym(.sbss)]:8 + ([[sym(.sbss)]:8+40] << 0x3)) +0x18.
  The `lw` at 0x1884 loads 4 bytes from [([sym(.sbss)]:8 + ([[sym(.sbss)]:8+40] << 0x3))+24]:8 +0x4.
  The `beq` branch at 0x1868 targets 0x1898, is taken when a2(=[sym(.sbss)]:8) == 0, and falls through when a2(=[sym(.sbss)]:8) != 0.
  The `beq` branch at 0x1874 targets 0x1898, is taken when a3(=[[sym(.sbss)]:8+40]) == v0(=0x13), and falls through when a3(=[[sym(.sbss)]:8+40]) != v0(=0x13).
  The return at 0x1890 has v0 = ?.
  The return at 0x1898 has v0 = 0x0.

- `ioc4_pckm_setleds` in `IP35/usr/cpu/sysgen/IP35boot/ioc4_pckm.o` at 0x18a0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc4_pckm.o`.
  Range: 0x18a0-0x18e0 (64 bytes).
  It occupies 64 bytes.
  The `lw` at 0x18b8 loads 4 bytes from [sym(.sbss)]:8 +0x28.
  The `ld` at 0x18d0 loads 8 bytes from ([sym(.sbss)]:8 + ([[sym(.sbss)]:8+40] << 0x3)) +0x18.
  The `jal` at 0x18cc calls ioc4_lcl_pckm_setleds with a0=[([sym(.sbss)]:8 + ([[sym(.sbss)]:8+40] << 0x3))+24]:8, a1=a0 at entry (arg0), a2=a2 at entry (arg2), a3=[sym(.sbss)]:8, a4=0x13, a5=[[sym(.sbss)]:8+40].
  The `beq` branch at 0x18b0 targets 0x18d4, is taken when a3(=[sym(.sbss)]:8) == 0, and falls through when a3(=[sym(.sbss)]:8) != 0.
  The `beq` branch at 0x18bc targets 0x18d8, is taken when a5(=[[sym(.sbss)]:8+40]) == a4(=0x13), and falls through when a5(=[[sym(.sbss)]:8+40]) != a4(=0x13).
  The return at 0x18d8 has v0 = ?.

- `ioc4_pckm_bell` in `IP35/usr/cpu/sysgen/IP35boot/ioc4_pckm.o` at 0x18e0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc4_pckm.o`.
  Range: 0x18e0-0x1924 (68 bytes).
  It occupies 68 bytes.
  The `lw` at 0x18f4 loads 4 bytes from [sym(.sbss)]:8 +0x28.
  The `lw` at 0x1900 loads 4 bytes from [sym(.sbss)]:8 +0x34.
  The `ld` at 0x1914 loads 8 bytes from ([sym(.sbss)]:8 + ([[sym(.sbss)]:8+40] << 0x3)) +0x18.
  The `jal` at 0x1910 calls ioc4_lcl_pckm_setleds with a0=[([sym(.sbss)]:8 + ([[sym(.sbss)]:8+40] << 0x3))+24]:8, a1=([[sym(.sbss)]:8+52] | 0x8), a2=a2 at entry (arg2), a3=[sym(.sbss)]:8, a4=[[sym(.sbss)]:8+40].
  The `beq` branch at 0x18ec targets 0x1918, is taken when a3(=[sym(.sbss)]:8) == 0, and falls through when a3(=[sym(.sbss)]:8) != 0.
  The `beq` branch at 0x18f8 targets 0x191c, is taken when a4(=[[sym(.sbss)]:8+40]) == a1(=0x13), and falls through when a4(=[[sym(.sbss)]:8+40]) != a1(=0x13).
  The return at 0x191c has v0 = ?.

- `ioc4_gl_setporthandler` in `IP35/usr/cpu/sysgen/IP35boot/ioc4_pckm.o` at 0x1924 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc4_pckm.o`.
  Range: 0x1924-0x1950 (44 bytes).
  It occupies 44 bytes.
  The `lw` at 0x1930 loads 4 bytes from [sym(.sbss)]:8 +0x28.
  The `ld` at 0x1940 loads 8 bytes from ([sym(.sbss)]:8 + ([[sym(.sbss)]:8+40] << 0x3)) +0x18.
  The `sd` at 0x1944 stores 8 bytes to [([sym(.sbss)]:8 + ([[sym(.sbss)]:8+40] << 0x3))+24]:8 +0x18.
  The `beq` branch at 0x1928 targets 0x1948, is taken when a2(=[sym(.sbss)]:8) == 0, and falls through when a2(=[sym(.sbss)]:8) != 0.
  The `beq` branch at 0x1934 targets 0x1948, is taken when a4(=[[sym(.sbss)]:8+40]) == a3(=0x13), and falls through when a4(=[[sym(.sbss)]:8+40]) != a3(=0x13).
  The return at 0x1948 has v0 = ?.

- `ioc4_du_keyboard_port` in `IP35/usr/cpu/sysgen/IP35boot/ioc4_pckm.o` at 0x1950 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc4_pckm.o`.
  Range: 0x1950-0x1958 (8 bytes).
  It occupies 8 bytes.
  The return at 0x1950 has v0 = -0x1.

- `ioc4_lcl_pckm_setleds` in `IP35/usr/cpu/sysgen/IP35boot/ioc4_pckm.o` at 0x1958 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc4_pckm.o`.
  Range: 0x1958-0x19ac (84 bytes).
  It occupies 84 bytes.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x48, including `ld` at 0x1964, `ld` at 0x198c.
  The `jal` at 0x1978 calls mutex_lock with a0=[a0+72]:8+72, a1=0x19, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1984 calls ioc4_lcl_pckm_setleds_lock with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0x1994 calls mutex_unlock with a0=[a0+72]:8+72, a1=?, a2=?, a3=?.
  The return at 0x19a4 has v0 = ret(mutex_unlock).

- `ioc4_lcl_pckm_setleds_lock` in `IP35/usr/cpu/sysgen/IP35boot/ioc4_pckm.o` at 0x19ac (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc4_pckm.o`.
  Range: 0x19ac-0x1b20 (372 bytes).
  It occupies 372 bytes.
  The `ld` at 0x19b8 loads 8 bytes from a0 (arg0 at entry) +0x48.
  5 such `lw` accesses load 4 bytes from [a0+72]:8 +0x34, including `lw` at 0x19c0, `lw` at 0x1a34, `lw` at 0x1a54.
  The `lw` at 0x19f0 loads 4 bytes from [a0+72]:8 +0x38.
  The `sw` at 0x1a1c stores 4 bytes to [a0+72]:8 +0x38.
  2 such `sw` accesses store 4 bytes to [a0+72]:8 +0x34, including `sw` at 0x1a28, `sw` at 0x1a5c.
  The `jal` at 0x1a30 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=[[a0+72]:8+52], a2=?, a3=?.
  The `jal` at 0x1a3c calls data_check with a0=ret(pckm_pollcmd), a1=0xfa, a2=?, a3=?.
  The `jal` at 0x1a88 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xed, a2=?, a3=?.
  The `jal` at 0x1a94 calls data_check with a0=ret(pckm_pollcmd), a1=0xfa, a2=?, a3=?.
  The `jal` at 0x1ab4 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xf4, a2=?, a3=?.
  The `jal` at 0x1ac0 calls data_check with a0=ret(pckm_pollcmd), a1=0xfa, a2=?, a3=?.
  The `jal` at 0x1ad4 calls default_kbd_setting with a0=a0 at entry (arg0), a1=0x0, a2=[[a0+72]:8+52], a3=?.
  The `jal` at 0x1af4 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=[[a0+72]:8+52], a2=?, a3=?.
  The `jal` at 0x1b00 calls data_check with a0=ret(pckm_pollcmd), a1=0xfa, a2=?, a3=?.
  The `jal` at 0x1b10 calls pckm_reinit_core with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `beq` branch at 0x19e0 targets 0x1a60, is taken when at(=[[a0+72]:8+52]) == a3(?), and falls through when at(=[[a0+72]:8+52]) != a3(?).
  The `beq` branch at 0x19e8 targets 0x1a24, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `beq` branch at 0x19fc targets 0x1a0c, is taken when a7(?) >= 0xe (signed), and falls through when a7(?) < 0xe (signed).
  The `bne` branch at 0x1a04 targets 0x1a64, is taken when a4(?) != 0, and falls through when a4(?) == 0.
  The `beq` branch at 0x1a0c targets 0x1a1c, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `bne` branch at 0x1a14 targets 0x1a64, is taken when a5(?) != 0, and falls through when a5(?) == 0.
  The `beq` branch at 0x1a24 targets 0x1a84 and is always taken.
  The `beq` branch at 0x1a44 targets 0x1af4, is taken when v0(=ret(data_check)) == 0, and falls through when v0(=ret(data_check)) != 0.
  The `beq` branch at 0x1a4c targets 0x1a64, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `beq` branch at 0x1a80 targets 0x1ae4, is taken when t1(?) == 0, and falls through when t1(?) != 0.
  The `bne` branch at 0x1a9c targets 0x1a2c, is taken when v0(=ret(data_check)) != 0, and falls through when v0(=ret(data_check)) == 0.
  The `bne` branch at 0x1aa8 targets 0x1a7c, is taken when s3(?) < 0x2 (unsigned), and falls through when s3(?) >= 0x2 (unsigned).
  The `bne` branch at 0x1ac8 targets 0x1a7c, is taken when v0(=ret(data_check)) != 0, and falls through when v0(=ret(data_check)) == 0.
  The `beq` branch at 0x1adc targets 0x1a80 and is always taken.
  The `bne` branch at 0x1ae4 targets 0x1a54, is taken when s2(?) != 0, and falls through when s2(?) == 0.
  The `beq` branch at 0x1aec targets 0x1a64 and is always taken.
  The `bne` branch at 0x1b08 targets 0x1a4c, is taken when v0(=ret(data_check)) != 0, and falls through when v0(=ret(data_check)) == 0.
  The `beq` branch at 0x1b18 targets 0x1a4c and is always taken.
  The return at 0x1a74 has v0 = ?.

- `pckm_sendok` in `IP35/usr/cpu/sysgen/IP35boot/ioc4_pckm.o` at 0x1b20 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc4_pckm.o`.
  Range: 0x1b20-0x1bac (140 bytes).
  It occupies 140 bytes.
  The `lw` at 0x1b2c loads 4 bytes from a0 (arg0 at entry) +0x50.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x48, including `ld` at 0x1b30, `ld` at 0x1b68.
  2 such `ld` accesses load 8 bytes from [a0+72]:8 +0x10, including `ld` at 0x1b44, `ld` at 0x1b6c.
  2 such `lw` accesses load 4 bytes from [[a0+72]:8+16]:8 +0x200, including `lw` at 0x1b5c, `lw` at 0x1b74.
  The `jal` at 0x1b60 calls us_delay with a0=0x32, a1=?, a2=[[[a0+72]:8+16]:8+512], a3=?.
  The `beq` branch at 0x1b58 targets 0x1ba0 and is always taken.
  The `beq` branch at 0x1b7c targets 0x1b8c, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `bne` branch at 0x1b84 targets 0x1b60, is taken when s0(?) != 0, and falls through when s0(?) == 0.
  The `beq` branch at 0x1ba4 targets 0x1b7c and is always taken.
  The return at 0x1b98 has v0 = ?.

- `pckm_flushinp` in `IP35/usr/cpu/sysgen/IP35boot/ioc4_pckm.o` at 0x1bac (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc4_pckm.o`.
  Range: 0x1bac-0x1be8 (60 bytes).
  It occupies 60 bytes.
  The `lw` at 0x1bac loads 4 bytes from a0 (arg0 at entry) +0x50.
  The `lw` at 0x1bc4 loads 4 bytes from ?.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x48, including `ld` at 0x1bc8, `ld` at 0x1bd8.
  2 such `ld` accesses load 8 bytes from [a0+72]:8 +0x10, including `ld` at 0x1bcc, `ld` at 0x1bdc.
  The `beq` branch at 0x1bb0 targets 0x1bd8, is taken when a2(=[a0+80]) == 0, and falls through when a2(=[a0+80]) != 0.
  The `beq` branch at 0x1bb8 targets 0x1bc8, is taken when a2(=[a0+80]) == a3(=0x1), and falls through when a2(=[a0+80]) != a3(=0x1).
  The `beq` branch at 0x1bd0 targets 0x1bc0 and is always taken.
  The `beq` branch at 0x1be0 targets 0x1bc0 and is always taken.
  The return at 0x1bc0 has v0 = ?.

- `data_check` in `IP35/usr/cpu/sysgen/IP35boot/ioc4_pckm.o` at 0x1be8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc4_pckm.o`.
  Range: 0x1be8-0x1c60 (120 bytes).
  It occupies 120 bytes.
  The `lw` at 0x1bec loads 4 bytes from sym(.rodata) +0x0.
  The `lw` at 0x1c14 loads 4 bytes from sym(.rodata) +0x10.
  The `lw` at 0x1c18 loads 4 bytes from sym(.rodata) +0xc.
  The `lw` at 0x1c28 loads 4 bytes from sym(.rodata) +0x4.
  The `lw` at 0x1c2c loads 4 bytes from sym(.rodata) +0x8.
  The `beq` branch at 0x1bf0 targets 0x1c58 and is never taken: its condition can never hold for these operands, so execution always falls through.
  The `beq` branch at 0x1bf8 targets 0x1c10 and is always taken.
  The `beq` branch at 0x1c00 targets 0x1c48 and is never taken: its condition can never hold for these operands, so execution always falls through.
  The `bne` branch at 0x1c08 targets 0x1c4c, is taken when a5(?) != 0, and falls through when a5(?) == 0.
  The `beq` branch at 0x1c10 targets 0x1c00, is taken when at(?) == 0, and falls through when at(?) != 0.
  The `bne` branch at 0x1c20 targets 0x1c00, is taken when (v1(=0x4000000) & a0) != 0, and falls through when (v1(=0x4000000) & a0) == 0.
  The `bne` branch at 0x1c38 targets 0x1c00, is taken when a1 != a2(?), and falls through when a1 == a2(?).
  The `beq` branch at 0x1c40 targets 0x1c00 and is always taken.
  The return at 0x1c50 has v0 = 0x1.
  The instructions from 0x1c48 to 0x1c48 are not reached by any path from the entry, and their branches are not listed.
  The instructions from 0x1c58 to 0x1c5c are not reached by any path from the entry, and their branches are not listed.

- `valid_data` in `IP35/usr/cpu/sysgen/IP35boot/ioc4_pckm.o` at 0x1c60 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc4_pckm.o`.
  Range: 0x1c60-0x1dfc (412 bytes).
  It occupies 412 bytes.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x50, including `lw` at 0x1c78, `lw` at 0x1d54.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0x1ca0, `lw` at 0x1cf0.
  2 such `lw` accesses load 4 bytes from sym(.rodata) +0x0, including `lw` at 0x1cc4, `lw` at 0x1d0c.
  2 such `lw` accesses load 4 bytes from sym(.rodata) +0x10, including `lw` at 0x1cd0, `lw` at 0x1d8c.
  The `lw` at 0x1d1c loads 4 bytes from sym(.rodata) +0xc.
  The `lw` at 0x1d20 loads 4 bytes from a0 (arg0 at entry) +0x4.
  The `lw` at 0x1d60 loads 4 bytes from sym(.rodata) +0x4.
  The `ld` at 0x1d64 loads 8 bytes from abs 0xffffffffffffc510.
  The `lw` at 0x1d68 loads 4 bytes from sym(.rodata) +0x8.
  The `lw` at 0x1d70 loads 4 bytes from [-0x3af0]:8 +0xa0.
  The `sw` at 0x1d84 stores 4 bytes to [-0x3af0]:8 +0xa0.
  4 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x48, including `ld` at 0x1d90, `ld` at 0x1dcc, `ld` at 0x1ddc.
  4 such `ld` accesses load 8 bytes from [a0+72]:8 +0x10, including `ld` at 0x1d94, `ld` at 0x1dd0, `ld` at 0x1de0.
  The `jal` at 0x1cc8 calls pckm_restart with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x1d3c calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xfe, a2=?, a3=?.
  The `jal` at 0x1d80 calls pckm_rx with a0=a0 at entry (arg0), a1=?, a2=0x10, a3=[[-0x3af0]:8+160]+1, a4=[-0x3af0]:8.
  The `beq` branch at 0x1c88 targets 0x1ddc, is taken when a2(=[a0+80]) == 0, and falls through when a2(=[a0+80]) != 0.
  The `beq` branch at 0x1c94 targets 0x1dec, is taken when a2(=[a0+80]) == at(=0x1), and falls through when a2(=[a0+80]) != at(=0x1).
  The `beq` branch at 0x1ca4 targets 0x1da0, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `beq` branch at 0x1cb4 targets 0x1da0, is taken when (s6(=0xffffffffe0000000) & s1(?)) == 0, and falls through when (s6(=0xffffffffe0000000) & s1(?)) != 0.
  The `beq` branch at 0x1cc0 targets 0x1d00 and is always taken.
  The `bne` branch at 0x1cd4 targets 0x1d0c and is always taken.
  The `beq` branch at 0x1ce0 targets 0x1d90, is taken when a2(=[a0+80]) == 0, and falls through when a2(=[a0+80]) != 0.
  The `beq` branch at 0x1ce8 targets 0x1dcc, is taken when a2(=[a0+80]) == s7(=0x1), and falls through when a2(=[a0+80]) != s7(=0x1).
  The `beq` branch at 0x1cf4 targets 0x1da0, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `beq` branch at 0x1cfc targets 0x1da0, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x1d04 targets 0x1cdc and is never taken: its condition can never hold for these operands, so execution always falls through.
  The `beq` branch at 0x1d14 targets 0x1cd0, is taken when (a1(=0xffffffff80000000) & s1(?)) == 0, and falls through when (a1(=0xffffffff80000000) & s1(?)) != 0.
  The `beq` branch at 0x1d28 targets 0x1d58, is taken when (a1(=0x4000000) & s1(?)) == 0, and falls through when (a1(=0x4000000) & s1(?)) != 0.
  The `beq` branch at 0x1d30 targets 0x1cc8, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `bne` branch at 0x1d48 targets 0x1d04, is taken when s3(?) < 0x3 (unsigned), and falls through when s3(?) >= 0x3 (unsigned).
  The `beq` branch at 0x1d50 targets 0x1ce0 and is always taken.
  The `beq` branch at 0x1d58 targets 0x1cc8, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x1d88 targets 0x1cd4 and is always taken.
  The `beq` branch at 0x1d98 targets 0x1cf0 and is always taken.
  The `beq` branch at 0x1dd4 targets 0x1cf0 and is always taken.
  The `beq` branch at 0x1de4 targets 0x1ca0 and is always taken.
  The `beq` branch at 0x1df4 targets 0x1ca0 and is always taken.
  The return at 0x1dc4 has v0 = one of ?, ret(pckm_pollcmd).
  The instructions from 0x1cdc to 0x1cdc are not reached by any path from the entry, and their branches are not listed.

- `set_ports` in `IP35/usr/cpu/sysgen/IP35boot/ioc4_pckm.o` at 0x1dfc (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc4_pckm.o`.
  Range: 0x1dfc-0x1f5c (352 bytes).
  It occupies 352 bytes.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x30, including `sw` at 0x1e20, `sw` at 0x1f28.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x28, including `sw` at 0x1e2c, `sw` at 0x1e74.
  The `ld` at 0x1e30 loads 8 bytes from a0 (arg0 at entry) +0x20.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x2c, including `sw` at 0x1e34, `sw` at 0x1edc.
  The `sw` at 0x1e3c stores 4 bytes to [a0+32]:8 +0x50.
  The `ld` at 0x1e48 loads 8 bytes from a0 (arg0 at entry) +0x18.
  The `sw` at 0x1e60 stores 4 bytes to [a0+24]:8 +0x50.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x28, including `lw` at 0x1e64, `lw` at 0x1eec.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x58, including `sw` at 0x1e70, `sw` at 0x1f40.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0x1e78, `ld` at 0x1e9c.
  The `sw` at 0x1e7c stores 4 bytes to ?.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x2c, including `lw` at 0x1ec8, `lw` at 0x1f04.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x5c, including `sw` at 0x1ed4, `sw` at 0x1f58.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x0, including `lw` at 0x1f30, `lw` at 0x1f48.
  The `jal` at 0x1e98 calls check_port with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1f34 calls cmn_err with a0=0x1, a1=sym(.rodata), a2=[a0], a3=?.
  The `jal` at 0x1f4c calls cmn_err with a0=0x1, a1=sym(.rodata), a2=[a0], a3=?.
  The `beq` branch at 0x1e5c targets 0x1e8c and is always taken.
  The `bne` branch at 0x1e68 targets 0x1f2c, is taken when v1(=[a0+40]) != s5(=0x13), and falls through when v1(=[a0+40]) == s5(=0x13).
  The `beq` branch at 0x1e88 targets 0x1ee0, is taken when s1(?) >= 0x2 (signed), and falls through when s1(?) < 0x2 (signed).
  The `beq` branch at 0x1ea0 targets 0x1e64, is taken when v0(=ret(check_port)) == s4(=0x47), and falls through when v0(=ret(check_port)) != s4(=0x47).
  The `beq` branch at 0x1ea8 targets 0x1e64, is taken when v0(=ret(check_port)) == s6(=0x83), and falls through when v0(=ret(check_port)) != s6(=0x83).
  The `beq` branch at 0x1eb0 targets 0x1ec8, is taken when v0(=ret(check_port)) == 0, and falls through when v0(=ret(check_port)) != 0.
  The `beq` branch at 0x1eb8 targets 0x1ec8, is taken when v0(=ret(check_port)) == s7(=0x3), and falls through when v0(=ret(check_port)) != s7(=0x3).
  The `bne` branch at 0x1ec0 targets 0x1e78, is taken when v0(=ret(check_port)) != s8(=0x4), and falls through when v0(=ret(check_port)) == s8(=0x4).
  The `bne` branch at 0x1ecc targets 0x1f44, is taken when t8(=[a0+44]) != s5(=0x13), and falls through when t8(=[a0+44]) == s5(=0x13).
  The `beq` branch at 0x1ed8 targets 0x1e78 and is always taken.
  The `bne` branch at 0x1efc targets 0x1f0c, is taken when t9(=[a0+40]) != s5(=0x13), and falls through when t9(=[a0+40]) == s5(=0x13).
  The `beq` branch at 0x1f08 targets 0x1f24, is taken when ra(=[a0+44]) == s5(=0x13), and falls through when ra(=[a0+44]) != s5(=0x13).
  The `beq` branch at 0x1f24 targets 0x1f0c and is always taken.
  The `beq` branch at 0x1f3c targets 0x1e74 and is always taken.
  The `beq` branch at 0x1f54 targets 0x1ed8 and is always taken.
  The return at 0x1f1c has v0 = 0x1.

- `check_port` in `IP35/usr/cpu/sysgen/IP35boot/ioc4_pckm.o` at 0x1f5c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc4_pckm.o`.
  Range: 0x1f5c-0x2298 (828 bytes).
  It occupies 828 bytes.
  The `sw` at 0x1f5c stores 4 bytes to a0 (arg0 at entry) +0x50.
  The `lw` at 0x1fbc loads 4 bytes from sym(.rodata) +0x0.
  The `lw` at 0x1fec loads 4 bytes from sym(.rodata) +0x10.
  The `lw` at 0x1ff8 loads 4 bytes from sym(.rodata) +0xc.
  The `lw` at 0x2014 loads 4 bytes from sym(.rodata) +0x20.
  The `lw` at 0x2018 loads 4 bytes from sym(.rodata) +0x1c.
  The `lw` at 0x2030 loads 4 bytes from sym(.rodata) +0x14.
  The `lw` at 0x2034 loads 4 bytes from sym(.rodata) +0x18.
  The `lw` at 0x20ec loads 4 bytes from sym(.rodata) +0x4.
  The `lw` at 0x20f0 loads 4 bytes from sym(.rodata) +0x8.
  The `jal` at 0x1f74 calls pckm_flushinp with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1f98 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xf2, a2=?, a3=?.
  The `beq` branch at 0x1fc4 targets 0x2074 and is never taken: its condition can never hold for these operands, so execution always falls through.
  The `beq` branch at 0x1fcc targets 0x1fe8 and is always taken.
  The `beq` branch at 0x1fd4 targets 0x1fe0, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `beq` branch at 0x1fe0 targets 0x2074 and is never taken: its condition can never hold for these operands, so execution always falls through.
  The `beq` branch at 0x1ff0 targets 0x2008, is taken when (a4(=one of 0xffffffff80000000, 0x20000000) & a5(=ret(pckm_pollcmd))) == 0, and falls through when (a4(=one of 0xffffffff80000000, 0x20000000) & a5(=ret(pckm_pollcmd))) != 0.
  The `beq` branch at 0x2000 targets 0x20e4, is taken when (v1(=0x4000000) & a5(=ret(pckm_pollcmd))) == 0, and falls through when (v1(=0x4000000) & a5(=ret(pckm_pollcmd))) != 0.
  The `beq` branch at 0x2008 targets 0x2074 and is never taken: its condition can never hold for these operands, so execution always falls through.
  The `beq` branch at 0x2010 targets 0x1fe0, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `bne` branch at 0x2020 targets 0x1fe0, is taken when (a0(=0x2000000) & a5(=ret(pckm_pollcmd))) != 0, and falls through when (a0(=0x2000000) & a5(=ret(pckm_pollcmd))) == 0.
  The `bne` branch at 0x2028 targets 0x1fe0, is taken when s0(?) != s5(=0x13), and falls through when s0(?) == s5(=0x13).
  The `bne` branch at 0x205c targets 0x218c, is taken when a6(?) < 0x53 (unsigned), and falls through when a6(?) >= 0x53 (unsigned).
  The `beq` branch at 0x2064 targets 0x21d4, is taken when t0(?) == 0, and falls through when t0(?) != 0.
  The `beq` branch at 0x206c targets 0x1fd4 and is always taken.
  The `bne` branch at 0x20e4 targets 0x2008, is taken when s0(?) != s5(=0x13), and falls through when s0(?) == s5(=0x13).
  The `bne` branch at 0x2114 targets 0x2174, is taken when a6(?) < 0x53 (unsigned), and falls through when a6(?) >= 0x53 (unsigned).
  The `beq` branch at 0x211c targets 0x21a4, is taken when t1(?) == 0, and falls through when t1(?) != 0.
  The `beq` branch at 0x2124 targets 0x2008, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `beq` branch at 0x212c targets 0x2008 and is always taken.
  The `bne` branch at 0x2174 targets 0x21bc, is taken when t0(?) != 0, and falls through when t0(?) == 0.
  The `beq` branch at 0x217c targets 0x221c, is taken when t2(?) == 0, and falls through when t2(?) != 0.
  The `beq` branch at 0x2184 targets 0x2008 and is always taken.
  The `bne` branch at 0x218c targets 0x21ec, is taken when v0(?) != 0, and falls through when v0(?) == 0.
  The `beq` branch at 0x2194 targets 0x2258, is taken when t2(?) == 0, and falls through when t2(?) != 0.
  The `beq` branch at 0x219c targets 0x1fe0 and is always taken.
  The `bne` branch at 0x21a4 targets 0x2204, is taken when t8(?) != 0, and falls through when t8(?) == 0.
  The `beq` branch at 0x21ac targets 0x2278, is taken when t9(?) == 0, and falls through when t9(?) != 0.
  The `beq` branch at 0x21b4 targets 0x2008 and is always taken.
  The `bne` branch at 0x21bc targets 0x222c, is taken when t3(?) != 0, and falls through when t3(?) == 0.
  The `beq` branch at 0x21cc targets 0x2008 and is always taken.
  The `bne` branch at 0x21d4 targets 0x223c, is taken when t3(?) != 0, and falls through when t3(?) == 0.
  The `beq` branch at 0x21dc targets 0x2288, is taken when t9(?) == 0, and falls through when t9(?) != 0.
  The `beq` branch at 0x21e4 targets 0x1fe0 and is always taken.
  The `bne` branch at 0x21ec targets 0x2268, is taken when t1(?) != 0, and falls through when t1(?) == 0.
  The `beq` branch at 0x21fc targets 0x1fe0 and is always taken.
  The `bne` branch at 0x2204 targets 0x2008, is taken when t2(=0x83) != a6(?), and falls through when t2(=0x83) == a6(?).
  The `beq` branch at 0x220c targets 0x2008, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `beq` branch at 0x2214 targets 0x2008 and is always taken.
  The `bne` branch at 0x221c targets 0x2008, is taken when t8(=0x47) != a6(?), and falls through when t8(=0x47) == a6(?).
  The `beq` branch at 0x2224 targets 0x2008 and is always taken.
  The `bne` branch at 0x222c targets 0x2008, is taken when a6(?) != 0, and falls through when a6(?) == 0.
  The `beq` branch at 0x2234 targets 0x2008 and is always taken.
  The `bne` branch at 0x2240 targets 0x1fe0, is taken when t9(=0x83) != a6(?), and falls through when t9(=0x83) == a6(?).
  The `beq` branch at 0x2248 targets 0x1fe0, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `beq` branch at 0x2250 targets 0x1fe0 and is always taken.
  The `bne` branch at 0x2258 targets 0x1fe0, is taken when at(=0x47) != a6(?), and falls through when at(=0x47) == a6(?).
  The `beq` branch at 0x2260 targets 0x1fe0 and is always taken.
  The `bne` branch at 0x2268 targets 0x1fe0, is taken when a6(?) != 0, and falls through when a6(?) == 0.
  The `beq` branch at 0x2270 targets 0x1fe0 and is always taken.
  The `bne` branch at 0x2278 targets 0x2008, is taken when v1(=0xfa) != a6(?), and falls through when v1(=0xfa) == a6(?).
  The `beq` branch at 0x2280 targets 0x2008 and is always taken.
  The `bne` branch at 0x2288 targets 0x1fe0, is taken when a0(=0xfa) != a6(?), and falls through when a0(=0xfa) == a6(?).
  The `beq` branch at 0x2290 targets 0x1fe0 and is always taken.
  The instructions from 0x2074 to 0x20e0 are not reached by any path from the entry, and their branches are not listed.
  The instructions from 0x2134 to 0x2170 are not reached by any path from the entry, and their branches are not listed.

- `pckm_restart` in `IP35/usr/cpu/sysgen/IP35boot/ioc4_pckm.o` at 0x2298 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc4_pckm.o`.
  Range: 0x2298-0x252c (660 bytes).
  It occupies 660 bytes.
  9 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x50, including `lw` at 0x2298, `lw` at 0x22e4, `lw` at 0x2310.
  13 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x48, including `ld` at 0x22a8, `ld` at 0x22e8, `ld` at 0x2300.
  2 such `ld` accesses load 8 bytes from ([a0+72]:8 + ([a0+80] << 0x3)) +0x18, including `ld` at 0x22c0, `ld` at 0x22f4.
  The `sw` at 0x22f8 stores 4 bytes to [([a0+72]:8 + ([a0+80] << 0x3))+24]:8 +0x50.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x4, including `lw` at 0x22fc, `lw` at 0x2354, `lw` at 0x23f8.
  3 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x4, including `sw` at 0x2308, `sw` at 0x2364, `sw` at 0x2418.
  2 such `lw` accesses load 4 bytes from [a0+72]:8 +0x28, including `lw` at 0x230c, `lw` at 0x23b0.
  2 such `lw` accesses load 4 bytes from [a0+72]:8 +0x2c, including `lw` at 0x231c, `lw` at 0x2438.
  The `lw` at 0x2334 loads 4 bytes from [a0+72]:8 +0x5c.
  3 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x8, including `sw` at 0x234c, `sw` at 0x2410, `sw` at 0x2470.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0xc, including `sw` at 0x235c, `sw` at 0x2404.
  2 such `ld` accesses load 8 bytes from [a0+72]:8 +0x10, including `ld` at 0x2368, `ld` at 0x238c.
  2 such `lw` accesses load 4 bytes from [[a0+72]:8+16]:8 +0x200, including `lw` at 0x2378, `lw` at 0x2390.
  2 such `sw` accesses store 4 bytes to [[a0+72]:8+16]:8 +0x200, including `sw` at 0x2384, `sw` at 0x2394.
  2 such `lw` accesses load 4 bytes from [a0+72]:8 +0x30, including `lw` at 0x23c0, `lw` at 0x2448.
  The `sw` at 0x23d8 stores 4 bytes to [a0+72]:8 +0x28.
  The `sw` at 0x23e4 stores 4 bytes to [a0+72]:8 +0x58.
  The `lw` at 0x23f4 loads 4 bytes from [a0+72]:8 +0x34.
  The `sw` at 0x2468 stores 4 bytes to [a0+72]:8 +0x2c.
  2 such `lw` accesses load 4 bytes from [a0+72]:8 +0x0, including `lw` at 0x2478, `lw` at 0x24c0.
  2 such `ld` accesses load 8 bytes from [a0+72]:8 +0x18, including `ld` at 0x2494, `ld` at 0x24dc.
  2 such `lw` accesses load 4 bytes from [[a0+72]:8+24]:8 +0x4, including `lw` at 0x2498, `lw` at 0x24e0.
  2 such `sw` accesses store 4 bytes to [[a0+72]:8+24]:8 +0x4, including `sw` at 0x24a0, `sw` at 0x24e8.
  2 such `ld` accesses load 8 bytes from [a0+72]:8 +0x20, including `ld` at 0x2504, `ld` at 0x2518.
  2 such `lw` accesses load 4 bytes from [[a0+72]:8+32]:8 +0x4, including `lw` at 0x2508, `lw` at 0x251c.
  2 such `sw` accesses store 4 bytes to [[a0+72]:8+32]:8 +0x4, including `sw` at 0x2514, `sw` at 0x2528.
  The `jal` at 0x22bc calls check_port with a0=[([a0+72]:8 + ([a0+80] << 0x3))+24]:8, a1=[a0+80], a2=([a0+80] << 0x3), a3=a3 at entry (arg3).
  The `jal` at 0x2328 calls default_ms_setting with a0=a0 at entry (arg0), a1=?, a2=?, a3=?, a5=[a0+72]:8.
  The `jal` at 0x23f0 calls default_kbd_setting with a0=a0 at entry (arg0), a1=0x0, a2=[[a0+72]:8+52], a3=?, a5=[a0+72]:8, a6=[[a0+72]:8+40], a7=([a0+4] | 0x20).
  The `jal` at 0x2420 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xf8, a2=?, a3=?.
  The `jal` at 0x247c calls cmn_err with a0=0x1, a1=sym(.rodata), a2=[[a0+72]:8], a3=0x47, a4=[[a0+72]:8+40], a5=[a0+72]:8, a6=0x13.
  The `jal` at 0x24ac calls cmn_err with a0=0x1, a1=sym(.rodata), a2=?, a3=?, a4=sym(.rodata), a5=[a0+72]:8, a7=[[a0+72]:8+48].
  The `jal` at 0x24c4 calls cmn_err with a0=0x1, a1=sym(.rodata), a2=[[a0+72]:8], a3=0x47, a4=0x83, a5=[a0+72]:8.
  The `jal` at 0x24f4 calls cmn_err with a0=0x1, a1=sym(.rodata), a2=?, a3=?, a4=sym(.rodata), a5=[a0+72]:8.
  The `beq` branch at 0x22c8 targets 0x23ac, is taken when v0(=ret(check_port)) == a3(=0x47), and falls through when v0(=ret(check_port)) != a3(=0x47).
  The `beq` branch at 0x22d4 targets 0x23ac, is taken when v0(=ret(check_port)) == a4(=0x83), and falls through when v0(=ret(check_port)) != a4(=0x83).
  The `beq` branch at 0x22dc targets 0x2434, is taken when v0(=ret(check_port)) == 0, and falls through when v0(=ret(check_port)) != 0.
  The `beq` branch at 0x2314 targets 0x23e8, is taken when a6(=[[a0+72]:8+40]) == a0(=[a0+80]), and falls through when a6(=[[a0+72]:8+40]) != a0(=[a0+80]).
  The `bne` branch at 0x2320 targets 0x2368, is taken when t3(=[[a0+72]:8+44]) != a0(=[a0+80]), and falls through when t3(=[[a0+72]:8+44]) == a0(=[a0+80]).
  The `beq` branch at 0x233c targets 0x246c, is taken when v0(=[[a0+72]:8+92]) == a3(=0x3), and falls through when v0(=[[a0+72]:8+92]) != a3(=0x3).
  The `beq` branch at 0x2344 targets 0x246c, is taken when v0(=[[a0+72]:8+92]) == a0(=0x4), and falls through when v0(=[[a0+72]:8+92]) != a0(=0x4).
  The `bne` branch at 0x23b8 targets 0x2474, is taken when a4(=[[a0+72]:8+40]) != a6(=0x13), and falls through when a4(=[[a0+72]:8+40]) == a6(=0x13).
  The `beq` branch at 0x23c8 targets 0x23d8, is taken when a7(=[[a0+72]:8+48]) == 0, and falls through when a7(=[[a0+72]:8+48]) != 0.
  The `bne` branch at 0x23d0 targets 0x24ac, is taken when a0(=[a0+80]) != 0, and falls through when a0(=[a0+80]) == 0.
  The `beq` branch at 0x23e0 targets 0x22e4 and is always taken.
  The `beq` branch at 0x2414 targets 0x2428, is taken when (t1(=([a0+4] | 0x1)) & 0x2) == 0, and falls through when (t1(=([a0+4] | 0x1)) & 0x2) != 0.
  The `beq` branch at 0x242c targets 0x231c and is always taken.
  The `bne` branch at 0x2440 targets 0x24bc, is taken when t2(=[[a0+72]:8+44]) != t3(=0x13), and falls through when t2(=[[a0+72]:8+44]) == t3(=0x13).
  The `beq` branch at 0x2454 targets 0x2464, is taken when t8(=[[a0+72]:8+48]) == 0, and falls through when t8(=[[a0+72]:8+48]) != 0.
  The `bne` branch at 0x245c targets 0x24f4, is taken when a0(=[a0+80]) != v0(=0x1), and falls through when a0(=[a0+80]) == v0(=0x1).
  The `beq` branch at 0x2464 targets 0x22e4 and is always taken.
  The `beq` branch at 0x246c targets 0x2350 and is always taken.
  The `beq` branch at 0x248c targets 0x2504, is taken when a2(=[a0+80]) == 0, and falls through when a2(=[a0+80]) != 0.
  The `beq` branch at 0x24a4 targets 0x23c0 and is always taken.
  The `beq` branch at 0x24b4 targets 0x239c and is always taken.
  The `beq` branch at 0x24d4 targets 0x2518, is taken when a2(=[a0+80]) == 0, and falls through when a2(=[a0+80]) != 0.
  The `beq` branch at 0x24ec targets 0x2448 and is always taken.
  The `beq` branch at 0x24fc targets 0x239c and is always taken.
  The `beq` branch at 0x2510 targets 0x24a4 and is always taken.
  The `beq` branch at 0x2524 targets 0x24ec and is always taken.
  The return at 0x23a4 has v0 = one of ([[[a0+72]:8+16]:8+512] | one of 0x40000, 0x80000), ret(cmn_err).

- `ioc4_pckm_rmalias` in `IP35/usr/cpu/sysgen/IP35boot/ioc4_pckm.o` at 0x252c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc4_pckm.o`.
  Range: 0x252c-0x25f0 (196 bytes).
  It occupies 196 bytes.
  5 such `lw` accesses load 4 bytes from ?, including `lw` at 0x2550, `lw` at 0x2570, `lw` at 0x2584.
  5 such `ld` accesses load 8 bytes from ?, including `ld` at 0x255c, `ld` at 0x2580, `ld` at 0x259c.
  The `sw` at 0x25c0 stores 4 bytes to ?.
  The `jal` at 0x25a0 calls pckm_rmalias with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=?, a5=0x13.
  The `jal` at 0x25b0 calls mutex_lock with a0=?, a1=0x19, a2=?, a3=?.
  The `jal` at 0x25cc calls device_controller_num_set with a0=?, a1=-0x1, a2=?, a3=?.
  The `jal` at 0x25d4 calls mutex_unlock with a0=?, a1=?, a2=?, a3=?.
  The `beq` branch at 0x2540 targets 0x25dc, is taken when at(=[sym(.sdata)+8]:8) == 0, and falls through when at(=[sym(.sdata)+8]:8) != 0.
  The `beq` branch at 0x2548 targets 0x2568 and is always taken.
  The `bne` branch at 0x2554 targets 0x257c, is taken when a3(?) != a5(=0x13), and falls through when a3(?) == a5(=0x13).
  The `beq` branch at 0x2560 targets 0x25e0, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0x2568 targets 0x2550, is taken when a1 == 0, and falls through when a1 != 0.
  The `beq` branch at 0x2574 targets 0x255c, is taken when a3(?) == a5(=0x13), and falls through when a3(?) != a5(=0x13).
  The `bne` branch at 0x2588 targets 0x255c, is taken when v0(?) != a0, and falls through when v0(?) == a0.
  The `bnel` branch at 0x2598 targets 0x2560, is taken when (t8(?) & 0x2) != 0, and falls through when (t8(?) & 0x2) == 0; its branch-likely delay slot `ld s0,104(s0)` at 0x259c runs only when taken and is annulled on fall-through.
  The return at 0x25e8 has v0 = ?.
