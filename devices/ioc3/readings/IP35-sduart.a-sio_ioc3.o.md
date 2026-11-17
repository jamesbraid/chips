# Readings: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc3.o)`

One entry per routine, filed here from the reading batches by binary.

- `ioc3_sio_mlreset` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc3.o)` at 0x0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc3.o)`.
  Range: 0x0-0x2c (44 bytes).
  It occupies 44 bytes.
  The `jal` at 0x18 calls sio_console_register with a0=sp-32, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x24 has v0 = ret(sio_console_register).

- `ring_dmatrans` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc3.o)` at 0x2c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc3.o)`.
  Range: 0x2c-0x78 (76 bytes).
  It occupies 76 bytes.
  The `jal` at 0x54 calls pciio_dmatrans_addr with a0=a0 at entry (arg0), a1=0x0, a2=?, a3=0x4000, a4=0x40.
  The `beq` branch at 0x40 targets 0x68, is taken when a0 == at(=-0x1), and falls through when a0 != at(=-0x1).
  The `beq` branch at 0x60 targets 0x6c and is always taken.
  The return at 0x70 has v0 = one of ret(pciio_dmatrans_addr), ?.

- `mask_disable_intrs` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc3.o)` at 0x78 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc3.o)`.
  Range: 0x78-0x8c (20 bytes).
  It occupies 20 bytes.
  The `lw` at 0x78 loads 4 bytes from a0 (arg0 at entry) +0x90.
  The `sw` at 0x88 stores 4 bytes to a0 (arg0 at entry) +0x90.
  The return at 0x84 has v0 = ?.

- `enable_intrs` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc3.o)` at 0x8c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc3.o)`.
  Range: 0x8c-0xdc (80 bytes).
  It occupies 80 bytes.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x90, including `lw` at 0x8c, `lw` at 0xc8.
  The `ld` at 0xb0 loads 8 bytes from a0 (arg0 at entry) +0xa0.
  The `sw` at 0xd8 stores 4 bytes to a0 (arg0 at entry) +0x90.
  The `jal` at 0xb8 calls ioc3_write_ireg with a0=[a0+160]:8, a1=a1 at entry (arg1), a2=0x0, a3=a3 at entry (arg3).
  The `bne` branch at 0xa0 targets 0xb0, is taken when a1 != at(?), and falls through when a1 == at(?).
  The `beq` branch at 0xd4 targets 0xa8 and is always taken.
  The return at 0xa8 has v0 = one of ?, ret(ioc3_write_ireg).

- `disable_intrs` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc3.o)` at 0xdc (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc3.o)`.
  Range: 0xdc-0x130 (84 bytes).
  It occupies 84 bytes.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x90, including `lw` at 0xdc, `lw` at 0x10c.
  The `ld` at 0x108 loads 8 bytes from a0 (arg0 at entry) +0xa0.
  The `sw` at 0x11c stores 4 bytes to a0 (arg0 at entry) +0x90.
  The `jal` at 0x104 calls ioc3_write_ireg with a0=[a0+160]:8, a1=a1 at entry (arg1), a2=0x1, a3=a3 at entry (arg3).
  The `beq` branch at 0xf8 targets 0x120, is taken when (at(=[a0+144]) & a1) == 0, and falls through when (at(=[a0+144]) & a1) != 0.
  The return at 0x128 has v0 = ?.

- `ioc3_serial_intr` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc3.o)` at 0x130 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc3.o)`.
  Range: 0x130-0x6cc (1436 bytes).
  It occupies 1436 bytes.
  The `ld` at 0x144 loads 8 bytes from a0 (arg0 at entry) +0x70.
  4 such `lw` accesses load 4 bytes from [a0+112]:8 +0x8, including `lw` at 0x14c, `lw` at 0x41c, `lw` at 0x454.
  3 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x40, including `ld` at 0x198, `ld` at 0x2dc, `ld` at 0x600.
  6 such `ld` accesses load 8 bytes from abs 0xa800000000001000, including `ld` at 0x19c, `ld` at 0x2c8, `ld` at 0x2e0.
  2 such `lw` accesses load 4 bytes from [a0+64]:8 +0x18, including `lw` at 0x1a4, `lw` at 0x2e8.
  9 such `ld` accesses load 8 bytes from abs 0xa800000000001020, including `ld` at 0x1a8, `ld` at 0x2d0, `ld` at 0x2ec.
  9 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x8c, including `lw` at 0x1b4, `lw` at 0x1fc, `lw` at 0x24c.
  6 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x8, including `ld` at 0x1c8, `ld` at 0x20c, `ld` at 0x25c.
  2 such `ld` accesses load 8 bytes from [a0+8]:8 +0x20, including `ld` at 0x1d4, `ld` at 0x4e4.
  2 such `lw` accesses load 4 bytes from [a0+112]:8 +0xc, including `lw` at 0x1e4, `lw` at 0x4f8.
  7 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x38, including `ld` at 0x1f4, `ld` at 0x238, `ld` at 0x278.
  4 such `sw` accesses store 4 bytes to [a0+56]:8 +0x1c, including `sw` at 0x1f8, `sw` at 0x248, `sw` at 0x2c0.
  2 such `ld` accesses load 8 bytes from [a0+8]:8 +0x0, including `ld` at 0x218, `ld` at 0x3d4.
  2 such `lw` accesses load 4 bytes from [a0+112]:8 +0x14, including `lw` at 0x224, `lw` at 0x244.
  4 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x78, including `lw` at 0x234, `lw` at 0x404, `lw` at 0x4fc.
  3 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x78, including `sw` at 0x240, `sw` at 0x508, `sw` at 0x638.
  2 such `ld` accesses load 8 bytes from [a0+8]:8 +0x8, including `ld` at 0x268, `ld` at 0x448.
  5 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x90, including `lw` at 0x274, `lw` at 0x3e8, `lw` at 0x45c.
  3 such `lw` accesses load 4 bytes from [a0+56]:8 +0x1c, including `lw` at 0x280, `lw` at 0x3ec, `lw` at 0x460.
  The `lw` at 0x284 loads 4 bytes from [a0+112]:8 +0x1c.
  3 such `lw` accesses load 4 bytes from [a0+112]:8 +0x10, including `lw` at 0x290, `lw` at 0x3a8, `lw` at 0x3e0.
  The `lw` at 0x2ac loads 4 bytes from [a0+112]:8 +0x0.
  The `ld` at 0x31c loads 8 bytes from [a0+8]:8 +0x18.
  The `lw` at 0x32c loads 4 bytes from [a0+112]:8 +0x4.
  6 such `lw` accesses load 4 bytes from [0xa800000000001020]:8 +0x0, including `lw` at 0x364, `lw` at 0x514, `lw` at 0x560.
  9 such `ld` accesses load 8 bytes from [0xa800000000001020]:8 +0x80, including `ld` at 0x374, `ld` at 0x38c, `ld` at 0x524.
  The `ld` at 0x4b4 loads 8 bytes from a0 (arg0 at entry) +0xa0.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x94, including `lw` at 0x5d8, `lw` at 0x680.
  The `sw` at 0x5e8 stores 4 bytes to a0 (arg0 at entry) +0x94.
  The `sw` at 0x604 stores 4 bytes to [a0+64]:8 +0x0.
  The `jal` at 0x16c calls sio_lock_port with a0=a0 at entry (arg0), a1=0x0, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x1dc calls (unknown callee) with a0=a0 at entry (arg0), a1=0x1, a2=?, a3=?.
  The `jalr` at 0x21c calls (unknown callee) with a0=a0 at entry (arg0), a1=[[a0+8]:8]:8, a2=?, a3=?.
  The `jalr` at 0x26c calls (unknown callee) with a0=a0 at entry (arg0), a1=?, a2=?, a3=?, a4=[[a0+112]:8+20], a5=[a0+56]:8, a7=[[a0+8]:8+8]:8.
  The `jalr` at 0x324 calls (unknown callee) with a0=a0 at entry (arg0), a1=0x1, a2=?, a3=?.
  The `jal` at 0x380 calls spl7 with a0=[sym(the_console_port)]:8, a1=[[0xa800000000001020]:8+128]:8, a2=?, a3=?, a4=[0xa800000000001000]:8.
  The `jalr` at 0x394 calls (unknown callee) with a0=0x0, a1=?, a2=[[0xa800000000001020]:8+128]:8, a3=?.
  The `jalr` at 0x3d8 calls (unknown callee) with a0=a0 at entry (arg0), a1=[[a0+112]:8+16], a2=?, a3=?, a5=[[a0+8]:8]:8.
  The `jalr` at 0x44c calls (unknown callee) with a0=a0 at entry (arg0), a1=[[a0+112]:8+8], a2=?, a3=?.
  The `jal` at 0x484 calls mask_disable_intrs with a0=a0 at entry (arg0), a1=[[a0+112]:8+8], a2=?, a3=?.
  The `jal` at 0x494 calls sio_unlock_port with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x4bc calls ioc3_write_ireg with a0=[a0+160]:8, a1=[a0+144], a2=0x0, a3=?.
  The `jalr` at 0x4ec calls (unknown callee) with a0=a0 at entry (arg0), a1=0x0, a2=[[a0+8]:8+32]:8, a3=?.
  The `jal` at 0x530 calls spl7 with a0=[sym(the_console_port)]:8, a1=[[a0+112]:8], a2=?, a3=[a0+56]:8, a4=0xfffffffffeeddead, a5=[[0xa800000000001020]:8+128]:8.
  The `jalr` at 0x544 calls (unknown callee) with a0=0x0, a1=?, a2=?, a3=?, a6=[[0xa800000000001020]:8+128]:8.
  The `jalr` at 0x580 calls (unknown callee) with a0=0x1, a1=[[0xa800000000001020]:8+128]:8, a2=?, a3=?, a7=0xfffffffffeeddead.
  The `jal` at 0x588 calls splx with a0=[sym(.sbss)], a1=?, a2=?, a3=?.
  The `jalr` at 0x5c0 calls (unknown callee) with a0=0x1, a1=[[0xa800000000001020]:8+128]:8, a2=?, a3=?.
  The `jal` at 0x5c8 calls splx with a0=[sym(.sbss)], a1=?, a2=?, a3=?.
  The `jal` at 0x624 calls mask_disable_intrs with a0=a0 at entry (arg0), a1=[[a0+112]:8+16], a2=?, a3=?.
  The `jal` at 0x664 calls spl7 with a0=?, a1=[a0+148], a2=?, a3=?, a4=0xfffffffffeeddead, a5=[[0xa800000000001020]:8+128]:8.
  The `jalr` at 0x678 calls (unknown callee) with a0=0x0, a1=?, a2=?, a3=?, a6=[[0xa800000000001020]:8+128]:8.
  The `jalr` at 0x6b4 calls (unknown callee) with a0=0x1, a1=[[0xa800000000001020]:8+128]:8, a2=[a0+64]:8, a3=?, a7=0xfffffffffeeddead.
  The `jal` at 0x6bc calls splx with a0=[sym(.sbss)], a1=?, a2=?, a3=?.
  The `beq` branch at 0x190 targets 0x2ac and is always taken.
  The `bne` branch at 0x1a0 targets 0x1b4, is taken when s0(=a0) != a0(=[sym(the_console_port)]:8), and falls through when s0(=a0) == a0(=[sym(the_console_port)]:8).
  The `beq` branch at 0x1ac targets 0x598, is taken when s6(=0x53435241) == a1(=[0xa800000000001000]:8), and falls through when s6(=0x53435241) != a1(=[0xa800000000001000]:8).
  The `beq` branch at 0x1bc targets 0x1e4, is taken when (t8(=[a0+140]) & 0x80) == 0, and falls through when (t8(=[a0+140]) & 0x80) != 0.
  The `beq` branch at 0x1c4 targets 0x4dc, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x1cc targets 0x1e4, is taken when v0(=[a0+8]:8) == 0, and falls through when v0(=[a0+8]:8) != 0.
  The `beq` branch at 0x1ec targets 0x3a8, is taken when (v0(=[[a0+112]:8+12]) & s1(?)) == 0, and falls through when (v0(=[[a0+112]:8+12]) & s1(?)) != 0.
  The `beq` branch at 0x204 targets 0x224, is taken when (at(=[a0+140]) & 0x1) == 0, and falls through when (at(=[a0+140]) & 0x1) != 0.
  The `beq` branch at 0x210 targets 0x224, is taken when v0(=[a0+8]:8) == 0, and falls through when v0(=[a0+8]:8) != 0.
  The `beq` branch at 0x22c targets 0x41c, is taken when (a2(=[[a0+112]:8+20]) & s1(?)) == 0, and falls through when (a2(=[[a0+112]:8+20]) & s1(?)) != 0.
  The `beq` branch at 0x254 targets 0x274, is taken when (a3(=[a0+140]) & 0x2) == 0, and falls through when (a3(=[a0+140]) & 0x2) != 0.
  The `beq` branch at 0x260 targets 0x274, is taken when v0(=[a0+8]:8) == 0, and falls through when v0(=[a0+8]:8) != 0.
  The `beq` branch at 0x288 targets 0x2a0, is taken when t9(?) == 0, and falls through when t9(?) != 0.
  The `bne` branch at 0x294 targets 0x2a0, is taken when a0(=[[a0+112]:8+16]) != s1(?), and falls through when a0(=[[a0+112]:8+16]) == s1(?).
  The `beq` branch at 0x2a4 targets 0x494, is taken when (v0(=[[a0+112]:8+28]) & s1(?)) == 0, and falls through when (v0(=[[a0+112]:8+28]) & s1(?)) != 0.
  The `beq` branch at 0x2b4 targets 0x32c, is taken when (a1(=[[a0+112]:8]) & s1(?)) == 0, and falls through when (a1(=[[a0+112]:8]) & s1(?)) != 0.
  The `bne` branch at 0x2cc targets 0x2dc, is taken when s0(=a0) != a0(=[sym(the_console_port)]:8), and falls through when s0(=a0) == a0(=[sym(the_console_port)]:8).
  The `beq` branch at 0x2d4 targets 0x50c, is taken when s6(=0x53435241) == a4(=[0xa800000000001000]:8), and falls through when s6(=0x53435241) != a4(=[0xa800000000001000]:8).
  The `bne` branch at 0x2e4 targets 0x2f8, is taken when s0(=a0) != a0(=[sym(the_console_port)]:8), and falls through when s0(=a0) == a0(=[sym(the_console_port)]:8).
  The `beq` branch at 0x2f0 targets 0x558, is taken when s6(=0x53435241) == a1(=[0xa800000000001000]:8), and falls through when s6(=0x53435241) != a1(=[0xa800000000001000]:8).
  The `beq` branch at 0x300 targets 0x32c, is taken when (t8(=[a0+140]) & 0x40) == 0, and falls through when (t8(=[a0+140]) & 0x40) != 0.
  The `beq` branch at 0x308 targets 0x4fc, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x314 targets 0x32c, is taken when v0(=[a0+8]:8) == 0, and falls through when v0(=[a0+8]:8) != 0.
  The `beq` branch at 0x334 targets 0x1e4, is taken when (a1(=[[a0+112]:8+4]) & s1(?)) == 0, and falls through when (a1(=[[a0+112]:8+4]) & s1(?)) != 0.
  The `bne` branch at 0x34c targets 0x198, is taken when s0(=a0) != a0(=[sym(the_console_port)]:8), and falls through when s0(=a0) == a0(=[sym(the_console_port)]:8).
  The `bne` branch at 0x354 targets 0x198, is taken when s6(=0x53435241) != a4(=[0xa800000000001000]:8), and falls through when s6(=0x53435241) == a4(=[0xa800000000001000]:8).
  The `beq` branch at 0x35c targets 0x198, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x36c targets 0x198, is taken when v1(=0xfffffffffeeddead) != a1(=[[0xa800000000001020]:8]), and falls through when v1(=0xfffffffffeeddead) == a1(=[[0xa800000000001020]:8]).
  The `beq` branch at 0x378 targets 0x198, is taken when a1(=[[0xa800000000001020]:8+128]:8) == 0, and falls through when a1(=[[0xa800000000001020]:8+128]:8) != 0.
  The `beq` branch at 0x3a0 targets 0x198 and is always taken.
  The `beq` branch at 0x3b0 targets 0x224, is taken when (a1(=[[a0+112]:8+16]) & s1(?)) == 0, and falls through when (a1(=[[a0+112]:8+16]) & s1(?)) != 0.
  The `beq` branch at 0x3c0 targets 0x3e4, is taken when (a4(=[a0+140]) & 0x1) == 0, and falls through when (a4(=[a0+140]) & 0x1) != 0.
  The `beq` branch at 0x3cc targets 0x3e4, is taken when v0(=[a0+8]:8) == 0, and falls through when v0(=[a0+8]:8) != 0.
  The `beq` branch at 0x3fc targets 0x224, is taken when (s1(?) & a1(=[[a0+112]:8+16])) == 0, and falls through when (s1(?) & a1(=[[a0+112]:8+16])) != 0.
  The `beq` branch at 0x40c targets 0x624, is taken when (t8(=[a0+120]) & 0x8) == 0, and falls through when (t8(=[a0+120]) & 0x8) != 0.
  The `beq` branch at 0x414 targets 0x224 and is always taken.
  The `beq` branch at 0x424 targets 0x274, is taken when (a1(=[[a0+112]:8+8]) & s1(?)) == 0, and falls through when (a1(=[[a0+112]:8+8]) & s1(?)) != 0.
  The `beq` branch at 0x434 targets 0x46c, is taken when (ra(=[a0+140]) & 0x2) == 0, and falls through when (ra(=[a0+140]) & 0x2) != 0.
  The `beq` branch at 0x440 targets 0x458, is taken when v0(=[a0+8]:8) == 0, and falls through when v0(=[a0+8]:8) != 0.
  The `beq` branch at 0x46c targets 0x274, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x47c targets 0x5d8, is taken when (v1(=[a0+140]) & 0x41) == 0, and falls through when (v1(=[a0+140]) & 0x41) != 0.
  The `beq` branch at 0x48c targets 0x278 and is always taken.
  The `beq` branch at 0x4dc targets 0x1e4, is taken when v0(=[a0+8]:8) == 0, and falls through when v0(=[a0+8]:8) != 0.
  The `beq` branch at 0x4f4 targets 0x1e8 and is always taken.
  The `beq` branch at 0x504 targets 0x32c and is always taken.
  The `beq` branch at 0x50c targets 0x2dc, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x51c targets 0x2dc, is taken when a4(=0xfffffffffeeddead) != a5(=[[0xa800000000001020]:8]), and falls through when a4(=0xfffffffffeeddead) == a5(=[[0xa800000000001020]:8]).
  The `beq` branch at 0x528 targets 0x2dc, is taken when a5(=[[0xa800000000001020]:8+128]:8) == 0, and falls through when a5(=[[0xa800000000001020]:8+128]:8) != 0.
  The `beq` branch at 0x550 targets 0x2dc and is always taken.
  The `beq` branch at 0x558 targets 0x2f8, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x568 targets 0x2f8, is taken when a7(=0xfffffffffeeddead) != t0(=[[0xa800000000001020]:8]), and falls through when a7(=0xfffffffffeeddead) == t0(=[[0xa800000000001020]:8]).
  The `beq` branch at 0x574 targets 0x2f8, is taken when a1(=[[0xa800000000001020]:8+128]:8) == 0, and falls through when a1(=[[0xa800000000001020]:8+128]:8) != 0.
  The `beq` branch at 0x590 targets 0x2fc and is always taken.
  The `beq` branch at 0x598 targets 0x1b4, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x5a8 targets 0x1b4, is taken when t1(=0xfffffffffeeddead) != t2(=[[0xa800000000001020]:8]), and falls through when t1(=0xfffffffffeeddead) == t2(=[[0xa800000000001020]:8]).
  The `beq` branch at 0x5b4 targets 0x1b4, is taken when a1(=[[0xa800000000001020]:8+128]:8) == 0, and falls through when a1(=[[0xa800000000001020]:8+128]:8) != 0.
  The `beq` branch at 0x5d0 targets 0x1b8 and is always taken.
  The `bne` branch at 0x5f0 targets 0x600, is taken when t3(=[sym(the_console_port)]:8) != s0(=a0), and falls through when t3(=[sym(the_console_port)]:8) == s0(=a0).
  The `beq` branch at 0x5f8 targets 0x63c, is taken when s6(=0x53435241) == v0(=[0xa800000000001000]:8), and falls through when s6(=0x53435241) != v0(=[0xa800000000001000]:8).
  The `bne` branch at 0x60c targets 0x61c, is taken when a1(=[sym(the_console_port)]:8) != s0(=a0), and falls through when a1(=[sym(the_console_port)]:8) == s0(=a0).
  The `beq` branch at 0x614 targets 0x68c, is taken when s6(=0x53435241) == v0(=[0xa800000000001000]:8), and falls through when s6(=0x53435241) != v0(=[0xa800000000001000]:8).
  The `beq` branch at 0x61c targets 0x484 and is always taken.
  The `beq` branch at 0x634 targets 0x224 and is always taken.
  The `beq` branch at 0x63c targets 0x600, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x650 targets 0x600, is taken when a4(=0xfffffffffeeddead) != a5(=[[0xa800000000001020]:8]), and falls through when a4(=0xfffffffffeeddead) == a5(=[[0xa800000000001020]:8]).
  The `beq` branch at 0x65c targets 0x600, is taken when a5(=[[0xa800000000001020]:8+128]:8) == 0, and falls through when a5(=[[0xa800000000001020]:8+128]:8) != 0.
  The `beq` branch at 0x684 targets 0x600 and is always taken.
  The `beq` branch at 0x68c targets 0x61c, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x6a0 targets 0x61c, is taken when a7(=0xfffffffffeeddead) != t0(=[[0xa800000000001020]:8]), and falls through when a7(=0xfffffffffeeddead) == t0(=[[0xa800000000001020]:8]).
  The `beq` branch at 0x6ac targets 0x61c, is taken when a1(=[[0xa800000000001020]:8+128]:8) == 0, and falls through when a1(=[[0xa800000000001020]:8+128]:8) != 0.
  The `beq` branch at 0x6c4 targets 0x61c and is always taken.
  The return at 0x4d4 has v0 = ret(ioc3_write_ireg).

