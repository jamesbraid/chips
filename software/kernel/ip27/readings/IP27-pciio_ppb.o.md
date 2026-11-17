# Readings: `IP27/usr/cpu/sysgen/IP27boot/pciio_ppb.o`

One entry per routine, filed here from the reading batches by binary.

- `ppb_scan` in `IP27/usr/cpu/sysgen/IP27boot/pciio_ppb.o` at 0x0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio_ppb.o`.
  Range: 0x0-0x2d8 (728 bytes).
  It occupies 728 bytes.
  3 such `ld` accesses load 8 bytes from ret(pciio_info_get) +0x1e8, including `ld` at 0x84, `ld` at 0x154, `ld` at 0x1d0.
  The `lhu` at 0x88 loads 2 bytes from [ret(pciio_info_get)+488]:8 +0x6a.
  3 such `ld` accesses load 8 bytes from [ret(pciio_info_get)+488]:8 +0x28, including `ld` at 0xa0, `ld` at 0xfc, `ld` at 0x244.
  The `sd` at 0xc4 stores 8 bytes to [ret(pciio_info_get)+488]:8 +0x28.
  The `sd` at 0xd8 stores 8 bytes to [ret(pciio_info_get)+488]:8 +0x20.
  The `ld` at 0xf0 loads 8 bytes from [ret(pciio_info_get)+488]:8 +0x20.
  The `ld` at 0x108 loads 8 bytes from [ret(pciio_info_get)+488]:8 +0x38.
  3 such `ld` accesses load 8 bytes from [ret(pciio_info_get)+488]:8 +0x40, including `ld` at 0x114, `ld` at 0x158, `ld` at 0x264.
  The `ld` at 0x120 loads 8 bytes from [ret(pciio_info_get)+488]:8 +0x50.
  3 such `ld` accesses load 8 bytes from [ret(pciio_info_get)+488]:8 +0x58, including `ld` at 0x12c, `ld` at 0x1d4, `ld` at 0x2c4.
  The `sd` at 0x17c stores 8 bytes to [ret(pciio_info_get)+488]:8 +0x40.
  The `sd` at 0x190 stores 8 bytes to [ret(pciio_info_get)+488]:8 +0x38.
  The `sd` at 0x1f8 stores 8 bytes to [ret(pciio_info_get)+488]:8 +0x58.
  The `sd` at 0x20c stores 8 bytes to [ret(pciio_info_get)+488]:8 +0x50.
  The `jal` at 0x30 calls psema with a0=sym(.bss), a1=0x19, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x3c calls do_ppb_scan with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x48 calls vsema with a0=sym(.bss), a1=?, a2=?, a3=?.
  The `jal` at 0x70 calls pciio_info_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x7c calls pciio_businfo_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xac calls ppb_roundup_log2 with a0=[[ret(pciio_info_get)+488]:8+40]:8, a1=0x0, a2=?, a3=?.
  The `jal` at 0xc8 calls pciio_piospace_alloc with a0=a0 at entry (arg0), a1=0x0, a2=0x2, a3=ret(ppb_roundup_log2), a4=ret(ppb_roundup_log2).
  The `jal` at 0x100 calls pciio_piospace_free with a0=a0 at entry (arg0), a1=0x2, a2=[[ret(pciio_info_get)+488]:8+32]:8, a3=[[ret(pciio_info_get)+488]:8+40]:8.
  The `jal` at 0x118 calls pciio_piospace_free with a0=a0 at entry (arg0), a1=0x5, a2=[[ret(pciio_info_get)+488]:8+56]:8, a3=[[ret(pciio_info_get)+488]:8+64]:8.
  The `jal` at 0x130 calls pciio_piospace_free with a0=a0 at entry (arg0), a1=0x5, a2=[[ret(pciio_info_get)+488]:8+80]:8, a3=[[ret(pciio_info_get)+488]:8+88]:8.
  The `jal` at 0x140 calls pciio_businfo_multi_master_get with a0=ret(pciio_businfo_get), a1=[ret(pciio_info_get)+488]:8, a2=?, a3=?.
  The `jal` at 0x164 calls ppb_roundup_log2 with a0=[[ret(pciio_info_get)+488]:8+64]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x180 calls pciio_piospace_alloc with a0=a0 at entry (arg0), a1=0x0, a2=0x5, a3=ret(ppb_roundup_log2), a4=ret(ppb_roundup_log2).
  The `jal` at 0x1e0 calls ppb_roundup_log2 with a0=[[ret(pciio_info_get)+488]:8+88]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x1fc calls pciio_piospace_alloc with a0=a0 at entry (arg0), a1=0x0, a2=0x5, a3=ret(ppb_roundup_log2), a4=ret(ppb_roundup_log2).
  The `jal` at 0x248 calls cmn_err with a0=0x4, a1=sym(.rodata), a2=[[ret(pciio_info_get)+488]:8+40]:8, a3=a0 at entry (arg0).
  The `jal` at 0x268 calls cmn_err with a0=0x4, a1=sym(.rodata), a2=[[ret(pciio_info_get)+488]:8+64]:8, a3=a0 at entry (arg0).
  The `jal` at 0x284 calls cmn_err with a0=0x4, a1=sym(.rodata), a2=a0 at entry (arg0), a3=?, a6=[sym(pciio_multimaster_override)].
  The `jal` at 0x290 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x29c calls cmn_err with a0=0x6, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x2a8 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x2c8 calls cmn_err with a0=0x4, a1=sym(.rodata), a2=[[ret(pciio_info_get)+488]:8+88]:8, a3=a0 at entry (arg0).
  The `beq` branch at 0x50 targets 0x70, is taken when s0(=ret(do_ppb_scan)) == 0, and falls through when s0(=ret(do_ppb_scan)) != 0.
  The `beq` branch at 0x90 targets 0x140, is taken when at(=[[ret(pciio_info_get)+488]:8+106]:2) >= 0x2 (signed), and falls through when at(=[[ret(pciio_info_get)+488]:8+106]:2) < 0x2 (signed).
  The `beq` branch at 0x98 targets 0x1bc, is taken when a1(=[ret(pciio_info_get)+488]:8) == 0, and falls through when a1(=[ret(pciio_info_get)+488]:8) != 0.
  The `beq` branch at 0xa4 targets 0xe4, is taken when a0(=[[ret(pciio_info_get)+488]:8+40]:8) == 0, and falls through when a0(=[[ret(pciio_info_get)+488]:8+40]:8) != 0.
  The `beq` branch at 0xd4 targets 0x238, is taken when v0(=ret(pciio_piospace_alloc)) == 0, and falls through when v0(=ret(pciio_piospace_alloc)) != 0.
  The `bne` branch at 0xe8 targets 0x158, is taken when a1(=one of 0x0, 0x1) < 0x1 (unsigned), and falls through when a1(=one of 0x0, 0x1) >= 0x1 (unsigned).
  The `beq` branch at 0xf4 targets 0x108, is taken when a2(=[[ret(pciio_info_get)+488]:8+32]:8) == 0, and falls through when a2(=[[ret(pciio_info_get)+488]:8+32]:8) != 0.
  The `beq` branch at 0x10c targets 0x120, is taken when a2(=[[ret(pciio_info_get)+488]:8+56]:8) == 0, and falls through when a2(=[[ret(pciio_info_get)+488]:8+56]:8) != 0.
  The `beq` branch at 0x124 targets 0x138, is taken when a2(=[[ret(pciio_info_get)+488]:8+80]:8) == 0, and falls through when a2(=[[ret(pciio_info_get)+488]:8+80]:8) != 0.
  The `beq` branch at 0x138 targets 0x58 and is always taken.
  The `beq` branch at 0x148 targets 0x1c4, is taken when v0(=ret(pciio_businfo_multi_master_get)) == 0, and falls through when v0(=ret(pciio_businfo_multi_master_get)) != 0.
  The `beq` branch at 0x150 targets 0x98 and is always taken.
  The `beq` branch at 0x15c targets 0x198, is taken when a0(=[[ret(pciio_info_get)+488]:8+64]:8) == 0, and falls through when a0(=[[ret(pciio_info_get)+488]:8+64]:8) != 0.
  The `beq` branch at 0x18c targets 0x258, is taken when v0(=ret(pciio_piospace_alloc)) == 0, and falls through when v0(=ret(pciio_piospace_alloc)) != 0.
  The `bne` branch at 0x1a0 targets 0x1d4, is taken when a3(=one of 0x0, 0x1) < 0x1 (unsigned), and falls through when a3(=one of 0x0, 0x1) >= 0x1 (unsigned).
  The `beq` branch at 0x1ac targets 0xf0, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0x1b4 targets 0xf0, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `beq` branch at 0x1bc targets 0x58 and is always taken.
  The `beq` branch at 0x1c4 targets 0x278, is taken when a6(=[sym(pciio_multimaster_override)]) == 0, and falls through when a6(=[sym(pciio_multimaster_override)]) != 0.
  The `beq` branch at 0x1cc targets 0x98 and is always taken.
  The `beq` branch at 0x1d8 targets 0x218, is taken when a0(=[[ret(pciio_info_get)+488]:8+88]:8) == 0, and falls through when a0(=[[ret(pciio_info_get)+488]:8+88]:8) != 0.
  The `beq` branch at 0x208 targets 0x2b8, is taken when v0(=ret(pciio_piospace_alloc)) == 0, and falls through when v0(=ret(pciio_piospace_alloc)) != 0.
  The `beq` branch at 0x218 targets 0xf0, is taken when a7(?) == 0, and falls through when a7(?) != 0.
  The `beq` branch at 0x220 targets 0xf0, is taken when t0(?) == 0, and falls through when t0(?) != 0.
  The `bne` branch at 0x228 targets 0xf0, is taken when s2(=one of 0x0, 0x1) != 0, and falls through when s2(=one of 0x0, 0x1) == 0.
  The `beq` branch at 0x230 targets 0x1bc and is always taken.
  The `beq` branch at 0x250 targets 0xdc and is always taken.
  The `beq` branch at 0x270 targets 0x194 and is always taken.
  The `beq` branch at 0x2b0 targets 0x58 and is always taken.
  The `beq` branch at 0x2d0 targets 0x210 and is always taken.
  The return at 0x68 has v0 = one of ret(do_ppb_scan), -0x1, 0x0.

- `do_ppb_scan` in `IP27/usr/cpu/sysgen/IP27boot/pciio_ppb.o` at 0x2d8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio_ppb.o`.
  Range: 0x2d8-0x530 (600 bytes).
  It occupies 600 bytes.
  The `sb` at 0x330 stores 1 byte to ret(kmem_zalloc) +0x18.
  The `sb` at 0x34c stores 1 byte to ret(kmem_zalloc) +0x19.
  The `sd` at 0x358 stores 8 bytes to ret(kmem_zalloc) +0x8.
  The `sd` at 0x364 stores 8 bytes to ret(pciio_info_get) +0x1e8.
  The `lbu` at 0x368 loads 1 byte from ret(kmem_zalloc) +0x19.
  The `sw` at 0x3a4 stores 4 bytes to ret(kmem_zalloc) +0x0.
  5 such `ld` accesses load 8 bytes from ?, including `ld` at 0x3c4, `ld` at 0x3d8, `ld` at 0x414.
  2 such `sd` accesses store 8 bytes to ?, including `sd` at 0x3d0, `sd` at 0x3e4.
  The `sb` at 0x3ec stores 1 byte to ret(kmem_zalloc) +0x12.
  The `sb` at 0x3f0 stores 1 byte to ret(kmem_zalloc) +0x11.
  The `sb` at 0x3f4 stores 1 byte to ret(kmem_zalloc) +0x10.
  The `sw` at 0x400 stores 4 bytes to ret(kmem_zalloc) +0x1f8.
  The `sw` at 0x404 stores 4 bytes to ret(kmem_zalloc) +0x8.
  The `sb` at 0x41c stores 1 byte to ?.
  The `ld` at 0x498 loads 8 bytes from ret(kmem_zalloc) +0x58.
  The `ld` at 0x49c loads 8 bytes from ret(kmem_zalloc) +0x40.
  The `ld` at 0x4a8 loads 8 bytes from ret(kmem_zalloc) +0x28.
  The `sd` at 0x4c8 stores 8 bytes to ret(kmem_zalloc) +0x28.
  The `sd` at 0x4d0 stores 8 bytes to ret(kmem_zalloc) +0x40.
  The `sd` at 0x4dc stores 8 bytes to ret(kmem_zalloc) +0x58.
  The `jal` at 0x2e8 calls pciio_info_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x2f8 calls pciio_info_bus_get with a0=ret(pciio_info_get), a1=?, a2=?, a3=?.
  The `jal` at 0x304 calls ppb_bus_alloc with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x318 calls kmem_zalloc with a0=0x80, a1=0x0, a2=?, a3=?.
  The `jal` at 0x334 calls pciio_config_set with a0=a0 at entry (arg0), a1=0x18, a2=0x1, a3=?.
  The `jal` at 0x350 calls pciio_config_set with a0=a0 at entry (arg0), a1=0x19, a2=0x1, a3=?.
  The `jal` at 0x36c calls sprintf with a0=sp-80, a1=sym(.rodata), a2=[ret(kmem_zalloc)+25]:1, a3=?.
  The `jal` at 0x37c calls hwgraph_path_add with a0=a0 at entry (arg0), a1=sp-80, a2=sp-64, a3=?.
  The `jal` at 0x38c calls hwgraph_vertex_unref with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x3a0 calls kmem_zalloc with a0=0x200, a1=0x0, a2=?, a3=?.
  The `jal` at 0x408 calls pciio_info_set with a0=?, a1=ret(kmem_zalloc), a2=?, a3=?.
  The `jal` at 0x418 calls pciio_info_dev_get with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x42c calls pciio_config_set with a0=ret(pciio_info_dev_get), a1=0x1a, a2=0x1, a3=?.
  The `jal` at 0x468 calls pciio_config_get_safe with a0=?, a1=?, a2=0x2, a3=?.
  The `jal` at 0x47c calls ppb_device_init with a0=ret(kmem_zalloc), a1=?, a2=?, a3=?.
  The `jal` at 0x50c calls cmn_err with a0=0x4, a1=sym(.rodata), a2=sp-80, a3=?.
  The `jal` at 0x518 calls kmem_free with a0=ret(kmem_zalloc), a1=0x80, a2=?, a3=?.
  The `jal` at 0x520 calls ppb_bus_free with a0=?, a1=?, a2=?, a3=?.
  The `bne` branch at 0x384 targets 0x500, is taken when v0(=ret(hwgraph_path_add)) != 0, and falls through when v0(=ret(hwgraph_path_add)) == 0.
  The `bgtz` branch at 0x3e0 targets 0x3b8, is taken when a5(?) > 0 (signed), and falls through when a5(?) <= 0 (signed).
  The `bne` branch at 0x43c targets 0x414, is taken when s0(?) != 0, and falls through when s0(?) == 0.
  The `beq` branch at 0x474 targets 0x484, is taken when s1(=0xffff) == a2(?), and falls through when s1(=0xffff) != a2(?).
  The `bne` branch at 0x490 targets 0x45c, is taken when s0(?) < 0x20 (signed), and falls through when s0(?) >= 0x20 (signed).
  The `beq` branch at 0x528 targets 0x4e0 and is always taken.
  The return at 0x4f8 has v0 = one of -0x1, 0x0.

