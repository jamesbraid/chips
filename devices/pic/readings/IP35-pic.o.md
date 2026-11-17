# Readings: `IP35/usr/cpu/sysgen/IP35boot/pic.o`

One entry per routine, filed here from the reading batches by binary.

- `pic_init` in `IP35/usr/cpu/sysgen/IP35boot/pic.o` at 0x0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pic.o`.
  Range: 0x0-0x3c (60 bytes).
  It occupies 60 bytes.
  The `jal` at 0x10 calls pcibr_debug with a0=0x1, a1=0x0, a2=sym(.rodata), a3=a3 at entry (arg3).
  The `jal` at 0x28 calls xwidget_driver_register with a0=0xd102, a1=0x24, a2=sym(.rodata), a3=0x0.
  The return at 0x34 has v0 = ret(xwidget_driver_register).

- `pic_bus1_inventory_dup` in `IP35/usr/cpu/sysgen/IP35boot/pic.o` at 0x3c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pic.o`.
  Range: 0x3c-0xe8 (172 bytes).
  It occupies 172 bytes.
  The `jal` at 0x54 calls hwgraph_info_get_LBL with a0=a0 at entry (arg0), a1=sym(.rodata), a2=sp-48, a3=a3 at entry (arg3).
  The `jal` at 0x68 calls kmem_zalloc with a0=0x20, a1=0x0, a2=?, a3=?.
  The `jal` at 0x7c calls bcopy with a0=?, a1=ret(kmem_zalloc), a2=0x20, a3=?.
  The `jal` at 0x90 calls hwgraph_info_add_LBL with a0=a1 at entry (arg1), a1=sym(.rodata), a2=ret(kmem_zalloc), a3=?.
  The `jal` at 0xa0 calls kmem_free with a0=ret(kmem_zalloc), a1=0x20, a2=?, a3=?.
  The `jal` at 0xd8 calls cmn_err with a0=0x4, a1=sym(.rodata), a2=?, a3=?.
  The `bne` branch at 0x5c targets 0xc4, is taken when v0(=ret(hwgraph_info_get_LBL)) != 0, and falls through when v0(=ret(hwgraph_info_get_LBL)) == 0.
  The `beq` branch at 0x98 targets 0xbc, is taken when v0(=ret(hwgraph_info_add_LBL)) == 0, and falls through when v0(=ret(hwgraph_info_add_LBL)) != 0.
  The `beq` branch at 0xbc targets 0xac and is always taken.
  The `beq` branch at 0xe0 targets 0xac and is always taken.
  The return at 0xb4 has v0 = one of 0x0, 0x1.

- `pic_bus1_widget_info_dup` in `IP35/usr/cpu/sysgen/IP35boot/pic.o` at 0xe8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pic.o`.
  Range: 0xe8-0x260 (376 bytes).
  It occupies 376 bytes.
  The `ld` at 0xf4 loads 8 bytes from abs 0xffffffffffffc400.
  The `ld` at 0xf8 loads 8 bytes from [-0x3c00]:8 +0x0.
  The `ld` at 0x10c loads 8 bytes from ([[-0x3c00]:8]:8 + (a2 << 0x3)) +0x0.
  The `lw` at 0x128 loads 4 bytes from [([[-0x3c00]:8]:8 + (a2 << 0x3))]:8 +0x8c80.
  The `sw` at 0x188 stores 4 bytes to ret(kmem_zalloc) +0x8.
  The `sd` at 0x190 stores 8 bytes to ret(kmem_zalloc) +0x0.
  2 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x19c, `lbu` at 0x1ac.
  The `sw` at 0x1a0 stores 4 bytes to ret(kmem_zalloc) +0x1c.
  The `sb` at 0x1a4 stores 1 byte to ret(kmem_zalloc) +0xc.
  The `sb` at 0x1b0 stores 1 byte to ret(kmem_zalloc) +0x20.
  3 such `lw` accesses load 4 bytes from ?, including `lw` at 0x1b8, `lw` at 0x1c0, `lw` at 0x1c8.
  The `sw` at 0x1bc stores 4 bytes to ret(kmem_zalloc) +0x10.
  The `sw` at 0x1c4 stores 4 bytes to ret(kmem_zalloc) +0x14.
  The `sd` at 0x1cc stores 8 bytes to ret(kmem_zalloc) +0x28.
  The `sd` at 0x1d4 stores 8 bytes to ret(kmem_zalloc) +0x30.
  The `sw` at 0x1e0 stores 4 bytes to ret(kmem_zalloc) +0x18.
  The `sd` at 0x1f4 stores 8 bytes to ret(kmem_zalloc) +0x38.
  The `jal` at 0x138 calls hwgraph_info_get_LBL with a0=[[([[-0x3c00]:8]:8 + (a2 << 0x3))]:8+35968], a1=sym(.rodata), a2=sp-64, a3=[[-0x3c00]:8]:8.
  The `jal` at 0x170 calls hwgraph_info_get_LBL with a0=a0 at entry (arg0), a1=sym(.rodata), a2=sp-56, a3=?.
  The `jal` at 0x180 calls kmem_zalloc with a0=0x40, a1=0x0, a2=?, a3=?.
  The `jal` at 0x1dc calls strlen with a0=a3 at entry (arg3), a1=?, a2=?, a3=?.
  The `jal` at 0x1e8 calls kmem_alloc with a0=ret(strlen)+1, a1=0x0, a2=?, a3=?.
  The `jal` at 0x1f8 calls strcpy with a0=ret(kmem_alloc), a1=a3 at entry (arg3), a2=?, a3=?.
  The `jal` at 0x20c calls hwgraph_info_add_LBL with a0=a1 at entry (arg1), a1=sym(.rodata), a2=ret(kmem_zalloc), a3=?.
  The `jal` at 0x220 calls kmem_free with a0=ret(kmem_zalloc), a1=0x40, a2=?, a3=?.
  The `jal` at 0x230 calls xwidget_info_set with a0=a1 at entry (arg1), a1=ret(kmem_zalloc), a2=?, a3=?.
  The `jal` at 0x250 calls cmn_err with a0=0x4, a1=sym(.rodata), a2=?, a3=?.
  The `bne` branch at 0x144 targets 0x164, is taken when a4(?) != 0, and falls through when a4(?) == 0.
  The `bne` branch at 0x178 targets 0x240, is taken when v0(=ret(hwgraph_info_get_LBL)) != 0, and falls through when v0(=ret(hwgraph_info_get_LBL)) == 0.
  The `beq` branch at 0x214 targets 0x230, is taken when v0(=ret(hwgraph_info_add_LBL)) == 0, and falls through when v0(=ret(hwgraph_info_add_LBL)) != 0.
  The `beq` branch at 0x228 targets 0x14c and is always taken.
  The `beq` branch at 0x238 targets 0x14c and is always taken.
  The `beq` branch at 0x258 targets 0x14c and is always taken.
  The return at 0x15c has v0 = one of 0x0, 0x1.

- `pic_bus1_device_desc_dup` in `IP35/usr/cpu/sysgen/IP35boot/pic.o` at 0x260 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pic.o`.
  Range: 0x260-0x290 (48 bytes).
  It occupies 48 bytes.
  The `jal` at 0x26c calls device_desc_dup with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x278 calls device_desc_default_set with a0=a1 at entry (arg1), a1=ret(device_desc_dup), a2=?, a3=?.
  The return at 0x288 has v0 = ret(device_desc_default_set).

