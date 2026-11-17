# Readings: `IP27/usr/cpu/sysgen/IP27boot/ioc3ei.o`

One entry per routine, filed here from the reading batches by binary.

- `ei_make_hwgraph_nodes` in `IP27/usr/cpu/sysgen/IP27boot/ioc3ei.o` at 0x0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/ioc3ei.o`.
  Range: 0x0-0x9c (156 bytes).
  It occupies 156 bytes.
  The `ll` at 0x14 loads 4 bytes from a0 (arg0 at entry) +0x28.
  The `sc` at 0x1c stores 4 bytes to a0 (arg0 at entry) +0x28.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x4, including `lw` at 0x48, `lw` at 0x90.
  The `jal` at 0x44 calls device_controller_num_get with a0=[a0+4], a1=a0 at entry (arg0), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x64 calls hwgraph_path_add with a0=[sym(hwgraph_root)], a1=sym(.rodata), a2=sp-32, a3=?.
  The `jal` at 0x78 calls sprintf with a0=sp-28, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x8c calls hwgraph_edge_add with a0=?, a1=[a0+4], a2=sp-28, a3=?.
  The `beql` branch at 0x20 targets 0x14, is taken when a0(=([a0+40] | 0x1)) == 0, and falls through when a0(=([a0+40] | 0x1)) != 0; its branch-likely delay slot `nop` at 0x24 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x2c targets 0x40, is taken when (at(=[a0+40]) & 0x1) == 0, and falls through when (at(=[a0+40]) & 0x1) != 0.
  The `blez` branch at 0x4c targets 0x34, is taken when v0(=ret(device_controller_num_get)) <= 0 (signed), and falls through when v0(=ret(device_controller_num_get)) > 0 (signed).
  The `beq` branch at 0x54 targets 0x34, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x94 targets 0x38 and is always taken.
  The return at 0x38 has v0 = one of ?, ret(hwgraph_edge_add).

- `ei_exit` in `IP27/usr/cpu/sysgen/IP27boot/ioc3ei.o` at 0x9c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/ioc3ei.o`.
  Range: 0x9c-0x174 (216 bytes).
  It occupies 216 bytes.
  The `ld` at 0xc0 loads 8 bytes from a0 (arg0 at entry) +0x18.
  The `ld` at 0xd8 loads 8 bytes from abs 0xffffffffffffc018.
  The `ld` at 0xe4 loads 8 bytes from [-0x3fe8]:8 +0x2f8.
  The `lw` at 0xf0 loads 4 bytes from [[-0x3fe8]:8+760]:8 +0x10.
  The `lw` at 0xf4 loads 4 bytes from ?.
  3 such `ld` accesses load 8 bytes from ?, including `ld` at 0x100, `ld` at 0x104, `ld` at 0x148.
  The `sd` at 0x154 stores 8 bytes to ?.
  The `jal` at 0xb8 calls mutex_spinlock with a0=a0+20, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x118 calls mutex_spinunlock with a0=a0+20, a1=ret(mutex_spinlock), a2=?, a3=?.
  The `jal` at 0x138 calls kthread_get_pid with a0=?, a1=?, a2=?, a3=?, a4=[-0x3fe8]:8.
  The `jal` at 0x150 calls spinlock_destroy with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x158 calls sv_destroy with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x164 calls kmem_free with a0=?, a1=0x28, a2=?, a3=?.
  The `beq` branch at 0xcc targets 0x110, is taken when a0(=[a0+24]:8) == 0, and falls through when a0(=[a0+24]:8) != 0.
  The `beq` branch at 0xdc targets 0x138, is taken when a4(=[-0x3fe8]:8) == 0, and falls through when a4(=[-0x3fe8]:8) != 0.
  The `beq` branch at 0xe8 targets 0x138, is taken when a5(=[[-0x3fe8]:8+760]:8) == 0, and falls through when a5(=[[-0x3fe8]:8+760]:8) != 0.
  The `beq` branch at 0xf8 targets 0x148, is taken when at(?) == a4(?), and falls through when at(?) != a4(?).
  The `bne` branch at 0x108 targets 0xd8, is taken when s0(?) != 0, and falls through when s0(?) == 0.
  The `beq` branch at 0x140 targets 0xf4 and is always taken.
  The `beq` branch at 0x16c targets 0x114 and is always taken.
  The return at 0x130 has v0 = ret(mutex_spinunlock).

