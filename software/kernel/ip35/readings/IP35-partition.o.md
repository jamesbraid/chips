# Readings: `IP35/usr/cpu/sysgen/IP35boot/partition.o`

One entry per routine, filed here from the reading batches by binary.

- `nasid_to_partid` in `IP35/usr/cpu/sysgen/IP35boot/partition.o` at 0x0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/partition.o`.
  Range: 0x0-0x20 (32 bytes).
  It occupies 32 bytes.
  The `lb` at 0x1c loads 1 byte from table(sym(.bss)) +0x6.
  The return at 0x18 has v0 = [table(sym(.bss))+6]:1.

- `part_avl_start` in `IP35/usr/cpu/sysgen/IP35boot/partition.o` at 0x20 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/partition.o`.
  Range: 0x20-0x28 (8 bytes).
  It occupies 8 bytes.
  The `ld` at 0x24 loads 8 bytes from a0 (arg0 at entry) +0x28.
  The return at 0x20 has v0 = [a0+40]:8.

- `part_avl_end` in `IP35/usr/cpu/sysgen/IP35boot/partition.o` at 0x28 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/partition.o`.
  Range: 0x28-0x38 (16 bytes).
  It occupies 16 bytes.
  The `ld` at 0x28 loads 8 bytes from a0 (arg0 at entry) +0x30.
  The `ld` at 0x2c loads 8 bytes from a0 (arg0 at entry) +0x28.
  The return at 0x30 has v0 = ([a0+40]:8 + [a0+48]:8).

- `part_hold_page` in `IP35/usr/cpu/sysgen/IP35boot/partition.o` at 0x38 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/partition.o`.
  Range: 0x38-0x48 (16 bytes).
  It occupies 16 bytes.
  The `lw` at 0x38 loads 4 bytes from a0 (arg0 at entry) +0x58.
  The `sw` at 0x44 stores 4 bytes to a0 (arg0 at entry) +0x58.
  The return at 0x40 has v0 = ?.

- `part_release_page_nolock` in `IP35/usr/cpu/sysgen/IP35boot/partition.o` at 0x48 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/partition.o`.
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

- `part_release_page` in `IP35/usr/cpu/sysgen/IP35boot/partition.o` at 0x13c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/partition.o`.
  Range: 0x13c-0x188 (76 bytes).
  It occupies 76 bytes.
  The `jal` at 0x150 calls mutex_spinlock_spl with a0=sym(.sbss), a1=sym(splerr), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x15c calls part_release_page_nolock with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x16c calls mutex_spinunlock with a0=sym(.sbss), a1=[sym(.sbss)+4], a2=?, a3=?.
  The return at 0x180 has v0 = ret(part_release_page_nolock).

- `part_find_page` in `IP35/usr/cpu/sysgen/IP35boot/partition.o` at 0x188 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/partition.o`.
  Range: 0x188-0x1ec (100 bytes).
  It occupies 100 bytes.
  The `jal` at 0x19c calls mutex_spinlock_spl with a0=sym(.sbss), a1=sym(splerr), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1ac calls avl_findrange with a0=sym(.bss), a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0x1c0 calls mutex_spinunlock with a0=sym(.sbss), a1=[sym(.sbss)+4], a2=?, a3=?.
  The `jal` at 0x1dc calls part_hold_page with a0=ret(avl_findrange), a1=?, a2=?, a3=?.
  The `bne` branch at 0x1b4 targets 0x1dc, is taken when v0(=ret(avl_findrange)) != 0, and falls through when v0(=ret(avl_findrange)) == 0.
  The `beq` branch at 0x1e4 targets 0x1c0 and is always taken.
  The return at 0x1d4 has v0 = ret(avl_findrange).

- `part_new_page` in `IP35/usr/cpu/sysgen/IP35boot/partition.o` at 0x1ec (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/partition.o`.
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
  The `jal` at 0x2e4 calls kmem_free with a0=ret(kmem_alloc), a1=0x60, a2=0x3f80000, a3=?.
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

- `part_init_node` in `IP35/usr/cpu/sysgen/IP35boot/partition.o` at 0x3b4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/partition.o`.
  Range: 0x3b4-0x7e8 (1076 bytes).
  It occupies 1076 bytes.
  The `ld` at 0x3d4 loads 8 bytes from abs 0xffffffffffffc400.
  The `ld` at 0x3dc loads 8 bytes from [-0x3c00]:8 +0x0.
  The `ld` at 0x3f0 loads 8 bytes from ([[-0x3c00]:8]:8 + (a1 << 0x3)) +0x0.
  The `lh` at 0x40c loads 2 bytes from [([[-0x3c00]:8]:8 + (a1 << 0x3))]:8 +0x8596.
  2 such `lh` accesses load 2 bytes from (sym(compact_to_nasid_node) + (a1 + a1)) +0x0, including `lh` at 0x438, `lh` at 0x4d8.
  The `ld` at 0x460 loads 8 bytes from ([(sym(compact_to_nasid_node) + (a1 + a1))]:2 << 0x21) -0x6dfffffffe040000.
  The `ld` at 0x46c loads 8 bytes from ([(sym(compact_to_nasid_node) + (a1 + a1))]:2 << 0x21) -0x6dfffffffe07fff8.
  The `sd` at 0x488 stores 8 bytes to ([(sym(compact_to_nasid_node) + (a1 + a1))]:2 << 0x21) -0x6dfffffffe07fff8.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0x534, `lw` at 0x54c.
  9 such `sd` accesses store 8 bytes to ?, including `sd` at 0x5c8, `sd` at 0x5cc, `sd` at 0x5d0.
  The `ld` at 0x61c loads 8 bytes from ?.
  2 such `ld` accesses load 8 bytes from table(0x9200000001fc0000) +0x0, including `ld` at 0x620, `ld` at 0x654.
  The `sd` at 0x6f0 stores 8 bytes to ([(sym(compact_to_nasid_node) + (a1 + a1))]:2 << 0x21) -0x6dfffffffe080000.
  The `sd` at 0x700 stores 8 bytes to ([(sym(compact_to_nasid_node) + (a1 + a1))]:2 << 0x21) -0x6dfffffffe1fbff0.
  The `sd` at 0x70c stores 8 bytes to ([(sym(compact_to_nasid_node) + (a1 + a1))]:2 << 0x21) -0x6dfffffffe1fc000.
  The `sd` at 0x750 stores 8 bytes to (([(sym(compact_to_nasid_node) + (a1 + a1))]:2 << 0x21) + one of 0x9200000001800018, 0x9200000001a00018) +0x0.
  The `sd` at 0x764 stores 8 bytes to (([(sym(compact_to_nasid_node) + (a1 + a1))]:2 << 0x21) + one of 0x9200000001800010, 0x9200000001a00010) +0x0.
  The `sd` at 0x76c stores 8 bytes to (([(sym(compact_to_nasid_node) + (a1 + a1))]:2 << 0x21) + one of 0x92000000018000e8, 0x9200000001a000e8) +0x0.
  The `sd` at 0x778 stores 8 bytes to ([(sym(compact_to_nasid_node) + (a1 + a1))]:2 << 0x21) -0x6dfffffffe1fbfe0.
  The `jal` at 0x408 calls setmustrun with a0=[[([[-0x3c00]:8]:8 + (a1 << 0x3))]:8+34198]:2, a1=[([[-0x3c00]:8]:8 + (a1 << 0x3))]:8, a2=[[-0x3c00]:8]:8, a3=a3 at entry (arg3).
  The `jal` at 0x4ac calls slot_getsize with a0=a1 at entry (arg1), a1=?, a2=?, a3=?.
  The `jal` at 0x780 calls vsema with a0=sym(.bss), a1=0x9200000001800000, a2=?, a3=one of 0xe8, 0x2000e8, a4=(([(sym(compact_to_nasid_node) + (a1 + a1))]:2 << 0x21) + one of 0x9200000001800018, 0x9200000001a00018), a5=0x200010, a6=0x200018, a7=([(sym(compact_to_nasid_node) + (a1 + a1))]:2 << 0x21)+0x9200000001f80000.
  The `beq` branch at 0x490 targets 0x4a8 and is always taken.
  The `bltz` branch at 0x4a0 targets 0x6cc, is taken when t1(?) < 0 (signed), and falls through when t1(?) >= 0 (signed).
  The `beq` branch at 0x4c4 targets 0x498, is taken when v0(=ret(slot_getsize)) == 0, and falls through when v0(=ret(slot_getsize)) != 0.
  The `beq` branch at 0x500 targets 0x498, is taken when ra(?) >= a3(?) (unsigned), and falls through when ra(?) < a3(?) (unsigned).
  The `beq` branch at 0x508 targets 0x7c4 and is always taken.
  The `bne` branch at 0x52c targets 0x538, is taken when v1(?) < 0x4000 (unsigned), and falls through when v1(?) >= 0x4000 (unsigned).
  The `beq` branch at 0x53c targets 0x558, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `bne` branch at 0x544 targets 0x550, is taken when a7(?) != 0, and falls through when a7(?) == 0.
  The `bne` branch at 0x550 targets 0x518, is taken when a5(?) != 0, and falls through when a5(?) == 0.
  The `beq` branch at 0x584 targets 0x498, is taken when ra(?) >= a5(?) (unsigned), and falls through when ra(?) < a5(?) (unsigned).
  The `beq` branch at 0x5b0 targets 0x7b8 and is always taken.
  The `bne` branch at 0x5e8 targets 0x510, is taken when s2(=one of 0xf, 0x3f) < v0(?) (unsigned), and falls through when s2(=one of 0xf, 0x3f) >= v0(?) (unsigned).
  The `beq` branch at 0x618 targets 0x654, is taken when (s1(=a0) & a4(?)) == 0, and falls through when (s1(=a0) & a4(?)) != 0.
  The `beq` branch at 0x62c targets 0x69c, is taken when 0 >= t2(?) (unsigned), and falls through when 0 < t2(?) (unsigned).
  The `beq` branch at 0x634 targets 0x6b0, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `bne` branch at 0x644 targets 0x5b8, is taken when (v0(?) & 0x20) != 0, and falls through when (v0(?) & 0x20) == 0.
  The `beq` branch at 0x64c targets 0x5c4 and is always taken.
  The `beq` branch at 0x66c targets 0x684, is taken when 0 >= v1(?) (unsigned), and falls through when 0 < v1(?) (unsigned).
  The `beq` branch at 0x694 targets 0x5d8 and is always taken.
  The `beq` branch at 0x69c targets 0x6c0, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `beq` branch at 0x6a8 targets 0x5c0 and is always taken.
  The `beq` branch at 0x6b8 targets 0x640 and is always taken.
  The `beq` branch at 0x6c4 targets 0x5c0 and is always taken.
  The `bne` branch at 0x768 targets 0x710, is taken when v0(?) < 0x2 (signed), and falls through when v0(?) >= 0x2 (signed).
  The `beq` branch at 0x774 targets 0x788, is taken when a0(=a2) == 0, and falls through when a0(=a2) != 0.
  The `beq` branch at 0x7bc targets 0x5f4 and is always taken.
  The `beq` branch at 0x7e0 targets 0x590 and is always taken.
  The return at 0x7b0 has v0 = one of ?, ret(vsema).

- `part_permit_xppage` in `IP35/usr/cpu/sysgen/IP35boot/partition.o` at 0x7e8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/partition.o`.
  Range: 0x7e8-0x924 (316 bytes).
  It occupies 316 bytes.
  The `ld` at 0x828 loads 8 bytes from a0 (arg0 at entry) +0x30.
  The `ld` at 0x82c loads 8 bytes from a0 (arg0 at entry) +0x50.
  The `ld` at 0x830 loads 8 bytes from a0 (arg0 at entry) +0x38.
  The `sd` at 0x854 stores 8 bytes to a0 (arg0 at entry) +0x50.
  2 such `lh` accesses load 2 bytes from abs 0xffffffffffffc428, including `lh` at 0x860, `lh` at 0x898.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x5c, including `lw` at 0x864, `lw` at 0x89c.
  2 such `sh` accesses store 2 bytes to a0 (arg0 at entry) +0x42, including `sh` at 0x868, `sh` at 0x8a8.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x5c, including `sw` at 0x874, `sw` at 0x8b4.
  The `ll` at 0x908 loads 4 bytes from a0 (arg0 at entry) +0x5c.
  The `sc` at 0x910 stores 4 bytes to a0 (arg0 at entry) +0x5c.
  The `jal` at 0x820 calls bitlock_acquire_32bit with a0=a0+92, a1=0x1, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x858 calls splerr with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x880 calls part_pfdat_depermit with a0=?, a1=[a0+80]:8, a2=?, a3=?.
  The `jal` at 0x8b0 calls splx with a0=ret(splerr), a1=?, a2=?, a3=?.
  The `jal` at 0x8c8 calls part_pfdat_permit with a0=?, a1=[a0+80]:8, a2=?, a3=?.
  The `beq` branch at 0x850 targets 0x8c0, is taken when (s7(=a2) & s3(=[a0+80]:8)) == 0, and falls through when (s7(=a2) & s3(=[a0+80]:8)) != 0.
  The `bne` branch at 0x890 targets 0x87c, is taken when s0(?) < s1(?) (unsigned), and falls through when s0(?) >= s1(?) (unsigned).
  The `beq` branch at 0x8b8 targets 0x8e4 and is always taken.
  The `bne` branch at 0x8d8 targets 0x8c4, is taken when s0(?) < s1(?) (unsigned), and falls through when s0(?) >= s1(?) (unsigned).
  The `beql` branch at 0x914 targets 0x908, is taken when (a1(=[a0+92]) & a3(=-0x2)) == 0, and falls through when (a1(=[a0+92]) & a3(=-0x2)) != 0; its branch-likely delay slot `nop` at 0x918 runs only when taken and is annulled on fall-through.
  The return at 0x91c has v0 = ?.

- `part_permit_page` in `IP35/usr/cpu/sysgen/IP35boot/partition.o` at 0x924 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/partition.o`.
  Range: 0x924-0x9ec (200 bytes).
  It occupies 200 bytes.
  2 such `ld` accesses load 8 bytes from ret(part_get) +0x18, including `ld` at 0x9a0, `ld` at 0x9d0.
  The `jal` at 0x938 calls part_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x978 calls part_find_page with a0=?, a1=?, a2=0x3f80000, a3=0xfffffffffe000000.
  The `jal` at 0x9a4 calls part_permit_xppage with a0=ret(part_find_page), a1=?, a2=?, a3=?.
  The `jal` at 0x9ac calls part_release_page with a0=ret(part_find_page), a1=?, a2=?, a3=?.
  The `jal` at 0x9d8 calls cmn_err with a0=0x0, a1=sym(.rodata), a2=a2 at entry (arg2), a3=0x1.
  The `beq` branch at 0x944 targets 0x9b4, is taken when v0(=ret(part_get)) == 0, and falls through when v0(=ret(part_get)) != 0.
  The `beq` branch at 0x990 targets 0x9cc, is taken when s0(=a2) == a3(=0x1), and falls through when s0(=a2) != a3(=0x1).
  The `bne` branch at 0x998 targets 0x9d4, is taken when s0(=a2) != a0(=0x2), and falls through when s0(=a2) == a0(=0x2).
  The `beq` branch at 0x9cc targets 0x9a4 and is always taken.
  The `beq` branch at 0x9e4 targets 0x9a4 and is always taken.
  The return at 0x9c4 has v0 = one of ret(part_get), ret(part_release_page).

- `part_pfdat_permit` in `IP35/usr/cpu/sysgen/IP35boot/partition.o` at 0x9ec (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/partition.o`.
  Range: 0x9ec-0xc58 (620 bytes).
  It occupies 620 bytes.
  3 such `ld` accesses load 8 bytes from table(0x9200000001fc0000) +0x0, including `ld` at 0xa60, `ld` at 0xb68, `ld` at 0xb9c.
  8 such `sd` accesses store 8 bytes to ?, including `sd` at 0xb08, `sd` at 0xb0c, `sd` at 0xb10.
  The `ld` at 0xb64 loads 8 bytes from ?.
  The `beq` branch at 0xa74 targets 0xc0c, is taken when s6(?) >= at(?) (unsigned), and falls through when s6(?) < at(?) (unsigned).
  The `beq` branch at 0xaa0 targets 0xaac and is always taken.
  The `beq` branch at 0xaa8 targets 0xc0c, is taken when s7(?) == 0, and falls through when s7(?) != 0.
  The `beq` branch at 0xaf0 targets 0xc3c and is always taken.
  The `beq` branch at 0xb30 targets 0xaa8, is taken when a1(?) >= 0x40 (unsigned), and falls through when a1(?) < 0x40 (unsigned).
  The `beq` branch at 0xb44 targets 0xb18, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `beq` branch at 0xb60 targets 0xb9c, is taken when a7(?) == 0, and falls through when a7(?) != 0.
  The `beq` branch at 0xb74 targets 0xbe4, is taken when 0 >= at(?) (unsigned), and falls through when 0 < at(?) (unsigned).
  The `beq` branch at 0xb7c targets 0xbf4, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `bne` branch at 0xb8c targets 0xaf8, is taken when a4(?) != 0, and falls through when a4(?) == 0.
  The `beq` branch at 0xb94 targets 0xb00 and is always taken.
  The `beq` branch at 0xbb4 targets 0xbcc, is taken when 0 >= v0(?) (unsigned), and falls through when 0 < v0(?) (unsigned).
  The `beq` branch at 0xbdc targets 0xb18 and is always taken.
  The `beq` branch at 0xbe4 targets 0xc00, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `beq` branch at 0xbec targets 0xb00 and is always taken.
  The `beq` branch at 0xbf8 targets 0xb8c and is always taken.
  The `beq` branch at 0xc04 targets 0xb04 and is always taken.
  The `beq` branch at 0xc50 targets 0xb3c and is always taken.
  The return at 0xc34 has v0 = one of ?, 0x3fff0000.

- `part_pfdat_depermit` in `IP35/usr/cpu/sysgen/IP35boot/partition.o` at 0xc58 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/partition.o`.
  Range: 0xc58-0xeac (596 bytes).
  It occupies 596 bytes.
  2 such `ld` accesses load 8 bytes from abs 0xffffffffffffc020, including `ld` at 0xc94, `ld` at 0xd60.
  The `lw` at 0xcc4 loads 4 bytes from a0 (arg0 at entry) +0x10.
  The `ld` at 0xdd4 loads 8 bytes from table(sym(.rodata)) +0x0.
  The `jal` at 0xcf8 calls part_pfdat_permit with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=?.
  The `jal` at 0xd10 calls __cache_hwb_inval_pfn with a0=0x0, a1=0x4000, a2=?, a3=?.
  The `jal` at 0xd30 calls badaddr_val with a0=?, a1=0x4, a2=sp-120, a3=?.
  The `jal` at 0xda8 calls get_dir_ent with a0=?, a1=sp-116, a2=sp-112, a3=sp-104.
  The `jal` at 0xe70 calls rt_unpin_thread with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xe80 calls rt_pin_thread with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xe9c calls cmn_err with a0=0x0, a1=sym(.rodata), a2=?, a3=?.
  The `beq` branch at 0xc8c targets 0xc9c, is taken when (a1 & at(?)) == 0, and falls through when (a1 & at(?)) != 0.
  The `bne` branch at 0xc98 targets 0xe80, is taken when v0(=[-0x3fe0]:8) != 0, and falls through when v0(=[-0x3fe0]:8) == 0.
  The `beq` branch at 0xd1c targets 0xd50, is taken when s1(?) >= s3(?) (unsigned), and falls through when s1(?) < s3(?) (unsigned).
  The `beq` branch at 0xd40 targets 0xd2c, is taken when s2(?) >= s0(?) (unsigned), and falls through when s2(?) < s0(?) (unsigned).
  The `beq` branch at 0xd48 targets 0xd8c and is always taken.
  The `beq` branch at 0xd58 targets 0xd68, is taken when ra(?) == 0, and falls through when ra(?) != 0.
  The `bne` branch at 0xd64 targets 0xe70, is taken when at(=[-0x3fe0]:8) != 0, and falls through when at(=[-0x3fe0]:8) == 0.
  The `beq` branch at 0xd8c targets 0xd9c and is always taken.
  The `beq` branch at 0xd98 targets 0xd7c and is never taken: its condition can never hold for these operands, so execution always falls through.
  The `beq` branch at 0xdcc targets 0xe90, is taken when a2(?) >= 0x8 (unsigned), and falls through when a2(?) < 0x8 (unsigned).
  The `beq` branch at 0xe78 targets 0xd6c and is always taken.
  The `beq` branch at 0xe88 targets 0xc9c and is always taken.
  The `beq` branch at 0xea4 targets 0xd98 and is always taken.
  The return at 0xd74 has v0 = one of ret(__cache_hwb_inval_pfn), ret(rt_unpin_thread).
  The instructions from 0xd7c to 0xd88 are not reached by any path from the entry, and their branches are not listed.
  The instructions from 0xd94 to 0xd94 are not reached by any path from the entry, and their branches are not listed.
  The instructions from 0xde0 to 0xe6c are not reached by any path from the entry, and their branches are not listed.
  The indirect jump at 0xdd8 uses a jump table whose successors are unresolved.

- `part_pfdat_flags` in `IP35/usr/cpu/sysgen/IP35boot/partition.o` at 0xeac (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/partition.o`.
  Range: 0xeac-0xfd0 (292 bytes).
  It occupies 292 bytes.
  The `jal` at 0xf14 calls splhi with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xf28 calls bitlock_set with a0=?, a1=0x8000000, a2=a2 at entry (arg2), a3=?.
  The `jal` at 0xf30 calls splx with a0=ret(splhi), a1=?, a2=?, a3=?.
  The `jal` at 0xf70 calls splhi with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xf84 calls bitlock_clr with a0=?, a1=0x8000000, a2=a3 at entry (arg3), a3=?.
  The `jal` at 0xf8c calls splx with a0=ret(splhi), a1=?, a2=?, a3=?.
  The `beq` branch at 0xef4 targets 0xf48, is taken when a2 == 0, and falls through when a2 != 0.
  The `beq` branch at 0xf0c targets 0xf48, is taken when a0 >= s3(?) (unsigned), and falls through when a0 < s3(?) (unsigned).
  The `beq` branch at 0xf40 targets 0xf14, is taken when s3(?) >= s1(?) (unsigned), and falls through when s3(?) < s1(?) (unsigned).
  The `beq` branch at 0xf48 targets 0xfa4, is taken when s5(=a3) == 0, and falls through when s5(=a3) != 0.
  The `beq` branch at 0xf60 targets 0xfa4, is taken when s2(=a0) >= s3(?) (unsigned), and falls through when s2(=a0) < s3(?) (unsigned).
  The `beq` branch at 0xf9c targets 0xf70, is taken when s3(?) >= s2(?) (unsigned), and falls through when s3(?) < s2(?) (unsigned).
  The return at 0xfc8 has v0 = one of ?, ret(splx).

