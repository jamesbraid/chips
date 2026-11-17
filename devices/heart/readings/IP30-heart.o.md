# Readings: `IP30/usr/cpu/sysgen/IP30boot/heart.o`

One entry per routine, filed here from the reading batches by binary.

- `heart_intr_level_alloc` in `IP30/usr/cpu/sysgen/IP30boot/heart.o` at 0x260 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/heart.o`.
  Range: 0x260-0x3b4 (340 bytes).
  It occupies 340 bytes.
  The `jal` at 0x29c calls heart_rev with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x2c0 calls heart_intr_bit_alloc with a0=0x3ffff00000000, a1=?, a2=?, a3=?.
  The `jal` at 0x2e8 calls heart_intr_bit_alloc with a0=0x4000000000000, a1=?, a2=?, a3=?.
  The `jal` at 0x304 calls heart_intr_bit_alloc with a0=0x3ffff00000000, a1=?, a2=?, a3=?.
  The `jal` at 0x320 calls heart_intr_bit_alloc with a0=0xffff, a1=?, a2=?, a3=?.
  The `jal` at 0x340 calls heart_intr_bit_alloc with a0=0xffff0000, a1=?, a2=?, a3=?.
  The `jal` at 0x360 calls heart_intr_bit_alloc with a0=0xfff8000000000000, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x380 calls heart_intr_bit_alloc with a0=0xffff0000, a1=?, a2=?, a3=?.
  The `jal` at 0x3a4 calls cmn_err with a0=0x0, a1=sym(.rodata), a2=a0 at entry (arg0), a3=?.
  The `beq` branch at 0x270 targets 0x35c, is taken when a0 == at(=0x4), and falls through when a0 != at(=0x4).
  The `beq` branch at 0x27c targets 0x2e4, is taken when a0 == v0(=0x3), and falls through when a0 != v0(=0x3).
  The `beq` branch at 0x284 targets 0x304, is taken when a0 == v1(=0x2), and falls through when a0 != v1(=0x2).
  The `beq` branch at 0x28c targets 0x33c, is taken when s0(=a0) == a0(=0x1), and falls through when s0(=a0) != a0(=0x1).
  The `bne` branch at 0x294 targets 0x3a0, is taken when s0(=a0) != 0, and falls through when s0(=a0) == 0.
  The `beq` branch at 0x2a8 targets 0x320, is taken when v0(=ret(heart_rev)) >= 0x3 (signed), and falls through when v0(=ret(heart_rev)) < 0x3 (signed).
  The `blez` branch at 0x2b0 targets 0x37c, is taken when s0(=a0) <= 0 (signed), and falls through when s0(=a0) > 0 (signed).
  The `beq` branch at 0x2b8 targets 0x3a0, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0x2cc targets 0x3a0, is taken when v0(=ret(heart_intr_bit_alloc)) == a3(=-0x1), and falls through when v0(=ret(heart_intr_bit_alloc)) != a3(=-0x1).
  The `beq` branch at 0x2f4 targets 0x304, is taken when v0(=ret(heart_intr_bit_alloc)) == a1(=-0x1), and falls through when v0(=ret(heart_intr_bit_alloc)) != a1(=-0x1).
  The `beq` branch at 0x2fc targets 0x2d8 and is always taken.
  The `beq` branch at 0x310 targets 0x340, is taken when v0(=ret(heart_intr_bit_alloc)) == a2(=-0x1), and falls through when v0(=ret(heart_intr_bit_alloc)) != a2(=-0x1).
  The `beq` branch at 0x318 targets 0x2d8 and is always taken.
  The `beq` branch at 0x32c targets 0x2b0, is taken when v0(=ret(heart_intr_bit_alloc)) == a3(=-0x1), and falls through when v0(=ret(heart_intr_bit_alloc)) != a3(=-0x1).
  The `beq` branch at 0x334 targets 0x2d8 and is always taken.
  The `beq` branch at 0x34c targets 0x29c, is taken when v0(=ret(heart_intr_bit_alloc)) == a1(=-0x1), and falls through when v0(=ret(heart_intr_bit_alloc)) != a1(=-0x1).
  The `beq` branch at 0x354 targets 0x2d8 and is always taken.
  The `beq` branch at 0x36c targets 0x2e8, is taken when v0(=ret(heart_intr_bit_alloc)) == a1(=-0x1), and falls through when v0(=ret(heart_intr_bit_alloc)) != a1(=-0x1).
  The `beq` branch at 0x374 targets 0x2d8 and is always taken.
  The `beq` branch at 0x38c targets 0x2b8, is taken when v0(=ret(heart_intr_bit_alloc)) == a1(=-0x1), and falls through when v0(=ret(heart_intr_bit_alloc)) != a1(=-0x1).
  The `beq` branch at 0x394 targets 0x2d8 and is always taken.
  The `beq` branch at 0x3ac targets 0x2d4 and is always taken.
  The return at 0x2dc has v0 = one of ?, ret(heart_intr_bit_alloc).
  The instructions from 0x39c to 0x39c are not reached by any path from the entry, and their branches are not listed.

- `heart_mlreset` in `IP30/usr/cpu/sysgen/IP30boot/heart.o` at 0x4c8.
  Role (from name): HEART chip reset. It calls getcpuid (0x4d0) first with its own arguments, makes ten stores (0x4e8 to 0x554 and 0x568; their addresses are not resolved in the facts), and returns the base address 0xffffffffaff10000 (0x564). The facts do not show what the stores write, and the name "mlreset" is not explained by them.
  Grade: inferred.
  Reviewed: 2026-11-12

- `heart_addr_phys_to_xio` in `IP30/usr/cpu/sysgen/IP30boot/heart.o` at 0x864 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/heart.o`.
  Range: 0x864-0x984 (288 bytes).
  It occupies 288 bytes.
  The `beq` branch at 0x870 targets 0x87c, is taken when a0 >= 0x4000 (unsigned), and falls through when a0 < 0x4000 (unsigned).
  The `beq` branch at 0x88c targets 0x8c4, is taken when v0(?) >= a3(=0x20000000) (unsigned), and falls through when v0(?) < a3(=0x20000000) (unsigned).
  The `bne` branch at 0x8a4 targets 0x8cc, is taken when v0(?) < a4(=0x10000000) (unsigned), and falls through when v0(?) >= a4(=0x10000000) (unsigned).
  The `beq` branch at 0x8b8 targets 0x974, is taken when a6(?) == a3(=0x8), and falls through when a6(?) != a3(=0x8).
  The `bne` branch at 0x8e4 targets 0x920, is taken when v0(?) < a1(=0x800000000) (unsigned), and falls through when v0(?) >= a1(=0x800000000) (unsigned).
  The `beq` branch at 0x8f4 targets 0x92c, is taken when t0(?) == 0, and falls through when t0(?) != 0.
  The `beq` branch at 0x910 targets 0x97c, is taken when a3(?) == a4(=0x8), and falls through when a3(?) != a4(=0x8).
  The `bne` branch at 0x924 targets 0x96c, is taken when v0(?) < a0(=0x1000000000) (unsigned), and falls through when v0(?) >= a0(=0x1000000000) (unsigned).
  The `beq` branch at 0x92c targets 0x96c, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0x95c targets 0x8c4, is taken when a3(?) == a4(=0x8), and falls through when a3(?) != a4(=0x8).
  The return at 0x8c4 has v0 = ?.
  The return at 0x918 has v0 = ?.
  The return at 0x964 has v0 = ?.
  The return at 0x96c has v0 = -0x1.
  The return at 0x974 has v0 = ?.
  The return at 0x97c has v0 = ?.

