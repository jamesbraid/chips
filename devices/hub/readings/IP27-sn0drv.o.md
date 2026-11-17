# Readings: `IP27/usr/cpu/sysgen/IP27boot/sn0drv.o`

One entry per routine, filed here from the reading batches by binary.

- `sn0drv_attach` in `IP27/usr/cpu/sysgen/IP27boot/sn0drv.o` at 0x0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/sn0drv.o`.
  Range: 0x0-0x254 (596 bytes).
  It occupies 596 bytes.
  The `ld` at 0xb0 loads 8 bytes from abs 0xffffffffffffc400.
  The `lh` at 0xb4 loads 2 bytes from ?.
  The `ld` at 0xb8 loads 8 bytes from [-0x3c00]:8 +0x0.
  The `ld` at 0xc8 loads 8 bytes from ?.
  The `jal` at 0x18 calls hwgraph_info_get_LBL with a0=a0 at entry (arg0), a1=sym(.rodata), a2=sp-64, a3=a3 at entry (arg3).
  The `jal` at 0x34 calls hwgraph_char_device_add with a0=a0 at entry (arg0), a1=sym(.rodata), a2=sym(.rodata), a3=sp-52.
  The `jal` at 0x44 calls hwgfs_chmod with a0=?, a1=0x1a4, a2=?, a3=?.
  The `jal` at 0x58 calls hwgraph_info_get_LBL with a0=a0 at entry (arg0), a1=sym(.rodata), a2=sp-48, a3=?.
  The `jal` at 0x68 calls device_master_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x84 calls hwgraph_info_get_LBL with a0=ret(device_master_get), a1=sym(.rodata), a2=sp-40, a3=?.
  The `jal` at 0xa0 calls hwgraph_info_get_LBL with a0=a0 at entry (arg0), a1=sym(.rodata), a2=sp-32, a3=ret(hwgraph_info_get_LBL), a6=sym(.rodata).
  The `jal` at 0xd4 calls hwgraph_info_add_LBL with a0=?, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0xe0 calls device_info_set with a0=?, a1=0x2, a2=?, a3=?.
  The `jal` at 0x10c calls hwgraph_char_device_add with a0=a0 at entry (arg0), a1=sym(.rodata), a2=sym(.rodata), a3=sp-56.
  The `jal` at 0x11c calls hwgfs_chmod with a0=?, a1=0x1a4, a2=?, a3=?.
  The `jal` at 0x128 calls device_info_set with a0=?, a1=0x3, a2=?, a3=?.
  The `jal` at 0x140 calls hwgraph_char_device_add with a0=a0 at entry (arg0), a1=sym(.rodata), a2=sym(.rodata), a3=sp-56.
  The `jal` at 0x150 calls hwgfs_chmod with a0=?, a1=0x1a4, a2=?, a3=?.
  The `jal` at 0x15c calls device_info_set with a0=?, a1=0x4, a2=?, a3=?.
  The `jal` at 0x178 calls hwgraph_info_get_LBL with a0=a0 at entry (arg0), a1=sym(.rodata), a2=sp-40, a3=?.
  The `jal` at 0x1a0 calls hwgraph_info_add_LBL with a0=?, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x1b0 calls hwgraph_info_add_LBL with a0=?, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x1bc calls device_info_set with a0=?, a1=0x1, a2=?, a3=?.
  The `jal` at 0x1d8 calls hwgraph_info_add_LBL with a0=?, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x1f4 calls cmn_err with a0=0x4, a1=sym(.rodata), a2=a0 at entry (arg0), a3=ret(hwgraph_char_device_add).
  The `jal` at 0x20c calls cmn_err with a0=0x4, a1=sym(.rodata), a2=a0 at entry (arg0), a3=ret(hwgraph_info_get_LBL), a6=sym(.rodata).
  The `jal` at 0x228 calls cmn_err with a0=0x4, a1=sym(.rodata), a2=a0 at entry (arg0), a3=ret(hwgraph_char_device_add).
  The `jal` at 0x244 calls cmn_err with a0=0x4, a1=sym(.rodata), a2=a0 at entry (arg0), a3=ret(hwgraph_char_device_add).
  The `beq` branch at 0x20 targets 0xfc, is taken when v0(=ret(hwgraph_info_get_LBL)) == 0, and falls through when v0(=ret(hwgraph_info_get_LBL)) != 0.
  The `bne` branch at 0x3c targets 0x1e8, is taken when v0(=ret(hwgraph_char_device_add)) != 0, and falls through when v0(=ret(hwgraph_char_device_add)) == 0.
  The `beq` branch at 0x60 targets 0x194, is taken when v0(=ret(hwgraph_info_get_LBL)) == 0, and falls through when v0(=ret(hwgraph_info_get_LBL)) != 0.
  The `beq` branch at 0x74 targets 0x16c, is taken when v0(=ret(device_master_get)) == a2(=-0x1), and falls through when v0(=ret(device_master_get)) != a2(=-0x1).
  The `bne` branch at 0x90 targets 0x204, is taken when v0(=ret(hwgraph_info_get_LBL)) != 0, and falls through when v0(=ret(hwgraph_info_get_LBL)) == 0.
  The `beq` branch at 0xa8 targets 0x1cc, is taken when v0(=ret(hwgraph_info_get_LBL)) == 0, and falls through when v0(=ret(hwgraph_info_get_LBL)) != 0.
  The `bne` branch at 0x114 targets 0x21c, is taken when v0(=ret(hwgraph_char_device_add)) != 0, and falls through when v0(=ret(hwgraph_char_device_add)) == 0.
  The `bne` branch at 0x148 targets 0x238, is taken when v0(=ret(hwgraph_char_device_add)) != 0, and falls through when v0(=ret(hwgraph_char_device_add)) == 0.
  The `beq` branch at 0x164 targets 0xec and is always taken.
  The `beq` branch at 0x184 targets 0x98, is taken when v0(=ret(hwgraph_info_get_LBL)) == 0, and falls through when v0(=ret(hwgraph_info_get_LBL)) != 0.
  The `beq` branch at 0x18c targets 0x208 and is always taken.
  The `beq` branch at 0x1c4 targets 0xec and is always taken.
  The `beq` branch at 0x1e0 targets 0xb0 and is always taken.
  The `beq` branch at 0x1fc targets 0x44 and is always taken.
  The `beq` branch at 0x214 targets 0xec and is always taken.
  The `beq` branch at 0x230 targets 0x11c and is always taken.
  The `beq` branch at 0x24c targets 0x150 and is always taken.
  The return at 0xf4 has v0 = 0x0.

- `sndrv_attach` in `IP27/usr/cpu/sysgen/IP27boot/sn0drv.o` at 0x254 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/sn0drv.o`.
  Range: 0x254-0x270 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x25c calls sn0drv_attach with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x268 has v0 = ret(sn0drv_attach).