- `pic_bus1_redist` in `IP35/usr/cpu/sysgen/IP35boot/pic.o` at 0x290 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pic.o`.
  Range: 0x290-0x42c (412 bytes).
  It occupies 412 bytes.
  2 such `ld` accesses load 8 bytes from abs 0xffffffffffffc400, including `ld` at 0x298, `ld` at 0x2fc.
  The `lh` at 0x2a0 loads 2 bytes from (sym(nasid_to_compact_node) + (a0 + a0)) +0x0.
  2 such `ld` accesses load 8 bytes from [-0x3c00]:8 +0x0, including `ld` at 0x2a4, `ld` at 0x300.
  The `ld` at 0x2b0 loads 8 bytes from ([[-0x3c00]:8]:8 + ([(sym(nasid_to_compact_node) + (a0 + a0))]:2 << 0x3)) +0x0.
  The `lh` at 0x2c0 loads 2 bytes from [([[-0x3c00]:8]:8 + ([(sym(nasid_to_compact_node) + (a0 + a0))]:2 << 0x3))]:8 +0x8600.
  The `lh` at 0x2f0 loads 2 bytes from (sym(nasid_to_compact_node) + ([[([[-0x3c00]:8]:8 + ([(sym(nasid_to_compact_node) + (a0 + a0))]:2 << 0x3))]:8+34304]:2 + [[([[-0x3c00]:8]:8 + ([(sym(nasid_to_compact_node) + (a0 + a0))]:2 << 0x3))]:8+34304]:2)) +0x0.
  The `ld` at 0x30c loads 8 bytes from ?.
  The `lh` at 0x32c loads 2 bytes from table(0x861a) +0x0.
  The `jal` at 0x2f4 calls sprintf with a0=sp-544, a1=sym(.rodata), a2=a1 at entry (arg1), a3=a3 at entry (arg3), a5=sym(nasid_to_compact_node).
  The `jal` at 0x328 calls sprintf with a0=sp-288, a1=sym(.rodata), a2=entry(0x861a), a3=sp-526.
  The `jal` at 0x338 calls hwgraph_traverse with a0=[sym(hwgraph_root)], a1=sp-288, a2=sp-32, a3=?.
  The `jal` at 0x354 calls hwgraph_path_add with a0=[sym(hwgraph_root)], a1=sp-288, a2=sp-32, a3=?.
  The `jal` at 0x370 calls pcibr_debug with a0=0x4, a1=a1 at entry (arg1), a2=sym(.rodata), a3=?, a6=sym(.rodata).
  The `jal` at 0x37c calls pic_bus1_inventory_dup with a0=a1 at entry (arg1), a1=?, a2=?, a3=?.
  The `jal` at 0x390 calls pic_bus1_device_desc_dup with a0=a1 at entry (arg1), a1=?, a2=?, a3=?.
  The `jal` at 0x3a4 calls pic_bus1_widget_info_dup with a0=a1 at entry (arg1), a1=?, a2=?, a3=sp-288.
  The `jal` at 0x3e8 calls cmn_err with a0=0x4, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x404 calls cmn_err with a0=0x4, a1=sym(.rodata), a2=ret(hwgraph_traverse), a3=?.
  The `jal` at 0x41c calls cmn_err with a0=0x4, a1=sym(.rodata), a2=ret(hwgraph_path_add), a3=?, a6=sym(.rodata).
  The `beq` branch at 0x2d4 targets 0x3cc, is taken when v0(=[[([[-0x3c00]:8]:8 + ([(sym(nasid_to_compact_node) + (a0 + a0))]:2 << 0x3))]:8+34304]:2) == at(=-0x1), and falls through when v0(=[[([[-0x3c00]:8]:8 + ([(sym(nasid_to_compact_node) + (a0 + a0))]:2 << 0x3))]:8+34304]:2) != at(=-0x1).
  The `beq` branch at 0x340 targets 0x3dc, is taken when v0(=ret(hwgraph_traverse)) == 0, and falls through when v0(=ret(hwgraph_traverse)) != 0.
  The `bne` branch at 0x348 targets 0x3f8, is taken when v0(=ret(hwgraph_traverse)) != a0(=0x2), and falls through when v0(=ret(hwgraph_traverse)) == a0(=0x2).
  The `bne` branch at 0x35c targets 0x414, is taken when v0(=ret(hwgraph_path_add)) != 0, and falls through when v0(=ret(hwgraph_path_add)) == 0.
  The `beq` branch at 0x384 targets 0x3d4, is taken when v0(=ret(pic_bus1_inventory_dup)) == 0, and falls through when v0(=ret(pic_bus1_inventory_dup)) != 0.
  The `beq` branch at 0x3cc targets 0x3b4 and is always taken.
  The `beq` branch at 0x3d4 targets 0x3b8 and is always taken.
  The `beq` branch at 0x3f0 targets 0x3cc and is always taken.
  The `beq` branch at 0x40c targets 0x3cc and is always taken.
  The `beq` branch at 0x424 targets 0x3cc and is always taken.
  The return at 0x3c4 has v0 = one of ?, 0x0.

- `pic_attach` in `IP35/usr/cpu/sysgen/IP35boot/pic.o` at 0x42c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pic.o`.
  Range: 0x42c-0x64c (544 bytes).
  It occupies 544 bytes.
  2 such `ld` accesses load 8 bytes from ret(xwidget_info_get) +0x28, including `ld` at 0x59c, `ld` at 0x5a8.
  The `sd` at 0x5ac stores 8 bytes to ret(xwidget_info_get) +0x28.
  The `ld` at 0x5b0 loads 8 bytes from ret(xwidget_info_get) +0x30.
  The `sd` at 0x5bc stores 8 bytes to ret(xwidget_info_get) +0x30.
  2 such `sd` accesses store 8 bytes to ?, including `sd` at 0x5d8, `sd` at 0x5e4.
  The `jal` at 0x448 calls pcibr_debug with a0=0x4, a1=a0 at entry (arg0), a2=sym(.rodata), a3=a3 at entry (arg3).
  The `jal` at 0x458 calls pcibr_bridge_ptr_get with a0=a0 at entry (arg0), a1=0x0, a2=?, a3=?.
  The `jal` at 0x468 calls pcibr_bridge_ptr_get with a0=a0 at entry (arg0), a1=0x1, a2=?, a3=?.
  The `jal` at 0x48c calls pcibr_debug with a0=0x4, a1=a0 at entry (arg0), a2=sym(.rodata), a3=ret(pcibr_bridge_ptr_get), a4=ret(pcibr_bridge_ptr_get).
  The `jal` at 0x4ac calls pic_bus1_redist with a0=?, a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0x4c0 calls iobrick_l1type_get_nasid with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x4e4 calls hwgraph_path_add with a0=a0 at entry (arg0), a1=sym(.rodata), a2=sp-80, a3=?.
  The `jal` at 0x500 calls hwgraph_path_add with a0=?, a1=sym(.rodata), a2=sp-76, a3=?.
  The `jal` at 0x520 calls pcibr_debug with a0=0x4, a1=a0 at entry (arg0), a2=sym(.rodata), a3=?.
  The `jal` at 0x52c calls pciio_provider_register with a0=?, a1=sym(pci_pic_provider), a2=?, a3=?.
  The `jal` at 0x538 calls pciio_provider_register with a0=?, a1=sym(pci_pic_provider), a2=?, a3=?.
  The `jal` at 0x540 calls pciio_provider_startup with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x548 calls pciio_provider_startup with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x560 calls pic_attach2 with a0=a0 at entry (arg0), a1=ret(pcibr_bridge_ptr_get), a2=?, a3=0x0, a4=sp-72.
  The `jal` at 0x578 calls pic_attach2 with a0=?, a1=?, a2=?, a3=0x1, a4=sp-64.
  The `jal` at 0x588 calls xwidget_info_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x594 calls xwidget_info_get with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x5f8 calls pcibr_debug with a0=0x4, a1=a0 at entry (arg0), a2=sym(.rodata), a3=?.
  The `jal` at 0x620 calls hwgraph_path_add with a0=a0 at entry (arg0), a1=sym(.rodata), a2=sp-80, a3=?.
  The `jal` at 0x63c calls hwgraph_path_add with a0=?, a1=sym(.rodata), a2=sp-76, a3=?.
  The `beq` branch at 0x4cc targets 0x614, is taken when v0(=ret(iobrick_l1type_get_nasid)) == a2(=0x56), and falls through when v0(=ret(iobrick_l1type_get_nasid)) != a2(=0x56).
  The `beq` branch at 0x4d4 targets 0x614, is taken when v0(=ret(iobrick_l1type_get_nasid)) == a0(=0x30), and falls through when v0(=ret(iobrick_l1type_get_nasid)) != a0(=0x30).
  The `beq` branch at 0x580 targets 0x5c0, is taken when s2(?) == s0(=a0), and falls through when s2(?) != s0(=a0).
  The `bne` branch at 0x5a0 targets 0x5b0, is taken when a3(=[ret(xwidget_info_get)+40]:8) != 0, and falls through when a3(=[ret(xwidget_info_get)+40]:8) == 0.
  The `bne` branch at 0x5b4 targets 0x5c0, is taken when a5(=[ret(xwidget_info_get)+48]:8) != 0, and falls through when a5(=[ret(xwidget_info_get)+48]:8) == 0.
  The `beq` branch at 0x644 targets 0x50c and is always taken.
  The return at 0x60c has v0 = 0x0.