- `part_page_allocate_node` in `IP35/usr/cpu/sysgen/IP35boot/partition.o` at 0xfd0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/partition.o`.
  Range: 0xfd0-0x1070 (160 bytes).
  It occupies 160 bytes.
  The `ld` at 0x105c loads 8 bytes from ret(part_get) +0x18.
  The `jal` at 0xff4 calls pagealloc_size_node with a0=a0 at entry (arg0), a1=a3 at entry (arg3), a2=a4 at entry (arg4), a3=a5 at entry (arg5).
  The `jal` at 0x102c calls part_new_page with a0=ret(pagealloc_size_node), a1=0x0, a2=a5 at entry (arg5), a3=0x0, a4=a6 at entry (arg6).
  The `jal` at 0x1044 calls part_pfdat_flags with a0=ret(pagealloc_size_node), a1=a5 at entry (arg5), a2=0x4000000, a3=0x0.
  The `jal` at 0x1050 calls part_get with a0=a1 at entry (arg1), a1=?, a2=?, a3=?.
  The `jal` at 0x1060 calls part_permit_xppage with a0=ret(part_new_page), a1=[ret(part_get)+24]:8, a2=0x0, a3=?.
  The `bne` branch at 0xffc targets 0x101c, is taken when v0(=ret(pagealloc_size_node)) != 0, and falls through when v0(=ret(pagealloc_size_node)) == 0.
  The `beq` branch at 0x1068 targets 0x1008 and is always taken.
  The return at 0x1014 has v0 = ret(pagealloc_size_node).

- `part_page_allocate` in `IP35/usr/cpu/sysgen/IP35boot/partition.o` at 0x1070 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/partition.o`.
  Range: 0x1070-0x111c (172 bytes).
  It occupies 172 bytes.
  The `ld` at 0x10e4 loads 8 bytes from ret(part_get) +0x18.
  The `jal` at 0x1094 calls pagealloc_size with a0=a2 at entry (arg2), a1=a3 at entry (arg3), a2=a4 at entry (arg4), a3=a3 at entry (arg3).
  The `jal` at 0x10b4 calls part_new_page with a0=ret(pagealloc_size), a1=0x0, a2=a4 at entry (arg4), a3=0x0, a4=a5 at entry (arg5).
  The `jal` at 0x10d0 calls part_pfdat_flags with a0=ret(pagealloc_size), a1=a4 at entry (arg4), a2=0x4000000, a3=0x0.
  The `jal` at 0x10d8 calls part_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x10e8 calls part_permit_xppage with a0=ret(part_new_page), a1=[ret(part_get)+24]:8, a2=0x0, a3=?.
  The `jal` at 0x110c calls pagefree_size with a0=ret(pagealloc_size), a1=a4 at entry (arg4), a2=?, a3=?.
  The `beq` branch at 0x109c targets 0x10f0, is taken when v0(=ret(pagealloc_size)) == 0, and falls through when v0(=ret(pagealloc_size)) != 0.
  The `beq` branch at 0x10bc targets 0x1108, is taken when v0(=ret(part_new_page)) == 0, and falls through when v0(=ret(part_new_page)) != 0.
  The `beq` branch at 0x1114 targets 0x10f0 and is always taken.
  The return at 0x1100 has v0 = one of ret(pagealloc_size), 0x0.

- `part_page_free` in `IP35/usr/cpu/sysgen/IP35boot/partition.o` at 0x111c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/partition.o`.
  Range: 0x111c-0x12b0 (404 bytes).
  It occupies 404 bytes.
  The `ld` at 0x1170 loads 8 bytes from ret(part_get) +0x18.
  The `ld` at 0x1188 loads 8 bytes from ret(part_find_page) +0x30.
  3 such `ld` accesses load 8 bytes from ret(part_find_page) +0x38, including `ld` at 0x118c, `ld` at 0x11bc, `ld` at 0x11d0.
  2 such `lw` accesses load 4 bytes from [ret(part_find_page)+56]:8 +0x10, including `lw` at 0x11d4, `lw` at 0x11e4.
  The `jal` at 0x1128 calls part_id with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1134 calls part_get with a0=ret(part_id), a1=?, a2=?, a3=?.
  The `jal` at 0x1168 calls part_find_page with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1180 calls part_permit_xppage with a0=ret(part_find_page), a1=[ret(part_get)+24]:8, a2=?, a3=?.
  The `jal` at 0x123c calls get_dir_ent with a0=?, a1=sp-80, a2=sp-72, a3=sp-64.
  The `jal` at 0x1280 calls part_release_page with a0=ret(part_find_page), a1=?, a2=?, a3=?.
  The `jal` at 0x1288 calls part_release_page with a0=ret(part_find_page), a1=?, a2=?, a3=?.
  The `jal` at 0x12a0 calls set_dir_state with a0=?, a1=0x1, a2=?, a3=?.
  The `beq` branch at 0x11ac targets 0x1270, is taken when s0(=[ret(part_find_page)+56]:8) >= s3(?) (unsigned), and falls through when s0(=[ret(part_find_page)+56]:8) < s3(?) (unsigned).
  The `beq` branch at 0x11b8 targets 0x11d4 and is always taken.
  The `bne` branch at 0x11c8 targets 0x1270, is taken when s3(?) < s0(?) (unsigned), and falls through when s3(?) >= s0(?) (unsigned).
  The `bne` branch at 0x11dc targets 0x11c0, is taken when (s2(=0x400000) & t9(=[[ret(part_find_page)+56]:8+16])) != 0, and falls through when (s2(=0x400000) & t9(=[[ret(part_find_page)+56]:8+16])) == 0.
  The `bne` branch at 0x11ec targets 0x11c0, is taken when (a0(=0x1000000) & ra(=[[ret(part_find_page)+56]:8+16])) != 0, and falls through when (a0(=0x1000000) & ra(=[[ret(part_find_page)+56]:8+16])) == 0.
  The `beq` branch at 0x1228 targets 0x11c0, is taken when s4(?) >= at(?) (unsigned), and falls through when s4(?) < at(?) (unsigned).
  The `beq` branch at 0x124c targets 0x12a0, is taken when at(?) == v0(=0x7), and falls through when at(?) != v0(=0x7).
  The `bne` branch at 0x1260 targets 0x1234, is taken when s4(?) < v1(?) (unsigned), and falls through when s4(?) >= v1(?) (unsigned).
  The `beq` branch at 0x1268 targets 0x11c0 and is always taken.
  The `beq` branch at 0x12a8 targets 0x1258 and is always taken.
  The return at 0x1298 has v0 = ret(part_release_page).

- `part_interrupt_thread_exit` in `IP35/usr/cpu/sysgen/IP35boot/partition.o` at 0x12b0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/partition.o`.
  Range: 0x12b0-0x1344 (148 bytes).
  It occupies 148 bytes.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x20, including `ld` at 0x12b0, `ld` at 0x12cc.
  The `ll` at 0x12d8 loads 4 bytes from [a0+32]:8 +0x7c.
  The `sc` at 0x12e4 stores 4 bytes to [a0+32]:8 +0x7c.
  The `lw` at 0x12f0 loads 4 bytes from a0 (arg0 at entry) +0x18.
  The `ll` at 0x130c loads 4 bytes from [a0+32]:8 +0x6c.
  The `sc` at 0x1318 stores 4 bytes to [a0+32]:8 +0x6c.
  The `jal` at 0x12c4 calls part_dequeue_xthread with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1328 calls kmem_free with a0=a0 at entry (arg0), a1=0x28, a2=?, a3=?.
  The `jal` at 0x1330 calls xthread_exit with a0=?, a1=?, a2=?, a3=?.
  The `beql` branch at 0x12e8 targets 0x12d8, is taken when a2(=[[a0+32]:8+124]+1) == 0, and falls through when a2(=[[a0+32]:8+124]+1) != 0; its branch-likely delay slot `nop` at 0x12ec runs only when taken and is annulled on fall-through.
  The `bne` branch at 0x12f8 targets 0x1328, is taken when (v0(=[a0+24]) & 0x2) != 0, and falls through when (v0(=[a0+24]) & 0x2) == 0.
  The `beql` branch at 0x131c targets 0x130c, is taken when a4(=[[a0+32]:8+108]-1) == 0, and falls through when a4(=[[a0+32]:8+108]-1) != 0; its branch-likely delay slot `nop` at 0x1320 runs only when taken and is annulled on fall-through.
  The return at 0x133c has v0 = ret(xthread_exit).

- `part_activate` in `IP35/usr/cpu/sysgen/IP35boot/partition.o` at 0x1344 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/partition.o`.
  Range: 0x1344-0x1754 (1040 bytes).
  It occupies 1040 bytes.
  3 such `lw` accesses load 4 bytes from ret(part_get) +0x20, including `lw` at 0x1370, `lw` at 0x1458, `lw` at 0x164c.
  3 such `sw` accesses store 4 bytes to ret(part_get) +0xc, including `sw` at 0x1374, `sw` at 0x1468, `sw` at 0x1658.
  The `sd` at 0x138c stores 8 bytes to ret(part_get) +0x38.
  The `sd` at 0x1390 stores 8 bytes to ret(part_get) +0x30.
  2 such `sw` accesses store 4 bytes to ret(part_get) +0x20, including `sw` at 0x139c, `sw` at 0x16c8.
  12 such `lb` accesses load 1 byte from ret(part_get) +0x14, including `lb` at 0x13a8, `lb` at 0x13f8, `lb` at 0x1420.
  The `lb` at 0x13bc loads 1 byte from ?.
  2 such `ld` accesses load 8 bytes from ret(part_get) +0x28, including `ld` at 0x13e0, `ld` at 0x14f0.
  The `ld` at 0x1404 loads 8 bytes from [sym(.sdata)+32]:8 +0x28.
  The `sd` at 0x1418 stores 8 bytes to [sym(.sdata)+32]:8 +0x28.
  7 such `lw` accesses load 4 bytes from ret(part_get) +0xc, including `lw` at 0x1444, `lw` at 0x15ac, `lw` at 0x1600.
  2 such `lw` accesses load 4 bytes from ret(part_get_nasid) +0x4, including `lw` at 0x151c, `lw` at 0x16ec.
  The `lh` at 0x156c loads 2 bytes from ret(part_get_nasid) +0x0.
  The `sd` at 0x1580 stores 8 bytes to (([ret(part_get_nasid)]:2 << 0x21) + one of 0x92000000018000c8, 0x92000000018000d0, 0x9200000001a000c8, 0x9200000001a000d0) +0x0.
  The `sd` at 0x15a0 stores 8 bytes to ret(part_get) +0x28.
  The `jal` at 0x1358 calls part_get with a0=?, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1368 calls mutex_spinlock with a0=ret(part_get)+8, a1=?, a2=?, a3=?.
  The `jal` at 0x13ec calls mutex_spinlock with a0=sym(.sbss)+12, a1=?, a2=?, a3=?.
  The `jal` at 0x1414 calls mutex_spinunlock with a0=sym(.sbss)+12, a1=ret(mutex_spinlock), a2=?, a3=[sym(.sdata)+32]:8, a5=[ret(part_get)+20]:1.
  The `jal` at 0x1440 calls mutex_spinunlock with a0=ret(part_get)+8, a1=[ret(part_get)+12], a2=[ret(part_get)+20]:1, a3=?.
  The `jal` at 0x1448 calls part_call_activate_handlers with a0=ret(part_get), a1=?, a2=?, a3=?.
  The `jal` at 0x1450 calls mutex_spinlock with a0=ret(part_get)+8, a1=?, a2=?, a3=?.
  The `jal` at 0x1478 calls mutex_spinunlock with a0=ret(part_get)+8, a1=?, a2=?, a3=?.
  The `jal` at 0x14b4 calls part_copy_fault with a0=(table(0x9600000000000000) | 0x2000)+512, a1=sp-384, a2=0x40, a3=?.
  The `jal` at 0x14f8 calls mutex_spinunlock with a0=ret(part_get)+8, a1=ret(mutex_spinlock), a2=?, a3=?.
  The `jal` at 0x150c calls part_get_nasid with a0=[ret(part_get)+20]:1, a1=0x0, a2=[ret(part_get)+20]:1, a3=?, a6=[sym(partition_partid)]:1, a7=[sym(.sdata)+16].
  The `jal` at 0x15a8 calls mutex_spinunlock with a0=ret(part_get)+8, a1=[ret(part_get)+12], a2=?, a3=?.
  The `jal` at 0x15b0 calls part_deactivate with a0=[ret(part_get)+20]:1, a1=?, a2=?, a3=?.
  The `jal` at 0x15cc calls part_from_addr with a0=?, a1=0x434d5f53505f5357, a2=?, a3=?.
  The `jal` at 0x15fc calls mutex_spinunlock with a0=ret(part_get)+8, a1=[ret(part_get)+12], a2=?, a3=?.
  The `jal` at 0x1604 calls part_deactivate with a0=[ret(part_get)+20]:1, a1=?, a2=?, a3=?.
  The `jal` at 0x1618 calls mutex_spinunlock with a0=ret(part_get)+8, a1=[ret(part_get)+12], a2=?, a3=?.
  The `jal` at 0x1620 calls part_deactivate with a0=[ret(part_get)+20]:1, a1=?, a2=?, a3=?.
  The `jal` at 0x163c calls sv_wait with a0=ret(part_get)+152, a1=0x19, a2=ret(part_get)+8, a3=ret(mutex_spinlock).
  The `jal` at 0x1644 calls mutex_spinlock with a0=ret(part_get)+8, a1=?, a2=?, a3=?.
  The `jal` at 0x168c calls part_copy_fault with a0=?, a1=sp-320, a2=0x110, a3=?.
  The `jal` at 0x16a0 calls mutex_spinunlock with a0=ret(part_get)+8, a1=[ret(part_get)+12], a2=?, a3=?.
  The `jal` at 0x16a8 calls part_deactivate with a0=[ret(part_get)+20]:1, a1=?, a2=?, a3=?.
  The `jal` at 0x16c4 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=[ret(part_get)+20]:1, a3=?.
  The `jal` at 0x16e0 calls assfail with a0=sym(.rodata), a1=sym(.rodata), a2=0x577, a3=?.
  The `jal` at 0x16f4 calls cmn_err with a0=0x4, a1=sym(.rodata), a2=[ret(part_get)+20]:1, a3=?.
  The `jal` at 0x1710 calls cmn_err with a0=0x5, a1=sym(.rodata), a2=[ret(part_get)+20]:1, a3=?, a4=0x1.
  The `jal` at 0x1730 calls cmn_err with a0=0x5, a1=sym(.rodata), a2=0x1, a3=0x0.
  The `jal` at 0x173c calls mutex_spinunlock with a0=ret(part_get)+8, a1=[ret(part_get)+12], a2=?, a3=?.
  The `jal` at 0x1744 calls part_deactivate with a0=[ret(part_get)+20]:1, a1=?, a2=?, a3=?.
  The `bne` branch at 0x1380 targets 0x14f4, is taken when a1(=[ret(part_get)+32]) != a0(=0x3), and falls through when a1(=[ret(part_get)+32]) == a0(=0x3).
  The `beq` branch at 0x13c0 targets 0x149c, is taken when v1(?) == a2(=[ret(part_get)+20]:1), and falls through when v1(?) != a2(=[ret(part_get)+20]:1).
  The `bne` branch at 0x13d8 targets 0x13b0, is taken when s1(?) < 0x80 (signed), and falls through when s1(?) >= 0x80 (signed).
  The `beq` branch at 0x13e4 targets 0x15a8, is taken when a1(=[ret(part_get)+40]:8) == 0, and falls through when a1(=[ret(part_get)+40]:8) != 0.
  The `bne` branch at 0x1424 targets 0x1508, is taken when a6(=[sym(partition_partid)]:1) != a2(=[ret(part_get)+20]:1), and falls through when a6(=[sym(partition_partid)]:1) == a2(=[ret(part_get)+20]:1).
  The `beq` branch at 0x1430 targets 0x143c, is taken when a7(=[sym(.sdata)+16]) >= a2(=[ret(part_get)+20]:1) (unsigned), and falls through when a7(=[sym(.sdata)+16]) < a2(=[ret(part_get)+20]:1) (unsigned).
  The `beq` branch at 0x1464 targets 0x1630, is taken when a0(=[ret(part_get)+32]) == t0(=0x5), and falls through when a0(=[ret(part_get)+32]) != t0(=0x5).
  The `beq` branch at 0x1470 targets 0x16b8, is taken when a0(=[ret(part_get)+32]) == t1(=0x4), and falls through when a0(=[ret(part_get)+32]) != t1(=0x4).
  The `bne` branch at 0x14bc targets 0x1614, is taken when v0(=ret(part_copy_fault)) != 0, and falls through when v0(=ret(part_copy_fault)) == 0.
  The `beq` branch at 0x14c8 targets 0x15c0, is taken when a1(=0x434d5f53505f5357) == a0(?), and falls through when a1(=0x434d5f53505f5357) != a0(?).
  The `bne` branch at 0x14e4 targets 0x13a8, is taken when s1(?) < 0x80 (signed), and falls through when s1(?) >= 0x80 (signed).
  The `beq` branch at 0x14ec targets 0x13e4 and is always taken.
  The `beq` branch at 0x1500 targets 0x1484 and is always taken.
  The `beq` branch at 0x1514 targets 0x16d4, is taken when v0(=ret(part_get_nasid)) == 0, and falls through when v0(=ret(part_get_nasid)) != 0.
  The `bltz` branch at 0x1524 targets 0x165c, is taken when t8(=([ret(part_get_nasid)+4] << 0x8)) < 0 (signed), and falls through when t8(=([ret(part_get_nasid)+4] << 0x8)) >= 0 (signed).
  The `bltz` branch at 0x152c targets 0x1664, is taken when t9(=([ret(part_get_nasid)+4] << 0x9)) < 0 (signed), and falls through when t9(=([ret(part_get_nasid)+4] << 0x9)) >= 0 (signed).
  The `bltz` branch at 0x1534 targets 0x1680, is taken when ra(=([ret(part_get_nasid)+4] << 0xa)) < 0 (signed), and falls through when ra(=([ret(part_get_nasid)+4] << 0xa)) >= 0 (signed).
  The `bltz` branch at 0x1554 targets 0x166c, is taken when v0(=(one of -0x1, 0x1, 0x2, 0x3 << 0x1e)) < 0 (signed), and falls through when v0(=(one of -0x1, 0x1, 0x2, 0x3 << 0x1e)) >= 0 (signed).
  The `beq` branch at 0x1584 targets 0x1428 and is always taken.
  The `bne` branch at 0x1594 targets 0x1704, is taken when a3(?) != a4(=0x1), and falls through when a3(?) == a4(=0x1).
  The `bne` branch at 0x159c targets 0x13ec, is taken when s1(?) != 0, and falls through when s1(?) == 0.
  The `beq` branch at 0x15b8 targets 0x1484 and is always taken.
  The `beq` branch at 0x15c0 targets 0x14d0, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x15d8 targets 0x1688, is taken when v0(=ret(part_from_addr)) == a2(=[ret(part_get)+20]:1), and falls through when v0(=ret(part_from_addr)) != a2(=[ret(part_get)+20]:1).
  The `bltz` branch at 0x15e8 targets 0x15f8, is taken when a3(?) < 0 (signed), and falls through when a3(?) >= 0 (signed).
  The `bne` branch at 0x15f0 targets 0x16f0, is taken when a4(?) != 0, and falls through when a4(?) == 0.
  The `beq` branch at 0x160c targets 0x1484 and is always taken.
  The `beq` branch at 0x1628 targets 0x1484 and is always taken.
  The `beq` branch at 0x1654 targets 0x146c and is always taken.
  The `beq` branch at 0x165c targets 0x155c and is always taken.
  The `beq` branch at 0x1664 targets 0x1550 and is always taken.
  The `beq` branch at 0x1678 targets 0x156c and is always taken.
  The `beq` branch at 0x1680 targets 0x154c and is always taken.
  The `beq` branch at 0x1694 targets 0x158c, is taken when v0(=ret(part_copy_fault)) == 0, and falls through when v0(=ret(part_copy_fault)) != 0.
  The `beq` branch at 0x16b0 targets 0x1484 and is always taken.
  The `beq` branch at 0x16cc targets 0x1478 and is always taken.
  The `beq` branch at 0x16e8 targets 0x1520 and is always taken.
  The `beq` branch at 0x16fc targets 0x15fc and is always taken.
  The `beq` branch at 0x174c targets 0x1484 and is always taken.
  The return at 0x1494 has v0 = one of ret(mutex_spinunlock), ret(part_deactivate).

- `part_deactivate` in `IP35/usr/cpu/sysgen/IP35boot/partition.o` at 0x1754 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/partition.o`.
  Range: 0x1754-0x1878 (292 bytes).
  It occupies 292 bytes.
  The `lw` at 0x1778 loads 4 bytes from ret(part_get) +0x20.
  The `sw` at 0x1788 stores 4 bytes to ret(part_get) +0xc.
  The `ld` at 0x17a8 loads 8 bytes from (sym(.rodata) + ([ret(part_get)+32] << 0x3)) +0x0.
  The `lw` at 0x1874 loads 4 bytes from ret(part_get) +0xc.
  The `jal` at 0x175c calls part_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1770 calls mutex_spinlock with a0=ret(part_get)+8, a1=?, a2=?, a3=?.
  Calls (unknown callee) via register with a0=ret(part_get)+152, a1=ret(mutex_spinlock), a2=[ret(part_get)+32], a3=?, a5=(sym(.rodata) + ([ret(part_get)+32] << 0x3)), a6=[(sym(.rodata) + ([ret(part_get)+32] << 0x3))]:8 (`jr` at 0x17ac).
  The `jal` at 0x17d0 calls mutex_spinunlock with a0=ret(part_get)+8, a1=[ret(part_get)+12], a2=?, a3=?.
  The `jal` at 0x1868 calls cmn_err with a0=0x0, a1=sym(.rodata), a2=[ret(part_get)+32], a3=?, a5=(sym(.rodata) + ([ret(part_get)+32] << 0x3)), a6=([ret(part_get)+32] << 0x3).
  The `beq` branch at 0x1764 targets 0x17d8, is taken when v0(=ret(part_get)) == 0, and falls through when v0(=ret(part_get)) != 0.
  The `beq` branch at 0x17a0 targets 0x1860, is taken when a6(=[ret(part_get)+32]) >= 0x9 (unsigned), and falls through when a6(=[ret(part_get)+32]) < 0x9 (unsigned).
  The `beq` branch at 0x1870 targets 0x17c8 and is always taken.
  The return at 0x17e0 has v0 = one of ret(part_get), ret(mutex_spinunlock).
  The instructions from 0x17b4 to 0x17c4 are not reached by any path from the entry, and their branches are not listed.
  The instructions from 0x17e8 to 0x185c are not reached by any path from the entry, and their branches are not listed.
  The indirect jump at 0x17ac uses a jump table whose successors are unresolved.

