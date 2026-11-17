# Readings: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc4.o)`

One entry per routine, filed here from the reading batches by binary.

- `ioc4_sio_mlreset` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc4.o)` at 0x0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc4.o)`.
  Range: 0x0-0x2c (44 bytes).
  It occupies 44 bytes.
  The `jal` at 0x18 calls sio_console_register with a0=sp-32, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x24 has v0 = ret(sio_console_register).

- `ring_dmatrans` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc4.o)` at 0x2c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc4.o)`.
  Range: 0x2c-0x7c (80 bytes).
  It occupies 80 bytes.
  The `jal` at 0x58 calls pciio_dma_addr with a0=a0 at entry (arg0), a1=0x0, a2=?, a3=0x4000, a4=0x0, a5=0x0.
  The `beq` branch at 0x40 targets 0x6c, is taken when a0 == at(=-0x1), and falls through when a0 != at(=-0x1).
  The `beq` branch at 0x64 targets 0x70 and is always taken.
  The return at 0x74 has v0 = one of ret(pciio_dma_addr), ?.

- `mask_disable_intrs` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc4.o)` at 0x7c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc4.o)`.
  Range: 0x7c-0x90 (20 bytes).
  It occupies 20 bytes.
  The `lw` at 0x7c loads 4 bytes from a0 (arg0 at entry) +0x88.
  The `sw` at 0x8c stores 4 bytes to a0 (arg0 at entry) +0x88.
  The return at 0x88 has v0 = ?.

- `enable_intrs` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc4.o)` at 0x90 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc4.o)`.
  Range: 0x90-0x110 (128 bytes).
  It occupies 128 bytes.
  The `ld` at 0x90 loads 8 bytes from a0 (arg0 at entry) +0x68.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x88, including `lw` at 0x98, `lw` at 0xfc.
  The `lw` at 0xc4 loads 4 bytes from [a0+104]:8 +0x18.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x98, including `ld` at 0xd0, `ld` at 0xe4.
  The `sw` at 0x10c stores 4 bytes to a0 (arg0 at entry) +0x88.
  The `jal` at 0xcc calls ioc4_write_ireg with a0=[a0+152]:8, a1=[[a0+104]:8+24], a2=0x0, a3=0x1, a5=[a0+104]:8.
  The `jal` at 0xf0 calls ioc4_write_ireg with a0=[a0+152]:8, a1=a1 at entry (arg1), a2=0x0, a3=0x0, a5=[a0+104]:8.
  The `bne` branch at 0xb0 targets 0xe4, is taken when a1 != at(?), and falls through when a1 == at(?).
  The `beq` branch at 0xb8 targets 0xd8, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0x108 targets 0xb8 and is always taken.
  The return at 0xdc has v0 = one of ?, ret(ioc4_write_ireg).

- `disable_intrs` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc4.o)` at 0x110 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc4.o)`.
  Range: 0x110-0x194 (132 bytes).
  It occupies 132 bytes.
  The `ld` at 0x110 loads 8 bytes from a0 (arg0 at entry) +0x68.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x88, including `lw` at 0x118, `lw` at 0x14c.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x98, including `ld` at 0x140, `ld` at 0x17c.
  The `sw` at 0x158 stores 4 bytes to a0 (arg0 at entry) +0x88.
  The `lw` at 0x188 loads 4 bytes from [a0+104]:8 +0x18.
  The `jal` at 0x144 calls ioc4_write_ireg with a0=[a0+152]:8, a1=a1 at entry (arg1), a2=0x1, a3=0x0.
  The `jal` at 0x184 calls ioc4_write_ireg with a0=[a0+152]:8, a1=[[a0+104]:8+24], a2=0x1, a3=0x1.
  The `beq` branch at 0x134 targets 0x15c, is taken when (a3(=[a0+136]) & a1) == 0, and falls through when (a3(=[a0+136]) & a1) != 0.
  The `beq` branch at 0x15c targets 0x174, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0x18c targets 0x168 and is always taken.
  The return at 0x16c has v0 = one of ?, ret(ioc4_write_ireg).

- `ioc4_serial_intr` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc4.o)` at 0x194 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc4.o)`.
  Range: 0x194-0x734 (1440 bytes).
  It occupies 1440 bytes.
  The `ld` at 0x1a8 loads 8 bytes from a0 (arg0 at entry) +0x68.
  4 such `lw` accesses load 4 bytes from [a0+104]:8 +0x8, including `lw` at 0x1b0, `lw` at 0x480, `lw` at 0x4b8.
  3 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x40, including `ld` at 0x1fc, `ld` at 0x340, `ld` at 0x668.
  6 such `ld` accesses load 8 bytes from abs 0xa800000000001000, including `ld` at 0x200, `ld` at 0x32c, `ld` at 0x344.
  2 such `lw` accesses load 4 bytes from [a0+64]:8 +0x18, including `lw` at 0x208, `lw` at 0x34c.
  9 such `ld` accesses load 8 bytes from abs 0xa800000000001020, including `ld` at 0x20c, `ld` at 0x334, `ld` at 0x350.
  9 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x84, including `lw` at 0x218, `lw` at 0x260, `lw` at 0x2b0.
  6 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x8, including `ld` at 0x22c, `ld` at 0x270, `ld` at 0x2c0.
  2 such `ld` accesses load 8 bytes from [a0+8]:8 +0x20, including `ld` at 0x238, `ld` at 0x54c.
  2 such `lw` accesses load 4 bytes from [a0+104]:8 +0xc, including `lw` at 0x248, `lw` at 0x560.
  7 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x38, including `ld` at 0x258, `ld` at 0x29c, `ld` at 0x2dc.
  4 such `sw` accesses store 4 bytes to [a0+56]:8 +0x8, including `sw` at 0x25c, `sw` at 0x2ac, `sw` at 0x324.
  2 such `ld` accesses load 8 bytes from [a0+8]:8 +0x0, including `ld` at 0x27c, `ld` at 0x438.
  2 such `lw` accesses load 4 bytes from [a0+104]:8 +0x14, including `lw` at 0x288, `lw` at 0x2a8.
  4 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x70, including `lw` at 0x298, `lw` at 0x468, `lw` at 0x564.
  3 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x70, including `sw` at 0x2a4, `sw` at 0x570, `sw` at 0x6a0.
  2 such `ld` accesses load 8 bytes from [a0+8]:8 +0x8, including `ld` at 0x2cc, `ld` at 0x4ac.
  5 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x88, including `lw` at 0x2d8, `lw` at 0x44c, `lw` at 0x4c0.
  3 such `lw` accesses load 4 bytes from [a0+56]:8 +0x8, including `lw` at 0x2e4, `lw` at 0x450, `lw` at 0x4c4.
  The `lw` at 0x2e8 loads 4 bytes from [a0+104]:8 +0x20.
  3 such `lw` accesses load 4 bytes from [a0+104]:8 +0x10, including `lw` at 0x2f4, `lw` at 0x40c, `lw` at 0x444.
  The `lw` at 0x310 loads 4 bytes from [a0+104]:8 +0x0.
  The `ld` at 0x380 loads 8 bytes from [a0+8]:8 +0x18.
  The `lw` at 0x390 loads 4 bytes from [a0+104]:8 +0x4.
  6 such `lw` accesses load 4 bytes from [0xa800000000001020]:8 +0x0, including `lw` at 0x3c8, `lw` at 0x57c, `lw` at 0x5c8.
  9 such `ld` accesses load 8 bytes from [0xa800000000001020]:8 +0x80, including `ld` at 0x3d8, `ld` at 0x3f0, `ld` at 0x58c.
  The `ld` at 0x518 loads 8 bytes from a0 (arg0 at entry) +0x98.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x8c, including `lw` at 0x640, `lw` at 0x6e8.
  The `sw` at 0x650 stores 4 bytes to a0 (arg0 at entry) +0x8c.
  The `sw` at 0x66c stores 4 bytes to [a0+64]:8 +0x0.
  The `jal` at 0x1d0 calls sio_lock_port with a0=a0 at entry (arg0), a1=0x0, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x240 calls (unknown callee) with a0=a0 at entry (arg0), a1=0x1, a2=?, a3=?.
  The `jalr` at 0x280 calls (unknown callee) with a0=a0 at entry (arg0), a1=[[a0+8]:8]:8, a2=?, a3=?.
  The `jalr` at 0x2d0 calls (unknown callee) with a0=a0 at entry (arg0), a1=?, a2=?, a3=?, a4=[[a0+104]:8+20], a5=[a0+56]:8, a7=[[a0+8]:8+8]:8.
  The `jalr` at 0x388 calls (unknown callee) with a0=a0 at entry (arg0), a1=0x1, a2=?, a3=?.
  The `jal` at 0x3e4 calls spl7 with a0=[sym(the_console_port)]:8, a1=[[0xa800000000001020]:8+128]:8, a2=?, a3=?, a4=[0xa800000000001000]:8.
  The `jalr` at 0x3f8 calls (unknown callee) with a0=0x0, a1=?, a2=[[0xa800000000001020]:8+128]:8, a3=?.
  The `jalr` at 0x43c calls (unknown callee) with a0=a0 at entry (arg0), a1=[[a0+104]:8+16], a2=?, a3=?, a5=[[a0+8]:8]:8.
  The `jalr` at 0x4b0 calls (unknown callee) with a0=a0 at entry (arg0), a1=[[a0+104]:8+8], a2=?, a3=?.
  The `jal` at 0x4e8 calls mask_disable_intrs with a0=a0 at entry (arg0), a1=[[a0+104]:8+8], a2=?, a3=?.
  The `jal` at 0x4f8 calls sio_unlock_port with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x524 calls ioc4_write_ireg with a0=[a0+152]:8, a1=[a0+136], a2=0x0, a3=0x0.
  The `jalr` at 0x554 calls (unknown callee) with a0=a0 at entry (arg0), a1=0x0, a2=[[a0+8]:8+32]:8, a3=?.
  The `jal` at 0x598 calls spl7 with a0=[sym(the_console_port)]:8, a1=[[a0+104]:8], a2=?, a3=[a0+56]:8, a4=0xfffffffffeeddead, a5=[[0xa800000000001020]:8+128]:8.
  The `jalr` at 0x5ac calls (unknown callee) with a0=0x0, a1=?, a2=?, a3=?, a6=[[0xa800000000001020]:8+128]:8.
  The `jalr` at 0x5e8 calls (unknown callee) with a0=0x1, a1=[[0xa800000000001020]:8+128]:8, a2=?, a3=?, a7=0xfffffffffeeddead.
  The `jal` at 0x5f0 calls splx with a0=[sym(.sbss)], a1=?, a2=?, a3=?.
  The `jalr` at 0x628 calls (unknown callee) with a0=0x1, a1=[[0xa800000000001020]:8+128]:8, a2=?, a3=?.
  The `jal` at 0x630 calls splx with a0=[sym(.sbss)], a1=?, a2=?, a3=?.
  The `jal` at 0x68c calls mask_disable_intrs with a0=a0 at entry (arg0), a1=[[a0+104]:8+16], a2=?, a3=?.
  The `jal` at 0x6cc calls spl7 with a0=?, a1=[a0+140], a2=?, a3=?, a4=0xfffffffffeeddead, a5=[[0xa800000000001020]:8+128]:8.
  The `jalr` at 0x6e0 calls (unknown callee) with a0=0x0, a1=?, a2=?, a3=?, a6=[[0xa800000000001020]:8+128]:8.
  The `jalr` at 0x71c calls (unknown callee) with a0=0x1, a1=[[0xa800000000001020]:8+128]:8, a2=[a0+64]:8, a3=?, a7=0xfffffffffeeddead.
  The `jal` at 0x724 calls splx with a0=[sym(.sbss)], a1=?, a2=?, a3=?.
  The `beq` branch at 0x1f4 targets 0x310 and is always taken.
  The `bne` branch at 0x204 targets 0x218, is taken when s0(=a0) != a0(=[sym(the_console_port)]:8), and falls through when s0(=a0) == a0(=[sym(the_console_port)]:8).
  The `beq` branch at 0x210 targets 0x600, is taken when s6(=0x53435241) == a1(=[0xa800000000001000]:8), and falls through when s6(=0x53435241) != a1(=[0xa800000000001000]:8).
  The `beq` branch at 0x220 targets 0x248, is taken when (t8(=[a0+132]) & 0x80) == 0, and falls through when (t8(=[a0+132]) & 0x80) != 0.
  The `beq` branch at 0x228 targets 0x544, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x230 targets 0x248, is taken when v0(=[a0+8]:8) == 0, and falls through when v0(=[a0+8]:8) != 0.
  The `beq` branch at 0x250 targets 0x40c, is taken when (v0(=[[a0+104]:8+12]) & s1(?)) == 0, and falls through when (v0(=[[a0+104]:8+12]) & s1(?)) != 0.
  The `beq` branch at 0x268 targets 0x288, is taken when (at(=[a0+132]) & 0x1) == 0, and falls through when (at(=[a0+132]) & 0x1) != 0.
  The `beq` branch at 0x274 targets 0x288, is taken when v0(=[a0+8]:8) == 0, and falls through when v0(=[a0+8]:8) != 0.
  The `beq` branch at 0x290 targets 0x480, is taken when (a2(=[[a0+104]:8+20]) & s1(?)) == 0, and falls through when (a2(=[[a0+104]:8+20]) & s1(?)) != 0.
  The `beq` branch at 0x2b8 targets 0x2d8, is taken when (a3(=[a0+132]) & 0x2) == 0, and falls through when (a3(=[a0+132]) & 0x2) != 0.
  The `beq` branch at 0x2c4 targets 0x2d8, is taken when v0(=[a0+8]:8) == 0, and falls through when v0(=[a0+8]:8) != 0.
  The `beq` branch at 0x2ec targets 0x304, is taken when t9(?) == 0, and falls through when t9(?) != 0.
  The `bne` branch at 0x2f8 targets 0x304, is taken when a0(=[[a0+104]:8+16]) != s1(?), and falls through when a0(=[[a0+104]:8+16]) == s1(?).
  The `beq` branch at 0x308 targets 0x4f8, is taken when (v0(=[[a0+104]:8+32]) & s1(?)) == 0, and falls through when (v0(=[[a0+104]:8+32]) & s1(?)) != 0.
  The `beq` branch at 0x318 targets 0x390, is taken when (a1(=[[a0+104]:8]) & s1(?)) == 0, and falls through when (a1(=[[a0+104]:8]) & s1(?)) != 0.
  The `bne` branch at 0x330 targets 0x340, is taken when s0(=a0) != a0(=[sym(the_console_port)]:8), and falls through when s0(=a0) == a0(=[sym(the_console_port)]:8).
  The `beq` branch at 0x338 targets 0x574, is taken when s6(=0x53435241) == a4(=[0xa800000000001000]:8), and falls through when s6(=0x53435241) != a4(=[0xa800000000001000]:8).
  The `bne` branch at 0x348 targets 0x35c, is taken when s0(=a0) != a0(=[sym(the_console_port)]:8), and falls through when s0(=a0) == a0(=[sym(the_console_port)]:8).
  The `beq` branch at 0x354 targets 0x5c0, is taken when s6(=0x53435241) == a1(=[0xa800000000001000]:8), and falls through when s6(=0x53435241) != a1(=[0xa800000000001000]:8).
  The `beq` branch at 0x364 targets 0x390, is taken when (t8(=[a0+132]) & 0x40) == 0, and falls through when (t8(=[a0+132]) & 0x40) != 0.
  The `beq` branch at 0x36c targets 0x564, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x378 targets 0x390, is taken when v0(=[a0+8]:8) == 0, and falls through when v0(=[a0+8]:8) != 0.
  The `beq` branch at 0x398 targets 0x248, is taken when (a1(=[[a0+104]:8+4]) & s1(?)) == 0, and falls through when (a1(=[[a0+104]:8+4]) & s1(?)) != 0.
  The `bne` branch at 0x3b0 targets 0x1fc, is taken when s0(=a0) != a0(=[sym(the_console_port)]:8), and falls through when s0(=a0) == a0(=[sym(the_console_port)]:8).
  The `bne` branch at 0x3b8 targets 0x1fc, is taken when s6(=0x53435241) != a4(=[0xa800000000001000]:8), and falls through when s6(=0x53435241) == a4(=[0xa800000000001000]:8).
  The `beq` branch at 0x3c0 targets 0x1fc, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x3d0 targets 0x1fc, is taken when v1(=0xfffffffffeeddead) != a1(=[[0xa800000000001020]:8]), and falls through when v1(=0xfffffffffeeddead) == a1(=[[0xa800000000001020]:8]).
  The `beq` branch at 0x3dc targets 0x1fc, is taken when a1(=[[0xa800000000001020]:8+128]:8) == 0, and falls through when a1(=[[0xa800000000001020]:8+128]:8) != 0.
  The `beq` branch at 0x404 targets 0x1fc and is always taken.
  The `beq` branch at 0x414 targets 0x288, is taken when (a1(=[[a0+104]:8+16]) & s1(?)) == 0, and falls through when (a1(=[[a0+104]:8+16]) & s1(?)) != 0.
  The `beq` branch at 0x424 targets 0x448, is taken when (a4(=[a0+132]) & 0x1) == 0, and falls through when (a4(=[a0+132]) & 0x1) != 0.
  The `beq` branch at 0x430 targets 0x448, is taken when v0(=[a0+8]:8) == 0, and falls through when v0(=[a0+8]:8) != 0.
  The `beq` branch at 0x460 targets 0x288, is taken when (s1(?) & a1(=[[a0+104]:8+16])) == 0, and falls through when (s1(?) & a1(=[[a0+104]:8+16])) != 0.
  The `beq` branch at 0x470 targets 0x68c, is taken when (t8(=[a0+112]) & 0x8) == 0, and falls through when (t8(=[a0+112]) & 0x8) != 0.
  The `beq` branch at 0x478 targets 0x288 and is always taken.
  The `beq` branch at 0x488 targets 0x2d8, is taken when (a1(=[[a0+104]:8+8]) & s1(?)) == 0, and falls through when (a1(=[[a0+104]:8+8]) & s1(?)) != 0.
  The `beq` branch at 0x498 targets 0x4d0, is taken when (ra(=[a0+132]) & 0x2) == 0, and falls through when (ra(=[a0+132]) & 0x2) != 0.
  The `beq` branch at 0x4a4 targets 0x4bc, is taken when v0(=[a0+8]:8) == 0, and falls through when v0(=[a0+8]:8) != 0.
  The `beq` branch at 0x4d0 targets 0x2d8, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x4e0 targets 0x640, is taken when (v1(=[a0+132]) & 0x41) == 0, and falls through when (v1(=[a0+132]) & 0x41) != 0.
  The `beq` branch at 0x4f0 targets 0x2dc and is always taken.
  The `beq` branch at 0x544 targets 0x248, is taken when v0(=[a0+8]:8) == 0, and falls through when v0(=[a0+8]:8) != 0.
  The `beq` branch at 0x55c targets 0x24c and is always taken.
  The `beq` branch at 0x56c targets 0x390 and is always taken.
  The `beq` branch at 0x574 targets 0x340, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x584 targets 0x340, is taken when a4(=0xfffffffffeeddead) != a5(=[[0xa800000000001020]:8]), and falls through when a4(=0xfffffffffeeddead) == a5(=[[0xa800000000001020]:8]).
  The `beq` branch at 0x590 targets 0x340, is taken when a5(=[[0xa800000000001020]:8+128]:8) == 0, and falls through when a5(=[[0xa800000000001020]:8+128]:8) != 0.
  The `beq` branch at 0x5b8 targets 0x340 and is always taken.
  The `beq` branch at 0x5c0 targets 0x35c, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x5d0 targets 0x35c, is taken when a7(=0xfffffffffeeddead) != t0(=[[0xa800000000001020]:8]), and falls through when a7(=0xfffffffffeeddead) == t0(=[[0xa800000000001020]:8]).
  The `beq` branch at 0x5dc targets 0x35c, is taken when a1(=[[0xa800000000001020]:8+128]:8) == 0, and falls through when a1(=[[0xa800000000001020]:8+128]:8) != 0.
  The `beq` branch at 0x5f8 targets 0x360 and is always taken.
  The `beq` branch at 0x600 targets 0x218, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x610 targets 0x218, is taken when t1(=0xfffffffffeeddead) != t2(=[[0xa800000000001020]:8]), and falls through when t1(=0xfffffffffeeddead) == t2(=[[0xa800000000001020]:8]).
  The `beq` branch at 0x61c targets 0x218, is taken when a1(=[[0xa800000000001020]:8+128]:8) == 0, and falls through when a1(=[[0xa800000000001020]:8+128]:8) != 0.
  The `beq` branch at 0x638 targets 0x21c and is always taken.
  The `bne` branch at 0x658 targets 0x668, is taken when t3(=[sym(the_console_port)]:8) != s0(=a0), and falls through when t3(=[sym(the_console_port)]:8) == s0(=a0).
  The `beq` branch at 0x660 targets 0x6a4, is taken when s6(=0x53435241) == v0(=[0xa800000000001000]:8), and falls through when s6(=0x53435241) != v0(=[0xa800000000001000]:8).
  The `bne` branch at 0x674 targets 0x684, is taken when a1(=[sym(the_console_port)]:8) != s0(=a0), and falls through when a1(=[sym(the_console_port)]:8) == s0(=a0).
  The `beq` branch at 0x67c targets 0x6f4, is taken when s6(=0x53435241) == v0(=[0xa800000000001000]:8), and falls through when s6(=0x53435241) != v0(=[0xa800000000001000]:8).
  The `beq` branch at 0x684 targets 0x4e8 and is always taken.
  The `beq` branch at 0x69c targets 0x288 and is always taken.
  The `beq` branch at 0x6a4 targets 0x668, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x6b8 targets 0x668, is taken when a4(=0xfffffffffeeddead) != a5(=[[0xa800000000001020]:8]), and falls through when a4(=0xfffffffffeeddead) == a5(=[[0xa800000000001020]:8]).
  The `beq` branch at 0x6c4 targets 0x668, is taken when a5(=[[0xa800000000001020]:8+128]:8) == 0, and falls through when a5(=[[0xa800000000001020]:8+128]:8) != 0.
  The `beq` branch at 0x6ec targets 0x668 and is always taken.
  The `beq` branch at 0x6f4 targets 0x684, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x708 targets 0x684, is taken when a7(=0xfffffffffeeddead) != t0(=[[0xa800000000001020]:8]), and falls through when a7(=0xfffffffffeeddead) == t0(=[[0xa800000000001020]:8]).
  The `beq` branch at 0x714 targets 0x684, is taken when a1(=[[0xa800000000001020]:8+128]:8) == 0, and falls through when a1(=[[0xa800000000001020]:8+128]:8) != 0.
  The `beq` branch at 0x72c targets 0x684 and is always taken.
  The return at 0x53c has v0 = ret(ioc4_write_ireg).

