# Readings: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`

One entry per routine, filed here from the reading batches by binary.

- `rad_ksync_notify` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0x0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0x0-0x8 (8 bytes).
  It occupies 8 bytes.
  The return at 0x0 has v0 = ?.

- `rad_create_subsys` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0x8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0x8-0x188 (384 bytes).
  It occupies 384 bytes.
  The `sw` at 0xac stores 4 bytes to ret(kmem_zalloc) +0x4f2c.
  The `sw` at 0xb4 stores 4 bytes to ret(kmem_zalloc) +0x154.
  The `sw` at 0xc0 stores 4 bytes to ret(kmem_zalloc) +0x158.
  The `sh` at 0xd8 stores 2 bytes to ret(kmem_zalloc) +0x150.
  The `sh` at 0xec stores 2 bytes to ret(kmem_zalloc) +0x152.
  The `lh` at 0x154 loads 2 bytes from ret(kmem_zalloc) +0x152.
  The `jal` at 0x28 calls pciio_config_get with a0=a2 at entry (arg2), a1=0x8, a2=0x4, a3=a3 at entry (arg3).
  The `jal` at 0x3c calls kmem_zalloc with a0=0x4f30, a1=0x0, a2=?, a3=?.
  The `jal` at 0x6c calls sprintf with a0=sp-144, a1=sym(.rodata)+64, a2=?, a3=?.
  The `jal` at 0x7c calls sprintf with a0=sp-112, a1=sym(.rodata)+72, a2=?, a3=?.
  The `jal` at 0xa4 calls kdsp_init_resource with a0=ret(kmem_zalloc), a1=0x2000001e, a2=sp-144, a3=sp-112, a4=0x0, a5=sym(.data)+192, a6=0x4f30.
  The `jal` at 0xf0 calls pciio_error_register with a0=a2 at entry (arg2), a1=sym(rad_error_handler), a2=ret(kmem_zalloc), a3=?, a4=a0 at entry (arg0).
  The `jal` at 0x10c calls hwgraph_char_device_add with a0=a2 at entry (arg2), a1=sym(.rodata)+48, a2=sym(.rodata)+80, a3=sp-80.
  The `jal` at 0x128 calls device_info_set with a0=?, a1=ret(kmem_zalloc), a2=?, a3=?.
  The `jal` at 0x14c calls device_inventory_add with a0=?, a1=0xa, a2=0x5, a3=-0x1, a4=0x0.
  The `jal` at 0x164 calls kdsp_add_subsys with a0=ret(kmem_zalloc), a1=one of 0x0, 0x64, a2=?, a3=?, a7=[ret(kmem_zalloc)+338]:2.
  The `bne` branch at 0x44 targets 0x64, is taken when v0(=ret(kmem_zalloc)) != 0, and falls through when v0(=ret(kmem_zalloc)) == 0.
  The `beq` branch at 0x114 targets 0x124, is taken when v0(=ret(hwgraph_char_device_add)) == 0, and falls through when v0(=ret(hwgraph_char_device_add)) != 0.
  The `beq` branch at 0x11c targets 0x50 and is always taken.
  The `beq` branch at 0x15c targets 0x180, is taken when a7(=[ret(kmem_zalloc)+338]:2) == t0(=0xd), and falls through when a7(=[ret(kmem_zalloc)+338]:2) != t0(=0xd).
  The `beq` branch at 0x178 targets 0x50 and is always taken.
  The `beq` branch at 0x180 targets 0x164 and is always taken.
  The return at 0x5c has v0 = one of 0x0, 0x1.

- `rad_open` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0x188 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0x188-0x190 (8 bytes).
  It occupies 8 bytes.
  The return at 0x188 has v0 = 0x0.

- `rad_ioctl` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0x190 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0x190-0x5b0 (1056 bytes).
  It occupies 1056 bytes.
  The `sw` at 0x1dc stores 4 bytes to ret(hwgraph_fastinfo_get) +0x1f4.
  The `sw` at 0x1e0 stores 4 bytes to ret(hwgraph_fastinfo_get) +0x1f0.
  The `sb` at 0x1e4 stores 1 byte to ret(hwgraph_fastinfo_get) +0x4f13.
  3 such `lh` accesses load 2 bytes from ret(hwgraph_fastinfo_get) +0x152, including `lh` at 0x20c, `lh` at 0x294, `lh` at 0x344.
  The `lbu` at 0x228 loads 1 byte from ?.
  The `sw` at 0x234 stores 4 bytes to ?.
  The `sw` at 0x260 stores 4 bytes to a5 (arg5 at entry) +0x0.
  The `lw` at 0x2d4 loads 4 bytes from ret(hwgraph_fastinfo_get) +0x1f0.
  The `lw` at 0x2e4 loads 4 bytes from ret(hwgraph_fastinfo_get) +0x1f4.
  The `lw` at 0x398 loads 4 bytes from ret(hwgraph_fastinfo_get) +0x4f2c.
  The `lw` at 0x3bc loads 4 bytes from ret(hwgraph_fastinfo_get) +0x158.
  The `lw` at 0x420 loads 4 bytes from ret(hwgraph_fastinfo_get) +0x154.
  The `lw` at 0x4c4 loads 4 bytes from ret(hwgraph_fastinfo_get) +0x4e84.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0x500, `lw` at 0x540.
  The `ll` at 0x514 loads 4 bytes from sym(fastick_callback_required_flags) +0x0.
  The `sc` at 0x51c stores 4 bytes to sym(fastick_callback_required_flags) +0x0.
  The `jal` at 0x1b4 calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x240 calls copyout with a0=sp-112, a1=a2 at entry (arg2), a2=0x14, a3=[ret(hwgraph_fastinfo_get)+338]:2, a6=0x2708.
  The `jal` at 0x2c4 calls update_ust with a0=0x16, a1=?, a2=?, a3=?.
  The `jal` at 0x2cc calls get_ust_nano with a0=sp-144, a1=?, a2=?, a3=?.
  The `jal` at 0x2ec calls copyout with a0=sp-144, a1=a2 at entry (arg2), a2=0x18, a3=?.
  The `jal` at 0x308 calls device_controller_num_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x328 calls sprintf with a0=ret(hwgraph_fastinfo_get)+160, a1=sym(.rodata)+224, a2=ret(device_controller_num_get), a3=?.
  The `jal` at 0x33c calls sprintf with a0=ret(hwgraph_fastinfo_get)+192, a1=sym(.rodata)+232, a2=ret(device_controller_num_get), a3=?.
  The `jal` at 0x37c calls kdsp_set_default_subsys_pri with a0=ret(hwgraph_fastinfo_get), a1=ret(device_controller_num_get), a2=0xd, a3=0x7.
  The `jal` at 0x390 calls hwgraph_path_add with a0=[sym(hwgraph_root)], a1=sym(.rodata)+240, a2=sp-176, a3=?.
  The `jal` at 0x3a4 calls hwgraph_edge_add with a0=?, a1=[ret(hwgraph_fastinfo_get)+20268], a2=ret(hwgraph_fastinfo_get)+160, a3=?.
  The `jal` at 0x3c0 calls sprintf with a0=sp-168, a1=sym(.rodata)+248, a2=[ret(hwgraph_fastinfo_get)+344], a3=?.
  The `jal` at 0x3c8 calls strlen with a0=sp-168, a1=?, a2=?, a3=?.
  The `jal` at 0x3d4 calls kern_malloc with a0=ret(strlen)+1, a1=?, a2=?, a3=?.
  The `jal` at 0x3e8 calls strcpy with a0=ret(kern_malloc), a1=sp-168, a2=?, a3=?.
  The `jal` at 0x400 calls hwgraph_info_add_LBL with a0=[ret(hwgraph_fastinfo_get)+20268], a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x410 calls hwgraph_info_export_LBL with a0=[ret(hwgraph_fastinfo_get)+20268], a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x424 calls sprintf with a0=sp-168, a1=sym(.rodata)+248, a2=[ret(hwgraph_fastinfo_get)+340], a3=?.
  The `jal` at 0x42c calls strlen with a0=sp-168, a1=?, a2=?, a3=?.
  The `jal` at 0x438 calls kern_malloc with a0=ret(strlen)+1, a1=?, a2=?, a3=?.
  The `jal` at 0x448 calls strcpy with a0=ret(kern_malloc), a1=sp-168, a2=?, a3=?.
  The `jal` at 0x458 calls hwgraph_info_add_LBL with a0=[ret(hwgraph_fastinfo_get)+20268], a1=sym(.rodata), a2=ret(kern_malloc), a3=?.
  The `jal` at 0x468 calls hwgraph_info_export_LBL with a0=[ret(hwgraph_fastinfo_get)+20268], a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x470 calls strlen with a0=ret(hwgraph_fastinfo_get)+160, a1=?, a2=?, a3=?.
  The `jal` at 0x47c calls kern_malloc with a0=ret(strlen)+1, a1=?, a2=?, a3=?.
  The `jal` at 0x48c calls strcpy with a0=ret(kern_malloc), a1=ret(hwgraph_fastinfo_get)+160, a2=?, a3=?.
  The `jal` at 0x49c calls hwgraph_info_add_LBL with a0=[ret(hwgraph_fastinfo_get)+20268], a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x4ac calls hwgraph_info_export_LBL with a0=[ret(hwgraph_fastinfo_get)+20268], a1=sym(.rodata), a2=ret(strlen)+1, a3=?.
  The `jal` at 0x4cc calls copyout with a0=sp-120, a1=a2 at entry (arg2), a2=0x4, a3=[ret(hwgraph_fastinfo_get)+20100], a6=0x2708.
  The `jal` at 0x4f0 calls strncmp with a0=?, a1=sym(.rodata)+256, a2=0x3, a3=?.
  The `jal` at 0x534 calls rad_stop_status_dma with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x548 calls rad_vl_write_MUX_SEL with a0=ret(hwgraph_fastinfo_get), a1=a2 at entry (arg2), a2=?, a3=?.
  The `jal` at 0x564 calls kdsp_set_default_subsys_pri with a0=ret(hwgraph_fastinfo_get), a1=ret(device_controller_num_get)+100, a2=0xd, a3=?.
  The `jal` at 0x580 calls cmn_err with a0=0x4, a1=sym(.rodata)+88, a2=a0 at entry (arg0), a3=?.
  The `jal` at 0x5a0 calls cmn_err with a0=0x4, a1=sym(.rodata)+128, a2=a0 at entry (arg0), a3=ret(device_controller_num_get).
  The `beq` branch at 0x1bc targets 0x574, is taken when v0(=ret(hwgraph_fastinfo_get)) == 0, and falls through when v0(=ret(hwgraph_fastinfo_get)) != 0.
  The `bne` branch at 0x1c8 targets 0x1f0, is taken when s0(=a1) < 0x270b (signed), and falls through when s0(=a1) >= 0x270b (signed).
  The `beq` branch at 0x1d4 targets 0x284, is taken when s0(=a1) >= 0x270c (signed), and falls through when s0(=a1) < 0x270c (signed).
  The `beq` branch at 0x1e8 targets 0x25c and is always taken.
  The `bne` branch at 0x1f0 targets 0x250, is taken when v1(?) != 0, and falls through when v1(?) == 0.
  The `bne` branch at 0x1fc targets 0x4bc, is taken when s0(=a1) < 0x270a (signed), and falls through when s0(=a1) >= 0x270a (signed).
  The `bne` branch at 0x204 targets 0x25c, is taken when s0(=a1) != a1(=0x270a), and falls through when s0(=a1) == a1(=0x270a).
  The `bne` branch at 0x230 targets 0x21c, is taken when a1(?) < 0x4 (signed), and falls through when a1(?) >= 0x4 (signed).
  The `beq` branch at 0x248 targets 0x25c and is always taken.
  The `beq` branch at 0x250 targets 0x4dc, is taken when s0(=a1) == a6(=0x2708), and falls through when s0(=a1) != a6(=0x2708).
  The `bne` branch at 0x284 targets 0x2b8, is taken when t0(?) != 0, and falls through when t0(?) == 0.
  The `beq` branch at 0x28c targets 0x2fc, is taken when t1(?) == 0, and falls through when t1(?) != 0.
  The `beq` branch at 0x29c targets 0x548, is taken when v0(=[ret(hwgraph_fastinfo_get)+338]:2) == t2(=0x7), and falls through when v0(=[ret(hwgraph_fastinfo_get)+338]:2) != t2(=0x7).
  The `beq` branch at 0x2a8 targets 0x548, is taken when v0(=[ret(hwgraph_fastinfo_get)+338]:2) == t3(=0xd), and falls through when v0(=[ret(hwgraph_fastinfo_get)+338]:2) != t3(=0xd).
  The `beq` branch at 0x2b0 targets 0x25c and is always taken.
  The `bne` branch at 0x2bc targets 0x25c, is taken when s0(=a1) != t8(=0x270c), and falls through when s0(=a1) == t8(=0x270c).
  The `beq` branch at 0x2f4 targets 0x25c and is always taken.
  The `bne` branch at 0x300 targets 0x25c, is taken when s0(=a1) != at(=0x6d687767), and falls through when s0(=a1) == at(=0x6d687767).
  The `bltz` branch at 0x310 targets 0x590, is taken when v0(=ret(device_controller_num_get)) < 0 (signed), and falls through when v0(=ret(device_controller_num_get)) >= 0 (signed).
  The `beq` branch at 0x34c targets 0x564, is taken when v0(=[ret(hwgraph_fastinfo_get)+338]:2) == a2(=0xd), and falls through when v0(=[ret(hwgraph_fastinfo_get)+338]:2) != a2(=0xd).
  The `bne` branch at 0x358 targets 0x37c, is taken when v0(=[ret(hwgraph_fastinfo_get)+338]:2) != a3(=0x7), and falls through when v0(=[ret(hwgraph_fastinfo_get)+338]:2) == a3(=0x7).
  The `beq` branch at 0x364 targets 0x374, is taken when v0(=[sym(.sbss)]) == 0, and falls through when v0(=[sym(.sbss)]) != 0.
  The `bne` branch at 0x36c targets 0x564, is taken when s0(=ret(device_controller_num_get)) != v0(=[sym(.sbss)]), and falls through when s0(=ret(device_controller_num_get)) == v0(=[sym(.sbss)]).
  The `beq` branch at 0x3b0 targets 0x558, is taken when v0(=ret(hwgraph_edge_add)) == a2(=0x1), and falls through when v0(=ret(hwgraph_edge_add)) != a2(=0x1).
  The `beq` branch at 0x4b4 targets 0x25c and is always taken.
  The `beq` branch at 0x4d4 targets 0x25c and is always taken.
  The `beq` branch at 0x4dc targets 0x50c, is taken when a4(=[sym(kdsp_sstab)]) == 0, and falls through when a4(=[sym(kdsp_sstab)]) != 0.
  The `beq` branch at 0x4f8 targets 0x534, is taken when v0(=ret(strncmp)) == 0, and falls through when v0(=ret(strncmp)) != 0.
  The `bne` branch at 0x504 targets 0x4e8, is taken when s0(?) != 0, and falls through when s0(?) == 0.
  The `beql` branch at 0x520 targets 0x514, is taken when (a2(=[sym(fastick_callback_required_flags)]) & a4(=-0x3)) == 0, and falls through when (a2(=[sym(fastick_callback_required_flags)]) & a4(=-0x3)) != 0; its branch-likely delay slot `nop` at 0x524 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x52c targets 0x25c and is always taken.
  The `beq` branch at 0x53c targets 0x504 and is always taken.
  The `beq` branch at 0x550 targets 0x25c and is always taken.
  The `beq` branch at 0x558 targets 0x264 and is always taken.
  The `beq` branch at 0x56c targets 0x388 and is always taken.
  The `beq` branch at 0x588 targets 0x264 and is always taken.
  The `beq` branch at 0x5a8 targets 0x25c and is always taken.
  The return at 0x27c has v0 = one of ?, 0x0, 0x5.
  The instructions from 0x544 to 0x544 are not reached by any path from the entry, and their branches are not listed.
  The instructions from 0x560 to 0x560 are not reached by any path from the entry, and their branches are not listed.

- `rad_close` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0x5b0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0x5b0-0x604 (84 bytes).
  It occupies 84 bytes.
  The `sb` at 0x5cc stores 1 byte to ret(hwgraph_fastinfo_get) +0x4f13.
  The `sw` at 0x5d0 stores 4 bytes to ret(hwgraph_fastinfo_get) +0x1f4.
  The `sw` at 0x5d4 stores 4 bytes to ret(hwgraph_fastinfo_get) +0x1f0.
  The `jal` at 0x5b8 calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x5f4 calls cmn_err with a0=0x4, a1=sym(.rodata)+264, a2=a0 at entry (arg0), a3=ret(hwgraph_fastinfo_get), a4=0x1.
  The `beq` branch at 0x5c4 targets 0x5e8, is taken when v0(=ret(hwgraph_fastinfo_get)) == 0, and falls through when v0(=ret(hwgraph_fastinfo_get)) != 0.
  The `beq` branch at 0x5fc targets 0x5dc and is always taken.
  The return at 0x5e0 has v0 = one of 0x0, 0x5.

- `rad_start_subsys` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0x604 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0x604-0xee4 (2272 bytes).
  It occupies 2272 bytes.
  The `sw` at 0x61c stores 4 bytes to sym(.bss) +0x158.
  The `sw` at 0x620 stores 4 bytes to sym(.bss) +0x150.
  The `sw` at 0x62c stores 4 bytes to sym(.bss) +0x148.
  The `sw` at 0x638 stores 4 bytes to sym(.bss) +0x140.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x4f2c, including `lw` at 0x644, `lw` at 0x658.
  30 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x158, including `lw` at 0x660, `lw` at 0x6ac, `lw` at 0x6d0.
  5 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x4e50, including `sw` at 0x668, `sw` at 0x6c8, `sw` at 0x81c.
  4 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x4e50, including `lw` at 0x680, `lw` at 0x808, `lw` at 0x83c.
  12 such `lh` accesses load 2 bytes from a0 (arg0 at entry) +0x152, including `lh` at 0x6f4, `lh` at 0x754, `lh` at 0x78c.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x4e58, including `sw` at 0x710, `sw` at 0xd10.
  The `sw` at 0x72c stores 4 bytes to a0 (arg0 at entry) +0x4e5c.
  The `sw` at 0x740 stores 4 bytes to a0 (arg0 at entry) +0x4e60.
  The `sw` at 0x768 stores 4 bytes to a0 (arg0 at entry) +0x4e68.
  The `sw` at 0x780 stores 4 bytes to a0 (arg0 at entry) +0x4e64.
  The `sw` at 0x79c stores 4 bytes to a0 (arg0 at entry) +0x4e6c.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x4e54, including `sw` at 0x7d0, `sw` at 0xcc8.
  The `sw` at 0x8d4 stores 4 bytes to a0 (arg0 at entry) +0x4ed4.
  The `sw` at 0x8d8 stores 4 bytes to a0 (arg0 at entry) +0x4ed0.
  The `sw` at 0x8e0 stores 4 bytes to a0 (arg0 at entry) +0x4ec4.
  The `sw` at 0x8e4 stores 4 bytes to a0 (arg0 at entry) +0x4ec0.
  The `sw` at 0x8e8 stores 4 bytes to a0 (arg0 at entry) +0x4ecc.
  The `sw` at 0x8f0 stores 4 bytes to a0 (arg0 at entry) +0x4ec8.
  The `sw` at 0x900 stores 4 bytes to a0 (arg0 at entry) +0x4e70.
  The `sw` at 0x970 stores 4 bytes to a0 (arg0 at entry) +0xa7c.
  The `sw` at 0x97c stores 4 bytes to a0 (arg0 at entry) +0x918.
  The `sw` at 0x988 stores 4 bytes to a0 (arg0 at entry) +0x91c.
  The `sw` at 0x990 stores 4 bytes to a0 (arg0 at entry) +0x920.
  The `sw` at 0x9a0 stores 4 bytes to a0 (arg0 at entry) +0xa3c.
  The `sw` at 0x9b8 stores 4 bytes to a0 (arg0 at entry) +0xc64.
  The `sw` at 0x9c0 stores 4 bytes to a0 (arg0 at entry) +0xb48.
  The `sw` at 0x9c8 stores 4 bytes to a0 (arg0 at entry) +0xb44.
  The `sw` at 0x9d0 stores 4 bytes to a0 (arg0 at entry) +0xb40.
  The `sw` at 0x9d8 stores 4 bytes to a0 (arg0 at entry) +0xca4.
  The `sw` at 0xa48 stores 4 bytes to a0 (arg0 at entry) +0xd70.
  The `sw` at 0xa50 stores 4 bytes to a0 (arg0 at entry) +0xd6c.
  The `sw` at 0xa58 stores 4 bytes to a0 (arg0 at entry) +0xd68.
  The `sw` at 0xa64 stores 4 bytes to a0 (arg0 at entry) +0xecc.
  The `sw` at 0xaa0 stores 4 bytes to a0 (arg0 at entry) +0x10b4.
  The `sw` at 0xaac stores 4 bytes to a0 (arg0 at entry) +0xf98.
  The `sw` at 0xab4 stores 4 bytes to a0 (arg0 at entry) +0xf94.
  The `sw` at 0xabc stores 4 bytes to a0 (arg0 at entry) +0xf90.
  The `sw` at 0xac8 stores 4 bytes to a0 (arg0 at entry) +0x10f4.
  The `sw` at 0xaf8 stores 4 bytes to a0 (arg0 at entry) +0x11c0.
  The `sw` at 0xb04 stores 4 bytes to a0 (arg0 at entry) +0x131c.
  The `sw` at 0xb1c stores 4 bytes to a0 (arg0 at entry) +0x11bc.
  The `sw` at 0xb28 stores 4 bytes to a0 (arg0 at entry) +0x11b8.
  The `sw` at 0xb40 stores 4 bytes to a0 (arg0 at entry) +0x1504.
  The `sw` at 0xb4c stores 4 bytes to a0 (arg0 at entry) +0x13e8.
  The `sw` at 0xb50 stores 4 bytes to a0 (arg0 at entry) +0x1544.
  The `sw` at 0xb60 stores 4 bytes to a0 (arg0 at entry) +0x13e4.
  The `sw` at 0xb6c stores 4 bytes to a0 (arg0 at entry) +0x13e0.
  The `lw` at 0xc1c loads 4 bytes from a0 (arg0 at entry) +0x30.
  The `lw` at 0xc50 loads 4 bytes from ?.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x138, including `sw` at 0xc80, `sw` at 0xe8c.
  The `sw` at 0xc8c stores 4 bytes to a0 (arg0 at entry) +0x13c.
  The `lw` at 0xcb4 loads 4 bytes from a0 (arg0 at entry) +0x4e54.
  3 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x4e80, including `sw` at 0xd54, `sw` at 0xde0, `sw` at 0xe54.
  3 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x4e7c, including `sw` at 0xd68, `sw` at 0xdc4, `sw` at 0xdf4.
  3 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x4e78, including `sw` at 0xd7c, `sw` at 0xe08, `sw` at 0xed0.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x4e74, including `sw` at 0xd94, `sw` at 0xe1c.
  3 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x4e84, including `sw` at 0xda0, `sw` at 0xe2c, `sw` at 0xeb8.
  2 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x4f12, including `sb` at 0xda8, `sb` at 0xec4.
  The `lw` at 0xea8 loads 4 bytes from a0 (arg0 at entry) +0x4e84.
  The `jal` at 0x640 calls pciio_config_set with a0=[a0+20268], a1=0x4, a2=0x4, a3=0x6.
  The `jal` at 0x654 calls pciio_config_set with a0=[a0+20268], a1=0xc, a2=0x4, a3=-0x1.
  The `jal` at 0x66c calls pciio_pio_write32 with a0=-0x1, a1=[a0+344]+128, a2=-0x1, a3=?.
  The `jal` at 0x674 calls us_delay with a0=0x3e8, a1=?, a2=?, a3=?.
  The `jal` at 0x6c4 calls pciio_pio_write32 with a0=?, a1=[a0+344]+128, a2=0xffffffffffefffff, a3=0xfffffffffff7ffff.
  The `jal` at 0x6d8 calls pciio_pio_write32 with a0=0x8000010, a1=[a0+344]+116, a2=?, a3=?.
  The `jal` at 0x6ec calls pciio_pio_write32 with a0=0xfac688, a1=[a0+344]+120, a2=?, a3=?.
  The `jal` at 0x718 calls pciio_pio_write32 with a0=one of 0x3000000, 0x5000000, a1=[a0+344]+76, a2=0xc, a3=?.
  The `jal` at 0x730 calls pciio_pio_write32 with a0=0x20000000, a1=[a0+344]+88, a2=?, a3=?.
  The `jal` at 0x74c calls pciio_pio_write32 with a0=0x10, a1=[a0+344]+72, a2=0x10, a3=?.
  The `jal` at 0x76c calls pciio_pio_write32 with a0=one of 0x0, 0x40000000, a1=[a0+344]+84, a2=?, a3=[a0+338]:2.
  The `jal` at 0x784 calls pciio_pio_write32 with a0=0xffffffffa0000008, a1=[a0+344]+68, a2=?, a3=?.
  The `jal` at 0x7a0 calls pciio_pio_write32 with a0=one of 0x20000000, 0x60000000, a1=[a0+344]+80, a2=[a0+338]:2, a3=?.
  The `jal` at 0x7d4 calls pciio_pio_write32 with a0=0x1500, a1=[a0+344]+112, a2=0x1500, a3=?.
  The `jal` at 0x7ec calls pciio_pio_write32 with a0=0xffffffff9fffffff, a1=[a0+344]+184, a2=?, a3=?.
  The `jal` at 0x7fc calls pciio_pio_write32 with a0=0xffffffff9fffffff, a1=[a0+344]+188, a2=?, a3=?.
  The `jal` at 0x818 calls pciio_pio_write32 with a0=?, a1=[a0+344]+128, a2=-0xf01, a3=?.
  The `jal` at 0x820 calls us_delay with a0=0x3e8, a1=?, a2=?, a3=?.
  The `jal` at 0x834 calls pciio_pio_write32 with a0=0x2000001, a1=[a0+344]+160, a2=?, a3=?.
  The `jal` at 0x880 calls pciio_pio_write32 with a0=?, a1=[a0+344]+128, a2=0xfffffffffffeffff, a3=-0x8001.
  The `jal` at 0x888 calls us_delay with a0=0x3e8, a1=?, a2=?, a3=?.
  The `jal` at 0x8bc calls pciio_pio_write32 with a0=?, a1=[a0+344]+128, a2=-0x4001, a3=?.
  The `jal` at 0x904 calls pciio_pio_write32 with a0=0xffffffffd6d6d6d6, a1=[a0+344]+124, a2=0xd6, a3=0xc0.
  The `jal` at 0x90c calls rad_init_subsys with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x94c calls rad_create_device with a0=a0 at entry (arg0), a1=a0+2280, a2=0x0, a3=0x400, a4=0x0, a5=sym(.rodata), a6=sym(.rodata), a7=0x2.
  The `jal` at 0x9a8 calls rad_create_device with a0=a0 at entry (arg0), a1=a0+2832, a2=0x1, a3=0x400, a4=0x1, a5=sym(.rodata), a6=sym(.rodata), a7=0x2.
  The `jal` at 0xa18 calls rad_create_device with a0=a0 at entry (arg0), a1=a0+3384, a2=0x0, a3=0x400, a4=0x2, a5=sym(.rodata)+384, a6=sym(.rodata)+392, a7=0x2.
  The `jal` at 0xa74 calls rad_create_device with a0=a0 at entry (arg0), a1=a0+3936, a2=0x1, a3=0x400, a4=0x3, a5=sym(.rodata)+400, a6=sym(.rodata)+408, a7=0x2.
  The `jal` at 0xad8 calls rad_create_device with a0=a0 at entry (arg0), a1=a0+4488, a2=0x0, a3=0x1000, a4=0x4, a5=sym(.rodata)+416, a6=sym(.rodata)+424, a7=0x8.
  The `jal` at 0xb30 calls rad_create_device with a0=a0 at entry (arg0), a1=a0+5040, a2=0x1, a3=0x1000, a4=0x5, a5=sym(.rodata)+432, a6=sym(.rodata), a7=0x8.
  The `jal` at 0xb68 calls rad_create_mclks with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xb88 calls rad_create_clockgen with a0=a0+17496, a1=a0+2280, a2=0x0, a3=a0+800.
  The `jal` at 0xba0 calls rad_create_clockgen with a0=a0+17880, a1=a0+2832, a2=0x1, a3=a0+800.
  The `jal` at 0xbb8 calls rad_create_clockgen with a0=a0+19032, a1=a0+3384, a2=0x4, a3=a0+1392.
  The `jal` at 0xbd4 calls rad_create_clockgen with a0=a0+18264, a1=a0+3936, a2=0x2, a3=a0+800.
  The `jal` at 0xbec calls rad_create_clockgen with a0=a0+19416, a1=a0+4488, a2=0x5, a3=a0+1096.
  The `jal` at 0xc04 calls rad_create_clockgen with a0=a0+18648, a1=a0+5040, a2=0x3, a3=a0+800.
  The `jal` at 0xc14 calls rad_create_ifs with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xc2c calls rad_start_device with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xc5c calls rad_create_subcodes with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xc68 calls kdsp_map_resource with a0=a0 at entry (arg0), a1=0x0, a2=?, a3=?.
  The `jal` at 0xc90 calls us_delay with a0=0xf4240, a1=(a0 + one of 0xb10, 0xf60), a2=?, a3=?.
  The `jal` at 0xcc4 calls pciio_pio_write32 with a0=?, a1=[a0+344]+112, a2=-0x101, a3=?.
  The `jal` at 0xd58 calls pciio_pio_write32 with a0=0x2, a1=[a0+344]+144, a2=?, a3=?.
  The `jal` at 0xd6c calls pciio_pio_write32 with a0=0x2, a1=[a0+344]+140, a2=?, a3=?.
  The `jal` at 0xd80 calls pciio_pio_write32 with a0=0x2, a1=[a0+344]+136, a2=?, a3=?.
  The `jal` at 0xd98 calls pciio_pio_write32 with a0=0x0, a1=[a0+344]+132, a2=?, a3=?.
  The `jal` at 0xdac calls rad_vl_write_MUX_SEL with a0=a0 at entry (arg0), a1=0x0, a2=?, a3=?.
  The `jal` at 0xdc8 calls pciio_pio_write32 with a0=0x2, a1=[a0+344]+140, a2=0x2, a3=?.
  The `jal` at 0xde4 calls pciio_pio_write32 with a0=0x0, a1=[a0+344]+144, a2=?, a3=?.
  The `jal` at 0xdf8 calls pciio_pio_write32 with a0=0x0, a1=[a0+344]+140, a2=?, a3=?.
  The `jal` at 0xe0c calls pciio_pio_write32 with a0=0x0, a1=[a0+344]+136, a2=?, a3=?.
  The `jal` at 0xe20 calls pciio_pio_write32 with a0=0x0, a1=[a0+344]+132, a2=?, a3=?.
  The `jal` at 0xe30 calls rad_vl_write_MUX_SEL with a0=a0 at entry (arg0), a1=0x0, a2=?, a3=?.
  The `jal` at 0xe58 calls pciio_pio_write32 with a0=0x2, a1=[a0+344]+144, a2=0x2, a3=?.
  The `jal` at 0xeb4 calls rad_vl_write_MUX_SEL with a0=a0 at entry (arg0), a1=([a0+20100] | 0x2000), a2=?, a3=?.
  The `jal` at 0xed4 calls pciio_pio_write32 with a0=0x3, a1=[a0+344]+136, a2=0x3, a3=?.
  The `beq` branch at 0x700 targets 0xd04, is taken when a1(=[a0+338]:2) == a2(=0xc), and falls through when a1(=[a0+338]:2) != a2(=0xc).
  The `beq` branch at 0x75c targets 0xd14, is taken when a3(=[a0+338]:2) == s1(=0xd), and falls through when a3(=[a0+338]:2) != s1(=0xd).
  The `beq` branch at 0x790 targets 0xd1c, is taken when a2(=[a0+338]:2) == s1(=0xd), and falls through when a2(=[a0+338]:2) != s1(=0xd).
  The `beq` branch at 0x7b0 targets 0xd4c, is taken when v0(=[a0+338]:2) == a1(=0x7), and falls through when v0(=[a0+338]:2) != a1(=0x7).
  The `beq` branch at 0x7b8 targets 0xdd8, is taken when v0(=[a0+338]:2) == s1(=0xd), and falls through when v0(=[a0+338]:2) != s1(=0xd).
  The `beq` branch at 0x7c0 targets 0xe48, is taken when v0(=[a0+338]:2) == s2(=0xc), and falls through when v0(=[a0+338]:2) != s2(=0xc).
  The `beq` branch at 0x8c8 targets 0xdbc, is taken when v0(=[a0+338]:2) == s2(=0xc), and falls through when v0(=[a0+338]:2) != s2(=0xc).
  The `beq` branch at 0x8ec targets 0x90c, is taken when v0(=[a0+338]:2) == s1(=0xd), and falls through when v0(=[a0+338]:2) != s1(=0xd).
  The `beq` branch at 0x914 targets 0xd3c, is taken when v0(=ret(rad_init_subsys)) == 0, and falls through when v0(=ret(rad_init_subsys)) != 0.
  The `beq` branch at 0x920 targets 0x9dc, is taken when a2(=[a0+338]:2) == s1(=0xd), and falls through when a2(=[a0+338]:2) != s1(=0xd).
  The `beq` branch at 0x954 targets 0xce0, is taken when v0(=ret(rad_create_device)) == 0, and falls through when v0(=ret(rad_create_device)) != 0.
  The `beq` branch at 0x9b0 targets 0xd44, is taken when v0(=ret(rad_create_device)) == 0, and falls through when v0(=ret(rad_create_device)) != 0.
  The `beq` branch at 0xa20 targets 0xcfc, is taken when v0(=ret(rad_create_device)) == 0, and falls through when v0(=ret(rad_create_device)) != 0.
  The `beq` branch at 0xa7c targets 0xd24, is taken when v0(=ret(rad_create_device)) == 0, and falls through when v0(=ret(rad_create_device)) != 0.
  The `beq` branch at 0xae0 targets 0xd2c, is taken when v0(=ret(rad_create_device)) == 0, and falls through when v0(=ret(rad_create_device)) != 0.
  The `beq` branch at 0xb38 targets 0xd34, is taken when v0(=ret(rad_create_device)) == 0, and falls through when v0(=ret(rad_create_device)) != 0.
  The `beq` branch at 0xb74 targets 0xbac, is taken when ra(=[a0+338]:2) == s1(=0xd), and falls through when ra(=[a0+338]:2) != s1(=0xd).
  The `beq` branch at 0xb90 targets 0xe40, is taken when v0(=ret(rad_create_clockgen)) == 0, and falls through when v0(=ret(rad_create_clockgen)) != 0.
  The `beq` branch at 0xba8 targets 0xe70, is taken when v0(=ret(rad_create_clockgen)) == 0, and falls through when v0(=ret(rad_create_clockgen)) != 0.
  The `beq` branch at 0xbc0 targets 0xe68, is taken when v0(=ret(rad_create_clockgen)) == 0, and falls through when v0(=ret(rad_create_clockgen)) != 0.
  The `beq` branch at 0xbdc targets 0xe78, is taken when v0(=ret(rad_create_clockgen)) == 0, and falls through when v0(=ret(rad_create_clockgen)) != 0.
  The `beq` branch at 0xbf4 targets 0xe80, is taken when v0(=ret(rad_create_clockgen)) == 0, and falls through when v0(=ret(rad_create_clockgen)) != 0.
  The `beq` branch at 0xc0c targets 0xe98, is taken when v0(=ret(rad_create_clockgen)) == 0, and falls through when v0(=ret(rad_create_clockgen)) != 0.
  The `beq` branch at 0xc20 targets 0xc5c, is taken when a1(=[a0+48]) == 0, and falls through when a1(=[a0+48]) != 0.
  The `beq` branch at 0xc38 targets 0xea0, is taken when v0(=ret(rad_start_device)) == 0, and falls through when v0(=ret(rad_start_device)) != 0.
  The `beq` branch at 0xc48 targets 0xc5c, is taken when a0(?) >= 0x18 (signed), and falls through when a0(?) < 0x18 (signed).
  The `bne` branch at 0xc54 targets 0xc2c, is taken when a1(?) != 0, and falls through when a1(?) == 0.
  The `beq` branch at 0xc74 targets 0xe88, is taken when v0(=[a0+338]:2) == s1(=0xd), and falls through when v0(=[a0+338]:2) != s1(=0xd).
  The `beq` branch at 0xc7c targets 0xe90, is taken when v0(=[a0+338]:2) == s1(=0xd), and falls through when v0(=[a0+338]:2) != s1(=0xd).
  The `beq` branch at 0xca0 targets 0xea8, is taken when v0(=[a0+338]:2) == a1(=0x7), and falls through when v0(=[a0+338]:2) != a1(=0x7).
  The `beq` branch at 0xca8 targets 0xcd4, is taken when v0(=[a0+338]:2) == s1(=0xd), and falls through when v0(=[a0+338]:2) != s1(=0xd).
  The `beq` branch at 0xcd4 targets 0xec8, is taken when v0(=[a0+338]:2) == a2(=0xc), and falls through when v0(=[a0+338]:2) != a2(=0xc).
  The `beq` branch at 0xcfc targets 0xce0 and is always taken.
  The `beq` branch at 0xd0c targets 0x714 and is always taken.
  The `beq` branch at 0xd14 targets 0x764 and is always taken.
  The `beq` branch at 0xd1c targets 0x798 and is always taken.
  The `beq` branch at 0xd24 targets 0xce0 and is always taken.
  The `beq` branch at 0xd2c targets 0xce0 and is always taken.
  The `beq` branch at 0xd34 targets 0xce0 and is always taken.
  The `beq` branch at 0xd3c targets 0xce0 and is always taken.
  The `beq` branch at 0xd44 targets 0xce0 and is always taken.
  The `beq` branch at 0xdb4 targets 0x7c8 and is always taken.
  The `beq` branch at 0xdd0 targets 0x8d0 and is always taken.
  The `beq` branch at 0xe38 targets 0x7c8 and is always taken.
  The `beq` branch at 0xe40 targets 0xce0 and is always taken.
  The `beq` branch at 0xe60 targets 0x7c8 and is always taken.
  The `beq` branch at 0xe68 targets 0xce0 and is always taken.
  The `beq` branch at 0xe70 targets 0xce0 and is always taken.
  The `beq` branch at 0xe78 targets 0xce0 and is always taken.
  The `beq` branch at 0xe80 targets 0xce0 and is always taken.
  The `bne` branch at 0xe88 targets 0xc84, is taken when v0(=[a0+338]:2) != s1(=0xd), and falls through when v0(=[a0+338]:2) == s1(=0xd).
  The `beq` branch at 0xe90 targets 0xc88 and is always taken.
  The `beq` branch at 0xe98 targets 0xce0 and is always taken.
  The `beq` branch at 0xea0 targets 0xce0 and is always taken.
  The `beq` branch at 0xec0 targets 0xca8 and is always taken.
  The `beq` branch at 0xedc targets 0xcdc and is always taken.
  The return at 0xcf4 has v0 = one of 0x0, 0x1.