- `part_terminate` in `IP35/usr/cpu/sysgen/IP35boot/partition.o` at 0x1878 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/partition.o`.
  Range: 0x1878-0x1bc8 (848 bytes).
  It occupies 848 bytes.
  The `ld` at 0x1880 loads 8 bytes from a0 (arg0 at entry) +0x20.
  The `lw` at 0x18a0 loads 4 bytes from [a0+32]:8 +0x20.
  3 such `sw` accesses store 4 bytes to [a0+32]:8 +0xc, including `sw` at 0x18ac, `sw` at 0x1ae4, `sw` at 0x1b14.
  2 such `sw` accesses store 4 bytes to [a0+32]:8 +0x20, including `sw` at 0x18c8, `sw` at 0x1b28.
  3 such `lb` accesses load 1 byte from [a0+32]:8 +0x14, including `lb` at 0x18f0, `lb` at 0x19e0, `lb` at 0x1aac.
  The `lh` at 0x1958 loads 2 bytes from ?.
  The `ld` at 0x1964 loads 8 bytes from [a0+32]:8 +0x18.
  7 such `ld` accesses load 8 bytes from ?, including `ld` at 0x1974, `ld` at 0x1a30, `ld` at 0x1a60.
  6 such `sd` accesses store 8 bytes to ?, including `sd` at 0x19a4, `sd` at 0x19a8, `sd` at 0x1a4c.
  The `sd` at 0x19d0 stores 8 bytes to [a0+32]:8 +0x18.
  2 such `lb` accesses load 1 byte from ?, including `lb` at 0x19e8, `lb` at 0x1ab0.
  2 such `sb` accesses store 1 byte to ?, including `sb` at 0x19fc, `sb` at 0x1a00.
  The `lw` at 0x1a80 loads 4 bytes from [a0+32]:8 +0xc.
  The `ld` at 0x1a98 loads 8 bytes from sym(.bss) +0x8.
  2 such `lw` accesses load 4 bytes from [a0+32]:8 +0x58, including `lw` at 0x1adc, `lw` at 0x1b08.
  2 such `lw` accesses load 4 bytes from [a0+32]:8 +0x5c, including `lw` at 0x1b18, `lw` at 0x1bb4.
  The `jal` at 0x1898 calls mutex_spinlock with a0=[a0+32]:8+8, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x18b4 calls mutex_spinunlock with a0=[a0+32]:8+8, a1=ret(mutex_spinlock), a2=?, a3=?.
  The `jal` at 0x18bc calls part_interrupt_thread_exit with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x18d4 calls mutex_spinlock with a0=sym(.sbss)+12, a1=0x8, a2=?, a3=?.
  The `jal` at 0x18e8 calls part_get_var with a0=[sym(partition_partid)]:1, a1=0x3, a2=sp-64, a3=?.
  The `jal` at 0x190c calls part_set_var with a0=0x3, a1=?, a2=?, a3=?.
  The `jal` at 0x1918 calls mutex_spinunlock with a0=sym(.sbss)+12, a1=ret(mutex_spinlock), a2=?, a3=?.
  The `jal` at 0x1920 calls mutex_spinlock with a0=sym(.sbss)+16, a1=?, a2=?, a3=?.
  The `jal` at 0x19bc calls mutex_spinunlock with a0=sym(.sbss)+16, a1=ret(mutex_spinlock), a2=?, a3=?.
  The `jal` at 0x1a7c calls mutex_spinunlock with a0=[a0+32]:8+8, a1=[[a0+32]:8+12], a2=?, a3=[[a0+32]:8+20]:1, a6=sym(.bss).
  The `jal` at 0x1a84 calls part_call_deactivate_handlers with a0=[a0+32]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x1a90 calls mutex_spinlock_spl with a0=sym(.sbss), a1=sym(splerr), a2=?, a3=?.
  The `jal` at 0x1acc calls mutex_spinunlock with a0=sym(.sbss), a1=?, a2=?, a3=?.
  The `jal` at 0x1ad4 calls mutex_spinlock with a0=[a0+32]:8+8, a1=?, a2=?, a3=?.
  The `jal` at 0x1af8 calls sv_wait with a0=[a0+32]:8+152, a1=0x19, a2=[a0+32]:8+8, a3=ret(mutex_spinlock).
  The `jal` at 0x1b00 calls mutex_spinlock with a0=[a0+32]:8+8, a1=?, a2=?, a3=?.
  The `jal` at 0x1b2c calls mutex_spinunlock with a0=[a0+32]:8+8, a1=ret(mutex_spinlock), a2=?, a3=ret(mutex_spinlock).
  The `jal` at 0x1b3c calls part_interrupt_thread_exit with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x1b5c calls part_hold_page with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1b68 calls mutex_spinunlock with a0=sym(.sbss), a1=[sym(.sbss)+4], a2=?, a3=?.
  The `jalr` at 0x1b80 calls (unknown callee) with a0=0x0, a1=?, a2=0xb, a3=?.
  The `jal` at 0x1b8c calls mutex_spinlock_spl with a0=sym(.sbss), a1=sym(splerr), a2=?, a3=?.
  The `jal` at 0x1b9c calls part_release_page_nolock with a0=?, a1=?, a2=?, a3=?.
  The `beq` branch at 0x18a8 targets 0x18c4, is taken when at(=[[a0+32]:8+32]) == v1(=0x7), and falls through when at(=[[a0+32]:8+32]) != v1(=0x7).
  The `blez` branch at 0x1934 targets 0x19bc, is taken when a3(=[sym(maxnodes)]) <= 0 (signed), and falls through when a3(=[sym(maxnodes)]) > 0 (signed).
  The `bne` branch at 0x19a0 targets 0x1988, is taken when a3(?) < 0x2 (signed), and falls through when a3(?) >= 0x2 (signed).
  The `bne` branch at 0x19b4 targets 0x1954, is taken when t2(?) < v0(=[sym(maxnodes)]) (signed), and falls through when t2(?) >= v0(=[sym(maxnodes)]) (signed).
  The `bne` branch at 0x19f4 targets 0x1a04, is taken when v1(?) != a3(=[[a0+32]:8+20]:1), and falls through when v1(?) == a3(=[[a0+32]:8+20]:1).
  The `bne` branch at 0x1a04 targets 0x19d8, is taken when a1(?) != 0, and falls through when a1(?) == 0.
  The `beq` branch at 0x1a0c targets 0x1a1c and is always taken.
  The `beq` branch at 0x1a14 targets 0x1a7c, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `bne` branch at 0x1a44 targets 0x1a54, is taken when a4(?) != s0(=[a0+32]:8), and falls through when a4(?) == s0(=[a0+32]:8).
  The `beq` branch at 0x1a54 targets 0x1a7c, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `bne` branch at 0x1a64 targets 0x1a14, is taken when t0(?) != s0(=[a0+32]:8), and falls through when t0(?) == s0(=[a0+32]:8).
  The `beq` branch at 0x1a70 targets 0x1a14 and is always taken.
  The `beq` branch at 0x1aa4 targets 0x1acc, is taken when t1(=[sym(.bss)+8]:8) == 0, and falls through when t1(=[sym(.bss)+8]:8) != 0.
  The `beq` branch at 0x1ab4 targets 0x1b5c, is taken when t2(?) == v0(=[[a0+32]:8+20]:1), and falls through when t2(?) != v0(=[[a0+32]:8+20]:1).
  The `bne` branch at 0x1ac0 targets 0x1ab0, is taken when t3(?) != 0, and falls through when t3(?) == 0.
  The `beq` branch at 0x1ae8 targets 0x1bb4, is taken when s2(=[[a0+32]:8+88]) == 0, and falls through when s2(=[[a0+32]:8+88]) != 0.
  The `bne` branch at 0x1b10 targets 0x1af0, is taken when t8(=[[a0+32]:8+88]) != 0, and falls through when t8(=[[a0+32]:8+88]) == 0.
  The `bne` branch at 0x1b1c targets 0x1af0, is taken when t9(=[[a0+32]:8+92]) != 0, and falls through when t9(=[[a0+32]:8+92]) == 0.
  The `beq` branch at 0x1b74 targets 0x1b88, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `bne` branch at 0x1ba4 targets 0x1aac, is taken when s2(?) != 0, and falls through when s2(?) == 0.
  The `beq` branch at 0x1bac targets 0x1acc and is always taken.
  The `bne` branch at 0x1bb8 targets 0x1af0, is taken when at(=[[a0+32]:8+92]) != 0, and falls through when at(=[[a0+32]:8+92]) == 0.
  The `beq` branch at 0x1bc0 targets 0x1b24 and is always taken.
  The return at 0x1b54 has v0 = ret(part_interrupt_thread_exit).
  The instructions from 0x1a78 to 0x1a78 are not reached by any path from the entry, and their branches are not listed.

- `part_copy_fault` in `IP35/usr/cpu/sysgen/IP35boot/partition.o` at 0x1bc8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/partition.o`.
  Range: 0x1bc8-0x1c34 (108 bytes).
  It occupies 108 bytes.
  The `jal` at 0x1bf4 calls _badaddr_val with a0=?, a1=0x4, a2=?, a3=?.
  The `beq` branch at 0x1be4 targets 0x1c2c, is taken when s2(=a2-4) == 0, and falls through when s2(=a2-4) != 0.
  The `beq` branch at 0x1bfc targets 0x1c20, is taken when v0(=ret(_badaddr_val)) == 0, and falls through when v0(=ret(_badaddr_val)) != 0.
  The `bne` branch at 0x1c24 targets 0x1bec, is taken when s2(?) != 0, and falls through when s2(?) == 0.
  The `beq` branch at 0x1c2c targets 0x1c08 and is always taken.
  The return at 0x1c18 has v0 = one of -0x1, 0x0.

- `part_probe_nasid` in `IP35/usr/cpu/sysgen/IP35boot/partition.o` at 0x1c34 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/partition.o`.
  Range: 0x1c34-0x1f6c (824 bytes).
  It occupies 824 bytes.
  4 such `lb` accesses load 1 byte from table(sym(.bss)) +0x3506, including `lb` at 0x1c9c, `lb` at 0x1d54, `lb` at 0x1ec0.
  4 such `sh` accesses store 2 bytes to table(sym(.bss)) +0x3500, including `sh` at 0x1cac, `sh` at 0x1cd4, `sh` at 0x1da4.
  6 such `sb` accesses store 1 byte to table(sym(.bss)) +0x3504, including `sb` at 0x1cdc, `sb` at 0x1d04, `sb` at 0x1d28.
  2 such `lbu` accesses load 1 byte from table(sym(.bss)) +0x3504, including `lbu` at 0x1d70, `lbu` at 0x1e30.
  The `sb` at 0x1d7c stores 1 byte to table(sym(.bss)) +0x3506.
  The `lw` at 0x1d8c loads 4 bytes from table(sym(.bss)) +0x3504.
  The `sh` at 0x1dbc stores 2 bytes to table(sym(.bss)) +0x350e.
  The `sh` at 0x1dd0 stores 2 bytes to table(sym(.bss)) +0x350a.
  The `sh` at 0x1de8 stores 2 bytes to table(sym(.bss)) +0x3508.
  The `sh` at 0x1dfc stores 2 bytes to table(sym(.bss)) +0x350c.
  The `sw` at 0x1e24 stores 4 bytes to table(sym(.bss)) +0x3504.
  The `sb` at 0x1e2c stores 1 byte to table(sym(.bss)) +0x3507.
  The `ld` at 0x1e78 loads 8 bytes from ?.
  The `sd` at 0x1e80 stores 8 bytes to table(sym(.bss)) +0x4308.
  The `sd` at 0x1e90 stores 8 bytes to ?.
  The `lw` at 0x1e94 loads 4 bytes from ?.
  2 such `sw` accesses store 4 bytes to ?, including `sw` at 0x1ea4, `sw` at 0x1ef8.
  2 such `sb` accesses store 1 byte to table(sym(.bss)) +0x115, including `sb` at 0x1f5c, `sb` at 0x1f68.
  The `jal` at 0x1c74 calls part_copy_fault with a0=((a0 << 0x21)+0x9600000000000000 | 0x2000)+576, a1=sp-128, a2=0x40, a3=a3 at entry (arg3).
  The `jal` at 0x1cf0 calls part_copy_fault with a0=?, a1=sp-64, a2=0x10, a3=?.
  The `jal` at 0x1d64 calls part_deactivate with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1e8c calls mutex_spinlock with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1ea8 calls mutex_spinunlock with a0=?, a1=ret(mutex_spinlock), a2=?, a3=?.
  The `jal` at 0x1efc calls part_deactivate with a0=[table(sym(.bss))+13574]:1, a1=table(sym(.bss)), a2=?, a3=?.
  The `jal` at 0x1f14 calls cmn_err with a0=0x4, a1=sym(.rodata), a2=a0 at entry (arg0), a3=[table(sym(.bss))+13574]:1.
  The `jal` at 0x1f24 calls is_specified with a0=sym(arg_clusterid), a1=?, a2=?, a3=[table(sym(.bss))+13572]:1, a5=[sym(cell_enabled)].
  The `jal` at 0x1f50 calls atoi with a0=sym(arg_clusterid), a1=table(sym(.bss)), a2=?, a3=?.
  The `beq` branch at 0x1c94 targets 0x1cc8, is taken when v0(=ret(part_copy_fault)) == 0, and falls through when v0(=ret(part_copy_fault)) != 0.
  The `bne` branch at 0x1ca4 targets 0x1efc, is taken when a0(=[table(sym(.bss))+13574]:1) != s2(=-0x1), and falls through when a0(=[table(sym(.bss))+13574]:1) == s2(=-0x1).
  The `beq` branch at 0x1cd0 targets 0x1ce0, is taken when (v0(?) & 0x7) == 0, and falls through when (v0(?) & 0x7) != 0.
  The `beq` branch at 0x1cd8 targets 0x1cb0 and is always taken.
  The `beq` branch at 0x1cf8 targets 0x1d08, is taken when v0(=ret(part_copy_fault)) == 0, and falls through when v0(=ret(part_copy_fault)) != 0.
  The `beq` branch at 0x1d00 targets 0x1cb0 and is always taken.
  The `bne` branch at 0x1d0c targets 0x1eb8, is taken when a1(?) != a2(=0x434d5f53505f5357), and falls through when a1(?) == a2(=0x434d5f53505f5357).
  The `beq` branch at 0x1d1c targets 0x1d2c, is taken when a0(=0x1) == a3(?), and falls through when a0(=0x1) != a3(?).
  The `beq` branch at 0x1d24 targets 0x1cb0 and is always taken.
  The `blez` branch at 0x1d2c targets 0x1ee0, is taken when v0(?) <= 0 (signed), and falls through when v0(?) > 0 (signed).
  The `beq` branch at 0x1d34 targets 0x1ee0, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `bltz` branch at 0x1d44 targets 0x1d54, is taken when a0(?) < 0 (signed), and falls through when a0(?) >= 0 (signed).
  The `bne` branch at 0x1d4c targets 0x1ec0, is taken when a1(?) != 0, and falls through when a1(?) == 0.
  The `beq` branch at 0x1d5c targets 0x1ee8, is taken when a2(=[table(sym(.bss))+13574]:1) == a0(=-0x1), and falls through when a2(=[table(sym(.bss))+13574]:1) != a0(=-0x1).
  The `beq` branch at 0x1d74 targets 0x1cb0, is taken when a3(=[table(sym(.bss))+13572]:1) == v0(?), and falls through when a3(=[table(sym(.bss))+13572]:1) != v0(?).
  The `bne` branch at 0x1e28 targets 0x1f24, is taken when a5(=[sym(cell_enabled)]) != 0, and falls through when a5(=[sym(cell_enabled)]) == 0.
  The `bne` branch at 0x1e38 targets 0x1cb0, is taken when t2(=[table(sym(.bss))+13572]:1) != t3(=0x4), and falls through when t2(=[table(sym(.bss))+13572]:1) == t3(=0x4).
  The `beq` branch at 0x1ea0 targets 0x1ef0, is taken when ra(?) == at(=0x1), and falls through when ra(?) != at(=0x1).
  The `beq` branch at 0x1eb0 targets 0x1cb4 and is always taken.
  The `beq` branch at 0x1eb8 targets 0x1cb0 and is always taken.
  The `beq` branch at 0x1ec8 targets 0x1d70, is taken when a1(=[table(sym(.bss))+13574]:1) == v1(=-0x1), and falls through when a1(=[table(sym(.bss))+13574]:1) != v1(=-0x1).
  The `beq` branch at 0x1ed0 targets 0x1d70, is taken when a1(=[table(sym(.bss))+13574]:1) == a0(?), and falls through when a1(=[table(sym(.bss))+13574]:1) != a0(?).
  The `beq` branch at 0x1ed8 targets 0x1d64 and is always taken.
  The `beq` branch at 0x1ee0 targets 0x1cb0 and is always taken.
  The `beq` branch at 0x1ee8 targets 0x1d70 and is always taken.
  The `beq` branch at 0x1ef4 targets 0x1ea8 and is always taken.
  The `beq` branch at 0x1f1c targets 0x1cb0 and is always taken.
  The `beq` branch at 0x1f48 targets 0x1f60, is taken when v0(=ret(is_specified)) == 0, and falls through when v0(=ret(is_specified)) != 0.
  The `beq` branch at 0x1f58 targets 0x1e30 and is always taken.
  The `beq` branch at 0x1f64 targets 0x1e30 and is always taken.
  The return at 0x1cc0 has v0 = one of ?, ret(mutex_spinunlock).

- `part_discovery` in `IP35/usr/cpu/sysgen/IP35boot/partition.o` at 0x1f6c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/partition.o`.
  Range: 0x1f6c-0x2240 (724 bytes).
  It occupies 724 bytes.
  The `ld` at 0x1fd0 loads 8 bytes from abs 0x9200000001680000.
  5 such `ld` accesses load 8 bytes from ?, including `ld` at 0x1fe8, `ld` at 0x2020, `ld` at 0x2050.
  The `lw` at 0x2160 loads 4 bytes from ?.
  2 such `sw` accesses store 4 bytes to ?, including `sw` at 0x2168, `sw` at 0x2180.
  The `jal` at 0x1f9c calls cpsema with a0=sym(.bss), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1fac calls cpsema with a0=sym(.bss), a1=?, a2=?, a3=?.
  The `jal` at 0x20a8 calls get_nasid with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x20b0 calls part_probe_nasid with a0=ret(get_nasid), a1=?, a2=?, a3=?.
  The `jal` at 0x20f8 calls part_probe_nasid with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x211c calls mutex_spinunlock with a0=?, a1=ret(mutex_spinlock), a2=?, a3=?.
  The `jal` at 0x2158 calls mutex_spinlock with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x2188 calls mutex_spinunlock with a0=?, a1=ret(mutex_spinlock), a2=?, a3=?.
  The `jal` at 0x219c calls part_interrupt_set with a0=?, a1=0x2, a2=sym(part_activate), a3=?.
  The `jal` at 0x21ac calls part_start_partition_thread with a0=?, a1=0x2, a2=0x1, a3=?.
  The `jal` at 0x21f0 calls vector_read with a0=0x0, a1=0x0, a2=0x600000, a3=sp-64.
  The `jal` at 0x2220 calls part_probe_nasid with a0=?, a1=?, a2=?, a3=?.
  The `beq` branch at 0x1fa4 targets 0x1fc0, is taken when v0(=ret(cpsema)) == 0, and falls through when v0(=ret(cpsema)) != 0.
  The `bne` branch at 0x1fb4 targets 0x1fac, is taken when v0(=ret(cpsema)) != 0, and falls through when v0(=ret(cpsema)) == 0.
  The `beq` branch at 0x1fcc targets 0x1fe0 and is always taken.
  The `bgtz` branch at 0x1fd4 targets 0x2040, is taken when s0(?) > 0 (signed), and falls through when s0(?) <= 0 (signed).
  The `beq` branch at 0x1fdc targets 0x2040, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0x1ffc targets 0x2010, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `beq` branch at 0x2004 targets 0x2010, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `bgtz` branch at 0x2010 targets 0x2040, is taken when s0(?) > 0 (signed), and falls through when s0(?) <= 0 (signed).
  The `beq` branch at 0x2018 targets 0x2040, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x2028 targets 0x1fd4, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x2030 targets 0x1fd4, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x2038 targets 0x1fd4 and is always taken.
  The `bgtz` branch at 0x2048 targets 0x20a8, is taken when s0(?) > 0 (signed), and falls through when s0(?) <= 0 (signed).
  The `beq` branch at 0x205c targets 0x2070, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x2064 targets 0x2070, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `bgtz` branch at 0x2070 targets 0x20a8, is taken when v0(?) > 0 (signed), and falls through when v0(?) <= 0 (signed).
  The `bgtz` branch at 0x2078 targets 0x20a8, is taken when s0(?) > 0 (signed), and falls through when s0(?) <= 0 (signed).
  The `beq` branch at 0x208c targets 0x20a0, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x2094 targets 0x20a0, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `blez` branch at 0x20a0 targets 0x2048, is taken when v0(?) <= 0 (signed), and falls through when v0(?) > 0 (signed).
  The `beq` branch at 0x20b8 targets 0x21e0, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0x20c0 targets 0x2230 and is always taken.
  The `beq` branch at 0x20dc targets 0x2108, is taken when s0(?) >= 0x80 (signed), and falls through when s0(?) < 0x80 (signed).
  The `beq` branch at 0x20e8 targets 0x20c8, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x20f0 targets 0x20c8, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x2100 targets 0x20cc and is always taken.
  The `beq` branch at 0x2114 targets 0x2138 and is always taken.
  The `beq` branch at 0x2134 targets 0x21bc, is taken when s1(?) >= 0x40 (signed), and falls through when s1(?) < 0x40 (signed).
  The `beq` branch at 0x2164 targets 0x217c, is taken when a0(?) == s3(=0x2), and falls through when a0(?) != s3(=0x2).
  The `bne` branch at 0x216c targets 0x211c, is taken when a0(?) != s5(=0x7), and falls through when a0(?) == s5(=0x7).
  The `beq` branch at 0x2174 targets 0x2188 and is always taken.
  The `beq` branch at 0x21b4 targets 0x2128 and is always taken.
  The `beq` branch at 0x21e0 targets 0x2108, is taken when t9(?) == 0, and falls through when t9(?) != 0.
  The `bne` branch at 0x21f8 targets 0x210c, is taken when v0(=ret(vector_read)) != 0, and falls through when v0(=ret(vector_read)) == 0.
  The `bne` branch at 0x2210 targets 0x2108, is taken when ra(?) != at(=0x3012), and falls through when ra(?) == at(=0x3012).
  The `beq` branch at 0x2228 targets 0x210c and is always taken.
  The `beq` branch at 0x2238 targets 0x20e4 and is always taken.
  The return at 0x21d8 has v0 = ?.

- `part_spurious_interrupt` in `IP35/usr/cpu/sysgen/IP35boot/partition.o` at 0x2240 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/partition.o`.
  Range: 0x2240-0x22a8 (104 bytes).
  It occupies 104 bytes.
  The `lw` at 0x2254 loads 4 bytes from ret(part_get) +0x20.
  The `lld` at 0x227c loads 8 bytes from ret(part_get) +0x48.
  The `scd` at 0x2288 stores 8 bytes to ret(part_get) +0x48.
  The `lb` at 0x2294 loads 1 byte from ret(part_get) +0x14.
  The `jal` at 0x224c calls part_get with a0=?, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x2298 calls cmn_err with a0=0x4, a1=sym(.rodata), a2=[ret(part_get)+20]:1, a3=ret(part_get)+72, a4=0x1, a5=[ret(part_get)+72]:8+1.
  The `beq` branch at 0x225c targets 0x2270, is taken when a1(=[ret(part_get)+32]) == a2(=0x1), and falls through when a1(=[ret(part_get)+32]) != a2(=0x1).
  The `beql` branch at 0x228c targets 0x227c, is taken when a5(=[ret(part_get)+72]:8+1) == 0, and falls through when a5(=[ret(part_get)+72]:8+1) != 0; its branch-likely delay slot `nop` at 0x2290 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x22a0 targets 0x2268 and is always taken.
  The return at 0x2268 has v0 = one of ret(part_get), ret(cmn_err).

- `part_interrupt_thread` in `IP35/usr/cpu/sysgen/IP35boot/partition.o` at 0x22a8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/partition.o`.
  Range: 0x22a8-0x23c4 (284 bytes).
  It occupies 284 bytes.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x18, including `lw` at 0x22c4, `lw` at 0x236c, `lw` at 0x2388.
  The `ld` at 0x22d4 loads 8 bytes from a0 (arg0 at entry) +0x20.
  3 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x18, including `sw` at 0x22f0, `sw` at 0x237c, `sw` at 0x2390.
  2 such `lw` accesses load 4 bytes from [a0+32]:8 +0x80, including `lw` at 0x22fc, `lw` at 0x2384.
  2 such `ll` accesses load 4 bytes from [a0+32]:8 +0x6c, including `ll` at 0x2314, `ll` at 0x234c.
  2 such `sc` accesses store 4 bytes to [a0+32]:8 +0x6c, including `sc` at 0x2320, `sc` at 0x2358.
  The `ld` at 0x232c loads 8 bytes from [a0+32]:8 +0x50.
  The `lw` at 0x2330 loads 4 bytes from [a0+32]:8 +0x70.
  The `lb` at 0x2338 loads 1 byte from [a0+32]:8 +0x14.
  The `lw` at 0x2394 loads 4 bytes from [a0+32]:8 +0x68.
  The `jal` at 0x2308 calls compare_and_dec_int_gt with a0=[a0+32]:8+128, a1=0x0, a2=?, a3=?.
  The `jalr` at 0x2340 calls (unknown callee) with a0=[[a0+32]:8+20]:1, a1=?, a2=[[a0+32]:8+80]:8, a3=[[a0+32]:8+108]-1, a4=-0x1, a5=[[a0+32]:8+108]-1.
  The `jal` at 0x2378 calls ipsema with a0=[a0+32]:8+136, a1=?, a2=?, a3=?, a6=0x1, a7=[[a0+32]:8+108]+1.
  The `jal` at 0x23a4 calls part_interrupt_thread_exit with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x23b4 calls ipsema with a0=[a0+32]:8+136, a1=?, a2=?, a3=?.
  The `beq` branch at 0x22f4 targets 0x2310 and is always taken.
  The `beq` branch at 0x2300 targets 0x2388, is taken when v0(=[[a0+32]:8+128]) == 0, and falls through when v0(=[[a0+32]:8+128]) != 0.
  The `beql` branch at 0x2324 targets 0x2314, is taken when a5(=[[a0+32]:8+108]-1) == 0, and falls through when a5(=[[a0+32]:8+108]-1) != 0; its branch-likely delay slot `nop` at 0x2328 runs only when taken and is annulled on fall-through.
  The `beql` branch at 0x235c targets 0x234c, is taken when a7(=[[a0+32]:8+108]+1) == 0, and falls through when a7(=[[a0+32]:8+108]+1) != 0; its branch-likely delay slot `nop` at 0x2360 runs only when taken and is annulled on fall-through.
  The `bne` branch at 0x2364 targets 0x22fc, is taken when s2(=[[a0+32]:8+108]+1) != s4(=0x1), and falls through when s2(=[[a0+32]:8+108]+1) == s4(=0x1).
  The `beq` branch at 0x2380 targets 0x2300 and is always taken.
  The `beq` branch at 0x239c targets 0x23b4, is taken when t1(=[[a0+32]:8+104]) >= s2(=[[a0+32]:8+108]+1) (signed), and falls through when t1(=[[a0+32]:8+104]) < s2(=[[a0+32]:8+108]+1) (signed).
  The `beq` branch at 0x23ac targets 0x2314 and is always taken.
  The `beq` branch at 0x23bc targets 0x2314 and is always taken.

