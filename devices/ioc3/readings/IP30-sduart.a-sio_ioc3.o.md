# Readings: `IP30/usr/cpu/sysgen/IP30boot/sduart.a(sio_ioc3.o)`

One entry per routine, filed here from the reading batches by binary.

- `ioc3_sio_mlreset` in `IP30/usr/cpu/sysgen/IP30boot/sduart.a(sio_ioc3.o)` at 0x0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/sduart.a(sio_ioc3.o)`.
  Range: 0x0-0x2c (44 bytes).
  It occupies 44 bytes.
  The `jal` at 0x18 calls sio_console_register with a0=sp-32, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x24 has v0 = ret(sio_console_register).

- `get_cons_dev` in `IP30/usr/cpu/sysgen/IP30boot/sduart.a(sio_ioc3.o)` at 0x2c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/sduart.a(sio_ioc3.o)`.
  Range: 0x2c-0x40 (20 bytes).
  It occupies 20 bytes.
  The `lw` at 0x3c loads 4 bytes from (sym(.sbss) + (a0 << 0x2)) -0x4.
  The return at 0x38 has v0 = [(sym(.sbss) + (a0 << 0x2))-4].

- `ring_dmatrans` in `IP30/usr/cpu/sysgen/IP30boot/sduart.a(sio_ioc3.o)` at 0x40 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/sduart.a(sio_ioc3.o)`.
  Range: 0x40-0x8c (76 bytes).
  It occupies 76 bytes.
  The `jal` at 0x68 calls pciio_dmatrans_addr with a0=a0 at entry (arg0), a1=0x0, a2=?, a3=0x4000, a4=0x40.
  The `beq` branch at 0x54 targets 0x7c, is taken when a0 == at(=-0x1), and falls through when a0 != at(=-0x1).
  The `beq` branch at 0x74 targets 0x80 and is always taken.
  The return at 0x84 has v0 = one of ret(pciio_dmatrans_addr), ?.

- `mask_disable_intrs` in `IP30/usr/cpu/sysgen/IP30boot/sduart.a(sio_ioc3.o)` at 0x8c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/sduart.a(sio_ioc3.o)`.
  Range: 0x8c-0xa0 (20 bytes).
  It occupies 20 bytes.
  The `lw` at 0x8c loads 4 bytes from a0 (arg0 at entry) +0x90.
  The `sw` at 0x9c stores 4 bytes to a0 (arg0 at entry) +0x90.
  The return at 0x98 has v0 = ?.

- `enable_intrs` in `IP30/usr/cpu/sysgen/IP30boot/sduart.a(sio_ioc3.o)` at 0xa0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/sduart.a(sio_ioc3.o)`.
  Range: 0xa0-0xf0 (80 bytes).
  It occupies 80 bytes.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x90, including `lw` at 0xa0, `lw` at 0xdc.
  The `ld` at 0xc4 loads 8 bytes from a0 (arg0 at entry) +0xa0.
  The `sw` at 0xec stores 4 bytes to a0 (arg0 at entry) +0x90.
  The `jal` at 0xcc calls ioc3_write_ireg with a0=[a0+160]:8, a1=a1 at entry (arg1), a2=0x0, a3=a3 at entry (arg3).
  The `bne` branch at 0xb4 targets 0xc4, is taken when a1 != at(?), and falls through when a1 == at(?).
  The `beq` branch at 0xe8 targets 0xbc and is always taken.
  The return at 0xbc has v0 = one of ?, ret(ioc3_write_ireg).

- `disable_intrs` in `IP30/usr/cpu/sysgen/IP30boot/sduart.a(sio_ioc3.o)` at 0xf0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/sduart.a(sio_ioc3.o)`.
  Range: 0xf0-0x144 (84 bytes).
  It occupies 84 bytes.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x90, including `lw` at 0xf0, `lw` at 0x120.
  The `ld` at 0x11c loads 8 bytes from a0 (arg0 at entry) +0xa0.
  The `sw` at 0x130 stores 4 bytes to a0 (arg0 at entry) +0x90.
  The `jal` at 0x118 calls ioc3_write_ireg with a0=[a0+160]:8, a1=a1 at entry (arg1), a2=0x1, a3=a3 at entry (arg3).
  The `beq` branch at 0x10c targets 0x134, is taken when (at(=[a0+144]) & a1) == 0, and falls through when (at(=[a0+144]) & a1) != 0.
  The return at 0x13c has v0 = ?.

