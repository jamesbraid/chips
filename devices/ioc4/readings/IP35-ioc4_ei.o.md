# Readings: `IP35/usr/cpu/sysgen/IP35boot/ioc4_ei.o`

One entry per routine, filed here from the reading batches by binary.

- `ei_make_hwgraph_nodes` in `IP35/usr/cpu/sysgen/IP35boot/ioc4_ei.o` at 0x0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc4_ei.o`.
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

- `ei_exit` in `IP35/usr/cpu/sysgen/IP35boot/ioc4_ei.o` at 0x9c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc4_ei.o`.
  Range: 0x9c-0x174 (216 bytes).
  It occupies 216 bytes.
  The `ld` at 0xc0 loads 8 bytes from a0 (arg0 at entry) +0x18.
  The `ld` at 0xd8 loads 8 bytes from abs 0xffffffffffffc018.
  The `ld` at 0xe4 loads 8 bytes from [-0x3fe8]:8 +0x308.
  The `lw` at 0xf0 loads 4 bytes from [[-0x3fe8]:8+776]:8 +0x10.
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
  The `beq` branch at 0xe8 targets 0x138, is taken when a5(=[[-0x3fe8]:8+776]:8) == 0, and falls through when a5(=[[-0x3fe8]:8+776]:8) != 0.
  The `beq` branch at 0xf8 targets 0x148, is taken when at(?) == a4(?), and falls through when at(?) != a4(?).
  The `bne` branch at 0x108 targets 0xd8, is taken when s0(?) != 0, and falls through when s0(?) == 0.
  The `beq` branch at 0x140 targets 0xf4 and is always taken.
  The `beq` branch at 0x16c targets 0x114 and is always taken.
  The return at 0x130 has v0 = ret(mutex_spinunlock).