- `set_baud_ti` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc3.o)` at 0x6cc (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc3.o)`.
  Range: 0x6cc-0x7b4 (232 bytes).
  It occupies 232 bytes.
  5 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x48, including `ld` at 0x778, `ld` at 0x788, `ld` at 0x790.
  The `lbu` at 0x77c loads 1 byte from [a0+72]:8 +0x3.
  2 such `sb` accesses store 1 byte to [a0+72]:8 +0x3, including `sb` at 0x784, `sb` at 0x7a8.
  The `sb` at 0x78c stores 1 byte to [a0+72]:8 +0x0.
  The `sb` at 0x794 stores 1 byte to [a0+72]:8 +0x1.
  The `sb` at 0x79c stores 1 byte to [a0+72]:8 +0x7.
  The `beq` branch at 0x6dc targets 0x714 and is always taken.
  The `beq` branch at 0x6fc targets 0x768, is taken when t1(?) >= t9(?) (signed), and falls through when t1(?) < t9(?) (signed).
  The `beq` branch at 0x70c targets 0x768, is taken when a4(?) >= 0x40 (signed), and falls through when a4(?) < 0x40 (signed).
  The `beq` branch at 0x738 targets 0x704, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `bgez` branch at 0x758 targets 0x6e4, is taken when t9(?) >= 0 (signed), and falls through when t9(?) < 0 (signed).
  The `beq` branch at 0x760 targets 0x6e4 and is always taken.
  The `beq` branch at 0x770 targets 0x7ac, is taken when a4(?) == a1(=0x40), and falls through when a4(?) != a1(=0x40).
  The return at 0x7ac has v0 = one of 0x0, 0x1.

