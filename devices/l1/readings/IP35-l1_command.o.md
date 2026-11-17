# Readings: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`

One entry per routine, filed here from the reading batches by binary.

- `elsc_init` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0x0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0x0-0x1c (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x8 calls sc_init with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0xf, a3=a3 at entry (arg3).
  The return at 0x14 has v0 = ret(sc_init).

- `elsc_errmsg` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0x1c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0x1c-0xc4 (168 bytes).
  It occupies 168 bytes.
  The `ld` at 0x38 loads 8 bytes from (sym(.rodata) + (a0+125 << 0x3)) +0x0.
  Calls (unknown callee) via register with a0=[(sym(.rodata) + (a0+125 << 0x3))]:8, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=sym(.rodata) (`jr` at 0x3c).
  The `beq` branch at 0x30 targets 0x44, is taken when v1(=a0+125) >= 0x1a (unsigned), and falls through when v1(=a0+125) < 0x1a (unsigned).
  The return at 0x4c has v0 = sym(.rodata).
  The instructions from 0x54 to 0xc0 are not reached by any path from the entry, and their branches are not listed.
  The indirect jump at 0x3c uses a jump table whose successors are unresolved.

- `elsc_nvram_init` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0xc4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0xc4-0xcc (8 bytes).
  It occupies 8 bytes.
  The return at 0xc4 has v0 = ?.

- `elsc_nvram_copy` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0xcc (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0xcc-0xec (32 bytes).
  It occupies 32 bytes.
  The `jal` at 0xd8 calls bcopy with a0=a0 at entry (arg0), a1=sym(.bss), a2=0x10, a3=a3 at entry (arg3).
  The return at 0xe4 has v0 = ret(bcopy).

- `elsc_nvram_write` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0xec (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0xec-0x100 (20 bytes).
  It occupies 20 bytes.
  The `bltz` branch at 0xec targets 0xf8, is taken when a3 < 0 (signed), and falls through when a3 >= 0 (signed).
  The return at 0xf8 has v0 = one of ?, a3.

- `elsc_nvram_read` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0x100 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0x100-0x108 (8 bytes).
  It occupies 8 bytes.
  The return at 0x100 has v0 = -0x1.

- `sc_version` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0x108 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0x108-0x218 (272 bytes).
  It occupies 272 bytes.
  The `jal` at 0x128 calls bzero with a0=sp-192, a1=0x80, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x13c calls sc_open with a0=a0 at entry (arg0), a1=0xffff000, a2=?, a3=?.
  The `jal` at 0x168 calls sc_construct_msg with a0=a0 at entry (arg0), a1=ret(sc_open), a2=sp-192, a3=0x80, a4=0x6, a5=0x5, a6=0x0.
  The `jal` at 0x188 calls sc_command_kern with a0=a0 at entry (arg0), a1=ret(sc_open), a2=sp-192, a3=sp-192, a4=sp-64.
  The `jal` at 0x19c calls sc_close with a0=a0 at entry (arg0), a1=ret(sc_open), a2=?, a3=?.
  The `jal` at 0x1c0 calls sc_interpret_resp with a0=sp-192, a1=0x6, a2=0x0, a3=a1 at entry (arg1), a4=0x0, a5=a2 at entry (arg2), a6=0x0, a7=a3 at entry (arg3).
  The `jal` at 0x1f8 calls sc_close with a0=a0 at entry (arg0), a1=ret(sc_open), a2=?, a3=?.
  The `jal` at 0x208 calls sc_close with a0=a0 at entry (arg0), a1=ret(sc_open), a2=?, a3=?.
  The `bltz` branch at 0x148 targets 0x1d0, is taken when v0(=ret(sc_open)) < 0 (signed), and falls through when v0(=ret(sc_open)) >= 0 (signed).
  The `bltz` branch at 0x170 targets 0x1f4, is taken when v0(=ret(sc_construct_msg)) < 0 (signed), and falls through when v0(=ret(sc_construct_msg)) >= 0 (signed).
  The `bltz` branch at 0x190 targets 0x208, is taken when v0(=ret(sc_command_kern)) < 0 (signed), and falls through when v0(=ret(sc_command_kern)) >= 0 (signed).
  The `bltz` branch at 0x1c8 targets 0x1e8, is taken when v0(=ret(sc_interpret_resp)) < 0 (signed), and falls through when v0(=ret(sc_interpret_resp)) >= 0 (signed).
  The `beq` branch at 0x1ec targets 0x1d4 and is always taken.
  The `beq` branch at 0x200 targets 0x1d0 and is always taken.
  The `beq` branch at 0x210 targets 0x1d0 and is always taken.
  The return at 0x1e0 has v0 = one of -0x70, -0x67, -0x64, 0x0.

- `sc_version_comp` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0x218 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0x218-0x280 (104 bytes).
  It occupies 104 bytes.
  The `jal` at 0x228 calls sc_version with a0=a0 at entry (arg0), a1=sp-32, a2=sp-28, a3=sp-24.
  The `bltz` branch at 0x234 targets 0x278, is taken when v0(=ret(sc_version)) < 0 (signed), and falls through when v0(=ret(sc_version)) >= 0 (signed).
  The `beq` branch at 0x278 targets 0x270 and is always taken.
  The return at 0x270 has v0 = one of ?, ret(sc_version).

- `elsc_version` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0x280 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0x280-0x2dc (92 bytes).
  It occupies 92 bytes.
  The `sb` at 0x2ac stores 1 byte to a1 (arg1 at entry) +0x0.
  The `jal` at 0x298 calls sc_version with a0=a0 at entry (arg0), a1=sp-32, a2=sp-28, a3=sp-24.
  The `jal` at 0x2c0 calls sprintf with a0=a1 at entry (arg1), a1=sym(.rodata), a2=?, a3=?.
  The `bgez` branch at 0x2a0 targets 0x2b0, is taken when v0(=ret(sc_version)) >= 0 (signed), and falls through when v0(=ret(sc_version)) < 0 (signed).
  The `beq` branch at 0x2a8 targets 0x2cc and is always taken.
  The return at 0x2d4 has v0 = one of ret(sc_version), 0x0.

- `elsc_debug_set` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0x2dc (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0x2dc-0x2e4 (8 bytes).
  It occupies 8 bytes.
  The return at 0x2dc has v0 = 0x0.

- `elsc_debug_get` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0x2e4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0x2e4-0x3fc (280 bytes).
  It occupies 280 bytes.
  The `sb` at 0x3a4 stores 1 byte to a1 (arg1 at entry) +0x0.
  The `sb` at 0x3ac stores 1 byte to a2 (arg2 at entry) +0x0.
  The `jal` at 0x300 calls bzero with a0=sp-176, a1=0x80, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x314 calls sc_open with a0=a0 at entry (arg0), a1=0xffff000, a2=?, a3=?.
  The `jal` at 0x340 calls sc_construct_msg with a0=a0 at entry (arg0), a1=ret(sc_open), a2=sp-176, a3=0x80, a4=0x6, a5=0x1, a6=0x0.
  The `jal` at 0x360 calls sc_command with a0=a0 at entry (arg0), a1=ret(sc_open), a2=sp-176, a3=sp-176, a4=sp-48.
  The `jal` at 0x370 calls sc_close with a0=a0 at entry (arg0), a1=ret(sc_open), a2=?, a3=?.
  The `jal` at 0x384 calls sc_interpret_resp with a0=sp-176, a1=0x2, a2=0x0, a3=sp-44.
  The `jal` at 0x3d8 calls sc_close with a0=a0 at entry (arg0), a1=ret(sc_open), a2=?, a3=?.
  The `jal` at 0x3ec calls sc_close with a0=a0 at entry (arg0), a1=ret(sc_open), a2=?, a3=?.
  The `bltz` branch at 0x320 targets 0x3b0, is taken when v0(=ret(sc_open)) < 0 (signed), and falls through when v0(=ret(sc_open)) >= 0 (signed).
  The `bltz` branch at 0x348 targets 0x3d4, is taken when v0(=ret(sc_construct_msg)) < 0 (signed), and falls through when v0(=ret(sc_construct_msg)) >= 0 (signed).
  The `bltz` branch at 0x368 targets 0x3e8, is taken when v0(=ret(sc_command)) < 0 (signed), and falls through when v0(=ret(sc_command)) >= 0 (signed).
  The `bltz` branch at 0x390 targets 0x3c8, is taken when v0(=ret(sc_interpret_resp)) < 0 (signed), and falls through when v0(=ret(sc_interpret_resp)) >= 0 (signed).
  The `beq` branch at 0x3cc targets 0x3b4 and is always taken.
  The `beq` branch at 0x3e0 targets 0x3b0 and is always taken.
  The `beq` branch at 0x3f4 targets 0x3b0 and is always taken.
  The return at 0x3c0 has v0 = one of -0x70, -0x67, -0x64, 0x0.

- `elsc_rack_bay_get` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0x3fc (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0x3fc-0x41c (32 bytes).
  It occupies 32 bytes.
  The `jal` at 0x408 calls _elsc_rack_bay_type_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=sp-16, a4=0x1.
  The return at 0x414 has v0 = ret(_elsc_rack_bay_type_get).

- `_elsc_rack_bay_type_get` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0x41c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0x41c-0x634 (536 bytes).
  It occupies 536 bytes.
  The `sw` at 0x528 stores 4 bytes to a1 (arg1 at entry) +0x0.
  2 such `sw` accesses store 4 bytes to a2 (arg2 at entry) +0x0, including `sw` at 0x540, `sw` at 0x628.
  3 such `lw` accesses load 4 bytes from a3 (arg3 at entry) +0x0, including `lw` at 0x54c, `lw` at 0x5d0, `lw` at 0x630.
  2 such `sw` accesses store 4 bytes to a3 (arg3 at entry) +0x0, including `sw` at 0x5c0, `sw` at 0x5f4.
  The `lw` at 0x61c loads 4 bytes from a2 (arg2 at entry) +0x0.
  The `jal` at 0x444 calls bzero with a0=sp-192, a1=0x80, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x458 calls sc_open with a0=a0 at entry (arg0), a1=0xffff000, a2=?, a3=?.
  The `jal` at 0x484 calls sc_construct_msg with a0=a0 at entry (arg0), a1=ret(sc_open), a2=sp-192, a3=0x80, a4=0x6, a5=0x3, a6=0x0.
  The `jal` at 0x4a4 calls sc_command_kern with a0=a0 at entry (arg0), a1=ret(sc_open), a2=sp-192, a3=sp-192, a4=sp-64.
  The `jal` at 0x4b8 calls sc_close with a0=a0 at entry (arg0), a1=ret(sc_open), a2=?, a3=?.
  The `jal` at 0x4e0 calls sc_close with a0=a0 at entry (arg0), a1=ret(sc_open), a2=?, a3=?.
  The `jal` at 0x500 calls sc_interpret_resp with a0=sp-192, a1=0x4, a2=0x0, a3=sp-60, a4=0x0, a5=a3 at entry (arg3).
  The `jal` at 0x544 calls elsc_slab_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=a4 at entry (arg4), a4=a1 at entry (arg1).
  The `jal` at 0x5d8 calls sc_close with a0=a0 at entry (arg0), a1=ret(sc_open), a2=?, a3=?.
  The `bltz` branch at 0x464 targets 0x4c4, is taken when v0(=ret(sc_open)) < 0 (signed), and falls through when v0(=ret(sc_open)) >= 0 (signed).
  The `bltz` branch at 0x48c targets 0x5d4, is taken when v0(=ret(sc_construct_msg)) < 0 (signed), and falls through when v0(=ret(sc_construct_msg)) >= 0 (signed).
  The `beq` branch at 0x4ac targets 0x4e0, is taken when v0(=ret(sc_command_kern)) == 0, and falls through when v0(=ret(sc_command_kern)) != 0.
  The `bltz` branch at 0x508 targets 0x600, is taken when v0(=ret(sc_interpret_resp)) < 0 (signed), and falls through when v0(=ret(sc_interpret_resp)) >= 0 (signed).
  The `beq` branch at 0x53c targets 0x5cc, is taken when a3(=a4) == 0, and falls through when a3(=a4) != 0.
  The `beq` branch at 0x554 targets 0x608, is taken when a2(=0x36) == a0(=[a3]), and falls through when a2(=0x36) != a0(=[a3]).
  The `beq` branch at 0x55c targets 0x5e8, is taken when v0(=ret(elsc_slab_get)) == a1(=0x4), and falls through when v0(=ret(elsc_slab_get)) != a1(=0x4).
  The `beq` branch at 0x580 targets 0x5c0, is taken when a0(?) == a5(=0x34), and falls through when a0(?) != a5(=0x34).
  The `beq` branch at 0x588 targets 0x5c0, is taken when a0(?) == v0(=0x41), and falls through when a0(?) != v0(=0x41).
  The `beq` branch at 0x590 targets 0x5c0, is taken when a0(?) == a1(=0x36), and falls through when a0(?) != a1(=0x36).
  The `beq` branch at 0x598 targets 0x5c0, is taken when a0(?) == a2(=0x37), and falls through when a0(?) != a2(=0x37).
  The `beq` branch at 0x5a0 targets 0x5c0, is taken when a0(?) == a3(=0x38), and falls through when a0(?) != a3(=0x38).
  The `beq` branch at 0x5a8 targets 0x5c0, is taken when a0(?) == a4(=0x39), and falls through when a0(?) != a4(=0x39).
  The `beq` branch at 0x5b0 targets 0x5c0, is taken when a0(?) == a5(=0x51), and falls through when a0(?) != a5(=0x51).
  The `bne` branch at 0x5b8 targets 0x5c4, is taken when a0(?) != t0(=0x30), and falls through when a0(?) == t0(=0x30).
  The `beq` branch at 0x5c4 targets 0x4c4 and is always taken.
  The `beq` branch at 0x5cc targets 0x560 and is always taken.
  The `beq` branch at 0x5e0 targets 0x4c4 and is always taken.
  The `bne` branch at 0x5e8 targets 0x564, is taken when a2(=0x36) != a0(=[a3]), and falls through when a2(=0x36) == a0(=[a3]).
  The `beq` branch at 0x5f8 targets 0x560 and is always taken.
  The `beq` branch at 0x600 targets 0x4c4 and is always taken.
  The `beq` branch at 0x62c targets 0x55c and is always taken.
  The return at 0x4d8 has v0 = one of -0x70, -0x67, -0x64, 0x0.

- `elsc_cbrick_type_get` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0x634 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0x634-0x73c (264 bytes).
  It occupies 264 bytes.
  The `jal` at 0x648 calls elsc_init with a0=sp-2544, a1=a0 at entry (arg0), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x654 calls bzero with a0=sp-160, a1=0x80, a2=?, a3=?.
  The `jal` at 0x668 calls sc_open with a0=sp-2544, a1=0xffff000, a2=?, a3=?.
  The `jal` at 0x694 calls sc_construct_msg with a0=sp-2544, a1=ret(sc_open), a2=sp-160, a3=0x80, a4=0x6, a5=0x3, a6=0x0.
  The `jal` at 0x6b4 calls sc_command_kern with a0=sp-2544, a1=ret(sc_open), a2=sp-160, a3=sp-160, a4=sp-32.
  The `jal` at 0x6c4 calls sc_close with a0=sp-2544, a1=ret(sc_open), a2=?, a3=?.
  The `jal` at 0x6e8 calls sc_close with a0=sp-2544, a1=ret(sc_open), a2=?, a3=?.
  The `jal` at 0x704 calls sc_interpret_resp with a0=sp-160, a1=0x4, a2=0x0, a3=sp-28, a4=0x0, a5=a1 at entry (arg1).
  The `jal` at 0x720 calls sc_close with a0=sp-2544, a1=ret(sc_open), a2=?, a3=?.
  The `bltz` branch at 0x674 targets 0x6d0, is taken when v0(=ret(sc_open)) < 0 (signed), and falls through when v0(=ret(sc_open)) >= 0 (signed).
  The `bltz` branch at 0x69c targets 0x71c, is taken when v0(=ret(sc_construct_msg)) < 0 (signed), and falls through when v0(=ret(sc_construct_msg)) >= 0 (signed).
  The `beq` branch at 0x6bc targets 0x6e4, is taken when v0(=ret(sc_command_kern)) == 0, and falls through when v0(=ret(sc_command_kern)) != 0.
  The `bltz` branch at 0x70c targets 0x730, is taken when v0(=ret(sc_interpret_resp)) < 0 (signed), and falls through when v0(=ret(sc_interpret_resp)) >= 0 (signed).
  The `beq` branch at 0x714 targets 0x6d4 and is always taken.
  The `beq` branch at 0x728 targets 0x6d0 and is always taken.
  The `beq` branch at 0x734 targets 0x6d4 and is always taken.
  The return at 0x6dc has v0 = one of -0x70, -0x67, -0x64, 0x0.

- `elsc_rack_bay_type_get` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0x73c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0x73c-0x758 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x744 calls _elsc_rack_bay_type_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a4=0x1.
  The return at 0x750 has v0 = ret(_elsc_rack_bay_type_get).

- `elsc_slab_get` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0x758 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0x758-0x850 (248 bytes).
  It occupies 248 bytes.
  The `jal` at 0x76c calls bzero with a0=sp-160, a1=0x80, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x780 calls sc_open with a0=a0 at entry (arg0), a1=0xffff000, a2=?, a3=?.
  The `jal` at 0x7ac calls sc_construct_msg with a0=a0 at entry (arg0), a1=ret(sc_open), a2=sp-160, a3=0x80, a4=0x6, a5=0xe, a6=0x0.
  The `jal` at 0x7cc calls sc_command_kern with a0=a0 at entry (arg0), a1=ret(sc_open), a2=sp-160, a3=sp-160, a4=sp-32.
  The `jal` at 0x7e0 calls sc_close with a0=a0 at entry (arg0), a1=ret(sc_open), a2=?, a3=?.
  The `jal` at 0x804 calls sc_close with a0=a0 at entry (arg0), a1=ret(sc_open), a2=?, a3=?.
  The `jal` at 0x818 calls sc_interpret_resp with a0=sp-160, a1=0x2, a2=0x0, a3=sp-28.
  The `jal` at 0x834 calls sc_close with a0=a0 at entry (arg0), a1=ret(sc_open), a2=?, a3=?.
  The `bltz` branch at 0x78c targets 0x7ec, is taken when v0(=ret(sc_open)) < 0 (signed), and falls through when v0(=ret(sc_open)) >= 0 (signed).
  The `bltz` branch at 0x7b4 targets 0x830, is taken when v0(=ret(sc_construct_msg)) < 0 (signed), and falls through when v0(=ret(sc_construct_msg)) >= 0 (signed).
  The `beq` branch at 0x7d4 targets 0x804, is taken when v0(=ret(sc_command_kern)) == 0, and falls through when v0(=ret(sc_command_kern)) != 0.
  The `bltz` branch at 0x820 targets 0x844, is taken when v0(=ret(sc_interpret_resp)) < 0 (signed), and falls through when v0(=ret(sc_interpret_resp)) >= 0 (signed).
  The `beq` branch at 0x828 targets 0x7f0 and is always taken.
  The `beq` branch at 0x83c targets 0x7ec and is always taken.
  The `beq` branch at 0x848 targets 0x7f0 and is always taken.
  The return at 0x7fc has v0 = one of -0x67, -0x64, ?, 0x0.

- `elsc_module_slab_get` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0x850 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0x850-0x8bc (108 bytes).
  It occupies 108 bytes.
  The `sh` at 0x89c stores 2 bytes to a1 (arg1 at entry) +0x0.
  The `sw` at 0x8a8 stores 4 bytes to a2 (arg2 at entry) +0x0.
  The `jal` at 0x870 calls _elsc_rack_bay_type_get with a0=a0 at entry (arg0), a1=sp-48, a2=sp-44, a3=sp-40, a4=0x0.
  The `jal` at 0x888 calls sc_rbt_to_moduleid with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x898 calls elsc_slab_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `bltz` branch at 0x878 targets 0x8ac, is taken when v0(=ret(_elsc_rack_bay_type_get)) < 0 (signed), and falls through when v0(=ret(_elsc_rack_bay_type_get)) >= 0 (signed).
  The return at 0x8b4 has v0 = one of ret(_elsc_rack_bay_type_get), 0x0.

- `elsc_module_get` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0x8bc (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0x8bc-0x91c (96 bytes).
  It occupies 96 bytes.
  The `jal` at 0x8d0 calls _elsc_rack_bay_type_get with a0=a0 at entry (arg0), a1=sp-32, a2=sp-28, a3=sp-24, a4=0x1.
  The `jal` at 0x900 calls sc_rbt_to_moduleid with a0=?, a1=?, a2=?, a3=?.
  The `bltz` branch at 0x8dc targets 0x90c, is taken when v0(=ret(_elsc_rack_bay_type_get)) < 0 (signed), and falls through when v0(=ret(_elsc_rack_bay_type_get)) >= 0 (signed).
  The `bne` branch at 0x8e8 targets 0x900, is taken when a0(?) != 0, and falls through when a0(?) == 0.
  The `bne` branch at 0x8f0 targets 0x900, is taken when a1(?) != 0, and falls through when a1(?) == 0.
  The `beq` branch at 0x8f8 targets 0x90c and is always taken.
  The return at 0x914 has v0 = one of ret(_elsc_rack_bay_type_get), 0x0, ret(sc_rbt_to_moduleid).

- `elsc_module_get_nasid` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0x91c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0x91c-0x9fc (224 bytes).
  It occupies 224 bytes.
  The `ld` at 0x928 loads 8 bytes from (a0 << 0x21) -0x6fffffffcc000000.
  The `jal` at 0x948 calls get_nasid with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x958 calls elsc_init with a0=sp-2400, a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0x960 calls elsc_module_get with a0=sp-2400, a1=?, a2=?, a3=?.
  The `jal` at 0x980 calls get_elsc with a0=sp-2400, a1=?, a2=?, a3=?.
  The `jal` at 0x988 calls elsc_module_get with a0=ret(get_elsc), a1=?, a2=?, a3=?.
  The `jal` at 0x99c calls peer_iobrick_rack_bay_get with a0=a0 at entry (arg0), a1=sp-2416, a2=sp-2412, a3=a3 at entry (arg3).
  The `jal` at 0x9b0 calls printf with a0=sym(.rodata), a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0x9b8 calls get_elsc with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x9cc calls peer_iobrick_type_get with a0=ret(get_elsc), a1=?, a2=?, a3=sp-2408.
  The `jal` at 0x9e4 calls sc_rbt_to_moduleid with a0=?, a1=?, a2=?, a3=?.
  The `beq` branch at 0x940 targets 0x998, is taken when at(?) == v0(=0xc000), and falls through when at(?) != v0(=0xc000).
  The `beq` branch at 0x950 targets 0x980, is taken when s0(=a0) == v0(=ret(get_nasid)), and falls through when s0(=a0) != v0(=ret(get_nasid)).
  The `beq` branch at 0x990 targets 0x96c and is always taken.
  The `beq` branch at 0x9a4 targets 0x9b8, is taken when v0(=ret(peer_iobrick_rack_bay_get)) == 0, and falls through when v0(=ret(peer_iobrick_rack_bay_get)) != 0.
  The `bltz` branch at 0x9d4 targets 0x9f4, is taken when v0(=ret(peer_iobrick_type_get)) < 0 (signed), and falls through when v0(=ret(peer_iobrick_type_get)) >= 0 (signed).
  The `beq` branch at 0x9ec targets 0x96c and is always taken.
  The `beq` branch at 0x9f4 targets 0x970 and is always taken.
  The return at 0x978 has v0 = one of ?, ret(peer_iobrick_type_get).

- `elsc_partition_set` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0x9fc (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0x9fc-0xafc (256 bytes).
  It occupies 256 bytes.
  The `jal` at 0xa14 calls bzero with a0=sp-176, a1=0x80, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa28 calls sc_open with a0=a0 at entry (arg0), a1=0xffff000, a2=?, a3=?.
  The `jal` at 0xa60 calls sc_construct_msg with a0=a0 at entry (arg0), a1=ret(sc_open), a2=sp-176, a3=0x80, a4=0x6, a5=0x1006, a6=0x2, a7=0x0.
  The `jal` at 0xa80 calls sc_command with a0=a0 at entry (arg0), a1=ret(sc_open), a2=sp-176, a3=sp-176, a4=sp-48.
  The `jal` at 0xa94 calls sc_close with a0=a0 at entry (arg0), a1=ret(sc_open), a2=?, a3=?.
  The `jal` at 0xab8 calls sc_close with a0=a0 at entry (arg0), a1=ret(sc_open), a2=?, a3=?.
  The `jal` at 0xac4 calls sc_interpret_resp with a0=sp-176, a1=0x0, a2=?, a3=?.
  The `jal` at 0xae0 calls sc_close with a0=a0 at entry (arg0), a1=ret(sc_open), a2=?, a3=?.
  The `bltz` branch at 0xa34 targets 0xaa0, is taken when v0(=ret(sc_open)) < 0 (signed), and falls through when v0(=ret(sc_open)) >= 0 (signed).
  The `bltz` branch at 0xa68 targets 0xadc, is taken when v0(=ret(sc_construct_msg)) < 0 (signed), and falls through when v0(=ret(sc_construct_msg)) >= 0 (signed).
  The `beq` branch at 0xa88 targets 0xab8, is taken when v0(=ret(sc_command)) == 0, and falls through when v0(=ret(sc_command)) != 0.
  The `bltz` branch at 0xacc targets 0xaf0, is taken when v0(=ret(sc_interpret_resp)) < 0 (signed), and falls through when v0(=ret(sc_interpret_resp)) >= 0 (signed).
  The `beq` branch at 0xad4 targets 0xaa4 and is always taken.
  The `beq` branch at 0xae8 targets 0xaa0 and is always taken.
  The `beq` branch at 0xaf4 targets 0xaa4 and is always taken.
  The return at 0xab0 has v0 = one of -0x70, -0x67, -0x64, 0x0.

- `elsc_evt_unreg` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0xafc (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0xafc-0xbec (240 bytes).
  It occupies 240 bytes.
  The `jal` at 0xb10 calls bzero with a0=sp-160, a1=0x80, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xb24 calls sc_open with a0=a0 at entry (arg0), a1=0xffff000, a2=?, a3=?.
  The `jal` at 0xb50 calls sc_construct_msg with a0=a0 at entry (arg0), a1=ret(sc_open), a2=sp-160, a3=0x80, a4=0x6, a5=0x100a, a6=0x0.
  The `jal` at 0xb70 calls sc_command_kern with a0=a0 at entry (arg0), a1=ret(sc_open), a2=sp-160, a3=sp-160, a4=sp-32.
  The `jal` at 0xb80 calls sc_close with a0=a0 at entry (arg0), a1=ret(sc_open), a2=?, a3=?.
  The `jal` at 0xba8 calls sc_close with a0=a0 at entry (arg0), a1=ret(sc_open), a2=?, a3=?.
  The `jal` at 0xbb4 calls sc_interpret_resp with a0=sp-160, a1=0x0, a2=?, a3=?.
  The `jal` at 0xbd0 calls sc_close with a0=a0 at entry (arg0), a1=ret(sc_open), a2=?, a3=?.
  The `bltz` branch at 0xb30 targets 0xb8c, is taken when v0(=ret(sc_open)) < 0 (signed), and falls through when v0(=ret(sc_open)) >= 0 (signed).
  The `bltz` branch at 0xb58 targets 0xbcc, is taken when v0(=ret(sc_construct_msg)) < 0 (signed), and falls through when v0(=ret(sc_construct_msg)) >= 0 (signed).
  The `beq` branch at 0xb78 targets 0xba4, is taken when v0(=ret(sc_command_kern)) == 0, and falls through when v0(=ret(sc_command_kern)) != 0.
  The `bltz` branch at 0xbbc targets 0xbe0, is taken when v0(=ret(sc_interpret_resp)) < 0 (signed), and falls through when v0(=ret(sc_interpret_resp)) >= 0 (signed).
  The `beq` branch at 0xbc4 targets 0xb90 and is always taken.
  The `beq` branch at 0xbd8 targets 0xb8c and is always taken.
  The `beq` branch at 0xbe4 targets 0xb90 and is always taken.
  The return at 0xb9c has v0 = one of -0x70, -0x67, -0x64, 0x0.

- `elsc_pwr_off` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0xbec (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0xbec-0xcdc (240 bytes).
  It occupies 240 bytes.
  The `jal` at 0xc00 calls bzero with a0=sp-160, a1=0x80, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xc14 calls sc_open with a0=a0 at entry (arg0), a1=0xffff000, a2=?, a3=?.
  The `jal` at 0xc40 calls sc_construct_msg with a0=a0 at entry (arg0), a1=ret(sc_open), a2=sp-160, a3=0x80, a4=0x6, a5=0x2005, a6=0x0.
  The `jal` at 0xc60 calls sc_command_kern with a0=a0 at entry (arg0), a1=ret(sc_open), a2=sp-160, a3=sp-160, a4=sp-32.
  The `jal` at 0xc70 calls sc_close with a0=a0 at entry (arg0), a1=ret(sc_open), a2=?, a3=?.
  The `jal` at 0xc98 calls sc_close with a0=a0 at entry (arg0), a1=ret(sc_open), a2=?, a3=?.
  The `jal` at 0xca4 calls sc_interpret_resp with a0=sp-160, a1=0x0, a2=?, a3=?.
  The `jal` at 0xcc0 calls sc_close with a0=a0 at entry (arg0), a1=ret(sc_open), a2=?, a3=?.
  The `bltz` branch at 0xc20 targets 0xc7c, is taken when v0(=ret(sc_open)) < 0 (signed), and falls through when v0(=ret(sc_open)) >= 0 (signed).
  The `bltz` branch at 0xc48 targets 0xcbc, is taken when v0(=ret(sc_construct_msg)) < 0 (signed), and falls through when v0(=ret(sc_construct_msg)) >= 0 (signed).
  The `beq` branch at 0xc68 targets 0xc94, is taken when v0(=ret(sc_command_kern)) == 0, and falls through when v0(=ret(sc_command_kern)) != 0.
  The `bltz` branch at 0xcac targets 0xcd0, is taken when v0(=ret(sc_interpret_resp)) < 0 (signed), and falls through when v0(=ret(sc_interpret_resp)) >= 0 (signed).
  The `beq` branch at 0xcb4 targets 0xc80 and is always taken.
  The `beq` branch at 0xcc8 targets 0xc7c and is always taken.
  The `beq` branch at 0xcd4 targets 0xc80 and is always taken.
  The return at 0xc8c has v0 = one of -0x70, -0x67, -0x64, 0x0.

- `elsc_pwr_cycle` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0xcdc (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0xcdc-0xdcc (240 bytes).
  It occupies 240 bytes.
  The `jal` at 0xcf0 calls bzero with a0=sp-160, a1=0x80, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xd04 calls sc_open with a0=a0 at entry (arg0), a1=0xffff000, a2=?, a3=?.
  The `jal` at 0xd30 calls sc_construct_msg with a0=a0 at entry (arg0), a1=ret(sc_open), a2=sp-160, a3=0x80, a4=0x6, a5=0x2006, a6=0x0.
  The `jal` at 0xd50 calls sc_command_kern with a0=a0 at entry (arg0), a1=ret(sc_open), a2=sp-160, a3=sp-160, a4=sp-32.
  The `jal` at 0xd64 calls sc_close with a0=a0 at entry (arg0), a1=ret(sc_open), a2=?, a3=?.
  The `jal` at 0xd88 calls sc_close with a0=a0 at entry (arg0), a1=ret(sc_open), a2=?, a3=?.
  The `jal` at 0xd94 calls sc_interpret_resp with a0=sp-160, a1=0x0, a2=?, a3=?.
  The `jal` at 0xdb0 calls sc_close with a0=a0 at entry (arg0), a1=ret(sc_open), a2=?, a3=?.
  The `bltz` branch at 0xd10 targets 0xd70, is taken when v0(=ret(sc_open)) < 0 (signed), and falls through when v0(=ret(sc_open)) >= 0 (signed).
  The `bltz` branch at 0xd38 targets 0xdac, is taken when v0(=ret(sc_construct_msg)) < 0 (signed), and falls through when v0(=ret(sc_construct_msg)) >= 0 (signed).
  The `beq` branch at 0xd58 targets 0xd88, is taken when v0(=ret(sc_command_kern)) == 0, and falls through when v0(=ret(sc_command_kern)) != 0.
  The `bltz` branch at 0xd9c targets 0xdc0, is taken when v0(=ret(sc_interpret_resp)) < 0 (signed), and falls through when v0(=ret(sc_interpret_resp)) >= 0 (signed).
  The `beq` branch at 0xda4 targets 0xd74 and is always taken.
  The `beq` branch at 0xdb8 targets 0xd70 and is always taken.
  The `beq` branch at 0xdc4 targets 0xd74 and is always taken.
  The return at 0xd80 has v0 = one of -0x70, -0x67, -0x64, 0x0.

- `elsc_led_set` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0xdcc (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0xdcc-0xee0 (276 bytes).
  It occupies 276 bytes.
  The `jal` at 0xde4 calls bzero with a0=sp-176, a1=0x80, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xdf8 calls sc_open with a0=a0 at entry (arg0), a1=0xffff000, a2=?, a3=?.
  The `jal` at 0xe44 calls sc_construct_msg with a0=a0 at entry (arg0), a1=ret(sc_open), a2=sp-176, a3=0x80, a4=0x6, a5=0x1009, a6=0x4, a7=0x0.
  The `jal` at 0xe64 calls sc_command_kern with a0=a0 at entry (arg0), a1=ret(sc_open), a2=sp-176, a3=sp-176, a4=sp-48.
  The `jal` at 0xe78 calls sc_close with a0=a0 at entry (arg0), a1=ret(sc_open), a2=?, a3=?.
  The `jal` at 0xe9c calls sc_close with a0=a0 at entry (arg0), a1=ret(sc_open), a2=?, a3=?.
  The `jal` at 0xea8 calls sc_interpret_resp with a0=sp-176, a1=0x0, a2=?, a3=?.
  The `jal` at 0xec4 calls sc_close with a0=a0 at entry (arg0), a1=ret(sc_open), a2=?, a3=?.
  The `bltz` branch at 0xe04 targets 0xe84, is taken when v0(=ret(sc_open)) < 0 (signed), and falls through when v0(=ret(sc_open)) >= 0 (signed).
  The `bltz` branch at 0xe4c targets 0xec0, is taken when v0(=ret(sc_construct_msg)) < 0 (signed), and falls through when v0(=ret(sc_construct_msg)) >= 0 (signed).
  The `beq` branch at 0xe6c targets 0xe9c, is taken when v0(=ret(sc_command_kern)) == 0, and falls through when v0(=ret(sc_command_kern)) != 0.
  The `bltz` branch at 0xeb0 targets 0xed4, is taken when v0(=ret(sc_interpret_resp)) < 0 (signed), and falls through when v0(=ret(sc_interpret_resp)) >= 0 (signed).
  The `beq` branch at 0xeb8 targets 0xe88 and is always taken.
  The `beq` branch at 0xecc targets 0xe84 and is always taken.
  The `beq` branch at 0xed8 targets 0xe88 and is always taken.
  The return at 0xe94 has v0 = one of -0x70, -0x67, -0x64, 0x0.

- `elsc_partition_get` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0xee0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0xee0-0xfd8 (248 bytes).
  It occupies 248 bytes.
  The `jal` at 0xef4 calls bzero with a0=sp-160, a1=0x80, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xf08 calls sc_open with a0=a0 at entry (arg0), a1=0xffff000, a2=?, a3=?.
  The `jal` at 0xf34 calls sc_construct_msg with a0=a0 at entry (arg0), a1=ret(sc_open), a2=sp-160, a3=0x80, a4=0x6, a5=0x9, a6=0x0.
  The `jal` at 0xf54 calls sc_command_kern with a0=a0 at entry (arg0), a1=ret(sc_open), a2=sp-160, a3=sp-160, a4=sp-32.
  The `jal` at 0xf64 calls sc_close with a0=a0 at entry (arg0), a1=ret(sc_open), a2=?, a3=?.
  The `jal` at 0xf8c calls sc_close with a0=a0 at entry (arg0), a1=ret(sc_open), a2=?, a3=?.
  The `jal` at 0xfa0 calls sc_interpret_resp with a0=sp-160, a1=0x2, a2=0x0, a3=sp-28.
  The `jal` at 0xfbc calls sc_close with a0=a0 at entry (arg0), a1=ret(sc_open), a2=?, a3=?.
  The `bltz` branch at 0xf14 targets 0xf70, is taken when v0(=ret(sc_open)) < 0 (signed), and falls through when v0(=ret(sc_open)) >= 0 (signed).
  The `bltz` branch at 0xf3c targets 0xfb8, is taken when v0(=ret(sc_construct_msg)) < 0 (signed), and falls through when v0(=ret(sc_construct_msg)) >= 0 (signed).
  The `beq` branch at 0xf5c targets 0xf88, is taken when v0(=ret(sc_command_kern)) == 0, and falls through when v0(=ret(sc_command_kern)) != 0.
  The `bltz` branch at 0xfa8 targets 0xfcc, is taken when v0(=ret(sc_interpret_resp)) < 0 (signed), and falls through when v0(=ret(sc_interpret_resp)) >= 0 (signed).
  The `beq` branch at 0xfb0 targets 0xf74 and is always taken.
  The `beq` branch at 0xfc4 targets 0xf70 and is always taken.
  The `beq` branch at 0xfd0 targets 0xf74 and is always taken.
  The return at 0xf80 has v0 = one of -0x67, -0x64, ?, -0x70.

- `elsc_cons_subch` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0xfd8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0xfd8-0x10d8 (256 bytes).
  It occupies 256 bytes.
  The `jal` at 0xff0 calls bzero with a0=sp-176, a1=0x80, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1004 calls sc_open with a0=a0 at entry (arg0), a1=0xffff000, a2=?, a3=?.
  The `jal` at 0x103c calls sc_construct_msg with a0=a0 at entry (arg0), a1=ret(sc_open), a2=sp-176, a3=0x80, a4=0x6, a5=0x1002, a6=0x2, a7=0x0.
  The `jal` at 0x105c calls sc_command_kern with a0=a0 at entry (arg0), a1=ret(sc_open), a2=sp-176, a3=sp-176, a4=sp-48.
  The `jal` at 0x106c calls sc_close with a0=a0 at entry (arg0), a1=ret(sc_open), a2=?, a3=?.
  The `jal` at 0x1094 calls sc_close with a0=a0 at entry (arg0), a1=ret(sc_open), a2=?, a3=?.
  The `jal` at 0x10a0 calls sc_interpret_resp with a0=sp-176, a1=0x0, a2=?, a3=?.
  The `jal` at 0x10bc calls sc_close with a0=a0 at entry (arg0), a1=ret(sc_open), a2=?, a3=?.
  The `bltz` branch at 0x1010 targets 0x1078, is taken when v0(=ret(sc_open)) < 0 (signed), and falls through when v0(=ret(sc_open)) >= 0 (signed).
  The `bltz` branch at 0x1044 targets 0x10b8, is taken when v0(=ret(sc_construct_msg)) < 0 (signed), and falls through when v0(=ret(sc_construct_msg)) >= 0 (signed).
  The `beq` branch at 0x1064 targets 0x1090, is taken when v0(=ret(sc_command_kern)) == 0, and falls through when v0(=ret(sc_command_kern)) != 0.
  The `bltz` branch at 0x10a8 targets 0x10cc, is taken when v0(=ret(sc_interpret_resp)) < 0 (signed), and falls through when v0(=ret(sc_interpret_resp)) >= 0 (signed).
  The `beq` branch at 0x10b0 targets 0x107c and is always taken.
  The `beq` branch at 0x10c4 targets 0x1078 and is always taken.
  The `beq` branch at 0x10d0 targets 0x107c and is always taken.
  The return at 0x1088 has v0 = one of -0x70, -0x67, -0x64, 0x0.

- `elsc_cons_node` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0x10d8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0x10d8-0x11c8 (240 bytes).
  It occupies 240 bytes.
  The `jal` at 0x10ec calls bzero with a0=sp-160, a1=0x80, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1100 calls sc_open with a0=a0 at entry (arg0), a1=0xffff000, a2=?, a3=?.
  The `jal` at 0x112c calls sc_construct_msg with a0=a0 at entry (arg0), a1=ret(sc_open), a2=sp-160, a3=0x80, a4=0x6, a5=0x1003, a6=0x0.
  The `jal` at 0x114c calls sc_command_kern with a0=a0 at entry (arg0), a1=ret(sc_open), a2=sp-160, a3=sp-160, a4=sp-32.
  The `jal` at 0x1160 calls sc_close with a0=a0 at entry (arg0), a1=ret(sc_open), a2=?, a3=?.
  The `jal` at 0x1184 calls sc_close with a0=a0 at entry (arg0), a1=ret(sc_open), a2=?, a3=?.
  The `jal` at 0x1190 calls sc_interpret_resp with a0=sp-160, a1=0x0, a2=?, a3=?.
  The `jal` at 0x11ac calls sc_close with a0=a0 at entry (arg0), a1=ret(sc_open), a2=?, a3=?.
  The `bltz` branch at 0x110c targets 0x116c, is taken when v0(=ret(sc_open)) < 0 (signed), and falls through when v0(=ret(sc_open)) >= 0 (signed).
  The `bltz` branch at 0x1134 targets 0x11a8, is taken when v0(=ret(sc_construct_msg)) < 0 (signed), and falls through when v0(=ret(sc_construct_msg)) >= 0 (signed).
  The `beq` branch at 0x1154 targets 0x1184, is taken when v0(=ret(sc_command_kern)) == 0, and falls through when v0(=ret(sc_command_kern)) != 0.
  The `bltz` branch at 0x1198 targets 0x11bc, is taken when v0(=ret(sc_interpret_resp)) < 0 (signed), and falls through when v0(=ret(sc_interpret_resp)) >= 0 (signed).
  The `beq` branch at 0x11a0 targets 0x1170 and is always taken.
  The `beq` branch at 0x11b4 targets 0x116c and is always taken.
  The `beq` branch at 0x11c0 targets 0x1170 and is always taken.
  The return at 0x117c has v0 = one of -0x70, -0x67, -0x64, 0x0.

- `elsc_display_line` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0x11c8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0x11c8-0x12f8 (304 bytes).
  It occupies 304 bytes.
  The `jal` at 0x11e0 calls strlen with a0=a1 at entry (arg1), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1214 calls bzero with a0=sp-176, a1=0x80, a2=?, a3=?, a5=-0x67.
  The `jal` at 0x1224 calls sc_open with a0=a0 at entry (arg0), a1=0xffff000, a2=?, a3=?.
  The `jal` at 0x1268 calls sc_construct_msg with a0=a0 at entry (arg0), a1=ret(sc_open), a2=sp-176, a3=0x80, a4=0x6, a6=0x2, a7=0x1.
  The `jal` at 0x1288 calls sc_command_kern with a0=a0 at entry (arg0), a1=ret(sc_open), a2=sp-176, a3=sp-176, a4=sp-48.
  The `jal` at 0x1298 calls sc_close with a0=a0 at entry (arg0), a1=ret(sc_open), a2=?, a3=?.
  The `jal` at 0x12a4 calls sc_interpret_resp with a0=sp-176, a1=0x0, a2=?, a3=?.
  The `jal` at 0x12d4 calls sc_close with a0=a0 at entry (arg0), a1=ret(sc_open), a2=?, a3=?.
  The `jal` at 0x12e8 calls sc_close with a0=a0 at entry (arg0), a1=ret(sc_open), a2=?, a3=?.
  The `bne` branch at 0x11f0 targets 0x1210, is taken when v0(=ret(strlen)) < 0xd (unsigned), and falls through when v0(=ret(strlen)) >= 0xd (unsigned).
  The `bltz` branch at 0x1230 targets 0x12bc, is taken when v0(=ret(sc_open)) < 0 (signed), and falls through when v0(=ret(sc_open)) >= 0 (signed).
  The `bltz` branch at 0x1270 targets 0x12d0, is taken when v0(=ret(sc_construct_msg)) < 0 (signed), and falls through when v0(=ret(sc_construct_msg)) >= 0 (signed).
  The `bltz` branch at 0x1290 targets 0x12e4, is taken when v0(=ret(sc_command_kern)) < 0 (signed), and falls through when v0(=ret(sc_command_kern)) >= 0 (signed).
  The `bltz` branch at 0x12ac targets 0x12c4, is taken when v0(=ret(sc_interpret_resp)) < 0 (signed), and falls through when v0(=ret(sc_interpret_resp)) >= 0 (signed).
  The `beq` branch at 0x12b4 targets 0x11fc and is always taken.
  The `beq` branch at 0x12bc targets 0x11fc and is always taken.
  The `beq` branch at 0x12c8 targets 0x11fc and is always taken.
  The `beq` branch at 0x12dc targets 0x11f8 and is always taken.
  The `beq` branch at 0x12f0 targets 0x11f8 and is always taken.
  The return at 0x1208 has v0 = one of -0x70, -0x67, -0x64, 0x0.

- `elsc_display_mesg` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0x12f8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0x12f8-0x13bc (196 bytes).
  It occupies 196 bytes.
  The `jal` at 0x1318 calls strlen with a0=a1 at entry (arg1), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x135c calls strncpy with a0=sp-64, a1=?, a2=0xc, a3=?.
  The `jal` at 0x1370 calls elsc_display_line with a0=a0 at entry (arg0), a1=sp-64, a2=?, a3=?.
  The `blez` branch at 0x1348 targets 0x1390, is taken when s4(?) <= 0 (signed), and falls through when s4(?) > 0 (signed).
  The `bltz` branch at 0x1378 targets 0x13b4, is taken when v0(=ret(elsc_display_line)) < 0 (signed), and falls through when v0(=ret(elsc_display_line)) >= 0 (signed).
  The `bne` branch at 0x1388 targets 0x1354, is taken when s0(?) < s4(?) (signed), and falls through when s0(?) >= s4(?) (signed).
  The `beq` branch at 0x13b4 targets 0x1398 and is always taken.
  The return at 0x13ac has v0 = one of 0x0, ret(elsc_display_line).

- `elsc_password_set` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0x13bc (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0x13bc-0x13c4 (8 bytes).
  It occupies 8 bytes.
  The return at 0x13bc has v0 = 0x0.

- `elsc_password_get` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0x13c4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0x13c4-0x13cc (8 bytes).
  It occupies 8 bytes.
  The return at 0x13c4 has v0 = 0x0.

- `sc_portspeed_get` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0x13cc (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0x13cc-0x14d4 (264 bytes).
  It occupies 264 bytes.
  The `jal` at 0x13e0 calls bzero with a0=sp-176, a1=0x80, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x13f4 calls sc_open with a0=a0 at entry (arg0), a1=0xffff000, a2=?, a3=?.
  The `jal` at 0x1420 calls sc_construct_msg with a0=a0 at entry (arg0), a1=ret(sc_open), a2=sp-176, a3=0x80, a4=0x6, a5=0xa, a6=0x0.
  The `jal` at 0x1440 calls sc_command with a0=a0 at entry (arg0), a1=ret(sc_open), a2=sp-176, a3=sp-176, a4=sp-48.
  The `jal` at 0x1450 calls sc_close with a0=a0 at entry (arg0), a1=ret(sc_open), a2=?, a3=?.
  The `jal` at 0x146c calls sc_interpret_resp with a0=sp-176, a1=0x4, a2=0x0, a3=sp-44, a4=0x0, a5=sp-40.
  The `jal` at 0x14b0 calls sc_close with a0=a0 at entry (arg0), a1=ret(sc_open), a2=?, a3=?.
  The `jal` at 0x14c4 calls sc_close with a0=a0 at entry (arg0), a1=ret(sc_open), a2=?, a3=?.
  The `bltz` branch at 0x1400 targets 0x1488, is taken when v0(=ret(sc_open)) < 0 (signed), and falls through when v0(=ret(sc_open)) >= 0 (signed).
  The `bltz` branch at 0x1428 targets 0x14ac, is taken when v0(=ret(sc_construct_msg)) < 0 (signed), and falls through when v0(=ret(sc_construct_msg)) >= 0 (signed).
  The `bltz` branch at 0x1448 targets 0x14c0, is taken when v0(=ret(sc_command)) < 0 (signed), and falls through when v0(=ret(sc_command)) >= 0 (signed).
  The `bltz` branch at 0x1474 targets 0x14a0, is taken when v0(=ret(sc_interpret_resp)) < 0 (signed), and falls through when v0(=ret(sc_interpret_resp)) >= 0 (signed).
  The `beq` branch at 0x14a4 targets 0x148c and is always taken.
  The `beq` branch at 0x14b8 targets 0x1488 and is always taken.
  The `beq` branch at 0x14cc targets 0x1488 and is always taken.
  The return at 0x1498 has v0 = one of -0x67, -0x64, 0x190, 0x258, -0x70.

- `elsc_power_query` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0x14d4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0x14d4-0x14dc (8 bytes).
  It occupies 8 bytes.
  The return at 0x14d4 has v0 = 0x1.

- `elsc_rpwr_query` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0x14dc (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0x14dc-0x14e4 (8 bytes).
  It occupies 8 bytes.
  The return at 0x14dc has v0 = -0x1.

- `elsc_power_down` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0x14e4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0x14e4-0x14ec (8 bytes).
  It occupies 8 bytes.
  The return at 0x14e4 has v0 = 0x0.

- `elsc_system_reset` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0x14ec (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0x14ec-0x15f4 (264 bytes).
  It occupies 264 bytes.
  The `jal` at 0x1500 calls bzero with a0=sp-176, a1=0x80, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1514 calls sc_open with a0=a0 at entry (arg0), a1=0xffff000, a2=?, a3=?.
  The `jal` at 0x1540 calls sc_construct_msg with a0=a0 at entry (arg0), a1=ret(sc_open), a2=sp-176, a3=0x80, a4=0x6, a5=0x2001, a6=0x0.
  The `jal` at 0x1560 calls sc_command with a0=a0 at entry (arg0), a1=ret(sc_open), a2=sp-176, a3=sp-176, a4=sp-48.
  The `jal` at 0x1574 calls sc_close with a0=a0 at entry (arg0), a1=ret(sc_open), a2=?, a3=?.
  The `jal` at 0x15ac calls sc_close with a0=a0 at entry (arg0), a1=ret(sc_open), a2=?, a3=?.
  The `jal` at 0x15b8 calls sc_interpret_resp with a0=sp-176, a1=0x0, a2=?, a3=?.
  The `jal` at 0x15dc calls sc_close with a0=a0 at entry (arg0), a1=ret(sc_open), a2=?, a3=?.
  The `bltz` branch at 0x1520 targets 0x1590, is taken when v0(=ret(sc_open)) < 0 (signed), and falls through when v0(=ret(sc_open)) >= 0 (signed).
  The `bltz` branch at 0x1548 targets 0x15d8, is taken when v0(=ret(sc_construct_msg)) < 0 (signed), and falls through when v0(=ret(sc_construct_msg)) >= 0 (signed).
  The `beq` branch at 0x1568 targets 0x15a8, is taken when v0(=ret(sc_command)) == 0, and falls through when v0(=ret(sc_command)) != 0.
  The `beq` branch at 0x1584 targets 0x15d0, is taken when a3(?) == a4(=-0x4), and falls through when a3(?) != a4(=-0x4).
  The `bltz` branch at 0x15c0 targets 0x15ec, is taken when v0(=ret(sc_interpret_resp)) < 0 (signed), and falls through when v0(=ret(sc_interpret_resp)) >= 0 (signed).
  The `beq` branch at 0x15c8 targets 0x1594 and is always taken.
  The `beq` branch at 0x15d0 targets 0x1594 and is always taken.
  The `beq` branch at 0x15e4 targets 0x1590 and is always taken.
  The `beq` branch at 0x15ec targets 0x1590 and is always taken.
  The return at 0x15a0 has v0 = one of -0x70, -0x67, -0x64, 0x0.

- `elsc_power_cycle` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0x15f4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0x15f4-0x15fc (8 bytes).
  It occupies 8 bytes.
  The return at 0x15f4 has v0 = 0x0.

- `elsc_nic_get` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0x15fc (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0x15fc-0x1618 (28 bytes).
  It occupies 28 bytes.
  The `lh` at 0x1608 loads 2 bytes from a0 (arg0 at entry) +0x0.
  The `jal` at 0x1604 calls cbrick_uid_get with a0=[a0]:2, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x1610 has v0 = ret(cbrick_uid_get).

- `_elsc_hbt` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0x1618 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0x1618-0x1620 (8 bytes).
  It occupies 8 bytes.
  The return at 0x1618 has v0 = 0x0.

- `sc_command_interp` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0x1620 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0x1620-0x186c (588 bytes).
  It occupies 588 bytes.
  The `sb` at 0x1714 stores 1 byte to a4 (arg4 at entry) +0x0.
  3 such `lh` accesses load 2 bytes from a0 (arg0 at entry) +0x0, including `lh` at 0x1748, `lh` at 0x1788, `lh` at 0x17fc.
  3 such `ld` accesses load 8 bytes from ([a0]:2 << 0x21) -0x6fffffffcc000000, including `ld` at 0x1758, `ld` at 0x1798, `ld` at 0x180c.
  The `jal` at 0x165c calls bzero with a0=sp-240, a1=0x80, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1680 calls sc_open with a0=a0 at entry (arg0), a1=?, a2=(a3 << 0xc), a3=?.
  The `jal` at 0x16b0 calls sc_construct_msg with a0=a0 at entry (arg0), a1=ret(sc_open), a2=sp-240, a3=0x80, a4=0x3, a5=0x0, a6=0x2, a7=0x1.
  The `jal` at 0x16d0 calls sc_command_kern with a0=a0 at entry (arg0), a1=ret(sc_open), a2=sp-240, a3=sp-240, a4=sp-112.
  The `jal` at 0x16e0 calls sc_close with a0=a0 at entry (arg0), a1=ret(sc_open), a2=?, a3=?.
  The `jal` at 0x16ec calls sc_interpret_resp with a0=sp-240, a1=0x0, a2=?, a3=?.
  The `jal` at 0x176c calls get_chimera_type with a0=[a0]:2, a1=?, a2=(a1 << 0x1c), a3=?, a5=0x4000.
  The `jal` at 0x17c8 calls get_chimera_type with a0=[a0]:2, a1=0x8000, a2=0xe, a3=0xf.
  The `jal` at 0x181c calls get_chimera_type with a0=[a0]:2, a1=0x8000, a2=?, a3=?, a6=0x3.
  The `jal` at 0x1838 calls sc_close with a0=a0 at entry (arg0), a1=ret(sc_open), a2=?, a3=?.
  The `jal` at 0x184c calls sc_close with a0=a0 at entry (arg0), a1=ret(sc_open), a2=?, a3=?.
  The `jal` at 0x185c calls strcpy with a0=a4 at entry (arg4), a1=sp-234, a2=?, a3=?.
  The `beq` branch at 0x1668 targets 0x1748, is taken when s2(=a1) == at(=0x4), and falls through when s2(=a1) != at(=0x4).
  The `bltz` branch at 0x1688 targets 0x1740, is taken when v0(=ret(sc_open)) < 0 (signed), and falls through when v0(=ret(sc_open)) >= 0 (signed).
  The `bltz` branch at 0x16b8 targets 0x1834, is taken when v0(=ret(sc_construct_msg)) < 0 (signed), and falls through when v0(=ret(sc_construct_msg)) >= 0 (signed).
  The `bltz` branch at 0x16d8 targets 0x1848, is taken when v0(=ret(sc_command_kern)) < 0 (signed), and falls through when v0(=ret(sc_command_kern)) >= 0 (signed).
  The `bgez` branch at 0x16f4 targets 0x171c, is taken when v0(=ret(sc_interpret_resp)) >= 0 (signed), and falls through when v0(=ret(sc_interpret_resp)) < 0 (signed).
  The `blez` branch at 0x1704 targets 0x1714, is taken when a3(?) <= 0 (signed), and falls through when a3(?) > 0 (signed).
  The `beq` branch at 0x170c targets 0x185c, is taken when a0(?) == v0(=0x1), and falls through when a0(?) != v0(=0x1).
  The `beq` branch at 0x1740 targets 0x171c and is always taken.
  The `beq` branch at 0x1764 targets 0x182c, is taken when a4(?) == a5(=0x4000), and falls through when a4(?) != a5(=0x4000).
  The `beq` branch at 0x1778 targets 0x182c, is taken when v0(=ret(get_chimera_type)) == a6(=0x3), and falls through when v0(=ret(get_chimera_type)) != a6(=0x3).
  The `beq` branch at 0x1780 targets 0x17fc, is taken when s1(=a5) == 0, and falls through when s1(=a5) != 0.
  The `bne` branch at 0x17a8 targets 0x17c8, is taken when a1(=0x8000) != a7(?), and falls through when a1(=0x8000) == a7(?).
  The `beq` branch at 0x17b0 targets 0x17c8, is taken when s1(=a5) == v0(=0x1), and falls through when s1(=a5) != v0(=0x1).
  The `beq` branch at 0x17b8 targets 0x182c, is taken when s1(=a5) == a2(=0xe), and falls through when s1(=a5) != a2(=0xe).
  The `beq` branch at 0x17c0 targets 0x182c, is taken when s1(=a5) == a3(=0xf), and falls through when s1(=a5) != a3(=0xf).
  The `beq` branch at 0x17d0 targets 0x166c, is taken when v0(=ret(get_chimera_type)) == 0, and falls through when v0(=ret(get_chimera_type)) != 0.
  The `beq` branch at 0x17dc targets 0x1670, is taken when s1(=a5) == t1(=0x1), and falls through when s1(=a5) != t1(=0x1).
  The `beq` branch at 0x17e4 targets 0x182c, is taken when s1(=a5) == a0(=0xc), and falls through when s1(=a5) != a0(=0xc).
  The `bne` branch at 0x17ec targets 0x1670, is taken when s1(=a5) != t2(=0xf), and falls through when s1(=a5) == t2(=0xf).
  The `beq` branch at 0x17f4 targets 0x182c and is always taken.
  The `beq` branch at 0x1814 targets 0x182c, is taken when a1(=0x8000) == t3(?), and falls through when a1(=0x8000) != t3(?).
  The `beq` branch at 0x1824 targets 0x1788, is taken when v0(=ret(get_chimera_type)) == 0, and falls through when v0(=ret(get_chimera_type)) != 0.
  The `beq` branch at 0x182c targets 0x166c and is always taken.
  The `beq` branch at 0x1840 targets 0x171c and is always taken.
  The `beq` branch at 0x1854 targets 0x171c and is always taken.
  The `beq` branch at 0x1864 targets 0x1718 and is always taken.
  The return at 0x1738 has v0 = one of -0x70, -0x67, -0x64, 0x0.

- `sc_power_down` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0x186c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0x186c-0x18b8 (76 bytes).
  It occupies 76 bytes.
  The `jal` at 0x1884 calls sprintf with a0=sp-80, a1=sym(.rodata), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x18a0 calls sc_command_interp with a0=a0 at entry (arg0), a1=0x0, a2=0x3ff, a3=0x3f, a4=sp-80, a5=0x0.
  The return at 0x18b0 has v0 = ret(sc_command_interp).

- `sc_power_down_all` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0x18b8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0x18b8-0x1940 (136 bytes).
  It occupies 136 bytes.
  The `ld` at 0x18b8 loads 8 bytes from abs 0xffffffffffffc400.
  The `lw` at 0x18c4 loads 4 bytes from [-0x3c00]:8 +0x8c68.
  The `jal` at 0x18dc calls elsc_partition_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x18f4 calls sprintf with a0=sp-80, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x1910 calls sc_command_interp with a0=a0 at entry (arg0), a1=0x1, a2=0x3ff, a3=0x3f, a4=sp-80, a5=0x0.
  The `jal` at 0x1930 calls sc_power_down with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `blez` branch at 0x18d4 targets 0x1930, is taken when at(=[[-0x3c00]:8+35944]) <= 0 (signed), and falls through when at(=[[-0x3c00]:8+35944]) > 0 (signed).
  The `beq` branch at 0x1938 targets 0x191c and is always taken.
  The return at 0x1928 has v0 = one of ret(sc_command_interp), ret(sc_power_down).

- `sc_set_system_state` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0x1940 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0x1940-0x1a4c (268 bytes).
  It occupies 268 bytes.
  The `ld` at 0x19ac loads 8 bytes from abs 0x9200000001000020.
  The `jal` at 0x1958 calls bzero with a0=sp-176, a1=0x80, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x196c calls sc_open with a0=a0 at entry (arg0), a1=0xffff000, a2=?, a3=?.
  The `jal` at 0x19b4 calls sc_construct_msg with a0=a0 at entry (arg0), a1=ret(sc_open), a2=sp-176, a3=0x80, a4=0x6, a5=0x100c, a6=0x4, a7=0x0.
  The `jal` at 0x19d4 calls sc_command_kern with a0=a0 at entry (arg0), a1=ret(sc_open), a2=sp-176, a3=sp-176, a4=sp-48.
  The `jal` at 0x19e4 calls sc_close with a0=a0 at entry (arg0), a1=ret(sc_open), a2=?, a3=?.
  The `jal` at 0x19f0 calls sc_interpret_resp with a0=sp-176, a1=0x0, a2=?, a3=?.
  The `jal` at 0x1a28 calls sc_close with a0=a0 at entry (arg0), a1=ret(sc_open), a2=?, a3=?.
  The `jal` at 0x1a3c calls sc_close with a0=a0 at entry (arg0), a1=ret(sc_open), a2=?, a3=?.
  The `bltz` branch at 0x1978 targets 0x1a00, is taken when v0(=ret(sc_open)) < 0 (signed), and falls through when v0(=ret(sc_open)) >= 0 (signed).
  The `bltz` branch at 0x19bc targets 0x1a24, is taken when v0(=ret(sc_construct_msg)) < 0 (signed), and falls through when v0(=ret(sc_construct_msg)) >= 0 (signed).
  The `bltz` branch at 0x19dc targets 0x1a38, is taken when v0(=ret(sc_command_kern)) < 0 (signed), and falls through when v0(=ret(sc_command_kern)) >= 0 (signed).
  The `bltz` branch at 0x19f8 targets 0x1a18, is taken when v0(=ret(sc_interpret_resp)) < 0 (signed), and falls through when v0(=ret(sc_interpret_resp)) >= 0 (signed).
  The `beq` branch at 0x1a1c targets 0x1a04 and is always taken.
  The `beq` branch at 0x1a30 targets 0x1a00 and is always taken.
  The `beq` branch at 0x1a44 targets 0x1a00 and is always taken.
  The return at 0x1a10 has v0 = one of -0x70, -0x67, -0x64, 0x0.

- `sc_rbt_to_moduleid` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0x1a4c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0x1a4c-0x1c60 (532 bytes).
  It occupies 532 bytes.
  The `lbu` at 0x1bf8 loads 1 byte from ?.
  The `beq` branch at 0x1a5c targets 0x1bd8, is taken when a1 >= 0x40 (unsigned), and falls through when a1 < 0x40 (unsigned).
  The `beq` branch at 0x1aa4 targets 0x1c24, is taken when a3(?) >= 0x2 (unsigned), and falls through when a3(?) < 0x2 (unsigned).
  The `bne` branch at 0x1b04 targets 0x1c2c, is taken when at(?) < a0(?) (unsigned), and falls through when at(?) >= a0(?) (unsigned).
  The `bne` branch at 0x1b58 targets 0x1c50, is taken when a3(=one of 0x3, 0x7) < at(?) (unsigned), and falls through when a3(=one of 0x3, 0x7) >= at(?) (unsigned).
  The `beq` branch at 0x1b60 targets 0x1be4, is taken when a2 == t1(=0x25), and falls through when a2 != t1(=0x25).
  The `beq` branch at 0x1b68 targets 0x1be4, is taken when a2 == t0(=0x23), and falls through when a2 != t0(=0x23).
  The `beq` branch at 0x1b70 targets 0x1be4, is taken when a2 == t0(=0x45), and falls through when a2 != t0(=0x45).
  The `beq` branch at 0x1b7c targets 0x1c58, is taken when a2 == t1(=0x3d), and falls through when a2 != t1(=0x3d).
  The `beq` branch at 0x1b84 targets 0x1c58, is taken when a2 == a7(=0x56), and falls through when a2 != a7(=0x56).
  The `beq` branch at 0x1b8c targets 0x1bd0, is taken when a2 == t2(=0x34), and falls through when a2 != t2(=0x34).
  The `beq` branch at 0x1b98 targets 0x1bd0, is taken when a2 == t3(=0x41), and falls through when a2 != t3(=0x41).
  The `beq` branch at 0x1ba0 targets 0x1bd0, is taken when a2 == t8(=0x36), and falls through when a2 != t8(=0x36).
  The `beq` branch at 0x1ba8 targets 0x1bd0, is taken when a2 == t9(=0x37), and falls through when a2 != t9(=0x37).
  The `beq` branch at 0x1bb0 targets 0x1bd0, is taken when a2 == v0(=0x38), and falls through when a2 != v0(=0x38).
  The `beq` branch at 0x1bb8 targets 0x1bd0, is taken when a2 == at(=0x39), and falls through when a2 != at(=0x39).
  The `beq` branch at 0x1bc0 targets 0x1bd0, is taken when a2 == v0(=0x51), and falls through when a2 != v0(=0x51).
  The `bne` branch at 0x1bc8 targets 0x1bec, is taken when a2 != v1(=0x30), and falls through when a2 == v1(=0x30).
  The `beq` branch at 0x1bd0 targets 0x1be8 and is always taken.
  The `beq` branch at 0x1bfc targets 0x1c34, is taken when a2(?) == v0(?), and falls through when a2(?) != v0(?).
  The `bne` branch at 0x1c14 targets 0x1bf8, is taken when a0(?) < 0x10 (unsigned), and falls through when a0(?) >= 0x10 (unsigned).
  The `beq` branch at 0x1c1c targets 0x1bdc and is always taken.
  The `beq` branch at 0x1c24 targets 0x1bdc and is always taken.
  The `beq` branch at 0x1c2c targets 0x1bdc and is always taken.
  The `beq` branch at 0x1c48 targets 0x1bdc and is always taken.
  The `beq` branch at 0x1c50 targets 0x1bdc and is always taken.
  The `beq` branch at 0x1c58 targets 0x1be8 and is always taken.
  The return at 0x1bdc has v0 = one of -0x1, ?.

- `router_module_get` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0x1c60 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0x1c60-0x1cd0 (112 bytes).
  It occupies 112 bytes.
  The `jal` at 0x1c74 calls sc_init with a0=sp-2400, a1=a0 at entry (arg0), a2=a1 at entry (arg1), a3=a3 at entry (arg3).
  The `jal` at 0x1c84 calls elsc_rack_bay_get with a0=sp-2400, a1=sp-16, a2=sp-12, a3=?.
  The `jal` at 0x1cb4 calls sc_rbt_to_moduleid with a0=?, a1=?, a2=0x52, a3=?.
  The `bltz` branch at 0x1c90 targets 0x1cc0, is taken when v0(=ret(elsc_rack_bay_get)) < 0 (signed), and falls through when v0(=ret(elsc_rack_bay_get)) >= 0 (signed).
  The `bne` branch at 0x1c9c targets 0x1cb4, is taken when a0(?) != 0, and falls through when a0(?) == 0.
  The `bne` branch at 0x1ca4 targets 0x1cb4, is taken when a1(?) != 0, and falls through when a1(?) == 0.
  The `beq` branch at 0x1cac targets 0x1cc0 and is always taken.
  The return at 0x1cc8 has v0 = one of ret(elsc_rack_bay_get), 0x0, ret(sc_rbt_to_moduleid).

- `iobrick_rack_bay_type_get` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0x1cd0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0x1cd0-0x1ef8 (552 bytes).
  It occupies 552 bytes.
  3 such `lh` accesses load 2 bytes from a0 (arg0 at entry) +0x0, including `lh` at 0x1cd0, `lh` at 0x1d30, `lh` at 0x1dac.
  3 such `ld` accesses load 8 bytes from ([a0]:2 << 0x21) -0x6fffffffcc000000, including `ld` at 0x1cec, `ld` at 0x1d40, `ld` at 0x1dbc.
  The `sw` at 0x1ebc stores 4 bytes to a1 (arg1 at entry) +0x0.
  The `sw` at 0x1ed4 stores 4 bytes to a2 (arg2 at entry) +0x0.
  The `jal` at 0x1d14 calls get_chimera_type with a0=[a0]:2, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1d70 calls get_chimera_type with a0=[a0]:2, a1=?, a2=([a0]:2 << 0x21), a3=?, a4=0x1.
  The `jal` at 0x1dcc calls get_chimera_type with a0=[a0]:2, a1=0xfff0000, a2=?, a3=([a0]:2 << 0x21).
  The `jal` at 0x1de4 calls sc_open with a0=a0 at entry (arg0), a1=one of 0xffff000, 0x4ffff000, a2=?, a3=?.
  The `jal` at 0x1dfc calls bzero with a0=sp-192, a1=0x80, a2=?, a3=?.
  The `jal` at 0x1e1c calls sc_construct_msg with a0=a0 at entry (arg0), a1=ret(sc_open), a2=sp-192, a3=0x80, a4=0x6, a5=0x3, a6=0x0.
  The `jal` at 0x1e3c calls sc_command_kern with a0=a0 at entry (arg0), a1=ret(sc_open), a2=sp-192, a3=sp-192, a4=sp-64.
  The `jal` at 0x1e4c calls sc_close with a0=a0 at entry (arg0), a1=ret(sc_open), a2=?, a3=?.
  The `jal` at 0x1e74 calls sc_close with a0=a0 at entry (arg0), a1=ret(sc_open), a2=?, a3=?.
  The `jal` at 0x1e90 calls sc_interpret_resp with a0=sp-192, a1=0x4, a2=0x0, a3=sp-60, a4=0x0, a5=a3 at entry (arg3).
  The `jal` at 0x1edc calls sc_close with a0=a0 at entry (arg0), a1=ret(sc_open), a2=?, a3=?.
  The `beq` branch at 0x1d0c targets 0x1ddc, is taken when at(?) == v1(=0x4000), and falls through when at(?) != v1(=0x4000).
  The `beq` branch at 0x1d20 targets 0x1ddc, is taken when v0(=ret(get_chimera_type)) == a0(=0x3), and falls through when v0(=ret(get_chimera_type)) != a0(=0x3).
  The `beq` branch at 0x1d28 targets 0x1dac, is taken when s1(=a4) == 0, and falls through when s1(=a4) != 0.
  The `bne` branch at 0x1d50 targets 0x1d70, is taken when a0(=0x8000) != a1(?), and falls through when a0(=0x8000) == a1(?).
  The `beq` branch at 0x1d58 targets 0x1d70, is taken when s1(=a4) == a4(=0x1), and falls through when s1(=a4) != a4(=0x1).
  The `beq` branch at 0x1d60 targets 0x1de0, is taken when s1(=a4) == t0(=0xe), and falls through when s1(=a4) != t0(=0xe).
  The `beq` branch at 0x1d68 targets 0x1de0, is taken when s1(=a4) == t1(=0xf), and falls through when s1(=a4) != t1(=0xf).
  The `beq` branch at 0x1d78 targets 0x1da0, is taken when v0(=ret(get_chimera_type)) == 0, and falls through when v0(=ret(get_chimera_type)) != 0.
  The `beq` branch at 0x1d84 targets 0x1da4, is taken when s1(=a4) == a3(=0x1), and falls through when s1(=a4) != a3(=0x1).
  The `beq` branch at 0x1d8c targets 0x1de0, is taken when s1(=a4) == a0(=0xc), and falls through when s1(=a4) != a0(=0xc).
  The `beq` branch at 0x1d98 targets 0x1de0, is taken when s1(=a4) == a4(=0xf), and falls through when s1(=a4) != a4(=0xf).
  The `beq` branch at 0x1da4 targets 0x1de4 and is always taken.
  The `beq` branch at 0x1dc4 targets 0x1de0, is taken when a0(=0x8000) == a2(?), and falls through when a0(=0x8000) != a2(?).
  The `beq` branch at 0x1dd4 targets 0x1d30, is taken when v0(=ret(get_chimera_type)) == 0, and falls through when v0(=ret(get_chimera_type)) != 0.
  The `bltz` branch at 0x1df0 targets 0x1e58, is taken when v0(=ret(sc_open)) < 0 (signed), and falls through when v0(=ret(sc_open)) >= 0 (signed).
  The `bltz` branch at 0x1e24 targets 0x1ed8, is taken when v0(=ret(sc_construct_msg)) < 0 (signed), and falls through when v0(=ret(sc_construct_msg)) >= 0 (signed).
  The `beq` branch at 0x1e44 targets 0x1e70, is taken when v0(=ret(sc_command_kern)) == 0, and falls through when v0(=ret(sc_command_kern)) != 0.
  The `bltz` branch at 0x1e98 targets 0x1eec, is taken when v0(=ret(sc_interpret_resp)) < 0 (signed), and falls through when v0(=ret(sc_interpret_resp)) >= 0 (signed).
  The `beq` branch at 0x1ed0 targets 0x1e58 and is always taken.
  The `beq` branch at 0x1ee4 targets 0x1e58 and is always taken.
  The `beq` branch at 0x1ef0 targets 0x1e5c and is always taken.
  The return at 0x1e68 has v0 = one of -0x70, -0x67, -0x64, 0x0.

- `iobrick_module_get` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0x1ef8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0x1ef8-0x1f74 (124 bytes).
  It occupies 124 bytes.
  The `jal` at 0x1f10 calls iobrick_rack_bay_type_get with a0=a0 at entry (arg0), a1=sp-32, a2=sp-28, a3=sp-24, a4=a1 at entry (arg1).
  The `jal` at 0x1f2c calls iobrick_rack_bay_type_get with a0=a0 at entry (arg0), a1=sp-32, a2=sp-28, a3=sp-24, a4=0x0.
  The `jal` at 0x1f44 calls iobrick_convert_l1type_generic with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1f58 calls sc_rbt_to_moduleid with a0=?, a1=?, a2=ret(iobrick_convert_l1type_generic), a3=?.
  The `bgez` branch at 0x1f18 targets 0x1f44, is taken when v0(=ret(iobrick_rack_bay_type_get)) >= 0 (signed), and falls through when v0(=ret(iobrick_rack_bay_type_get)) < 0 (signed).
  The `bgez` branch at 0x1f34 targets 0x1f44, is taken when v0(=ret(iobrick_rack_bay_type_get)) >= 0 (signed), and falls through when v0(=ret(iobrick_rack_bay_type_get)) < 0 (signed).
  The `beq` branch at 0x1f3c targets 0x1f68 and is always taken.
  The return at 0x1f6c has v0 = one of ret(iobrick_rack_bay_type_get), ret(sc_rbt_to_moduleid).

- `iobrick_module_get_nasid` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0x1f74 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0x1f74-0x2040 (204 bytes).
  It occupies 204 bytes.
  The `ld` at 0x1fa0 loads 8 bytes from (a0 << 0x21) -0x6fffffffcc000000.
  The `jal` at 0x1f88 calls get_elsc with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1fb4 calls get_nasid with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x1fc8 calls elsc_init with a0=sp-2424, a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0x1fd4 calls iobrick_module_get with a0=sp-2424, a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0x1ff8 calls iobrick_module_get with a0=?, a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0x200c calls peer_iobrick_rack_bay_get with a0=a0 at entry (arg0), a1=sp-2432, a2=sp-2428, a3=?.
  The `jal` at 0x2020 calls printf with a0=sym(.rodata), a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0x2030 calls peer_iobrick_module_get with a0=?, a1=?, a2=?, a3=?.
  The `beq` branch at 0x1fac targets 0x2008, is taken when at(?) == v0(=0xc000), and falls through when at(?) != v0(=0xc000).
  The `beq` branch at 0x1fbc targets 0x1ff8, is taken when s0(=a0) == v0(=ret(get_nasid)), and falls through when s0(=a0) != v0(=ret(get_nasid)).
  The `beq` branch at 0x2000 targets 0x1fe0 and is always taken.
  The `beq` branch at 0x2014 targets 0x2028, is taken when v0(=ret(peer_iobrick_rack_bay_get)) == 0, and falls through when v0(=ret(peer_iobrick_rack_bay_get)) != 0.
  The `beq` branch at 0x2038 targets 0x1fe0 and is always taken.
  The return at 0x1ff0 has v0 = one of ret(iobrick_module_get), ret(peer_iobrick_module_get).

- `iobrick_real_l1type_get_nasid` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0x2040 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0x2040-0x2188 (328 bytes).
  It occupies 328 bytes.
  The `ld` at 0x2070 loads 8 bytes from (a0 << 0x21) -0x6fffffffcc000000.
  The `jal` at 0x2058 calls get_elsc with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x2084 calls get_nasid with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x2094 calls elsc_init with a0=sp-2416, a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0x20ac calls iobrick_rack_bay_type_get with a0=sp-2416, a1=sp-2432, a2=sp-2428, a3=sp-2424, a4=a1 at entry (arg1).
  The `jal` at 0x20cc calls iobrick_rack_bay_type_get with a0=sp-2416, a1=sp-2432, a2=sp-2428, a3=sp-2424, a4=0x0.
  The `jal` at 0x20f4 calls iobrick_rack_bay_type_get with a0=ret(get_elsc), a1=sp-2432, a2=sp-2428, a3=sp-2424, a4=a1 at entry (arg1).
  The `jal` at 0x2124 calls peer_iobrick_rack_bay_get with a0=a0 at entry (arg0), a1=sp-2432, a2=sp-2428, a3=?.
  The `jal` at 0x2138 calls printf with a0=sym(.rodata), a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0x214c calls peer_iobrick_type_get with a0=ret(get_elsc), a1=?, a2=?, a3=sp-2424.
  The `jal` at 0x2170 calls iobrick_rack_bay_type_get with a0=ret(get_elsc), a1=sp-2432, a2=sp-2428, a3=sp-2424, a4=0x0.
  The `beq` branch at 0x207c targets 0x2120, is taken when at(?) == v0(=0xc000), and falls through when at(?) != v0(=0xc000).
  The `beq` branch at 0x208c targets 0x20e4, is taken when s0(=a0) == v0(=ret(get_nasid)), and falls through when s0(=a0) != v0(=ret(get_nasid)).
  The `bgez` branch at 0x20b4 targets 0x2108, is taken when v0(=ret(iobrick_rack_bay_type_get)) >= 0 (signed), and falls through when v0(=ret(iobrick_rack_bay_type_get)) < 0 (signed).
  The `bgez` branch at 0x20d4 targets 0x2104, is taken when v0(=ret(iobrick_rack_bay_type_get)) >= 0 (signed), and falls through when v0(=ret(iobrick_rack_bay_type_get)) < 0 (signed).
  The `beq` branch at 0x20dc targets 0x210c and is always taken.
  The `bltz` branch at 0x20fc targets 0x2164, is taken when v0(=ret(iobrick_rack_bay_type_get)) < 0 (signed), and falls through when v0(=ret(iobrick_rack_bay_type_get)) >= 0 (signed).
  The `beq` branch at 0x212c targets 0x2140, is taken when v0(=ret(peer_iobrick_rack_bay_get)) == 0, and falls through when v0(=ret(peer_iobrick_rack_bay_get)) != 0.
  The `bgez` branch at 0x2154 targets 0x2104, is taken when v0(=ret(peer_iobrick_type_get)) >= 0 (signed), and falls through when v0(=ret(peer_iobrick_type_get)) < 0 (signed).
  The `beq` branch at 0x215c targets 0x210c and is always taken.
  The `bgez` branch at 0x2178 targets 0x2104, is taken when v0(=ret(iobrick_rack_bay_type_get)) >= 0 (signed), and falls through when v0(=ret(iobrick_rack_bay_type_get)) < 0 (signed).
  The `beq` branch at 0x2180 targets 0x210c and is always taken.
  The return at 0x2118 has v0 = one of ret(iobrick_rack_bay_type_get), ?, ret(peer_iobrick_type_get).

- `iobrick_has_baseio` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0x2188 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0x2188-0x2260 (216 bytes).
  It occupies 216 bytes.
  The `ld` at 0x2194 loads 8 bytes from (a0 << 0x21) -0x6fffffffcc000000.
  The `ld` at 0x21c0 loads 8 bytes from ((a0 << 0x21)+0x9600000000000000 | 0x2000) +0x48.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0x21d0, `lw` at 0x2224.
  The `lbu` at 0x2200 loads 1 byte from ?.
  The `jal` at 0x224c calls chk_for_pebrick with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=0x9600000000000000, a4=(a0 << 0x21), a5=(a0 << 0x21)+0x9600000000000000.
  The `beq` branch at 0x21b4 targets 0x224c, is taken when at(?) == v1(=0xc000), and falls through when at(?) != v1(=0xc000).
  The `beq` branch at 0x21dc targets 0x21e8, is taken when t0(?) == 0, and falls through when t0(?) != 0.
  The `beq` branch at 0x21ec targets 0x2244, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x2210 targets 0x2224, is taken when (a4(?) & 0x10) == 0, and falls through when (a4(?) & 0x10) != 0.
  The `beq` branch at 0x2230 targets 0x223c, is taken when t0(?) == 0, and falls through when t0(?) != 0.
  The `bne` branch at 0x223c targets 0x2200, is taken when a0(?) != 0, and falls through when a0(?) == 0.
  The `beq` branch at 0x2244 targets 0x221c and is always taken.
  The `beq` branch at 0x2258 targets 0x21e8 and is always taken.
  The return at 0x221c has v0 = one of 0x0, 0x1.

- `iobrick_l1type_get_nasid` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0x2260 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0x2260-0x2308 (168 bytes).
  It occupies 168 bytes.
  The `lh` at 0x2288 loads 2 bytes from (sym(nasid_to_compact_node) + (a0 + a0)) +0x0.
  The `ld` at 0x22c0 loads 8 bytes from abs 0xffffffffffffc400.
  The `ld` at 0x22c8 loads 8 bytes from [-0x3c00]:8 +0x0.
  The `ld` at 0x22d4 loads 8 bytes from ([[-0x3c00]:8]:8 + ([(sym(nasid_to_compact_node) + (a0 + a0))]:2 << 0x3)) +0x0.
  The `lh` at 0x22e0 loads 2 bytes from [([[-0x3c00]:8]:8 + ([(sym(nasid_to_compact_node) + (a0 + a0))]:2 << 0x3))]:8 +0x8600.
  The `jal` at 0x226c calls iobrick_real_l1type_get_nasid with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x22a8 calls iobrick_has_baseio with a0=a0 at entry (arg0), a1=(a0 + a0), a2=?, a3=?.
  The `jal` at 0x22f0 calls iobrick_has_baseio with a0=[[([[-0x3c00]:8]:8 + ([(sym(nasid_to_compact_node) + (a0 + a0))]:2 << 0x3))]:8+34304]:2, a1=[([[-0x3c00]:8]:8 + ([(sym(nasid_to_compact_node) + (a0 + a0))]:2 << 0x3))]:8, a2=([(sym(nasid_to_compact_node) + (a0 + a0))]:2 << 0x3), a3=-0x1.
  The `beq` branch at 0x228c targets 0x22a8, is taken when v0(=ret(iobrick_real_l1type_get_nasid)) == at(=0x23), and falls through when v0(=ret(iobrick_real_l1type_get_nasid)) != at(=0x23).
  The `beq` branch at 0x22b0 targets 0x22c0, is taken when v0(=ret(iobrick_has_baseio)) == 0, and falls through when v0(=ret(iobrick_has_baseio)) != 0.
  The `beq` branch at 0x22b8 targets 0x2298 and is always taken.
  The `beq` branch at 0x22e8 targets 0x2298, is taken when a0(=[[([[-0x3c00]:8]:8 + ([(sym(nasid_to_compact_node) + (a0 + a0))]:2 << 0x3))]:8+34304]:2) == a3(=-0x1), and falls through when a0(=[[([[-0x3c00]:8]:8 + ([(sym(nasid_to_compact_node) + (a0 + a0))]:2 << 0x3))]:8+34304]:2) != a3(=-0x1).
  The `beq` branch at 0x22f8 targets 0x2298, is taken when v0(=ret(iobrick_has_baseio)) == 0, and falls through when v0(=ret(iobrick_has_baseio)) != 0.
  The `beq` branch at 0x2300 targets 0x2298 and is always taken.
  The return at 0x22a0 has v0 = one of ret(iobrick_real_l1type_get_nasid), 0x3d.

- `iobrick_convert_l1type_generic` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0x2308 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0x2308-0x236c (100 bytes).
  It occupies 100 bytes.
  The `ld` at 0x232c loads 8 bytes from (sym(.rodata) + (a0-38 << 0x3)) +0x0.
  Calls (unknown callee) via register with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=(sym(.rodata) + (a0-38 << 0x3)), a4=[(sym(.rodata) + (a0-38 << 0x3))]:8 (`jr` at 0x2330).
  The `beq` branch at 0x2324 targets 0x233c, is taken when a4(=a0-38) >= 0x34 (unsigned), and falls through when a4(=a0-38) < 0x34 (unsigned).
  The return at 0x233c has v0 = a0.
  The instructions from 0x2338 to 0x2338 are not reached by any path from the entry, and their branches are not listed.
  The instructions from 0x2344 to 0x2368 are not reached by any path from the entry, and their branches are not listed.
  The indirect jump at 0x2330 uses a jump table whose successors are unresolved.

- `iobrick_portspeed_get_nasid` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0x236c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0x236c-0x2428 (188 bytes).
  It occupies 188 bytes.
  The `ld` at 0x2390 loads 8 bytes from (a0 << 0x21) -0x6fffffffcc000000.
  The `jal` at 0x2378 calls get_elsc with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x23a4 calls get_nasid with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x23b4 calls elsc_init with a0=sp-2408, a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0x23bc calls sc_portspeed_get with a0=sp-2408, a1=?, a2=?, a3=?.
  The `jal` at 0x23dc calls sc_portspeed_get with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x23f0 calls peer_iobrick_rack_bay_get with a0=a0 at entry (arg0), a1=sp-2416, a2=sp-2412, a3=?.
  The `jal` at 0x2408 calls printf with a0=sym(.rodata), a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0x2418 calls peer_iobrick_portspeed_get with a0=?, a1=?, a2=?, a3=?.
  The `beq` branch at 0x239c targets 0x23ec, is taken when at(?) == v0(=0xc000), and falls through when at(?) != v0(=0xc000).
  The `beq` branch at 0x23ac targets 0x23dc, is taken when s0(=a0) == v0(=ret(get_nasid)), and falls through when s0(=a0) != v0(=ret(get_nasid)).
  The `beq` branch at 0x23e4 targets 0x23c8 and is always taken.
  The `beq` branch at 0x23f8 targets 0x2414, is taken when v0(=ret(peer_iobrick_rack_bay_get)) == 0, and falls through when v0(=ret(peer_iobrick_rack_bay_get)) != 0.
  The `beq` branch at 0x2420 targets 0x23c8 and is always taken.
  The return at 0x23d4 has v0 = one of ret(sc_portspeed_get), ret(peer_iobrick_portspeed_get).

- `iobrick_attached_bricks` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0x2428 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0x2428-0x2620 (504 bytes).
  It occupies 504 bytes.
  The `lh` at 0x2428 loads 2 bytes from a0 (arg0 at entry) +0x0.
  2 such `ld` accesses load 8 bytes from ([a0]:2 << 0x21) -0x6fffffffcc000000, including `ld` at 0x2444, `ld` at 0x246c.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0x25b8, `lw` at 0x25d8.
  3 such `sw` accesses store 4 bytes to ?, including `sw` at 0x25c8, `sw` at 0x25d4, `sw` at 0x25f8.
  The `jal` at 0x247c calls get_chimera_type with a0=[a0]:2, a1=0x4000, a2=a2 at entry (arg2), a3=a3 at entry (arg3), a7=[a0]:2.
  The `jal` at 0x2490 calls sc_open with a0=a0 at entry (arg0), a1=0xffff000, a2=?, a3=?.
  The `jal` at 0x24a4 calls bzero with a0=sp-208, a1=0x80, a2=?, a3=?.
  The `jal` at 0x24c4 calls sc_construct_msg with a0=a0 at entry (arg0), a1=ret(sc_open), a2=sp-208, a3=0x80, a4=0x6, a5=0xc, a6=0x0.
  The `jal` at 0x24e4 calls sc_command with a0=a0 at entry (arg0), a1=ret(sc_open), a2=sp-208, a3=sp-208, a4=sp-80.
  The `jal` at 0x24f8 calls sc_close with a0=a0 at entry (arg0), a1=ret(sc_open), a2=?, a3=?.
  The `jal` at 0x2520 calls sc_open with a0=a0 at entry (arg0), a1=0x4ffff000, a2=?, a3=?.
  The `jal` at 0x2538 calls sc_close with a0=a0 at entry (arg0), a1=ret(sc_open), a2=?, a3=?.
  The `jal` at 0x259c calls sc_interpret_resp with a0=sp-208, a1=0x10, a2=0x0, a3=sp-72, a4=0x0, a5=a3 at entry (arg3), a6=0x0, a7=sp-68.
  The `jal` at 0x2608 calls sc_close with a0=a0 at entry (arg0), a1=ret(sc_open), a2=?, a3=?.
  The `beq` branch at 0x2460 targets 0x2488, is taken when at(?) == v1(=0x8000), and falls through when at(?) != v1(=0x8000).
  The `beq` branch at 0x2474 targets 0x248c, is taken when a0(?) == a1(=0x4000), and falls through when a0(?) != a1(=0x4000).
  The `beq` branch at 0x2484 targets 0x2518, is taken when v0(=ret(get_chimera_type)) == 0, and falls through when v0(=ret(get_chimera_type)) != 0.
  The `bltz` branch at 0x2498 targets 0x2530, is taken when v0(=ret(sc_open)) < 0 (signed), and falls through when v0(=ret(sc_open)) >= 0 (signed).
  The `bltz` branch at 0x24cc targets 0x2604, is taken when v0(=ret(sc_construct_msg)) < 0 (signed), and falls through when v0(=ret(sc_construct_msg)) >= 0 (signed).
  The `beq` branch at 0x24ec targets 0x2538, is taken when v0(=ret(sc_command)) == 0, and falls through when v0(=ret(sc_command)) != 0.
  The `bgez` branch at 0x2528 targets 0x24a0, is taken when v0(=ret(sc_open)) >= 0 (signed), and falls through when v0(=ret(sc_open)) < 0 (signed).
  The `beq` branch at 0x2530 targets 0x2504 and is always taken.
  The `bltz` branch at 0x25a4 targets 0x2618, is taken when v0(=ret(sc_interpret_resp)) < 0 (signed), and falls through when v0(=ret(sc_interpret_resp)) >= 0 (signed).
  The `bne` branch at 0x25f4 targets 0x25ac, is taken when v0(?) < 0x4 (signed), and falls through when v0(?) >= 0x4 (signed).
  The `beq` branch at 0x25fc targets 0x2504 and is always taken.
  The `beq` branch at 0x2610 targets 0x2504 and is always taken.
  The `beq` branch at 0x2618 targets 0x2504 and is always taken.
  The return at 0x2510 has v0 = one of -0x70, -0x67, -0x64, 0x0.

- `iobrick_attached_modids_all` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0x2620 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0x2620-0x2710 (240 bytes).
  It occupies 240 bytes.
  The `lw` at 0x2670 loads 4 bytes from ?.
  The `sh` at 0x26a0 stores 2 bytes to a1 (arg1 at entry) +0x0.
  The `sh` at 0x26b8 stores 2 bytes to a2 (arg2 at entry) +0x0.
  The `sh` at 0x26d0 stores 2 bytes to a3 (arg3 at entry) +0x0.
  The `sh` at 0x26ec stores 2 bytes to a4 (arg4 at entry) +0x0.
  2 such `sw` accesses store 4 bytes to ?, including `sw` at 0x2704, `sw` at 0x270c.
  The `jal` at 0x2640 calls iobrick_attached_bricks with a0=a0 at entry (arg0), a1=sp-96, a2=sp-80, a3=sp-64.
  The `jal` at 0x2694 calls sc_rbt_to_moduleid with a0=?, a1=?, a2=?, a3=?, a6=sp-64, a7=0x26.
  The `jal` at 0x26ac calls sc_rbt_to_moduleid with a0=?, a1=?, a2=?, a3=?, a6=a1 at entry (arg1).
  The `jal` at 0x26c4 calls sc_rbt_to_moduleid with a0=?, a1=?, a2=?, a3=?, a7=a2 at entry (arg2).
  The `jal` at 0x26dc calls sc_rbt_to_moduleid with a0=?, a1=?, a2=?, a3=?.
  The `bltz` branch at 0x264c targets 0x26f0, is taken when v0(=ret(iobrick_attached_bricks)) < 0 (signed), and falls through when v0(=ret(iobrick_attached_bricks)) >= 0 (signed).
  The `beq` branch at 0x2678 targets 0x2700, is taken when a7(=0x26) == a3(?), and falls through when a7(=0x26) != a3(?).
  The `beq` branch at 0x2680 targets 0x2708, is taken when t0(=0x36) == a3(?), and falls through when t0(=0x36) != a3(?).
  The `bne` branch at 0x2688 targets 0x2668, is taken when a2(?) != 0, and falls through when a2(?) == 0.
  The `beq` branch at 0x2700 targets 0x2688 and is always taken.
  The `beq` branch at 0x2708 targets 0x2688 and is always taken.
  The return at 0x26f8 has v0 = one of ret(iobrick_attached_bricks), 0x0.

- `iobrick_attached_modids` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0x2710 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0x2710-0x2730 (32 bytes).
  It occupies 32 bytes.
  The `jal` at 0x271c calls iobrick_attached_modids_all with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=sp-16, a4=sp-14.
  The return at 0x2728 has v0 = ret(iobrick_attached_modids_all).

- `iobrick_get_sys_snum` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0x2730 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0x2730-0x2874 (324 bytes).
  It occupies 324 bytes.
  The `lh` at 0x2730 loads 2 bytes from a0 (arg0 at entry) +0x0.
  2 such `ld` accesses load 8 bytes from ([a0]:2 << 0x21) -0x6fffffffcc000000, including `ld` at 0x2744, `ld` at 0x276c.
  The `jal` at 0x277c calls get_chimera_type with a0=[a0]:2, a1=0x4000, a2=a2 at entry (arg2), a3=a3 at entry (arg3), a5=[a0]:2.
  The `jal` at 0x2794 calls sc_open with a0=a0 at entry (arg0), a1=0xffff000, a2=?, a3=?.
  The `jal` at 0x27a8 calls bzero with a0=sp-176, a1=0x80, a2=?, a3=?.
  The `jal` at 0x27c8 calls sc_construct_msg with a0=a0 at entry (arg0), a1=ret(sc_open), a2=sp-176, a3=0x80, a4=0x6, a5=0x8, a6=0x0.
  The `jal` at 0x27e8 calls sc_command with a0=a0 at entry (arg0), a1=ret(sc_open), a2=sp-176, a3=sp-176, a4=sp-48.
  The `jal` at 0x27fc calls sc_close with a0=a0 at entry (arg0), a1=ret(sc_open), a2=?, a3=?.
  The `jal` at 0x2824 calls sc_open with a0=a0 at entry (arg0), a1=0x4ffff000, a2=?, a3=?.
  The `jal` at 0x283c calls sc_close with a0=a0 at entry (arg0), a1=ret(sc_open), a2=?, a3=?.
  The `jal` at 0x2850 calls sc_interpret_resp with a0=sp-176, a1=0x2, a2=0x1, a3=a1 at entry (arg1).
  The `jal` at 0x2864 calls sc_close with a0=a0 at entry (arg0), a1=ret(sc_open), a2=?, a3=?.
  The `beq` branch at 0x2764 targets 0x278c, is taken when at(?) == v1(=0x8000), and falls through when at(?) != v1(=0x8000).
  The `beq` branch at 0x2774 targets 0x2790, is taken when a0(?) == a1(=0x4000), and falls through when a0(?) != a1(=0x4000).
  The `beq` branch at 0x2784 targets 0x2820, is taken when v0(=ret(get_chimera_type)) == 0, and falls through when v0(=ret(get_chimera_type)) != 0.
  The `bltz` branch at 0x279c targets 0x2834, is taken when v0(=ret(sc_open)) < 0 (signed), and falls through when v0(=ret(sc_open)) >= 0 (signed).
  The `bltz` branch at 0x27d0 targets 0x2860, is taken when v0(=ret(sc_construct_msg)) < 0 (signed), and falls through when v0(=ret(sc_construct_msg)) >= 0 (signed).
  The `beq` branch at 0x27f0 targets 0x283c, is taken when v0(=ret(sc_command)) == 0, and falls through when v0(=ret(sc_command)) != 0.
  The `bgez` branch at 0x282c targets 0x27a4, is taken when v0(=ret(sc_open)) >= 0 (signed), and falls through when v0(=ret(sc_open)) < 0 (signed).
  The `beq` branch at 0x2834 targets 0x2808 and is always taken.
  The `beq` branch at 0x2858 targets 0x2808 and is always taken.
  The `beq` branch at 0x286c targets 0x2808 and is always taken.
  The return at 0x2818 has v0 = one of -0x64, ret(sc_interpret_resp), -0x67.

- `iobrick_pci_pwr` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0x2874 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0x2874-0x297c (264 bytes).
  It occupies 264 bytes.
  The `sb` at 0x2948 stores 1 byte to a4 (arg4 at entry) +0x0.
  The `jal` at 0x28f0 calls sprintf with a0=sp-112, a1=sym(.rodata), a2=a1 at entry (arg1), a3=a2 at entry (arg2), a4=sym(.rodata), a6=-0x1.
  The `jal` at 0x290c calls sc_command_interp with a0=a0 at entry (arg0), a1=0x4, a2=0x3ff, a3=0x3f, a4=sp-112.
  The `jal` at 0x2944 calls strcpy with a0=a4 at entry (arg4), a1=sp-112, a2=?, a3=?.
  The `jal` at 0x296c calls sprintf with a0=sp-112, a1=sym(.rodata), a2=a1 at entry (arg1), a3=sym(.rodata), a4=sym(.rodata), a6=-0x1.
  The `beq` branch at 0x28ac targets 0x28d0, is taken when a3 == at(=0x2002), and falls through when a3 != at(=0x2002).
  The `beq` branch at 0x28b8 targets 0x2954, is taken when a3 == t2(=0x2003), and falls through when a3 != t2(=0x2003).
  The `beq` branch at 0x28c0 targets 0x2934, is taken when a3 == t8(=0x2004), and falls through when a3 != t8(=0x2004).
  The `beq` branch at 0x28c8 targets 0x2928 and is always taken.
  The `beq` branch at 0x28d8 targets 0x295c, is taken when t0(=a2) == a6(=-0x1), and falls through when t0(=a2) != a6(=-0x1).
  The `bne` branch at 0x2918 targets 0x293c, is taken when s0(=a4) != 0, and falls through when s0(=a4) == 0.
  The `beq` branch at 0x2934 targets 0x28d8 and is always taken.
  The `beq` branch at 0x294c targets 0x2920 and is always taken.
  The `beq` branch at 0x2954 targets 0x28d8 and is always taken.
  The `beq` branch at 0x2974 targets 0x28fc and is always taken.
  The return at 0x292c has v0 = one of -0x67, ?.

- `iobrick_pci_slot_pwr` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0x297c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0x297c-0x2998 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x2984 calls iobrick_pci_pwr with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x2990 has v0 = ret(iobrick_pci_pwr).

- `iobrick_pci_bus_pwr` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0x2998 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0x2998-0x29c8 (48 bytes).
  It occupies 48 bytes.
  The `jal` at 0x29b4 calls iobrick_pci_pwr with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=-0x1, a3=a2 at entry (arg2), a4=a3 at entry (arg3), a5=a4 at entry (arg4).
  The return at 0x29c0 has v0 = ret(iobrick_pci_pwr).

- `iobrick_pci_slot_rst` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0x29c8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0x29c8-0x29f0 (40 bytes).
  It occupies 40 bytes.
  The `jal` at 0x29dc calls iobrick_pci_pwr with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=0x2004, a4=a3 at entry (arg3), a5=a4 at entry (arg4).
  The return at 0x29e8 has v0 = ret(iobrick_pci_pwr).

- `iobrick_pci_bus_rst` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0x29f0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0x29f0-0x2a18 (40 bytes).
  It occupies 40 bytes.
  The `jal` at 0x2a04 calls iobrick_pci_pwr with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=-0x1, a3=0x2004, a4=a2 at entry (arg2), a5=a3 at entry (arg3).
  The return at 0x2a10 has v0 = ret(iobrick_pci_pwr).

- `iobrick_sc_version` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0x2a18 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0x2a18-0x2c24 (524 bytes).
  It occupies 524 bytes.
  3 such `lh` accesses load 2 bytes from a0 (arg0 at entry) +0x0, including `lh` at 0x2a18, `lh` at 0x2a70, `lh` at 0x2aec.
  3 such `ld` accesses load 8 bytes from ([a0]:2 << 0x21) -0x6fffffffcc000000, including `ld` at 0x2a2c, `ld` at 0x2a80, `ld` at 0x2afc.
  The `jal` at 0x2a54 calls get_chimera_type with a0=[a0]:2, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x2ab0 calls get_chimera_type with a0=[a0]:2, a1=?, a2=0x1, a3=?, a5=0xe, a6=0xf.
  The `jal` at 0x2b0c calls get_chimera_type with a0=[a0]:2, a1=0xfff0000, a2=?, a3=([a0]:2 << 0x21).
  The `jal` at 0x2b24 calls sc_open with a0=a0 at entry (arg0), a1=one of 0xffff000, 0x4ffff000, a2=?, a3=?.
  The `jal` at 0x2b3c calls bzero with a0=sp-176, a1=0x80, a2=-0x64, a3=?.
  The `jal` at 0x2b5c calls sc_construct_msg with a0=a0 at entry (arg0), a1=ret(sc_open), a2=sp-176, a3=0x80, a4=0x6, a5=0x5, a6=0x0.
  The `jal` at 0x2b7c calls sc_command_kern with a0=a0 at entry (arg0), a1=ret(sc_open), a2=sp-176, a3=sp-176, a4=sp-48.
  The `jal` at 0x2b8c calls sc_close with a0=a0 at entry (arg0), a1=ret(sc_open), a2=?, a3=?.
  The `jal` at 0x2bb0 calls sc_interpret_resp with a0=sp-176, a1=0x6, a2=0x0, a3=sp-44, a4=0x0, a5=sp-40, a6=0x0, a7=sp-36.
  The `jal` at 0x2bd8 calls sprintf with a0=a1 at entry (arg1), a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x2c00 calls sc_close with a0=a0 at entry (arg0), a1=ret(sc_open), a2=?, a3=?.
  The `jal` at 0x2c14 calls sc_close with a0=a0 at entry (arg0), a1=ret(sc_open), a2=?, a3=?.
  The `beq` branch at 0x2a4c targets 0x2b1c, is taken when at(?) == v1(=0x4000), and falls through when at(?) != v1(=0x4000).
  The `beq` branch at 0x2a60 targets 0x2b1c, is taken when v0(=ret(get_chimera_type)) == a0(=0x3), and falls through when v0(=ret(get_chimera_type)) != a0(=0x3).
  The `beq` branch at 0x2a68 targets 0x2aec, is taken when s1(=a2) == 0, and falls through when s1(=a2) != 0.
  The `bne` branch at 0x2a90 targets 0x2ab0, is taken when a0(=0x8000) != a1(?), and falls through when a0(=0x8000) == a1(?).
  The `beq` branch at 0x2a98 targets 0x2ab0, is taken when s1(=a2) == a2(=0x1), and falls through when s1(=a2) != a2(=0x1).
  The `beq` branch at 0x2aa0 targets 0x2b20, is taken when s1(=a2) == a5(=0xe), and falls through when s1(=a2) != a5(=0xe).
  The `beq` branch at 0x2aa8 targets 0x2b20, is taken when s1(=a2) == a6(=0xf), and falls through when s1(=a2) != a6(=0xf).
  The `beq` branch at 0x2ab8 targets 0x2ae0, is taken when v0(=ret(get_chimera_type)) == 0, and falls through when v0(=ret(get_chimera_type)) != 0.
  The `beq` branch at 0x2ac4 targets 0x2ae4, is taken when s1(=a2) == a3(=0x1), and falls through when s1(=a2) != a3(=0x1).
  The `beq` branch at 0x2acc targets 0x2b20, is taken when s1(=a2) == a2(=0xc), and falls through when s1(=a2) != a2(=0xc).
  The `beq` branch at 0x2ad8 targets 0x2b20, is taken when s1(=a2) == a4(=0xf), and falls through when s1(=a2) != a4(=0xf).
  The `beq` branch at 0x2ae4 targets 0x2b24 and is always taken.
  The `beq` branch at 0x2b04 targets 0x2b20, is taken when a0(=0x8000) == a2(?), and falls through when a0(=0x8000) != a2(?).
  The `beq` branch at 0x2b14 targets 0x2a70, is taken when v0(=ret(get_chimera_type)) == 0, and falls through when v0(=ret(get_chimera_type)) != 0.
  The `bltz` branch at 0x2b30 targets 0x2be4, is taken when v0(=ret(sc_open)) < 0 (signed), and falls through when v0(=ret(sc_open)) >= 0 (signed).
  The `bltz` branch at 0x2b64 targets 0x2bfc, is taken when v0(=ret(sc_construct_msg)) < 0 (signed), and falls through when v0(=ret(sc_construct_msg)) >= 0 (signed).
  The `bltz` branch at 0x2b84 targets 0x2c10, is taken when v0(=ret(sc_command_kern)) < 0 (signed), and falls through when v0(=ret(sc_command_kern)) >= 0 (signed).
  The `bgez` branch at 0x2bb8 targets 0x2bc8, is taken when v0(=ret(sc_interpret_resp)) >= 0 (signed), and falls through when v0(=ret(sc_interpret_resp)) < 0 (signed).
  The `beq` branch at 0x2bc0 targets 0x2be4 and is always taken.
  The `beq` branch at 0x2c08 targets 0x2be4 and is always taken.
  The `beq` branch at 0x2c1c targets 0x2be4 and is always taken.
  The return at 0x2bf4 has v0 = one of -0x70, -0x67, -0x64, 0x0.

- `iobrick_L1bricktype_to_name` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0x2c24 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0x2c24-0x2cbc (152 bytes).
  It occupies 152 bytes.
  The `ld` at 0x2c5c loads 8 bytes from (sym(.rodata) + (ret(iobrick_convert_l1type_generic)-35 << 0x3)) +0x0.
  The `jal` at 0x2c2c calls iobrick_convert_l1type_generic with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  Calls (unknown callee) via register with a0=?, a1=?, a2=sym(.rodata), a3=(sym(.rodata) + (ret(iobrick_convert_l1type_generic)-35 << 0x3)), a4=sym(.rodata), a5=(ret(iobrick_convert_l1type_generic)-35 << 0x3), a6=[(sym(.rodata) + (ret(iobrick_convert_l1type_generic)-35 << 0x3))]:8 (`jr` at 0x2c60).
  The `beq` branch at 0x2c50 targets 0x2c68, is taken when a5(=ret(iobrick_convert_l1type_generic)-35) >= 0x36 (unsigned), and falls through when a5(=ret(iobrick_convert_l1type_generic)-35) < 0x36 (unsigned).
  The return at 0x2c6c has v0 = sym(.rodata).
  The instructions from 0x2c74 to 0x2cb8 are not reached by any path from the entry, and their branches are not listed.
  The indirect jump at 0x2c60 uses a jump table whose successors are unresolved.

- `peer_iobrick_rack_bay_get` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0x2cbc (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0x2cbc-0x2cec (48 bytes).
  It occupies 48 bytes.
  The `lhu` at 0x2cc8 loads 2 bytes from (a0 << 0x21) -0x6fffffffcb000000.
  The `sw` at 0x2cd4 stores 4 bytes to a2 (arg2 at entry) +0x0.
  The `sw` at 0x2ce8 stores 4 bytes to a1 (arg1 at entry) +0x0.
  The return at 0x2ce4 has v0 = 0x0.

- `peer_iobrick_type_get` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0x2cec (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0x2cec-0x2e44 (344 bytes).
  It occupies 344 bytes.
  The `jal` at 0x2d14 calls bzero with a0=sp-192, a1=0x80, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x2d2c calls sc_open with a0=a0 at entry (arg0), a1=((a1 << 0x12) | (a2 << 0xc)), a2=(a2 << 0xc), a3=?.
  The `jal` at 0x2d58 calls sc_construct_msg with a0=a0 at entry (arg0), a1=ret(sc_open), a2=sp-192, a3=0x80, a4=0x6, a5=0x3, a6=0x0.
  The `jal` at 0x2d78 calls sc_command_kern with a0=a0 at entry (arg0), a1=ret(sc_open), a2=sp-192, a3=sp-192, a4=sp-64.
  The `jal` at 0x2d8c calls sc_close with a0=a0 at entry (arg0), a1=ret(sc_open), a2=?, a3=?.
  The `jal` at 0x2db8 calls sc_close with a0=a0 at entry (arg0), a1=ret(sc_open), a2=?, a3=?.
  The `jal` at 0x2dd4 calls sc_interpret_resp with a0=sp-192, a1=0x4, a2=0x0, a3=sp-60, a4=0x0, a5=a3 at entry (arg3).
  The `jal` at 0x2e18 calls printf with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jal` at 0x2e2c calls sc_close with a0=a0 at entry (arg0), a1=ret(sc_open), a2=?, a3=?.
  The `bltz` branch at 0x2d38 targets 0x2d98, is taken when v0(=ret(sc_open)) < 0 (signed), and falls through when v0(=ret(sc_open)) >= 0 (signed).
  The `bltz` branch at 0x2d60 targets 0x2e28, is taken when v0(=ret(sc_construct_msg)) < 0 (signed), and falls through when v0(=ret(sc_construct_msg)) >= 0 (signed).
  The `beq` branch at 0x2d80 targets 0x2db8, is taken when v0(=ret(sc_command_kern)) == 0, and falls through when v0(=ret(sc_command_kern)) != 0.
  The `bltz` branch at 0x2ddc targets 0x2e3c, is taken when v0(=ret(sc_interpret_resp)) < 0 (signed), and falls through when v0(=ret(sc_interpret_resp)) >= 0 (signed).
  The `bne` branch at 0x2df0 targets 0x2e10, is taken when s2(=a1) != v1(?), and falls through when s2(=a1) == v1(?).
  The `beq` branch at 0x2e00 targets 0x2e20, is taken when s3(=a2) == a0(?), and falls through when s3(=a2) != a0(?).
  The `beq` branch at 0x2e08 targets 0x2e14 and is always taken.
  The `beq` branch at 0x2e20 targets 0x2d98 and is always taken.
  The `beq` branch at 0x2e34 targets 0x2d98 and is always taken.
  The `beq` branch at 0x2e3c targets 0x2d98 and is always taken.
  The return at 0x2db0 has v0 = one of -0x70, -0x67, -0x64, 0x0.

- `peer_iobrick_module_get` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0x2e44 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0x2e44-0x2e88 (68 bytes).
  It occupies 68 bytes.
  The `jal` at 0x2e54 calls peer_iobrick_type_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=sp-32.
  The `jal` at 0x2e6c calls sc_rbt_to_moduleid with a0=a1 at entry (arg1), a1=a2 at entry (arg2), a2=?, a3=?.
  The `bltz` branch at 0x2e5c targets 0x2e78, is taken when v0(=ret(peer_iobrick_type_get)) < 0 (signed), and falls through when v0(=ret(peer_iobrick_type_get)) >= 0 (signed).
  The return at 0x2e80 has v0 = one of ret(peer_iobrick_type_get), ret(sc_rbt_to_moduleid).

- `peer_iobrick_portspeed_get` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0x2e88 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0x2e88-0x2fa4 (284 bytes).
  It occupies 284 bytes.
  The `jal` at 0x2eac calls bzero with a0=sp-176, a1=0x80, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x2ec0 calls sc_open with a0=a0 at entry (arg0), a1=((a1 << 0x12) | (a2 << 0xc)), a2=(a2 << 0xc), a3=?.
  The `jal` at 0x2eec calls sc_construct_msg with a0=a0 at entry (arg0), a1=ret(sc_open), a2=sp-176, a3=0x80, a4=0x6, a5=0xa, a6=0x0.
  The `jal` at 0x2f0c calls sc_command_kern with a0=a0 at entry (arg0), a1=ret(sc_open), a2=sp-176, a3=sp-176, a4=sp-48.
  The `jal` at 0x2f20 calls sc_close with a0=a0 at entry (arg0), a1=ret(sc_open), a2=?, a3=?.
  The `jal` at 0x2f3c calls sc_interpret_resp with a0=sp-176, a1=0x4, a2=0x0, a3=sp-44, a4=0x0, a5=sp-40.
  The `jal` at 0x2f84 calls sc_close with a0=a0 at entry (arg0), a1=ret(sc_open), a2=?, a3=?.
  The `jal` at 0x2f94 calls sc_close with a0=a0 at entry (arg0), a1=ret(sc_open), a2=?, a3=?.
  The `bltz` branch at 0x2ecc targets 0x2f58, is taken when v0(=ret(sc_open)) < 0 (signed), and falls through when v0(=ret(sc_open)) >= 0 (signed).
  The `bltz` branch at 0x2ef4 targets 0x2f80, is taken when v0(=ret(sc_construct_msg)) < 0 (signed), and falls through when v0(=ret(sc_construct_msg)) >= 0 (signed).
  The `bltz` branch at 0x2f14 targets 0x2f94, is taken when v0(=ret(sc_command_kern)) < 0 (signed), and falls through when v0(=ret(sc_command_kern)) >= 0 (signed).
  The `bltz` branch at 0x2f44 targets 0x2f74, is taken when v0(=ret(sc_interpret_resp)) < 0 (signed), and falls through when v0(=ret(sc_interpret_resp)) >= 0 (signed).
  The `beq` branch at 0x2f78 targets 0x2f5c and is always taken.
  The `beq` branch at 0x2f8c targets 0x2f58 and is always taken.
  The `beq` branch at 0x2f9c targets 0x2f58 and is always taken.
  The return at 0x2f6c has v0 = one of -0x67, -0x64, 0x190, 0x258, -0x70.

- `peer_iobrick_pci_pwr` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0x2fa4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0x2fa4-0x30b4 (272 bytes).
  It occupies 272 bytes.
  The `sb` at 0x3080 stores 1 byte to a6 (arg6 at entry) +0x0.
  The `jal` at 0x3028 calls sprintf with a0=sp-128, a1=sym(.rodata), a2=a3 at entry (arg3), a3=a4 at entry (arg4), a4=sym(.rodata), a5=-0x1.
  The `jal` at 0x3044 calls sc_command_interp with a0=a0 at entry (arg0), a1=0x0, a2=a1 at entry (arg1), a3=a2 at entry (arg2), a4=sp-128, a5=0x0.
  The `jal` at 0x307c calls strcpy with a0=a6 at entry (arg6), a1=sp-128, a2=?, a3=?.
  The `jal` at 0x30a4 calls sprintf with a0=sp-128, a1=sym(.rodata), a2=a3 at entry (arg3), a3=sym(.rodata), a4=sym(.rodata), a5=-0x1.
  The `beq` branch at 0x2fdc targets 0x3000, is taken when a5 == at(=0x2002), and falls through when a5 != at(=0x2002).
  The `beq` branch at 0x2fe8 targets 0x308c, is taken when a5 == t3(=0x2003), and falls through when a5 != t3(=0x2003).
  The `beq` branch at 0x2ff0 targets 0x306c, is taken when a5 == t9(=0x2004), and falls through when a5 != t9(=0x2004).
  The `beq` branch at 0x2ff8 targets 0x3060 and is always taken.
  The `beq` branch at 0x3010 targets 0x3094, is taken when t1(=a4) == a5(=-0x1), and falls through when t1(=a4) != a5(=-0x1).
  The `bne` branch at 0x3050 targets 0x3074, is taken when s0(=a6) != 0, and falls through when s0(=a6) == 0.
  The `beq` branch at 0x306c targets 0x3008 and is always taken.
  The `beq` branch at 0x3084 targets 0x3058 and is always taken.
  The `beq` branch at 0x308c targets 0x3008 and is always taken.
  The `beq` branch at 0x30ac targets 0x3034 and is always taken.
  The return at 0x3064 has v0 = one of -0x67, ?.

- `peer_iobrick_pci_slot_pwr` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0x30b4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0x30b4-0x30d0 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x30bc calls peer_iobrick_pci_pwr with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x30c8 has v0 = ret(peer_iobrick_pci_pwr).

- `peer_iobrick_pci_bus_pwr` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0x30d0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0x30d0-0x30f8 (40 bytes).
  It occupies 40 bytes.
  The `jal` at 0x30e4 calls peer_iobrick_pci_pwr with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a4=-0x1, a5=a4 at entry (arg4), a6=a5 at entry (arg5).
  The return at 0x30f0 has v0 = ret(peer_iobrick_pci_pwr).

- `peer_iobrick_pci_slot_rst` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0x30f8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0x30f8-0x3118 (32 bytes).
  It occupies 32 bytes.
  The `jal` at 0x3104 calls peer_iobrick_pci_pwr with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a5=0x2004, a6=a5 at entry (arg5).
  The return at 0x3110 has v0 = ret(peer_iobrick_pci_pwr).

- `peer_iobrick_pci_bus_rst` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0x3118 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0x3118-0x313c (36 bytes).
  It occupies 36 bytes.
  The `jal` at 0x3128 calls peer_iobrick_pci_pwr with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a4=-0x1, a5=0x2004, a6=a4 at entry (arg4).
  The return at 0x3134 has v0 = ret(peer_iobrick_pci_pwr).

- `peer_iobrick_partition_set` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0x313c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0x313c-0x3250 (276 bytes).
  It occupies 276 bytes.
  The `jal` at 0x3164 calls bzero with a0=sp-176, a1=0x80, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x3178 calls sc_open with a0=a0 at entry (arg0), a1=((a1 << 0x12) | (a2 << 0xc)), a2=(a2 << 0xc), a3=?.
  The `jal` at 0x31b4 calls sc_construct_msg with a0=a0 at entry (arg0), a1=ret(sc_open), a2=sp-176, a3=0x80, a4=0x6, a5=0x1006, a6=0x2, a7=0x0.
  The `jal` at 0x31d4 calls sc_command_kern with a0=a0 at entry (arg0), a1=ret(sc_open), a2=sp-176, a3=sp-176, a4=sp-48.
  The `jal` at 0x31e4 calls sc_close with a0=a0 at entry (arg0), a1=ret(sc_open), a2=?, a3=?.
  The `jal` at 0x320c calls sc_close with a0=a0 at entry (arg0), a1=ret(sc_open), a2=?, a3=?.
  The `jal` at 0x3218 calls sc_interpret_resp with a0=sp-176, a1=0x0, a2=?, a3=?.
  The `jal` at 0x3234 calls sc_close with a0=a0 at entry (arg0), a1=ret(sc_open), a2=?, a3=?.
  The `bltz` branch at 0x3188 targets 0x31f0, is taken when v0(=ret(sc_open)) < 0 (signed), and falls through when v0(=ret(sc_open)) >= 0 (signed).
  The `bltz` branch at 0x31bc targets 0x3230, is taken when v0(=ret(sc_construct_msg)) < 0 (signed), and falls through when v0(=ret(sc_construct_msg)) >= 0 (signed).
  The `beq` branch at 0x31dc targets 0x3208, is taken when v0(=ret(sc_command_kern)) == 0, and falls through when v0(=ret(sc_command_kern)) != 0.
  The `bltz` branch at 0x3220 targets 0x3244, is taken when v0(=ret(sc_interpret_resp)) < 0 (signed), and falls through when v0(=ret(sc_interpret_resp)) >= 0 (signed).
  The `beq` branch at 0x3228 targets 0x31f4 and is always taken.
  The `beq` branch at 0x323c targets 0x31f0 and is always taken.
  The `beq` branch at 0x3248 targets 0x31f4 and is always taken.
  The return at 0x3200 has v0 = one of -0x70, -0x67, -0x64, 0x0.

- `peer_iobrick_partition_get` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0x3250 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0x3250-0x335c (268 bytes).
  It occupies 268 bytes.
  The `jal` at 0x3274 calls bzero with a0=sp-176, a1=0x80, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x3288 calls sc_open with a0=a0 at entry (arg0), a1=((a1 << 0x12) | (a2 << 0xc)), a2=(a2 << 0xc), a3=?.
  The `jal` at 0x32b8 calls sc_construct_msg with a0=a0 at entry (arg0), a1=ret(sc_open), a2=sp-176, a3=0x80, a4=0x6, a5=0x9, a6=0x0.
  The `jal` at 0x32d8 calls sc_command_kern with a0=a0 at entry (arg0), a1=ret(sc_open), a2=sp-176, a3=sp-176, a4=sp-48.
  The `jal` at 0x32e8 calls sc_close with a0=a0 at entry (arg0), a1=ret(sc_open), a2=?, a3=?.
  The `jal` at 0x3310 calls sc_close with a0=a0 at entry (arg0), a1=ret(sc_open), a2=?, a3=?.
  The `jal` at 0x3324 calls sc_interpret_resp with a0=sp-176, a1=0x2, a2=0x0, a3=sp-44.
  The `jal` at 0x3340 calls sc_close with a0=a0 at entry (arg0), a1=ret(sc_open), a2=?, a3=?.
  The `bltz` branch at 0x3298 targets 0x32f4, is taken when v0(=ret(sc_open)) < 0 (signed), and falls through when v0(=ret(sc_open)) >= 0 (signed).
  The `bltz` branch at 0x32c0 targets 0x333c, is taken when v0(=ret(sc_construct_msg)) < 0 (signed), and falls through when v0(=ret(sc_construct_msg)) >= 0 (signed).
  The `beq` branch at 0x32e0 targets 0x330c, is taken when v0(=ret(sc_command_kern)) == 0, and falls through when v0(=ret(sc_command_kern)) != 0.
  The `bltz` branch at 0x332c targets 0x3350, is taken when v0(=ret(sc_interpret_resp)) < 0 (signed), and falls through when v0(=ret(sc_interpret_resp)) >= 0 (signed).
  The `beq` branch at 0x3334 targets 0x32f8 and is always taken.
  The `beq` branch at 0x3348 targets 0x32f4 and is always taken.
  The `beq` branch at 0x3354 targets 0x32f8 and is always taken.
  The return at 0x3304 has v0 = one of -0x67, -0x64, ?, -0x70.

- `_elscuart_puts` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0x335c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0x335c-0x33cc (112 bytes).
  It occupies 112 bytes.
  2 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x337c, `lbu` at 0x3398.
  The `jal` at 0x3388 calls _elscuart_putc with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `beq` branch at 0x3374 targets 0x33bc, is taken when a1 == 0, and falls through when a1 != 0.
  The `beq` branch at 0x3380 targets 0x33a8, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `bltz` branch at 0x3390 targets 0x33c4, is taken when v0(=ret(_elscuart_putc)) < 0 (signed), and falls through when v0(=ret(_elscuart_putc)) >= 0 (signed).
  The `bne` branch at 0x339c targets 0x3388, is taken when a1(?) != 0, and falls through when a1(?) == 0.
  The `beq` branch at 0x33bc targets 0x337c and is always taken.
  The `beq` branch at 0x33c4 targets 0x33a8 and is always taken.
  The return at 0x33b4 has v0 = one of -0x1, 0x0.

- `elscuart_probe` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0x33cc (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0x33cc-0x33f0 (36 bytes).
  It occupies 36 bytes.
  The `jal` at 0x33d4 calls get_elsc with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x33dc calls _elscuart_probe with a0=ret(get_elsc), a1=?, a2=?, a3=?.
  The return at 0x33e8 has v0 = ret(_elscuart_probe).

- `elscuart_init` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0x33f0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0x33f0-0x3414 (36 bytes).
  It occupies 36 bytes.
  The `jal` at 0x33f8 calls get_elsc with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x3400 calls _elscuart_init with a0=ret(get_elsc), a1=?, a2=?, a3=?.
  The return at 0x340c has v0 = ret(_elscuart_init).

- `elscuart_poll` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0x3414 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0x3414-0x3438 (36 bytes).
  It occupies 36 bytes.
  The `jal` at 0x341c calls get_elsc with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x3424 calls _elscuart_poll with a0=ret(get_elsc), a1=?, a2=?, a3=?.
  The return at 0x3430 has v0 = ret(_elscuart_poll).

- `elscuart_readc` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0x3438 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0x3438-0x345c (36 bytes).
  It occupies 36 bytes.
  The `jal` at 0x3440 calls get_elsc with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x3448 calls _elscuart_readc with a0=ret(get_elsc), a1=?, a2=?, a3=?.
  The return at 0x3454 has v0 = ret(_elscuart_readc).

- `elscuart_getc` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0x345c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0x345c-0x3480 (36 bytes).
  It occupies 36 bytes.
  The `jal` at 0x3464 calls get_elsc with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x346c calls _elscuart_getc with a0=ret(get_elsc), a1=?, a2=?, a3=?.
  The return at 0x3478 has v0 = ret(_elscuart_getc).

- `elscuart_puts` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0x3480 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0x3480-0x34b0 (48 bytes).
  It occupies 48 bytes.
  The `jal` at 0x348c calls get_elsc with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x3498 calls _elscuart_puts with a0=ret(get_elsc), a1=a0 at entry (arg0), a2=?, a3=?.
  The return at 0x34a8 has v0 = ret(_elscuart_puts).

- `elscuart_putc` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0x34b0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0x34b0-0x34e0 (48 bytes).
  It occupies 48 bytes.
  The `jal` at 0x34bc calls get_elsc with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x34c8 calls _elscuart_putc with a0=ret(get_elsc), a1=a0 at entry (arg0), a2=?, a3=?.
  The return at 0x34d8 has v0 = ret(_elscuart_putc).

- `elscuart_flush` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0x34e0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0x34e0-0x3504 (36 bytes).
  It occupies 36 bytes.
  The `jal` at 0x34e8 calls get_elsc with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x34f0 calls _elscuart_flush with a0=ret(get_elsc), a1=?, a2=?, a3=?.
  The return at 0x34fc has v0 = ret(_elscuart_flush).

- `elsc_ody_expander_set` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0x3504 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0x3504-0x364c (328 bytes).
  It occupies 328 bytes.
  The `jal` at 0x3520 calls bzero with a0=sp-176, a1=0x80, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x3534 calls sc_open with a0=a0 at entry (arg0), a1=0xffff000, a2=?, a3=?.
  The `jal` at 0x3574 calls sc_construct_msg with a0=a0 at entry (arg0), a1=ret(sc_open), a2=sp-176, a3=0x80, a4=0x6, a5=0x2008, a6=0x4, a7=0x0.
  The `jal` at 0x3594 calls sc_command with a0=a0 at entry (arg0), a1=ret(sc_open), a2=sp-176, a3=sp-176, a4=sp-48.
  The `jal` at 0x35a8 calls sc_close with a0=a0 at entry (arg0), a1=ret(sc_open), a2=?, a3=?.
  The `jal` at 0x35b4 calls sc_interpret_resp with a0=sp-176, a1=0x0, a2=?, a3=?.
  The `jal` at 0x35e4 calls cmn_err with a0=0x1, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x35fc calls cmn_err with a0=0x1, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x3608 calls sc_close with a0=a0 at entry (arg0), a1=ret(sc_open), a2=?, a3=?.
  The `jal` at 0x361c calls cmn_err with a0=0x1, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x3628 calls sc_close with a0=a0 at entry (arg0), a1=ret(sc_open), a2=?, a3=?.
  The `jal` at 0x363c calls cmn_err with a0=0x1, a1=sym(.rodata), a2=?, a3=?.
  The `bltz` branch at 0x353c targets 0x35dc, is taken when v0(=ret(sc_open)) < 0 (signed), and falls through when v0(=ret(sc_open)) >= 0 (signed).
  The `bltz` branch at 0x357c targets 0x35f4, is taken when v0(=ret(sc_construct_msg)) < 0 (signed), and falls through when v0(=ret(sc_construct_msg)) >= 0 (signed).
  The `bltz` branch at 0x359c targets 0x3618, is taken when v0(=ret(sc_command)) < 0 (signed), and falls through when v0(=ret(sc_command)) >= 0 (signed).
  The `bltz` branch at 0x35bc targets 0x3638, is taken when v0(=ret(sc_interpret_resp)) < 0 (signed), and falls through when v0(=ret(sc_interpret_resp)) >= 0 (signed).
  The `beq` branch at 0x35ec targets 0x35c8 and is always taken.
  The `beq` branch at 0x3610 targets 0x35c8 and is always taken.
  The `beq` branch at 0x3630 targets 0x35c8 and is always taken.
  The `beq` branch at 0x3644 targets 0x35c8 and is always taken.
  The return at 0x35d4 has v0 = one of -0x70, -0x67, -0x64, 0x0.

- `elsc_ody_expander_get` in `IP35/usr/cpu/sysgen/IP35boot/l1_command.o` at 0x364c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/l1_command.o`.
  Range: 0x364c-0x3780 (308 bytes).
  It occupies 308 bytes.
  The `jal` at 0x3664 calls bzero with a0=sp-176, a1=0x80, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x3678 calls sc_open with a0=a0 at entry (arg0), a1=0xffff000, a2=?, a3=?.
  The `jal` at 0x36a0 calls sc_construct_msg with a0=a0 at entry (arg0), a1=ret(sc_open), a2=sp-176, a3=0x80, a4=0x6, a5=0x2007, a6=0x0.
  The `jal` at 0x36c0 calls sc_command with a0=a0 at entry (arg0), a1=ret(sc_open), a2=sp-176, a3=sp-176, a4=sp-48.
  The `jal` at 0x36d0 calls sc_close with a0=a0 at entry (arg0), a1=ret(sc_open), a2=?, a3=?.
  The `jal` at 0x36e4 calls sc_interpret_resp with a0=sp-176, a1=0x2, a2=0x0, a3=a1 at entry (arg1).
  The `jal` at 0x3710 calls cmn_err with a0=0x1, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x3728 calls cmn_err with a0=0x1, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x3734 calls sc_close with a0=a0 at entry (arg0), a1=ret(sc_open), a2=?, a3=?.
  The `jal` at 0x374c calls cmn_err with a0=0x1, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x3758 calls sc_close with a0=a0 at entry (arg0), a1=ret(sc_open), a2=?, a3=?.
  The `jal` at 0x3770 calls cmn_err with a0=0x1, a1=sym(.rodata), a2=?, a3=?.
  The `bltz` branch at 0x3680 targets 0x3708, is taken when v0(=ret(sc_open)) < 0 (signed), and falls through when v0(=ret(sc_open)) >= 0 (signed).
  The `bltz` branch at 0x36a8 targets 0x3720, is taken when v0(=ret(sc_construct_msg)) < 0 (signed), and falls through when v0(=ret(sc_construct_msg)) >= 0 (signed).
  The `bne` branch at 0x36c8 targets 0x3744, is taken when v0(=ret(sc_command)) != 0, and falls through when v0(=ret(sc_command)) == 0.
  The `bltz` branch at 0x36ec targets 0x3768, is taken when v0(=ret(sc_interpret_resp)) < 0 (signed), and falls through when v0(=ret(sc_interpret_resp)) >= 0 (signed).
  The `beq` branch at 0x3718 targets 0x36f4 and is always taken.
  The `beq` branch at 0x373c targets 0x36f4 and is always taken.
  The `beq` branch at 0x3760 targets 0x36f4 and is always taken.
  The `beq` branch at 0x3778 targets 0x36f4 and is always taken.
  The return at 0x3700 has v0 = one of -0x70, -0x67, -0x64, 0x0.