- `ioc4_dma_error_intr` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc4.o)` at 0x734 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc4.o)`.
  Range: 0x734-0x83c (264 bytes).
  It occupies 264 bytes.
  The `ld` at 0x750 loads 8 bytes from a0 (arg0 at entry) +0x68.
  3 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x38, including `ld` at 0x758, `ld` at 0x770, `ld` at 0x80c.
  2 such `lw` accesses load 4 bytes from [a0+104]:8 +0x18, including `lw` at 0x75c, `lw` at 0x790.
  The `sw` at 0x760 stores 4 bytes to [a0+56]:8 +0xc.
  The `lw` at 0x76c loads 4 bytes from a0 (arg0 at entry) +0x34.
  5 such `lw` accesses load 4 bytes from [a0+56]:8 +0x0, including `lw` at 0x774, `lw` at 0x7b4, `lw` at 0x7d0.
  The `ld` at 0x79c loads 8 bytes from a0 (arg0 at entry) +0x98.
  The `lw` at 0x7d4 loads 4 bytes from [a0+56]:8 +0x4.
  The `jal` at 0x74c calls sio_lock_port with a0=a0 at entry (arg0), a1=0x0, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x768 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=[a0+52], a3=?.
  The `jal` at 0x784 calls sio_unlock_port with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x798 calls ioc4_write_ireg with a0=[a0+152]:8, a1=[[a0+104]:8+24], a2=0x0, a3=0x1.
  The `jal` at 0x804 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=?, a3=?, a4=sym(.rodata), a5=([[a0+56]:8+4] << 0x20), a6=-0x40.
  The `jal` at 0x824 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=?, a3=?.
  The `bne` branch at 0x77c targets 0x7b4, is taken when (v1(=[[a0+56]:8]) & 0x1) != 0, and falls through when (v1(=[[a0+56]:8]) & 0x1) == 0.
  The `beq` branch at 0x7bc targets 0x834, is taken when (a0(=[[a0+56]:8]) & 0x2) == 0, and falls through when (a0(=[[a0+56]:8]) & 0x2) != 0.
  The `beq` branch at 0x818 targets 0x784, is taken when (a4(=[[a0+56]:8]) & 0x20) == 0, and falls through when (a4(=[[a0+56]:8]) & 0x20) != 0.
  The `beq` branch at 0x82c targets 0x784 and is always taken.
  The `beq` branch at 0x834 targets 0x7cc and is always taken.
  The return at 0x7ac has v0 = ret(ioc4_write_ireg).

- `set_baud_ti` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc4.o)` at 0x83c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc4.o)`.
  Range: 0x83c-0x8f8 (188 bytes).
  It occupies 188 bytes.
  The `lw` at 0x83c loads 4 bytes from a0 (arg0 at entry) +0xa0.
  4 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x48, including `ld` at 0x8b8, `ld` at 0x8c8, `ld` at 0x8d0.
  The `lbu` at 0x8bc loads 1 byte from [a0+72]:8 +0x3.
  2 such `sb` accesses store 1 byte to [a0+72]:8 +0x3, including `sb` at 0x8c4, `sb` at 0x8e4.
  The `sb` at 0x8cc stores 1 byte to [a0+72]:8 +0x0.
  The `sb` at 0x8d4 stores 1 byte to [a0+72]:8 +0x1.
  The `beq` branch at 0x864 targets 0x8f0, is taken when (a4(?) & 0xffff) == 0, and falls through when (a4(?) & 0xffff) != 0.
  The `bltz` branch at 0x888 targets 0x8e8, is taken when t1(?) < 0 (signed), and falls through when t1(?) >= 0 (signed).
  The `beq` branch at 0x8a8 targets 0x8b8, is taken when t0(?) >= t1(?) (signed), and falls through when t0(?) < t1(?) (signed).
  The `beq` branch at 0x8e8 targets 0x890 and is always taken.
  The return at 0x8b0 has v0 = 0x1.
  The return at 0x8e0 has v0 = 0x0.
  The return at 0x8f0 has v0 = 0x1.