- `ioc3_serial_intr` in `IP30/usr/cpu/sysgen/IP30boot/sduart.a(sio_ioc3.o)` at 0x144 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/sduart.a(sio_ioc3.o)`.
  Range: 0x144-0x494 (848 bytes).
  It occupies 848 bytes.
  The `ld` at 0x154 loads 8 bytes from a0 (arg0 at entry) +0x70.
  4 such `lw` accesses load 4 bytes from [a0+112]:8 +0x8, including `lw` at 0x15c, `lw` at 0x390, `lw` at 0x3c8.
  2 such `ld` accesses load 8 bytes from [a0+8]:8 +0x20, including `ld` at 0x1a0, `ld` at 0x308.
  2 such `lw` accesses load 4 bytes from [a0+112]:8 +0xc, including `lw` at 0x1b0, `lw` at 0x31c.
  8 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x38, including `ld` at 0x1c0, `ld` at 0x204, `ld` at 0x240.
  4 such `sw` accesses store 4 bytes to [a0+56]:8 +0x1c, including `sw` at 0x1c4, `sw` at 0x214, `sw` at 0x288.
  7 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x8c, including `lw` at 0x1c8, `lw` at 0x218, `lw` at 0x28c.
  6 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x8, including `ld` at 0x1d8, `ld` at 0x228, `ld` at 0x2ac.
  2 such `ld` accesses load 8 bytes from [a0+8]:8 +0x0, including `ld` at 0x1e4, `ld` at 0x34c.
  2 such `lw` accesses load 4 bytes from [a0+112]:8 +0x14, including `lw` at 0x1f0, `lw` at 0x210.
  4 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x78, including `lw` at 0x200, `lw` at 0x378, `lw` at 0x448.
  3 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x78, including `sw` at 0x20c, `sw` at 0x454, `sw` at 0x490.
  2 such `ld` accesses load 8 bytes from [a0+8]:8 +0x8, including `ld` at 0x234, `ld` at 0x3bc.
  4 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x90, including `lw` at 0x244, `lw` at 0x360, `lw` at 0x3d0.
  3 such `lw` accesses load 4 bytes from [a0+56]:8 +0x1c, including `lw` at 0x248, `lw` at 0x364, `lw` at 0x3d4.
  The `lw` at 0x24c loads 4 bytes from [a0+112]:8 +0x1c.
  3 such `lw` accesses load 4 bytes from [a0+112]:8 +0x10, including `lw` at 0x258, `lw` at 0x320, `lw` at 0x358.
  The `lw` at 0x274 loads 4 bytes from [a0+112]:8 +0x0.
  3 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x40, including `ld` at 0x290, `ld` at 0x2e4, `ld` at 0x460.
  2 such `lw` accesses load 4 bytes from [a0+64]:8 +0x18, including `lw` at 0x29c, `lw` at 0x2f0.
  The `ld` at 0x2b8 loads 8 bytes from [a0+8]:8 +0x18.
  The `lw` at 0x2c8 loads 4 bytes from [a0+112]:8 +0x4.
  The `ld` at 0x420 loads 8 bytes from a0 (arg0 at entry) +0xa0.
  The `lw` at 0x458 loads 4 bytes from a0 (arg0 at entry) +0x94.
  The `sw` at 0x46c stores 4 bytes to a0 (arg0 at entry) +0x94.
  The `sw` at 0x470 stores 4 bytes to [a0+64]:8 +0x0.
  The `jal` at 0x17c calls sio_lock_port with a0=a0 at entry (arg0), a1=0x0, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x1a8 calls (unknown callee) with a0=a0 at entry (arg0), a1=0x1, a2=?, a3=[a0+8]:8.
  The `jalr` at 0x1e8 calls (unknown callee) with a0=a0 at entry (arg0), a1=?, a2=?, a3=[a0+8]:8.
  The `jalr` at 0x238 calls (unknown callee) with a0=a0 at entry (arg0), a1=[[a0+112]:8+20], a2=[a0+56]:8, a3=[a0+8]:8, a4=[[a0+8]:8+8]:8.
  The `jalr` at 0x2c0 calls (unknown callee) with a0=a0 at entry (arg0), a1=0x1, a2=?, a3=[a0+8]:8, a5=[[a0+8]:8+24]:8.
  The `jalr` at 0x310 calls (unknown callee) with a0=a0 at entry (arg0), a1=0x0, a2=?, a3=[a0+8]:8, a5=[[a0+8]:8+32]:8.
  The `jalr` at 0x350 calls (unknown callee) with a0=a0 at entry (arg0), a1=[[a0+112]:8+16], a2=?, a3=[a0+8]:8.
  The `jalr` at 0x3c0 calls (unknown callee) with a0=a0 at entry (arg0), a1=[[a0+112]:8+8], a2=?, a3=[a0+8]:8.
  The `jal` at 0x3f8 calls mask_disable_intrs with a0=a0 at entry (arg0), a1=[[a0+112]:8+8], a2=?, a3=?.
  The `jal` at 0x408 calls sio_unlock_port with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x428 calls ioc3_write_ireg with a0=[a0+160]:8, a1=[a0+144], a2=0x0, a3=?.
  The `jal` at 0x47c calls mask_disable_intrs with a0=a0 at entry (arg0), a1=[[a0+112]:8+16], a2=?, a3=?.
  The `beq` branch at 0x190 targets 0x274 and is always taken.
  The `beq` branch at 0x198 targets 0x1b0, is taken when a3(=[a0+8]:8) == 0, and falls through when a3(=[a0+8]:8) != 0.
  The `beq` branch at 0x1b8 targets 0x320, is taken when (a0(=[[a0+112]:8+12]) & s1(?)) == 0, and falls through when (a0(=[[a0+112]:8+12]) & s1(?)) != 0.
  The `beq` branch at 0x1d0 targets 0x1f0, is taken when (ra(=[a0+140]) & 0x1) == 0, and falls through when (ra(=[a0+140]) & 0x1) != 0.
  The `beq` branch at 0x1dc targets 0x1f0, is taken when a3(=[a0+8]:8) == 0, and falls through when a3(=[a0+8]:8) != 0.
  The `beq` branch at 0x1f8 targets 0x390, is taken when (v1(=[[a0+112]:8+20]) & s1(?)) == 0, and falls through when (v1(=[[a0+112]:8+20]) & s1(?)) != 0.
  The `beq` branch at 0x220 targets 0x240, is taken when (a0(=[a0+140]) & 0x2) == 0, and falls through when (a0(=[a0+140]) & 0x2) != 0.
  The `beq` branch at 0x22c targets 0x240, is taken when a3(=[a0+8]:8) == 0, and falls through when a3(=[a0+8]:8) != 0.
  The `beq` branch at 0x250 targets 0x268, is taken when s3(?) == 0, and falls through when s3(?) != 0.
  The `bne` branch at 0x25c targets 0x268, is taken when a1(=[[a0+112]:8+16]) != s1(?), and falls through when a1(=[[a0+112]:8+16]) == s1(?).
  The `beq` branch at 0x26c targets 0x408, is taken when (a0(=[[a0+112]:8+28]) & s1(?)) == 0, and falls through when (a0(=[[a0+112]:8+28]) & s1(?)) != 0.
  The `beq` branch at 0x27c targets 0x2c8, is taken when (a1(=[[a0+112]:8]) & s1(?)) == 0, and falls through when (a1(=[[a0+112]:8]) & s1(?)) != 0.
  The `beq` branch at 0x298 targets 0x2c8, is taken when (a2(=[a0+140]) & 0x40) == 0, and falls through when (a2(=[a0+140]) & 0x40) != 0.
  The `beq` branch at 0x2a4 targets 0x448, is taken when (s4(=0x800000) & a0(=[[a0+64]:8+24])) == 0, and falls through when (s4(=0x800000) & a0(=[[a0+64]:8+24])) != 0.
  The `beq` branch at 0x2b0 targets 0x2c8, is taken when a3(=[a0+8]:8) == 0, and falls through when a3(=[a0+8]:8) != 0.
  The `beq` branch at 0x2d0 targets 0x1b0, is taken when (a1(=[[a0+112]:8+4]) & s1(?)) == 0, and falls through when (a1(=[[a0+112]:8+4]) & s1(?)) != 0.
  The `beq` branch at 0x2ec targets 0x1b0, is taken when (a2(=[a0+140]) & 0x80) == 0, and falls through when (a2(=[a0+140]) & 0x80) != 0.
  The `bne` branch at 0x2f8 targets 0x198, is taken when (s5(=0x100000) & a0(=[[a0+64]:8+24])) != 0, and falls through when (s5(=0x100000) & a0(=[[a0+64]:8+24])) == 0.
  The `beq` branch at 0x300 targets 0x1b0, is taken when a3(=[a0+8]:8) == 0, and falls through when a3(=[a0+8]:8) != 0.
  The `beq` branch at 0x318 targets 0x1b4 and is always taken.
  The `beq` branch at 0x328 targets 0x1f0, is taken when (a1(=[[a0+112]:8+16]) & s1(?)) == 0, and falls through when (a1(=[[a0+112]:8+16]) & s1(?)) != 0.
  The `beq` branch at 0x338 targets 0x35c, is taken when (a7(=[a0+140]) & 0x1) == 0, and falls through when (a7(=[a0+140]) & 0x1) != 0.
  The `beq` branch at 0x344 targets 0x35c, is taken when a3(=[a0+8]:8) == 0, and falls through when a3(=[a0+8]:8) != 0.
  The `beq` branch at 0x370 targets 0x1f0, is taken when (s1(?) & a1(=[[a0+112]:8+16])) == 0, and falls through when (s1(?) & a1(=[[a0+112]:8+16])) != 0.
  The `beq` branch at 0x380 targets 0x47c, is taken when (t8(=[a0+120]) & 0x8) == 0, and falls through when (t8(=[a0+120]) & 0x8) != 0.
  The `beq` branch at 0x388 targets 0x1f0 and is always taken.
  The `beq` branch at 0x398 targets 0x240, is taken when (a1(=[[a0+112]:8+8]) & s1(?)) == 0, and falls through when (a1(=[[a0+112]:8+8]) & s1(?)) != 0.
  The `beq` branch at 0x3a8 targets 0x3e0, is taken when (t9(=[a0+140]) & 0x2) == 0, and falls through when (t9(=[a0+140]) & 0x2) != 0.
  The `beq` branch at 0x3b4 targets 0x3cc, is taken when a3(=[a0+8]:8) == 0, and falls through when a3(=[a0+8]:8) != 0.
  The `beq` branch at 0x3e0 targets 0x240, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x3f0 targets 0x458, is taken when (a2(=[a0+140]) & 0x41) == 0, and falls through when (a2(=[a0+140]) & 0x41) != 0.
  The `beq` branch at 0x400 targets 0x244 and is always taken.
  The `beq` branch at 0x450 targets 0x2c8 and is always taken.
  The `beq` branch at 0x474 targets 0x3f8 and is always taken.
  The `beq` branch at 0x48c targets 0x1f0 and is always taken.
  The return at 0x440 has v0 = ret(ioc3_write_ireg).

- `set_baud_ti` in `IP30/usr/cpu/sysgen/IP30boot/sduart.a(sio_ioc3.o)` at 0x494 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/sduart.a(sio_ioc3.o)`.
  Range: 0x494-0x57c (232 bytes).
  It occupies 232 bytes.
  5 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x48, including `ld` at 0x540, `ld` at 0x550, `ld` at 0x558.
  The `lbu` at 0x544 loads 1 byte from [a0+72]:8 +0x3.
  2 such `sb` accesses store 1 byte to [a0+72]:8 +0x3, including `sb` at 0x54c, `sb` at 0x570.
  The `sb` at 0x554 stores 1 byte to [a0+72]:8 +0x0.
  The `sb` at 0x55c stores 1 byte to [a0+72]:8 +0x1.
  The `sb` at 0x564 stores 1 byte to [a0+72]:8 +0x7.
  The `beq` branch at 0x4a4 targets 0x4dc and is always taken.
  The `beq` branch at 0x4c4 targets 0x530, is taken when t1(?) >= t9(?) (signed), and falls through when t1(?) < t9(?) (signed).
  The `beq` branch at 0x4d4 targets 0x530, is taken when a4(?) >= 0x40 (signed), and falls through when a4(?) < 0x40 (signed).
  The `beq` branch at 0x500 targets 0x4cc, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `bgez` branch at 0x520 targets 0x4ac, is taken when t9(?) >= 0 (signed), and falls through when t9(?) < 0 (signed).
  The `beq` branch at 0x528 targets 0x4ac and is always taken.
  The `beq` branch at 0x538 targets 0x574, is taken when a4(?) == a1(=0x40), and falls through when a4(?) != a1(=0x40).
  The return at 0x574 has v0 = one of 0x0, 0x1.