- `rad_enable_ust` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0xee4 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0xee4-0xf24 (64 bytes).
  It occupies 64 bytes.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x158, including `lw` at 0xee8, `lw` at 0xf04.
  The `jal` at 0xefc calls pciio_pio_write32 with a0=0xe, a1=[a0+344]+64, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xf0c calls pciio_pio_write32 with a0=0xa, a1=[a0+344]+64, a2=?, a3=?.
  The return at 0xf1c has v0 = ret(pciio_pio_write32).

- `rad_disable_ust` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0xf24 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0xf24-0xf64 (64 bytes).
  It occupies 64 bytes.
  The `lh` at 0xf24 loads 2 bytes from a0 (arg0 at entry) +0x152.
  The `lw` at 0xf48 loads 4 bytes from a0 (arg0 at entry) +0x158.
  The `jal` at 0xf50 calls pciio_pio_write32 with a0=0x2, a1=[a0+344]+64, a2=[a0+338]:2, a3=0xd, a4=a0 at entry (arg0).
  The `beq` branch at 0xf38 targets 0xf58, is taken when a2(=[a0+338]:2) == at(=0x7), and falls through when a2(=[a0+338]:2) != at(=0x7).
  The `beq` branch at 0xf40 targets 0xf5c, is taken when a2(=[a0+338]:2) == a3(=0xd), and falls through when a2(=[a0+338]:2) != a3(=0xd).
  The return at 0xf5c has v0 = ?.

- `rad_reset_ust` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0xf64 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0xf64-0xfc0 (92 bytes).
  It occupies 92 bytes.
  The `lh` at 0xf64 loads 2 bytes from a0 (arg0 at entry) +0x152.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x158, including `lw` at 0xf94, `lw` at 0xfa8.
  The `jal` at 0xf9c calls pciio_pio_write32 with a0=0x4, a1=[a0+344]+64, a2=[a0+338]:2, a3=0xd.
  The `jal` at 0xfb0 calls pciio_pio_write32 with a0=0x0, a1=[a0+344]+64, a2=?, a3=?.
  The `beq` branch at 0xf78 targets 0xf90, is taken when a2(=[a0+338]:2) == at(=0x7), and falls through when a2(=[a0+338]:2) != at(=0x7).
  The `beq` branch at 0xf80 targets 0xf90, is taken when a2(=[a0+338]:2) == a3(=0xd), and falls through when a2(=[a0+338]:2) != a3(=0xd).
  The `beq` branch at 0xfb8 targets 0xf88 and is always taken.
  The return at 0xf88 has v0 = one of ?, ret(pciio_pio_write32).

- `rad_set_ust_offset` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0xfc0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0xfc0-0x1064 (164 bytes).
  It occupies 164 bytes.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x158, including `lw` at 0xff4, `lw` at 0x101c.
  The `sd` at 0x1004 stores 8 bytes to a0 (arg0 at entry) +0x4eb8.
  The `lw` at 0x1050 loads 4 bytes from a0 (arg0 at entry) +0x4f2c.
  The `jal` at 0x1008 calls pciio_pio_read32 with a0=[a0+344]+48, a1=?, a2=?, a3=a3 at entry (arg3).
  The `jal` at 0x1014 calls us_delay with a0=0xa, a1=?, a2=?, a3=?.
  The `jal` at 0x1020 calls pciio_pio_read32 with a0=[a0+344]+48, a1=?, a2=?, a3=?.
  The `jal` at 0x1054 calls cmn_err with a0=0x1, a1=sym(.rodata)+440, a2=[a0+20268], a3=?.
  The `bne` branch at 0x1030 targets 0x1048, is taken when a1(?) < 0x3 (unsigned), and falls through when a1(?) >= 0x3 (unsigned).
  The `beq` branch at 0x105c targets 0x1038 and is always taken.
  The return at 0x1040 has v0 = one of ret(pciio_pio_read32), ret(cmn_err).

- `rad_create_device` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0x1064 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0x1064-0x15a4 (1344 bytes).
  It occupies 1344 bytes.
  The `sw` at 0x1110 stores 4 bytes to a1 (arg1 at entry) +0x1d0.
  The `sw` at 0x1118 stores 4 bytes to a1 (arg1 at entry) +0x1cc.
  The `sw` at 0x1120 stores 4 bytes to a1 (arg1 at entry) +0x94.
  The `sw` at 0x1134 stores 4 bytes to a1 (arg1 at entry) +0x14c.
  The `sw` at 0x1140 stores 4 bytes to a1 (arg1 at entry) +0x158.
  The `sw` at 0x114c stores 4 bytes to a1 (arg1 at entry) +0x1c4.
  The `sw` at 0x1158 stores 4 bytes to a1 (arg1 at entry) +0x1b8.
  The `sw` at 0x1164 stores 4 bytes to a1 (arg1 at entry) +0xc.
  The `sw` at 0x116c stores 4 bytes to a1 (arg1 at entry) +0x4.
  The `sw` at 0x1178 stores 4 bytes to a1 (arg1 at entry) +0x1c0.
  The `sw` at 0x1188 stores 4 bytes to a1 (arg1 at entry) +0x10.
  2 such `sw` accesses store 4 bytes to a1 (arg1 at entry) +0x1bc, including `sw` at 0x1194, `sw` at 0x12e0.
  The `sw` at 0x11a0 stores 4 bytes to a1 (arg1 at entry) +0x1e0.
  The `sw` at 0x11b0 stores 4 bytes to a1 (arg1 at entry) +0x1c8.
  The `sw` at 0x11bc stores 4 bytes to a1 (arg1 at entry) +0x20c.
  The `lh` at 0x11d8 loads 2 bytes from table(sym(.data)) +0x0.
  The `lw` at 0x11dc loads 4 bytes from table(sym(.data)) +0x10.
  3 such `sw` accesses store 4 bytes to a1 (arg1 at entry) +0x214, including `sw` at 0x11f0, `sw` at 0x12f0, `sw` at 0x1300.
  3 such `sw` accesses store 4 bytes to a1 (arg1 at entry) +0x210, including `sw` at 0x11fc, `sw` at 0x12e4, `sw` at 0x12f4.
  The `lw` at 0x121c loads 4 bytes from (sym(.rodata)+472 + (a4+2 << 0x2)) +0x0.
  The `jal` at 0x10b0 calls kmem_alloc with a0=(a3 << 0x2), a1=0x8800, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x10e0 calls kdsp_init_resource with a0=a1 at entry (arg1), a1=one of 0x2000001b, 0x2000001c, a2=a5 at entry (arg5), a3=a6 at entry (arg6), a4=a0 at entry (arg0), a5=0x0, a6=0x228.
  The `jal` at 0x1100 calls kdsp_create_device with a0=a1 at entry (arg1), a1=a3 at entry (arg3), a2=(a2 | 0x40), a3=0x0, a4=ret(kmem_alloc), a5=a7 at entry (arg7).
  Calls (unknown callee) via register with a0=-0x2, a1=?, a2=sym(.data), a3=?, a4=a0+20068, a5=sym(rad_pre_connect), a6=0x29, a7=0x1 (`jr` at 0x1220).
  The `jal` at 0x1594 calls rad_destroy_devices with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `beq` branch at 0x10c0 targets 0x12d4, is taken when s3(=a2) == a2(=0x1), and falls through when s3(=a2) != a2(=0x1).
  The `beq` branch at 0x1108 targets 0x1594, is taken when v0(=ret(kdsp_create_device)) == 0, and falls through when v0(=ret(kdsp_create_device)) != 0.
  The `beq` branch at 0x1184 targets 0x12dc, is taken when s3(=a2) == 0, and falls through when s3(=a2) != 0.
  The `beq` branch at 0x11b8 targets 0x12f4, is taken when s2(=a4) == a0(=-0x2), and falls through when s2(=a4) != a0(=-0x2).
  The `beq` branch at 0x11c4 targets 0x12e4, is taken when s2(=a4) == t2(=-0x1), and falls through when s2(=a4) != t2(=-0x1).
  The `beq` branch at 0x1214 targets 0x1228, is taken when v1(=a4+2) >= 0xa (unsigned), and falls through when v1(=a4+2) < 0xa (unsigned).
  The `beq` branch at 0x1228 targets 0x12a8 and is always taken.
  The `beq` branch at 0x12d4 targets 0x10cc and is always taken.
  The `beq` branch at 0x12dc targets 0x1198 and is always taken.
  The `beq` branch at 0x12ec targets 0x1200 and is always taken.
  The `beq` branch at 0x12fc targets 0x1200 and is always taken.
  The `beq` branch at 0x159c targets 0x12a8 and is always taken.
  The return at 0x12cc has v0 = 0x0.
  The instructions from 0x1230 to 0x12a4 are not reached by any path from the entry, and their branches are not listed.
  The instructions from 0x1304 to 0x1590 are not reached by any path from the entry, and their branches are not listed.
  The indirect jump at 0x1220 uses a jump table whose successors are unresolved.

- `rad_start_device` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0x15a4 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0x15a4-0x164c (168 bytes).
  It occupies 168 bytes.
  The `lw` at 0x15ac loads 4 bytes from a1 (arg1 at entry) +0x1e0.
  4 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x208, including `lw` at 0x15e4, `lw` at 0x15f4, `lw` at 0x161c.
  4 such `lw` accesses load 4 bytes from [a1+520] +0x0, including `lw` at 0x15e8, `lw` at 0x1608, `lw` at 0x1620.
  3 such `sw` accesses store 4 bytes to [a1+520] +0x0, including `sw` at 0x15f0, `sw` at 0x1630, `sw` at 0x1648.
  The `lw` at 0x15f8 loads 4 bytes from a1 (arg1 at entry) +0x204.
  The `lw` at 0x15fc loads 4 bytes from a0 (arg0 at entry) +0x158.
  The `jal` at 0x1604 calls pciio_pio_write32 with a0=[[a1+520]], a1=([a0+344] + [a1+516]), a2=[a1+516], a3=a1 at entry (arg1), a5=a0 at entry (arg0), a7=one of -0x41, 0x7.
  The `beq` branch at 0x15c4 targets 0x161c, is taken when a4(=[a1+480]) == at(=-0x1), and falls through when a4(=[a1+480]) != at(=-0x1).
  The `beq` branch at 0x15cc targets 0x161c, is taken when a4(=[a1+480]) == t0(=-0x2), and falls through when a4(=[a1+480]) != t0(=-0x2).
  The `beq` branch at 0x15d4 targets 0x1634, is taken when a4(=[a1+480]) == a6(=0x6), and falls through when a4(=[a1+480]) != a6(=0x6).
  The `beq` branch at 0x15dc targets 0x1634, is taken when a4(=[a1+480]) == a7(=0x7), and falls through when a4(=[a1+480]) != a7(=0x7).
  The `beq` branch at 0x162c targets 0x15f4 and is always taken.
  The `beq` branch at 0x1644 targets 0x15f4 and is always taken.
  The return at 0x1614 has v0 = 0x1.

- `rad_create_ifs` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0x164c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0x164c-0x1b78 (1324 bytes).
  It occupies 1324 bytes.
  The `sw` at 0x1698 stores 4 bytes to sym(.data) +0x5040.
  The `sw` at 0x16a0 stores 4 bytes to sym(.data) +0x5038.
  2 such `lh` accesses load 2 bytes from a0 (arg0 at entry) +0x152, including `lh` at 0x16a4, `lh` at 0x1ad8.
  The `sw` at 0x16fc stores 4 bytes to a0 (arg0 at entry) +0x3ce0.
  The `sw` at 0x1708 stores 4 bytes to a0 (arg0 at entry) +0x3c6c.
  The `sw` at 0x1710 stores 4 bytes to a0 (arg0 at entry) +0x3be8.
  The `sw` at 0x1720 stores 4 bytes to a0 (arg0 at entry) +0x3be0.
  The `sw` at 0x1738 stores 4 bytes to a0 (arg0 at entry) +0x3bdc.
  The `sw` at 0x1744 stores 4 bytes to a0 (arg0 at entry) +0x3ce4.
  The `sd` at 0x174c stores 8 bytes to sym(.bss) +0x0.
  The `sd` at 0x175c stores 8 bytes to sym(.bss) +0x40.
  The `sd` at 0x1768 stores 8 bytes to sym(.bss) +0x10.
  The `sd` at 0x1774 stores 8 bytes to sym(.bss) +0x18.
  The `sw` at 0x1780 stores 4 bytes to sym(.bss) +0x20.
  The `sd` at 0x178c stores 8 bytes to sym(.bss) +0x28.
  The `sd` at 0x1798 stores 8 bytes to sym(.bss) +0x48.
  The `sd` at 0x17a0 stores 8 bytes to sym(.bss) +0x30.
  The `sw` at 0x17ac stores 4 bytes to sym(.bss) +0x38.
  The `sd` at 0x17bc stores 8 bytes to sym(.bss) +0x8.
  The `sw` at 0x17c8 stores 4 bytes to a0 (arg0 at entry) +0x3df0.
  2 such `lw` accesses load 4 bytes from sym(.data) +0x5038, including `lw` at 0x17cc, `lw` at 0x1914.
  The `sw` at 0x17d4 stores 4 bytes to a0 (arg0 at entry) +0x3cf8.
  The `sw` at 0x17e0 stores 4 bytes to a0 (arg0 at entry) +0x3d7c.
  The `sw` at 0x17f0 stores 4 bytes to a0 (arg0 at entry) +0x3cf0.
  The `sw` at 0x17f8 stores 4 bytes to a0 (arg0 at entry) +0x3cec.
  The `sw` at 0x17fc stores 4 bytes to a0 (arg0 at entry) +0x3df4.
  The `sd` at 0x1800 stores 8 bytes to sym(.bss) +0x98.
  The `sd` at 0x1804 stores 8 bytes to sym(.bss) +0x58.
  The `sd` at 0x1808 stores 8 bytes to sym(.bss) +0x50.
  The `sw` at 0x1810 stores 4 bytes to sym(.bss) +0x70.
  The `sd` at 0x1814 stores 8 bytes to sym(.bss) +0x68.
  The `sd` at 0x1818 stores 8 bytes to sym(.bss) +0x60.
  The `sd` at 0x1820 stores 8 bytes to sym(.bss) +0x90.
  The `sw` at 0x1858 stores 4 bytes to a0 (arg0 at entry) +0x3f00.
  The `sw` at 0x1864 stores 4 bytes to a0 (arg0 at entry) +0x3e8c.
  The `sw` at 0x1870 stores 4 bytes to a0 (arg0 at entry) +0x3e08.
  The `sw` at 0x187c stores 4 bytes to a0 (arg0 at entry) +0x3e00.
  The `sw` at 0x1884 stores 4 bytes to a0 (arg0 at entry) +0x3dfc.
  The `sw` at 0x188c stores 4 bytes to a0 (arg0 at entry) +0x3f04.
  The `sd` at 0x1898 stores 8 bytes to sym(.bss) +0x138.
  The `sd` at 0x18a0 stores 8 bytes to sym(.bss) +0xf8.
  The `sd` at 0x18a4 stores 8 bytes to sym(.bss) +0xf0.
  The `sd` at 0x18ac stores 8 bytes to sym(.bss) +0x118.
  The `sd` at 0x18b4 stores 8 bytes to sym(.bss) +0x120.
  The `sw` at 0x18bc stores 4 bytes to sym(.bss) +0x128.
  The `sw` at 0x18c4 stores 4 bytes to sym(.bss) +0x110.
  The `sd` at 0x18c8 stores 8 bytes to sym(.bss) +0x108.
  The `sd` at 0x18cc stores 8 bytes to sym(.bss) +0x100.
  The `sd` at 0x18d4 stores 8 bytes to sym(.bss) +0x130.
  The `sw` at 0x1910 stores 4 bytes to a0 (arg0 at entry) +0x4010.
  The `sw` at 0x191c stores 4 bytes to a0 (arg0 at entry) +0x3f9c.
  The `sw` at 0x1928 stores 4 bytes to a0 (arg0 at entry) +0x3f18.
  The `sw` at 0x1934 stores 4 bytes to a0 (arg0 at entry) +0x3f10.
  The `sw` at 0x193c stores 4 bytes to a0 (arg0 at entry) +0x3f0c.
  The `sw` at 0x1944 stores 4 bytes to a0 (arg0 at entry) +0x4014.
  The `sd` at 0x1950 stores 8 bytes to sym(.bss) +0xe8.
  The `sd` at 0x1958 stores 8 bytes to sym(.bss) +0xa8.
  The `sd` at 0x195c stores 8 bytes to sym(.bss) +0xa0.
  The `sd` at 0x1960 stores 8 bytes to sym(.bss) +0xd0.
  The `sw` at 0x1968 stores 4 bytes to sym(.bss) +0xc0.
  The `sd` at 0x196c stores 8 bytes to sym(.bss) +0xb8.
  The `sd` at 0x1970 stores 8 bytes to sym(.bss) +0xb0.
  The `sd` at 0x1978 stores 8 bytes to sym(.bss) +0xe0.
  The `sw` at 0x19b8 stores 4 bytes to a0 (arg0 at entry) +0x4120.
  The `sw` at 0x19c4 stores 4 bytes to a0 (arg0 at entry) +0x4028.
  The `sw` at 0x19c8 stores 4 bytes to a0 (arg0 at entry) +0x40ac.
  The `sw` at 0x19d4 stores 4 bytes to a0 (arg0 at entry) +0x4124.
  The `sw` at 0x19e0 stores 4 bytes to a0 (arg0 at entry) +0x401c.
  The `sw` at 0x1a10 stores 4 bytes to a0 (arg0 at entry) +0x4230.
  The `sw` at 0x1a18 stores 4 bytes to a0 (arg0 at entry) +0x412c.
  The `sw` at 0x1a20 stores 4 bytes to a0 (arg0 at entry) +0x4138.
  The `sw` at 0x1a24 stores 4 bytes to a0 (arg0 at entry) +0x41bc.
  The `sw` at 0x1a30 stores 4 bytes to a0 (arg0 at entry) +0x4234.
  The `sw` at 0x1a64 stores 4 bytes to a0 (arg0 at entry) +0x4340.
  The `sw` at 0x1a6c stores 4 bytes to a0 (arg0 at entry) +0x423c.
  The `sw` at 0x1a74 stores 4 bytes to a0 (arg0 at entry) +0x4248.
  The `sw` at 0x1a78 stores 4 bytes to a0 (arg0 at entry) +0x42cc.
  The `sw` at 0x1a84 stores 4 bytes to a0 (arg0 at entry) +0x4344.
  The `sw` at 0x1ab4 stores 4 bytes to a0 (arg0 at entry) +0x4450.
  The `sw` at 0x1abc stores 4 bytes to a0 (arg0 at entry) +0x434c.
  The `sw` at 0x1ac4 stores 4 bytes to a0 (arg0 at entry) +0x4358.
  The `sw` at 0x1ac8 stores 4 bytes to a0 (arg0 at entry) +0x43dc.
  The `sw` at 0x1ad4 stores 4 bytes to a0 (arg0 at entry) +0x4454.
  The `jal` at 0x16e4 calls kdsp_init_resource with a0=a0+15320, a1=0x2000000e, a2=sym(.rodata)+664, a3=sym(.rodata)+672, a4=a0 at entry (arg0), a5=0x0, a6=0x110.
  The `jal` at 0x17b8 calls kdsp_init_resource with a0=a0+15592, a1=0x2000000e, a2=sym(.rodata)+680, a3=sym(.rodata), a4=a0 at entry (arg0), a5=0x0, a6=0x110, a7=0x1f80000000.
  The `jal` at 0x181c calls kdsp_add_subresource with a0=a0+2832, a1=a0+15592, a2=sym(rad_get_analog_out_if_params), a3=sym(rad_set_analog_out_if_params), a4=[sym(.data)+20536].
  The `jal` at 0x1844 calls kdsp_init_resource with a0=a0+15864, a1=0x2000000d, a2=sym(.rodata), a3=0x0, a4=a0 at entry (arg0), a5=0x0, a6=0x110.
  The `jal` at 0x18d0 calls kdsp_select_interface with a0=a0+2280, a1=a0+15864, a2=0x1, a3=0xff, a4=0x50d0d0d1, a5=0x32aee8263, a6=0x1480000000, a7=0xb00000000.
  The `jal` at 0x18fc calls kdsp_init_resource with a0=a0+16136, a1=0x20000011, a2=sym(.rodata)+688, a3=sym(.rodata), a4=a0 at entry (arg0), a5=0x0, a6=0x110.
  The `jal` at 0x1974 calls kdsp_add_subresource with a0=a0+2832, a1=a0+16136, a2=?, a3=0x3, a4=0x217354b8e7, a5=0x1480000000, a6=0xb00000000, a7=0xb.
  The `jal` at 0x19ac calls kdsp_init_resource with a0=a0+16408, a1=0x2000000f, a2=sym(.rodata)+384, a3=sym(.rodata), a4=a0 at entry (arg0), a5=0x0, a6=0x110.
  The `jal` at 0x19dc calls kdsp_select_interface with a0=a0+3384, a1=a0+16408, a2=?, a3=?.
  The `jal` at 0x1a04 calls kdsp_init_resource with a0=a0+16680, a1=0x2000000f, a2=sym(.rodata)+400, a3=sym(.rodata), a4=a0 at entry (arg0), a5=0x0, a6=0x110.
  The `jal` at 0x1a2c calls kdsp_select_interface with a0=a0+3936, a1=a0+16680, a2=?, a3=[sym(.sdata)+40], a4=sym(.data).
  The `jal` at 0x1a58 calls kdsp_init_resource with a0=a0+16952, a1=0x20000025, a2=sym(.rodata), a3=sym(.rodata), a4=a0 at entry (arg0), a5=0x0, a6=0x110.
  The `jal` at 0x1a80 calls kdsp_select_interface with a0=a0+4488, a1=a0+16952, a2=[sym(.sdata)+40], a3=sym(.data).
  The `jal` at 0x1aa8 calls kdsp_init_resource with a0=a0+17224, a1=0x20000025, a2=sym(.rodata), a3=sym(.rodata), a4=a0 at entry (arg0), a5=0x0, a6=0x110.
  The `jal` at 0x1ad0 calls kdsp_select_interface with a0=a0+5040, a1=a0+17224, a2=[sym(.sdata)+40], a3=sym(.data).
  The `jal` at 0x1aec calls kdsp_map_resource with a0=a0+15864, a1=0x0, a2=?, a3=?, a4=[a0+338]:2, a5=0xd.
  The `jal` at 0x1af8 calls kdsp_map_resource with a0=a0+15320, a1=0x0, a2=?, a3=?.
  The `jal` at 0x1b04 calls kdsp_map_resource with a0=a0+15592, a1=0x0, a2=?, a3=?.
  The `jal` at 0x1b10 calls kdsp_map_resource with a0=a0+16136, a1=0x0, a2=?, a3=?.
  The `jal` at 0x1b34 calls kdsp_map_resource with a0=a0+16408, a1=0x0, a2=?, a3=?.
  The `jal` at 0x1b40 calls kdsp_map_resource with a0=a0+16680, a1=0x0, a2=?, a3=?.
  The `jal` at 0x1b50 calls kdsp_map_resource with a0=a0+16952, a1=0x0, a2=?, a3=?.
  The `jal` at 0x1b5c calls kdsp_map_resource with a0=a0+17224, a1=0x0, a2=?, a3=?.
  The `beq` branch at 0x16b8 targets 0x197c, is taken when at(=[a0+338]:2) == v0(=0xd), and falls through when at(=[a0+338]:2) != v0(=0xd).
  The `beq` branch at 0x1ae0 targets 0x1b18, is taken when a4(=[a0+338]:2) == a5(=0xd), and falls through when a4(=[a0+338]:2) != a5(=0xd).
  The return at 0x1b70 has v0 = 0x1.

- `rad_create_subcode_device` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0x1b78 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0x1b78-0x1cd4 (348 bytes).
  It occupies 348 bytes.
  The `sw` at 0x1bf0 stores 4 bytes to a1 (arg1 at entry) +0x194.
  The `sw` at 0x1bf8 stores 4 bytes to a1 (arg1 at entry) +0x34.
  The `sw` at 0x1c04 stores 4 bytes to a1 (arg1 at entry) +0x30.
  The `lw` at 0x1cac loads 4 bytes from a3 (arg3 at entry) +0x38.
  The `sw` at 0x1cc0 stores 4 bytes to a3 (arg3 at entry) +0x38.
  The `jal` at 0x1be0 calls rad_create_device with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a4 at entry (arg4), a3=?, a4=a5 at entry (arg5), a5=a7 at entry (arg7).
  The `jal` at 0x1c10 calls kdsp_select_clockgen with a0=a1 at entry (arg1), a1=?, a2=?, a3=?.
  The `jal` at 0x1c1c calls kdsp_select_interface with a0=a1 at entry (arg1), a1=?, a2=?, a3=?.
  The `jal` at 0x1c28 calls rad_start_device with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0x1c64 calls kdsp_create_subcode with a0=a3 at entry (arg3), a1=a2 at entry (arg2), a2=a1 at entry (arg1), a3=a6 at entry (arg6).
  The `jal` at 0x1c8c calls kdsp_set_default_subcode with a0=a3 at entry (arg3), a1=sp-144, a2=0x0, a3=?.
  The `beq` branch at 0x1bb8 targets 0x1bc4, is taken when a6 == 0, and falls through when a6 != 0.
  The `beq` branch at 0x1be8 targets 0x1ccc, is taken when v0(=ret(rad_create_device)) == 0, and falls through when v0(=ret(rad_create_device)) != 0.
  The `bne` branch at 0x1c00 targets 0x1c58, is taken when s1(=a3) != 0, and falls through when s1(=a3) == 0.
  The `beq` branch at 0x1c30 targets 0x1cc4, is taken when v0(=ret(rad_start_device)) == 0, and falls through when v0(=ret(rad_start_device)) != 0.
  The `beq` branch at 0x1c70 targets 0x1c98, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x1ca4 targets 0x1c08, is taken when v1(?) == 0, and falls through when v1(?) != 0.
  The `beq` branch at 0x1cbc targets 0x1c08 and is always taken.
  The `beq` branch at 0x1cc4 targets 0x1c38 and is always taken.
  The `beq` branch at 0x1ccc targets 0x1c38 and is always taken.
  The return at 0x1c50 has v0 = one of 0x0, 0x1.

- `rad_create_subcodes` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0x1cd4 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0x1cd4-0x226c (1432 bytes).
  It occupies 1432 bytes.
  2 such `lh` accesses load 2 bytes from a0 (arg0 at entry) +0x152, including `lh` at 0x1d14, `lh` at 0x21dc.
  The `sw` at 0x214c stores 4 bytes to a0 (arg0 at entry) +0x4e4c.
  The `sw` at 0x2150 stores 4 bytes to a0 (arg0 at entry) +0x4e48.
  The `sb` at 0x2154 stores 1 byte to a0 (arg0 at entry) +0x4f21.
  The `sb` at 0x2158 stores 1 byte to a0 (arg0 at entry) +0x4f20.
  The `sb` at 0x2160 stores 1 byte to a0 (arg0 at entry) +0x4f22.
  2 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x4f26, including `sb` at 0x2164, `sb` at 0x2180.
  2 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x4f24, including `sb` at 0x2168, `sb` at 0x217c.
  The `sb` at 0x2184 stores 1 byte to a0 (arg0 at entry) +0x4f25.
  The `lw` at 0x2188 loads 4 bytes from a0 (arg0 at entry) +0x158.
  The `lw` at 0x218c loads 4 bytes from a0 (arg0 at entry) +0x4e54.
  The `sb` at 0x2190 stores 1 byte to a0 (arg0 at entry) +0x4f27.
  The `sw` at 0x21a0 stores 4 bytes to a0 (arg0 at entry) +0x4e54.
  The `jal` at 0x1d88 calls rad_create_subcode_device with a0=a0 at entry (arg0), a1=a0+5592, a2=a0+3384, a3=0x0, a4=0x400, a5=0x6, a6=0x0, a7=sym(.rodata).
  The `jal` at 0x1de8 calls rad_create_subcode_device with a0=a0 at entry (arg0), a1=a0+6144, a2=a0+4488, a3=0x0, a4=0x400, a5=0x7, a6=0x0, a7=sym(.rodata).
  The `jal` at 0x1e3c calls rad_create_subcode_device with a0=a0 at entry (arg0), a1=a0+7248, a2=a0+3384, a3=a0+14680, a4=0x0, a5=0x6, a6=0x1000002f, a7=sym(.rodata).
  The `jal` at 0x1e90 calls rad_create_subcode_device with a0=a0 at entry (arg0), a1=a0+6696, a2=a0+3384, a3=a0+14616, a4=0x0, a5=0x6, a6=0x10000030, a7=sym(.rodata).
  The `jal` at 0x1ee4 calls rad_create_subcode_device with a0=a0 at entry (arg0), a1=a0+7800, a2=a0+3384, a3=a0+14744, a4=0x0, a5=0x6, a6=0x10000031, a7=sym(.rodata).
  The `jal` at 0x1f40 calls rad_create_subcode_device with a0=a0 at entry (arg0), a1=a0+8904, a2=a0+3936, a3=a0+14488, a4=0x1, a5=-0x1, a6=0x1000002f, a7=sym(.rodata).
  The `jal` at 0x1f98 calls rad_create_subcode_device with a0=a0 at entry (arg0), a1=a0+8352, a2=a0+3936, a3=a0+14424, a4=0x1, a5=-0x1, a6=0x10000030, a7=sym(.rodata).
  The `jal` at 0x1ff4 calls rad_create_subcode_device with a0=a0 at entry (arg0), a1=a0+9456, a2=a0+3936, a3=a0+14552, a4=0x1, a5=-0x1, a6=0x10000031, a7=sym(.rodata).
  The `jal` at 0x2040 calls sprintf with a0=sp-192, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x2050 calls sprintf with a0=sp-168, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x20a4 calls rad_create_subcode_device with a0=a0 at entry (arg0), a1=?, a2=?, a3=?, a4=0x0, a5=0x7, a7=sp-192.
  The `jal` at 0x20b8 calls sprintf with a0=sp-192, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x20c8 calls sprintf with a0=sp-168, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x211c calls rad_create_subcode_device with a0=a0 at entry (arg0), a1=?, a2=?, a3=?, a4=0x1, a5=-0x2, a7=sp-192.
  The `jal` at 0x216c calls rad_pio_writeback_subcode_tx with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x2174 calls rad_pio_writeback_subcode_tx with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x219c calls pciio_pio_write32 with a0=([a0+20052] | 0x40), a1=[a0+344]+112, a2=?, a3=?.
  The `beq` branch at 0x1d04 targets 0x21dc, is taken when v0(=[sym(kdsp_pro_audio_subcode)]) == a1(=0x1), and falls through when v0(=[sym(kdsp_pro_audio_subcode)]) != a1(=0x1).
  The `beq` branch at 0x1d0c targets 0x2200, is taken when v0(=[sym(kdsp_pro_audio_subcode)]) == 0, and falls through when v0(=[sym(kdsp_pro_audio_subcode)]) != 0.
  The `beq` branch at 0x1d1c targets 0x220c, is taken when v0(=[a0+338]:2) == at(=0x7), and falls through when v0(=[a0+338]:2) != at(=0x7).
  The `beq` branch at 0x1d28 targets 0x2220, is taken when v0(=[a0+338]:2) == v1(=0xd), and falls through when v0(=[a0+338]:2) != v1(=0xd).
  The `beq` branch at 0x1d90 targets 0x21a8, is taken when v0(=ret(rad_create_subcode_device)) == 0, and falls through when v0(=ret(rad_create_subcode_device)) != 0.
  The `beq` branch at 0x1df0 targets 0x21d4, is taken when v0(=ret(rad_create_subcode_device)) == 0, and falls through when v0(=ret(rad_create_subcode_device)) != 0.
  The `beq` branch at 0x1e44 targets 0x21f8, is taken when v0(=ret(rad_create_subcode_device)) == 0, and falls through when v0(=ret(rad_create_subcode_device)) != 0.
  The `beq` branch at 0x1e98 targets 0x2218, is taken when v0(=ret(rad_create_subcode_device)) == 0, and falls through when v0(=ret(rad_create_subcode_device)) != 0.
  The `beq` branch at 0x1eec targets 0x2230, is taken when v0(=ret(rad_create_subcode_device)) == 0, and falls through when v0(=ret(rad_create_subcode_device)) != 0.
  The `beq` branch at 0x1f48 targets 0x2238, is taken when v0(=ret(rad_create_subcode_device)) == 0, and falls through when v0(=ret(rad_create_subcode_device)) != 0.
  The `beq` branch at 0x1fa0 targets 0x2240, is taken when v0(=ret(rad_create_subcode_device)) == 0, and falls through when v0(=ret(rad_create_subcode_device)) != 0.
  The `beq` branch at 0x1ffc targets 0x2264, is taken when v0(=ret(rad_create_subcode_device)) == 0, and falls through when v0(=ret(rad_create_subcode_device)) != 0.
  The `beq` branch at 0x20ac targets 0x2248, is taken when v0(=ret(rad_create_subcode_device)) == 0, and falls through when v0(=ret(rad_create_subcode_device)) != 0.
  The `beq` branch at 0x2124 targets 0x225c, is taken when v0(=ret(rad_create_subcode_device)) == 0, and falls through when v0(=ret(rad_create_subcode_device)) != 0.
  The `bne` branch at 0x2144 targets 0x203c, is taken when s2(?) < 0x4 (signed), and falls through when s2(?) >= 0x4 (signed).
  The `beq` branch at 0x21d4 targets 0x21a8 and is always taken.
  The `beq` branch at 0x21e4 targets 0x2250, is taken when a2(=[a0+338]:2) == a3(=0xd), and falls through when a2(=[a0+338]:2) != a3(=0xd).
  The `beq` branch at 0x21f0 targets 0x1d38 and is always taken.
  The `beq` branch at 0x21f8 targets 0x21a8 and is always taken.
  The `beq` branch at 0x2204 targets 0x1d38 and is always taken.
  The `beq` branch at 0x2210 targets 0x1d38 and is always taken.
  The `beq` branch at 0x2218 targets 0x21a8 and is always taken.
  The `beq` branch at 0x2228 targets 0x1d38 and is always taken.
  The `beq` branch at 0x2230 targets 0x21a8 and is always taken.
  The `beq` branch at 0x2238 targets 0x21a8 and is always taken.
  The `beq` branch at 0x2240 targets 0x21a8 and is always taken.
  The `beq` branch at 0x2248 targets 0x21a8 and is always taken.
  The `beq` branch at 0x2254 targets 0x1d38 and is always taken.
  The `beq` branch at 0x225c targets 0x21a8 and is always taken.
  The `beq` branch at 0x2264 targets 0x21a8 and is always taken.
  The return at 0x21cc has v0 = one of 0x0, 0x1.

