# Readings: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`

One entry per routine, filed here from the reading batches by binary.

- `rad_ksync_notify` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x0-0x8 (8 bytes).
  It occupies 8 bytes.
  The return at 0x0 has v0 = ?.

- `rad_create_subsys` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
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

- `rad_open` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x1d8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x1d8-0x1e0 (8 bytes).
  It occupies 8 bytes.
  The return at 0x1d8 has v0 = 0x0.

- `rad_ioctl` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x1e0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x1e0-0x878 (1688 bytes).
  It occupies 1688 bytes.
  The `sw` at 0x258 stores 4 bytes to a5 (arg5 at entry) +0x0.
  5 such `lh` accesses load 2 bytes from ret(hwgraph_fastinfo_get) +0x21a, including `lh` at 0x290, `lh` at 0x350, `lh` at 0x43c.
  The `lbu` at 0x2b4 loads 1 byte from ?.
  The `sw` at 0x2bc stores 4 bytes to ?.
  2 such `lw` accesses load 4 bytes from ret(hwgraph_fastinfo_get) +0x7274, including `lw` at 0x2f0, `lw` at 0x370.
  6 such `sw` accesses store 4 bytes to ret(hwgraph_fastinfo_get) +0x7318, including `sw` at 0x35c, `sw` at 0x580, `sw` at 0x6e0.
  The `sw` at 0x390 stores 4 bytes to ret(hwgraph_fastinfo_get) +0x7274.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0x3c8, `ld` at 0x700.
  The `ll` at 0x3dc loads 4 bytes from sym(fastick_callback_required_flags) +0x0.
  The `sc` at 0x3e4 stores 4 bytes to sym(fastick_callback_required_flags) +0x0.
  The `lw` at 0x40c loads 4 bytes from ret(hwgraph_fastinfo_get) +0x2cc.
  The `lw` at 0x41c loads 4 bytes from ret(hwgraph_fastinfo_get) +0x2d0.
  The `sw` at 0x468 stores 4 bytes to ret(hwgraph_fastinfo_get) +0x2d0.
  The `sw` at 0x46c stores 4 bytes to ret(hwgraph_fastinfo_get) +0x2cc.
  The `sb` at 0x470 stores 1 byte to ret(hwgraph_fastinfo_get) +0x7303.
  The `lw` at 0x598 loads 4 bytes from ret(hwgraph_fastinfo_get) +0x731c.
  The `ld` at 0x5bc loads 8 bytes from ret(hwgraph_fastinfo_get) +0x228.
  The `ld` at 0x620 loads 8 bytes from ret(hwgraph_fastinfo_get) +0x220.
  The `lw` at 0x710 loads 4 bytes from ret(hwgraph_fastinfo_get) +0x7318.
  The `sb` at 0x7f4 stores 1 byte to ret(strchr) +0x0.
  The `jal` at 0x208 calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x2c8 calls copyout with a0=sp-128, a1=a2 at entry (arg2), a2=0x14, a3=?, a5=[ret(hwgraph_fastinfo_get)+538]:2.
  The `jal` at 0x2f8 calls copyout with a0=sp-104, a1=a2 at entry (arg2), a2=0x4, a3=?.
  The `jal` at 0x32c calls copyin with a0=a2 at entry (arg2), a1=sp-136, a2=0x4, a3=?.
  The `jal` at 0x38c calls rad_vl_write_MUX_SEL with a0=ret(hwgraph_fastinfo_get), a1=?, a2=?, a3=-0x201, a4=[ret(hwgraph_fastinfo_get)+538]:2.
  The `jal` at 0x3b8 calls strncmp with a0=?, a1=sym(.rodata), a2=0x3, a3=?.
  The `jal` at 0x3fc calls update_ust with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x404 calls get_ust_nano with a0=sp-560, a1=?, a2=?, a3=?.
  The `jal` at 0x424 calls copyout with a0=sp-560, a1=a2 at entry (arg2), a2=0x18, a3=?, a6=[ret(hwgraph_fastinfo_get)+720], a7=[ret(hwgraph_fastinfo_get)+716].
  The `jal` at 0x47c calls curproc_abi with a0=0x6b730002, a1=?, a2=0x6d680000, a3=?.
  The `jal` at 0x49c calls copyin_xlate with a0=a2 at entry (arg2), a1=sp-536, a2=0x44, a3=sym(irix5_to_kstat_t), a4=ret(curproc_abi), a5=0x4, a6=0x1.
  The `jal` at 0x4b4 calls device_controller_num_get with a0=a0 at entry (arg0), a1=?, a2=0x6d687767, a3=?.
  The `jal` at 0x4d4 calls sprintf with a0=ret(hwgraph_fastinfo_get)+300, a1=sym(.rodata), a2=ret(device_controller_num_get), a3=?.
  The `jal` at 0x4e8 calls sprintf with a0=ret(hwgraph_fastinfo_get)+332, a1=sym(.rodata), a2=ret(device_controller_num_get), a3=?.
  The `jal` at 0x520 calls kdsp_set_default_subsys_pri with a0=ret(hwgraph_fastinfo_get), a1=ret(device_controller_num_get)+100, a2=one of 0x7, 0xd, a3=?, a4=[ret(hwgraph_fastinfo_get)+538]:2.
  The `jal` at 0x544 calls kdsp_set_default_subsys_pri with a0=ret(hwgraph_fastinfo_get), a1=ret(device_controller_num_get), a2=0x7, a3=?, a4=[ret(hwgraph_fastinfo_get)+538]:2.
  The `jal` at 0x558 calls sprintf with a0=sp-464, a1=sym(.rodata), a2=ret(device_controller_num_get), a3=?.
  The `jal` at 0x590 calls hwgraph_path_add with a0=[sym(hwgraph_root)], a1=sym(.rodata), a2=sp-432, a3=one of 0x4, 0x7.
  The `jal` at 0x5a4 calls hwgraph_edge_add with a0=?, a1=[ret(hwgraph_fastinfo_get)+29468], a2=ret(hwgraph_fastinfo_get)+300, a3=?.
  The `jal` at 0x5c0 calls sprintf with a0=sp-424, a1=sym(.rodata), a2=[ret(hwgraph_fastinfo_get)+552]:8, a3=?.
  The `jal` at 0x5c8 calls strlen with a0=sp-424, a1=?, a2=?, a3=?.
  The `jal` at 0x5d4 calls kern_malloc with a0=ret(strlen)+1, a1=?, a2=?, a3=?.
  The `jal` at 0x5e8 calls strcpy with a0=ret(kern_malloc), a1=sp-424, a2=?, a3=?.
  The `jal` at 0x5fc calls hwgraph_info_add_LBL with a0=[ret(hwgraph_fastinfo_get)+29468], a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x610 calls hwgraph_info_export_LBL with a0=[ret(hwgraph_fastinfo_get)+29468], a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x624 calls sprintf with a0=sp-424, a1=sym(.rodata), a2=[ret(hwgraph_fastinfo_get)+544]:8, a3=?.
  The `jal` at 0x62c calls strlen with a0=sp-424, a1=?, a2=?, a3=?.
  The `jal` at 0x638 calls kern_malloc with a0=ret(strlen)+1, a1=?, a2=?, a3=?.
  The `jal` at 0x648 calls strcpy with a0=ret(kern_malloc), a1=sp-424, a2=?, a3=?.
  The `jal` at 0x658 calls hwgraph_info_add_LBL with a0=[ret(hwgraph_fastinfo_get)+29468], a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x668 calls hwgraph_info_export_LBL with a0=[ret(hwgraph_fastinfo_get)+29468], a1=sym(.rodata), a2=(ret(strlen)+1 << 0x0), a3=?.
  The `jal` at 0x670 calls strlen with a0=ret(hwgraph_fastinfo_get)+300, a1=?, a2=?, a3=?.
  The `jal` at 0x67c calls kern_malloc with a0=ret(strlen)+1, a1=?, a2=?, a3=?.
  The `jal` at 0x68c calls strcpy with a0=ret(kern_malloc), a1=ret(hwgraph_fastinfo_get)+300, a2=?, a3=?.
  The `jal` at 0x69c calls hwgraph_info_add_LBL with a0=[ret(hwgraph_fastinfo_get)+29468], a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x6ac calls hwgraph_info_export_LBL with a0=[ret(hwgraph_fastinfo_get)+29468], a1=sym(.rodata), a2=(ret(strlen)+1 << 0x0), a3=?.
  The `jal` at 0x6bc calls hwgraph_edge_get with a0=[ret(hwgraph_fastinfo_get)+29468], a1=sym(.rodata), a2=sp-400, a3=?.
  The `jal` at 0x6f4 calls rad_stop_status_dma with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x708 calls sprintf with a0=sp-536, a1=ret(hwgraph_fastinfo_get)+300, a2=?, a3=?.
  The `jal` at 0x714 calls curproc_abi with a0=?, a1=?, a2=?, a3=?, a4=[ret(hwgraph_fastinfo_get)+29464].
  The `jal` at 0x734 calls xlate_copyout with a0=sp-536, a1=a2 at entry (arg2), a2=0x44, a3=sym(kstat_t_to_irix5), a4=ret(curproc_abi), a5=0x4, a6=0x1.
  The `jal` at 0x74c calls rad_vl_write_MUX_SEL with a0=ret(hwgraph_fastinfo_get), a1=(a2 << 0x0), a2=?, a3=?.
  The `jal` at 0x764 calls hwgraph_vertex_name_get with a0=?, a1=sp-392, a2=0x100, a3=?.
  The `jal` at 0x77c calls strstr with a0=sp-392, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x79c calls ksync_attach with a0=?, a1=sp-464, a2=?, a3=sym(rad_ksync_notify).
  The `jal` at 0x7e4 calls strchr with a0=ret(strstr)+7, a1=0x2f, a2=?, a3=?, a4=-0x1.
  The `jal` at 0x7f8 calls parse_module_id with a0=ret(strstr)+7, a1=?, a2=?, a3=?.
  The `jal` at 0x820 calls cmn_err with a0=0x4, a1=sym(.rodata), a2=a0 at entry (arg0), a3=?.
  The `jal` at 0x840 calls cmn_err with a0=0x4, a1=sym(.rodata), a2=a0 at entry (arg0), a3=ret(device_controller_num_get).
  The `jal` at 0x850 calls cmn_err with a0=0x1, a1=sym(.rodata), a2=[sym(showconfig)], a3=?.
  The `jal` at 0x868 calls cmn_err with a0=0x1, a1=sym(.rodata), a2=?, a3=?.
  The `beq` branch at 0x210 targets 0x814, is taken when v0(=ret(hwgraph_fastinfo_get)) == 0, and falls through when v0(=ret(hwgraph_fastinfo_get)) != 0.
  The `bne` branch at 0x21c targets 0x278, is taken when s1(=a1) < 0x270c (signed), and falls through when s1(=a1) >= 0x270c (signed).
  The `bne` branch at 0x224 targets 0x3fc, is taken when v0(?) != 0, and falls through when v0(?) == 0.
  The `bne` branch at 0x234 targets 0x308, is taken when s1(=a1) < a0(=0x6b730002) (signed), and falls through when s1(=a1) >= a0(=0x6b730002) (signed).
  The `beq` branch at 0x23c targets 0x47c, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x248 targets 0x4b4, is taken when s1(=a1) == a2(=0x6d687767), and falls through when s1(=a1) != a2(=0x6d687767).
  The `bne` branch at 0x27c targets 0x2d8, is taken when s1(=a1) < 0x270a (signed), and falls through when s1(=a1) >= 0x270a (signed).
  The `beq` branch at 0x288 targets 0x460, is taken when s1(=a1) >= 0x270b (signed), and falls through when s1(=a1) < 0x270b (signed).
  The `bne` branch at 0x2b8 targets 0x2a0, is taken when v0(?) < 0x4 (signed), and falls through when v0(?) >= 0x4 (signed).
  The `beq` branch at 0x2d0 targets 0x250 and is always taken.
  The `bne` branch at 0x2d8 targets 0x39c, is taken when t0(?) != 0, and falls through when t0(?) == 0.
  The `beq` branch at 0x2e0 targets 0x250, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x300 targets 0x250 and is always taken.
  The `bne` branch at 0x310 targets 0x434, is taken when s1(=a1) < a0(=0x6b730001) (signed), and falls through when s1(=a1) >= a0(=0x6b730001) (signed).
  The `bne` branch at 0x31c targets 0x250, is taken when a0(=0x6b730001) < s1(=a1) (signed), and falls through when a0(=0x6b730001) >= s1(=a1) (signed).
  The `bne` branch at 0x338 targets 0x250, is taken when v0(=ret(copyin)) != 0, and falls through when v0(=ret(copyin)) == 0.
  The `beq` branch at 0x34c targets 0x7b4, is taken when t8(?) == a3(=0x1), and falls through when t8(?) != a3(=0x1).
  The `beq` branch at 0x354 targets 0x7d0, is taken when a4(=[ret(hwgraph_fastinfo_get)+538]:2) == v0(=0xc), and falls through when a4(=[ret(hwgraph_fastinfo_get)+538]:2) != v0(=0xc).
  The `bne` branch at 0x364 targets 0x250, is taken when a4(=[ret(hwgraph_fastinfo_get)+538]:2) != ra(=0xd), and falls through when a4(=[ret(hwgraph_fastinfo_get)+538]:2) == ra(=0xd).
  The `beq` branch at 0x394 targets 0x254 and is always taken.
  The `bne` branch at 0x39c targets 0x24c, is taken when s1(=a1) != a2(=0x2708), and falls through when s1(=a1) == a2(=0x2708).
  The `beq` branch at 0x3a4 targets 0x3d4, is taken when a3(=[sym(kdsp_sstab)]:8) == 0, and falls through when a3(=[sym(kdsp_sstab)]:8) != 0.
  The `beq` branch at 0x3c0 targets 0x6f4, is taken when v0(=ret(strncmp)) == 0, and falls through when v0(=ret(strncmp)) != 0.
  The `bne` branch at 0x3cc targets 0x3b0, is taken when s0(?) != 0, and falls through when s0(?) == 0.
  The `beql` branch at 0x3e8 targets 0x3dc, is taken when (a2(=[sym(fastick_callback_required_flags)]) & a4(=-0x3)) == 0, and falls through when (a2(=[sym(fastick_callback_required_flags)]) & a4(=-0x3)) != 0; its branch-likely delay slot `nop` at 0x3ec runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x3f4 targets 0x250 and is always taken.
  The `beq` branch at 0x42c targets 0x250 and is always taken.
  The `bne` branch at 0x434 targets 0x250, is taken when s1(=a1) != t0(=0x270d), and falls through when s1(=a1) == t0(=0x270d).
  The `beq` branch at 0x444 targets 0x74c, is taken when v0(=[ret(hwgraph_fastinfo_get)+538]:2) == t1(=0x7), and falls through when v0(=[ret(hwgraph_fastinfo_get)+538]:2) != t1(=0x7).
  The `beq` branch at 0x450 targets 0x74c, is taken when v0(=[ret(hwgraph_fastinfo_get)+538]:2) == t2(=0xd), and falls through when v0(=[ret(hwgraph_fastinfo_get)+538]:2) != t2(=0xd).
  The `beq` branch at 0x458 targets 0x250 and is always taken.
  The `bne` branch at 0x460 targets 0x250, is taken when s1(=a1) != t3(=0x270b), and falls through when s1(=a1) == t3(=0x270b).
  The `beq` branch at 0x474 targets 0x250 and is always taken.
  The `beq` branch at 0x4a4 targets 0x704, is taken when v0(=ret(copyin_xlate)) == 0, and falls through when v0(=ret(copyin_xlate)) != 0.
  The `beq` branch at 0x4ac targets 0x250 and is always taken.
  The `bltz` branch at 0x4bc targets 0x830, is taken when v0(=ret(device_controller_num_get)) < 0 (signed), and falls through when v0(=ret(device_controller_num_get)) >= 0 (signed).
  The `beq` branch at 0x4f8 targets 0x520, is taken when a4(=[ret(hwgraph_fastinfo_get)+538]:2) == a2(=0xd), and falls through when a4(=[ret(hwgraph_fastinfo_get)+538]:2) != a2(=0xd).
  The `bne` branch at 0x504 targets 0x530, is taken when a4(=[ret(hwgraph_fastinfo_get)+538]:2) != a2(=0x7), and falls through when a4(=[ret(hwgraph_fastinfo_get)+538]:2) == a2(=0x7).
  The `beq` branch at 0x50c targets 0x534, is taken when v0(=[sym(.sbss)+8]) == 0, and falls through when v0(=[sym(.sbss)+8]) != 0.
  The `beq` branch at 0x514 targets 0x534, is taken when s1(=ret(device_controller_num_get)) == v0(=[sym(.sbss)+8]), and falls through when s1(=ret(device_controller_num_get)) != v0(=[sym(.sbss)+8]).
  The `beq` branch at 0x528 targets 0x550 and is always taken.
  The `beq` branch at 0x568 targets 0x6e0, is taken when a4(=[ret(hwgraph_fastinfo_get)+538]:2) == a2(=0xc), and falls through when a4(=[ret(hwgraph_fastinfo_get)+538]:2) != a2(=0xc).
  The `beq` branch at 0x574 targets 0x6dc, is taken when a4(=[ret(hwgraph_fastinfo_get)+538]:2) == a3(=0x7), and falls through when a4(=[ret(hwgraph_fastinfo_get)+538]:2) != a3(=0x7).
  The `beq` branch at 0x5b0 targets 0x6ec, is taken when v0(=ret(hwgraph_edge_add)) == a2(=0x1), and falls through when v0(=ret(hwgraph_edge_add)) != a2(=0x1).
  The `beq` branch at 0x6c4 targets 0x75c, is taken when v0(=ret(hwgraph_edge_get)) == 0, and falls through when v0(=ret(hwgraph_edge_get)) != 0.
  The `bne` branch at 0x6cc targets 0x850, is taken when a2(=[sym(showconfig)]) != 0, and falls through when a2(=[sym(showconfig)]) == 0.
  The `beq` branch at 0x6d4 targets 0x250 and is always taken.
  The `beq` branch at 0x6e4 targets 0x584 and is always taken.
  The `beq` branch at 0x6ec targets 0x25c and is always taken.
  The `beq` branch at 0x6fc targets 0x3cc and is always taken.
  The `beq` branch at 0x740 targets 0x250 and is always taken.
  The `beq` branch at 0x754 targets 0x250 and is always taken.
  The `bne` branch at 0x76c targets 0x860, is taken when v0(=ret(hwgraph_vertex_name_get)) != 0, and falls through when v0(=ret(hwgraph_vertex_name_get)) == 0.
  The `bne` branch at 0x784 targets 0x7dc, is taken when v0(=ret(strstr)) != 0, and falls through when v0(=ret(strstr)) == 0.
  The `bne` branch at 0x7a4 targets 0x254, is taken when s0(?) != 0, and falls through when s0(?) == 0.
  The `beq` branch at 0x7ac targets 0x6d4 and is always taken.
  The `beq` branch at 0x7b4 targets 0x80c, is taken when a4(=[ret(hwgraph_fastinfo_get)+538]:2) == v0(=0xc), and falls through when a4(=[ret(hwgraph_fastinfo_get)+538]:2) != v0(=0xc).
  The `beq` branch at 0x7c0 targets 0x80c, is taken when a4(=[ret(hwgraph_fastinfo_get)+538]:2) == a2(=0x7), and falls through when a4(=[ret(hwgraph_fastinfo_get)+538]:2) != a2(=0x7).
  The `beq` branch at 0x7c8 targets 0x360 and is always taken.
  The `beq` branch at 0x7d4 targets 0x360 and is always taken.
  The `beq` branch at 0x7ec targets 0x7f8, is taken when v0(=ret(strchr)) == 0, and falls through when v0(=ret(strchr)) != 0.
  The `beq` branch at 0x800 targets 0x78c and is always taken.
  The `beq` branch at 0x80c targets 0x360 and is always taken.
  The `beq` branch at 0x828 targets 0x25c and is always taken.
  The `beq` branch at 0x848 targets 0x250 and is always taken.
  The `beq` branch at 0x858 targets 0x6d4 and is always taken.
  The `beq` branch at 0x870 targets 0x7a4 and is always taken.
  The return at 0x270 has v0 = one of ?, 0x0, 0x5.
  The instructions from 0x748 to 0x748 are not reached by any path from the entry, and their branches are not listed.
  The instructions from 0x808 to 0x808 are not reached by any path from the entry, and their branches are not listed.

- `rad_close` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x878 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x878-0x8cc (84 bytes).
  It occupies 84 bytes.
  The `sb` at 0x894 stores 1 byte to ret(hwgraph_fastinfo_get) +0x7303.
  The `sw` at 0x898 stores 4 bytes to ret(hwgraph_fastinfo_get) +0x2d0.
  The `sw` at 0x89c stores 4 bytes to ret(hwgraph_fastinfo_get) +0x2cc.
  The `jal` at 0x880 calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x8bc calls cmn_err with a0=0x4, a1=sym(.rodata), a2=a0 at entry (arg0), a3=ret(hwgraph_fastinfo_get), a4=0x1.
  The `beq` branch at 0x88c targets 0x8b0, is taken when v0(=ret(hwgraph_fastinfo_get)) == 0, and falls through when v0(=ret(hwgraph_fastinfo_get)) != 0.
  The `beq` branch at 0x8c4 targets 0x8a4 and is always taken.
  The return at 0x8a8 has v0 = one of 0x0, 0x5.