- `ioc3_serial_attach` in `IP30/usr/cpu/sysgen/IP30boot/sduart.a(sio_ioc3.o)` at 0x74c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/sduart.a(sio_ioc3.o)`.
  Range: 0x74c-0xc08 (1212 bytes).
  It occupies 1212 bytes.
  The `sd` at 0x8a4 stores 8 bytes to ret(kmem_zalloc) +0x70.
  The `ld` at 0x8a8 loads 8 bytes from ret(kmem_zalloc) +0x50.
  4 such `ld` accesses load 8 bytes from ret(kmem_zalloc) +0x58, including `ld` at 0x8ac, `ld` at 0x8d0, `ld` at 0x968.
  The `ld` at 0x8b0 loads 8 bytes from ret(kmem_zalloc) +0x38.
  The `sd` at 0x8b8 stores 8 bytes to ret(kmem_zalloc) +0x48.
  The `sd` at 0x8c4 stores 8 bytes to ret(kmem_zalloc) +0x40.
  The `sd` at 0x8dc stores 8 bytes to ret(kmem_zalloc) +0x68.
  The `sd` at 0x8e8 stores 8 bytes to ret(kmem_zalloc) +0x60.
  4 such `lw` accesses load 4 bytes from ret(kmem_zalloc) +0x34, including `lw` at 0x8f4, `lw` at 0x908, `lw` at 0x914.
  The `sd` at 0x964 stores 8 bytes to ret(kmem_zalloc) +0x118.
  The `sd` at 0x96c stores 8 bytes to ret(kmem_zalloc) +0x100.
  The `ld` at 0x970 loads 8 bytes from ret(kmem_zalloc) +0xe0.
  The `ld` at 0x974 loads 8 bytes from ret(kmem_zalloc) +0xf8.
  The `sd` at 0x97c stores 8 bytes to ret(kmem_zalloc) +0xe8.
  The `sd` at 0x988 stores 8 bytes to ret(kmem_zalloc) +0xf0.
  The `sd` at 0x994 stores 8 bytes to ret(kmem_zalloc) +0x108.
  The `sd` at 0x9a0 stores 8 bytes to ret(kmem_zalloc) +0x110.
  4 such `lw` accesses load 4 bytes from ret(kmem_zalloc) +0xdc, including `lw` at 0x9ac, `lw` at 0x9c0, `lw` at 0x9dc.
  6 such `sw` accesses store 4 bytes to ?, including `sw` at 0xa28, `sw` at 0xab0, `sw` at 0xab8.
  5 such `sd` accesses store 8 bytes to ?, including `sd` at 0xa54, `sd` at 0xa60, `sd` at 0xa70.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0xa88, `ld` at 0xa90.
  The `lw` at 0xae4 loads 4 bytes from ?.
  2 such `sb` accesses store 1 byte to ret(kmem_zalloc) +0x1d, including `sb` at 0xb0c, `sb` at 0xb90.
  The `sd` at 0xbf4 stores 8 bytes to ret(kmem_zalloc) +0x58.
  The `jal` at 0x758 calls ioc3_subdev_enabled with a0=a0 at entry (arg0), a1=0x4, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x780 calls ioc3_subdev_enabled with a0=a0 at entry (arg0), a1=0x4, a2=?, a3=?.
  The `jal` at 0x7a4 calls ioc3_subdev_enabled with a0=a0 at entry (arg0), a1=0x5, a2=?, a3=?.
  The `jal` at 0x7e4 calls pciio_piotrans_addr with a0=a0 at entry (arg0), a1=0x0, a2=0x8, a3=0x0, a4=0x20180, a5=0x0.
  The `jal` at 0x7f0 calls ioc3_is_console with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x808 calls hwgraph_traverse with a0=a0 at entry (arg0), a1=sym(.rodata), a2=sp-12, a3=?.
  The `jal` at 0x81c calls hwgraph_traverse with a0=a0 at entry (arg0), a1=sym(.rodata), a2=sp-176, a3=?.
  The `jal` at 0x824 calls hwgraph_fastinfo_get with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x834 calls kmem_zalloc with a0=0x150, a1=0x0, a2=?, a3=?.
  The `jal` at 0x894 calls ioc3_subdev_enabled with a0=a0 at entry (arg0), a1=0x4, a2=?, a3=?.
  The `jal` at 0x8c8 calls bzero with a0=?, a1=0x4000, a2=?, a3=?.
  The `jal` at 0x8e4 calls hardware_init with a0=ret(kmem_zalloc), a1=ret(ioc3_is_console), a2=?, a3=?, a6=[ret(kmem_zalloc)+88]:8+4096.
  The `jal` at 0x8f8 calls hwgraph_edge_get with a0=[ret(kmem_zalloc)+52], a1=sym(.rodata), a2=sp-140, a3=?.
  The `jal` at 0x924 calls ioc3_intr_connect with a0=a0 at entry (arg0), a1=0x1ff, a2=sym(ioc3_serial_intr), a3=ret(kmem_zalloc), a4=[ret(kmem_zalloc)+52], a6=0x0.
  The `jal` at 0x934 calls device_controller_num_set with a0=[ret(kmem_zalloc)+52], a1=0x1, a2=?, a3=?.
  The `jal` at 0x93c calls sio_make_hwgraph_nodes with a0=ret(kmem_zalloc), a1=?, a2=?, a3=?.
  The `jal` at 0x950 calls ioc3_subdev_enabled with a0=a0 at entry (arg0), a1=0x5, a2=?, a3=?.
  The `jal` at 0x99c calls hardware_init with a0=?, a1=0x0, a2=[ret(kmem_zalloc)+88]:8+8192, a3=[ret(kmem_zalloc)+88]:8+12288, a4=[ret(kmem_zalloc)+248]:8+368, a5=[ret(kmem_zalloc)+224]:8+212, a6=sym(.data).
  The `jal` at 0x9b0 calls hwgraph_edge_get with a0=[ret(kmem_zalloc)+220], a1=sym(.rodata), a2=sp-140, a3=?.
  The `jal` at 0x9e0 calls ioc3_intr_connect with a0=a0 at entry (arg0), a1=0x3fe00, a2=sym(ioc3_serial_intr), a3=?, a4=[ret(kmem_zalloc)+220], a6=0x0.
  The `jal` at 0x9f0 calls device_controller_num_set with a0=[ret(kmem_zalloc)+220], a1=0x2, a2=?, a3=?.
  The `jal` at 0x9f8 calls sio_make_hwgraph_nodes with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xa4c calls device_inventory_add with a0=?, a1=0x4, a2=0x10, a3=-0x1, a4=0x0, a5=0x0.
  The `jal` at 0xaa4 calls hwgraph_path_add with a0=a0 at entry (arg0), a1=?, a2=sp-148, a3=?.
  The `jal` at 0xac4 calls hwgraph_fastinfo_set with a0=?, a1=?, a2=?, a3=a0 at entry (arg0).
  The `jal` at 0xae8 calls sio_initport with a0=?, a1=?, a2=0x1ff, a3=one of 0x0, 0x1.
  The `jal` at 0xaf4 calls kmem_zalloc with a0=0x28, a1=0x0, a2=?, a3=?.
  The `jal` at 0xb10 calls sio_init_locks with a0=ret(kmem_zalloc), a1=?, a2=one of 0x2, 0x3, a3=?.
  The `jal` at 0xb34 calls hwgraph_edge_get with a0=?, a1=sym(.rodata), a2=sp-144, a3=?, a4=0x2580.
  The `jal` at 0xb58 calls kopt_find with a0=sym(.rodata), a1=?, a2=?, a3=0x1.
  The `jal` at 0xb68 calls atoi with a0=ret(kopt_find), a1=?, a2=0x1, a3=?.
  The `jal` at 0xba4 calls ioc3_subdev_enabled with a0=a0 at entry (arg0), a1=0x5, a2=?, a3=?.
  The `jal` at 0xbcc calls printf with a0=sym(.rodata), a1=?, a2=0x1, a3=?.
  The `jal` at 0xbe4 calls kvpalloc with a0=0x1, a1=0x100, a2=0x0, a3=?, a4=[ret(kmem_zalloc)+56]:8+184, a5=[ret(kmem_zalloc)+80]:8+376.
  The `jal` at 0xbf8 calls panic with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `beq` branch at 0x774 targets 0xba0, is taken when v0(=ret(ioc3_subdev_enabled)) == 0, and falls through when v0(=ret(ioc3_subdev_enabled)) != 0.
  The `beq` branch at 0x790 targets 0xbbc, is taken when v0(=ret(ioc3_subdev_enabled)) == 0, and falls through when v0(=ret(ioc3_subdev_enabled)) != 0.
  The `beq` branch at 0x7ac targets 0x7cc, is taken when v0(=ret(ioc3_subdev_enabled)) == 0, and falls through when v0(=ret(ioc3_subdev_enabled)) != 0.
  The `bne` branch at 0x854 targets 0x878, is taken when s5(=one of -0x1, 0x0, 0x1) < s0(=one of -0x1, 0x0, 0x1) (signed), and falls through when s5(=one of -0x1, 0x0, 0x1) >= s0(=one of -0x1, 0x0, 0x1) (signed).
  The `beq` branch at 0x870 targets 0xa74 and is always taken.
  The `beq` branch at 0x89c targets 0x94c, is taken when v0(=ret(ioc3_subdev_enabled)) == 0, and falls through when v0(=ret(ioc3_subdev_enabled)) != 0.
  The `beq` branch at 0x8c0 targets 0xbdc, is taken when a0(=[ret(kmem_zalloc)+88]:8) == 0, and falls through when a0(=[ret(kmem_zalloc)+88]:8) != 0.
  The `beq` branch at 0x900 targets 0x910, is taken when v0(=ret(hwgraph_edge_get)) == 0, and falls through when v0(=ret(hwgraph_edge_get)) != 0.
  The `beq` branch at 0x92c targets 0x948, is taken when s3(=ret(ioc3_is_console)) == 0, and falls through when s3(=ret(ioc3_is_console)) != 0.
  The `beq` branch at 0x958 targets 0xa04, is taken when v0(=ret(ioc3_subdev_enabled)) == 0, and falls through when v0(=ret(ioc3_subdev_enabled)) != 0.
  The `beq` branch at 0x9b8 targets 0x9c8, is taken when v0(=ret(hwgraph_edge_get)) == 0, and falls through when v0(=ret(hwgraph_edge_get)) != 0.
  The `beq` branch at 0x9e8 targets 0xa00, is taken when s3(=ret(ioc3_is_console)) == 0, and falls through when s3(=ret(ioc3_is_console)) != 0.
  The `beq` branch at 0xa30 targets 0xbc4, is taken when s0(?) == a2(=0x1), and falls through when s0(?) != a2(=0x1).
  The `bne` branch at 0xa6c targets 0x878, is taken when s5(=one of -0x1, 0x0, 0x1) < s0(?) (signed), and falls through when s5(=one of -0x1, 0x0, 0x1) >= s0(?) (signed).
  The `beq` branch at 0xacc targets 0xae0, is taken when s3(=ret(ioc3_is_console)) == 0, and falls through when s3(=ret(ioc3_is_console)) != 0.
  The `beq` branch at 0xad4 targets 0xb80, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0xafc targets 0xb08, is taken when s3(=ret(ioc3_is_console)) == 0, and falls through when s3(=ret(ioc3_is_console)) != 0.
  The `beq` branch at 0xb04 targets 0xb88, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0xb20 targets 0xa38, is taken when s3(=ret(ioc3_is_console)) == 0, and falls through when s3(=ret(ioc3_is_console)) != 0.
  The `beq` branch at 0xb44 targets 0xb94, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `bne` branch at 0xb4c targets 0xa38, is taken when s0(?) != a3(=0x1), and falls through when s0(?) == a3(=0x1).
  The `beq` branch at 0xb60 targets 0xa30, is taken when v0(=ret(kopt_find)) == 0, and falls through when v0(=ret(kopt_find)) != 0.
  The `bgtz` branch at 0xb70 targets 0xa28, is taken when v0(=ret(atoi)) > 0 (signed), and falls through when v0(=ret(atoi)) <= 0 (signed).
  The `beq` branch at 0xb78 targets 0xa30 and is always taken.
  The `beq` branch at 0xb80 targets 0xae4 and is always taken.
  The `beq` branch at 0xb8c targets 0xb10 and is always taken.
  The `beq` branch at 0xb98 targets 0xb58 and is always taken.
  The `bne` branch at 0xbac targets 0x780, is taken when v0(=ret(ioc3_subdev_enabled)) != 0, and falls through when v0(=ret(ioc3_subdev_enabled)) == 0.
  The `beq` branch at 0xbb4 targets 0xa04 and is always taken.
  The `beq` branch at 0xbbc targets 0x7a0 and is always taken.
  The `beq` branch at 0xbc4 targets 0xbd4, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0xbd4 targets 0xa38 and is always taken.
  The `bne` branch at 0xbf0 targets 0x8c8, is taken when v0(=ret(kvpalloc)) != 0, and falls through when v0(=ret(kvpalloc)) == 0.
  The `beq` branch at 0xc00 targets 0x8c8 and is always taken.
  The return at 0xa20 has v0 = one of -0x1, 0x0.

- `ioc3_serial_kill` in `IP30/usr/cpu/sysgen/IP30boot/sduart.a(sio_ioc3.o)` at 0xc08 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/sduart.a(sio_ioc3.o)`.
  Range: 0xc08-0xc48 (64 bytes).
  It occupies 64 bytes.
  The `ld` at 0xc08 loads 8 bytes from a0 (arg0 at entry) +0x8.
  The `ld` at 0xc20 loads 8 bytes from [a0+8]:8 +0x28.
  The `ld` at 0xc2c loads 8 bytes from a0 (arg0 at entry) +0x40.
  The `sw` at 0xc34 stores 4 bytes to [a0+64]:8 +0x0.
  The `sw` at 0xc38 stores 4 bytes to a0 (arg0 at entry) +0x94.
  The `jalr` at 0xc24 calls (unknown callee) with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=[a0+8]:8, a3=a3 at entry (arg3).
  The `beq` branch at 0xc18 targets 0xc2c, is taken when a2(=[a0+8]:8) == 0, and falls through when a2(=[a0+8]:8) != 0.
  The return at 0xc40 has v0 = [a0+64]:8.