- `heart_addr_xio_to_phys` in `IP30/usr/cpu/sysgen/IP30boot/heart.o` at 0x984 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/heart.o`.
  Range: 0x984-0xa28 (164 bytes).
  It occupies 164 bytes.
  The `beq` branch at 0x998 targets 0x9a8, is taken when (a1 & v1(=0xf000000000000000)) == 0, and falls through when (a1 & v1(=0xf000000000000000)) != 0.
  The `beq` branch at 0x9c0 targets 0x9f4, is taken when a3(=0x1000000) >= a5(?) (unsigned), and falls through when a3(=0x1000000) < a5(?) (unsigned).
  The `beq` branch at 0x9d4 targets 0xa0c, is taken when a4(=0x80000000) >= a5(?) (unsigned), and falls through when a4(=0x80000000) < a5(?) (unsigned).
  The `bne` branch at 0x9dc targets 0x9ec, is taken when a6(?) != 0, and falls through when a6(?) == 0.
  The return at 0x9e4 has v0 = ?.
  The return at 0x9ec has v0 = 0x0.
  The return at 0xa04 has v0 = table(0x10000000).
  The return at 0xa20 has v0 = table(0x800000000).

- `heart_piomap_alloc` in `IP30/usr/cpu/sysgen/IP30boot/heart.o` at 0xa60 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/heart.o`.
  Range: 0xa60-0xb20 (192 bytes).
  It occupies 192 bytes.
  The `sd` at 0xae0 stores 8 bytes to ret(kmem_zalloc) +0x8.
  The `sd` at 0xae4 stores 8 bytes to ret(kmem_zalloc) +0x10.
  The `sd` at 0xae8 stores 8 bytes to ret(kmem_zalloc) +0x18.
  The `sw` at 0xaec stores 4 bytes to ret(kmem_zalloc) +0x20.
  The `sw` at 0xaf0 stores 4 bytes to ret(kmem_zalloc) +0x0.
  The `sb` at 0xaf8 stores 1 byte to ret(kmem_zalloc) +0x4.
  The `jal` at 0xa80 calls heart_widget_num with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa98 calls heart_addr_xio_to_kva with a0=?, a1=a2 at entry (arg2), a2=a3 at entry (arg3), a3=?.
  The `jal` at 0xab4 calls kmem_zalloc with a0=0x28, a1=?, a2=?, a3=?.
  The `beq` branch at 0xaa4 targets 0xb18, is taken when v0(=ret(heart_addr_xio_to_kva)) == 0, and falls through when v0(=ret(heart_addr_xio_to_kva)) != 0.
  The `beq` branch at 0xac0 targets 0xb18, is taken when v0(=ret(kmem_zalloc)) == 0, and falls through when v0(=ret(kmem_zalloc)) != 0.
  The `beq` branch at 0xac8 targets 0xae0, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0xb18 targets 0xafc and is always taken.
  The return at 0xb10 has v0 = one of ret(kmem_zalloc), 0x0.