- `pic_attach2` in `IP35/usr/cpu/sysgen/IP35boot/pic.o` at 0x64c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pic.o`.
  Range: 0x64c-0x1318 (3276 bytes).
  It occupies 3276 bytes.
  The `lw` at 0x764 loads 4 bytes from ret(pcibr_hints_get) +0xc.
  The `sw` at 0x7bc stores 4 bytes to ret(kmem_zalloc) +0x10.
  2 such `sd` accesses store 8 bytes to ret(kmem_zalloc) +0x8, including `sd` at 0x7c0, `sd` at 0x86c.
  2 such `sd` accesses store 8 bytes to ret(kmem_zalloc) +0x0, including `sd` at 0x7d8, `sd` at 0x7e4.
  The `sd` at 0x7e8 stores 8 bytes to a4 (arg4 at entry) +0x0.
  The `sd` at 0x834 stores 8 bytes to ret(kmem_zalloc) +0x10.
  The `sh` at 0x844 stores 2 bytes to ret(kmem_zalloc) +0x70.
  The `sh` at 0x84c stores 2 bytes to ret(kmem_zalloc) +0x72.
  The `sw` at 0x854 stores 4 bytes to ret(kmem_zalloc) +0xab8.
  The `sw` at 0x858 stores 4 bytes to ret(kmem_zalloc) +0x48.
  The `sb` at 0x860 stores 1 byte to ret(kmem_zalloc) +0x39.
  The `sb` at 0x864 stores 1 byte to ret(kmem_zalloc) +0x38.
  2 such `sd` accesses store 8 bytes to ret(kmem_zalloc) +0x830, including `sd` at 0x868, `sd` at 0xc50.
  The `sw` at 0x870 stores 4 bytes to ret(kmem_zalloc) +0x4.
  The `sw` at 0x874 stores 4 bytes to ret(kmem_zalloc) +0x0.
  The `sw` at 0x880 stores 4 bytes to ret(kmem_zalloc) +0x78.
  2 such `sd` accesses store 8 bytes to ret(kmem_zalloc) +0x508, including `sd` at 0x88c, `sd` at 0x1034.
  The `sh` at 0x8a8 stores 2 bytes to ret(kmem_zalloc) +0x74.
  The `sb` at 0x8c0 stores 1 byte to ret(kmem_zalloc) +0x28.
  The `sw` at 0x8cc stores 4 bytes to ret(kmem_zalloc) +0x2c.
  4 such `lh` accesses load 2 bytes from ret(kmem_zalloc) +0x74, including `lh` at 0x8d8, `lh` at 0xce8, `lh` at 0xe40.
  The `sb` at 0x8e4 stores 1 byte to ret(kmem_zalloc) +0x30.
  The `lw` at 0x8f0 loads 4 bytes from sym(.rodata) +0x430.
  The `sw` at 0x8fc stores 4 bytes to ret(kmem_zalloc) +0x18.
  4 such `lw` accesses load 4 bytes from ret(kmem_zalloc) +0x78, including `lw` at 0x900, `lw` at 0xb7c, `lw` at 0x10d0.
  11 such `sd` accesses store 8 bytes to ?, including `sd` at 0x954, `sd` at 0x958, `sd` at 0x95c.
  2 such `lbu` accesses load 1 byte from ret(kmem_zalloc) +0x28, including `lbu` at 0x998, `lbu` at 0x9c8.
  The `sd` at 0x9a0 stores 8 bytes to ret(kmem_zalloc) +0x80.
  The `sh` at 0x9bc stores 2 bytes to ret(kmem_zalloc) +0x8a.
  3 such `lh` accesses load 2 bytes from ret(kmem_zalloc) +0x8a, including `lh` at 0x9cc, `lh` at 0xee8, `lh` at 0x12ec.
  The `sh` at 0x9d4 stores 2 bytes to ret(kmem_zalloc) +0x88.
  2 such `ld` accesses load 8 bytes from (sym(.rodata) + ([ret(kmem_zalloc)+138]:2-35 << 0x3)) +0x0, including `ld` at 0x9f8, `ld` at 0xf0c.
  2 such `lbu` accesses load 1 byte from ret(kmem_zalloc) +0x32, including `lbu` at 0xa70, `lbu` at 0xed8.
  2 such `lbu` accesses load 1 byte from ret(kmem_zalloc) +0x31, including `lbu` at 0xa7c, `lbu` at 0xee4.
  14 such `lbu` accesses load 1 byte from ret(kmem_zalloc) +0x39, including `lbu` at 0xab0, `lbu` at 0xaf8, `lbu` at 0xda4.
  11 such `lbu` accesses load 1 byte from ret(kmem_zalloc) +0x38, including `lbu` at 0xab4, `lbu` at 0xda0, `lbu` at 0xde0.
  9 such `sw` accesses store 4 bytes to ?, including `sw` at 0xad8, `sw` at 0xadc, `sw` at 0xaf0.
  3 such `lh` accesses load 2 bytes from ret(kmem_zalloc) +0x70, including `lh` at 0xbc4, `lh` at 0xbe0, `lh` at 0xbfc.
  The `sd` at 0xc0c stores 8 bytes to ret(kmem_zalloc) +0x60.
  2 such `lh` accesses load 2 bytes from ret(kmem_zalloc) +0x72, including `lh` at 0xcac, `lh` at 0xcdc.
  2 such `sw` accesses store 4 bytes to ret(kmem_zalloc) +0x7c, including `sw` at 0xcf4, `sw` at 0xcfc.
  The `sd` at 0xdb0 stores 8 bytes to ret(kmem_zalloc) +0x100.
  The `sw` at 0xdb4 stores 4 bytes to ret(kmem_zalloc) +0xf8.
  The `sw` at 0xe50 stores 4 bytes to ret(kmem_zalloc) +0x520.
  The `sw` at 0xe54 stores 4 bytes to ret(kmem_zalloc) +0x51c.
  The `sw` at 0xe6c stores 4 bytes to ret(kmem_zalloc) +0x518.
  The `lw` at 0xed4 loads 4 bytes from ret(kmem_zalloc) +0x4.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0xf90, `ld` at 0xf94.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0xf98, `lw` at 0xfa4.
  The `lw` at 0x1020 loads 4 bytes from ret(pcibr_hints_get) +0x8.
  The `sw` at 0x1024 stores 4 bytes to ret(kmem_zalloc) +0x524.
  The `ld` at 0x1028 loads 8 bytes from ret(pcibr_hints_get) +0x18.
  2 such `sb` accesses store 1 byte to ?, including `sb` at 0x1078, `sb` at 0x10b0.
  The `lbu` at 0x109c loads 1 byte from ?.
  2 such `ld` accesses load 8 bytes from ret(kmem_zalloc) +0x10, including `ld` at 0x12dc, `ld` at 0x12f4.
  The `lbu` at 0x1314 loads 1 byte from ([ret(kmem_zalloc)+56]:1 + ret(pcibr_hints_get)) +0x0.
  The `jal` at 0x690 calls pcibr_debug with a0=0x4, a1=a2 at entry (arg2), a2=sym(.rodata), a3=a1 at entry (arg1), a4=a3 at entry (arg3).
  The `jal` at 0x69c calls async_attach_get_info with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x6b8 calls hwgraph_char_device_add with a0=a2 at entry (arg2), a1=sym(.rodata), a2=sym(.rodata), a3=sp-400.
  The `jal` at 0x6c0 calls pcireg_id_get with a0=a1 at entry (arg1), a1=?, a2=?, a3=?.
  The `jal` at 0x6e8 calls hwgraph_info_add_LBL with a0=a2 at entry (arg2), a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x6f4 calls pcireg_nic_addr with a0=a1 at entry (arg1), a1=?, a2=?, a3=?.
  The `jal` at 0x700 calls pcireg_nic_addr with a0=a1 at entry (arg1), a1=?, a2=?, a3=?.
  The `jal` at 0x714 calls is_iobrick with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x724 calls pcireg_nic_addr with a0=a1 at entry (arg1), a1=?, a2=?, a3=?.
  The `jal` at 0x744 calls eeprom_vertex_info_set with a0=0x400, a1=?, a2=a0 at entry (arg0), a3=0x0.
  The `jal` at 0x754 calls pcibr_hints_get with a0=a0 at entry (arg0), a1=0x0, a2=?, a3=?.
  The `jal` at 0x7a4 calls kmem_zalloc with a0=0xac0, a1=0x0, a2=?, a3=?.
  The `jal` at 0x7b4 calls kmem_zalloc with a0=0x18, a1=0x0, a2=?, a3=?.
  The `jal` at 0x7d4 calls swap_ptr with a0=sym(pcibr_list), a1=ret(kmem_zalloc), a2=?, a3=?, a6=[sym(pcibr_list)]:8.
  The `jal` at 0x7f4 calls memset with a0=ret(kmem_zalloc), a1=0x0, a2=0xac0, a3=?, a7=a4 at entry (arg4).
  The `jal` at 0x800 calls hwgraph_fastinfo_set with a0=a2 at entry (arg2), a1=ret(kmem_zalloc), a2=?, a3=?.
  The `jal` at 0x810 calls dev_to_name with a0=a2 at entry (arg2), a1=sp-392, a2=0x100, a3=?.
  The `jal` at 0x81c calls strlen with a0=ret(dev_to_name), a1=?, a2=?, a3=?.
  The `jal` at 0x828 calls kmem_alloc with a0=ret(strlen)+1, a1=0x0, a2=?, a3=?.
  The `jal` at 0x838 calls strcpy with a0=ret(kmem_alloc), a1=ret(dev_to_name), a2=?, a3=?.
  The `jal` at 0x888 calls pcireg_mode_get with a0=ret(kmem_zalloc), a1=?, a2=?, a3=?.
  The `jal` at 0x894 calls pcireg_speed_get with a0=ret(kmem_zalloc), a1=?, a2=?, a3=?.
  The `jal` at 0x8ac calls xwidget_info_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x8b8 calls xwidget_info_id_get with a0=ret(xwidget_info_get), a1=?, a2=?, a3=?.
  The `jal` at 0x8c4 calls xwidget_info_master_get with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x8d0 calls xwidget_info_masterid_get with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x8f8 calls pcibr_debug with a0=0x4, a1=a2 at entry (arg2), a2=sym(.rodata), a3=ret(kmem_zalloc), a4=[ret(kmem_zalloc)+116]:2.
  The `jal` at 0x930 calls pcibr_debug with a0=0x4, a1=a2 at entry (arg2), a2=sym(.rodata), a3=ret(kmem_zalloc)+24, a4=sym(.rodata), a5=[ret(kmem_zalloc)+120].
  The `jal` at 0x988 calls get_elsc with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x9a8 calls iobrick_l1type_get_nasid with a0=?, a1=[ret(kmem_zalloc)+40]:1, a2=?, a3=?.
  The `jal` at 0x9c4 calls iobrick_module_get_nasid with a0=?, a1=[ret(kmem_zalloc)+40]:1, a2=?, a3=?.
  Calls (unknown callee) via register with a0=?, a1=?, a2=?, a3=[ret(kmem_zalloc)+138]:2 (`jr` at 0x9fc).
  The `jal` at 0xa04 calls pcireg_nic_addr with a0=a1 at entry (arg1), a1=?, a2=?, a3=?.
  The `jal` at 0xa10 calls nic_bridge_vertex_info with a0=a0 at entry (arg0), a1=ret(pcireg_nic_addr), a2=?, a3=?.
  The `jal` at 0xa64 calls iobrick_L1bricktype_to_name with a0=[ret(kmem_zalloc)+138]:2, a1=?, a2=?, a3=[ret(kmem_zalloc)+138]:2.
  The `jal` at 0xa80 calls pcibr_debug with a0=0x4, a1=a2 at entry (arg2), a2=sym(.rodata), a3=ret(iobrick_L1bricktype_to_name), a4=[ret(kmem_zalloc)+49]:1, a5=[ret(kmem_zalloc)+50]:1.
  The `jal` at 0xa8c calls spinlock_init with a0=ret(kmem_zalloc)+140, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0xaa0 calls mrlock_init with a0=ret(kmem_zalloc)+144, a1=0x0, a2=sym(.rodata), a3=-0x1.
  The `jal` at 0xb50 calls pcireg_intr_reset_set with a0=ret(kmem_zalloc), a1=0x7f, a2=?, a3=?.
  The `jal` at 0xb60 calls pcireg_intr_device_set with a0=ret(kmem_zalloc), a1=0x6db6db, a2=?, a3=?.
  The `jal` at 0xb68 calls pcibr_directmap_init with a0=ret(kmem_zalloc), a1=?, a2=?, a3=?.
  The `jal` at 0xb70 calls pcireg_control_get with a0=ret(kmem_zalloc), a1=?, a2=?, a3=?.
  The `jal` at 0xbbc calls pcireg_control_set with a0=ret(kmem_zalloc), a1=?, a2=?, a3=one of 0x20000000, 0xc0000000, a5=0x9fff00ffffffffff.
  The `jal` at 0xbd8 calls pcireg_int_ate_set with a0=ret(kmem_zalloc), a1=?, a2=0x0, a3=?.
  The `jal` at 0xbf4 calls rmallocmap with a0=[ret(kmem_zalloc)+112]:2, a1=?, a2=?, a3=?.
  The `jal` at 0xc08 calls pcibr_ate_free with a0=ret(kmem_zalloc), a1=0x0, a2=[ret(kmem_zalloc)+112]:2, a3=?.
  The `jal` at 0xc10 calls device_desc_dup with a0=a2 at entry (arg2), a1=?, a2=?, a3=?.
  The `jal` at 0xc1c calls device_desc_flags_get with a0=ret(device_desc_dup), a1=?, a2=?, a3=?.
  The `jal` at 0xc28 calls device_desc_flags_set with a0=ret(device_desc_dup), a1=(ret(device_desc_flags_get) | 0x1), a2=?, a3=?.
  The `jal` at 0xc34 calls device_desc_intr_name_set with a0=ret(device_desc_dup), a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0xc44 calls xtalk_intr_alloc with a0=a0 at entry (arg0), a1=ret(device_desc_dup), a2=a2 at entry (arg2), a3=?.
  The `jal` at 0xc54 calls device_desc_free with a0=ret(device_desc_dup), a1=?, a2=?, a3=?.
  The `jal` at 0xc70 calls xtalk_intr_connect with a0=?, a1=sym(pcibr_error_intr_handler), a2=ret(kmem_zalloc), a3=sym(pcibr_setwidint), a4=a1 at entry (arg1), a5=0x0.
  The `jal` at 0xc78 calls pcireg_intr_dst_target_id_get with a0=ret(kmem_zalloc), a1=?, a2=?, a3=?.
  The `jal` at 0xc84 calls pcireg_intr_dst_addr_get with a0=ret(kmem_zalloc), a1=?, a2=?, a3=?.
  The `jal` at 0xc9c calls pcibr_debug with a0=0x1000, a1=a2 at entry (arg2), a2=sym(.rodata), a3=ret(pcireg_intr_dst_target_id_get), a4=ret(pcireg_intr_dst_addr_get).
  The `jal` at 0xca4 calls pcireg_intr_enable_get with a0=ret(kmem_zalloc), a1=?, a2=?, a3=?.
  The `jal` at 0xcc0 calls pcireg_intr_enable_set with a0=ret(kmem_zalloc), a1=?, a2=?, a3=?.
  The `jal` at 0xccc calls pcireg_intr_mode_set with a0=ret(kmem_zalloc), a1=0x0, a2=?, a3=?.
  The `jal` at 0xcd4 calls pcireg_tflush_get with a0=ret(kmem_zalloc), a1=?, a2=?, a3=?.
  The `jal` at 0xd10 calls pciio_device_win_map_new with a0=ret(kmem_zalloc)+2128, a1=0x10000000, a2=0x100000, a3=?.
  The `jal` at 0xd24 calls pciio_device_win_populate with a0=ret(kmem_zalloc)+2128, a1=0x200000, a2=0xff00000, a3=?.
  The `jal` at 0xd38 calls pciio_device_win_map_new with a0=ret(kmem_zalloc)+2144, a1=0x100000, a2=0x4000, a3=?.
  The `jal` at 0xd4c calls pciio_device_win_populate with a0=ret(kmem_zalloc)+2144, a1=0x4000, a2=0xfc000, a3=?.
  The `jal` at 0xd60 calls pciio_device_win_map_new with a0=ret(kmem_zalloc)+2160, a1=0x40000000, a2=0x100000, a3=?.
  The `jal` at 0xd70 calls pciio_device_win_populate with a0=ret(kmem_zalloc)+2160, a1=0x200000, a2=0x3ff00000, a3=?.
  The `jal` at 0xd88 calls pcibr_device_info_new with a0=ret(kmem_zalloc), a1=0xff, a2=0xff, a3=-0x1, a4=-0x1.
  The `jal` at 0xd98 calls pciio_device_info_register with a0=a2 at entry (arg2), a1=ret(pcibr_device_info_new), a2=?, a3=?.
  The `jal` at 0xdc4 calls pcibr_slot_info_init with a0=a2 at entry (arg2), a1=?, a2=?, a3=?, a4=[ret(kmem_zalloc)+57]:1.
  The `jal` at 0xdf4 calls pcibr_slot_addr_space_init with a0=a2 at entry (arg2), a1=?, a2=?, a3=?, a4=[ret(kmem_zalloc)+57]:1.
  The `jal` at 0xe24 calls pcibr_slot_device_init with a0=a2 at entry (arg2), a1=?, a2=?, a3=?, a4=[ret(kmem_zalloc)+57]:1.
  The `jal` at 0xe58 calls pcibr_pcix_rbars_calc with a0=ret(kmem_zalloc), a1=?, a2=?, a3=?, a4=[ret(kmem_zalloc)+57]:1.
  The `jal` at 0xe7c calls pcibr_slot_pcix_rbar_init with a0=ret(kmem_zalloc), a1=?, a2=?, a3=?, a4=[ret(kmem_zalloc)+57]:1.
  The `jal` at 0xeb4 calls pcibr_slot_guest_info_init with a0=a2 at entry (arg2), a1=?, a2=?, a3=?.
  The `jal` at 0xed0 calls pcibr_bus_cnvlink with a0=[ret(kmem_zalloc)+4], a1=?, a2=?, a3=?.
  The `jal` at 0xee0 calls pcibr_initial_rrb with a0=a2 at entry (arg2), a1=[ret(kmem_zalloc)+49]:1, a2=[ret(kmem_zalloc)+50]:1, a3=?.
  Calls (unknown callee) via register with a0=ret(kmem_zalloc), a1=?, a2=?, a3=[ret(kmem_zalloc)+138]:2 (`jr` at 0xf10).
  The `jal` at 0xf44 calls pcibr_slot_call_device_attach with a0=a2 at entry (arg2), a1=?, a2=0x0, a3=?, a4=[ret(kmem_zalloc)+57]:1.
  The `jal` at 0xfb0 calls pcireg_timeout_bit_clr with a0=ret(kmem_zalloc), a1=0x3ff, a2=?, a3=?, a4=[ret(kmem_zalloc)+57]:1.
  The `jal` at 0xfd4 calls pciio_device_attach with a0=ret(pciio_device_info_register), a1=0x0, a2=?, a3=?.
  The `jal` at 0xff0 calls async_attach_add_info with a0=ret(pciio_device_info_register), a1=ret(async_attach_get_info), a2=?, a3=?, a4=[ret(kmem_zalloc)+57]:1.
  The `jal` at 0x1000 calls async_attach_del_info with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x1018 calls pcibr_debug with a0=0x2, a1=a2 at entry (arg2), a2=sym(.rodata), a3=ret(pcibr_hints_get).
  The `jal` at 0x10f0 calls pcireg_req_timeout_set with a0=ret(kmem_zalloc), a1=0x750, a2=?, a3=?, a5=0xffffff7ffffffdff.
  The `jal` at 0x1124 calls pcireg_rrb_bit_set with a0=ret(kmem_zalloc), a1=0x0, a2=0xf000f, a3=?.
  The `jal` at 0x1134 calls pcireg_rrb_bit_set with a0=ret(kmem_zalloc), a1=0x1, a2=0xf000f, a3=?.
  The `jal` at 0x11f8 calls xwidget_error_register with a0=a0 at entry (arg0), a1=sym(pcibr_error_handler_wrapper), a2=ret(kmem_zalloc), a3=?.
  The `jal` at 0x12e0 calls cmn_err with a0=0x4, a1=sym(.rodata), a2=[ret(kmem_zalloc)+16]:8, a3=[ret(kmem_zalloc)+138]:2.
  The `jal` at 0x12f8 calls cmn_err with a0=0x4, a1=sym(.rodata), a2=[ret(kmem_zalloc)+16]:8, a3=?.
  The `beq` branch at 0x71c targets 0xa04, is taken when v0(=ret(is_iobrick)) == 0, and falls through when v0(=ret(is_iobrick)) != 0.
  The `beq` branch at 0x75c targets 0x7a0, is taken when v0(=ret(pcibr_hints_get)) == 0, and falls through when v0(=ret(pcibr_hints_get)) != 0.
  The `beq` branch at 0x768 targets 0x7a0, is taken when a5(=[ret(pcibr_hints_get)+12]) == 0, and falls through when a5(=[ret(pcibr_hints_get)+12]) != 0.
  The `beq` branch at 0x7e0 targets 0x7ec, is taken when a7(=a4) == 0, and falls through when a7(=a4) != 0.
  The `beq` branch at 0x90c targets 0x91c, is taken when a5(=[ret(kmem_zalloc)+120]) == a0(=0xd1021), and falls through when a5(=[ret(kmem_zalloc)+120]) != a0(=0xd1021).
  The `bne` branch at 0x914 targets 0x1054, is taken when a5(=[ret(kmem_zalloc)+120]) != a1(=0xd1121), and falls through when a5(=[ret(kmem_zalloc)+120]) == a1(=0xd1121).
  The `beq` branch at 0x960 targets 0x988, is taken when a5(?) >= 0x100 (signed), and falls through when a5(?) < 0x100 (signed).
  The `bne` branch at 0x980 targets 0x940, is taken when a5(?) < 0x100 (signed), and falls through when a5(?) >= 0x100 (signed).
  The `bltz` branch at 0x9b8 targets 0x12f0, is taken when a3(?) < 0 (signed), and falls through when a3(?) >= 0 (signed).
  The `blez` branch at 0x9d0 targets 0x10c8, is taken when a3(=[ret(kmem_zalloc)+138]:2) <= 0 (signed), and falls through when a3(=[ret(kmem_zalloc)+138]:2) > 0 (signed).
  The `beq` branch at 0x9f0 targets 0x12d8, is taken when v1(=[ret(kmem_zalloc)+138]:2-35) >= 0x34 (unsigned), and falls through when v1(=[ret(kmem_zalloc)+138]:2-35) < 0x34 (unsigned).
  The `beq` branch at 0xa18 targets 0x750 and is always taken.
  The `bne` branch at 0xaa8 targets 0x1010, is taken when s5(=ret(pcibr_hints_get)) != 0, and falls through when s5(=ret(pcibr_hints_get)) == 0.
  The `bne` branch at 0xabc targets 0xb10, is taken when a4(=[ret(kmem_zalloc)+57]:1) < a5(=[ret(kmem_zalloc)+56]:1) (signed), and falls through when a4(=[ret(kmem_zalloc)+57]:1) >= a5(=[ret(kmem_zalloc)+56]:1) (signed).
  The `beq` branch at 0xb04 targets 0xad4, is taken when v1(=[ret(kmem_zalloc)+57]:1) >= a5(?) (signed), and falls through when v1(=[ret(kmem_zalloc)+57]:1) < a5(?) (signed).
  The `bne` branch at 0xb40 targets 0xb10, is taken when a0(?) < 0x8 (signed), and falls through when a0(?) >= 0x8 (signed).
  The `beq` branch at 0xb48 targets 0x11f0, is taken when s6(=a3) == 0, and falls through when s6(=a3) != 0.
  The `beq` branch at 0xba8 targets 0x10bc, is taken when (a4(?) & 0x2) == 0, and falls through when (a4(?) & 0x2) != 0.
  The `blez` branch at 0xbc8 targets 0xbf4, is taken when a0(=[ret(kmem_zalloc)+112]:2) <= 0 (signed), and falls through when a0(=[ret(kmem_zalloc)+112]:2) > 0 (signed).
  The `bne` branch at 0xbec targets 0xbd0, is taken when s5(?) < a0(=[ret(kmem_zalloc)+112]:2) (signed), and falls through when s5(?) >= a0(=[ret(kmem_zalloc)+112]:2) (signed).
  The `beq` branch at 0xcb4 targets 0x10d0, is taken when t8(=[ret(kmem_zalloc)+114]:2) == s6(=0x2), and falls through when t8(=[ret(kmem_zalloc)+114]:2) != s6(=0x2).
  The `beq` branch at 0xce0 targets 0x1100, is taken when t9(=[ret(kmem_zalloc)+114]:2) == s6(=0x2), and falls through when t9(=[ret(kmem_zalloc)+114]:2) != s6(=0x2).
  The `beq` branch at 0xcf0 targets 0xd00, is taken when (ra(=[ret(kmem_zalloc)+116]:2) & 0x1) == 0, and falls through when (ra(=[ret(kmem_zalloc)+116]:2) & 0x1) != 0.
  The `bne` branch at 0xdb8 targets 0xde4, is taken when a4(=[ret(kmem_zalloc)+57]:1) < a5(=[ret(kmem_zalloc)+56]:1) (signed), and falls through when a4(=[ret(kmem_zalloc)+57]:1) >= a5(=[ret(kmem_zalloc)+56]:1) (signed).
  The `beq` branch at 0xdd8 targets 0xdc4, is taken when a4(=[ret(kmem_zalloc)+57]:1) >= s0(?) (signed), and falls through when a4(=[ret(kmem_zalloc)+57]:1) < s0(?) (signed).
  The `bne` branch at 0xde8 targets 0xe14, is taken when a4(=[ret(kmem_zalloc)+57]:1) < a5(=[ret(kmem_zalloc)+56]:1) (signed), and falls through when a4(=[ret(kmem_zalloc)+57]:1) >= a5(=[ret(kmem_zalloc)+56]:1) (signed).
  The `beq` branch at 0xe08 targets 0xdf4, is taken when a4(=[ret(kmem_zalloc)+57]:1) >= s0(?) (signed), and falls through when a4(=[ret(kmem_zalloc)+57]:1) < s0(?) (signed).
  The `bne` branch at 0xe18 targets 0xe40, is taken when a4(=[ret(kmem_zalloc)+57]:1) < a5(=[ret(kmem_zalloc)+56]:1) (signed), and falls through when a4(=[ret(kmem_zalloc)+57]:1) >= a5(=[ret(kmem_zalloc)+56]:1) (signed).
  The `beq` branch at 0xe38 targets 0xe24, is taken when a4(=[ret(kmem_zalloc)+57]:1) >= s0(?) (signed), and falls through when a4(=[ret(kmem_zalloc)+57]:1) < s0(?) (signed).
  The `beq` branch at 0xe48 targets 0xea0, is taken when (t2(=[ret(kmem_zalloc)+116]:2) & 0x1) == 0, and falls through when (t2(=[ret(kmem_zalloc)+116]:2) & 0x1) != 0.
  The `bne` branch at 0xe70 targets 0xea4, is taken when a4(=[ret(kmem_zalloc)+57]:1) < a5(=[ret(kmem_zalloc)+56]:1) (signed), and falls through when a4(=[ret(kmem_zalloc)+57]:1) >= a5(=[ret(kmem_zalloc)+56]:1) (signed).
  The `beq` branch at 0xe90 targets 0xe7c, is taken when a4(=[ret(kmem_zalloc)+57]:1) >= s0(?) (signed), and falls through when a4(=[ret(kmem_zalloc)+57]:1) < s0(?) (signed).
  The `beq` branch at 0xe98 targets 0xea4 and is always taken.
  The `bne` branch at 0xea8 targets 0xed0, is taken when a4(=[ret(kmem_zalloc)+57]:1) < a5(=[ret(kmem_zalloc)+56]:1) (signed), and falls through when a4(=[ret(kmem_zalloc)+57]:1) >= a5(=[ret(kmem_zalloc)+56]:1) (signed).
  The `beq` branch at 0xec8 targets 0xeb4, is taken when at(=[ret(kmem_zalloc)+57]:1) >= s0(?) (signed), and falls through when at(=[ret(kmem_zalloc)+57]:1) < s0(?) (signed).
  The `blez` branch at 0xeec targets 0xf28, is taken when a3(=[ret(kmem_zalloc)+138]:2) <= 0 (signed), and falls through when a3(=[ret(kmem_zalloc)+138]:2) > 0 (signed).
  The `beq` branch at 0xf04 targets 0xf28, is taken when v1(=[ret(kmem_zalloc)+138]:2-35) >= 0x34 (unsigned), and falls through when v1(=[ret(kmem_zalloc)+138]:2-35) < 0x34 (unsigned).
  The `bne` branch at 0xf34 targets 0xf64, is taken when a4(=[ret(kmem_zalloc)+57]:1) < a5(=[ret(kmem_zalloc)+56]:1) (signed), and falls through when a4(=[ret(kmem_zalloc)+57]:1) >= a5(=[ret(kmem_zalloc)+56]:1) (signed).
  The `beq` branch at 0xf58 targets 0xf40, is taken when a4(=[ret(kmem_zalloc)+57]:1) >= s0(?) (signed), and falls through when a4(=[ret(kmem_zalloc)+57]:1) < s0(?) (signed).
  The `bne` branch at 0xf68 targets 0xfcc, is taken when a4(=[ret(kmem_zalloc)+57]:1) < a5(=[ret(kmem_zalloc)+56]:1) (signed), and falls through when a4(=[ret(kmem_zalloc)+57]:1) >= a5(=[ret(kmem_zalloc)+56]:1) (signed).
  The `beq` branch at 0xf74 targets 0xf88 and is always taken.
  The `bne` branch at 0xf84 targets 0xfcc, is taken when a4(=[ret(kmem_zalloc)+57]:1) < s0(?) (signed), and falls through when a4(=[ret(kmem_zalloc)+57]:1) >= s0(?) (signed).
  The `bne` branch at 0xf9c targets 0xf7c, is taken when a5(?) != s2(=0x1014), and falls through when a5(?) == s2(=0x1014).
  The `bne` branch at 0xfa8 targets 0xf7c, is taken when a2(?) != s5(=0x1a7), and falls through when a2(?) == s5(=0x1a7).
  The `beq` branch at 0xfc4 targets 0xf8c, is taken when a4(=[ret(kmem_zalloc)+57]:1) >= s0(?) (signed), and falls through when a4(=[ret(kmem_zalloc)+57]:1) < s0(?) (signed).
  The `bne` branch at 0xfcc targets 0xfec, is taken when s7(=ret(async_attach_get_info)) != 0, and falls through when s7(=ret(async_attach_get_info)) == 0.
  The `bne` branch at 0xfdc targets 0x1000, is taken when s7(=ret(async_attach_get_info)) != 0, and falls through when s7(=ret(async_attach_get_info)) == 0.
  The `beq` branch at 0xfe4 targets 0x770 and is always taken.
  The `beq` branch at 0xff8 targets 0xfd4 and is always taken.
  The `beq` branch at 0x1008 targets 0xfe4 and is always taken.
  The `beq` branch at 0x102c targets 0x1038, is taken when v0(=[ret(pcibr_hints_get)+24]:8) == 0, and falls through when v0(=[ret(pcibr_hints_get)+24]:8) != 0.
  The `bne` branch at 0x1044 targets 0xab8, is taken when a4(=[ret(kmem_zalloc)+57]:1) < a5(=[ret(kmem_zalloc)+56]:1) (signed), and falls through when a4(=[ret(kmem_zalloc)+57]:1) >= a5(=[ret(kmem_zalloc)+56]:1) (signed).
  The `beq` branch at 0x104c targets 0x1308 and is always taken.
  The `beq` branch at 0x1054 targets 0x106c, is taken when a5(=[ret(kmem_zalloc)+120]) == a7(=0xd1022), and falls through when a5(=[ret(kmem_zalloc)+120]) != a7(=0xd1022).
  The `bne` branch at 0x1060 targets 0x11cc, is taken when a5(=[ret(kmem_zalloc)+120]) != t0(=0xd1122), and falls through when a5(=[ret(kmem_zalloc)+120]) == t0(=0xd1122).
  The `beq` branch at 0x1070 targets 0x928 and is always taken.
  The `bne` branch at 0x1094 targets 0x10b4, is taken when a4(=[ret(kmem_zalloc)+57]:1) < a0(?) (signed), and falls through when a4(=[ret(kmem_zalloc)+57]:1) >= a0(?) (signed).
  The `bgez` branch at 0x10a4 targets 0x1078, is taken when a1(?) >= 0 (signed), and falls through when a1(?) < 0 (signed).
  The `beq` branch at 0x10ac targets 0x1080 and is always taken.
  The `beq` branch at 0x10b4 targets 0xab8 and is always taken.
  The `beq` branch at 0x10c0 targets 0xbb0 and is always taken.
  The `beq` branch at 0x10c8 targets 0xa88 and is always taken.
  The `beq` branch at 0x10e0 targets 0xcbc, is taken when (a4(?) & 0x2) == 0, and falls through when (a4(?) & 0x2) != 0.
  The `beq` branch at 0x10f8 targets 0xcc0 and is always taken.
  The `beq` branch at 0x1110 targets 0xce8, is taken when (a6(?) & 0x2) == 0, and falls through when (a6(?) & 0x2) != 0.
  The `beq` branch at 0x113c targets 0xcec and is always taken.
  The `beq` branch at 0x11cc targets 0x11e4, is taken when a5(=[ret(kmem_zalloc)+120]) == a3(=0xd1023), and falls through when a5(=[ret(kmem_zalloc)+120]) != a3(=0xd1023).
  The `bne` branch at 0x11d8 targets 0x1224, is taken when a5(=[ret(kmem_zalloc)+120]) != a4(=0xd1123), and falls through when a5(=[ret(kmem_zalloc)+120]) == a4(=0xd1123).
  The `beq` branch at 0x11e8 targets 0x1070 and is always taken.
  The `beq` branch at 0x1200 targets 0xb50 and is always taken.
  The `beq` branch at 0x1224 targets 0x1070 and is always taken.
  The `beq` branch at 0x12e8 targets 0xa64 and is always taken.
  The `beq` branch at 0x1300 targets 0x9c4 and is always taken.
  The `beq` branch at 0x1310 targets 0x10a0 and is always taken.
  The return at 0x798 has v0 = one of -0x1, 0x0.
  The instructions from 0xa20 to 0xa60 are not reached by any path from the entry, and their branches are not listed.
  The instructions from 0xf18 to 0xf24 are not reached by any path from the entry, and their branches are not listed.
  The instructions from 0x1144 to 0x11c8 are not reached by any path from the entry, and their branches are not listed.
  The instructions from 0x1208 to 0x1220 are not reached by any path from the entry, and their branches are not listed.
  The instructions from 0x122c to 0x12d4 are not reached by any path from the entry, and their branches are not listed.
  The indirect jump at 0x9fc uses a jump table whose successors are unresolved.
  The indirect jump at 0xf10 uses a jump table whose successors are unresolved.

- `pic_pio_flush_new` in `IP35/usr/cpu/sysgen/IP35boot/pic.o` at 0x1318 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pic.o`.
  Range: 0x1318-0x1484 (364 bytes).
  It occupies 364 bytes.
  The `ld` at 0x1338 loads 8 bytes from a1 (arg1 at entry) +0x28.
  The `lh` at 0x133c loads 2 bytes from [a1+40]:8 +0x72.
  The `lbu` at 0x1378 loads 1 byte from a1 (arg1 at entry) +0x10.
  The `lw` at 0x138c loads 4 bytes from [a1+40]:8 +0xab8.
  The `ld` at 0x1390 loads 8 bytes from [a1+40]:8 +0x120.
  The `ld` at 0x1394 loads 8 bytes from [[a1+40]:8+288]:8 +0x0.
  The `lw` at 0x1398 loads 4 bytes from [[[a1+40]:8+288]:8]:8 +0x14.
  The `lw` at 0x13a4 loads 4 bytes from [[[a1+40]:8+288]:8]:8 +0x18.
  The `sw` at 0x1424 stores 4 bytes to [a1+40]:8 +0xab8.
  The `sd` at 0x142c stores 8 bytes to a0 (arg0 at entry) +0x40.
  The `sw` at 0x1440 stores 4 bytes to a0 (arg0 at entry) +0x5c.
  The `sw` at 0x1448 stores 4 bytes to a0 (arg0 at entry) +0x58.
  The `jal` at 0x1334 calls pciio_info_bus_get with a0=a1 at entry (arg1), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x136c calls mutex_spinlock with a0=[a1+40]:8+140, a1=?, a2=?, a3=?.
  The `jal` at 0x13c8 calls mutex_io_spinunlock with a0=[a1+40]:8+140, a1=ret(mutex_spinlock), a2=?, a3=?.
  The `jal` at 0x13d8 calls get_nasid with a0=?, a1=0x10a9, a2=?, a3=?.
  The `jal` at 0x13e0 calls get_chimera_type with a0=ret(get_nasid), a1=?, a2=?, a3=?.
  The `jal` at 0x1400 calls ms1bit with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1428 calls mutex_io_spinunlock with a0=[a1+40]:8+140, a1=ret(mutex_spinlock), a2=?, a3=?.
  The `jal` at 0x144c calls pcireg_intr_addr_vect_set with a0=[a1+40]:8, a1=ret(ms1bit), a2=0xed, a3=?.
  The `jal` at 0x145c calls pcireg_intr_addr_addr_set with a0=[a1+40]:8, a1=ret(ms1bit), a2=a0+80, a3=?.
  The `beq` branch at 0x1348 targets 0x1368, is taken when at(=[[a1+40]:8+114]:2) == v0(=0x2), and falls through when at(=[[a1+40]:8+114]:2) != v0(=0x2).
  The `bne` branch at 0x1388 targets 0x13d8, is taken when a5(=0x1) != v1(=[a1+16]:1), and falls through when a5(=0x1) == v1(=[a1+16]:1).
  The `bne` branch at 0x139c targets 0x13d8, is taken when a0(=[[[[a1+40]:8+288]:8]:8+20]) != a1(=0x10a9), and falls through when a0(=[[[[a1+40]:8+288]:8]:8+20]) == a1(=0x10a9).
  The `bne` branch at 0x13ac targets 0x13d8, is taken when a5(=[[[[a1+40]:8+288]:8]:8+24]) != a6(=0x100a), and falls through when a5(=[[[[a1+40]:8+288]:8]:8+24]) == a6(=0x100a).
  The `bne` branch at 0x13b8 targets 0x1400, is taken when (s1(=[[a1+40]:8+2744]) & 0xd0) != 0, and falls through when (s1(=[[a1+40]:8+2744]) & 0xd0) == 0.
  The `beq` branch at 0x13d0 targets 0x1354 and is always taken.
  The `beq` branch at 0x13ec targets 0x146c, is taken when v0(=ret(get_chimera_type)) == a7(=0x3), and falls through when v0(=ret(get_chimera_type)) != a7(=0x3).
  The `beq` branch at 0x13f8 targets 0x13c0, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `beq` branch at 0x1464 targets 0x1354 and is always taken.
  The `bne` branch at 0x1474 targets 0x13f4, is taken when t8(=0x2) != t9(?), and falls through when t8(=0x2) == t9(?).
  The `beq` branch at 0x147c targets 0x13f8 and is always taken.
  The return at 0x1360 has v0 = one of 0x0, 0x1.

