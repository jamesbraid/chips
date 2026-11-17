# Readings: `IP35/usr/cpu/sysgen/IP35boot/ioc4.o`

One entry per routine, filed here from the reading batches by binary.

- `ioc4_intr_cpu_get` in `IP35/usr/cpu/sysgen/IP35boot/ioc4.o` at 0x0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc4.o`.
  Range: 0x0-0x8 (8 bytes).
  It occupies 8 bytes.
  The `lh` at 0x4 loads 2 bytes from a0 (arg0 at entry) +0x20.
  The return at 0x0 has v0 = [a0+32]:2.

- `ioc4_mlreset` in `IP35/usr/cpu/sysgen/IP35boot/ioc4.o` at 0x8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc4.o`.
  Range: 0x8-0x94 (140 bytes).
  It occupies 140 bytes.
  The `ld` at 0x2c loads 8 bytes from (([sym(master_nasid)]:2 << 0x21)+0x9600000000000000 | 0x2000) +0x48.
  3 such `lw` accesses load 4 bytes from ?, including `lw` at 0x3c, `lw` at 0x4c, `lw` at 0x68.
  The `ld` at 0x44 loads 8 bytes from ?.
  The `jal` at 0x84 calls ioc4_sio_mlreset with a0=a0 at entry (arg0), a1=?, a2=a2 at entry (arg2), a3=?, a4=0x300fafa, a5=0x300fafb, a6=0x3000000.
  The `bne` branch at 0x60 targets 0x7c, is taken when at(?) != v0(=0x100a10a9), and falls through when at(?) == v0(=0x100a10a9).
  The `beq` branch at 0x6c targets 0x7c, is taken when a1(?) == a4(=0x300fafa), and falls through when a1(?) != a4(=0x300fafa).
  The `bne` branch at 0x74 targets 0x84, is taken when a1(?) != a5(=0x300fafb), and falls through when a1(?) == a5(=0x300fafb).
  The `beq` branch at 0x8c targets 0x7c and is always taken.
  The return at 0x7c has v0 = one of 0x100a10a9, ret(ioc4_sio_mlreset).

