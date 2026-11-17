# Readings: `IP32/usr/cpu/sysgen/IP32boot/pcimh.o`

One entry per routine, filed here from the reading batches by binary.

- `pcimh_attach` in `IP32/usr/cpu/sysgen/IP32boot/pcimh.o` at 0x0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pcimh.o`.
  Range: 0x0-0xfc (252 bytes).
  It occupies 252 bytes.
  The `sw` at 0x78 stores 4 bytes to ret(kmem_zalloc) +0x128.
  The `sw` at 0x80 stores 4 bytes to ret(kmem_zalloc) +0x14.
  The `sw` at 0x84 stores 4 bytes to ret(kmem_zalloc) +0x10.
  The `sb` at 0x8c stores 1 byte to ret(kmem_zalloc) +0xe.
  The `sb` at 0x90 stores 1 byte to ret(kmem_zalloc) +0xd.
  The `sb` at 0x94 stores 1 byte to ret(kmem_zalloc) +0xc.
  The `sw` at 0x9c stores 4 bytes to ret(kmem_zalloc) +0x18.
  The `sw` at 0xac stores 4 bytes to ret(kmem_zalloc) +0x20.
  The `sw` at 0xb8 stores 4 bytes to ret(kmem_zalloc) +0x20c.
  The `sw` at 0xbc stores 4 bytes to ret(kmem_zalloc) +0x208.
  The `sw` at 0xc0 stores 4 bytes to ret(kmem_zalloc) +0x24.
  The `sw` at 0xdc stores 4 bytes to ret(kmem_zalloc) +0x4.
  The `sw` at 0xe8 stores 4 bytes to sym(pcimh_devflag) +0x10.
  The `jal` at 0x10 calls hwgraph_path_add with a0=a0 at entry (arg0), a1=sym(.rodata)+16, a2=sym(.sbss), a3=a3 at entry (arg3).
  The `jal` at 0x2c calls hwgraph_char_device_add with a0=[sym(.sbss)], a1=sym(.rodata), a2=sym(.rodata)+24, a3=0x0.
  The `jal` at 0x3c calls pciio_provider_register with a0=[sym(.sbss)], a1=sym(.data)+352, a2=?, a3=?.
  The `jal` at 0x44 calls pciio_provider_startup with a0=[sym(.sbss)], a1=?, a2=?, a3=?.
  The `jal` at 0x60 calls setcrimevector with a0=0x7, a1=0x1, a2=sym(mace_pci_error), a3=0x0, a4=0x0.
  The `jal` at 0x70 calls kmem_zalloc with a0=0x210, a1=0x0, a2=?, a3=?.
  The `jal` at 0xa4 calls hwgraph_fastinfo_get with a0=[sym(.sbss)], a1=?, a2=?, a3=[sym(.sbss)], a4=-0x1, a5=0xff.
  The `jal` at 0xb0 calls pciio_provider_fns_get with a0=[sym(.sbss)], a1=?, a2=?, a3=?.
  The `jal` at 0xc8 calls pciio_device_info_register with a0=[sym(.sbss)], a1=ret(kmem_zalloc), a2=?, a3=?.
  The `jal` at 0xe4 calls pcimh_scan_bus with a0=ret(kmem_zalloc), a1=?, a2=?, a3=?, a6=sym(.sdata)+16, a7=ret(kmem_zalloc)+516.
  The return at 0xf4 has v0 = ret(pcimh_scan_bus).

- `pcimh_scan_bus` in `IP32/usr/cpu/sysgen/IP32boot/pcimh.o` at 0xfc (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pcimh.o`.
  Range: 0xfc-0x72c (1584 bytes).
  It occupies 1584 bytes.
  The `lw` at 0xfc loads 4 bytes from a0 (arg0 at entry) +0x20c.
  The `sb` at 0x270 stores 1 byte to ret(kmem_zalloc) +0xc.
  3 such `sb` accesses store 1 byte to ret(kmem_zalloc) +0xd, including `sb` at 0x27c, `sb` at 0x2cc, `sb` at 0x5c0.
  The `sw` at 0x290 stores 4 bytes to ret(kmem_zalloc) +0x128.
  The `sw` at 0x294 stores 4 bytes to ret(kmem_zalloc) +0x14.
  The `sw` at 0x298 stores 4 bytes to ret(kmem_zalloc) +0x10.
  The `sb` at 0x29c stores 1 byte to ret(kmem_zalloc) +0xe.
  The `lw` at 0x2a0 loads 4 bytes from a0 (arg0 at entry) +0x18.
  The `sw` at 0x2a4 stores 4 bytes to ret(kmem_zalloc) +0x18.
  The `lw` at 0x2a8 loads 4 bytes from a0 (arg0 at entry) +0x20.
  The `sw` at 0x2ac stores 4 bytes to ret(kmem_zalloc) +0x20.
  The `lw` at 0x2b0 loads 4 bytes from a0 (arg0 at entry) +0x24.
  The `sw` at 0x2b4 stores 4 bytes to ret(kmem_zalloc) +0x208.
  The `sw` at 0x2b8 stores 4 bytes to ret(kmem_zalloc) +0x24.
  The `sw` at 0x2d0 stores 4 bytes to ret(kmem_zalloc) +0x4.
  The `sw` at 0x31c stores 4 bytes to sym(pcimh_devflag) +0x10.
  The `lw` at 0x378 loads 4 bytes from ret(kmem_zalloc) +0x1fc.
  The `sw` at 0x384 stores 4 bytes to ret(kmem_zalloc) +0x1fc.
  3 such `sw` accesses store 4 bytes to ?, including `sw` at 0x3d0, `sw` at 0x3d8, `sw` at 0x3e4.
  The `sw` at 0x4e0 stores 4 bytes to ret(kmem_zalloc) +0x1f4.
  The `sw` at 0x4e4 stores 4 bytes to ret(kmem_zalloc) +0x1f0.
  The `sw` at 0x4ec stores 4 bytes to ret(kmem_zalloc) +0x1ec.
  The `lw` at 0x560 loads 4 bytes from ret(kmem_zalloc) +0x4.
  3 such `lw` accesses load 4 bytes from ?, including `lw` at 0x638, `lw` at 0x668, `lw` at 0x674.
  The `lw` at 0x65c loads 4 bytes from table(sym(.data)) +0x18.
  The `lbu` at 0x6c0 loads 1 byte from ret(kmem_zalloc) +0xc.
  The `lw` at 0x6ec loads 4 bytes from sym(.data) +0x28.
  The `jal` at 0x200 calls pcimh_config_ptr_get with a0=?, a1=0x0, a2=0x2, a3=?.
  The `jal` at 0x220 calls pcimh_config_ptr_get with a0=?, a1=0x2, a2=0x2, a3=?.
  The `jal` at 0x234 calls pcimh_config_ptr_get with a0=?, a1=0xe, a2=0x1, a3=?.
  The `jal` at 0x25c calls kmem_zalloc with a0=0x210, a1=0x0, a2=?, a3=?.
  The `jal` at 0x2bc calls pciio_device_info_register with a0=[sym(.sbss)], a1=ret(kmem_zalloc), a2=[a0+32], a3=[a0+24].
  The `jal` at 0x2ec calls do_bist_for with a0=ret(kmem_zalloc), a1=?, a2=?, a3=?, a7=[sym(enable_pci_BIST)].
  The `jal` at 0x350 calls pcimh_config_ptr_setget with a0=?, a1=?, a2=0x4, a3=-0x1.
  The `jal` at 0x3e8 calls pcimh_config_ptr_set with a0=?, a1=?, a2=0x4, a3=?.
  The `jal` at 0x430 calls pcimh_config_ptr_set with a0=?, a1=?, a2=0x4, a3=0x0.
  The `jal` at 0x44c calls pcimh_config_ptr_setget with a0=?, a1=0x30, a2=0x4, a3=0x0.
  The `jal` at 0x46c calls pcimh_config_ptr_setget with a0=?, a1=0x30, a2=0x4, a3=-0x1000, a7=-0x1.
  The `jal` at 0x4d4 calls pcimh_config_ptr_set with a0=?, a1=0x30, a2=0x4, a3=?.
  The `jal` at 0x508 calls pcimh_config_ptr_set with a0=?, a1=0xc, a2=0x1, a3=0x20.
  The `jal` at 0x51c calls pcimh_config_ptr_set with a0=?, a1=0xd, a2=0x1, a3=0x30.
  The `jal` at 0x52c calls pcimh_config_ptr_get with a0=?, a1=0x4, a2=0x2, a3=?.
  The `jal` at 0x54c calls pcimh_config_ptr_set with a0=?, a1=0x4, a2=0x2, a3=?.
  The `jal` at 0x55c calls pciio_device_attach with a0=[ret(kmem_zalloc)+4], a1=0x0, a2=?, a3=?.
  The `jal` at 0x5d4 calls pcimh_scan_subbus with a0=a0 at entry (arg0), a1=one of 0x5, 0x20, a2=?, a3=?.
  The `jal` at 0x688 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x6bc calls cmn_err with a0=0x6, a1=sym(.rodata), a2=ret(pciio_device_info_register), a3=[ret(kmem_zalloc)+12]:1, a5=(ret(pcimh_config_ptr_get) << 0x0), a6=(ret(pcimh_config_ptr_get) << 0x0).
  The `jal` at 0x6e8 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata)+1216, a3=?.
  The `jal` at 0x6fc calls cmn_err with a0=0x6, a1=sym(.rodata)+188, a2=?, a3=?.
  The `jal` at 0x714 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0x134 targets 0x624, is taken when at(=[sym(showconfig)]) == 0, and falls through when at(=[sym(showconfig)]) != 0.
  The `beq` branch at 0x140 targets 0x70c, is taken when a0(=[a0+524]) == 0, and falls through when a0(=[a0+524]) != 0.
  The `beq` branch at 0x14c targets 0x630, is taken when a1(=[a0+524]) == 0, and falls through when a1(=[a0+524]) != 0.
  The `bne` branch at 0x160 targets 0x5c4, is taken when a1(=one of 0x5, 0x20) < a3(?) (signed), and falls through when a1(=one of 0x5, 0x20) >= a3(?) (signed).
  The `beq` branch at 0x184 targets 0x1b8 and is always taken.
  The `beq` branch at 0x19c targets 0x1a8, is taken when a5(=[a0+524]) == 0, and falls through when a5(=[a0+524]) != 0.
  The `bne` branch at 0x1b0 targets 0x5cc, is taken when a1(=one of 0x5, 0x20) < a7(?) (signed), and falls through when a1(=one of 0x5, 0x20) >= a7(?) (signed).
  The `beq` branch at 0x1d0 targets 0x1ec and is always taken.
  The `beq` branch at 0x1d8 targets 0x18c, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0x1e4 targets 0x190, is taken when s0(?) >= 0x8 (signed), and falls through when s0(?) < 0x8 (signed).
  The `beq` branch at 0x20c targets 0x1d8, is taken when s2(=(ret(pcimh_config_ptr_get) << 0x0)) == 0, and falls through when s2(=(ret(pcimh_config_ptr_get) << 0x0)) != 0.
  The `beq` branch at 0x214 targets 0x1d8, is taken when s4(=0xffff) == s2(=(ret(pcimh_config_ptr_get) << 0x0)), and falls through when s4(=0xffff) != s2(=(ret(pcimh_config_ptr_get) << 0x0)).
  The `beq` branch at 0x23c targets 0x320, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0x248 targets 0x334, is taken when s8(=0x1) == a2(?), and falls through when s8(=0x1) != a2(?).
  The `bnel` branch at 0x250 targets 0x1e0, is taken when a2(?) != 0, and falls through when a2(?) == 0; its branch-likely delay slot `addiu s0,s0,1` at 0x254 runs only when taken and is annulled on fall-through.
  The `blez` branch at 0x26c targets 0x5b4, is taken when t8(=[a0+524]) <= 0 (signed), and falls through when t8(=[a0+524]) > 0 (signed).
  The `bne` branch at 0x2d8 targets 0x698, is taken when a4(=[sym(showconfig)]) != 0, and falls through when a4(=[sym(showconfig)]) == 0.
  The `beq` branch at 0x2e4 targets 0x2fc, is taken when a7(=[sym(enable_pci_BIST)]) == 0, and falls through when a7(=[sym(enable_pci_BIST)]) != 0.
  The `beq` branch at 0x318 targets 0x724 and is always taken.
  The `bne` branch at 0x324 targets 0x248, is taken when (a1(=(ret(pcimh_config_ptr_get) << 0x0)) & 0x80) != 0, and falls through when (a1(=(ret(pcimh_config_ptr_get) << 0x0)) & 0x80) == 0.
  The `beq` branch at 0x32c targets 0x244 and is always taken.
  The `beq` branch at 0x33c targets 0x250 and is always taken.
  The `beq` branch at 0x35c targets 0x3fc, is taken when v0(=ret(pcimh_config_ptr_setget)) == 0, and falls through when v0(=ret(pcimh_config_ptr_setget)) != 0.
  The `beq` branch at 0x36c targets 0x3fc, is taken when t9(=-0x1) == v0(=ret(pcimh_config_ptr_setget)), and falls through when t9(=-0x1) != v0(=ret(pcimh_config_ptr_setget)).
  The `beq` branch at 0x380 targets 0x56c, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0x3a4 targets 0x3b4, is taken when a2(?) >= 0xfff (unsigned), and falls through when a2(?) < 0xfff (unsigned).
  The `bne` branch at 0x3f4 targets 0x638, is taken when a4(=[sym(showconfig)]) != 0, and falls through when a4(=[sym(showconfig)]) == 0.
  The `beq` branch at 0x410 targets 0x440, is taken when s7(?) >= 0x6 (signed), and falls through when s7(?) < 0x6 (signed).
  The `bne` branch at 0x418 targets 0x348, is taken when a6(?) != 0, and falls through when a6(?) == 0.
  The `beq` branch at 0x420 targets 0x344, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0x438 targets 0x3fc and is always taken.
  The `beq` branch at 0x458 targets 0x4fc, is taken when a7(=-0x1) == v0(=ret(pcimh_config_ptr_setget)), and falls through when a7(=-0x1) != v0(=ret(pcimh_config_ptr_setget)).
  The `beq` branch at 0x480 targets 0x4fc, is taken when t1(=-0x1) == v0(=ret(pcimh_config_ptr_setget)), and falls through when t1(=-0x1) != v0(=ret(pcimh_config_ptr_setget)).
  The `beq` branch at 0x48c targets 0x4fc, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0x4a0 targets 0x4b0, is taken when a5(?) >= 0xfff (unsigned), and falls through when a5(?) < 0xfff (unsigned).
  The `bne` branch at 0x4f4 targets 0x6cc, is taken when t8(=[sym(showconfig)]) != 0, and falls through when t8(=[sym(showconfig)]) == 0.
  The `beq` branch at 0x564 targets 0x1e0 and is always taken.
  The `beq` branch at 0x588 targets 0x594, is taken when a2(?) >= 0xfff (unsigned), and falls through when a2(?) < 0xfff (unsigned).
  The `beq` branch at 0x5ac targets 0x3cc and is always taken.
  The `beq` branch at 0x5bc targets 0x288 and is always taken.
  The `beq` branch at 0x5cc targets 0x5e0, is taken when t8(?) == 0, and falls through when t8(?) != 0.
  The `beq` branch at 0x5e0 targets 0x5f8, is taken when t9(=[sym(showconfig)]) == 0, and falls through when t9(=[sym(showconfig)]) != 0.
  The `beq` branch at 0x5ec targets 0x6f8, is taken when ra(=[a0+524]) == 0, and falls through when ra(=[a0+524]) != 0.
  The `bne` branch at 0x628 targets 0x154, is taken when at(=[a0+524]) != 0, and falls through when at(=[a0+524]) == 0.
  The `beq` branch at 0x630 targets 0x154 and is always taken.
  The `beq` branch at 0x640 targets 0x660, is taken when a2(?) >= 0x16 (unsigned), and falls through when a2(?) < 0x16 (unsigned).
  The `beq` branch at 0x658 targets 0x664 and is always taken.
  The `beq` branch at 0x690 targets 0x3fc and is always taken.
  The `beq` branch at 0x6c4 targets 0x2e0 and is always taken.
  The `beq` branch at 0x6f0 targets 0x500 and is always taken.
  The `beq` branch at 0x704 targets 0x5f8 and is always taken.
  The `beq` branch at 0x71c targets 0x14c and is always taken.
  The `beq` branch at 0x724 targets 0x418 and is always taken.
  The return at 0x61c has v0 = one of ?, ret(cmn_err).

