# Readings: `IP35/usr/cpu/sysgen/IP35boot/os.a(vmdump.o)`

One entry per routine, filed here from the reading batches by binary.

- `real_dumpsys` in `IP35/usr/cpu/sysgen/IP35boot/os.a(vmdump.o)` at 0x268 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/os.a(vmdump.o)`.
  Range: 0x268-0x688 (1056 bytes).
  It occupies 1056 bytes.
  The `lh` at 0x2c0 loads 2 bytes from table(sym(MAJOR)) +0x0.
  The `ld` at 0x2f8 loads 8 bytes from table(sym(bdevsw)) +0x0.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0x308, `ld` at 0x314.
  4 such `ld` accesses load 8 bytes from abs 0xffffffffffffc400, including `ld` at 0x388, `ld` at 0x484, `ld` at 0x4f0.
  4 such `lh` accesses load 2 bytes from abs 0xffffffffffffc42a, including `lh` at 0x38c, `lh` at 0x488, `lh` at 0x4f4.
  4 such `ld` accesses load 8 bytes from [-0x3c00]:8 +0x0, including `ld` at 0x394, `ld` at 0x48c, `ld` at 0x4f8.
  4 such `ld` accesses load 8 bytes from ([[-0x3c00]:8]:8 + ([-0x3bd6]:2 << 0x3)) +0x0, including `ld` at 0x3b4, `ld` at 0x498, `ld` at 0x504.
  2 such `ld` accesses load 8 bytes from [([[-0x3c00]:8]:8 + ([-0x3bd6]:2 << 0x3))]:8 +0x8588, including `ld` at 0x3d8, `ld` at 0x574.
  2 such `lhu` accesses load 2 bytes from [([[-0x3c00]:8]:8 + ([-0x3bd6]:2 << 0x3))]:8 +0x8598, including `lhu` at 0x4a0, `lhu` at 0x4c8.
  2 such `lh` accesses load 2 bytes from [([[-0x3c00]:8]:8 + ([-0x3bd6]:2 << 0x3))]:8 +0x8596, including `lh` at 0x4dc, `lh` at 0x510.
  The `lh` at 0x514 loads 2 bytes from abs 0xffffffffffffc428.
  2 such `ld` accesses load 8 bytes from abs 0x9200000001030100, including `ld` at 0x55c, `ld` at 0x5a0.
  2 such `lw` accesses load 4 bytes from sym(.data) +0x450, including `lw` at 0x564, `lw` at 0x5e0.
  The `sd` at 0x58c stores 8 bytes to sym(.data) +0x468.
  The `sd` at 0x598 stores 8 bytes to sym(.data) +0x460.
  The `ld` at 0x5a4 loads 8 bytes from abs 0x9200000001604200.
  The `lw` at 0x5f8 loads 4 bytes from sym(.data) +0x458.
  The `sw` at 0x608 stores 4 bytes to sym(.data) +0x458.
  The `jal` at 0x270 calls spl7 with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x320 calls enter_dump_mode with a0=?, a1=?, a2=?, a3=?, a4=0x1.
  The `jal` at 0x328 calls get_elsc with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x334 calls sc_set_system_state with a0=ret(get_elsc), a1=0x50, a2=?, a3=?.
  The `jal` at 0x34c calls printf with a0=sym(.rodata), a1=[sym(dumpdevname)]:8, a2=[sym(dumplo)], a3=[sym(dumpsize)].
  The `jal` at 0x36c calls bdrv with a0=[sym(.sbss)+48]:8, a1=0x8, a2=[sym(dumpdev)], a3=0x1, a4=0x0, a5=0x0, a6=0x0.
  The `jal` at 0x380 calls pmem_getfirstclick with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x3ec calls compression_init with a0=sym(ccookie_ptr), a1=sym(dumpstack+15560), a2=0x8000, a3=0x0, a6=([-0x3bd6]:2 << 0x3).
  The `jal` at 0x404 calls dumpvmcore with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x40c calls get_elsc with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x418 calls sc_set_system_state with a0=ret(get_elsc), a1=0x5a, a2=?, a3=?.
  The `jal` at 0x420 calls exit_dump_mode with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x430 calls mdboot with a0=0x0, a1=0x0, a2=?, a3=?.
  The `jal` at 0x468 calls printf with a0=sym(.rodata), a1=[sym(dumpdev)], a2=[sym(dumplo)], a3=[sym(dumpsize)].
  The `jal` at 0x4b8 calls mdboot with a0=0x0, a1=0x0, a2=?, a3=?.
  The `jal` at 0x4e8 calls cpu_enabled with a0=?, a1=[([[-0x3c00]:8]:8 + ([-0x3bd6]:2 << 0x3))]:8+65536, a2=?, a3=?.
  The `jal` at 0x528 calls printf with a0=sym(.rodata), a1=[([[-0x3c00]:8]:8 + ([-0x3bd6]:2 << 0x3))]:8+65536, a2=?, a3=?.
  The `jal` at 0x5fc calls printf with a0=sym(.rodata), a1=[sym(.data)+1112], a2=0x9200000001604200, a3=one of 0x1, 0x3b9aca00, a7=0x1.
  The `jal` at 0x60c calls hwgraph_bdevsw_get with a0=[sym(dumpdev)], a1=?, a2=?, a3=?.
  The `jal` at 0x620 calls printf with a0=sym(.rodata), a1=0x9200000001030100, a2=0x9200000001604200, a3=0x3b9aca00, a6=[0x9200000001030100]:8, a7=0x1.
  The `jal` at 0x634 calls panic with a0=sym(.rodata), a1=[sym(dumpdev)], a2=?, a3=?.
  The `jal` at 0x648 calls panic with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jal` at 0x658 calls dumperror with a0=ret(bdrv), a1=?, a2=?, a3=?.
  The `jal` at 0x660 calls panic with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jal` at 0x670 calls dumperror with a0=?, a1=?, a2=?, a3=?, a6=[sym(disable_asyncdump)].
  The `jal` at 0x678 calls panic with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `beq` branch at 0x280 targets 0x4b4, is taken when at(=[sym(dumpdev)]) == v0(=-0x1), and falls through when at(=[sym(dumpdev)]) != v0(=-0x1).
  The `bltz` branch at 0x288 targets 0x4b4, is taken when v1(=[sym(dump_level)]) < 0 (signed), and falls through when v1(=[sym(dump_level)]) >= 0 (signed).
  The `beq` branch at 0x290 targets 0x644, is taken when a0(=[sym(dumpsize)]) == 0, and falls through when a0(=[sym(dumpsize)]) != 0.
  The `beq` branch at 0x2a4 targets 0x60c, is taken when (a1(?) & 0x1ff) == 0, and falls through when (a1(?) & 0x1ff) != 0.
  The `bne` branch at 0x2cc targets 0x440, is taken when v0(=entry(sym(MAJOR))) < a2(=[sym(bdevcnt)]) (signed), and falls through when v0(=entry(sym(MAJOR))) >= a2(=[sym(bdevcnt)]) (signed).
  The `beq` branch at 0x2d8 targets 0x304, is taken when v0(=entry(sym(MAJOR))) >= a0(=[sym(bdevmax)]) (signed), and falls through when v0(=entry(sym(MAJOR))) < a0(=[sym(bdevmax)]) (signed).
  The `bne` branch at 0x2fc targets 0x308, is taken when a1(=entry(sym(bdevsw))) != 0, and falls through when a1(=entry(sym(bdevsw))) == 0.
  The `bne` branch at 0x30c targets 0x630, is taken when a2(?) != 0, and falls through when a2(?) == 0.
  The `beq` branch at 0x318 targets 0x630, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0x344 targets 0x464, is taken when a1(=[sym(dumpdevname)]:8) == 0, and falls through when a1(=[sym(dumpdevname)]:8) != 0.
  The `bne` branch at 0x374 targets 0x658, is taken when v0(=ret(bdrv)) != 0, and falls through when v0(=ret(bdrv)) == 0.
  The `bltz` branch at 0x3f4 targets 0x670, is taken when v0(=ret(compression_init)) < 0 (signed), and falls through when v0(=ret(compression_init)) >= 0 (signed).
  The `beq` branch at 0x3fc targets 0x478, is taken when a6(=[sym(disable_asyncdump)]) == 0, and falls through when a6(=[sym(disable_asyncdump)]) != 0.
  The `beq` branch at 0x438 targets 0x438 and is always taken.
  The `beq` branch at 0x45c targets 0x308 and is always taken.
  The `beq` branch at 0x470 targets 0x358 and is always taken.
  The `bne` branch at 0x47c targets 0x404, is taken when a2(=[sym(numcpus)]) < 0x2 (signed), and falls through when a2(=[sym(numcpus)]) >= 0x2 (signed).
  The `blez` branch at 0x4a4 targets 0x528, is taken when a3(=[[([[-0x3c00]:8]:8 + ([-0x3bd6]:2 << 0x3))]:8+34200]:2) <= 0 (signed), and falls through when a3(=[[([[-0x3c00]:8]:8 + ([-0x3bd6]:2 << 0x3))]:8+34200]:2) > 0 (signed).
  The `beq` branch at 0x4ac targets 0x4dc and is always taken.
  The `beq` branch at 0x4c0 targets 0x290 and is always taken.
  The `beq` branch at 0x4d4 targets 0x528, is taken when s1(?) >= a2(=[[([[-0x3c00]:8]:8 + ([-0x3bd6]:2 << 0x3))]:8+34200]:2) (signed), and falls through when s1(?) < a2(=[[([[-0x3c00]:8]:8 + ([-0x3bd6]:2 << 0x3))]:8+34200]:2) (signed).
  The `beq` branch at 0x508 targets 0x4c8, is taken when v0(=ret(cpu_enabled)) == 0, and falls through when v0(=ret(cpu_enabled)) != 0.
  The `beq` branch at 0x51c targets 0x4c8, is taken when a2(=[-0x3bd8]:2) == v0(?), and falls through when a2(=[-0x3bd8]:2) != v0(?).
  The `bne` branch at 0x594 targets 0x5f4, is taken when a4(=[sym(.data)+1104]) != 0, and falls through when a4(=[sym(.data)+1104]) == 0.
  The `bne` branch at 0x5d8 targets 0x61c, is taken when a5(?) < a6(=[0x9200000001030100]:8) (unsigned), and falls through when a5(?) >= a6(=[0x9200000001030100]:8) (unsigned).
  The `beq` branch at 0x5e4 targets 0x5a0, is taken when a6(=[sym(.data)+1104]) == 0, and falls through when a6(=[sym(.data)+1104]) != 0.
  The `beq` branch at 0x5ec targets 0x5f8 and is always taken.
  The `beq` branch at 0x604 targets 0x404 and is always taken.
  The `beq` branch at 0x614 targets 0x308 and is always taken.
  The `beq` branch at 0x628 targets 0x404 and is always taken.
  The `beq` branch at 0x63c targets 0x320 and is always taken.
  The `beq` branch at 0x650 targets 0x29c and is always taken.
  The `beq` branch at 0x668 targets 0x380 and is always taken.
  The `beq` branch at 0x680 targets 0x3fc and is always taken.

- `move_buffer` in `IP35/usr/cpu/sysgen/IP35boot/os.a(vmdump.o)` at 0x2b1c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/os.a(vmdump.o)`.
  Range: 0x2b1c-0x3278 (1884 bytes).
  It occupies 1884 bytes.
  4 such `ld` accesses load 8 bytes from abs 0xffffffffffffc400, including `ld` at 0x2c0c, `ld` at 0x2c8c, `ld` at 0x2e08.
  6 such `lh` accesses load 2 bytes from ?, including `lh` at 0x2c14, `lh` at 0x2c90, `lh` at 0x2e64.
  The `lh` at 0x2c1c loads 2 bytes from [-0x3c00]:8 +0x857c.
  The `ld` at 0x2c3c loads 8 bytes from ((ret(get_nasid) << 0x21)+0x9600000000000000 | 0x2000) +0xd0.
  The `ld` at 0x2c44 loads 8 bytes from [((ret(get_nasid) << 0x21)+0x9600000000000000 | 0x2000)+208]:8 +0x40.
  16 such `ld` accesses load 8 bytes from ?, including `ld` at 0x2c54, `ld` at 0x2cac, `ld` at 0x2cb0.
  3 such `ld` accesses load 8 bytes from [-0x3c00]:8 +0x0, including `ld` at 0x2c94, `ld` at 0x2e1c, `ld` at 0x2f84.
  The `ld` at 0x2cfc loads 8 bytes from [-0x3c00]:8 +0x5e8.
  The `sd` at 0x2e38 stores 8 bytes to sym(.data) +0x460.
  The `sd` at 0x2e48 stores 8 bytes to sym(.data) +0x468.
  2 such `lhu` accesses load 2 bytes from ?, including `lhu` at 0x2e70, `lhu` at 0x2f94.
  10 such `sd` accesses store 8 bytes to ?, including `sd` at 0x2f20, `sd` at 0x2f24, `sd` at 0x2f28.
  2 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x2f34, `lbu` at 0x2fe8.
  The `sd` at 0x2f68 stores 8 bytes to table(0x9200000001800000) +0x0.
  The `lw` at 0x2fbc loads 4 bytes from ?.
  2 such `ld` accesses load 8 bytes from table(0x9200000001fc0000) +0x0, including `ld` at 0x3038, `ld` at 0x3114.
  The `sh` at 0x3110 stores 2 bytes to ?.
  The `jal` at 0x2bb4 calls memory_present with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x2bc4 calls memory_write_accessible with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x2bfc calls get_compact_nodeid with a0=?, a1=?, a2=?, a3=?, a4=[sym(numnodes)].
  The `jal` at 0x2c28 calls get_nasid with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x2db8 calls memory_read_accessible with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x2ec4 calls page_allow_access with a0=?, a1=[sym(.sdata)+36], a2=?, a3=?.
  The `jal` at 0x2edc calls page_allow_access with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x2fa8 calls get_nasid with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x314c calls us_delay with a0=0x64, a1=?, a2=?, a3=?.
  The `jal` at 0x31f0 calls bcopy with a0=?, a1=[sym(.sbss)+56]:8, a2=[sym(.sdata)+52], a3=?.
  The `jal` at 0x3238 calls bcopy with a0=?, a1=[sym(.sbss)+56]:8, a2=[sym(.sdata)+52], a3=?, a4=[[-0x3c00]:8]:8, a6=[sym(.sdata)+40].
  The `jal` at 0x325c calls printf with a0=sym(.rodata), a1=?, a2=?, a3=?, a4=[sym(numnodes)].
  The `beq` branch at 0x2b58 targets 0x31f8, is taken when a4(=[sym(numnodes)]) == at(=0x1), and falls through when a4(=[sym(numnodes)]) != at(=0x1).
  The `bltz` branch at 0x2b64 targets 0x2b7c, is taken when v0(=[sym(.sdata)+52]) < 0 (signed), and falls through when v0(=[sym(.sdata)+52]) >= 0 (signed).
  The `bne` branch at 0x2b7c targets 0x324c, is taken when a0(?) != 0, and falls through when a0(?) == 0.
  The `beq` branch at 0x2b9c targets 0x2bfc and is always taken.
  The `blez` branch at 0x2ba8 targets 0x2dd8, is taken when v0(?) <= 0 (signed), and falls through when v0(?) > 0 (signed).
  The `beq` branch at 0x2bbc targets 0x2e90, is taken when v0(=ret(memory_present)) == 0, and falls through when v0(=ret(memory_present)) != 0.
  The `bne` branch at 0x2bcc targets 0x2db8, is taken when v0(=ret(memory_write_accessible)) != 0, and falls through when v0(=ret(memory_write_accessible)) == 0.
  The `beq` branch at 0x2bd4 targets 0x2ed8, is taken when s5(?) == 0, and falls through when s5(?) != 0.
  The `beq` branch at 0x2bf4 targets 0x2de8, is taken when s0(?) >= a4(=[sym(numnodes)]) (signed), and falls through when s0(?) < a4(=[sym(numnodes)]) (signed).
  The `beq` branch at 0x2c04 targets 0x2be0, is taken when v0(=ret(get_compact_nodeid)) == s0(?), and falls through when v0(=ret(get_compact_nodeid)) != s0(?).
  The `beq` branch at 0x2c20 targets 0x2be0, is taken when t8(=[[-0x3c00]:8+34172]:2) == t9(?), and falls through when t8(=[[-0x3c00]:8+34172]:2) != t9(?).
  The `bne` branch at 0x2c80 targets 0x2be0, is taken when t9(?) < 0x1 (unsigned), and falls through when t9(?) >= 0x1 (unsigned).
  The `beq` branch at 0x2cdc targets 0x2cec, is taken when t0(?) == 0, and falls through when t0(?) != 0.
  The `bne` branch at 0x2d74 targets 0x326c, is taken when v0(?) < s1(=0x10000) (signed), and falls through when v0(?) >= s1(=0x10000) (signed).
  The `beq` branch at 0x2d94 targets 0x2ea4, is taken when a3(=[sym(.sdata)+40]) == 0, and falls through when a3(=[sym(.sdata)+40]) != 0.
  The `beq` branch at 0x2da4 targets 0x2ba4, is taken when a3(=(([sym(maxdmasz)] << 0xe) + ([sym(maxdmasz)] << 0xe))) >= v0(?) (unsigned), and falls through when a3(=(([sym(maxdmasz)] << 0xe) + ([sym(maxdmasz)] << 0xe))) < v0(?) (unsigned).
  The `beq` branch at 0x2db0 targets 0x2ba8 and is always taken.
  The `beq` branch at 0x2dc0 targets 0x2eb8, is taken when v0(=ret(memory_read_accessible)) == 0, and falls through when v0(=ret(memory_read_accessible)) != 0.
  The `bne` branch at 0x2dd0 targets 0x2bb4, is taken when s3(?) < a1(=[sym(.sdata)+36]) (signed), and falls through when s3(?) >= a1(=[sym(.sdata)+36]) (signed).
  The `bne` branch at 0x2dd8 targets 0x2be0, is taken when s5(?) != 0, and falls through when s5(?) == 0.
  The `beq` branch at 0x2e00 targets 0x3248, is taken when s0(?) >= a4(=[sym(numnodes)]) (signed), and falls through when s0(?) < a4(=[sym(numnodes)]) (signed).
  The `beq` branch at 0x2e18 targets 0x2e54, is taken when a6(=[sym(.sdata)+40]) == 0, and falls through when a6(=[sym(.sdata)+40]) != 0.
  The `beq` branch at 0x2e68 targets 0x3228, is taken when a2(?) == s5(=-0x1), and falls through when a2(?) != s5(=-0x1).
  The `blez` branch at 0x2e74 targets 0x31e0, is taken when v1(?) <= 0 (signed), and falls through when v1(?) > 0 (signed).
  The `beq` branch at 0x2e88 targets 0x2fa8 and is always taken.
  The `bne` branch at 0x2e94 targets 0x2be0, is taken when s5(?) != 0, and falls through when s5(?) == 0.
  The `beq` branch at 0x2e9c targets 0x2de4 and is always taken.
  The `beq` branch at 0x2ea4 targets 0x2ef0, is taken when t9(?) == 0, and falls through when t9(?) != 0.
  The `beq` branch at 0x2eb0 targets 0x2ba8 and is always taken.
  The `bne` branch at 0x2eb8 targets 0x2bdc, is taken when s5(?) != 0, and falls through when s5(?) == 0.
  The `beq` branch at 0x2ed0 targets 0x2dc4 and is always taken.
  The `beq` branch at 0x2ee8 targets 0x2dc4 and is always taken.
  The `beq` branch at 0x2ef0 targets 0x2ba8 and is always taken.
  The `beq` branch at 0x2f08 targets 0x31c0, is taken when (a2(?) & 0x20) == 0, and falls through when (a2(?) & 0x20) != 0.
  The `bltz` branch at 0x2f4c targets 0x3178, is taken when t1(?) < 0 (signed), and falls through when t1(?) >= 0 (signed).
  The `beq` branch at 0x2f74 targets 0x314c, is taken when t3(?) == s5(=-0x1), and falls through when t3(?) != s5(=-0x1).
  The `beq` branch at 0x2fa0 targets 0x31e0, is taken when s3(?) >= t8(?) (signed), and falls through when s3(?) < t8(?) (signed).
  The `beq` branch at 0x2fd0 targets 0x2f7c, is taken when t9(?) == s5(=-0x1), and falls through when t9(?) != s5(=-0x1).
  The `beq` branch at 0x3070 targets 0x3188, is taken when 0 >= at(?) (unsigned), and falls through when 0 < at(?) (unsigned).
  The `beq` branch at 0x3078 targets 0x31a8, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `beq` branch at 0x308c targets 0x31b8, is taken when (a2(?) & 0x20) == 0, and falls through when (a2(?) & 0x20) != 0.
  The `beq` branch at 0x312c targets 0x3198, is taken when 0 >= a1(?) (unsigned), and falls through when 0 < a1(?) (unsigned).
  The `bne` branch at 0x3134 targets 0x2ef8, is taken when a5(?) != 0, and falls through when a5(?) == 0.
  The `beq` branch at 0x3144 targets 0x2f04 and is always taken.
  The `bne` branch at 0x3168 targets 0x2f6c, is taken when a2(?) < v1(=0x7a120) (signed), and falls through when a2(?) >= v1(=0x7a120) (signed).
  The `beq` branch at 0x3170 targets 0x2f7c and is always taken.
  The `beq` branch at 0x3180 targets 0x2f58 and is always taken.
  The `beq` branch at 0x3188 targets 0x31c8, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `beq` branch at 0x3190 targets 0x30a0 and is always taken.
  The `beq` branch at 0x3198 targets 0x31d4, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `beq` branch at 0x31a0 targets 0x2f1c and is always taken.
  The `beq` branch at 0x31b0 targets 0x3088 and is always taken.
  The `beq` branch at 0x31b8 targets 0x309c and is always taken.
  The `beq` branch at 0x31c0 targets 0x2f18 and is always taken.
  The `beq` branch at 0x31cc targets 0x309c and is always taken.
  The `beq` branch at 0x31d8 targets 0x2f18 and is always taken.
  The `blez` branch at 0x31e4 targets 0x31f8, is taken when a2(=[sym(.sdata)+52]) <= 0 (signed), and falls through when a2(=[sym(.sdata)+52]) > 0 (signed).
  The `blez` branch at 0x322c targets 0x31fc, is taken when a2(=[sym(.sdata)+52]) <= 0 (signed), and falls through when a2(=[sym(.sdata)+52]) > 0 (signed).
  The `beq` branch at 0x3240 targets 0x31fc and is always taken.
  The `beq` branch at 0x3264 targets 0x31fc and is always taken.
  The `beq` branch at 0x3270 targets 0x31f8 and is always taken.
  The return at 0x3220 has v0 = one of ?, ret(bcopy), ret(printf).