- `heart_dmamap_list` in `IP30/usr/cpu/sysgen/IP30boot/heart.o` at 0xc4c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/heart.o`.
  Range: 0xc4c-0xdb8 (364 bytes).
  It occupies 364 bytes.
  The `jal` at 0xc74 calls alenlist_cursor_init with a0=a1 at entry (arg1), a1=0x0, a2=0x0, a3=a3 at entry (arg3).
  The `jal` at 0xc9c calls alenlist_get with a0=a1 at entry (arg1), a1=0x0, a2=0x0, a3=sp-80, a4=sp-72, a5=0x0.
  The `jal` at 0xce0 calls heart_addr_phys_to_xio with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xd0c calls alenlist_replace with a0=?, a1=0x0, a2=sp-64, a3=sp-72.
  The `jal` at 0xd40 calls alenlist_append with a0=?, a1=ret(heart_addr_phys_to_xio), a2=?, a3=?.
  The `jal` at 0xd60 calls alenlist_get with a0=a1 at entry (arg1), a1=0x0, a2=0x0, a3=sp-80, a4=sp-72, a5=0x0.
  The `jal` at 0xd7c calls alenlist_create with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xd98 calls alenlist_done with a0=a1 at entry (arg1), a1=?, a2=?, a3=?.
  The `jal` at 0xda8 calls alenlist_destroy with a0=?, a1=?, a2=?, a3=?.
  The `beq` branch at 0xc80 targets 0xd78, is taken when (s3(=a2) & 0x4) == 0, and falls through when (s3(=a2) & 0x4) != 0.
  The `beq` branch at 0xca4 targets 0xcd4, is taken when v0(=ret(alenlist_get)) == 0, and falls through when v0(=ret(alenlist_get)) != 0.
  The `beq` branch at 0xcac targets 0xd98, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `beq` branch at 0xce8 targets 0xd34, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `beq` branch at 0xcf4 targets 0xd50, is taken when v1(?) == v0(=ret(heart_addr_phys_to_xio)), and falls through when v1(?) != v0(=ret(heart_addr_phys_to_xio)).
  The `beq` branch at 0xd14 targets 0xd50, is taken when v0(=ret(alenlist_replace)) == 0, and falls through when v0(=ret(alenlist_replace)) != 0.
  The `beq` branch at 0xd1c targets 0xd2c, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `beq` branch at 0xd24 targets 0xda8, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `beq` branch at 0xd2c targets 0xcb4 and is always taken.
  The `bne` branch at 0xd48 targets 0xd1c, is taken when v0(=ret(alenlist_append)) != 0, and falls through when v0(=ret(alenlist_append)) == 0.
  The `beq` branch at 0xd68 targets 0xce0, is taken when v0(=ret(alenlist_get)) == 0, and falls through when v0(=ret(alenlist_get)) != 0.
  The `beq` branch at 0xd70 targets 0xcac and is always taken.
  The `beq` branch at 0xd88 targets 0xc88, is taken when v0(=ret(alenlist_create)) >= 0x1 (unsigned), and falls through when v0(=ret(alenlist_create)) < 0x1 (unsigned).
  The `beq` branch at 0xd90 targets 0xd1c and is always taken.
  The `beq` branch at 0xda0 targets 0xcb4 and is always taken.
  The `beq` branch at 0xdb0 targets 0xd2c and is always taken.
  The return at 0xccc has v0 = one of ?, 0x0.

- `heart_dmatrans_list` in `IP30/usr/cpu/sysgen/IP30boot/heart.o` at 0xde0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/heart.o`.
  Range: 0xde0-0xf4c (364 bytes).
  It occupies 364 bytes.
  The `jal` at 0xe08 calls alenlist_cursor_init with a0=a2 at entry (arg2), a1=0x0, a2=0x0, a3=a3 at entry (arg3).
  The `jal` at 0xe30 calls alenlist_get with a0=a2 at entry (arg2), a1=0x0, a2=0x0, a3=sp-80, a4=sp-72, a5=0x0.
  The `jal` at 0xe74 calls heart_addr_phys_to_xio with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xea0 calls alenlist_replace with a0=?, a1=0x0, a2=sp-64, a3=sp-72.
  The `jal` at 0xed4 calls alenlist_append with a0=?, a1=ret(heart_addr_phys_to_xio), a2=?, a3=?.
  The `jal` at 0xef4 calls alenlist_get with a0=a2 at entry (arg2), a1=0x0, a2=0x0, a3=sp-80, a4=sp-72, a5=0x0.
  The `jal` at 0xf10 calls alenlist_create with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xf2c calls alenlist_done with a0=a2 at entry (arg2), a1=?, a2=?, a3=?.
  The `jal` at 0xf3c calls alenlist_destroy with a0=?, a1=?, a2=?, a3=?.
  The `beq` branch at 0xe14 targets 0xf0c, is taken when (s3(=a3) & 0x4) == 0, and falls through when (s3(=a3) & 0x4) != 0.
  The `beq` branch at 0xe38 targets 0xe68, is taken when v0(=ret(alenlist_get)) == 0, and falls through when v0(=ret(alenlist_get)) != 0.
  The `beq` branch at 0xe40 targets 0xf2c, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `beq` branch at 0xe7c targets 0xec8, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `beq` branch at 0xe88 targets 0xee4, is taken when v1(?) == v0(=ret(heart_addr_phys_to_xio)), and falls through when v1(?) != v0(=ret(heart_addr_phys_to_xio)).
  The `beq` branch at 0xea8 targets 0xee4, is taken when v0(=ret(alenlist_replace)) == 0, and falls through when v0(=ret(alenlist_replace)) != 0.
  The `beq` branch at 0xeb0 targets 0xec0, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `beq` branch at 0xeb8 targets 0xf3c, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `beq` branch at 0xec0 targets 0xe48 and is always taken.
  The `bne` branch at 0xedc targets 0xeb0, is taken when v0(=ret(alenlist_append)) != 0, and falls through when v0(=ret(alenlist_append)) == 0.
  The `beq` branch at 0xefc targets 0xe74, is taken when v0(=ret(alenlist_get)) == 0, and falls through when v0(=ret(alenlist_get)) != 0.
  The `beq` branch at 0xf04 targets 0xe40 and is always taken.
  The `beq` branch at 0xf1c targets 0xe1c, is taken when v0(=ret(alenlist_create)) >= 0x1 (unsigned), and falls through when v0(=ret(alenlist_create)) < 0x1 (unsigned).
  The `beq` branch at 0xf24 targets 0xeb0 and is always taken.
  The `beq` branch at 0xf34 targets 0xe48 and is always taken.
  The `beq` branch at 0xf44 targets 0xec0 and is always taken.
  The return at 0xe60 has v0 = one of ?, 0x0.

