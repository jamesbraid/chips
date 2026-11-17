# Readings: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`

One entry per routine, filed here from the reading batches by binary.

- `rad_ksync_notify` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x0-0x8 (8 bytes).
  It occupies 8 bytes.
  The return at 0x0 has v0 = ?.

- `rad_create_subsys` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x8-0x1d8 (464 bytes).
  It occupies 464 bytes.
  The `sw` at 0x9c stores 4 bytes to ret(kmem_zalloc) +0x731c.
  The `sd` at 0xa8 stores 8 bytes to ret(kmem_zalloc) +0x220.
  The `sd` at 0xb4 stores 8 bytes to ret(kmem_zalloc) +0x228.
  The `sh` at 0xc4 stores 2 bytes to ret(kmem_zalloc) +0x218.
  The `sh` at 0xd8 stores 2 bytes to ret(kmem_zalloc) +0x21a.
  2 such `lh` accesses load 2 bytes from ret(kmem_zalloc) +0x21a, including `lh` at 0xf0, `lh` at 0x188.
  The `jal` at 0x28 calls pciio_config_get with a0=a2 at entry (arg2), a1=0x8, a2=0x4, a3=a3 at entry (arg3).
  The `jal` at 0x3c calls kmem_zalloc with a0=0x7320, a1=0x0, a2=?, a3=?.
  The `jal` at 0x5c calls sprintf with a0=sp-144, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x6c calls sprintf with a0=sp-112, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x94 calls kdsp_init_resource with a0=ret(kmem_zalloc), a1=0x2000001e, a2=sp-144, a3=sp-112, a4=0x0, a5=sym(.data), a6=0x7320.
  The `jal` at 0xdc calls pciio_error_register with a0=a2 at entry (arg2), a1=sym(rad_error_handler), a2=ret(kmem_zalloc), a3=?, a4=a0 at entry (arg0).
  The `jal` at 0x114 calls pcibr_rrb_alloc with a0=a2 at entry (arg2), a1=sp-80, a2=sp-76, a3=?, a5=one of 0x2, 0x3, a7=0x3.
  The `jal` at 0x130 calls hwgraph_char_device_add with a0=a2 at entry (arg2), a1=sym(.rodata), a2=sym(.rodata), a3=sp-72.
  The `jal` at 0x15c calls device_info_set with a0=?, a1=ret(kmem_zalloc), a2=?, a3=?.
  The `jal` at 0x180 calls device_inventory_add with a0=?, a1=0xa, a2=0x5, a3=-0x1, a4=0x0.
  The `jal` at 0x1a0 calls kdsp_add_subsys with a0=ret(kmem_zalloc), a1=one of 0x0, 0x64, a2=?, a3=?.
  The `jal` at 0x1c8 calls cmn_err with a0=0x1, a1=sym(.rodata), a2=a2 at entry (arg2), a3=?.
  The `bne` branch at 0x44 targets 0x54, is taken when v0(=ret(kmem_zalloc)) != 0, and falls through when v0(=ret(kmem_zalloc)) == 0.
  The `beq` branch at 0x4c targets 0x144 and is always taken.
  The `bltz` branch at 0x11c targets 0x1bc, is taken when v0(=ret(pcibr_rrb_alloc)) < 0 (signed), and falls through when v0(=ret(pcibr_rrb_alloc)) >= 0 (signed).
  The `beq` branch at 0x138 targets 0x158, is taken when v0(=ret(hwgraph_char_device_add)) == 0, and falls through when v0(=ret(hwgraph_char_device_add)) != 0.
  The `beq` branch at 0x1b4 targets 0x144 and is always taken.
  The `beq` branch at 0x1d0 targets 0x124 and is always taken.
  The return at 0x150 has v0 = one of 0x0, 0x1.

- `rad_open` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x1d8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x1d8-0x1e0 (8 bytes).
  It occupies 8 bytes.
  The return at 0x1d8 has v0 = 0x0.

- `rad_ioctl` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x1e0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x1e0-0x7fc (1564 bytes).
  It occupies 1564 bytes.
  The `sw` at 0x254 stores 4 bytes to a5 (arg5 at entry) +0x0.
  5 such `lh` accesses load 2 bytes from ret(hwgraph_fastinfo_get) +0x21a, including `lh` at 0x28c, `lh` at 0x34c, `lh` at 0x438.
  The `lbu` at 0x2b0 loads 1 byte from ?.
  The `sw` at 0x2b8 stores 4 bytes to ?.
  2 such `lw` accesses load 4 bytes from ret(hwgraph_fastinfo_get) +0x7274, including `lw` at 0x2ec, `lw` at 0x36c.
  6 such `sw` accesses store 4 bytes to ret(hwgraph_fastinfo_get) +0x7318, including `sw` at 0x358, `sw` at 0x57c, `sw` at 0x6e0.
  The `sw` at 0x38c stores 4 bytes to ret(hwgraph_fastinfo_get) +0x7274.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0x3c4, `ld` at 0x700.
  The `ll` at 0x3d8 loads 4 bytes from sym(fastick_callback_required_flags) +0x0.
  The `sc` at 0x3e0 stores 4 bytes to sym(fastick_callback_required_flags) +0x0.
  The `lw` at 0x408 loads 4 bytes from ret(hwgraph_fastinfo_get) +0x2cc.
  The `lw` at 0x418 loads 4 bytes from ret(hwgraph_fastinfo_get) +0x2d0.
  The `sw` at 0x464 stores 4 bytes to ret(hwgraph_fastinfo_get) +0x2d0.
  The `sw` at 0x468 stores 4 bytes to ret(hwgraph_fastinfo_get) +0x2cc.
  The `sb` at 0x46c stores 1 byte to ret(hwgraph_fastinfo_get) +0x7303.
  The `lw` at 0x594 loads 4 bytes from ret(hwgraph_fastinfo_get) +0x731c.
  The `ld` at 0x5b8 loads 8 bytes from ret(hwgraph_fastinfo_get) +0x228.
  The `ld` at 0x61c loads 8 bytes from ret(hwgraph_fastinfo_get) +0x220.
  The `lw` at 0x710 loads 4 bytes from ret(hwgraph_fastinfo_get) +0x7318.
  The `jal` at 0x204 calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x2c4 calls copyout with a0=sp-120, a1=a2 at entry (arg2), a2=0x14, a3=?, a5=[ret(hwgraph_fastinfo_get)+538]:2.
  The `jal` at 0x2f4 calls copyout with a0=sp-96, a1=a2 at entry (arg2), a2=0x4, a3=?.
  The `jal` at 0x328 calls copyin with a0=a2 at entry (arg2), a1=sp-124, a2=0x4, a3=?.
  The `jal` at 0x388 calls rad_vl_write_MUX_SEL with a0=ret(hwgraph_fastinfo_get), a1=?, a2=?, a3=-0x201, a7=[ret(hwgraph_fastinfo_get)+538]:2.
  The `jal` at 0x3b4 calls strncmp with a0=?, a1=sym(.rodata), a2=0x3, a3=?.
  The `jal` at 0x3f8 calls update_ust with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x400 calls get_ust_nano with a0=sp-288, a1=?, a2=?, a3=?.
  The `jal` at 0x420 calls copyout with a0=sp-288, a1=a2 at entry (arg2), a2=0x18, a3=?, a6=[ret(hwgraph_fastinfo_get)+720], a7=[ret(hwgraph_fastinfo_get)+716].
  The `jal` at 0x478 calls curproc_abi with a0=0x6b730002, a1=?, a2=0x6d680000, a3=?.
  The `jal` at 0x498 calls copyin_xlate with a0=a2 at entry (arg2), a1=sp-264, a2=0x44, a3=sym(irix5_to_kstat_t), a4=ret(curproc_abi), a5=0x4, a6=0x1.
  The `jal` at 0x4b0 calls device_controller_num_get with a0=a0 at entry (arg0), a1=?, a2=0x6d687767, a3=?.
  The `jal` at 0x4d0 calls sprintf with a0=ret(hwgraph_fastinfo_get)+300, a1=sym(.rodata), a2=ret(device_controller_num_get), a3=?.
  The `jal` at 0x4e4 calls sprintf with a0=ret(hwgraph_fastinfo_get)+332, a1=sym(.rodata), a2=ret(device_controller_num_get), a3=?.
  The `jal` at 0x51c calls kdsp_set_default_subsys_pri with a0=ret(hwgraph_fastinfo_get), a1=ret(device_controller_num_get)+100, a2=one of 0x7, 0xd, a3=?, a7=[ret(hwgraph_fastinfo_get)+538]:2.
  The `jal` at 0x540 calls kdsp_set_default_subsys_pri with a0=ret(hwgraph_fastinfo_get), a1=ret(device_controller_num_get), a2=0x7, a3=?, a7=[ret(hwgraph_fastinfo_get)+538]:2.
  The `jal` at 0x554 calls sprintf with a0=sp-192, a1=sym(.rodata), a2=ret(device_controller_num_get), a3=?.
  The `jal` at 0x58c calls hwgraph_path_add with a0=[sym(hwgraph_root)], a1=sym(.rodata), a2=sp-160, a3=one of 0x4, 0x7, a7=[ret(hwgraph_fastinfo_get)+538]:2.
  The `jal` at 0x5a0 calls hwgraph_edge_add with a0=?, a1=[ret(hwgraph_fastinfo_get)+29468], a2=ret(hwgraph_fastinfo_get)+300, a3=?.
  The `jal` at 0x5bc calls sprintf with a0=sp-152, a1=sym(.rodata), a2=[ret(hwgraph_fastinfo_get)+552]:8, a3=?.
  The `jal` at 0x5c4 calls strlen with a0=sp-152, a1=?, a2=?, a3=?.
  The `jal` at 0x5d0 calls kern_malloc with a0=ret(strlen)+1, a1=?, a2=?, a3=?.
  The `jal` at 0x5e4 calls strcpy with a0=ret(kern_malloc), a1=sp-152, a2=?, a3=?.
  The `jal` at 0x5f8 calls hwgraph_info_add_LBL with a0=[ret(hwgraph_fastinfo_get)+29468], a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x60c calls hwgraph_info_export_LBL with a0=[ret(hwgraph_fastinfo_get)+29468], a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x620 calls sprintf with a0=sp-152, a1=sym(.rodata), a2=[ret(hwgraph_fastinfo_get)+544]:8, a3=?.
  The `jal` at 0x628 calls strlen with a0=sp-152, a1=?, a2=?, a3=?.
  The `jal` at 0x634 calls kern_malloc with a0=ret(strlen)+1, a1=?, a2=?, a3=?.
  The `jal` at 0x644 calls strcpy with a0=ret(kern_malloc), a1=sp-152, a2=?, a3=?.
  The `jal` at 0x654 calls hwgraph_info_add_LBL with a0=[ret(hwgraph_fastinfo_get)+29468], a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x664 calls hwgraph_info_export_LBL with a0=[ret(hwgraph_fastinfo_get)+29468], a1=sym(.rodata), a2=(ret(strlen)+1 << 0x0), a3=?.
  The `jal` at 0x66c calls strlen with a0=ret(hwgraph_fastinfo_get)+300, a1=?, a2=?, a3=?.
  The `jal` at 0x678 calls kern_malloc with a0=ret(strlen)+1, a1=?, a2=?, a3=?.
  The `jal` at 0x688 calls strcpy with a0=ret(kern_malloc), a1=ret(hwgraph_fastinfo_get)+300, a2=?, a3=?.
  The `jal` at 0x69c calls hwgraph_info_add_LBL with a0=[ret(hwgraph_fastinfo_get)+29468], a1=sym(.rodata), a2=ret(kern_malloc), a3=?.
  The `jal` at 0x6ac calls hwgraph_info_export_LBL with a0=[ret(hwgraph_fastinfo_get)+29468], a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x6bc calls hwgraph_edge_get with a0=[ret(hwgraph_fastinfo_get)+29468], a1=sym(.rodata), a2=sp-128, a3=?.
  The `jal` at 0x6f4 calls rad_stop_status_dma with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x708 calls sprintf with a0=sp-264, a1=ret(hwgraph_fastinfo_get)+300, a2=?, a3=?.
  The `jal` at 0x714 calls curproc_abi with a0=?, a1=?, a2=?, a3=?, a4=[ret(hwgraph_fastinfo_get)+29464].
  The `jal` at 0x734 calls xlate_copyout with a0=sp-264, a1=a2 at entry (arg2), a2=0x44, a3=sym(kstat_t_to_irix5), a4=ret(curproc_abi), a5=0x4, a6=0x1.
  The `jal` at 0x74c calls rad_vl_write_MUX_SEL with a0=ret(hwgraph_fastinfo_get), a1=(a2 << 0x0), a2=?, a3=?.
  The `jal` at 0x76c calls ksync_attach with a0=?, a1=sp-192, a2=?, a3=sym(rad_ksync_notify), a4=-0x1.
  The `jal` at 0x7bc calls cmn_err with a0=0x4, a1=sym(.rodata), a2=a0 at entry (arg0), a3=?.
  The `jal` at 0x7dc calls cmn_err with a0=0x4, a1=sym(.rodata), a2=a0 at entry (arg0), a3=ret(device_controller_num_get).
  The `jal` at 0x7ec calls cmn_err with a0=0x1, a1=sym(.rodata), a2=[sym(showconfig)], a3=?.
  The `beq` branch at 0x20c targets 0x7b0, is taken when v0(=ret(hwgraph_fastinfo_get)) == 0, and falls through when v0(=ret(hwgraph_fastinfo_get)) != 0.
  The `bne` branch at 0x218 targets 0x274, is taken when s1(=a1) < 0x270c (signed), and falls through when s1(=a1) >= 0x270c (signed).
  The `bne` branch at 0x220 targets 0x3f8, is taken when v0(?) != 0, and falls through when v0(?) == 0.
  The `bne` branch at 0x230 targets 0x304, is taken when s1(=a1) < a0(=0x6b730002) (signed), and falls through when s1(=a1) >= a0(=0x6b730002) (signed).
  The `beq` branch at 0x238 targets 0x478, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x244 targets 0x4b0, is taken when s1(=a1) == a2(=0x6d687767), and falls through when s1(=a1) != a2(=0x6d687767).
  The `bne` branch at 0x278 targets 0x2d4, is taken when s1(=a1) < 0x270a (signed), and falls through when s1(=a1) >= 0x270a (signed).
  The `beq` branch at 0x284 targets 0x45c, is taken when s1(=a1) >= 0x270b (signed), and falls through when s1(=a1) < 0x270b (signed).
  The `bne` branch at 0x2b4 targets 0x29c, is taken when v0(?) < 0x4 (signed), and falls through when v0(?) >= 0x4 (signed).
  The `beq` branch at 0x2cc targets 0x24c and is always taken.
  The `bne` branch at 0x2d4 targets 0x398, is taken when t0(?) != 0, and falls through when t0(?) == 0.
  The `beq` branch at 0x2dc targets 0x24c, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x2fc targets 0x24c and is always taken.
  The `bne` branch at 0x30c targets 0x430, is taken when s1(=a1) < a0(=0x6b730001) (signed), and falls through when s1(=a1) >= a0(=0x6b730001) (signed).
  The `bne` branch at 0x318 targets 0x24c, is taken when a0(=0x6b730001) < s1(=a1) (signed), and falls through when a0(=0x6b730001) >= s1(=a1) (signed).
  The `bne` branch at 0x334 targets 0x24c, is taken when v0(=ret(copyin)) != 0, and falls through when v0(=ret(copyin)) == 0.
  The `beq` branch at 0x348 targets 0x77c, is taken when t8(?) == a3(=0x1), and falls through when t8(?) != a3(=0x1).
  The `beq` branch at 0x350 targets 0x798, is taken when a7(=[ret(hwgraph_fastinfo_get)+538]:2) == v0(=0xc), and falls through when a7(=[ret(hwgraph_fastinfo_get)+538]:2) != v0(=0xc).
  The `bne` branch at 0x360 targets 0x24c, is taken when a7(=[ret(hwgraph_fastinfo_get)+538]:2) != ra(=0xd), and falls through when a7(=[ret(hwgraph_fastinfo_get)+538]:2) == ra(=0xd).
  The `beq` branch at 0x390 targets 0x250 and is always taken.
  The `bne` branch at 0x398 targets 0x248, is taken when s1(=a1) != a2(=0x2708), and falls through when s1(=a1) == a2(=0x2708).
  The `beq` branch at 0x3a0 targets 0x3d0, is taken when a3(=[sym(kdsp_sstab)]:8) == 0, and falls through when a3(=[sym(kdsp_sstab)]:8) != 0.
  The `beq` branch at 0x3bc targets 0x6f4, is taken when v0(=ret(strncmp)) == 0, and falls through when v0(=ret(strncmp)) != 0.
  The `bne` branch at 0x3c8 targets 0x3ac, is taken when s0(?) != 0, and falls through when s0(?) == 0.
  The `beql` branch at 0x3e4 targets 0x3d8, is taken when (a2(=[sym(fastick_callback_required_flags)]) & a4(=-0x3)) == 0, and falls through when (a2(=[sym(fastick_callback_required_flags)]) & a4(=-0x3)) != 0; its branch-likely delay slot `nop` at 0x3e8 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x3f0 targets 0x24c and is always taken.
  The `beq` branch at 0x428 targets 0x24c and is always taken.
  The `bne` branch at 0x430 targets 0x24c, is taken when s1(=a1) != t0(=0x270d), and falls through when s1(=a1) == t0(=0x270d).
  The `beq` branch at 0x440 targets 0x74c, is taken when v0(=[ret(hwgraph_fastinfo_get)+538]:2) == t1(=0x7), and falls through when v0(=[ret(hwgraph_fastinfo_get)+538]:2) != t1(=0x7).
  The `beq` branch at 0x44c targets 0x74c, is taken when v0(=[ret(hwgraph_fastinfo_get)+538]:2) == t2(=0xd), and falls through when v0(=[ret(hwgraph_fastinfo_get)+538]:2) != t2(=0xd).
  The `beq` branch at 0x454 targets 0x24c and is always taken.
  The `bne` branch at 0x45c targets 0x24c, is taken when s1(=a1) != t3(=0x270b), and falls through when s1(=a1) == t3(=0x270b).
  The `beq` branch at 0x470 targets 0x24c and is always taken.
  The `beq` branch at 0x4a0 targets 0x704, is taken when v0(=ret(copyin_xlate)) == 0, and falls through when v0(=ret(copyin_xlate)) != 0.
  The `beq` branch at 0x4a8 targets 0x24c and is always taken.
  The `bltz` branch at 0x4b8 targets 0x7cc, is taken when v0(=ret(device_controller_num_get)) < 0 (signed), and falls through when v0(=ret(device_controller_num_get)) >= 0 (signed).
  The `beq` branch at 0x4f4 targets 0x51c, is taken when a7(=[ret(hwgraph_fastinfo_get)+538]:2) == a2(=0xd), and falls through when a7(=[ret(hwgraph_fastinfo_get)+538]:2) != a2(=0xd).
  The `bne` branch at 0x500 targets 0x52c, is taken when a7(=[ret(hwgraph_fastinfo_get)+538]:2) != a2(=0x7), and falls through when a7(=[ret(hwgraph_fastinfo_get)+538]:2) == a2(=0x7).
  The `beq` branch at 0x508 targets 0x530, is taken when v0(=[sym(.sbss)]) == 0, and falls through when v0(=[sym(.sbss)]) != 0.
  The `beq` branch at 0x510 targets 0x530, is taken when s1(=ret(device_controller_num_get)) == v0(=[sym(.sbss)]), and falls through when s1(=ret(device_controller_num_get)) != v0(=[sym(.sbss)]).
  The `beq` branch at 0x524 targets 0x54c and is always taken.
  The `beq` branch at 0x564 targets 0x6e0, is taken when a7(=[ret(hwgraph_fastinfo_get)+538]:2) == a2(=0xc), and falls through when a7(=[ret(hwgraph_fastinfo_get)+538]:2) != a2(=0xc).
  The `beq` branch at 0x570 targets 0x6dc, is taken when a7(=[ret(hwgraph_fastinfo_get)+538]:2) == a3(=0x7), and falls through when a7(=[ret(hwgraph_fastinfo_get)+538]:2) != a3(=0x7).
  The `beq` branch at 0x5ac targets 0x6ec, is taken when v0(=ret(hwgraph_edge_add)) == a2(=0x1), and falls through when v0(=ret(hwgraph_edge_add)) != a2(=0x1).
  The `beq` branch at 0x6c4 targets 0x75c, is taken when v0(=ret(hwgraph_edge_get)) == 0, and falls through when v0(=ret(hwgraph_edge_get)) != 0.
  The `bne` branch at 0x6cc targets 0x7ec, is taken when a2(=[sym(showconfig)]) != 0, and falls through when a2(=[sym(showconfig)]) == 0.
  The `beq` branch at 0x6d4 targets 0x24c and is always taken.
  The `beq` branch at 0x6e4 targets 0x580 and is always taken.
  The `beq` branch at 0x6ec targets 0x258 and is always taken.
  The `beq` branch at 0x6fc targets 0x3c8 and is always taken.
  The `beq` branch at 0x740 targets 0x24c and is always taken.
  The `beq` branch at 0x754 targets 0x24c and is always taken.
  The `beq` branch at 0x774 targets 0x6d4 and is always taken.
  The `beq` branch at 0x77c targets 0x7a8, is taken when a7(=[ret(hwgraph_fastinfo_get)+538]:2) == v0(=0xc), and falls through when a7(=[ret(hwgraph_fastinfo_get)+538]:2) != v0(=0xc).
  The `beq` branch at 0x788 targets 0x7a8, is taken when a7(=[ret(hwgraph_fastinfo_get)+538]:2) == a2(=0x7), and falls through when a7(=[ret(hwgraph_fastinfo_get)+538]:2) != a2(=0x7).
  The `beq` branch at 0x790 targets 0x35c and is always taken.
  The `beq` branch at 0x79c targets 0x35c and is always taken.
  The `beq` branch at 0x7a8 targets 0x35c and is always taken.
  The `beq` branch at 0x7c4 targets 0x258 and is always taken.
  The `beq` branch at 0x7e4 targets 0x24c and is always taken.
  The `beq` branch at 0x7f4 targets 0x6d4 and is always taken.
  The return at 0x26c has v0 = one of ?, 0x0, 0x5.
  The instructions from 0x748 to 0x748 are not reached by any path from the entry, and their branches are not listed.
  The instructions from 0x7a4 to 0x7a4 are not reached by any path from the entry, and their branches are not listed.

