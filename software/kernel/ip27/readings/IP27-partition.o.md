# Readings: `IP27/usr/cpu/sysgen/IP27boot/partition.o`

One entry per routine, filed here from the reading batches by binary.

- `nasid_to_partid` in `IP27/usr/cpu/sysgen/IP27boot/partition.o` at 0x0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/partition.o`.
  Range: 0x0-0x20 (32 bytes).
  It occupies 32 bytes.
  The `lb` at 0x1c loads 1 byte from table(sym(.bss)) +0x6.
  The return at 0x18 has v0 = [table(sym(.bss))+6]:1.

- `part_avl_start` in `IP27/usr/cpu/sysgen/IP27boot/partition.o` at 0x20 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/partition.o`.
  Range: 0x20-0x28 (8 bytes).
  It occupies 8 bytes.
  The `ld` at 0x24 loads 8 bytes from a0 (arg0 at entry) +0x28.
  The return at 0x20 has v0 = [a0+40]:8.

- `part_avl_end` in `IP27/usr/cpu/sysgen/IP27boot/partition.o` at 0x28 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/partition.o`.
  Range: 0x28-0x38 (16 bytes).
  It occupies 16 bytes.
  The `ld` at 0x28 loads 8 bytes from a0 (arg0 at entry) +0x30.
  The `ld` at 0x2c loads 8 bytes from a0 (arg0 at entry) +0x28.
  The return at 0x30 has v0 = ([a0+40]:8 + [a0+48]:8).

- `part_hold_page` in `IP27/usr/cpu/sysgen/IP27boot/partition.o` at 0x38 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/partition.o`.
  Range: 0x38-0x48 (16 bytes).
  It occupies 16 bytes.
  The `lw` at 0x38 loads 4 bytes from a0 (arg0 at entry) +0x58.
  The `sw` at 0x44 stores 4 bytes to a0 (arg0 at entry) +0x58.
  The return at 0x40 has v0 = ?.

- `part_release_page_nolock` in `IP27/usr/cpu/sysgen/IP27boot/partition.o` at 0x48 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/partition.o`.
  Range: 0x48-0x13c (244 bytes).
  It occupies 244 bytes.
  The `lw` at 0x50 loads 4 bytes from a0 (arg0 at entry) +0x58.
  The `sw` at 0x68 stores 4 bytes to a0 (arg0 at entry) +0x58.
  The `lb` at 0x80 loads 1 byte from a0 (arg0 at entry) +0x40.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x38, including `ld` at 0x9c, `ld` at 0xbc.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x30, including `ld` at 0xa8, `ld` at 0xb4.
  The `lw` at 0xc0 loads 4 bytes from a0 (arg0 at entry) +0x5c.
  The `ll` at 0xd4 loads 4 bytes from (ret(part_get) + one of 0x58, 0x5c) +0x0.
  The `sc` at 0xe0 stores 4 bytes to (ret(part_get) + one of 0x58, 0x5c) +0x0.
  The `sw` at 0x124 stores 4 bytes to ret(part_get) +0xc.
  The `lw` at 0x130 loads 4 bytes from ret(part_get) +0xc.
  The `jal` at 0x84 calls part_get with a0=[a0+64]:1, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x94 calls avl_delete with a0=sym(.bss), a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0xac calls part_pfdat_flags with a0=[a0+56]:8, a1=[a0+48]:8, a2=0x0, a3=0x4000000.
  The `jal` at 0xb8 calls pagefree_size with a0=[a0+56]:8, a1=[a0+48]:8, a2=?, a3=?.
  The `jal` at 0xf8 calls kmem_free with a0=a0 at entry (arg0), a1=0x60, a2=?, a3=?.
  The `jal` at 0x114 calls mutex_spinlock with a0=ret(part_get)+8, a1=?, a2=?, a3=?.
  The `jal` at 0x120 calls sv_broadcast with a0=ret(part_get)+152, a1=?, a2=?, a3=?.
  The `jal` at 0x12c calls mutex_spinunlock with a0=ret(part_get)+8, a1=[ret(part_get)+12], a2=?, a3=?.
  The `beq` branch at 0x64 targets 0x80, is taken when s8(=[a0+88]-1) == 0, and falls through when s8(=[a0+88]-1) != 0.
  The `beq` branch at 0xa0 targets 0xc0, is taken when a0(=[a0+56]:8) == 0, and falls through when a0(=[a0+56]:8) != 0.
  The `beq` branch at 0xcc targets 0x108, is taken when (ra(=[a0+92]) & 0x10) == 0, and falls through when (ra(=[a0+92]) & 0x10) != 0.
  The `beql` branch at 0xe4 targets 0xd4, is taken when v1(?) == 0, and falls through when v1(?) != 0; its branch-likely delay slot `nop` at 0xe8 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0xec targets 0x110, is taken when at(?) == 0, and falls through when at(?) != 0.
  The `beq` branch at 0x100 targets 0x6c and is always taken.
  The `beq` branch at 0x108 targets 0xd4 and is always taken.
  The `beq` branch at 0x134 targets 0xf4 and is always taken.
  The return at 0x78 has v0 = [a0+88]-1.

- `part_release_page` in `IP27/usr/cpu/sysgen/IP27boot/partition.o` at 0x13c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/partition.o`.
  Range: 0x13c-0x188 (76 bytes).
  It occupies 76 bytes.
  The `jal` at 0x150 calls mutex_spinlock_spl with a0=sym(.sbss), a1=sym(splerr), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x15c calls part_release_page_nolock with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x16c calls mutex_spinunlock with a0=sym(.sbss), a1=[sym(.sbss)+4], a2=?, a3=?.
  The return at 0x180 has v0 = ret(part_release_page_nolock).

- `part_find_page` in `IP27/usr/cpu/sysgen/IP27boot/partition.o` at 0x188 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/partition.o`.
  Range: 0x188-0x1ec (100 bytes).
  It occupies 100 bytes.
  The `jal` at 0x19c calls mutex_spinlock_spl with a0=sym(.sbss), a1=sym(splerr), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1ac calls avl_findrange with a0=sym(.bss), a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0x1c0 calls mutex_spinunlock with a0=sym(.sbss), a1=[sym(.sbss)+4], a2=?, a3=?.
  The `jal` at 0x1dc calls part_hold_page with a0=ret(avl_findrange), a1=?, a2=?, a3=?.
  The `bne` branch at 0x1b4 targets 0x1dc, is taken when v0(=ret(avl_findrange)) != 0, and falls through when v0(=ret(avl_findrange)) == 0.
  The `beq` branch at 0x1e4 targets 0x1c0 and is always taken.
  The return at 0x1d4 has v0 = ret(avl_findrange).

- `part_new_page` in `IP27/usr/cpu/sysgen/IP27boot/partition.o` at 0x1ec (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/partition.o`.
  Range: 0x1ec-0x3b4 (456 bytes).
  It occupies 456 bytes.
  The `lw` at 0x278 loads 4 bytes from ret(part_get) +0x20.
  The `sw` at 0x288 stores 4 bytes to ret(part_get) +0xc.
  2 such `sd` accesses store 8 bytes to ret(kmem_alloc) +0x28, including `sd` at 0x2bc, `sd` at 0x314.
  The `lw` at 0x2f8 loads 4 bytes from ret(part_get) +0xc.
  The `sw` at 0x320 stores 4 bytes to ret(kmem_alloc) +0x58.
  The `sd` at 0x324 stores 8 bytes to ret(kmem_alloc) +0x38.
  The `sd` at 0x334 stores 8 bytes to ret(kmem_alloc) +0x48.
  The `sw` at 0x338 stores 4 bytes to ret(kmem_alloc) +0x5c.
  The `sd` at 0x33c stores 8 bytes to ret(kmem_alloc) +0x30.
  The `lb` at 0x340 loads 1 byte from ret(part_get) +0x14.
  The `sb` at 0x344 stores 1 byte to ret(kmem_alloc) +0x40.
  The `ld` at 0x348 loads 8 bytes from ret(part_get) +0x18.
  The `sd` at 0x354 stores 8 bytes to ret(kmem_alloc) +0x50.
  The `ll` at 0x36c loads 4 bytes from ret(part_get) +0x5c.
  The `sc` at 0x378 stores 4 bytes to ret(part_get) +0x5c.
  The `ll` at 0x394 loads 4 bytes from ret(part_get) +0x58.
  The `sc` at 0x3a0 stores 4 bytes to ret(part_get) +0x58.
  The `jal` at 0x218 calls part_id with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x220 calls part_get with a0=ret(part_id), a1=?, a2=?, a3=?.
  The `jal` at 0x230 calls part_from_addr with a0=a1 at entry (arg1), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x238 calls part_get with a0=ret(part_from_addr), a1=?, a2=?, a3=?.
  The `jal` at 0x250 calls kmem_alloc with a0=0x60, a1=0x0, a2=?, a3=?.
  The `jal` at 0x260 calls mutex_spinlock_spl with a0=sym(.sbss), a1=sym(splerr), a2=?, a3=?.
  The `jal` at 0x270 calls mutex_spinlock with a0=ret(part_get)+8, a1=?, a2=?, a3=?.
  The `jal` at 0x2e4 calls kmem_free with a0=ret(kmem_alloc), a1=0x60, a2=0x3fc0000, a3=?.
  The `jal` at 0x2f4 calls mutex_spinunlock with a0=ret(part_get)+8, a1=[ret(part_get)+12], a2=?, a3=?.
  The `jal` at 0x300 calls mutex_spinunlock with a0=sym(.sbss), a1=[sym(.sbss)+4], a2=?, a3=?.
  The `jal` at 0x350 calls avl_insert with a0=sym(.bss), a1=ret(kmem_alloc), a2=?, a3=[ret(part_get)+24]:8, a4=[ret(part_get)+20]:1, a5=0x1, a6=a4 at entry (arg4), a7=a3 at entry (arg3).
  The `beq` branch at 0x210 targets 0x230, is taken when a0 == 0, and falls through when a0 != 0.
  The `beq` branch at 0x228 targets 0x244 and is always taken.
  The `beq` branch at 0x244 targets 0x2c0, is taken when s0(=ret(part_get)) == 0, and falls through when s0(=ret(part_get)) != 0.
  The `bne` branch at 0x284 targets 0x2e0, is taken when at(=[ret(part_get)+32]) != v1(=0x6), and falls through when at(=[ret(part_get)+32]) == v1(=0x6).
  The `beq` branch at 0x28c targets 0x310, is taken when s2(=a0) == 0, and falls through when s2(=a0) != 0.
  The `beq` branch at 0x2b8 targets 0x318 and is always taken.
  The `beq` branch at 0x308 targets 0x2c8 and is always taken.
  The `beq` branch at 0x364 targets 0x38c, is taken when (t1(=a3) & 0x10) == 0, and falls through when (t1(=a3) & 0x10) != 0.
  The `beql` branch at 0x37c targets 0x36c, is taken when t3(=[ret(part_get)+92]+1) == 0, and falls through when t3(=[ret(part_get)+92]+1) != 0; its branch-likely delay slot `nop` at 0x380 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x384 targets 0x2f4 and is always taken.
  The `beql` branch at 0x3a4 targets 0x394, is taken when at(=[ret(part_get)+88]+1) == 0, and falls through when at(=[ret(part_get)+88]+1) != 0; its branch-likely delay slot `nop` at 0x3a8 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x3ac targets 0x2f4 and is always taken.
  The return at 0x2d8 has v0 = one of 0x0, ?.

- `part_init_node` in `IP27/usr/cpu/sysgen/IP27boot/partition.o` at 0x3b4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/partition.o`.
  Range: 0x3b4-0x640 (652 bytes).
  It occupies 652 bytes.
  The `ld` at 0x3c0 loads 8 bytes from abs 0xffffffffffffc400.
  The `ld` at 0x3c4 loads 8 bytes from [-0x3c00]:8 +0x0.
  The `ld` at 0x3dc loads 8 bytes from ([[-0x3c00]:8]:8 + (a1 << 0x3)) +0x0.
  The `lh` at 0x3ec loads 2 bytes from [([[-0x3c00]:8]:8 + (a1 << 0x3))]:8 +0x4956.
  2 such `lh` accesses load 2 bytes from (sym(compact_to_nasid_node) + (a1 + a1)) +0x0, including `lh` at 0x404, `lh` at 0x4d8.
  2 such `ld` accesses load 8 bytes from ([(sym(compact_to_nasid_node) + (a1 + a1))]:2 << 0x20) -0x6dfffffffe5fffe8, including `ld` at 0x41c, `ld` at 0x448.
  The `sd` at 0x460 stores 8 bytes to ([(sym(compact_to_nasid_node) + (a1 + a1))]:2 << 0x20) -0x6dfffffffe5fffe8.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0x540, `lw` at 0x558.
  2 such `sd` accesses store 8 bytes to ?, including `sd` at 0x580, `sd` at 0x5bc.
  The `sd` at 0x5d4 stores 8 bytes to ([(sym(compact_to_nasid_node) + (a1 + a1))]:2 << 0x20) -0x6dfffffffe800000.
  The `sd` at 0x5d8 stores 8 bytes to ([(sym(compact_to_nasid_node) + (a1 + a1))]:2 << 0x20) -0x6dfffffffe7ffff0.
  The `sd` at 0x5dc stores 8 bytes to ([(sym(compact_to_nasid_node) + (a1 + a1))]:2 << 0x20) -0x6dfffffffe7fff18.
  The `sd` at 0x5e0 stores 8 bytes to ([(sym(compact_to_nasid_node) + (a1 + a1))]:2 << 0x20) -0x6dfffffffe600000.
  The `sd` at 0x5e8 stores 8 bytes to ([(sym(compact_to_nasid_node) + (a1 + a1))]:2 << 0x20) -0x6dfffffffe5ffff0.
  The `jal` at 0x3e8 calls setmustrun with a0=[[([[-0x3c00]:8]:8 + (a1 << 0x3))]:8+18774]:2, a1=(a1 << 0x3), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x4b8 calls slot_getsize with a0=a1 at entry (arg1), a1=?, a2=?, a3=?.
  The `jal` at 0x5f0 calls vsema with a0=sym(.bss), a1=?, a2=?, a3=?, a6=([(sym(compact_to_nasid_node) + (a1 + a1))]:2 << 0x20)+0x9200000001a00000, a7=a2 at entry (arg2).
  The `beq` branch at 0x43c targets 0x628, is taken when 0 >= a1(?) (unsigned), and falls through when 0 < a1(?) (unsigned).
  The `beq` branch at 0x4a0 targets 0x4b4 and is always taken.
  The `bltz` branch at 0x4ac targets 0x5c0, is taken when a1(?) < 0 (signed), and falls through when a1(?) >= 0 (signed).
  The `beq` branch at 0x4c8 targets 0x4a8, is taken when v0(=ret(slot_getsize)) == 0, and falls through when v0(=ret(slot_getsize)) != 0.
  The `bne` branch at 0x4fc targets 0x638, is taken when t2(?) < t8(?) (unsigned), and falls through when t2(?) >= t8(?) (unsigned).
  The `beq` branch at 0x504 targets 0x4a8 and is always taken.
  The `beq` branch at 0x514 targets 0x4a8, is taken when t2(?) >= t8(?) (unsigned), and falls through when t2(?) < t8(?) (unsigned).
  The `bne` branch at 0x538 targets 0x544, is taken when ra(?) < 0x4000 (unsigned), and falls through when ra(?) >= 0x4000 (unsigned).
  The `bne` branch at 0x548 targets 0x564, is taken when a6(?) != 0, and falls through when a6(?) == 0.
  The `bne` branch at 0x550 targets 0x55c, is taken when a7(?) != 0, and falls through when a7(?) == 0.
  The `beq` branch at 0x55c targets 0x524, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `beq` branch at 0x564 targets 0x50c, is taken when a0(=one of 0x10, 0x40) == 0, and falls through when a0(=one of 0x10, 0x40) != 0.
  The `beq` branch at 0x578 targets 0x588 and is always taken.
  The `bne` branch at 0x584 targets 0x50c, is taken when a6(?) != 0, and falls through when a6(?) == 0.
  The `bne` branch at 0x5b0 targets 0x580, is taken when (s1(=a0) & t1(?)) != 0, and falls through when (s1(=a0) & t1(?)) == 0.
  The `beq` branch at 0x5b8 targets 0x584 and is always taken.
  The `beq` branch at 0x5e4 targets 0x5f8, is taken when a7(=a2) == 0, and falls through when a7(=a2) != 0.
  The `beq` branch at 0x630 targets 0x464 and is always taken.
  The `beq` branch at 0x638 targets 0x520 and is always taken.
  The return at 0x620 has v0 = one of ?, ret(vsema).

- `part_permit_xppage` in `IP27/usr/cpu/sysgen/IP27boot/partition.o` at 0x640 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/partition.o`.
  Range: 0x640-0x77c (316 bytes).
  It occupies 316 bytes.
  The `ld` at 0x680 loads 8 bytes from a0 (arg0 at entry) +0x30.
  The `ld` at 0x684 loads 8 bytes from a0 (arg0 at entry) +0x50.
  The `ld` at 0x688 loads 8 bytes from a0 (arg0 at entry) +0x38.
  The `sd` at 0x6ac stores 8 bytes to a0 (arg0 at entry) +0x50.
  2 such `lh` accesses load 2 bytes from abs 0xffffffffffffc420, including `lh` at 0x6b8, `lh` at 0x6f0.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x5c, including `lw` at 0x6bc, `lw` at 0x6f4.
  2 such `sh` accesses store 2 bytes to a0 (arg0 at entry) +0x42, including `sh` at 0x6c0, `sh` at 0x700.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x5c, including `sw` at 0x6cc, `sw` at 0x70c.
  The `ll` at 0x760 loads 4 bytes from a0 (arg0 at entry) +0x5c.
  The `sc` at 0x768 stores 4 bytes to a0 (arg0 at entry) +0x5c.
  The `jal` at 0x678 calls bitlock_acquire_32bit with a0=a0+92, a1=0x1, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x6b0 calls splerr with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x6d8 calls part_pfdat_depermit with a0=?, a1=[a0+80]:8, a2=?, a3=?.
  The `jal` at 0x708 calls splx with a0=ret(splerr), a1=?, a2=?, a3=?.
  The `jal` at 0x720 calls part_pfdat_permit with a0=?, a1=[a0+80]:8, a2=?, a3=?.
  The `beq` branch at 0x6a8 targets 0x718, is taken when (s7(=a2) & s3(=[a0+80]:8)) == 0, and falls through when (s7(=a2) & s3(=[a0+80]:8)) != 0.
  The `bne` branch at 0x6e8 targets 0x6d4, is taken when s0(?) < s1(?) (unsigned), and falls through when s0(?) >= s1(?) (unsigned).
  The `beq` branch at 0x710 targets 0x73c and is always taken.
  The `bne` branch at 0x730 targets 0x71c, is taken when s0(?) < s1(?) (unsigned), and falls through when s0(?) >= s1(?) (unsigned).
  The `beql` branch at 0x76c targets 0x760, is taken when (a1(=[a0+92]) & a3(=-0x2)) == 0, and falls through when (a1(=[a0+92]) & a3(=-0x2)) != 0; its branch-likely delay slot `nop` at 0x770 runs only when taken and is annulled on fall-through.
  The return at 0x774 has v0 = ?.

- `part_permit_page` in `IP27/usr/cpu/sysgen/IP27boot/partition.o` at 0x77c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/partition.o`.
  Range: 0x77c-0x844 (200 bytes).
  It occupies 200 bytes.
  2 such `ld` accesses load 8 bytes from ret(part_get) +0x18, including `ld` at 0x7f8, `ld` at 0x828.
  The `jal` at 0x790 calls part_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x7d0 calls part_find_page with a0=?, a1=?, a2=0x3fc0000, a3=0xfffffffffe800000.
  The `jal` at 0x7fc calls part_permit_xppage with a0=ret(part_find_page), a1=?, a2=?, a3=?.
  The `jal` at 0x804 calls part_release_page with a0=ret(part_find_page), a1=?, a2=?, a3=?.
  The `jal` at 0x830 calls cmn_err with a0=0x0, a1=sym(.rodata), a2=a2 at entry (arg2), a3=0x1.
  The `beq` branch at 0x79c targets 0x80c, is taken when v0(=ret(part_get)) == 0, and falls through when v0(=ret(part_get)) != 0.
  The `beq` branch at 0x7e8 targets 0x824, is taken when s0(=a2) == a3(=0x1), and falls through when s0(=a2) != a3(=0x1).
  The `bne` branch at 0x7f0 targets 0x82c, is taken when s0(=a2) != a0(=0x2), and falls through when s0(=a2) == a0(=0x2).
  The `beq` branch at 0x824 targets 0x7fc and is always taken.
  The `beq` branch at 0x83c targets 0x7fc and is always taken.
  The return at 0x81c has v0 = one of ret(part_get), ret(part_release_page).

- `part_pfdat_permit` in `IP27/usr/cpu/sysgen/IP27boot/partition.o` at 0x844 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/partition.o`.
  Range: 0x844-0x968 (292 bytes).
  It occupies 292 bytes.
  The `ld` at 0x89c loads 8 bytes from table(0x9200000001a00018) +0x0.
  2 such `sd` accesses store 8 bytes to ?, including `sd` at 0x900, `sd` at 0x944.
  The `beq` branch at 0x8ac targets 0x948, is taken when t3(?) >= s0(?) (unsigned), and falls through when t3(?) < s0(?) (unsigned).
  The `beq` branch at 0x8cc targets 0x8d8 and is always taken.
  The `beq` branch at 0x8d4 targets 0x948, is taken when t8(?) == 0, and falls through when t8(?) != 0.
  The `beq` branch at 0x8f8 targets 0x958 and is always taken.
  The `beq` branch at 0x914 targets 0x8d4, is taken when a1(?) >= 0x40 (unsigned), and falls through when a1(?) < 0x40 (unsigned).
  The `beq` branch at 0x928 targets 0x904, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `bne` branch at 0x938 targets 0x900, is taken when a3(?) != 0, and falls through when a3(?) == 0.
  The `beq` branch at 0x940 targets 0x904 and is always taken.
  The `beq` branch at 0x960 targets 0x920 and is always taken.
  The return at 0x950 has v0 = ?.