- `find_pstate` in `IP35/usr/cpu/sysgen/IP35boot/ioc4_ei.o` at 0x174 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc4_ei.o`.
  Range: 0x174-0x2f4 (384 bytes).
  It occupies 384 bytes.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x18, including `ld` at 0x19c, `ld` at 0x274.
  3 such `ld` accesses load 8 bytes from abs 0xffffffffffffc018, including `ld` at 0x1a8, `ld` at 0x1e4, `ld` at 0x224.
  3 such `ld` accesses load 8 bytes from [-0x3fe8]:8 +0x308, including `ld` at 0x1b4, `ld` at 0x1f0, `ld` at 0x230.
  3 such `lw` accesses load 4 bytes from [[-0x3fe8]:8+776]:8 +0x10, including `lw` at 0x1c0, `lw` at 0x1fc, `lw` at 0x23c.
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
  The `beq` branch at 0x1b8 targets 0x2ac, is taken when a6(=[[-0x3fe8]:8+776]:8) == 0, and falls through when a6(=[[-0x3fe8]:8+776]:8) != 0.
  The `beq` branch at 0x1c8 targets 0x2bc, is taken when at(?) == a5(?), and falls through when at(?) != a5(?).
  The `bne` branch at 0x1d4 targets 0x1a8, is taken when s0(?) != 0, and falls through when s0(?) == 0.
  The `beq` branch at 0x1e8 targets 0x2d4, is taken when a5(=[-0x3fe8]:8) == 0, and falls through when a5(=[-0x3fe8]:8) != 0.
  The `beq` branch at 0x1f4 targets 0x2d4, is taken when v0(=[[-0x3fe8]:8+776]:8) == 0, and falls through when v0(=[[-0x3fe8]:8+776]:8) != 0.
  The `beq` branch at 0x21c targets 0x2cc, is taken when v0(=ret(kmem_zalloc)) == 0, and falls through when v0(=ret(kmem_zalloc)) != 0.
  The `beq` branch at 0x228 targets 0x2e4, is taken when a5(=[-0x3fe8]:8) == 0, and falls through when a5(=[-0x3fe8]:8) != 0.
  The `beq` branch at 0x234 targets 0x2e4, is taken when v0(=[[-0x3fe8]:8+776]:8) == 0, and falls through when v0(=[[-0x3fe8]:8+776]:8) != 0.
  The `beq` branch at 0x2b4 targets 0x1c4 and is always taken.
  The `beq` branch at 0x2c4 targets 0x290 and is always taken.
  The `beq` branch at 0x2cc targets 0x28c and is always taken.
  The `beq` branch at 0x2dc targets 0x200 and is always taken.
  The `beq` branch at 0x2ec targets 0x240 and is always taken.
  The return at 0x2a4 has v0 = ?.

- `ioc4_ei_intr` in `IP35/usr/cpu/sysgen/IP35boot/ioc4_ei.o` at 0x2f4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc4_ei.o`.
  Range: 0x2f4-0x434 (320 bytes).
  It occupies 320 bytes.
  The `ld` at 0x2f4 loads 8 bytes from a0 (arg0 at entry) +0x8.
  The `sw` at 0x2fc stores 4 bytes to [a0+8]:8 +0xc.
  The `lw` at 0x300 loads 4 bytes from abs 0xffffffffffffc6a8.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x10, including `lw` at 0x324, `lw` at 0x354, `lw` at 0x41c.
  3 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x30, including `ld` at 0x330, `ld` at 0x360, `ld` at 0x428.
  The `lw` at 0x33c loads 4 bytes from a0 (arg0 at entry) +0x2c.
  The `ld` at 0x384 loads 8 bytes from a0 (arg0 at entry) +0x20.
  The `lw` at 0x388 loads 4 bytes from [a0+32]:8 +0x0.
  The `sw` at 0x390 stores 4 bytes to [a0+32]:8 +0x0.
  The `ld` at 0x394 loads 8 bytes from a0 (arg0 at entry) +0x18.
  The `ll` at 0x3a8 loads 4 bytes from ?.
  The `sc` at 0x3b4 stores 4 bytes to ?.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0x3c0, `lw` at 0x3d4.
  The `ld` at 0x3fc loads 8 bytes from ?.
  The `jal` at 0x318 calls frs_handle_eintr with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x32c calls ioc4_write_ireg with a0=[a0+48]:8, a1=[a0+16], a2=0x0, a3=0x1.
  The `jal` at 0x348 calls uli_callup with a0=[a0+44], a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x35c calls ioc4_write_ireg with a0=[a0+48]:8, a1=[a0+16], a2=0x0, a3=0x1.
  The `jal` at 0x37c calls mutex_spinlock with a0=a0+20, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x3d8 calls sigtopid with a0=?, a1=?, a2=0x12, a3=0x0, a4=0x0, a5=0x0.
  The `jal` at 0x3e4 calls nested_spinlock with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x3ec calls sv_signal with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x3f4 calls nested_spinunlock with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x410 calls mutex_spinunlock with a0=a0+20, a1=ret(mutex_spinlock), a2=?, a3=?.
  The `jal` at 0x424 calls ioc4_write_ireg with a0=[a0+48]:8, a1=[a0+16], a2=0x0, a3=0x1.
  The `beq` branch at 0x310 targets 0x33c, is taken when at(=[-0x3958]) == 0, and falls through when at(=[-0x3958]) != 0.
  The `beq` branch at 0x334 targets 0x368 and is always taken.
  The `bltz` branch at 0x340 targets 0x374, is taken when a0(=[a0+44]) < 0 (signed), and falls through when a0(=[a0+44]) >= 0 (signed).
  The `beq` branch at 0x398 targets 0x408, is taken when s0(=[a0+24]:8) == 0, and falls through when s0(=[a0+24]:8) != 0.
  The `beql` branch at 0x3b8 targets 0x3a8, is taken when a4(?) == 0, and falls through when a4(?) != 0; its branch-likely delay slot `nop` at 0x3bc runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x3c4 targets 0x3e0, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `bne` branch at 0x400 targets 0x3a0, is taken when s0(?) != 0, and falls through when s0(?) == 0.
  The `beq` branch at 0x42c targets 0x368 and is always taken.
  The return at 0x36c has v0 = ret(ioc4_write_ireg).