- `sn0drv_open` in `IP27/usr/cpu/sysgen/IP27boot/sn0drv.o` at 0x270 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/sn0drv.o`.
  Range: 0x270-0x29c (44 bytes).
  It occupies 44 bytes.
  The `lw` at 0x27c loads 4 bytes from a0 (arg0 at entry) +0x0.
  The `jal` at 0x278 calls device_info_get with a0=[a0], a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `bne` branch at 0x280 targets 0x290, is taken when v0(=ret(device_info_get)) != 0, and falls through when v0(=ret(device_info_get)) == 0.
  The `beq` branch at 0x288 targets 0x294 and is always taken.
  The return at 0x294 has v0 = one of 0x0, 0x13.

- `sn0drv_close` in `IP27/usr/cpu/sysgen/IP27boot/sn0drv.o` at 0x29c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/sn0drv.o`.
  Range: 0x29c-0x2a4 (8 bytes).
  It occupies 8 bytes.
  The return at 0x29c has v0 = 0x0.

- `sn0drv_ioctl` in `IP27/usr/cpu/sysgen/IP27boot/sn0drv.o` at 0x2a4.
  This is the ioctl entry of the sn0drv object. It compares the command, a1-8, with 0xf, unsigned (0x2dc). Commands at or above 0xf go to sndrv_ioctl_common (0x2f8) with the same four arguments and return its result. Commands below 0xf load a handler address (0x2e4) and tail-call it through a register (0x2e8) with the same four arguments; the facts do not resolve the table or the targets. The facts show nothing between 0x324 and 0xb6c.
  Grade: inferred.
  Reviewed: 2026-11-12