- `ioc3_open` in `IP30/usr/cpu/sysgen/IP30boot/sduart.a(sio_ioc3.o)` at 0xc48 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/sduart.a(sio_ioc3.o)`.
  Range: 0xc48-0xd30 (232 bytes).
  It occupies 232 bytes.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x94, including `lw` at 0xc48, `lw` at 0xce8.
  The `sb` at 0xc4c stores 1 byte to a0 (arg0 at entry) +0x7c.
  The `sw` at 0xc54 stores 4 bytes to a0 (arg0 at entry) +0x78.
  4 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x40, including `ld` at 0xc7c, `ld` at 0xc8c, `ld` at 0xcf0.
  2 such `sw` accesses store 4 bytes to [a0+64]:8 +0x0, including `sw` at 0xc88, `sw` at 0xd00.
  2 such `lw` accesses load 4 bytes from [a0+64]:8 +0x0, including `lw` at 0xc90, `lw` at 0xcb0.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x48, including `ld` at 0xcc4, `ld` at 0xcdc.
  The `sb` at 0xcd8 stores 1 byte to [a0+72]:8 +0x2.
  The `sb` at 0xce4 stores 1 byte to [a0+72]:8 +0x3.
  The `sw` at 0xcfc stores 4 bytes to a0 (arg0 at entry) +0x94.
  The `sw` at 0xd08 stores 4 bytes to [a0+64]:8 +0x14.
  The `sw` at 0xd14 stores 4 bytes to a0 (arg0 at entry) +0x84.
  The `jal` at 0xcd4 calls set_baud_ti with a0=a0 at entry (arg0), a1=0x2580, a2=?, a3=0x3, a4=[a0+72]:8, a7=0xf0000.
  The `bgez` branch at 0xc70 targets 0xcc4, is taken when at(=([a0+148] << 0x23)) >= 0 (signed), and falls through when at(=([a0+148] << 0x23)) < 0 (signed).
  The `bltz` branch at 0xc98 targets 0xcc4, is taken when v1(=([[a0+64]:8] << 0x21)) < 0 (signed), and falls through when v1(=([[a0+64]:8] << 0x21)) >= 0 (signed).
  The `bne` branch at 0xca8 targets 0xd28, is taken when a1(?) != 0, and falls through when a1(?) == 0.
  The `beq` branch at 0xcbc targets 0xca8, is taken when (a2(=[[a0+64]:8]) & a5(=0x40000000)) == 0, and falls through when (a2(=[[a0+64]:8]) & a5(=0x40000000)) != 0.
  The `beq` branch at 0xd28 targets 0xd1c and is always taken.
  The return at 0xd20 has v0 = one of -0x1, 0x0.

- `ioc3_config` in `IP30/usr/cpu/sysgen/IP30boot/sduart.a(sio_ioc3.o)` at 0xd30 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/sduart.a(sio_ioc3.o)`.
  Range: 0xd30-0xf04 (468 bytes).
  It occupies 468 bytes.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x94, including `lw` at 0xdc8, `lw` at 0xe74.
  3 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x40, including `ld` at 0xdd8, `ld` at 0xde8, `ld` at 0xe84.
  2 such `sw` accesses store 4 bytes to [a0+64]:8 +0x0, including `sw` at 0xde4, `sw` at 0xe88.
  2 such `lw` accesses load 4 bytes from [a0+64]:8 +0x0, including `lw` at 0xdec, `lw` at 0xe18.
  The `ld` at 0xe2c loads 8 bytes from a0 (arg0 at entry) +0x48.
  The `lbu` at 0xe30 loads 1 byte from [a0+72]:8 +0x3.
  The `sb` at 0xe70 stores 1 byte to [a0+72]:8 +0x3.
  The `sw` at 0xeb4 stores 4 bytes to a0 (arg0 at entry) +0x80.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x84, including `sw` at 0xebc, `sw` at 0xed8.
  The `lw` at 0xec8 loads 4 bytes from a0 (arg0 at entry) +0x88.
  The `jal` at 0xd54 calls set_baud_ti with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xec4 calls ioc3_rx_timeout with a0=a0 at entry (arg0), a1=[a0+136], a2=[a0+148], a3=?, a6=a1 at entry (arg1), a7=0x3e8.
  The `beq` branch at 0xd5c targets 0xd7c, is taken when v0(=ret(set_baud_ti)) == 0, and falls through when v0(=ret(set_baud_ti)) != 0.
  The `beq` branch at 0xd90 targets 0xdc0, is taken when s1(=a2) == at(=0x5), and falls through when s1(=a2) != at(=0x5).
  The `beq` branch at 0xd98 targets 0xedc, is taken when s1(=a2) == a0(=0x6), and falls through when s1(=a2) != a0(=0x6).
  The `beq` branch at 0xda0 targets 0xee4, is taken when s1(=a2) == a2(=0x7), and falls through when s1(=a2) != a2(=0x7).
  The `beq` branch at 0xda8 targets 0xdb8, is taken when s1(=a2) == a7(=0x8), and falls through when s1(=a2) != a7(=0x8).
  The `beq` branch at 0xdb0 targets 0xd6c and is always taken.
  The `beq` branch at 0xdb8 targets 0xdc8 and is always taken.
  The `bgez` branch at 0xdd0 targets 0xe2c, is taken when v0(=([a0+148] << 0x23)) >= 0 (signed), and falls through when v0(=([a0+148] << 0x23)) < 0 (signed).
  The `bltz` branch at 0xe00 targets 0xe2c, is taken when t3(=([[a0+64]:8] << 0x21)) < 0 (signed), and falls through when t3(=([[a0+64]:8] << 0x21)) >= 0 (signed).
  The `bne` branch at 0xe10 targets 0xeec, is taken when t9(?) != 0, and falls through when t9(?) == 0.
  The `beq` branch at 0xe24 targets 0xe10, is taken when (ra(=[[a0+64]:8]) & t1(=0x40000000)) == 0, and falls through when (ra(=[[a0+64]:8]) & t1(=0x40000000)) != 0.
  The `beq` branch at 0xe50 targets 0xe64, is taken when v1(=a4) == 0, and falls through when v1(=a4) != 0.
  The `beq` branch at 0xe5c targets 0xef4, is taken when a0(=a5) == 0, and falls through when a0(=a5) != 0.
  The `beq` branch at 0xe64 targets 0xe70, is taken when a1(=a3) == 0, and falls through when a1(=a3) != 0.
  The `beq` branch at 0xe7c targets 0xe8c, is taken when (t2(=0x10000000) & a2(=[a0+148])) == 0, and falls through when (t2(=0x10000000) & a2(=[a0+148])) != 0.
  The `beq` branch at 0xeb8 targets 0xed4, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `beq` branch at 0xecc targets 0xd68 and is always taken.
  The `beq` branch at 0xed4 targets 0xec0 and is always taken.
  The `beq` branch at 0xedc targets 0xdc4 and is always taken.
  The `beq` branch at 0xee4 targets 0xdc8 and is always taken.
  The `beq` branch at 0xeec targets 0xd6c and is always taken.
  The `bne` branch at 0xef4 targets 0xe6c, is taken when t3(=a3) != 0, and falls through when t3(=a3) == 0.
  The `beq` branch at 0xefc targets 0xe70 and is always taken.
  The return at 0xd74 has v0 = one of -0x1, 0x0, 0x1.