- `part_interrupt_thread_setup` in `IP35/usr/cpu/sysgen/IP35boot/partition.o` at 0x23c4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/partition.o`.
  Range: 0x23c4-0x240c (72 bytes).
  It occupies 72 bytes.
  The `ld` at 0x23c8 loads 8 bytes from abs 0xffffffffffffc020.
  The `sd` at 0x23cc stores 8 bytes to a0 (arg0 at entry) +0x10.
  The `jal` at 0x23e4 calls xthread_set_func with a0=[-0x3fe0]:8, a1=sym(part_interrupt_thread), a2=a0 at entry (arg0), a3=a3 at entry (arg3).
  The `jal` at 0x23ec calls part_queue_xthread with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x23f4 calls part_interrupt_thread with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The return at 0x2404 has v0 = ret(part_interrupt_thread).

- `part_interrupt` in `IP35/usr/cpu/sysgen/IP35boot/partition.o` at 0x240c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/partition.o`.
  Range: 0x240c-0x2578 (364 bytes).
  It occupies 364 bytes.
  The `lh` at 0x240c loads 2 bytes from abs 0xffffffffffffc428.
  The `ld` at 0x241c loads 8 bytes from (sym(pdaindr) + ([-0x3bd8]:2 << 0x4)) +0x8.
  The `lbu` at 0x2420 loads 1 byte from [(sym(pdaindr) + ([-0x3bd8]:2 << 0x4))+8]:8 +0x528.
  The `lh` at 0x2424 loads 2 bytes from [(sym(pdaindr) + ([-0x3bd8]:2 << 0x4))+8]:8 +0x42c.
  The `ld` at 0x2460 loads 8 bytes from table(0x9200000001800000) +0x0.
  The `sd` at 0x2488 stores 8 bytes to table(0x9200000001800000) +0x0.
  The `ld` at 0x24bc loads 8 bytes from ?.
  2 such `lld` accesses load 8 bytes from ?, including `lld` at 0x24c4, `lld` at 0x2524.
  2 such `scd` accesses store 8 bytes to ?, including `scd` at 0x24d0, `scd` at 0x2530.
  2 such `lb` accesses load 1 byte from ?, including `lb` at 0x24dc, `lb` at 0x253c.
  The `jal` at 0x2548 calls vsema with a0=?, a1=?, a2=?, a3=?, a5=table(0x1), a7=0x1.
  The `bltz` branch at 0x2444 targets 0x2558, is taken when a5(=([[(sym(pdaindr) + ([-0x3bd8]:2 << 0x4))+8]:8+1320]:1 << 0x1e)) < 0 (signed), and falls through when a5(=([[(sym(pdaindr) + ([-0x3bd8]:2 << 0x4))+8]:8+1320]:1 << 0x1e)) >= 0 (signed).
  The `bltz` branch at 0x245c targets 0x2568, is taken when a5(=([[(sym(pdaindr) + ([-0x3bd8]:2 << 0x4))+8]:8+1320]:1 << 0x1e)) < 0 (signed), and falls through when a5(=([[(sym(pdaindr) + ([-0x3bd8]:2 << 0x4))+8]:8+1320]:1 << 0x1e)) >= 0 (signed).
  The `beq` branch at 0x2484 targets 0x24fc, is taken when s0(=entry(0x9200000001800000)) == 0, and falls through when s0(=entry(0x9200000001800000)) != 0.
  The `beq` branch at 0x2490 targets 0x24a8 and is always taken.
  The `beq` branch at 0x24a0 targets 0x24fc, is taken when t9(?) == 0, and falls through when t9(?) != 0.
  The `beq` branch at 0x24ac targets 0x2498, is taken when (s0(?) & 0x1) == 0, and falls through when (s0(?) & 0x1) != 0.
  The `beql` branch at 0x24d4 targets 0x24c4, is taken when a1(?) == 0, and falls through when a1(?) != 0; its branch-likely delay slot `nop` at 0x24d8 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x24e8 targets 0x251c, is taken when (s2(?) & at(?)) == 0, and falls through when (s2(?) & at(?)) != 0.
  The `bne` branch at 0x24f4 targets 0x24a8, is taken when a3(?) != 0, and falls through when a3(?) == 0.
  The `beql` branch at 0x2534 targets 0x2524, is taken when t0(=table(0x1)) == 0, and falls through when t0(=table(0x1)) != 0; its branch-likely delay slot `nop` at 0x2538 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x2550 targets 0x24f0 and is always taken.
  The `beq` branch at 0x2560 targets 0x2450 and is always taken.
  The `beq` branch at 0x2570 targets 0x2464 and is always taken.
  The return at 0x2514 has v0 = ?.

- `part_interrupt_id` in `IP35/usr/cpu/sysgen/IP35boot/partition.o` at 0x2578 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/partition.o`.
  Range: 0x2578-0x25a0 (40 bytes).
  It occupies 40 bytes.
  The `ld` at 0x259c loads 8 bytes from table(sym(.bss)) +0x40.
  The return at 0x2598 has v0 = [table(sym(.bss))+64]:8.

- `part_queue_xthread` in `IP35/usr/cpu/sysgen/IP35boot/partition.o` at 0x25a0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/partition.o`.
  Range: 0x25a0-0x26e8 (328 bytes).
  It occupies 328 bytes.
  The `ld` at 0x25a8 loads 8 bytes from a0 (arg0 at entry) +0x20.
  2 such `lw` accesses load 4 bytes from [a0+32]:8 +0x20, including `lw` at 0x25c8, `lw` at 0x265c.
  The `sw` at 0x25d4 stores 4 bytes to [a0+32]:8 +0xc.
  2 such `ld` accesses load 8 bytes from [a0+32]:8 +0xa8, including `ld` at 0x25d8, `ld` at 0x26e4.
  The `sd` at 0x25e0 stores 8 bytes to a0 (arg0 at entry) +0x0.
  The `sd` at 0x25e4 stores 8 bytes to a0 (arg0 at entry) +0x8.
  The `sd` at 0x25e8 stores 8 bytes to [[a0+32]:8+168]:8 +0x0.
  The `ld` at 0x25ec loads 8 bytes from a0 (arg0 at entry) +0x0.
  The `sd` at 0x25f0 stores 8 bytes to [a0]:8 +0x8.
  The `sw` at 0x25f8 stores 4 bytes to a0 (arg0 at entry) +0x18.
  The `lw` at 0x25fc loads 4 bytes from [a0+32]:8 +0x60.
  The `lw` at 0x2600 loads 4 bytes from [a0+32]:8 +0x64.
  The `sw` at 0x2624 stores 4 bytes to [a0+32]:8 +0x60.
  The `sw` at 0x2628 stores 4 bytes to [a0+32]:8 +0x64.
  The `ll` at 0x262c loads 4 bytes from [a0+32]:8 +0x70.
  The `sc` at 0x2638 stores 4 bytes to [a0+32]:8 +0x70.
  The `ll` at 0x2644 loads 4 bytes from [a0+32]:8 +0x6c.
  The `sc` at 0x2650 stores 4 bytes to [a0+32]:8 +0x6c.
  2 such `lw` accesses load 4 bytes from [a0+32]:8 +0xc, including `lw` at 0x2664, `lw` at 0x26d4.
  The `ll` at 0x26b4 loads 4 bytes from [a0+32]:8 +0x7c.
  The `sc` at 0x26c0 stores 4 bytes to [a0+32]:8 +0x7c.
  The `jal` at 0x25c0 calls mutex_spinlock with a0=[a0+32]:8+8, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x2668 calls mutex_spinunlock with a0=[a0+32]:8+8, a1=[[a0+32]:8+12], a2=?, a3=[a0+32]:8+108, a4=0x1, a5=-0x1, a6=[[a0+32]:8+32], a7=0x7.
  The `jal` at 0x2688 calls mutex_spinunlock with a0=[a0+32]:8+8, a1=[[a0+32]:8+12], a2=?, a3=[a0+32]:8+108, a4=0x1, a5=-0x1, a6=[[a0+32]:8+32], a7=0x7.
  The `jal` at 0x2690 calls part_terminate with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x26a4 calls kmem_free with a0=a0 at entry (arg0), a1=0x28, a2=?, a3=?.
  The `jal` at 0x26d0 calls mutex_spinunlock with a0=[a0+32]:8+8, a1=[[a0+32]:8+12], a2=?, a3=?.
  The `jal` at 0x26d8 calls xthread_exit with a0=?, a1=?, a2=?, a3=?.
  The `beq` branch at 0x25d0 targets 0x26a0, is taken when at(=[[a0+32]:8+32]) == v1(=0x8), and falls through when at(=[[a0+32]:8+32]) != v1(=0x8).
  The `beq` branch at 0x2620 targets 0x262c, is taken when a2(=[[a0+32]:8+100]) >= a1(=[[a0+32]:8+96]+1) (signed), and falls through when a2(=[[a0+32]:8+100]) < a1(=[[a0+32]:8+96]+1) (signed).
  The `beql` branch at 0x263c targets 0x262c, is taken when t3(=[[a0+32]:8+112]-1) == 0, and falls through when t3(=[[a0+32]:8+112]-1) != 0; its branch-likely delay slot `nop` at 0x2640 runs only when taken and is annulled on fall-through.
  The `beql` branch at 0x2654 targets 0x2644, is taken when t1(=[[a0+32]:8+108]+1) == 0, and falls through when t1(=[[a0+32]:8+108]+1) != 0; its branch-likely delay slot `nop` at 0x2658 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x2660 targets 0x2688, is taken when a6(=[[a0+32]:8+32]) == a7(=0x7), and falls through when a6(=[[a0+32]:8+32]) != a7(=0x7).
  The `beq` branch at 0x2698 targets 0x2674 and is always taken.
  The `beql` branch at 0x26c4 targets 0x26b4, is taken when at(=[[a0+32]:8+124]+1) == 0, and falls through when at(=[[a0+32]:8+124]+1) != 0; its branch-likely delay slot `nop` at 0x26c8 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x26e0 targets 0x25dc and is always taken.
  The return at 0x2680 has v0 = one of ret(mutex_spinunlock), ret(part_terminate).

- `part_dequeue_xthread` in `IP35/usr/cpu/sysgen/IP35boot/partition.o` at 0x26e8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/partition.o`.
  Range: 0x26e8-0x2770 (136 bytes).
  It occupies 136 bytes.
  The `ld` at 0x26f0 loads 8 bytes from a0 (arg0 at entry) +0x20.
  The `sw` at 0x2710 stores 4 bytes to [a0+32]:8 +0xc.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x0, including `ld` at 0x2714, `ld` at 0x2724.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x8, including `ld` at 0x2718, `ld` at 0x2720.
  The `sd` at 0x271c stores 8 bytes to [a0]:8 +0x8.
  The `sd` at 0x2728 stores 8 bytes to [a0+8]:8 +0x0.
  The `lw` at 0x272c loads 4 bytes from [a0+32]:8 +0x60.
  The `sw` at 0x2738 stores 4 bytes to [a0+32]:8 +0x60.
  The `lw` at 0x2748 loads 4 bytes from [a0+32]:8 +0xc.
  The `jal` at 0x2708 calls mutex_spinlock with a0=[a0+32]:8+8, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x2744 calls mutex_spinunlock with a0=[a0+32]:8+8, a1=[[a0+32]:8+12], a2=?, a3=?.
  The `jal` at 0x2760 calls sv_broadcast with a0=[a0+32]:8+152, a1=[a0]:8, a2=?, a3=?.
  The `beq` branch at 0x2734 targets 0x2760, is taken when at(=[[a0+32]:8+96]-1) == 0, and falls through when at(=[[a0+32]:8+96]-1) != 0.
  The `beq` branch at 0x2768 targets 0x2740 and is always taken.
  The return at 0x2758 has v0 = ret(mutex_spinunlock).

- `part_start_partition_thread` in `IP35/usr/cpu/sysgen/IP35boot/partition.o` at 0x2770 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/partition.o`.
  Range: 0x2770-0x296c (508 bytes).
  It occupies 508 bytes.
  The `sd` at 0x2810 stores 8 bytes to ret(kmem_zalloc) +0x20.
  The `ll` at 0x2838 loads 4 bytes from a0 (arg0 at entry) +0x70.
  The `sc` at 0x2844 stores 4 bytes to a0 (arg0 at entry) +0x70.
  The `ll` at 0x2884 loads 4 bytes from a0 (arg0 at entry) +0x78.
  The `sc` at 0x2890 stores 4 bytes to a0 (arg0 at entry) +0x78.
  The `ll` at 0x28a4 loads 4 bytes from a0 (arg0 at entry) +0x74.
  The `sc` at 0x28b0 stores 4 bytes to a0 (arg0 at entry) +0x74.
  The `ll` at 0x28bc loads 4 bytes from a0 (arg0 at entry) +0x80.
  The `sc` at 0x28c8 stores 4 bytes to a0 (arg0 at entry) +0x80.
  The `ll` at 0x28e0 loads 4 bytes from a0 (arg0 at entry) +0x84.
  The `sc` at 0x28ec stores 4 bytes to a0 (arg0 at entry) +0x84.
  The `jal` at 0x27e4 calls kmem_zalloc with a0=0x28, a1=?, a2=?, a3=?.
  The `jal` at 0x27f8 calls kmem_alloc with a0=0x4000, a1=one of 0x100, 0x101, a2=?, a3=?.
  The `jal` at 0x2824 calls xthread_create with a0=a0 at entry (arg0), a1=ret(kmem_alloc), a2=0x4000, a3=0x1, a4=[sym(partition_pri)], a5=0x3000, a6=sym(part_interrupt_thread_setup), a7=ret(kmem_zalloc).
  The `jal` at 0x286c calls kmem_free with a0=ret(kmem_zalloc), a1=0x28, a2=0x4000, a3=?.
  The `jal` at 0x292c calls cvsema with a0=a0+136, a1=?, a2=?, a3=?.
  The `jal` at 0x2944 calls vsema with a0=a0+136, a1=?, a2=?, a3=?.
  The `jal` at 0x2954 calls vsema with a0=sym(.bss), a1=?, a2=?, a3=?.
  The `blez` branch at 0x27a8 targets 0x2964, is taken when a1 <= 0 (signed), and falls through when a1 > 0 (signed).
  The `beq` branch at 0x27dc targets 0x292c, is taken when s3(=a2) == 0, and falls through when s3(=a2) != 0.
  The `beq` branch at 0x27ec targets 0x2874, is taken when v0(=ret(kmem_zalloc)) == 0, and falls through when v0(=ret(kmem_zalloc)) != 0.
  The `beq` branch at 0x2800 targets 0x2868, is taken when v0(=ret(kmem_alloc)) == 0, and falls through when v0(=ret(kmem_alloc)) != 0.
  The `beql` branch at 0x2848 targets 0x2838, is taken when a4(=[a0+112]+1) == 0, and falls through when a4(=[a0+112]+1) != 0; its branch-likely delay slot `nop` at 0x284c runs only when taken and is annulled on fall-through.
  The `bne` branch at 0x2858 targets 0x27dc, is taken when s0(?) < s4(=a1) (signed), and falls through when s0(?) >= s4(=a1) (signed).
  The `beq` branch at 0x2860 targets 0x2878 and is always taken.
  The `beql` branch at 0x2894 targets 0x2884, is taken when t1(?) == 0, and falls through when t1(?) != 0; its branch-likely delay slot `nop` at 0x2898 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x289c targets 0x2900, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `beql` branch at 0x28b4 targets 0x28a4, is taken when t9(?) == 0, and falls through when t9(?) != 0; its branch-likely delay slot `nop` at 0x28b8 runs only when taken and is annulled on fall-through.
  The `beql` branch at 0x28cc targets 0x28bc, is taken when t3(?) == 0, and falls through when t3(?) != 0; its branch-likely delay slot `nop` at 0x28d0 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x28d8 targets 0x2944, is taken when s3(?) >= t2(?) (signed), and falls through when s3(?) < t2(?) (signed).
  The `beql` branch at 0x28f0 targets 0x28e0, is taken when v0(?) == 0, and falls through when v0(?) != 0; its branch-likely delay slot `nop` at 0x28f4 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x28f8 targets 0x2954, is taken when ra(?) == s3(?), and falls through when ra(?) != s3(?).
  The `bne` branch at 0x2934 targets 0x2850, is taken when v0(=ret(cvsema)) != 0, and falls through when v0(=ret(cvsema)) == 0.
  The `beq` branch at 0x293c targets 0x27e4 and is always taken.
  The `beq` branch at 0x294c targets 0x28e0 and is always taken.
  The `beq` branch at 0x295c targets 0x2904 and is always taken.
  The `beq` branch at 0x2964 targets 0x2878 and is always taken.
  The return at 0x2924 has v0 = ?.

- `part_start_thread` in `IP35/usr/cpu/sysgen/IP35boot/partition.o` at 0x296c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/partition.o`.
  Range: 0x296c-0x29a4 (56 bytes).
  It occupies 56 bytes.
  The `jal` at 0x297c calls part_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x298c calls part_start_partition_thread with a0=ret(part_get), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=?.
  The return at 0x299c has v0 = ret(part_start_partition_thread).

- `part_interrupt_reset` in `IP35/usr/cpu/sysgen/IP35boot/partition.o` at 0x29a4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/partition.o`.
  Range: 0x29a4-0x2a38 (148 bytes).
  It occupies 148 bytes.
  The `ld` at 0x29ac loads 8 bytes from a0 (arg0 at entry) +0xa0.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0x29cc, `ld` at 0x29d8.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x60, including `lw` at 0x29e4, `lw` at 0x29fc.
  The `sd` at 0x2a28 stores 8 bytes to a0 (arg0 at entry) +0x50.
  The `jal` at 0x29d0 calls xthread_set_func with a0=?, a1=sym(part_interrupt_thread_exit), a2=?, a3=?.
  The `jal` at 0x29f4 calls vsema with a0=a0+136, a1=?, a2=?, a3=?.
  The `jal` at 0x2a18 calls sv_broadcast with a0=a0+152, a1=?, a2=?, a3=?.
  The `beq` branch at 0x29c0 targets 0x29e4, is taken when s2(=a0+160) == s0(=[a0+160]:8), and falls through when s2(=a0+160) != s0(=[a0+160]:8).
  The `bne` branch at 0x29dc targets 0x29cc, is taken when s2(=a0+160) != s0(?), and falls through when s2(=a0+160) == s0(?).
  The `blez` branch at 0x29ec targets 0x2a10, is taken when at(=[a0+96]) <= 0 (signed), and falls through when at(=[a0+96]) > 0 (signed).
  The `bne` branch at 0x2a08 targets 0x29f4, is taken when s0(?) < v0(=[a0+96]) (signed), and falls through when s0(?) >= v0(=[a0+96]) (signed).
  The return at 0x2a30 has v0 = ret(sv_broadcast).

- `part_interrupt_set` in `IP35/usr/cpu/sysgen/IP35boot/partition.o` at 0x2a38 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/partition.o`.
  Range: 0x2a38-0x2aa8 (112 bytes).
  It occupies 112 bytes.
  The `sw` at 0x2a6c stores 4 bytes to ret(part_get) +0xc.
  The `sd` at 0x2a74 stores 8 bytes to ret(part_get) +0x50.
  The `sw` at 0x2a78 stores 4 bytes to ret(part_get) +0x68.
  The `lw` at 0x2aa4 loads 4 bytes from ret(part_get) +0xc.
  The `jal` at 0x2a4c calls part_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x2a5c calls mutex_spinlock with a0=ret(part_get)+8, a1=?, a2=?, a3=?.
  The `jal` at 0x2a84 calls mutex_spinunlock with a0=ret(part_get)+8, a1=?, a2=?, a3=?.
  The `jal` at 0x2a98 calls part_interrupt_reset with a0=ret(part_get), a1=ret(mutex_spinlock), a2=?, a3=?.
  The `beq` branch at 0x2a68 targets 0x2a98, is taken when s1(=a2) == 0, and falls through when s1(=a2) != 0.
  The `beq` branch at 0x2aa0 targets 0x2a7c and is always taken.
  The return at 0x2a90 has v0 = ret(mutex_spinunlock).

- `part_init_partition` in `IP35/usr/cpu/sysgen/IP35boot/partition.o` at 0x2aa8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/partition.o`.
  Range: 0x2aa8-0x2bb8 (272 bytes).
  It occupies 272 bytes.
  2 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x14, including `sb` at 0x2ae4, `sb` at 0x2bb4.
  The `sw` at 0x2aec stores 4 bytes to a0 (arg0 at entry) +0x20.
  The `sd` at 0x2af0 stores 8 bytes to a0 (arg0 at entry) +0x28.
  The `sd` at 0x2af4 stores 8 bytes to a0 (arg0 at entry) +0x30.
  The `sd` at 0x2af8 stores 8 bytes to a0 (arg0 at entry) +0x38.
  The `sw` at 0x2afc stores 4 bytes to a0 (arg0 at entry) +0x10.
  The `sd` at 0x2b00 stores 8 bytes to a0 (arg0 at entry) +0x40.
  The `sd` at 0x2b04 stores 8 bytes to a0 (arg0 at entry) +0x48.
  The `sw` at 0x2b08 stores 4 bytes to a0 (arg0 at entry) +0x60.
  The `sw` at 0x2b0c stores 4 bytes to a0 (arg0 at entry) +0x64.
  The `sw` at 0x2b10 stores 4 bytes to a0 (arg0 at entry) +0x6c.
  The `sw` at 0x2b14 stores 4 bytes to a0 (arg0 at entry) +0x68.
  The `sw` at 0x2b18 stores 4 bytes to a0 (arg0 at entry) +0x70.
  The `sw` at 0x2b1c stores 4 bytes to a0 (arg0 at entry) +0x78.
  The `sw` at 0x2b20 stores 4 bytes to a0 (arg0 at entry) +0x74.
  The `sw` at 0x2b24 stores 4 bytes to a0 (arg0 at entry) +0x80.
  The `sw` at 0x2b28 stores 4 bytes to a0 (arg0 at entry) +0x84.
  The `sw` at 0x2b2c stores 4 bytes to a0 (arg0 at entry) +0x7c.
  The `sd` at 0x2b30 stores 8 bytes to a0 (arg0 at entry) +0x18.
  The `sd` at 0x2b38 stores 8 bytes to a0 (arg0 at entry) +0xa8.
  The `sd` at 0x2b3c stores 8 bytes to a0 (arg0 at entry) +0xa0.
  The `sd` at 0x2b50 stores 8 bytes to a0 (arg0 at entry) +0x50.
  The `jal` at 0x2adc calls sprintf with a0=a0 at entry (arg0), a1=sym(.rodata), a2=a1 at entry (arg1), a3=a3 at entry (arg3).
  The `jal` at 0x2b54 calls init_spinlock with a0=a0+8, a1=sym(.rodata), a2=a0 at entry (arg0), a3=0x1, a4=a2 at entry (arg2).
  The `jal` at 0x2b6c calls init_sema with a0=a0+136, a1=0x0, a2=sym(.rodata), a3=a0 at entry (arg0).
  The `jal` at 0x2b88 calls init_sv with a0=a0+152, a1=0x0, a2=sym(.rodata), a3=a0 at entry (arg0).
  The `jal` at 0x2ba8 calls sprintf with a0=a0 at entry (arg0), a1=sym(.rodata), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `bltz` branch at 0x2ac0 targets 0x2ba0, is taken when a1 < 0 (signed), and falls through when a1 >= 0 (signed).
  The `beq` branch at 0x2acc targets 0x2ba4, is taken when a1 >= 0x40 (signed), and falls through when a1 < 0x40 (signed).
  The `beq` branch at 0x2bb0 targets 0x2ae8 and is always taken.
  The return at 0x2b98 has v0 = ret(init_sv).

