# Readings: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_l1.o)`

One entry per routine, filed here from the reading batches by binary.

- `return_0` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_l1.o)` at 0x0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_l1.o)`.
  Range: 0x0-0x8 (8 bytes).
  It occupies 8 bytes.
  The return at 0x0 has v0 = 0x0.

- `return_1` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_l1.o)` at 0x8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_l1.o)`.
  Range: 0x8-0x10 (8 bytes).
  It occupies 8 bytes.
  The return at 0x8 has v0 = 0x1.

- `l1_mlreset` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_l1.o)` at 0x10 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_l1.o)`.
  Range: 0x10-0x8c (124 bytes).
  It occupies 124 bytes.
  The `ld` at 0x2c loads 8 bytes from (([sym(master_nasid)]:2 << 0x21)+0x9600000000000000 | 0x2000) +0x48.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0x3c, `lw` at 0x48.
  The `jal` at 0x7c calls sio_console_register with a0=sp-32, a1=?, a2=0x300fafb, a3=sym(console_debug_poll), a4=0xffffffffff.
  The `beq` branch at 0x58 targets 0x70, is taken when a1(?) == at(=0x300fafa), and falls through when a1(?) != at(=0x300fafa).
  The `beq` branch at 0x60 targets 0x70, is taken when a1(?) == a2(=0x300fafb), and falls through when a1(?) != a2(=0x300fafb).
  The `beq` branch at 0x84 targets 0x68 and is always taken.
  The return at 0x68 has v0 = one of ?, ret(sio_console_register).