- `check_router` in `IP27/usr/cpu/sysgen/IP27boot/sn0drv.o` at 0xb70 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/sn0drv.o`.
  Range: 0xb70-0xc20 (176 bytes).
  It occupies 176 bytes.
  3 such `sw` accesses store 4 bytes to a3 (arg3 at entry) +0x0, including `sw` at 0xba4, `sw` at 0xc00, `sw` at 0xc1c.
  The `ld` at 0xbf4 loads 8 bytes from a1 (arg1 at entry) +0x0.
  The `jal` at 0xb88 calls device_info_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xbc4 calls cap_able_cred with a0=a2 at entry (arg2), a1=0x2000000000, a2=?, a3=0x16, a6=-0x1.
  The `jal` at 0xbe0 calls hwgraph_info_get_LBL with a0=a0 at entry (arg0), a1=sym(.rodata), a2=a1 at entry (arg1), a3=?, a6=-0x1.
  The `beq` branch at 0xb9c targets 0xbbc, is taken when at(=0x1) == v0(=(ret(device_info_get) << 0x0)), and falls through when at(=0x1) != v0(=(ret(device_info_get) << 0x0)).
  The `beq` branch at 0xbcc targets 0xc14, is taken when v0(=ret(cap_able_cred)) == 0, and falls through when v0(=ret(cap_able_cred)) != 0.
  The `bne` branch at 0xbe8 targets 0xbfc, is taken when v0(=ret(hwgraph_info_get_LBL)) != 0, and falls through when v0(=ret(hwgraph_info_get_LBL)) == 0.
  The `bne` branch at 0xbf8 targets 0xc0c, is taken when a2(=[a1]:8) != 0, and falls through when a2(=[a1]:8) == 0.
  The `beq` branch at 0xc04 targets 0xba8 and is always taken.
  The `beq` branch at 0xc0c targets 0xbac and is always taken.
  The `beq` branch at 0xc18 targets 0xba8 and is always taken.
  The return at 0xbb4 has v0 = one of -0x1, 0x0.

- `do_reg_op` in `IP27/usr/cpu/sysgen/IP27boot/sn0drv.o` at 0xc20 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/sn0drv.o`.
  Range: 0xc20-0xce4 (196 bytes).
  It occupies 196 bytes.
  2 such `ld` accesses load 8 bytes from a1 (arg1 at entry) +0x1a8, including `ld` at 0xc8c, `ld` at 0xccc.
  The `ld` at 0xcac loads 8 bytes from a3 (arg3 at entry) +0x0.
  The `jal` at 0xc68 calls router_reg_read with a0=a1 at entry (arg1), a1=a2 at entry (arg2), a2=a3 at entry (arg3), a3=a3 at entry (arg3), a6=a2 at entry (arg2).
  The `jal` at 0xc7c calls net_errmsg with a0=ret(router_reg_read), a1=?, a2=ret(router_reg_read), a3=?.
  The `jal` at 0xc94 calls printf with a0=sym(.rodata), a1=[a1+424]:8, a2=ret(router_reg_read), a3=ret(net_errmsg).
  The `jal` at 0xca8 calls router_reg_write with a0=a1 at entry (arg1), a1=a2 at entry (arg2), a2=[a3]:8, a3=a3 at entry (arg3), a6=a2 at entry (arg2).
  The `jal` at 0xcbc calls net_errmsg with a0=ret(router_reg_write), a1=?, a2=ret(router_reg_write), a3=?.
  The `jal` at 0xcd4 calls printf with a0=sym(.rodata), a1=[a1+424]:8, a2=ret(router_reg_write), a3=ret(net_errmsg).
  The `beq` branch at 0xc38 targets 0xc60, is taken when a0 == at(=0x1), and falls through when a0 != at(=0x1).
  The `beq` branch at 0xc40 targets 0xca4, is taken when a0 == v0(=0x2), and falls through when a0 != v0(=0x2).
  The `beq` branch at 0xc74 targets 0xc4c, is taken when v0(=ret(router_reg_read)) == 0, and falls through when v0(=ret(router_reg_read)) != 0.
  The `beq` branch at 0xc9c targets 0xc50 and is always taken.
  The `beq` branch at 0xcb4 targets 0xc4c, is taken when v0(=ret(router_reg_write)) == 0, and falls through when v0(=ret(router_reg_write)) != 0.
  The `beq` branch at 0xcdc targets 0xc50 and is always taken.
  The return at 0xc58 has v0 = one of ?, ret(router_reg_read), ret(router_reg_write).