- `ppb_device_init` in `IP27/usr/cpu/sysgen/IP27boot/pciio_ppb.o` at 0x530 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio_ppb.o`.
  Range: 0x530-0x6c0 (400 bytes).
  It occupies 400 bytes.
  The `lbu` at 0x54c loads 1 byte from a0 (arg0 at entry) +0x19.
  The `lw` at 0x554 loads 4 bytes from a0 (arg0 at entry) +0x0.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x8, including `ld` at 0x570, `ld` at 0x650.
  The `lw` at 0x654 loads 4 bytes from [a0+8]:8 +0xc.
  The `sb` at 0x65c stores 1 byte to ret(pciio_device_info_new) +0x10.
  The `sw` at 0x668 stores 4 bytes to ret(pciio_device_info_new) +0xc.
  The `jal` at 0x56c calls pciio_info_master_get with a0=[a0+8]:8, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x598 calls pciio_config_get with a0=[a0], a1=?, a2=0x2, a3=?.
  The `jal` at 0x5a8 calls pciio_config_get with a0=[a0], a1=?, a2=0x2, a3=?.
  The `jal` at 0x5b8 calls pciio_config_get with a0=[a0], a1=?, a2=0x1, a3=?.
  The `jal` at 0x5f8 calls pciio_config_get_safe with a0=[a0], a1=?, a2=0x2, a3=?.
  The `jal` at 0x610 calls pciio_config_get with a0=[a0], a1=?, a2=0x2, a3=?.
  The `jal` at 0x638 calls pciio_device_info_new with a0=0x0, a1=ret(pciio_info_master_get), a2=a1 at entry (arg1), a3=?.
  The `jal` at 0x648 calls pciio_device_info_register with a0=[a0], a1=ret(pciio_device_info_new), a2=?, a3=?.
  The `jal` at 0x664 calls ppb_link with a0=ret(pciio_device_info_new), a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0x66c calls ppb_function_init with a0=ret(pciio_device_info_new), a1=?, a2=?, a3=?.
  The `beq` branch at 0x604 targets 0x674, is taken when s4(=0xffff) == s2(?), and falls through when s4(=0xffff) != s2(?).
  The `bne` branch at 0x684 targets 0x5e8, is taken when s1(?) < ra(=one of 0x1, 0x8) (signed), and falls through when s1(?) >= ra(=one of 0x1, 0x8) (signed).
  The return at 0x6b8 has v0 = 0x0.

- `ppb_function_init` in `IP27/usr/cpu/sysgen/IP27boot/pciio_ppb.o` at 0x6c0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio_ppb.o`.
  Range: 0x6c0-0xcf8 (1592 bytes).
  It occupies 1592 bytes.
  The `ld` at 0x774 loads 8 bytes from a0 (arg0 at entry) +0x1f0.
  2 such `ld` accesses load 8 bytes from ([a0+496]:8 + one of 0x28, 0x40, 0x58) +0x0, including `ld` at 0x7e8, `ld` at 0x8fc.
  The `sd` at 0x7f0 stores 8 bytes to ([a0+496]:8 + one of 0x28, 0x40, 0x58) +0x0.
  The `sd` at 0x894 stores 8 bytes to ?.
  The `sb` at 0x898 stores 1 byte to ?.
  The `sw` at 0x8a4 stores 4 bytes to ?.
  The `sd` at 0xa18 stores 8 bytes to a0 (arg0 at entry) +0x1a8.
  2 such `ld` accesses load 8 bytes from [a0+496]:8 +0x40, including `ld` at 0xa28, `ld` at 0xb9c.
  2 such `sd` accesses store 8 bytes to [a0+496]:8 +0x40, including `sd` at 0xa54, `sd` at 0xbb4.
  2 such `lhu` accesses load 2 bytes from [a0+496]:8 +0x6a, including `lhu` at 0xab0, `lhu` at 0xbbc.
  The `lhu` at 0xab4 loads 2 bytes from [a0+496]:8 +0x68.
  2 such `sh` accesses store 2 bytes to [a0+496]:8 +0x6a, including `sh` at 0xabc, `sh` at 0xbd4.
  The `sh` at 0xacc stores 2 bytes to [a0+496]:8 +0x68.
  The `ld` at 0xb90 loads 8 bytes from a0 (arg0 at entry) +0x1e8.
  The `ld` at 0xb94 loads 8 bytes from [a0+496]:8 +0x28.
  The `ld` at 0xb98 loads 8 bytes from [a0+488]:8 +0x28.
  The `sd` at 0xba4 stores 8 bytes to [a0+496]:8 +0x28.
  The `ld` at 0xba8 loads 8 bytes from [a0+488]:8 +0x40.
  The `ld` at 0xbac loads 8 bytes from [a0+496]:8 +0x58.
  The `ld` at 0xbb8 loads 8 bytes from [a0+488]:8 +0x58.
  The `sd` at 0xbc4 stores 8 bytes to [a0+496]:8 +0x58.
  The `lhu` at 0xbc8 loads 2 bytes from [a0+488]:8 +0x6a.
  The `jal` at 0x6d0 calls pciio_info_dev_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x6dc calls pciio_info_slot_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x6e8 calls pciio_info_function_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x6f4 calls pciio_info_vendor_id_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x700 calls pciio_info_device_id_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x714 calls pciio_config_get with a0=ret(pciio_info_dev_get), a1=0xe, a2=0x1, a3=?.
  The `jal` at 0x754 calls pciio_config_get with a0=ret(pciio_info_dev_get), a1=0xd, a2=0x1, a3=?.
  The `jal` at 0x77c calls pciio_config_get with a0=ret(pciio_info_dev_get), a1=0x4, a2=0x2, a3=?.
  The `jal` at 0x838 calls pciio_config_get with a0=ret(pciio_info_dev_get), a1=?, a2=0x4, a3=?.
  The `jal` at 0x8c4 calls max with a0=0x4000, a1=?, a2=?, a3=?.
  The `jal` at 0x8d4 calls max with a0=0x4000, a1=?, a2=?, a3=?.
  The `jal` at 0x8e4 calls max with a0=0x4000, a1=?, a2=?, a3=?.
  The `jal` at 0x8f4 calls max with a0=0x4000, a1=?, a2=?, a3=?.
  The `jal` at 0x97c calls pciio_config_set with a0=ret(pciio_info_dev_get), a1=?, a2=0x4, a3=0xffffffff.
  The `jal` at 0x98c calls pciio_config_get with a0=ret(pciio_info_dev_get), a1=?, a2=0x4, a3=?.
  The `jal` at 0x9f4 calls pciio_config_set with a0=ret(pciio_info_dev_get), a1=0x30, a2=0x4, a3=0xfffff800.
  The `jal` at 0xa04 calls pciio_config_get with a0=ret(pciio_info_dev_get), a1=0x30, a2=0x4, a3=?.
  The `jal` at 0xa70 calls pciio_config_get with a0=ret(pciio_info_dev_get), a1=0xb, a2=0x1, a3=?.
  The `jal` at 0xa84 calls pciio_config_get with a0=ret(pciio_info_dev_get), a1=0xa, a2=0x1, a3=?.
  The `jal` at 0xb28 calls pciio_config_set with a0=ret(pciio_info_dev_get), a1=?, a2=0x4, a3=0x0.
  The `jal` at 0xb7c calls do_ppb_scan with a0=ret(pciio_info_dev_get), a1=?, a2=?, a3=?.
  The `jal` at 0xc00 calls pciio_config_get with a0=ret(pciio_info_dev_get), a1=0x3e, a2=0x1, a3=?, a6=ret(pciio_info_device_id_get).
  The `jal` at 0xc5c calls pciio_config_set with a0=ret(pciio_info_dev_get), a1=0xd, a2=0x1, a3=?.
  The `jal` at 0xc78 calls pciio_config_get with a0=ret(pciio_info_dev_get), a1=?, a2=0x4, a3=?.
  The `jal` at 0xc9c calls pciio_config_set with a0=ret(pciio_info_dev_get), a1=0x4, a2=0x2, a3=?.
  The `jal` at 0xcac calls pciio_config_get with a0=ret(pciio_info_dev_get), a1=0x4, a2=0x2, a3=?.
  The `jal` at 0xce8 calls cmn_err with a0=0x4, a1=sym(.rodata), a2=?, a3=?, a5=0x1, a6=0x2.
  The `beq` branch at 0x734 targets 0xbd8, is taken when (a4(=(ret(pciio_config_get) << 0x0)) & 0x7f) == 0, and falls through when (a4(=(ret(pciio_config_get) << 0x0)) & 0x7f) != 0.
  The `bne` branch at 0x740 targets 0xcd0, is taken when a4(?) != a5(=0x1), and falls through when a4(?) == a5(=0x1).
  The `beq` branch at 0x760 targets 0xbe0, is taken when a7(=(ret(pciio_config_get) << 0x0)) == 0, and falls through when a7(=(ret(pciio_config_get) << 0x0)) != 0.
  The `blez` branch at 0x79c targets 0x9bc, is taken when t1(=one of 0x2, 0x6) <= 0 (signed), and falls through when t1(=one of 0x2, 0x6) > 0 (signed).
  The `beq` branch at 0x7e0 targets 0x82c and is always taken.
  The `beq` branch at 0x804 targets 0x9b4, is taken when v1(=ret(pciio_info_vendor_id_get)) == a0(=0x10a9), and falls through when v1(=ret(pciio_info_vendor_id_get)) != a0(=0x10a9).
  The `beq` branch at 0x810 targets 0xb0c, is taken when a1(=0x4) == a2(?), and falls through when a1(=0x4) != a2(?).
  The `beq` branch at 0x824 targets 0x9bc, is taken when s2(?) >= a3(=one of 0x2, 0x6) (signed), and falls through when s2(?) < a3(=one of 0x2, 0x6) (signed).
  The `beq` branch at 0x850 targets 0x930, is taken when (v0(=ret(pciio_config_get)) & 0x1) == 0, and falls through when (v0(=ret(pciio_config_get)) & 0x1) != 0.
  The `beq` branch at 0x85c targets 0x870, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `beq` branch at 0x870 targets 0x970, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0x8a0 targets 0x7f4, is taken when t9(=[a0+496]:8) == 0, and falls through when t9(=[a0+496]:8) != 0.
  The `beq` branch at 0x8ac targets 0xaf8, is taken when s4(=one of 0x2, 0x4) == t9(=0x2), and falls through when s4(=one of 0x2, 0x4) != t9(=0x2).
  The `beq` branch at 0x8b4 targets 0xb00, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x8cc targets 0x7e8, is taken when v0(=ret(max)) == 0, and falls through when v0(=ret(max)) != 0.
  The `beq` branch at 0x928 targets 0x7ec and is always taken.
  The `beq` branch at 0x94c targets 0xb44, is taken when (a1(=-0x10) & v0(=ret(pciio_config_get))) == 0, and falls through when (a1(=-0x10) & v0(=ret(pciio_config_get))) != 0.
  The `beq` branch at 0x954 targets 0xb58, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0x964 targets 0xb38, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x9a4 targets 0x884, is taken when s0(?) >= 0x1 (unsigned), and falls through when s0(?) < 0x1 (unsigned).
  The `beq` branch at 0x9ac targets 0x818 and is always taken.
  The `bne` branch at 0x9b4 targets 0x810, is taken when t9(=ret(pciio_info_device_id_get)) != ra(=0x3), and falls through when t9(=ret(pciio_info_device_id_get)) == ra(=0x3).
  The `bne` branch at 0x9d0 targets 0x9e8, is taken when at(=ret(pciio_info_vendor_id_get)) != v0(=0x10a9), and falls through when at(=ret(pciio_info_vendor_id_get)) == v0(=0x10a9).
  The `beq` branch at 0x9e0 targets 0xa14, is taken when v1(=ret(pciio_info_device_id_get)) == a0(=0x3), and falls through when v1(=ret(pciio_info_device_id_get)) != a0(=0x3).
  The `beq` branch at 0xa14 targets 0xa58, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0xa20 targets 0xa5c, is taken when t8(=[a0+496]:8) == 0, and falls through when t8(=[a0+496]:8) != 0.
  The `beq` branch at 0xa64 targets 0xc90, is taken when (v1(?) & 0x4) == 0, and falls through when (v1(?) & 0x4) != 0.
  The `beq` branch at 0xa90 targets 0xb60, is taken when (s3(?) & 0x4) == 0, and falls through when (s3(?) & 0x4) != 0.
  The `beq` branch at 0xa9c targets 0xb60, is taken when a1(=[a0+496]:8) == 0, and falls through when a1(=[a0+496]:8) != 0.
  The `beq` branch at 0xaa8 targets 0xc28, is taken when a2(=0x6) == a0(?), and falls through when a2(=0x6) != a0(?).
  The `beq` branch at 0xac8 targets 0xb68, is taken when a5(=0x6) == a0(?), and falls through when a5(=0x6) != a0(?).
  The `beq` branch at 0xaf8 targets 0x8bc and is always taken.
  The `beq` branch at 0xb04 targets 0x8c0 and is always taken.
  The `beq` branch at 0xb30 targets 0x818 and is always taken.
  The `beq` branch at 0xb3c targets 0xc6c, is taken when a2(=0x4) == a6(?), and falls through when a2(=0x4) != a6(?).
  The `bne` branch at 0xb48 targets 0x878, is taken when a4(?) != 0, and falls through when a4(?) == 0.
  The `beq` branch at 0xb50 targets 0x970 and is always taken.
  The `beq` branch at 0xb58 targets 0x96c and is always taken.
  The `bne` branch at 0xb64 targets 0xad0, is taken when a3(=0x6) != a0(?), and falls through when a3(=0x6) == a0(?).
  The `beq` branch at 0xb6c targets 0xb7c, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `bne` branch at 0xb74 targets 0xad0, is taken when a1(?) != a4(=0x4), and falls through when a1(?) == a4(=0x4).
  The `beq` branch at 0xb88 targets 0xad4, is taken when a5(=[a0+496]:8) == 0, and falls through when a5(=[a0+496]:8) != 0.
  The `beq` branch at 0xbd0 targets 0xad0 and is always taken.
  The `beq` branch at 0xbd8 targets 0x74c and is always taken.
  The `beq` branch at 0xbec targets 0xcbc, is taken when v0(=ret(pciio_info_vendor_id_get)) == v1(=0x10a9), and falls through when v0(=ret(pciio_info_vendor_id_get)) != v1(=0x10a9).
  The `beq` branch at 0xbf4 targets 0x768, is taken when a1(=ret(pciio_info_device_id_get)) == a0(=0x5), and falls through when a1(=ret(pciio_info_device_id_get)) != a0(=0x5).
  The `beq` branch at 0xc10 targets 0xc48, is taken when a2(=(ret(pciio_config_get) << 0x0)) == 0, and falls through when a2(=(ret(pciio_config_get) << 0x0)) != 0.
  The `beq` branch at 0xc18 targets 0xc48, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0xc20 targets 0xc50 and is always taken.
  The `beq` branch at 0xc30 targets 0xb7c, is taken when (v0(=ret(pciio_config_get)) & 0xff) == 0, and falls through when (v0(=ret(pciio_config_get)) & 0xff) != 0.
  The `bne` branch at 0xc38 targets 0xab0, is taken when a1(?) != a3(=0x4), and falls through when a1(?) == a3(=0x4).
  The `beq` branch at 0xc40 targets 0xb64 and is always taken.
  The `beq` branch at 0xc64 targets 0x76c and is always taken.
  The `beq` branch at 0xc88 targets 0xb44 and is always taken.
  The `beq` branch at 0xcb4 targets 0xa68 and is always taken.
  The `bne` branch at 0xcc0 targets 0xbf4, is taken when a6(=ret(pciio_info_device_id_get)) != a7(=0x3), and falls through when a6(=ret(pciio_info_device_id_get)) == a7(=0x3).
  The `beq` branch at 0xcc8 targets 0x76c and is always taken.
  The `beq` branch at 0xcf0 targets 0x748 and is always taken.
  The return at 0xaf0 has v0 = 0x0.