- `ioc3_serial_attach` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc3.o)` at 0xa58 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc3.o)`.
  Range: 0xa58-0xf6c (1300 bytes).
  It occupies 1300 bytes.
  The `ld` at 0xb24 loads 8 bytes from (([sym(master_nasid)]:2 << 0x21)+0x9600000000000000 | 0x2000) +0x48.
  3 such `lw` accesses load 4 bytes from ?, including `lw` at 0xb34, `lw` at 0xb40, `lw` at 0xe44.
  The `sd` at 0xc04 stores 8 bytes to ret(kmem_zalloc) +0x70.
  The `ld` at 0xc08 loads 8 bytes from ret(kmem_zalloc) +0x50.
  4 such `ld` accesses load 8 bytes from ret(kmem_zalloc) +0x58, including `ld` at 0xc0c, `ld` at 0xc30, `ld` at 0xcc8.
  The `ld` at 0xc10 loads 8 bytes from ret(kmem_zalloc) +0x38.
  The `sd` at 0xc18 stores 8 bytes to ret(kmem_zalloc) +0x48.
  The `sd` at 0xc24 stores 8 bytes to ret(kmem_zalloc) +0x40.
  The `sd` at 0xc3c stores 8 bytes to ret(kmem_zalloc) +0x68.
  The `sd` at 0xc48 stores 8 bytes to ret(kmem_zalloc) +0x60.
  4 such `lw` accesses load 4 bytes from ret(kmem_zalloc) +0x34, including `lw` at 0xc54, `lw` at 0xc68, `lw` at 0xc74.
  The `sd` at 0xcc4 stores 8 bytes to ret(kmem_zalloc) +0x118.
  The `sd` at 0xccc stores 8 bytes to ret(kmem_zalloc) +0x100.
  The `ld` at 0xcd0 loads 8 bytes from ret(kmem_zalloc) +0xe0.
  The `ld` at 0xcd4 loads 8 bytes from ret(kmem_zalloc) +0xf8.
  The `sd` at 0xcdc stores 8 bytes to ret(kmem_zalloc) +0xe8.
  The `sd` at 0xce8 stores 8 bytes to ret(kmem_zalloc) +0xf0.
  The `sd` at 0xcf4 stores 8 bytes to ret(kmem_zalloc) +0x108.
  The `sd` at 0xd00 stores 8 bytes to ret(kmem_zalloc) +0x110.
  4 such `lw` accesses load 4 bytes from ret(kmem_zalloc) +0xdc, including `lw` at 0xd0c, `lw` at 0xd20, `lw` at 0xd3c.
  6 such `sw` accesses store 4 bytes to ?, including `sw` at 0xd88, `sw` at 0xe10, `sw` at 0xe18.
  5 such `sd` accesses store 8 bytes to ?, including `sd` at 0xdb4, `sd` at 0xdc0, `sd` at 0xdd0.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0xde8, `ld` at 0xdf0.
  2 such `sb` accesses store 1 byte to ret(kmem_zalloc) +0x1d, including `sb` at 0xe70, `sb` at 0xef4.
  The `sd` at 0xf58 stores 8 bytes to ret(kmem_zalloc) +0x58.
  The `jal` at 0xa64 calls ioc3_subdev_enabled with a0=a0 at entry (arg0), a1=0x4, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa8c calls ioc3_subdev_enabled with a0=a0 at entry (arg0), a1=0x4, a2=?, a3=?.
  The `jal` at 0xab0 calls ioc3_subdev_enabled with a0=a0 at entry (arg0), a1=0x5, a2=?, a3=?.
  The `jal` at 0xaec calls pciio_piotrans_addr with a0=a0 at entry (arg0), a1=0x0, a2=0x8, a3=0x0, a4=0x20180, a5=0x0.
  The `jal` at 0xaf8 calls ioc3_is_console with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xb68 calls hwgraph_traverse with a0=a0 at entry (arg0), a1=sym(.rodata), a2=sp-12, a3=?.
  The `jal` at 0xb7c calls hwgraph_traverse with a0=a0 at entry (arg0), a1=sym(.rodata), a2=sp-176, a3=?.
  The `jal` at 0xb84 calls hwgraph_fastinfo_get with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xb94 calls kmem_zalloc with a0=0x150, a1=0x0, a2=?, a3=?.
  The `jal` at 0xbf4 calls ioc3_subdev_enabled with a0=a0 at entry (arg0), a1=0x4, a2=?, a3=?.
  The `jal` at 0xc28 calls bzero with a0=?, a1=0x4000, a2=?, a3=?.
  The `jal` at 0xc44 calls hardware_init with a0=ret(kmem_zalloc), a1=one of 0x0, 0x1, a2=?, a3=?, a7=[ret(kmem_zalloc)+88]:8+4096.
  The `jal` at 0xc58 calls hwgraph_edge_get with a0=[ret(kmem_zalloc)+52], a1=sym(.rodata), a2=sp-140, a3=?.
  The `jal` at 0xc84 calls ioc3_intr_connect with a0=a0 at entry (arg0), a1=0x1ff, a2=sym(ioc3_serial_intr), a3=ret(kmem_zalloc), a4=[ret(kmem_zalloc)+52], a6=0x0.
  The `jal` at 0xc98 calls device_controller_num_set with a0=[ret(kmem_zalloc)+52], a1=0x1, a2=?, a3=?.
  The `jal` at 0xca0 calls sio_make_hwgraph_nodes with a0=ret(kmem_zalloc), a1=?, a2=?, a3=?.
  The `jal` at 0xcb4 calls ioc3_subdev_enabled with a0=a0 at entry (arg0), a1=0x5, a2=?, a3=?.
  The `jal` at 0xcfc calls hardware_init with a0=?, a1=0x0, a2=[ret(kmem_zalloc)+88]:8+8192, a3=[ret(kmem_zalloc)+88]:8+12288, a4=[ret(kmem_zalloc)+248]:8+368, a5=[ret(kmem_zalloc)+224]:8+212, a6=sym(.data).
  The `jal` at 0xd10 calls hwgraph_edge_get with a0=[ret(kmem_zalloc)+220], a1=sym(.rodata), a2=sp-140, a3=?.
  The `jal` at 0xd40 calls ioc3_intr_connect with a0=a0 at entry (arg0), a1=0x3fe00, a2=sym(ioc3_serial_intr), a3=?, a4=[ret(kmem_zalloc)+220], a6=0x0.
  The `jal` at 0xd50 calls device_controller_num_set with a0=[ret(kmem_zalloc)+220], a1=0x2, a2=?, a3=?.
  The `jal` at 0xd58 calls sio_make_hwgraph_nodes with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xdac calls device_inventory_add with a0=?, a1=0x4, a2=0x10, a3=-0x1, a4=0x0, a5=0x0.
  The `jal` at 0xe04 calls hwgraph_path_add with a0=a0 at entry (arg0), a1=?, a2=sp-148, a3=?.
  The `jal` at 0xe24 calls hwgraph_fastinfo_set with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xe48 calls sio_initport with a0=?, a1=?, a2=0x1ff, a3=one of 0x0, 0x1.
  The `jal` at 0xe54 calls kmem_zalloc with a0=0x28, a1=0x0, a2=?, a3=?.
  The `jal` at 0xe74 calls sio_init_locks with a0=ret(kmem_zalloc), a1=?, a2=one of 0x2, 0x3, a3=?.
  The `jal` at 0xe98 calls hwgraph_edge_get with a0=?, a1=sym(.rodata), a2=sp-144, a3=?.
  The `jal` at 0xec0 calls kopt_find with a0=sym(.rodata), a1=?, a2=?, a3=0x1.
  The `jal` at 0xed0 calls atoi with a0=ret(kopt_find), a1=?, a2=0x1, a3=?.
  The `jal` at 0xf08 calls ioc3_subdev_enabled with a0=a0 at entry (arg0), a1=0x5, a2=?, a3=?.
  The `jal` at 0xf30 calls printf with a0=sym(.rodata), a1=?, a2=0x1, a3=?.
  The `jal` at 0xf48 calls kvpalloc with a0=0x1, a1=0x100, a2=0x0, a3=?, a5=[ret(kmem_zalloc)+56]:8+184, a6=[ret(kmem_zalloc)+80]:8+376.
  The `jal` at 0xf5c calls panic with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `beq` branch at 0xa80 targets 0xf04, is taken when v0(=ret(ioc3_subdev_enabled)) == 0, and falls through when v0(=ret(ioc3_subdev_enabled)) != 0.
  The `beq` branch at 0xa9c targets 0xf20, is taken when v0(=ret(ioc3_subdev_enabled)) == 0, and falls through when v0(=ret(ioc3_subdev_enabled)) != 0.
  The `beq` branch at 0xab8 targets 0xad0, is taken when v0(=ret(ioc3_subdev_enabled)) == 0, and falls through when v0(=ret(ioc3_subdev_enabled)) != 0.
  The `beq` branch at 0xb00 targets 0xb5c, is taken when v0(=ret(ioc3_is_console)) == 0, and falls through when v0(=ret(ioc3_is_console)) != 0.
  The `bne` branch at 0xb48 targets 0xb5c, is taken when a5(?) != a6(=0x310a9), and falls through when a5(?) == a6(=0x310a9).
  The `beq` branch at 0xb54 targets 0xb60 and is always taken.
  The `bne` branch at 0xbb4 targets 0xbd8, is taken when s5(=one of -0x1, 0x0, 0x1) < s0(=one of -0x1, 0x0, 0x1) (signed), and falls through when s5(=one of -0x1, 0x0, 0x1) >= s0(=one of -0x1, 0x0, 0x1) (signed).
  The `beq` branch at 0xbd0 targets 0xdd4 and is always taken.
  The `beq` branch at 0xbfc targets 0xcb0, is taken when v0(=ret(ioc3_subdev_enabled)) == 0, and falls through when v0(=ret(ioc3_subdev_enabled)) != 0.
  The `beq` branch at 0xc20 targets 0xf40, is taken when a0(=[ret(kmem_zalloc)+88]:8) == 0, and falls through when a0(=[ret(kmem_zalloc)+88]:8) != 0.
  The `beq` branch at 0xc60 targets 0xc70, is taken when v0(=ret(hwgraph_edge_get)) == 0, and falls through when v0(=ret(hwgraph_edge_get)) != 0.
  The `beq` branch at 0xc8c targets 0xcb0, is taken when s3(=one of 0x0, 0x1) == 0, and falls through when s3(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0xcbc targets 0xd60, is taken when v0(=ret(ioc3_subdev_enabled)) == 0, and falls through when v0(=ret(ioc3_subdev_enabled)) != 0.
  The `beq` branch at 0xd18 targets 0xd28, is taken when v0(=ret(hwgraph_edge_get)) == 0, and falls through when v0(=ret(hwgraph_edge_get)) != 0.
  The `beq` branch at 0xd48 targets 0xd60, is taken when s3(=one of 0x0, 0x1) == 0, and falls through when s3(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0xd90 targets 0xf28, is taken when s0(?) == a2(=0x1), and falls through when s0(?) != a2(=0x1).
  The `bne` branch at 0xdcc targets 0xbd8, is taken when s5(=one of -0x1, 0x0, 0x1) < s0(?) (signed), and falls through when s5(=one of -0x1, 0x0, 0x1) >= s0(?) (signed).
  The `beq` branch at 0xe2c targets 0xe40, is taken when s3(=one of 0x0, 0x1) == 0, and falls through when s3(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0xe34 targets 0xee8, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0xe5c targets 0xe6c, is taken when s3(=one of 0x0, 0x1) == 0, and falls through when s3(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0xe64 targets 0xef0, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0xe84 targets 0xd98, is taken when s3(=one of 0x0, 0x1) == 0, and falls through when s3(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0xea8 targets 0xef8, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `bne` branch at 0xeb0 targets 0xd9c, is taken when s0(?) != a3(=0x1), and falls through when s0(?) == a3(=0x1).
  The `beq` branch at 0xec8 targets 0xd90, is taken when v0(=ret(kopt_find)) == 0, and falls through when v0(=ret(kopt_find)) != 0.
  The `bgtz` branch at 0xed8 targets 0xd88, is taken when v0(=ret(atoi)) > 0 (signed), and falls through when v0(=ret(atoi)) <= 0 (signed).
  The `beq` branch at 0xee0 targets 0xd90 and is always taken.
  The `beq` branch at 0xee8 targets 0xe44 and is always taken.
  The `beq` branch at 0xef0 targets 0xe74 and is always taken.
  The `beq` branch at 0xefc targets 0xec0 and is always taken.
  The `bne` branch at 0xf10 targets 0xa8c, is taken when v0(=ret(ioc3_subdev_enabled)) != 0, and falls through when v0(=ret(ioc3_subdev_enabled)) == 0.
  The `beq` branch at 0xf18 targets 0xd64 and is always taken.
  The `beq` branch at 0xf20 targets 0xaac and is always taken.
  The `beq` branch at 0xf28 targets 0xf38, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0xf38 targets 0xd98 and is always taken.
  The `bne` branch at 0xf54 targets 0xc28, is taken when v0(=ret(kvpalloc)) != 0, and falls through when v0(=ret(kvpalloc)) == 0.
  The `beq` branch at 0xf64 targets 0xc28 and is always taken.
  The return at 0xd80 has v0 = one of -0x1, 0x0.

- `ioc3_serial_kill` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc3.o)` at 0xf6c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc3.o)`.
  Range: 0xf6c-0x1084 (280 bytes).
  It occupies 280 bytes.
  The `ld` at 0xf6c loads 8 bytes from a0 (arg0 at entry) +0x8.
  The `ld` at 0xf84 loads 8 bytes from [a0+8]:8 +0x28.
  2 such `ld` accesses load 8 bytes from abs 0xa800000000001000, including `ld` at 0xfa8, `ld` at 0xffc.
  3 such `ld` accesses load 8 bytes from abs 0xa800000000001020, including `ld` at 0xfac, `ld` at 0xff0, `ld` at 0x1064.
  2 such `lw` accesses load 4 bytes from [0xa800000000001020]:8 +0x0, including `lw` at 0xfc0, `lw` at 0x1014.
  3 such `ld` accesses load 8 bytes from [0xa800000000001020]:8 +0x80, including `ld` at 0xfcc, `ld` at 0x1020, `ld` at 0x1068.
  The `ld` at 0xfd8 loads 8 bytes from a0 (arg0 at entry) +0x40.
  The `sw` at 0xfe0 stores 4 bytes to [a0+64]:8 +0x0.
  The `sw` at 0x1048 stores 4 bytes to a0 (arg0 at entry) +0x94.
  The `jalr` at 0xf88 calls (unknown callee) with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x1034 calls (unknown callee) with a0=0x1, a1=[a0+64]:8, a2=[[0xa800000000001020]:8], a3=[[0xa800000000001020]:8+128]:8, a4=[sym(.sbss)], a5=[sym(the_console_port)]:8.
  The `jal` at 0x103c calls splx with a0=[sym(.sbss)], a1=?, a2=?, a3=?.
  The `jal` at 0x1058 calls spl7 with a0=0xa800000000001020, a1=?, a2=?, a3=[0xa800000000001000]:8, a4=0x53435241, a5=[[0xa800000000001020]:8], a6=0xfffffffffeeddead, a7=[[0xa800000000001020]:8+128]:8.
  The `jalr` at 0x1070 calls (unknown callee) with a0=0x0, a1=?, a2=?, a3=?, a5=[[0xa800000000001020]:8+128]:8.
  The `beq` branch at 0xf7c targets 0xf90, is taken when v0(=[a0+8]:8) == 0, and falls through when v0(=[a0+8]:8) != 0.
  The `bne` branch at 0xfa4 targets 0xfd8, is taken when a5(=[sym(the_console_port)]:8) != s0(=a0), and falls through when a5(=[sym(the_console_port)]:8) == s0(=a0).
  The `bne` branch at 0xfb0 targets 0xfd8, is taken when a3(=[0xa800000000001000]:8) != a4(=0x53435241), and falls through when a3(=[0xa800000000001000]:8) == a4(=0x53435241).
  The `beq` branch at 0xfb8 targets 0xfd8, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0xfc4 targets 0xfd8, is taken when a5(=[[0xa800000000001020]:8]) != a6(=0xfffffffffeeddead), and falls through when a5(=[[0xa800000000001020]:8]) == a6(=0xfffffffffeeddead).
  The `bne` branch at 0xfd0 targets 0x1058, is taken when a7(=[[0xa800000000001020]:8+128]:8) != 0, and falls through when a7(=[[0xa800000000001020]:8+128]:8) == 0.
  The `bne` branch at 0xff8 targets 0x1044, is taken when a5(=[sym(the_console_port)]:8) != s0(=a0), and falls through when a5(=[sym(the_console_port)]:8) == s0(=a0).
  The `bne` branch at 0x1000 targets 0x1048, is taken when a3(=[0xa800000000001000]:8) != a0(=0x53435241), and falls through when a3(=[0xa800000000001000]:8) == a0(=0x53435241).
  The `beq` branch at 0x1008 targets 0x1048, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x1018 targets 0x1048, is taken when a2(=[[0xa800000000001020]:8]) != a3(=0xfffffffffeeddead), and falls through when a2(=[[0xa800000000001020]:8]) == a3(=0xfffffffffeeddead).
  The `beq` branch at 0x1024 targets 0x1048, is taken when a3(=[[0xa800000000001020]:8+128]:8) == 0, and falls through when a3(=[[0xa800000000001020]:8+128]:8) != 0.
  The `beq` branch at 0x107c targets 0xfd8 and is always taken.
  The return at 0x1050 has v0 = one of [0xa800000000001020]:8, ?.

- `ioc3_open` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc3.o)` at 0x1084 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc3.o)`.
  Range: 0x1084-0x1328 (676 bytes).
  It occupies 676 bytes.
  The `sb` at 0x1084 stores 1 byte to a0 (arg0 at entry) +0x7c.
  4 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x94, including `lw` at 0x1088, `lw` at 0x11b4, `lw` at 0x12e0.
  The `sw` at 0x108c stores 4 bytes to a0 (arg0 at entry) +0x78.
  4 such `ld` accesses load 8 bytes from abs 0xa800000000001000, including `ld` at 0x10bc, `ld` at 0x113c, `ld` at 0x11d8.
  6 such `ld` accesses load 8 bytes from abs 0xa800000000001020, including `ld` at 0x10d0, `ld` at 0x1150, `ld` at 0x11e4.
  4 such `lw` accesses load 4 bytes from [0xa800000000001020]:8 +0x0, including `lw` at 0x10dc, `lw` at 0x115c, `lw` at 0x11f8.
  6 such `ld` accesses load 8 bytes from [0xa800000000001020]:8 +0x80, including `ld` at 0x10e8, `ld` at 0x1168, `ld` at 0x1204.
  4 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x40, including `ld` at 0x10f4, `ld` at 0x1104, `ld` at 0x1210.
  2 such `sw` accesses store 4 bytes to [a0+64]:8 +0x0, including `sw` at 0x1100, `sw` at 0x1214.
  2 such `lw` accesses load 4 bytes from [a0+64]:8 +0x0, including `lw` at 0x1108, `lw` at 0x1294.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x48, including `ld` at 0x1190, `ld` at 0x11a8.
  The `sb` at 0x11a4 stores 1 byte to [a0+72]:8 +0x2.
  The `sb` at 0x11b0 stores 1 byte to [a0+72]:8 +0x3.
  The `sw` at 0x11c8 stores 4 bytes to a0 (arg0 at entry) +0x94.
  The `sw` at 0x1270 stores 4 bytes to [a0+64]:8 +0x14.
  The `sw` at 0x127c stores 4 bytes to a0 (arg0 at entry) +0x84.
  The `jalr` at 0x1178 calls (unknown callee) with a0=0x1, a1=0xfffffffffeeddead, a2=[sym(.sbss)], a3=[[0xa800000000001020]:8+128]:8, a4=0xf4240, a5=0x40000000, a7=([a0+148] | 0x20000000).
  The `jal` at 0x1180 calls splx with a0=[sym(.sbss)], a1=?, a2=?, a3=?.
  The `jal` at 0x11a0 calls set_baud_ti with a0=a0 at entry (arg0), a1=0x2580, a2=?, a3=0x3, a4=[a0+72]:8.
  The `jalr` at 0x125c calls (unknown callee) with a0=0x1, a1=?, a2=?, a3=[[0xa800000000001020]:8+128]:8.
  The `jal` at 0x1264 calls splx with a0=[sym(.sbss)], a1=?, a2=?, a3=?.
  The `jal` at 0x12c0 calls spl7 with a0=0xa800000000001020, a1=[0xa800000000001000]:8, a2=[[0xa800000000001020]:8], a3=[a0+148], a4=0xfffffffffeeddead, a5=[[0xa800000000001020]:8+128]:8.
  The `jalr` at 0x12d8 calls (unknown callee) with a0=0x0, a1=?, a2=?, a3=?, a7=[[0xa800000000001020]:8+128]:8.
  The `jal` at 0x12ec calls spl7 with a0=0x53435241, a1=?, a2=?, a3=?, a4=[0xa800000000001000]:8, a5=[sym(the_console_port)]:8, a6=0x3, a7=[a0+72]:8.
  The `jalr` at 0x1300 calls (unknown callee) with a0=0x0, a1=?, a2=?, a3=?.
  The `bgez` branch at 0x10a4 targets 0x1190, is taken when at(=([a0+148] << 0x23)) >= 0 (signed), and falls through when at(=([a0+148] << 0x23)) < 0 (signed).
  The `bne` branch at 0x10b0 targets 0x10f4, is taken when v1(=[sym(the_console_port)]:8) != a0, and falls through when v1(=[sym(the_console_port)]:8) == a0.
  The `bne` branch at 0x10cc targets 0x10f4, is taken when a1(=[0xa800000000001000]:8) != a2(=0x53435241), and falls through when a1(=[0xa800000000001000]:8) == a2(=0x53435241).
  The `beq` branch at 0x10d4 targets 0x10f4, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x10e0 targets 0x10f4, is taken when a2(=[[0xa800000000001020]:8]) != a4(=0xfffffffffeeddead), and falls through when a2(=[[0xa800000000001020]:8]) == a4(=0xfffffffffeeddead).
  The `bne` branch at 0x10ec targets 0x12c0, is taken when a5(=[[0xa800000000001020]:8+128]:8) != 0, and falls through when a5(=[[0xa800000000001020]:8+128]:8) == 0.
  The `bltz` branch at 0x1118 targets 0x1128, is taken when a6(=([[a0+64]:8] << 0x21)) < 0 (signed), and falls through when a6(=([[a0+64]:8] << 0x21)) >= 0 (signed).
  The `beq` branch at 0x1120 targets 0x1318 and is always taken.
  The `bne` branch at 0x1130 targets 0x1188, is taken when t0(=[sym(the_console_port)]:8) != s0(=a0), and falls through when t0(=[sym(the_console_port)]:8) == s0(=a0).
  The `bne` branch at 0x114c targets 0x1188, is taken when v1(=[0xa800000000001000]:8) != a0(=0x53435241), and falls through when v1(=[0xa800000000001000]:8) == a0(=0x53435241).
  The `beq` branch at 0x1154 targets 0x1188, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x1160 targets 0x1188, is taken when a0(=[[0xa800000000001020]:8]) != a1(=0xfffffffffeeddead), and falls through when a0(=[[0xa800000000001020]:8]) == a1(=0xfffffffffeeddead).
  The `beq` branch at 0x116c targets 0x1188, is taken when a3(=[[0xa800000000001020]:8+128]:8) == 0, and falls through when a3(=[[0xa800000000001020]:8+128]:8) != 0.
  The `beq` branch at 0x1188 targets 0x12b8, is taken when s1(=one of 0x0, 0x1) == 0, and falls through when s1(=one of 0x0, 0x1) != 0.
  The `bne` branch at 0x11e0 targets 0x1210, is taken when a5(=[sym(the_console_port)]:8) != s0(=a0), and falls through when a5(=[sym(the_console_port)]:8) == s0(=a0).
  The `bne` branch at 0x11e8 targets 0x1210, is taken when a4(=[0xa800000000001000]:8) != a0(=0x53435241), and falls through when a4(=[0xa800000000001000]:8) == a0(=0x53435241).
  The `beq` branch at 0x11f0 targets 0x1210, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x11fc targets 0x1210, is taken when t0(=[[0xa800000000001020]:8]) != t1(=0xfffffffffeeddead), and falls through when t0(=[[0xa800000000001020]:8]) == t1(=0xfffffffffeeddead).
  The `bne` branch at 0x1208 targets 0x12ec, is taken when t2(=[[0xa800000000001020]:8+128]:8) != 0, and falls through when t2(=[[0xa800000000001020]:8+128]:8) == 0.
  The `bne` branch at 0x121c targets 0x126c, is taken when t3(=[sym(the_console_port)]:8) != s0(=a0), and falls through when t3(=[sym(the_console_port)]:8) == s0(=a0).
  The `bne` branch at 0x1230 targets 0x126c, is taken when t9(=[0xa800000000001000]:8) != ra(=0x53435241), and falls through when t9(=[0xa800000000001000]:8) == ra(=0x53435241).
  The `beq` branch at 0x123c targets 0x126c, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x1248 targets 0x126c, is taken when v1(=[[0xa800000000001020]:8]) != a0(=0xfffffffffeeddead), and falls through when v1(=[[0xa800000000001020]:8]) == a0(=0xfffffffffeeddead).
  The `beq` branch at 0x1254 targets 0x126c, is taken when a3(=[[0xa800000000001020]:8+128]:8) == 0, and falls through when a3(=[[0xa800000000001020]:8+128]:8) != 0.
  The `bne` branch at 0x12a0 targets 0x1128, is taken when (a3(=[[a0+64]:8]) & a5(=0x40000000)) != 0, and falls through when (a3(=[[a0+64]:8]) & a5(=0x40000000)) == 0.
  The `beq` branch at 0x12a8 targets 0x1294, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `beq` branch at 0x12b0 targets 0x1130 and is always taken.
  The `beq` branch at 0x12b8 targets 0x1280 and is always taken.
  The `beq` branch at 0x12e4 targets 0x10f4 and is always taken.
  The `beq` branch at 0x1310 targets 0x1210 and is always taken.
  The `beq` branch at 0x1320 targets 0x12a8 and is always taken.
  The return at 0x128c has v0 = one of -0x1, 0x0.

- `ioc3_config` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc3.o)` at 0x1328 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc3.o)`.
  Range: 0x1328-0x16b8 (912 bytes).
  It occupies 912 bytes.
  4 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x94, including `lw` at 0x13a8, `lw` at 0x14e0, `lw` at 0x166c.
  4 such `ld` accesses load 8 bytes from abs 0xa800000000001000, including `ld` at 0x13c4, `ld` at 0x1444, `ld` at 0x1500.
  6 such `ld` accesses load 8 bytes from abs 0xa800000000001020, including `ld` at 0x13d8, `ld` at 0x1458, `ld` at 0x1514.
  4 such `lw` accesses load 4 bytes from [0xa800000000001020]:8 +0x0, including `lw` at 0x13e4, `lw` at 0x1464, `lw` at 0x1520.
  6 such `ld` accesses load 8 bytes from [0xa800000000001020]:8 +0x80, including `ld` at 0x13f0, `ld` at 0x1470, `ld` at 0x152c.
  3 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x40, including `ld` at 0x13fc, `ld` at 0x140c, `ld` at 0x1538.
  2 such `sw` accesses store 4 bytes to [a0+64]:8 +0x0, including `sw` at 0x1408, `sw` at 0x153c.
  2 such `lw` accesses load 4 bytes from [a0+64]:8 +0x0, including `lw` at 0x1410, `lw` at 0x15f4.
  The `ld` at 0x14a0 loads 8 bytes from a0 (arg0 at entry) +0x48.
  The `lbu` at 0x14a4 loads 1 byte from [a0+72]:8 +0x3.
  The `sb` at 0x14dc stores 1 byte to [a0+72]:8 +0x3.
  The `sw` at 0x15d4 stores 4 bytes to a0 (arg0 at entry) +0x80.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x84, including `sw` at 0x15dc, `sw` at 0x1620.
  The `lw` at 0x15e8 loads 4 bytes from a0 (arg0 at entry) +0x88.
  The `jal` at 0x134c calls set_baud_ti with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x1484 calls (unknown callee) with a0=0x1, a1=[[0xa800000000001020]:8], a2=[[0xa800000000001020]:8+128]:8, a3=[sym(.sbss)], a7=0x40000000.
  The `jal` at 0x148c calls splx with a0=[sym(.sbss)], a1=?, a2=?, a3=?.
  The `jalr` at 0x158c calls (unknown callee) with a0=0x1, a1=0xfffffffffeeddead, a2=[[0xa800000000001020]:8+128]:8, a3=a1 at entry (arg1).
  The `jal` at 0x1594 calls splx with a0=[sym(.sbss)], a1=?, a2=?, a3=?.
  The `jal` at 0x15e4 calls ioc3_rx_timeout with a0=a0 at entry (arg0), a1=[a0+136], a2=?, a3=a1 at entry (arg1), a6=0xa.
  The `jal` at 0x164c calls spl7 with a0=[a0+148], a1=([a0+148] << 0x23), a2=0xa800000000001020, a3=[0xa800000000001000]:8, a4=[[0xa800000000001020]:8], a5=0xfffffffffeeddead, a6=[[0xa800000000001020]:8+128]:8.
  The `jalr` at 0x1664 calls (unknown callee) with a0=0x0, a1=?, a2=?, a3=?.
  The `jal` at 0x167c calls spl7 with a0=[a0+148], a1=?, a2=[a0+72]:8, a3=?, a4=[sym(the_console_port)]:8, a5=[0xa800000000001000]:8, a6=[[0xa800000000001020]:8], a7=0xfffffffffeeddead.
  The `jalr` at 0x1690 calls (unknown callee) with a0=0x0, a1=?, a2=?, a3=?.
  The `beq` branch at 0x1354 targets 0x1370, is taken when v0(=ret(set_baud_ti)) == 0, and falls through when v0(=ret(set_baud_ti)) != 0.
  The `beq` branch at 0x1374 targets 0x13a4, is taken when s1(=a2) == at(=0x5), and falls through when s1(=a2) != at(=0x5).
  The `beq` branch at 0x137c targets 0x1624, is taken when s1(=a2) == v0(=0x6), and falls through when s1(=a2) != v0(=0x6).
  The `beq` branch at 0x1384 targets 0x162c, is taken when s1(=a2) == v1(=0x7), and falls through when s1(=a2) != v1(=0x7).
  The `beq` branch at 0x138c targets 0x139c, is taken when s1(=a2) == a0(=0x8), and falls through when s1(=a2) != a0(=0x8).
  The `beq` branch at 0x1394 targets 0x135c and is always taken.
  The `beq` branch at 0x139c targets 0x13a8 and is always taken.
  The `bgez` branch at 0x13b0 targets 0x14a0, is taken when a1(=([a0+148] << 0x23)) >= 0 (signed), and falls through when a1(=([a0+148] << 0x23)) < 0 (signed).
  The `bne` branch at 0x13b8 targets 0x13fc, is taken when a2(=[sym(the_console_port)]:8) != s0(=a0), and falls through when a2(=[sym(the_console_port)]:8) == s0(=a0).
  The `bne` branch at 0x13d4 targets 0x13fc, is taken when a3(=[0xa800000000001000]:8) != a4(=0x53435241), and falls through when a3(=[0xa800000000001000]:8) == a4(=0x53435241).
  The `beq` branch at 0x13dc targets 0x13fc, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x13e8 targets 0x13fc, is taken when a4(=[[0xa800000000001020]:8]) != a5(=0xfffffffffeeddead), and falls through when a4(=[[0xa800000000001020]:8]) == a5(=0xfffffffffeeddead).
  The `bne` branch at 0x13f4 targets 0x164c, is taken when a6(=[[0xa800000000001020]:8+128]:8) != 0, and falls through when a6(=[[0xa800000000001020]:8+128]:8) == 0.
  The `bltz` branch at 0x1418 targets 0x1430, is taken when a7(=([[a0+64]:8] << 0x21)) < 0 (signed), and falls through when a7(=([[a0+64]:8] << 0x21)) >= 0 (signed).
  The `beq` branch at 0x1428 targets 0x16a8 and is always taken.
  The `bne` branch at 0x1438 targets 0x1498, is taken when a1(=[sym(the_console_port)]:8) != s0(=a0), and falls through when a1(=[sym(the_console_port)]:8) == s0(=a0).
  The `bne` branch at 0x1454 targets 0x1498, is taken when v1(=[0xa800000000001000]:8) != a1(=0x53435241), and falls through when v1(=[0xa800000000001000]:8) == a1(=0x53435241).
  The `beq` branch at 0x145c targets 0x1498, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x1468 targets 0x1498, is taken when a1(=[[0xa800000000001020]:8]) != a2(=0xfffffffffeeddead), and falls through when a1(=[[0xa800000000001020]:8]) == a2(=0xfffffffffeeddead).
  The `beq` branch at 0x1474 targets 0x1498, is taken when a2(=[[0xa800000000001020]:8+128]:8) == 0, and falls through when a2(=[[0xa800000000001020]:8+128]:8) != 0.
  The `beq` branch at 0x1498 targets 0x1644, is taken when a0(=one of 0x0, 0x1) == 0, and falls through when a0(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x14b4 targets 0x14cc, is taken when v1(=a4) == 0, and falls through when v1(=a4) != 0.
  The `beq` branch at 0x14c4 targets 0x1634, is taken when a0(=a5) == 0, and falls through when a0(=a5) != 0.
  The `beq` branch at 0x14d0 targets 0x14dc, is taken when a1(=a3) == 0, and falls through when a1(=a3) != 0.
  The `beq` branch at 0x14ec targets 0x159c, is taken when (a3(=0x10000000) & a0(=[a0+148])) == 0, and falls through when (a3(=0x10000000) & a0(=[a0+148])) != 0.
  The `bne` branch at 0x14f4 targets 0x1538, is taken when a4(=[sym(the_console_port)]:8) != s0(=a0), and falls through when a4(=[sym(the_console_port)]:8) == s0(=a0).
  The `bne` branch at 0x1510 targets 0x1538, is taken when a5(=[0xa800000000001000]:8) != a6(=0x53435241), and falls through when a5(=[0xa800000000001000]:8) == a6(=0x53435241).
  The `beq` branch at 0x1518 targets 0x1538, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x1524 targets 0x1538, is taken when a6(=[[0xa800000000001020]:8]) != a7(=0xfffffffffeeddead), and falls through when a6(=[[0xa800000000001020]:8]) == a7(=0xfffffffffeeddead).
  The `bne` branch at 0x1530 targets 0x167c, is taken when t0(=[[0xa800000000001020]:8+128]:8) != 0, and falls through when t0(=[[0xa800000000001020]:8+128]:8) == 0.
  The `bne` branch at 0x1544 targets 0x159c, is taken when t1(=[sym(the_console_port)]:8) != s0(=a0), and falls through when t1(=[sym(the_console_port)]:8) == s0(=a0).
  The `bne` branch at 0x1560 targets 0x159c, is taken when v1(=[0xa800000000001000]:8) != a0(=0x53435241), and falls through when v1(=[0xa800000000001000]:8) == a0(=0x53435241).
  The `beq` branch at 0x1568 targets 0x15a0, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x1574 targets 0x15a0, is taken when a0(=[[0xa800000000001020]:8]) != a1(=0xfffffffffeeddead), and falls through when a0(=[[0xa800000000001020]:8]) == a1(=0xfffffffffeeddead).
  The `beq` branch at 0x1580 targets 0x15a0, is taken when a2(=[[0xa800000000001020]:8+128]:8) == 0, and falls through when a2(=[[0xa800000000001020]:8+128]:8) != 0.
  The `beq` branch at 0x15d8 targets 0x1618, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0x15ec targets 0x135c and is always taken.
  The `bne` branch at 0x1600 targets 0x1430, is taken when (t0(=[[a0+64]:8]) & a7(=0x40000000)) != 0, and falls through when (t0(=[[a0+64]:8]) & a7(=0x40000000)) == 0.
  The `beq` branch at 0x1608 targets 0x15f4, is taken when t1(?) == 0, and falls through when t1(?) != 0.
  The `beq` branch at 0x1610 targets 0x1434 and is always taken.
  The `beq` branch at 0x161c targets 0x15e0 and is always taken.
  The `beq` branch at 0x1624 targets 0x13a8 and is always taken.
  The `beq` branch at 0x162c targets 0x13a8 and is always taken.
  The `bne` branch at 0x1634 targets 0x14d8, is taken when t3(=a3) != 0, and falls through when t3(=a3) == 0.
  The `beq` branch at 0x163c targets 0x14dc and is always taken.
  The `beq` branch at 0x1644 targets 0x135c and is always taken.
  The `beq` branch at 0x1674 targets 0x13fc and is always taken.
  The `beq` branch at 0x16a0 targets 0x1538 and is always taken.
  The `beq` branch at 0x16b0 targets 0x1608 and is always taken.
  The return at 0x1368 has v0 = one of -0x1, 0x0, 0x1.

- `ioc3_enable_hfc` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc3.o)` at 0x16b8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc3.o)`.
  Range: 0x16b8-0x17dc (292 bytes).
  It occupies 292 bytes.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x94, including `lw` at 0x16bc, `lw` at 0x17cc.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x94, including `sw` at 0x16d4, `sw` at 0x17a4.
  2 such `ld` accesses load 8 bytes from abs 0xa800000000001000, including `ld` at 0x16f0, `ld` at 0x1744.
  3 such `ld` accesses load 8 bytes from abs 0xa800000000001020, including `ld` at 0x16f4, `ld` at 0x1738, `ld` at 0x17b4.
  2 such `lw` accesses load 4 bytes from [0xa800000000001020]:8 +0x0, including `lw` at 0x1708, `lw` at 0x1758.
  3 such `ld` accesses load 8 bytes from [0xa800000000001020]:8 +0x80, including `ld` at 0x1714, `ld` at 0x1764, `ld` at 0x17b8.
  The `ld` at 0x1720 loads 8 bytes from a0 (arg0 at entry) +0x40.
  The `sw` at 0x1728 stores 4 bytes to [a0+64]:8 +0x0.
  The `jalr` at 0x1774 calls (unknown callee) with a0=0x1, a1=[sym(the_console_port)]:8, a2=?, a3=[[0xa800000000001020]:8+128]:8, a5=0xa800000000001020, a6=[a0+64]:8, a7=[[0xa800000000001020]:8].
  The `jal` at 0x177c calls splx with a0=[sym(.sbss)], a1=?, a2=?, a3=?.
  The `jal` at 0x17a8 calls spl7 with a0=[0xa800000000001000]:8, a1=[sym(the_console_port)]:8, a2=a2 at entry (arg2), a3=0x53435241, a5=[[0xa800000000001020]:8], a6=0xfffffffffeeddead, a7=[[0xa800000000001020]:8+128]:8.
  The `jalr` at 0x17c0 calls (unknown callee) with a0=0x0, a1=?, a2=?, a3=?.
  The `beq` branch at 0x16c8 targets 0x1798, is taken when a1 == 0, and falls through when a1 != 0.
  The `bne` branch at 0x16ec targets 0x1720, is taken when a1(=[sym(the_console_port)]:8) != s0(=a0), and falls through when a1(=[sym(the_console_port)]:8) == s0(=a0).
  The `bne` branch at 0x16f8 targets 0x1720, is taken when a0(=[0xa800000000001000]:8) != a3(=0x53435241), and falls through when a0(=[0xa800000000001000]:8) == a3(=0x53435241).
  The `beq` branch at 0x1700 targets 0x1720, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x170c targets 0x1720, is taken when a5(=[[0xa800000000001020]:8]) != a6(=0xfffffffffeeddead), and falls through when a5(=[[0xa800000000001020]:8]) == a6(=0xfffffffffeeddead).
  The `bne` branch at 0x1718 targets 0x17a8, is taken when a7(=[[0xa800000000001020]:8+128]:8) != 0, and falls through when a7(=[[0xa800000000001020]:8+128]:8) == 0.
  The `bne` branch at 0x1740 targets 0x1788, is taken when a1(=[sym(the_console_port)]:8) != s0(=a0), and falls through when a1(=[sym(the_console_port)]:8) == s0(=a0).
  The `bne` branch at 0x1748 targets 0x1788, is taken when a0(=[0xa800000000001000]:8) != a3(=0x53435241), and falls through when a0(=[0xa800000000001000]:8) == a3(=0x53435241).
  The `beq` branch at 0x1750 targets 0x1788, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x175c targets 0x1788, is taken when a7(=[[0xa800000000001020]:8]) != t0(=0xfffffffffeeddead), and falls through when a7(=[[0xa800000000001020]:8]) == t0(=0xfffffffffeeddead).
  The `beq` branch at 0x1768 targets 0x1788, is taken when a3(=[[0xa800000000001020]:8+128]:8) == 0, and falls through when a3(=[[0xa800000000001020]:8+128]:8) != 0.
  The `beq` branch at 0x17a0 targets 0x16d8 and is always taken.
  The `beq` branch at 0x17d4 targets 0x1720 and is always taken.
  The return at 0x1790 has v0 = 0x0.

- `ioc3_set_extclk` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc3.o)` at 0x17dc (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc3.o)`.
  Range: 0x17dc-0x17e4 (8 bytes).
  It occupies 8 bytes.
  The return at 0x17dc has v0 = a1.

- `do_ioc3_write` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc3.o)` at 0x17e4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc3.o)`.
  Range: 0x17e4-0x1a60 (636 bytes).
  It occupies 636 bytes.
  3 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x40, including `ld` at 0x17e4, `ld` at 0x1960, `ld` at 0x19d0.
  The `ld` at 0x17e8 loads 8 bytes from a0 (arg0 at entry) +0x68.
  The `lw` at 0x17ec loads 4 bytes from [a0+64]:8 +0x8.
  The `ld` at 0x17f0 loads 8 bytes from a0 (arg0 at entry) +0x70.
  The `lw` at 0x1800 loads 4 bytes from a0 (arg0 at entry) +0x98.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x78, including `lw` at 0x183c, `lw` at 0x18c4, `lw` at 0x1a28.
  The `sw` at 0x1854 stores 4 bytes to a0 (arg0 at entry) +0x98.
  3 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x1880, `lbu` at 0x18a8, `lbu` at 0x1a10.
  5 such `sb` accesses store 1 byte to ?, including `sb` at 0x1888, `sb` at 0x1894, `sb` at 0x18b0.
  The `sw` at 0x18f4 stores 4 bytes to ?.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x94, including `lw` at 0x1908, `lw` at 0x1a50.
  The `sw` at 0x1918 stores 4 bytes to a0 (arg0 at entry) +0x94.
  2 such `ld` accesses load 8 bytes from abs 0xa800000000001000, including `ld` at 0x1930, `ld` at 0x197c.
  3 such `ld` accesses load 8 bytes from abs 0xa800000000001020, including `ld` at 0x193c, `ld` at 0x1988, `ld` at 0x1a38.
  2 such `lw` accesses load 4 bytes from [0xa800000000001020]:8 +0x0, including `lw` at 0x1948, `lw` at 0x1994.
  3 such `ld` accesses load 8 bytes from [0xa800000000001020]:8 +0x80, including `ld` at 0x1954, `ld` at 0x19a4, `ld` at 0x1a3c.
  The `sw` at 0x1964 stores 4 bytes to [a0+64]:8 +0x0.
  The `sw` at 0x19d8 stores 4 bytes to [a0+64]:8 +0x4.
  The `lw` at 0x19e4 loads 4 bytes from [a0+112]:8 +0x8.
  The `lw` at 0x19f0 loads 4 bytes from a0 (arg0 at entry) +0x84.
  The `sw` at 0x1a0c stores 4 bytes to a0 (arg0 at entry) +0x78.
  The `jalr` at 0x19b8 calls (unknown callee) with a0=0x1, a1=[[0xa800000000001020]:8+128]:8, a2=[sym(.sbss)], a3=?.
  The `jal` at 0x19c0 calls splx with a0=[sym(.sbss)], a1=?, a2=?, a3=?.
  The `jal` at 0x19e0 calls enable_intrs with a0=a0 at entry (arg0), a1=[[a0+112]:8+8], a2=?, a3=[a0+64]:8.
  The `jal` at 0x1a2c calls spl7 with a0=(0x10000000 | [a0+148]), a1=0xa800000000001020, a2=0xfffffffffeeddead, a3=[[0xa800000000001020]:8+128]:8, a6=([a0+148] << 0x23), a7=0x40.
  The `jalr` at 0x1a44 calls (unknown callee) with a0=0x0, a1=?, a2=?, a3=?.
  The `beq` branch at 0x1820 targets 0x1838, is taken when a6(?) == s2(=[a0+152]), and falls through when a6(?) != s2(=[a0+152]).
  The `blez` branch at 0x1828 targets 0x1a20, is taken when a2 <= 0 (signed), and falls through when a2 > 0 (signed).
  The `beq` branch at 0x1830 targets 0x18e8 and is always taken.
  The `beq` branch at 0x1844 targets 0x19d0, is taken when (a7(=[a0+120]) & 0x10) == 0, and falls through when (a7(=[a0+120]) & 0x10) != 0.
  The `blez` branch at 0x1868 targets 0x18c4, is taken when a2(?) <= 0 (signed), and falls through when a2(?) > 0 (signed).
  The `beq` branch at 0x1898 targets 0x18c4, is taken when v0(?) >= 0x4 (signed), and falls through when v0(?) < 0x4 (signed).
  The `blez` branch at 0x18a0 targets 0x18c4, is taken when a2(?) <= 0 (signed), and falls through when a2(?) > 0 (signed).
  The `bne` branch at 0x18bc targets 0x1868, is taken when a4(?) != 0, and falls through when a4(?) == 0.
  The `beq` branch at 0x18cc targets 0x19f0, is taken when (v0(=[a0+120]) & 0x4) == 0, and falls through when (v0(=[a0+120]) & 0x4) != 0.
  The `beq` branch at 0x18d8 targets 0x1900, is taken when a6(?) == s2(?), and falls through when a6(?) != s2(?).
  The `blez` branch at 0x18e0 targets 0x1900, is taken when a2(?) <= 0 (signed), and falls through when a2(?) > 0 (signed).
  The `blez` branch at 0x18f0 targets 0x18c4, is taken when a2(?) <= 0 (signed), and falls through when a2(?) > 0 (signed).
  The `beq` branch at 0x18f8 targets 0x1870 and is always taken.
  The `blez` branch at 0x1900 targets 0x183c, is taken when s0(?) <= 0 (signed), and falls through when s0(?) > 0 (signed).
  The `bltz` branch at 0x1910 targets 0x183c, is taken when a6(=([a0+148] << 0x23)) < 0 (signed), and falls through when a6(=([a0+148] << 0x23)) >= 0 (signed).
  The `bne` branch at 0x192c targets 0x1960, is taken when a3(=[sym(the_console_port)]:8) != s1(=a0), and falls through when a3(=[sym(the_console_port)]:8) == s1(=a0).
  The `bne` branch at 0x1934 targets 0x1960, is taken when a1(=[0xa800000000001000]:8) != v0(=0x53435241), and falls through when a1(=[0xa800000000001000]:8) == v0(=0x53435241).
  The `beq` branch at 0x1940 targets 0x1960, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x194c targets 0x1960, is taken when v1(=[[0xa800000000001020]:8]) != a2(=0xfffffffffeeddead), and falls through when v1(=[[0xa800000000001020]:8]) == a2(=0xfffffffffeeddead).
  The `bne` branch at 0x1958 targets 0x1a2c, is taken when a3(=[[0xa800000000001020]:8+128]:8) != 0, and falls through when a3(=[[0xa800000000001020]:8+128]:8) == 0.
  The `bne` branch at 0x1978 targets 0x183c, is taken when v1(=[sym(the_console_port)]:8) != s1(=a0), and falls through when v1(=[sym(the_console_port)]:8) == s1(=a0).
  The `bne` branch at 0x1980 targets 0x183c, is taken when v0(=[0xa800000000001000]:8) != a1(=0x53435241), and falls through when v0(=[0xa800000000001000]:8) == a1(=0x53435241).
  The `beq` branch at 0x198c targets 0x183c, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x199c targets 0x183c, is taken when v1(=[[0xa800000000001020]:8]) != a0(=0xfffffffffeeddead), and falls through when v1(=[[0xa800000000001020]:8]) == a0(=0xfffffffffeeddead).
  The `beq` branch at 0x19a8 targets 0x183c, is taken when a1(=[[0xa800000000001020]:8+128]:8) == 0, and falls through when a1(=[[0xa800000000001020]:8+128]:8) != 0.
  The `beq` branch at 0x19c8 targets 0x183c and is always taken.
  The `blez` branch at 0x19d4 targets 0x1848, is taken when s0(?) <= 0 (signed), and falls through when s0(?) > 0 (signed).
  The `beq` branch at 0x19e8 targets 0x184c and is always taken.
  The `bne` branch at 0x1a04 targets 0x18d4, is taken when a4(=([a0+132] << 0x3)) < a5(?) (signed), and falls through when a4(=([a0+132] << 0x3)) >= a5(?) (signed).
  The `beq` branch at 0x1a18 targets 0x18d4 and is always taken.
  The `beq` branch at 0x1a24 targets 0x1840 and is always taken.
  The `beq` branch at 0x1a58 targets 0x1960 and is always taken.
  The return at 0x1860 has v0 = ?.