- `part_pfdat_depermit` in `IP27/usr/cpu/sysgen/IP27boot/partition.o` at 0x968 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/partition.o`.
  Range: 0x968-0xbf8 (656 bytes).
  It occupies 656 bytes.
  2 such `ld` accesses load 8 bytes from abs 0xffffffffffffc020, including `ld` at 0x9a4, `ld` at 0xaa8.
  The `lw` at 0x9c4 loads 4 bytes from a0 (arg0 at entry) +0x10.
  The `ld` at 0xb24 loads 8 bytes from table(sym(.rodata)) +0x0.
  The `jal` at 0xa08 calls __cache_hwb_inval_pfn with a0=0x0, a1=0x4000, a2=?, a3=?.
  The `jal` at 0xa2c calls badaddr_val with a0=?, a1=0x4, a2=sp-136, a3=?.
  The `jal` at 0xa50 calls part_pfdat_permit with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=?.
  The `jal` at 0xa60 calls __cache_hwb_inval_pfn with a0=0x0, a1=0x4000, a2=?, a3=?.
  The `jal` at 0xa78 calls badaddr_val with a0=?, a1=0x4, a2=sp-136, a3=?.
  The `jal` at 0xaf8 calls get_dir_ent with a0=?, a1=sp-132, a2=sp-128, a3=sp-120.
  The `jal` at 0xbc0 calls rt_unpin_thread with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xbd0 calls rt_pin_thread with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xbe8 calls cmn_err with a0=0x0, a1=sym(.rodata), a2=?, a3=?.
  The `beq` branch at 0x99c targets 0x9ac, is taken when (a1 & s5(?)) == 0, and falls through when (a1 & s5(?)) != 0.
  The `bne` branch at 0x9a8 targets 0xbd0, is taken when ra(=[-0x3fe0]:8) != 0, and falls through when ra(=[-0x3fe0]:8) == 0.
  The `beq` branch at 0xa14 targets 0xa44, is taken when s1(?) >= s3(?) (unsigned), and falls through when s1(?) < s3(?) (unsigned).
  The `beq` branch at 0xa3c targets 0xa28, is taken when s2(?) >= s0(?) (unsigned), and falls through when s2(?) < s0(?) (unsigned).
  The `beq` branch at 0xa68 targets 0xa98, is taken when s8(?) == 0, and falls through when s8(?) != 0.
  The `bne` branch at 0xa88 targets 0xa74, is taken when s0(?) < s3(?) (unsigned), and falls through when s0(?) >= s3(?) (unsigned).
  The `beq` branch at 0xa90 targets 0xadc and is always taken.
  The `beq` branch at 0xaa0 targets 0xab0, is taken when s5(?) == 0, and falls through when s5(?) != 0.
  The `bne` branch at 0xaac targets 0xbc0, is taken when ra(=[-0x3fe0]:8) != 0, and falls through when ra(=[-0x3fe0]:8) == 0.
  The `beq` branch at 0xadc targets 0xaec and is always taken.
  The `beq` branch at 0xae8 targets 0xacc and is never taken: its condition can never hold for these operands, so execution always falls through.
  The `beq` branch at 0xb1c targets 0xbe0, is taken when a2(?) >= 0x8 (unsigned), and falls through when a2(?) < 0x8 (unsigned).
  The `beq` branch at 0xbc8 targets 0xab4 and is always taken.
  The `beq` branch at 0xbd8 targets 0x9ac and is always taken.
  The `beq` branch at 0xbf0 targets 0xae8 and is always taken.
  The return at 0xac4 has v0 = one of ret(__cache_hwb_inval_pfn), ret(rt_unpin_thread).
  The instructions from 0xacc to 0xad8 are not reached by any path from the entry, and their branches are not listed.
  The instructions from 0xae4 to 0xae4 are not reached by any path from the entry, and their branches are not listed.
  The instructions from 0xb30 to 0xbbc are not reached by any path from the entry, and their branches are not listed.
  The indirect jump at 0xb28 uses a jump table whose successors are unresolved.

- `part_pfdat_flags` in `IP27/usr/cpu/sysgen/IP27boot/partition.o` at 0xbf8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/partition.o`.
  Range: 0xbf8-0xd1c (292 bytes).
  It occupies 292 bytes.
  The `jal` at 0xc60 calls splhi with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xc74 calls bitlock_set with a0=?, a1=0x8000000, a2=a2 at entry (arg2), a3=?.
  The `jal` at 0xc7c calls splx with a0=ret(splhi), a1=?, a2=?, a3=?.
  The `jal` at 0xcbc calls splhi with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xcd0 calls bitlock_clr with a0=?, a1=0x8000000, a2=a3 at entry (arg3), a3=?.
  The `jal` at 0xcd8 calls splx with a0=ret(splhi), a1=?, a2=?, a3=?.
  The `beq` branch at 0xc40 targets 0xc94, is taken when a2 == 0, and falls through when a2 != 0.
  The `beq` branch at 0xc58 targets 0xc94, is taken when a0 >= s3(?) (unsigned), and falls through when a0 < s3(?) (unsigned).
  The `beq` branch at 0xc8c targets 0xc60, is taken when s3(?) >= s1(?) (unsigned), and falls through when s3(?) < s1(?) (unsigned).
  The `beq` branch at 0xc94 targets 0xcf0, is taken when s5(=a3) == 0, and falls through when s5(=a3) != 0.
  The `beq` branch at 0xcac targets 0xcf0, is taken when s2(=a0) >= s3(?) (unsigned), and falls through when s2(=a0) < s3(?) (unsigned).
  The `beq` branch at 0xce8 targets 0xcbc, is taken when s3(?) >= s2(?) (unsigned), and falls through when s3(?) < s2(?) (unsigned).
  The return at 0xd14 has v0 = one of ?, ret(splx).

- `part_page_allocate_node` in `IP27/usr/cpu/sysgen/IP27boot/partition.o` at 0xd1c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/partition.o`.
  Range: 0xd1c-0xdbc (160 bytes).
  It occupies 160 bytes.
  The `ld` at 0xda8 loads 8 bytes from ret(part_get) +0x18.
  The `jal` at 0xd40 calls pagealloc_size_node with a0=a0 at entry (arg0), a1=a3 at entry (arg3), a2=a4 at entry (arg4), a3=a5 at entry (arg5).
  The `jal` at 0xd78 calls part_new_page with a0=ret(pagealloc_size_node), a1=0x0, a2=a5 at entry (arg5), a3=0x0, a4=a6 at entry (arg6).
  The `jal` at 0xd90 calls part_pfdat_flags with a0=ret(pagealloc_size_node), a1=a5 at entry (arg5), a2=0x4000000, a3=0x0.
  The `jal` at 0xd9c calls part_get with a0=a1 at entry (arg1), a1=?, a2=?, a3=?.
  The `jal` at 0xdac calls part_permit_xppage with a0=ret(part_new_page), a1=[ret(part_get)+24]:8, a2=0x0, a3=?.
  The `bne` branch at 0xd48 targets 0xd68, is taken when v0(=ret(pagealloc_size_node)) != 0, and falls through when v0(=ret(pagealloc_size_node)) == 0.
  The `beq` branch at 0xdb4 targets 0xd54 and is always taken.
  The return at 0xd60 has v0 = ret(pagealloc_size_node).

- `part_page_allocate` in `IP27/usr/cpu/sysgen/IP27boot/partition.o` at 0xdbc (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/partition.o`.
  Range: 0xdbc-0xe68 (172 bytes).
  It occupies 172 bytes.
  The `ld` at 0xe30 loads 8 bytes from ret(part_get) +0x18.
  The `jal` at 0xde0 calls pagealloc_size with a0=a2 at entry (arg2), a1=a3 at entry (arg3), a2=a4 at entry (arg4), a3=a3 at entry (arg3).
  The `jal` at 0xe00 calls part_new_page with a0=ret(pagealloc_size), a1=0x0, a2=a4 at entry (arg4), a3=0x0, a4=a5 at entry (arg5).
  The `jal` at 0xe1c calls part_pfdat_flags with a0=ret(pagealloc_size), a1=a4 at entry (arg4), a2=0x4000000, a3=0x0.
  The `jal` at 0xe24 calls part_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xe34 calls part_permit_xppage with a0=ret(part_new_page), a1=[ret(part_get)+24]:8, a2=0x0, a3=?.
  The `jal` at 0xe58 calls pagefree_size with a0=ret(pagealloc_size), a1=a4 at entry (arg4), a2=?, a3=?.
  The `beq` branch at 0xde8 targets 0xe3c, is taken when v0(=ret(pagealloc_size)) == 0, and falls through when v0(=ret(pagealloc_size)) != 0.
  The `beq` branch at 0xe08 targets 0xe54, is taken when v0(=ret(part_new_page)) == 0, and falls through when v0(=ret(part_new_page)) != 0.
  The `beq` branch at 0xe60 targets 0xe3c and is always taken.
  The return at 0xe4c has v0 = one of ret(pagealloc_size), 0x0.

- `part_page_free` in `IP27/usr/cpu/sysgen/IP27boot/partition.o` at 0xe68 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/partition.o`.
  Range: 0xe68-0xffc (404 bytes).
  It occupies 404 bytes.
  The `ld` at 0xebc loads 8 bytes from ret(part_get) +0x18.
  The `ld` at 0xed4 loads 8 bytes from ret(part_find_page) +0x30.
  3 such `ld` accesses load 8 bytes from ret(part_find_page) +0x38, including `ld` at 0xed8, `ld` at 0xf08, `ld` at 0xf1c.
  2 such `lw` accesses load 4 bytes from [ret(part_find_page)+56]:8 +0x10, including `lw` at 0xf20, `lw` at 0xf30.
  The `jal` at 0xe74 calls part_id with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xe80 calls part_get with a0=ret(part_id), a1=?, a2=?, a3=?.
  The `jal` at 0xeb4 calls part_find_page with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xecc calls part_permit_xppage with a0=ret(part_find_page), a1=[ret(part_get)+24]:8, a2=?, a3=?.
  The `jal` at 0xf88 calls get_dir_ent with a0=?, a1=sp-80, a2=sp-72, a3=sp-64.
  The `jal` at 0xfcc calls part_release_page with a0=ret(part_find_page), a1=?, a2=?, a3=?.
  The `jal` at 0xfd4 calls part_release_page with a0=ret(part_find_page), a1=?, a2=?, a3=?.
  The `jal` at 0xfec calls set_dir_state with a0=?, a1=0x7, a2=?, a3=?.
  The `beq` branch at 0xef8 targets 0xfbc, is taken when s0(=[ret(part_find_page)+56]:8) >= s3(?) (unsigned), and falls through when s0(=[ret(part_find_page)+56]:8) < s3(?) (unsigned).
  The `beq` branch at 0xf04 targets 0xf20 and is always taken.
  The `bne` branch at 0xf14 targets 0xfbc, is taken when s3(?) < s0(?) (unsigned), and falls through when s3(?) >= s0(?) (unsigned).
  The `bne` branch at 0xf28 targets 0xf0c, is taken when (s2(=0x400000) & t9(=[[ret(part_find_page)+56]:8+16])) != 0, and falls through when (s2(=0x400000) & t9(=[[ret(part_find_page)+56]:8+16])) == 0.
  The `bne` branch at 0xf38 targets 0xf0c, is taken when (a0(=0x1000000) & ra(=[[ret(part_find_page)+56]:8+16])) != 0, and falls through when (a0(=0x1000000) & ra(=[[ret(part_find_page)+56]:8+16])) == 0.
  The `beq` branch at 0xf74 targets 0xf0c, is taken when s4(?) >= at(?) (unsigned), and falls through when s4(?) < at(?) (unsigned).
  The `beq` branch at 0xf98 targets 0xfec, is taken when at(?) == v0(=0x1), and falls through when at(?) != v0(=0x1).
  The `bne` branch at 0xfac targets 0xf80, is taken when s4(?) < v1(?) (unsigned), and falls through when s4(?) >= v1(?) (unsigned).
  The `beq` branch at 0xfb4 targets 0xf0c and is always taken.
  The `beq` branch at 0xff4 targets 0xfa4 and is always taken.
  The return at 0xfe4 has v0 = ret(part_release_page).

- `part_interrupt_thread_exit` in `IP27/usr/cpu/sysgen/IP27boot/partition.o` at 0xffc (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/partition.o`.
  Range: 0xffc-0x108c (144 bytes).
  It occupies 144 bytes.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x20, including `ld` at 0xffc, `ld` at 0x1018.
  The `ll` at 0x1024 loads 4 bytes from [a0+32]:8 +0x7c.
  The `sc` at 0x1030 stores 4 bytes to [a0+32]:8 +0x7c.
  The `lw` at 0x103c loads 4 bytes from a0 (arg0 at entry) +0x18.
  The `ll` at 0x1054 loads 4 bytes from [a0+32]:8 +0x6c.
  The `sc` at 0x1060 stores 4 bytes to [a0+32]:8 +0x6c.
  The `jal` at 0x1010 calls part_dequeue_xthread with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1070 calls kmem_free with a0=a0 at entry (arg0), a1=0x28, a2=?, a3=?.
  The `jal` at 0x1078 calls xthread_exit with a0=?, a1=?, a2=?, a3=?.
  The `beql` branch at 0x1034 targets 0x1024, is taken when a2(=[[a0+32]:8+124]+1) == 0, and falls through when a2(=[[a0+32]:8+124]+1) != 0; its branch-likely delay slot `nop` at 0x1038 runs only when taken and is annulled on fall-through.
  The `bne` branch at 0x1044 targets 0x106c, is taken when (v0(=[a0+24]) & 0x2) != 0, and falls through when (v0(=[a0+24]) & 0x2) == 0.
  The `beql` branch at 0x1064 targets 0x1054, is taken when a4(=[[a0+32]:8+108]-1) == 0, and falls through when a4(=[[a0+32]:8+108]-1) != 0; its branch-likely delay slot `nop` at 0x1068 runs only when taken and is annulled on fall-through.
  The return at 0x1084 has v0 = ret(xthread_exit).

- `part_activate` in `IP27/usr/cpu/sysgen/IP27boot/partition.o` at 0x108c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/partition.o`.
  Range: 0x108c-0x1450 (964 bytes).
  It occupies 964 bytes.
  3 such `lw` accesses load 4 bytes from ret(part_get) +0x20, including `lw` at 0x10b8, `lw` at 0x11a0, `lw` at 0x136c.
  3 such `sw` accesses store 4 bytes to ret(part_get) +0xc, including `sw` at 0x10bc, `sw` at 0x11b0, `sw` at 0x1378.
  The `sd` at 0x10d4 stores 8 bytes to ret(part_get) +0x38.
  The `sd` at 0x10d8 stores 8 bytes to ret(part_get) +0x30.
  2 such `sw` accesses store 4 bytes to ret(part_get) +0x20, including `sw` at 0x10e4, `sw` at 0x13c0.
  12 such `lb` accesses load 1 byte from ret(part_get) +0x14, including `lb` at 0x10f0, `lb` at 0x1140, `lb` at 0x1168.
  The `lb` at 0x1104 loads 1 byte from ?.
  2 such `ld` accesses load 8 bytes from ret(part_get) +0x28, including `ld` at 0x1128, `ld` at 0x1238.
  The `ld` at 0x114c loads 8 bytes from [sym(.sdata)+32]:8 +0x28.
  The `sd` at 0x1160 stores 8 bytes to [sym(.sdata)+32]:8 +0x28.
  7 such `lw` accesses load 4 bytes from ret(part_get) +0xc, including `lw` at 0x118c, `lw` at 0x12d0, `lw` at 0x1320.
  2 such `lw` accesses load 4 bytes from ret(part_get_nasid) +0x4, including `lw` at 0x1264, `lw` at 0x13e4.
  The `lh` at 0x1288 loads 2 bytes from ret(part_get_nasid) +0x0.
  The `sd` at 0x12a0 stores 8 bytes to (([ret(part_get_nasid)]:2 << 0x20) + one of 0x92000000018000c8, 0x92000000018000d0) +0x0.
  The `sd` at 0x12c4 stores 8 bytes to ret(part_get) +0x28.
  The `jal` at 0x10a0 calls part_get with a0=?, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x10b0 calls mutex_spinlock with a0=ret(part_get)+8, a1=?, a2=?, a3=?.
  The `jal` at 0x1134 calls mutex_spinlock with a0=sym(.sbss)+12, a1=?, a2=?, a3=?.
  The `jal` at 0x115c calls mutex_spinunlock with a0=sym(.sbss)+12, a1=ret(mutex_spinlock), a2=?, a3=[sym(.sdata)+32]:8.
  The `jal` at 0x1188 calls mutex_spinunlock with a0=ret(part_get)+8, a1=[ret(part_get)+12], a2=[ret(part_get)+20]:1, a3=?.
  The `jal` at 0x1190 calls part_call_activate_handlers with a0=ret(part_get), a1=?, a2=?, a3=?.
  The `jal` at 0x1198 calls mutex_spinlock with a0=ret(part_get)+8, a1=?, a2=?, a3=?.
  The `jal` at 0x11c0 calls mutex_spinunlock with a0=ret(part_get)+8, a1=?, a2=?, a3=?.
  The `jal` at 0x11fc calls part_copy_fault with a0=(table(0x9600000000000000) | 0x2000)+512, a1=sp-384, a2=0x40, a3=?.
  The `jal` at 0x1240 calls mutex_spinunlock with a0=ret(part_get)+8, a1=ret(mutex_spinlock), a2=0x3, a3=?.
  The `jal` at 0x1254 calls part_get_nasid with a0=[ret(part_get)+20]:1, a1=0x0, a2=[ret(part_get)+20]:1, a3=?, a5=[sym(partition_partid)]:1, a6=[sym(.sdata)+16].
  The `jal` at 0x12cc calls mutex_spinunlock with a0=ret(part_get)+8, a1=[ret(part_get)+12], a2=?, a3=?.
  The `jal` at 0x12d4 calls part_deactivate with a0=[ret(part_get)+20]:1, a1=?, a2=?, a3=?.
  The `jal` at 0x12f0 calls part_from_addr with a0=?, a1=0x434d5f53505f5357, a2=?, a3=?.
  The `jal` at 0x131c calls mutex_spinunlock with a0=ret(part_get)+8, a1=[ret(part_get)+12], a2=?, a3=?.
  The `jal` at 0x1324 calls part_deactivate with a0=[ret(part_get)+20]:1, a1=?, a2=?, a3=?.
  The `jal` at 0x1338 calls mutex_spinunlock with a0=ret(part_get)+8, a1=[ret(part_get)+12], a2=?, a3=?.
  The `jal` at 0x1340 calls part_deactivate with a0=[ret(part_get)+20]:1, a1=?, a2=?, a3=?.
  The `jal` at 0x135c calls sv_wait with a0=ret(part_get)+152, a1=0x19, a2=ret(part_get)+8, a3=ret(mutex_spinlock), a7=0x5.
  The `jal` at 0x1364 calls mutex_spinlock with a0=ret(part_get)+8, a1=?, a2=?, a3=?.
  The `jal` at 0x1388 calls part_copy_fault with a0=?, a1=sp-320, a2=0x110, a3=?.
  The `jal` at 0x1398 calls mutex_spinunlock with a0=ret(part_get)+8, a1=[ret(part_get)+12], a2=?, a3=?.
  The `jal` at 0x13a0 calls part_deactivate with a0=[ret(part_get)+20]:1, a1=?, a2=?, a3=?.
  The `jal` at 0x13bc calls cmn_err with a0=0x6, a1=sym(.rodata), a2=[ret(part_get)+20]:1, a3=?.
  The `jal` at 0x13d8 calls assfail with a0=sym(.rodata), a1=sym(.rodata), a2=0x577, a3=?.
  The `jal` at 0x13f0 calls cmn_err with a0=0x4, a1=sym(.rodata), a2=[ret(part_get)+20]:1, a3=?.
  The `jal` at 0x140c calls cmn_err with a0=0x5, a1=sym(.rodata), a2=[ret(part_get)+20]:1, a3=?.
  The `jal` at 0x142c calls cmn_err with a0=0x5, a1=sym(.rodata), a2=0x1, a3=0x0.
  The `jal` at 0x1438 calls mutex_spinunlock with a0=ret(part_get)+8, a1=[ret(part_get)+12], a2=?, a3=?.
  The `jal` at 0x1440 calls part_deactivate with a0=[ret(part_get)+20]:1, a1=?, a2=?, a3=?.
  The `bne` branch at 0x10c8 targets 0x123c, is taken when a1(=[ret(part_get)+32]) != a2(=0x3), and falls through when a1(=[ret(part_get)+32]) == a2(=0x3).
  The `beq` branch at 0x1108 targets 0x11e4, is taken when v1(?) == a2(=[ret(part_get)+20]:1), and falls through when v1(?) != a2(=[ret(part_get)+20]:1).
  The `bne` branch at 0x1120 targets 0x10f8, is taken when s1(?) < 0x100 (signed), and falls through when s1(?) >= 0x100 (signed).
  The `beq` branch at 0x112c targets 0x12cc, is taken when a1(=[ret(part_get)+40]:8) == 0, and falls through when a1(=[ret(part_get)+40]:8) != 0.
  The `bne` branch at 0x116c targets 0x1250, is taken when a5(=[sym(partition_partid)]:1) != a2(=[ret(part_get)+20]:1), and falls through when a5(=[sym(partition_partid)]:1) == a2(=[ret(part_get)+20]:1).
  The `beq` branch at 0x1178 targets 0x1184, is taken when a6(=[sym(.sdata)+16]) >= a2(=[ret(part_get)+20]:1) (unsigned), and falls through when a6(=[sym(.sdata)+16]) < a2(=[ret(part_get)+20]:1) (unsigned).
  The `beq` branch at 0x11ac targets 0x1350, is taken when a0(=[ret(part_get)+32]) == a7(=0x5), and falls through when a0(=[ret(part_get)+32]) != a7(=0x5).
  The `beq` branch at 0x11b8 targets 0x13b0, is taken when a0(=[ret(part_get)+32]) == t0(=0x4), and falls through when a0(=[ret(part_get)+32]) != t0(=0x4).
  The `bne` branch at 0x1204 targets 0x1334, is taken when v0(=ret(part_copy_fault)) != 0, and falls through when v0(=ret(part_copy_fault)) == 0.
  The `beq` branch at 0x1210 targets 0x12e4, is taken when a1(=0x434d5f53505f5357) == a0(?), and falls through when a1(=0x434d5f53505f5357) != a0(?).
  The `bne` branch at 0x122c targets 0x10f0, is taken when s1(?) < 0x100 (signed), and falls through when s1(?) >= 0x100 (signed).
  The `beq` branch at 0x1234 targets 0x112c and is always taken.
  The `beq` branch at 0x1248 targets 0x11cc and is always taken.
  The `beq` branch at 0x125c targets 0x13cc, is taken when v0(=ret(part_get_nasid)) == 0, and falls through when v0(=ret(part_get_nasid)) != 0.
  The `bltz` branch at 0x126c targets 0x137c, is taken when t8(=([ret(part_get_nasid)+4] << 0x8)) < 0 (signed), and falls through when t8(=([ret(part_get_nasid)+4] << 0x8)) >= 0 (signed).
  The `beq` branch at 0x12a4 targets 0x1170 and is always taken.
  The `bne` branch at 0x12b8 targets 0x1400, is taken when a1(?) != a2(=0x1), and falls through when a1(?) == a2(=0x1).
  The `bne` branch at 0x12c0 targets 0x1134, is taken when s1(?) != 0, and falls through when s1(?) == 0.
  The `beq` branch at 0x12dc targets 0x11cc and is always taken.
  The `beq` branch at 0x12e4 targets 0x1218, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x12fc targets 0x1384, is taken when v0(=ret(part_from_addr)) == a2(=[ret(part_get)+20]:1), and falls through when v0(=ret(part_from_addr)) != a2(=[ret(part_get)+20]:1).
  The `bltz` branch at 0x130c targets 0x1318, is taken when a3(?) < 0 (signed), and falls through when a3(?) >= 0 (signed).
  The `bne` branch at 0x1314 targets 0x13e8, is taken when a4(?) != 0, and falls through when a4(?) == 0.
  The `beq` branch at 0x132c targets 0x11cc and is always taken.
  The `beq` branch at 0x1348 targets 0x11cc and is always taken.
  The `beq` branch at 0x1374 targets 0x11b4 and is always taken.
  The `beq` branch at 0x137c targets 0x1280 and is always taken.
  The `beq` branch at 0x1390 targets 0x12ac, is taken when v0(=ret(part_copy_fault)) == 0, and falls through when v0(=ret(part_copy_fault)) != 0.
  The `beq` branch at 0x13a8 targets 0x11cc and is always taken.
  The `beq` branch at 0x13c4 targets 0x11c0 and is always taken.
  The `beq` branch at 0x13e0 targets 0x1268 and is always taken.
  The `beq` branch at 0x13f8 targets 0x131c and is always taken.
  The `beq` branch at 0x1448 targets 0x11cc and is always taken.
  The return at 0x11dc has v0 = one of ret(mutex_spinunlock), ret(part_deactivate).

- `part_deactivate` in `IP27/usr/cpu/sysgen/IP27boot/partition.o` at 0x1450 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/partition.o`.
  Range: 0x1450-0x1574 (292 bytes).
  It occupies 292 bytes.
  The `lw` at 0x1474 loads 4 bytes from ret(part_get) +0x20.
  The `sw` at 0x1484 stores 4 bytes to ret(part_get) +0xc.
  The `ld` at 0x14a4 loads 8 bytes from (sym(.rodata) + ([ret(part_get)+32] << 0x3)) +0x0.
  The `lw` at 0x1570 loads 4 bytes from ret(part_get) +0xc.
  The `jal` at 0x1458 calls part_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x146c calls mutex_spinlock with a0=ret(part_get)+8, a1=?, a2=?, a3=?.
  Calls (unknown callee) via register with a0=ret(part_get)+152, a1=ret(mutex_spinlock), a2=[ret(part_get)+32], a3=?, a5=(sym(.rodata) + ([ret(part_get)+32] << 0x3)), a6=[(sym(.rodata) + ([ret(part_get)+32] << 0x3))]:8 (`jr` at 0x14a8).
  The `jal` at 0x14cc calls mutex_spinunlock with a0=ret(part_get)+8, a1=[ret(part_get)+12], a2=?, a3=?.
  The `jal` at 0x1564 calls cmn_err with a0=0x0, a1=sym(.rodata), a2=[ret(part_get)+32], a3=?, a5=(sym(.rodata) + ([ret(part_get)+32] << 0x3)), a6=([ret(part_get)+32] << 0x3).
  The `beq` branch at 0x1460 targets 0x14d4, is taken when v0(=ret(part_get)) == 0, and falls through when v0(=ret(part_get)) != 0.
  The `beq` branch at 0x149c targets 0x155c, is taken when a6(=[ret(part_get)+32]) >= 0x9 (unsigned), and falls through when a6(=[ret(part_get)+32]) < 0x9 (unsigned).
  The `beq` branch at 0x156c targets 0x14c4 and is always taken.
  The return at 0x14dc has v0 = one of ret(part_get), ret(mutex_spinunlock).
  The instructions from 0x14b0 to 0x14c0 are not reached by any path from the entry, and their branches are not listed.
  The instructions from 0x14e4 to 0x1558 are not reached by any path from the entry, and their branches are not listed.
  The indirect jump at 0x14a8 uses a jump table whose successors are unresolved.