- `l1_attach` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_l1.o)` at 0x8c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_l1.o)`.
  Range: 0x8c-0x2bc (560 bytes).
  It occupies 560 bytes.
  The `ld` at 0xb4 loads 8 bytes from sym(pdaindr) +0x8.
  The `ld` at 0xbc loads 8 bytes from abs 0xffffffffffffc400.
  The `lh` at 0xc0 loads 2 bytes from ?.
  The `ld` at 0xc4 loads 8 bytes from [-0x3c00]:8 +0x0.
  The `ld` at 0xcc loads 8 bytes from [sym(pdaindr)+8]:8 +0x400.
  The `ld` at 0xd8 loads 8 bytes from ?.
  The `lh` at 0xe0 loads 2 bytes from [[sym(pdaindr)+8]:8+1024]:8 +0x861a.
  The `lh` at 0xe8 loads 2 bytes from table(0x861a) +0x0.
  The `sd` at 0x130 stores 8 bytes to ret(kmem_zalloc) +0x0.
  4 such `ld` accesses load 8 bytes from table(0x8620) +0x0, including `ld` at 0x134, `ld` at 0x1a8, `ld` at 0x240.
  The `sd` at 0x13c stores 8 bytes to ret(kmem_zalloc) +0x38.
  The `sb` at 0x18c stores 1 byte to ret(kmem_zalloc) +0x1d.
  The `sd` at 0x1a0 stores 8 bytes to ?.
  2 such `lhu` accesses load 2 bytes from table(0x8598) +0x0, including `lhu` at 0x1a4, `lhu` at 0x220.
  The `lh` at 0x1b8 loads 2 bytes from table(0x8596) +0x0.
  The `sd` at 0x238 stores 8 bytes to sym(.data) +0x28.
  The `sd` at 0x23c stores 8 bytes to sym(brl1_port) +0x0.
  The `sd` at 0x24c stores 8 bytes to sym(brl1_port) +0x38.
  The `lbu` at 0x2a0 loads 1 byte from entry(0x8620) +0x2d.
  The `sb` at 0x2b0 stores 1 byte to entry(0x8620) +0x2d.
  The `jal` at 0xa8 calls hwgraph_info_get_LBL with a0=a0 at entry (arg0), a1=sym(.rodata), a2=sp-320, a3=a3 at entry (arg3).
  The `jal` at 0xf8 calls sprintf with a0=sp-312, a1=sym(.rodata), a2=entry(0x861a), a3=?.
  The `jal` at 0x108 calls hwgraph_traverse with a0=[sym(hwgraph_root)], a1=sp-312, a2=sp-56, a3=?.
  The `jal` at 0x124 calls kmem_zalloc with a0=0x40, a1=0x1, a2=?, a3=?.
  The `jal` at 0x148 calls hwgraph_path_add with a0=[sym(hwgraph_root)], a1=sp-312, a2=sp-56, a3=?.
  The `jal` at 0x154 calls hwgraph_fastinfo_set with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x16c calls sio_initport with a0=?, a1=?, a2=0x9, a3=0x0.
  The `jal` at 0x180 calls kmem_zalloc with a0=0x28, a1=0x0, a2=[sym(L1_is_console)], a3=?.
  The `jal` at 0x194 calls sio_init_locks with a0=ret(kmem_zalloc), a1=?, a2=?, a3=?.
  The `jal` at 0x1b4 calls brl1_connect_intr with a0=entry(0x8620)+40, a1=entry(0x8596), a2=?, a3=?.
  The `jal` at 0x1ec calls hwgraph_edge_get with a0=?, a1=sym(.rodata), a2=sp-52, a3=?.
  The `jal` at 0x20c calls hwgraph_edge_add with a0=[sym(hwgraph_root)], a1=?, a2=sym(.rodata), a3=0x1.
  The `jal` at 0x214 calls sio_make_hwgraph_nodes with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x228 calls sio_lock_port with a0=sym(brl1_port), a1=0x0, a2=?, a3=?.
  The `jal` at 0x248 calls sio_unlock_port with a0=sym(brl1_port), a1=?, a2=?, a3=?, a4=entry(0x8620), a5=sym(.data), a6=sym(l1_duwrite).
  The `jal` at 0x274 calls device_inventory_add with a0=?, a1=0x4, a2=0x12, a3=0x1, a4=0x0, a5=0x0, a7=[sym(L1_is_console)].
  The `jal` at 0x284 calls brl1_enable_uart_intr with a0=entry(0x8620)+40, a1=entry(0x8598), a2=?, a3=?.
  The `jal` at 0x2ac calls sc_listen with a0=entry(0x8620)+40, a1=?, a2=?, a3=?.
  The `beq` branch at 0x110 targets 0x294, is taken when v0(=ret(hwgraph_traverse)) == 0, and falls through when v0(=ret(hwgraph_traverse)) != 0.
  The `bne` branch at 0x118 targets 0x224, is taken when s2(?) != 0, and falls through when s2(?) == 0.
  The `bne` branch at 0x15c targets 0x258, is taken when s2(?) != 0, and falls through when s2(?) == 0.
  The `bne` branch at 0x174 targets 0x1dc, is taken when s2(?) != 0, and falls through when s2(?) == 0.
  The `beq` branch at 0x1ac targets 0x284, is taken when a1(=entry(0x8598)) == 0, and falls through when a1(=entry(0x8598)) != 0.
  The `bne` branch at 0x1bc targets 0x29c, is taken when s2(?) != 0, and falls through when s2(?) == 0.
  The `beq` branch at 0x1dc targets 0x1a4, is taken when a2(=[sym(L1_is_console)]) == 0, and falls through when a2(=[sym(L1_is_console)]) != 0.
  The `beq` branch at 0x21c targets 0x1a8 and is always taken.
  The `beq` branch at 0x250 targets 0x144 and is always taken.
  The `beq` branch at 0x25c targets 0x160, is taken when a7(=[sym(L1_is_console)]) == 0, and falls through when a7(=[sym(L1_is_console)]) != 0.
  The `beq` branch at 0x27c targets 0x164 and is always taken.
  The `beq` branch at 0x28c targets 0x1bc and is always taken.
  The `beq` branch at 0x294 targets 0x1c4 and is always taken.
  The `beq` branch at 0x2b4 targets 0x1c4 and is always taken.
  The return at 0x1d4 has v0 = 0x0.

- `early_brl1_port_init` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_l1.o)` at 0x2bc (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_l1.o)`.
  Range: 0x2bc-0x350 (148 bytes).
  It occupies 148 bytes.
  The `sd` at 0x2d0 stores 8 bytes to sym(brl1_port) +0x0.
  The `sd` at 0x2d8 stores 8 bytes to sym(.data) +0x28.
  The `sb` at 0x2e4 stores 1 byte to sym(brl1_port) +0x5d.
  The `sd` at 0x304 stores 8 bytes to sym(brl1_port) +0x20.
  The `ld` at 0x310 loads 8 bytes from (([sym(master_nasid)]:2 << 0x21)+0x9600000000000000 | 0x2000) +0x48.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0x320, `lw` at 0x32c.
  The `jal` at 0x2e0 calls sio_init_locks with a0=sym(brl1_port), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `bne` branch at 0x338 targets 0x348, is taken when a2(?) != a3(=0x300fafa), and falls through when a2(?) == a3(=0x300fafa).
  The return at 0x348 has v0 = ret(sio_init_locks).