- `pcimh_scan_subbus` in `IP32/usr/cpu/sysgen/IP32boot/pcimh.o` at 0x72c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pcimh.o`.
  Range: 0x72c-0xbb8 (1164 bytes).
  It occupies 1164 bytes.
  The `lw` at 0x730 loads 4 bytes from a0 (arg0 at entry) +0x20c.
  The `sb` at 0x870 stores 1 byte to ret(kmem_zalloc) +0xc.
  3 such `sb` accesses store 1 byte to ret(kmem_zalloc) +0xd, including `sb` at 0x878, `sb` at 0x8d0, `sb` at 0xb68.
  The `sw` at 0x888 stores 4 bytes to ret(kmem_zalloc) +0x128.
  The `sw` at 0x88c stores 4 bytes to ret(kmem_zalloc) +0x14.
  The `sw` at 0x890 stores 4 bytes to ret(kmem_zalloc) +0x10.
  The `sb` at 0x898 stores 1 byte to ret(kmem_zalloc) +0xe.
  The `lw` at 0x89c loads 4 bytes from a0 (arg0 at entry) +0x18.
  The `sw` at 0x8a0 stores 4 bytes to ret(kmem_zalloc) +0x18.
  The `lw` at 0x8a4 loads 4 bytes from a0 (arg0 at entry) +0x20.
  The `sw` at 0x8a8 stores 4 bytes to ret(kmem_zalloc) +0x20.
  The `lw` at 0x8ac loads 4 bytes from a0 (arg0 at entry) +0x24.
  The `sw` at 0x8b0 stores 4 bytes to ret(kmem_zalloc) +0x208.
  The `sw` at 0x8b4 stores 4 bytes to ret(kmem_zalloc) +0x20c.
  The `sw` at 0x8b8 stores 4 bytes to ret(kmem_zalloc) +0x24.
  The `sw` at 0x8c8 stores 4 bytes to ret(kmem_zalloc) +0x4.
  The `lw` at 0xac4 loads 4 bytes from ret(kmem_zalloc) +0x4.
  The `jal` at 0x7fc calls pcimh_config_ptr_get with a0=?, a1=0x0, a2=0x2, a3=?.
  The `jal` at 0x81c calls pcimh_config_ptr_get with a0=?, a1=0x2, a2=0x2, a3=?.
  The `jal` at 0x830 calls pcimh_config_ptr_get with a0=?, a1=0xe, a2=0x1, a3=?.
  The `jal` at 0x858 calls kmem_zalloc with a0=0x210, a1=0x0, a2=?, a3=?.
  The `jal` at 0x8c0 calls pciio_device_info_register with a0=[sym(.sbss)], a1=ret(kmem_zalloc), a2=[a0+32], a3=[a0+24].
  The `jal` at 0x8e0 calls do_bist_for with a0=ret(kmem_zalloc), a1=?, a2=?, a3=?, a4=[sym(enable_pci_BIST)].
  The `jal` at 0x938 calls pcimh_config_ptr_set with a0=?, a1=0x4, a2=0x1, a3=0x87, a7=0x4.
  The `jal` at 0x94c calls pcimh_config_ptr_set with a0=?, a1=0xc, a2=0x1, a3=0x8.
  The `jal` at 0x960 calls pcimh_config_ptr_set with a0=?, a1=0xd, a2=0x1, a3=0x30.
  The `jal` at 0x974 calls pcimh_config_ptr_set with a0=?, a1=0x18, a2=0x1, a3=[a0+524].
  The `jal` at 0x988 calls pcimh_config_ptr_set with a0=?, a1=0x19, a2=0x1, a3=[sym(.sdata)+24].
  The `jal` at 0x99c calls pcimh_config_ptr_set with a0=?, a1=0x1a, a2=0x1, a3=0xff.
  The `jal` at 0x9b0 calls pcimh_config_ptr_set with a0=?, a1=0x1b, a2=0x1, a3=0x30.
  The `jal` at 0x9cc calls pcimh_config_ptr_set with a0=?, a1=0x20, a2=0x2, a3=?.
  The `jal` at 0x9e0 calls pcimh_config_ptr_set with a0=?, a1=0x22, a2=0x2, a3=0xfff0.
  The `jal` at 0x9fc calls pcimh_config_ptr_set with a0=?, a1=0x1c, a2=0x1, a3=?.
  The `jal` at 0xa10 calls pcimh_config_ptr_set with a0=?, a1=0x1d, a2=0x1, a3=0xf0.
  The `jal` at 0xa28 calls pcimh_config_ptr_set with a0=?, a1=0x30, a2=0x2, a3=?.
  The `jal` at 0xa3c calls pcimh_config_ptr_set with a0=?, a1=0x32, a2=0x2, a3=0xffff.
  The `jal` at 0xa50 calls pcimh_config_ptr_set with a0=?, a1=0x24, a2=0x2, a3=0xfff0.
  The `jal` at 0xa64 calls pcimh_config_ptr_set with a0=?, a1=0x26, a2=0x2, a3=0x0.
  The `jal` at 0xa78 calls pcimh_config_ptr_set with a0=?, a1=0x28, a2=0x4, a3=0x0.
  The `jal` at 0xa8c calls pcimh_config_ptr_set with a0=?, a1=0x2c, a2=0x0, a3=0x0.
  The `jal` at 0xa9c calls pcimh_config_ptr_get with a0=?, a1=0x4, a2=0x2, a3=?.
  The `jal` at 0xabc calls pcimh_config_ptr_set with a0=?, a1=0x4, a2=0x2, a3=?.
  The `jal` at 0xac8 calls pciio_device_attach with a0=[ret(kmem_zalloc)+4], a1=0x0, a2=?, a3=?.
  The `jal` at 0xad0 calls pcimh_scan_bus with a0=ret(kmem_zalloc), a1=?, a2=?, a3=?.
  The `jal` at 0xae4 calls pcimh_config_ptr_set with a0=?, a1=0x1a, a2=0x1, a3=[sym(.sdata)+24].
  The `jal` at 0xb04 calls pcimh_config_ptr_set with a0=?, a1=0x22, a2=0x2, a3=?.
  The `jal` at 0xb24 calls pcimh_config_ptr_set with a0=?, a1=0x1d, a2=0x1, a3=?.
  The `jal` at 0xb40 calls pcimh_config_ptr_set with a0=?, a1=0x32, a2=0x2, a3=?.
  The `beq` branch at 0x77c targets 0xba4, is taken when at(=[a0+524]) == 0, and falls through when at(=[a0+524]) != 0.
  The `beq` branch at 0x788 targets 0xb74, is taken when v0(?) >= 0x21 (signed), and falls through when v0(?) < 0x21 (signed).
  The `beq` branch at 0x790 targets 0x7c4 and is always taken.
  The `beq` branch at 0x7a8 targets 0xb6c, is taken when a3(=[a0+524]) == 0, and falls through when a3(=[a0+524]) != 0.
  The `bne` branch at 0x7bc targets 0xb74, is taken when v0(=one of 0x5, 0x20) < a5(?) (signed), and falls through when v0(=one of 0x5, 0x20) >= a5(?) (signed).
  The `beq` branch at 0x7d0 targets 0x7e8 and is always taken.
  The `beq` branch at 0x7d8 targets 0x798, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0x7e4 targets 0x798, is taken when s0(?) >= 0x8 (signed), and falls through when s0(?) < 0x8 (signed).
  The `beq` branch at 0x808 targets 0x7d8, is taken when a1(=(ret(pcimh_config_ptr_get) << 0x0)) == 0, and falls through when a1(=(ret(pcimh_config_ptr_get) << 0x0)) != 0.
  The `beq` branch at 0x810 targets 0x7d8, is taken when s3(=0xffff) == a1(=(ret(pcimh_config_ptr_get) << 0x0)), and falls through when s3(=0xffff) != a1(=(ret(pcimh_config_ptr_get) << 0x0)).
  The `beq` branch at 0x838 targets 0xb50, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `bne` branch at 0x844 targets 0x7dc, is taken when s7(=0x1) != t8(?), and falls through when s7(=0x1) == t8(?).
  The `blez` branch at 0x86c targets 0xb64, is taken when ra(=[a0+524]) <= 0 (signed), and falls through when ra(=[a0+524]) > 0 (signed).
  The `beq` branch at 0x8d8 targets 0x8ec, is taken when a4(=[sym(enable_pci_BIST)]) == 0, and falls through when a4(=[sym(enable_pci_BIST)]) != 0.
  The `beq` branch at 0x8f8 targets 0x90c, is taken when s2(=0xffffffff80000000) == v0(=[sym(.sdata)+12]), and falls through when s2(=0xffffffff80000000) != v0(=[sym(.sdata)+12]).
  The `beq` branch at 0x918 targets 0x92c, is taken when a7(=0x4) == v0(=[sym(.sdata)+8]), and falls through when a7(=0x4) != v0(=[sym(.sdata)+8]).
  The `beq` branch at 0xb48 targets 0x7e0 and is always taken.
  The `bne` branch at 0xb54 targets 0x844, is taken when (a1(=(ret(pcimh_config_ptr_get) << 0x0)) & 0x80) != 0, and falls through when (a1(=(ret(pcimh_config_ptr_get) << 0x0)) & 0x80) == 0.
  The `beq` branch at 0xb5c targets 0x840 and is always taken.
  The `beq` branch at 0xb64 targets 0x884 and is always taken.
  The `beq` branch at 0xb6c targets 0x7b8 and is always taken.
  The `bne` branch at 0xba8 targets 0x790, is taken when v0(?) < 0x6 (signed), and falls through when v0(?) >= 0x6 (signed).
  The `beq` branch at 0xbb0 targets 0xb78 and is always taken.
  The return at 0xb9c has v0 = ?.

- `do_bist_for` in `IP32/usr/cpu/sysgen/IP32boot/pcimh.o` at 0xbb8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pcimh.o`.
  Range: 0xbb8-0xd48 (400 bytes).
  It occupies 400 bytes.
  The `lw` at 0xbc4 loads 4 bytes from a0 (arg0 at entry) +0x128.
  4 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x4, including `lw` at 0xce0, `lw` at 0xcf8, `lw` at 0xd0c.
  The `jal` at 0xbd8 calls pcimh_config_ptr_get with a0=[a0+296], a1=0xf, a2=0x1, a3=a3 at entry (arg3).
  The `jal` at 0xc14 calls pcimh_config_ptr_set with a0=[a0+296], a1=0xf, a2=0x1, a3=0x40.
  The `jal` at 0xc24 calls drv_usecwait with a0=0x3e8, a1=?, a2=?, a3=?.
  The `jal` at 0xc34 calls pcimh_config_ptr_get with a0=[a0+296], a1=0xf, a2=0x1, a3=?.
  The `jal` at 0xcc4 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=?, a3=[sym(showconfig)].
  The `jal` at 0xce4 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=[a0+4], a3=0x40.
  The `jal` at 0xcfc calls cmn_err with a0=0x1, a1=sym(.rodata), a2=[a0+4], a3=?.
  The `jal` at 0xd10 calls cmn_err with a0=0x1, a1=sym(.rodata), a2=[a0+4], a3=?.
  The `jal` at 0xd20 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0xd38 calls cmn_err with a0=0x6, a1=sym(.rodata)+192, a2=[a0+4], a3=?.
  The `beq` branch at 0xbf4 targets 0xcb4, is taken when (v0(=ret(pcimh_config_ptr_get)) & 0x80) == 0, and falls through when (v0(=ret(pcimh_config_ptr_get)) & 0x80) != 0.
  The `bne` branch at 0xbfc targets 0xcd4, is taken when a0(=[sym(showconfig)]) != 0, and falls through when a0(=[sym(showconfig)]) == 0.
  The `beq` branch at 0xc44 targets 0xc70, is taken when (v0(=ret(pcimh_config_ptr_get)) & 0x40) == 0, and falls through when (v0(=ret(pcimh_config_ptr_get)) & 0x40) != 0.
  The `beq` branch at 0xc4c targets 0xc64, is taken when a3(=[sym(showconfig)]) == 0, and falls through when a3(=[sym(showconfig)]) != 0.
  The `beq` branch at 0xc5c targets 0xcc4, is taken when t9(?) == 0, and falls through when t9(?) != 0.
  The `bne` branch at 0xc6c targets 0xc24, is taken when s0(?) < 0xbb8 (signed), and falls through when s0(?) >= 0xbb8 (signed).
  The `beq` branch at 0xc78 targets 0xcf4, is taken when s0(?) == at(=0xbb8), and falls through when s0(?) != at(=0xbb8).
  The `bne` branch at 0xc80 targets 0xd0c, is taken when a3(?) != 0, and falls through when a3(?) == 0.
  The `bne` branch at 0xc88 targets 0xd20, is taken when a0(=[sym(showconfig)]) != 0, and falls through when a0(=[sym(showconfig)]) == 0.
  The `beq` branch at 0xcb4 targets 0xc94, is taken when a0(=[sym(showconfig)]) == 0, and falls through when a0(=[sym(showconfig)]) != 0.
  The `beq` branch at 0xcbc targets 0xd30 and is always taken.
  The `beq` branch at 0xccc targets 0xc68 and is always taken.
  The `beq` branch at 0xcec targets 0xc04 and is always taken.
  The `beq` branch at 0xd04 targets 0xc94 and is always taken.
  The `beq` branch at 0xd18 targets 0xc94 and is always taken.
  The `beq` branch at 0xd28 targets 0xc94 and is always taken.
  The `beq` branch at 0xd40 targets 0xc94 and is always taken.
  The return at 0xcac has v0 = one of ?, ret(pcimh_config_ptr_get), ret(cmn_err).