- `rad_close` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x7fc (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x7fc-0x850 (84 bytes).
  It occupies 84 bytes.
  The `sb` at 0x818 stores 1 byte to ret(hwgraph_fastinfo_get) +0x7303.
  The `sw` at 0x81c stores 4 bytes to ret(hwgraph_fastinfo_get) +0x2d0.
  The `sw` at 0x820 stores 4 bytes to ret(hwgraph_fastinfo_get) +0x2cc.
  The `jal` at 0x804 calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x840 calls cmn_err with a0=0x4, a1=sym(.rodata), a2=a0 at entry (arg0), a3=ret(hwgraph_fastinfo_get), a4=0x1.
  The `beq` branch at 0x810 targets 0x834, is taken when v0(=ret(hwgraph_fastinfo_get)) == 0, and falls through when v0(=ret(hwgraph_fastinfo_get)) != 0.
  The `beq` branch at 0x848 targets 0x828 and is always taken.
  The return at 0x82c has v0 = one of 0x0, 0x5.

- `rad_start_subsys` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x850 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x850-0x1050 (2048 bytes).
  It occupies 2048 bytes.
  The `sw` at 0x864 stores 4 bytes to sym(.bss) +0x158.
  The `sw` at 0x868 stores 4 bytes to sym(.bss) +0x150.
  The `sw` at 0x874 stores 4 bytes to sym(.bss) +0x148.
  The `sw` at 0x880 stores 4 bytes to sym(.bss) +0x140.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x731c, including `lw` at 0x88c, `lw` at 0x8a0.
  32 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x228, including `ld` at 0x8a8, `ld` at 0x8fc, `ld` at 0x90c.
  5 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x7240, including `sw` at 0x8b0, `sw` at 0x904, `sw` at 0xa1c.
  5 such `sw` accesses store 4 bytes to [a0+552]:8 +0x80, including `sw` at 0x8bc, `sw` at 0x908, `sw` at 0xa28.
  4 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x7240, including `lw` at 0x8c0, `lw` at 0xa0c, `lw` at 0xa3c.
  The `sw` at 0x918 stores 4 bytes to [a0+552]:8 +0x74.
  The `sw` at 0x928 stores 4 bytes to [a0+552]:8 +0x78.
  12 such `lh` accesses load 2 bytes from a0 (arg0 at entry) +0x21a, including `lh` at 0x92c, `lh` at 0x96c, `lh` at 0x9a4.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x7248, including `sw` at 0x940, `sw` at 0xed4.
  The `sw` at 0x948 stores 4 bytes to [a0+552]:8 +0x4c.
  The `sw` at 0x954 stores 4 bytes to a0 (arg0 at entry) +0x724c.
  The `sw` at 0x958 stores 4 bytes to [a0+552]:8 +0x58.
  The `sw` at 0x964 stores 4 bytes to a0 (arg0 at entry) +0x7250.
  The `sw` at 0x968 stores 4 bytes to [a0+552]:8 +0x48.
  The `sw` at 0x988 stores 4 bytes to a0 (arg0 at entry) +0x7258.
  The `sw` at 0x98c stores 4 bytes to [a0+552]:8 +0x54.
  The `sw` at 0x99c stores 4 bytes to a0 (arg0 at entry) +0x7254.
  The `sw` at 0x9a0 stores 4 bytes to [a0+552]:8 +0x44.
  The `sw` at 0x9bc stores 4 bytes to a0 (arg0 at entry) +0x725c.
  The `sw` at 0x9c0 stores 4 bytes to [a0+552]:8 +0x50.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x7244, including `sw` at 0x9ec, `sw` at 0xe8c.
  2 such `sw` accesses store 4 bytes to [a0+552]:8 +0x70, including `sw` at 0x9f0, `sw` at 0xe90.
  The `sw` at 0xa00 stores 4 bytes to [a0+552]:8 +0xb8.
  The `sw` at 0xa08 stores 4 bytes to [a0+552]:8 +0xbc.
  The `sw` at 0xa38 stores 4 bytes to [a0+552]:8 +0xa0.
  The `sw` at 0xac8 stores 4 bytes to a0 (arg0 at entry) +0x72c4.
  The `sw` at 0xacc stores 4 bytes to a0 (arg0 at entry) +0x72c0.
  The `sw` at 0xad4 stores 4 bytes to a0 (arg0 at entry) +0x72b4.
  The `sw` at 0xad8 stores 4 bytes to a0 (arg0 at entry) +0x72b0.
  The `sw` at 0xadc stores 4 bytes to a0 (arg0 at entry) +0x72bc.
  The `sw` at 0xae4 stores 4 bytes to a0 (arg0 at entry) +0x72b8.
  The `sw` at 0xaf4 stores 4 bytes to a0 (arg0 at entry) +0x7260.
  The `sw` at 0xaf8 stores 4 bytes to [a0+552]:8 +0x7c.
  The `sd` at 0xb48 stores 8 bytes to a0 (arg0 at entry) +0xdb0.
  The `sd` at 0xb50 stores 8 bytes to a0 (arg0 at entry) +0xdc0.
  The `sw` at 0xb58 stores 4 bytes to a0 (arg0 at entry) +0xfb0.
  The `sd` at 0xb64 stores 8 bytes to a0 (arg0 at entry) +0xdb8.
  The `sd` at 0xb84 stores 8 bytes to a0 (arg0 at entry) +0xf68.
  The `sd` at 0xba0 stores 8 bytes to a0 (arg0 at entry) +0x10d8.
  The `sd` at 0xba8 stores 8 bytes to a0 (arg0 at entry) +0x10d0.
  The `sd` at 0xbb0 stores 8 bytes to a0 (arg0 at entry) +0x10c8.
  The `sw` at 0xbb8 stores 4 bytes to a0 (arg0 at entry) +0x12c8.
  The `sd` at 0xbc0 stores 8 bytes to a0 (arg0 at entry) +0x1280.
  The `sd` at 0xc08 stores 8 bytes to a0 (arg0 at entry) +0x13e8.
  The `sd` at 0xc10 stores 8 bytes to a0 (arg0 at entry) +0x13e0.
  The `sw` at 0xc18 stores 4 bytes to a0 (arg0 at entry) +0x15e0.
  The `sd` at 0xc38 stores 8 bytes to a0 (arg0 at entry) +0x13f0.
  The `sd` at 0xc68 stores 8 bytes to a0 (arg0 at entry) +0x1708.
  The `sd` at 0xc6c stores 8 bytes to a0 (arg0 at entry) +0x1700.
  The `sd` at 0xc74 stores 8 bytes to a0 (arg0 at entry) +0x16f8.
  The `sw` at 0xc7c stores 4 bytes to a0 (arg0 at entry) +0x18f8.
  The `sd` at 0xc9c stores 8 bytes to a0 (arg0 at entry) +0x18b0.
  The `sw` at 0xcbc stores 4 bytes to a0 (arg0 at entry) +0x1c10.
  The `sd` at 0xcc8 stores 8 bytes to a0 (arg0 at entry) +0x1a10.
  The `sd` at 0xcd4 stores 8 bytes to a0 (arg0 at entry) +0x1a20.
  The `sd` at 0xcf4 stores 8 bytes to a0 (arg0 at entry) +0x1a18.
  The `sd` at 0xd14 stores 8 bytes to a0 (arg0 at entry) +0x1d38.
  The `sw` at 0xd18 stores 4 bytes to a0 (arg0 at entry) +0x1f28.
  The `sd` at 0xd28 stores 8 bytes to a0 (arg0 at entry) +0x1ee0.
  The `sd` at 0xd2c stores 8 bytes to a0 (arg0 at entry) +0x1d30.
  The `sd` at 0xd38 stores 8 bytes to a0 (arg0 at entry) +0x1d28.
  The `ld` at 0xde8 loads 8 bytes from a0 (arg0 at entry) +0x58.
  The `ld` at 0xe1c loads 8 bytes from ?.
  2 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x1f8, including `sd` at 0xe50, `sd` at 0x1014.
  The `sd` at 0xe58 stores 8 bytes to a0 (arg0 at entry) +0x200.
  The `lw` at 0xe7c loads 4 bytes from a0 (arg0 at entry) +0x7244.
  3 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x726c, including `sw` at 0xee0, `sw` at 0xf40, `sw` at 0xf90.
  3 such `sw` accesses store 4 bytes to [a0+552]:8 +0x8c, including `sw` at 0xee4, `sw` at 0xf44, `sw` at 0xf94.
  3 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x7270, including `sw` at 0xf00, `sw` at 0xf34, `sw` at 0xf84.
  3 such `sw` accesses store 4 bytes to [a0+552]:8 +0x90, including `sw` at 0xf08, `sw` at 0xf38, `sw` at 0xf88.
  3 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x7268, including `sw` at 0xf4c, `sw` at 0xf9c, `sw` at 0xff8.
  3 such `sw` accesses store 4 bytes to [a0+552]:8 +0x88, including `sw` at 0xf50, `sw` at 0xfa0, `sw` at 0x1000.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x7264, including `sw` at 0xf58, `sw` at 0xfa8.
  2 such `sw` accesses store 4 bytes to [a0+552]:8 +0x84, including `sw` at 0xf5c, `sw` at 0xfb0.
  3 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x7274, including `sw` at 0xf68, `sw` at 0xfbc, `sw` at 0x1040.
  2 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x7302, including `sb` at 0xf74, `sb` at 0x104c.
  The `lw` at 0x1030 loads 4 bytes from a0 (arg0 at entry) +0x7274.
  The `jal` at 0x888 calls pciio_config_set with a0=[a0+29468], a1=0x4, a2=0x4, a3=0x6.
  The `jal` at 0x89c calls pciio_config_set with a0=[a0+29468], a1=0xc, a2=0x4, a3=-0x1.
  The `jal` at 0x8b8 calls us_delay with a0=0x3e8, a1=-0x1, a2=[a0+552]:8, a3=?.
  The `jal` at 0xa24 calls us_delay with a0=0x3e8, a1=?, a2=?, a3=[a0+552]:8, a4=-0xf01, a5=0xffffffff9fffffff, a6=[a0+552]:8, a7=[a0+552]:8.
  The `jal` at 0xa84 calls us_delay with a0=0x3e8, a1=?, a2=?, a3=?.
  The `jal` at 0xafc calls rad_init_subsys with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xb38 calls rad_create_device with a0=a0 at entry (arg0), a1=a0+3416, a2=0x0, a3=0x400, a4=0x0, a5=sym(.rodata), a6=sym(.rodata), a7=0x2.
  The `jal` at 0xb90 calls rad_create_device with a0=a0 at entry (arg0), a1=a0+4208, a2=0x1, a3=0x400, a4=0x1, a5=sym(.rodata), a6=sym(.rodata), a7=0x2.
  The `jal` at 0xbec calls rad_create_device with a0=a0 at entry (arg0), a1=a0+5000, a2=0x0, a3=0x400, a4=0x2, a5=sym(.rodata), a6=sym(.rodata), a7=0x2.
  The `jal` at 0xc44 calls rad_create_device with a0=a0 at entry (arg0), a1=a0+5792, a2=0x1, a3=0x400, a4=0x3, a5=sym(.rodata), a6=sym(.rodata), a7=0x2.
  The `jal` at 0xca8 calls rad_create_device with a0=a0 at entry (arg0), a1=a0+6584, a2=0x0, a3=0x1000, a4=0x4, a5=sym(.rodata), a6=sym(.rodata), a7=0x8.
  The `jal` at 0xd00 calls rad_create_device with a0=a0 at entry (arg0), a1=a0+7376, a2=0x1, a3=0x1000, a4=0x5, a5=sym(.rodata), a6=sym(.rodata), a7=0x8.
  The `jal` at 0xd34 calls rad_create_mclks with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xd54 calls rad_create_clockgen with a0=a0+25688, a1=a0+3416, a2=0x0, a3=a0+1176.
  The `jal` at 0xd6c calls rad_create_clockgen with a0=a0+26240, a1=a0+4208, a2=0x1, a3=a0+1176.
  The `jal` at 0xd84 calls rad_create_clockgen with a0=a0+27896, a1=a0+5000, a2=0x4, a3=a0+2072.
  The `jal` at 0xda0 calls rad_create_clockgen with a0=a0+26792, a1=a0+5792, a2=0x2, a3=a0+1176.
  The `jal` at 0xdb8 calls rad_create_clockgen with a0=a0+28448, a1=a0+6584, a2=0x5, a3=a0+1624.
  The `jal` at 0xdd0 calls rad_create_clockgen with a0=a0+27344, a1=a0+7376, a2=0x3, a3=a0+1176.
  The `jal` at 0xde0 calls rad_create_ifs with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xdf8 calls rad_start_device with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xe28 calls rad_create_subcodes with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xe34 calls kdsp_map_resource with a0=a0 at entry (arg0), a1=0x0, a2=?, a3=?.
  The `jal` at 0xe5c calls us_delay with a0=0xf4240, a1=(a0 + one of 0x1070, 0x16a0), a2=?, a3=?.
  The `jal` at 0xf70 calls rad_vl_write_MUX_SEL with a0=a0 at entry (arg0), a1=0x0, a2=?, a3=[a0+538]:2, a4=0xfac688, a5=[a0+552]:8, a6=[a0+552]:8, a7=[a0+552]:8.
  The `jal` at 0xfb8 calls rad_vl_write_MUX_SEL with a0=a0 at entry (arg0), a1=0x0, a2=?, a3=[a0+538]:2, a4=0xfac688, a5=[a0+552]:8, a6=[a0+552]:8, a7=[a0+552]:8.
  The `jal` at 0x103c calls rad_vl_write_MUX_SEL with a0=a0 at entry (arg0), a1=([a0+29300] | 0x2000), a2=?, a3=?.
  The `beq` branch at 0x934 targets 0xecc, is taken when a3(=[a0+538]:2) == s2(=0xc), and falls through when a3(=[a0+538]:2) != s2(=0xc).
  The `beq` branch at 0x9cc targets 0xf2c, is taken when v0(=[a0+538]:2) == a1(=0x7), and falls through when v0(=[a0+538]:2) != a1(=0x7).
  The `beq` branch at 0x9d4 targets 0xf80, is taken when v0(=[a0+538]:2) == s1(=0xd), and falls through when v0(=[a0+538]:2) != s1(=0xd).
  The `beq` branch at 0x9dc targets 0xef8, is taken when v0(=[a0+538]:2) == s2(=0xc), and falls through when v0(=[a0+538]:2) != s2(=0xc).
  The `beq` branch at 0xac0 targets 0xed8, is taken when v0(=[a0+538]:2) == s2(=0xc), and falls through when v0(=[a0+538]:2) != s2(=0xc).
  The `beq` branch at 0xae0 targets 0xafc, is taken when v0(=[a0+538]:2) == s1(=0xd), and falls through when v0(=[a0+538]:2) != s1(=0xd).
  The `beq` branch at 0xb04 targets 0xf1c, is taken when v0(=ret(rad_init_subsys)) == 0, and falls through when v0(=ret(rad_init_subsys)) != 0.
  The `beq` branch at 0xb10 targets 0xbc4, is taken when v0(=[a0+538]:2) == s1(=0xd), and falls through when v0(=[a0+538]:2) != s1(=0xd).
  The `beq` branch at 0xb40 targets 0xea8, is taken when v0(=ret(rad_create_device)) == 0, and falls through when v0(=ret(rad_create_device)) != 0.
  The `beq` branch at 0xb98 targets 0xf24, is taken when v0(=ret(rad_create_device)) == 0, and falls through when v0(=ret(rad_create_device)) != 0.
  The `beq` branch at 0xbf4 targets 0xec4, is taken when v0(=ret(rad_create_device)) == 0, and falls through when v0(=ret(rad_create_device)) != 0.
  The `beq` branch at 0xc4c targets 0xef0, is taken when v0(=ret(rad_create_device)) == 0, and falls through when v0(=ret(rad_create_device)) != 0.
  The `beq` branch at 0xcb0 targets 0xf0c, is taken when v0(=ret(rad_create_device)) == 0, and falls through when v0(=ret(rad_create_device)) != 0.
  The `beq` branch at 0xd08 targets 0xf14, is taken when v0(=ret(rad_create_device)) == 0, and falls through when v0(=ret(rad_create_device)) != 0.
  The `beq` branch at 0xd40 targets 0xd78, is taken when t9(=[a0+538]:2) == s1(=0xd), and falls through when t9(=[a0+538]:2) != s1(=0xd).
  The `beq` branch at 0xd5c targets 0xfc8, is taken when v0(=ret(rad_create_clockgen)) == 0, and falls through when v0(=ret(rad_create_clockgen)) != 0.
  The `beq` branch at 0xd74 targets 0xfd8, is taken when v0(=ret(rad_create_clockgen)) == 0, and falls through when v0(=ret(rad_create_clockgen)) != 0.
  The `beq` branch at 0xd8c targets 0xfd0, is taken when v0(=ret(rad_create_clockgen)) == 0, and falls through when v0(=ret(rad_create_clockgen)) != 0.
  The `beq` branch at 0xda8 targets 0xfe0, is taken when v0(=ret(rad_create_clockgen)) == 0, and falls through when v0(=ret(rad_create_clockgen)) != 0.
  The `beq` branch at 0xdc0 targets 0x1004, is taken when v0(=ret(rad_create_clockgen)) == 0, and falls through when v0(=ret(rad_create_clockgen)) != 0.
  The `beq` branch at 0xdd8 targets 0x1020, is taken when v0(=ret(rad_create_clockgen)) == 0, and falls through when v0(=ret(rad_create_clockgen)) != 0.
  The `beq` branch at 0xdec targets 0xe28, is taken when a1(=[a0+88]:8) == 0, and falls through when a1(=[a0+88]:8) != 0.
  The `beq` branch at 0xe00 targets 0x1028, is taken when v0(=ret(rad_start_device)) == 0, and falls through when v0(=ret(rad_start_device)) != 0.
  The `beq` branch at 0xe14 targets 0xe28, is taken when a0(?) >= 0x18 (signed), and falls through when a0(?) < 0x18 (signed).
  The `bne` branch at 0xe20 targets 0xdf8, is taken when a1(?) != 0, and falls through when a1(?) == 0.
  The `beq` branch at 0xe44 targets 0x100c, is taken when v0(=[a0+538]:2) == s1(=0xd), and falls through when v0(=[a0+538]:2) != s1(=0xd).
  The `beq` branch at 0xe4c targets 0x1018, is taken when v0(=[a0+538]:2) == s1(=0xd), and falls through when v0(=[a0+538]:2) != s1(=0xd).
  The `beq` branch at 0xe6c targets 0x1030, is taken when v0(=[a0+538]:2) == a1(=0x7), and falls through when v0(=[a0+538]:2) != a1(=0x7).
  The `beq` branch at 0xe74 targets 0xfe8, is taken when v0(=[a0+538]:2) == s1(=0xd), and falls through when v0(=[a0+538]:2) != s1(=0xd).
  The `beq` branch at 0xe98 targets 0xff0, is taken when v0(=[a0+538]:2) == s2(=0xc), and falls through when v0(=[a0+538]:2) != s2(=0xc).
  The `beq` branch at 0xea0 targets 0xeac and is always taken.
  The `beq` branch at 0xec4 targets 0xeac and is always taken.
  The `beq` branch at 0xed0 targets 0x944 and is always taken.
  The `beq` branch at 0xee8 targets 0xac4 and is always taken.
  The `beq` branch at 0xef0 targets 0xeac and is always taken.
  The `beq` branch at 0xf04 targets 0x9e4 and is always taken.
  The `beq` branch at 0xf0c targets 0xeac and is always taken.
  The `beq` branch at 0xf14 targets 0xeac and is always taken.
  The `beq` branch at 0xf1c targets 0xeac and is always taken.
  The `beq` branch at 0xf24 targets 0xeac and is always taken.
  The `beq` branch at 0xf78 targets 0x9e8 and is always taken.
  The `beq` branch at 0xfc0 targets 0x9e8 and is always taken.
  The `beq` branch at 0xfc8 targets 0xeac and is always taken.
  The `beq` branch at 0xfd0 targets 0xeac and is always taken.
  The `beq` branch at 0xfd8 targets 0xeac and is always taken.
  The `beq` branch at 0xfe0 targets 0xeac and is always taken.
  The `bne` branch at 0xfe8 targets 0xea0, is taken when v0(=[a0+538]:2) != s2(=0xc), and falls through when v0(=[a0+538]:2) == s2(=0xc).
  The `beq` branch at 0xffc targets 0xea0 and is always taken.
  The `beq` branch at 0x1004 targets 0xeac and is always taken.
  The `bne` branch at 0x1010 targets 0xe54, is taken when v0(=[a0+538]:2) != s1(=0xd), and falls through when v0(=[a0+538]:2) == s1(=0xd).
  The `beq` branch at 0x1018 targets 0xe54 and is always taken.
  The `beq` branch at 0x1020 targets 0xeac and is always taken.
  The `beq` branch at 0x1028 targets 0xeac and is always taken.
  The `beq` branch at 0x1048 targets 0xe74 and is always taken.
  The return at 0xebc has v0 = one of 0x0, 0x1.

- `rad_enable_ust` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x1050 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x1050-0x1084 (52 bytes).
  It occupies 52 bytes.
  The `lh` at 0x1050 loads 2 bytes from a0 (arg0 at entry) +0x21a.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x228, including `ld` at 0x1068, `ld` at 0x1074.
  2 such `sw` accesses store 4 bytes to [a0+552]:8 +0x40, including `sw` at 0x1070, `sw` at 0x1078.
  The `beq` branch at 0x1058 targets 0x107c, is taken when a2(=[a0+538]:2) == at(=0x7), and falls through when a2(=[a0+538]:2) != at(=0x7).
  The `beq` branch at 0x1060 targets 0x107c, is taken when a2(=[a0+538]:2) == a3(=0xd), and falls through when a2(=[a0+538]:2) != a3(=0xd).
  The return at 0x107c has v0 = one of ?, 0xa.

- `rad_disable_ust` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x1084 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x1084-0x10ac (40 bytes).
  It occupies 40 bytes.
  The `lh` at 0x1084 loads 2 bytes from a0 (arg0 at entry) +0x21a.
  The `ld` at 0x109c loads 8 bytes from a0 (arg0 at entry) +0x228.
  The `sw` at 0x10a0 stores 4 bytes to [a0+552]:8 +0x40.
  The `beq` branch at 0x108c targets 0x10a4, is taken when a2(=[a0+538]:2) == at(=0x7), and falls through when a2(=[a0+538]:2) != at(=0x7).
  The `beq` branch at 0x1094 targets 0x10a4, is taken when a2(=[a0+538]:2) == a3(=0xd), and falls through when a2(=[a0+538]:2) != a3(=0xd).
  The return at 0x10a4 has v0 = one of ?, 0x2.

- `rad_reset_ust` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x10ac (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x10ac-0x10e4 (56 bytes).
  It occupies 56 bytes.
  The `lh` at 0x10ac loads 2 bytes from a0 (arg0 at entry) +0x21a.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x228, including `ld` at 0x10cc, `ld` at 0x10d8.
  2 such `sw` accesses store 4 bytes to [a0+552]:8 +0x40, including `sw` at 0x10d4, `sw` at 0x10e0.
  The `beq` branch at 0x10b4 targets 0x10cc, is taken when a2(=[a0+538]:2) == at(=0x7), and falls through when a2(=[a0+538]:2) != at(=0x7).
  The `beq` branch at 0x10bc targets 0x10cc, is taken when a2(=[a0+538]:2) == a3(=0xd), and falls through when a2(=[a0+538]:2) != a3(=0xd).
  The return at 0x10c4 has v0 = ?.
  The return at 0x10dc has v0 = [a0+552]:8.

- `rad_set_ust_offset` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x10e4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x10e4-0x115c (120 bytes).
  It occupies 120 bytes.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x228, including `ld` at 0x10fc, `ld` at 0x1118.
  The `sd` at 0x1108 stores 8 bytes to a0 (arg0 at entry) +0x72a8.
  2 such `lw` accesses load 4 bytes from [a0+552]:8 +0x30, including `lw` at 0x110c, `lw` at 0x111c.
  The `lw` at 0x1148 loads 4 bytes from a0 (arg0 at entry) +0x731c.
  The `jal` at 0x1110 calls us_delay with a0=0xa, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x114c calls cmn_err with a0=0x1, a1=sym(.rodata), a2=[a0+29468], a3=?.
  The `bne` branch at 0x1128 targets 0x1140, is taken when v0(?) < 0x3 (unsigned), and falls through when v0(?) >= 0x3 (unsigned).
  The `beq` branch at 0x1154 targets 0x1130 and is always taken.
  The return at 0x1138 has v0 = one of ?, ret(cmn_err).

- `rad_create_device` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x115c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x115c-0x165c (1280 bytes).
  It occupies 1280 bytes.
  The `sd` at 0x1218 stores 8 bytes to a1 (arg1 at entry) +0x2a0.
  The `sw` at 0x121c stores 4 bytes to a1 (arg1 at entry) +0x29c.
  The `sw` at 0x1224 stores 4 bytes to a1 (arg1 at entry) +0x120.
  The `sd` at 0x1244 stores 8 bytes to a1 (arg1 at entry) +0x200.
  The `sd` at 0x1248 stores 8 bytes to a1 (arg1 at entry) +0x218.
  The `sd` at 0x124c stores 8 bytes to a1 (arg1 at entry) +0x290.
  The `sd` at 0x1250 stores 8 bytes to a1 (arg1 at entry) +0x288.
  The `sd` at 0x1254 stores 8 bytes to a1 (arg1 at entry) +0x278.
  The `sd` at 0x1258 stores 8 bytes to a1 (arg1 at entry) +0x18.
  The `sd` at 0x1260 stores 8 bytes to a1 (arg1 at entry) +0x8.
  The `sd` at 0x126c stores 8 bytes to a1 (arg1 at entry) +0x20.
  2 such `sd` accesses store 8 bytes to a1 (arg1 at entry) +0x280, including `sd` at 0x1270, `sd` at 0x13a8.
  The `sw` at 0x127c stores 4 bytes to a1 (arg1 at entry) +0x2c0.
  The `sw` at 0x128c stores 4 bytes to a1 (arg1 at entry) +0x298.
  The `sw` at 0x1298 stores 4 bytes to a1 (arg1 at entry) +0x2f0.
  The `lh` at 0x12b4 loads 2 bytes from table(sym(.data)) +0x0.
  The `lw` at 0x12b8 loads 4 bytes from table(sym(.data)) +0x10.
  3 such `sd` accesses store 8 bytes to a1 (arg1 at entry) +0x300, including `sd` at 0x12d0, `sd` at 0x13b8, `sd` at 0x13c8.
  3 such `sd` accesses store 8 bytes to a1 (arg1 at entry) +0x2f8, including `sd` at 0x12d8, `sd` at 0x13ac, `sd` at 0x13bc.
  The `ld` at 0x12f8 loads 8 bytes from (sym(.rodata) + (a4+2 << 0x3)) +0x0.
  The `jal` at 0x11a8 calls kmem_alloc with a0=(a3 << 0x2), a1=0x8800, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x11e4 calls kdsp_init_resource with a0=a1 at entry (arg1), a1=one of 0x2000001b, 0x2000001c, a2=a5 at entry (arg5), a3=a6 at entry (arg6), a4=a0 at entry (arg0), a5=0x0, a6=0x318.
  The `jal` at 0x1208 calls kdsp_create_device with a0=a1 at entry (arg1), a1=a3 at entry (arg3), a2=(a2 | 0x40), a3=0x0, a4=ret(kmem_alloc), a5=a7 at entry (arg7).
  Calls (unknown callee) via register with a0=-0x2, a1=?, a2=sym(rad_commit_device_params), a3=sym(rad_update_dev), a4=sym(rad_start_dma), a5=sym(rad_stop_dma), a6=sym(rad_get_hw_mscust), a7=sym(rad_pre_connect) (`jr` at 0x12fc).
  The `jal` at 0x164c calls rad_destroy_devices with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `beq` branch at 0x1210 targets 0x164c, is taken when v0(=ret(kdsp_create_device)) == 0, and falls through when v0(=ret(kdsp_create_device)) != 0.
  The `beq` branch at 0x1268 targets 0x13a4, is taken when s3(=a2) == 0, and falls through when s3(=a2) != 0.
  The `beq` branch at 0x1294 targets 0x13bc, is taken when s2(=a4) == a0(=-0x2), and falls through when s2(=a4) != a0(=-0x2).
  The `beq` branch at 0x12a0 targets 0x13ac, is taken when s2(=a4) == t8(=-0x1), and falls through when s2(=a4) != t8(=-0x1).
  The `beq` branch at 0x12f0 targets 0x1304, is taken when v1(=a4+2) >= 0xa (unsigned), and falls through when v1(=a4+2) < 0xa (unsigned).
  The `beq` branch at 0x1304 targets 0x1378 and is always taken.
  The `beq` branch at 0x13a4 targets 0x1274 and is always taken.
  The `beq` branch at 0x13b4 targets 0x12dc and is always taken.
  The `beq` branch at 0x13c4 targets 0x12dc and is always taken.
  The `beq` branch at 0x1654 targets 0x1378 and is always taken.
  The return at 0x139c has v0 = 0x0.
  The instructions from 0x130c to 0x1374 are not reached by any path from the entry, and their branches are not listed.
  The instructions from 0x13cc to 0x1648 are not reached by any path from the entry, and their branches are not listed.
  The indirect jump at 0x12fc uses a jump table whose successors are unresolved.

- `rad_start_device` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x165c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x165c-0x16ec (144 bytes).
  It occupies 144 bytes.
  The `lw` at 0x165c loads 4 bytes from a1 (arg1 at entry) +0x2c0.
  4 such `ld` accesses load 8 bytes from a1 (arg1 at entry) +0x2e8, including `ld` at 0x168c, `ld` at 0x169c, `ld` at 0x16bc.
  4 such `lw` accesses load 4 bytes from [a1+744]:8 +0x0, including `lw` at 0x1690, `lw` at 0x16ac, `lw` at 0x16c0.
  3 such `sw` accesses store 4 bytes to [a1+744]:8 +0x0, including `sw` at 0x1698, `sw` at 0x16d0, `sw` at 0x16e8.
  The `ld` at 0x16a0 loads 8 bytes from a0 (arg0 at entry) +0x228.
  The `lwu` at 0x16a4 loads 4 bytes from a1 (arg1 at entry) +0x2e4.
  The `sw` at 0x16b8 stores 4 bytes to ([a1+740] + [a0+552]:8) +0x0.
  The `beq` branch at 0x166c targets 0x16d4, is taken when a3(=[a1+704]) == at(=-0x1), and falls through when a3(=[a1+704]) != at(=-0x1).
  The `beq` branch at 0x1674 targets 0x16d4, is taken when a3(=[a1+704]) == a6(=-0x2), and falls through when a3(=[a1+704]) != a6(=-0x2).
  The `beq` branch at 0x167c targets 0x16bc, is taken when a3(=[a1+704]) == a4(=0x6), and falls through when a3(=[a1+704]) != a4(=0x6).
  The `beq` branch at 0x1684 targets 0x16bc, is taken when a3(=[a1+704]) == a5(=0x7), and falls through when a3(=[a1+704]) != a5(=0x7).
  The `beq` branch at 0x16cc targets 0x169c and is always taken.
  The `beq` branch at 0x16e4 targets 0x169c and is always taken.
  The return at 0x16b4 has v0 = 0x1.

- `rad_create_ifs` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x16ec (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x16ec-0x1c08 (1308 bytes).
  It occupies 1308 bytes.
  The `sw` at 0x172c stores 4 bytes to sym(.data) +0x7430.
  The `sw` at 0x1734 stores 4 bytes to sym(.data) +0x7428.
  2 such `lh` accesses load 2 bytes from a0 (arg0 at entry) +0x21a, including `lh` at 0x1738, `lh` at 0x1b70.
  The `sd` at 0x178c stores 8 bytes to a0 (arg0 at entry) +0x58b0.
  The `sw` at 0x1798 stores 4 bytes to a0 (arg0 at entry) +0x5838.
  The `sd` at 0x17a8 stores 8 bytes to a0 (arg0 at entry) +0x5728.
  The `sd` at 0x17ac stores 8 bytes to a0 (arg0 at entry) +0x5720.
  The `sw` at 0x17b0 stores 4 bytes to a0 (arg0 at entry) +0x58b8.
  The `sd` at 0x17c8 stores 8 bytes to a0 (arg0 at entry) +0x5738.
  The `sd` at 0x17d4 stores 8 bytes to sym(.bss) +0x40.
  The `sd` at 0x17dc stores 8 bytes to sym(.bss) +0x10.
  The `sd` at 0x17e8 stores 8 bytes to sym(.bss) +0x18.
  The `sd` at 0x17f4 stores 8 bytes to sym(.bss) +0x28.
  The `sd` at 0x1800 stores 8 bytes to sym(.bss) +0x0.
  The `sd` at 0x180c stores 8 bytes to sym(.bss) +0x8.
  The `sd` at 0x1818 stores 8 bytes to sym(.bss) +0x30.
  The `sw` at 0x1824 stores 4 bytes to sym(.bss) +0x20.
  The `sw` at 0x1830 stores 4 bytes to sym(.bss) +0x38.
  The `sd` at 0x183c stores 8 bytes to sym(.bss) +0x48.
  The `sd` at 0x1850 stores 8 bytes to a0 (arg0 at entry) +0x5a58.
  2 such `lw` accesses load 4 bytes from sym(.data) +0x7428, including `lw` at 0x1860, `lw` at 0x19ac.
  The `sw` at 0x1868 stores 4 bytes to a0 (arg0 at entry) +0x59e0.
  The `sd` at 0x1870 stores 8 bytes to a0 (arg0 at entry) +0x58e0.
  The `sd` at 0x1874 stores 8 bytes to a0 (arg0 at entry) +0x58d0.
  The `sd` at 0x1878 stores 8 bytes to a0 (arg0 at entry) +0x58c8.
  The `sw` at 0x187c stores 4 bytes to a0 (arg0 at entry) +0x5a60.
  The `sd` at 0x1880 stores 8 bytes to sym(.bss) +0x98.
  The `sd` at 0x1884 stores 8 bytes to sym(.bss) +0x58.
  The `sd` at 0x1888 stores 8 bytes to sym(.bss) +0x50.
  The `sw` at 0x1890 stores 4 bytes to sym(.bss) +0x70.
  The `sd` at 0x1894 stores 8 bytes to sym(.bss) +0x68.
  The `sd` at 0x1898 stores 8 bytes to sym(.bss) +0x60.
  The `sd` at 0x189c stores 8 bytes to sym(.bss) +0x90.
  The `sd` at 0x18e4 stores 8 bytes to a0 (arg0 at entry) +0x5c00.
  The `sw` at 0x18f0 stores 4 bytes to a0 (arg0 at entry) +0x5b88.
  The `sd` at 0x18f4 stores 8 bytes to a0 (arg0 at entry) +0x5a78.
  The `sd` at 0x18f8 stores 8 bytes to a0 (arg0 at entry) +0x5a70.
  The `sd` at 0x1908 stores 8 bytes to a0 (arg0 at entry) +0x5a88.
  The `sw` at 0x1910 stores 4 bytes to a0 (arg0 at entry) +0x5c08.
  The `sd` at 0x191c stores 8 bytes to sym(.bss) +0x138.
  The `sd` at 0x1924 stores 8 bytes to sym(.bss) +0xf8.
  The `sd` at 0x1928 stores 8 bytes to sym(.bss) +0xf0.
  The `sd` at 0x1930 stores 8 bytes to sym(.bss) +0x118.
  The `sd` at 0x1938 stores 8 bytes to sym(.bss) +0x120.
  The `sw` at 0x1940 stores 4 bytes to sym(.bss) +0x128.
  The `sw` at 0x1948 stores 4 bytes to sym(.bss) +0x110.
  The `sd` at 0x194c stores 8 bytes to sym(.bss) +0x108.
  The `sd` at 0x1950 stores 8 bytes to sym(.bss) +0x100.
  The `sd` at 0x1958 stores 8 bytes to sym(.bss) +0x130.
  The `sd` at 0x19a8 stores 8 bytes to a0 (arg0 at entry) +0x5da8.
  The `sw` at 0x19b4 stores 4 bytes to a0 (arg0 at entry) +0x5d30.
  The `sd` at 0x19bc stores 8 bytes to a0 (arg0 at entry) +0x5c30.
  The `sd` at 0x19c0 stores 8 bytes to a0 (arg0 at entry) +0x5c20.
  The `sd` at 0x19c4 stores 8 bytes to a0 (arg0 at entry) +0x5c18.
  The `sw` at 0x19cc stores 4 bytes to a0 (arg0 at entry) +0x5db0.
  The `sd` at 0x19d8 stores 8 bytes to sym(.bss) +0xe8.
  The `sd` at 0x19e0 stores 8 bytes to sym(.bss) +0xa8.
  The `sd` at 0x19e4 stores 8 bytes to sym(.bss) +0xa0.
  The `sd` at 0x19e8 stores 8 bytes to sym(.bss) +0xd0.
  The `sw` at 0x19f0 stores 4 bytes to sym(.bss) +0xc0.
  The `sd` at 0x19f4 stores 8 bytes to sym(.bss) +0xb8.
  The `sd` at 0x19f8 stores 8 bytes to sym(.bss) +0xb0.
  The `sd` at 0x1a00 stores 8 bytes to sym(.bss) +0xe0.
  The `sd` at 0x1a38 stores 8 bytes to a0 (arg0 at entry) +0x5f50.
  The `sw` at 0x1a40 stores 4 bytes to a0 (arg0 at entry) +0x5ed8.
  The `sd` at 0x1a48 stores 8 bytes to a0 (arg0 at entry) +0x5dc0.
  The `sw` at 0x1a54 stores 4 bytes to a0 (arg0 at entry) +0x5f58.
  The `sd` at 0x1a60 stores 8 bytes to a0 (arg0 at entry) +0x5dd8.
  The `sd` at 0x1a90 stores 8 bytes to a0 (arg0 at entry) +0x60f8.
  The `sw` at 0x1a98 stores 4 bytes to a0 (arg0 at entry) +0x6080.
  The `sd` at 0x1aa0 stores 8 bytes to a0 (arg0 at entry) +0x5f68.
  The `sw` at 0x1aac stores 4 bytes to a0 (arg0 at entry) +0x6100.
  The `sd` at 0x1ab8 stores 8 bytes to a0 (arg0 at entry) +0x5f80.
  The `sd` at 0x1aec stores 8 bytes to a0 (arg0 at entry) +0x62a0.
  The `sw` at 0x1af4 stores 4 bytes to a0 (arg0 at entry) +0x6228.
  The `sd` at 0x1afc stores 8 bytes to a0 (arg0 at entry) +0x6110.
  The `sw` at 0x1b08 stores 4 bytes to a0 (arg0 at entry) +0x62a8.
  The `sd` at 0x1b14 stores 8 bytes to a0 (arg0 at entry) +0x6128.
  The `sd` at 0x1b44 stores 8 bytes to a0 (arg0 at entry) +0x6448.
  The `sw` at 0x1b4c stores 4 bytes to a0 (arg0 at entry) +0x63d0.
  The `sd` at 0x1b54 stores 8 bytes to a0 (arg0 at entry) +0x62b8.
  The `sw` at 0x1b60 stores 4 bytes to a0 (arg0 at entry) +0x6450.
  The `sd` at 0x1b6c stores 8 bytes to a0 (arg0 at entry) +0x62d0.
  The `jal` at 0x1774 calls kdsp_init_resource with a0=a0+22296, a1=0x2000000e, a2=sym(.rodata), a3=sym(.rodata), a4=a0 at entry (arg0), a5=0x0, a6=0x1a8.
  The `jal` at 0x1838 calls kdsp_init_resource with a0=a0+22720, a1=0x2000000e, a2=sym(.rodata), a3=sym(.rodata), a4=a0 at entry (arg0), a5=0x0, a6=0x1a8, a7=sym(.bss).
  The `jal` at 0x18a0 calls kdsp_add_subresource with a0=a0+4208, a1=a0+22720, a2=0x1, a3=0xb, a4=sym(.data)+32768, a5=sym(rad_get_analog_out_if_params), a6=sym(rad_set_analog_out_if_params), a7=[sym(.data)+29736].
  The `jal` at 0x18c8 calls kdsp_init_resource with a0=a0+23144, a1=0x2000000d, a2=sym(.rodata), a3=0x0, a4=a0 at entry (arg0), a5=0x0, a6=0x1a8.
  The `jal` at 0x1954 calls kdsp_select_interface with a0=a0+3416, a1=a0+23144, a2=sym(.bss), a3=0x1, a4=0xff, a5=0x50d0d0d1, a6=0x32aee8263, a7=0x1480000000.
  The `jal` at 0x1980 calls kdsp_init_resource with a0=a0+23568, a1=0x20000011, a2=sym(.rodata), a3=sym(.rodata), a4=a0 at entry (arg0), a5=0x0, a6=0x1a8.
  The `jal` at 0x19fc calls kdsp_add_subresource with a0=a0+4208, a1=a0+23568, a2=sym(.bss), a3=0x3, a4=0x217354b8e7, a5=0x1480000000, a6=0xb00000000, a7=0xb.
  The `jal` at 0x1a2c calls kdsp_init_resource with a0=a0+23992, a1=0x2000000f, a2=sym(.rodata), a3=sym(.rodata), a4=a0 at entry (arg0), a5=0x0, a6=0x1a8.
  The `jal` at 0x1a5c calls kdsp_select_interface with a0=a0+5000, a1=a0+23992, a2=?, a3=?.
  The `jal` at 0x1a84 calls kdsp_init_resource with a0=a0+24416, a1=0x2000000f, a2=sym(.rodata), a3=sym(.rodata), a4=a0 at entry (arg0), a5=0x0, a6=0x1a8.
  The `jal` at 0x1ab4 calls kdsp_select_interface with a0=a0+5792, a1=a0+24416, a2=?, a3=sym(.data)+32768, a4=[sym(.sdata)+40], a5=sym(rad_set_digital_if_params).
  The `jal` at 0x1ae0 calls kdsp_init_resource with a0=a0+24840, a1=0x20000025, a2=sym(.rodata), a3=sym(.rodata), a4=a0 at entry (arg0), a5=0x0, a6=0x1a8.
  The `jal` at 0x1b10 calls kdsp_select_interface with a0=a0+6584, a1=a0+24840, a2=sym(.data)+32768, a3=[sym(.sdata)+40], a4=sym(rad_set_digital_if_params).
  The `jal` at 0x1b38 calls kdsp_init_resource with a0=a0+25264, a1=0x20000025, a2=sym(.rodata), a3=sym(.rodata), a4=a0 at entry (arg0), a5=0x0, a6=0x1a8.
  The `jal` at 0x1b68 calls kdsp_select_interface with a0=a0+7376, a1=a0+25264, a2=sym(.data)+32768, a3=[sym(.sdata)+40], a4=sym(rad_set_digital_if_params).
  The `jal` at 0x1b84 calls kdsp_map_resource with a0=a0+23144, a1=0x0, a2=?, a3=?, a5=[a0+538]:2, a6=0xd.
  The `jal` at 0x1b90 calls kdsp_map_resource with a0=a0+22296, a1=0x0, a2=?, a3=?.
  The `jal` at 0x1b9c calls kdsp_map_resource with a0=a0+22720, a1=0x0, a2=?, a3=?.
  The `jal` at 0x1ba8 calls kdsp_map_resource with a0=a0+23568, a1=0x0, a2=?, a3=?.
  The `jal` at 0x1bc4 calls kdsp_map_resource with a0=a0+23992, a1=0x0, a2=?, a3=?.
  The `jal` at 0x1bd0 calls kdsp_map_resource with a0=a0+24416, a1=0x0, a2=?, a3=?.
  The `jal` at 0x1be0 calls kdsp_map_resource with a0=a0+24840, a1=0x0, a2=?, a3=?.
  The `jal` at 0x1bec calls kdsp_map_resource with a0=a0+25264, a1=0x0, a2=?, a3=?.
  The `beq` branch at 0x174c targets 0x1a04, is taken when at(=[a0+538]:2) == v0(=0xd), and falls through when at(=[a0+538]:2) != v0(=0xd).
  The `beq` branch at 0x1b78 targets 0x1bb0, is taken when a5(=[a0+538]:2) == a6(=0xd), and falls through when a5(=[a0+538]:2) != a6(=0xd).
  The return at 0x1c00 has v0 = 0x1.

- `rad_create_subcode_device` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x1c08 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x1c08-0x1d58 (336 bytes).
  It occupies 336 bytes.
  The `sw` at 0x1c80 stores 4 bytes to a1 (arg1 at entry) +0x258.
  The `sd` at 0x1c88 stores 8 bytes to a1 (arg1 at entry) +0x60.
  The `sd` at 0x1c94 stores 8 bytes to a1 (arg1 at entry) +0x58.
  The `lw` at 0x1d40 loads 4 bytes from a3 (arg3 at entry) +0x5c.
  The `sw` at 0x1d54 stores 4 bytes to a3 (arg3 at entry) +0x5c.
  The `jal` at 0x1c70 calls rad_create_device with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a4 at entry (arg4), a3=?, a4=a5 at entry (arg5), a5=a7 at entry (arg7).
  The `jal` at 0x1ca0 calls kdsp_select_clockgen with a0=a1 at entry (arg1), a1=?, a2=?, a3=?.
  The `jal` at 0x1cac calls kdsp_select_interface with a0=a1 at entry (arg1), a1=?, a2=?, a3=?.
  The `jal` at 0x1cb8 calls rad_start_device with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0x1cf8 calls kdsp_create_subcode with a0=a3 at entry (arg3), a1=a2 at entry (arg2), a2=a1 at entry (arg1), a3=a6 at entry (arg6).
  The `jal` at 0x1d20 calls kdsp_set_default_subcode with a0=a3 at entry (arg3), a1=sp-144, a2=0x0, a3=?.
  The `beq` branch at 0x1c48 targets 0x1c54, is taken when a6 == 0, and falls through when a6 != 0.
  The `beq` branch at 0x1c78 targets 0x1cc8, is taken when v0(=ret(rad_create_device)) == 0, and falls through when v0(=ret(rad_create_device)) != 0.
  The `bne` branch at 0x1c90 targets 0x1cec, is taken when s1(=a3) != 0, and falls through when s1(=a3) == 0.
  The `beq` branch at 0x1d04 targets 0x1d2c, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x1d38 targets 0x1c98, is taken when v1(?) == 0, and falls through when v1(?) != 0.
  The `beq` branch at 0x1d50 targets 0x1c98 and is always taken.
  The return at 0x1ce4 has v0 = one of 0x0, 0x1.

- `rad_create_subcodes` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x1d58 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x1d58-0x22e8 (1424 bytes).
  It occupies 1424 bytes.
  2 such `lh` accesses load 2 bytes from a0 (arg0 at entry) +0x21a, including `lh` at 0x1d94, `lh` at 0x2268.
  The `sw` at 0x21e0 stores 4 bytes to a0 (arg0 at entry) +0x723c.
  The `sw` at 0x21e4 stores 4 bytes to a0 (arg0 at entry) +0x7238.
  The `sb` at 0x21e8 stores 1 byte to a0 (arg0 at entry) +0x7311.
  The `sb` at 0x21ec stores 1 byte to a0 (arg0 at entry) +0x7310.
  The `sb` at 0x21f4 stores 1 byte to a0 (arg0 at entry) +0x7312.
  2 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x7316, including `sb` at 0x21f8, `sb` at 0x2214.
  2 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x7314, including `sb` at 0x21fc, `sb` at 0x2210.
  The `sb` at 0x2218 stores 1 byte to a0 (arg0 at entry) +0x7315.
  The `sb` at 0x221c stores 1 byte to a0 (arg0 at entry) +0x7317.
  The `lw` at 0x2220 loads 4 bytes from a0 (arg0 at entry) +0x7244.
  The `ld` at 0x2224 loads 8 bytes from a0 (arg0 at entry) +0x228.
  The `sw` at 0x222c stores 4 bytes to a0 (arg0 at entry) +0x7244.
  The `sw` at 0x2234 stores 4 bytes to [a0+552]:8 +0x70.
  The `jal` at 0x1e04 calls rad_create_subcode_device with a0=a0 at entry (arg0), a1=a0+8168, a2=a0+5000, a3=0x0, a4=0x400, a5=0x6, a6=0x0, a7=sym(.rodata).
  The `jal` at 0x1e64 calls rad_create_subcode_device with a0=a0 at entry (arg0), a1=a0+8960, a2=a0+6584, a3=0x0, a4=0x400, a5=0x7, a6=0x0, a7=sym(.rodata).
  The `jal` at 0x1eb8 calls rad_create_subcode_device with a0=a0 at entry (arg0), a1=a0+10544, a2=a0+5000, a3=a0+21256, a4=0x0, a5=0x6, a6=0x1000002f, a7=sym(.rodata).
  The `jal` at 0x1f0c calls rad_create_subcode_device with a0=a0 at entry (arg0), a1=a0+9752, a2=a0+5000, a3=a0+21152, a4=0x0, a5=0x6, a6=0x10000030, a7=sym(.rodata).
  The `jal` at 0x1f60 calls rad_create_subcode_device with a0=a0 at entry (arg0), a1=a0+11336, a2=a0+5000, a3=a0+21360, a4=0x0, a5=0x6, a6=0x10000031, a7=sym(.rodata).
  The `jal` at 0x1fbc calls rad_create_subcode_device with a0=a0 at entry (arg0), a1=a0+12920, a2=a0+5792, a3=a0+20944, a4=0x1, a5=-0x1, a6=0x1000002f, a7=sym(.rodata).
  The `jal` at 0x2014 calls rad_create_subcode_device with a0=a0 at entry (arg0), a1=a0+12128, a2=a0+5792, a3=a0+20840, a4=0x1, a5=-0x1, a6=0x10000030, a7=sym(.rodata).
  The `jal` at 0x206c calls rad_create_subcode_device with a0=a0 at entry (arg0), a1=a0+13712, a2=a0+5792, a3=a0+21048, a4=0x1, a5=-0x1, a6=0x10000031, a7=sym(.rodata).
  The `jal` at 0x20b0 calls sprintf with a0=sp-192, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x20c0 calls sprintf with a0=sp-168, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x2144 calls rad_create_subcode_device with a0=a0 at entry (arg0), a1=?, a2=?, a3=?, a4=0x0, a5=0x7, a7=sp-192.
  The `jal` at 0x2158 calls sprintf with a0=sp-192, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x2168 calls sprintf with a0=sp-168, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x21c0 calls rad_create_subcode_device with a0=a0 at entry (arg0), a1=?, a2=?, a3=?, a4=0x1, a5=-0x2, a7=sp-192.
  The `jal` at 0x2200 calls rad_pio_writeback_subcode_tx with a0=?, a1=?, a2=?, a3=0x1.
  The `jal` at 0x2208 calls rad_pio_writeback_subcode_tx with a0=a0+17672, a1=?, a2=?, a3=?.
  The `beq` branch at 0x1d84 targets 0x2268, is taken when v0(=[sym(kdsp_pro_audio_subcode)]) == a1(=0x1), and falls through when v0(=[sym(kdsp_pro_audio_subcode)]) != a1(=0x1).
  The `beq` branch at 0x1d8c targets 0x2290, is taken when v0(=[sym(kdsp_pro_audio_subcode)]) == 0, and falls through when v0(=[sym(kdsp_pro_audio_subcode)]) != 0.
  The `beq` branch at 0x1da0 targets 0x2298, is taken when v0(=[a0+538]:2) == at(=0x7), and falls through when v0(=[a0+538]:2) != at(=0x7).
  The `beq` branch at 0x1dac targets 0x22a8, is taken when v0(=[a0+538]:2) == v1(=0xd), and falls through when v0(=[a0+538]:2) != v1(=0xd).
  The `beq` branch at 0x1e0c targets 0x2238, is taken when v0(=ret(rad_create_subcode_device)) == 0, and falls through when v0(=ret(rad_create_subcode_device)) != 0.
  The `beq` branch at 0x1e6c targets 0x2260, is taken when v0(=ret(rad_create_subcode_device)) == 0, and falls through when v0(=ret(rad_create_subcode_device)) != 0.
  The `beq` branch at 0x1ec0 targets 0x2288, is taken when v0(=ret(rad_create_subcode_device)) == 0, and falls through when v0(=ret(rad_create_subcode_device)) != 0.
  The `beq` branch at 0x1f14 targets 0x22a0, is taken when v0(=ret(rad_create_subcode_device)) == 0, and falls through when v0(=ret(rad_create_subcode_device)) != 0.
  The `beq` branch at 0x1f68 targets 0x22b0, is taken when v0(=ret(rad_create_subcode_device)) == 0, and falls through when v0(=ret(rad_create_subcode_device)) != 0.
  The `beq` branch at 0x1fc4 targets 0x22b8, is taken when v0(=ret(rad_create_subcode_device)) == 0, and falls through when v0(=ret(rad_create_subcode_device)) != 0.
  The `beq` branch at 0x201c targets 0x22c0, is taken when v0(=ret(rad_create_subcode_device)) == 0, and falls through when v0(=ret(rad_create_subcode_device)) != 0.
  The `beq` branch at 0x2074 targets 0x22e0, is taken when v0(=ret(rad_create_subcode_device)) == 0, and falls through when v0(=ret(rad_create_subcode_device)) != 0.
  The `beq` branch at 0x214c targets 0x22c8, is taken when v0(=ret(rad_create_subcode_device)) == 0, and falls through when v0(=ret(rad_create_subcode_device)) != 0.
  The `beq` branch at 0x21c8 targets 0x22d8, is taken when v0(=ret(rad_create_subcode_device)) == 0, and falls through when v0(=ret(rad_create_subcode_device)) != 0.
  The `bne` branch at 0x21d8 targets 0x20ac, is taken when s1(?) < 0x4 (signed), and falls through when s1(?) >= 0x4 (signed).
  The `beq` branch at 0x2260 targets 0x2238 and is always taken.
  The `beq` branch at 0x2274 targets 0x22d0, is taken when a5(=[a0+538]:2) == a6(=0xd), and falls through when a5(=[a0+538]:2) != a6(=0xd).
  The `beq` branch at 0x2280 targets 0x1db8 and is always taken.
  The `beq` branch at 0x2288 targets 0x2238 and is always taken.
  The `beq` branch at 0x2290 targets 0x1db8 and is always taken.
  The `beq` branch at 0x2298 targets 0x1dbc and is always taken.
  The `beq` branch at 0x22a0 targets 0x2238 and is always taken.
  The `beq` branch at 0x22a8 targets 0x1dbc and is always taken.
  The `beq` branch at 0x22b0 targets 0x2238 and is always taken.
  The `beq` branch at 0x22b8 targets 0x2238 and is always taken.
  The `beq` branch at 0x22c0 targets 0x2238 and is always taken.
  The `beq` branch at 0x22c8 targets 0x2238 and is always taken.
  The `beq` branch at 0x22d0 targets 0x1dbc and is always taken.
  The `beq` branch at 0x22d8 targets 0x2238 and is always taken.
  The `beq` branch at 0x22e0 targets 0x2238 and is always taken.
  The return at 0x2258 has v0 = one of 0x0, 0x1.

- `rad_create_mclks` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x22e8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x22e8-0x25e0 (760 bytes).
  It occupies 760 bytes.
  The `sw` at 0x2334 stores 4 bytes to a0 (arg0 at entry) +0x488.
  The `sw` at 0x233c stores 4 bytes to a0 (arg0 at entry) +0x490.
  The `sw` at 0x2340 stores 4 bytes to a0 (arg0 at entry) +0x48c.
  The `sw` at 0x2348 stores 4 bytes to a0 (arg0 at entry) +0x3f8.
  The `sd` at 0x2364 stores 8 bytes to a0 (arg0 at entry) +0x470.
  The `sd` at 0x2370 stores 8 bytes to a0 (arg0 at entry) +0x2f8.
  The `sw` at 0x23a0 stores 4 bytes to a0 (arg0 at entry) +0x648.
  The `sw` at 0x23a4 stores 4 bytes to a0 (arg0 at entry) +0x64c.
  The `sw` at 0x23a8 stores 4 bytes to a0 (arg0 at entry) +0x650.
  The `sw` at 0x23ac stores 4 bytes to a0 (arg0 at entry) +0x5b8.
  The `sd` at 0x23c4 stores 8 bytes to a0 (arg0 at entry) +0x630.
  The `sd` at 0x23d0 stores 8 bytes to a0 (arg0 at entry) +0x4b8.
  The `sw` at 0x2404 stores 4 bytes to a0 (arg0 at entry) +0x9c8.
  The `sw` at 0x2408 stores 4 bytes to a0 (arg0 at entry) +0x9cc.
  The `sw` at 0x240c stores 4 bytes to a0 (arg0 at entry) +0x9d0.
  The `sd` at 0x2410 stores 8 bytes to a0 (arg0 at entry) +0x9b0.
  The `sw` at 0x2414 stores 4 bytes to a0 (arg0 at entry) +0x938.
  The `sd` at 0x2428 stores 8 bytes to a0 (arg0 at entry) +0x9b8.
  The `sd` at 0x2434 stores 8 bytes to a0 (arg0 at entry) +0x838.
  The `sd` at 0x2450 stores 8 bytes to a0 (arg0 at entry) +0x72f8.
  The `sh` at 0x245c stores 2 bytes to a0 (arg0 at entry) +0x7300.
  The `sw` at 0x246c stores 4 bytes to a0 (arg0 at entry) +0x808.
  The `sw` at 0x2470 stores 4 bytes to a0 (arg0 at entry) +0x80c.
  The `sw` at 0x2474 stores 4 bytes to a0 (arg0 at entry) +0x810.
  The `sd` at 0x2478 stores 8 bytes to a0 (arg0 at entry) +0x7f0.
  The `sw` at 0x247c stores 4 bytes to a0 (arg0 at entry) +0x778.
  The `sd` at 0x2490 stores 8 bytes to a0 (arg0 at entry) +0x7f8.
  The `sd` at 0x249c stores 8 bytes to a0 (arg0 at entry) +0x678.
  The `sb` at 0x24b4 stores 1 byte to a0 (arg0 at entry) +0x730a.
  The `sh` at 0x24c0 stores 2 bytes to a0 (arg0 at entry) +0x730c.
  The `sb` at 0x24cc stores 1 byte to a0 (arg0 at entry) +0x730b.
  The `sw` at 0x24d8 stores 4 bytes to a0 (arg0 at entry) +0xb88.
  The `sw` at 0x24dc stores 4 bytes to a0 (arg0 at entry) +0xb90.
  The `sw` at 0x24e0 stores 4 bytes to a0 (arg0 at entry) +0xb8c.
  The `sw` at 0x24e4 stores 4 bytes to a0 (arg0 at entry) +0xaf8.
  The `sd` at 0x24f8 stores 8 bytes to a0 (arg0 at entry) +0xb70.
  The `sd` at 0x24fc stores 8 bytes to a0 (arg0 at entry) +0x9e0.
  The `sd` at 0x250c stores 8 bytes to a0 (arg0 at entry) +0x9e8.
  The `sd` at 0x2518 stores 8 bytes to a0 (arg0 at entry) +0x9f8.
  The `sw` at 0x254c stores 4 bytes to a0 (arg0 at entry) +0xd48.
  The `sw` at 0x2550 stores 4 bytes to a0 (arg0 at entry) +0xd4c.
  The `sw` at 0x2554 stores 4 bytes to a0 (arg0 at entry) +0xd50.
  The `sd` at 0x2558 stores 8 bytes to a0 (arg0 at entry) +0xd30.
  The `sw` at 0x255c stores 4 bytes to a0 (arg0 at entry) +0xcb8.
  The `sd` at 0x2568 stores 8 bytes to a0 (arg0 at entry) +0xba0.
  The `sd` at 0x2578 stores 8 bytes to a0 (arg0 at entry) +0xba8.
  The `sd` at 0x2584 stores 8 bytes to a0 (arg0 at entry) +0xbb8.
  The `lh` at 0x258c loads 2 bytes from a0 (arg0 at entry) +0x21a.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0xd54, including `sw` at 0x25c8, `sw` at 0x25d4.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0xb94, including `sw` at 0x25d0, `sw` at 0x25dc.
  The `jal` at 0x232c calls kdsp_init_resource with a0=a0+728, a1=0x2000000a, a2=sym(.rodata), a3=sym(.rodata), a4=a0 at entry (arg0), a5=0x0, a6=0x1c0.
  The `jal` at 0x236c calls kdsp_map_resource with a0=a0+728, a1=0x0, a2=sym(.data)+32768, a3=0xac4400000000.
  The `jal` at 0x2394 calls kdsp_init_resource with a0=a0+1176, a1=0x2000000a, a2=sym(.rodata), a3=sym(.rodata), a4=a0 at entry (arg0), a5=0x0, a6=0x1c0.
  The `jal` at 0x23cc calls kdsp_map_resource with a0=a0+1176, a1=0x0, a2=sym(.data)+32768, a3=?.
  The `jal` at 0x23f8 calls kdsp_init_resource with a0=a0+2072, a1=0x2000000b, a2=sym(.rodata), a3=sym(.rodata), a4=a0 at entry (arg0), a5=0x0, a6=0x1c0.
  The `jal` at 0x2430 calls kdsp_map_resource with a0=a0+2072, a1=0x0, a2=sym(.data)+32768, a3=sym(rad_update_aes_mclk), a4=0x3.
  The `jal` at 0x2460 calls kdsp_init_resource with a0=a0+1624, a1=0x2000000c, a2=sym(.rodata), a3=sym(.rodata), a4=a0 at entry (arg0), a5=0x0, a6=0x1c0.
  The `jal` at 0x2498 calls kdsp_map_resource with a0=a0+1624, a1=0x0, a2=sym(.data)+32768, a3=sym(rad_update_adat_mclk), a4=0x2.
  The `jal` at 0x24d0 calls kdsp_init_resource with a0=a0+2520, a1=0x20000016, a2=sym(.rodata), a3=sym(.rodata), a4=a0 at entry (arg0), a5=0x0, a6=0x1c0, a7=0x1.
  The `jal` at 0x2514 calls kdsp_map_resource with a0=a0+2520, a1=0x0, a2=sym(.data)+32768, a3=sym(rad_get_mclk_params), a4=sym(rad_set_mclk_params), a5=0xac4400000000.
  The `jal` at 0x253c calls kdsp_init_resource with a0=a0+2968, a1=0x20000016, a2=sym(.rodata), a3=sym(.rodata), a4=a0 at entry (arg0), a5=0x0, a6=0x1c0.
  The `jal` at 0x2580 calls kdsp_map_resource with a0=a0+2968, a1=0x0, a2=sym(.data)+32768, a3=sym(rad_get_mclk_params), a4=sym(rad_set_mclk_params), a5=0x1.
  The `beq` branch at 0x2598 targets 0x25d4, is taken when a0(=[a0+538]:2) == s2(=0x7), and falls through when a0(=[a0+538]:2) != s2(=0x7).
  The `beq` branch at 0x25a4 targets 0x25d4, is taken when a0(=[a0+538]:2) == a6(=0xd), and falls through when a0(=[a0+538]:2) != a6(=0xd).
  The `beq` branch at 0x25ac targets 0x25c4, is taken when a0(=[a0+538]:2) == a7(=0xc), and falls through when a0(=[a0+538]:2) != a7(=0xc).
  The `beq` branch at 0x25cc targets 0x25b0 and is always taken.
  The `beq` branch at 0x25d8 targets 0x25b0 and is always taken.
  The return at 0x25bc has v0 = 0x1.

- `rad_video_sync_paraminfo_vals` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x25e0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x25e0-0x268c (172 bytes).
  It occupies 172 bytes.
  The `lw` at 0x25e4 loads 4 bytes from a1 (arg1 at entry) +0x0.
  The `ld` at 0x25f0 loads 8 bytes from a0 (arg0 at entry) +0x118.
  The `lh` at 0x2600 loads 2 bytes from [a0+280]:8 +0x21a.
  The `sw` at 0x2654 stores 4 bytes to (a2 + (a3 << 0x3)) +0x0.
  The `sw` at 0x265c stores 4 bytes to (a2 + (a3+2 << 0x3)) -0x8.
  2 such `sw` accesses store 4 bytes to a1 (arg1 at entry) +0x4c, including `sw` at 0x2668, `sw` at 0x2688.
  The `sw` at 0x267c stores 4 bytes to (a2 + (a3+1 << 0x3)) -0x8.
  The `bne` branch at 0x2604 targets 0x2638, is taken when at(=[a1]) != v1(=0x1000002a), and falls through when at(=[a1]) == v1(=0x1000002a).
  The `beq` branch at 0x2610 targets 0x2620, is taken when a0 == a3(=[a0+280]:8+2520), and falls through when a0 != a3(=[a0+280]:8+2520).
  The `bne` branch at 0x2618 targets 0x2638, is taken when a0 != t2(=[a0+280]:8+2968), and falls through when a0 == t2(=[a0+280]:8+2968).
  The `beq` branch at 0x2620 targets 0x2644, is taken when a6(=[[a0+280]:8+538]:2) == t0(=0x7), and falls through when a6(=[[a0+280]:8+538]:2) != t0(=0x7).
  The `beq` branch at 0x2628 targets 0x2644, is taken when a6(=[[a0+280]:8+538]:2) == t1(=0xd), and falls through when a6(=[[a0+280]:8+538]:2) != t1(=0xd).
  The `beq` branch at 0x2630 targets 0x266c, is taken when a6(=[[a0+280]:8+538]:2) == t3(=0xc), and falls through when a6(=[[a0+280]:8+538]:2) != t3(=0xc).
  The return at 0x2638 has v0 = a3.
  The return at 0x2664 has v0 = a3+2.
  The return at 0x2684 has v0 = a3+1.
  The instructions from 0x2640 to 0x2640 are not reached by any path from the entry, and their branches are not listed.

- `rad_create_clockgen` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x268c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x268c-0x292c (672 bytes).
  It occupies 672 bytes.
  The `ld` at 0x26bc loads 8 bytes from a1 (arg1 at entry) +0x2a0.
  The `sw` at 0x2708 stores 4 bytes to a0 (arg0 at entry) +0x1d8.
  The `sd` at 0x270c stores 8 bytes to a0 (arg0 at entry) +0x1c0.
  The `sd` at 0x2710 stores 8 bytes to a0 (arg0 at entry) +0x1d0.
  The `sd` at 0x2714 stores 8 bytes to a0 (arg0 at entry) +0x1c8.
  The `sw` at 0x271c stores 4 bytes to a0 (arg0 at entry) +0x120.
  The `sd` at 0x2734 stores 8 bytes to a0 (arg0 at entry) +0x1a8.
  The `sd` at 0x2738 stores 8 bytes to a0 (arg0 at entry) +0x1a0.
  The `sd` at 0x273c stores 8 bytes to a0 (arg0 at entry) +0x18.
  The `sd` at 0x2740 stores 8 bytes to a0 (arg0 at entry) +0x10.
  The `sd` at 0x2748 stores 8 bytes to a0 (arg0 at entry) +0x8.
  The `sd` at 0x2750 stores 8 bytes to a0 (arg0 at entry) +0x20.
  The `sw` at 0x2758 stores 4 bytes to a0 (arg0 at entry) +0x1bc.
  The `sw` at 0x275c stores 4 bytes to a0 (arg0 at entry) +0x1b4.
  The `sw` at 0x2760 stores 4 bytes to a0 (arg0 at entry) +0x1b8.
  The `sw` at 0x2764 stores 4 bytes to a0 (arg0 at entry) +0x1b0.
  The `lw` at 0x2768 loads 4 bytes from a1 (arg1 at entry) +0x268.
  The `sw` at 0x2780 stores 4 bytes to a0 (arg0 at entry) +0x1e0.
  The `sd` at 0x2788 stores 8 bytes to a0 (arg0 at entry) +0x198.
  The `sw` at 0x278c stores 4 bytes to a0 (arg0 at entry) +0x1f8.
  The `sd` at 0x2790 stores 8 bytes to a0 (arg0 at entry) +0x1f0.
  The `sw` at 0x2798 stores 4 bytes to a0 (arg0 at entry) +0x21c.
  4 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x58, including `sd` at 0x27a0, `sd` at 0x28cc, `sd` at 0x2918.
  4 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x60, including `sd` at 0x27a8, `sd` at 0x28c4, `sd` at 0x290c.
  2 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x68, including `sd` at 0x27b0, `sd` at 0x28c0.
  2 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x70, including `sd` at 0x27b8, `sd` at 0x28bc.
  2 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x78, including `sd` at 0x27c0, `sd` at 0x28b8.
  The `sd` at 0x27c8 stores 8 bytes to a0 (arg0 at entry) +0x80.
  The `sd` at 0x27cc stores 8 bytes to a0 (arg0 at entry) +0x88.
  3 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x20c, including `sw` at 0x27d4, `sw` at 0x2908, `sw` at 0x291c.
  The `sd` at 0x27e0 stores 8 bytes to a0 (arg0 at entry) +0x1e8.
  The `lw` at 0x2820 loads 4 bytes from a0 (arg0 at entry) +0x208.
  The `sw` at 0x2838 stores 4 bytes to ([a1+672]:8 + ([a0+520] << 0x2)) +0x72cc.
  4 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x208, including `sw` at 0x28b0, `sw` at 0x28b4, `sw` at 0x28e8.
  2 such `lh` accesses load 2 bytes from [a1+672]:8 +0x21a, including `lh` at 0x28d0, `lh` at 0x28ec.
  The `jal` at 0x26c4 calls sprintf with a0=sp-112, a1=sym(.rodata), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x26d8 calls sprintf with a0=sp-80, a1=sym(.rodata), a2=a2 at entry (arg2), a3=?.
  The `jal` at 0x26fc calls kdsp_init_resource with a0=a0 at entry (arg0), a1=0x20000004, a2=sp-112, a3=sp-80, a4=[a1+672]:8, a5=0x0, a6=0x228.
  The `jal` at 0x2848 calls kdsp_select_clockgen with a0=a1 at entry (arg1), a1=a0 at entry (arg0), a2=[a1+672]:8+2072, a3=[a1+672]:8+1624, a4=0x5.
  The `jal` at 0x285c calls kdsp_add_subresource with a0=a0 at entry (arg0), a1=a3 at entry (arg3), a2=?, a3=?.
  The `jal` at 0x2878 calls rad_set_clockgen with a0=a0 at entry (arg0), a1=a3 at entry (arg3), a2=0x4, a3=0x0, a4=0x1, a5=0x1.
  The `jal` at 0x2884 calls rad_start_clockgen with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x2890 calls kdsp_map_resource with a0=a0 at entry (arg0), a1=0x0, a2=?, a3=?.
  The `beq` branch at 0x27dc targets 0x28ac, is taken when s1(=a2) == 0, and falls through when s1(=a2) != 0.
  The `beq` branch at 0x27e4 targets 0x28b4, is taken when s1(=a2) == a1(=0x1), and falls through when s1(=a2) != a1(=0x1).
  The `beq` branch at 0x27ec targets 0x28d0, is taken when s1(=a2) == t0(=0x2), and falls through when s1(=a2) != t0(=0x2).
  The `beq` branch at 0x27f4 targets 0x28ec, is taken when s1(=a2) == t1(=0x3), and falls through when s1(=a2) != t1(=0x3).
  The `beq` branch at 0x27fc targets 0x2908, is taken when s1(=a2) == a5(=0x4), and falls through when s1(=a2) != a5(=0x4).
  The `beq` branch at 0x2804 targets 0x291c, is taken when s1(=a2) == a4(=0x5), and falls through when s1(=a2) != a4(=0x5).
  The `beq` branch at 0x280c targets 0x283c, is taken when a0(=one of 0x0, 0x1) == 0, and falls through when a0(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x28ac targets 0x280c and is always taken.
  The `beq` branch at 0x28c8 targets 0x280c and is always taken.
  The `beq` branch at 0x28e4 targets 0x280c and is always taken.
  The `beq` branch at 0x2900 targets 0x280c and is always taken.
  The `beq` branch at 0x2914 targets 0x280c and is always taken.
  The `beq` branch at 0x2924 targets 0x283c and is always taken.
  The return at 0x28a4 has v0 = 0x1.

- `rad_destroy_devices` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x292c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x292c-0x2b1c (496 bytes).
  It occupies 496 bytes.
  The `ld` at 0x293c loads 8 bytes from a0 (arg0 at entry) +0xff8.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x1310, including `ld` at 0x2954, `ld` at 0x2aa8.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x1628, including `ld` at 0x2960, `ld` at 0x2ab8.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x1940, including `ld` at 0x296c, `ld` at 0x2ac8.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x1c58, including `ld` at 0x2978, `ld` at 0x2ad8.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x1f70, including `ld` at 0x2984, `ld` at 0x2ae8.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x2288, including `ld` at 0x2990, `ld` at 0x2af8.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x25a0, including `ld` at 0x299c, `ld` at 0x2b08.
  The `jal` at 0x29b4 calls kdsp_destroy_subcode with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x29c4 calls kdsp_destroy_subcode with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x2a20 calls kdsp_destroy_subcode with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x2a30 calls kdsp_destroy_subcode with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x2a9c calls kdsp_destroy_device with a0=a0+3416, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x2aac calls kdsp_destroy_device with a0=a0+4208, a1=?, a2=?, a3=?.
  The `jal` at 0x2abc calls kdsp_destroy_device with a0=a0+5000, a1=?, a2=?, a3=?.
  The `jal` at 0x2acc calls kdsp_destroy_device with a0=a0+5792, a1=?, a2=?, a3=?.
  The `jal` at 0x2adc calls kdsp_destroy_device with a0=a0+6584, a1=[a0+7256]:8, a2=?, a3=?.
  The `jal` at 0x2aec calls kdsp_destroy_device with a0=a0+7376, a1=?, a2=[a0+8048]:8, a3=?.
  The `jal` at 0x2afc calls kdsp_destroy_device with a0=a0+8168, a1=?, a2=?, a3=[a0+8840]:8.
  The `jal` at 0x2b0c calls kdsp_destroy_device with a0=a0+8960, a1=?, a2=?, a3=?, a4=[a0+9632]:8.
  The `bne` branch at 0x294c targets 0x2a9c, is taken when at(=[a0+4088]:8) != 0, and falls through when at(=[a0+4088]:8) == 0.
  The `bne` branch at 0x2958 targets 0x2aac, is taken when v0(=[a0+4880]:8) != 0, and falls through when v0(=[a0+4880]:8) == 0.
  The `bne` branch at 0x2964 targets 0x2abc, is taken when v1(=[a0+5672]:8) != 0, and falls through when v1(=[a0+5672]:8) == 0.
  The `bne` branch at 0x2970 targets 0x2acc, is taken when a0(=[a0+6464]:8) != 0, and falls through when a0(=[a0+6464]:8) == 0.
  The `bne` branch at 0x297c targets 0x2adc, is taken when a1(=[a0+7256]:8) != 0, and falls through when a1(=[a0+7256]:8) == 0.
  The `bne` branch at 0x2988 targets 0x2aec, is taken when a2(=[a0+8048]:8) != 0, and falls through when a2(=[a0+8048]:8) == 0.
  The `bne` branch at 0x2994 targets 0x2afc, is taken when a3(=[a0+8840]:8) != 0, and falls through when a3(=[a0+8840]:8) == 0.
  The `bne` branch at 0x29a0 targets 0x2b0c, is taken when a4(=[a0+9632]:8) != 0, and falls through when a4(=[a0+9632]:8) == 0.
  The `beq` branch at 0x29ac targets 0x29d8 and is always taken.
  The `beq` branch at 0x29bc targets 0x29cc, is taken when s3(=-0x52a0) == s1(?), and falls through when s3(=-0x52a0) != s1(?).
  The `beq` branch at 0x29d4 targets 0x2a10, is taken when s2(?) >= 0x3 (signed), and falls through when s2(?) < 0x3 (signed).
  The `bne` branch at 0x29f0 targets 0x29b4, is taken when s4(=-0x5168) != s1(?), and falls through when s4(=-0x5168) == s1(?).
  The `bne` branch at 0x29f8 targets 0x29c4, is taken when s3(=-0x52a0) != s1(?), and falls through when s3(=-0x52a0) == s1(?).
  The `bne` branch at 0x2a08 targets 0x29dc, is taken when s2(?) < 0x3 (signed), and falls through when s2(?) >= 0x3 (signed).
  The `beq` branch at 0x2a18 targets 0x2a44 and is always taken.
  The `beq` branch at 0x2a28 targets 0x2a38, is taken when s3(=-0x5578) == s1(?), and falls through when s3(=-0x5578) != s1(?).
  The `beq` branch at 0x2a40 targets 0x2a7c, is taken when s2(?) >= 0x4 (signed), and falls through when s2(?) < 0x4 (signed).
  The `bne` branch at 0x2a5c targets 0x2a20, is taken when s4(=-0x53d8) != s1(?), and falls through when s4(=-0x53d8) == s1(?).
  The `bne` branch at 0x2a64 targets 0x2a30, is taken when s3(=-0x5578) != s1(?), and falls through when s3(=-0x5578) == s1(?).
  The `bne` branch at 0x2a74 targets 0x2a48, is taken when s2(?) < 0x4 (signed), and falls through when s2(?) >= 0x4 (signed).
  The `beq` branch at 0x2aa4 targets 0x2958 and is always taken.
  The `beq` branch at 0x2ab4 targets 0x2964 and is always taken.
  The `beq` branch at 0x2ac4 targets 0x2970 and is always taken.
  The `beq` branch at 0x2ad4 targets 0x297c and is always taken.
  The `beq` branch at 0x2ae4 targets 0x2988 and is always taken.
  The `beq` branch at 0x2af4 targets 0x2994 and is always taken.
  The `beq` branch at 0x2b04 targets 0x29a0 and is always taken.
  The `beq` branch at 0x2b14 targets 0x29a8 and is always taken.
  The return at 0x2a94 has v0 = one of ret(kdsp_destroy_subcode), ?.

- `rad_init_subsys` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x2b1c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x2b1c-0x2b8c (112 bytes).
  It occupies 112 bytes.
  The `sd` at 0x2b40 stores 8 bytes to a0 (arg0 at entry) +0x240.
  The `sb` at 0x2b54 stores 1 byte to a0 (arg0 at entry) +0x7303.
  The `lh` at 0x2b58 loads 2 bytes from a0 (arg0 at entry) +0x21a.
  The `sw` at 0x2b5c stores 4 bytes to a0 (arg0 at entry) +0x72c8.
  The `sw` at 0x2b64 stores 4 bytes to a0 (arg0 at entry) +0x230.
  The `sw` at 0x2b70 stores 4 bytes to a0 (arg0 at entry) +0x234.
  The `sb` at 0x2b88 stores 1 byte to a0 (arg0 at entry) +0x7304.
  The `jal` at 0x2b34 calls kvpalloc with a0=0x1, a1=0x0, a2=0x0, a3=a3 at entry (arg3).
  The `jal` at 0x2b44 calls bzero with a0=ret(kvpalloc), a1=0x4000, a2=?, a3=?.
  The `beq` branch at 0x2b6c targets 0x2b84, is taken when v0(=[a0+538]:2) == v1(=0x7), and falls through when v0(=[a0+538]:2) != v1(=0x7).
  The `beq` branch at 0x2b84 targets 0x2b74 and is always taken.
  The return at 0x2b7c has v0 = 0x1.

- `rad_update_subsys` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x2b8c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x2b8c-0x3048 (1212 bytes).
  It occupies 1212 bytes.
  The `lw` at 0x2b98 loads 4 bytes from a0 (arg0 at entry) +0x230.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x238, including `lw` at 0x2bb0, `lw` at 0x2c70, `lw` at 0x2f6c.
  4 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x2c8, including `lw` at 0x2bbc, `lw` at 0x2f48, `lw` at 0x2fe0.
  7 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x240, including `ld` at 0x2be8, `ld` at 0x2c10, `ld` at 0x2c40.
  5 such `lw` accesses load 4 bytes from ?, including `lw` at 0x2bf0, `lw` at 0x2c04, `lw` at 0x2c18.
  2 such `sw` accesses store 4 bytes to ?, including `sw` at 0x2c0c, `sw` at 0x2f30.
  The `ll` at 0x2c28 loads 4 bytes from a0 (arg0 at entry) +0x2d0.
  The `sc` at 0x2c34 stores 4 bytes to a0 (arg0 at entry) +0x2d0.
  The `ll` at 0x2c58 loads 4 bytes from a0 (arg0 at entry) +0x2cc.
  The `sc` at 0x2c64 stores 4 bytes to a0 (arg0 at entry) +0x2cc.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x72f0, including `lw` at 0x2c94, `lw` at 0x2de8.
  The `sw` at 0x2ca4 stores 4 bytes to a0 (arg0 at entry) +0x72f0.
  The `sb` at 0x2cbc stores 1 byte to a0 (arg0 at entry) +0x730e.
  The `sb` at 0x2cc0 stores 1 byte to a0 (arg0 at entry) +0x730f.
  2 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x7310, including `lbu` at 0x2cc4, `lbu` at 0x2d44.
  The `lw` at 0x2cc8 loads 4 bytes from a0 (arg0 at entry) +0x2b0.
  The `lw` at 0x2ccc loads 4 bytes from a0 (arg0 at entry) +0x7238.
  The `lw` at 0x2cd0 loads 4 bytes from a0 (arg0 at entry) +0x2a8.
  2 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x7311, including `lbu` at 0x2cd4, `lbu` at 0x2d8c.
  3 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x7313, including `sb` at 0x2cd8, `sb` at 0x2db8, `sb` at 0x2dc0.
  The `lw` at 0x2ce0 loads 4 bytes from a0 (arg0 at entry) +0x723c.
  3 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x7312, including `sb` at 0x2ce4, `sb` at 0x2f04, `sb` at 0x2f10.
  The `sw` at 0x2cf4 stores 4 bytes to a0 (arg0 at entry) +0x7238.
  The `sw` at 0x2d04 stores 4 bytes to a0 (arg0 at entry) +0x723c.
  The `lbu` at 0x2d28 loads 1 byte from a0 (arg0 at entry) +0x7314.
  The `sb` at 0x2d40 stores 1 byte to a0 (arg0 at entry) +0x7314.
  The `lbu` at 0x2d70 loads 1 byte from a0 (arg0 at entry) +0x7316.
  The `sb` at 0x2d88 stores 1 byte to a0 (arg0 at entry) +0x7316.
  The `lbu` at 0x2da0 loads 1 byte from a0 (arg0 at entry) +0x7317.
  2 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x7311, including `sb` at 0x2dac, `sb` at 0x2dbc.
  The `lbu` at 0x2df4 loads 1 byte from a0 (arg0 at entry) +0x7303.
  The `ld` at 0x2e10 loads 8 bytes from a0 (arg0 at entry) +0x72e0.
  The `lw` at 0x2e20 loads 4 bytes from a0 (arg0 at entry) +0x2d0.
  The `lw` at 0x2e24 loads 4 bytes from a0 (arg0 at entry) +0x2cc.
  The `ld` at 0x2e30 loads 8 bytes from a0 (arg0 at entry) +0x72e8.
  2 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x72e8, including `sd` at 0x2e44, `sd` at 0x2fc4.
  The `lh` at 0x2e64 loads 2 bytes from a0 (arg0 at entry) +0x21a.
  The `sw` at 0x2e68 stores 4 bytes to a0 (arg0 at entry) +0x2d0.
  The `sw` at 0x2e70 stores 4 bytes to a0 (arg0 at entry) +0x2cc.
  The `sd` at 0x2e7c stores 8 bytes to a0 (arg0 at entry) +0x72e0.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x2bc, including `lw` at 0x2e8c, `lw` at 0x2eb4, `lw` at 0x2f7c.
  2 such `sb` accesses store 1 byte to ?, including `sb` at 0x2ea8, `sb` at 0x2ed4.
  The `lbu` at 0x2ee8 loads 1 byte from a0 (arg0 at entry) +0x7315.
  2 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x7310, including `sb` at 0x2ef8, `sb` at 0x2f08.
  2 such `lw` accesses load 4 bytes from ([a0+576]:8 + ([a0+712] << 0x7)) +0x7c, including `lw` at 0x2f60, `lw` at 0x2ff0.
  2 such `sw` accesses store 4 bytes to ([a0+576]:8 + ([a0+712] << 0x7)) +0x7c, including `sw` at 0x2f68, `sw` at 0x2ff8.
  The `sw` at 0x2f70 stores 4 bytes to a0 (arg0 at entry) +0x2c8.
  2 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x7304, including `lbu` at 0x2f80, `lbu` at 0x2f94.
  The `sb` at 0x2f90 stores 1 byte to ([a0+29444]:1 + a0) +0x7305.
  The `ld` at 0x2fa8 loads 8 bytes from a0 (arg0 at entry) +0x228.
  The `sw` at 0x2fb0 stores 4 bytes to a0 (arg0 at entry) +0x726c.
  The `sw` at 0x2fb8 stores 4 bytes to [a0+552]:8 +0x8c.
  2 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x7304, including `sb` at 0x2fd0, `sb` at 0x2fdc.
  The `jal` at 0x2ca8 calls rad_check_adat_rx with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x2cb4 calls rad_process_aesrx_subcode with a0=a0 at entry (arg0), a1=0x0, a2=?, a3=?.
  The `jal` at 0x2d20 calls kdsp_update_default_subcode with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x2d68 calls kdsp_update_default_subcode with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x2db4 calls rad_pio_writeback_subcode_tx with a0=a0+17672, a1=[a0+29457]:1, a2=?, a3=0x1.
  The `jal` at 0x2e00 calls update_ust with a0=?, a1=?, a2=?, a3=?, a5=[a0+29443]:1.
  The `jal` at 0x2e08 calls get_ust_nano with a0=sp-64, a1=?, a2=?, a3=?.
  The `jal` at 0x2e58 calls rad_update_ksync with a0=a0 at entry (arg0), a1=?, a2=?, a3=([a0+716] + [a0+720]), a4=[a0+29416]:8, a6=[a0+29408]:8.
  The `jal` at 0x2f00 calls rad_pio_writeback_subcode_tx with a0=a0+12128, a1=[a0+29456]:1, a2=?, a3=?.
  The `jal` at 0x2f40 calls bcopy with a0=?, a1=a0+584, a2=0x80, a3=?, a6=[a0+576]:8, a7=a0+720.
  The `jal` at 0x3010 calls bcopy with a0=([a0+576]:8 + ([a0+712] << 0x7)), a1=a0+584, a2=0x80, a3=([a0+712] << 0x7), a4=(0xffffffff80000000 | [([a0+576]:8 + ([a0+712] << 0x7))+124]), a5=([a0+576]:8 + ([a0+712] << 0x7)), a6=[a0+576]:8.
  The `jal` at 0x3020 calls cmn_err with a0=0x1, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x3028 calls rad_stop_status_dma with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x3030 calls rad_start_status_dma with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `beq` branch at 0x2ba8 targets 0x2dc4, is taken when at(=[a0+560]) == 0, and falls through when at(=[a0+560]) != 0.
  The `bne` branch at 0x2bb8 targets 0x2de0, is taken when a0(=[a0+568]) < 0x2 (signed), and falls through when a0(=[a0+568]) >= 0x2 (signed).
  The `beq` branch at 0x2bfc targets 0x2f14, is taken when (s2(=0xffffffff80000000) & t8(?)) == 0, and falls through when (s2(=0xffffffff80000000) & t8(?)) != 0.
  The `beq` branch at 0x2c20 targets 0x2c48, is taken when (a6(?) & 0x100) == 0, and falls through when (a6(?) & 0x100) != 0.
  The `beql` branch at 0x2c38 targets 0x2c28, is taken when a4(=[a0+720]+1) == 0, and falls through when a4(=[a0+720]+1) != 0; its branch-likely delay slot `nop` at 0x2c3c runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x2c50 targets 0x2c70, is taken when (a6(?) & 0x80) == 0, and falls through when (a6(?) & 0x80) != 0.
  The `beql` branch at 0x2c68 targets 0x2c58, is taken when t2(=[a0+716]+1) == 0, and falls through when t2(=[a0+716]+1) != 0; its branch-likely delay slot `nop` at 0x2c6c runs only when taken and is annulled on fall-through.
  The `bne` branch at 0x2c84 targets 0x2be8, is taken when s1(?) < a4(=[a0+568]-1) (signed), and falls through when s1(?) >= a4(=[a0+568]-1) (signed).
  The `beq` branch at 0x2c8c targets 0x2fe0, is taken when a4(=[a0+568]-1) == s1(?), and falls through when a4(=[a0+568]-1) != s1(?).
  The `beq` branch at 0x2ca0 targets 0x2df4, is taken when (a5(=[a0+29424]+1) & 0x3ff) == 0, and falls through when (a5(=[a0+29424]+1) & 0x3ff) != 0.
  The `bne` branch at 0x2d3c targets 0x2d08, is taken when s1(?) < 0x3 (signed), and falls through when s1(?) >= 0x3 (signed).
  The `beq` branch at 0x2d48 targets 0x2ee0, is taken when a1(=[a0+29456]:1) == 0, and falls through when a1(=[a0+29456]:1) != 0.
  The `bne` branch at 0x2d84 targets 0x2d50, is taken when s1(?) < 0x4 (signed), and falls through when s1(?) >= 0x4 (signed).
  The `bne` branch at 0x2d90 targets 0x2dc8, is taken when a1(=[a0+29457]:1) != 0, and falls through when a1(=[a0+29457]:1) == 0.
  The `bne` branch at 0x2d98 targets 0x2dac, is taken when a0(?) != 0, and falls through when a0(?) == 0.
  The `beq` branch at 0x2da4 targets 0x2dc4, is taken when a2(=[a0+29463]:1) == 0, and falls through when a2(=[a0+29463]:1) != 0.
  The `bnel` branch at 0x2de4 targets 0x2c98, is taken when a0(=[a0+568]) != a4(=0x1), and falls through when a0(=[a0+568]) == a4(=0x1); its branch-likely delay slot `lw a5,29424(s0)` at 0x2de8 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x2dec targets 0x3040 and is always taken.
  The `beq` branch at 0x2df8 targets 0x2ca8, is taken when a5(=[a0+29443]:1) == 0, and falls through when a5(=[a0+29443]:1) != 0.
  The `beq` branch at 0x2e18 targets 0x2e60, is taken when a6(=[a0+29408]:8) == 0, and falls through when a6(=[a0+29408]:8) != 0.
  The `blez` branch at 0x2e2c targets 0x2fbc, is taken when a3(=([a0+716] + [a0+720])) <= 0 (signed), and falls through when a3(=([a0+716] + [a0+720])) > 0 (signed).
  The `bgtz` branch at 0x2e48 targets 0x2e58, is taken when a0(?) > 0 (signed), and falls through when a0(?) <= 0 (signed).
  The `blez` branch at 0x2e50 targets 0x2e64, is taken when a4(=[a0+29416]:8) <= 0 (signed), and falls through when a4(=[a0+29416]:8) > 0 (signed).
  The `beq` branch at 0x2e78 targets 0x2f7c, is taken when a0(=[a0+538]:2) == a6(=0x7), and falls through when a0(=[a0+538]:2) != a6(=0x7).
  The `bne` branch at 0x2e84 targets 0x2ca8, is taken when a0(=[a0+538]:2) != a7(=0xd), and falls through when a0(=[a0+538]:2) == a7(=0xd).
  The `beq` branch at 0x2eac targets 0x2ca8, is taken when a0(?) >= 0x4 (signed), and falls through when a0(?) < 0x4 (signed).
  The `bne` branch at 0x2ed0 targets 0x2e8c, is taken when a0(?) < 0x4 (signed), and falls through when a0(?) >= 0x4 (signed).
  The `beq` branch at 0x2ed8 targets 0x2ca8 and is always taken.
  The `bne` branch at 0x2ee0 targets 0x2ef8, is taken when a0(?) != 0, and falls through when a0(?) == 0.
  The `beq` branch at 0x2eec targets 0x2d50, is taken when t3(=[a0+29461]:1) == 0, and falls through when t3(=[a0+29461]:1) != 0.
  The `beq` branch at 0x2f0c targets 0x2d4c and is always taken.
  The `beq` branch at 0x2f50 targets 0x2f6c, is taken when a0(?) == a5(=[a0+712]), and falls through when a0(?) != a5(=[a0+712]).
  The `beq` branch at 0x2f74 targets 0x2c8c and is always taken.
  The `beq` branch at 0x2f98 targets 0x2fc8, is taken when a0(=[a0+29444]:1) == 0, and falls through when a0(=[a0+29444]:1) != 0.
  The `beq` branch at 0x2fa0 targets 0x2fd4, is taken when a0(=[a0+29444]:1) == a2(=0x1), and falls through when a0(=[a0+29444]:1) != a2(=0x1).
  The `beq` branch at 0x2fb4 targets 0x2ca8 and is always taken.
  The `beq` branch at 0x2fc0 targets 0x2e48 and is always taken.
  The `beq` branch at 0x2fcc targets 0x2fa8 and is always taken.
  The `beq` branch at 0x2fd8 targets 0x2fa8 and is always taken.
  The `beq` branch at 0x3038 targets 0x2dc8 and is always taken.
  The `beq` branch at 0x3040 targets 0x2fe4 and is always taken.
  The return at 0x2dd8 has v0 = one of ret(kdsp_update_default_subcode), ?, ret(rad_start_status_dma).

- `rad_start_status_dma` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x3048 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x3048-0x31d4 (396 bytes).
  It occupies 396 bytes.
  The `lw` at 0x3048 loads 4 bytes from a0 (arg0 at entry) +0x230.
  3 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x238, including `sw` at 0x306c, `sw` at 0x3098, `sw` at 0x31c0.
  5 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x240, including `ld` at 0x30a4, `ld` at 0x30c8, `ld` at 0x30f4.
  2 such `sw` accesses store 4 bytes to ?, including `sw` at 0x30b0, `sw` at 0x30d4.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x238, including `lw` at 0x30b4, `lw` at 0x30d8, `lw` at 0x3128.
  7 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x228, including `ld` at 0x312c, `ld` at 0x3140, `ld` at 0x3148.
  The `sw` at 0x313c stores 4 bytes to [a0+552]:8 +0x504.
  The `sw` at 0x3144 stores 4 bytes to [a0+552]:8 +0x500.
  The `sw` at 0x3150 stores 4 bytes to [a0+552]:8 +0x528.
  The `sw` at 0x3158 stores 4 bytes to [a0+552]:8 +0x4bc.
  The `sw` at 0x3160 stores 4 bytes to [a0+552]:8 +0x4b4.
  The `sw` at 0x3168 stores 4 bytes to [a0+552]:8 +0x4b8.
  The `lw` at 0x316c loads 4 bytes from a0 (arg0 at entry) +0x234.
  The `sw` at 0x3194 stores 4 bytes to [a0+552]:8 +0x5c.
  The `sw` at 0x3198 stores 4 bytes to a0 (arg0 at entry) +0x2c8.
  The `sw` at 0x31a4 stores 4 bytes to a0 (arg0 at entry) +0x230.
  The `jal` at 0x30f0 calls rad_one_shot_status with a0=a0 at entry (arg0), a1=[a0+576]:8, a2=?, a3=?.
  The `jal` at 0x3110 calls bcopy with a0=[a0+576]:8, a1=a0+584, a2=0x80, a3=?.
  The `jal` at 0x3120 calls Mem_to_PCI_DMA with a0=a0 at entry (arg0), a1=[a0+576]:8, a2=0x1000, a3=?.
  The `jal` at 0x31c4 calls us_delay with a0=0x12c, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=0x1, a4=0x80.
  The `bne` branch at 0x3060 targets 0x31c4, is taken when at(=[a0+560]) != 0, and falls through when at(=[a0+560]) == 0.
  The `beq` branch at 0x3078 targets 0x3090, is taken when v0(?) >= 0x80 (signed), and falls through when v0(?) < 0x80 (signed).
  The `bne` branch at 0x3088 targets 0x3070, is taken when v0(?) < 0x80 (signed), and falls through when v0(?) >= 0x80 (signed).
  The `beq` branch at 0x3094 targets 0x31bc, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `blez` branch at 0x309c targets 0x30ec, is taken when v0(?) <= 0 (signed), and falls through when v0(?) > 0 (signed).
  The `beq` branch at 0x30c0 targets 0x30ec, is taken when v0(?) >= a2(=[a0+568]) (signed), and falls through when v0(?) < a2(=[a0+568]) (signed).
  The `bne` branch at 0x30e4 targets 0x30a4, is taken when v0(?) < a5(=[a0+568]) (signed), and falls through when v0(?) >= a5(=[a0+568]) (signed).
  The `bne` branch at 0x30f8 targets 0x3108, is taken when v0(=ret(rad_one_shot_status)) != 0, and falls through when v0(=ret(rad_one_shot_status)) == 0.
  The `beq` branch at 0x3100 targets 0x31ac and is always taken.
  The `beq` branch at 0x31bc targets 0x31a8 and is always taken.
  The `beq` branch at 0x31cc targets 0x31a8 and is always taken.
  The return at 0x31b4 has v0 = one of 0x0, 0x1.

- `rad_stop_status_dma` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x31d4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x31d4-0x3200 (44 bytes).
  It occupies 44 bytes.
  The `lw` at 0x31d4 loads 4 bytes from a0 (arg0 at entry) +0x230.
  The `ld` at 0x31e0 loads 8 bytes from a0 (arg0 at entry) +0x228.
  The `sw` at 0x31ec stores 4 bytes to [a0+552]:8 +0x5c.
  The `sw` at 0x31f4 stores 4 bytes to a0 (arg0 at entry) +0x230.
  The `beq` branch at 0x31d8 targets 0x31f8, is taken when at(=[a0+560]) == 0, and falls through when at(=[a0+560]) != 0.
  The return at 0x31f8 has v0 = 0x1.

- `rad_sync_device_ust` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x3200 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x3200-0x3334 (308 bytes).
  It occupies 308 bytes.
  The `ld` at 0x3228 loads 8 bytes from a0 (arg0 at entry) +0x2a0.
  The `ld` at 0x3250 loads 8 bytes from [a0+672]:8 +0x72a8.
  6 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x1b0, including `sd` at 0x3294, `sd` at 0x32a4, `sd` at 0x32d0.
  The `lw` at 0x32a8 loads 4 bytes from a0 (arg0 at entry) +0x314.
  The `sw` at 0x32f8 stores 4 bytes to a0 (arg0 at entry) +0x310.
  The `jal` at 0x3224 calls update_ust with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x322c calls get_ust_nano with a0=sp-48, a1=?, a2=?, a3=?.
  The `beq` branch at 0x3290 targets 0x3308, is taken when at(?) == 0, and falls through when at(?) != 0.
  The `beq` branch at 0x3298 targets 0x32a8, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0x32ac targets 0x32f0, is taken when t0(=[a0+788]) == 0, and falls through when t0(=[a0+788]) != 0.
  The `bltz` branch at 0x32d4 targets 0x3324, is taken when t1(?) < 0 (signed), and falls through when t1(?) >= 0 (signed).
  The `beq` branch at 0x32e0 targets 0x32f4, is taken when s1(=a2) >= a2(?) (unsigned), and falls through when s1(=a2) < a2(?) (unsigned).
  The `beq` branch at 0x3310 targets 0x32a8, is taken when s2(=a1) >= a5(?) (unsigned), and falls through when s2(=a1) < a5(?) (unsigned).
  The `beq` branch at 0x331c targets 0x32a8 and is always taken.
  The `beq` branch at 0x3324 targets 0x32f4, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `beq` branch at 0x332c targets 0x32f0 and is always taken.
  The return at 0x3300 has v0 = ret(get_ust_nano).

- `rad_start_dma` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x3334 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x3334-0x37f0 (1212 bytes).
  It occupies 1212 bytes.
  The `ld` at 0x333c loads 8 bytes from a0 (arg0 at entry) +0x2a0.
  4 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x2c0, including `lw` at 0x3344, `lw` at 0x3508, `lw` at 0x35ac.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x268, including `lw` at 0x336c, `lw` at 0x33c8.
  The `lw` at 0x337c loads 4 bytes from a0 (arg0 at entry) +0x238.
  The `lbu` at 0x3398 loads 1 byte from ([a0+672]:8 + one of 0x225c, 0x2574) +0x0.
  4 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x1b8, including `ld` at 0x33c0, `ld` at 0x33f4, `ld` at 0x3458.
  The `sw` at 0x33c4 stores 4 bytes to [a0+440]:8 +0x0.
  The `lw` at 0x33d0 loads 4 bytes from a0 (arg0 at entry) +0x220.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x1c8, including `ld` at 0x33d4, `ld` at 0x347c.
  The `ld` at 0x33e0 loads 8 bytes from a0 (arg0 at entry) +0x1f0.
  The `lw` at 0x33e4 loads 4 bytes from a0 (arg0 at entry) +0x23c.
  The `lw` at 0x33e8 loads 4 bytes from [a0+496]:8 +0x1d8.
  2 such `sw` accesses store 4 bytes to [a0+440]:8 +0x4, including `sw` at 0x33f8, `sw` at 0x346c.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0x3404, `lw` at 0x340c.
  5 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x314, including `sw` at 0x3408, `sw` at 0x3610, `sw` at 0x3684.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x310, including `sw` at 0x3410, `sw` at 0x376c.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0x3414, `ld` at 0x341c.
  2 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x308, including `sd` at 0x3418, `sd` at 0x3728.
  2 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x1a8, including `sd` at 0x3420, `sd` at 0x3718.
  The `sb` at 0x3424 stores 1 byte to a0 (arg0 at entry) +0x274.
  The `lw` at 0x3428 loads 4 bytes from [a0+672]:8 +0x72c8.
  The `sw` at 0x3434 stores 4 bytes to [a0+672]:8 +0x72c8.
  The `ld` at 0x3470 loads 8 bytes from a0 (arg0 at entry) +0x1d0.
  The `ld` at 0x3474 loads 8 bytes from a0 (arg0 at entry) +0x1e0.
  12 such `ld` accesses load 8 bytes from [a0+672]:8 +0x228, including `ld` at 0x3488, `ld` at 0x3498, `ld` at 0x34ac.
  The `lwu` at 0x348c loads 4 bytes from a0 (arg0 at entry) +0x2cc.
  The `sw` at 0x3494 stores 4 bytes to ([a0+716] + [[a0+672]:8+552]:8) +0x0.
  The `lwu` at 0x349c loads 4 bytes from a0 (arg0 at entry) +0x2c8.
  The `sw` at 0x34a8 stores 4 bytes to ([a0+712] + [[a0+672]:8+552]:8) +0x0.
  The `lw` at 0x34b0 loads 4 bytes from a0 (arg0 at entry) +0x2f0.
  The `lw` at 0x34b4 loads 4 bytes from a0 (arg0 at entry) +0x2e0.
  The `lwu` at 0x34b8 loads 4 bytes from a0 (arg0 at entry) +0x2d0.
  The `sw` at 0x34d4 stores 4 bytes to ([a0+720] + [[a0+672]:8+552]:8) +0x0.
  The `lwu` at 0x34dc loads 4 bytes from a0 (arg0 at entry) +0x2d8.
  The `sw` at 0x34e4 stores 4 bytes to ([a0+728] + [[a0+672]:8+552]:8) +0x0.
  The `lwu` at 0x34ec loads 4 bytes from a0 (arg0 at entry) +0x2d4.
  The `sw` at 0x34f4 stores 4 bytes to ([a0+724] + [[a0+672]:8+552]:8) +0x0.
  The `lwu` at 0x34fc loads 4 bytes from a0 (arg0 at entry) +0x2dc.
  The `sw` at 0x3504 stores 4 bytes to ([a0+732] + [[a0+672]:8+552]:8) +0x0.
  2 such `lh` accesses load 2 bytes from table(sym(.data)) +0x0, including `lh` at 0x3528, `lh` at 0x35f8.
  2 such `lh` accesses load 2 bytes from table(sym(.data)) +0x8, including `lh` at 0x352c, `lh` at 0x35c4.
  2 such `lw` accesses load 4 bytes from table(sym(.data)) +0xc, including `lw` at 0x3530, `lw` at 0x35e4.
  2 such `lh` accesses load 2 bytes from table(sym(.data)) +0xa, including `lh` at 0x3538, `lh` at 0x35d0.
  The `lh` at 0x3548 loads 2 bytes from table(sym(.data)) +0x2.
  2 such `lw` accesses load 4 bytes from ([[a0+672]:8+552]:8 + ([table(sym(.data))+8]:2 << 0x2)) -0x40, including `lw` at 0x354c, `lw` at 0x35dc.
  2 such `lw` accesses load 4 bytes from ([[a0+672]:8+552]:8 + (entry(sym(.data)) << 0x2)) -0x40, including `lw` at 0x3554, `lw` at 0x360c.
  The `lw` at 0x355c loads 4 bytes from table(sym(.data)) +0x4.
  4 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x2e8, including `ld` at 0x3624, `ld` at 0x3644, `ld` at 0x3698.
  4 such `lw` accesses load 4 bytes from [a0+744]:8 +0x0, including `lw` at 0x362c, `lw` at 0x3658, `lw` at 0x36a0.
  2 such `sw` accesses store 4 bytes to [a0+744]:8 +0x0, including `sw` at 0x3640, `sw` at 0x36a8.
  2 such `lwu` accesses load 4 bytes from a0 (arg0 at entry) +0x2e4, including `lwu` at 0x364c, `lwu` at 0x36b0.
  2 such `sw` accesses store 4 bytes to ([a0+740] + [[a0+672]:8+552]:8) +0x0, including `sw` at 0x3664, `sw` at 0x36c8.
  The `ld` at 0x36e0 loads 8 bytes from a0 (arg0 at entry) +0x1a8.
  The `lw` at 0x3744 loads 4 bytes from [[a0+672]:8+552]:8 +0x30.
  The `sw` at 0x3754 stores 4 bytes to a0 (arg0 at entry) +0x2c4.
  The `lw` at 0x377c loads 4 bytes from [a0+672]:8 +0x2c0.
  2 such `sb` accesses store 1 byte to [a0+672]:8 +0x7309, including `sb` at 0x378c, `sb` at 0x37c4.
  2 such `sb` accesses store 1 byte to [a0+672]:8 +0x800, including `sb` at 0x3790, `sb` at 0x37c8.
  The `lw` at 0x37ac loads 4 bytes from [a0+672]:8 +0x7240.
  The `sw` at 0x37bc stores 4 bytes to [a0+672]:8 +0x7240.
  The `sw` at 0x37c0 stores 4 bytes to [[a0+672]:8+552]:8 +0x80.
  The `lw` at 0x37dc loads 4 bytes from [a0+672]:8 +0x731c.
  The `jal` at 0x33a4 calls rad_start_dma with a0=([a0+672]:8 + one of 0x1fe8, 0x2300), a1=0x7, a2=[([a0+672]:8 + one of 0x225c, 0x2574)]:1, a3=[a0+704].
  The `jal` at 0x33ec calls bzero with a0=[a0+456]:8, a1=([a0+544] << 0x2), a2=?, a3=[a0+440]:8.
  The `jal` at 0x345c calls bzero with a0=[a0+456]:8, a1=([a0+544] << 0x2), a2=?, a3=[a0+440]:8.
  The `jal` at 0x3480 calls Mem_to_PCI_DMA with a0=[a0+672]:8, a1=[a0+456]:8, a2=?, a3=[a0+464]:8.
  The `jal` at 0x35a4 calls us_delay with a0=0xa, a1=?, a2=?, a3=?, a5=sym(.data).
  The `jal` at 0x3740 calls rad_sync_device_ust with a0=a0 at entry (arg0), a1=[[[a0+672]:8+552]:8+48], a2=?, a3=?, a6=[([[a0+672]:8+552]:8 + (entry(sym(.data)) << 0x2))-64].
  The `jal` at 0x3750 calls rad_start_status_dma with a0=[a0+672]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x37e0 calls cmn_err with a0=0x1, a1=sym(.rodata), a2=[[a0+672]:8+29468], a3=[a0+704].
  The `beq` branch at 0x3358 targets 0x37d4, is taken when a3(=[a0+704]) == at(=-0x2), and falls through when a3(=[a0+704]) != at(=-0x2).
  The `beq` branch at 0x3364 targets 0x37d8, is taken when a3(=[a0+704]) == v0(=-0x1), and falls through when a3(=[a0+704]) != v0(=-0x1).
  The `beq` branch at 0x3374 targets 0x3454, is taken when (v1(=[a0+616]) & 0x400) == 0, and falls through when (v1(=[a0+616]) & 0x400) != 0.
  The `beq` branch at 0x3384 targets 0x33bc, is taken when a0(=[a0+568]) >= 0x20 (signed), and falls through when a0(=[a0+568]) < 0x20 (signed).
  The `beq` branch at 0x338c targets 0x3398, is taken when a3(=[a0+704]) == a1(=0x7), and falls through when a3(=[a0+704]) != a1(=0x7).
  The `bne` branch at 0x339c targets 0x33c0, is taken when a2(=[([a0+672]:8 + one of 0x225c, 0x2574)]:1) != 0, and falls through when a2(=[([a0+672]:8 + one of 0x225c, 0x2574)]:1) == 0.
  The `bne` branch at 0x33ac targets 0x33c0, is taken when v0(=ret(rad_start_dma)) != 0, and falls through when v0(=ret(rad_start_dma)) == 0.
  The `beq` branch at 0x33b4 targets 0x3438 and is always taken.
  The `beq` branch at 0x33d8 targets 0x345c, is taken when (a2(=[a0+616]) & 0x1) == 0, and falls through when (a2(=[a0+616]) & 0x1) != 0.
  The `beq` branch at 0x33fc targets 0x3470, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `beq` branch at 0x3454 targets 0x33c4 and is always taken.
  The `beq` branch at 0x3468 targets 0x33fc and is always taken.
  The `beq` branch at 0x3574 targets 0x379c, is taken when a3(=[a0+704]) == a1(=0x7), and falls through when a3(=[a0+704]) != a1(=0x7).
  The `beq` branch at 0x357c targets 0x379c, is taken when a3(=[a0+704]) == a0(=0x6), and falls through when a3(=[a0+704]) != a0(=0x6).
  The `beq` branch at 0x3594 targets 0x3620 and is always taken.
  The `bne` branch at 0x359c targets 0x35f8, is taken when t8(?) != a3(?), and falls through when t8(?) == a3(?).
  The `bne` branch at 0x35f0 targets 0x359c, is taken when s2(?) < 0x32 (signed), and falls through when s2(?) >= 0x32 (signed).
  The `beq` branch at 0x3608 targets 0x3668, is taken when s2(?) == a7(=0x32), and falls through when s2(?) != a7(=0x32).
  The `beq` branch at 0x3618 targets 0x36e0, is taken when a7(=one of 0x0, 0x1) == 0, and falls through when a7(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x3660 targets 0x35a4 and is always taken.
  The `bne` branch at 0x3674 targets 0x3688, is taken when a0(?) != ra(?), and falls through when a0(?) == ra(?).
  The `beq` branch at 0x3680 targets 0x36d4 and is always taken.
  The `beq` branch at 0x3690 targets 0x36d0, is taken when at(?) >= 0x6 (signed), and falls through when at(?) < 0x6 (signed).
  The `beq` branch at 0x36d8 targets 0x3614 and is always taken.
  The `beq` branch at 0x3758 targets 0x37a4, is taken when v0(=ret(rad_start_status_dma)) == 0, and falls through when v0(=ret(rad_start_status_dma)) != 0.
  The `beq` branch at 0x3768 targets 0x377c, is taken when a3(=[a0+704]) == t1(=0x4), and falls through when a3(=[a0+704]) != t1(=0x4).
  The `bne` branch at 0x3774 targets 0x3424, is taken when a3(=[a0+704]) != t2(=0x7), and falls through when a3(=[a0+704]) == t2(=0x7).
  The `beq` branch at 0x3784 targets 0x37ac, is taken when (t3(=[[a0+672]:8+704]) & 0x40) == 0, and falls through when (t3(=[[a0+672]:8+704]) & 0x40) != 0.
  The `beq` branch at 0x3794 targets 0x3424 and is always taken.
  The `beq` branch at 0x379c targets 0x3584 and is always taken.
  The `beq` branch at 0x37a4 targets 0x3438 and is always taken.
  The `beq` branch at 0x37cc targets 0x3424 and is always taken.
  The `beq` branch at 0x37e8 targets 0x3438 and is always taken.
  The return at 0x344c has v0 = one of 0x0, 0x1.

- `rad_start_subcode_tx` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x37f0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x37f0-0x39b4 (452 bytes).
  It occupies 452 bytes.
  The `lbu` at 0x37f8 loads 1 byte from a0 (arg0 at entry) +0x274.
  The `ld` at 0x37fc loads 8 bytes from a0 (arg0 at entry) +0x2a0.
  2 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x1b0, including `sd` at 0x3820, `sd` at 0x38bc.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x1b8, including `ld` at 0x3838, `ld` at 0x388c.
  The `sw` at 0x383c stores 4 bytes to [a0+440]:8 +0x0.
  The `lw` at 0x3840 loads 4 bytes from a0 (arg0 at entry) +0x220.
  The `ld` at 0x3844 loads 8 bytes from a0 (arg0 at entry) +0x1c8.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x2e8, including `ld` at 0x3850, `ld` at 0x3860.
  2 such `lw` accesses load 4 bytes from [a0+744]:8 +0x0, including `lw` at 0x3854, `lw` at 0x3870.
  The `sw` at 0x385c stores 4 bytes to [a0+744]:8 +0x0.
  3 such `ld` accesses load 8 bytes from [a0+672]:8 +0x228, including `ld` at 0x3864, `ld` at 0x3930, `ld` at 0x3990.
  The `lwu` at 0x3868 loads 4 bytes from a0 (arg0 at entry) +0x2e4.
  The `sw` at 0x3874 stores 4 bytes to ([a0+740] + [[a0+672]:8+552]:8) +0x0.
  The `lw` at 0x3878 loads 4 bytes from a0 (arg0 at entry) +0x268.
  The `lw` at 0x3880 loads 4 bytes from a0 (arg0 at entry) +0x23c.
  The `sw` at 0x389c stores 4 bytes to [a0+440]:8 +0x4.
  The `ld` at 0x38a0 loads 8 bytes from a0 (arg0 at entry) +0x1a8.
  The `lw` at 0x38a4 loads 4 bytes from a0 (arg0 at entry) +0x2c0.
  2 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x1a8, including `sd` at 0x38ec, `sd` at 0x396c.
  The `lbu` at 0x38f0 loads 1 byte from [a0+672]:8 +0x7311.
  The `sb` at 0x38f8 stores 1 byte to [a0+672]:8 +0x7311.
  The `sw` at 0x390c stores 4 bytes to a0 (arg0 at entry) +0x2c4.
  The `sb` at 0x3910 stores 1 byte to a0 (arg0 at entry) +0x274.
  The `lw` at 0x3914 loads 4 bytes from [a0+672]:8 +0x72c8.
  The `sw` at 0x3924 stores 4 bytes to [a0+672]:8 +0x72c8.
  The `lh` at 0x392c loads 2 bytes from sym(.data) +0x50.
  The `lh` at 0x3938 loads 2 bytes from sym(.data) +0x52.
  The `lw` at 0x3940 loads 4 bytes from ([[a0+672]:8+552]:8 + ([sym(.data)+80]:2 << 0x2)) -0x40.
  The `lw` at 0x3944 loads 4 bytes from sym(.data) +0x54.
  The `lbu` at 0x3970 loads 1 byte from [a0+672]:8 +0x7310.
  The `sb` at 0x397c stores 1 byte to [a0+672]:8 +0x7310.
  The `lh` at 0x398c loads 2 bytes from sym(.data) +0x80.
  The `lh` at 0x399c loads 2 bytes from sym(.data) +0x82.
  The `lw` at 0x39a0 loads 4 bytes from ([[a0+672]:8+552]:8 + ([sym(.data)+128]:2 << 0x2)) -0x40.
  The `lw` at 0x39a4 loads 4 bytes from sym(.data) +0x84.
  The `jal` at 0x3810 calls update_ust with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x3848 calls bzero with a0=[a0+456]:8, a1=([a0+544] << 0x2), a2=[a0+440]:8, a3=a3 at entry (arg3).
  The `jal` at 0x3898 calls update_ust with a0=?, a1=?, a2=?, a3=?, a4=[a0+440]:8, a5=[a0+572], a7=0x1.
  The `jal` at 0x38fc calls rad_start_status_dma with a0=[a0+672]:8, a1=?, a2=?, a3=?, a5=-0x1.
  The `beq` branch at 0x3808 targets 0x3838, is taken when at(=[a0+628]:1) == 0, and falls through when at(=[a0+628]:1) != 0.
  The `beq` branch at 0x38c0 targets 0x3928, is taken when v0(=[a0+704]) == a5(=-0x1), and falls through when v0(=[a0+704]) != a5(=-0x1).
  The `beq` branch at 0x38c8 targets 0x3988, is taken when v0(=[a0+704]) == a4(=-0x2), and falls through when v0(=[a0+704]) != a4(=-0x2).
  The `beq` branch at 0x38e8 targets 0x3970, is taken when v0(=[a0+704]) == a5(=-0x1), and falls through when v0(=[a0+704]) != a5(=-0x1).
  The `beq` branch at 0x3904 targets 0x3980, is taken when v0(=ret(rad_start_status_dma)) == 0, and falls through when v0(=ret(rad_start_status_dma)) != 0.
  The `beq` branch at 0x3920 targets 0x3824 and is always taken.
  The `bne` branch at 0x3968 targets 0x38f0, is taken when v0(=[a0+704]) != a5(=-0x1), and falls through when v0(=[a0+704]) == a5(=-0x1).
  The `beq` branch at 0x3978 targets 0x38fc and is always taken.
  The `beq` branch at 0x3980 targets 0x3824 and is always taken.
  The `beq` branch at 0x39ac targets 0x38d0 and is always taken.
  The return at 0x3830 has v0 = one of 0x0, 0x1.

- `rad_stop_dma` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x39b4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x39b4-0x3bd8 (548 bytes).
  It occupies 548 bytes.
  The `lbu` at 0x39bc loads 1 byte from a0 (arg0 at entry) +0x274.
  The `ld` at 0x39c8 loads 8 bytes from a0 (arg0 at entry) +0x2a0.
  The `lw` at 0x39e4 loads 4 bytes from a0 (arg0 at entry) +0x2c0.
  6 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x2e8, including `ld` at 0x3a08, `ld` at 0x3a18, `ld` at 0x3b0c.
  4 such `lw` accesses load 4 bytes from [a0+744]:8 +0x0, including `lw` at 0x3a0c, `lw` at 0x3a28, `lw` at 0x3bac.
  3 such `sw` accesses store 4 bytes to [a0+744]:8 +0x0, including `sw` at 0x3a14, `sw` at 0x3bbc, `sw` at 0x3bd4.
  2 such `ld` accesses load 8 bytes from [a0+672]:8 +0x228, including `ld` at 0x3a1c, `ld` at 0x3a30.
  2 such `lwu` accesses load 4 bytes from a0 (arg0 at entry) +0x2e4, including `lwu` at 0x3a20, `lwu` at 0x3a34.
  The `sw` at 0x3a2c stores 4 bytes to ([a0+740] + [[a0+672]:8+552]:8) +0x0.
  The `lw` at 0x3a38 loads 4 bytes from [a0+672]:8 +0x731c.
  2 such `lw` accesses load 4 bytes from ([a0+740] + [[a0+672]:8+552]:8) +0x0, including `lw` at 0x3a40, `lw` at 0x3a48.
  3 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x274, including `sb` at 0x3a54, `sb` at 0x3aa0, `sb` at 0x3ba4.
  The `lw` at 0x3a58 loads 4 bytes from [a0+672]:8 +0x72c8.
  The `sw` at 0x3a60 stores 4 bytes to [a0+672]:8 +0x72c8.
  The `lbu` at 0x3a78 loads 1 byte from [a0+672]:8 +0x7310.
  The `sb` at 0x3a88 stores 1 byte to [a0+672]:8 +0x7310.
  The `sb` at 0x3a98 stores 1 byte to [a0+672]:8 +0x7312.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x238, including `lw` at 0x3aa4, `lw` at 0x3b10.
  2 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x3adc, `lbu` at 0x3b48.
  The `lbu` at 0x3b7c loads 1 byte from [a0+672]:8 +0x7311.
  The `sb` at 0x3b8c stores 1 byte to [a0+672]:8 +0x7311.
  The `sb` at 0x3b9c stores 1 byte to [a0+672]:8 +0x7313.
  The `jal` at 0x3a4c calls pcibr_rrb_flush with a0=[[a0+672]:8+29468], a1=[([a0+740] + [[a0+672]:8+552]:8)], a2=[[a0+744]:8], a3=([a0+740] + [[a0+672]:8+552]:8), a4=[[a0+672]:8+552]:8.
  The `jal` at 0x3a94 calls rad_pio_writeback_subcode_tx with a0=[a0+672]:8+12128, a1=a1 at entry (arg1), a2=-0x1, a3=0x6, a4=0x7, a5=-0x2, a7=0x1.
  The `jal` at 0x3b00 calls rad_stop_dma with a0=[a0+672]:8+8168, a1=a1 at entry (arg1), a2=?, a3=?, a4=0x1, a5=-0x2.
  The `jal` at 0x3b6c calls rad_stop_dma with a0=[a0+672]:8+8960, a1=a1 at entry (arg1), a2=?, a3=?, a4=0x1, a5=-0x2.
  The `jal` at 0x3b98 calls rad_pio_writeback_subcode_tx with a0=[a0+672]:8+17672, a1=a1 at entry (arg1), a2=-0x1, a3=0x6, a4=0x7, a5=-0x2.
  The `beq` branch at 0x39dc targets 0x3a64, is taken when at(=[a0+628]:1) == 0, and falls through when at(=[a0+628]:1) != 0.
  The `beq` branch at 0x39e8 targets 0x3a78, is taken when a0(=[a0+704]) == a2(=-0x1), and falls through when a0(=[a0+704]) != a2(=-0x1).
  The `beq` branch at 0x39f0 targets 0x3b7c, is taken when a0(=[a0+704]) == a5(=-0x2), and falls through when a0(=[a0+704]) != a5(=-0x2).
  The `beq` branch at 0x39f8 targets 0x3aa4, is taken when a0(=[a0+704]) == a3(=0x6), and falls through when a0(=[a0+704]) != a3(=0x6).
  The `beq` branch at 0x3a00 targets 0x3b10, is taken when a0(=[a0+704]) == a4(=0x7), and falls through when a0(=[a0+704]) != a4(=0x7).
  The `bne` branch at 0x3a84 targets 0x3a54, is taken when (a6(=[[a0+672]:8+29456]:1-1) & 0xff) != 0, and falls through when (a6(=[[a0+672]:8+29456]:1-1) & 0xff) == 0.
  The `beq` branch at 0x3a9c targets 0x3a58 and is always taken.
  The `beq` branch at 0x3ab4 targets 0x3ba8, is taken when t0(=[a0+568]) >= 0x20 (signed), and falls through when t0(=[a0+568]) < 0x20 (signed).
  The `beq` branch at 0x3ae4 targets 0x3af0, is taken when t1(?) == 0, and falls through when t1(?) != 0.
  The `bne` branch at 0x3af0 targets 0x3ac0, is taken when a3(?) != 0, and falls through when a3(?) == 0.
  The `bne` branch at 0x3af8 targets 0x3a18, is taken when a0(?) != a4(=0x1), and falls through when a0(?) == a4(=0x1).
  The `beq` branch at 0x3b08 targets 0x3a1c and is always taken.
  The `beq` branch at 0x3b20 targets 0x3bc0, is taken when t2(=[a0+568]) >= 0x20 (signed), and falls through when t2(=[a0+568]) < 0x20 (signed).
  The `beq` branch at 0x3b50 targets 0x3b5c, is taken when t3(?) == 0, and falls through when t3(?) != 0.
  The `bne` branch at 0x3b5c targets 0x3b2c, is taken when a3(?) != 0, and falls through when a3(?) == 0.
  The `bne` branch at 0x3b64 targets 0x3a18, is taken when a0(?) != a4(=0x1), and falls through when a0(?) == a4(=0x1).
  The `beq` branch at 0x3b74 targets 0x3a1c and is always taken.
  The `bne` branch at 0x3b88 targets 0x3a54, is taken when (t8(=[[a0+672]:8+29457]:1-1) & 0xff) != 0, and falls through when (t8(=[[a0+672]:8+29457]:1-1) & 0xff) == 0.
  The `beq` branch at 0x3ba0 targets 0x3a58 and is always taken.
  The `beq` branch at 0x3bb8 targets 0x3a18 and is always taken.
  The `beq` branch at 0x3bd0 targets 0x3a18 and is always taken.
  The return at 0x3a70 has v0 = ?.

- `rad_mclk_update_cg` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x3bd8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x3bd8-0x3ce0 (264 bytes).
  It occupies 264 bytes.
  The `ld` at 0x3bf0 loads 8 bytes from a0 (arg0 at entry) +0x1f0.
  The `ld` at 0x3c0c loads 8 bytes from a0 (arg0 at entry) +0x1c8.
  The `lw` at 0x3c10 loads 4 bytes from [a0+456]:8 +0x128.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x21c, including `lw` at 0x3c24, `lw` at 0x3c84.
  The `sw` at 0x3c38 stores 4 bytes to a0 (arg0 at entry) +0x21c.
  The `ld` at 0x3c40 loads 8 bytes from [a0+496]:8 +0x228.
  The `sw` at 0x3c58 stores 4 bytes to [[a0+496]:8+552]:8 +0xa0.
  The `ld` at 0x3c70 loads 8 bytes from a0 (arg0 at entry) +0x1a0.
  The `jal` at 0x3bec calls kdsp_mclk_update_cg with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `bne` branch at 0x3c04 targets 0x3c5c, is taken when s0(=a0) != at(=[a0+496]:8+26240), and falls through when s0(=a0) == at(=[a0+496]:8+26240).
  The `beq` branch at 0x3c14 targets 0x3c24, is taken when a1(=[[a0+456]:8+296]) == a4(=0x2000000b), and falls through when a1(=[[a0+456]:8+296]) != a4(=0x2000000b).
  The `bne` branch at 0x3c1c targets 0x3c6c, is taken when a1(=[[a0+456]:8+296]) != a3(=0x2000000c), and falls through when a1(=[[a0+456]:8+296]) == a3(=0x2000000c).
  The `beq` branch at 0x3c2c targets 0x3c5c, is taken when a2(=[a0+540]) == a1(=0x3), and falls through when a2(=[a0+540]) != a1(=0x3).
  The `beq` branch at 0x3c88 targets 0x3ca0, is taken when a4(=0x72d800000000) >= a5(=[a0+416]:8) (signed), and falls through when a4(=0x72d800000000) < a5(=[a0+416]:8) (signed).
  The `beq` branch at 0x3c90 targets 0x3c5c, is taken when a2(=[a0+540]) == a1(=0x3), and falls through when a2(=[a0+540]) != a1(=0x3).
  The `beq` branch at 0x3c98 targets 0x3c38 and is always taken.
  The `beq` branch at 0x3cb0 targets 0x3cc8, is taken when a7(=0x396c00000000) >= a5(=[a0+416]:8) (signed), and falls through when a7(=0x396c00000000) < a5(=[a0+416]:8) (signed).
  The `beq` branch at 0x3cb8 targets 0x3c5c, is taken when a2(=[a0+540]) == a1(=0x6), and falls through when a2(=[a0+540]) != a1(=0x6).
  The `beq` branch at 0x3cc0 targets 0x3c38 and is always taken.
  The `beq` branch at 0x3cd0 targets 0x3c5c, is taken when a2(=[a0+540]) == a1(=one of 0xc, 0x18), and falls through when a2(=[a0+540]) != a1(=one of 0xc, 0x18).
  The `beq` branch at 0x3cd8 targets 0x3c38 and is always taken.
  The return at 0x3c64 has v0 = ret(kdsp_mclk_update_cg).

- `rad_check_adat_rx` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x3ce0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x3ce0-0x3e64 (388 bytes).
  It occupies 388 bytes.
  3 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x7309, including `lbu` at 0x3ce0, `lbu` at 0x3d30, `lbu` at 0x3e60.
  The `lbu` at 0x3d10 loads 1 byte from a0 (arg0 at entry) +0x730a.
  2 such `sh` accesses store 2 bytes to a0 (arg0 at entry) +0x730c, including `sh` at 0x3d1c, `sh` at 0x3d58.
  2 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x730b, including `sb` at 0x3d20, `sb` at 0x3d64.
  The `lbu` at 0x3d24 loads 1 byte from a0 (arg0 at entry) +0x730b.
  The `sb` at 0x3d34 stores 1 byte to a0 (arg0 at entry) +0x730a.
  The `lhu` at 0x3d44 loads 2 bytes from a0 (arg0 at entry) +0x730c.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x2c0, including `lw` at 0x3d70, `lw` at 0x3d94, `lw` at 0x3dd8.
  3 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x800, including `sb` at 0x3d80, `sb` at 0x3e10, `sb` at 0x3e24.
  4 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x7309, including `sb` at 0x3d84, `sb` at 0x3dd0, `sb` at 0x3e1c.
  3 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x1ccc, including `sw` at 0x3d90, `sw` at 0x3e0c, `sw` at 0x3e28.
  5 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x228, including `ld` at 0x3da4, `ld` at 0x3db8, `ld` at 0x3df8.
  5 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x7240, including `lw` at 0x3da8, `lw` at 0x3db4, `lw` at 0x3df0.
  5 such `sw` accesses store 4 bytes to [a0+552]:8 +0x80, including `sw` at 0x3db0, `sw` at 0x3dc4, `sw` at 0x3e04.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x7240, including `sw` at 0x3dc0, `sw` at 0x3e00.
  The `lw` at 0x3dd4 loads 4 bytes from a0 (arg0 at entry) +0x72f0.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x1cc8, including `sw` at 0x3e08, `sw` at 0x3e34.
  The `jal` at 0x3d60 calls kdsp_update_mclk_users with a0=a0+1624, a1=?, a2=?, a3=?, a4=0x1, a5=0x1f4.
  The `beq` branch at 0x3cf8 targets 0x3d70, is taken when a4(=0x1) == a2(=[a0+29449]:1), and falls through when a4(=0x1) != a2(=[a0+29449]:1).
  The `beq` branch at 0x3d00 targets 0x3d94, is taken when a2(=[a0+29449]:1) == 0, and falls through when a2(=[a0+29449]:1) != 0.
  The `beq` branch at 0x3d08 targets 0x3dd4, is taken when a2(=[a0+29449]:1) == a3(=0x2), and falls through when a2(=[a0+29449]:1) != a3(=0x2).
  The `beq` branch at 0x3d14 targets 0x3d24, is taken when at(=[a0+29450]:1) == a2(?), and falls through when at(=[a0+29450]:1) != a2(?).
  The `beq` branch at 0x3d28 targets 0x3d44, is taken when v0(=[a0+29451]:1) == 0, and falls through when v0(=[a0+29451]:1) != 0.
  The `bne` branch at 0x3d54 targets 0x3d30, is taken when (a0(=[a0+29452]:2-1) & 0xffff) != 0, and falls through when (a0(=[a0+29452]:2-1) & 0xffff) == 0.
  The `beq` branch at 0x3d68 targets 0x3d30 and is always taken.
  The `beq` branch at 0x3d78 targets 0x3d10, is taken when (a1(=[a0+704]) & 0x40) == 0, and falls through when (a1(=[a0+704]) & 0x40) != 0.
  The `beq` branch at 0x3d8c targets 0x3d10 and is always taken.
  The `beq` branch at 0x3d9c targets 0x3e20, is taken when (a2(=[a0+704]) & 0x40) == 0, and falls through when (a2(=[a0+704]) & 0x40) != 0.
  The `beq` branch at 0x3dcc targets 0x3d10 and is always taken.
  The `beq` branch at 0x3de0 targets 0x3e38, is taken when (a1(=[a0+29424]) & 0x3ff) == 0, and falls through when (a1(=[a0+29424]) & 0x3ff) != 0.
  The `bne` branch at 0x3de8 targets 0x3d10, is taken when a0(?) != 0, and falls through when a0(?) == 0.
  The `beq` branch at 0x3e18 targets 0x3d10 and is always taken.
  The `beq` branch at 0x3e30 targets 0x3d10 and is always taken.
  The `beq` branch at 0x3e38 targets 0x3df0, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x3e5c targets 0x3d10 and is always taken.
  The return at 0x3d3c has v0 = one of [a0+29451]:1, ret(kdsp_update_mclk_users).

- `rad_update_dev` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x3e64 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x3e64-0x43a4 (1344 bytes).
  It occupies 1344 bytes.
  The `ld` at 0x3e6c loads 8 bytes from a0 (arg0 at entry) +0x2a0.
  The `lbu` at 0x3e78 loads 1 byte from a0 (arg0 at entry) +0x274.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x268, including `lw` at 0x3e90, `lw` at 0x3fd4.
  2 such `lbu` accesses load 1 byte from [a0+672]:8 +0x730f, including `lbu` at 0x3eac, `lbu` at 0x410c.
  7 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x2c0, including `lw` at 0x3ebc, `lw` at 0x3ed8, `lw` at 0x3edc.
  2 such `lbu` accesses load 1 byte from [a0+672]:8 +0x730e, including `lbu` at 0x3ec8, `lbu` at 0x4234.
  The `lw` at 0x3ef4 loads 4 bytes from a0 (arg0 at entry) +0x1e4.
  The `lw` at 0x3ef8 loads 4 bytes from a0 (arg0 at entry) +0x1d4.
  3 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x1b8, including `ld` at 0x3f00, `ld` at 0x4164, `ld` at 0x428c.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x308, including `ld` at 0x3f18, `ld` at 0x4108.
  The `ld` at 0x3f1c loads 8 bytes from a0 (arg0 at entry) +0x2f8.
  The `ld` at 0x3f20 loads 8 bytes from a0 (arg0 at entry) +0x300.
  The `lw` at 0x3f24 loads 4 bytes from [a0+760]:8 +0x0.
  The `lw` at 0x3f2c loads 4 bytes from [a0+768]:8 +0x0.
  The `lw` at 0x3f48 loads 4 bytes from a0 (arg0 at entry) +0x310.
  The `sd` at 0x3f6c stores 8 bytes to a0 (arg0 at entry) +0x308.
  The `lw` at 0x3f78 loads 4 bytes from [a0+672]:8 +0x2b8.
  The `ld` at 0x3f84 loads 8 bytes from a0 (arg0 at entry) +0x1b0.
  3 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x1b0, including `sd` at 0x3fac, `sd` at 0x4130, `sd` at 0x4258.
  4 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x2c4, including `lw` at 0x3fc8, `lw` at 0x4054, `lw` at 0x40f8.
  5 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x264, including `sw` at 0x3fd0, `sw` at 0x411c, `sw` at 0x419c.
  The `lw` at 0x3ff4 loads 4 bytes from [a0+440]:8 +0x0.
  The `sw` at 0x4000 stores 4 bytes to [a0+440]:8 +0x0.
  The `sw` at 0x400c stores 4 bytes to a0 (arg0 at entry) +0x2c4.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x220, including `lw` at 0x4010, `lw` at 0x4374, `lw` at 0x4398.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x23c, including `lw` at 0x4018, `lw` at 0x4168, `lw` at 0x4290.
  The `ld` at 0x401c loads 8 bytes from a0 (arg0 at entry) +0x1a8.
  3 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x1a8, including `sd` at 0x4028, `sd` at 0x4124, `sd` at 0x424c.
  The `lw` at 0x4088 loads 4 bytes from a0 (arg0 at entry) +0x238.
  4 such `lw` accesses load 4 bytes from [a0+440]:8 +0x4, including `lw` at 0x409c, `lw` at 0x4134, `lw` at 0x4170.
  2 such `sw` accesses store 4 bytes to [a0+440]:8 +0x4, including `sw` at 0x40a8, `sw` at 0x4140.
  The `lbu` at 0x40b4 loads 1 byte from [a0+672]:8 +0x7309.
  2 such `lw` accesses load 4 bytes from [a0+672]:8 +0x2564, including `lw` at 0x4118, `lw` at 0x4360.
  The `ld` at 0x4120 loads 8 bytes from [a0+672]:8 +0x24a8.
  The `ld` at 0x4128 loads 8 bytes from [a0+672]:8 +0x24b0.
  3 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x1c8, including `ld` at 0x4184, `ld` at 0x426c, `ld` at 0x4394.
  8 such `ld` accesses load 8 bytes from ?, including `ld` at 0x41e4, `ld` at 0x41f4, `ld` at 0x4218.
  7 such `lw` accesses load 4 bytes from ?, including `lw` at 0x41e8, `lw` at 0x41f8, `lw` at 0x41fc.
  4 such `sw` accesses store 4 bytes to ?, including `sw` at 0x41f0, `sw` at 0x4210, `sw` at 0x4310.
  4 such `sd` accesses store 8 bytes to ?, including `sd` at 0x4224, `sd` at 0x4344, `sd` at 0x4384.
  The `sb` at 0x4230 stores 1 byte to [a0+672]:8 +0x730f.
  2 such `lw` accesses load 4 bytes from [a0+672]:8 +0x224c, including `lw` at 0x4240, `lw` at 0x4370.
  The `ld` at 0x4248 loads 8 bytes from [a0+672]:8 +0x2190.
  The `ld` at 0x4250 loads 8 bytes from [a0+672]:8 +0x2198.
  The `sb` at 0x4350 stores 1 byte to [a0+672]:8 +0x730e.
  The `jal` at 0x3f74 calls rad_sync_device_ust with a0=a0 at entry (arg0), a1=[[a0+672]:8+696], a2=?, a3=0x3ffff.
  The `jal` at 0x40dc calls kdsp_update_default_subcode with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x40fc calls rad_check_adat_rx with a0=[a0+672]:8, a1=?, a2=[a0+704], a3=?, a5=0x4, a6=[a0+440]:8.
  The `jal` at 0x4190 calls rad_prepare_adat_in_subcode with a0=[a0+672]:8, a1=?, a2=?, a3=?, a4=[a0+572].
  The `jal` at 0x41bc calls kdsp_update_default_subcode with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x42b0 calls rad_prepare_aes_in_subcode with a0=[a0+672]:8, a1=?, a2=?, a3=?, a4=[a0+456]:8, a5=[a0+572].
  The `jal` at 0x42dc calls kdsp_update_default_subcode with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x4354 calls rad_update_dev with a0=[a0+672]:8+8960, a1=0x7, a2=[[a0+672]:8+29455]:1, a3=[a0+672]:8+8168, a4=0x6.
  The `jal` at 0x4364 calls rad_update_dev with a0=[a0+672]:8+8168, a1=0x7, a2=[a0+704], a3=[a0+672]:8+8168, a4=[[a0+672]:8+29454]:1.
  The `beq` branch at 0x3e88 targets 0x402c, is taken when at(=[a0+628]:1) == 0, and falls through when at(=[a0+628]:1) != 0.
  The `beq` branch at 0x3e98 targets 0x404c, is taken when (v0(=[a0+616]) & 0x400) == 0, and falls through when (v0(=[a0+616]) & 0x400) != 0.
  The `bne` branch at 0x3ea4 targets 0x3ec0, is taken when a0(=[a0+672]:8+8960) != s0(=a0), and falls through when a0(=[a0+672]:8+8960) == s0(=a0).
  The `bne` branch at 0x3eb0 targets 0x4030, is taken when v1(=[[a0+672]:8+29455]:1) != 0, and falls through when v1(=[[a0+672]:8+29455]:1) == 0.
  The `beq` branch at 0x3eb8 targets 0x3ef4 and is always taken.
  The `bne` branch at 0x3ec0 targets 0x3edc, is taken when a3(=[a0+672]:8+8168) != s0(=a0), and falls through when a3(=[a0+672]:8+8168) == s0(=a0).
  The `bne` branch at 0x3ecc targets 0x4030, is taken when a0(=[[a0+672]:8+29454]:1) != 0, and falls through when a0(=[[a0+672]:8+29454]:1) == 0.
  The `beq` branch at 0x3ed4 targets 0x3ef4 and is always taken.
  The `beq` branch at 0x3ee4 targets 0x410c, is taken when a2(=[a0+704]) == a1(=0x7), and falls through when a2(=[a0+704]) != a1(=0x7).
  The `beq` branch at 0x3eec targets 0x4234, is taken when a2(=[a0+704]) == a4(=0x6), and falls through when a2(=[a0+704]) != a4(=0x6).
  The `beq` branch at 0x3f04 targets 0x40fc, is taken when a2(=[a0+704]) == a5(=0x4), and falls through when a2(=[a0+704]) != a5(=0x4).
  The `beq` branch at 0x3f10 targets 0x40fc, is taken when a2(=[a0+704]) == a7(=0x7), and falls through when a2(=[a0+704]) != a7(=0x7).
  The `beq` branch at 0x3f68 targets 0x3f84, is taken when t1(=[a0+784]) == 0, and falls through when t1(=[a0+784]) != 0.
  The `beq` branch at 0x3f7c targets 0x3fb4 and is always taken.
  The `beq` branch at 0x3fb8 targets 0x4054, is taken when a0(=[a0+704]) == a2(=0x6), and falls through when a0(=[a0+704]) != a2(=0x6).
  The `beq` branch at 0x3fc0 targets 0x40b4, is taken when a0(=[a0+704]) == t9(=0x7), and falls through when a0(=[a0+704]) != t9(=0x7).
  The `beq` branch at 0x3fcc targets 0x402c, is taken when a0(=[a0+708]) == s2(?), and falls through when a0(=[a0+708]) != s2(?).
  The `beq` branch at 0x3fdc targets 0x4070, is taken when (a0(=[a0+616]) & 0x1) == 0, and falls through when (a0(=[a0+616]) & 0x1) != 0.
  The `bgez` branch at 0x4008 targets 0x4018, is taken when s3(?) >= 0 (signed), and falls through when s3(?) < 0 (signed).
  The `beq` branch at 0x404c targets 0x3ef4 and is always taken.
  The `bltz` branch at 0x405c targets 0x425c, is taken when a2(?) < 0 (signed), and falls through when a2(?) >= 0 (signed).
  The `beq` branch at 0x4068 targets 0x3fcc and is always taken.
  The `beq` branch at 0x4080 targets 0x4134, is taken when (a0(=[a0+616]) & 0x400) == 0, and falls through when (a0(=[a0+616]) & 0x400) != 0.
  The `beq` branch at 0x4090 targets 0x4134, is taken when a6(=[a0+568]) >= 0x20 (signed), and falls through when a6(=[a0+568]) < 0x20 (signed).
  The `beq` branch at 0x40ac targets 0x4008 and is always taken.
  The `beq` branch at 0x40bc targets 0x3fc8, is taken when ra(=[[a0+672]:8+29449]:1) == at(=0x1), and falls through when ra(=[[a0+672]:8+29449]:1) != at(=0x1).
  The `bne` branch at 0x40ec targets 0x40c8, is taken when s3(?) < 0x4 (signed), and falls through when s3(?) >= 0x4 (signed).
  The `beq` branch at 0x40f4 targets 0x3fcc and is always taken.
  The `beq` branch at 0x4104 targets 0x3f1c and is always taken.
  The `beq` branch at 0x4110 targets 0x4354, is taken when a2(=[[a0+672]:8+29455]:1) == 0, and falls through when a2(=[[a0+672]:8+29455]:1) != 0.
  The `beq` branch at 0x412c targets 0x402c and is always taken.
  The `beq` branch at 0x4150 targets 0x4264, is taken when a0(=[a0+704]) == t9(=0x6), and falls through when a0(=[a0+704]) != t9(=0x6).
  The `bne` branch at 0x415c targets 0x4008, is taken when a0(=[a0+704]) != t8(=0x7), and falls through when a0(=[a0+704]) == t8(=0x7).
  The `bltz` branch at 0x417c targets 0x4398, is taken when a2(?) < 0 (signed), and falls through when a2(?) >= 0 (signed).
  The `bne` branch at 0x4204 targets 0x4214, is taken when a2(?) < a3(?) (signed), and falls through when a2(?) >= a3(?) (signed).
  The `bne` branch at 0x4220 targets 0x41a4, is taken when s4(?) < 0x4 (signed), and falls through when s4(?) >= 0x4 (signed).
  The `beq` branch at 0x422c targets 0x4008 and is always taken.
  The `beq` branch at 0x4238 targets 0x4364, is taken when a4(=[[a0+672]:8+29454]:1) == 0, and falls through when a4(=[[a0+672]:8+29454]:1) != 0.
  The `beq` branch at 0x4254 targets 0x402c and is always taken.
  The `beq` branch at 0x425c targets 0x4064 and is always taken.
  The `beq` branch at 0x4284 targets 0x4380, is taken when (t1(?) & 0x1) == 0, and falls through when (t1(?) & 0x1) != 0.
  The `bltz` branch at 0x42a4 targets 0x4374, is taken when a2(?) < 0 (signed), and falls through when a2(?) >= 0 (signed).
  The `bne` branch at 0x4328 targets 0x4334, is taken when a3(?) < a4(?) (signed), and falls through when a3(?) >= a4(?) (signed).
  The `bne` branch at 0x4340 targets 0x42c4, is taken when s4(?) < 0x3 (signed), and falls through when s4(?) >= 0x3 (signed).
  The `beq` branch at 0x434c targets 0x4008 and is always taken.
  The `beq` branch at 0x435c targets 0x411c and is always taken.
  The `beq` branch at 0x436c targets 0x4244 and is always taken.
  The `beq` branch at 0x4378 targets 0x42a8 and is always taken.
  The `beq` branch at 0x4390 targets 0x428c and is always taken.
  The `beq` branch at 0x439c targets 0x4184 and is always taken.
  The return at 0x4044 has v0 = ?.

- `rad_update_subcode_tx_dev` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x43a4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x43a4-0x4528 (388 bytes).
  It occupies 388 bytes.
  The `lbu` at 0x43a4 loads 1 byte from a0 (arg0 at entry) +0x274.
  The `ld` at 0x43ac loads 8 bytes from a0 (arg0 at entry) +0x2a0.
  The `ld` at 0x43bc loads 8 bytes from a0 (arg0 at entry) +0x1b0.
  The `ld` at 0x43c4 loads 8 bytes from a0 (arg0 at entry) +0x300.
  The `lw` at 0x43d0 loads 4 bytes from [a0+768]:8 +0x0.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x1a8, including `ld` at 0x43e8, `ld` at 0x44a8.
  The `lw` at 0x4400 loads 4 bytes from a0 (arg0 at entry) +0x2c0.
  The `ld` at 0x4414 loads 8 bytes from a0 (arg0 at entry) +0x1b8.
  2 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x1a8, including `sd` at 0x4428, `sd` at 0x44b4.
  The `lwu` at 0x442c loads 4 bytes from [a0+672]:8 +0x2a4.
  3 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x1b0, including `sd` at 0x4448, `sd` at 0x44ac, `sd` at 0x44dc.
  The `lw` at 0x444c loads 4 bytes from [a0+672]:8 +0x723c.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x238, including `lw` at 0x4460, `lw` at 0x44e0.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x264, including `sw` at 0x446c, `sw` at 0x4514.
  The `lw` at 0x4478 loads 4 bytes from [a0+440]:8 +0x0.
  2 such `sw` accesses store 4 bytes to [a0+440]:8 +0x0, including `sw` at 0x4480, `sw` at 0x449c.
  The `lw` at 0x4484 loads 4 bytes from a0 (arg0 at entry) +0x220.
  The `sd` at 0x44a0 stores 8 bytes to a0 (arg0 at entry) +0x308.
  The `sw` at 0x44a4 stores 4 bytes to a0 (arg0 at entry) +0x2c4.
  The `lwu` at 0x44c0 loads 4 bytes from [a0+672]:8 +0x2ac.
  The `lw` at 0x44e4 loads 4 bytes from [a0+672]:8 +0x7238.
  The `beq` branch at 0x43b0 targets 0x44b8, is taken when at(=[a0+628]:1) == 0, and falls through when at(=[a0+628]:1) != 0.
  The `beq` branch at 0x4424 targets 0x44c0, is taken when a3(=[a0+704]) == t3(=-0x1), and falls through when a3(=[a0+704]) != t3(=-0x1).
  The `beq` branch at 0x4444 targets 0x44e0, is taken when a3(=[a0+704]) == t3(=-0x1), and falls through when a3(=[a0+704]) != t3(=-0x1).
  The `beq` branch at 0x445c targets 0x4518, is taken when a3(?) == t0(=0x2), and falls through when a3(?) != t0(=0x2).
  The `beq` branch at 0x4464 targets 0x4518, is taken when a3(?) == t2(=0x1), and falls through when a3(?) != t2(=0x1).
  The `beq` branch at 0x4470 targets 0x44b8, is taken when a2(=one of 0x0, 0x1, 0x6) == 0, and falls through when a2(=one of 0x0, 0x1, 0x6) != 0.
  The `bne` branch at 0x4494 targets 0x44a0, is taken when a6(?) < t2(=[a0+544]) (signed), and falls through when a6(?) >= t2(=[a0+544]) (signed).
  The `bne` branch at 0x44d8 targets 0x444c, is taken when a3(=[a0+704]) != t3(=-0x1), and falls through when a3(=[a0+704]) == t3(=-0x1).
  The `beq` branch at 0x4500 targets 0x4520, is taken when a3(?) == t2(=0x2), and falls through when a3(?) != t2(=0x2).
  The `beq` branch at 0x4508 targets 0x4520, is taken when a3(?) == a6(=0x1), and falls through when a3(?) != a6(=0x1).
  The `beq` branch at 0x4510 targets 0x4470 and is always taken.
  The `beq` branch at 0x4518 targets 0x446c and is always taken.
  The `beq` branch at 0x4520 targets 0x4510 and is always taken.
  The return at 0x44b8 has v0 = ?.

- `rad_pio_writeback_subcode_tx` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x4528 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x4528-0x48f0 (968 bytes).
  It occupies 968 bytes.
  The `lw` at 0x4528 loads 4 bytes from a0 (arg0 at entry) +0x230.
  The `lw` at 0x4530 loads 4 bytes from a0 (arg0 at entry) +0x2c0.
  The `ld` at 0x453c loads 8 bytes from a0 (arg0 at entry) +0x2a0.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x1b8, including `ld` at 0x4550, `ld` at 0x4654.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x22c, including `lw` at 0x4554, `lw` at 0x4658.
  2 such `lw` accesses load 4 bytes from [a0+440]:8 +0x4, including `lw` at 0x4558, `lw` at 0x465c.
  2 such `lw` accesses load 4 bytes from [a0+440]:8 +0x0, including `lw` at 0x4570, `lw` at 0x4674.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x1c8, including `ld` at 0x4574, `ld` at 0x4678.
  24 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x45d0, `lbu` at 0x45d4, `lbu` at 0x45e4.
  4 such `sb` accesses store 1 byte to ?, including `sb` at 0x45ec, `sb` at 0x45f4, `sb` at 0x4614.
  The `lbu` at 0x4628 loads 1 byte from [a0+672]:8 +0x7313.
  The `sb` at 0x4638 stores 1 byte to [a0+672]:8 +0x7313.
  2 such `sw` accesses store 4 bytes to ?, including `sw` at 0x471c, `sw` at 0x4774.
  The `lbu` at 0x4778 loads 1 byte from [a0+672]:8 +0x7312.
  The `sb` at 0x4788 stores 1 byte to [a0+672]:8 +0x7312.
  The `lbu` at 0x479c loads 1 byte from [a0+672]:8 +0x7310.
  The `lw` at 0x47a0 loads 4 bytes from [a0+672]:8 +0x7238.
  2 such `lbu` accesses load 1 byte from [a0+672]:8 +0x7314, including `lbu` at 0x47d4, `lbu` at 0x48e0.
  3 such `sb` accesses store 1 byte to [a0+672]:8 +0x7314, including `sb` at 0x47d8, `sb` at 0x48c4, `sb` at 0x48e4.
  3 such `sb` accesses store 1 byte to [a0+672]:8 +0x7315, including `sb` at 0x47e0, `sb` at 0x48cc, `sb` at 0x48ec.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x220, including `lw` at 0x47e4, `lw` at 0x484c.
  The `lbu` at 0x4800 loads 1 byte from [a0+672]:8 +0x7311.
  The `lw` at 0x4804 loads 4 bytes from [a0+672]:8 +0x723c.
  2 such `lbu` accesses load 1 byte from [a0+672]:8 +0x7316, including `lbu` at 0x483c, `lbu` at 0x4894.
  3 such `sb` accesses store 1 byte to [a0+672]:8 +0x7316, including `sb` at 0x4840, `sb` at 0x4878, `sb` at 0x4898.
  3 such `sb` accesses store 1 byte to [a0+672]:8 +0x7317, including `sb` at 0x4848, `sb` at 0x4880, `sb` at 0x48a0.
  The `jal` at 0x4794 calls rad_prepare_aes_out_subcode with a0=[a0+672]:8, a1=[a0+672]:8+29000, a2=?, a3=?.
  The `jal` at 0x47cc calls rad_write_aes_out_subcode with a0=[a0+672]:8, a1=0x1180, a2=[a0+672]:8+29000, a3=?.
  The `jal` at 0x47f8 calls rad_prepare_adat_out_subcode with a0=[a0+672]:8, a1=[a0+672]:8+29144, a2=?, a3=?.
  The `jal` at 0x4834 calls rad_write_adat_out_subcode with a0=[a0+672]:8, a1=0x1080, a2=[a0+672]:8+29144, a3=?, a4=0x2, a5=0x1.
  The `jal` at 0x4860 calls rad_write_adat_out_subcode with a0=[a0+672]:8, a1=0x1000, a2=[a0+672]:8+29144, a3=?, a4=0x2, a5=0x1.
  The `jal` at 0x4870 calls rad_write_adat_out_subcode with a0=[a0+672]:8, a1=0x1080, a2=[a0+672]:8+29144, a3=?.
  The `jal` at 0x488c calls rad_write_adat_out_subcode with a0=[a0+672]:8, a1=0x1000, a2=[a0+672]:8+29144, a3=?, a4=0x2, a5=0x1.
  The `jal` at 0x48ac calls rad_write_aes_out_subcode with a0=[a0+672]:8, a1=0x1100, a2=[a0+672]:8+29000, a3=?.
  The `jal` at 0x48bc calls rad_write_aes_out_subcode with a0=[a0+672]:8, a1=0x1180, a2=[a0+672]:8+29000, a3=?.
  The `jal` at 0x48d8 calls rad_write_aes_out_subcode with a0=[a0+672]:8, a1=0x1100, a2=[a0+672]:8+29000, a3=?.
  The `beq` branch at 0x4540 targets 0x464c, is taken when at(=[a0+704]) == v0(=-0x1), and falls through when at(=[a0+704]) != v0(=-0x1).
  The `beq` branch at 0x4548 targets 0x4628, is taken when a1(=[a0+560]) == 0, and falls through when a1(=[a0+560]) != 0.
  The `bltz` branch at 0x4560 targets 0x47e4, is taken when a2(?) < 0 (signed), and falls through when a2(?) >= 0 (signed).
  The `blez` branch at 0x4568 targets 0x4628, is taken when a1(?) <= 0 (signed), and falls through when a1(?) > 0 (signed).
  The `beq` branch at 0x45b0 targets 0x45c0, is taken when a0 == a7(?), and falls through when a0 != a7(?).
  The `bne` branch at 0x45b8 targets 0x4588, is taken when a4(?) != 0, and falls through when a4(?) == 0.
  The `bne` branch at 0x4620 targets 0x45c8, is taken when a0(?) < 0x6 (signed), and falls through when a0(?) >= 0x6 (signed).
  The `blez` branch at 0x4634 targets 0x47f0, is taken when t1(?) <= 0 (signed), and falls through when t1(?) > 0 (signed).
  The `beq` branch at 0x464c targets 0x4778, is taken when a1(=[a0+560]) == 0, and falls through when a1(=[a0+560]) != 0.
  The `bltz` branch at 0x4664 targets 0x484c, is taken when a2(?) < 0 (signed), and falls through when a2(?) >= 0 (signed).
  The `blez` branch at 0x466c targets 0x4778, is taken when a1(?) <= 0 (signed), and falls through when a1(?) > 0 (signed).
  The `beq` branch at 0x46b0 targets 0x46c0, is taken when a0 == a7(?), and falls through when a0 != a7(?).
  The `bne` branch at 0x46b8 targets 0x4688, is taken when a4(?) != 0, and falls through when a4(?) == 0.
  The `bne` branch at 0x4770 targets 0x46c8, is taken when a0(?) < 0x6 (signed), and falls through when a0(?) >= 0x6 (signed).
  The `bgtz` branch at 0x4784 targets 0x463c, is taken when t8(?) > 0 (signed), and falls through when t8(?) <= 0 (signed).
  The `beq` branch at 0x47a8 targets 0x48a4, is taken when a1(=[[a0+672]:8+29456]:1) == 0, and falls through when a1(=[[a0+672]:8+29456]:1) != 0.
  The `beq` branch at 0x47b4 targets 0x48d0, is taken when a0(?) == a1(=0x2), and falls through when a0(?) != a1(=0x2).
  The `bne` branch at 0x47bc targets 0x4640, is taken when a0(?) != a2(=0x1), and falls through when a0(?) == a2(=0x1).
  The `beq` branch at 0x47dc targets 0x463c and is always taken.
  The `beq` branch at 0x47e8 targets 0x4568 and is always taken.
  The `beq` branch at 0x4814 targets 0x4858, is taken when a1(=[[a0+672]:8+29457]:1) == 0, and falls through when a1(=[[a0+672]:8+29457]:1) != 0.
  The `beq` branch at 0x481c targets 0x4884, is taken when a0(?) == a4(=0x2), and falls through when a0(?) != a4(=0x2).
  The `bne` branch at 0x4824 targets 0x4640, is taken when a0(?) != a5(=0x1), and falls through when a0(?) == a5(=0x1).
  The `beq` branch at 0x4844 targets 0x463c and is always taken.
  The `beq` branch at 0x4850 targets 0x466c and is always taken.
  The `beq` branch at 0x487c targets 0x463c and is always taken.
  The `beq` branch at 0x489c targets 0x463c and is always taken.
  The `beq` branch at 0x48c8 targets 0x463c and is always taken.
  The `beq` branch at 0x48e8 targets 0x463c and is always taken.
  The return at 0x4644 has v0 = one of ?, ret(rad_prepare_aes_out_subcode), ret(rad_prepare_adat_out_subcode).

- `rad_pre_connect` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x48f0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x48f0-0x48f8 (8 bytes).
  It occupies 8 bytes.
  The return at 0x48f0 has v0 = 0x0.

- `rad_set_clockgen` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x48f8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x48f8-0x4bb0 (696 bytes).
  It occupies 696 bytes.
  The `ld` at 0x4904 loads 8 bytes from a0 (arg0 at entry) +0x1f0.
  The `lw` at 0x4914 loads 4 bytes from a0 (arg0 at entry) +0x1f8.
  The `sd` at 0x4948 stores 8 bytes to a0 (arg0 at entry) +0x200.
  The `lw` at 0x494c loads 4 bytes from a0 (arg0 at entry) +0x20c.
  9 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x208, including `lw` at 0x4968, `lw` at 0x49d4, `lw` at 0x4a24.
  The `lw` at 0x497c loads 4 bytes from ([a0+496]:8 + ([a0+520] << 0x2)) +0x72cc.
  3 such `lh` accesses load 2 bytes from [a0+496]:8 +0x21a, including `lh` at 0x4994, `lh` at 0x4a08, `lh` at 0x4af0.
  2 such `lw` accesses load 4 bytes from [a0+496]:8 +0x7240, including `lw` at 0x49a8, `lw` at 0x4ad4.
  5 such `ld` accesses load 8 bytes from [a0+496]:8 +0x228, including `ld` at 0x49b4, `ld` at 0x49e4, `ld` at 0x4a4c.
  2 such `sw` accesses store 4 bytes to [a0+496]:8 +0x7240, including `sw` at 0x49c0, `sw` at 0x4ae8.
  2 such `sw` accesses store 4 bytes to [[a0+496]:8+552]:8 +0x80, including `sw` at 0x49cc, `sw` at 0x4aec.
  The `ld` at 0x49d8 loads 8 bytes from a0 (arg0 at entry) +0x200.
  The `lwu` at 0x49e8 loads 4 bytes from (sym(.rodata) + ([a0+520] << 0x2)) +0x0.
  The `lw` at 0x49ec loads 4 bytes from [a0+512]:8 +0x1b4.
  The `sw` at 0x49f8 stores 4 bytes to ([(sym(.rodata) + ([a0+520] << 0x2))] + [[a0+496]:8+552]:8) +0x0.
  The `sw` at 0x49fc stores 4 bytes to a0 (arg0 at entry) +0x218.
  The `sw` at 0x4a00 stores 4 bytes to a0 (arg0 at entry) +0x214.
  The `sw` at 0x4a04 stores 4 bytes to a0 (arg0 at entry) +0x210.
  The `sw` at 0x4a40 stores 4 bytes to ([a0+496]:8 + ([a0+520] << 0x2)) +0x7288.
  The `lw` at 0x4a54 loads 4 bytes from ([a0+496]:8 + ([a0+520] << 0x2)) +0x7288.
  The `sw` at 0x4a58 stores 4 bytes to [[a0+496]:8+552]:8 +0xa4.
  3 such `lw` accesses load 4 bytes from ([a0+496]:8 + ([a0+520] << 0x2)) +0x7278, including `lw` at 0x4a68, `lw` at 0x4aa0, `lw` at 0x4ac4.
  2 such `sw` accesses store 4 bytes to ([a0+496]:8 + ([a0+520] << 0x2)) +0x7278, including `sw` at 0x4a70, `sw` at 0x4ab0.
  The `sw` at 0x4ac8 stores 4 bytes to [[a0+496]:8+552]:8 +0xa0.
  2 such `lbu` accesses load 1 byte from [a0+496]:8 +0x7302, including `lbu` at 0x4b08, `lbu` at 0x4b3c.
  2 such `lw` accesses load 4 bytes from [a0+496]:8 +0x7274, including `lw` at 0x4b48, `lw` at 0x4b94.
  2 such `sw` accesses store 4 bytes to [a0+496]:8 +0x7274, including `sw` at 0x4b5c, `sw` at 0x4ba4.
  The `jal` at 0x4b58 calls rad_vl_write_MUX_SEL with a0=[a0+496]:8, a1=?, a2=-0x2001, a3=0x7, a4=0x1, a5=[a0+520]+8.
  The `jal` at 0x4b60 calls us_delay with a0=0xfa, a1=?, a2=?, a3=?.
  The `jal` at 0x4b80 calls rad_vl_set_clockgen with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0xd, a3=0x7, a4=0x1.
  The `jal` at 0x4ba0 calls rad_vl_write_MUX_SEL with a0=[a0+496]:8, a1=([[a0+496]:8+29300] | 0x2000), a2=[[a0+496]:8+552]:8, a3=0x7, a4=0x1, a5=([a0+496]:8 + ([a0+520] << 0x2)), a6=[a0+496]:8+26240, a7=[[a0+496]:8+29442]:1.
  The `bltz` branch at 0x4934 targets 0x4b10, is taken when at(=[a0+504]) < 0 (signed), and falls through when at(=[a0+504]) >= 0 (signed).
  The `beq` branch at 0x493c targets 0x494c, is taken when a1 == 0, and falls through when a1 != 0.
  The `beq` branch at 0x4950 targets 0x4b10, is taken when v0(=[a0+524]) == 0, and falls through when v0(=[a0+524]) != 0.
  The `bne` branch at 0x498c targets 0x4b10, is taken when (v1(=[([a0+496]:8 + ([a0+520] << 0x2))+29388]) & a2(?)) != 0, and falls through when (v1(=[([a0+496]:8 + ([a0+520] << 0x2))+29388]) & a2(?)) == 0.
  The `beq` branch at 0x499c targets 0x4b34, is taken when a2(=[[a0+496]:8+538]:2) == a3(=0x7), and falls through when a2(=[[a0+496]:8+538]:2) != a3(=0x7).
  The `beq` branch at 0x49c8 targets 0x49fc, is taken when a0(=one of 0x0, 0x1) == 0, and falls through when a0(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x4a0c targets 0x4b7c, is taken when a0(=[[a0+496]:8+538]:2) == a3(=0x7), and falls through when a0(=[[a0+496]:8+538]:2) != a3(=0x7).
  The `beq` branch at 0x4a14 targets 0x4b80, is taken when a0(=[[a0+496]:8+538]:2) == a2(=0xd), and falls through when a0(=[[a0+496]:8+538]:2) != a2(=0xd).
  The `bne` branch at 0x4af4 targets 0x4b10, is taken when t1(=[[a0+496]:8+538]:2) != a3(=0x7), and falls through when t1(=[[a0+496]:8+538]:2) == a3(=0x7).
  The `bne` branch at 0x4b00 targets 0x4b14, is taken when s0(=a0) != a6(=[a0+496]:8+26240), and falls through when s0(=a0) == a6(=[a0+496]:8+26240).
  The `beq` branch at 0x4b0c targets 0x4b94, is taken when a7(=[[a0+496]:8+29442]:1) == 0, and falls through when a7(=[[a0+496]:8+29442]:1) != 0.
  The `bne` branch at 0x4b34 targets 0x49a8, is taken when s0(=a0) != a2(=[a0+496]:8+26240), and falls through when s0(=a0) == a2(=[a0+496]:8+26240).
  The `bne` branch at 0x4b40 targets 0x49a4, is taken when t0(=[[a0+496]:8+29442]:1) != 0, and falls through when t0(=[[a0+496]:8+29442]:1) == 0.
  The `beq` branch at 0x4b74 targets 0x49a4 and is always taken.
  The `beq` branch at 0x4b8c targets 0x4a1c and is always taken.
  The `beq` branch at 0x4ba8 targets 0x4b14 and is always taken.
  The return at 0x4b2c has v0 = one of ?, ret(rad_vl_write_MUX_SEL).

- `rad_get_hw_mscust` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x4bb0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x4bb0-0x4be4 (52 bytes).
  It occupies 52 bytes.
  The `ld` at 0x4bb0 loads 8 bytes from a0 (arg0 at entry) +0x308.
  The `lw` at 0x4bb4 loads 4 bytes from a0 (arg0 at entry) +0x258.
  The `ld` at 0x4bb8 loads 8 bytes from a0 (arg0 at entry) +0x2a0.
  The `sd` at 0x4bc0 stores 8 bytes to a1 (arg1 at entry) +0x0.
  The `ld` at 0x4bc4 loads 8 bytes from [a0+672]:8 +0x72a8.
  The `ld` at 0x4bc8 loads 8 bytes from a0 (arg0 at entry) +0x1b0.
  The `sd` at 0x4be0 stores 8 bytes to a2 (arg2 at entry) +0x0.
  The return at 0x4bdc has v0 = ([a0+432]:8 + [[a0+672]:8+29352]:8).

- `rad_start_clockgen` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x4be4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x4be4-0x4c18 (52 bytes).
  It occupies 52 bytes.
  The `lw` at 0x4be4 loads 4 bytes from a0 (arg0 at entry) +0x20c.
  The `ld` at 0x4bf0 loads 8 bytes from a0 (arg0 at entry) +0x1f0.
  The `lw` at 0x4bf4 loads 4 bytes from a0 (arg0 at entry) +0x208.
  The `lw` at 0x4bfc loads 4 bytes from [a0+496]:8 +0x7240.
  The `sw` at 0x4c0c stores 4 bytes to [a0+496]:8 +0x7240.
  The `beq` branch at 0x4bec targets 0x4c10, is taken when at(=[a0+524]) == 0, and falls through when at(=[a0+524]) != 0.
  The return at 0x4c10 has v0 = ?.

- `rad_shutdown` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x4c18 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x4c18-0x4c34 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x4c20 calls kdsp_idbg_rad_delfuncs with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x4c2c has v0 = ret(kdsp_idbg_rad_delfuncs).

- `rad_halt_intr_ops` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x4c34 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x4c34-0x4c5c (40 bytes).
  It occupies 40 bytes.
  The `sw` at 0x4c4c stores 4 bytes to a0 (arg0 at entry) +0x72c8.
  The `jal` at 0x4c40 calls rad_stop_status_dma with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x4c54 has v0 = ret(rad_stop_status_dma).

- `rad_one_shot_status` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x4c5c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x4c5c-0x4d40 (228 bytes).
  It occupies 228 bytes.
  3 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x7c, including `lw` at 0x4c70, `lw` at 0x4ccc, `lw` at 0x4d10.
  The `sw` at 0x4c90 stores 4 bytes to a1 (arg1 at entry) +0x7c.
  4 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x228, including `ld` at 0x4c94, `ld` at 0x4ca0, `ld` at 0x4ca8.
  The `sw` at 0x4c9c stores 4 bytes to [a0+552]:8 +0x504.
  The `sw` at 0x4ca4 stores 4 bytes to [a0+552]:8 +0x500.
  The `sw` at 0x4cb0 stores 4 bytes to [a0+552]:8 +0x528.
  The `sw` at 0x4cc8 stores 4 bytes to [a0+552]:8 +0x5c.
  The `jal` at 0x4c8c calls Mem_to_PCI_DMA with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0x1000, a3=a3 at entry (arg3).
  The `jal` at 0x4cc4 calls us_delay with a0=0x5, a1=[a0+552]:8, a2=[a0+552]:8, a3=-0x4, a4=[a0+552]:8.
  The `jal` at 0x4d08 calls us_delay with a0=0x5, a1=?, a2=?, a3=?.
  The `jal` at 0x4d30 calls debug with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `beq` branch at 0x4cd8 targets 0x4cf8, is taken when (v0(=0xffffffff80000000) & a5(=[a1+124])) == 0, and falls through when (v0(=0xffffffff80000000) & a5(=[a1+124])) != 0.
  The `beq` branch at 0x4cf8 targets 0x4d08 and is always taken.
  The `blez` branch at 0x4d00 targets 0x4d24, is taken when s0(?) <= 0 (signed), and falls through when s0(?) > 0 (signed).
  The `beq` branch at 0x4d1c targets 0x4d00, is taken when (v0(=0xffffffff80000000) & a6(=[a1+124])) == 0, and falls through when (v0(=0xffffffff80000000) & a6(=[a1+124])) != 0.
  The `bne` branch at 0x4d24 targets 0x4ce4, is taken when s0(?) != 0, and falls through when s0(?) == 0.
  The `beq` branch at 0x4d38 targets 0x4ce4 and is always taken.
  The return at 0x4cf0 has v0 = one of 0x0, 0x1.

- `rad_attach` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x4d40 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x4d40-0x4df4 (180 bytes).
  It occupies 180 bytes.
  The `jal` at 0x4d60 calls pciio_piotrans_addr with a0=a0 at entry (arg0), a1=0x0, a2=0x7, a3=0x0, a4=0x20, a5=0x0.
  The `jal` at 0x4d80 calls pciio_piotrans_addr with a0=a0 at entry (arg0), a1=0x0, a2=0x8, a3=0x0, a4=0x2000, a5=0x0.
  The `jal` at 0x4d94 calls pciio_config_get with a0=a0 at entry (arg0), a1=0x8, a2=0x4, a3=?.
  The `jal` at 0x4db8 calls pciio_priority_set with a0=a0 at entry (arg0), a1=0x2, a2=?, a3=?.
  The `jal` at 0x4dc8 calls pciio_priority_set with a0=a0 at entry (arg0), a1=0x1, a2=?, a3=?.
  The `jal` at 0x4dd8 calls rad_create_subsys with a0=ret(pciio_piotrans_addr), a1=ret(pciio_piotrans_addr), a2=a0 at entry (arg0), a3=?.
  The `bne` branch at 0x4dac targets 0x4dc8, is taken when at(?) != v0(=0xc), and falls through when at(?) == v0(=0xc).
  The `beq` branch at 0x4dc0 targets 0x4dd0 and is always taken.
  The return at 0x4dec has v0 = 0x0.

- `rad_detach` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x4df4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x4df4-0x4dfc (8 bytes).
  It occupies 8 bytes.
  The return at 0x4df4 has v0 = 0x0.

- `rad_error` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x4dfc (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x4dfc-0x4e04 (8 bytes).
  It occupies 8 bytes.
  The return at 0x4dfc has v0 = 0x0.

- `rad_error_handler` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x4e04 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x4e04-0x4e9c (152 bytes).
  It occupies 152 bytes.
  4 such `ld` accesses load 8 bytes from a3 (arg3 at entry) +0x28, including `ld` at 0x4e58, `ld` at 0x4e5c, `ld` at 0x4e88.
  The `lw` at 0x4e68 loads 4 bytes from a0 (arg0 at entry) +0x731c.
  The `jal` at 0x4e6c calls cmn_err with a0=0x4, a1=sym(.rodata), a2=[a0+29468], a3=sym(.rodata), a4=a1 at entry (arg1), a5=a2 at entry (arg2), a6=[a3+40]:8, a7=0x6.
  The `beq` branch at 0x4e30 targets 0x4e5c, is taken when a1 == at(=0x5), and falls through when a1 != at(=0x5).
  The `beq` branch at 0x4e38 targets 0x4e84, is taken when a1 == a7(=0x6), and falls through when a1 != a7(=0x6).
  The `beq` branch at 0x4e40 targets 0x4e8c, is taken when a1 == t3(=0x9), and falls through when a1 != t3(=0x9).
  The `beq` branch at 0x4e48 targets 0x4e94, is taken when a1 == t8(=0xa), and falls through when a1 != t8(=0xa).
  The `beq` branch at 0x4e54 targets 0x4e60 and is always taken.
  The `beq` branch at 0x4e84 targets 0x4e60 and is always taken.
  The `beq` branch at 0x4e8c targets 0x4e5c and is always taken.
  The `beq` branch at 0x4e94 targets 0x4e60 and is always taken.
  The return at 0x4e7c has v0 = 0x9.

- `rad_init` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x4e9c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x4e9c-0x4ed4 (56 bytes).
  It occupies 56 bytes.
  The `jal` at 0x4eb4 calls pciio_driver_register with a0=0x10a9, a1=0x5, a2=sym(.rodata), a3=0x0.
  The `jal` at 0x4ec0 calls kdsp_idbg_rad_addfuncs with a0=?, a1=?, a2=?, a3=sym(rad_halt).
  The return at 0x4ecc has v0 = ret(kdsp_idbg_rad_addfuncs).

- `rad_halt` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x4ed4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x4ed4-0x4fb0 (220 bytes).
  It occupies 220 bytes.
  4 such `ld` accesses load 8 bytes from ?, including `ld` at 0x4efc, `ld` at 0x4f34, `ld` at 0x4f5c.
  3 such `lh` accesses load 2 bytes from ?, including `lh` at 0x4f20, `lh` at 0x4f44, `lh` at 0x4fac.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0x4f30, `lw` at 0x4f90.
  6 such `sw` accesses store 4 bytes to ?, including `sw` at 0x4f3c, `sw` at 0x4f40, `sw` at 0x4f64.
  The `jal` at 0x4ef4 calls rad_stop_status_dma with a0=?, a1=?, a2=?, a3=?, a5=0xc.
  The `jal` at 0x4f10 calls strncmp with a0=?, a1=sym(.rodata), a2=0x3, a3=?.
  The `jal` at 0x4f7c calls us_delay with a0=0xc8, a1=?, a2=?, a3=?.
  The `jal` at 0x4fa0 calls rad_vl_write_MUX_SEL with a0=?, a1=?, a2=?, a3=?, a4=0x7, a5=0xc.
  The `beq` branch at 0x4ee4 targets 0x4f78, is taken when at(=[sym(kdsp_sstab)]:8) == 0, and falls through when at(=[sym(kdsp_sstab)]:8) != 0.
  The `beq` branch at 0x4eec targets 0x4f08 and is always taken.
  The `beq` branch at 0x4f00 targets 0x4f78, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `bne` branch at 0x4f18 targets 0x4efc, is taken when v0(=ret(strncmp)) != 0, and falls through when v0(=ret(strncmp)) == 0.
  The `beq` branch at 0x4f28 targets 0x4f4c, is taken when a0(?) == a2(=0xd), and falls through when a0(?) != a2(=0xd).
  The `beq` branch at 0x4f4c targets 0x4f90, is taken when a0(?) == a4(=0x7), and falls through when a0(?) != a4(=0x7).
  The `bne` branch at 0x4f54 targets 0x4ef4, is taken when a0(?) != a5(=0xc), and falls through when a0(?) == a5(=0xc).
  The `beq` branch at 0x4f70 targets 0x4ef4 and is always taken.
  The `beq` branch at 0x4fa8 targets 0x4f50 and is always taken.
  The return at 0x4f88 has v0 = ret(us_delay).

- `Mem_to_PCI_DMA` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x4fb0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x4fb0-0x4ff4 (68 bytes).
  It occupies 68 bytes.
  The `lw` at 0x4fd8 loads 4 bytes from a0 (arg0 at entry) +0x731c.
  The `jal` at 0x4fc4 calls kvtophys with a0=a1 at entry (arg1), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x4fdc calls pciio_dmatrans_addr with a0=[a0+29468], a1=0x0, a2=ret(kvtophys), a3=a2 at entry (arg2), a4=0x50.
  The return at 0x4fec has v0 = ret(pciio_dmatrans_addr).

- `rad_initial_val` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x4ff4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x4ff4-0x5268 (628 bytes).
  It occupies 628 bytes.
  The `lw` at 0x4ff4 loads 4 bytes from a1 (arg1 at entry) +0x0.
  The `ld` at 0x501c loads 8 bytes from a0 (arg0 at entry) +0x118.
  The `ld` at 0x5028 loads 8 bytes from (sym(.rodata) + ([a1]+0xffffffffeffffffe << 0x3)) +0x0.
  Calls (unknown callee) via register with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a4=[a0+280]:8, a5=(sym(.rodata) + ([a1]+0xffffffffeffffffe << 0x3)), a6=([a1]+0xffffffffeffffffe << 0x3) (`jr` at 0x502c).
  The `beq` branch at 0x5020 targets 0x5038, is taken when a6(=[a1]+0xffffffffeffffffe) >= 0x34 (unsigned), and falls through when a6(=[a1]+0xffffffffeffffffe) < 0x34 (unsigned).
  The return at 0x5038 has v0 = 0x0.
  The instructions from 0x5034 to 0x5034 are not reached by any path from the entry, and their branches are not listed.
  The instructions from 0x5040 to 0x5264 are not reached by any path from the entry, and their branches are not listed.
  The indirect jump at 0x502c uses a jump table whose successors are unresolved.

- `rad_set_device_params` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x5268 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x5268-0x5604 (924 bytes).
  It occupies 924 bytes.
  The `lw` at 0x526c loads 4 bytes from a1 (arg1 at entry) +0x0.
  The `ld` at 0x52a0 loads 8 bytes from a0 (arg0 at entry) +0x2a0.
  The `ld` at 0x52ac loads 8 bytes from (sym(.rodata) + ([a1]+0xffffffffeffffffe << 0x3)) +0x0.
  Calls (unknown callee) via register with a0=[(sym(.rodata) + ([a1]+0xffffffffeffffffe << 0x3))]:8, a1=?, a2=a2 at entry (arg2), a3=a3 at entry (arg3), a5=[a1] (`jr` at 0x52b0).
  The `beq` branch at 0x52a4 targets 0x52b8, is taken when v1(=[a1]+0xffffffffeffffffe) >= 0x34 (unsigned), and falls through when v1(=[a1]+0xffffffffeffffffe) < 0x34 (unsigned).
  The return at 0x52c8 has v0 = 0x0.
  The instructions from 0x52d0 to 0x5600 are not reached by any path from the entry, and their branches are not listed.
  The indirect jump at 0x52b0 uses a jump table whose successors are unresolved.

- `rad_commit_device_params` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x5604 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x5604-0x560c (8 bytes).
  It occupies 8 bytes.
  The return at 0x5604 has v0 = ?.

- `rad_calculate_rate_frac` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x560c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x560c-0x5780 (372 bytes).
  It occupies 372 bytes.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x1a0, including `ld` at 0x560c, `ld` at 0x5738.
  The `ld` at 0x5618 loads 8 bytes from a0 (arg0 at entry) +0x200.
  The `ld` at 0x561c loads 8 bytes from a0 (arg0 at entry) +0x1f0.
  2 such `ld` accesses load 8 bytes from [a0+512]:8 +0x198, including `ld` at 0x5638, `ld` at 0x5650.
  2 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x1a0, including `sd` at 0x5648, `sd` at 0x5694.
  The `ld` at 0x56a4 loads 8 bytes from [a0+496]:8 +0x630.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x220, including `lw` at 0x56bc, `lw` at 0x5758.
  3 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x1b0, including `sw` at 0x56c0, `sw` at 0x56f8, `sw` at 0x575c.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x1b8, including `sw` at 0x56d0, `sw` at 0x5768.
  2 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x200, including `sd` at 0x56dc, `sd` at 0x5774.
  The `lw` at 0x56e0 loads 4 bytes from a0 (arg0 at entry) +0x1b8.
  The `lw` at 0x56e4 loads 4 bytes from a0 (arg0 at entry) +0x1b0.
  The `ld` at 0x572c loads 8 bytes from [a0+496]:8 +0x470.
  The `jal` at 0x5660 calls kdsp_reduce_frac with a0=?, a1=[[a0+512]:8+408]:8, a2=a0+432, a3=a0+440, a4=0xffff.
  The `jal` at 0x56a8 calls kdsp_reduce_frac with a0=?, a1=[[a0+496]:8+1584]:8, a2=sp-48, a3=sp-44, a4=0xffff.
  The `jal` at 0x5714 calls kdsp_reduce_frac with a0=?, a1=[a0+440], a2=a0+432, a3=a0+440, a4=0xffff, a6=[a0+416]:8.
  The `jal` at 0x5734 calls kdsp_reduce_frac with a0=[a0+416]:8, a1=[[a0+496]:8+1136]:8, a2=sp-40, a3=sp-36, a4=0xffff.
  The `beq` branch at 0x5628 targets 0x567c, is taken when a3(=[a0+512]:8) == 0, and falls through when a3(=[a0+512]:8) != 0.
  The `beq` branch at 0x5630 targets 0x56e0, is taken when a6(=[a0+416]:8) == 0, and falls through when a6(=[a0+416]:8) != 0.
  The `beq` branch at 0x5640 targets 0x5654, is taken when a0(=[[a0+512]:8+408]:8) >= a6(=[a0+416]:8) (signed), and falls through when a0(=[[a0+512]:8+408]:8) < a6(=[a0+416]:8) (signed).
  The `beq` branch at 0x5688 targets 0x5698, is taken when a0(=0xbb8000000000) >= a6(=[a0+416]:8) (signed), and falls through when a0(=0xbb8000000000) < a6(=[a0+416]:8) (signed).
  The `bne` branch at 0x56b4 targets 0x5724, is taken when s0(=a0) != a1(=[a0+496]:8+26240), and falls through when s0(=a0) == a1(=[a0+496]:8+26240).
  The `beq` branch at 0x56cc targets 0x56d8, is taken when a3(=[a0+544]) == 0, and falls through when a3(=[a0+544]) != 0.
  The `beq` branch at 0x56d8 targets 0x5668 and is always taken.
  The `beq` branch at 0x56ec targets 0x56fc, is taken when a1(=[a0+440]) >= a0(=[a0+432]) (signed), and falls through when a1(=[a0+440]) < a0(=[a0+432]) (signed).
  The `bne` branch at 0x5700 targets 0x570c, is taken when a4(=0xffff) < a0(?) (signed), and falls through when a4(=0xffff) >= a0(?) (signed).
  The `beq` branch at 0x5708 targets 0x5668, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0x571c targets 0x566c and is always taken.
  The `beq` branch at 0x573c targets 0x56bc, is taken when v0(=ret(kdsp_reduce_frac)) == 0, and falls through when v0(=ret(kdsp_reduce_frac)) != 0.
  The `beq` branch at 0x5750 targets 0x56bc, is taken when a1(?) >= a0(?) (signed), and falls through when a1(?) < a0(?) (signed).
  The `beq` branch at 0x5764 targets 0x5778, is taken when t0(=[a0+544]) == 0, and falls through when t0(=[a0+544]) != 0.
  The `beq` branch at 0x5770 targets 0x5668 and is always taken.
  The `beq` branch at 0x5778 targets 0x5770 and is always taken.
  The return at 0x5674 has v0 = one of ?, ret(kdsp_reduce_frac).

- `rad_cg_update_dev` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x5780 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x5780-0x586c (236 bytes).
  It occupies 236 bytes.
  The `ld` at 0x5788 loads 8 bytes from a0 (arg0 at entry) +0x1f0.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x2e8, including `ld` at 0x578c, `ld` at 0x57c4.
  The `lw` at 0x5790 loads 4 bytes from [a0+496]:8 +0x1b8.
  The `ld` at 0x5794 loads 8 bytes from a0 (arg0 at entry) +0x2a0.
  2 such `lw` accesses load 4 bytes from [a0+744]:8 +0x0, including `lw` at 0x57a0, `lw` at 0x57d8.
  The `lw` at 0x57ac loads 4 bytes from [a0+496]:8 +0x208.
  The `sw` at 0x57c0 stores 4 bytes to [a0+744]:8 +0x0.
  The `ld` at 0x57c8 loads 8 bytes from [a0+672]:8 +0x228.
  The `lwu` at 0x57cc loads 4 bytes from a0 (arg0 at entry) +0x2e4.
  The `sw` at 0x57e0 stores 4 bytes to ([a0+740] + [[a0+672]:8+552]:8) +0x0.
  The `ld` at 0x57f4 loads 8 bytes from [a0+496]:8 +0x1a0.
  The `lw` at 0x5800 loads 4 bytes from [a0+672]:8 +0x230.
  The `lbu` at 0x5804 loads 1 byte from [a0+672]:8 +0x7314.
  The `sb` at 0x5810 stores 1 byte to [a0+672]:8 +0x7314.
  The `sb` at 0x5818 stores 1 byte to [a0+672]:8 +0x7312.
  The `sb` at 0x5824 stores 1 byte to [a0+672]:8 +0x7310.
  The `lw` at 0x5830 loads 4 bytes from [a0+496]:8 +0x1b0.
  The `ld` at 0x583c loads 8 bytes from [a0+496]:8 +0x200.
  The `lw` at 0x5840 loads 4 bytes from [[a0+496]:8+512]:8 +0x1b4.
  The `jal` at 0x57f8 calls kdsp_set_aes_rate_bits with a0=[a0+672]:8+20944, a1=[[a0+496]:8+416]:8, a2=?, a3=[a0+496]:8, a4=0x1fffffff, a5=[[a0+744]:8], a6=[a0+744]:8, a7=0x1fff0000.
  The `jal` at 0x5820 calls rad_pio_writeback_subcode_tx with a0=[a0+672]:8+12128, a1=?, a2=?, a3=?.
  The `beq` branch at 0x57a8 targets 0x5830, is taken when at(=[[a0+496]:8+440]) == t1(=0x1), and falls through when at(=[[a0+496]:8+440]) != t1(=0x1).
  The `beq` branch at 0x57dc targets 0x57f4, is taken when a0 == v0(=[a0+672]:8+5792), and falls through when a0 != v0(=[a0+672]:8+5792).
  The `bne` branch at 0x580c targets 0x57e4, is taken when t9(=[[a0+672]:8+560]) != 0, and falls through when t9(=[[a0+672]:8+560]) == 0.
  The `beq` branch at 0x5828 targets 0x57e8 and is always taken.
  The `bne` branch at 0x5834 targets 0x57b4, is taken when at(=[[a0+496]:8+432]) != t1(=0x1), and falls through when at(=[[a0+496]:8+432]) == t1(=0x1).
  The `beq` branch at 0x5854 targets 0x5864, is taken when t3(?) == t8(=0x2), and falls through when t3(?) != t8(=0x2).
  The `beq` branch at 0x585c targets 0x57b0 and is always taken.
  The `beq` branch at 0x5864 targets 0x57b0 and is always taken.
  The return at 0x57ec has v0 = one of ?, ret(rad_pio_writeback_subcode_tx).

- `rad_get_cg_id` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x586c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x586c-0x59e4 (376 bytes).
  It occupies 376 bytes.
  The `ld` at 0x586c loads 8 bytes from a0 (arg0 at entry) +0x1f0.
  The `lh` at 0x587c loads 2 bytes from [a0+496]:8 +0x21a.
  The `lw` at 0x589c loads 4 bytes from a0 (arg0 at entry) +0x208.
  The `ll` at 0x58c0 loads 4 bytes from ([a0+496]:8 + ([a0+520] << 0x2)) +0x72cc.
  The `sc` at 0x58c8 stores 4 bytes to ([a0+496]:8 + ([a0+520] << 0x2)) +0x72cc.
  The `ld` at 0x58d4 loads 8 bytes from a0 (arg0 at entry) +0x200.
  4 such `lw` accesses load 4 bytes from ?, including `lw` at 0x58f0, `lw` at 0x59b0, `lw` at 0x59bc.
  The `ll` at 0x5920 loads 4 bytes from ?.
  The `sc` at 0x5928 stores 4 bytes to ?.
  The `sw` at 0x5934 stores 4 bytes to a0 (arg0 at entry) +0x208.
  The `lw` at 0x5948 loads 4 bytes from a0 (arg0 at entry) +0x1b8.
  The `lw` at 0x5954 loads 4 bytes from a0 (arg0 at entry) +0x1b0.
  The `ld` at 0x599c loads 8 bytes from ?.
  The `beq` branch at 0x5890 targets 0x5938, is taken when a6(=[[a0+496]:8+538]:2) == t1(=0xd), and falls through when a6(=[[a0+496]:8+538]:2) != t1(=0xd).
  The `beql` branch at 0x58cc targets 0x58c0, is taken when (t3(=[([a0+496]:8 + ([a0+520] << 0x2))+29388]) & t9(?)) == 0, and falls through when (t3(=[([a0+496]:8 + ([a0+520] << 0x2))+29388]) & t9(?)) != 0; its branch-likely delay slot `nop` at 0x58d0 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x58d8 targets 0x5940, is taken when a4(=[a0+512]:8) == t2(=[a0+496]:8+2968), and falls through when a4(=[a0+512]:8) != t2(=[a0+496]:8+2968).
  The `beq` branch at 0x58e0 targets 0x5940, is taken when a4(=[a0+512]:8) == t0(=[a0+496]:8+2520), and falls through when a4(=[a0+512]:8) != t0(=[a0+496]:8+2520).
  The `beq` branch at 0x58f4 targets 0x5914, is taken when t9(?) == 0, and falls through when t9(?) != 0.
  The `bne` branch at 0x5908 targets 0x58f0, is taken when a2(?) < 0x4 (signed), and falls through when a2(?) >= 0x4 (signed).
  The `beql` branch at 0x592c targets 0x5920, is taken when a1(?) == 0, and falls through when a1(?) != 0; its branch-likely delay slot `nop` at 0x5930 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x5940 targets 0x58e8, is taken when a0 == a7(=[a0+496]:8+26240), and falls through when a0 != a7(=[a0+496]:8+26240).
  The `bne` branch at 0x594c targets 0x58e8, is taken when a1(=[a0+440]) != t1(=0x1), and falls through when a1(=[a0+440]) == t1(=0x1).
  The `bne` branch at 0x5958 targets 0x58e8, is taken when a2(=[a0+432]) != t1(=0x1), and falls through when a2(=[a0+432]) == t1(=0x1).
  The `beq` branch at 0x5960 targets 0x5978 and is always taken.
  The `beq` branch at 0x5970 targets 0x59d4, is taken when a2(?) >= 0x6 (signed), and falls through when a2(?) < 0x6 (signed).
  The `beq` branch at 0x5994 targets 0x5968, is taken when a0 == a7(?), and falls through when a0 != a7(?).
  The `bne` branch at 0x59a0 targets 0x5968, is taken when a7(?) != a4(=[a0+512]:8), and falls through when a7(?) == a4(=[a0+512]:8).
  The `beq` branch at 0x59a8 targets 0x5968, is taken when a2(?) == t1(=0x1), and falls through when a2(?) != t1(=0x1).
  The `bne` branch at 0x59b4 targets 0x5968, is taken when t0(?) != t1(=0x1), and falls through when t0(?) == t1(=0x1).
  The `bnel` branch at 0x59c0 targets 0x596c, is taken when t2(?) != t1(=0x1), and falls through when t2(?) == t1(=0x1); its branch-likely delay slot `addiu a2,a2,1` at 0x59c4 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x59d4 targets 0x58e8, is taken when a2(?) == t8(=0x6), and falls through when a2(?) != t8(=0x6).
  The `beq` branch at 0x59dc targets 0x5914 and is always taken.
  The return at 0x5938 has v0 = ?.

- `rad_commit_clockgen_params` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x59e4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x59e4-0x5af4 (272 bytes).
  It occupies 272 bytes.
  The `lw` at 0x59e4 loads 4 bytes from a0 (arg0 at entry) +0x224.
  The `sd` at 0x5a10 stores 8 bytes to a0 (arg0 at entry) +0x200.
  3 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x200, including `ld` at 0x5a24, `ld` at 0x5a74, `ld` at 0x5ac0.
  The `ld` at 0x5a30 loads 8 bytes from a0 (arg0 at entry) +0x1c8.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x1b0, including `lw` at 0x5a48, `lw` at 0x5a5c.
  The `ld` at 0x5a4c loads 8 bytes from a0 (arg0 at entry) +0x198.
  The `lw` at 0x5a68 loads 4 bytes from a0 (arg0 at entry) +0x1b8.
  The `lw` at 0x5a78 loads 4 bytes from [a0+512]:8 +0x1b8.
  The `jal` at 0x5a14 calls rad_calculate_rate_frac with a0=a0 at entry (arg0), a1=[a0+548], a2=0x20000016, a3=a3 at entry (arg3).
  The `jal` at 0x5a1c calls rad_get_cg_id with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x5a3c calls kdsp_select_mclk with a0=a0 at entry (arg0), a1=[a0+512]:8, a2=?, a3=[a0+456]:8.
  The `jalr` at 0x5a54 calls (unknown callee) with a0=a0 at entry (arg0), a1=0x0, a2=?, a3=?, a4=[a0+408]:8.
  The `jal` at 0x5ab8 calls kdsp_reduce_frac with a0=?, a1=[a0+432], a2=sp-32, a3=sp-28, a4=0xffff, a7=[[a0+512]:8+440].
  The `jal` at 0x5ad4 calls rad_set_clockgen with a0=a0 at entry (arg0), a1=[a0+512]:8, a2=?, a3=?, a5=0x0.
  The `jal` at 0x5adc calls kdsp_update_cg_users with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `beq` branch at 0x5a00 targets 0x5a10, is taken when a1(=[a0+548]) == at(=0x2000000a), and falls through when a1(=[a0+548]) != at(=0x2000000a).
  The `bne` branch at 0x5a08 targets 0x5a14, is taken when a1(=[a0+548]) != a2(=0x20000016), and falls through when a1(=[a0+548]) == a2(=0x20000016).
  The `beq` branch at 0x5a28 targets 0x5a4c, is taken when a1(=[a0+512]:8) == 0, and falls through when a1(=[a0+512]:8) != 0.
  The `beq` branch at 0x5a34 targets 0x5a4c, is taken when a3(=[a0+456]:8) == a1(=[a0+512]:8), and falls through when a3(=[a0+456]:8) != a1(=[a0+512]:8).
  The `beq` branch at 0x5a44 targets 0x5a60 and is always taken.
  The `beq` branch at 0x5a60 targets 0x5ae8, is taken when a1(=[a0+432]) == 0, and falls through when a1(=[a0+432]) != 0.
  The `beq` branch at 0x5a6c targets 0x5ae8, is taken when a6(=[a0+440]) == 0, and falls through when a6(=[a0+440]) != 0.
  The return at 0x5aec has v0 = one of ?, ret(kdsp_update_cg_users).

- `rad_update_aes_mclk` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x5af4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x5af4-0x5b14 (32 bytes).
  It occupies 32 bytes.
  The `ld` at 0x5af4 loads 8 bytes from a0 (arg0 at entry) +0x118.
  The `jal` at 0x5b00 calls rad_process_aesrx_subcode with a0=[a0+280]:8, a1=0x1, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x5b0c has v0 = ret(rad_process_aesrx_subcode).

- `rad_process_aesrx_subcode` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x5b14 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x5b14-0x5bd4 (192 bytes).
  It occupies 192 bytes.
  The `lw` at 0x5b14 loads 4 bytes from a0 (arg0 at entry) +0x2c4.
  The `ld` at 0x5b34 loads 8 bytes from a0 (arg0 at entry) +0x72f8.
  The `ld` at 0x5b4c loads 8 bytes from table(sym(.data)+32768) +0x0.
  2 such `lhu` accesses load 2 bytes from a0 (arg0 at entry) +0x7300, including `lhu` at 0x5b58, `lhu` at 0x5bb4.
  2 such `sh` accesses store 2 bytes to a0 (arg0 at entry) +0x7300, including `sh` at 0x5b68, `sh` at 0x5b94.
  2 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x72f8, including `sd` at 0x5b6c, `sd` at 0x5ba0.
  The `lbu` at 0x5b78 loads 1 byte from a0 (arg0 at entry) +0x9c0.
  2 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x9c0, including `sb` at 0x5b9c, `sb` at 0x5bbc.
  The `sd` at 0x5bc8 stores 8 bytes to a0 (arg0 at entry) +0x9b0.
  The `jal` at 0x5bc4 calls kdsp_update_mclk_users with a0=a0+2072, a1=?, a2=?, a3=?, a5=sym(.data)+32768.
  The `bltz` branch at 0x5b38 targets 0x5b88, is taken when a6(=([a0+708] << 0xc)) < 0 (signed), and falls through when a6(=([a0+708] << 0xc)) >= 0 (signed).
  The `bne` branch at 0x5b50 targets 0x5b94, is taken when v0(=[a0+29432]:8) != a3(=entry(sym(.data)+32768)), and falls through when v0(=[a0+29432]:8) == a3(=entry(sym(.data)+32768)).
  The `beq` branch at 0x5b60 targets 0x5b78, is taken when v1(=[a0+29440]:2) == 0, and falls through when v1(=[a0+29440]:2) != 0.
  The `beq` branch at 0x5b70 targets 0x5bb8, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x5b88 targets 0x5bac, is taken when v0(=[a0+29432]:8) == 0, and falls through when v0(=[a0+29432]:8) != 0.
  The `beq` branch at 0x5ba4 targets 0x5b7c and is always taken.
  The `beq` branch at 0x5bb0 targets 0x5b5c and is always taken.
  The `beq` branch at 0x5bcc targets 0x5b78 and is always taken.
  The return at 0x5b80 has v0 = one of [a0+2496]:1, 0x1.

- `rad_prepare_aes_in_subcode` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x5bd4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x5bd4-0x5cf8 (292 bytes).
  It occupies 292 bytes.
  4 such `ld` accesses load 8 bytes from ?, including `ld` at 0x5bfc, `ld` at 0x5c00, `ld` at 0x5c14.
  The `lw` at 0x5c08 loads 4 bytes from ?.
  16 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x5c34, `lbu` at 0x5c38, `lbu` at 0x5c3c.
  4 such `sw` accesses store 4 bytes to ?, including `sw` at 0x5c84, `sw` at 0x5c88, `sw` at 0x5cd8.
  The `bne` branch at 0x5ce0 targets 0x5c2c, is taken when a4(?) < 0x6 (signed), and falls through when a4(?) >= 0x6 (signed).
  The `bne` branch at 0x5ce8 targets 0x5be8, is taken when t3(?) != 0, and falls through when t3(?) == 0.
  The return at 0x5cf0 has v0 = ?.

- `rad_prepare_aes_out_subcode` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x5cf8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x5cf8-0x5e08 (272 bytes).
  It occupies 272 bytes.
  3 such `ld` accesses load 8 bytes from ?, including `ld` at 0x5d20, `ld` at 0x5d24, `ld` at 0x5d40.
  16 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x5d4c, `lbu` at 0x5d50, `lbu` at 0x5d54.
  2 such `sw` accesses store 4 bytes to ?, including `sw` at 0x5d98, `sw` at 0x5df0.
  The `bne` branch at 0x5d38 targets 0x5df4, is taken when at(?) != 0, and falls through when at(?) == 0.
  The `bne` branch at 0x5dec targets 0x5d44, is taken when a4(?) < 0x6 (signed), and falls through when a4(?) >= 0x6 (signed).
  The `bne` branch at 0x5df8 targets 0x5d10, is taken when t1(?) != 0, and falls through when t1(?) == 0.
  The return at 0x5e00 has v0 = ?.

- `rad_prepare_adat_in_subcode` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x5e08 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x5e08-0x5ee0 (216 bytes).
  It occupies 216 bytes.
  4 such `ld` accesses load 8 bytes from ?, including `ld` at 0x5e2c, `ld` at 0x5e30, `ld` at 0x5e40.
  The `lw` at 0x5e34 loads 4 bytes from ?.
  9 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x5e5c, `lbu` at 0x5e60, `lbu` at 0x5e70.
  5 such `sb` accesses store 1 byte to ?, including `sb` at 0x5e78, `sb` at 0x5e80, `sb` at 0x5ea0.
  The `bne` branch at 0x5eac targets 0x5e54, is taken when a3(?) < 0x6 (signed), and falls through when a3(?) >= 0x6 (signed).
  The `bne` branch at 0x5ed0 targets 0x5e24, is taken when t0(?) < 0x4 (signed), and falls through when t0(?) >= 0x4 (signed).
  The return at 0x5ed8 has v0 = ?.

- `rad_prepare_adat_out_subcode` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x5ee0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x5ee0-0x5fb4 (212 bytes).
  It occupies 212 bytes.
  3 such `ld` accesses load 8 bytes from ?, including `ld` at 0x5f0c, `ld` at 0x5f10, `ld` at 0x5f20.
  8 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x5f24, `lbu` at 0x5f28, `lbu` at 0x5f2c.
  The `sw` at 0x5f84 stores 4 bytes to ?.
  The `bne` branch at 0x5f18 targets 0x5f88, is taken when at(?) != 0, and falls through when at(?) == 0.
  The `bne` branch at 0x5f80 targets 0x5f6c, is taken when a3(?) < 0x6 (signed), and falls through when a3(?) >= 0x6 (signed).
  The `bne` branch at 0x5fa4 targets 0x5f0c, is taken when t0(?) != 0, and falls through when t0(?) == 0.
  The return at 0x5fac has v0 = ?.

- `rad_write_aes_out_subcode` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x5fb4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x5fb4-0x6120 (364 bytes).
  It occupies 364 bytes.
  7 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x228, including `ld` at 0x5fbc, `ld` at 0x5fe8, `ld` at 0x6040.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0x5fd0, `ld` at 0x5ffc.
  2 such `sd` accesses store 8 bytes to ?, including `sd` at 0x5fdc, `sd` at 0x600c.
  2 such `ld` accesses load 8 bytes from a2 (arg2 at entry) +0x80, including `ld` at 0x6010, `ld` at 0x6044.
  The `lw` at 0x6020 loads 4 bytes from a0 (arg0 at entry) +0x5294.
  4 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x5294, including `sw` at 0x603c, `sw` at 0x60d0, `sw` at 0x6104.
  The `sd` at 0x604c stores 8 bytes to ([a0+552]:8 + one of 0x1200, 0x1210) +0x0.
  The `ld` at 0x6054 loads 8 bytes from a2 (arg2 at entry) +0x88.
  The `sd` at 0x605c stores 8 bytes to ([a0+552]:8 + one of 0x1208, 0x1218) +0x0.
  The `sd` at 0x6064 stores 8 bytes to [a0+552]:8 +0x1060.
  The `ld` at 0x6068 loads 8 bytes from a2 (arg2 at entry) +0x28.
  The `lw` at 0x607c loads 4 bytes from a0 (arg0 at entry) +0x7258.
  4 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x7258, including `sw` at 0x6088, `sw` at 0x60a4, `sw` at 0x60dc.
  The `ld` at 0x608c loads 8 bytes from a2 (arg2 at entry) +0x70.
  The `sw` at 0x60ac stores 4 bytes to [a0+552]:8 +0x54.
  The `beq` branch at 0x5fe0 targets 0x6010, is taken when a5(?) >= 0x10 (signed), and falls through when a5(?) < 0x10 (signed).
  The `bne` branch at 0x6008 targets 0x5fbc, is taken when a5(?) < 0x10 (signed), and falls through when a5(?) >= 0x10 (signed).
  The `beq` branch at 0x6024 targets 0x60b8, is taken when a3(=[a2+128]:8) == 0, and falls through when a3(=[a2+128]:8) != 0.
  The `beq` branch at 0x602c targets 0x60f4, is taken when a1 == a7(=0x1180), and falls through when a1 != a7(=0x1180).
  The `beq` branch at 0x6078 targets 0x60e8, is taken when a6(=0xff000000) == t9(?), and falls through when a6(=0xff000000) != t9(?).
  The `beq` branch at 0x6094 targets 0x60d4, is taken when a6(=0xff000000) == a3(?), and falls through when a6(=0xff000000) != a3(?).
  The `beq` branch at 0x60a0 targets 0x60b0, is taken when a1(?) == a4(=[a0+29272]), and falls through when a1(?) != a4(=[a0+29272]).
  The `beq` branch at 0x60b8 targets 0x6108, is taken when a1 == a7(=0x1180), and falls through when a1 != a7(=0x1180).
  The `bltz` branch at 0x60c0 targets 0x6068, is taken when a6(=([a0+21140] << 0x2f)) < 0 (signed), and falls through when a6(=([a0+21140] << 0x2f)) >= 0 (signed).
  The `beq` branch at 0x60cc targets 0x6040 and is always taken.
  The `beq` branch at 0x60d8 targets 0x60b0, is taken when a1(?) == a4(=[a0+29272]), and falls through when a1(?) != a4(=[a0+29272]).
  The `beq` branch at 0x60e0 targets 0x60ac and is always taken.
  The `beq` branch at 0x60ec targets 0x608c and is always taken.
  The `beq` branch at 0x6100 targets 0x6040 and is always taken.
  The `bne` branch at 0x610c targets 0x6068, is taken when (a4(=[a0+21140]) & 0x8000) != 0, and falls through when (a4(=[a0+21140]) & 0x8000) == 0.
  The `beq` branch at 0x6118 targets 0x6040 and is always taken.
  The return at 0x60b0 has v0 = ?.

- `rad_write_adat_out_subcode` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x6120 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x6120-0x619c (124 bytes).
  It occupies 124 bytes.
  3 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x228, including `ld` at 0x612c, `ld` at 0x6158, `ld` at 0x6184.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0x6140, `ld` at 0x616c.
  2 such `sd` accesses store 8 bytes to ?, including `sd` at 0x614c, `sd` at 0x617c.
  The `sd` at 0x6188 stores 8 bytes to [a0+552]:8 +0x1060.
  The `sd` at 0x6198 stores 8 bytes to [a0+552]:8 +0x10e0.
  The `beq` branch at 0x6150 targets 0x6180, is taken when a4(?) >= 0xf (signed), and falls through when a4(?) < 0xf (signed).
  The `bne` branch at 0x6178 targets 0x612c, is taken when a4(?) < 0xf (signed), and falls through when a4(?) >= 0xf (signed).
  The `beq` branch at 0x6180 targets 0x6194, is taken when a1 == a6(=0x1000), and falls through when a1 != a6(=0x1000).
  The return at 0x618c has v0 = ?.
  The return at 0x6194 has v0 = ?.

- `rad_update_adat_mclk` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x619c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x619c-0x61f0 (84 bytes).
  It occupies 84 bytes.
  The `ld` at 0x61a4 loads 8 bytes from a0 (arg0 at entry) +0x118.
  The `lw` at 0x61a8 loads 4 bytes from [a0+280]:8 +0x230.
  The `jal` at 0x61b4 calls rad_check_adat_rx with a0=[a0+280]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x61d0 calls rad_start_dma with a0=[a0+280]:8+6584, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x61e0 calls rad_stop_dma with a0=[a0+280]:8+6584, a1=?, a2=?, a3=?.
  The `beq` branch at 0x61ac targets 0x61cc, is taken when at(=[[a0+280]:8+560]) == 0, and falls through when at(=[[a0+280]:8+560]) != 0.
  The `beq` branch at 0x61d8 targets 0x61b4, is taken when v0(=ret(rad_start_dma)) == 0, and falls through when v0(=ret(rad_start_dma)) != 0.
  The `beq` branch at 0x61e8 targets 0x61b4 and is always taken.
  The return at 0x61c4 has v0 = ret(rad_check_adat_rx).

- `rad_get_mclk_params` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x61f0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x61f0-0x6220 (48 bytes).
  It occupies 48 bytes.
  The `lw` at 0x61f0 loads 4 bytes from a1 (arg1 at entry) +0x0.
  The `lw` at 0x620c loads 4 bytes from a0 (arg0 at entry) +0x1bc.
  The `sw` at 0x6214 stores 4 bytes to a1 (arg1 at entry) +0x8.
  The `beq` branch at 0x61fc targets 0x620c, is taken when at(=[a1]) == v0(=0x1000002a), and falls through when at(=[a1]) != v0(=0x1000002a).
  The return at 0x6204 has v0 = 0x0.
  The return at 0x6218 has v0 = 0x1.

- `rad_set_mclk_params` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x6220 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x6220-0x6318 (248 bytes).
  It occupies 248 bytes.
  The `ld` at 0x6220 loads 8 bytes from a0 (arg0 at entry) +0x118.
  The `lw` at 0x6228 loads 4 bytes from a1 (arg1 at entry) +0x0.
  The `lh` at 0x624c loads 2 bytes from [a0+280]:8 +0x21a.
  2 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x8, including `lw` at 0x6264, `lw` at 0x6280.
  2 such `sw` accesses store 4 bytes to [a0+280]:8 +0xd54, including `sw` at 0x626c, `sw` at 0x6288.
  2 such `sw` accesses store 4 bytes to [a0+280]:8 +0xb94, including `sw` at 0x6274, `sw` at 0x628c.
  2 such `lw` accesses load 4 bytes from [a0+280]:8 +0xd54, including `lw` at 0x62c0, `lw` at 0x62ec.
  2 such `lw` accesses load 4 bytes from [a0+280]:8 +0x7274, including `lw` at 0x62c4, `lw` at 0x62f0.
  2 such `sw` accesses store 4 bytes to [a0+280]:8 +0x7274, including `sw` at 0x62e0, `sw` at 0x630c.
  The `jal` at 0x62dc calls rad_vl_write_MUX_SEL with a0=[a0+280]:8, a1=?, a2=?, a3=-0x101, a4=[[a0+280]:8+538]:2, a5=0xc, a6=[a0+280]:8+2520, a7=0x7.
  The `jal` at 0x6308 calls rad_vl_write_MUX_SEL with a0=[a0+280]:8, a1=?, a2=?, a3=-0x1001, a4=[[a0+280]:8+538]:2, a5=0xc, a6=[a0+280]:8+2520, a7=0x7.
  The `bne` branch at 0x6244 targets 0x62b0, is taken when at(=[a1]) != v1(=0x1000002a), and falls through when at(=[a1]) == v1(=0x1000002a).
  The `beq` branch at 0x6254 targets 0x62b8, is taken when a4(=[[a0+280]:8+538]:2) == a5(=0xc), and falls through when a4(=[[a0+280]:8+538]:2) != a5(=0xc).
  The `bne` branch at 0x625c targets 0x6278, is taken when a0 != a6(=[a0+280]:8+2520), and falls through when a0 == a6(=[a0+280]:8+2520).
  The `beq` branch at 0x6270 targets 0x6290 and is always taken.
  The `bne` branch at 0x6278 targets 0x6290, is taken when a0 != t0(=[a0+280]:8+2968), and falls through when a0 == t0(=[a0+280]:8+2968).
  The `beq` branch at 0x6290 targets 0x62c0, is taken when a4(=[[a0+280]:8+538]:2) == t1(=0xd), and falls through when a4(=[[a0+280]:8+538]:2) != t1(=0xd).
  The `beq` branch at 0x6298 targets 0x62ec, is taken when a4(=[[a0+280]:8+538]:2) == a7(=0x7), and falls through when a4(=[[a0+280]:8+538]:2) != a7(=0x7).
  The `beq` branch at 0x62b0 targets 0x62a4 and is always taken.
  The `beq` branch at 0x62b8 targets 0x62a4 and is always taken.
  The `beq` branch at 0x62e4 targets 0x62a4 and is always taken.
  The `beq` branch at 0x6310 targets 0x62a4 and is always taken.
  The return at 0x62a8 has v0 = one of 0x0, 0x1.

- `rad_set_clockgen_params` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x6318 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x6318-0x6528 (528 bytes).
  It occupies 528 bytes.
  The `ld` at 0x6320 loads 8 bytes from a0 (arg0 at entry) +0x1f0.
  The `lw` at 0x634c loads 4 bytes from a1 (arg1 at entry) +0x0.
  4 such `sh` accesses store 2 bytes to a1 (arg1 at entry) +0x14, including `sh` at 0x6390, `sh` at 0x64bc, `sh` at 0x651c.
  3 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x224, including `sw` at 0x6394, `sw` at 0x64e4, `sw` at 0x64f4.
  3 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x8, including `lw` at 0x63b4, `lw` at 0x6484, `lw` at 0x64a4.
  The `ld` at 0x63d4 loads 8 bytes from a0 (arg0 at entry) +0x58.
  The `ld` at 0x63e8 loads 8 bytes from ?.
  3 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x200, including `sd` at 0x6420, `sd` at 0x64f0, `sd` at 0x6504.
  2 such `ld` accesses load 8 bytes from a1 (arg1 at entry) +0x8, including `ld` at 0x643c, `ld` at 0x650c.
  3 such `ld` accesses load 8 bytes from ret(kdsp_find_param_info) +0x28, including `ld` at 0x6450, `ld` at 0x6470, `ld` at 0x64d4.
  2 such `ld` accesses load 8 bytes from [ret(kdsp_find_param_info)+40]:8 +0x0, including `ld` at 0x645c, `ld` at 0x6474.
  The `ld` at 0x6468 loads 8 bytes from a0 (arg0 at entry) +0x1a0.
  3 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x1a8, including `sd` at 0x646c, `sd` at 0x64d0, `sd` at 0x6508.
  5 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x1a0, including `sd` at 0x647c, `sd` at 0x6480, `sd` at 0x64a0.
  The `sw` at 0x6494 stores 4 bytes to a0 (arg0 at entry) +0x1b0.
  3 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x220, including `sw` at 0x649c, `sw` at 0x64e8, `sw` at 0x64fc.
  The `sw` at 0x64b4 stores 4 bytes to a0 (arg0 at entry) +0x1b8.
  2 such `ld` accesses load 8 bytes from [ret(kdsp_find_param_info)+40]:8 +0x8, including `ld` at 0x64c0, `ld` at 0x64d8.
  The `jal` at 0x6408 calls kdsp_find_resource_in_list with a0=[a1+8], a1=a0+88, a2=?, a3=a3 at entry (arg3), a4=[a0+88]:8.
  The `jal` at 0x6434 calls kdsp_find_param_info with a0=a0 at entry (arg0), a1=[a1], a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0x6338 targets 0x6384, is taken when a0 == at(=[a0+496]:8+27896), and falls through when a0 != at(=[a0+496]:8+27896).
  The `beq` branch at 0x6344 targets 0x6384, is taken when a0 == v0(=[a0+496]:8+28448), and falls through when a0 != v0(=[a0+496]:8+28448).
  The `beq` branch at 0x6358 targets 0x6434, is taken when a1(=[a1]) == v1(=0x1000000d), and falls through when a1(=[a1]) != v1(=0x1000000d).
  The `beq` branch at 0x6364 targets 0x63b4, is taken when a1(=[a1]) == a0(=0x10000011), and falls through when a1(=[a1]) != a0(=0x10000011).
  The `beq` branch at 0x636c targets 0x6480, is taken when a1(=[a1]) == a2(=0x1000000e), and falls through when a1(=[a1]) != a2(=0x1000000e).
  The `beq` branch at 0x6374 targets 0x64a0, is taken when a1(=[a1]) == a0(=0x1000000f), and falls through when a1(=[a1]) != a0(=0x1000000f).
  The `beq` branch at 0x637c targets 0x63a0 and is always taken.
  The `beq` branch at 0x6384 targets 0x639c and is always taken.
  The `beq` branch at 0x63c0 targets 0x64e4, is taken when a0(=[a1+8]) == a1(=0x2000000a), and falls through when a0(=[a1+8]) != a1(=0x2000000a).
  The `beq` branch at 0x63cc targets 0x64f4, is taken when a0(=[a1+8]) == a1(=0x20000016), and falls through when a0(=[a1+8]) != a1(=0x20000016).
  The `beq` branch at 0x63d8 targets 0x6408, is taken when a4(=[a0+88]:8) == 0, and falls through when a4(=[a0+88]:8) != 0.
  The `beq` branch at 0x63e0 targets 0x63f4 and is always taken.
  The `beq` branch at 0x63ec targets 0x6408, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `bne` branch at 0x6400 targets 0x63e8, is taken when a2(?) < 0x18 (signed), and falls through when a2(?) >= 0x18 (signed).
  The `beq` branch at 0x6414 targets 0x638c, is taken when v0(=ret(kdsp_find_resource_in_list)) == 0, and falls through when v0(=ret(kdsp_find_resource_in_list)) != 0.
  The `beq` branch at 0x641c targets 0x642c, is taken when v0(=ret(kdsp_find_resource_in_list)) == a0(=[a0+496]:8+2520), and falls through when v0(=ret(kdsp_find_resource_in_list)) != a0(=[a0+496]:8+2520).
  The `bne` branch at 0x6424 targets 0x6498, is taken when v0(=ret(kdsp_find_resource_in_list)) != a1(=[a0+496]:8+2968), and falls through when v0(=ret(kdsp_find_resource_in_list)) == a1(=[a0+496]:8+2968).
  The `beq` branch at 0x642c targets 0x6498 and is always taken.
  The `blez` branch at 0x6440 targets 0x64b8, is taken when a1(=[a1+8]:8) <= 0 (signed), and falls through when a1(=[a1+8]:8) > 0 (signed).
  The `beq` branch at 0x6448 targets 0x64b8, is taken when v0(=ret(kdsp_find_param_info)) == 0, and falls through when v0(=ret(kdsp_find_param_info)) != 0.
  The `beq` branch at 0x6454 targets 0x64b8, is taken when a2(=[ret(kdsp_find_param_info)+40]:8) == 0, and falls through when a2(=[ret(kdsp_find_param_info)+40]:8) != 0.
  The `beq` branch at 0x6464 targets 0x64c0, is taken when a1(=[a1+8]:8) >= a0(=[[ret(kdsp_find_param_info)+40]:8]:8) (signed), and falls through when a1(=[a1+8]:8) < a0(=[[ret(kdsp_find_param_info)+40]:8]:8) (signed).
  The `beq` branch at 0x6478 targets 0x6398 and is always taken.
  The `blez` branch at 0x6488 targets 0x6518, is taken when a0(=[a1+8]) <= 0 (signed), and falls through when a0(=[a1+8]) > 0 (signed).
  The `beq` branch at 0x6490 targets 0x6398 and is always taken.
  The `beq` branch at 0x6498 targets 0x6394 and is always taken.
  The `blez` branch at 0x64a8 targets 0x6520, is taken when a0(=[a1+8]) <= 0 (signed), and falls through when a0(=[a1+8]) > 0 (signed).
  The `beq` branch at 0x64b0 targets 0x6398 and is always taken.
  The `beq` branch at 0x64b8 targets 0x6398 and is always taken.
  The `beq` branch at 0x64c8 targets 0x6508, is taken when a3(=[[ret(kdsp_find_param_info)+40]:8+8]:8) >= a1(=[a1+8]:8) (signed), and falls through when a3(=[[ret(kdsp_find_param_info)+40]:8+8]:8) < a1(=[a1+8]:8) (signed).
  The `beq` branch at 0x64dc targets 0x6398 and is always taken.
  The `beq` branch at 0x64ec targets 0x6398 and is always taken.
  The `beq` branch at 0x6500 targets 0x6398 and is always taken.
  The `beq` branch at 0x6510 targets 0x6398 and is always taken.
  The `beq` branch at 0x6518 targets 0x6398 and is always taken.
  The `beq` branch at 0x6520 targets 0x6398 and is always taken.
  The return at 0x63ac has v0 = one of 0x0, 0x1.

- `rad_get_clockgen_params` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x6528 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x6528-0x6594 (108 bytes).
  It occupies 108 bytes.
  The `lw` at 0x6528 loads 4 bytes from a1 (arg1 at entry) +0x0.
  The `ld` at 0x6538 loads 8 bytes from a0 (arg0 at entry) +0x1f0.
  The `ld` at 0x653c loads 8 bytes from a0 (arg0 at entry) +0x200.
  The `lw` at 0x655c loads 4 bytes from a0 (arg0 at entry) +0x1b0.
  The `sw` at 0x656c stores 4 bytes to a1 (arg1 at entry) +0x8.
  The `lw` at 0x6580 loads 4 bytes from a0 (arg0 at entry) +0x1b8.
  The `bne` branch at 0x6534 targets 0x6578, is taken when at(=[a1]) != v0(=0x10000010), and falls through when at(=[a1]) == v0(=0x10000010).
  The `beq` branch at 0x654c targets 0x655c, is taken when a6(=[a0+512]:8) == v1(=[a0+496]:8+2520), and falls through when a6(=[a0+512]:8) != v1(=[a0+496]:8+2520).
  The `bne` branch at 0x6554 targets 0x658c, is taken when a6(=[a0+512]:8) != a5(=[a0+496]:8+2968), and falls through when a6(=[a0+512]:8) == a5(=[a0+496]:8+2968).
  The `beq` branch at 0x6560 targets 0x6580, is taken when a2(=[a0+432]) == a4(=0x1), and falls through when a2(=[a0+432]) != a4(=0x1).
  The `bne` branch at 0x6584 targets 0x656c, is taken when a3(=[a0+440]) != a4(=0x1), and falls through when a3(=[a0+440]) == a4(=0x1).
  The `beq` branch at 0x658c targets 0x656c and is always taken.
  The return at 0x6570 has v0 = 0x1.
  The return at 0x6578 has v0 = 0x0.

- `rad_set_digital_if_params` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x6594 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x6594-0x65dc (72 bytes).
  It occupies 72 bytes.
  The `lw` at 0x6594 loads 4 bytes from a1 (arg1 at entry) +0x0.
  The `beq` branch at 0x65a8 targets 0x65d0, is taken when v0(=[a1]) == at(=0x10000004), and falls through when v0(=[a1]) != at(=0x10000004).
  The `beq` branch at 0x65b0 targets 0x65d0, is taken when v0(=[a1]) == a3(=0x10000019), and falls through when v0(=[a1]) != a3(=0x10000019).
  The `beq` branch at 0x65b8 targets 0x65d0, is taken when v0(=[a1]) == a4(=0x1000001b), and falls through when v0(=[a1]) != a4(=0x1000001b).
  The `beq` branch at 0x65c0 targets 0x65d4, is taken when v0(=[a1]) == a5(=0x1000001c), and falls through when v0(=[a1]) != a5(=0x1000001c).
  The return at 0x65c8 has v0 = 0x0.
  The return at 0x65d4 has v0 = 0x1.

- `rad_set_analog_in_gain` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x65dc (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x65dc-0x671c (320 bytes).
  It occupies 320 bytes.
  The `ld` at 0x65e8 loads 8 bytes from a0 (arg0 at entry) +0x198.
  The `ld` at 0x65f0 loads 8 bytes from [a0+408]:8 +0x2a0.
  3 such `lw` accesses load 4 bytes from [[a0+408]:8+672]:8 +0x7260, including `lw` at 0x6664, `lw` at 0x66b4, `lw` at 0x66ec.
  2 such `sw` accesses store 4 bytes to [[a0+408]:8+672]:8 +0x7260, including `sw` at 0x6678, `sw` at 0x66c0.
  2 such `sw` accesses store 4 bytes to ?, including `sw` at 0x667c, `sw` at 0x66c8.
  The `ld` at 0x66a0 loads 8 bytes from ?.
  The `ld` at 0x66f4 loads 8 bytes from [[a0+408]:8+672]:8 +0x228.
  The `sw` at 0x6704 stores 4 bytes to [[[a0+408]:8+672]:8+552]:8 +0x7c.
  The `jal` at 0x6650 calls kdsp_db_gain_to_regval with a0=?, a1=a0 at entry (arg0), a2=0x0, a3=?.
  The `bne` branch at 0x660c targets 0x661c, is taken when a0 != at(=[[a0+408]:8+672]:8+23144), and falls through when a0 == at(=[[a0+408]:8+672]:8+23144).
  The `beq` branch at 0x6614 targets 0x6620 and is always taken.
  The `blez` branch at 0x662c targets 0x66cc, is taken when s5(=a2) <= 0 (signed), and falls through when s5(=a2) > 0 (signed).
  The `beq` branch at 0x6644 targets 0x6708 and is always taken.
  The `bltz` branch at 0x6658 targets 0x6680, is taken when v0(=ret(kdsp_db_gain_to_regval)) < 0 (signed), and falls through when v0(=ret(kdsp_db_gain_to_regval)) >= 0 (signed).
  The `beq` branch at 0x6694 targets 0x66cc, is taken when s1(?) >= s5(=a2) (signed), and falls through when s1(?) < s5(=a2) (signed).
  The `bne` branch at 0x66ac targets 0x664c, is taken when a0(?) != s3(=0x8000000000000000), and falls through when a0(?) == s3(=0x8000000000000000).
  The `beq` branch at 0x66c4 targets 0x6680 and is always taken.
  The `beq` branch at 0x6714 targets 0x66a0 and is always taken.
  The return at 0x6700 has v0 = [[[a0+408]:8+672]:8+552]:8.

- `rad_set_analog_in_if_params` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x671c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x671c-0x67d4 (184 bytes).
  It occupies 184 bytes.
  The `lw` at 0x6720 loads 4 bytes from a1 (arg1 at entry) +0x0.
  The `lh` at 0x6778 loads 2 bytes from a1 (arg1 at entry) +0x14.
  The `ld` at 0x67ac loads 8 bytes from a0 (arg0 at entry) +0x198.
  The `lw` at 0x67c0 loads 4 bytes from [a0+408]:8 +0x238.
  The `jal` at 0x678c calls rad_set_analog_in_gain with a0=a0 at entry (arg0), a1=ret(kdsp_fetch_external), a2=?, a3=0x2.
  The `jal` at 0x67bc calls kdsp_fetch_external with a0=a1 at entry (arg1), a1=sp-48, a2=[[a0+408]:8+568], a3=0x8, a4=a2 at entry (arg2), a6=0x10000004, a7=0x1000001b.
  The `beq` branch at 0x6744 targets 0x67a8, is taken when v0(=[a1]) == at(=0x10000019), and falls through when v0(=[a1]) != at(=0x10000019).
  The `beq` branch at 0x674c targets 0x6798, is taken when v0(=[a1]) == a6(=0x10000004), and falls through when v0(=[a1]) != a6(=0x10000004).
  The `beq` branch at 0x6754 targets 0x6798, is taken when v0(=[a1]) == a7(=0x1000001b), and falls through when v0(=[a1]) != a7(=0x1000001b).
  The `beq` branch at 0x675c targets 0x6798, is taken when v0(=[a1]) == t0(=0x1000001c), and falls through when v0(=[a1]) != t0(=0x1000001c).
  The `beq` branch at 0x6768 targets 0x679c and is always taken.
  The `bne` branch at 0x67c4 targets 0x6770, is taken when v0(=ret(kdsp_fetch_external)) != 0, and falls through when v0(=ret(kdsp_fetch_external)) == 0.
  The `beq` branch at 0x67cc targets 0x679c and is always taken.
  The return at 0x67a0 has v0 = one of 0x0, 0x1.

- `rad_get_analog_in_if_params` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x67d4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x67d4-0x6940 (364 bytes).
  It occupies 364 bytes.
  The `lw` at 0x67f0 loads 4 bytes from a1 (arg1 at entry) +0x0.
  The `ld` at 0x6808 loads 8 bytes from a0 (arg0 at entry) +0x198.
  The `ld` at 0x6820 loads 8 bytes from [a0+408]:8 +0x2a0.
  The `lw` at 0x682c loads 4 bytes from [a0+408]:8 +0x238.
  2 such `sd` accesses store 8 bytes to ?, including `sd` at 0x6880, `sd` at 0x68bc.
  The `lw` at 0x68a0 loads 4 bytes from ?.
  3 such `sw` accesses store 4 bytes to a1 (arg1 at entry) +0x8, including `sw` at 0x6914, `sw` at 0x691c, `sw` at 0x6924.
  The `lw` at 0x693c loads 4 bytes from ([[a0+408]:8+672]:8 + one of 0x72b0, 0x72b8) +0x0.
  The `jal` at 0x68b0 calls kdsp_regval_to_db_gain with a0=?, a1=a0 at entry (arg0), a2=0x0, a3=?.
  The `jal` at 0x68dc calls kdsp_put_external with a0=a1 at entry (arg1), a1=sp-96, a2=[[a0+408]:8+568], a3=0x8, a4=a2 at entry (arg2).
  The `beq` branch at 0x6828 targets 0x684c, is taken when a6(=[a1]) == at(=0x10000019), and falls through when a6(=[a1]) != at(=0x10000019).
  The `beq` branch at 0x6834 targets 0x6908, is taken when a6(=[a1]) == a4(=0x10000004), and falls through when a6(=[a1]) != a4(=0x10000004).
  The `beq` branch at 0x683c targets 0x6918, is taken when a6(=[a1]) == a7(=0x1000001c), and falls through when a6(=[a1]) != a7(=0x1000001c).
  The `beq` branch at 0x6844 targets 0x68ec and is always taken.
  The `bne` branch at 0x6854 targets 0x6864, is taken when a0 != t8(=[[a0+408]:8+672]:8+23144), and falls through when a0 == t8(=[[a0+408]:8+672]:8+23144).
  The `beq` branch at 0x685c targets 0x6868 and is always taken.
  The `blez` branch at 0x686c targets 0x68c0, is taken when s2(=[[a0+408]:8+568]) <= 0 (signed), and falls through when s2(=[[a0+408]:8+568]) > 0 (signed).
  The `beq` branch at 0x6878 targets 0x6928 and is always taken.
  The `beq` branch at 0x6898 targets 0x68c0, is taken when s0(?) >= s2(=[[a0+408]:8+568]) (signed), and falls through when s0(?) < s2(=[[a0+408]:8+568]) (signed).
  The `beq` branch at 0x68a4 targets 0x6880, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x68b8 targets 0x6884 and is always taken.
  The `bne` branch at 0x6908 targets 0x6920, is taken when s3(=a0) != a0(=[[a0+408]:8+672]:8+23144), and falls through when s3(=a0) == a0(=[[a0+408]:8+672]:8+23144).
  The `beq` branch at 0x6910 targets 0x68e4 and is always taken.
  The `beq` branch at 0x6918 targets 0x68e4 and is always taken.
  The `beq` branch at 0x6920 targets 0x68e4 and is always taken.
  The `beq` branch at 0x6938 targets 0x68a4 and is always taken.
  The return at 0x6900 has v0 = one of 0x0, 0x1.

- `rad_set_analog_out_if_params` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x6940 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x6940-0x6bb8 (632 bytes).
  It occupies 632 bytes.
  The `lw` at 0x6958 loads 4 bytes from a1 (arg1 at entry) +0x0.
  The `ld` at 0x6964 loads 8 bytes from a0 (arg0 at entry) +0x198.
  The `ld` at 0x6980 loads 8 bytes from [a0+408]:8 +0x2a0.
  The `lw` at 0x69c0 loads 4 bytes from a1 (arg1 at entry) +0x8.
  The `lw` at 0x69c4 loads 4 bytes from [[a0+408]:8+672]:8 +0x7244.
  3 such `ld` accesses load 8 bytes from [[a0+408]:8+672]:8 +0x228, including `ld` at 0x69cc, `ld` at 0x6b74, `ld` at 0x6b8c.
  The `sw` at 0x69dc stores 4 bytes to [[a0+408]:8+672]:8 +0x7244.
  The `sw` at 0x69e0 stores 4 bytes to [[[a0+408]:8+672]:8+552]:8 +0x70.
  The `ld` at 0x6a34 loads 8 bytes from ret(kdsp_fetch_external) +0x0.
  The `lw` at 0x6a60 loads 4 bytes from [a0+408]:8 +0x238.
  The `lh` at 0x6a8c loads 2 bytes from a1 (arg1 at entry) +0x14.
  3 such `lw` accesses load 4 bytes from [[a0+408]:8+672]:8 +0x7260, including `lw` at 0x6af8, `lw` at 0x6b50, `lw` at 0x6b78.
  2 such `sw` accesses store 4 bytes to [[a0+408]:8+672]:8 +0x7260, including `sw` at 0x6b14, `sw` at 0x6b64.
  2 such `sw` accesses store 4 bytes to ?, including `sw` at 0x6b18, `sw` at 0x6b6c.
  The `ld` at 0x6b44 loads 8 bytes from ?.
  The `sw` at 0x6b80 stores 4 bytes to [[[a0+408]:8+672]:8+552]:8 +0x7c.
  2 such `sw` accesses store 4 bytes to [[a0+408]:8+672]:8 +0x7270, including `sw` at 0x6b84, `sw` at 0x6ba0.
  The `sw` at 0x6b90 stores 4 bytes to [[[a0+408]:8+672]:8+552]:8 +0x90.
  The `sw` at 0x6b98 stores 4 bytes to a0 (arg0 at entry) +0x1a0.
  The `jal` at 0x6a2c calls kdsp_fetch_external with a0=a1 at entry (arg1), a1=sp-96, a2=0x1, a3=0x8, a4=a2 at entry (arg2), a6=0x10000000, a7=0x1000001c.
  The `jal` at 0x6a64 calls kdsp_fetch_external with a0=a1 at entry (arg1), a1=sp-88, a2=[[a0+408]:8+568], a3=0x8, a4=a2 at entry (arg2), a6=0x10000000, a7=0x1000001c.
  The `jal` at 0x6a94 calls kdsp_find_param_info with a0=a0 at entry (arg0), a1=0x10000019, a2=[a1+20]:2, a3=?.
  The `jal` at 0x6ad8 calls kdsp_db_gain_to_regval with a0=?, a1=a0 at entry (arg0), a2=0x0, a3=?, a4=0xff.
  The `beq` branch at 0x697c targets 0x6a10, is taken when v0(=[a1]) == t2(=0x10000019), and falls through when v0(=[a1]) != t2(=0x10000019).
  The `beq` branch at 0x698c targets 0x69b8, is taken when v0(=[a1]) == at(=0x1000001d), and falls through when v0(=[a1]) != at(=0x1000001d).
  The `beq` branch at 0x6994 targets 0x6a24, is taken when v0(=[a1]) == a7(=0x1000001c), and falls through when v0(=[a1]) != a7(=0x1000001c).
  The `beq` branch at 0x699c targets 0x69e8, is taken when v0(=[a1]) == a1(=0x10000004), and falls through when v0(=[a1]) != a1(=0x10000004).
  The `beq` branch at 0x69a4 targets 0x69e8, is taken when v0(=[a1]) == t0(=0x1000001b), and falls through when v0(=[a1]) != t0(=0x1000001b).
  The `beq` branch at 0x69b0 targets 0x69ec and is always taken.
  The `bne` branch at 0x69b8 targets 0x6a04, is taken when s1(=a0) != a0(=[[a0+408]:8+672]:8+23568), and falls through when s1(=a0) == a0(=[[a0+408]:8+672]:8+23568).
  The `beq` branch at 0x6a08 targets 0x69ec and is always taken.
  The `beq` branch at 0x6a14 targets 0x6a5c, is taken when a0 == v1(=[[a0+408]:8+672]:8+23568), and falls through when a0 != v1(=[[a0+408]:8+672]:8+23568).
  The `beq` branch at 0x6a1c targets 0x69ec and is always taken.
  The `beq` branch at 0x6a44 targets 0x6b9c, is taken when a0(?) == a1(=0x12), and falls through when a0(?) != a1(=0x12).
  The `beq` branch at 0x6a4c targets 0x6b84, is taken when a0(?) == a1(=0x10), and falls through when a0(?) != a1(=0x10).
  The `beq` branch at 0x6a54 targets 0x69ec and is always taken.
  The `bne` branch at 0x6a70 targets 0x6a80, is taken when v0(=ret(kdsp_fetch_external)) != 0, and falls through when v0(=ret(kdsp_fetch_external)) == 0.
  The `beq` branch at 0x6a78 targets 0x69ec and is always taken.
  The `blez` branch at 0x6ac0 targets 0x6b70, is taken when a3(?) <= 0 (signed), and falls through when a3(?) > 0 (signed).
  The `beq` branch at 0x6acc targets 0x6bac and is always taken.
  The `bltz` branch at 0x6aec targets 0x6b1c, is taken when v0(=ret(kdsp_db_gain_to_regval)) < 0 (signed), and falls through when v0(=ret(kdsp_db_gain_to_regval)) >= 0 (signed).
  The `beq` branch at 0x6b30 targets 0x6b70, is taken when s2(?) >= t1(?) (signed), and falls through when s2(?) < t1(?) (signed).
  The `bne` branch at 0x6b48 targets 0x6ad4, is taken when a0(?) != a2(=0x8000000000000000), and falls through when a0(?) == a2(=0x8000000000000000).
  The `beq` branch at 0x6b68 targets 0x6b1c and is always taken.
  The `beq` branch at 0x6b7c targets 0x69e4 and is always taken.
  The `beq` branch at 0x6b94 targets 0x69e4 and is always taken.
  The `beq` branch at 0x6ba4 targets 0x6b8c and is always taken.
  The `beq` branch at 0x6bb0 targets 0x6b3c and is always taken.
  The return at 0x69fc has v0 = one of 0x0, 0x1.

- `rad_get_analog_out_if_params` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x6bb8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x6bb8-0x6d4c (404 bytes).
  It occupies 404 bytes.
  The `lw` at 0x6bd0 loads 4 bytes from a1 (arg1 at entry) +0x0.
  The `ld` at 0x6bdc loads 8 bytes from a0 (arg0 at entry) +0x198.
  The `ld` at 0x6bf4 loads 8 bytes from [a0+408]:8 +0x2a0.
  The `lw` at 0x6c00 loads 4 bytes from [a0+408]:8 +0x238.
  The `lw` at 0x6c18 loads 4 bytes from [[a0+408]:8+672]:8 +0x7270.
  The `lw` at 0x6c24 loads 4 bytes from sym(.data) +0x7430.
  3 such `sw` accesses store 4 bytes to a1 (arg1 at entry) +0x8, including `sw` at 0x6c28, `sw` at 0x6c68, `sw` at 0x6c7c.
  The `lw` at 0x6c58 loads 4 bytes from [[a0+408]:8+672]:8 +0x7244.
  The `lw` at 0x6c74 loads 4 bytes from sym(.data) +0x7428.
  The `ld` at 0x6cac loads 8 bytes from sym(.bss) +0x58.
  2 such `sd` accesses store 8 bytes to ?, including `sd` at 0x6cd8, `sd` at 0x6d30.
  The `lw` at 0x6cf4 loads 4 bytes from ?.
  The `lw` at 0x6d48 loads 4 bytes from [[a0+408]:8+672]:8 +0x72c0.
  The `jal` at 0x6c80 calls kdsp_find_param_info with a0=a0 at entry (arg0), a1=0x10000019, a2=a2 at entry (arg2), a3=a3 at entry (arg3), a6=0x1000001d, a7=0x1000001c.
  The `jal` at 0x6cc8 calls kdsp_put_external with a0=a1 at entry (arg1), a1=sp-80, a2=[[a0+408]:8+568], a3=0x8, a4=a2 at entry (arg2), a7=sp-80.
  The `jal` at 0x6d18 calls kdsp_regval_to_db_gain with a0=?, a1=a0 at entry (arg0), a2=0x0, a3=?, a7=sp-80.
  The `beq` branch at 0x6bfc targets 0x6c80, is taken when v0(=[a1]) == t2(=0x10000019), and falls through when v0(=[a1]) != t2(=0x10000019).
  The `beq` branch at 0x6c08 targets 0x6c48, is taken when v0(=[a1]) == a6(=0x1000001d), and falls through when v0(=[a1]) != a6(=0x1000001d).
  The `bne` branch at 0x6c10 targets 0x6c6c, is taken when v0(=[a1]) != a7(=0x1000001c), and falls through when v0(=[a1]) == a7(=0x1000001c).
  The `beq` branch at 0x6c1c targets 0x6c74, is taken when t8(=[[[a0+408]:8+672]:8+29296]) == t9(=0x2), and falls through when t8(=[[[a0+408]:8+672]:8+29296]) != t9(=0x2).
  The `beq` branch at 0x6c48 targets 0x6c58, is taken when s1(=a0) == a0(=[[a0+408]:8+672]:8+23568), and falls through when s1(=a0) != a0(=[[a0+408]:8+672]:8+23568).
  The `beq` branch at 0x6c50 targets 0x6c34 and is always taken.
  The `beq` branch at 0x6c64 targets 0x6c2c and is always taken.
  The `beq` branch at 0x6c6c targets 0x6c30 and is always taken.
  The `beq` branch at 0x6c78 targets 0x6c2c and is always taken.
  The `bne` branch at 0x6c90 targets 0x6cac, is taken when s1(=a0) != a0(=[[a0+408]:8+672]:8+23568), and falls through when s1(=a0) == a0(=[[a0+408]:8+672]:8+23568).
  The `blez` branch at 0x6c98 targets 0x6cbc, is taken when s3(=[[a0+408]:8+568]) <= 0 (signed), and falls through when s3(=[[a0+408]:8+568]) > 0 (signed).
  The `beq` branch at 0x6ca4 targets 0x6d3c and is always taken.
  The `beq` branch at 0x6cd0 targets 0x6c2c and is always taken.
  The `beq` branch at 0x6cec targets 0x6d34, is taken when a0(?) >= s3(=[[a0+408]:8+568]) (signed), and falls through when a0(?) < s3(=[[a0+408]:8+568]) (signed).
  The `beq` branch at 0x6d08 targets 0x6cd8, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `beq` branch at 0x6d2c targets 0x6cdc and is always taken.
  The `beq` branch at 0x6d34 targets 0x6cbc and is always taken.
  The `beq` branch at 0x6d44 targets 0x6cf8 and is always taken.
  The return at 0x6c40 has v0 = one of 0x0, 0x1.

- `rad_vl_write_MUX_SEL_MIO` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x6d4c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x6d4c-0x6dcc (128 bytes).
  It occupies 128 bytes.
  6 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x228, including `ld` at 0x6d60, `ld` at 0x6d74, `ld` at 0x6d8c.
  2 such `sw` accesses store 4 bytes to [a0+552]:8 +0x8c, including `sw` at 0x6d6c, `sw` at 0x6dc8.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x7248, including `lw` at 0x6d70, `lw` at 0x6d84.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x7248, including `sw` at 0x6d7c, `sw` at 0x6d94.
  2 such `sw` accesses store 4 bytes to [a0+552]:8 +0x4c, including `sw` at 0x6d80, `sw` at 0x6d9c.
  2 such `sw` accesses store 4 bytes to [a0+552]:8 +0x88, including `sw` at 0x6da8, `sw` at 0x6db8.
  The `sw` at 0x6db4 stores 4 bytes to a0 (arg0 at entry) +0x7268.
  The `lw` at 0x6dc0 loads 4 bytes from a0 (arg0 at entry) +0x726c.
  The `bgez` branch at 0x6d98 targets 0x6d5c, is taken when a3(?) >= 0 (signed), and falls through when a3(?) < 0 (signed).
  The return at 0x6dc4 has v0 = ?.

- `rad_vl_write_MUX_SEL_RADICAL` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x6dcc (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x6dcc-0x6dd8 (12 bytes).
  It occupies 12 bytes.
  The `ld` at 0x6dcc loads 8 bytes from a0 (arg0 at entry) +0x228.
  The `sw` at 0x6dd4 stores 4 bytes to [a0+552]:8 +0x7c.
  The return at 0x6dd0 has v0 = ?.

- `rad_vl_write_MUX_SEL` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x6dd8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x6dd8-0x6e20 (72 bytes).
  It occupies 72 bytes.
  The `lh` at 0x6dd8 loads 2 bytes from a0 (arg0 at entry) +0x21a.
  The `jal` at 0x6e00 calls rad_vl_write_MUX_SEL_RADICAL with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=0xd, a4=[a0+538]:2.
  The `jal` at 0x6e10 calls rad_vl_write_MUX_SEL_MIO with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=0xd, a4=[a0+538]:2.
  The `beq` branch at 0x6de8 targets 0x6e10, is taken when a4(=[a0+538]:2) == at(=0x7), and falls through when a4(=[a0+538]:2) != at(=0x7).
  The `beq` branch at 0x6df0 targets 0x6e00, is taken when a4(=[a0+538]:2) == a3(=0xd), and falls through when a4(=[a0+538]:2) != a3(=0xd).
  The `beq` branch at 0x6e08 targets 0x6df8 and is always taken.
  The `beq` branch at 0x6e18 targets 0x6df8 and is always taken.
  The return at 0x6df8 has v0 = one of ?, ret(rad_vl_write_MUX_SEL_RADICAL), ret(rad_vl_write_MUX_SEL_MIO).

- `rad_vl_set_clockgen_MIO` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x6e20 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x6e20-0x7014 (500 bytes).
  It occupies 500 bytes.
  The `ld` at 0x6e28 loads 8 bytes from a0 (arg0 at entry) +0x1f0.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x1b8, including `lw` at 0x6e84, `lw` at 0x6eac, `lw` at 0x6ee4.
  3 such `lw` accesses load 4 bytes from [a0+496]:8 +0x7274, including `lw` at 0x6e9c, `lw` at 0x6ecc, `lw` at 0x6fec.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x1b0, including `lw` at 0x6eb8, `lw` at 0x6f88, `lw` at 0x6fb0.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x208, including `lw` at 0x6ef8, `lw` at 0x6f98.
  The `lw` at 0x6f08 loads 4 bytes from (sym(.rodata) + ([a0+520] << 0x3)) +0x0.
  The `lw` at 0x6f0c loads 4 bytes from (sym(.rodata) + ([a0+520] << 0x3)) +0x4.
  2 such `sw` accesses store 4 bytes to [a0+496]:8 +0x7274, including `sw` at 0x6f2c, `sw` at 0x7008.
  The `jal` at 0x6f28 calls rad_vl_write_MUX_SEL_MIO with a0=[a0+496]:8, a1=?, a2=?, a3=([a0+520] << 0x3), a4=one of 0x0, 0x1, 0x2, a5=[a0+496]:8+26240, a6=[a0+496]:8+26240.
  The `jal` at 0x6f30 calls rad_update_ksync with a0=[a0+496]:8, a1=?, a2=?, a3=?.
  The `bne` branch at 0x6e50 targets 0x6e5c, is taken when s3(=[a0+496]:8+2968) != a1, and falls through when s3(=[a0+496]:8+2968) == a1.
  The `bne` branch at 0x6e58 targets 0x6e84, is taken when a0 != v0(=[a0+496]:8+26240), and falls through when a0 == v0(=[a0+496]:8+26240).
  The `bne` branch at 0x6e60 targets 0x6e78, is taken when s2(=a1) != at(=[a0+496]:8+2520), and falls through when s2(=a1) == at(=[a0+496]:8+2520).
  The `beq` branch at 0x6e68 targets 0x6e7c, is taken when s1(=a0) == v0(=[a0+496]:8+26240), and falls through when s1(=a0) != v0(=[a0+496]:8+26240).
  The `beq` branch at 0x6e70 targets 0x6e7c and is always taken.
  The `beq` branch at 0x6e7c targets 0x6e94, is taken when v0(=one of 0x0, 0x1) == 0, and falls through when v0(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x6e8c targets 0x6f88, is taken when v0(=[a0+440]) == a4(=0x1), and falls through when v0(=[a0+440]) != a4(=0x1).
  The `bne` branch at 0x6e94 targets 0x6ecc, is taken when s3(=[a0+496]:8+2968) != s2(=a1), and falls through when s3(=[a0+496]:8+2968) == s2(=a1).
  The `beq` branch at 0x6ea0 targets 0x6ed4, is taken when s1(=a0) == a5(=[a0+496]:8+26240), and falls through when s1(=a0) != a5(=[a0+496]:8+26240).
  The `bne` branch at 0x6eb0 targets 0x6ed4, is taken when v1(=[a0+440]) != a4(=0x1), and falls through when v1(=[a0+440]) == a4(=0x1).
  The `bne` branch at 0x6ebc targets 0x6ed4, is taken when a0(=[a0+432]) != a4(=0x1), and falls through when a0(=[a0+432]) == a4(=0x1).
  The `beq` branch at 0x6ec4 targets 0x6ef8 and is always taken.
  The `bne` branch at 0x6ed4 targets 0x6ef4, is taken when s2(=a1) != a1(=[a0+496]:8+2520), and falls through when s2(=a1) == a1(=[a0+496]:8+2520).
  The `beq` branch at 0x6edc targets 0x6ef0, is taken when s1(=a0) == a6(=[a0+496]:8+26240), and falls through when s1(=a0) != a6(=[a0+496]:8+26240).
  The `beq` branch at 0x6ee8 targets 0x6fb0, is taken when a2(=[a0+440]) == a4(=0x1), and falls through when a2(=[a0+440]) != a4(=0x1).
  The `bne` branch at 0x6f3c targets 0x6f58, is taken when s3(=[a0+496]:8+2968) != s2(=a1), and falls through when s3(=[a0+496]:8+2968) == s2(=a1).
  The `beq` branch at 0x6f48 targets 0x6f5c, is taken when s1(=a0) == a3(=[a0+496]:8+26240), and falls through when s1(=a0) != a3(=[a0+496]:8+26240).
  The `beq` branch at 0x6f50 targets 0x6f74 and is always taken.
  The `bne` branch at 0x6f5c targets 0x6f6c, is taken when s2(=a1) != a4(=[a0+496]:8+2520), and falls through when s2(=a1) == a4(=[a0+496]:8+2520).
  The `bne` branch at 0x6f64 targets 0x6f50, is taken when s1(=a0) != a5(=[a0+496]:8+26240), and falls through when s1(=a0) == a5(=[a0+496]:8+26240).
  The `bne` branch at 0x6f8c targets 0x6e94, is taken when a7(=[a0+432]) != a4(=0x1), and falls through when a7(=[a0+432]) == a4(=0x1).
  The `bne` branch at 0x6f94 targets 0x6fc4, is taken when s3(=[a0+496]:8+2968) != s2(=a1), and falls through when s3(=[a0+496]:8+2968) == s2(=a1).
  The `beq` branch at 0x6fa0 targets 0x6fc4, is taken when s1(=a0) == t0(=[a0+496]:8+26240), and falls through when s1(=a0) != t0(=[a0+496]:8+26240).
  The `beq` branch at 0x6fa8 targets 0x6fec and is always taken.
  The `bne` branch at 0x6fb4 targets 0x6ef4, is taken when t1(=[a0+432]) != a4(=0x1), and falls through when t1(=[a0+432]) == a4(=0x1).
  The `beq` branch at 0x6fbc targets 0x6ef4 and is always taken.
  The `bne` branch at 0x6fc8 targets 0x6fe8, is taken when s2(=a1) != t2(=[a0+496]:8+2520), and falls through when s2(=a1) == t2(=[a0+496]:8+2520).
  The `beq` branch at 0x6fd4 targets 0x6fe4, is taken when s1(=a0) == t3(=[a0+496]:8+26240), and falls through when s1(=a0) != t3(=[a0+496]:8+26240).
  The `beq` branch at 0x6fdc targets 0x6fec and is always taken.
  The `bne` branch at 0x7004 targets 0x6ed0, is taken when s3(=[a0+496]:8+2968) != s2(=a1), and falls through when s3(=[a0+496]:8+2968) == s2(=a1).
  The `beq` branch at 0x700c targets 0x6ea0 and is always taken.
  The return at 0x6f80 has v0 = one of 0x0, 0x1.

- `rad_vl_set_clockgen_RADICAL` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x7014 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x7014-0x7130 (284 bytes).
  It occupies 284 bytes.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x208, including `lw` at 0x701c, `lw` at 0x7094, `lw` at 0x7118.
  The `ld` at 0x7030 loads 8 bytes from a0 (arg0 at entry) +0x1f0.
  The `lw` at 0x7044 loads 4 bytes from [a0+496]:8 +0x7274.
  2 such `sw` accesses store 4 bytes to [a0+496]:8 +0x7274, including `sw` at 0x7068, `sw` at 0x70c8.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x1b8, including `lw` at 0x706c, `lw` at 0x7084.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x1b0, including `lw` at 0x7108, `lw` at 0x711c.
  The `jal` at 0x70c4 calls rad_vl_write_MUX_SEL_RADICAL with a0=[a0+496]:8, a1=?, a2=?, a3=?, a4=one of 0x0, 0x1, 0x2, a6=0x6, a7=-0xc1.
  The `jal` at 0x70cc calls rad_update_ksync with a0=[a0+496]:8, a1=?, a2=?, a3=?.
  The `bne` branch at 0x7064 targets 0x7078, is taken when s8(=[a0+496]:8+2968) != a1, and falls through when s8(=[a0+496]:8+2968) == a1.
  The `beq` branch at 0x7074 targets 0x7108, is taken when t1(=[a0+440]) == a4(=0x1), and falls through when t1(=[a0+440]) != a4(=0x1).
  The `bne` branch at 0x707c targets 0x7090, is taken when s1(=a1) != t2(=[a0+496]:8+2520), and falls through when s1(=a1) == t2(=[a0+496]:8+2520).
  The `beq` branch at 0x7088 targets 0x711c, is taken when t3(=[a0+440]) == a4(=0x1), and falls through when t3(=[a0+440]) != a4(=0x1).
  The `beq` branch at 0x70d8 targets 0x7100, is taken when s8(=[a0+496]:8+2968) == s1(=a1), and falls through when s8(=[a0+496]:8+2968) != s1(=a1).
  The `beq` branch at 0x70e4 targets 0x7100, is taken when s1(=a1) == t0(=[a0+496]:8+2520), and falls through when s1(=a1) != t0(=[a0+496]:8+2520).
  The `beq` branch at 0x7100 targets 0x70ec and is always taken.
  The `bne` branch at 0x710c targets 0x707c, is taken when t1(=[a0+432]) != a4(=0x1), and falls through when t1(=[a0+432]) == a4(=0x1).
  The `beq` branch at 0x7114 targets 0x7098 and is always taken.
  The `bne` branch at 0x7120 targets 0x7094, is taken when t2(=[a0+432]) != a4(=0x1), and falls through when t2(=[a0+432]) == a4(=0x1).
  The `beq` branch at 0x7128 targets 0x7094 and is always taken.
  The return at 0x70f8 has v0 = one of 0x0, 0x1.

- `rad_vl_set_clockgen` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x7130 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x7130-0x7174 (68 bytes).
  It occupies 68 bytes.
  The `ld` at 0x7130 loads 8 bytes from a0 (arg0 at entry) +0x1f0.
  The `lh` at 0x7134 loads 2 bytes from [a0+496]:8 +0x21a.
  The `jal` at 0x7148 calls rad_vl_set_clockgen_RADICAL with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x7164 calls rad_vl_set_clockgen_MIO with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0x7140 targets 0x7164, is taken when at(=[[a0+496]:8+538]:2) == v0(=0x7), and falls through when at(=[[a0+496]:8+538]:2) != v0(=0x7).
  The `beq` branch at 0x716c targets 0x7154 and is always taken.
  The return at 0x715c has v0 = one of ret(rad_vl_set_clockgen_RADICAL), ret(rad_vl_set_clockgen_MIO).

- `rad_update_ksync` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x7174 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x7174-0x746c (760 bytes).
  It occupies 760 bytes.
  The `ld` at 0x7180 loads 8 bytes from a0 (arg0 at entry) +0x72e8.
  20 such `lw` accesses load 4 bytes from ?, including `lw` at 0x7218, `lw` at 0x7268, `lw` at 0x7278.
  5 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x228, including `ld` at 0x7228, `ld` at 0x7230, `ld` at 0x72dc.
  2 such `sw` accesses store 4 bytes to [a0+552]:8 +0xa4, including `sw` at 0x722c, `sw` at 0x72e8.
  2 such `sw` accesses store 4 bytes to [a0+552]:8 +0xa0, including `sw` at 0x7234, `sw` at 0x7300.
  3 such `sw` accesses store 4 bytes to ?, including `sw` at 0x7238, `sw` at 0x723c, `sw` at 0x72d0.
  The `bne` branch at 0x71a0 targets 0x71c4, is taken when v0(=[a0+29416]:8) < at(=0xfa24e2) (signed), and falls through when v0(=[a0+29416]:8) >= at(=0xfa24e2) (signed).
  The `bne` branch at 0x71b4 targets 0x71c4, is taken when v1(=0x1029fa0) < v0(=[a0+29416]:8) (signed), and falls through when v1(=0x1029fa0) >= v0(=[a0+29416]:8) (signed).
  The `beq` branch at 0x71bc targets 0x71e4 and is always taken.
  The `bne` branch at 0x71d0 targets 0x728c, is taken when v0(=[a0+29416]:8) < a1(=0x12b3123) (signed), and falls through when v0(=[a0+29416]:8) >= a1(=0x12b3123) (signed).
  The `bne` branch at 0x71d8 targets 0x73dc, is taken when a4(?) != 0, and falls through when a4(?) == 0.
  The `beq` branch at 0x7200 targets 0x7254 and is always taken.
  The `beq` branch at 0x7208 targets 0x73e8, is taken when t1(=one of 0x0, 0x1) == 0, and falls through when t1(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x7220 targets 0x7450, is taken when a4(=0x11ffe89) == t8(?), and falls through when a4(=0x11ffe89) != t8(?).
  The `beq` branch at 0x7240 targets 0x7398, is taken when a7(=one of 0x0, 0x1) == 0, and falls through when a7(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x724c targets 0x7290, is taken when v1(?) == 0, and falls through when v1(?) != 0.
  The `beq` branch at 0x7254 targets 0x7208, is taken when v0(?) == t2(=0x1), and falls through when v0(?) != t2(=0x1).
  The `beq` branch at 0x725c targets 0x73a8, is taken when t1(=one of 0x0, 0x1) == 0, and falls through when t1(=one of 0x0, 0x1) != 0.
  The `bne` branch at 0x7270 targets 0x7228, is taken when t0(=0x54fd8f) != a1(?), and falls through when t0(=0x54fd8f) == a1(?).
  The `bne` branch at 0x727c targets 0x7228, is taken when a6(=0x400166b) != t8(?), and falls through when a6(=0x400166b) == t8(?).
  The `beq` branch at 0x7284 targets 0x7240 and is always taken.
  The `beq` branch at 0x7294 targets 0x7308 and is always taken.
  The `beq` branch at 0x72a0 targets 0x7304, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `beq` branch at 0x72c0 targets 0x7304, is taken when t9(?) == v0(=one of 0x0, 0x1), and falls through when t9(?) != v0(=one of 0x0, 0x1).
  The `beq` branch at 0x7304 targets 0x737c, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `beq` branch at 0x732c targets 0x7350, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `bne` branch at 0x7334 targets 0x72a0, is taken when a7(=one of 0x0, 0x1) != 0, and falls through when a7(=one of 0x0, 0x1) == 0.
  The `bne` branch at 0x733c targets 0x72a0, is taken when t1(=one of 0x0, 0x1) != 0, and falls through when t1(=one of 0x0, 0x1) == 0.
  The `beq` branch at 0x7348 targets 0x72a0 and is always taken.
  The `beq` branch at 0x7350 targets 0x7304, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `beq` branch at 0x736c targets 0x7304, is taken when (t0(?) & 0x100) == 0, and falls through when (t0(?) & 0x100) != 0.
  The `beq` branch at 0x7374 targets 0x72c8 and is always taken.
  The `bne` branch at 0x737c targets 0x7390, is taken when a7(=one of 0x0, 0x1) != 0, and falls through when a7(=one of 0x0, 0x1) == 0.
  The `beq` branch at 0x7384 targets 0x7464, is taken when t1(=one of 0x0, 0x1) == 0, and falls through when t1(=one of 0x0, 0x1) != 0.
  The `bne` branch at 0x7398 targets 0x724c, is taken when t1(=one of 0x0, 0x1) != 0, and falls through when t1(=one of 0x0, 0x1) == 0.
  The `beq` branch at 0x73a0 targets 0x7294 and is always taken.
  The `beq` branch at 0x73a8 targets 0x7428, is taken when a7(=one of 0x0, 0x1) == 0, and falls through when a7(=one of 0x0, 0x1) != 0.
  The `bne` branch at 0x73c0 targets 0x7228, is taken when a4(=0xacfd8f) != t8(?), and falls through when a4(=0xacfd8f) == t8(?).
  The `bne` branch at 0x73cc targets 0x7228, is taken when t9(=0x4001693) != t8(?), and falls through when t9(=0x4001693) == t8(?).
  The `beq` branch at 0x73d4 targets 0x7240 and is always taken.
  The `beq` branch at 0x73e0 targets 0x7290 and is always taken.
  The `beq` branch at 0x73e8 targets 0x7428, is taken when a7(=one of 0x0, 0x1) == 0, and falls through when a7(=one of 0x0, 0x1) != 0.
  The `bne` branch at 0x7404 targets 0x7228, is taken when a4(=0x39ff83) != at(?), and falls through when a4(=0x39ff83) == at(?).
  The `bne` branch at 0x7418 targets 0x7228, is taken when t8(=0x8001892) != at(?), and falls through when t8(=0x8001892) == at(?).
  The `beq` branch at 0x7420 targets 0x7240 and is always taken.
  The `bne` branch at 0x7434 targets 0x7228, is taken when at(?) != a4(?), and falls through when at(?) == a4(?).
  The `beq` branch at 0x7440 targets 0x7240, is taken when t8(?) == a5(?), and falls through when t8(?) != a5(?).
  The `beq` branch at 0x7448 targets 0x722c and is always taken.
  The `bne` branch at 0x7454 targets 0x7228, is taken when t3(=0x8001866) != at(?), and falls through when t3(=0x8001866) == at(?).
  The `beq` branch at 0x745c targets 0x7240 and is always taken.
  The `beq` branch at 0x7464 targets 0x7390 and is always taken.
  The return at 0x7390 has v0 = one of 0x0, 0x1.
  The instructions from 0x729c to 0x729c are not reached by any path from the entry, and their branches are not listed.

- `kdsp_idbg_rad_dump_subsys` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x746c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x746c-0x76a4 (568 bytes).
  It occupies 568 bytes.
  The `lw` at 0x746c loads 4 bytes from a0 (arg0 at entry) +0x230.
  The `lw` at 0x7490 loads 4 bytes from a0 (arg0 at entry) +0x24c.
  The `lw` at 0x7494 loads 4 bytes from a0 (arg0 at entry) +0x248.
  The `lw` at 0x74a0 loads 4 bytes from a0 (arg0 at entry) +0x254.
  The `lw` at 0x74a4 loads 4 bytes from a0 (arg0 at entry) +0x250.
  The `lw` at 0x74b0 loads 4 bytes from a0 (arg0 at entry) +0x25c.
  The `lw` at 0x74b4 loads 4 bytes from a0 (arg0 at entry) +0x258.
  The `lw` at 0x74c0 loads 4 bytes from a0 (arg0 at entry) +0x264.
  The `lw` at 0x74c4 loads 4 bytes from a0 (arg0 at entry) +0x260.
  The `lw` at 0x74d0 loads 4 bytes from a0 (arg0 at entry) +0x26c.
  The `lw` at 0x74d4 loads 4 bytes from a0 (arg0 at entry) +0x268.
  The `lw` at 0x74e0 loads 4 bytes from a0 (arg0 at entry) +0x274.
  The `lw` at 0x74e4 loads 4 bytes from a0 (arg0 at entry) +0x270.
  The `lw` at 0x74f0 loads 4 bytes from a0 (arg0 at entry) +0x27c.
  The `lw` at 0x74f4 loads 4 bytes from a0 (arg0 at entry) +0x278.
  The `lw` at 0x7500 loads 4 bytes from a0 (arg0 at entry) +0x284.
  The `lw` at 0x7504 loads 4 bytes from a0 (arg0 at entry) +0x280.
  The `lw` at 0x7510 loads 4 bytes from a0 (arg0 at entry) +0x288.
  The `lw` at 0x751c loads 4 bytes from a0 (arg0 at entry) +0x290.
  The `lw` at 0x7520 loads 4 bytes from a0 (arg0 at entry) +0x28c.
  The `lw` at 0x752c loads 4 bytes from a0 (arg0 at entry) +0x298.
  The `lw` at 0x7530 loads 4 bytes from a0 (arg0 at entry) +0x294.
  The `lw` at 0x753c loads 4 bytes from a0 (arg0 at entry) +0x2a0.
  The `lw` at 0x7540 loads 4 bytes from a0 (arg0 at entry) +0x29c.
  The `lw` at 0x754c loads 4 bytes from a0 (arg0 at entry) +0x2a8.
  The `lw` at 0x7550 loads 4 bytes from a0 (arg0 at entry) +0x2a4.
  The `lw` at 0x755c loads 4 bytes from a0 (arg0 at entry) +0x2b0.
  The `lw` at 0x7560 loads 4 bytes from a0 (arg0 at entry) +0x2ac.
  The `lw` at 0x756c loads 4 bytes from a0 (arg0 at entry) +0x2b8.
  The `lw` at 0x7570 loads 4 bytes from a0 (arg0 at entry) +0x2b4.
  The `lw` at 0x757c loads 4 bytes from a0 (arg0 at entry) +0x2c4.
  The `lw` at 0x7580 loads 4 bytes from a0 (arg0 at entry) +0x2c0.
  The `lw` at 0x7584 loads 4 bytes from a0 (arg0 at entry) +0x2bc.
  The `lw` at 0x7598 loads 4 bytes from a0 (arg0 at entry) +0x7248.
  The `lw` at 0x759c loads 4 bytes from a0 (arg0 at entry) +0x724c.
  The `lw` at 0x75a8 loads 4 bytes from a0 (arg0 at entry) +0x7258.
  The `lw` at 0x75ac loads 4 bytes from a0 (arg0 at entry) +0x7250.
  The `lw` at 0x75b8 loads 4 bytes from a0 (arg0 at entry) +0x725c.
  The `lw` at 0x75bc loads 4 bytes from a0 (arg0 at entry) +0x7254.
  The `lw` at 0x75c8 loads 4 bytes from a0 (arg0 at entry) +0x7240.
  The `lw` at 0x75cc loads 4 bytes from a0 (arg0 at entry) +0x7244.
  The `lw` at 0x75d8 loads 4 bytes from a0 (arg0 at entry) +0x7284.
  The `lw` at 0x75dc loads 4 bytes from a0 (arg0 at entry) +0x7280.
  The `lw` at 0x75e0 loads 4 bytes from a0 (arg0 at entry) +0x727c.
  The `lw` at 0x75e4 loads 4 bytes from a0 (arg0 at entry) +0x7278.
  The `lw` at 0x75f0 loads 4 bytes from a0 (arg0 at entry) +0x7294.
  The `lw` at 0x75f4 loads 4 bytes from a0 (arg0 at entry) +0x7290.
  The `lw` at 0x75f8 loads 4 bytes from a0 (arg0 at entry) +0x728c.
  The `lw` at 0x75fc loads 4 bytes from a0 (arg0 at entry) +0x7288.
  The `lw` at 0x7608 loads 4 bytes from a0 (arg0 at entry) +0x729c.
  The `lw` at 0x760c loads 4 bytes from a0 (arg0 at entry) +0x7298.
  The `lw` at 0x7610 loads 4 bytes from a0 (arg0 at entry) +0x72a4.
  The `lw` at 0x7614 loads 4 bytes from a0 (arg0 at entry) +0x72a0.
  The `lw` at 0x7620 loads 4 bytes from a0 (arg0 at entry) +0x7270.
  The `lw` at 0x7624 loads 4 bytes from a0 (arg0 at entry) +0x726c.
  The `lw` at 0x7628 loads 4 bytes from a0 (arg0 at entry) +0x7268.
  The `lw` at 0x762c loads 4 bytes from a0 (arg0 at entry) +0x7264.
  The `lw` at 0x7630 loads 4 bytes from a0 (arg0 at entry) +0x7274.
  The `lw` at 0x763c loads 4 bytes from a0 (arg0 at entry) +0x72d8.
  The `lw` at 0x7640 loads 4 bytes from a0 (arg0 at entry) +0x72d4.
  The `lw` at 0x7644 loads 4 bytes from a0 (arg0 at entry) +0x72d0.
  The `lw` at 0x7648 loads 4 bytes from a0 (arg0 at entry) +0x72cc.
  The `ld` at 0x7654 loads 8 bytes from a0 (arg0 at entry) +0x72e0.
  The `ld` at 0x7658 loads 8 bytes from a0 (arg0 at entry) +0x72e8.
  The `lw` at 0x765c loads 4 bytes from a0 (arg0 at entry) +0x72f0.
  The `lbu` at 0x7668 loads 1 byte from a0 (arg0 at entry) +0x7309.
  The `lbu` at 0x766c loads 1 byte from a0 (arg0 at entry) +0x7303.
  The `jal` at 0x7488 calls qprintf with a0=sym(.rodata), a1=[a0+560], a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x7498 calls qprintf with a0=sym(.rodata), a1=[a0+584], a2=[a0+588], a3=?.
  The `jal` at 0x74a8 calls qprintf with a0=sym(.rodata), a1=[a0+592], a2=[a0+596], a3=?.
  The `jal` at 0x74b8 calls qprintf with a0=sym(.rodata), a1=[a0+600], a2=[a0+604], a3=?.
  The `jal` at 0x74c8 calls qprintf with a0=sym(.rodata), a1=[a0+608], a2=[a0+612], a3=?.
  The `jal` at 0x74d8 calls qprintf with a0=sym(.rodata), a1=[a0+616], a2=[a0+620], a3=?.
  The `jal` at 0x74e8 calls qprintf with a0=sym(.rodata), a1=[a0+624], a2=[a0+628], a3=?.
  The `jal` at 0x74f8 calls qprintf with a0=sym(.rodata), a1=[a0+632], a2=[a0+636], a3=?.
  The `jal` at 0x7508 calls qprintf with a0=sym(.rodata), a1=[a0+640], a2=[a0+644], a3=?.
  The `jal` at 0x7514 calls qprintf with a0=sym(.rodata), a1=[a0+648], a2=?, a3=?.
  The `jal` at 0x7524 calls qprintf with a0=sym(.rodata), a1=[a0+652], a2=[a0+656], a3=?.
  The `jal` at 0x7534 calls qprintf with a0=sym(.rodata), a1=[a0+660], a2=[a0+664], a3=?.
  The `jal` at 0x7544 calls qprintf with a0=sym(.rodata), a1=[a0+668], a2=[a0+672], a3=?.
  The `jal` at 0x7554 calls qprintf with a0=sym(.rodata), a1=[a0+676], a2=[a0+680], a3=?.
  The `jal` at 0x7564 calls qprintf with a0=sym(.rodata), a1=[a0+684], a2=[a0+688], a3=?.
  The `jal` at 0x7574 calls qprintf with a0=sym(.rodata), a1=[a0+692], a2=[a0+696], a3=?.
  The `jal` at 0x7588 calls qprintf with a0=sym(.rodata), a1=[a0+700], a2=[a0+704], a3=[a0+708].
  The `jal` at 0x7590 calls qprintf with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jal` at 0x75a0 calls qprintf with a0=sym(.rodata), a1=[a0+29260], a2=[a0+29256], a3=?.
  The `jal` at 0x75b0 calls qprintf with a0=sym(.rodata), a1=[a0+29264], a2=[a0+29272], a3=?.
  The `jal` at 0x75c0 calls qprintf with a0=sym(.rodata), a1=[a0+29268], a2=[a0+29276], a3=?.
  The `jal` at 0x75d0 calls qprintf with a0=sym(.rodata), a1=[a0+29252], a2=[a0+29248], a3=?.
  The `jal` at 0x75e8 calls qprintf with a0=sym(.rodata), a1=[a0+29304], a2=[a0+29308], a3=[a0+29312], a4=[a0+29316].
  The `jal` at 0x7600 calls qprintf with a0=sym(.rodata), a1=[a0+29320], a2=[a0+29324], a3=[a0+29328], a4=[a0+29332].
  The `jal` at 0x7618 calls qprintf with a0=sym(.rodata), a1=[a0+29344], a2=[a0+29348], a3=[a0+29336], a4=[a0+29340].
  The `jal` at 0x7634 calls qprintf with a0=sym(.rodata), a1=[a0+29300], a2=[a0+29284], a3=[a0+29288], a4=[a0+29292], a5=[a0+29296].
  The `jal` at 0x764c calls qprintf with a0=sym(.rodata), a1=[a0+29388], a2=[a0+29392], a3=[a0+29396], a4=[a0+29400].
  The `jal` at 0x7660 calls qprintf with a0=sym(.rodata), a1=[a0+29424], a2=[a0+29416]:8, a3=[a0+29408]:8.
  The `jal` at 0x7670 calls qprintf with a0=sym(.rodata), a1=[a0+29443]:1, a2=[a0+29449]:1, a3=?.
  The `jal` at 0x767c calls qprintf with a0=sym(.rodata), a1=a0+29000, a2=?, a3=?.
  The `jal` at 0x7688 calls qprintf with a0=sym(.rodata), a1=a0+29144, a2=?, a3=?.
  The return at 0x769c has v0 = ret(qprintf).

- `kdsp_idbg_rad_dump_cg` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x76a4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x76a4-0x771c (120 bytes).
  It occupies 120 bytes.
  The `ld` at 0x76cc loads 8 bytes from a0 (arg0 at entry) +0x200.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x1f0, including `ld` at 0x76d0, `ld` at 0x76dc.
  The `lw` at 0x76f4 loads 4 bytes from a0 (arg0 at entry) +0x220.
  The `lw` at 0x76f8 loads 4 bytes from a0 (arg0 at entry) +0x20c.
  The `lw` at 0x7708 loads 4 bytes from a0 (arg0 at entry) +0x208.
  The `jal` at 0x76b8 calls qprintf with a0=sym(.rodata), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x76c0 calls kdsp_idbg_dump_clockgen with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x76d4 calls qprintf with a0=sym(.rodata), a1=[a0+496]:8, a2=[a0+512]:8, a3=?.
  The `jal` at 0x7704 calls qprintf with a0=sym(.rodata), a1=?, a2=[a0+520], a3=[a0+524], a4=[a0+544].
  The return at 0x7714 has v0 = ret(qprintf).

- `kdsp_idbg_rad_dump_device` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x771c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x771c-0x778c (112 bytes).
  It occupies 112 bytes.
  The `lw` at 0x7740 loads 4 bytes from a0 (arg0 at entry) +0x2c4.
  The `lw` at 0x7748 loads 4 bytes from a0 (arg0 at entry) +0x2c0.
  The `ld` at 0x7754 loads 8 bytes from a0 (arg0 at entry) +0x300.
  The `ld` at 0x7758 loads 8 bytes from a0 (arg0 at entry) +0x2f8.
  The `lw` at 0x7764 loads 4 bytes from a0 (arg0 at entry) +0x314.
  The `lw` at 0x7768 loads 4 bytes from a0 (arg0 at entry) +0x310.
  The `ld` at 0x776c loads 8 bytes from a0 (arg0 at entry) +0x308.
  The `jal` at 0x772c calls kdsp_idbg_dump_device with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x7738 calls qprintf with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jal` at 0x774c calls qprintf with a0=sym(.rodata), a1=[a0+704], a2=[a0+708], a3=[a0+708].
  The `jal` at 0x775c calls qprintf with a0=sym(.rodata), a1=[a0+760]:8, a2=[a0+768]:8, a3=?.
  The `jal` at 0x7770 calls qprintf with a0=sym(.rodata), a1=[a0+776]:8, a2=[a0+784], a3=[a0+788].
  The return at 0x7784 has v0 = ret(qprintf).

- `kdsp_idbg_rad_addfuncs` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x778c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x778c-0x7818 (140 bytes).
  It occupies 140 bytes.
  The `jal` at 0x77c0 calls idbg_addfunc with a0=sym(.rodata), a1=sym(kdsp_idbg_rad_dump_subsys), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x77dc calls idbg_addfunc with a0=sym(.rodata), a1=sym(kdsp_idbg_rad_dump_device), a2=?, a3=?.
  The `jal` at 0x77f8 calls idbg_addfunc with a0=sym(.rodata), a1=sym(kdsp_idbg_rad_dump_cg), a2=?, a3=?.
  The `bne` branch at 0x77a0 targets 0x77b8, is taken when v0(=[sym(.sdata)+52]) < 0x1 (signed), and falls through when v0(=[sym(.sdata)+52]) >= 0x1 (signed).
  The `beq` branch at 0x77c8 targets 0x77d8, is taken when v0(=ret(idbg_addfunc)) == 0, and falls through when v0(=ret(idbg_addfunc)) != 0.
  The `beq` branch at 0x77d0 targets 0x77b0 and is always taken.
  The `beq` branch at 0x77e4 targets 0x77f4, is taken when v0(=ret(idbg_addfunc)) == 0, and falls through when v0(=ret(idbg_addfunc)) != 0.
  The `beq` branch at 0x77ec targets 0x77b0 and is always taken.
  The `beq` branch at 0x7800 targets 0x7810, is taken when v0(=ret(idbg_addfunc)) == 0, and falls through when v0(=ret(idbg_addfunc)) != 0.
  The `beq` branch at 0x7808 targets 0x77b0 and is always taken.
  The `beq` branch at 0x7810 targets 0x77ac and is always taken.
  The return at 0x77b0 has v0 = one of 0x0, ret(idbg_addfunc).

- `kdsp_idbg_rad_delfuncs` in `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o` at 0x7818 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/rad_dd.o`.
  Range: 0x7818-0x7858 (64 bytes).
  It occupies 64 bytes.
  The `jal` at 0x7838 calls idbg_delfunc with a0=sym(kdsp_idbg_rad_dump_subsys), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x7840 calls idbg_delfunc with a0=sym(kdsp_idbg_rad_dump_cg), a1=?, a2=?, a3=?.
  The `jal` at 0x7848 calls idbg_delfunc with a0=sym(kdsp_idbg_rad_dump_device), a1=?, a2=?, a3=?.
  The `blez` branch at 0x7828 targets 0x7838, is taken when at(=[sym(.sdata)+52]-1) <= 0 (signed), and falls through when at(=[sym(.sdata)+52]-1) > 0 (signed).
  The `beq` branch at 0x7850 targets 0x7830 and is always taken.
  The return at 0x7830 has v0 = one of ?, ret(idbg_delfunc).