- `rad_create_mclks` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0x226c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0x226c-0x2554 (744 bytes).
  It occupies 744 bytes.
  The `sw` at 0x22c0 stores 4 bytes to a0 (arg0 at entry) +0x310.
  The `sw` at 0x22c8 stores 4 bytes to a0 (arg0 at entry) +0x318.
  The `sw` at 0x22cc stores 4 bytes to a0 (arg0 at entry) +0x314.
  The `sw` at 0x22d4 stores 4 bytes to a0 (arg0 at entry) +0x28c.
  The `sd` at 0x22f0 stores 8 bytes to a0 (arg0 at entry) +0x300.
  The `sw` at 0x2300 stores 4 bytes to a0 (arg0 at entry) +0x208.
  The `sw` at 0x2330 stores 4 bytes to a0 (arg0 at entry) +0x438.
  The `sw` at 0x2334 stores 4 bytes to a0 (arg0 at entry) +0x43c.
  The `sw` at 0x2338 stores 4 bytes to a0 (arg0 at entry) +0x440.
  The `sw` at 0x2340 stores 4 bytes to a0 (arg0 at entry) +0x330.
  The `sw` at 0x2348 stores 4 bytes to a0 (arg0 at entry) +0x3b4.
  The `sd` at 0x235c stores 8 bytes to a0 (arg0 at entry) +0x428.
  The `sw` at 0x2390 stores 4 bytes to a0 (arg0 at entry) +0x688.
  The `sw` at 0x2394 stores 4 bytes to a0 (arg0 at entry) +0x68c.
  The `sw` at 0x2398 stores 4 bytes to a0 (arg0 at entry) +0x690.
  The `sd` at 0x239c stores 8 bytes to a0 (arg0 at entry) +0x678.
  The `sw` at 0x23a4 stores 4 bytes to a0 (arg0 at entry) +0x580.
  The `sw` at 0x23ac stores 4 bytes to a0 (arg0 at entry) +0x604.
  The `sw` at 0x23c0 stores 4 bytes to a0 (arg0 at entry) +0x680.
  The `sd` at 0x23dc stores 8 bytes to a0 (arg0 at entry) +0x4f08.
  The `sh` at 0x23e8 stores 2 bytes to a0 (arg0 at entry) +0x4f10.
  The `sw` at 0x23f8 stores 4 bytes to a0 (arg0 at entry) +0x560.
  The `sw` at 0x23fc stores 4 bytes to a0 (arg0 at entry) +0x564.
  The `sw` at 0x2400 stores 4 bytes to a0 (arg0 at entry) +0x568.
  The `sd` at 0x2404 stores 8 bytes to a0 (arg0 at entry) +0x550.
  The `sw` at 0x240c stores 4 bytes to a0 (arg0 at entry) +0x458.
  The `sw` at 0x2414 stores 4 bytes to a0 (arg0 at entry) +0x4dc.
  The `sw` at 0x2428 stores 4 bytes to a0 (arg0 at entry) +0x558.
  The `sb` at 0x2440 stores 1 byte to a0 (arg0 at entry) +0x4f1a.
  The `sh` at 0x244c stores 2 bytes to a0 (arg0 at entry) +0x4f1c.
  The `sb` at 0x2458 stores 1 byte to a0 (arg0 at entry) +0x4f1b.
  The `sw` at 0x2464 stores 4 bytes to a0 (arg0 at entry) +0x7b0.
  The `sw` at 0x2468 stores 4 bytes to a0 (arg0 at entry) +0x7b8.
  The `sw` at 0x246c stores 4 bytes to a0 (arg0 at entry) +0x7b4.
  The `sw` at 0x2474 stores 4 bytes to a0 (arg0 at entry) +0x6a8.
  The `sw` at 0x2478 stores 4 bytes to a0 (arg0 at entry) +0x72c.
  The `sd` at 0x2494 stores 8 bytes to a0 (arg0 at entry) +0x7a0.
  The `sw` at 0x24a0 stores 4 bytes to a0 (arg0 at entry) +0x69c.
  The `sw` at 0x24ac stores 4 bytes to a0 (arg0 at entry) +0x6a0.
  The `sw` at 0x24e4 stores 4 bytes to a0 (arg0 at entry) +0x8d8.
  The `sw` at 0x24e8 stores 4 bytes to a0 (arg0 at entry) +0x8dc.
  The `sw` at 0x24ec stores 4 bytes to a0 (arg0 at entry) +0x8e0.
  The `sd` at 0x24f0 stores 8 bytes to a0 (arg0 at entry) +0x8c8.
  The `sw` at 0x24f8 stores 4 bytes to a0 (arg0 at entry) +0x7d0.
  The `sw` at 0x2500 stores 4 bytes to a0 (arg0 at entry) +0x854.
  The `sw` at 0x2514 stores 4 bytes to a0 (arg0 at entry) +0x7c4.
  The `sw` at 0x2520 stores 4 bytes to a0 (arg0 at entry) +0x7c8.
  The `sw` at 0x253c stores 4 bytes to a0 (arg0 at entry) +0x7bc.
  The `sw` at 0x2544 stores 4 bytes to a0 (arg0 at entry) +0x8e4.
  The `jal` at 0x22b8 calls kdsp_init_resource with a0=a0+504, a1=0x2000000a, a2=sym(.rodata), a3=sym(.rodata), a4=a0 at entry (arg0), a5=0x0, a6=0x128.
  The `jal` at 0x22fc calls kdsp_map_resource with a0=a0+504, a1=0x0, a2=sym(.data), a3=?.
  The `jal` at 0x2324 calls kdsp_init_resource with a0=a0+800, a1=0x2000000a, a2=sym(.rodata), a3=sym(.rodata), a4=a0 at entry (arg0), a5=0x0, a6=0x128.
  The `jal` at 0x2358 calls kdsp_map_resource with a0=a0+800, a1=0x0, a2=?, a3=?.
  The `jal` at 0x2384 calls kdsp_init_resource with a0=a0+1392, a1=0x2000000b, a2=sym(.rodata)+1264, a3=sym(.rodata), a4=a0 at entry (arg0), a5=0x0, a6=0x128.
  The `jal` at 0x23bc calls kdsp_map_resource with a0=a0+1392, a1=0x0, a2=?, a3=sym(rad_update_aes_mclk), a4=sym(.data), a5=0x3.
  The `jal` at 0x23ec calls kdsp_init_resource with a0=a0+1096, a1=0x2000000c, a2=sym(.rodata), a3=sym(.rodata), a4=a0 at entry (arg0), a5=0x0, a6=0x128.
  The `jal` at 0x2424 calls kdsp_map_resource with a0=a0+1096, a1=0x0, a2=sym(rad_update_adat_mclk), a3=sym(.data), a4=0x2.
  The `jal` at 0x245c calls kdsp_init_resource with a0=a0+1688, a1=0x20000016, a2=sym(.rodata), a3=sym(.rodata), a4=a0 at entry (arg0), a5=0x0, a6=0x128, a7=0x1.
  The `jal` at 0x24a8 calls kdsp_map_resource with a0=a0+1688, a1=0x0, a2=sym(rad_get_mclk_params), a3=sym(rad_set_mclk_params), a4=sym(.data), a5=0xac4400000000.
  The `jal` at 0x24d4 calls kdsp_init_resource with a0=a0+1984, a1=0x20000016, a2=sym(.rodata), a3=sym(.rodata), a4=a0 at entry (arg0), a5=0x0, a6=0x128.
  The `jal` at 0x251c calls kdsp_map_resource with a0=a0+1984, a1=0x0, a2=sym(rad_get_mclk_params), a3=sym(rad_set_mclk_params), a4=sym(.data), a5=0x1.
  The return at 0x254c has v0 = 0x1.

- `rad_video_sync_paraminfo_vals` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0x2554 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0x2554-0x25b0 (92 bytes).
  It occupies 92 bytes.
  The `lw` at 0x2554 loads 4 bytes from a1 (arg1 at entry) +0x0.
  The `lw` at 0x2564 loads 4 bytes from a0 (arg0 at entry) +0x90.
  The `sw` at 0x2598 stores 4 bytes to (a2 + (a3 << 0x3)) +0x0.
  The `sw` at 0x259c stores 4 bytes to a1 (arg1 at entry) +0x34.
  The `bne` branch at 0x2560 targets 0x25a8, is taken when at(=[a1]) != v0(=0x1000002a), and falls through when at(=[a1]) == v0(=0x1000002a).
  The `beq` branch at 0x2578 targets 0x2594, is taken when a0 == v1(=[a0+144]+1688), and falls through when a0 != v1(=[a0+144]+1688).
  The `beq` branch at 0x2580 targets 0x2598, is taken when a0 == a6(=[a0+144]+1984), and falls through when a0 != a6(=[a0+144]+1984).
  The return at 0x258c has v0 = a3.
  The return at 0x25a0 has v0 = a3+1.
  The return at 0x25a8 has v0 = a3.