- `pcimh_piomap_alloc` in `IP32/usr/cpu/sysgen/IP32boot/pcimh.o` at 0xd48 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pcimh.o`.
  Range: 0xd48-0xdac (100 bytes).
  It occupies 100 bytes.
  The `sw` at 0xd80 stores 4 bytes to ret(kmem_zalloc) +0x14.
  The `sw` at 0xd94 stores 4 bytes to ret(kmem_zalloc) +0x0.
  The `sw` at 0xd98 stores 4 bytes to ret(kmem_zalloc) +0x10.
  The `sw` at 0xd9c stores 4 bytes to ret(kmem_zalloc) +0xc.
  The `sw` at 0xda0 stores 4 bytes to ret(kmem_zalloc) +0x4.
  The `jal` at 0xd6c calls kmem_zalloc with a0=0x1c, a1=?, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0xd74 targets 0xda4, is taken when v0(=ret(kmem_zalloc)) == 0, and falls through when v0(=ret(kmem_zalloc)) != 0.
  The return at 0xda4 has v0 = ret(kmem_zalloc).

- `pcimh_piomap_addr` in `IP32/usr/cpu/sysgen/IP32boot/pcimh.o` at 0xdc8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pcimh.o`.
  Range: 0xdc8-0xe04 (60 bytes).
  It occupies 60 bytes.
  The `lw` at 0xdcc loads 4 bytes from a0 (arg0 at entry) +0x4.
  The `lw` at 0xdd4 loads 4 bytes from a0 (arg0 at entry) +0xc.
  The `lw` at 0xddc loads 4 bytes from a0 (arg0 at entry) +0x10.
  The `lw` at 0xde8 loads 4 bytes from a0 (arg0 at entry) +0x0.
  The `jal` at 0xdf0 calls pcimh_piotrans_addr with a0=[a0+4], a1=0x0, a2=[a0+12], a3=([a0+16] + a1), a4=a2 at entry (arg2), a5=[a0], a6=a1 at entry (arg1).
  The return at 0xdfc has v0 = ret(pcimh_piotrans_addr).