- `find_pstate` in `IP27/usr/cpu/sysgen/IP27boot/ioc3ei.o` at 0x174 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/ioc3ei.o`.
  Range: 0x174-0x2f4 (384 bytes).
  It occupies 384 bytes.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x18, including `ld` at 0x19c, `ld` at 0x274.
  3 such `ld` accesses load 8 bytes from abs 0xffffffffffffc018, including `ld` at 0x1a8, `ld` at 0x1e4, `ld` at 0x224.
  3 such `ld` accesses load 8 bytes from [-0x3fe8]:8 +0x2f8, including `ld` at 0x1b4, `ld` at 0x1f0, `ld` at 0x230.
  3 such `lw` accesses load 4 bytes from [[-0x3fe8]:8+760]:8 +0x10, including `lw` at 0x1c0, `lw` at 0x1fc, `lw` at 0x23c.
  The `lw` at 0x1c4 loads 4 bytes from ?.
  The `ld` at 0x1d0 loads 8 bytes from ?.
  The `sw` at 0x248 stores 4 bytes to ret(kmem_zalloc) +0x0.
  The `sd` at 0x27c stores 8 bytes to ret(kmem_zalloc) +0x8.
  The `sd` at 0x288 stores 8 bytes to a0 (arg0 at entry) +0x18.
  The `jal` at 0x194 calls mutex_spinlock with a0=a0+20, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1dc calls mutex_spinunlock with a0=a0+20, a1=ret(mutex_spinlock), a2=?, a3=?.
  The `jal` at 0x208 calls add_exit_callback with a0=?, a1=0x0, a2=sym(ei_exit), a3=a0 at entry (arg0).
  The `jal` at 0x214 calls kmem_zalloc with a0=0x28, a1=0x0, a2=?, a3=?.
  The `jal` at 0x24c calls spinlock_init with a0=ret(kmem_zalloc)+24, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x264 calls init_sv with a0=ret(kmem_zalloc)+32, a1=0x0, a2=sym(.rodata), a3=-0x1.
  The `jal` at 0x26c calls mutex_spinlock with a0=a0+20, a1=?, a2=?, a3=?.
  The `jal` at 0x284 calls mutex_spinunlock with a0=a0+20, a1=ret(mutex_spinlock), a2=?, a3=[a0+24]:8.
  The `jal` at 0x2ac calls kthread_get_pid with a0=?, a1=?, a2=?, a3=?, a5=[-0x3fe8]:8.
  The `jal` at 0x2bc calls mutex_spinunlock with a0=a0+20, a1=ret(mutex_spinlock), a2=?, a3=?.
  The `jal` at 0x2d4 calls kthread_get_pid with a0=?, a1=?, a2=?, a3=?, a5=[-0x3fe8]:8.
  The `jal` at 0x2e4 calls kthread_get_pid with a0=?, a1=?, a2=?, a3=?, a5=[-0x3fe8]:8.
  The `beq` branch at 0x1a0 targets 0x1d8, is taken when s0(=[a0+24]:8) == 0, and falls through when s0(=[a0+24]:8) != 0.
  The `beq` branch at 0x1ac targets 0x2ac, is taken when a5(=[-0x3fe8]:8) == 0, and falls through when a5(=[-0x3fe8]:8) != 0.
  The `beq` branch at 0x1b8 targets 0x2ac, is taken when a6(=[[-0x3fe8]:8+760]:8) == 0, and falls through when a6(=[[-0x3fe8]:8+760]:8) != 0.
  The `beq` branch at 0x1c8 targets 0x2bc, is taken when at(?) == a5(?), and falls through when at(?) != a5(?).
  The `bne` branch at 0x1d4 targets 0x1a8, is taken when s0(?) != 0, and falls through when s0(?) == 0.
  The `beq` branch at 0x1e8 targets 0x2d4, is taken when a5(=[-0x3fe8]:8) == 0, and falls through when a5(=[-0x3fe8]:8) != 0.
  The `beq` branch at 0x1f4 targets 0x2d4, is taken when v0(=[[-0x3fe8]:8+760]:8) == 0, and falls through when v0(=[[-0x3fe8]:8+760]:8) != 0.
  The `beq` branch at 0x21c targets 0x2cc, is taken when v0(=ret(kmem_zalloc)) == 0, and falls through when v0(=ret(kmem_zalloc)) != 0.
  The `beq` branch at 0x228 targets 0x2e4, is taken when a5(=[-0x3fe8]:8) == 0, and falls through when a5(=[-0x3fe8]:8) != 0.
  The `beq` branch at 0x234 targets 0x2e4, is taken when v0(=[[-0x3fe8]:8+760]:8) == 0, and falls through when v0(=[[-0x3fe8]:8+760]:8) != 0.
  The `beq` branch at 0x2b4 targets 0x1c4 and is always taken.
  The `beq` branch at 0x2c4 targets 0x290 and is always taken.
  The `beq` branch at 0x2cc targets 0x28c and is always taken.
  The `beq` branch at 0x2dc targets 0x200 and is always taken.
  The `beq` branch at 0x2ec targets 0x240 and is always taken.
  The return at 0x2a4 has v0 = ?.

- `ioc3_ei_intr` in `IP27/usr/cpu/sysgen/IP27boot/ioc3ei.o` at 0x2f4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/ioc3ei.o`.
  Range: 0x2f4-0x428 (308 bytes).
  It occupies 308 bytes.
  The `ld` at 0x2f4 loads 8 bytes from a0 (arg0 at entry) +0x8.
  The `sw` at 0x2fc stores 4 bytes to [a0+8]:8 +0x1c.
  The `lw` at 0x300 loads 4 bytes from abs 0xffffffffffffc6a0.
  3 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x30, including `ld` at 0x320, `ld` at 0x34c, `ld` at 0x410.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x10, including `lw` at 0x324, `lw` at 0x350, `lw` at 0x414.
  The `lw` at 0x338 loads 4 bytes from a0 (arg0 at entry) +0x2c.
  The `ld` at 0x37c loads 8 bytes from a0 (arg0 at entry) +0x20.
  The `lw` at 0x380 loads 4 bytes from [a0+32]:8 +0x0.
  The `sw` at 0x388 stores 4 bytes to [a0+32]:8 +0x0.
  The `ld` at 0x38c loads 8 bytes from a0 (arg0 at entry) +0x18.
  The `ll` at 0x3a0 loads 4 bytes from ?.
  The `sc` at 0x3ac stores 4 bytes to ?.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0x3b8, `lw` at 0x3cc.
  The `ld` at 0x3f4 loads 8 bytes from ?.
  The `jal` at 0x318 calls frs_handle_eintr with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x328 calls ioc3_write_ireg with a0=[a0+48]:8, a1=[a0+16], a2=0x0, a3=?.
  The `jal` at 0x344 calls uli_callup with a0=[a0+44], a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x354 calls ioc3_write_ireg with a0=[a0+48]:8, a1=[a0+16], a2=0x0, a3=?.
  The `jal` at 0x374 calls mutex_spinlock with a0=a0+20, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x3d0 calls sigtopid with a0=?, a1=?, a2=0x12, a3=0x0, a4=0x0, a5=0x0.
  The `jal` at 0x3dc calls nested_spinlock with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x3e4 calls sv_signal with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x3ec calls nested_spinunlock with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x408 calls mutex_spinunlock with a0=a0+20, a1=ret(mutex_spinlock), a2=?, a3=?.
  The `jal` at 0x418 calls ioc3_write_ireg with a0=[a0+48]:8, a1=[a0+16], a2=0x0, a3=?.
  The `beq` branch at 0x310 targets 0x338, is taken when at(=[-0x3960]) == 0, and falls through when at(=[-0x3960]) != 0.
  The `beq` branch at 0x330 targets 0x360 and is always taken.
  The `bltz` branch at 0x33c targets 0x36c, is taken when a0(=[a0+44]) < 0 (signed), and falls through when a0(=[a0+44]) >= 0 (signed).
  The `beq` branch at 0x390 targets 0x400, is taken when s0(=[a0+24]:8) == 0, and falls through when s0(=[a0+24]:8) != 0.
  The `beql` branch at 0x3b0 targets 0x3a0, is taken when a4(?) == 0, and falls through when a4(?) != 0; its branch-likely delay slot `nop` at 0x3b4 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x3bc targets 0x3d8, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `bne` branch at 0x3f8 targets 0x398, is taken when s0(?) != 0, and falls through when s0(?) == 0.
  The `beq` branch at 0x420 targets 0x360 and is always taken.
  The return at 0x364 has v0 = ret(ioc3_write_ireg).