- `rad_create_clockgen` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0x25b0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0x25b0-0x2874 (708 bytes).
  It occupies 708 bytes.
  The `lw` at 0x25e0 loads 4 bytes from a1 (arg1 at entry) +0x1d0.
  The `sw` at 0x262c stores 4 bytes to a0 (arg0 at entry) +0x13c.
  The `sw` at 0x2630 stores 4 bytes to a0 (arg0 at entry) +0x130.
  The `sw` at 0x2634 stores 4 bytes to a0 (arg0 at entry) +0x138.
  The `sw` at 0x2638 stores 4 bytes to a0 (arg0 at entry) +0x134.
  The `sw` at 0x2640 stores 4 bytes to a0 (arg0 at entry) +0x12c.
  The `sw` at 0x2644 stores 4 bytes to a0 (arg0 at entry) +0x124.
  The `sw` at 0x2648 stores 4 bytes to a0 (arg0 at entry) +0x128.
  The `sw` at 0x264c stores 4 bytes to a0 (arg0 at entry) +0x120.
  The `sw` at 0x2654 stores 4 bytes to a0 (arg0 at entry) +0x94.
  The `sd` at 0x2660 stores 8 bytes to a0 (arg0 at entry) +0x118.
  The `sd` at 0x2668 stores 8 bytes to a0 (arg0 at entry) +0x110.
  The `sw` at 0x2674 stores 4 bytes to a0 (arg0 at entry) +0xc.
  The `sw` at 0x2680 stores 4 bytes to a0 (arg0 at entry) +0x10.
  The `sw` at 0x268c stores 4 bytes to a0 (arg0 at entry) +0x8.
  The `sw` at 0x2694 stores 4 bytes to a0 (arg0 at entry) +0x4.
  The `lw` at 0x2698 loads 4 bytes from a1 (arg1 at entry) +0x1a4.
  The `sw` at 0x26a8 stores 4 bytes to a0 (arg0 at entry) +0x144.
  The `sw` at 0x26b0 stores 4 bytes to a0 (arg0 at entry) +0x154.
  The `sw` at 0x26b4 stores 4 bytes to a0 (arg0 at entry) +0x150.
  The `sw` at 0x26bc stores 4 bytes to a0 (arg0 at entry) +0x170.
  4 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x30, including `sw` at 0x26c4, `sw` at 0x2820, `sw` at 0x284c.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x38, including `sw` at 0x26cc, `sw` at 0x2814.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x3c, including `sw` at 0x26d4, `sw` at 0x2810.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x40, including `sw` at 0x26dc, `sw` at 0x280c.
  The `sw` at 0x26e8 stores 4 bytes to a0 (arg0 at entry) +0x44.
  4 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x34, including `sw` at 0x26f4, `sw` at 0x2818, `sw` at 0x2840.
  The `sw` at 0x2700 stores 4 bytes to a0 (arg0 at entry) +0x48.
  3 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x160, including `sw` at 0x2708, `sw` at 0x283c, `sw` at 0x2850.
  The `sw` at 0x2714 stores 4 bytes to a0 (arg0 at entry) +0x148.
  The `sw` at 0x2724 stores 4 bytes to a0 (arg0 at entry) +0x108.
  The `lw` at 0x275c loads 4 bytes from a0 (arg0 at entry) +0x15c.
  The `sw` at 0x2770 stores 4 bytes to ([a1+464] + ([a0+348] << 0x2)) +0x4edc.
  4 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x15c, including `sw` at 0x27ec, `sw` at 0x2804, `sw` at 0x2808.
  2 such `lh` accesses load 2 bytes from [a1+464] +0x152, including `lh` at 0x27f0, `lh` at 0x2824.
  The `jal` at 0x25e8 calls sprintf with a0=sp-112, a1=sym(.rodata)+1288, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x25fc calls sprintf with a0=sp-80, a1=sym(.rodata)+1272, a2=a2 at entry (arg2), a3=?.
  The `jal` at 0x2620 calls kdsp_init_resource with a0=a0 at entry (arg0), a1=0x20000004, a2=sp-112, a3=sp-80, a4=[a1+464], a5=0x0, a6=0x180.
  The `jal` at 0x277c calls kdsp_select_clockgen with a0=a1 at entry (arg1), a1=a0 at entry (arg0), a2=?, a3=0x180.
  The `jal` at 0x2790 calls kdsp_add_subresource with a0=a0 at entry (arg0), a1=a3 at entry (arg3), a2=?, a3=?.
  The `jal` at 0x27ac calls rad_set_clockgen with a0=a0 at entry (arg0), a1=a3 at entry (arg3), a2=0x4, a3=0x0, a4=0x1, a5=0x1.
  The `jal` at 0x27b8 calls rad_start_clockgen with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x27c4 calls kdsp_map_resource with a0=a0 at entry (arg0), a1=0x0, a2=?, a3=?.
  The `beq` branch at 0x26a0 targets 0x27e0, is taken when (a2(=[a1+420]) & 0x1) == 0, and falls through when (a2(=[a1+420]) & 0x1) != 0.
  The `beq` branch at 0x2720 targets 0x27e8, is taken when s1(=a2) == 0, and falls through when s1(=a2) != 0.
  The `beq` branch at 0x2728 targets 0x2808, is taken when s1(=a2) == a1(=0x1), and falls through when s1(=a2) != a1(=0x1).
  The `beq` branch at 0x2730 targets 0x27f0, is taken when s1(=a2) == a6(=0x2), and falls through when s1(=a2) != a6(=0x2).
  The `beq` branch at 0x2738 targets 0x2824, is taken when s1(=a2) == ra(=0x3), and falls through when s1(=a2) != ra(=0x3).
  The `beq` branch at 0x2740 targets 0x283c, is taken when s1(=a2) == t1(=0x4), and falls through when s1(=a2) != t1(=0x4).
  The `beq` branch at 0x2748 targets 0x2850, is taken when s1(=a2) == t2(=0x5), and falls through when s1(=a2) != t2(=0x5).
  The `beq` branch at 0x2750 targets 0x2774, is taken when a0(=one of 0x0, 0x1) == 0, and falls through when a0(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x27e0 targets 0x26a8 and is always taken.
  The `beq` branch at 0x27e8 targets 0x2750 and is always taken.
  The `beq` branch at 0x27f8 targets 0x2864, is taken when a6(=[[a1+464]+338]:2) == a7(=0xd), and falls through when a6(=[[a1+464]+338]:2) != a7(=0xd).
  The `beq` branch at 0x2800 targets 0x2750 and is always taken.
  The `beq` branch at 0x281c targets 0x2750 and is always taken.
  The `beq` branch at 0x282c targets 0x286c, is taken when t0(=[[a1+464]+338]:2) == t1(=0xd), and falls through when t0(=[[a1+464]+338]:2) != t1(=0xd).
  The `beq` branch at 0x2834 targets 0x2750 and is always taken.
  The `beq` branch at 0x2848 targets 0x2750 and is always taken.
  The `beq` branch at 0x285c targets 0x2750 and is always taken.
  The `beq` branch at 0x2864 targets 0x2800 and is always taken.
  The `beq` branch at 0x286c targets 0x2834 and is always taken.
  The return at 0x27d8 has v0 = 0x1.

- `rad_destroy_devices` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0x2874 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0x2874-0x2a80 (524 bytes).
  It occupies 524 bytes.
  The `lw` at 0x288c loads 4 bytes from a0 (arg0 at entry) +0xab8.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0xce0, including `lw` at 0x28a4, `lw` at 0x2a0c.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0xf08, including `lw` at 0x28b0, `lw` at 0x2a1c.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x1130, including `lw` at 0x28bc, `lw` at 0x2a2c.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x1358, including `lw` at 0x28c8, `lw` at 0x2a3c.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x1580, including `lw` at 0x28d4, `lw` at 0x2a4c.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x17a8, including `lw` at 0x28e0, `lw` at 0x2a5c.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x19d0, including `lw` at 0x28ec, `lw` at 0x2a6c.
  The `jal` at 0x2910 calls kdsp_destroy_subcode with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x2920 calls kdsp_destroy_subcode with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x2980 calls kdsp_destroy_subcode with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x2990 calls kdsp_destroy_subcode with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x2a00 calls kdsp_destroy_device with a0=a0+2280, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x2a10 calls kdsp_destroy_device with a0=a0+2832, a1=?, a2=?, a3=?.
  The `jal` at 0x2a20 calls kdsp_destroy_device with a0=a0+3384, a1=?, a2=?, a3=?.
  The `jal` at 0x2a30 calls kdsp_destroy_device with a0=a0+3936, a1=?, a2=?, a3=?.
  The `jal` at 0x2a40 calls kdsp_destroy_device with a0=a0+4488, a1=[a0+4952], a2=?, a3=?.
  The `jal` at 0x2a50 calls kdsp_destroy_device with a0=a0+5040, a1=?, a2=[a0+5504], a3=?.
  The `jal` at 0x2a60 calls kdsp_destroy_device with a0=a0+5592, a1=?, a2=?, a3=[a0+6056].
  The `jal` at 0x2a70 calls kdsp_destroy_device with a0=a0+6144, a1=?, a2=?, a3=?, a4=[a0+6608].
  The `bne` branch at 0x289c targets 0x2a00, is taken when at(=[a0+2744]) != 0, and falls through when at(=[a0+2744]) == 0.
  The `bne` branch at 0x28a8 targets 0x2a10, is taken when v0(=[a0+3296]) != 0, and falls through when v0(=[a0+3296]) == 0.
  The `bne` branch at 0x28b4 targets 0x2a20, is taken when v1(=[a0+3848]) != 0, and falls through when v1(=[a0+3848]) == 0.
  The `bne` branch at 0x28c0 targets 0x2a30, is taken when a0(=[a0+4400]) != 0, and falls through when a0(=[a0+4400]) == 0.
  The `bne` branch at 0x28cc targets 0x2a40, is taken when a1(=[a0+4952]) != 0, and falls through when a1(=[a0+4952]) == 0.
  The `bne` branch at 0x28d8 targets 0x2a50, is taken when a2(=[a0+5504]) != 0, and falls through when a2(=[a0+5504]) == 0.
  The `bne` branch at 0x28e4 targets 0x2a60, is taken when a3(=[a0+6056]) != 0, and falls through when a3(=[a0+6056]) == 0.
  The `bne` branch at 0x28f0 targets 0x2a70, is taken when a4(=[a0+6608]) != 0, and falls through when a4(=[a0+6608]) == 0.
  The `beq` branch at 0x2908 targets 0x2940 and is always taken.
  The `beq` branch at 0x2918 targets 0x2928, is taken when s5(=-0x3918) == s1(?), and falls through when s5(=-0x3918) != s1(?).
  The `beq` branch at 0x2938 targets 0x2968, is taken when s4(?) >= 0x3 (signed), and falls through when s4(?) < 0x3 (signed).
  The `bne` branch at 0x2940 targets 0x2910, is taken when s6(=-0x3858) != s1(?), and falls through when s6(=-0x3858) == s1(?).
  The `bne` branch at 0x2948 targets 0x2920, is taken when s5(=-0x3918) != s1(?), and falls through when s5(=-0x3918) == s1(?).
  The `bne` branch at 0x2960 targets 0x2940, is taken when s4(?) < 0x3 (signed), and falls through when s4(?) >= 0x3 (signed).
  The `beq` branch at 0x2978 targets 0x29b0 and is always taken.
  The `beq` branch at 0x2988 targets 0x2998, is taken when s4(=-0x3ad8) == s0(?), and falls through when s4(=-0x3ad8) != s0(?).
  The `beq` branch at 0x29a8 targets 0x29d8, is taken when s3(?) >= 0x4 (signed), and falls through when s3(?) < 0x4 (signed).
  The `bne` branch at 0x29b0 targets 0x2980, is taken when s5(=-0x39d8) != s0(?), and falls through when s5(=-0x39d8) == s0(?).
  The `bne` branch at 0x29b8 targets 0x2990, is taken when s4(=-0x3ad8) != s0(?), and falls through when s4(=-0x3ad8) == s0(?).
  The `bne` branch at 0x29d0 targets 0x29b0, is taken when s3(?) < 0x4 (signed), and falls through when s3(?) >= 0x4 (signed).
  The `beq` branch at 0x2a08 targets 0x28a8 and is always taken.
  The `beq` branch at 0x2a18 targets 0x28b4 and is always taken.
  The `beq` branch at 0x2a28 targets 0x28c0 and is always taken.
  The `beq` branch at 0x2a38 targets 0x28cc and is always taken.
  The `beq` branch at 0x2a48 targets 0x28d8 and is always taken.
  The `beq` branch at 0x2a58 targets 0x28e4 and is always taken.
  The `beq` branch at 0x2a68 targets 0x28f0 and is always taken.
  The `beq` branch at 0x2a78 targets 0x28f8 and is always taken.
  The return at 0x29f8 has v0 = one of ret(kdsp_destroy_subcode), ?.

- `rad_init_subsys` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0x2a80 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0x2a80-0x2af0 (112 bytes).
  It occupies 112 bytes.
  The `sw` at 0x2aa4 stores 4 bytes to a0 (arg0 at entry) +0x168.
  The `sb` at 0x2ab8 stores 1 byte to a0 (arg0 at entry) +0x4f13.
  The `lh` at 0x2abc loads 2 bytes from a0 (arg0 at entry) +0x152.
  The `sw` at 0x2ac0 stores 4 bytes to a0 (arg0 at entry) +0x4ed8.
  The `sw` at 0x2ac8 stores 4 bytes to a0 (arg0 at entry) +0x15c.
  The `sw` at 0x2ad4 stores 4 bytes to a0 (arg0 at entry) +0x160.
  The `sb` at 0x2aec stores 1 byte to a0 (arg0 at entry) +0x4f14.
  The `jal` at 0x2a98 calls kvpalloc with a0=0x1, a1=0x111, a2=0x0, a3=a3 at entry (arg3).
  The `jal` at 0x2aa8 calls bzero with a0=ret(kvpalloc), a1=0x1000, a2=?, a3=?.
  The `beq` branch at 0x2ad0 targets 0x2ae8, is taken when v0(=[a0+338]:2) == v1(=0x7), and falls through when v0(=[a0+338]:2) != v1(=0x7).
  The `beq` branch at 0x2ae8 targets 0x2ad8 and is always taken.
  The return at 0x2ae0 has v0 = 0x1.

- `rad_update_subsys` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0x2af0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0x2af0-0x2f94 (1188 bytes).
  It occupies 1188 bytes.
  The `lw` at 0x2afc loads 4 bytes from a0 (arg0 at entry) +0x15c.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x164, including `lw` at 0x2b14, `lw` at 0x2bd4, `lw` at 0x2eb0.
  4 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x1ec, including `lw` at 0x2b20, `lw` at 0x2e8c, `lw` at 0x2f2c.
  7 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x168, including `lw` at 0x2b4c, `lw` at 0x2b74, `lw` at 0x2ba4.
  5 such `lw` accesses load 4 bytes from ?, including `lw` at 0x2b54, `lw` at 0x2b68, `lw` at 0x2b7c.
  2 such `sw` accesses store 4 bytes to ?, including `sw` at 0x2b70, `sw` at 0x2e74.
  The `ll` at 0x2b8c loads 4 bytes from a0 (arg0 at entry) +0x1f4.
  The `sc` at 0x2b98 stores 4 bytes to a0 (arg0 at entry) +0x1f4.
  The `ll` at 0x2bbc loads 4 bytes from a0 (arg0 at entry) +0x1f0.
  The `sc` at 0x2bc8 stores 4 bytes to a0 (arg0 at entry) +0x1f0.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x4f00, including `lw` at 0x2bf8, `lw` at 0x2d30.
  The `sw` at 0x2c08 stores 4 bytes to a0 (arg0 at entry) +0x4f00.
  The `sb` at 0x2c20 stores 1 byte to a0 (arg0 at entry) +0x4f1e.
  The `sb` at 0x2c24 stores 1 byte to a0 (arg0 at entry) +0x4f1f.
  2 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x4f21, including `lbu` at 0x2c28, `lbu` at 0x2cd0.
  3 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x4f23, including `sb` at 0x2c2c, `sb` at 0x2d00, `sb` at 0x2d08.
  2 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x4f20, including `lbu` at 0x2c30, `lbu` at 0x2c98.
  The `lw` at 0x2c34 loads 4 bytes from a0 (arg0 at entry) +0x1cc.
  The `lw` at 0x2c38 loads 4 bytes from a0 (arg0 at entry) +0x4e4c.
  The `lw` at 0x2c3c loads 4 bytes from a0 (arg0 at entry) +0x1d4.
  The `lw` at 0x2c48 loads 4 bytes from a0 (arg0 at entry) +0x4e48.
  3 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x4f22, including `sb` at 0x2c50, `sb` at 0x2e48, `sb` at 0x2e54.
  The `sw` at 0x2c58 stores 4 bytes to a0 (arg0 at entry) +0x4e4c.
  The `sw` at 0x2c6c stores 4 bytes to a0 (arg0 at entry) +0x4e48.
  The `lbu` at 0x2c78 loads 1 byte from a0 (arg0 at entry) +0x4f24.
  The `sb` at 0x2c94 stores 1 byte to a0 (arg0 at entry) +0x4f24.
  The `lbu` at 0x2cb0 loads 1 byte from a0 (arg0 at entry) +0x4f26.
  The `sb` at 0x2ccc stores 1 byte to a0 (arg0 at entry) +0x4f26.
  The `lbu` at 0x2ce4 loads 1 byte from a0 (arg0 at entry) +0x4f27.
  2 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x4f21, including `sb` at 0x2cf4, `sb` at 0x2d04.
  The `lbu` at 0x2d3c loads 1 byte from a0 (arg0 at entry) +0x4f13.
  The `ld` at 0x2d58 loads 8 bytes from a0 (arg0 at entry) +0x4ef0.
  The `lw` at 0x2d68 loads 4 bytes from a0 (arg0 at entry) +0x1f4.
  The `lw` at 0x2d6c loads 4 bytes from a0 (arg0 at entry) +0x1f0.
  The `ld` at 0x2d78 loads 8 bytes from a0 (arg0 at entry) +0x4ef8.
  2 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x4ef8, including `sd` at 0x2d8c, `sd` at 0x2f10.
  The `lh` at 0x2dac loads 2 bytes from a0 (arg0 at entry) +0x152.
  The `sw` at 0x2db0 stores 4 bytes to a0 (arg0 at entry) +0x1f4.
  The `sw` at 0x2db8 stores 4 bytes to a0 (arg0 at entry) +0x1f0.
  The `sd` at 0x2dc8 stores 8 bytes to a0 (arg0 at entry) +0x4ef0.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x1e0, including `lw` at 0x2dd8, `lw` at 0x2dfc, `lw` at 0x2ec0.
  2 such `sb` accesses store 1 byte to ?, including `sb` at 0x2df0, `sb` at 0x2e1c.
  The `lbu` at 0x2e30 loads 1 byte from a0 (arg0 at entry) +0x4f25.
  2 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x4f20, including `sb` at 0x2e3c, `sb` at 0x2e4c.
  2 such `lw` accesses load 4 bytes from ([a0+360] + ([a0+492] << 0x7)) +0x7c, including `lw` at 0x2ea4, `lw` at 0x2f3c.
  2 such `sw` accesses store 4 bytes to ([a0+360] + ([a0+492] << 0x7)) +0x7c, including `sw` at 0x2eac, `sw` at 0x2f44.
  The `sw` at 0x2eb4 stores 4 bytes to a0 (arg0 at entry) +0x1ec.
  2 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x4f14, including `lbu` at 0x2ec4, `lbu` at 0x2ed8.
  The `sb` at 0x2ed4 stores 1 byte to ([a0+20244]:1 + a0) +0x4f15.
  The `lw` at 0x2eec loads 4 bytes from a0 (arg0 at entry) +0x158.
  The `sw` at 0x2ef4 stores 4 bytes to a0 (arg0 at entry) +0x4e7c.
  2 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x4f14, including `sb` at 0x2f1c, `sb` at 0x2f28.
  The `jal` at 0x2c0c calls rad_check_adat_rx with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x2c18 calls rad_process_aesrx_subcode with a0=a0 at entry (arg0), a1=0x0, a2=?, a3=?.
  The `jal` at 0x2c70 calls kdsp_update_default_subcode with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x2ca8 calls kdsp_update_default_subcode with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x2cfc calls rad_pio_writeback_subcode_tx with a0=a0+12216, a1=[a0+20257]:1, a2=?, a3=0x1.
  The `jal` at 0x2d48 calls update_ust with a0=?, a1=?, a2=?, a3=?, a5=[a0+20243]:1.
  The `jal` at 0x2d50 calls get_ust_nano with a0=sp-64, a1=?, a2=?, a3=?.
  The `jal` at 0x2da0 calls rad_update_ksync with a0=a0 at entry (arg0), a1=?, a2=?, a3=([a0+496] + [a0+500]), a4=[a0+20216]:8, a6=[a0+20208]:8.
  The `jal` at 0x2e44 calls rad_pio_writeback_subcode_tx with a0=a0+8352, a1=[a0+20256]:1, a2=?, a3=?.
  The `jal` at 0x2e84 calls bcopy with a0=?, a1=a0+364, a2=0x80, a3=?, a6=[a0+360], a7=a0+500.
  The `jal` at 0x2ef8 calls pciio_pio_write32 with a0=?, a1=[a0+344]+140, a2=?, a3=?, a6=([a0+20244]:1 + a0).
  The `jal` at 0x2f5c calls bcopy with a0=([a0+360] + ([a0+492] << 0x7)), a1=a0+364, a2=0x80, a3=([a0+492] << 0x7), a4=(0xffffffff80000000 | [([a0+360] + ([a0+492] << 0x7))+124]), a5=([a0+360] + ([a0+492] << 0x7)), a6=[a0+360].
  The `jal` at 0x2f6c calls cmn_err with a0=0x1, a1=sym(.rodata)+1296, a2=?, a3=?.
  The `jal` at 0x2f74 calls rad_stop_status_dma with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x2f7c calls rad_start_status_dma with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `beq` branch at 0x2b0c targets 0x2d0c, is taken when at(=[a0+348]) == 0, and falls through when at(=[a0+348]) != 0.
  The `bne` branch at 0x2b1c targets 0x2d28, is taken when a0(=[a0+356]) < 0x2 (signed), and falls through when a0(=[a0+356]) >= 0x2 (signed).
  The `beq` branch at 0x2b60 targets 0x2e58, is taken when (s2(=0xffffffff80000000) & t8(?)) == 0, and falls through when (s2(=0xffffffff80000000) & t8(?)) != 0.
  The `beq` branch at 0x2b84 targets 0x2bac, is taken when (a6(?) & 0x100) == 0, and falls through when (a6(?) & 0x100) != 0.
  The `beql` branch at 0x2b9c targets 0x2b8c, is taken when a4(=[a0+500]+1) == 0, and falls through when a4(=[a0+500]+1) != 0; its branch-likely delay slot `nop` at 0x2ba0 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x2bb4 targets 0x2bd4, is taken when (a6(?) & 0x80) == 0, and falls through when (a6(?) & 0x80) != 0.
  The `beql` branch at 0x2bcc targets 0x2bbc, is taken when t2(=[a0+496]+1) == 0, and falls through when t2(=[a0+496]+1) != 0; its branch-likely delay slot `nop` at 0x2bd0 runs only when taken and is annulled on fall-through.
  The `bne` branch at 0x2be8 targets 0x2b4c, is taken when s1(?) < a4(=[a0+356]-1) (signed), and falls through when s1(?) >= a4(=[a0+356]-1) (signed).
  The `beq` branch at 0x2bf0 targets 0x2f2c, is taken when a4(=[a0+356]-1) == s1(?), and falls through when a4(=[a0+356]-1) != s1(?).
  The `beq` branch at 0x2c04 targets 0x2d3c, is taken when (a5(=[a0+20224]+1) & 0x3ff) == 0, and falls through when (a5(=[a0+20224]+1) & 0x3ff) != 0.
  The `bne` branch at 0x2c90 targets 0x2c70, is taken when s2(?) < 0x3 (signed), and falls through when s2(?) >= 0x3 (signed).
  The `beq` branch at 0x2c9c targets 0x2e28, is taken when a1(=[a0+20256]:1) == 0, and falls through when a1(=[a0+20256]:1) != 0.
  The `bne` branch at 0x2cc8 targets 0x2ca8, is taken when s2(?) < 0x4 (signed), and falls through when s2(?) >= 0x4 (signed).
  The `bne` branch at 0x2cd4 targets 0x2d10, is taken when a1(=[a0+20257]:1) != 0, and falls through when a1(=[a0+20257]:1) == 0.
  The `bne` branch at 0x2cdc targets 0x2cf4, is taken when a0(?) != 0, and falls through when a0(?) == 0.
  The `beq` branch at 0x2ce8 targets 0x2d10, is taken when a2(=[a0+20263]:1) == 0, and falls through when a2(=[a0+20263]:1) != 0.
  The `bnel` branch at 0x2d2c targets 0x2bfc, is taken when a0(=[a0+356]) != a4(=0x1), and falls through when a0(=[a0+356]) == a4(=0x1); its branch-likely delay slot `lw a5,20224(s0)` at 0x2d30 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x2d34 targets 0x2f8c and is always taken.
  The `beq` branch at 0x2d40 targets 0x2c0c, is taken when a5(=[a0+20243]:1) == 0, and falls through when a5(=[a0+20243]:1) != 0.
  The `beq` branch at 0x2d60 targets 0x2da8, is taken when a6(=[a0+20208]:8) == 0, and falls through when a6(=[a0+20208]:8) != 0.
  The `blez` branch at 0x2d74 targets 0x2f08, is taken when a3(=([a0+496] + [a0+500])) <= 0 (signed), and falls through when a3(=([a0+496] + [a0+500])) > 0 (signed).
  The `bgtz` branch at 0x2d90 targets 0x2da0, is taken when a0(?) > 0 (signed), and falls through when a0(?) <= 0 (signed).
  The `blez` branch at 0x2d98 targets 0x2dac, is taken when a4(=[a0+20216]:8) <= 0 (signed), and falls through when a4(=[a0+20216]:8) > 0 (signed).
  The `beq` branch at 0x2dc4 targets 0x2ec0, is taken when a0(=[a0+338]:2) == a6(=0x7), and falls through when a0(=[a0+338]:2) != a6(=0x7).
  The `bne` branch at 0x2dd0 targets 0x2c0c, is taken when a0(=[a0+338]:2) != a7(=0xd), and falls through when a0(=[a0+338]:2) == a7(=0xd).
  The `beq` branch at 0x2df4 targets 0x2c0c, is taken when a2(?) >= 0x4 (signed), and falls through when a2(?) < 0x4 (signed).
  The `bne` branch at 0x2e18 targets 0x2dd8, is taken when a2(?) < 0x4 (signed), and falls through when a2(?) >= 0x4 (signed).
  The `beq` branch at 0x2e20 targets 0x2c0c and is always taken.
  The `bne` branch at 0x2e28 targets 0x2e3c, is taken when a0(?) != 0, and falls through when a0(?) == 0.
  The `beq` branch at 0x2e34 targets 0x2ca0, is taken when t3(=[a0+20261]:1) == 0, and falls through when t3(=[a0+20261]:1) != 0.
  The `beq` branch at 0x2e50 targets 0x2ca0 and is always taken.
  The `beq` branch at 0x2e94 targets 0x2eb0, is taken when a0(?) == a5(=[a0+492]), and falls through when a0(?) != a5(=[a0+492]).
  The `beq` branch at 0x2eb8 targets 0x2bf0 and is always taken.
  The `beq` branch at 0x2edc targets 0x2f14, is taken when a3(=[a0+20244]:1) == 0, and falls through when a3(=[a0+20244]:1) != 0.
  The `beq` branch at 0x2ee4 targets 0x2f20, is taken when a0(=0x1) == a3(=[a0+20244]:1), and falls through when a0(=0x1) != a3(=[a0+20244]:1).
  The `beq` branch at 0x2f00 targets 0x2c0c and is always taken.
  The `beq` branch at 0x2f0c targets 0x2d90 and is always taken.
  The `beq` branch at 0x2f18 targets 0x2ee8 and is always taken.
  The `beq` branch at 0x2f24 targets 0x2ee8 and is always taken.
  The `beq` branch at 0x2f84 targets 0x2d10 and is always taken.
  The `beq` branch at 0x2f8c targets 0x2f30 and is always taken.
  The return at 0x2d20 has v0 = one of ret(kdsp_update_default_subcode), ?, ret(rad_start_status_dma).

- `rad_start_status_dma` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0x2f94 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0x2f94-0x314c (440 bytes).
  It occupies 440 bytes.
  The `lw` at 0x2f94 loads 4 bytes from a0 (arg0 at entry) +0x15c.
  3 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x164, including `sw` at 0x2fb8, `sw` at 0x2fe4, `sw` at 0x3130.
  5 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x168, including `lw` at 0x2ff0, `lw` at 0x3014, `lw` at 0x303c.
  2 such `sw` accesses store 4 bytes to ?, including `sw` at 0x2ff8, `sw` at 0x301c.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x164, including `lw` at 0x2ffc, `lw` at 0x3020, `lw` at 0x306c.
  7 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x158, including `lw` at 0x3070, `lw` at 0x3090, `lw` at 0x30a0.
  The `lw` at 0x30e0 loads 4 bytes from a0 (arg0 at entry) +0x160.
  The `sw` at 0x3110 stores 4 bytes to a0 (arg0 at entry) +0x1ec.
  The `sw` at 0x311c stores 4 bytes to a0 (arg0 at entry) +0x15c.
  The `jal` at 0x3038 calls rad_one_shot_status with a0=a0 at entry (arg0), a1=[a0+360], a2=?, a3=?.
  The `jal` at 0x3054 calls bcopy with a0=[a0+360], a1=a0+364, a2=0x80, a3=?.
  The `jal` at 0x3064 calls Mem_to_PCI_DMA with a0=a0 at entry (arg0), a1=[a0+360], a2=0x1000, a3=?.
  The `jal` at 0x3088 calls pciio_pio_write32 with a0=?, a1=[a0+344]+1284, a2=?, a3=?.
  The `jal` at 0x3098 calls pciio_pio_write32 with a0=ret(Mem_to_PCI_DMA), a1=[a0+344]+1280, a2=?, a3=?.
  The `jal` at 0x30a8 calls pciio_pio_write32 with a0=0x0, a1=[a0+344]+1320, a2=?, a3=?.
  The `jal` at 0x30b8 calls pciio_pio_write32 with a0=?, a1=[a0+344]+1212, a2=?, a3=?.
  The `jal` at 0x30c8 calls pciio_pio_write32 with a0=ret(Mem_to_PCI_DMA), a1=[a0+344]+1204, a2=?, a3=?.
  The `jal` at 0x30d8 calls pciio_pio_write32 with a0=0x0, a1=[a0+344]+1208, a2=?, a3=?.
  The `jal` at 0x3108 calls pciio_pio_write32 with a0=table(0x40003), a1=[a0+344]+92, a2=0x40003, a3=?.
  The `jal` at 0x313c calls us_delay with a0=0x12c, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=0x1, a4=0x20.
  The `bne` branch at 0x2fac targets 0x313c, is taken when at(=[a0+348]) != 0, and falls through when at(=[a0+348]) == 0.
  The `beq` branch at 0x2fc4 targets 0x2fdc, is taken when v0(?) >= 0x20 (signed), and falls through when v0(?) < 0x20 (signed).
  The `bne` branch at 0x2fd4 targets 0x2fbc, is taken when v0(?) < 0x20 (signed), and falls through when v0(?) >= 0x20 (signed).
  The `beq` branch at 0x2fe0 targets 0x3130, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `blez` branch at 0x2fe8 targets 0x3034, is taken when v0(?) <= 0 (signed), and falls through when v0(?) > 0 (signed).
  The `beq` branch at 0x300c targets 0x3034, is taken when a0(?) >= a2(=[a0+356]) (signed), and falls through when a0(?) < a2(=[a0+356]) (signed).
  The `bne` branch at 0x302c targets 0x2ff0, is taken when a0(?) < a4(=[a0+356]) (signed), and falls through when a0(?) >= a4(=[a0+356]) (signed).
  The `bne` branch at 0x3040 targets 0x3050, is taken when v0(=ret(rad_one_shot_status)) != 0, and falls through when v0(=ret(rad_one_shot_status)) == 0.
  The `beq` branch at 0x3048 targets 0x3120 and is always taken.
  The `beq` branch at 0x3134 targets 0x3120 and is always taken.
  The `beq` branch at 0x3144 targets 0x3120 and is always taken.
  The return at 0x3128 has v0 = one of 0x0, 0x1.

- `rad_stop_status_dma` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0x314c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0x314c-0x3194 (72 bytes).
  It occupies 72 bytes.
  The `lw` at 0x314c loads 4 bytes from a0 (arg0 at entry) +0x15c.
  The `lw` at 0x316c loads 4 bytes from a0 (arg0 at entry) +0x158.
  The `sw` at 0x3184 stores 4 bytes to a0 (arg0 at entry) +0x15c.
  The `jal` at 0x3174 calls pciio_pio_write32 with a0=0x1fffc, a1=[a0+344]+92, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0x3160 targets 0x3188, is taken when at(=[a0+348]) == 0, and falls through when at(=[a0+348]) != 0.
  The return at 0x318c has v0 = 0x1.

- `rad_sync_device_ust` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0x3194 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0x3194-0x32ec (344 bytes).
  It occupies 344 bytes.
  The `lw` at 0x31bc loads 4 bytes from a0 (arg0 at entry) +0x1d0.
  The `ld` at 0x3208 loads 8 bytes from [a0+464] +0x4eb8.
  6 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x120, including `sd` at 0x324c, `sd` at 0x325c, `sd` at 0x3288.
  The `lw` at 0x3260 loads 4 bytes from a0 (arg0 at entry) +0x224.
  The `sw` at 0x32b0 stores 4 bytes to a0 (arg0 at entry) +0x220.
  The `jal` at 0x31b8 calls update_ust with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x31c0 calls get_ust_nano with a0=sp-48, a1=?, a2=?, a3=?.
  The `beq` branch at 0x3248 targets 0x32c0, is taken when at(?) == 0, and falls through when at(?) != 0.
  The `beq` branch at 0x3250 targets 0x3260, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0x3264 targets 0x32a8, is taken when t0(=[a0+548]) == 0, and falls through when t0(=[a0+548]) != 0.
  The `bltz` branch at 0x328c targets 0x32dc, is taken when t1(?) < 0 (signed), and falls through when t1(?) >= 0 (signed).
  The `beq` branch at 0x3298 targets 0x32ac, is taken when s1(=a2) >= a2(?) (unsigned), and falls through when s1(=a2) < a2(?) (unsigned).
  The `beq` branch at 0x32c8 targets 0x3260, is taken when s2(=a1) >= a5(?) (unsigned), and falls through when s2(=a1) < a5(?) (unsigned).
  The `beq` branch at 0x32d4 targets 0x3260 and is always taken.
  The `beq` branch at 0x32dc targets 0x32ac, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `beq` branch at 0x32e4 targets 0x32a8 and is always taken.
  The return at 0x32b8 has v0 = ret(get_ust_nano).

- `rad_start_dma` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0x32ec (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0x32ec-0x3868 (1404 bytes).
  It occupies 1404 bytes.
  The `lw` at 0x32f4 loads 4 bytes from a0 (arg0 at entry) +0x1d0.
  7 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x1e0, including `lw` at 0x32fc, `lw` at 0x34f4, `lw` at 0x3528.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x1a4, including `lw` at 0x3324, `lw` at 0x337c.
  The `lw` at 0x3334 loads 4 bytes from a0 (arg0 at entry) +0x174.
  The `lbu` at 0x334c loads 1 byte from ([a0+464] + one of 0x1788, 0x19b0) +0x0.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x128, including `lw` at 0x3374, `lw` at 0x33b8, `lw` at 0x3428.
  The `sw` at 0x3378 stores 4 bytes to [a0+296] +0x0.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x15c, including `lw` at 0x3384, `lw` at 0x33a8.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x130, including `lw` at 0x3388, `lw` at 0x33ac, `lw` at 0x3448.
  The `lw` at 0x3394 loads 4 bytes from a0 (arg0 at entry) +0x144.
  The `lw` at 0x3398 loads 4 bytes from a0 (arg0 at entry) +0x178.
  The `lw` at 0x339c loads 4 bytes from [a0+324] +0x13c.
  2 such `sw` accesses store 4 bytes to [a0+296] +0x4, including `sw` at 0x33bc, `sw` at 0x3430.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0x33c8, `lw` at 0x33d0.
  5 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x224, including `sw` at 0x33cc, `sw` at 0x3658, `sw` at 0x36d4.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x220, including `sw` at 0x33d4, `sw` at 0x37a8.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0x33d8, `ld` at 0x33e0.
  2 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x218, including `sd` at 0x33dc, `sd` at 0x3744.
  2 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x118, including `sd` at 0x33e4, `sd` at 0x3734.
  The `sb` at 0x33e8 stores 1 byte to a0 (arg0 at entry) +0x1b0.
  The `lw` at 0x33ec loads 4 bytes from [a0+464] +0x4ed8.
  The `sw` at 0x33f8 stores 4 bytes to [a0+464] +0x4ed8.
  The `lw` at 0x343c loads 4 bytes from a0 (arg0 at entry) +0x134.
  The `lw` at 0x3440 loads 4 bytes from a0 (arg0 at entry) +0x13c.
  The `lw` at 0x3454 loads 4 bytes from a0 (arg0 at entry) +0x1ec.
  14 such `lw` accesses load 4 bytes from [a0+464] +0x158, including `lw` at 0x3458, `lw` at 0x3470, `lw` at 0x348c.
  The `lw` at 0x346c loads 4 bytes from a0 (arg0 at entry) +0x1e8.
  The `lw` at 0x3480 loads 4 bytes from a0 (arg0 at entry) +0x1f0.
  The `lw` at 0x3484 loads 4 bytes from a0 (arg0 at entry) +0x20c.
  The `lw` at 0x3488 loads 4 bytes from a0 (arg0 at entry) +0x200.
  The `lw` at 0x34b0 loads 4 bytes from a0 (arg0 at entry) +0x1f8.
  The `lw` at 0x34c8 loads 4 bytes from a0 (arg0 at entry) +0x1f4.
  The `lw` at 0x34e0 loads 4 bytes from a0 (arg0 at entry) +0x1fc.
  2 such `lh` accesses load 2 bytes from table(sym(.data)) +0x8, including `lh` at 0x3510, `lh` at 0x35e8.
  2 such `lw` accesses load 4 bytes from table(sym(.data)) +0xc, including `lw` at 0x353c, `lw` at 0x3620.
  2 such `lh` accesses load 2 bytes from table(sym(.data)) +0xa, including `lh` at 0x3540, `lh` at 0x3618.
  2 such `lh` accesses load 2 bytes from table(sym(.data)) +0x0, including `lh` at 0x3544, `lh` at 0x3634.
  The `lh` at 0x357c loads 2 bytes from table(sym(.data)) +0x2.
  The `lw` at 0x3584 loads 4 bytes from table(sym(.data)) +0x4.
  4 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x208, including `lw` at 0x3668, `lw` at 0x3690, `lw` at 0x37e0.
  4 such `lw` accesses load 4 bytes from [a0+520] +0x0, including `lw` at 0x3670, `lw` at 0x369c, `lw` at 0x37e8.
  2 such `sw` accesses store 4 bytes to [a0+520] +0x0, including `sw` at 0x3684, `sw` at 0x37f0.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x204, including `lw` at 0x3688, `lw` at 0x37f8.
  The `ld` at 0x36f8 loads 8 bytes from a0 (arg0 at entry) +0x118.
  The `sw` at 0x3790 stores 4 bytes to a0 (arg0 at entry) +0x1e4.
  The `lw` at 0x37b8 loads 4 bytes from [a0+464] +0x1e4.
  2 such `sb` accesses store 1 byte to [a0+464] +0x55c, including `sb` at 0x37c8, `sb` at 0x3840.
  2 such `sb` accesses store 1 byte to [a0+464] +0x4f19, including `sb` at 0x37cc, `sb` at 0x383c.
  The `lw` at 0x3824 loads 4 bytes from [a0+464] +0x4e50.
  The `sw` at 0x3838 stores 4 bytes to [a0+464] +0x4e50.
  The `lw` at 0x3854 loads 4 bytes from [a0+464] +0x4f2c.
  The `jal` at 0x3358 calls rad_start_dma with a0=([a0+464] + one of 0x15d8, 0x1800), a1=0x7, a2=?, a3=[a0+480].
  The `jal` at 0x33a0 calls bzero with a0=[a0+304], a1=([a0+348] << 0x2), a2=?, a3=[a0+296].
  The `jal` at 0x33b0 calls dki_dcache_wb with a0=[a0+304], a1=([a0+348] << 0x2), a2=?, a3=?.
  The `jal` at 0x3420 calls bzero with a0=[a0+304], a1=([a0+348] << 0x2), a2=?, a3=[a0+296].
  The `jal` at 0x344c calls Mem_to_PCI_DMA with a0=[a0+464], a1=[a0+304], a2=?, a3=[a0+308].
  The `jal` at 0x3464 calls pciio_pio_write32 with a0=ret(Mem_to_PCI_DMA), a1=([[a0+464]+344] + [a0+492]), a2=[a0+492], a3=?.
  The `jal` at 0x3478 calls pciio_pio_write32 with a0=0x0, a1=([[a0+464]+344] + [a0+488]), a2=[a0+488], a3=?.
  The `jal` at 0x34a8 calls pciio_pio_write32 with a0=?, a1=([[a0+464]+344] + [a0+496]), a2=?, a3=[a0+496].
  The `jal` at 0x34c0 calls pciio_pio_write32 with a0=ret(Mem_to_PCI_DMA), a1=([[a0+464]+344] + [a0+504]), a2=[a0+504], a3=?.
  The `jal` at 0x34d8 calls pciio_pio_write32 with a0=0x0, a1=([[a0+464]+344] + [a0+500]), a2=[a0+500], a3=?.
  The `jal` at 0x34ec calls pciio_pio_write32 with a0=?, a1=([[a0+464]+344] + [a0+508]), a2=[a0+508], a3=?.
  The `jal` at 0x3520 calls pciio_pio_read32 with a0=([[a0+464]+344] + ([table(sym(.data))+8]:2 << 0x2))-64, a1=([table(sym(.data))+8]:2 << 0x2), a2=[a0+480], a3=?.
  The `jal` at 0x3560 calls pciio_pio_read32 with a0=([[a0+464]+344] + (entry(sym(.data)) << 0x2))-64, a1=(entry(sym(.data)) << 0x2), a2=?, a3=?.
  The `jal` at 0x35cc calls us_delay with a0=0xa, a1=?, a2=?, a3=?.
  The `jal` at 0x35f8 calls pciio_pio_read32 with a0=([[a0+464]+344] + ([table(sym(.data))+8]:2 << 0x2))-64, a1=([table(sym(.data))+8]:2 << 0x2), a2=[a0+480], a3=?.
  The `jal` at 0x3644 calls pciio_pio_read32 with a0=([[a0+464]+344] + (entry(sym(.data)) << 0x2))-64, a1=(entry(sym(.data)) << 0x2), a2=[a0+480], a3=?.
  The `jal` at 0x36a0 calls pciio_pio_write32 with a0=[[a0+520]], a1=([[a0+464]+344] + [a0+516]), a2=[a0+516], a3=?, a4=[[a0+520]].
  The `jal` at 0x374c calls pciio_pio_read32 with a0=[[a0+464]+344]+48, a1=?, a2=?, a3=?.
  The `jal` at 0x3774 calls rad_sync_device_ust with a0=a0 at entry (arg0), a1=ret(pciio_pio_read32), a2=?, a3=0x3ffff.
  The `jal` at 0x378c calls rad_start_status_dma with a0=[a0+464], a1=?, a2=?, a3=?.
  The `jal` at 0x3804 calls pciio_pio_write32 with a0=[[a0+520]], a1=([[a0+464]+344] + [a0+516]), a2=[a0+516], a3=?, a4=[a0+520], a5=[[a0+520]].
  The `jal` at 0x3834 calls pciio_pio_write32 with a0=?, a1=[[a0+464]+344]+128, a2=-0xc1, a3=[a0+480], a5=0x4.
  The `jal` at 0x3858 calls cmn_err with a0=0x1, a1=sym(.rodata)+1336, a2=[[a0+464]+20268], a3=[a0+480].
  The `beq` branch at 0x3310 targets 0x384c, is taken when a3(=[a0+480]) == at(=-0x2), and falls through when a3(=[a0+480]) != at(=-0x2).
  The `beq` branch at 0x331c targets 0x384c, is taken when a3(=[a0+480]) == v0(=-0x1), and falls through when a3(=[a0+480]) != v0(=-0x1).
  The `beq` branch at 0x332c targets 0x3418, is taken when (v1(=[a0+420]) & 0x400) == 0, and falls through when (v1(=[a0+420]) & 0x400) != 0.
  The `beq` branch at 0x333c targets 0x3370, is taken when a0(=[a0+372]) >= 0x20 (signed), and falls through when a0(=[a0+372]) < 0x20 (signed).
  The `beq` branch at 0x3344 targets 0x3434, is taken when a3(=[a0+480]) == a1(=0x7), and falls through when a3(=[a0+480]) != a1(=0x7).
  The `bne` branch at 0x3350 targets 0x3374, is taken when a2(?) != 0, and falls through when a2(?) == 0.
  The `bne` branch at 0x3360 targets 0x3374, is taken when v0(=ret(rad_start_dma)) != 0, and falls through when v0(=ret(rad_start_dma)) == 0.
  The `beq` branch at 0x3368 targets 0x33fc and is always taken.
  The `beq` branch at 0x338c targets 0x3420, is taken when (a2(=[a0+420]) & 0x1) == 0, and falls through when (a2(=[a0+420]) & 0x1) != 0.
  The `beq` branch at 0x33c0 targets 0x343c, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `beq` branch at 0x3418 targets 0x3374 and is always taken.
  The `beq` branch at 0x342c targets 0x33c0 and is always taken.
  The `beq` branch at 0x3434 targets 0x334c and is always taken.
  The `beq` branch at 0x3594 targets 0x37d8, is taken when a3(=[a0+480]) == a5(=0x7), and falls through when a3(=[a0+480]) != a5(=0x7).
  The `beq` branch at 0x359c targets 0x37d8, is taken when a3(=[a0+480]) == a1(=0x6), and falls through when a3(=[a0+480]) != a1(=0x6).
  The `beq` branch at 0x35bc targets 0x3668 and is always taken.
  The `bne` branch at 0x35c4 targets 0x3634, is taken when a6(?) != s4(?), and falls through when a6(?) == s4(?).
  The `bne` branch at 0x362c targets 0x35c4, is taken when s3(?) < 0x32 (signed), and falls through when s3(?) >= 0x32 (signed).
  The `beq` branch at 0x3650 targets 0x36b4, is taken when s3(?) == a1(=0x32), and falls through when s3(?) != a1(=0x32).
  The `beq` branch at 0x3660 targets 0x36f8, is taken when a2(=one of 0x0, 0x1) == 0, and falls through when a2(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x36ac targets 0x35cc and is always taken.
  The `bne` branch at 0x36c4 targets 0x36d8, is taken when a1(?) != a5(?), and falls through when a1(?) == a5(?).
  The `beq` branch at 0x36d0 targets 0x36ec and is always taken.
  The `bne` branch at 0x36e0 targets 0x37e0, is taken when a2(?) < 0x6 (signed), and falls through when a2(?) >= 0x6 (signed).
  The `beq` branch at 0x36f0 targets 0x365c and is always taken.
  The `beq` branch at 0x3794 targets 0x3818, is taken when v0(=ret(rad_start_status_dma)) == 0, and falls through when v0(=ret(rad_start_status_dma)) != 0.
  The `beq` branch at 0x37a4 targets 0x37b8, is taken when a3(=[a0+480]) == a5(=0x4), and falls through when a3(=[a0+480]) != a5(=0x4).
  The `bne` branch at 0x37b0 targets 0x33e8, is taken when a3(=[a0+480]) != a6(=0x7), and falls through when a3(=[a0+480]) == a6(=0x7).
  The `beq` branch at 0x37c0 targets 0x3820, is taken when (a7(=[[a0+464]+484]) & 0x40) == 0, and falls through when (a7(=[[a0+464]+484]) & 0x40) != 0.
  The `beq` branch at 0x37d0 targets 0x33e8 and is always taken.
  The `beq` branch at 0x37d8 targets 0x35a4 and is always taken.
  The `beq` branch at 0x3810 targets 0x36e4 and is always taken.
  The `beq` branch at 0x3818 targets 0x33fc and is always taken.
  The `beq` branch at 0x3844 targets 0x33e8 and is always taken.
  The `beq` branch at 0x3860 targets 0x33fc and is always taken.
  The return at 0x3410 has v0 = one of 0x0, 0x1.

- `rad_start_subcode_tx` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0x3868 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0x3868-0x3a44 (476 bytes).
  It occupies 476 bytes.
  The `lbu` at 0x3870 loads 1 byte from a0 (arg0 at entry) +0x1b0.
  The `lw` at 0x3874 loads 4 bytes from a0 (arg0 at entry) +0x1d0.
  2 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x120, including `sd` at 0x3898, `sd` at 0x3930.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x128, including `lw` at 0x38b0, `lw` at 0x3908.
  The `sw` at 0x38b4 stores 4 bytes to [a0+296] +0x0.
  The `lw` at 0x38b8 loads 4 bytes from a0 (arg0 at entry) +0x15c.
  The `lw` at 0x38bc loads 4 bytes from a0 (arg0 at entry) +0x130.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x208, including `lw` at 0x38c8, `lw` at 0x38d8.
  2 such `lw` accesses load 4 bytes from [a0+520] +0x0, including `lw` at 0x38cc, `lw` at 0x38ec.
  The `sw` at 0x38d4 stores 4 bytes to [a0+520] +0x0.
  The `lw` at 0x38dc loads 4 bytes from a0 (arg0 at entry) +0x204.
  3 such `lw` accesses load 4 bytes from [a0+464] +0x158, including `lw` at 0x38e0, `lw` at 0x39d4, `lw` at 0x3a10.
  The `lw` at 0x38f0 loads 4 bytes from a0 (arg0 at entry) +0x1a4.
  The `lw` at 0x3904 loads 4 bytes from a0 (arg0 at entry) +0x178.
  The `sw` at 0x3914 stores 4 bytes to [a0+296] +0x4.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x1e0, including `lw` at 0x3918, `lw` at 0x39fc, `lw` at 0x3a38.
  The `ld` at 0x393c loads 8 bytes from a0 (arg0 at entry) +0x118.
  The `sd` at 0x396c stores 8 bytes to a0 (arg0 at entry) +0x118.
  The `lbu` at 0x3970 loads 1 byte from [a0+464] +0x4f21.
  The `sb` at 0x3978 stores 1 byte to [a0+464] +0x4f21.
  The `sw` at 0x398c stores 4 bytes to a0 (arg0 at entry) +0x1e4.
  The `sb` at 0x3990 stores 1 byte to a0 (arg0 at entry) +0x1b0.
  The `lw` at 0x3994 loads 4 bytes from [a0+464] +0x4ed8.
  The `sw` at 0x39a4 stores 4 bytes to [a0+464] +0x4ed8.
  The `lbu` at 0x39b8 loads 1 byte from [a0+464] +0x4f20.
  The `sb` at 0x39c4 stores 1 byte to [a0+464] +0x4f20.
  The `lh` at 0x39d0 loads 2 bytes from sym(.data) +0x50.
  The `lh` at 0x39f0 loads 2 bytes from sym(.data) +0x52.
  The `lw` at 0x39f4 loads 4 bytes from sym(.data) +0x54.
  The `lh` at 0x3a0c loads 2 bytes from sym(.data) +0x80.
  The `lh` at 0x3a2c loads 2 bytes from sym(.data) +0x82.
  The `lw` at 0x3a30 loads 4 bytes from sym(.data) +0x84.
  The `jal` at 0x3888 calls update_ust with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x38c0 calls bzero with a0=[a0+304], a1=([a0+348] << 0x2), a2=[a0+296], a3=a3 at entry (arg3).
  The `jal` at 0x38e8 calls pciio_pio_write32 with a0=[[a0+520]], a1=([[a0+464]+344] + [a0+516]), a2=[a0+516], a3=([[a0+520]] | 0x40), a4=[a0+520].
  The `jal` at 0x3910 calls update_ust with a0=0x1, a1=?, a2=?, a3=?, a6=[a0+296].
  The `jal` at 0x397c calls rad_start_status_dma with a0=[a0+464], a1=?, a2=?, a3=?.
  The `jal` at 0x39e0 calls pciio_pio_read32 with a0=([[a0+464]+344] + ([sym(.data)+80]:2 << 0x2))-64, a1=([sym(.data)+80]:2 << 0x2), a2=?, a3=?, a4=-0x1, a6=[sym(ust_val)]:8.
  The `jal` at 0x3a1c calls pciio_pio_read32 with a0=([[a0+464]+344] + ([sym(.data)+128]:2 << 0x2))-64, a1=([sym(.data)+128]:2 << 0x2), a2=?, a3=?, a4=-0x1, a6=[sym(ust_val)]:8.
  The `beq` branch at 0x3880 targets 0x38b0, is taken when at(=[a0+432]:1) == 0, and falls through when at(=[a0+432]:1) != 0.
  The `beq` branch at 0x38fc targets 0x39b0, is taken when (a4(=[a0+420]) & 0x800) == 0, and falls through when (a4(=[a0+420]) & 0x800) != 0.
  The `beq` branch at 0x392c targets 0x39c8, is taken when a0(=[a0+480]) == a4(=-0x1), and falls through when a0(=[a0+480]) != a4(=-0x1).
  The `beq` branch at 0x3934 targets 0x3a08, is taken when a0(=[a0+480]) == v0(=-0x2), and falls through when a0(=[a0+480]) != v0(=-0x2).
  The `beq` branch at 0x3968 targets 0x39b8, is taken when a0(=[a0+480]) == t0(=-0x1), and falls through when a0(=[a0+480]) != t0(=-0x1).
  The `beq` branch at 0x3984 targets 0x39a8, is taken when v0(=ret(rad_start_status_dma)) == 0, and falls through when v0(=ret(rad_start_status_dma)) != 0.
  The `beq` branch at 0x39a0 targets 0x389c and is always taken.
  The `beq` branch at 0x39a8 targets 0x389c and is always taken.
  The `beq` branch at 0x39b0 targets 0x3904 and is always taken.
  The `beq` branch at 0x39c0 targets 0x397c and is always taken.
  The `beq` branch at 0x3a00 targets 0x393c and is always taken.
  The `beq` branch at 0x3a3c targets 0x393c and is always taken.
  The return at 0x38a8 has v0 = one of 0x0, 0x1.

- `rad_stop_dma` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0x3a44 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0x3a44-0x3c58 (532 bytes).
  It occupies 532 bytes.
  The `lbu` at 0x3a4c loads 1 byte from a0 (arg0 at entry) +0x1b0.
  The `lw` at 0x3a50 loads 4 bytes from a0 (arg0 at entry) +0x1d0.
  The `lw` at 0x3a6c loads 4 bytes from a0 (arg0 at entry) +0x1e0.
  6 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x208, including `lw` at 0x3a94, `lw` at 0x3aa4, `lw` at 0x3b8c.
  4 such `lw` accesses load 4 bytes from [a0+520] +0x0, including `lw` at 0x3a98, `lw` at 0x3ab8, `lw` at 0x3c2c.
  3 such `sw` accesses store 4 bytes to [a0+520] +0x0, including `sw` at 0x3aa0, `sw` at 0x3c3c, `sw` at 0x3c54.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x204, including `lw` at 0x3aa8, `lw` at 0x3abc, `lw` at 0x3acc.
  3 such `lw` accesses load 4 bytes from [a0+464] +0x158, including `lw` at 0x3aac, `lw` at 0x3ac0, `lw` at 0x3ad0.
  The `lw` at 0x3ae0 loads 4 bytes from [a0+464] +0x4f2c.
  3 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x1b0, including `sb` at 0x3aec, `sb` at 0x3b38, `sb` at 0x3c24.
  The `lw` at 0x3af0 loads 4 bytes from [a0+464] +0x4ed8.
  The `sw` at 0x3af8 stores 4 bytes to [a0+464] +0x4ed8.
  The `lbu` at 0x3b10 loads 1 byte from [a0+464] +0x4f20.
  The `sb` at 0x3b20 stores 1 byte to [a0+464] +0x4f20.
  The `sb` at 0x3b30 stores 1 byte to [a0+464] +0x4f22.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x174, including `lw` at 0x3b3c, `lw` at 0x3b90.
  3 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x3b58, `lbu` at 0x3bac, `lbu` at 0x3bc8.
  The `lbu` at 0x3bfc loads 1 byte from [a0+464] +0x4f21.
  The `sb` at 0x3c0c stores 1 byte to [a0+464] +0x4f21.
  The `sb` at 0x3c1c stores 1 byte to [a0+464] +0x4f23.
  The `jal` at 0x3ab4 calls pciio_pio_write32 with a0=[[a0+520]], a1=([[a0+464]+344] + [a0+516]), a2=[a0+516], a3=?.
  The `jal` at 0x3ac4 calls pciio_pio_read32 with a0=([[a0+464]+344] + [a0+516]), a1=[a0+516], a2=?, a3=?.
  The `jal` at 0x3ad8 calls pciio_pio_read32 with a0=([[a0+464]+344] + [a0+516]), a1=[a0+516], a2=?, a3=?.
  The `jal` at 0x3ae4 calls pcimh_flush_buffers with a0=[[a0+464]+20268], a1=?, a2=?, a3=?.
  The `jal` at 0x3b2c calls rad_pio_writeback_subcode_tx with a0=[a0+464]+8352, a1=a1 at entry (arg1), a2=0x6, a3=?, a4=0x1.
  The `jal` at 0x3b80 calls rad_stop_dma with a0=[a0+464]+5592, a1=a1 at entry (arg1), a2=?, a3=?, a5=0x1.
  The `jal` at 0x3bec calls rad_stop_dma with a0=[a0+464]+6144, a1=a1 at entry (arg1), a2=?, a3=?, a5=0x1.
  The `jal` at 0x3c18 calls rad_pio_writeback_subcode_tx with a0=[a0+464]+12216, a1=a1 at entry (arg1), a2=0x6, a3=0x7, a4=-0x2.
  The `beq` branch at 0x3a64 targets 0x3afc, is taken when at(=[a0+432]:1) == 0, and falls through when at(=[a0+432]:1) != 0.
  The `beq` branch at 0x3a74 targets 0x3b10, is taken when a0(=[a0+480]) == v0(=-0x1), and falls through when a0(=[a0+480]) != v0(=-0x1).
  The `beq` branch at 0x3a7c targets 0x3bfc, is taken when a0(=[a0+480]) == a4(=-0x2), and falls through when a0(=[a0+480]) != a4(=-0x2).
  The `beq` branch at 0x3a84 targets 0x3b3c, is taken when a0(=[a0+480]) == a2(=0x6), and falls through when a0(=[a0+480]) != a2(=0x6).
  The `beq` branch at 0x3a8c targets 0x3b90, is taken when a0(=[a0+480]) == a3(=0x7), and falls through when a0(=[a0+480]) != a3(=0x7).
  The `bne` branch at 0x3b1c targets 0x3aec, is taken when (a3(=[[a0+464]+20256]:1-1) & 0xff) != 0, and falls through when (a3(=[[a0+464]+20256]:1-1) & 0xff) == 0.
  The `beq` branch at 0x3b34 targets 0x3af0 and is always taken.
  The `beq` branch at 0x3b50 targets 0x3c28, is taken when a5(=[a0+372]) >= 0x20 (signed), and falls through when a5(=[a0+372]) < 0x20 (signed).
  The `beq` branch at 0x3b64 targets 0x3b70, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `bne` branch at 0x3b70 targets 0x3b58, is taken when a4(?) != 0, and falls through when a4(?) == 0.
  The `bne` branch at 0x3b78 targets 0x3aa4, is taken when a0(?) != a5(=0x1), and falls through when a0(?) == a5(=0x1).
  The `beq` branch at 0x3b88 targets 0x3aa8 and is always taken.
  The `beq` branch at 0x3ba4 targets 0x3c40, is taken when a7(=[a0+372]) >= 0x20 (signed), and falls through when a7(=[a0+372]) < 0x20 (signed).
  The `beq` branch at 0x3bb4 targets 0x3bc0, is taken when t0(?) == 0, and falls through when t0(?) != 0.
  The `beq` branch at 0x3bc0 targets 0x3be4, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0x3bd0 targets 0x3bdc, is taken when t1(?) == 0, and falls through when t1(?) != 0.
  The `bne` branch at 0x3bdc targets 0x3bac, is taken when a4(?) != 0, and falls through when a4(?) == 0.
  The `bne` branch at 0x3be4 targets 0x3aa4, is taken when a0(?) != a5(=0x1), and falls through when a0(?) == a5(=0x1).
  The `beq` branch at 0x3bf4 targets 0x3aa8 and is always taken.
  The `bne` branch at 0x3c08 targets 0x3aec, is taken when (t2(=[[a0+464]+20257]:1-1) & 0xff) != 0, and falls through when (t2(=[[a0+464]+20257]:1-1) & 0xff) == 0.
  The `beq` branch at 0x3c20 targets 0x3af0 and is always taken.
  The `beq` branch at 0x3c38 targets 0x3aa4 and is always taken.
  The `beq` branch at 0x3c50 targets 0x3aa4 and is always taken.
  The return at 0x3b08 has v0 = ?.

- `rad_mclk_update_cg` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0x3c58 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0x3c58-0x3d74 (284 bytes).
  It occupies 284 bytes.
  The `lw` at 0x3c70 loads 4 bytes from a0 (arg0 at entry) +0x150.
  The `lw` at 0x3c8c loads 4 bytes from a0 (arg0 at entry) +0x134.
  The `lw` at 0x3c90 loads 4 bytes from [a0+308] +0x9c.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x170, including `lw` at 0x3ca4, `lw` at 0x3d0c.
  5 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x170, including `sw` at 0x3cb4, `sw` at 0x3d28, `sw` at 0x3d44.
  The `lw` at 0x3cb8 loads 4 bytes from [a0+336] +0x158.
  The `ld` at 0x3cf8 loads 8 bytes from a0 (arg0 at entry) +0x110.
  The `jal` at 0x3c6c calls kdsp_mclk_update_cg with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x3cd8 calls pciio_pio_write32 with a0=table(0x2000000), a1=[[a0+336]+344]+160, a2=0x2000000, a3=one of 0x3, 0x6, 0xc, 0x18, a6=one of 0xe5b, 0x396c00000000.
  The `bne` branch at 0x3c84 targets 0x3ce0, is taken when s0(=a0) != at(=[a0+336]+17880), and falls through when s0(=a0) == at(=[a0+336]+17880).
  The `beq` branch at 0x3c94 targets 0x3ca4, is taken when a1(=[[a0+308]+156]) == a4(=0x2000000b), and falls through when a1(=[[a0+308]+156]) != a4(=0x2000000b).
  The `bne` branch at 0x3c9c targets 0x3cf4, is taken when a1(=[[a0+308]+156]) != a2(=0x2000000c), and falls through when a1(=[[a0+308]+156]) == a2(=0x2000000c).
  The `beq` branch at 0x3cac targets 0x3ce4, is taken when a2(=[a0+368]) == a3(=0x3), and falls through when a2(=[a0+368]) != a3(=0x3).
  The `beq` branch at 0x3d10 targets 0x3d2c, is taken when a4(=0x72d800000000) >= a5(=[a0+272]:8) (signed), and falls through when a4(=0x72d800000000) < a5(=[a0+272]:8) (signed).
  The `beq` branch at 0x3d1c targets 0x3ce4, is taken when a1(=[a0+368]) == a3(=0x3), and falls through when a1(=[a0+368]) != a3(=0x3).
  The `beq` branch at 0x3d24 targets 0x3cb8 and is always taken.
  The `beq` branch at 0x3d30 targets 0x3d48, is taken when a6(=0x396c00000000) >= a5(=[a0+272]:8) (signed), and falls through when a6(=0x396c00000000) < a5(=[a0+272]:8) (signed).
  The `beq` branch at 0x3d38 targets 0x3ce4, is taken when a1(=[a0+368]) == a3(=0x6), and falls through when a1(=[a0+368]) != a3(=0x6).
  The `beq` branch at 0x3d40 targets 0x3cb8 and is always taken.
  The `beq` branch at 0x3d48 targets 0x3d64, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0x3d54 targets 0x3ce4, is taken when a1(=[a0+368]) == a3(=0xc), and falls through when a1(=[a0+368]) != a3(=0xc).
  The `beq` branch at 0x3d5c targets 0x3cb8 and is always taken.
  The `beq` branch at 0x3d64 targets 0x3ce4, is taken when a1(=[a0+368]) == a3(=0x18), and falls through when a1(=[a0+368]) != a3(=0x18).
  The `beq` branch at 0x3d6c targets 0x3cb8 and is always taken.
  The return at 0x3cec has v0 = one of ret(kdsp_mclk_update_cg), ?.

- `rad_check_adat_rx` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0x3d74 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0x3d74-0x3f10 (412 bytes).
  It occupies 412 bytes.
  3 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x4f19, including `lbu` at 0x3d74, `lbu` at 0x3dc4, `lbu` at 0x3f0c.
  2 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x4f1a, including `lbu` at 0x3da4, `lbu` at 0x3e8c.
  2 such `sh` accesses store 2 bytes to a0 (arg0 at entry) +0x4f1c, including `sh` at 0x3db0, `sh` at 0x3de8.
  2 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x4f1b, including `sb` at 0x3db4, `sb` at 0x3df8.
  The `lbu` at 0x3db8 loads 1 byte from a0 (arg0 at entry) +0x4f1b.
  The `sb` at 0x3dc8 stores 1 byte to a0 (arg0 at entry) +0x4f1a.
  The `lhu` at 0x3dd8 loads 2 bytes from a0 (arg0 at entry) +0x4f1c.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x1e4, including `lw` at 0x3e04, `lw` at 0x3e28, `lw` at 0x3e78.
  3 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x55c, including `sb` at 0x3e14, `sb` at 0x3eb8, `sb` at 0x3ecc.
  4 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x4f19, including `sb` at 0x3e18, `sb` at 0x3e68, `sb` at 0x3ebc.
  3 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x13ac, including `sw` at 0x3e24, `sw` at 0x3eb4, `sw` at 0x3ed0.
  5 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x158, including `lw` at 0x3e38, `lw` at 0x3e4c, `lw` at 0x3e90.
  5 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x4e50, including `lw` at 0x3e3c, `lw` at 0x3e50, `lw` at 0x3e94.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x4e50, including `sw` at 0x3e60, `sw` at 0x3ea8.
  The `lw` at 0x3e74 loads 4 bytes from a0 (arg0 at entry) +0x4f00.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x13a8, including `sw` at 0x3eb0, `sw` at 0x3ed8.
  The `jal` at 0x3df4 calls kdsp_update_mclk_users with a0=a0+1096, a1=0x1, a2=?, a3=?.
  The `jal` at 0x3e44 calls pciio_pio_write32 with a0=([a0+20048] | 0xc0), a1=[a0+344]+128, a2=0x1, a3=0x2, a4=0x1.
  The `jal` at 0x3e5c calls pciio_pio_write32 with a0=([a0+20048] | 0x40), a1=[a0+344]+128, a2=?, a3=?.
  The `jal` at 0x3ea4 calls pciio_pio_write32 with a0=?, a1=[a0+344]+128, a2=-0x41, a3=0x2, a4=0x1.
  The `jal` at 0x3ef0 calls pciio_pio_write32 with a0=([a0+20048] | 0x80), a1=[a0+344]+128, a2=[a0+20249]:1, a3=0x2, a4=0x1.
  The `jal` at 0x3f00 calls pciio_pio_write32 with a0=[a0+20048], a1=[a0+344]+128, a2=?, a3=?.
  The `beq` branch at 0x3d8c targets 0x3e04, is taken when a4(=0x1) == a2(=[a0+20249]:1), and falls through when a4(=0x1) != a2(=[a0+20249]:1).
  The `beq` branch at 0x3d94 targets 0x3e28, is taken when a2(=[a0+20249]:1) == 0, and falls through when a2(=[a0+20249]:1) != 0.
  The `beq` branch at 0x3d9c targets 0x3e74, is taken when a2(=[a0+20249]:1) == a3(=0x2), and falls through when a2(=[a0+20249]:1) != a3(=0x2).
  The `beq` branch at 0x3da8 targets 0x3db8, is taken when at(=[a0+20250]:1) == a2(?), and falls through when at(=[a0+20250]:1) != a2(?).
  The `beq` branch at 0x3dbc targets 0x3dd8, is taken when v0(=[a0+20251]:1) == 0, and falls through when v0(=[a0+20251]:1) != 0.
  The `bne` branch at 0x3de4 targets 0x3dc0, is taken when (a0(=[a0+20252]:2-1) & 0xffff) != 0, and falls through when (a0(=[a0+20252]:2-1) & 0xffff) == 0.
  The `beq` branch at 0x3dfc targets 0x3dc4 and is always taken.
  The `beq` branch at 0x3e0c targets 0x3da4, is taken when (a3(=[a0+484]) & 0x40) == 0, and falls through when (a3(=[a0+484]) & 0x40) != 0.
  The `beq` branch at 0x3e20 targets 0x3da4 and is always taken.
  The `beq` branch at 0x3e30 targets 0x3ec8, is taken when (a5(=[a0+484]) & 0x40) == 0, and falls through when (a5(=[a0+484]) & 0x40) != 0.
  The `beq` branch at 0x3e6c targets 0x3da4 and is always taken.
  The `beq` branch at 0x3e80 targets 0x3edc, is taken when (a1(=[a0+20224]) & 0x3ff) == 0, and falls through when (a1(=[a0+20224]) & 0x3ff) != 0.
  The `bnel` branch at 0x3e88 targets 0x3da8, is taken when a0(?) != 0, and falls through when a0(?) == 0; its branch-likely delay slot `lbu at,20250(s0)` at 0x3e8c runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x3ec0 targets 0x3da4 and is always taken.
  The `beq` branch at 0x3ed4 targets 0x3da4 and is always taken.
  The `beq` branch at 0x3edc targets 0x3e90, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x3f08 targets 0x3da4 and is always taken.
  The return at 0x3dd0 has v0 = one of [a0+20251]:1, ret(kdsp_update_mclk_users).

- `rad_update_dev` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0x3f10 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0x3f10-0x4428 (1304 bytes).
  It occupies 1304 bytes.
  The `lw` at 0x3f18 loads 4 bytes from a0 (arg0 at entry) +0x1d0.
  The `lbu` at 0x3f2c loads 1 byte from a0 (arg0 at entry) +0x1b0.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x1a4, including `lw` at 0x3f44, `lw` at 0x4094.
  2 such `lbu` accesses load 1 byte from [a0+464] +0x4f1f, including `lbu` at 0x3f60, `lbu` at 0x419c.
  7 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x1e0, including `lw` at 0x3f70, `lw` at 0x3f8c, `lw` at 0x3f90.
  2 such `lbu` accesses load 1 byte from [a0+464] +0x4f1e, including `lbu` at 0x3f7c, `lbu` at 0x42ac.
  The `lw` at 0x3fa8 loads 4 bytes from a0 (arg0 at entry) +0x13c.
  The `lw` at 0x3fb0 loads 4 bytes from a0 (arg0 at entry) +0x134.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x128, including `lw` at 0x3fb8, `lw` at 0x4200, `lw` at 0x4334.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x210, including `lw` at 0x3fc8, `lw` at 0x4198.
  The `lw` at 0x3fcc loads 4 bytes from [a0+528] +0x0.
  The `lw` at 0x3fec loads 4 bytes from a0 (arg0 at entry) +0x214.
  The `lw` at 0x3ff0 loads 4 bytes from [a0+532] +0x0.
  The `ld` at 0x3ff8 loads 8 bytes from a0 (arg0 at entry) +0x218.
  The `lw` at 0x4008 loads 4 bytes from a0 (arg0 at entry) +0x220.
  The `sd` at 0x402c stores 8 bytes to a0 (arg0 at entry) +0x218.
  The `lw` at 0x4038 loads 4 bytes from [a0+464] +0x1dc.
  The `ld` at 0x4044 loads 8 bytes from a0 (arg0 at entry) +0x120.
  3 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x120, including `sd` at 0x406c, `sd` at 0x41c0, `sd` at 0x42d0.
  4 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x1e4, including `lw` at 0x4088, `lw` at 0x410c, `lw` at 0x4188.
  5 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x1a0, including `sw` at 0x4090, `sw` at 0x41ac, `sw` at 0x4244.
  2 such `lw` accesses load 4 bytes from [a0+296] +0x0, including `lw` at 0x409c, `lw` at 0x42f0.
  The `sw` at 0x40b4 stores 4 bytes to [a0+296] +0x0.
  The `sw` at 0x40bc stores 4 bytes to a0 (arg0 at entry) +0x1e4.
  4 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x15c, including `lw` at 0x40c0, `lw` at 0x42ec, `lw` at 0x43f8.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x178, including `lw` at 0x40c8, `lw` at 0x4204, `lw` at 0x4338.
  The `ld` at 0x40cc loads 8 bytes from a0 (arg0 at entry) +0x118.
  3 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x118, including `sd` at 0x40d8, `sd` at 0x41b4, `sd` at 0x42c4.
  The `lw` at 0x4138 loads 4 bytes from a0 (arg0 at entry) +0x174.
  4 such `lw` accesses load 4 bytes from [a0+296] +0x4, including `lw` at 0x4148, `lw` at 0x41dc, `lw` at 0x420c.
  2 such `sw` accesses store 4 bytes to [a0+296] +0x4, including `sw` at 0x414c, `sw` at 0x41e0.
  The `lbu` at 0x4158 loads 1 byte from [a0+464] +0x4f19.
  2 such `lw` accesses load 4 bytes from [a0+464] +0x19a0, including `lw` at 0x41a8, `lw` at 0x43e4.
  The `ld` at 0x41b0 loads 8 bytes from [a0+464] +0x1918.
  The `ld` at 0x41b8 loads 8 bytes from [a0+464] +0x1920.
  5 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x130, including `lw` at 0x41c8, `lw` at 0x4220, `lw` at 0x42fc.
  11 such `lw` accesses load 4 bytes from ?, including `lw` at 0x4250, `lw` at 0x4254, `lw` at 0x4260.
  4 such `sw` accesses store 4 bytes to ?, including `sw` at 0x425c, `sw` at 0x428c, `sw` at 0x4388.
  4 such `ld` accesses load 8 bytes from ?, including `ld` at 0x4290, `ld` at 0x43bc, `ld` at 0x4404.
  4 such `sd` accesses store 8 bytes to ?, including `sd` at 0x429c, `sd` at 0x43c8, `sd` at 0x4408.
  The `sb` at 0x42a8 stores 1 byte to [a0+464] +0x4f1f.
  2 such `lw` accesses load 4 bytes from [a0+464] +0x1778, including `lw` at 0x42b8, `lw` at 0x43f4.
  The `ld` at 0x42c0 loads 8 bytes from [a0+464] +0x16f0.
  The `ld` at 0x42c8 loads 8 bytes from [a0+464] +0x16f8.
  The `sb` at 0x43d4 stores 1 byte to [a0+464] +0x4f1e.
  The `jal` at 0x4034 calls rad_sync_device_ust with a0=a0 at entry (arg0), a1=[[a0+464]+476], a2=?, a3=0x3ffff.
  The `jal` at 0x416c calls kdsp_update_default_subcode with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x418c calls rad_check_adat_rx with a0=[a0+464], a1=?, a2=[a0+480], a3=?, a5=0x4.
  The `jal` at 0x41d4 calls dki_dcache_inval with a0=([a0+304] + ([[a0+296]] << 0x2)), a1=?, a2=[a0+304], a3=?, a5=[[a0+296]].
  The `jal` at 0x422c calls rad_prepare_adat_in_subcode with a0=[a0+464], a1=?, a2=?, a3=?, a4=[a0+376].
  The `jal` at 0x4248 calls kdsp_update_default_subcode with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x42e4 calls dki_dcache_inval with a0=[a0+304], a1=?, a2=[a0+304], a3=?, a5=[[a0+296]].
  The `jal` at 0x4304 calls dki_dcache_inval with a0=([a0+304] + ([[a0+296]] << 0x2)), a1=?, a2=([[a0+296]] << 0x2), a3=?.
  The `jal` at 0x4358 calls rad_prepare_aes_in_subcode with a0=[a0+464], a1=?, a2=[a0+304], a3=?, a6=[a0+376].
  The `jal` at 0x4374 calls kdsp_update_default_subcode with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x43d8 calls rad_update_dev with a0=[a0+464]+6144, a1=0x7, a2=[a0+480], a3=[a0+464]+5592, a4=0x6.
  The `jal` at 0x43e8 calls rad_update_dev with a0=[a0+464]+5592, a1=0x7, a2=[a0+480], a3=[a0+464]+5592, a4=0x6.
  The `beq` branch at 0x3f3c targets 0x40dc, is taken when at(=[a0+432]:1) == 0, and falls through when at(=[a0+432]:1) != 0.
  The `beq` branch at 0x3f4c targets 0x4104, is taken when (v0(=[a0+420]) & 0x400) == 0, and falls through when (v0(=[a0+420]) & 0x400) != 0.
  The `bne` branch at 0x3f58 targets 0x3f74, is taken when a0(=[a0+464]+6144) != s0(=a0), and falls through when a0(=[a0+464]+6144) == s0(=a0).
  The `bne` branch at 0x3f64 targets 0x40e0, is taken when v1(=[[a0+464]+20255]:1) != 0, and falls through when v1(=[[a0+464]+20255]:1) == 0.
  The `beq` branch at 0x3f6c targets 0x3fa8 and is always taken.
  The `bne` branch at 0x3f74 targets 0x3f90, is taken when a3(=[a0+464]+5592) != s0(=a0), and falls through when a3(=[a0+464]+5592) == s0(=a0).
  The `bne` branch at 0x3f80 targets 0x40e0, is taken when a0(=[[a0+464]+20254]:1) != 0, and falls through when a0(=[[a0+464]+20254]:1) == 0.
  The `beq` branch at 0x3f88 targets 0x3fa8 and is always taken.
  The `beq` branch at 0x3f98 targets 0x419c, is taken when a2(=[a0+480]) == a1(=0x7), and falls through when a2(=[a0+480]) != a1(=0x7).
  The `beq` branch at 0x3fa0 targets 0x42ac, is taken when a2(=[a0+480]) == a4(=0x6), and falls through when a2(=[a0+480]) != a4(=0x6).
  The `beq` branch at 0x3fb4 targets 0x418c, is taken when a2(=[a0+480]) == a5(=0x4), and falls through when a2(=[a0+480]) != a5(=0x4).
  The `beq` branch at 0x3fc0 targets 0x418c, is taken when a2(=[a0+480]) == a6(=0x7), and falls through when a2(=[a0+480]) != a6(=0x7).
  The `bne` branch at 0x3fe0 targets 0x3fec, is taken when s2(?) < s3(=[a0+316]) (unsigned), and falls through when s2(?) >= s3(=[a0+316]) (unsigned).
  The `beq` branch at 0x4028 targets 0x4044, is taken when t9(=[a0+544]) == 0, and falls through when t9(=[a0+544]) != 0.
  The `beq` branch at 0x403c targets 0x4074 and is always taken.
  The `beq` branch at 0x4078 targets 0x410c, is taken when a0(=[a0+480]) == a2(=0x6), and falls through when a0(=[a0+480]) != a2(=0x6).
  The `beq` branch at 0x4080 targets 0x4158, is taken when a0(=[a0+480]) == v0(=0x7), and falls through when a0(=[a0+480]) != v0(=0x7).
  The `beq` branch at 0x408c targets 0x40dc, is taken when a0(=[a0+484]) == s2(?), and falls through when a0(=[a0+484]) != s2(?).
  The `beq` branch at 0x40a8 targets 0x412c, is taken when (a0(=[a0+420]) & 0x1) == 0, and falls through when (a0(=[a0+420]) & 0x1) != 0.
  The `bgez` branch at 0x40b8 targets 0x40c8, is taken when s3(?) >= 0 (signed), and falls through when s3(?) < 0 (signed).
  The `beq` branch at 0x4104 targets 0x3fa8 and is always taken.
  The `bltz` branch at 0x4114 targets 0x42d4, is taken when a2(?) < 0 (signed), and falls through when a2(?) >= 0 (signed).
  The `beq` branch at 0x411c targets 0x408c, is taken when at(?) == 0, and falls through when at(?) != 0.
  The `beq` branch at 0x4124 targets 0x408c and is always taken.
  The `beq` branch at 0x4130 targets 0x41c4, is taken when (a0(=[a0+420]) & 0x400) == 0, and falls through when (a0(=[a0+420]) & 0x400) != 0.
  The `beq` branch at 0x4140 targets 0x41c4, is taken when v1(=[a0+372]) >= 0x20 (signed), and falls through when v1(=[a0+372]) < 0x20 (signed).
  The `beq` branch at 0x4150 targets 0x40b8 and is always taken.
  The `beq` branch at 0x4160 targets 0x4088, is taken when t8(=[[a0+464]+20249]:1) == t9(=0x1), and falls through when t8(=[[a0+464]+20249]:1) != t9(=0x1).
  The `bne` branch at 0x417c targets 0x416c, is taken when s6(?) < 0x4 (signed), and falls through when s6(?) >= 0x4 (signed).
  The `beq` branch at 0x4184 targets 0x408c and is always taken.
  The `beq` branch at 0x4194 targets 0x3fcc and is always taken.
  The `beq` branch at 0x41a0 targets 0x43d8, is taken when at(=[[a0+464]+20255]:1) == 0, and falls through when at(=[[a0+464]+20255]:1) != 0.
  The `beq` branch at 0x41bc targets 0x40dc and is always taken.
  The `bltz` branch at 0x41c4 targets 0x42e0, is taken when a4(?) < 0 (signed), and falls through when a4(?) >= 0 (signed).
  The `beq` branch at 0x41f0 targets 0x4314, is taken when a0(=[a0+480]) == t8(=0x6), and falls through when a0(=[a0+480]) != t8(=0x6).
  The `bne` branch at 0x41f8 targets 0x40b8, is taken when a0(=[a0+480]) != a2(=0x7), and falls through when a0(=[a0+480]) == a2(=0x7).
  The `bltz` branch at 0x4218 targets 0x441c, is taken when a2(?) < 0 (signed), and falls through when a2(?) >= 0 (signed).
  The `bne` branch at 0x4284 targets 0x4290, is taken when a0(?) < a1(?) (signed), and falls through when a0(?) >= a1(?) (signed).
  The `bne` branch at 0x4298 targets 0x4248, is taken when a6(?) != 0, and falls through when a6(?) == 0.
  The `beq` branch at 0x42a4 targets 0x40b8 and is always taken.
  The `beq` branch at 0x42b0 targets 0x43e8, is taken when t1(=[[a0+464]+20254]:1) == 0, and falls through when t1(=[[a0+464]+20254]:1) != 0.
  The `beq` branch at 0x42cc targets 0x40dc and is always taken.
  The `beq` branch at 0x42d8 targets 0x4118 and is always taken.
  The `beq` branch at 0x430c targets 0x41dc and is always taken.
  The `beq` branch at 0x432c targets 0x4404, is taken when (a3(?) & 0x1) == 0, and falls through when (a3(?) & 0x1) != 0.
  The `bltz` branch at 0x434c targets 0x43f8, is taken when a4(?) < 0 (signed), and falls through when a4(?) >= 0 (signed).
  The `bne` branch at 0x43b0 targets 0x43bc, is taken when a0(?) < a1(?) (signed), and falls through when a0(?) >= a1(?) (signed).
  The `bne` branch at 0x43c4 targets 0x4374, is taken when a6(?) != 0, and falls through when a6(?) == 0.
  The `beq` branch at 0x43d0 targets 0x40b8 and is always taken.
  The `beq` branch at 0x43e0 targets 0x41ac and is always taken.
  The `beq` branch at 0x43f0 targets 0x42bc and is always taken.
  The `beq` branch at 0x43fc targets 0x4350 and is always taken.
  The `beq` branch at 0x4414 targets 0x4334 and is always taken.
  The `beq` branch at 0x4420 targets 0x4220 and is always taken.
  The return at 0x40fc has v0 = ?.

- `rad_update_subcode_tx_dev` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0x4428 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0x4428-0x45b0 (392 bytes).
  It occupies 392 bytes.
  The `lbu` at 0x4428 loads 1 byte from a0 (arg0 at entry) +0x1b0.
  The `lw` at 0x4430 loads 4 bytes from a0 (arg0 at entry) +0x1d0.
  The `ld` at 0x4440 loads 8 bytes from a0 (arg0 at entry) +0x120.
  The `lw` at 0x4448 loads 4 bytes from a0 (arg0 at entry) +0x214.
  The `lw` at 0x4454 loads 4 bytes from [a0+532] +0x0.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x118, including `ld` at 0x446c, `ld` at 0x452c.
  The `lw` at 0x4484 loads 4 bytes from a0 (arg0 at entry) +0x1e0.
  The `lw` at 0x4498 loads 4 bytes from a0 (arg0 at entry) +0x128.
  2 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x118, including `sd` at 0x44ac, `sd` at 0x453c.
  The `lwu` at 0x44b0 loads 4 bytes from [a0+464] +0x1c8.
  3 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x120, including `sd` at 0x44cc, `sd` at 0x4530, `sd` at 0x4564.
  The `lw` at 0x44d0 loads 4 bytes from [a0+464] +0x4e4c.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x174, including `lw` at 0x44e4, `lw` at 0x4568.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x1a0, including `sw` at 0x44f0, `sw` at 0x459c.
  The `lw` at 0x44fc loads 4 bytes from [a0+296] +0x0.
  2 such `sw` accesses store 4 bytes to [a0+296] +0x0, including `sw` at 0x4504, `sw` at 0x4520.
  The `lw` at 0x4508 loads 4 bytes from a0 (arg0 at entry) +0x15c.
  The `sd` at 0x4524 stores 8 bytes to a0 (arg0 at entry) +0x218.
  The `sw` at 0x4528 stores 4 bytes to a0 (arg0 at entry) +0x1e4.
  The `lwu` at 0x4548 loads 4 bytes from [a0+464] +0x1d0.
  The `lw` at 0x456c loads 4 bytes from [a0+464] +0x4e48.
  The `beq` branch at 0x4434 targets 0x4540, is taken when at(=[a0+432]:1) == 0, and falls through when at(=[a0+432]:1) != 0.
  The `beq` branch at 0x44a8 targets 0x4548, is taken when a3(=[a0+480]) == t3(=-0x1), and falls through when a3(=[a0+480]) != t3(=-0x1).
  The `beq` branch at 0x44c8 targets 0x4568, is taken when a3(=[a0+480]) == t3(=-0x1), and falls through when a3(=[a0+480]) != t3(=-0x1).
  The `beq` branch at 0x44e0 targets 0x45a0, is taken when a3(?) == t0(=0x2), and falls through when a3(?) != t0(=0x2).
  The `beq` branch at 0x44e8 targets 0x45a0, is taken when a3(?) == t2(=0x1), and falls through when a3(?) != t2(=0x1).
  The `beq` branch at 0x44f4 targets 0x4540, is taken when a2(=one of 0x0, 0x1, 0x6) == 0, and falls through when a2(=one of 0x0, 0x1, 0x6) != 0.
  The `bne` branch at 0x4518 targets 0x4524, is taken when a6(?) < t2(=[a0+348]) (signed), and falls through when a6(?) >= t2(=[a0+348]) (signed).
  The `bne` branch at 0x4560 targets 0x44d0, is taken when a3(=[a0+480]) != t3(=-0x1), and falls through when a3(=[a0+480]) == t3(=-0x1).
  The `beq` branch at 0x4588 targets 0x45a8, is taken when a3(?) == t2(=0x2), and falls through when a3(?) != t2(=0x2).
  The `beq` branch at 0x4590 targets 0x45a8, is taken when a3(?) == a6(=0x1), and falls through when a3(?) != a6(=0x1).
  The `beq` branch at 0x4598 targets 0x44f4 and is always taken.
  The `beq` branch at 0x45a0 targets 0x44f0 and is always taken.
  The `beq` branch at 0x45a8 targets 0x4598 and is always taken.
  The return at 0x4540 has v0 = ?.

- `rad_pio_writeback_subcode_tx` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0x45b0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0x45b0-0x49e4 (1076 bytes).
  It occupies 1076 bytes.
  The `lw` at 0x45b0 loads 4 bytes from a0 (arg0 at entry) +0x16c.
  The `lw` at 0x45b8 loads 4 bytes from a0 (arg0 at entry) +0x1e0.
  The `lw` at 0x45c4 loads 4 bytes from a0 (arg0 at entry) +0x1d0.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x128, including `lw` at 0x45d8, `lw` at 0x4714.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x168, including `lw` at 0x45dc, `lw` at 0x4718.
  2 such `lw` accesses load 4 bytes from [a0+296] +0x4, including `lw` at 0x45e0, `lw` at 0x471c.
  2 such `lw` accesses load 4 bytes from [a0+296] +0x0, including `lw` at 0x45f8, `lw` at 0x4734.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x130, including `lw` at 0x4600, `lw` at 0x4738.
  24 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x4694, `lbu` at 0x4698, `lbu` at 0x46a0.
  4 such `sb` accesses store 1 byte to ?, including `sb` at 0x46a8, `sb` at 0x46b0, `sb` at 0x46d0.
  The `lbu` at 0x46e8 loads 1 byte from [a0+464] +0x4f23.
  The `sb` at 0x46f8 stores 1 byte to [a0+464] +0x4f23.
  2 such `sw` accesses store 4 bytes to ?, including `sw` at 0x480c, `sw` at 0x4868.
  The `lbu` at 0x486c loads 1 byte from [a0+464] +0x4f22.
  The `sb` at 0x487c stores 1 byte to [a0+464] +0x4f22.
  The `lbu` at 0x4890 loads 1 byte from [a0+464] +0x4f20.
  The `lw` at 0x4894 loads 4 bytes from [a0+464] +0x4e48.
  2 such `lbu` accesses load 1 byte from [a0+464] +0x4f24, including `lbu` at 0x48c8, `lbu` at 0x49d4.
  3 such `sb` accesses store 1 byte to [a0+464] +0x4f24, including `sb` at 0x48cc, `sb` at 0x49b8, `sb` at 0x49d8.
  3 such `sb` accesses store 1 byte to [a0+464] +0x4f25, including `sb` at 0x48d4, `sb` at 0x49c0, `sb` at 0x49e0.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x15c, including `lw` at 0x48d8, `lw` at 0x4940.
  The `lbu` at 0x48f4 loads 1 byte from [a0+464] +0x4f21.
  The `lw` at 0x48f8 loads 4 bytes from [a0+464] +0x4e4c.
  2 such `lbu` accesses load 1 byte from [a0+464] +0x4f26, including `lbu` at 0x4930, `lbu` at 0x4988.
  3 such `sb` accesses store 1 byte to [a0+464] +0x4f26, including `sb` at 0x4934, `sb` at 0x496c, `sb` at 0x498c.
  3 such `sb` accesses store 1 byte to [a0+464] +0x4f27, including `sb` at 0x493c, `sb` at 0x4974, `sb` at 0x4994.
  The `jal` at 0x4888 calls rad_prepare_aes_out_subcode with a0=[a0+464], a1=[a0+464]+19800, a2=?, a3=?.
  The `jal` at 0x48c0 calls rad_write_aes_out_subcode with a0=[a0+464], a1=0x1180, a2=[a0+464]+19800, a3=?.
  The `jal` at 0x48ec calls rad_prepare_adat_out_subcode with a0=[a0+464], a1=[a0+464]+19944, a2=?, a3=?.
  The `jal` at 0x4928 calls rad_write_adat_out_subcode with a0=[a0+464], a1=0x1080, a2=[a0+464]+19944, a3=?, a4=0x2, a5=0x1.
  The `jal` at 0x4954 calls rad_write_adat_out_subcode with a0=[a0+464], a1=0x1000, a2=[a0+464]+19944, a3=?, a4=0x2, a5=0x1.
  The `jal` at 0x4964 calls rad_write_adat_out_subcode with a0=[a0+464], a1=0x1080, a2=[a0+464]+19944, a3=?.
  The `jal` at 0x4980 calls rad_write_adat_out_subcode with a0=[a0+464], a1=0x1000, a2=[a0+464]+19944, a3=?, a4=0x2, a5=0x1.
  The `jal` at 0x49a0 calls rad_write_aes_out_subcode with a0=[a0+464], a1=0x1100, a2=[a0+464]+19800, a3=?.
  The `jal` at 0x49b0 calls rad_write_aes_out_subcode with a0=[a0+464], a1=0x1180, a2=[a0+464]+19800, a3=?.
  The `jal` at 0x49cc calls rad_write_aes_out_subcode with a0=[a0+464], a1=0x1100, a2=[a0+464]+19800, a3=?.
  The `beq` branch at 0x45c8 targets 0x470c, is taken when at(=[a0+480]) == v0(=-0x1), and falls through when at(=[a0+480]) != v0(=-0x1).
  The `beq` branch at 0x45d0 targets 0x46e8, is taken when a1(=[a0+364]) == 0, and falls through when a1(=[a0+364]) != 0.
  The `bltz` branch at 0x45e8 targets 0x48d8, is taken when a2(?) < 0 (signed), and falls through when a2(?) >= 0 (signed).
  The `blez` branch at 0x45f0 targets 0x46e8, is taken when a1(?) <= 0 (signed), and falls through when a1(?) > 0 (signed).
  The `beq` branch at 0x4614 targets 0x467c, is taken when a2(=[a0+464]+12216) == a0, and falls through when a2(=[a0+464]+12216) != a0.
  The `beq` branch at 0x4630 targets 0x467c and is never taken: its condition can never hold for these operands, so execution always falls through.
  The `beq` branch at 0x4638 targets 0x467c, is taken when a2(=[a0+464]+12768) == a0, and falls through when a2(=[a0+464]+12768) != a0.
  The `beq` branch at 0x4644 targets 0x467c and is never taken: its condition can never hold for these operands, so execution always falls through.
  The `beq` branch at 0x464c targets 0x467c, is taken when a2(=[a0+464]+13320) == a0, and falls through when a2(=[a0+464]+13320) != a0.
  The `beq` branch at 0x4660 targets 0x467c and is never taken: its condition can never hold for these operands, so execution always falls through.
  The `beq` branch at 0x4668 targets 0x467c, is taken when a2(=[a0+464]+13872) == a0, and falls through when a2(=[a0+464]+13872) != a0.
  The `bne` branch at 0x4674 targets 0x4614 and is never taken: its condition can never hold for these operands, so execution always falls through.
  The `bne` branch at 0x46e0 targets 0x4694, is taken when a0(?) < 0x6 (signed), and falls through when a0(?) >= 0x6 (signed).
  The `blez` branch at 0x46f4 targets 0x48e4, is taken when t2(?) <= 0 (signed), and falls through when t2(?) > 0 (signed).
  The `beq` branch at 0x470c targets 0x486c, is taken when a1(=[a0+364]) == 0, and falls through when a1(=[a0+364]) != 0.
  The `bltz` branch at 0x4724 targets 0x4940, is taken when a2(?) < 0 (signed), and falls through when a2(?) >= 0 (signed).
  The `blez` branch at 0x472c targets 0x486c, is taken when a1(?) <= 0 (signed), and falls through when a1(?) > 0 (signed).
  The `beq` branch at 0x474c targets 0x47b4, is taken when a1(=[a0+464]+8352) == a0, and falls through when a1(=[a0+464]+8352) != a0.
  The `beq` branch at 0x4768 targets 0x47b4 and is never taken: its condition can never hold for these operands, so execution always falls through.
  The `beq` branch at 0x4770 targets 0x47b4, is taken when a1(=[a0+464]+8904) == a0, and falls through when a1(=[a0+464]+8904) != a0.
  The `beq` branch at 0x477c targets 0x47b4 and is never taken: its condition can never hold for these operands, so execution always falls through.
  The `beq` branch at 0x4784 targets 0x47b4, is taken when a1(=[a0+464]+9456) == a0, and falls through when a1(=[a0+464]+9456) != a0.
  The `beq` branch at 0x4798 targets 0x47b4 and is always taken.
  The `bne` branch at 0x4864 targets 0x47c8, is taken when a0(?) < 0x6 (signed), and falls through when a0(?) >= 0x6 (signed).
  The `bgtz` branch at 0x4878 targets 0x46fc, is taken when v1(?) > 0 (signed), and falls through when v1(?) <= 0 (signed).
  The `beq` branch at 0x489c targets 0x4998, is taken when a1(=[[a0+464]+20256]:1) == 0, and falls through when a1(=[[a0+464]+20256]:1) != 0.
  The `beq` branch at 0x48a8 targets 0x49c4, is taken when a0(?) == a1(=0x2), and falls through when a0(?) != a1(=0x2).
  The `bne` branch at 0x48b0 targets 0x4700, is taken when a0(?) != a2(=0x1), and falls through when a0(?) == a2(=0x1).
  The `beq` branch at 0x48d0 targets 0x46fc and is always taken.
  The `beq` branch at 0x48dc targets 0x45f0 and is always taken.
  The `beq` branch at 0x4908 targets 0x494c, is taken when a1(=[[a0+464]+20257]:1) == 0, and falls through when a1(=[[a0+464]+20257]:1) != 0.
  The `beq` branch at 0x4910 targets 0x4978, is taken when a0(?) == a4(=0x2), and falls through when a0(?) != a4(=0x2).
  The `bne` branch at 0x4918 targets 0x4700, is taken when a0(?) != a5(=0x1), and falls through when a0(?) == a5(=0x1).
  The `beq` branch at 0x4938 targets 0x46fc and is always taken.
  The `beq` branch at 0x4944 targets 0x472c and is always taken.
  The `beq` branch at 0x4970 targets 0x46fc and is always taken.
  The `beq` branch at 0x4990 targets 0x46fc and is always taken.
  The `beq` branch at 0x49bc targets 0x46fc and is always taken.
  The `beq` branch at 0x49dc targets 0x46fc and is always taken.
  The return at 0x4704 has v0 = one of ?, ret(rad_prepare_aes_out_subcode), ret(rad_prepare_adat_out_subcode).
  The instructions from 0x47a0 to 0x47b0 are not reached by any path from the entry, and their branches are not listed.

- `rad_pre_connect` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0x49e4 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0x49e4-0x49ec (8 bytes).
  It occupies 8 bytes.
  The return at 0x49e4 has v0 = 0x0.

- `rad_set_clockgen` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0x49ec (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0x49ec-0x4cbc (720 bytes).
  It occupies 720 bytes.
  The `lw` at 0x49f4 loads 4 bytes from a0 (arg0 at entry) +0x150.
  The `lw` at 0x4a04 loads 4 bytes from a0 (arg0 at entry) +0x154.
  The `sw` at 0x4a38 stores 4 bytes to a0 (arg0 at entry) +0x158.
  The `lw` at 0x4a3c loads 4 bytes from a0 (arg0 at entry) +0x160.
  10 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x15c, including `lw` at 0x4a54, `lw` at 0x4ad0, `lw` at 0x4b24.
  The `lw` at 0x4a64 loads 4 bytes from ([a0+336] + ([a0+348] << 0x2)) +0x4edc.
  3 such `lh` accesses load 2 bytes from [a0+336] +0x152, including `lh` at 0x4a7c, `lh` at 0x4b0c, `lh` at 0x4c14.
  3 such `lw` accesses load 4 bytes from [a0+336] +0x4e50, including `lw` at 0x4a94, `lw` at 0x4bf8, `lw` at 0x4c60.
  5 such `lw` accesses load 4 bytes from [a0+336] +0x158, including `lw` at 0x4aa4, `lw` at 0x4ae8, `lw` at 0x4b48.
  2 such `sw` accesses store 4 bytes to [a0+336] +0x4e50, including `sw` at 0x4abc, `sw` at 0x4c10.
  The `lw` at 0x4acc loads 4 bytes from a0 (arg0 at entry) +0x158.
  The `lw` at 0x4ad8 loads 4 bytes from [a0+344] +0x11c.
  The `lw` at 0x4aec loads 4 bytes from (sym(.rodata) + ([a0+348] << 0x2)) +0x0.
  The `sw` at 0x4afc stores 4 bytes to a0 (arg0 at entry) +0x16c.
  The `sw` at 0x4b00 stores 4 bytes to a0 (arg0 at entry) +0x168.
  The `sw` at 0x4b08 stores 4 bytes to a0 (arg0 at entry) +0x164.
  The `sw` at 0x4b40 stores 4 bytes to ([a0+336] + ([a0+348] << 0x2)) +0x4e98.
  The `lw` at 0x4b5c loads 4 bytes from ([a0+336] + ([a0+348] << 0x2)) +0x4e98.
  3 such `lw` accesses load 4 bytes from ([a0+336] + ([a0+348] << 0x2)) +0x4e88, including `lw` at 0x4b74, `lw` at 0x4bb4, `lw` at 0x4be4.
  2 such `sw` accesses store 4 bytes to ([a0+336] + ([a0+348] << 0x2)) +0x4e88, including `sw` at 0x4b7c, `sw` at 0x4bc4.
  2 such `lbu` accesses load 1 byte from [a0+336] +0x4f12, including `lbu` at 0x4c28, `lbu` at 0x4c58.
  2 such `lw` accesses load 4 bytes from [a0+336] +0x4e84, including `lw` at 0x4c64, `lw` at 0x4ca0.
  2 such `sw` accesses store 4 bytes to [a0+336] +0x4e84, including `sw` at 0x4c78, `sw` at 0x4cb0.
  The `jal` at 0x4ab8 calls pciio_pio_write32 with a0=?, a1=[[a0+336]+344]+128, a2=?, a3=?, a4=[a0+348].
  The `jal` at 0x4af4 calls pciio_pio_write32 with a0=?, a1=([(sym(.rodata) + ([a0+348] << 0x2))] + [[a0+336]+344]), a2=[[a0+336]+344], a3=?.
  The `jal` at 0x4b58 calls pciio_pio_write32 with a0=[([a0+336] + ([a0+348] << 0x2))+20120], a1=[[a0+336]+344]+164, a2=([a0+336] + ([a0+348] << 0x2)), a3=(a3 << 0x10).
  The `jal` at 0x4be0 calls pciio_pio_write32 with a0=[([a0+336] + ([a0+348] << 0x2))+20104], a1=[[a0+336]+344]+160, a2=([a0+336] + ([a0+348] << 0x2)), a3=?, a5=([a0+336] + ([a0+348] << 0x2)), a6=(a3 + a3).
  The `jal` at 0x4c0c calls pciio_pio_write32 with a0=?, a1=[[a0+336]+344]+128, a2=?, a3=?.
  The `jal` at 0x4c74 calls rad_vl_write_MUX_SEL with a0=[a0+336], a1=?, a2=-0x2001, a3=one of 0x0, 0x1, a4=[a0+348], a5=[[a0+336]+20242]:1, a6=0x1, a7=[[a0+336]+338]:2.
  The `jal` at 0x4c7c calls us_delay with a0=0xfa, a1=?, a2=?, a3=?.
  The `jal` at 0x4c90 calls rad_vl_set_clockgen with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0x7, a3=a2 at entry (arg2).
  The `jal` at 0x4cac calls rad_vl_write_MUX_SEL with a0=[a0+336], a1=([[a0+336]+20100] | 0x2000), a2=?, a3=[[a0+336]+338]:2, a4=[[a0+336]+20242]:1.
  The `bltz` branch at 0x4a24 targets 0x4c30, is taken when at(=[a0+340]) < 0 (signed), and falls through when at(=[a0+340]) >= 0 (signed).
  The `beq` branch at 0x4a2c targets 0x4a3c, is taken when a1 == 0, and falls through when a1 != 0.
  The `beq` branch at 0x4a48 targets 0x4c30, is taken when a4(=[a0+352]) == 0, and falls through when a4(=[a0+352]) != 0.
  The `bne` branch at 0x4a74 targets 0x4c30, is taken when (a5(=[([a0+336] + ([a0+348] << 0x2))+20188]) & a7(?)) != 0, and falls through when (a5(=[([a0+336] + ([a0+348] << 0x2))+20188]) & a7(?)) == 0.
  The `beq` branch at 0x4a8c targets 0x4c50, is taken when a7(=[[a0+336]+338]:2) == a1(=0x7), and falls through when a7(=[[a0+336]+338]:2) != a1(=0x7).
  The `beq` branch at 0x4ac4 targets 0x4afc, is taken when a2(=one of 0x0, 0x1) == 0, and falls through when a2(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x4b14 targets 0x4c8c, is taken when a0(=[[a0+336]+338]:2) == a2(=0x7), and falls through when a0(=[[a0+336]+338]:2) != a2(=0x7).
  The `beq` branch at 0x4b1c targets 0x4c90, is taken when a0(=[[a0+336]+338]:2) == a1(=0xd), and falls through when a0(=[[a0+336]+338]:2) != a1(=0xd).
  The `bne` branch at 0x4c18 targets 0x4c30, is taken when a3(=[[a0+336]+338]:2) != s3(=0x7), and falls through when a3(=[[a0+336]+338]:2) == s3(=0x7).
  The `bne` branch at 0x4c20 targets 0x4c34, is taken when s1(=a0) != a0(=[a0+336]+17880), and falls through when s1(=a0) == a0(=[a0+336]+17880).
  The `beq` branch at 0x4c2c targets 0x4ca0, is taken when a4(=[[a0+336]+20242]:1) == 0, and falls through when a4(=[[a0+336]+20242]:1) != 0.
  The `bne` branch at 0x4c50 targets 0x4a94, is taken when s1(=a0) != a0(=[a0+336]+17880), and falls through when s1(=a0) == a0(=[a0+336]+17880).
  The `bnel` branch at 0x4c5c targets 0x4a98, is taken when a5(=[[a0+336]+20242]:1) != 0, and falls through when a5(=[[a0+336]+20242]:1) == 0; its branch-likely delay slot `lw a2,20048(s0)` at 0x4c60 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x4c84 targets 0x4a94 and is always taken.
  The `beq` branch at 0x4c98 targets 0x4b28 and is always taken.
  The `beq` branch at 0x4cb4 targets 0x4c34 and is always taken.
  The return at 0x4c48 has v0 = one of ret(pciio_pio_write32), ?, ret(rad_vl_write_MUX_SEL).

- `rad_get_hw_mscust` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0x4cbc (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0x4cbc-0x4d18 (92 bytes).
  It occupies 92 bytes.
  The `ld` at 0x4cbc loads 8 bytes from a0 (arg0 at entry) +0x218.
  The `lw` at 0x4cc0 loads 4 bytes from a0 (arg0 at entry) +0x194.
  The `lw` at 0x4cc4 loads 4 bytes from a0 (arg0 at entry) +0x1d0.
  The `sd` at 0x4ccc stores 8 bytes to a1 (arg1 at entry) +0x0.
  The `ld` at 0x4cd0 loads 8 bytes from a0 (arg0 at entry) +0x120.
  The `ld` at 0x4cd4 loads 8 bytes from [a0+464] +0x4eb8.
  The `sd` at 0x4d14 stores 8 bytes to a2 (arg2 at entry) +0x0.
  The return at 0x4d10 has v0 = ?.

- `rad_start_clockgen` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0x4d18 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0x4d18-0x4d4c (52 bytes).
  It occupies 52 bytes.
  The `lw` at 0x4d18 loads 4 bytes from a0 (arg0 at entry) +0x160.
  The `lw` at 0x4d24 loads 4 bytes from a0 (arg0 at entry) +0x150.
  The `lw` at 0x4d28 loads 4 bytes from a0 (arg0 at entry) +0x15c.
  The `lw` at 0x4d30 loads 4 bytes from [a0+336] +0x4e50.
  The `sw` at 0x4d40 stores 4 bytes to [a0+336] +0x4e50.
  The `beq` branch at 0x4d20 targets 0x4d44, is taken when at(=[a0+352]) == 0, and falls through when at(=[a0+352]) != 0.
  The return at 0x4d44 has v0 = ?.

- `rad_shutdown` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0x4d4c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0x4d4c-0x4d68 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x4d54 calls kdsp_idbg_rad_delfuncs with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x4d60 has v0 = ret(kdsp_idbg_rad_delfuncs).

- `rad_halt_intr_ops` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0x4d68 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0x4d68-0x4d90 (40 bytes).
  It occupies 40 bytes.
  The `sw` at 0x4d80 stores 4 bytes to a0 (arg0 at entry) +0x4ed8.
  The `jal` at 0x4d74 calls rad_stop_status_dma with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x4d88 has v0 = ret(rad_stop_status_dma).

- `rad_one_shot_status` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0x4d90 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0x4d90-0x4e8c (252 bytes).
  It occupies 252 bytes.
  3 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x7c, including `lw` at 0x4da8, `lw` at 0x4e1c, `lw` at 0x4e60.
  The `sw` at 0x4dc4 stores 4 bytes to a1 (arg1 at entry) +0x7c.
  4 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x158, including `lw` at 0x4dc8, `lw` at 0x4ddc, `lw` at 0x4dec.
  The `jal` at 0x4dc0 calls Mem_to_PCI_DMA with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0x1000, a3=a3 at entry (arg3).
  The `jal` at 0x4dd4 calls pciio_pio_write32 with a0=-0x4, a1=[a0+344]+1284, a2=?, a3=?.
  The `jal` at 0x4de4 calls pciio_pio_write32 with a0=ret(Mem_to_PCI_DMA), a1=[a0+344]+1280, a2=?, a3=?.
  The `jal` at 0x4df8 calls pciio_pio_write32 with a0=0x0, a1=[a0+344]+1320, a2=?, a3=?.
  The `jal` at 0x4e0c calls pciio_pio_write32 with a0=0x40001, a1=[a0+344]+92, a2=?, a3=?.
  The `jal` at 0x4e14 calls us_delay with a0=0x5, a1=?, a2=?, a3=?.
  The `jal` at 0x4e58 calls us_delay with a0=0x5, a1=?, a2=?, a3=?.
  The `jal` at 0x4e7c calls debug with a0=sym(.rodata)+1392, a1=?, a2=?, a3=?.
  The `beq` branch at 0x4e28 targets 0x4e48, is taken when (v0(=0xffffffff80000000) & a1(=[a1+124])) == 0, and falls through when (v0(=0xffffffff80000000) & a1(=[a1+124])) != 0.
  The `beq` branch at 0x4e48 targets 0x4e58 and is always taken.
  The `blez` branch at 0x4e50 targets 0x4e74, is taken when s0(?) <= 0 (signed), and falls through when s0(?) > 0 (signed).
  The `beq` branch at 0x4e6c targets 0x4e50, is taken when (v0(=0xffffffff80000000) & a2(=[a1+124])) == 0, and falls through when (v0(=0xffffffff80000000) & a2(=[a1+124])) != 0.
  The `bne` branch at 0x4e74 targets 0x4e30, is taken when s0(?) != 0, and falls through when s0(?) == 0.
  The `beq` branch at 0x4e84 targets 0x4e34 and is always taken.
  The return at 0x4e40 has v0 = one of 0x0, 0x1.

- `rad_attach` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0x4e8c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0x4e8c-0x4fb8 (300 bytes).
  It occupies 300 bytes.
  The `jal` at 0x4eac calls pciio_piotrans_addr with a0=a0 at entry (arg0), a1=0x0, a2=0x7, a3=0x0, a4=0x20, a5=0x0.
  The `jal` at 0x4ecc calls pciio_piotrans_addr with a0=a0 at entry (arg0), a1=0x0, a2=0x8, a3=0x0, a4=0x2000, a5=0x0.
  The `jal` at 0x4ee0 calls pciio_config_get with a0=a0 at entry (arg0), a1=0x8, a2=0x4, a3=?.
  The `jal` at 0x4f04 calls pciio_priority_set with a0=a0 at entry (arg0), a1=0x1, a2=?, a3=?.
  The `jal` at 0x4f10 calls pciio_pio_read32 with a0=0xffffffffbf080008, a1=?, a2=?, a3=?.
  The `jal` at 0x4f2c calls rad_create_subsys with a0=ret(pciio_piotrans_addr), a1=ret(pciio_piotrans_addr), a2=a0 at entry (arg0), a3=?.
  The `jal` at 0x4f48 calls pciio_priority_set with a0=a0 at entry (arg0), a1=0x2, a2=?, a3=?.
  The `jal` at 0x4f64 calls cmn_err with a0=0x4, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x4f7c calls pciio_pio_write32 with a0=?, a1=0xffffffffbf080008, a2=?, a3=?.
  The `jal` at 0x4f88 calls pciio_pio_read32 with a0=0xffffffffbf080008, a1=?, a2=?, a3=?.
  The `jal` at 0x4fa8 calls cmn_err with a0=0x4, a1=sym(.rodata), a2=?, a3=?.
  The `beq` branch at 0x4ef8 targets 0x4f48, is taken when at(?) == v0(=0xc), and falls through when at(?) != v0(=0xc).
  The `bne` branch at 0x4f1c targets 0x4f58, is taken when (v0(=ret(pciio_pio_read32)) & 0x800) != 0, and falls through when (v0(=ret(pciio_pio_read32)) & 0x800) == 0.
  The `beq` branch at 0x4f50 targets 0x4f10 and is always taken.
  The `beq` branch at 0x4f94 targets 0x4f28, is taken when (v0(=ret(pciio_pio_read32)) & 0x800) == 0, and falls through when (v0(=ret(pciio_pio_read32)) & 0x800) != 0.
  The `beq` branch at 0x4fb0 targets 0x4f38 and is always taken.
  The return at 0x4f40 has v0 = 0x0.

- `rad_detach` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0x4fb8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0x4fb8-0x4fc0 (8 bytes).
  It occupies 8 bytes.
  The return at 0x4fb8 has v0 = 0x0.

- `rad_error` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0x4fc0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0x4fc0-0x4fc8 (8 bytes).
  It occupies 8 bytes.
  The return at 0x4fc0 has v0 = 0x0.

- `rad_error_handler` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0x4fc8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0x4fc8-0x5074 (172 bytes).
  It occupies 172 bytes.
  4 such `lw` accesses load 4 bytes from a3 (arg3 at entry) +0x1c, including `lw` at 0x502c, `lw` at 0x5030, `lw` at 0x5068.
  The `lw` at 0x503c loads 4 bytes from a0 (arg0 at entry) +0x4f2c.
  The `jal` at 0x5040 calls cmn_err with a0=0x4, a1=sym(.rodata), a2=[a0+20268], a3=sym(.rodata), a4=a1 at entry (arg1), a5=a2 at entry (arg2), a6=[a3+28], a7=0x6.
  The `beq` branch at 0x4ff0 targets 0x5030, is taken when a1 == at(=0x5), and falls through when a1 != at(=0x5).
  The `beq` branch at 0x4ffc targets 0x5058, is taken when a1 == a7(=0x6), and falls through when a1 != a7(=0x6).
  The `beq` branch at 0x5014 targets 0x5064, is taken when a4(=a1) == t8(=0x9), and falls through when a4(=a1) != t8(=0x9).
  The `beq` branch at 0x501c targets 0x506c, is taken when a4(=a1) == a0(=0xa), and falls through when a4(=a1) != a0(=0xa).
  The `beq` branch at 0x5028 targets 0x5034 and is always taken.
  The `beq` branch at 0x505c targets 0x5030 and is always taken.
  The `beq` branch at 0x5064 targets 0x5034 and is always taken.
  The `beq` branch at 0x506c targets 0x5034 and is always taken.
  The return at 0x5050 has v0 = 0x9.

- `rad_init` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0x5074 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0x5074-0x50a8 (52 bytes).
  It occupies 52 bytes.
  The `jal` at 0x508c calls pciio_driver_register with a0=0x10a9, a1=0x5, a2=sym(.rodata)+80, a3=0x0.
  The `jal` at 0x5094 calls kdsp_idbg_rad_addfuncs with a0=?, a1=?, a2=?, a3=?.
  The return at 0x50a0 has v0 = ret(kdsp_idbg_rad_addfuncs).

- `rad_halt` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0x50a8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0x50a8-0x519c (244 bytes).
  It occupies 244 bytes.
  4 such `sw` accesses store 4 bytes to ?, including `sw` at 0x50cc, `sw` at 0x5128, `sw` at 0x5150.
  6 such `lw` accesses load 4 bytes from ?, including `lw` at 0x50e0, `lw` at 0x5114, `lw` at 0x5118.
  3 such `lh` accesses load 2 bytes from ?, including `lh` at 0x5104, `lh` at 0x512c, `lh` at 0x5198.
  The `jal` at 0x50d0 calls pciio_pio_write32 with a0=0x0, a1=?, a2=?, a3=?.
  The `jal` at 0x50d8 calls rad_stop_status_dma with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x50f4 calls strncmp with a0=?, a1=sym(.rodata)+256, a2=0x3, a3=?.
  The `jal` at 0x5124 calls pciio_pio_write32 with a0=?, a1=?, a2=0x7, a3=?.
  The `jal` at 0x5154 calls pciio_pio_write32 with a0=0x2, a1=?, a2=0x2, a3=0xc.
  The `jal` at 0x5168 calls us_delay with a0=0xc8, a1=?, a2=?, a3=?.
  The `jal` at 0x518c calls rad_vl_write_MUX_SEL with a0=?, a1=?, a2=?, a3=0xc.
  The `beq` branch at 0x50b8 targets 0x5164, is taken when at(=[sym(kdsp_sstab)]) == 0, and falls through when at(=[sym(kdsp_sstab)]) != 0.
  The `beq` branch at 0x50c0 targets 0x50ec and is always taken.
  The `beq` branch at 0x50e4 targets 0x5164, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `bne` branch at 0x50fc targets 0x50e0, is taken when v0(=ret(strncmp)) != 0, and falls through when v0(=ret(strncmp)) == 0.
  The `beq` branch at 0x510c targets 0x5134, is taken when a0(?) == a2(=0xd), and falls through when a0(?) != a2(=0xd).
  The `beq` branch at 0x5134 targets 0x517c, is taken when a0(?) == a2(=0x7), and falls through when a0(?) != a2(=0x7).
  The `bne` branch at 0x513c targets 0x50d8, is taken when a0(?) != a3(=0xc), and falls through when a0(?) == a3(=0xc).
  The `beq` branch at 0x515c targets 0x50c8 and is always taken.
  The `beq` branch at 0x5194 targets 0x5138 and is always taken.
  The return at 0x5174 has v0 = ret(us_delay).

- `Mem_to_PCI_DMA` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0x519c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0x519c-0x51e0 (68 bytes).
  It occupies 68 bytes.
  The `lw` at 0x51c4 loads 4 bytes from a0 (arg0 at entry) +0x4f2c.
  The `jal` at 0x51b0 calls kvtophys with a0=a1 at entry (arg1), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x51c8 calls pciio_dmatrans_addr with a0=[a0+20268], a1=0x0, a2=ret(kvtophys), a3=a2 at entry (arg2), a4=0x50.
  The return at 0x51d8 has v0 = ret(pciio_dmatrans_addr).

- `rad_initial_val` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0x51e0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0x51e0-0x5458 (632 bytes).
  It occupies 632 bytes.
  The `lw` at 0x51e0 loads 4 bytes from a1 (arg1 at entry) +0x0.
  The `lw` at 0x5208 loads 4 bytes from a0 (arg0 at entry) +0x90.
  The `lw` at 0x5214 loads 4 bytes from (sym(.rodata)+1680 + ([a1]+0xffffffffeffffffe << 0x2)) +0x0.
  Calls (unknown callee) via register with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a4=[a0+144], a5=(sym(.rodata)+1680 + ([a1]+0xffffffffeffffffe << 0x2)), a6=([a1]+0xffffffffeffffffe << 0x2) (`jr` at 0x5218).
  The `beq` branch at 0x520c targets 0x5260, is taken when a6(=[a1]+0xffffffffeffffffe) >= 0x34 (unsigned), and falls through when a6(=[a1]+0xffffffffeffffffe) < 0x34 (unsigned).
  The return at 0x5260 has v0 = 0x0.
  The instructions from 0x5220 to 0x525c are not reached by any path from the entry, and their branches are not listed.
  The instructions from 0x5268 to 0x5454 are not reached by any path from the entry, and their branches are not listed.
  The indirect jump at 0x5218 uses a jump table whose successors are unresolved.

- `rad_set_device_params` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0x5458 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0x5458-0x5810 (952 bytes).
  It occupies 952 bytes.
  The `lw` at 0x545c loads 4 bytes from a1 (arg1 at entry) +0x0.
  The `lw` at 0x5490 loads 4 bytes from a0 (arg0 at entry) +0x1d0.
  The `lw` at 0x549c loads 4 bytes from (sym(.rodata)+1888 + ([a1]+0xffffffffeffffffe << 0x2)) +0x0.
  Calls (unknown callee) via register with a0=[(sym(.rodata)+1888 + ([a1]+0xffffffffeffffffe << 0x2))], a1=?, a2=a2 at entry (arg2), a3=a3 at entry (arg3), a5=[a1] (`jr` at 0x54a0).
  The `beq` branch at 0x5494 targets 0x54a8, is taken when v1(=[a1]+0xffffffffeffffffe) >= 0x34 (unsigned), and falls through when v1(=[a1]+0xffffffffeffffffe) < 0x34 (unsigned).
  The return at 0x54b8 has v0 = 0x0.
  The instructions from 0x54c0 to 0x580c are not reached by any path from the entry, and their branches are not listed.
  The indirect jump at 0x54a0 uses a jump table whose successors are unresolved.

- `rad_commit_device_params` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0x5810 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0x5810-0x5818 (8 bytes).
  It occupies 8 bytes.
  The return at 0x5810 has v0 = ?.

- `rad_calculate_rate_frac` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0x5818 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0x5818-0x598c (372 bytes).
  It occupies 372 bytes.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x110, including `ld` at 0x5818, `ld` at 0x5944.
  The `lw` at 0x5824 loads 4 bytes from a0 (arg0 at entry) +0x158.
  The `lw` at 0x5828 loads 4 bytes from a0 (arg0 at entry) +0x150.
  2 such `ld` accesses load 8 bytes from [a0+344] +0x108, including `ld` at 0x5844, `ld` at 0x585c.
  2 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x110, including `sd` at 0x5854, `sd` at 0x58a0.
  The `ld` at 0x58b0 loads 8 bytes from [a0+336] +0x428.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x174, including `lw` at 0x58c8, `lw` at 0x5964.
  3 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x120, including `sw` at 0x58cc, `sw` at 0x5904, `sw` at 0x5968.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x128, including `sw` at 0x58dc, `sw` at 0x5974.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x158, including `sw` at 0x58e8, `sw` at 0x5980.
  The `lw` at 0x58ec loads 4 bytes from a0 (arg0 at entry) +0x128.
  The `lw` at 0x58f0 loads 4 bytes from a0 (arg0 at entry) +0x120.
  The `ld` at 0x5938 loads 8 bytes from [a0+336] +0x300.
  The `jal` at 0x586c calls kdsp_reduce_frac with a0=?, a1=[[a0+344]+264]:8, a2=a0+288, a3=a0+296, a4=0xffff.
  The `jal` at 0x58b4 calls kdsp_reduce_frac with a0=?, a1=[[a0+336]+1064]:8, a2=sp-48, a3=sp-44, a4=0xffff.
  The `jal` at 0x5920 calls kdsp_reduce_frac with a0=?, a1=[a0+296], a2=a0+288, a3=a0+296, a4=0xffff, a6=[a0+272]:8.
  The `jal` at 0x5940 calls kdsp_reduce_frac with a0=[a0+272]:8, a1=[[a0+336]+768]:8, a2=sp-40, a3=sp-36, a4=0xffff.
  The `beq` branch at 0x5834 targets 0x5888, is taken when a3(=[a0+344]) == 0, and falls through when a3(=[a0+344]) != 0.
  The `beq` branch at 0x583c targets 0x58ec, is taken when a6(=[a0+272]:8) == 0, and falls through when a6(=[a0+272]:8) != 0.
  The `beq` branch at 0x584c targets 0x5860, is taken when a0(=[[a0+344]+264]:8) >= a6(=[a0+272]:8) (signed), and falls through when a0(=[[a0+344]+264]:8) < a6(=[a0+272]:8) (signed).
  The `beq` branch at 0x5894 targets 0x58a4, is taken when a0(=0xbb8000000000) >= a6(=[a0+272]:8) (signed), and falls through when a0(=0xbb8000000000) < a6(=[a0+272]:8) (signed).
  The `bne` branch at 0x58c0 targets 0x5930, is taken when s0(=a0) != a1(=[a0+336]+17880), and falls through when s0(=a0) == a1(=[a0+336]+17880).
  The `beq` branch at 0x58d8 targets 0x58e4, is taken when a3(=[a0+372]) == 0, and falls through when a3(=[a0+372]) != 0.
  The `beq` branch at 0x58e4 targets 0x5874 and is always taken.
  The `beq` branch at 0x58f8 targets 0x5908, is taken when a1(=[a0+296]) >= a0(=[a0+288]) (signed), and falls through when a1(=[a0+296]) < a0(=[a0+288]) (signed).
  The `bne` branch at 0x590c targets 0x5918, is taken when a4(=0xffff) < a0(?) (signed), and falls through when a4(=0xffff) >= a0(?) (signed).
  The `beq` branch at 0x5914 targets 0x5874, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0x5928 targets 0x5878 and is always taken.
  The `beq` branch at 0x5948 targets 0x58c8, is taken when v0(=ret(kdsp_reduce_frac)) == 0, and falls through when v0(=ret(kdsp_reduce_frac)) != 0.
  The `beq` branch at 0x595c targets 0x58c8, is taken when a1(?) >= a0(?) (signed), and falls through when a1(?) < a0(?) (signed).
  The `beq` branch at 0x5970 targets 0x5984, is taken when t0(=[a0+372]) == 0, and falls through when t0(=[a0+372]) != 0.
  The `beq` branch at 0x597c targets 0x5874 and is always taken.
  The `beq` branch at 0x5984 targets 0x597c and is always taken.
  The return at 0x5880 has v0 = one of ?, ret(kdsp_reduce_frac).

- `rad_cg_update_dev` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0x598c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0x598c-0x5a8c (256 bytes).
  It occupies 256 bytes.
  The `lw` at 0x5998 loads 4 bytes from a0 (arg0 at entry) +0x144.
  The `lw` at 0x599c loads 4 bytes from a0 (arg0 at entry) +0x1d0.
  The `lw` at 0x59a0 loads 4 bytes from [a0+324] +0x128.
  The `lw` at 0x59b8 loads 4 bytes from [a0+324] +0x15c.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x208, including `lw` at 0x59bc, `lw` at 0x59dc.
  2 such `lw` accesses load 4 bytes from [a0+520] +0x0, including `lw` at 0x59c4, `lw` at 0x59f0.
  The `sw` at 0x59d8 stores 4 bytes to [a0+520] +0x0.
  The `lw` at 0x59e0 loads 4 bytes from a0 (arg0 at entry) +0x204.
  The `lw` at 0x59e4 loads 4 bytes from [a0+464] +0x158.
  The `ld` at 0x5a14 loads 8 bytes from [a0+324] +0x110.
  The `lw` at 0x5a20 loads 4 bytes from [a0+464] +0x15c.
  The `lbu` at 0x5a24 loads 1 byte from [a0+464] +0x4f24.
  The `sb` at 0x5a30 stores 1 byte to [a0+464] +0x4f24.
  The `sb` at 0x5a38 stores 1 byte to [a0+464] +0x4f22.
  The `sb` at 0x5a44 stores 1 byte to [a0+464] +0x4f20.
  The `lw` at 0x5a50 loads 4 bytes from [a0+324] +0x120.
  The `lw` at 0x5a5c loads 4 bytes from [a0+324] +0x158.
  The `lw` at 0x5a60 loads 4 bytes from [[a0+324]+344] +0x11c.
  The `jal` at 0x59ec calls pciio_pio_write32 with a0=[[a0+520]], a1=([[a0+464]+344] + [a0+516]), a2=[a0+516], a3=?, a4=[a0+520], a6=0x1fffffff.
  The `jal` at 0x5a18 calls kdsp_set_aes_rate_bits with a0=[a0+464]+14488, a1=[[a0+324]+272]:8, a2=?, a3=?, a7=[a0+464]+3936.
  The `jal` at 0x5a40 calls rad_pio_writeback_subcode_tx with a0=[a0+464]+8352, a1=?, a2=?, a3=?.
  The `beq` branch at 0x59b4 targets 0x5a50, is taken when at(=[[a0+324]+296]) == a2(=0x1), and falls through when at(=[[a0+324]+296]) != a2(=0x1).
  The `beq` branch at 0x59f8 targets 0x5a14, is taken when s1(=a0) == a7(=[a0+464]+3936), and falls through when s1(=a0) != a7(=[a0+464]+3936).
  The `bne` branch at 0x5a2c targets 0x59fc, is taken when t1(=[[a0+464]+348]) != 0, and falls through when t1(=[[a0+464]+348]) == 0.
  The `beq` branch at 0x5a48 targets 0x5a00 and is always taken.
  The `bne` branch at 0x5a54 targets 0x59bc, is taken when t2(=[[a0+324]+288]) != a2(=0x1), and falls through when t2(=[[a0+324]+288]) == a2(=0x1).
  The `beq` branch at 0x5a6c targets 0x5a84, is taken when a2(?) == t3(=0x2), and falls through when a2(?) != t3(=0x2).
  The `bne` branch at 0x5a74 targets 0x59bc, is taken when a2(?) != a0(=0x3), and falls through when a2(?) == a0(=0x3).
  The `beq` branch at 0x5a7c targets 0x59bc and is always taken.
  The `beq` branch at 0x5a84 targets 0x59bc and is always taken.
  The return at 0x5a0c has v0 = one of ret(pciio_pio_write32), ?, ret(rad_pio_writeback_subcode_tx).

- `rad_get_cg_id` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0x5a8c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0x5a8c-0x5be4 (344 bytes).
  It occupies 344 bytes.
  The `lw` at 0x5a8c loads 4 bytes from a0 (arg0 at entry) +0x150.
  The `lh` at 0x5aa0 loads 2 bytes from [a0+336] +0x152.
  The `lw` at 0x5ac0 loads 4 bytes from a0 (arg0 at entry) +0x15c.
  The `ll` at 0x5adc loads 4 bytes from ([a0+336] + ([a0+348] << 0x2)) +0x4edc.
  The `sc` at 0x5ae4 stores 4 bytes to ([a0+336] + ([a0+348] << 0x2)) +0x4edc.
  The `lw` at 0x5af0 loads 4 bytes from a0 (arg0 at entry) +0x158.
  The `lw` at 0x5b08 loads 4 bytes from [a0+336] +0x4edc.
  5 such `lw` accesses load 4 bytes from ?, including `lw` at 0x5b20, `lw` at 0x5b9c, `lw` at 0x5bb0.
  The `ll` at 0x5b34 loads 4 bytes from ?.
  The `sc` at 0x5b3c stores 4 bytes to ?.
  The `sw` at 0x5b48 stores 4 bytes to a0 (arg0 at entry) +0x15c.
  The `lw` at 0x5b5c loads 4 bytes from a0 (arg0 at entry) +0x128.
  The `lw` at 0x5b68 loads 4 bytes from a0 (arg0 at entry) +0x120.
  The `beq` branch at 0x5ab4 targets 0x5b4c, is taken when a5(=[[a0+336]+338]:2) == a6(=0xd), and falls through when a5(=[[a0+336]+338]:2) != a6(=0xd).
  The `beql` branch at 0x5ae8 targets 0x5adc, is taken when (t3(=[([a0+336] + ([a0+348] << 0x2))+20188]) & t9(?)) == 0, and falls through when (t3(=[([a0+336] + ([a0+348] << 0x2))+20188]) & t9(?)) != 0; its branch-likely delay slot `nop` at 0x5aec runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x5af4 targets 0x5b54, is taken when a5(=[a0+344]) == t2(=[a0+336]+1984), and falls through when a5(=[a0+344]) != t2(=[a0+336]+1984).
  The `beq` branch at 0x5afc targets 0x5b54, is taken when a5(=[a0+344]) == t0(=[a0+336]+1688), and falls through when a5(=[a0+344]) != t0(=[a0+336]+1688).
  The `beq` branch at 0x5b0c targets 0x5b28, is taken when t9(?) == 0, and falls through when t9(?) != 0.
  The `bnel` branch at 0x5b1c targets 0x5b0c, is taken when a3(?) < 0x4 (signed), and falls through when a3(?) >= 0x4 (signed); its branch-likely delay slot `lw t9,20188(a2)` at 0x5b20 runs only when taken and is annulled on fall-through.
  The `beql` branch at 0x5b40 targets 0x5b34, is taken when a1(?) == 0, and falls through when a1(?) != 0; its branch-likely delay slot `nop` at 0x5b44 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x5b54 targets 0x5b04, is taken when a0 == a7(=[a0+336]+17880), and falls through when a0 != a7(=[a0+336]+17880).
  The `bne` branch at 0x5b60 targets 0x5b04, is taken when a1(=[a0+296]) != t1(=0x1), and falls through when a1(=[a0+296]) == t1(=0x1).
  The `bne` branch at 0x5b6c targets 0x5b00, is taken when a2(=[a0+288]) != t1(=0x1), and falls through when a2(=[a0+288]) == t1(=0x1).
  The `beq` branch at 0x5b78 targets 0x5b94 and is always taken.
  The `beq` branch at 0x5b8c targets 0x5bd0, is taken when a3(?) >= 0x6 (signed), and falls through when a3(?) < 0x6 (signed).
  The `beq` branch at 0x5b94 targets 0x5b80, is taken when a7(?) == a0, and falls through when a7(?) != a0.
  The `bne` branch at 0x5ba0 targets 0x5b80, is taken when t2(?) != a5(=[a0+344]), and falls through when t2(?) == a5(=[a0+344]).
  The `beq` branch at 0x5ba8 targets 0x5b80, is taken when a3(?) == t1(=0x1), and falls through when a3(?) != t1(=0x1).
  The `bne` branch at 0x5bb4 targets 0x5b80, is taken when t3(?) != t1(=0x1), and falls through when t3(?) == t1(=0x1).
  The `bnel` branch at 0x5bc0 targets 0x5b84, is taken when t8(?) != t1(=0x1), and falls through when t8(?) == t1(=0x1); its branch-likely delay slot `addiu a3,a3,1` at 0x5bc4 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x5bd4 targets 0x5b04, is taken when a3(?) == at(=0x6), and falls through when a3(?) != at(=0x6).
  The `beq` branch at 0x5bdc targets 0x5b28 and is always taken.
  The return at 0x5b4c has v0 = ?.

- `rad_commit_clockgen_params` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0x5be4 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0x5be4-0x5cf4 (272 bytes).
  It occupies 272 bytes.
  The `lw` at 0x5be4 loads 4 bytes from a0 (arg0 at entry) +0x178.
  The `sw` at 0x5c10 stores 4 bytes to a0 (arg0 at entry) +0x158.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x158, including `lw` at 0x5c24, `lw` at 0x5c74, `lw` at 0x5cc0.
  The `lw` at 0x5c30 loads 4 bytes from a0 (arg0 at entry) +0x134.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x120, including `lw` at 0x5c48, `lw` at 0x5c5c.
  The `lw` at 0x5c4c loads 4 bytes from a0 (arg0 at entry) +0x108.
  The `lw` at 0x5c68 loads 4 bytes from a0 (arg0 at entry) +0x128.
  The `lw` at 0x5c78 loads 4 bytes from [a0+344] +0x120.
  The `jal` at 0x5c14 calls rad_calculate_rate_frac with a0=a0 at entry (arg0), a1=[a0+376], a2=0x20000016, a3=a3 at entry (arg3).
  The `jal` at 0x5c1c calls rad_get_cg_id with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x5c3c calls kdsp_select_mclk with a0=a0 at entry (arg0), a1=[a0+344], a2=?, a3=[a0+308].
  The `jalr` at 0x5c54 calls (unknown callee) with a0=a0 at entry (arg0), a1=0x0, a2=?, a3=?, a4=[a0+264].
  The `jal` at 0x5cb8 calls kdsp_reduce_frac with a0=?, a1=[a0+288], a2=sp-32, a3=sp-28, a4=0xffff, a7=[[a0+344]+288].
  The `jal` at 0x5cd4 calls rad_set_clockgen with a0=a0 at entry (arg0), a1=[a0+344], a2=?, a3=?, a5=0x0.
  The `jal` at 0x5cdc calls kdsp_update_cg_users with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `beq` branch at 0x5c00 targets 0x5c10, is taken when a1(=[a0+376]) == at(=0x2000000a), and falls through when a1(=[a0+376]) != at(=0x2000000a).
  The `bne` branch at 0x5c08 targets 0x5c14, is taken when a1(=[a0+376]) != a2(=0x20000016), and falls through when a1(=[a0+376]) == a2(=0x20000016).
  The `beq` branch at 0x5c28 targets 0x5c4c, is taken when a1(=[a0+344]) == 0, and falls through when a1(=[a0+344]) != 0.
  The `beq` branch at 0x5c34 targets 0x5c4c, is taken when a3(=[a0+308]) == a1(=[a0+344]), and falls through when a3(=[a0+308]) != a1(=[a0+344]).
  The `beq` branch at 0x5c44 targets 0x5c60 and is always taken.
  The `beq` branch at 0x5c60 targets 0x5ce8, is taken when a1(=[a0+288]) == 0, and falls through when a1(=[a0+288]) != 0.
  The `beq` branch at 0x5c6c targets 0x5ce8, is taken when a6(=[a0+296]) == 0, and falls through when a6(=[a0+296]) != 0.
  The return at 0x5cec has v0 = one of ?, ret(kdsp_update_cg_users).

- `rad_update_aes_mclk` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0x5cf4 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0x5cf4-0x5d14 (32 bytes).
  It occupies 32 bytes.
  The `lw` at 0x5cf4 loads 4 bytes from a0 (arg0 at entry) +0x90.
  The `jal` at 0x5d00 calls rad_process_aesrx_subcode with a0=[a0+144], a1=0x1, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x5d0c has v0 = ret(rad_process_aesrx_subcode).

- `rad_process_aesrx_subcode` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0x5d14 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0x5d14-0x5dd4 (192 bytes).
  It occupies 192 bytes.
  The `lw` at 0x5d14 loads 4 bytes from a0 (arg0 at entry) +0x1e8.
  The `ld` at 0x5d20 loads 8 bytes from a0 (arg0 at entry) +0x4f08.
  The `ld` at 0x5d4c loads 8 bytes from table(sym(.data)+25352) +0x0.
  2 such `lhu` accesses load 2 bytes from a0 (arg0 at entry) +0x4f10, including `lhu` at 0x5d58, `lhu` at 0x5db4.
  2 such `sh` accesses store 2 bytes to a0 (arg0 at entry) +0x4f10, including `sh` at 0x5d68, `sh` at 0x5d94.
  2 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x4f08, including `sd` at 0x5d6c, `sd` at 0x5da0.
  The `lbu` at 0x5d78 loads 1 byte from a0 (arg0 at entry) +0x684.
  2 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x684, including `sb` at 0x5d9c, `sb` at 0x5dbc.
  The `sd` at 0x5dc8 stores 8 bytes to a0 (arg0 at entry) +0x678.
  The `jal` at 0x5dc4 calls kdsp_update_mclk_users with a0=a0+1392, a1=?, a2=?, a3=?, a4=sym(.data)+25352.
  The `bltz` branch at 0x5d34 targets 0x5d88, is taken when a6(=([a0+488] << 0xc)) < 0 (signed), and falls through when a6(=([a0+488] << 0xc)) >= 0 (signed).
  The `bne` branch at 0x5d50 targets 0x5d94, is taken when v0(=[a0+20232]:8) != a3(=entry(sym(.data)+25352)), and falls through when v0(=[a0+20232]:8) == a3(=entry(sym(.data)+25352)).
  The `beq` branch at 0x5d60 targets 0x5d78, is taken when v1(=[a0+20240]:2) == 0, and falls through when v1(=[a0+20240]:2) != 0.
  The `beq` branch at 0x5d70 targets 0x5db8, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x5d88 targets 0x5dac, is taken when v0(=[a0+20232]:8) == 0, and falls through when v0(=[a0+20232]:8) != 0.
  The `beq` branch at 0x5da4 targets 0x5d7c and is always taken.
  The `beq` branch at 0x5db0 targets 0x5d5c and is always taken.
  The `beq` branch at 0x5dcc targets 0x5d78 and is always taken.
  The return at 0x5d80 has v0 = one of [a0+1668]:1, 0x1.

- `rad_prepare_aes_in_subcode` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0x5dd4 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0x5dd4-0x5ee8 (276 bytes).
  It occupies 276 bytes.
  5 such `lw` accesses load 4 bytes from ?, including `lw` at 0x5df4, `lw` at 0x5df8, `lw` at 0x5dfc.
  16 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x5e18, `lbu` at 0x5e1c, `lbu` at 0x5e20.
  4 such `sw` accesses store 4 bytes to ?, including `sw` at 0x5e5c, `sw` at 0x5e60, `sw` at 0x5eb8.
  The `bne` branch at 0x5ec0 targets 0x5e18, is taken when a5(?) < 0x6 (signed), and falls through when a5(?) >= 0x6 (signed).
  The `bne` branch at 0x5ed8 targets 0x5df4, is taken when t0(?) < 0x3 (signed), and falls through when t0(?) >= 0x3 (signed).
  The return at 0x5ee0 has v0 = ?.

- `rad_prepare_aes_out_subcode` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0x5ee8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0x5ee8-0x5fd8 (240 bytes).
  It occupies 240 bytes.
  3 such `lw` accesses load 4 bytes from ?, including `lw` at 0x5f04, `lw` at 0x5f08, `lw` at 0x5f20.
  16 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x5f24, `lbu` at 0x5f28, `lbu` at 0x5f2c.
  2 such `sw` accesses store 4 bytes to ?, including `sw` at 0x5f68, `sw` at 0x5fc4.
  The `bne` branch at 0x5f18 targets 0x5fc8, is taken when t0(?) != 0, and falls through when t0(?) == 0.
  The `bne` branch at 0x5fc0 targets 0x5f24, is taken when a1(?) < 0x6 (signed), and falls through when a1(?) >= 0x6 (signed).
  The `bne` branch at 0x5fc8 targets 0x5f00, is taken when t0(?) != 0, and falls through when t0(?) == 0.
  The return at 0x5fd0 has v0 = ?.

- `rad_prepare_adat_in_subcode` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0x5fd8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0x5fd8-0x6090 (184 bytes).
  It occupies 184 bytes.
  5 such `lw` accesses load 4 bytes from ?, including `lw` at 0x5ff0, `lw` at 0x5ff4, `lw` at 0x5ff8.
  9 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x6020, `lbu` at 0x6024, `lbu` at 0x602c.
  5 such `sb` accesses store 1 byte to ?, including `sb` at 0x6034, `sb` at 0x603c, `sb` at 0x605c.
  The `bne` branch at 0x606c targets 0x6020, is taken when a2(?) < 0x6 (signed), and falls through when a2(?) >= 0x6 (signed).
  The `bne` branch at 0x6080 targets 0x5ff0, is taken when a0(?) != 0, and falls through when a0(?) == 0.
  The return at 0x6088 has v0 = ?.

- `rad_prepare_adat_out_subcode` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0x6090 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0x6090-0x6138 (168 bytes).
  It occupies 168 bytes.
  3 such `lw` accesses load 4 bytes from ?, including `lw` at 0x60ac, `lw` at 0x60b0, `lw` at 0x60c0.
  8 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x60c4, `lbu` at 0x60c8, `lbu` at 0x60cc.
  The `sw` at 0x611c stores 4 bytes to ?.
  The `bne` branch at 0x60b8 targets 0x6120, is taken when t1(?) != 0, and falls through when t1(?) == 0.
  The `bne` branch at 0x6118 targets 0x610c, is taken when a2(?) < 0x6 (signed), and falls through when a2(?) >= 0x6 (signed).
  The `bne` branch at 0x6128 targets 0x60ac, is taken when a7(?) != 0, and falls through when a7(?) == 0.
  The return at 0x6130 has v0 = ?.

- `rad_write_aes_out_subcode` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0x6138 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0x6138-0x6338 (512 bytes).
  It occupies 512 bytes.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0x617c, `ld` at 0x6198.
  7 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x158, including `lw` at 0x6180, `lw` at 0x6194, `lw` at 0x61f4.
  3 such `ld` accesses load 8 bytes from a2 (arg2 at entry) +0x80, including `ld` at 0x61c4, `ld` at 0x61f0, `ld` at 0x620c.
  The `lw` at 0x61d4 loads 4 bytes from a0 (arg0 at entry) +0x3910.
  4 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x3910, including `sw` at 0x61ec, `sw` at 0x62f0, `sw` at 0x631c.
  2 such `ld` accesses load 8 bytes from a2 (arg2 at entry) +0x88, including `ld` at 0x6228, `ld` at 0x6244.
  The `ld` at 0x6264 loads 8 bytes from a2 (arg2 at entry) +0x28.
  The `lw` at 0x626c loads 4 bytes from a0 (arg0 at entry) +0x4e68.
  4 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x4e68, including `sw` at 0x6294, `sw` at 0x62ac, `sw` at 0x62fc.
  The `ld` at 0x6298 loads 8 bytes from a2 (arg2 at entry) +0x70.
  The `jal` at 0x618c calls pciio_pio_write32 with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x61a8 calls pciio_pio_write32 with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x6200 calls pciio_pio_write32 with a0=?, a1=([a0+344] + one of 0x1200, 0x1210), a2=?, a3=?.
  The `jal` at 0x621c calls pciio_pio_write32 with a0=?, a1=([a0+344] + one of 0x1204, 0x1214), a2=?, a3=?.
  The `jal` at 0x6238 calls pciio_pio_write32 with a0=?, a1=([a0+344] + one of 0x1208, 0x1218), a2=?, a3=?.
  The `jal` at 0x6254 calls pciio_pio_write32 with a0=?, a1=([a0+344] + one of 0x120c, 0x121c), a2=?, a3=?.
  The `jal` at 0x62cc calls pciio_pio_write32 with a0=?, a1=[a0+344]+84, a2=-0x9, a3=?, a4=0xff000000.
  The `bne` branch at 0x61bc targets 0x617c, is taken when s3(?) < 0x10 (signed), and falls through when s3(?) >= 0x10 (signed).
  The `beq` branch at 0x61d8 targets 0x62dc, is taken when a3(=[a2+128]:8) == 0, and falls through when a3(=[a2+128]:8) != 0.
  The `beq` branch at 0x61e0 targets 0x6308, is taken when s6(=a1) == a2(=0x1180), and falls through when s6(=a1) != a2(=0x1180).
  The `beq` branch at 0x6288 targets 0x6300, is taken when a4(=0xff000000) == a2(?), and falls through when a4(=0xff000000) != a2(?).
  The `beq` branch at 0x62a0 targets 0x62f4, is taken when a4(=0xff000000) == a5(?), and falls through when a4(=0xff000000) != a5(?).
  The `bne` branch at 0x62b0 targets 0x62c8, is taken when a0(?) != a1(=[a0+20072]), and falls through when a0(?) == a1(=[a0+20072]).
  The `beq` branch at 0x62d4 targets 0x62b8 and is always taken.
  The `beq` branch at 0x62dc targets 0x6320, is taken when s6(=a1) == a2(=0x1180), and falls through when s6(=a1) != a2(=0x1180).
  The `bltz` branch at 0x62e4 targets 0x625c, is taken when a2(=([a0+14608] << 0x2f)) < 0 (signed), and falls through when a2(=([a0+14608] << 0x2f)) >= 0 (signed).
  The `beq` branch at 0x62ec targets 0x61f0 and is always taken.
  The `beq` branch at 0x62f8 targets 0x62b0 and is always taken.
  The `beq` branch at 0x6300 targets 0x6298 and is always taken.
  The `beq` branch at 0x6318 targets 0x61f0 and is always taken.
  The `bne` branch at 0x6328 targets 0x625c, is taken when (a0(=[a0+14608]) & 0x8000) != 0, and falls through when (a0(=[a0+14608]) & 0x8000) == 0.
  The `beq` branch at 0x6330 targets 0x61f0 and is always taken.
  The return at 0x62c0 has v0 = ret(pciio_pio_write32).

- `rad_write_adat_out_subcode` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0x6338 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0x6338-0x63d4 (156 bytes).
  It occupies 156 bytes.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0x636c, `ld` at 0x6388.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x158, including `lw` at 0x6370, `lw` at 0x6384.
  The `jal` at 0x637c calls pciio_pio_write32 with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x6398 calls pciio_pio_write32 with a0=?, a1=?, a2=?, a3=?.
  The `bne` branch at 0x63ac targets 0x636c, is taken when s2(?) < 0xf (signed), and falls through when s2(?) >= 0xf (signed).
  The return at 0x63cc has v0 = ret(pciio_pio_write32).

- `rad_update_adat_mclk` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0x63d4 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0x63d4-0x6428 (84 bytes).
  It occupies 84 bytes.
  The `lw` at 0x63dc loads 4 bytes from a0 (arg0 at entry) +0x90.
  The `lw` at 0x63e0 loads 4 bytes from [a0+144] +0x15c.
  The `jal` at 0x63ec calls rad_check_adat_rx with a0=[a0+144], a1=?, a2=?, a3=?.
  The `jal` at 0x6408 calls rad_start_dma with a0=[a0+144]+4488, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x6418 calls rad_stop_dma with a0=[a0+144]+4488, a1=?, a2=?, a3=?.
  The `beq` branch at 0x63e4 targets 0x6404, is taken when at(=[[a0+144]+348]) == 0, and falls through when at(=[[a0+144]+348]) != 0.
  The `beq` branch at 0x6410 targets 0x63ec, is taken when v0(=ret(rad_start_dma)) == 0, and falls through when v0(=ret(rad_start_dma)) != 0.
  The `beq` branch at 0x6420 targets 0x63ec and is always taken.
  The return at 0x63fc has v0 = ret(rad_check_adat_rx).

- `rad_get_mclk_params` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0x6428 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0x6428-0x6458 (48 bytes).
  It occupies 48 bytes.
  The `lw` at 0x6428 loads 4 bytes from a1 (arg1 at entry) +0x0.
  The `lw` at 0x6444 loads 4 bytes from a0 (arg0 at entry) +0x124.
  The `sw` at 0x644c stores 4 bytes to a1 (arg1 at entry) +0x8.
  The `beq` branch at 0x6434 targets 0x6444, is taken when at(=[a1]) == v0(=0x1000002a), and falls through when at(=[a1]) != v0(=0x1000002a).
  The return at 0x643c has v0 = 0x0.
  The return at 0x6450 has v0 = 0x1.

- `rad_set_mclk_params` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0x6458 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0x6458-0x6460 (8 bytes).
  It occupies 8 bytes.
  The return at 0x6458 has v0 = 0x0.

- `rad_set_clockgen_params` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0x6460 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0x6460-0x667c (540 bytes).
  It occupies 540 bytes.
  The `lw` at 0x6468 loads 4 bytes from a0 (arg0 at entry) +0x150.
  The `lw` at 0x6494 loads 4 bytes from a1 (arg1 at entry) +0x0.
  4 such `sh` accesses store 2 bytes to a1 (arg1 at entry) +0x14, including `sh` at 0x64d8, `sh` at 0x6604, `sh` at 0x6664.
  3 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x178, including `sw` at 0x64dc, `sw` at 0x662c, `sw` at 0x663c.
  3 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x8, including `lw` at 0x64fc, `lw` at 0x65cc, `lw` at 0x65ec.
  The `lw` at 0x651c loads 4 bytes from a0 (arg0 at entry) +0x30.
  The `lw` at 0x6534 loads 4 bytes from ?.
  3 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x158, including `sw` at 0x6568, `sw` at 0x6638, `sw` at 0x664c.
  2 such `ld` accesses load 8 bytes from a1 (arg1 at entry) +0x8, including `ld` at 0x6584, `ld` at 0x6654.
  3 such `lw` accesses load 4 bytes from ret(kdsp_find_param_info) +0x20, including `lw` at 0x6598, `lw` at 0x65b8, `lw` at 0x661c.
  2 such `ld` accesses load 8 bytes from [ret(kdsp_find_param_info)+32] +0x0, including `ld` at 0x65a4, `ld` at 0x65bc.
  The `ld` at 0x65b0 loads 8 bytes from a0 (arg0 at entry) +0x110.
  3 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x118, including `sd` at 0x65b4, `sd` at 0x6618, `sd` at 0x6650.
  5 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x110, including `sd` at 0x65c4, `sd` at 0x65c8, `sd` at 0x65e8.
  The `sw` at 0x65dc stores 4 bytes to a0 (arg0 at entry) +0x120.
  3 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x174, including `sw` at 0x65e4, `sw` at 0x6630, `sw` at 0x6644.
  The `sw` at 0x65fc stores 4 bytes to a0 (arg0 at entry) +0x128.
  2 such `ld` accesses load 8 bytes from [ret(kdsp_find_param_info)+32] +0x8, including `ld` at 0x6608, `ld` at 0x6620.
  The `jal` at 0x6550 calls kdsp_find_resource_in_list with a0=[a1+8], a1=a0+48, a2=?, a3=a3 at entry (arg3), a4=[a0+48].
  The `jal` at 0x657c calls kdsp_find_param_info with a0=a0 at entry (arg0), a1=[a1], a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0x6480 targets 0x64cc, is taken when a0 == at(=[a0+336]+19032), and falls through when a0 != at(=[a0+336]+19032).
  The `beq` branch at 0x648c targets 0x64cc, is taken when a0 == v0(=[a0+336]+19416), and falls through when a0 != v0(=[a0+336]+19416).
  The `beq` branch at 0x64a0 targets 0x657c, is taken when a1(=[a1]) == v1(=0x1000000d), and falls through when a1(=[a1]) != v1(=0x1000000d).
  The `beq` branch at 0x64ac targets 0x64fc, is taken when a1(=[a1]) == a0(=0x10000011), and falls through when a1(=[a1]) != a0(=0x10000011).
  The `beq` branch at 0x64b4 targets 0x65c8, is taken when a1(=[a1]) == a2(=0x1000000e), and falls through when a1(=[a1]) != a2(=0x1000000e).
  The `beq` branch at 0x64bc targets 0x65e8, is taken when a1(=[a1]) == a0(=0x1000000f), and falls through when a1(=[a1]) != a0(=0x1000000f).
  The `beq` branch at 0x64c4 targets 0x64e8 and is always taken.
  The `beq` branch at 0x64cc targets 0x64e4 and is always taken.
  The `beq` branch at 0x6508 targets 0x662c, is taken when a0(=[a1+8]) == a1(=0x2000000a), and falls through when a0(=[a1+8]) != a1(=0x2000000a).
  The `beq` branch at 0x6514 targets 0x663c, is taken when a0(=[a1+8]) == a1(=0x20000016), and falls through when a0(=[a1+8]) != a1(=0x20000016).
  The `beq` branch at 0x6520 targets 0x6550, is taken when a4(=[a0+48]) == 0, and falls through when a4(=[a0+48]) != 0.
  The `beq` branch at 0x652c targets 0x6670 and is always taken.
  The `beq` branch at 0x6538 targets 0x6550, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `bne` branch at 0x6548 targets 0x6534, is taken when a2(?) < 0x18 (signed), and falls through when a2(?) >= 0x18 (signed).
  The `beq` branch at 0x655c targets 0x64d4, is taken when v0(=ret(kdsp_find_resource_in_list)) == 0, and falls through when v0(=ret(kdsp_find_resource_in_list)) != 0.
  The `beq` branch at 0x6564 targets 0x6574, is taken when v0(=ret(kdsp_find_resource_in_list)) == a0(=[a0+336]+1688), and falls through when v0(=ret(kdsp_find_resource_in_list)) != a0(=[a0+336]+1688).
  The `bne` branch at 0x656c targets 0x65e0, is taken when v0(=ret(kdsp_find_resource_in_list)) != a1(=[a0+336]+1984), and falls through when v0(=ret(kdsp_find_resource_in_list)) == a1(=[a0+336]+1984).
  The `beq` branch at 0x6574 targets 0x65e0 and is always taken.
  The `blez` branch at 0x6588 targets 0x6600, is taken when a1(=[a1+8]:8) <= 0 (signed), and falls through when a1(=[a1+8]:8) > 0 (signed).
  The `beq` branch at 0x6590 targets 0x6600, is taken when v0(=ret(kdsp_find_param_info)) == 0, and falls through when v0(=ret(kdsp_find_param_info)) != 0.
  The `beq` branch at 0x659c targets 0x6600, is taken when a2(=[ret(kdsp_find_param_info)+32]) == 0, and falls through when a2(=[ret(kdsp_find_param_info)+32]) != 0.
  The `beq` branch at 0x65ac targets 0x6608, is taken when a1(=[a1+8]:8) >= a7(=[[ret(kdsp_find_param_info)+32]]:8) (signed), and falls through when a1(=[a1+8]:8) < a7(=[[ret(kdsp_find_param_info)+32]]:8) (signed).
  The `beq` branch at 0x65c0 targets 0x64e0 and is always taken.
  The `blez` branch at 0x65d0 targets 0x6660, is taken when a0(=[a1+8]) <= 0 (signed), and falls through when a0(=[a1+8]) > 0 (signed).
  The `beq` branch at 0x65d8 targets 0x64e0 and is always taken.
  The `beq` branch at 0x65e0 targets 0x64dc and is always taken.
  The `blez` branch at 0x65f0 targets 0x6668, is taken when a0(=[a1+8]) <= 0 (signed), and falls through when a0(=[a1+8]) > 0 (signed).
  The `beq` branch at 0x65f8 targets 0x64e0 and is always taken.
  The `beq` branch at 0x6600 targets 0x64e0 and is always taken.
  The `beq` branch at 0x6610 targets 0x6650, is taken when t1(=[[ret(kdsp_find_param_info)+32]+8]:8) >= a1(=[a1+8]:8) (signed), and falls through when t1(=[[ret(kdsp_find_param_info)+32]+8]:8) < a1(=[a1+8]:8) (signed).
  The `beq` branch at 0x6624 targets 0x64e0 and is always taken.
  The `beq` branch at 0x6634 targets 0x64e0 and is always taken.
  The `beq` branch at 0x6648 targets 0x64e0 and is always taken.
  The `beq` branch at 0x6658 targets 0x64e0 and is always taken.
  The `beq` branch at 0x6660 targets 0x64e0 and is always taken.
  The `beq` branch at 0x6668 targets 0x64e0 and is always taken.
  The `beq` branch at 0x6674 targets 0x6544 and is always taken.
  The return at 0x64f4 has v0 = one of 0x0, 0x1.

- `rad_get_clockgen_params` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0x667c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0x667c-0x66e8 (108 bytes).
  It occupies 108 bytes.
  The `lw` at 0x667c loads 4 bytes from a1 (arg1 at entry) +0x0.
  The `lw` at 0x668c loads 4 bytes from a0 (arg0 at entry) +0x150.
  The `lw` at 0x6690 loads 4 bytes from a0 (arg0 at entry) +0x158.
  The `lw` at 0x66b0 loads 4 bytes from a0 (arg0 at entry) +0x120.
  The `sw` at 0x66c0 stores 4 bytes to a1 (arg1 at entry) +0x8.
  The `lw` at 0x66d4 loads 4 bytes from a0 (arg0 at entry) +0x128.
  The `bne` branch at 0x6688 targets 0x66cc, is taken when at(=[a1]) != v0(=0x10000010), and falls through when at(=[a1]) == v0(=0x10000010).
  The `beq` branch at 0x66a0 targets 0x66b0, is taken when a6(=[a0+344]) == v1(=[a0+336]+1688), and falls through when a6(=[a0+344]) != v1(=[a0+336]+1688).
  The `bne` branch at 0x66a8 targets 0x66e0, is taken when a6(=[a0+344]) != a5(=[a0+336]+1984), and falls through when a6(=[a0+344]) == a5(=[a0+336]+1984).
  The `beq` branch at 0x66b4 targets 0x66d4, is taken when a2(=[a0+288]) == a4(=0x1), and falls through when a2(=[a0+288]) != a4(=0x1).
  The `bne` branch at 0x66d8 targets 0x66c0, is taken when a3(=[a0+296]) != a4(=0x1), and falls through when a3(=[a0+296]) == a4(=0x1).
  The `beq` branch at 0x66e0 targets 0x66c0 and is always taken.
  The return at 0x66c4 has v0 = 0x1.
  The return at 0x66cc has v0 = 0x0.

- `rad_set_digital_if_params` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0x66e8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0x66e8-0x6730 (72 bytes).
  It occupies 72 bytes.
  The `lw` at 0x66e8 loads 4 bytes from a1 (arg1 at entry) +0x0.
  The `beq` branch at 0x66fc targets 0x6724, is taken when v0(=[a1]) == at(=0x10000004), and falls through when v0(=[a1]) != at(=0x10000004).
  The `beq` branch at 0x6704 targets 0x6724, is taken when v0(=[a1]) == a3(=0x10000019), and falls through when v0(=[a1]) != a3(=0x10000019).
  The `beq` branch at 0x670c targets 0x6724, is taken when v0(=[a1]) == a4(=0x1000001b), and falls through when v0(=[a1]) != a4(=0x1000001b).
  The `beq` branch at 0x6714 targets 0x6728, is taken when v0(=[a1]) == a5(=0x1000001c), and falls through when v0(=[a1]) != a5(=0x1000001c).
  The return at 0x671c has v0 = 0x0.
  The return at 0x6728 has v0 = 0x1.

- `rad_set_analog_in_gain` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0x6730 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0x6730-0x6868 (312 bytes).
  It occupies 312 bytes.
  The `lw` at 0x6738 loads 4 bytes from a0 (arg0 at entry) +0x108.
  The `lw` at 0x6740 loads 4 bytes from [a0+264] +0x1d0.
  3 such `lw` accesses load 4 bytes from [[a0+264]+464] +0x4e70, including `lw` at 0x67cc, `lw` at 0x67fc, `lw` at 0x682c.
  2 such `sw` accesses store 4 bytes to [[a0+264]+464] +0x4e70, including `sw` at 0x67d8, `sw` at 0x6818.
  2 such `sw` accesses store 4 bytes to ?, including `sw` at 0x67dc, `sw` at 0x6824.
  The `ld` at 0x67ec loads 8 bytes from ?.
  The `lw` at 0x6828 loads 4 bytes from [[a0+264]+464] +0x158.
  The `jal` at 0x67a0 calls kdsp_db_gain_to_regval with a0=?, a1=a0 at entry (arg0), a2=0x0, a3=?.
  The `jal` at 0x6830 calls pciio_pio_write32 with a0=[[[a0+264]+464]+20080], a1=[[[a0+264]+464]+344]+124, a2=?, a3=?.
  The `beq` branch at 0x6760 targets 0x676c, is taken when a0 == at(=[[a0+264]+464]+15864), and falls through when a0 != at(=[[a0+264]+464]+15864).
  The `blez` branch at 0x6778 targets 0x6828, is taken when s6(=a2) <= 0 (signed), and falls through when s6(=a2) > 0 (signed).
  The `beq` branch at 0x6794 targets 0x67ec and is always taken.
  The `bltz` branch at 0x67c0 targets 0x67e0, is taken when v0(=ret(kdsp_db_gain_to_regval)) < 0 (signed), and falls through when v0(=ret(kdsp_db_gain_to_regval)) >= 0 (signed).
  The `beq` branch at 0x67e4 targets 0x6828, is taken when a2(?) >= s6(=a2) (signed), and falls through when a2(?) < s6(=a2) (signed).
  The `bne` branch at 0x67f0 targets 0x679c, is taken when a0(?) != s4(=0x8000000000000000), and falls through when a0(?) == s4(=0x8000000000000000).
  The `bne` branch at 0x6820 targets 0x67ec, is taken when s2(?) < s6(=a2) (signed), and falls through when s2(?) >= s6(=a2) (signed).
  The return at 0x6860 has v0 = ret(pciio_pio_write32).

- `rad_set_analog_in_if_params` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0x6868 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0x6868-0x6924 (188 bytes).
  It occupies 188 bytes.
  The `lw` at 0x686c loads 4 bytes from a1 (arg1 at entry) +0x0.
  The `lw` at 0x68c0 loads 4 bytes from a0 (arg0 at entry) +0x108.
  The `lw` at 0x68d4 loads 4 bytes from [a0+264] +0x174.
  The `lh` at 0x68e8 loads 2 bytes from a1 (arg1 at entry) +0x14.
  The `jal` at 0x68d0 calls kdsp_fetch_external with a0=a1 at entry (arg1), a1=sp-48, a2=[[a0+264]+372], a3=0x8, a4=a2 at entry (arg2), a6=0x10000004, a7=0x1000001b.
  The `jal` at 0x6900 calls rad_set_analog_in_gain with a0=a0 at entry (arg0), a1=ret(kdsp_fetch_external), a2=?, a3=?.
  The `beq` branch at 0x6890 targets 0x68bc, is taken when v0(=[a1]) == at(=0x10000019), and falls through when v0(=[a1]) != at(=0x10000019).
  The `beq` branch at 0x6898 targets 0x6910, is taken when v0(=[a1]) == a6(=0x10000004), and falls through when v0(=[a1]) != a6(=0x10000004).
  The `beq` branch at 0x68a0 targets 0x6910, is taken when v0(=[a1]) == a7(=0x1000001b), and falls through when v0(=[a1]) != a7(=0x1000001b).
  The `beq` branch at 0x68a8 targets 0x6910, is taken when v0(=[a1]) == t0(=0x1000001c), and falls through when v0(=[a1]) != t0(=0x1000001c).
  The `beq` branch at 0x68b4 targets 0x6914 and is always taken.
  The `beq` branch at 0x68dc targets 0x691c, is taken when v0(=ret(kdsp_fetch_external)) == 0, and falls through when v0(=ret(kdsp_fetch_external)) != 0.
  The `bne` branch at 0x68f0 targets 0x6900, is taken when a2(=[a1+20]:2) < 0x3 (signed), and falls through when a2(=[a1+20]:2) >= 0x3 (signed).
  The `beq` branch at 0x691c targets 0x6914 and is always taken.
  The return at 0x6914 has v0 = one of 0x0, 0x1.

- `rad_get_analog_in_if_params` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0x6924 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0x6924-0x6a7c (344 bytes).
  It occupies 344 bytes.
  The `lw` at 0x6944 loads 4 bytes from a1 (arg1 at entry) +0x0.
  The `lw` at 0x695c loads 4 bytes from a0 (arg0 at entry) +0x108.
  The `lw` at 0x6974 loads 4 bytes from [a0+264] +0x1d0.
  The `lw` at 0x6980 loads 4 bytes from [a0+264] +0x174.
  2 such `sd` accesses store 8 bytes to ?, including `sd` at 0x69f0, `sd` at 0x6a14.
  The `lw` at 0x69f4 loads 4 bytes from ?.
  3 such `sw` accesses store 4 bytes to a1 (arg1 at entry) +0x8, including `sw` at 0x6a68, `sw` at 0x6a70, `sw` at 0x6a78.
  The `jal` at 0x69d4 calls kdsp_regval_to_db_gain with a0=?, a1=a0 at entry (arg0), a2=0x0, a3=?.
  The `jal` at 0x6a28 calls kdsp_put_external with a0=a1 at entry (arg1), a1=sp-96, a2=[[a0+264]+372], a3=0x8, a4=a2 at entry (arg2).
  The `beq` branch at 0x697c targets 0x69a0, is taken when a6(=[a1]) == at(=0x10000019), and falls through when a6(=[a1]) != at(=0x10000019).
  The `beq` branch at 0x6988 targets 0x6a5c, is taken when a6(=[a1]) == a4(=0x10000004), and falls through when a6(=[a1]) != a4(=0x10000004).
  The `beq` branch at 0x6990 targets 0x6a6c, is taken when a6(=[a1]) == a7(=0x1000001c), and falls through when a6(=[a1]) != a7(=0x1000001c).
  The `beq` branch at 0x6998 targets 0x6a40 and is always taken.
  The `bne` branch at 0x69a4 targets 0x69b4, is taken when a0 != t8(=[[a0+264]+464]+15864), and falls through when a0 == t8(=[[a0+264]+464]+15864).
  The `beq` branch at 0x69ac targets 0x69b8 and is always taken.
  The `blez` branch at 0x69c0 targets 0x6a18, is taken when s3(=[[a0+264]+372]) <= 0 (signed), and falls through when s3(=[[a0+264]+372]) > 0 (signed).
  The `beq` branch at 0x69c8 targets 0x69f4 and is always taken.
  The `beq` branch at 0x69ec targets 0x6a18, is taken when s2(?) >= s3(=[[a0+264]+372]) (signed), and falls through when s2(?) < s3(=[[a0+264]+372]) (signed).
  The `bne` branch at 0x69f8 targets 0x69d0, is taken when v0(?) != 0, and falls through when v0(?) == 0.
  The `bne` branch at 0x6a10 targets 0x69f4, is taken when s2(?) < s3(=[[a0+264]+372]) (signed), and falls through when s2(?) >= s3(=[[a0+264]+372]) (signed).
  The `bne` branch at 0x6a5c targets 0x6a74, is taken when s4(=a0) != a0(=[[a0+264]+464]+15864), and falls through when s4(=a0) == a0(=[[a0+264]+464]+15864).
  The `beq` branch at 0x6a64 targets 0x6a38 and is always taken.
  The `beq` branch at 0x6a6c targets 0x6a38 and is always taken.
  The `beq` branch at 0x6a74 targets 0x6a38 and is always taken.
  The return at 0x6a54 has v0 = one of 0x0, 0x1.

- `rad_set_analog_out_if_params` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0x6a7c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0x6a7c-0x6d08 (652 bytes).
  It occupies 652 bytes.
  The `lw` at 0x6a8c loads 4 bytes from a1 (arg1 at entry) +0x0.
  The `lw` at 0x6a94 loads 4 bytes from a0 (arg0 at entry) +0x108.
  The `lw` at 0x6ab0 loads 4 bytes from [a0+264] +0x1d0.
  The `lw` at 0x6af8 loads 4 bytes from a1 (arg1 at entry) +0x8.
  3 such `lw` accesses load 4 bytes from [[a0+264]+464] +0x158, including `lw` at 0x6afc, `lw` at 0x6cb4, `lw` at 0x6cdc.
  The `lw` at 0x6b04 loads 4 bytes from [[a0+264]+464] +0x4e54.
  The `sw` at 0x6b20 stores 4 bytes to [[a0+264]+464] +0x4e54.
  The `ld` at 0x6b68 loads 8 bytes from ret(kdsp_fetch_external) +0x0.
  The `lw` at 0x6b98 loads 4 bytes from [a0+264] +0x174.
  The `lh` at 0x6bac loads 2 bytes from a1 (arg1 at entry) +0x14.
  3 such `lw` accesses load 4 bytes from [[a0+264]+464] +0x4e70, including `lw` at 0x6c38, `lw` at 0x6c78, `lw` at 0x6cb8.
  2 such `sw` accesses store 4 bytes to [[a0+264]+464] +0x4e70, including `sw` at 0x6c50, `sw` at 0x6ca4.
  2 such `sw` accesses store 4 bytes to ?, including `sw` at 0x6c54, `sw` at 0x6cb0.
  The `ld` at 0x6c6c loads 8 bytes from ?.
  2 such `sw` accesses store 4 bytes to [[a0+264]+464] +0x4e80, including `sw` at 0x6cd4, `sw` at 0x6cf4.
  The `sw` at 0x6cec stores 4 bytes to a0 (arg0 at entry) +0x10c.
  The `jal` at 0x6b1c calls pciio_pio_write32 with a0=?, a1=[[[a0+264]+464]+344]+112, a2=?, a3=-0x101, a4=a2 at entry (arg2), a6=0x10000000, a7=[a0+264].
  The `jal` at 0x6b60 calls kdsp_fetch_external with a0=a1 at entry (arg1), a1=sp-96, a2=0x1, a3=0x8, a4=a2 at entry (arg2), a6=0x10000000, a7=[a0+264].
  The `jal` at 0x6b9c calls kdsp_fetch_external with a0=a1 at entry (arg1), a1=sp-88, a2=[[a0+264]+372], a3=0x8, a4=a2 at entry (arg2), a6=0x10000000, a7=[a0+264].
  The `jal` at 0x6bd0 calls kdsp_find_param_info with a0=a0 at entry (arg0), a1=0x10000019, a2=?, a3=?.
  The `jal` at 0x6c0c calls kdsp_db_gain_to_regval with a0=?, a1=a0 at entry (arg0), a2=0x0, a3=?, a4=0xff.
  The `jal` at 0x6cbc calls pciio_pio_write32 with a0=[[[a0+264]+464]+20080], a1=[[[a0+264]+464]+344]+124, a2=?, a3=?.
  The `jal` at 0x6ce0 calls pciio_pio_write32 with a0=one of 0x2, 0x3, a1=[[[a0+264]+464]+344]+144, a2=one of 0x2, 0x3, a3=?.
  The `beq` branch at 0x6aac targets 0x6b40, is taken when v0(=[a1]) == t0(=0x10000019), and falls through when v0(=[a1]) != t0(=0x10000019).
  The `beq` branch at 0x6ab8 targets 0x6ae4, is taken when v0(=[a1]) == at(=0x1000001d), and falls through when v0(=[a1]) != at(=0x1000001d).
  The `beq` branch at 0x6ac4 targets 0x6b54, is taken when v0(=[a1]) == v1(=0x1000001c), and falls through when v0(=[a1]) != v1(=0x1000001c).
  The `beq` branch at 0x6acc targets 0x6b24, is taken when v0(=[a1]) == a0(=0x10000004), and falls through when v0(=[a1]) != a0(=0x10000004).
  The `beq` branch at 0x6ad4 targets 0x6b28, is taken when v0(=[a1]) == a1(=0x1000001b), and falls through when v0(=[a1]) != a1(=0x1000001b).
  The `beq` branch at 0x6adc targets 0x6b28 and is always taken.
  The `beq` branch at 0x6ae8 targets 0x6af8, is taken when s1(=a0) == a0(=[[a0+264]+464]+16136), and falls through when s1(=a0) != a0(=[[a0+264]+464]+16136).
  The `beq` branch at 0x6af0 targets 0x6b28 and is always taken.
  The `beq` branch at 0x6b44 targets 0x6b90, is taken when a0 == a1(=[[a0+264]+464]+16136), and falls through when a0 != a1(=[[a0+264]+464]+16136).
  The `beq` branch at 0x6b4c targets 0x6b2c and is always taken.
  The `beq` branch at 0x6b78 targets 0x6cf0, is taken when s3(?) == a2(=0x12), and falls through when s3(?) != a2(=0x12).
  The `beq` branch at 0x6b80 targets 0x6cd4, is taken when s3(?) == a0(=0x10), and falls through when s3(?) != a0(=0x10).
  The `beq` branch at 0x6b88 targets 0x6b2c and is always taken.
  The `beq` branch at 0x6ba4 targets 0x6d00, is taken when v0(=ret(kdsp_fetch_external)) == 0, and falls through when v0(=ret(kdsp_fetch_external)) != 0.
  The `bne` branch at 0x6bb8 targets 0x6bc8, is taken when t8(=[a1+20]:2) < 0x3 (signed), and falls through when t8(=[a1+20]:2) >= 0x3 (signed).
  The `blez` branch at 0x6be4 targets 0x6cb4, is taken when a2(?) <= 0 (signed), and falls through when a2(?) > 0 (signed).
  The `beq` branch at 0x6c04 targets 0x6c6c and is always taken.
  The `bltz` branch at 0x6c2c targets 0x6c58, is taken when v0(=ret(kdsp_db_gain_to_regval)) < 0 (signed), and falls through when v0(=ret(kdsp_db_gain_to_regval)) >= 0 (signed).
  The `beq` branch at 0x6c64 targets 0x6cb4, is taken when a0(?) >= t0(?) (signed), and falls through when a0(?) < t0(?) (signed).
  The `bne` branch at 0x6c70 targets 0x6c0c, is taken when a0(?) != a2(=0x8000000000000000), and falls through when a0(?) == a2(=0x8000000000000000).
  The `bne` branch at 0x6cac targets 0x6c6c, is taken when s5(?) < t1(?) (signed), and falls through when s5(?) >= t1(?) (signed).
  The `beq` branch at 0x6ccc targets 0x6b24 and is always taken.
  The `beq` branch at 0x6ce8 targets 0x6b24 and is always taken.
  The `beq` branch at 0x6cf8 targets 0x6cdc and is always taken.
  The `beq` branch at 0x6d00 targets 0x6b28 and is always taken.
  The return at 0x6b38 has v0 = one of 0x0, 0x1.

- `rad_get_analog_out_if_params` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0x6d08 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0x6d08-0x6ea0 (408 bytes).
  It occupies 408 bytes.
  The `lw` at 0x6d14 loads 4 bytes from sym(.data) +0x5040.
  The `lw` at 0x6d24 loads 4 bytes from a1 (arg1 at entry) +0x0.
  The `lw` at 0x6d30 loads 4 bytes from a0 (arg0 at entry) +0x108.
  The `lw` at 0x6d48 loads 4 bytes from [a0+264] +0x174.
  The `lw` at 0x6d54 loads 4 bytes from [a0+264] +0x1d0.
  The `lw` at 0x6d68 loads 4 bytes from [[a0+264]+464] +0x4e80.
  3 such `sw` accesses store 4 bytes to a1 (arg1 at entry) +0x8, including `sw` at 0x6d74, `sw` at 0x6db4, `sw` at 0x6dc8.
  The `lw` at 0x6da4 loads 4 bytes from [[a0+264]+464] +0x4e54.
  The `lw` at 0x6dc0 loads 4 bytes from sym(.data) +0x5038.
  The `ld` at 0x6e00 loads 8 bytes from sym(.bss) +0x58.
  2 such `sd` accesses store 8 bytes to ?, including `sd` at 0x6e58, `sd` at 0x6e94.
  The `lw` at 0x6e64 loads 4 bytes from ?.
  The `jal` at 0x6dcc calls kdsp_find_param_info with a0=a0 at entry (arg0), a1=0x10000019, a2=a2 at entry (arg2), a3=a3 at entry (arg3), a6=0x1000001d, a7=0x1000001c.
  The `jal` at 0x6e1c calls kdsp_put_external with a0=a1 at entry (arg1), a1=sp-96, a2=[[a0+264]+372], a3=0x8, a4=a2 at entry (arg2).
  The `jal` at 0x6e38 calls kdsp_regval_to_db_gain with a0=?, a1=a0 at entry (arg0), a2=0x0, a3=?.
  The `beq` branch at 0x6d50 targets 0x6dcc, is taken when v0(=[a1]) == t3(=0x10000019), and falls through when v0(=[a1]) != t3(=0x10000019).
  The `beq` branch at 0x6d58 targets 0x6d94, is taken when v0(=[a1]) == a6(=0x1000001d), and falls through when v0(=[a1]) != a6(=0x1000001d).
  The `bne` branch at 0x6d60 targets 0x6db8, is taken when v0(=[a1]) != a7(=0x1000001c), and falls through when v0(=[a1]) == a7(=0x1000001c).
  The `beq` branch at 0x6d6c targets 0x6dc0, is taken when t8(=[[[a0+264]+464]+20096]) == t9(=0x2), and falls through when t8(=[[[a0+264]+464]+20096]) != t9(=0x2).
  The `beq` branch at 0x6d94 targets 0x6da4, is taken when a0 == at(=[[a0+264]+464]+16136), and falls through when a0 != at(=[[a0+264]+464]+16136).
  The `beq` branch at 0x6d9c targets 0x6d80 and is always taken.
  The `beq` branch at 0x6db0 targets 0x6d78 and is always taken.
  The `beq` branch at 0x6db8 targets 0x6d7c and is always taken.
  The `beq` branch at 0x6dc4 targets 0x6d78 and is always taken.
  The `bne` branch at 0x6de0 targets 0x6e00, is taken when s1(=a0) != a0(=[[a0+264]+464]+16136), and falls through when s1(=a0) == a0(=[[a0+264]+464]+16136).
  The `blez` branch at 0x6de8 targets 0x6e10, is taken when s3(=[[a0+264]+372]) <= 0 (signed), and falls through when s3(=[[a0+264]+372]) > 0 (signed).
  The `beq` branch at 0x6df8 targets 0x6e64 and is always taken.
  The `beq` branch at 0x6e28 targets 0x6d78 and is always taken.
  The `beq` branch at 0x6e5c targets 0x6e0c, is taken when a2(?) >= s3(=[[a0+264]+372]) (signed), and falls through when a2(?) < s3(=[[a0+264]+372]) (signed).
  The `bne` branch at 0x6e6c targets 0x6e30, is taken when v0(?) != 0, and falls through when v0(?) == 0.
  The `bne` branch at 0x6e90 targets 0x6e64, is taken when a0(?) < s3(=[[a0+264]+372]) (signed), and falls through when a0(?) >= s3(=[[a0+264]+372]) (signed).
  The `beq` branch at 0x6e98 targets 0x6e10 and is always taken.
  The return at 0x6d8c has v0 = one of 0x0, 0x1.

- `rad_vl_write_MUX_SEL_MIO` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0x6ea0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0x6ea0-0x6f84 (228 bytes).
  It occupies 228 bytes.
  6 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x158, including `lw` at 0x6ed4, `lw` at 0x6eec, `lw` at 0x6f04.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x4e58, including `lw` at 0x6ef0, `lw` at 0x6f08.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x4e58, including `sw` at 0x6f00, `sw` at 0x6f18.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x4e78, including `sw` at 0x6f30, `sw` at 0x6f58.
  The `lw` at 0x6f68 loads 4 bytes from a0 (arg0 at entry) +0x4e7c.
  The `jal` at 0x6ee4 calls pciio_pio_write32 with a0=?, a1=[a0+344]+140, a2=?, a3=?.
  The `jal` at 0x6efc calls pciio_pio_write32 with a0=?, a1=[a0+344]+76, a2=?, a3=?.
  The `jal` at 0x6f14 calls pciio_pio_write32 with a0=(0x8000000 | [a0+20056]), a1=[a0+344]+76, a2=?, a3=?.
  The `jal` at 0x6f34 calls pciio_pio_write32 with a0=0x2, a1=[a0+344]+136, a2=0x2, a3=?.
  The `jal` at 0x6f5c calls pciio_pio_write32 with a0=0x3, a1=[a0+344]+136, a2=0x3, a3=?.
  The `jal` at 0x6f6c calls pciio_pio_write32 with a0=[a0+20092], a1=[a0+344]+140, a2=?, a3=?.
  The `bgez` branch at 0x6f20 targets 0x6ed4, is taken when s1(?) >= 0 (signed), and falls through when s1(?) < 0 (signed).
  The return at 0x6f7c has v0 = ret(pciio_pio_write32).

- `rad_vl_write_MUX_SEL_RADICAL` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0x6f84 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0x6f84-0x6fac (40 bytes).
  It occupies 40 bytes.
  The `lw` at 0x6f8c loads 4 bytes from a0 (arg0 at entry) +0x158.
  The `jal` at 0x6f98 calls pciio_pio_write32 with a0=a1 at entry (arg1), a1=[a0+344]+124, a2=a0 at entry (arg0), a3=a3 at entry (arg3).
  The return at 0x6fa4 has v0 = ret(pciio_pio_write32).

- `rad_vl_write_MUX_SEL` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0x6fac (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0x6fac-0x6ff4 (72 bytes).
  It occupies 72 bytes.
  The `lh` at 0x6fac loads 2 bytes from a0 (arg0 at entry) +0x152.
  The `jal` at 0x6fd4 calls rad_vl_write_MUX_SEL_RADICAL with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=0xd, a4=[a0+338]:2.
  The `jal` at 0x6fe4 calls rad_vl_write_MUX_SEL_MIO with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=0xd, a4=[a0+338]:2.
  The `beq` branch at 0x6fbc targets 0x6fe4, is taken when a4(=[a0+338]:2) == at(=0x7), and falls through when a4(=[a0+338]:2) != at(=0x7).
  The `beq` branch at 0x6fc4 targets 0x6fd4, is taken when a4(=[a0+338]:2) == a3(=0xd), and falls through when a4(=[a0+338]:2) != a3(=0xd).
  The `beq` branch at 0x6fdc targets 0x6fcc and is always taken.
  The `beq` branch at 0x6fec targets 0x6fcc and is always taken.
  The return at 0x6fcc has v0 = one of ?, ret(rad_vl_write_MUX_SEL_RADICAL), ret(rad_vl_write_MUX_SEL_MIO).

- `rad_vl_set_clockgen_MIO` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0x6ff4 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0x6ff4-0x71ec (504 bytes).
  It occupies 504 bytes.
  The `lw` at 0x6ffc loads 4 bytes from a0 (arg0 at entry) +0x150.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x128, including `lw` at 0x7058, `lw` at 0x707c, `lw` at 0x70b4.
  3 such `lw` accesses load 4 bytes from [a0+336] +0x4e84, including `lw` at 0x7070, `lw` at 0x709c, `lw` at 0x71c4.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x120, including `lw` at 0x7088, `lw` at 0x7158, `lw` at 0x7184.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x15c, including `lw` at 0x7098, `lw` at 0x70c4, `lw` at 0x7168.
  The `lw` at 0x70d8 loads 4 bytes from (sym(.rodata)+16 + ([a0+348] << 0x3)) +0x0.
  The `lw` at 0x70dc loads 4 bytes from (sym(.rodata)+16 + ([a0+348] << 0x3)) +0x4.
  2 such `sw` accesses store 4 bytes to [a0+336] +0x4e84, including `sw` at 0x70fc, `sw` at 0x71e0.
  The `jal` at 0x70f8 calls rad_vl_write_MUX_SEL_MIO with a0=[a0+336], a1=?, a2=?, a3=([a0+348] << 0x3), a4=one of 0x0, 0x1, 0x2, a5=[a0+336]+17880, a6=[a0+336]+17880.
  The `jal` at 0x7100 calls rad_update_ksync with a0=[a0+336], a1=?, a2=?, a3=?.
  The `bne` branch at 0x7024 targets 0x7030, is taken when s3(=[a0+336]+1984) != a1, and falls through when s3(=[a0+336]+1984) == a1.
  The `bne` branch at 0x702c targets 0x7058, is taken when a0 != v0(=[a0+336]+17880), and falls through when a0 == v0(=[a0+336]+17880).
  The `bne` branch at 0x7034 targets 0x704c, is taken when s2(=a1) != at(=[a0+336]+1688), and falls through when s2(=a1) == at(=[a0+336]+1688).
  The `beq` branch at 0x703c targets 0x7050, is taken when s1(=a0) == v0(=[a0+336]+17880), and falls through when s1(=a0) != v0(=[a0+336]+17880).
  The `beq` branch at 0x7044 targets 0x7050 and is always taken.
  The `beq` branch at 0x7050 targets 0x7068, is taken when v0(=one of 0x0, 0x1) == 0, and falls through when v0(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x7060 targets 0x7158, is taken when v0(=[a0+296]) == a4(=0x1), and falls through when v0(=[a0+296]) != a4(=0x1).
  The `bne` branch at 0x7068 targets 0x709c, is taken when s3(=[a0+336]+1984) != s2(=a1), and falls through when s3(=[a0+336]+1984) == s2(=a1).
  The `beq` branch at 0x7074 targets 0x70a0, is taken when s1(=a0) == a5(=[a0+336]+17880), and falls through when s1(=a0) != a5(=[a0+336]+17880).
  The `bne` branch at 0x7080 targets 0x70a4, is taken when v1(=[a0+296]) != a4(=0x1), and falls through when v1(=[a0+296]) == a4(=0x1).
  The `bne` branch at 0x708c targets 0x70a4, is taken when a0(=[a0+288]) != a4(=0x1), and falls through when a0(=[a0+288]) == a4(=0x1).
  The `beq` branch at 0x7094 targets 0x70c8 and is always taken.
  The `bne` branch at 0x70a4 targets 0x70c4, is taken when s2(=a1) != a1(=[a0+336]+1688), and falls through when s2(=a1) == a1(=[a0+336]+1688).
  The `beq` branch at 0x70ac targets 0x70c0, is taken when s1(=a0) == a6(=[a0+336]+17880), and falls through when s1(=a0) != a6(=[a0+336]+17880).
  The `beq` branch at 0x70b8 targets 0x7184, is taken when a2(=[a0+296]) == a4(=0x1), and falls through when a2(=[a0+296]) != a4(=0x1).
  The `bne` branch at 0x710c targets 0x7128, is taken when s3(=[a0+336]+1984) != s2(=a1), and falls through when s3(=[a0+336]+1984) == s2(=a1).
  The `beq` branch at 0x7118 targets 0x712c, is taken when s1(=a0) == a3(=[a0+336]+17880), and falls through when s1(=a0) != a3(=[a0+336]+17880).
  The `beq` branch at 0x7120 targets 0x7144 and is always taken.
  The `bne` branch at 0x712c targets 0x713c, is taken when s2(=a1) != a4(=[a0+336]+1688), and falls through when s2(=a1) == a4(=[a0+336]+1688).
  The `bne` branch at 0x7134 targets 0x7120, is taken when s1(=a0) != a5(=[a0+336]+17880), and falls through when s1(=a0) == a5(=[a0+336]+17880).
  The `bne` branch at 0x715c targets 0x7068, is taken when a7(=[a0+288]) != a4(=0x1), and falls through when a7(=[a0+288]) == a4(=0x1).
  The `bne` branch at 0x7164 targets 0x7198, is taken when s3(=[a0+336]+1984) != s2(=a1), and falls through when s3(=[a0+336]+1984) == s2(=a1).
  The `beq` branch at 0x7170 targets 0x719c, is taken when s1(=a0) == t0(=[a0+336]+17880), and falls through when s1(=a0) != t0(=[a0+336]+17880).
  The `beq` branch at 0x717c targets 0x71c4 and is always taken.
  The `bne` branch at 0x7188 targets 0x70c4, is taken when t1(=[a0+288]) != a4(=0x1), and falls through when t1(=[a0+288]) == a4(=0x1).
  The `beq` branch at 0x7190 targets 0x70c4 and is always taken.
  The `bne` branch at 0x719c targets 0x71c0, is taken when s2(=a1) != t2(=[a0+336]+1688), and falls through when s2(=a1) == t2(=[a0+336]+1688).
  The `beq` branch at 0x71a8 targets 0x71c0, is taken when s1(=a0) == t3(=[a0+336]+17880), and falls through when s1(=a0) != t3(=[a0+336]+17880).
  The `beq` branch at 0x71b4 targets 0x71c4 and is always taken.
  The `bne` branch at 0x71dc targets 0x70a0, is taken when s3(=[a0+336]+1984) != s2(=a1), and falls through when s3(=[a0+336]+1984) == s2(=a1).
  The `beq` branch at 0x71e4 targets 0x7074 and is always taken.
  The return at 0x7150 has v0 = one of 0x0, 0x1.
  The instructions from 0x71bc to 0x71bc are not reached by any path from the entry, and their branches are not listed.

- `rad_vl_set_clockgen_RADICAL` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0x71ec (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0x71ec-0x7304 (280 bytes).
  It occupies 280 bytes.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x15c, including `lw` at 0x71f4, `lw` at 0x7270, `lw` at 0x72ec.
  The `lw` at 0x7200 loads 4 bytes from a0 (arg0 at entry) +0x150.
  The `lw` at 0x7220 loads 4 bytes from [a0+336] +0x4e84.
  2 such `sw` accesses store 4 bytes to [a0+336] +0x4e84, including `sw` at 0x7240, `sw` at 0x729c.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x128, including `lw` at 0x7248, `lw` at 0x7260.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x120, including `lw` at 0x72dc, `lw` at 0x72f0.
  The `jal` at 0x7298 calls rad_vl_write_MUX_SEL_RADICAL with a0=[a0+336], a1=?, a2=?, a3=?, a4=one of 0x4, 0x6, a6=0x3.
  The `jal` at 0x72a0 calls rad_update_ksync with a0=[a0+336], a1=?, a2=?, a3=?.
  The `beq` branch at 0x7214 targets 0x7220, is taken when a4(=[a0+348]) == 0, and falls through when a4(=[a0+348]) != 0.
  The `bne` branch at 0x723c targets 0x7254, is taken when s8(=[a0+336]+1984) != s1(=a1), and falls through when s8(=[a0+336]+1984) == s1(=a1).
  The `beq` branch at 0x724c targets 0x72dc, is taken when t1(=[a0+296]) == v0(=0x1), and falls through when t1(=[a0+296]) != v0(=0x1).
  The `bne` branch at 0x7254 targets 0x7270, is taken when s1(=a1) != a1(=[a0+336]+1688), and falls through when s1(=a1) == a1(=[a0+336]+1688).
  The `beq` branch at 0x7264 targets 0x72f0, is taken when t2(=[a0+296]) == v0(=0x1), and falls through when t2(=[a0+296]) != v0(=0x1).
  The `beq` branch at 0x7274 targets 0x7280, is taken when t3(=[a0+348]) == 0, and falls through when t3(=[a0+348]) != 0.
  The `beq` branch at 0x72ac targets 0x72d4, is taken when s8(=[a0+336]+1984) == s1(=a1), and falls through when s8(=[a0+336]+1984) != s1(=a1).
  The `beq` branch at 0x72b8 targets 0x72d4, is taken when s1(=a1) == a2(=[a0+336]+1688), and falls through when s1(=a1) != a2(=[a0+336]+1688).
  The `beq` branch at 0x72d4 targets 0x72c0 and is always taken.
  The `bne` branch at 0x72e0 targets 0x7254, is taken when a3(=[a0+288]) != v0(=0x1), and falls through when a3(=[a0+288]) == v0(=0x1).
  The `beq` branch at 0x72e8 targets 0x7274 and is always taken.
  The `bne` branch at 0x72f4 targets 0x7270, is taken when a4(=[a0+288]) != v0(=0x1), and falls through when a4(=[a0+288]) == v0(=0x1).
  The `beq` branch at 0x72fc targets 0x7270 and is always taken.
  The return at 0x72cc has v0 = one of 0x0, 0x1.

- `rad_vl_set_clockgen` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0x7304 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0x7304-0x7348 (68 bytes).
  It occupies 68 bytes.
  The `lw` at 0x7304 loads 4 bytes from a0 (arg0 at entry) +0x150.
  The `lh` at 0x7308 loads 2 bytes from [a0+336] +0x152.
  The `jal` at 0x731c calls rad_vl_set_clockgen_RADICAL with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x7338 calls rad_vl_set_clockgen_MIO with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0x7314 targets 0x7338, is taken when at(=[[a0+336]+338]:2) == v0(=0x7), and falls through when at(=[[a0+336]+338]:2) != v0(=0x7).
  The `beq` branch at 0x7340 targets 0x7328 and is always taken.
  The return at 0x7330 has v0 = one of ret(rad_vl_set_clockgen_RADICAL), ret(rad_vl_set_clockgen_MIO).

- `rad_update_ksync` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0x7348 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0x7348-0x76a0 (856 bytes).
  It occupies 856 bytes.
  The `ld` at 0x7388 loads 8 bytes from a0 (arg0 at entry) +0x4ef8.
  20 such `lw` accesses load 4 bytes from ?, including `lw` at 0x7408, `lw` at 0x7420, `lw` at 0x7488.
  5 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x158, including `lw` at 0x7434, `lw` at 0x7444, `lw` at 0x7520.
  3 such `sw` accesses store 4 bytes to ?, including `sw` at 0x7454, `sw` at 0x745c, `sw` at 0x7518.
  The `jal` at 0x743c calls pciio_pio_write32 with a0=?, a1=[a0+344]+164, a2=?, a3=?.
  The `jal` at 0x744c calls pciio_pio_write32 with a0=?, a1=[a0+344]+160, a2=?, a3=?.
  The `jal` at 0x7530 calls pciio_pio_write32 with a0=?, a1=[a0+344]+164, a2=?, a3=?.
  The `jal` at 0x754c calls pciio_pio_write32 with a0=?, a1=[a0+344]+160, a2=?, a3=?.
  The `bne` branch at 0x73b8 targets 0x73d4, is taken when a3(=[a0+20216]:8) < at(=0xfa24e2) (signed), and falls through when a3(=[a0+20216]:8) >= at(=0xfa24e2) (signed).
  The `bne` branch at 0x73c4 targets 0x73d4, is taken when a4(=0x1029fa0) < a3(=[a0+20216]:8) (signed), and falls through when a4(=0x1029fa0) >= a3(=[a0+20216]:8) (signed).
  The `beq` branch at 0x73cc targets 0x73f4 and is always taken.
  The `bne` branch at 0x73e0 targets 0x74ac, is taken when a3(=[a0+20216]:8) < v1(=0x12b3123) (signed), and falls through when a3(=[a0+20216]:8) >= v1(=0x12b3123) (signed).
  The `bne` branch at 0x73e8 targets 0x762c, is taken when a6(?) != 0, and falls through when a6(?) == 0.
  The `beq` branch at 0x73f8 targets 0x7478 and is always taken.
  The `beq` branch at 0x7400 targets 0x7638, is taken when s6(=one of 0x0, 0x1) == 0, and falls through when s6(=one of 0x0, 0x1) != 0.
  The `bne` branch at 0x7418 targets 0x7434, is taken when t8(=0x11ffe89) != t9(?), and falls through when t8(=0x11ffe89) == t9(?).
  The `beq` branch at 0x742c targets 0x7460, is taken when t9(=0x8001866) == ra(?), and falls through when t9(=0x8001866) != ra(?).
  The `beq` branch at 0x7464 targets 0x75e0, is taken when s3(=one of 0x0, 0x1) == 0, and falls through when s3(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x7470 targets 0x74b0, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0x7478 targets 0x7400, is taken when s2(?) == v0(=0x1), and falls through when s2(?) != v0(=0x1).
  The `beq` branch at 0x7480 targets 0x75f0, is taken when s6(=one of 0x0, 0x1) == 0, and falls through when s6(=one of 0x0, 0x1) != 0.
  The `bne` branch at 0x7490 targets 0x7434, is taken when s8(=0x54fd8f) != a3(?), and falls through when s8(=0x54fd8f) == a3(?).
  The `bne` branch at 0x749c targets 0x7434, is taken when s7(=0x400166b) != a4(?), and falls through when s7(=0x400166b) == a4(?).
  The `beq` branch at 0x74a4 targets 0x7464 and is always taken.
  The `beq` branch at 0x74b8 targets 0x74d0 and is always taken.
  The `beq` branch at 0x74c8 targets 0x7564, is taken when s2(?) >= 0x6 (signed), and falls through when s2(?) < 0x6 (signed).
  The `beq` branch at 0x74d8 targets 0x75a0, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `beq` branch at 0x74e0 targets 0x75cc, is taken when s3(=one of 0x0, 0x1) == 0, and falls through when s3(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x74e8 targets 0x74c0, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x7508 targets 0x74c0, is taken when a7(?) == v0(=one of 0x0, 0x1), and falls through when a7(?) != v0(=one of 0x0, 0x1).
  The `bne` branch at 0x755c targets 0x74d0, is taken when s2(?) < 0x6 (signed), and falls through when s2(?) >= 0x6 (signed).
  The `bne` branch at 0x7564 targets 0x7570, is taken when s3(=one of 0x0, 0x1) != 0, and falls through when s3(=one of 0x0, 0x1) == 0.
  The `beq` branch at 0x756c targets 0x7694, is taken when s6(=one of 0x0, 0x1) == 0, and falls through when s6(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x75a0 targets 0x74c0, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x75bc targets 0x74c0, is taken when (a4(?) & 0x100) == 0, and falls through when (a4(?) & 0x100) != 0.
  The `beq` branch at 0x75c4 targets 0x750c and is always taken.
  The `bne` branch at 0x75cc targets 0x74e8, is taken when s6(=one of 0x0, 0x1) != 0, and falls through when s6(=one of 0x0, 0x1) == 0.
  The `beq` branch at 0x75d8 targets 0x74e8 and is always taken.
  The `bne` branch at 0x75e0 targets 0x7470, is taken when s6(=one of 0x0, 0x1) != 0, and falls through when s6(=one of 0x0, 0x1) == 0.
  The `beq` branch at 0x75e8 targets 0x74b4 and is always taken.
  The `beq` branch at 0x75f0 targets 0x7674, is taken when s3(=one of 0x0, 0x1) == 0, and falls through when s3(=one of 0x0, 0x1) != 0.
  The `bne` branch at 0x7608 targets 0x7434, is taken when a6(=0xacfd8f) != a7(?), and falls through when a6(=0xacfd8f) == a7(?).
  The `bne` branch at 0x761c targets 0x7434, is taken when a7(=0x4001693) != t0(?), and falls through when a7(=0x4001693) == t0(?).
  The `beq` branch at 0x7624 targets 0x7464 and is always taken.
  The `beq` branch at 0x7630 targets 0x74b0 and is always taken.
  The `beq` branch at 0x7638 targets 0x7674, is taken when s3(=one of 0x0, 0x1) == 0, and falls through when s3(=one of 0x0, 0x1) != 0.
  The `bne` branch at 0x7650 targets 0x7434, is taken when t0(=0x39ff83) != t1(?), and falls through when t0(=0x39ff83) == t1(?).
  The `bne` branch at 0x7664 targets 0x7434, is taken when t1(=0x8001892) != t2(?), and falls through when t1(=0x8001892) == t2(?).
  The `beq` branch at 0x766c targets 0x7464 and is always taken.
  The `bne` branch at 0x7678 targets 0x7434, is taken when t2(?) != s4(?), and falls through when t2(?) == s4(?).
  The `beq` branch at 0x7684 targets 0x7460, is taken when t3(?) == s5(?), and falls through when t3(?) != s5(?).
  The `beq` branch at 0x768c targets 0x7438 and is always taken.
  The `beq` branch at 0x7698 targets 0x7578 and is always taken.
  The return at 0x7598 has v0 = one of 0x0, 0x1.

- `kdsp_idbg_rad_dump_subsys` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0x76a0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0x76a0-0x78dc (572 bytes).
  It occupies 572 bytes.
  The `lw` at 0x76a0 loads 4 bytes from a0 (arg0 at entry) +0x15c.
  The `lw` at 0x76c8 loads 4 bytes from a0 (arg0 at entry) +0x170.
  The `lw` at 0x76cc loads 4 bytes from a0 (arg0 at entry) +0x16c.
  The `lw` at 0x76d8 loads 4 bytes from a0 (arg0 at entry) +0x178.
  The `lw` at 0x76dc loads 4 bytes from a0 (arg0 at entry) +0x174.
  The `lw` at 0x76e8 loads 4 bytes from a0 (arg0 at entry) +0x180.
  The `lw` at 0x76ec loads 4 bytes from a0 (arg0 at entry) +0x17c.
  The `lw` at 0x76f8 loads 4 bytes from a0 (arg0 at entry) +0x188.
  The `lw` at 0x76fc loads 4 bytes from a0 (arg0 at entry) +0x184.
  The `lw` at 0x7708 loads 4 bytes from a0 (arg0 at entry) +0x190.
  The `lw` at 0x770c loads 4 bytes from a0 (arg0 at entry) +0x18c.
  The `lw` at 0x7718 loads 4 bytes from a0 (arg0 at entry) +0x198.
  The `lw` at 0x771c loads 4 bytes from a0 (arg0 at entry) +0x194.
  The `lw` at 0x7728 loads 4 bytes from a0 (arg0 at entry) +0x1a0.
  The `lw` at 0x772c loads 4 bytes from a0 (arg0 at entry) +0x19c.
  The `lw` at 0x7738 loads 4 bytes from a0 (arg0 at entry) +0x1a8.
  The `lw` at 0x773c loads 4 bytes from a0 (arg0 at entry) +0x1a4.
  The `lw` at 0x7748 loads 4 bytes from a0 (arg0 at entry) +0x1ac.
  The `lw` at 0x7754 loads 4 bytes from a0 (arg0 at entry) +0x1b4.
  The `lw` at 0x7758 loads 4 bytes from a0 (arg0 at entry) +0x1b0.
  The `lw` at 0x7764 loads 4 bytes from a0 (arg0 at entry) +0x1bc.
  The `lw` at 0x7768 loads 4 bytes from a0 (arg0 at entry) +0x1b8.
  The `lw` at 0x7774 loads 4 bytes from a0 (arg0 at entry) +0x1c4.
  The `lw` at 0x7778 loads 4 bytes from a0 (arg0 at entry) +0x1c0.
  The `lw` at 0x7784 loads 4 bytes from a0 (arg0 at entry) +0x1cc.
  The `lw` at 0x7788 loads 4 bytes from a0 (arg0 at entry) +0x1c8.
  The `lw` at 0x7794 loads 4 bytes from a0 (arg0 at entry) +0x1d4.
  The `lw` at 0x7798 loads 4 bytes from a0 (arg0 at entry) +0x1d0.
  The `lw` at 0x77a4 loads 4 bytes from a0 (arg0 at entry) +0x1dc.
  The `lw` at 0x77a8 loads 4 bytes from a0 (arg0 at entry) +0x1d8.
  The `lw` at 0x77b4 loads 4 bytes from a0 (arg0 at entry) +0x1e8.
  The `lw` at 0x77b8 loads 4 bytes from a0 (arg0 at entry) +0x1e4.
  The `lw` at 0x77bc loads 4 bytes from a0 (arg0 at entry) +0x1e0.
  The `lw` at 0x77d0 loads 4 bytes from a0 (arg0 at entry) +0x4e58.
  The `lw` at 0x77d4 loads 4 bytes from a0 (arg0 at entry) +0x4e5c.
  The `lw` at 0x77e0 loads 4 bytes from a0 (arg0 at entry) +0x4e68.
  The `lw` at 0x77e4 loads 4 bytes from a0 (arg0 at entry) +0x4e60.
  The `lw` at 0x77f0 loads 4 bytes from a0 (arg0 at entry) +0x4e6c.
  The `lw` at 0x77f4 loads 4 bytes from a0 (arg0 at entry) +0x4e64.
  The `lw` at 0x7800 loads 4 bytes from a0 (arg0 at entry) +0x4e50.
  The `lw` at 0x7804 loads 4 bytes from a0 (arg0 at entry) +0x4e54.
  The `lw` at 0x7810 loads 4 bytes from a0 (arg0 at entry) +0x4e94.
  The `lw` at 0x7814 loads 4 bytes from a0 (arg0 at entry) +0x4e90.
  The `lw` at 0x7818 loads 4 bytes from a0 (arg0 at entry) +0x4e8c.
  The `lw` at 0x781c loads 4 bytes from a0 (arg0 at entry) +0x4e88.
  The `lw` at 0x7828 loads 4 bytes from a0 (arg0 at entry) +0x4ea4.
  The `lw` at 0x782c loads 4 bytes from a0 (arg0 at entry) +0x4ea0.
  The `lw` at 0x7830 loads 4 bytes from a0 (arg0 at entry) +0x4e9c.
  The `lw` at 0x7834 loads 4 bytes from a0 (arg0 at entry) +0x4e98.
  The `lw` at 0x7840 loads 4 bytes from a0 (arg0 at entry) +0x4eac.
  The `lw` at 0x7844 loads 4 bytes from a0 (arg0 at entry) +0x4ea8.
  The `lw` at 0x7848 loads 4 bytes from a0 (arg0 at entry) +0x4eb4.
  The `lw` at 0x784c loads 4 bytes from a0 (arg0 at entry) +0x4eb0.
  The `lw` at 0x7858 loads 4 bytes from a0 (arg0 at entry) +0x4e80.
  The `lw` at 0x785c loads 4 bytes from a0 (arg0 at entry) +0x4e7c.
  The `lw` at 0x7860 loads 4 bytes from a0 (arg0 at entry) +0x4e78.
  The `lw` at 0x7864 loads 4 bytes from a0 (arg0 at entry) +0x4e74.
  The `lw` at 0x7868 loads 4 bytes from a0 (arg0 at entry) +0x4e84.
  The `lw` at 0x7874 loads 4 bytes from a0 (arg0 at entry) +0x4ee8.
  The `lw` at 0x7878 loads 4 bytes from a0 (arg0 at entry) +0x4ee4.
  The `lw` at 0x787c loads 4 bytes from a0 (arg0 at entry) +0x4ee0.
  The `lw` at 0x7880 loads 4 bytes from a0 (arg0 at entry) +0x4edc.
  The `ld` at 0x788c loads 8 bytes from a0 (arg0 at entry) +0x4ef0.
  The `ld` at 0x7890 loads 8 bytes from a0 (arg0 at entry) +0x4ef8.
  The `lw` at 0x7894 loads 4 bytes from a0 (arg0 at entry) +0x4f00.
  The `lbu` at 0x78a0 loads 1 byte from a0 (arg0 at entry) +0x4f19.
  The `lbu` at 0x78a4 loads 1 byte from a0 (arg0 at entry) +0x4f13.
  The `jal` at 0x76c0 calls qprintf with a0=sym(.rodata), a1=[a0+348], a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x76d0 calls qprintf with a0=sym(.rodata), a1=[a0+364], a2=[a0+368], a3=?.
  The `jal` at 0x76e0 calls qprintf with a0=sym(.rodata), a1=[a0+372], a2=[a0+376], a3=?.
  The `jal` at 0x76f0 calls qprintf with a0=sym(.rodata), a1=[a0+380], a2=[a0+384], a3=?.
  The `jal` at 0x7700 calls qprintf with a0=sym(.rodata), a1=[a0+388], a2=[a0+392], a3=?.
  The `jal` at 0x7710 calls qprintf with a0=sym(.rodata), a1=[a0+396], a2=[a0+400], a3=?.
  The `jal` at 0x7720 calls qprintf with a0=sym(.rodata), a1=[a0+404], a2=[a0+408], a3=?.
  The `jal` at 0x7730 calls qprintf with a0=sym(.rodata), a1=[a0+412], a2=[a0+416], a3=?.
  The `jal` at 0x7740 calls qprintf with a0=sym(.rodata), a1=[a0+420], a2=[a0+424], a3=?.
  The `jal` at 0x774c calls qprintf with a0=sym(.rodata), a1=[a0+428], a2=?, a3=?.
  The `jal` at 0x775c calls qprintf with a0=sym(.rodata), a1=[a0+432], a2=[a0+436], a3=?.
  The `jal` at 0x776c calls qprintf with a0=sym(.rodata), a1=[a0+440], a2=[a0+444], a3=?.
  The `jal` at 0x777c calls qprintf with a0=sym(.rodata), a1=[a0+448], a2=[a0+452], a3=?.
  The `jal` at 0x778c calls qprintf with a0=sym(.rodata), a1=[a0+456], a2=[a0+460], a3=?.
  The `jal` at 0x779c calls qprintf with a0=sym(.rodata), a1=[a0+464], a2=[a0+468], a3=?.
  The `jal` at 0x77ac calls qprintf with a0=sym(.rodata), a1=[a0+472], a2=[a0+476], a3=?.
  The `jal` at 0x77c0 calls qprintf with a0=sym(.rodata), a1=[a0+480], a2=[a0+484], a3=[a0+488].
  The `jal` at 0x77c8 calls qprintf with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jal` at 0x77d8 calls qprintf with a0=sym(.rodata), a1=[a0+20060], a2=[a0+20056], a3=?.
  The `jal` at 0x77e8 calls qprintf with a0=sym(.rodata), a1=[a0+20064], a2=[a0+20072], a3=?.
  The `jal` at 0x77f8 calls qprintf with a0=sym(.rodata), a1=[a0+20068], a2=[a0+20076], a3=?.
  The `jal` at 0x7808 calls qprintf with a0=sym(.rodata), a1=[a0+20052], a2=[a0+20048], a3=?.
  The `jal` at 0x7820 calls qprintf with a0=sym(.rodata), a1=[a0+20104], a2=[a0+20108], a3=[a0+20112], a4=[a0+20116].
  The `jal` at 0x7838 calls qprintf with a0=sym(.rodata), a1=[a0+20120], a2=[a0+20124], a3=[a0+20128], a4=[a0+20132].
  The `jal` at 0x7850 calls qprintf with a0=sym(.rodata), a1=[a0+20144], a2=[a0+20148], a3=[a0+20136], a4=[a0+20140].
  The `jal` at 0x786c calls qprintf with a0=sym(.rodata), a1=[a0+20100], a2=[a0+20084], a3=[a0+20088], a4=[a0+20092], a5=[a0+20096].
  The `jal` at 0x7884 calls qprintf with a0=sym(.rodata), a1=[a0+20188], a2=[a0+20192], a3=[a0+20196], a4=[a0+20200].
  The `jal` at 0x7898 calls qprintf with a0=sym(.rodata), a1=[a0+20224], a2=[a0+20216]:8, a3=[a0+20208]:8.
  The `jal` at 0x78a8 calls qprintf with a0=sym(.rodata), a1=[a0+20243]:1, a2=[a0+20249]:1, a3=?.
  The `jal` at 0x78b4 calls qprintf with a0=sym(.rodata), a1=a0+19800, a2=?, a3=?.
  The `jal` at 0x78c0 calls qprintf with a0=sym(.rodata), a1=a0+19944, a2=?, a3=?.
  The return at 0x78d4 has v0 = ret(qprintf).

- `kdsp_idbg_rad_dump_cg` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0x78dc (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0x78dc-0x7958 (124 bytes).
  It occupies 124 bytes.
  The `lw` at 0x7908 loads 4 bytes from a0 (arg0 at entry) +0x158.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x150, including `lw` at 0x790c, `lw` at 0x7918.
  The `lw` at 0x792c loads 4 bytes from a0 (arg0 at entry) +0x174.
  The `lw` at 0x7930 loads 4 bytes from a0 (arg0 at entry) +0x160.
  The `lw` at 0x7938 loads 4 bytes from a0 (arg0 at entry) +0x15c.
  The `jal` at 0x78f8 calls qprintf with a0=sym(.rodata), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x7900 calls kdsp_idbg_dump_clockgen with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x7910 calls qprintf with a0=sym(.rodata), a1=[a0+336], a2=[a0+344], a3=?.
  The `jal` at 0x793c calls qprintf with a0=sym(.rodata), a1=?, a2=[a0+348], a3=[a0+352], a4=[a0+372].
  The return at 0x7950 has v0 = ret(qprintf).

- `kdsp_idbg_rad_dump_device` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0x7958 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0x7958-0x79cc (116 bytes).
  It occupies 116 bytes.
  The `lw` at 0x7980 loads 4 bytes from a0 (arg0 at entry) +0x1e4.
  The `lw` at 0x7988 loads 4 bytes from a0 (arg0 at entry) +0x1e0.
  The `lw` at 0x7994 loads 4 bytes from a0 (arg0 at entry) +0x214.
  The `lw` at 0x7998 loads 4 bytes from a0 (arg0 at entry) +0x210.
  The `lw` at 0x79a4 loads 4 bytes from a0 (arg0 at entry) +0x224.
  The `lw` at 0x79a8 loads 4 bytes from a0 (arg0 at entry) +0x220.
  The `ld` at 0x79ac loads 8 bytes from a0 (arg0 at entry) +0x218.
  The `jal` at 0x7968 calls kdsp_idbg_dump_device with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x7978 calls qprintf with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jal` at 0x798c calls qprintf with a0=sym(.rodata), a1=[a0+480], a2=[a0+484], a3=[a0+484].
  The `jal` at 0x799c calls qprintf with a0=sym(.rodata), a1=[a0+528], a2=[a0+532], a3=?.
  The `jal` at 0x79b0 calls qprintf with a0=sym(.rodata), a1=[a0+536]:8, a2=[a0+544], a3=[a0+548].
  The return at 0x79c4 has v0 = ret(qprintf).

- `kdsp_idbg_rad_addfuncs` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0x79cc (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0x79cc-0x7a64 (152 bytes).
  It occupies 152 bytes.
  The `jal` at 0x7a04 calls idbg_addfunc with a0=sym(.rodata)+3888, a1=sym(kdsp_idbg_rad_dump_subsys), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x7a24 calls idbg_addfunc with a0=sym(.rodata)+3896, a1=sym(kdsp_idbg_rad_dump_device), a2=?, a3=?.
  The `jal` at 0x7a44 calls idbg_addfunc with a0=sym(.rodata)+3904, a1=sym(kdsp_idbg_rad_dump_cg), a2=?, a3=?.
  The `bne` branch at 0x79e0 targets 0x79f8, is taken when v0(=[sym(.sdata)+52]) < 0x1 (signed), and falls through when v0(=[sym(.sdata)+52]) >= 0x1 (signed).
  The `beq` branch at 0x7a0c targets 0x7a1c, is taken when v0(=ret(idbg_addfunc)) == 0, and falls through when v0(=ret(idbg_addfunc)) != 0.
  The `beq` branch at 0x7a14 targets 0x79f0 and is always taken.
  The `beq` branch at 0x7a2c targets 0x7a3c, is taken when v0(=ret(idbg_addfunc)) == 0, and falls through when v0(=ret(idbg_addfunc)) != 0.
  The `beq` branch at 0x7a34 targets 0x79f0 and is always taken.
  The `beq` branch at 0x7a4c targets 0x7a5c, is taken when v0(=ret(idbg_addfunc)) == 0, and falls through when v0(=ret(idbg_addfunc)) != 0.
  The `beq` branch at 0x7a54 targets 0x79f0 and is always taken.
  The `beq` branch at 0x7a5c targets 0x79ec and is always taken.
  The return at 0x79f0 has v0 = one of 0x0, ret(idbg_addfunc).

- `kdsp_idbg_rad_delfuncs` in `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o` at 0x7a64 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/rad_dd.o`.
  Range: 0x7a64-0x7ab0 (76 bytes).
  It occupies 76 bytes.
  The `jal` at 0x7a88 calls idbg_delfunc with a0=sym(kdsp_idbg_rad_dump_subsys), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x7a94 calls idbg_delfunc with a0=sym(kdsp_idbg_rad_dump_cg), a1=?, a2=?, a3=?.
  The `jal` at 0x7aa0 calls idbg_delfunc with a0=sym(kdsp_idbg_rad_dump_device), a1=?, a2=?, a3=?.
  The `blez` branch at 0x7a74 targets 0x7a84, is taken when at(=[sym(.sdata)+52]-1) <= 0 (signed), and falls through when at(=[sym(.sdata)+52]-1) > 0 (signed).
  The `beq` branch at 0x7aa8 targets 0x7a7c and is always taken.
  The return at 0x7a7c has v0 = one of ?, ret(idbg_delfunc).