- `ioc3_write` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc3.o)` at 0x1a60 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc3.o)`.
  Range: 0x1a60-0x1a7c (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x1a68 calls do_ioc3_write with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x1a74 has v0 = ret(do_ioc3_write).

- `ioc3_sync_write` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc3.o)` at 0x1a7c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc3.o)`.
  Range: 0x1a7c-0x1ad8 (92 bytes).
  It occupies 92 bytes.
  The `lw` at 0x1aa8 loads 4 bytes from a0 (arg0 at entry) +0x78.
  The `jal` at 0x1a90 calls do_ioc3_write with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1ab8 calls ioc3_enable_tx with a0=a0 at entry (arg0), a1=0x1, a2=?, a3=?.
  The `blez` branch at 0x1a98 targets 0x1ac0, is taken when s3(=a2) <= 0 (signed), and falls through when s3(=a2) > 0 (signed).
  The `bne` branch at 0x1aa0 targets 0x1ac0, is taken when v0(=ret(do_ioc3_write)) != 0, and falls through when v0(=ret(do_ioc3_write)) == 0.
  The `beq` branch at 0x1ab0 targets 0x1ac0, is taken when (at(=[a0+120]) & 0x10) == 0, and falls through when (at(=[a0+120]) & 0x10) != 0.
  The return at 0x1ad0 has v0 = ret(do_ioc3_write).