- `rad_start_subsys` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x8cc (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x8cc-0x1170 (2212 bytes).
  It occupies 2212 bytes.
  The `sw` at 0x8e0 stores 4 bytes to sym(.bss) +0x158.
  The `sw` at 0x8e4 stores 4 bytes to sym(.bss) +0x150.
  The `sw` at 0x8f0 stores 4 bytes to sym(.bss) +0x148.
  The `sw` at 0x8fc stores 4 bytes to sym(.bss) +0x140.
  4 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x731c, including `lw` at 0x908, `lw` at 0x91c, `lw` at 0x1144.
  35 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x228, including `ld` at 0x924, `ld` at 0x978, `ld` at 0x988.
  5 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x7240, including `sw` at 0x92c, `sw` at 0x980, `sw` at 0xa98.
  5 such `sw` accesses store 4 bytes to [a0+552]:8 +0x80, including `sw` at 0x938, `sw` at 0x984, `sw` at 0xaa4.
  4 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x7240, including `lw` at 0x93c, `lw` at 0xa88, `lw` at 0xab8.
  The `sw` at 0x994 stores 4 bytes to [a0+552]:8 +0x74.
  The `sw` at 0x9a4 stores 4 bytes to [a0+552]:8 +0x78.
  12 such `lh` accesses load 2 bytes from a0 (arg0 at entry) +0x21a, including `lh` at 0x9a8, `lh` at 0x9e8, `lh` at 0xa20.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x7248, including `sw` at 0x9bc, `sw` at 0xfb4.
  The `sw` at 0x9c4 stores 4 bytes to [a0+552]:8 +0x4c.
  The `sw` at 0x9d0 stores 4 bytes to a0 (arg0 at entry) +0x724c.
  The `sw` at 0x9d4 stores 4 bytes to [a0+552]:8 +0x58.
  The `sw` at 0x9e0 stores 4 bytes to a0 (arg0 at entry) +0x7250.
  The `sw` at 0x9e4 stores 4 bytes to [a0+552]:8 +0x48.
  The `sw` at 0xa04 stores 4 bytes to a0 (arg0 at entry) +0x7258.
  The `sw` at 0xa08 stores 4 bytes to [a0+552]:8 +0x54.
  The `sw` at 0xa18 stores 4 bytes to a0 (arg0 at entry) +0x7254.
  The `sw` at 0xa1c stores 4 bytes to [a0+552]:8 +0x44.
  The `sw` at 0xa38 stores 4 bytes to a0 (arg0 at entry) +0x725c.
  The `sw` at 0xa3c stores 4 bytes to [a0+552]:8 +0x50.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x7244, including `sw` at 0xa68, `sw` at 0xf0c.
  2 such `sw` accesses store 4 bytes to [a0+552]:8 +0x70, including `sw` at 0xa6c, `sw` at 0xf10.
  The `sw` at 0xa7c stores 4 bytes to [a0+552]:8 +0xb8.
  The `sw` at 0xa84 stores 4 bytes to [a0+552]:8 +0xbc.
  The `sw` at 0xab4 stores 4 bytes to [a0+552]:8 +0xa0.
  The `sw` at 0xb44 stores 4 bytes to a0 (arg0 at entry) +0x72c4.
  The `sw` at 0xb48 stores 4 bytes to a0 (arg0 at entry) +0x72c0.
  The `sw` at 0xb50 stores 4 bytes to a0 (arg0 at entry) +0x72b4.
  The `sw` at 0xb54 stores 4 bytes to a0 (arg0 at entry) +0x72b0.
  The `sw` at 0xb58 stores 4 bytes to a0 (arg0 at entry) +0x72bc.
  The `sw` at 0xb60 stores 4 bytes to a0 (arg0 at entry) +0x72b8.
  The `sw` at 0xb70 stores 4 bytes to a0 (arg0 at entry) +0x7260.
  The `sw` at 0xb74 stores 4 bytes to [a0+552]:8 +0x7c.
  The `sd` at 0xbc4 stores 8 bytes to a0 (arg0 at entry) +0xdb0.
  The `sd` at 0xbcc stores 8 bytes to a0 (arg0 at entry) +0xdc0.
  The `sw` at 0xbd4 stores 4 bytes to a0 (arg0 at entry) +0xfb0.
  The `sd` at 0xbe0 stores 8 bytes to a0 (arg0 at entry) +0xdb8.
  The `sd` at 0xc00 stores 8 bytes to a0 (arg0 at entry) +0xf68.
  The `sd` at 0xc1c stores 8 bytes to a0 (arg0 at entry) +0x10d8.
  The `sd` at 0xc24 stores 8 bytes to a0 (arg0 at entry) +0x10d0.
  The `sd` at 0xc2c stores 8 bytes to a0 (arg0 at entry) +0x10c8.
  The `sw` at 0xc34 stores 4 bytes to a0 (arg0 at entry) +0x12c8.
  The `sd` at 0xc3c stores 8 bytes to a0 (arg0 at entry) +0x1280.
  The `sd` at 0xc84 stores 8 bytes to a0 (arg0 at entry) +0x13e8.
  The `sd` at 0xc8c stores 8 bytes to a0 (arg0 at entry) +0x13e0.
  The `sw` at 0xc94 stores 4 bytes to a0 (arg0 at entry) +0x15e0.
  The `sd` at 0xcb4 stores 8 bytes to a0 (arg0 at entry) +0x13f0.
  The `sd` at 0xce4 stores 8 bytes to a0 (arg0 at entry) +0x1708.
  The `sd` at 0xce8 stores 8 bytes to a0 (arg0 at entry) +0x1700.
  The `sd` at 0xcf0 stores 8 bytes to a0 (arg0 at entry) +0x16f8.
  The `sw` at 0xcf8 stores 4 bytes to a0 (arg0 at entry) +0x18f8.
  The `sd` at 0xd18 stores 8 bytes to a0 (arg0 at entry) +0x18b0.
  The `sw` at 0xd38 stores 4 bytes to a0 (arg0 at entry) +0x1c10.
  The `sd` at 0xd44 stores 8 bytes to a0 (arg0 at entry) +0x1a10.
  The `sd` at 0xd50 stores 8 bytes to a0 (arg0 at entry) +0x1a20.
  The `sd` at 0xd70 stores 8 bytes to a0 (arg0 at entry) +0x1a18.
  The `sd` at 0xd90 stores 8 bytes to a0 (arg0 at entry) +0x1d38.
  The `sw` at 0xd94 stores 4 bytes to a0 (arg0 at entry) +0x1f28.
  The `sd` at 0xda4 stores 8 bytes to a0 (arg0 at entry) +0x1ee0.
  The `sd` at 0xda8 stores 8 bytes to a0 (arg0 at entry) +0x1d30.
  The `sd` at 0xdb4 stores 8 bytes to a0 (arg0 at entry) +0x1d28.
  The `ld` at 0xe64 loads 8 bytes from a0 (arg0 at entry) +0x58.
  The `ld` at 0xe98 loads 8 bytes from ?.
  2 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x1f8, including `sd` at 0xecc, `sd` at 0x1104.
  The `sd` at 0xed8 stores 8 bytes to a0 (arg0 at entry) +0x200.
  The `lw` at 0xefc loads 4 bytes from a0 (arg0 at entry) +0x7244.
  The `lbu` at 0xf20 loads 1 byte from abs 0xffffffffffffc523.
  2 such `sw` accesses store 4 bytes to [a0+552]:8 +0x40, including `sw` at 0xf3c, `sw` at 0xf50.
  The `lw` at 0xf60 loads 4 bytes from [a0+552]:8 +0x30.
  3 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x726c, including `sw` at 0xfc0, `sw` at 0x1020, `sw` at 0x1070.
  3 such `sw` accesses store 4 bytes to [a0+552]:8 +0x8c, including `sw` at 0xfc4, `sw` at 0x1024, `sw` at 0x1074.
  3 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x7270, including `sw` at 0xfe0, `sw` at 0x1014, `sw` at 0x1064.
  3 such `sw` accesses store 4 bytes to [a0+552]:8 +0x90, including `sw` at 0xfe8, `sw` at 0x1018, `sw` at 0x1068.
  3 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x7268, including `sw` at 0x102c, `sw` at 0x107c, `sw` at 0x10f4.
  3 such `sw` accesses store 4 bytes to [a0+552]:8 +0x88, including `sw` at 0x1030, `sw` at 0x1080, `sw` at 0x10fc.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x7264, including `sw` at 0x1038, `sw` at 0x1088.
  2 such `sw` accesses store 4 bytes to [a0+552]:8 +0x84, including `sw` at 0x103c, `sw` at 0x1090.
  2 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x7302, including `sb` at 0x1044, `sb` at 0x113c.
  3 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x7274, including `sw` at 0x104c, `sw` at 0x109c, `sw` at 0x1130.
  The `lw` at 0x1120 loads 4 bytes from a0 (arg0 at entry) +0x7274.
  The `jal` at 0x904 calls pciio_config_set with a0=[a0+29468], a1=0x4, a2=0x4, a3=0x6.
  The `jal` at 0x918 calls pciio_config_set with a0=[a0+29468], a1=0xc, a2=0x4, a3=-0x1.
  The `jal` at 0x934 calls us_delay with a0=0x3e8, a1=-0x1, a2=[a0+552]:8, a3=?.
  The `jal` at 0xaa0 calls us_delay with a0=0x3e8, a1=?, a2=?, a3=[a0+552]:8, a4=-0xf01, a5=0xffffffff9fffffff, a6=[a0+552]:8, a7=[a0+552]:8.
  The `jal` at 0xb00 calls us_delay with a0=0x3e8, a1=?, a2=?, a3=?.
  The `jal` at 0xb78 calls rad_init_subsys with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xbb4 calls rad_create_device with a0=a0 at entry (arg0), a1=a0+3416, a2=0x0, a3=0x400, a4=0x0, a5=sym(.rodata), a6=sym(.rodata), a7=0x2.
  The `jal` at 0xc0c calls rad_create_device with a0=a0 at entry (arg0), a1=a0+4208, a2=0x1, a3=0x400, a4=0x1, a5=sym(.rodata), a6=sym(.rodata), a7=0x2.
  The `jal` at 0xc68 calls rad_create_device with a0=a0 at entry (arg0), a1=a0+5000, a2=0x0, a3=0x400, a4=0x2, a5=sym(.rodata), a6=sym(.rodata), a7=0x2.
  The `jal` at 0xcc0 calls rad_create_device with a0=a0 at entry (arg0), a1=a0+5792, a2=0x1, a3=0x400, a4=0x3, a5=sym(.rodata), a6=sym(.rodata), a7=0x2.
  The `jal` at 0xd24 calls rad_create_device with a0=a0 at entry (arg0), a1=a0+6584, a2=0x0, a3=0x1000, a4=0x4, a5=sym(.rodata), a6=sym(.rodata), a7=0x8.
  The `jal` at 0xd7c calls rad_create_device with a0=a0 at entry (arg0), a1=a0+7376, a2=0x1, a3=0x1000, a4=0x5, a5=sym(.rodata), a6=sym(.rodata), a7=0x8.
  The `jal` at 0xdb0 calls rad_create_mclks with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xdd0 calls rad_create_clockgen with a0=a0+25688, a1=a0+3416, a2=0x0, a3=a0+1176.
  The `jal` at 0xde8 calls rad_create_clockgen with a0=a0+26240, a1=a0+4208, a2=0x1, a3=a0+1176.
  The `jal` at 0xe00 calls rad_create_clockgen with a0=a0+27896, a1=a0+5000, a2=0x4, a3=a0+2072.
  The `jal` at 0xe1c calls rad_create_clockgen with a0=a0+26792, a1=a0+5792, a2=0x2, a3=a0+1176.
  The `jal` at 0xe34 calls rad_create_clockgen with a0=a0+28448, a1=a0+6584, a2=0x5, a3=a0+1624.
  The `jal` at 0xe4c calls rad_create_clockgen with a0=a0+27344, a1=a0+7376, a2=0x3, a3=a0+1176.
  The `jal` at 0xe5c calls rad_create_ifs with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xe74 calls rad_start_device with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xea4 calls rad_create_subcodes with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xeb0 calls kdsp_map_resource with a0=a0 at entry (arg0), a1=0x0, a2=?, a3=?.
  The `jal` at 0xedc calls us_delay with a0=0xf4240, a1=(a0 + one of 0x1070, 0x16a0), a2=?, a3=?.
  The `jal` at 0xf2c calls splprof with a0=?, a1=?, a2=?, a3=?, a5=[-0x3add]:1.
  The `jal` at 0xf4c calls us_delay with a0=0xa, a1=?, a2=?, a3=?, a6=[a0+552]:8, a7=0x4.
  The `jal` at 0xf5c calls splx with a0=ret(splprof), a1=?, a2=?, a3=?.
  The `jal` at 0x1050 calls rad_vl_write_MUX_SEL with a0=a0 at entry (arg0), a1=0x0, a2=0x2, a3=[a0+552]:8, a4=[a0+552]:8, a5=[a0+552]:8, a6=[a0+552]:8, a7=[a0+552]:8.
  The `jal` at 0x1098 calls rad_vl_write_MUX_SEL with a0=a0 at entry (arg0), a1=0x0, a2=?, a3=[a0+538]:2, a4=0xfac688, a5=[a0+552]:8, a6=[a0+552]:8, a7=[a0+552]:8.
  The `jal` at 0x112c calls rad_vl_write_MUX_SEL with a0=a0 at entry (arg0), a1=([a0+29300] | 0x2000), a2=?, a3=?.
  The `jal` at 0x1148 calls cmn_err with a0=0x1, a1=sym(.rodata), a2=[a0+29468], a3=?.
  The `jal` at 0x1160 calls cmn_err with a0=0x1, a1=sym(.rodata), a2=[a0+29468], a3=?.
  The `beq` branch at 0x9b0 targets 0xfac, is taken when a3(=[a0+538]:2) == s2(=0xc), and falls through when a3(=[a0+538]:2) != s2(=0xc).
  The `beq` branch at 0xa48 targets 0x100c, is taken when v0(=[a0+538]:2) == a1(=0x7), and falls through when v0(=[a0+538]:2) != a1(=0x7).
  The `beq` branch at 0xa50 targets 0x1060, is taken when v0(=[a0+538]:2) == s1(=0xd), and falls through when v0(=[a0+538]:2) != s1(=0xd).
  The `beq` branch at 0xa58 targets 0xfd8, is taken when v0(=[a0+538]:2) == s2(=0xc), and falls through when v0(=[a0+538]:2) != s2(=0xc).
  The `beq` branch at 0xb3c targets 0xfb8, is taken when v0(=[a0+538]:2) == s2(=0xc), and falls through when v0(=[a0+538]:2) != s2(=0xc).
  The `beq` branch at 0xb5c targets 0xb78, is taken when v0(=[a0+538]:2) == s1(=0xd), and falls through when v0(=[a0+538]:2) != s1(=0xd).
  The `beq` branch at 0xb80 targets 0xffc, is taken when v0(=ret(rad_init_subsys)) == 0, and falls through when v0(=ret(rad_init_subsys)) != 0.
  The `beq` branch at 0xb8c targets 0xc40, is taken when v0(=[a0+538]:2) == s1(=0xd), and falls through when v0(=[a0+538]:2) != s1(=0xd).
  The `beq` branch at 0xbbc targets 0xf88, is taken when v0(=ret(rad_create_device)) == 0, and falls through when v0(=ret(rad_create_device)) != 0.
  The `beq` branch at 0xc14 targets 0x1004, is taken when v0(=ret(rad_create_device)) == 0, and falls through when v0(=ret(rad_create_device)) != 0.
  The `beq` branch at 0xc70 targets 0xfa4, is taken when v0(=ret(rad_create_device)) == 0, and falls through when v0(=ret(rad_create_device)) != 0.
  The `beq` branch at 0xcc8 targets 0xfd0, is taken when v0(=ret(rad_create_device)) == 0, and falls through when v0(=ret(rad_create_device)) != 0.
  The `beq` branch at 0xd2c targets 0xfec, is taken when v0(=ret(rad_create_device)) == 0, and falls through when v0(=ret(rad_create_device)) != 0.
  The `beq` branch at 0xd84 targets 0xff4, is taken when v0(=ret(rad_create_device)) == 0, and falls through when v0(=ret(rad_create_device)) != 0.
  The `beq` branch at 0xdbc targets 0xdf4, is taken when t9(=[a0+538]:2) == s1(=0xd), and falls through when t9(=[a0+538]:2) != s1(=0xd).
  The `beq` branch at 0xdd8 targets 0x10a8, is taken when v0(=ret(rad_create_clockgen)) == 0, and falls through when v0(=ret(rad_create_clockgen)) != 0.
  The `beq` branch at 0xdf0 targets 0x10b8, is taken when v0(=ret(rad_create_clockgen)) == 0, and falls through when v0(=ret(rad_create_clockgen)) != 0.
  The `beq` branch at 0xe08 targets 0x10b0, is taken when v0(=ret(rad_create_clockgen)) == 0, and falls through when v0(=ret(rad_create_clockgen)) != 0.
  The `beq` branch at 0xe24 targets 0x10c0, is taken when v0(=ret(rad_create_clockgen)) == 0, and falls through when v0(=ret(rad_create_clockgen)) != 0.
  The `beq` branch at 0xe3c targets 0x10c8, is taken when v0(=ret(rad_create_clockgen)) == 0, and falls through when v0(=ret(rad_create_clockgen)) != 0.
  The `beq` branch at 0xe54 targets 0x1110, is taken when v0(=ret(rad_create_clockgen)) == 0, and falls through when v0(=ret(rad_create_clockgen)) != 0.
  The `beq` branch at 0xe68 targets 0xea4, is taken when a1(=[a0+88]:8) == 0, and falls through when a1(=[a0+88]:8) != 0.
  The `beq` branch at 0xe7c targets 0x1118, is taken when v0(=ret(rad_start_device)) == 0, and falls through when v0(=ret(rad_start_device)) != 0.
  The `beq` branch at 0xe90 targets 0xea4, is taken when a0(?) >= 0x18 (signed), and falls through when a0(?) < 0x18 (signed).
  The `bne` branch at 0xe9c targets 0xe74, is taken when a1(?) != 0, and falls through when a1(?) == 0.
  The `beq` branch at 0xebc targets 0x1100, is taken when v0(=[a0+538]:2) == s1(=0xd), and falls through when v0(=[a0+538]:2) != s1(=0xd).
  The `beq` branch at 0xec8 targets 0x1108, is taken when v0(=[a0+538]:2) == s1(=0xd), and falls through when v0(=[a0+538]:2) != s1(=0xd).
  The `beq` branch at 0xeec targets 0x1120, is taken when v0(=[a0+538]:2) == a1(=0x7), and falls through when v0(=[a0+538]:2) != a1(=0x7).
  The `beq` branch at 0xef4 targets 0x10e4, is taken when v0(=[a0+538]:2) == s1(=0xd), and falls through when v0(=[a0+538]:2) != s1(=0xd).
  The `beq` branch at 0xf18 targets 0x10ec, is taken when v0(=[a0+538]:2) == s2(=0xc), and falls through when v0(=[a0+538]:2) != s2(=0xc).
  The `beq` branch at 0xf24 targets 0xf80, is taken when a5(=[-0x3add]:1) == 0, and falls through when a5(=[-0x3add]:1) != 0.
  The `bne` branch at 0xf68 targets 0x10d0, is taken when s1(=[[a0+552]:8+48]) < 0x10 (unsigned), and falls through when s1(=[[a0+552]:8+48]) >= 0x10 (unsigned).
  The `beq` branch at 0xf70 targets 0x1140, is taken when v0(=[sym(.sbss)]:1) == 0, and falls through when v0(=[sym(.sbss)]:1) != 0.
  The `beq` branch at 0xf80 targets 0xf8c and is always taken.
  The `beq` branch at 0xfa4 targets 0xf8c and is always taken.
  The `beq` branch at 0xfb0 targets 0x9c0 and is always taken.
  The `beq` branch at 0xfc8 targets 0xb40 and is always taken.
  The `beq` branch at 0xfd0 targets 0xf8c and is always taken.
  The `beq` branch at 0xfe4 targets 0xa60 and is always taken.
  The `beq` branch at 0xfec targets 0xf8c and is always taken.
  The `beq` branch at 0xff4 targets 0xf8c and is always taken.
  The `beq` branch at 0xffc targets 0xf8c and is always taken.
  The `beq` branch at 0x1004 targets 0xf8c and is always taken.
  The `beq` branch at 0x1058 targets 0xa64 and is always taken.
  The `beq` branch at 0x10a0 targets 0xa64 and is always taken.
  The `beq` branch at 0x10a8 targets 0xf8c and is always taken.
  The `beq` branch at 0x10b0 targets 0xf8c and is always taken.
  The `beq` branch at 0x10b8 targets 0xf8c and is always taken.
  The `beq` branch at 0x10c0 targets 0xf8c and is always taken.
  The `beq` branch at 0x10c8 targets 0xf8c and is always taken.
  The `bne` branch at 0x10d4 targets 0xf80, is taken when s1(=[[a0+552]:8+48]) != 0, and falls through when s1(=[[a0+552]:8+48]) == 0.
  The `beq` branch at 0x10dc targets 0x1158 and is always taken.
  The `bne` branch at 0x10e4 targets 0xf20, is taken when v0(=[a0+538]:2) != s2(=0xc), and falls through when v0(=[a0+538]:2) == s2(=0xc).
  The `beq` branch at 0x10f8 targets 0xf20 and is always taken.
  The `bne` branch at 0x1100 targets 0xed0, is taken when v0(=[a0+538]:2) != s1(=0xd), and falls through when v0(=[a0+538]:2) == s1(=0xd).
  The `beq` branch at 0x1108 targets 0xed4 and is always taken.
  The `beq` branch at 0x1110 targets 0xf8c and is always taken.
  The `beq` branch at 0x1118 targets 0xf8c and is always taken.
  The `beq` branch at 0x1138 targets 0xef4 and is always taken.
  The `beq` branch at 0x1150 targets 0xf7c and is always taken.
  The `beq` branch at 0x1168 targets 0xf80 and is always taken.
  The return at 0xf9c has v0 = one of 0x0, 0x1.

- `rad_enable_ust` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x1170 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x1170-0x11a4 (52 bytes).
  It occupies 52 bytes.
  The `lh` at 0x1170 loads 2 bytes from a0 (arg0 at entry) +0x21a.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x228, including `ld` at 0x1188, `ld` at 0x1194.
  2 such `sw` accesses store 4 bytes to [a0+552]:8 +0x40, including `sw` at 0x1190, `sw` at 0x1198.
  The `beq` branch at 0x1178 targets 0x119c, is taken when a2(=[a0+538]:2) == at(=0x7), and falls through when a2(=[a0+538]:2) != at(=0x7).
  The `beq` branch at 0x1180 targets 0x119c, is taken when a2(=[a0+538]:2) == a3(=0xd), and falls through when a2(=[a0+538]:2) != a3(=0xd).
  The return at 0x119c has v0 = one of ?, 0xa.

- `rad_disable_ust` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x11a4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x11a4-0x11cc (40 bytes).
  It occupies 40 bytes.
  The `lh` at 0x11a4 loads 2 bytes from a0 (arg0 at entry) +0x21a.
  The `ld` at 0x11bc loads 8 bytes from a0 (arg0 at entry) +0x228.
  The `sw` at 0x11c0 stores 4 bytes to [a0+552]:8 +0x40.
  The `beq` branch at 0x11ac targets 0x11c4, is taken when a2(=[a0+538]:2) == at(=0x7), and falls through when a2(=[a0+538]:2) != at(=0x7).
  The `beq` branch at 0x11b4 targets 0x11c4, is taken when a2(=[a0+538]:2) == a3(=0xd), and falls through when a2(=[a0+538]:2) != a3(=0xd).
  The return at 0x11c4 has v0 = one of ?, 0x2.

- `rad_reset_ust` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x11cc (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x11cc-0x12c4 (248 bytes).
  It occupies 248 bytes.
  The `lh` at 0x11cc loads 2 bytes from a0 (arg0 at entry) +0x21a.
  2 such `lbu` accesses load 1 byte from abs 0xffffffffffffc523, including `lbu` at 0x11f8, `lbu` at 0x12c0.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x228, including `ld` at 0x123c, `ld` at 0x124c.
  2 such `sw` accesses store 4 bytes to [a0+552]:8 +0x40, including `sw` at 0x1244, `sw` at 0x1258.
  The `sd` at 0x1288 stores 8 bytes to a0 (arg0 at entry) +0x72a8.
  The `lw` at 0x12b0 loads 4 bytes from a0 (arg0 at entry) +0x731c.
  The `jal` at 0x1240 calls splprof with a0=[a0+552]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x1254 calls update_ust with a0=?, a1=?, a2=[a0+552]:8, a3=?.
  The `jal` at 0x125c calls get_ust_nano with a0=sp-48, a1=?, a2=?, a3=?.
  The `jal` at 0x1264 calls splx with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x12b4 calls cmn_err with a0=0x1, a1=sym(.rodata), a2=[a0+29468], a3=0xd, a4=[sym(.sbss)]:1, a5=[sym(.sbss)+1]:1.
  The `beq` branch at 0x11e8 targets 0x11f8, is taken when v0(=[a0+538]:2) == at(=0x7), and falls through when v0(=[a0+538]:2) != at(=0x7).
  The `bne` branch at 0x11f0 targets 0x128c, is taken when v0(=[a0+538]:2) != a3(=0xd), and falls through when v0(=[a0+538]:2) == a3(=0xd).
  The `beq` branch at 0x11fc targets 0x122c, is taken when v0(=[-0x3add]:1) == 0, and falls through when v0(=[-0x3add]:1) != 0.
  The `beq` branch at 0x1204 targets 0x1214, is taken when a4(=[sym(.sbss)]:1) == 0, and falls through when a4(=[sym(.sbss)]:1) != 0.
  The `bne` branch at 0x120c targets 0x12ac, is taken when a5(=[sym(.sbss)+1]:1) != 0, and falls through when a5(=[sym(.sbss)+1]:1) == 0.
  The `beq` branch at 0x1214 targets 0x122c, is taken when v0(=[-0x3add]:1) == 0, and falls through when v0(=[-0x3add]:1) != 0.
  The `beq` branch at 0x121c targets 0x122c, is taken when a0(=[sym(.sbss)]:1) == 0, and falls through when a0(=[sym(.sbss)]:1) != 0.
  The `beq` branch at 0x1224 targets 0x1298, is taken when v0(=[sym(.sbss)+1]:1) == 0, and falls through when v0(=[sym(.sbss)+1]:1) != 0.
  The `beq` branch at 0x12a4 targets 0x123c and is always taken.
  The `beq` branch at 0x12bc targets 0x1214 and is always taken.
  The return at 0x1290 has v0 = one of [a0+538]:2, ret(splx).

- `rad_set_ust_offset` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x12c4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x12c4-0x132c (104 bytes).
  It occupies 104 bytes.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x228, including `ld` at 0x12d0, `ld` at 0x12e8.
  2 such `lw` accesses load 4 bytes from [a0+552]:8 +0x30, including `lw` at 0x12e4, `lw` at 0x12ec.
  The `lw` at 0x1318 loads 4 bytes from a0 (arg0 at entry) +0x731c.
  The `jal` at 0x12e0 calls us_delay with a0=0xa, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x131c calls cmn_err with a0=0x1, a1=sym(.rodata), a2=[a0+29468], a3=?.
  The `bne` branch at 0x12f8 targets 0x1310, is taken when ra(?) < 0x3 (unsigned), and falls through when ra(?) >= 0x3 (unsigned).
  The `beq` branch at 0x1324 targets 0x1300 and is always taken.
  The return at 0x1308 has v0 = one of ret(us_delay), ret(cmn_err).

- `rad_create_device` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x132c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x132c-0x182c (1280 bytes).
  It occupies 1280 bytes.
  The `sd` at 0x13e8 stores 8 bytes to a1 (arg1 at entry) +0x2a0.
  The `sw` at 0x13ec stores 4 bytes to a1 (arg1 at entry) +0x29c.
  The `sw` at 0x13f4 stores 4 bytes to a1 (arg1 at entry) +0x120.
  The `sd` at 0x1414 stores 8 bytes to a1 (arg1 at entry) +0x200.
  The `sd` at 0x1418 stores 8 bytes to a1 (arg1 at entry) +0x218.
  The `sd` at 0x141c stores 8 bytes to a1 (arg1 at entry) +0x290.
  The `sd` at 0x1420 stores 8 bytes to a1 (arg1 at entry) +0x288.
  The `sd` at 0x1424 stores 8 bytes to a1 (arg1 at entry) +0x278.
  The `sd` at 0x1428 stores 8 bytes to a1 (arg1 at entry) +0x18.
  The `sd` at 0x1430 stores 8 bytes to a1 (arg1 at entry) +0x8.
  The `sd` at 0x143c stores 8 bytes to a1 (arg1 at entry) +0x20.
  2 such `sd` accesses store 8 bytes to a1 (arg1 at entry) +0x280, including `sd` at 0x1440, `sd` at 0x1578.
  The `sw` at 0x144c stores 4 bytes to a1 (arg1 at entry) +0x2c0.
  The `sw` at 0x145c stores 4 bytes to a1 (arg1 at entry) +0x298.
  The `sw` at 0x1468 stores 4 bytes to a1 (arg1 at entry) +0x2f0.
  The `lh` at 0x1484 loads 2 bytes from table(sym(.data)) +0x0.
  The `lw` at 0x1488 loads 4 bytes from table(sym(.data)) +0x10.
  3 such `sd` accesses store 8 bytes to a1 (arg1 at entry) +0x300, including `sd` at 0x14a0, `sd` at 0x1588, `sd` at 0x1598.
  3 such `sd` accesses store 8 bytes to a1 (arg1 at entry) +0x2f8, including `sd` at 0x14a8, `sd` at 0x157c, `sd` at 0x158c.
  The `ld` at 0x14c8 loads 8 bytes from (sym(.rodata) + (a4+2 << 0x3)) +0x0.
  The `jal` at 0x1378 calls kmem_alloc with a0=(a3 << 0x2), a1=0x8800, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x13b4 calls kdsp_init_resource with a0=a1 at entry (arg1), a1=one of 0x2000001b, 0x2000001c, a2=a5 at entry (arg5), a3=a6 at entry (arg6), a4=a0 at entry (arg0), a5=0x0, a6=0x318.
  The `jal` at 0x13d8 calls kdsp_create_device with a0=a1 at entry (arg1), a1=a3 at entry (arg3), a2=(a2 | 0x40), a3=0x0, a4=ret(kmem_alloc), a5=a7 at entry (arg7).
  Calls (unknown callee) via register with a0=-0x2, a1=?, a2=sym(rad_commit_device_params), a3=sym(rad_update_dev), a4=a0+29264, a5=sym(rad_stop_dma), a6=sym(rad_get_hw_mscust), a7=sym(rad_pre_connect) (`jr` at 0x14cc).
  The `jal` at 0x181c calls rad_destroy_devices with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `beq` branch at 0x13e0 targets 0x181c, is taken when v0(=ret(kdsp_create_device)) == 0, and falls through when v0(=ret(kdsp_create_device)) != 0.
  The `beq` branch at 0x1438 targets 0x1574, is taken when s3(=a2) == 0, and falls through when s3(=a2) != 0.
  The `beq` branch at 0x1464 targets 0x158c, is taken when s2(=a4) == a0(=-0x2), and falls through when s2(=a4) != a0(=-0x2).
  The `beq` branch at 0x1470 targets 0x157c, is taken when s2(=a4) == t8(=-0x1), and falls through when s2(=a4) != t8(=-0x1).
  The `beq` branch at 0x14c0 targets 0x14d4, is taken when v1(=a4+2) >= 0xa (unsigned), and falls through when v1(=a4+2) < 0xa (unsigned).
  The `beq` branch at 0x14d4 targets 0x1548 and is always taken.
  The `beq` branch at 0x1574 targets 0x1444 and is always taken.
  The `beq` branch at 0x1584 targets 0x14ac and is always taken.
  The `beq` branch at 0x1594 targets 0x14ac and is always taken.
  The `beq` branch at 0x1824 targets 0x1548 and is always taken.
  The return at 0x156c has v0 = 0x0.
  The instructions from 0x14dc to 0x1544 are not reached by any path from the entry, and their branches are not listed.
  The instructions from 0x159c to 0x1818 are not reached by any path from the entry, and their branches are not listed.
  The indirect jump at 0x14cc uses a jump table whose successors are unresolved.

- `rad_start_device` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x182c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x182c-0x18bc (144 bytes).
  It occupies 144 bytes.
  The `lw` at 0x182c loads 4 bytes from a1 (arg1 at entry) +0x2c0.
  4 such `ld` accesses load 8 bytes from a1 (arg1 at entry) +0x2e8, including `ld` at 0x185c, `ld` at 0x186c, `ld` at 0x188c.
  4 such `lw` accesses load 4 bytes from [a1+744]:8 +0x0, including `lw` at 0x1860, `lw` at 0x187c, `lw` at 0x1890.
  3 such `sw` accesses store 4 bytes to [a1+744]:8 +0x0, including `sw` at 0x1868, `sw` at 0x18a0, `sw` at 0x18b8.
  The `ld` at 0x1870 loads 8 bytes from a0 (arg0 at entry) +0x228.
  The `lwu` at 0x1874 loads 4 bytes from a1 (arg1 at entry) +0x2e4.
  The `sw` at 0x1888 stores 4 bytes to ([a1+740] + [a0+552]:8) +0x0.
  The `beq` branch at 0x183c targets 0x18a4, is taken when a3(=[a1+704]) == at(=-0x1), and falls through when a3(=[a1+704]) != at(=-0x1).
  The `beq` branch at 0x1844 targets 0x18a4, is taken when a3(=[a1+704]) == a6(=-0x2), and falls through when a3(=[a1+704]) != a6(=-0x2).
  The `beq` branch at 0x184c targets 0x188c, is taken when a3(=[a1+704]) == a4(=0x6), and falls through when a3(=[a1+704]) != a4(=0x6).
  The `beq` branch at 0x1854 targets 0x188c, is taken when a3(=[a1+704]) == a5(=0x7), and falls through when a3(=[a1+704]) != a5(=0x7).
  The `beq` branch at 0x189c targets 0x186c and is always taken.
  The `beq` branch at 0x18b4 targets 0x186c and is always taken.
  The return at 0x1884 has v0 = 0x1.

- `rad_create_ifs` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x18bc (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x18bc-0x1dd8 (1308 bytes).
  It occupies 1308 bytes.
  The `sw` at 0x18fc stores 4 bytes to sym(.data) +0x7430.
  The `sw` at 0x1904 stores 4 bytes to sym(.data) +0x7428.
  2 such `lh` accesses load 2 bytes from a0 (arg0 at entry) +0x21a, including `lh` at 0x1908, `lh` at 0x1d40.
  The `sd` at 0x195c stores 8 bytes to a0 (arg0 at entry) +0x58b0.
  The `sw` at 0x1968 stores 4 bytes to a0 (arg0 at entry) +0x5838.
  The `sd` at 0x1978 stores 8 bytes to a0 (arg0 at entry) +0x5728.
  The `sd` at 0x197c stores 8 bytes to a0 (arg0 at entry) +0x5720.
  The `sw` at 0x1980 stores 4 bytes to a0 (arg0 at entry) +0x58b8.
  The `sd` at 0x1998 stores 8 bytes to a0 (arg0 at entry) +0x5738.
  The `sd` at 0x19a4 stores 8 bytes to sym(.bss) +0x40.
  The `sd` at 0x19ac stores 8 bytes to sym(.bss) +0x10.
  The `sd` at 0x19b8 stores 8 bytes to sym(.bss) +0x18.
  The `sd` at 0x19c4 stores 8 bytes to sym(.bss) +0x28.
  The `sd` at 0x19d0 stores 8 bytes to sym(.bss) +0x0.
  The `sd` at 0x19dc stores 8 bytes to sym(.bss) +0x8.
  The `sd` at 0x19e8 stores 8 bytes to sym(.bss) +0x30.
  The `sw` at 0x19f4 stores 4 bytes to sym(.bss) +0x20.
  The `sw` at 0x1a00 stores 4 bytes to sym(.bss) +0x38.
  The `sd` at 0x1a0c stores 8 bytes to sym(.bss) +0x48.
  The `sd` at 0x1a20 stores 8 bytes to a0 (arg0 at entry) +0x5a58.
  2 such `lw` accesses load 4 bytes from sym(.data) +0x7428, including `lw` at 0x1a30, `lw` at 0x1b7c.
  The `sw` at 0x1a38 stores 4 bytes to a0 (arg0 at entry) +0x59e0.
  The `sd` at 0x1a40 stores 8 bytes to a0 (arg0 at entry) +0x58e0.
  The `sd` at 0x1a44 stores 8 bytes to a0 (arg0 at entry) +0x58d0.
  The `sd` at 0x1a48 stores 8 bytes to a0 (arg0 at entry) +0x58c8.
  The `sw` at 0x1a4c stores 4 bytes to a0 (arg0 at entry) +0x5a60.
  The `sd` at 0x1a50 stores 8 bytes to sym(.bss) +0x98.
  The `sd` at 0x1a54 stores 8 bytes to sym(.bss) +0x58.
  The `sd` at 0x1a58 stores 8 bytes to sym(.bss) +0x50.
  The `sw` at 0x1a60 stores 4 bytes to sym(.bss) +0x70.
  The `sd` at 0x1a64 stores 8 bytes to sym(.bss) +0x68.
  The `sd` at 0x1a68 stores 8 bytes to sym(.bss) +0x60.
  The `sd` at 0x1a6c stores 8 bytes to sym(.bss) +0x90.
  The `sd` at 0x1ab4 stores 8 bytes to a0 (arg0 at entry) +0x5c00.
  The `sw` at 0x1ac0 stores 4 bytes to a0 (arg0 at entry) +0x5b88.
  The `sd` at 0x1ac4 stores 8 bytes to a0 (arg0 at entry) +0x5a78.
  The `sd` at 0x1ac8 stores 8 bytes to a0 (arg0 at entry) +0x5a70.
  The `sd` at 0x1ad8 stores 8 bytes to a0 (arg0 at entry) +0x5a88.
  The `sw` at 0x1ae0 stores 4 bytes to a0 (arg0 at entry) +0x5c08.
  The `sd` at 0x1aec stores 8 bytes to sym(.bss) +0x138.
  The `sd` at 0x1af4 stores 8 bytes to sym(.bss) +0xf8.
  The `sd` at 0x1af8 stores 8 bytes to sym(.bss) +0xf0.
  The `sd` at 0x1b00 stores 8 bytes to sym(.bss) +0x118.
  The `sd` at 0x1b08 stores 8 bytes to sym(.bss) +0x120.
  The `sw` at 0x1b10 stores 4 bytes to sym(.bss) +0x128.
  The `sw` at 0x1b18 stores 4 bytes to sym(.bss) +0x110.
  The `sd` at 0x1b1c stores 8 bytes to sym(.bss) +0x108.
  The `sd` at 0x1b20 stores 8 bytes to sym(.bss) +0x100.
  The `sd` at 0x1b28 stores 8 bytes to sym(.bss) +0x130.
  The `sd` at 0x1b78 stores 8 bytes to a0 (arg0 at entry) +0x5da8.
  The `sw` at 0x1b84 stores 4 bytes to a0 (arg0 at entry) +0x5d30.
  The `sd` at 0x1b8c stores 8 bytes to a0 (arg0 at entry) +0x5c30.
  The `sd` at 0x1b90 stores 8 bytes to a0 (arg0 at entry) +0x5c20.
  The `sd` at 0x1b94 stores 8 bytes to a0 (arg0 at entry) +0x5c18.
  The `sw` at 0x1b9c stores 4 bytes to a0 (arg0 at entry) +0x5db0.
  The `sd` at 0x1ba8 stores 8 bytes to sym(.bss) +0xe8.
  The `sd` at 0x1bb0 stores 8 bytes to sym(.bss) +0xa8.
  The `sd` at 0x1bb4 stores 8 bytes to sym(.bss) +0xa0.
  The `sd` at 0x1bb8 stores 8 bytes to sym(.bss) +0xd0.
  The `sw` at 0x1bc0 stores 4 bytes to sym(.bss) +0xc0.
  The `sd` at 0x1bc4 stores 8 bytes to sym(.bss) +0xb8.
  The `sd` at 0x1bc8 stores 8 bytes to sym(.bss) +0xb0.
  The `sd` at 0x1bd0 stores 8 bytes to sym(.bss) +0xe0.
  The `sd` at 0x1c08 stores 8 bytes to a0 (arg0 at entry) +0x5f50.
  The `sw` at 0x1c10 stores 4 bytes to a0 (arg0 at entry) +0x5ed8.
  The `sd` at 0x1c18 stores 8 bytes to a0 (arg0 at entry) +0x5dc0.
  The `sw` at 0x1c24 stores 4 bytes to a0 (arg0 at entry) +0x5f58.
  The `sd` at 0x1c30 stores 8 bytes to a0 (arg0 at entry) +0x5dd8.
  The `sd` at 0x1c60 stores 8 bytes to a0 (arg0 at entry) +0x60f8.
  The `sw` at 0x1c68 stores 4 bytes to a0 (arg0 at entry) +0x6080.
  The `sd` at 0x1c70 stores 8 bytes to a0 (arg0 at entry) +0x5f68.
  The `sw` at 0x1c7c stores 4 bytes to a0 (arg0 at entry) +0x6100.
  The `sd` at 0x1c88 stores 8 bytes to a0 (arg0 at entry) +0x5f80.
  The `sd` at 0x1cbc stores 8 bytes to a0 (arg0 at entry) +0x62a0.
  The `sw` at 0x1cc4 stores 4 bytes to a0 (arg0 at entry) +0x6228.
  The `sd` at 0x1ccc stores 8 bytes to a0 (arg0 at entry) +0x6110.
  The `sw` at 0x1cd8 stores 4 bytes to a0 (arg0 at entry) +0x62a8.
  The `sd` at 0x1ce4 stores 8 bytes to a0 (arg0 at entry) +0x6128.
  The `sd` at 0x1d14 stores 8 bytes to a0 (arg0 at entry) +0x6448.
  The `sw` at 0x1d1c stores 4 bytes to a0 (arg0 at entry) +0x63d0.
  The `sd` at 0x1d24 stores 8 bytes to a0 (arg0 at entry) +0x62b8.
  The `sw` at 0x1d30 stores 4 bytes to a0 (arg0 at entry) +0x6450.
  The `sd` at 0x1d3c stores 8 bytes to a0 (arg0 at entry) +0x62d0.
  The `jal` at 0x1944 calls kdsp_init_resource with a0=a0+22296, a1=0x2000000e, a2=sym(.rodata), a3=sym(.rodata), a4=a0 at entry (arg0), a5=0x0, a6=0x1a8.
  The `jal` at 0x1a08 calls kdsp_init_resource with a0=a0+22720, a1=0x2000000e, a2=sym(.rodata), a3=sym(.rodata), a4=a0 at entry (arg0), a5=0x0, a6=0x1a8, a7=sym(.bss).
  The `jal` at 0x1a70 calls kdsp_add_subresource with a0=a0+4208, a1=a0+22720, a2=0x1, a3=0xb, a4=sym(.data)+32768, a5=sym(rad_get_analog_out_if_params), a6=sym(rad_set_analog_out_if_params), a7=[sym(.data)+29736].
  The `jal` at 0x1a98 calls kdsp_init_resource with a0=a0+23144, a1=0x2000000d, a2=sym(.rodata), a3=0x0, a4=a0 at entry (arg0), a5=0x0, a6=0x1a8.
  The `jal` at 0x1b24 calls kdsp_select_interface with a0=a0+3416, a1=a0+23144, a2=sym(.bss), a3=0x1, a4=0xff, a5=0x50d0d0d1, a6=0x32aee8263, a7=0x1480000000.
  The `jal` at 0x1b50 calls kdsp_init_resource with a0=a0+23568, a1=0x20000011, a2=sym(.rodata), a3=sym(.rodata), a4=a0 at entry (arg0), a5=0x0, a6=0x1a8.
  The `jal` at 0x1bcc calls kdsp_add_subresource with a0=a0+4208, a1=a0+23568, a2=sym(.bss), a3=0x3, a4=0x217354b8e7, a5=0x1480000000, a6=0xb00000000, a7=0xb.
  The `jal` at 0x1bfc calls kdsp_init_resource with a0=a0+23992, a1=0x2000000f, a2=sym(.rodata), a3=sym(.rodata), a4=a0 at entry (arg0), a5=0x0, a6=0x1a8.
  The `jal` at 0x1c2c calls kdsp_select_interface with a0=a0+5000, a1=a0+23992, a2=?, a3=?.
  The `jal` at 0x1c54 calls kdsp_init_resource with a0=a0+24416, a1=0x2000000f, a2=sym(.rodata), a3=sym(.rodata), a4=a0 at entry (arg0), a5=0x0, a6=0x1a8.
  The `jal` at 0x1c84 calls kdsp_select_interface with a0=a0+5792, a1=a0+24416, a2=?, a3=sym(.data)+32768, a4=[sym(.sdata)+40], a5=sym(rad_set_digital_if_params).
  The `jal` at 0x1cb0 calls kdsp_init_resource with a0=a0+24840, a1=0x20000025, a2=sym(.rodata), a3=sym(.rodata), a4=a0 at entry (arg0), a5=0x0, a6=0x1a8.
  The `jal` at 0x1ce0 calls kdsp_select_interface with a0=a0+6584, a1=a0+24840, a2=sym(.data)+32768, a3=[sym(.sdata)+40], a4=sym(rad_set_digital_if_params).
  The `jal` at 0x1d08 calls kdsp_init_resource with a0=a0+25264, a1=0x20000025, a2=sym(.rodata), a3=sym(.rodata), a4=a0 at entry (arg0), a5=0x0, a6=0x1a8.
  The `jal` at 0x1d38 calls kdsp_select_interface with a0=a0+7376, a1=a0+25264, a2=sym(.data)+32768, a3=[sym(.sdata)+40], a4=sym(rad_set_digital_if_params).
  The `jal` at 0x1d54 calls kdsp_map_resource with a0=a0+23144, a1=0x0, a2=?, a3=?, a5=[a0+538]:2, a6=0xd.
  The `jal` at 0x1d60 calls kdsp_map_resource with a0=a0+22296, a1=0x0, a2=?, a3=?.
  The `jal` at 0x1d6c calls kdsp_map_resource with a0=a0+22720, a1=0x0, a2=?, a3=?.
  The `jal` at 0x1d78 calls kdsp_map_resource with a0=a0+23568, a1=0x0, a2=?, a3=?.
  The `jal` at 0x1d94 calls kdsp_map_resource with a0=a0+23992, a1=0x0, a2=?, a3=?.
  The `jal` at 0x1da0 calls kdsp_map_resource with a0=a0+24416, a1=0x0, a2=?, a3=?.
  The `jal` at 0x1db0 calls kdsp_map_resource with a0=a0+24840, a1=0x0, a2=?, a3=?.
  The `jal` at 0x1dbc calls kdsp_map_resource with a0=a0+25264, a1=0x0, a2=?, a3=?.
  The `beq` branch at 0x191c targets 0x1bd4, is taken when at(=[a0+538]:2) == v0(=0xd), and falls through when at(=[a0+538]:2) != v0(=0xd).
  The `beq` branch at 0x1d48 targets 0x1d80, is taken when a5(=[a0+538]:2) == a6(=0xd), and falls through when a5(=[a0+538]:2) != a6(=0xd).
  The return at 0x1dd0 has v0 = 0x1.

- `rad_create_subcode_device` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x1dd8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x1dd8-0x1f28 (336 bytes).
  It occupies 336 bytes.
  The `sw` at 0x1e50 stores 4 bytes to a1 (arg1 at entry) +0x258.
  The `sd` at 0x1e58 stores 8 bytes to a1 (arg1 at entry) +0x60.
  The `sd` at 0x1e64 stores 8 bytes to a1 (arg1 at entry) +0x58.
  The `lw` at 0x1f10 loads 4 bytes from a3 (arg3 at entry) +0x5c.
  The `sw` at 0x1f24 stores 4 bytes to a3 (arg3 at entry) +0x5c.
  The `jal` at 0x1e40 calls rad_create_device with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a4 at entry (arg4), a3=?, a4=a5 at entry (arg5), a5=a7 at entry (arg7).
  The `jal` at 0x1e70 calls kdsp_select_clockgen with a0=a1 at entry (arg1), a1=?, a2=?, a3=?.
  The `jal` at 0x1e7c calls kdsp_select_interface with a0=a1 at entry (arg1), a1=?, a2=?, a3=?.
  The `jal` at 0x1e88 calls rad_start_device with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0x1ec8 calls kdsp_create_subcode with a0=a3 at entry (arg3), a1=a2 at entry (arg2), a2=a1 at entry (arg1), a3=a6 at entry (arg6).
  The `jal` at 0x1ef0 calls kdsp_set_default_subcode with a0=a3 at entry (arg3), a1=sp-144, a2=0x0, a3=?.
  The `beq` branch at 0x1e18 targets 0x1e24, is taken when a6 == 0, and falls through when a6 != 0.
  The `beq` branch at 0x1e48 targets 0x1e98, is taken when v0(=ret(rad_create_device)) == 0, and falls through when v0(=ret(rad_create_device)) != 0.
  The `bne` branch at 0x1e60 targets 0x1ebc, is taken when s1(=a3) != 0, and falls through when s1(=a3) == 0.
  The `beq` branch at 0x1ed4 targets 0x1efc, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x1f08 targets 0x1e68, is taken when v1(?) == 0, and falls through when v1(?) != 0.
  The `beq` branch at 0x1f20 targets 0x1e68 and is always taken.
  The return at 0x1eb4 has v0 = one of 0x0, 0x1.

- `rad_create_subcodes` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x1f28 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x1f28-0x24bc (1428 bytes).
  It occupies 1428 bytes.
  2 such `lh` accesses load 2 bytes from a0 (arg0 at entry) +0x21a, including `lh` at 0x1f64, `lh` at 0x243c.
  The `sw` at 0x23ac stores 4 bytes to a0 (arg0 at entry) +0x723c.
  The `sw` at 0x23b0 stores 4 bytes to a0 (arg0 at entry) +0x7238.
  The `sb` at 0x23b4 stores 1 byte to a0 (arg0 at entry) +0x7311.
  The `sb` at 0x23b8 stores 1 byte to a0 (arg0 at entry) +0x7310.
  The `sb` at 0x23c0 stores 1 byte to a0 (arg0 at entry) +0x7312.
  2 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x7316, including `sb` at 0x23c4, `sb` at 0x23e0.
  2 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x7314, including `sb` at 0x23c8, `sb` at 0x23dc.
  The `sb` at 0x23e4 stores 1 byte to a0 (arg0 at entry) +0x7315.
  The `sb` at 0x23e8 stores 1 byte to a0 (arg0 at entry) +0x7317.
  The `lw` at 0x23ec loads 4 bytes from a0 (arg0 at entry) +0x7244.
  The `ld` at 0x23f0 loads 8 bytes from a0 (arg0 at entry) +0x228.
  The `sw` at 0x23f8 stores 4 bytes to a0 (arg0 at entry) +0x7244.
  The `sw` at 0x2404 stores 4 bytes to [a0+552]:8 +0x70.
  The `jal` at 0x1fd4 calls rad_create_subcode_device with a0=a0 at entry (arg0), a1=a0+8168, a2=a0+5000, a3=0x0, a4=0x400, a5=0x6, a6=0x0, a7=sym(.rodata).
  The `jal` at 0x2030 calls rad_create_subcode_device with a0=a0 at entry (arg0), a1=a0+8960, a2=a0+6584, a3=0x0, a4=0x400, a5=0x7, a6=0x0, a7=sym(.rodata).
  The `jal` at 0x2084 calls rad_create_subcode_device with a0=a0 at entry (arg0), a1=a0+10544, a2=a0+5000, a3=a0+21256, a4=0x0, a5=0x6, a6=0x1000002f, a7=sym(.rodata).
  The `jal` at 0x20d8 calls rad_create_subcode_device with a0=a0 at entry (arg0), a1=a0+9752, a2=a0+5000, a3=a0+21152, a4=0x0, a5=0x6, a6=0x10000030, a7=sym(.rodata).
  The `jal` at 0x212c calls rad_create_subcode_device with a0=a0 at entry (arg0), a1=a0+11336, a2=a0+5000, a3=a0+21360, a4=0x0, a5=0x6, a6=0x10000031, a7=sym(.rodata).
  The `jal` at 0x2188 calls rad_create_subcode_device with a0=a0 at entry (arg0), a1=a0+12920, a2=a0+5792, a3=a0+20944, a4=0x1, a5=-0x1, a6=0x1000002f, a7=sym(.rodata).
  The `jal` at 0x21e0 calls rad_create_subcode_device with a0=a0 at entry (arg0), a1=a0+12128, a2=a0+5792, a3=a0+20840, a4=0x1, a5=-0x1, a6=0x10000030, a7=sym(.rodata).
  The `jal` at 0x2238 calls rad_create_subcode_device with a0=a0 at entry (arg0), a1=a0+13712, a2=a0+5792, a3=a0+21048, a4=0x1, a5=-0x1, a6=0x10000031, a7=sym(.rodata).
  The `jal` at 0x227c calls sprintf with a0=sp-192, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x228c calls sprintf with a0=sp-168, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x2310 calls rad_create_subcode_device with a0=a0 at entry (arg0), a1=?, a2=?, a3=?, a4=0x0, a5=0x7, a7=sp-192.
  The `jal` at 0x2324 calls sprintf with a0=sp-192, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x2334 calls sprintf with a0=sp-168, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x238c calls rad_create_subcode_device with a0=a0 at entry (arg0), a1=?, a2=?, a3=?, a4=0x1, a5=-0x2, a7=sp-192.
  The `jal` at 0x23cc calls rad_pio_writeback_subcode_tx with a0=?, a1=?, a2=?, a3=0x1.
  The `jal` at 0x23d4 calls rad_pio_writeback_subcode_tx with a0=a0+17672, a1=?, a2=?, a3=?.
  The `beq` branch at 0x1f54 targets 0x243c, is taken when v0(=[sym(kdsp_pro_audio_subcode)]) == a1(=0x1), and falls through when v0(=[sym(kdsp_pro_audio_subcode)]) != a1(=0x1).
  The `beq` branch at 0x1f5c targets 0x2464, is taken when v0(=[sym(kdsp_pro_audio_subcode)]) == 0, and falls through when v0(=[sym(kdsp_pro_audio_subcode)]) != 0.
  The `beq` branch at 0x1f70 targets 0x246c, is taken when v0(=[a0+538]:2) == at(=0x7), and falls through when v0(=[a0+538]:2) != at(=0x7).
  The `beq` branch at 0x1f7c targets 0x247c, is taken when v0(=[a0+538]:2) == v1(=0xd), and falls through when v0(=[a0+538]:2) != v1(=0xd).
  The `beq` branch at 0x1fdc targets 0x2408, is taken when v0(=ret(rad_create_subcode_device)) == 0, and falls through when v0(=ret(rad_create_subcode_device)) != 0.
  The `beq` branch at 0x2038 targets 0x2434, is taken when v0(=ret(rad_create_subcode_device)) == 0, and falls through when v0(=ret(rad_create_subcode_device)) != 0.
  The `beq` branch at 0x208c targets 0x245c, is taken when v0(=ret(rad_create_subcode_device)) == 0, and falls through when v0(=ret(rad_create_subcode_device)) != 0.
  The `beq` branch at 0x20e0 targets 0x2474, is taken when v0(=ret(rad_create_subcode_device)) == 0, and falls through when v0(=ret(rad_create_subcode_device)) != 0.
  The `beq` branch at 0x2134 targets 0x2484, is taken when v0(=ret(rad_create_subcode_device)) == 0, and falls through when v0(=ret(rad_create_subcode_device)) != 0.
  The `beq` branch at 0x2190 targets 0x248c, is taken when v0(=ret(rad_create_subcode_device)) == 0, and falls through when v0(=ret(rad_create_subcode_device)) != 0.
  The `beq` branch at 0x21e8 targets 0x2494, is taken when v0(=ret(rad_create_subcode_device)) == 0, and falls through when v0(=ret(rad_create_subcode_device)) != 0.
  The `beq` branch at 0x2240 targets 0x24b4, is taken when v0(=ret(rad_create_subcode_device)) == 0, and falls through when v0(=ret(rad_create_subcode_device)) != 0.
  The `beq` branch at 0x2318 targets 0x249c, is taken when v0(=ret(rad_create_subcode_device)) == 0, and falls through when v0(=ret(rad_create_subcode_device)) != 0.
  The `beq` branch at 0x2394 targets 0x24ac, is taken when v0(=ret(rad_create_subcode_device)) == 0, and falls through when v0(=ret(rad_create_subcode_device)) != 0.
  The `bne` branch at 0x23a4 targets 0x2278, is taken when s1(?) < 0x4 (signed), and falls through when s1(?) >= 0x4 (signed).
  The `beq` branch at 0x2400 targets 0x240c and is always taken.
  The `beq` branch at 0x2434 targets 0x240c and is always taken.
  The `beq` branch at 0x2448 targets 0x24a4, is taken when a5(=[a0+538]:2) == a6(=0xd), and falls through when a5(=[a0+538]:2) != a6(=0xd).
  The `beq` branch at 0x2454 targets 0x1f88 and is always taken.
  The `beq` branch at 0x245c targets 0x240c and is always taken.
  The `beq` branch at 0x2464 targets 0x1f88 and is always taken.
  The `beq` branch at 0x246c targets 0x1f8c and is always taken.
  The `beq` branch at 0x2474 targets 0x240c and is always taken.
  The `beq` branch at 0x247c targets 0x1f8c and is always taken.
  The `beq` branch at 0x2484 targets 0x240c and is always taken.
  The `beq` branch at 0x248c targets 0x240c and is always taken.
  The `beq` branch at 0x2494 targets 0x240c and is always taken.
  The `beq` branch at 0x249c targets 0x240c and is always taken.
  The `beq` branch at 0x24a4 targets 0x1f8c and is always taken.
  The `beq` branch at 0x24ac targets 0x240c and is always taken.
  The `beq` branch at 0x24b4 targets 0x240c and is always taken.
  The return at 0x242c has v0 = one of 0x0, 0x1.

- `rad_create_mclks` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x24bc (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x24bc-0x27b4 (760 bytes).
  It occupies 760 bytes.
  The `sw` at 0x2508 stores 4 bytes to a0 (arg0 at entry) +0x488.
  The `sw` at 0x2510 stores 4 bytes to a0 (arg0 at entry) +0x490.
  The `sw` at 0x2514 stores 4 bytes to a0 (arg0 at entry) +0x48c.
  The `sw` at 0x251c stores 4 bytes to a0 (arg0 at entry) +0x3f8.
  The `sd` at 0x2538 stores 8 bytes to a0 (arg0 at entry) +0x470.
  The `sd` at 0x2544 stores 8 bytes to a0 (arg0 at entry) +0x2f8.
  The `sw` at 0x2574 stores 4 bytes to a0 (arg0 at entry) +0x648.
  The `sw` at 0x2578 stores 4 bytes to a0 (arg0 at entry) +0x64c.
  The `sw` at 0x257c stores 4 bytes to a0 (arg0 at entry) +0x650.
  The `sw` at 0x2580 stores 4 bytes to a0 (arg0 at entry) +0x5b8.
  The `sd` at 0x2598 stores 8 bytes to a0 (arg0 at entry) +0x630.
  The `sd` at 0x25a4 stores 8 bytes to a0 (arg0 at entry) +0x4b8.
  The `sw` at 0x25d8 stores 4 bytes to a0 (arg0 at entry) +0x9c8.
  The `sw` at 0x25dc stores 4 bytes to a0 (arg0 at entry) +0x9cc.
  The `sw` at 0x25e0 stores 4 bytes to a0 (arg0 at entry) +0x9d0.
  The `sd` at 0x25e4 stores 8 bytes to a0 (arg0 at entry) +0x9b0.
  The `sw` at 0x25e8 stores 4 bytes to a0 (arg0 at entry) +0x938.
  The `sd` at 0x25fc stores 8 bytes to a0 (arg0 at entry) +0x9b8.
  The `sd` at 0x2608 stores 8 bytes to a0 (arg0 at entry) +0x838.
  The `sd` at 0x2624 stores 8 bytes to a0 (arg0 at entry) +0x72f8.
  The `sh` at 0x2630 stores 2 bytes to a0 (arg0 at entry) +0x7300.
  The `sw` at 0x2640 stores 4 bytes to a0 (arg0 at entry) +0x808.
  The `sw` at 0x2644 stores 4 bytes to a0 (arg0 at entry) +0x80c.
  The `sw` at 0x2648 stores 4 bytes to a0 (arg0 at entry) +0x810.
  The `sd` at 0x264c stores 8 bytes to a0 (arg0 at entry) +0x7f0.
  The `sw` at 0x2650 stores 4 bytes to a0 (arg0 at entry) +0x778.
  The `sd` at 0x2664 stores 8 bytes to a0 (arg0 at entry) +0x7f8.
  The `sd` at 0x2670 stores 8 bytes to a0 (arg0 at entry) +0x678.
  The `sb` at 0x2688 stores 1 byte to a0 (arg0 at entry) +0x730a.
  The `sh` at 0x2694 stores 2 bytes to a0 (arg0 at entry) +0x730c.
  The `sb` at 0x26a0 stores 1 byte to a0 (arg0 at entry) +0x730b.
  The `sw` at 0x26ac stores 4 bytes to a0 (arg0 at entry) +0xb88.
  The `sw` at 0x26b0 stores 4 bytes to a0 (arg0 at entry) +0xb90.
  The `sw` at 0x26b4 stores 4 bytes to a0 (arg0 at entry) +0xb8c.
  The `sw` at 0x26b8 stores 4 bytes to a0 (arg0 at entry) +0xaf8.
  The `sd` at 0x26cc stores 8 bytes to a0 (arg0 at entry) +0xb70.
  The `sd` at 0x26d0 stores 8 bytes to a0 (arg0 at entry) +0x9e0.
  The `sd` at 0x26e0 stores 8 bytes to a0 (arg0 at entry) +0x9e8.
  The `sd` at 0x26ec stores 8 bytes to a0 (arg0 at entry) +0x9f8.
  The `sw` at 0x2720 stores 4 bytes to a0 (arg0 at entry) +0xd48.
  The `sw` at 0x2724 stores 4 bytes to a0 (arg0 at entry) +0xd4c.
  The `sw` at 0x2728 stores 4 bytes to a0 (arg0 at entry) +0xd50.
  The `sd` at 0x272c stores 8 bytes to a0 (arg0 at entry) +0xd30.
  The `sw` at 0x2730 stores 4 bytes to a0 (arg0 at entry) +0xcb8.
  The `sd` at 0x273c stores 8 bytes to a0 (arg0 at entry) +0xba0.
  The `sd` at 0x274c stores 8 bytes to a0 (arg0 at entry) +0xba8.
  The `sd` at 0x2758 stores 8 bytes to a0 (arg0 at entry) +0xbb8.
  The `lh` at 0x2760 loads 2 bytes from a0 (arg0 at entry) +0x21a.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0xd54, including `sw` at 0x279c, `sw` at 0x27a8.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0xb94, including `sw` at 0x27a4, `sw` at 0x27b0.
  The `jal` at 0x2500 calls kdsp_init_resource with a0=a0+728, a1=0x2000000a, a2=sym(.rodata), a3=sym(.rodata), a4=a0 at entry (arg0), a5=0x0, a6=0x1c0.
  The `jal` at 0x2540 calls kdsp_map_resource with a0=a0+728, a1=0x0, a2=sym(.data)+32768, a3=0xac4400000000.
  The `jal` at 0x2568 calls kdsp_init_resource with a0=a0+1176, a1=0x2000000a, a2=sym(.rodata), a3=sym(.rodata), a4=a0 at entry (arg0), a5=0x0, a6=0x1c0.
  The `jal` at 0x25a0 calls kdsp_map_resource with a0=a0+1176, a1=0x0, a2=sym(.data)+32768, a3=?.
  The `jal` at 0x25cc calls kdsp_init_resource with a0=a0+2072, a1=0x2000000b, a2=sym(.rodata), a3=sym(.rodata), a4=a0 at entry (arg0), a5=0x0, a6=0x1c0.
  The `jal` at 0x2604 calls kdsp_map_resource with a0=a0+2072, a1=0x0, a2=sym(.data)+32768, a3=sym(rad_update_aes_mclk), a4=0x3.
  The `jal` at 0x2634 calls kdsp_init_resource with a0=a0+1624, a1=0x2000000c, a2=sym(.rodata), a3=sym(.rodata), a4=a0 at entry (arg0), a5=0x0, a6=0x1c0.
  The `jal` at 0x266c calls kdsp_map_resource with a0=a0+1624, a1=0x0, a2=sym(.data)+32768, a3=sym(rad_update_adat_mclk), a4=0x2.
  The `jal` at 0x26a4 calls kdsp_init_resource with a0=a0+2520, a1=0x20000016, a2=sym(.rodata), a3=sym(.rodata), a4=a0 at entry (arg0), a5=0x0, a6=0x1c0, a7=0x1.
  The `jal` at 0x26e8 calls kdsp_map_resource with a0=a0+2520, a1=0x0, a2=sym(.data)+32768, a3=sym(rad_get_mclk_params), a4=sym(rad_set_mclk_params), a5=0xac4400000000.
  The `jal` at 0x2710 calls kdsp_init_resource with a0=a0+2968, a1=0x20000016, a2=sym(.rodata), a3=sym(.rodata), a4=a0 at entry (arg0), a5=0x0, a6=0x1c0.
  The `jal` at 0x2754 calls kdsp_map_resource with a0=a0+2968, a1=0x0, a2=sym(.data)+32768, a3=sym(rad_get_mclk_params), a4=sym(rad_set_mclk_params), a5=0x1.
  The `beq` branch at 0x276c targets 0x27a8, is taken when a0(=[a0+538]:2) == s2(=0x7), and falls through when a0(=[a0+538]:2) != s2(=0x7).
  The `beq` branch at 0x2778 targets 0x27a8, is taken when a0(=[a0+538]:2) == a6(=0xd), and falls through when a0(=[a0+538]:2) != a6(=0xd).
  The `beq` branch at 0x2780 targets 0x2798, is taken when a0(=[a0+538]:2) == a7(=0xc), and falls through when a0(=[a0+538]:2) != a7(=0xc).
  The `beq` branch at 0x27a0 targets 0x2784 and is always taken.
  The `beq` branch at 0x27ac targets 0x2784 and is always taken.
  The return at 0x2790 has v0 = 0x1.

- `rad_video_sync_paraminfo_vals` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x27b4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x27b4-0x2860 (172 bytes).
  It occupies 172 bytes.
  The `lw` at 0x27b8 loads 4 bytes from a1 (arg1 at entry) +0x0.
  The `ld` at 0x27c4 loads 8 bytes from a0 (arg0 at entry) +0x118.
  The `lh` at 0x27d4 loads 2 bytes from [a0+280]:8 +0x21a.
  The `sw` at 0x2828 stores 4 bytes to (a2 + (a3 << 0x3)) +0x0.
  The `sw` at 0x2830 stores 4 bytes to (a2 + (a3+2 << 0x3)) -0x8.
  2 such `sw` accesses store 4 bytes to a1 (arg1 at entry) +0x4c, including `sw` at 0x283c, `sw` at 0x285c.
  The `sw` at 0x2850 stores 4 bytes to (a2 + (a3+1 << 0x3)) -0x8.
  The `bne` branch at 0x27d8 targets 0x280c, is taken when at(=[a1]) != v1(=0x1000002a), and falls through when at(=[a1]) == v1(=0x1000002a).
  The `beq` branch at 0x27e4 targets 0x27f4, is taken when a0 == a3(=[a0+280]:8+2520), and falls through when a0 != a3(=[a0+280]:8+2520).
  The `bne` branch at 0x27ec targets 0x280c, is taken when a0 != t2(=[a0+280]:8+2968), and falls through when a0 == t2(=[a0+280]:8+2968).
  The `beq` branch at 0x27f4 targets 0x2818, is taken when a6(=[[a0+280]:8+538]:2) == t0(=0x7), and falls through when a6(=[[a0+280]:8+538]:2) != t0(=0x7).
  The `beq` branch at 0x27fc targets 0x2818, is taken when a6(=[[a0+280]:8+538]:2) == t1(=0xd), and falls through when a6(=[[a0+280]:8+538]:2) != t1(=0xd).
  The `beq` branch at 0x2804 targets 0x2840, is taken when a6(=[[a0+280]:8+538]:2) == t3(=0xc), and falls through when a6(=[[a0+280]:8+538]:2) != t3(=0xc).
  The return at 0x280c has v0 = a3.
  The return at 0x2838 has v0 = a3+2.
  The return at 0x2858 has v0 = a3+1.
  The instructions from 0x2814 to 0x2814 are not reached by any path from the entry, and their branches are not listed.

- `rad_create_clockgen` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x2860 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x2860-0x2b00 (672 bytes).
  It occupies 672 bytes.
  The `ld` at 0x2890 loads 8 bytes from a1 (arg1 at entry) +0x2a0.
  The `sw` at 0x28dc stores 4 bytes to a0 (arg0 at entry) +0x1d8.
  The `sd` at 0x28e0 stores 8 bytes to a0 (arg0 at entry) +0x1c0.
  The `sd` at 0x28e4 stores 8 bytes to a0 (arg0 at entry) +0x1d0.
  The `sd` at 0x28e8 stores 8 bytes to a0 (arg0 at entry) +0x1c8.
  The `sw` at 0x28f0 stores 4 bytes to a0 (arg0 at entry) +0x120.
  The `sd` at 0x2908 stores 8 bytes to a0 (arg0 at entry) +0x1a8.
  The `sd` at 0x290c stores 8 bytes to a0 (arg0 at entry) +0x1a0.
  The `sd` at 0x2910 stores 8 bytes to a0 (arg0 at entry) +0x18.
  The `sd` at 0x2914 stores 8 bytes to a0 (arg0 at entry) +0x10.
  The `sd` at 0x291c stores 8 bytes to a0 (arg0 at entry) +0x8.
  The `sd` at 0x2924 stores 8 bytes to a0 (arg0 at entry) +0x20.
  The `sw` at 0x292c stores 4 bytes to a0 (arg0 at entry) +0x1bc.
  The `sw` at 0x2930 stores 4 bytes to a0 (arg0 at entry) +0x1b4.
  The `sw` at 0x2934 stores 4 bytes to a0 (arg0 at entry) +0x1b8.
  The `sw` at 0x2938 stores 4 bytes to a0 (arg0 at entry) +0x1b0.
  The `lw` at 0x293c loads 4 bytes from a1 (arg1 at entry) +0x268.
  The `sw` at 0x2954 stores 4 bytes to a0 (arg0 at entry) +0x1e0.
  The `sd` at 0x295c stores 8 bytes to a0 (arg0 at entry) +0x198.
  The `sw` at 0x2960 stores 4 bytes to a0 (arg0 at entry) +0x1f8.
  The `sd` at 0x2964 stores 8 bytes to a0 (arg0 at entry) +0x1f0.
  The `sw` at 0x296c stores 4 bytes to a0 (arg0 at entry) +0x21c.
  4 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x58, including `sd` at 0x2974, `sd` at 0x2aa0, `sd` at 0x2aec.
  4 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x60, including `sd` at 0x297c, `sd` at 0x2a98, `sd` at 0x2ae0.
  2 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x68, including `sd` at 0x2984, `sd` at 0x2a94.
  2 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x70, including `sd` at 0x298c, `sd` at 0x2a90.
  2 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x78, including `sd` at 0x2994, `sd` at 0x2a8c.
  The `sd` at 0x299c stores 8 bytes to a0 (arg0 at entry) +0x80.
  The `sd` at 0x29a0 stores 8 bytes to a0 (arg0 at entry) +0x88.
  3 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x20c, including `sw` at 0x29a8, `sw` at 0x2adc, `sw` at 0x2af0.
  The `sd` at 0x29b4 stores 8 bytes to a0 (arg0 at entry) +0x1e8.
  The `lw` at 0x29f4 loads 4 bytes from a0 (arg0 at entry) +0x208.
  The `sw` at 0x2a0c stores 4 bytes to ([a1+672]:8 + ([a0+520] << 0x2)) +0x72cc.
  4 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x208, including `sw` at 0x2a84, `sw` at 0x2a88, `sw` at 0x2abc.
  2 such `lh` accesses load 2 bytes from [a1+672]:8 +0x21a, including `lh` at 0x2aa4, `lh` at 0x2ac0.
  The `jal` at 0x2898 calls sprintf with a0=sp-112, a1=sym(.rodata), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x28ac calls sprintf with a0=sp-80, a1=sym(.rodata), a2=a2 at entry (arg2), a3=?.
  The `jal` at 0x28d0 calls kdsp_init_resource with a0=a0 at entry (arg0), a1=0x20000004, a2=sp-112, a3=sp-80, a4=[a1+672]:8, a5=0x0, a6=0x228.
  The `jal` at 0x2a1c calls kdsp_select_clockgen with a0=a1 at entry (arg1), a1=a0 at entry (arg0), a2=[a1+672]:8+2072, a3=[a1+672]:8+1624, a4=0x5.
  The `jal` at 0x2a30 calls kdsp_add_subresource with a0=a0 at entry (arg0), a1=a3 at entry (arg3), a2=?, a3=?.
  The `jal` at 0x2a4c calls rad_set_clockgen with a0=a0 at entry (arg0), a1=a3 at entry (arg3), a2=0x4, a3=0x0, a4=0x1, a5=0x1.
  The `jal` at 0x2a58 calls rad_start_clockgen with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x2a64 calls kdsp_map_resource with a0=a0 at entry (arg0), a1=0x0, a2=?, a3=?.
  The `beq` branch at 0x29b0 targets 0x2a80, is taken when s1(=a2) == 0, and falls through when s1(=a2) != 0.
  The `beq` branch at 0x29b8 targets 0x2a88, is taken when s1(=a2) == a1(=0x1), and falls through when s1(=a2) != a1(=0x1).
  The `beq` branch at 0x29c0 targets 0x2aa4, is taken when s1(=a2) == t0(=0x2), and falls through when s1(=a2) != t0(=0x2).
  The `beq` branch at 0x29c8 targets 0x2ac0, is taken when s1(=a2) == t1(=0x3), and falls through when s1(=a2) != t1(=0x3).
  The `beq` branch at 0x29d0 targets 0x2adc, is taken when s1(=a2) == a5(=0x4), and falls through when s1(=a2) != a5(=0x4).
  The `beq` branch at 0x29d8 targets 0x2af0, is taken when s1(=a2) == a4(=0x5), and falls through when s1(=a2) != a4(=0x5).
  The `beq` branch at 0x29e0 targets 0x2a10, is taken when a0(=one of 0x0, 0x1) == 0, and falls through when a0(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x2a80 targets 0x29e0 and is always taken.
  The `beq` branch at 0x2a9c targets 0x29e0 and is always taken.
  The `beq` branch at 0x2ab8 targets 0x29e0 and is always taken.
  The `beq` branch at 0x2ad4 targets 0x29e0 and is always taken.
  The `beq` branch at 0x2ae8 targets 0x29e0 and is always taken.
  The `beq` branch at 0x2af8 targets 0x2a10 and is always taken.
  The return at 0x2a78 has v0 = 0x1.

- `rad_destroy_devices` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x2b00 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x2b00-0x2cf0 (496 bytes).
  It occupies 496 bytes.
  The `ld` at 0x2b10 loads 8 bytes from a0 (arg0 at entry) +0xff8.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x1310, including `ld` at 0x2b28, `ld` at 0x2c7c.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x1628, including `ld` at 0x2b34, `ld` at 0x2c8c.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x1940, including `ld` at 0x2b40, `ld` at 0x2c9c.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x1c58, including `ld` at 0x2b4c, `ld` at 0x2cac.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x1f70, including `ld` at 0x2b58, `ld` at 0x2cbc.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x2288, including `ld` at 0x2b64, `ld` at 0x2ccc.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x25a0, including `ld` at 0x2b70, `ld` at 0x2cdc.
  The `jal` at 0x2b88 calls kdsp_destroy_subcode with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x2b98 calls kdsp_destroy_subcode with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x2bf4 calls kdsp_destroy_subcode with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x2c04 calls kdsp_destroy_subcode with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x2c70 calls kdsp_destroy_device with a0=a0+3416, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x2c80 calls kdsp_destroy_device with a0=a0+4208, a1=?, a2=?, a3=?.
  The `jal` at 0x2c90 calls kdsp_destroy_device with a0=a0+5000, a1=?, a2=?, a3=?.
  The `jal` at 0x2ca0 calls kdsp_destroy_device with a0=a0+5792, a1=?, a2=?, a3=?.
  The `jal` at 0x2cb0 calls kdsp_destroy_device with a0=a0+6584, a1=[a0+7256]:8, a2=?, a3=?.
  The `jal` at 0x2cc0 calls kdsp_destroy_device with a0=a0+7376, a1=?, a2=[a0+8048]:8, a3=?.
  The `jal` at 0x2cd0 calls kdsp_destroy_device with a0=a0+8168, a1=?, a2=?, a3=[a0+8840]:8.
  The `jal` at 0x2ce0 calls kdsp_destroy_device with a0=a0+8960, a1=?, a2=?, a3=?, a4=[a0+9632]:8.
  The `bne` branch at 0x2b20 targets 0x2c70, is taken when at(=[a0+4088]:8) != 0, and falls through when at(=[a0+4088]:8) == 0.
  The `bne` branch at 0x2b2c targets 0x2c80, is taken when v0(=[a0+4880]:8) != 0, and falls through when v0(=[a0+4880]:8) == 0.
  The `bne` branch at 0x2b38 targets 0x2c90, is taken when v1(=[a0+5672]:8) != 0, and falls through when v1(=[a0+5672]:8) == 0.
  The `bne` branch at 0x2b44 targets 0x2ca0, is taken when a0(=[a0+6464]:8) != 0, and falls through when a0(=[a0+6464]:8) == 0.
  The `bne` branch at 0x2b50 targets 0x2cb0, is taken when a1(=[a0+7256]:8) != 0, and falls through when a1(=[a0+7256]:8) == 0.
  The `bne` branch at 0x2b5c targets 0x2cc0, is taken when a2(=[a0+8048]:8) != 0, and falls through when a2(=[a0+8048]:8) == 0.
  The `bne` branch at 0x2b68 targets 0x2cd0, is taken when a3(=[a0+8840]:8) != 0, and falls through when a3(=[a0+8840]:8) == 0.
  The `bne` branch at 0x2b74 targets 0x2ce0, is taken when a4(=[a0+9632]:8) != 0, and falls through when a4(=[a0+9632]:8) == 0.
  The `beq` branch at 0x2b80 targets 0x2bac and is always taken.
  The `beq` branch at 0x2b90 targets 0x2ba0, is taken when s3(=-0x52a0) == s1(?), and falls through when s3(=-0x52a0) != s1(?).
  The `beq` branch at 0x2ba8 targets 0x2be4, is taken when s2(?) >= 0x3 (signed), and falls through when s2(?) < 0x3 (signed).
  The `bne` branch at 0x2bc4 targets 0x2b88, is taken when s4(=-0x5168) != s1(?), and falls through when s4(=-0x5168) == s1(?).
  The `bne` branch at 0x2bcc targets 0x2b98, is taken when s3(=-0x52a0) != s1(?), and falls through when s3(=-0x52a0) == s1(?).
  The `bne` branch at 0x2bdc targets 0x2bb0, is taken when s2(?) < 0x3 (signed), and falls through when s2(?) >= 0x3 (signed).
  The `beq` branch at 0x2bec targets 0x2c18 and is always taken.
  The `beq` branch at 0x2bfc targets 0x2c0c, is taken when s3(=-0x5578) == s1(?), and falls through when s3(=-0x5578) != s1(?).
  The `beq` branch at 0x2c14 targets 0x2c50, is taken when s2(?) >= 0x4 (signed), and falls through when s2(?) < 0x4 (signed).
  The `bne` branch at 0x2c30 targets 0x2bf4, is taken when s4(=-0x53d8) != s1(?), and falls through when s4(=-0x53d8) == s1(?).
  The `bne` branch at 0x2c38 targets 0x2c04, is taken when s3(=-0x5578) != s1(?), and falls through when s3(=-0x5578) == s1(?).
  The `bne` branch at 0x2c48 targets 0x2c1c, is taken when s2(?) < 0x4 (signed), and falls through when s2(?) >= 0x4 (signed).
  The `beq` branch at 0x2c78 targets 0x2b2c and is always taken.
  The `beq` branch at 0x2c88 targets 0x2b38 and is always taken.
  The `beq` branch at 0x2c98 targets 0x2b44 and is always taken.
  The `beq` branch at 0x2ca8 targets 0x2b50 and is always taken.
  The `beq` branch at 0x2cb8 targets 0x2b5c and is always taken.
  The `beq` branch at 0x2cc8 targets 0x2b68 and is always taken.
  The `beq` branch at 0x2cd8 targets 0x2b74 and is always taken.
  The `beq` branch at 0x2ce8 targets 0x2b7c and is always taken.
  The return at 0x2c68 has v0 = one of ret(kdsp_destroy_subcode), ?.

- `rad_init_subsys` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x2cf0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x2cf0-0x2d60 (112 bytes).
  It occupies 112 bytes.
  The `sd` at 0x2d14 stores 8 bytes to a0 (arg0 at entry) +0x240.
  The `sb` at 0x2d28 stores 1 byte to a0 (arg0 at entry) +0x7303.
  The `lh` at 0x2d2c loads 2 bytes from a0 (arg0 at entry) +0x21a.
  The `sw` at 0x2d30 stores 4 bytes to a0 (arg0 at entry) +0x72c8.
  The `sw` at 0x2d38 stores 4 bytes to a0 (arg0 at entry) +0x230.
  The `sw` at 0x2d44 stores 4 bytes to a0 (arg0 at entry) +0x234.
  The `sb` at 0x2d5c stores 1 byte to a0 (arg0 at entry) +0x7304.
  The `jal` at 0x2d08 calls kvpalloc with a0=0x1, a1=0x0, a2=0x0, a3=a3 at entry (arg3).
  The `jal` at 0x2d18 calls bzero with a0=ret(kvpalloc), a1=0x4000, a2=?, a3=?.
  The `beq` branch at 0x2d40 targets 0x2d58, is taken when v0(=[a0+538]:2) == v1(=0x7), and falls through when v0(=[a0+538]:2) != v1(=0x7).
  The `beq` branch at 0x2d58 targets 0x2d48 and is always taken.
  The return at 0x2d50 has v0 = 0x1.

- `rad_update_subsys` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x2d60 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x2d60-0x3220 (1216 bytes).
  It occupies 1216 bytes.
  The `lw` at 0x2d6c loads 4 bytes from a0 (arg0 at entry) +0x230.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x238, including `lw` at 0x2d84, `lw` at 0x2e44, `lw` at 0x3140.
  4 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x2c8, including `lw` at 0x2d90, `lw` at 0x311c, `lw` at 0x31b4.
  7 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x240, including `ld` at 0x2dbc, `ld` at 0x2de4, `ld` at 0x2e14.
  5 such `lw` accesses load 4 bytes from ?, including `lw` at 0x2dc4, `lw` at 0x2dd8, `lw` at 0x2dec.
  2 such `sw` accesses store 4 bytes to ?, including `sw` at 0x2de0, `sw` at 0x3104.
  The `ll` at 0x2dfc loads 4 bytes from a0 (arg0 at entry) +0x2d0.
  The `sc` at 0x2e08 stores 4 bytes to a0 (arg0 at entry) +0x2d0.
  The `ll` at 0x2e2c loads 4 bytes from a0 (arg0 at entry) +0x2cc.
  The `sc` at 0x2e38 stores 4 bytes to a0 (arg0 at entry) +0x2cc.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x72f0, including `lw` at 0x2e68, `lw` at 0x2fbc.
  The `sw` at 0x2e78 stores 4 bytes to a0 (arg0 at entry) +0x72f0.
  The `sb` at 0x2e90 stores 1 byte to a0 (arg0 at entry) +0x730e.
  The `sb` at 0x2e94 stores 1 byte to a0 (arg0 at entry) +0x730f.
  2 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x7310, including `lbu` at 0x2e98, `lbu` at 0x2f18.
  The `lw` at 0x2e9c loads 4 bytes from a0 (arg0 at entry) +0x2b0.
  The `lw` at 0x2ea0 loads 4 bytes from a0 (arg0 at entry) +0x7238.
  The `lw` at 0x2ea4 loads 4 bytes from a0 (arg0 at entry) +0x2a8.
  2 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x7311, including `lbu` at 0x2ea8, `lbu` at 0x2f60.
  3 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x7313, including `sb` at 0x2eac, `sb` at 0x2f8c, `sb` at 0x2f94.
  The `lw` at 0x2eb4 loads 4 bytes from a0 (arg0 at entry) +0x723c.
  3 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x7312, including `sb` at 0x2eb8, `sb` at 0x30d8, `sb` at 0x30e4.
  The `sw` at 0x2ec8 stores 4 bytes to a0 (arg0 at entry) +0x7238.
  The `sw` at 0x2ed8 stores 4 bytes to a0 (arg0 at entry) +0x723c.
  The `lbu` at 0x2efc loads 1 byte from a0 (arg0 at entry) +0x7314.
  The `sb` at 0x2f14 stores 1 byte to a0 (arg0 at entry) +0x7314.
  The `lbu` at 0x2f44 loads 1 byte from a0 (arg0 at entry) +0x7316.
  The `sb` at 0x2f5c stores 1 byte to a0 (arg0 at entry) +0x7316.
  The `lbu` at 0x2f74 loads 1 byte from a0 (arg0 at entry) +0x7317.
  2 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x7311, including `sb` at 0x2f80, `sb` at 0x2f90.
  The `lbu` at 0x2fc8 loads 1 byte from a0 (arg0 at entry) +0x7303.
  The `ld` at 0x2fe4 loads 8 bytes from a0 (arg0 at entry) +0x72e0.
  The `lw` at 0x2ff4 loads 4 bytes from a0 (arg0 at entry) +0x2d0.
  The `lw` at 0x2ff8 loads 4 bytes from a0 (arg0 at entry) +0x2cc.
  The `ld` at 0x3004 loads 8 bytes from a0 (arg0 at entry) +0x72e8.
  2 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x72e8, including `sd` at 0x3018, `sd` at 0x3198.
  The `lh` at 0x3038 loads 2 bytes from a0 (arg0 at entry) +0x21a.
  The `sw` at 0x303c stores 4 bytes to a0 (arg0 at entry) +0x2d0.
  The `sw` at 0x3044 stores 4 bytes to a0 (arg0 at entry) +0x2cc.
  The `sd` at 0x3050 stores 8 bytes to a0 (arg0 at entry) +0x72e0.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x2bc, including `lw` at 0x3060, `lw` at 0x3088, `lw` at 0x3150.
  2 such `sb` accesses store 1 byte to ?, including `sb` at 0x307c, `sb` at 0x30a8.
  The `lbu` at 0x30bc loads 1 byte from a0 (arg0 at entry) +0x7315.
  2 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x7310, including `sb` at 0x30cc, `sb` at 0x30dc.
  2 such `lw` accesses load 4 bytes from ([a0+576]:8 + ([a0+712] << 0x7)) +0x7c, including `lw` at 0x3134, `lw` at 0x31c4.
  2 such `sw` accesses store 4 bytes to ([a0+576]:8 + ([a0+712] << 0x7)) +0x7c, including `sw` at 0x313c, `sw` at 0x31cc.
  The `sw` at 0x3144 stores 4 bytes to a0 (arg0 at entry) +0x2c8.
  2 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x7304, including `lbu` at 0x3154, `lbu` at 0x3168.
  The `sb` at 0x3164 stores 1 byte to ([a0+29444]:1 + a0) +0x7305.
  The `ld` at 0x317c loads 8 bytes from a0 (arg0 at entry) +0x228.
  The `sw` at 0x3184 stores 4 bytes to a0 (arg0 at entry) +0x726c.
  The `sw` at 0x318c stores 4 bytes to [a0+552]:8 +0x8c.
  2 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x7304, including `sb` at 0x31a4, `sb` at 0x31b0.
  The `lw` at 0x31f4 loads 4 bytes from a0 (arg0 at entry) +0x731c.
  The `jal` at 0x2e7c calls rad_check_adat_rx with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x2e88 calls rad_process_aesrx_subcode with a0=a0 at entry (arg0), a1=0x0, a2=?, a3=?.
  The `jal` at 0x2ef4 calls kdsp_update_default_subcode with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x2f3c calls kdsp_update_default_subcode with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x2f88 calls rad_pio_writeback_subcode_tx with a0=a0+17672, a1=[a0+29457]:1, a2=?, a3=0x1.
  The `jal` at 0x2fd4 calls update_ust with a0=?, a1=?, a2=?, a3=?, a5=[a0+29443]:1.
  The `jal` at 0x2fdc calls get_ust_nano with a0=sp-64, a1=?, a2=?, a3=?.
  The `jal` at 0x302c calls rad_update_ksync with a0=a0 at entry (arg0), a1=?, a2=?, a3=([a0+716] + [a0+720]), a4=[a0+29416]:8, a6=[a0+29408]:8.
  The `jal` at 0x30d4 calls rad_pio_writeback_subcode_tx with a0=a0+12128, a1=[a0+29456]:1, a2=?, a3=?.
  The `jal` at 0x3114 calls bcopy with a0=?, a1=a0+584, a2=0x80, a3=?, a6=[a0+576]:8, a7=a0+720.
  The `jal` at 0x31e4 calls bcopy with a0=([a0+576]:8 + ([a0+712] << 0x7)), a1=a0+584, a2=0x80, a3=([a0+712] << 0x7), a4=(0xffffffff80000000 | [([a0+576]:8 + ([a0+712] << 0x7))+124]), a5=([a0+576]:8 + ([a0+712] << 0x7)), a6=[a0+576]:8.
  The `jal` at 0x31f8 calls cmn_err with a0=0x1, a1=sym(.rodata), a2=[a0+29468], a3=?.
  The `jal` at 0x3200 calls rad_stop_status_dma with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x3208 calls rad_start_status_dma with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `beq` branch at 0x2d7c targets 0x2f98, is taken when at(=[a0+560]) == 0, and falls through when at(=[a0+560]) != 0.
  The `bne` branch at 0x2d8c targets 0x2fb4, is taken when a0(=[a0+568]) < 0x2 (signed), and falls through when a0(=[a0+568]) >= 0x2 (signed).
  The `beq` branch at 0x2dd0 targets 0x30e8, is taken when (s2(=0xffffffff80000000) & t8(?)) == 0, and falls through when (s2(=0xffffffff80000000) & t8(?)) != 0.
  The `beq` branch at 0x2df4 targets 0x2e1c, is taken when (a6(?) & 0x100) == 0, and falls through when (a6(?) & 0x100) != 0.
  The `beql` branch at 0x2e0c targets 0x2dfc, is taken when a4(=[a0+720]+1) == 0, and falls through when a4(=[a0+720]+1) != 0; its branch-likely delay slot `nop` at 0x2e10 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x2e24 targets 0x2e44, is taken when (a6(?) & 0x80) == 0, and falls through when (a6(?) & 0x80) != 0.
  The `beql` branch at 0x2e3c targets 0x2e2c, is taken when t2(=[a0+716]+1) == 0, and falls through when t2(=[a0+716]+1) != 0; its branch-likely delay slot `nop` at 0x2e40 runs only when taken and is annulled on fall-through.
  The `bne` branch at 0x2e58 targets 0x2dbc, is taken when s1(?) < a4(=[a0+568]-1) (signed), and falls through when s1(?) >= a4(=[a0+568]-1) (signed).
  The `beq` branch at 0x2e60 targets 0x31b4, is taken when a4(=[a0+568]-1) == s1(?), and falls through when a4(=[a0+568]-1) != s1(?).
  The `beq` branch at 0x2e74 targets 0x2fc8, is taken when (a5(=[a0+29424]+1) & 0x3ff) == 0, and falls through when (a5(=[a0+29424]+1) & 0x3ff) != 0.
  The `bne` branch at 0x2f10 targets 0x2edc, is taken when s1(?) < 0x3 (signed), and falls through when s1(?) >= 0x3 (signed).
  The `beq` branch at 0x2f1c targets 0x30b4, is taken when a1(=[a0+29456]:1) == 0, and falls through when a1(=[a0+29456]:1) != 0.
  The `bne` branch at 0x2f58 targets 0x2f24, is taken when s1(?) < 0x4 (signed), and falls through when s1(?) >= 0x4 (signed).
  The `bne` branch at 0x2f64 targets 0x2f9c, is taken when a1(=[a0+29457]:1) != 0, and falls through when a1(=[a0+29457]:1) == 0.
  The `bne` branch at 0x2f6c targets 0x2f80, is taken when a0(?) != 0, and falls through when a0(?) == 0.
  The `beq` branch at 0x2f78 targets 0x2f98, is taken when a2(=[a0+29463]:1) == 0, and falls through when a2(=[a0+29463]:1) != 0.
  The `bnel` branch at 0x2fb8 targets 0x2e6c, is taken when a0(=[a0+568]) != a4(=0x1), and falls through when a0(=[a0+568]) == a4(=0x1); its branch-likely delay slot `lw a5,29424(s0)` at 0x2fbc runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x2fc0 targets 0x3218 and is always taken.
  The `beq` branch at 0x2fcc targets 0x2e7c, is taken when a5(=[a0+29443]:1) == 0, and falls through when a5(=[a0+29443]:1) != 0.
  The `beq` branch at 0x2fec targets 0x3034, is taken when a6(=[a0+29408]:8) == 0, and falls through when a6(=[a0+29408]:8) != 0.
  The `blez` branch at 0x3000 targets 0x3190, is taken when a3(=([a0+716] + [a0+720])) <= 0 (signed), and falls through when a3(=([a0+716] + [a0+720])) > 0 (signed).
  The `bgtz` branch at 0x301c targets 0x302c, is taken when a0(?) > 0 (signed), and falls through when a0(?) <= 0 (signed).
  The `blez` branch at 0x3024 targets 0x3038, is taken when a4(=[a0+29416]:8) <= 0 (signed), and falls through when a4(=[a0+29416]:8) > 0 (signed).
  The `beq` branch at 0x304c targets 0x3150, is taken when a0(=[a0+538]:2) == a6(=0x7), and falls through when a0(=[a0+538]:2) != a6(=0x7).
  The `bne` branch at 0x3058 targets 0x2e7c, is taken when a0(=[a0+538]:2) != a7(=0xd), and falls through when a0(=[a0+538]:2) == a7(=0xd).
  The `beq` branch at 0x3080 targets 0x2e7c, is taken when a0(?) >= 0x4 (signed), and falls through when a0(?) < 0x4 (signed).
  The `bne` branch at 0x30a4 targets 0x3060, is taken when a0(?) < 0x4 (signed), and falls through when a0(?) >= 0x4 (signed).
  The `beq` branch at 0x30ac targets 0x2e7c and is always taken.
  The `bne` branch at 0x30b4 targets 0x30cc, is taken when a0(?) != 0, and falls through when a0(?) == 0.
  The `beq` branch at 0x30c0 targets 0x2f24, is taken when t3(=[a0+29461]:1) == 0, and falls through when t3(=[a0+29461]:1) != 0.
  The `beq` branch at 0x30e0 targets 0x2f20 and is always taken.
  The `beq` branch at 0x3124 targets 0x3140, is taken when a0(?) == a5(=[a0+712]), and falls through when a0(?) != a5(=[a0+712]).
  The `beq` branch at 0x3148 targets 0x2e60 and is always taken.
  The `beq` branch at 0x316c targets 0x319c, is taken when a0(=[a0+29444]:1) == 0, and falls through when a0(=[a0+29444]:1) != 0.
  The `beq` branch at 0x3174 targets 0x31a8, is taken when a0(=[a0+29444]:1) == a2(=0x1), and falls through when a0(=[a0+29444]:1) != a2(=0x1).
  The `beq` branch at 0x3188 targets 0x2e7c and is always taken.
  The `beq` branch at 0x3194 targets 0x301c and is always taken.
  The `beq` branch at 0x31a0 targets 0x317c and is always taken.
  The `beq` branch at 0x31ac targets 0x317c and is always taken.
  The `beq` branch at 0x3210 targets 0x2f9c and is always taken.
  The `beq` branch at 0x3218 targets 0x31b8 and is always taken.
  The return at 0x2fac has v0 = one of ret(kdsp_update_default_subcode), ?, ret(rad_start_status_dma).

- `rad_start_status_dma` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x3220 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x3220-0x33ac (396 bytes).
  It occupies 396 bytes.
  The `lw` at 0x3220 loads 4 bytes from a0 (arg0 at entry) +0x230.
  3 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x238, including `sw` at 0x3244, `sw` at 0x3270, `sw` at 0x3398.
  5 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x240, including `ld` at 0x327c, `ld` at 0x32a0, `ld` at 0x32cc.
  2 such `sw` accesses store 4 bytes to ?, including `sw` at 0x3288, `sw` at 0x32ac.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x238, including `lw` at 0x328c, `lw` at 0x32b0, `lw` at 0x3300.
  7 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x228, including `ld` at 0x3304, `ld` at 0x3318, `ld` at 0x3320.
  The `sw` at 0x3314 stores 4 bytes to [a0+552]:8 +0x504.
  The `sw` at 0x331c stores 4 bytes to [a0+552]:8 +0x500.
  The `sw` at 0x3328 stores 4 bytes to [a0+552]:8 +0x528.
  The `sw` at 0x3330 stores 4 bytes to [a0+552]:8 +0x4bc.
  The `sw` at 0x3338 stores 4 bytes to [a0+552]:8 +0x4b4.
  The `sw` at 0x3340 stores 4 bytes to [a0+552]:8 +0x4b8.
  The `lw` at 0x3344 loads 4 bytes from a0 (arg0 at entry) +0x234.
  The `sw` at 0x336c stores 4 bytes to [a0+552]:8 +0x5c.
  The `sw` at 0x3370 stores 4 bytes to a0 (arg0 at entry) +0x2c8.
  The `sw` at 0x337c stores 4 bytes to a0 (arg0 at entry) +0x230.
  The `jal` at 0x32c8 calls rad_one_shot_status with a0=a0 at entry (arg0), a1=[a0+576]:8, a2=?, a3=?.
  The `jal` at 0x32e8 calls bcopy with a0=[a0+576]:8, a1=a0+584, a2=0x80, a3=?.
  The `jal` at 0x32f8 calls Mem_to_PCI_DMA with a0=a0 at entry (arg0), a1=[a0+576]:8, a2=0x1000, a3=?.
  The `jal` at 0x339c calls us_delay with a0=0x12c, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=0x1, a4=0x80.
  The `bne` branch at 0x3238 targets 0x339c, is taken when at(=[a0+560]) != 0, and falls through when at(=[a0+560]) == 0.
  The `beq` branch at 0x3250 targets 0x3268, is taken when v0(?) >= 0x80 (signed), and falls through when v0(?) < 0x80 (signed).
  The `bne` branch at 0x3260 targets 0x3248, is taken when v0(?) < 0x80 (signed), and falls through when v0(?) >= 0x80 (signed).
  The `beq` branch at 0x326c targets 0x3394, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `blez` branch at 0x3274 targets 0x32c4, is taken when v0(?) <= 0 (signed), and falls through when v0(?) > 0 (signed).
  The `beq` branch at 0x3298 targets 0x32c4, is taken when v0(?) >= a2(=[a0+568]) (signed), and falls through when v0(?) < a2(=[a0+568]) (signed).
  The `bne` branch at 0x32bc targets 0x327c, is taken when v0(?) < a5(=[a0+568]) (signed), and falls through when v0(?) >= a5(=[a0+568]) (signed).
  The `bne` branch at 0x32d0 targets 0x32e4, is taken when v0(=ret(rad_one_shot_status)) != 0, and falls through when v0(=ret(rad_one_shot_status)) == 0.
  The `beq` branch at 0x32dc targets 0x3384 and is always taken.
  The `beq` branch at 0x3394 targets 0x3380 and is always taken.
  The `beq` branch at 0x33a4 targets 0x3380 and is always taken.
  The return at 0x338c has v0 = one of 0x0, 0x1.

- `rad_stop_status_dma` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x33ac (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x33ac-0x33d8 (44 bytes).
  It occupies 44 bytes.
  The `lw` at 0x33ac loads 4 bytes from a0 (arg0 at entry) +0x230.
  The `ld` at 0x33b8 loads 8 bytes from a0 (arg0 at entry) +0x228.
  The `sw` at 0x33c4 stores 4 bytes to [a0+552]:8 +0x5c.
  The `sw` at 0x33cc stores 4 bytes to a0 (arg0 at entry) +0x230.
  The `beq` branch at 0x33b0 targets 0x33d0, is taken when at(=[a0+560]) == 0, and falls through when at(=[a0+560]) != 0.
  The return at 0x33d0 has v0 = 0x1.

- `rad_sync_device_ust` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x33d8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x33d8-0x3510 (312 bytes).
  It occupies 312 bytes.
  The `ld` at 0x3400 loads 8 bytes from a0 (arg0 at entry) +0x2a0.
  The `ld` at 0x342c loads 8 bytes from [a0+672]:8 +0x72a8.
  6 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x1b0, including `sd` at 0x3470, `sd` at 0x3480, `sd` at 0x34ac.
  The `lw` at 0x3484 loads 4 bytes from a0 (arg0 at entry) +0x314.
  The `sw` at 0x34d4 stores 4 bytes to a0 (arg0 at entry) +0x310.
  The `jal` at 0x33fc calls update_ust with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x3404 calls get_ust_nano with a0=sp-48, a1=?, a2=?, a3=?.
  The `beq` branch at 0x346c targets 0x34e4, is taken when at(?) == 0, and falls through when at(?) != 0.
  The `beq` branch at 0x3474 targets 0x3484, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0x3488 targets 0x34cc, is taken when t0(=[a0+788]) == 0, and falls through when t0(=[a0+788]) != 0.
  The `bltz` branch at 0x34b0 targets 0x3500, is taken when t1(?) < 0 (signed), and falls through when t1(?) >= 0 (signed).
  The `beq` branch at 0x34bc targets 0x34d0, is taken when s1(=a2) >= a2(?) (unsigned), and falls through when s1(=a2) < a2(?) (unsigned).
  The `beq` branch at 0x34ec targets 0x3484, is taken when s2(=a1) >= a5(?) (unsigned), and falls through when s2(=a1) < a5(?) (unsigned).
  The `beq` branch at 0x34f8 targets 0x3484 and is always taken.
  The `beq` branch at 0x3500 targets 0x34d0, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `beq` branch at 0x3508 targets 0x34cc and is always taken.
  The return at 0x34dc has v0 = ret(get_ust_nano).

- `rad_start_dma` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x3510 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x3510-0x39cc (1212 bytes).
  It occupies 1212 bytes.
  The `ld` at 0x3518 loads 8 bytes from a0 (arg0 at entry) +0x2a0.
  4 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x2c0, including `lw` at 0x3520, `lw` at 0x36e4, `lw` at 0x3788.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x268, including `lw` at 0x3548, `lw` at 0x35a4.
  The `lw` at 0x3558 loads 4 bytes from a0 (arg0 at entry) +0x238.
  The `lbu` at 0x3578 loads 1 byte from ([a0+672]:8 + one of 0x225c, 0x2574) +0x0.
  4 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x1b8, including `ld` at 0x359c, `ld` at 0x35d0, `ld` at 0x3634.
  The `sw` at 0x35a0 stores 4 bytes to [a0+440]:8 +0x0.
  The `lw` at 0x35ac loads 4 bytes from a0 (arg0 at entry) +0x220.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x1c8, including `ld` at 0x35b0, `ld` at 0x3658.
  The `ld` at 0x35bc loads 8 bytes from a0 (arg0 at entry) +0x1f0.
  The `lw` at 0x35c0 loads 4 bytes from a0 (arg0 at entry) +0x23c.
  The `lw` at 0x35c4 loads 4 bytes from [a0+496]:8 +0x1d8.
  2 such `sw` accesses store 4 bytes to [a0+440]:8 +0x4, including `sw` at 0x35d4, `sw` at 0x3648.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0x35e0, `lw` at 0x35e8.
  5 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x314, including `sw` at 0x35e4, `sw` at 0x37ec, `sw` at 0x3860.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x310, including `sw` at 0x35ec, `sw` at 0x3948.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0x35f0, `ld` at 0x35f8.
  2 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x308, including `sd` at 0x35f4, `sd` at 0x3904.
  2 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x1a8, including `sd` at 0x35fc, `sd` at 0x38f4.
  The `sb` at 0x3600 stores 1 byte to a0 (arg0 at entry) +0x274.
  The `lw` at 0x3604 loads 4 bytes from [a0+672]:8 +0x72c8.
  The `sw` at 0x3610 stores 4 bytes to [a0+672]:8 +0x72c8.
  The `ld` at 0x364c loads 8 bytes from a0 (arg0 at entry) +0x1d0.
  The `ld` at 0x3650 loads 8 bytes from a0 (arg0 at entry) +0x1e0.
  12 such `ld` accesses load 8 bytes from [a0+672]:8 +0x228, including `ld` at 0x3664, `ld` at 0x3674, `ld` at 0x3688.
  The `lwu` at 0x3668 loads 4 bytes from a0 (arg0 at entry) +0x2cc.
  The `sw` at 0x3670 stores 4 bytes to ([a0+716] + [[a0+672]:8+552]:8) +0x0.
  The `lwu` at 0x3678 loads 4 bytes from a0 (arg0 at entry) +0x2c8.
  The `sw` at 0x3684 stores 4 bytes to ([a0+712] + [[a0+672]:8+552]:8) +0x0.
  The `lw` at 0x368c loads 4 bytes from a0 (arg0 at entry) +0x2f0.
  The `lw` at 0x3690 loads 4 bytes from a0 (arg0 at entry) +0x2e0.
  The `lwu` at 0x3694 loads 4 bytes from a0 (arg0 at entry) +0x2d0.
  The `sw` at 0x36b0 stores 4 bytes to ([a0+720] + [[a0+672]:8+552]:8) +0x0.
  The `lwu` at 0x36b8 loads 4 bytes from a0 (arg0 at entry) +0x2d8.
  The `sw` at 0x36c0 stores 4 bytes to ([a0+728] + [[a0+672]:8+552]:8) +0x0.
  The `lwu` at 0x36c8 loads 4 bytes from a0 (arg0 at entry) +0x2d4.
  The `sw` at 0x36d0 stores 4 bytes to ([a0+724] + [[a0+672]:8+552]:8) +0x0.
  The `lwu` at 0x36d8 loads 4 bytes from a0 (arg0 at entry) +0x2dc.
  The `sw` at 0x36e0 stores 4 bytes to ([a0+732] + [[a0+672]:8+552]:8) +0x0.
  2 such `lh` accesses load 2 bytes from table(sym(.data)) +0x0, including `lh` at 0x3704, `lh` at 0x37d4.
  2 such `lh` accesses load 2 bytes from table(sym(.data)) +0x8, including `lh` at 0x3708, `lh` at 0x37a0.
  2 such `lw` accesses load 4 bytes from table(sym(.data)) +0xc, including `lw` at 0x370c, `lw` at 0x37c0.
  2 such `lh` accesses load 2 bytes from table(sym(.data)) +0xa, including `lh` at 0x3714, `lh` at 0x37ac.
  The `lh` at 0x3724 loads 2 bytes from table(sym(.data)) +0x2.
  2 such `lw` accesses load 4 bytes from ([[a0+672]:8+552]:8 + ([table(sym(.data))+8]:2 << 0x2)) -0x40, including `lw` at 0x3728, `lw` at 0x37b8.
  2 such `lw` accesses load 4 bytes from ([[a0+672]:8+552]:8 + (entry(sym(.data)) << 0x2)) -0x40, including `lw` at 0x3730, `lw` at 0x37e8.
  The `lw` at 0x3738 loads 4 bytes from table(sym(.data)) +0x4.
  4 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x2e8, including `ld` at 0x3800, `ld` at 0x3820, `ld` at 0x3874.
  4 such `lw` accesses load 4 bytes from [a0+744]:8 +0x0, including `lw` at 0x3808, `lw` at 0x3834, `lw` at 0x387c.
  2 such `sw` accesses store 4 bytes to [a0+744]:8 +0x0, including `sw` at 0x381c, `sw` at 0x3884.
  2 such `lwu` accesses load 4 bytes from a0 (arg0 at entry) +0x2e4, including `lwu` at 0x3828, `lwu` at 0x388c.
  2 such `sw` accesses store 4 bytes to ([a0+740] + [[a0+672]:8+552]:8) +0x0, including `sw` at 0x3840, `sw` at 0x38a4.
  The `ld` at 0x38bc loads 8 bytes from a0 (arg0 at entry) +0x1a8.
  The `lw` at 0x3920 loads 4 bytes from [[a0+672]:8+552]:8 +0x30.
  The `sw` at 0x3930 stores 4 bytes to a0 (arg0 at entry) +0x2c4.
  The `lw` at 0x3958 loads 4 bytes from [a0+672]:8 +0x2c0.
  2 such `sb` accesses store 1 byte to [a0+672]:8 +0x7309, including `sb` at 0x3968, `sb` at 0x39a0.
  2 such `sb` accesses store 1 byte to [a0+672]:8 +0x800, including `sb` at 0x396c, `sb` at 0x39a4.
  The `lw` at 0x3988 loads 4 bytes from [a0+672]:8 +0x7240.
  The `sw` at 0x3998 stores 4 bytes to [a0+672]:8 +0x7240.
  The `sw` at 0x399c stores 4 bytes to [[a0+672]:8+552]:8 +0x80.
  The `lw` at 0x39b8 loads 4 bytes from [a0+672]:8 +0x731c.
  The `jal` at 0x3584 calls rad_start_dma with a0=([a0+672]:8 + one of 0x1fe8, 0x2300), a1=0x7, a2=[([a0+672]:8 + one of 0x225c, 0x2574)]:1, a3=[a0+704].
  The `jal` at 0x35c8 calls bzero with a0=[a0+456]:8, a1=([a0+544] << 0x2), a2=?, a3=[a0+440]:8.
  The `jal` at 0x3638 calls bzero with a0=[a0+456]:8, a1=([a0+544] << 0x2), a2=?, a3=[a0+440]:8.
  The `jal` at 0x365c calls Mem_to_PCI_DMA with a0=[a0+672]:8, a1=[a0+456]:8, a2=?, a3=[a0+464]:8.
  The `jal` at 0x3780 calls us_delay with a0=0xa, a1=?, a2=?, a3=?, a5=sym(.data).
  The `jal` at 0x391c calls rad_sync_device_ust with a0=a0 at entry (arg0), a1=[[[a0+672]:8+552]:8+48], a2=?, a3=?, a6=[([[a0+672]:8+552]:8 + (entry(sym(.data)) << 0x2))-64].
  The `jal` at 0x392c calls rad_start_status_dma with a0=[a0+672]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x39bc calls cmn_err with a0=0x1, a1=sym(.rodata), a2=[[a0+672]:8+29468], a3=[a0+704].
  The `beq` branch at 0x3534 targets 0x39b0, is taken when a3(=[a0+704]) == at(=-0x2), and falls through when a3(=[a0+704]) != at(=-0x2).
  The `beq` branch at 0x3540 targets 0x39b4, is taken when a3(=[a0+704]) == v0(=-0x1), and falls through when a3(=[a0+704]) != v0(=-0x1).
  The `beq` branch at 0x3550 targets 0x3630, is taken when (v1(=[a0+616]) & 0x400) == 0, and falls through when (v1(=[a0+616]) & 0x400) != 0.
  The `beq` branch at 0x3560 targets 0x359c, is taken when a0(=[a0+568]) >= 0x20 (signed), and falls through when a0(=[a0+568]) < 0x20 (signed).
  The `beq` branch at 0x356c targets 0x3578, is taken when a3(=[a0+704]) == a1(=0x7), and falls through when a3(=[a0+704]) != a1(=0x7).
  The `bne` branch at 0x357c targets 0x359c, is taken when a2(=[([a0+672]:8 + one of 0x225c, 0x2574)]:1) != 0, and falls through when a2(=[([a0+672]:8 + one of 0x225c, 0x2574)]:1) == 0.
  The `bne` branch at 0x358c targets 0x359c, is taken when v0(=ret(rad_start_dma)) != 0, and falls through when v0(=ret(rad_start_dma)) == 0.
  The `beq` branch at 0x3594 targets 0x3614 and is always taken.
  The `beq` branch at 0x35b4 targets 0x3638, is taken when (a2(=[a0+616]) & 0x1) == 0, and falls through when (a2(=[a0+616]) & 0x1) != 0.
  The `beq` branch at 0x35d8 targets 0x364c, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `beq` branch at 0x3630 targets 0x35a0 and is always taken.
  The `beq` branch at 0x3644 targets 0x35d8 and is always taken.
  The `beq` branch at 0x3750 targets 0x3978, is taken when a3(=[a0+704]) == a1(=0x7), and falls through when a3(=[a0+704]) != a1(=0x7).
  The `beq` branch at 0x3758 targets 0x3978, is taken when a3(=[a0+704]) == a0(=0x6), and falls through when a3(=[a0+704]) != a0(=0x6).
  The `beq` branch at 0x3770 targets 0x37fc and is always taken.
  The `bne` branch at 0x3778 targets 0x37d4, is taken when t8(?) != a3(?), and falls through when t8(?) == a3(?).
  The `bne` branch at 0x37cc targets 0x3778, is taken when s2(?) < 0x32 (signed), and falls through when s2(?) >= 0x32 (signed).
  The `beq` branch at 0x37e4 targets 0x3844, is taken when s2(?) == a7(=0x32), and falls through when s2(?) != a7(=0x32).
  The `beq` branch at 0x37f4 targets 0x38bc, is taken when a7(=one of 0x0, 0x1) == 0, and falls through when a7(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x383c targets 0x3780 and is always taken.
  The `bne` branch at 0x3850 targets 0x3864, is taken when a0(?) != ra(?), and falls through when a0(?) == ra(?).
  The `beq` branch at 0x385c targets 0x38b0 and is always taken.
  The `beq` branch at 0x386c targets 0x38ac, is taken when at(?) >= 0x6 (signed), and falls through when at(?) < 0x6 (signed).
  The `beq` branch at 0x38b4 targets 0x37f0 and is always taken.
  The `beq` branch at 0x3934 targets 0x3980, is taken when v0(=ret(rad_start_status_dma)) == 0, and falls through when v0(=ret(rad_start_status_dma)) != 0.
  The `beq` branch at 0x3944 targets 0x3958, is taken when a3(=[a0+704]) == t1(=0x4), and falls through when a3(=[a0+704]) != t1(=0x4).
  The `bne` branch at 0x3950 targets 0x3600, is taken when a3(=[a0+704]) != t2(=0x7), and falls through when a3(=[a0+704]) == t2(=0x7).
  The `beq` branch at 0x3960 targets 0x3988, is taken when (t3(=[[a0+672]:8+704]) & 0x40) == 0, and falls through when (t3(=[[a0+672]:8+704]) & 0x40) != 0.
  The `beq` branch at 0x3970 targets 0x3600 and is always taken.
  The `beq` branch at 0x3978 targets 0x3760 and is always taken.
  The `beq` branch at 0x3980 targets 0x3614 and is always taken.
  The `beq` branch at 0x39a8 targets 0x3600 and is always taken.
  The `beq` branch at 0x39c4 targets 0x3614 and is always taken.
  The return at 0x3628 has v0 = one of 0x0, 0x1.

- `rad_start_subcode_tx` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x39cc (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x39cc-0x3b90 (452 bytes).
  It occupies 452 bytes.
  The `lbu` at 0x39d4 loads 1 byte from a0 (arg0 at entry) +0x274.
  The `ld` at 0x39d8 loads 8 bytes from a0 (arg0 at entry) +0x2a0.
  2 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x1b0, including `sd` at 0x39fc, `sd` at 0x3a98.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x1b8, including `ld` at 0x3a14, `ld` at 0x3a68.
  The `sw` at 0x3a18 stores 4 bytes to [a0+440]:8 +0x0.
  The `lw` at 0x3a1c loads 4 bytes from a0 (arg0 at entry) +0x220.
  The `ld` at 0x3a20 loads 8 bytes from a0 (arg0 at entry) +0x1c8.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x2e8, including `ld` at 0x3a2c, `ld` at 0x3a3c.
  2 such `lw` accesses load 4 bytes from [a0+744]:8 +0x0, including `lw` at 0x3a30, `lw` at 0x3a4c.
  The `sw` at 0x3a38 stores 4 bytes to [a0+744]:8 +0x0.
  3 such `ld` accesses load 8 bytes from [a0+672]:8 +0x228, including `ld` at 0x3a40, `ld` at 0x3b0c, `ld` at 0x3b6c.
  The `lwu` at 0x3a44 loads 4 bytes from a0 (arg0 at entry) +0x2e4.
  The `sw` at 0x3a50 stores 4 bytes to ([a0+740] + [[a0+672]:8+552]:8) +0x0.
  The `lw` at 0x3a54 loads 4 bytes from a0 (arg0 at entry) +0x268.
  The `lw` at 0x3a5c loads 4 bytes from a0 (arg0 at entry) +0x23c.
  The `sw` at 0x3a78 stores 4 bytes to [a0+440]:8 +0x4.
  The `ld` at 0x3a7c loads 8 bytes from a0 (arg0 at entry) +0x1a8.
  The `lw` at 0x3a80 loads 4 bytes from a0 (arg0 at entry) +0x2c0.
  2 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x1a8, including `sd` at 0x3ac8, `sd` at 0x3b48.
  The `lbu` at 0x3acc loads 1 byte from [a0+672]:8 +0x7311.
  The `sb` at 0x3ad4 stores 1 byte to [a0+672]:8 +0x7311.
  The `sw` at 0x3ae8 stores 4 bytes to a0 (arg0 at entry) +0x2c4.
  The `sb` at 0x3aec stores 1 byte to a0 (arg0 at entry) +0x274.
  The `lw` at 0x3af0 loads 4 bytes from [a0+672]:8 +0x72c8.
  The `sw` at 0x3b00 stores 4 bytes to [a0+672]:8 +0x72c8.
  The `lh` at 0x3b08 loads 2 bytes from sym(.data) +0x50.
  The `lh` at 0x3b14 loads 2 bytes from sym(.data) +0x52.
  The `lw` at 0x3b1c loads 4 bytes from ([[a0+672]:8+552]:8 + ([sym(.data)+80]:2 << 0x2)) -0x40.
  The `lw` at 0x3b20 loads 4 bytes from sym(.data) +0x54.
  The `lbu` at 0x3b4c loads 1 byte from [a0+672]:8 +0x7310.
  The `sb` at 0x3b58 stores 1 byte to [a0+672]:8 +0x7310.
  The `lh` at 0x3b68 loads 2 bytes from sym(.data) +0x80.
  The `lh` at 0x3b78 loads 2 bytes from sym(.data) +0x82.
  The `lw` at 0x3b7c loads 4 bytes from ([[a0+672]:8+552]:8 + ([sym(.data)+128]:2 << 0x2)) -0x40.
  The `lw` at 0x3b80 loads 4 bytes from sym(.data) +0x84.
  The `jal` at 0x39ec calls update_ust with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x3a24 calls bzero with a0=[a0+456]:8, a1=([a0+544] << 0x2), a2=[a0+440]:8, a3=a3 at entry (arg3).
  The `jal` at 0x3a74 calls update_ust with a0=?, a1=?, a2=?, a3=?, a4=[a0+440]:8, a5=[a0+572], a7=0x1.
  The `jal` at 0x3ad8 calls rad_start_status_dma with a0=[a0+672]:8, a1=?, a2=?, a3=?, a5=-0x1.
  The `beq` branch at 0x39e4 targets 0x3a14, is taken when at(=[a0+628]:1) == 0, and falls through when at(=[a0+628]:1) != 0.
  The `beq` branch at 0x3a9c targets 0x3b04, is taken when v0(=[a0+704]) == a5(=-0x1), and falls through when v0(=[a0+704]) != a5(=-0x1).
  The `beq` branch at 0x3aa4 targets 0x3b64, is taken when v0(=[a0+704]) == a4(=-0x2), and falls through when v0(=[a0+704]) != a4(=-0x2).
  The `beq` branch at 0x3ac4 targets 0x3b4c, is taken when v0(=[a0+704]) == a5(=-0x1), and falls through when v0(=[a0+704]) != a5(=-0x1).
  The `beq` branch at 0x3ae0 targets 0x3b5c, is taken when v0(=ret(rad_start_status_dma)) == 0, and falls through when v0(=ret(rad_start_status_dma)) != 0.
  The `beq` branch at 0x3afc targets 0x3a00 and is always taken.
  The `bne` branch at 0x3b44 targets 0x3acc, is taken when v0(=[a0+704]) != a5(=-0x1), and falls through when v0(=[a0+704]) == a5(=-0x1).
  The `beq` branch at 0x3b54 targets 0x3ad8 and is always taken.
  The `beq` branch at 0x3b5c targets 0x3a00 and is always taken.
  The `beq` branch at 0x3b88 targets 0x3aac and is always taken.
  The return at 0x3a0c has v0 = one of 0x0, 0x1.

- `rad_stop_dma` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x3b90 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x3b90-0x3db4 (548 bytes).
  It occupies 548 bytes.
  The `lbu` at 0x3b98 loads 1 byte from a0 (arg0 at entry) +0x274.
  The `ld` at 0x3ba4 loads 8 bytes from a0 (arg0 at entry) +0x2a0.
  The `lw` at 0x3bc0 loads 4 bytes from a0 (arg0 at entry) +0x2c0.
  6 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x2e8, including `ld` at 0x3be4, `ld` at 0x3bf4, `ld` at 0x3ce8.
  4 such `lw` accesses load 4 bytes from [a0+744]:8 +0x0, including `lw` at 0x3be8, `lw` at 0x3c04, `lw` at 0x3d88.
  3 such `sw` accesses store 4 bytes to [a0+744]:8 +0x0, including `sw` at 0x3bf0, `sw` at 0x3d98, `sw` at 0x3db0.
  2 such `ld` accesses load 8 bytes from [a0+672]:8 +0x228, including `ld` at 0x3bf8, `ld` at 0x3c0c.
  2 such `lwu` accesses load 4 bytes from a0 (arg0 at entry) +0x2e4, including `lwu` at 0x3bfc, `lwu` at 0x3c10.
  The `sw` at 0x3c08 stores 4 bytes to ([a0+740] + [[a0+672]:8+552]:8) +0x0.
  The `lw` at 0x3c14 loads 4 bytes from [a0+672]:8 +0x731c.
  2 such `lw` accesses load 4 bytes from ([a0+740] + [[a0+672]:8+552]:8) +0x0, including `lw` at 0x3c1c, `lw` at 0x3c24.
  3 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x274, including `sb` at 0x3c30, `sb` at 0x3c7c, `sb` at 0x3d80.
  The `lw` at 0x3c34 loads 4 bytes from [a0+672]:8 +0x72c8.
  The `sw` at 0x3c3c stores 4 bytes to [a0+672]:8 +0x72c8.
  The `lbu` at 0x3c54 loads 1 byte from [a0+672]:8 +0x7310.
  The `sb` at 0x3c64 stores 1 byte to [a0+672]:8 +0x7310.
  The `sb` at 0x3c74 stores 1 byte to [a0+672]:8 +0x7312.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x238, including `lw` at 0x3c80, `lw` at 0x3cec.
  2 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x3cb8, `lbu` at 0x3d24.
  The `lbu` at 0x3d58 loads 1 byte from [a0+672]:8 +0x7311.
  The `sb` at 0x3d68 stores 1 byte to [a0+672]:8 +0x7311.
  The `sb` at 0x3d78 stores 1 byte to [a0+672]:8 +0x7313.
  The `jal` at 0x3c28 calls pcibr_rrb_flush with a0=[[a0+672]:8+29468], a1=[([a0+740] + [[a0+672]:8+552]:8)], a2=[[a0+744]:8], a3=([a0+740] + [[a0+672]:8+552]:8), a4=[[a0+672]:8+552]:8.
  The `jal` at 0x3c70 calls rad_pio_writeback_subcode_tx with a0=[a0+672]:8+12128, a1=a1 at entry (arg1), a2=-0x1, a3=0x6, a4=0x7, a5=-0x2, a7=0x1.
  The `jal` at 0x3cdc calls rad_stop_dma with a0=[a0+672]:8+8168, a1=a1 at entry (arg1), a2=?, a3=?, a4=0x1, a5=-0x2.
  The `jal` at 0x3d48 calls rad_stop_dma with a0=[a0+672]:8+8960, a1=a1 at entry (arg1), a2=?, a3=?, a4=0x1, a5=-0x2.
  The `jal` at 0x3d74 calls rad_pio_writeback_subcode_tx with a0=[a0+672]:8+17672, a1=a1 at entry (arg1), a2=-0x1, a3=0x6, a4=0x7, a5=-0x2.
  The `beq` branch at 0x3bb8 targets 0x3c40, is taken when at(=[a0+628]:1) == 0, and falls through when at(=[a0+628]:1) != 0.
  The `beq` branch at 0x3bc4 targets 0x3c54, is taken when a0(=[a0+704]) == a2(=-0x1), and falls through when a0(=[a0+704]) != a2(=-0x1).
  The `beq` branch at 0x3bcc targets 0x3d58, is taken when a0(=[a0+704]) == a5(=-0x2), and falls through when a0(=[a0+704]) != a5(=-0x2).
  The `beq` branch at 0x3bd4 targets 0x3c80, is taken when a0(=[a0+704]) == a3(=0x6), and falls through when a0(=[a0+704]) != a3(=0x6).
  The `beq` branch at 0x3bdc targets 0x3cec, is taken when a0(=[a0+704]) == a4(=0x7), and falls through when a0(=[a0+704]) != a4(=0x7).
  The `bne` branch at 0x3c60 targets 0x3c30, is taken when (a6(=[[a0+672]:8+29456]:1-1) & 0xff) != 0, and falls through when (a6(=[[a0+672]:8+29456]:1-1) & 0xff) == 0.
  The `beq` branch at 0x3c78 targets 0x3c34 and is always taken.
  The `beq` branch at 0x3c90 targets 0x3d84, is taken when t0(=[a0+568]) >= 0x20 (signed), and falls through when t0(=[a0+568]) < 0x20 (signed).
  The `beq` branch at 0x3cc0 targets 0x3ccc, is taken when t1(?) == 0, and falls through when t1(?) != 0.
  The `bne` branch at 0x3ccc targets 0x3c9c, is taken when a3(?) != 0, and falls through when a3(?) == 0.
  The `bne` branch at 0x3cd4 targets 0x3bf4, is taken when a0(?) != a4(=0x1), and falls through when a0(?) == a4(=0x1).
  The `beq` branch at 0x3ce4 targets 0x3bf8 and is always taken.
  The `beq` branch at 0x3cfc targets 0x3d9c, is taken when t2(=[a0+568]) >= 0x20 (signed), and falls through when t2(=[a0+568]) < 0x20 (signed).
  The `beq` branch at 0x3d2c targets 0x3d38, is taken when t3(?) == 0, and falls through when t3(?) != 0.
  The `bne` branch at 0x3d38 targets 0x3d08, is taken when a3(?) != 0, and falls through when a3(?) == 0.
  The `bne` branch at 0x3d40 targets 0x3bf4, is taken when a0(?) != a4(=0x1), and falls through when a0(?) == a4(=0x1).
  The `beq` branch at 0x3d50 targets 0x3bf8 and is always taken.
  The `bne` branch at 0x3d64 targets 0x3c30, is taken when (t8(=[[a0+672]:8+29457]:1-1) & 0xff) != 0, and falls through when (t8(=[[a0+672]:8+29457]:1-1) & 0xff) == 0.
  The `beq` branch at 0x3d7c targets 0x3c34 and is always taken.
  The `beq` branch at 0x3d94 targets 0x3bf4 and is always taken.
  The `beq` branch at 0x3dac targets 0x3bf4 and is always taken.
  The return at 0x3c4c has v0 = ?.

- `rad_mclk_update_cg` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x3db4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x3db4-0x3ebc (264 bytes).
  It occupies 264 bytes.
  The `ld` at 0x3dcc loads 8 bytes from a0 (arg0 at entry) +0x1f0.
  The `ld` at 0x3de8 loads 8 bytes from a0 (arg0 at entry) +0x1c8.
  The `lw` at 0x3dec loads 4 bytes from [a0+456]:8 +0x128.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x21c, including `lw` at 0x3e00, `lw` at 0x3e60.
  The `sw` at 0x3e14 stores 4 bytes to a0 (arg0 at entry) +0x21c.
  The `ld` at 0x3e1c loads 8 bytes from [a0+496]:8 +0x228.
  The `sw` at 0x3e34 stores 4 bytes to [[a0+496]:8+552]:8 +0xa0.
  The `ld` at 0x3e4c loads 8 bytes from a0 (arg0 at entry) +0x1a0.
  The `jal` at 0x3dc8 calls kdsp_mclk_update_cg with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `bne` branch at 0x3de0 targets 0x3e38, is taken when s0(=a0) != at(=[a0+496]:8+26240), and falls through when s0(=a0) == at(=[a0+496]:8+26240).
  The `beq` branch at 0x3df0 targets 0x3e00, is taken when a1(=[[a0+456]:8+296]) == a4(=0x2000000b), and falls through when a1(=[[a0+456]:8+296]) != a4(=0x2000000b).
  The `bne` branch at 0x3df8 targets 0x3e48, is taken when a1(=[[a0+456]:8+296]) != a3(=0x2000000c), and falls through when a1(=[[a0+456]:8+296]) == a3(=0x2000000c).
  The `beq` branch at 0x3e08 targets 0x3e38, is taken when a2(=[a0+540]) == a1(=0x3), and falls through when a2(=[a0+540]) != a1(=0x3).
  The `beq` branch at 0x3e64 targets 0x3e7c, is taken when a4(=0x72d800000000) >= a5(=[a0+416]:8) (signed), and falls through when a4(=0x72d800000000) < a5(=[a0+416]:8) (signed).
  The `beq` branch at 0x3e6c targets 0x3e38, is taken when a2(=[a0+540]) == a1(=0x3), and falls through when a2(=[a0+540]) != a1(=0x3).
  The `beq` branch at 0x3e74 targets 0x3e14 and is always taken.
  The `beq` branch at 0x3e8c targets 0x3ea4, is taken when a7(=0x396c00000000) >= a5(=[a0+416]:8) (signed), and falls through when a7(=0x396c00000000) < a5(=[a0+416]:8) (signed).
  The `beq` branch at 0x3e94 targets 0x3e38, is taken when a2(=[a0+540]) == a1(=0x6), and falls through when a2(=[a0+540]) != a1(=0x6).
  The `beq` branch at 0x3e9c targets 0x3e14 and is always taken.
  The `beq` branch at 0x3eac targets 0x3e38, is taken when a2(=[a0+540]) == a1(=one of 0xc, 0x18), and falls through when a2(=[a0+540]) != a1(=one of 0xc, 0x18).
  The `beq` branch at 0x3eb4 targets 0x3e14 and is always taken.
  The return at 0x3e40 has v0 = ret(kdsp_mclk_update_cg).

- `rad_check_adat_rx` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x3ebc (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x3ebc-0x4040 (388 bytes).
  It occupies 388 bytes.
  3 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x7309, including `lbu` at 0x3ebc, `lbu` at 0x3f0c, `lbu` at 0x403c.
  The `lbu` at 0x3eec loads 1 byte from a0 (arg0 at entry) +0x730a.
  2 such `sh` accesses store 2 bytes to a0 (arg0 at entry) +0x730c, including `sh` at 0x3ef8, `sh` at 0x3f34.
  2 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x730b, including `sb` at 0x3efc, `sb` at 0x3f40.
  The `lbu` at 0x3f00 loads 1 byte from a0 (arg0 at entry) +0x730b.
  The `sb` at 0x3f10 stores 1 byte to a0 (arg0 at entry) +0x730a.
  The `lhu` at 0x3f20 loads 2 bytes from a0 (arg0 at entry) +0x730c.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x2c0, including `lw` at 0x3f4c, `lw` at 0x3f70, `lw` at 0x3fb4.
  3 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x800, including `sb` at 0x3f5c, `sb` at 0x3fec, `sb` at 0x4000.
  4 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x7309, including `sb` at 0x3f60, `sb` at 0x3fac, `sb` at 0x3ff8.
  3 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x1ccc, including `sw` at 0x3f6c, `sw` at 0x3fe8, `sw` at 0x4004.
  5 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x228, including `ld` at 0x3f80, `ld` at 0x3f94, `ld` at 0x3fd4.
  5 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x7240, including `lw` at 0x3f84, `lw` at 0x3f90, `lw` at 0x3fcc.
  5 such `sw` accesses store 4 bytes to [a0+552]:8 +0x80, including `sw` at 0x3f8c, `sw` at 0x3fa0, `sw` at 0x3fe0.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x7240, including `sw` at 0x3f9c, `sw` at 0x3fdc.
  The `lw` at 0x3fb0 loads 4 bytes from a0 (arg0 at entry) +0x72f0.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x1cc8, including `sw` at 0x3fe4, `sw` at 0x4010.
  The `jal` at 0x3f3c calls kdsp_update_mclk_users with a0=a0+1624, a1=?, a2=?, a3=?, a4=0x1, a5=0x1f4.
  The `beq` branch at 0x3ed4 targets 0x3f4c, is taken when a4(=0x1) == a2(=[a0+29449]:1), and falls through when a4(=0x1) != a2(=[a0+29449]:1).
  The `beq` branch at 0x3edc targets 0x3f70, is taken when a2(=[a0+29449]:1) == 0, and falls through when a2(=[a0+29449]:1) != 0.
  The `beq` branch at 0x3ee4 targets 0x3fb0, is taken when a2(=[a0+29449]:1) == a3(=0x2), and falls through when a2(=[a0+29449]:1) != a3(=0x2).
  The `beq` branch at 0x3ef0 targets 0x3f00, is taken when at(=[a0+29450]:1) == a2(?), and falls through when at(=[a0+29450]:1) != a2(?).
  The `beq` branch at 0x3f04 targets 0x3f20, is taken when v0(=[a0+29451]:1) == 0, and falls through when v0(=[a0+29451]:1) != 0.
  The `bne` branch at 0x3f30 targets 0x3f0c, is taken when (a0(=[a0+29452]:2-1) & 0xffff) != 0, and falls through when (a0(=[a0+29452]:2-1) & 0xffff) == 0.
  The `beq` branch at 0x3f44 targets 0x3f0c and is always taken.
  The `beq` branch at 0x3f54 targets 0x3eec, is taken when (a1(=[a0+704]) & 0x40) == 0, and falls through when (a1(=[a0+704]) & 0x40) != 0.
  The `beq` branch at 0x3f68 targets 0x3eec and is always taken.
  The `beq` branch at 0x3f78 targets 0x3ffc, is taken when (a2(=[a0+704]) & 0x40) == 0, and falls through when (a2(=[a0+704]) & 0x40) != 0.
  The `beq` branch at 0x3fa8 targets 0x3eec and is always taken.
  The `beq` branch at 0x3fbc targets 0x4014, is taken when (a1(=[a0+29424]) & 0x3ff) == 0, and falls through when (a1(=[a0+29424]) & 0x3ff) != 0.
  The `bne` branch at 0x3fc4 targets 0x3eec, is taken when a0(?) != 0, and falls through when a0(?) == 0.
  The `beq` branch at 0x3ff4 targets 0x3eec and is always taken.
  The `beq` branch at 0x400c targets 0x3eec and is always taken.
  The `beq` branch at 0x4014 targets 0x3fcc, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x4038 targets 0x3eec and is always taken.
  The return at 0x3f18 has v0 = one of [a0+29451]:1, ret(kdsp_update_mclk_users).

- `rad_update_dev` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x4040 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x4040-0x4580 (1344 bytes).
  It occupies 1344 bytes.
  The `ld` at 0x4048 loads 8 bytes from a0 (arg0 at entry) +0x2a0.
  The `lbu` at 0x4054 loads 1 byte from a0 (arg0 at entry) +0x274.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x268, including `lw` at 0x406c, `lw` at 0x41b0.
  2 such `lbu` accesses load 1 byte from [a0+672]:8 +0x730f, including `lbu` at 0x4088, `lbu` at 0x42e4.
  7 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x2c0, including `lw` at 0x4098, `lw` at 0x40b4, `lw` at 0x40b8.
  2 such `lbu` accesses load 1 byte from [a0+672]:8 +0x730e, including `lbu` at 0x40a4, `lbu` at 0x440c.
  The `lw` at 0x40d0 loads 4 bytes from a0 (arg0 at entry) +0x1e4.
  The `lw` at 0x40d4 loads 4 bytes from a0 (arg0 at entry) +0x1d4.
  3 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x1b8, including `ld` at 0x40dc, `ld` at 0x433c, `ld` at 0x4468.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x308, including `ld` at 0x40f4, `ld` at 0x42e0.
  The `ld` at 0x40f8 loads 8 bytes from a0 (arg0 at entry) +0x2f8.
  The `ld` at 0x40fc loads 8 bytes from a0 (arg0 at entry) +0x300.
  The `lw` at 0x4100 loads 4 bytes from [a0+760]:8 +0x0.
  The `lw` at 0x4108 loads 4 bytes from [a0+768]:8 +0x0.
  The `lw` at 0x4124 loads 4 bytes from a0 (arg0 at entry) +0x310.
  The `sd` at 0x4148 stores 8 bytes to a0 (arg0 at entry) +0x308.
  The `lw` at 0x4154 loads 4 bytes from [a0+672]:8 +0x2b8.
  The `ld` at 0x4160 loads 8 bytes from a0 (arg0 at entry) +0x1b0.
  3 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x1b0, including `sd` at 0x4188, `sd` at 0x4308, `sd` at 0x4430.
  4 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x2c4, including `lw` at 0x41a4, `lw` at 0x422c, `lw` at 0x42d0.
  5 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x264, including `sw` at 0x41ac, `sw` at 0x42f4, `sw` at 0x4374.
  The `lw` at 0x41cc loads 4 bytes from [a0+440]:8 +0x0.
  The `sw` at 0x41d8 stores 4 bytes to [a0+440]:8 +0x0.
  The `sw` at 0x41e4 stores 4 bytes to a0 (arg0 at entry) +0x2c4.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x220, including `lw` at 0x41e8, `lw` at 0x4550, `lw` at 0x4574.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x23c, including `lw` at 0x41f0, `lw` at 0x4340, `lw` at 0x446c.
  The `ld` at 0x41f4 loads 8 bytes from a0 (arg0 at entry) +0x1a8.
  3 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x1a8, including `sd` at 0x4200, `sd` at 0x42fc, `sd` at 0x4424.
  The `lw` at 0x4260 loads 4 bytes from a0 (arg0 at entry) +0x238.
  4 such `lw` accesses load 4 bytes from [a0+440]:8 +0x4, including `lw` at 0x4274, `lw` at 0x430c, `lw` at 0x4348.
  2 such `sw` accesses store 4 bytes to [a0+440]:8 +0x4, including `sw` at 0x4280, `sw` at 0x4318.
  The `lbu` at 0x428c loads 1 byte from [a0+672]:8 +0x7309.
  2 such `lw` accesses load 4 bytes from [a0+672]:8 +0x2564, including `lw` at 0x42f0, `lw` at 0x453c.
  The `ld` at 0x42f8 loads 8 bytes from [a0+672]:8 +0x24a8.
  The `ld` at 0x4300 loads 8 bytes from [a0+672]:8 +0x24b0.
  3 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x1c8, including `ld` at 0x435c, `ld` at 0x4448, `ld` at 0x4570.
  8 such `ld` accesses load 8 bytes from ?, including `ld` at 0x43bc, `ld` at 0x43cc, `ld` at 0x43f0.
  7 such `lw` accesses load 4 bytes from ?, including `lw` at 0x43c0, `lw` at 0x43d0, `lw` at 0x43d4.
  4 such `sw` accesses store 4 bytes to ?, including `sw` at 0x43c8, `sw` at 0x43e8, `sw` at 0x44ec.
  4 such `sd` accesses store 8 bytes to ?, including `sd` at 0x43fc, `sd` at 0x4520, `sd` at 0x4560.
  The `sb` at 0x4408 stores 1 byte to [a0+672]:8 +0x730f.
  2 such `lw` accesses load 4 bytes from [a0+672]:8 +0x224c, including `lw` at 0x4418, `lw` at 0x454c.
  The `ld` at 0x4420 loads 8 bytes from [a0+672]:8 +0x2190.
  The `ld` at 0x4428 loads 8 bytes from [a0+672]:8 +0x2198.
  The `sb` at 0x452c stores 1 byte to [a0+672]:8 +0x730e.
  The `jal` at 0x4150 calls rad_sync_device_ust with a0=a0 at entry (arg0), a1=[[a0+672]:8+696], a2=?, a3=0x3ffff.
  The `jal` at 0x42b4 calls kdsp_update_default_subcode with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x42d4 calls rad_check_adat_rx with a0=[a0+672]:8, a1=?, a2=[a0+704], a3=?, a5=0x4, a6=[a0+440]:8.
  The `jal` at 0x4368 calls rad_prepare_adat_in_subcode with a0=[a0+672]:8, a1=?, a2=?, a3=?, a4=[a0+572].
  The `jal` at 0x4394 calls kdsp_update_default_subcode with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x448c calls rad_prepare_aes_in_subcode with a0=[a0+672]:8, a1=?, a2=?, a3=?, a4=[a0+456]:8, a5=[a0+572].
  The `jal` at 0x44b8 calls kdsp_update_default_subcode with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x4530 calls rad_update_dev with a0=[a0+672]:8+8960, a1=0x7, a2=[[a0+672]:8+29455]:1, a3=[a0+672]:8+8168, a4=0x6.
  The `jal` at 0x4540 calls rad_update_dev with a0=[a0+672]:8+8168, a1=0x7, a2=[a0+704], a3=[a0+672]:8+8168, a4=[[a0+672]:8+29454]:1.
  The `beq` branch at 0x4064 targets 0x4204, is taken when at(=[a0+628]:1) == 0, and falls through when at(=[a0+628]:1) != 0.
  The `beq` branch at 0x4074 targets 0x4224, is taken when (v0(=[a0+616]) & 0x400) == 0, and falls through when (v0(=[a0+616]) & 0x400) != 0.
  The `bne` branch at 0x4080 targets 0x409c, is taken when a0(=[a0+672]:8+8960) != s0(=a0), and falls through when a0(=[a0+672]:8+8960) == s0(=a0).
  The `bne` branch at 0x408c targets 0x4208, is taken when v1(=[[a0+672]:8+29455]:1) != 0, and falls through when v1(=[[a0+672]:8+29455]:1) == 0.
  The `beq` branch at 0x4094 targets 0x40d0 and is always taken.
  The `bne` branch at 0x409c targets 0x40b8, is taken when a3(=[a0+672]:8+8168) != s0(=a0), and falls through when a3(=[a0+672]:8+8168) == s0(=a0).
  The `bne` branch at 0x40a8 targets 0x4208, is taken when a0(=[[a0+672]:8+29454]:1) != 0, and falls through when a0(=[[a0+672]:8+29454]:1) == 0.
  The `beq` branch at 0x40b0 targets 0x40d0 and is always taken.
  The `beq` branch at 0x40c0 targets 0x42e4, is taken when a2(=[a0+704]) == a1(=0x7), and falls through when a2(=[a0+704]) != a1(=0x7).
  The `beq` branch at 0x40c8 targets 0x440c, is taken when a2(=[a0+704]) == a4(=0x6), and falls through when a2(=[a0+704]) != a4(=0x6).
  The `beq` branch at 0x40e0 targets 0x42d4, is taken when a2(=[a0+704]) == a5(=0x4), and falls through when a2(=[a0+704]) != a5(=0x4).
  The `beq` branch at 0x40ec targets 0x42d4, is taken when a2(=[a0+704]) == a7(=0x7), and falls through when a2(=[a0+704]) != a7(=0x7).
  The `beq` branch at 0x4144 targets 0x4160, is taken when t1(=[a0+784]) == 0, and falls through when t1(=[a0+784]) != 0.
  The `beq` branch at 0x4158 targets 0x4190 and is always taken.
  The `beq` branch at 0x4194 targets 0x422c, is taken when a0(=[a0+704]) == a2(=0x6), and falls through when a0(=[a0+704]) != a2(=0x6).
  The `beq` branch at 0x419c targets 0x428c, is taken when a0(=[a0+704]) == t9(=0x7), and falls through when a0(=[a0+704]) != t9(=0x7).
  The `beq` branch at 0x41a8 targets 0x4204, is taken when a0(=[a0+708]) == s2(?), and falls through when a0(=[a0+708]) != s2(?).
  The `beq` branch at 0x41b8 targets 0x4244, is taken when (a0(=[a0+616]) & 0x1) == 0, and falls through when (a0(=[a0+616]) & 0x1) != 0.
  The `bgez` branch at 0x41e0 targets 0x41f0, is taken when s3(?) >= 0 (signed), and falls through when s3(?) < 0 (signed).
  The `beq` branch at 0x4224 targets 0x40d0 and is always taken.
  The `bltz` branch at 0x4234 targets 0x4434, is taken when a2(?) < 0 (signed), and falls through when a2(?) >= 0 (signed).
  The `beq` branch at 0x423c targets 0x41a8 and is always taken.
  The `beq` branch at 0x4258 targets 0x430c, is taken when (a0(=[a0+616]) & 0x400) == 0, and falls through when (a0(=[a0+616]) & 0x400) != 0.
  The `beq` branch at 0x4268 targets 0x430c, is taken when a6(=[a0+568]) >= 0x20 (signed), and falls through when a6(=[a0+568]) < 0x20 (signed).
  The `beq` branch at 0x4284 targets 0x41e0 and is always taken.
  The `beq` branch at 0x4294 targets 0x41a4, is taken when ra(=[[a0+672]:8+29449]:1) == at(=0x1), and falls through when ra(=[[a0+672]:8+29449]:1) != at(=0x1).
  The `bne` branch at 0x42c4 targets 0x42a0, is taken when s3(?) < 0x4 (signed), and falls through when s3(?) >= 0x4 (signed).
  The `beq` branch at 0x42cc targets 0x41a8 and is always taken.
  The `beq` branch at 0x42dc targets 0x40f8 and is always taken.
  The `beq` branch at 0x42e8 targets 0x4530, is taken when a2(=[[a0+672]:8+29455]:1) == 0, and falls through when a2(=[[a0+672]:8+29455]:1) != 0.
  The `beq` branch at 0x4304 targets 0x4204 and is always taken.
  The `beq` branch at 0x4328 targets 0x4440, is taken when a0(=[a0+704]) == t9(=0x6), and falls through when a0(=[a0+704]) != t9(=0x6).
  The `bne` branch at 0x4334 targets 0x41e0, is taken when a0(=[a0+704]) != t8(=0x7), and falls through when a0(=[a0+704]) == t8(=0x7).
  The `bltz` branch at 0x4354 targets 0x4574, is taken when a2(?) < 0 (signed), and falls through when a2(?) >= 0 (signed).
  The `bne` branch at 0x43dc targets 0x43ec, is taken when a2(?) < a3(?) (signed), and falls through when a2(?) >= a3(?) (signed).
  The `bne` branch at 0x43f8 targets 0x437c, is taken when s4(?) < 0x4 (signed), and falls through when s4(?) >= 0x4 (signed).
  The `beq` branch at 0x4404 targets 0x41e0 and is always taken.
  The `beq` branch at 0x4410 targets 0x4540, is taken when a4(=[[a0+672]:8+29454]:1) == 0, and falls through when a4(=[[a0+672]:8+29454]:1) != 0.
  The `beq` branch at 0x442c targets 0x4204 and is always taken.
  The `beq` branch at 0x4438 targets 0x4238 and is always taken.
  The `beq` branch at 0x4460 targets 0x455c, is taken when (t1(?) & 0x1) == 0, and falls through when (t1(?) & 0x1) != 0.
  The `bltz` branch at 0x4480 targets 0x4550, is taken when a2(?) < 0 (signed), and falls through when a2(?) >= 0 (signed).
  The `bne` branch at 0x4504 targets 0x4510, is taken when a3(?) < a4(?) (signed), and falls through when a3(?) >= a4(?) (signed).
  The `bne` branch at 0x451c targets 0x44a0, is taken when s4(?) < 0x3 (signed), and falls through when s4(?) >= 0x3 (signed).
  The `beq` branch at 0x4528 targets 0x41e0 and is always taken.
  The `beq` branch at 0x4538 targets 0x42f4 and is always taken.
  The `beq` branch at 0x4548 targets 0x441c and is always taken.
  The `beq` branch at 0x4554 targets 0x4484 and is always taken.
  The `beq` branch at 0x456c targets 0x4468 and is always taken.
  The `beq` branch at 0x4578 targets 0x435c and is always taken.
  The return at 0x421c has v0 = ?.

- `rad_update_subcode_tx_dev` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x4580 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x4580-0x4704 (388 bytes).
  It occupies 388 bytes.
  The `lbu` at 0x4580 loads 1 byte from a0 (arg0 at entry) +0x274.
  The `ld` at 0x4588 loads 8 bytes from a0 (arg0 at entry) +0x2a0.
  The `ld` at 0x4598 loads 8 bytes from a0 (arg0 at entry) +0x1b0.
  The `ld` at 0x45a0 loads 8 bytes from a0 (arg0 at entry) +0x300.
  The `lw` at 0x45ac loads 4 bytes from [a0+768]:8 +0x0.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x1a8, including `ld` at 0x45c4, `ld` at 0x4684.
  The `lw` at 0x45dc loads 4 bytes from a0 (arg0 at entry) +0x2c0.
  The `ld` at 0x45f0 loads 8 bytes from a0 (arg0 at entry) +0x1b8.
  2 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x1a8, including `sd` at 0x4604, `sd` at 0x4690.
  The `lwu` at 0x4608 loads 4 bytes from [a0+672]:8 +0x2a4.
  3 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x1b0, including `sd` at 0x4624, `sd` at 0x4688, `sd` at 0x46b8.
  The `lw` at 0x4628 loads 4 bytes from [a0+672]:8 +0x723c.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x238, including `lw` at 0x463c, `lw` at 0x46bc.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x264, including `sw` at 0x4648, `sw` at 0x46f0.
  The `lw` at 0x4654 loads 4 bytes from [a0+440]:8 +0x0.
  2 such `sw` accesses store 4 bytes to [a0+440]:8 +0x0, including `sw` at 0x465c, `sw` at 0x4678.
  The `lw` at 0x4660 loads 4 bytes from a0 (arg0 at entry) +0x220.
  The `sd` at 0x467c stores 8 bytes to a0 (arg0 at entry) +0x308.
  The `sw` at 0x4680 stores 4 bytes to a0 (arg0 at entry) +0x2c4.
  The `lwu` at 0x469c loads 4 bytes from [a0+672]:8 +0x2ac.
  The `lw` at 0x46c0 loads 4 bytes from [a0+672]:8 +0x7238.
  The `beq` branch at 0x458c targets 0x4694, is taken when at(=[a0+628]:1) == 0, and falls through when at(=[a0+628]:1) != 0.
  The `beq` branch at 0x4600 targets 0x469c, is taken when a3(=[a0+704]) == t3(=-0x1), and falls through when a3(=[a0+704]) != t3(=-0x1).
  The `beq` branch at 0x4620 targets 0x46bc, is taken when a3(=[a0+704]) == t3(=-0x1), and falls through when a3(=[a0+704]) != t3(=-0x1).
  The `beq` branch at 0x4638 targets 0x46f4, is taken when a3(?) == t0(=0x2), and falls through when a3(?) != t0(=0x2).
  The `beq` branch at 0x4640 targets 0x46f4, is taken when a3(?) == t2(=0x1), and falls through when a3(?) != t2(=0x1).
  The `beq` branch at 0x464c targets 0x4694, is taken when a2(=one of 0x0, 0x1, 0x6) == 0, and falls through when a2(=one of 0x0, 0x1, 0x6) != 0.
  The `bne` branch at 0x4670 targets 0x467c, is taken when a6(?) < t2(=[a0+544]) (signed), and falls through when a6(?) >= t2(=[a0+544]) (signed).
  The `bne` branch at 0x46b4 targets 0x4628, is taken when a3(=[a0+704]) != t3(=-0x1), and falls through when a3(=[a0+704]) == t3(=-0x1).
  The `beq` branch at 0x46dc targets 0x46fc, is taken when a3(?) == t2(=0x2), and falls through when a3(?) != t2(=0x2).
  The `beq` branch at 0x46e4 targets 0x46fc, is taken when a3(?) == a6(=0x1), and falls through when a3(?) != a6(=0x1).
  The `beq` branch at 0x46ec targets 0x464c and is always taken.
  The `beq` branch at 0x46f4 targets 0x4648 and is always taken.
  The `beq` branch at 0x46fc targets 0x46ec and is always taken.
  The return at 0x4694 has v0 = ?.

- `rad_pio_writeback_subcode_tx` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x4704 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x4704-0x4ac8 (964 bytes).
  It occupies 964 bytes.
  The `lw` at 0x4704 loads 4 bytes from a0 (arg0 at entry) +0x230.
  The `lw` at 0x470c loads 4 bytes from a0 (arg0 at entry) +0x2c0.
  The `ld` at 0x4718 loads 8 bytes from a0 (arg0 at entry) +0x2a0.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x1b8, including `ld` at 0x472c, `ld` at 0x4830.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x22c, including `lw` at 0x4730, `lw` at 0x4834.
  2 such `lw` accesses load 4 bytes from [a0+440]:8 +0x4, including `lw` at 0x4734, `lw` at 0x4838.
  2 such `lw` accesses load 4 bytes from [a0+440]:8 +0x0, including `lw` at 0x474c, `lw` at 0x4850.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x1c8, including `ld` at 0x4750, `ld` at 0x4854.
  24 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x47ac, `lbu` at 0x47b0, `lbu` at 0x47c0.
  4 such `sb` accesses store 1 byte to ?, including `sb` at 0x47c8, `sb` at 0x47d0, `sb` at 0x47f0.
  The `lbu` at 0x4804 loads 1 byte from [a0+672]:8 +0x7313.
  The `sb` at 0x4814 stores 1 byte to [a0+672]:8 +0x7313.
  2 such `sw` accesses store 4 bytes to ?, including `sw` at 0x48f8, `sw` at 0x4950.
  The `lbu` at 0x4954 loads 1 byte from [a0+672]:8 +0x7312.
  The `sb` at 0x4964 stores 1 byte to [a0+672]:8 +0x7312.
  The `lbu` at 0x4978 loads 1 byte from [a0+672]:8 +0x7310.
  The `lw` at 0x497c loads 4 bytes from [a0+672]:8 +0x7238.
  2 such `lbu` accesses load 1 byte from [a0+672]:8 +0x7314, including `lbu` at 0x49b0, `lbu` at 0x4ab8.
  3 such `sb` accesses store 1 byte to [a0+672]:8 +0x7314, including `sb` at 0x49b4, `sb` at 0x4a9c, `sb` at 0x4abc.
  3 such `sb` accesses store 1 byte to [a0+672]:8 +0x7315, including `sb` at 0x49bc, `sb` at 0x4aa4, `sb` at 0x4ac4.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x220, including `lw` at 0x49c0, `lw` at 0x4a24.
  The `lbu` at 0x49dc loads 1 byte from [a0+672]:8 +0x7311.
  The `lw` at 0x49e0 loads 4 bytes from [a0+672]:8 +0x723c.
  2 such `lbu` accesses load 1 byte from [a0+672]:8 +0x7316, including `lbu` at 0x4a14, `lbu` at 0x4a6c.
  3 such `sb` accesses store 1 byte to [a0+672]:8 +0x7316, including `sb` at 0x4a18, `sb` at 0x4a50, `sb` at 0x4a70.
  3 such `sb` accesses store 1 byte to [a0+672]:8 +0x7317, including `sb` at 0x4a20, `sb` at 0x4a58, `sb` at 0x4a78.
  The `jal` at 0x4970 calls rad_prepare_aes_out_subcode with a0=[a0+672]:8, a1=[a0+672]:8+29000, a2=?, a3=?.
  The `jal` at 0x49a8 calls rad_write_aes_out_subcode with a0=[a0+672]:8, a1=0x1180, a2=[a0+672]:8+29000, a3=?.
  The `jal` at 0x49d4 calls rad_prepare_adat_out_subcode with a0=[a0+672]:8, a1=[a0+672]:8+29144, a2=?, a3=?.
  The `jal` at 0x4a0c calls rad_write_adat_out_subcode with a0=[a0+672]:8, a1=0x1080, a2=[a0+672]:8+29144, a3=?, a4=0x2, a5=0x1.
  The `jal` at 0x4a38 calls rad_write_adat_out_subcode with a0=[a0+672]:8, a1=0x1000, a2=[a0+672]:8+29144, a3=?, a4=0x2, a5=0x1.
  The `jal` at 0x4a48 calls rad_write_adat_out_subcode with a0=[a0+672]:8, a1=0x1080, a2=[a0+672]:8+29144, a3=?.
  The `jal` at 0x4a64 calls rad_write_adat_out_subcode with a0=[a0+672]:8, a1=0x1000, a2=[a0+672]:8+29144, a3=?, a4=0x2, a5=0x1.
  The `jal` at 0x4a84 calls rad_write_aes_out_subcode with a0=[a0+672]:8, a1=0x1100, a2=[a0+672]:8+29000, a3=?.
  The `jal` at 0x4a94 calls rad_write_aes_out_subcode with a0=[a0+672]:8, a1=0x1180, a2=[a0+672]:8+29000, a3=?.
  The `jal` at 0x4ab0 calls rad_write_aes_out_subcode with a0=[a0+672]:8, a1=0x1100, a2=[a0+672]:8+29000, a3=?.
  The `beq` branch at 0x471c targets 0x4828, is taken when at(=[a0+704]) == v0(=-0x1), and falls through when at(=[a0+704]) != v0(=-0x1).
  The `beq` branch at 0x4724 targets 0x4804, is taken when a1(=[a0+560]) == 0, and falls through when a1(=[a0+560]) != 0.
  The `bltz` branch at 0x473c targets 0x49c0, is taken when a2(?) < 0 (signed), and falls through when a2(?) >= 0 (signed).
  The `blez` branch at 0x4744 targets 0x4804, is taken when a1(?) <= 0 (signed), and falls through when a1(?) > 0 (signed).
  The `beq` branch at 0x478c targets 0x479c, is taken when a0 == a7(?), and falls through when a0 != a7(?).
  The `bne` branch at 0x4794 targets 0x4764, is taken when a4(?) != 0, and falls through when a4(?) == 0.
  The `bne` branch at 0x47fc targets 0x47a4, is taken when a0(?) < 0x6 (signed), and falls through when a0(?) >= 0x6 (signed).
  The `blez` branch at 0x4810 targets 0x49cc, is taken when t1(?) <= 0 (signed), and falls through when t1(?) > 0 (signed).
  The `beq` branch at 0x4828 targets 0x4954, is taken when a1(=[a0+560]) == 0, and falls through when a1(=[a0+560]) != 0.
  The `bltz` branch at 0x4840 targets 0x4a24, is taken when a2(?) < 0 (signed), and falls through when a2(?) >= 0 (signed).
  The `blez` branch at 0x4848 targets 0x4954, is taken when a1(?) <= 0 (signed), and falls through when a1(?) > 0 (signed).
  The `beq` branch at 0x488c targets 0x489c, is taken when a0 == a7(?), and falls through when a0 != a7(?).
  The `bne` branch at 0x4894 targets 0x4864, is taken when a4(?) != 0, and falls through when a4(?) == 0.
  The `bne` branch at 0x494c targets 0x48a4, is taken when a0(?) < 0x6 (signed), and falls through when a0(?) >= 0x6 (signed).
  The `bgtz` branch at 0x4960 targets 0x4818, is taken when t8(?) > 0 (signed), and falls through when t8(?) <= 0 (signed).
  The `beq` branch at 0x4984 targets 0x4a7c, is taken when a1(=[[a0+672]:8+29456]:1) == 0, and falls through when a1(=[[a0+672]:8+29456]:1) != 0.
  The `beq` branch at 0x4990 targets 0x4aa8, is taken when a0(?) == a1(=0x2), and falls through when a0(?) != a1(=0x2).
  The `bne` branch at 0x4998 targets 0x481c, is taken when a0(?) != a2(=0x1), and falls through when a0(?) == a2(=0x1).
  The `beq` branch at 0x49b8 targets 0x4818 and is always taken.
  The `beq` branch at 0x49c4 targets 0x4744 and is always taken.
  The `beq` branch at 0x49f0 targets 0x4a30, is taken when a1(=[[a0+672]:8+29457]:1) == 0, and falls through when a1(=[[a0+672]:8+29457]:1) != 0.
  The `beq` branch at 0x49f8 targets 0x4a5c, is taken when a0(?) == a4(=0x2), and falls through when a0(?) != a4(=0x2).
  The `bne` branch at 0x4a00 targets 0x4818, is taken when a0(?) != a5(=0x1), and falls through when a0(?) == a5(=0x1).
  The `beq` branch at 0x4a1c targets 0x4818 and is always taken.
  The `beq` branch at 0x4a28 targets 0x4848 and is always taken.
  The `beq` branch at 0x4a54 targets 0x4818 and is always taken.
  The `beq` branch at 0x4a74 targets 0x4818 and is always taken.
  The `beq` branch at 0x4aa0 targets 0x4818 and is always taken.
  The `beq` branch at 0x4ac0 targets 0x4818 and is always taken.
  The return at 0x4820 has v0 = one of ?, ret(rad_prepare_aes_out_subcode).

- `rad_pre_connect` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x4ac8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x4ac8-0x4ad0 (8 bytes).
  It occupies 8 bytes.
  The return at 0x4ac8 has v0 = 0x0.

- `rad_set_clockgen` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x4ad0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x4ad0-0x4d84 (692 bytes).
  It occupies 692 bytes.
  The `ld` at 0x4adc loads 8 bytes from a0 (arg0 at entry) +0x1f0.
  The `lw` at 0x4aec loads 4 bytes from a0 (arg0 at entry) +0x1f8.
  The `sd` at 0x4b20 stores 8 bytes to a0 (arg0 at entry) +0x200.
  The `lw` at 0x4b24 loads 4 bytes from a0 (arg0 at entry) +0x20c.
  9 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x208, including `lw` at 0x4b40, `lw` at 0x4bac, `lw` at 0x4bf8.
  The `lw` at 0x4b54 loads 4 bytes from ([a0+496]:8 + ([a0+520] << 0x2)) +0x72cc.
  3 such `lh` accesses load 2 bytes from [a0+496]:8 +0x21a, including `lh` at 0x4b6c, `lh` at 0x4be0, `lh` at 0x4cc4.
  2 such `lw` accesses load 4 bytes from [a0+496]:8 +0x7240, including `lw` at 0x4b80, `lw` at 0x4ca8.
  5 such `ld` accesses load 8 bytes from [a0+496]:8 +0x228, including `ld` at 0x4b8c, `ld` at 0x4bbc, `ld` at 0x4c20.
  2 such `sw` accesses store 4 bytes to [a0+496]:8 +0x7240, including `sw` at 0x4b98, `sw` at 0x4cbc.
  2 such `sw` accesses store 4 bytes to [[a0+496]:8+552]:8 +0x80, including `sw` at 0x4ba4, `sw` at 0x4cc0.
  The `ld` at 0x4bb0 loads 8 bytes from a0 (arg0 at entry) +0x200.
  The `lwu` at 0x4bc0 loads 4 bytes from (sym(.rodata) + ([a0+520] << 0x2)) +0x0.
  The `lw` at 0x4bc4 loads 4 bytes from [a0+512]:8 +0x1b4.
  The `sw` at 0x4bd0 stores 4 bytes to ([(sym(.rodata) + ([a0+520] << 0x2))] + [[a0+496]:8+552]:8) +0x0.
  The `sw` at 0x4bd4 stores 4 bytes to a0 (arg0 at entry) +0x218.
  The `sw` at 0x4bd8 stores 4 bytes to a0 (arg0 at entry) +0x214.
  The `sw` at 0x4bdc stores 4 bytes to a0 (arg0 at entry) +0x210.
  The `sw` at 0x4c14 stores 4 bytes to ([a0+496]:8 + ([a0+520] << 0x2)) +0x7288.
  The `lw` at 0x4c28 loads 4 bytes from ([a0+496]:8 + ([a0+520] << 0x2)) +0x7288.
  The `sw` at 0x4c2c stores 4 bytes to [[a0+496]:8+552]:8 +0xa4.
  3 such `lw` accesses load 4 bytes from ([a0+496]:8 + ([a0+520] << 0x2)) +0x7278, including `lw` at 0x4c3c, `lw` at 0x4c74, `lw` at 0x4c98.
  2 such `sw` accesses store 4 bytes to ([a0+496]:8 + ([a0+520] << 0x2)) +0x7278, including `sw` at 0x4c44, `sw` at 0x4c84.
  The `sw` at 0x4c9c stores 4 bytes to [[a0+496]:8+552]:8 +0xa0.
  2 such `lbu` accesses load 1 byte from [a0+496]:8 +0x7302, including `lbu` at 0x4cdc, `lbu` at 0x4d10.
  2 such `lw` accesses load 4 bytes from [a0+496]:8 +0x7274, including `lw` at 0x4d1c, `lw` at 0x4d68.
  2 such `sw` accesses store 4 bytes to [a0+496]:8 +0x7274, including `sw` at 0x4d30, `sw` at 0x4d78.
  The `jal` at 0x4d2c calls rad_vl_write_MUX_SEL with a0=[a0+496]:8, a1=?, a2=-0x2001, a3=0x7, a4=0x1, a5=[a0+520]+8.
  The `jal` at 0x4d34 calls us_delay with a0=0xfa, a1=?, a2=?, a3=?.
  The `jal` at 0x4d54 calls rad_vl_set_clockgen with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0xd, a3=0x7, a4=0x1.
  The `jal` at 0x4d74 calls rad_vl_write_MUX_SEL with a0=[a0+496]:8, a1=([[a0+496]:8+29300] | 0x2000), a2=[[a0+496]:8+552]:8, a3=0x7, a4=0x1, a5=([a0+496]:8 + ([a0+520] << 0x2)), a6=[a0+496]:8+26240, a7=[[a0+496]:8+29442]:1.
  The `bltz` branch at 0x4b0c targets 0x4ce4, is taken when at(=[a0+504]) < 0 (signed), and falls through when at(=[a0+504]) >= 0 (signed).
  The `beq` branch at 0x4b14 targets 0x4b24, is taken when a1 == 0, and falls through when a1 != 0.
  The `beq` branch at 0x4b28 targets 0x4ce4, is taken when v0(=[a0+524]) == 0, and falls through when v0(=[a0+524]) != 0.
  The `bne` branch at 0x4b64 targets 0x4ce4, is taken when (v1(=[([a0+496]:8 + ([a0+520] << 0x2))+29388]) & a2(?)) != 0, and falls through when (v1(=[([a0+496]:8 + ([a0+520] << 0x2))+29388]) & a2(?)) == 0.
  The `beq` branch at 0x4b74 targets 0x4d08, is taken when a2(=[[a0+496]:8+538]:2) == a3(=0x7), and falls through when a2(=[[a0+496]:8+538]:2) != a3(=0x7).
  The `beq` branch at 0x4ba0 targets 0x4bd4, is taken when a0(=one of 0x0, 0x1) == 0, and falls through when a0(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x4be4 targets 0x4d50, is taken when a0(=[[a0+496]:8+538]:2) == a3(=0x7), and falls through when a0(=[[a0+496]:8+538]:2) != a3(=0x7).
  The `beq` branch at 0x4bec targets 0x4d50, is taken when a0(=[[a0+496]:8+538]:2) == a2(=0xd), and falls through when a0(=[[a0+496]:8+538]:2) != a2(=0xd).
  The `bne` branch at 0x4cc8 targets 0x4ce4, is taken when t1(=[[a0+496]:8+538]:2) != a3(=0x7), and falls through when t1(=[[a0+496]:8+538]:2) == a3(=0x7).
  The `bne` branch at 0x4cd4 targets 0x4ce8, is taken when s0(=a0) != a6(=[a0+496]:8+26240), and falls through when s0(=a0) == a6(=[a0+496]:8+26240).
  The `beq` branch at 0x4ce0 targets 0x4d68, is taken when a7(=[[a0+496]:8+29442]:1) == 0, and falls through when a7(=[[a0+496]:8+29442]:1) != 0.
  The `bne` branch at 0x4d08 targets 0x4b80, is taken when s0(=a0) != a2(=[a0+496]:8+26240), and falls through when s0(=a0) == a2(=[a0+496]:8+26240).
  The `bne` branch at 0x4d14 targets 0x4b7c, is taken when t0(=[[a0+496]:8+29442]:1) != 0, and falls through when t0(=[[a0+496]:8+29442]:1) == 0.
  The `beq` branch at 0x4d48 targets 0x4b7c and is always taken.
  The `beq` branch at 0x4d60 targets 0x4bf0 and is always taken.
  The `beq` branch at 0x4d7c targets 0x4ce8 and is always taken.
  The return at 0x4d00 has v0 = one of ?, ret(rad_vl_write_MUX_SEL).

- `rad_get_hw_mscust` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x4d84 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x4d84-0x4db8 (52 bytes).
  It occupies 52 bytes.
  The `ld` at 0x4d84 loads 8 bytes from a0 (arg0 at entry) +0x308.
  The `lw` at 0x4d88 loads 4 bytes from a0 (arg0 at entry) +0x258.
  The `ld` at 0x4d8c loads 8 bytes from a0 (arg0 at entry) +0x2a0.
  The `sd` at 0x4d94 stores 8 bytes to a1 (arg1 at entry) +0x0.
  The `ld` at 0x4d98 loads 8 bytes from a0 (arg0 at entry) +0x1b0.
  The `ld` at 0x4d9c loads 8 bytes from [a0+672]:8 +0x72a8.
  The `sd` at 0x4db4 stores 8 bytes to a2 (arg2 at entry) +0x0.
  The return at 0x4db0 has v0 = [sym(.sbss)+4].

- `rad_start_clockgen` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x4db8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x4db8-0x4dec (52 bytes).
  It occupies 52 bytes.
  The `lw` at 0x4db8 loads 4 bytes from a0 (arg0 at entry) +0x20c.
  The `ld` at 0x4dc4 loads 8 bytes from a0 (arg0 at entry) +0x1f0.
  The `lw` at 0x4dc8 loads 4 bytes from a0 (arg0 at entry) +0x208.
  The `lw` at 0x4dd0 loads 4 bytes from [a0+496]:8 +0x7240.
  The `sw` at 0x4de0 stores 4 bytes to [a0+496]:8 +0x7240.
  The `beq` branch at 0x4dc0 targets 0x4de4, is taken when at(=[a0+524]) == 0, and falls through when at(=[a0+524]) != 0.
  The return at 0x4de4 has v0 = ?.

- `rad_shutdown` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x4dec (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x4dec-0x4e08 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x4df4 calls kdsp_idbg_rad_delfuncs with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x4e00 has v0 = ret(kdsp_idbg_rad_delfuncs).

- `rad_halt_intr_ops` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x4e08 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x4e08-0x4e30 (40 bytes).
  It occupies 40 bytes.
  The `sw` at 0x4e20 stores 4 bytes to a0 (arg0 at entry) +0x72c8.
  The `jal` at 0x4e14 calls rad_stop_status_dma with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x4e28 has v0 = ret(rad_stop_status_dma).

- `rad_one_shot_status` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x4e30 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x4e30-0x4f10 (224 bytes).
  It occupies 224 bytes.
  3 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x7c, including `lw` at 0x4e44, `lw` at 0x4ea0, `lw` at 0x4ee4.
  The `sw` at 0x4e64 stores 4 bytes to a1 (arg1 at entry) +0x7c.
  4 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x228, including `ld` at 0x4e68, `ld` at 0x4e74, `ld` at 0x4e7c.
  The `sw` at 0x4e70 stores 4 bytes to [a0+552]:8 +0x504.
  The `sw` at 0x4e78 stores 4 bytes to [a0+552]:8 +0x500.
  The `sw` at 0x4e84 stores 4 bytes to [a0+552]:8 +0x528.
  The `sw` at 0x4e9c stores 4 bytes to [a0+552]:8 +0x5c.
  The `jal` at 0x4e60 calls Mem_to_PCI_DMA with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0x1000, a3=a3 at entry (arg3).
  The `jal` at 0x4e98 calls us_delay with a0=0x5, a1=[a0+552]:8, a2=[a0+552]:8, a3=-0x4, a4=[a0+552]:8.
  The `jal` at 0x4edc calls us_delay with a0=0x5, a1=?, a2=?, a3=?.
  The `jal` at 0x4f00 calls debug with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `beq` branch at 0x4eac targets 0x4ecc, is taken when (v0(=0xffffffff80000000) & a5(=[a1+124])) == 0, and falls through when (v0(=0xffffffff80000000) & a5(=[a1+124])) != 0.
  The `beq` branch at 0x4ecc targets 0x4edc and is always taken.
  The `blez` branch at 0x4ed4 targets 0x4ef8, is taken when s0(?) <= 0 (signed), and falls through when s0(?) > 0 (signed).
  The `beq` branch at 0x4ef0 targets 0x4ed4, is taken when (v0(=0xffffffff80000000) & a6(=[a1+124])) == 0, and falls through when (v0(=0xffffffff80000000) & a6(=[a1+124])) != 0.
  The `bne` branch at 0x4ef8 targets 0x4eb4, is taken when s0(?) != 0, and falls through when s0(?) == 0.
  The `beq` branch at 0x4f08 targets 0x4eb8 and is always taken.
  The return at 0x4ec4 has v0 = one of 0x0, 0x1.

- `rad_attach` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x4f10 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x4f10-0x4fc4 (180 bytes).
  It occupies 180 bytes.
  The `jal` at 0x4f30 calls pciio_piotrans_addr with a0=a0 at entry (arg0), a1=0x0, a2=0x7, a3=0x0, a4=0x20, a5=0x0.
  The `jal` at 0x4f50 calls pciio_piotrans_addr with a0=a0 at entry (arg0), a1=0x0, a2=0x8, a3=0x0, a4=0x2000, a5=0x0.
  The `jal` at 0x4f64 calls pciio_config_get with a0=a0 at entry (arg0), a1=0x8, a2=0x4, a3=?.
  The `jal` at 0x4f84 calls pciio_priority_set with a0=a0 at entry (arg0), a1=0x2, a2=?, a3=?.
  The `jal` at 0x4f98 calls pciio_priority_set with a0=a0 at entry (arg0), a1=0x1, a2=?, a3=?.
  The `jal` at 0x4fa8 calls rad_create_subsys with a0=ret(pciio_piotrans_addr), a1=ret(pciio_piotrans_addr), a2=a0 at entry (arg0), a3=?.
  The `bne` branch at 0x4f7c targets 0x4f94, is taken when at(?) != v0(=0xc), and falls through when at(?) == v0(=0xc).
  The `beq` branch at 0x4f8c targets 0x4fa0 and is always taken.
  The return at 0x4fbc has v0 = 0x0.

- `rad_detach` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x4fc4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x4fc4-0x4fcc (8 bytes).
  It occupies 8 bytes.
  The return at 0x4fc4 has v0 = 0x0.

- `rad_error` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x4fcc (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x4fcc-0x4fd4 (8 bytes).
  It occupies 8 bytes.
  The return at 0x4fcc has v0 = 0x0.

- `rad_error_handler` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x4fd4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x4fd4-0x506c (152 bytes).
  It occupies 152 bytes.
  4 such `ld` accesses load 8 bytes from a3 (arg3 at entry) +0x28, including `ld` at 0x5028, `ld` at 0x502c, `ld` at 0x5058.
  The `lw` at 0x5038 loads 4 bytes from a0 (arg0 at entry) +0x731c.
  The `jal` at 0x503c calls cmn_err with a0=0x4, a1=sym(.rodata), a2=[a0+29468], a3=sym(.rodata), a4=a1 at entry (arg1), a5=a2 at entry (arg2), a6=[a3+40]:8, a7=0x6.
  The `beq` branch at 0x5000 targets 0x502c, is taken when a1 == at(=0x5), and falls through when a1 != at(=0x5).
  The `beq` branch at 0x5008 targets 0x5054, is taken when a1 == a7(=0x6), and falls through when a1 != a7(=0x6).
  The `beq` branch at 0x5010 targets 0x505c, is taken when a1 == t3(=0x9), and falls through when a1 != t3(=0x9).
  The `beq` branch at 0x5018 targets 0x5064, is taken when a1 == t8(=0xa), and falls through when a1 != t8(=0xa).
  The `beq` branch at 0x5024 targets 0x5030 and is always taken.
  The `beq` branch at 0x5054 targets 0x5030 and is always taken.
  The `beq` branch at 0x505c targets 0x502c and is always taken.
  The `beq` branch at 0x5064 targets 0x5030 and is always taken.
  The return at 0x504c has v0 = 0x9.

- `rad_init` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x506c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x506c-0x50a0 (52 bytes).
  It occupies 52 bytes.
  The `jal` at 0x5084 calls pciio_driver_register with a0=0x10a9, a1=0x5, a2=sym(.rodata), a3=0x0.
  The `jal` at 0x508c calls kdsp_idbg_rad_addfuncs with a0=?, a1=?, a2=?, a3=?.
  The return at 0x5098 has v0 = ret(kdsp_idbg_rad_addfuncs).

- `rad_halt` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x50a0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x50a0-0x517c (220 bytes).
  It occupies 220 bytes.
  4 such `ld` accesses load 8 bytes from ?, including `ld` at 0x50c8, `ld` at 0x5100, `ld` at 0x5128.
  3 such `lh` accesses load 2 bytes from ?, including `lh` at 0x50ec, `lh` at 0x5110, `lh` at 0x5178.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0x50fc, `lw` at 0x515c.
  6 such `sw` accesses store 4 bytes to ?, including `sw` at 0x5108, `sw` at 0x510c, `sw` at 0x5130.
  The `jal` at 0x50c0 calls rad_stop_status_dma with a0=?, a1=?, a2=?, a3=?, a5=0xc.
  The `jal` at 0x50dc calls strncmp with a0=?, a1=sym(.rodata), a2=0x3, a3=?.
  The `jal` at 0x5148 calls us_delay with a0=0xc8, a1=?, a2=?, a3=?.
  The `jal` at 0x516c calls rad_vl_write_MUX_SEL with a0=?, a1=?, a2=?, a3=?, a4=0x7, a5=0xc.
  The `beq` branch at 0x50b0 targets 0x5144, is taken when at(=[sym(kdsp_sstab)]:8) == 0, and falls through when at(=[sym(kdsp_sstab)]:8) != 0.
  The `beq` branch at 0x50b8 targets 0x50d4 and is always taken.
  The `beq` branch at 0x50cc targets 0x5144, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `bne` branch at 0x50e4 targets 0x50c8, is taken when v0(=ret(strncmp)) != 0, and falls through when v0(=ret(strncmp)) == 0.
  The `beq` branch at 0x50f4 targets 0x5118, is taken when a0(?) == a2(=0xd), and falls through when a0(?) != a2(=0xd).
  The `beq` branch at 0x5118 targets 0x515c, is taken when a0(?) == a4(=0x7), and falls through when a0(?) != a4(=0x7).
  The `bne` branch at 0x5120 targets 0x50c0, is taken when a0(?) != a5(=0xc), and falls through when a0(?) == a5(=0xc).
  The `beq` branch at 0x513c targets 0x50c0 and is always taken.
  The `beq` branch at 0x5174 targets 0x511c and is always taken.
  The return at 0x5154 has v0 = ret(us_delay).

- `Mem_to_PCI_DMA` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x517c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x517c-0x51c0 (68 bytes).
  It occupies 68 bytes.
  The `lw` at 0x51a4 loads 4 bytes from a0 (arg0 at entry) +0x731c.
  The `jal` at 0x5190 calls kvtophys with a0=a1 at entry (arg1), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x51a8 calls pciio_dmatrans_addr with a0=[a0+29468], a1=0x0, a2=ret(kvtophys), a3=a2 at entry (arg2), a4=0x50.
  The return at 0x51b8 has v0 = ret(pciio_dmatrans_addr).

- `rad_initial_val` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x51c0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x51c0-0x5434 (628 bytes).
  It occupies 628 bytes.
  The `lw` at 0x51c0 loads 4 bytes from a1 (arg1 at entry) +0x0.
  The `ld` at 0x51e8 loads 8 bytes from a0 (arg0 at entry) +0x118.
  The `ld` at 0x51f4 loads 8 bytes from (sym(.rodata) + ([a1]+0xffffffffeffffffe << 0x3)) +0x0.
  Calls (unknown callee) via register with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a4=[a0+280]:8, a5=(sym(.rodata) + ([a1]+0xffffffffeffffffe << 0x3)), a6=([a1]+0xffffffffeffffffe << 0x3) (`jr` at 0x51f8).
  The `beq` branch at 0x51ec targets 0x5204, is taken when a6(=[a1]+0xffffffffeffffffe) >= 0x34 (unsigned), and falls through when a6(=[a1]+0xffffffffeffffffe) < 0x34 (unsigned).
  The return at 0x5204 has v0 = 0x0.
  The instructions from 0x5200 to 0x5200 are not reached by any path from the entry, and their branches are not listed.
  The instructions from 0x520c to 0x5430 are not reached by any path from the entry, and their branches are not listed.
  The indirect jump at 0x51f8 uses a jump table whose successors are unresolved.

- `rad_set_device_params` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x5434 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x5434-0x57dc (936 bytes).
  It occupies 936 bytes.
  The `lw` at 0x5438 loads 4 bytes from a1 (arg1 at entry) +0x0.
  The `ld` at 0x546c loads 8 bytes from a0 (arg0 at entry) +0x2a0.
  The `ld` at 0x5478 loads 8 bytes from (sym(.rodata) + ([a1]+0xffffffffeffffffe << 0x3)) +0x0.
  Calls (unknown callee) via register with a0=[(sym(.rodata) + ([a1]+0xffffffffeffffffe << 0x3))]:8, a1=?, a2=a2 at entry (arg2), a3=a3 at entry (arg3), a5=[a1] (`jr` at 0x547c).
  The `beq` branch at 0x5470 targets 0x5484, is taken when v1(=[a1]+0xffffffffeffffffe) >= 0x34 (unsigned), and falls through when v1(=[a1]+0xffffffffeffffffe) < 0x34 (unsigned).
  The return at 0x5494 has v0 = 0x0.
  The instructions from 0x549c to 0x57d8 are not reached by any path from the entry, and their branches are not listed.
  The indirect jump at 0x547c uses a jump table whose successors are unresolved.

- `rad_commit_device_params` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x57dc (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x57dc-0x57e4 (8 bytes).
  It occupies 8 bytes.
  The return at 0x57dc has v0 = ?.

- `rad_calculate_rate_frac` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x57e4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x57e4-0x5958 (372 bytes).
  It occupies 372 bytes.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x1a0, including `ld` at 0x57e4, `ld` at 0x5914.
  The `ld` at 0x57f0 loads 8 bytes from a0 (arg0 at entry) +0x200.
  The `ld` at 0x57f4 loads 8 bytes from a0 (arg0 at entry) +0x1f0.
  2 such `ld` accesses load 8 bytes from [a0+512]:8 +0x198, including `ld` at 0x5810, `ld` at 0x5828.
  2 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x1a0, including `sd` at 0x5820, `sd` at 0x586c.
  The `ld` at 0x587c loads 8 bytes from [a0+496]:8 +0x630.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x220, including `lw` at 0x5898, `lw` at 0x5930.
  3 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x1b0, including `sw` at 0x589c, `sw` at 0x58d4, `sw` at 0x5934.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x1b8, including `sw` at 0x58ac, `sw` at 0x5940.
  2 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x200, including `sd` at 0x58b8, `sd` at 0x594c.
  The `lw` at 0x58bc loads 4 bytes from a0 (arg0 at entry) +0x1b8.
  The `lw` at 0x58c0 loads 4 bytes from a0 (arg0 at entry) +0x1b0.
  The `ld` at 0x5908 loads 8 bytes from [a0+496]:8 +0x470.
  The `jal` at 0x5838 calls kdsp_reduce_frac with a0=?, a1=[[a0+512]:8+408]:8, a2=a0+432, a3=a0+440, a4=0xffff.
  The `jal` at 0x5880 calls kdsp_reduce_frac with a0=?, a1=[[a0+496]:8+1584]:8, a2=sp-48, a3=sp-44, a4=0xffff.
  The `jal` at 0x58f4 calls kdsp_reduce_frac with a0=?, a1=[a0+440], a2=a0+432, a3=a0+440, a4=0xffff, a6=[a0+416]:8.
  The `jal` at 0x5910 calls kdsp_reduce_frac with a0=[a0+416]:8, a1=[[a0+496]:8+1136]:8, a2=sp-40, a3=sp-36, a4=0xffff.
  The `beq` branch at 0x5800 targets 0x5854, is taken when a3(=[a0+512]:8) == 0, and falls through when a3(=[a0+512]:8) != 0.
  The `beq` branch at 0x5808 targets 0x58bc, is taken when a6(=[a0+416]:8) == 0, and falls through when a6(=[a0+416]:8) != 0.
  The `beq` branch at 0x5818 targets 0x582c, is taken when a0(=[[a0+512]:8+408]:8) >= a6(=[a0+416]:8) (signed), and falls through when a0(=[[a0+512]:8+408]:8) < a6(=[a0+416]:8) (signed).
  The `beq` branch at 0x5860 targets 0x5870, is taken when a0(=0xbb8000000000) >= a6(=[a0+416]:8) (signed), and falls through when a0(=0xbb8000000000) < a6(=[a0+416]:8) (signed).
  The `bne` branch at 0x588c targets 0x5904, is taken when s0(=a0) != a1(=[a0+496]:8+26240), and falls through when s0(=a0) == a1(=[a0+496]:8+26240).
  The `beq` branch at 0x58a8 targets 0x58b4, is taken when a3(=[a0+544]) == 0, and falls through when a3(=[a0+544]) != 0.
  The `beq` branch at 0x58b4 targets 0x5840 and is always taken.
  The `beq` branch at 0x58c8 targets 0x58d8, is taken when a1(=[a0+440]) >= a0(=[a0+432]) (signed), and falls through when a1(=[a0+440]) < a0(=[a0+432]) (signed).
  The `bne` branch at 0x58dc targets 0x58ec, is taken when a4(=0xffff) < a0(?) (signed), and falls through when a4(=0xffff) >= a0(?) (signed).
  The `beq` branch at 0x58e4 targets 0x5844, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0x58fc targets 0x5844 and is always taken.
  The `beq` branch at 0x5918 targets 0x5894, is taken when v0(=ret(kdsp_reduce_frac)) == 0, and falls through when v0(=ret(kdsp_reduce_frac)) != 0.
  The `beq` branch at 0x5928 targets 0x5898, is taken when a1(?) >= a0(?) (signed), and falls through when a1(?) < a0(?) (signed).
  The `beq` branch at 0x593c targets 0x5950, is taken when t0(=[a0+544]) == 0, and falls through when t0(=[a0+544]) != 0.
  The `beq` branch at 0x5948 targets 0x5840 and is always taken.
  The `beq` branch at 0x5950 targets 0x5948 and is always taken.
  The return at 0x584c has v0 = one of ret(kdsp_reduce_frac), ?.

- `rad_cg_update_dev` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x5958 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x5958-0x5a44 (236 bytes).
  It occupies 236 bytes.
  The `ld` at 0x5960 loads 8 bytes from a0 (arg0 at entry) +0x1f0.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x2e8, including `ld` at 0x5964, `ld` at 0x599c.
  The `lw` at 0x5968 loads 4 bytes from [a0+496]:8 +0x1b8.
  The `ld` at 0x596c loads 8 bytes from a0 (arg0 at entry) +0x2a0.
  2 such `lw` accesses load 4 bytes from [a0+744]:8 +0x0, including `lw` at 0x5978, `lw` at 0x59b0.
  The `lw` at 0x5984 loads 4 bytes from [a0+496]:8 +0x208.
  The `sw` at 0x5998 stores 4 bytes to [a0+744]:8 +0x0.
  The `ld` at 0x59a0 loads 8 bytes from [a0+672]:8 +0x228.
  The `lwu` at 0x59a4 loads 4 bytes from a0 (arg0 at entry) +0x2e4.
  The `sw` at 0x59b8 stores 4 bytes to ([a0+740] + [[a0+672]:8+552]:8) +0x0.
  The `ld` at 0x59cc loads 8 bytes from [a0+496]:8 +0x1a0.
  The `lw` at 0x59d8 loads 4 bytes from [a0+672]:8 +0x230.
  The `lbu` at 0x59dc loads 1 byte from [a0+672]:8 +0x7314.
  The `sb` at 0x59e8 stores 1 byte to [a0+672]:8 +0x7314.
  The `sb` at 0x59f0 stores 1 byte to [a0+672]:8 +0x7312.
  The `sb` at 0x59fc stores 1 byte to [a0+672]:8 +0x7310.
  The `lw` at 0x5a08 loads 4 bytes from [a0+496]:8 +0x1b0.
  The `ld` at 0x5a14 loads 8 bytes from [a0+496]:8 +0x200.
  The `lw` at 0x5a18 loads 4 bytes from [[a0+496]:8+512]:8 +0x1b4.
  The `jal` at 0x59d0 calls kdsp_set_aes_rate_bits with a0=[a0+672]:8+20944, a1=[[a0+496]:8+416]:8, a2=?, a3=[a0+496]:8, a4=0x1fffffff, a5=[[a0+744]:8], a6=[a0+744]:8, a7=0x1fff0000.
  The `jal` at 0x59f8 calls rad_pio_writeback_subcode_tx with a0=[a0+672]:8+12128, a1=?, a2=?, a3=?.
  The `beq` branch at 0x5980 targets 0x5a08, is taken when at(=[[a0+496]:8+440]) == t1(=0x1), and falls through when at(=[[a0+496]:8+440]) != t1(=0x1).
  The `beq` branch at 0x59b4 targets 0x59cc, is taken when a0 == v0(=[a0+672]:8+5792), and falls through when a0 != v0(=[a0+672]:8+5792).
  The `bne` branch at 0x59e4 targets 0x59bc, is taken when t9(=[[a0+672]:8+560]) != 0, and falls through when t9(=[[a0+672]:8+560]) == 0.
  The `beq` branch at 0x5a00 targets 0x59c0 and is always taken.
  The `bne` branch at 0x5a0c targets 0x598c, is taken when at(=[[a0+496]:8+432]) != t1(=0x1), and falls through when at(=[[a0+496]:8+432]) == t1(=0x1).
  The `beq` branch at 0x5a2c targets 0x5a3c, is taken when t3(?) == t8(=0x2), and falls through when t3(?) != t8(=0x2).
  The `beq` branch at 0x5a34 targets 0x5988 and is always taken.
  The `beq` branch at 0x5a3c targets 0x5988 and is always taken.
  The return at 0x59c4 has v0 = one of ?, ret(rad_pio_writeback_subcode_tx).

- `rad_get_cg_id` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x5a44 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x5a44-0x5bbc (376 bytes).
  It occupies 376 bytes.
  The `ld` at 0x5a44 loads 8 bytes from a0 (arg0 at entry) +0x1f0.
  The `lh` at 0x5a54 loads 2 bytes from [a0+496]:8 +0x21a.
  The `lw` at 0x5a74 loads 4 bytes from a0 (arg0 at entry) +0x208.
  The `ll` at 0x5a98 loads 4 bytes from ([a0+496]:8 + ([a0+520] << 0x2)) +0x72cc.
  The `sc` at 0x5aa0 stores 4 bytes to ([a0+496]:8 + ([a0+520] << 0x2)) +0x72cc.
  The `ld` at 0x5aac loads 8 bytes from a0 (arg0 at entry) +0x200.
  4 such `lw` accesses load 4 bytes from ?, including `lw` at 0x5ac8, `lw` at 0x5b88, `lw` at 0x5b94.
  The `ll` at 0x5af8 loads 4 bytes from ?.
  The `sc` at 0x5b00 stores 4 bytes to ?.
  The `sw` at 0x5b0c stores 4 bytes to a0 (arg0 at entry) +0x208.
  The `lw` at 0x5b20 loads 4 bytes from a0 (arg0 at entry) +0x1b8.
  The `lw` at 0x5b2c loads 4 bytes from a0 (arg0 at entry) +0x1b0.
  The `ld` at 0x5b74 loads 8 bytes from ?.
  The `beq` branch at 0x5a68 targets 0x5b10, is taken when a6(=[[a0+496]:8+538]:2) == t1(=0xd), and falls through when a6(=[[a0+496]:8+538]:2) != t1(=0xd).
  The `beql` branch at 0x5aa4 targets 0x5a98, is taken when (t3(=[([a0+496]:8 + ([a0+520] << 0x2))+29388]) & t9(?)) == 0, and falls through when (t3(=[([a0+496]:8 + ([a0+520] << 0x2))+29388]) & t9(?)) != 0; its branch-likely delay slot `nop` at 0x5aa8 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x5ab0 targets 0x5b18, is taken when a4(=[a0+512]:8) == t2(=[a0+496]:8+2968), and falls through when a4(=[a0+512]:8) != t2(=[a0+496]:8+2968).
  The `beq` branch at 0x5ab8 targets 0x5b18, is taken when a4(=[a0+512]:8) == t0(=[a0+496]:8+2520), and falls through when a4(=[a0+512]:8) != t0(=[a0+496]:8+2520).
  The `beq` branch at 0x5acc targets 0x5aec, is taken when t9(?) == 0, and falls through when t9(?) != 0.
  The `bne` branch at 0x5ae0 targets 0x5ac8, is taken when a2(?) < 0x4 (signed), and falls through when a2(?) >= 0x4 (signed).
  The `beql` branch at 0x5b04 targets 0x5af8, is taken when a1(?) == 0, and falls through when a1(?) != 0; its branch-likely delay slot `nop` at 0x5b08 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x5b18 targets 0x5ac0, is taken when a0 == a7(=[a0+496]:8+26240), and falls through when a0 != a7(=[a0+496]:8+26240).
  The `bne` branch at 0x5b24 targets 0x5ac0, is taken when a1(=[a0+440]) != t1(=0x1), and falls through when a1(=[a0+440]) == t1(=0x1).
  The `bne` branch at 0x5b30 targets 0x5ac0, is taken when a2(=[a0+432]) != t1(=0x1), and falls through when a2(=[a0+432]) == t1(=0x1).
  The `beq` branch at 0x5b38 targets 0x5b50 and is always taken.
  The `beq` branch at 0x5b48 targets 0x5bac, is taken when a2(?) >= 0x6 (signed), and falls through when a2(?) < 0x6 (signed).
  The `beq` branch at 0x5b6c targets 0x5b40, is taken when a0 == a7(?), and falls through when a0 != a7(?).
  The `bne` branch at 0x5b78 targets 0x5b40, is taken when a7(?) != a4(=[a0+512]:8), and falls through when a7(?) == a4(=[a0+512]:8).
  The `beq` branch at 0x5b80 targets 0x5b40, is taken when a2(?) == t1(=0x1), and falls through when a2(?) != t1(=0x1).
  The `bne` branch at 0x5b8c targets 0x5b40, is taken when t0(?) != t1(=0x1), and falls through when t0(?) == t1(=0x1).
  The `bnel` branch at 0x5b98 targets 0x5b44, is taken when t2(?) != t1(=0x1), and falls through when t2(?) == t1(=0x1); its branch-likely delay slot `addiu a2,a2,1` at 0x5b9c runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x5bac targets 0x5ac0, is taken when a2(?) == t8(=0x6), and falls through when a2(?) != t8(=0x6).
  The `beq` branch at 0x5bb4 targets 0x5aec and is always taken.
  The return at 0x5b10 has v0 = ?.

- `rad_commit_clockgen_params` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x5bbc (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x5bbc-0x5ccc (272 bytes).
  It occupies 272 bytes.
  The `lw` at 0x5bbc loads 4 bytes from a0 (arg0 at entry) +0x224.
  The `sd` at 0x5be8 stores 8 bytes to a0 (arg0 at entry) +0x200.
  3 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x200, including `ld` at 0x5bfc, `ld` at 0x5c4c, `ld` at 0x5c98.
  The `ld` at 0x5c08 loads 8 bytes from a0 (arg0 at entry) +0x1c8.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x1b0, including `lw` at 0x5c20, `lw` at 0x5c34.
  The `ld` at 0x5c24 loads 8 bytes from a0 (arg0 at entry) +0x198.
  The `lw` at 0x5c40 loads 4 bytes from a0 (arg0 at entry) +0x1b8.
  The `lw` at 0x5c50 loads 4 bytes from [a0+512]:8 +0x1b8.
  The `jal` at 0x5bec calls rad_calculate_rate_frac with a0=a0 at entry (arg0), a1=[a0+548], a2=0x20000016, a3=a3 at entry (arg3).
  The `jal` at 0x5bf4 calls rad_get_cg_id with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x5c14 calls kdsp_select_mclk with a0=a0 at entry (arg0), a1=[a0+512]:8, a2=?, a3=[a0+456]:8.
  The `jalr` at 0x5c2c calls (unknown callee) with a0=a0 at entry (arg0), a1=0x0, a2=?, a3=?, a4=[a0+408]:8.
  The `jal` at 0x5c90 calls kdsp_reduce_frac with a0=?, a1=[a0+432], a2=sp-32, a3=sp-28, a4=0xffff, a7=[[a0+512]:8+440].
  The `jal` at 0x5cac calls rad_set_clockgen with a0=a0 at entry (arg0), a1=[a0+512]:8, a2=?, a3=?, a5=0x0.
  The `jal` at 0x5cb4 calls kdsp_update_cg_users with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `beq` branch at 0x5bd8 targets 0x5be8, is taken when a1(=[a0+548]) == at(=0x2000000a), and falls through when a1(=[a0+548]) != at(=0x2000000a).
  The `bne` branch at 0x5be0 targets 0x5bec, is taken when a1(=[a0+548]) != a2(=0x20000016), and falls through when a1(=[a0+548]) == a2(=0x20000016).
  The `beq` branch at 0x5c00 targets 0x5c24, is taken when a1(=[a0+512]:8) == 0, and falls through when a1(=[a0+512]:8) != 0.
  The `beq` branch at 0x5c0c targets 0x5c24, is taken when a3(=[a0+456]:8) == a1(=[a0+512]:8), and falls through when a3(=[a0+456]:8) != a1(=[a0+512]:8).
  The `beq` branch at 0x5c1c targets 0x5c38 and is always taken.
  The `beq` branch at 0x5c38 targets 0x5cc0, is taken when a1(=[a0+432]) == 0, and falls through when a1(=[a0+432]) != 0.
  The `beq` branch at 0x5c44 targets 0x5cc0, is taken when a6(=[a0+440]) == 0, and falls through when a6(=[a0+440]) != 0.
  The return at 0x5cc4 has v0 = one of ?, ret(kdsp_update_cg_users).

- `rad_update_aes_mclk` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x5ccc (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x5ccc-0x5cec (32 bytes).
  It occupies 32 bytes.
  The `ld` at 0x5ccc loads 8 bytes from a0 (arg0 at entry) +0x118.
  The `jal` at 0x5cd8 calls rad_process_aesrx_subcode with a0=[a0+280]:8, a1=0x1, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x5ce4 has v0 = ret(rad_process_aesrx_subcode).

- `rad_process_aesrx_subcode` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x5cec (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x5cec-0x5dac (192 bytes).
  It occupies 192 bytes.
  The `lw` at 0x5cec loads 4 bytes from a0 (arg0 at entry) +0x2c4.
  The `ld` at 0x5d0c loads 8 bytes from a0 (arg0 at entry) +0x72f8.
  The `ld` at 0x5d24 loads 8 bytes from table(sym(.data)+32768) +0x0.
  2 such `lhu` accesses load 2 bytes from a0 (arg0 at entry) +0x7300, including `lhu` at 0x5d30, `lhu` at 0x5d8c.
  2 such `sh` accesses store 2 bytes to a0 (arg0 at entry) +0x7300, including `sh` at 0x5d40, `sh` at 0x5d6c.
  2 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x72f8, including `sd` at 0x5d44, `sd` at 0x5d78.
  The `lbu` at 0x5d50 loads 1 byte from a0 (arg0 at entry) +0x9c0.
  2 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x9c0, including `sb` at 0x5d74, `sb` at 0x5d94.
  The `sd` at 0x5da0 stores 8 bytes to a0 (arg0 at entry) +0x9b0.
  The `jal` at 0x5d9c calls kdsp_update_mclk_users with a0=a0+2072, a1=?, a2=?, a3=?, a5=sym(.data)+32768.
  The `bltz` branch at 0x5d10 targets 0x5d60, is taken when a6(=([a0+708] << 0xc)) < 0 (signed), and falls through when a6(=([a0+708] << 0xc)) >= 0 (signed).
  The `bne` branch at 0x5d28 targets 0x5d6c, is taken when v0(=[a0+29432]:8) != a3(=entry(sym(.data)+32768)), and falls through when v0(=[a0+29432]:8) == a3(=entry(sym(.data)+32768)).
  The `beq` branch at 0x5d38 targets 0x5d50, is taken when v1(=[a0+29440]:2) == 0, and falls through when v1(=[a0+29440]:2) != 0.
  The `beq` branch at 0x5d48 targets 0x5d90, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x5d60 targets 0x5d84, is taken when v0(=[a0+29432]:8) == 0, and falls through when v0(=[a0+29432]:8) != 0.
  The `beq` branch at 0x5d7c targets 0x5d54 and is always taken.
  The `beq` branch at 0x5d88 targets 0x5d34 and is always taken.
  The `beq` branch at 0x5da4 targets 0x5d50 and is always taken.
  The return at 0x5d58 has v0 = one of [a0+2496]:1, 0x1.

- `rad_prepare_aes_in_subcode` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x5dac (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x5dac-0x5ed0 (292 bytes).
  It occupies 292 bytes.
  4 such `ld` accesses load 8 bytes from ?, including `ld` at 0x5dd4, `ld` at 0x5dd8, `ld` at 0x5dec.
  The `lw` at 0x5de0 loads 4 bytes from ?.
  16 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x5e0c, `lbu` at 0x5e10, `lbu` at 0x5e14.
  4 such `sw` accesses store 4 bytes to ?, including `sw` at 0x5e5c, `sw` at 0x5e60, `sw` at 0x5eb0.
  The `bne` branch at 0x5eb8 targets 0x5e04, is taken when a4(?) < 0x6 (signed), and falls through when a4(?) >= 0x6 (signed).
  The `bne` branch at 0x5ec0 targets 0x5dc0, is taken when t3(?) != 0, and falls through when t3(?) == 0.
  The return at 0x5ec8 has v0 = ?.

- `rad_prepare_aes_out_subcode` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x5ed0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x5ed0-0x5fe0 (272 bytes).
  It occupies 272 bytes.
  3 such `ld` accesses load 8 bytes from ?, including `ld` at 0x5ef8, `ld` at 0x5efc, `ld` at 0x5f18.
  16 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x5f24, `lbu` at 0x5f28, `lbu` at 0x5f2c.
  2 such `sw` accesses store 4 bytes to ?, including `sw` at 0x5f70, `sw` at 0x5fc8.
  The `bne` branch at 0x5f10 targets 0x5fcc, is taken when at(?) != 0, and falls through when at(?) == 0.
  The `bne` branch at 0x5fc4 targets 0x5f1c, is taken when a4(?) < 0x6 (signed), and falls through when a4(?) >= 0x6 (signed).
  The `bne` branch at 0x5fd0 targets 0x5ee8, is taken when t1(?) != 0, and falls through when t1(?) == 0.
  The return at 0x5fd8 has v0 = ?.

- `rad_prepare_adat_in_subcode` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x5fe0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x5fe0-0x60b8 (216 bytes).
  It occupies 216 bytes.
  4 such `ld` accesses load 8 bytes from ?, including `ld` at 0x6004, `ld` at 0x6008, `ld` at 0x6018.
  The `lw` at 0x600c loads 4 bytes from ?.
  9 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x6034, `lbu` at 0x6038, `lbu` at 0x6048.
  5 such `sb` accesses store 1 byte to ?, including `sb` at 0x6050, `sb` at 0x6058, `sb` at 0x6078.
  The `bne` branch at 0x6084 targets 0x602c, is taken when a3(?) < 0x6 (signed), and falls through when a3(?) >= 0x6 (signed).
  The `bne` branch at 0x60a8 targets 0x5ffc, is taken when t0(?) < 0x4 (signed), and falls through when t0(?) >= 0x4 (signed).
  The return at 0x60b0 has v0 = ?.

- `rad_prepare_adat_out_subcode` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x60b8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x60b8-0x618c (212 bytes).
  It occupies 212 bytes.
  3 such `ld` accesses load 8 bytes from ?, including `ld` at 0x60e4, `ld` at 0x60e8, `ld` at 0x60f8.
  8 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x60fc, `lbu` at 0x6100, `lbu` at 0x6104.
  The `sw` at 0x615c stores 4 bytes to ?.
  The `bne` branch at 0x60f0 targets 0x6160, is taken when at(?) != 0, and falls through when at(?) == 0.
  The `bne` branch at 0x6158 targets 0x6144, is taken when a3(?) < 0x6 (signed), and falls through when a3(?) >= 0x6 (signed).
  The `bne` branch at 0x617c targets 0x60e4, is taken when t0(?) != 0, and falls through when t0(?) == 0.
  The return at 0x6184 has v0 = ?.

- `rad_write_aes_out_subcode` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x618c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x618c-0x62f0 (356 bytes).
  It occupies 356 bytes.
  6 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x228, including `ld` at 0x6194, `ld` at 0x61c0, `ld` at 0x6218.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0x61a8, `ld` at 0x61d4.
  2 such `sd` accesses store 8 bytes to ?, including `sd` at 0x61b4, `sd` at 0x61e4.
  2 such `ld` accesses load 8 bytes from a2 (arg2 at entry) +0x80, including `ld` at 0x61e8, `ld` at 0x621c.
  The `lw` at 0x61f8 loads 4 bytes from a0 (arg0 at entry) +0x5294.
  4 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x5294, including `sw` at 0x6214, `sw` at 0x62a0, `sw` at 0x62d4.
  The `sd` at 0x6224 stores 8 bytes to ([a0+552]:8 + one of 0x1200, 0x1210) +0x0.
  The `ld` at 0x622c loads 8 bytes from a2 (arg2 at entry) +0x88.
  The `sd` at 0x6234 stores 8 bytes to ([a0+552]:8 + one of 0x1208, 0x1218) +0x0.
  The `ld` at 0x6238 loads 8 bytes from a2 (arg2 at entry) +0x28.
  The `lw` at 0x624c loads 4 bytes from a0 (arg0 at entry) +0x7258.
  4 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x7258, including `sw` at 0x6258, `sw` at 0x6274, `sw` at 0x62ac.
  The `ld` at 0x625c loads 8 bytes from a2 (arg2 at entry) +0x70.
  The `sw` at 0x627c stores 4 bytes to [a0+552]:8 +0x54.
  The `beq` branch at 0x61b8 targets 0x61e8, is taken when a5(?) >= 0x10 (signed), and falls through when a5(?) < 0x10 (signed).
  The `bne` branch at 0x61e0 targets 0x6194, is taken when a5(?) < 0x10 (signed), and falls through when a5(?) >= 0x10 (signed).
  The `beq` branch at 0x61fc targets 0x6288, is taken when a3(=[a2+128]:8) == 0, and falls through when a3(=[a2+128]:8) != 0.
  The `beq` branch at 0x6204 targets 0x62c4, is taken when a1 == a7(=0x1180), and falls through when a1 != a7(=0x1180).
  The `beq` branch at 0x6248 targets 0x62b8, is taken when a6(=0xff000000) == t8(?), and falls through when a6(=0xff000000) != t8(?).
  The `beq` branch at 0x6264 targets 0x62a4, is taken when a6(=0xff000000) == a3(?), and falls through when a6(=0xff000000) != a3(?).
  The `beq` branch at 0x6270 targets 0x6280, is taken when a1(?) == a4(=[a0+29272]), and falls through when a1(?) != a4(=[a0+29272]).
  The `beq` branch at 0x6288 targets 0x62d8, is taken when a1 == a7(=0x1180), and falls through when a1 != a7(=0x1180).
  The `bltz` branch at 0x6290 targets 0x6238, is taken when a6(=([a0+21140] << 0x2f)) < 0 (signed), and falls through when a6(=([a0+21140] << 0x2f)) >= 0 (signed).
  The `beq` branch at 0x629c targets 0x6218 and is always taken.
  The `beq` branch at 0x62a8 targets 0x6280, is taken when a1(?) == a4(=[a0+29272]), and falls through when a1(?) != a4(=[a0+29272]).
  The `beq` branch at 0x62b0 targets 0x627c and is always taken.
  The `beq` branch at 0x62bc targets 0x625c and is always taken.
  The `beq` branch at 0x62d0 targets 0x6218 and is always taken.
  The `bne` branch at 0x62dc targets 0x6238, is taken when (a4(=[a0+21140]) & 0x8000) != 0, and falls through when (a4(=[a0+21140]) & 0x8000) == 0.
  The `beq` branch at 0x62e8 targets 0x6218 and is always taken.
  The return at 0x6280 has v0 = ?.

- `rad_write_adat_out_subcode` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x62f0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x62f0-0x6354 (100 bytes).
  It occupies 100 bytes.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x228, including `ld` at 0x62f8, `ld` at 0x6324.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0x630c, `ld` at 0x6338.
  2 such `sd` accesses store 8 bytes to ?, including `sd` at 0x6318, `sd` at 0x6348.
  The `beq` branch at 0x631c targets 0x634c, is taken when a4(?) >= 0xf (signed), and falls through when a4(?) < 0xf (signed).
  The `bne` branch at 0x6344 targets 0x62f8, is taken when a4(?) < 0xf (signed), and falls through when a4(?) >= 0xf (signed).
  The return at 0x634c has v0 = ?.

- `rad_update_adat_mclk` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x6354 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x6354-0x63a8 (84 bytes).
  It occupies 84 bytes.
  The `ld` at 0x635c loads 8 bytes from a0 (arg0 at entry) +0x118.
  The `lw` at 0x6360 loads 4 bytes from [a0+280]:8 +0x230.
  The `jal` at 0x636c calls rad_check_adat_rx with a0=[a0+280]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x6388 calls rad_start_dma with a0=[a0+280]:8+6584, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x6398 calls rad_stop_dma with a0=[a0+280]:8+6584, a1=?, a2=?, a3=?.
  The `beq` branch at 0x6364 targets 0x6384, is taken when at(=[[a0+280]:8+560]) == 0, and falls through when at(=[[a0+280]:8+560]) != 0.
  The `beq` branch at 0x6390 targets 0x636c, is taken when v0(=ret(rad_start_dma)) == 0, and falls through when v0(=ret(rad_start_dma)) != 0.
  The `beq` branch at 0x63a0 targets 0x636c and is always taken.
  The return at 0x637c has v0 = ret(rad_check_adat_rx).

- `rad_get_mclk_params` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x63a8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x63a8-0x63d8 (48 bytes).
  It occupies 48 bytes.
  The `lw` at 0x63a8 loads 4 bytes from a1 (arg1 at entry) +0x0.
  The `lw` at 0x63c4 loads 4 bytes from a0 (arg0 at entry) +0x1bc.
  The `sw` at 0x63cc stores 4 bytes to a1 (arg1 at entry) +0x8.
  The `beq` branch at 0x63b4 targets 0x63c4, is taken when at(=[a1]) == v0(=0x1000002a), and falls through when at(=[a1]) != v0(=0x1000002a).
  The return at 0x63bc has v0 = 0x0.
  The return at 0x63d0 has v0 = 0x1.

- `rad_set_mclk_params` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x63d8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x63d8-0x64d0 (248 bytes).
  It occupies 248 bytes.
  The `ld` at 0x63d8 loads 8 bytes from a0 (arg0 at entry) +0x118.
  The `lw` at 0x63e0 loads 4 bytes from a1 (arg1 at entry) +0x0.
  The `lh` at 0x6404 loads 2 bytes from [a0+280]:8 +0x21a.
  2 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x8, including `lw` at 0x641c, `lw` at 0x6438.
  2 such `sw` accesses store 4 bytes to [a0+280]:8 +0xd54, including `sw` at 0x6424, `sw` at 0x6440.
  2 such `sw` accesses store 4 bytes to [a0+280]:8 +0xb94, including `sw` at 0x642c, `sw` at 0x6444.
  2 such `lw` accesses load 4 bytes from [a0+280]:8 +0xd54, including `lw` at 0x6478, `lw` at 0x64a4.
  2 such `lw` accesses load 4 bytes from [a0+280]:8 +0x7274, including `lw` at 0x647c, `lw` at 0x64a8.
  2 such `sw` accesses store 4 bytes to [a0+280]:8 +0x7274, including `sw` at 0x6498, `sw` at 0x64c4.
  The `jal` at 0x6494 calls rad_vl_write_MUX_SEL with a0=[a0+280]:8, a1=?, a2=?, a3=-0x101, a4=[[a0+280]:8+538]:2, a5=0xc, a6=[a0+280]:8+2520, a7=0x7.
  The `jal` at 0x64c0 calls rad_vl_write_MUX_SEL with a0=[a0+280]:8, a1=?, a2=?, a3=-0x1001, a4=[[a0+280]:8+538]:2, a5=0xc, a6=[a0+280]:8+2520, a7=0x7.
  The `bne` branch at 0x63fc targets 0x6468, is taken when at(=[a1]) != v1(=0x1000002a), and falls through when at(=[a1]) == v1(=0x1000002a).
  The `beq` branch at 0x640c targets 0x6470, is taken when a4(=[[a0+280]:8+538]:2) == a5(=0xc), and falls through when a4(=[[a0+280]:8+538]:2) != a5(=0xc).
  The `bne` branch at 0x6414 targets 0x6430, is taken when a0 != a6(=[a0+280]:8+2520), and falls through when a0 == a6(=[a0+280]:8+2520).
  The `beq` branch at 0x6428 targets 0x6448 and is always taken.
  The `bne` branch at 0x6430 targets 0x6448, is taken when a0 != t0(=[a0+280]:8+2968), and falls through when a0 == t0(=[a0+280]:8+2968).
  The `beq` branch at 0x6448 targets 0x6478, is taken when a4(=[[a0+280]:8+538]:2) == t1(=0xd), and falls through when a4(=[[a0+280]:8+538]:2) != t1(=0xd).
  The `beq` branch at 0x6450 targets 0x64a4, is taken when a4(=[[a0+280]:8+538]:2) == a7(=0x7), and falls through when a4(=[[a0+280]:8+538]:2) != a7(=0x7).
  The `beq` branch at 0x6468 targets 0x645c and is always taken.
  The `beq` branch at 0x6470 targets 0x645c and is always taken.
  The `beq` branch at 0x649c targets 0x645c and is always taken.
  The `beq` branch at 0x64c8 targets 0x645c and is always taken.
  The return at 0x6460 has v0 = one of 0x0, 0x1.

- `rad_set_clockgen_params` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x64d0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x64d0-0x66e0 (528 bytes).
  It occupies 528 bytes.
  The `ld` at 0x64d8 loads 8 bytes from a0 (arg0 at entry) +0x1f0.
  The `lw` at 0x6504 loads 4 bytes from a1 (arg1 at entry) +0x0.
  4 such `sh` accesses store 2 bytes to a1 (arg1 at entry) +0x14, including `sh` at 0x6548, `sh` at 0x6674, `sh` at 0x66d4.
  3 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x224, including `sw` at 0x654c, `sw` at 0x669c, `sw` at 0x66ac.
  3 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x8, including `lw` at 0x656c, `lw` at 0x663c, `lw` at 0x665c.
  The `ld` at 0x658c loads 8 bytes from a0 (arg0 at entry) +0x58.
  The `ld` at 0x65a0 loads 8 bytes from ?.
  3 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x200, including `sd` at 0x65d8, `sd` at 0x66a8, `sd` at 0x66bc.
  2 such `ld` accesses load 8 bytes from a1 (arg1 at entry) +0x8, including `ld` at 0x65f4, `ld` at 0x66c4.
  3 such `ld` accesses load 8 bytes from ret(kdsp_find_param_info) +0x28, including `ld` at 0x6608, `ld` at 0x6628, `ld` at 0x668c.
  2 such `ld` accesses load 8 bytes from [ret(kdsp_find_param_info)+40]:8 +0x0, including `ld` at 0x6614, `ld` at 0x662c.
  The `ld` at 0x6620 loads 8 bytes from a0 (arg0 at entry) +0x1a0.
  3 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x1a8, including `sd` at 0x6624, `sd` at 0x6688, `sd` at 0x66c0.
  5 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x1a0, including `sd` at 0x6634, `sd` at 0x6638, `sd` at 0x6658.
  The `sw` at 0x664c stores 4 bytes to a0 (arg0 at entry) +0x1b0.
  3 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x220, including `sw` at 0x6654, `sw` at 0x66a0, `sw` at 0x66b4.
  The `sw` at 0x666c stores 4 bytes to a0 (arg0 at entry) +0x1b8.
  2 such `ld` accesses load 8 bytes from [ret(kdsp_find_param_info)+40]:8 +0x8, including `ld` at 0x6678, `ld` at 0x6690.
  The `jal` at 0x65c0 calls kdsp_find_resource_in_list with a0=[a1+8], a1=a0+88, a2=?, a3=a3 at entry (arg3), a4=[a0+88]:8.
  The `jal` at 0x65ec calls kdsp_find_param_info with a0=a0 at entry (arg0), a1=[a1], a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0x64f0 targets 0x653c, is taken when a0 == at(=[a0+496]:8+27896), and falls through when a0 != at(=[a0+496]:8+27896).
  The `beq` branch at 0x64fc targets 0x653c, is taken when a0 == v0(=[a0+496]:8+28448), and falls through when a0 != v0(=[a0+496]:8+28448).
  The `beq` branch at 0x6510 targets 0x65ec, is taken when a1(=[a1]) == v1(=0x1000000d), and falls through when a1(=[a1]) != v1(=0x1000000d).
  The `beq` branch at 0x651c targets 0x656c, is taken when a1(=[a1]) == a0(=0x10000011), and falls through when a1(=[a1]) != a0(=0x10000011).
  The `beq` branch at 0x6524 targets 0x6638, is taken when a1(=[a1]) == a2(=0x1000000e), and falls through when a1(=[a1]) != a2(=0x1000000e).
  The `beq` branch at 0x652c targets 0x6658, is taken when a1(=[a1]) == a0(=0x1000000f), and falls through when a1(=[a1]) != a0(=0x1000000f).
  The `beq` branch at 0x6534 targets 0x6558 and is always taken.
  The `beq` branch at 0x653c targets 0x6554 and is always taken.
  The `beq` branch at 0x6578 targets 0x669c, is taken when a0(=[a1+8]) == a1(=0x2000000a), and falls through when a0(=[a1+8]) != a1(=0x2000000a).
  The `beq` branch at 0x6584 targets 0x66ac, is taken when a0(=[a1+8]) == a1(=0x20000016), and falls through when a0(=[a1+8]) != a1(=0x20000016).
  The `beq` branch at 0x6590 targets 0x65c0, is taken when a4(=[a0+88]:8) == 0, and falls through when a4(=[a0+88]:8) != 0.
  The `beq` branch at 0x6598 targets 0x65ac and is always taken.
  The `beq` branch at 0x65a4 targets 0x65c0, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `bne` branch at 0x65b8 targets 0x65a0, is taken when a2(?) < 0x18 (signed), and falls through when a2(?) >= 0x18 (signed).
  The `beq` branch at 0x65cc targets 0x6544, is taken when v0(=ret(kdsp_find_resource_in_list)) == 0, and falls through when v0(=ret(kdsp_find_resource_in_list)) != 0.
  The `beq` branch at 0x65d4 targets 0x65e4, is taken when v0(=ret(kdsp_find_resource_in_list)) == a0(=[a0+496]:8+2520), and falls through when v0(=ret(kdsp_find_resource_in_list)) != a0(=[a0+496]:8+2520).
  The `bne` branch at 0x65dc targets 0x6650, is taken when v0(=ret(kdsp_find_resource_in_list)) != a1(=[a0+496]:8+2968), and falls through when v0(=ret(kdsp_find_resource_in_list)) == a1(=[a0+496]:8+2968).
  The `beq` branch at 0x65e4 targets 0x6650 and is always taken.
  The `blez` branch at 0x65f8 targets 0x6670, is taken when a1(=[a1+8]:8) <= 0 (signed), and falls through when a1(=[a1+8]:8) > 0 (signed).
  The `beq` branch at 0x6600 targets 0x6670, is taken when v0(=ret(kdsp_find_param_info)) == 0, and falls through when v0(=ret(kdsp_find_param_info)) != 0.
  The `beq` branch at 0x660c targets 0x6670, is taken when a2(=[ret(kdsp_find_param_info)+40]:8) == 0, and falls through when a2(=[ret(kdsp_find_param_info)+40]:8) != 0.
  The `beq` branch at 0x661c targets 0x6678, is taken when a1(=[a1+8]:8) >= a0(=[[ret(kdsp_find_param_info)+40]:8]:8) (signed), and falls through when a1(=[a1+8]:8) < a0(=[[ret(kdsp_find_param_info)+40]:8]:8) (signed).
  The `beq` branch at 0x6630 targets 0x6550 and is always taken.
  The `blez` branch at 0x6640 targets 0x66d0, is taken when a0(=[a1+8]) <= 0 (signed), and falls through when a0(=[a1+8]) > 0 (signed).
  The `beq` branch at 0x6648 targets 0x6550 and is always taken.
  The `beq` branch at 0x6650 targets 0x654c and is always taken.
  The `blez` branch at 0x6660 targets 0x66d8, is taken when a0(=[a1+8]) <= 0 (signed), and falls through when a0(=[a1+8]) > 0 (signed).
  The `beq` branch at 0x6668 targets 0x6550 and is always taken.
  The `beq` branch at 0x6670 targets 0x6550 and is always taken.
  The `beq` branch at 0x6680 targets 0x66c0, is taken when a3(=[[ret(kdsp_find_param_info)+40]:8+8]:8) >= a1(=[a1+8]:8) (signed), and falls through when a3(=[[ret(kdsp_find_param_info)+40]:8+8]:8) < a1(=[a1+8]:8) (signed).
  The `beq` branch at 0x6694 targets 0x6550 and is always taken.
  The `beq` branch at 0x66a4 targets 0x6550 and is always taken.
  The `beq` branch at 0x66b8 targets 0x6550 and is always taken.
  The `beq` branch at 0x66c8 targets 0x6550 and is always taken.
  The `beq` branch at 0x66d0 targets 0x6550 and is always taken.
  The `beq` branch at 0x66d8 targets 0x6550 and is always taken.
  The return at 0x6564 has v0 = one of 0x0, 0x1.

- `rad_get_clockgen_params` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x66e0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x66e0-0x674c (108 bytes).
  It occupies 108 bytes.
  The `lw` at 0x66e0 loads 4 bytes from a1 (arg1 at entry) +0x0.
  The `ld` at 0x66f0 loads 8 bytes from a0 (arg0 at entry) +0x1f0.
  The `ld` at 0x66f4 loads 8 bytes from a0 (arg0 at entry) +0x200.
  The `lw` at 0x6714 loads 4 bytes from a0 (arg0 at entry) +0x1b0.
  The `sw` at 0x6724 stores 4 bytes to a1 (arg1 at entry) +0x8.
  The `lw` at 0x6738 loads 4 bytes from a0 (arg0 at entry) +0x1b8.
  The `bne` branch at 0x66ec targets 0x6730, is taken when at(=[a1]) != v0(=0x10000010), and falls through when at(=[a1]) == v0(=0x10000010).
  The `beq` branch at 0x6704 targets 0x6714, is taken when a6(=[a0+512]:8) == v1(=[a0+496]:8+2520), and falls through when a6(=[a0+512]:8) != v1(=[a0+496]:8+2520).
  The `bne` branch at 0x670c targets 0x6744, is taken when a6(=[a0+512]:8) != a5(=[a0+496]:8+2968), and falls through when a6(=[a0+512]:8) == a5(=[a0+496]:8+2968).
  The `beq` branch at 0x6718 targets 0x6738, is taken when a2(=[a0+432]) == a4(=0x1), and falls through when a2(=[a0+432]) != a4(=0x1).
  The `bne` branch at 0x673c targets 0x6724, is taken when a3(=[a0+440]) != a4(=0x1), and falls through when a3(=[a0+440]) == a4(=0x1).
  The `beq` branch at 0x6744 targets 0x6724 and is always taken.
  The return at 0x6728 has v0 = 0x1.
  The return at 0x6730 has v0 = 0x0.

- `rad_set_digital_if_params` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x674c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x674c-0x6794 (72 bytes).
  It occupies 72 bytes.
  The `lw` at 0x674c loads 4 bytes from a1 (arg1 at entry) +0x0.
  The `beq` branch at 0x6760 targets 0x6788, is taken when v0(=[a1]) == at(=0x10000004), and falls through when v0(=[a1]) != at(=0x10000004).
  The `beq` branch at 0x6768 targets 0x6788, is taken when v0(=[a1]) == a3(=0x10000019), and falls through when v0(=[a1]) != a3(=0x10000019).
  The `beq` branch at 0x6770 targets 0x6788, is taken when v0(=[a1]) == a4(=0x1000001b), and falls through when v0(=[a1]) != a4(=0x1000001b).
  The `beq` branch at 0x6778 targets 0x678c, is taken when v0(=[a1]) == a5(=0x1000001c), and falls through when v0(=[a1]) != a5(=0x1000001c).
  The return at 0x6780 has v0 = 0x0.
  The return at 0x678c has v0 = 0x1.

- `rad_set_analog_in_gain` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x6794 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x6794-0x68d4 (320 bytes).
  It occupies 320 bytes.
  The `ld` at 0x67a0 loads 8 bytes from a0 (arg0 at entry) +0x198.
  The `ld` at 0x67a8 loads 8 bytes from [a0+408]:8 +0x2a0.
  3 such `lw` accesses load 4 bytes from [[a0+408]:8+672]:8 +0x7260, including `lw` at 0x681c, `lw` at 0x686c, `lw` at 0x68a4.
  2 such `sw` accesses store 4 bytes to [[a0+408]:8+672]:8 +0x7260, including `sw` at 0x6830, `sw` at 0x6878.
  2 such `sw` accesses store 4 bytes to ?, including `sw` at 0x6834, `sw` at 0x6880.
  The `ld` at 0x6858 loads 8 bytes from ?.
  The `ld` at 0x68ac loads 8 bytes from [[a0+408]:8+672]:8 +0x228.
  The `sw` at 0x68bc stores 4 bytes to [[[a0+408]:8+672]:8+552]:8 +0x7c.
  The `jal` at 0x6808 calls kdsp_db_gain_to_regval with a0=?, a1=a0 at entry (arg0), a2=0x0, a3=?.
  The `bne` branch at 0x67c4 targets 0x67d4, is taken when a0 != at(=[[a0+408]:8+672]:8+23144), and falls through when a0 == at(=[[a0+408]:8+672]:8+23144).
  The `beq` branch at 0x67cc targets 0x67d8 and is always taken.
  The `blez` branch at 0x67e4 targets 0x6884, is taken when s5(=a2) <= 0 (signed), and falls through when s5(=a2) > 0 (signed).
  The `beq` branch at 0x67fc targets 0x68c0 and is always taken.
  The `bltz` branch at 0x6810 targets 0x6838, is taken when v0(=ret(kdsp_db_gain_to_regval)) < 0 (signed), and falls through when v0(=ret(kdsp_db_gain_to_regval)) >= 0 (signed).
  The `beq` branch at 0x684c targets 0x6884, is taken when s1(?) >= s5(=a2) (signed), and falls through when s1(?) < s5(=a2) (signed).
  The `bne` branch at 0x6864 targets 0x6804, is taken when a0(?) != s3(=0x8000000000000000), and falls through when a0(?) == s3(=0x8000000000000000).
  The `beq` branch at 0x687c targets 0x6838 and is always taken.
  The `beq` branch at 0x68cc targets 0x6858 and is always taken.
  The return at 0x68b8 has v0 = [[[a0+408]:8+672]:8+552]:8.

- `rad_set_analog_in_if_params` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x68d4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x68d4-0x698c (184 bytes).
  It occupies 184 bytes.
  The `lw` at 0x68d8 loads 4 bytes from a1 (arg1 at entry) +0x0.
  The `lh` at 0x6930 loads 2 bytes from a1 (arg1 at entry) +0x14.
  The `ld` at 0x6964 loads 8 bytes from a0 (arg0 at entry) +0x198.
  The `lw` at 0x6978 loads 4 bytes from [a0+408]:8 +0x238.
  The `jal` at 0x6944 calls rad_set_analog_in_gain with a0=a0 at entry (arg0), a1=ret(kdsp_fetch_external), a2=?, a3=0x2.
  The `jal` at 0x6974 calls kdsp_fetch_external with a0=a1 at entry (arg1), a1=sp-48, a2=[[a0+408]:8+568], a3=0x8, a4=a2 at entry (arg2), a6=0x10000004, a7=0x1000001b.
  The `beq` branch at 0x68fc targets 0x6960, is taken when v0(=[a1]) == at(=0x10000019), and falls through when v0(=[a1]) != at(=0x10000019).
  The `beq` branch at 0x6904 targets 0x6950, is taken when v0(=[a1]) == a6(=0x10000004), and falls through when v0(=[a1]) != a6(=0x10000004).
  The `beq` branch at 0x690c targets 0x6950, is taken when v0(=[a1]) == a7(=0x1000001b), and falls through when v0(=[a1]) != a7(=0x1000001b).
  The `beq` branch at 0x6914 targets 0x6950, is taken when v0(=[a1]) == t0(=0x1000001c), and falls through when v0(=[a1]) != t0(=0x1000001c).
  The `beq` branch at 0x6920 targets 0x6954 and is always taken.
  The `bne` branch at 0x697c targets 0x6928, is taken when v0(=ret(kdsp_fetch_external)) != 0, and falls through when v0(=ret(kdsp_fetch_external)) == 0.
  The `beq` branch at 0x6984 targets 0x6954 and is always taken.
  The return at 0x6958 has v0 = one of 0x0, 0x1.

- `rad_get_analog_in_if_params` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x698c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x698c-0x6af8 (364 bytes).
  It occupies 364 bytes.
  The `lw` at 0x69a8 loads 4 bytes from a1 (arg1 at entry) +0x0.
  The `ld` at 0x69c0 loads 8 bytes from a0 (arg0 at entry) +0x198.
  The `ld` at 0x69d8 loads 8 bytes from [a0+408]:8 +0x2a0.
  The `lw` at 0x69e4 loads 4 bytes from [a0+408]:8 +0x238.
  2 such `sd` accesses store 8 bytes to ?, including `sd` at 0x6a38, `sd` at 0x6a74.
  The `lw` at 0x6a58 loads 4 bytes from ?.
  3 such `sw` accesses store 4 bytes to a1 (arg1 at entry) +0x8, including `sw` at 0x6acc, `sw` at 0x6ad4, `sw` at 0x6adc.
  The `lw` at 0x6af4 loads 4 bytes from ([[a0+408]:8+672]:8 + one of 0x72b0, 0x72b8) +0x0.
  The `jal` at 0x6a68 calls kdsp_regval_to_db_gain with a0=?, a1=a0 at entry (arg0), a2=0x0, a3=?.
  The `jal` at 0x6a94 calls kdsp_put_external with a0=a1 at entry (arg1), a1=sp-96, a2=[[a0+408]:8+568], a3=0x8, a4=a2 at entry (arg2).
  The `beq` branch at 0x69e0 targets 0x6a04, is taken when a6(=[a1]) == at(=0x10000019), and falls through when a6(=[a1]) != at(=0x10000019).
  The `beq` branch at 0x69ec targets 0x6ac0, is taken when a6(=[a1]) == a4(=0x10000004), and falls through when a6(=[a1]) != a4(=0x10000004).
  The `beq` branch at 0x69f4 targets 0x6ad0, is taken when a6(=[a1]) == a7(=0x1000001c), and falls through when a6(=[a1]) != a7(=0x1000001c).
  The `beq` branch at 0x69fc targets 0x6aa4 and is always taken.
  The `bne` branch at 0x6a0c targets 0x6a1c, is taken when a0 != t8(=[[a0+408]:8+672]:8+23144), and falls through when a0 == t8(=[[a0+408]:8+672]:8+23144).
  The `beq` branch at 0x6a14 targets 0x6a20 and is always taken.
  The `blez` branch at 0x6a24 targets 0x6a78, is taken when s2(=[[a0+408]:8+568]) <= 0 (signed), and falls through when s2(=[[a0+408]:8+568]) > 0 (signed).
  The `beq` branch at 0x6a30 targets 0x6ae0 and is always taken.
  The `beq` branch at 0x6a50 targets 0x6a78, is taken when s0(?) >= s2(=[[a0+408]:8+568]) (signed), and falls through when s0(?) < s2(=[[a0+408]:8+568]) (signed).
  The `beq` branch at 0x6a5c targets 0x6a38, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x6a70 targets 0x6a3c and is always taken.
  The `bne` branch at 0x6ac0 targets 0x6ad8, is taken when s3(=a0) != a0(=[[a0+408]:8+672]:8+23144), and falls through when s3(=a0) == a0(=[[a0+408]:8+672]:8+23144).
  The `beq` branch at 0x6ac8 targets 0x6a9c and is always taken.
  The `beq` branch at 0x6ad0 targets 0x6a9c and is always taken.
  The `beq` branch at 0x6ad8 targets 0x6a9c and is always taken.
  The `beq` branch at 0x6af0 targets 0x6a5c and is always taken.
  The return at 0x6ab8 has v0 = one of 0x0, 0x1.

- `rad_set_analog_out_if_params` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x6af8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x6af8-0x6d6c (628 bytes).
  It occupies 628 bytes.
  The `lw` at 0x6b10 loads 4 bytes from a1 (arg1 at entry) +0x0.
  The `ld` at 0x6b1c loads 8 bytes from a0 (arg0 at entry) +0x198.
  The `ld` at 0x6b38 loads 8 bytes from [a0+408]:8 +0x2a0.
  The `lw` at 0x6b74 loads 4 bytes from a1 (arg1 at entry) +0x8.
  The `lw` at 0x6b78 loads 4 bytes from [[a0+408]:8+672]:8 +0x7244.
  3 such `ld` accesses load 8 bytes from [[a0+408]:8+672]:8 +0x228, including `ld` at 0x6b80, `ld` at 0x6d28, `ld` at 0x6d40.
  The `sw` at 0x6b90 stores 4 bytes to [[a0+408]:8+672]:8 +0x7244.
  The `sw` at 0x6b94 stores 4 bytes to [[[a0+408]:8+672]:8+552]:8 +0x70.
  The `ld` at 0x6be8 loads 8 bytes from ret(kdsp_fetch_external) +0x0.
  The `lw` at 0x6c14 loads 4 bytes from [a0+408]:8 +0x238.
  The `lh` at 0x6c40 loads 2 bytes from a1 (arg1 at entry) +0x14.
  3 such `lw` accesses load 4 bytes from [[a0+408]:8+672]:8 +0x7260, including `lw` at 0x6cac, `lw` at 0x6d04, `lw` at 0x6d2c.
  2 such `sw` accesses store 4 bytes to [[a0+408]:8+672]:8 +0x7260, including `sw` at 0x6cc8, `sw` at 0x6d18.
  2 such `sw` accesses store 4 bytes to ?, including `sw` at 0x6ccc, `sw` at 0x6d20.
  The `ld` at 0x6cf8 loads 8 bytes from ?.
  The `sw` at 0x6d34 stores 4 bytes to [[[a0+408]:8+672]:8+552]:8 +0x7c.
  2 such `sw` accesses store 4 bytes to [[a0+408]:8+672]:8 +0x7270, including `sw` at 0x6d38, `sw` at 0x6d54.
  The `sw` at 0x6d44 stores 4 bytes to [[[a0+408]:8+672]:8+552]:8 +0x90.
  The `sw` at 0x6d4c stores 4 bytes to a0 (arg0 at entry) +0x1a0.
  The `jal` at 0x6be0 calls kdsp_fetch_external with a0=a1 at entry (arg1), a1=sp-96, a2=0x1, a3=0x8, a4=a2 at entry (arg2), a6=0x10000000, a7=0x1000001c.
  The `jal` at 0x6c18 calls kdsp_fetch_external with a0=a1 at entry (arg1), a1=sp-88, a2=[[a0+408]:8+568], a3=0x8, a4=a2 at entry (arg2), a6=0x10000000, a7=0x1000001c.
  The `jal` at 0x6c48 calls kdsp_find_param_info with a0=a0 at entry (arg0), a1=0x10000019, a2=[a1+20]:2, a3=?.
  The `jal` at 0x6c8c calls kdsp_db_gain_to_regval with a0=?, a1=a0 at entry (arg0), a2=0x0, a3=?, a4=0xff.
  The `beq` branch at 0x6b34 targets 0x6bc4, is taken when v0(=[a1]) == t2(=0x10000019), and falls through when v0(=[a1]) != t2(=0x10000019).
  The `beq` branch at 0x6b44 targets 0x6b6c, is taken when v0(=[a1]) == at(=0x1000001d), and falls through when v0(=[a1]) != at(=0x1000001d).
  The `beq` branch at 0x6b4c targets 0x6bd8, is taken when v0(=[a1]) == a7(=0x1000001c), and falls through when v0(=[a1]) != a7(=0x1000001c).
  The `beq` branch at 0x6b54 targets 0x6b9c, is taken when v0(=[a1]) == a1(=0x10000004), and falls through when v0(=[a1]) != a1(=0x10000004).
  The `beq` branch at 0x6b5c targets 0x6b98, is taken when v0(=[a1]) == t0(=0x1000001b), and falls through when v0(=[a1]) != t0(=0x1000001b).
  The `beq` branch at 0x6b64 targets 0x6ba0 and is always taken.
  The `bne` branch at 0x6b6c targets 0x6bb8, is taken when s1(=a0) != a0(=[[a0+408]:8+672]:8+23568), and falls through when s1(=a0) == a0(=[[a0+408]:8+672]:8+23568).
  The `beq` branch at 0x6bbc targets 0x6ba0 and is always taken.
  The `beq` branch at 0x6bc8 targets 0x6c10, is taken when a0 == v1(=[[a0+408]:8+672]:8+23568), and falls through when a0 != v1(=[[a0+408]:8+672]:8+23568).
  The `beq` branch at 0x6bd0 targets 0x6ba0 and is always taken.
  The `beq` branch at 0x6bf8 targets 0x6d50, is taken when a0(?) == a1(=0x12), and falls through when a0(?) != a1(=0x12).
  The `beq` branch at 0x6c00 targets 0x6d38, is taken when a0(?) == a1(=0x10), and falls through when a0(?) != a1(=0x10).
  The `beq` branch at 0x6c08 targets 0x6ba0 and is always taken.
  The `bne` branch at 0x6c24 targets 0x6c34, is taken when v0(=ret(kdsp_fetch_external)) != 0, and falls through when v0(=ret(kdsp_fetch_external)) == 0.
  The `beq` branch at 0x6c2c targets 0x6ba0 and is always taken.
  The `blez` branch at 0x6c74 targets 0x6d24, is taken when a3(?) <= 0 (signed), and falls through when a3(?) > 0 (signed).
  The `beq` branch at 0x6c80 targets 0x6d60 and is always taken.
  The `bltz` branch at 0x6ca0 targets 0x6cd0, is taken when v0(=ret(kdsp_db_gain_to_regval)) < 0 (signed), and falls through when v0(=ret(kdsp_db_gain_to_regval)) >= 0 (signed).
  The `beq` branch at 0x6ce4 targets 0x6d24, is taken when s2(?) >= t1(?) (signed), and falls through when s2(?) < t1(?) (signed).
  The `bne` branch at 0x6cfc targets 0x6c88, is taken when a0(?) != a2(=0x8000000000000000), and falls through when a0(?) == a2(=0x8000000000000000).
  The `beq` branch at 0x6d1c targets 0x6cd0 and is always taken.
  The `beq` branch at 0x6d30 targets 0x6b98 and is always taken.
  The `beq` branch at 0x6d48 targets 0x6b98 and is always taken.
  The `beq` branch at 0x6d58 targets 0x6d40 and is always taken.
  The `beq` branch at 0x6d64 targets 0x6cf0 and is always taken.
  The return at 0x6bb0 has v0 = one of 0x0, 0x1.

- `rad_get_analog_out_if_params` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x6d6c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x6d6c-0x6f00 (404 bytes).
  It occupies 404 bytes.
  The `lw` at 0x6d84 loads 4 bytes from a1 (arg1 at entry) +0x0.
  The `ld` at 0x6d90 loads 8 bytes from a0 (arg0 at entry) +0x198.
  The `ld` at 0x6da8 loads 8 bytes from [a0+408]:8 +0x2a0.
  The `lw` at 0x6db4 loads 4 bytes from [a0+408]:8 +0x238.
  The `lw` at 0x6dcc loads 4 bytes from [[a0+408]:8+672]:8 +0x7270.
  The `lw` at 0x6dd8 loads 4 bytes from sym(.data) +0x7430.
  3 such `sw` accesses store 4 bytes to a1 (arg1 at entry) +0x8, including `sw` at 0x6ddc, `sw` at 0x6e1c, `sw` at 0x6e30.
  The `lw` at 0x6e0c loads 4 bytes from [[a0+408]:8+672]:8 +0x7244.
  The `lw` at 0x6e28 loads 4 bytes from sym(.data) +0x7428.
  The `ld` at 0x6e60 loads 8 bytes from sym(.bss) +0x58.
  2 such `sd` accesses store 8 bytes to ?, including `sd` at 0x6e8c, `sd` at 0x6ee4.
  The `lw` at 0x6ea8 loads 4 bytes from ?.
  The `lw` at 0x6efc loads 4 bytes from [[a0+408]:8+672]:8 +0x72c0.
  The `jal` at 0x6e34 calls kdsp_find_param_info with a0=a0 at entry (arg0), a1=0x10000019, a2=a2 at entry (arg2), a3=a3 at entry (arg3), a6=0x1000001d, a7=0x1000001c.
  The `jal` at 0x6e7c calls kdsp_put_external with a0=a1 at entry (arg1), a1=sp-80, a2=[[a0+408]:8+568], a3=0x8, a4=a2 at entry (arg2), a7=sp-80.
  The `jal` at 0x6ecc calls kdsp_regval_to_db_gain with a0=?, a1=a0 at entry (arg0), a2=0x0, a3=?, a7=sp-80.
  The `beq` branch at 0x6db0 targets 0x6e34, is taken when v0(=[a1]) == t2(=0x10000019), and falls through when v0(=[a1]) != t2(=0x10000019).
  The `beq` branch at 0x6dbc targets 0x6dfc, is taken when v0(=[a1]) == a6(=0x1000001d), and falls through when v0(=[a1]) != a6(=0x1000001d).
  The `bne` branch at 0x6dc4 targets 0x6e20, is taken when v0(=[a1]) != a7(=0x1000001c), and falls through when v0(=[a1]) == a7(=0x1000001c).
  The `beq` branch at 0x6dd0 targets 0x6e28, is taken when t8(=[[[a0+408]:8+672]:8+29296]) == t9(=0x2), and falls through when t8(=[[[a0+408]:8+672]:8+29296]) != t9(=0x2).
  The `beq` branch at 0x6dfc targets 0x6e0c, is taken when s1(=a0) == a0(=[[a0+408]:8+672]:8+23568), and falls through when s1(=a0) != a0(=[[a0+408]:8+672]:8+23568).
  The `beq` branch at 0x6e04 targets 0x6de8 and is always taken.
  The `beq` branch at 0x6e18 targets 0x6de0 and is always taken.
  The `beq` branch at 0x6e20 targets 0x6de4 and is always taken.
  The `beq` branch at 0x6e2c targets 0x6de0 and is always taken.
  The `bne` branch at 0x6e44 targets 0x6e60, is taken when s1(=a0) != a0(=[[a0+408]:8+672]:8+23568), and falls through when s1(=a0) == a0(=[[a0+408]:8+672]:8+23568).
  The `blez` branch at 0x6e4c targets 0x6e70, is taken when s3(=[[a0+408]:8+568]) <= 0 (signed), and falls through when s3(=[[a0+408]:8+568]) > 0 (signed).
  The `beq` branch at 0x6e58 targets 0x6ef0 and is always taken.
  The `beq` branch at 0x6e84 targets 0x6de0 and is always taken.
  The `beq` branch at 0x6ea0 targets 0x6ee8, is taken when a0(?) >= s3(=[[a0+408]:8+568]) (signed), and falls through when a0(?) < s3(=[[a0+408]:8+568]) (signed).
  The `beq` branch at 0x6ebc targets 0x6e8c, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `beq` branch at 0x6ee0 targets 0x6e90 and is always taken.
  The `beq` branch at 0x6ee8 targets 0x6e70 and is always taken.
  The `beq` branch at 0x6ef8 targets 0x6eac and is always taken.
  The return at 0x6df4 has v0 = one of 0x0, 0x1.

- `rad_vl_write_MUX_SEL_MIO` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x6f00 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x6f00-0x6f80 (128 bytes).
  It occupies 128 bytes.
  6 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x228, including `ld` at 0x6f14, `ld` at 0x6f28, `ld` at 0x6f40.
  2 such `sw` accesses store 4 bytes to [a0+552]:8 +0x8c, including `sw` at 0x6f20, `sw` at 0x6f7c.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x7248, including `lw` at 0x6f24, `lw` at 0x6f38.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x7248, including `sw` at 0x6f30, `sw` at 0x6f48.
  2 such `sw` accesses store 4 bytes to [a0+552]:8 +0x4c, including `sw` at 0x6f34, `sw` at 0x6f50.
  2 such `sw` accesses store 4 bytes to [a0+552]:8 +0x88, including `sw` at 0x6f5c, `sw` at 0x6f6c.
  The `sw` at 0x6f68 stores 4 bytes to a0 (arg0 at entry) +0x7268.
  The `lw` at 0x6f74 loads 4 bytes from a0 (arg0 at entry) +0x726c.
  The `bgez` branch at 0x6f4c targets 0x6f10, is taken when a3(?) >= 0 (signed), and falls through when a3(?) < 0 (signed).
  The return at 0x6f78 has v0 = ?.

- `rad_vl_write_MUX_SEL_RADICAL` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x6f80 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x6f80-0x6f8c (12 bytes).
  It occupies 12 bytes.
  The `ld` at 0x6f80 loads 8 bytes from a0 (arg0 at entry) +0x228.
  The `sw` at 0x6f88 stores 4 bytes to [a0+552]:8 +0x7c.
  The return at 0x6f84 has v0 = ?.

- `rad_vl_write_MUX_SEL` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x6f8c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x6f8c-0x6fd4 (72 bytes).
  It occupies 72 bytes.
  The `lh` at 0x6f8c loads 2 bytes from a0 (arg0 at entry) +0x21a.
  The `jal` at 0x6fb4 calls rad_vl_write_MUX_SEL_RADICAL with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=0xd, a4=[a0+538]:2.
  The `jal` at 0x6fc4 calls rad_vl_write_MUX_SEL_MIO with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=0xd, a4=[a0+538]:2.
  The `beq` branch at 0x6f9c targets 0x6fc4, is taken when a4(=[a0+538]:2) == at(=0x7), and falls through when a4(=[a0+538]:2) != at(=0x7).
  The `beq` branch at 0x6fa4 targets 0x6fb4, is taken when a4(=[a0+538]:2) == a3(=0xd), and falls through when a4(=[a0+538]:2) != a3(=0xd).
  The `beq` branch at 0x6fbc targets 0x6fac and is always taken.
  The `beq` branch at 0x6fcc targets 0x6fac and is always taken.
  The return at 0x6fac has v0 = one of ?, ret(rad_vl_write_MUX_SEL_RADICAL), ret(rad_vl_write_MUX_SEL_MIO).

- `rad_vl_set_clockgen_MIO` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x6fd4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x6fd4-0x71d0 (508 bytes).
  It occupies 508 bytes.
  The `ld` at 0x6fdc loads 8 bytes from a0 (arg0 at entry) +0x1f0.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x1b8, including `lw` at 0x7038, `lw` at 0x7060, `lw` at 0x7098.
  3 such `lw` accesses load 4 bytes from [a0+496]:8 +0x7274, including `lw` at 0x7050, `lw` at 0x7080, `lw` at 0x71a8.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x1b0, including `lw` at 0x706c, `lw` at 0x713c, `lw` at 0x7168.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x208, including `lw` at 0x70ac, `lw` at 0x714c.
  The `lw` at 0x70bc loads 4 bytes from (sym(.rodata) + ([a0+520] << 0x3)) +0x0.
  The `lw` at 0x70c0 loads 4 bytes from (sym(.rodata) + ([a0+520] << 0x3)) +0x4.
  2 such `sw` accesses store 4 bytes to [a0+496]:8 +0x7274, including `sw` at 0x70e0, `sw` at 0x71c4.
  The `jal` at 0x70dc calls rad_vl_write_MUX_SEL_MIO with a0=[a0+496]:8, a1=?, a2=?, a3=([a0+520] << 0x3), a4=one of 0x0, 0x1, 0x2, a5=[a0+496]:8+26240, a6=[a0+496]:8+26240.
  The `jal` at 0x70e4 calls rad_update_ksync with a0=[a0+496]:8, a1=?, a2=?, a3=?.
  The `bne` branch at 0x7004 targets 0x7010, is taken when s3(=[a0+496]:8+2968) != a1, and falls through when s3(=[a0+496]:8+2968) == a1.
  The `bne` branch at 0x700c targets 0x7038, is taken when a0 != v0(=[a0+496]:8+26240), and falls through when a0 == v0(=[a0+496]:8+26240).
  The `bne` branch at 0x7014 targets 0x702c, is taken when s2(=a1) != at(=[a0+496]:8+2520), and falls through when s2(=a1) == at(=[a0+496]:8+2520).
  The `beq` branch at 0x701c targets 0x7030, is taken when s1(=a0) == v0(=[a0+496]:8+26240), and falls through when s1(=a0) != v0(=[a0+496]:8+26240).
  The `beq` branch at 0x7024 targets 0x7030 and is always taken.
  The `beq` branch at 0x7030 targets 0x7048, is taken when v0(=one of 0x0, 0x1) == 0, and falls through when v0(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x7040 targets 0x713c, is taken when v0(=[a0+440]) == a4(=0x1), and falls through when v0(=[a0+440]) != a4(=0x1).
  The `bne` branch at 0x7048 targets 0x7080, is taken when s3(=[a0+496]:8+2968) != s2(=a1), and falls through when s3(=[a0+496]:8+2968) == s2(=a1).
  The `beq` branch at 0x7054 targets 0x7088, is taken when s1(=a0) == a5(=[a0+496]:8+26240), and falls through when s1(=a0) != a5(=[a0+496]:8+26240).
  The `bne` branch at 0x7064 targets 0x7088, is taken when v1(=[a0+440]) != a4(=0x1), and falls through when v1(=[a0+440]) == a4(=0x1).
  The `bne` branch at 0x7070 targets 0x7088, is taken when a0(=[a0+432]) != a4(=0x1), and falls through when a0(=[a0+432]) == a4(=0x1).
  The `beq` branch at 0x7078 targets 0x70ac and is always taken.
  The `bne` branch at 0x7088 targets 0x70a8, is taken when s2(=a1) != a1(=[a0+496]:8+2520), and falls through when s2(=a1) == a1(=[a0+496]:8+2520).
  The `beq` branch at 0x7090 targets 0x70a4, is taken when s1(=a0) == a6(=[a0+496]:8+26240), and falls through when s1(=a0) != a6(=[a0+496]:8+26240).
  The `beq` branch at 0x709c targets 0x7168, is taken when a2(=[a0+440]) == a4(=0x1), and falls through when a2(=[a0+440]) != a4(=0x1).
  The `bne` branch at 0x70f0 targets 0x710c, is taken when s3(=[a0+496]:8+2968) != s2(=a1), and falls through when s3(=[a0+496]:8+2968) == s2(=a1).
  The `beq` branch at 0x70fc targets 0x7110, is taken when s1(=a0) == a3(=[a0+496]:8+26240), and falls through when s1(=a0) != a3(=[a0+496]:8+26240).
  The `beq` branch at 0x7104 targets 0x7128 and is always taken.
  The `bne` branch at 0x7110 targets 0x7120, is taken when s2(=a1) != a4(=[a0+496]:8+2520), and falls through when s2(=a1) == a4(=[a0+496]:8+2520).
  The `bne` branch at 0x7118 targets 0x7104, is taken when s1(=a0) != a5(=[a0+496]:8+26240), and falls through when s1(=a0) == a5(=[a0+496]:8+26240).
  The `bne` branch at 0x7140 targets 0x7048, is taken when a7(=[a0+432]) != a4(=0x1), and falls through when a7(=[a0+432]) == a4(=0x1).
  The `bne` branch at 0x7148 targets 0x717c, is taken when s3(=[a0+496]:8+2968) != s2(=a1), and falls through when s3(=[a0+496]:8+2968) == s2(=a1).
  The `beq` branch at 0x7154 targets 0x7180, is taken when s1(=a0) == t0(=[a0+496]:8+26240), and falls through when s1(=a0) != t0(=[a0+496]:8+26240).
  The `beq` branch at 0x7160 targets 0x71a8 and is always taken.
  The `bne` branch at 0x716c targets 0x70a8, is taken when t1(=[a0+432]) != a4(=0x1), and falls through when t1(=[a0+432]) == a4(=0x1).
  The `beq` branch at 0x7174 targets 0x70a8 and is always taken.
  The `bne` branch at 0x7180 targets 0x71a4, is taken when s2(=a1) != t2(=[a0+496]:8+2520), and falls through when s2(=a1) == t2(=[a0+496]:8+2520).
  The `beq` branch at 0x718c targets 0x71a4, is taken when s1(=a0) == t3(=[a0+496]:8+26240), and falls through when s1(=a0) != t3(=[a0+496]:8+26240).
  The `beq` branch at 0x7198 targets 0x71a8 and is always taken.
  The `bne` branch at 0x71c0 targets 0x7084, is taken when s3(=[a0+496]:8+2968) != s2(=a1), and falls through when s3(=[a0+496]:8+2968) == s2(=a1).
  The `beq` branch at 0x71c8 targets 0x7054 and is always taken.
  The return at 0x7134 has v0 = one of 0x0, 0x1.
  The instructions from 0x71a0 to 0x71a0 are not reached by any path from the entry, and their branches are not listed.

- `rad_vl_set_clockgen_RADICAL` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x71d0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x71d0-0x72ec (284 bytes).
  It occupies 284 bytes.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x208, including `lw` at 0x71d8, `lw` at 0x7250, `lw` at 0x72d4.
  The `ld` at 0x71ec loads 8 bytes from a0 (arg0 at entry) +0x1f0.
  The `lw` at 0x7200 loads 4 bytes from [a0+496]:8 +0x7274.
  2 such `sw` accesses store 4 bytes to [a0+496]:8 +0x7274, including `sw` at 0x7224, `sw` at 0x7284.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x1b8, including `lw` at 0x7228, `lw` at 0x7240.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x1b0, including `lw` at 0x72c4, `lw` at 0x72d8.
  The `jal` at 0x7280 calls rad_vl_write_MUX_SEL_RADICAL with a0=[a0+496]:8, a1=?, a2=?, a3=?, a4=one of 0x0, 0x1, 0x2, a6=0x6, a7=-0xc1.
  The `jal` at 0x7288 calls rad_update_ksync with a0=[a0+496]:8, a1=?, a2=?, a3=?.
  The `bne` branch at 0x7220 targets 0x7234, is taken when s8(=[a0+496]:8+2968) != a1, and falls through when s8(=[a0+496]:8+2968) == a1.
  The `beq` branch at 0x7230 targets 0x72c4, is taken when t1(=[a0+440]) == a4(=0x1), and falls through when t1(=[a0+440]) != a4(=0x1).
  The `bne` branch at 0x7238 targets 0x724c, is taken when s1(=a1) != t2(=[a0+496]:8+2520), and falls through when s1(=a1) == t2(=[a0+496]:8+2520).
  The `beq` branch at 0x7244 targets 0x72d8, is taken when t3(=[a0+440]) == a4(=0x1), and falls through when t3(=[a0+440]) != a4(=0x1).
  The `beq` branch at 0x7294 targets 0x72bc, is taken when s8(=[a0+496]:8+2968) == s1(=a1), and falls through when s8(=[a0+496]:8+2968) != s1(=a1).
  The `beq` branch at 0x72a0 targets 0x72bc, is taken when s1(=a1) == t0(=[a0+496]:8+2520), and falls through when s1(=a1) != t0(=[a0+496]:8+2520).
  The `beq` branch at 0x72bc targets 0x72a8 and is always taken.
  The `bne` branch at 0x72c8 targets 0x7238, is taken when t1(=[a0+432]) != a4(=0x1), and falls through when t1(=[a0+432]) == a4(=0x1).
  The `beq` branch at 0x72d0 targets 0x7254 and is always taken.
  The `bne` branch at 0x72dc targets 0x7250, is taken when t2(=[a0+432]) != a4(=0x1), and falls through when t2(=[a0+432]) == a4(=0x1).
  The `beq` branch at 0x72e4 targets 0x7250 and is always taken.
  The return at 0x72b4 has v0 = one of 0x0, 0x1.

- `rad_vl_set_clockgen` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x72ec (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x72ec-0x7330 (68 bytes).
  It occupies 68 bytes.
  The `ld` at 0x72ec loads 8 bytes from a0 (arg0 at entry) +0x1f0.
  The `lh` at 0x72f0 loads 2 bytes from [a0+496]:8 +0x21a.
  The `jal` at 0x7304 calls rad_vl_set_clockgen_RADICAL with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x7320 calls rad_vl_set_clockgen_MIO with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0x72fc targets 0x7320, is taken when at(=[[a0+496]:8+538]:2) == v0(=0x7), and falls through when at(=[[a0+496]:8+538]:2) != v0(=0x7).
  The `beq` branch at 0x7328 targets 0x7310 and is always taken.
  The return at 0x7318 has v0 = one of ret(rad_vl_set_clockgen_RADICAL), ret(rad_vl_set_clockgen_MIO).

- `rad_update_ksync` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x7330 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x7330-0x7624 (756 bytes).
  It occupies 756 bytes.
  The `ld` at 0x733c loads 8 bytes from a0 (arg0 at entry) +0x72e8.
  20 such `lw` accesses load 4 bytes from ?, including `lw` at 0x73d4, `lw` at 0x7424, `lw` at 0x7434.
  5 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x228, including `ld` at 0x73e4, `ld` at 0x73ec, `ld` at 0x7498.
  2 such `sw` accesses store 4 bytes to [a0+552]:8 +0xa4, including `sw` at 0x73e8, `sw` at 0x74a4.
  2 such `sw` accesses store 4 bytes to [a0+552]:8 +0xa0, including `sw` at 0x73f0, `sw` at 0x74bc.
  3 such `sw` accesses store 4 bytes to ?, including `sw` at 0x73f4, `sw` at 0x73f8, `sw` at 0x748c.
  The `bne` branch at 0x735c targets 0x7380, is taken when v0(=[a0+29416]:8) < at(=0xfa24e2) (signed), and falls through when v0(=[a0+29416]:8) >= at(=0xfa24e2) (signed).
  The `bne` branch at 0x7370 targets 0x7380, is taken when v1(=0x1029fa0) < v0(=[a0+29416]:8) (signed), and falls through when v1(=0x1029fa0) >= v0(=[a0+29416]:8) (signed).
  The `beq` branch at 0x7378 targets 0x73a0 and is always taken.
  The `bne` branch at 0x738c targets 0x7448, is taken when v0(=[a0+29416]:8) < a1(=0x12b3123) (signed), and falls through when v0(=[a0+29416]:8) >= a1(=0x12b3123) (signed).
  The `bne` branch at 0x7394 targets 0x7594, is taken when a4(?) != 0, and falls through when a4(?) == 0.
  The `beq` branch at 0x73bc targets 0x7410 and is always taken.
  The `beq` branch at 0x73c4 targets 0x75a0, is taken when t1(=one of 0x0, 0x1) == 0, and falls through when t1(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x73dc targets 0x7608, is taken when a4(=0x11ffe89) == t8(?), and falls through when a4(=0x11ffe89) != t8(?).
  The `beq` branch at 0x73fc targets 0x7550, is taken when a7(=one of 0x0, 0x1) == 0, and falls through when a7(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x7408 targets 0x744c, is taken when v1(?) == 0, and falls through when v1(?) != 0.
  The `beq` branch at 0x7410 targets 0x73c4, is taken when v0(?) == t2(=0x1), and falls through when v0(?) != t2(=0x1).
  The `beq` branch at 0x7418 targets 0x7560, is taken when t1(=one of 0x0, 0x1) == 0, and falls through when t1(=one of 0x0, 0x1) != 0.
  The `bne` branch at 0x742c targets 0x73e4, is taken when t0(=0x54fd8f) != a1(?), and falls through when t0(=0x54fd8f) == a1(?).
  The `bne` branch at 0x7438 targets 0x73e4, is taken when a6(=0x400166b) != t8(?), and falls through when a6(=0x400166b) == t8(?).
  The `beq` branch at 0x7440 targets 0x73fc and is always taken.
  The `beq` branch at 0x7450 targets 0x74c4 and is always taken.
  The `beq` branch at 0x745c targets 0x74c0, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `beq` branch at 0x747c targets 0x74c0, is taken when t9(?) == v0(=one of 0x0, 0x1), and falls through when t9(?) != v0(=one of 0x0, 0x1).
  The `beq` branch at 0x74c0 targets 0x7534, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `beq` branch at 0x74e8 targets 0x7508, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `bne` branch at 0x74f0 targets 0x745c, is taken when a7(=one of 0x0, 0x1) != 0, and falls through when a7(=one of 0x0, 0x1) == 0.
  The `bne` branch at 0x74f8 targets 0x7458, is taken when t1(=one of 0x0, 0x1) != 0, and falls through when t1(=one of 0x0, 0x1) == 0.
  The `beq` branch at 0x7500 targets 0x745c and is always taken.
  The `beq` branch at 0x7508 targets 0x74c0, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `beq` branch at 0x7524 targets 0x74c0, is taken when (t0(?) & 0x100) == 0, and falls through when (t0(?) & 0x100) != 0.
  The `beq` branch at 0x752c targets 0x7484 and is always taken.
  The `bne` branch at 0x7534 targets 0x7548, is taken when a7(=one of 0x0, 0x1) != 0, and falls through when a7(=one of 0x0, 0x1) == 0.
  The `beq` branch at 0x753c targets 0x761c, is taken when t1(=one of 0x0, 0x1) == 0, and falls through when t1(=one of 0x0, 0x1) != 0.
  The `bne` branch at 0x7550 targets 0x7408, is taken when t1(=one of 0x0, 0x1) != 0, and falls through when t1(=one of 0x0, 0x1) == 0.
  The `beq` branch at 0x7558 targets 0x7450 and is always taken.
  The `beq` branch at 0x7560 targets 0x75e0, is taken when a7(=one of 0x0, 0x1) == 0, and falls through when a7(=one of 0x0, 0x1) != 0.
  The `bne` branch at 0x7578 targets 0x73e4, is taken when a4(=0xacfd8f) != t8(?), and falls through when a4(=0xacfd8f) == t8(?).
  The `bne` branch at 0x7584 targets 0x73e4, is taken when t9(=0x4001693) != t8(?), and falls through when t9(=0x4001693) == t8(?).
  The `beq` branch at 0x758c targets 0x73fc and is always taken.
  The `beq` branch at 0x7598 targets 0x744c and is always taken.
  The `beq` branch at 0x75a0 targets 0x75e0, is taken when a7(=one of 0x0, 0x1) == 0, and falls through when a7(=one of 0x0, 0x1) != 0.
  The `bne` branch at 0x75bc targets 0x73e4, is taken when a4(=0x39ff83) != at(?), and falls through when a4(=0x39ff83) == at(?).
  The `bne` branch at 0x75d0 targets 0x73e4, is taken when t8(=0x8001892) != at(?), and falls through when t8(=0x8001892) == at(?).
  The `beq` branch at 0x75d8 targets 0x73fc and is always taken.
  The `bne` branch at 0x75ec targets 0x73e4, is taken when at(?) != a4(?), and falls through when at(?) == a4(?).
  The `beq` branch at 0x75f8 targets 0x73fc, is taken when t8(?) == a5(?), and falls through when t8(?) != a5(?).
  The `beq` branch at 0x7600 targets 0x73e8 and is always taken.
  The `bne` branch at 0x760c targets 0x73e4, is taken when t3(=0x8001866) != at(?), and falls through when t3(=0x8001866) == at(?).
  The `beq` branch at 0x7614 targets 0x73fc and is always taken.
  The `beq` branch at 0x761c targets 0x7548 and is always taken.
  The return at 0x7548 has v0 = one of 0x0, 0x1.

- `kdsp_idbg_rad_dump_subsys` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x7624 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x7624-0x785c (568 bytes).
  It occupies 568 bytes.
  The `lw` at 0x7624 loads 4 bytes from a0 (arg0 at entry) +0x230.
  The `lw` at 0x7648 loads 4 bytes from a0 (arg0 at entry) +0x24c.
  The `lw` at 0x764c loads 4 bytes from a0 (arg0 at entry) +0x248.
  The `lw` at 0x7658 loads 4 bytes from a0 (arg0 at entry) +0x254.
  The `lw` at 0x765c loads 4 bytes from a0 (arg0 at entry) +0x250.
  The `lw` at 0x7668 loads 4 bytes from a0 (arg0 at entry) +0x25c.
  The `lw` at 0x766c loads 4 bytes from a0 (arg0 at entry) +0x258.
  The `lw` at 0x7678 loads 4 bytes from a0 (arg0 at entry) +0x264.
  The `lw` at 0x767c loads 4 bytes from a0 (arg0 at entry) +0x260.
  The `lw` at 0x7688 loads 4 bytes from a0 (arg0 at entry) +0x26c.
  The `lw` at 0x768c loads 4 bytes from a0 (arg0 at entry) +0x268.
  The `lw` at 0x7698 loads 4 bytes from a0 (arg0 at entry) +0x274.
  The `lw` at 0x769c loads 4 bytes from a0 (arg0 at entry) +0x270.
  The `lw` at 0x76a8 loads 4 bytes from a0 (arg0 at entry) +0x27c.
  The `lw` at 0x76ac loads 4 bytes from a0 (arg0 at entry) +0x278.
  The `lw` at 0x76b8 loads 4 bytes from a0 (arg0 at entry) +0x284.
  The `lw` at 0x76bc loads 4 bytes from a0 (arg0 at entry) +0x280.
  The `lw` at 0x76c8 loads 4 bytes from a0 (arg0 at entry) +0x288.
  The `lw` at 0x76d4 loads 4 bytes from a0 (arg0 at entry) +0x290.
  The `lw` at 0x76d8 loads 4 bytes from a0 (arg0 at entry) +0x28c.
  The `lw` at 0x76e4 loads 4 bytes from a0 (arg0 at entry) +0x298.
  The `lw` at 0x76e8 loads 4 bytes from a0 (arg0 at entry) +0x294.
  The `lw` at 0x76f4 loads 4 bytes from a0 (arg0 at entry) +0x2a0.
  The `lw` at 0x76f8 loads 4 bytes from a0 (arg0 at entry) +0x29c.
  The `lw` at 0x7704 loads 4 bytes from a0 (arg0 at entry) +0x2a8.
  The `lw` at 0x7708 loads 4 bytes from a0 (arg0 at entry) +0x2a4.
  The `lw` at 0x7714 loads 4 bytes from a0 (arg0 at entry) +0x2b0.
  The `lw` at 0x7718 loads 4 bytes from a0 (arg0 at entry) +0x2ac.
  The `lw` at 0x7724 loads 4 bytes from a0 (arg0 at entry) +0x2b8.
  The `lw` at 0x7728 loads 4 bytes from a0 (arg0 at entry) +0x2b4.
  The `lw` at 0x7734 loads 4 bytes from a0 (arg0 at entry) +0x2c4.
  The `lw` at 0x7738 loads 4 bytes from a0 (arg0 at entry) +0x2c0.
  The `lw` at 0x773c loads 4 bytes from a0 (arg0 at entry) +0x2bc.
  The `lw` at 0x7750 loads 4 bytes from a0 (arg0 at entry) +0x7248.
  The `lw` at 0x7754 loads 4 bytes from a0 (arg0 at entry) +0x724c.
  The `lw` at 0x7760 loads 4 bytes from a0 (arg0 at entry) +0x7258.
  The `lw` at 0x7764 loads 4 bytes from a0 (arg0 at entry) +0x7250.
  The `lw` at 0x7770 loads 4 bytes from a0 (arg0 at entry) +0x725c.
  The `lw` at 0x7774 loads 4 bytes from a0 (arg0 at entry) +0x7254.
  The `lw` at 0x7780 loads 4 bytes from a0 (arg0 at entry) +0x7240.
  The `lw` at 0x7784 loads 4 bytes from a0 (arg0 at entry) +0x7244.
  The `lw` at 0x7790 loads 4 bytes from a0 (arg0 at entry) +0x7284.
  The `lw` at 0x7794 loads 4 bytes from a0 (arg0 at entry) +0x7280.
  The `lw` at 0x7798 loads 4 bytes from a0 (arg0 at entry) +0x727c.
  The `lw` at 0x779c loads 4 bytes from a0 (arg0 at entry) +0x7278.
  The `lw` at 0x77a8 loads 4 bytes from a0 (arg0 at entry) +0x7294.
  The `lw` at 0x77ac loads 4 bytes from a0 (arg0 at entry) +0x7290.
  The `lw` at 0x77b0 loads 4 bytes from a0 (arg0 at entry) +0x728c.
  The `lw` at 0x77b4 loads 4 bytes from a0 (arg0 at entry) +0x7288.
  The `lw` at 0x77c0 loads 4 bytes from a0 (arg0 at entry) +0x729c.
  The `lw` at 0x77c4 loads 4 bytes from a0 (arg0 at entry) +0x7298.
  The `lw` at 0x77c8 loads 4 bytes from a0 (arg0 at entry) +0x72a4.
  The `lw` at 0x77cc loads 4 bytes from a0 (arg0 at entry) +0x72a0.
  The `lw` at 0x77d8 loads 4 bytes from a0 (arg0 at entry) +0x7270.
  The `lw` at 0x77dc loads 4 bytes from a0 (arg0 at entry) +0x726c.
  The `lw` at 0x77e0 loads 4 bytes from a0 (arg0 at entry) +0x7268.
  The `lw` at 0x77e4 loads 4 bytes from a0 (arg0 at entry) +0x7264.
  The `lw` at 0x77e8 loads 4 bytes from a0 (arg0 at entry) +0x7274.
  The `lw` at 0x77f4 loads 4 bytes from a0 (arg0 at entry) +0x72d8.
  The `lw` at 0x77f8 loads 4 bytes from a0 (arg0 at entry) +0x72d4.
  The `lw` at 0x77fc loads 4 bytes from a0 (arg0 at entry) +0x72d0.
  The `lw` at 0x7800 loads 4 bytes from a0 (arg0 at entry) +0x72cc.
  The `ld` at 0x780c loads 8 bytes from a0 (arg0 at entry) +0x72e0.
  The `ld` at 0x7810 loads 8 bytes from a0 (arg0 at entry) +0x72e8.
  The `lw` at 0x7814 loads 4 bytes from a0 (arg0 at entry) +0x72f0.
  The `lbu` at 0x7820 loads 1 byte from a0 (arg0 at entry) +0x7309.
  The `lbu` at 0x7824 loads 1 byte from a0 (arg0 at entry) +0x7303.
  The `jal` at 0x7640 calls qprintf with a0=sym(.rodata), a1=[a0+560], a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x7650 calls qprintf with a0=sym(.rodata), a1=[a0+584], a2=[a0+588], a3=?.
  The `jal` at 0x7660 calls qprintf with a0=sym(.rodata), a1=[a0+592], a2=[a0+596], a3=?.
  The `jal` at 0x7670 calls qprintf with a0=sym(.rodata), a1=[a0+600], a2=[a0+604], a3=?.
  The `jal` at 0x7680 calls qprintf with a0=sym(.rodata), a1=[a0+608], a2=[a0+612], a3=?.
  The `jal` at 0x7690 calls qprintf with a0=sym(.rodata), a1=[a0+616], a2=[a0+620], a3=?.
  The `jal` at 0x76a0 calls qprintf with a0=sym(.rodata), a1=[a0+624], a2=[a0+628], a3=?.
  The `jal` at 0x76b0 calls qprintf with a0=sym(.rodata), a1=[a0+632], a2=[a0+636], a3=?.
  The `jal` at 0x76c0 calls qprintf with a0=sym(.rodata), a1=[a0+640], a2=[a0+644], a3=?.
  The `jal` at 0x76cc calls qprintf with a0=sym(.rodata), a1=[a0+648], a2=?, a3=?.
  The `jal` at 0x76dc calls qprintf with a0=sym(.rodata), a1=[a0+652], a2=[a0+656], a3=?.
  The `jal` at 0x76ec calls qprintf with a0=sym(.rodata), a1=[a0+660], a2=[a0+664], a3=?.
  The `jal` at 0x76fc calls qprintf with a0=sym(.rodata), a1=[a0+668], a2=[a0+672], a3=?.
  The `jal` at 0x770c calls qprintf with a0=sym(.rodata), a1=[a0+676], a2=[a0+680], a3=?.
  The `jal` at 0x771c calls qprintf with a0=sym(.rodata), a1=[a0+684], a2=[a0+688], a3=?.
  The `jal` at 0x772c calls qprintf with a0=sym(.rodata), a1=[a0+692], a2=[a0+696], a3=?.
  The `jal` at 0x7740 calls qprintf with a0=sym(.rodata), a1=[a0+700], a2=[a0+704], a3=[a0+708].
  The `jal` at 0x7748 calls qprintf with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jal` at 0x7758 calls qprintf with a0=sym(.rodata), a1=[a0+29260], a2=[a0+29256], a3=?.
  The `jal` at 0x7768 calls qprintf with a0=sym(.rodata), a1=[a0+29264], a2=[a0+29272], a3=?.
  The `jal` at 0x7778 calls qprintf with a0=sym(.rodata), a1=[a0+29268], a2=[a0+29276], a3=?.
  The `jal` at 0x7788 calls qprintf with a0=sym(.rodata), a1=[a0+29252], a2=[a0+29248], a3=?.
  The `jal` at 0x77a0 calls qprintf with a0=sym(.rodata), a1=[a0+29304], a2=[a0+29308], a3=[a0+29312], a4=[a0+29316].
  The `jal` at 0x77b8 calls qprintf with a0=sym(.rodata), a1=[a0+29320], a2=[a0+29324], a3=[a0+29328], a4=[a0+29332].
  The `jal` at 0x77d0 calls qprintf with a0=sym(.rodata), a1=[a0+29344], a2=[a0+29348], a3=[a0+29336], a4=[a0+29340].
  The `jal` at 0x77ec calls qprintf with a0=sym(.rodata), a1=[a0+29300], a2=[a0+29284], a3=[a0+29288], a4=[a0+29292], a5=[a0+29296].
  The `jal` at 0x7804 calls qprintf with a0=sym(.rodata), a1=[a0+29388], a2=[a0+29392], a3=[a0+29396], a4=[a0+29400].
  The `jal` at 0x7818 calls qprintf with a0=sym(.rodata), a1=[a0+29424], a2=[a0+29416]:8, a3=[a0+29408]:8.
  The `jal` at 0x7828 calls qprintf with a0=sym(.rodata), a1=[a0+29443]:1, a2=[a0+29449]:1, a3=?.
  The `jal` at 0x7834 calls qprintf with a0=sym(.rodata), a1=a0+29000, a2=?, a3=?.
  The `jal` at 0x7840 calls qprintf with a0=sym(.rodata), a1=a0+29144, a2=?, a3=?.
  The return at 0x7854 has v0 = ret(qprintf).

- `kdsp_idbg_rad_dump_cg` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x785c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x785c-0x78d4 (120 bytes).
  It occupies 120 bytes.
  The `ld` at 0x7884 loads 8 bytes from a0 (arg0 at entry) +0x200.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x1f0, including `ld` at 0x7888, `ld` at 0x7894.
  The `lw` at 0x78ac loads 4 bytes from a0 (arg0 at entry) +0x220.
  The `lw` at 0x78b0 loads 4 bytes from a0 (arg0 at entry) +0x20c.
  The `lw` at 0x78c0 loads 4 bytes from a0 (arg0 at entry) +0x208.
  The `jal` at 0x7870 calls qprintf with a0=sym(.rodata), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x7878 calls kdsp_idbg_dump_clockgen with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x788c calls qprintf with a0=sym(.rodata), a1=[a0+496]:8, a2=[a0+512]:8, a3=?.
  The `jal` at 0x78bc calls qprintf with a0=sym(.rodata), a1=?, a2=[a0+520], a3=[a0+524], a4=[a0+544].
  The return at 0x78cc has v0 = ret(qprintf).

- `kdsp_idbg_rad_dump_device` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x78d4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x78d4-0x7944 (112 bytes).
  It occupies 112 bytes.
  The `lw` at 0x78f8 loads 4 bytes from a0 (arg0 at entry) +0x2c4.
  The `lw` at 0x7900 loads 4 bytes from a0 (arg0 at entry) +0x2c0.
  The `ld` at 0x790c loads 8 bytes from a0 (arg0 at entry) +0x300.
  The `ld` at 0x7910 loads 8 bytes from a0 (arg0 at entry) +0x2f8.
  The `lw` at 0x791c loads 4 bytes from a0 (arg0 at entry) +0x314.
  The `lw` at 0x7920 loads 4 bytes from a0 (arg0 at entry) +0x310.
  The `ld` at 0x7924 loads 8 bytes from a0 (arg0 at entry) +0x308.
  The `jal` at 0x78e4 calls kdsp_idbg_dump_device with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x78f0 calls qprintf with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jal` at 0x7904 calls qprintf with a0=sym(.rodata), a1=[a0+704], a2=[a0+708], a3=[a0+708].
  The `jal` at 0x7914 calls qprintf with a0=sym(.rodata), a1=[a0+760]:8, a2=[a0+768]:8, a3=?.
  The `jal` at 0x7928 calls qprintf with a0=sym(.rodata), a1=[a0+776]:8, a2=[a0+784], a3=[a0+788].
  The return at 0x793c has v0 = ret(qprintf).

- `kdsp_idbg_rad_addfuncs` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x7944 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x7944-0x79d0 (140 bytes).
  It occupies 140 bytes.
  The `jal` at 0x7978 calls idbg_addfunc with a0=sym(.rodata), a1=sym(kdsp_idbg_rad_dump_subsys), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x7994 calls idbg_addfunc with a0=sym(.rodata), a1=sym(kdsp_idbg_rad_dump_device), a2=?, a3=?.
  The `jal` at 0x79b0 calls idbg_addfunc with a0=sym(.rodata), a1=sym(kdsp_idbg_rad_dump_cg), a2=?, a3=?.
  The `bne` branch at 0x7958 targets 0x7970, is taken when v0(=[sym(.sdata)+52]) < 0x1 (signed), and falls through when v0(=[sym(.sdata)+52]) >= 0x1 (signed).
  The `beq` branch at 0x7980 targets 0x7990, is taken when v0(=ret(idbg_addfunc)) == 0, and falls through when v0(=ret(idbg_addfunc)) != 0.
  The `beq` branch at 0x7988 targets 0x7968 and is always taken.
  The `beq` branch at 0x799c targets 0x79ac, is taken when v0(=ret(idbg_addfunc)) == 0, and falls through when v0(=ret(idbg_addfunc)) != 0.
  The `beq` branch at 0x79a4 targets 0x7968 and is always taken.
  The `beq` branch at 0x79b8 targets 0x79c8, is taken when v0(=ret(idbg_addfunc)) == 0, and falls through when v0(=ret(idbg_addfunc)) != 0.
  The `beq` branch at 0x79c0 targets 0x7968 and is always taken.
  The `beq` branch at 0x79c8 targets 0x7964 and is always taken.
  The return at 0x7968 has v0 = one of 0x0, ret(idbg_addfunc).

- `kdsp_idbg_rad_delfuncs` in `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o` at 0x79d0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/rad_dd.o`.
  Range: 0x79d0-0x7a10 (64 bytes).
  It occupies 64 bytes.
  The `jal` at 0x79f0 calls idbg_delfunc with a0=sym(kdsp_idbg_rad_dump_subsys), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x79f8 calls idbg_delfunc with a0=sym(kdsp_idbg_rad_dump_cg), a1=?, a2=?, a3=?.
  The `jal` at 0x7a00 calls idbg_delfunc with a0=sym(kdsp_idbg_rad_dump_device), a1=?, a2=?, a3=?.
  The `blez` branch at 0x79e0 targets 0x79f0, is taken when at(=[sym(.sdata)+52]-1) <= 0 (signed), and falls through when at(=[sym(.sdata)+52]-1) > 0 (signed).
  The `beq` branch at 0x7a08 targets 0x79e8 and is always taken.
  The return at 0x79e8 has v0 = one of ?, ret(idbg_delfunc).