- `issue_force_interrupt` in `IP35/usr/cpu/sysgen/IP35boot/pic.o` at 0x1484 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pic.o`.
  Range: 0x1484-0x14ac (40 bytes).
  It occupies 40 bytes.
  The `sd` at 0x1484 stores 8 bytes to a0 (arg0 at entry) +0x50.
  The `ld` at 0x148c loads 8 bytes from a0 (arg0 at entry) +0x40.
  The `lw` at 0x149c loads 4 bytes from a0 (arg0 at entry) +0x58.
  The `jal` at 0x1498 calls pcireg_force_always_set with a0=[a0+64]:8, a1=[a0+88], a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x14a4 has v0 = ret(pcireg_force_always_set).

- `pio_spin_wait` in `IP35/usr/cpu/sysgen/IP35boot/pic.o` at 0x14ac (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pic.o`.
  Range: 0x14ac-0x14e8 (60 bytes).
  It occupies 60 bytes.
  4 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x50, including `ld` at 0x14ac, `ld` at 0x14bc, `ld` at 0x14c8.
  The `beq` branch at 0x14b4 targets 0x14e0, is taken when a2(=0x1ed) == at(=[a0+80]:8), and falls through when a2(=0x1ed) != at(=[a0+80]:8).
  The `beq` branch at 0x14c0 targets 0x14e0, is taken when a2(=0x1ed) == v0(=[a0+80]:8), and falls through when a2(=0x1ed) != v0(=[a0+80]:8).
  The `beq` branch at 0x14cc targets 0x14e0, is taken when a2(=0x1ed) == v1(=[a0+80]:8), and falls through when a2(=0x1ed) != v1(=[a0+80]:8).
  The `bne` branch at 0x14d8 targets 0x14bc, is taken when a2(=0x1ed) != a1(=[a0+80]:8), and falls through when a2(=0x1ed) == a1(=[a0+80]:8).
  The return at 0x14e0 has v0 = one of ?, [a0+80]:8.