- `ioc4_eiinit` in `IP35/usr/cpu/sysgen/IP35boot/ioc4_ei.o` at 0x434 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc4_ei.o`.
  Range: 0x434-0x43c (8 bytes).
  It occupies 8 bytes.
  The return at 0x434 has v0 = ?.

- `ioc4_eireg` in `IP35/usr/cpu/sysgen/IP35boot/ioc4_ei.o` at 0x43c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc4_ei.o`.
  Range: 0x43c-0x468 (44 bytes).
  It occupies 44 bytes.
  The `jal` at 0x454 calls pciio_driver_register with a0=0x10a9, a1=0x100a, a2=sym(.rodata), a3=0x0.
  The return at 0x460 has v0 = ret(pciio_driver_register).

- `ioc4_eiunreg` in `IP35/usr/cpu/sysgen/IP35boot/ioc4_ei.o` at 0x468 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc4_ei.o`.
  Range: 0x468-0x488 (32 bytes).
  It occupies 32 bytes.
  The `jal` at 0x474 calls pciio_driver_unregister with a0=sym(.rodata), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x480 has v0 = ret(pciio_driver_unregister).

- `use_ithread` in `IP35/usr/cpu/sysgen/IP35boot/ioc4_ei.o` at 0x488 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc4_ei.o`.
  Range: 0x488-0x4b4 (44 bytes).
  It occupies 44 bytes.
  The `lw` at 0x488 loads 4 bytes from a0 (arg0 at entry) +0x2c.
  The `lw` at 0x498 loads 4 bytes from abs 0xffffffffffffc6a8.
  The `bne` branch at 0x490 targets 0x4ac, is taken when at(=[a0+44]) != v0(=-0x1), and falls through when at(=[a0+44]) == v0(=-0x1).
  The `beq` branch at 0x4a0 targets 0x4ac, is taken when (v1(=[-0x3958]) & 0x8) == 0, and falls through when (v1(=[-0x3958]) & 0x8) != 0.
  The return at 0x4ac has v0 = one of 0x0, 0x1.