- `ioc4_write_ireg` in `IP35/usr/cpu/sysgen/IP35boot/ioc4.o` at 0x94 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc4.o`.
  Range: 0x94-0x14c (184 bytes).
  It occupies 184 bytes.
  The `ld` at 0xa8 loads 8 bytes from a0 (arg0 at entry) +0x10.
  The `sw` at 0x130 stores 4 bytes to [a0+16]:8 +0x18.
  The `sw` at 0x138 stores 4 bytes to [a0+16]:8 +0x1c.
  The `sw` at 0x140 stores 4 bytes to [a0+16]:8 +0x14.
  The `sw` at 0x148 stores 4 bytes to [a0+16]:8 +0x10.
  The `jal` at 0xc8 calls mutex_spinlock_spl with a0=a0+5704, a1=sym(spl7), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x104 calls mutex_spinunlock with a0=a0+5704, a1=ret(mutex_spinlock_spl), a2=?, a3=?.
  The `beq` branch at 0xd4 targets 0x11c, is taken when s0(=a3) == 0, and falls through when s0(=a3) != 0.
  The `bne` branch at 0xdc targets 0xf4, is taken when s0(=a3) != a0(=0x1), and falls through when s0(=a3) == a0(=0x1).
  The `beq` branch at 0xe4 targets 0x13c, is taken when s1(=a2) == 0, and falls through when s1(=a2) != 0.
  The `beq` branch at 0xec targets 0x134, is taken when s1(=a2) == a0(=0x1), and falls through when s1(=a2) != a0(=0x1).
  The `beq` branch at 0x11c targets 0x144, is taken when s1(=a2) == 0, and falls through when s1(=a2) != 0.
  The `bne` branch at 0x124 targets 0xf4, is taken when s1(=a2) != at(=0x1), and falls through when s1(=a2) == at(=0x1).
  The `beq` branch at 0x12c targets 0xf4 and is always taken.
  The `beq` branch at 0x134 targets 0xf4 and is always taken.
  The `beq` branch at 0x13c targets 0xf4 and is always taken.
  The `beq` branch at 0x144 targets 0xf4 and is always taken.
  The return at 0x114 has v0 = ret(mutex_spinunlock).

- `ioc4_pending_intrs` in `IP35/usr/cpu/sysgen/IP35boot/ioc4.o` at 0x14c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc4.o`.
  Range: 0x14c-0x1dc (144 bytes).
  It occupies 144 bytes.
  The `ld` at 0x14c loads 8 bytes from a0 (arg0 at entry) +0x10.
  The `lw` at 0x1b0 loads 4 bytes from [a0+16]:8 +0x8.
  The `lw` at 0x1b4 loads 4 bytes from [a0+16]:8 +0x10.
  The `lw` at 0x1c4 loads 4 bytes from [a0+16]:8 +0xc.
  The `lw` at 0x1c8 loads 4 bytes from [a0+16]:8 +0x14.
  The `jal` at 0x170 calls mutex_spinlock_spl with a0=a0+5704, a1=sym(spl7), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x18c calls mutex_spinunlock with a0=a0+5704, a1=ret(mutex_spinlock_spl), a2=?, a3=?.
  The `beq` branch at 0x17c targets 0x1ac, is taken when s0(=a1) == 0, and falls through when s0(=a1) != 0.
  The `beq` branch at 0x184 targets 0x1c0, is taken when s0(=a1) == a0(=0x1), and falls through when s0(=a1) != a0(=0x1).
  The `beq` branch at 0x1b8 targets 0x18c and is always taken.
  The `beq` branch at 0x1d4 targets 0x18c and is always taken.
  The return at 0x1a4 has v0 = ?.