- `ioc3_enable_hfc` in `IP30/usr/cpu/sysgen/IP30boot/sduart.a(sio_ioc3.o)` at 0xf04 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/sduart.a(sio_ioc3.o)`.
  Range: 0xf04-0xf38 (52 bytes).
  It occupies 52 bytes.
  The `lw` at 0xf04 loads 4 bytes from a0 (arg0 at entry) +0x94.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x94, including `sw` at 0xf14, `sw` at 0xf34.
  The `ld` at 0xf18 loads 8 bytes from a0 (arg0 at entry) +0x40.
  The `sw` at 0xf24 stores 4 bytes to [a0+64]:8 +0x0.
  The `beq` branch at 0xf08 targets 0xf28, is taken when a1 == 0, and falls through when a1 != 0.
  The `beq` branch at 0xf30 targets 0xf18 and is always taken.
  The return at 0xf20 has v0 = 0x0.

- `ioc3_set_extclk` in `IP30/usr/cpu/sysgen/IP30boot/sduart.a(sio_ioc3.o)` at 0xf38 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/sduart.a(sio_ioc3.o)`.
  Range: 0xf38-0xf40 (8 bytes).
  It occupies 8 bytes.
  The return at 0xf38 has v0 = a1.

- `do_ioc3_write` in `IP30/usr/cpu/sysgen/IP30boot/sduart.a(sio_ioc3.o)` at 0xf40 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/sduart.a(sio_ioc3.o)`.
  Range: 0xf40-0x10dc (412 bytes).
  It occupies 412 bytes.
  3 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x40, including `ld` at 0xf40, `ld` at 0x1068, `ld` at 0x107c.
  The `lw` at 0xf44 loads 4 bytes from [a0+64]:8 +0x8.
  The `ld` at 0xf48 loads 8 bytes from a0 (arg0 at entry) +0x68.
  The `lw` at 0xf58 loads 4 bytes from a0 (arg0 at entry) +0x98.
  The `ld` at 0xf60 loads 8 bytes from a0 (arg0 at entry) +0x70.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x78, including `lw` at 0xf90, `lw` at 0x1014, `lw` at 0x10d8.
  The `sw` at 0xfa4 stores 4 bytes to a0 (arg0 at entry) +0x98.
  3 such `lbu` accesses load 1 byte from ?, including `lbu` at 0xfd0, `lbu` at 0xff8, `lbu` at 0x10c0.
  5 such `sb` accesses store 1 byte to ?, including `sb` at 0xfd8, `sb` at 0xfe4, `sb` at 0x1000.
  The `sw` at 0x1044 stores 4 bytes to ?.
  The `lw` at 0x1058 loads 4 bytes from a0 (arg0 at entry) +0x94.
  The `sw` at 0x1070 stores 4 bytes to a0 (arg0 at entry) +0x94.
  The `sw` at 0x1078 stores 4 bytes to [a0+64]:8 +0x0.
  The `sw` at 0x1088 stores 4 bytes to [a0+64]:8 +0x4.
  The `lw` at 0x1094 loads 4 bytes from [a0+112]:8 +0x8.
  The `lw` at 0x10a0 loads 4 bytes from a0 (arg0 at entry) +0x84.
  The `sw` at 0x10bc stores 4 bytes to a0 (arg0 at entry) +0x78.
  The `jal` at 0x1090 calls enable_intrs with a0=a0 at entry (arg0), a1=[[a0+112]:8+8], a2=?, a3=?.
  The `beq` branch at 0xf78 targets 0xf90, is taken when a6(?) == s2(=[a0+152]), and falls through when a6(?) != s2(=[a0+152]).
  The `blez` branch at 0xf80 targets 0x10d0, is taken when a2 <= 0 (signed), and falls through when a2 > 0 (signed).
  The `beq` branch at 0xf88 targets 0x1038 and is always taken.
  The `beq` branch at 0xf98 targets 0x107c, is taken when (a7(=[a0+120]) & 0x10) == 0, and falls through when (a7(=[a0+120]) & 0x10) != 0.
  The `blez` branch at 0xfb8 targets 0x1014, is taken when a2(?) <= 0 (signed), and falls through when a2(?) > 0 (signed).
  The `beq` branch at 0xfe8 targets 0x1014, is taken when v0(?) >= 0x4 (signed), and falls through when v0(?) < 0x4 (signed).
  The `blez` branch at 0xff0 targets 0x1014, is taken when a2(?) <= 0 (signed), and falls through when a2(?) > 0 (signed).
  The `bne` branch at 0x100c targets 0xfb8, is taken when a4(?) != 0, and falls through when a4(?) == 0.
  The `beq` branch at 0x101c targets 0x10a0, is taken when (v0(=[a0+120]) & 0x4) == 0, and falls through when (v0(=[a0+120]) & 0x4) != 0.
  The `beq` branch at 0x1028 targets 0x1050, is taken when a6(?) == s2(?), and falls through when a6(?) != s2(?).
  The `blez` branch at 0x1030 targets 0x1050, is taken when a2(?) <= 0 (signed), and falls through when a2(?) > 0 (signed).
  The `blez` branch at 0x1040 targets 0x1014, is taken when a2(?) <= 0 (signed), and falls through when a2(?) > 0 (signed).
  The `beq` branch at 0x1048 targets 0xfc0 and is always taken.
  The `blez` branch at 0x1050 targets 0xf90, is taken when s0(?) <= 0 (signed), and falls through when s0(?) > 0 (signed).
  The `bltz` branch at 0x1060 targets 0xf90, is taken when a6(=([a0+148] << 0x23)) < 0 (signed), and falls through when a6(=([a0+148] << 0x23)) >= 0 (signed).
  The `beq` branch at 0x1074 targets 0xf90 and is always taken.
  The `blez` branch at 0x1084 targets 0xf9c, is taken when s0(?) <= 0 (signed), and falls through when s0(?) > 0 (signed).
  The `beq` branch at 0x1098 targets 0xf9c and is always taken.
  The `bne` branch at 0x10b4 targets 0x1024, is taken when t3(=([a0+132] << 0x3)) < t8(?) (signed), and falls through when t3(=([a0+132] << 0x3)) >= t8(?) (signed).
  The `beq` branch at 0x10c8 targets 0x1024 and is always taken.
  The `beq` branch at 0x10d4 targets 0xf94 and is always taken.
  The return at 0xfb0 has v0 = ?.

- `ioc3_write` in `IP30/usr/cpu/sysgen/IP30boot/sduart.a(sio_ioc3.o)` at 0x10dc (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/sduart.a(sio_ioc3.o)`.
  Range: 0x10dc-0x10f8 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x10e4 calls do_ioc3_write with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x10f0 has v0 = ret(do_ioc3_write).

- `ioc3_sync_write` in `IP30/usr/cpu/sysgen/IP30boot/sduart.a(sio_ioc3.o)` at 0x10f8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/sduart.a(sio_ioc3.o)`.
  Range: 0x10f8-0x115c (100 bytes).
  It occupies 100 bytes.
  The `lw` at 0x1128 loads 4 bytes from a0 (arg0 at entry) +0x78.
  The `jal` at 0x110c calls do_ioc3_write with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x113c calls ioc3_enable_tx with a0=a0 at entry (arg0), a1=0x1, a2=?, a3=?.
  The `blez` branch at 0x1114 targets 0x1144, is taken when s3(=a2) <= 0 (signed), and falls through when s3(=a2) > 0 (signed).
  The `bne` branch at 0x111c targets 0x1148, is taken when v0(=ret(do_ioc3_write)) != 0, and falls through when v0(=ret(do_ioc3_write)) == 0.
  The `beq` branch at 0x1130 targets 0x1148, is taken when (at(=[a0+120]) & 0x10) == 0, and falls through when (at(=[a0+120]) & 0x10) != 0.
  The return at 0x1154 has v0 = ret(do_ioc3_write).

- `ioc3_wrflush` in `IP30/usr/cpu/sysgen/IP30boot/sduart.a(sio_ioc3.o)` at 0x115c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/sduart.a(sio_ioc3.o)`.
  Range: 0x115c-0x1220 (196 bytes).
  It occupies 196 bytes.
  3 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x38, including `ld` at 0x115c, `ld` at 0x1198, `ld` at 0x11e0.
  3 such `lw` accesses load 4 bytes from [a0+56]:8 +0x1c, including `lw` at 0x1160, `lw` at 0x119c, `lw` at 0x11e4.
  3 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x40, including `ld` at 0x117c, `ld` at 0x11d4, `ld` at 0x11fc.
  2 such `lw` accesses load 4 bytes from [a0+64]:8 +0x0, including `lw` at 0x1180, `lw` at 0x1200.
  The `lw` at 0x11b8 loads 4 bytes from a0 (arg0 at entry) +0x78.
  The `jal` at 0x11c8 calls ioc3_enable_tx with a0=a0 at entry (arg0), a1=0x1, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x11f4 calls us_delay with a0=0x5, a1=?, a2=one of 0x10000000, 0x50000000, a3=?.
  The `beq` branch at 0x1174 targets 0x11b8, is taken when (at(=[[a0+56]:8+28]) & 0x1) == 0, and falls through when (at(=[[a0+56]:8+28]) & 0x1) != 0.
  The `bne` branch at 0x1190 targets 0x11ac, is taken when a0(=0x10000000) != v0(?), and falls through when a0(=0x10000000) == v0(?).
  The `beq` branch at 0x11a4 targets 0x11d8, is taken when (v1(=[[a0+56]:8+28]) & 0x1) == 0, and falls through when (v1(=[[a0+56]:8+28]) & 0x1) != 0.
  The `beq` branch at 0x11c0 targets 0x117c, is taken when (a0(=[a0+120]) & 0x10) == 0, and falls through when (a0(=[a0+120]) & 0x10) != 0.
  The `beq` branch at 0x11d0 targets 0x1180 and is always taken.
  The `beq` branch at 0x11d8 targets 0x11f4 and is always taken.
  The `bne` branch at 0x11ec targets 0x1218, is taken when (a1(=[[a0+56]:8+28]) & 0x1) != 0, and falls through when (a1(=[[a0+56]:8+28]) & 0x1) == 0.
  The `beq` branch at 0x1210 targets 0x11e0, is taken when a2(=0x10000000) == a3(?), and falls through when a2(=0x10000000) != a3(?).
  The `beq` branch at 0x1218 targets 0x11ac and is always taken.
  The return at 0x11b0 has v0 = one of ?, ret(us_delay).