- `do_heart_intr_alloc` in `IP30/usr/cpu/sysgen/IP30boot/heart.o` at 0x1028 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/heart.o`.
  Range: 0x1028-0x11ec (452 bytes).
  It occupies 452 bytes.
  3 such `ll` accesses load 4 bytes from (sym(heart_ivec) + (ret(heart_intr_level_alloc) << 0x6)) +0x18, including `ll` at 0x10bc, `ll` at 0x10e4, `ll` at 0x11d0.
  3 such `sc` accesses store 4 bytes to (sym(heart_ivec) + (ret(heart_intr_level_alloc) << 0x6)) +0x18, including `sc` at 0x10c4, `sc` at 0x10ec, `sc` at 0x11d8.
  3 such `sw` accesses store 4 bytes to ret(kmem_zalloc) +0x0, including `sw` at 0x10fc, `sw` at 0x1160, `sw` at 0x11e8.
  The `sb` at 0x1164 stores 1 byte to ret(kmem_zalloc) +0x5.
  The `sd` at 0x116c stores 8 bytes to ret(kmem_zalloc) +0x8.
  The `sd` at 0x1170 stores 8 bytes to ret(kmem_zalloc) +0x10.
  The `sd` at 0x1174 stores 8 bytes to ret(kmem_zalloc) +0x18.
  The `sw` at 0x1178 stores 4 bytes to ret(kmem_zalloc) +0x28.
  The `sw` at 0x117c stores 4 bytes to ret(kmem_zalloc) +0x20.
  The `sb` at 0x1184 stores 1 byte to ret(kmem_zalloc) +0x4.
  The `sh` at 0x1194 stores 2 bytes to ret(kmem_zalloc) +0x24.
  The `jal` at 0x104c calls kmem_zalloc with a0=0x30, a1=0x0, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1064 calls device_desc_default_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x107c calls heart_intr_swlevel_to_hwlevel with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1084 calls heart_intr_level_alloc with a0=ret(heart_intr_swlevel_to_hwlevel), a1=?, a2=?, a3=?.
  The `jal` at 0x1100 calls device_desc_flags_get with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1110 calls device_desc_intr_swlevel_get with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1130 calls xwidget_info_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x1138 calls xwidget_info_id_get with a0=ret(xwidget_info_get), a1=?, a2=?, a3=?.
  The `jal` at 0x1154 calls heart_intr_bits_take with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1188 calls intr_spray_heuristic with a0=?, a1=?, a2=?, a3=?.
  The `beq` branch at 0x1054 targets 0x1198, is taken when v0(=ret(kmem_zalloc)) == 0, and falls through when v0(=ret(kmem_zalloc)) != 0.
  The `bne` branch at 0x105c targets 0x1100, is taken when s0(=a1) != 0, and falls through when s0(=a1) == 0.
  The `bne` branch at 0x1070 targets 0x1100, is taken when v0(=ret(device_desc_default_get)) != 0, and falls through when v0(=ret(device_desc_default_get)) == 0.
  The `bne` branch at 0x10a8 targets 0x10d0, is taken when at(=[sym(graphics_intr_pri)]) != s2(?), and falls through when at(=[sym(graphics_intr_pri)]) == s2(?).
  The `beql` branch at 0x10c8 targets 0x10bc, is taken when t1(=([(sym(heart_ivec) + (ret(heart_intr_level_alloc) << 0x6))+24] | 0x1)) == 0, and falls through when t1(=([(sym(heart_ivec) + (ret(heart_intr_level_alloc) << 0x6))+24] | 0x1)) != 0; its branch-likely delay slot `nop` at 0x10cc runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x10d4 targets 0x11b4, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beql` branch at 0x10f0 targets 0x10e4, is taken when (a7(=[(sym(heart_ivec) + (ret(heart_intr_level_alloc) << 0x6))+24]) & t1(=-0x101)) == 0, and falls through when (a7(=[(sym(heart_ivec) + (ret(heart_intr_level_alloc) << 0x6))+24]) & t1(=-0x101)) != 0; its branch-likely delay slot `nop` at 0x10f4 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x10f8 targets 0x1164 and is always taken.
  The `beq` branch at 0x1128 targets 0x107c, is taken when (t3(=ret(device_desc_flags_get)) & 0x1) == 0, and falls through when (t3(=ret(device_desc_flags_get)) & 0x1) != 0.
  The `bne` branch at 0x11b8 targets 0x10e0, is taken when at(=a3) != 0, and falls through when at(=a3) == 0.
  The `beql` branch at 0x11dc targets 0x11d0, is taken when a1(=([(sym(heart_ivec) + (ret(heart_intr_level_alloc) << 0x6))+24] | 0x100)) == 0, and falls through when a1(=([(sym(heart_ivec) + (ret(heart_intr_level_alloc) << 0x6))+24] | 0x100)) != 0; its branch-likely delay slot `nop` at 0x11e0 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x11e4 targets 0x1164 and is always taken.
  The return at 0x11ac has v0 = ret(kmem_zalloc).