- `brl1_port_ready` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_l1.o)` at 0x350 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_l1.o)`.
  Range: 0x350-0x368 (24 bytes).
  It occupies 24 bytes.
  The `ld` at 0x358 loads 8 bytes from sym(brl1_port) +0x0.
  The return at 0x360 has v0 = ?.

- `l1_open` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_l1.o)` at 0x368 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_l1.o)`.
  Range: 0x368-0x370 (8 bytes).
  It occupies 8 bytes.
  The return at 0x368 has v0 = 0x0.

- `l1_write` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_l1.o)` at 0x370 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_l1.o)`.
  Range: 0x370-0x3a0 (48 bytes).
  It occupies 48 bytes.
  The `ld` at 0x370 loads 8 bytes from a0 (arg0 at entry) +0x38.
  The `jal` at 0x380 calls l1_cons_write with a0=[a0+56]:8+40, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=0x0.
  The `bltz` branch at 0x388 targets 0x398, is taken when v0(=ret(l1_cons_write)) < 0 (signed), and falls through when v0(=ret(l1_cons_write)) >= 0 (signed).
  The `beq` branch at 0x398 targets 0x390 and is always taken.
  The return at 0x390 has v0 = one of ret(l1_cons_write), -0x1.

- `l1_write_nobuf` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_l1.o)` at 0x3a0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_l1.o)`.
  Range: 0x3a0-0x3d4 (52 bytes).
  It occupies 52 bytes.
  The `jal` at 0x3b8 calls brl1_send_console_packet with a0=a1 at entry (arg1), a1=a2 at entry (arg2), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `bgtz` branch at 0x3a8 targets 0x3b8, is taken when a2 > 0 (signed), and falls through when a2 <= 0 (signed).
  The `beq` branch at 0x3b0 targets 0x3c8 and is always taken.
  The return at 0x3cc has v0 = one of 0x0, ret(brl1_send_console_packet).

- `l1_duwrite` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_l1.o)` at 0x3d4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_l1.o)`.
  Range: 0x3d4-0x404 (48 bytes).
  It occupies 48 bytes.
  The `ld` at 0x3d4 loads 8 bytes from a0 (arg0 at entry) +0x38.
  The `jal` at 0x3e4 calls l1_cons_write with a0=[a0+56]:8+40, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=0x1.
  The `bltz` branch at 0x3ec targets 0x3fc, is taken when v0(=ret(l1_cons_write)) < 0 (signed), and falls through when v0(=ret(l1_cons_write)) >= 0 (signed).
  The `beq` branch at 0x3fc targets 0x3f4 and is always taken.
  The return at 0x3f4 has v0 = one of ret(l1_cons_write), -0x1.

- `l1_wrflush` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_l1.o)` at 0x404 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_l1.o)`.
  Range: 0x404-0x430 (44 bytes).
  It occupies 44 bytes.
  The `ld` at 0x40c loads 8 bytes from a0 (arg0 at entry) +0x38.
  The `jal` at 0x41c calls l1_cons_write with a0=[a0+56]:8+40, a1=0x0, a2=0x0, a3=0x1.
  The return at 0x428 has v0 = ret(l1_cons_write).

- `l1_read` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_l1.o)` at 0x430 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_l1.o)`.
  Range: 0x430-0x450 (32 bytes).
  It occupies 32 bytes.
  The `ld` at 0x430 loads 8 bytes from a0 (arg0 at entry) +0x38.
  The `jal` at 0x43c calls l1_cons_read with a0=[a0+56]:8+40, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x448 has v0 = ret(l1_cons_read).