- `part_init` in `IP35/usr/cpu/sysgen/IP35boot/partition.o` at 0x2bb8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/partition.o`.
  Range: 0x2bb8-0x3228 (1648 bytes).
  It occupies 1648 bytes.
  5 such `sb` accesses store 1 byte to ?, including `sb` at 0x2c10, `sb` at 0x2f64, `sb` at 0x2f78.
  11 such `lw` accesses load 4 bytes from ?, including `lw` at 0x2c18, `lw` at 0x2fac, `lw` at 0x2fd4.
  7 such `sh` accesses store 2 bytes to ?, including `sh` at 0x2c30, `sh` at 0x2f04, `sh` at 0x2f5c.
  11 such `sw` accesses store 4 bytes to ?, including `sw` at 0x2c40, `sw` at 0x2ef4, `sw` at 0x2efc.
  13 such `sd` accesses store 8 bytes to ?, including `sd` at 0x2c64, `sd` at 0x2c70, `sd` at 0x2ee4.
  5 such `ld` accesses load 8 bytes from ?, including `ld` at 0x2d90, `ld` at 0x30a8, `ld` at 0x30bc.
  The `lbu` at 0x2d9c loads 1 byte from ?.
  The `lh` at 0x2f68 loads 2 bytes from ret(find_lboard) +0xe.
  The `lh` at 0x309c loads 2 bytes from ?.
  The `jal` at 0x2bd0 calls bzero with a0=sym(.bss), a1=0xe00, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x2c9c calls part_init_partition with a0=?, a1=?, a2=sym(part_activate), a3=?.
  The `jal` at 0x2cc4 calls part_init_partition with a0=sym(.bss), a1=-0x1, a2=sym(part_discovery), a3=?.
  The `jal` at 0x2ccc calls vsema with a0=sym(.bss), a1=?, a2=?, a3=?.
  The `jal` at 0x2cdc calls spinlock_init with a0=sym(.sbss), a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x2ce8 calls spinlock_init with a0=sym(.sbss)+12, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x2cf4 calls spinlock_init with a0=sym(.sbss)+16, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x2d08 calls init_mutex with a0=sym(.bss), a1=0x0, a2=sym(.rodata), a3=-0x1.
  The `jal` at 0x2d14 calls part_init_nodes with a0=[sym(region_mask)]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x2d20 calls kmem_alloc with a0=0x180, a1=0x900, a2=?, a3=?.
  The `jal` at 0x2d30 calls bte_poison_range with a0=ret(kmem_alloc), a1=0x180, a2=?, a3=?.
  The `jal` at 0x2d7c calls cpu_enabled with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x2db0 calls intr_connect_level with a0=?, a1=?, a2=0x0, a3=sym(part_interrupt), a4=0x0, a5=0x0.
  The `jal` at 0x2dc8 calls part_get_promid with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x2e08 calls avl_init_tree with a0=sym(.bss), a1=sym(.data), a2=?, a3=?.
  The `jal` at 0x2e1c calls timeout_pri with a0=sym(part_heartbeat), a1=0x0, a2=[sym(.sdata)+24], a3=[sym(hb_pri)].
  The `jal` at 0x2e24 calls error_reg_partition_handler with a0=sym(part_error_handler), a1=?, a2=?, a3=?.
  The `jal` at 0x2e34 calls part_start_partition_thread with a0=sym(.bss), a1=0x1, a2=0x1, a3=?.
  The `jal` at 0x2e60 calls is_fine_dirmode with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x2e78 calls init_sema with a0=sym(.bss), a1=0x0, a2=sym(.rodata), a3=0x0.
  The `jal` at 0x2eac calls sthread_create with a0=sym(.rodata), a1=0x0, a2=0x0, a3=0x0, a4=[sym(partition_pri)], a5=0x1000, a6=sym(part_thread), a7=0x0.
  The `jal` at 0x2ed4 calls bzero with a0=?, a1=0x110, a2=?, a3=?.
  The `jal` at 0x2f94 calls cnode_slice_to_cpuid with a0=?, a1=0x0, a2=?, a3=?.
  The `jal` at 0x2f9c calls cpu_enabled with a0=ret(cnode_slice_to_cpuid), a1=?, a2=?, a3=?.
  The `jal` at 0x2fbc calls cnode_slice_to_cpuid with a0=?, a1=0x1, a2=?, a3=?.
  The `jal` at 0x2fc4 calls cpu_enabled with a0=ret(cnode_slice_to_cpuid), a1=?, a2=?, a3=?.
  The `jal` at 0x2fe4 calls cnode_slice_to_cpuid with a0=?, a1=0x2, a2=?, a3=?.
  The `jal` at 0x2fec calls cpu_enabled with a0=ret(cnode_slice_to_cpuid), a1=?, a2=?, a3=?.
  The `jal` at 0x300c calls cnode_slice_to_cpuid with a0=?, a1=0x3, a2=?, a3=?.
  The `jal` at 0x3014 calls cpu_enabled with a0=ret(cnode_slice_to_cpuid), a1=?, a2=?, a3=?.
  The `jal` at 0x3050 calls is_specified with a0=sym(arg_clusterid), a1=?, a2=?, a3=?.
  The `jal` at 0x3060 calls atoi with a0=sym(arg_clusterid), a1=?, a2=?, a3=?.
  The `jal` at 0x30e0 calls find_lboard with a0=?, a1=0x11, a2=?, a3=?.
  The `jal` at 0x3130 calls cnode_slice_to_cpuid with a0=?, a1=0x3, a2=?, a3=?.
  The `jal` at 0x3138 calls cpu_enabled with a0=ret(cnode_slice_to_cpuid), a1=?, a2=?, a3=?.
  The `jal` at 0x315c calls chk_for_pebrick with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x316c calls cnode_slice_to_cpuid with a0=?, a1=0x0, a2=?, a3=?.
  The `jal` at 0x3174 calls cpu_enabled with a0=ret(cnode_slice_to_cpuid), a1=?, a2=?, a3=?.
  The `jal` at 0x3198 calls cnode_slice_to_cpuid with a0=?, a1=0x1, a2=?, a3=?.
  The `jal` at 0x31a0 calls cpu_enabled with a0=ret(cnode_slice_to_cpuid), a1=?, a2=?, a3=?.
  The `jal` at 0x31c4 calls cnode_slice_to_cpuid with a0=?, a1=0x2, a2=?, a3=?.
  The `jal` at 0x31cc calls cpu_enabled with a0=ret(cnode_slice_to_cpuid), a1=?, a2=?, a3=?.
  The `jal` at 0x31ec calls cmn_err with a0=0x0, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x3200 calls cmn_err with a0=0x4, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x320c calls cmn_err with a0=0x4, a1=sym(.rodata), a2=?, a3=?.
  The `bne` branch at 0x2c3c targets 0x2c00, is taken when v0(?) < 0x80 (signed), and falls through when v0(?) >= 0x80 (signed).
  The `bne` branch at 0x2c6c targets 0x2c50, is taken when v0(?) < 0x40 (unsigned), and falls through when v0(?) >= 0x40 (unsigned).
  The `bne` branch at 0x2cb4 targets 0x2c80, is taken when s1(?) < 0x40 (signed), and falls through when s1(?) >= 0x40 (signed).
  The `bne` branch at 0x2d40 targets 0x31fc, is taken when v0(=ret(bte_poison_range)) != 0, and falls through when v0(=ret(bte_poison_range)) == 0.
  The `blez` branch at 0x2d48 targets 0x2dc8, is taken when a1(=[sym(maxcpus)]) <= 0 (signed), and falls through when a1(=[sym(maxcpus)]) > 0 (signed).
  The `beq` branch at 0x2d58 targets 0x2d7c and is always taken.
  The `beq` branch at 0x2d74 targets 0x2dc8, is taken when s1(?) >= t8(=[sym(maxcpus)]) (signed), and falls through when s1(?) < t8(=[sym(maxcpus)]) (signed).
  The `beq` branch at 0x2d84 targets 0x2d60, is taken when v0(=ret(cpu_enabled)) == 0, and falls through when v0(=ret(cpu_enabled)) != 0.
  The `beql` branch at 0x2db8 targets 0x2d64, is taken when v0(=ret(intr_connect_level)) == 0, and falls through when v0(=ret(intr_connect_level)) != 0; its branch-likely delay slot `addiu s1,s1,1` at 0x2dbc runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x2dc0 targets 0x31ec and is always taken.
  The `bltz` branch at 0x2dd8 targets 0x2dec, is taken when a1(?) < 0 (signed), and falls through when a1(?) >= 0 (signed).
  The `bne` branch at 0x2de4 targets 0x2e60, is taken when a1(?) < 0x40 (signed), and falls through when a1(?) >= 0x40 (signed).
  The `beq` branch at 0x2dec targets 0x2e3c and is always taken.
  The `beq` branch at 0x2f28 targets 0x2f38, is taken when ra(=[sym(kdebug)]:2) == 0, and falls through when ra(=[sym(kdebug)]:2) != 0.
  The `blez` branch at 0x2f3c targets 0x2df4, is taken when v0(=[sym(maxnodes)]) <= 0 (signed), and falls through when v0(=[sym(maxnodes)]) > 0 (signed).
  The `beq` branch at 0x2f50 targets 0x321c and is always taken.
  The `beq` branch at 0x2fa4 targets 0x2fbc, is taken when v0(=ret(cpu_enabled)) == 0, and falls through when v0(=ret(cpu_enabled)) != 0.
  The `beq` branch at 0x2fcc targets 0x2fe4, is taken when v0(=ret(cpu_enabled)) == 0, and falls through when v0(=ret(cpu_enabled)) != 0.
  The `beq` branch at 0x2ff4 targets 0x300c, is taken when v0(=ret(cpu_enabled)) == 0, and falls through when v0(=ret(cpu_enabled)) != 0.
  The `beq` branch at 0x301c targets 0x3030, is taken when v0(=ret(cpu_enabled)) == 0, and falls through when v0(=ret(cpu_enabled)) != 0.
  The `beq` branch at 0x3048 targets 0x3074, is taken when v1(=[sym(cell_enabled)]) == 0, and falls through when v1(=[sym(cell_enabled)]) != 0.
  The `beq` branch at 0x3058 targets 0x3074, is taken when v0(=ret(is_specified)) == 0, and falls through when v0(=ret(is_specified)) != 0.
  The `beq` branch at 0x308c targets 0x2df4, is taken when s1(?) >= a1(=[sym(maxnodes)]) (signed), and falls through when s1(?) < a1(=[sym(maxnodes)]) (signed).
  The `beq` branch at 0x30b4 targets 0x315c, is taken when s6(=0xc000) == t9(?), and falls through when s6(=0xc000) != t9(?).
  The `beq` branch at 0x30d4 targets 0x30e0, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `bne` branch at 0x30f4 targets 0x2f58, is taken when s5(=0x434d5f53505f5357) != a4(?), and falls through when s5(=0x434d5f53505f5357) == a4(?).
  The `bltz` branch at 0x3108 targets 0x316c, is taken when a6(?) < 0 (signed), and falls through when a6(?) >= 0 (signed).
  The `bltz` branch at 0x3114 targets 0x3194, is taken when a7(?) < 0 (signed), and falls through when a7(?) >= 0 (signed).
  The `bltz` branch at 0x311c targets 0x31c0, is taken when t0(?) < 0 (signed), and falls through when t0(?) >= 0 (signed).
  The `bgez` branch at 0x3124 targets 0x3048, is taken when t1(?) >= 0 (signed), and falls through when t1(?) < 0 (signed).
  The `bne` branch at 0x3140 targets 0x3048, is taken when v0(=ret(cpu_enabled)) != 0, and falls through when v0(=ret(cpu_enabled)) == 0.
  The `beq` branch at 0x3154 targets 0x3044 and is always taken.
  The `beq` branch at 0x3164 targets 0x30e0 and is always taken.
  The `bne` branch at 0x317c targets 0x3110, is taken when v0(=ret(cpu_enabled)) != 0, and falls through when v0(=ret(cpu_enabled)) == 0.
  The `beq` branch at 0x318c targets 0x3110 and is always taken.
  The `bne` branch at 0x31a8 targets 0x3118, is taken when v0(=ret(cpu_enabled)) != 0, and falls through when v0(=ret(cpu_enabled)) == 0.
  The `beq` branch at 0x31b8 targets 0x3118 and is always taken.
  The `bne` branch at 0x31d4 targets 0x3120, is taken when v0(=ret(cpu_enabled)) != 0, and falls through when v0(=ret(cpu_enabled)) == 0.
  The `beq` branch at 0x31e4 targets 0x3120 and is always taken.
  The `beq` branch at 0x31f4 targets 0x2d64 and is always taken.
  The `beq` branch at 0x3214 targets 0x2e40 and is always taken.
  The `beq` branch at 0x3220 targets 0x3098 and is always taken.
  The return at 0x2e58 has v0 = one of ?, ret(cmn_err).

- `part_init_nodes` in `IP35/usr/cpu/sysgen/IP35boot/partition.o` at 0x3228 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/partition.o`.
  Range: 0x3228-0x3358 (304 bytes).
  It occupies 304 bytes.
  The `jal` at 0x3258 calls init_sema with a0=sym(.bss), a1=0x0, a2=sym(.rodata), a3=-0x1.
  The `jal` at 0x32e4 calls sthread_create with a0=sym(.rodata), a1=0x0, a2=0x1000, a3=0x0, a4=[sym(partition_pri)], a5=0x1000, a6=sym(part_init_node), a7=a0 at entry (arg0).
  The `jal` at 0x3308 calls psema with a0=sym(.bss), a1=0x19, a2=?, a3=?.
  The `beq` branch at 0x327c targets 0x3328, is taken when a1(=[sym(maxnodes)]) == 0, and falls through when a1(=[sym(maxnodes)]) != 0.
  The `beq` branch at 0x3284 targets 0x32a0 and is always taken.
  The `beq` branch at 0x3294 targets 0x3328, is taken when s2(?) >= a1(=[sym(maxnodes)]) (unsigned), and falls through when s2(?) < a1(=[sym(maxnodes)]) (unsigned).
  The `beq` branch at 0x32b0 targets 0x328c, is taken when s4(?) >= s2(?) (unsigned), and falls through when s4(?) < s2(?) (unsigned).
  The `beq` branch at 0x32f4 targets 0x32bc, is taken when s1(?) >= s0(?) (unsigned), and falls through when s1(?) < s0(?) (unsigned).
  The `beq` branch at 0x32fc targets 0x328c, is taken when s7(?) == 0, and falls through when s7(?) != 0.
  The `bne` branch at 0x3318 targets 0x3308, is taken when s0(?) < s2(?) (unsigned), and falls through when s0(?) >= s2(?) (unsigned).
  The `beq` branch at 0x3320 targets 0x3290 and is always taken.
  The return at 0x3350 has v0 = one of ret(init_sema), ?.

- `part_from_addr` in `IP35/usr/cpu/sysgen/IP35boot/partition.o` at 0x3358 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/partition.o`.
  Range: 0x3358-0x3380 (40 bytes).
  It occupies 40 bytes.
  The `lb` at 0x337c loads 1 byte from table(sym(.bss)) +0x6.
  The return at 0x3378 has v0 = [table(sym(.bss))+6]:1.

- `part_from_region` in `IP35/usr/cpu/sysgen/IP35boot/partition.o` at 0x3380 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/partition.o`.
  Range: 0x3380-0x33a0 (32 bytes).
  It occupies 32 bytes.
  The `ld` at 0x3394 loads 8 bytes from table(sym(.bss)) +0x8.
  The `lb` at 0x339c loads 1 byte from [table(sym(.bss))+8]:8 +0x14.
  The return at 0x3398 has v0 = [[table(sym(.bss))+8]:8+20]:1.

- `part_get_promid` in `IP35/usr/cpu/sysgen/IP35boot/partition.o` at 0x33a0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/partition.o`.
  Range: 0x33a0-0x347c (220 bytes).
  It occupies 220 bytes.
  The `ld` at 0x33c4 loads 8 bytes from ((ret(get_nasid) << 0x21)+0x9600000000000000 | 0x2000) +0xd0.
  2 such `lhu` accesses load 2 bytes from [((ret(get_nasid) << 0x21)+0x9600000000000000 | 0x2000)+208]:8 +0x4, including `lhu` at 0x33c8, `lhu` at 0x3454.
  The `lb` at 0x33d8 loads 1 byte from [((ret(get_nasid) << 0x21)+0x9600000000000000 | 0x2000)+208]:8 +0x2b.
  The `lh` at 0x33e8 loads 2 bytes from [((ret(get_nasid) << 0x21)+0x9600000000000000 | 0x2000)+208]:8 +0x80.
  The `ld` at 0x33f8 loads 8 bytes from ([[((ret(get_nasid) << 0x21)+0x9600000000000000 | 0x2000)+208]:8+128]:2 << 0x21) -0x6fffffffcc000000.
  The `ld` at 0x3420 loads 8 bytes from (([[((ret(get_nasid) << 0x21)+0x9600000000000000 | 0x2000)+208]:8+128]:2 << 0x21)+0x9600000000000000 | 0x2000) +0x48.
  The `lw` at 0x3434 loads 4 bytes from ?.
  The `lb` at 0x3464 loads 1 byte from ret(find_lboard) +0x10.
  The `sw` at 0x3468 stores 4 bytes to [((ret(get_nasid) << 0x21)+0x9600000000000000 | 0x2000)+208]:8 +0x28.
  The `jal` at 0x33a8 calls get_nasid with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x340c calls chk_for_pebrick with a0=[[((ret(get_nasid) << 0x21)+0x9600000000000000 | 0x2000)+208]:8+128]:2, a1=?, a2=([[((ret(get_nasid) << 0x21)+0x9600000000000000 | 0x2000)+208]:8+128]:2 << 0x21), a3=0x9600000000000000, a4=([[((ret(get_nasid) << 0x21)+0x9600000000000000 | 0x2000)+208]:8+128]:2 << 0x21)+0x9600000000000000, a5=0xc000.
  The `jal` at 0x344c calls find_lboard with a0=?, a1=0x11, a2=?, a3=?.
  The `jal` at 0x346c calls cmn_err with a0=0x5, a1=sym(.rodata), a2=[[((ret(get_nasid) << 0x21)+0x9600000000000000 | 0x2000)+208]:8+4]:2, a3=0x2, a4=[ret(find_lboard)+16]:1.
  The `bne` branch at 0x33d0 targets 0x33e8, is taken when at(=[[((ret(get_nasid) << 0x21)+0x9600000000000000 | 0x2000)+208]:8+4]:2) < 0x2 (signed), and falls through when at(=[[((ret(get_nasid) << 0x21)+0x9600000000000000 | 0x2000)+208]:8+4]:2) >= 0x2 (signed).
  The `bne` branch at 0x3404 targets 0x341c, is taken when a4(?) != a5(=0xc000), and falls through when a4(?) == a5(=0xc000).
  The `beq` branch at 0x3414 targets 0x344c and is always taken.
  The `beq` branch at 0x3438 targets 0x344c, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0x3474 targets 0x33d8 and is always taken.
  The return at 0x33e0 has v0 = [[((ret(get_nasid) << 0x21)+0x9600000000000000 | 0x2000)+208]:8+43]:1.

- `part_get_clusterid` in `IP35/usr/cpu/sysgen/IP35boot/partition.o` at 0x347c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/partition.o`.
  Range: 0x347c-0x34a4 (40 bytes).
  It occupies 40 bytes.
  The `lbu` at 0x34a0 loads 1 byte from table(sym(.bss)) +0x15.
  The return at 0x349c has v0 = [table(sym(.bss))+21]:1.

- `part_set_clusterid` in `IP35/usr/cpu/sysgen/IP35boot/partition.o` at 0x34a4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/partition.o`.
  Range: 0x34a4-0x34f8 (84 bytes).
  It occupies 84 bytes.
  The `lw` at 0x34cc loads 4 bytes from ?.
  The `sb` at 0x34e4 stores 1 byte to ?.
  The `beq` branch at 0x34dc targets 0x34e8, is taken when at(?) == t1(=0x1), and falls through when at(?) != t1(=0x1).
  The `bne` branch at 0x34e8 targets 0x34b4, is taken when a3(?) != 0, and falls through when a3(?) == 0.
  The return at 0x34f0 has v0 = ?.

- `part_installed` in `IP35/usr/cpu/sysgen/IP35boot/partition.o` at 0x34f8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/partition.o`.
  Range: 0x34f8-0x3500 (8 bytes).
  It occupies 8 bytes.
  The return at 0x34f8 has v0 = 0x1.

- `part_id` in `IP35/usr/cpu/sysgen/IP35boot/partition.o` at 0x3500 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/partition.o`.
  Range: 0x3500-0x3508 (8 bytes).
  It occupies 8 bytes.
  The return at 0x3500 has v0 = [sym(partition_partid)]:1.

- `part_get` in `IP35/usr/cpu/sysgen/IP35boot/partition.o` at 0x3508 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/partition.o`.
  Range: 0x3508-0x3548 (64 bytes).
  It occupies 64 bytes.
  The `bltz` branch at 0x3508 targets 0x3540, is taken when a0 < 0 (signed), and falls through when a0 >= 0 (signed).
  The `beq` branch at 0x351c targets 0x353c, is taken when a0 >= 0x40 (signed), and falls through when a0 < 0x40 (signed).
  The return at 0x3534 has v0 = table(sym(.bss)).
  The return at 0x3540 has v0 = 0x0.

- `part_get_nasid` in `IP35/usr/cpu/sysgen/IP35boot/partition.o` at 0x3548 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/partition.o`.
  Range: 0x3548-0x35fc (180 bytes).
  It occupies 180 bytes.
  The `lh` at 0x3550 loads 2 bytes from a1 (arg1 at entry) +0x0.
  The `lb` at 0x3594 loads 1 byte from table(sym(.bss)) +0x3506.
  The `lw` at 0x35a4 loads 4 bytes from table(sym(.bss)) +0x3504.
  The `sh` at 0x35e0 stores 2 bytes to a1 (arg1 at entry) +0x0.
  The `beq` branch at 0x3548 targets 0x3554, is taken when a1 == 0, and falls through when a1 != 0.
  The `beq` branch at 0x3560 targets 0x35e8, is taken when at(?) >= 0x80 (signed), and falls through when at(?) < 0x80 (signed).
  The `beq` branch at 0x3568 targets 0x35f0 and is always taken.
  The `beq` branch at 0x357c targets 0x35e4, is taken when a4(?) >= 0x80 (signed), and falls through when a4(?) < 0x80 (signed).
  The `bne` branch at 0x359c targets 0x3570, is taken when v1(=[table(sym(.bss))+13574]:1) != a0, and falls through when v1(=[table(sym(.bss))+13574]:1) == a0.
  The `bltz` branch at 0x35b4 targets 0x35d4, is taken when t1(=([table(sym(.bss))+13572] << 0x8)) < 0 (signed), and falls through when t1(=([table(sym(.bss))+13572] << 0x8)) >= 0 (signed).
  The `bltz` branch at 0x35bc targets 0x35d4, is taken when a7(=([table(sym(.bss))+13572] << 0x9)) < 0 (signed), and falls through when a7(=([table(sym(.bss))+13572] << 0x9)) >= 0 (signed).
  The `bltz` branch at 0x35c4 targets 0x35d4, is taken when t0(=([table(sym(.bss))+13572] << 0xa)) < 0 (signed), and falls through when t0(=([table(sym(.bss))+13572] << 0xa)) >= 0 (signed).
  The `bgezl` branch at 0x35cc targets 0x3574, is taken when t1(=([table(sym(.bss))+13572] << 0xb)) >= 0 (signed), and falls through when t1(=([table(sym(.bss))+13572] << 0xb)) < 0 (signed); its branch-likely delay slot `dsra32 a4,a5,0x10` at 0x35d0 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x35d4 targets 0x35e8, is taken when a1 == 0, and falls through when a1 != 0.
  The `beq` branch at 0x35f4 targets 0x3588 and is always taken.
  The return at 0x35dc has v0 = table(sym(.bss))+13568.
  The return at 0x35e8 has v0 = one of 0x0, table(sym(.bss))+13568.

- `part_poison_xppage` in `IP35/usr/cpu/sysgen/IP35boot/partition.o` at 0x35fc (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/partition.o`.
  Range: 0x35fc-0x3730 (308 bytes).
  It occupies 308 bytes.
  The `lw` at 0x361c loads 4 bytes from a0 (arg0 at entry) +0x5c.
  The `ll` at 0x3644 loads 4 bytes from a0 (arg0 at entry) +0x5c.
  The `sc` at 0x364c stores 4 bytes to a0 (arg0 at entry) +0x5c.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x30, including `ld` at 0x3660, `ld` at 0x36d8.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x38, including `ld` at 0x3664, `ld` at 0x36dc.
  The `sw` at 0x3674 stores 4 bytes to a0 (arg0 at entry) +0x5c.
  The `jal` at 0x3614 calls bitlock_acquire_32bit with a0=a0+92, a1=0x1, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x36a0 calls splhi with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x36b4 calls bitlock_set with a0=?, a1=0x8000000, a2=0x400000, a3=?.
  The `jal` at 0x36bc calls splx with a0=ret(splhi), a1=?, a2=?, a3=?.
  The `jal` at 0x3720 calls bte_poison_range with a0=?, a1=([a0+48]:8 << 0x0), a2=?, a3=0x3f80000, a4=0xfffffffffe000000, a5=0x1ffffffff.
  The `beq` branch at 0x362c targets 0x3660, is taken when (v0(=[a0+92]) & 0x8) == 0, and falls through when (v0(=[a0+92]) & 0x8) != 0.
  The `beql` branch at 0x3650 targets 0x3644, is taken when (v0(=[a0+92]) & a0(=-0x2)) == 0, and falls through when (v0(=[a0+92]) & a0(=-0x2)) != 0; its branch-likely delay slot `nop` at 0x3654 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x3694 targets 0x36e0, is taken when a2(=[a0+56]:8) >= a3(?) (unsigned), and falls through when a2(=[a0+56]:8) < a3(?) (unsigned).
  The `bne` branch at 0x36d0 targets 0x36a0, is taken when s1(?) < a4(?) (unsigned), and falls through when s1(?) >= a4(?) (unsigned).
  The `beq` branch at 0x3728 targets 0x3638 and is always taken.
  The return at 0x3658 has v0 = [a0+92].