- `ppb_addr_space_assign` in `IP27/usr/cpu/sysgen/IP27boot/pciio_ppb.o` at 0xcf8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio_ppb.o`.
  Range: 0xcf8-0xf40 (584 bytes).
  It occupies 584 bytes.
  The `ld` at 0xd0c loads 8 bytes from a0 (arg0 at entry) +0x1e8.
  2 such `ld` accesses load 8 bytes from [a0+488]:8 +0x50, including `ld` at 0xd14, `ld` at 0xe58.
  2 such `ld` accesses load 8 bytes from [a0+488]:8 +0x38, including `ld` at 0xd18, `ld` at 0xe0c.
  2 such `ld` accesses load 8 bytes from [a0+488]:8 +0x20, including `ld` at 0xd1c, `ld` at 0xd68.
  The `ld` at 0xd20 loads 8 bytes from [a0+488]:8 +0x10.
  The `sd` at 0xd24 stores 8 bytes to [a0+488]:8 +0x30.
  The `sd` at 0xd28 stores 8 bytes to [a0+488]:8 +0x48.
  The `sd` at 0xd34 stores 8 bytes to [a0+488]:8 +0x60.
  The `ld` at 0xd40 loads 8 bytes from ?.
  The `ld` at 0xd54 loads 8 bytes from [a0+488]:8 +0x28.
  2 such `ld` accesses load 8 bytes from [a0+488]:8 +0x40, including `ld` at 0xdd4, `ld` at 0xdfc.
  The `ld` at 0xe48 loads 8 bytes from [a0+488]:8 +0x58.
  The `jal` at 0xd38 calls function_addr_space_assign with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xd4c calls pciio_info_dev_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xd84 calls pciio_config_set with a0=ret(pciio_info_dev_get), a1=0x1c, a2=0x1, a3=?.
  The `jal` at 0xd9c calls pciio_config_set with a0=ret(pciio_info_dev_get), a1=0x1d, a2=0x1, a3=?.
  The `jal` at 0xdac calls pciio_config_get with a0=ret(pciio_info_dev_get), a1=0x1c, a2=0x1, a3=?.
  The `jal` at 0xde0 calls pciio_config_set with a0=ret(pciio_info_dev_get), a1=0x30, a2=0x2, a3=?.
  The `jal` at 0xdf4 calls pciio_config_set with a0=ret(pciio_info_dev_get), a1=0x32, a2=0x2, a3=?.
  The `jal` at 0xe28 calls pciio_config_set with a0=ret(pciio_info_dev_get), a1=0x20, a2=0x2, a3=?.
  The `jal` at 0xe40 calls pciio_config_set with a0=ret(pciio_info_dev_get), a1=0x22, a2=0x2, a3=?.
  The `jal` at 0xe74 calls pciio_config_set with a0=ret(pciio_info_dev_get), a1=0x24, a2=0x2, a3=?.
  The `jal` at 0xe8c calls pciio_config_set with a0=ret(pciio_info_dev_get), a1=0x26, a2=0x2, a3=?.
  The `jal` at 0xe9c calls pciio_config_get with a0=ret(pciio_info_dev_get), a1=0x24, a2=0x1, a3=?.
  The `jal` at 0xed4 calls pciio_config_set with a0=ret(pciio_info_dev_get), a1=0x28, a2=0x4, a3=?.
  The `jal` at 0xee8 calls pciio_config_set with a0=ret(pciio_info_dev_get), a1=0x2c, a2=0x4, a3=?.
  The `jal` at 0xf18 calls cmn_err with a0=0x4, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0xf30 calls cmn_err with a0=0x4, a1=sym(.rodata), a2=?, a3=?.
  The `beq` branch at 0xd30 targets 0xd4c, is taken when s0(=[[a0+488]:8+16]:8) == 0, and falls through when s0(=[[a0+488]:8+16]:8) != 0.
  The `bne` branch at 0xd44 targets 0xd38, is taken when s0(?) != 0, and falls through when s0(?) == 0.
  The `beq` branch at 0xd60 targets 0xd74, is taken when a0(=[[a0+488]:8+40]:8) == 0, and falls through when a0(=[[a0+488]:8+40]:8) != 0.
  The `bne` branch at 0xdb8 targets 0xdd8, is taken when (v0(=ret(pciio_config_get)) & 0xf) != 0, and falls through when (v0(=ret(pciio_config_get)) & 0xf) == 0.
  The `bne` branch at 0xdc0 targets 0xf28, is taken when a3(?) != 0, and falls through when a3(?) == 0.
  The `bne` branch at 0xdc8 targets 0xf2c, is taken when a5(?) != 0, and falls through when a5(?) == 0.
  The `beq` branch at 0xdd0 targets 0xe00 and is always taken.
  The `beq` branch at 0xe04 targets 0xe18, is taken when v0(=[[a0+488]:8+64]:8) == 0, and falls through when v0(=[[a0+488]:8+64]:8) != 0.
  The `beq` branch at 0xe50 targets 0xe64, is taken when v0(=[[a0+488]:8+88]:8) == 0, and falls through when v0(=[[a0+488]:8+88]:8) != 0.
  The `bne` branch at 0xea8 targets 0xecc, is taken when (v0(=ret(pciio_config_get)) & 0xf) != 0, and falls through when (v0(=ret(pciio_config_get)) & 0xf) == 0.
  The `bne` branch at 0xeb0 targets 0xf14, is taken when a3(?) != 0, and falls through when a3(?) == 0.
  The `beq` branch at 0xebc targets 0xef4, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `beq` branch at 0xec4 targets 0xf14 and is always taken.
  The `beq` branch at 0xf20 targets 0xef4 and is always taken.
  The `beq` branch at 0xf38 targets 0xdd0 and is always taken.
  The return at 0xf08 has v0 = 0x0.
  The instructions from 0xf10 to 0xf10 are not reached by any path from the entry, and their branches are not listed.

- `function_addr_space_assign` in `IP27/usr/cpu/sysgen/IP27boot/pciio_ppb.o` at 0xf40 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio_ppb.o`.
  Range: 0xf40-0x12bc (892 bytes).
  It occupies 892 bytes.
  The `ld` at 0xfa0 loads 8 bytes from a0 (arg0 at entry) +0x1f0.
  4 such `lw` accesses load 4 bytes from ?, including `lw` at 0xfd4, `lw` at 0xfec, `lw` at 0xffc.
  6 such `ld` accesses load 8 bytes from ([a0+496]:8 + one of 0x30, 0x48, 0x60) +0x0, including `ld` at 0x1000, `ld` at 0x1050, `ld` at 0x1068.
  2 such `sd` accesses store 8 bytes to ([a0+496]:8 + one of 0x30, 0x48, 0x60) +0x0, including `sd` at 0x1044, `sd` at 0x10a8.
  The `sd` at 0x1070 stores 8 bytes to ?.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0x10a0, `ld` at 0x10d0.
  The `lbu` at 0x10ec loads 1 byte from ?.
  The `ld` at 0x1124 loads 8 bytes from a0 (arg0 at entry) +0x1a8.
  3 such `ld` accesses load 8 bytes from [a0+496]:8 +0x48, including `ld` at 0x1134, `ld` at 0x1174, `ld` at 0x122c.
  2 such `sd` accesses store 8 bytes to [a0+496]:8 +0x48, including `sd` at 0x115c, `sd` at 0x1288.
  The `sd` at 0x1168 stores 8 bytes to a0 (arg0 at entry) +0x1a0.
  The `ld` at 0x120c loads 8 bytes from [a0+496]:8 +0x30.
  The `ld` at 0x1214 loads 8 bytes from a0 (arg0 at entry) +0x1e8.
  The `sd` at 0x1224 stores 8 bytes to [a0+488]:8 +0x20.
  The `sd` at 0x1240 stores 8 bytes to [a0+488]:8 +0x38.
  The `ld` at 0x1244 loads 8 bytes from [a0+496]:8 +0x60.
  The `sd` at 0x125c stores 8 bytes to [a0+488]:8 +0x50.
  The `ld` at 0x1260 loads 8 bytes from [a0+488]:8 +0x30.
  The `sd` at 0x1274 stores 8 bytes to [a0+496]:8 +0x30.
  The `ld` at 0x1278 loads 8 bytes from [a0+488]:8 +0x48.
  The `ld` at 0x128c loads 8 bytes from [a0+488]:8 +0x60.
  The `sd` at 0x12a0 stores 8 bytes to [a0+496]:8 +0x60.
  The `jal` at 0xf50 calls pciio_info_dev_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xf64 calls pciio_config_get with a0=ret(pciio_info_dev_get), a1=0xb, a2=0x1, a3=?.
  The `jal` at 0xf84 calls pciio_config_get with a0=ret(pciio_info_dev_get), a1=0xa, a2=0x1, a3=?.
  The `jal` at 0xfd8 calls max with a0=0x4000, a1=?, a2=?, a3=?.
  The `jal` at 0xfe8 calls max with a0=0x4000, a1=?, a2=?, a3=?.
  The `jal` at 0xff8 calls max with a0=0x4000, a1=?, a2=?, a3=?.
  The `jal` at 0x1040 calls pciio_config_get with a0=ret(pciio_info_dev_get), a1=?, a2=0x4, a3=?.
  The `jal` at 0x105c calls pciio_config_set with a0=ret(pciio_info_dev_get), a1=?, a2=0x4, a3=?.
  The `jal` at 0x1094 calls pciio_config_set with a0=ret(pciio_info_dev_get), a1=?, a2=0x4, a3=?.
  The `jal` at 0x1104 calls max with a0=0x4000, a1=?, a2=?, a3=?.
  The `jal` at 0x1170 calls pciio_config_set with a0=ret(pciio_info_dev_get), a1=0x30, a2=0x4, a3=[[a0+496]:8+72]:8, a6=[a0+424]:8, a7=([[a0+496]:8+72]:8 + [a0+424]:8)-1.
  The `jal` at 0x11cc calls pciio_config_get with a0=ret(pciio_info_dev_get), a1=0x4, a2=0x2, a3=?.
  The `jal` at 0x11e4 calls pciio_config_set with a0=ret(pciio_info_dev_get), a1=0x4, a2=0x2, a3=?.
  The `jal` at 0x1258 calls ppb_addr_space_assign with a0=a0 at entry (arg0), a1=0x4, a2=?, a3=?.
  The `beq` branch at 0xfcc targets 0x12a4 and is always taken.
  The `beq` branch at 0x1074 targets 0x10a0, is taken when (a4(=(ret(pciio_config_get) << 0x0)) & 0x4) == 0, and falls through when (a4(=(ret(pciio_config_get) << 0x0)) & 0x4) != 0.
  The `beq` branch at 0x1084 targets 0x10a0, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0x10c4 targets 0x1124, is taken when s3(?) >= 0x6 (signed), and falls through when s3(?) < 0x6 (signed).
  The `beq` branch at 0x10d8 targets 0x10ac, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0x10e4 targets 0x111c, is taken when t8(?) == t9(=0x2), and falls through when t8(?) != t9(=0x2).
  The `beq` branch at 0x10f4 targets 0x1200, is taken when (ra(?) & 0x8) == 0, and falls through when (ra(?) & 0x8) != 0.
  The `bne` branch at 0x110c targets 0xfd4, is taken when v0(=ret(max)) != 0, and falls through when v0(=ret(max)) == 0.
  The `beq` branch at 0x1114 targets 0x1034 and is always taken.
  The `beq` branch at 0x111c targets 0x1100 and is always taken.
  The `beq` branch at 0x1128 targets 0x117c, is taken when a6(=[a0+424]:8) == 0, and falls through when a6(=[a0+424]:8) != 0.
  The `bne` branch at 0x118c targets 0x11a4, is taken when t0(?) != t1(=0x6), and falls through when t0(?) == t1(=0x6).
  The `beq` branch at 0x1194 targets 0x120c, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x119c targets 0x120c, is taken when a0(?) == a1(=0x4), and falls through when a0(?) != a1(=0x4).
  The `beq` branch at 0x1200 targets 0x1104 and is always taken.
  The `beq` branch at 0x129c targets 0x11a4 and is always taken.
  The `beq` branch at 0x12b4 targets 0x10d0 and is always taken.
  The return at 0x11f8 has v0 = 0x0.
  The instructions from 0x1208 to 0x1208 are not reached by any path from the entry, and their branches are not listed.