- `pcimh_piotrans_addr` in `IP32/usr/cpu/sysgen/IP32boot/pcimh.o` at 0xe0c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pcimh.o`.
  Range: 0xe0c-0x11b0 (932 bytes).
  It occupies 932 bytes.
  2 such `sw` accesses store 4 bytes to ?, including `sw` at 0xea8, `sw` at 0x100c.
  The `lw` at 0xeec loads 4 bytes from (ret(device_info_get) + ((a2 + one of -0xe, -0x8) << 0x4)) +0x138.
  The `lw` at 0xf00 loads 4 bytes from ret(device_info_get) +0x1f8.
  The `lw` at 0xf14 loads 4 bytes from (ret(device_info_get) + ((a2 + one of -0xe, -0x8) << 0x4)) +0x130.
  The `lw` at 0xf1c loads 4 bytes from (ret(device_info_get) + ((a2 + one of -0xe, -0x8) << 0x4)) +0x134.
  The `lw` at 0xf20 loads 4 bytes from (ret(device_info_get) + ((a2 + one of -0xe, -0x8) << 0x4)) +0x12c.
  2 such `ll` accesses load 4 bytes from ?, including `ll` at 0xfc0, `ll` at 0xfd4.
  2 such `sc` accesses store 4 bytes to ?, including `sc` at 0xfc8, `sc` at 0xfdc.
  The `lw` at 0xff0 loads 4 bytes from ?.
  The `lw` at 0x104c loads 4 bytes from ret(device_info_get) +0x128.
  The `lw` at 0x1060 loads 4 bytes from ret(device_info_get) +0x1f0.
  The `lw` at 0x1064 loads 4 bytes from ret(device_info_get) +0x1ec.
  The `lw` at 0x1070 loads 4 bytes from ret(device_info_get) +0x1f4.
  The `jal` at 0xe2c calls device_info_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xf6c calls kvalloc with a0=?, a1=0x80011, a2=0x0, a3=?.
  The `beq` branch at 0xe40 targets 0x104c, is taken when s0(=a2) == at(=0x7), and falls through when s0(=a2) != at(=0x7).
  The `bne` branch at 0xe4c targets 0xe5c, is taken when s0(=a2) < 0x8 (signed), and falls through when s0(=a2) >= 0x8 (signed).
  The `bne` branch at 0xe58 targets 0xed8, is taken when s0(=a2) < 0xe (signed), and falls through when s0(=a2) >= 0xe (signed).
  The `bne` branch at 0xe60 targets 0xe78, is taken when a0(?) != 0, and falls through when a0(?) == 0.
  The `bne` branch at 0xe6c targets 0xed8, is taken when s0(=a2) < 0x1a (signed), and falls through when s0(=a2) >= 0x1a (signed).
  The `beq` branch at 0xe80 targets 0xf00, is taken when s0(?) == a2(=0x1), and falls through when s0(?) != a2(=0x1).
  The `beq` branch at 0xe88 targets 0xf2c, is taken when s0(?) == a3(=0x2), and falls through when s0(?) != a3(=0x2).
  The `beq` branch at 0xe94 targets 0x1018, is taken when s0(?) == a4(=0x4), and falls through when s0(?) != a4(=0x4).
  The `beq` branch at 0xe9c targets 0xeac, is taken when s2(?) == t0(=-0x1), and falls through when s2(?) != t0(=-0x1).
  The `beq` branch at 0xedc targets 0xe80, is taken when s2(=(a2 + one of -0xe, -0x8)) == t0(=-0x1), and falls through when s2(=(a2 + one of -0xe, -0x8)) != t0(=-0x1).
  The `beq` branch at 0xef0 targets 0xf14, is taken when a2(=[(ret(device_info_get) + ((a2 + one of -0xe, -0x8) << 0x4))+312]) == 0, and falls through when a2(=[(ret(device_info_get) + ((a2 + one of -0xe, -0x8) << 0x4))+312]) != 0.
  The `beq` branch at 0xef8 targets 0xeb4 and is always taken.
  The `beq` branch at 0xf04 targets 0x1060, is taken when a2(=[ret(device_info_get)+504]) == 0, and falls through when a2(=[ret(device_info_get)+504]) != 0.
  The `beq` branch at 0xf0c targets 0xeb4 and is always taken.
  The `beq` branch at 0xf24 targets 0xe7c and is always taken.
  The `beq` branch at 0xf2c targets 0x1090, is taken when a2(=[sym(peer_peer_dma)]) == 0, and falls through when a2(=[sym(peer_peer_dma)]) != 0.
  The `beq` branch at 0xf4c targets 0x1100, is taken when s0(?) == t8(=0x4), and falls through when s0(?) != t8(=0x4).
  The `beq` branch at 0xf54 targets 0x1058, is taken when s5(?) == 0, and falls through when s5(?) != 0.
  The `beq` branch at 0xf78 targets 0x1088, is taken when v0(=ret(kvalloc)) == 0, and falls through when v0(=ret(kvalloc)) != 0.
  The `beq` branch at 0xf94 targets 0xe9c, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beql` branch at 0xfcc targets 0xfc0, is taken when t9(?) == 0, and falls through when t9(?) != 0; its branch-likely delay slot `nop` at 0xfd0 runs only when taken and is annulled on fall-through.
  The `beql` branch at 0xfe0 targets 0xfd4, is taken when t3(?) == 0, and falls through when t3(?) != 0; its branch-likely delay slot `nop` at 0xfe4 runs only when taken and is annulled on fall-through.
  The `bne` branch at 0x1008 targets 0xfc0, is taken when a0(?) != 0, and falls through when a0(?) == 0.
  The `beq` branch at 0x1010 targets 0xe9c and is always taken.
  The `bne` branch at 0x1020 targets 0x1080, is taken when s1(?) < v0(=0xffffffff80000000) (unsigned), and falls through when s1(?) >= v0(=0xffffffff80000000) (unsigned).
  The `beq` branch at 0x1028 targets 0x1154, is taken when at(=[sym(peer_peer_dma)]) == 0, and falls through when at(=[sym(peer_peer_dma)]) != 0.
  The `beq` branch at 0x1044 targets 0xf54 and is always taken.
  The `beq` branch at 0x1050 targets 0xeb4 and is always taken.
  The `beq` branch at 0x1058 targets 0xe9c and is always taken.
  The `beq` branch at 0x106c targets 0x1198, is taken when s3(=[ret(device_info_get)+496]) == 0, and falls through when s3(=[ret(device_info_get)+496]) != 0.
  The `beq` branch at 0x1078 targets 0xe84 and is always taken.
  The `beq` branch at 0x1080 targets 0xeb4 and is always taken.
  The `beq` branch at 0x1088 targets 0xeb4 and is always taken.
  The `bne` branch at 0x1094 targets 0xf34, is taken when a0(=0x2000000) < s1(?) (unsigned), and falls through when a0(=0x2000000) >= s1(?) (unsigned).
  The `bne` branch at 0x109c targets 0xf34, is taken when a1(?) != 0, and falls through when a1(?) == 0.
  The `bne` branch at 0x10a8 targets 0xf38, is taken when a0(=0x2000000) < a4(?) (unsigned), and falls through when a0(=0x2000000) >= a4(?) (unsigned).
  The `bne` branch at 0x10c0 targets 0xe9c, is taken when s0(?) != a3(=0x4), and falls through when s0(?) == a3(=0x4).
  The `bne` branch at 0x10d0 targets 0x1080, is taken when s1(?) < v0(=0xffffffff80000000) (unsigned), and falls through when s1(?) >= v0(=0xffffffff80000000) (unsigned).
  The `bne` branch at 0x10dc targets 0x11a0, is taken when a0(=0x2000000) < a3(?) (unsigned), and falls through when a0(=0x2000000) >= a3(?) (unsigned).
  The `bne` branch at 0x10e8 targets 0x11a8, is taken when a0(=0x2000000) < a7(?) (unsigned), and falls through when a0(=0x2000000) >= a7(?) (unsigned).
  The `beq` branch at 0x10f8 targets 0xe9c and is always taken.
  The `bne` branch at 0x1108 targets 0x1080, is taken when s1(?) < v0(=0xffffffff80000000) (unsigned), and falls through when s1(?) >= v0(=0xffffffff80000000) (unsigned).
  The `bne` branch at 0x1110 targets 0x1030, is taken when a2(=[sym(peer_peer_dma)]) != 0, and falls through when a2(=[sym(peer_peer_dma)]) == 0.
  The `bne` branch at 0x1120 targets 0x1030, is taken when a0(=0x2000000) < a3(?) (unsigned), and falls through when a0(=0x2000000) >= a3(?) (unsigned).
  The `bne` branch at 0x1128 targets 0x1030, is taken when a5(?) != 0, and falls through when a5(?) == 0.
  The `bne` branch at 0x1138 targets 0x1030, is taken when a0(=0x2000000) < a6(?) (unsigned), and falls through when a0(=0x2000000) >= a6(?) (unsigned).
  The `beq` branch at 0x114c targets 0xf54 and is always taken.
  The `bne` branch at 0x115c targets 0x1034, is taken when a0(=0x2000000) < a3(?) (unsigned), and falls through when a0(=0x2000000) >= a3(?) (unsigned).
  The `bne` branch at 0x1168 targets 0x1034, is taken when a0(=0x2000000) < s3(?) (unsigned), and falls through when a0(=0x2000000) >= s3(?) (unsigned).
  The `bne` branch at 0x117c targets 0x1034, is taken when a0(=0x2000000) < t3(?) (unsigned), and falls through when a0(=0x2000000) >= t3(?) (unsigned).
  The `beq` branch at 0x1190 targets 0xe9c and is always taken.
  The `beq` branch at 0x1198 targets 0xeb4 and is always taken.
  The `beq` branch at 0x11a0 targets 0x1030 and is always taken.
  The `beq` branch at 0x11a8 targets 0x1030 and is always taken.
  The return at 0xed0 has v0 = one of ?, (a3 + [(ret(device_info_get) + ((a2 + one of -0xe, -0x8) << 0x4))+312]), ([ret(device_info_get)+296] + a3), 0x0.

