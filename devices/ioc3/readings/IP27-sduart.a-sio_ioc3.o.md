# Readings: `IP27/usr/cpu/sysgen/IP27boot/sduart.a(sio_ioc3.o)`

One entry per routine, filed here from the reading batches by binary.

- `ioc3_sio_mlreset` in `IP27/usr/cpu/sysgen/IP27boot/sduart.a(sio_ioc3.o)` at 0x0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/sduart.a(sio_ioc3.o)`.
  Range: 0x0-0x2c (44 bytes).
  It occupies 44 bytes.
  The `jal` at 0x18 calls sio_console_register with a0=sp-32, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x24 has v0 = ret(sio_console_register).

- `ring_dmatrans` in `IP27/usr/cpu/sysgen/IP27boot/sduart.a(sio_ioc3.o)` at 0x2c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/sduart.a(sio_ioc3.o)`.
  Range: 0x2c-0x78 (76 bytes).
  It occupies 76 bytes.
  The `jal` at 0x54 calls pciio_dmatrans_addr with a0=a0 at entry (arg0), a1=0x0, a2=?, a3=0x4000, a4=0x40.
  The `beq` branch at 0x40 targets 0x68, is taken when a0 == at(=-0x1), and falls through when a0 != at(=-0x1).
  The `beq` branch at 0x60 targets 0x6c and is always taken.
  The return at 0x70 has v0 = one of ret(pciio_dmatrans_addr), ?.

- `mask_disable_intrs` in `IP27/usr/cpu/sysgen/IP27boot/sduart.a(sio_ioc3.o)` at 0x78 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/sduart.a(sio_ioc3.o)`.
  Range: 0x78-0x8c (20 bytes).
  It occupies 20 bytes.
  The `lw` at 0x78 loads 4 bytes from a0 (arg0 at entry) +0x90.
  The `sw` at 0x88 stores 4 bytes to a0 (arg0 at entry) +0x90.
  The return at 0x84 has v0 = ?.

- `enable_intrs` in `IP27/usr/cpu/sysgen/IP27boot/sduart.a(sio_ioc3.o)` at 0x8c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/sduart.a(sio_ioc3.o)`.
  Range: 0x8c-0xdc (80 bytes).
  It occupies 80 bytes.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x90, including `lw` at 0x8c, `lw` at 0xc8.
  The `ld` at 0xb0 loads 8 bytes from a0 (arg0 at entry) +0xa0.
  The `sw` at 0xd8 stores 4 bytes to a0 (arg0 at entry) +0x90.
  The `jal` at 0xb8 calls ioc3_write_ireg with a0=[a0+160]:8, a1=a1 at entry (arg1), a2=0x0, a3=a3 at entry (arg3).
  The `bne` branch at 0xa0 targets 0xb0, is taken when a1 != at(?), and falls through when a1 == at(?).
  The `beq` branch at 0xd4 targets 0xa8 and is always taken.
  The return at 0xa8 has v0 = one of ?, ret(ioc3_write_ireg).