- `part_terminate` in `IP27/usr/cpu/sysgen/IP27boot/partition.o` at 0x1574 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/partition.o`.
  Range: 0x1574-0x1890 (796 bytes).
  It occupies 796 bytes.
  The `ld` at 0x157c loads 8 bytes from a0 (arg0 at entry) +0x20.
  The `lw` at 0x159c loads 4 bytes from [a0+32]:8 +0x20.
  3 such `sw` accesses store 4 bytes to [a0+32]:8 +0xc, including `sw` at 0x15a8, `sw` at 0x17ac, `sw` at 0x17dc.
  2 such `sw` accesses store 4 bytes to [a0+32]:8 +0x20, including `sw` at 0x15c4, `sw` at 0x17f0.
  3 such `lb` accesses load 1 byte from [a0+32]:8 +0x14, including `lb` at 0x15ec, `lb` at 0x16a8, `lb` at 0x1774.
  The `lh` at 0x1644 loads 2 bytes from ?.
  The `ld` at 0x1650 loads 8 bytes from [a0+32]:8 +0x18.
  7 such `ld` accesses load 8 bytes from ?, including `ld` at 0x1654, `ld` at 0x16f8, `ld` at 0x1728.
  5 such `sd` accesses store 8 bytes to ?, including `sd` at 0x1668, `sd` at 0x1714, `sd` at 0x1718.
  The `sd` at 0x1698 stores 8 bytes to [a0+32]:8 +0x18.
  2 such `lb` accesses load 1 byte from ?, including `lb` at 0x16b0, `lb` at 0x1778.
  2 such `sb` accesses store 1 byte to ?, including `sb` at 0x16c4, `sb` at 0x16c8.
  The `lw` at 0x1748 loads 4 bytes from [a0+32]:8 +0xc.
  The `ld` at 0x1760 loads 8 bytes from sym(.bss) +0x8.
  2 such `lw` accesses load 4 bytes from [a0+32]:8 +0x58, including `lw` at 0x17a4, `lw` at 0x17d0.
  2 such `lw` accesses load 4 bytes from [a0+32]:8 +0x5c, including `lw` at 0x17e0, `lw` at 0x187c.
  The `jal` at 0x1594 calls mutex_spinlock with a0=[a0+32]:8+8, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x15b0 calls mutex_spinunlock with a0=[a0+32]:8+8, a1=ret(mutex_spinlock), a2=?, a3=?.
  The `jal` at 0x15b8 calls part_interrupt_thread_exit with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x15d0 calls mutex_spinlock with a0=sym(.sbss)+12, a1=0x8, a2=?, a3=?.
  The `jal` at 0x15e4 calls part_get_var with a0=[sym(partition_partid)]:1, a1=0x3, a2=sp-64, a3=?.
  The `jal` at 0x1608 calls part_set_var with a0=0x3, a1=?, a2=?, a3=?.
  The `jal` at 0x1614 calls mutex_spinunlock with a0=sym(.sbss)+12, a1=ret(mutex_spinlock), a2=?, a3=?.
  The `jal` at 0x161c calls mutex_spinlock with a0=sym(.sbss)+16, a1=?, a2=?, a3=?.
  The `jal` at 0x1684 calls mutex_spinunlock with a0=sym(.sbss)+16, a1=ret(mutex_spinlock), a2=sym(compact_to_nasid_node), a3=?, a6=0x9200000001800000.
  The `jal` at 0x1744 calls mutex_spinunlock with a0=[a0+32]:8+8, a1=[[a0+32]:8+12], a2=?, a3=?, a6=sym(.bss).
  The `jal` at 0x174c calls part_call_deactivate_handlers with a0=[a0+32]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x1758 calls mutex_spinlock_spl with a0=sym(.sbss), a1=sym(splerr), a2=?, a3=?.
  The `jal` at 0x1794 calls mutex_spinunlock with a0=sym(.sbss), a1=?, a2=?, a3=?.
  The `jal` at 0x179c calls mutex_spinlock with a0=[a0+32]:8+8, a1=?, a2=?, a3=?.
  The `jal` at 0x17c0 calls sv_wait with a0=[a0+32]:8+152, a1=0x19, a2=[a0+32]:8+8, a3=ret(mutex_spinlock).
  The `jal` at 0x17c8 calls mutex_spinlock with a0=[a0+32]:8+8, a1=?, a2=?, a3=?.
  The `jal` at 0x17f4 calls mutex_spinunlock with a0=[a0+32]:8+8, a1=ret(mutex_spinlock), a2=?, a3=ret(mutex_spinlock).
  The `jal` at 0x1804 calls part_interrupt_thread_exit with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x1824 calls part_hold_page with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1830 calls mutex_spinunlock with a0=sym(.sbss), a1=[sym(.sbss)+4], a2=?, a3=?.
  The `jalr` at 0x1848 calls (unknown callee) with a0=0x0, a1=?, a2=0xb, a3=?.
  The `jal` at 0x1854 calls mutex_spinlock_spl with a0=sym(.sbss), a1=sym(splerr), a2=?, a3=?.
  The `jal` at 0x1864 calls part_release_page_nolock with a0=?, a1=?, a2=?, a3=?.
  The `beq` branch at 0x15a4 targets 0x15c0, is taken when at(=[[a0+32]:8+32]) == v1(=0x7), and falls through when at(=[[a0+32]:8+32]) != v1(=0x7).
  The `blez` branch at 0x1630 targets 0x1684, is taken when a3(=[sym(maxnodes)]) <= 0 (signed), and falls through when a3(=[sym(maxnodes)]) > 0 (signed).
  The `bne` branch at 0x167c targets 0x1640, is taken when a3(?) < a4(=[sym(maxnodes)]) (signed), and falls through when a3(?) >= a4(=[sym(maxnodes)]) (signed).
  The `bne` branch at 0x16bc targets 0x16cc, is taken when a6(?) != a7(=[[a0+32]:8+20]:1), and falls through when a6(?) == a7(=[[a0+32]:8+20]:1).
  The `bne` branch at 0x16cc targets 0x16a0, is taken when a1(?) != 0, and falls through when a1(?) == 0.
  The `beq` branch at 0x16d4 targets 0x16e4 and is always taken.
  The `beq` branch at 0x16dc targets 0x1744, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `bne` branch at 0x170c targets 0x171c, is taken when a4(?) != s0(=[a0+32]:8), and falls through when a4(?) == s0(=[a0+32]:8).
  The `beq` branch at 0x171c targets 0x1744, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `bne` branch at 0x172c targets 0x16dc, is taken when t0(?) != s0(=[a0+32]:8), and falls through when t0(?) == s0(=[a0+32]:8).
  The `beq` branch at 0x1738 targets 0x16dc and is always taken.
  The `beq` branch at 0x176c targets 0x1794, is taken when t1(=[sym(.bss)+8]:8) == 0, and falls through when t1(=[sym(.bss)+8]:8) != 0.
  The `beq` branch at 0x177c targets 0x1824, is taken when t2(?) == v0(=[[a0+32]:8+20]:1), and falls through when t2(?) != v0(=[[a0+32]:8+20]:1).
  The `bne` branch at 0x1788 targets 0x1778, is taken when t3(?) != 0, and falls through when t3(?) == 0.
  The `beq` branch at 0x17b0 targets 0x187c, is taken when s2(=[[a0+32]:8+88]) == 0, and falls through when s2(=[[a0+32]:8+88]) != 0.
  The `bne` branch at 0x17d8 targets 0x17b8, is taken when t8(=[[a0+32]:8+88]) != 0, and falls through when t8(=[[a0+32]:8+88]) == 0.
  The `bne` branch at 0x17e4 targets 0x17b8, is taken when t9(=[[a0+32]:8+92]) != 0, and falls through when t9(=[[a0+32]:8+92]) == 0.
  The `beq` branch at 0x183c targets 0x1850, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `bne` branch at 0x186c targets 0x1774, is taken when s2(?) != 0, and falls through when s2(?) == 0.
  The `beq` branch at 0x1874 targets 0x1794 and is always taken.
  The `bne` branch at 0x1880 targets 0x17b8, is taken when at(=[[a0+32]:8+92]) != 0, and falls through when at(=[[a0+32]:8+92]) == 0.
  The `beq` branch at 0x1888 targets 0x17ec and is always taken.
  The return at 0x181c has v0 = ret(part_interrupt_thread_exit).
  The instructions from 0x1740 to 0x1740 are not reached by any path from the entry, and their branches are not listed.

- `part_copy_fault` in `IP27/usr/cpu/sysgen/IP27boot/partition.o` at 0x1890 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/partition.o`.
  Range: 0x1890-0x18fc (108 bytes).
  It occupies 108 bytes.
  The `jal` at 0x18bc calls _badaddr_val with a0=?, a1=0x4, a2=?, a3=?.
  The `beq` branch at 0x18ac targets 0x18f4, is taken when s2(=a2-4) == 0, and falls through when s2(=a2-4) != 0.
  The `beq` branch at 0x18c4 targets 0x18e4, is taken when v0(=ret(_badaddr_val)) == 0, and falls through when v0(=ret(_badaddr_val)) != 0.
  The `bne` branch at 0x18ec targets 0x18b4, is taken when s2(?) != 0, and falls through when s2(?) == 0.
  The `beq` branch at 0x18f4 targets 0x18cc and is always taken.
  The return at 0x18dc has v0 = one of -0x1, 0x0.