- `l1_data_ready` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_l1.o)` at 0x450 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_l1.o)`.
  Range: 0x450-0x49c (76 bytes).
  It occupies 76 bytes.
  The `ld` at 0x46c loads 8 bytes from [sym(the_console_port)]:8 +0x8.
  The `ld` at 0x478 loads 8 bytes from [[sym(the_console_port)]:8+8]:8 +0x0.
  The `jal` at 0x464 calls sio_lock_port with a0=[sym(the_console_port)]:8, a1=0x0, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x47c calls (unknown callee) with a0=[sym(the_console_port)]:8, a1=?, a2=[[sym(the_console_port)]:8+8]:8, a3=?.
  The `jal` at 0x484 calls sio_unlock_port with a0=[sym(the_console_port)]:8, a1=?, a2=?, a3=?.
  The `beq` branch at 0x470 targets 0x484, is taken when a2(=[[sym(the_console_port)]:8+8]:8) == 0, and falls through when a2(=[[sym(the_console_port)]:8+8]:8) != 0.
  The return at 0x494 has v0 = ret(sio_unlock_port).

- `l1_output_lowat` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_l1.o)` at 0x49c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_l1.o)`.
  Range: 0x49c-0x4e8 (76 bytes).
  It occupies 76 bytes.
  The `ld` at 0x4b8 loads 8 bytes from [sym(the_console_port)]:8 +0x8.
  The `ld` at 0x4c4 loads 8 bytes from [[sym(the_console_port)]:8+8]:8 +0x8.
  The `jal` at 0x4b0 calls sio_lock_port with a0=[sym(the_console_port)]:8, a1=0x0, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x4c8 calls (unknown callee) with a0=[sym(the_console_port)]:8, a1=?, a2=[[sym(the_console_port)]:8+8]:8, a3=?.
  The `jal` at 0x4d0 calls sio_unlock_port with a0=[sym(the_console_port)]:8, a1=?, a2=?, a3=?.
  The `beq` branch at 0x4bc targets 0x4d0, is taken when a2(=[[sym(the_console_port)]:8+8]:8) == 0, and falls through when a2(=[[sym(the_console_port)]:8+8]:8) != 0.
  The return at 0x4e0 has v0 = ret(sio_unlock_port).

- `l1_notification` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_l1.o)` at 0x4e8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_l1.o)`.
  Range: 0x4e8-0x58c (164 bytes).
  It occupies 164 bytes.
  4 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x38, including `ld` at 0x510, `ld` at 0x52c, `ld` at 0x558.
  The `jal` at 0x518 calls l1_cons_rx_notif with a0=[a0+56]:8+40, a1=sym(l1_data_ready), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x534 calls l1_cons_tx_notif with a0=[a0+56]:8+40, a1=sym(l1_output_lowat), a2=?, a3=?.
  The `jal` at 0x560 calls l1_cons_rx_notif with a0=[a0+56]:8+40, a1=0x0, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x57c calls l1_cons_tx_notif with a0=[a0+56]:8+40, a1=0x0, a2=?, a3=?.
  The `beq` branch at 0x500 targets 0x550, is taken when a2 == 0, and falls through when a2 != 0.
  The `beq` branch at 0x508 targets 0x524, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0x524 targets 0x540, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x550 targets 0x56c, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0x56c targets 0x540, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x584 targets 0x540 and is always taken.
  The return at 0x548 has v0 = 0x0.

- `l1_set_extclk` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_l1.o)` at 0x58c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_l1.o)`.
  Range: 0x58c-0x594 (8 bytes).
  It occupies 8 bytes.
  The return at 0x58c has v0 = a1.

- `l1_set_proto` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_l1.o)` at 0x594 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_l1.o)`.
  Range: 0x594-0x59c (8 bytes).
  It occupies 8 bytes.
  The return at 0x594 has v0 = ?.

- `console_debug_poll` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_l1.o)` at 0x59c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_l1.o)`.
  Range: 0x59c-0x5dc (64 bytes).
  It occupies 64 bytes.
  The `jal` at 0x5a4 calls get_elsc with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x5ac calls l1_cons_getc with a0=ret(get_elsc), a1=?, a2=?, a3=?.
  The `jal` at 0x5cc calls debug with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `beq` branch at 0x5b8 targets 0x5c8, is taken when v0(=ret(l1_cons_getc)) == at(=0x1), and falls through when v0(=ret(l1_cons_getc)) != at(=0x1).
  The `beq` branch at 0x5d4 targets 0x5c0 and is always taken.
  The return at 0x5c0 has v0 = one of ret(l1_cons_getc), ret(debug).

- `du_lateinit` in `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_l1.o)` at 0x5dc (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/sduart.a(sio_l1.o)`.
  Range: 0x5dc-0x5e4 (8 bytes).
  It occupies 8 bytes.
  The return at 0x5dc has v0 = ?.