- `part_poison_page` in `IP35/usr/cpu/sysgen/IP35boot/partition.o` at 0x3730 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/partition.o`.
  Range: 0x3730-0x3790 (96 bytes).
  It occupies 96 bytes.
  The `jal` at 0x3764 calls part_find_page with a0=?, a1=?, a2=0x3f80000, a3=0xfffffffffe000000.
  The `jal` at 0x3770 calls part_poison_xppage with a0=ret(part_find_page), a1=?, a2=?, a3=?.
  The `jal` at 0x3778 calls part_release_page with a0=ret(part_find_page), a1=?, a2=?, a3=?.
  The return at 0x3788 has v0 = ret(part_release_page).

- `part_error_handler` in `IP35/usr/cpu/sysgen/IP35boot/partition.o` at 0x3790 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/partition.o`.
  Range: 0x3790-0x3a4c (700 bytes).
  It occupies 700 bytes.
  4 such `lw` accesses load 4 bytes from ret(part_find_page) +0x5c, including `lw` at 0x37c8, `lw` at 0x3800, `lw` at 0x3828.
  The `lh` at 0x37d8 loads 2 bytes from ret(part_find_page) +0x42.
  The `lh` at 0x37dc loads 2 bytes from abs 0xffffffffffffc428.
  2 such `ll` accesses load 4 bytes from ret(part_find_page) +0x5c, including `ll` at 0x383c, `ll` at 0x39e0.
  2 such `sc` accesses store 4 bytes to ret(part_find_page) +0x5c, including `sc` at 0x3844, `sc` at 0x39e8.
  The `ld` at 0x38ec loads 8 bytes from table(sym(.rodata)) +0x0.
  2 such `ld` accesses load 8 bytes from ret(part_find_page) +0x48, including `ld` at 0x3980, `ld` at 0x39fc.
  2 such `sw` accesses store 4 bytes to ret(part_find_page) +0x5c, including `sw` at 0x3988, `sw` at 0x39a0.
  The `jal` at 0x37b0 calls part_find_page with a0=a1 at entry (arg1), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x37f8 calls splerr with a0=?, a1=0x3, a2=?, a3=?.
  The `jal` at 0x3820 calls bitlock_acquire_32bit with a0=ret(part_find_page)+92, a1=0x1, a2=?, a3=?.
  The `jal` at 0x3850 calls splx with a0=?, a1=?, a2=?, a3=?, a5=[ret(part_find_page)+92], a6=-0x2.
  The `jal` at 0x385c calls part_release_page with a0=ret(part_find_page), a1=?, a2=?, a3=?.
  The `jal` at 0x38c0 calls get_dir_ent with a0=a1 at entry (arg1), a1=sp-128, a2=sp-120, a3=sp-112.
  The `jal` at 0x39a4 calls part_release_page with a0=ret(part_find_page), a1=[ret(part_find_page)+92], a2=?, a3=?.
  The `jal` at 0x39b4 calls part_release_page with a0=ret(part_find_page), a1=0x3, a2=?, a3=?.
  The `jal` at 0x39f4 calls splx with a0=?, a1=([ret(part_find_page)+92] | 0x4), a2=?, a3=?, a7=[ret(part_find_page)+72]:8.
  The `jalr` at 0x3a08 calls (unknown callee) with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=?.
  The `jal` at 0x3a10 calls splerr with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x3a20 calls bitlock_acquire_32bit with a0=ret(part_find_page)+92, a1=0x1, a2=?, a3=?.
  The `jal` at 0x3a3c calls cmn_err with a0=0x0, a1=sym(.rodata), a2=a1 at entry (arg1), a3=?.
  The `beq` branch at 0x37c0 targets 0x3884, is taken when v0(=ret(part_find_page)) == 0, and falls through when v0(=ret(part_find_page)) != 0.
  The `beq` branch at 0x37d0 targets 0x37e8, is taken when (a1(=[ret(part_find_page)+92]) & 0x2) == 0, and falls through when (a1(=[ret(part_find_page)+92]) & 0x2) != 0.
  The `beq` branch at 0x37e0 targets 0x39a4, is taken when v0(=[-0x3bd8]:2) == v1(=[ret(part_find_page)+66]:2), and falls through when v0(=[-0x3bd8]:2) != v1(=[ret(part_find_page)+66]:2).
  The `beq` branch at 0x37e8 targets 0x37f8, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x37f0 targets 0x39b4, is taken when s4(=a2) == a1(=0x3), and falls through when s4(=a2) != a1(=0x3).
  The `beq` branch at 0x3810 targets 0x38a4, is taken when (a2(=[ret(part_find_page)+92]) & 0x10) == 0, and falls through when (a2(=[ret(part_find_page)+92]) & 0x10) != 0.
  The `beq` branch at 0x3830 targets 0x3980, is taken when (a1(=[ret(part_find_page)+92]) & 0x4) == 0, and falls through when (a1(=[ret(part_find_page)+92]) & 0x4) != 0.
  The `beql` branch at 0x3848 targets 0x383c, is taken when (a5(=[ret(part_find_page)+92]) & a6(=-0x2)) == 0, and falls through when (a5(=[ret(part_find_page)+92]) & a6(=-0x2)) != 0; its branch-likely delay slot `nop` at 0x384c runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x3864 targets 0x39c4, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0x3870 targets 0x39d0, is taken when s0(?) == v0(=0x1), and falls through when s0(?) != v0(=0x1).
  The `beq` branch at 0x3878 targets 0x3978, is taken when s0(?) == t0(=0x2), and falls through when s0(?) != t0(=0x2).
  The `beq` branch at 0x38a4 targets 0x38b4 and is always taken.
  The `bne` branch at 0x38b0 targets 0x3970 and is never taken: its condition can never hold for these operands, so execution always falls through.
  The `beq` branch at 0x38e4 targets 0x3a30, is taken when a2(?) >= 0x8 (unsigned), and falls through when a2(?) < 0x8 (unsigned).
  The `beq` branch at 0x3978 targets 0x3888 and is always taken.
  The `bne` branch at 0x398c targets 0x39d8, is taken when a7(=[ret(part_find_page)+72]:8) != 0, and falls through when a7(=[ret(part_find_page)+72]:8) == 0.
  The `beq` branch at 0x399c targets 0x3838 and is always taken.
  The `beq` branch at 0x39ac targets 0x3884 and is always taken.
  The `beq` branch at 0x39bc targets 0x3884 and is always taken.
  The `beq` branch at 0x39c8 targets 0x3888 and is always taken.
  The `beq` branch at 0x39d0 targets 0x3888 and is always taken.
  The `beql` branch at 0x39ec targets 0x39e0, is taken when (t1(=[ret(part_find_page)+92]) & t2(=-0x2)) == 0, and falls through when (t1(=[ret(part_find_page)+92]) & t2(=-0x2)) != 0; its branch-likely delay slot `nop` at 0x39f0 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x3a28 targets 0x3994 and is always taken.
  The `beq` branch at 0x3a44 targets 0x38b0 and is always taken.
  The return at 0x389c has v0 = one of 0x0, 0x1, 0x2, 0x3.
  The instructions from 0x38ac to 0x38ac are not reached by any path from the entry, and their branches are not listed.
  The instructions from 0x38f8 to 0x3974 are not reached by any path from the entry, and their branches are not listed.
  The indirect jump at 0x38f0 uses a jump table whose successors are unresolved.

- `part_register_page` in `IP35/usr/cpu/sysgen/IP35boot/partition.o` at 0x3a4c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/partition.o`.
  Range: 0x3a4c-0x3a80 (52 bytes).
  It occupies 52 bytes.
  The `jal` at 0x3a6c calls part_new_page with a0=0x0, a1=a0 at entry (arg0), a2=a1 at entry (arg1), a3=0x10, a4=a2 at entry (arg2).
  The return at 0x3a78 has v0 = ret(part_new_page).

- `part_unregister_page` in `IP35/usr/cpu/sysgen/IP35boot/partition.o` at 0x3a80 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/partition.o`.
  Range: 0x3a80-0x3ab4 (52 bytes).
  It occupies 52 bytes.
  The `jal` at 0x3a88 calls part_find_page with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x3a94 calls part_release_page with a0=ret(part_find_page), a1=?, a2=?, a3=?.
  The `jal` at 0x3a9c calls part_release_page with a0=ret(part_find_page), a1=?, a2=?, a3=?.
  The return at 0x3aac has v0 = ret(part_release_page).

- `part_call_activate_handlers` in `IP35/usr/cpu/sysgen/IP35boot/partition.o` at 0x3ab4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/partition.o`.
  Range: 0x3ab4-0x3c98 (484 bytes).
  It occupies 484 bytes.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0xc, including `sw` at 0x3af0, `sw` at 0x3c34.
  The `ld` at 0x3af8 loads 8 bytes from a0 (arg0 at entry) +0xc8.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x20, including `lw` at 0x3b20, `lw` at 0x3c28.
  The `ld` at 0x3b24 loads 8 bytes from abs 0xffffffffffffc020.
  3 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0xc8, including `sd` at 0x3b2c, `sd` at 0x3b90, `sd` at 0x3c64.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x10, including `lw` at 0x3b40, `lw` at 0x3c58.
  5 such `ld` accesses load 8 bytes from ?, including `ld` at 0x3b70, `ld` at 0x3be0, `ld` at 0x3be4.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x10, including `sw` at 0x3bd8, `sw` at 0x3bf4.
  The `lb` at 0x3c10 loads 1 byte from a0 (arg0 at entry) +0x14.
  The `jal` at 0x3ad4 calls mutex_lock with a0=sym(.bss), a1=0x19, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x3ae8 calls mutex_spinlock with a0=a0+8, a1=?, a2=?, a3=?.
  The `jal` at 0x3b94 calls mutex_spinunlock with a0=a0+8, a1=ret(mutex_spinlock), a2=?, a3=?.
  The `jal` at 0x3b9c calls mutex_unlock with a0=sym(.bss), a1=?, a2=?, a3=?.
  The `jal` at 0x3bf8 calls mutex_spinunlock with a0=a0+8, a1=ret(mutex_spinlock), a2=?, a3=?.
  The `jal` at 0x3c00 calls mutex_unlock with a0=sym(.bss), a1=?, a2=?, a3=?.
  The `jalr` at 0x3c0c calls (unknown callee) with a0=[a0+20]:1, a1=?, a2=?, a3=?.
  The `jal` at 0x3c18 calls mutex_lock with a0=sym(.bss), a1=0x19, a2=?, a3=?.
  The `jal` at 0x3c20 calls mutex_spinlock with a0=a0+8, a1=?, a2=?, a3=?.
  The `jal` at 0x3c68 calls mutex_spinunlock with a0=a0+8, a1=ret(mutex_spinlock), a2=?, a3=?, a4=[a0+32], a7=0x5.
  The `jal` at 0x3c70 calls mutex_unlock with a0=sym(.bss), a1=?, a2=?, a3=?.
  The `jal` at 0x3c80 calls mutex_spinunlock with a0=a0+8, a1=ret(mutex_spinlock), a2=?, a3=?, a5=0x5.
  The `jal` at 0x3c88 calls mutex_unlock with a0=sym(.bss), a1=?, a2=?, a3=?.
  The `bne` branch at 0x3b18 targets 0x3c80, is taken when at(=[a0+200]:8) != 0, and falls through when at(=[a0+200]:8) == 0.
  The `beq` branch at 0x3b28 targets 0x3b3c, is taken when a4(=[a0+32]) == s7(=0x6), and falls through when a4(=[a0+32]) != s7(=0x6).
  The `beq` branch at 0x3b30 targets 0x3b40, is taken when a4(=[a0+32]) == a0(=0x4), and falls through when a4(=[a0+32]) != a0(=0x4).
  The `bne` branch at 0x3b38 targets 0x3b90, is taken when a4(=[a0+32]) != a5(=0x5), and falls through when a4(=[a0+32]) == a5(=0x5).
  The `beq` branch at 0x3b48 targets 0x3b90, is taken when s1(=[a0+16]) >= s4(=[sym(.sdata)]) (signed), and falls through when s1(=[a0+16]) < s4(=[sym(.sdata)]) (signed).
  The `bltz` branch at 0x3b5c targets 0x3b74, is taken when a5(?) < 0 (signed), and falls through when a5(?) >= 0 (signed).
  The `beq` branch at 0x3b6c targets 0x3b64, is taken when a5(?) >= a4(?) (signed), and falls through when a5(?) < a4(?) (signed).
  The `bne` branch at 0x3b7c targets 0x3be4, is taken when s3(?) < s4(=[sym(.sdata)]) (signed), and falls through when s3(?) >= s4(=[sym(.sdata)]) (signed).
  The `bne` branch at 0x3b88 targets 0x3b54, is taken when a3(?) != 0, and falls through when a3(?) == 0.
  The `beq` branch at 0x3bdc targets 0x3c5c, is taken when s1(?) >= s4(=[sym(.sdata)]) (signed), and falls through when s1(?) < s4(=[sym(.sdata)]) (signed).
  The `beq` branch at 0x3bec targets 0x3bd4, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `beq` branch at 0x3c38 targets 0x3c50, is taken when a4(=[a0+32]) == s7(=0x6), and falls through when a4(=[a0+32]) != s7(=0x6).
  The `beq` branch at 0x3c40 targets 0x3c50, is taken when a4(=[a0+32]) == s8(=0x4), and falls through when a4(=[a0+32]) != s8(=0x4).
  The `bne` branch at 0x3c48 targets 0x3c64, is taken when a4(=[a0+32]) != a7(=0x5), and falls through when a4(=[a0+32]) == a7(=0x5).
  The `bne` branch at 0x3c50 targets 0x3be4, is taken when a0(?) != 0, and falls through when a0(?) == 0.
  The `beq` branch at 0x3c5c targets 0x3b80 and is always taken.
  The `beq` branch at 0x3c78 targets 0x3ba8 and is always taken.
  The `beq` branch at 0x3c90 targets 0x3ba8 and is always taken.
  The return at 0x3bcc has v0 = ret(mutex_unlock).

- `part_activate_thread_setup` in `IP35/usr/cpu/sysgen/IP35boot/partition.o` at 0x3c98 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/partition.o`.
  Range: 0x3c98-0x3cbc (36 bytes).
  It occupies 36 bytes.
  The `jal` at 0x3ca0 calls part_call_activate_handlers with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x3ca8 calls xthread_exit with a0=?, a1=?, a2=?, a3=?.
  The return at 0x3cb4 has v0 = ret(xthread_exit).