- `ioc3_break` in `IP30/usr/cpu/sysgen/IP30boot/sduart.a(sio_ioc3.o)` at 0x1220 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/sduart.a(sio_ioc3.o)`.
  Range: 0x1220-0x12d0 (176 bytes).
  It occupies 176 bytes.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x94, including `lw` at 0x1220, `lw` at 0x129c.
  3 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x40, including `ld` at 0x1234, `ld` at 0x1244, `ld` at 0x12ac.
  2 such `sw` accesses store 4 bytes to [a0+64]:8 +0x0, including `sw` at 0x1240, `sw` at 0x12b0.
  2 such `lw` accesses load 4 bytes from [a0+64]:8 +0x0, including `lw` at 0x1248, `lw` at 0x1274.
  The `ld` at 0x1288 loads 8 bytes from a0 (arg0 at entry) +0x48.
  The `lbu` at 0x1290 loads 1 byte from [a0+72]:8 +0x3.
  2 such `sb` accesses store 1 byte to [a0+72]:8 +0x3, including `sb` at 0x1298, `sb` at 0x12cc.
  The `bgez` branch at 0x1228 targets 0x1288, is taken when at(=([a0+148] << 0x23)) >= 0 (signed), and falls through when at(=([a0+148] << 0x23)) < 0 (signed).
  The `bltz` branch at 0x125c targets 0x1288, is taken when t1(=([[a0+64]:8] << 0x21)) < 0 (signed), and falls through when t1(=([[a0+64]:8] << 0x21)) >= 0 (signed).
  The `bne` branch at 0x126c targets 0x12b8, is taken when t3(?) != 0, and falls through when t3(?) == 0.
  The `beq` branch at 0x1280 targets 0x126c, is taken when (t8(=[[a0+64]:8]) & a7(=0x40000000)) == 0, and falls through when (t8(=[[a0+64]:8]) & a7(=0x40000000)) != 0.
  The `beq` branch at 0x128c targets 0x12c0, is taken when a1 == 0, and falls through when a1 != 0.
  The `beq` branch at 0x12a4 targets 0x12b8, is taken when (t0(=0x10000000) & a4(=[a0+148])) == 0, and falls through when (t0(=0x10000000) & a4(=[a0+148])) != 0.
  The `beq` branch at 0x12c8 targets 0x129c and is always taken.
  The return at 0x12b8 has v0 = one of -0x1, 0x0.

- `ioc3_enable_tx` in `IP30/usr/cpu/sysgen/IP30boot/sduart.a(sio_ioc3.o)` at 0x12d0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/sduart.a(sio_ioc3.o)`.
  Range: 0x12d0-0x1410 (320 bytes).
  It occupies 320 bytes.
  The `ld` at 0x12d0 loads 8 bytes from a0 (arg0 at entry) +0x70.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x78, including `lw` at 0x12d8, `lw` at 0x135c.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x94, including `lw` at 0x12f8, `lw` at 0x1388.
  4 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x40, including `ld` at 0x1304, `ld` at 0x1318, `ld` at 0x139c.
  2 such `sw` accesses store 4 bytes to [a0+64]:8 +0x0, including `sw` at 0x1314, `sw` at 0x13a0.
  2 such `lw` accesses load 4 bytes from [a0+64]:8 +0x0, including `lw` at 0x131c, `lw` at 0x1348.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x98, including `lw` at 0x1368, `lw` at 0x13e8.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x78, including `sw` at 0x1374, `sw` at 0x13d0.
  2 such `sw` accesses store 4 bytes to [a0+64]:8 +0x4, including `sw` at 0x1378, `sw` at 0x1404.
  2 such `lw` accesses load 4 bytes from [a0+112]:8 +0x8, including `lw` at 0x1384, `lw` at 0x13d8.
  The `lw` at 0x13c8 loads 4 bytes from [a0+64]:8 +0x8.
  The `jal` at 0x1380 calls enable_intrs with a0=a0 at entry (arg0), a1=[[a0+112]:8+8], a2=a2 at entry (arg2), a3=a3 at entry (arg3), a4=[a0+64]:8, a5=[a0+112]:8.
  The `jal` at 0x13e0 calls disable_intrs with a0=a0 at entry (arg0), a1=[[a0+112]:8+8], a2=a2 at entry (arg2), a3=a3 at entry (arg3), a4=[a0+64]:8, a5=[a0+112]:8.
  The `beq` branch at 0x12e8 targets 0x13b8, is taken when a1 == 0, and falls through when a1 != 0.
  The `beq` branch at 0x12f0 targets 0x13c0, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `bgez` branch at 0x1300 targets 0x1360, is taken when at(=([a0+148] << 0x23)) >= 0 (signed), and falls through when at(=([a0+148] << 0x23)) < 0 (signed).
  The `bltz` branch at 0x1330 targets 0x135c, is taken when t1(=([[a0+64]:8] << 0x21)) < 0 (signed), and falls through when t1(=([[a0+64]:8] << 0x21)) >= 0 (signed).
  The `bne` branch at 0x1340 targets 0x1408, is taken when t3(?) != 0, and falls through when t3(?) == 0.
  The `beq` branch at 0x1354 targets 0x1340, is taken when (t8(=[[a0+64]:8]) & a7(=0x40000000)) == 0, and falls through when (t8(=[[a0+64]:8]) & a7(=0x40000000)) != 0.
  The `beq` branch at 0x1360 targets 0x13c8, is taken when a1 == 0, and falls through when a1 != 0.
  The `beq` branch at 0x1394 targets 0x13a8, is taken when (at(=0x10000000) & a0(=[a0+148])) == 0, and falls through when (at(=0x10000000) & a0(=[a0+148])) != 0.
  The `beq` branch at 0x13b8 targets 0x12f8, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0x13c0 targets 0x13a8 and is always taken.
  The `beq` branch at 0x13f4 targets 0x1388, is taken when a1(=[a0+152]) == v0(?), and falls through when a1(=[a0+152]) != v0(?).
  The `beq` branch at 0x1400 targets 0x1388 and is always taken.
  The `beq` branch at 0x1408 targets 0x13ac and is always taken.
  The return at 0x13b0 has v0 = one of -0x1, 0x0.

- `ioc3_notification` in `IP30/usr/cpu/sysgen/IP30boot/sduart.a(sio_ioc3.o)` at 0x18c4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/sduart.a(sio_ioc3.o)`.
  Range: 0x18c4-0x19fc (312 bytes).
  It occupies 312 bytes.
  The `ld` at 0x18cc loads 8 bytes from a0 (arg0 at entry) +0x70.
  The `lw` at 0x18f4 loads 4 bytes from [a0+112]:8 +0x10.
  The `lw` at 0x18f8 loads 4 bytes from [a0+112]:8 +0xc.
  The `lw` at 0x190c loads 4 bytes from [a0+112]:8 +0x14.
  The `lw` at 0x1920 loads 4 bytes from [a0+112]:8 +0x0.
  The `lw` at 0x1934 loads 4 bytes from [a0+112]:8 +0x4.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x94, including `lw` at 0x1948, `lw` at 0x19d0.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x8c, including `lw` at 0x194c, `lw` at 0x19d4.
  4 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x94, including `sw` at 0x1954, `sw` at 0x1980, `sw` at 0x19bc.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x8c, including `sw` at 0x195c, `sw` at 0x19f0.
  The `ld` at 0x1988 loads 8 bytes from a0 (arg0 at entry) +0x40.
  The `sw` at 0x1998 stores 4 bytes to [a0+64]:8 +0x0.
  The `lw` at 0x199c loads 4 bytes from a0 (arg0 at entry) +0x90.
  The `lw` at 0x19a0 loads 4 bytes from [a0+112]:8 +0x8.
  The `jal` at 0x1940 calls enable_intrs with a0=a0 at entry (arg0), a1=?, a2=a2 at entry (arg2), a3=?.
  The `jal` at 0x19c8 calls disable_intrs with a0=a0 at entry (arg0), a1=?, a2=a2 at entry (arg2), a3=?.
  The `beq` branch at 0x18ec targets 0x1900, is taken when (a1 & 0x1) == 0, and falls through when (a1 & 0x1) != 0.
  The `beq` branch at 0x1904 targets 0x1918, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0x1918 targets 0x19f4, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x192c targets 0x19c0, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0x1938 targets 0x19c8, is taken when a2 == 0, and falls through when a2 != 0.
  The `beq` branch at 0x1974 targets 0x199c, is taken when (a1(?) & 0x41) == 0, and falls through when (a1(?) & 0x41) != 0.
  The `bne` branch at 0x19a8 targets 0x1988, is taken when (a4(=[[a0+112]:8+8]) & a5(=[a0+144])) != 0, and falls through when (a4(=[[a0+112]:8+8]) & a5(=[a0+144])) == 0.
  The `beq` branch at 0x19b8 targets 0x1984 and is always taken.
  The `bne` branch at 0x19c0 targets 0x1940, is taken when a2 != 0, and falls through when a2 == 0.
  The `beq` branch at 0x19ec targets 0x1960 and is always taken.
  The `beq` branch at 0x19f4 targets 0x192c and is always taken.
  The return at 0x1994 has v0 = 0x0.

- `ioc3_rx_timeout` in `IP30/usr/cpu/sysgen/IP30boot/sduart.a(sio_ioc3.o)` at 0x19fc (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/sduart.a(sio_ioc3.o)`.
  Range: 0x19fc-0x1abc (192 bytes).
  It occupies 192 bytes.
  The `lw` at 0x19fc loads 4 bytes from a0 (arg0 at entry) +0x80.
  The `sw` at 0x1a6c stores 4 bytes to a0 (arg0 at entry) +0x88.
  The `lw` at 0x1a88 loads 4 bytes from a0 (arg0 at entry) +0x94.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x40, including `ld` at 0x1a8c, `ld` at 0x1aa0.
  The `sw` at 0x1a98 stores 4 bytes to a0 (arg0 at entry) +0x94.
  The `sw` at 0x1a9c stores 4 bytes to [a0+64]:8 +0x0.
  The `sw` at 0x1ab0 stores 4 bytes to [a0+64]:8 +0x14.
  The `bne` branch at 0x1a74 targets 0x1a84, is taken when a4(?) < 0x200 (unsigned), and falls through when a4(?) >= 0x200 (unsigned).
  The return at 0x1a7c has v0 = 0x1.
  The return at 0x1ab4 has v0 = 0x0.