- `eiinit` in `IP27/usr/cpu/sysgen/IP27boot/ioc3ei.o` at 0x428 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/ioc3ei.o`.
  Range: 0x428-0x430 (8 bytes).
  It occupies 8 bytes.
  The return at 0x428 has v0 = ?.

- `eireg` in `IP27/usr/cpu/sysgen/IP27boot/ioc3ei.o` at 0x430 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/ioc3ei.o`.
  Range: 0x430-0x45c (44 bytes).
  It occupies 44 bytes.
  The `jal` at 0x448 calls pciio_driver_register with a0=0x10a9, a1=0x3, a2=sym(.rodata), a3=0x0.
  The return at 0x454 has v0 = ret(pciio_driver_register).

- `eiunreg` in `IP27/usr/cpu/sysgen/IP27boot/ioc3ei.o` at 0x45c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/ioc3ei.o`.
  Range: 0x45c-0x47c (32 bytes).
  It occupies 32 bytes.
  The `jal` at 0x468 calls pciio_driver_unregister with a0=sym(.rodata), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x474 has v0 = ret(pciio_driver_unregister).

- `use_ithread` in `IP27/usr/cpu/sysgen/IP27boot/ioc3ei.o` at 0x47c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/ioc3ei.o`.
  Range: 0x47c-0x4a8 (44 bytes).
  It occupies 44 bytes.
  The `lw` at 0x47c loads 4 bytes from a0 (arg0 at entry) +0x2c.
  The `lw` at 0x48c loads 4 bytes from abs 0xffffffffffffc6a0.
  The `bne` branch at 0x484 targets 0x4a0, is taken when at(=[a0+44]) != v0(=-0x1), and falls through when at(=[a0+44]) == v0(=-0x1).
  The `beq` branch at 0x494 targets 0x4a0, is taken when (v1(=[-0x3960]) & 0x8) == 0, and falls through when (v1(=[-0x3960]) & 0x8) != 0.
  The return at 0x4a0 has v0 = one of 0x0, 0x1.