- `ppb_function_print` in `IP27/usr/cpu/sysgen/IP27boot/pciio_ppb.o` at 0x12bc (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio_ppb.o`.
  Range: 0x12bc-0x179c (1248 bytes).
  It occupies 1248 bytes.
  4 such `ld` accesses load 8 bytes from ?, including `ld` at 0x1430, `ld` at 0x143c, `ld` at 0x1468.
  3 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x1478, `lbu` at 0x1494, `lbu` at 0x14ac.
  The `ld` at 0x14e8 loads 8 bytes from a0 (arg0 at entry) +0x1a8.
  The `ld` at 0x14f4 loads 8 bytes from a0 (arg0 at entry) +0x1a0.
  The `ld` at 0x15a8 loads 8 bytes from a0 (arg0 at entry) +0x1e8.
  The `lbu` at 0x15ac loads 1 byte from [a0+488]:8 +0x1a.
  The `lbu` at 0x15b4 loads 1 byte from [a0+488]:8 +0x19.
  The `lbu` at 0x15c0 loads 1 byte from [a0+488]:8 +0x18.
  The `ld` at 0x1644 loads 8 bytes from [a0+488]:8 +0x28.
  The `ld` at 0x16a4 loads 8 bytes from [a0+488]:8 +0x40.
  The `ld` at 0x1738 loads 8 bytes from [a0+488]:8 +0x58.
  The `ld` at 0x1758 loads 8 bytes from [a0+488]:8 +0x10.
  The `jal` at 0x12d4 calls pciio_info_bus_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x12e4 calls pciio_info_slot_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x12f4 calls pciio_info_function_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x1304 calls pciio_info_dev_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x1320 calls pciio_config_get with a0=ret(pciio_info_dev_get), a1=0xe, a2=0x1, a3=?.
  The `jal` at 0x1350 calls printf with a0=sym(.rodata), a1=a1 at entry (arg1), a2=?, a3=?, a5=ret(pciio_info_dev_get).
  The `jal` at 0x1360 calls pciio_config_get with a0=ret(pciio_info_dev_get), a1=0x0, a2=0x2, a3=?.
  The `jal` at 0x1374 calls pciio_config_get with a0=ret(pciio_info_dev_get), a1=0x2, a2=0x2, a3=?.
  The `jal` at 0x1388 calls pciio_config_get with a0=ret(pciio_info_dev_get), a1=0x9, a2=0x3, a3=?.
  The `jal` at 0x13a0 calls printf with a0=sym(.rodata), a1=a1 at entry (arg1), a2=ret(pciio_config_get), a3=ret(pciio_config_get), a4=ret(pciio_config_get).
  The `jal` at 0x13b0 calls pciio_config_get with a0=ret(pciio_info_dev_get), a1=0xe, a2=0x1, a3=?.
  The `jal` at 0x13c4 calls pciio_config_get with a0=ret(pciio_info_dev_get), a1=0xd, a2=0x1, a3=?.
  The `jal` at 0x13d8 calls pciio_config_get with a0=ret(pciio_info_dev_get), a1=0x3f, a2=0x1, a3=?.
  The `jal` at 0x13f4 calls printf with a0=sym(.rodata), a1=a1 at entry (arg1), a2=ret(pciio_config_get), a3=ret(pciio_config_get), a4=ret(pciio_config_get).
  The `jal` at 0x1424 calls strcat with a0=sp-176, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x1440 calls printf with a0=sym(.rodata), a1=a1 at entry (arg1), a2=?, a3=?, a4=sp-175.
  The `jal` at 0x148c calls strcat with a0=sp-176, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x14a4 calls strcat with a0=sp-176, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x14c4 calls strcat with a0=sp-176, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x14f8 calls printf with a0=sym(.rodata), a1=a1 at entry (arg1), a2=[a0+416]:8, a3=[a0+424]:8.
  The `jal` at 0x1508 calls pciio_config_get with a0=ret(pciio_info_dev_get), a1=0xb, a2=0x1, a3=?.
  The `jal` at 0x151c calls pciio_config_get with a0=ret(pciio_info_dev_get), a1=0xa, a2=0x1, a3=?.
  The `jal` at 0x1580 calls strcat with a0=sp-176, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x1598 calls strcat with a0=sp-176, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x15bc calls printf with a0=sym(.rodata), a1=a1 at entry (arg1), a2=[[a0+488]:8+24]:1, a3=[[a0+488]:8+25]:1, a4=[[a0+488]:8+26]:1.
  The `jal` at 0x15cc calls pciio_config_get with a0=ret(pciio_info_dev_get), a1=0x30, a2=0x2, a3=?.
  The `jal` at 0x15e0 calls pciio_config_get with a0=ret(pciio_info_dev_get), a1=0x1c, a2=0x1, a3=?.
  The `jal` at 0x15f4 calls pciio_config_get with a0=ret(pciio_info_dev_get), a1=0x32, a2=0x2, a3=?.
  The `jal` at 0x1608 calls pciio_config_get with a0=ret(pciio_info_dev_get), a1=0x1d, a2=0x1, a3=?.
  The `jal` at 0x1648 calls printf with a0=sym(.rodata), a1=a1 at entry (arg1), a2=[[a0+488]:8+40]:8, a3=?, a5=0xfffff000, a6=(ret(pciio_config_get) << 0x8).
  The `jal` at 0x1658 calls pciio_config_get with a0=ret(pciio_info_dev_get), a1=0x20, a2=0x2, a3=?.
  The `jal` at 0x166c calls pciio_config_get with a0=ret(pciio_info_dev_get), a1=0x22, a2=0x2, a3=?.
  The `jal` at 0x16a8 calls printf with a0=sym(.rodata), a1=a1 at entry (arg1), a2=[[a0+488]:8+64]:8, a3=?, a5=0xfff00000.
  The `jal` at 0x16b8 calls pciio_config_get with a0=ret(pciio_info_dev_get), a1=0x28, a2=0x4, a3=?.
  The `jal` at 0x16cc calls pciio_config_get with a0=ret(pciio_info_dev_get), a1=0x24, a2=0x2, a3=?.
  The `jal` at 0x16e0 calls pciio_config_get with a0=ret(pciio_info_dev_get), a1=0x2c, a2=0x4, a3=?.
  The `jal` at 0x16f4 calls pciio_config_get with a0=ret(pciio_info_dev_get), a1=0x26, a2=0x2, a3=?.
  The `jal` at 0x173c calls printf with a0=sym(.rodata), a1=a1 at entry (arg1), a2=[[a0+488]:8+88]:8, a3=?, a5=0xfffffffffff00000, a6=(ret(pciio_config_get) << 0x10).
  The `jal` at 0x1750 calls sprintf with a0=sp-144, a1=sym(.rodata), a2=a1 at entry (arg1), a3=?.
  The `jal` at 0x1770 calls ppb_function_print with a0=?, a1=sp-144, a2=?, a3=?.
  The `jal` at 0x178c calls printf with a0=sym(.rodata), a1=a1 at entry (arg1), a2=?, a3=?.
  The `beq` branch at 0x1414 targets 0x1458 and is always taken.
  The `beq` branch at 0x1454 targets 0x14e8, is taken when s0(?) >= s5(=one of 0x2, 0x6) (signed), and falls through when s0(?) < s5(=one of 0x2, 0x6) (signed).
  The `beq` branch at 0x146c targets 0x14d4, is taken when t8(?) == 0, and falls through when t8(?) != 0.
  The `bne` branch at 0x1480 targets 0x141c, is taken when (t8(?) & 0x1) != 0, and falls through when (t8(?) & 0x1) == 0.
  The `beq` branch at 0x149c targets 0x14b0, is taken when (v0(?) & 0x8) == 0, and falls through when (v0(?) & 0x8) != 0.
  The `beq` branch at 0x14b4 targets 0x1574, is taken when (v0(?) & 0x2) == 0, and falls through when (v0(?) & 0x2) != 0.
  The `beq` branch at 0x14cc targets 0x1430 and is always taken.
  The `bne` branch at 0x14e0 targets 0x145c, is taken when s0(?) < s5(=one of 0x2, 0x6) (signed), and falls through when s0(?) >= s5(=one of 0x2, 0x6) (signed).
  The `beq` branch at 0x14ec targets 0x1500, is taken when a3(=[a0+424]:8) == 0, and falls through when a3(=[a0+424]:8) != 0.
  The `bne` branch at 0x152c targets 0x1548, is taken when t8(=0x6) != t9(?), and falls through when t8(=0x6) == t9(?).
  The `beq` branch at 0x1538 targets 0x15a8, is taken when (v0(=ret(pciio_config_get)) & 0xff) == 0, and falls through when (v0(=ret(pciio_config_get)) & 0xff) != 0.
  The `beq` branch at 0x1540 targets 0x15a8, is taken when a0(?) == ra(=0x4), and falls through when a0(?) != ra(=0x4).
  The `beq` branch at 0x1574 targets 0x1590, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x1588 targets 0x1430 and is always taken.
  The `beq` branch at 0x15a0 targets 0x1430 and is always taken.
  The `beq` branch at 0x1624 targets 0x1630, is taken when (a5(=0xfffff000) & a0(=((ret(pciio_config_get) << 0x10) | (ret(pciio_config_get) << 0x8)))) == 0, and falls through when (a5(=0xfffff000) & a0(=((ret(pciio_config_get) << 0x10) | (ret(pciio_config_get) << 0x8)))) != 0.
  The `beq` branch at 0x168c targets 0x1698, is taken when (a5(=0xfff00000) & a1(=(ret(pciio_config_get) << 0x10))) == 0, and falls through when (a5(=0xfff00000) & a1(=(ret(pciio_config_get) << 0x10))) != 0.
  The `beq` branch at 0x1718 targets 0x1724, is taken when (a5(=0xfffffffffff00000) & a0(=((ret(pciio_config_get) << 0x20) | (ret(pciio_config_get) << 0x10)))) == 0, and falls through when (a5(=0xfffffffffff00000) & a0(=((ret(pciio_config_get) << 0x20) | (ret(pciio_config_get) << 0x10)))) != 0.
  The `beq` branch at 0x175c targets 0x178c, is taken when s0(=[[a0+488]:8+16]:8) == 0, and falls through when s0(=[[a0+488]:8+16]:8) != 0.
  The `beq` branch at 0x1764 targets 0x1548, is taken when s0(=[[a0+488]:8+16]:8) == 0, and falls through when s0(=[[a0+488]:8+16]:8) != 0.
  The `bne` branch at 0x177c targets 0x1770, is taken when s0(?) != 0, and falls through when s0(?) == 0.
  The `beq` branch at 0x1784 targets 0x1548 and is always taken.
  The `beq` branch at 0x1794 targets 0x1548 and is always taken.
  The return at 0x156c has v0 = one of ret(pciio_config_get), ret(sprintf), ret(ppb_function_print), ret(printf).

- `ppb_link` in `IP27/usr/cpu/sysgen/IP27boot/pciio_ppb.o` at 0x179c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio_ppb.o`.
  Range: 0x179c-0x1888 (236 bytes).
  It occupies 236 bytes.
  The `sd` at 0x179c stores 8 bytes to a0 (arg0 at entry) +0x1f0.
  The `ld` at 0x17a0 loads 8 bytes from a1 (arg1 at entry) +0x10.
  The `lbu` at 0x17ac loads 1 byte from a0 (arg0 at entry) +0x11.
  4 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x17b0, `lbu` at 0x17c8, `lbu` at 0x17ec.
  2 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x12, including `lbu` at 0x17cc, `lbu` at 0x1808.
  3 such `ld` accesses load 8 bytes from ?, including `ld` at 0x17e0, `ld` at 0x181c, `ld` at 0x1848.
  4 such `sd` accesses store 8 bytes to ?, including `sd` at 0x1838, `sd` at 0x1850, `sd` at 0x1854.
  4 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x1e0, including `sd` at 0x183c, `sd` at 0x1858, `sd` at 0x186c.
  4 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x1d8, including `sd` at 0x1844, `sd` at 0x184c, `sd` at 0x1874.
  2 such `sd` accesses store 8 bytes to a1 (arg1 at entry) +0x10, including `sd` at 0x1864, `sd` at 0x1878.
  The `beq` branch at 0x17a4 targets 0x1878, is taken when a3(=[a1+16]:8) == 0, and falls through when a3(=[a1+16]:8) != 0.
  The `bne` branch at 0x17b8 targets 0x1828, is taken when a5(=[a0+17]:1) < a6(?) (signed), and falls through when a5(=[a0+17]:1) >= a6(?) (signed).
  The `bne` branch at 0x17c0 targets 0x17dc, is taken when a6(?) != a5(=[a0+17]:1), and falls through when a6(?) == a5(=[a0+17]:1).
  The `bne` branch at 0x17d4 targets 0x1828, is taken when v0(=[a0+18]:1) < v1(?) (signed), and falls through when v0(=[a0+18]:1) >= v1(?) (signed).
  The `beq` branch at 0x17e4 targets 0x1828, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `bne` branch at 0x17f4 targets 0x1828, is taken when a5(=[a0+17]:1) < a6(?) (signed), and falls through when a5(=[a0+17]:1) >= a6(?) (signed).
  The `bne` branch at 0x17fc targets 0x1818, is taken when a6(?) != a5(=[a0+17]:1), and falls through when a6(?) == a5(=[a0+17]:1).
  The `bne` branch at 0x1810 targets 0x1828, is taken when a6(=[a0+18]:1) < a7(?) (signed), and falls through when a6(=[a0+18]:1) >= a7(?) (signed).
  The `bne` branch at 0x1820 targets 0x17b0, is taken when a3(?) != 0, and falls through when a3(?) == 0.
  The `beq` branch at 0x1828 targets 0x1864, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `bne` branch at 0x1830 targets 0x1848, is taken when a3(?) != 0, and falls through when a3(?) == 0.
  The return at 0x1840 has v0 = ?.
  The return at 0x185c has v0 = ?.
  The return at 0x1870 has v0 = ?.
  The return at 0x1880 has v0 = ?.

- `pciio_ppb_intr_map` in `IP27/usr/cpu/sysgen/IP27boot/pciio_ppb.o` at 0x1888 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio_ppb.o`.
  Range: 0x1888-0x1968 (224 bytes).
  It occupies 224 bytes.
  The `ld` at 0x18b0 loads 8 bytes from a0 (arg0 at entry) +0x1f0.
  The `lw` at 0x1904 loads 4 bytes from ?.
  3 such `ld` accesses load 8 bytes from ?, including `ld` at 0x1930, `ld` at 0x1934, `ld` at 0x1938.
  The `jal` at 0x18a8 calls pciio_info_slot_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x192c calls pciio_info_slot_get with a0=?, a1=?, a2=?, a3=?.
  The `beq` branch at 0x18bc targets 0x1944, is taken when s1(=[a0+496]:8) == 0, and falls through when s1(=[a0+496]:8) != 0.
  The `beq` branch at 0x18e4 targets 0x190c, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `bne` branch at 0x1924 targets 0x18e4, is taken when a2(?) < 0x4 (signed), and falls through when a2(?) >= 0x4 (signed).
  The `bne` branch at 0x193c targets 0x18c4, is taken when s1(?) != 0, and falls through when s1(?) == 0.
  The return at 0x1960 has v0 = one of a1, ?.

- `ppb_bus_alloc` in `IP27/usr/cpu/sysgen/IP27boot/pciio_ppb.o` at 0x1968 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio_ppb.o`.
  Range: 0x1968-0x1a28 (192 bytes).
  It occupies 192 bytes.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0x197c, `lw` at 0x19a4.
  The `lw` at 0x19f0 loads 4 bytes from table(sym(.bss)) +0x10.
  The `sw` at 0x1a1c stores 4 bytes to table(sym(.bss)) +0x10.
  The `bne` branch at 0x1984 targets 0x19d0, is taken when at(?) < -0x1 (unsigned), and falls through when at(?) >= -0x1 (unsigned).
  The `beq` branch at 0x199c targets 0x19cc, is taken when a3(?) >= 0x8 (unsigned), and falls through when a3(?) < 0x8 (unsigned).
  The `bne` branch at 0x19ac targets 0x19d0, is taken when v1(?) < -0x1 (unsigned), and falls through when v1(?) >= -0x1 (unsigned).
  The `bne` branch at 0x19c4 targets 0x197c, is taken when a3(?) < 0x8 (unsigned), and falls through when a3(?) >= 0x8 (unsigned).
  The `beq` branch at 0x19d0 targets 0x1a20, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x19fc targets 0x1a18, is taken when (a4(=[table(sym(.bss))+16]) & a2(?)) == 0, and falls through when (a4(=[table(sym(.bss))+16]) & a2(?)) != 0.
  The `bne` branch at 0x1a08 targets 0x19f8, is taken when a2(?) != 0, and falls through when a2(?) == 0.
  The return at 0x1a10 has v0 = 0xff.
  The return at 0x1a20 has v0 = one of 0xff, ?.

- `ppb_bus_reserve` in `IP27/usr/cpu/sysgen/IP27boot/pciio_ppb.o` at 0x1a28 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio_ppb.o`.
  Range: 0x1a28-0x1a78 (80 bytes).
  It occupies 80 bytes.
  The `lw` at 0x1a64 loads 4 bytes from table(sym(.bss)) +0x0.
  The `sw` at 0x1a74 stores 4 bytes to table(sym(.bss)) +0x0.
  The return at 0x1a70 has v0 = table(sym(.bss)).

- `ppb_bus_free` in `IP27/usr/cpu/sysgen/IP27boot/pciio_ppb.o` at 0x1a78 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio_ppb.o`.
  Range: 0x1a78-0x1acc (84 bytes).
  It occupies 84 bytes.
  The `lw` at 0x1ab4 loads 4 bytes from table(sym(.bss)) +0x0.
  The `sw` at 0x1ac8 stores 4 bytes to table(sym(.bss)) +0x0.
  The return at 0x1ac4 has v0 = table(sym(.bss)).

- `pciio_ppb_init` in `IP27/usr/cpu/sysgen/IP27boot/pciio_ppb.o` at 0x1acc (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio_ppb.o`.
  Range: 0x1acc-0x1b40 (116 bytes).
  It occupies 116 bytes.
  The `jal` at 0x1ae8 calls init_sema with a0=sym(.bss), a1=0x1, a2=sym(.rodata), a3=-0x1.
  The `jal` at 0x1af4 calls ppb_bus_reserve with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1b10 calls ppb_bus_reserve with a0=0xff, a1=?, a2=?, a3=?.
  The `jal` at 0x1b2c calls pciio_driver_register with a0=-0x1, a1=-0x1, a2=sym(.rodata), a3=0x0.
  The `bne` branch at 0x1b08 targets 0x1af4, is taken when s0(?) < 0x10 (signed), and falls through when s0(?) >= 0x10 (signed).
  The return at 0x1b38 has v0 = ret(pciio_driver_register).

- `pciio_ppb_attach` in `IP27/usr/cpu/sysgen/IP27boot/pciio_ppb.o` at 0x1b40 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio_ppb.o`.
  Range: 0x1b40-0x1c24 (228 bytes).
  It occupies 228 bytes.
  The `jal` at 0x1b50 calls pciio_info_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1b5c calls pciio_info_slot_get with a0=ret(pciio_info_get), a1=?, a2=?, a3=?.
  The `jal` at 0x1b78 calls pciio_config_get with a0=a0 at entry (arg0), a1=0xb, a2=0x1, a3=?.
  The `jal` at 0x1b8c calls pciio_config_get with a0=a0 at entry (arg0), a1=0xa, a2=0x1, a3=?.
  The `jal` at 0x1bdc calls ppb_scan with a0=a0 at entry (arg0), a1=0x6, a2=?, a3=0x4.
  The `jal` at 0x1bf4 calls ppb_addr_space_assign with a0=ret(pciio_info_get), a1=?, a2=?, a3=?.
  The `jal` at 0x1c0c calls ppb_function_print with a0=ret(pciio_info_get), a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x1c14 calls ppb_attach_function with a0=ret(pciio_info_get), a1=?, a2=?, a3=?.
  The `beq` branch at 0x1b6c targets 0x1bd4, is taken when at(?) == v0(=0xff), and falls through when at(?) != v0(=0xff).
  The `bne` branch at 0x1ba8 targets 0x1bc0, is taken when v1(?) != a1(=0x6), and falls through when v1(?) == a1(=0x6).
  The `beq` branch at 0x1bb0 targets 0x1bdc, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x1bb8 targets 0x1bdc, is taken when a0(?) == a3(=0x4), and falls through when a0(?) != a3(=0x4).
  The `beq` branch at 0x1bd4 targets 0x1bc0 and is always taken.
  The `beq` branch at 0x1be4 targets 0x1bf4, is taken when v0(=ret(ppb_scan)) == 0, and falls through when v0(=ret(ppb_scan)) != 0.
  The `beq` branch at 0x1bec targets 0x1bc4 and is always taken.
  The `beq` branch at 0x1c00 targets 0x1c14, is taken when a0(=[sym(showconfig)]) == 0, and falls through when a0(=[sym(showconfig)]) != 0.
  The `beq` branch at 0x1c1c targets 0x1bc0 and is always taken.
  The return at 0x1bcc has v0 = one of 0x0, ret(ppb_scan).

- `ppb_attach_function` in `IP27/usr/cpu/sysgen/IP27boot/pciio_ppb.o` at 0x1c24 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio_ppb.o`.
  Range: 0x1c24-0x1c98 (116 bytes).
  It occupies 116 bytes.
  The `ld` at 0x1c24 loads 8 bytes from a0 (arg0 at entry) +0x1e8.
  The `ld` at 0x1c38 loads 8 bytes from [a0+488]:8 +0x10.
  The `ld` at 0x1c48 loads 8 bytes from [[a0+488]:8+16]:8 +0x1e8.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0x1c54, `ld` at 0x1c60.
  The `jal` at 0x1c4c calls ppb_attach_function with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1c6c calls pciio_info_dev_get with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1c78 calls pciio_device_attach with a0=ret(pciio_info_dev_get), a1=0x0, a2=?, a3=?.
  The `beq` branch at 0x1c30 targets 0x1c88, is taken when a2(=[a0+488]:8) == 0, and falls through when a2(=[a0+488]:8) != 0.
  The `beq` branch at 0x1c3c targets 0x1c8c, is taken when s0(=[[a0+488]:8+16]:8) == 0, and falls through when s0(=[[a0+488]:8+16]:8) != 0.
  The `beq` branch at 0x1c44 targets 0x1c64 and is always taken.
  The `beq` branch at 0x1c58 targets 0x1c88, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `bne` branch at 0x1c64 targets 0x1c4c, is taken when at(?) != 0, and falls through when at(?) == 0.
  The `beq` branch at 0x1c80 targets 0x1c54 and is always taken.
  The return at 0x1c90 has v0 = ?.

- `pciio_ppb_detach` in `IP27/usr/cpu/sysgen/IP27boot/pciio_ppb.o` at 0x1c98 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio_ppb.o`.
  Range: 0x1c98-0x1d0c (116 bytes).
  It occupies 116 bytes.
  The `jal` at 0x1cac calls pciio_config_get with a0=a0 at entry (arg0), a1=0xb, a2=0x1, a3=a3 at entry (arg3).
  The `jal` at 0x1cc0 calls pciio_config_get with a0=a0 at entry (arg0), a1=0xa, a2=0x1, a3=?.
  The `bne` branch at 0x1ce4 targets 0x1cf8, is taken when at(?) != v0(=0x6), and falls through when at(?) == v0(=0x6).
  The `beq` branch at 0x1cec targets 0x1d04, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x1cf4 targets 0x1d04, is taken when a0(?) == a3(=0x4), and falls through when a0(?) != a3(=0x4).
  The `beq` branch at 0x1d04 targets 0x1cfc and is always taken.
  The return at 0x1cfc has v0 = one of 0x0, 0x1.

- `ppb_roundup_log2` in `IP27/usr/cpu/sysgen/IP27boot/pciio_ppb.o` at 0x1d0c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio_ppb.o`.
  Range: 0x1d0c-0x1d60 (84 bytes).
  It occupies 84 bytes.
  The `beq` branch at 0x1d0c targets 0x1d28, is taken when a0 == 0, and falls through when a0 != 0.
  The `beq` branch at 0x1d20 targets 0x1d30, is taken when (a0 & at(=0x8000000000000000)) == 0, and falls through when (a0 & at(=0x8000000000000000)) != 0.
  The `bne` branch at 0x1d30 targets 0x1d54, is taken when a3(?) != 0, and falls through when a3(?) == 0.
  The `beq` branch at 0x1d3c targets 0x1d4c, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `bne` branch at 0x1d44 targets 0x1d38, is taken when a3(?) != 0, and falls through when a3(?) == 0.
  The return at 0x1d28 has v0 = 0x0.
  The return at 0x1d4c has v0 = ?.
  The return at 0x1d58 has v0 = 0x1.

- `pciio_ppb_businfo_get` in `IP27/usr/cpu/sysgen/IP27boot/pciio_ppb.o` at 0x1d60 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pciio_ppb.o`.
  Range: 0x1d60-0x1da8 (72 bytes).
  It occupies 72 bytes.
  The `ld` at 0x1d78 loads 8 bytes from ret(pciio_info_get) +0x1e8.
  The `sw` at 0x1d84 stores 4 bytes to [ret(pciio_info_get)+488]:8 +0x78.
  The `sw` at 0x1d88 stores 4 bytes to [ret(pciio_info_get)+488]:8 +0x74.
  The `sw` at 0x1d8c stores 4 bytes to [ret(pciio_info_get)+488]:8 +0x70.
  The `sw` at 0x1d94 stores 4 bytes to [ret(pciio_info_get)+488]:8 +0x6c.
  The `jal` at 0x1d68 calls pciio_info_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0x1d70 targets 0x1da0, is taken when v0(=ret(pciio_info_get)) == 0, and falls through when v0(=ret(pciio_info_get)) != 0.
  The `beq` branch at 0x1d7c targets 0x1da0, is taken when a2(=[ret(pciio_info_get)+488]:8) == 0, and falls through when a2(=[ret(pciio_info_get)+488]:8) != 0.
  The `beq` branch at 0x1da0 targets 0x1d98 and is always taken.
  The return at 0x1d98 has v0 = one of [ret(pciio_info_get)+488]:8+108, 0x0.