- `pcimh_piospace_alloc` in `IP32/usr/cpu/sysgen/IP32boot/pcimh.o` at 0x11b0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pcimh.o`.
  Range: 0x11b0-0x137c (460 bytes).
  It occupies 460 bytes.
  The `lw` at 0x1220 loads 4 bytes from ret(device_info_get) +0x190.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0x123c, `lw` at 0x1254.
  3 such `sw` accesses store 4 bytes to ?, including `sw` at 0x12b8, `sw` at 0x12bc, `sw` at 0x12c4.
  The `jal` at 0x11d4 calls device_info_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1274 calls spl7 with a0=?, a1=?, a2=?, a3=0xc.
  The `jal` at 0x12a8 calls splx with a0=ret(spl7), a1=?, a2=?, a3=[sym(.sdata)+12], a7=0x2.
  The `jal` at 0x1320 calls cmn_err with a0=0x6, a1=sym(.rodata)+360, a2=a3 at entry (arg3), a3=0xc, a4=0x4.
  The `jal` at 0x1338 calls cmn_err with a0=0x6, a1=sym(.rodata)+408, a2=0x5, a3=0xc, a4=0x4.
  The `jal` at 0x1350 calls cmn_err with a0=0x6, a1=sym(.rodata)+496, a2=?, a3=0xc.
  The `jal` at 0x136c calls cmn_err with a0=0x6, a1=sym(.rodata)+456, a2=a2 at entry (arg2), a3=0xc, a4=0x4.
  The `beq` branch at 0x11f0 targets 0x1314, is taken when s3(=a3) == 0, and falls through when s3(=a3) != 0.
  The `bne` branch at 0x1200 targets 0x1330, is taken when at(=[sym(.sdata)+24]) != 0, and falls through when at(=[sym(.sdata)+24]) == 0.
  The `beq` branch at 0x1208 targets 0x12ec, is taken when s1(=a2) == a2(=0x5), and falls through when s1(=a2) != a2(=0x5).
  The `beq` branch at 0x1210 targets 0x1220, is taken when s1(=a2) == v0(=0x2), and falls through when s1(=a2) != v0(=0x2).
  The `bne` branch at 0x1218 targets 0x1360, is taken when s1(=a2) != a4(=0x4), and falls through when s1(=a2) == a4(=0x4).
  The `beq` branch at 0x1224 targets 0x1258, is taken when v1(?) == 0, and falls through when v1(?) != 0.
  The `beq` branch at 0x1234 targets 0x1258, is taken when s0(?) >= 0xc (signed), and falls through when s0(?) < 0xc (signed).
  The `beq` branch at 0x1240 targets 0x1258, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `bnel` branch at 0x1250 targets 0x1224, is taken when s0(?) < 0xc (signed), and falls through when s0(?) >= 0xc (signed); its branch-likely delay slot `lw v1,304(a0)` at 0x1254 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x1258 targets 0x1348, is taken when s0(?) == a3(=0xc), and falls through when s0(?) != a3(=0xc).
  The `beq` branch at 0x1268 targets 0x1274, is taken when s2(?) >= 0x1000 (unsigned), and falls through when s2(?) < 0x1000 (unsigned).
  The `beq` branch at 0x1288 targets 0x12f4, is taken when s1(?) == a7(=0x2), and falls through when s1(?) != a7(=0x2).
  The `beq` branch at 0x12ec targets 0x1220 and is always taken.
  The `beq` branch at 0x130c targets 0x12a8 and is always taken.
  The `beq` branch at 0x1328 targets 0x12c8 and is always taken.
  The `beq` branch at 0x1340 targets 0x12c8 and is always taken.
  The `beq` branch at 0x1358 targets 0x12c8 and is always taken.
  The `beq` branch at 0x1374 targets 0x12c8 and is always taken.
  The return at 0x12e4 has v0 = one of ?, -0x1.

- `pcimh_piospace_free` in `IP32/usr/cpu/sysgen/IP32boot/pcimh.o` at 0x137c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pcimh.o`.
  Range: 0x137c-0x1438 (188 bytes).
  It occupies 188 bytes.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0x13dc, `lw` at 0x13e8.
  4 such `sw` accesses store 4 bytes to ?, including `sw` at 0x13f4, `sw` at 0x13f8, `sw` at 0x13fc.
  The `sw` at 0x141c stores 4 bytes to (ret(device_info_get) + (a1 << 0x4)) +0x54.
  The `sw` at 0x1420 stores 4 bytes to (ret(device_info_get) + (a1 << 0x4)) +0x58.
  The `sw` at 0x1424 stores 4 bytes to (ret(device_info_get) + (a1 << 0x4)) +0x50.
  The `sw` at 0x142c stores 4 bytes to (ret(device_info_get) + (a1 << 0x4)) +0x4c.
  The `jal` at 0x1390 calls device_info_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `bne` branch at 0x13b0 targets 0x1414, is taken when at(=a1-20) < 0x6 (unsigned), and falls through when at(=a1-20) >= 0x6 (unsigned).
  The `beq` branch at 0x13b8 targets 0x1430, is taken when s0(=a1) == a1(=0x5), and falls through when s0(=a1) != a1(=0x5).
  The `bne` branch at 0x13c0 targets 0x1404, is taken when s0(=a1) != a2(=0x2), and falls through when s0(=a1) == a2(=0x2).
  The `beq` branch at 0x13c8 targets 0x13dc and is always taken.
  The `beq` branch at 0x13d0 targets 0x1404, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `bne` branch at 0x13e0 targets 0x13d0, is taken when v0(?) != s0(?), and falls through when v0(?) == s0(?).
  The `bne` branch at 0x13ec targets 0x13d0, is taken when v1(?) != s1(=a2), and falls through when v1(?) == s1(=a2).
  The `beq` branch at 0x1428 targets 0x1404 and is always taken.
  The `beq` branch at 0x1430 targets 0x13c8 and is always taken.
  The return at 0x140c has v0 = one of ret(device_info_get), ?.

- `pcimh_dmamap_alloc` in `IP32/usr/cpu/sysgen/IP32boot/pcimh.o` at 0x14c8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pcimh.o`.
  Range: 0x14c8-0x1538 (112 bytes).
  It occupies 112 bytes.
  The `sw` at 0x151c stores 4 bytes to ret(kmem_zalloc) +0x0.
  The `sb` at 0x1528 stores 1 byte to ret(kmem_zalloc) +0x8.
  The `sw` at 0x1534 stores 4 bytes to ret(kmem_zalloc) +0x4.
  The `jal` at 0x14dc calls pciio_info_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x14f4 calls kmem_zalloc with a0=0xc, a1=?, a2=?, a3=?.
  The `jal` at 0x1520 calls pciio_info_slot_get with a0=ret(pciio_info_get), a1=?, a2=?, a3=?.
  The `bne` branch at 0x14fc targets 0x151c, is taken when v0(=ret(kmem_zalloc)) != 0, and falls through when v0(=ret(kmem_zalloc)) == 0.
  The `beq` branch at 0x1530 targets 0x1504 and is always taken.
  The return at 0x1514 has v0 = ret(kmem_zalloc).

- `pcimh_dmamap_addr` in `IP32/usr/cpu/sysgen/IP32boot/pcimh.o` at 0x1554 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pcimh.o`.
  Range: 0x1554-0x157c (40 bytes).
  It occupies 40 bytes.
  The `lw` at 0x1560 loads 4 bytes from a0 (arg0 at entry) +0x4.
  The `lw` at 0x156c loads 4 bytes from a0 (arg0 at entry) +0x0.
  The `jal` at 0x1568 calls pcimh_endian_apply with a0=a1 at entry (arg1), a1=[a0+4], a2=[a0], a3=a3 at entry (arg3).
  The return at 0x1574 has v0 = ret(pcimh_endian_apply).

- `pcimh_dmamap_list` in `IP32/usr/cpu/sysgen/IP32boot/pcimh.o` at 0x157c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pcimh.o`.
  Range: 0x157c-0x16e4 (360 bytes).
  It occupies 360 bytes.
  The `lw` at 0x157c loads 4 bytes from a0 (arg0 at entry) +0x4.
  The `jal` at 0x15c0 calls alenlist_cursor_init with a0=a1 at entry (arg1), a1=0x0, a2=0x0, a3=?.
  The `jal` at 0x15dc calls alenlist_get with a0=a1 at entry (arg1), a1=0x0, a2=0x0, a3=sp-80, a4=sp-72.
  The `jal` at 0x161c calls pcimh_endian_apply with a0=?, a1=?, a2=a2 at entry (arg2), a3=?.
  The `jal` at 0x163c calls alenlist_replace with a0=?, a1=0x0, a2=sp-80, a3=sp-72.
  The `jal` at 0x1670 calls alenlist_append with a0=?, a1=ret(pcimh_endian_apply), a2=?, a3=?.
  The `jal` at 0x1690 calls alenlist_get with a0=a1 at entry (arg1), a1=0x0, a2=0x0, a3=sp-80, a4=sp-72.
  The `jal` at 0x16a8 calls alenlist_create with a0=?, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x16c4 calls alenlist_done with a0=a1 at entry (arg1), a1=?, a2=?, a3=?.
  The `jal` at 0x16d4 calls alenlist_destroy with a0=?, a1=?, a2=?, a3=?.
  The `beq` branch at 0x15b0 targets 0x16a8, is taken when (a2 & 0x4) == 0, and falls through when (a2 & 0x4) != 0.
  The `beq` branch at 0x15e4 targets 0x1614, is taken when v0(=ret(alenlist_get)) == 0, and falls through when v0(=ret(alenlist_get)) != 0.
  The `beq` branch at 0x15ec targets 0x16c4, is taken when s3(?) == 0, and falls through when s3(?) != 0.
  The `beq` branch at 0x1624 targets 0x1664, is taken when s3(?) == 0, and falls through when s3(?) != 0.
  The `beq` branch at 0x1644 targets 0x1680, is taken when v0(=ret(alenlist_replace)) == 0, and falls through when v0(=ret(alenlist_replace)) != 0.
  The `beq` branch at 0x164c targets 0x165c, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `beq` branch at 0x1654 targets 0x16d4, is taken when s3(?) == 0, and falls through when s3(?) != 0.
  The `beq` branch at 0x165c targets 0x15f4 and is always taken.
  The `bne` branch at 0x1678 targets 0x164c, is taken when v0(=ret(alenlist_append)) != 0, and falls through when v0(=ret(alenlist_append)) == 0.
  The `beq` branch at 0x1698 targets 0x1618, is taken when v0(=ret(alenlist_get)) == 0, and falls through when v0(=ret(alenlist_get)) != 0.
  The `beq` branch at 0x16a0 targets 0x15ec and is always taken.
  The `beq` branch at 0x16b4 targets 0x15b8, is taken when v0(=ret(alenlist_create)) >= 0x1 (unsigned), and falls through when v0(=ret(alenlist_create)) < 0x1 (unsigned).
  The `beq` branch at 0x16bc targets 0x164c and is always taken.
  The `beq` branch at 0x16cc targets 0x15f4 and is always taken.
  The `beq` branch at 0x16dc targets 0x165c and is always taken.
  The return at 0x160c has v0 = one of ?, 0x0.

- `pcimh_dmatrans_addr` in `IP32/usr/cpu/sysgen/IP32boot/pcimh.o` at 0x16ec (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pcimh.o`.
  Range: 0x16ec-0x1710 (36 bytes).
  It occupies 36 bytes.
  The `jal` at 0x16fc calls pcimh_endian_apply with a0=a2 at entry (arg2), a1=a0 at entry (arg0), a2=a4 at entry (arg4), a3=a3 at entry (arg3).
  The return at 0x1708 has v0 = ret(pcimh_endian_apply).

- `pcimh_dmatrans_list` in `IP32/usr/cpu/sysgen/IP32boot/pcimh.o` at 0x1710 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pcimh.o`.
  Range: 0x1710-0x1874 (356 bytes).
  It occupies 356 bytes.
  The `jal` at 0x1750 calls alenlist_cursor_init with a0=a2 at entry (arg2), a1=0x0, a2=0x0, a3=?.
  The `jal` at 0x176c calls alenlist_get with a0=a2 at entry (arg2), a1=0x0, a2=0x0, a3=sp-80, a4=sp-72.
  The `jal` at 0x17ac calls pcimh_endian_apply with a0=?, a1=a0 at entry (arg0), a2=a3 at entry (arg3), a3=?.
  The `jal` at 0x17cc calls alenlist_replace with a0=?, a1=0x0, a2=sp-80, a3=sp-72.
  The `jal` at 0x1800 calls alenlist_append with a0=?, a1=ret(pcimh_endian_apply), a2=?, a3=?.
  The `jal` at 0x1820 calls alenlist_get with a0=a2 at entry (arg2), a1=0x0, a2=0x0, a3=sp-80, a4=sp-72.
  The `jal` at 0x1838 calls alenlist_create with a0=?, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1854 calls alenlist_done with a0=a2 at entry (arg2), a1=?, a2=?, a3=?.
  The `jal` at 0x1864 calls alenlist_destroy with a0=?, a1=?, a2=?, a3=?.
  The `beq` branch at 0x173c targets 0x1838, is taken when (a3 & 0x4) == 0, and falls through when (a3 & 0x4) != 0.
  The `beq` branch at 0x1774 targets 0x17a4, is taken when v0(=ret(alenlist_get)) == 0, and falls through when v0(=ret(alenlist_get)) != 0.
  The `beq` branch at 0x177c targets 0x1854, is taken when s3(?) == 0, and falls through when s3(?) != 0.
  The `beq` branch at 0x17b4 targets 0x17f4, is taken when s3(?) == 0, and falls through when s3(?) != 0.
  The `beq` branch at 0x17d4 targets 0x1810, is taken when v0(=ret(alenlist_replace)) == 0, and falls through when v0(=ret(alenlist_replace)) != 0.
  The `beq` branch at 0x17dc targets 0x17ec, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `beq` branch at 0x17e4 targets 0x1864, is taken when s3(?) == 0, and falls through when s3(?) != 0.
  The `beq` branch at 0x17ec targets 0x1784 and is always taken.
  The `bne` branch at 0x1808 targets 0x17dc, is taken when v0(=ret(alenlist_append)) != 0, and falls through when v0(=ret(alenlist_append)) == 0.
  The `beq` branch at 0x1828 targets 0x17a8, is taken when v0(=ret(alenlist_get)) == 0, and falls through when v0(=ret(alenlist_get)) != 0.
  The `beq` branch at 0x1830 targets 0x177c and is always taken.
  The `beq` branch at 0x1844 targets 0x1748, is taken when v0(=ret(alenlist_create)) >= 0x1 (unsigned), and falls through when v0(=ret(alenlist_create)) < 0x1 (unsigned).
  The `beq` branch at 0x184c targets 0x17dc and is always taken.
  The `beq` branch at 0x185c targets 0x1784 and is always taken.
  The `beq` branch at 0x186c targets 0x17ec and is always taken.
  The return at 0x179c has v0 = one of ?, 0x0.

- `pcimh_flush_buffers` in `IP32/usr/cpu/sysgen/IP32boot/pcimh.o` at 0x188c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pcimh.o`.
  Range: 0x188c-0x18c4 (56 bytes).
  It occupies 56 bytes.
  The `jal` at 0x18ac calls pciio_pio_write32 with a0=0x1, a1=0xffffffffbf08000c, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `bne` branch at 0x1898 targets 0x18a4, is taken when at(=[sym(ip32_pci_enable_prefetch)]) != 0, and falls through when at(=[sym(ip32_pci_enable_prefetch)]) == 0.
  The `beq` branch at 0x18a0 targets 0x18b4, is taken when a1(=[sym(ip32_pci_flush_prefetch)]) == 0, and falls through when a1(=[sym(ip32_pci_flush_prefetch)]) != 0.
  The return at 0x18bc has v0 = 0x0.