- `pcibr_pio_flush_read` in `IP35/usr/cpu/sysgen/IP35boot/pic.o` at 0x14e8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pic.o`.
  Range: 0x14e8-0x159c (180 bytes).
  It occupies 180 bytes.
  The `lw` at 0x1508 loads 4 bytes from a0 (arg0 at entry) +0x5c.
  The `lbu` at 0x153c loads 1 byte from a1 (arg1 at entry) +0x0.
  The `sb` at 0x1540 stores 1 byte to a2 (arg2 at entry) +0x0.
  The `ld` at 0x1570 loads 8 bytes from a1 (arg1 at entry) +0x0.
  The `sd` at 0x1578 stores 8 bytes to a2 (arg2 at entry) +0x0.
  The `lhu` at 0x157c loads 2 bytes from a1 (arg1 at entry) +0x0.
  The `sh` at 0x1584 stores 2 bytes to a2 (arg2 at entry) +0x0.
  The `lw` at 0x1588 loads 4 bytes from a1 (arg1 at entry) +0x0.
  The `sw` at 0x1590 stores 4 bytes to a2 (arg2 at entry) +0x0.
  The `jal` at 0x1544 calls issue_force_interrupt with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=?, a6=0x2, a7=0x8.
  The `jal` at 0x154c calls pio_spin_wait with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `beq` branch at 0x1500 targets 0x1568, is taken when a0 == 0, and falls through when a0 != 0.
  The `beq` branch at 0x150c targets 0x1594, is taken when at(=[a0+92]) == 0, and falls through when at(=[a0+92]) != 0.
  The `beq` branch at 0x1514 targets 0x153c, is taken when a3 == v0(=0x1), and falls through when a3 != v0(=0x1).
  The `beq` branch at 0x151c targets 0x157c, is taken when a3 == a6(=0x2), and falls through when a3 != a6(=0x2).
  The `beq` branch at 0x1524 targets 0x1588, is taken when a3 == v0(=0x4), and falls through when a3 != v0(=0x4).
  The `beq` branch at 0x152c targets 0x1570, is taken when a3 == a7(=0x8), and falls through when a3 != a7(=0x8).
  The `beq` branch at 0x1534 targets 0x155c and is always taken.
  The `beq` branch at 0x1568 targets 0x1558 and is always taken.
  The `beq` branch at 0x1574 targets 0x1544 and is always taken.
  The `beq` branch at 0x1580 targets 0x1544 and is always taken.
  The `beq` branch at 0x158c targets 0x1544 and is always taken.
  The `beq` branch at 0x1594 targets 0x1558 and is always taken.
  The return at 0x1560 has v0 = one of 0x0, 0x1.

- `pcibr_pio_flush_del` in `IP35/usr/cpu/sysgen/IP35boot/pic.o` at 0x159c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pic.o`.
  Range: 0x159c-0x15b8 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x15a4 calls kmem_free with a0=a0 at entry (arg0), a1=0x60, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x15b0 has v0 = ret(kmem_free).