- `ioc4_eiattach` in `IP35/usr/cpu/sysgen/IP35boot/ioc4_ei.o` at 0x4b4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc4_ei.o`.
  Range: 0x4b4-0x658 (420 bytes).
  It occupies 420 bytes.
  The `sw` at 0x510 stores 4 bytes to ret(kmem_zalloc) +0x0.
  The `sd` at 0x514 stores 8 bytes to ret(kmem_zalloc) +0x8.
  The `sd` at 0x528 stores 8 bytes to ret(kmem_zalloc) +0x30.
  The `sd` at 0x544 stores 8 bytes to ret(kmem_zalloc) +0x20.
  The `sw` at 0x55c stores 4 bytes to ret(ioc4_mem_ptr) +0x34.
  2 such `sw` accesses store 4 bytes to ret(ioc4_mem_ptr) +0x30, including `sw` at 0x564, `sw` at 0x56c.
  The `sw` at 0x580 stores 4 bytes to ret(ioc4_mem_ptr) +0xc.
  The `sw` at 0x584 stores 4 bytes to ret(ioc4_mem_ptr) +0x28.
  The `sw` at 0x590 stores 4 bytes to ret(kmem_zalloc) +0x2c.
  The `sw` at 0x5ac stores 4 bytes to ret(kmem_zalloc) +0x4.
  The `sw` at 0x620 stores 4 bytes to ret(kmem_zalloc) +0x10.
  The `jal` at 0x4c4 calls ioc4_subdev_enabled with a0=a0 at entry (arg0), a1=0x6, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x4e0 calls hwgraph_traverse with a0=a0 at entry (arg0), a1=sym(.rodata), a2=sp-48, a3=?.
  The `jal` at 0x4e8 calls hwgraph_fastinfo_get with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x4f8 calls ioc4_mem_ptr with a0=ret(hwgraph_fastinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0x508 calls kmem_zalloc with a0=0x38, a1=0x1, a2=?, a3=?.
  The `jal` at 0x52c calls spinlock_init with a0=ret(kmem_zalloc)+20, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x53c calls kvpalloc with a0=0x1, a1=0x80000, a2=0x0, a3=?.
  The `jal` at 0x594 calls hwgraph_char_device_add with a0=a0 at entry (arg0), a1=sym(.rodata), a2=sym(.rodata), a3=sp-44, a4=-0x1, a5=0xffffffffff800000, a6=0xff00, a7=0x200.
  The `jal` at 0x5a0 calls hwgraph_chmod with a0=?, a1=0x124, a2=?, a3=?.
  The `jal` at 0x5b4 calls hwgraph_fastinfo_set with a0=?, a1=ret(kmem_zalloc), a2=?, a3=?.
  The `jal` at 0x5d0 calls device_inventory_add with a0=?, a1=0xe, a2=0x2, a3=0x0, a4=0x0, a5=0x0.
  The `jal` at 0x5d8 calls ioc4_is_console with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x5e8 calls device_controller_num_set with a0=?, a1=0x1, a2=?, a3=?.
  The `jal` at 0x5f0 calls ei_make_hwgraph_nodes with a0=ret(kmem_zalloc), a1=?, a2=?, a3=?.
  The `jal` at 0x618 calls ioc4_intr_connect with a0=a0 at entry (arg0), a1=0x1, a2=0x2800000, a3=sym(ioc4_ei_intr), a4=ret(kmem_zalloc), a7=sym(use_ithread).
  The `jal` at 0x648 calls device_controller_num_set with a0=?, a1=-0x1, a2=?, a3=?.
  The `beq` branch at 0x4cc targets 0x640, is taken when v0(=ret(ioc4_subdev_enabled)) == 0, and falls through when v0(=ret(ioc4_subdev_enabled)) != 0.
  The `bne` branch at 0x548 targets 0x558, is taken when v0(=ret(kvpalloc)) != 0, and falls through when v0(=ret(kvpalloc)) == 0.
  The `beq` branch at 0x550 targets 0x628 and is always taken.
  The `beq` branch at 0x5e0 targets 0x648, is taken when v0(=ret(ioc4_is_console)) == 0, and falls through when v0(=ret(ioc4_is_console)) != 0.
  The `beq` branch at 0x640 targets 0x628 and is always taken.
  The `beq` branch at 0x650 targets 0x5fc and is always taken.
  The return at 0x638 has v0 = one of -0x1, 0x0.

- `ioc4_eiopen` in `IP35/usr/cpu/sysgen/IP35boot/ioc4_ei.o` at 0x658 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc4_ei.o`.
  Range: 0x658-0x6b8 (96 bytes).
  It occupies 96 bytes.
  The `lw` at 0x658 loads 4 bytes from a0 (arg0 at entry) +0x0.
  The `ld` at 0x698 loads 8 bytes from ret(hwgraph_fastinfo_get) +0x8.
  The `sw` at 0x6a0 stores 4 bytes to [ret(hwgraph_fastinfo_get)+8]:8 +0x30.
  The `jal` at 0x670 calls hwgraph_fastinfo_get with a0=[a0], a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=[a0].
  The `jal` at 0x67c calls find_pstate with a0=ret(hwgraph_fastinfo_get), a1=?, a2=?, a3=?.
  The `beq` branch at 0x668 targets 0x6b0, is taken when a3(=[a0]) == at(=-0x1), and falls through when a3(=[a0]) != at(=-0x1).
  The `bne` branch at 0x684 targets 0x694, is taken when v0(=ret(find_pstate)) != 0, and falls through when v0(=ret(find_pstate)) == 0.
  The `beq` branch at 0x68c targets 0x6a8 and is always taken.
  The `beq` branch at 0x6b0 targets 0x6a8 and is always taken.
  The return at 0x6a8 has v0 = one of 0x0, 0xc, 0x13.