- `pcimh_endian_apply` in `IP32/usr/cpu/sysgen/IP32boot/pcimh.o` at 0x18c4 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pcimh.o`.
  Range: 0x18c4-0x194c (136 bytes).
  It occupies 136 bytes.
  The `lw` at 0x18e4 loads 4 bytes from ret(device_info_get) +0x200.
  The `jal` at 0x18dc calls device_info_get with a0=a1 at entry (arg1), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0x18fc targets 0x1938, is taken when a4(=[ret(device_info_get)+512]) == 0, and falls through when a4(=[ret(device_info_get)+512]) != 0.
  The `beq` branch at 0x1904 targets 0x1940, is taken when a4(=[ret(device_info_get)+512]) == a3(=0x1), and falls through when a4(=[ret(device_info_get)+512]) != a3(=0x1).
  The `beq` branch at 0x190c targets 0x191c, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0x191c targets 0x1928, is taken when at(?) == 0, and falls through when at(?) != 0.
  The `beq` branch at 0x1938 targets 0x1904 and is always taken.
  The `beq` branch at 0x1944 targets 0x190c and is always taken.
  The return at 0x1930 has v0 = ?.

- `pcimh_intr_alloc` in `IP32/usr/cpu/sysgen/IP32boot/pcimh.o` at 0x194c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pcimh.o`.
  Range: 0x194c-0x19f0 (164 bytes).
  It occupies 164 bytes.
  The `sw` at 0x19b4 stores 4 bytes to ret(kmem_zalloc) +0x4.
  The `sw` at 0x19b8 stores 4 bytes to ret(kmem_zalloc) +0x8.
  The `sw` at 0x19bc stores 4 bytes to ret(kmem_zalloc) +0xc.
  The `sw` at 0x19c0 stores 4 bytes to ret(kmem_zalloc) +0x0.
  The `sw` at 0x19c4 stores 4 bytes to ret(kmem_zalloc) +0x30.
  The `sw` at 0x19c8 stores 4 bytes to ret(kmem_zalloc) +0x34.
  The `jal` at 0x1968 calls device_info_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1978 calls mace_ivecs with a0=ret(device_info_get), a1=a2 at entry (arg2), a2=?, a3=?.
  The `jal` at 0x1988 calls mace_level with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0x199c calls kmem_zalloc with a0=0x38, a1=0x0, a2=?, a3=?.
  The `beq` branch at 0x1990 targets 0x19e8, is taken when s3(=ret(mace_ivecs)) == 0, and falls through when s3(=ret(mace_ivecs)) != 0.
  The `bne` branch at 0x19a4 targets 0x19b4, is taken when v0(=ret(kmem_zalloc)) != 0, and falls through when v0(=ret(kmem_zalloc)) == 0.
  The `beq` branch at 0x19ac targets 0x19cc and is always taken.
  The `beq` branch at 0x19e8 targets 0x19cc and is always taken.
  The return at 0x19e0 has v0 = one of 0x0, ret(kmem_zalloc).

- `pcimh_intr_connect` in `IP32/usr/cpu/sysgen/IP32boot/pcimh.o` at 0x1a0c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pcimh.o`.
  Range: 0x1a0c-0x1b1c (272 bytes).
  It occupies 272 bytes.
  The `sw` at 0x1a0c stores 4 bytes to a0 (arg0 at entry) +0x10.
  The `sw` at 0x1a10 stores 4 bytes to a0 (arg0 at entry) +0x14.
  The `lw` at 0x1a18 loads 4 bytes from a0 (arg0 at entry) +0x4.
  The `lw` at 0x1a24 loads 4 bytes from a0 (arg0 at entry) +0x30.
  The `lw` at 0x1a2c loads 4 bytes from a0 (arg0 at entry) +0x34.
  The `jal` at 0x1a74 calls setcrimevector with a0=?, a1=[a0+52], a2=a1 at entry (arg1), a3=a2 at entry (arg2), a4=0x0.
  The `jal` at 0x1b0c calls cmn_err with a0=0x1, a1=sym(.rodata), a2=[a0+4], a3=?, a4=[a0+52].
  The `beq` branch at 0x1a60 targets 0x1a94 and is always taken.
  The `bne` branch at 0x1a7c targets 0x1af8, is taken when v0(=ret(setcrimevector)) != 0, and falls through when v0(=ret(setcrimevector)) == 0.
  The `beq` branch at 0x1a90 targets 0x1ab4, is taken when s0(?) >= 0x10 (signed), and falls through when s0(?) < 0x10 (signed).
  The `bne` branch at 0x1a9c targets 0x1a68, is taken when (s1(=[a0+48]) & v1(?)) != 0, and falls through when (s1(=[a0+48]) & v1(?)) == 0.
  The `bne` branch at 0x1aac targets 0x1a98, is taken when s0(?) < 0x10 (signed), and falls through when s0(?) >= 0x10 (signed).
  The `beq` branch at 0x1acc targets 0x1ad8, is taken when s2(=one of 0x0, 0x1) == 0, and falls through when s2(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x1ad4 targets 0x1aec, is taken when s7(=one of 0x0, 0x1) == 0, and falls through when s7(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x1af0 targets 0x1ae0 and is always taken.
  The `beq` branch at 0x1b14 targets 0x1a88 and is always taken.
  The return at 0x1ae4 has v0 = one of -0x1, 0x0.

- `pcimh_intr_disconnect` in `IP32/usr/cpu/sysgen/IP32boot/pcimh.o` at 0x1b1c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pcimh.o`.
  Range: 0x1b1c-0x1bd0 (180 bytes).
  It occupies 180 bytes.
  The `lw` at 0x1b1c loads 4 bytes from a0 (arg0 at entry) +0x4.
  The `lw` at 0x1b4c loads 4 bytes from a0 (arg0 at entry) +0x30.
  The `lw` at 0x1b54 loads 4 bytes from a0 (arg0 at entry) +0x10.
  The `sw` at 0x1b94 stores 4 bytes to a0 (arg0 at entry) +0x10.
  The `sw` at 0x1b9c stores 4 bytes to a0 (arg0 at entry) +0x14.
  The `jal` at 0x1b50 calls unsetcrimevector with a0=?, a1=[a0+16], a2=?, a3=?.
  The `jal` at 0x1bc0 calls cmn_err with a0=0x1, a1=sym(.rodata), a2=[a0+4], a3=?.
  The `beq` branch at 0x1b48 targets 0x1b6c and is always taken.
  The `beq` branch at 0x1b58 targets 0x1bb0, is taken when v0(=ret(unsetcrimevector)) == 0, and falls through when v0(=ret(unsetcrimevector)) != 0.
  The `beq` branch at 0x1b68 targets 0x1b8c, is taken when s0(?) >= 0x10 (signed), and falls through when s0(?) < 0x10 (signed).
  The `bne` branch at 0x1b74 targets 0x1b50, is taken when (s1(=[a0+48]) & v1(?)) != 0, and falls through when (s1(=[a0+48]) & v1(?)) == 0.
  The `bne` branch at 0x1b84 targets 0x1b70, is taken when s0(?) < 0x10 (signed), and falls through when s0(?) >= 0x10 (signed).
  The `beq` branch at 0x1bc8 targets 0x1b64 and is always taken.
  The return at 0x1ba8 has v0 = ?.