- `part_call_deactivate_handlers` in `IP35/usr/cpu/sysgen/IP35boot/partition.o` at 0x3cbc (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/partition.o`.
  Range: 0x3cbc-0x3d70 (180 bytes).
  It occupies 180 bytes.
  The `sw` at 0x3cf0 stores 4 bytes to a0 (arg0 at entry) +0xc.
  The `lw` at 0x3cf8 loads 4 bytes from a0 (arg0 at entry) +0x10.
  The `sw` at 0x3cfc stores 4 bytes to a0 (arg0 at entry) +0x10.
  The `lb` at 0x3d1c loads 1 byte from a0 (arg0 at entry) +0x14.
  3 such `ld` accesses load 8 bytes from ?, including `ld` at 0x3d24, `ld` at 0x3d30, `ld` at 0x3d40.
  The `jal` at 0x3cd8 calls mutex_lock with a0=sym(.bss), a1=0x19, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x3ce8 calls mutex_spinlock with a0=a0+8, a1=?, a2=?, a3=?.
  The `jal` at 0x3d00 calls mutex_spinunlock with a0=a0+8, a1=ret(mutex_spinlock), a2=?, a3=?.
  The `jalr` at 0x3d18 calls (unknown callee) with a0=[a0+20]:1, a1=?, a2=?, a3=?.
  The `jal` at 0x3d50 calls mutex_unlock with a0=sym(.bss), a1=?, a2=?, a3=?.
  The `bgtz` branch at 0x3d08 targets 0x3d30, is taken when s1(=[a0+16]) > 0 (signed), and falls through when s1(=[a0+16]) <= 0 (signed).
  The `beq` branch at 0x3d10 targets 0x3d4c and is always taken.
  The `blez` branch at 0x3d28 targets 0x3d4c, is taken when a1(?) <= 0 (signed), and falls through when a1(?) > 0 (signed).
  The `bne` branch at 0x3d34 targets 0x3d18, is taken when a2(?) != 0, and falls through when a2(?) == 0.
  The `bgtz` branch at 0x3d44 targets 0x3d30, is taken when a2(?) > 0 (signed), and falls through when a2(?) <= 0 (signed).
  The return at 0x3d68 has v0 = ret(mutex_unlock).

- `part_register_handlers` in `IP35/usr/cpu/sysgen/IP35boot/partition.o` at 0x3d70 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/partition.o`.
  Range: 0x3d70-0x3f04 (404 bytes).
  It occupies 404 bytes.
  The `sd` at 0x3d98 stores 8 bytes to ret(kmem_alloc) +0x8.
  The `sd` at 0x3da4 stores 8 bytes to ret(kmem_alloc) +0x10.
  The `sd` at 0x3dac stores 8 bytes to ret(kmem_alloc) +0x0.
  The `ld` at 0x3dd8 loads 8 bytes from [sym(.sdata)+8]:8 +0x0.
  The `ld` at 0x3de8 loads 8 bytes from ?.
  The `sd` at 0x3df4 stores 8 bytes to ?.
  The `sw` at 0x3e64 stores 4 bytes to ret(part_get) +0xc.
  The `lw` at 0x3e68 loads 4 bytes from ret(part_get) +0x20.
  The `lw` at 0x3e84 loads 4 bytes from ret(part_get) +0x10.
  The `lw` at 0x3e9c loads 4 bytes from ret(part_get) +0xc.
  The `jal` at 0x3d90 calls kmem_alloc with a0=0x18, a1=0x0, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x3db0 calls mutex_lock with a0=sym(.bss), a1=0x19, a2=?, a3=?.
  The `jal` at 0x3e04 calls mutex_unlock with a0=sym(.bss), a1=[sym(.sdata)]+1, a2=?, a3=?.
  The `jal` at 0x3e20 calls mutex_spinunlock with a0=ret(part_get)+8, a1=?, a2=?, a3=?.
  The `jal` at 0x3e44 calls part_get with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x3e54 calls mutex_spinlock with a0=ret(part_get)+8, a1=?, a2=?, a3=?.
  The `jal` at 0x3ec8 calls mutex_spinunlock with a0=ret(part_get)+8, a1=ret(mutex_spinlock), a2=?, a3=?, a4=[ret(part_get)+32].
  The `jal` at 0x3eec calls xthread_create with a0=ret(part_get), a1=0x0, a2=0x4000, a3=0x1, a4=[sym(partition_pri)], a5=0x3000, a6=sym(part_activate_thread_setup), a7=ret(part_get).
  The `beq` branch at 0x3dd0 targets 0x3efc, is taken when a1(=[sym(.sdata)+8]:8) == 0, and falls through when a1(=[sym(.sdata)+8]:8) != 0.
  The `beq` branch at 0x3ddc targets 0x3df4, is taken when a0(=[[sym(.sdata)+8]:8]:8) == 0, and falls through when a0(=[[sym(.sdata)+8]:8]:8) != 0.
  The `bne` branch at 0x3dec targets 0x3de4, is taken when a0(?) != 0, and falls through when a0(?) == 0.
  The `beq` branch at 0x3e18 targets 0x3e40 and is always taken.
  The `beq` branch at 0x3e38 targets 0x3ea0, is taken when s1(?) >= 0x40 (signed), and falls through when s1(?) < 0x40 (signed).
  The `beq` branch at 0x3e60 targets 0x3e20, is taken when s0(=ret(part_get)) == 0, and falls through when s0(=ret(part_get)) != 0.
  The `beq` branch at 0x3e6c targets 0x3e84, is taken when a4(=[ret(part_get)+32]) == s5(=0x6), and falls through when a4(=[ret(part_get)+32]) != s5(=0x6).
  The `beq` branch at 0x3e74 targets 0x3e84, is taken when a4(=[ret(part_get)+32]) == s6(=0x4), and falls through when a4(=[ret(part_get)+32]) != s6(=0x4).
  The `bne` branch at 0x3e7c targets 0x3e20, is taken when a4(=[ret(part_get)+32]) != s7(=0x5), and falls through when a4(=[ret(part_get)+32]) == s7(=0x5).
  The `beq` branch at 0x3e88 targets 0x3ec8, is taken when t8(=[ret(part_get)+16]) == s4(=[sym(.sdata)]), and falls through when t8(=[ret(part_get)+16]) != s4(=[sym(.sdata)]).
  The `bne` branch at 0x3e90 targets 0x3e28, is taken when s3(=one of 0x0, 0x1) != 0, and falls through when s3(=one of 0x0, 0x1) == 0.
  The `beq` branch at 0x3e98 targets 0x3e20 and is always taken.
  The `beq` branch at 0x3ef4 targets 0x3e90 and is always taken.
  The `beq` branch at 0x3efc targets 0x3df8 and is always taken.
  The return at 0x3ec0 has v0 = ?.

- `part_operation` in `IP35/usr/cpu/sysgen/IP35boot/partition.o` at 0x3f04 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/partition.o`.
  Range: 0x3f04-0x4174 (624 bytes).
  It occupies 624 bytes.
  The `lw` at 0x3fc4 loads 4 bytes from ?.
  5 such `sd` accesses store 8 bytes to a4 (arg4 at entry) +0x0, including `sd` at 0x3fe8, `sd` at 0x4084, `sd` at 0x40b0.
  The `lh` at 0x4034 loads 2 bytes from ?.
  The `jal` at 0x400c calls copyout with a0=sp-96, a1=?, a2=0x28, a3=?, a7=0x1.
  The `jal` at 0x4050 calls copyout with a0=?, a1=?, a2=0x1c, a3=?.
  The `jal` at 0x40e4 calls part_id with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a7=0x1.
  The `jal` at 0x410c calls cap_able with a0=0x2000000000, a1=0x4, a2=a2 at entry (arg2), a3=a3 at entry (arg3), a6=0x16, a7=0x1.
  The `jal` at 0x4124 calls cap_able with a0=0x2000000000, a1=0x4, a2=a2 at entry (arg2), a3=a3 at entry (arg3), a6=0x16, a7=0x1.
  The `jal` at 0x413c calls part_id with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x4154 calls vsema with a0=sym(.bss), a1=?, a2=?, a3=?.
  The `jal` at 0x4164 calls part_deactivate with a0=?, a1=?, a2=?, a3=?.
  The `beq` branch at 0x3f34 targets 0x40e4, is taken when a0 == a7(=0x1), and falls through when a0 != a7(=0x1).
  The `beq` branch at 0x3f48 targets 0x3fa4, is taken when a0 == at(=0x3), and falls through when a0 != at(=0x3).
  The `beq` branch at 0x3f60 targets 0x4024, is taken when a0 == v1(=0x2), and falls through when a0 != v1(=0x2).
  The `beq` branch at 0x3f6c targets 0x4108, is taken when a0 == a1(=0x4), and falls through when a0 != a1(=0x4).
  The `beq` branch at 0x3f74 targets 0x4124, is taken when a0 == v0(=0x5), and falls through when a0 != v0(=0x5).
  The `beq` branch at 0x3fc8 targets 0x3ff4, is taken when a2(?) == a1(=0x6), and falls through when a2(?) != a1(=0x6).
  The `bne` branch at 0x3fe0 targets 0x3fb0, is taken when s0(?) < 0x40 (signed), and falls through when s0(?) >= 0x40 (signed).
  The `beq` branch at 0x3fec targets 0x3f7c and is always taken.
  The `bltz` branch at 0x3ffc targets 0x40b4, is taken when s1(?) < 0 (signed), and falls through when s1(?) >= 0 (signed).
  The `beq` branch at 0x4014 targets 0x40bc, is taken when v0(=ret(copyout)) == 0, and falls through when v0(=ret(copyout)) != 0.
  The `beq` branch at 0x401c targets 0x3f7c and is always taken.
  The `beq` branch at 0x4038 targets 0x406c, is taken when a2(?) == a1(=-0x1), and falls through when a2(?) != a1(=-0x1).
  The `bltz` branch at 0x4044 targets 0x4068, is taken when s1(?) < 0 (signed), and falls through when s1(?) >= 0 (signed).
  The `beq` branch at 0x4058 targets 0x4090, is taken when v0(=ret(copyout)) == 0, and falls through when v0(=ret(copyout)) != 0.
  The `beq` branch at 0x4060 targets 0x3f7c and is always taken.
  The `bne` branch at 0x407c targets 0x4028, is taken when s0(?) < 0x80 (signed), and falls through when s0(?) >= 0x80 (signed).
  The `beq` branch at 0x4088 targets 0x3f7c and is always taken.
  The `bne` branch at 0x40a4 targets 0x4024, is taken when s0(?) < 0x80 (signed), and falls through when s0(?) >= 0x80 (signed).
  The `beq` branch at 0x40ac targets 0x4088 and is always taken.
  The `beq` branch at 0x40b4 targets 0x3fd0 and is always taken.
  The `bne` branch at 0x40d4 targets 0x3fac, is taken when s0(?) < 0x40 (signed), and falls through when s0(?) >= 0x40 (signed).
  The `beq` branch at 0x40dc targets 0x3fec and is always taken.
  The `beq` branch at 0x4100 targets 0x3f7c and is always taken.
  The `bne` branch at 0x4114 targets 0x413c, is taken when v0(=ret(cap_able)) != 0, and falls through when v0(=ret(cap_able)) == 0.
  The `beq` branch at 0x411c targets 0x3f7c and is always taken.
  The `bne` branch at 0x412c targets 0x4154, is taken when v0(=ret(cap_able)) != 0, and falls through when v0(=ret(cap_able)) == 0.
  The `beq` branch at 0x4134 targets 0x3f7c and is always taken.
  The `bne` branch at 0x4144 targets 0x4164, is taken when v0(=ret(part_id)) != s1(=a1), and falls through when v0(=ret(part_id)) == s1(=a1).
  The `beq` branch at 0x414c targets 0x3f7c and is always taken.
  The `beq` branch at 0x415c targets 0x3f7c and is always taken.
  The `beq` branch at 0x416c targets 0x3f7c and is always taken.
  The return at 0x3f9c has v0 = one of 0x16, 0x0, 0xe, 0x3f0, 0x1.

- `part_page_dump` in `IP35/usr/cpu/sysgen/IP35boot/partition.o` at 0x4174 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/partition.o`.
  Range: 0x4174-0x4280 (268 bytes).
  It occupies 268 bytes.
  The `ld` at 0x419c loads 8 bytes from sym(.bss) +0x8.
  7 such `lw` accesses load 4 bytes from ?, including `lw` at 0x41a8, `lw` at 0x41b0, `lw` at 0x41c8.
  4 such `ld` accesses load 8 bytes from ?, including `ld` at 0x41ac, `ld` at 0x41b8, `ld` at 0x41bc.
  The `lb` at 0x41b4 loads 1 byte from ?.
  The `lh` at 0x41f8 loads 2 bytes from ?.
  The `jalr` at 0x4190 calls (unknown callee) with a0=sym(.rodata), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x41c0 calls (unknown callee) with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jalr` at 0x41e0 calls (unknown callee) with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jalr` at 0x41fc calls (unknown callee) with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jalr` at 0x4218 calls (unknown callee) with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jalr` at 0x4230 calls (unknown callee) with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jalr` at 0x4248 calls (unknown callee) with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jalr` at 0x4254 calls (unknown callee) with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `beq` branch at 0x41a0 targets 0x4268, is taken when at(=[sym(.bss)+8]:8) == 0, and falls through when at(=[sym(.bss)+8]:8) != 0.
  The `beq` branch at 0x41cc targets 0x4250, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x41d4 targets 0x41f0, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0x41f0 targets 0x420c, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0x420c targets 0x4228, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0x4228 targets 0x423c, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0x4240 targets 0x4254, is taken when (a1(?) & 0x10) == 0, and falls through when (a1(?) & 0x10) != 0.
  The `bne` branch at 0x4260 targets 0x41a8, is taken when s0(?) != 0, and falls through when s0(?) == 0.
  The return at 0x4278 has v0 = ret(?).

- `part_dump_partition` in `IP35/usr/cpu/sysgen/IP35boot/partition.o` at 0x4280 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/partition.o`.
  Range: 0x4280-0x46cc (1100 bytes).
  It occupies 1100 bytes.
  4 such `lb` accesses load 1 byte from a1 (arg1 at entry) +0x14, including `lb` at 0x4298, `lb` at 0x42d0, `lb` at 0x434c.
  The `lw` at 0x42c4 loads 4 bytes from a1 (arg1 at entry) +0x20.
  The `lw` at 0x42c8 loads 4 bytes from a1 (arg1 at entry) +0x10.
  The `ld` at 0x42e0 loads 8 bytes from (sym(.data) + ([a1+32] << 0x3)) +0x0.
  The `ld` at 0x42e4 loads 8 bytes from a1 (arg1 at entry) +0xc8.
  2 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x5c, including `lw` at 0x42f8, `lw` at 0x4654.
  The `lw` at 0x4300 loads 4 bytes from a1 (arg1 at entry) +0x58.
  The `ld` at 0x430c loads 8 bytes from a1 (arg1 at entry) +0x28.
  5 such `ld` accesses load 8 bytes from ?, including `ld` at 0x435c, `ld` at 0x43a4, `ld` at 0x43b0.
  The `ld` at 0x43c4 loads 8 bytes from a1 (arg1 at entry) +0x48.
  The `ld` at 0x43c8 loads 8 bytes from a1 (arg1 at entry) +0x40.
  The `lw` at 0x43d4 loads 4 bytes from a1 (arg1 at entry) +0x84.
  The `lw` at 0x43d8 loads 4 bytes from a1 (arg1 at entry) +0x80.
  The `lw` at 0x43dc loads 4 bytes from a1 (arg1 at entry) +0x70.
  2 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x6c, including `lw` at 0x43e0, `lw` at 0x43fc.
  The `lw` at 0x43e4 loads 4 bytes from a1 (arg1 at entry) +0x64.
  2 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x60, including `lw` at 0x43e8, `lw` at 0x4400.
  The `lw` at 0x43f4 loads 4 bytes from a1 (arg1 at entry) +0x74.
  The `lw` at 0x43f8 loads 4 bytes from a1 (arg1 at entry) +0x7c.
  The `lw` at 0x4404 loads 4 bytes from a1 (arg1 at entry) +0x78.
  The `lw` at 0x440c loads 4 bytes from a1 (arg1 at entry) +0x68.
  The `ld` at 0x442c loads 8 bytes from a1 (arg1 at entry) +0xa0.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0x4450, `lw` at 0x4538.
  2 such `ld` accesses load 8 bytes from a1 (arg1 at entry) +0x18, including `ld` at 0x44b8, `ld` at 0x44d0.
  The `lb` at 0x45bc loads 1 byte from ?.
  The `ld` at 0x4668 loads 8 bytes from table(sym(.data)) +0x70.
  The `lbu` at 0x466c loads 1 byte from a1 (arg1 at entry) +0x15.
  The `ld` at 0x468c loads 8 bytes from sym(.bss) +0x4308.
  The `jal` at 0x42a0 calls part_get_var with a0=[a1+20]:1, a1=0x0, a2=sp-96, a3=a3 at entry (arg3).
  The `jalr` at 0x42dc calls (unknown callee) with a0=sym(.rodata), a1=[a1+20]:1, a2=[(sym(.data) + ([a1+32] << 0x3))]:8, a3=?, a4=[a1+16].
  The `jalr` at 0x42f0 calls (unknown callee) with a0=sym(.rodata), a1=[a1+200]:8, a2=?, a3=?.
  The `jalr` at 0x4304 calls (unknown callee) with a0=sym(.rodata), a1=a1+136, a2=[a1+88], a3=[a1+92].
  The `jalr` at 0x4310 calls (unknown callee) with a0=sym(.rodata), a1=[a1+40]:8, a2=?, a3=?.
  The `jalr` at 0x4328 calls (unknown callee) with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jal` at 0x4350 calls part_get_var with a0=[a1+20]:1, a1=?, a2=sp-96, a3=?.
  The `jalr` at 0x436c calls (unknown callee) with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jalr` at 0x437c calls (unknown callee) with a0=sym(.rodata), a1=?, a2=sp-96, a3=?.
  The `jalr` at 0x43b4 calls (unknown callee) with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jalr` at 0x43cc calls (unknown callee) with a0=sym(.rodata), a1=[a1+64]:8, a2=[a1+72]:8, a3=table(sym(.bss)).
  The `jalr` at 0x43ec calls (unknown callee) with a0=sym(.rodata), a1=[a1+96], a2=[a1+100], a3=[a1+108], a4=[a1+112], a5=[a1+128], a6=[a1+132].
  The `jalr` at 0x4410 calls (unknown callee) with a0=sym(.rodata), a1=[a1+104], a2=?, a3=[a1+120], a4=[a1+124], a5=[a1+116], a6=[a1+108].
  The `jalr` at 0x4424 calls (unknown callee) with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jalr` at 0x4464 calls (unknown callee) with a0=sym(.rodata), a1=?, a2=one of 0x20, 0x2a, a3=sym(.rodata).
  The `jalr` at 0x44b0 calls (unknown callee) with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jalr` at 0x44bc calls (unknown callee) with a0=sym(.rodata), a1=[a1+24]:8, a2=?, a3=?.
  The `jalr` at 0x44f8 calls (unknown callee) with a0=sym(.rodata), a1=?, a2=?, a3=[a1+24]:8.
  The `jalr` at 0x4510 calls (unknown callee) with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jalr` at 0x4580 calls (unknown callee) with a0=sym(.rodata), a1=?, a2=one of 0x41, 0x5f, a3=one of 0x42, 0x5f, a4=one of 0x43, 0x5f, a5=one of 0x44, 0x5f.
  The `jalr` at 0x460c calls (unknown callee) with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jalr` at 0x4648 calls (unknown callee) with a0=sym(.rodata), a1=[a1+200]:8, a2=?, a3=?.
  The `jalr` at 0x4670 calls (unknown callee) with a0=sym(.rodata), a1=[a1+21]:1, a2=?, a3=-0x1.
  The `beq` branch at 0x42b0 targets 0x4628, is taken when v0(=ret(part_get_var)) == 0, and falls through when v0(=ret(part_get_var)) != 0.
  The `beq` branch at 0x42e8 targets 0x4648, is taken when a1(=[a1+200]:8) == 0, and falls through when a1(=[a1+200]:8) != 0.
  The `beq` branch at 0x431c targets 0x433c and is always taken.
  The `beq` branch at 0x4338 targets 0x437c, is taken when s2(?) >= 0x5 (signed), and falls through when s2(?) < 0x5 (signed).
  The `bne` branch at 0x4358 targets 0x4324, is taken when v0(=ret(part_get_var)) != 0, and falls through when v0(=ret(part_get_var)) == 0.
  The `beq` branch at 0x4374 targets 0x4334 and is always taken.
  The `beq` branch at 0x4388 targets 0x4680 and is always taken.
  The `beq` branch at 0x439c targets 0x43c4, is taken when s2(?) >= 0x40 (signed), and falls through when s2(?) < 0x40 (signed).
  The `bne` branch at 0x43a8 targets 0x4390, is taken when t9(?) != s1(=a1), and falls through when t9(?) == s1(=a1).
  The `beq` branch at 0x43bc targets 0x4394 and is always taken.
  The `beq` branch at 0x443c targets 0x44ac, is taken when s6(=a1+160) == s2(=[a1+160]:8), and falls through when s6(=a1+160) != s2(=[a1+160]:8).
  The `beq` branch at 0x4444 targets 0x4690 and is always taken.
  The `beq` branch at 0x448c targets 0x44ac, is taken when s6(=a1+160) == s2(?), and falls through when s6(=a1+160) != s2(?).
  The `bne` branch at 0x449c targets 0x444c, is taken when t0(?) != 0, and falls through when t0(?) == 0.
  The `beq` branch at 0x44a4 targets 0x4450 and is always taken.
  The `beq` branch at 0x44cc targets 0x44dc and is always taken.
  The `beq` branch at 0x44d4 targets 0x4510, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0x44e8 targets 0x44d4, is taken when (a3(=[a1+24]:8) & a2(?)) == 0, and falls through when (a3(=[a1+24]:8) & a2(?)) != 0.
  The `bne` branch at 0x4508 targets 0x44cc, is taken when s2(?) < 0x40 (signed), and falls through when s2(?) >= 0x40 (signed).
  The `beq` branch at 0x4528 targets 0x46b4 and is always taken.
  The `beq` branch at 0x45ac targets 0x45e4, is taken when s2(?) >= 0x80 (signed), and falls through when s2(?) < 0x80 (signed).
  The `bne` branch at 0x45c4 targets 0x4590, is taken when t8(?) != t9(=[a1+20]:1), and falls through when t8(?) == t9(=[a1+20]:1).
  The `bne` branch at 0x45cc targets 0x4534 and is always taken.
  The `bne` branch at 0x45e8 targets 0x466c, is taken when t8(=[sym(cell_enabled)]) != 0, and falls through when t8(=[sym(cell_enabled)]) == 0.
  The `bne` branch at 0x4638 targets 0x4658, is taken when a1(?) < 0x3 (unsigned), and falls through when a1(?) >= 0x3 (unsigned).
  The `beq` branch at 0x4640 targets 0x42c4 and is always taken.
  The `beq` branch at 0x4650 targets 0x42fc and is always taken.
  The `beq` branch at 0x4664 targets 0x42c4 and is always taken.
  The `beq` branch at 0x4678 targets 0x45f0 and is always taken.
  The `beq` branch at 0x4688 targets 0x43a8 and is always taken.
  The `beq` branch at 0x46ac targets 0x4498 and is always taken.
  The `beq` branch at 0x46c4 targets 0x45b8 and is always taken.
  The return at 0x4620 has v0 = ret(?).
  The instructions from 0x4530 to 0x4530 are not reached by any path from the entry, and their branches are not listed.
  The instructions from 0x45d4 to 0x45e0 are not reached by any path from the entry, and their branches are not listed.

- `part_dump` in `IP35/usr/cpu/sysgen/IP35boot/partition.o` at 0x46cc (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/partition.o`.
  Range: 0x46cc-0x4920 (596 bytes).
  It occupies 596 bytes.
  5 such `ld` accesses load 8 bytes from ?, including `ld` at 0x4728, `ld` at 0x4734, `ld` at 0x4740.
  The `lw` at 0x4770 loads 4 bytes from ?.
  2 such `lb` accesses load 1 byte from ?, including `lb` at 0x47f0, `lb` at 0x486c.
  2 such `lh` accesses load 2 bytes from ?, including `lh` at 0x47fc, `lh` at 0x4800.
  The `lb` at 0x490c loads 1 byte from sym(.bss) +0x3506.
  The `ld` at 0x491c loads 8 bytes from sym(.bss) +0x4308.
  The `jalr` at 0x4704 calls (unknown callee) with a0=sym(.rodata), a1=[sym(partition_partid)]:1, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x4710 calls (unknown callee) with a0=sym(.rodata), a1=[sym(.sdata)], a2=?, a3=?.
  The `jalr` at 0x4738 calls (unknown callee) with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jal` at 0x477c calls part_dump_partition with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jalr` at 0x47b0 calls (unknown callee) with a0=sym(.rodata), a1=table(sym(.bss)), a2=?, a3=?.
  The `jalr` at 0x4804 calls (unknown callee) with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jalr` at 0x482c calls (unknown callee) with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jalr` at 0x483c calls (unknown callee) with a0=sym(.rodata), a1=?, a2=?, a3=?, a5=table(sym(.bss)).
  The `jalr` at 0x487c calls (unknown callee) with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jalr` at 0x48a4 calls (unknown callee) with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jal` at 0x48b4 calls part_page_dump with a0=a0 at entry (arg0), a1=?, a2=?, a3=?, a5=table(sym(.bss)).
  The `jalr` at 0x48e8 calls (unknown callee) with a0=sym(.rodata), a1=[sym(partition_partid)]:1, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0x46f8 targets 0x48e4, is taken when a1(=[sym(partition_partid)]:1) == s5(=-0x1), and falls through when a1(=[sym(partition_partid)]:1) != s5(=-0x1).
  The `beq` branch at 0x4720 targets 0x474c, is taken when at(=[sym(.sdata)+8]:8) == 0, and falls through when at(=[sym(.sdata)+8]:8) != 0.
  The `bne` branch at 0x4744 targets 0x4728, is taken when s1(?) != 0, and falls through when s1(?) == 0.
  The `beq` branch at 0x4774 targets 0x4784, is taken when a2(?) == s4(=0x1), and falls through when a2(?) != s4(=0x1).
  The `bne` branch at 0x47a8 targets 0x4770, is taken when s1(?) < 0x40 (signed), and falls through when s1(?) >= 0x40 (signed).
  The `beq` branch at 0x47c0 targets 0x48f8 and is always taken.
  The `beq` branch at 0x47e8 targets 0x483c, is taken when s1(?) >= 0x80 (signed), and falls through when s1(?) < 0x80 (signed).
  The `beq` branch at 0x47f4 targets 0x47cc, is taken when a2(?) == s5(=-0x1), and falls through when a2(?) != s5(=-0x1).
  The `bne` branch at 0x4824 targets 0x47c8, is taken when s6(=0x3) != a6(?), and falls through when s6(=0x3) == a6(?).
  The `beq` branch at 0x4834 targets 0x47cc and is always taken.
  The `beq` branch at 0x4848 targets 0x4910 and is always taken.
  The `beq` branch at 0x4860 targets 0x48b4, is taken when s1(?) >= 0x40 (signed), and falls through when s1(?) < 0x40 (signed).
  The `beq` branch at 0x4870 targets 0x4854, is taken when a2(?) == s5(=-0x1), and falls through when a2(?) != s5(=-0x1).
  The `bne` branch at 0x489c targets 0x4850, is taken when s6(=0x3) != a6(?), and falls through when s6(=0x3) == a6(?).
  The `beq` branch at 0x48ac targets 0x4854 and is always taken.
  The `beq` branch at 0x48f0 targets 0x48c0 and is always taken.
  The `beq` branch at 0x4908 targets 0x47f4 and is always taken.
  The `beq` branch at 0x4918 targets 0x486c and is always taken.
  The return at 0x48dc has v0 = one of ret(part_page_dump), ret(?).

- `part_export_page` in `IP35/usr/cpu/sysgen/IP35boot/partition.o` at 0x4920 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/partition.o`.
  Range: 0x4920-0x4954 (52 bytes).
  It occupies 52 bytes.
  The `ld` at 0x4944 loads 8 bytes from table(0x9200000001fc0000) +0x0.
  The `jal` at 0x4940 calls part_export_page_perms with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=0xffff.
  The return at 0x494c has v0 = ret(part_export_page_perms).

- `part_export_page_perms` in `IP35/usr/cpu/sysgen/IP35boot/partition.o` at 0x4954 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/partition.o`.
  Range: 0x4954-0x4bac (600 bytes).
  It occupies 600 bytes.
  3 such `ld` accesses load 8 bytes from table(0x9200000001fc0000) +0x0, including `ld` at 0x4994, `ld` at 0x4a8c, `ld` at 0x4ae0.
  The `ld` at 0x4a14 loads 8 bytes from ret(part_get) +0x18.
  4 such `sd` accesses store 8 bytes to ?, including `sd` at 0x4a5c, `sd` at 0x4a64, `sd` at 0x4a70.
  The `ld` at 0x4aac loads 8 bytes from ?.
  The `jal` at 0x49b4 calls part_get with a0=a2 at entry (arg2), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0x49f4 targets 0x4b9c and is always taken.
  The `beq` branch at 0x4a08 targets 0x4b7c, is taken when s2(?) >= s7(=one of 0x10, 0x40) (signed), and falls through when s2(?) < s7(=one of 0x10, 0x40) (signed).
  The `beq` branch at 0x4a20 targets 0x49fc, is taken when (at(=[ret(part_get)+24]:8) & v1(?)) == 0, and falls through when (at(=[ret(part_get)+24]:8) & v1(?)) != 0.
  The `beq` branch at 0x4a28 targets 0x49fc, is taken when s6(?) == 0, and falls through when s6(?) != 0.
  The `beq` branch at 0x4a38 targets 0x4b84 and is always taken.
  The `beq` branch at 0x4a44 targets 0x4b10, is taken when a7(?) == 0, and falls through when a7(?) != 0.
  The `beq` branch at 0x4a7c targets 0x49fc, is taken when at(?) == 0, and falls through when at(?) != 0.
  The `beq` branch at 0x4ab4 targets 0x4b1c, is taken when 0 >= at(?) (unsigned), and falls through when 0 < at(?) (unsigned).
  The `beq` branch at 0x4abc targets 0x4acc, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0x4ad0 targets 0x4ae0, is taken when t1(=one of 0x0, 0x1) == 0, and falls through when t1(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x4ad8 targets 0x4b3c, is taken when s0(=a3) == v1(?), and falls through when s0(=a3) != v1(?).
  The `beq` branch at 0x4af8 targets 0x4b2c, is taken when 0 >= a0(?) (unsigned), and falls through when 0 < a0(?) (unsigned).
  The `beq` branch at 0x4b00 targets 0x4a40, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `bne` branch at 0x4b08 targets 0x4a4c, is taken when a7(?) != 0, and falls through when a7(?) == 0.
  The `beq` branch at 0x4b14 targets 0x4a54 and is always taken.
  The `beq` branch at 0x4b1c targets 0x4ad0, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0x4b24 targets 0x4ad0 and is always taken.
  The `beq` branch at 0x4b2c targets 0x4b70, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0x4b34 targets 0x4a54 and is always taken.
  The `beq` branch at 0x4b74 targets 0x4a58 and is always taken.
  The `beq` branch at 0x4b7c targets 0x4b40 and is always taken.
  The `beq` branch at 0x4b94 targets 0x4a88 and is always taken.
  The `beq` branch at 0x4ba4 targets 0x4a14 and is always taken.
  The return at 0x4b68 has v0 = one of 0x0, 0x1.

- `part_unexport_page` in `IP35/usr/cpu/sysgen/IP35boot/partition.o` at 0x4bac (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/partition.o`.
  Range: 0x4bac-0x4ca0 (244 bytes).
  It occupies 244 bytes.
  The `jal` at 0x4c00 calls is_POISONED_dir_state with a0=?, a1=?, a2=?, a3=0x0.
  The `jal` at 0x4c24 calls part_unexport_page_nocheck with a0=?, a1=?, a2=a2 at entry (arg2), a3=one of 0x0, 0x1.
  The `jal` at 0x4c90 calls assfail with a0=sym(.rodata), a1=sym(.rodata), a2=0xe06, a3=a3 at entry (arg3).
  The `bne` branch at 0x4be0 targets 0x4c84, is taken when (a0 & 0x3fff) != 0, and falls through when (a0 & 0x3fff) == 0.
  The `beq` branch at 0x4be8 targets 0x4c78, is taken when s6(=a1) == 0, and falls through when s6(=a1) != 0.
  The `beq` branch at 0x4bf8 targets 0x4c3c and is always taken.
  The `beq` branch at 0x4c34 targets 0x4c4c, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `bne` branch at 0x4c3c targets 0x4c00, is taken when s4(=a3) != 0, and falls through when s4(=a3) == 0.
  The `beq` branch at 0x4c44 targets 0x4c14 and is always taken.
  The `beq` branch at 0x4c7c targets 0x4c4c and is always taken.
  The `beq` branch at 0x4c98 targets 0x4be8 and is always taken.
  The return at 0x4c70 has v0 = one of ?, 0x0.

- `part_unexport_page_nocheck` in `IP35/usr/cpu/sysgen/IP35boot/partition.o` at 0x4ca0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/partition.o`.
  Range: 0x4ca0-0x4fa4 (772 bytes).
  It occupies 772 bytes.
  3 such `ld` accesses load 8 bytes from table(0x9200000001fc0000) +0x0, including `ld` at 0x4d64, `ld` at 0x4e30, `ld` at 0x4e80.
  The `ld` at 0x4da0 loads 8 bytes from ret(part_get) +0x18.
  4 such `sd` accesses store 8 bytes to ?, including `sd` at 0x4e04, `sd` at 0x4e0c, `sd` at 0x4e18.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0x4e60, `ld` at 0x4eac.
  3 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x4f44, `lbu` at 0x4f54, `lbu` at 0x4f68.
  The `jal` at 0x4cd4 calls part_get with a0=a2 at entry (arg2), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0x4d7c targets 0x4f94 and is always taken.
  The `beq` branch at 0x4d94 targets 0x4edc, is taken when s2(?) >= s4(=one of 0x10, 0x40) (signed), and falls through when s2(?) < s4(=one of 0x10, 0x40) (signed).
  The `beq` branch at 0x4db4 targets 0x4e6c, is taken when (at(=[ret(part_get)+24]:8) & a4(?)) == 0, and falls through when (at(=[ret(part_get)+24]:8) & a4(?)) != 0.
  The `beq` branch at 0x4dbc targets 0x4d88, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0x4dec targets 0x4f88 and is always taken.
  The `bne` branch at 0x4e24 targets 0x4d84, is taken when ra(=(a0 + a1)-1) < a4(?) (unsigned), and falls through when ra(=(a0 + a1)-1) >= a4(?) (unsigned).
  The `bne` branch at 0x4e5c targets 0x4df4, is taken when 0 < a1(?) (unsigned), and falls through when 0 >= a1(?) (unsigned).
  The `beq` branch at 0x4e64 targets 0x4dfc and is always taken.
  The `bne` branch at 0x4e6c targets 0x4d88, is taken when a2(?) != 0, and falls through when a2(?) == 0.
  The `bne` branch at 0x4e78 targets 0x4d88, is taken when (a5(=[sym(region_mask)]:8) & a4(?)) != 0, and falls through when (a5(=[sym(region_mask)]:8) & a4(?)) == 0.
  The `beq` branch at 0x4ea8 targets 0x4f78, is taken when 0 >= a6(?) (unsigned), and falls through when 0 < a6(?) (unsigned).
  The `beq` branch at 0x4eb0 targets 0x4ec0, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `beq` branch at 0x4ed4 targets 0x4d88 and is always taken.
  The `beq` branch at 0x4f0c targets 0x4f6c, is taken when a0(=a3) == 0, and falls through when a0(=a3) != 0.
  The `beq` branch at 0x4f2c targets 0x4f6c, is taken when a1(=(a0 | 0xa000000000000000)) >= a3(=((a0 | 0xa000000000000000) + a1)) (unsigned), and falls through when a1(=(a0 | 0xa000000000000000)) < a3(=((a0 | 0xa000000000000000) + a1)) (unsigned).
  The `bne` branch at 0x4f34 targets 0x4f70, is taken when a4(?) != 0, and falls through when a4(?) == 0.
  The `bne` branch at 0x4f48 targets 0x4f6c, is taken when a3(=((a0 | 0xa000000000000000) + a1)-1) < a1(?) (unsigned), and falls through when a3(=((a0 | 0xa000000000000000) + a1)-1) >= a1(?) (unsigned).
  The `bne` branch at 0x4f58 targets 0x4f6c, is taken when a3(=((a0 | 0xa000000000000000) + a1)-1) < a1(?) (unsigned), and falls through when a3(=((a0 | 0xa000000000000000) + a1)-1) >= a1(?) (unsigned).
  The `beq` branch at 0x4f64 targets 0x4f3c, is taken when a3(=((a0 | 0xa000000000000000) + a1)-1) >= a1(?) (unsigned), and falls through when a3(=((a0 | 0xa000000000000000) + a1)-1) < a1(?) (unsigned).
  The `beq` branch at 0x4f78 targets 0x4ecc, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `beq` branch at 0x4f80 targets 0x4ec8 and is always taken.
  The `beq` branch at 0x4f8c targets 0x4e30 and is always taken.
  The `beq` branch at 0x4f9c targets 0x4da0 and is always taken.
  The return at 0x4f70 has v0 = ?.

- `part_add_regions` in `IP35/usr/cpu/sysgen/IP35boot/partition.o` at 0x4fa4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/partition.o`.
  Range: 0x4fa4-0x5078 (212 bytes).
  It occupies 212 bytes.
  The `lh` at 0x4ffc loads 2 bytes from ?.
  The `ld` at 0x5004 loads 8 bytes from ret(part_get) +0x18.
  The `ld` at 0x500c loads 8 bytes from ?.
  2 such `sd` accesses store 8 bytes to ?, including `sd` at 0x503c, `sd` at 0x5040.
  The `jal` at 0x4fac calls part_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x4fb8 calls mutex_spinlock with a0=sym(.sbss)+16, a1=?, a2=?, a3=?.
  The `jal` at 0x5064 calls mutex_spinunlock with a0=sym(.sbss)+16, a1=ret(mutex_spinlock), a2=?, a3=?, a4=[sym(maxnodes)].
  The `blez` branch at 0x4fcc targets 0x5060, is taken when a4(=[sym(maxnodes)]) <= 0 (signed), and falls through when a4(=[sym(maxnodes)]) > 0 (signed).
  The `beq` branch at 0x5014 targets 0x5048, is taken when a5(?) == t1(?), and falls through when a5(?) != t1(?).
  The `bne` branch at 0x5038 targets 0x5020, is taken when a4(?) < 0x2 (signed), and falls through when a4(?) >= 0x2 (signed).
  The `bne` branch at 0x5058 targets 0x4ff8, is taken when a6(?) < a4(=[sym(maxnodes)]) (signed), and falls through when a6(?) >= a4(=[sym(maxnodes)]) (signed).
  The return at 0x5070 has v0 = ret(mutex_spinunlock).

- `part_rm_regions` in `IP35/usr/cpu/sysgen/IP35boot/partition.o` at 0x5078 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/partition.o`.
  Range: 0x5078-0x5164 (236 bytes).
  It occupies 236 bytes.
  The `lh` at 0x50cc loads 2 bytes from ?.
  The `ld` at 0x50d8 loads 8 bytes from ret(part_get) +0x18.
  The `ld` at 0x50e8 loads 8 bytes from ?.
  2 such `sd` accesses store 8 bytes to ?, including `sd` at 0x5118, `sd` at 0x511c.
  The `jal` at 0x5088 calls part_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=[sym(partition_partid)]:1, a3=a3 at entry (arg3).
  The `jal` at 0x5094 calls mutex_spinlock with a0=sym(.sbss)+16, a1=?, a2=?, a3=?.
  The `jal` at 0x5134 calls mutex_spinunlock with a0=sym(.sbss)+16, a1=ret(mutex_spinlock), a2=?, a3=?.
  The `jal` at 0x5154 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=[sym(partition_partid)]:1, a3=a3 at entry (arg3).
  The `beq` branch at 0x5080 targets 0x514c, is taken when a0 == a2(=[sym(partition_partid)]:1), and falls through when a0 != a2(=[sym(partition_partid)]:1).
  The `blez` branch at 0x50a8 targets 0x5130, is taken when at(=[sym(maxnodes)]) <= 0 (signed), and falls through when at(=[sym(maxnodes)]) > 0 (signed).
  The `bne` branch at 0x5114 targets 0x50fc, is taken when a0(?) < 0x2 (signed), and falls through when a0(?) >= 0x2 (signed).
  The `bne` branch at 0x5128 targets 0x50c8, is taken when t0(?) < v0(=[sym(maxnodes)]) (signed), and falls through when t0(?) >= v0(=[sym(maxnodes)]) (signed).
  The `beq` branch at 0x515c targets 0x5140 and is always taken.
  The return at 0x5144 has v0 = one of -0x1, 0x0.

- `part_get_var` in `IP35/usr/cpu/sysgen/IP35boot/partition.o` at 0x5164 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/partition.o`.
  Range: 0x5164-0x51d0 (108 bytes).
  It occupies 108 bytes.
  The `ld` at 0x5180 loads 8 bytes from ret(part_get) +0x28.
  The `jal` at 0x5170 calls part_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x51b4 calls _badaddr_val with a0=?, a1=0x8, a2=a2 at entry (arg2), a3=?, a4=-0x1, a5=[ret(part_get)+40]:8.
  The `beq` branch at 0x5178 targets 0x51c0, is taken when v0(=ret(part_get)) == 0, and falls through when v0(=ret(part_get)) != 0.
  The `beq` branch at 0x5184 targets 0x51c0, is taken when a5(=[ret(part_get)+40]:8) == 0, and falls through when a5(=[ret(part_get)+40]:8) != 0.
  The return at 0x51c8 has v0 = one of -0x1, ret(_badaddr_val).

- `part_set_var` in `IP35/usr/cpu/sysgen/IP35boot/partition.o` at 0x51d0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/partition.o`.
  Range: 0x51d0-0x51e4 (20 bytes).
  It occupies 20 bytes.
  The `sd` at 0x51e0 stores 8 bytes to ([sym(.sdata)+32]:8 + (a0 << 0x3)) +0x10.
  The return at 0x51dc has v0 = (a0 << 0x3).

- `part_heartbeat` in `IP35/usr/cpu/sysgen/IP35boot/partition.o` at 0x51e4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/partition.o`.
  Range: 0x51e4-0x5690 (1196 bytes).
  It occupies 1196 bytes.
  The `ld` at 0x523c loads 8 bytes from [sym(.sdata)+32]:8 +0x18.
  The `sd` at 0x5254 stores 8 bytes to [sym(.sdata)+32]:8 +0x18.
  11 such `lw` accesses load 4 bytes from ?, including `lw` at 0x52d4, `lw` at 0x53b0, `lw` at 0x5420.
  2 such `sw` accesses store 4 bytes to ?, including `sw` at 0x52dc, `sw` at 0x5550.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0x52f8, `ld` at 0x5328.
  2 such `sd` accesses store 8 bytes to ?, including `sd` at 0x530c, `sd` at 0x5450.
  4 such `lb` accesses load 1 byte from ?, including `lb` at 0x531c, `lb` at 0x5354, `lb` at 0x5398.
  2 such `ld` accesses load 8 bytes from [sym(.sdata)+32]:8 +0x28, including `ld` at 0x5370, `ld` at 0x54cc.
  The `sd` at 0x540c stores 8 bytes to [sym(.sdata)+32]:8 +0x10.
  The `lh` at 0x5498 loads 2 bytes from ret(part_get_nasid) +0x0.
  The `sd` at 0x54ac stores 8 bytes to (([ret(part_get_nasid)]:2 << 0x21) + one of 0x92000000018000c8, 0x92000000018000d0, 0x9200000001a000c8, 0x9200000001a000d0) +0x0.
  The `lw` at 0x54f8 loads 4 bytes from ret(part_get_nasid) +0x4.
  The `jal` at 0x5264 calls mutex_spinunlock with a0=?, a1=ret(mutex_spinlock), a2=?, a3=?.
  The `jal` at 0x52cc calls mutex_spinlock with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x5318 calls part_get_var with a0=?, a1=0x1, a2=sp-160, a3=?.
  The `jal` at 0x5350 calls part_get_var with a0=?, a1=0x3, a2=sp-144, a3=?.
  The `jal` at 0x5394 calls part_get_var with a0=?, a1=0x0, a2=sp-152, a3=?.
  The `jal` at 0x5408 calls timeout with a0=sym(part_heartbeat), a1=0x0, a2=[sym(.sdata)+24], a3=[sym(.sdata)+32]:8, a6=0x1.
  The `jal` at 0x541c calls mutex_spinunlock with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x5458 calls mutex_spinunlock with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x54f0 calls part_get_nasid with a0=?, a1=0x0, a2=?, a3=?.
  The `jal` at 0x554c calls sv_broadcast with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x5568 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x5574 calls mutex_spinunlock with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x557c calls part_deactivate with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x5590 calls mutex_spinunlock with a0=?, a1=ret(mutex_spinlock), a2=?, a3=?.
  The `jal` at 0x55a4 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x55ac calls part_deactivate with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x55c8 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x55d4 calls mutex_spinunlock with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x55dc calls part_deactivate with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x55f8 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x5604 calls mutex_spinunlock with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x560c calls part_deactivate with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x562c calls cmn_err with a0=0x6, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x5638 calls mutex_spinunlock with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x5640 calls part_deactivate with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x565c calls cmn_err with a0=0x6, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x5668 calls mutex_spinunlock with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x5670 calls part_deactivate with a0=?, a1=?, a2=?, a3=?.
  The `beq` branch at 0x5250 targets 0x53d8, is taken when v0(=[sym(.sdata)+16]) == 0, and falls through when v0(=[sym(.sdata)+16]) != 0.
  The `beq` branch at 0x525c targets 0x5684 and is always taken.
  The `bne` branch at 0x52a0 targets 0x53d0, is taken when v0(=[sym(.sdata)+16]) < s0(?) (unsigned), and falls through when v0(=[sym(.sdata)+16]) >= s0(?) (unsigned).
  The `beq` branch at 0x52a8 targets 0x5290, is taken when t8(=[sym(partition_partid)]:1) == s0(?), and falls through when t8(=[sym(partition_partid)]:1) != s0(?).
  The `beq` branch at 0x52d8 targets 0x52f8, is taken when a2(?) == s3(=0x5), and falls through when a2(?) != s3(=0x5).
  The `beq` branch at 0x52e0 targets 0x5310, is taken when a2(?) == s6(=0x4), and falls through when a2(?) != s6(=0x4).
  The `bne` branch at 0x52e8 targets 0x5264, is taken when a2(?) != s7(=0x6), and falls through when a2(?) == s7(=0x6).
  The `beq` branch at 0x52f0 targets 0x5314 and is always taken.
  The `bne` branch at 0x5308 targets 0x558c, is taken when t9(=[sym(.sdata)+28]) < t8(?) (unsigned), and falls through when t9(=[sym(.sdata)+28]) >= t8(?) (unsigned).
  The `bne` branch at 0x5320 targets 0x555c, is taken when v0(=ret(part_get_var)) != 0, and falls through when v0(=ret(part_get_var)) == 0.
  The `beq` branch at 0x532c targets 0x5390, is taken when ra(?) == at(?), and falls through when ra(?) != at(?).
  The `bne` branch at 0x5334 targets 0x526c, is taken when s4(?) != 0, and falls through when s4(?) == 0.
  The `bne` branch at 0x533c targets 0x526c, is taken when s8(?) != 0, and falls through when s8(?) == 0.
  The `bne` branch at 0x5344 targets 0x526c, is taken when v0(?) != 0, and falls through when v0(?) == 0.
  The `bne` branch at 0x5358 targets 0x5620, is taken when v0(=ret(part_get_var)) != 0, and falls through when v0(=ret(part_get_var)) == 0.
  The `beq` branch at 0x5360 targets 0x5430, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `bne` branch at 0x5368 targets 0x526c, is taken when v1(?) != 0, and falls through when v1(?) == 0.
  The `beq` branch at 0x5378 targets 0x5444, is taken when a0(=[[sym(.sdata)+32]:8+40]:8) == a1(?), and falls through when a0(=[[sym(.sdata)+32]:8+40]:8) != a1(?).
  The `beq` branch at 0x5380 targets 0x5444, is taken when v0(=[sym(.sdata)+16]) == 0, and falls through when v0(=[sym(.sdata)+16]) != 0.
  The `beq` branch at 0x5388 targets 0x54c0 and is always taken.
  The `bne` branch at 0x539c targets 0x55bc, is taken when v0(=ret(part_get_var)) != 0, and falls through when v0(=ret(part_get_var)) == 0.
  The `beq` branch at 0x53a8 targets 0x541c, is taken when a1(=0x2) == a2(?), and falls through when a1(=0x2) != a2(?).
  The `bne` branch at 0x53b4 targets 0x55f0, is taken when a3(?) != s3(=0x5), and falls through when a3(?) == s3(=0x5).
  The `beq` branch at 0x53c8 targets 0x5334 and is always taken.
  The `beq` branch at 0x5428 targets 0x53c4 and is always taken.
  The `bne` branch at 0x5434 targets 0x5650, is taken when a6(?) != s3(=0x5), and falls through when a6(?) == s3(=0x5).
  The `beq` branch at 0x543c targets 0x5364 and is always taken.
  The `beq` branch at 0x544c targets 0x5548, is taken when t1(?) == s3(=0x5), and falls through when t1(?) != s3(=0x5).
  The `beq` branch at 0x5460 targets 0x5270 and is always taken.
  The `bltz` branch at 0x5480 targets 0x5528, is taken when t3(?) < 0 (signed), and falls through when t3(?) >= 0 (signed).
  The `bne` branch at 0x54bc targets 0x5444, is taken when v0(=[sym(.sdata)+16]) < s4(?) (unsigned), and falls through when v0(=[sym(.sdata)+16]) >= s4(?) (unsigned).
  The `beq` branch at 0x54dc targets 0x54b4, is taken when a0(?) == a1(?), and falls through when a0(?) != a1(?).
  The `bne` branch at 0x54e4 targets 0x54b4, is taken when a1(=[sym(partition_partid)]:1) != s4(?), and falls through when a1(=[sym(partition_partid)]:1) == s4(?).
  The `bltz` branch at 0x5500 targets 0x5520, is taken when a2(=([ret(part_get_nasid)+4] << 0x8)) < 0 (signed), and falls through when a2(=([ret(part_get_nasid)+4] << 0x8)) >= 0 (signed).
  The `bltz` branch at 0x5508 targets 0x5540, is taken when a3(=([ret(part_get_nasid)+4] << 0x9)) < 0 (signed), and falls through when a3(=([ret(part_get_nasid)+4] << 0x9)) >= 0 (signed).
  The `bgez` branch at 0x5510 targets 0x5468, is taken when a4(=([ret(part_get_nasid)+4] << 0xa)) >= 0 (signed), and falls through when a4(=([ret(part_get_nasid)+4] << 0xa)) < 0 (signed).
  The `beq` branch at 0x5518 targets 0x5478 and is always taken.
  The `beq` branch at 0x5520 targets 0x5488 and is always taken.
  The `beq` branch at 0x5538 targets 0x5498 and is always taken.
  The `beq` branch at 0x5540 targets 0x547c and is always taken.
  The `beq` branch at 0x5554 targets 0x5458 and is always taken.
  The `beq` branch at 0x5584 targets 0x5270 and is always taken.
  The `beq` branch at 0x55b4 targets 0x5270 and is always taken.
  The `beq` branch at 0x55e8 targets 0x53c8 and is always taken.
  The `beq` branch at 0x5618 targets 0x53bc and is always taken.
  The `beq` branch at 0x5648 targets 0x5270 and is always taken.
  The `beq` branch at 0x567c targets 0x5438 and is always taken.
  The `beq` branch at 0x5688 targets 0x52a8 and is always taken.
  The return at 0x5414 has v0 = ret(timeout).

- `part_heartbeat_timeout` in `IP35/usr/cpu/sysgen/IP35boot/partition.o` at 0x5690 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/partition.o`.
  Range: 0x5690-0x5698 (8 bytes).
  It occupies 8 bytes.
  The return at 0x5690 has v0 = [sym(.sdata)+24].

- `part_heart_beater` in `IP35/usr/cpu/sysgen/IP35boot/partition.o` at 0x5698 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/partition.o`.
  Range: 0x5698-0x56b8 (32 bytes).
  It occupies 32 bytes.
  The `ld` at 0x56a4 loads 8 bytes from [sym(.sdata)+32]:8 +0x18.
  The `sd` at 0x56ac stores 8 bytes to [sym(.sdata)+32]:8 +0x18.
  The `beq` branch at 0x569c targets 0x56b0, is taken when a1(=[sym(.sdata)+32]:8) == 0, and falls through when a1(=[sym(.sdata)+32]:8) != 0.
  The return at 0x56b0 has v0 = ?.

- `part_thread` in `IP35/usr/cpu/sysgen/IP35boot/partition.o` at 0x56b8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/partition.o`.
  Range: 0x56b8-0x57c8 (272 bytes).
  It occupies 272 bytes.
  3 such `ll` accesses load 4 bytes from ?, including `ll` at 0x5718, `ll` at 0x5770, `ll` at 0x5794.
  3 such `sc` accesses store 4 bytes to ?, including `sc` at 0x5724, `sc` at 0x577c, `sc` at 0x57a0.
  The `lw` at 0x575c loads 4 bytes from ?.
  The `sw` at 0x57b0 stores 4 bytes to ?.
  The `jal` at 0x5704 calls part_start_partition_thread with a0=?, a1=0x1, a2=0x1, a3=-0x1.
  The `jal` at 0x57b8 calls psema with a0=sym(.bss), a1=0x19, a2=?, a3=?.
  The `beq` branch at 0x56d0 targets 0x56f4 and is always taken.
  The `bne` branch at 0x56e8 targets 0x5748, is taken when s0(?) < 0x40 (signed), and falls through when s0(?) >= 0x40 (signed).
  The `blez` branch at 0x56f0 targets 0x57b4, is taken when s2(?) <= 0 (signed), and falls through when s2(?) > 0 (signed).
  The `beq` branch at 0x56f8 targets 0x5744 and is always taken.
  The `beql` branch at 0x5728 targets 0x5718, is taken when at(=table(-0x1)) == 0, and falls through when at(=table(-0x1)) != 0; its branch-likely delay slot `nop` at 0x572c runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x5740 targets 0x56f0, is taken when s0(?) >= 0x40 (signed), and falls through when s0(?) < 0x40 (signed).
  The `blez` branch at 0x5760 targets 0x56d8, is taken when s1(?) <= 0 (signed), and falls through when s1(?) > 0 (signed).
  The `beql` branch at 0x5780 targets 0x5770, is taken when a4(?) == 0, and falls through when a4(?) != 0; its branch-likely delay slot `nop` at 0x5784 runs only when taken and is annulled on fall-through.
  The `bgez` branch at 0x5788 targets 0x5700, is taken when a1(?) >= 0 (signed), and falls through when a1(?) < 0 (signed).
  The `beql` branch at 0x57a4 targets 0x5794, is taken when a7(?) == 0, and falls through when a7(?) != 0; its branch-likely delay slot `nop` at 0x57a8 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x57ac targets 0x5730 and is always taken.
  The `beq` branch at 0x57c0 targets 0x56f8 and is always taken.