- `do_router_op` in `IP27/usr/cpu/sysgen/IP27boot/sn0drv.o` at 0xce4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/sn0drv.o`.
  Range: 0xce4-0xdf0 (268 bytes).
  It occupies 268 bytes.
  The `lh` at 0xcf4 loads 2 bytes from a0 (arg0 at entry) +0x0.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x8, including `ld` at 0xd68, `ld` at 0xdbc.
  2 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x8, including `sd` at 0xd8c, `sd` at 0xdec.
  The `jal` at 0xd54 calls do_reg_op with a0=0x1, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=sp-48, a5=0x4, a6=0x8, a7=0xa.
  The `jal` at 0xd78 calls do_reg_op with a0=0x2, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=sp-48.
  The `jal` at 0xd94 calls do_reg_op with a0=0x1, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a0+8, a5=0x4, a6=0x8, a7=0xa.
  The `jal` at 0xda4 calls do_reg_op with a0=0x2, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a0+8, a5=0x4, a6=0x8, a7=0xa.
  The `jal` at 0xdb4 calls do_reg_op with a0=0x1, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=sp-48, a5=0x4, a6=0x8, a7=0xa.
  The `jal` at 0xdd8 calls do_reg_op with a0=0x2, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=sp-48.
  The `beq` branch at 0xd14 targets 0xd90, is taken when v0(=[a0]:2) == at(=0x2), and falls through when v0(=[a0]:2) != at(=0x2).
  The `beq` branch at 0xd1c targets 0xda4, is taken when v0(=[a0]:2) == a5(=0x4), and falls through when v0(=[a0]:2) != a5(=0x4).
  The `beq` branch at 0xd24 targets 0xdb4, is taken when v0(=[a0]:2) == a6(=0x8), and falls through when v0(=[a0]:2) != a6(=0x8).
  The `beq` branch at 0xd2c targets 0xd54, is taken when v0(=[a0]:2) == a7(=0xa), and falls through when v0(=[a0]:2) != a7(=0xa).
  The `beq` branch at 0xd88 targets 0xd38 and is always taken.
  The `beq` branch at 0xd9c targets 0xd38 and is always taken.
  The `beq` branch at 0xdac targets 0xd38 and is always taken.
  The `beq` branch at 0xde8 targets 0xd38 and is always taken.
  The return at 0xd4c has v0 = one of 0x0, ret(do_reg_op).

- `rou_fence_op` in `IP27/usr/cpu/sysgen/IP27boot/sn0drv.o` at 0xdf0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/sn0drv.o`.
  Range: 0xdf0-0xeb4 (196 bytes).
  It occupies 196 bytes.
  The `lbu` at 0xe34 loads 1 byte from a1 (arg1 at entry) +0x8.
  The `jal` at 0xe0c calls do_router_op with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0x10, a3=a3 at entry (arg3).
  The `jal` at 0xe68 calls do_router_op with a0=?, a1=a1 at entry (arg1), a2=?, a3=?, a5=[a1+8]:1.
  The `bltz` branch at 0xe24 targets 0xe90, is taken when v0(=ret(do_router_op)) < 0 (signed), and falls through when v0(=ret(do_router_op)) >= 0 (signed).
  The `beq` branch at 0xe30 targets 0xe44 and is always taken.
  The `beq` branch at 0xe3c targets 0xe90, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0xe50 targets 0xe38, is taken when (a5(=[a1+8]:1) & at(?)) == 0, and falls through when (a5(=[a1+8]:1) & at(?)) != 0.
  The `bltz` branch at 0xe78 targets 0xe90, is taken when v0(=ret(do_router_op)) < 0 (signed), and falls through when v0(=ret(do_router_op)) >= 0 (signed).
  The `bne` branch at 0xe88 targets 0xe30, is taken when a4(?) != 0, and falls through when a4(?) == 0.
  The return at 0xeac has v0 = ret(do_router_op).