- `pcibr_pio_flush_init` in `IP35/usr/cpu/sysgen/IP35boot/pic.o` at 0x15b8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pic.o`.
  Range: 0x15b8-0x1620 (104 bytes).
  It occupies 104 bytes.
  The `jal` at 0x15c0 calls pcibr_info_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x15d0 calls kmem_zalloc with a0=0x60, a1=0x0, a2=?, a3=?.
  The `jal` at 0x15ec calls pic_pio_flush_new with a0=ret(kmem_zalloc), a1=ret(pcibr_info_get), a2=?, a3=?.
  The `jal` at 0x1610 calls kmem_free with a0=ret(kmem_zalloc), a1=0x60, a2=?, a3=?.
  The `bne` branch at 0x15d8 targets 0x15e8, is taken when v0(=ret(kmem_zalloc)) != 0, and falls through when v0(=ret(kmem_zalloc)) == 0.
  The `beq` branch at 0x15e0 targets 0x15fc and is always taken.
  The `beq` branch at 0x15f4 targets 0x1610, is taken when v0(=ret(pic_pio_flush_new)) == 0, and falls through when v0(=ret(pic_pio_flush_new)) != 0.
  The `beq` branch at 0x1618 targets 0x15fc and is always taken.
  The return at 0x1608 has v0 = one of 0x0, ret(kmem_zalloc).