- `ioc4_eiclose` in `IP35/usr/cpu/sysgen/IP35boot/ioc4_ei.o` at 0x6b8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc4_ei.o`.
  Range: 0x6b8-0x730 (120 bytes).
  It occupies 120 bytes.
  The `ld` at 0x6e0 loads 8 bytes from ret(hwgraph_fastinfo_get) +0x30.
  The `ld` at 0x6ec loads 8 bytes from ret(hwgraph_fastinfo_get) +0x8.
  The `lw` at 0x708 loads 4 bytes from ret(hwgraph_fastinfo_get) +0x10.
  The `sw` at 0x714 stores 4 bytes to ret(hwgraph_fastinfo_get) +0x10.
  The `sw` at 0x718 stores 4 bytes to [ret(hwgraph_fastinfo_get)+8]:8 +0x28.
  The `sw` at 0x724 stores 4 bytes to ret(hwgraph_fastinfo_get) +0x2c.
  The `jal` at 0x6d4 calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x6f4 calls ioc4_write_ireg with a0=[ret(hwgraph_fastinfo_get)+48]:8, a1=0x2800000, a2=0x1, a3=0x1.
  The `bne` branch at 0x6c4 targets 0x6d4, is taken when at(=-0x1) != a0, and falls through when at(=-0x1) == a0.
  The `beq` branch at 0x6cc targets 0x728 and is always taken.
  The return at 0x728 has v0 = one of 0x0, 0x13.

- `ei_uli_teardown` in `IP35/usr/cpu/sysgen/IP35boot/ioc4_ei.o` at 0x730 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc4_ei.o`.
  Range: 0x730-0x740 (16 bytes).
  It occupies 16 bytes.
  The `ld` at 0x730 loads 8 bytes from a0 (arg0 at entry) +0xd0.
  The `sw` at 0x73c stores 4 bytes to [a0+208]:8 +0x2c.
  The return at 0x738 has v0 = [a0+208]:8.

- `register_uli` in `IP35/usr/cpu/sysgen/IP35boot/ioc4_ei.o` at 0x740 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc4_ei.o`.
  Range: 0x740-0x890 (336 bytes).
  It occupies 336 bytes.
  The `lw` at 0x7a4 loads 4 bytes from a0 (arg0 at entry) +0x2c.
  5 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x2c, including `sw` at 0x7c8, `sw` at 0x808, `sw` at 0x818.
  The `ld` at 0x7d8 loads 8 bytes from a0 (arg0 at entry) +0x30.
  2 such `sd` accesses store 8 bytes to ?, including `sd` at 0x824, `sd` at 0x82c.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0x834, `lw` at 0x880.
  The `jal` at 0x754 calls get_current_abi with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x774 calls copyin_xlate with a0=a1 at entry (arg1), a1=sp-96, a2=0x28, a3=sym(irix5_to_uliargs), a4=ret(get_current_abi), a5=0x4, a6=0x1.
  The `jal` at 0x79c calls mutex_spinlock with a0=a0+20, a1=?, a2=?, a3=?.
  The `jal` at 0x7b4 calls mutex_spinunlock with a0=?, a1=ret(mutex_spinlock), a2=?, a3=?.
  The `jal` at 0x7cc calls mutex_spinunlock with a0=?, a1=ret(mutex_spinlock), a2=?, a3=?.
  The `jal` at 0x7d4 calls ioc4_intr_cpu_get with a0=[a0+48]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x7e0 calls cpu_isvalid with a0=ret(ioc4_intr_cpu_get), a1=?, a2=?, a3=?.
  The `jal` at 0x7f4 calls new_uli with a0=sp-96, a1=sp-56, a2=?, a3=?.
  The `jal` at 0x838 calls get_current_abi with a0=?, a1=?, a2=-0x1, a3=?, a6=sym(ei_uli_teardown).
  The `jal` at 0x858 calls xlate_copyout with a0=sp-96, a1=a1 at entry (arg1), a2=0x28, a3=sym(uliargs_to_irix5), a4=ret(get_current_abi), a5=0x4, a6=0x1.
  The `jal` at 0x868 calls free_uli with a0=?, a1=?, a2=?, a3=?.
  The `beq` branch at 0x77c targets 0x798, is taken when v0(=ret(copyin_xlate)) == 0, and falls through when v0(=ret(copyin_xlate)) != 0.
  The `beq` branch at 0x7ac targets 0x7c4, is taken when at(=[a0+44]) == v1(=-0x1), and falls through when at(=[a0+44]) != v1(=-0x1).
  The `beq` branch at 0x7bc targets 0x784 and is always taken.
  The `beq` branch at 0x7e8 targets 0x80c, is taken when v0(=ret(cpu_isvalid)) == 0, and falls through when v0(=ret(cpu_isvalid)) != 0.
  The `beq` branch at 0x7fc targets 0x81c, is taken when v0(=ret(new_uli)) == 0, and falls through when v0(=ret(new_uli)) != 0.
  The `beq` branch at 0x804 targets 0x784 and is always taken.
  The `beq` branch at 0x814 targets 0x784 and is always taken.
  The `beq` branch at 0x860 targets 0x880, is taken when v0(=ret(xlate_copyout)) == 0, and falls through when v0(=ret(xlate_copyout)) != 0.
  The `beq` branch at 0x878 targets 0x784 and is always taken.
  The `beq` branch at 0x888 targets 0x784 and is always taken.
  The return at 0x790 has v0 = one of 0xe, 0x10, ret(new_uli), 0x16, 0x0.

- `set_output_mode` in `IP35/usr/cpu/sysgen/IP35boot/ioc4_ei.o` at 0x890 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc4_ei.o`.
  Range: 0x890-0x8ec (92 bytes).
  It occupies 92 bytes.
  The `ld` at 0x8b4 loads 8 bytes from a0 (arg0 at entry) +0x8.
  The `lw` at 0x8bc loads 4 bytes from [a0+8]:8 +0x28.
  The `sw` at 0x8d8 stores 4 bytes to [a0+8]:8 +0x28.
  The `jal` at 0x8a8 calls mutex_spinlock with a0=a0+20, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x8d4 calls mutex_spinunlock with a0=a0+20, a1=ret(mutex_spinlock), a2=?, a3=?.
  The return at 0x8e4 has v0 = ret(mutex_spinunlock).