- `ioc3_wrflush` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc3.o)` at 0x1ad8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc3.o)`.
  Range: 0x1ad8-0x1b9c (196 bytes).
  It occupies 196 bytes.
  3 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x38, including `ld` at 0x1ad8, `ld` at 0x1b14, `ld` at 0x1b5c.
  3 such `lw` accesses load 4 bytes from [a0+56]:8 +0x1c, including `lw` at 0x1adc, `lw` at 0x1b18, `lw` at 0x1b60.
  3 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x40, including `ld` at 0x1af8, `ld` at 0x1b50, `ld` at 0x1b78.
  2 such `lw` accesses load 4 bytes from [a0+64]:8 +0x0, including `lw` at 0x1afc, `lw` at 0x1b7c.
  The `lw` at 0x1b34 loads 4 bytes from a0 (arg0 at entry) +0x78.
  The `jal` at 0x1b44 calls ioc3_enable_tx with a0=a0 at entry (arg0), a1=0x1, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1b70 calls us_delay with a0=0x5, a1=?, a2=one of 0x10000000, 0x50000000, a3=?.
  The `beq` branch at 0x1af0 targets 0x1b34, is taken when (at(=[[a0+56]:8+28]) & 0x1) == 0, and falls through when (at(=[[a0+56]:8+28]) & 0x1) != 0.
  The `bne` branch at 0x1b0c targets 0x1b28, is taken when a0(=0x10000000) != v0(?), and falls through when a0(=0x10000000) == v0(?).
  The `beq` branch at 0x1b20 targets 0x1b54, is taken when (v1(=[[a0+56]:8+28]) & 0x1) == 0, and falls through when (v1(=[[a0+56]:8+28]) & 0x1) != 0.
  The `beq` branch at 0x1b3c targets 0x1af8, is taken when (a0(=[a0+120]) & 0x10) == 0, and falls through when (a0(=[a0+120]) & 0x10) != 0.
  The `beq` branch at 0x1b4c targets 0x1afc and is always taken.
  The `beq` branch at 0x1b54 targets 0x1b70 and is always taken.
  The `bne` branch at 0x1b68 targets 0x1b94, is taken when (a1(=[[a0+56]:8+28]) & 0x1) != 0, and falls through when (a1(=[[a0+56]:8+28]) & 0x1) == 0.
  The `beq` branch at 0x1b8c targets 0x1b5c, is taken when a2(=0x10000000) == a3(?), and falls through when a2(=0x10000000) != a3(?).
  The `beq` branch at 0x1b94 targets 0x1b28 and is always taken.
  The return at 0x1b2c has v0 = one of ?, ret(us_delay).

- `ioc3_break` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc3.o)` at 0x1b9c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc3.o)`.
  Range: 0x1b9c-0x1e44 (680 bytes).
  It occupies 680 bytes.
  4 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x94, including `lw` at 0x1b9c, `lw` at 0x1cc8, `lw` at 0x1df4.
  4 such `ld` accesses load 8 bytes from abs 0xa800000000001000, including `ld` at 0x1bd0, `ld` at 0x1c5c, `ld` at 0x1ce4.
  6 such `ld` accesses load 8 bytes from abs 0xa800000000001020, including `ld` at 0x1be4, `ld` at 0x1c60, `ld` at 0x1cf8.
  4 such `lw` accesses load 4 bytes from [0xa800000000001020]:8 +0x0, including `lw` at 0x1bf0, `lw` at 0x1c74, `lw` at 0x1d04.
  6 such `ld` accesses load 8 bytes from [0xa800000000001020]:8 +0x80, including `ld` at 0x1bfc, `ld` at 0x1c80, `ld` at 0x1d10.
  3 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x40, including `ld` at 0x1c08, `ld` at 0x1c18, `ld` at 0x1d1c.
  2 such `sw` accesses store 4 bytes to [a0+64]:8 +0x0, including `sw` at 0x1c14, `sw` at 0x1d20.
  2 such `lw` accesses load 4 bytes from [a0+64]:8 +0x0, including `lw` at 0x1c1c, `lw` at 0x1d9c.
  The `ld` at 0x1cb4 loads 8 bytes from a0 (arg0 at entry) +0x48.
  The `lbu` at 0x1cbc loads 1 byte from [a0+72]:8 +0x3.
  2 such `sb` accesses store 1 byte to [a0+72]:8 +0x3, including `sb` at 0x1cc4, `sb` at 0x1dcc.
  The `jalr` at 0x1c94 calls (unknown callee) with a0=0x1, a1=a1 at entry (arg1), a2=[[0xa800000000001020]:8], a3=0xfffffffffeeddead, a4=[[0xa800000000001020]:8+128]:8, a5=[sym(.sbss)], a6=0x10000000, a7=[sym(the_console_port)]:8.
  The `jal` at 0x1c9c calls splx with a0=[sym(.sbss)], a1=?, a2=?, a3=?.
  The `jalr` at 0x1d74 calls (unknown callee) with a0=0x1, a1=?, a2=?, a3=?, a4=[[0xa800000000001020]:8+128]:8.
  The `jal` at 0x1d7c calls splx with a0=[sym(.sbss)], a1=?, a2=?, a3=?.
  The `jal` at 0x1dd8 calls spl7 with a0=[a0+72]:8, a1=a1 at entry (arg1), a2=?, a3=?, a4=[a0+148], a6=0x10000000.
  The `jalr` at 0x1dec calls (unknown callee) with a0=0x0, a1=?, a2=?, a3=?, a5=[[0xa800000000001020]:8+128]:8.
  The `jal` at 0x1e04 calls spl7 with a0=[[0xa800000000001020]:8], a1=a1 at entry (arg1), a2=0xfffffffffeeddead, a3=[[0xa800000000001020]:8+128]:8, a4=[a0+148], a6=0x10000000.
  The `jalr` at 0x1e18 calls (unknown callee) with a0=0x0, a1=?, a2=?, a3=?, a7=[[0xa800000000001020]:8+128]:8.
  The `bgez` branch at 0x1bb8 targets 0x1cb4, is taken when at(=([a0+148] << 0x23)) >= 0 (signed), and falls through when at(=([a0+148] << 0x23)) < 0 (signed).
  The `bne` branch at 0x1bc4 targets 0x1c08, is taken when v0(=[sym(the_console_port)]:8) != a0, and falls through when v0(=[sym(the_console_port)]:8) == a0.
  The `bne` branch at 0x1be0 targets 0x1c08, is taken when v1(=[0xa800000000001000]:8) != a0(=0x53435241), and falls through when v1(=[0xa800000000001000]:8) == a0(=0x53435241).
  The `beq` branch at 0x1be8 targets 0x1c08, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x1bf4 targets 0x1c08, is taken when a0(=[[0xa800000000001020]:8]) != a2(=0xfffffffffeeddead), and falls through when a0(=[[0xa800000000001020]:8]) == a2(=0xfffffffffeeddead).
  The `bne` branch at 0x1c00 targets 0x1e04, is taken when a3(=[[0xa800000000001020]:8+128]:8) != 0, and falls through when a3(=[[0xa800000000001020]:8+128]:8) == 0.
  The `bltz` branch at 0x1c30 targets 0x1c40, is taken when t0(=([[a0+64]:8] << 0x21)) < 0 (signed), and falls through when t0(=([[a0+64]:8] << 0x21)) >= 0 (signed).
  The `beq` branch at 0x1c38 targets 0x1e38 and is always taken.
  The `bne` branch at 0x1c58 targets 0x1cac, is taken when a7(=[sym(the_console_port)]:8) != s0(=a0), and falls through when a7(=[sym(the_console_port)]:8) == s0(=a0).
  The `bne` branch at 0x1c64 targets 0x1cac, is taken when a4(=[0xa800000000001000]:8) != a0(=0x53435241), and falls through when a4(=[0xa800000000001000]:8) == a0(=0x53435241).
  The `beq` branch at 0x1c6c targets 0x1cac, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x1c78 targets 0x1cac, is taken when a2(=[[0xa800000000001020]:8]) != a3(=0xfffffffffeeddead), and falls through when a2(=[[0xa800000000001020]:8]) == a3(=0xfffffffffeeddead).
  The `beq` branch at 0x1c84 targets 0x1cac, is taken when a4(=[[0xa800000000001020]:8+128]:8) == 0, and falls through when a4(=[[0xa800000000001020]:8+128]:8) != 0.
  The `beq` branch at 0x1cac targets 0x1dd0, is taken when s1(=one of 0x0, 0x1) == 0, and falls through when s1(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x1cb8 targets 0x1dc0, is taken when a1 == 0, and falls through when a1 != 0.
  The `beq` branch at 0x1cd0 targets 0x1d84, is taken when (a6(=0x10000000) & a4(=[a0+148])) == 0, and falls through when (a6(=0x10000000) & a4(=[a0+148])) != 0.
  The `bne` branch at 0x1cd8 targets 0x1d1c, is taken when t1(=[sym(the_console_port)]:8) != s0(=a0), and falls through when t1(=[sym(the_console_port)]:8) == s0(=a0).
  The `bne` branch at 0x1cf4 targets 0x1d1c, is taken when t2(=[0xa800000000001000]:8) != t3(=0x53435241), and falls through when t2(=[0xa800000000001000]:8) == t3(=0x53435241).
  The `beq` branch at 0x1cfc targets 0x1d1c, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x1d08 targets 0x1d1c, is taken when t3(=[[0xa800000000001020]:8]) != t8(=0xfffffffffeeddead), and falls through when t3(=[[0xa800000000001020]:8]) == t8(=0xfffffffffeeddead).
  The `bne` branch at 0x1d14 targets 0x1dd8, is taken when t9(=[[0xa800000000001020]:8+128]:8) != 0, and falls through when t9(=[[0xa800000000001020]:8+128]:8) == 0.
  The `bne` branch at 0x1d28 targets 0x1d88, is taken when ra(=[sym(the_console_port)]:8) != s0(=a0), and falls through when ra(=[sym(the_console_port)]:8) == s0(=a0).
  The `bne` branch at 0x1d40 targets 0x1d88, is taken when v0(=[0xa800000000001000]:8) != v1(=0x53435241), and falls through when v0(=[0xa800000000001000]:8) == v1(=0x53435241).
  The `beq` branch at 0x1d50 targets 0x1d84, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x1d5c targets 0x1d84, is taken when v1(=[[0xa800000000001020]:8]) != a0(=0xfffffffffeeddead), and falls through when v1(=[[0xa800000000001020]:8]) == a0(=0xfffffffffeeddead).
  The `beq` branch at 0x1d68 targets 0x1d88, is taken when a4(=[[0xa800000000001020]:8+128]:8) == 0, and falls through when a4(=[[0xa800000000001020]:8+128]:8) != 0.
  The `bne` branch at 0x1da8 targets 0x1c40, is taken when (a2(=[[a0+64]:8]) & a7(=0x40000000)) != 0, and falls through when (a2(=[[a0+64]:8]) & a7(=0x40000000)) == 0.
  The `beq` branch at 0x1db0 targets 0x1d9c, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0x1db8 targets 0x1c48 and is always taken.
  The `beq` branch at 0x1dc8 targets 0x1cc8 and is always taken.
  The `beq` branch at 0x1dd0 targets 0x1d88 and is always taken.
  The `beq` branch at 0x1dfc targets 0x1d1c and is always taken.
  The `beq` branch at 0x1e30 targets 0x1c08 and is always taken.
  The `beq` branch at 0x1e3c targets 0x1db0 and is always taken.
  The return at 0x1d94 has v0 = one of -0x1, 0x0.

- `ioc3_enable_tx` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc3.o)` at 0x1e44 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc3.o)`.
  Range: 0x1e44-0x2058 (532 bytes).
  It occupies 532 bytes.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x78, including `lw` at 0x1e50, `lw` at 0x1f1c.
  The `ld` at 0x1e58 loads 8 bytes from a0 (arg0 at entry) +0x70.
  2 such `ld` accesses load 8 bytes from abs 0xa800000000001000, including `ld` at 0x1e84, `ld` at 0x1f64.
  3 such `ld` accesses load 8 bytes from abs 0xa800000000001020, including `ld` at 0x1e88, `ld` at 0x1f68, `ld` at 0x2034.
  2 such `lw` accesses load 4 bytes from [0xa800000000001020]:8 +0x0, including `lw` at 0x1e9c, `lw` at 0x1f8c.
  3 such `ld` accesses load 8 bytes from [0xa800000000001020]:8 +0x80, including `ld` at 0x1ea8, `ld` at 0x1f98, `ld` at 0x2038.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x94, including `lw` at 0x1eb4, `lw` at 0x1f40.
  4 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x40, including `ld` at 0x1ec0, `ld` at 0x1ed0, `ld` at 0x1f58.
  2 such `sw` accesses store 4 bytes to [a0+64]:8 +0x0, including `sw` at 0x1ecc, `sw` at 0x1f5c.
  2 such `lw` accesses load 4 bytes from [a0+64]:8 +0x0, including `lw` at 0x1ed4, `lw` at 0x1f04.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x98, including `lw` at 0x1f20, `lw` at 0x2000.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x78, including `sw` at 0x1f2c, `sw` at 0x1fe8.
  2 such `sw` accesses store 4 bytes to [a0+64]:8 +0x4, including `sw` at 0x1f30, `sw` at 0x201c.
  2 such `lw` accesses load 4 bytes from [a0+112]:8 +0x8, including `lw` at 0x1f3c, `lw` at 0x1ff0.
  The `lw` at 0x1fe0 loads 4 bytes from [a0+64]:8 +0x8.
  The `jal` at 0x1f38 calls enable_intrs with a0=a0 at entry (arg0), a1=[[a0+112]:8+8], a2=?, a3=?, a4=[a0+64]:8.
  The `jalr` at 0x1fa8 calls (unknown callee) with a0=0x1, a1=[[0xa800000000001020]:8+128]:8, a2=[sym(the_console_port)]:8, a3=[[0xa800000000001020]:8], a4=0xfffffffffeeddead, a5=0xa800000000001000.
  The `jal` at 0x1fb0 calls splx with a0=[sym(.sbss)], a1=?, a2=?, a3=?.
  The `jal` at 0x1ff8 calls disable_intrs with a0=a0 at entry (arg0), a1=[[a0+112]:8+8], a2=?, a3=?, a4=[a0+64]:8, a6=([a0+120] | 0x10).
  The `jal` at 0x2028 calls spl7 with a0=0x53435241, a1=a1 at entry (arg1), a2=[[0xa800000000001020]:8], a3=0xfffffffffeeddead, a4=[[0xa800000000001020]:8+128]:8, a5=0xa800000000001020, a6=[sym(the_console_port)]:8.
  The `jalr` at 0x2040 calls (unknown callee) with a0=0x0, a1=?, a2=?, a3=?.
  The `beq` branch at 0x1e60 targets 0x1fd0, is taken when a1 == 0, and falls through when a1 != 0.
  The `beq` branch at 0x1e68 targets 0x1fd8, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `bne` branch at 0x1e80 targets 0x1eb4, is taken when a6(=[sym(the_console_port)]:8) != s0(=a0), and falls through when a6(=[sym(the_console_port)]:8) == s0(=a0).
  The `bne` branch at 0x1e8c targets 0x1eb4, is taken when a4(=[0xa800000000001000]:8) != a0(=0x53435241), and falls through when a4(=[0xa800000000001000]:8) == a0(=0x53435241).
  The `beq` branch at 0x1e94 targets 0x1eb4, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x1ea0 targets 0x1eb4, is taken when a2(=[[0xa800000000001020]:8]) != a3(=0xfffffffffeeddead), and falls through when a2(=[[0xa800000000001020]:8]) == a3(=0xfffffffffeeddead).
  The `bne` branch at 0x1eac targets 0x2028, is taken when a4(=[[0xa800000000001020]:8+128]:8) != 0, and falls through when a4(=[[0xa800000000001020]:8+128]:8) == 0.
  The `bgez` branch at 0x1ebc targets 0x1f18, is taken when a5(=([a0+148] << 0x23)) >= 0 (signed), and falls through when a5(=([a0+148] << 0x23)) < 0 (signed).
  The `bltz` branch at 0x1eec targets 0x1f18, is taken when t0(=([[a0+64]:8] << 0x21)) < 0 (signed), and falls through when t0(=([[a0+64]:8] << 0x21)) >= 0 (signed).
  The `bne` branch at 0x1efc targets 0x2020, is taken when t2(?) != 0, and falls through when t2(?) == 0.
  The `beq` branch at 0x1f10 targets 0x1efc, is taken when (t3(=[[a0+64]:8]) & a6(=0x40000000)) == 0, and falls through when (t3(=[[a0+64]:8]) & a6(=0x40000000)) != 0.
  The `beq` branch at 0x1f18 targets 0x1fe0, is taken when a1 == 0, and falls through when a1 != 0.
  The `beq` branch at 0x1f50 targets 0x1f60, is taken when (ra(=0x10000000) & a0(=[a0+148])) == 0, and falls through when (ra(=0x10000000) & a0(=[a0+148])) != 0.
  The `bne` branch at 0x1f74 targets 0x1fb8, is taken when a2(=[sym(the_console_port)]:8) != s0(=a0), and falls through when a2(=[sym(the_console_port)]:8) == s0(=a0).
  The `bne` branch at 0x1f7c targets 0x1fb8, is taken when a1(=[0xa800000000001000]:8) != a0(=0x53435241), and falls through when a1(=[0xa800000000001000]:8) == a0(=0x53435241).
  The `beq` branch at 0x1f84 targets 0x1fb8, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x1f90 targets 0x1fb8, is taken when a3(=[[0xa800000000001020]:8]) != a4(=0xfffffffffeeddead), and falls through when a3(=[[0xa800000000001020]:8]) == a4(=0xfffffffffeeddead).
  The `beq` branch at 0x1f9c targets 0x1fbc, is taken when a1(=[[0xa800000000001020]:8+128]:8) == 0, and falls through when a1(=[[0xa800000000001020]:8+128]:8) != 0.
  The `beq` branch at 0x1fd0 targets 0x1e70, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x1fd8 targets 0x1fbc and is always taken.
  The `beq` branch at 0x200c targets 0x1f40, is taken when a7(=[a0+152]) == v0(?), and falls through when a7(=[a0+152]) != v0(?).
  The `beq` branch at 0x2018 targets 0x1f40 and is always taken.
  The `beq` branch at 0x2020 targets 0x1fc0 and is always taken.
  The `beq` branch at 0x2050 targets 0x1eb4 and is always taken.
  The return at 0x1fc8 has v0 = one of -0x1, 0x0.