- `router_port_map_get` in `IP27/usr/cpu/sysgen/IP27boot/sn0drv.o` at 0xeb4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/sn0drv.o`.
  Range: 0xeb4-0xfd8 (292 bytes).
  It occupies 292 bytes.
  2 such `sb` accesses store 1 byte to ?, including `sb` at 0xeec, `sb` at 0xf44.
  3 such `lh` accesses load 2 bytes from a0 (arg0 at entry) +0x2, including `lh` at 0xef4, `lh` at 0xf10, `lh` at 0xf80.
  The `lh` at 0xf14 loads 2 bytes from abs 0xffffffffffffc422.
  2 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x8, including `lbu` at 0xf5c, `lbu` at 0xfd4.
  The `ld` at 0xf70 loads 8 bytes from a0 (arg0 at entry) +0x18.
  The `lw` at 0xf88 loads 4 bytes from a0 (arg0 at entry) +0x20.
  The `jal` at 0xef0 calls cnodetocpu with a0=[a0+2]:2, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=?, a4=0xff.
  The `jal` at 0xefc calls setmustrun with a0=ret(cnodetocpu), a1=?, a2=?, a3=?.
  The `jal` at 0xf74 calls vector_concat with a0=[a0+24]:8, a1=?, a2=?, a3=?.
  The `jal` at 0xf8c calls hub_vector_read with a0=[a0+2]:2, a1=ret(vector_concat), a2=[a0+32], a3=0x0, a4=sp-64.
  The `jal` at 0xfbc calls restoremustrun with a0=?, a1=?, a2=?, a3=?.
  The `bne` branch at 0xee8 targets 0xedc, is taken when a3(?) < 0x7 (signed), and falls through when a3(?) >= 0x7 (signed).
  The `bne` branch at 0xf30 targets 0xfa4, is taken when v1(=[-0x3bde]:2) != a0(=[a0+2]:2), and falls through when v1(=[-0x3bde]:2) == a0(=[a0+2]:2).
  The `beq` branch at 0xf38 targets 0xfd0 and is always taken.
  The `beq` branch at 0xf54 targets 0xfa4, is taken when s0(?) >= 0x7 (signed), and falls through when s0(?) < 0x7 (signed).
  The `beq` branch at 0xf68 targets 0xf48, is taken when (a5(=[a0+8]:1) & a6(?)) == 0, and falls through when (a5(=[a0+8]:1) & a6(?)) != 0.
  The `bgez` branch at 0xf94 targets 0xf40, is taken when v0(=ret(hub_vector_read)) >= 0 (signed), and falls through when v0(=ret(hub_vector_read)) < 0 (signed).
  The `beq` branch at 0xf9c targets 0xf4c and is always taken.
  The `beq` branch at 0xfd0 targets 0xf60 and is always taken.
  The return at 0xfc8 has v0 = ret(restoremustrun).

- `router_port_mfg_info_get` in `IP27/usr/cpu/sysgen/IP27boot/sn0drv.o` at 0xfd8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/sn0drv.o`.
  Range: 0xfd8-0x10e0 (264 bytes).
  It occupies 264 bytes.
  The `lbu` at 0xfd8 loads 1 byte from a0 (arg0 at entry) +0x8.
  3 such `lh` accesses load 2 bytes from a0 (arg0 at entry) +0x2, including `lh` at 0x1010, `lh` at 0x1028, `lh` at 0x1080.
  The `lh` at 0x1030 loads 2 bytes from abs 0xffffffffffffc422.
  The `ld` at 0x1070 loads 8 bytes from a0 (arg0 at entry) +0x18.
  The `lw` at 0x108c loads 4 bytes from a0 (arg0 at entry) +0x20.
  The `jal` at 0x1018 calls cnodetocpu with a0=[a0+2]:2, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a5=-0x1, a6=0x1.
  The `jal` at 0x1020 calls setmustrun with a0=ret(cnodetocpu), a1=?, a2=?, a3=?.
  The `jal` at 0x1050 calls restoremustrun with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1074 calls vector_concat with a0=[a0+24]:8, a1=a1 at entry (arg1), a2=[a0+2]:2, a3=?.
  The `jal` at 0x1090 calls hub_vector_read with a0=[a0+2]:2, a1=ret(vector_concat), a2=[a0+32], a3=0x0, a4=sp-64.
  The `jal` at 0x10c8 calls router_nic_get with a0=ret(vector_concat), a1=a2 at entry (arg2), a2=?, a3=?, a4=0x1.
  The `beq` branch at 0x1008 targets 0x105c, is taken when (at(=[a0+8]:1) & v1(?)) == 0, and falls through when (at(=[a0+8]:1) & v1(?)) != 0.
  The `beq` branch at 0x1048 targets 0x1070, is taken when a1(=[-0x3bde]:2) == a2(=[a0+2]:2), and falls through when a1(=[-0x3bde]:2) != a2(=[a0+2]:2).
  The `bltz` branch at 0x10a0 targets 0x10bc, is taken when v0(=ret(hub_vector_read)) < 0 (signed), and falls through when v0(=ret(hub_vector_read)) >= 0 (signed).
  The `bne` branch at 0x10ac targets 0x1050, is taken when a4(=0x1) != a6(?), and falls through when a4(=0x1) == a6(?).
  The `beq` branch at 0x10b4 targets 0x10c4 and is always taken.
  The `beq` branch at 0x10bc targets 0x1050 and is always taken.
  The `beq` branch at 0x10d8 targets 0x1050 and is always taken.
  The return at 0x1068 has v0 = one of -0x1, 0x0.