- `heart_intr_connect` in `IP30/usr/cpu/sysgen/IP30boot/heart.o` at 0x1260 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/heart.o`.
  Range: 0x1260-0x1334 (212 bytes).
  It occupies 212 bytes.
  The `lbu` at 0x1268 loads 1 byte from a0 (arg0 at entry) +0x5.
  The `lh` at 0x1278 loads 2 bytes from a0 (arg0 at entry) +0x24.
  The `sd` at 0x1280 stores 8 bytes to (sym(heart_ivec) + ([a0+5]:1 << 0x6)) +0x8.
  The `sd` at 0x1284 stores 8 bytes to (sym(heart_ivec) + ([a0+5]:1 << 0x6)) +0x0.
  The `sd` at 0x1288 stores 8 bytes to a0 (arg0 at entry) +0x18.
  The `sd` at 0x128c stores 8 bytes to a0 (arg0 at entry) +0x10.
  The `lw` at 0x1290 loads 4 bytes from (sym(heart_ivec) + ([a0+5]:1 << 0x6)) +0x18.
  The `sh` at 0x12b8 stores 2 bytes to (sym(heart_ivec) + ([a0+5]:1 << 0x6)) +0x10.
  The `ll` at 0x12bc loads 4 bytes from (sym(heart_ivec) + ([a0+5]:1 << 0x6)) +0x18.
  The `sc` at 0x12c4 stores 4 bytes to (sym(heart_ivec) + ([a0+5]:1 << 0x6)) +0x18.
  The `lw` at 0x12e4 loads 4 bytes from a0 (arg0 at entry) +0x20.
  The `jal` at 0x12e0 calls heart_ithread_setup with a0=[a0+36]:2, a1=[a0+5]:1, a2=[a0+32], a3=a3 at entry (arg3), a6=(sym(heart_ivec) + ([a0+5]:1 << 0x6)), a7=(sym(heart_ivec) + ([a0+5]:1 << 0x6))+24.
  The `jal` at 0x1304 calls heart_imr_bits_rmw with a0=[a0+36]:2, a1=0x0, a2=?, a3=?.
  The `jalr` at 0x1324 calls (unknown callee) with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `beq` branch at 0x12b0 targets 0x12e8, is taken when (at(=[(sym(heart_ivec) + ([a0+5]:1 << 0x6))+24]) & 0x100) == 0, and falls through when (at(=[(sym(heart_ivec) + ([a0+5]:1 << 0x6))+24]) & 0x100) != 0.
  The `beql` branch at 0x12c8 targets 0x12bc, is taken when t3(=([(sym(heart_ivec) + ([a0+5]:1 << 0x6))+24] | 0x200)) == 0, and falls through when t3(=([(sym(heart_ivec) + ([a0+5]:1 << 0x6))+24] | 0x200)) != 0; its branch-likely delay slot `nop` at 0x12cc runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x12d4 targets 0x12e8, is taken when t1(=[sym(ithreads_enabled)]) == 0, and falls through when t1(=[sym(ithreads_enabled)]) != 0.
  The `bne` branch at 0x12e8 targets 0x1324, is taken when s2(=a3) != 0, and falls through when s2(=a3) == 0.
  The `beq` branch at 0x132c targets 0x12f4 and is always taken.
  The return at 0x131c has v0 = 0x0.

- `heart_paddr_to_port` in `IP30/usr/cpu/sysgen/IP30boot/heart.o` at 0x13ec (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/heart.o`.
  Range: 0x13ec-0x1508 (284 bytes).
  It occupies 284 bytes.
  The `sd` at 0x1444 stores 8 bytes to a1 (arg1 at entry) +0x0.
  3 such `sd` accesses store 8 bytes to a2 (arg2 at entry) +0x0, including `sd` at 0x1474, `sd` at 0x14b8, `sd` at 0x14f0.
  The `bne` branch at 0x13fc targets 0x143c, is taken when a0 < 0x4000 (unsigned), and falls through when a0 >= 0x4000 (unsigned).
  The `bne` branch at 0x1424 targets 0x1454, is taken when a0 < v1(=0x20004000) (unsigned), and falls through when a0 >= v1(=0x20004000) (unsigned).
  The `beq` branch at 0x1434 targets 0x1454, is taken when a0 >= a3(=0x800000000) (unsigned), and falls through when a0 < a3(=0x800000000) (unsigned).
  The `beq` branch at 0x143c targets 0x144c, is taken when a1 == 0, and falls through when a1 != 0.
  The `bne` branch at 0x1458 targets 0x1484, is taken when v0(?) != 0, and falls through when v0(?) == 0.
  The `beq` branch at 0x1460 targets 0x1488, is taken when t0(?) == 0, and falls through when t0(?) != 0.
  The `beq` branch at 0x146c targets 0x1478, is taken when a2 == 0, and falls through when a2 != 0.
  The `bne` branch at 0x149c targets 0x14d0, is taken when a0 < v1(=0x800000000) (unsigned), and falls through when a0 >= v1(=0x800000000) (unsigned).
  The `beq` branch at 0x14a8 targets 0x14dc, is taken when a0 >= v0(=0x1000000000) (unsigned), and falls through when a0 < v0(=0x1000000000) (unsigned).
  The `beq` branch at 0x14b0 targets 0x14c0, is taken when a2 == 0, and falls through when a2 != 0.
  The `bne` branch at 0x14d4 targets 0x1500, is taken when a0 < v0(=0x1000000000) (unsigned), and falls through when a0 >= v0(=0x1000000000) (unsigned).
  The `beq` branch at 0x14e0 targets 0x1500, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0x14e8 targets 0x14f4, is taken when a2 == 0, and falls through when a2 != 0.
  The return at 0x144c has v0 = 0xfe.
  The return at 0x147c has v0 = ?.
  The return at 0x14c8 has v0 = ?.
  The return at 0x14f8 has v0 = ?.
  The return at 0x1500 has v0 = 0xff.