- `ioc3_notification` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc3.o)` at 0x2780 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc3.o)`.
  Range: 0x2780-0x2980 (512 bytes).
  It occupies 512 bytes.
  The `ld` at 0x2788 loads 8 bytes from a0 (arg0 at entry) +0x70.
  The `lw` at 0x27ac loads 4 bytes from [a0+112]:8 +0x10.
  The `lw` at 0x27b0 loads 4 bytes from [a0+112]:8 +0xc.
  The `lw` at 0x27c4 loads 4 bytes from [a0+112]:8 +0x14.
  The `lw` at 0x27d8 loads 4 bytes from [a0+112]:8 +0x0.
  The `lw` at 0x27f0 loads 4 bytes from [a0+112]:8 +0x4.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x94, including `lw` at 0x2804, `lw` at 0x290c, `lw` at 0x2974.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x8c, including `lw` at 0x2808, `lw` at 0x2914.
  4 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x94, including `sw` at 0x2810, `sw` at 0x282c, `sw` at 0x2920.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x8c, including `sw` at 0x2818, `sw` at 0x292c.
  2 such `ld` accesses load 8 bytes from abs 0xa800000000001000, including `ld` at 0x2848, `ld` at 0x289c.
  3 such `ld` accesses load 8 bytes from abs 0xa800000000001020, including `ld` at 0x284c, `ld` at 0x2890, `ld` at 0x2960.
  2 such `lw` accesses load 4 bytes from [0xa800000000001020]:8 +0x0, including `lw` at 0x2860, `lw` at 0x28b0.
  3 such `ld` accesses load 8 bytes from [0xa800000000001020]:8 +0x80, including `ld` at 0x286c, `ld` at 0x28bc, `ld` at 0x2964.
  The `ld` at 0x2878 loads 8 bytes from a0 (arg0 at entry) +0x40.
  The `sw` at 0x2880 stores 4 bytes to [a0+64]:8 +0x0.
  The `lw` at 0x2930 loads 4 bytes from a0 (arg0 at entry) +0x90.
  The `lw` at 0x2934 loads 4 bytes from [a0+112]:8 +0x8.
  The `jal` at 0x27fc calls enable_intrs with a0=a0 at entry (arg0), a1=?, a2=a2 at entry (arg2), a3=?.
  The `jalr` at 0x28cc calls (unknown callee) with a0=0x1, a1=[[0xa800000000001020]:8+128]:8, a2=0x53435241, a3=[sym(the_console_port)]:8, a4=[[0xa800000000001020]:8], a5=0xfffffffffeeddead.
  The `jal` at 0x28d4 calls splx with a0=[sym(.sbss)], a1=?, a2=?, a3=?.
  The `jal` at 0x2904 calls disable_intrs with a0=a0 at entry (arg0), a1=?, a2=a2 at entry (arg2), a3=?.
  The `jal` at 0x2958 calls spl7 with a0=?, a1=0x53435241, a2=[[0xa800000000001020]:8], a3=0xfffffffffeeddead, a4=[[0xa800000000001020]:8+128]:8.
  The `jalr` at 0x296c calls (unknown callee) with a0=0x0, a1=?, a2=?, a3=?, a5=[[0xa800000000001020]:8+128]:8.
  The `beq` branch at 0x27a4 targets 0x27b8, is taken when (a1 & 0x1) == 0, and falls through when (a1 & 0x1) != 0.
  The `beq` branch at 0x27bc targets 0x27d0, is taken when (s1(=a1) & 0x2) == 0, and falls through when (s1(=a1) & 0x2) != 0.
  The `beq` branch at 0x27d0 targets 0x2950, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `beq` branch at 0x27e8 targets 0x28fc, is taken when (s1(=a1) & 0x80) == 0, and falls through when (s1(=a1) & 0x80) != 0.
  The `beq` branch at 0x27f4 targets 0x2904, is taken when a2 == 0, and falls through when a2 != 0.
  The `beq` branch at 0x2820 targets 0x2930, is taken when (v0(?) & 0x41) == 0, and falls through when (v0(?) & 0x41) != 0.
  The `bne` branch at 0x2844 targets 0x2878, is taken when a3(=[sym(the_console_port)]:8) != s0(=a0), and falls through when a3(=[sym(the_console_port)]:8) == s0(=a0).
  The `bne` branch at 0x2850 targets 0x2878, is taken when a2(=[0xa800000000001000]:8) != a1(=0x53435241), and falls through when a2(=[0xa800000000001000]:8) == a1(=0x53435241).
  The `beq` branch at 0x2858 targets 0x2878, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x2864 targets 0x2878, is taken when a2(=[[0xa800000000001020]:8]) != a3(=0xfffffffffeeddead), and falls through when a2(=[[0xa800000000001020]:8]) == a3(=0xfffffffffeeddead).
  The `bne` branch at 0x2870 targets 0x2958, is taken when a4(=[[0xa800000000001020]:8+128]:8) != 0, and falls through when a4(=[[0xa800000000001020]:8+128]:8) == 0.
  The `bne` branch at 0x2898 targets 0x28dc, is taken when a3(=[sym(the_console_port)]:8) != s0(=a0), and falls through when a3(=[sym(the_console_port)]:8) == s0(=a0).
  The `bne` branch at 0x28a0 targets 0x28e0, is taken when a1(=[0xa800000000001000]:8) != a2(=0x53435241), and falls through when a1(=[0xa800000000001000]:8) == a2(=0x53435241).
  The `beq` branch at 0x28a8 targets 0x28dc, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x28b4 targets 0x28e0, is taken when a4(=[[0xa800000000001020]:8]) != a5(=0xfffffffffeeddead), and falls through when a4(=[[0xa800000000001020]:8]) == a5(=0xfffffffffeeddead).
  The `beq` branch at 0x28c0 targets 0x28e0, is taken when a1(=[[0xa800000000001020]:8+128]:8) == 0, and falls through when a1(=[[0xa800000000001020]:8+128]:8) != 0.
  The `bne` branch at 0x28fc targets 0x27fc, is taken when a2 != 0, and falls through when a2 == 0.
  The `beq` branch at 0x2928 targets 0x281c and is always taken.
  The `bne` branch at 0x293c targets 0x2830, is taken when (a2(=[[a0+112]:8+8]) & a3(=[a0+144])) != 0, and falls through when (a2(=[[a0+112]:8+8]) & a3(=[a0+144])) == 0.
  The `beq` branch at 0x2948 targets 0x2830 and is always taken.
  The `beq` branch at 0x2950 targets 0x27e4 and is always taken.
  The `beq` branch at 0x2978 targets 0x2878 and is always taken.
  The return at 0x28f4 has v0 = 0x0.

- `ioc3_rx_timeout` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc3.o)` at 0x2980 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc3.o)`.
  Range: 0x2980-0x2b38 (440 bytes).
  It occupies 440 bytes.
  The `lw` at 0x2980 loads 4 bytes from a0 (arg0 at entry) +0x80.
  The `sw` at 0x29e4 stores 4 bytes to a0 (arg0 at entry) +0x88.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x94, including `lw` at 0x29f4, `lw` at 0x2b28.
  The `sw` at 0x2a08 stores 4 bytes to a0 (arg0 at entry) +0x94.
  2 such `ld` accesses load 8 bytes from abs 0xa800000000001000, including `ld` at 0x2a14, `ld` at 0x2a70.
  3 such `ld` accesses load 8 bytes from abs 0xa800000000001020, including `ld` at 0x2a20, `ld` at 0x2a64, `ld` at 0x2b14.
  2 such `lw` accesses load 4 bytes from [0xa800000000001020]:8 +0x0, including `lw` at 0x2a34, `lw` at 0x2a84.
  3 such `ld` accesses load 8 bytes from [0xa800000000001020]:8 +0x80, including `ld` at 0x2a40, `ld` at 0x2a90, `ld` at 0x2b18.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x40, including `ld` at 0x2a4c, `ld` at 0x2ad8.
  The `sw` at 0x2a54 stores 4 bytes to [a0+64]:8 +0x0.
  The `sw` at 0x2af4 stores 4 bytes to [a0+64]:8 +0x14.
  The `jalr` at 0x2aa4 calls (unknown callee) with a0=0x1, a1=?, a2=?, a3=?, a4=[[0xa800000000001020]:8+128]:8, a5=0x53435241, a6=0xa800000000001020, a7=[sym(the_console_port)]:8.
  The `jal` at 0x2aac calls splx with a0=[sym(.sbss)], a1=?, a2=?, a3=?.
  The `jal` at 0x2b04 calls spl7 with a0=?, a1=a1 at entry (arg1), a2=-0x200, a3=[[0xa800000000001020]:8], a4=0xfffffffffeeddead, a5=[[0xa800000000001020]:8+128]:8, a6=0x53435241, a7=0x64.
  The `jalr` at 0x2b1c calls (unknown callee) with a0=0x0, a1=?, a2=?, a3=?.
  The `beq` branch at 0x29e8 targets 0x2af8, is taken when a4(?) >= 0x200 (unsigned), and falls through when a4(?) < 0x200 (unsigned).
  The `bne` branch at 0x2a1c targets 0x2a4c, is taken when t1(=[sym(the_console_port)]:8) != s0(=a0), and falls through when t1(=[sym(the_console_port)]:8) == s0(=a0).
  The `bne` branch at 0x2a24 targets 0x2a4c, is taken when a5(=[0xa800000000001000]:8) != a6(=0x53435241), and falls through when a5(=[0xa800000000001000]:8) == a6(=0x53435241).
  The `beq` branch at 0x2a2c targets 0x2a4c, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x2a38 targets 0x2a4c, is taken when a3(=[[0xa800000000001020]:8]) != a4(=0xfffffffffeeddead), and falls through when a3(=[[0xa800000000001020]:8]) == a4(=0xfffffffffeeddead).
  The `bne` branch at 0x2a44 targets 0x2b04, is taken when a5(=[[0xa800000000001020]:8+128]:8) != 0, and falls through when a5(=[[0xa800000000001020]:8+128]:8) == 0.
  The `bne` branch at 0x2a6c targets 0x2ab8, is taken when a7(=[sym(the_console_port)]:8) != s0(=a0), and falls through when a7(=[sym(the_console_port)]:8) == s0(=a0).
  The `bne` branch at 0x2a74 targets 0x2ab8, is taken when a4(=[0xa800000000001000]:8) != a5(=0x53435241), and falls through when a4(=[0xa800000000001000]:8) == a5(=0x53435241).
  The `beq` branch at 0x2a7c targets 0x2ab8, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x2a88 targets 0x2ab8, is taken when t0(=[[0xa800000000001020]:8]) != t1(=0xfffffffffeeddead), and falls through when t0(=[[0xa800000000001020]:8]) == t1(=0xfffffffffeeddead).
  The `beq` branch at 0x2a94 targets 0x2ab8, is taken when a4(=[[0xa800000000001020]:8+128]:8) == 0, and falls through when a4(=[[0xa800000000001020]:8+128]:8) != 0.
  The `beq` branch at 0x2b30 targets 0x2a4c and is always taken.
  The return at 0x2afc has v0 = one of 0x0, 0x1.