- `eiattach` in `IP27/usr/cpu/sysgen/IP27boot/ioc3ei.o` at 0x4a8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/ioc3ei.o`.
  Range: 0x4a8-0x64c (420 bytes).
  It occupies 420 bytes.
  The `sd` at 0x51c stores 8 bytes to ret(kmem_zalloc) +0x8.
  The `sd` at 0x530 stores 8 bytes to ret(kmem_zalloc) +0x30.
  The `sw` at 0x534 stores 4 bytes to ret(kmem_zalloc) +0x0.
  The `sd` at 0x550 stores 8 bytes to ret(kmem_zalloc) +0x20.
  The `sw` at 0x568 stores 4 bytes to ret(ioc3_mem_ptr) +0x38.
  The `sw` at 0x570 stores 4 bytes to ret(ioc3_mem_ptr) +0x34.
  The `sw` at 0x57c stores 4 bytes to ret(ioc3_mem_ptr) +0x2c.
  The `sw` at 0x584 stores 4 bytes to ret(kmem_zalloc) +0x2c.
  The `sw` at 0x5a8 stores 4 bytes to ret(kmem_zalloc) +0x4.
  The `sw` at 0x618 stores 4 bytes to ret(kmem_zalloc) +0x10.
  The `jal` at 0x4b8 calls ioc3_subdev_enabled with a0=a0 at entry (arg0), a1=0x7, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x4d4 calls hwgraph_traverse with a0=a0 at entry (arg0), a1=sym(.rodata), a2=sp-12, a3=?.
  The `jal` at 0x4e8 calls hwgraph_traverse with a0=a0 at entry (arg0), a1=sym(.rodata), a2=sp-64, a3=?.
  The `jal` at 0x4f0 calls hwgraph_fastinfo_get with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x500 calls ioc3_mem_ptr with a0=ret(hwgraph_fastinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0x510 calls kmem_zalloc with a0=0x38, a1=0x1, a2=?, a3=?.
  The `jal` at 0x538 calls spinlock_init with a0=ret(kmem_zalloc)+20, a1=sym(.rodata), a2=a0 at entry (arg0), a3=?.
  The `jal` at 0x548 calls kvpalloc with a0=0x1, a1=0x80000, a2=0x0, a3=?.
  The `jal` at 0x590 calls hwgraph_char_device_add with a0=a0 at entry (arg0), a1=sym(.rodata), a2=sym(.rodata), a3=sp-60, a4=0x2.
  The `jal` at 0x59c calls hwgraph_chmod with a0=?, a1=0x124, a2=?, a3=?.
  The `jal` at 0x5b0 calls hwgraph_fastinfo_set with a0=?, a1=ret(kmem_zalloc), a2=?, a3=?.
  The `jal` at 0x5cc calls device_inventory_add with a0=?, a1=0xe, a2=0x2, a3=0x0, a4=0x0, a5=0x0.
  The `jal` at 0x5d4 calls ioc3_is_console with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x5e4 calls device_controller_num_set with a0=?, a1=0x1, a2=?, a3=?.
  The `jal` at 0x5ec calls ei_make_hwgraph_nodes with a0=ret(kmem_zalloc), a1=?, a2=?, a3=?.
  The `jal` at 0x610 calls ioc3_intr_connect with a0=a0 at entry (arg0), a1=0x18000000, a2=sym(ioc3_ei_intr), a3=ret(kmem_zalloc), a6=sym(use_ithread).
  The `jal` at 0x63c calls device_controller_num_set with a0=?, a1=-0x1, a2=?, a3=?.
  The `beq` branch at 0x4c0 targets 0x634, is taken when v0(=ret(ioc3_subdev_enabled)) == 0, and falls through when v0(=ret(ioc3_subdev_enabled)) != 0.
  The `bne` branch at 0x554 targets 0x564, is taken when v0(=ret(kvpalloc)) != 0, and falls through when v0(=ret(kvpalloc)) == 0.
  The `beq` branch at 0x55c targets 0x620 and is always taken.
  The `beq` branch at 0x5dc targets 0x63c, is taken when v0(=ret(ioc3_is_console)) == 0, and falls through when v0(=ret(ioc3_is_console)) != 0.
  The `beq` branch at 0x634 targets 0x620 and is always taken.
  The `beq` branch at 0x644 targets 0x5f8 and is always taken.
  The return at 0x62c has v0 = one of -0x1, 0x0.

- `eiopen` in `IP27/usr/cpu/sysgen/IP27boot/ioc3ei.o` at 0x64c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/ioc3ei.o`.
  Range: 0x64c-0x6ac (96 bytes).
  It occupies 96 bytes.
  The `lw` at 0x64c loads 4 bytes from a0 (arg0 at entry) +0x0.
  The `ld` at 0x68c loads 8 bytes from ret(hwgraph_fastinfo_get) +0x8.
  The `sw` at 0x694 stores 4 bytes to [ret(hwgraph_fastinfo_get)+8]:8 +0x34.
  The `jal` at 0x664 calls hwgraph_fastinfo_get with a0=[a0], a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=[a0].
  The `jal` at 0x670 calls find_pstate with a0=ret(hwgraph_fastinfo_get), a1=?, a2=?, a3=?.
  The `beq` branch at 0x65c targets 0x6a4, is taken when a3(=[a0]) == at(=-0x1), and falls through when a3(=[a0]) != at(=-0x1).
  The `bne` branch at 0x678 targets 0x688, is taken when v0(=ret(find_pstate)) != 0, and falls through when v0(=ret(find_pstate)) == 0.
  The `beq` branch at 0x680 targets 0x69c and is always taken.
  The `beq` branch at 0x6a4 targets 0x69c and is always taken.
  The return at 0x69c has v0 = one of 0x0, 0xc, 0x13.