- `heart_error_refine` in `IP30/usr/cpu/sysgen/IP30boot/heart.o` at 0x1508 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/heart.o`.
  Range: 0x1508-0x15fc (244 bytes).
  It occupies 244 bytes.
  2 such `lw` accesses load 4 bytes from a3 (arg3 at entry) +0x0, including `lw` at 0x1508, `lw` at 0x1598.
  The `lbu` at 0x1530 loads 1 byte from a3 (arg3 at entry) +0x7.
  The `ld` at 0x1580 loads 8 bytes from a3 (arg3 at entry) +0x10.
  3 such `sw` accesses store 4 bytes to a3 (arg3 at entry) +0x0, including `sw` at 0x15a8, `sw` at 0x15bc, `sw` at 0x15f0.
  The `sh` at 0x15ac stores 2 bytes to a3 (arg3 at entry) +0x6.
  The `sd` at 0x15c4 stores 8 bytes to a3 (arg3 at entry) +0x18.
  The `sd` at 0x15f8 stores 8 bytes to a3 (arg3 at entry) +0x38.
  The `jal` at 0x157c calls heart_paddr_to_port with a0=[a3+16]:8, a1=sp-48, a2=sp-40, a3=a3 at entry (arg3), a5=[a3].
  The `jal` at 0x15d8 calls xtalk_error_handler with a0=[sym(the_error_vhdl)], a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `bltz` branch at 0x1520 targets 0x1558, is taken when at(=([a3] << 0x6)) < 0 (signed), and falls through when at(=([a3] << 0x6)) >= 0 (signed).
  The `bgez` branch at 0x1528 targets 0x1540, is taken when v0(?) >= 0 (signed), and falls through when v0(?) < 0 (signed).
  The `bne` branch at 0x1538 targets 0x15d8, is taken when v0(=[a3+7]:1) < 0x10 (signed), and falls through when v0(=[a3+7]:1) >= 0x10 (signed).
  The `bgez` branch at 0x155c targets 0x1574, is taken when v0(=([a3] << 0x1)) >= 0 (signed), and falls through when v0(=([a3] << 0x1)) < 0 (signed).
  The `bltz` branch at 0x156c targets 0x1528, is taken when v1(=([a3] << 0x7)) < 0 (signed), and falls through when v1(=([a3] << 0x7)) >= 0 (signed).
  The `beq` branch at 0x159c targets 0x15c8, is taken when a3(?) >= 0x10 (signed), and falls through when a3(?) < 0x10 (signed).
  The `beq` branch at 0x15c0 targets 0x15d0 and is always taken.
  The `beq` branch at 0x15c8 targets 0x15e8, is taken when a3(?) == a6(=0xfe), and falls through when a3(?) != a6(=0xfe).
  The `beq` branch at 0x15d0 targets 0x1528 and is always taken.
  The `beq` branch at 0x15e0 targets 0x1544 and is always taken.
  The `beq` branch at 0x15f4 targets 0x15d0 and is always taken.
  The return at 0x1550 has v0 = one of 0x9, ret(xtalk_error_handler).

- `heart_intr` in `IP30/usr/cpu/sysgen/IP30boot/heart.o` at 0x1630 (n64).
  Grade: inferred.
  It reads the doubleword at 0xffffffffaff10038, ANDs it with its second argument and, while the result is nonzero, loops: it passes the masked value to `ffintr64` and uses the returned index to pick a 64-byte entry of `heart_ivec`. An index of 0x3b or more goes to `buserror_intr` at 0x171c with the first argument. For a lower index the entry's word at +0x18 decides the path. With bit 0x1000 clear, the indirect call at 0x1730 runs through the doubleword at +0x0, with the doubleword at +0x8 as its first argument. With that bit set, the path runs `valusema` on the entry's +0x20 and then `cvsema` when the result is 0x7001 or more, or `vsema` when it is lower. The loop stores 1 shifted left by the index to 0xffffffffaff10028, before the handler for indexes of 3 and above and after it for lower ones. On exit it adds the pass count less one to the word at offset 0xd0 of whatever the pointer at absolute address -0x3b78 points to, with an `ll`/`sc` loop. How the status bits at 0xffffffffaff10038 map to vectors is open.
  Reviewed: 2026-11-12

- `enable_ithreads` in `IP30/usr/cpu/sysgen/IP30boot/heart.o` at 0x18c0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/heart.o`.
  Range: 0x18c0-0x1978 (184 bytes).
  It occupies 184 bytes.
  The `lw` at 0x18e4 loads 4 bytes from ?.
  The `lh` at 0x18fc loads 2 bytes from ?.
  The `lh` at 0x191c loads 2 bytes from abs 0xffffffffffffc3a0.
  The `sh` at 0x1934 stores 2 bytes to sym(heart_ivec) +0x1010.
  The `ll` at 0x1938 loads 4 bytes from sym(heart_ivec) +0x0.
  The `sc` at 0x1940 stores 4 bytes to sym(heart_ivec) +0x0.
  The `jal` at 0x18f8 calls heart_ithread_setup with a0=?, a1=?, a2=[sym(default_intr_pri)], a3=?.
  The `jal` at 0x194c calls xthread_setup with a0=sym(.rodata), a1=0xff, a2=sym(heart_ivec), a3=sym(heart_intrd_start), a4=sym(heart_ivec), a5=sym(heart_stray_intr), a6=0x300, a7=(sym(heart_stray_intr) | 0x300).
  The `beq` branch at 0x18ec targets 0x1900, is taken when (at(?) & 0x200) == 0, and falls through when (at(?) & 0x200) != 0.
  The `bne` branch at 0x190c targets 0x18e4, is taken when s0(?) < 0x40 (signed), and falls through when s0(?) >= 0x40 (signed).
  The `beql` branch at 0x1944 targets 0x1938, is taken when a7(=(sym(heart_stray_intr) | 0x300)) == 0, and falls through when a7(=(sym(heart_stray_intr) | 0x300)) != 0; its branch-likely delay slot `nop` at 0x1948 runs only when taken and is annulled on fall-through.
  The return at 0x1970 has v0 = ret(xthread_setup).