- `mace_ivecs` in `IP32/usr/cpu/sysgen/IP32boot/pcimh.o` at 0x1bd8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pcimh.o`.
  Range: 0x1bd8-0x1c90 (184 bytes).
  It occupies 184 bytes.
  The `lw` at 0x1bd8 loads 4 bytes from a0 (arg0 at entry) +0x208.
  The `lbu` at 0x1be4 loads 1 byte from a0 (arg0 at entry) +0xd.
  The `lbu` at 0x1be8 loads 1 byte from a0 (arg0 at entry) +0xc.
  The `lbu` at 0x1c60 loads 1 byte from ?.
  The `jal` at 0x1c14 calls mace_ivecs with a0=[a0+520], a1=?, a2=?, a3=a3 at entry (arg3), a5=[a0+13]:1, a7=0x4.
  The `beq` branch at 0x1be0 targets 0x1c28, is taken when v0(=[a0+520]) == 0, and falls through when v0(=[a0+520]) != 0.
  The `beq` branch at 0x1bf8 targets 0x1c28, is taken when at(=[a0+12]:1) == 0, and falls through when at(=[a0+12]:1) != 0.
  The `beq` branch at 0x1c00 targets 0x1c14, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0x1c20 targets 0x1c84 and is always taken.
  The `beq` branch at 0x1c58 targets 0x1c6c, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `bne` branch at 0x1c78 targets 0x1c58, is taken when a5(?) != 0, and falls through when a5(?) == 0.
  The return at 0x1c88 has v0 = one of ret(mace_ivecs), ?.

- `mace_level` in `IP32/usr/cpu/sysgen/IP32boot/pcimh.o` at 0x1c90 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pcimh.o`.
  Range: 0x1c90-0x1d70 (224 bytes).
  It occupies 224 bytes.
  The `jal` at 0x1c9c calls device_desc_default_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1cc0 calls device_desc_intr_swlevel_get with a0=?, a1=?, a2=?, a3=?.
  The `bne` branch at 0x1c94 targets 0x1cc0, is taken when a1 != 0, and falls through when a1 == 0.
  The `bne` branch at 0x1ca8 targets 0x1cc0, is taken when v0(=ret(device_desc_default_get)) != 0, and falls through when v0(=ret(device_desc_default_get)) == 0.
  The `beq` branch at 0x1cdc targets 0x1d68, is taken when v0(=ret(device_desc_intr_swlevel_get)) == 0, and falls through when v0(=ret(device_desc_intr_swlevel_get)) != 0.
  The `beq` branch at 0x1ce8 targets 0x1d38, is taken when v0(=ret(device_desc_intr_swlevel_get)) == at(=sym(spl0)), and falls through when v0(=ret(device_desc_intr_swlevel_get)) != at(=sym(spl0)).
  The `beq` branch at 0x1cf4 targets 0x1d48, is taken when v0(=ret(device_desc_intr_swlevel_get)) == v1(=sym(spl1)), and falls through when v0(=ret(device_desc_intr_swlevel_get)) != v1(=sym(spl1)).
  The `beq` branch at 0x1d00 targets 0x1d50, is taken when v0(=ret(device_desc_intr_swlevel_get)) == a1(=sym(spl3)), and falls through when v0(=ret(device_desc_intr_swlevel_get)) != a1(=sym(spl3)).
  The `beq` branch at 0x1d0c targets 0x1d58, is taken when v0(=ret(device_desc_intr_swlevel_get)) == a2(=sym(spl5)), and falls through when v0(=ret(device_desc_intr_swlevel_get)) != a2(=sym(spl5)).
  The `beq` branch at 0x1d1c targets 0x1d60, is taken when v0(=ret(device_desc_intr_swlevel_get)) == a3(=sym(spl6)), and falls through when v0(=ret(device_desc_intr_swlevel_get)) != a3(=sym(spl6)).
  The `bne` branch at 0x1d24 targets 0x1d40, is taken when v0(=ret(device_desc_intr_swlevel_get)) != a0(=sym(spl7)), and falls through when v0(=ret(device_desc_intr_swlevel_get)) == a0(=sym(spl7)).
  The `beq` branch at 0x1d30 targets 0x1cb4 and is always taken.
  The `beq` branch at 0x1d38 targets 0x1cb0 and is always taken.
  The `beq` branch at 0x1d40 targets 0x1cb4 and is always taken.
  The `beq` branch at 0x1d48 targets 0x1cb4 and is always taken.
  The `beq` branch at 0x1d50 targets 0x1cb4 and is always taken.
  The `beq` branch at 0x1d58 targets 0x1cb4 and is always taken.
  The `beq` branch at 0x1d60 targets 0x1cb4 and is always taken.
  The `beq` branch at 0x1d68 targets 0x1cb4 and is always taken.
  The return at 0x1cb8 has v0 = one of 0x0, 0x1, 0x3.

- `pcimh_endian_set` in `IP32/usr/cpu/sysgen/IP32boot/pcimh.o` at 0x1da4 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pcimh.o`.
  Range: 0x1da4-0x1dd0 (44 bytes).
  It occupies 44 bytes.
  The `sw` at 0x1dbc stores 4 bytes to ret(device_info_get) +0x200.
  The `jal` at 0x1db0 calls device_info_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x1dc8 has v0 = a2.

- `pcimh_config_get` in `IP32/usr/cpu/sysgen/IP32boot/pcimh.o` at 0x1dd8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pcimh.o`.
  Range: 0x1dd8-0x1e10 (56 bytes).
  It occupies 56 bytes.
  The `lw` at 0x1df0 loads 4 bytes from ret(device_info_get) +0x128.
  The `jal` at 0x1de8 calls device_info_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1df8 calls pcimh_config_ptr_get with a0=[ret(device_info_get)+296], a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=?.
  The return at 0x1e08 has v0 = ret(pcimh_config_ptr_get).

- `pcimh_config_ptr_get` in `IP32/usr/cpu/sysgen/IP32boot/pcimh.o` at 0x1e2c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pcimh.o`.
  Range: 0x1e2c-0x1edc (176 bytes).
  It occupies 176 bytes.
  The `jal` at 0x1e4c calls spl7 with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1e64 calls pciio_pio_write32 with a0=?, a1=0xffffffffbf080cf8, a2=?, a3=?.
  The `jal` at 0x1e70 calls pciio_pio_read32 with a0=0xffffffffbf080cfc, a1=?, a2=?, a3=?.
  The `jal` at 0x1e80 calls splx with a0=ret(spl7), a1=?, a2=?, a3=?.
  The `beq` branch at 0x1ea4 targets 0x1eb4, is taken when (s1(=a1) & 0x3) == 0, and falls through when (s1(=a1) & 0x3) != 0.
  The `beq` branch at 0x1eb8 targets 0x1ec4, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The return at 0x1ed4 has v0 = ?.

- `pcimh_config_set` in `IP32/usr/cpu/sysgen/IP32boot/pcimh.o` at 0x1edc (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pcimh.o`.
  Range: 0x1edc-0x1f1c (64 bytes).
  It occupies 64 bytes.
  The `lw` at 0x1ef8 loads 4 bytes from ret(device_info_get) +0x128.
  The `jal` at 0x1ef0 calls device_info_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1f04 calls pcimh_config_ptr_set with a0=[ret(device_info_get)+296], a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x1f14 has v0 = ret(pcimh_config_ptr_set).

- `pcimh_config_ptr_set` in `IP32/usr/cpu/sysgen/IP32boot/pcimh.o` at 0x1f1c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pcimh.o`.
  Range: 0x1f1c-0x2028 (268 bytes).
  It occupies 268 bytes.
  The `jal` at 0x1f88 calls spl7 with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1f98 calls pciio_pio_write32 with a0=?, a1=0xffffffffbf080cf8, a2=?, a3=?.
  The `jal` at 0x1fa0 calls pciio_pio_read32 with a0=0xffffffffbf080cfc, a1=?, a2=?, a3=?.
  The `jal` at 0x1fd4 calls spl7 with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1fe4 calls pciio_pio_write32 with a0=?, a1=0xffffffffbf080cf8, a2=?, a3=?.
  The `jal` at 0x1ff8 calls pciio_pio_write32 with a0=?, a1=0xffffffffbf080cfc, a2=?, a3=?.
  The `jal` at 0x2008 calls splx with a0=ret(spl7), a1=?, a2=?, a3=?.
  The `beq` branch at 0x1f54 targets 0x1fd4, is taken when a2 >= 0x4 (unsigned), and falls through when a2 < 0x4 (unsigned).
  The `beq` branch at 0x1fc0 targets 0x2020, is taken when at(?) == v1(=0x4), and falls through when at(?) != v1(=0x4).
  The `beq` branch at 0x1fcc targets 0x1fe0 and is always taken.
  The `beq` branch at 0x2020 targets 0x1fc8 and is always taken.
  The return at 0x2018 has v0 = ret(splx).

- `pcimh_config_ptr_setget` in `IP32/usr/cpu/sysgen/IP32boot/pcimh.o` at 0x2028 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pcimh.o`.
  Range: 0x2028-0x2070 (72 bytes).
  It occupies 72 bytes.
  The `jal` at 0x2044 calls pcimh_config_ptr_set with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=?.
  The `jal` at 0x2054 calls pcimh_config_ptr_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=?.
  The return at 0x2068 has v0 = (ret(pcimh_config_ptr_get) << 0x0).

- `pciio_pio_read8` in `IP32/usr/cpu/sysgen/IP32boot/pcimh.o` at 0x2080 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pcimh.o`.
  Range: 0x2080-0x20d0 (80 bytes).
  It occupies 80 bytes.
  The `lbu` at 0x20a4 loads 1 byte from a0 (arg0 at entry) +0x0.
  The `jal` at 0x208c calls spl7 with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x2098 calls us_delay with a0=[sym(ip32_pio_predelay)], a1=?, a2=?, a3=?.
  The `jal` at 0x20a8 calls us_delay with a0=[sym(ip32_pio_postdelay)], a1=?, a2=?, a3=?.
  The `jal` at 0x20b4 calls splx with a0=ret(spl7), a1=?, a2=?, a3=?.
  The return at 0x20c8 has v0 = [a0]:1.

- `pciio_pio_read16` in `IP32/usr/cpu/sysgen/IP32boot/pcimh.o` at 0x20d0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pcimh.o`.
  Range: 0x20d0-0x2120 (80 bytes).
  It occupies 80 bytes.
  The `lhu` at 0x20f4 loads 2 bytes from a0 (arg0 at entry) +0x0.
  The `jal` at 0x20dc calls spl7 with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x20e8 calls us_delay with a0=[sym(ip32_pio_predelay)], a1=?, a2=?, a3=?.
  The `jal` at 0x20f8 calls us_delay with a0=[sym(ip32_pio_postdelay)], a1=?, a2=?, a3=?.
  The `jal` at 0x2104 calls splx with a0=ret(spl7), a1=?, a2=?, a3=?.
  The return at 0x2118 has v0 = [a0]:2.

- `pciio_pio_read32` in `IP32/usr/cpu/sysgen/IP32boot/pcimh.o` at 0x2120 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pcimh.o`.
  Range: 0x2120-0x2170 (80 bytes).
  It occupies 80 bytes.
  The `lw` at 0x2144 loads 4 bytes from a0 (arg0 at entry) +0x0.
  The `jal` at 0x212c calls spl7 with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x2138 calls us_delay with a0=[sym(ip32_pio_predelay)], a1=?, a2=?, a3=?.
  The `jal` at 0x2148 calls us_delay with a0=[sym(ip32_pio_postdelay)], a1=?, a2=?, a3=?.
  The `jal` at 0x2154 calls splx with a0=ret(spl7), a1=?, a2=?, a3=?.
  The return at 0x2168 has v0 = [a0].

- `pciio_pio_read64` in `IP32/usr/cpu/sysgen/IP32boot/pcimh.o` at 0x2170 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pcimh.o`.
  Range: 0x2170-0x21c0 (80 bytes).
  It occupies 80 bytes.
  The `ld` at 0x2194 loads 8 bytes from a0 (arg0 at entry) +0x0.
  The `jal` at 0x217c calls spl7 with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x2188 calls us_delay with a0=[sym(ip32_pio_predelay)], a1=?, a2=?, a3=?.
  The `jal` at 0x2198 calls us_delay with a0=[sym(ip32_pio_postdelay)], a1=?, a2=?, a3=?.
  The `jal` at 0x21a4 calls splx with a0=ret(spl7), a1=?, a2=?, a3=?.
  The return at 0x21b8 has v0 = [a0]:8.

- `pciio_pio_write8` in `IP32/usr/cpu/sysgen/IP32boot/pcimh.o` at 0x21c0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pcimh.o`.
  Range: 0x21c0-0x21c8 (8 bytes).
  It occupies 8 bytes.
  The `sb` at 0x21c4 stores 1 byte to a1 (arg1 at entry) +0x0.
  The return at 0x21c0 has v0 = ?.

- `pciio_pio_write16` in `IP32/usr/cpu/sysgen/IP32boot/pcimh.o` at 0x21c8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pcimh.o`.
  Range: 0x21c8-0x21d0 (8 bytes).
  It occupies 8 bytes.
  The `sh` at 0x21cc stores 2 bytes to a1 (arg1 at entry) +0x0.
  The return at 0x21c8 has v0 = ?.