- `disable_intrs` in `IP27/usr/cpu/sysgen/IP27boot/sduart.a(sio_ioc3.o)` at 0xdc (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/sduart.a(sio_ioc3.o)`.
  Range: 0xdc-0x130 (84 bytes).
  It occupies 84 bytes.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x90, including `lw` at 0xdc, `lw` at 0x10c.
  The `ld` at 0x108 loads 8 bytes from a0 (arg0 at entry) +0xa0.
  The `sw` at 0x11c stores 4 bytes to a0 (arg0 at entry) +0x90.
  The `jal` at 0x104 calls ioc3_write_ireg with a0=[a0+160]:8, a1=a1 at entry (arg1), a2=0x1, a3=a3 at entry (arg3).
  The `beq` branch at 0xf8 targets 0x120, is taken when (at(=[a0+144]) & a1) == 0, and falls through when (at(=[a0+144]) & a1) != 0.
  The return at 0x128 has v0 = ?.

- `ioc3_serial_intr` in `IP27/usr/cpu/sysgen/IP27boot/sduart.a(sio_ioc3.o)` at 0x130 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/sduart.a(sio_ioc3.o)`.
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
  9 such `ld` accesses load 8 bytes from [0xa800000000001020]:8 +0x50, including `ld` at 0x374, `ld` at 0x38c, `ld` at 0x524.
  The `ld` at 0x4b4 loads 8 bytes from a0 (arg0 at entry) +0xa0.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x94, including `lw` at 0x5d8, `lw` at 0x680.
  The `sw` at 0x5e8 stores 4 bytes to a0 (arg0 at entry) +0x94.
  The `sw` at 0x604 stores 4 bytes to [a0+64]:8 +0x0.
  The `jal` at 0x16c calls sio_lock_port with a0=a0 at entry (arg0), a1=0x0, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x1dc calls (unknown callee) with a0=a0 at entry (arg0), a1=0x1, a2=?, a3=?.
  The `jalr` at 0x21c calls (unknown callee) with a0=a0 at entry (arg0), a1=[[a0+8]:8]:8, a2=?, a3=?.
  The `jalr` at 0x26c calls (unknown callee) with a0=a0 at entry (arg0), a1=?, a2=?, a3=?, a4=[[a0+112]:8+20], a5=[a0+56]:8, a7=[[a0+8]:8+8]:8.
  The `jalr` at 0x324 calls (unknown callee) with a0=a0 at entry (arg0), a1=0x1, a2=?, a3=?.
  The `jal` at 0x380 calls spl7 with a0=[sym(the_console_port)]:8, a1=[[0xa800000000001020]:8+80]:8, a2=?, a3=?, a4=[0xa800000000001000]:8.
  The `jalr` at 0x394 calls (unknown callee) with a0=0x0, a1=?, a2=[[0xa800000000001020]:8+80]:8, a3=?.
  The `jalr` at 0x3d8 calls (unknown callee) with a0=a0 at entry (arg0), a1=[[a0+112]:8+16], a2=?, a3=?, a5=[[a0+8]:8]:8.
  The `jalr` at 0x44c calls (unknown callee) with a0=a0 at entry (arg0), a1=[[a0+112]:8+8], a2=?, a3=?.
  The `jal` at 0x484 calls mask_disable_intrs with a0=a0 at entry (arg0), a1=[[a0+112]:8+8], a2=?, a3=?.
  The `jal` at 0x494 calls sio_unlock_port with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x4bc calls ioc3_write_ireg with a0=[a0+160]:8, a1=[a0+144], a2=0x0, a3=?.
  The `jalr` at 0x4ec calls (unknown callee) with a0=a0 at entry (arg0), a1=0x0, a2=[[a0+8]:8+32]:8, a3=?.
  The `jal` at 0x530 calls spl7 with a0=[sym(the_console_port)]:8, a1=[[a0+112]:8], a2=?, a3=[a0+56]:8, a4=0xfffffffffeeddead, a5=[[0xa800000000001020]:8+80]:8.
  The `jalr` at 0x544 calls (unknown callee) with a0=0x0, a1=?, a2=?, a3=?, a6=[[0xa800000000001020]:8+80]:8.
  The `jalr` at 0x580 calls (unknown callee) with a0=0x1, a1=[[0xa800000000001020]:8+80]:8, a2=?, a3=?, a7=0xfffffffffeeddead.
  The `jal` at 0x588 calls splx with a0=[sym(.sbss)], a1=?, a2=?, a3=?.
  The `jalr` at 0x5c0 calls (unknown callee) with a0=0x1, a1=[[0xa800000000001020]:8+80]:8, a2=?, a3=?.
  The `jal` at 0x5c8 calls splx with a0=[sym(.sbss)], a1=?, a2=?, a3=?.
  The `jal` at 0x624 calls mask_disable_intrs with a0=a0 at entry (arg0), a1=[[a0+112]:8+16], a2=?, a3=?.
  The `jal` at 0x664 calls spl7 with a0=?, a1=[a0+148], a2=?, a3=?, a4=0xfffffffffeeddead, a5=[[0xa800000000001020]:8+80]:8.
  The `jalr` at 0x678 calls (unknown callee) with a0=0x0, a1=?, a2=?, a3=?, a6=[[0xa800000000001020]:8+80]:8.
  The `jalr` at 0x6b4 calls (unknown callee) with a0=0x1, a1=[[0xa800000000001020]:8+80]:8, a2=[a0+64]:8, a3=?, a7=0xfffffffffeeddead.
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
  The `beq` branch at 0x378 targets 0x198, is taken when a1(=[[0xa800000000001020]:8+80]:8) == 0, and falls through when a1(=[[0xa800000000001020]:8+80]:8) != 0.
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
  The `beq` branch at 0x528 targets 0x2dc, is taken when a5(=[[0xa800000000001020]:8+80]:8) == 0, and falls through when a5(=[[0xa800000000001020]:8+80]:8) != 0.
  The `beq` branch at 0x550 targets 0x2dc and is always taken.
  The `beq` branch at 0x558 targets 0x2f8, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x568 targets 0x2f8, is taken when a7(=0xfffffffffeeddead) != t0(=[[0xa800000000001020]:8]), and falls through when a7(=0xfffffffffeeddead) == t0(=[[0xa800000000001020]:8]).
  The `beq` branch at 0x574 targets 0x2f8, is taken when a1(=[[0xa800000000001020]:8+80]:8) == 0, and falls through when a1(=[[0xa800000000001020]:8+80]:8) != 0.
  The `beq` branch at 0x590 targets 0x2fc and is always taken.
  The `beq` branch at 0x598 targets 0x1b4, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x5a8 targets 0x1b4, is taken when t1(=0xfffffffffeeddead) != t2(=[[0xa800000000001020]:8]), and falls through when t1(=0xfffffffffeeddead) == t2(=[[0xa800000000001020]:8]).
  The `beq` branch at 0x5b4 targets 0x1b4, is taken when a1(=[[0xa800000000001020]:8+80]:8) == 0, and falls through when a1(=[[0xa800000000001020]:8+80]:8) != 0.
  The `beq` branch at 0x5d0 targets 0x1b8 and is always taken.
  The `bne` branch at 0x5f0 targets 0x600, is taken when t3(=[sym(the_console_port)]:8) != s0(=a0), and falls through when t3(=[sym(the_console_port)]:8) == s0(=a0).
  The `beq` branch at 0x5f8 targets 0x63c, is taken when s6(=0x53435241) == v0(=[0xa800000000001000]:8), and falls through when s6(=0x53435241) != v0(=[0xa800000000001000]:8).
  The `bne` branch at 0x60c targets 0x61c, is taken when a1(=[sym(the_console_port)]:8) != s0(=a0), and falls through when a1(=[sym(the_console_port)]:8) == s0(=a0).
  The `beq` branch at 0x614 targets 0x68c, is taken when s6(=0x53435241) == v0(=[0xa800000000001000]:8), and falls through when s6(=0x53435241) != v0(=[0xa800000000001000]:8).
  The `beq` branch at 0x61c targets 0x484 and is always taken.
  The `beq` branch at 0x634 targets 0x224 and is always taken.
  The `beq` branch at 0x63c targets 0x600, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x650 targets 0x600, is taken when a4(=0xfffffffffeeddead) != a5(=[[0xa800000000001020]:8]), and falls through when a4(=0xfffffffffeeddead) == a5(=[[0xa800000000001020]:8]).
  The `beq` branch at 0x65c targets 0x600, is taken when a5(=[[0xa800000000001020]:8+80]:8) == 0, and falls through when a5(=[[0xa800000000001020]:8+80]:8) != 0.
  The `beq` branch at 0x684 targets 0x600 and is always taken.
  The `beq` branch at 0x68c targets 0x61c, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x6a0 targets 0x61c, is taken when a7(=0xfffffffffeeddead) != t0(=[[0xa800000000001020]:8]), and falls through when a7(=0xfffffffffeeddead) == t0(=[[0xa800000000001020]:8]).
  The `beq` branch at 0x6ac targets 0x61c, is taken when a1(=[[0xa800000000001020]:8+80]:8) == 0, and falls through when a1(=[[0xa800000000001020]:8+80]:8) != 0.
  The `beq` branch at 0x6c4 targets 0x61c and is always taken.
  The return at 0x4d4 has v0 = ret(ioc3_write_ireg).

- `set_baud_ti` in `IP27/usr/cpu/sysgen/IP27boot/sduart.a(sio_ioc3.o)` at 0x6cc (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/sduart.a(sio_ioc3.o)`.
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

- `ioc3_serial_attach` in `IP27/usr/cpu/sysgen/IP27boot/sduart.a(sio_ioc3.o)` at 0xa58 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/sduart.a(sio_ioc3.o)`.
  Range: 0xa58-0xf14 (1212 bytes).
  It occupies 1212 bytes.
  The `sd` at 0xbac stores 8 bytes to ret(kmem_zalloc) +0x70.
  The `ld` at 0xbb0 loads 8 bytes from ret(kmem_zalloc) +0x50.
  4 such `ld` accesses load 8 bytes from ret(kmem_zalloc) +0x58, including `ld` at 0xbb4, `ld` at 0xbd8, `ld` at 0xc70.
  The `ld` at 0xbb8 loads 8 bytes from ret(kmem_zalloc) +0x38.
  The `sd` at 0xbc0 stores 8 bytes to ret(kmem_zalloc) +0x48.
  The `sd` at 0xbcc stores 8 bytes to ret(kmem_zalloc) +0x40.
  The `sd` at 0xbe4 stores 8 bytes to ret(kmem_zalloc) +0x68.
  The `sd` at 0xbf0 stores 8 bytes to ret(kmem_zalloc) +0x60.
  4 such `lw` accesses load 4 bytes from ret(kmem_zalloc) +0x34, including `lw` at 0xbfc, `lw` at 0xc10, `lw` at 0xc1c.
  The `sd` at 0xc6c stores 8 bytes to ret(kmem_zalloc) +0x118.
  The `sd` at 0xc74 stores 8 bytes to ret(kmem_zalloc) +0x100.
  The `ld` at 0xc78 loads 8 bytes from ret(kmem_zalloc) +0xe0.
  The `ld` at 0xc7c loads 8 bytes from ret(kmem_zalloc) +0xf8.
  The `sd` at 0xc84 stores 8 bytes to ret(kmem_zalloc) +0xe8.
  The `sd` at 0xc90 stores 8 bytes to ret(kmem_zalloc) +0xf0.
  The `sd` at 0xc9c stores 8 bytes to ret(kmem_zalloc) +0x108.
  The `sd` at 0xca8 stores 8 bytes to ret(kmem_zalloc) +0x110.
  4 such `lw` accesses load 4 bytes from ret(kmem_zalloc) +0xdc, including `lw` at 0xcb4, `lw` at 0xcc8, `lw` at 0xce4.
  6 such `sw` accesses store 4 bytes to ?, including `sw` at 0xd34, `sw` at 0xdbc, `sw` at 0xdc4.
  5 such `sd` accesses store 8 bytes to ?, including `sd` at 0xd60, `sd` at 0xd6c, `sd` at 0xd7c.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0xd94, `ld` at 0xd9c.
  The `lw` at 0xdf0 loads 4 bytes from ?.
  2 such `sb` accesses store 1 byte to ret(kmem_zalloc) +0x1d, including `sb` at 0xe1c, `sb` at 0xe9c.
  The `sd` at 0xf00 stores 8 bytes to ret(kmem_zalloc) +0x58.
  The `jal` at 0xa64 calls ioc3_subdev_enabled with a0=a0 at entry (arg0), a1=0x4, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa8c calls ioc3_subdev_enabled with a0=a0 at entry (arg0), a1=0x4, a2=?, a3=?.
  The `jal` at 0xab0 calls ioc3_subdev_enabled with a0=a0 at entry (arg0), a1=0x5, a2=?, a3=?.
  The `jal` at 0xaec calls pciio_piotrans_addr with a0=a0 at entry (arg0), a1=0x0, a2=0x8, a3=0x0, a4=0x20180, a5=0x0.
  The `jal` at 0xaf8 calls ioc3_is_console with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xb10 calls hwgraph_traverse with a0=a0 at entry (arg0), a1=sym(.rodata), a2=sp-12, a3=?.
  The `jal` at 0xb24 calls hwgraph_traverse with a0=a0 at entry (arg0), a1=sym(.rodata), a2=sp-176, a3=?.
  The `jal` at 0xb2c calls hwgraph_fastinfo_get with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xb3c calls kmem_zalloc with a0=0x150, a1=0x0, a2=?, a3=?.
  The `jal` at 0xb9c calls ioc3_subdev_enabled with a0=a0 at entry (arg0), a1=0x4, a2=?, a3=?.
  The `jal` at 0xbd0 calls bzero with a0=?, a1=0x4000, a2=?, a3=?.
  The `jal` at 0xbec calls hardware_init with a0=ret(kmem_zalloc), a1=ret(ioc3_is_console), a2=?, a3=?, a6=[ret(kmem_zalloc)+88]:8+4096.
  The `jal` at 0xc00 calls hwgraph_edge_get with a0=[ret(kmem_zalloc)+52], a1=sym(.rodata), a2=sp-140, a3=?.
  The `jal` at 0xc2c calls ioc3_intr_connect with a0=a0 at entry (arg0), a1=0x1ff, a2=sym(ioc3_serial_intr), a3=ret(kmem_zalloc), a4=[ret(kmem_zalloc)+52], a6=0x0.
  The `jal` at 0xc40 calls device_controller_num_set with a0=[ret(kmem_zalloc)+52], a1=0x1, a2=?, a3=?.
  The `jal` at 0xc48 calls sio_make_hwgraph_nodes with a0=ret(kmem_zalloc), a1=?, a2=?, a3=?.
  The `jal` at 0xc5c calls ioc3_subdev_enabled with a0=a0 at entry (arg0), a1=0x5, a2=?, a3=?.
  The `jal` at 0xca4 calls hardware_init with a0=?, a1=0x0, a2=[ret(kmem_zalloc)+88]:8+8192, a3=[ret(kmem_zalloc)+88]:8+12288, a4=[ret(kmem_zalloc)+248]:8+368, a5=[ret(kmem_zalloc)+224]:8+212, a6=sym(.data).
  The `jal` at 0xcb8 calls hwgraph_edge_get with a0=[ret(kmem_zalloc)+220], a1=sym(.rodata), a2=sp-140, a3=?.
  The `jal` at 0xce8 calls ioc3_intr_connect with a0=a0 at entry (arg0), a1=0x3fe00, a2=sym(ioc3_serial_intr), a3=?, a4=[ret(kmem_zalloc)+220], a6=0x0.
  The `jal` at 0xcfc calls device_controller_num_set with a0=[ret(kmem_zalloc)+220], a1=0x2, a2=?, a3=?.
  The `jal` at 0xd04 calls sio_make_hwgraph_nodes with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xd58 calls device_inventory_add with a0=?, a1=0x4, a2=0x10, a3=-0x1, a4=0x0, a5=0x0.
  The `jal` at 0xdb0 calls hwgraph_path_add with a0=a0 at entry (arg0), a1=?, a2=sp-148, a3=?.
  The `jal` at 0xdd0 calls hwgraph_fastinfo_set with a0=?, a1=?, a2=?, a3=a0 at entry (arg0).
  The `jal` at 0xdf4 calls sio_initport with a0=?, a1=?, a2=0x1ff, a3=one of 0x0, 0x1.
  The `jal` at 0xe00 calls kmem_zalloc with a0=0x28, a1=0x0, a2=?, a3=?.
  The `jal` at 0xe20 calls sio_init_locks with a0=ret(kmem_zalloc), a1=?, a2=one of 0x2, 0x3, a3=?.
  The `jal` at 0xe44 calls hwgraph_edge_get with a0=?, a1=sym(.rodata), a2=sp-144, a3=?, a4=0x2580.
  The `jal` at 0xe68 calls kopt_find with a0=sym(.rodata), a1=?, a2=?, a3=0x1.
  The `jal` at 0xe78 calls atoi with a0=ret(kopt_find), a1=?, a2=0x1, a3=?.
  The `jal` at 0xeb0 calls ioc3_subdev_enabled with a0=a0 at entry (arg0), a1=0x5, a2=?, a3=?.
  The `jal` at 0xed8 calls printf with a0=sym(.rodata), a1=?, a2=0x1, a3=?.
  The `jal` at 0xef0 calls kvpalloc with a0=0x1, a1=0x100, a2=0x0, a3=?, a4=[ret(kmem_zalloc)+56]:8+184, a5=[ret(kmem_zalloc)+80]:8+376.
  The `jal` at 0xf04 calls panic with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `beq` branch at 0xa80 targets 0xeac, is taken when v0(=ret(ioc3_subdev_enabled)) == 0, and falls through when v0(=ret(ioc3_subdev_enabled)) != 0.
  The `beq` branch at 0xa9c targets 0xec8, is taken when v0(=ret(ioc3_subdev_enabled)) == 0, and falls through when v0(=ret(ioc3_subdev_enabled)) != 0.
  The `beq` branch at 0xab8 targets 0xad0, is taken when v0(=ret(ioc3_subdev_enabled)) == 0, and falls through when v0(=ret(ioc3_subdev_enabled)) != 0.
  The `bne` branch at 0xb5c targets 0xb80, is taken when s5(=one of -0x1, 0x0, 0x1) < s0(=one of -0x1, 0x0, 0x1) (signed), and falls through when s5(=one of -0x1, 0x0, 0x1) >= s0(=one of -0x1, 0x0, 0x1) (signed).
  The `beq` branch at 0xb78 targets 0xd80 and is always taken.
  The `beq` branch at 0xba4 targets 0xc58, is taken when v0(=ret(ioc3_subdev_enabled)) == 0, and falls through when v0(=ret(ioc3_subdev_enabled)) != 0.
  The `beq` branch at 0xbc8 targets 0xee8, is taken when a0(=[ret(kmem_zalloc)+88]:8) == 0, and falls through when a0(=[ret(kmem_zalloc)+88]:8) != 0.
  The `beq` branch at 0xc08 targets 0xc18, is taken when v0(=ret(hwgraph_edge_get)) == 0, and falls through when v0(=ret(hwgraph_edge_get)) != 0.
  The `beq` branch at 0xc34 targets 0xc58, is taken when s3(=ret(ioc3_is_console)) == 0, and falls through when s3(=ret(ioc3_is_console)) != 0.
  The `beq` branch at 0xc64 targets 0xd0c, is taken when v0(=ret(ioc3_subdev_enabled)) == 0, and falls through when v0(=ret(ioc3_subdev_enabled)) != 0.
  The `beq` branch at 0xcc0 targets 0xcd0, is taken when v0(=ret(hwgraph_edge_get)) == 0, and falls through when v0(=ret(hwgraph_edge_get)) != 0.
  The `beq` branch at 0xcf0 targets 0xd10, is taken when s3(=ret(ioc3_is_console)) == 0, and falls through when s3(=ret(ioc3_is_console)) != 0.
  The `beq` branch at 0xd3c targets 0xed0, is taken when s0(?) == a2(=0x1), and falls through when s0(?) != a2(=0x1).
  The `bne` branch at 0xd78 targets 0xb80, is taken when s5(=one of -0x1, 0x0, 0x1) < s0(?) (signed), and falls through when s5(=one of -0x1, 0x0, 0x1) >= s0(?) (signed).
  The `beq` branch at 0xdd8 targets 0xdec, is taken when s3(=ret(ioc3_is_console)) == 0, and falls through when s3(=ret(ioc3_is_console)) != 0.
  The `beq` branch at 0xde0 targets 0xe90, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0xe08 targets 0xe18, is taken when s3(=ret(ioc3_is_console)) == 0, and falls through when s3(=ret(ioc3_is_console)) != 0.
  The `beq` branch at 0xe10 targets 0xe98, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0xe30 targets 0xd44, is taken when s3(=ret(ioc3_is_console)) == 0, and falls through when s3(=ret(ioc3_is_console)) != 0.
  The `beq` branch at 0xe54 targets 0xea0, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `bne` branch at 0xe5c targets 0xd44, is taken when s0(?) != a3(=0x1), and falls through when s0(?) == a3(=0x1).
  The `beq` branch at 0xe70 targets 0xd3c, is taken when v0(=ret(kopt_find)) == 0, and falls through when v0(=ret(kopt_find)) != 0.
  The `bgtz` branch at 0xe80 targets 0xd34, is taken when v0(=ret(atoi)) > 0 (signed), and falls through when v0(=ret(atoi)) <= 0 (signed).
  The `beq` branch at 0xe88 targets 0xd3c and is always taken.
  The `beq` branch at 0xe90 targets 0xdf0 and is always taken.
  The `beq` branch at 0xe98 targets 0xe20 and is always taken.
  The `beq` branch at 0xea4 targets 0xe68 and is always taken.
  The `bne` branch at 0xeb8 targets 0xa8c, is taken when v0(=ret(ioc3_subdev_enabled)) != 0, and falls through when v0(=ret(ioc3_subdev_enabled)) == 0.
  The `beq` branch at 0xec0 targets 0xd10 and is always taken.
  The `beq` branch at 0xec8 targets 0xaac and is always taken.
  The `beq` branch at 0xed0 targets 0xee0, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0xee0 targets 0xd44 and is always taken.
  The `bne` branch at 0xefc targets 0xbd0, is taken when v0(=ret(kvpalloc)) != 0, and falls through when v0(=ret(kvpalloc)) == 0.
  The `beq` branch at 0xf0c targets 0xbd0 and is always taken.
  The return at 0xd2c has v0 = one of -0x1, 0x0.

- `ioc3_serial_kill` in `IP27/usr/cpu/sysgen/IP27boot/sduart.a(sio_ioc3.o)` at 0xf14 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/sduart.a(sio_ioc3.o)`.
  Range: 0xf14-0x1028 (276 bytes).
  It occupies 276 bytes.
  The `ld` at 0xf14 loads 8 bytes from a0 (arg0 at entry) +0x8.
  The `ld` at 0xf2c loads 8 bytes from [a0+8]:8 +0x28.
  2 such `ld` accesses load 8 bytes from abs 0xa800000000001000, including `ld` at 0xf50, `ld` at 0xfa4.
  3 such `ld` accesses load 8 bytes from abs 0xa800000000001020, including `ld` at 0xf54, `ld` at 0xf98, `ld` at 0x1008.
  2 such `lw` accesses load 4 bytes from [0xa800000000001020]:8 +0x0, including `lw` at 0xf68, `lw` at 0xfbc.
  3 such `ld` accesses load 8 bytes from [0xa800000000001020]:8 +0x50, including `ld` at 0xf74, `ld` at 0xfc8, `ld` at 0x100c.
  The `ld` at 0xf80 loads 8 bytes from a0 (arg0 at entry) +0x40.
  The `sw` at 0xf88 stores 4 bytes to [a0+64]:8 +0x0.
  The `sw` at 0xfec stores 4 bytes to a0 (arg0 at entry) +0x94.
  The `jalr` at 0xf30 calls (unknown callee) with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0xfd8 calls (unknown callee) with a0=0x1, a1=[a0+64]:8, a2=[[0xa800000000001020]:8], a3=[[0xa800000000001020]:8+80]:8, a4=[sym(.sbss)], a5=[sym(the_console_port)]:8.
  The `jal` at 0xfe0 calls splx with a0=[sym(.sbss)], a1=?, a2=?, a3=?.
  The `jal` at 0xffc calls spl7 with a0=0xa800000000001020, a1=?, a2=?, a3=[0xa800000000001000]:8, a4=0x53435241, a5=[[0xa800000000001020]:8], a6=0xfffffffffeeddead, a7=[[0xa800000000001020]:8+80]:8.
  The `jalr` at 0x1014 calls (unknown callee) with a0=0x0, a1=?, a2=?, a3=?, a5=[[0xa800000000001020]:8+80]:8.
  The `beq` branch at 0xf24 targets 0xf38, is taken when v0(=[a0+8]:8) == 0, and falls through when v0(=[a0+8]:8) != 0.
  The `bne` branch at 0xf4c targets 0xf80, is taken when a5(=[sym(the_console_port)]:8) != s0(=a0), and falls through when a5(=[sym(the_console_port)]:8) == s0(=a0).
  The `bne` branch at 0xf58 targets 0xf80, is taken when a3(=[0xa800000000001000]:8) != a4(=0x53435241), and falls through when a3(=[0xa800000000001000]:8) == a4(=0x53435241).
  The `beq` branch at 0xf60 targets 0xf80, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0xf6c targets 0xf80, is taken when a5(=[[0xa800000000001020]:8]) != a6(=0xfffffffffeeddead), and falls through when a5(=[[0xa800000000001020]:8]) == a6(=0xfffffffffeeddead).
  The `bne` branch at 0xf78 targets 0xffc, is taken when a7(=[[0xa800000000001020]:8+80]:8) != 0, and falls through when a7(=[[0xa800000000001020]:8+80]:8) == 0.
  The `bne` branch at 0xfa0 targets 0xfe8, is taken when a5(=[sym(the_console_port)]:8) != s0(=a0), and falls through when a5(=[sym(the_console_port)]:8) == s0(=a0).
  The `bne` branch at 0xfa8 targets 0xfec, is taken when a3(=[0xa800000000001000]:8) != a0(=0x53435241), and falls through when a3(=[0xa800000000001000]:8) == a0(=0x53435241).
  The `beq` branch at 0xfb0 targets 0xfec, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0xfc0 targets 0xfec, is taken when a2(=[[0xa800000000001020]:8]) != a3(=0xfffffffffeeddead), and falls through when a2(=[[0xa800000000001020]:8]) == a3(=0xfffffffffeeddead).
  The `beq` branch at 0xfcc targets 0xfe8, is taken when a3(=[[0xa800000000001020]:8+80]:8) == 0, and falls through when a3(=[[0xa800000000001020]:8+80]:8) != 0.
  The `beq` branch at 0x1020 targets 0xf80 and is always taken.
  The return at 0xff4 has v0 = one of [0xa800000000001020]:8, ?.

- `ioc3_open` in `IP27/usr/cpu/sysgen/IP27boot/sduart.a(sio_ioc3.o)` at 0x1028 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/sduart.a(sio_ioc3.o)`.
  Range: 0x1028-0x12cc (676 bytes).
  It occupies 676 bytes.
  The `sb` at 0x1028 stores 1 byte to a0 (arg0 at entry) +0x7c.
  4 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x94, including `lw` at 0x102c, `lw` at 0x1158, `lw` at 0x1284.
  The `sw` at 0x1030 stores 4 bytes to a0 (arg0 at entry) +0x78.
  4 such `ld` accesses load 8 bytes from abs 0xa800000000001000, including `ld` at 0x1060, `ld` at 0x10e0, `ld` at 0x117c.
  6 such `ld` accesses load 8 bytes from abs 0xa800000000001020, including `ld` at 0x1074, `ld` at 0x10f4, `ld` at 0x1188.
  4 such `lw` accesses load 4 bytes from [0xa800000000001020]:8 +0x0, including `lw` at 0x1080, `lw` at 0x1100, `lw` at 0x119c.
  6 such `ld` accesses load 8 bytes from [0xa800000000001020]:8 +0x50, including `ld` at 0x108c, `ld` at 0x110c, `ld` at 0x11a8.
  4 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x40, including `ld` at 0x1098, `ld` at 0x10a8, `ld` at 0x11b4.
  2 such `sw` accesses store 4 bytes to [a0+64]:8 +0x0, including `sw` at 0x10a4, `sw` at 0x11b8.
  2 such `lw` accesses load 4 bytes from [a0+64]:8 +0x0, including `lw` at 0x10ac, `lw` at 0x1238.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x48, including `ld` at 0x1134, `ld` at 0x114c.
  The `sb` at 0x1148 stores 1 byte to [a0+72]:8 +0x2.
  The `sb` at 0x1154 stores 1 byte to [a0+72]:8 +0x3.
  The `sw` at 0x116c stores 4 bytes to a0 (arg0 at entry) +0x94.
  The `sw` at 0x1214 stores 4 bytes to [a0+64]:8 +0x14.
  The `sw` at 0x1220 stores 4 bytes to a0 (arg0 at entry) +0x84.
  The `jalr` at 0x111c calls (unknown callee) with a0=0x1, a1=0xfffffffffeeddead, a2=[sym(.sbss)], a3=[[0xa800000000001020]:8+80]:8, a4=0xf4240, a5=0x40000000, a7=([a0+148] | 0x20000000).
  The `jal` at 0x1124 calls splx with a0=[sym(.sbss)], a1=?, a2=?, a3=?.
  The `jal` at 0x1144 calls set_baud_ti with a0=a0 at entry (arg0), a1=0x2580, a2=?, a3=0x3, a4=[a0+72]:8.
  The `jalr` at 0x1200 calls (unknown callee) with a0=0x1, a1=?, a2=?, a3=[[0xa800000000001020]:8+80]:8.
  The `jal` at 0x1208 calls splx with a0=[sym(.sbss)], a1=?, a2=?, a3=?.
  The `jal` at 0x1264 calls spl7 with a0=0xa800000000001020, a1=[0xa800000000001000]:8, a2=[[0xa800000000001020]:8], a3=[a0+148], a4=0xfffffffffeeddead, a5=[[0xa800000000001020]:8+80]:8.
  The `jalr` at 0x127c calls (unknown callee) with a0=0x0, a1=?, a2=?, a3=?, a7=[[0xa800000000001020]:8+80]:8.
  The `jal` at 0x1290 calls spl7 with a0=0x53435241, a1=?, a2=?, a3=?, a4=[0xa800000000001000]:8, a5=[sym(the_console_port)]:8, a6=0x3, a7=[a0+72]:8.
  The `jalr` at 0x12a4 calls (unknown callee) with a0=0x0, a1=?, a2=?, a3=?.
  The `bgez` branch at 0x1048 targets 0x1134, is taken when at(=([a0+148] << 0x23)) >= 0 (signed), and falls through when at(=([a0+148] << 0x23)) < 0 (signed).
  The `bne` branch at 0x1054 targets 0x1098, is taken when v1(=[sym(the_console_port)]:8) != a0, and falls through when v1(=[sym(the_console_port)]:8) == a0.
  The `bne` branch at 0x1070 targets 0x1098, is taken when a1(=[0xa800000000001000]:8) != a2(=0x53435241), and falls through when a1(=[0xa800000000001000]:8) == a2(=0x53435241).
  The `beq` branch at 0x1078 targets 0x1098, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x1084 targets 0x1098, is taken when a2(=[[0xa800000000001020]:8]) != a4(=0xfffffffffeeddead), and falls through when a2(=[[0xa800000000001020]:8]) == a4(=0xfffffffffeeddead).
  The `bne` branch at 0x1090 targets 0x1264, is taken when a5(=[[0xa800000000001020]:8+80]:8) != 0, and falls through when a5(=[[0xa800000000001020]:8+80]:8) == 0.
  The `bltz` branch at 0x10bc targets 0x10cc, is taken when a6(=([[a0+64]:8] << 0x21)) < 0 (signed), and falls through when a6(=([[a0+64]:8] << 0x21)) >= 0 (signed).
  The `beq` branch at 0x10c4 targets 0x12bc and is always taken.
  The `bne` branch at 0x10d4 targets 0x112c, is taken when t0(=[sym(the_console_port)]:8) != s0(=a0), and falls through when t0(=[sym(the_console_port)]:8) == s0(=a0).
  The `bne` branch at 0x10f0 targets 0x112c, is taken when v1(=[0xa800000000001000]:8) != a0(=0x53435241), and falls through when v1(=[0xa800000000001000]:8) == a0(=0x53435241).
  The `beq` branch at 0x10f8 targets 0x112c, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x1104 targets 0x112c, is taken when a0(=[[0xa800000000001020]:8]) != a1(=0xfffffffffeeddead), and falls through when a0(=[[0xa800000000001020]:8]) == a1(=0xfffffffffeeddead).
  The `beq` branch at 0x1110 targets 0x112c, is taken when a3(=[[0xa800000000001020]:8+80]:8) == 0, and falls through when a3(=[[0xa800000000001020]:8+80]:8) != 0.
  The `beq` branch at 0x112c targets 0x125c, is taken when s1(=one of 0x0, 0x1) == 0, and falls through when s1(=one of 0x0, 0x1) != 0.
  The `bne` branch at 0x1184 targets 0x11b4, is taken when a5(=[sym(the_console_port)]:8) != s0(=a0), and falls through when a5(=[sym(the_console_port)]:8) == s0(=a0).
  The `bne` branch at 0x118c targets 0x11b4, is taken when a4(=[0xa800000000001000]:8) != a0(=0x53435241), and falls through when a4(=[0xa800000000001000]:8) == a0(=0x53435241).
  The `beq` branch at 0x1194 targets 0x11b4, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x11a0 targets 0x11b4, is taken when t0(=[[0xa800000000001020]:8]) != t1(=0xfffffffffeeddead), and falls through when t0(=[[0xa800000000001020]:8]) == t1(=0xfffffffffeeddead).
  The `bne` branch at 0x11ac targets 0x1290, is taken when t2(=[[0xa800000000001020]:8+80]:8) != 0, and falls through when t2(=[[0xa800000000001020]:8+80]:8) == 0.
  The `bne` branch at 0x11c0 targets 0x1210, is taken when t3(=[sym(the_console_port)]:8) != s0(=a0), and falls through when t3(=[sym(the_console_port)]:8) == s0(=a0).
  The `bne` branch at 0x11d4 targets 0x1210, is taken when t9(=[0xa800000000001000]:8) != ra(=0x53435241), and falls through when t9(=[0xa800000000001000]:8) == ra(=0x53435241).
  The `beq` branch at 0x11e0 targets 0x1210, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x11ec targets 0x1210, is taken when v1(=[[0xa800000000001020]:8]) != a0(=0xfffffffffeeddead), and falls through when v1(=[[0xa800000000001020]:8]) == a0(=0xfffffffffeeddead).
  The `beq` branch at 0x11f8 targets 0x1210, is taken when a3(=[[0xa800000000001020]:8+80]:8) == 0, and falls through when a3(=[[0xa800000000001020]:8+80]:8) != 0.
  The `bne` branch at 0x1244 targets 0x10cc, is taken when (a3(=[[a0+64]:8]) & a5(=0x40000000)) != 0, and falls through when (a3(=[[a0+64]:8]) & a5(=0x40000000)) == 0.
  The `beq` branch at 0x124c targets 0x1238, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `beq` branch at 0x1254 targets 0x10d4 and is always taken.
  The `beq` branch at 0x125c targets 0x1224 and is always taken.
  The `beq` branch at 0x1288 targets 0x1098 and is always taken.
  The `beq` branch at 0x12b4 targets 0x11b4 and is always taken.
  The `beq` branch at 0x12c4 targets 0x124c and is always taken.
  The return at 0x1230 has v0 = one of -0x1, 0x0.

- `ioc3_config` in `IP27/usr/cpu/sysgen/IP27boot/sduart.a(sio_ioc3.o)` at 0x12cc (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/sduart.a(sio_ioc3.o)`.
  Range: 0x12cc-0x1660 (916 bytes).
  It occupies 916 bytes.
  4 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x94, including `lw` at 0x134c, `lw` at 0x1484, `lw` at 0x1614.
  4 such `ld` accesses load 8 bytes from abs 0xa800000000001000, including `ld` at 0x1368, `ld` at 0x13e8, `ld` at 0x14a4.
  6 such `ld` accesses load 8 bytes from abs 0xa800000000001020, including `ld` at 0x137c, `ld` at 0x13fc, `ld` at 0x14b8.
  4 such `lw` accesses load 4 bytes from [0xa800000000001020]:8 +0x0, including `lw` at 0x1388, `lw` at 0x1408, `lw` at 0x14c4.
  6 such `ld` accesses load 8 bytes from [0xa800000000001020]:8 +0x50, including `ld` at 0x1394, `ld` at 0x1414, `ld` at 0x14d0.
  3 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x40, including `ld` at 0x13a0, `ld` at 0x13b0, `ld` at 0x14dc.
  2 such `sw` accesses store 4 bytes to [a0+64]:8 +0x0, including `sw` at 0x13ac, `sw` at 0x14e0.
  2 such `lw` accesses load 4 bytes from [a0+64]:8 +0x0, including `lw` at 0x13b4, `lw` at 0x159c.
  The `ld` at 0x1444 loads 8 bytes from a0 (arg0 at entry) +0x48.
  The `lbu` at 0x1448 loads 1 byte from [a0+72]:8 +0x3.
  The `sb` at 0x1480 stores 1 byte to [a0+72]:8 +0x3.
  The `sw` at 0x157c stores 4 bytes to a0 (arg0 at entry) +0x80.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x84, including `sw` at 0x1584, `sw` at 0x15c8.
  The `lw` at 0x1590 loads 4 bytes from a0 (arg0 at entry) +0x88.
  The `jal` at 0x12f0 calls set_baud_ti with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x1428 calls (unknown callee) with a0=0x1, a1=[[0xa800000000001020]:8], a2=[[0xa800000000001020]:8+80]:8, a3=[sym(.sbss)], a7=0x40000000.
  The `jal` at 0x1430 calls splx with a0=[sym(.sbss)], a1=?, a2=?, a3=?.
  The `jalr` at 0x1534 calls (unknown callee) with a0=0x1, a1=0xfffffffffeeddead, a2=[[0xa800000000001020]:8+80]:8, a3=a1 at entry (arg1).
  The `jal` at 0x153c calls splx with a0=[sym(.sbss)], a1=?, a2=?, a3=?.
  The `jal` at 0x158c calls ioc3_rx_timeout with a0=a0 at entry (arg0), a1=[a0+136], a2=?, a3=a1 at entry (arg1), a6=0xa.
  The `jal` at 0x15f4 calls spl7 with a0=[a0+148], a1=([a0+148] << 0x23), a2=0xa800000000001020, a3=[0xa800000000001000]:8, a4=[[0xa800000000001020]:8], a5=0xfffffffffeeddead, a6=[[0xa800000000001020]:8+80]:8.
  The `jalr` at 0x160c calls (unknown callee) with a0=0x0, a1=?, a2=?, a3=?.
  The `jal` at 0x1624 calls spl7 with a0=[a0+148], a1=?, a2=[a0+72]:8, a3=?, a4=[sym(the_console_port)]:8, a5=[0xa800000000001000]:8, a6=[[0xa800000000001020]:8], a7=0xfffffffffeeddead.
  The `jalr` at 0x1638 calls (unknown callee) with a0=0x0, a1=?, a2=?, a3=?.
  The `beq` branch at 0x12f8 targets 0x1314, is taken when v0(=ret(set_baud_ti)) == 0, and falls through when v0(=ret(set_baud_ti)) != 0.
  The `beq` branch at 0x1318 targets 0x1348, is taken when s1(=a2) == at(=0x5), and falls through when s1(=a2) != at(=0x5).
  The `beq` branch at 0x1320 targets 0x15cc, is taken when s1(=a2) == v0(=0x6), and falls through when s1(=a2) != v0(=0x6).
  The `beq` branch at 0x1328 targets 0x15d4, is taken when s1(=a2) == v1(=0x7), and falls through when s1(=a2) != v1(=0x7).
  The `beq` branch at 0x1330 targets 0x1340, is taken when s1(=a2) == a0(=0x8), and falls through when s1(=a2) != a0(=0x8).
  The `beq` branch at 0x1338 targets 0x1300 and is always taken.
  The `beq` branch at 0x1340 targets 0x134c and is always taken.
  The `bgez` branch at 0x1354 targets 0x1444, is taken when a1(=([a0+148] << 0x23)) >= 0 (signed), and falls through when a1(=([a0+148] << 0x23)) < 0 (signed).
  The `bne` branch at 0x135c targets 0x13a0, is taken when a2(=[sym(the_console_port)]:8) != s0(=a0), and falls through when a2(=[sym(the_console_port)]:8) == s0(=a0).
  The `bne` branch at 0x1378 targets 0x13a0, is taken when a3(=[0xa800000000001000]:8) != a4(=0x53435241), and falls through when a3(=[0xa800000000001000]:8) == a4(=0x53435241).
  The `beq` branch at 0x1380 targets 0x13a0, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x138c targets 0x13a0, is taken when a4(=[[0xa800000000001020]:8]) != a5(=0xfffffffffeeddead), and falls through when a4(=[[0xa800000000001020]:8]) == a5(=0xfffffffffeeddead).
  The `bne` branch at 0x1398 targets 0x15f4, is taken when a6(=[[0xa800000000001020]:8+80]:8) != 0, and falls through when a6(=[[0xa800000000001020]:8+80]:8) == 0.
  The `bltz` branch at 0x13bc targets 0x13d4, is taken when a7(=([[a0+64]:8] << 0x21)) < 0 (signed), and falls through when a7(=([[a0+64]:8] << 0x21)) >= 0 (signed).
  The `beq` branch at 0x13cc targets 0x1650 and is always taken.
  The `bne` branch at 0x13dc targets 0x143c, is taken when a1(=[sym(the_console_port)]:8) != s0(=a0), and falls through when a1(=[sym(the_console_port)]:8) == s0(=a0).
  The `bne` branch at 0x13f8 targets 0x143c, is taken when v1(=[0xa800000000001000]:8) != a1(=0x53435241), and falls through when v1(=[0xa800000000001000]:8) == a1(=0x53435241).
  The `beq` branch at 0x1400 targets 0x143c, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x140c targets 0x143c, is taken when a1(=[[0xa800000000001020]:8]) != a2(=0xfffffffffeeddead), and falls through when a1(=[[0xa800000000001020]:8]) == a2(=0xfffffffffeeddead).
  The `beq` branch at 0x1418 targets 0x143c, is taken when a2(=[[0xa800000000001020]:8+80]:8) == 0, and falls through when a2(=[[0xa800000000001020]:8+80]:8) != 0.
  The `beq` branch at 0x143c targets 0x15ec, is taken when a0(=one of 0x0, 0x1) == 0, and falls through when a0(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x1458 targets 0x1470, is taken when v1(=a4) == 0, and falls through when v1(=a4) != 0.
  The `beq` branch at 0x1468 targets 0x15dc, is taken when a0(=a5) == 0, and falls through when a0(=a5) != 0.
  The `beq` branch at 0x1474 targets 0x1480, is taken when a1(=a3) == 0, and falls through when a1(=a3) != 0.
  The `beq` branch at 0x1490 targets 0x1544, is taken when (a3(=0x10000000) & a0(=[a0+148])) == 0, and falls through when (a3(=0x10000000) & a0(=[a0+148])) != 0.
  The `bne` branch at 0x1498 targets 0x14dc, is taken when a4(=[sym(the_console_port)]:8) != s0(=a0), and falls through when a4(=[sym(the_console_port)]:8) == s0(=a0).
  The `bne` branch at 0x14b4 targets 0x14dc, is taken when a5(=[0xa800000000001000]:8) != a6(=0x53435241), and falls through when a5(=[0xa800000000001000]:8) == a6(=0x53435241).
  The `beq` branch at 0x14bc targets 0x14dc, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x14c8 targets 0x14dc, is taken when a6(=[[0xa800000000001020]:8]) != a7(=0xfffffffffeeddead), and falls through when a6(=[[0xa800000000001020]:8]) == a7(=0xfffffffffeeddead).
  The `bne` branch at 0x14d4 targets 0x1624, is taken when t0(=[[0xa800000000001020]:8+80]:8) != 0, and falls through when t0(=[[0xa800000000001020]:8+80]:8) == 0.
  The `bne` branch at 0x14e8 targets 0x1548, is taken when t1(=[sym(the_console_port)]:8) != s0(=a0), and falls through when t1(=[sym(the_console_port)]:8) == s0(=a0).
  The `bne` branch at 0x1508 targets 0x1544, is taken when v1(=[0xa800000000001000]:8) != a0(=0x53435241), and falls through when v1(=[0xa800000000001000]:8) == a0(=0x53435241).
  The `beq` branch at 0x1510 targets 0x1548, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x151c targets 0x1548, is taken when a0(=[[0xa800000000001020]:8]) != a1(=0xfffffffffeeddead), and falls through when a0(=[[0xa800000000001020]:8]) == a1(=0xfffffffffeeddead).
  The `beq` branch at 0x1528 targets 0x1548, is taken when a2(=[[0xa800000000001020]:8+80]:8) == 0, and falls through when a2(=[[0xa800000000001020]:8+80]:8) != 0.
  The `beq` branch at 0x1580 targets 0x15c0, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0x1594 targets 0x1300 and is always taken.
  The `bne` branch at 0x15a8 targets 0x13d4, is taken when (t0(=[[a0+64]:8]) & a7(=0x40000000)) != 0, and falls through when (t0(=[[a0+64]:8]) & a7(=0x40000000)) == 0.
  The `beq` branch at 0x15b0 targets 0x159c, is taken when t1(?) == 0, and falls through when t1(?) != 0.
  The `beq` branch at 0x15b8 targets 0x13d8 and is always taken.
  The `beq` branch at 0x15c4 targets 0x1588 and is always taken.
  The `beq` branch at 0x15cc targets 0x134c and is always taken.
  The `beq` branch at 0x15d4 targets 0x134c and is always taken.
  The `bne` branch at 0x15dc targets 0x147c, is taken when t3(=a3) != 0, and falls through when t3(=a3) == 0.
  The `beq` branch at 0x15e4 targets 0x1480 and is always taken.
  The `beq` branch at 0x15ec targets 0x1300 and is always taken.
  The `beq` branch at 0x161c targets 0x13a0 and is always taken.
  The `beq` branch at 0x1648 targets 0x14dc and is always taken.
  The `beq` branch at 0x1658 targets 0x15b0 and is always taken.
  The return at 0x130c has v0 = one of -0x1, 0x0, 0x1.

- `ioc3_enable_hfc` in `IP27/usr/cpu/sysgen/IP27boot/sduart.a(sio_ioc3.o)` at 0x1660 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/sduart.a(sio_ioc3.o)`.
  Range: 0x1660-0x1784 (292 bytes).
  It occupies 292 bytes.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x94, including `lw` at 0x1664, `lw` at 0x1774.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x94, including `sw` at 0x167c, `sw` at 0x174c.
  2 such `ld` accesses load 8 bytes from abs 0xa800000000001000, including `ld` at 0x1698, `ld` at 0x16ec.
  3 such `ld` accesses load 8 bytes from abs 0xa800000000001020, including `ld` at 0x169c, `ld` at 0x16e0, `ld` at 0x175c.
  2 such `lw` accesses load 4 bytes from [0xa800000000001020]:8 +0x0, including `lw` at 0x16b0, `lw` at 0x1700.
  3 such `ld` accesses load 8 bytes from [0xa800000000001020]:8 +0x50, including `ld` at 0x16bc, `ld` at 0x170c, `ld` at 0x1760.
  The `ld` at 0x16c8 loads 8 bytes from a0 (arg0 at entry) +0x40.
  The `sw` at 0x16d0 stores 4 bytes to [a0+64]:8 +0x0.
  The `jalr` at 0x171c calls (unknown callee) with a0=0x1, a1=[sym(the_console_port)]:8, a2=?, a3=[[0xa800000000001020]:8+80]:8, a5=0xa800000000001020, a6=[a0+64]:8, a7=[[0xa800000000001020]:8].
  The `jal` at 0x1724 calls splx with a0=[sym(.sbss)], a1=?, a2=?, a3=?.
  The `jal` at 0x1750 calls spl7 with a0=[0xa800000000001000]:8, a1=[sym(the_console_port)]:8, a2=a2 at entry (arg2), a3=0x53435241, a5=[[0xa800000000001020]:8], a6=0xfffffffffeeddead, a7=[[0xa800000000001020]:8+80]:8.
  The `jalr` at 0x1768 calls (unknown callee) with a0=0x0, a1=?, a2=?, a3=?.
  The `beq` branch at 0x1670 targets 0x1740, is taken when a1 == 0, and falls through when a1 != 0.
  The `bne` branch at 0x1694 targets 0x16c8, is taken when a1(=[sym(the_console_port)]:8) != s0(=a0), and falls through when a1(=[sym(the_console_port)]:8) == s0(=a0).
  The `bne` branch at 0x16a0 targets 0x16c8, is taken when a0(=[0xa800000000001000]:8) != a3(=0x53435241), and falls through when a0(=[0xa800000000001000]:8) == a3(=0x53435241).
  The `beq` branch at 0x16a8 targets 0x16c8, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x16b4 targets 0x16c8, is taken when a5(=[[0xa800000000001020]:8]) != a6(=0xfffffffffeeddead), and falls through when a5(=[[0xa800000000001020]:8]) == a6(=0xfffffffffeeddead).
  The `bne` branch at 0x16c0 targets 0x1750, is taken when a7(=[[0xa800000000001020]:8+80]:8) != 0, and falls through when a7(=[[0xa800000000001020]:8+80]:8) == 0.
  The `bne` branch at 0x16e8 targets 0x1730, is taken when a1(=[sym(the_console_port)]:8) != s0(=a0), and falls through when a1(=[sym(the_console_port)]:8) == s0(=a0).
  The `bne` branch at 0x16f0 targets 0x1730, is taken when a0(=[0xa800000000001000]:8) != a3(=0x53435241), and falls through when a0(=[0xa800000000001000]:8) == a3(=0x53435241).
  The `beq` branch at 0x16f8 targets 0x1730, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x1704 targets 0x1730, is taken when a7(=[[0xa800000000001020]:8]) != t0(=0xfffffffffeeddead), and falls through when a7(=[[0xa800000000001020]:8]) == t0(=0xfffffffffeeddead).
  The `beq` branch at 0x1710 targets 0x1730, is taken when a3(=[[0xa800000000001020]:8+80]:8) == 0, and falls through when a3(=[[0xa800000000001020]:8+80]:8) != 0.
  The `beq` branch at 0x1748 targets 0x1680 and is always taken.
  The `beq` branch at 0x177c targets 0x16c8 and is always taken.
  The return at 0x1738 has v0 = 0x0.

- `ioc3_set_extclk` in `IP27/usr/cpu/sysgen/IP27boot/sduart.a(sio_ioc3.o)` at 0x1784 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/sduart.a(sio_ioc3.o)`.
  Range: 0x1784-0x178c (8 bytes).
  It occupies 8 bytes.
  The return at 0x1784 has v0 = a1.

- `do_ioc3_write` in `IP27/usr/cpu/sysgen/IP27boot/sduart.a(sio_ioc3.o)` at 0x178c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/sduart.a(sio_ioc3.o)`.
  Range: 0x178c-0x1a08 (636 bytes).
  It occupies 636 bytes.
  3 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x40, including `ld` at 0x178c, `ld` at 0x1908, `ld` at 0x1978.
  The `ld` at 0x1790 loads 8 bytes from a0 (arg0 at entry) +0x68.
  The `lw` at 0x1794 loads 4 bytes from [a0+64]:8 +0x8.
  The `ld` at 0x1798 loads 8 bytes from a0 (arg0 at entry) +0x70.
  The `lw` at 0x17a8 loads 4 bytes from a0 (arg0 at entry) +0x98.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x78, including `lw` at 0x17e4, `lw` at 0x186c, `lw` at 0x19d0.
  The `sw` at 0x17fc stores 4 bytes to a0 (arg0 at entry) +0x98.
  3 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x1828, `lbu` at 0x1850, `lbu` at 0x19b8.
  5 such `sb` accesses store 1 byte to ?, including `sb` at 0x1830, `sb` at 0x183c, `sb` at 0x1858.
  The `sw` at 0x189c stores 4 bytes to ?.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x94, including `lw` at 0x18b0, `lw` at 0x19f8.
  The `sw` at 0x18c0 stores 4 bytes to a0 (arg0 at entry) +0x94.
  2 such `ld` accesses load 8 bytes from abs 0xa800000000001000, including `ld` at 0x18d8, `ld` at 0x1924.
  3 such `ld` accesses load 8 bytes from abs 0xa800000000001020, including `ld` at 0x18e4, `ld` at 0x1930, `ld` at 0x19e0.
  2 such `lw` accesses load 4 bytes from [0xa800000000001020]:8 +0x0, including `lw` at 0x18f0, `lw` at 0x193c.
  3 such `ld` accesses load 8 bytes from [0xa800000000001020]:8 +0x50, including `ld` at 0x18fc, `ld` at 0x194c, `ld` at 0x19e4.
  The `sw` at 0x190c stores 4 bytes to [a0+64]:8 +0x0.
  The `sw` at 0x1980 stores 4 bytes to [a0+64]:8 +0x4.
  The `lw` at 0x198c loads 4 bytes from [a0+112]:8 +0x8.
  The `lw` at 0x1998 loads 4 bytes from a0 (arg0 at entry) +0x84.
  The `sw` at 0x19b4 stores 4 bytes to a0 (arg0 at entry) +0x78.
  The `jalr` at 0x1960 calls (unknown callee) with a0=0x1, a1=[[0xa800000000001020]:8+80]:8, a2=[sym(.sbss)], a3=?.
  The `jal` at 0x1968 calls splx with a0=[sym(.sbss)], a1=?, a2=?, a3=?.
  The `jal` at 0x1988 calls enable_intrs with a0=a0 at entry (arg0), a1=[[a0+112]:8+8], a2=?, a3=[a0+64]:8.
  The `jal` at 0x19d4 calls spl7 with a0=(0x10000000 | [a0+148]), a1=0xa800000000001020, a2=0xfffffffffeeddead, a3=[[0xa800000000001020]:8+80]:8, a6=([a0+148] << 0x23), a7=0x40.
  The `jalr` at 0x19ec calls (unknown callee) with a0=0x0, a1=?, a2=?, a3=?.
  The `beq` branch at 0x17c8 targets 0x17e0, is taken when a6(?) == s2(=[a0+152]), and falls through when a6(?) != s2(=[a0+152]).
  The `blez` branch at 0x17d0 targets 0x19c8, is taken when a2 <= 0 (signed), and falls through when a2 > 0 (signed).
  The `beq` branch at 0x17d8 targets 0x1890 and is always taken.
  The `beq` branch at 0x17ec targets 0x1978, is taken when (a7(=[a0+120]) & 0x10) == 0, and falls through when (a7(=[a0+120]) & 0x10) != 0.
  The `blez` branch at 0x1810 targets 0x186c, is taken when a2(?) <= 0 (signed), and falls through when a2(?) > 0 (signed).
  The `beq` branch at 0x1840 targets 0x186c, is taken when v0(?) >= 0x4 (signed), and falls through when v0(?) < 0x4 (signed).
  The `blez` branch at 0x1848 targets 0x186c, is taken when a2(?) <= 0 (signed), and falls through when a2(?) > 0 (signed).
  The `bne` branch at 0x1864 targets 0x1810, is taken when a4(?) != 0, and falls through when a4(?) == 0.
  The `beq` branch at 0x1874 targets 0x1998, is taken when (v0(=[a0+120]) & 0x4) == 0, and falls through when (v0(=[a0+120]) & 0x4) != 0.
  The `beq` branch at 0x1880 targets 0x18a8, is taken when a6(?) == s2(?), and falls through when a6(?) != s2(?).
  The `blez` branch at 0x1888 targets 0x18a8, is taken when a2(?) <= 0 (signed), and falls through when a2(?) > 0 (signed).
  The `blez` branch at 0x1898 targets 0x186c, is taken when a2(?) <= 0 (signed), and falls through when a2(?) > 0 (signed).
  The `beq` branch at 0x18a0 targets 0x1818 and is always taken.
  The `blez` branch at 0x18a8 targets 0x17e4, is taken when s0(?) <= 0 (signed), and falls through when s0(?) > 0 (signed).
  The `bltz` branch at 0x18b8 targets 0x17e4, is taken when a6(=([a0+148] << 0x23)) < 0 (signed), and falls through when a6(=([a0+148] << 0x23)) >= 0 (signed).
  The `bne` branch at 0x18d4 targets 0x1908, is taken when a3(=[sym(the_console_port)]:8) != s1(=a0), and falls through when a3(=[sym(the_console_port)]:8) == s1(=a0).
  The `bne` branch at 0x18dc targets 0x1908, is taken when a1(=[0xa800000000001000]:8) != v0(=0x53435241), and falls through when a1(=[0xa800000000001000]:8) == v0(=0x53435241).
  The `beq` branch at 0x18e8 targets 0x1908, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x18f4 targets 0x1908, is taken when v1(=[[0xa800000000001020]:8]) != a2(=0xfffffffffeeddead), and falls through when v1(=[[0xa800000000001020]:8]) == a2(=0xfffffffffeeddead).
  The `bne` branch at 0x1900 targets 0x19d4, is taken when a3(=[[0xa800000000001020]:8+80]:8) != 0, and falls through when a3(=[[0xa800000000001020]:8+80]:8) == 0.
  The `bne` branch at 0x1920 targets 0x17e4, is taken when v1(=[sym(the_console_port)]:8) != s1(=a0), and falls through when v1(=[sym(the_console_port)]:8) == s1(=a0).
  The `bne` branch at 0x1928 targets 0x17e4, is taken when v0(=[0xa800000000001000]:8) != a1(=0x53435241), and falls through when v0(=[0xa800000000001000]:8) == a1(=0x53435241).
  The `beq` branch at 0x1934 targets 0x17e4, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x1944 targets 0x17e4, is taken when v1(=[[0xa800000000001020]:8]) != a0(=0xfffffffffeeddead), and falls through when v1(=[[0xa800000000001020]:8]) == a0(=0xfffffffffeeddead).
  The `beq` branch at 0x1950 targets 0x17e4, is taken when a1(=[[0xa800000000001020]:8+80]:8) == 0, and falls through when a1(=[[0xa800000000001020]:8+80]:8) != 0.
  The `beq` branch at 0x1970 targets 0x17e4 and is always taken.
  The `blez` branch at 0x197c targets 0x17f0, is taken when s0(?) <= 0 (signed), and falls through when s0(?) > 0 (signed).
  The `beq` branch at 0x1990 targets 0x17f4 and is always taken.
  The `bne` branch at 0x19ac targets 0x187c, is taken when a4(=([a0+132] << 0x3)) < a5(?) (signed), and falls through when a4(=([a0+132] << 0x3)) >= a5(?) (signed).
  The `beq` branch at 0x19c0 targets 0x187c and is always taken.
  The `beq` branch at 0x19cc targets 0x17e8 and is always taken.
  The `beq` branch at 0x1a00 targets 0x1908 and is always taken.
  The return at 0x1808 has v0 = ?.

- `ioc3_write` in `IP27/usr/cpu/sysgen/IP27boot/sduart.a(sio_ioc3.o)` at 0x1a08 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/sduart.a(sio_ioc3.o)`.
  Range: 0x1a08-0x1a24 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x1a10 calls do_ioc3_write with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x1a1c has v0 = ret(do_ioc3_write).

- `ioc3_sync_write` in `IP27/usr/cpu/sysgen/IP27boot/sduart.a(sio_ioc3.o)` at 0x1a24 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/sduart.a(sio_ioc3.o)`.
  Range: 0x1a24-0x1a84 (96 bytes).
  It occupies 96 bytes.
  The `lw` at 0x1a50 loads 4 bytes from a0 (arg0 at entry) +0x78.
  The `jal` at 0x1a38 calls do_ioc3_write with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1a64 calls ioc3_enable_tx with a0=a0 at entry (arg0), a1=0x1, a2=?, a3=?.
  The `blez` branch at 0x1a40 targets 0x1a6c, is taken when s3(=a2) <= 0 (signed), and falls through when s3(=a2) > 0 (signed).
  The `bne` branch at 0x1a48 targets 0x1a6c, is taken when v0(=ret(do_ioc3_write)) != 0, and falls through when v0(=ret(do_ioc3_write)) == 0.
  The `beq` branch at 0x1a58 targets 0x1a70, is taken when (at(=[a0+120]) & 0x10) == 0, and falls through when (at(=[a0+120]) & 0x10) != 0.
  The return at 0x1a7c has v0 = ret(do_ioc3_write).

- `ioc3_wrflush` in `IP27/usr/cpu/sysgen/IP27boot/sduart.a(sio_ioc3.o)` at 0x1a84 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/sduart.a(sio_ioc3.o)`.
  Range: 0x1a84-0x1b48 (196 bytes).
  It occupies 196 bytes.
  3 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x38, including `ld` at 0x1a84, `ld` at 0x1ac0, `ld` at 0x1b08.
  3 such `lw` accesses load 4 bytes from [a0+56]:8 +0x1c, including `lw` at 0x1a88, `lw` at 0x1ac4, `lw` at 0x1b0c.
  3 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x40, including `ld` at 0x1aa4, `ld` at 0x1afc, `ld` at 0x1b24.
  2 such `lw` accesses load 4 bytes from [a0+64]:8 +0x0, including `lw` at 0x1aa8, `lw` at 0x1b28.
  The `lw` at 0x1ae0 loads 4 bytes from a0 (arg0 at entry) +0x78.
  The `jal` at 0x1af0 calls ioc3_enable_tx with a0=a0 at entry (arg0), a1=0x1, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1b1c calls us_delay with a0=0x5, a1=?, a2=one of 0x10000000, 0x50000000, a3=?.
  The `beq` branch at 0x1a9c targets 0x1ae0, is taken when (at(=[[a0+56]:8+28]) & 0x1) == 0, and falls through when (at(=[[a0+56]:8+28]) & 0x1) != 0.
  The `bne` branch at 0x1ab8 targets 0x1ad4, is taken when a0(=0x10000000) != v0(?), and falls through when a0(=0x10000000) == v0(?).
  The `beq` branch at 0x1acc targets 0x1b00, is taken when (v1(=[[a0+56]:8+28]) & 0x1) == 0, and falls through when (v1(=[[a0+56]:8+28]) & 0x1) != 0.
  The `beq` branch at 0x1ae8 targets 0x1aa4, is taken when (a0(=[a0+120]) & 0x10) == 0, and falls through when (a0(=[a0+120]) & 0x10) != 0.
  The `beq` branch at 0x1af8 targets 0x1aa8 and is always taken.
  The `beq` branch at 0x1b00 targets 0x1b1c and is always taken.
  The `bne` branch at 0x1b14 targets 0x1b40, is taken when (a1(=[[a0+56]:8+28]) & 0x1) != 0, and falls through when (a1(=[[a0+56]:8+28]) & 0x1) == 0.
  The `beq` branch at 0x1b38 targets 0x1b08, is taken when a2(=0x10000000) == a3(?), and falls through when a2(=0x10000000) != a3(?).
  The `beq` branch at 0x1b40 targets 0x1ad4 and is always taken.
  The return at 0x1ad8 has v0 = one of ?, ret(us_delay).

- `ioc3_break` in `IP27/usr/cpu/sysgen/IP27boot/sduart.a(sio_ioc3.o)` at 0x1b48 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/sduart.a(sio_ioc3.o)`.
  Range: 0x1b48-0x1dec (676 bytes).
  It occupies 676 bytes.
  4 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x94, including `lw` at 0x1b48, `lw` at 0x1c74, `lw` at 0x1d9c.
  4 such `ld` accesses load 8 bytes from abs 0xa800000000001000, including `ld` at 0x1b7c, `ld` at 0x1c08, `ld` at 0x1c90.
  6 such `ld` accesses load 8 bytes from abs 0xa800000000001020, including `ld` at 0x1b90, `ld` at 0x1c0c, `ld` at 0x1ca4.
  4 such `lw` accesses load 4 bytes from [0xa800000000001020]:8 +0x0, including `lw` at 0x1b9c, `lw` at 0x1c20, `lw` at 0x1cb0.
  6 such `ld` accesses load 8 bytes from [0xa800000000001020]:8 +0x50, including `ld` at 0x1ba8, `ld` at 0x1c2c, `ld` at 0x1cbc.
  3 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x40, including `ld` at 0x1bb4, `ld` at 0x1bc4, `ld` at 0x1cc8.
  2 such `sw` accesses store 4 bytes to [a0+64]:8 +0x0, including `sw` at 0x1bc0, `sw` at 0x1ccc.
  2 such `lw` accesses load 4 bytes from [a0+64]:8 +0x0, including `lw` at 0x1bc8, `lw` at 0x1d44.
  The `ld` at 0x1c60 loads 8 bytes from a0 (arg0 at entry) +0x48.
  The `lbu` at 0x1c68 loads 1 byte from [a0+72]:8 +0x3.
  2 such `sb` accesses store 1 byte to [a0+72]:8 +0x3, including `sb` at 0x1c70, `sb` at 0x1d74.
  The `jalr` at 0x1c40 calls (unknown callee) with a0=0x1, a1=a1 at entry (arg1), a2=[[0xa800000000001020]:8], a3=0xfffffffffeeddead, a4=[[0xa800000000001020]:8+80]:8, a5=[sym(.sbss)], a6=0x10000000, a7=[sym(the_console_port)]:8.
  The `jal` at 0x1c48 calls splx with a0=[sym(.sbss)], a1=?, a2=?, a3=?.
  The `jalr` at 0x1d1c calls (unknown callee) with a0=0x1, a1=?, a2=?, a3=?, a4=[[0xa800000000001020]:8+80]:8.
  The `jal` at 0x1d24 calls splx with a0=[sym(.sbss)], a1=?, a2=?, a3=?.
  The `jal` at 0x1d80 calls spl7 with a0=[a0+72]:8, a1=a1 at entry (arg1), a2=?, a3=?, a4=[a0+148], a6=0x10000000.
  The `jalr` at 0x1d94 calls (unknown callee) with a0=0x0, a1=?, a2=?, a3=?, a5=[[0xa800000000001020]:8+80]:8.
  The `jal` at 0x1dac calls spl7 with a0=[[0xa800000000001020]:8], a1=a1 at entry (arg1), a2=0xfffffffffeeddead, a3=[[0xa800000000001020]:8+80]:8, a4=[a0+148], a6=0x10000000.
  The `jalr` at 0x1dc0 calls (unknown callee) with a0=0x0, a1=?, a2=?, a3=?, a7=[[0xa800000000001020]:8+80]:8.
  The `bgez` branch at 0x1b64 targets 0x1c60, is taken when at(=([a0+148] << 0x23)) >= 0 (signed), and falls through when at(=([a0+148] << 0x23)) < 0 (signed).
  The `bne` branch at 0x1b70 targets 0x1bb4, is taken when v0(=[sym(the_console_port)]:8) != a0, and falls through when v0(=[sym(the_console_port)]:8) == a0.
  The `bne` branch at 0x1b8c targets 0x1bb4, is taken when v1(=[0xa800000000001000]:8) != a0(=0x53435241), and falls through when v1(=[0xa800000000001000]:8) == a0(=0x53435241).
  The `beq` branch at 0x1b94 targets 0x1bb4, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x1ba0 targets 0x1bb4, is taken when a0(=[[0xa800000000001020]:8]) != a2(=0xfffffffffeeddead), and falls through when a0(=[[0xa800000000001020]:8]) == a2(=0xfffffffffeeddead).
  The `bne` branch at 0x1bac targets 0x1dac, is taken when a3(=[[0xa800000000001020]:8+80]:8) != 0, and falls through when a3(=[[0xa800000000001020]:8+80]:8) == 0.
  The `bltz` branch at 0x1bdc targets 0x1bec, is taken when t0(=([[a0+64]:8] << 0x21)) < 0 (signed), and falls through when t0(=([[a0+64]:8] << 0x21)) >= 0 (signed).
  The `beq` branch at 0x1be4 targets 0x1de0 and is always taken.
  The `bne` branch at 0x1c04 targets 0x1c58, is taken when a7(=[sym(the_console_port)]:8) != s0(=a0), and falls through when a7(=[sym(the_console_port)]:8) == s0(=a0).
  The `bne` branch at 0x1c10 targets 0x1c58, is taken when a4(=[0xa800000000001000]:8) != a0(=0x53435241), and falls through when a4(=[0xa800000000001000]:8) == a0(=0x53435241).
  The `beq` branch at 0x1c18 targets 0x1c58, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x1c24 targets 0x1c58, is taken when a2(=[[0xa800000000001020]:8]) != a3(=0xfffffffffeeddead), and falls through when a2(=[[0xa800000000001020]:8]) == a3(=0xfffffffffeeddead).
  The `beq` branch at 0x1c30 targets 0x1c58, is taken when a4(=[[0xa800000000001020]:8+80]:8) == 0, and falls through when a4(=[[0xa800000000001020]:8+80]:8) != 0.
  The `beq` branch at 0x1c58 targets 0x1d78, is taken when s1(=one of 0x0, 0x1) == 0, and falls through when s1(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x1c64 targets 0x1d68, is taken when a1 == 0, and falls through when a1 != 0.
  The `beq` branch at 0x1c7c targets 0x1d2c, is taken when (a6(=0x10000000) & a4(=[a0+148])) == 0, and falls through when (a6(=0x10000000) & a4(=[a0+148])) != 0.
  The `bne` branch at 0x1c84 targets 0x1cc8, is taken when t1(=[sym(the_console_port)]:8) != s0(=a0), and falls through when t1(=[sym(the_console_port)]:8) == s0(=a0).
  The `bne` branch at 0x1ca0 targets 0x1cc8, is taken when t2(=[0xa800000000001000]:8) != t3(=0x53435241), and falls through when t2(=[0xa800000000001000]:8) == t3(=0x53435241).
  The `beq` branch at 0x1ca8 targets 0x1cc8, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x1cb4 targets 0x1cc8, is taken when t3(=[[0xa800000000001020]:8]) != t8(=0xfffffffffeeddead), and falls through when t3(=[[0xa800000000001020]:8]) == t8(=0xfffffffffeeddead).
  The `bne` branch at 0x1cc0 targets 0x1d80, is taken when t9(=[[0xa800000000001020]:8+80]:8) != 0, and falls through when t9(=[[0xa800000000001020]:8+80]:8) == 0.
  The `bne` branch at 0x1cd4 targets 0x1d30, is taken when ra(=[sym(the_console_port)]:8) != s0(=a0), and falls through when ra(=[sym(the_console_port)]:8) == s0(=a0).
  The `bne` branch at 0x1cec targets 0x1d30, is taken when v0(=[0xa800000000001000]:8) != v1(=0x53435241), and falls through when v0(=[0xa800000000001000]:8) == v1(=0x53435241).
  The `beq` branch at 0x1cfc targets 0x1d2c, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x1d08 targets 0x1d2c, is taken when v1(=[[0xa800000000001020]:8]) != a0(=0xfffffffffeeddead), and falls through when v1(=[[0xa800000000001020]:8]) == a0(=0xfffffffffeeddead).
  The `beq` branch at 0x1d14 targets 0x1d2c, is taken when a4(=[[0xa800000000001020]:8+80]:8) == 0, and falls through when a4(=[[0xa800000000001020]:8+80]:8) != 0.
  The `bne` branch at 0x1d50 targets 0x1bec, is taken when (a2(=[[a0+64]:8]) & a7(=0x40000000)) != 0, and falls through when (a2(=[[a0+64]:8]) & a7(=0x40000000)) == 0.
  The `beq` branch at 0x1d58 targets 0x1d44, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0x1d60 targets 0x1bf4 and is always taken.
  The `beq` branch at 0x1d70 targets 0x1c74 and is always taken.
  The `beq` branch at 0x1d78 targets 0x1d30 and is always taken.
  The `beq` branch at 0x1da4 targets 0x1cc8 and is always taken.
  The `beq` branch at 0x1dd8 targets 0x1bb4 and is always taken.
  The `beq` branch at 0x1de4 targets 0x1d58 and is always taken.
  The return at 0x1d3c has v0 = one of -0x1, 0x0.

- `ioc3_enable_tx` in `IP27/usr/cpu/sysgen/IP27boot/sduart.a(sio_ioc3.o)` at 0x1dec (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/sduart.a(sio_ioc3.o)`.
  Range: 0x1dec-0x1ffc (528 bytes).
  It occupies 528 bytes.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x78, including `lw` at 0x1df8, `lw` at 0x1ec4.
  The `ld` at 0x1e00 loads 8 bytes from a0 (arg0 at entry) +0x70.
  2 such `ld` accesses load 8 bytes from abs 0xa800000000001000, including `ld` at 0x1e2c, `ld` at 0x1f0c.
  3 such `ld` accesses load 8 bytes from abs 0xa800000000001020, including `ld` at 0x1e30, `ld` at 0x1f10, `ld` at 0x1fd8.
  2 such `lw` accesses load 4 bytes from [0xa800000000001020]:8 +0x0, including `lw` at 0x1e44, `lw` at 0x1f34.
  3 such `ld` accesses load 8 bytes from [0xa800000000001020]:8 +0x50, including `ld` at 0x1e50, `ld` at 0x1f40, `ld` at 0x1fdc.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x94, including `lw` at 0x1e5c, `lw` at 0x1ee8.
  4 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x40, including `ld` at 0x1e68, `ld` at 0x1e78, `ld` at 0x1f00.
  2 such `sw` accesses store 4 bytes to [a0+64]:8 +0x0, including `sw` at 0x1e74, `sw` at 0x1f04.
  2 such `lw` accesses load 4 bytes from [a0+64]:8 +0x0, including `lw` at 0x1e7c, `lw` at 0x1eac.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x98, including `lw` at 0x1ec8, `lw` at 0x1fa4.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x78, including `sw` at 0x1ed4, `sw` at 0x1f8c.
  2 such `sw` accesses store 4 bytes to [a0+64]:8 +0x4, including `sw` at 0x1ed8, `sw` at 0x1fc0.
  2 such `lw` accesses load 4 bytes from [a0+112]:8 +0x8, including `lw` at 0x1ee4, `lw` at 0x1f94.
  The `lw` at 0x1f84 loads 4 bytes from [a0+64]:8 +0x8.
  The `jal` at 0x1ee0 calls enable_intrs with a0=a0 at entry (arg0), a1=[[a0+112]:8+8], a2=?, a3=?, a4=[a0+64]:8.
  The `jalr` at 0x1f4c calls (unknown callee) with a0=0x1, a1=[[0xa800000000001020]:8+80]:8, a2=[sym(the_console_port)]:8, a3=[[0xa800000000001020]:8], a4=0xfffffffffeeddead, a5=0xa800000000001000.
  The `jal` at 0x1f54 calls splx with a0=[sym(.sbss)], a1=?, a2=?, a3=?.
  The `jal` at 0x1f9c calls disable_intrs with a0=a0 at entry (arg0), a1=[[a0+112]:8+8], a2=?, a3=?, a4=[a0+64]:8, a6=([a0+120] | 0x10).
  The `jal` at 0x1fcc calls spl7 with a0=0x53435241, a1=a1 at entry (arg1), a2=[[0xa800000000001020]:8], a3=0xfffffffffeeddead, a4=[[0xa800000000001020]:8+80]:8, a5=0xa800000000001020, a6=[sym(the_console_port)]:8.
  The `jalr` at 0x1fe4 calls (unknown callee) with a0=0x0, a1=?, a2=?, a3=?.
  The `beq` branch at 0x1e08 targets 0x1f74, is taken when a1 == 0, and falls through when a1 != 0.
  The `beq` branch at 0x1e10 targets 0x1f7c, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `bne` branch at 0x1e28 targets 0x1e5c, is taken when a6(=[sym(the_console_port)]:8) != s0(=a0), and falls through when a6(=[sym(the_console_port)]:8) == s0(=a0).
  The `bne` branch at 0x1e34 targets 0x1e5c, is taken when a4(=[0xa800000000001000]:8) != a0(=0x53435241), and falls through when a4(=[0xa800000000001000]:8) == a0(=0x53435241).
  The `beq` branch at 0x1e3c targets 0x1e5c, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x1e48 targets 0x1e5c, is taken when a2(=[[0xa800000000001020]:8]) != a3(=0xfffffffffeeddead), and falls through when a2(=[[0xa800000000001020]:8]) == a3(=0xfffffffffeeddead).
  The `bne` branch at 0x1e54 targets 0x1fcc, is taken when a4(=[[0xa800000000001020]:8+80]:8) != 0, and falls through when a4(=[[0xa800000000001020]:8+80]:8) == 0.
  The `bgez` branch at 0x1e64 targets 0x1ec0, is taken when a5(=([a0+148] << 0x23)) >= 0 (signed), and falls through when a5(=([a0+148] << 0x23)) < 0 (signed).
  The `bltz` branch at 0x1e94 targets 0x1ec0, is taken when t0(=([[a0+64]:8] << 0x21)) < 0 (signed), and falls through when t0(=([[a0+64]:8] << 0x21)) >= 0 (signed).
  The `bne` branch at 0x1ea4 targets 0x1fc4, is taken when t2(?) != 0, and falls through when t2(?) == 0.
  The `beq` branch at 0x1eb8 targets 0x1ea4, is taken when (t3(=[[a0+64]:8]) & a6(=0x40000000)) == 0, and falls through when (t3(=[[a0+64]:8]) & a6(=0x40000000)) != 0.
  The `beq` branch at 0x1ec0 targets 0x1f84, is taken when a1 == 0, and falls through when a1 != 0.
  The `beq` branch at 0x1ef8 targets 0x1f08, is taken when (ra(=0x10000000) & a0(=[a0+148])) == 0, and falls through when (ra(=0x10000000) & a0(=[a0+148])) != 0.
  The `bne` branch at 0x1f1c targets 0x1f5c, is taken when a2(=[sym(the_console_port)]:8) != s0(=a0), and falls through when a2(=[sym(the_console_port)]:8) == s0(=a0).
  The `bne` branch at 0x1f24 targets 0x1f5c, is taken when a1(=[0xa800000000001000]:8) != a0(=0x53435241), and falls through when a1(=[0xa800000000001000]:8) == a0(=0x53435241).
  The `beq` branch at 0x1f2c targets 0x1f5c, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x1f38 targets 0x1f5c, is taken when a3(=[[0xa800000000001020]:8]) != a4(=0xfffffffffeeddead), and falls through when a3(=[[0xa800000000001020]:8]) == a4(=0xfffffffffeeddead).
  The `beq` branch at 0x1f44 targets 0x1f5c, is taken when a1(=[[0xa800000000001020]:8+80]:8) == 0, and falls through when a1(=[[0xa800000000001020]:8+80]:8) != 0.
  The `beq` branch at 0x1f74 targets 0x1e18, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x1f7c targets 0x1f60 and is always taken.
  The `beq` branch at 0x1fb0 targets 0x1ee8, is taken when a7(=[a0+152]) == v0(?), and falls through when a7(=[a0+152]) != v0(?).
  The `beq` branch at 0x1fbc targets 0x1ee8 and is always taken.
  The `beq` branch at 0x1fc4 targets 0x1f64 and is always taken.
  The `beq` branch at 0x1ff4 targets 0x1e5c and is always taken.
  The return at 0x1f6c has v0 = one of -0x1, 0x0.

- `ioc3_notification` in `IP27/usr/cpu/sysgen/IP27boot/sduart.a(sio_ioc3.o)` at 0x272c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/sduart.a(sio_ioc3.o)`.
  Range: 0x272c-0x292c (512 bytes).
  It occupies 512 bytes.
  The `ld` at 0x2734 loads 8 bytes from a0 (arg0 at entry) +0x70.
  The `lw` at 0x2758 loads 4 bytes from [a0+112]:8 +0x10.
  The `lw` at 0x275c loads 4 bytes from [a0+112]:8 +0xc.
  The `lw` at 0x2770 loads 4 bytes from [a0+112]:8 +0x14.
  The `lw` at 0x2784 loads 4 bytes from [a0+112]:8 +0x0.
  The `lw` at 0x279c loads 4 bytes from [a0+112]:8 +0x4.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x94, including `lw` at 0x27b0, `lw` at 0x28b8, `lw` at 0x2920.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x8c, including `lw` at 0x27b4, `lw` at 0x28c0.
  4 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x94, including `sw` at 0x27bc, `sw` at 0x27d8, `sw` at 0x28cc.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x8c, including `sw` at 0x27c4, `sw` at 0x28d8.
  2 such `ld` accesses load 8 bytes from abs 0xa800000000001000, including `ld` at 0x27f4, `ld` at 0x2848.
  3 such `ld` accesses load 8 bytes from abs 0xa800000000001020, including `ld` at 0x27f8, `ld` at 0x283c, `ld` at 0x290c.
  2 such `lw` accesses load 4 bytes from [0xa800000000001020]:8 +0x0, including `lw` at 0x280c, `lw` at 0x285c.
  3 such `ld` accesses load 8 bytes from [0xa800000000001020]:8 +0x50, including `ld` at 0x2818, `ld` at 0x2868, `ld` at 0x2910.
  The `ld` at 0x2824 loads 8 bytes from a0 (arg0 at entry) +0x40.
  The `sw` at 0x282c stores 4 bytes to [a0+64]:8 +0x0.
  The `lw` at 0x28dc loads 4 bytes from a0 (arg0 at entry) +0x90.
  The `lw` at 0x28e0 loads 4 bytes from [a0+112]:8 +0x8.
  The `jal` at 0x27a8 calls enable_intrs with a0=a0 at entry (arg0), a1=?, a2=a2 at entry (arg2), a3=?.
  The `jalr` at 0x2878 calls (unknown callee) with a0=0x1, a1=[[0xa800000000001020]:8+80]:8, a2=0x53435241, a3=[sym(the_console_port)]:8, a4=[[0xa800000000001020]:8], a5=0xfffffffffeeddead.
  The `jal` at 0x2880 calls splx with a0=[sym(.sbss)], a1=?, a2=?, a3=?.
  The `jal` at 0x28b0 calls disable_intrs with a0=a0 at entry (arg0), a1=?, a2=a2 at entry (arg2), a3=?.
  The `jal` at 0x2904 calls spl7 with a0=?, a1=0x53435241, a2=[[0xa800000000001020]:8], a3=0xfffffffffeeddead, a4=[[0xa800000000001020]:8+80]:8.
  The `jalr` at 0x2918 calls (unknown callee) with a0=0x0, a1=?, a2=?, a3=?, a5=[[0xa800000000001020]:8+80]:8.
  The `beq` branch at 0x2750 targets 0x2764, is taken when (a1 & 0x1) == 0, and falls through when (a1 & 0x1) != 0.
  The `beq` branch at 0x2768 targets 0x277c, is taken when (s1(=a1) & 0x2) == 0, and falls through when (s1(=a1) & 0x2) != 0.
  The `beq` branch at 0x277c targets 0x28fc, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `beq` branch at 0x2794 targets 0x28a8, is taken when (s1(=a1) & 0x80) == 0, and falls through when (s1(=a1) & 0x80) != 0.
  The `beq` branch at 0x27a0 targets 0x28b0, is taken when a2 == 0, and falls through when a2 != 0.
  The `beq` branch at 0x27cc targets 0x28dc, is taken when (v0(?) & 0x41) == 0, and falls through when (v0(?) & 0x41) != 0.
  The `bne` branch at 0x27f0 targets 0x2824, is taken when a3(=[sym(the_console_port)]:8) != s0(=a0), and falls through when a3(=[sym(the_console_port)]:8) == s0(=a0).
  The `bne` branch at 0x27fc targets 0x2824, is taken when a2(=[0xa800000000001000]:8) != a1(=0x53435241), and falls through when a2(=[0xa800000000001000]:8) == a1(=0x53435241).
  The `beq` branch at 0x2804 targets 0x2824, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x2810 targets 0x2824, is taken when a2(=[[0xa800000000001020]:8]) != a3(=0xfffffffffeeddead), and falls through when a2(=[[0xa800000000001020]:8]) == a3(=0xfffffffffeeddead).
  The `bne` branch at 0x281c targets 0x2904, is taken when a4(=[[0xa800000000001020]:8+80]:8) != 0, and falls through when a4(=[[0xa800000000001020]:8+80]:8) == 0.
  The `bne` branch at 0x2844 targets 0x2888, is taken when a3(=[sym(the_console_port)]:8) != s0(=a0), and falls through when a3(=[sym(the_console_port)]:8) == s0(=a0).
  The `bne` branch at 0x284c targets 0x288c, is taken when a1(=[0xa800000000001000]:8) != a2(=0x53435241), and falls through when a1(=[0xa800000000001000]:8) == a2(=0x53435241).
  The `beq` branch at 0x2854 targets 0x2888, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x2860 targets 0x288c, is taken when a4(=[[0xa800000000001020]:8]) != a5(=0xfffffffffeeddead), and falls through when a4(=[[0xa800000000001020]:8]) == a5(=0xfffffffffeeddead).
  The `beq` branch at 0x286c targets 0x288c, is taken when a1(=[[0xa800000000001020]:8+80]:8) == 0, and falls through when a1(=[[0xa800000000001020]:8+80]:8) != 0.
  The `bne` branch at 0x28a8 targets 0x27a8, is taken when a2 != 0, and falls through when a2 == 0.
  The `beq` branch at 0x28d4 targets 0x27c8 and is always taken.
  The `bne` branch at 0x28e8 targets 0x27dc, is taken when (a2(=[[a0+112]:8+8]) & a3(=[a0+144])) != 0, and falls through when (a2(=[[a0+112]:8+8]) & a3(=[a0+144])) == 0.
  The `beq` branch at 0x28f4 targets 0x27dc and is always taken.
  The `beq` branch at 0x28fc targets 0x2790 and is always taken.
  The `beq` branch at 0x2924 targets 0x2824 and is always taken.
  The return at 0x28a0 has v0 = 0x0.

- `ioc3_rx_timeout` in `IP27/usr/cpu/sysgen/IP27boot/sduart.a(sio_ioc3.o)` at 0x292c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/sduart.a(sio_ioc3.o)`.
  Range: 0x292c-0x2ae4 (440 bytes).
  It occupies 440 bytes.
  The `lw` at 0x292c loads 4 bytes from a0 (arg0 at entry) +0x80.
  The `sw` at 0x2990 stores 4 bytes to a0 (arg0 at entry) +0x88.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x94, including `lw` at 0x29a0, `lw` at 0x2ad4.
  The `sw` at 0x29b4 stores 4 bytes to a0 (arg0 at entry) +0x94.
  2 such `ld` accesses load 8 bytes from abs 0xa800000000001000, including `ld` at 0x29c0, `ld` at 0x2a1c.
  3 such `ld` accesses load 8 bytes from abs 0xa800000000001020, including `ld` at 0x29cc, `ld` at 0x2a10, `ld` at 0x2ac0.
  2 such `lw` accesses load 4 bytes from [0xa800000000001020]:8 +0x0, including `lw` at 0x29e0, `lw` at 0x2a30.
  3 such `ld` accesses load 8 bytes from [0xa800000000001020]:8 +0x50, including `ld` at 0x29ec, `ld` at 0x2a3c, `ld` at 0x2ac4.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x40, including `ld` at 0x29f8, `ld` at 0x2a84.
  The `sw` at 0x2a00 stores 4 bytes to [a0+64]:8 +0x0.
  The `sw` at 0x2aa0 stores 4 bytes to [a0+64]:8 +0x14.
  The `jalr` at 0x2a50 calls (unknown callee) with a0=0x1, a1=?, a2=?, a3=?, a4=[[0xa800000000001020]:8+80]:8, a5=0x53435241, a6=0xa800000000001020, a7=[sym(the_console_port)]:8.
  The `jal` at 0x2a58 calls splx with a0=[sym(.sbss)], a1=?, a2=?, a3=?.
  The `jal` at 0x2ab0 calls spl7 with a0=?, a1=a1 at entry (arg1), a2=-0x200, a3=[[0xa800000000001020]:8], a4=0xfffffffffeeddead, a5=[[0xa800000000001020]:8+80]:8, a6=0x53435241, a7=0x64.
  The `jalr` at 0x2ac8 calls (unknown callee) with a0=0x0, a1=?, a2=?, a3=?.
  The `beq` branch at 0x2994 targets 0x2aa4, is taken when a4(?) >= 0x200 (unsigned), and falls through when a4(?) < 0x200 (unsigned).
  The `bne` branch at 0x29c8 targets 0x29f8, is taken when t1(=[sym(the_console_port)]:8) != s0(=a0), and falls through when t1(=[sym(the_console_port)]:8) == s0(=a0).
  The `bne` branch at 0x29d0 targets 0x29f8, is taken when a5(=[0xa800000000001000]:8) != a6(=0x53435241), and falls through when a5(=[0xa800000000001000]:8) == a6(=0x53435241).
  The `beq` branch at 0x29d8 targets 0x29f8, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x29e4 targets 0x29f8, is taken when a3(=[[0xa800000000001020]:8]) != a4(=0xfffffffffeeddead), and falls through when a3(=[[0xa800000000001020]:8]) == a4(=0xfffffffffeeddead).
  The `bne` branch at 0x29f0 targets 0x2ab0, is taken when a5(=[[0xa800000000001020]:8+80]:8) != 0, and falls through when a5(=[[0xa800000000001020]:8+80]:8) == 0.
  The `bne` branch at 0x2a18 targets 0x2a64, is taken when a7(=[sym(the_console_port)]:8) != s0(=a0), and falls through when a7(=[sym(the_console_port)]:8) == s0(=a0).
  The `bne` branch at 0x2a20 targets 0x2a64, is taken when a4(=[0xa800000000001000]:8) != a5(=0x53435241), and falls through when a4(=[0xa800000000001000]:8) == a5(=0x53435241).
  The `beq` branch at 0x2a28 targets 0x2a64, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x2a34 targets 0x2a64, is taken when t0(=[[0xa800000000001020]:8]) != t1(=0xfffffffffeeddead), and falls through when t0(=[[0xa800000000001020]:8]) == t1(=0xfffffffffeeddead).
  The `beq` branch at 0x2a40 targets 0x2a64, is taken when a4(=[[0xa800000000001020]:8+80]:8) == 0, and falls through when a4(=[[0xa800000000001020]:8+80]:8) != 0.
  The `beq` branch at 0x2adc targets 0x29f8 and is always taken.
  The return at 0x2aa8 has v0 = one of 0x0, 0x1.

- `set_DTRRTS` in `IP27/usr/cpu/sysgen/IP27boot/sduart.a(sio_ioc3.o)` at 0x2ae4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/sduart.a(sio_ioc3.o)`.
  Range: 0x2ae4-0x2cb8 (468 bytes).
  It occupies 468 bytes.
  2 such `ld` accesses load 8 bytes from abs 0xa800000000001000, including `ld` at 0x2b18, `ld` at 0x2c0c.
  3 such `ld` accesses load 8 bytes from abs 0xa800000000001020, including `ld` at 0x2b1c, `ld` at 0x2c04, `ld` at 0x2c90.
  2 such `lw` accesses load 4 bytes from [0xa800000000001020]:8 +0x0, including `lw` at 0x2b30, `lw` at 0x2c20.
  3 such `ld` accesses load 8 bytes from [0xa800000000001020]:8 +0x50, including `ld` at 0x2b3c, `ld` at 0x2c2c, `ld` at 0x2c94.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x94, including `lw` at 0x2b4c, `lw` at 0x2be4.
  4 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x40, including `ld` at 0x2b60, `ld` at 0x2b84, `ld` at 0x2bdc.
  2 such `sw` accesses store 4 bytes to [a0+64]:8 +0x0, including `sw` at 0x2b80, `sw` at 0x2bf8.
  2 such `lw` accesses load 4 bytes from [a0+64]:8 +0x0, including `lw` at 0x2b88, `lw` at 0x2ba4.
  The `ld` at 0x2bb8 loads 8 bytes from a0 (arg0 at entry) +0x48.
  The `lw` at 0x2bbc loads 4 bytes from [a0+64]:8 +0x18.
  The `lbu` at 0x2bcc loads 1 byte from [a0+72]:8 +0x4.
  The `sb` at 0x2bd8 stores 1 byte to [a0+72]:8 +0x4.
  The `sw` at 0x2be0 stores 4 bytes to [a0+64]:8 +0x18.
  The `jalr` at 0x2c3c calls (unknown callee) with a0=0x1, a1=[[0xa800000000001020]:8+80]:8, a2=[a0+72]:8, a3=?, a7=[a0+148].
  The `jal` at 0x2c44 calls splx with a0=[sym(.sbss)], a1=?, a2=?, a3=?.
  The `jal` at 0x2c84 calls spl7 with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a6=0x53435241, a7=[[0xa800000000001020]:8].
  The `jalr` at 0x2c9c calls (unknown callee) with a0=0x0, a1=?, a2=?, a3=?, a5=[[0xa800000000001020]:8+80]:8.
  The `bne` branch at 0x2b14 targets 0x2b4c, is taken when t1(=[sym(the_console_port)]:8) != a0, and falls through when t1(=[sym(the_console_port)]:8) == a0.
  The `bne` branch at 0x2b20 targets 0x2b4c, is taken when a7(=[0xa800000000001000]:8) != a6(=0x53435241), and falls through when a7(=[0xa800000000001000]:8) == a6(=0x53435241).
  The `beq` branch at 0x2b28 targets 0x2b4c, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x2b34 targets 0x2b4c, is taken when a7(=[[0xa800000000001020]:8]) != t0(=0xfffffffffeeddead), and falls through when a7(=[[0xa800000000001020]:8]) == t0(=0xfffffffffeeddead).
  The `bne` branch at 0x2b44 targets 0x2c84, is taken when t1(=[[0xa800000000001020]:8+80]:8) != 0, and falls through when t1(=[[0xa800000000001020]:8+80]:8) == 0.
  The `bgez` branch at 0x2b70 targets 0x2bb8, is taken when t2(=([a0+148] << 0x23)) >= 0 (signed), and falls through when t2(=([a0+148] << 0x23)) < 0 (signed).
  The `bltz` branch at 0x2b90 targets 0x2bb8, is taken when a4(=([[a0+64]:8] << 0x21)) < 0 (signed), and falls through when a4(=([[a0+64]:8] << 0x21)) >= 0 (signed).
  The `bne` branch at 0x2b9c targets 0x2c7c, is taken when a7(?) != 0, and falls through when a7(?) == 0.
  The `beq` branch at 0x2bb0 targets 0x2b9c, is taken when (t2(=[[a0+64]:8]) & a3(=0x40000000)) == 0, and falls through when (t2(=[[a0+64]:8]) & a3(=0x40000000)) != 0.
  The `beq` branch at 0x2bc8 targets 0x2c68, is taken when a1 == 0, and falls through when a1 != 0.
  The `beq` branch at 0x2bec targets 0x2bfc, is taken when (t0(=0x10000000) & a7(=[a0+148])) == 0, and falls through when (t0(=0x10000000) & a7(=[a0+148])) != 0.
  The `bne` branch at 0x2c00 targets 0x2c50, is taken when at(=[sym(the_console_port)]:8) != s0(=a0), and falls through when at(=[sym(the_console_port)]:8) == s0(=a0).
  The `bne` branch at 0x2c10 targets 0x2c50, is taken when v1(=[0xa800000000001000]:8) != a0(=0x53435241), and falls through when v1(=[0xa800000000001000]:8) == a0(=0x53435241).
  The `beq` branch at 0x2c18 targets 0x2c50, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x2c24 targets 0x2c50, is taken when a0(=[[0xa800000000001020]:8]) != a1(=0xfffffffffeeddead), and falls through when a0(=[[0xa800000000001020]:8]) == a1(=0xfffffffffeeddead).
  The `beq` branch at 0x2c30 targets 0x2c50, is taken when a1(=[[0xa800000000001020]:8+80]:8) == 0, and falls through when a1(=[[0xa800000000001020]:8+80]:8) != 0.
  The `beq` branch at 0x2c74 targets 0x2bd8 and is always taken.
  The `beq` branch at 0x2c7c targets 0x2c58 and is always taken.
  The `beq` branch at 0x2cb0 targets 0x2b4c and is always taken.
  The return at 0x2c60 has v0 = one of -0x1, 0x0.

- `ioc3_set_DTR` in `IP27/usr/cpu/sysgen/IP27boot/sduart.a(sio_ioc3.o)` at 0x2cb8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/sduart.a(sio_ioc3.o)`.
  Range: 0x2cb8-0x2cd8 (32 bytes).
  It occupies 32 bytes.
  The `jal` at 0x2cc4 calls set_DTRRTS with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0x1, a3=0x1000000.
  The return at 0x2cd0 has v0 = ret(set_DTRRTS).

- `ioc3_set_RTS` in `IP27/usr/cpu/sysgen/IP27boot/sduart.a(sio_ioc3.o)` at 0x2cd8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/sduart.a(sio_ioc3.o)`.
  Range: 0x2cd8-0x2cf8 (32 bytes).
  It occupies 32 bytes.
  The `jal` at 0x2ce4 calls set_DTRRTS with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0x2, a3=0x2000000.
  The return at 0x2cf0 has v0 = ret(set_DTRRTS).

- `ioc3_query_DCD` in `IP27/usr/cpu/sysgen/IP27boot/sduart.a(sio_ioc3.o)` at 0x2cf8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/sduart.a(sio_ioc3.o)`.
  Range: 0x2cf8-0x2dfc (260 bytes).
  It occupies 260 bytes.
  2 such `ld` accesses load 8 bytes from abs 0xa800000000001000, including `ld` at 0x2d14, `ld` at 0x2d64.
  3 such `ld` accesses load 8 bytes from abs 0xa800000000001020, including `ld` at 0x2d18, `ld` at 0x2d6c, `ld` at 0x2dd0.
  2 such `lw` accesses load 4 bytes from [0xa800000000001020]:8 +0x0, including `lw` at 0x2d2c, `lw` at 0x2d78.
  3 such `ld` accesses load 8 bytes from [0xa800000000001020]:8 +0x50, including `ld` at 0x2d38, `ld` at 0x2d84, `ld` at 0x2dd4.
  The `ld` at 0x2d48 loads 8 bytes from a0 (arg0 at entry) +0x40.
  The `lw` at 0x2d5c loads 4 bytes from [a0+64]:8 +0x18.
  The `jalr` at 0x2d9c calls (unknown callee) with a0=0x1, a1=?, a2=?, a3=[[0xa800000000001020]:8+80]:8, a4=[[a0+64]:8+24], a5=0xa800000000001020, a6=[0xa800000000001000]:8, a7=[[0xa800000000001020]:8].
  The `jal` at 0x2da4 calls splx with a0=[sym(.sbss)], a1=?, a2=?, a3=?.
  The `jal` at 0x2dc4 calls spl7 with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=[sym(the_console_port)]:8, a4=0x53435241, a5=[[0xa800000000001020]:8], a6=0xfffffffffeeddead, a7=[[0xa800000000001020]:8+80]:8.
  The `jalr` at 0x2ddc calls (unknown callee) with a0=0x0, a1=?, a2=?, a3=?.
  The `bne` branch at 0x2d10 targets 0x2d48, is taken when a0 != a3(=[sym(the_console_port)]:8), and falls through when a0 == a3(=[sym(the_console_port)]:8).
  The `bne` branch at 0x2d1c targets 0x2d48, is taken when a5(=[0xa800000000001000]:8) != a4(=0x53435241), and falls through when a5(=[0xa800000000001000]:8) == a4(=0x53435241).
  The `beq` branch at 0x2d24 targets 0x2d48, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x2d30 targets 0x2d48, is taken when a5(=[[0xa800000000001020]:8]) != a6(=0xfffffffffeeddead), and falls through when a5(=[[0xa800000000001020]:8]) == a6(=0xfffffffffeeddead).
  The `bne` branch at 0x2d40 targets 0x2dc4, is taken when a7(=[[0xa800000000001020]:8+80]:8) != 0, and falls through when a7(=[[0xa800000000001020]:8+80]:8) == 0.
  The `bne` branch at 0x2d58 targets 0x2db4, is taken when a0 != a3(=[sym(the_console_port)]:8), and falls through when a0 == a3(=[sym(the_console_port)]:8).
  The `bne` branch at 0x2d68 targets 0x2db4, is taken when a6(=[0xa800000000001000]:8) != a7(=0x53435241), and falls through when a6(=[0xa800000000001000]:8) == a7(=0x53435241).
  The `beq` branch at 0x2d70 targets 0x2db4, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x2d7c targets 0x2db4, is taken when a7(=[[0xa800000000001020]:8]) != t0(=0xfffffffffeeddead), and falls through when a7(=[[0xa800000000001020]:8]) == t0(=0xfffffffffeeddead).
  The `beq` branch at 0x2d8c targets 0x2db4, is taken when a3(=[[0xa800000000001020]:8+80]:8) == 0, and falls through when a3(=[[0xa800000000001020]:8+80]:8) != 0.
  The `beq` branch at 0x2df4 targets 0x2d48 and is always taken.
  The return at 0x2dbc has v0 = ?.

- `ioc3_query_CTS` in `IP27/usr/cpu/sysgen/IP27boot/sduart.a(sio_ioc3.o)` at 0x2dfc (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/sduart.a(sio_ioc3.o)`.
  Range: 0x2dfc-0x2f00 (260 bytes).
  It occupies 260 bytes.
  2 such `ld` accesses load 8 bytes from abs 0xa800000000001000, including `ld` at 0x2e18, `ld` at 0x2e68.
  3 such `ld` accesses load 8 bytes from abs 0xa800000000001020, including `ld` at 0x2e1c, `ld` at 0x2e70, `ld` at 0x2ed4.
  2 such `lw` accesses load 4 bytes from [0xa800000000001020]:8 +0x0, including `lw` at 0x2e30, `lw` at 0x2e7c.
  3 such `ld` accesses load 8 bytes from [0xa800000000001020]:8 +0x50, including `ld` at 0x2e3c, `ld` at 0x2e88, `ld` at 0x2ed8.
  The `ld` at 0x2e4c loads 8 bytes from a0 (arg0 at entry) +0x40.
  The `lw` at 0x2e60 loads 4 bytes from [a0+64]:8 +0x18.
  The `jalr` at 0x2ea0 calls (unknown callee) with a0=0x1, a1=?, a2=?, a3=[[0xa800000000001020]:8+80]:8, a4=[[a0+64]:8+24], a5=0xa800000000001020, a6=[0xa800000000001000]:8, a7=[[0xa800000000001020]:8].
  The `jal` at 0x2ea8 calls splx with a0=[sym(.sbss)], a1=?, a2=?, a3=?.
  The `jal` at 0x2ec8 calls spl7 with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=[sym(the_console_port)]:8, a4=0x53435241, a5=[[0xa800000000001020]:8], a6=0xfffffffffeeddead, a7=[[0xa800000000001020]:8+80]:8.
  The `jalr` at 0x2ee0 calls (unknown callee) with a0=0x0, a1=?, a2=?, a3=?.
  The `bne` branch at 0x2e14 targets 0x2e4c, is taken when a0 != a3(=[sym(the_console_port)]:8), and falls through when a0 == a3(=[sym(the_console_port)]:8).
  The `bne` branch at 0x2e20 targets 0x2e4c, is taken when a5(=[0xa800000000001000]:8) != a4(=0x53435241), and falls through when a5(=[0xa800000000001000]:8) == a4(=0x53435241).
  The `beq` branch at 0x2e28 targets 0x2e4c, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x2e34 targets 0x2e4c, is taken when a5(=[[0xa800000000001020]:8]) != a6(=0xfffffffffeeddead), and falls through when a5(=[[0xa800000000001020]:8]) == a6(=0xfffffffffeeddead).
  The `bne` branch at 0x2e44 targets 0x2ec8, is taken when a7(=[[0xa800000000001020]:8+80]:8) != 0, and falls through when a7(=[[0xa800000000001020]:8+80]:8) == 0.
  The `bne` branch at 0x2e5c targets 0x2eb8, is taken when a0 != a3(=[sym(the_console_port)]:8), and falls through when a0 == a3(=[sym(the_console_port)]:8).
  The `bne` branch at 0x2e6c targets 0x2eb8, is taken when a6(=[0xa800000000001000]:8) != a7(=0x53435241), and falls through when a6(=[0xa800000000001000]:8) == a7(=0x53435241).
  The `beq` branch at 0x2e74 targets 0x2eb8, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x2e80 targets 0x2eb8, is taken when a7(=[[0xa800000000001020]:8]) != t0(=0xfffffffffeeddead), and falls through when a7(=[[0xa800000000001020]:8]) == t0(=0xfffffffffeeddead).
  The `beq` branch at 0x2e90 targets 0x2eb8, is taken when a3(=[[0xa800000000001020]:8+80]:8) == 0, and falls through when a3(=[[0xa800000000001020]:8+80]:8) != 0.
  The `beq` branch at 0x2ef8 targets 0x2e4c and is always taken.
  The return at 0x2ec0 has v0 = ?.

- `ioc3_set_proto` in `IP27/usr/cpu/sysgen/IP27boot/sduart.a(sio_ioc3.o)` at 0x2f00 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/sduart.a(sio_ioc3.o)`.
  Range: 0x2f00-0x2f54 (84 bytes).
  It occupies 84 bytes.
  The `ld` at 0x2f00 loads 8 bytes from a0 (arg0 at entry) +0x70.
  2 such `lbu` accesses load 1 byte from [a0+112]:8 +0x20, including `lbu` at 0x2f1c, `lbu` at 0x2f3c.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x38, including `ld` at 0x2f20, `ld` at 0x2f40.
  2 such `sw` accesses store 4 bytes to ([a0+56]:8 + ([[a0+112]:8+32]:1 << 0x2)) +0x40, including `sw` at 0x2f2c, `sw` at 0x2f50.
  The `beq` branch at 0x2f04 targets 0x2f1c, is taken when a1 == 0, and falls through when a1 != 0.
  The `bne` branch at 0x2f0c targets 0x2f34, is taken when a1 != v0(=0x1), and falls through when a1 == v0(=0x1).
  The `beq` branch at 0x2f14 targets 0x2f3c and is always taken.
  The `beq` branch at 0x2f4c targets 0x2f30 and is always taken.
  The return at 0x2f34 has v0 = one of 0x0, 0x1.

- `ioc3_get_mapid` in `IP27/usr/cpu/sysgen/IP27boot/sduart.a(sio_ioc3.o)` at 0x2f54 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/sduart.a(sio_ioc3.o)`.
  Range: 0x2f54-0x2fb4 (96 bytes).
  It occupies 96 bytes.
  The `ld` at 0x2f68 loads 8 bytes from a0 (arg0 at entry) +0x70.
  The `jal` at 0x2f8c calls copyout with a0=sp-16, a1=a1 at entry (arg1), a2=0x8, a3=sym(.data).
  The `beq` branch at 0x2f5c targets 0x2fa4, is taken when a1 == 0, and falls through when a1 != 0.
  The `beq` branch at 0x2f9c targets 0x2fa8 and is always taken.
  The return at 0x2fac has v0 = one of 0x0, 0xe.

- `ioc3_map` in `IP27/usr/cpu/sysgen/IP27boot/sduart.a(sio_ioc3.o)` at 0x2fb4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/sduart.a(sio_ioc3.o)`.
  Range: 0x2fb4-0x3044 (144 bytes).
  It occupies 144 bytes.
  The `ld` at 0x2fe0 loads 8 bytes from a0 (arg0 at entry) +0x58.
  The `ld` at 0x3014 loads 8 bytes from a0 (arg0 at entry) +0x70.
  The `ld` at 0x3024 loads 8 bytes from a0 (arg0 at entry) +0x38.
  The `jal` at 0x2fe8 calls disable_intrs with a0=a0 at entry (arg0), a1=-0x1, a2=?, a3=?, a5=0x16.
  The `jal` at 0x2ff8 calls v_mapphys with a0=a1 at entry (arg1), a1=?, a2=0x4000, a3=?.
  The `beq` branch at 0x2fbc targets 0x2fd8, is taken when a2 == 0, and falls through when a2 != 0.
  The `beq` branch at 0x2fc8 targets 0x3014, is taken when a2 == at(=0x4000), and falls through when a2 != at(=0x4000).
  The `beq` branch at 0x2fd0 targets 0x300c and is always taken.
  The `beq` branch at 0x303c targets 0x2fe8 and is always taken.
  The return at 0x300c has v0 = one of 0x16, ret(v_mapphys).

- `ioc3_unmap` in `IP27/usr/cpu/sysgen/IP27boot/sduart.a(sio_ioc3.o)` at 0x3044 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/sduart.a(sio_ioc3.o)`.
  Range: 0x3044-0x3180 (316 bytes).
  It occupies 316 bytes.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x94, including `lw` at 0x304c, `lw` at 0x3170.
  The `sw` at 0x3060 stores 4 bytes to a0 (arg0 at entry) +0x94.
  2 such `ld` accesses load 8 bytes from abs 0xa800000000001000, including `ld` at 0x3070, `ld` at 0x30d0.
  3 such `ld` accesses load 8 bytes from abs 0xa800000000001020, including `ld` at 0x3078, `ld` at 0x30c4, `ld` at 0x3158.
  2 such `lw` accesses load 4 bytes from [0xa800000000001020]:8 +0x0, including `lw` at 0x3094, `lw` at 0x30e4.
  3 such `ld` accesses load 8 bytes from [0xa800000000001020]:8 +0x50, including `ld` at 0x30a0, `ld` at 0x30f0, `ld` at 0x315c.
  3 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x40, including `ld` at 0x30ac, `ld` at 0x3118, `ld` at 0x312c.
  The `sw` at 0x30b4 stores 4 bytes to [a0+64]:8 +0x0.
  The `lw` at 0x311c loads 4 bytes from [a0+64]:8 +0x8.
  The `sw` at 0x3124 stores 4 bytes to a0 (arg0 at entry) +0x98.
  The `sw` at 0x3128 stores 4 bytes to [a0+64]:8 +0x4.
  The `lw` at 0x3130 loads 4 bytes from [a0+64]:8 +0xc.
  The `sw` at 0x3138 stores 4 bytes to a0 (arg0 at entry) +0x9c.
  The `sw` at 0x313c stores 4 bytes to [a0+64]:8 +0x10.
  The `jalr` at 0x3104 calls (unknown callee) with a0=0x1, a1=[a0+64]:8, a2=[[0xa800000000001020]:8], a3=[[0xa800000000001020]:8+80]:8, a4=[sym(.sbss)], a5=0xa800000000001020, a6=[sym(the_console_port)]:8.
  The `jal` at 0x310c calls splx with a0=[sym(.sbss)], a1=?, a2=?, a3=?.
  The `jal` at 0x314c calls spl7 with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=?, a4=[0xa800000000001000]:8, a5=0x53435241, a6=[[0xa800000000001020]:8], a7=0xfffffffffeeddead.
  The `jalr` at 0x3164 calls (unknown callee) with a0=0x0, a1=?, a2=?, a3=?, a7=[[0xa800000000001020]:8+80]:8.
  The `bne` branch at 0x307c targets 0x30ac, is taken when at(=[sym(the_console_port)]:8) != a0, and falls through when at(=[sym(the_console_port)]:8) == a0.
  The `bne` branch at 0x3084 targets 0x30ac, is taken when a4(=[0xa800000000001000]:8) != a5(=0x53435241), and falls through when a4(=[0xa800000000001000]:8) == a5(=0x53435241).
  The `beq` branch at 0x308c targets 0x30ac, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x3098 targets 0x30ac, is taken when a6(=[[0xa800000000001020]:8]) != a7(=0xfffffffffeeddead), and falls through when a6(=[[0xa800000000001020]:8]) == a7(=0xfffffffffeeddead).
  The `bne` branch at 0x30a4 targets 0x314c, is taken when t0(=[[0xa800000000001020]:8+80]:8) != 0, and falls through when t0(=[[0xa800000000001020]:8+80]:8) == 0.
  The `bne` branch at 0x30cc targets 0x3118, is taken when a6(=[sym(the_console_port)]:8) != s0(=a0), and falls through when a6(=[sym(the_console_port)]:8) == s0(=a0).
  The `bne` branch at 0x30d4 targets 0x3118, is taken when a4(=[0xa800000000001000]:8) != a0(=0x53435241), and falls through when a4(=[0xa800000000001000]:8) == a0(=0x53435241).
  The `beq` branch at 0x30dc targets 0x3118, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x30e8 targets 0x3118, is taken when a2(=[[0xa800000000001020]:8]) != a3(=0xfffffffffeeddead), and falls through when a2(=[[0xa800000000001020]:8]) == a3(=0xfffffffffeeddead).
  The `beq` branch at 0x30f4 targets 0x3118, is taken when a3(=[[0xa800000000001020]:8+80]:8) == 0, and falls through when a3(=[[0xa800000000001020]:8+80]:8) != 0.
  The `beq` branch at 0x3178 targets 0x30ac and is always taken.
  The return at 0x3144 has v0 = one of [0xa800000000001020]:8, ret(splx).

- `ioc3_set_sscr` in `IP27/usr/cpu/sysgen/IP27boot/sduart.a(sio_ioc3.o)` at 0x3180 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/sduart.a(sio_ioc3.o)`.
  Range: 0x3180-0x32a4 (292 bytes).
  It occupies 292 bytes.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x94, including `lw` at 0x3180, `lw` at 0x3254, `lw` at 0x3294.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x94, including `sw` at 0x319c, `sw` at 0x326c.
  2 such `ld` accesses load 8 bytes from abs 0xa800000000001000, including `ld` at 0x31b8, `ld` at 0x320c.
  3 such `ld` accesses load 8 bytes from abs 0xa800000000001020, including `ld` at 0x31bc, `ld` at 0x3200, `ld` at 0x327c.
  2 such `lw` accesses load 4 bytes from [0xa800000000001020]:8 +0x0, including `lw` at 0x31d0, `lw` at 0x3220.
  3 such `ld` accesses load 8 bytes from [0xa800000000001020]:8 +0x50, including `ld` at 0x31dc, `ld` at 0x322c, `ld` at 0x3280.
  The `ld` at 0x31e8 loads 8 bytes from a0 (arg0 at entry) +0x40.
  The `sw` at 0x31f0 stores 4 bytes to [a0+64]:8 +0x0.
  The `jalr` at 0x3240 calls (unknown callee) with a0=0x1, a1=[[0xa800000000001020]:8+80]:8, a2=[sym(the_console_port)]:8, a3=[[0xa800000000001020]:8], a4=0xfffffffffeeddead, a5=[sym(.sbss)].
  The `jal` at 0x3248 calls splx with a0=[sym(.sbss)], a1=?, a2=?, a3=?.
  The `jal` at 0x3270 calls spl7 with a0=0x53435241, a1=[[0xa800000000001020]:8], a2=0xfffffffffeeddead, a3=[[0xa800000000001020]:8+80]:8, a4=0xa800000000001020.
  The `jalr` at 0x3288 calls (unknown callee) with a0=0x0, a1=?, a2=?, a3=?, a6=[[0xa800000000001020]:8+80]:8.
  The `beq` branch at 0x3190 targets 0x3264, is taken when a2 == 0, and falls through when a2 != 0.
  The `bne` branch at 0x31b4 targets 0x31e8, is taken when a2(=[sym(the_console_port)]:8) != s0(=a0), and falls through when a2(=[sym(the_console_port)]:8) == s0(=a0).
  The `bne` branch at 0x31c0 targets 0x31e8, is taken when a1(=[0xa800000000001000]:8) != a0(=0x53435241), and falls through when a1(=[0xa800000000001000]:8) == a0(=0x53435241).
  The `beq` branch at 0x31c8 targets 0x31e8, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x31d4 targets 0x31e8, is taken when a1(=[[0xa800000000001020]:8]) != a2(=0xfffffffffeeddead), and falls through when a1(=[[0xa800000000001020]:8]) == a2(=0xfffffffffeeddead).
  The `bne` branch at 0x31e0 targets 0x3270, is taken when a3(=[[0xa800000000001020]:8+80]:8) != 0, and falls through when a3(=[[0xa800000000001020]:8+80]:8) == 0.
  The `bne` branch at 0x3208 targets 0x3254, is taken when a2(=[sym(the_console_port)]:8) != s0(=a0), and falls through when a2(=[sym(the_console_port)]:8) == s0(=a0).
  The `bne` branch at 0x3210 targets 0x3254, is taken when a0(=[0xa800000000001000]:8) != a1(=0x53435241), and falls through when a0(=[0xa800000000001000]:8) == a1(=0x53435241).
  The `beq` branch at 0x3218 targets 0x3254, is taken when v0(=[0xa800000000001020]:8) == 0, and falls through when v0(=[0xa800000000001020]:8) != 0.
  The `bne` branch at 0x3224 targets 0x3254, is taken when a3(=[[0xa800000000001020]:8]) != a4(=0xfffffffffeeddead), and falls through when a3(=[[0xa800000000001020]:8]) == a4(=0xfffffffffeeddead).
  The `beq` branch at 0x3230 targets 0x3254, is taken when a1(=[[0xa800000000001020]:8+80]:8) == 0, and falls through when a1(=[[0xa800000000001020]:8+80]:8) != 0.
  The `beq` branch at 0x3268 targets 0x31a0 and is always taken.
  The `beq` branch at 0x329c targets 0x31e8 and is always taken.
  The return at 0x325c has v0 = [a0+148].

- `ioc3_console_write` in `IP27/usr/cpu/sysgen/IP27boot/sduart.a(sio_ioc3.o)` at 0x32a4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/sduart.a(sio_ioc3.o)`.
  Range: 0x32a4-0x33f8 (340 bytes).
  It occupies 340 bytes.
  7 such `lw` accesses load 4 bytes from [sym(console_mem)]:8 +0xb8, including `lw` at 0x32a8, `lw` at 0x3384, `lw` at 0x3394.
  The `sd` at 0x32d0 stores 8 bytes to a2 (arg2 at entry) +0x0.
  The `sb` at 0x32f8 stores 1 byte to [sym(console_mem)]:8 +0x20178.
  6 such `lbu` accesses load 1 byte from [sym(console_mem)]:8 +0x2017d, including `lbu` at 0x32fc, `lbu` at 0x3314, `lbu` at 0x3324.
  The `lbu` at 0x3308 loads 1 byte from ?.
  The `sw` at 0x3380 stores 4 bytes to [sym(console_mem)]:8 +0xb8.
  The `bne` branch at 0x32b8 targets 0x32d0, is taken when t0(=0x10000000) != t2(?), and falls through when t0(=0x10000000) == t2(?).
  The `beq` branch at 0x32c8 targets 0x33ec and is always taken.
  The `bne` branch at 0x32e4 targets 0x32fc, is taken when a1 != 0, and falls through when a1 == 0.
  The `beq` branch at 0x32ec targets 0x336c and is always taken.
  The `beq` branch at 0x32f4 targets 0x336c, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `bne` branch at 0x330c targets 0x32f4, is taken when (a6(=[[sym(console_mem)]:8+131453]:1) & 0x20) != 0, and falls through when (a6(=[[sym(console_mem)]:8+131453]:1) & 0x20) == 0.
  The `bne` branch at 0x331c targets 0x32f4, is taken when (a7(=[[sym(console_mem)]:8+131453]:1) & 0x20) != 0, and falls through when (a7(=[[sym(console_mem)]:8+131453]:1) & 0x20) == 0.
  The `bne` branch at 0x332c targets 0x32f4, is taken when (t0(=[[sym(console_mem)]:8+131453]:1) & 0x20) != 0, and falls through when (t0(=[[sym(console_mem)]:8+131453]:1) & 0x20) == 0.
  The `bne` branch at 0x333c targets 0x32f4, is taken when (t1(=[[sym(console_mem)]:8+131453]:1) & 0x20) != 0, and falls through when (t1(=[[sym(console_mem)]:8+131453]:1) & 0x20) == 0.
  The `bne` branch at 0x334c targets 0x32f4, is taken when (t2(=[[sym(console_mem)]:8+131453]:1) & 0x20) != 0, and falls through when (t2(=[[sym(console_mem)]:8+131453]:1) & 0x20) == 0.
  The `beq` branch at 0x335c targets 0x3314, is taken when (t3(=[[sym(console_mem)]:8+131453]:1) & 0x20) == 0, and falls through when (t3(=[[sym(console_mem)]:8+131453]:1) & 0x20) != 0.
  The `beq` branch at 0x3364 targets 0x32f4 and is always taken.
  The `bne` branch at 0x3378 targets 0x32d0, is taken when t0(=0x10000000) != t8(?), and falls through when t0(=0x10000000) == t8(?).
  The `bne` branch at 0x338c targets 0x3378, is taken when a5(=0x30000000) != t9(?), and falls through when a5(=0x30000000) == t9(?).
  The `bne` branch at 0x339c targets 0x3374, is taken when a5(=0x30000000) != v0(?), and falls through when a5(=0x30000000) == v0(?).
  The `bne` branch at 0x33ac targets 0x3374, is taken when a5(=0x30000000) != v1(?), and falls through when a5(=0x30000000) == v1(?).
  The `bne` branch at 0x33bc targets 0x3374, is taken when a5(=0x30000000) != a3(?), and falls through when a5(=0x30000000) == a3(?).
  The `bne` branch at 0x33cc targets 0x3374, is taken when a5(=0x30000000) != t3(?), and falls through when a5(=0x30000000) == t3(?).
  The `beq` branch at 0x33dc targets 0x3394, is taken when a5(=0x30000000) == t8(?), and falls through when a5(=0x30000000) != t8(?).
  The `beq` branch at 0x33e4 targets 0x3374 and is always taken.
  The `beq` branch at 0x33f0 targets 0x3380 and is always taken.
  The return at 0x336c has v0 = 0x0.

- `console_debug_poll` in `IP27/usr/cpu/sysgen/IP27boot/sduart.a(sio_ioc3.o)` at 0x33f8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/sduart.a(sio_ioc3.o)`.
  Range: 0x33f8-0x34d0 (216 bytes).
  It occupies 216 bytes.
  7 such `lw` accesses load 4 bytes from [sym(console_mem)]:8 +0xb8, including `lw` at 0x33fc, `lw` at 0x3454, `lw` at 0x3464.
  The `lbu` at 0x3428 loads 1 byte from [sym(console_mem)]:8 +0x2017d.
  The `lbu` at 0x3438 loads 1 byte from [sym(console_mem)]:8 +0x20178.
  The `sw` at 0x3450 stores 4 bytes to [sym(console_mem)]:8 +0xb8.
  The `jal` at 0x34c0 calls debug with a0=sym(.rodata), a1=[sym(console_mem)]:8+131072, a2=[sym(console_mem)]:8+184, a3=[sym(console_mem)]:8, a4=0x20000, a5=([[sym(console_mem)]:8+184] << 0x21), a6=[[sym(console_mem)]:8+184].
  The `bgez` branch at 0x3414 targets 0x3424, is taken when at(=([[sym(console_mem)]:8+184] << 0x23)) >= 0 (signed), and falls through when at(=([[sym(console_mem)]:8+184] << 0x23)) < 0 (signed).
  The `bgez` branch at 0x341c targets 0x344c, is taken when a5(=([[sym(console_mem)]:8+184] << 0x21)) >= 0 (signed), and falls through when a5(=([[sym(console_mem)]:8+184] << 0x21)) < 0 (signed).
  The `beq` branch at 0x3430 targets 0x3444, is taken when (v0(=[[sym(console_mem)]:8+131453]:1) & 0x1) == 0, and falls through when (v0(=[[sym(console_mem)]:8+131453]:1) & 0x1) != 0.
  The `beq` branch at 0x343c targets 0x34bc, is taken when v1(=[[sym(console_mem)]:8+131448]:1) == a0(=0x1), and falls through when v1(=[[sym(console_mem)]:8+131448]:1) != a0(=0x1).
  The `bltz` branch at 0x345c targets 0x34b4, is taken when a5(=([[sym(console_mem)]:8+184] << 0x21)) < 0 (signed), and falls through when a5(=([[sym(console_mem)]:8+184] << 0x21)) >= 0 (signed).
  The `bne` branch at 0x346c targets 0x34b4, is taken when (t0(=[[sym(console_mem)]:8+184]) & a1(=0x40000000)) != 0, and falls through when (t0(=[[sym(console_mem)]:8+184]) & a1(=0x40000000)) == 0.
  The `bne` branch at 0x347c targets 0x34b4, is taken when (t1(=[[sym(console_mem)]:8+184]) & a1(=0x40000000)) != 0, and falls through when (t1(=[[sym(console_mem)]:8+184]) & a1(=0x40000000)) == 0.
  The `bne` branch at 0x348c targets 0x34b4, is taken when (t2(=[[sym(console_mem)]:8+184]) & a1(=0x40000000)) != 0, and falls through when (t2(=[[sym(console_mem)]:8+184]) & a1(=0x40000000)) == 0.
  The `bne` branch at 0x349c targets 0x34b4, is taken when (t3(=[[sym(console_mem)]:8+184]) & a1(=0x40000000)) != 0, and falls through when (t3(=[[sym(console_mem)]:8+184]) & a1(=0x40000000)) == 0.
  The `beq` branch at 0x34ac targets 0x3464, is taken when (t8(=[[sym(console_mem)]:8+184]) & a1(=0x40000000)) == 0, and falls through when (t8(=[[sym(console_mem)]:8+184]) & a1(=0x40000000)) != 0.
  The `beq` branch at 0x34b4 targets 0x3428 and is always taken.
  The `beq` branch at 0x34c8 targets 0x3444 and is always taken.
  The return at 0x3444 has v0 = one of ?, ret(debug).