- `set_DTRRTS` in `IP30/usr/cpu/sysgen/IP30boot/sduart.a(sio_ioc3.o)` at 0x1abc (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/sduart.a(sio_ioc3.o)`.
  Range: 0x1abc-0x1b80 (196 bytes).
  It occupies 196 bytes.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x94, including `lw` at 0x1abc, `lw` at 0x1b48.
  4 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x40, including `ld` at 0x1ac4, `ld` at 0x1ae0, `ld` at 0x1b40.
  2 such `sw` accesses store 4 bytes to [a0+64]:8 +0x0, including `sw` at 0x1adc, `sw` at 0x1b60.
  2 such `lw` accesses load 4 bytes from [a0+64]:8 +0x0, including `lw` at 0x1ae4, `lw` at 0x1b10.
  The `ld` at 0x1b24 loads 8 bytes from a0 (arg0 at entry) +0x48.
  The `lw` at 0x1b28 loads 4 bytes from [a0+64]:8 +0x18.
  The `lbu` at 0x1b30 loads 1 byte from [a0+72]:8 +0x4.
  The `sb` at 0x1b3c stores 1 byte to [a0+72]:8 +0x4.
  The `sw` at 0x1b44 stores 4 bytes to [a0+64]:8 +0x18.
  The `bgez` branch at 0x1ac8 targets 0x1b24, is taken when at(=([a0+148] << 0x23)) >= 0 (signed), and falls through when at(=([a0+148] << 0x23)) < 0 (signed).
  The `bltz` branch at 0x1af8 targets 0x1b24, is taken when t8(=([[a0+64]:8] << 0x21)) < 0 (signed), and falls through when t8(=([[a0+64]:8] << 0x21)) >= 0 (signed).
  The `bne` branch at 0x1b08 targets 0x1b64, is taken when at(?) != 0, and falls through when at(?) == 0.
  The `beq` branch at 0x1b1c targets 0x1b08, is taken when (v1(=[[a0+64]:8]) & t2(=0x40000000)) == 0, and falls through when (v1(=[[a0+64]:8]) & t2(=0x40000000)) != 0.
  The `beq` branch at 0x1b2c targets 0x1b6c, is taken when a1 == 0, and falls through when a1 != 0.
  The `beq` branch at 0x1b50 targets 0x1b64, is taken when (t3(=0x10000000) & t0(=[a0+148])) == 0, and falls through when (t3(=0x10000000) & t0(=[a0+148])) != 0.
  The `beq` branch at 0x1b78 targets 0x1b3c and is always taken.
  The return at 0x1b5c has v0 = 0x0.
  The return at 0x1b64 has v0 = one of -0x1, 0x0.

- `ioc3_set_DTR` in `IP30/usr/cpu/sysgen/IP30boot/sduart.a(sio_ioc3.o)` at 0x1b80 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/sduart.a(sio_ioc3.o)`.
  Range: 0x1b80-0x1ba0 (32 bytes).
  It occupies 32 bytes.
  The `jal` at 0x1b8c calls set_DTRRTS with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0x1, a3=0x1000000.
  The return at 0x1b98 has v0 = ret(set_DTRRTS).

- `ioc3_set_RTS` in `IP30/usr/cpu/sysgen/IP30boot/sduart.a(sio_ioc3.o)` at 0x1ba0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/sduart.a(sio_ioc3.o)`.
  Range: 0x1ba0-0x1bc0 (32 bytes).
  It occupies 32 bytes.
  The `jal` at 0x1bac calls set_DTRRTS with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0x2, a3=0x2000000.
  The return at 0x1bb8 has v0 = ret(set_DTRRTS).

- `ioc3_query_DCD` in `IP30/usr/cpu/sysgen/IP30boot/sduart.a(sio_ioc3.o)` at 0x1bc0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/sduart.a(sio_ioc3.o)`.
  Range: 0x1bc0-0x1bd4 (20 bytes).
  It occupies 20 bytes.
  The `ld` at 0x1bc0 loads 8 bytes from a0 (arg0 at entry) +0x40.
  The `lw` at 0x1bc4 loads 4 bytes from [a0+64]:8 +0x18.
  The return at 0x1bcc has v0 = ?.

- `ioc3_query_CTS` in `IP30/usr/cpu/sysgen/IP30boot/sduart.a(sio_ioc3.o)` at 0x1bd4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/sduart.a(sio_ioc3.o)`.
  Range: 0x1bd4-0x1be8 (20 bytes).
  It occupies 20 bytes.
  The `ld` at 0x1bd4 loads 8 bytes from a0 (arg0 at entry) +0x40.
  The `lw` at 0x1bd8 loads 4 bytes from [a0+64]:8 +0x18.
  The return at 0x1be0 has v0 = ?.

- `ioc3_set_proto` in `IP30/usr/cpu/sysgen/IP30boot/sduart.a(sio_ioc3.o)` at 0x1be8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/sduart.a(sio_ioc3.o)`.
  Range: 0x1be8-0x1c3c (84 bytes).
  It occupies 84 bytes.
  The `ld` at 0x1be8 loads 8 bytes from a0 (arg0 at entry) +0x70.
  2 such `lbu` accesses load 1 byte from [a0+112]:8 +0x20, including `lbu` at 0x1c04, `lbu` at 0x1c24.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x38, including `ld` at 0x1c08, `ld` at 0x1c28.
  2 such `sw` accesses store 4 bytes to ([a0+56]:8 + ([[a0+112]:8+32]:1 << 0x2)) +0x40, including `sw` at 0x1c14, `sw` at 0x1c38.
  The `beq` branch at 0x1bec targets 0x1c04, is taken when a1 == 0, and falls through when a1 != 0.
  The `bne` branch at 0x1bf4 targets 0x1c1c, is taken when a1 != v0(=0x1), and falls through when a1 == v0(=0x1).
  The `beq` branch at 0x1bfc targets 0x1c24 and is always taken.
  The `beq` branch at 0x1c34 targets 0x1c18 and is always taken.
  The return at 0x1c1c has v0 = one of 0x0, 0x1.

- `ioc3_get_mapid` in `IP30/usr/cpu/sysgen/IP30boot/sduart.a(sio_ioc3.o)` at 0x1c3c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/sduart.a(sio_ioc3.o)`.
  Range: 0x1c3c-0x1c9c (96 bytes).
  It occupies 96 bytes.
  The `ld` at 0x1c50 loads 8 bytes from a0 (arg0 at entry) +0x70.
  The `jal` at 0x1c74 calls copyout with a0=sp-16, a1=a1 at entry (arg1), a2=0x8, a3=sym(.data).
  The `beq` branch at 0x1c44 targets 0x1c8c, is taken when a1 == 0, and falls through when a1 != 0.
  The `beq` branch at 0x1c84 targets 0x1c90 and is always taken.
  The return at 0x1c94 has v0 = one of 0x0, 0xe.

- `ioc3_map` in `IP30/usr/cpu/sysgen/IP30boot/sduart.a(sio_ioc3.o)` at 0x1c9c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/sduart.a(sio_ioc3.o)`.
  Range: 0x1c9c-0x1d2c (144 bytes).
  It occupies 144 bytes.
  The `ld` at 0x1cc8 loads 8 bytes from a0 (arg0 at entry) +0x58.
  The `ld` at 0x1cfc loads 8 bytes from a0 (arg0 at entry) +0x70.
  The `ld` at 0x1d0c loads 8 bytes from a0 (arg0 at entry) +0x38.
  The `jal` at 0x1cd0 calls disable_intrs with a0=a0 at entry (arg0), a1=-0x1, a2=?, a3=?, a5=0x16.
  The `jal` at 0x1ce0 calls v_mapphys with a0=a1 at entry (arg1), a1=?, a2=0x4000, a3=?.
  The `beq` branch at 0x1ca4 targets 0x1cc0, is taken when a2 == 0, and falls through when a2 != 0.
  The `beq` branch at 0x1cb0 targets 0x1cfc, is taken when a2 == at(=0x4000), and falls through when a2 != at(=0x4000).
  The `beq` branch at 0x1cb8 targets 0x1cf4 and is always taken.
  The `beq` branch at 0x1d24 targets 0x1cd0 and is always taken.
  The return at 0x1cf4 has v0 = one of 0x16, ret(v_mapphys).

- `ioc3_unmap` in `IP30/usr/cpu/sysgen/IP30boot/sduart.a(sio_ioc3.o)` at 0x1d2c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/sduart.a(sio_ioc3.o)`.
  Range: 0x1d2c-0x1d74 (72 bytes).
  It occupies 72 bytes.
  The `lw` at 0x1d2c loads 4 bytes from a0 (arg0 at entry) +0x94.
  3 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x40, including `ld` at 0x1d34, `ld` at 0x1d48, `ld` at 0x1d5c.
  The `sw` at 0x1d40 stores 4 bytes to a0 (arg0 at entry) +0x94.
  The `sw` at 0x1d44 stores 4 bytes to [a0+64]:8 +0x0.
  The `lw` at 0x1d4c loads 4 bytes from [a0+64]:8 +0x8.
  The `sw` at 0x1d54 stores 4 bytes to a0 (arg0 at entry) +0x98.
  The `sw` at 0x1d58 stores 4 bytes to [a0+64]:8 +0x4.
  The `lw` at 0x1d60 loads 4 bytes from [a0+64]:8 +0xc.
  The `sw` at 0x1d68 stores 4 bytes to a0 (arg0 at entry) +0x9c.
  The `sw` at 0x1d70 stores 4 bytes to [a0+64]:8 +0x10.
  The return at 0x1d6c has v0 = [a0+64]:8.

- `ioc3_set_sscr` in `IP30/usr/cpu/sysgen/IP30boot/sduart.a(sio_ioc3.o)` at 0x1d74 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/sduart.a(sio_ioc3.o)`.
  Range: 0x1d74-0x1da4 (48 bytes).
  It occupies 48 bytes.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x94, including `lw` at 0x1d74, `lw` at 0x1d94.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x94, including `sw` at 0x1d84, `sw` at 0x1da0.
  The `ld` at 0x1d88 loads 8 bytes from a0 (arg0 at entry) +0x40.
  The `sw` at 0x1d8c stores 4 bytes to [a0+64]:8 +0x0.
  The `beq` branch at 0x1d78 targets 0x1d98, is taken when a2 == 0, and falls through when a2 != 0.
  The `beq` branch at 0x1d9c targets 0x1d88 and is always taken.
  The return at 0x1d90 has v0 = [a0+148].

- `ioc3_console_write` in `IP30/usr/cpu/sysgen/IP30boot/sduart.a(sio_ioc3.o)` at 0x1da4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/sduart.a(sio_ioc3.o)`.
  Range: 0x1da4-0x1ef8 (340 bytes).
  It occupies 340 bytes.
  7 such `lw` accesses load 4 bytes from [sym(console_mem)]:8 +0xb8, including `lw` at 0x1da8, `lw` at 0x1e84, `lw` at 0x1e94.
  The `sd` at 0x1dd0 stores 8 bytes to a2 (arg2 at entry) +0x0.
  The `sb` at 0x1df8 stores 1 byte to [sym(console_mem)]:8 +0x20178.
  6 such `lbu` accesses load 1 byte from [sym(console_mem)]:8 +0x2017d, including `lbu` at 0x1dfc, `lbu` at 0x1e14, `lbu` at 0x1e24.
  The `lbu` at 0x1e08 loads 1 byte from ?.
  The `sw` at 0x1e80 stores 4 bytes to [sym(console_mem)]:8 +0xb8.
  The `bne` branch at 0x1db8 targets 0x1dd0, is taken when t0(=0x10000000) != t2(?), and falls through when t0(=0x10000000) == t2(?).
  The `beq` branch at 0x1dc8 targets 0x1eec and is always taken.
  The `bne` branch at 0x1de4 targets 0x1dfc, is taken when a1 != 0, and falls through when a1 == 0.
  The `beq` branch at 0x1dec targets 0x1e6c and is always taken.
  The `beq` branch at 0x1df4 targets 0x1e6c, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `bne` branch at 0x1e0c targets 0x1df4, is taken when (a6(=[[sym(console_mem)]:8+131453]:1) & 0x20) != 0, and falls through when (a6(=[[sym(console_mem)]:8+131453]:1) & 0x20) == 0.
  The `bne` branch at 0x1e1c targets 0x1df4, is taken when (a7(=[[sym(console_mem)]:8+131453]:1) & 0x20) != 0, and falls through when (a7(=[[sym(console_mem)]:8+131453]:1) & 0x20) == 0.
  The `bne` branch at 0x1e2c targets 0x1df4, is taken when (t0(=[[sym(console_mem)]:8+131453]:1) & 0x20) != 0, and falls through when (t0(=[[sym(console_mem)]:8+131453]:1) & 0x20) == 0.
  The `bne` branch at 0x1e3c targets 0x1df4, is taken when (t1(=[[sym(console_mem)]:8+131453]:1) & 0x20) != 0, and falls through when (t1(=[[sym(console_mem)]:8+131453]:1) & 0x20) == 0.
  The `bne` branch at 0x1e4c targets 0x1df4, is taken when (t2(=[[sym(console_mem)]:8+131453]:1) & 0x20) != 0, and falls through when (t2(=[[sym(console_mem)]:8+131453]:1) & 0x20) == 0.
  The `beq` branch at 0x1e5c targets 0x1e14, is taken when (t3(=[[sym(console_mem)]:8+131453]:1) & 0x20) == 0, and falls through when (t3(=[[sym(console_mem)]:8+131453]:1) & 0x20) != 0.
  The `beq` branch at 0x1e64 targets 0x1df4 and is always taken.
  The `bne` branch at 0x1e78 targets 0x1dd0, is taken when t0(=0x10000000) != t8(?), and falls through when t0(=0x10000000) == t8(?).
  The `bne` branch at 0x1e8c targets 0x1e78, is taken when a5(=0x30000000) != t9(?), and falls through when a5(=0x30000000) == t9(?).
  The `bne` branch at 0x1e9c targets 0x1e74, is taken when a5(=0x30000000) != v0(?), and falls through when a5(=0x30000000) == v0(?).
  The `bne` branch at 0x1eac targets 0x1e74, is taken when a5(=0x30000000) != v1(?), and falls through when a5(=0x30000000) == v1(?).
  The `bne` branch at 0x1ebc targets 0x1e74, is taken when a5(=0x30000000) != a3(?), and falls through when a5(=0x30000000) == a3(?).
  The `bne` branch at 0x1ecc targets 0x1e74, is taken when a5(=0x30000000) != t3(?), and falls through when a5(=0x30000000) == t3(?).
  The `beq` branch at 0x1edc targets 0x1e94, is taken when a5(=0x30000000) == t8(?), and falls through when a5(=0x30000000) != t8(?).
  The `beq` branch at 0x1ee4 targets 0x1e74 and is always taken.
  The `beq` branch at 0x1ef0 targets 0x1e80 and is always taken.
  The return at 0x1e6c has v0 = 0x0.

- `console_debug_poll` in `IP30/usr/cpu/sysgen/IP30boot/sduart.a(sio_ioc3.o)` at 0x1ef8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/sduart.a(sio_ioc3.o)`.
  Range: 0x1ef8-0x1fd0 (216 bytes).
  It occupies 216 bytes.
  7 such `lw` accesses load 4 bytes from [sym(console_mem)]:8 +0xb8, including `lw` at 0x1efc, `lw` at 0x1f54, `lw` at 0x1f64.
  The `lbu` at 0x1f28 loads 1 byte from [sym(console_mem)]:8 +0x2017d.
  The `lbu` at 0x1f38 loads 1 byte from [sym(console_mem)]:8 +0x20178.
  The `sw` at 0x1f50 stores 4 bytes to [sym(console_mem)]:8 +0xb8.
  The `jal` at 0x1fc0 calls debug with a0=sym(.rodata), a1=[sym(console_mem)]:8+131072, a2=[sym(console_mem)]:8+184, a3=[sym(console_mem)]:8, a4=0x20000, a5=([[sym(console_mem)]:8+184] << 0x21), a6=[[sym(console_mem)]:8+184].
  The `bgez` branch at 0x1f14 targets 0x1f24, is taken when at(=([[sym(console_mem)]:8+184] << 0x23)) >= 0 (signed), and falls through when at(=([[sym(console_mem)]:8+184] << 0x23)) < 0 (signed).
  The `bgez` branch at 0x1f1c targets 0x1f4c, is taken when a5(=([[sym(console_mem)]:8+184] << 0x21)) >= 0 (signed), and falls through when a5(=([[sym(console_mem)]:8+184] << 0x21)) < 0 (signed).
  The `beq` branch at 0x1f30 targets 0x1f44, is taken when (v0(=[[sym(console_mem)]:8+131453]:1) & 0x1) == 0, and falls through when (v0(=[[sym(console_mem)]:8+131453]:1) & 0x1) != 0.
  The `beq` branch at 0x1f3c targets 0x1fbc, is taken when v1(=[[sym(console_mem)]:8+131448]:1) == a0(=0x1), and falls through when v1(=[[sym(console_mem)]:8+131448]:1) != a0(=0x1).
  The `bltz` branch at 0x1f5c targets 0x1fb4, is taken when a5(=([[sym(console_mem)]:8+184] << 0x21)) < 0 (signed), and falls through when a5(=([[sym(console_mem)]:8+184] << 0x21)) >= 0 (signed).
  The `bne` branch at 0x1f6c targets 0x1fb4, is taken when (t0(=[[sym(console_mem)]:8+184]) & a1(=0x40000000)) != 0, and falls through when (t0(=[[sym(console_mem)]:8+184]) & a1(=0x40000000)) == 0.
  The `bne` branch at 0x1f7c targets 0x1fb4, is taken when (t1(=[[sym(console_mem)]:8+184]) & a1(=0x40000000)) != 0, and falls through when (t1(=[[sym(console_mem)]:8+184]) & a1(=0x40000000)) == 0.
  The `bne` branch at 0x1f8c targets 0x1fb4, is taken when (t2(=[[sym(console_mem)]:8+184]) & a1(=0x40000000)) != 0, and falls through when (t2(=[[sym(console_mem)]:8+184]) & a1(=0x40000000)) == 0.
  The `bne` branch at 0x1f9c targets 0x1fb4, is taken when (t3(=[[sym(console_mem)]:8+184]) & a1(=0x40000000)) != 0, and falls through when (t3(=[[sym(console_mem)]:8+184]) & a1(=0x40000000)) == 0.
  The `beq` branch at 0x1fac targets 0x1f64, is taken when (t8(=[[sym(console_mem)]:8+184]) & a1(=0x40000000)) == 0, and falls through when (t8(=[[sym(console_mem)]:8+184]) & a1(=0x40000000)) != 0.
  The `beq` branch at 0x1fb4 targets 0x1f28 and is always taken.
  The `beq` branch at 0x1fc8 targets 0x1f44 and is always taken.
  The return at 0x1f44 has v0 = one of ?, ret(debug).