- `ioc4_init` in `IP35/usr/cpu/sysgen/IP35boot/ioc4.o` at 0x1dc (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc4.o`.
  Range: 0x1dc-0x204 (40 bytes).
  It occupies 40 bytes.
  The `jal` at 0x1f0 calls pciio_driver_register with a0=0x10a9, a1=0x100a, a2=sym(.rodata), a3=0x1.
  The return at 0x1fc has v0 = ret(pciio_driver_register).

- `ioc4_intr_connect` in `IP35/usr/cpu/sysgen/IP35boot/ioc4.o` at 0x604 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc4.o`.
  Range: 0x604-0x8a4 (672 bytes).
  It occupies 672 bytes.
  The `lw` at 0x68c loads 4 bytes from ?.
  4 such `ll` accesses load 4 bytes from ?, including `ll` at 0x6a4, `ll` at 0x740, `ll` at 0x7cc.
  4 such `sc` accesses store 4 bytes to ?, including `sc` at 0x6ac, `sc` at 0x748, `sc` at 0x7d4.
  4 such `sd` accesses store 8 bytes to ?, including `sd` at 0x724, `sd` at 0x728, `sd` at 0x730.
  2 such `sw` accesses store 4 bytes to ?, including `sw` at 0x72c, `sw` at 0x73c.
  The `jal` at 0x638 calls hwgraph_traverse with a0=a0 at entry (arg0), a1=sym(.rodata), a2=sp-144, a3=a3 at entry (arg3).
  The `jal` at 0x64c calls hwgraph_fastinfo_get with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x760 calls device_desc_dup with a0=a6 at entry (arg6), a1=?, a2=?, a3=?.
  The `jal` at 0x768 calls device_desc_intr_swlevel_get with a0=ret(device_desc_dup), a1=?, a2=?, a3=?.
  The `jal` at 0x77c calls device_driver_getbydev with a0=a6 at entry (arg6), a1=?, a2=?, a3=?.
  The `jal` at 0x794 calls device_driver_name_get with a0=ret(device_driver_getbydev), a1=sp-136, a2=0x10, a3=?.
  The `jal` at 0x7a8 calls sprintf with a0=sp-120, a1=sym(.rodata), a2=?, a3=sp-136.
  The `jal` at 0x7e0 calls xthread_setup with a0=sp-120, a1=?, a2=?, a3=sym(ioc4_intrd_setup).
  The `jal` at 0x830 calls sprintf with a0=sp-120, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x86c calls cmn_err with a0=0x1, a1=sym(.rodata), a2=a5 at entry (arg5), a3=?.
  The `jal` at 0x888 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=a5 at entry (arg5), a3=?, a5=a3 at entry (arg3).
  The `jal` at 0x894 calls panic with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `bne` branch at 0x640 targets 0x860, is taken when v0(=ret(hwgraph_traverse)) != 0, and falls through when v0(=ret(hwgraph_traverse)) == 0.
  The `beq` branch at 0x694 targets 0x800, is taken when t3(?) == 0, and falls through when t3(?) != 0.
  The `beql` branch at 0x6b0 targets 0x6a4, is taken when (ra(?) & at(?)) == 0, and falls through when (ra(?) & at(?)) != 0; its branch-likely delay slot `nop` at 0x6b4 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x6bc targets 0x68c, is taken when (ra(?) & a1(?)) == 0, and falls through when (ra(?) & a1(?)) != 0.
  The `beq` branch at 0x6c4 targets 0x6d4, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0x6d8 targets 0x848, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0x6e8 targets 0x850, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0x6f8 targets 0x858, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0x708 targets 0x840, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beql` branch at 0x74c targets 0x740, is taken when a7(?) == 0, and falls through when a7(?) != 0; its branch-likely delay slot `nop` at 0x750 runs only when taken and is annulled on fall-through.
  The `bne` branch at 0x758 targets 0x87c, is taken when (a3(?) & a0(=a2)) != 0, and falls through when (a3(?) & a0(=a2)) == 0.
  The `beq` branch at 0x784 targets 0x828, is taken when v0(=ret(device_driver_getbydev)) == 0, and falls through when v0(=ret(device_driver_getbydev)) != 0.
  The `beql` branch at 0x7d8 targets 0x7cc, is taken when t8(?) == 0, and falls through when t8(?) != 0; its branch-likely delay slot `nop` at 0x7dc runs only when taken and is annulled on fall-through.
  The `beql` branch at 0x818 targets 0x808, is taken when at(=table(0x1)) == 0, and falls through when at(=table(0x1)) != 0; its branch-likely delay slot `nop` at 0x81c runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x820 targets 0x70c and is always taken.
  The `beq` branch at 0x838 targets 0x7b4 and is always taken.
  The `beq` branch at 0x840 targets 0x70c and is always taken.
  The `beq` branch at 0x848 targets 0x6e4 and is always taken.
  The `beq` branch at 0x850 targets 0x6f4 and is always taken.
  The `beq` branch at 0x858 targets 0x704 and is always taken.
  The `beq` branch at 0x874 targets 0x7ec and is always taken.
  The `beq` branch at 0x89c targets 0x760 and is always taken.
  The return at 0x7f8 has v0 = one of ret(xthread_setup), ret(cmn_err).

- `ioc4_intr_disconnect` in `IP35/usr/cpu/sysgen/IP35boot/ioc4.o` at 0x8a4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc4.o`.
  Range: 0x8a4-0xa2c (392 bytes).
  It occupies 392 bytes.
  4 such `lw` accesses load 4 bytes from ?, including `lw` at 0x910, `lw` at 0x970, `lw` at 0x97c.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0x958, `ld` at 0x964.
  3 such `ll` accesses load 4 bytes from ?, including `ll` at 0x990, `ll` at 0x9a4, `ll` at 0x9f8.
  3 such `sc` accesses store 4 bytes to ?, including `sc` at 0x998, `sc` at 0x9ac, `sc` at 0xa00.
  The `sw` at 0x9e8 stores 4 bytes to ?.
  2 such `sd` accesses store 8 bytes to ?, including `sd` at 0x9ec, `sd` at 0x9f4.
  The `jal` at 0x8d4 calls hwgraph_traverse with a0=a0 at entry (arg0), a1=sym(.rodata), a2=sp-64, a3=a3 at entry (arg3).
  The `jal` at 0x8e4 calls hwgraph_fastinfo_get with a0=?, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0xa1c calls cmn_err with a0=0x1, a1=sym(.rodata), a2=a5 at entry (arg5), a3=?.
  The `bne` branch at 0x8dc targets 0xa14, is taken when v0(=ret(hwgraph_traverse)) != 0, and falls through when v0(=ret(hwgraph_traverse)) == 0.
  The `blez` branch at 0x920 targets 0x9d0, is taken when t0(?) <= 0 (signed), and falls through when t0(?) > 0 (signed).
  The `beq` branch at 0x928 targets 0x940 and is always taken.
  The `beq` branch at 0x938 targets 0x9d4, is taken when a1(?) >= t0(?) (signed), and falls through when a1(?) < t0(?) (signed).
  The `bne` branch at 0x95c targets 0x930, is taken when t9(?) != s0(=a3), and falls through when t9(?) == s0(=a3).
  The `bne` branch at 0x968 targets 0x930, is taken when t8(?) != s1(=a4), and falls through when t8(?) == s1(=a4).
  The `bne` branch at 0x974 targets 0x930, is taken when t9(?) != s2(=a5), and falls through when t9(?) == s2(=a5).
  The `beq` branch at 0x984 targets 0x930, is taken when (a3(?) & a4(=a2)) == 0, and falls through when (a3(?) & a4(=a2)) != 0.
  The `beql` branch at 0x99c targets 0x990, is taken when (v0(?) & ra(?)) == 0, and falls through when (v0(?) & ra(?)) != 0; its branch-likely delay slot `nop` at 0x9a0 runs only when taken and is annulled on fall-through.
  The `beql` branch at 0x9b0 targets 0x9a4, is taken when (t9(?) & ra(?)) == 0, and falls through when (t9(?) & ra(?)) != 0; its branch-likely delay slot `nop` at 0x9b4 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x9c0 targets 0x9e8, is taken when t8(?) == 0, and falls through when t8(?) != 0.
  The `bne` branch at 0x9c8 targets 0x940, is taken when a4(?) != 0, and falls through when a4(?) == 0.
  The `beql` branch at 0xa04 targets 0x9f8, is taken when t9(?) == 0, and falls through when t9(?) != 0; its branch-likely delay slot `nop` at 0xa08 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0xa0c targets 0x9c8 and is always taken.
  The `beq` branch at 0xa24 targets 0x9d4 and is always taken.
  The return at 0x9e0 has v0 = one of ?, ret(cmn_err).

- `ioc4_intr` in `IP35/usr/cpu/sysgen/IP35boot/ioc4.o` at 0xa2c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc4.o`.
  Range: 0xa2c-0xbe8 (444 bytes).
  It occupies 444 bytes.
  4 such `lw` accesses load 4 bytes from ?, including `lw` at 0xa9c, `lw` at 0xab4, `lw` at 0xb00.
  4 such `ld` accesses load 8 bytes from ?, including `ld` at 0xb20, `ld` at 0xb30, `ld` at 0xb3c.
  The `ld` at 0xb64 loads 8 bytes from abs 0xffffffffffffc510.
  The `ll` at 0xb70 loads 4 bytes from [-0x3af0]:8 +0xd0.
  The `sc` at 0xb7c stores 4 bytes to [-0x3af0]:8 +0xd0.
  The `jal` at 0xa98 calls ioc4_pending_intrs with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xac0 calls ioc4_write_ireg with a0=?, a1=?, a2=0x1, a3=?.
  The `jal` at 0xac8 calls vsema with a0=?, a1=?, a2=?, a3=?.
  The `jalr` at 0xb2c calls (unknown callee) with a0=?, a1=?, a2=?, a3=?.
  The `jalr` at 0xb44 calls (unknown callee) with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xbd8 calls cmn_err with a0=0x1, a1=sym(.rodata), a2=?, a3=?.
  The `beq` branch at 0xa64 targets 0xba0, is taken when s6(?) == 0, and falls through when s6(?) != 0.
  The `blez` branch at 0xaa0 targets 0xb64, is taken when s7(?) <= 0 (signed), and falls through when s7(?) > 0 (signed).
  The `beq` branch at 0xaac targets 0xaec and is always taken.
  The `beq` branch at 0xae0 targets 0xb64, is taken when s1(?) >= s7(?) (signed), and falls through when s1(?) < s7(?) (signed).
  The `beq` branch at 0xb08 targets 0xb54, is taken when (a1(?) & s2(?)) == 0, and falls through when (a1(?) & s2(?)) != 0.
  The `beq` branch at 0xb18 targets 0xb3c, is taken when (t8(?) & 0x1000) == 0, and falls through when (t8(?) & 0x1000) != 0.
  The `beq` branch at 0xb24 targets 0xabc, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `bne` branch at 0xb34 targets 0xab4, is taken when v0(=ret(?)) != 0, and falls through when v0(=ret(?)) == 0.
  The `beq` branch at 0xb4c targets 0xad4 and is always taken.
  The `bne` branch at 0xb5c targets 0xaec, is taken when s1(?) < s7(?) (signed), and falls through when s1(?) >= s7(?) (signed).
  The `beql` branch at 0xb80 targets 0xb70, is taken when a0(?) == 0, and falls through when a0(?) != 0; its branch-likely delay slot `nop` at 0xb84 runs only when taken and is annulled on fall-through.
  The `bne` branch at 0xb88 targets 0xbd0, is taken when s2(?) != 0, and falls through when s2(?) == 0.
  The `bne` branch at 0xb98 targets 0xa74, is taken when s3(?) < 0x2 (signed), and falls through when s3(?) >= 0x2 (signed).
  The `beq` branch at 0xbe0 targets 0xb94 and is always taken.
  The return at 0xbc8 has v0 = ?.

- `ioc4_is_console` in `IP35/usr/cpu/sysgen/IP35boot/ioc4.o` at 0xbe8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc4.o`.
  Range: 0xbe8-0xc40 (88 bytes).
  It occupies 88 bytes.
  The `jal` at 0xc08 calls hwgraph_traverse with a0=a0 at entry (arg0), a1=sym(.rodata), a2=sp-16, a3=a3 at entry (arg3).
  The `jal` at 0xc28 calls hwgraph_fastinfo_get with a0=?, a1=?, a2=?, a3=?.
  The `bne` branch at 0xbf0 targets 0xc00, is taken when at(=[sym(.sbss)]:8) != 0, and falls through when at(=[sym(.sbss)]:8) == 0.
  The `beq` branch at 0xbf8 targets 0xc18 and is always taken.
  The `beq` branch at 0xc10 targets 0xc28, is taken when v0(=ret(hwgraph_traverse)) == 0, and falls through when v0(=ret(hwgraph_traverse)) != 0.
  The `beq` branch at 0xc38 targets 0xc18 and is always taken.
  The return at 0xc20 has v0 = one of 0x0, ?.

- `ioc4_error_handler` in `IP35/usr/cpu/sysgen/IP35boot/ioc4.o` at 0xc40 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc4.o`.
  Range: 0xc40-0xf4c (780 bytes).
  It occupies 780 bytes.
  The `ld` at 0xc54 loads 8 bytes from a0 (arg0 at entry) +0x8.
  The `lbu` at 0xc58 loads 1 byte from sym(.rodata) +0x2c4.
  The `lw` at 0xc5c loads 4 bytes from [a0+8]:8 +0x4.
  The `lhu` at 0xc64 loads 2 bytes from sym(.rodata) +0x2b0.
  The `ld` at 0xc74 loads 8 bytes from sym(.rodata) +0x2a8.
  The `lw` at 0xc84 loads 4 bytes from sym(.rodata) +0x2c0.
  The `ld` at 0xc90 loads 8 bytes from sym(.rodata) +0x2b8.
  The `lw` at 0xca4 loads 4 bytes from sym(.rodata) +0x440.
  The `lbu` at 0xca8 loads 1 byte from sym(.rodata) +0x444.
  The `lhu` at 0xcb8 loads 2 bytes from sym(.rodata) +0x2dc.
  The `lw` at 0xcc0 loads 4 bytes from sym(.rodata) +0x2f0.
  The `ld` at 0xccc loads 8 bytes from sym(.rodata) +0x2c8.
  The `lbu` at 0xcd8 loads 1 byte from sym(.rodata) +0x2de.
  The `lw` at 0xcdc loads 4 bytes from sym(.rodata) +0x2d8.
  The `ld` at 0xce0 loads 8 bytes from sym(.rodata) +0x2d0.
  The `ld` at 0xcf4 loads 8 bytes from sym(.rodata) +0x2e0.
  The `ld` at 0xd00 loads 8 bytes from sym(.rodata) +0x2e8.
  The `lhu` at 0xd04 loads 2 bytes from sym(.rodata) +0x2f4.
  The `ld` at 0xd18 loads 8 bytes from sym(.rodata) +0x2f8.
  The `lw` at 0xd20 loads 4 bytes from sym(.rodata) +0x308.
  The `ld` at 0xd24 loads 8 bytes from sym(.rodata) +0x300.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x10, including `ld` at 0xd44, `ld` at 0xde4.
  The `lw` at 0xd48 loads 4 bytes from [a0+16]:8 +0x0.
  The `lw` at 0xd84 loads 4 bytes from [a0+16]:8 +0x4.
  The `ld` at 0xd90 loads 8 bytes from table(sym(.rodata)) +0x0.
  The `lbu` at 0xd98 loads 1 byte from sym(.rodata) +0x3fe.
  The `lbu` at 0xd9c loads 1 byte from sym(.rodata) +0x414.
  The `lw` at 0xda4 loads 4 bytes from sym(.rodata) +0x410.
  The `ld` at 0xdac loads 8 bytes from sym(.rodata) +0x408.
  The `ld` at 0xdb4 loads 8 bytes from sym(.rodata) +0x400.
  The `sw` at 0xdf0 stores 4 bytes to [a0+16]:8 +0x0.
  The `jal` at 0xd3c calls cmn_err with a0=0x5, a1=sym(.rodata), a2=sp-64, a3=one of 0x0, 0x7400.
  The `jal` at 0xddc calls cmn_err with a0=0x5, a1=sym(.rodata), a2=sp-64, a3=?, a4=([[a0+16]:8+4] << 0x20), a5=[[a0+16]:8], a6=[[a0+16]:8+4], a7=0x756e6b6e6f776e20.
  The `beq` branch at 0xc7c targets 0xc98, is taken when (a5(=[[a0+8]:8+4]) & at(=0xffffffff81000000)) == 0, and falls through when (a5(=[[a0+8]:8+4]) & at(=0xffffffff81000000)) != 0.
  The `bgez` branch at 0xc9c targets 0xcb8, is taken when a2(=([[a0+8]:8+4] << 0x21)) >= 0 (signed), and falls through when a2(=([[a0+8]:8+4] << 0x21)) < 0 (signed).
  The `bgez` branch at 0xcc4 targets 0xcf0, is taken when t3(=([[a0+8]:8+4] << 0x24)) >= 0 (signed), and falls through when t3(=([[a0+8]:8+4] << 0x24)) < 0 (signed).
  The `bgez` branch at 0xcf0 targets 0xd10, is taken when a0(=([[a0+8]:8+4] << 0x23)) >= 0 (signed), and falls through when a0(=([[a0+8]:8+4] << 0x23)) < 0 (signed).
  The `bgez` branch at 0xd10 targets 0xd34, is taken when a2(=([[a0+8]:8+4] << 0x22)) >= 0 (signed), and falls through when a2(=([[a0+8]:8+4] << 0x22)) < 0 (signed).
  The `bne` branch at 0xd50 targets 0xd6c, is taken when (a5(=[[a0+16]:8]) & 0x1) != 0, and falls through when (a5(=[[a0+16]:8]) & 0x1) == 0.
  The `beq` branch at 0xd88 targets 0xd9c, is taken when a3(?) >= 0x9 (unsigned), and falls through when a3(?) < 0x9 (unsigned).
  The `beq` branch at 0xdec targets 0xd54 and is always taken.
  The return at 0xd64 has v0 = 0x0.
  The instructions from 0xdf4 to 0xf48 are not reached by any path from the entry, and their branches are not listed.
  The indirect jump at 0xd94 uses a jump table whose successors are unresolved.

- `ioc4_intrd` in `IP35/usr/cpu/sysgen/IP35boot/ioc4.o` at 0xf4c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc4.o`.
  Range: 0xf4c-0xf94 (72 bytes).
  It occupies 72 bytes.
  The `lw` at 0xf4c loads 4 bytes from a0 (arg0 at entry) +0x0.
  The `ld` at 0xf54 loads 8 bytes from a0 (arg0 at entry) +0x20.
  The `ld` at 0xf60 loads 8 bytes from [a0+32]:8 +0x10.
  The `ld` at 0xf64 loads 8 bytes from a0 (arg0 at entry) +0x8.
  The `lw` at 0xf68 loads 4 bytes from [[a0+32]:8+16]:8 +0x8.
  The `ld` at 0xf6c loads 8 bytes from a0 (arg0 at entry) +0x10.
  The `jalr` at 0xf74 calls (unknown callee) with a0=[a0+16]:8, a1=?, a2=[a0], a3=a3 at entry (arg3).
  The `jal` at 0xf7c calls ipsema with a0=a0+48, a1=?, a2=?, a3=?.
  The return at 0xf8c has v0 = ret(ipsema).

- `ioc4_intrd_setup` in `IP35/usr/cpu/sysgen/IP35boot/ioc4.o` at 0xf94 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc4.o`.
  Range: 0xf94-0x1014 (128 bytes).
  It occupies 128 bytes.
  The `ld` at 0xfa0 loads 8 bytes from a0 (arg0 at entry) +0x20.
  The `lh` at 0xfac loads 2 bytes from [a0+32]:8 +0x22.
  2 such `ld` accesses load 8 bytes from abs 0xffffffffffffc020, including `ld` at 0xfb0, `ld` at 0xfcc.
  The `ld` at 0xfc8 loads 8 bytes from a0 (arg0 at entry) +0x8.
  The `ll` at 0xfe8 loads 4 bytes from a0 (arg0 at entry) +0x28.
  The `sc` at 0xff0 stores 4 bytes to a0 (arg0 at entry) +0x28.
  The `jal` at 0xfa8 calls setmustrun with a0=[[a0+32]:8+34]:2, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xfb8 calls xthread_set_func with a0=[-0x3fe0]:8, a1=sym(ioc4_intrd), a2=a0 at entry (arg0), a3=?.
  The `jal` at 0xfc4 calls fetch_kname with a0=[a0+8]:8, a1=sp-32, a2=?, a3=?.
  The `jal` at 0xfd8 calls strncpy with a0=[-0x3fe0]:8+848, a1=ret(fetch_kname), a2=0x10, a3=?.
  The `jal` at 0xffc calls ipsema with a0=a0+48, a1=[a0+40], a2=a0+40, a3=0x400, a4=([a0+40] | 0x400).
  The `beql` branch at 0xff4 targets 0xfe8, is taken when a4(=([a0+40] | 0x400)) == 0, and falls through when a4(=([a0+40] | 0x400)) != 0; its branch-likely delay slot `nop` at 0xff8 runs only when taken and is annulled on fall-through.
  The return at 0x100c has v0 = ret(ipsema).

- `ioc4_subdev_ptr` in `IP35/usr/cpu/sysgen/IP35boot/ioc4.o` at 0x102c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc4.o`.
  Range: 0x102c-0x10dc (176 bytes).
  It occupies 176 bytes.
  The `sd` at 0x1080 stores 8 bytes to ret(kmem_zalloc) +0x0.
  The `jal` at 0x1050 calls hwgraph_info_get_LBL with a0=a0 at entry (arg0), a1=sym(.rodata), a2=sp-48, a3=a3 at entry (arg3).
  The `jal` at 0x1068 calls kmem_zalloc with a0=0x8, a1=0x0, a2=?, a3=?.
  The `jal` at 0x1088 calls hwgraph_info_add_LBL with a0=a0 at entry (arg0), a1=sym(.rodata), a2=ret(kmem_zalloc), a3=?.
  The `jal` at 0x109c calls hwgraph_info_get_LBL with a0=a0 at entry (arg0), a1=sym(.rodata), a2=sp-48, a3=?.
  The `jal` at 0x10cc calls kmem_free with a0=ret(kmem_zalloc), a1=0x8, a2=?, a3=?.
  The `beq` branch at 0x1058 targets 0x10ac, is taken when s3(=a1) == 0, and falls through when s3(=a1) != 0.
  The `beq` branch at 0x1060 targets 0x10ac, is taken when v0(=ret(hwgraph_info_get_LBL)) == 0, and falls through when v0(=ret(hwgraph_info_get_LBL)) != 0.
  The `bne` branch at 0x10a8 targets 0x10c8, is taken when a3(?) != s1(=ret(kmem_zalloc)), and falls through when a3(?) == s1(=ret(kmem_zalloc)).
  The `beq` branch at 0x10d4 targets 0x10b0 and is always taken.
  The return at 0x10c0 has v0 = ?.

- `ioc4_subdev_enabled` in `IP35/usr/cpu/sysgen/IP35boot/ioc4.o` at 0x10dc (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc4.o`.
  Range: 0x10dc-0x1124 (72 bytes).
  It occupies 72 bytes.
  The `ld` at 0x1104 loads 8 bytes from ret(ioc4_subdev_ptr) +0x0.
  The `jal` at 0x10ec calls ioc4_subdev_ptr with a0=a0 at entry (arg0), a1=0x0, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0x10f8 targets 0x1108, is taken when v0(=ret(ioc4_subdev_ptr)) == 0, and falls through when v0(=ret(ioc4_subdev_ptr)) != 0.
  The `beq` branch at 0x1100 targets 0x110c and is always taken.
  The return at 0x111c has v0 = ?.

- `ioc4_mem_ptr` in `IP35/usr/cpu/sysgen/IP35boot/ioc4.o` at 0x11dc (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc4.o`.
  Range: 0x11dc-0x11e4 (8 bytes).
  It occupies 8 bytes.
  The `ld` at 0x11e0 loads 8 bytes from a0 (arg0 at entry) +0x10.
  The return at 0x11dc has v0 = [a0+16]:8.

- `ioc4_get_mem` in `IP35/usr/cpu/sysgen/IP35boot/ioc4.o` at 0x11e4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc4.o`.
  Range: 0x11e4-0x1204 (32 bytes).
  It occupies 32 bytes.
  The `ld` at 0x11f8 loads 8 bytes from ret(hwgraph_fastinfo_get) +0x10.
  The `jal` at 0x11ec calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x11fc has v0 = [ret(hwgraph_fastinfo_get)+16]:8.