- `part_probe_nasid` in `IP27/usr/cpu/sysgen/IP27boot/partition.o` at 0x18fc (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/partition.o`.
  Range: 0x18fc-0x1c10 (788 bytes).
  It occupies 788 bytes.
  4 such `lb` accesses load 1 byte from table(sym(.bss)) +0x3506, including `lb` at 0x1964, `lb` at 0x1a1c, `lb` at 0x1b5c.
  4 such `sh` accesses store 2 bytes to table(sym(.bss)) +0x3500, including `sh` at 0x1974, `sh` at 0x199c, `sh` at 0x1a44.
  6 such `sb` accesses store 1 byte to table(sym(.bss)) +0x3504, including `sb` at 0x19a4, `sb` at 0x19cc, `sb` at 0x19f0.
  2 such `lbu` accesses load 1 byte from table(sym(.bss)) +0x3504, including `lbu` at 0x1a38, `lbu` at 0x1ac4.
  The `sh` at 0x1a4c stores 2 bytes to table(sym(.bss)) +0x350e.
  The `sh` at 0x1a54 stores 2 bytes to table(sym(.bss)) +0x350a.
  The `sb` at 0x1a5c stores 1 byte to table(sym(.bss)) +0x3506.
  The `lw` at 0x1a6c loads 4 bytes from table(sym(.bss)) +0x3504.
  The `sh` at 0x1a7c stores 2 bytes to table(sym(.bss)) +0x3508.
  The `sh` at 0x1a90 stores 2 bytes to table(sym(.bss)) +0x350c.
  The `sw` at 0x1ab8 stores 4 bytes to table(sym(.bss)) +0x3504.
  The `sb` at 0x1ac0 stores 1 byte to table(sym(.bss)) +0x3507.
  The `ld` at 0x1b08 loads 8 bytes from ?.
  The `sd` at 0x1b14 stores 8 bytes to table(sym(.bss)) +0x5108.
  The `sd` at 0x1b1c stores 8 bytes to ?.
  The `lw` at 0x1b2c loads 4 bytes from ?.
  2 such `sw` accesses store 4 bytes to ?, including `sw` at 0x1b40, `sw` at 0x1b94.
  The `sb` at 0x1c00 stores 1 byte to ?.
  The `sb` at 0x1c0c stores 1 byte to table(sym(.bss)) +0x115.
  The `jal` at 0x193c calls part_copy_fault with a0=((a0 << 0x20)+0x9600000000000000 | 0x2000)+576, a1=sp-144, a2=0x40, a3=one of 0x0, 0x3, a4=[sym(.sbss)+8], a5=0x9600000000000000.
  The `jal` at 0x19b8 calls part_copy_fault with a0=?, a1=sp-80, a2=0x10, a3=?.
  The `jal` at 0x1a2c calls part_deactivate with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1b24 calls mutex_spinlock with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1b44 calls mutex_spinunlock with a0=?, a1=ret(mutex_spinlock), a2=0x1, a3=?.
  The `jal` at 0x1b98 calls part_deactivate with a0=[table(sym(.bss))+13574]:1, a1=table(sym(.bss)), a2=?, a3=?.
  The `jal` at 0x1bb0 calls cmn_err with a0=0x4, a1=sym(.rodata), a2=a0 at entry (arg0), a3=[table(sym(.bss))+13574]:1.
  The `jal` at 0x1bc0 calls is_specified with a0=sym(arg_clusterid), a1=?, a2=?, a3=[table(sym(.bss))+13572]:1, a5=[sym(cell_enabled)].
  The `jal` at 0x1bf0 calls atoi with a0=sym(arg_clusterid), a1=table(sym(.bss))+256, a2=table(sym(.bss)), a3=?.
  The `beq` branch at 0x195c targets 0x1990, is taken when v0(=ret(part_copy_fault)) == 0, and falls through when v0(=ret(part_copy_fault)) != 0.
  The `bne` branch at 0x196c targets 0x1b98, is taken when a0(=[table(sym(.bss))+13574]:1) != s2(=-0x1), and falls through when a0(=[table(sym(.bss))+13574]:1) == s2(=-0x1).
  The `beq` branch at 0x1998 targets 0x19a8, is taken when (v0(?) & 0x7) == 0, and falls through when (v0(?) & 0x7) != 0.
  The `beq` branch at 0x19a0 targets 0x1978 and is always taken.
  The `beq` branch at 0x19c0 targets 0x19d0, is taken when v0(=ret(part_copy_fault)) == 0, and falls through when v0(=ret(part_copy_fault)) != 0.
  The `beq` branch at 0x19c8 targets 0x1978 and is always taken.
  The `bne` branch at 0x19d4 targets 0x1b54, is taken when a1(?) != a2(=0x434d5f53505f5357), and falls through when a1(?) == a2(=0x434d5f53505f5357).
  The `beq` branch at 0x19e4 targets 0x19f4, is taken when a0(=0x1) == a3(?), and falls through when a0(=0x1) != a3(?).
  The `beq` branch at 0x19ec targets 0x1978 and is always taken.
  The `blez` branch at 0x19f4 targets 0x1b7c, is taken when v0(?) <= 0 (signed), and falls through when v0(?) > 0 (signed).
  The `beq` branch at 0x19fc targets 0x1b7c, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `bltz` branch at 0x1a0c targets 0x1a1c, is taken when a0(?) < 0 (signed), and falls through when a0(?) >= 0 (signed).
  The `bne` branch at 0x1a14 targets 0x1b5c, is taken when a1(?) != 0, and falls through when a1(?) == 0.
  The `beq` branch at 0x1a24 targets 0x1b84, is taken when a2(=[table(sym(.bss))+13574]:1) == a0(=-0x1), and falls through when a2(=[table(sym(.bss))+13574]:1) != a0(=-0x1).
  The `beq` branch at 0x1a3c targets 0x197c, is taken when a3(=[table(sym(.bss))+13572]:1) == v0(?), and falls through when a3(=[table(sym(.bss))+13572]:1) != v0(?).
  The `bne` branch at 0x1abc targets 0x1bc0, is taken when a5(=[sym(cell_enabled)]) != 0, and falls through when a5(=[sym(cell_enabled)]) == 0.
  The `bne` branch at 0x1acc targets 0x1978, is taken when t3(=[table(sym(.bss))+13572]:1) != t8(=0x4), and falls through when t3(=[table(sym(.bss))+13572]:1) == t8(=0x4).
  The `beq` branch at 0x1b3c targets 0x1b8c, is taken when v1(?) == a2(=0x1), and falls through when v1(?) != a2(=0x1).
  The `beq` branch at 0x1b4c targets 0x197c and is always taken.
  The `beq` branch at 0x1b54 targets 0x1978 and is always taken.
  The `beq` branch at 0x1b64 targets 0x1a38, is taken when a1(=[table(sym(.bss))+13574]:1) == a3(=-0x1), and falls through when a1(=[table(sym(.bss))+13574]:1) != a3(=-0x1).
  The `beq` branch at 0x1b6c targets 0x1a38, is taken when a1(=[table(sym(.bss))+13574]:1) == a0(?), and falls through when a1(=[table(sym(.bss))+13574]:1) != a0(?).
  The `beq` branch at 0x1b74 targets 0x1a2c and is always taken.
  The `beq` branch at 0x1b7c targets 0x1978 and is always taken.
  The `beq` branch at 0x1b84 targets 0x1a38 and is always taken.
  The `beq` branch at 0x1b90 targets 0x1b44 and is always taken.
  The `beq` branch at 0x1bb8 targets 0x1978 and is always taken.
  The `beq` branch at 0x1be8 targets 0x1c04, is taken when v0(=ret(is_specified)) == 0, and falls through when v0(=ret(is_specified)) != 0.
  The `beq` branch at 0x1bfc targets 0x1ac4 and is always taken.
  The `beq` branch at 0x1c08 targets 0x1ac4 and is always taken.
  The return at 0x1988 has v0 = one of ?, ret(mutex_spinunlock).

- `part_discovery` in `IP27/usr/cpu/sysgen/IP27boot/partition.o` at 0x1c10 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/partition.o`.
  Range: 0x1c10-0x1da4 (404 bytes).
  It occupies 404 bytes.
  The `lw` at 0x1d08 loads 4 bytes from ?.
  2 such `sw` accesses store 4 bytes to ?, including `sw` at 0x1d18, `sw` at 0x1d30.
  The `lh` at 0x1d80 loads 2 bytes from abs 0xffffffffffffc420.
  The `ld` at 0x1d90 loads 8 bytes from (sym(pdaindr) + ([-0x3be0]:2 << 0x4)) +0x8.
  The `lh` at 0x1d98 loads 2 bytes from [(sym(pdaindr) + ([-0x3be0]:2 << 0x4))+8]:8 +0x424.
  The `jal` at 0x1c2c calls cpsema with a0=sym(.bss), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1c3c calls cpsema with a0=sym(.bss), a1=?, a2=?, a3=?.
  The `jal` at 0x1c58 calls vector_read with a0=0x0, a1=0x0, a2=0x600000, a3=sp-48.
  The `jal` at 0x1c7c calls part_probe_nasid with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1cc0 calls mutex_spinunlock with a0=?, a1=ret(mutex_spinlock), a2=?, a3=?.
  The `jal` at 0x1d00 calls mutex_spinlock with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1d38 calls mutex_spinunlock with a0=?, a1=ret(mutex_spinlock), a2=?, a3=?.
  The `jal` at 0x1d4c calls part_interrupt_set with a0=?, a1=0x2, a2=sym(part_activate), a3=?.
  The `jal` at 0x1d5c calls part_start_partition_thread with a0=?, a1=0x2, a2=0x1, a3=?.
  The `jal` at 0x1d78 calls part_probe_nasid with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1d94 calls part_probe_nasid with a0=[[(sym(pdaindr) + ([-0x3be0]:2 << 0x4))+8]:8+1060]:2, a1=([-0x3be0]:2 << 0x4), a2=?, a3=?.
  The `beq` branch at 0x1c34 targets 0x1c50, is taken when v0(=ret(cpsema)) == 0, and falls through when v0(=ret(cpsema)) != 0.
  The `bne` branch at 0x1c44 targets 0x1c3c, is taken when v0(=ret(cpsema)) != 0, and falls through when v0(=ret(cpsema)) == 0.
  The `bne` branch at 0x1c64 targets 0x1ca8, is taken when v0(=ret(vector_read)) != 0, and falls through when v0(=ret(vector_read)) == 0.
  The `beq` branch at 0x1c74 targets 0x1d6c, is taken when (v0(?) & 0xf) == 0, and falls through when (v0(?) & 0xf) != 0.
  The `bne` branch at 0x1c94 targets 0x1c7c, is taken when s0(?) < 0x100 (signed), and falls through when s0(?) >= 0x100 (signed).
  The `beq` branch at 0x1ca0 targets 0x1cdc and is always taken.
  The `beq` branch at 0x1cd8 targets 0x1ca8, is taken when s1(?) >= 0x40 (signed), and falls through when s1(?) < 0x40 (signed).
  The `beq` branch at 0x1d14 targets 0x1d2c, is taken when a0(?) == a1(=0x2), and falls through when a0(?) != a1(=0x2).
  The `bne` branch at 0x1d1c targets 0x1cc0, is taken when a0(?) != t9(=0x7), and falls through when a0(?) == t9(=0x7).
  The `beq` branch at 0x1d24 targets 0x1d38 and is always taken.
  The `beq` branch at 0x1d64 targets 0x1ccc and is always taken.
  The `beq` branch at 0x1d9c targets 0x1ca0 and is always taken.
  The return at 0x1cb8 has v0 = one of ret(vector_read), ?.

- `part_spurious_interrupt` in `IP27/usr/cpu/sysgen/IP27boot/partition.o` at 0x1da4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/partition.o`.
  Range: 0x1da4-0x1e0c (104 bytes).
  It occupies 104 bytes.
  The `lw` at 0x1db8 loads 4 bytes from ret(part_get) +0x20.
  The `lld` at 0x1de0 loads 8 bytes from ret(part_get) +0x48.
  The `scd` at 0x1dec stores 8 bytes to ret(part_get) +0x48.
  The `lb` at 0x1df8 loads 1 byte from ret(part_get) +0x14.
  The `jal` at 0x1db0 calls part_get with a0=?, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1dfc calls cmn_err with a0=0x4, a1=sym(.rodata), a2=[ret(part_get)+20]:1, a3=ret(part_get)+72, a4=0x1, a5=[ret(part_get)+72]:8+1.
  The `beq` branch at 0x1dc0 targets 0x1dd4, is taken when a1(=[ret(part_get)+32]) == a2(=0x1), and falls through when a1(=[ret(part_get)+32]) != a2(=0x1).
  The `beql` branch at 0x1df0 targets 0x1de0, is taken when a5(=[ret(part_get)+72]:8+1) == 0, and falls through when a5(=[ret(part_get)+72]:8+1) != 0; its branch-likely delay slot `nop` at 0x1df4 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x1e04 targets 0x1dcc and is always taken.
  The return at 0x1dcc has v0 = one of ret(part_get), ret(cmn_err).

- `part_interrupt_thread` in `IP27/usr/cpu/sysgen/IP27boot/partition.o` at 0x1e0c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/partition.o`.
  Range: 0x1e0c-0x1f28 (284 bytes).
  It occupies 284 bytes.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x18, including `lw` at 0x1e28, `lw` at 0x1ed0, `lw` at 0x1eec.
  The `ld` at 0x1e38 loads 8 bytes from a0 (arg0 at entry) +0x20.
  3 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x18, including `sw` at 0x1e54, `sw` at 0x1ee0, `sw` at 0x1ef4.
  2 such `lw` accesses load 4 bytes from [a0+32]:8 +0x80, including `lw` at 0x1e60, `lw` at 0x1ee8.
  2 such `ll` accesses load 4 bytes from [a0+32]:8 +0x6c, including `ll` at 0x1e78, `ll` at 0x1eb0.
  2 such `sc` accesses store 4 bytes to [a0+32]:8 +0x6c, including `sc` at 0x1e84, `sc` at 0x1ebc.
  The `ld` at 0x1e90 loads 8 bytes from [a0+32]:8 +0x50.
  The `lw` at 0x1e94 loads 4 bytes from [a0+32]:8 +0x70.
  The `lb` at 0x1e9c loads 1 byte from [a0+32]:8 +0x14.
  The `lw` at 0x1ef8 loads 4 bytes from [a0+32]:8 +0x68.
  The `jal` at 0x1e6c calls compare_and_dec_int_gt with a0=[a0+32]:8+128, a1=0x0, a2=?, a3=?.
  The `jalr` at 0x1ea4 calls (unknown callee) with a0=[[a0+32]:8+20]:1, a1=?, a2=[[a0+32]:8+80]:8, a3=[[a0+32]:8+108]-1, a4=-0x1, a5=[[a0+32]:8+108]-1.
  The `jal` at 0x1edc calls ipsema with a0=[a0+32]:8+136, a1=?, a2=?, a3=?, a6=0x1, a7=[[a0+32]:8+108]+1.
  The `jal` at 0x1f08 calls part_interrupt_thread_exit with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x1f18 calls ipsema with a0=[a0+32]:8+136, a1=?, a2=?, a3=?.
  The `beq` branch at 0x1e58 targets 0x1e74 and is always taken.
  The `beq` branch at 0x1e64 targets 0x1eec, is taken when v0(=[[a0+32]:8+128]) == 0, and falls through when v0(=[[a0+32]:8+128]) != 0.
  The `beql` branch at 0x1e88 targets 0x1e78, is taken when a5(=[[a0+32]:8+108]-1) == 0, and falls through when a5(=[[a0+32]:8+108]-1) != 0; its branch-likely delay slot `nop` at 0x1e8c runs only when taken and is annulled on fall-through.
  The `beql` branch at 0x1ec0 targets 0x1eb0, is taken when a7(=[[a0+32]:8+108]+1) == 0, and falls through when a7(=[[a0+32]:8+108]+1) != 0; its branch-likely delay slot `nop` at 0x1ec4 runs only when taken and is annulled on fall-through.
  The `bne` branch at 0x1ec8 targets 0x1e60, is taken when s2(=[[a0+32]:8+108]+1) != s4(=0x1), and falls through when s2(=[[a0+32]:8+108]+1) == s4(=0x1).
  The `beq` branch at 0x1ee4 targets 0x1e64 and is always taken.
  The `beq` branch at 0x1f00 targets 0x1f18, is taken when t1(=[[a0+32]:8+104]) >= s2(=[[a0+32]:8+108]+1) (signed), and falls through when t1(=[[a0+32]:8+104]) < s2(=[[a0+32]:8+108]+1) (signed).
  The `beq` branch at 0x1f10 targets 0x1e78 and is always taken.
  The `beq` branch at 0x1f20 targets 0x1e78 and is always taken.

- `part_interrupt_thread_setup` in `IP27/usr/cpu/sysgen/IP27boot/partition.o` at 0x1f28 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/partition.o`.
  Range: 0x1f28-0x1f70 (72 bytes).
  It occupies 72 bytes.
  The `ld` at 0x1f2c loads 8 bytes from abs 0xffffffffffffc020.
  The `sd` at 0x1f30 stores 8 bytes to a0 (arg0 at entry) +0x10.
  The `jal` at 0x1f48 calls xthread_set_func with a0=[-0x3fe0]:8, a1=sym(part_interrupt_thread), a2=a0 at entry (arg0), a3=a3 at entry (arg3).
  The `jal` at 0x1f50 calls part_queue_xthread with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x1f58 calls part_interrupt_thread with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The return at 0x1f68 has v0 = ret(part_interrupt_thread).

- `part_interrupt` in `IP27/usr/cpu/sysgen/IP27boot/partition.o` at 0x1f70 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/partition.o`.
  Range: 0x1f70-0x20b0 (320 bytes).
  It occupies 320 bytes.
  The `lh` at 0x1f7c loads 2 bytes from abs 0xffffffffffffc420.
  The `ld` at 0x1f94 loads 8 bytes from (sym(pdaindr) + ([-0x3be0]:2 << 0x4)) +0x8.
  The `lbu` at 0x1f9c loads 1 byte from [(sym(pdaindr) + ([-0x3be0]:2 << 0x4))+8]:8 +0x520.
  The `lh` at 0x1fa0 loads 2 bytes from [(sym(pdaindr) + ([-0x3be0]:2 << 0x4))+8]:8 +0x424.
  The `ld` at 0x1fc8 loads 8 bytes from (([[(sym(pdaindr) + ([-0x3be0]:2 << 0x4))+8]:8+1312]:1 << 0x3) + ([[(sym(pdaindr) + ([-0x3be0]:2 << 0x4))+8]:8+1060]:2 << 0x20)) -0x6dfffffffe7fff28.
  The `sd` at 0x1fcc stores 8 bytes to (([[(sym(pdaindr) + ([-0x3be0]:2 << 0x4))+8]:8+1312]:1 << 0x3) + ([[(sym(pdaindr) + ([-0x3be0]:2 << 0x4))+8]:8+1060]:2 << 0x20)) -0x6dfffffffe7fff28.
  The `sd` at 0x1fd4 stores 8 bytes to abs 0x9200000001000090.
  The `ld` at 0x1fe0 loads 8 bytes from abs 0x9200000001000098.
  The `ld` at 0x2014 loads 8 bytes from ?.
  2 such `lld` accesses load 8 bytes from ?, including `lld` at 0x201c, `lld` at 0x207c.
  2 such `scd` accesses store 8 bytes to ?, including `scd` at 0x2028, `scd` at 0x2088.
  2 such `lb` accesses load 1 byte from ?, including `lb` at 0x2034, `lb` at 0x2094.
  The `jal` at 0x20a0 calls vsema with a0=?, a1=?, a2=?, a3=?, a5=table(0x1), a7=0x1.
  The `beq` branch at 0x1fdc targets 0x2058, is taken when s0(=[(([[(sym(pdaindr) + ([-0x3be0]:2 << 0x4))+8]:8+1312]:1 << 0x3) + ([[(sym(pdaindr) + ([-0x3be0]:2 << 0x4))+8]:8+1060]:2 << 0x20))-7926335344146906920]:8) == 0, and falls through when s0(=[(([[(sym(pdaindr) + ([-0x3be0]:2 << 0x4))+8]:8+1312]:1 << 0x3) + ([[(sym(pdaindr) + ([-0x3be0]:2 << 0x4))+8]:8+1060]:2 << 0x20))-7926335344146906920]:8) != 0.
  The `beq` branch at 0x1fe8 targets 0x2000 and is always taken.
  The `beq` branch at 0x1ff8 targets 0x2058, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0x2004 targets 0x1ff0, is taken when (s0(?) & 0x1) == 0, and falls through when (s0(?) & 0x1) != 0.
  The `beql` branch at 0x202c targets 0x201c, is taken when t2(?) == 0, and falls through when t2(?) != 0; its branch-likely delay slot `nop` at 0x2030 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x2040 targets 0x2078, is taken when (s2(?) & a6(?)) == 0, and falls through when (s2(?) & a6(?)) != 0.
  The `bne` branch at 0x2050 targets 0x2000, is taken when a3(?) != 0, and falls through when a3(?) == 0.
  The `beql` branch at 0x208c targets 0x207c, is taken when t0(=table(0x1)) == 0, and falls through when t0(=table(0x1)) != 0; its branch-likely delay slot `nop` at 0x2090 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x20a8 targets 0x204c and is always taken.
  The return at 0x2070 has v0 = one of [[(sym(pdaindr) + ([-0x3be0]:2 << 0x4))+8]:8+1312]:1+69, ?.

- `part_interrupt_id` in `IP27/usr/cpu/sysgen/IP27boot/partition.o` at 0x20b0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/partition.o`.
  Range: 0x20b0-0x20d8 (40 bytes).
  It occupies 40 bytes.
  The `ld` at 0x20d4 loads 8 bytes from table(sym(.bss)) +0x40.
  The return at 0x20d0 has v0 = [table(sym(.bss))+64]:8.

- `part_queue_xthread` in `IP27/usr/cpu/sysgen/IP27boot/partition.o` at 0x20d8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/partition.o`.
  Range: 0x20d8-0x2220 (328 bytes).
  It occupies 328 bytes.
  The `ld` at 0x20e0 loads 8 bytes from a0 (arg0 at entry) +0x20.
  2 such `lw` accesses load 4 bytes from [a0+32]:8 +0x20, including `lw` at 0x2100, `lw` at 0x2194.
  The `sw` at 0x210c stores 4 bytes to [a0+32]:8 +0xc.
  2 such `ld` accesses load 8 bytes from [a0+32]:8 +0xa8, including `ld` at 0x2110, `ld` at 0x221c.
  The `sd` at 0x2118 stores 8 bytes to a0 (arg0 at entry) +0x0.
  The `sd` at 0x211c stores 8 bytes to a0 (arg0 at entry) +0x8.
  The `sd` at 0x2120 stores 8 bytes to [[a0+32]:8+168]:8 +0x0.
  The `ld` at 0x2124 loads 8 bytes from a0 (arg0 at entry) +0x0.
  The `sd` at 0x2128 stores 8 bytes to [a0]:8 +0x8.
  The `sw` at 0x2130 stores 4 bytes to a0 (arg0 at entry) +0x18.
  The `lw` at 0x2134 loads 4 bytes from [a0+32]:8 +0x60.
  The `lw` at 0x2138 loads 4 bytes from [a0+32]:8 +0x64.
  The `sw` at 0x215c stores 4 bytes to [a0+32]:8 +0x60.
  The `sw` at 0x2160 stores 4 bytes to [a0+32]:8 +0x64.
  The `ll` at 0x2164 loads 4 bytes from [a0+32]:8 +0x70.
  The `sc` at 0x2170 stores 4 bytes to [a0+32]:8 +0x70.
  The `ll` at 0x217c loads 4 bytes from [a0+32]:8 +0x6c.
  The `sc` at 0x2188 stores 4 bytes to [a0+32]:8 +0x6c.
  2 such `lw` accesses load 4 bytes from [a0+32]:8 +0xc, including `lw` at 0x219c, `lw` at 0x220c.
  The `ll` at 0x21ec loads 4 bytes from [a0+32]:8 +0x7c.
  The `sc` at 0x21f8 stores 4 bytes to [a0+32]:8 +0x7c.
  The `jal` at 0x20f8 calls mutex_spinlock with a0=[a0+32]:8+8, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x21a0 calls mutex_spinunlock with a0=[a0+32]:8+8, a1=[[a0+32]:8+12], a2=?, a3=[a0+32]:8+108, a4=0x1, a5=-0x1, a6=[[a0+32]:8+32], a7=0x7.
  The `jal` at 0x21c0 calls mutex_spinunlock with a0=[a0+32]:8+8, a1=[[a0+32]:8+12], a2=?, a3=[a0+32]:8+108, a4=0x1, a5=-0x1, a6=[[a0+32]:8+32], a7=0x7.
  The `jal` at 0x21c8 calls part_terminate with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x21dc calls kmem_free with a0=a0 at entry (arg0), a1=0x28, a2=?, a3=?.
  The `jal` at 0x2208 calls mutex_spinunlock with a0=[a0+32]:8+8, a1=[[a0+32]:8+12], a2=?, a3=?.
  The `jal` at 0x2210 calls xthread_exit with a0=?, a1=?, a2=?, a3=?.
  The `beq` branch at 0x2108 targets 0x21d8, is taken when at(=[[a0+32]:8+32]) == v1(=0x8), and falls through when at(=[[a0+32]:8+32]) != v1(=0x8).
  The `beq` branch at 0x2158 targets 0x2164, is taken when a2(=[[a0+32]:8+100]) >= a1(=[[a0+32]:8+96]+1) (signed), and falls through when a2(=[[a0+32]:8+100]) < a1(=[[a0+32]:8+96]+1) (signed).
  The `beql` branch at 0x2174 targets 0x2164, is taken when t3(=[[a0+32]:8+112]-1) == 0, and falls through when t3(=[[a0+32]:8+112]-1) != 0; its branch-likely delay slot `nop` at 0x2178 runs only when taken and is annulled on fall-through.
  The `beql` branch at 0x218c targets 0x217c, is taken when t1(=[[a0+32]:8+108]+1) == 0, and falls through when t1(=[[a0+32]:8+108]+1) != 0; its branch-likely delay slot `nop` at 0x2190 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x2198 targets 0x21c0, is taken when a6(=[[a0+32]:8+32]) == a7(=0x7), and falls through when a6(=[[a0+32]:8+32]) != a7(=0x7).
  The `beq` branch at 0x21d0 targets 0x21ac and is always taken.
  The `beql` branch at 0x21fc targets 0x21ec, is taken when at(=[[a0+32]:8+124]+1) == 0, and falls through when at(=[[a0+32]:8+124]+1) != 0; its branch-likely delay slot `nop` at 0x2200 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x2218 targets 0x2114 and is always taken.
  The return at 0x21b8 has v0 = one of ret(mutex_spinunlock), ret(part_terminate).

- `part_dequeue_xthread` in `IP27/usr/cpu/sysgen/IP27boot/partition.o` at 0x2220 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/partition.o`.
  Range: 0x2220-0x22a8 (136 bytes).
  It occupies 136 bytes.
  The `ld` at 0x2228 loads 8 bytes from a0 (arg0 at entry) +0x20.
  The `sw` at 0x2248 stores 4 bytes to [a0+32]:8 +0xc.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x0, including `ld` at 0x224c, `ld` at 0x225c.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x8, including `ld` at 0x2250, `ld` at 0x2258.
  The `sd` at 0x2254 stores 8 bytes to [a0]:8 +0x8.
  The `sd` at 0x2260 stores 8 bytes to [a0+8]:8 +0x0.
  The `lw` at 0x2264 loads 4 bytes from [a0+32]:8 +0x60.
  The `sw` at 0x2270 stores 4 bytes to [a0+32]:8 +0x60.
  The `lw` at 0x2280 loads 4 bytes from [a0+32]:8 +0xc.
  The `jal` at 0x2240 calls mutex_spinlock with a0=[a0+32]:8+8, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x227c calls mutex_spinunlock with a0=[a0+32]:8+8, a1=[[a0+32]:8+12], a2=?, a3=?.
  The `jal` at 0x2298 calls sv_broadcast with a0=[a0+32]:8+152, a1=[a0]:8, a2=?, a3=?.
  The `beq` branch at 0x226c targets 0x2298, is taken when at(=[[a0+32]:8+96]-1) == 0, and falls through when at(=[[a0+32]:8+96]-1) != 0.
  The `beq` branch at 0x22a0 targets 0x2278 and is always taken.
  The return at 0x2290 has v0 = ret(mutex_spinunlock).

- `part_start_partition_thread` in `IP27/usr/cpu/sysgen/IP27boot/partition.o` at 0x22a8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/partition.o`.
  Range: 0x22a8-0x24a4 (508 bytes).
  It occupies 508 bytes.
  The `sd` at 0x234c stores 8 bytes to ret(kmem_zalloc) +0x20.
  The `ll` at 0x2374 loads 4 bytes from a0 (arg0 at entry) +0x70.
  The `sc` at 0x2380 stores 4 bytes to a0 (arg0 at entry) +0x70.
  The `ll` at 0x23bc loads 4 bytes from a0 (arg0 at entry) +0x78.
  The `sc` at 0x23c8 stores 4 bytes to a0 (arg0 at entry) +0x78.
  The `ll` at 0x23dc loads 4 bytes from a0 (arg0 at entry) +0x74.
  The `sc` at 0x23e8 stores 4 bytes to a0 (arg0 at entry) +0x74.
  The `ll` at 0x23f4 loads 4 bytes from a0 (arg0 at entry) +0x80.
  The `sc` at 0x2400 stores 4 bytes to a0 (arg0 at entry) +0x80.
  The `ll` at 0x2418 loads 4 bytes from a0 (arg0 at entry) +0x84.
  The `sc` at 0x2424 stores 4 bytes to a0 (arg0 at entry) +0x84.
  The `jal` at 0x231c calls kmem_zalloc with a0=0x28, a1=?, a2=?, a3=?.
  The `jal` at 0x2330 calls kmem_alloc with a0=0x4000, a1=one of 0x100, 0x101, a2=?, a3=?.
  The `jal` at 0x2360 calls xthread_create with a0=a0 at entry (arg0), a1=ret(kmem_alloc), a2=0x4000, a3=0x1, a4=[sym(partition_pri)], a5=0x3000, a6=sym(part_interrupt_thread_setup), a7=ret(kmem_zalloc).
  The `jal` at 0x23a4 calls kmem_free with a0=ret(kmem_zalloc), a1=0x28, a2=?, a3=?.
  The `jal` at 0x2464 calls cvsema with a0=a0+136, a1=?, a2=?, a3=?.
  The `jal` at 0x247c calls vsema with a0=a0+136, a1=?, a2=?, a3=?.
  The `jal` at 0x248c calls vsema with a0=sym(.bss), a1=?, a2=?, a3=?.
  The `blez` branch at 0x22e0 targets 0x249c, is taken when a1 <= 0 (signed), and falls through when a1 > 0 (signed).
  The `beq` branch at 0x2314 targets 0x2464, is taken when s3(=a2) == 0, and falls through when s3(=a2) != 0.
  The `beq` branch at 0x2324 targets 0x23ac, is taken when v0(=ret(kmem_zalloc)) == 0, and falls through when v0(=ret(kmem_zalloc)) != 0.
  The `beq` branch at 0x2338 targets 0x23a4, is taken when v0(=ret(kmem_alloc)) == 0, and falls through when v0(=ret(kmem_alloc)) != 0.
  The `beql` branch at 0x2384 targets 0x2374, is taken when a4(=[a0+112]+1) == 0, and falls through when a4(=[a0+112]+1) != 0; its branch-likely delay slot `nop` at 0x2388 runs only when taken and is annulled on fall-through.
  The `bne` branch at 0x2394 targets 0x2314, is taken when s0(?) < s4(=a1) (signed), and falls through when s0(?) >= s4(=a1) (signed).
  The `beq` branch at 0x239c targets 0x23b0 and is always taken.
  The `beql` branch at 0x23cc targets 0x23bc, is taken when t1(?) == 0, and falls through when t1(?) != 0; its branch-likely delay slot `nop` at 0x23d0 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x23d4 targets 0x2438, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `beql` branch at 0x23ec targets 0x23dc, is taken when t9(?) == 0, and falls through when t9(?) != 0; its branch-likely delay slot `nop` at 0x23f0 runs only when taken and is annulled on fall-through.
  The `beql` branch at 0x2404 targets 0x23f4, is taken when t3(?) == 0, and falls through when t3(?) != 0; its branch-likely delay slot `nop` at 0x2408 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x2410 targets 0x247c, is taken when s3(?) >= t2(?) (signed), and falls through when s3(?) < t2(?) (signed).
  The `beql` branch at 0x2428 targets 0x2418, is taken when v0(?) == 0, and falls through when v0(?) != 0; its branch-likely delay slot `nop` at 0x242c runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x2430 targets 0x248c, is taken when ra(?) == s3(?), and falls through when ra(?) != s3(?).
  The `bne` branch at 0x246c targets 0x238c, is taken when v0(=ret(cvsema)) != 0, and falls through when v0(=ret(cvsema)) == 0.
  The `beq` branch at 0x2474 targets 0x231c and is always taken.
  The `beq` branch at 0x2484 targets 0x2418 and is always taken.
  The `beq` branch at 0x2494 targets 0x243c and is always taken.
  The `beq` branch at 0x249c targets 0x23b0 and is always taken.
  The return at 0x245c has v0 = ?.

- `part_start_thread` in `IP27/usr/cpu/sysgen/IP27boot/partition.o` at 0x24a4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/partition.o`.
  Range: 0x24a4-0x24dc (56 bytes).
  It occupies 56 bytes.
  The `jal` at 0x24b4 calls part_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x24c4 calls part_start_partition_thread with a0=ret(part_get), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=?.
  The return at 0x24d4 has v0 = ret(part_start_partition_thread).

- `part_interrupt_reset` in `IP27/usr/cpu/sysgen/IP27boot/partition.o` at 0x24dc (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/partition.o`.
  Range: 0x24dc-0x2570 (148 bytes).
  It occupies 148 bytes.
  The `ld` at 0x24e4 loads 8 bytes from a0 (arg0 at entry) +0xa0.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0x2504, `ld` at 0x2510.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x60, including `lw` at 0x251c, `lw` at 0x2534.
  The `sd` at 0x2560 stores 8 bytes to a0 (arg0 at entry) +0x50.
  The `jal` at 0x2508 calls xthread_set_func with a0=?, a1=sym(part_interrupt_thread_exit), a2=?, a3=?.
  The `jal` at 0x252c calls vsema with a0=a0+136, a1=?, a2=?, a3=?.
  The `jal` at 0x2550 calls sv_broadcast with a0=a0+152, a1=?, a2=?, a3=?.
  The `beq` branch at 0x24f8 targets 0x251c, is taken when s2(=a0+160) == s0(=[a0+160]:8), and falls through when s2(=a0+160) != s0(=[a0+160]:8).
  The `bne` branch at 0x2514 targets 0x2504, is taken when s2(=a0+160) != s0(?), and falls through when s2(=a0+160) == s0(?).
  The `blez` branch at 0x2524 targets 0x2548, is taken when at(=[a0+96]) <= 0 (signed), and falls through when at(=[a0+96]) > 0 (signed).
  The `bne` branch at 0x2540 targets 0x252c, is taken when s0(?) < v0(=[a0+96]) (signed), and falls through when s0(?) >= v0(=[a0+96]) (signed).
  The return at 0x2568 has v0 = ret(sv_broadcast).

- `part_interrupt_set` in `IP27/usr/cpu/sysgen/IP27boot/partition.o` at 0x2570 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/partition.o`.
  Range: 0x2570-0x25e0 (112 bytes).
  It occupies 112 bytes.
  The `sw` at 0x25a4 stores 4 bytes to ret(part_get) +0xc.
  The `sd` at 0x25ac stores 8 bytes to ret(part_get) +0x50.
  The `sw` at 0x25b0 stores 4 bytes to ret(part_get) +0x68.
  The `lw` at 0x25dc loads 4 bytes from ret(part_get) +0xc.
  The `jal` at 0x2584 calls part_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x2594 calls mutex_spinlock with a0=ret(part_get)+8, a1=?, a2=?, a3=?.
  The `jal` at 0x25bc calls mutex_spinunlock with a0=ret(part_get)+8, a1=?, a2=?, a3=?.
  The `jal` at 0x25d0 calls part_interrupt_reset with a0=ret(part_get), a1=ret(mutex_spinlock), a2=?, a3=?.
  The `beq` branch at 0x25a0 targets 0x25d0, is taken when s1(=a2) == 0, and falls through when s1(=a2) != 0.
  The `beq` branch at 0x25d8 targets 0x25b4 and is always taken.
  The return at 0x25c8 has v0 = ret(mutex_spinunlock).

- `part_init_partition` in `IP27/usr/cpu/sysgen/IP27boot/partition.o` at 0x25e0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/partition.o`.
  Range: 0x25e0-0x26ec (268 bytes).
  It occupies 268 bytes.
  2 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x14, including `sb` at 0x2618, `sb` at 0x26e8.
  The `sw` at 0x2620 stores 4 bytes to a0 (arg0 at entry) +0x20.
  The `sd` at 0x2624 stores 8 bytes to a0 (arg0 at entry) +0x28.
  The `sd` at 0x2628 stores 8 bytes to a0 (arg0 at entry) +0x30.
  The `sd` at 0x262c stores 8 bytes to a0 (arg0 at entry) +0x38.
  The `sw` at 0x2630 stores 4 bytes to a0 (arg0 at entry) +0x10.
  The `sd` at 0x2634 stores 8 bytes to a0 (arg0 at entry) +0x40.
  The `sd` at 0x2638 stores 8 bytes to a0 (arg0 at entry) +0x48.
  The `sw` at 0x263c stores 4 bytes to a0 (arg0 at entry) +0x60.
  The `sw` at 0x2640 stores 4 bytes to a0 (arg0 at entry) +0x64.
  The `sw` at 0x2644 stores 4 bytes to a0 (arg0 at entry) +0x6c.
  The `sw` at 0x2648 stores 4 bytes to a0 (arg0 at entry) +0x68.
  The `sw` at 0x264c stores 4 bytes to a0 (arg0 at entry) +0x70.
  The `sw` at 0x2650 stores 4 bytes to a0 (arg0 at entry) +0x78.
  The `sw` at 0x2654 stores 4 bytes to a0 (arg0 at entry) +0x74.
  The `sw` at 0x2658 stores 4 bytes to a0 (arg0 at entry) +0x80.
  The `sw` at 0x265c stores 4 bytes to a0 (arg0 at entry) +0x84.
  The `sw` at 0x2660 stores 4 bytes to a0 (arg0 at entry) +0x7c.
  The `sd` at 0x2664 stores 8 bytes to a0 (arg0 at entry) +0x18.
  The `sd` at 0x266c stores 8 bytes to a0 (arg0 at entry) +0xa8.
  The `sd` at 0x2670 stores 8 bytes to a0 (arg0 at entry) +0xa0.
  The `sd` at 0x2684 stores 8 bytes to a0 (arg0 at entry) +0x50.
  The `jal` at 0x2610 calls sprintf with a0=a0 at entry (arg0), a1=sym(.rodata), a2=a1 at entry (arg1), a3=a3 at entry (arg3).
  The `jal` at 0x2688 calls init_spinlock with a0=a0+8, a1=sym(.rodata), a2=a0 at entry (arg0), a3=0x1, a4=a2 at entry (arg2).
  The `jal` at 0x26a0 calls init_sema with a0=a0+136, a1=0x0, a2=sym(.rodata), a3=a0 at entry (arg0).
  The `jal` at 0x26bc calls init_sv with a0=a0+152, a1=0x0, a2=sym(.rodata), a3=a0 at entry (arg0).
  The `jal` at 0x26dc calls sprintf with a0=a0 at entry (arg0), a1=sym(.rodata), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `bltz` branch at 0x25f8 targets 0x26d4, is taken when a1 < 0 (signed), and falls through when a1 >= 0 (signed).
  The `beq` branch at 0x2604 targets 0x26d4, is taken when a1 >= 0x40 (signed), and falls through when a1 < 0x40 (signed).
  The `beq` branch at 0x26e4 targets 0x261c and is always taken.
  The return at 0x26cc has v0 = ret(init_sv).

- `part_init` in `IP27/usr/cpu/sysgen/IP27boot/partition.o` at 0x26ec (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/partition.o`.
  Range: 0x26ec-0x2c48 (1372 bytes).
  It occupies 1372 bytes.
  5 such `sb` accesses store 1 byte to ?, including `sb` at 0x273c, `sb` at 0x2a7c, `sb` at 0x2a90.
  4 such `lw` accesses load 4 bytes from ?, including `lw` at 0x2740, `lw` at 0x2ac4, `lw` at 0x2aec.
  7 such `sh` accesses store 2 bytes to ?, including `sh` at 0x2754, `sh` at 0x2a24, `sh` at 0x2a74.
  5 such `sw` accesses store 4 bytes to ?, including `sw` at 0x2764, `sw` at 0x2a14, `sw` at 0x2a1c.
  13 such `sd` accesses store 8 bytes to ?, including `sd` at 0x2784, `sd` at 0x2790, `sd` at 0x2a04.
  2 such `lh` accesses load 2 bytes from ?, including `lh` at 0x285c, `lh` at 0x2b60.
  5 such `ld` accesses load 8 bytes from ?, including `ld` at 0x2868, `ld` at 0x2948, `ld` at 0x2b70.
  The `lbu` at 0x2954 loads 1 byte from ?.
  The `lh` at 0x2a80 loads 2 bytes from ret(find_lboard) +0xe.
  The `lh` at 0x2c44 loads 2 bytes from sym(compact_to_nasid_node) +0x0.
  The `jal` at 0x270c calls bzero with a0=sym(.bss), a1=0x1c00, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x27bc calls part_init_partition with a0=?, a1=?, a2=sym(part_activate), a3=?.
  The `jal` at 0x27e0 calls part_init_partition with a0=sym(.bss), a1=-0x1, a2=sym(part_discovery), a3=?.
  The `jal` at 0x27e8 calls vsema with a0=sym(.bss), a1=?, a2=?, a3=?.
  The `jal` at 0x27f8 calls spinlock_init with a0=sym(.sbss), a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x2804 calls spinlock_init with a0=sym(.sbss)+12, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x2810 calls spinlock_init with a0=sym(.sbss)+16, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x2824 calls init_mutex with a0=sym(.bss), a1=0x0, a2=sym(.rodata), a3=-0x1.
  The `jal` at 0x2830 calls part_init_nodes with a0=[sym(region_mask)]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x289c calls kmem_alloc with a0=0x180, a1=0x900, a2=?, a3=?.
  The `jal` at 0x28ac calls bte_poison_range with a0=ret(kmem_alloc), a1=0x180, a2=?, a3=?.
  The `jal` at 0x28cc calls part_get_promid with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x2930 calls cpu_enabled with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x2964 calls intr_connect_level with a0=?, a1=?, a2=0x0, a3=sym(part_interrupt), a4=0x0, a5=0x0.
  The `jal` at 0x297c calls is_fine_dirmode with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x2994 calls init_sema with a0=sym(.bss), a1=0x0, a2=sym(.rodata), a3=0x0.
  The `jal` at 0x29cc calls sthread_create with a0=sym(.rodata), a1=0x0, a2=0x0, a3=0x0, a4=[sym(partition_pri)], a5=0x1000, a6=sym(part_thread), a7=0x0.
  The `jal` at 0x29f8 calls bzero with a0=?, a1=0x110, a2=?, a3=?.
  The `jal` at 0x2aac calls cnode_slice_to_cpuid with a0=?, a1=0x0, a2=?, a3=[sym(partition_partid)]:1, a4=0xffff, a5=0x3, a6=[ret(find_lboard)+14]:2, a7=[sym(partition_partid)]:1.
  The `jal` at 0x2ab4 calls cpu_enabled with a0=ret(cnode_slice_to_cpuid), a1=?, a2=?, a3=?.
  The `jal` at 0x2ad4 calls cnode_slice_to_cpuid with a0=?, a1=0x1, a2=?, a3=?.
  The `jal` at 0x2adc calls cpu_enabled with a0=ret(cnode_slice_to_cpuid), a1=?, a2=?, a3=?.
  The `jal` at 0x2b18 calls is_specified with a0=sym(arg_clusterid), a1=?, a2=?, a3=?.
  The `jal` at 0x2b28 calls atoi with a0=sym(arg_clusterid), a1=?, a2=?, a3=?.
  The `jal` at 0x2b94 calls find_lboard with a0=?, a1=0x11, a2=?, a3=?.
  The `jal` at 0x2bcc calls avl_init_tree with a0=sym(.bss), a1=sym(.data), a2=?, a3=?.
  The `jal` at 0x2be0 calls timeout_pri with a0=sym(part_heartbeat), a1=0x0, a2=[sym(.sdata)+24], a3=[sym(hb_pri)].
  The `jal` at 0x2be8 calls error_reg_partition_handler with a0=sym(part_error_handler), a1=?, a2=?, a3=?.
  The `jal` at 0x2bf8 calls part_start_partition_thread with a0=sym(.bss), a1=0x1, a2=0x1, a3=?.
  The `jal` at 0x2c08 calls cmn_err with a0=0x0, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x2c1c calls cmn_err with a0=0x4, a1=sym(.rodata), a2=?, a3=[sym(maxcpus)].
  The `jal` at 0x2c28 calls cmn_err with a0=0x4, a1=sym(.rodata), a2=?, a3=?.
  The `bne` branch at 0x2760 targets 0x272c, is taken when v0(?) < 0x100 (signed), and falls through when v0(?) >= 0x100 (signed).
  The `bne` branch at 0x278c targets 0x2770, is taken when v0(?) < 0x40 (unsigned), and falls through when v0(?) >= 0x40 (unsigned).
  The `bne` branch at 0x27d4 targets 0x279c, is taken when s2(?) < 0x40 (signed), and falls through when s2(?) >= 0x40 (signed).
  The `blez` branch at 0x283c targets 0x2894, is taken when a1(=[sym(maxnodes)]) <= 0 (signed), and falls through when a1(=[sym(maxnodes)]) > 0 (signed).
  The `bne` branch at 0x2878 targets 0x28f4, is taken when v1(?) < 0x3 (unsigned), and falls through when v1(?) >= 0x3 (unsigned).
  The `bne` branch at 0x288c targets 0x2858, is taken when v0(?) < a1(=[sym(maxnodes)]) (signed), and falls through when v0(?) >= a1(=[sym(maxnodes)]) (signed).
  The `bne` branch at 0x28b4 targets 0x2c18, is taken when v0(=ret(bte_poison_range)) != 0, and falls through when v0(=ret(bte_poison_range)) == 0.
  The `blez` branch at 0x28bc targets 0x28cc, is taken when a3(=[sym(maxcpus)]) <= 0 (signed), and falls through when a3(=[sym(maxcpus)]) > 0 (signed).
  The `beq` branch at 0x28c4 targets 0x2930 and is always taken.
  The `bltz` branch at 0x28dc targets 0x28f0, is taken when a1(?) < 0 (signed), and falls through when a1(?) >= 0 (signed).
  The `bne` branch at 0x28e8 targets 0x297c, is taken when a1(?) < 0x40 (signed), and falls through when a1(?) >= 0x40 (signed).
  The `beq` branch at 0x2928 targets 0x28cc, is taken when s3(?) >= a3(=[sym(maxcpus)]) (signed), and falls through when s3(?) < a3(=[sym(maxcpus)]) (signed).
  The `beq` branch at 0x2938 targets 0x2914, is taken when v0(=ret(cpu_enabled)) == 0, and falls through when v0(=ret(cpu_enabled)) != 0.
  The `beql` branch at 0x296c targets 0x2918, is taken when v0(=ret(intr_connect_level)) == 0, and falls through when v0(=ret(intr_connect_level)) != 0; its branch-likely delay slot `addiu s3,s3,1` at 0x2970 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x2974 targets 0x2c08 and is always taken.
  The `beq` branch at 0x2a50 targets 0x2a60, is taken when ra(=[sym(kdebug)]:2) == 0, and falls through when ra(=[sym(kdebug)]:2) != 0.
  The `blez` branch at 0x2a60 targets 0x2bb4, is taken when v0(=[sym(maxnodes)]) <= 0 (signed), and falls through when v0(=[sym(maxnodes)]) > 0 (signed).
  The `beq` branch at 0x2a68 targets 0x2c38 and is always taken.
  The `beq` branch at 0x2abc targets 0x2ad4, is taken when v0(=ret(cpu_enabled)) == 0, and falls through when v0(=ret(cpu_enabled)) != 0.
  The `beq` branch at 0x2ae4 targets 0x2af8, is taken when v0(=ret(cpu_enabled)) == 0, and falls through when v0(=ret(cpu_enabled)) != 0.
  The `beq` branch at 0x2b10 targets 0x2b38, is taken when t3(=[sym(cell_enabled)]) == 0, and falls through when t3(=[sym(cell_enabled)]) != 0.
  The `beq` branch at 0x2b20 targets 0x2b3c, is taken when v0(=ret(is_specified)) == 0, and falls through when v0(=ret(is_specified)) != 0.
  The `beq` branch at 0x2b58 targets 0x2bb4, is taken when s1(?) >= t9(=[sym(maxnodes)]) (signed), and falls through when s1(?) < t9(=[sym(maxnodes)]) (signed).
  The `beq` branch at 0x2b88 targets 0x2b94, is taken when v1(?) == 0, and falls through when v1(?) != 0.
  The `bne` branch at 0x2ba4 targets 0x2a70, is taken when s6(=0x434d5f53505f5357) != v1(?), and falls through when s6(=0x434d5f53505f5357) == v1(?).
  The `beq` branch at 0x2bac targets 0x2b0c and is always taken.
  The `beq` branch at 0x2c00 targets 0x28f8 and is always taken.
  The `beq` branch at 0x2c10 targets 0x2918 and is always taken.
  The `beq` branch at 0x2c30 targets 0x28f8 and is always taken.
  The `beq` branch at 0x2c40 targets 0x2b64 and is always taken.
  The return at 0x290c has v0 = one of ?, ret(part_start_partition_thread), ret(cmn_err).

- `part_init_nodes` in `IP27/usr/cpu/sysgen/IP27boot/partition.o` at 0x2c48 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/partition.o`.
  Range: 0x2c48-0x2d7c (308 bytes).
  It occupies 308 bytes.
  The `jal` at 0x2c78 calls init_sema with a0=sym(.bss), a1=0x0, a2=sym(.rodata), a3=-0x1.
  The `jal` at 0x2d04 calls sthread_create with a0=sym(.rodata), a1=0x0, a2=0x1000, a3=0x0, a4=[sym(partition_pri)], a5=0x1000, a6=sym(part_init_node), a7=a0 at entry (arg0).
  The `jal` at 0x2d2c calls psema with a0=sym(.bss), a1=0x19, a2=?, a3=?.
  The `beq` branch at 0x2c9c targets 0x2d4c, is taken when a1(=[sym(maxnodes)]) == 0, and falls through when a1(=[sym(maxnodes)]) != 0.
  The `beq` branch at 0x2ca4 targets 0x2cc0 and is always taken.
  The `beq` branch at 0x2cb4 targets 0x2d4c, is taken when s2(?) >= a1(=[sym(maxnodes)]) (unsigned), and falls through when s2(?) < a1(=[sym(maxnodes)]) (unsigned).
  The `beq` branch at 0x2cd0 targets 0x2cac, is taken when s4(?) >= s2(?) (unsigned), and falls through when s4(?) < s2(?) (unsigned).
  The `beq` branch at 0x2d14 targets 0x2cdc, is taken when s1(?) >= s0(?) (unsigned), and falls through when s1(?) < s0(?) (unsigned).
  The `beq` branch at 0x2d1c targets 0x2cb0, is taken when s7(?) == 0, and falls through when s7(?) != 0.
  The `bne` branch at 0x2d3c targets 0x2d2c, is taken when s0(?) < s2(?) (unsigned), and falls through when s0(?) >= s2(?) (unsigned).
  The `beq` branch at 0x2d44 targets 0x2cb0 and is always taken.
  The return at 0x2d74 has v0 = one of ret(init_sema), ?.

- `part_from_addr` in `IP27/usr/cpu/sysgen/IP27boot/partition.o` at 0x2d7c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/partition.o`.
  Range: 0x2d7c-0x2da4 (40 bytes).
  It occupies 40 bytes.
  The `lb` at 0x2da0 loads 1 byte from table(sym(.bss)) +0x6.
  The return at 0x2d9c has v0 = [table(sym(.bss))+6]:1.

- `part_from_region` in `IP27/usr/cpu/sysgen/IP27boot/partition.o` at 0x2da4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/partition.o`.
  Range: 0x2da4-0x2dc4 (32 bytes).
  It occupies 32 bytes.
  The `ld` at 0x2db8 loads 8 bytes from table(sym(.bss)) +0x8.
  The `lb` at 0x2dc0 loads 1 byte from [table(sym(.bss))+8]:8 +0x14.
  The return at 0x2dbc has v0 = [[table(sym(.bss))+8]:8+20]:1.

- `part_get_promid` in `IP27/usr/cpu/sysgen/IP27boot/partition.o` at 0x2dc4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/partition.o`.
  Range: 0x2dc4-0x2e7c (184 bytes).
  It occupies 184 bytes.
  The `ld` at 0x2de8 loads 8 bytes from ((ret(get_nasid) << 0x20)+0x9600000000000000 | 0x2000) +0xd0.
  2 such `lhu` accesses load 2 bytes from [((ret(get_nasid) << 0x20)+0x9600000000000000 | 0x2000)+208]:8 +0x4, including `lhu` at 0x2dec, `lhu` at 0x2e54.
  The `lb` at 0x2dfc loads 1 byte from [((ret(get_nasid) << 0x20)+0x9600000000000000 | 0x2000)+208]:8 +0x2b.
  The `lh` at 0x2e0c loads 2 bytes from [((ret(get_nasid) << 0x20)+0x9600000000000000 | 0x2000)+208]:8 +0x80.
  The `ld` at 0x2e1c loads 8 bytes from (([[((ret(get_nasid) << 0x20)+0x9600000000000000 | 0x2000)+208]:8+128]:2 << 0x20)+0x9600000000000000 | 0x2000) +0x48.
  The `lw` at 0x2e30 loads 4 bytes from ?.
  The `lb` at 0x2e64 loads 1 byte from ret(find_lboard) +0x10.
  The `sw` at 0x2e68 stores 4 bytes to [((ret(get_nasid) << 0x20)+0x9600000000000000 | 0x2000)+208]:8 +0x28.
  The `jal` at 0x2dcc calls get_nasid with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x2e4c calls find_lboard with a0=?, a1=0x11, a2=?, a3=0x9600000000000000, a4=([[((ret(get_nasid) << 0x20)+0x9600000000000000 | 0x2000)+208]:8+128]:2 << 0x20), a5=0xffffffffff.
  The `jal` at 0x2e6c calls cmn_err with a0=0x5, a1=sym(.rodata), a2=[[((ret(get_nasid) << 0x20)+0x9600000000000000 | 0x2000)+208]:8+4]:2, a3=0x2, a4=[ret(find_lboard)+16]:1.
  The `bne` branch at 0x2df4 targets 0x2e0c, is taken when at(=[[((ret(get_nasid) << 0x20)+0x9600000000000000 | 0x2000)+208]:8+4]:2) < 0x2 (signed), and falls through when at(=[[((ret(get_nasid) << 0x20)+0x9600000000000000 | 0x2000)+208]:8+4]:2) >= 0x2 (signed).
  The `beq` branch at 0x2e34 targets 0x2e48, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0x2e40 targets 0x2e4c and is always taken.
  The `beq` branch at 0x2e74 targets 0x2dfc and is always taken.
  The return at 0x2e04 has v0 = [[((ret(get_nasid) << 0x20)+0x9600000000000000 | 0x2000)+208]:8+43]:1.

- `part_get_clusterid` in `IP27/usr/cpu/sysgen/IP27boot/partition.o` at 0x2e7c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/partition.o`.
  Range: 0x2e7c-0x2ea4 (40 bytes).
  It occupies 40 bytes.
  The `lbu` at 0x2ea0 loads 1 byte from table(sym(.bss)) +0x15.
  The return at 0x2e9c has v0 = [table(sym(.bss))+21]:1.

- `part_set_clusterid` in `IP27/usr/cpu/sysgen/IP27boot/partition.o` at 0x2ea4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/partition.o`.
  Range: 0x2ea4-0x2ef8 (84 bytes).
  It occupies 84 bytes.
  The `lw` at 0x2ecc loads 4 bytes from ?.
  The `sb` at 0x2ee4 stores 1 byte to ?.
  The `beq` branch at 0x2edc targets 0x2ee8, is taken when at(?) == t1(=0x1), and falls through when at(?) != t1(=0x1).
  The `bne` branch at 0x2ee8 targets 0x2eb4, is taken when a3(?) != 0, and falls through when a3(?) == 0.
  The return at 0x2ef0 has v0 = ?.

- `part_installed` in `IP27/usr/cpu/sysgen/IP27boot/partition.o` at 0x2ef8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/partition.o`.
  Range: 0x2ef8-0x2f00 (8 bytes).
  It occupies 8 bytes.
  The return at 0x2ef8 has v0 = 0x1.

- `part_id` in `IP27/usr/cpu/sysgen/IP27boot/partition.o` at 0x2f00 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/partition.o`.
  Range: 0x2f00-0x2f08 (8 bytes).
  It occupies 8 bytes.
  The return at 0x2f00 has v0 = [sym(partition_partid)]:1.

- `part_get` in `IP27/usr/cpu/sysgen/IP27boot/partition.o` at 0x2f08 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/partition.o`.
  Range: 0x2f08-0x2f48 (64 bytes).
  It occupies 64 bytes.
  The `bltz` branch at 0x2f08 targets 0x2f40, is taken when a0 < 0 (signed), and falls through when a0 >= 0 (signed).
  The `beq` branch at 0x2f1c targets 0x2f3c, is taken when a0 >= 0x40 (signed), and falls through when a0 < 0x40 (signed).
  The return at 0x2f34 has v0 = table(sym(.bss)).
  The return at 0x2f40 has v0 = 0x0.

- `part_get_nasid` in `IP27/usr/cpu/sysgen/IP27boot/partition.o` at 0x2f48 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/partition.o`.
  Range: 0x2f48-0x2fe4 (156 bytes).
  It occupies 156 bytes.
  The `lh` at 0x2f50 loads 2 bytes from a1 (arg1 at entry) +0x0.
  The `lb` at 0x2f94 loads 1 byte from table(sym(.bss)) +0x3506.
  The `lw` at 0x2fa4 loads 4 bytes from table(sym(.bss)) +0x3504.
  The `sh` at 0x2fc8 stores 2 bytes to a1 (arg1 at entry) +0x0.
  The `beq` branch at 0x2f48 targets 0x2f54, is taken when a1 == 0, and falls through when a1 != 0.
  The `beq` branch at 0x2f60 targets 0x2fd0, is taken when at(?) >= 0x100 (signed), and falls through when at(?) < 0x100 (signed).
  The `beq` branch at 0x2f68 targets 0x2fd8 and is always taken.
  The `beq` branch at 0x2f7c targets 0x2fcc, is taken when a4(?) >= 0x100 (signed), and falls through when a4(?) < 0x100 (signed).
  The `bne` branch at 0x2f9c targets 0x2f70, is taken when v1(=[table(sym(.bss))+13574]:1) != a0, and falls through when v1(=[table(sym(.bss))+13574]:1) == a0.
  The `bltz` branch at 0x2fac targets 0x2fbc, is taken when t1(=([table(sym(.bss))+13572] << 0x8)) < 0 (signed), and falls through when t1(=([table(sym(.bss))+13572] << 0x8)) >= 0 (signed).
  The `bgezl` branch at 0x2fb4 targets 0x2f74, is taken when a7(=([table(sym(.bss))+13572] << 0x9)) >= 0 (signed), and falls through when a7(=([table(sym(.bss))+13572] << 0x9)) < 0 (signed); its branch-likely delay slot `dsra32 a4,a5,0x10` at 0x2fb8 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x2fbc targets 0x2fd0, is taken when a1 == 0, and falls through when a1 != 0.
  The `beq` branch at 0x2fdc targets 0x2f88 and is always taken.
  The return at 0x2fc4 has v0 = table(sym(.bss))+13568.
  The return at 0x2fd0 has v0 = one of 0x0, table(sym(.bss))+13568.

- `part_poison_xppage` in `IP27/usr/cpu/sysgen/IP27boot/partition.o` at 0x2fe4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/partition.o`.
  Range: 0x2fe4-0x3118 (308 bytes).
  It occupies 308 bytes.
  The `lw` at 0x3004 loads 4 bytes from a0 (arg0 at entry) +0x5c.
  The `ll` at 0x302c loads 4 bytes from a0 (arg0 at entry) +0x5c.
  The `sc` at 0x3034 stores 4 bytes to a0 (arg0 at entry) +0x5c.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x30, including `ld` at 0x3048, `ld` at 0x30c0.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x38, including `ld` at 0x304c, `ld` at 0x30c4.
  The `sw` at 0x305c stores 4 bytes to a0 (arg0 at entry) +0x5c.
  The `jal` at 0x2ffc calls bitlock_acquire_32bit with a0=a0+92, a1=0x1, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x3088 calls splhi with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x309c calls bitlock_set with a0=?, a1=0x8000000, a2=0x400000, a3=?.
  The `jal` at 0x30a4 calls splx with a0=ret(splhi), a1=?, a2=?, a3=?.
  The `jal` at 0x3108 calls bte_poison_range with a0=?, a1=([a0+48]:8 << 0x0), a2=?, a3=0x3fc0000, a4=0xfffffffffe800000, a5=0xffffffff.
  The `beq` branch at 0x3014 targets 0x3048, is taken when (v0(=[a0+92]) & 0x8) == 0, and falls through when (v0(=[a0+92]) & 0x8) != 0.
  The `beql` branch at 0x3038 targets 0x302c, is taken when (v0(=[a0+92]) & a0(=-0x2)) == 0, and falls through when (v0(=[a0+92]) & a0(=-0x2)) != 0; its branch-likely delay slot `nop` at 0x303c runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x307c targets 0x30c8, is taken when a2(=[a0+56]:8) >= a3(?) (unsigned), and falls through when a2(=[a0+56]:8) < a3(?) (unsigned).
  The `bne` branch at 0x30b8 targets 0x3088, is taken when s1(?) < a4(?) (unsigned), and falls through when s1(?) >= a4(?) (unsigned).
  The `beq` branch at 0x3110 targets 0x3020 and is always taken.
  The return at 0x3040 has v0 = [a0+92].

- `part_poison_page` in `IP27/usr/cpu/sysgen/IP27boot/partition.o` at 0x3118 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/partition.o`.
  Range: 0x3118-0x3178 (96 bytes).
  It occupies 96 bytes.
  The `jal` at 0x314c calls part_find_page with a0=?, a1=?, a2=0x3fc0000, a3=0xfffffffffe800000.
  The `jal` at 0x3158 calls part_poison_xppage with a0=ret(part_find_page), a1=?, a2=?, a3=?.
  The `jal` at 0x3160 calls part_release_page with a0=ret(part_find_page), a1=?, a2=?, a3=?.
  The return at 0x3170 has v0 = ret(part_release_page).

- `part_error_handler` in `IP27/usr/cpu/sysgen/IP27boot/partition.o` at 0x3178 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/partition.o`.
  Range: 0x3178-0x3434 (700 bytes).
  It occupies 700 bytes.
  4 such `lw` accesses load 4 bytes from ret(part_find_page) +0x5c, including `lw` at 0x31b0, `lw` at 0x31e8, `lw` at 0x3210.
  The `lh` at 0x31c0 loads 2 bytes from ret(part_find_page) +0x42.
  The `lh` at 0x31c4 loads 2 bytes from abs 0xffffffffffffc420.
  2 such `ll` accesses load 4 bytes from ret(part_find_page) +0x5c, including `ll` at 0x3224, `ll` at 0x33c8.
  2 such `sc` accesses store 4 bytes to ret(part_find_page) +0x5c, including `sc` at 0x322c, `sc` at 0x33d0.
  The `ld` at 0x32d4 loads 8 bytes from table(sym(.rodata)) +0x0.
  2 such `ld` accesses load 8 bytes from ret(part_find_page) +0x48, including `ld` at 0x3368, `ld` at 0x33e4.
  2 such `sw` accesses store 4 bytes to ret(part_find_page) +0x5c, including `sw` at 0x3370, `sw` at 0x3388.
  The `jal` at 0x3198 calls part_find_page with a0=a1 at entry (arg1), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x31e0 calls splerr with a0=?, a1=0x3, a2=?, a3=?.
  The `jal` at 0x3208 calls bitlock_acquire_32bit with a0=ret(part_find_page)+92, a1=0x1, a2=?, a3=?.
  The `jal` at 0x3238 calls splx with a0=?, a1=?, a2=?, a3=?, a5=[ret(part_find_page)+92], a6=-0x2.
  The `jal` at 0x3244 calls part_release_page with a0=ret(part_find_page), a1=?, a2=?, a3=?.
  The `jal` at 0x32a8 calls get_dir_ent with a0=a1 at entry (arg1), a1=sp-128, a2=sp-120, a3=sp-112.
  The `jal` at 0x338c calls part_release_page with a0=ret(part_find_page), a1=[ret(part_find_page)+92], a2=?, a3=?.
  The `jal` at 0x339c calls part_release_page with a0=ret(part_find_page), a1=0x3, a2=?, a3=?.
  The `jal` at 0x33dc calls splx with a0=?, a1=([ret(part_find_page)+92] | 0x4), a2=?, a3=?, a7=[ret(part_find_page)+72]:8.
  The `jalr` at 0x33f0 calls (unknown callee) with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=?.
  The `jal` at 0x33f8 calls splerr with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x3408 calls bitlock_acquire_32bit with a0=ret(part_find_page)+92, a1=0x1, a2=?, a3=?.
  The `jal` at 0x3424 calls cmn_err with a0=0x0, a1=sym(.rodata), a2=a1 at entry (arg1), a3=?.
  The `beq` branch at 0x31a8 targets 0x326c, is taken when v0(=ret(part_find_page)) == 0, and falls through when v0(=ret(part_find_page)) != 0.
  The `beq` branch at 0x31b8 targets 0x31d0, is taken when (a1(=[ret(part_find_page)+92]) & 0x2) == 0, and falls through when (a1(=[ret(part_find_page)+92]) & 0x2) != 0.
  The `beq` branch at 0x31c8 targets 0x338c, is taken when v0(=[-0x3be0]:2) == v1(=[ret(part_find_page)+66]:2), and falls through when v0(=[-0x3be0]:2) != v1(=[ret(part_find_page)+66]:2).
  The `beq` branch at 0x31d0 targets 0x31e0, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x31d8 targets 0x339c, is taken when s4(=a2) == a1(=0x3), and falls through when s4(=a2) != a1(=0x3).
  The `beq` branch at 0x31f8 targets 0x328c, is taken when (a2(=[ret(part_find_page)+92]) & 0x10) == 0, and falls through when (a2(=[ret(part_find_page)+92]) & 0x10) != 0.
  The `beq` branch at 0x3218 targets 0x3368, is taken when (a1(=[ret(part_find_page)+92]) & 0x4) == 0, and falls through when (a1(=[ret(part_find_page)+92]) & 0x4) != 0.
  The `beql` branch at 0x3230 targets 0x3224, is taken when (a5(=[ret(part_find_page)+92]) & a6(=-0x2)) == 0, and falls through when (a5(=[ret(part_find_page)+92]) & a6(=-0x2)) != 0; its branch-likely delay slot `nop` at 0x3234 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x324c targets 0x33ac, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0x3258 targets 0x33b8, is taken when s0(?) == v0(=0x1), and falls through when s0(?) != v0(=0x1).
  The `beq` branch at 0x3260 targets 0x3360, is taken when s0(?) == t0(=0x2), and falls through when s0(?) != t0(=0x2).
  The `beq` branch at 0x328c targets 0x329c and is always taken.
  The `bne` branch at 0x3298 targets 0x3358 and is never taken: its condition can never hold for these operands, so execution always falls through.
  The `beq` branch at 0x32cc targets 0x3418, is taken when a2(?) >= 0x8 (unsigned), and falls through when a2(?) < 0x8 (unsigned).
  The `beq` branch at 0x3360 targets 0x3270 and is always taken.
  The `bne` branch at 0x3374 targets 0x33c0, is taken when a7(=[ret(part_find_page)+72]:8) != 0, and falls through when a7(=[ret(part_find_page)+72]:8) == 0.
  The `beq` branch at 0x3384 targets 0x3220 and is always taken.
  The `beq` branch at 0x3394 targets 0x326c and is always taken.
  The `beq` branch at 0x33a4 targets 0x326c and is always taken.
  The `beq` branch at 0x33b0 targets 0x3270 and is always taken.
  The `beq` branch at 0x33b8 targets 0x3270 and is always taken.
  The `beql` branch at 0x33d4 targets 0x33c8, is taken when (t1(=[ret(part_find_page)+92]) & t2(=-0x2)) == 0, and falls through when (t1(=[ret(part_find_page)+92]) & t2(=-0x2)) != 0; its branch-likely delay slot `nop` at 0x33d8 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x3410 targets 0x337c and is always taken.
  The `beq` branch at 0x342c targets 0x3298 and is always taken.
  The return at 0x3284 has v0 = one of 0x0, 0x1, 0x2, 0x3.
  The instructions from 0x3294 to 0x3294 are not reached by any path from the entry, and their branches are not listed.
  The instructions from 0x32e0 to 0x335c are not reached by any path from the entry, and their branches are not listed.
  The indirect jump at 0x32d8 uses a jump table whose successors are unresolved.

- `part_register_page` in `IP27/usr/cpu/sysgen/IP27boot/partition.o` at 0x3434 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/partition.o`.
  Range: 0x3434-0x3468 (52 bytes).
  It occupies 52 bytes.
  The `jal` at 0x3454 calls part_new_page with a0=0x0, a1=a0 at entry (arg0), a2=a1 at entry (arg1), a3=0x10, a4=a2 at entry (arg2).
  The return at 0x3460 has v0 = ret(part_new_page).

- `part_unregister_page` in `IP27/usr/cpu/sysgen/IP27boot/partition.o` at 0x3468 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/partition.o`.
  Range: 0x3468-0x349c (52 bytes).
  It occupies 52 bytes.
  The `jal` at 0x3470 calls part_find_page with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x347c calls part_release_page with a0=ret(part_find_page), a1=?, a2=?, a3=?.
  The `jal` at 0x3484 calls part_release_page with a0=ret(part_find_page), a1=?, a2=?, a3=?.
  The return at 0x3494 has v0 = ret(part_release_page).

- `part_call_activate_handlers` in `IP27/usr/cpu/sysgen/IP27boot/partition.o` at 0x349c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/partition.o`.
  Range: 0x349c-0x3680 (484 bytes).
  It occupies 484 bytes.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0xc, including `sw` at 0x34d8, `sw` at 0x361c.
  The `ld` at 0x34e0 loads 8 bytes from a0 (arg0 at entry) +0xc8.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x20, including `lw` at 0x3508, `lw` at 0x3610.
  The `ld` at 0x350c loads 8 bytes from abs 0xffffffffffffc020.
  3 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0xc8, including `sd` at 0x3514, `sd` at 0x3578, `sd` at 0x364c.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x10, including `lw` at 0x3528, `lw` at 0x3640.
  5 such `ld` accesses load 8 bytes from ?, including `ld` at 0x3558, `ld` at 0x35c8, `ld` at 0x35cc.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x10, including `sw` at 0x35c0, `sw` at 0x35dc.
  The `lb` at 0x35f8 loads 1 byte from a0 (arg0 at entry) +0x14.
  The `jal` at 0x34bc calls mutex_lock with a0=sym(.bss), a1=0x19, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x34d0 calls mutex_spinlock with a0=a0+8, a1=?, a2=?, a3=?.
  The `jal` at 0x357c calls mutex_spinunlock with a0=a0+8, a1=ret(mutex_spinlock), a2=?, a3=?.
  The `jal` at 0x3584 calls mutex_unlock with a0=sym(.bss), a1=?, a2=?, a3=?.
  The `jal` at 0x35e0 calls mutex_spinunlock with a0=a0+8, a1=ret(mutex_spinlock), a2=?, a3=?.
  The `jal` at 0x35e8 calls mutex_unlock with a0=sym(.bss), a1=?, a2=?, a3=?.
  The `jalr` at 0x35f4 calls (unknown callee) with a0=[a0+20]:1, a1=?, a2=?, a3=?.
  The `jal` at 0x3600 calls mutex_lock with a0=sym(.bss), a1=0x19, a2=?, a3=?.
  The `jal` at 0x3608 calls mutex_spinlock with a0=a0+8, a1=?, a2=?, a3=?.
  The `jal` at 0x3650 calls mutex_spinunlock with a0=a0+8, a1=ret(mutex_spinlock), a2=?, a3=?, a4=[a0+32], a7=0x5.
  The `jal` at 0x3658 calls mutex_unlock with a0=sym(.bss), a1=?, a2=?, a3=?.
  The `jal` at 0x3668 calls mutex_spinunlock with a0=a0+8, a1=ret(mutex_spinlock), a2=?, a3=?, a5=0x5.
  The `jal` at 0x3670 calls mutex_unlock with a0=sym(.bss), a1=?, a2=?, a3=?.
  The `bne` branch at 0x3500 targets 0x3668, is taken when at(=[a0+200]:8) != 0, and falls through when at(=[a0+200]:8) == 0.
  The `beq` branch at 0x3510 targets 0x3524, is taken when a4(=[a0+32]) == s7(=0x6), and falls through when a4(=[a0+32]) != s7(=0x6).
  The `beq` branch at 0x3518 targets 0x3528, is taken when a4(=[a0+32]) == a0(=0x4), and falls through when a4(=[a0+32]) != a0(=0x4).
  The `bne` branch at 0x3520 targets 0x3578, is taken when a4(=[a0+32]) != a5(=0x5), and falls through when a4(=[a0+32]) == a5(=0x5).
  The `beq` branch at 0x3530 targets 0x3578, is taken when s1(=[a0+16]) >= s4(=[sym(.sdata)]) (signed), and falls through when s1(=[a0+16]) < s4(=[sym(.sdata)]) (signed).
  The `bltz` branch at 0x3544 targets 0x355c, is taken when a5(?) < 0 (signed), and falls through when a5(?) >= 0 (signed).
  The `beq` branch at 0x3554 targets 0x354c, is taken when a5(?) >= a4(?) (signed), and falls through when a5(?) < a4(?) (signed).
  The `bne` branch at 0x3564 targets 0x35cc, is taken when s3(?) < s4(=[sym(.sdata)]) (signed), and falls through when s3(?) >= s4(=[sym(.sdata)]) (signed).
  The `bne` branch at 0x3570 targets 0x353c, is taken when a3(?) != 0, and falls through when a3(?) == 0.
  The `beq` branch at 0x35c4 targets 0x3644, is taken when s1(?) >= s4(=[sym(.sdata)]) (signed), and falls through when s1(?) < s4(=[sym(.sdata)]) (signed).
  The `beq` branch at 0x35d4 targets 0x35bc, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `beq` branch at 0x3620 targets 0x3638, is taken when a4(=[a0+32]) == s7(=0x6), and falls through when a4(=[a0+32]) != s7(=0x6).
  The `beq` branch at 0x3628 targets 0x3638, is taken when a4(=[a0+32]) == s8(=0x4), and falls through when a4(=[a0+32]) != s8(=0x4).
  The `bne` branch at 0x3630 targets 0x364c, is taken when a4(=[a0+32]) != a7(=0x5), and falls through when a4(=[a0+32]) == a7(=0x5).
  The `bne` branch at 0x3638 targets 0x35cc, is taken when a0(?) != 0, and falls through when a0(?) == 0.
  The `beq` branch at 0x3644 targets 0x3568 and is always taken.
  The `beq` branch at 0x3660 targets 0x3590 and is always taken.
  The `beq` branch at 0x3678 targets 0x3590 and is always taken.
  The return at 0x35b4 has v0 = ret(mutex_unlock).

- `part_activate_thread_setup` in `IP27/usr/cpu/sysgen/IP27boot/partition.o` at 0x3680 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/partition.o`.
  Range: 0x3680-0x36a4 (36 bytes).
  It occupies 36 bytes.
  The `jal` at 0x3688 calls part_call_activate_handlers with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x3690 calls xthread_exit with a0=?, a1=?, a2=?, a3=?.
  The return at 0x369c has v0 = ret(xthread_exit).

- `part_call_deactivate_handlers` in `IP27/usr/cpu/sysgen/IP27boot/partition.o` at 0x36a4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/partition.o`.
  Range: 0x36a4-0x3758 (180 bytes).
  It occupies 180 bytes.
  The `sw` at 0x36d8 stores 4 bytes to a0 (arg0 at entry) +0xc.
  The `lw` at 0x36e0 loads 4 bytes from a0 (arg0 at entry) +0x10.
  The `sw` at 0x36e4 stores 4 bytes to a0 (arg0 at entry) +0x10.
  The `lb` at 0x3704 loads 1 byte from a0 (arg0 at entry) +0x14.
  3 such `ld` accesses load 8 bytes from ?, including `ld` at 0x370c, `ld` at 0x3718, `ld` at 0x3728.
  The `jal` at 0x36c0 calls mutex_lock with a0=sym(.bss), a1=0x19, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x36d0 calls mutex_spinlock with a0=a0+8, a1=?, a2=?, a3=?.
  The `jal` at 0x36e8 calls mutex_spinunlock with a0=a0+8, a1=ret(mutex_spinlock), a2=?, a3=?.
  The `jalr` at 0x3700 calls (unknown callee) with a0=[a0+20]:1, a1=?, a2=?, a3=?.
  The `jal` at 0x3738 calls mutex_unlock with a0=sym(.bss), a1=?, a2=?, a3=?.
  The `bgtz` branch at 0x36f0 targets 0x3718, is taken when s1(=[a0+16]) > 0 (signed), and falls through when s1(=[a0+16]) <= 0 (signed).
  The `beq` branch at 0x36f8 targets 0x3734 and is always taken.
  The `blez` branch at 0x3710 targets 0x3734, is taken when a1(?) <= 0 (signed), and falls through when a1(?) > 0 (signed).
  The `bne` branch at 0x371c targets 0x3700, is taken when a2(?) != 0, and falls through when a2(?) == 0.
  The `bgtz` branch at 0x372c targets 0x3718, is taken when a2(?) > 0 (signed), and falls through when a2(?) <= 0 (signed).
  The return at 0x3750 has v0 = ret(mutex_unlock).

- `part_register_handlers` in `IP27/usr/cpu/sysgen/IP27boot/partition.o` at 0x3758 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/partition.o`.
  Range: 0x3758-0x38ec (404 bytes).
  It occupies 404 bytes.
  The `sd` at 0x3780 stores 8 bytes to ret(kmem_alloc) +0x8.
  The `sd` at 0x378c stores 8 bytes to ret(kmem_alloc) +0x10.
  The `sd` at 0x3794 stores 8 bytes to ret(kmem_alloc) +0x0.
  The `ld` at 0x37c0 loads 8 bytes from [sym(.sdata)+8]:8 +0x0.
  The `ld` at 0x37d0 loads 8 bytes from ?.
  The `sd` at 0x37dc stores 8 bytes to ?.
  The `sw` at 0x3848 stores 4 bytes to ret(part_get) +0xc.
  The `lw` at 0x384c loads 4 bytes from ret(part_get) +0x20.
  The `lw` at 0x3868 loads 4 bytes from ret(part_get) +0x10.
  The `lw` at 0x3880 loads 4 bytes from ret(part_get) +0xc.
  The `jal` at 0x3778 calls kmem_alloc with a0=0x18, a1=0x0, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x3798 calls mutex_lock with a0=sym(.bss), a1=0x19, a2=?, a3=?.
  The `jal` at 0x37ec calls mutex_unlock with a0=sym(.bss), a1=[sym(.sdata)]+1, a2=?, a3=?.
  The `jal` at 0x3808 calls mutex_spinunlock with a0=ret(part_get)+8, a1=?, a2=?, a3=?.
  The `jal` at 0x3828 calls part_get with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x3838 calls mutex_spinlock with a0=ret(part_get)+8, a1=?, a2=?, a3=?.
  The `jal` at 0x38b0 calls mutex_spinunlock with a0=ret(part_get)+8, a1=ret(mutex_spinlock), a2=?, a3=?, a4=[ret(part_get)+32].
  The `jal` at 0x38d4 calls xthread_create with a0=ret(part_get), a1=0x0, a2=0x4000, a3=0x1, a4=[sym(partition_pri)], a5=0x3000, a6=sym(part_activate_thread_setup), a7=ret(part_get).
  The `beq` branch at 0x37b8 targets 0x38e4, is taken when a1(=[sym(.sdata)+8]:8) == 0, and falls through when a1(=[sym(.sdata)+8]:8) != 0.
  The `beq` branch at 0x37c4 targets 0x37dc, is taken when a0(=[[sym(.sdata)+8]:8]:8) == 0, and falls through when a0(=[[sym(.sdata)+8]:8]:8) != 0.
  The `bne` branch at 0x37d4 targets 0x37cc, is taken when a0(?) != 0, and falls through when a0(?) == 0.
  The `beq` branch at 0x3800 targets 0x3824 and is always taken.
  The `beq` branch at 0x3820 targets 0x3884, is taken when s1(?) >= 0x40 (signed), and falls through when s1(?) < 0x40 (signed).
  The `beq` branch at 0x3844 targets 0x3808, is taken when s0(=ret(part_get)) == 0, and falls through when s0(=ret(part_get)) != 0.
  The `beq` branch at 0x3850 targets 0x3868, is taken when a4(=[ret(part_get)+32]) == s5(=0x6), and falls through when a4(=[ret(part_get)+32]) != s5(=0x6).
  The `beq` branch at 0x3858 targets 0x3868, is taken when a4(=[ret(part_get)+32]) == s6(=0x4), and falls through when a4(=[ret(part_get)+32]) != s6(=0x4).
  The `bne` branch at 0x3860 targets 0x3808, is taken when a4(=[ret(part_get)+32]) != s7(=0x5), and falls through when a4(=[ret(part_get)+32]) == s7(=0x5).
  The `beq` branch at 0x386c targets 0x38b0, is taken when t8(=[ret(part_get)+16]) == s4(=[sym(.sdata)]), and falls through when t8(=[ret(part_get)+16]) != s4(=[sym(.sdata)]).
  The `bne` branch at 0x3874 targets 0x3810, is taken when s3(=one of 0x0, 0x1) != 0, and falls through when s3(=one of 0x0, 0x1) == 0.
  The `beq` branch at 0x387c targets 0x3808 and is always taken.
  The `beq` branch at 0x38dc targets 0x3874 and is always taken.
  The `beq` branch at 0x38e4 targets 0x37e0 and is always taken.
  The return at 0x38a8 has v0 = ?.

- `part_operation` in `IP27/usr/cpu/sysgen/IP27boot/partition.o` at 0x38ec (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/partition.o`.
  Range: 0x38ec-0x3b5c (624 bytes).
  It occupies 624 bytes.
  The `lw` at 0x39ac loads 4 bytes from ?.
  5 such `sd` accesses store 8 bytes to a4 (arg4 at entry) +0x0, including `sd` at 0x39d0, `sd` at 0x3a6c, `sd` at 0x3a98.
  The `lh` at 0x3a1c loads 2 bytes from ?.
  The `jal` at 0x39f4 calls copyout with a0=sp-96, a1=?, a2=0x28, a3=?, a7=0x1.
  The `jal` at 0x3a38 calls copyout with a0=?, a1=?, a2=0x1c, a3=?.
  The `jal` at 0x3acc calls part_id with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a7=0x1.
  The `jal` at 0x3af4 calls cap_able with a0=0x2000000000, a1=0x4, a2=a2 at entry (arg2), a3=a3 at entry (arg3), a6=0x16, a7=0x1.
  The `jal` at 0x3b0c calls cap_able with a0=0x2000000000, a1=0x4, a2=a2 at entry (arg2), a3=a3 at entry (arg3), a6=0x16, a7=0x1.
  The `jal` at 0x3b24 calls part_id with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x3b3c calls vsema with a0=sym(.bss), a1=?, a2=?, a3=?.
  The `jal` at 0x3b4c calls part_deactivate with a0=?, a1=?, a2=?, a3=?.
  The `beq` branch at 0x391c targets 0x3acc, is taken when a0 == a7(=0x1), and falls through when a0 != a7(=0x1).
  The `beq` branch at 0x3930 targets 0x398c, is taken when a0 == at(=0x3), and falls through when a0 != at(=0x3).
  The `beq` branch at 0x3948 targets 0x3a0c, is taken when a0 == v1(=0x2), and falls through when a0 != v1(=0x2).
  The `beq` branch at 0x3954 targets 0x3af0, is taken when a0 == a1(=0x4), and falls through when a0 != a1(=0x4).
  The `beq` branch at 0x395c targets 0x3b0c, is taken when a0 == v0(=0x5), and falls through when a0 != v0(=0x5).
  The `beq` branch at 0x39b0 targets 0x39dc, is taken when a2(?) == a1(=0x6), and falls through when a2(?) != a1(=0x6).
  The `bne` branch at 0x39c8 targets 0x3998, is taken when s0(?) < 0x40 (signed), and falls through when s0(?) >= 0x40 (signed).
  The `beq` branch at 0x39d4 targets 0x3964 and is always taken.
  The `bltz` branch at 0x39e4 targets 0x3a9c, is taken when s1(?) < 0 (signed), and falls through when s1(?) >= 0 (signed).
  The `beq` branch at 0x39fc targets 0x3aa4, is taken when v0(=ret(copyout)) == 0, and falls through when v0(=ret(copyout)) != 0.
  The `beq` branch at 0x3a04 targets 0x3964 and is always taken.
  The `beq` branch at 0x3a20 targets 0x3a54, is taken when a2(?) == a1(=-0x1), and falls through when a2(?) != a1(=-0x1).
  The `bltz` branch at 0x3a2c targets 0x3a50, is taken when s1(?) < 0 (signed), and falls through when s1(?) >= 0 (signed).
  The `beq` branch at 0x3a40 targets 0x3a78, is taken when v0(=ret(copyout)) == 0, and falls through when v0(=ret(copyout)) != 0.
  The `beq` branch at 0x3a48 targets 0x3964 and is always taken.
  The `bne` branch at 0x3a64 targets 0x3a10, is taken when s0(?) < 0x100 (signed), and falls through when s0(?) >= 0x100 (signed).
  The `beq` branch at 0x3a70 targets 0x3964 and is always taken.
  The `bne` branch at 0x3a8c targets 0x3a0c, is taken when s0(?) < 0x100 (signed), and falls through when s0(?) >= 0x100 (signed).
  The `beq` branch at 0x3a94 targets 0x3a70 and is always taken.
  The `beq` branch at 0x3a9c targets 0x39b8 and is always taken.
  The `bne` branch at 0x3abc targets 0x3994, is taken when s0(?) < 0x40 (signed), and falls through when s0(?) >= 0x40 (signed).
  The `beq` branch at 0x3ac4 targets 0x39d4 and is always taken.
  The `beq` branch at 0x3ae8 targets 0x3964 and is always taken.
  The `bne` branch at 0x3afc targets 0x3b24, is taken when v0(=ret(cap_able)) != 0, and falls through when v0(=ret(cap_able)) == 0.
  The `beq` branch at 0x3b04 targets 0x3964 and is always taken.
  The `bne` branch at 0x3b14 targets 0x3b3c, is taken when v0(=ret(cap_able)) != 0, and falls through when v0(=ret(cap_able)) == 0.
  The `beq` branch at 0x3b1c targets 0x3964 and is always taken.
  The `bne` branch at 0x3b2c targets 0x3b4c, is taken when v0(=ret(part_id)) != s1(=a1), and falls through when v0(=ret(part_id)) == s1(=a1).
  The `beq` branch at 0x3b34 targets 0x3964 and is always taken.
  The `beq` branch at 0x3b44 targets 0x3964 and is always taken.
  The `beq` branch at 0x3b54 targets 0x3964 and is always taken.
  The return at 0x3984 has v0 = one of 0x16, 0x0, 0xe, 0x3f0, 0x1.

- `part_page_dump` in `IP27/usr/cpu/sysgen/IP27boot/partition.o` at 0x3b5c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/partition.o`.
  Range: 0x3b5c-0x3c64 (264 bytes).
  It occupies 264 bytes.
  The `ld` at 0x3b84 loads 8 bytes from sym(.bss) +0x8.
  7 such `lw` accesses load 4 bytes from ?, including `lw` at 0x3b90, `lw` at 0x3b98, `lw` at 0x3bb0.
  4 such `ld` accesses load 8 bytes from ?, including `ld` at 0x3b94, `ld` at 0x3ba0, `ld` at 0x3ba4.
  The `lb` at 0x3b9c loads 1 byte from ?.
  The `lh` at 0x3be0 loads 2 bytes from ?.
  The `jalr` at 0x3b78 calls (unknown callee) with a0=sym(.rodata), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x3ba8 calls (unknown callee) with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jalr` at 0x3bc8 calls (unknown callee) with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jalr` at 0x3be4 calls (unknown callee) with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jalr` at 0x3bfc calls (unknown callee) with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jalr` at 0x3c14 calls (unknown callee) with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jalr` at 0x3c2c calls (unknown callee) with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jalr` at 0x3c38 calls (unknown callee) with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `beq` branch at 0x3b88 targets 0x3c4c, is taken when at(=[sym(.bss)+8]:8) == 0, and falls through when at(=[sym(.bss)+8]:8) != 0.
  The `beq` branch at 0x3bb4 targets 0x3c34, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x3bbc targets 0x3bd8, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0x3bd8 targets 0x3bf4, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0x3bf4 targets 0x3c08, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0x3c0c targets 0x3c20, is taken when (a1(?) & 0x8) == 0, and falls through when (a1(?) & 0x8) != 0.
  The `beq` branch at 0x3c24 targets 0x3c38, is taken when (a1(?) & 0x10) == 0, and falls through when (a1(?) & 0x10) != 0.
  The `bne` branch at 0x3c44 targets 0x3b90, is taken when s0(?) != 0, and falls through when s0(?) == 0.
  The return at 0x3c5c has v0 = ret(?).

- `part_dump_partition` in `IP27/usr/cpu/sysgen/IP27boot/partition.o` at 0x3c64 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/partition.o`.
  Range: 0x3c64-0x4088 (1060 bytes).
  It occupies 1060 bytes.
  4 such `lb` accesses load 1 byte from a1 (arg1 at entry) +0x14, including `lb` at 0x3c7c, `lb` at 0x3cb4, `lb` at 0x3d30.
  The `lw` at 0x3ca8 loads 4 bytes from a1 (arg1 at entry) +0x20.
  The `lw` at 0x3cac loads 4 bytes from a1 (arg1 at entry) +0x10.
  The `ld` at 0x3cc4 loads 8 bytes from (sym(.data) + ([a1+32] << 0x3)) +0x0.
  The `ld` at 0x3cc8 loads 8 bytes from a1 (arg1 at entry) +0xc8.
  2 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x5c, including `lw` at 0x3cdc, `lw` at 0x4010.
  The `lw` at 0x3ce4 loads 4 bytes from a1 (arg1 at entry) +0x58.
  The `ld` at 0x3cf0 loads 8 bytes from a1 (arg1 at entry) +0x28.
  5 such `ld` accesses load 8 bytes from ?, including `ld` at 0x3d40, `ld` at 0x3d88, `ld` at 0x3d94.
  The `ld` at 0x3da8 loads 8 bytes from a1 (arg1 at entry) +0x48.
  The `ld` at 0x3dac loads 8 bytes from a1 (arg1 at entry) +0x40.
  The `lw` at 0x3db8 loads 4 bytes from a1 (arg1 at entry) +0x84.
  The `lw` at 0x3dbc loads 4 bytes from a1 (arg1 at entry) +0x80.
  The `lw` at 0x3dc0 loads 4 bytes from a1 (arg1 at entry) +0x70.
  2 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x6c, including `lw` at 0x3dc4, `lw` at 0x3de0.
  The `lw` at 0x3dc8 loads 4 bytes from a1 (arg1 at entry) +0x64.
  2 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x60, including `lw` at 0x3dcc, `lw` at 0x3de4.
  The `lw` at 0x3dd8 loads 4 bytes from a1 (arg1 at entry) +0x74.
  The `lw` at 0x3ddc loads 4 bytes from a1 (arg1 at entry) +0x7c.
  The `lw` at 0x3de8 loads 4 bytes from a1 (arg1 at entry) +0x78.
  The `lw` at 0x3df0 loads 4 bytes from a1 (arg1 at entry) +0x68.
  The `ld` at 0x3e10 loads 8 bytes from a1 (arg1 at entry) +0xa0.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0x3e34, `lw` at 0x3f14.
  2 such `ld` accesses load 8 bytes from a1 (arg1 at entry) +0x18, including `ld` at 0x3e9c, `ld` at 0x3eb4.
  The `lb` at 0x3f74 loads 1 byte from ?.
  The `ld` at 0x4024 loads 8 bytes from table(sym(.data)) +0x70.
  The `lbu` at 0x4028 loads 1 byte from a1 (arg1 at entry) +0x15.
  The `ld` at 0x4048 loads 8 bytes from sym(.bss) +0x5108.
  The `jal` at 0x3c84 calls part_get_var with a0=[a1+20]:1, a1=0x0, a2=sp-96, a3=a3 at entry (arg3).
  The `jalr` at 0x3cc0 calls (unknown callee) with a0=sym(.rodata), a1=[a1+20]:1, a2=[(sym(.data) + ([a1+32] << 0x3))]:8, a3=?, a4=[a1+16].
  The `jalr` at 0x3cd4 calls (unknown callee) with a0=sym(.rodata), a1=[a1+200]:8, a2=?, a3=?.
  The `jalr` at 0x3ce8 calls (unknown callee) with a0=sym(.rodata), a1=a1+136, a2=[a1+88], a3=[a1+92].
  The `jalr` at 0x3cf4 calls (unknown callee) with a0=sym(.rodata), a1=[a1+40]:8, a2=?, a3=?.
  The `jalr` at 0x3d0c calls (unknown callee) with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jal` at 0x3d34 calls part_get_var with a0=[a1+20]:1, a1=?, a2=sp-96, a3=?.
  The `jalr` at 0x3d50 calls (unknown callee) with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jalr` at 0x3d60 calls (unknown callee) with a0=sym(.rodata), a1=?, a2=sp-96, a3=?.
  The `jalr` at 0x3d98 calls (unknown callee) with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jalr` at 0x3db0 calls (unknown callee) with a0=sym(.rodata), a1=[a1+64]:8, a2=[a1+72]:8, a3=table(sym(.bss)).
  The `jalr` at 0x3dd0 calls (unknown callee) with a0=sym(.rodata), a1=[a1+96], a2=[a1+100], a3=[a1+108], a4=[a1+112], a5=[a1+128], a6=[a1+132].
  The `jalr` at 0x3df4 calls (unknown callee) with a0=sym(.rodata), a1=[a1+104], a2=?, a3=[a1+120], a4=[a1+124], a5=[a1+116], a6=[a1+108].
  The `jalr` at 0x3e08 calls (unknown callee) with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jalr` at 0x3e48 calls (unknown callee) with a0=sym(.rodata), a1=?, a2=one of 0x20, 0x2a, a3=sym(.rodata).
  The `jalr` at 0x3e94 calls (unknown callee) with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jalr` at 0x3ea0 calls (unknown callee) with a0=sym(.rodata), a1=[a1+24]:8, a2=?, a3=?.
  The `jalr` at 0x3edc calls (unknown callee) with a0=sym(.rodata), a1=?, a2=?, a3=[a1+24]:8.
  The `jalr` at 0x3ef4 calls (unknown callee) with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jalr` at 0x3f3c calls (unknown callee) with a0=sym(.rodata), a1=?, a2=one of 0x41, 0x5f, a3=one of 0x42, 0x5f.
  The `jalr` at 0x3fc8 calls (unknown callee) with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jalr` at 0x4004 calls (unknown callee) with a0=sym(.rodata), a1=[a1+200]:8, a2=?, a3=?.
  The `jalr` at 0x402c calls (unknown callee) with a0=sym(.rodata), a1=[a1+21]:1, a2=?, a3=-0x1.
  The `beq` branch at 0x3c94 targets 0x3fe4, is taken when v0(=ret(part_get_var)) == 0, and falls through when v0(=ret(part_get_var)) != 0.
  The `beq` branch at 0x3ccc targets 0x4004, is taken when a1(=[a1+200]:8) == 0, and falls through when a1(=[a1+200]:8) != 0.
  The `beq` branch at 0x3d00 targets 0x3d20 and is always taken.
  The `beq` branch at 0x3d1c targets 0x3d60, is taken when s2(?) >= 0x5 (signed), and falls through when s2(?) < 0x5 (signed).
  The `bne` branch at 0x3d3c targets 0x3d08, is taken when v0(=ret(part_get_var)) != 0, and falls through when v0(=ret(part_get_var)) == 0.
  The `beq` branch at 0x3d58 targets 0x3d18 and is always taken.
  The `beq` branch at 0x3d6c targets 0x403c and is always taken.
  The `beq` branch at 0x3d80 targets 0x3da8, is taken when s2(?) >= 0x40 (signed), and falls through when s2(?) < 0x40 (signed).
  The `bne` branch at 0x3d8c targets 0x3d74, is taken when t9(?) != s1(=a1), and falls through when t9(?) == s1(=a1).
  The `beq` branch at 0x3da0 targets 0x3d78 and is always taken.
  The `beq` branch at 0x3e20 targets 0x3e90, is taken when s6(=a1+160) == s2(=[a1+160]:8), and falls through when s6(=a1+160) != s2(=[a1+160]:8).
  The `beq` branch at 0x3e28 targets 0x404c and is always taken.
  The `beq` branch at 0x3e70 targets 0x3e90, is taken when s6(=a1+160) == s2(?), and falls through when s6(=a1+160) != s2(?).
  The `bne` branch at 0x3e80 targets 0x3e30, is taken when t0(?) != 0, and falls through when t0(?) == 0.
  The `beq` branch at 0x3e88 targets 0x3e34 and is always taken.
  The `beq` branch at 0x3eb0 targets 0x3ec0 and is always taken.
  The `beq` branch at 0x3eb8 targets 0x3ef4, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0x3ecc targets 0x3eb8, is taken when (a3(=[a1+24]:8) & a2(?)) == 0, and falls through when (a3(=[a1+24]:8) & a2(?)) != 0.
  The `bne` branch at 0x3eec targets 0x3eb0, is taken when s2(?) < 0x40 (signed), and falls through when s2(?) >= 0x40 (signed).
  The `beq` branch at 0x3f0c targets 0x4070 and is always taken.
  The `beq` branch at 0x3f68 targets 0x3fa0, is taken when s2(?) >= 0x100 (signed), and falls through when s2(?) < 0x100 (signed).
  The `bne` branch at 0x3f80 targets 0x3f4c, is taken when t8(?) != t9(=[a1+20]:1), and falls through when t8(?) == t9(=[a1+20]:1).
  The `bne` branch at 0x3f88 targets 0x3f14 and is always taken.
  The `bne` branch at 0x3fa4 targets 0x4028, is taken when t8(=[sym(cell_enabled)]) != 0, and falls through when t8(=[sym(cell_enabled)]) == 0.
  The `bne` branch at 0x3ff4 targets 0x4014, is taken when a1(?) < 0x3 (unsigned), and falls through when a1(?) >= 0x3 (unsigned).
  The `beq` branch at 0x3ffc targets 0x3ca8 and is always taken.
  The `beq` branch at 0x400c targets 0x3ce0 and is always taken.
  The `beq` branch at 0x4020 targets 0x3ca8 and is always taken.
  The `beq` branch at 0x4034 targets 0x3fac and is always taken.
  The `beq` branch at 0x4044 targets 0x3d8c and is always taken.
  The `beq` branch at 0x4068 targets 0x3e7c and is always taken.
  The `beq` branch at 0x4080 targets 0x3f74 and is always taken.
  The return at 0x3fdc has v0 = ret(?).
  The instructions from 0x3f90 to 0x3f9c are not reached by any path from the entry, and their branches are not listed.

- `part_dump` in `IP27/usr/cpu/sysgen/IP27boot/partition.o` at 0x4088 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/partition.o`.
  Range: 0x4088-0x42dc (596 bytes).
  It occupies 596 bytes.
  5 such `ld` accesses load 8 bytes from ?, including `ld` at 0x40e4, `ld` at 0x40f0, `ld` at 0x40fc.
  The `lw` at 0x412c loads 4 bytes from ?.
  2 such `lb` accesses load 1 byte from ?, including `lb` at 0x41ac, `lb` at 0x4228.
  2 such `lh` accesses load 2 bytes from ?, including `lh` at 0x41b8, `lh` at 0x41bc.
  The `lb` at 0x42c8 loads 1 byte from sym(.bss) +0x3506.
  The `ld` at 0x42d8 loads 8 bytes from sym(.bss) +0x5108.
  The `jalr` at 0x40c0 calls (unknown callee) with a0=sym(.rodata), a1=[sym(partition_partid)]:1, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x40cc calls (unknown callee) with a0=sym(.rodata), a1=[sym(.sdata)], a2=?, a3=?.
  The `jalr` at 0x40f4 calls (unknown callee) with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jal` at 0x4138 calls part_dump_partition with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jalr` at 0x416c calls (unknown callee) with a0=sym(.rodata), a1=table(sym(.bss)), a2=?, a3=?.
  The `jalr` at 0x41c0 calls (unknown callee) with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jalr` at 0x41e8 calls (unknown callee) with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jalr` at 0x41f8 calls (unknown callee) with a0=sym(.rodata), a1=?, a2=?, a3=?, a5=table(sym(.bss)).
  The `jalr` at 0x4238 calls (unknown callee) with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jalr` at 0x4260 calls (unknown callee) with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jal` at 0x4270 calls part_page_dump with a0=a0 at entry (arg0), a1=?, a2=?, a3=?, a5=table(sym(.bss)).
  The `jalr` at 0x42a4 calls (unknown callee) with a0=sym(.rodata), a1=[sym(partition_partid)]:1, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0x40b4 targets 0x42a0, is taken when a1(=[sym(partition_partid)]:1) == s5(=-0x1), and falls through when a1(=[sym(partition_partid)]:1) != s5(=-0x1).
  The `beq` branch at 0x40dc targets 0x4108, is taken when at(=[sym(.sdata)+8]:8) == 0, and falls through when at(=[sym(.sdata)+8]:8) != 0.
  The `bne` branch at 0x4100 targets 0x40e4, is taken when s1(?) != 0, and falls through when s1(?) == 0.
  The `beq` branch at 0x4130 targets 0x4140, is taken when a2(?) == s4(=0x1), and falls through when a2(?) != s4(=0x1).
  The `bne` branch at 0x4164 targets 0x412c, is taken when s1(?) < 0x40 (signed), and falls through when s1(?) >= 0x40 (signed).
  The `beq` branch at 0x417c targets 0x42b4 and is always taken.
  The `beq` branch at 0x41a4 targets 0x41f8, is taken when s1(?) >= 0x100 (signed), and falls through when s1(?) < 0x100 (signed).
  The `beq` branch at 0x41b0 targets 0x4188, is taken when a2(?) == s5(=-0x1), and falls through when a2(?) != s5(=-0x1).
  The `bne` branch at 0x41e0 targets 0x4184, is taken when s6(=0x3) != a6(?), and falls through when s6(=0x3) == a6(?).
  The `beq` branch at 0x41f0 targets 0x4188 and is always taken.
  The `beq` branch at 0x4204 targets 0x42cc and is always taken.
  The `beq` branch at 0x421c targets 0x4270, is taken when s1(?) >= 0x40 (signed), and falls through when s1(?) < 0x40 (signed).
  The `beq` branch at 0x422c targets 0x4210, is taken when a2(?) == s5(=-0x1), and falls through when a2(?) != s5(=-0x1).
  The `bne` branch at 0x4258 targets 0x420c, is taken when s6(=0x3) != a6(?), and falls through when s6(=0x3) == a6(?).
  The `beq` branch at 0x4268 targets 0x4210 and is always taken.
  The `beq` branch at 0x42ac targets 0x427c and is always taken.
  The `beq` branch at 0x42c4 targets 0x41b0 and is always taken.
  The `beq` branch at 0x42d4 targets 0x4228 and is always taken.
  The return at 0x4298 has v0 = one of ret(part_page_dump), ret(?).

- `part_export_page` in `IP27/usr/cpu/sysgen/IP27boot/partition.o` at 0x42dc (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/partition.o`.
  Range: 0x42dc-0x4320 (68 bytes).
  It occupies 68 bytes.
  The `ld` at 0x42f0 loads 8 bytes from table(0x9200000001a00018) +0x0.
  The `jal` at 0x430c calls part_export_page_perms with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=one of 0x6, 0xc00000000006.
  The return at 0x4318 has v0 = ret(part_export_page_perms).

- `part_export_page_perms` in `IP27/usr/cpu/sysgen/IP27boot/partition.o` at 0x4320 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/partition.o`.
  Range: 0x4320-0x444c (300 bytes).
  It occupies 300 bytes.
  The `ld` at 0x4354 loads 8 bytes from table(0x9200000001a00018) +0x0.
  The `ld` at 0x43b4 loads 8 bytes from ret(part_get) +0x18.
  The `ld` at 0x43f4 loads 8 bytes from ?.
  The `sd` at 0x4414 stores 8 bytes to ?.
  The `jal` at 0x4370 calls part_get with a0=a2 at entry (arg2), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0x43c8 targets 0x4420, is taken when (t3(=[ret(part_get)+24]:8) & ra(?)) == 0, and falls through when (t3(=[ret(part_get)+24]:8) & ra(?)) != 0.
  The `beq` branch at 0x43d0 targets 0x4420, is taken when t9(?) == 0, and falls through when t9(?) != 0.
  The `beq` branch at 0x43ec targets 0x4404, is taken when a3(=one of 0x0, 0x1) == 0, and falls through when a3(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x43fc targets 0x4430, is taken when s0(=a3) == v1(?), and falls through when s0(=a3) != v1(?).
  The `bne` branch at 0x4418 targets 0x43e4, is taken when a1(?) < t1(=(a0 + a1)) (unsigned), and falls through when a1(?) >= t1(=(a0 + a1)) (unsigned).
  The `bne` branch at 0x4420 targets 0x43b4, is taken when t3(?) != 0, and falls through when t3(?) == 0.
  The `beq` branch at 0x4428 targets 0x4434 and is always taken.
  The return at 0x4444 has v0 = one of 0x0, 0x1.

- `part_unexport_page` in `IP27/usr/cpu/sysgen/IP27boot/partition.o` at 0x444c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/partition.o`.
  Range: 0x444c-0x4540 (244 bytes).
  It occupies 244 bytes.
  The `jal` at 0x44a0 calls is_POISONED_dir_state with a0=?, a1=?, a2=?, a3=0x0.
  The `jal` at 0x44c4 calls part_unexport_page_nocheck with a0=?, a1=?, a2=a2 at entry (arg2), a3=one of 0x0, 0x1.
  The `jal` at 0x4530 calls assfail with a0=sym(.rodata), a1=sym(.rodata), a2=0xe06, a3=a3 at entry (arg3).
  The `bne` branch at 0x4480 targets 0x4524, is taken when (a0 & 0x3fff) != 0, and falls through when (a0 & 0x3fff) == 0.
  The `beq` branch at 0x4488 targets 0x4518, is taken when s6(=a1) == 0, and falls through when s6(=a1) != 0.
  The `beq` branch at 0x4498 targets 0x44dc and is always taken.
  The `beq` branch at 0x44d4 targets 0x44ec, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `bne` branch at 0x44dc targets 0x44a0, is taken when s4(=a3) != 0, and falls through when s4(=a3) == 0.
  The `beq` branch at 0x44e4 targets 0x44b4 and is always taken.
  The `beq` branch at 0x451c targets 0x44ec and is always taken.
  The `beq` branch at 0x4538 targets 0x4488 and is always taken.
  The return at 0x4510 has v0 = one of ?, 0x0.

- `part_unexport_page_nocheck` in `IP27/usr/cpu/sysgen/IP27boot/partition.o` at 0x4540 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/partition.o`.
  Range: 0x4540-0x475c (540 bytes).
  It occupies 540 bytes.
  6 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x45bc, `lbu` at 0x45cc, `lbu` at 0x45e0.
  The `ld` at 0x4624 loads 8 bytes from table(0x9200000001a00018) +0x0.
  The `sd` at 0x4670 stores 8 bytes to ?.
  2 such `ld` accesses load 8 bytes from ret(part_get) +0x18, including `ld` at 0x4688, `ld` at 0x4758.
  The `ld` at 0x46b8 loads 8 bytes from ?.
  The `jal` at 0x4560 calls part_get with a0=a2 at entry (arg2), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0x4588 targets 0x45e4, is taken when s2(=a3) == 0, and falls through when s2(=a3) != 0.
  The `beq` branch at 0x45a4 targets 0x45e4, is taken when a5(=(a0 | 0xa000000000000000)) >= a4(=((a0 | 0xa000000000000000) + a1)) (unsigned), and falls through when a5(=(a0 | 0xa000000000000000)) < a4(=((a0 | 0xa000000000000000) + a1)) (unsigned).
  The `bne` branch at 0x45ac targets 0x45e8, is taken when a7(?) != 0, and falls through when a7(?) == 0.
  The `bne` branch at 0x45c0 targets 0x45e4, is taken when a4(=((a0 | 0xa000000000000000) + a1)-1) < a5(?) (unsigned), and falls through when a4(=((a0 | 0xa000000000000000) + a1)-1) >= a5(?) (unsigned).
  The `bne` branch at 0x45d0 targets 0x45e4, is taken when a4(=((a0 | 0xa000000000000000) + a1)-1) < a5(?) (unsigned), and falls through when a4(=((a0 | 0xa000000000000000) + a1)-1) >= a5(?) (unsigned).
  The `beq` branch at 0x45dc targets 0x45b4, is taken when a4(=((a0 | 0xa000000000000000) + a1)-1) >= a5(?) (unsigned), and falls through when a4(=((a0 | 0xa000000000000000) + a1)-1) < a5(?) (unsigned).
  The `beq` branch at 0x463c targets 0x474c and is always taken.
  The `beq` branch at 0x4644 targets 0x4674, is taken when t8(?) == 0, and falls through when t8(?) != 0.
  The `beq` branch at 0x466c targets 0x464c, is taken when t1(=(a0 + a1)-1) >= a4(?) (unsigned), and falls through when t1(=(a0 + a1)-1) < a4(?) (unsigned).
  The `beq` branch at 0x4680 targets 0x46d0, is taken when t2(?) >= t3(=one of 0x10, 0x40) (signed), and falls through when t2(?) < t3(=one of 0x10, 0x40) (signed).
  The `bne` branch at 0x4690 targets 0x4644, is taken when (a3(=[ret(part_get)+24]:8) & a4(?)) != 0, and falls through when (a3(=[ret(part_get)+24]:8) & a4(?)) == 0.
  The `bne` branch at 0x4698 targets 0x4674, is taken when ra(?) != 0, and falls through when ra(?) == 0.
  The `bne` branch at 0x46a4 targets 0x4674, is taken when (t0(=[sym(region_mask)]:8) & a4(?)) != 0, and falls through when (t0(=[sym(region_mask)]:8) & a4(?)) == 0.
  The `beq` branch at 0x46c8 targets 0x4674 and is always taken.
  The `beq` branch at 0x46d0 targets 0x4730, is taken when s2(=a3) == 0, and falls through when s2(=a3) != 0.
  The `beq` branch at 0x46ec targets 0x4730, is taken when a5(=(a0 | 0xa000000000000000)) >= a4(=((a0 | 0xa000000000000000) + a1)) (unsigned), and falls through when a5(=(a0 | 0xa000000000000000)) < a4(=((a0 | 0xa000000000000000) + a1)) (unsigned).
  The `bne` branch at 0x46f4 targets 0x4734, is taken when v0(?) != 0, and falls through when v0(?) == 0.
  The `bne` branch at 0x470c targets 0x4730, is taken when a4(=((a0 | 0xa000000000000000) + a1)-1) < v0(?) (unsigned), and falls through when a4(=((a0 | 0xa000000000000000) + a1)-1) >= v0(?) (unsigned).
  The `bne` branch at 0x471c targets 0x4730, is taken when a4(=((a0 | 0xa000000000000000) + a1)-1) < v0(?) (unsigned), and falls through when a4(=((a0 | 0xa000000000000000) + a1)-1) >= v0(?) (unsigned).
  The `beq` branch at 0x4728 targets 0x4700, is taken when a4(=((a0 | 0xa000000000000000) + a1)-1) >= v0(?) (unsigned), and falls through when a4(=((a0 | 0xa000000000000000) + a1)-1) < v0(?) (unsigned).
  The `beq` branch at 0x4754 targets 0x468c and is always taken.
  The return at 0x4744 has v0 = ?.

- `part_get_var` in `IP27/usr/cpu/sysgen/IP27boot/partition.o` at 0x475c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/partition.o`.
  Range: 0x475c-0x47c8 (108 bytes).
  It occupies 108 bytes.
  The `ld` at 0x4778 loads 8 bytes from ret(part_get) +0x28.
  The `jal` at 0x4768 calls part_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x47ac calls _badaddr_val with a0=?, a1=0x8, a2=a2 at entry (arg2), a3=?, a4=-0x1, a5=[ret(part_get)+40]:8.
  The `beq` branch at 0x4770 targets 0x47b8, is taken when v0(=ret(part_get)) == 0, and falls through when v0(=ret(part_get)) != 0.
  The `beq` branch at 0x477c targets 0x47b8, is taken when a5(=[ret(part_get)+40]:8) == 0, and falls through when a5(=[ret(part_get)+40]:8) != 0.
  The return at 0x47c0 has v0 = one of -0x1, ret(_badaddr_val).

- `part_set_var` in `IP27/usr/cpu/sysgen/IP27boot/partition.o` at 0x47c8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/partition.o`.
  Range: 0x47c8-0x47dc (20 bytes).
  It occupies 20 bytes.
  The `sd` at 0x47d8 stores 8 bytes to ([sym(.sdata)+32]:8 + (a0 << 0x3)) +0x10.
  The return at 0x47d4 has v0 = (a0 << 0x3).

- `part_heartbeat` in `IP27/usr/cpu/sysgen/IP27boot/partition.o` at 0x47dc (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/partition.o`.
  Range: 0x47dc-0x4c3c (1120 bytes).
  It occupies 1120 bytes.
  The `ld` at 0x483c loads 8 bytes from [sym(.sdata)+32]:8 +0x18.
  The `sd` at 0x4854 stores 8 bytes to [sym(.sdata)+32]:8 +0x18.
  11 such `lw` accesses load 4 bytes from ?, including `lw` at 0x48d0, `lw` at 0x49b4, `lw` at 0x4a24.
  2 such `sw` accesses store 4 bytes to ?, including `sw` at 0x48d8, `sw` at 0x4b0c.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0x48f4, `ld` at 0x4928.
  2 such `sd` accesses store 8 bytes to ?, including `sd` at 0x4908, `sd` at 0x4a58.
  4 such `lb` accesses load 1 byte from ?, including `lb` at 0x4918, `lb` at 0x4954, `lb` at 0x4998.
  2 such `ld` accesses load 8 bytes from [sym(.sdata)+32]:8 +0x28, including `ld` at 0x4970, `ld` at 0x4ac0.
  The `sd` at 0x4a10 stores 8 bytes to [sym(.sdata)+32]:8 +0x10.
  The `lh` at 0x4a88 loads 2 bytes from ret(part_get_nasid) +0x0.
  The `sd` at 0x4aa0 stores 8 bytes to (([ret(part_get_nasid)]:2 << 0x20) + one of 0x92000000018000c8, 0x92000000018000d0) +0x0.
  The `lw` at 0x4aec loads 4 bytes from ret(part_get_nasid) +0x4.
  The `jal` at 0x4860 calls mutex_spinunlock with a0=?, a1=ret(mutex_spinlock), a2=?, a3=?.
  The `jal` at 0x48c8 calls mutex_spinlock with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x4914 calls part_get_var with a0=?, a1=0x1, a2=sp-160, a3=?.
  The `jal` at 0x4950 calls part_get_var with a0=?, a1=0x3, a2=sp-144, a3=?.
  The `jal` at 0x4994 calls part_get_var with a0=?, a1=0x0, a2=sp-152, a3=?.
  The `jal` at 0x4a0c calls timeout with a0=sym(part_heartbeat), a1=0x0, a2=[sym(.sdata)+24], a3=[sym(.sdata)+32]:8, a6=0x1.
  The `jal` at 0x4a20 calls mutex_spinunlock with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x4a60 calls mutex_spinunlock with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x4ae4 calls part_get_nasid with a0=?, a1=0x0, a2=?, a3=?.
  The `jal` at 0x4b08 calls sv_broadcast with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x4b20 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x4b2c calls mutex_spinunlock with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x4b34 calls part_deactivate with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x4b48 calls mutex_spinunlock with a0=?, a1=ret(mutex_spinlock), a2=?, a3=?.
  The `jal` at 0x4b5c calls cmn_err with a0=0x6, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x4b64 calls part_deactivate with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x4b7c calls cmn_err with a0=0x6, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x4b88 calls mutex_spinunlock with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x4b90 calls part_deactivate with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x4bac calls cmn_err with a0=0x6, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x4bb8 calls mutex_spinunlock with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x4bc0 calls part_deactivate with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x4be0 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x4bec calls mutex_spinunlock with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x4bf4 calls part_deactivate with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x4c0c calls cmn_err with a0=0x6, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x4c18 calls mutex_spinunlock with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x4c20 calls part_deactivate with a0=?, a1=?, a2=?, a3=?.
  The `beq` branch at 0x4850 targets 0x49dc, is taken when v0(=[sym(.sdata)+16]) == 0, and falls through when v0(=[sym(.sdata)+16]) != 0.
  The `beq` branch at 0x4858 targets 0x4c34 and is always taken.
  The `bne` branch at 0x489c targets 0x49d4, is taken when v0(=[sym(.sdata)+16]) < s0(?) (unsigned), and falls through when v0(=[sym(.sdata)+16]) >= s0(?) (unsigned).
  The `beq` branch at 0x48a4 targets 0x488c, is taken when t8(=[sym(partition_partid)]:1) == s0(?), and falls through when t8(=[sym(partition_partid)]:1) != s0(?).
  The `beq` branch at 0x48d4 targets 0x48f4, is taken when a2(?) == s3(=0x5), and falls through when a2(?) != s3(=0x5).
  The `beq` branch at 0x48dc targets 0x490c, is taken when a2(?) == s6(=0x4), and falls through when a2(?) != s6(=0x4).
  The `bne` branch at 0x48e4 targets 0x4860, is taken when a2(?) != s7(=0x6), and falls through when a2(?) == s7(=0x6).
  The `beq` branch at 0x48ec targets 0x4910 and is always taken.
  The `bne` branch at 0x4904 targets 0x4b44, is taken when t9(=[sym(.sdata)+28]) < t8(?) (unsigned), and falls through when t9(=[sym(.sdata)+28]) >= t8(?) (unsigned).
  The `bne` branch at 0x491c targets 0x4b18, is taken when v0(=ret(part_get_var)) != 0, and falls through when v0(=ret(part_get_var)) == 0.
  The `beq` branch at 0x492c targets 0x4990, is taken when ra(?) == at(?), and falls through when ra(?) != at(?).
  The `bne` branch at 0x4934 targets 0x4868, is taken when s4(?) != 0, and falls through when s4(?) == 0.
  The `bne` branch at 0x493c targets 0x4868, is taken when s8(?) != 0, and falls through when s8(?) == 0.
  The `bne` branch at 0x4944 targets 0x4868, is taken when v0(?) != 0, and falls through when v0(?) == 0.
  The `bne` branch at 0x4958 targets 0x4bd4, is taken when v0(=ret(part_get_var)) != 0, and falls through when v0(=ret(part_get_var)) == 0.
  The `beq` branch at 0x4960 targets 0x4a34, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `bne` branch at 0x4968 targets 0x4868, is taken when v1(?) != 0, and falls through when v1(?) == 0.
  The `beq` branch at 0x4978 targets 0x4a4c, is taken when a0(=[[sym(.sdata)+32]:8+40]:8) == a1(?), and falls through when a0(=[[sym(.sdata)+32]:8+40]:8) != a1(?).
  The `beq` branch at 0x4980 targets 0x4a4c, is taken when v0(=[sym(.sdata)+16]) == 0, and falls through when v0(=[sym(.sdata)+16]) != 0.
  The `beq` branch at 0x4988 targets 0x4ab4 and is always taken.
  The `bne` branch at 0x499c targets 0x4b74, is taken when v0(=ret(part_get_var)) != 0, and falls through when v0(=ret(part_get_var)) == 0.
  The `beq` branch at 0x49ac targets 0x4a20, is taken when a1(=0x2) == a2(?), and falls through when a1(=0x2) != a2(?).
  The `bne` branch at 0x49b8 targets 0x4ba4, is taken when a3(?) != s3(=0x5), and falls through when a3(?) == s3(=0x5).
  The `beq` branch at 0x49cc targets 0x4934 and is always taken.
  The `beq` branch at 0x4a2c targets 0x49c8 and is always taken.
  The `bne` branch at 0x4a38 targets 0x4c04, is taken when a6(?) != s3(=0x5), and falls through when a6(?) == s3(=0x5).
  The `beq` branch at 0x4a44 targets 0x4964 and is always taken.
  The `beq` branch at 0x4a54 targets 0x4b04, is taken when t1(?) == s3(=0x5), and falls through when t1(?) != s3(=0x5).
  The `beq` branch at 0x4a68 targets 0x486c and is always taken.
  The `bne` branch at 0x4ab0 targets 0x4a4c, is taken when v0(=[sym(.sdata)+16]) < s4(?) (unsigned), and falls through when v0(=[sym(.sdata)+16]) >= s4(?) (unsigned).
  The `beq` branch at 0x4ad0 targets 0x4aa8, is taken when ra(?) == at(?), and falls through when ra(?) != at(?).
  The `bne` branch at 0x4ad8 targets 0x4aa8, is taken when at(=[sym(partition_partid)]:1) != s4(?), and falls through when at(=[sym(partition_partid)]:1) == s4(?).
  The `bgez` branch at 0x4af4 targets 0x4a70, is taken when v1(=([ret(part_get_nasid)+4] << 0x8)) >= 0 (signed), and falls through when v1(=([ret(part_get_nasid)+4] << 0x8)) < 0 (signed).
  The `beq` branch at 0x4afc targets 0x4a80 and is always taken.
  The `beq` branch at 0x4b10 targets 0x4a60 and is always taken.
  The `beq` branch at 0x4b3c targets 0x486c and is always taken.
  The `beq` branch at 0x4b6c targets 0x486c and is always taken.
  The `beq` branch at 0x4b9c targets 0x49cc and is always taken.
  The `beq` branch at 0x4bcc targets 0x49c0 and is always taken.
  The `beq` branch at 0x4bfc targets 0x486c and is always taken.
  The `beq` branch at 0x4c2c targets 0x4a40 and is always taken.
  The `beq` branch at 0x4c34 targets 0x48a4 and is always taken.
  The return at 0x4a18 has v0 = ret(timeout).

- `part_heartbeat_timeout` in `IP27/usr/cpu/sysgen/IP27boot/partition.o` at 0x4c3c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/partition.o`.
  Range: 0x4c3c-0x4c44 (8 bytes).
  It occupies 8 bytes.
  The return at 0x4c3c has v0 = [sym(.sdata)+24].

- `part_heart_beater` in `IP27/usr/cpu/sysgen/IP27boot/partition.o` at 0x4c44 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/partition.o`.
  Range: 0x4c44-0x4c64 (32 bytes).
  It occupies 32 bytes.
  The `ld` at 0x4c50 loads 8 bytes from [sym(.sdata)+32]:8 +0x18.
  The `sd` at 0x4c58 stores 8 bytes to [sym(.sdata)+32]:8 +0x18.
  The `beq` branch at 0x4c48 targets 0x4c5c, is taken when a1(=[sym(.sdata)+32]:8) == 0, and falls through when a1(=[sym(.sdata)+32]:8) != 0.
  The return at 0x4c5c has v0 = ?.

- `part_thread` in `IP27/usr/cpu/sysgen/IP27boot/partition.o` at 0x4c64 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/partition.o`.
  Range: 0x4c64-0x4d74 (272 bytes).
  It occupies 272 bytes.
  3 such `ll` accesses load 4 bytes from ?, including `ll` at 0x4cc4, `ll` at 0x4d1c, `ll` at 0x4d40.
  3 such `sc` accesses store 4 bytes to ?, including `sc` at 0x4cd0, `sc` at 0x4d28, `sc` at 0x4d4c.
  The `lw` at 0x4d08 loads 4 bytes from ?.
  The `sw` at 0x4d5c stores 4 bytes to ?.
  The `jal` at 0x4cb0 calls part_start_partition_thread with a0=?, a1=0x1, a2=0x1, a3=-0x1.
  The `jal` at 0x4d64 calls psema with a0=sym(.bss), a1=0x19, a2=?, a3=?.
  The `beq` branch at 0x4c7c targets 0x4ca0 and is always taken.
  The `bne` branch at 0x4c94 targets 0x4cf4, is taken when s0(?) < 0x40 (signed), and falls through when s0(?) >= 0x40 (signed).
  The `blez` branch at 0x4c9c targets 0x4d60, is taken when s2(?) <= 0 (signed), and falls through when s2(?) > 0 (signed).
  The `beq` branch at 0x4ca4 targets 0x4cf0 and is always taken.
  The `beql` branch at 0x4cd4 targets 0x4cc4, is taken when at(=table(-0x1)) == 0, and falls through when at(=table(-0x1)) != 0; its branch-likely delay slot `nop` at 0x4cd8 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x4cec targets 0x4c9c, is taken when s0(?) >= 0x40 (signed), and falls through when s0(?) < 0x40 (signed).
  The `blez` branch at 0x4d0c targets 0x4c84, is taken when s1(?) <= 0 (signed), and falls through when s1(?) > 0 (signed).
  The `beql` branch at 0x4d2c targets 0x4d1c, is taken when a4(?) == 0, and falls through when a4(?) != 0; its branch-likely delay slot `nop` at 0x4d30 runs only when taken and is annulled on fall-through.
  The `bgez` branch at 0x4d34 targets 0x4cac, is taken when a1(?) >= 0 (signed), and falls through when a1(?) < 0 (signed).
  The `beql` branch at 0x4d50 targets 0x4d40, is taken when a7(?) == 0, and falls through when a7(?) != 0; its branch-likely delay slot `nop` at 0x4d54 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x4d58 targets 0x4cdc and is always taken.
  The `beq` branch at 0x4d6c targets 0x4ca4 and is always taken.