- `eiclose` in `IP27/usr/cpu/sysgen/IP27boot/ioc3ei.o` at 0x6ac (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/ioc3ei.o`.
  Range: 0x6ac-0x724 (120 bytes).
  It occupies 120 bytes.
  The `ld` at 0x6d4 loads 8 bytes from ret(hwgraph_fastinfo_get) +0x30.
  The `ld` at 0x6dc loads 8 bytes from ret(hwgraph_fastinfo_get) +0x8.
  The `lw` at 0x6f8 loads 4 bytes from ret(hwgraph_fastinfo_get) +0x10.
  The `sw` at 0x708 stores 4 bytes to ret(hwgraph_fastinfo_get) +0x10.
  The `sw` at 0x70c stores 4 bytes to [ret(hwgraph_fastinfo_get)+8]:8 +0x2c.
  The `sw` at 0x718 stores 4 bytes to ret(hwgraph_fastinfo_get) +0x2c.
  The `jal` at 0x6c8 calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x6e4 calls ioc3_write_ireg with a0=[ret(hwgraph_fastinfo_get)+48]:8, a1=0x18000000, a2=0x1, a3=?.
  The `bne` branch at 0x6b8 targets 0x6c8, is taken when at(=-0x1) != a0, and falls through when at(=-0x1) == a0.
  The `beq` branch at 0x6c0 targets 0x71c and is always taken.
  The return at 0x71c has v0 = one of 0x0, 0x13.

- `ei_uli_teardown` in `IP27/usr/cpu/sysgen/IP27boot/ioc3ei.o` at 0x724 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/ioc3ei.o`.
  Range: 0x724-0x734 (16 bytes).
  It occupies 16 bytes.
  The `ld` at 0x724 loads 8 bytes from a0 (arg0 at entry) +0xd0.
  The `sw` at 0x730 stores 4 bytes to [a0+208]:8 +0x2c.
  The return at 0x72c has v0 = [a0+208]:8.

- `register_uli` in `IP27/usr/cpu/sysgen/IP27boot/ioc3ei.o` at 0x734 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/ioc3ei.o`.
  Range: 0x734-0x884 (336 bytes).
  It occupies 336 bytes.
  The `lw` at 0x798 loads 4 bytes from a0 (arg0 at entry) +0x2c.
  5 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x2c, including `sw` at 0x7bc, `sw` at 0x800, `sw` at 0x80c.
  The `ld` at 0x7cc loads 8 bytes from a0 (arg0 at entry) +0x30.
  2 such `sd` accesses store 8 bytes to ?, including `sd` at 0x818, `sd` at 0x820.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0x828, `lw` at 0x874.
  The `jal` at 0x748 calls get_current_abi with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x768 calls copyin_xlate with a0=a1 at entry (arg1), a1=sp-96, a2=0x28, a3=sym(irix5_to_uliargs), a4=ret(get_current_abi), a5=0x4, a6=0x1.
  The `jal` at 0x790 calls mutex_spinlock with a0=a0+20, a1=?, a2=?, a3=?.
  The `jal` at 0x7a8 calls mutex_spinunlock with a0=?, a1=ret(mutex_spinlock), a2=?, a3=?.
  The `jal` at 0x7c0 calls mutex_spinunlock with a0=?, a1=ret(mutex_spinlock), a2=?, a3=?.
  The `jal` at 0x7c8 calls ioc3_intr_cpu_get with a0=[a0+48]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x7d4 calls cpu_isvalid with a0=ret(ioc3_intr_cpu_get), a1=?, a2=?, a3=?.
  The `jal` at 0x7ec calls new_uli with a0=sp-96, a1=sp-56, a2=?, a3=?.
  The `jal` at 0x82c calls get_current_abi with a0=?, a1=?, a2=-0x1, a3=?, a6=sym(ei_uli_teardown).
  The `jal` at 0x84c calls xlate_copyout with a0=sp-96, a1=a1 at entry (arg1), a2=0x28, a3=sym(uliargs_to_irix5), a4=ret(get_current_abi), a5=0x4, a6=0x1.
  The `jal` at 0x85c calls free_uli with a0=?, a1=?, a2=?, a3=?.
  The `beq` branch at 0x770 targets 0x790, is taken when v0(=ret(copyin_xlate)) == 0, and falls through when v0(=ret(copyin_xlate)) != 0.
  The `beq` branch at 0x7a0 targets 0x7b8, is taken when at(=[a0+44]) == v1(=-0x1), and falls through when at(=[a0+44]) != v1(=-0x1).
  The `beq` branch at 0x7b0 targets 0x77c and is always taken.
  The `beq` branch at 0x7dc targets 0x804, is taken when v0(=ret(cpu_isvalid)) == 0, and falls through when v0(=ret(cpu_isvalid)) != 0.
  The `beq` branch at 0x7f4 targets 0x810, is taken when v0(=ret(new_uli)) == 0, and falls through when v0(=ret(new_uli)) != 0.
  The `beq` branch at 0x7fc targets 0x77c and is always taken.
  The `beq` branch at 0x808 targets 0x77c and is always taken.
  The `beq` branch at 0x854 targets 0x874, is taken when v0(=ret(xlate_copyout)) == 0, and falls through when v0(=ret(xlate_copyout)) != 0.
  The `beq` branch at 0x86c targets 0x77c and is always taken.
  The `beq` branch at 0x87c targets 0x77c and is always taken.
  The return at 0x788 has v0 = one of 0xe, 0x10, ret(new_uli), 0x16, 0x0.

- `set_output_mode` in `IP27/usr/cpu/sysgen/IP27boot/ioc3ei.o` at 0x884 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/ioc3ei.o`.
  Range: 0x884-0x8e0 (92 bytes).
  It occupies 92 bytes.
  The `ld` at 0x8a8 loads 8 bytes from a0 (arg0 at entry) +0x8.
  The `lw` at 0x8b0 loads 4 bytes from [a0+8]:8 +0x2c.
  The `sw` at 0x8cc stores 4 bytes to [a0+8]:8 +0x2c.
  The `jal` at 0x89c calls mutex_spinlock with a0=a0+20, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x8c8 calls mutex_spinunlock with a0=a0+20, a1=ret(mutex_spinlock), a2=?, a3=?.
  The return at 0x8d8 has v0 = ret(mutex_spinunlock).

- `eiioctl` in `IP27/usr/cpu/sysgen/IP27boot/ioc3ei.o` at 0x8e0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/ioc3ei.o`.
  Range: 0x8e0-0xdb4 (1236 bytes).
  It occupies 1236 bytes.
  The `ld` at 0x93c loads 8 bytes from (sym(.rodata) + (a1-25857 << 0x3)) +0x0.
  The `jal` at 0x904 calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x910 calls find_pstate with a0=ret(hwgraph_fastinfo_get), a1=?, a2=?, a3=?.
  Calls (unknown callee) via register with a0=a2 at entry (arg2), a1=(a1-25857 << 0x3), a2=[(sym(.rodata) + (a1-25857 << 0x3))]:8, a3=? (`jr` at 0x940).
  The `beq` branch at 0x8fc targets 0x968, is taken when at(=-0x1) == a0, and falls through when at(=-0x1) != a0.
  The `beq` branch at 0x934 targets 0x948, is taken when a1(=a1-25857) >= 0x19 (unsigned), and falls through when a1(=a1-25857) < 0x19 (unsigned).
  The `beq` branch at 0x968 targets 0x94c and is always taken.
  The return at 0x960 has v0 = one of 0x13, 0x16.
  The instructions from 0x970 to 0xdb0 are not reached by any path from the entry, and their branches are not listed.
  The indirect jump at 0x940 uses a jump table whose successors are unresolved.

- `eimap` in `IP27/usr/cpu/sysgen/IP27boot/ioc3ei.o` at 0xdb4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/ioc3ei.o`.
  Range: 0xdb4-0xe48 (148 bytes).
  It occupies 148 bytes.
  The `ld` at 0xe34 loads 8 bytes from ret(hwgraph_fastinfo_get) +0x20.
  The `jal` at 0xddc calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a7=0x13.
  The `jal` at 0xe38 calls v_mapphys with a0=a1 at entry (arg1), a1=[ret(hwgraph_fastinfo_get)+32]:8, a2=a3 at entry (arg3), a3=?, a7=0xd.
  The `beq` branch at 0xdd4 targets 0xdf4, is taken when a0 == at(=-0x1), and falls through when a0 != at(=-0x1).
  The `beq` branch at 0xdec targets 0xe08, is taken when s0(=a3) == v1(=0x4000), and falls through when s0(=a3) != v1(=0x4000).
  The `bne` branch at 0xe08 targets 0xe28, is taken when a0(=a2) != 0, and falls through when a0(=a2) == 0.
  The `beq` branch at 0xe18 targets 0xe30, is taken when (a1(=a4) & 0x2) == 0, and falls through when (a1(=a4) & 0x2) != 0.
  The `beq` branch at 0xe20 targets 0xdf8 and is always taken.
  The `beq` branch at 0xe28 targets 0xdf8 and is always taken.
  The `beq` branch at 0xe40 targets 0xdf4 and is always taken.
  The return at 0xe00 has v0 = one of ?, 0xd, 0x16.

- `eiunmap` in `IP27/usr/cpu/sysgen/IP27boot/ioc3ei.o` at 0xe48 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/ioc3ei.o`.
  Range: 0xe48-0xe50 (8 bytes).
  It occupies 8 bytes.
  The return at 0xe48 has v0 = 0x0.

- `irix5_to_eiargs_xlate` in `IP27/usr/cpu/sysgen/IP27boot/ioc3ei.o` at 0xe50 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/ioc3ei.o`.
  Range: 0xe50-0xec8 (120 bytes).
  It occupies 120 bytes.
  The `lw` at 0xe64 loads 4 bytes from a3 (arg3 at entry) +0x0.
  The `ld` at 0xe74 loads 8 bytes from a3 (arg3 at entry) +0x8.
  2 such `sd` accesses store 8 bytes to a3 (arg3 at entry) +0x10, including `sd` at 0xe78, `sd` at 0xec4.
  The `sw` at 0xe80 stores 4 bytes to a3 (arg3 at entry) +0x4.
  The `ld` at 0xe8c loads 8 bytes from a3 (arg3 at entry) +0x10.
  The `lw` at 0xe90 loads 4 bytes from [a3+16]:8 +0x0.
  The `sw` at 0xe94 stores 4 bytes to a1 (arg1 at entry) +0x0.
  The `lw` at 0xe98 loads 4 bytes from [a3+16]:8 +0x4.
  The `sw` at 0xe9c stores 4 bytes to a1 (arg1 at entry) +0xc.
  The `lw` at 0xea0 loads 4 bytes from [a3+16]:8 +0x8.
  The `sd` at 0xea4 stores 8 bytes to a1 (arg1 at entry) +0x10.
  The `jal` at 0xeb4 calls kern_malloc with a0=0xc, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `bne` branch at 0xe5c targets 0xe8c, is taken when a0 != 0, and falls through when a0 == 0.
  The `bne` branch at 0xe6c targets 0xeb4, is taken when at(=[a3]) < 0xc (unsigned), and falls through when at(=[a3]) >= 0xc (unsigned).
  The `beq` branch at 0xe84 targets 0xea8 and is always taken.
  The `beq` branch at 0xec0 targets 0xe7c and is always taken.
  The return at 0xeac has v0 = 0x0.

- `eiargs_to_irix5_xlate` in `IP27/usr/cpu/sysgen/IP27boot/ioc3ei.o` at 0xec8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/ioc3ei.o`.
  Range: 0xec8-0xf40 (120 bytes).
  It occupies 120 bytes.
  The `lw` at 0xec8 loads 4 bytes from a2 (arg2 at entry) +0x0.
  The `ld` at 0xeec loads 8 bytes from a2 (arg2 at entry) +0x8.
  2 such `sd` accesses store 8 bytes to a2 (arg2 at entry) +0x10, including `sd` at 0xef0, `sd` at 0xf3c.
  The `sw` at 0xef8 stores 4 bytes to a2 (arg2 at entry) +0x4.
  The `lw` at 0xf00 loads 4 bytes from a0 (arg0 at entry) +0x0.
  3 such `sw` accesses store 4 bytes to ?, including `sw` at 0xf04, `sw` at 0xf0c, `sw` at 0xf1c.
  The `lw` at 0xf08 loads 4 bytes from a0 (arg0 at entry) +0xc.
  The `ld` at 0xf10 loads 8 bytes from a0 (arg0 at entry) +0x10.
  The `jal` at 0xf28 calls kern_malloc with a0=0xc, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `bne` branch at 0xee4 targets 0xf28, is taken when at(=[a2]) < 0xc (unsigned), and falls through when at(=[a2]) >= 0xc (unsigned).
  The `beq` branch at 0xf38 targets 0xef4 and is always taken.
  The return at 0xf20 has v0 = 0x0.