- `ioc4_serial_attach` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc4.o)` at 0xbdc (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc4.o)`.
  Range: 0xbdc-0x1408 (2092 bytes).
  It occupies 2092 bytes.
  The `ld` at 0xd1c loads 8 bytes from (([sym(master_nasid)]:2 << 0x21)+0x9600000000000000 | 0x2000) +0x48.
  3 such `lw` accesses load 4 bytes from ?, including `lw` at 0xd30, `lw` at 0xd38, `lw` at 0x1250.
  The `ld` at 0xe18 loads 8 bytes from ret(kmem_zalloc) +0x38.
  4 such `ld` accesses load 8 bytes from ret(kmem_zalloc) +0x50, including `ld` at 0xe1c, `ld` at 0xe40, `ld` at 0xf00.
  The `sd` at 0xe20 stores 8 bytes to ret(kmem_zalloc) +0x68.
  The `sd` at 0xe28 stores 8 bytes to ret(kmem_zalloc) +0x48.
  The `sd` at 0xe34 stores 8 bytes to ret(kmem_zalloc) +0x40.
  The `sd` at 0xe4c stores 8 bytes to ret(kmem_zalloc) +0x60.
  The `sd` at 0xe58 stores 8 bytes to ret(kmem_zalloc) +0x58.
  6 such `lw` accesses load 4 bytes from ret(kmem_zalloc) +0x34, including `lw` at 0xe64, `lw` at 0xe78, `lw` at 0xe94.
  The `sd` at 0xef8 stores 8 bytes to ret(kmem_zalloc) +0x110.
  The `ld` at 0xefc loads 8 bytes from ret(kmem_zalloc) +0xe0.
  The `sd` at 0xf04 stores 8 bytes to ret(kmem_zalloc) +0xf8.
  The `sd` at 0xf0c stores 8 bytes to ret(kmem_zalloc) +0xe8.
  The `sd` at 0xf18 stores 8 bytes to ret(kmem_zalloc) +0xf0.
  The `sd` at 0xf24 stores 8 bytes to ret(kmem_zalloc) +0x100.
  The `sd` at 0xf30 stores 8 bytes to ret(kmem_zalloc) +0x108.
  5 such `lw` accesses load 4 bytes from ret(kmem_zalloc) +0xdc, including `lw` at 0xf3c, `lw` at 0xf50, `lw` at 0xf6c.
  The `ld` at 0xfd0 loads 8 bytes from ret(kmem_zalloc) +0x188.
  4 such `ld` accesses load 8 bytes from ret(kmem_zalloc) +0x1a0, including `ld` at 0xfd4, `ld` at 0xffc, `ld` at 0x10b4.
  The `sd` at 0xfdc stores 8 bytes to ret(kmem_zalloc) +0x1b8.
  The `sd` at 0xfe4 stores 8 bytes to ret(kmem_zalloc) +0x198.
  The `sd` at 0xff0 stores 8 bytes to ret(kmem_zalloc) +0x190.
  The `sd` at 0x1008 stores 8 bytes to ret(kmem_zalloc) +0x1b0.
  The `sd` at 0x1014 stores 8 bytes to ret(kmem_zalloc) +0x1a8.
  4 such `lw` accesses load 4 bytes from ret(kmem_zalloc) +0x184, including `lw` at 0x1034, `lw` at 0x1048, `lw` at 0x1074.
  The `sd` at 0x10b0 stores 8 bytes to ret(kmem_zalloc) +0x260.
  The `sd` at 0x10b8 stores 8 bytes to ret(kmem_zalloc) +0x248.
  The `ld` at 0x10bc loads 8 bytes from ret(kmem_zalloc) +0x230.
  The `sd` at 0x10c4 stores 8 bytes to ret(kmem_zalloc) +0x258.
  The `sd` at 0x10d0 stores 8 bytes to ret(kmem_zalloc) +0x250.
  The `sd` at 0x10dc stores 8 bytes to ret(kmem_zalloc) +0x240.
  The `sd` at 0x10e8 stores 8 bytes to ret(kmem_zalloc) +0x238.
  5 such `lw` accesses load 4 bytes from ret(kmem_zalloc) +0x22c, including `lw` at 0x10f4, `lw` at 0x1108, `lw` at 0x111c.
  7 such `sw` accesses store 4 bytes to ?, including `sw` at 0x1198, `sw` at 0x1218, `sw` at 0x1220.
  4 such `sd` accesses store 8 bytes to ?, including `sd` at 0x11cc, `sd` at 0x11dc, `sd` at 0x1214.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0x11fc, `ld` at 0x1208.
  2 such `sb` accesses store 1 byte to ret(kmem_zalloc) +0x1d, including `sb` at 0x127c, `sb` at 0x130c.
  The `sd` at 0x139c stores 8 bytes to ret(kmem_zalloc) +0x1a0.
  The `sd` at 0x13c0 stores 8 bytes to ret(kmem_zalloc) +0x50.
  The `jal` at 0xbf8 calls pciio_config_get with a0=a0 at entry (arg0), a1=0x8, a2=0x1, a3=a3 at entry (arg3).
  The `jal` at 0xc24 calls ioc4_subdev_enabled with a0=a0 at entry (arg0), a1=0x2, a2=(ret(pciio_config_get) << 0x0), a3=?.
  The `jal` at 0xc34 calls ioc4_subdev_enabled with a0=a0 at entry (arg0), a1=0x2, a2=?, a3=?.
  The `jal` at 0xc58 calls ioc4_subdev_enabled with a0=a0 at entry (arg0), a1=0x3, a2=?, a3=?.
  The `jal` at 0xc7c calls ioc4_subdev_enabled with a0=a0 at entry (arg0), a1=0x4, a2=?, a3=?.
  The `jal` at 0xca0 calls ioc4_subdev_enabled with a0=a0 at entry (arg0), a1=0x5, a2=?, a3=?.
  The `jal` at 0xcbc calls pciio_businfo_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xcc4 calls pciio_businfo_bus_speed_get with a0=ret(pciio_businfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0xce4 calls pciio_piotrans_addr with a0=a0 at entry (arg0), a1=0x0, a2=0x8, a3=0x0, a4=0x3a0, a5=0x0.
  The `jal` at 0xcf4 calls ioc4_is_console with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xd5c calls hwgraph_traverse with a0=a0 at entry (arg0), a1=sym(.rodata), a2=sp-208, a3=?.
  The `jal` at 0xd64 calls hwgraph_fastinfo_get with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xd74 calls kmem_zalloc with a0=0x2a0, a1=0x0, a2=?, a3=?.
  The `jal` at 0xe08 calls ioc4_subdev_enabled with a0=a0 at entry (arg0), a1=0x2, a2=?, a3=?.
  The `jal` at 0xe38 calls bzero with a0=?, a1=0x4000, a2=?, a3=?.
  The `jal` at 0xe54 calls hardware_init with a0=ret(kmem_zalloc), a1=one of 0x0, 0x1, a2=?, a3=?.
  The `jal` at 0xe68 calls hwgraph_edge_get with a0=[ret(kmem_zalloc)+52], a1=sym(.rodata), a2=sp-156, a3=?.
  The `jal` at 0xe98 calls ioc4_intr_connect with a0=a0 at entry (arg0), a1=0x0, a2=0xff, a3=sym(ioc4_serial_intr), a4=ret(kmem_zalloc), a5=[ret(kmem_zalloc)+52], a7=0x0.
  The `jal` at 0xebc calls ioc4_intr_connect with a0=a0 at entry (arg0), a1=0x1, a2=0x4, a3=sym(ioc4_dma_error_intr), a4=ret(kmem_zalloc), a5=[ret(kmem_zalloc)+52], a7=0x0.
  The `jal` at 0xed0 calls device_controller_num_set with a0=[ret(kmem_zalloc)+52], a1=0x1, a2=?, a3=?.
  The `jal` at 0xed8 calls sio_make_hwgraph_nodes with a0=ret(kmem_zalloc), a1=?, a2=?, a3=?.
  The `jal` at 0xee8 calls ioc4_subdev_enabled with a0=a0 at entry (arg0), a1=0x3, a2=?, a3=?.
  The `jal` at 0xf2c calls hardware_init with a0=?, a1=0x0, a2=[ret(kmem_zalloc)+80]:8+8192, a3=[ret(kmem_zalloc)+80]:8+12288, a4=[ret(kmem_zalloc)+224]:8+904, a5=[ret(kmem_zalloc)+224]:8+812, a6=sym(.data).
  The `jal` at 0xf40 calls hwgraph_edge_get with a0=[ret(kmem_zalloc)+220], a1=sym(.rodata), a2=sp-156, a3=?.
  The `jal` at 0xf70 calls ioc4_intr_connect with a0=a0 at entry (arg0), a1=0x0, a2=0xff00, a3=sym(ioc4_serial_intr), a5=[ret(kmem_zalloc)+220], a7=0x0.
  The `jal` at 0xf94 calls ioc4_intr_connect with a0=a0 at entry (arg0), a1=0x1, a2=0x8, a3=sym(ioc4_dma_error_intr), a5=[ret(kmem_zalloc)+220], a7=0x0.
  The `jal` at 0xfa8 calls device_controller_num_set with a0=[ret(kmem_zalloc)+220], a1=0x2, a2=?, a3=?.
  The `jal` at 0xfb0 calls sio_make_hwgraph_nodes with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xfc0 calls ioc4_subdev_enabled with a0=a0 at entry (arg0), a1=0x4, a2=?, a3=?.
  The `jal` at 0xff4 calls bzero with a0=?, a1=0x4000, a2=?, a3=?.
  The `jal` at 0x1010 calls hardware_init with a0=ret(kmem_zalloc)+336, a1=0x0, a2=?, a3=?, a5=[ret(kmem_zalloc)+416]:8+4096.
  The `jal` at 0x1024 calls hwgraph_edge_get with a0=[ret(kmem_zalloc)+52], a1=sym(.rodata), a2=sp-156, a3=?.
  The `jal` at 0x1054 calls ioc4_intr_connect with a0=a0 at entry (arg0), a1=0x0, a2=0xff0000, a3=sym(ioc4_serial_intr), a4=ret(kmem_zalloc)+336, a5=[ret(kmem_zalloc)+388], a7=0x0.
  The `jal` at 0x1078 calls ioc4_intr_connect with a0=a0 at entry (arg0), a1=0x1, a2=0x10, a3=sym(ioc4_dma_error_intr), a4=ret(kmem_zalloc)+336, a5=[ret(kmem_zalloc)+388], a7=0x0.
  The `jal` at 0x108c calls device_controller_num_set with a0=[ret(kmem_zalloc)+388], a1=-0x1, a2=?, a3=?.
  The `jal` at 0x1094 calls sio_make_hwgraph_nodes with a0=ret(kmem_zalloc)+336, a1=?, a2=?, a3=?.
  The `jal` at 0x10a0 calls ioc4_subdev_enabled with a0=a0 at entry (arg0), a1=0x5, a2=?, a3=?.
  The `jal` at 0x10e4 calls hardware_init with a0=?, a1=0x0, a2=[ret(kmem_zalloc)+560]:8+868, a3=[ret(kmem_zalloc)+560]:8+920, a4=[ret(kmem_zalloc)+416]:8+12288, a5=[ret(kmem_zalloc)+416]:8+8192, a6=sym(.data).
  The `jal` at 0x10f8 calls hwgraph_edge_get with a0=[ret(kmem_zalloc)+556], a1=sym(.rodata), a2=sp-156, a3=?.
  The `jal` at 0x1128 calls ioc4_intr_connect with a0=a0 at entry (arg0), a1=0x0, a2=0xffffffffff000000, a3=sym(ioc4_serial_intr), a5=[ret(kmem_zalloc)+556], a7=0x0.
  The `jal` at 0x114c calls ioc4_intr_connect with a0=a0 at entry (arg0), a1=0x1, a2=0x20, a3=sym(ioc4_dma_error_intr), a5=[ret(kmem_zalloc)+556], a7=0x0.
  The `jal` at 0x115c calls device_controller_num_set with a0=[ret(kmem_zalloc)+556], a1=-0x1, a2=?, a3=?.
  The `jal` at 0x1164 calls sio_make_hwgraph_nodes with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x11bc calls device_inventory_add with a0=?, a1=0x4, a2=0x10, a3=-0x1, a4=0x0, a5=0x0.
  The `jal` at 0x1210 calls hwgraph_path_add with a0=a0 at entry (arg0), a1=?, a2=sp-164, a3=?.
  The `jal` at 0x1234 calls hwgraph_fastinfo_set with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1254 calls sio_initport with a0=?, a1=?, a2=0x1ff, a3=one of 0x0, 0x1.
  The `jal` at 0x1264 calls kmem_zalloc with a0=0x28, a1=0x0, a2=?, a3=?.
  The `jal` at 0x1280 calls sio_init_locks with a0=ret(kmem_zalloc), a1=?, a2=one of 0x2, 0x3, a3=?.
  The `jal` at 0x12a4 calls hwgraph_edge_get with a0=?, a1=sym(.rodata), a2=sp-160, a3=?.
  The `jal` at 0x12d0 calls kopt_find with a0=sym(.rodata), a1=?, a2=?, a3=?, a4=0x1.
  The `jal` at 0x12e0 calls atoi with a0=ret(kopt_find), a1=?, a2=0x1, a3=?.
  The `jal` at 0x1320 calls ioc4_subdev_enabled with a0=a0 at entry (arg0), a1=0x3, a2=?, a3=?.
  The `jal` at 0x1334 calls ioc4_subdev_enabled with a0=a0 at entry (arg0), a1=0x4, a2=?, a3=?.
  The `jal` at 0x1348 calls ioc4_subdev_enabled with a0=a0 at entry (arg0), a1=0x5, a2=?, a3=?.
  The `jal` at 0x1374 calls printf with a0=sym(.rodata), a1=?, a2=0x1, a3=?.
  The `jal` at 0x138c calls kvpalloc with a0=0x1, a1=0x100, a2=0x0, a3=[ret(kmem_zalloc)+392]:8+912, a4=sym(.data).
  The `jal` at 0x13b0 calls kvpalloc with a0=0x1, a1=0x100, a2=0x0, a3=?, a6=[ret(kmem_zalloc)+56]:8+784, a7=[ret(kmem_zalloc)+56]:8+896.
  The `jal` at 0x13d8 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=(ret(pciio_config_get) << 0x0), a3=0x3e.
  The `jal` at 0x13e8 calls panic with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jal` at 0x13f8 calls panic with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `bne` branch at 0xc18 targets 0x13cc, is taken when a2(=(ret(pciio_config_get) << 0x0)) < 0x3e (unsigned), and falls through when a2(=(ret(pciio_config_get) << 0x0)) >= 0x3e (unsigned).
  The `beq` branch at 0xc2c targets 0x131c, is taken when v0(=ret(ioc4_subdev_enabled)) == 0, and falls through when v0(=ret(ioc4_subdev_enabled)) != 0.
  The `beq` branch at 0xc44 targets 0x1360, is taken when v0(=ret(ioc4_subdev_enabled)) == 0, and falls through when v0(=ret(ioc4_subdev_enabled)) != 0.
  The `beq` branch at 0xc60 targets 0xc7c, is taken when v0(=ret(ioc4_subdev_enabled)) == 0, and falls through when v0(=ret(ioc4_subdev_enabled)) != 0.
  The `beq` branch at 0xc84 targets 0xca0, is taken when v0(=ret(ioc4_subdev_enabled)) == 0, and falls through when v0(=ret(ioc4_subdev_enabled)) != 0.
  The `beq` branch at 0xca8 targets 0xcbc, is taken when v0(=ret(ioc4_subdev_enabled)) == 0, and falls through when v0(=ret(ioc4_subdev_enabled)) != 0.
  The `beq` branch at 0xcfc targets 0xd50, is taken when v0(=ret(ioc4_is_console)) == 0, and falls through when v0(=ret(ioc4_is_console)) != 0.
  The `bne` branch at 0xd44 targets 0xd50, is taken when a1(?) != a2(=0x100a10a9), and falls through when a1(?) == a2(=0x100a10a9).
  The `bne` branch at 0xda8 targets 0xdf0, is taken when s6(?) < s2(?) (signed), and falls through when s6(?) >= s2(?) (signed).
  The `beq` branch at 0xde8 targets 0x11e0 and is always taken.
  The `beq` branch at 0xe10 targets 0xee8, is taken when v0(=ret(ioc4_subdev_enabled)) == 0, and falls through when v0(=ret(ioc4_subdev_enabled)) != 0.
  The `beq` branch at 0xe30 targets 0x13a8, is taken when a0(=[ret(kmem_zalloc)+80]:8) == 0, and falls through when a0(=[ret(kmem_zalloc)+80]:8) != 0.
  The `beq` branch at 0xe70 targets 0xe80, is taken when v0(=ret(hwgraph_edge_get)) == 0, and falls through when v0(=ret(hwgraph_edge_get)) != 0.
  The `beq` branch at 0xec4 targets 0xee8, is taken when s4(=one of 0x0, 0x1) == 0, and falls through when s4(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0xef0 targets 0xfb8, is taken when v0(=ret(ioc4_subdev_enabled)) == 0, and falls through when v0(=ret(ioc4_subdev_enabled)) != 0.
  The `beq` branch at 0xf48 targets 0xf58, is taken when v0(=ret(hwgraph_edge_get)) == 0, and falls through when v0(=ret(hwgraph_edge_get)) != 0.
  The `beq` branch at 0xf9c targets 0xfbc, is taken when s4(=one of 0x0, 0x1) == 0, and falls through when s4(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0xfc8 targets 0x10a0, is taken when v0(=ret(ioc4_subdev_enabled)) == 0, and falls through when v0(=ret(ioc4_subdev_enabled)) != 0.
  The `beq` branch at 0xfec targets 0x1384, is taken when a0(=[ret(kmem_zalloc)+416]:8) == 0, and falls through when a0(=[ret(kmem_zalloc)+416]:8) != 0.
  The `beq` branch at 0x102c targets 0x103c, is taken when v0(=ret(hwgraph_edge_get)) == 0, and falls through when v0(=ret(hwgraph_edge_get)) != 0.
  The `beq` branch at 0x1080 targets 0x10a0, is taken when s4(=one of 0x0, 0x1) == 0, and falls through when s4(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x10a8 targets 0x116c, is taken when v0(=ret(ioc4_subdev_enabled)) == 0, and falls through when v0(=ret(ioc4_subdev_enabled)) != 0.
  The `beq` branch at 0x1100 targets 0x1110, is taken when v0(=ret(hwgraph_edge_get)) == 0, and falls through when v0(=ret(hwgraph_edge_get)) != 0.
  The `beq` branch at 0x1154 targets 0x116c, is taken when s4(=one of 0x0, 0x1) == 0, and falls through when s4(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x11a0 targets 0x1368, is taken when s2(?) == a2(=0x1), and falls through when s2(?) != a2(=0x1).
  The `bne` branch at 0x11d8 targets 0xdf0, is taken when s6(?) < s2(?) (signed), and falls through when s6(?) >= s2(?) (signed).
  The `beq` branch at 0x123c targets 0x124c, is taken when s4(=one of 0x0, 0x1) == 0, and falls through when s4(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x1244 targets 0x12f8, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `beq` branch at 0x126c targets 0x1278, is taken when s4(=one of 0x0, 0x1) == 0, and falls through when s4(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x1274 targets 0x1304, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `beq` branch at 0x1290 targets 0x11a8, is taken when s4(=one of 0x0, 0x1) == 0, and falls through when s4(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x12b8 targets 0x1310, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `bne` branch at 0x12c0 targets 0x11ac, is taken when s2(?) != a4(=0x1), and falls through when s2(?) == a4(=0x1).
  The `beq` branch at 0x12d8 targets 0x11a0, is taken when v0(=ret(kopt_find)) == 0, and falls through when v0(=ret(kopt_find)) != 0.
  The `bgtz` branch at 0x12e8 targets 0x1198, is taken when v0(=ret(atoi)) > 0 (signed), and falls through when v0(=ret(atoi)) <= 0 (signed).
  The `beq` branch at 0x12f0 targets 0x11a0 and is always taken.
  The `beq` branch at 0x12fc targets 0x1250 and is always taken.
  The `beq` branch at 0x1308 targets 0x1280 and is always taken.
  The `beq` branch at 0x1314 targets 0x12d0 and is always taken.
  The `bne` branch at 0x1328 targets 0xc34, is taken when v0(=ret(ioc4_subdev_enabled)) != 0, and falls through when v0(=ret(ioc4_subdev_enabled)) == 0.
  The `bne` branch at 0x133c targets 0xc34, is taken when v0(=ret(ioc4_subdev_enabled)) != 0, and falls through when v0(=ret(ioc4_subdev_enabled)) == 0.
  The `bne` branch at 0x1350 targets 0xc34, is taken when v0(=ret(ioc4_subdev_enabled)) != 0, and falls through when v0(=ret(ioc4_subdev_enabled)) == 0.
  The `beq` branch at 0x1358 targets 0x1170 and is always taken.
  The `beq` branch at 0x1360 targets 0xc54 and is always taken.
  The `beq` branch at 0x1368 targets 0x137c, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x137c targets 0x11a8 and is always taken.
  The `bne` branch at 0x1398 targets 0xff4, is taken when v0(=ret(kvpalloc)) != 0, and falls through when v0(=ret(kvpalloc)) == 0.
  The `beq` branch at 0x13a0 targets 0x13f8 and is always taken.
  The `bne` branch at 0x13bc targets 0xe38, is taken when v0(=ret(kvpalloc)) != 0, and falls through when v0(=ret(kvpalloc)) == 0.
  The `beq` branch at 0x13c4 targets 0x13e8 and is always taken.
  The `beq` branch at 0x13e0 targets 0x1170 and is always taken.
  The `beq` branch at 0x13f0 targets 0xe38 and is always taken.
  The `beq` branch at 0x1400 targets 0xff4 and is always taken.
  The return at 0x1190 has v0 = one of -0x1, 0x0.

- `ioc4_serial_kill` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc4.o)` at 0x1408 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc4.o)`.
  Range: 0x1408-0x1520 (280 bytes).
  It occupies 280 bytes.
  The `ld` at 0x1408 loads 8 bytes from a0 (arg0 at entry) +0x8.
  The `ld` at 0x1420 loads 8 bytes from [a0+8]:8 +0x28.
  2 such `ld` accesses load 8 bytes from abs 0xa800000000001000, including `ld` at 0x1444, `ld` at 0x1498.
  3 such `ld` accesses load 8 bytes from abs 0xa800000000001020, including `ld` at 0x1448, `ld` at 0x148c, `ld` at 0x1500.
  2 such `lw` accesses load 4 bytes from [0xa800000000001020]:8 +0x0, including `lw` at 0x145c, `lw` at 0x14b0.
  3 such `ld` accesses load 8 bytes from [0xa800000000001020]:8 +0x80, including `ld` at 0x1468, `ld` at 0x14bc, `ld` at 0x1504.
  The `ld` at 0x1474 loads 8 bytes from a0 (arg0 at entry) +0x40.
  The `sw` at 0x147c stores 4 bytes to [a0+64]:8 +0x0.
  The `sw` at 0x14e4 stores 4 bytes to a0 (arg0 at entry) +0x8c.
  The `jalr` at 0x1424 calls (unknown callee) with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x14d0 calls (unknown callee) with a0=0x1, a1=[a0+64]:8, a2=[[0xa800000000001020]:8], a3=[[0xa800000000001020]:8+128]:8, a4=[sym(.sbss)], a5=[sym(the_console_port)]:8.
  The `jal` at 0x14d8 calls splx with a0=[sym(.sbss)], a1=?, a2=?, a3=?.
  The `jal` at 0x14f4 calls spl7 with a0=0xa800000000001020, a1=?, a2=?, a3=[0xa800000000001000]:8, a4=0x53435241, a5=[[0xa800000000001020]:8], a6=0xfffffffffeeddead, a7=[[0xa800000000001020]:8+128]:8.
  The `jalr` at 0x150c calls (unknown callee) with a0=0x0, a1=?, a2=?, a3=?, a5=[[0xa800000000001020]:8+128]:8.
  The `beq` branch at 0x1418 targets 0x142c, is taken when v0(=[a0+8]:8) == 0, and falls through when v0(=[a0+8]:8) != 0.
  The `bne` branch at 0x1440 targets 0x1474, is taken when a5(=[sym(the_console_port)]:8) != s0(=a0), and falls through when a5(=[sym(the_console_port)]:8) == s0(=a0).
  The `bne` branch at 0x144c targets 0x1474, is taken when a3(=[0xa800000000001000]:8) != a4(=0x53435241), and falls through when a3(=[0xa800000000001000]:8) == a4(=0x53435241).
  The `beq` branch at 0x1454 targets 0x1474, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x1460 targets 0x1474, is taken when a5(=[[0xa800000000001020]:8]) != a6(=0xfffffffffeeddead), and falls through when a5(=[[0xa800000000001020]:8]) == a6(=0xfffffffffeeddead).
  The `bne` branch at 0x146c targets 0x14f4, is taken when a7(=[[0xa800000000001020]:8+128]:8) != 0, and falls through when a7(=[[0xa800000000001020]:8+128]:8) == 0.
  The `bne` branch at 0x1494 targets 0x14e0, is taken when a5(=[sym(the_console_port)]:8) != s0(=a0), and falls through when a5(=[sym(the_console_port)]:8) == s0(=a0).
  The `bne` branch at 0x149c targets 0x14e4, is taken when a3(=[0xa800000000001000]:8) != a0(=0x53435241), and falls through when a3(=[0xa800000000001000]:8) == a0(=0x53435241).
  The `beq` branch at 0x14a4 targets 0x14e4, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x14b4 targets 0x14e4, is taken when a2(=[[0xa800000000001020]:8]) != a3(=0xfffffffffeeddead), and falls through when a2(=[[0xa800000000001020]:8]) == a3(=0xfffffffffeeddead).
  The `beq` branch at 0x14c0 targets 0x14e4, is taken when a3(=[[0xa800000000001020]:8+128]:8) == 0, and falls through when a3(=[[0xa800000000001020]:8+128]:8) != 0.
  The `beq` branch at 0x1518 targets 0x1474 and is always taken.
  The return at 0x14ec has v0 = one of [0xa800000000001020]:8, ?.

- `ioc4_open` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc4.o)` at 0x1520 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc4.o)`.
  Range: 0x1520-0x17c4 (676 bytes).
  It occupies 676 bytes.
  The `sb` at 0x1520 stores 1 byte to a0 (arg0 at entry) +0x74.
  4 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x8c, including `lw` at 0x1524, `lw` at 0x1650, `lw` at 0x177c.
  The `sw` at 0x1528 stores 4 bytes to a0 (arg0 at entry) +0x70.
  4 such `ld` accesses load 8 bytes from abs 0xa800000000001000, including `ld` at 0x1558, `ld` at 0x15d8, `ld` at 0x1674.
  6 such `ld` accesses load 8 bytes from abs 0xa800000000001020, including `ld` at 0x156c, `ld` at 0x15ec, `ld` at 0x1680.
  4 such `lw` accesses load 4 bytes from [0xa800000000001020]:8 +0x0, including `lw` at 0x1578, `lw` at 0x15f8, `lw` at 0x1694.
  6 such `ld` accesses load 8 bytes from [0xa800000000001020]:8 +0x80, including `ld` at 0x1584, `ld` at 0x1604, `ld` at 0x16a0.
  4 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x40, including `ld` at 0x1590, `ld` at 0x15a0, `ld` at 0x16ac.
  2 such `sw` accesses store 4 bytes to [a0+64]:8 +0x0, including `sw` at 0x159c, `sw` at 0x16b0.
  2 such `lw` accesses load 4 bytes from [a0+64]:8 +0x0, including `lw` at 0x15a4, `lw` at 0x1730.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x48, including `ld` at 0x162c, `ld` at 0x1644.
  The `sb` at 0x1640 stores 1 byte to [a0+72]:8 +0x2.
  The `sb` at 0x164c stores 1 byte to [a0+72]:8 +0x3.
  The `sw` at 0x1664 stores 4 bytes to a0 (arg0 at entry) +0x8c.
  The `sw` at 0x170c stores 4 bytes to [a0+64]:8 +0x14.
  The `sw` at 0x1718 stores 4 bytes to a0 (arg0 at entry) +0x7c.
  The `jalr` at 0x1614 calls (unknown callee) with a0=0x1, a1=0xfffffffffeeddead, a2=[sym(.sbss)], a3=[[0xa800000000001020]:8+128]:8, a4=0xf4240, a5=0x40000000, a7=([a0+140] | 0x20000000).
  The `jal` at 0x161c calls splx with a0=[sym(.sbss)], a1=?, a2=?, a3=?.
  The `jal` at 0x163c calls set_baud_ti with a0=a0 at entry (arg0), a1=0x2580, a2=?, a3=0x3, a4=[a0+72]:8.
  The `jalr` at 0x16f8 calls (unknown callee) with a0=0x1, a1=?, a2=?, a3=[[0xa800000000001020]:8+128]:8.
  The `jal` at 0x1700 calls splx with a0=[sym(.sbss)], a1=?, a2=?, a3=?.
  The `jal` at 0x175c calls spl7 with a0=0xa800000000001020, a1=[0xa800000000001000]:8, a2=[[0xa800000000001020]:8], a3=[a0+140], a4=0xfffffffffeeddead, a5=[[0xa800000000001020]:8+128]:8.
  The `jalr` at 0x1774 calls (unknown callee) with a0=0x0, a1=?, a2=?, a3=?, a7=[[0xa800000000001020]:8+128]:8.
  The `jal` at 0x1788 calls spl7 with a0=0x53435241, a1=?, a2=?, a3=?, a4=[0xa800000000001000]:8, a5=[sym(the_console_port)]:8, a6=0x3, a7=[a0+72]:8.
  The `jalr` at 0x179c calls (unknown callee) with a0=0x0, a1=?, a2=?, a3=?.
  The `bgez` branch at 0x1540 targets 0x162c, is taken when at(=([a0+140] << 0x23)) >= 0 (signed), and falls through when at(=([a0+140] << 0x23)) < 0 (signed).
  The `bne` branch at 0x154c targets 0x1590, is taken when v1(=[sym(the_console_port)]:8) != a0, and falls through when v1(=[sym(the_console_port)]:8) == a0.
  The `bne` branch at 0x1568 targets 0x1590, is taken when a1(=[0xa800000000001000]:8) != a2(=0x53435241), and falls through when a1(=[0xa800000000001000]:8) == a2(=0x53435241).
  The `beq` branch at 0x1570 targets 0x1590, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x157c targets 0x1590, is taken when a2(=[[0xa800000000001020]:8]) != a4(=0xfffffffffeeddead), and falls through when a2(=[[0xa800000000001020]:8]) == a4(=0xfffffffffeeddead).
  The `bne` branch at 0x1588 targets 0x175c, is taken when a5(=[[0xa800000000001020]:8+128]:8) != 0, and falls through when a5(=[[0xa800000000001020]:8+128]:8) == 0.
  The `bltz` branch at 0x15b4 targets 0x15c4, is taken when a6(=([[a0+64]:8] << 0x21)) < 0 (signed), and falls through when a6(=([[a0+64]:8] << 0x21)) >= 0 (signed).
  The `beq` branch at 0x15bc targets 0x17b4 and is always taken.
  The `bne` branch at 0x15cc targets 0x1624, is taken when t0(=[sym(the_console_port)]:8) != s0(=a0), and falls through when t0(=[sym(the_console_port)]:8) == s0(=a0).
  The `bne` branch at 0x15e8 targets 0x1624, is taken when v1(=[0xa800000000001000]:8) != a0(=0x53435241), and falls through when v1(=[0xa800000000001000]:8) == a0(=0x53435241).
  The `beq` branch at 0x15f0 targets 0x1624, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x15fc targets 0x1624, is taken when a0(=[[0xa800000000001020]:8]) != a1(=0xfffffffffeeddead), and falls through when a0(=[[0xa800000000001020]:8]) == a1(=0xfffffffffeeddead).
  The `beq` branch at 0x1608 targets 0x1624, is taken when a3(=[[0xa800000000001020]:8+128]:8) == 0, and falls through when a3(=[[0xa800000000001020]:8+128]:8) != 0.
  The `beq` branch at 0x1624 targets 0x1754, is taken when s1(=one of 0x0, 0x1) == 0, and falls through when s1(=one of 0x0, 0x1) != 0.
  The `bne` branch at 0x167c targets 0x16ac, is taken when a5(=[sym(the_console_port)]:8) != s0(=a0), and falls through when a5(=[sym(the_console_port)]:8) == s0(=a0).
  The `bne` branch at 0x1684 targets 0x16ac, is taken when a4(=[0xa800000000001000]:8) != a0(=0x53435241), and falls through when a4(=[0xa800000000001000]:8) == a0(=0x53435241).
  The `beq` branch at 0x168c targets 0x16ac, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x1698 targets 0x16ac, is taken when t0(=[[0xa800000000001020]:8]) != t1(=0xfffffffffeeddead), and falls through when t0(=[[0xa800000000001020]:8]) == t1(=0xfffffffffeeddead).
  The `bne` branch at 0x16a4 targets 0x1788, is taken when t2(=[[0xa800000000001020]:8+128]:8) != 0, and falls through when t2(=[[0xa800000000001020]:8+128]:8) == 0.
  The `bne` branch at 0x16b8 targets 0x1708, is taken when t3(=[sym(the_console_port)]:8) != s0(=a0), and falls through when t3(=[sym(the_console_port)]:8) == s0(=a0).
  The `bne` branch at 0x16cc targets 0x1708, is taken when t9(=[0xa800000000001000]:8) != ra(=0x53435241), and falls through when t9(=[0xa800000000001000]:8) == ra(=0x53435241).
  The `beq` branch at 0x16d8 targets 0x1708, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x16e4 targets 0x1708, is taken when v1(=[[0xa800000000001020]:8]) != a0(=0xfffffffffeeddead), and falls through when v1(=[[0xa800000000001020]:8]) == a0(=0xfffffffffeeddead).
  The `beq` branch at 0x16f0 targets 0x1708, is taken when a3(=[[0xa800000000001020]:8+128]:8) == 0, and falls through when a3(=[[0xa800000000001020]:8+128]:8) != 0.
  The `bne` branch at 0x173c targets 0x15c4, is taken when (a3(=[[a0+64]:8]) & a5(=0x40000000)) != 0, and falls through when (a3(=[[a0+64]:8]) & a5(=0x40000000)) == 0.
  The `beq` branch at 0x1744 targets 0x1730, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `beq` branch at 0x174c targets 0x15cc and is always taken.
  The `beq` branch at 0x1754 targets 0x171c and is always taken.
  The `beq` branch at 0x1780 targets 0x1590 and is always taken.
  The `beq` branch at 0x17ac targets 0x16ac and is always taken.
  The `beq` branch at 0x17bc targets 0x1744 and is always taken.
  The return at 0x1728 has v0 = one of -0x1, 0x0.

- `ioc4_config` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc4.o)` at 0x17c4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc4.o)`.
  Range: 0x17c4-0x1b58 (916 bytes).
  It occupies 916 bytes.
  4 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x8c, including `lw` at 0x1844, `lw` at 0x197c, `lw` at 0x1b0c.
  4 such `ld` accesses load 8 bytes from abs 0xa800000000001000, including `ld` at 0x1860, `ld` at 0x18e0, `ld` at 0x19a0.
  6 such `ld` accesses load 8 bytes from abs 0xa800000000001020, including `ld` at 0x1874, `ld` at 0x18f4, `ld` at 0x19b4.
  4 such `lw` accesses load 4 bytes from [0xa800000000001020]:8 +0x0, including `lw` at 0x1880, `lw` at 0x1900, `lw` at 0x19c0.
  6 such `ld` accesses load 8 bytes from [0xa800000000001020]:8 +0x80, including `ld` at 0x188c, `ld` at 0x190c, `ld` at 0x19cc.
  3 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x40, including `ld` at 0x1898, `ld` at 0x18a8, `ld` at 0x19d8.
  2 such `sw` accesses store 4 bytes to [a0+64]:8 +0x0, including `sw` at 0x18a4, `sw` at 0x19dc.
  2 such `lw` accesses load 4 bytes from [a0+64]:8 +0x0, including `lw` at 0x18ac, `lw` at 0x1a94.
  The `ld` at 0x193c loads 8 bytes from a0 (arg0 at entry) +0x48.
  The `lbu` at 0x1940 loads 1 byte from [a0+72]:8 +0x3.
  The `sb` at 0x1978 stores 1 byte to [a0+72]:8 +0x3.
  The `sw` at 0x1a74 stores 4 bytes to a0 (arg0 at entry) +0x78.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x7c, including `sw` at 0x1a7c, `sw` at 0x1ac0.
  The `lw` at 0x1a88 loads 4 bytes from a0 (arg0 at entry) +0x80.
  The `jal` at 0x17e8 calls set_baud_ti with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x1920 calls (unknown callee) with a0=0x1, a1=[[0xa800000000001020]:8], a2=[[0xa800000000001020]:8+128]:8, a3=[sym(.sbss)], a7=0x40000000.
  The `jal` at 0x1928 calls splx with a0=[sym(.sbss)], a1=?, a2=?, a3=?.
  The `jalr` at 0x1a2c calls (unknown callee) with a0=0x1, a1=0xfffffffffeeddead, a2=[[0xa800000000001020]:8+128]:8, a3=a1 at entry (arg1).
  The `jal` at 0x1a34 calls splx with a0=[sym(.sbss)], a1=?, a2=?, a3=?.
  The `jal` at 0x1a84 calls ioc4_rx_timeout with a0=a0 at entry (arg0), a1=[a0+128], a2=?, a3=a1 at entry (arg1), a6=0xa.
  The `jal` at 0x1aec calls spl7 with a0=[a0+140], a1=([a0+140] << 0x23), a2=0xa800000000001020, a3=[0xa800000000001000]:8, a4=[[0xa800000000001020]:8], a5=0xfffffffffeeddead, a6=[[0xa800000000001020]:8+128]:8.
  The `jalr` at 0x1b04 calls (unknown callee) with a0=0x0, a1=?, a2=?, a3=?.
  The `jal` at 0x1b1c calls spl7 with a0=[a0+140], a1=?, a2=[a0+72]:8, a3=a1 at entry (arg1), a4=[sym(the_console_port)]:8, a5=[0xa800000000001000]:8, a6=[[0xa800000000001020]:8], a7=0xfffffffffeeddead.
  The `jalr` at 0x1b30 calls (unknown callee) with a0=0x0, a1=?, a2=?, a3=?.
  The `beq` branch at 0x17f0 targets 0x1810, is taken when v0(=ret(set_baud_ti)) == 0, and falls through when v0(=ret(set_baud_ti)) != 0.
  The `beq` branch at 0x1810 targets 0x1840, is taken when s1(=a2) == at(=0x5), and falls through when s1(=a2) != at(=0x5).
  The `beq` branch at 0x1818 targets 0x1ac4, is taken when s1(=a2) == v0(=0x6), and falls through when s1(=a2) != v0(=0x6).
  The `beq` branch at 0x1820 targets 0x1acc, is taken when s1(=a2) == v1(=0x7), and falls through when s1(=a2) != v1(=0x7).
  The `beq` branch at 0x1828 targets 0x1838, is taken when s1(=a2) == a0(=0x8), and falls through when s1(=a2) != a0(=0x8).
  The `beq` branch at 0x1830 targets 0x17fc and is always taken.
  The `beq` branch at 0x1838 targets 0x1844 and is always taken.
  The `bgez` branch at 0x184c targets 0x193c, is taken when a1(=([a0+140] << 0x23)) >= 0 (signed), and falls through when a1(=([a0+140] << 0x23)) < 0 (signed).
  The `bne` branch at 0x1854 targets 0x1898, is taken when a2(=[sym(the_console_port)]:8) != s0(=a0), and falls through when a2(=[sym(the_console_port)]:8) == s0(=a0).
  The `bne` branch at 0x1870 targets 0x1898, is taken when a3(=[0xa800000000001000]:8) != a4(=0x53435241), and falls through when a3(=[0xa800000000001000]:8) == a4(=0x53435241).
  The `beq` branch at 0x1878 targets 0x1898, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x1884 targets 0x1898, is taken when a4(=[[0xa800000000001020]:8]) != a5(=0xfffffffffeeddead), and falls through when a4(=[[0xa800000000001020]:8]) == a5(=0xfffffffffeeddead).
  The `bne` branch at 0x1890 targets 0x1aec, is taken when a6(=[[0xa800000000001020]:8+128]:8) != 0, and falls through when a6(=[[0xa800000000001020]:8+128]:8) == 0.
  The `bltz` branch at 0x18b4 targets 0x18cc, is taken when a7(=([[a0+64]:8] << 0x21)) < 0 (signed), and falls through when a7(=([[a0+64]:8] << 0x21)) >= 0 (signed).
  The `beq` branch at 0x18c4 targets 0x1b48 and is always taken.
  The `bne` branch at 0x18d4 targets 0x1934, is taken when a1(=[sym(the_console_port)]:8) != s0(=a0), and falls through when a1(=[sym(the_console_port)]:8) == s0(=a0).
  The `bne` branch at 0x18f0 targets 0x1934, is taken when v1(=[0xa800000000001000]:8) != a1(=0x53435241), and falls through when v1(=[0xa800000000001000]:8) == a1(=0x53435241).
  The `beq` branch at 0x18f8 targets 0x1934, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x1904 targets 0x1934, is taken when a1(=[[0xa800000000001020]:8]) != a2(=0xfffffffffeeddead), and falls through when a1(=[[0xa800000000001020]:8]) == a2(=0xfffffffffeeddead).
  The `beq` branch at 0x1910 targets 0x1934, is taken when a2(=[[0xa800000000001020]:8+128]:8) == 0, and falls through when a2(=[[0xa800000000001020]:8+128]:8) != 0.
  The `beq` branch at 0x1934 targets 0x1ae4, is taken when a0(=one of 0x0, 0x1) == 0, and falls through when a0(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x1950 targets 0x1968, is taken when v1(=a4) == 0, and falls through when v1(=a4) != 0.
  The `beq` branch at 0x1960 targets 0x1ad4, is taken when a0(=a5) == 0, and falls through when a0(=a5) != 0.
  The `beq` branch at 0x196c targets 0x1978, is taken when a1(=a3) == 0, and falls through when a1(=a3) != 0.
  The `beq` branch at 0x1988 targets 0x1a40, is taken when (a3(=0x10000000) & a0(=[a0+140])) == 0, and falls through when (a3(=0x10000000) & a0(=[a0+140])) != 0.
  The `bne` branch at 0x1994 targets 0x19d8, is taken when a4(=[sym(the_console_port)]:8) != s0(=a0), and falls through when a4(=[sym(the_console_port)]:8) == s0(=a0).
  The `bne` branch at 0x19b0 targets 0x19d8, is taken when a5(=[0xa800000000001000]:8) != a6(=0x53435241), and falls through when a5(=[0xa800000000001000]:8) == a6(=0x53435241).
  The `beq` branch at 0x19b8 targets 0x19d8, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x19c4 targets 0x19d8, is taken when a6(=[[0xa800000000001020]:8]) != a7(=0xfffffffffeeddead), and falls through when a6(=[[0xa800000000001020]:8]) == a7(=0xfffffffffeeddead).
  The `bne` branch at 0x19d0 targets 0x1b1c, is taken when t0(=[[0xa800000000001020]:8+128]:8) != 0, and falls through when t0(=[[0xa800000000001020]:8+128]:8) == 0.
  The `bne` branch at 0x19e4 targets 0x1a40, is taken when t1(=[sym(the_console_port)]:8) != s0(=a0), and falls through when t1(=[sym(the_console_port)]:8) == s0(=a0).
  The `bne` branch at 0x1a04 targets 0x1a3c, is taken when v1(=[0xa800000000001000]:8) != a0(=0x53435241), and falls through when v1(=[0xa800000000001000]:8) == a0(=0x53435241).
  The `beq` branch at 0x1a0c targets 0x1a40, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x1a18 targets 0x1a40, is taken when a0(=[[0xa800000000001020]:8]) != a1(=0xfffffffffeeddead), and falls through when a0(=[[0xa800000000001020]:8]) == a1(=0xfffffffffeeddead).
  The `beq` branch at 0x1a24 targets 0x1a3c, is taken when a2(=[[0xa800000000001020]:8+128]:8) == 0, and falls through when a2(=[[0xa800000000001020]:8+128]:8) != 0.
  The `beq` branch at 0x1a78 targets 0x1ab8, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0x1a8c targets 0x17fc and is always taken.
  The `bne` branch at 0x1aa0 targets 0x18cc, is taken when (t0(=[[a0+64]:8]) & a7(=0x40000000)) != 0, and falls through when (t0(=[[a0+64]:8]) & a7(=0x40000000)) == 0.
  The `beq` branch at 0x1aa8 targets 0x1a94, is taken when t1(?) == 0, and falls through when t1(?) != 0.
  The `beq` branch at 0x1ab0 targets 0x18d0 and is always taken.
  The `beq` branch at 0x1abc targets 0x1a80 and is always taken.
  The `beq` branch at 0x1ac4 targets 0x1844 and is always taken.
  The `beq` branch at 0x1acc targets 0x1844 and is always taken.
  The `bne` branch at 0x1ad4 targets 0x1974, is taken when t3(=a3) != 0, and falls through when t3(=a3) == 0.
  The `beq` branch at 0x1adc targets 0x1978 and is always taken.
  The `beq` branch at 0x1ae4 targets 0x17fc and is always taken.
  The `beq` branch at 0x1b14 targets 0x1898 and is always taken.
  The `beq` branch at 0x1b40 targets 0x19d8 and is always taken.
  The `beq` branch at 0x1b50 targets 0x1aa8 and is always taken.
  The return at 0x1808 has v0 = one of -0x1, 0x0, 0x1.

- `ioc4_enable_hfc` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc4.o)` at 0x1b58 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc4.o)`.
  Range: 0x1b58-0x1c7c (292 bytes).
  It occupies 292 bytes.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x8c, including `lw` at 0x1b5c, `lw` at 0x1c6c.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x8c, including `sw` at 0x1b74, `sw` at 0x1c44.
  2 such `ld` accesses load 8 bytes from abs 0xa800000000001000, including `ld` at 0x1b90, `ld` at 0x1be4.
  3 such `ld` accesses load 8 bytes from abs 0xa800000000001020, including `ld` at 0x1b94, `ld` at 0x1bd8, `ld` at 0x1c54.
  2 such `lw` accesses load 4 bytes from [0xa800000000001020]:8 +0x0, including `lw` at 0x1ba8, `lw` at 0x1bf8.
  3 such `ld` accesses load 8 bytes from [0xa800000000001020]:8 +0x80, including `ld` at 0x1bb4, `ld` at 0x1c04, `ld` at 0x1c58.
  The `ld` at 0x1bc0 loads 8 bytes from a0 (arg0 at entry) +0x40.
  The `sw` at 0x1bc8 stores 4 bytes to [a0+64]:8 +0x0.
  The `jalr` at 0x1c14 calls (unknown callee) with a0=0x1, a1=[sym(the_console_port)]:8, a2=?, a3=[[0xa800000000001020]:8+128]:8, a5=0xa800000000001020, a6=[a0+64]:8, a7=[[0xa800000000001020]:8].
  The `jal` at 0x1c1c calls splx with a0=[sym(.sbss)], a1=?, a2=?, a3=?.
  The `jal` at 0x1c48 calls spl7 with a0=[0xa800000000001000]:8, a1=[sym(the_console_port)]:8, a2=a2 at entry (arg2), a3=0x53435241, a5=[[0xa800000000001020]:8], a6=0xfffffffffeeddead, a7=[[0xa800000000001020]:8+128]:8.
  The `jalr` at 0x1c60 calls (unknown callee) with a0=0x0, a1=?, a2=?, a3=?.
  The `beq` branch at 0x1b68 targets 0x1c38, is taken when a1 == 0, and falls through when a1 != 0.
  The `bne` branch at 0x1b8c targets 0x1bc0, is taken when a1(=[sym(the_console_port)]:8) != s0(=a0), and falls through when a1(=[sym(the_console_port)]:8) == s0(=a0).
  The `bne` branch at 0x1b98 targets 0x1bc0, is taken when a0(=[0xa800000000001000]:8) != a3(=0x53435241), and falls through when a0(=[0xa800000000001000]:8) == a3(=0x53435241).
  The `beq` branch at 0x1ba0 targets 0x1bc0, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x1bac targets 0x1bc0, is taken when a5(=[[0xa800000000001020]:8]) != a6(=0xfffffffffeeddead), and falls through when a5(=[[0xa800000000001020]:8]) == a6(=0xfffffffffeeddead).
  The `bne` branch at 0x1bb8 targets 0x1c48, is taken when a7(=[[0xa800000000001020]:8+128]:8) != 0, and falls through when a7(=[[0xa800000000001020]:8+128]:8) == 0.
  The `bne` branch at 0x1be0 targets 0x1c28, is taken when a1(=[sym(the_console_port)]:8) != s0(=a0), and falls through when a1(=[sym(the_console_port)]:8) == s0(=a0).
  The `bne` branch at 0x1be8 targets 0x1c28, is taken when a0(=[0xa800000000001000]:8) != a3(=0x53435241), and falls through when a0(=[0xa800000000001000]:8) == a3(=0x53435241).
  The `beq` branch at 0x1bf0 targets 0x1c28, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x1bfc targets 0x1c28, is taken when a7(=[[0xa800000000001020]:8]) != t0(=0xfffffffffeeddead), and falls through when a7(=[[0xa800000000001020]:8]) == t0(=0xfffffffffeeddead).
  The `beq` branch at 0x1c08 targets 0x1c28, is taken when a3(=[[0xa800000000001020]:8+128]:8) == 0, and falls through when a3(=[[0xa800000000001020]:8+128]:8) != 0.
  The `beq` branch at 0x1c40 targets 0x1b78 and is always taken.
  The `beq` branch at 0x1c74 targets 0x1bc0 and is always taken.
  The return at 0x1c30 has v0 = 0x0.

- `ioc4_set_extclk` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc4.o)` at 0x1c7c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc4.o)`.
  Range: 0x1c7c-0x1c84 (8 bytes).
  It occupies 8 bytes.
  The return at 0x1c7c has v0 = a1.

- `do_ioc4_write` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc4.o)` at 0x1c84 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc4.o)`.
  Range: 0x1c84-0x1f00 (636 bytes).
  It occupies 636 bytes.
  3 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x40, including `ld` at 0x1c84, `ld` at 0x1e00, `ld` at 0x1e70.
  The `ld` at 0x1c88 loads 8 bytes from a0 (arg0 at entry) +0x60.
  The `lw` at 0x1c8c loads 4 bytes from [a0+64]:8 +0x8.
  The `ld` at 0x1c90 loads 8 bytes from a0 (arg0 at entry) +0x68.
  The `lw` at 0x1ca0 loads 4 bytes from a0 (arg0 at entry) +0x90.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x70, including `lw` at 0x1cdc, `lw` at 0x1d64, `lw` at 0x1ec8.
  The `sw` at 0x1cf4 stores 4 bytes to a0 (arg0 at entry) +0x90.
  3 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x1d20, `lbu` at 0x1d48, `lbu` at 0x1eb0.
  5 such `sb` accesses store 1 byte to ?, including `sb` at 0x1d28, `sb` at 0x1d34, `sb` at 0x1d50.
  The `sw` at 0x1d94 stores 4 bytes to ?.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x8c, including `lw` at 0x1da8, `lw` at 0x1ef0.
  The `sw` at 0x1db8 stores 4 bytes to a0 (arg0 at entry) +0x8c.
  2 such `ld` accesses load 8 bytes from abs 0xa800000000001000, including `ld` at 0x1dd0, `ld` at 0x1e1c.
  3 such `ld` accesses load 8 bytes from abs 0xa800000000001020, including `ld` at 0x1ddc, `ld` at 0x1e28, `ld` at 0x1ed8.
  2 such `lw` accesses load 4 bytes from [0xa800000000001020]:8 +0x0, including `lw` at 0x1de8, `lw` at 0x1e34.
  3 such `ld` accesses load 8 bytes from [0xa800000000001020]:8 +0x80, including `ld` at 0x1df4, `ld` at 0x1e44, `ld` at 0x1edc.
  The `sw` at 0x1e04 stores 4 bytes to [a0+64]:8 +0x0.
  The `sw` at 0x1e78 stores 4 bytes to [a0+64]:8 +0x4.
  The `lw` at 0x1e84 loads 4 bytes from [a0+104]:8 +0x8.
  The `lw` at 0x1e90 loads 4 bytes from a0 (arg0 at entry) +0x7c.
  The `sw` at 0x1eac stores 4 bytes to a0 (arg0 at entry) +0x70.
  The `jalr` at 0x1e58 calls (unknown callee) with a0=0x1, a1=[[0xa800000000001020]:8+128]:8, a2=[sym(.sbss)], a3=?.
  The `jal` at 0x1e60 calls splx with a0=[sym(.sbss)], a1=?, a2=?, a3=?.
  The `jal` at 0x1e80 calls enable_intrs with a0=a0 at entry (arg0), a1=[[a0+104]:8+8], a2=?, a3=[a0+64]:8.
  The `jal` at 0x1ecc calls spl7 with a0=(0x10000000 | [a0+140]), a1=0xa800000000001020, a2=0xfffffffffeeddead, a3=[[0xa800000000001020]:8+128]:8, a6=([a0+140] << 0x23), a7=0x40.
  The `jalr` at 0x1ee4 calls (unknown callee) with a0=0x0, a1=?, a2=?, a3=?.
  The `beq` branch at 0x1cc0 targets 0x1cd8, is taken when a6(?) == s2(=[a0+144]), and falls through when a6(?) != s2(=[a0+144]).
  The `blez` branch at 0x1cc8 targets 0x1ec0, is taken when a2 <= 0 (signed), and falls through when a2 > 0 (signed).
  The `beq` branch at 0x1cd0 targets 0x1d88 and is always taken.
  The `beq` branch at 0x1ce4 targets 0x1e70, is taken when (a7(=[a0+112]) & 0x10) == 0, and falls through when (a7(=[a0+112]) & 0x10) != 0.
  The `blez` branch at 0x1d08 targets 0x1d64, is taken when a2(?) <= 0 (signed), and falls through when a2(?) > 0 (signed).
  The `beq` branch at 0x1d38 targets 0x1d64, is taken when v0(?) >= 0x4 (signed), and falls through when v0(?) < 0x4 (signed).
  The `blez` branch at 0x1d40 targets 0x1d64, is taken when a2(?) <= 0 (signed), and falls through when a2(?) > 0 (signed).
  The `bne` branch at 0x1d5c targets 0x1d08, is taken when a4(?) != 0, and falls through when a4(?) == 0.
  The `beq` branch at 0x1d6c targets 0x1e90, is taken when (v0(=[a0+112]) & 0x4) == 0, and falls through when (v0(=[a0+112]) & 0x4) != 0.
  The `beq` branch at 0x1d78 targets 0x1da0, is taken when a6(?) == s2(?), and falls through when a6(?) != s2(?).
  The `blez` branch at 0x1d80 targets 0x1da0, is taken when a2(?) <= 0 (signed), and falls through when a2(?) > 0 (signed).
  The `blez` branch at 0x1d90 targets 0x1d64, is taken when a2(?) <= 0 (signed), and falls through when a2(?) > 0 (signed).
  The `beq` branch at 0x1d98 targets 0x1d10 and is always taken.
  The `blez` branch at 0x1da0 targets 0x1cdc, is taken when s0(?) <= 0 (signed), and falls through when s0(?) > 0 (signed).
  The `bltz` branch at 0x1db0 targets 0x1cdc, is taken when a6(=([a0+140] << 0x23)) < 0 (signed), and falls through when a6(=([a0+140] << 0x23)) >= 0 (signed).
  The `bne` branch at 0x1dcc targets 0x1e00, is taken when a3(=[sym(the_console_port)]:8) != s1(=a0), and falls through when a3(=[sym(the_console_port)]:8) == s1(=a0).
  The `bne` branch at 0x1dd4 targets 0x1e00, is taken when a1(=[0xa800000000001000]:8) != v0(=0x53435241), and falls through when a1(=[0xa800000000001000]:8) == v0(=0x53435241).
  The `beq` branch at 0x1de0 targets 0x1e00, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x1dec targets 0x1e00, is taken when v1(=[[0xa800000000001020]:8]) != a2(=0xfffffffffeeddead), and falls through when v1(=[[0xa800000000001020]:8]) == a2(=0xfffffffffeeddead).
  The `bne` branch at 0x1df8 targets 0x1ecc, is taken when a3(=[[0xa800000000001020]:8+128]:8) != 0, and falls through when a3(=[[0xa800000000001020]:8+128]:8) == 0.
  The `bne` branch at 0x1e18 targets 0x1cdc, is taken when v1(=[sym(the_console_port)]:8) != s1(=a0), and falls through when v1(=[sym(the_console_port)]:8) == s1(=a0).
  The `bne` branch at 0x1e20 targets 0x1cdc, is taken when v0(=[0xa800000000001000]:8) != a1(=0x53435241), and falls through when v0(=[0xa800000000001000]:8) == a1(=0x53435241).
  The `beq` branch at 0x1e2c targets 0x1cdc, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x1e3c targets 0x1cdc, is taken when v1(=[[0xa800000000001020]:8]) != a0(=0xfffffffffeeddead), and falls through when v1(=[[0xa800000000001020]:8]) == a0(=0xfffffffffeeddead).
  The `beq` branch at 0x1e48 targets 0x1cdc, is taken when a1(=[[0xa800000000001020]:8+128]:8) == 0, and falls through when a1(=[[0xa800000000001020]:8+128]:8) != 0.
  The `beq` branch at 0x1e68 targets 0x1cdc and is always taken.
  The `blez` branch at 0x1e74 targets 0x1ce8, is taken when s0(?) <= 0 (signed), and falls through when s0(?) > 0 (signed).
  The `beq` branch at 0x1e88 targets 0x1cec and is always taken.
  The `bne` branch at 0x1ea4 targets 0x1d74, is taken when a4(=([a0+124] << 0x3)) < a5(?) (signed), and falls through when a4(=([a0+124] << 0x3)) >= a5(?) (signed).
  The `beq` branch at 0x1eb8 targets 0x1d74 and is always taken.
  The `beq` branch at 0x1ec4 targets 0x1ce0 and is always taken.
  The `beq` branch at 0x1ef8 targets 0x1e00 and is always taken.
  The return at 0x1d00 has v0 = ?.

- `ioc4_write` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc4.o)` at 0x1f00 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc4.o)`.
  Range: 0x1f00-0x1f1c (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x1f08 calls do_ioc4_write with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x1f14 has v0 = ret(do_ioc4_write).

- `ioc4_sync_write` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc4.o)` at 0x1f1c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc4.o)`.
  Range: 0x1f1c-0x1f80 (100 bytes).
  It occupies 100 bytes.
  The `lw` at 0x1f4c loads 4 bytes from a0 (arg0 at entry) +0x70.
  The `jal` at 0x1f30 calls do_ioc4_write with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1f60 calls ioc4_enable_tx with a0=a0 at entry (arg0), a1=0x1, a2=?, a3=?.
  The `blez` branch at 0x1f38 targets 0x1f68, is taken when s3(=a2) <= 0 (signed), and falls through when s3(=a2) > 0 (signed).
  The `bne` branch at 0x1f40 targets 0x1f6c, is taken when v0(=ret(do_ioc4_write)) != 0, and falls through when v0(=ret(do_ioc4_write)) == 0.
  The `beq` branch at 0x1f54 targets 0x1f6c, is taken when (at(=[a0+112]) & 0x10) == 0, and falls through when (at(=[a0+112]) & 0x10) != 0.
  The return at 0x1f78 has v0 = ret(do_ioc4_write).

- `ioc4_wrflush` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc4.o)` at 0x1f80 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc4.o)`.
  Range: 0x1f80-0x2044 (196 bytes).
  It occupies 196 bytes.
  3 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x38, including `ld` at 0x1f80, `ld` at 0x1fbc, `ld` at 0x2004.
  3 such `lw` accesses load 4 bytes from [a0+56]:8 +0x8, including `lw` at 0x1f84, `lw` at 0x1fc0, `lw` at 0x2008.
  3 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x40, including `ld` at 0x1fa0, `ld` at 0x1ff8, `ld` at 0x2020.
  2 such `lw` accesses load 4 bytes from [a0+64]:8 +0x0, including `lw` at 0x1fa4, `lw` at 0x2024.
  The `lw` at 0x1fdc loads 4 bytes from a0 (arg0 at entry) +0x70.
  The `jal` at 0x1fec calls ioc4_enable_tx with a0=a0 at entry (arg0), a1=0x1, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x2018 calls us_delay with a0=0x5, a1=?, a2=one of 0x10000000, 0x50000000, a3=?.
  The `beq` branch at 0x1f98 targets 0x1fdc, is taken when (at(=[[a0+56]:8+8]) & 0x1) == 0, and falls through when (at(=[[a0+56]:8+8]) & 0x1) != 0.
  The `bne` branch at 0x1fb4 targets 0x1fd0, is taken when a0(=0x10000000) != v0(?), and falls through when a0(=0x10000000) == v0(?).
  The `beq` branch at 0x1fc8 targets 0x1ffc, is taken when (v1(=[[a0+56]:8+8]) & 0x1) == 0, and falls through when (v1(=[[a0+56]:8+8]) & 0x1) != 0.
  The `beq` branch at 0x1fe4 targets 0x1fa0, is taken when (a0(=[a0+112]) & 0x10) == 0, and falls through when (a0(=[a0+112]) & 0x10) != 0.
  The `beq` branch at 0x1ff4 targets 0x1fa4 and is always taken.
  The `beq` branch at 0x1ffc targets 0x2018 and is always taken.
  The `bne` branch at 0x2010 targets 0x203c, is taken when (a1(=[[a0+56]:8+8]) & 0x1) != 0, and falls through when (a1(=[[a0+56]:8+8]) & 0x1) == 0.
  The `beq` branch at 0x2034 targets 0x2004, is taken when a2(=0x10000000) == a3(?), and falls through when a2(=0x10000000) != a3(?).
  The `beq` branch at 0x203c targets 0x1fd0 and is always taken.
  The return at 0x1fd4 has v0 = one of ?, ret(us_delay).

- `ioc4_break` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc4.o)` at 0x2044 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc4.o)`.
  Range: 0x2044-0x22ec (680 bytes).
  It occupies 680 bytes.
  4 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x8c, including `lw` at 0x2044, `lw` at 0x2170, `lw` at 0x229c.
  4 such `ld` accesses load 8 bytes from abs 0xa800000000001000, including `ld` at 0x2078, `ld` at 0x2104, `ld` at 0x2190.
  6 such `ld` accesses load 8 bytes from abs 0xa800000000001020, including `ld` at 0x208c, `ld` at 0x2108, `ld` at 0x21a4.
  4 such `lw` accesses load 4 bytes from [0xa800000000001020]:8 +0x0, including `lw` at 0x2098, `lw` at 0x211c, `lw` at 0x21b0.
  6 such `ld` accesses load 8 bytes from [0xa800000000001020]:8 +0x80, including `ld` at 0x20a4, `ld` at 0x2128, `ld` at 0x21bc.
  3 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x40, including `ld` at 0x20b0, `ld` at 0x20c0, `ld` at 0x21c8.
  2 such `sw` accesses store 4 bytes to [a0+64]:8 +0x0, including `sw` at 0x20bc, `sw` at 0x21cc.
  2 such `lw` accesses load 4 bytes from [a0+64]:8 +0x0, including `lw` at 0x20c4, `lw` at 0x2244.
  The `ld` at 0x215c loads 8 bytes from a0 (arg0 at entry) +0x48.
  The `lbu` at 0x2164 loads 1 byte from [a0+72]:8 +0x3.
  2 such `sb` accesses store 1 byte to [a0+72]:8 +0x3, including `sb` at 0x216c, `sb` at 0x2274.
  The `jalr` at 0x213c calls (unknown callee) with a0=0x1, a1=a1 at entry (arg1), a2=[[0xa800000000001020]:8], a3=0xfffffffffeeddead, a4=[[0xa800000000001020]:8+128]:8, a5=[sym(.sbss)], a6=0x10000000, a7=[sym(the_console_port)]:8.
  The `jal` at 0x2144 calls splx with a0=[sym(.sbss)], a1=?, a2=?, a3=?.
  The `jalr` at 0x221c calls (unknown callee) with a0=0x1, a1=?, a2=?, a3=?, a4=[[0xa800000000001020]:8+128]:8.
  The `jal` at 0x2224 calls splx with a0=[sym(.sbss)], a1=?, a2=?, a3=?.
  The `jal` at 0x2280 calls spl7 with a0=[a0+72]:8, a1=a1 at entry (arg1), a2=?, a3=?, a4=[a0+140], a6=0x10000000.
  The `jalr` at 0x2294 calls (unknown callee) with a0=0x0, a1=?, a2=?, a3=?, a5=[[0xa800000000001020]:8+128]:8.
  The `jal` at 0x22ac calls spl7 with a0=[[0xa800000000001020]:8], a1=a1 at entry (arg1), a2=0xfffffffffeeddead, a3=[[0xa800000000001020]:8+128]:8, a4=[a0+140], a6=0x10000000.
  The `jalr` at 0x22c0 calls (unknown callee) with a0=0x0, a1=?, a2=?, a3=?, a7=[[0xa800000000001020]:8+128]:8.
  The `bgez` branch at 0x2060 targets 0x215c, is taken when at(=([a0+140] << 0x23)) >= 0 (signed), and falls through when at(=([a0+140] << 0x23)) < 0 (signed).
  The `bne` branch at 0x206c targets 0x20b0, is taken when v0(=[sym(the_console_port)]:8) != a0, and falls through when v0(=[sym(the_console_port)]:8) == a0.
  The `bne` branch at 0x2088 targets 0x20b0, is taken when v1(=[0xa800000000001000]:8) != a0(=0x53435241), and falls through when v1(=[0xa800000000001000]:8) == a0(=0x53435241).
  The `beq` branch at 0x2090 targets 0x20b0, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x209c targets 0x20b0, is taken when a0(=[[0xa800000000001020]:8]) != a2(=0xfffffffffeeddead), and falls through when a0(=[[0xa800000000001020]:8]) == a2(=0xfffffffffeeddead).
  The `bne` branch at 0x20a8 targets 0x22ac, is taken when a3(=[[0xa800000000001020]:8+128]:8) != 0, and falls through when a3(=[[0xa800000000001020]:8+128]:8) == 0.
  The `bltz` branch at 0x20d8 targets 0x20e8, is taken when t0(=([[a0+64]:8] << 0x21)) < 0 (signed), and falls through when t0(=([[a0+64]:8] << 0x21)) >= 0 (signed).
  The `beq` branch at 0x20e0 targets 0x22e0 and is always taken.
  The `bne` branch at 0x2100 targets 0x2154, is taken when a7(=[sym(the_console_port)]:8) != s0(=a0), and falls through when a7(=[sym(the_console_port)]:8) == s0(=a0).
  The `bne` branch at 0x210c targets 0x2154, is taken when a4(=[0xa800000000001000]:8) != a0(=0x53435241), and falls through when a4(=[0xa800000000001000]:8) == a0(=0x53435241).
  The `beq` branch at 0x2114 targets 0x2154, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x2120 targets 0x2154, is taken when a2(=[[0xa800000000001020]:8]) != a3(=0xfffffffffeeddead), and falls through when a2(=[[0xa800000000001020]:8]) == a3(=0xfffffffffeeddead).
  The `beq` branch at 0x212c targets 0x2154, is taken when a4(=[[0xa800000000001020]:8+128]:8) == 0, and falls through when a4(=[[0xa800000000001020]:8+128]:8) != 0.
  The `beq` branch at 0x2154 targets 0x2278, is taken when s1(=one of 0x0, 0x1) == 0, and falls through when s1(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x2160 targets 0x2268, is taken when a1 == 0, and falls through when a1 != 0.
  The `beq` branch at 0x2178 targets 0x2230, is taken when (a6(=0x10000000) & a4(=[a0+140])) == 0, and falls through when (a6(=0x10000000) & a4(=[a0+140])) != 0.
  The `bne` branch at 0x2184 targets 0x21c8, is taken when t1(=[sym(the_console_port)]:8) != s0(=a0), and falls through when t1(=[sym(the_console_port)]:8) == s0(=a0).
  The `bne` branch at 0x21a0 targets 0x21c8, is taken when t2(=[0xa800000000001000]:8) != t3(=0x53435241), and falls through when t2(=[0xa800000000001000]:8) == t3(=0x53435241).
  The `beq` branch at 0x21a8 targets 0x21c8, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x21b4 targets 0x21c8, is taken when t3(=[[0xa800000000001020]:8]) != t8(=0xfffffffffeeddead), and falls through when t3(=[[0xa800000000001020]:8]) == t8(=0xfffffffffeeddead).
  The `bne` branch at 0x21c0 targets 0x2280, is taken when t9(=[[0xa800000000001020]:8+128]:8) != 0, and falls through when t9(=[[0xa800000000001020]:8+128]:8) == 0.
  The `bne` branch at 0x21d4 targets 0x2230, is taken when ra(=[sym(the_console_port)]:8) != s0(=a0), and falls through when ra(=[sym(the_console_port)]:8) == s0(=a0).
  The `bne` branch at 0x21ec targets 0x222c, is taken when v0(=[0xa800000000001000]:8) != v1(=0x53435241), and falls through when v0(=[0xa800000000001000]:8) == v1(=0x53435241).
  The `beq` branch at 0x21f8 targets 0x222c, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x2204 targets 0x222c, is taken when v1(=[[0xa800000000001020]:8]) != a0(=0xfffffffffeeddead), and falls through when v1(=[[0xa800000000001020]:8]) == a0(=0xfffffffffeeddead).
  The `beq` branch at 0x2210 targets 0x2230, is taken when a4(=[[0xa800000000001020]:8+128]:8) == 0, and falls through when a4(=[[0xa800000000001020]:8+128]:8) != 0.
  The `bne` branch at 0x2250 targets 0x20e8, is taken when (a2(=[[a0+64]:8]) & a7(=0x40000000)) != 0, and falls through when (a2(=[[a0+64]:8]) & a7(=0x40000000)) == 0.
  The `beq` branch at 0x2258 targets 0x2244, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0x2260 targets 0x20f0 and is always taken.
  The `beq` branch at 0x2270 targets 0x2170 and is always taken.
  The `beq` branch at 0x2278 targets 0x2230 and is always taken.
  The `beq` branch at 0x22a4 targets 0x21c8 and is always taken.
  The `beq` branch at 0x22d8 targets 0x20b0 and is always taken.
  The `beq` branch at 0x22e4 targets 0x2258 and is always taken.
  The return at 0x223c has v0 = one of -0x1, 0x0.

- `ioc4_enable_tx` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc4.o)` at 0x22ec (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc4.o)`.
  Range: 0x22ec-0x24fc (528 bytes).
  It occupies 528 bytes.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x70, including `lw` at 0x22f8, `lw` at 0x23c4.
  The `ld` at 0x2300 loads 8 bytes from a0 (arg0 at entry) +0x68.
  2 such `ld` accesses load 8 bytes from abs 0xa800000000001000, including `ld` at 0x232c, `ld` at 0x240c.
  3 such `ld` accesses load 8 bytes from abs 0xa800000000001020, including `ld` at 0x2330, `ld` at 0x2410, `ld` at 0x24d8.
  2 such `lw` accesses load 4 bytes from [0xa800000000001020]:8 +0x0, including `lw` at 0x2344, `lw` at 0x2434.
  3 such `ld` accesses load 8 bytes from [0xa800000000001020]:8 +0x80, including `ld` at 0x2350, `ld` at 0x2440, `ld` at 0x24dc.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x8c, including `lw` at 0x235c, `lw` at 0x23e8.
  4 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x40, including `ld` at 0x2368, `ld` at 0x2378, `ld` at 0x2400.
  2 such `sw` accesses store 4 bytes to [a0+64]:8 +0x0, including `sw` at 0x2374, `sw` at 0x2404.
  2 such `lw` accesses load 4 bytes from [a0+64]:8 +0x0, including `lw` at 0x237c, `lw` at 0x23ac.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x90, including `lw` at 0x23c8, `lw` at 0x24a4.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x70, including `sw` at 0x23d4, `sw` at 0x248c.
  2 such `sw` accesses store 4 bytes to [a0+64]:8 +0x4, including `sw` at 0x23d8, `sw` at 0x24c0.
  2 such `lw` accesses load 4 bytes from [a0+104]:8 +0x8, including `lw` at 0x23e4, `lw` at 0x2494.
  The `lw` at 0x2484 loads 4 bytes from [a0+64]:8 +0x8.
  The `jal` at 0x23e0 calls enable_intrs with a0=a0 at entry (arg0), a1=[[a0+104]:8+8], a2=?, a3=?, a4=[a0+64]:8.
  The `jalr` at 0x244c calls (unknown callee) with a0=0x1, a1=[[0xa800000000001020]:8+128]:8, a2=[sym(the_console_port)]:8, a3=[[0xa800000000001020]:8], a4=0xfffffffffeeddead, a5=0xa800000000001000.
  The `jal` at 0x2454 calls splx with a0=[sym(.sbss)], a1=?, a2=?, a3=?.
  The `jal` at 0x249c calls disable_intrs with a0=a0 at entry (arg0), a1=[[a0+104]:8+8], a2=?, a3=?, a4=[a0+64]:8, a6=([a0+112] | 0x10).
  The `jal` at 0x24cc calls spl7 with a0=0x53435241, a1=a1 at entry (arg1), a2=[[0xa800000000001020]:8], a3=0xfffffffffeeddead, a4=[[0xa800000000001020]:8+128]:8, a5=0xa800000000001020, a6=[sym(the_console_port)]:8.
  The `jalr` at 0x24e4 calls (unknown callee) with a0=0x0, a1=?, a2=?, a3=?.
  The `beq` branch at 0x2308 targets 0x2474, is taken when a1 == 0, and falls through when a1 != 0.
  The `beq` branch at 0x2310 targets 0x247c, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `bne` branch at 0x2328 targets 0x235c, is taken when a6(=[sym(the_console_port)]:8) != s0(=a0), and falls through when a6(=[sym(the_console_port)]:8) == s0(=a0).
  The `bne` branch at 0x2334 targets 0x235c, is taken when a4(=[0xa800000000001000]:8) != a0(=0x53435241), and falls through when a4(=[0xa800000000001000]:8) == a0(=0x53435241).
  The `beq` branch at 0x233c targets 0x235c, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x2348 targets 0x235c, is taken when a2(=[[0xa800000000001020]:8]) != a3(=0xfffffffffeeddead), and falls through when a2(=[[0xa800000000001020]:8]) == a3(=0xfffffffffeeddead).
  The `bne` branch at 0x2354 targets 0x24cc, is taken when a4(=[[0xa800000000001020]:8+128]:8) != 0, and falls through when a4(=[[0xa800000000001020]:8+128]:8) == 0.
  The `bgez` branch at 0x2364 targets 0x23c0, is taken when a5(=([a0+140] << 0x23)) >= 0 (signed), and falls through when a5(=([a0+140] << 0x23)) < 0 (signed).
  The `bltz` branch at 0x2394 targets 0x23c0, is taken when t0(=([[a0+64]:8] << 0x21)) < 0 (signed), and falls through when t0(=([[a0+64]:8] << 0x21)) >= 0 (signed).
  The `bne` branch at 0x23a4 targets 0x24c4, is taken when t2(?) != 0, and falls through when t2(?) == 0.
  The `beq` branch at 0x23b8 targets 0x23a4, is taken when (t3(=[[a0+64]:8]) & a6(=0x40000000)) == 0, and falls through when (t3(=[[a0+64]:8]) & a6(=0x40000000)) != 0.
  The `beq` branch at 0x23c0 targets 0x2484, is taken when a1 == 0, and falls through when a1 != 0.
  The `beq` branch at 0x23f8 targets 0x2408, is taken when (ra(=0x10000000) & a0(=[a0+140])) == 0, and falls through when (ra(=0x10000000) & a0(=[a0+140])) != 0.
  The `bne` branch at 0x241c targets 0x245c, is taken when a2(=[sym(the_console_port)]:8) != s0(=a0), and falls through when a2(=[sym(the_console_port)]:8) == s0(=a0).
  The `bne` branch at 0x2424 targets 0x245c, is taken when a1(=[0xa800000000001000]:8) != a0(=0x53435241), and falls through when a1(=[0xa800000000001000]:8) == a0(=0x53435241).
  The `beq` branch at 0x242c targets 0x245c, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x2438 targets 0x245c, is taken when a3(=[[0xa800000000001020]:8]) != a4(=0xfffffffffeeddead), and falls through when a3(=[[0xa800000000001020]:8]) == a4(=0xfffffffffeeddead).
  The `beq` branch at 0x2444 targets 0x245c, is taken when a1(=[[0xa800000000001020]:8+128]:8) == 0, and falls through when a1(=[[0xa800000000001020]:8+128]:8) != 0.
  The `beq` branch at 0x2474 targets 0x2318, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x247c targets 0x2460 and is always taken.
  The `beq` branch at 0x24b0 targets 0x23e8, is taken when a7(=[a0+144]) == v0(?), and falls through when a7(=[a0+144]) != v0(?).
  The `beq` branch at 0x24bc targets 0x23e8 and is always taken.
  The `beq` branch at 0x24c4 targets 0x2464 and is always taken.
  The `beq` branch at 0x24f4 targets 0x235c and is always taken.
  The return at 0x246c has v0 = one of -0x1, 0x0.

- `ioc4_read` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc4.o)` at 0x24fc (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc4.o)`.
  Range: 0x24fc-0x2bec (1776 bytes).
  It occupies 1776 bytes.
  The `ld` at 0x2508 loads 8 bytes from a0 (arg0 at entry) +0x68.
  10 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x40, including `ld` at 0x2520, `ld` at 0x2538, `ld` at 0x2624.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x94, including `lw` at 0x2524, `lw` at 0x2544.
  3 such `sw` accesses store 4 bytes to [a0+64]:8 +0x10, including `sw` at 0x2534, `sw` at 0x28d0, `sw` at 0x2b98.
  3 such `lw` accesses load 4 bytes from [a0+64]:8 +0xc, including `lw` at 0x2540, `lw` at 0x2628, `lw` at 0x26f4.
  5 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x8c, including `lw` at 0x2564, `lw` at 0x2704, `lw` at 0x28e4.
  6 such `ld` accesses load 8 bytes from abs 0xa800000000001000, including `ld` at 0x2584, `ld` at 0x25d8, `ld` at 0x2640.
  9 such `ld` accesses load 8 bytes from abs 0xa800000000001020, including `ld` at 0x2598, `ld` at 0x25ec, `ld` at 0x2654.
  6 such `lw` accesses load 4 bytes from [0xa800000000001020]:8 +0x0, including `lw` at 0x25a4, `lw` at 0x25f8, `lw` at 0x2660.
  9 such `ld` accesses load 8 bytes from [0xa800000000001020]:8 +0x80, including `ld` at 0x25b4, `ld` at 0x2608, `ld` at 0x266c.
  2 such `sw` accesses store 4 bytes to [a0+64]:8 +0x0, including `sw` at 0x25c8, `sw` at 0x275c.
  2 such `lw` accesses load 4 bytes from [a0+64]:8 +0x0, including `lw` at 0x2678, `lw` at 0x2a4c.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x8c, including `sw` at 0x2710, `sw` at 0x2a9c.
  4 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x70, including `lw` at 0x27b8, `lw` at 0x2830, `lw` at 0x28d4.
  The `ld` at 0x27bc loads 8 bytes from a0 (arg0 at entry) +0x58.
  4 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x70, including `sw` at 0x27cc, `sw` at 0x2a78, `sw` at 0x2adc.
  5 such `lw` accesses load 4 bytes from ?, including `lw` at 0x27f0, `lw` at 0x28b0, `lw` at 0x2a24.
  7 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x280c, `lbu` at 0x2874, `lbu` at 0x2964.
  5 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x84, including `lw` at 0x2820, `lw` at 0x2898, `lw` at 0x2974.
  5 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x8, including `ld` at 0x2858, `ld` at 0x2948, `ld` at 0x2984.
  4 such `ld` accesses load 8 bytes from [a0+8]:8 +0x10, including `ld` at 0x2864, `ld` at 0x2954, `ld` at 0x2990.
  4 such `sb` accesses store 1 byte to ?, including `sb` at 0x2880, `sb` at 0x29f4, `sb` at 0x2a08.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x94, including `sw` at 0x28e0, `sw` at 0x2ba8.
  The `lw` at 0x2a84 loads 4 bytes from [a0+104]:8 +0x10.
  The `ld` at 0x2bb8 loads 8 bytes from [a0+8]:8 +0x18.
  The `jalr` at 0x2614 calls (unknown callee) with a0=0x1, a1=?, a2=[[0xa800000000001020]:8+128]:8, a3=?, a5=[a0+64]:8, a7=[sym(the_console_port)]:8.
  The `jal` at 0x261c calls splx with a0=[sym(.sbss)], a1=?, a2=?, a3=?.
  The `jalr` at 0x26d8 calls (unknown callee) with a0=0x1, a1=[0xa800000000001000]:8, a2=[[0xa800000000001020]:8+128]:8, a3=?, a5=[a0+64]:8.
  The `jal` at 0x26e0 calls splx with a0=[sym(.sbss)], a1=?, a2=?, a3=?.
  The `jalr` at 0x27a8 calls (unknown callee) with a0=0x1, a1=?, a2=[[0xa800000000001020]:8+128]:8, a3=?, a5=[a0+64]:8, a7=[sym(the_console_port)]:8.
  The `jal` at 0x27b0 calls splx with a0=[sym(.sbss)], a1=?, a2=?, a3=?.
  The `jalr` at 0x286c calls (unknown callee) with a0=a0 at entry (arg0), a1=0x8, a2=[a0+132], a3=?.
  The `jalr` at 0x295c calls (unknown callee) with a0=a0 at entry (arg0), a1=0x2, a2=[a0+132], a3=?.
  The `jalr` at 0x2998 calls (unknown callee) with a0=a0 at entry (arg0), a1=0x4, a2=?, a3=?.
  The `jalr` at 0x29d4 calls (unknown callee) with a0=a0 at entry (arg0), a1=0x1, a2=?, a3=?.
  The `jal` at 0x2a80 calls enable_intrs with a0=a0 at entry (arg0), a1=[[a0+104]:8+16], a2=?, a3=?, a4=[a0+64]:8.
  The `jal` at 0x2ae8 calls spl7 with a0=?, a1=[sym(the_console_port)]:8, a2=[0xa800000000001000]:8, a3=[[0xa800000000001020]:8], a4=0xfffffffffeeddead, a5=[a0+64]:8, a6=[[0xa800000000001020]:8+128]:8.
  The `jalr` at 0x2afc calls (unknown callee) with a0=0x0, a1=?, a2=?, a3=?, a5=[[0xa800000000001020]:8+128]:8.
  The `jal` at 0x2b14 calls spl7 with a0=?, a1=0xffffffffefffffff, a2=[0xa800000000001000]:8, a3=[[0xa800000000001020]:8], a4=0xfffffffffeeddead, a5=[a0+64]:8, a6=[[0xa800000000001020]:8+128]:8.
  The `jalr` at 0x2b28 calls (unknown callee) with a0=0x0, a1=?, a2=?, a3=?, a6=[[0xa800000000001020]:8+128]:8.
  The `jal` at 0x2b40 calls spl7 with a0=?, a1=?, a2=[sym(the_console_port)]:8, a3=?, a5=[a0+64]:8.
  The `jalr` at 0x2b54 calls (unknown callee) with a0=0x0, a1=?, a2=?, a3=?, a7=[[0xa800000000001020]:8+128]:8.
  The `jalr` at 0x2bc0 calls (unknown callee) with a0=a0 at entry (arg0), a1=0x0, a2=[a0+132], a3=?.
  The `bne` branch at 0x255c targets 0x27b8, is taken when s4(?) != s1(=[a0+148]), and falls through when s4(?) == s1(=[a0+148]).
  The `bgez` branch at 0x256c targets 0x2a90, is taken when v1(=([a0+140] << 0x23)) >= 0 (signed), and falls through when v1(=([a0+140] << 0x23)) < 0 (signed).
  The `bne` branch at 0x257c targets 0x25c0, is taken when a1(=[sym(the_console_port)]:8) != s0(=a0), and falls through when a1(=[sym(the_console_port)]:8) == s0(=a0).
  The `bne` branch at 0x2590 targets 0x25c0, is taken when a2(=[0xa800000000001000]:8) != a3(=0x53435241), and falls through when a2(=[0xa800000000001000]:8) == a3(=0x53435241).
  The `beq` branch at 0x259c targets 0x25c0, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x25ac targets 0x25c0, is taken when a3(=[[0xa800000000001020]:8]) != a4(=0xfffffffffeeddead), and falls through when a3(=[[0xa800000000001020]:8]) == a4(=0xfffffffffeeddead).
  The `bne` branch at 0x25b8 targets 0x2ae8, is taken when a6(=[[0xa800000000001020]:8+128]:8) != 0, and falls through when a6(=[[0xa800000000001020]:8+128]:8) == 0.
  The `bne` branch at 0x25d0 targets 0x2624, is taken when a7(=[sym(the_console_port)]:8) != s0(=a0), and falls through when a7(=[sym(the_console_port)]:8) == s0(=a0).
  The `bne` branch at 0x25e4 targets 0x2624, is taken when t1(=[0xa800000000001000]:8) != t2(=0x53435241), and falls through when t1(=[0xa800000000001000]:8) == t2(=0x53435241).
  The `beq` branch at 0x25f0 targets 0x2624, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x2600 targets 0x2624, is taken when v1(=[[0xa800000000001020]:8]) != a0(=0xfffffffffeeddead), and falls through when v1(=[[0xa800000000001020]:8]) == a0(=0xfffffffffeeddead).
  The `beq` branch at 0x260c targets 0x2624, is taken when a2(=[[0xa800000000001020]:8+128]:8) == 0, and falls through when a2(=[[0xa800000000001020]:8+128]:8) != 0.
  The `bne` branch at 0x2630 targets 0x26fc, is taken when s4(?) != s1(=[a0+148]), and falls through when s4(?) == s1(=[a0+148]).
  The `bne` branch at 0x2638 targets 0x2678, is taken when s0(=a0) != a2(=[sym(the_console_port)]:8), and falls through when s0(=a0) == a2(=[sym(the_console_port)]:8).
  The `bne` branch at 0x264c targets 0x2678, is taken when t8(=[0xa800000000001000]:8) != t9(=0x53435241), and falls through when t8(=[0xa800000000001000]:8) == t9(=0x53435241).
  The `beq` branch at 0x2658 targets 0x2678, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x2664 targets 0x2678, is taken when t9(=[[0xa800000000001020]:8]) != ra(=0xfffffffffeeddead), and falls through when t9(=[[0xa800000000001020]:8]) == ra(=0xfffffffffeeddead).
  The `bne` branch at 0x2670 targets 0x2b40, is taken when at(=[[0xa800000000001020]:8+128]:8) != 0, and falls through when at(=[[0xa800000000001020]:8+128]:8) == 0.
  The `beq` branch at 0x2680 targets 0x2694, is taken when (v0(=[[a0+64]:8]) & s2(=0x8000000)) == 0, and falls through when (v0(=[[a0+64]:8]) & s2(=0x8000000)) != 0.
  The `beq` branch at 0x268c targets 0x2bdc and is always taken.
  The `bne` branch at 0x2698 targets 0x26e8, is taken when s0(=a0) != a2(=[sym(the_console_port)]:8), and falls through when s0(=a0) == a2(=[sym(the_console_port)]:8).
  The `bne` branch at 0x26ac targets 0x26e8, is taken when a1(=[0xa800000000001000]:8) != a2(=0x53435241), and falls through when a1(=[0xa800000000001000]:8) == a2(=0x53435241).
  The `beq` branch at 0x26b8 targets 0x26e8, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x26c4 targets 0x26e8, is taken when v1(=[[0xa800000000001020]:8]) != a0(=0xfffffffffeeddead), and falls through when v1(=[[0xa800000000001020]:8]) == a0(=0xfffffffffeeddead).
  The `beq` branch at 0x26d0 targets 0x26e8, is taken when a2(=[[0xa800000000001020]:8+128]:8) == 0, and falls through when a2(=[[0xa800000000001020]:8+128]:8) != 0.
  The `beq` branch at 0x26e8 targets 0x2ae0, is taken when s2(=one of 0x0, 0x1) == 0, and falls through when s2(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x26fc targets 0x27b8, is taken when s3(=one of 0x0, 0x1) == 0, and falls through when s3(=one of 0x0, 0x1) != 0.
  The `bne` branch at 0x2718 targets 0x275c, is taken when t8(=[sym(the_console_port)]:8) != s0(=a0), and falls through when t8(=[sym(the_console_port)]:8) == s0(=a0).
  The `bne` branch at 0x272c targets 0x275c, is taken when a2(=[0xa800000000001000]:8) != a3(=0x53435241), and falls through when a2(=[0xa800000000001000]:8) == a3(=0x53435241).
  The `beq` branch at 0x2738 targets 0x275c, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x2748 targets 0x275c, is taken when a3(=[[0xa800000000001020]:8]) != a4(=0xfffffffffeeddead), and falls through when a3(=[[0xa800000000001020]:8]) == a4(=0xfffffffffeeddead).
  The `bne` branch at 0x2754 targets 0x2b14, is taken when a6(=[[0xa800000000001020]:8+128]:8) != 0, and falls through when a6(=[[0xa800000000001020]:8+128]:8) == 0.
  The `bne` branch at 0x2764 targets 0x27b8, is taken when a7(=[sym(the_console_port)]:8) != s0(=a0), and falls through when a7(=[sym(the_console_port)]:8) == s0(=a0).
  The `bne` branch at 0x2778 targets 0x27b8, is taken when t0(=[0xa800000000001000]:8) != t1(=0x53435241), and falls through when t0(=[0xa800000000001000]:8) == t1(=0x53435241).
  The `beq` branch at 0x2784 targets 0x27b8, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x2794 targets 0x27b8, is taken when v1(=[[0xa800000000001020]:8]) != a0(=0xfffffffffeeddead), and falls through when v1(=[[0xa800000000001020]:8]) == a0(=0xfffffffffeeddead).
  The `beq` branch at 0x27a0 targets 0x27b8, is taken when a2(=[[0xa800000000001020]:8+128]:8) == 0, and falls through when a2(=[[0xa800000000001020]:8+128]:8) != 0.
  The `beq` branch at 0x27c8 targets 0x28c8, is taken when s4(?) == s1(=[a0+148]), and falls through when s4(?) != s1(=[a0+148]).
  The `blez` branch at 0x27d0 targets 0x2aa8, is taken when s5(=a2) <= 0 (signed), and falls through when s5(=a2) > 0 (signed).
  The `beq` branch at 0x27f8 targets 0x2ad0, is taken when (s6(=0xffffffffc0c0c0c0) & t8(?)) == 0, and falls through when (s6(=0xffffffffc0c0c0c0) & t8(?)) != 0.
  The `blez` branch at 0x2800 targets 0x2a24, is taken when s5(?) <= 0 (signed), and falls through when s5(?) > 0 (signed).
  The `beq` branch at 0x2818 targets 0x2884, is taken when (a0(?) & 0x40) == 0, and falls through when (a0(?) & 0x40) != 0.
  The `beq` branch at 0x2828 targets 0x2848, is taken when (a2(=[a0+132]) & 0x40) == 0, and falls through when (a2(=[a0+132]) & 0x40) != 0.
  The `beq` branch at 0x2838 targets 0x2848, is taken when (v0(=[a0+112]) & 0x2) == 0, and falls through when (v0(=[a0+112]) & 0x2) != 0.
  The `beq` branch at 0x2840 targets 0x2ab0, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `beq` branch at 0x2848 targets 0x287c, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `beq` branch at 0x2850 targets 0x287c, is taken when a7(?) == 0, and falls through when a7(?) != 0.
  The `beq` branch at 0x285c targets 0x2878, is taken when v0(=[a0+8]:8) == 0, and falls through when v0(=[a0+8]:8) != 0.
  The `beq` branch at 0x2888 targets 0x2a0c, is taken when (a0(?) & 0x80) == 0, and falls through when (a0(?) & 0x80) != 0.
  The `beq` branch at 0x2890 targets 0x29e4, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x28a0 targets 0x29e4, is taken when (a2(=[a0+132]) & 0x1c) == 0, and falls through when (a2(=[a0+132]) & 0x1c) != 0.
  The `blez` branch at 0x28a8 targets 0x2938, is taken when s2(?) <= 0 (signed), and falls through when s2(?) > 0 (signed).
  The `beq` branch at 0x28c0 targets 0x28cc and is always taken.
  The `beq` branch at 0x28dc targets 0x2904, is taken when (v0(=[a0+112]) & 0x1) == 0, and falls through when (v0(=[a0+112]) & 0x1) != 0.
  The `bne` branch at 0x28fc targets 0x2a70, is taken when a5(?) < a6(?) (unsigned), and falls through when a5(?) >= a6(?) (unsigned).
  The `beq` branch at 0x2938 targets 0x2968, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x2940 targets 0x296c, is taken when a7(?) == 0, and falls through when a7(?) != 0.
  The `beq` branch at 0x294c targets 0x296c, is taken when v0(=[a0+8]:8) == 0, and falls through when v0(=[a0+8]:8) != 0.
  The `beq` branch at 0x296c targets 0x29a8, is taken when t1(?) == 0, and falls through when t1(?) != 0.
  The `beq` branch at 0x297c targets 0x29a8, is taken when (t2(=[a0+132]) & 0x10) == 0, and falls through when (t2(=[a0+132]) & 0x10) != 0.
  The `beq` branch at 0x2988 targets 0x29a8, is taken when v0(=[a0+8]:8) == 0, and falls through when v0(=[a0+8]:8) != 0.
  The `beq` branch at 0x29a8 targets 0x29e4, is taken when t8(?) == 0, and falls through when t8(?) != 0.
  The `beq` branch at 0x29b8 targets 0x29e4, is taken when (t9(=[a0+132]) & 0x4) == 0, and falls through when (t9(=[a0+132]) & 0x4) != 0.
  The `beq` branch at 0x29c4 targets 0x29e4, is taken when v0(=[a0+8]:8) == 0, and falls through when v0(=[a0+8]:8) != 0.
  The `beq` branch at 0x2a14 targets 0x2a24, is taken when s8(?) >= 0x4 (signed), and falls through when s8(?) < 0x4 (signed).
  The `bgtz` branch at 0x2a1c targets 0x280c, is taken when s5(?) > 0 (signed), and falls through when s5(?) <= 0 (signed).
  The `beq` branch at 0x2a2c targets 0x2aa0, is taken when (s6(=0xffffffffc0c0c0c0) & a3(?)) == 0, and falls through when (s6(=0xffffffffc0c0c0c0) & a3(?)) != 0.
  The `beq` branch at 0x2a34 targets 0x28cc, is taken when s4(?) == s1(?), and falls through when s4(?) != s1(?).
  The `bgtz` branch at 0x2a3c targets 0x27e8, is taken when s5(?) > 0 (signed), and falls through when s5(?) <= 0 (signed).
  The `beq` branch at 0x2a44 targets 0x28d0 and is always taken.
  The `beq` branch at 0x2a58 targets 0x2694, is taken when (a4(=[[a0+64]:8]) & s2(=0x8000000)) == 0, and falls through when (a4(=[[a0+64]:8]) & s2(=0x8000000)) != 0.
  The `beq` branch at 0x2a60 targets 0x2a4c, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `beq` branch at 0x2a68 targets 0x2698 and is always taken.
  The `beq` branch at 0x2a88 targets 0x2904 and is always taken.
  The `beq` branch at 0x2a98 targets 0x2578 and is always taken.
  The `beq` branch at 0x2aa0 targets 0x2a34 and is always taken.
  The `beq` branch at 0x2aa8 targets 0x28cc and is always taken.
  The `blez` branch at 0x2ab0 targets 0x2b6c, is taken when s2(?) <= 0 (signed), and falls through when s2(?) > 0 (signed).
  The `beq` branch at 0x2ac8 targets 0x28cc and is always taken.
  The `beq` branch at 0x2ad8 targets 0x28cc and is always taken.
  The `beq` branch at 0x2ae0 targets 0x2904 and is always taken.
  The `beq` branch at 0x2b0c targets 0x25c0 and is always taken.
  The `beq` branch at 0x2b38 targets 0x275c and is always taken.
  The `beq` branch at 0x2b64 targets 0x2678 and is always taken.
  The `beq` branch at 0x2b8c targets 0x2bd0, is taken when (s6(=0xffffffffc0c0c0c0) & t0(?)) == 0, and falls through when (s6(=0xffffffffc0c0c0c0) & t0(?)) != 0.
  The `beq` branch at 0x2ba4 targets 0x2bc8, is taken when (t8(=[a0+132]) & 0x40) == 0, and falls through when (t8(=[a0+132]) & 0x40) != 0.
  The `beq` branch at 0x2bb0 targets 0x2bc8, is taken when v0(=[a0+8]:8) == 0, and falls through when v0(=[a0+8]:8) != 0.
  The `beq` branch at 0x2bc8 targets 0x2904 and is always taken.
  The `beq` branch at 0x2bd4 targets 0x2b94 and is always taken.
  The `beq` branch at 0x2be4 targets 0x2a60 and is always taken.
  The return at 0x2930 has v0 = one of ?, -0x1, 0x0.

- `ioc4_notification` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc4.o)` at 0x2bec (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc4.o)`.
  Range: 0x2bec-0x2df0 (516 bytes).
  It occupies 516 bytes.
  The `ld` at 0x2bf4 loads 8 bytes from a0 (arg0 at entry) +0x68.
  The `lw` at 0x2c18 loads 4 bytes from [a0+104]:8 +0x10.
  The `lw` at 0x2c1c loads 4 bytes from [a0+104]:8 +0xc.
  The `lw` at 0x2c30 loads 4 bytes from [a0+104]:8 +0x14.
  The `lw` at 0x2c44 loads 4 bytes from [a0+104]:8 +0x0.
  The `lw` at 0x2c5c loads 4 bytes from [a0+104]:8 +0x4.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x8c, including `lw` at 0x2c70, `lw` at 0x2d78, `lw` at 0x2de4.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x84, including `lw` at 0x2c74, `lw` at 0x2d80.
  4 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x8c, including `sw` at 0x2c7c, `sw` at 0x2c98, `sw` at 0x2d8c.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x84, including `sw` at 0x2c84, `sw` at 0x2d98.
  2 such `ld` accesses load 8 bytes from abs 0xa800000000001000, including `ld` at 0x2cb4, `ld` at 0x2d08.
  3 such `ld` accesses load 8 bytes from abs 0xa800000000001020, including `ld` at 0x2cb8, `ld` at 0x2cfc, `ld` at 0x2dd0.
  2 such `lw` accesses load 4 bytes from [0xa800000000001020]:8 +0x0, including `lw` at 0x2ccc, `lw` at 0x2d1c.
  3 such `ld` accesses load 8 bytes from [0xa800000000001020]:8 +0x80, including `ld` at 0x2cd8, `ld` at 0x2d28, `ld` at 0x2dd4.
  The `ld` at 0x2ce4 loads 8 bytes from a0 (arg0 at entry) +0x40.
  The `sw` at 0x2cec stores 4 bytes to [a0+64]:8 +0x0.
  The `lw` at 0x2d9c loads 4 bytes from a0 (arg0 at entry) +0x88.
  The `lw` at 0x2da0 loads 4 bytes from [a0+104]:8 +0x8.
  The `jal` at 0x2c68 calls enable_intrs with a0=a0 at entry (arg0), a1=?, a2=a2 at entry (arg2), a3=?.
  The `jalr` at 0x2d38 calls (unknown callee) with a0=0x1, a1=[[0xa800000000001020]:8+128]:8, a2=0x53435241, a3=[sym(the_console_port)]:8, a4=[[0xa800000000001020]:8], a5=0xfffffffffeeddead.
  The `jal` at 0x2d40 calls splx with a0=[sym(.sbss)], a1=?, a2=?, a3=?.
  The `jal` at 0x2d70 calls disable_intrs with a0=a0 at entry (arg0), a1=?, a2=a2 at entry (arg2), a3=?.
  The `jal` at 0x2dc8 calls spl7 with a0=?, a1=0x53435241, a2=[[0xa800000000001020]:8], a3=0xfffffffffeeddead, a4=[[0xa800000000001020]:8+128]:8.
  The `jalr` at 0x2ddc calls (unknown callee) with a0=0x0, a1=?, a2=?, a3=?, a5=[[0xa800000000001020]:8+128]:8.
  The `beq` branch at 0x2c10 targets 0x2c24, is taken when (a1 & 0x1) == 0, and falls through when (a1 & 0x1) != 0.
  The `beq` branch at 0x2c28 targets 0x2c3c, is taken when (s1(=a1) & 0x2) == 0, and falls through when (s1(=a1) & 0x2) != 0.
  The `beq` branch at 0x2c3c targets 0x2dc0, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `beq` branch at 0x2c54 targets 0x2d68, is taken when (s1(=a1) & 0x80) == 0, and falls through when (s1(=a1) & 0x80) != 0.
  The `beq` branch at 0x2c60 targets 0x2d70, is taken when a2 == 0, and falls through when a2 != 0.
  The `beq` branch at 0x2c8c targets 0x2d9c, is taken when (v0(?) & 0x41) == 0, and falls through when (v0(?) & 0x41) != 0.
  The `bne` branch at 0x2cb0 targets 0x2ce4, is taken when a3(=[sym(the_console_port)]:8) != s0(=a0), and falls through when a3(=[sym(the_console_port)]:8) == s0(=a0).
  The `bne` branch at 0x2cbc targets 0x2ce4, is taken when a2(=[0xa800000000001000]:8) != a1(=0x53435241), and falls through when a2(=[0xa800000000001000]:8) == a1(=0x53435241).
  The `beq` branch at 0x2cc4 targets 0x2ce4, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x2cd0 targets 0x2ce4, is taken when a2(=[[0xa800000000001020]:8]) != a3(=0xfffffffffeeddead), and falls through when a2(=[[0xa800000000001020]:8]) == a3(=0xfffffffffeeddead).
  The `bne` branch at 0x2cdc targets 0x2dc8, is taken when a4(=[[0xa800000000001020]:8+128]:8) != 0, and falls through when a4(=[[0xa800000000001020]:8+128]:8) == 0.
  The `bne` branch at 0x2d04 targets 0x2d48, is taken when a3(=[sym(the_console_port)]:8) != s0(=a0), and falls through when a3(=[sym(the_console_port)]:8) == s0(=a0).
  The `bne` branch at 0x2d0c targets 0x2d4c, is taken when a1(=[0xa800000000001000]:8) != a2(=0x53435241), and falls through when a1(=[0xa800000000001000]:8) == a2(=0x53435241).
  The `beq` branch at 0x2d14 targets 0x2d48, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x2d20 targets 0x2d4c, is taken when a4(=[[0xa800000000001020]:8]) != a5(=0xfffffffffeeddead), and falls through when a4(=[[0xa800000000001020]:8]) == a5(=0xfffffffffeeddead).
  The `beq` branch at 0x2d2c targets 0x2d4c, is taken when a1(=[[0xa800000000001020]:8+128]:8) == 0, and falls through when a1(=[[0xa800000000001020]:8+128]:8) != 0.
  The `bne` branch at 0x2d68 targets 0x2c68, is taken when a2 != 0, and falls through when a2 == 0.
  The `beq` branch at 0x2d94 targets 0x2c88 and is always taken.
  The `bne` branch at 0x2da8 targets 0x2ca0, is taken when (a2(=[[a0+104]:8+8]) & a3(=[a0+136])) != 0, and falls through when (a2(=[[a0+104]:8+8]) & a3(=[a0+136])) == 0.
  The `beq` branch at 0x2db8 targets 0x2c9c and is always taken.
  The `beq` branch at 0x2dc0 targets 0x2c50 and is always taken.
  The `beq` branch at 0x2de8 targets 0x2ce4 and is always taken.
  The return at 0x2d60 has v0 = 0x0.

- `ioc4_rx_timeout` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc4.o)` at 0x2df0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc4.o)`.
  Range: 0x2df0-0x2fa8 (440 bytes).
  It occupies 440 bytes.
  The `lw` at 0x2df0 loads 4 bytes from a0 (arg0 at entry) +0x78.
  The `sw` at 0x2e54 stores 4 bytes to a0 (arg0 at entry) +0x80.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x8c, including `lw` at 0x2e64, `lw` at 0x2f98.
  The `sw` at 0x2e78 stores 4 bytes to a0 (arg0 at entry) +0x8c.
  2 such `ld` accesses load 8 bytes from abs 0xa800000000001000, including `ld` at 0x2e84, `ld` at 0x2ee0.
  3 such `ld` accesses load 8 bytes from abs 0xa800000000001020, including `ld` at 0x2e90, `ld` at 0x2ed4, `ld` at 0x2f84.
  2 such `lw` accesses load 4 bytes from [0xa800000000001020]:8 +0x0, including `lw` at 0x2ea4, `lw` at 0x2ef4.
  3 such `ld` accesses load 8 bytes from [0xa800000000001020]:8 +0x80, including `ld` at 0x2eb0, `ld` at 0x2f00, `ld` at 0x2f88.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x40, including `ld` at 0x2ebc, `ld` at 0x2f48.
  The `sw` at 0x2ec4 stores 4 bytes to [a0+64]:8 +0x0.
  The `sw` at 0x2f64 stores 4 bytes to [a0+64]:8 +0x14.
  The `jalr` at 0x2f14 calls (unknown callee) with a0=0x1, a1=?, a2=?, a3=?, a4=[[0xa800000000001020]:8+128]:8, a5=0x53435241, a6=0xa800000000001020, a7=[sym(the_console_port)]:8.
  The `jal` at 0x2f1c calls splx with a0=[sym(.sbss)], a1=?, a2=?, a3=?.
  The `jal` at 0x2f74 calls spl7 with a0=?, a1=a1 at entry (arg1), a2=-0x200, a3=[[0xa800000000001020]:8], a4=0xfffffffffeeddead, a5=[[0xa800000000001020]:8+128]:8, a6=0x53435241, a7=0x64.
  The `jalr` at 0x2f8c calls (unknown callee) with a0=0x0, a1=?, a2=?, a3=?.
  The `beq` branch at 0x2e58 targets 0x2f68, is taken when a4(?) >= 0x200 (unsigned), and falls through when a4(?) < 0x200 (unsigned).
  The `bne` branch at 0x2e8c targets 0x2ebc, is taken when t1(=[sym(the_console_port)]:8) != s0(=a0), and falls through when t1(=[sym(the_console_port)]:8) == s0(=a0).
  The `bne` branch at 0x2e94 targets 0x2ebc, is taken when a5(=[0xa800000000001000]:8) != a6(=0x53435241), and falls through when a5(=[0xa800000000001000]:8) == a6(=0x53435241).
  The `beq` branch at 0x2e9c targets 0x2ebc, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x2ea8 targets 0x2ebc, is taken when a3(=[[0xa800000000001020]:8]) != a4(=0xfffffffffeeddead), and falls through when a3(=[[0xa800000000001020]:8]) == a4(=0xfffffffffeeddead).
  The `bne` branch at 0x2eb4 targets 0x2f74, is taken when a5(=[[0xa800000000001020]:8+128]:8) != 0, and falls through when a5(=[[0xa800000000001020]:8+128]:8) == 0.
  The `bne` branch at 0x2edc targets 0x2f28, is taken when a7(=[sym(the_console_port)]:8) != s0(=a0), and falls through when a7(=[sym(the_console_port)]:8) == s0(=a0).
  The `bne` branch at 0x2ee4 targets 0x2f28, is taken when a4(=[0xa800000000001000]:8) != a5(=0x53435241), and falls through when a4(=[0xa800000000001000]:8) == a5(=0x53435241).
  The `beq` branch at 0x2eec targets 0x2f28, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x2ef8 targets 0x2f28, is taken when t0(=[[0xa800000000001020]:8]) != t1(=0xfffffffffeeddead), and falls through when t0(=[[0xa800000000001020]:8]) == t1(=0xfffffffffeeddead).
  The `beq` branch at 0x2f04 targets 0x2f28, is taken when a4(=[[0xa800000000001020]:8+128]:8) == 0, and falls through when a4(=[[0xa800000000001020]:8+128]:8) != 0.
  The `beq` branch at 0x2fa0 targets 0x2ebc and is always taken.
  The return at 0x2f6c has v0 = one of 0x0, 0x1.

- `set_DTRRTS` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc4.o)` at 0x2fa8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc4.o)`.
  Range: 0x2fa8-0x317c (468 bytes).
  It occupies 468 bytes.
  2 such `ld` accesses load 8 bytes from abs 0xa800000000001000, including `ld` at 0x2fdc, `ld` at 0x30d0.
  3 such `ld` accesses load 8 bytes from abs 0xa800000000001020, including `ld` at 0x2fe0, `ld` at 0x30c8, `ld` at 0x3154.
  2 such `lw` accesses load 4 bytes from [0xa800000000001020]:8 +0x0, including `lw` at 0x2ff4, `lw` at 0x30e4.
  3 such `ld` accesses load 8 bytes from [0xa800000000001020]:8 +0x80, including `ld` at 0x3000, `ld` at 0x30f0, `ld` at 0x3158.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x8c, including `lw` at 0x3010, `lw` at 0x30a0.
  4 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x40, including `ld` at 0x3020, `ld` at 0x3044, `ld` at 0x3098.
  2 such `sw` accesses store 4 bytes to [a0+64]:8 +0x0, including `sw` at 0x3040, `sw` at 0x30bc.
  2 such `lw` accesses load 4 bytes from [a0+64]:8 +0x0, including `lw` at 0x3048, `lw` at 0x3068.
  The `lw` at 0x307c loads 4 bytes from [a0+64]:8 +0x18.
  The `ld` at 0x3080 loads 8 bytes from a0 (arg0 at entry) +0x48.
  The `sb` at 0x3094 stores 1 byte to [a0+72]:8 +0x4.
  The `sw` at 0x309c stores 4 bytes to [a0+64]:8 +0x18.
  The `jalr` at 0x3100 calls (unknown callee) with a0=0x1, a1=[[0xa800000000001020]:8+128]:8, a2=?, a3=[a0+72]:8, a6=[a0+140], a7=0x10000000.
  The `jal` at 0x3108 calls splx with a0=[sym(.sbss)], a1=?, a2=?, a3=?.
  The `jal` at 0x3148 calls spl7 with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a6=0x53435241, a7=[[0xa800000000001020]:8].
  The `jalr` at 0x3160 calls (unknown callee) with a0=0x0, a1=?, a2=[[0xa800000000001020]:8+128]:8, a3=?.
  The `bne` branch at 0x2fd8 targets 0x3010, is taken when t1(=[sym(the_console_port)]:8) != a0, and falls through when t1(=[sym(the_console_port)]:8) == a0.
  The `bne` branch at 0x2fe4 targets 0x3010, is taken when a7(=[0xa800000000001000]:8) != a6(=0x53435241), and falls through when a7(=[0xa800000000001000]:8) == a6(=0x53435241).
  The `beq` branch at 0x2fec targets 0x3010, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x2ff8 targets 0x3010, is taken when a7(=[[0xa800000000001020]:8]) != t0(=0xfffffffffeeddead), and falls through when a7(=[[0xa800000000001020]:8]) == t0(=0xfffffffffeeddead).
  The `bne` branch at 0x3008 targets 0x3148, is taken when t1(=[[0xa800000000001020]:8+128]:8) != 0, and falls through when t1(=[[0xa800000000001020]:8+128]:8) == 0.
  The `bgez` branch at 0x302c targets 0x307c, is taken when t2(=([a0+140] << 0x23)) >= 0 (signed), and falls through when t2(=([a0+140] << 0x23)) < 0 (signed).
  The `bltz` branch at 0x3050 targets 0x307c, is taken when a4(=([[a0+64]:8] << 0x21)) < 0 (signed), and falls through when a4(=([[a0+64]:8] << 0x21)) >= 0 (signed).
  The `bne` branch at 0x3060 targets 0x3140, is taken when t1(?) != 0, and falls through when t1(?) == 0.
  The `beq` branch at 0x3074 targets 0x3060, is taken when (t2(=[[a0+64]:8]) & a3(=0x40000000)) == 0, and falls through when (t2(=[[a0+64]:8]) & a3(=0x40000000)) != 0.
  The `beq` branch at 0x3084 targets 0x312c, is taken when a1 == 0, and falls through when a1 != 0.
  The `beq` branch at 0x30b0 targets 0x30c0, is taken when (a7(=0x10000000) & a6(=[a0+140])) == 0, and falls through when (a7(=0x10000000) & a6(=[a0+140])) != 0.
  The `bne` branch at 0x30c4 targets 0x3114, is taken when at(=[sym(the_console_port)]:8) != s0(=a0), and falls through when at(=[sym(the_console_port)]:8) == s0(=a0).
  The `bne` branch at 0x30d4 targets 0x3114, is taken when v1(=[0xa800000000001000]:8) != a0(=0x53435241), and falls through when v1(=[0xa800000000001000]:8) == a0(=0x53435241).
  The `beq` branch at 0x30dc targets 0x3114, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x30e8 targets 0x3114, is taken when a0(=[[0xa800000000001020]:8]) != a1(=0xfffffffffeeddead), and falls through when a0(=[[0xa800000000001020]:8]) == a1(=0xfffffffffeeddead).
  The `beq` branch at 0x30f4 targets 0x3114, is taken when a1(=[[0xa800000000001020]:8+128]:8) == 0, and falls through when a1(=[[0xa800000000001020]:8+128]:8) != 0.
  The `beq` branch at 0x3138 targets 0x3094 and is always taken.
  The `beq` branch at 0x3140 targets 0x311c and is always taken.
  The `beq` branch at 0x3174 targets 0x3010 and is always taken.
  The return at 0x3124 has v0 = one of -0x1, 0x0.

- `ioc4_set_DTR` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc4.o)` at 0x317c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc4.o)`.
  Range: 0x317c-0x319c (32 bytes).
  It occupies 32 bytes.
  The `jal` at 0x3188 calls set_DTRRTS with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0x1, a3=0x1000000.
  The return at 0x3194 has v0 = ret(set_DTRRTS).

- `ioc4_set_RTS` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc4.o)` at 0x319c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc4.o)`.
  Range: 0x319c-0x31bc (32 bytes).
  It occupies 32 bytes.
  The `jal` at 0x31a8 calls set_DTRRTS with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0x2, a3=0x2000000.
  The return at 0x31b4 has v0 = ret(set_DTRRTS).

- `ioc4_query_DCD` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc4.o)` at 0x31bc (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc4.o)`.
  Range: 0x31bc-0x32c0 (260 bytes).
  It occupies 260 bytes.
  2 such `ld` accesses load 8 bytes from abs 0xa800000000001000, including `ld` at 0x31d8, `ld` at 0x3228.
  3 such `ld` accesses load 8 bytes from abs 0xa800000000001020, including `ld` at 0x31dc, `ld` at 0x3230, `ld` at 0x3294.
  2 such `lw` accesses load 4 bytes from [0xa800000000001020]:8 +0x0, including `lw` at 0x31f0, `lw` at 0x323c.
  3 such `ld` accesses load 8 bytes from [0xa800000000001020]:8 +0x80, including `ld` at 0x31fc, `ld` at 0x3248, `ld` at 0x3298.
  The `ld` at 0x320c loads 8 bytes from a0 (arg0 at entry) +0x40.
  The `lw` at 0x3220 loads 4 bytes from [a0+64]:8 +0x18.
  The `jalr` at 0x3260 calls (unknown callee) with a0=0x1, a1=?, a2=?, a3=[[0xa800000000001020]:8+128]:8, a4=[[a0+64]:8+24], a5=0xa800000000001020, a6=[0xa800000000001000]:8, a7=[[0xa800000000001020]:8].
  The `jal` at 0x3268 calls splx with a0=[sym(.sbss)], a1=?, a2=?, a3=?.
  The `jal` at 0x3288 calls spl7 with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=[sym(the_console_port)]:8, a4=0x53435241, a5=[[0xa800000000001020]:8], a6=0xfffffffffeeddead, a7=[[0xa800000000001020]:8+128]:8.
  The `jalr` at 0x32a0 calls (unknown callee) with a0=0x0, a1=?, a2=?, a3=?.
  The `bne` branch at 0x31d4 targets 0x320c, is taken when a0 != a3(=[sym(the_console_port)]:8), and falls through when a0 == a3(=[sym(the_console_port)]:8).
  The `bne` branch at 0x31e0 targets 0x320c, is taken when a5(=[0xa800000000001000]:8) != a4(=0x53435241), and falls through when a5(=[0xa800000000001000]:8) == a4(=0x53435241).
  The `beq` branch at 0x31e8 targets 0x320c, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x31f4 targets 0x320c, is taken when a5(=[[0xa800000000001020]:8]) != a6(=0xfffffffffeeddead), and falls through when a5(=[[0xa800000000001020]:8]) == a6(=0xfffffffffeeddead).
  The `bne` branch at 0x3204 targets 0x3288, is taken when a7(=[[0xa800000000001020]:8+128]:8) != 0, and falls through when a7(=[[0xa800000000001020]:8+128]:8) == 0.
  The `bne` branch at 0x321c targets 0x3278, is taken when a0 != a3(=[sym(the_console_port)]:8), and falls through when a0 == a3(=[sym(the_console_port)]:8).
  The `bne` branch at 0x322c targets 0x3278, is taken when a6(=[0xa800000000001000]:8) != a7(=0x53435241), and falls through when a6(=[0xa800000000001000]:8) == a7(=0x53435241).
  The `beq` branch at 0x3234 targets 0x3278, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x3240 targets 0x3278, is taken when a7(=[[0xa800000000001020]:8]) != t0(=0xfffffffffeeddead), and falls through when a7(=[[0xa800000000001020]:8]) == t0(=0xfffffffffeeddead).
  The `beq` branch at 0x3250 targets 0x3278, is taken when a3(=[[0xa800000000001020]:8+128]:8) == 0, and falls through when a3(=[[0xa800000000001020]:8+128]:8) != 0.
  The `beq` branch at 0x32b8 targets 0x320c and is always taken.
  The return at 0x3280 has v0 = ?.

- `ioc4_query_CTS` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc4.o)` at 0x32c0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc4.o)`.
  Range: 0x32c0-0x33c4 (260 bytes).
  It occupies 260 bytes.
  2 such `ld` accesses load 8 bytes from abs 0xa800000000001000, including `ld` at 0x32dc, `ld` at 0x332c.
  3 such `ld` accesses load 8 bytes from abs 0xa800000000001020, including `ld` at 0x32e0, `ld` at 0x3334, `ld` at 0x3398.
  2 such `lw` accesses load 4 bytes from [0xa800000000001020]:8 +0x0, including `lw` at 0x32f4, `lw` at 0x3340.
  3 such `ld` accesses load 8 bytes from [0xa800000000001020]:8 +0x80, including `ld` at 0x3300, `ld` at 0x334c, `ld` at 0x339c.
  The `ld` at 0x3310 loads 8 bytes from a0 (arg0 at entry) +0x40.
  The `lw` at 0x3324 loads 4 bytes from [a0+64]:8 +0x18.
  The `jalr` at 0x3364 calls (unknown callee) with a0=0x1, a1=?, a2=?, a3=[[0xa800000000001020]:8+128]:8, a4=[[a0+64]:8+24], a5=0xa800000000001020, a6=[0xa800000000001000]:8, a7=[[0xa800000000001020]:8].
  The `jal` at 0x336c calls splx with a0=[sym(.sbss)], a1=?, a2=?, a3=?.
  The `jal` at 0x338c calls spl7 with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=[sym(the_console_port)]:8, a4=0x53435241, a5=[[0xa800000000001020]:8], a6=0xfffffffffeeddead, a7=[[0xa800000000001020]:8+128]:8.
  The `jalr` at 0x33a4 calls (unknown callee) with a0=0x0, a1=?, a2=?, a3=?.
  The `bne` branch at 0x32d8 targets 0x3310, is taken when a0 != a3(=[sym(the_console_port)]:8), and falls through when a0 == a3(=[sym(the_console_port)]:8).
  The `bne` branch at 0x32e4 targets 0x3310, is taken when a5(=[0xa800000000001000]:8) != a4(=0x53435241), and falls through when a5(=[0xa800000000001000]:8) == a4(=0x53435241).
  The `beq` branch at 0x32ec targets 0x3310, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x32f8 targets 0x3310, is taken when a5(=[[0xa800000000001020]:8]) != a6(=0xfffffffffeeddead), and falls through when a5(=[[0xa800000000001020]:8]) == a6(=0xfffffffffeeddead).
  The `bne` branch at 0x3308 targets 0x338c, is taken when a7(=[[0xa800000000001020]:8+128]:8) != 0, and falls through when a7(=[[0xa800000000001020]:8+128]:8) == 0.
  The `bne` branch at 0x3320 targets 0x337c, is taken when a0 != a3(=[sym(the_console_port)]:8), and falls through when a0 == a3(=[sym(the_console_port)]:8).
  The `bne` branch at 0x3330 targets 0x337c, is taken when a6(=[0xa800000000001000]:8) != a7(=0x53435241), and falls through when a6(=[0xa800000000001000]:8) == a7(=0x53435241).
  The `beq` branch at 0x3338 targets 0x337c, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x3344 targets 0x337c, is taken when a7(=[[0xa800000000001020]:8]) != t0(=0xfffffffffeeddead), and falls through when a7(=[[0xa800000000001020]:8]) == t0(=0xfffffffffeeddead).
  The `beq` branch at 0x3354 targets 0x337c, is taken when a3(=[[0xa800000000001020]:8+128]:8) == 0, and falls through when a3(=[[0xa800000000001020]:8+128]:8) != 0.
  The `beq` branch at 0x33bc targets 0x3310 and is always taken.
  The return at 0x3384 has v0 = ?.

- `ioc4_set_proto` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc4.o)` at 0x33c4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc4.o)`.
  Range: 0x33c4-0x3418 (84 bytes).
  It occupies 84 bytes.
  The `ld` at 0x33c4 loads 8 bytes from a0 (arg0 at entry) +0x68.
  2 such `lbu` accesses load 1 byte from [a0+104]:8 +0x24, including `lbu` at 0x33e0, `lbu` at 0x3400.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x38, including `ld` at 0x33e4, `ld` at 0x3404.
  2 such `sw` accesses store 4 bytes to ([a0+56]:8 + ([[a0+104]:8+36]:1 << 0x2)) +0x40, including `sw` at 0x33f0, `sw` at 0x3414.
  The `beq` branch at 0x33c8 targets 0x33e0, is taken when a1 == 0, and falls through when a1 != 0.
  The `bne` branch at 0x33d0 targets 0x33f8, is taken when a1 != v0(=0x1), and falls through when a1 == v0(=0x1).
  The `beq` branch at 0x33d8 targets 0x3400 and is always taken.
  The `beq` branch at 0x3410 targets 0x33f4 and is always taken.
  The return at 0x33f8 has v0 = one of 0x0, 0x1.

- `ioc4_get_mapid` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc4.o)` at 0x3418 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc4.o)`.
  Range: 0x3418-0x34c8 (176 bytes).
  It occupies 176 bytes.
  4 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x68, including `ld` at 0x3430, `ld` at 0x3448, `ld` at 0x3464.
  The `jal` at 0x34a8 calls copyout with a0=sp-16, a1=a1 at entry (arg1), a2=0x8, a3=?, a4=sym(.data), a7=sym(.data).
  The `beq` branch at 0x3424 targets 0x34bc, is taken when a1 == 0, and falls through when a1 != 0.
  The return at 0x34c0 has v0 = one of 0x0, 0x1, 0xe.

- `ioc4_map` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc4.o)` at 0x34c8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc4.o)`.
  Range: 0x34c8-0x3598 (208 bytes).
  It occupies 208 bytes.
  The `ld` at 0x34f4 loads 8 bytes from a0 (arg0 at entry) +0x50.
  The `ld` at 0x3538 loads 8 bytes from a0 (arg0 at entry) +0x68.
  The `ld` at 0x3578 loads 8 bytes from a0 (arg0 at entry) +0x38.
  The `jal` at 0x34fc calls disable_intrs with a0=a0 at entry (arg0), a1=-0x1, a2=?, a3=?.
  The `jal` at 0x350c calls v_mapphys with a0=a1 at entry (arg1), a1=?, a2=0x4000, a3=?.
  The `beq` branch at 0x34d0 targets 0x34ec, is taken when a2 == 0, and falls through when a2 != 0.
  The `beq` branch at 0x34dc targets 0x3528, is taken when a2 == at(=0x4000), and falls through when a2 != at(=0x4000).
  The `beq` branch at 0x34e4 targets 0x3520 and is always taken.
  The `beq` branch at 0x3590 targets 0x34fc and is always taken.
  The return at 0x3520 has v0 = one of 0x16, ret(v_mapphys).

- `ioc4_unmap` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc4.o)` at 0x3598 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc4.o)`.
  Range: 0x3598-0x36d4 (316 bytes).
  It occupies 316 bytes.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x8c, including `lw` at 0x35a0, `lw` at 0x36c4.
  The `sw` at 0x35b4 stores 4 bytes to a0 (arg0 at entry) +0x8c.
  2 such `ld` accesses load 8 bytes from abs 0xa800000000001000, including `ld` at 0x35c4, `ld` at 0x3624.
  3 such `ld` accesses load 8 bytes from abs 0xa800000000001020, including `ld` at 0x35cc, `ld` at 0x3618, `ld` at 0x36ac.
  2 such `lw` accesses load 4 bytes from [0xa800000000001020]:8 +0x0, including `lw` at 0x35e8, `lw` at 0x3638.
  3 such `ld` accesses load 8 bytes from [0xa800000000001020]:8 +0x80, including `ld` at 0x35f4, `ld` at 0x3644, `ld` at 0x36b0.
  3 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x40, including `ld` at 0x3600, `ld` at 0x366c, `ld` at 0x3680.
  The `sw` at 0x3608 stores 4 bytes to [a0+64]:8 +0x0.
  The `lw` at 0x3670 loads 4 bytes from [a0+64]:8 +0x8.
  The `sw` at 0x3678 stores 4 bytes to a0 (arg0 at entry) +0x90.
  The `sw` at 0x367c stores 4 bytes to [a0+64]:8 +0x4.
  The `lw` at 0x3684 loads 4 bytes from [a0+64]:8 +0xc.
  The `sw` at 0x368c stores 4 bytes to a0 (arg0 at entry) +0x94.
  The `sw` at 0x3690 stores 4 bytes to [a0+64]:8 +0x10.
  The `jalr` at 0x3658 calls (unknown callee) with a0=0x1, a1=[a0+64]:8, a2=[[0xa800000000001020]:8], a3=[[0xa800000000001020]:8+128]:8, a4=[sym(.sbss)], a5=0xa800000000001020, a6=[sym(the_console_port)]:8.
  The `jal` at 0x3660 calls splx with a0=[sym(.sbss)], a1=?, a2=?, a3=?.
  The `jal` at 0x36a0 calls spl7 with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=?, a4=[0xa800000000001000]:8, a5=0x53435241, a6=[[0xa800000000001020]:8], a7=0xfffffffffeeddead.
  The `jalr` at 0x36b8 calls (unknown callee) with a0=0x0, a1=?, a2=?, a3=?, a7=[[0xa800000000001020]:8+128]:8.
  The `bne` branch at 0x35d0 targets 0x3600, is taken when at(=[sym(the_console_port)]:8) != a0, and falls through when at(=[sym(the_console_port)]:8) == a0.
  The `bne` branch at 0x35d8 targets 0x3600, is taken when a4(=[0xa800000000001000]:8) != a5(=0x53435241), and falls through when a4(=[0xa800000000001000]:8) == a5(=0x53435241).
  The `beq` branch at 0x35e0 targets 0x3600, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x35ec targets 0x3600, is taken when a6(=[[0xa800000000001020]:8]) != a7(=0xfffffffffeeddead), and falls through when a6(=[[0xa800000000001020]:8]) == a7(=0xfffffffffeeddead).
  The `bne` branch at 0x35f8 targets 0x36a0, is taken when t0(=[[0xa800000000001020]:8+128]:8) != 0, and falls through when t0(=[[0xa800000000001020]:8+128]:8) == 0.
  The `bne` branch at 0x3620 targets 0x366c, is taken when a6(=[sym(the_console_port)]:8) != s0(=a0), and falls through when a6(=[sym(the_console_port)]:8) == s0(=a0).
  The `bne` branch at 0x3628 targets 0x366c, is taken when a4(=[0xa800000000001000]:8) != a0(=0x53435241), and falls through when a4(=[0xa800000000001000]:8) == a0(=0x53435241).
  The `beq` branch at 0x3630 targets 0x366c, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x363c targets 0x366c, is taken when a2(=[[0xa800000000001020]:8]) != a3(=0xfffffffffeeddead), and falls through when a2(=[[0xa800000000001020]:8]) == a3(=0xfffffffffeeddead).
  The `beq` branch at 0x3648 targets 0x366c, is taken when a3(=[[0xa800000000001020]:8+128]:8) == 0, and falls through when a3(=[[0xa800000000001020]:8+128]:8) != 0.
  The `beq` branch at 0x36cc targets 0x3600 and is always taken.
  The return at 0x3698 has v0 = one of [0xa800000000001020]:8, ret(splx).

- `ioc4_set_sscr` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc4.o)` at 0x36d4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc4.o)`.
  Range: 0x36d4-0x37f8 (292 bytes).
  It occupies 292 bytes.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x8c, including `lw` at 0x36d4, `lw` at 0x37a8, `lw` at 0x37e8.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x8c, including `sw` at 0x36f0, `sw` at 0x37c0.
  2 such `ld` accesses load 8 bytes from abs 0xa800000000001000, including `ld` at 0x370c, `ld` at 0x3760.
  3 such `ld` accesses load 8 bytes from abs 0xa800000000001020, including `ld` at 0x3710, `ld` at 0x3754, `ld` at 0x37d0.
  2 such `lw` accesses load 4 bytes from [0xa800000000001020]:8 +0x0, including `lw` at 0x3724, `lw` at 0x3774.
  3 such `ld` accesses load 8 bytes from [0xa800000000001020]:8 +0x80, including `ld` at 0x3730, `ld` at 0x3780, `ld` at 0x37d4.
  The `ld` at 0x373c loads 8 bytes from a0 (arg0 at entry) +0x40.
  The `sw` at 0x3744 stores 4 bytes to [a0+64]:8 +0x0.
  The `jalr` at 0x3794 calls (unknown callee) with a0=0x1, a1=[[0xa800000000001020]:8+128]:8, a2=[sym(the_console_port)]:8, a3=[[0xa800000000001020]:8], a4=0xfffffffffeeddead, a5=[sym(.sbss)].
  The `jal` at 0x379c calls splx with a0=[sym(.sbss)], a1=?, a2=?, a3=?.
  The `jal` at 0x37c4 calls spl7 with a0=0x53435241, a1=[[0xa800000000001020]:8], a2=0xfffffffffeeddead, a3=[[0xa800000000001020]:8+128]:8, a4=0xa800000000001020.
  The `jalr` at 0x37dc calls (unknown callee) with a0=0x0, a1=?, a2=?, a3=?, a6=[[0xa800000000001020]:8+128]:8.
  The `beq` branch at 0x36e4 targets 0x37b8, is taken when a2 == 0, and falls through when a2 != 0.
  The `bne` branch at 0x3708 targets 0x373c, is taken when a2(=[sym(the_console_port)]:8) != s0(=a0), and falls through when a2(=[sym(the_console_port)]:8) == s0(=a0).
  The `bne` branch at 0x3714 targets 0x373c, is taken when a1(=[0xa800000000001000]:8) != a0(=0x53435241), and falls through when a1(=[0xa800000000001000]:8) == a0(=0x53435241).
  The `beq` branch at 0x371c targets 0x373c, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x3728 targets 0x373c, is taken when a1(=[[0xa800000000001020]:8]) != a2(=0xfffffffffeeddead), and falls through when a1(=[[0xa800000000001020]:8]) == a2(=0xfffffffffeeddead).
  The `bne` branch at 0x3734 targets 0x37c4, is taken when a3(=[[0xa800000000001020]:8+128]:8) != 0, and falls through when a3(=[[0xa800000000001020]:8+128]:8) == 0.
  The `bne` branch at 0x375c targets 0x37a8, is taken when a2(=[sym(the_console_port)]:8) != s0(=a0), and falls through when a2(=[sym(the_console_port)]:8) == s0(=a0).
  The `bne` branch at 0x3764 targets 0x37a8, is taken when a0(=[0xa800000000001000]:8) != a1(=0x53435241), and falls through when a0(=[0xa800000000001000]:8) == a1(=0x53435241).
  The `beq` branch at 0x376c targets 0x37a8, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x3778 targets 0x37a8, is taken when a3(=[[0xa800000000001020]:8]) != a4(=0xfffffffffeeddead), and falls through when a3(=[[0xa800000000001020]:8]) == a4(=0xfffffffffeeddead).
  The `beq` branch at 0x3784 targets 0x37a8, is taken when a1(=[[0xa800000000001020]:8+128]:8) == 0, and falls through when a1(=[[0xa800000000001020]:8+128]:8) != 0.
  The `beq` branch at 0x37bc targets 0x36f4 and is always taken.
  The `beq` branch at 0x37f0 targets 0x373c and is always taken.
  The return at 0x37b0 has v0 = [a0+140].

- `ioc4_console_write` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc4.o)` at 0x37f8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc4.o)`.
  Range: 0x37f8-0x394c (340 bytes).
  It occupies 340 bytes.
  7 such `lw` accesses load 4 bytes from [sym(ioc4_console_mem)]:8 +0x310, including `lw` at 0x3810, `lw` at 0x38d8, `lw` at 0x38e8.
  The `sd` at 0x382c stores 8 bytes to a2 (arg2 at entry) +0x0.
  The `sb` at 0x3848 stores 1 byte to [sym(ioc4_console_mem)]:8 +0x380.
  6 such `lbu` accesses load 1 byte from [sym(ioc4_console_mem)]:8 +0x385, including `lbu` at 0x384c, `lbu` at 0x3864, `lbu` at 0x3874.
  The `lbu` at 0x3858 loads 1 byte from ?.
  The `sw` at 0x38d4 stores 4 bytes to [sym(ioc4_console_mem)]:8 +0x310.
  The `beq` branch at 0x3804 targets 0x38c0, is taken when a5(=[sym(ioc4_console_mem)]:8) == 0, and falls through when a5(=[sym(ioc4_console_mem)]:8) != 0.
  The `bne` branch at 0x3818 targets 0x382c, is taken when t1(=0x10000000) != at(?), and falls through when t1(=0x10000000) == at(?).
  The `beq` branch at 0x3824 targets 0x3940 and is always taken.
  The `bne` branch at 0x3834 targets 0x384c, is taken when a1 != 0, and falls through when a1 == 0.
  The `beq` branch at 0x383c targets 0x38bc and is always taken.
  The `beq` branch at 0x3844 targets 0x38bc, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `bne` branch at 0x385c targets 0x3844, is taken when (v1(=[[sym(ioc4_console_mem)]:8+901]:1) & 0x20) != 0, and falls through when (v1(=[[sym(ioc4_console_mem)]:8+901]:1) & 0x20) == 0.
  The `bne` branch at 0x386c targets 0x3844, is taken when (a3(=[[sym(ioc4_console_mem)]:8+901]:1) & 0x20) != 0, and falls through when (a3(=[[sym(ioc4_console_mem)]:8+901]:1) & 0x20) == 0.
  The `bne` branch at 0x387c targets 0x3844, is taken when (a4(=[[sym(ioc4_console_mem)]:8+901]:1) & 0x20) != 0, and falls through when (a4(=[[sym(ioc4_console_mem)]:8+901]:1) & 0x20) == 0.
  The `bne` branch at 0x388c targets 0x3844, is taken when (a5(=[[sym(ioc4_console_mem)]:8+901]:1) & 0x20) != 0, and falls through when (a5(=[[sym(ioc4_console_mem)]:8+901]:1) & 0x20) == 0.
  The `bne` branch at 0x389c targets 0x3844, is taken when (a6(=[[sym(ioc4_console_mem)]:8+901]:1) & 0x20) != 0, and falls through when (a6(=[[sym(ioc4_console_mem)]:8+901]:1) & 0x20) == 0.
  The `beq` branch at 0x38ac targets 0x3864, is taken when (a7(=[[sym(ioc4_console_mem)]:8+901]:1) & 0x20) == 0, and falls through when (a7(=[[sym(ioc4_console_mem)]:8+901]:1) & 0x20) != 0.
  The `beq` branch at 0x38b4 targets 0x3844 and is always taken.
  The `bne` branch at 0x38cc targets 0x382c, is taken when t1(=0x10000000) != t3(?), and falls through when t1(=0x10000000) == t3(?).
  The `bne` branch at 0x38e0 targets 0x38cc, is taken when a6(=0x30000000) != t8(?), and falls through when a6(=0x30000000) == t8(?).
  The `bne` branch at 0x38f0 targets 0x38c8, is taken when a6(=0x30000000) != at(?), and falls through when a6(=0x30000000) == at(?).
  The `bne` branch at 0x3900 targets 0x38c8, is taken when a6(=0x30000000) != v1(?), and falls through when a6(=0x30000000) == v1(?).
  The `bne` branch at 0x3910 targets 0x38c8, is taken when a6(=0x30000000) != a3(?), and falls through when a6(=0x30000000) == a3(?).
  The `bne` branch at 0x3920 targets 0x38c8, is taken when a6(=0x30000000) != a4(?), and falls through when a6(=0x30000000) == a4(?).
  The `beq` branch at 0x3930 targets 0x38e8, is taken when a6(=0x30000000) == t3(?), and falls through when a6(=0x30000000) != t3(?).
  The `beq` branch at 0x3938 targets 0x38c8 and is always taken.
  The `beq` branch at 0x3944 targets 0x38d4 and is always taken.
  The return at 0x38c0 has v0 = one of -0x1, 0x0.

- `console_debug_poll` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc4.o)` at 0x394c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc4.o)`.
  Range: 0x394c-0x3a20 (212 bytes).
  It occupies 212 bytes.
  7 such `lw` accesses load 4 bytes from [sym(ioc4_console_mem)]:8 +0x310, including `lw` at 0x3950, `lw` at 0x39a4, `lw` at 0x39b4.
  The `lbu` at 0x3978 loads 1 byte from [sym(ioc4_console_mem)]:8 +0x385.
  The `lbu` at 0x3988 loads 1 byte from [sym(ioc4_console_mem)]:8 +0x380.
  The `sw` at 0x39a0 stores 4 bytes to [sym(ioc4_console_mem)]:8 +0x310.
  The `jal` at 0x3a10 calls debug with a0=sym(.rodata), a1=0x40000000, a2=[sym(ioc4_console_mem)]:8+896, a3=[sym(ioc4_console_mem)]:8+784, a4=([[sym(ioc4_console_mem)]:8+784] << 0x21), a5=[[sym(ioc4_console_mem)]:8+784], a6=[sym(ioc4_console_mem)]:8.
  The `bgez` branch at 0x3968 targets 0x3978, is taken when at(=([[sym(ioc4_console_mem)]:8+784] << 0x23)) >= 0 (signed), and falls through when at(=([[sym(ioc4_console_mem)]:8+784] << 0x23)) < 0 (signed).
  The `bgez` branch at 0x3970 targets 0x399c, is taken when a4(=([[sym(ioc4_console_mem)]:8+784] << 0x21)) >= 0 (signed), and falls through when a4(=([[sym(ioc4_console_mem)]:8+784] << 0x21)) < 0 (signed).
  The `beq` branch at 0x3980 targets 0x3994, is taken when (v0(=[[sym(ioc4_console_mem)]:8+901]:1) & 0x1) == 0, and falls through when (v0(=[[sym(ioc4_console_mem)]:8+901]:1) & 0x1) != 0.
  The `beq` branch at 0x398c targets 0x3a0c, is taken when v1(=[[sym(ioc4_console_mem)]:8+896]:1) == a0(=0x1), and falls through when v1(=[[sym(ioc4_console_mem)]:8+896]:1) != a0(=0x1).
  The `bltz` branch at 0x39ac targets 0x3978, is taken when a4(=([[sym(ioc4_console_mem)]:8+784] << 0x21)) < 0 (signed), and falls through when a4(=([[sym(ioc4_console_mem)]:8+784] << 0x21)) >= 0 (signed).
  The `bne` branch at 0x39bc targets 0x3978, is taken when (t0(=[[sym(ioc4_console_mem)]:8+784]) & a1(=0x40000000)) != 0, and falls through when (t0(=[[sym(ioc4_console_mem)]:8+784]) & a1(=0x40000000)) == 0.
  The `bne` branch at 0x39cc targets 0x3978, is taken when (t1(=[[sym(ioc4_console_mem)]:8+784]) & a1(=0x40000000)) != 0, and falls through when (t1(=[[sym(ioc4_console_mem)]:8+784]) & a1(=0x40000000)) == 0.
  The `bne` branch at 0x39dc targets 0x3978, is taken when (t2(=[[sym(ioc4_console_mem)]:8+784]) & a1(=0x40000000)) != 0, and falls through when (t2(=[[sym(ioc4_console_mem)]:8+784]) & a1(=0x40000000)) == 0.
  The `bne` branch at 0x39ec targets 0x3978, is taken when (t3(=[[sym(ioc4_console_mem)]:8+784]) & a1(=0x40000000)) != 0, and falls through when (t3(=[[sym(ioc4_console_mem)]:8+784]) & a1(=0x40000000)) == 0.
  The `beq` branch at 0x39fc targets 0x39b4, is taken when (t8(=[[sym(ioc4_console_mem)]:8+784]) & a1(=0x40000000)) == 0, and falls through when (t8(=[[sym(ioc4_console_mem)]:8+784]) & a1(=0x40000000)) != 0.
  The `beq` branch at 0x3a04 targets 0x3978 and is always taken.
  The `beq` branch at 0x3a18 targets 0x3994 and is always taken.
  The return at 0x3994 has v0 = one of ?, ret(debug).