- `set_DTRRTS` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc3.o)` at 0x2b38 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc3.o)`.
  Range: 0x2b38-0x2d0c (468 bytes).
  It occupies 468 bytes.
  2 such `ld` accesses load 8 bytes from abs 0xa800000000001000, including `ld` at 0x2b6c, `ld` at 0x2c60.
  3 such `ld` accesses load 8 bytes from abs 0xa800000000001020, including `ld` at 0x2b70, `ld` at 0x2c58, `ld` at 0x2ce4.
  2 such `lw` accesses load 4 bytes from [0xa800000000001020]:8 +0x0, including `lw` at 0x2b84, `lw` at 0x2c74.
  3 such `ld` accesses load 8 bytes from [0xa800000000001020]:8 +0x80, including `ld` at 0x2b90, `ld` at 0x2c80, `ld` at 0x2ce8.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x94, including `lw` at 0x2ba0, `lw` at 0x2c38.
  4 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x40, including `ld` at 0x2bb4, `ld` at 0x2bd8, `ld` at 0x2c30.
  2 such `sw` accesses store 4 bytes to [a0+64]:8 +0x0, including `sw` at 0x2bd4, `sw` at 0x2c4c.
  2 such `lw` accesses load 4 bytes from [a0+64]:8 +0x0, including `lw` at 0x2bdc, `lw` at 0x2bf8.
  The `ld` at 0x2c0c loads 8 bytes from a0 (arg0 at entry) +0x48.
  The `lw` at 0x2c10 loads 4 bytes from [a0+64]:8 +0x18.
  The `lbu` at 0x2c20 loads 1 byte from [a0+72]:8 +0x4.
  The `sb` at 0x2c2c stores 1 byte to [a0+72]:8 +0x4.
  The `sw` at 0x2c34 stores 4 bytes to [a0+64]:8 +0x18.
  The `jalr` at 0x2c90 calls (unknown callee) with a0=0x1, a1=[[0xa800000000001020]:8+128]:8, a2=[a0+72]:8, a3=?, a7=[a0+148].
  The `jal` at 0x2c98 calls splx with a0=[sym(.sbss)], a1=?, a2=?, a3=?.
  The `jal` at 0x2cd8 calls spl7 with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a6=0x53435241, a7=[[0xa800000000001020]:8].
  The `jalr` at 0x2cf0 calls (unknown callee) with a0=0x0, a1=?, a2=?, a3=?, a5=[[0xa800000000001020]:8+128]:8.
  The `bne` branch at 0x2b68 targets 0x2ba0, is taken when t1(=[sym(the_console_port)]:8) != a0, and falls through when t1(=[sym(the_console_port)]:8) == a0.
  The `bne` branch at 0x2b74 targets 0x2ba0, is taken when a7(=[0xa800000000001000]:8) != a6(=0x53435241), and falls through when a7(=[0xa800000000001000]:8) == a6(=0x53435241).
  The `beq` branch at 0x2b7c targets 0x2ba0, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x2b88 targets 0x2ba0, is taken when a7(=[[0xa800000000001020]:8]) != t0(=0xfffffffffeeddead), and falls through when a7(=[[0xa800000000001020]:8]) == t0(=0xfffffffffeeddead).
  The `bne` branch at 0x2b98 targets 0x2cd8, is taken when t1(=[[0xa800000000001020]:8+128]:8) != 0, and falls through when t1(=[[0xa800000000001020]:8+128]:8) == 0.
  The `bgez` branch at 0x2bc4 targets 0x2c0c, is taken when t2(=([a0+148] << 0x23)) >= 0 (signed), and falls through when t2(=([a0+148] << 0x23)) < 0 (signed).
  The `bltz` branch at 0x2be4 targets 0x2c0c, is taken when a4(=([[a0+64]:8] << 0x21)) < 0 (signed), and falls through when a4(=([[a0+64]:8] << 0x21)) >= 0 (signed).
  The `bne` branch at 0x2bf0 targets 0x2cd0, is taken when a7(?) != 0, and falls through when a7(?) == 0.
  The `beq` branch at 0x2c04 targets 0x2bf0, is taken when (t2(=[[a0+64]:8]) & a3(=0x40000000)) == 0, and falls through when (t2(=[[a0+64]:8]) & a3(=0x40000000)) != 0.
  The `beq` branch at 0x2c1c targets 0x2cbc, is taken when a1 == 0, and falls through when a1 != 0.
  The `beq` branch at 0x2c40 targets 0x2c50, is taken when (t0(=0x10000000) & a7(=[a0+148])) == 0, and falls through when (t0(=0x10000000) & a7(=[a0+148])) != 0.
  The `bne` branch at 0x2c54 targets 0x2ca4, is taken when at(=[sym(the_console_port)]:8) != s0(=a0), and falls through when at(=[sym(the_console_port)]:8) == s0(=a0).
  The `bne` branch at 0x2c64 targets 0x2ca4, is taken when v1(=[0xa800000000001000]:8) != a0(=0x53435241), and falls through when v1(=[0xa800000000001000]:8) == a0(=0x53435241).
  The `beq` branch at 0x2c6c targets 0x2ca4, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x2c78 targets 0x2ca4, is taken when a0(=[[0xa800000000001020]:8]) != a1(=0xfffffffffeeddead), and falls through when a0(=[[0xa800000000001020]:8]) == a1(=0xfffffffffeeddead).
  The `beq` branch at 0x2c84 targets 0x2ca4, is taken when a1(=[[0xa800000000001020]:8+128]:8) == 0, and falls through when a1(=[[0xa800000000001020]:8+128]:8) != 0.
  The `beq` branch at 0x2cc8 targets 0x2c2c and is always taken.
  The `beq` branch at 0x2cd0 targets 0x2cac and is always taken.
  The `beq` branch at 0x2d04 targets 0x2ba0 and is always taken.
  The return at 0x2cb4 has v0 = one of -0x1, 0x0.

- `ioc3_set_DTR` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc3.o)` at 0x2d0c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc3.o)`.
  Range: 0x2d0c-0x2d2c (32 bytes).
  It occupies 32 bytes.
  The `jal` at 0x2d18 calls set_DTRRTS with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0x1, a3=0x1000000.
  The return at 0x2d24 has v0 = ret(set_DTRRTS).

- `ioc3_set_RTS` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc3.o)` at 0x2d2c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc3.o)`.
  Range: 0x2d2c-0x2d4c (32 bytes).
  It occupies 32 bytes.
  The `jal` at 0x2d38 calls set_DTRRTS with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0x2, a3=0x2000000.
  The return at 0x2d44 has v0 = ret(set_DTRRTS).

- `ioc3_query_DCD` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc3.o)` at 0x2d4c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc3.o)`.
  Range: 0x2d4c-0x2e50 (260 bytes).
  It occupies 260 bytes.
  2 such `ld` accesses load 8 bytes from abs 0xa800000000001000, including `ld` at 0x2d68, `ld` at 0x2db8.
  3 such `ld` accesses load 8 bytes from abs 0xa800000000001020, including `ld` at 0x2d6c, `ld` at 0x2dc0, `ld` at 0x2e24.
  2 such `lw` accesses load 4 bytes from [0xa800000000001020]:8 +0x0, including `lw` at 0x2d80, `lw` at 0x2dcc.
  3 such `ld` accesses load 8 bytes from [0xa800000000001020]:8 +0x80, including `ld` at 0x2d8c, `ld` at 0x2dd8, `ld` at 0x2e28.
  The `ld` at 0x2d9c loads 8 bytes from a0 (arg0 at entry) +0x40.
  The `lw` at 0x2db0 loads 4 bytes from [a0+64]:8 +0x18.
  The `jalr` at 0x2df0 calls (unknown callee) with a0=0x1, a1=?, a2=?, a3=[[0xa800000000001020]:8+128]:8, a4=[[a0+64]:8+24], a5=0xa800000000001020, a6=[0xa800000000001000]:8, a7=[[0xa800000000001020]:8].
  The `jal` at 0x2df8 calls splx with a0=[sym(.sbss)], a1=?, a2=?, a3=?.
  The `jal` at 0x2e18 calls spl7 with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=[sym(the_console_port)]:8, a4=0x53435241, a5=[[0xa800000000001020]:8], a6=0xfffffffffeeddead, a7=[[0xa800000000001020]:8+128]:8.
  The `jalr` at 0x2e30 calls (unknown callee) with a0=0x0, a1=?, a2=?, a3=?.
  The `bne` branch at 0x2d64 targets 0x2d9c, is taken when a0 != a3(=[sym(the_console_port)]:8), and falls through when a0 == a3(=[sym(the_console_port)]:8).
  The `bne` branch at 0x2d70 targets 0x2d9c, is taken when a5(=[0xa800000000001000]:8) != a4(=0x53435241), and falls through when a5(=[0xa800000000001000]:8) == a4(=0x53435241).
  The `beq` branch at 0x2d78 targets 0x2d9c, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x2d84 targets 0x2d9c, is taken when a5(=[[0xa800000000001020]:8]) != a6(=0xfffffffffeeddead), and falls through when a5(=[[0xa800000000001020]:8]) == a6(=0xfffffffffeeddead).
  The `bne` branch at 0x2d94 targets 0x2e18, is taken when a7(=[[0xa800000000001020]:8+128]:8) != 0, and falls through when a7(=[[0xa800000000001020]:8+128]:8) == 0.
  The `bne` branch at 0x2dac targets 0x2e08, is taken when a0 != a3(=[sym(the_console_port)]:8), and falls through when a0 == a3(=[sym(the_console_port)]:8).
  The `bne` branch at 0x2dbc targets 0x2e08, is taken when a6(=[0xa800000000001000]:8) != a7(=0x53435241), and falls through when a6(=[0xa800000000001000]:8) == a7(=0x53435241).
  The `beq` branch at 0x2dc4 targets 0x2e08, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x2dd0 targets 0x2e08, is taken when a7(=[[0xa800000000001020]:8]) != t0(=0xfffffffffeeddead), and falls through when a7(=[[0xa800000000001020]:8]) == t0(=0xfffffffffeeddead).
  The `beq` branch at 0x2de0 targets 0x2e08, is taken when a3(=[[0xa800000000001020]:8+128]:8) == 0, and falls through when a3(=[[0xa800000000001020]:8+128]:8) != 0.
  The `beq` branch at 0x2e48 targets 0x2d9c and is always taken.
  The return at 0x2e10 has v0 = ?.

- `ioc3_query_CTS` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc3.o)` at 0x2e50 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc3.o)`.
  Range: 0x2e50-0x2f54 (260 bytes).
  It occupies 260 bytes.
  2 such `ld` accesses load 8 bytes from abs 0xa800000000001000, including `ld` at 0x2e6c, `ld` at 0x2ebc.
  3 such `ld` accesses load 8 bytes from abs 0xa800000000001020, including `ld` at 0x2e70, `ld` at 0x2ec4, `ld` at 0x2f28.
  2 such `lw` accesses load 4 bytes from [0xa800000000001020]:8 +0x0, including `lw` at 0x2e84, `lw` at 0x2ed0.
  3 such `ld` accesses load 8 bytes from [0xa800000000001020]:8 +0x80, including `ld` at 0x2e90, `ld` at 0x2edc, `ld` at 0x2f2c.
  The `ld` at 0x2ea0 loads 8 bytes from a0 (arg0 at entry) +0x40.
  The `lw` at 0x2eb4 loads 4 bytes from [a0+64]:8 +0x18.
  The `jalr` at 0x2ef4 calls (unknown callee) with a0=0x1, a1=?, a2=?, a3=[[0xa800000000001020]:8+128]:8, a4=[[a0+64]:8+24], a5=0xa800000000001020, a6=[0xa800000000001000]:8, a7=[[0xa800000000001020]:8].
  The `jal` at 0x2efc calls splx with a0=[sym(.sbss)], a1=?, a2=?, a3=?.
  The `jal` at 0x2f1c calls spl7 with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=[sym(the_console_port)]:8, a4=0x53435241, a5=[[0xa800000000001020]:8], a6=0xfffffffffeeddead, a7=[[0xa800000000001020]:8+128]:8.
  The `jalr` at 0x2f34 calls (unknown callee) with a0=0x0, a1=?, a2=?, a3=?.
  The `bne` branch at 0x2e68 targets 0x2ea0, is taken when a0 != a3(=[sym(the_console_port)]:8), and falls through when a0 == a3(=[sym(the_console_port)]:8).
  The `bne` branch at 0x2e74 targets 0x2ea0, is taken when a5(=[0xa800000000001000]:8) != a4(=0x53435241), and falls through when a5(=[0xa800000000001000]:8) == a4(=0x53435241).
  The `beq` branch at 0x2e7c targets 0x2ea0, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x2e88 targets 0x2ea0, is taken when a5(=[[0xa800000000001020]:8]) != a6(=0xfffffffffeeddead), and falls through when a5(=[[0xa800000000001020]:8]) == a6(=0xfffffffffeeddead).
  The `bne` branch at 0x2e98 targets 0x2f1c, is taken when a7(=[[0xa800000000001020]:8+128]:8) != 0, and falls through when a7(=[[0xa800000000001020]:8+128]:8) == 0.
  The `bne` branch at 0x2eb0 targets 0x2f0c, is taken when a0 != a3(=[sym(the_console_port)]:8), and falls through when a0 == a3(=[sym(the_console_port)]:8).
  The `bne` branch at 0x2ec0 targets 0x2f0c, is taken when a6(=[0xa800000000001000]:8) != a7(=0x53435241), and falls through when a6(=[0xa800000000001000]:8) == a7(=0x53435241).
  The `beq` branch at 0x2ec8 targets 0x2f0c, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x2ed4 targets 0x2f0c, is taken when a7(=[[0xa800000000001020]:8]) != t0(=0xfffffffffeeddead), and falls through when a7(=[[0xa800000000001020]:8]) == t0(=0xfffffffffeeddead).
  The `beq` branch at 0x2ee4 targets 0x2f0c, is taken when a3(=[[0xa800000000001020]:8+128]:8) == 0, and falls through when a3(=[[0xa800000000001020]:8+128]:8) != 0.
  The `beq` branch at 0x2f4c targets 0x2ea0 and is always taken.
  The return at 0x2f14 has v0 = ?.

- `ioc3_set_proto` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc3.o)` at 0x2f54 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc3.o)`.
  Range: 0x2f54-0x2fa8 (84 bytes).
  It occupies 84 bytes.
  The `ld` at 0x2f54 loads 8 bytes from a0 (arg0 at entry) +0x70.
  2 such `lbu` accesses load 1 byte from [a0+112]:8 +0x20, including `lbu` at 0x2f70, `lbu` at 0x2f90.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x38, including `ld` at 0x2f74, `ld` at 0x2f94.
  2 such `sw` accesses store 4 bytes to ([a0+56]:8 + ([[a0+112]:8+32]:1 << 0x2)) +0x40, including `sw` at 0x2f80, `sw` at 0x2fa4.
  The `beq` branch at 0x2f58 targets 0x2f70, is taken when a1 == 0, and falls through when a1 != 0.
  The `bne` branch at 0x2f60 targets 0x2f88, is taken when a1 != v0(=0x1), and falls through when a1 == v0(=0x1).
  The `beq` branch at 0x2f68 targets 0x2f90 and is always taken.
  The `beq` branch at 0x2fa0 targets 0x2f84 and is always taken.
  The return at 0x2f88 has v0 = one of 0x0, 0x1.

- `ioc3_get_mapid` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc3.o)` at 0x2fa8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc3.o)`.
  Range: 0x2fa8-0x3008 (96 bytes).
  It occupies 96 bytes.
  The `ld` at 0x2fbc loads 8 bytes from a0 (arg0 at entry) +0x70.
  The `jal` at 0x2fe0 calls copyout with a0=sp-16, a1=a1 at entry (arg1), a2=0x8, a3=sym(.data).
  The `beq` branch at 0x2fb0 targets 0x2ff8, is taken when a1 == 0, and falls through when a1 != 0.
  The `beq` branch at 0x2ff0 targets 0x2ffc and is always taken.
  The return at 0x3000 has v0 = one of 0x0, 0xe.

- `ioc3_map` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc3.o)` at 0x3008 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc3.o)`.
  Range: 0x3008-0x3098 (144 bytes).
  It occupies 144 bytes.
  The `ld` at 0x3034 loads 8 bytes from a0 (arg0 at entry) +0x58.
  The `ld` at 0x3068 loads 8 bytes from a0 (arg0 at entry) +0x70.
  The `ld` at 0x3078 loads 8 bytes from a0 (arg0 at entry) +0x38.
  The `jal` at 0x303c calls disable_intrs with a0=a0 at entry (arg0), a1=-0x1, a2=?, a3=?, a5=0x16.
  The `jal` at 0x304c calls v_mapphys with a0=a1 at entry (arg1), a1=?, a2=0x4000, a3=?.
  The `beq` branch at 0x3010 targets 0x302c, is taken when a2 == 0, and falls through when a2 != 0.
  The `beq` branch at 0x301c targets 0x3068, is taken when a2 == at(=0x4000), and falls through when a2 != at(=0x4000).
  The `beq` branch at 0x3024 targets 0x3060 and is always taken.
  The `beq` branch at 0x3090 targets 0x303c and is always taken.
  The return at 0x3060 has v0 = one of 0x16, ret(v_mapphys).