- `pciio_pio_write32` in `IP32/usr/cpu/sysgen/IP32boot/pcimh.o` at 0x21d0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pcimh.o`.
  Range: 0x21d0-0x21d8 (8 bytes).
  It occupies 8 bytes.
  The `sw` at 0x21d4 stores 4 bytes to a1 (arg1 at entry) +0x0.
  The return at 0x21d0 has v0 = ?.

- `pciio_pio_write64` in `IP32/usr/cpu/sysgen/IP32boot/pcimh.o` at 0x21d8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pcimh.o`.
  Range: 0x21d8-0x21e0 (8 bytes).
  It occupies 8 bytes.
  The `sd` at 0x21dc stores 8 bytes to a1 (arg1 at entry) +0x0.
  The return at 0x21d8 has v0 = ?.

- `mace_pci_error` in `IP32/usr/cpu/sysgen/IP32boot/pcimh.o` at 0x21e0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pcimh.o`.
  Range: 0x21e0-0x261c (1084 bytes).
  It occupies 1084 bytes.
  11 such `lw` accesses load 4 bytes from ?, including `lw` at 0x22ac, `lw` at 0x22e8, `lw` at 0x2374.
  4 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x22b8, `lbu` at 0x22c4, `lbu` at 0x22d0.
  The `ld` at 0x2350 loads 8 bytes from a0 (arg0 at entry) +0x120.
  The `ld` at 0x23f0 loads 8 bytes from a0 (arg0 at entry) +0xf8.
  3 such `lw` accesses load 4 bytes from sym(.data) +0x34, including `lw` at 0x244c, `lw` at 0x248c, `lw` at 0x2528.
  The `jal` at 0x21f4 calls pciio_pio_read32 with a0=0xffffffffbf080004, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x2204 calls pciio_pio_read32 with a0=0xffffffffbf080000, a1=?, a2=?, a3=?.
  The `jal` at 0x2218 calls pciio_pio_write32 with a0=0x0, a1=0xffffffffbf080004, a2=?, a3=?.
  The `jal` at 0x2408 calls pciio_error_handler with a0=[sym(.sbss)], a1=0x0, a2=one of 0x1, 0x2, a3=sp-112, a4=0x1.
  The `jal` at 0x2468 calls cmn_err with a0=0x1, a1=sym(.rodata)+744, a2=ret(pciio_pio_read32), a3=sym(.data), a4=sym(.rodata)+1228, a5=ret(pciio_pio_read32).
  The `jal` at 0x24a8 calls cmn_err with a0=0x1, a1=sym(.rodata)+912, a2=ret(pciio_pio_read32), a3=sym(.data), a4=sym(.rodata)+1228, a5=ret(pciio_pio_read32).
  The `jal` at 0x24cc calls cmn_err with a0=0x1, a1=sym(.rodata)+832, a2=ret(pciio_pio_read32), a3=sym(.data), a4=sym(.rodata)+1228, a5=ret(pciio_pio_read32).
  The `jal` at 0x24f4 calls cmn_err with a0=0x1, a1=sym(.rodata)+992, a2=ret(pciio_pio_read32), a3=sym(.data), a4=sym(.rodata)+1228, a5=ret(pciio_pio_read32).
  The `jal` at 0x252c calls cmn_err with a0=0x1, a1=sym(.rodata)+688, a2=ret(pciio_pio_read32), a3=sym(.data), a4=sym(.rodata)+1228, a5=ret(pciio_pio_read32).
  The `jal` at 0x2580 calls cmn_err with a0=0x1, a1=sym(.rodata)+1128, a2=ret(pciio_pio_read32), a3=sym(.data), a5=ret(pciio_pio_read32).
  The `jal` at 0x259c calls cmn_err with a0=0x1, a1=sym(.rodata)+648, a2=ret(pciio_pio_read32), a3=?, a5=(ret(pciio_pio_read32) << 0x2b).
  The `jal` at 0x25fc calls cmn_err with a0=0x1, a1=sym(.rodata)+1064, a2=ret(pciio_pio_read32), a3=sym(.data), a5=ret(pciio_pio_read32), a7=sym(.rodata)+1192.
  The `beq` branch at 0x2230 targets 0x22f4, is taken when a2(=0xffffffff80180000) == a3(?), and falls through when a2(=0xffffffff80180000) != a3(?).
  The `beq` branch at 0x2240 targets 0x2308, is taken when (s3(=ret(pciio_pio_read32)) & a4(=0xf0000)) == 0, and falls through when (s3(=ret(pciio_pio_read32)) & a4(=0xf0000)) != 0.
  The `bgez` branch at 0x2248 targets 0x2330, is taken when a5(=(ret(pciio_pio_read32) << 0x2b)) >= 0 (signed), and falls through when a5(=(ret(pciio_pio_read32) << 0x2b)) < 0 (signed).
  The `bne` branch at 0x226c targets 0x2294, is taken when (a1(=-0x800) & a6(?)) != 0, and falls through when (a1(=-0x800) & a6(?)) == 0.
  The `bne` branch at 0x2284 targets 0x2268, is taken when a7(?) < 0x6 (signed), and falls through when a7(?) >= 0x6 (signed).
  The `beq` branch at 0x228c targets 0x2478 and is always taken.
  The `beq` branch at 0x2294 targets 0x2434, is taken when t1(=[sym(.sdata)+16]) == 0, and falls through when t1(=[sym(.sdata)+16]) != 0.
  The `beq` branch at 0x22a4 targets 0x22b8 and is always taken.
  The `beq` branch at 0x22b0 targets 0x243c, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `bne` branch at 0x22bc targets 0x22ac, is taken when t3(?) != 0, and falls through when t3(?) == 0.
  The `bne` branch at 0x22c8 targets 0x22ac, is taken when a7(?) != t8(?), and falls through when a7(?) == t8(?).
  The `beq` branch at 0x22d4 targets 0x2508, is taken when a1(?) == t2(?), and falls through when a1(?) != t2(?).
  The `bne` branch at 0x22dc targets 0x22ac, is taken when a2(=0xff) != a1(?), and falls through when a2(=0xff) == a1(?).
  The `bnel` branch at 0x22e4 targets 0x22b0, is taken when t2(?) != 0, and falls through when t2(?) == 0; its branch-likely delay slot `lw v0,516(v0)` at 0x22e8 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x22ec targets 0x2508 and is always taken.
  The `bne` branch at 0x22f8 targets 0x223c, is taken when t9(=[sym(pcimh_verbose)]) != 0, and falls through when t9(=[sym(pcimh_verbose)]) == 0.
  The `beq` branch at 0x2300 targets 0x2314 and is always taken.
  The `bne` branch at 0x230c targets 0x2590, is taken when ra(=[sym(pcimh_verbose)]) != 0, and falls through when ra(=[sym(pcimh_verbose)]) == 0.
  The `bgez` branch at 0x2330 targets 0x2424, is taken when at(=(ret(pciio_pio_read32) << 0x2a)) >= 0 (signed), and falls through when at(=(ret(pciio_pio_read32) << 0x2a)) < 0 (signed).
  The `beq` branch at 0x2364 targets 0x253c, is taken when v1(=[sym(.sdata)+16]) == 0, and falls through when v1(=[sym(.sdata)+16]) != 0.
  The `beq` branch at 0x236c targets 0x237c and is always taken.
  The `beq` branch at 0x2378 targets 0x253c, is taken when s4(?) == 0, and falls through when s4(?) != 0.
  The `beq` branch at 0x2384 targets 0x260c and is always taken.
  The `beq` branch at 0x239c targets 0x2374, is taken when s0(?) >= 0x6 (signed), and falls through when s0(?) < 0x6 (signed).
  The `beq` branch at 0x23a4 targets 0x238c, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `bne` branch at 0x23b0 targets 0x238c, is taken when a7(?) != s2(=one of 0x2, 0x4), and falls through when a7(?) == s2(=one of 0x2, 0x4).
  The `bne` branch at 0x23c0 targets 0x238c, is taken when s1(=ret(pciio_pio_read32)) < a6(?) (unsigned), and falls through when s1(=ret(pciio_pio_read32)) >= a6(?) (unsigned).
  The `beq` branch at 0x23d4 targets 0x238c, is taken when s1(=ret(pciio_pio_read32)) >= t1(?) (unsigned), and falls through when s1(=ret(pciio_pio_read32)) < t1(?) (unsigned).
  The `beq` branch at 0x23f8 targets 0x242c, is taken when (t2(=[a0+248]:8) & 0x18) == 0, and falls through when (t2(=[a0+248]:8) & 0x18) != 0.
  The `bnel` branch at 0x2414 targets 0x2314, is taken when v0(=ret(pciio_error_handler)) != ra(=0x9), and falls through when v0(=ret(pciio_error_handler)) == ra(=0x9); its branch-likely delay slot `ld s2,120(sp)` at 0x2418 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x241c targets 0x25ac and is always taken.
  The `beq` branch at 0x2424 targets 0x2338 and is always taken.
  The `beq` branch at 0x242c targets 0x2400 and is always taken.
  The `beq` branch at 0x2448 targets 0x24b8, is taken when t2(?) == 0, and falls through when t2(?) != 0.
  The `beq` branch at 0x2470 targets 0x2314 and is always taken.
  The `beq` branch at 0x2488 targets 0x24dc, is taken when (t2(?) & 0x7) == 0, and falls through when (t2(?) & 0x7) != 0.
  The `beq` branch at 0x24b0 targets 0x2314 and is always taken.
  The `beq` branch at 0x24d4 targets 0x2314 and is always taken.
  The `beq` branch at 0x24fc targets 0x2314 and is always taken.
  The `beq` branch at 0x2534 targets 0x2314 and is always taken.
  The `beq` branch at 0x2540 targets 0x255c, is taken when s2(=one of 0x2, 0x4) >= 0x16 (unsigned), and falls through when s2(=one of 0x2, 0x4) < 0x16 (unsigned).
  The `beq` branch at 0x2554 targets 0x256c and is always taken.
  The `beq` branch at 0x2588 targets 0x2314 and is always taken.
  The `beq` branch at 0x25a4 targets 0x2314 and is always taken.
  The `beq` branch at 0x25ac targets 0x25cc, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0x25c4 targets 0x25d8 and is always taken.
  The `beq` branch at 0x2604 targets 0x2314 and is always taken.
  The `beq` branch at 0x2614 targets 0x23a4 and is always taken.
  The return at 0x2328 has v0 = one of ret(pciio_pio_write32), ret(pciio_error_handler), ret(cmn_err).
  The instructions from 0x2504 to 0x2504 are not reached by any path from the entry, and their branches are not listed.

- `IP32_hinv_location` in `IP32/usr/cpu/sysgen/IP32boot/pcimh.o` at 0x261c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/pcimh.o`.
  Range: 0x261c-0x2654 (56 bytes).
  It occupies 56 bytes.
  The `lbu` at 0x262c loads 1 byte from ret(device_info_get) +0xe.
  The `lbu` at 0x2630 loads 1 byte from ret(device_info_get) +0xc.
  The `lbu` at 0x263c loads 1 byte from ret(device_info_get) +0xd.
  The `jal` at 0x2624 calls device_info_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x264c has v0 = ([ret(device_info_get)+13]:1 | (([ret(device_info_get)+12]:1 << 0x10) | ([ret(device_info_get)+14]:1 << 0x8))).
