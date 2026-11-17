# Readings: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`

One entry per routine, filed here from the reading batches by binary.

- `rad_ksync_notify` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x0-0x8 (8 bytes).
  It occupies 8 bytes.
  The return at 0x0 has v0 = ?.

- `rad_create_subsys` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x8-0x1f8 (496 bytes).
  It occupies 496 bytes.
  The `sw` at 0x9c stores 4 bytes to ret(kmem_zalloc) +0x731c.
  The `sd` at 0xb0 stores 8 bytes to ret(kmem_zalloc) +0x220.
  The `sd` at 0xc4 stores 8 bytes to ret(kmem_zalloc) +0x228.
  The `sh` at 0xcc stores 2 bytes to ret(kmem_zalloc) +0x218.
  The `sh` at 0xe4 stores 2 bytes to ret(kmem_zalloc) +0x21a.
  The `sw` at 0xf0 stores 4 bytes to ret(kmem_zalloc) +0x7320.
  2 such `lh` accesses load 2 bytes from ret(kmem_zalloc) +0x21a, including `lh` at 0x110, `lh` at 0x1a8.
  The `jal` at 0x28 calls pciio_config_get with a0=a2 at entry (arg2), a1=0x8, a2=0x4, a3=a3 at entry (arg3).
  The `jal` at 0x3c calls kmem_zalloc with a0=0x7328, a1=0x0, a2=?, a3=?.
  The `jal` at 0x5c calls sprintf with a0=sp-144, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x6c calls sprintf with a0=sp-112, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x94 calls kdsp_init_resource with a0=ret(kmem_zalloc), a1=0x2000001e, a2=sp-144, a3=sp-112, a4=0x0, a5=sym(.data), a6=0x7328.
  The `jal` at 0xe8 calls iobrick_real_l1type_get_nasid with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xfc calls pciio_error_register with a0=a2 at entry (arg2), a1=sym(rad_error_handler), a2=ret(kmem_zalloc), a3=?.
  The `jal` at 0x134 calls pcibr_rrb_alloc with a0=a2 at entry (arg2), a1=sp-80, a2=sp-76, a3=?, a4=one of 0x2, 0x3, a6=0x3, a7=0xd.
  The `jal` at 0x150 calls hwgraph_char_device_add with a0=a2 at entry (arg2), a1=sym(.rodata), a2=sym(.rodata), a3=sp-72.
  The `jal` at 0x17c calls device_info_set with a0=?, a1=ret(kmem_zalloc), a2=?, a3=?.
  The `jal` at 0x1a0 calls device_inventory_add with a0=?, a1=0xa, a2=0x5, a3=-0x1, a4=0x0.
  The `jal` at 0x1c0 calls kdsp_add_subsys with a0=ret(kmem_zalloc), a1=one of 0x0, 0x64, a2=?, a3=?.
  The `jal` at 0x1e8 calls cmn_err with a0=0x1, a1=sym(.rodata), a2=a2 at entry (arg2), a3=?.
  The `bne` branch at 0x44 targets 0x54, is taken when v0(=ret(kmem_zalloc)) != 0, and falls through when v0(=ret(kmem_zalloc)) == 0.
  The `beq` branch at 0x4c targets 0x164 and is always taken.
  The `bltz` branch at 0x13c targets 0x1dc, is taken when v0(=ret(pcibr_rrb_alloc)) < 0 (signed), and falls through when v0(=ret(pcibr_rrb_alloc)) >= 0 (signed).
  The `beq` branch at 0x158 targets 0x178, is taken when v0(=ret(hwgraph_char_device_add)) == 0, and falls through when v0(=ret(hwgraph_char_device_add)) != 0.
  The `beq` branch at 0x1d4 targets 0x164 and is always taken.
  The `beq` branch at 0x1f0 targets 0x144 and is always taken.
  The return at 0x170 has v0 = one of 0x0, 0x1.

- `rad_open` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x1f8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x1f8-0x200 (8 bytes).
  It occupies 8 bytes.
  The return at 0x1f8 has v0 = 0x0.

- `rad_ioctl` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x200 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x200-0x898 (1688 bytes).
  It occupies 1688 bytes.
  The `sw` at 0x278 stores 4 bytes to a5 (arg5 at entry) +0x0.
  5 such `lh` accesses load 2 bytes from ret(hwgraph_fastinfo_get) +0x21a, including `lh` at 0x2b0, `lh` at 0x370, `lh` at 0x45c.
  The `lbu` at 0x2d4 loads 1 byte from ?.
  The `sw` at 0x2dc stores 4 bytes to ?.
  2 such `lw` accesses load 4 bytes from ret(hwgraph_fastinfo_get) +0x7274, including `lw` at 0x310, `lw` at 0x390.
  6 such `sw` accesses store 4 bytes to ret(hwgraph_fastinfo_get) +0x7318, including `sw` at 0x37c, `sw` at 0x5a0, `sw` at 0x700.
  The `sw` at 0x3b0 stores 4 bytes to ret(hwgraph_fastinfo_get) +0x7274.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0x3e8, `ld` at 0x720.
  The `ll` at 0x3fc loads 4 bytes from sym(fastick_callback_required_flags) +0x0.
  The `sc` at 0x404 stores 4 bytes to sym(fastick_callback_required_flags) +0x0.
  The `lw` at 0x42c loads 4 bytes from ret(hwgraph_fastinfo_get) +0x2cc.
  The `lw` at 0x43c loads 4 bytes from ret(hwgraph_fastinfo_get) +0x2d0.
  The `sw` at 0x488 stores 4 bytes to ret(hwgraph_fastinfo_get) +0x2d0.
  The `sw` at 0x48c stores 4 bytes to ret(hwgraph_fastinfo_get) +0x2cc.
  The `sb` at 0x490 stores 1 byte to ret(hwgraph_fastinfo_get) +0x7303.
  The `lw` at 0x5b8 loads 4 bytes from ret(hwgraph_fastinfo_get) +0x731c.
  The `ld` at 0x5dc loads 8 bytes from ret(hwgraph_fastinfo_get) +0x228.
  The `ld` at 0x640 loads 8 bytes from ret(hwgraph_fastinfo_get) +0x220.
  The `lw` at 0x730 loads 4 bytes from ret(hwgraph_fastinfo_get) +0x7318.
  The `sb` at 0x814 stores 1 byte to ret(strchr) +0x0.
  The `jal` at 0x228 calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x2e8 calls copyout with a0=sp-128, a1=a2 at entry (arg2), a2=0x14, a3=?, a5=[ret(hwgraph_fastinfo_get)+538]:2.
  The `jal` at 0x318 calls copyout with a0=sp-104, a1=a2 at entry (arg2), a2=0x4, a3=?.
  The `jal` at 0x34c calls copyin with a0=a2 at entry (arg2), a1=sp-136, a2=0x4, a3=?.
  The `jal` at 0x3ac calls rad_vl_write_MUX_SEL with a0=ret(hwgraph_fastinfo_get), a1=?, a2=?, a3=-0x201, a4=[ret(hwgraph_fastinfo_get)+538]:2.
  The `jal` at 0x3d8 calls strncmp with a0=?, a1=sym(.rodata), a2=0x3, a3=?.
  The `jal` at 0x41c calls update_ust with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x424 calls get_ust_nano with a0=sp-560, a1=?, a2=?, a3=?.
  The `jal` at 0x444 calls copyout with a0=sp-560, a1=a2 at entry (arg2), a2=0x18, a3=?, a6=[ret(hwgraph_fastinfo_get)+720], a7=[ret(hwgraph_fastinfo_get)+716].
  The `jal` at 0x49c calls curproc_abi with a0=0x6b730002, a1=?, a2=0x6d680000, a3=?.
  The `jal` at 0x4bc calls copyin_xlate with a0=a2 at entry (arg2), a1=sp-536, a2=0x44, a3=sym(irix5_to_kstat_t), a4=ret(curproc_abi), a5=0x4, a6=0x1.
  The `jal` at 0x4d4 calls device_controller_num_get with a0=a0 at entry (arg0), a1=?, a2=0x6d687767, a3=?.
  The `jal` at 0x4f4 calls sprintf with a0=ret(hwgraph_fastinfo_get)+300, a1=sym(.rodata), a2=ret(device_controller_num_get), a3=?.
  The `jal` at 0x508 calls sprintf with a0=ret(hwgraph_fastinfo_get)+332, a1=sym(.rodata), a2=ret(device_controller_num_get), a3=?.
  The `jal` at 0x540 calls kdsp_set_default_subsys_pri with a0=ret(hwgraph_fastinfo_get), a1=ret(device_controller_num_get)+100, a2=one of 0x7, 0xd, a3=?, a4=[ret(hwgraph_fastinfo_get)+538]:2.
  The `jal` at 0x564 calls kdsp_set_default_subsys_pri with a0=ret(hwgraph_fastinfo_get), a1=ret(device_controller_num_get), a2=0x7, a3=?, a4=[ret(hwgraph_fastinfo_get)+538]:2.
  The `jal` at 0x578 calls sprintf with a0=sp-464, a1=sym(.rodata), a2=ret(device_controller_num_get), a3=?.
  The `jal` at 0x5b0 calls hwgraph_path_add with a0=[sym(hwgraph_root)], a1=sym(.rodata), a2=sp-432, a3=one of 0x4, 0x7.
  The `jal` at 0x5c4 calls hwgraph_edge_add with a0=?, a1=[ret(hwgraph_fastinfo_get)+29468], a2=ret(hwgraph_fastinfo_get)+300, a3=?.
  The `jal` at 0x5e0 calls sprintf with a0=sp-424, a1=sym(.rodata), a2=[ret(hwgraph_fastinfo_get)+552]:8, a3=?.
  The `jal` at 0x5e8 calls strlen with a0=sp-424, a1=?, a2=?, a3=?.
  The `jal` at 0x5f4 calls kern_malloc with a0=ret(strlen)+1, a1=?, a2=?, a3=?.
  The `jal` at 0x608 calls strcpy with a0=ret(kern_malloc), a1=sp-424, a2=?, a3=?.
  The `jal` at 0x61c calls hwgraph_info_add_LBL with a0=[ret(hwgraph_fastinfo_get)+29468], a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x630 calls hwgraph_info_export_LBL with a0=[ret(hwgraph_fastinfo_get)+29468], a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x644 calls sprintf with a0=sp-424, a1=sym(.rodata), a2=[ret(hwgraph_fastinfo_get)+544]:8, a3=?.
  The `jal` at 0x64c calls strlen with a0=sp-424, a1=?, a2=?, a3=?.
  The `jal` at 0x658 calls kern_malloc with a0=ret(strlen)+1, a1=?, a2=?, a3=?.
  The `jal` at 0x668 calls strcpy with a0=ret(kern_malloc), a1=sp-424, a2=?, a3=?.
  The `jal` at 0x678 calls hwgraph_info_add_LBL with a0=[ret(hwgraph_fastinfo_get)+29468], a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x688 calls hwgraph_info_export_LBL with a0=[ret(hwgraph_fastinfo_get)+29468], a1=sym(.rodata), a2=(ret(strlen)+1 << 0x0), a3=?.
  The `jal` at 0x690 calls strlen with a0=ret(hwgraph_fastinfo_get)+300, a1=?, a2=?, a3=?.
  The `jal` at 0x69c calls kern_malloc with a0=ret(strlen)+1, a1=?, a2=?, a3=?.
  The `jal` at 0x6ac calls strcpy with a0=ret(kern_malloc), a1=ret(hwgraph_fastinfo_get)+300, a2=?, a3=?.
  The `jal` at 0x6bc calls hwgraph_info_add_LBL with a0=[ret(hwgraph_fastinfo_get)+29468], a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x6cc calls hwgraph_info_export_LBL with a0=[ret(hwgraph_fastinfo_get)+29468], a1=sym(.rodata), a2=(ret(strlen)+1 << 0x0), a3=?.
  The `jal` at 0x6dc calls hwgraph_edge_get with a0=[ret(hwgraph_fastinfo_get)+29468], a1=sym(.rodata), a2=sp-400, a3=?.
  The `jal` at 0x714 calls rad_stop_status_dma with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x728 calls sprintf with a0=sp-536, a1=ret(hwgraph_fastinfo_get)+300, a2=?, a3=?.
  The `jal` at 0x734 calls curproc_abi with a0=?, a1=?, a2=?, a3=?, a4=[ret(hwgraph_fastinfo_get)+29464].
  The `jal` at 0x754 calls xlate_copyout with a0=sp-536, a1=a2 at entry (arg2), a2=0x44, a3=sym(kstat_t_to_irix5), a4=ret(curproc_abi), a5=0x4, a6=0x1.
  The `jal` at 0x76c calls rad_vl_write_MUX_SEL with a0=ret(hwgraph_fastinfo_get), a1=(a2 << 0x0), a2=?, a3=?.
  The `jal` at 0x784 calls hwgraph_vertex_name_get with a0=?, a1=sp-392, a2=0x100, a3=?.
  The `jal` at 0x79c calls strstr with a0=sp-392, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x7bc calls ksync_attach with a0=?, a1=sp-464, a2=?, a3=sym(rad_ksync_notify).
  The `jal` at 0x804 calls strchr with a0=ret(strstr)+7, a1=0x2f, a2=?, a3=?, a4=-0x1.
  The `jal` at 0x818 calls parse_module_id with a0=ret(strstr)+7, a1=?, a2=?, a3=?.
  The `jal` at 0x840 calls cmn_err with a0=0x4, a1=sym(.rodata), a2=a0 at entry (arg0), a3=?.
  The `jal` at 0x860 calls cmn_err with a0=0x4, a1=sym(.rodata), a2=a0 at entry (arg0), a3=ret(device_controller_num_get).
  The `jal` at 0x870 calls cmn_err with a0=0x1, a1=sym(.rodata), a2=[sym(showconfig)], a3=?.
  The `jal` at 0x888 calls cmn_err with a0=0x1, a1=sym(.rodata), a2=?, a3=?.
  The `beq` branch at 0x230 targets 0x834, is taken when v0(=ret(hwgraph_fastinfo_get)) == 0, and falls through when v0(=ret(hwgraph_fastinfo_get)) != 0.
  The `bne` branch at 0x23c targets 0x298, is taken when s1(=a1) < 0x270c (signed), and falls through when s1(=a1) >= 0x270c (signed).
  The `bne` branch at 0x244 targets 0x41c, is taken when v0(?) != 0, and falls through when v0(?) == 0.
  The `bne` branch at 0x254 targets 0x328, is taken when s1(=a1) < a0(=0x6b730002) (signed), and falls through when s1(=a1) >= a0(=0x6b730002) (signed).
  The `beq` branch at 0x25c targets 0x49c, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x268 targets 0x4d4, is taken when s1(=a1) == a2(=0x6d687767), and falls through when s1(=a1) != a2(=0x6d687767).
  The `bne` branch at 0x29c targets 0x2f8, is taken when s1(=a1) < 0x270a (signed), and falls through when s1(=a1) >= 0x270a (signed).
  The `beq` branch at 0x2a8 targets 0x480, is taken when s1(=a1) >= 0x270b (signed), and falls through when s1(=a1) < 0x270b (signed).
  The `bne` branch at 0x2d8 targets 0x2c0, is taken when v0(?) < 0x4 (signed), and falls through when v0(?) >= 0x4 (signed).
  The `beq` branch at 0x2f0 targets 0x270 and is always taken.
  The `bne` branch at 0x2f8 targets 0x3bc, is taken when t0(?) != 0, and falls through when t0(?) == 0.
  The `beq` branch at 0x300 targets 0x270, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x320 targets 0x270 and is always taken.
  The `bne` branch at 0x330 targets 0x454, is taken when s1(=a1) < a0(=0x6b730001) (signed), and falls through when s1(=a1) >= a0(=0x6b730001) (signed).
  The `bne` branch at 0x33c targets 0x270, is taken when a0(=0x6b730001) < s1(=a1) (signed), and falls through when a0(=0x6b730001) >= s1(=a1) (signed).
  The `bne` branch at 0x358 targets 0x270, is taken when v0(=ret(copyin)) != 0, and falls through when v0(=ret(copyin)) == 0.
  The `beq` branch at 0x36c targets 0x7d4, is taken when t8(?) == a3(=0x1), and falls through when t8(?) != a3(=0x1).
  The `beq` branch at 0x374 targets 0x7f0, is taken when a4(=[ret(hwgraph_fastinfo_get)+538]:2) == v0(=0xc), and falls through when a4(=[ret(hwgraph_fastinfo_get)+538]:2) != v0(=0xc).
  The `bne` branch at 0x384 targets 0x270, is taken when a4(=[ret(hwgraph_fastinfo_get)+538]:2) != ra(=0xd), and falls through when a4(=[ret(hwgraph_fastinfo_get)+538]:2) == ra(=0xd).
  The `beq` branch at 0x3b4 targets 0x274 and is always taken.
  The `bne` branch at 0x3bc targets 0x26c, is taken when s1(=a1) != a2(=0x2708), and falls through when s1(=a1) == a2(=0x2708).
  The `beq` branch at 0x3c4 targets 0x3f4, is taken when a3(=[sym(kdsp_sstab)]:8) == 0, and falls through when a3(=[sym(kdsp_sstab)]:8) != 0.
  The `beq` branch at 0x3e0 targets 0x714, is taken when v0(=ret(strncmp)) == 0, and falls through when v0(=ret(strncmp)) != 0.
  The `bne` branch at 0x3ec targets 0x3d0, is taken when s0(?) != 0, and falls through when s0(?) == 0.
  The `beql` branch at 0x408 targets 0x3fc, is taken when (a2(=[sym(fastick_callback_required_flags)]) & a4(=-0x3)) == 0, and falls through when (a2(=[sym(fastick_callback_required_flags)]) & a4(=-0x3)) != 0; its branch-likely delay slot `nop` at 0x40c runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x414 targets 0x270 and is always taken.
  The `beq` branch at 0x44c targets 0x270 and is always taken.
  The `bne` branch at 0x454 targets 0x270, is taken when s1(=a1) != t0(=0x270d), and falls through when s1(=a1) == t0(=0x270d).
  The `beq` branch at 0x464 targets 0x76c, is taken when v0(=[ret(hwgraph_fastinfo_get)+538]:2) == t1(=0x7), and falls through when v0(=[ret(hwgraph_fastinfo_get)+538]:2) != t1(=0x7).
  The `beq` branch at 0x470 targets 0x76c, is taken when v0(=[ret(hwgraph_fastinfo_get)+538]:2) == t2(=0xd), and falls through when v0(=[ret(hwgraph_fastinfo_get)+538]:2) != t2(=0xd).
  The `beq` branch at 0x478 targets 0x270 and is always taken.
  The `bne` branch at 0x480 targets 0x270, is taken when s1(=a1) != t3(=0x270b), and falls through when s1(=a1) == t3(=0x270b).
  The `beq` branch at 0x494 targets 0x270 and is always taken.
  The `beq` branch at 0x4c4 targets 0x724, is taken when v0(=ret(copyin_xlate)) == 0, and falls through when v0(=ret(copyin_xlate)) != 0.
  The `beq` branch at 0x4cc targets 0x270 and is always taken.
  The `bltz` branch at 0x4dc targets 0x850, is taken when v0(=ret(device_controller_num_get)) < 0 (signed), and falls through when v0(=ret(device_controller_num_get)) >= 0 (signed).
  The `beq` branch at 0x518 targets 0x540, is taken when a4(=[ret(hwgraph_fastinfo_get)+538]:2) == a2(=0xd), and falls through when a4(=[ret(hwgraph_fastinfo_get)+538]:2) != a2(=0xd).
  The `bne` branch at 0x524 targets 0x550, is taken when a4(=[ret(hwgraph_fastinfo_get)+538]:2) != a2(=0x7), and falls through when a4(=[ret(hwgraph_fastinfo_get)+538]:2) == a2(=0x7).
  The `beq` branch at 0x52c targets 0x554, is taken when v0(=[sym(.sbss)+8]) == 0, and falls through when v0(=[sym(.sbss)+8]) != 0.
  The `beq` branch at 0x534 targets 0x554, is taken when s1(=ret(device_controller_num_get)) == v0(=[sym(.sbss)+8]), and falls through when s1(=ret(device_controller_num_get)) != v0(=[sym(.sbss)+8]).
  The `beq` branch at 0x548 targets 0x570 and is always taken.
  The `beq` branch at 0x588 targets 0x700, is taken when a4(=[ret(hwgraph_fastinfo_get)+538]:2) == a2(=0xc), and falls through when a4(=[ret(hwgraph_fastinfo_get)+538]:2) != a2(=0xc).
  The `beq` branch at 0x594 targets 0x6fc, is taken when a4(=[ret(hwgraph_fastinfo_get)+538]:2) == a3(=0x7), and falls through when a4(=[ret(hwgraph_fastinfo_get)+538]:2) != a3(=0x7).
  The `beq` branch at 0x5d0 targets 0x70c, is taken when v0(=ret(hwgraph_edge_add)) == a2(=0x1), and falls through when v0(=ret(hwgraph_edge_add)) != a2(=0x1).
  The `beq` branch at 0x6e4 targets 0x77c, is taken when v0(=ret(hwgraph_edge_get)) == 0, and falls through when v0(=ret(hwgraph_edge_get)) != 0.
  The `bne` branch at 0x6ec targets 0x870, is taken when a2(=[sym(showconfig)]) != 0, and falls through when a2(=[sym(showconfig)]) == 0.
  The `beq` branch at 0x6f4 targets 0x270 and is always taken.
  The `beq` branch at 0x704 targets 0x5a4 and is always taken.
  The `beq` branch at 0x70c targets 0x27c and is always taken.
  The `beq` branch at 0x71c targets 0x3ec and is always taken.
  The `beq` branch at 0x760 targets 0x270 and is always taken.
  The `beq` branch at 0x774 targets 0x270 and is always taken.
  The `bne` branch at 0x78c targets 0x880, is taken when v0(=ret(hwgraph_vertex_name_get)) != 0, and falls through when v0(=ret(hwgraph_vertex_name_get)) == 0.
  The `bne` branch at 0x7a4 targets 0x7fc, is taken when v0(=ret(strstr)) != 0, and falls through when v0(=ret(strstr)) == 0.
  The `bne` branch at 0x7c4 targets 0x274, is taken when s0(?) != 0, and falls through when s0(?) == 0.
  The `beq` branch at 0x7cc targets 0x6f4 and is always taken.
  The `beq` branch at 0x7d4 targets 0x82c, is taken when a4(=[ret(hwgraph_fastinfo_get)+538]:2) == v0(=0xc), and falls through when a4(=[ret(hwgraph_fastinfo_get)+538]:2) != v0(=0xc).
  The `beq` branch at 0x7e0 targets 0x82c, is taken when a4(=[ret(hwgraph_fastinfo_get)+538]:2) == a2(=0x7), and falls through when a4(=[ret(hwgraph_fastinfo_get)+538]:2) != a2(=0x7).
  The `beq` branch at 0x7e8 targets 0x380 and is always taken.
  The `beq` branch at 0x7f4 targets 0x380 and is always taken.
  The `beq` branch at 0x80c targets 0x818, is taken when v0(=ret(strchr)) == 0, and falls through when v0(=ret(strchr)) != 0.
  The `beq` branch at 0x820 targets 0x7ac and is always taken.
  The `beq` branch at 0x82c targets 0x380 and is always taken.
  The `beq` branch at 0x848 targets 0x27c and is always taken.
  The `beq` branch at 0x868 targets 0x270 and is always taken.
  The `beq` branch at 0x878 targets 0x6f4 and is always taken.
  The `beq` branch at 0x890 targets 0x7c4 and is always taken.
  The return at 0x290 has v0 = one of ?, 0x0, 0x5.
  The instructions from 0x768 to 0x768 are not reached by any path from the entry, and their branches are not listed.
  The instructions from 0x828 to 0x828 are not reached by any path from the entry, and their branches are not listed.

- `rad_close` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x898 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x898-0x8ec (84 bytes).
  It occupies 84 bytes.
  The `sb` at 0x8b4 stores 1 byte to ret(hwgraph_fastinfo_get) +0x7303.
  The `sw` at 0x8b8 stores 4 bytes to ret(hwgraph_fastinfo_get) +0x2d0.
  The `sw` at 0x8bc stores 4 bytes to ret(hwgraph_fastinfo_get) +0x2cc.
  The `jal` at 0x8a0 calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x8dc calls cmn_err with a0=0x4, a1=sym(.rodata), a2=a0 at entry (arg0), a3=ret(hwgraph_fastinfo_get), a4=0x1.
  The `beq` branch at 0x8ac targets 0x8d0, is taken when v0(=ret(hwgraph_fastinfo_get)) == 0, and falls through when v0(=ret(hwgraph_fastinfo_get)) != 0.
  The `beq` branch at 0x8e4 targets 0x8c4 and is always taken.
  The return at 0x8c8 has v0 = one of 0x0, 0x5.