- `ioc4_eiioctl` in `IP35/usr/cpu/sysgen/IP35boot/ioc4_ei.o` at 0x8ec (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc4_ei.o`.
  Range: 0x8ec-0xdd8 (1260 bytes).
  It occupies 1260 bytes.
  The `ld` at 0x948 loads 8 bytes from (sym(.rodata) + (a1-25857 << 0x3)) +0x0.
  The `jal` at 0x910 calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x91c calls find_pstate with a0=ret(hwgraph_fastinfo_get), a1=?, a2=?, a3=?.
  Calls (unknown callee) via register with a0=a2 at entry (arg2), a1=(a1-25857 << 0x3), a2=[(sym(.rodata) + (a1-25857 << 0x3))]:8, a3=? (`jr` at 0x94c).
  The `beq` branch at 0x908 targets 0x974, is taken when at(=-0x1) == a0, and falls through when at(=-0x1) != a0.
  The `beq` branch at 0x940 targets 0x954, is taken when a1(=a1-25857) >= 0x19 (unsigned), and falls through when a1(=a1-25857) < 0x19 (unsigned).
  The `beq` branch at 0x974 targets 0x958 and is always taken.
  The return at 0x96c has v0 = one of 0x13, 0x16.
  The instructions from 0x97c to 0xdd4 are not reached by any path from the entry, and their branches are not listed.
  The indirect jump at 0x94c uses a jump table whose successors are unresolved.

- `ioc4_eimap` in `IP35/usr/cpu/sysgen/IP35boot/ioc4_ei.o` at 0xdd8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc4_ei.o`.
  Range: 0xdd8-0xe6c (148 bytes).
  It occupies 148 bytes.
  The `ld` at 0xe58 loads 8 bytes from ret(hwgraph_fastinfo_get) +0x20.
  The `jal` at 0xe00 calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a7=0x13.
  The `jal` at 0xe5c calls v_mapphys with a0=a1 at entry (arg1), a1=[ret(hwgraph_fastinfo_get)+32]:8, a2=a3 at entry (arg3), a3=?, a7=0xd.
  The `beq` branch at 0xdf8 targets 0xe18, is taken when a0 == at(=-0x1), and falls through when a0 != at(=-0x1).
  The `beq` branch at 0xe10 targets 0xe2c, is taken when s0(=a3) == v1(=0x4000), and falls through when s0(=a3) != v1(=0x4000).
  The `bne` branch at 0xe2c targets 0xe4c, is taken when a0(=a2) != 0, and falls through when a0(=a2) == 0.
  The `beq` branch at 0xe3c targets 0xe54, is taken when (a1(=a4) & 0x2) == 0, and falls through when (a1(=a4) & 0x2) != 0.
  The `beq` branch at 0xe44 targets 0xe1c and is always taken.
  The `beq` branch at 0xe4c targets 0xe1c and is always taken.
  The `beq` branch at 0xe64 targets 0xe18 and is always taken.
  The return at 0xe24 has v0 = one of ?, 0xd, 0x16.

- `ioc4_eiunmap` in `IP35/usr/cpu/sysgen/IP35boot/ioc4_ei.o` at 0xe6c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc4_ei.o`.
  Range: 0xe6c-0xe74 (8 bytes).
  It occupies 8 bytes.
  The return at 0xe6c has v0 = 0x0.

- `irix5_to_ioc4_eiargs_xlate` in `IP35/usr/cpu/sysgen/IP35boot/ioc4_ei.o` at 0xe74 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc4_ei.o`.
  Range: 0xe74-0xeec (120 bytes).
  It occupies 120 bytes.
  The `lw` at 0xe88 loads 4 bytes from a3 (arg3 at entry) +0x0.
  The `ld` at 0xe98 loads 8 bytes from a3 (arg3 at entry) +0x8.
  2 such `sd` accesses store 8 bytes to a3 (arg3 at entry) +0x10, including `sd` at 0xe9c, `sd` at 0xee8.
  The `sw` at 0xea4 stores 4 bytes to a3 (arg3 at entry) +0x4.
  The `ld` at 0xeb0 loads 8 bytes from a3 (arg3 at entry) +0x10.
  The `lw` at 0xeb4 loads 4 bytes from [a3+16]:8 +0x0.
  The `sw` at 0xeb8 stores 4 bytes to a1 (arg1 at entry) +0x0.
  The `lw` at 0xebc loads 4 bytes from [a3+16]:8 +0x4.
  The `sw` at 0xec0 stores 4 bytes to a1 (arg1 at entry) +0xc.
  The `lw` at 0xec4 loads 4 bytes from [a3+16]:8 +0x8.
  The `sd` at 0xec8 stores 8 bytes to a1 (arg1 at entry) +0x10.
  The `jal` at 0xed8 calls kern_malloc with a0=0xc, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `bne` branch at 0xe80 targets 0xeb0, is taken when a0 != 0, and falls through when a0 == 0.
  The `bne` branch at 0xe90 targets 0xed8, is taken when at(=[a3]) < 0xc (unsigned), and falls through when at(=[a3]) >= 0xc (unsigned).
  The `beq` branch at 0xea8 targets 0xecc and is always taken.
  The `beq` branch at 0xee4 targets 0xea0 and is always taken.
  The return at 0xed0 has v0 = 0x0.

- `ioc4_eiargs_to_irix5_xlate` in `IP35/usr/cpu/sysgen/IP35boot/ioc4_ei.o` at 0xeec (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc4_ei.o`.
  Range: 0xeec-0xf64 (120 bytes).
  It occupies 120 bytes.
  The `lw` at 0xeec loads 4 bytes from a2 (arg2 at entry) +0x0.
  The `ld` at 0xf10 loads 8 bytes from a2 (arg2 at entry) +0x8.
  2 such `sd` accesses store 8 bytes to a2 (arg2 at entry) +0x10, including `sd` at 0xf14, `sd` at 0xf60.
  The `sw` at 0xf1c stores 4 bytes to a2 (arg2 at entry) +0x4.
  The `lw` at 0xf24 loads 4 bytes from a0 (arg0 at entry) +0x0.
  3 such `sw` accesses store 4 bytes to ?, including `sw` at 0xf28, `sw` at 0xf30, `sw` at 0xf40.
  The `lw` at 0xf2c loads 4 bytes from a0 (arg0 at entry) +0xc.
  The `ld` at 0xf34 loads 8 bytes from a0 (arg0 at entry) +0x10.
  The `jal` at 0xf4c calls kern_malloc with a0=0xc, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `bne` branch at 0xf08 targets 0xf4c, is taken when at(=[a2]) < 0xc (unsigned), and falls through when at(=[a2]) >= 0xc (unsigned).
  The `beq` branch at 0xf5c targets 0xf18 and is always taken.
  The return at 0xf44 has v0 = 0x0.