- `ioc3_unmap` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc3.o)` at 0x3098 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc3.o)`.
  Range: 0x3098-0x31d4 (316 bytes).
  It occupies 316 bytes.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x94, including `lw` at 0x30a0, `lw` at 0x31c4.
  The `sw` at 0x30b4 stores 4 bytes to a0 (arg0 at entry) +0x94.
  2 such `ld` accesses load 8 bytes from abs 0xa800000000001000, including `ld` at 0x30c4, `ld` at 0x3124.
  3 such `ld` accesses load 8 bytes from abs 0xa800000000001020, including `ld` at 0x30cc, `ld` at 0x3118, `ld` at 0x31ac.
  2 such `lw` accesses load 4 bytes from [0xa800000000001020]:8 +0x0, including `lw` at 0x30e8, `lw` at 0x3138.
  3 such `ld` accesses load 8 bytes from [0xa800000000001020]:8 +0x80, including `ld` at 0x30f4, `ld` at 0x3144, `ld` at 0x31b0.
  3 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x40, including `ld` at 0x3100, `ld` at 0x316c, `ld` at 0x3180.
  The `sw` at 0x3108 stores 4 bytes to [a0+64]:8 +0x0.
  The `lw` at 0x3170 loads 4 bytes from [a0+64]:8 +0x8.
  The `sw` at 0x3178 stores 4 bytes to a0 (arg0 at entry) +0x98.
  The `sw` at 0x317c stores 4 bytes to [a0+64]:8 +0x4.
  The `lw` at 0x3184 loads 4 bytes from [a0+64]:8 +0xc.
  The `sw` at 0x318c stores 4 bytes to a0 (arg0 at entry) +0x9c.
  The `sw` at 0x3190 stores 4 bytes to [a0+64]:8 +0x10.
  The `jalr` at 0x3158 calls (unknown callee) with a0=0x1, a1=[a0+64]:8, a2=[[0xa800000000001020]:8], a3=[[0xa800000000001020]:8+128]:8, a4=[sym(.sbss)], a5=0xa800000000001020, a6=[sym(the_console_port)]:8.
  The `jal` at 0x3160 calls splx with a0=[sym(.sbss)], a1=?, a2=?, a3=?.
  The `jal` at 0x31a0 calls spl7 with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=?, a4=[0xa800000000001000]:8, a5=0x53435241, a6=[[0xa800000000001020]:8], a7=0xfffffffffeeddead.
  The `jalr` at 0x31b8 calls (unknown callee) with a0=0x0, a1=?, a2=?, a3=?, a7=[[0xa800000000001020]:8+128]:8.
  The `bne` branch at 0x30d0 targets 0x3100, is taken when at(=[sym(the_console_port)]:8) != a0, and falls through when at(=[sym(the_console_port)]:8) == a0.
  The `bne` branch at 0x30d8 targets 0x3100, is taken when a4(=[0xa800000000001000]:8) != a5(=0x53435241), and falls through when a4(=[0xa800000000001000]:8) == a5(=0x53435241).
  The `beq` branch at 0x30e0 targets 0x3100, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x30ec targets 0x3100, is taken when a6(=[[0xa800000000001020]:8]) != a7(=0xfffffffffeeddead), and falls through when a6(=[[0xa800000000001020]:8]) == a7(=0xfffffffffeeddead).
  The `bne` branch at 0x30f8 targets 0x31a0, is taken when t0(=[[0xa800000000001020]:8+128]:8) != 0, and falls through when t0(=[[0xa800000000001020]:8+128]:8) == 0.
  The `bne` branch at 0x3120 targets 0x316c, is taken when a6(=[sym(the_console_port)]:8) != s0(=a0), and falls through when a6(=[sym(the_console_port)]:8) == s0(=a0).
  The `bne` branch at 0x3128 targets 0x316c, is taken when a4(=[0xa800000000001000]:8) != a0(=0x53435241), and falls through when a4(=[0xa800000000001000]:8) == a0(=0x53435241).
  The `beq` branch at 0x3130 targets 0x316c, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x313c targets 0x316c, is taken when a2(=[[0xa800000000001020]:8]) != a3(=0xfffffffffeeddead), and falls through when a2(=[[0xa800000000001020]:8]) == a3(=0xfffffffffeeddead).
  The `beq` branch at 0x3148 targets 0x316c, is taken when a3(=[[0xa800000000001020]:8+128]:8) == 0, and falls through when a3(=[[0xa800000000001020]:8+128]:8) != 0.
  The `beq` branch at 0x31cc targets 0x3100 and is always taken.
  The return at 0x3198 has v0 = one of [0xa800000000001020]:8, ret(splx).

- `ioc3_set_sscr` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc3.o)` at 0x31d4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc3.o)`.
  Range: 0x31d4-0x32f8 (292 bytes).
  It occupies 292 bytes.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x94, including `lw` at 0x31d4, `lw` at 0x32a8, `lw` at 0x32e8.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x94, including `sw` at 0x31f0, `sw` at 0x32c0.
  2 such `ld` accesses load 8 bytes from abs 0xa800000000001000, including `ld` at 0x320c, `ld` at 0x3260.
  3 such `ld` accesses load 8 bytes from abs 0xa800000000001020, including `ld` at 0x3210, `ld` at 0x3254, `ld` at 0x32d0.
  2 such `lw` accesses load 4 bytes from [0xa800000000001020]:8 +0x0, including `lw` at 0x3224, `lw` at 0x3274.
  3 such `ld` accesses load 8 bytes from [0xa800000000001020]:8 +0x80, including `ld` at 0x3230, `ld` at 0x3280, `ld` at 0x32d4.
  The `ld` at 0x323c loads 8 bytes from a0 (arg0 at entry) +0x40.
  The `sw` at 0x3244 stores 4 bytes to [a0+64]:8 +0x0.
  The `jalr` at 0x3294 calls (unknown callee) with a0=0x1, a1=[[0xa800000000001020]:8+128]:8, a2=[sym(the_console_port)]:8, a3=[[0xa800000000001020]:8], a4=0xfffffffffeeddead, a5=[sym(.sbss)].
  The `jal` at 0x329c calls splx with a0=[sym(.sbss)], a1=?, a2=?, a3=?.
  The `jal` at 0x32c4 calls spl7 with a0=0x53435241, a1=[[0xa800000000001020]:8], a2=0xfffffffffeeddead, a3=[[0xa800000000001020]:8+128]:8, a4=0xa800000000001020.
  The `jalr` at 0x32dc calls (unknown callee) with a0=0x0, a1=?, a2=?, a3=?, a6=[[0xa800000000001020]:8+128]:8.
  The `beq` branch at 0x31e4 targets 0x32b8, is taken when a2 == 0, and falls through when a2 != 0.
  The `bne` branch at 0x3208 targets 0x323c, is taken when a2(=[sym(the_console_port)]:8) != s0(=a0), and falls through when a2(=[sym(the_console_port)]:8) == s0(=a0).
  The `bne` branch at 0x3214 targets 0x323c, is taken when a1(=[0xa800000000001000]:8) != a0(=0x53435241), and falls through when a1(=[0xa800000000001000]:8) == a0(=0x53435241).
  The `beq` branch at 0x321c targets 0x323c, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x3228 targets 0x323c, is taken when a1(=[[0xa800000000001020]:8]) != a2(=0xfffffffffeeddead), and falls through when a1(=[[0xa800000000001020]:8]) == a2(=0xfffffffffeeddead).
  The `bne` branch at 0x3234 targets 0x32c4, is taken when a3(=[[0xa800000000001020]:8+128]:8) != 0, and falls through when a3(=[[0xa800000000001020]:8+128]:8) == 0.
  The `bne` branch at 0x325c targets 0x32a8, is taken when a2(=[sym(the_console_port)]:8) != s0(=a0), and falls through when a2(=[sym(the_console_port)]:8) == s0(=a0).
  The `bne` branch at 0x3264 targets 0x32a8, is taken when a0(=[0xa800000000001000]:8) != a1(=0x53435241), and falls through when a0(=[0xa800000000001000]:8) == a1(=0x53435241).
  The `beq` branch at 0x326c targets 0x32a8, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x3278 targets 0x32a8, is taken when a3(=[[0xa800000000001020]:8]) != a4(=0xfffffffffeeddead), and falls through when a3(=[[0xa800000000001020]:8]) == a4(=0xfffffffffeeddead).
  The `beq` branch at 0x3284 targets 0x32a8, is taken when a1(=[[0xa800000000001020]:8+128]:8) == 0, and falls through when a1(=[[0xa800000000001020]:8+128]:8) != 0.
  The `beq` branch at 0x32bc targets 0x31f4 and is always taken.
  The `beq` branch at 0x32f0 targets 0x323c and is always taken.
  The return at 0x32b0 has v0 = [a0+148].

- `ioc3_console_write` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc3.o)` at 0x32f8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc3.o)`.
  Range: 0x32f8-0x344c (340 bytes).
  It occupies 340 bytes.
  7 such `lw` accesses load 4 bytes from [sym(console_mem)]:8 +0xb8, including `lw` at 0x32fc, `lw` at 0x33d8, `lw` at 0x33e8.
  The `sd` at 0x3324 stores 8 bytes to a2 (arg2 at entry) +0x0.
  The `sb` at 0x334c stores 1 byte to [sym(console_mem)]:8 +0x20178.
  6 such `lbu` accesses load 1 byte from [sym(console_mem)]:8 +0x2017d, including `lbu` at 0x3350, `lbu` at 0x3368, `lbu` at 0x3378.
  The `lbu` at 0x335c loads 1 byte from ?.
  The `sw` at 0x33d4 stores 4 bytes to [sym(console_mem)]:8 +0xb8.
  The `bne` branch at 0x330c targets 0x3324, is taken when t0(=0x10000000) != t2(?), and falls through when t0(=0x10000000) == t2(?).
  The `beq` branch at 0x331c targets 0x3440 and is always taken.
  The `bne` branch at 0x3338 targets 0x3350, is taken when a1 != 0, and falls through when a1 == 0.
  The `beq` branch at 0x3340 targets 0x33c0 and is always taken.
  The `beq` branch at 0x3348 targets 0x33c0, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `bne` branch at 0x3360 targets 0x3348, is taken when (a6(=[[sym(console_mem)]:8+131453]:1) & 0x20) != 0, and falls through when (a6(=[[sym(console_mem)]:8+131453]:1) & 0x20) == 0.
  The `bne` branch at 0x3370 targets 0x3348, is taken when (a7(=[[sym(console_mem)]:8+131453]:1) & 0x20) != 0, and falls through when (a7(=[[sym(console_mem)]:8+131453]:1) & 0x20) == 0.
  The `bne` branch at 0x3380 targets 0x3348, is taken when (t0(=[[sym(console_mem)]:8+131453]:1) & 0x20) != 0, and falls through when (t0(=[[sym(console_mem)]:8+131453]:1) & 0x20) == 0.
  The `bne` branch at 0x3390 targets 0x3348, is taken when (t1(=[[sym(console_mem)]:8+131453]:1) & 0x20) != 0, and falls through when (t1(=[[sym(console_mem)]:8+131453]:1) & 0x20) == 0.
  The `bne` branch at 0x33a0 targets 0x3348, is taken when (t2(=[[sym(console_mem)]:8+131453]:1) & 0x20) != 0, and falls through when (t2(=[[sym(console_mem)]:8+131453]:1) & 0x20) == 0.
  The `beq` branch at 0x33b0 targets 0x3368, is taken when (t3(=[[sym(console_mem)]:8+131453]:1) & 0x20) == 0, and falls through when (t3(=[[sym(console_mem)]:8+131453]:1) & 0x20) != 0.
  The `beq` branch at 0x33b8 targets 0x3348 and is always taken.
  The `bne` branch at 0x33cc targets 0x3324, is taken when t0(=0x10000000) != t8(?), and falls through when t0(=0x10000000) == t8(?).
  The `bne` branch at 0x33e0 targets 0x33cc, is taken when a5(=0x30000000) != t9(?), and falls through when a5(=0x30000000) == t9(?).
  The `bne` branch at 0x33f0 targets 0x33c8, is taken when a5(=0x30000000) != v0(?), and falls through when a5(=0x30000000) == v0(?).
  The `bne` branch at 0x3400 targets 0x33c8, is taken when a5(=0x30000000) != v1(?), and falls through when a5(=0x30000000) == v1(?).
  The `bne` branch at 0x3410 targets 0x33c8, is taken when a5(=0x30000000) != a3(?), and falls through when a5(=0x30000000) == a3(?).
  The `bne` branch at 0x3420 targets 0x33c8, is taken when a5(=0x30000000) != t3(?), and falls through when a5(=0x30000000) == t3(?).
  The `beq` branch at 0x3430 targets 0x33e8, is taken when a5(=0x30000000) == t8(?), and falls through when a5(=0x30000000) != t8(?).
  The `beq` branch at 0x3438 targets 0x33c8 and is always taken.
  The `beq` branch at 0x3444 targets 0x33d4 and is always taken.
  The return at 0x33c0 has v0 = 0x0.

- `console_debug_poll` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc3.o)` at 0x344c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_ioc3.o)`.
  Range: 0x344c-0x3524 (216 bytes).
  It occupies 216 bytes.
  7 such `lw` accesses load 4 bytes from [sym(console_mem)]:8 +0xb8, including `lw` at 0x3450, `lw` at 0x34a8, `lw` at 0x34b8.
  The `lbu` at 0x347c loads 1 byte from [sym(console_mem)]:8 +0x2017d.
  The `lbu` at 0x348c loads 1 byte from [sym(console_mem)]:8 +0x20178.
  The `sw` at 0x34a4 stores 4 bytes to [sym(console_mem)]:8 +0xb8.
  The `jal` at 0x3514 calls debug with a0=sym(.rodata), a1=[sym(console_mem)]:8+131072, a2=[sym(console_mem)]:8+184, a3=[sym(console_mem)]:8, a4=0x20000, a5=([[sym(console_mem)]:8+184] << 0x21), a6=[[sym(console_mem)]:8+184].
  The `bgez` branch at 0x3468 targets 0x3478, is taken when at(=([[sym(console_mem)]:8+184] << 0x23)) >= 0 (signed), and falls through when at(=([[sym(console_mem)]:8+184] << 0x23)) < 0 (signed).
  The `bgez` branch at 0x3470 targets 0x34a0, is taken when a5(=([[sym(console_mem)]:8+184] << 0x21)) >= 0 (signed), and falls through when a5(=([[sym(console_mem)]:8+184] << 0x21)) < 0 (signed).
  The `beq` branch at 0x3484 targets 0x3498, is taken when (v0(=[[sym(console_mem)]:8+131453]:1) & 0x1) == 0, and falls through when (v0(=[[sym(console_mem)]:8+131453]:1) & 0x1) != 0.
  The `beq` branch at 0x3490 targets 0x3510, is taken when v1(=[[sym(console_mem)]:8+131448]:1) == a0(=0x1), and falls through when v1(=[[sym(console_mem)]:8+131448]:1) != a0(=0x1).
  The `bltz` branch at 0x34b0 targets 0x3508, is taken when a5(=([[sym(console_mem)]:8+184] << 0x21)) < 0 (signed), and falls through when a5(=([[sym(console_mem)]:8+184] << 0x21)) >= 0 (signed).
  The `bne` branch at 0x34c0 targets 0x3508, is taken when (t0(=[[sym(console_mem)]:8+184]) & a1(=0x40000000)) != 0, and falls through when (t0(=[[sym(console_mem)]:8+184]) & a1(=0x40000000)) == 0.
  The `bne` branch at 0x34d0 targets 0x3508, is taken when (t1(=[[sym(console_mem)]:8+184]) & a1(=0x40000000)) != 0, and falls through when (t1(=[[sym(console_mem)]:8+184]) & a1(=0x40000000)) == 0.
  The `bne` branch at 0x34e0 targets 0x3508, is taken when (t2(=[[sym(console_mem)]:8+184]) & a1(=0x40000000)) != 0, and falls through when (t2(=[[sym(console_mem)]:8+184]) & a1(=0x40000000)) == 0.
  The `bne` branch at 0x34f0 targets 0x3508, is taken when (t3(=[[sym(console_mem)]:8+184]) & a1(=0x40000000)) != 0, and falls through when (t3(=[[sym(console_mem)]:8+184]) & a1(=0x40000000)) == 0.
  The `beq` branch at 0x3500 targets 0x34b8, is taken when (t8(=[[sym(console_mem)]:8+184]) & a1(=0x40000000)) == 0, and falls through when (t8(=[[sym(console_mem)]:8+184]) & a1(=0x40000000)) != 0.
  The `beq` branch at 0x3508 targets 0x347c and is always taken.
  The `beq` branch at 0x351c targets 0x3498 and is always taken.
  The return at 0x3498 has v0 = one of ?, ret(debug).