- `rad_start_subsys` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x8ec (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x8ec-0x10ec (2048 bytes).
  It occupies 2048 bytes.
  The `sw` at 0x900 stores 4 bytes to sym(.bss) +0x158.
  The `sw` at 0x904 stores 4 bytes to sym(.bss) +0x150.
  The `sw` at 0x910 stores 4 bytes to sym(.bss) +0x148.
  The `sw` at 0x91c stores 4 bytes to sym(.bss) +0x140.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x731c, including `lw` at 0x928, `lw` at 0x93c.
  32 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x228, including `ld` at 0x944, `ld` at 0x998, `ld` at 0x9a8.
  5 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x7240, including `sw` at 0x94c, `sw` at 0x9a0, `sw` at 0xab8.
  5 such `sw` accesses store 4 bytes to [a0+552]:8 +0x80, including `sw` at 0x958, `sw` at 0x9a4, `sw` at 0xac4.
  4 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x7240, including `lw` at 0x95c, `lw` at 0xaa8, `lw` at 0xad8.
  The `sw` at 0x9b4 stores 4 bytes to [a0+552]:8 +0x74.
  The `sw` at 0x9c4 stores 4 bytes to [a0+552]:8 +0x78.
  12 such `lh` accesses load 2 bytes from a0 (arg0 at entry) +0x21a, including `lh` at 0x9c8, `lh` at 0xa08, `lh` at 0xa40.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x7248, including `sw` at 0x9dc, `sw` at 0xf70.
  The `sw` at 0x9e4 stores 4 bytes to [a0+552]:8 +0x4c.
  The `sw` at 0x9f0 stores 4 bytes to a0 (arg0 at entry) +0x724c.
  The `sw` at 0x9f4 stores 4 bytes to [a0+552]:8 +0x58.
  The `sw` at 0xa00 stores 4 bytes to a0 (arg0 at entry) +0x7250.
  The `sw` at 0xa04 stores 4 bytes to [a0+552]:8 +0x48.
  The `sw` at 0xa24 stores 4 bytes to a0 (arg0 at entry) +0x7258.
  The `sw` at 0xa28 stores 4 bytes to [a0+552]:8 +0x54.
  The `sw` at 0xa38 stores 4 bytes to a0 (arg0 at entry) +0x7254.
  The `sw` at 0xa3c stores 4 bytes to [a0+552]:8 +0x44.
  The `sw` at 0xa58 stores 4 bytes to a0 (arg0 at entry) +0x725c.
  The `sw` at 0xa5c stores 4 bytes to [a0+552]:8 +0x50.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x7244, including `sw` at 0xa88, `sw` at 0xf28.
  2 such `sw` accesses store 4 bytes to [a0+552]:8 +0x70, including `sw` at 0xa8c, `sw` at 0xf2c.
  The `sw` at 0xa9c stores 4 bytes to [a0+552]:8 +0xb8.
  The `sw` at 0xaa4 stores 4 bytes to [a0+552]:8 +0xbc.
  The `sw` at 0xad4 stores 4 bytes to [a0+552]:8 +0xa0.
  The `sw` at 0xb64 stores 4 bytes to a0 (arg0 at entry) +0x72c4.
  The `sw` at 0xb68 stores 4 bytes to a0 (arg0 at entry) +0x72c0.
  The `sw` at 0xb70 stores 4 bytes to a0 (arg0 at entry) +0x72b4.
  The `sw` at 0xb74 stores 4 bytes to a0 (arg0 at entry) +0x72b0.
  The `sw` at 0xb78 stores 4 bytes to a0 (arg0 at entry) +0x72bc.
  The `sw` at 0xb80 stores 4 bytes to a0 (arg0 at entry) +0x72b8.
  The `sw` at 0xb90 stores 4 bytes to a0 (arg0 at entry) +0x7260.
  The `sw` at 0xb94 stores 4 bytes to [a0+552]:8 +0x7c.
  The `sd` at 0xbe4 stores 8 bytes to a0 (arg0 at entry) +0xdb0.
  The `sd` at 0xbec stores 8 bytes to a0 (arg0 at entry) +0xdc0.
  The `sw` at 0xbf4 stores 4 bytes to a0 (arg0 at entry) +0xfb0.
  The `sd` at 0xc00 stores 8 bytes to a0 (arg0 at entry) +0xdb8.
  The `sd` at 0xc20 stores 8 bytes to a0 (arg0 at entry) +0xf68.
  The `sd` at 0xc3c stores 8 bytes to a0 (arg0 at entry) +0x10d8.
  The `sd` at 0xc44 stores 8 bytes to a0 (arg0 at entry) +0x10d0.
  The `sd` at 0xc4c stores 8 bytes to a0 (arg0 at entry) +0x10c8.
  The `sw` at 0xc54 stores 4 bytes to a0 (arg0 at entry) +0x12c8.
  The `sd` at 0xc5c stores 8 bytes to a0 (arg0 at entry) +0x1280.
  The `sd` at 0xca4 stores 8 bytes to a0 (arg0 at entry) +0x13e8.
  The `sd` at 0xcac stores 8 bytes to a0 (arg0 at entry) +0x13e0.
  The `sw` at 0xcb4 stores 4 bytes to a0 (arg0 at entry) +0x15e0.
  The `sd` at 0xcd4 stores 8 bytes to a0 (arg0 at entry) +0x13f0.
  The `sd` at 0xd04 stores 8 bytes to a0 (arg0 at entry) +0x1708.
  The `sd` at 0xd08 stores 8 bytes to a0 (arg0 at entry) +0x1700.
  The `sd` at 0xd10 stores 8 bytes to a0 (arg0 at entry) +0x16f8.
  The `sw` at 0xd18 stores 4 bytes to a0 (arg0 at entry) +0x18f8.
  The `sd` at 0xd38 stores 8 bytes to a0 (arg0 at entry) +0x18b0.
  The `sw` at 0xd58 stores 4 bytes to a0 (arg0 at entry) +0x1c10.
  The `sd` at 0xd64 stores 8 bytes to a0 (arg0 at entry) +0x1a10.
  The `sd` at 0xd70 stores 8 bytes to a0 (arg0 at entry) +0x1a20.
  The `sd` at 0xd90 stores 8 bytes to a0 (arg0 at entry) +0x1a18.
  The `sd` at 0xdb0 stores 8 bytes to a0 (arg0 at entry) +0x1d38.
  The `sw` at 0xdb4 stores 4 bytes to a0 (arg0 at entry) +0x1f28.
  The `sd` at 0xdc4 stores 8 bytes to a0 (arg0 at entry) +0x1ee0.
  The `sd` at 0xdc8 stores 8 bytes to a0 (arg0 at entry) +0x1d30.
  The `sd` at 0xdd4 stores 8 bytes to a0 (arg0 at entry) +0x1d28.
  The `ld` at 0xe84 loads 8 bytes from a0 (arg0 at entry) +0x58.
  The `ld` at 0xeb8 loads 8 bytes from ?.
  2 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x1f8, including `sd` at 0xeec, `sd` at 0x10b0.
  The `sd` at 0xef4 stores 8 bytes to a0 (arg0 at entry) +0x200.
  The `lw` at 0xf18 loads 4 bytes from a0 (arg0 at entry) +0x7244.
  3 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x726c, including `sw` at 0xf7c, `sw` at 0xfdc, `sw` at 0x102c.
  3 such `sw` accesses store 4 bytes to [a0+552]:8 +0x8c, including `sw` at 0xf80, `sw` at 0xfe0, `sw` at 0x1030.
  3 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x7270, including `sw` at 0xf9c, `sw` at 0xfd0, `sw` at 0x1020.
  3 such `sw` accesses store 4 bytes to [a0+552]:8 +0x90, including `sw` at 0xfa4, `sw` at 0xfd4, `sw` at 0x1024.
  3 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x7268, including `sw` at 0xfe8, `sw` at 0x1038, `sw` at 0x1094.
  3 such `sw` accesses store 4 bytes to [a0+552]:8 +0x88, including `sw` at 0xfec, `sw` at 0x103c, `sw` at 0x109c.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x7264, including `sw` at 0xff4, `sw` at 0x1044.
  2 such `sw` accesses store 4 bytes to [a0+552]:8 +0x84, including `sw` at 0xff8, `sw` at 0x104c.
  3 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x7274, including `sw` at 0x1004, `sw` at 0x1058, `sw` at 0x10dc.
  2 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x7302, including `sb` at 0x1010, `sb` at 0x10e8.
  The `lw` at 0x10cc loads 4 bytes from a0 (arg0 at entry) +0x7274.
  The `jal` at 0x924 calls pciio_config_set with a0=[a0+29468], a1=0x4, a2=0x4, a3=0x6.
  The `jal` at 0x938 calls pciio_config_set with a0=[a0+29468], a1=0xc, a2=0x4, a3=-0x1.
  The `jal` at 0x954 calls us_delay with a0=0x3e8, a1=-0x1, a2=[a0+552]:8, a3=?.
  The `jal` at 0xac0 calls us_delay with a0=0x3e8, a1=?, a2=?, a3=[a0+552]:8, a4=-0xf01, a5=0xffffffff9fffffff, a6=[a0+552]:8, a7=[a0+552]:8.
  The `jal` at 0xb20 calls us_delay with a0=0x3e8, a1=?, a2=?, a3=?.
  The `jal` at 0xb98 calls rad_init_subsys with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xbd4 calls rad_create_device with a0=a0 at entry (arg0), a1=a0+3416, a2=0x0, a3=0x400, a4=0x0, a5=sym(.rodata), a6=sym(.rodata), a7=0x2.
  The `jal` at 0xc2c calls rad_create_device with a0=a0 at entry (arg0), a1=a0+4208, a2=0x1, a3=0x400, a4=0x1, a5=sym(.rodata), a6=sym(.rodata), a7=0x2.
  The `jal` at 0xc88 calls rad_create_device with a0=a0 at entry (arg0), a1=a0+5000, a2=0x0, a3=0x400, a4=0x2, a5=sym(.rodata), a6=sym(.rodata), a7=0x2.
  The `jal` at 0xce0 calls rad_create_device with a0=a0 at entry (arg0), a1=a0+5792, a2=0x1, a3=0x400, a4=0x3, a5=sym(.rodata), a6=sym(.rodata), a7=0x2.
  The `jal` at 0xd44 calls rad_create_device with a0=a0 at entry (arg0), a1=a0+6584, a2=0x0, a3=0x1000, a4=0x4, a5=sym(.rodata), a6=sym(.rodata), a7=0x8.
  The `jal` at 0xd9c calls rad_create_device with a0=a0 at entry (arg0), a1=a0+7376, a2=0x1, a3=0x1000, a4=0x5, a5=sym(.rodata), a6=sym(.rodata), a7=0x8.
  The `jal` at 0xdd0 calls rad_create_mclks with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xdf0 calls rad_create_clockgen with a0=a0+25688, a1=a0+3416, a2=0x0, a3=a0+1176.
  The `jal` at 0xe08 calls rad_create_clockgen with a0=a0+26240, a1=a0+4208, a2=0x1, a3=a0+1176.
  The `jal` at 0xe20 calls rad_create_clockgen with a0=a0+27896, a1=a0+5000, a2=0x4, a3=a0+2072.
  The `jal` at 0xe3c calls rad_create_clockgen with a0=a0+26792, a1=a0+5792, a2=0x2, a3=a0+1176.
  The `jal` at 0xe54 calls rad_create_clockgen with a0=a0+28448, a1=a0+6584, a2=0x5, a3=a0+1624.
  The `jal` at 0xe6c calls rad_create_clockgen with a0=a0+27344, a1=a0+7376, a2=0x3, a3=a0+1176.
  The `jal` at 0xe7c calls rad_create_ifs with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xe94 calls rad_start_device with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xec4 calls rad_create_subcodes with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xed0 calls kdsp_map_resource with a0=a0 at entry (arg0), a1=0x0, a2=?, a3=?.
  The `jal` at 0xef8 calls us_delay with a0=0xf4240, a1=(a0 + one of 0x1070, 0x16a0), a2=?, a3=?.
  The `jal` at 0x100c calls rad_vl_write_MUX_SEL with a0=a0 at entry (arg0), a1=0x0, a2=?, a3=[a0+538]:2, a4=0xfac688, a5=[a0+552]:8, a6=[a0+552]:8, a7=[a0+552]:8.
  The `jal` at 0x1054 calls rad_vl_write_MUX_SEL with a0=a0 at entry (arg0), a1=0x0, a2=?, a3=[a0+538]:2, a4=0xfac688, a5=[a0+552]:8, a6=[a0+552]:8, a7=[a0+552]:8.
  The `jal` at 0x10d8 calls rad_vl_write_MUX_SEL with a0=a0 at entry (arg0), a1=([a0+29300] | 0x2000), a2=?, a3=?.
  The `beq` branch at 0x9d0 targets 0xf68, is taken when a3(=[a0+538]:2) == s2(=0xc), and falls through when a3(=[a0+538]:2) != s2(=0xc).
  The `beq` branch at 0xa68 targets 0xfc8, is taken when v0(=[a0+538]:2) == a1(=0x7), and falls through when v0(=[a0+538]:2) != a1(=0x7).
  The `beq` branch at 0xa70 targets 0x101c, is taken when v0(=[a0+538]:2) == s1(=0xd), and falls through when v0(=[a0+538]:2) != s1(=0xd).
  The `beq` branch at 0xa78 targets 0xf94, is taken when v0(=[a0+538]:2) == s2(=0xc), and falls through when v0(=[a0+538]:2) != s2(=0xc).
  The `beq` branch at 0xb5c targets 0xf74, is taken when v0(=[a0+538]:2) == s2(=0xc), and falls through when v0(=[a0+538]:2) != s2(=0xc).
  The `beq` branch at 0xb7c targets 0xb98, is taken when v0(=[a0+538]:2) == s1(=0xd), and falls through when v0(=[a0+538]:2) != s1(=0xd).
  The `beq` branch at 0xba0 targets 0xfb8, is taken when v0(=ret(rad_init_subsys)) == 0, and falls through when v0(=ret(rad_init_subsys)) != 0.
  The `beq` branch at 0xbac targets 0xc60, is taken when v0(=[a0+538]:2) == s1(=0xd), and falls through when v0(=[a0+538]:2) != s1(=0xd).
  The `beq` branch at 0xbdc targets 0xf44, is taken when v0(=ret(rad_create_device)) == 0, and falls through when v0(=ret(rad_create_device)) != 0.
  The `beq` branch at 0xc34 targets 0xfc0, is taken when v0(=ret(rad_create_device)) == 0, and falls through when v0(=ret(rad_create_device)) != 0.
  The `beq` branch at 0xc90 targets 0xf60, is taken when v0(=ret(rad_create_device)) == 0, and falls through when v0(=ret(rad_create_device)) != 0.
  The `beq` branch at 0xce8 targets 0xf8c, is taken when v0(=ret(rad_create_device)) == 0, and falls through when v0(=ret(rad_create_device)) != 0.
  The `beq` branch at 0xd4c targets 0xfa8, is taken when v0(=ret(rad_create_device)) == 0, and falls through when v0(=ret(rad_create_device)) != 0.
  The `beq` branch at 0xda4 targets 0xfb0, is taken when v0(=ret(rad_create_device)) == 0, and falls through when v0(=ret(rad_create_device)) != 0.
  The `beq` branch at 0xddc targets 0xe14, is taken when t9(=[a0+538]:2) == s1(=0xd), and falls through when t9(=[a0+538]:2) != s1(=0xd).
  The `beq` branch at 0xdf8 targets 0x1064, is taken when v0(=ret(rad_create_clockgen)) == 0, and falls through when v0(=ret(rad_create_clockgen)) != 0.
  The `beq` branch at 0xe10 targets 0x1074, is taken when v0(=ret(rad_create_clockgen)) == 0, and falls through when v0(=ret(rad_create_clockgen)) != 0.
  The `beq` branch at 0xe28 targets 0x106c, is taken when v0(=ret(rad_create_clockgen)) == 0, and falls through when v0(=ret(rad_create_clockgen)) != 0.
  The `beq` branch at 0xe44 targets 0x107c, is taken when v0(=ret(rad_create_clockgen)) == 0, and falls through when v0(=ret(rad_create_clockgen)) != 0.
  The `beq` branch at 0xe5c targets 0x10a0, is taken when v0(=ret(rad_create_clockgen)) == 0, and falls through when v0(=ret(rad_create_clockgen)) != 0.
  The `beq` branch at 0xe74 targets 0x10bc, is taken when v0(=ret(rad_create_clockgen)) == 0, and falls through when v0(=ret(rad_create_clockgen)) != 0.
  The `beq` branch at 0xe88 targets 0xec4, is taken when a1(=[a0+88]:8) == 0, and falls through when a1(=[a0+88]:8) != 0.
  The `beq` branch at 0xe9c targets 0x10c4, is taken when v0(=ret(rad_start_device)) == 0, and falls through when v0(=ret(rad_start_device)) != 0.
  The `beq` branch at 0xeb0 targets 0xec4, is taken when a0(?) >= 0x18 (signed), and falls through when a0(?) < 0x18 (signed).
  The `bne` branch at 0xebc targets 0xe94, is taken when a1(?) != 0, and falls through when a1(?) == 0.
  The `beq` branch at 0xee0 targets 0x10a8, is taken when v0(=[a0+538]:2) == s1(=0xd), and falls through when v0(=[a0+538]:2) != s1(=0xd).
  The `beq` branch at 0xee8 targets 0x10b4, is taken when v0(=[a0+538]:2) == s1(=0xd), and falls through when v0(=[a0+538]:2) != s1(=0xd).
  The `beq` branch at 0xf08 targets 0x10cc, is taken when v0(=[a0+538]:2) == a1(=0x7), and falls through when v0(=[a0+538]:2) != a1(=0x7).
  The `beq` branch at 0xf10 targets 0x1084, is taken when v0(=[a0+538]:2) == s1(=0xd), and falls through when v0(=[a0+538]:2) != s1(=0xd).
  The `beq` branch at 0xf34 targets 0x108c, is taken when v0(=[a0+538]:2) == s2(=0xc), and falls through when v0(=[a0+538]:2) != s2(=0xc).
  The `beq` branch at 0xf3c targets 0xf48 and is always taken.
  The `beq` branch at 0xf60 targets 0xf48 and is always taken.
  The `beq` branch at 0xf6c targets 0x9e0 and is always taken.
  The `beq` branch at 0xf84 targets 0xb60 and is always taken.
  The `beq` branch at 0xf8c targets 0xf48 and is always taken.
  The `beq` branch at 0xfa0 targets 0xa80 and is always taken.
  The `beq` branch at 0xfa8 targets 0xf48 and is always taken.
  The `beq` branch at 0xfb0 targets 0xf48 and is always taken.
  The `beq` branch at 0xfb8 targets 0xf48 and is always taken.
  The `beq` branch at 0xfc0 targets 0xf48 and is always taken.
  The `beq` branch at 0x1014 targets 0xa84 and is always taken.
  The `beq` branch at 0x105c targets 0xa84 and is always taken.
  The `beq` branch at 0x1064 targets 0xf48 and is always taken.
  The `beq` branch at 0x106c targets 0xf48 and is always taken.
  The `beq` branch at 0x1074 targets 0xf48 and is always taken.
  The `beq` branch at 0x107c targets 0xf48 and is always taken.
  The `bne` branch at 0x1084 targets 0xf3c, is taken when v0(=[a0+538]:2) != s2(=0xc), and falls through when v0(=[a0+538]:2) == s2(=0xc).
  The `beq` branch at 0x1098 targets 0xf3c and is always taken.
  The `beq` branch at 0x10a0 targets 0xf48 and is always taken.
  The `bne` branch at 0x10ac targets 0xef0, is taken when v0(=[a0+538]:2) != s1(=0xd), and falls through when v0(=[a0+538]:2) == s1(=0xd).
  The `beq` branch at 0x10b4 targets 0xef0 and is always taken.
  The `beq` branch at 0x10bc targets 0xf48 and is always taken.
  The `beq` branch at 0x10c4 targets 0xf48 and is always taken.
  The `beq` branch at 0x10e4 targets 0xf10 and is always taken.
  The return at 0xf58 has v0 = one of 0x0, 0x1.

- `rad_enable_ust` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x10ec (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x10ec-0x1120 (52 bytes).
  It occupies 52 bytes.
  The `lh` at 0x10ec loads 2 bytes from a0 (arg0 at entry) +0x21a.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x228, including `ld` at 0x1104, `ld` at 0x1110.
  2 such `sw` accesses store 4 bytes to [a0+552]:8 +0x40, including `sw` at 0x110c, `sw` at 0x1114.
  The `beq` branch at 0x10f4 targets 0x1118, is taken when a2(=[a0+538]:2) == at(=0x7), and falls through when a2(=[a0+538]:2) != at(=0x7).
  The `beq` branch at 0x10fc targets 0x1118, is taken when a2(=[a0+538]:2) == a3(=0xd), and falls through when a2(=[a0+538]:2) != a3(=0xd).
  The return at 0x1118 has v0 = one of ?, 0xa.

- `rad_disable_ust` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x1120 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x1120-0x1148 (40 bytes).
  It occupies 40 bytes.
  The `lh` at 0x1120 loads 2 bytes from a0 (arg0 at entry) +0x21a.
  The `ld` at 0x1138 loads 8 bytes from a0 (arg0 at entry) +0x228.
  The `sw` at 0x113c stores 4 bytes to [a0+552]:8 +0x40.
  The `beq` branch at 0x1128 targets 0x1140, is taken when a2(=[a0+538]:2) == at(=0x7), and falls through when a2(=[a0+538]:2) != at(=0x7).
  The `beq` branch at 0x1130 targets 0x1140, is taken when a2(=[a0+538]:2) == a3(=0xd), and falls through when a2(=[a0+538]:2) != a3(=0xd).
  The return at 0x1140 has v0 = one of ?, 0x2.

- `rad_reset_ust` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x1148 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x1148-0x1254 (268 bytes).
  It occupies 268 bytes.
  The `lh` at 0x1148 loads 2 bytes from a0 (arg0 at entry) +0x21a.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x228, including `ld` at 0x118c, `ld` at 0x119c.
  2 such `sw` accesses store 4 bytes to [a0+552]:8 +0x40, including `sw` at 0x1194, `sw` at 0x11a8.
  The `sd` at 0x11d8 stores 8 bytes to a0 (arg0 at entry) +0x72a8.
  The `lw` at 0x11e8 loads 4 bytes from a0 (arg0 at entry) +0x7320.
  The `ld` at 0x1228 loads 8 bytes from abs 0x9200000001604200.
  The `jal` at 0x1190 calls splprof with a0=[a0+552]:8, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=one of 0xd, 0x38, a7=0x3c0.
  The `jal` at 0x11a4 calls update_ust with a0=?, a1=?, a2=[a0+552]:8, a3=?.
  The `jal` at 0x11ac calls get_ust_nano with a0=sp-48, a1=?, a2=?, a3=?.
  The `jal` at 0x11b4 calls splx with a0=?, a1=?, a2=?, a3=?.
  The `beq` branch at 0x1164 targets 0x1174, is taken when v0(=[a0+538]:2) == at(=0x7), and falls through when v0(=[a0+538]:2) != at(=0x7).
  The `bne` branch at 0x116c targets 0x11dc, is taken when v0(=[a0+538]:2) != a3(=0xd), and falls through when v0(=[a0+538]:2) == a3(=0xd).
  The `beq` branch at 0x1174 targets 0x11e8, is taken when a4(=[sym(.sbss)+4]) == 0, and falls through when a4(=[sym(.sbss)+4]) != 0.
  The `beq` branch at 0x1200 targets 0x117c, is taken when v0(=[a0+29472]) == t0(=0x39), and falls through when v0(=[a0+29472]) != t0(=0x39).
  The `beq` branch at 0x1208 targets 0x1180, is taken when v0(=[a0+29472]) == a0(=0x37), and falls through when v0(=[a0+29472]) != a0(=0x37).
  The `beq` branch at 0x1210 targets 0x1180, is taken when v0(=[a0+29472]) == a3(=0x38), and falls through when v0(=[a0+29472]) != a3(=0x38).
  The `beq` branch at 0x1218 targets 0x1180, is taken when v0(=[a0+29472]) == a4(=0x51), and falls through when v0(=[a0+29472]) != a4(=0x51).
  The `beq` branch at 0x1220 targets 0x1180, is taken when v0(=[a0+29472]) == a5(=0x45), and falls through when v0(=[a0+29472]) != a5(=0x45).
  The `beq` branch at 0x124c targets 0x118c and is always taken.
  The return at 0x11e0 has v0 = one of [a0+538]:2, ret(splx).

- `rad_set_ust_offset` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x1254 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x1254-0x12bc (104 bytes).
  It occupies 104 bytes.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x228, including `ld` at 0x1260, `ld` at 0x1278.
  2 such `lw` accesses load 4 bytes from [a0+552]:8 +0x30, including `lw` at 0x1274, `lw` at 0x127c.
  The `lw` at 0x12a8 loads 4 bytes from a0 (arg0 at entry) +0x731c.
  The `jal` at 0x1270 calls us_delay with a0=0xa, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x12ac calls cmn_err with a0=0x1, a1=sym(.rodata), a2=[a0+29468], a3=?.
  The `bne` branch at 0x1288 targets 0x12a0, is taken when ra(?) < 0x3 (unsigned), and falls through when ra(?) >= 0x3 (unsigned).
  The `beq` branch at 0x12b4 targets 0x1290 and is always taken.
  The return at 0x1298 has v0 = one of ret(us_delay), ret(cmn_err).

- `rad_create_device` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x12bc (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x12bc-0x17b8 (1276 bytes).
  It occupies 1276 bytes.
  The `sd` at 0x1378 stores 8 bytes to a1 (arg1 at entry) +0x2a0.
  The `sw` at 0x137c stores 4 bytes to a1 (arg1 at entry) +0x29c.
  The `sw` at 0x1384 stores 4 bytes to a1 (arg1 at entry) +0x120.
  The `sd` at 0x13a4 stores 8 bytes to a1 (arg1 at entry) +0x200.
  The `sd` at 0x13a8 stores 8 bytes to a1 (arg1 at entry) +0x218.
  The `sd` at 0x13ac stores 8 bytes to a1 (arg1 at entry) +0x290.
  The `sd` at 0x13b0 stores 8 bytes to a1 (arg1 at entry) +0x288.
  The `sd` at 0x13b4 stores 8 bytes to a1 (arg1 at entry) +0x278.
  The `sd` at 0x13b8 stores 8 bytes to a1 (arg1 at entry) +0x18.
  The `sd` at 0x13c0 stores 8 bytes to a1 (arg1 at entry) +0x8.
  The `sd` at 0x13cc stores 8 bytes to a1 (arg1 at entry) +0x20.
  2 such `sd` accesses store 8 bytes to a1 (arg1 at entry) +0x280, including `sd` at 0x13d0, `sd` at 0x1504.
  The `sw` at 0x13dc stores 4 bytes to a1 (arg1 at entry) +0x2c0.
  The `sw` at 0x13ec stores 4 bytes to a1 (arg1 at entry) +0x298.
  The `sw` at 0x13f8 stores 4 bytes to a1 (arg1 at entry) +0x2f0.
  The `lh` at 0x1414 loads 2 bytes from table(sym(.data)) +0x0.
  The `lw` at 0x1418 loads 4 bytes from table(sym(.data)) +0x10.
  3 such `sd` accesses store 8 bytes to a1 (arg1 at entry) +0x300, including `sd` at 0x1430, `sd` at 0x1514, `sd` at 0x1524.
  3 such `sd` accesses store 8 bytes to a1 (arg1 at entry) +0x2f8, including `sd` at 0x1438, `sd` at 0x1508, `sd` at 0x1518.
  The `ld` at 0x1458 loads 8 bytes from (sym(.rodata) + (a4+2 << 0x3)) +0x0.
  The `jal` at 0x1308 calls kmem_alloc with a0=(a3 << 0x2), a1=0x8800, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1344 calls kdsp_init_resource with a0=a1 at entry (arg1), a1=one of 0x2000001b, 0x2000001c, a2=a5 at entry (arg5), a3=a6 at entry (arg6), a4=a0 at entry (arg0), a5=0x0, a6=0x318.
  The `jal` at 0x1368 calls kdsp_create_device with a0=a1 at entry (arg1), a1=a3 at entry (arg3), a2=(a2 | 0x40), a3=0x0, a4=ret(kmem_alloc), a5=a7 at entry (arg7).
  Calls (unknown callee) via register with a0=-0x2, a1=?, a2=sym(rad_commit_device_params), a3=sym(rad_update_dev), a4=sym(rad_start_dma), a5=sym(rad_stop_dma), a6=sym(rad_get_hw_mscust), a7=sym(rad_pre_connect) (`jr` at 0x145c).
  The `jal` at 0x17a8 calls rad_destroy_devices with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `beq` branch at 0x1370 targets 0x17a8, is taken when v0(=ret(kdsp_create_device)) == 0, and falls through when v0(=ret(kdsp_create_device)) != 0.
  The `beq` branch at 0x13c8 targets 0x1500, is taken when s3(=a2) == 0, and falls through when s3(=a2) != 0.
  The `beq` branch at 0x13f4 targets 0x1518, is taken when s2(=a4) == a0(=-0x2), and falls through when s2(=a4) != a0(=-0x2).
  The `beq` branch at 0x1400 targets 0x1508, is taken when s2(=a4) == t8(=-0x1), and falls through when s2(=a4) != t8(=-0x1).
  The `beq` branch at 0x1450 targets 0x1464, is taken when v1(=a4+2) >= 0xa (unsigned), and falls through when v1(=a4+2) < 0xa (unsigned).
  The `beq` branch at 0x1464 targets 0x14d4 and is always taken.
  The `beq` branch at 0x1500 targets 0x13d4 and is always taken.
  The `beq` branch at 0x1510 targets 0x143c and is always taken.
  The `beq` branch at 0x1520 targets 0x143c and is always taken.
  The `beq` branch at 0x17b0 targets 0x14d4 and is always taken.
  The return at 0x14f8 has v0 = 0x0.
  The instructions from 0x146c to 0x14d0 are not reached by any path from the entry, and their branches are not listed.
  The instructions from 0x1528 to 0x17a4 are not reached by any path from the entry, and their branches are not listed.
  The indirect jump at 0x145c uses a jump table whose successors are unresolved.

- `rad_start_device` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x17b8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x17b8-0x1848 (144 bytes).
  It occupies 144 bytes.
  The `lw` at 0x17b8 loads 4 bytes from a1 (arg1 at entry) +0x2c0.
  4 such `ld` accesses load 8 bytes from a1 (arg1 at entry) +0x2e8, including `ld` at 0x17e8, `ld` at 0x17f8, `ld` at 0x1818.
  4 such `lw` accesses load 4 bytes from [a1+744]:8 +0x0, including `lw` at 0x17ec, `lw` at 0x1808, `lw` at 0x181c.
  3 such `sw` accesses store 4 bytes to [a1+744]:8 +0x0, including `sw` at 0x17f4, `sw` at 0x182c, `sw` at 0x1844.
  The `ld` at 0x17fc loads 8 bytes from a0 (arg0 at entry) +0x228.
  The `lwu` at 0x1800 loads 4 bytes from a1 (arg1 at entry) +0x2e4.
  The `sw` at 0x1814 stores 4 bytes to ([a1+740] + [a0+552]:8) +0x0.
  The `beq` branch at 0x17c8 targets 0x1830, is taken when a3(=[a1+704]) == at(=-0x1), and falls through when a3(=[a1+704]) != at(=-0x1).
  The `beq` branch at 0x17d0 targets 0x1830, is taken when a3(=[a1+704]) == a6(=-0x2), and falls through when a3(=[a1+704]) != a6(=-0x2).
  The `beq` branch at 0x17d8 targets 0x1818, is taken when a3(=[a1+704]) == a4(=0x6), and falls through when a3(=[a1+704]) != a4(=0x6).
  The `beq` branch at 0x17e0 targets 0x1818, is taken when a3(=[a1+704]) == a5(=0x7), and falls through when a3(=[a1+704]) != a5(=0x7).
  The `beq` branch at 0x1828 targets 0x17f8 and is always taken.
  The `beq` branch at 0x1840 targets 0x17f8 and is always taken.
  The return at 0x1810 has v0 = 0x1.

- `rad_create_ifs` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x1848 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x1848-0x1d64 (1308 bytes).
  It occupies 1308 bytes.
  The `sw` at 0x1888 stores 4 bytes to sym(.data) +0x7438.
  The `sw` at 0x1890 stores 4 bytes to sym(.data) +0x7430.
  2 such `lh` accesses load 2 bytes from a0 (arg0 at entry) +0x21a, including `lh` at 0x1894, `lh` at 0x1ccc.
  The `sd` at 0x18e8 stores 8 bytes to a0 (arg0 at entry) +0x58b0.
  The `sw` at 0x18f4 stores 4 bytes to a0 (arg0 at entry) +0x5838.
  The `sd` at 0x1904 stores 8 bytes to a0 (arg0 at entry) +0x5728.
  The `sd` at 0x1908 stores 8 bytes to a0 (arg0 at entry) +0x5720.
  The `sw` at 0x190c stores 4 bytes to a0 (arg0 at entry) +0x58b8.
  The `sd` at 0x1924 stores 8 bytes to a0 (arg0 at entry) +0x5738.
  The `sd` at 0x1930 stores 8 bytes to sym(.bss) +0x40.
  The `sd` at 0x1938 stores 8 bytes to sym(.bss) +0x10.
  The `sd` at 0x1944 stores 8 bytes to sym(.bss) +0x18.
  The `sd` at 0x1950 stores 8 bytes to sym(.bss) +0x28.
  The `sd` at 0x195c stores 8 bytes to sym(.bss) +0x0.
  The `sd` at 0x1968 stores 8 bytes to sym(.bss) +0x8.
  The `sd` at 0x1974 stores 8 bytes to sym(.bss) +0x30.
  The `sw` at 0x1980 stores 4 bytes to sym(.bss) +0x20.
  The `sw` at 0x198c stores 4 bytes to sym(.bss) +0x38.
  The `sd` at 0x1998 stores 8 bytes to sym(.bss) +0x48.
  The `sd` at 0x19ac stores 8 bytes to a0 (arg0 at entry) +0x5a58.
  2 such `lw` accesses load 4 bytes from sym(.data) +0x7430, including `lw` at 0x19bc, `lw` at 0x1b08.
  The `sw` at 0x19c4 stores 4 bytes to a0 (arg0 at entry) +0x59e0.
  The `sd` at 0x19cc stores 8 bytes to a0 (arg0 at entry) +0x58e0.
  The `sd` at 0x19d0 stores 8 bytes to a0 (arg0 at entry) +0x58d0.
  The `sd` at 0x19d4 stores 8 bytes to a0 (arg0 at entry) +0x58c8.
  The `sw` at 0x19d8 stores 4 bytes to a0 (arg0 at entry) +0x5a60.
  The `sd` at 0x19dc stores 8 bytes to sym(.bss) +0x98.
  The `sd` at 0x19e0 stores 8 bytes to sym(.bss) +0x58.
  The `sd` at 0x19e4 stores 8 bytes to sym(.bss) +0x50.
  The `sw` at 0x19ec stores 4 bytes to sym(.bss) +0x70.
  The `sd` at 0x19f0 stores 8 bytes to sym(.bss) +0x68.
  The `sd` at 0x19f4 stores 8 bytes to sym(.bss) +0x60.
  The `sd` at 0x19f8 stores 8 bytes to sym(.bss) +0x90.
  The `sd` at 0x1a40 stores 8 bytes to a0 (arg0 at entry) +0x5c00.
  The `sw` at 0x1a4c stores 4 bytes to a0 (arg0 at entry) +0x5b88.
  The `sd` at 0x1a50 stores 8 bytes to a0 (arg0 at entry) +0x5a78.
  The `sd` at 0x1a54 stores 8 bytes to a0 (arg0 at entry) +0x5a70.
  The `sd` at 0x1a64 stores 8 bytes to a0 (arg0 at entry) +0x5a88.
  The `sw` at 0x1a6c stores 4 bytes to a0 (arg0 at entry) +0x5c08.
  The `sd` at 0x1a78 stores 8 bytes to sym(.bss) +0x138.
  The `sd` at 0x1a80 stores 8 bytes to sym(.bss) +0xf8.
  The `sd` at 0x1a84 stores 8 bytes to sym(.bss) +0xf0.
  The `sd` at 0x1a8c stores 8 bytes to sym(.bss) +0x118.
  The `sd` at 0x1a94 stores 8 bytes to sym(.bss) +0x120.
  The `sw` at 0x1a9c stores 4 bytes to sym(.bss) +0x128.
  The `sw` at 0x1aa4 stores 4 bytes to sym(.bss) +0x110.
  The `sd` at 0x1aa8 stores 8 bytes to sym(.bss) +0x108.
  The `sd` at 0x1aac stores 8 bytes to sym(.bss) +0x100.
  The `sd` at 0x1ab4 stores 8 bytes to sym(.bss) +0x130.
  The `sd` at 0x1b04 stores 8 bytes to a0 (arg0 at entry) +0x5da8.
  The `sw` at 0x1b10 stores 4 bytes to a0 (arg0 at entry) +0x5d30.
  The `sd` at 0x1b18 stores 8 bytes to a0 (arg0 at entry) +0x5c30.
  The `sd` at 0x1b1c stores 8 bytes to a0 (arg0 at entry) +0x5c20.
  The `sd` at 0x1b20 stores 8 bytes to a0 (arg0 at entry) +0x5c18.
  The `sw` at 0x1b28 stores 4 bytes to a0 (arg0 at entry) +0x5db0.
  The `sd` at 0x1b34 stores 8 bytes to sym(.bss) +0xe8.
  The `sd` at 0x1b3c stores 8 bytes to sym(.bss) +0xa8.
  The `sd` at 0x1b40 stores 8 bytes to sym(.bss) +0xa0.
  The `sd` at 0x1b44 stores 8 bytes to sym(.bss) +0xd0.
  The `sw` at 0x1b4c stores 4 bytes to sym(.bss) +0xc0.
  The `sd` at 0x1b50 stores 8 bytes to sym(.bss) +0xb8.
  The `sd` at 0x1b54 stores 8 bytes to sym(.bss) +0xb0.
  The `sd` at 0x1b5c stores 8 bytes to sym(.bss) +0xe0.
  The `sd` at 0x1b94 stores 8 bytes to a0 (arg0 at entry) +0x5f50.
  The `sw` at 0x1b9c stores 4 bytes to a0 (arg0 at entry) +0x5ed8.
  The `sd` at 0x1ba4 stores 8 bytes to a0 (arg0 at entry) +0x5dc0.
  The `sw` at 0x1bb0 stores 4 bytes to a0 (arg0 at entry) +0x5f58.
  The `sd` at 0x1bbc stores 8 bytes to a0 (arg0 at entry) +0x5dd8.
  The `sd` at 0x1bec stores 8 bytes to a0 (arg0 at entry) +0x60f8.
  The `sw` at 0x1bf4 stores 4 bytes to a0 (arg0 at entry) +0x6080.
  The `sd` at 0x1bfc stores 8 bytes to a0 (arg0 at entry) +0x5f68.
  The `sw` at 0x1c08 stores 4 bytes to a0 (arg0 at entry) +0x6100.
  The `sd` at 0x1c14 stores 8 bytes to a0 (arg0 at entry) +0x5f80.
  The `sd` at 0x1c48 stores 8 bytes to a0 (arg0 at entry) +0x62a0.
  The `sw` at 0x1c50 stores 4 bytes to a0 (arg0 at entry) +0x6228.
  The `sd` at 0x1c58 stores 8 bytes to a0 (arg0 at entry) +0x6110.
  The `sw` at 0x1c64 stores 4 bytes to a0 (arg0 at entry) +0x62a8.
  The `sd` at 0x1c70 stores 8 bytes to a0 (arg0 at entry) +0x6128.
  The `sd` at 0x1ca0 stores 8 bytes to a0 (arg0 at entry) +0x6448.
  The `sw` at 0x1ca8 stores 4 bytes to a0 (arg0 at entry) +0x63d0.
  The `sd` at 0x1cb0 stores 8 bytes to a0 (arg0 at entry) +0x62b8.
  The `sw` at 0x1cbc stores 4 bytes to a0 (arg0 at entry) +0x6450.
  The `sd` at 0x1cc8 stores 8 bytes to a0 (arg0 at entry) +0x62d0.
  The `jal` at 0x18d0 calls kdsp_init_resource with a0=a0+22296, a1=0x2000000e, a2=sym(.rodata), a3=sym(.rodata), a4=a0 at entry (arg0), a5=0x0, a6=0x1a8.
  The `jal` at 0x1994 calls kdsp_init_resource with a0=a0+22720, a1=0x2000000e, a2=sym(.rodata), a3=sym(.rodata), a4=a0 at entry (arg0), a5=0x0, a6=0x1a8, a7=sym(.bss).
  The `jal` at 0x19fc calls kdsp_add_subresource with a0=a0+4208, a1=a0+22720, a2=0x1, a3=0xb, a4=sym(.data)+32768, a5=sym(rad_get_analog_out_if_params), a6=sym(rad_set_analog_out_if_params), a7=[sym(.data)+29744].
  The `jal` at 0x1a24 calls kdsp_init_resource with a0=a0+23144, a1=0x2000000d, a2=sym(.rodata), a3=0x0, a4=a0 at entry (arg0), a5=0x0, a6=0x1a8.
  The `jal` at 0x1ab0 calls kdsp_select_interface with a0=a0+3416, a1=a0+23144, a2=sym(.bss), a3=0x1, a4=0xff, a5=0x50d0d0d1, a6=0x32aee8263, a7=0x1480000000.
  The `jal` at 0x1adc calls kdsp_init_resource with a0=a0+23568, a1=0x20000011, a2=sym(.rodata), a3=sym(.rodata), a4=a0 at entry (arg0), a5=0x0, a6=0x1a8.
  The `jal` at 0x1b58 calls kdsp_add_subresource with a0=a0+4208, a1=a0+23568, a2=sym(.bss), a3=0x3, a4=0x217354b8e7, a5=0x1480000000, a6=0xb00000000, a7=0xb.
  The `jal` at 0x1b88 calls kdsp_init_resource with a0=a0+23992, a1=0x2000000f, a2=sym(.rodata), a3=sym(.rodata), a4=a0 at entry (arg0), a5=0x0, a6=0x1a8.
  The `jal` at 0x1bb8 calls kdsp_select_interface with a0=a0+5000, a1=a0+23992, a2=?, a3=?.
  The `jal` at 0x1be0 calls kdsp_init_resource with a0=a0+24416, a1=0x2000000f, a2=sym(.rodata), a3=sym(.rodata), a4=a0 at entry (arg0), a5=0x0, a6=0x1a8.
  The `jal` at 0x1c10 calls kdsp_select_interface with a0=a0+5792, a1=a0+24416, a2=?, a3=sym(.data)+32768, a4=[sym(.sdata)+40], a5=sym(rad_set_digital_if_params).
  The `jal` at 0x1c3c calls kdsp_init_resource with a0=a0+24840, a1=0x20000025, a2=sym(.rodata), a3=sym(.rodata), a4=a0 at entry (arg0), a5=0x0, a6=0x1a8.
  The `jal` at 0x1c6c calls kdsp_select_interface with a0=a0+6584, a1=a0+24840, a2=sym(.data)+32768, a3=[sym(.sdata)+40], a4=sym(rad_set_digital_if_params).
  The `jal` at 0x1c94 calls kdsp_init_resource with a0=a0+25264, a1=0x20000025, a2=sym(.rodata), a3=sym(.rodata), a4=a0 at entry (arg0), a5=0x0, a6=0x1a8.
  The `jal` at 0x1cc4 calls kdsp_select_interface with a0=a0+7376, a1=a0+25264, a2=sym(.data)+32768, a3=[sym(.sdata)+40], a4=sym(rad_set_digital_if_params).
  The `jal` at 0x1ce0 calls kdsp_map_resource with a0=a0+23144, a1=0x0, a2=?, a3=?, a5=[a0+538]:2, a6=0xd.
  The `jal` at 0x1cec calls kdsp_map_resource with a0=a0+22296, a1=0x0, a2=?, a3=?.
  The `jal` at 0x1cf8 calls kdsp_map_resource with a0=a0+22720, a1=0x0, a2=?, a3=?.
  The `jal` at 0x1d04 calls kdsp_map_resource with a0=a0+23568, a1=0x0, a2=?, a3=?.
  The `jal` at 0x1d20 calls kdsp_map_resource with a0=a0+23992, a1=0x0, a2=?, a3=?.
  The `jal` at 0x1d2c calls kdsp_map_resource with a0=a0+24416, a1=0x0, a2=?, a3=?.
  The `jal` at 0x1d3c calls kdsp_map_resource with a0=a0+24840, a1=0x0, a2=?, a3=?.
  The `jal` at 0x1d48 calls kdsp_map_resource with a0=a0+25264, a1=0x0, a2=?, a3=?.
  The `beq` branch at 0x18a8 targets 0x1b60, is taken when at(=[a0+538]:2) == v0(=0xd), and falls through when at(=[a0+538]:2) != v0(=0xd).
  The `beq` branch at 0x1cd4 targets 0x1d0c, is taken when a5(=[a0+538]:2) == a6(=0xd), and falls through when a5(=[a0+538]:2) != a6(=0xd).
  The return at 0x1d5c has v0 = 0x1.

- `rad_create_subcode_device` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x1d64 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x1d64-0x1eb4 (336 bytes).
  It occupies 336 bytes.
  The `sw` at 0x1ddc stores 4 bytes to a1 (arg1 at entry) +0x258.
  The `sd` at 0x1de4 stores 8 bytes to a1 (arg1 at entry) +0x60.
  The `sd` at 0x1df0 stores 8 bytes to a1 (arg1 at entry) +0x58.
  The `lw` at 0x1e9c loads 4 bytes from a3 (arg3 at entry) +0x5c.
  The `sw` at 0x1eb0 stores 4 bytes to a3 (arg3 at entry) +0x5c.
  The `jal` at 0x1dcc calls rad_create_device with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a4 at entry (arg4), a3=?, a4=a5 at entry (arg5), a5=a7 at entry (arg7).
  The `jal` at 0x1dfc calls kdsp_select_clockgen with a0=a1 at entry (arg1), a1=?, a2=?, a3=?.
  The `jal` at 0x1e08 calls kdsp_select_interface with a0=a1 at entry (arg1), a1=?, a2=?, a3=?.
  The `jal` at 0x1e14 calls rad_start_device with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0x1e54 calls kdsp_create_subcode with a0=a3 at entry (arg3), a1=a2 at entry (arg2), a2=a1 at entry (arg1), a3=a6 at entry (arg6).
  The `jal` at 0x1e7c calls kdsp_set_default_subcode with a0=a3 at entry (arg3), a1=sp-144, a2=0x0, a3=?.
  The `beq` branch at 0x1da4 targets 0x1db0, is taken when a6 == 0, and falls through when a6 != 0.
  The `beq` branch at 0x1dd4 targets 0x1e24, is taken when v0(=ret(rad_create_device)) == 0, and falls through when v0(=ret(rad_create_device)) != 0.
  The `bne` branch at 0x1dec targets 0x1e48, is taken when s1(=a3) != 0, and falls through when s1(=a3) == 0.
  The `beq` branch at 0x1e60 targets 0x1e88, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x1e94 targets 0x1df4, is taken when v1(?) == 0, and falls through when v1(?) != 0.
  The `beq` branch at 0x1eac targets 0x1df4 and is always taken.
  The return at 0x1e40 has v0 = one of 0x0, 0x1.

- `rad_create_subcodes` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x1eb4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x1eb4-0x2448 (1428 bytes).
  It occupies 1428 bytes.
  2 such `lh` accesses load 2 bytes from a0 (arg0 at entry) +0x21a, including `lh` at 0x1ef0, `lh` at 0x23c8.
  The `sw` at 0x2338 stores 4 bytes to a0 (arg0 at entry) +0x723c.
  The `sw` at 0x233c stores 4 bytes to a0 (arg0 at entry) +0x7238.
  The `sb` at 0x2340 stores 1 byte to a0 (arg0 at entry) +0x7311.
  The `sb` at 0x2344 stores 1 byte to a0 (arg0 at entry) +0x7310.
  The `sb` at 0x234c stores 1 byte to a0 (arg0 at entry) +0x7312.
  2 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x7316, including `sb` at 0x2350, `sb` at 0x236c.
  2 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x7314, including `sb` at 0x2354, `sb` at 0x2368.
  The `sb` at 0x2370 stores 1 byte to a0 (arg0 at entry) +0x7315.
  The `sb` at 0x2374 stores 1 byte to a0 (arg0 at entry) +0x7317.
  The `lw` at 0x2378 loads 4 bytes from a0 (arg0 at entry) +0x7244.
  The `ld` at 0x237c loads 8 bytes from a0 (arg0 at entry) +0x228.
  The `sw` at 0x2384 stores 4 bytes to a0 (arg0 at entry) +0x7244.
  The `sw` at 0x2390 stores 4 bytes to [a0+552]:8 +0x70.
  The `jal` at 0x1f60 calls rad_create_subcode_device with a0=a0 at entry (arg0), a1=a0+8168, a2=a0+5000, a3=0x0, a4=0x400, a5=0x6, a6=0x0, a7=sym(.rodata).
  The `jal` at 0x1fbc calls rad_create_subcode_device with a0=a0 at entry (arg0), a1=a0+8960, a2=a0+6584, a3=0x0, a4=0x400, a5=0x7, a6=0x0, a7=sym(.rodata).
  The `jal` at 0x2010 calls rad_create_subcode_device with a0=a0 at entry (arg0), a1=a0+10544, a2=a0+5000, a3=a0+21256, a4=0x0, a5=0x6, a6=0x1000002f, a7=sym(.rodata).
  The `jal` at 0x2064 calls rad_create_subcode_device with a0=a0 at entry (arg0), a1=a0+9752, a2=a0+5000, a3=a0+21152, a4=0x0, a5=0x6, a6=0x10000030, a7=sym(.rodata).
  The `jal` at 0x20b8 calls rad_create_subcode_device with a0=a0 at entry (arg0), a1=a0+11336, a2=a0+5000, a3=a0+21360, a4=0x0, a5=0x6, a6=0x10000031, a7=sym(.rodata).
  The `jal` at 0x2114 calls rad_create_subcode_device with a0=a0 at entry (arg0), a1=a0+12920, a2=a0+5792, a3=a0+20944, a4=0x1, a5=-0x1, a6=0x1000002f, a7=sym(.rodata).
  The `jal` at 0x216c calls rad_create_subcode_device with a0=a0 at entry (arg0), a1=a0+12128, a2=a0+5792, a3=a0+20840, a4=0x1, a5=-0x1, a6=0x10000030, a7=sym(.rodata).
  The `jal` at 0x21c4 calls rad_create_subcode_device with a0=a0 at entry (arg0), a1=a0+13712, a2=a0+5792, a3=a0+21048, a4=0x1, a5=-0x1, a6=0x10000031, a7=sym(.rodata).
  The `jal` at 0x2208 calls sprintf with a0=sp-192, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x2218 calls sprintf with a0=sp-168, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x229c calls rad_create_subcode_device with a0=a0 at entry (arg0), a1=?, a2=?, a3=?, a4=0x0, a5=0x7, a7=sp-192.
  The `jal` at 0x22b0 calls sprintf with a0=sp-192, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x22c0 calls sprintf with a0=sp-168, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x2318 calls rad_create_subcode_device with a0=a0 at entry (arg0), a1=?, a2=?, a3=?, a4=0x1, a5=-0x2, a7=sp-192.
  The `jal` at 0x2358 calls rad_pio_writeback_subcode_tx with a0=?, a1=?, a2=?, a3=0x1.
  The `jal` at 0x2360 calls rad_pio_writeback_subcode_tx with a0=a0+17672, a1=?, a2=?, a3=?.
  The `beq` branch at 0x1ee0 targets 0x23c8, is taken when v0(=[sym(kdsp_pro_audio_subcode)]) == a1(=0x1), and falls through when v0(=[sym(kdsp_pro_audio_subcode)]) != a1(=0x1).
  The `beq` branch at 0x1ee8 targets 0x23f0, is taken when v0(=[sym(kdsp_pro_audio_subcode)]) == 0, and falls through when v0(=[sym(kdsp_pro_audio_subcode)]) != 0.
  The `beq` branch at 0x1efc targets 0x23f8, is taken when v0(=[a0+538]:2) == at(=0x7), and falls through when v0(=[a0+538]:2) != at(=0x7).
  The `beq` branch at 0x1f08 targets 0x2408, is taken when v0(=[a0+538]:2) == v1(=0xd), and falls through when v0(=[a0+538]:2) != v1(=0xd).
  The `beq` branch at 0x1f68 targets 0x2394, is taken when v0(=ret(rad_create_subcode_device)) == 0, and falls through when v0(=ret(rad_create_subcode_device)) != 0.
  The `beq` branch at 0x1fc4 targets 0x23c0, is taken when v0(=ret(rad_create_subcode_device)) == 0, and falls through when v0(=ret(rad_create_subcode_device)) != 0.
  The `beq` branch at 0x2018 targets 0x23e8, is taken when v0(=ret(rad_create_subcode_device)) == 0, and falls through when v0(=ret(rad_create_subcode_device)) != 0.
  The `beq` branch at 0x206c targets 0x2400, is taken when v0(=ret(rad_create_subcode_device)) == 0, and falls through when v0(=ret(rad_create_subcode_device)) != 0.
  The `beq` branch at 0x20c0 targets 0x2410, is taken when v0(=ret(rad_create_subcode_device)) == 0, and falls through when v0(=ret(rad_create_subcode_device)) != 0.
  The `beq` branch at 0x211c targets 0x2418, is taken when v0(=ret(rad_create_subcode_device)) == 0, and falls through when v0(=ret(rad_create_subcode_device)) != 0.
  The `beq` branch at 0x2174 targets 0x2420, is taken when v0(=ret(rad_create_subcode_device)) == 0, and falls through when v0(=ret(rad_create_subcode_device)) != 0.
  The `beq` branch at 0x21cc targets 0x2440, is taken when v0(=ret(rad_create_subcode_device)) == 0, and falls through when v0(=ret(rad_create_subcode_device)) != 0.
  The `beq` branch at 0x22a4 targets 0x2428, is taken when v0(=ret(rad_create_subcode_device)) == 0, and falls through when v0(=ret(rad_create_subcode_device)) != 0.
  The `beq` branch at 0x2320 targets 0x2438, is taken when v0(=ret(rad_create_subcode_device)) == 0, and falls through when v0(=ret(rad_create_subcode_device)) != 0.
  The `bne` branch at 0x2330 targets 0x2204, is taken when s1(?) < 0x4 (signed), and falls through when s1(?) >= 0x4 (signed).
  The `beq` branch at 0x238c targets 0x2398 and is always taken.
  The `beq` branch at 0x23c0 targets 0x2398 and is always taken.
  The `beq` branch at 0x23d4 targets 0x2430, is taken when a5(=[a0+538]:2) == a6(=0xd), and falls through when a5(=[a0+538]:2) != a6(=0xd).
  The `beq` branch at 0x23e0 targets 0x1f14 and is always taken.
  The `beq` branch at 0x23e8 targets 0x2398 and is always taken.
  The `beq` branch at 0x23f0 targets 0x1f14 and is always taken.
  The `beq` branch at 0x23f8 targets 0x1f18 and is always taken.
  The `beq` branch at 0x2400 targets 0x2398 and is always taken.
  The `beq` branch at 0x2408 targets 0x1f18 and is always taken.
  The `beq` branch at 0x2410 targets 0x2398 and is always taken.
  The `beq` branch at 0x2418 targets 0x2398 and is always taken.
  The `beq` branch at 0x2420 targets 0x2398 and is always taken.
  The `beq` branch at 0x2428 targets 0x2398 and is always taken.
  The `beq` branch at 0x2430 targets 0x1f18 and is always taken.
  The `beq` branch at 0x2438 targets 0x2398 and is always taken.
  The `beq` branch at 0x2440 targets 0x2398 and is always taken.
  The return at 0x23b8 has v0 = one of 0x0, 0x1.

- `rad_create_mclks` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x2448 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x2448-0x2740 (760 bytes).
  It occupies 760 bytes.
  The `sw` at 0x2494 stores 4 bytes to a0 (arg0 at entry) +0x488.
  The `sw` at 0x249c stores 4 bytes to a0 (arg0 at entry) +0x490.
  The `sw` at 0x24a0 stores 4 bytes to a0 (arg0 at entry) +0x48c.
  The `sw` at 0x24a8 stores 4 bytes to a0 (arg0 at entry) +0x3f8.
  The `sd` at 0x24c4 stores 8 bytes to a0 (arg0 at entry) +0x470.
  The `sd` at 0x24d0 stores 8 bytes to a0 (arg0 at entry) +0x2f8.
  The `sw` at 0x2500 stores 4 bytes to a0 (arg0 at entry) +0x648.
  The `sw` at 0x2504 stores 4 bytes to a0 (arg0 at entry) +0x64c.
  The `sw` at 0x2508 stores 4 bytes to a0 (arg0 at entry) +0x650.
  The `sw` at 0x250c stores 4 bytes to a0 (arg0 at entry) +0x5b8.
  The `sd` at 0x2524 stores 8 bytes to a0 (arg0 at entry) +0x630.
  The `sd` at 0x2530 stores 8 bytes to a0 (arg0 at entry) +0x4b8.
  The `sw` at 0x2564 stores 4 bytes to a0 (arg0 at entry) +0x9c8.
  The `sw` at 0x2568 stores 4 bytes to a0 (arg0 at entry) +0x9cc.
  The `sw` at 0x256c stores 4 bytes to a0 (arg0 at entry) +0x9d0.
  The `sd` at 0x2570 stores 8 bytes to a0 (arg0 at entry) +0x9b0.
  The `sw` at 0x2574 stores 4 bytes to a0 (arg0 at entry) +0x938.
  The `sd` at 0x2588 stores 8 bytes to a0 (arg0 at entry) +0x9b8.
  The `sd` at 0x2594 stores 8 bytes to a0 (arg0 at entry) +0x838.
  The `sd` at 0x25b0 stores 8 bytes to a0 (arg0 at entry) +0x72f8.
  The `sh` at 0x25bc stores 2 bytes to a0 (arg0 at entry) +0x7300.
  The `sw` at 0x25cc stores 4 bytes to a0 (arg0 at entry) +0x808.
  The `sw` at 0x25d0 stores 4 bytes to a0 (arg0 at entry) +0x80c.
  The `sw` at 0x25d4 stores 4 bytes to a0 (arg0 at entry) +0x810.
  The `sd` at 0x25d8 stores 8 bytes to a0 (arg0 at entry) +0x7f0.
  The `sw` at 0x25dc stores 4 bytes to a0 (arg0 at entry) +0x778.
  The `sd` at 0x25f0 stores 8 bytes to a0 (arg0 at entry) +0x7f8.
  The `sd` at 0x25fc stores 8 bytes to a0 (arg0 at entry) +0x678.
  The `sb` at 0x2614 stores 1 byte to a0 (arg0 at entry) +0x730a.
  The `sh` at 0x2620 stores 2 bytes to a0 (arg0 at entry) +0x730c.
  The `sb` at 0x262c stores 1 byte to a0 (arg0 at entry) +0x730b.
  The `sw` at 0x2638 stores 4 bytes to a0 (arg0 at entry) +0xb88.
  The `sw` at 0x263c stores 4 bytes to a0 (arg0 at entry) +0xb90.
  The `sw` at 0x2640 stores 4 bytes to a0 (arg0 at entry) +0xb8c.
  The `sw` at 0x2644 stores 4 bytes to a0 (arg0 at entry) +0xaf8.
  The `sd` at 0x2658 stores 8 bytes to a0 (arg0 at entry) +0xb70.
  The `sd` at 0x265c stores 8 bytes to a0 (arg0 at entry) +0x9e0.
  The `sd` at 0x266c stores 8 bytes to a0 (arg0 at entry) +0x9e8.
  The `sd` at 0x2678 stores 8 bytes to a0 (arg0 at entry) +0x9f8.
  The `sw` at 0x26ac stores 4 bytes to a0 (arg0 at entry) +0xd48.
  The `sw` at 0x26b0 stores 4 bytes to a0 (arg0 at entry) +0xd4c.
  The `sw` at 0x26b4 stores 4 bytes to a0 (arg0 at entry) +0xd50.
  The `sd` at 0x26b8 stores 8 bytes to a0 (arg0 at entry) +0xd30.
  The `sw` at 0x26bc stores 4 bytes to a0 (arg0 at entry) +0xcb8.
  The `sd` at 0x26c8 stores 8 bytes to a0 (arg0 at entry) +0xba0.
  The `sd` at 0x26d8 stores 8 bytes to a0 (arg0 at entry) +0xba8.
  The `sd` at 0x26e4 stores 8 bytes to a0 (arg0 at entry) +0xbb8.
  The `lh` at 0x26ec loads 2 bytes from a0 (arg0 at entry) +0x21a.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0xd54, including `sw` at 0x2728, `sw` at 0x2734.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0xb94, including `sw` at 0x2730, `sw` at 0x273c.
  The `jal` at 0x248c calls kdsp_init_resource with a0=a0+728, a1=0x2000000a, a2=sym(.rodata), a3=sym(.rodata), a4=a0 at entry (arg0), a5=0x0, a6=0x1c0.
  The `jal` at 0x24cc calls kdsp_map_resource with a0=a0+728, a1=0x0, a2=sym(.data)+32768, a3=0xac4400000000.
  The `jal` at 0x24f4 calls kdsp_init_resource with a0=a0+1176, a1=0x2000000a, a2=sym(.rodata), a3=sym(.rodata), a4=a0 at entry (arg0), a5=0x0, a6=0x1c0.
  The `jal` at 0x252c calls kdsp_map_resource with a0=a0+1176, a1=0x0, a2=sym(.data)+32768, a3=?.
  The `jal` at 0x2558 calls kdsp_init_resource with a0=a0+2072, a1=0x2000000b, a2=sym(.rodata), a3=sym(.rodata), a4=a0 at entry (arg0), a5=0x0, a6=0x1c0.
  The `jal` at 0x2590 calls kdsp_map_resource with a0=a0+2072, a1=0x0, a2=sym(.data)+32768, a3=sym(rad_update_aes_mclk), a4=0x3.
  The `jal` at 0x25c0 calls kdsp_init_resource with a0=a0+1624, a1=0x2000000c, a2=sym(.rodata), a3=sym(.rodata), a4=a0 at entry (arg0), a5=0x0, a6=0x1c0.
  The `jal` at 0x25f8 calls kdsp_map_resource with a0=a0+1624, a1=0x0, a2=sym(.data)+32768, a3=sym(rad_update_adat_mclk), a4=0x2.
  The `jal` at 0x2630 calls kdsp_init_resource with a0=a0+2520, a1=0x20000016, a2=sym(.rodata), a3=sym(.rodata), a4=a0 at entry (arg0), a5=0x0, a6=0x1c0, a7=0x1.
  The `jal` at 0x2674 calls kdsp_map_resource with a0=a0+2520, a1=0x0, a2=sym(.data)+32768, a3=sym(rad_get_mclk_params), a4=sym(rad_set_mclk_params), a5=0xac4400000000.
  The `jal` at 0x269c calls kdsp_init_resource with a0=a0+2968, a1=0x20000016, a2=sym(.rodata), a3=sym(.rodata), a4=a0 at entry (arg0), a5=0x0, a6=0x1c0.
  The `jal` at 0x26e0 calls kdsp_map_resource with a0=a0+2968, a1=0x0, a2=sym(.data)+32768, a3=sym(rad_get_mclk_params), a4=sym(rad_set_mclk_params), a5=0x1.
  The `beq` branch at 0x26f8 targets 0x2734, is taken when a0(=[a0+538]:2) == s2(=0x7), and falls through when a0(=[a0+538]:2) != s2(=0x7).
  The `beq` branch at 0x2704 targets 0x2734, is taken when a0(=[a0+538]:2) == a6(=0xd), and falls through when a0(=[a0+538]:2) != a6(=0xd).
  The `beq` branch at 0x270c targets 0x2724, is taken when a0(=[a0+538]:2) == a7(=0xc), and falls through when a0(=[a0+538]:2) != a7(=0xc).
  The `beq` branch at 0x272c targets 0x2710 and is always taken.
  The `beq` branch at 0x2738 targets 0x2710 and is always taken.
  The return at 0x271c has v0 = 0x1.

- `rad_video_sync_paraminfo_vals` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x2740 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x2740-0x27ec (172 bytes).
  It occupies 172 bytes.
  The `lw` at 0x2744 loads 4 bytes from a1 (arg1 at entry) +0x0.
  The `ld` at 0x2750 loads 8 bytes from a0 (arg0 at entry) +0x118.
  The `lh` at 0x2760 loads 2 bytes from [a0+280]:8 +0x21a.
  The `sw` at 0x27b4 stores 4 bytes to (a2 + (a3 << 0x3)) +0x0.
  The `sw` at 0x27bc stores 4 bytes to (a2 + (a3+2 << 0x3)) -0x8.
  2 such `sw` accesses store 4 bytes to a1 (arg1 at entry) +0x4c, including `sw` at 0x27c8, `sw` at 0x27e8.
  The `sw` at 0x27dc stores 4 bytes to (a2 + (a3+1 << 0x3)) -0x8.
  The `bne` branch at 0x2764 targets 0x2798, is taken when at(=[a1]) != v1(=0x1000002a), and falls through when at(=[a1]) == v1(=0x1000002a).
  The `beq` branch at 0x2770 targets 0x2780, is taken when a0 == a3(=[a0+280]:8+2520), and falls through when a0 != a3(=[a0+280]:8+2520).
  The `bne` branch at 0x2778 targets 0x2798, is taken when a0 != t2(=[a0+280]:8+2968), and falls through when a0 == t2(=[a0+280]:8+2968).
  The `beq` branch at 0x2780 targets 0x27a4, is taken when a6(=[[a0+280]:8+538]:2) == t0(=0x7), and falls through when a6(=[[a0+280]:8+538]:2) != t0(=0x7).
  The `beq` branch at 0x2788 targets 0x27a4, is taken when a6(=[[a0+280]:8+538]:2) == t1(=0xd), and falls through when a6(=[[a0+280]:8+538]:2) != t1(=0xd).
  The `beq` branch at 0x2790 targets 0x27cc, is taken when a6(=[[a0+280]:8+538]:2) == t3(=0xc), and falls through when a6(=[[a0+280]:8+538]:2) != t3(=0xc).
  The return at 0x2798 has v0 = a3.
  The return at 0x27c4 has v0 = a3+2.
  The return at 0x27e4 has v0 = a3+1.
  The instructions from 0x27a0 to 0x27a0 are not reached by any path from the entry, and their branches are not listed.

- `rad_create_clockgen` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x27ec (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x27ec-0x2a8c (672 bytes).
  It occupies 672 bytes.
  The `ld` at 0x281c loads 8 bytes from a1 (arg1 at entry) +0x2a0.
  The `sw` at 0x2868 stores 4 bytes to a0 (arg0 at entry) +0x1d8.
  The `sd` at 0x286c stores 8 bytes to a0 (arg0 at entry) +0x1c0.
  The `sd` at 0x2870 stores 8 bytes to a0 (arg0 at entry) +0x1d0.
  The `sd` at 0x2874 stores 8 bytes to a0 (arg0 at entry) +0x1c8.
  The `sw` at 0x287c stores 4 bytes to a0 (arg0 at entry) +0x120.
  The `sd` at 0x2894 stores 8 bytes to a0 (arg0 at entry) +0x1a8.
  The `sd` at 0x2898 stores 8 bytes to a0 (arg0 at entry) +0x1a0.
  The `sd` at 0x289c stores 8 bytes to a0 (arg0 at entry) +0x18.
  The `sd` at 0x28a0 stores 8 bytes to a0 (arg0 at entry) +0x10.
  The `sd` at 0x28a8 stores 8 bytes to a0 (arg0 at entry) +0x8.
  The `sd` at 0x28b0 stores 8 bytes to a0 (arg0 at entry) +0x20.
  The `sw` at 0x28b8 stores 4 bytes to a0 (arg0 at entry) +0x1bc.
  The `sw` at 0x28bc stores 4 bytes to a0 (arg0 at entry) +0x1b4.
  The `sw` at 0x28c0 stores 4 bytes to a0 (arg0 at entry) +0x1b8.
  The `sw` at 0x28c4 stores 4 bytes to a0 (arg0 at entry) +0x1b0.
  The `lw` at 0x28c8 loads 4 bytes from a1 (arg1 at entry) +0x268.
  The `sw` at 0x28e0 stores 4 bytes to a0 (arg0 at entry) +0x1e0.
  The `sd` at 0x28e8 stores 8 bytes to a0 (arg0 at entry) +0x198.
  The `sw` at 0x28ec stores 4 bytes to a0 (arg0 at entry) +0x1f8.
  The `sd` at 0x28f0 stores 8 bytes to a0 (arg0 at entry) +0x1f0.
  The `sw` at 0x28f8 stores 4 bytes to a0 (arg0 at entry) +0x21c.
  4 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x58, including `sd` at 0x2900, `sd` at 0x2a2c, `sd` at 0x2a78.
  4 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x60, including `sd` at 0x2908, `sd` at 0x2a24, `sd` at 0x2a6c.
  2 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x68, including `sd` at 0x2910, `sd` at 0x2a20.
  2 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x70, including `sd` at 0x2918, `sd` at 0x2a1c.
  2 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x78, including `sd` at 0x2920, `sd` at 0x2a18.
  The `sd` at 0x2928 stores 8 bytes to a0 (arg0 at entry) +0x80.
  The `sd` at 0x292c stores 8 bytes to a0 (arg0 at entry) +0x88.
  3 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x20c, including `sw` at 0x2934, `sw` at 0x2a68, `sw` at 0x2a7c.
  The `sd` at 0x2940 stores 8 bytes to a0 (arg0 at entry) +0x1e8.
  The `lw` at 0x2980 loads 4 bytes from a0 (arg0 at entry) +0x208.
  The `sw` at 0x2998 stores 4 bytes to ([a1+672]:8 + ([a0+520] << 0x2)) +0x72cc.
  4 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x208, including `sw` at 0x2a10, `sw` at 0x2a14, `sw` at 0x2a48.
  2 such `lh` accesses load 2 bytes from [a1+672]:8 +0x21a, including `lh` at 0x2a30, `lh` at 0x2a4c.
  The `jal` at 0x2824 calls sprintf with a0=sp-112, a1=sym(.rodata), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x2838 calls sprintf with a0=sp-80, a1=sym(.rodata), a2=a2 at entry (arg2), a3=?.
  The `jal` at 0x285c calls kdsp_init_resource with a0=a0 at entry (arg0), a1=0x20000004, a2=sp-112, a3=sp-80, a4=[a1+672]:8, a5=0x0, a6=0x228.
  The `jal` at 0x29a8 calls kdsp_select_clockgen with a0=a1 at entry (arg1), a1=a0 at entry (arg0), a2=[a1+672]:8+2072, a3=[a1+672]:8+1624, a4=0x5.
  The `jal` at 0x29bc calls kdsp_add_subresource with a0=a0 at entry (arg0), a1=a3 at entry (arg3), a2=?, a3=?.
  The `jal` at 0x29d8 calls rad_set_clockgen with a0=a0 at entry (arg0), a1=a3 at entry (arg3), a2=0x4, a3=0x0, a4=0x1, a5=0x1.
  The `jal` at 0x29e4 calls rad_start_clockgen with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x29f0 calls kdsp_map_resource with a0=a0 at entry (arg0), a1=0x0, a2=?, a3=?.
  The `beq` branch at 0x293c targets 0x2a0c, is taken when s1(=a2) == 0, and falls through when s1(=a2) != 0.
  The `beq` branch at 0x2944 targets 0x2a14, is taken when s1(=a2) == a1(=0x1), and falls through when s1(=a2) != a1(=0x1).
  The `beq` branch at 0x294c targets 0x2a30, is taken when s1(=a2) == t0(=0x2), and falls through when s1(=a2) != t0(=0x2).
  The `beq` branch at 0x2954 targets 0x2a4c, is taken when s1(=a2) == t1(=0x3), and falls through when s1(=a2) != t1(=0x3).
  The `beq` branch at 0x295c targets 0x2a68, is taken when s1(=a2) == a5(=0x4), and falls through when s1(=a2) != a5(=0x4).
  The `beq` branch at 0x2964 targets 0x2a7c, is taken when s1(=a2) == a4(=0x5), and falls through when s1(=a2) != a4(=0x5).
  The `beq` branch at 0x296c targets 0x299c, is taken when a0(=one of 0x0, 0x1) == 0, and falls through when a0(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x2a0c targets 0x296c and is always taken.
  The `beq` branch at 0x2a28 targets 0x296c and is always taken.
  The `beq` branch at 0x2a44 targets 0x296c and is always taken.
  The `beq` branch at 0x2a60 targets 0x296c and is always taken.
  The `beq` branch at 0x2a74 targets 0x296c and is always taken.
  The `beq` branch at 0x2a84 targets 0x299c and is always taken.
  The return at 0x2a04 has v0 = 0x1.

- `rad_destroy_devices` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x2a8c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x2a8c-0x2c7c (496 bytes).
  It occupies 496 bytes.
  The `ld` at 0x2a9c loads 8 bytes from a0 (arg0 at entry) +0xff8.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x1310, including `ld` at 0x2ab4, `ld` at 0x2c08.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x1628, including `ld` at 0x2ac0, `ld` at 0x2c18.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x1940, including `ld` at 0x2acc, `ld` at 0x2c28.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x1c58, including `ld` at 0x2ad8, `ld` at 0x2c38.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x1f70, including `ld` at 0x2ae4, `ld` at 0x2c48.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x2288, including `ld` at 0x2af0, `ld` at 0x2c58.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x25a0, including `ld` at 0x2afc, `ld` at 0x2c68.
  The `jal` at 0x2b14 calls kdsp_destroy_subcode with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x2b24 calls kdsp_destroy_subcode with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x2b80 calls kdsp_destroy_subcode with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x2b90 calls kdsp_destroy_subcode with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x2bfc calls kdsp_destroy_device with a0=a0+3416, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x2c0c calls kdsp_destroy_device with a0=a0+4208, a1=?, a2=?, a3=?.
  The `jal` at 0x2c1c calls kdsp_destroy_device with a0=a0+5000, a1=?, a2=?, a3=?.
  The `jal` at 0x2c2c calls kdsp_destroy_device with a0=a0+5792, a1=?, a2=?, a3=?.
  The `jal` at 0x2c3c calls kdsp_destroy_device with a0=a0+6584, a1=[a0+7256]:8, a2=?, a3=?.
  The `jal` at 0x2c4c calls kdsp_destroy_device with a0=a0+7376, a1=?, a2=[a0+8048]:8, a3=?.
  The `jal` at 0x2c5c calls kdsp_destroy_device with a0=a0+8168, a1=?, a2=?, a3=[a0+8840]:8.
  The `jal` at 0x2c6c calls kdsp_destroy_device with a0=a0+8960, a1=?, a2=?, a3=?, a4=[a0+9632]:8.
  The `bne` branch at 0x2aac targets 0x2bfc, is taken when at(=[a0+4088]:8) != 0, and falls through when at(=[a0+4088]:8) == 0.
  The `bne` branch at 0x2ab8 targets 0x2c0c, is taken when v0(=[a0+4880]:8) != 0, and falls through when v0(=[a0+4880]:8) == 0.
  The `bne` branch at 0x2ac4 targets 0x2c1c, is taken when v1(=[a0+5672]:8) != 0, and falls through when v1(=[a0+5672]:8) == 0.
  The `bne` branch at 0x2ad0 targets 0x2c2c, is taken when a0(=[a0+6464]:8) != 0, and falls through when a0(=[a0+6464]:8) == 0.
  The `bne` branch at 0x2adc targets 0x2c3c, is taken when a1(=[a0+7256]:8) != 0, and falls through when a1(=[a0+7256]:8) == 0.
  The `bne` branch at 0x2ae8 targets 0x2c4c, is taken when a2(=[a0+8048]:8) != 0, and falls through when a2(=[a0+8048]:8) == 0.
  The `bne` branch at 0x2af4 targets 0x2c5c, is taken when a3(=[a0+8840]:8) != 0, and falls through when a3(=[a0+8840]:8) == 0.
  The `bne` branch at 0x2b00 targets 0x2c6c, is taken when a4(=[a0+9632]:8) != 0, and falls through when a4(=[a0+9632]:8) == 0.
  The `beq` branch at 0x2b0c targets 0x2b38 and is always taken.
  The `beq` branch at 0x2b1c targets 0x2b2c, is taken when s3(=-0x52a0) == s1(?), and falls through when s3(=-0x52a0) != s1(?).
  The `beq` branch at 0x2b34 targets 0x2b70, is taken when s2(?) >= 0x3 (signed), and falls through when s2(?) < 0x3 (signed).
  The `bne` branch at 0x2b50 targets 0x2b14, is taken when s4(=-0x5168) != s1(?), and falls through when s4(=-0x5168) == s1(?).
  The `bne` branch at 0x2b58 targets 0x2b24, is taken when s3(=-0x52a0) != s1(?), and falls through when s3(=-0x52a0) == s1(?).
  The `bne` branch at 0x2b68 targets 0x2b3c, is taken when s2(?) < 0x3 (signed), and falls through when s2(?) >= 0x3 (signed).
  The `beq` branch at 0x2b78 targets 0x2ba4 and is always taken.
  The `beq` branch at 0x2b88 targets 0x2b98, is taken when s3(=-0x5578) == s1(?), and falls through when s3(=-0x5578) != s1(?).
  The `beq` branch at 0x2ba0 targets 0x2bdc, is taken when s2(?) >= 0x4 (signed), and falls through when s2(?) < 0x4 (signed).
  The `bne` branch at 0x2bbc targets 0x2b80, is taken when s4(=-0x53d8) != s1(?), and falls through when s4(=-0x53d8) == s1(?).
  The `bne` branch at 0x2bc4 targets 0x2b90, is taken when s3(=-0x5578) != s1(?), and falls through when s3(=-0x5578) == s1(?).
  The `bne` branch at 0x2bd4 targets 0x2ba8, is taken when s2(?) < 0x4 (signed), and falls through when s2(?) >= 0x4 (signed).
  The `beq` branch at 0x2c04 targets 0x2ab8 and is always taken.
  The `beq` branch at 0x2c14 targets 0x2ac4 and is always taken.
  The `beq` branch at 0x2c24 targets 0x2ad0 and is always taken.
  The `beq` branch at 0x2c34 targets 0x2adc and is always taken.
  The `beq` branch at 0x2c44 targets 0x2ae8 and is always taken.
  The `beq` branch at 0x2c54 targets 0x2af4 and is always taken.
  The `beq` branch at 0x2c64 targets 0x2b00 and is always taken.
  The `beq` branch at 0x2c74 targets 0x2b08 and is always taken.
  The return at 0x2bf4 has v0 = one of ret(kdsp_destroy_subcode), ?.

- `rad_init_subsys` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x2c7c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x2c7c-0x2cec (112 bytes).
  It occupies 112 bytes.
  The `sd` at 0x2ca0 stores 8 bytes to a0 (arg0 at entry) +0x240.
  The `sb` at 0x2cb4 stores 1 byte to a0 (arg0 at entry) +0x7303.
  The `lh` at 0x2cb8 loads 2 bytes from a0 (arg0 at entry) +0x21a.
  The `sw` at 0x2cbc stores 4 bytes to a0 (arg0 at entry) +0x72c8.
  The `sw` at 0x2cc4 stores 4 bytes to a0 (arg0 at entry) +0x230.
  The `sw` at 0x2cd0 stores 4 bytes to a0 (arg0 at entry) +0x234.
  The `sb` at 0x2ce8 stores 1 byte to a0 (arg0 at entry) +0x7304.
  The `jal` at 0x2c94 calls kvpalloc with a0=0x1, a1=0x0, a2=0x0, a3=a3 at entry (arg3).
  The `jal` at 0x2ca4 calls bzero with a0=ret(kvpalloc), a1=0x4000, a2=?, a3=?.
  The `beq` branch at 0x2ccc targets 0x2ce4, is taken when v0(=[a0+538]:2) == v1(=0x7), and falls through when v0(=[a0+538]:2) != v1(=0x7).
  The `beq` branch at 0x2ce4 targets 0x2cd4 and is always taken.
  The return at 0x2cdc has v0 = 0x1.

- `rad_update_subsys` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x2cec (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x2cec-0x31b0 (1220 bytes).
  It occupies 1220 bytes.
  The `lw` at 0x2cf8 loads 4 bytes from a0 (arg0 at entry) +0x230.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x238, including `lw` at 0x2d10, `lw` at 0x2dd0, `lw` at 0x30d0.
  4 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x2c8, including `lw` at 0x2d1c, `lw` at 0x30ac, `lw` at 0x3144.
  7 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x240, including `ld` at 0x2d48, `ld` at 0x2d70, `ld` at 0x2da0.
  5 such `lw` accesses load 4 bytes from ?, including `lw` at 0x2d50, `lw` at 0x2d64, `lw` at 0x2d78.
  2 such `sw` accesses store 4 bytes to ?, including `sw` at 0x2d6c, `sw` at 0x3094.
  The `ll` at 0x2d88 loads 4 bytes from a0 (arg0 at entry) +0x2d0.
  The `sc` at 0x2d94 stores 4 bytes to a0 (arg0 at entry) +0x2d0.
  The `ll` at 0x2db8 loads 4 bytes from a0 (arg0 at entry) +0x2cc.
  The `sc` at 0x2dc4 stores 4 bytes to a0 (arg0 at entry) +0x2cc.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x72f0, including `lw` at 0x2df4, `lw` at 0x2f4c.
  The `sw` at 0x2e04 stores 4 bytes to a0 (arg0 at entry) +0x72f0.
  The `sb` at 0x2e1c stores 1 byte to a0 (arg0 at entry) +0x730e.
  The `sb` at 0x2e20 stores 1 byte to a0 (arg0 at entry) +0x730f.
  2 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x7310, including `lbu` at 0x2e24, `lbu` at 0x2ea4.
  The `lw` at 0x2e28 loads 4 bytes from a0 (arg0 at entry) +0x2b0.
  The `lw` at 0x2e2c loads 4 bytes from a0 (arg0 at entry) +0x7238.
  The `lw` at 0x2e30 loads 4 bytes from a0 (arg0 at entry) +0x2a8.
  2 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x7311, including `lbu` at 0x2e34, `lbu` at 0x2eec.
  3 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x7313, including `sb` at 0x2e38, `sb` at 0x2f1c, `sb` at 0x2f24.
  The `lw` at 0x2e40 loads 4 bytes from a0 (arg0 at entry) +0x723c.
  3 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x7312, including `sb` at 0x2e44, `sb` at 0x3068, `sb` at 0x3074.
  The `sw` at 0x2e54 stores 4 bytes to a0 (arg0 at entry) +0x7238.
  The `sw` at 0x2e64 stores 4 bytes to a0 (arg0 at entry) +0x723c.
  The `lbu` at 0x2e88 loads 1 byte from a0 (arg0 at entry) +0x7314.
  The `sb` at 0x2ea0 stores 1 byte to a0 (arg0 at entry) +0x7314.
  The `lbu` at 0x2ed0 loads 1 byte from a0 (arg0 at entry) +0x7316.
  The `sb` at 0x2ee8 stores 1 byte to a0 (arg0 at entry) +0x7316.
  The `lbu` at 0x2f00 loads 1 byte from a0 (arg0 at entry) +0x7317.
  2 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x7311, including `sb` at 0x2f10, `sb` at 0x2f20.
  The `lbu` at 0x2f58 loads 1 byte from a0 (arg0 at entry) +0x7303.
  The `ld` at 0x2f74 loads 8 bytes from a0 (arg0 at entry) +0x72e0.
  The `lw` at 0x2f84 loads 4 bytes from a0 (arg0 at entry) +0x2d0.
  The `lw` at 0x2f88 loads 4 bytes from a0 (arg0 at entry) +0x2cc.
  The `ld` at 0x2f94 loads 8 bytes from a0 (arg0 at entry) +0x72e8.
  2 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x72e8, including `sd` at 0x2fa8, `sd` at 0x3128.
  The `lh` at 0x2fc8 loads 2 bytes from a0 (arg0 at entry) +0x21a.
  The `sw` at 0x2fcc stores 4 bytes to a0 (arg0 at entry) +0x2d0.
  The `sw` at 0x2fd4 stores 4 bytes to a0 (arg0 at entry) +0x2cc.
  The `sd` at 0x2fe0 stores 8 bytes to a0 (arg0 at entry) +0x72e0.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x2bc, including `lw` at 0x2ff0, `lw` at 0x3018, `lw` at 0x30e0.
  2 such `sb` accesses store 1 byte to ?, including `sb` at 0x300c, `sb` at 0x3038.
  The `lbu` at 0x304c loads 1 byte from a0 (arg0 at entry) +0x7315.
  2 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x7310, including `sb` at 0x305c, `sb` at 0x306c.
  2 such `lw` accesses load 4 bytes from ([a0+576]:8 + ([a0+712] << 0x7)) +0x7c, including `lw` at 0x30c4, `lw` at 0x3154.
  2 such `sw` accesses store 4 bytes to ([a0+576]:8 + ([a0+712] << 0x7)) +0x7c, including `sw` at 0x30cc, `sw` at 0x315c.
  The `sw` at 0x30d4 stores 4 bytes to a0 (arg0 at entry) +0x2c8.
  2 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x7304, including `lbu` at 0x30e4, `lbu` at 0x30f8.
  The `sb` at 0x30f4 stores 1 byte to ([a0+29444]:1 + a0) +0x7305.
  The `ld` at 0x310c loads 8 bytes from a0 (arg0 at entry) +0x228.
  The `sw` at 0x3114 stores 4 bytes to a0 (arg0 at entry) +0x726c.
  The `sw` at 0x311c stores 4 bytes to [a0+552]:8 +0x8c.
  2 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x7304, including `sb` at 0x3134, `sb` at 0x3140.
  The `lw` at 0x3184 loads 4 bytes from a0 (arg0 at entry) +0x731c.
  The `jal` at 0x2e08 calls rad_check_adat_rx with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x2e14 calls rad_process_aesrx_subcode with a0=a0 at entry (arg0), a1=0x0, a2=?, a3=?.
  The `jal` at 0x2e80 calls kdsp_update_default_subcode with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x2ec8 calls kdsp_update_default_subcode with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x2f18 calls rad_pio_writeback_subcode_tx with a0=a0+17672, a1=[a0+29457]:1, a2=?, a3=0x1.
  The `jal` at 0x2f64 calls update_ust with a0=?, a1=?, a2=?, a3=?, a5=[a0+29443]:1.
  The `jal` at 0x2f6c calls get_ust_nano with a0=sp-64, a1=?, a2=?, a3=?.
  The `jal` at 0x2fbc calls rad_update_ksync with a0=a0 at entry (arg0), a1=?, a2=?, a3=([a0+716] + [a0+720]), a4=[a0+29416]:8, a6=[a0+29408]:8.
  The `jal` at 0x3064 calls rad_pio_writeback_subcode_tx with a0=a0+12128, a1=[a0+29456]:1, a2=?, a3=?.
  The `jal` at 0x30a4 calls bcopy with a0=?, a1=a0+584, a2=0x80, a3=?, a6=[a0+576]:8, a7=a0+720.
  The `jal` at 0x3174 calls bcopy with a0=([a0+576]:8 + ([a0+712] << 0x7)), a1=a0+584, a2=0x80, a3=([a0+712] << 0x7), a4=(0xffffffff80000000 | [([a0+576]:8 + ([a0+712] << 0x7))+124]), a5=([a0+576]:8 + ([a0+712] << 0x7)), a6=[a0+576]:8.
  The `jal` at 0x3188 calls cmn_err with a0=0x1, a1=sym(.rodata), a2=[a0+29468], a3=?.
  The `jal` at 0x3190 calls rad_stop_status_dma with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x3198 calls rad_start_status_dma with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `beq` branch at 0x2d08 targets 0x2f28, is taken when at(=[a0+560]) == 0, and falls through when at(=[a0+560]) != 0.
  The `bne` branch at 0x2d18 targets 0x2f44, is taken when a0(=[a0+568]) < 0x2 (signed), and falls through when a0(=[a0+568]) >= 0x2 (signed).
  The `beq` branch at 0x2d5c targets 0x3078, is taken when (s2(=0xffffffff80000000) & t8(?)) == 0, and falls through when (s2(=0xffffffff80000000) & t8(?)) != 0.
  The `beq` branch at 0x2d80 targets 0x2da8, is taken when (a6(?) & 0x100) == 0, and falls through when (a6(?) & 0x100) != 0.
  The `beql` branch at 0x2d98 targets 0x2d88, is taken when a4(=[a0+720]+1) == 0, and falls through when a4(=[a0+720]+1) != 0; its branch-likely delay slot `nop` at 0x2d9c runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x2db0 targets 0x2dd0, is taken when (a6(?) & 0x80) == 0, and falls through when (a6(?) & 0x80) != 0.
  The `beql` branch at 0x2dc8 targets 0x2db8, is taken when t2(=[a0+716]+1) == 0, and falls through when t2(=[a0+716]+1) != 0; its branch-likely delay slot `nop` at 0x2dcc runs only when taken and is annulled on fall-through.
  The `bne` branch at 0x2de4 targets 0x2d48, is taken when s1(?) < a4(=[a0+568]-1) (signed), and falls through when s1(?) >= a4(=[a0+568]-1) (signed).
  The `beq` branch at 0x2dec targets 0x3144, is taken when a4(=[a0+568]-1) == s1(?), and falls through when a4(=[a0+568]-1) != s1(?).
  The `beq` branch at 0x2e00 targets 0x2f58, is taken when (a5(=[a0+29424]+1) & 0x3ff) == 0, and falls through when (a5(=[a0+29424]+1) & 0x3ff) != 0.
  The `bne` branch at 0x2e9c targets 0x2e68, is taken when s1(?) < 0x3 (signed), and falls through when s1(?) >= 0x3 (signed).
  The `beq` branch at 0x2ea8 targets 0x3044, is taken when a1(=[a0+29456]:1) == 0, and falls through when a1(=[a0+29456]:1) != 0.
  The `bne` branch at 0x2ee4 targets 0x2eb0, is taken when s1(?) < 0x4 (signed), and falls through when s1(?) >= 0x4 (signed).
  The `bne` branch at 0x2ef0 targets 0x2f2c, is taken when a1(=[a0+29457]:1) != 0, and falls through when a1(=[a0+29457]:1) == 0.
  The `bne` branch at 0x2ef8 targets 0x2f10, is taken when a0(?) != 0, and falls through when a0(?) == 0.
  The `beq` branch at 0x2f04 targets 0x2f2c, is taken when a2(=[a0+29463]:1) == 0, and falls through when a2(=[a0+29463]:1) != 0.
  The `bnel` branch at 0x2f48 targets 0x2df8, is taken when a0(=[a0+568]) != a4(=0x1), and falls through when a0(=[a0+568]) == a4(=0x1); its branch-likely delay slot `lw a5,29424(s0)` at 0x2f4c runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x2f50 targets 0x31a8 and is always taken.
  The `beq` branch at 0x2f5c targets 0x2e08, is taken when a5(=[a0+29443]:1) == 0, and falls through when a5(=[a0+29443]:1) != 0.
  The `beq` branch at 0x2f7c targets 0x2fc4, is taken when a6(=[a0+29408]:8) == 0, and falls through when a6(=[a0+29408]:8) != 0.
  The `blez` branch at 0x2f90 targets 0x3120, is taken when a3(=([a0+716] + [a0+720])) <= 0 (signed), and falls through when a3(=([a0+716] + [a0+720])) > 0 (signed).
  The `bgtz` branch at 0x2fac targets 0x2fbc, is taken when a0(?) > 0 (signed), and falls through when a0(?) <= 0 (signed).
  The `blez` branch at 0x2fb4 targets 0x2fc8, is taken when a4(=[a0+29416]:8) <= 0 (signed), and falls through when a4(=[a0+29416]:8) > 0 (signed).
  The `beq` branch at 0x2fdc targets 0x30e0, is taken when a0(=[a0+538]:2) == a6(=0x7), and falls through when a0(=[a0+538]:2) != a6(=0x7).
  The `bne` branch at 0x2fe8 targets 0x2e08, is taken when a0(=[a0+538]:2) != a7(=0xd), and falls through when a0(=[a0+538]:2) == a7(=0xd).
  The `beq` branch at 0x3010 targets 0x2e08, is taken when a0(?) >= 0x4 (signed), and falls through when a0(?) < 0x4 (signed).
  The `bne` branch at 0x3034 targets 0x2ff0, is taken when a0(?) < 0x4 (signed), and falls through when a0(?) >= 0x4 (signed).
  The `beq` branch at 0x303c targets 0x2e08 and is always taken.
  The `bne` branch at 0x3044 targets 0x305c, is taken when a0(?) != 0, and falls through when a0(?) == 0.
  The `beq` branch at 0x3050 targets 0x2eb0, is taken when t3(=[a0+29461]:1) == 0, and falls through when t3(=[a0+29461]:1) != 0.
  The `beq` branch at 0x3070 targets 0x2eac and is always taken.
  The `beq` branch at 0x30b4 targets 0x30d0, is taken when a0(?) == a5(=[a0+712]), and falls through when a0(?) != a5(=[a0+712]).
  The `beq` branch at 0x30d8 targets 0x2dec and is always taken.
  The `beq` branch at 0x30fc targets 0x312c, is taken when a0(=[a0+29444]:1) == 0, and falls through when a0(=[a0+29444]:1) != 0.
  The `beq` branch at 0x3104 targets 0x3138, is taken when a0(=[a0+29444]:1) == a2(=0x1), and falls through when a0(=[a0+29444]:1) != a2(=0x1).
  The `beq` branch at 0x3118 targets 0x2e08 and is always taken.
  The `beq` branch at 0x3124 targets 0x2fac and is always taken.
  The `beq` branch at 0x3130 targets 0x310c and is always taken.
  The `beq` branch at 0x313c targets 0x310c and is always taken.
  The `beq` branch at 0x31a0 targets 0x2f2c and is always taken.
  The `beq` branch at 0x31a8 targets 0x3148 and is always taken.
  The return at 0x2f3c has v0 = one of ret(kdsp_update_default_subcode), ?, ret(rad_start_status_dma).

- `rad_start_status_dma` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x31b0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x31b0-0x3340 (400 bytes).
  It occupies 400 bytes.
  The `lw` at 0x31b0 loads 4 bytes from a0 (arg0 at entry) +0x230.
  3 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x238, including `sw` at 0x31d4, `sw` at 0x3200, `sw` at 0x332c.
  5 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x240, including `ld` at 0x3210, `ld` at 0x3234, `ld` at 0x3260.
  2 such `sw` accesses store 4 bytes to ?, including `sw` at 0x321c, `sw` at 0x3240.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x238, including `lw` at 0x3220, `lw` at 0x3244, `lw` at 0x3294.
  7 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x228, including `ld` at 0x3298, `ld` at 0x32ac, `ld` at 0x32b4.
  The `sw` at 0x32a8 stores 4 bytes to [a0+552]:8 +0x504.
  The `sw` at 0x32b0 stores 4 bytes to [a0+552]:8 +0x500.
  The `sw` at 0x32bc stores 4 bytes to [a0+552]:8 +0x528.
  The `sw` at 0x32c4 stores 4 bytes to [a0+552]:8 +0x4bc.
  The `sw` at 0x32cc stores 4 bytes to [a0+552]:8 +0x4b4.
  The `sw` at 0x32d4 stores 4 bytes to [a0+552]:8 +0x4b8.
  The `lw` at 0x32d8 loads 4 bytes from a0 (arg0 at entry) +0x234.
  The `sw` at 0x3300 stores 4 bytes to [a0+552]:8 +0x5c.
  The `sw` at 0x3304 stores 4 bytes to a0 (arg0 at entry) +0x2c8.
  The `sw` at 0x3310 stores 4 bytes to a0 (arg0 at entry) +0x230.
  The `jal` at 0x325c calls rad_one_shot_status with a0=a0 at entry (arg0), a1=[a0+576]:8, a2=?, a3=?.
  The `jal` at 0x327c calls bcopy with a0=[a0+576]:8, a1=a0+584, a2=0x80, a3=?.
  The `jal` at 0x328c calls Mem_to_PCI_DMA with a0=a0 at entry (arg0), a1=[a0+576]:8, a2=0x1000, a3=?.
  The `jal` at 0x3330 calls us_delay with a0=0x12c, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=0x1, a4=0x80.
  The `bne` branch at 0x31c8 targets 0x3330, is taken when at(=[a0+560]) != 0, and falls through when at(=[a0+560]) == 0.
  The `beq` branch at 0x31e0 targets 0x31f8, is taken when v0(?) >= 0x80 (signed), and falls through when v0(?) < 0x80 (signed).
  The `bne` branch at 0x31f0 targets 0x31d8, is taken when v0(?) < 0x80 (signed), and falls through when v0(?) >= 0x80 (signed).
  The `beq` branch at 0x31fc targets 0x3328, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `blez` branch at 0x3204 targets 0x325c, is taken when v0(?) <= 0 (signed), and falls through when v0(?) > 0 (signed).
  The `beq` branch at 0x322c targets 0x3258, is taken when v0(?) >= a2(=[a0+568]) (signed), and falls through when v0(?) < a2(=[a0+568]) (signed).
  The `bne` branch at 0x3250 targets 0x3210, is taken when v0(?) < a5(=[a0+568]) (signed), and falls through when v0(?) >= a5(=[a0+568]) (signed).
  The `bne` branch at 0x3264 targets 0x3274, is taken when v0(=ret(rad_one_shot_status)) != 0, and falls through when v0(=ret(rad_one_shot_status)) == 0.
  The `beq` branch at 0x326c targets 0x3318 and is always taken.
  The `beq` branch at 0x3328 targets 0x3314 and is always taken.
  The `beq` branch at 0x3338 targets 0x3314 and is always taken.
  The return at 0x3320 has v0 = one of 0x0, 0x1.

- `rad_stop_status_dma` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x3340 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x3340-0x336c (44 bytes).
  It occupies 44 bytes.
  The `lw` at 0x3340 loads 4 bytes from a0 (arg0 at entry) +0x230.
  The `ld` at 0x334c loads 8 bytes from a0 (arg0 at entry) +0x228.
  The `sw` at 0x3358 stores 4 bytes to [a0+552]:8 +0x5c.
  The `sw` at 0x3360 stores 4 bytes to a0 (arg0 at entry) +0x230.
  The `beq` branch at 0x3344 targets 0x3364, is taken when at(=[a0+560]) == 0, and falls through when at(=[a0+560]) != 0.
  The return at 0x3364 has v0 = 0x1.

- `rad_sync_device_ust` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x336c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x336c-0x34e0 (372 bytes).
  It occupies 372 bytes.
  The `ld` at 0x3394 loads 8 bytes from a0 (arg0 at entry) +0x2a0.
  The `ld` at 0x33c4 loads 8 bytes from [a0+672]:8 +0x72a8.
  7 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x1b0, including `sd` at 0x33dc, `sd` at 0x342c, `sd` at 0x343c.
  The `lw` at 0x33e4 loads 4 bytes from [a0+672]:8 +0x7320.
  The `lw` at 0x3440 loads 4 bytes from a0 (arg0 at entry) +0x314.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x310, including `sw` at 0x3494, `sw` at 0x3498.
  The `jal` at 0x3390 calls update_ust with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x3398 calls get_ust_nano with a0=sp-48, a1=?, a2=?, a3=?.
  The `bne` branch at 0x33d8 targets 0x3498, is taken when at(=[sym(.sbss)+4]) != 0, and falls through when at(=[sym(.sbss)+4]) == 0.
  The `beq` branch at 0x33f8 targets 0x3498, is taken when a1(=[[a0+672]:8+29472]) == a2(=0x37), and falls through when a1(=[[a0+672]:8+29472]) != a2(=0x37).
  The `beq` branch at 0x3400 targets 0x3498, is taken when a1(=[[a0+672]:8+29472]) == a4(=0x38), and falls through when a1(=[[a0+672]:8+29472]) != a4(=0x38).
  The `beq` branch at 0x340c targets 0x3498, is taken when a1(=[[a0+672]:8+29472]) == t8(=0x51), and falls through when a1(=[[a0+672]:8+29472]) != t8(=0x51).
  The `beq` branch at 0x3414 targets 0x3498, is taken when a1(=[[a0+672]:8+29472]) == a5(=0x45), and falls through when a1(=[[a0+672]:8+29472]) != a5(=0x45).
  The `beq` branch at 0x3428 targets 0x34b4, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0x3430 targets 0x3440, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x3444 targets 0x3490, is taken when at(=[a0+788]) == 0, and falls through when at(=[a0+788]) != 0.
  The `bltz` branch at 0x347c targets 0x34d0, is taken when v0(?) < 0 (signed), and falls through when v0(?) >= 0 (signed).
  The `beq` branch at 0x3484 targets 0x3490, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x3490 targets 0x349c and is always taken.
  The `beq` branch at 0x34bc targets 0x3440, is taken when s1(=a1) >= t0(?) (unsigned), and falls through when s1(=a1) < t0(?) (unsigned).
  The `beq` branch at 0x34c8 targets 0x3440 and is always taken.
  The `beq` branch at 0x34d0 targets 0x3490, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0x34d8 targets 0x3490 and is always taken.
  The return at 0x34ac has v0 = one of ?, ret(get_ust_nano).

- `rad_start_dma` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x34e0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x34e0-0x399c (1212 bytes).
  It occupies 1212 bytes.
  The `ld` at 0x34e8 loads 8 bytes from a0 (arg0 at entry) +0x2a0.
  4 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x2c0, including `lw` at 0x34f0, `lw` at 0x36b4, `lw` at 0x3758.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x268, including `lw` at 0x3518, `lw` at 0x3574.
  The `lw` at 0x3528 loads 4 bytes from a0 (arg0 at entry) +0x238.
  The `lbu` at 0x3544 loads 1 byte from ([a0+672]:8 + one of 0x225c, 0x2574) +0x0.
  4 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x1b8, including `ld` at 0x356c, `ld` at 0x35a0, `ld` at 0x3604.
  The `sw` at 0x3570 stores 4 bytes to [a0+440]:8 +0x0.
  The `lw` at 0x357c loads 4 bytes from a0 (arg0 at entry) +0x220.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x1c8, including `ld` at 0x3580, `ld` at 0x3628.
  The `ld` at 0x358c loads 8 bytes from a0 (arg0 at entry) +0x1f0.
  The `lw` at 0x3590 loads 4 bytes from a0 (arg0 at entry) +0x23c.
  The `lw` at 0x3594 loads 4 bytes from [a0+496]:8 +0x1d8.
  2 such `sw` accesses store 4 bytes to [a0+440]:8 +0x4, including `sw` at 0x35a4, `sw` at 0x3618.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0x35b0, `lw` at 0x35b8.
  5 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x314, including `sw` at 0x35b4, `sw` at 0x37bc, `sw` at 0x3830.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x310, including `sw` at 0x35bc, `sw` at 0x3918.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0x35c0, `ld` at 0x35c8.
  2 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x308, including `sd` at 0x35c4, `sd` at 0x38d4.
  2 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x1a8, including `sd` at 0x35cc, `sd` at 0x38c4.
  The `sb` at 0x35d0 stores 1 byte to a0 (arg0 at entry) +0x274.
  The `lw` at 0x35d4 loads 4 bytes from [a0+672]:8 +0x72c8.
  The `sw` at 0x35e0 stores 4 bytes to [a0+672]:8 +0x72c8.
  The `ld` at 0x361c loads 8 bytes from a0 (arg0 at entry) +0x1d0.
  The `ld` at 0x3620 loads 8 bytes from a0 (arg0 at entry) +0x1e0.
  12 such `ld` accesses load 8 bytes from [a0+672]:8 +0x228, including `ld` at 0x3634, `ld` at 0x3644, `ld` at 0x3658.
  The `lwu` at 0x3638 loads 4 bytes from a0 (arg0 at entry) +0x2cc.
  The `sw` at 0x3640 stores 4 bytes to ([a0+716] + [[a0+672]:8+552]:8) +0x0.
  The `lwu` at 0x3648 loads 4 bytes from a0 (arg0 at entry) +0x2c8.
  The `sw` at 0x3654 stores 4 bytes to ([a0+712] + [[a0+672]:8+552]:8) +0x0.
  The `lw` at 0x365c loads 4 bytes from a0 (arg0 at entry) +0x2f0.
  The `lw` at 0x3660 loads 4 bytes from a0 (arg0 at entry) +0x2e0.
  The `lwu` at 0x3664 loads 4 bytes from a0 (arg0 at entry) +0x2d0.
  The `sw` at 0x3680 stores 4 bytes to ([a0+720] + [[a0+672]:8+552]:8) +0x0.
  The `lwu` at 0x3688 loads 4 bytes from a0 (arg0 at entry) +0x2d8.
  The `sw` at 0x3690 stores 4 bytes to ([a0+728] + [[a0+672]:8+552]:8) +0x0.
  The `lwu` at 0x3698 loads 4 bytes from a0 (arg0 at entry) +0x2d4.
  The `sw` at 0x36a0 stores 4 bytes to ([a0+724] + [[a0+672]:8+552]:8) +0x0.
  The `lwu` at 0x36a8 loads 4 bytes from a0 (arg0 at entry) +0x2dc.
  The `sw` at 0x36b0 stores 4 bytes to ([a0+732] + [[a0+672]:8+552]:8) +0x0.
  2 such `lh` accesses load 2 bytes from table(sym(.data)) +0x0, including `lh` at 0x36d4, `lh` at 0x37a4.
  2 such `lh` accesses load 2 bytes from table(sym(.data)) +0x8, including `lh` at 0x36d8, `lh` at 0x3770.
  2 such `lw` accesses load 4 bytes from table(sym(.data)) +0xc, including `lw` at 0x36dc, `lw` at 0x3790.
  2 such `lh` accesses load 2 bytes from table(sym(.data)) +0xa, including `lh` at 0x36e4, `lh` at 0x377c.
  The `lh` at 0x36f4 loads 2 bytes from table(sym(.data)) +0x2.
  2 such `lw` accesses load 4 bytes from ([[a0+672]:8+552]:8 + ([table(sym(.data))+8]:2 << 0x2)) -0x40, including `lw` at 0x36f8, `lw` at 0x3788.
  2 such `lw` accesses load 4 bytes from ([[a0+672]:8+552]:8 + (entry(sym(.data)) << 0x2)) -0x40, including `lw` at 0x3700, `lw` at 0x37b8.
  The `lw` at 0x3708 loads 4 bytes from table(sym(.data)) +0x4.
  4 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x2e8, including `ld` at 0x37d0, `ld` at 0x37f0, `ld` at 0x3844.
  4 such `lw` accesses load 4 bytes from [a0+744]:8 +0x0, including `lw` at 0x37d8, `lw` at 0x3804, `lw` at 0x384c.
  2 such `sw` accesses store 4 bytes to [a0+744]:8 +0x0, including `sw` at 0x37ec, `sw` at 0x3854.
  2 such `lwu` accesses load 4 bytes from a0 (arg0 at entry) +0x2e4, including `lwu` at 0x37f8, `lwu` at 0x385c.
  2 such `sw` accesses store 4 bytes to ([a0+740] + [[a0+672]:8+552]:8) +0x0, including `sw` at 0x3810, `sw` at 0x3874.
  The `ld` at 0x388c loads 8 bytes from a0 (arg0 at entry) +0x1a8.
  The `lw` at 0x38f0 loads 4 bytes from [[a0+672]:8+552]:8 +0x30.
  The `sw` at 0x3900 stores 4 bytes to a0 (arg0 at entry) +0x2c4.
  The `lw` at 0x3928 loads 4 bytes from [a0+672]:8 +0x2c0.
  2 such `sb` accesses store 1 byte to [a0+672]:8 +0x7309, including `sb` at 0x3938, `sb` at 0x3970.
  2 such `sb` accesses store 1 byte to [a0+672]:8 +0x800, including `sb` at 0x393c, `sb` at 0x3974.
  The `lw` at 0x3958 loads 4 bytes from [a0+672]:8 +0x7240.
  The `sw` at 0x3968 stores 4 bytes to [a0+672]:8 +0x7240.
  The `sw` at 0x396c stores 4 bytes to [[a0+672]:8+552]:8 +0x80.
  The `lw` at 0x3988 loads 4 bytes from [a0+672]:8 +0x731c.
  The `jal` at 0x3550 calls rad_start_dma with a0=([a0+672]:8 + one of 0x1fe8, 0x2300), a1=0x7, a2=[([a0+672]:8 + one of 0x225c, 0x2574)]:1, a3=[a0+704].
  The `jal` at 0x3598 calls bzero with a0=[a0+456]:8, a1=([a0+544] << 0x2), a2=?, a3=[a0+440]:8.
  The `jal` at 0x3608 calls bzero with a0=[a0+456]:8, a1=([a0+544] << 0x2), a2=?, a3=[a0+440]:8.
  The `jal` at 0x362c calls Mem_to_PCI_DMA with a0=[a0+672]:8, a1=[a0+456]:8, a2=?, a3=[a0+464]:8.
  The `jal` at 0x3750 calls us_delay with a0=0xa, a1=?, a2=?, a3=?, a5=sym(.data).
  The `jal` at 0x38ec calls rad_sync_device_ust with a0=a0 at entry (arg0), a1=[[[a0+672]:8+552]:8+48], a2=?, a3=?, a6=[([[a0+672]:8+552]:8 + (entry(sym(.data)) << 0x2))-64].
  The `jal` at 0x38fc calls rad_start_status_dma with a0=[a0+672]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x398c calls cmn_err with a0=0x1, a1=sym(.rodata), a2=[[a0+672]:8+29468], a3=[a0+704].
  The `beq` branch at 0x3504 targets 0x3980, is taken when a3(=[a0+704]) == at(=-0x2), and falls through when a3(=[a0+704]) != at(=-0x2).
  The `beq` branch at 0x3510 targets 0x3984, is taken when a3(=[a0+704]) == v0(=-0x1), and falls through when a3(=[a0+704]) != v0(=-0x1).
  The `beq` branch at 0x3520 targets 0x3600, is taken when (v1(=[a0+616]) & 0x400) == 0, and falls through when (v1(=[a0+616]) & 0x400) != 0.
  The `beq` branch at 0x3530 targets 0x3568, is taken when a0(=[a0+568]) >= 0x20 (signed), and falls through when a0(=[a0+568]) < 0x20 (signed).
  The `beq` branch at 0x3538 targets 0x3544, is taken when a3(=[a0+704]) == a1(=0x7), and falls through when a3(=[a0+704]) != a1(=0x7).
  The `bne` branch at 0x3548 targets 0x356c, is taken when a2(=[([a0+672]:8 + one of 0x225c, 0x2574)]:1) != 0, and falls through when a2(=[([a0+672]:8 + one of 0x225c, 0x2574)]:1) == 0.
  The `bne` branch at 0x3558 targets 0x356c, is taken when v0(=ret(rad_start_dma)) != 0, and falls through when v0(=ret(rad_start_dma)) == 0.
  The `beq` branch at 0x3560 targets 0x35e4 and is always taken.
  The `beq` branch at 0x3584 targets 0x3608, is taken when (a2(=[a0+616]) & 0x1) == 0, and falls through when (a2(=[a0+616]) & 0x1) != 0.
  The `beq` branch at 0x35a8 targets 0x361c, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `beq` branch at 0x3600 targets 0x3570 and is always taken.
  The `beq` branch at 0x3614 targets 0x35a8 and is always taken.
  The `beq` branch at 0x3720 targets 0x3948, is taken when a3(=[a0+704]) == a1(=0x7), and falls through when a3(=[a0+704]) != a1(=0x7).
  The `beq` branch at 0x3728 targets 0x3948, is taken when a3(=[a0+704]) == a0(=0x6), and falls through when a3(=[a0+704]) != a0(=0x6).
  The `beq` branch at 0x3740 targets 0x37cc and is always taken.
  The `bne` branch at 0x3748 targets 0x37a4, is taken when t8(?) != a3(?), and falls through when t8(?) == a3(?).
  The `bne` branch at 0x379c targets 0x3748, is taken when s2(?) < 0x32 (signed), and falls through when s2(?) >= 0x32 (signed).
  The `beq` branch at 0x37b4 targets 0x3814, is taken when s2(?) == a7(=0x32), and falls through when s2(?) != a7(=0x32).
  The `beq` branch at 0x37c4 targets 0x388c, is taken when a7(=one of 0x0, 0x1) == 0, and falls through when a7(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x380c targets 0x3750 and is always taken.
  The `bne` branch at 0x3820 targets 0x3834, is taken when a0(?) != ra(?), and falls through when a0(?) == ra(?).
  The `beq` branch at 0x382c targets 0x3880 and is always taken.
  The `beq` branch at 0x383c targets 0x387c, is taken when at(?) >= 0x6 (signed), and falls through when at(?) < 0x6 (signed).
  The `beq` branch at 0x3884 targets 0x37c0 and is always taken.
  The `beq` branch at 0x3904 targets 0x3950, is taken when v0(=ret(rad_start_status_dma)) == 0, and falls through when v0(=ret(rad_start_status_dma)) != 0.
  The `beq` branch at 0x3914 targets 0x3928, is taken when a3(=[a0+704]) == t1(=0x4), and falls through when a3(=[a0+704]) != t1(=0x4).
  The `bne` branch at 0x3920 targets 0x35d0, is taken when a3(=[a0+704]) != t2(=0x7), and falls through when a3(=[a0+704]) == t2(=0x7).
  The `beq` branch at 0x3930 targets 0x3958, is taken when (t3(=[[a0+672]:8+704]) & 0x40) == 0, and falls through when (t3(=[[a0+672]:8+704]) & 0x40) != 0.
  The `beq` branch at 0x3940 targets 0x35d0 and is always taken.
  The `beq` branch at 0x3948 targets 0x3730 and is always taken.
  The `beq` branch at 0x3950 targets 0x35e4 and is always taken.
  The `beq` branch at 0x3978 targets 0x35d0 and is always taken.
  The `beq` branch at 0x3994 targets 0x35e4 and is always taken.
  The return at 0x35f8 has v0 = one of 0x0, 0x1.

- `rad_start_subcode_tx` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x399c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x399c-0x3b60 (452 bytes).
  It occupies 452 bytes.
  The `lbu` at 0x39a4 loads 1 byte from a0 (arg0 at entry) +0x274.
  The `ld` at 0x39a8 loads 8 bytes from a0 (arg0 at entry) +0x2a0.
  2 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x1b0, including `sd` at 0x39cc, `sd` at 0x3a68.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x1b8, including `ld` at 0x39e4, `ld` at 0x3a38.
  The `sw` at 0x39e8 stores 4 bytes to [a0+440]:8 +0x0.
  The `lw` at 0x39ec loads 4 bytes from a0 (arg0 at entry) +0x220.
  The `ld` at 0x39f0 loads 8 bytes from a0 (arg0 at entry) +0x1c8.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x2e8, including `ld` at 0x39fc, `ld` at 0x3a0c.
  2 such `lw` accesses load 4 bytes from [a0+744]:8 +0x0, including `lw` at 0x3a00, `lw` at 0x3a1c.
  The `sw` at 0x3a08 stores 4 bytes to [a0+744]:8 +0x0.
  3 such `ld` accesses load 8 bytes from [a0+672]:8 +0x228, including `ld` at 0x3a10, `ld` at 0x3adc, `ld` at 0x3b3c.
  The `lwu` at 0x3a14 loads 4 bytes from a0 (arg0 at entry) +0x2e4.
  The `sw` at 0x3a20 stores 4 bytes to ([a0+740] + [[a0+672]:8+552]:8) +0x0.
  The `lw` at 0x3a24 loads 4 bytes from a0 (arg0 at entry) +0x268.
  The `lw` at 0x3a2c loads 4 bytes from a0 (arg0 at entry) +0x23c.
  The `sw` at 0x3a48 stores 4 bytes to [a0+440]:8 +0x4.
  The `ld` at 0x3a4c loads 8 bytes from a0 (arg0 at entry) +0x1a8.
  The `lw` at 0x3a50 loads 4 bytes from a0 (arg0 at entry) +0x2c0.
  2 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x1a8, including `sd` at 0x3a98, `sd` at 0x3b18.
  The `lbu` at 0x3a9c loads 1 byte from [a0+672]:8 +0x7311.
  The `sb` at 0x3aa4 stores 1 byte to [a0+672]:8 +0x7311.
  The `sw` at 0x3ab8 stores 4 bytes to a0 (arg0 at entry) +0x2c4.
  The `sb` at 0x3abc stores 1 byte to a0 (arg0 at entry) +0x274.
  The `lw` at 0x3ac0 loads 4 bytes from [a0+672]:8 +0x72c8.
  The `sw` at 0x3ad0 stores 4 bytes to [a0+672]:8 +0x72c8.
  The `lh` at 0x3ad8 loads 2 bytes from sym(.data) +0x50.
  The `lh` at 0x3ae4 loads 2 bytes from sym(.data) +0x52.
  The `lw` at 0x3aec loads 4 bytes from ([[a0+672]:8+552]:8 + ([sym(.data)+80]:2 << 0x2)) -0x40.
  The `lw` at 0x3af0 loads 4 bytes from sym(.data) +0x54.
  The `lbu` at 0x3b1c loads 1 byte from [a0+672]:8 +0x7310.
  The `sb` at 0x3b28 stores 1 byte to [a0+672]:8 +0x7310.
  The `lh` at 0x3b38 loads 2 bytes from sym(.data) +0x80.
  The `lh` at 0x3b48 loads 2 bytes from sym(.data) +0x82.
  The `lw` at 0x3b4c loads 4 bytes from ([[a0+672]:8+552]:8 + ([sym(.data)+128]:2 << 0x2)) -0x40.
  The `lw` at 0x3b50 loads 4 bytes from sym(.data) +0x84.
  The `jal` at 0x39bc calls update_ust with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x39f4 calls bzero with a0=[a0+456]:8, a1=([a0+544] << 0x2), a2=[a0+440]:8, a3=a3 at entry (arg3).
  The `jal` at 0x3a44 calls update_ust with a0=?, a1=?, a2=?, a3=?, a4=[a0+440]:8, a5=[a0+572], a7=0x1.
  The `jal` at 0x3aa8 calls rad_start_status_dma with a0=[a0+672]:8, a1=?, a2=?, a3=?, a5=-0x1.
  The `beq` branch at 0x39b4 targets 0x39e4, is taken when at(=[a0+628]:1) == 0, and falls through when at(=[a0+628]:1) != 0.
  The `beq` branch at 0x3a6c targets 0x3ad4, is taken when v0(=[a0+704]) == a5(=-0x1), and falls through when v0(=[a0+704]) != a5(=-0x1).
  The `beq` branch at 0x3a74 targets 0x3b34, is taken when v0(=[a0+704]) == a4(=-0x2), and falls through when v0(=[a0+704]) != a4(=-0x2).
  The `beq` branch at 0x3a94 targets 0x3b1c, is taken when v0(=[a0+704]) == a5(=-0x1), and falls through when v0(=[a0+704]) != a5(=-0x1).
  The `beq` branch at 0x3ab0 targets 0x3b2c, is taken when v0(=ret(rad_start_status_dma)) == 0, and falls through when v0(=ret(rad_start_status_dma)) != 0.
  The `beq` branch at 0x3acc targets 0x39d0 and is always taken.
  The `bne` branch at 0x3b14 targets 0x3a9c, is taken when v0(=[a0+704]) != a5(=-0x1), and falls through when v0(=[a0+704]) == a5(=-0x1).
  The `beq` branch at 0x3b24 targets 0x3aa8 and is always taken.
  The `beq` branch at 0x3b2c targets 0x39d0 and is always taken.
  The `beq` branch at 0x3b58 targets 0x3a7c and is always taken.
  The return at 0x39dc has v0 = one of 0x0, 0x1.

- `rad_stop_dma` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x3b60 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x3b60-0x3d84 (548 bytes).
  It occupies 548 bytes.
  The `lbu` at 0x3b68 loads 1 byte from a0 (arg0 at entry) +0x274.
  The `ld` at 0x3b74 loads 8 bytes from a0 (arg0 at entry) +0x2a0.
  The `lw` at 0x3b90 loads 4 bytes from a0 (arg0 at entry) +0x2c0.
  6 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x2e8, including `ld` at 0x3bb4, `ld` at 0x3bc4, `ld` at 0x3cb8.
  4 such `lw` accesses load 4 bytes from [a0+744]:8 +0x0, including `lw` at 0x3bb8, `lw` at 0x3bd4, `lw` at 0x3d58.
  3 such `sw` accesses store 4 bytes to [a0+744]:8 +0x0, including `sw` at 0x3bc0, `sw` at 0x3d68, `sw` at 0x3d80.
  2 such `ld` accesses load 8 bytes from [a0+672]:8 +0x228, including `ld` at 0x3bc8, `ld` at 0x3bdc.
  2 such `lwu` accesses load 4 bytes from a0 (arg0 at entry) +0x2e4, including `lwu` at 0x3bcc, `lwu` at 0x3be0.
  The `sw` at 0x3bd8 stores 4 bytes to ([a0+740] + [[a0+672]:8+552]:8) +0x0.
  The `lw` at 0x3be4 loads 4 bytes from [a0+672]:8 +0x731c.
  2 such `lw` accesses load 4 bytes from ([a0+740] + [[a0+672]:8+552]:8) +0x0, including `lw` at 0x3bec, `lw` at 0x3bf4.
  3 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x274, including `sb` at 0x3c00, `sb` at 0x3c4c, `sb` at 0x3d50.
  The `lw` at 0x3c04 loads 4 bytes from [a0+672]:8 +0x72c8.
  The `sw` at 0x3c0c stores 4 bytes to [a0+672]:8 +0x72c8.
  The `lbu` at 0x3c24 loads 1 byte from [a0+672]:8 +0x7310.
  The `sb` at 0x3c34 stores 1 byte to [a0+672]:8 +0x7310.
  The `sb` at 0x3c44 stores 1 byte to [a0+672]:8 +0x7312.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x238, including `lw` at 0x3c50, `lw` at 0x3cbc.
  2 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x3c88, `lbu` at 0x3cf4.
  The `lbu` at 0x3d28 loads 1 byte from [a0+672]:8 +0x7311.
  The `sb` at 0x3d38 stores 1 byte to [a0+672]:8 +0x7311.
  The `sb` at 0x3d48 stores 1 byte to [a0+672]:8 +0x7313.
  The `jal` at 0x3bf8 calls pcibr_rrb_flush with a0=[[a0+672]:8+29468], a1=[([a0+740] + [[a0+672]:8+552]:8)], a2=[[a0+744]:8], a3=([a0+740] + [[a0+672]:8+552]:8), a4=[[a0+672]:8+552]:8.
  The `jal` at 0x3c40 calls rad_pio_writeback_subcode_tx with a0=[a0+672]:8+12128, a1=a1 at entry (arg1), a2=-0x1, a3=0x6, a4=0x7, a5=-0x2, a7=0x1.
  The `jal` at 0x3cac calls rad_stop_dma with a0=[a0+672]:8+8168, a1=a1 at entry (arg1), a2=?, a3=?, a4=0x1, a5=-0x2.
  The `jal` at 0x3d18 calls rad_stop_dma with a0=[a0+672]:8+8960, a1=a1 at entry (arg1), a2=?, a3=?, a4=0x1, a5=-0x2.
  The `jal` at 0x3d44 calls rad_pio_writeback_subcode_tx with a0=[a0+672]:8+17672, a1=a1 at entry (arg1), a2=-0x1, a3=0x6, a4=0x7, a5=-0x2.
  The `beq` branch at 0x3b88 targets 0x3c10, is taken when at(=[a0+628]:1) == 0, and falls through when at(=[a0+628]:1) != 0.
  The `beq` branch at 0x3b94 targets 0x3c24, is taken when a0(=[a0+704]) == a2(=-0x1), and falls through when a0(=[a0+704]) != a2(=-0x1).
  The `beq` branch at 0x3b9c targets 0x3d28, is taken when a0(=[a0+704]) == a5(=-0x2), and falls through when a0(=[a0+704]) != a5(=-0x2).
  The `beq` branch at 0x3ba4 targets 0x3c50, is taken when a0(=[a0+704]) == a3(=0x6), and falls through when a0(=[a0+704]) != a3(=0x6).
  The `beq` branch at 0x3bac targets 0x3cbc, is taken when a0(=[a0+704]) == a4(=0x7), and falls through when a0(=[a0+704]) != a4(=0x7).
  The `bne` branch at 0x3c30 targets 0x3c00, is taken when (a6(=[[a0+672]:8+29456]:1-1) & 0xff) != 0, and falls through when (a6(=[[a0+672]:8+29456]:1-1) & 0xff) == 0.
  The `beq` branch at 0x3c48 targets 0x3c04 and is always taken.
  The `beq` branch at 0x3c60 targets 0x3d54, is taken when t0(=[a0+568]) >= 0x20 (signed), and falls through when t0(=[a0+568]) < 0x20 (signed).
  The `beq` branch at 0x3c90 targets 0x3c9c, is taken when t1(?) == 0, and falls through when t1(?) != 0.
  The `bne` branch at 0x3c9c targets 0x3c6c, is taken when a3(?) != 0, and falls through when a3(?) == 0.
  The `bne` branch at 0x3ca4 targets 0x3bc4, is taken when a0(?) != a4(=0x1), and falls through when a0(?) == a4(=0x1).
  The `beq` branch at 0x3cb4 targets 0x3bc8 and is always taken.
  The `beq` branch at 0x3ccc targets 0x3d6c, is taken when t2(=[a0+568]) >= 0x20 (signed), and falls through when t2(=[a0+568]) < 0x20 (signed).
  The `beq` branch at 0x3cfc targets 0x3d08, is taken when t3(?) == 0, and falls through when t3(?) != 0.
  The `bne` branch at 0x3d08 targets 0x3cd8, is taken when a3(?) != 0, and falls through when a3(?) == 0.
  The `bne` branch at 0x3d10 targets 0x3bc4, is taken when a0(?) != a4(=0x1), and falls through when a0(?) == a4(=0x1).
  The `beq` branch at 0x3d20 targets 0x3bc8 and is always taken.
  The `bne` branch at 0x3d34 targets 0x3c00, is taken when (t8(=[[a0+672]:8+29457]:1-1) & 0xff) != 0, and falls through when (t8(=[[a0+672]:8+29457]:1-1) & 0xff) == 0.
  The `beq` branch at 0x3d4c targets 0x3c04 and is always taken.
  The `beq` branch at 0x3d64 targets 0x3bc4 and is always taken.
  The `beq` branch at 0x3d7c targets 0x3bc4 and is always taken.
  The return at 0x3c1c has v0 = ?.

- `rad_mclk_update_cg` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x3d84 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x3d84-0x3e8c (264 bytes).
  It occupies 264 bytes.
  The `ld` at 0x3d9c loads 8 bytes from a0 (arg0 at entry) +0x1f0.
  The `ld` at 0x3db8 loads 8 bytes from a0 (arg0 at entry) +0x1c8.
  The `lw` at 0x3dbc loads 4 bytes from [a0+456]:8 +0x128.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x21c, including `lw` at 0x3dd0, `lw` at 0x3e30.
  The `sw` at 0x3de4 stores 4 bytes to a0 (arg0 at entry) +0x21c.
  The `ld` at 0x3dec loads 8 bytes from [a0+496]:8 +0x228.
  The `sw` at 0x3e04 stores 4 bytes to [[a0+496]:8+552]:8 +0xa0.
  The `ld` at 0x3e1c loads 8 bytes from a0 (arg0 at entry) +0x1a0.
  The `jal` at 0x3d98 calls kdsp_mclk_update_cg with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `bne` branch at 0x3db0 targets 0x3e08, is taken when s0(=a0) != at(=[a0+496]:8+26240), and falls through when s0(=a0) == at(=[a0+496]:8+26240).
  The `beq` branch at 0x3dc0 targets 0x3dd0, is taken when a1(=[[a0+456]:8+296]) == a4(=0x2000000b), and falls through when a1(=[[a0+456]:8+296]) != a4(=0x2000000b).
  The `bne` branch at 0x3dc8 targets 0x3e18, is taken when a1(=[[a0+456]:8+296]) != a3(=0x2000000c), and falls through when a1(=[[a0+456]:8+296]) == a3(=0x2000000c).
  The `beq` branch at 0x3dd8 targets 0x3e08, is taken when a2(=[a0+540]) == a1(=0x3), and falls through when a2(=[a0+540]) != a1(=0x3).
  The `beq` branch at 0x3e34 targets 0x3e4c, is taken when a4(=0x72d800000000) >= a5(=[a0+416]:8) (signed), and falls through when a4(=0x72d800000000) < a5(=[a0+416]:8) (signed).
  The `beq` branch at 0x3e3c targets 0x3e08, is taken when a2(=[a0+540]) == a1(=0x3), and falls through when a2(=[a0+540]) != a1(=0x3).
  The `beq` branch at 0x3e44 targets 0x3de4 and is always taken.
  The `beq` branch at 0x3e5c targets 0x3e74, is taken when a7(=0x396c00000000) >= a5(=[a0+416]:8) (signed), and falls through when a7(=0x396c00000000) < a5(=[a0+416]:8) (signed).
  The `beq` branch at 0x3e64 targets 0x3e08, is taken when a2(=[a0+540]) == a1(=0x6), and falls through when a2(=[a0+540]) != a1(=0x6).
  The `beq` branch at 0x3e6c targets 0x3de4 and is always taken.
  The `beq` branch at 0x3e7c targets 0x3e08, is taken when a2(=[a0+540]) == a1(=one of 0xc, 0x18), and falls through when a2(=[a0+540]) != a1(=one of 0xc, 0x18).
  The `beq` branch at 0x3e84 targets 0x3de4 and is always taken.
  The return at 0x3e10 has v0 = ret(kdsp_mclk_update_cg).

- `rad_check_adat_rx` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x3e8c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x3e8c-0x4010 (388 bytes).
  It occupies 388 bytes.
  3 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x7309, including `lbu` at 0x3e8c, `lbu` at 0x3edc, `lbu` at 0x400c.
  The `lbu` at 0x3ebc loads 1 byte from a0 (arg0 at entry) +0x730a.
  2 such `sh` accesses store 2 bytes to a0 (arg0 at entry) +0x730c, including `sh` at 0x3ec8, `sh` at 0x3f04.
  2 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x730b, including `sb` at 0x3ecc, `sb` at 0x3f10.
  The `lbu` at 0x3ed0 loads 1 byte from a0 (arg0 at entry) +0x730b.
  The `sb` at 0x3ee0 stores 1 byte to a0 (arg0 at entry) +0x730a.
  The `lhu` at 0x3ef0 loads 2 bytes from a0 (arg0 at entry) +0x730c.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x2c0, including `lw` at 0x3f1c, `lw` at 0x3f40, `lw` at 0x3f84.
  3 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x800, including `sb` at 0x3f2c, `sb` at 0x3fbc, `sb` at 0x3fd0.
  4 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x7309, including `sb` at 0x3f30, `sb` at 0x3f7c, `sb` at 0x3fc8.
  3 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x1ccc, including `sw` at 0x3f3c, `sw` at 0x3fb8, `sw` at 0x3fd4.
  5 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x228, including `ld` at 0x3f50, `ld` at 0x3f64, `ld` at 0x3fa4.
  5 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x7240, including `lw` at 0x3f54, `lw` at 0x3f60, `lw` at 0x3f9c.
  5 such `sw` accesses store 4 bytes to [a0+552]:8 +0x80, including `sw` at 0x3f5c, `sw` at 0x3f70, `sw` at 0x3fb0.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x7240, including `sw` at 0x3f6c, `sw` at 0x3fac.
  The `lw` at 0x3f80 loads 4 bytes from a0 (arg0 at entry) +0x72f0.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x1cc8, including `sw` at 0x3fb4, `sw` at 0x3fe0.
  The `jal` at 0x3f0c calls kdsp_update_mclk_users with a0=a0+1624, a1=?, a2=?, a3=?, a4=0x1, a5=0x1f4.
  The `beq` branch at 0x3ea4 targets 0x3f1c, is taken when a4(=0x1) == a2(=[a0+29449]:1), and falls through when a4(=0x1) != a2(=[a0+29449]:1).
  The `beq` branch at 0x3eac targets 0x3f40, is taken when a2(=[a0+29449]:1) == 0, and falls through when a2(=[a0+29449]:1) != 0.
  The `beq` branch at 0x3eb4 targets 0x3f80, is taken when a2(=[a0+29449]:1) == a3(=0x2), and falls through when a2(=[a0+29449]:1) != a3(=0x2).
  The `beq` branch at 0x3ec0 targets 0x3ed0, is taken when at(=[a0+29450]:1) == a2(?), and falls through when at(=[a0+29450]:1) != a2(?).
  The `beq` branch at 0x3ed4 targets 0x3ef0, is taken when v0(=[a0+29451]:1) == 0, and falls through when v0(=[a0+29451]:1) != 0.
  The `bne` branch at 0x3f00 targets 0x3edc, is taken when (a0(=[a0+29452]:2-1) & 0xffff) != 0, and falls through when (a0(=[a0+29452]:2-1) & 0xffff) == 0.
  The `beq` branch at 0x3f14 targets 0x3edc and is always taken.
  The `beq` branch at 0x3f24 targets 0x3ebc, is taken when (a1(=[a0+704]) & 0x40) == 0, and falls through when (a1(=[a0+704]) & 0x40) != 0.
  The `beq` branch at 0x3f38 targets 0x3ebc and is always taken.
  The `beq` branch at 0x3f48 targets 0x3fcc, is taken when (a2(=[a0+704]) & 0x40) == 0, and falls through when (a2(=[a0+704]) & 0x40) != 0.
  The `beq` branch at 0x3f78 targets 0x3ebc and is always taken.
  The `beq` branch at 0x3f8c targets 0x3fe4, is taken when (a1(=[a0+29424]) & 0x3ff) == 0, and falls through when (a1(=[a0+29424]) & 0x3ff) != 0.
  The `bne` branch at 0x3f94 targets 0x3ebc, is taken when a0(?) != 0, and falls through when a0(?) == 0.
  The `beq` branch at 0x3fc4 targets 0x3ebc and is always taken.
  The `beq` branch at 0x3fdc targets 0x3ebc and is always taken.
  The `beq` branch at 0x3fe4 targets 0x3f9c, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x4008 targets 0x3ebc and is always taken.
  The return at 0x3ee8 has v0 = one of [a0+29451]:1, ret(kdsp_update_mclk_users).

- `rad_update_dev` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x4010 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x4010-0x4624 (1556 bytes).
  It occupies 1556 bytes.
  The `ld` at 0x4018 loads 8 bytes from a0 (arg0 at entry) +0x2a0.
  The `lbu` at 0x4024 loads 1 byte from a0 (arg0 at entry) +0x274.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x268, including `lw` at 0x403c, `lw` at 0x4224.
  2 such `lbu` accesses load 1 byte from [a0+672]:8 +0x730f, including `lbu` at 0x4058, `lbu` at 0x4388.
  8 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x2c0, including `lw` at 0x4068, `lw` at 0x4084, `lw` at 0x4088.
  2 such `lbu` accesses load 1 byte from [a0+672]:8 +0x730e, including `lbu` at 0x4074, `lbu` at 0x44b0.
  The `lw` at 0x40a0 loads 4 bytes from a0 (arg0 at entry) +0x1e4.
  The `lw` at 0x40a4 loads 4 bytes from a0 (arg0 at entry) +0x1d4.
  3 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x1b8, including `ld` at 0x40ac, `ld` at 0x43e0, `ld` at 0x450c.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x2f8, including `ld` at 0x40c4, `ld` at 0x4384.
  The `lw` at 0x40cc loads 4 bytes from [a0+760]:8 +0x0.
  The `lw` at 0x40e0 loads 4 bytes from [a0+672]:8 +0x7320.
  The `ld` at 0x4108 loads 8 bytes from a0 (arg0 at entry) +0x300.
  The `lw` at 0x410c loads 4 bytes from [a0+768]:8 +0x0.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x308, including `ld` at 0x4114, `ld` at 0x41ac.
  The `lw` at 0x4124 loads 4 bytes from a0 (arg0 at entry) +0x310.
  2 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x308, including `sd` at 0x4148, `sd` at 0x41dc.
  The `lw` at 0x4154 loads 4 bytes from [a0+672]:8 +0x2b8.
  The `lh` at 0x4178 loads 2 bytes from table(sym(.data)) +0x0.
  The `ld` at 0x417c loads 8 bytes from [a0+672]:8 +0x228.
  The `lh` at 0x4188 loads 2 bytes from table(sym(.data)) +0x2.
  The `lw` at 0x418c loads 4 bytes from ([[a0+672]:8+552]:8 + (entry(sym(.data)) << 0x2)) -0x40.
  The `lw` at 0x4190 loads 4 bytes from table(sym(.data)) +0x4.
  The `ld` at 0x41f0 loads 8 bytes from [a0+672]:8 +0x72a8.
  4 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x1b0, including `sd` at 0x41fc, `sd` at 0x4374, `sd` at 0x43ac.
  4 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x2c4, including `lw` at 0x4218, `lw` at 0x42a0, `lw` at 0x4344.
  5 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x264, including `sw` at 0x4220, `sw` at 0x4398, `sw` at 0x4418.
  10 such `lw` accesses load 4 bytes from ?, including `lw` at 0x4240, `lw` at 0x42e8, `lw` at 0x43b0.
  7 such `sw` accesses store 4 bytes to ?, including `sw` at 0x424c, `sw` at 0x42f4, `sw` at 0x43bc.
  The `sw` at 0x4258 stores 4 bytes to a0 (arg0 at entry) +0x2c4.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x220, including `lw` at 0x425c, `lw` at 0x45f4, `lw` at 0x4618.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x23c, including `lw` at 0x4264, `lw` at 0x43e4, `lw` at 0x4510.
  The `ld` at 0x4268 loads 8 bytes from a0 (arg0 at entry) +0x1a8.
  3 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x1a8, including `sd` at 0x4274, `sd` at 0x43a0, `sd` at 0x44c8.
  The `lw` at 0x42d4 loads 4 bytes from a0 (arg0 at entry) +0x238.
  The `lbu` at 0x4300 loads 1 byte from [a0+672]:8 +0x7309.
  The `ld` at 0x4348 loads 8 bytes from a0 (arg0 at entry) +0x1b0.
  2 such `lw` accesses load 4 bytes from [a0+672]:8 +0x2564, including `lw` at 0x4394, `lw` at 0x45e0.
  The `ld` at 0x439c loads 8 bytes from [a0+672]:8 +0x24a8.
  The `ld` at 0x43a4 loads 8 bytes from [a0+672]:8 +0x24b0.
  2 such `lw` accesses load 4 bytes from [a0+440]:8 +0x4, including `lw` at 0x43ec, `lw` at 0x4518.
  3 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x1c8, including `ld` at 0x4400, `ld` at 0x44ec, `ld` at 0x4614.
  8 such `ld` accesses load 8 bytes from ?, including `ld` at 0x4460, `ld` at 0x4470, `ld` at 0x4494.
  4 such `sd` accesses store 8 bytes to ?, including `sd` at 0x44a0, `sd` at 0x45c4, `sd` at 0x4604.
  The `sb` at 0x44ac stores 1 byte to [a0+672]:8 +0x730f.
  2 such `lw` accesses load 4 bytes from [a0+672]:8 +0x224c, including `lw` at 0x44bc, `lw` at 0x45f0.
  The `ld` at 0x44c4 loads 8 bytes from [a0+672]:8 +0x2190.
  The `ld` at 0x44cc loads 8 bytes from [a0+672]:8 +0x2198.
  The `sb` at 0x45d0 stores 1 byte to [a0+672]:8 +0x730e.
  The `jal` at 0x4150 calls rad_sync_device_ust with a0=a0 at entry (arg0), a1=[[a0+672]:8+696], a2=?, a3=0x3ffff, a4=-0x4000.
  The `jal` at 0x419c calls update_ust with a0=?, a1=?, a2=?, a3=[table(sym(.data))+2]:2.
  The `jal` at 0x41a4 calls get_ust_nano with a0=sp-80, a1=?, a2=?, a3=?.
  The `jal` at 0x4328 calls kdsp_update_default_subcode with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x4378 calls rad_check_adat_rx with a0=[a0+672]:8, a1=?, a2=[a0+704], a3=?, a5=0x4, a6=[a0+440]:8.
  The `jal` at 0x440c calls rad_prepare_adat_in_subcode with a0=[a0+672]:8, a1=?, a2=?, a3=?, a4=[a0+572].
  The `jal` at 0x4438 calls kdsp_update_default_subcode with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x4530 calls rad_prepare_aes_in_subcode with a0=[a0+672]:8, a1=?, a2=?, a3=?, a4=[a0+456]:8, a5=[a0+572].
  The `jal` at 0x455c calls kdsp_update_default_subcode with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x45d4 calls rad_update_dev with a0=[a0+672]:8+8960, a1=0x7, a2=[a0+704], a3=[a0+672]:8+8168, a4=0x6, a5=[[a0+672]:8+29455]:1.
  The `jal` at 0x45e4 calls rad_update_dev with a0=[a0+672]:8+8168, a1=0x7, a2=[a0+704], a3=[a0+672]:8+8168, a4=[[a0+672]:8+29454]:1.
  The `beq` branch at 0x4034 targets 0x4278, is taken when at(=[a0+628]:1) == 0, and falls through when at(=[a0+628]:1) != 0.
  The `beq` branch at 0x4044 targets 0x4298, is taken when (v0(=[a0+616]) & 0x400) == 0, and falls through when (v0(=[a0+616]) & 0x400) != 0.
  The `bne` branch at 0x4050 targets 0x406c, is taken when a0(=[a0+672]:8+8960) != s0(=a0), and falls through when a0(=[a0+672]:8+8960) == s0(=a0).
  The `bne` branch at 0x405c targets 0x427c, is taken when v1(=[[a0+672]:8+29455]:1) != 0, and falls through when v1(=[[a0+672]:8+29455]:1) == 0.
  The `beq` branch at 0x4064 targets 0x40a0 and is always taken.
  The `bne` branch at 0x406c targets 0x4088, is taken when a3(=[a0+672]:8+8168) != s0(=a0), and falls through when a3(=[a0+672]:8+8168) == s0(=a0).
  The `bne` branch at 0x4078 targets 0x427c, is taken when a0(=[[a0+672]:8+29454]:1) != 0, and falls through when a0(=[[a0+672]:8+29454]:1) == 0.
  The `beq` branch at 0x4080 targets 0x40a0 and is always taken.
  The `beq` branch at 0x4090 targets 0x4388, is taken when a2(=[a0+704]) == a1(=0x7), and falls through when a2(=[a0+704]) != a1(=0x7).
  The `beq` branch at 0x4098 targets 0x44b0, is taken when a2(=[a0+704]) == a4(=0x6), and falls through when a2(=[a0+704]) != a4(=0x6).
  The `beq` branch at 0x40b0 targets 0x4378, is taken when a2(=[a0+704]) == a5(=0x4), and falls through when a2(=[a0+704]) != a5(=0x4).
  The `beq` branch at 0x40bc targets 0x4378, is taken when a2(=[a0+704]) == a7(=0x7), and falls through when a2(=[a0+704]) != a7(=0x7).
  The `bne` branch at 0x40d8 targets 0x4160, is taken when t1(=[sym(.sbss)+4]) != 0, and falls through when t1(=[sym(.sbss)+4]) == 0.
  The `beq` branch at 0x40e8 targets 0x4160, is taken when a0(=[[a0+672]:8+29472]) == t8(=0x37), and falls through when a0(=[[a0+672]:8+29472]) != t8(=0x37).
  The `beq` branch at 0x40f0 targets 0x4160, is taken when a0(=[[a0+672]:8+29472]) == t9(=0x38), and falls through when a0(=[[a0+672]:8+29472]) != t9(=0x38).
  The `beq` branch at 0x40f8 targets 0x4160, is taken when a0(=[[a0+672]:8+29472]) == ra(=0x51), and falls through when a0(=[[a0+672]:8+29472]) != ra(=0x51).
  The `beq` branch at 0x4100 targets 0x4160, is taken when a0(=[[a0+672]:8+29472]) == at(=0x45), and falls through when a0(=[[a0+672]:8+29472]) != at(=0x45).
  The `beq` branch at 0x4144 targets 0x4348, is taken when v1(=[a0+784]) == 0, and falls through when v1(=[a0+784]) != 0.
  The `beq` branch at 0x4158 targets 0x4204 and is always taken.
  The `beq` branch at 0x4208 targets 0x42a0, is taken when a0(=[a0+704]) == a2(=0x6), and falls through when a0(=[a0+704]) != a2(=0x6).
  The `beq` branch at 0x4210 targets 0x4300, is taken when a0(=[a0+704]) == t1(=0x7), and falls through when a0(=[a0+704]) != t1(=0x7).
  The `beq` branch at 0x421c targets 0x4278, is taken when a0(=[a0+708]) == s2(?), and falls through when a0(=[a0+708]) != s2(?).
  The `beq` branch at 0x422c targets 0x42b8, is taken when (a0(=[a0+616]) & 0x1) == 0, and falls through when (a0(=[a0+616]) & 0x1) != 0.
  The `bgez` branch at 0x4254 targets 0x4264, is taken when s3(?) >= 0 (signed), and falls through when s3(?) < 0 (signed).
  The `beq` branch at 0x4298 targets 0x40a0 and is always taken.
  The `bltz` branch at 0x42a8 targets 0x44d8, is taken when a2(?) < 0 (signed), and falls through when a2(?) >= 0 (signed).
  The `beq` branch at 0x42b0 targets 0x421c and is always taken.
  The `beq` branch at 0x42cc targets 0x43b0, is taken when (a0(=[a0+616]) & 0x400) == 0, and falls through when (a0(=[a0+616]) & 0x400) != 0.
  The `beq` branch at 0x42dc targets 0x43b0, is taken when a6(=[a0+568]) >= 0x20 (signed), and falls through when a6(=[a0+568]) < 0x20 (signed).
  The `beq` branch at 0x42f8 targets 0x4254 and is always taken.
  The `beq` branch at 0x4308 targets 0x4218, is taken when ra(=[[a0+672]:8+29449]:1) == at(=0x1), and falls through when ra(=[[a0+672]:8+29449]:1) != at(=0x1).
  The `bne` branch at 0x4338 targets 0x4314, is taken when s3(?) < 0x4 (signed), and falls through when s3(?) >= 0x4 (signed).
  The `beq` branch at 0x4340 targets 0x421c and is always taken.
  The `beq` branch at 0x4370 targets 0x4200 and is always taken.
  The `beq` branch at 0x4380 targets 0x40c8 and is always taken.
  The `beq` branch at 0x438c targets 0x45d4, is taken when a5(=[[a0+672]:8+29455]:1) == 0, and falls through when a5(=[[a0+672]:8+29455]:1) != 0.
  The `beq` branch at 0x43a8 targets 0x4278 and is always taken.
  The `beq` branch at 0x43cc targets 0x44e4, is taken when a0(=[a0+704]) == t9(=0x6), and falls through when a0(=[a0+704]) != t9(=0x6).
  The `bne` branch at 0x43d8 targets 0x4254, is taken when a0(=[a0+704]) != t8(=0x7), and falls through when a0(=[a0+704]) == t8(=0x7).
  The `bltz` branch at 0x43f8 targets 0x4618, is taken when a2(?) < 0 (signed), and falls through when a2(?) >= 0 (signed).
  The `bne` branch at 0x4480 targets 0x4490, is taken when a2(?) < a3(?) (signed), and falls through when a2(?) >= a3(?) (signed).
  The `bne` branch at 0x449c targets 0x4420, is taken when s4(?) < 0x4 (signed), and falls through when s4(?) >= 0x4 (signed).
  The `beq` branch at 0x44a8 targets 0x4254 and is always taken.
  The `beq` branch at 0x44b4 targets 0x45e4, is taken when a4(=[[a0+672]:8+29454]:1) == 0, and falls through when a4(=[[a0+672]:8+29454]:1) != 0.
  The `beq` branch at 0x44d0 targets 0x4278 and is always taken.
  The `beq` branch at 0x44dc targets 0x42ac and is always taken.
  The `beq` branch at 0x4504 targets 0x4600, is taken when (t1(?) & 0x1) == 0, and falls through when (t1(?) & 0x1) != 0.
  The `bltz` branch at 0x4524 targets 0x45f4, is taken when a2(?) < 0 (signed), and falls through when a2(?) >= 0 (signed).
  The `bne` branch at 0x45a8 targets 0x45b4, is taken when a2(?) < a4(?) (signed), and falls through when a2(?) >= a4(?) (signed).
  The `bne` branch at 0x45c0 targets 0x4544, is taken when s4(?) < 0x3 (signed), and falls through when s4(?) >= 0x3 (signed).
  The `beq` branch at 0x45cc targets 0x4254 and is always taken.
  The `beq` branch at 0x45dc targets 0x4398 and is always taken.
  The `beq` branch at 0x45ec targets 0x44c0 and is always taken.
  The `beq` branch at 0x45f8 targets 0x4528 and is always taken.
  The `beq` branch at 0x4610 targets 0x450c and is always taken.
  The `beq` branch at 0x461c targets 0x4400 and is always taken.
  The return at 0x4290 has v0 = ?.

- `rad_update_subcode_tx_dev` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x4624 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x4624-0x47a8 (388 bytes).
  It occupies 388 bytes.
  The `lbu` at 0x4624 loads 1 byte from a0 (arg0 at entry) +0x274.
  The `ld` at 0x462c loads 8 bytes from a0 (arg0 at entry) +0x2a0.
  The `ld` at 0x463c loads 8 bytes from a0 (arg0 at entry) +0x1b0.
  The `ld` at 0x4644 loads 8 bytes from a0 (arg0 at entry) +0x300.
  The `lw` at 0x4650 loads 4 bytes from [a0+768]:8 +0x0.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x1a8, including `ld` at 0x4668, `ld` at 0x4728.
  The `lw` at 0x4680 loads 4 bytes from a0 (arg0 at entry) +0x2c0.
  The `ld` at 0x4694 loads 8 bytes from a0 (arg0 at entry) +0x1b8.
  2 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x1a8, including `sd` at 0x46a8, `sd` at 0x4734.
  The `lwu` at 0x46ac loads 4 bytes from [a0+672]:8 +0x2a4.
  3 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x1b0, including `sd` at 0x46c8, `sd` at 0x472c, `sd` at 0x475c.
  The `lw` at 0x46cc loads 4 bytes from [a0+672]:8 +0x723c.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x238, including `lw` at 0x46e0, `lw` at 0x4760.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x264, including `sw` at 0x46ec, `sw` at 0x4794.
  The `lw` at 0x46f8 loads 4 bytes from [a0+440]:8 +0x0.
  2 such `sw` accesses store 4 bytes to [a0+440]:8 +0x0, including `sw` at 0x4700, `sw` at 0x471c.
  The `lw` at 0x4704 loads 4 bytes from a0 (arg0 at entry) +0x220.
  The `sd` at 0x4720 stores 8 bytes to a0 (arg0 at entry) +0x308.
  The `sw` at 0x4724 stores 4 bytes to a0 (arg0 at entry) +0x2c4.
  The `lwu` at 0x4740 loads 4 bytes from [a0+672]:8 +0x2ac.
  The `lw` at 0x4764 loads 4 bytes from [a0+672]:8 +0x7238.
  The `beq` branch at 0x4630 targets 0x4738, is taken when at(=[a0+628]:1) == 0, and falls through when at(=[a0+628]:1) != 0.
  The `beq` branch at 0x46a4 targets 0x4740, is taken when a3(=[a0+704]) == t3(=-0x1), and falls through when a3(=[a0+704]) != t3(=-0x1).
  The `beq` branch at 0x46c4 targets 0x4760, is taken when a3(=[a0+704]) == t3(=-0x1), and falls through when a3(=[a0+704]) != t3(=-0x1).
  The `beq` branch at 0x46dc targets 0x4798, is taken when a3(?) == t0(=0x2), and falls through when a3(?) != t0(=0x2).
  The `beq` branch at 0x46e4 targets 0x4798, is taken when a3(?) == t2(=0x1), and falls through when a3(?) != t2(=0x1).
  The `beq` branch at 0x46f0 targets 0x4738, is taken when a2(=one of 0x0, 0x1, 0x6) == 0, and falls through when a2(=one of 0x0, 0x1, 0x6) != 0.
  The `bne` branch at 0x4714 targets 0x4720, is taken when a6(?) < t2(=[a0+544]) (signed), and falls through when a6(?) >= t2(=[a0+544]) (signed).
  The `bne` branch at 0x4758 targets 0x46cc, is taken when a3(=[a0+704]) != t3(=-0x1), and falls through when a3(=[a0+704]) == t3(=-0x1).
  The `beq` branch at 0x4780 targets 0x47a0, is taken when a3(?) == t2(=0x2), and falls through when a3(?) != t2(=0x2).
  The `beq` branch at 0x4788 targets 0x47a0, is taken when a3(?) == a6(=0x1), and falls through when a3(?) != a6(=0x1).
  The `beq` branch at 0x4790 targets 0x46f0 and is always taken.
  The `beq` branch at 0x4798 targets 0x46ec and is always taken.
  The `beq` branch at 0x47a0 targets 0x4790 and is always taken.
  The return at 0x4738 has v0 = ?.

- `rad_pio_writeback_subcode_tx` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x47a8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x47a8-0x4b68 (960 bytes).
  It occupies 960 bytes.
  The `lw` at 0x47a8 loads 4 bytes from a0 (arg0 at entry) +0x230.
  The `lw` at 0x47b0 loads 4 bytes from a0 (arg0 at entry) +0x2c0.
  The `ld` at 0x47bc loads 8 bytes from a0 (arg0 at entry) +0x2a0.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x1b8, including `ld` at 0x47d0, `ld` at 0x48d4.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x22c, including `lw` at 0x47d4, `lw` at 0x48d8.
  2 such `lw` accesses load 4 bytes from [a0+440]:8 +0x4, including `lw` at 0x47d8, `lw` at 0x48dc.
  2 such `lw` accesses load 4 bytes from [a0+440]:8 +0x0, including `lw` at 0x47f0, `lw` at 0x48f4.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x1c8, including `ld` at 0x47f4, `ld` at 0x48f8.
  24 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x4850, `lbu` at 0x4854, `lbu` at 0x4864.
  4 such `sb` accesses store 1 byte to ?, including `sb` at 0x486c, `sb` at 0x4874, `sb` at 0x4894.
  The `lbu` at 0x48a8 loads 1 byte from [a0+672]:8 +0x7313.
  The `sb` at 0x48b8 stores 1 byte to [a0+672]:8 +0x7313.
  2 such `sw` accesses store 4 bytes to ?, including `sw` at 0x499c, `sw` at 0x49f4.
  The `lbu` at 0x49f8 loads 1 byte from [a0+672]:8 +0x7312.
  The `sb` at 0x4a08 stores 1 byte to [a0+672]:8 +0x7312.
  The `lbu` at 0x4a1c loads 1 byte from [a0+672]:8 +0x7310.
  The `lw` at 0x4a20 loads 4 bytes from [a0+672]:8 +0x7238.
  2 such `lbu` accesses load 1 byte from [a0+672]:8 +0x7314, including `lbu` at 0x4a50, `lbu` at 0x4b58.
  3 such `sb` accesses store 1 byte to [a0+672]:8 +0x7314, including `sb` at 0x4a54, `sb` at 0x4b3c, `sb` at 0x4b5c.
  3 such `sb` accesses store 1 byte to [a0+672]:8 +0x7315, including `sb` at 0x4a5c, `sb` at 0x4b44, `sb` at 0x4b64.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x220, including `lw` at 0x4a60, `lw` at 0x4ac4.
  The `lbu` at 0x4a7c loads 1 byte from [a0+672]:8 +0x7311.
  The `lw` at 0x4a80 loads 4 bytes from [a0+672]:8 +0x723c.
  2 such `lbu` accesses load 1 byte from [a0+672]:8 +0x7316, including `lbu` at 0x4ab4, `lbu` at 0x4b0c.
  3 such `sb` accesses store 1 byte to [a0+672]:8 +0x7316, including `sb` at 0x4ab8, `sb` at 0x4af0, `sb` at 0x4b10.
  3 such `sb` accesses store 1 byte to [a0+672]:8 +0x7317, including `sb` at 0x4ac0, `sb` at 0x4af8, `sb` at 0x4b18.
  The `jal` at 0x4a14 calls rad_prepare_aes_out_subcode with a0=[a0+672]:8, a1=[a0+672]:8+29000, a2=?, a3=?.
  The `jal` at 0x4a48 calls rad_write_aes_out_subcode with a0=[a0+672]:8, a1=0x1180, a2=[a0+672]:8+29000, a3=?.
  The `jal` at 0x4a74 calls rad_prepare_adat_out_subcode with a0=[a0+672]:8, a1=[a0+672]:8+29144, a2=?, a3=?.
  The `jal` at 0x4aac calls rad_write_adat_out_subcode with a0=[a0+672]:8, a1=0x1080, a2=[a0+672]:8+29144, a3=?, a4=0x2, a5=0x1.
  The `jal` at 0x4ad8 calls rad_write_adat_out_subcode with a0=[a0+672]:8, a1=0x1000, a2=[a0+672]:8+29144, a3=?, a4=0x2, a5=0x1.
  The `jal` at 0x4ae8 calls rad_write_adat_out_subcode with a0=[a0+672]:8, a1=0x1080, a2=[a0+672]:8+29144, a3=?.
  The `jal` at 0x4b04 calls rad_write_adat_out_subcode with a0=[a0+672]:8, a1=0x1000, a2=[a0+672]:8+29144, a3=?, a4=0x2, a5=0x1.
  The `jal` at 0x4b24 calls rad_write_aes_out_subcode with a0=[a0+672]:8, a1=0x1100, a2=[a0+672]:8+29000, a3=?.
  The `jal` at 0x4b34 calls rad_write_aes_out_subcode with a0=[a0+672]:8, a1=0x1180, a2=[a0+672]:8+29000, a3=?.
  The `jal` at 0x4b50 calls rad_write_aes_out_subcode with a0=[a0+672]:8, a1=0x1100, a2=[a0+672]:8+29000, a3=?.
  The `beq` branch at 0x47c0 targets 0x48cc, is taken when at(=[a0+704]) == v0(=-0x1), and falls through when at(=[a0+704]) != v0(=-0x1).
  The `beq` branch at 0x47c8 targets 0x48a8, is taken when a1(=[a0+560]) == 0, and falls through when a1(=[a0+560]) != 0.
  The `bltz` branch at 0x47e0 targets 0x4a60, is taken when a2(?) < 0 (signed), and falls through when a2(?) >= 0 (signed).
  The `blez` branch at 0x47e8 targets 0x48a8, is taken when a1(?) <= 0 (signed), and falls through when a1(?) > 0 (signed).
  The `beq` branch at 0x4830 targets 0x4840, is taken when a0 == a7(?), and falls through when a0 != a7(?).
  The `bne` branch at 0x4838 targets 0x4808, is taken when a4(?) != 0, and falls through when a4(?) == 0.
  The `bne` branch at 0x48a0 targets 0x4848, is taken when a0(?) < 0x6 (signed), and falls through when a0(?) >= 0x6 (signed).
  The `blez` branch at 0x48b4 targets 0x4a6c, is taken when t1(?) <= 0 (signed), and falls through when t1(?) > 0 (signed).
  The `beq` branch at 0x48cc targets 0x49f8, is taken when a1(=[a0+560]) == 0, and falls through when a1(=[a0+560]) != 0.
  The `bltz` branch at 0x48e4 targets 0x4ac4, is taken when a2(?) < 0 (signed), and falls through when a2(?) >= 0 (signed).
  The `blez` branch at 0x48ec targets 0x49f8, is taken when a1(?) <= 0 (signed), and falls through when a1(?) > 0 (signed).
  The `beq` branch at 0x4930 targets 0x4940, is taken when a0 == a7(?), and falls through when a0 != a7(?).
  The `bne` branch at 0x4938 targets 0x4908, is taken when a4(?) != 0, and falls through when a4(?) == 0.
  The `bne` branch at 0x49f0 targets 0x4948, is taken when a0(?) < 0x6 (signed), and falls through when a0(?) >= 0x6 (signed).
  The `bgtz` branch at 0x4a04 targets 0x48bc, is taken when t8(?) > 0 (signed), and falls through when t8(?) <= 0 (signed).
  The `beq` branch at 0x4a28 targets 0x4b1c, is taken when a1(=[[a0+672]:8+29456]:1) == 0, and falls through when a1(=[[a0+672]:8+29456]:1) != 0.
  The `beq` branch at 0x4a34 targets 0x4b48, is taken when a0(?) == a1(=0x2), and falls through when a0(?) != a1(=0x2).
  The `bne` branch at 0x4a3c targets 0x48bc, is taken when a0(?) != a2(=0x1), and falls through when a0(?) == a2(=0x1).
  The `beq` branch at 0x4a58 targets 0x48bc and is always taken.
  The `beq` branch at 0x4a64 targets 0x47e8 and is always taken.
  The `beq` branch at 0x4a90 targets 0x4ad0, is taken when a1(=[[a0+672]:8+29457]:1) == 0, and falls through when a1(=[[a0+672]:8+29457]:1) != 0.
  The `beq` branch at 0x4a98 targets 0x4afc, is taken when a0(?) == a4(=0x2), and falls through when a0(?) != a4(=0x2).
  The `bne` branch at 0x4aa0 targets 0x48bc, is taken when a0(?) != a5(=0x1), and falls through when a0(?) == a5(=0x1).
  The `beq` branch at 0x4abc targets 0x48bc and is always taken.
  The `beq` branch at 0x4ac8 targets 0x48ec and is always taken.
  The `beq` branch at 0x4af4 targets 0x48bc and is always taken.
  The `beq` branch at 0x4b14 targets 0x48bc and is always taken.
  The `beq` branch at 0x4b40 targets 0x48bc and is always taken.
  The `beq` branch at 0x4b60 targets 0x48bc and is always taken.
  The return at 0x48c4 has v0 = one of -0x1, ret(rad_prepare_aes_out_subcode), ret(rad_write_aes_out_subcode), ret(rad_prepare_adat_out_subcode), ret(rad_write_adat_out_subcode).

- `rad_pre_connect` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x4b68 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x4b68-0x4b70 (8 bytes).
  It occupies 8 bytes.
  The return at 0x4b68 has v0 = 0x0.

- `rad_set_clockgen` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x4b70 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x4b70-0x4e24 (692 bytes).
  It occupies 692 bytes.
  The `ld` at 0x4b7c loads 8 bytes from a0 (arg0 at entry) +0x1f0.
  The `lw` at 0x4b8c loads 4 bytes from a0 (arg0 at entry) +0x1f8.
  The `sd` at 0x4bc0 stores 8 bytes to a0 (arg0 at entry) +0x200.
  The `lw` at 0x4bc4 loads 4 bytes from a0 (arg0 at entry) +0x20c.
  9 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x208, including `lw` at 0x4be0, `lw` at 0x4c4c, `lw` at 0x4c98.
  The `lw` at 0x4bf4 loads 4 bytes from ([a0+496]:8 + ([a0+520] << 0x2)) +0x72cc.
  3 such `lh` accesses load 2 bytes from [a0+496]:8 +0x21a, including `lh` at 0x4c0c, `lh` at 0x4c80, `lh` at 0x4d64.
  2 such `lw` accesses load 4 bytes from [a0+496]:8 +0x7240, including `lw` at 0x4c20, `lw` at 0x4d48.
  5 such `ld` accesses load 8 bytes from [a0+496]:8 +0x228, including `ld` at 0x4c2c, `ld` at 0x4c5c, `ld` at 0x4cc0.
  2 such `sw` accesses store 4 bytes to [a0+496]:8 +0x7240, including `sw` at 0x4c38, `sw` at 0x4d5c.
  2 such `sw` accesses store 4 bytes to [[a0+496]:8+552]:8 +0x80, including `sw` at 0x4c44, `sw` at 0x4d60.
  The `ld` at 0x4c50 loads 8 bytes from a0 (arg0 at entry) +0x200.
  The `lwu` at 0x4c60 loads 4 bytes from (sym(.rodata) + ([a0+520] << 0x2)) +0x0.
  The `lw` at 0x4c64 loads 4 bytes from [a0+512]:8 +0x1b4.
  The `sw` at 0x4c70 stores 4 bytes to ([(sym(.rodata) + ([a0+520] << 0x2))] + [[a0+496]:8+552]:8) +0x0.
  The `sw` at 0x4c74 stores 4 bytes to a0 (arg0 at entry) +0x218.
  The `sw` at 0x4c78 stores 4 bytes to a0 (arg0 at entry) +0x214.
  The `sw` at 0x4c7c stores 4 bytes to a0 (arg0 at entry) +0x210.
  The `sw` at 0x4cb4 stores 4 bytes to ([a0+496]:8 + ([a0+520] << 0x2)) +0x7288.
  The `lw` at 0x4cc8 loads 4 bytes from ([a0+496]:8 + ([a0+520] << 0x2)) +0x7288.
  The `sw` at 0x4ccc stores 4 bytes to [[a0+496]:8+552]:8 +0xa4.
  3 such `lw` accesses load 4 bytes from ([a0+496]:8 + ([a0+520] << 0x2)) +0x7278, including `lw` at 0x4cdc, `lw` at 0x4d14, `lw` at 0x4d38.
  2 such `sw` accesses store 4 bytes to ([a0+496]:8 + ([a0+520] << 0x2)) +0x7278, including `sw` at 0x4ce4, `sw` at 0x4d24.
  The `sw` at 0x4d3c stores 4 bytes to [[a0+496]:8+552]:8 +0xa0.
  2 such `lbu` accesses load 1 byte from [a0+496]:8 +0x7302, including `lbu` at 0x4d7c, `lbu` at 0x4db0.
  2 such `lw` accesses load 4 bytes from [a0+496]:8 +0x7274, including `lw` at 0x4dbc, `lw` at 0x4e08.
  2 such `sw` accesses store 4 bytes to [a0+496]:8 +0x7274, including `sw` at 0x4dd0, `sw` at 0x4e18.
  The `jal` at 0x4dcc calls rad_vl_write_MUX_SEL with a0=[a0+496]:8, a1=?, a2=-0x2001, a3=0x7, a4=0x1, a5=[a0+520]+8.
  The `jal` at 0x4dd4 calls us_delay with a0=0xfa, a1=?, a2=?, a3=?.
  The `jal` at 0x4df4 calls rad_vl_set_clockgen with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0xd, a3=0x7, a4=0x1.
  The `jal` at 0x4e14 calls rad_vl_write_MUX_SEL with a0=[a0+496]:8, a1=([[a0+496]:8+29300] | 0x2000), a2=[[a0+496]:8+552]:8, a3=0x7, a4=0x1, a5=([a0+496]:8 + ([a0+520] << 0x2)), a6=[a0+496]:8+26240, a7=[[a0+496]:8+29442]:1.
  The `bltz` branch at 0x4bac targets 0x4d84, is taken when at(=[a0+504]) < 0 (signed), and falls through when at(=[a0+504]) >= 0 (signed).
  The `beq` branch at 0x4bb4 targets 0x4bc4, is taken when a1 == 0, and falls through when a1 != 0.
  The `beq` branch at 0x4bc8 targets 0x4d84, is taken when v0(=[a0+524]) == 0, and falls through when v0(=[a0+524]) != 0.
  The `bne` branch at 0x4c04 targets 0x4d84, is taken when (v1(=[([a0+496]:8 + ([a0+520] << 0x2))+29388]) & a2(?)) != 0, and falls through when (v1(=[([a0+496]:8 + ([a0+520] << 0x2))+29388]) & a2(?)) == 0.
  The `beq` branch at 0x4c14 targets 0x4da8, is taken when a2(=[[a0+496]:8+538]:2) == a3(=0x7), and falls through when a2(=[[a0+496]:8+538]:2) != a3(=0x7).
  The `beq` branch at 0x4c40 targets 0x4c74, is taken when a0(=one of 0x0, 0x1) == 0, and falls through when a0(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x4c84 targets 0x4df0, is taken when a0(=[[a0+496]:8+538]:2) == a3(=0x7), and falls through when a0(=[[a0+496]:8+538]:2) != a3(=0x7).
  The `beq` branch at 0x4c8c targets 0x4df0, is taken when a0(=[[a0+496]:8+538]:2) == a2(=0xd), and falls through when a0(=[[a0+496]:8+538]:2) != a2(=0xd).
  The `bne` branch at 0x4d68 targets 0x4d84, is taken when t1(=[[a0+496]:8+538]:2) != a3(=0x7), and falls through when t1(=[[a0+496]:8+538]:2) == a3(=0x7).
  The `bne` branch at 0x4d74 targets 0x4d88, is taken when s0(=a0) != a6(=[a0+496]:8+26240), and falls through when s0(=a0) == a6(=[a0+496]:8+26240).
  The `beq` branch at 0x4d80 targets 0x4e08, is taken when a7(=[[a0+496]:8+29442]:1) == 0, and falls through when a7(=[[a0+496]:8+29442]:1) != 0.
  The `bne` branch at 0x4da8 targets 0x4c20, is taken when s0(=a0) != a2(=[a0+496]:8+26240), and falls through when s0(=a0) == a2(=[a0+496]:8+26240).
  The `bne` branch at 0x4db4 targets 0x4c1c, is taken when t0(=[[a0+496]:8+29442]:1) != 0, and falls through when t0(=[[a0+496]:8+29442]:1) == 0.
  The `beq` branch at 0x4de8 targets 0x4c1c and is always taken.
  The `beq` branch at 0x4e00 targets 0x4c90 and is always taken.
  The `beq` branch at 0x4e1c targets 0x4d88 and is always taken.
  The return at 0x4da0 has v0 = one of ?, ret(rad_vl_write_MUX_SEL).

- `rad_get_hw_mscust` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x4e24 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x4e24-0x4e58 (52 bytes).
  It occupies 52 bytes.
  The `ld` at 0x4e24 loads 8 bytes from a0 (arg0 at entry) +0x308.
  The `lw` at 0x4e28 loads 4 bytes from a0 (arg0 at entry) +0x258.
  The `ld` at 0x4e2c loads 8 bytes from a0 (arg0 at entry) +0x2a0.
  The `sd` at 0x4e34 stores 8 bytes to a1 (arg1 at entry) +0x0.
  The `ld` at 0x4e38 loads 8 bytes from a0 (arg0 at entry) +0x1b0.
  The `ld` at 0x4e3c loads 8 bytes from [a0+672]:8 +0x72a8.
  The `sd` at 0x4e54 stores 8 bytes to a2 (arg2 at entry) +0x0.
  The return at 0x4e50 has v0 = [sym(.sbss)].

- `rad_start_clockgen` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x4e58 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x4e58-0x4e8c (52 bytes).
  It occupies 52 bytes.
  The `lw` at 0x4e58 loads 4 bytes from a0 (arg0 at entry) +0x20c.
  The `ld` at 0x4e64 loads 8 bytes from a0 (arg0 at entry) +0x1f0.
  The `lw` at 0x4e68 loads 4 bytes from a0 (arg0 at entry) +0x208.
  The `lw` at 0x4e70 loads 4 bytes from [a0+496]:8 +0x7240.
  The `sw` at 0x4e80 stores 4 bytes to [a0+496]:8 +0x7240.
  The `beq` branch at 0x4e60 targets 0x4e84, is taken when at(=[a0+524]) == 0, and falls through when at(=[a0+524]) != 0.
  The return at 0x4e84 has v0 = ?.

- `rad_shutdown` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x4e8c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x4e8c-0x4ea8 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x4e94 calls kdsp_idbg_rad_delfuncs with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x4ea0 has v0 = ret(kdsp_idbg_rad_delfuncs).

- `rad_halt_intr_ops` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x4ea8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x4ea8-0x4ed0 (40 bytes).
  It occupies 40 bytes.
  The `sw` at 0x4ec0 stores 4 bytes to a0 (arg0 at entry) +0x72c8.
  The `jal` at 0x4eb4 calls rad_stop_status_dma with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x4ec8 has v0 = ret(rad_stop_status_dma).

- `rad_one_shot_status` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x4ed0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x4ed0-0x4fb4 (228 bytes).
  It occupies 228 bytes.
  3 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x7c, including `lw` at 0x4ee4, `lw` at 0x4f40, `lw` at 0x4f84.
  The `sw` at 0x4f04 stores 4 bytes to a1 (arg1 at entry) +0x7c.
  4 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x228, including `ld` at 0x4f08, `ld` at 0x4f14, `ld` at 0x4f1c.
  The `sw` at 0x4f10 stores 4 bytes to [a0+552]:8 +0x504.
  The `sw` at 0x4f18 stores 4 bytes to [a0+552]:8 +0x500.
  The `sw` at 0x4f24 stores 4 bytes to [a0+552]:8 +0x528.
  The `sw` at 0x4f3c stores 4 bytes to [a0+552]:8 +0x5c.
  The `jal` at 0x4f00 calls Mem_to_PCI_DMA with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0x1000, a3=a3 at entry (arg3).
  The `jal` at 0x4f38 calls us_delay with a0=0x5, a1=[a0+552]:8, a2=[a0+552]:8, a3=-0x4, a4=[a0+552]:8.
  The `jal` at 0x4f7c calls us_delay with a0=0x5, a1=?, a2=?, a3=?.
  The `jal` at 0x4fa4 calls debug with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `beq` branch at 0x4f4c targets 0x4f6c, is taken when (v0(=0xffffffff80000000) & a5(=[a1+124])) == 0, and falls through when (v0(=0xffffffff80000000) & a5(=[a1+124])) != 0.
  The `beq` branch at 0x4f6c targets 0x4f7c and is always taken.
  The `blez` branch at 0x4f74 targets 0x4f98, is taken when s0(?) <= 0 (signed), and falls through when s0(?) > 0 (signed).
  The `beq` branch at 0x4f90 targets 0x4f74, is taken when (v0(=0xffffffff80000000) & a6(=[a1+124])) == 0, and falls through when (v0(=0xffffffff80000000) & a6(=[a1+124])) != 0.
  The `bne` branch at 0x4f98 targets 0x4f58, is taken when s0(?) != 0, and falls through when s0(?) == 0.
  The `beq` branch at 0x4fac targets 0x4f58 and is always taken.
  The return at 0x4f64 has v0 = one of 0x0, 0x1.

- `rad_attach` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x4fb4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x4fb4-0x5068 (180 bytes).
  It occupies 180 bytes.
  The `jal` at 0x4fd4 calls pciio_piotrans_addr with a0=a0 at entry (arg0), a1=0x0, a2=0x7, a3=0x0, a4=0x20, a5=0x0.
  The `jal` at 0x4ff4 calls pciio_piotrans_addr with a0=a0 at entry (arg0), a1=0x0, a2=0x8, a3=0x0, a4=0x2000, a5=0x0.
  The `jal` at 0x5008 calls pciio_config_get with a0=a0 at entry (arg0), a1=0x8, a2=0x4, a3=?.
  The `jal` at 0x5028 calls pciio_priority_set with a0=a0 at entry (arg0), a1=0x2, a2=?, a3=?.
  The `jal` at 0x503c calls pciio_priority_set with a0=a0 at entry (arg0), a1=0x1, a2=?, a3=?.
  The `jal` at 0x504c calls rad_create_subsys with a0=ret(pciio_piotrans_addr), a1=ret(pciio_piotrans_addr), a2=a0 at entry (arg0), a3=?.
  The `bne` branch at 0x5020 targets 0x5038, is taken when at(?) != v0(=0xc), and falls through when at(?) == v0(=0xc).
  The `beq` branch at 0x5030 targets 0x5044 and is always taken.
  The return at 0x5060 has v0 = 0x0.

- `rad_detach` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x5068 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x5068-0x5070 (8 bytes).
  It occupies 8 bytes.
  The return at 0x5068 has v0 = 0x0.

- `rad_error` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x5070 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x5070-0x5078 (8 bytes).
  It occupies 8 bytes.
  The return at 0x5070 has v0 = 0x0.

- `rad_error_handler` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x5078 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x5078-0x5110 (152 bytes).
  It occupies 152 bytes.
  4 such `ld` accesses load 8 bytes from a3 (arg3 at entry) +0x28, including `ld` at 0x50cc, `ld` at 0x50d0, `ld` at 0x50fc.
  The `lw` at 0x50dc loads 4 bytes from a0 (arg0 at entry) +0x731c.
  The `jal` at 0x50e0 calls cmn_err with a0=0x4, a1=sym(.rodata), a2=[a0+29468], a3=sym(.rodata), a4=a1 at entry (arg1), a5=a2 at entry (arg2), a6=[a3+40]:8, a7=0x6.
  The `beq` branch at 0x50a4 targets 0x50d0, is taken when a1 == at(=0x5), and falls through when a1 != at(=0x5).
  The `beq` branch at 0x50ac targets 0x50f8, is taken when a1 == a7(=0x6), and falls through when a1 != a7(=0x6).
  The `beq` branch at 0x50b4 targets 0x5100, is taken when a1 == t3(=0x9), and falls through when a1 != t3(=0x9).
  The `beq` branch at 0x50bc targets 0x5108, is taken when a1 == t8(=0xa), and falls through when a1 != t8(=0xa).
  The `beq` branch at 0x50c8 targets 0x50d4 and is always taken.
  The `beq` branch at 0x50f8 targets 0x50d4 and is always taken.
  The `beq` branch at 0x5100 targets 0x50d0 and is always taken.
  The `beq` branch at 0x5108 targets 0x50d4 and is always taken.
  The return at 0x50f0 has v0 = 0x9.

- `rad_init` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x5110 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x5110-0x515c (76 bytes).
  It occupies 76 bytes.
  The `ld` at 0x5118 loads 8 bytes from abs 0x9000000014000000.
  The `jal` at 0x5140 calls pciio_driver_register with a0=0x10a9, a1=0x5, a2=sym(.rodata), a3=0x0.
  The `jal` at 0x5148 calls kdsp_idbg_rad_addfuncs with a0=?, a1=?, a2=?, a3=?.
  The return at 0x5154 has v0 = ret(kdsp_idbg_rad_addfuncs).

- `rad_halt` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x515c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x515c-0x5238 (220 bytes).
  It occupies 220 bytes.
  4 such `ld` accesses load 8 bytes from ?, including `ld` at 0x5184, `ld` at 0x51bc, `ld` at 0x51e4.
  3 such `lh` accesses load 2 bytes from ?, including `lh` at 0x51a8, `lh` at 0x51cc, `lh` at 0x5234.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0x51b8, `lw` at 0x5218.
  6 such `sw` accesses store 4 bytes to ?, including `sw` at 0x51c4, `sw` at 0x51c8, `sw` at 0x51ec.
  The `jal` at 0x517c calls rad_stop_status_dma with a0=?, a1=?, a2=?, a3=?, a5=0xc.
  The `jal` at 0x5198 calls strncmp with a0=?, a1=sym(.rodata), a2=0x3, a3=?.
  The `jal` at 0x5204 calls us_delay with a0=0xc8, a1=?, a2=?, a3=?.
  The `jal` at 0x5228 calls rad_vl_write_MUX_SEL with a0=?, a1=?, a2=?, a3=?, a4=0x7, a5=0xc.
  The `beq` branch at 0x516c targets 0x5200, is taken when at(=[sym(kdsp_sstab)]:8) == 0, and falls through when at(=[sym(kdsp_sstab)]:8) != 0.
  The `beq` branch at 0x5174 targets 0x5190 and is always taken.
  The `beq` branch at 0x5188 targets 0x5200, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `bne` branch at 0x51a0 targets 0x5184, is taken when v0(=ret(strncmp)) != 0, and falls through when v0(=ret(strncmp)) == 0.
  The `beq` branch at 0x51b0 targets 0x51d4, is taken when a0(?) == a2(=0xd), and falls through when a0(?) != a2(=0xd).
  The `beq` branch at 0x51d4 targets 0x5218, is taken when a0(?) == a4(=0x7), and falls through when a0(?) != a4(=0x7).
  The `bne` branch at 0x51dc targets 0x517c, is taken when a0(?) != a5(=0xc), and falls through when a0(?) == a5(=0xc).
  The `beq` branch at 0x51f8 targets 0x517c and is always taken.
  The `beq` branch at 0x5230 targets 0x51d8 and is always taken.
  The return at 0x5210 has v0 = ret(us_delay).

- `Mem_to_PCI_DMA` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x5238 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x5238-0x527c (68 bytes).
  It occupies 68 bytes.
  The `lw` at 0x5260 loads 4 bytes from a0 (arg0 at entry) +0x731c.
  The `jal` at 0x524c calls kvtophys with a0=a1 at entry (arg1), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x5264 calls pciio_dmatrans_addr with a0=[a0+29468], a1=0x0, a2=ret(kvtophys), a3=a2 at entry (arg2), a4=0x50.
  The return at 0x5274 has v0 = ret(pciio_dmatrans_addr).

- `rad_initial_val` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x527c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x527c-0x54f0 (628 bytes).
  It occupies 628 bytes.
  The `lw` at 0x527c loads 4 bytes from a1 (arg1 at entry) +0x0.
  The `ld` at 0x52a4 loads 8 bytes from a0 (arg0 at entry) +0x118.
  The `ld` at 0x52b0 loads 8 bytes from (sym(.rodata) + ([a1]+0xffffffffeffffffe << 0x3)) +0x0.
  Calls (unknown callee) via register with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a4=[a0+280]:8, a5=(sym(.rodata) + ([a1]+0xffffffffeffffffe << 0x3)), a6=([a1]+0xffffffffeffffffe << 0x3) (`jr` at 0x52b4).
  The `beq` branch at 0x52a8 targets 0x52c0, is taken when a6(=[a1]+0xffffffffeffffffe) >= 0x34 (unsigned), and falls through when a6(=[a1]+0xffffffffeffffffe) < 0x34 (unsigned).
  The return at 0x52c0 has v0 = 0x0.
  The instructions from 0x52bc to 0x52bc are not reached by any path from the entry, and their branches are not listed.
  The instructions from 0x52c8 to 0x54ec are not reached by any path from the entry, and their branches are not listed.
  The indirect jump at 0x52b4 uses a jump table whose successors are unresolved.

- `rad_set_device_params` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x54f0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x54f0-0x589c (940 bytes).
  It occupies 940 bytes.
  The `lw` at 0x54f4 loads 4 bytes from a1 (arg1 at entry) +0x0.
  The `ld` at 0x5528 loads 8 bytes from a0 (arg0 at entry) +0x2a0.
  The `ld` at 0x5534 loads 8 bytes from (sym(.rodata) + ([a1]+0xffffffffeffffffe << 0x3)) +0x0.
  Calls (unknown callee) via register with a0=[(sym(.rodata) + ([a1]+0xffffffffeffffffe << 0x3))]:8, a1=?, a2=a2 at entry (arg2), a3=a3 at entry (arg3), a5=[a1] (`jr` at 0x5538).
  The `beq` branch at 0x552c targets 0x5540, is taken when v1(=[a1]+0xffffffffeffffffe) >= 0x34 (unsigned), and falls through when v1(=[a1]+0xffffffffeffffffe) < 0x34 (unsigned).
  The return at 0x5550 has v0 = 0x0.
  The instructions from 0x5558 to 0x5898 are not reached by any path from the entry, and their branches are not listed.
  The indirect jump at 0x5538 uses a jump table whose successors are unresolved.

- `rad_commit_device_params` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x589c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x589c-0x58a4 (8 bytes).
  It occupies 8 bytes.
  The return at 0x589c has v0 = ?.

- `rad_calculate_rate_frac` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x58a4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x58a4-0x5a1c (376 bytes).
  It occupies 376 bytes.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x1a0, including `ld` at 0x58a4, `ld` at 0x59d4.
  The `ld` at 0x58b0 loads 8 bytes from a0 (arg0 at entry) +0x200.
  The `ld` at 0x58b4 loads 8 bytes from a0 (arg0 at entry) +0x1f0.
  2 such `ld` accesses load 8 bytes from [a0+512]:8 +0x198, including `ld` at 0x58d0, `ld` at 0x58e8.
  2 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x1a0, including `sd` at 0x58e0, `sd` at 0x592c.
  The `ld` at 0x593c loads 8 bytes from [a0+496]:8 +0x630.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x220, including `lw` at 0x5954, `lw` at 0x59f4.
  3 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x1b0, including `sw` at 0x5958, `sw` at 0x5990, `sw` at 0x59f8.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x1b8, including `sw` at 0x5968, `sw` at 0x5a04.
  2 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x200, including `sd` at 0x5974, `sd` at 0x5a10.
  The `lw` at 0x5978 loads 4 bytes from a0 (arg0 at entry) +0x1b8.
  The `lw` at 0x597c loads 4 bytes from a0 (arg0 at entry) +0x1b0.
  The `ld` at 0x59c8 loads 8 bytes from [a0+496]:8 +0x470.
  The `jal` at 0x58f8 calls kdsp_reduce_frac with a0=?, a1=[[a0+512]:8+408]:8, a2=a0+432, a3=a0+440, a4=0xffff.
  The `jal` at 0x5940 calls kdsp_reduce_frac with a0=?, a1=[[a0+496]:8+1584]:8, a2=sp-48, a3=sp-44, a4=0xffff.
  The `jal` at 0x59b0 calls kdsp_reduce_frac with a0=?, a1=[a0+440], a2=a0+432, a3=a0+440, a4=0xffff, a6=[a0+416]:8.
  The `jal` at 0x59d0 calls kdsp_reduce_frac with a0=[a0+416]:8, a1=[[a0+496]:8+1136]:8, a2=sp-40, a3=sp-36, a4=0xffff.
  The `beq` branch at 0x58c0 targets 0x5914, is taken when a3(=[a0+512]:8) == 0, and falls through when a3(=[a0+512]:8) != 0.
  The `beq` branch at 0x58c8 targets 0x5978, is taken when a6(=[a0+416]:8) == 0, and falls through when a6(=[a0+416]:8) != 0.
  The `beq` branch at 0x58d8 targets 0x58ec, is taken when a0(=[[a0+512]:8+408]:8) >= a6(=[a0+416]:8) (signed), and falls through when a0(=[[a0+512]:8+408]:8) < a6(=[a0+416]:8) (signed).
  The `beq` branch at 0x5920 targets 0x5930, is taken when a0(=0xbb8000000000) >= a6(=[a0+416]:8) (signed), and falls through when a0(=0xbb8000000000) < a6(=[a0+416]:8) (signed).
  The `bne` branch at 0x594c targets 0x59c0, is taken when s0(=a0) != a1(=[a0+496]:8+26240), and falls through when s0(=a0) == a1(=[a0+496]:8+26240).
  The `beq` branch at 0x5964 targets 0x5970, is taken when a3(=[a0+544]) == 0, and falls through when a3(=[a0+544]) != 0.
  The `beq` branch at 0x5970 targets 0x5900 and is always taken.
  The `beq` branch at 0x5984 targets 0x5994, is taken when a1(=[a0+440]) >= a0(=[a0+432]) (signed), and falls through when a1(=[a0+440]) < a0(=[a0+432]) (signed).
  The `bne` branch at 0x5998 targets 0x59a8, is taken when a4(=0xffff) < a0(?) (signed), and falls through when a4(=0xffff) >= a0(?) (signed).
  The `beq` branch at 0x59a0 targets 0x5904, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0x59b8 targets 0x5904 and is always taken.
  The `beq` branch at 0x59d8 targets 0x5954, is taken when v0(=ret(kdsp_reduce_frac)) == 0, and falls through when v0(=ret(kdsp_reduce_frac)) != 0.
  The `beq` branch at 0x59ec targets 0x5954, is taken when a1(?) >= a0(?) (signed), and falls through when a1(?) < a0(?) (signed).
  The `beq` branch at 0x5a00 targets 0x5a14, is taken when t0(=[a0+544]) == 0, and falls through when t0(=[a0+544]) != 0.
  The `beq` branch at 0x5a0c targets 0x5900 and is always taken.
  The `beq` branch at 0x5a14 targets 0x5a0c and is always taken.
  The return at 0x590c has v0 = one of ret(kdsp_reduce_frac), ?.

- `rad_cg_update_dev` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x5a1c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x5a1c-0x5b08 (236 bytes).
  It occupies 236 bytes.
  The `ld` at 0x5a24 loads 8 bytes from a0 (arg0 at entry) +0x1f0.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x2e8, including `ld` at 0x5a28, `ld` at 0x5a60.
  The `lw` at 0x5a2c loads 4 bytes from [a0+496]:8 +0x1b8.
  The `ld` at 0x5a30 loads 8 bytes from a0 (arg0 at entry) +0x2a0.
  2 such `lw` accesses load 4 bytes from [a0+744]:8 +0x0, including `lw` at 0x5a3c, `lw` at 0x5a74.
  The `lw` at 0x5a48 loads 4 bytes from [a0+496]:8 +0x208.
  The `sw` at 0x5a5c stores 4 bytes to [a0+744]:8 +0x0.
  The `ld` at 0x5a64 loads 8 bytes from [a0+672]:8 +0x228.
  The `lwu` at 0x5a68 loads 4 bytes from a0 (arg0 at entry) +0x2e4.
  The `sw` at 0x5a7c stores 4 bytes to ([a0+740] + [[a0+672]:8+552]:8) +0x0.
  The `ld` at 0x5a90 loads 8 bytes from [a0+496]:8 +0x1a0.
  The `lw` at 0x5a9c loads 4 bytes from [a0+672]:8 +0x230.
  The `lbu` at 0x5aa0 loads 1 byte from [a0+672]:8 +0x7314.
  The `sb` at 0x5aac stores 1 byte to [a0+672]:8 +0x7314.
  The `sb` at 0x5ab4 stores 1 byte to [a0+672]:8 +0x7312.
  The `sb` at 0x5ac0 stores 1 byte to [a0+672]:8 +0x7310.
  The `lw` at 0x5acc loads 4 bytes from [a0+496]:8 +0x1b0.
  The `ld` at 0x5ad8 loads 8 bytes from [a0+496]:8 +0x200.
  The `lw` at 0x5adc loads 4 bytes from [[a0+496]:8+512]:8 +0x1b4.
  The `jal` at 0x5a94 calls kdsp_set_aes_rate_bits with a0=[a0+672]:8+20944, a1=[[a0+496]:8+416]:8, a2=?, a3=[a0+496]:8, a4=0x1fffffff, a5=[[a0+744]:8], a6=[a0+744]:8, a7=0x1fff0000.
  The `jal` at 0x5abc calls rad_pio_writeback_subcode_tx with a0=[a0+672]:8+12128, a1=?, a2=?, a3=?.
  The `beq` branch at 0x5a44 targets 0x5acc, is taken when at(=[[a0+496]:8+440]) == t1(=0x1), and falls through when at(=[[a0+496]:8+440]) != t1(=0x1).
  The `beq` branch at 0x5a78 targets 0x5a90, is taken when a0 == v0(=[a0+672]:8+5792), and falls through when a0 != v0(=[a0+672]:8+5792).
  The `bne` branch at 0x5aa8 targets 0x5a80, is taken when t9(=[[a0+672]:8+560]) != 0, and falls through when t9(=[[a0+672]:8+560]) == 0.
  The `beq` branch at 0x5ac4 targets 0x5a84 and is always taken.
  The `bne` branch at 0x5ad0 targets 0x5a50, is taken when at(=[[a0+496]:8+432]) != t1(=0x1), and falls through when at(=[[a0+496]:8+432]) == t1(=0x1).
  The `beq` branch at 0x5af0 targets 0x5b00, is taken when t3(?) == t8(=0x2), and falls through when t3(?) != t8(=0x2).
  The `beq` branch at 0x5af8 targets 0x5a4c and is always taken.
  The `beq` branch at 0x5b00 targets 0x5a4c and is always taken.
  The return at 0x5a88 has v0 = one of ?, ret(rad_pio_writeback_subcode_tx).

- `rad_get_cg_id` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x5b08 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x5b08-0x5c7c (372 bytes).
  It occupies 372 bytes.
  The `ld` at 0x5b08 loads 8 bytes from a0 (arg0 at entry) +0x1f0.
  The `lh` at 0x5b18 loads 2 bytes from [a0+496]:8 +0x21a.
  The `lw` at 0x5b38 loads 4 bytes from a0 (arg0 at entry) +0x208.
  The `ll` at 0x5b5c loads 4 bytes from ([a0+496]:8 + ([a0+520] << 0x2)) +0x72cc.
  The `sc` at 0x5b64 stores 4 bytes to ([a0+496]:8 + ([a0+520] << 0x2)) +0x72cc.
  The `ld` at 0x5b70 loads 8 bytes from a0 (arg0 at entry) +0x200.
  4 such `lw` accesses load 4 bytes from ?, including `lw` at 0x5b8c, `lw` at 0x5c48, `lw` at 0x5c54.
  The `ll` at 0x5bbc loads 4 bytes from ?.
  The `sc` at 0x5bc4 stores 4 bytes to ?.
  The `sw` at 0x5bd0 stores 4 bytes to a0 (arg0 at entry) +0x208.
  The `lw` at 0x5be4 loads 4 bytes from a0 (arg0 at entry) +0x1b8.
  The `lw` at 0x5bf0 loads 4 bytes from a0 (arg0 at entry) +0x1b0.
  The `ld` at 0x5c34 loads 8 bytes from ?.
  The `beq` branch at 0x5b2c targets 0x5bd4, is taken when a6(=[[a0+496]:8+538]:2) == t1(=0xd), and falls through when a6(=[[a0+496]:8+538]:2) != t1(=0xd).
  The `beql` branch at 0x5b68 targets 0x5b5c, is taken when (t3(=[([a0+496]:8 + ([a0+520] << 0x2))+29388]) & t9(?)) == 0, and falls through when (t3(=[([a0+496]:8 + ([a0+520] << 0x2))+29388]) & t9(?)) != 0; its branch-likely delay slot `nop` at 0x5b6c runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x5b74 targets 0x5bdc, is taken when a4(=[a0+512]:8) == t2(=[a0+496]:8+2968), and falls through when a4(=[a0+512]:8) != t2(=[a0+496]:8+2968).
  The `beq` branch at 0x5b7c targets 0x5bdc, is taken when a4(=[a0+512]:8) == t0(=[a0+496]:8+2520), and falls through when a4(=[a0+512]:8) != t0(=[a0+496]:8+2520).
  The `beq` branch at 0x5b90 targets 0x5bb0, is taken when t9(?) == 0, and falls through when t9(?) != 0.
  The `bne` branch at 0x5ba4 targets 0x5b8c, is taken when a2(?) < 0x4 (signed), and falls through when a2(?) >= 0x4 (signed).
  The `beql` branch at 0x5bc8 targets 0x5bbc, is taken when a1(?) == 0, and falls through when a1(?) != 0; its branch-likely delay slot `nop` at 0x5bcc runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x5bdc targets 0x5b84, is taken when a0 == a7(=[a0+496]:8+26240), and falls through when a0 != a7(=[a0+496]:8+26240).
  The `bne` branch at 0x5be8 targets 0x5b84, is taken when a1(=[a0+440]) != t1(=0x1), and falls through when a1(=[a0+440]) == t1(=0x1).
  The `bne` branch at 0x5bf4 targets 0x5b84, is taken when a2(=[a0+432]) != t1(=0x1), and falls through when a2(=[a0+432]) == t1(=0x1).
  The `beq` branch at 0x5bfc targets 0x5c10 and is always taken.
  The `beq` branch at 0x5c0c targets 0x5c68, is taken when a2(?) >= 0x6 (signed), and falls through when a2(?) < 0x6 (signed).
  The `beq` branch at 0x5c2c targets 0x5c04, is taken when a0 == a7(?), and falls through when a0 != a7(?).
  The `bne` branch at 0x5c38 targets 0x5c04, is taken when a7(?) != a4(=[a0+512]:8), and falls through when a7(?) == a4(=[a0+512]:8).
  The `beq` branch at 0x5c40 targets 0x5c04, is taken when a2(?) == t1(=0x1), and falls through when a2(?) != t1(=0x1).
  The `bne` branch at 0x5c4c targets 0x5c04, is taken when t0(?) != t1(=0x1), and falls through when t0(?) == t1(=0x1).
  The `bnel` branch at 0x5c58 targets 0x5c08, is taken when t2(?) != t1(=0x1), and falls through when t2(?) == t1(=0x1); its branch-likely delay slot `addiu a2,a2,1` at 0x5c5c runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x5c6c targets 0x5b84, is taken when a2(?) == t8(=0x6), and falls through when a2(?) != t8(=0x6).
  The `beq` branch at 0x5c74 targets 0x5bb0 and is always taken.
  The return at 0x5bd4 has v0 = ?.

- `rad_commit_clockgen_params` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x5c7c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x5c7c-0x5d8c (272 bytes).
  It occupies 272 bytes.
  The `lw` at 0x5c7c loads 4 bytes from a0 (arg0 at entry) +0x224.
  The `sd` at 0x5ca8 stores 8 bytes to a0 (arg0 at entry) +0x200.
  3 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x200, including `ld` at 0x5cbc, `ld` at 0x5d0c, `ld` at 0x5d58.
  The `ld` at 0x5cc8 loads 8 bytes from a0 (arg0 at entry) +0x1c8.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x1b0, including `lw` at 0x5ce0, `lw` at 0x5cf4.
  The `ld` at 0x5ce4 loads 8 bytes from a0 (arg0 at entry) +0x198.
  The `lw` at 0x5d00 loads 4 bytes from a0 (arg0 at entry) +0x1b8.
  The `lw` at 0x5d10 loads 4 bytes from [a0+512]:8 +0x1b8.
  The `jal` at 0x5cac calls rad_calculate_rate_frac with a0=a0 at entry (arg0), a1=[a0+548], a2=0x20000016, a3=a3 at entry (arg3).
  The `jal` at 0x5cb4 calls rad_get_cg_id with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x5cd4 calls kdsp_select_mclk with a0=a0 at entry (arg0), a1=[a0+512]:8, a2=?, a3=[a0+456]:8.
  The `jalr` at 0x5cec calls (unknown callee) with a0=a0 at entry (arg0), a1=0x0, a2=?, a3=?, a4=[a0+408]:8.
  The `jal` at 0x5d50 calls kdsp_reduce_frac with a0=?, a1=[a0+432], a2=sp-32, a3=sp-28, a4=0xffff, a7=[[a0+512]:8+440].
  The `jal` at 0x5d6c calls rad_set_clockgen with a0=a0 at entry (arg0), a1=[a0+512]:8, a2=?, a3=?, a5=0x0.
  The `jal` at 0x5d74 calls kdsp_update_cg_users with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `beq` branch at 0x5c98 targets 0x5ca8, is taken when a1(=[a0+548]) == at(=0x2000000a), and falls through when a1(=[a0+548]) != at(=0x2000000a).
  The `bne` branch at 0x5ca0 targets 0x5cac, is taken when a1(=[a0+548]) != a2(=0x20000016), and falls through when a1(=[a0+548]) == a2(=0x20000016).
  The `beq` branch at 0x5cc0 targets 0x5ce4, is taken when a1(=[a0+512]:8) == 0, and falls through when a1(=[a0+512]:8) != 0.
  The `beq` branch at 0x5ccc targets 0x5ce4, is taken when a3(=[a0+456]:8) == a1(=[a0+512]:8), and falls through when a3(=[a0+456]:8) != a1(=[a0+512]:8).
  The `beq` branch at 0x5cdc targets 0x5cf8 and is always taken.
  The `beq` branch at 0x5cf8 targets 0x5d80, is taken when a1(=[a0+432]) == 0, and falls through when a1(=[a0+432]) != 0.
  The `beq` branch at 0x5d04 targets 0x5d80, is taken when a6(=[a0+440]) == 0, and falls through when a6(=[a0+440]) != 0.
  The return at 0x5d84 has v0 = one of ?, ret(kdsp_update_cg_users).

- `rad_update_aes_mclk` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x5d8c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x5d8c-0x5dac (32 bytes).
  It occupies 32 bytes.
  The `ld` at 0x5d8c loads 8 bytes from a0 (arg0 at entry) +0x118.
  The `jal` at 0x5d98 calls rad_process_aesrx_subcode with a0=[a0+280]:8, a1=0x1, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x5da4 has v0 = ret(rad_process_aesrx_subcode).

- `rad_process_aesrx_subcode` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x5dac (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x5dac-0x5e6c (192 bytes).
  It occupies 192 bytes.
  The `lw` at 0x5dac loads 4 bytes from a0 (arg0 at entry) +0x2c4.
  The `ld` at 0x5dcc loads 8 bytes from a0 (arg0 at entry) +0x72f8.
  The `ld` at 0x5de4 loads 8 bytes from table(sym(.data)+32768) +0x0.
  2 such `lhu` accesses load 2 bytes from a0 (arg0 at entry) +0x7300, including `lhu` at 0x5df0, `lhu` at 0x5e4c.
  2 such `sh` accesses store 2 bytes to a0 (arg0 at entry) +0x7300, including `sh` at 0x5e00, `sh` at 0x5e2c.
  2 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x72f8, including `sd` at 0x5e04, `sd` at 0x5e38.
  The `lbu` at 0x5e10 loads 1 byte from a0 (arg0 at entry) +0x9c0.
  2 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x9c0, including `sb` at 0x5e34, `sb` at 0x5e54.
  The `sd` at 0x5e60 stores 8 bytes to a0 (arg0 at entry) +0x9b0.
  The `jal` at 0x5e5c calls kdsp_update_mclk_users with a0=a0+2072, a1=?, a2=?, a3=?, a5=sym(.data)+32768.
  The `bltz` branch at 0x5dd0 targets 0x5e20, is taken when a6(=([a0+708] << 0xc)) < 0 (signed), and falls through when a6(=([a0+708] << 0xc)) >= 0 (signed).
  The `bne` branch at 0x5de8 targets 0x5e2c, is taken when v0(=[a0+29432]:8) != a3(=entry(sym(.data)+32768)), and falls through when v0(=[a0+29432]:8) == a3(=entry(sym(.data)+32768)).
  The `beq` branch at 0x5df8 targets 0x5e10, is taken when v1(=[a0+29440]:2) == 0, and falls through when v1(=[a0+29440]:2) != 0.
  The `beq` branch at 0x5e08 targets 0x5e50, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x5e20 targets 0x5e44, is taken when v0(=[a0+29432]:8) == 0, and falls through when v0(=[a0+29432]:8) != 0.
  The `beq` branch at 0x5e3c targets 0x5e14 and is always taken.
  The `beq` branch at 0x5e48 targets 0x5df4 and is always taken.
  The `beq` branch at 0x5e64 targets 0x5e10 and is always taken.
  The return at 0x5e18 has v0 = one of [a0+2496]:1, 0x1.

- `rad_prepare_aes_in_subcode` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x5e6c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x5e6c-0x5f90 (292 bytes).
  It occupies 292 bytes.
  4 such `ld` accesses load 8 bytes from ?, including `ld` at 0x5e94, `ld` at 0x5e98, `ld` at 0x5eac.
  The `lw` at 0x5ea0 loads 4 bytes from ?.
  16 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x5ecc, `lbu` at 0x5ed0, `lbu` at 0x5ed4.
  4 such `sw` accesses store 4 bytes to ?, including `sw` at 0x5f1c, `sw` at 0x5f20, `sw` at 0x5f70.
  The `bne` branch at 0x5f78 targets 0x5ec4, is taken when a4(?) < 0x6 (signed), and falls through when a4(?) >= 0x6 (signed).
  The `bne` branch at 0x5f80 targets 0x5e80, is taken when t3(?) != 0, and falls through when t3(?) == 0.
  The return at 0x5f88 has v0 = ?.

- `rad_prepare_aes_out_subcode` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x5f90 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x5f90-0x60a0 (272 bytes).
  It occupies 272 bytes.
  3 such `ld` accesses load 8 bytes from ?, including `ld` at 0x5fb8, `ld` at 0x5fbc, `ld` at 0x5fd8.
  16 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x5fe4, `lbu` at 0x5fe8, `lbu` at 0x5fec.
  2 such `sw` accesses store 4 bytes to ?, including `sw` at 0x6030, `sw` at 0x6088.
  The `bne` branch at 0x5fd0 targets 0x608c, is taken when at(?) != 0, and falls through when at(?) == 0.
  The `bne` branch at 0x6084 targets 0x5fdc, is taken when a4(?) < 0x6 (signed), and falls through when a4(?) >= 0x6 (signed).
  The `bne` branch at 0x6090 targets 0x5fa8, is taken when t1(?) != 0, and falls through when t1(?) == 0.
  The return at 0x6098 has v0 = ?.

- `rad_prepare_adat_in_subcode` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x60a0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x60a0-0x6178 (216 bytes).
  It occupies 216 bytes.
  4 such `ld` accesses load 8 bytes from ?, including `ld` at 0x60c4, `ld` at 0x60c8, `ld` at 0x60d8.
  The `lw` at 0x60cc loads 4 bytes from ?.
  9 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x60f4, `lbu` at 0x60f8, `lbu` at 0x6108.
  5 such `sb` accesses store 1 byte to ?, including `sb` at 0x6110, `sb` at 0x6118, `sb` at 0x6138.
  The `bne` branch at 0x6144 targets 0x60ec, is taken when a3(?) < 0x6 (signed), and falls through when a3(?) >= 0x6 (signed).
  The `bne` branch at 0x6168 targets 0x60bc, is taken when t0(?) < 0x4 (signed), and falls through when t0(?) >= 0x4 (signed).
  The return at 0x6170 has v0 = ?.

- `rad_prepare_adat_out_subcode` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x6178 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x6178-0x624c (212 bytes).
  It occupies 212 bytes.
  3 such `ld` accesses load 8 bytes from ?, including `ld` at 0x61a4, `ld` at 0x61a8, `ld` at 0x61b8.
  8 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x61bc, `lbu` at 0x61c0, `lbu` at 0x61c4.
  The `sw` at 0x621c stores 4 bytes to ?.
  The `bne` branch at 0x61b0 targets 0x6220, is taken when at(?) != 0, and falls through when at(?) == 0.
  The `bne` branch at 0x6218 targets 0x6204, is taken when a3(?) < 0x6 (signed), and falls through when a3(?) >= 0x6 (signed).
  The `bne` branch at 0x623c targets 0x61a4, is taken when t0(?) != 0, and falls through when t0(?) == 0.
  The return at 0x6244 has v0 = ?.

- `rad_write_aes_out_subcode` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x624c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x624c-0x63b0 (356 bytes).
  It occupies 356 bytes.
  6 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x228, including `ld` at 0x6254, `ld` at 0x6280, `ld` at 0x62d4.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0x6268, `ld` at 0x6294.
  2 such `sd` accesses store 8 bytes to ?, including `sd` at 0x6274, `sd` at 0x62a4.
  2 such `ld` accesses load 8 bytes from a2 (arg2 at entry) +0x80, including `ld` at 0x62a8, `ld` at 0x62d8.
  The `lw` at 0x62b8 loads 4 bytes from a0 (arg0 at entry) +0x5294.
  4 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x5294, including `sw` at 0x62d0, `sw` at 0x635c, `sw` at 0x6394.
  The `sd` at 0x62e0 stores 8 bytes to ([a0+552]:8 + one of 0x1200, 0x1210) +0x0.
  The `ld` at 0x62e8 loads 8 bytes from a2 (arg2 at entry) +0x88.
  The `sd` at 0x62f0 stores 8 bytes to ([a0+552]:8 + one of 0x1208, 0x1218) +0x0.
  The `ld` at 0x62f4 loads 8 bytes from a2 (arg2 at entry) +0x28.
  The `lw` at 0x6308 loads 4 bytes from a0 (arg0 at entry) +0x7258.
  4 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x7258, including `sw` at 0x6314, `sw` at 0x6330, `sw` at 0x6368.
  The `ld` at 0x6318 loads 8 bytes from a2 (arg2 at entry) +0x70.
  The `sw` at 0x6338 stores 4 bytes to [a0+552]:8 +0x54.
  The `beq` branch at 0x6278 targets 0x62a8, is taken when a5(?) >= 0x10 (signed), and falls through when a5(?) < 0x10 (signed).
  The `bne` branch at 0x62a0 targets 0x6254, is taken when a5(?) < 0x10 (signed), and falls through when a5(?) >= 0x10 (signed).
  The `beq` branch at 0x62bc targets 0x6344, is taken when a3(=[a2+128]:8) == 0, and falls through when a3(=[a2+128]:8) != 0.
  The `beq` branch at 0x62c4 targets 0x6380, is taken when a1 == a7(=0x1180), and falls through when a1 != a7(=0x1180).
  The `beq` branch at 0x6304 targets 0x6374, is taken when a6(=0xff000000) == t8(?), and falls through when a6(=0xff000000) != t8(?).
  The `beq` branch at 0x6320 targets 0x6360, is taken when a6(=0xff000000) == a3(?), and falls through when a6(=0xff000000) != a3(?).
  The `beq` branch at 0x632c targets 0x633c, is taken when a1(?) == a4(=[a0+29272]), and falls through when a1(?) != a4(=[a0+29272]).
  The `beq` branch at 0x6344 targets 0x6398, is taken when a1 == a7(=0x1180), and falls through when a1 != a7(=0x1180).
  The `bltz` branch at 0x634c targets 0x62f4, is taken when a6(=([a0+21140] << 0x2f)) < 0 (signed), and falls through when a6(=([a0+21140] << 0x2f)) >= 0 (signed).
  The `beq` branch at 0x6358 targets 0x62d4 and is always taken.
  The `beq` branch at 0x6364 targets 0x633c, is taken when a1(?) == a4(=[a0+29272]), and falls through when a1(?) != a4(=[a0+29272]).
  The `beq` branch at 0x636c targets 0x6338 and is always taken.
  The `beq` branch at 0x6378 targets 0x6318 and is always taken.
  The `beq` branch at 0x6390 targets 0x62d4 and is always taken.
  The `bne` branch at 0x639c targets 0x62f4, is taken when (a4(=[a0+21140]) & 0x8000) != 0, and falls through when (a4(=[a0+21140]) & 0x8000) == 0.
  The `beq` branch at 0x63a8 targets 0x62d4 and is always taken.
  The return at 0x633c has v0 = ?.

- `rad_write_adat_out_subcode` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x63b0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x63b0-0x6414 (100 bytes).
  It occupies 100 bytes.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x228, including `ld` at 0x63b8, `ld` at 0x63e4.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0x63cc, `ld` at 0x63f8.
  2 such `sd` accesses store 8 bytes to ?, including `sd` at 0x63d8, `sd` at 0x6408.
  The `beq` branch at 0x63dc targets 0x640c, is taken when a4(?) >= 0xf (signed), and falls through when a4(?) < 0xf (signed).
  The `bne` branch at 0x6404 targets 0x63b8, is taken when a4(?) < 0xf (signed), and falls through when a4(?) >= 0xf (signed).
  The return at 0x640c has v0 = ?.

- `rad_update_adat_mclk` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x6414 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x6414-0x6468 (84 bytes).
  It occupies 84 bytes.
  The `ld` at 0x641c loads 8 bytes from a0 (arg0 at entry) +0x118.
  The `lw` at 0x6420 loads 4 bytes from [a0+280]:8 +0x230.
  The `jal` at 0x642c calls rad_check_adat_rx with a0=[a0+280]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x6448 calls rad_start_dma with a0=[a0+280]:8+6584, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x6458 calls rad_stop_dma with a0=[a0+280]:8+6584, a1=?, a2=?, a3=?.
  The `beq` branch at 0x6424 targets 0x6444, is taken when at(=[[a0+280]:8+560]) == 0, and falls through when at(=[[a0+280]:8+560]) != 0.
  The `beq` branch at 0x6450 targets 0x642c, is taken when v0(=ret(rad_start_dma)) == 0, and falls through when v0(=ret(rad_start_dma)) != 0.
  The `beq` branch at 0x6460 targets 0x642c and is always taken.
  The return at 0x643c has v0 = ret(rad_check_adat_rx).

- `rad_get_mclk_params` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x6468 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x6468-0x6498 (48 bytes).
  It occupies 48 bytes.
  The `lw` at 0x6468 loads 4 bytes from a1 (arg1 at entry) +0x0.
  The `lw` at 0x6484 loads 4 bytes from a0 (arg0 at entry) +0x1bc.
  The `sw` at 0x648c stores 4 bytes to a1 (arg1 at entry) +0x8.
  The `beq` branch at 0x6474 targets 0x6484, is taken when at(=[a1]) == v0(=0x1000002a), and falls through when at(=[a1]) != v0(=0x1000002a).
  The return at 0x647c has v0 = 0x0.
  The return at 0x6490 has v0 = 0x1.

- `rad_set_mclk_params` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x6498 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x6498-0x6590 (248 bytes).
  It occupies 248 bytes.
  The `ld` at 0x6498 loads 8 bytes from a0 (arg0 at entry) +0x118.
  The `lw` at 0x64a0 loads 4 bytes from a1 (arg1 at entry) +0x0.
  The `lh` at 0x64c4 loads 2 bytes from [a0+280]:8 +0x21a.
  2 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x8, including `lw` at 0x64dc, `lw` at 0x64f8.
  2 such `sw` accesses store 4 bytes to [a0+280]:8 +0xd54, including `sw` at 0x64e4, `sw` at 0x6500.
  2 such `sw` accesses store 4 bytes to [a0+280]:8 +0xb94, including `sw` at 0x64ec, `sw` at 0x6504.
  2 such `lw` accesses load 4 bytes from [a0+280]:8 +0xd54, including `lw` at 0x6538, `lw` at 0x6564.
  2 such `lw` accesses load 4 bytes from [a0+280]:8 +0x7274, including `lw` at 0x653c, `lw` at 0x6568.
  2 such `sw` accesses store 4 bytes to [a0+280]:8 +0x7274, including `sw` at 0x6558, `sw` at 0x6584.
  The `jal` at 0x6554 calls rad_vl_write_MUX_SEL with a0=[a0+280]:8, a1=?, a2=?, a3=-0x101, a4=[[a0+280]:8+538]:2, a5=0xc, a6=[a0+280]:8+2520, a7=0x7.
  The `jal` at 0x6580 calls rad_vl_write_MUX_SEL with a0=[a0+280]:8, a1=?, a2=?, a3=-0x1001, a4=[[a0+280]:8+538]:2, a5=0xc, a6=[a0+280]:8+2520, a7=0x7.
  The `bne` branch at 0x64bc targets 0x6528, is taken when at(=[a1]) != v1(=0x1000002a), and falls through when at(=[a1]) == v1(=0x1000002a).
  The `beq` branch at 0x64cc targets 0x6530, is taken when a4(=[[a0+280]:8+538]:2) == a5(=0xc), and falls through when a4(=[[a0+280]:8+538]:2) != a5(=0xc).
  The `bne` branch at 0x64d4 targets 0x64f0, is taken when a0 != a6(=[a0+280]:8+2520), and falls through when a0 == a6(=[a0+280]:8+2520).
  The `beq` branch at 0x64e8 targets 0x6508 and is always taken.
  The `bne` branch at 0x64f0 targets 0x6508, is taken when a0 != t0(=[a0+280]:8+2968), and falls through when a0 == t0(=[a0+280]:8+2968).
  The `beq` branch at 0x6508 targets 0x6538, is taken when a4(=[[a0+280]:8+538]:2) == t1(=0xd), and falls through when a4(=[[a0+280]:8+538]:2) != t1(=0xd).
  The `beq` branch at 0x6510 targets 0x6564, is taken when a4(=[[a0+280]:8+538]:2) == a7(=0x7), and falls through when a4(=[[a0+280]:8+538]:2) != a7(=0x7).
  The `beq` branch at 0x6528 targets 0x651c and is always taken.
  The `beq` branch at 0x6530 targets 0x651c and is always taken.
  The `beq` branch at 0x655c targets 0x651c and is always taken.
  The `beq` branch at 0x6588 targets 0x651c and is always taken.
  The return at 0x6520 has v0 = one of 0x0, 0x1.

- `rad_set_clockgen_params` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x6590 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x6590-0x67a0 (528 bytes).
  It occupies 528 bytes.
  The `ld` at 0x6598 loads 8 bytes from a0 (arg0 at entry) +0x1f0.
  The `lw` at 0x65c4 loads 4 bytes from a1 (arg1 at entry) +0x0.
  4 such `sh` accesses store 2 bytes to a1 (arg1 at entry) +0x14, including `sh` at 0x6608, `sh` at 0x6734, `sh` at 0x6794.
  3 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x224, including `sw` at 0x660c, `sw` at 0x675c, `sw` at 0x676c.
  3 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x8, including `lw` at 0x662c, `lw` at 0x66fc, `lw` at 0x671c.
  The `ld` at 0x664c loads 8 bytes from a0 (arg0 at entry) +0x58.
  The `ld` at 0x6660 loads 8 bytes from ?.
  3 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x200, including `sd` at 0x6698, `sd` at 0x6768, `sd` at 0x677c.
  2 such `ld` accesses load 8 bytes from a1 (arg1 at entry) +0x8, including `ld` at 0x66b4, `ld` at 0x6784.
  3 such `ld` accesses load 8 bytes from ret(kdsp_find_param_info) +0x28, including `ld` at 0x66c8, `ld` at 0x66e8, `ld` at 0x674c.
  2 such `ld` accesses load 8 bytes from [ret(kdsp_find_param_info)+40]:8 +0x0, including `ld` at 0x66d4, `ld` at 0x66ec.
  The `ld` at 0x66e0 loads 8 bytes from a0 (arg0 at entry) +0x1a0.
  3 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x1a8, including `sd` at 0x66e4, `sd` at 0x6748, `sd` at 0x6780.
  5 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x1a0, including `sd` at 0x66f4, `sd` at 0x66f8, `sd` at 0x6718.
  The `sw` at 0x670c stores 4 bytes to a0 (arg0 at entry) +0x1b0.
  3 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x220, including `sw` at 0x6714, `sw` at 0x6760, `sw` at 0x6774.
  The `sw` at 0x672c stores 4 bytes to a0 (arg0 at entry) +0x1b8.
  2 such `ld` accesses load 8 bytes from [ret(kdsp_find_param_info)+40]:8 +0x8, including `ld` at 0x6738, `ld` at 0x6750.
  The `jal` at 0x6680 calls kdsp_find_resource_in_list with a0=[a1+8], a1=a0+88, a2=?, a3=a3 at entry (arg3), a4=[a0+88]:8.
  The `jal` at 0x66ac calls kdsp_find_param_info with a0=a0 at entry (arg0), a1=[a1], a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0x65b0 targets 0x65fc, is taken when a0 == at(=[a0+496]:8+27896), and falls through when a0 != at(=[a0+496]:8+27896).
  The `beq` branch at 0x65bc targets 0x65fc, is taken when a0 == v0(=[a0+496]:8+28448), and falls through when a0 != v0(=[a0+496]:8+28448).
  The `beq` branch at 0x65d0 targets 0x66ac, is taken when a1(=[a1]) == v1(=0x1000000d), and falls through when a1(=[a1]) != v1(=0x1000000d).
  The `beq` branch at 0x65dc targets 0x662c, is taken when a1(=[a1]) == a0(=0x10000011), and falls through when a1(=[a1]) != a0(=0x10000011).
  The `beq` branch at 0x65e4 targets 0x66f8, is taken when a1(=[a1]) == a2(=0x1000000e), and falls through when a1(=[a1]) != a2(=0x1000000e).
  The `beq` branch at 0x65ec targets 0x6718, is taken when a1(=[a1]) == a0(=0x1000000f), and falls through when a1(=[a1]) != a0(=0x1000000f).
  The `beq` branch at 0x65f4 targets 0x6618 and is always taken.
  The `beq` branch at 0x65fc targets 0x6614 and is always taken.
  The `beq` branch at 0x6638 targets 0x675c, is taken when a0(=[a1+8]) == a1(=0x2000000a), and falls through when a0(=[a1+8]) != a1(=0x2000000a).
  The `beq` branch at 0x6644 targets 0x676c, is taken when a0(=[a1+8]) == a1(=0x20000016), and falls through when a0(=[a1+8]) != a1(=0x20000016).
  The `beq` branch at 0x6650 targets 0x6680, is taken when a4(=[a0+88]:8) == 0, and falls through when a4(=[a0+88]:8) != 0.
  The `beq` branch at 0x6658 targets 0x666c and is always taken.
  The `beq` branch at 0x6664 targets 0x6680, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `bne` branch at 0x6678 targets 0x6660, is taken when a2(?) < 0x18 (signed), and falls through when a2(?) >= 0x18 (signed).
  The `beq` branch at 0x668c targets 0x6604, is taken when v0(=ret(kdsp_find_resource_in_list)) == 0, and falls through when v0(=ret(kdsp_find_resource_in_list)) != 0.
  The `beq` branch at 0x6694 targets 0x66a4, is taken when v0(=ret(kdsp_find_resource_in_list)) == a0(=[a0+496]:8+2520), and falls through when v0(=ret(kdsp_find_resource_in_list)) != a0(=[a0+496]:8+2520).
  The `bne` branch at 0x669c targets 0x6710, is taken when v0(=ret(kdsp_find_resource_in_list)) != a1(=[a0+496]:8+2968), and falls through when v0(=ret(kdsp_find_resource_in_list)) == a1(=[a0+496]:8+2968).
  The `beq` branch at 0x66a4 targets 0x6710 and is always taken.
  The `blez` branch at 0x66b8 targets 0x6730, is taken when a1(=[a1+8]:8) <= 0 (signed), and falls through when a1(=[a1+8]:8) > 0 (signed).
  The `beq` branch at 0x66c0 targets 0x6730, is taken when v0(=ret(kdsp_find_param_info)) == 0, and falls through when v0(=ret(kdsp_find_param_info)) != 0.
  The `beq` branch at 0x66cc targets 0x6730, is taken when a2(=[ret(kdsp_find_param_info)+40]:8) == 0, and falls through when a2(=[ret(kdsp_find_param_info)+40]:8) != 0.
  The `beq` branch at 0x66dc targets 0x6738, is taken when a1(=[a1+8]:8) >= a0(=[[ret(kdsp_find_param_info)+40]:8]:8) (signed), and falls through when a1(=[a1+8]:8) < a0(=[[ret(kdsp_find_param_info)+40]:8]:8) (signed).
  The `beq` branch at 0x66f0 targets 0x6610 and is always taken.
  The `blez` branch at 0x6700 targets 0x6790, is taken when a0(=[a1+8]) <= 0 (signed), and falls through when a0(=[a1+8]) > 0 (signed).
  The `beq` branch at 0x6708 targets 0x6610 and is always taken.
  The `beq` branch at 0x6710 targets 0x660c and is always taken.
  The `blez` branch at 0x6720 targets 0x6798, is taken when a0(=[a1+8]) <= 0 (signed), and falls through when a0(=[a1+8]) > 0 (signed).
  The `beq` branch at 0x6728 targets 0x6610 and is always taken.
  The `beq` branch at 0x6730 targets 0x6610 and is always taken.
  The `beq` branch at 0x6740 targets 0x6780, is taken when a3(=[[ret(kdsp_find_param_info)+40]:8+8]:8) >= a1(=[a1+8]:8) (signed), and falls through when a3(=[[ret(kdsp_find_param_info)+40]:8+8]:8) < a1(=[a1+8]:8) (signed).
  The `beq` branch at 0x6754 targets 0x6610 and is always taken.
  The `beq` branch at 0x6764 targets 0x6610 and is always taken.
  The `beq` branch at 0x6778 targets 0x6610 and is always taken.
  The `beq` branch at 0x6788 targets 0x6610 and is always taken.
  The `beq` branch at 0x6790 targets 0x6610 and is always taken.
  The `beq` branch at 0x6798 targets 0x6610 and is always taken.
  The return at 0x6624 has v0 = one of 0x0, 0x1.

- `rad_get_clockgen_params` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x67a0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x67a0-0x680c (108 bytes).
  It occupies 108 bytes.
  The `lw` at 0x67a0 loads 4 bytes from a1 (arg1 at entry) +0x0.
  The `ld` at 0x67b0 loads 8 bytes from a0 (arg0 at entry) +0x1f0.
  The `ld` at 0x67b4 loads 8 bytes from a0 (arg0 at entry) +0x200.
  The `lw` at 0x67d4 loads 4 bytes from a0 (arg0 at entry) +0x1b0.
  The `sw` at 0x67e4 stores 4 bytes to a1 (arg1 at entry) +0x8.
  The `lw` at 0x67f8 loads 4 bytes from a0 (arg0 at entry) +0x1b8.
  The `bne` branch at 0x67ac targets 0x67f0, is taken when at(=[a1]) != v0(=0x10000010), and falls through when at(=[a1]) == v0(=0x10000010).
  The `beq` branch at 0x67c4 targets 0x67d4, is taken when a6(=[a0+512]:8) == v1(=[a0+496]:8+2520), and falls through when a6(=[a0+512]:8) != v1(=[a0+496]:8+2520).
  The `bne` branch at 0x67cc targets 0x6804, is taken when a6(=[a0+512]:8) != a5(=[a0+496]:8+2968), and falls through when a6(=[a0+512]:8) == a5(=[a0+496]:8+2968).
  The `beq` branch at 0x67d8 targets 0x67f8, is taken when a2(=[a0+432]) == a4(=0x1), and falls through when a2(=[a0+432]) != a4(=0x1).
  The `bne` branch at 0x67fc targets 0x67e4, is taken when a3(=[a0+440]) != a4(=0x1), and falls through when a3(=[a0+440]) == a4(=0x1).
  The `beq` branch at 0x6804 targets 0x67e4 and is always taken.
  The return at 0x67e8 has v0 = 0x1.
  The return at 0x67f0 has v0 = 0x0.

- `rad_set_digital_if_params` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x680c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x680c-0x6854 (72 bytes).
  It occupies 72 bytes.
  The `lw` at 0x680c loads 4 bytes from a1 (arg1 at entry) +0x0.
  The `beq` branch at 0x6820 targets 0x6848, is taken when v0(=[a1]) == at(=0x10000004), and falls through when v0(=[a1]) != at(=0x10000004).
  The `beq` branch at 0x6828 targets 0x6848, is taken when v0(=[a1]) == a3(=0x10000019), and falls through when v0(=[a1]) != a3(=0x10000019).
  The `beq` branch at 0x6830 targets 0x6848, is taken when v0(=[a1]) == a4(=0x1000001b), and falls through when v0(=[a1]) != a4(=0x1000001b).
  The `beq` branch at 0x6838 targets 0x684c, is taken when v0(=[a1]) == a5(=0x1000001c), and falls through when v0(=[a1]) != a5(=0x1000001c).
  The return at 0x6840 has v0 = 0x0.
  The return at 0x684c has v0 = 0x1.

- `rad_set_analog_in_gain` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x6854 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x6854-0x6994 (320 bytes).
  It occupies 320 bytes.
  The `ld` at 0x6860 loads 8 bytes from a0 (arg0 at entry) +0x198.
  The `ld` at 0x6868 loads 8 bytes from [a0+408]:8 +0x2a0.
  3 such `lw` accesses load 4 bytes from [[a0+408]:8+672]:8 +0x7260, including `lw` at 0x68dc, `lw` at 0x692c, `lw` at 0x6964.
  2 such `sw` accesses store 4 bytes to [[a0+408]:8+672]:8 +0x7260, including `sw` at 0x68f0, `sw` at 0x6938.
  2 such `sw` accesses store 4 bytes to ?, including `sw` at 0x68f4, `sw` at 0x6940.
  The `ld` at 0x6918 loads 8 bytes from ?.
  The `ld` at 0x696c loads 8 bytes from [[a0+408]:8+672]:8 +0x228.
  The `sw` at 0x697c stores 4 bytes to [[[a0+408]:8+672]:8+552]:8 +0x7c.
  The `jal` at 0x68c8 calls kdsp_db_gain_to_regval with a0=?, a1=a0 at entry (arg0), a2=0x0, a3=?.
  The `bne` branch at 0x6884 targets 0x6894, is taken when a0 != at(=[[a0+408]:8+672]:8+23144), and falls through when a0 == at(=[[a0+408]:8+672]:8+23144).
  The `beq` branch at 0x688c targets 0x6898 and is always taken.
  The `blez` branch at 0x68a4 targets 0x6944, is taken when s5(=a2) <= 0 (signed), and falls through when s5(=a2) > 0 (signed).
  The `beq` branch at 0x68bc targets 0x6980 and is always taken.
  The `bltz` branch at 0x68d0 targets 0x68f8, is taken when v0(=ret(kdsp_db_gain_to_regval)) < 0 (signed), and falls through when v0(=ret(kdsp_db_gain_to_regval)) >= 0 (signed).
  The `beq` branch at 0x690c targets 0x6944, is taken when s1(?) >= s5(=a2) (signed), and falls through when s1(?) < s5(=a2) (signed).
  The `bne` branch at 0x6924 targets 0x68c4, is taken when a0(?) != s3(=0x8000000000000000), and falls through when a0(?) == s3(=0x8000000000000000).
  The `beq` branch at 0x693c targets 0x68f8 and is always taken.
  The `beq` branch at 0x698c targets 0x6918 and is always taken.
  The return at 0x6978 has v0 = [[[a0+408]:8+672]:8+552]:8.

- `rad_set_analog_in_if_params` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x6994 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x6994-0x6a4c (184 bytes).
  It occupies 184 bytes.
  The `lw` at 0x6998 loads 4 bytes from a1 (arg1 at entry) +0x0.
  The `lh` at 0x69f0 loads 2 bytes from a1 (arg1 at entry) +0x14.
  The `ld` at 0x6a24 loads 8 bytes from a0 (arg0 at entry) +0x198.
  The `lw` at 0x6a38 loads 4 bytes from [a0+408]:8 +0x238.
  The `jal` at 0x6a04 calls rad_set_analog_in_gain with a0=a0 at entry (arg0), a1=ret(kdsp_fetch_external), a2=?, a3=0x2.
  The `jal` at 0x6a34 calls kdsp_fetch_external with a0=a1 at entry (arg1), a1=sp-48, a2=[[a0+408]:8+568], a3=0x8, a4=a2 at entry (arg2), a6=0x10000004, a7=0x1000001b.
  The `beq` branch at 0x69bc targets 0x6a20, is taken when v0(=[a1]) == at(=0x10000019), and falls through when v0(=[a1]) != at(=0x10000019).
  The `beq` branch at 0x69c4 targets 0x6a10, is taken when v0(=[a1]) == a6(=0x10000004), and falls through when v0(=[a1]) != a6(=0x10000004).
  The `beq` branch at 0x69cc targets 0x6a10, is taken when v0(=[a1]) == a7(=0x1000001b), and falls through when v0(=[a1]) != a7(=0x1000001b).
  The `beq` branch at 0x69d4 targets 0x6a10, is taken when v0(=[a1]) == t0(=0x1000001c), and falls through when v0(=[a1]) != t0(=0x1000001c).
  The `beq` branch at 0x69e0 targets 0x6a14 and is always taken.
  The `bne` branch at 0x6a3c targets 0x69e8, is taken when v0(=ret(kdsp_fetch_external)) != 0, and falls through when v0(=ret(kdsp_fetch_external)) == 0.
  The `beq` branch at 0x6a44 targets 0x6a14 and is always taken.
  The return at 0x6a18 has v0 = one of 0x0, 0x1.

- `rad_get_analog_in_if_params` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x6a4c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x6a4c-0x6bb8 (364 bytes).
  It occupies 364 bytes.
  The `lw` at 0x6a68 loads 4 bytes from a1 (arg1 at entry) +0x0.
  The `ld` at 0x6a80 loads 8 bytes from a0 (arg0 at entry) +0x198.
  The `ld` at 0x6a98 loads 8 bytes from [a0+408]:8 +0x2a0.
  The `lw` at 0x6aa4 loads 4 bytes from [a0+408]:8 +0x238.
  2 such `sd` accesses store 8 bytes to ?, including `sd` at 0x6af8, `sd` at 0x6b34.
  The `lw` at 0x6b18 loads 4 bytes from ?.
  3 such `sw` accesses store 4 bytes to a1 (arg1 at entry) +0x8, including `sw` at 0x6b8c, `sw` at 0x6b94, `sw` at 0x6b9c.
  The `lw` at 0x6bb4 loads 4 bytes from ([[a0+408]:8+672]:8 + one of 0x72b0, 0x72b8) +0x0.
  The `jal` at 0x6b28 calls kdsp_regval_to_db_gain with a0=?, a1=a0 at entry (arg0), a2=0x0, a3=?.
  The `jal` at 0x6b54 calls kdsp_put_external with a0=a1 at entry (arg1), a1=sp-96, a2=[[a0+408]:8+568], a3=0x8, a4=a2 at entry (arg2).
  The `beq` branch at 0x6aa0 targets 0x6ac4, is taken when a6(=[a1]) == at(=0x10000019), and falls through when a6(=[a1]) != at(=0x10000019).
  The `beq` branch at 0x6aac targets 0x6b80, is taken when a6(=[a1]) == a4(=0x10000004), and falls through when a6(=[a1]) != a4(=0x10000004).
  The `beq` branch at 0x6ab4 targets 0x6b90, is taken when a6(=[a1]) == a7(=0x1000001c), and falls through when a6(=[a1]) != a7(=0x1000001c).
  The `beq` branch at 0x6abc targets 0x6b64 and is always taken.
  The `bne` branch at 0x6acc targets 0x6adc, is taken when a0 != t8(=[[a0+408]:8+672]:8+23144), and falls through when a0 == t8(=[[a0+408]:8+672]:8+23144).
  The `beq` branch at 0x6ad4 targets 0x6ae0 and is always taken.
  The `blez` branch at 0x6ae4 targets 0x6b38, is taken when s2(=[[a0+408]:8+568]) <= 0 (signed), and falls through when s2(=[[a0+408]:8+568]) > 0 (signed).
  The `beq` branch at 0x6af0 targets 0x6ba0 and is always taken.
  The `beq` branch at 0x6b10 targets 0x6b38, is taken when s0(?) >= s2(=[[a0+408]:8+568]) (signed), and falls through when s0(?) < s2(=[[a0+408]:8+568]) (signed).
  The `beq` branch at 0x6b1c targets 0x6af8, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x6b30 targets 0x6afc and is always taken.
  The `bne` branch at 0x6b80 targets 0x6b98, is taken when s3(=a0) != a0(=[[a0+408]:8+672]:8+23144), and falls through when s3(=a0) == a0(=[[a0+408]:8+672]:8+23144).
  The `beq` branch at 0x6b88 targets 0x6b5c and is always taken.
  The `beq` branch at 0x6b90 targets 0x6b5c and is always taken.
  The `beq` branch at 0x6b98 targets 0x6b5c and is always taken.
  The `beq` branch at 0x6bb0 targets 0x6b1c and is always taken.
  The return at 0x6b78 has v0 = one of 0x0, 0x1.

- `rad_set_analog_out_if_params` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x6bb8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x6bb8-0x6e30 (632 bytes).
  It occupies 632 bytes.
  The `lw` at 0x6bd0 loads 4 bytes from a1 (arg1 at entry) +0x0.
  The `ld` at 0x6bdc loads 8 bytes from a0 (arg0 at entry) +0x198.
  The `ld` at 0x6bf8 loads 8 bytes from [a0+408]:8 +0x2a0.
  The `lw` at 0x6c38 loads 4 bytes from a1 (arg1 at entry) +0x8.
  The `lw` at 0x6c3c loads 4 bytes from [[a0+408]:8+672]:8 +0x7244.
  3 such `ld` accesses load 8 bytes from [[a0+408]:8+672]:8 +0x228, including `ld` at 0x6c44, `ld` at 0x6dec, `ld` at 0x6e04.
  The `sw` at 0x6c54 stores 4 bytes to [[a0+408]:8+672]:8 +0x7244.
  The `sw` at 0x6c58 stores 4 bytes to [[[a0+408]:8+672]:8+552]:8 +0x70.
  The `ld` at 0x6cac loads 8 bytes from ret(kdsp_fetch_external) +0x0.
  The `lw` at 0x6cd8 loads 4 bytes from [a0+408]:8 +0x238.
  The `lh` at 0x6d04 loads 2 bytes from a1 (arg1 at entry) +0x14.
  3 such `lw` accesses load 4 bytes from [[a0+408]:8+672]:8 +0x7260, including `lw` at 0x6d70, `lw` at 0x6dc8, `lw` at 0x6df0.
  2 such `sw` accesses store 4 bytes to [[a0+408]:8+672]:8 +0x7260, including `sw` at 0x6d8c, `sw` at 0x6ddc.
  2 such `sw` accesses store 4 bytes to ?, including `sw` at 0x6d90, `sw` at 0x6de4.
  The `ld` at 0x6dbc loads 8 bytes from ?.
  The `sw` at 0x6df8 stores 4 bytes to [[[a0+408]:8+672]:8+552]:8 +0x7c.
  2 such `sw` accesses store 4 bytes to [[a0+408]:8+672]:8 +0x7270, including `sw` at 0x6dfc, `sw` at 0x6e18.
  The `sw` at 0x6e08 stores 4 bytes to [[[a0+408]:8+672]:8+552]:8 +0x90.
  The `sw` at 0x6e10 stores 4 bytes to a0 (arg0 at entry) +0x1a0.
  The `jal` at 0x6ca4 calls kdsp_fetch_external with a0=a1 at entry (arg1), a1=sp-96, a2=0x1, a3=0x8, a4=a2 at entry (arg2), a6=0x10000000, a7=0x1000001c.
  The `jal` at 0x6cdc calls kdsp_fetch_external with a0=a1 at entry (arg1), a1=sp-88, a2=[[a0+408]:8+568], a3=0x8, a4=a2 at entry (arg2), a6=0x10000000, a7=0x1000001c.
  The `jal` at 0x6d0c calls kdsp_find_param_info with a0=a0 at entry (arg0), a1=0x10000019, a2=[a1+20]:2, a3=?.
  The `jal` at 0x6d50 calls kdsp_db_gain_to_regval with a0=?, a1=a0 at entry (arg0), a2=0x0, a3=?, a4=0xff.
  The `beq` branch at 0x6bf4 targets 0x6c88, is taken when v0(=[a1]) == t2(=0x10000019), and falls through when v0(=[a1]) != t2(=0x10000019).
  The `beq` branch at 0x6c04 targets 0x6c30, is taken when v0(=[a1]) == at(=0x1000001d), and falls through when v0(=[a1]) != at(=0x1000001d).
  The `beq` branch at 0x6c0c targets 0x6c9c, is taken when v0(=[a1]) == a7(=0x1000001c), and falls through when v0(=[a1]) != a7(=0x1000001c).
  The `beq` branch at 0x6c14 targets 0x6c60, is taken when v0(=[a1]) == a1(=0x10000004), and falls through when v0(=[a1]) != a1(=0x10000004).
  The `beq` branch at 0x6c1c targets 0x6c60, is taken when v0(=[a1]) == t0(=0x1000001b), and falls through when v0(=[a1]) != t0(=0x1000001b).
  The `beq` branch at 0x6c28 targets 0x6c64 and is always taken.
  The `bne` branch at 0x6c30 targets 0x6c7c, is taken when s1(=a0) != a0(=[[a0+408]:8+672]:8+23568), and falls through when s1(=a0) == a0(=[[a0+408]:8+672]:8+23568).
  The `beq` branch at 0x6c80 targets 0x6c64 and is always taken.
  The `beq` branch at 0x6c8c targets 0x6cd4, is taken when a0 == v1(=[[a0+408]:8+672]:8+23568), and falls through when a0 != v1(=[[a0+408]:8+672]:8+23568).
  The `beq` branch at 0x6c94 targets 0x6c64 and is always taken.
  The `beq` branch at 0x6cbc targets 0x6e14, is taken when a0(?) == a1(=0x12), and falls through when a0(?) != a1(=0x12).
  The `beq` branch at 0x6cc4 targets 0x6dfc, is taken when a0(?) == a1(=0x10), and falls through when a0(?) != a1(=0x10).
  The `beq` branch at 0x6ccc targets 0x6c64 and is always taken.
  The `bne` branch at 0x6ce8 targets 0x6cf8, is taken when v0(=ret(kdsp_fetch_external)) != 0, and falls through when v0(=ret(kdsp_fetch_external)) == 0.
  The `beq` branch at 0x6cf0 targets 0x6c64 and is always taken.
  The `blez` branch at 0x6d38 targets 0x6de8, is taken when a3(?) <= 0 (signed), and falls through when a3(?) > 0 (signed).
  The `beq` branch at 0x6d44 targets 0x6e24 and is always taken.
  The `bltz` branch at 0x6d64 targets 0x6d94, is taken when v0(=ret(kdsp_db_gain_to_regval)) < 0 (signed), and falls through when v0(=ret(kdsp_db_gain_to_regval)) >= 0 (signed).
  The `beq` branch at 0x6da8 targets 0x6de8, is taken when s2(?) >= t1(?) (signed), and falls through when s2(?) < t1(?) (signed).
  The `bne` branch at 0x6dc0 targets 0x6d4c, is taken when a0(?) != a2(=0x8000000000000000), and falls through when a0(?) == a2(=0x8000000000000000).
  The `beq` branch at 0x6de0 targets 0x6d94 and is always taken.
  The `beq` branch at 0x6df4 targets 0x6c5c and is always taken.
  The `beq` branch at 0x6e0c targets 0x6c5c and is always taken.
  The `beq` branch at 0x6e1c targets 0x6e04 and is always taken.
  The `beq` branch at 0x6e28 targets 0x6db4 and is always taken.
  The return at 0x6c74 has v0 = one of 0x0, 0x1.

- `rad_get_analog_out_if_params` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x6e30 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x6e30-0x6fc4 (404 bytes).
  It occupies 404 bytes.
  The `lw` at 0x6e48 loads 4 bytes from a1 (arg1 at entry) +0x0.
  The `ld` at 0x6e54 loads 8 bytes from a0 (arg0 at entry) +0x198.
  The `ld` at 0x6e6c loads 8 bytes from [a0+408]:8 +0x2a0.
  The `lw` at 0x6e78 loads 4 bytes from [a0+408]:8 +0x238.
  The `lw` at 0x6e90 loads 4 bytes from [[a0+408]:8+672]:8 +0x7270.
  The `lw` at 0x6e9c loads 4 bytes from sym(.data) +0x7438.
  3 such `sw` accesses store 4 bytes to a1 (arg1 at entry) +0x8, including `sw` at 0x6ea0, `sw` at 0x6ee0, `sw` at 0x6ef4.
  The `lw` at 0x6ed0 loads 4 bytes from [[a0+408]:8+672]:8 +0x7244.
  The `lw` at 0x6eec loads 4 bytes from sym(.data) +0x7430.
  The `ld` at 0x6f24 loads 8 bytes from sym(.bss) +0x58.
  2 such `sd` accesses store 8 bytes to ?, including `sd` at 0x6f50, `sd` at 0x6fa8.
  The `lw` at 0x6f6c loads 4 bytes from ?.
  The `lw` at 0x6fc0 loads 4 bytes from [[a0+408]:8+672]:8 +0x72c0.
  The `jal` at 0x6ef8 calls kdsp_find_param_info with a0=a0 at entry (arg0), a1=0x10000019, a2=a2 at entry (arg2), a3=a3 at entry (arg3), a6=0x1000001d, a7=0x1000001c.
  The `jal` at 0x6f40 calls kdsp_put_external with a0=a1 at entry (arg1), a1=sp-80, a2=[[a0+408]:8+568], a3=0x8, a4=a2 at entry (arg2), a7=sp-80.
  The `jal` at 0x6f90 calls kdsp_regval_to_db_gain with a0=?, a1=a0 at entry (arg0), a2=0x0, a3=?, a7=sp-80.
  The `beq` branch at 0x6e74 targets 0x6ef8, is taken when v0(=[a1]) == t2(=0x10000019), and falls through when v0(=[a1]) != t2(=0x10000019).
  The `beq` branch at 0x6e80 targets 0x6ec0, is taken when v0(=[a1]) == a6(=0x1000001d), and falls through when v0(=[a1]) != a6(=0x1000001d).
  The `bne` branch at 0x6e88 targets 0x6ee4, is taken when v0(=[a1]) != a7(=0x1000001c), and falls through when v0(=[a1]) == a7(=0x1000001c).
  The `beq` branch at 0x6e94 targets 0x6eec, is taken when t8(=[[[a0+408]:8+672]:8+29296]) == t9(=0x2), and falls through when t8(=[[[a0+408]:8+672]:8+29296]) != t9(=0x2).
  The `beq` branch at 0x6ec0 targets 0x6ed0, is taken when s1(=a0) == a0(=[[a0+408]:8+672]:8+23568), and falls through when s1(=a0) != a0(=[[a0+408]:8+672]:8+23568).
  The `beq` branch at 0x6ec8 targets 0x6eac and is always taken.
  The `beq` branch at 0x6edc targets 0x6ea4 and is always taken.
  The `beq` branch at 0x6ee4 targets 0x6ea8 and is always taken.
  The `beq` branch at 0x6ef0 targets 0x6ea4 and is always taken.
  The `bne` branch at 0x6f08 targets 0x6f24, is taken when s1(=a0) != a0(=[[a0+408]:8+672]:8+23568), and falls through when s1(=a0) == a0(=[[a0+408]:8+672]:8+23568).
  The `blez` branch at 0x6f10 targets 0x6f34, is taken when s3(=[[a0+408]:8+568]) <= 0 (signed), and falls through when s3(=[[a0+408]:8+568]) > 0 (signed).
  The `beq` branch at 0x6f1c targets 0x6fb4 and is always taken.
  The `beq` branch at 0x6f48 targets 0x6ea4 and is always taken.
  The `beq` branch at 0x6f64 targets 0x6fac, is taken when a0(?) >= s3(=[[a0+408]:8+568]) (signed), and falls through when a0(?) < s3(=[[a0+408]:8+568]) (signed).
  The `beq` branch at 0x6f80 targets 0x6f50, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `beq` branch at 0x6fa4 targets 0x6f54 and is always taken.
  The `beq` branch at 0x6fac targets 0x6f34 and is always taken.
  The `beq` branch at 0x6fbc targets 0x6f70 and is always taken.
  The return at 0x6eb8 has v0 = one of 0x0, 0x1.

- `rad_vl_write_MUX_SEL_MIO` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x6fc4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x6fc4-0x7044 (128 bytes).
  It occupies 128 bytes.
  6 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x228, including `ld` at 0x6fd8, `ld` at 0x6fec, `ld` at 0x7004.
  2 such `sw` accesses store 4 bytes to [a0+552]:8 +0x8c, including `sw` at 0x6fe4, `sw` at 0x7040.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x7248, including `lw` at 0x6fe8, `lw` at 0x6ffc.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x7248, including `sw` at 0x6ff4, `sw` at 0x700c.
  2 such `sw` accesses store 4 bytes to [a0+552]:8 +0x4c, including `sw` at 0x6ff8, `sw` at 0x7014.
  2 such `sw` accesses store 4 bytes to [a0+552]:8 +0x88, including `sw` at 0x7020, `sw` at 0x7030.
  The `sw` at 0x702c stores 4 bytes to a0 (arg0 at entry) +0x7268.
  The `lw` at 0x7038 loads 4 bytes from a0 (arg0 at entry) +0x726c.
  The `bgez` branch at 0x7010 targets 0x6fd4, is taken when a3(?) >= 0 (signed), and falls through when a3(?) < 0 (signed).
  The return at 0x703c has v0 = ?.

- `rad_vl_write_MUX_SEL_RADICAL` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x7044 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x7044-0x7050 (12 bytes).
  It occupies 12 bytes.
  The `ld` at 0x7044 loads 8 bytes from a0 (arg0 at entry) +0x228.
  The `sw` at 0x704c stores 4 bytes to [a0+552]:8 +0x7c.
  The return at 0x7048 has v0 = ?.

- `rad_vl_write_MUX_SEL` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x7050 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x7050-0x7098 (72 bytes).
  It occupies 72 bytes.
  The `lh` at 0x7050 loads 2 bytes from a0 (arg0 at entry) +0x21a.
  The `jal` at 0x7078 calls rad_vl_write_MUX_SEL_RADICAL with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=0xd, a4=[a0+538]:2.
  The `jal` at 0x7088 calls rad_vl_write_MUX_SEL_MIO with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=0xd, a4=[a0+538]:2.
  The `beq` branch at 0x7060 targets 0x7088, is taken when a4(=[a0+538]:2) == at(=0x7), and falls through when a4(=[a0+538]:2) != at(=0x7).
  The `beq` branch at 0x7068 targets 0x7078, is taken when a4(=[a0+538]:2) == a3(=0xd), and falls through when a4(=[a0+538]:2) != a3(=0xd).
  The `beq` branch at 0x7080 targets 0x7070 and is always taken.
  The `beq` branch at 0x7090 targets 0x7070 and is always taken.
  The return at 0x7070 has v0 = one of ?, ret(rad_vl_write_MUX_SEL_RADICAL), ret(rad_vl_write_MUX_SEL_MIO).

- `rad_vl_set_clockgen_MIO` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x7098 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x7098-0x7288 (496 bytes).
  It occupies 496 bytes.
  The `ld` at 0x70a0 loads 8 bytes from a0 (arg0 at entry) +0x1f0.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x1b8, including `lw` at 0x70fc, `lw` at 0x7120, `lw` at 0x715c.
  3 such `lw` accesses load 4 bytes from [a0+496]:8 +0x7274, including `lw` at 0x7114, `lw` at 0x7140, `lw` at 0x7260.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x1b0, including `lw` at 0x712c, `lw` at 0x7200, `lw` at 0x7228.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x208, including `lw` at 0x7170, `lw` at 0x7210.
  The `lw` at 0x7180 loads 4 bytes from (sym(.rodata) + ([a0+520] << 0x3)) +0x0.
  The `lw` at 0x7184 loads 4 bytes from (sym(.rodata) + ([a0+520] << 0x3)) +0x4.
  2 such `sw` accesses store 4 bytes to [a0+496]:8 +0x7274, including `sw` at 0x71a4, `sw` at 0x727c.
  The `jal` at 0x71a0 calls rad_vl_write_MUX_SEL_MIO with a0=[a0+496]:8, a1=?, a2=?, a3=([a0+520] << 0x3), a4=one of 0x0, 0x1, 0x2, a5=[a0+496]:8+26240, a6=[a0+496]:8+26240.
  The `jal` at 0x71a8 calls rad_update_ksync with a0=[a0+496]:8, a1=?, a2=?, a3=?.
  The `bne` branch at 0x70c8 targets 0x70d4, is taken when s3(=[a0+496]:8+2968) != a1, and falls through when s3(=[a0+496]:8+2968) == a1.
  The `bne` branch at 0x70d0 targets 0x70fc, is taken when a0 != v0(=[a0+496]:8+26240), and falls through when a0 == v0(=[a0+496]:8+26240).
  The `bne` branch at 0x70d8 targets 0x70f0, is taken when s2(=a1) != at(=[a0+496]:8+2520), and falls through when s2(=a1) == at(=[a0+496]:8+2520).
  The `beq` branch at 0x70e0 targets 0x70f4, is taken when s1(=a0) == v0(=[a0+496]:8+26240), and falls through when s1(=a0) != v0(=[a0+496]:8+26240).
  The `beq` branch at 0x70e8 targets 0x70f4 and is always taken.
  The `beq` branch at 0x70f4 targets 0x710c, is taken when v0(=one of 0x0, 0x1) == 0, and falls through when v0(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x7104 targets 0x7200, is taken when v0(=[a0+440]) == a4(=0x1), and falls through when v0(=[a0+440]) != a4(=0x1).
  The `bne` branch at 0x710c targets 0x7140, is taken when s3(=[a0+496]:8+2968) != s2(=a1), and falls through when s3(=[a0+496]:8+2968) == s2(=a1).
  The `beq` branch at 0x7118 targets 0x7144, is taken when s1(=a0) == a5(=[a0+496]:8+26240), and falls through when s1(=a0) != a5(=[a0+496]:8+26240).
  The `bne` branch at 0x7124 targets 0x7148, is taken when v1(=[a0+440]) != a4(=0x1), and falls through when v1(=[a0+440]) == a4(=0x1).
  The `bne` branch at 0x7130 targets 0x7148, is taken when a0(=[a0+432]) != a4(=0x1), and falls through when a0(=[a0+432]) == a4(=0x1).
  The `beq` branch at 0x7138 targets 0x7170 and is always taken.
  The `bne` branch at 0x7148 targets 0x716c, is taken when s2(=a1) != a1(=[a0+496]:8+2520), and falls through when s2(=a1) == a1(=[a0+496]:8+2520).
  The `beq` branch at 0x7150 targets 0x716c, is taken when s1(=a0) == a6(=[a0+496]:8+26240), and falls through when s1(=a0) != a6(=[a0+496]:8+26240).
  The `beq` branch at 0x7160 targets 0x7228, is taken when a2(=[a0+440]) == a4(=0x1), and falls through when a2(=[a0+440]) != a4(=0x1).
  The `bne` branch at 0x71b4 targets 0x71d0, is taken when s3(=[a0+496]:8+2968) != s2(=a1), and falls through when s3(=[a0+496]:8+2968) == s2(=a1).
  The `beq` branch at 0x71c0 targets 0x71d4, is taken when s1(=a0) == a3(=[a0+496]:8+26240), and falls through when s1(=a0) != a3(=[a0+496]:8+26240).
  The `beq` branch at 0x71c8 targets 0x71ec and is always taken.
  The `bne` branch at 0x71d4 targets 0x71e4, is taken when s2(=a1) != a4(=[a0+496]:8+2520), and falls through when s2(=a1) == a4(=[a0+496]:8+2520).
  The `bne` branch at 0x71dc targets 0x71c8, is taken when s1(=a0) != a5(=[a0+496]:8+26240), and falls through when s1(=a0) == a5(=[a0+496]:8+26240).
  The `bne` branch at 0x7204 targets 0x710c, is taken when a7(=[a0+432]) != a4(=0x1), and falls through when a7(=[a0+432]) == a4(=0x1).
  The `bne` branch at 0x720c targets 0x723c, is taken when s3(=[a0+496]:8+2968) != s2(=a1), and falls through when s3(=[a0+496]:8+2968) == s2(=a1).
  The `beq` branch at 0x7218 targets 0x723c, is taken when s1(=a0) == t0(=[a0+496]:8+26240), and falls through when s1(=a0) != t0(=[a0+496]:8+26240).
  The `beq` branch at 0x7220 targets 0x7260 and is always taken.
  The `bne` branch at 0x722c targets 0x716c, is taken when t1(=[a0+432]) != a4(=0x1), and falls through when t1(=[a0+432]) == a4(=0x1).
  The `beq` branch at 0x7234 targets 0x716c and is always taken.
  The `bne` branch at 0x7240 targets 0x7258, is taken when s2(=a1) != t2(=[a0+496]:8+2520), and falls through when s2(=a1) == t2(=[a0+496]:8+2520).
  The `beq` branch at 0x7248 targets 0x7258, is taken when s1(=a0) == t3(=[a0+496]:8+26240), and falls through when s1(=a0) != t3(=[a0+496]:8+26240).
  The `beq` branch at 0x7250 targets 0x7260 and is always taken.
  The `bne` branch at 0x7278 targets 0x7144, is taken when s3(=[a0+496]:8+2968) != s2(=a1), and falls through when s3(=[a0+496]:8+2968) == s2(=a1).
  The `beq` branch at 0x7280 targets 0x7118 and is always taken.
  The return at 0x71f8 has v0 = one of 0x0, 0x1.

- `rad_vl_set_clockgen_RADICAL` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x7288 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x7288-0x73a4 (284 bytes).
  It occupies 284 bytes.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x208, including `lw` at 0x7290, `lw` at 0x7308, `lw` at 0x738c.
  The `ld` at 0x72a4 loads 8 bytes from a0 (arg0 at entry) +0x1f0.
  The `lw` at 0x72b8 loads 4 bytes from [a0+496]:8 +0x7274.
  2 such `sw` accesses store 4 bytes to [a0+496]:8 +0x7274, including `sw` at 0x72dc, `sw` at 0x733c.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x1b8, including `lw` at 0x72e0, `lw` at 0x72f8.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x1b0, including `lw` at 0x737c, `lw` at 0x7390.
  The `jal` at 0x7338 calls rad_vl_write_MUX_SEL_RADICAL with a0=[a0+496]:8, a1=?, a2=?, a3=?, a4=one of 0x0, 0x1, 0x2, a6=0x6, a7=-0xc1.
  The `jal` at 0x7340 calls rad_update_ksync with a0=[a0+496]:8, a1=?, a2=?, a3=?.
  The `bne` branch at 0x72d8 targets 0x72ec, is taken when s8(=[a0+496]:8+2968) != a1, and falls through when s8(=[a0+496]:8+2968) == a1.
  The `beq` branch at 0x72e8 targets 0x737c, is taken when t1(=[a0+440]) == a4(=0x1), and falls through when t1(=[a0+440]) != a4(=0x1).
  The `bne` branch at 0x72f0 targets 0x7304, is taken when s1(=a1) != t2(=[a0+496]:8+2520), and falls through when s1(=a1) == t2(=[a0+496]:8+2520).
  The `beq` branch at 0x72fc targets 0x7390, is taken when t3(=[a0+440]) == a4(=0x1), and falls through when t3(=[a0+440]) != a4(=0x1).
  The `beq` branch at 0x734c targets 0x7374, is taken when s8(=[a0+496]:8+2968) == s1(=a1), and falls through when s8(=[a0+496]:8+2968) != s1(=a1).
  The `beq` branch at 0x7358 targets 0x7374, is taken when s1(=a1) == t0(=[a0+496]:8+2520), and falls through when s1(=a1) != t0(=[a0+496]:8+2520).
  The `beq` branch at 0x7374 targets 0x7360 and is always taken.
  The `bne` branch at 0x7380 targets 0x72f0, is taken when t1(=[a0+432]) != a4(=0x1), and falls through when t1(=[a0+432]) == a4(=0x1).
  The `beq` branch at 0x7388 targets 0x730c and is always taken.
  The `bne` branch at 0x7394 targets 0x7308, is taken when t2(=[a0+432]) != a4(=0x1), and falls through when t2(=[a0+432]) == a4(=0x1).
  The `beq` branch at 0x739c targets 0x7308 and is always taken.
  The return at 0x736c has v0 = one of 0x0, 0x1.

- `rad_vl_set_clockgen` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x73a4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x73a4-0x73e8 (68 bytes).
  It occupies 68 bytes.
  The `ld` at 0x73a4 loads 8 bytes from a0 (arg0 at entry) +0x1f0.
  The `lh` at 0x73a8 loads 2 bytes from [a0+496]:8 +0x21a.
  The `jal` at 0x73bc calls rad_vl_set_clockgen_RADICAL with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x73d8 calls rad_vl_set_clockgen_MIO with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0x73b4 targets 0x73d8, is taken when at(=[[a0+496]:8+538]:2) == v0(=0x7), and falls through when at(=[[a0+496]:8+538]:2) != v0(=0x7).
  The `beq` branch at 0x73e0 targets 0x73c8 and is always taken.
  The return at 0x73d0 has v0 = one of ret(rad_vl_set_clockgen_RADICAL), ret(rad_vl_set_clockgen_MIO).

- `rad_update_ksync` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x73e8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x73e8-0x76e8 (768 bytes).
  It occupies 768 bytes.
  The `ld` at 0x73f4 loads 8 bytes from a0 (arg0 at entry) +0x72e8.
  20 such `lw` accesses load 4 bytes from ?, including `lw` at 0x748c, `lw` at 0x74dc, `lw` at 0x74ec.
  5 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x228, including `ld` at 0x749c, `ld` at 0x74a4, `ld` at 0x7550.
  2 such `sw` accesses store 4 bytes to [a0+552]:8 +0xa4, including `sw` at 0x74a0, `sw` at 0x755c.
  2 such `sw` accesses store 4 bytes to [a0+552]:8 +0xa0, including `sw` at 0x74a8, `sw` at 0x7574.
  3 such `sw` accesses store 4 bytes to ?, including `sw` at 0x74ac, `sw` at 0x74b0, `sw` at 0x7544.
  The `bne` branch at 0x7414 targets 0x7438, is taken when v0(=[a0+29416]:8) < at(=0xfa24e2) (signed), and falls through when v0(=[a0+29416]:8) >= at(=0xfa24e2) (signed).
  The `bne` branch at 0x7428 targets 0x7438, is taken when v1(=0x1029fa0) < v0(=[a0+29416]:8) (signed), and falls through when v1(=0x1029fa0) >= v0(=[a0+29416]:8) (signed).
  The `beq` branch at 0x7430 targets 0x7458 and is always taken.
  The `bne` branch at 0x7444 targets 0x7500, is taken when v0(=[a0+29416]:8) < a1(=0x12b3123) (signed), and falls through when v0(=[a0+29416]:8) >= a1(=0x12b3123) (signed).
  The `bne` branch at 0x744c targets 0x7654, is taken when a4(?) != 0, and falls through when a4(?) == 0.
  The `beq` branch at 0x7474 targets 0x74c8 and is always taken.
  The `beq` branch at 0x747c targets 0x7660, is taken when t1(=one of 0x0, 0x1) == 0, and falls through when t1(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x7494 targets 0x76cc, is taken when a4(=0x11ffe89) == t8(?), and falls through when a4(=0x11ffe89) != t8(?).
  The `beq` branch at 0x74b4 targets 0x760c, is taken when a7(=one of 0x0, 0x1) == 0, and falls through when a7(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x74c0 targets 0x7504, is taken when v1(?) == 0, and falls through when v1(?) != 0.
  The `beq` branch at 0x74c8 targets 0x747c, is taken when v0(?) == t2(=0x1), and falls through when v0(?) != t2(=0x1).
  The `beq` branch at 0x74d0 targets 0x761c, is taken when t1(=one of 0x0, 0x1) == 0, and falls through when t1(=one of 0x0, 0x1) != 0.
  The `bne` branch at 0x74e4 targets 0x749c, is taken when t0(=0x54fd8f) != a1(?), and falls through when t0(=0x54fd8f) == a1(?).
  The `bne` branch at 0x74f0 targets 0x749c, is taken when a6(=0x400166b) != t8(?), and falls through when a6(=0x400166b) == t8(?).
  The `beq` branch at 0x74f8 targets 0x74b4 and is always taken.
  The `beq` branch at 0x7508 targets 0x757c and is always taken.
  The `beq` branch at 0x7514 targets 0x7578, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `beq` branch at 0x7534 targets 0x7578, is taken when t9(?) == v0(=one of 0x0, 0x1), and falls through when t9(?) != v0(=one of 0x0, 0x1).
  The `beq` branch at 0x7578 targets 0x75f0, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `beq` branch at 0x75a0 targets 0x75c4, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `bne` branch at 0x75a8 targets 0x7514, is taken when a7(=one of 0x0, 0x1) != 0, and falls through when a7(=one of 0x0, 0x1) == 0.
  The `bne` branch at 0x75b0 targets 0x7514, is taken when t1(=one of 0x0, 0x1) != 0, and falls through when t1(=one of 0x0, 0x1) == 0.
  The `beq` branch at 0x75bc targets 0x7514 and is always taken.
  The `beq` branch at 0x75c4 targets 0x7578, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `beq` branch at 0x75e0 targets 0x7578, is taken when (t0(?) & 0x100) == 0, and falls through when (t0(?) & 0x100) != 0.
  The `beq` branch at 0x75e8 targets 0x753c and is always taken.
  The `bne` branch at 0x75f0 targets 0x7604, is taken when a7(=one of 0x0, 0x1) != 0, and falls through when a7(=one of 0x0, 0x1) == 0.
  The `beq` branch at 0x75f8 targets 0x76e0, is taken when t1(=one of 0x0, 0x1) == 0, and falls through when t1(=one of 0x0, 0x1) != 0.
  The `bne` branch at 0x760c targets 0x74c0, is taken when t1(=one of 0x0, 0x1) != 0, and falls through when t1(=one of 0x0, 0x1) == 0.
  The `beq` branch at 0x7614 targets 0x7508 and is always taken.
  The `beq` branch at 0x761c targets 0x76a8, is taken when a7(=one of 0x0, 0x1) == 0, and falls through when a7(=one of 0x0, 0x1) != 0.
  The `bne` branch at 0x7638 targets 0x749c, is taken when a4(=0xacfd8f) != t8(?), and falls through when a4(=0xacfd8f) == t8(?).
  The `bne` branch at 0x7644 targets 0x749c, is taken when t9(=0x4001693) != t8(?), and falls through when t9(=0x4001693) == t8(?).
  The `beq` branch at 0x764c targets 0x74b4 and is always taken.
  The `beq` branch at 0x7658 targets 0x7504 and is always taken.
  The `beq` branch at 0x7660 targets 0x76a8, is taken when a7(=one of 0x0, 0x1) == 0, and falls through when a7(=one of 0x0, 0x1) != 0.
  The `bne` branch at 0x7680 targets 0x749c, is taken when a4(=0x39ff83) != at(?), and falls through when a4(=0x39ff83) == at(?).
  The `bne` branch at 0x7694 targets 0x749c, is taken when t8(=0x8001892) != at(?), and falls through when t8(=0x8001892) == at(?).
  The `beq` branch at 0x769c targets 0x74b4 and is always taken.
  The `bne` branch at 0x76b0 targets 0x749c, is taken when at(?) != a4(?), and falls through when at(?) == a4(?).
  The `beq` branch at 0x76bc targets 0x74b4, is taken when t8(?) == a5(?), and falls through when t8(?) != a5(?).
  The `beq` branch at 0x76c4 targets 0x74a0 and is always taken.
  The `bne` branch at 0x76d0 targets 0x749c, is taken when t3(=0x8001866) != at(?), and falls through when t3(=0x8001866) == at(?).
  The `beq` branch at 0x76d8 targets 0x74b4 and is always taken.
  The `beq` branch at 0x76e0 targets 0x7604 and is always taken.
  The return at 0x7604 has v0 = one of 0x0, 0x1.
  The instructions from 0x7510 to 0x7510 are not reached by any path from the entry, and their branches are not listed.
  The instructions from 0x76a4 to 0x76a4 are not reached by any path from the entry, and their branches are not listed.

- `kdsp_idbg_rad_dump_subsys` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x76e8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x76e8-0x7920 (568 bytes).
  It occupies 568 bytes.
  The `lw` at 0x76e8 loads 4 bytes from a0 (arg0 at entry) +0x230.
  The `lw` at 0x770c loads 4 bytes from a0 (arg0 at entry) +0x24c.
  The `lw` at 0x7710 loads 4 bytes from a0 (arg0 at entry) +0x248.
  The `lw` at 0x771c loads 4 bytes from a0 (arg0 at entry) +0x254.
  The `lw` at 0x7720 loads 4 bytes from a0 (arg0 at entry) +0x250.
  The `lw` at 0x772c loads 4 bytes from a0 (arg0 at entry) +0x25c.
  The `lw` at 0x7730 loads 4 bytes from a0 (arg0 at entry) +0x258.
  The `lw` at 0x773c loads 4 bytes from a0 (arg0 at entry) +0x264.
  The `lw` at 0x7740 loads 4 bytes from a0 (arg0 at entry) +0x260.
  The `lw` at 0x774c loads 4 bytes from a0 (arg0 at entry) +0x26c.
  The `lw` at 0x7750 loads 4 bytes from a0 (arg0 at entry) +0x268.
  The `lw` at 0x775c loads 4 bytes from a0 (arg0 at entry) +0x274.
  The `lw` at 0x7760 loads 4 bytes from a0 (arg0 at entry) +0x270.
  The `lw` at 0x776c loads 4 bytes from a0 (arg0 at entry) +0x27c.
  The `lw` at 0x7770 loads 4 bytes from a0 (arg0 at entry) +0x278.
  The `lw` at 0x777c loads 4 bytes from a0 (arg0 at entry) +0x284.
  The `lw` at 0x7780 loads 4 bytes from a0 (arg0 at entry) +0x280.
  The `lw` at 0x778c loads 4 bytes from a0 (arg0 at entry) +0x288.
  The `lw` at 0x7798 loads 4 bytes from a0 (arg0 at entry) +0x290.
  The `lw` at 0x779c loads 4 bytes from a0 (arg0 at entry) +0x28c.
  The `lw` at 0x77a8 loads 4 bytes from a0 (arg0 at entry) +0x298.
  The `lw` at 0x77ac loads 4 bytes from a0 (arg0 at entry) +0x294.
  The `lw` at 0x77b8 loads 4 bytes from a0 (arg0 at entry) +0x2a0.
  The `lw` at 0x77bc loads 4 bytes from a0 (arg0 at entry) +0x29c.
  The `lw` at 0x77c8 loads 4 bytes from a0 (arg0 at entry) +0x2a8.
  The `lw` at 0x77cc loads 4 bytes from a0 (arg0 at entry) +0x2a4.
  The `lw` at 0x77d8 loads 4 bytes from a0 (arg0 at entry) +0x2b0.
  The `lw` at 0x77dc loads 4 bytes from a0 (arg0 at entry) +0x2ac.
  The `lw` at 0x77e8 loads 4 bytes from a0 (arg0 at entry) +0x2b8.
  The `lw` at 0x77ec loads 4 bytes from a0 (arg0 at entry) +0x2b4.
  The `lw` at 0x77f8 loads 4 bytes from a0 (arg0 at entry) +0x2c4.
  The `lw` at 0x77fc loads 4 bytes from a0 (arg0 at entry) +0x2c0.
  The `lw` at 0x7800 loads 4 bytes from a0 (arg0 at entry) +0x2bc.
  The `lw` at 0x7814 loads 4 bytes from a0 (arg0 at entry) +0x7248.
  The `lw` at 0x7818 loads 4 bytes from a0 (arg0 at entry) +0x724c.
  The `lw` at 0x7824 loads 4 bytes from a0 (arg0 at entry) +0x7258.
  The `lw` at 0x7828 loads 4 bytes from a0 (arg0 at entry) +0x7250.
  The `lw` at 0x7834 loads 4 bytes from a0 (arg0 at entry) +0x725c.
  The `lw` at 0x7838 loads 4 bytes from a0 (arg0 at entry) +0x7254.
  The `lw` at 0x7844 loads 4 bytes from a0 (arg0 at entry) +0x7240.
  The `lw` at 0x7848 loads 4 bytes from a0 (arg0 at entry) +0x7244.
  The `lw` at 0x7854 loads 4 bytes from a0 (arg0 at entry) +0x7284.
  The `lw` at 0x7858 loads 4 bytes from a0 (arg0 at entry) +0x7280.
  The `lw` at 0x785c loads 4 bytes from a0 (arg0 at entry) +0x727c.
  The `lw` at 0x7860 loads 4 bytes from a0 (arg0 at entry) +0x7278.
  The `lw` at 0x786c loads 4 bytes from a0 (arg0 at entry) +0x7294.
  The `lw` at 0x7870 loads 4 bytes from a0 (arg0 at entry) +0x7290.
  The `lw` at 0x7874 loads 4 bytes from a0 (arg0 at entry) +0x728c.
  The `lw` at 0x7878 loads 4 bytes from a0 (arg0 at entry) +0x7288.
  The `lw` at 0x7884 loads 4 bytes from a0 (arg0 at entry) +0x729c.
  The `lw` at 0x7888 loads 4 bytes from a0 (arg0 at entry) +0x7298.
  The `lw` at 0x788c loads 4 bytes from a0 (arg0 at entry) +0x72a4.
  The `lw` at 0x7890 loads 4 bytes from a0 (arg0 at entry) +0x72a0.
  The `lw` at 0x789c loads 4 bytes from a0 (arg0 at entry) +0x7270.
  The `lw` at 0x78a0 loads 4 bytes from a0 (arg0 at entry) +0x726c.
  The `lw` at 0x78a4 loads 4 bytes from a0 (arg0 at entry) +0x7268.
  The `lw` at 0x78a8 loads 4 bytes from a0 (arg0 at entry) +0x7264.
  The `lw` at 0x78ac loads 4 bytes from a0 (arg0 at entry) +0x7274.
  The `lw` at 0x78b8 loads 4 bytes from a0 (arg0 at entry) +0x72d8.
  The `lw` at 0x78bc loads 4 bytes from a0 (arg0 at entry) +0x72d4.
  The `lw` at 0x78c0 loads 4 bytes from a0 (arg0 at entry) +0x72d0.
  The `lw` at 0x78c4 loads 4 bytes from a0 (arg0 at entry) +0x72cc.
  The `ld` at 0x78d0 loads 8 bytes from a0 (arg0 at entry) +0x72e0.
  The `ld` at 0x78d4 loads 8 bytes from a0 (arg0 at entry) +0x72e8.
  The `lw` at 0x78d8 loads 4 bytes from a0 (arg0 at entry) +0x72f0.
  The `lbu` at 0x78e4 loads 1 byte from a0 (arg0 at entry) +0x7309.
  The `lbu` at 0x78e8 loads 1 byte from a0 (arg0 at entry) +0x7303.
  The `jal` at 0x7704 calls qprintf with a0=sym(.rodata), a1=[a0+560], a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x7714 calls qprintf with a0=sym(.rodata), a1=[a0+584], a2=[a0+588], a3=?.
  The `jal` at 0x7724 calls qprintf with a0=sym(.rodata), a1=[a0+592], a2=[a0+596], a3=?.
  The `jal` at 0x7734 calls qprintf with a0=sym(.rodata), a1=[a0+600], a2=[a0+604], a3=?.
  The `jal` at 0x7744 calls qprintf with a0=sym(.rodata), a1=[a0+608], a2=[a0+612], a3=?.
  The `jal` at 0x7754 calls qprintf with a0=sym(.rodata), a1=[a0+616], a2=[a0+620], a3=?.
  The `jal` at 0x7764 calls qprintf with a0=sym(.rodata), a1=[a0+624], a2=[a0+628], a3=?.
  The `jal` at 0x7774 calls qprintf with a0=sym(.rodata), a1=[a0+632], a2=[a0+636], a3=?.
  The `jal` at 0x7784 calls qprintf with a0=sym(.rodata), a1=[a0+640], a2=[a0+644], a3=?.
  The `jal` at 0x7790 calls qprintf with a0=sym(.rodata), a1=[a0+648], a2=?, a3=?.
  The `jal` at 0x77a0 calls qprintf with a0=sym(.rodata), a1=[a0+652], a2=[a0+656], a3=?.
  The `jal` at 0x77b0 calls qprintf with a0=sym(.rodata), a1=[a0+660], a2=[a0+664], a3=?.
  The `jal` at 0x77c0 calls qprintf with a0=sym(.rodata), a1=[a0+668], a2=[a0+672], a3=?.
  The `jal` at 0x77d0 calls qprintf with a0=sym(.rodata), a1=[a0+676], a2=[a0+680], a3=?.
  The `jal` at 0x77e0 calls qprintf with a0=sym(.rodata), a1=[a0+684], a2=[a0+688], a3=?.
  The `jal` at 0x77f0 calls qprintf with a0=sym(.rodata), a1=[a0+692], a2=[a0+696], a3=?.
  The `jal` at 0x7804 calls qprintf with a0=sym(.rodata), a1=[a0+700], a2=[a0+704], a3=[a0+708].
  The `jal` at 0x780c calls qprintf with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jal` at 0x781c calls qprintf with a0=sym(.rodata), a1=[a0+29260], a2=[a0+29256], a3=?.
  The `jal` at 0x782c calls qprintf with a0=sym(.rodata), a1=[a0+29264], a2=[a0+29272], a3=?.
  The `jal` at 0x783c calls qprintf with a0=sym(.rodata), a1=[a0+29268], a2=[a0+29276], a3=?.
  The `jal` at 0x784c calls qprintf with a0=sym(.rodata), a1=[a0+29252], a2=[a0+29248], a3=?.
  The `jal` at 0x7864 calls qprintf with a0=sym(.rodata), a1=[a0+29304], a2=[a0+29308], a3=[a0+29312], a4=[a0+29316].
  The `jal` at 0x787c calls qprintf with a0=sym(.rodata), a1=[a0+29320], a2=[a0+29324], a3=[a0+29328], a4=[a0+29332].
  The `jal` at 0x7894 calls qprintf with a0=sym(.rodata), a1=[a0+29344], a2=[a0+29348], a3=[a0+29336], a4=[a0+29340].
  The `jal` at 0x78b0 calls qprintf with a0=sym(.rodata), a1=[a0+29300], a2=[a0+29284], a3=[a0+29288], a4=[a0+29292], a5=[a0+29296].
  The `jal` at 0x78c8 calls qprintf with a0=sym(.rodata), a1=[a0+29388], a2=[a0+29392], a3=[a0+29396], a4=[a0+29400].
  The `jal` at 0x78dc calls qprintf with a0=sym(.rodata), a1=[a0+29424], a2=[a0+29416]:8, a3=[a0+29408]:8.
  The `jal` at 0x78ec calls qprintf with a0=sym(.rodata), a1=[a0+29443]:1, a2=[a0+29449]:1, a3=?.
  The `jal` at 0x78f8 calls qprintf with a0=sym(.rodata), a1=a0+29000, a2=?, a3=?.
  The `jal` at 0x7904 calls qprintf with a0=sym(.rodata), a1=a0+29144, a2=?, a3=?.
  The return at 0x7918 has v0 = ret(qprintf).

- `kdsp_idbg_rad_dump_cg` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x7920 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x7920-0x7998 (120 bytes).
  It occupies 120 bytes.
  The `ld` at 0x7948 loads 8 bytes from a0 (arg0 at entry) +0x200.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x1f0, including `ld` at 0x794c, `ld` at 0x7958.
  The `lw` at 0x7970 loads 4 bytes from a0 (arg0 at entry) +0x220.
  The `lw` at 0x7974 loads 4 bytes from a0 (arg0 at entry) +0x20c.
  The `lw` at 0x7984 loads 4 bytes from a0 (arg0 at entry) +0x208.
  The `jal` at 0x7934 calls qprintf with a0=sym(.rodata), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x793c calls kdsp_idbg_dump_clockgen with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x7950 calls qprintf with a0=sym(.rodata), a1=[a0+496]:8, a2=[a0+512]:8, a3=?.
  The `jal` at 0x7980 calls qprintf with a0=sym(.rodata), a1=?, a2=[a0+520], a3=[a0+524], a4=[a0+544].
  The return at 0x7990 has v0 = ret(qprintf).

- `kdsp_idbg_rad_dump_device` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x7998 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x7998-0x7a08 (112 bytes).
  It occupies 112 bytes.
  The `lw` at 0x79bc loads 4 bytes from a0 (arg0 at entry) +0x2c4.
  The `lw` at 0x79c4 loads 4 bytes from a0 (arg0 at entry) +0x2c0.
  The `ld` at 0x79d0 loads 8 bytes from a0 (arg0 at entry) +0x300.
  The `ld` at 0x79d4 loads 8 bytes from a0 (arg0 at entry) +0x2f8.
  The `lw` at 0x79e0 loads 4 bytes from a0 (arg0 at entry) +0x314.
  The `lw` at 0x79e4 loads 4 bytes from a0 (arg0 at entry) +0x310.
  The `ld` at 0x79e8 loads 8 bytes from a0 (arg0 at entry) +0x308.
  The `jal` at 0x79a8 calls kdsp_idbg_dump_device with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x79b4 calls qprintf with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jal` at 0x79c8 calls qprintf with a0=sym(.rodata), a1=[a0+704], a2=[a0+708], a3=[a0+708].
  The `jal` at 0x79d8 calls qprintf with a0=sym(.rodata), a1=[a0+760]:8, a2=[a0+768]:8, a3=?.
  The `jal` at 0x79ec calls qprintf with a0=sym(.rodata), a1=[a0+776]:8, a2=[a0+784], a3=[a0+788].
  The return at 0x7a00 has v0 = ret(qprintf).

- `kdsp_idbg_rad_addfuncs` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x7a08 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x7a08-0x7a94 (140 bytes).
  It occupies 140 bytes.
  The `jal` at 0x7a3c calls idbg_addfunc with a0=sym(.rodata), a1=sym(kdsp_idbg_rad_dump_subsys), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x7a58 calls idbg_addfunc with a0=sym(.rodata), a1=sym(kdsp_idbg_rad_dump_device), a2=?, a3=?.
  The `jal` at 0x7a74 calls idbg_addfunc with a0=sym(.rodata), a1=sym(kdsp_idbg_rad_dump_cg), a2=?, a3=?.
  The `bne` branch at 0x7a1c targets 0x7a34, is taken when v0(=[sym(.sdata)+52]) < 0x1 (signed), and falls through when v0(=[sym(.sdata)+52]) >= 0x1 (signed).
  The `beq` branch at 0x7a44 targets 0x7a54, is taken when v0(=ret(idbg_addfunc)) == 0, and falls through when v0(=ret(idbg_addfunc)) != 0.
  The `beq` branch at 0x7a4c targets 0x7a2c and is always taken.
  The `beq` branch at 0x7a60 targets 0x7a70, is taken when v0(=ret(idbg_addfunc)) == 0, and falls through when v0(=ret(idbg_addfunc)) != 0.
  The `beq` branch at 0x7a68 targets 0x7a2c and is always taken.
  The `beq` branch at 0x7a7c targets 0x7a8c, is taken when v0(=ret(idbg_addfunc)) == 0, and falls through when v0(=ret(idbg_addfunc)) != 0.
  The `beq` branch at 0x7a84 targets 0x7a2c and is always taken.
  The `beq` branch at 0x7a8c targets 0x7a28 and is always taken.
  The return at 0x7a2c has v0 = one of 0x0, ret(idbg_addfunc).

- `kdsp_idbg_rad_delfuncs` in `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o` at 0x7a94 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/rad_dd.o`.
  Range: 0x7a94-0x7ad4 (64 bytes).
  It occupies 64 bytes.
  The `jal` at 0x7ab4 calls idbg_delfunc with a0=sym(kdsp_idbg_rad_dump_subsys), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x7abc calls idbg_delfunc with a0=sym(kdsp_idbg_rad_dump_cg), a1=?, a2=?, a3=?.
  The `jal` at 0x7ac4 calls idbg_delfunc with a0=sym(kdsp_idbg_rad_dump_device), a1=?, a2=?, a3=?.
  The `blez` branch at 0x7aa4 targets 0x7ab4, is taken when at(=[sym(.sdata)+52]-1) <= 0 (signed), and falls through when at(=[sym(.sdata)+52]-1) > 0 (signed).
  The `beq` branch at 0x7acc targets 0x7aac and is always taken.
  The return at 0x7aac has v0 = one of ?, ret(idbg_delfunc).
