# Readings: `IP30/usr/cpu/sysgen/IP30boot/ioc3_pckm.o`

One entry per routine, filed here from the reading batches by binary.

- `ioc3_pckm_mlreset` in `IP30/usr/cpu/sysgen/IP30boot/ioc3_pckm.o` at 0x0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/ioc3_pckm.o`.
  Range: 0x0-0x4c (76 bytes).
  It occupies 76 bytes.
  The `jal` at 0x38 calls pckm_console_register with a0=sp-64, a1=sym(ioc3_pckm_kbdexists), a2=sym(ioc3_early_pckminit), a3=a3 at entry (arg3).
  The return at 0x44 has v0 = ret(pckm_console_register).

- `ioc3_early_pckminit` in `IP30/usr/cpu/sysgen/IP30boot/ioc3_pckm.o` at 0x4c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/ioc3_pckm.o`.
  Range: 0x4c-0x54 (8 bytes).
  It occupies 8 bytes.
  The return at 0x4c has v0 = ?.

- `pckminit` in `IP30/usr/cpu/sysgen/IP30boot/ioc3_pckm.o` at 0x54 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/ioc3_pckm.o`.
  Range: 0x54-0x5c (8 bytes).
  It occupies 8 bytes.
  The return at 0x54 has v0 = ?.

- `pckm_open` in `IP30/usr/cpu/sysgen/IP30boot/ioc3_pckm.o` at 0x590 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/ioc3_pckm.o`.
  Range: 0x590-0x8c0 (816 bytes).
  It occupies 816 bytes.
  The `lw` at 0x5d0 loads 4 bytes from a1 (arg1 at entry) +0x0.
  4 such `lw` accesses load 4 bytes from ret(hwgraph_fastinfo_get) +0x50, including `lw` at 0x5fc, `lw` at 0x674, `lw` at 0x710.
  3 such `lw` accesses load 4 bytes from ret(hwgraph_fastinfo_get) +0x4, including `lw` at 0x60c, `lw` at 0x6c8, `lw` at 0x7d4.
  The `sd` at 0x644 stores 8 bytes to a0 (arg0 at entry) +0x28.
  The `sd` at 0x648 stores 8 bytes to ?.
  9 such `ld` accesses load 8 bytes from ret(hwgraph_fastinfo_get) +0x48, including `ld` at 0x64c, `ld` at 0x664, `ld` at 0x66c.
  The `sd` at 0x654 stores 8 bytes to ret(hwgraph_fastinfo_get) +0x20.
  The `sd` at 0x658 stores 8 bytes to ret(hwgraph_fastinfo_get) +0x28.
  The `sw` at 0x668 stores 4 bytes to [ret(hwgraph_fastinfo_get)+72]:8 +0x34.
  2 such `lw` accesses load 4 bytes from [ret(hwgraph_fastinfo_get)+72]:8 +0x28, including `lw` at 0x670, `lw` at 0x714.
  The `lw` at 0x680 loads 4 bytes from [ret(hwgraph_fastinfo_get)+72]:8 +0x2c.
  The `lw` at 0x698 loads 4 bytes from [ret(hwgraph_fastinfo_get)+72]:8 +0x5c.
  3 such `sw` accesses store 4 bytes to ret(hwgraph_fastinfo_get) +0x8, including `sw` at 0x6b0, `sw` at 0x808, `sw` at 0x81c.
  2 such `sw` accesses store 4 bytes to ret(hwgraph_fastinfo_get) +0xc, including `sw` at 0x6b8, `sw` at 0x7fc.
  The `sw` at 0x6d8 stores 4 bytes to ret(hwgraph_fastinfo_get) +0x4.
  The `ll` at 0x6f8 loads 4 bytes from ret(hwgraph_fastinfo_get) +0x4.
  The `sc` at 0x700 stores 4 bytes to ret(hwgraph_fastinfo_get) +0x4.
  The `lhu` at 0x774 loads 2 bytes from sym(.rodata) +0x15c.
  The `lw` at 0x778 loads 4 bytes from sym(.rodata) +0x158.
  The `lw` at 0x7b8 loads 4 bytes from [ret(hwgraph_fastinfo_get)+72]:8 +0x4.
  The `lw` at 0x7c4 loads 4 bytes from [ret(hwgraph_fastinfo_get)+72]:8 +0x8.
  The `lw` at 0x7ec loads 4 bytes from [ret(hwgraph_fastinfo_get)+72]:8 +0x34.
  The `jal` at 0x5a4 calls WR with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x5ec calls hwgraph_fastinfo_get with a0=[a1], a1=-0x1, a2=?, a3=?.
  The `jal` at 0x65c calls mutex_lock with a0=[ret(hwgraph_fastinfo_get)+72]:8+72, a1=0x19, a2=?, a3=a0 at entry (arg0).
  The `jal` at 0x68c calls default_ms_setting with a0=ret(hwgraph_fastinfo_get), a1=[ret(hwgraph_fastinfo_get)+72]:8, a2=?, a3=?, a6=[[ret(hwgraph_fastinfo_get)+72]:8+44].
  The `jal` at 0x6bc calls pckm_reinit_lock with a0=ret(hwgraph_fastinfo_get), a1=0x3, a2=?, a3=?.
  The `jal` at 0x6d4 calls mutex_unlock with a0=[ret(hwgraph_fastinfo_get)+72]:8+72, a1=([ret(hwgraph_fastinfo_get)+4] | 0x2), a2=[ret(hwgraph_fastinfo_get)+4], a3=?.
  The `jal` at 0x728 calls device_controller_num_get with a0=[a1], a1=?, a2=?, a3=?, a4=[ret(hwgraph_fastinfo_get)+80], a5=ret(hwgraph_fastinfo_get)+4, a6=0x20, a7=([ret(hwgraph_fastinfo_get)+4] | 0x20).
  The `jal` at 0x74c calls hwgraph_traverse with a0=[a1], a1=sym(.rodata), a2=sp-128, a3=?.
  The `jal` at 0x798 calls sprintf with a0=sp-120, a1=sym(.rodata), a2=?, a3=?, a5=sym(.rodata).
  The `jal` at 0x7ac calls hwgraph_path_add with a0=[sym(hwgraph_root)], a1=sp-120, a2=sp-96, a3=?.
  The `jal` at 0x7d8 calls pckm_pollcmd with a0=ret(hwgraph_fastinfo_get), a1=0xed, a2=?, a3=?, a4=[[ret(hwgraph_fastinfo_get)+72]:8+40], a5=[ret(hwgraph_fastinfo_get)+72]:8.
  The `jal` at 0x7e8 calls pckm_pollcmd with a0=ret(hwgraph_fastinfo_get), a1=[[ret(hwgraph_fastinfo_get)+72]:8+52], a2=?, a3=?.
  The `jal` at 0x804 calls pckm_pollcmd with a0=ret(hwgraph_fastinfo_get), a1=0xf8, a2=0xc, a3=0x2.
  The `jal` at 0x828 calls hwgraph_edge_add with a0=?, a1=[a1], a2=sym(.rodata), a3=?.
  The `jal` at 0x840 calls hwgraph_edge_add with a0=?, a1=[a1], a2=sym(.rodata), a3=[[ret(hwgraph_fastinfo_get)+72]:8+8].
  The `jal` at 0x85c calls device_controller_num_get with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x880 calls device_controller_num_set with a0=?, a1=?, a2=-0x1, a3=?.
  The `jal` at 0x8ac calls cmn_err with a0=0x4, a1=sym(.rodata), a2=[a1], a3=?.
  The `beq` branch at 0x5ac targets 0x5cc, is taken when s0(=a3) == 0, and falls through when s0(=a3) != 0.
  The `bne` branch at 0x5dc targets 0x630, is taken when (at(?) & 0x1ff) != 0, and falls through when (at(?) & 0x1ff) == 0.
  The `beq` branch at 0x5e4 targets 0x638, is taken when a1(=-0x1) == s1(=[a1]), and falls through when a1(=-0x1) != s1(=[a1]).
  The `beq` branch at 0x5f4 targets 0x6e4, is taken when v0(=ret(hwgraph_fastinfo_get)) == 0, and falls through when v0(=ret(hwgraph_fastinfo_get)) != 0.
  The `beq` branch at 0x604 targets 0x6ec, is taken when t8(=[ret(hwgraph_fastinfo_get)+80]) == t9(=0x13), and falls through when t8(=[ret(hwgraph_fastinfo_get)+80]) != t9(=0x13).
  The `beq` branch at 0x614 targets 0x6f4, is taken when (a0(=[ret(hwgraph_fastinfo_get)+4]) & 0x20) == 0, and falls through when (a0(=[ret(hwgraph_fastinfo_get)+4]) & 0x20) != 0.
  The `beq` branch at 0x620 targets 0x640, is taken when (a0(=[ret(hwgraph_fastinfo_get)+4]) & 0x2) == 0, and falls through when (a0(=[ret(hwgraph_fastinfo_get)+4]) & 0x2) != 0.
  The `beq` branch at 0x628 targets 0x5b8 and is always taken.
  The `beq` branch at 0x630 targets 0x5b8 and is always taken.
  The `beq` branch at 0x638 targets 0x5b8 and is always taken.
  The `beq` branch at 0x678 targets 0x7d8, is taken when a4(=[[ret(hwgraph_fastinfo_get)+72]:8+40]) == v0(=[ret(hwgraph_fastinfo_get)+80]), and falls through when a4(=[[ret(hwgraph_fastinfo_get)+72]:8+40]) != v0(=[ret(hwgraph_fastinfo_get)+80]).
  The `bne` branch at 0x684 targets 0x6c8, is taken when a6(=[[ret(hwgraph_fastinfo_get)+72]:8+44]) != v0(=[ret(hwgraph_fastinfo_get)+80]), and falls through when a6(=[[ret(hwgraph_fastinfo_get)+72]:8+44]) == v0(=[ret(hwgraph_fastinfo_get)+80]).
  The `beq` branch at 0x6a0 targets 0x818, is taken when v0(=[[ret(hwgraph_fastinfo_get)+72]:8+92]) == a1(=0x3), and falls through when v0(=[[ret(hwgraph_fastinfo_get)+72]:8+92]) != a1(=0x3).
  The `beq` branch at 0x6a8 targets 0x818, is taken when v0(=[[ret(hwgraph_fastinfo_get)+72]:8+92]) == a0(=0x4), and falls through when v0(=[[ret(hwgraph_fastinfo_get)+72]:8+92]) != a0(=0x4).
  The `beq` branch at 0x6dc targets 0x5b8 and is always taken.
  The `beq` branch at 0x6e4 targets 0x5b8 and is always taken.
  The `beq` branch at 0x6ec targets 0x5b8 and is always taken.
  The `beql` branch at 0x704 targets 0x6f8, is taken when a7(=([ret(hwgraph_fastinfo_get)+4] | 0x20)) == 0, and falls through when a7(=([ret(hwgraph_fastinfo_get)+4] | 0x20)) != 0; its branch-likely delay slot `nop` at 0x708 runs only when taken and is annulled on fall-through.
  The `bne` branch at 0x738 targets 0x850, is taken when t0(?) != 0, and falls through when t0(?) == 0.
  The `beq` branch at 0x754 targets 0x85c, is taken when v0(=ret(hwgraph_traverse)) == 0, and falls through when v0(=ret(hwgraph_traverse)) != 0.
  The `blez` branch at 0x75c targets 0x8a0, is taken when s2(?) <= 0 (signed), and falls through when s2(?) > 0 (signed).
  The `bne` branch at 0x768 targets 0x78c, is taken when s2(?) != a2(=0x1), and falls through when s2(?) == a2(=0x1).
  The `beq` branch at 0x784 targets 0x7a4 and is always taken.
  The `beq` branch at 0x7bc targets 0x820, is taken when a2(=[[ret(hwgraph_fastinfo_get)+72]:8+4]) == s1(=[a1]), and falls through when a2(=[[ret(hwgraph_fastinfo_get)+72]:8+4]) != s1(=[a1]).
  The `beq` branch at 0x7c8 targets 0x838, is taken when a3(=[[ret(hwgraph_fastinfo_get)+72]:8+8]) == s1(=[a1]), and falls through when a3(=[[ret(hwgraph_fastinfo_get)+72]:8+8]) != s1(=[a1]).
  The `beq` branch at 0x7d0 targets 0x61c and is always taken.
  The `beq` branch at 0x810 targets 0x680 and is always taken.
  The `beq` branch at 0x818 targets 0x6b4 and is always taken.
  The `beq` branch at 0x830 targets 0x7d0 and is always taken.
  The `beq` branch at 0x848 targets 0x7d0 and is always taken.
  The `beq` branch at 0x854 targets 0x748 and is always taken.
  The `beq` branch at 0x86c targets 0x87c, is taken when v0(=ret(device_controller_num_get)) == a2(=-0x1), and falls through when v0(=ret(device_controller_num_get)) != a2(=-0x1).
  The `beq` branch at 0x874 targets 0x75c and is always taken.
  The `bne` branch at 0x890 targets 0x874, is taken when a0(?) != a3(=-0x1), and falls through when a0(?) == a3(=-0x1).
  The `beq` branch at 0x898 targets 0x75c and is always taken.
  The `beq` branch at 0x8b8 targets 0x5b8 and is always taken.
  The return at 0x5c4 has v0 = one of 0x6, 0x10, 0x13, 0x0, 0x5.

- `pckm_close` in `IP30/usr/cpu/sysgen/IP30boot/ioc3_pckm.o` at 0x8c0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/ioc3_pckm.o`.
  Range: 0x8c0-0x9a4 (228 bytes).
  It occupies 228 bytes.
  The `ld` at 0x8c8 loads 8 bytes from a0 (arg0 at entry) +0x28.
  4 such `ld` accesses load 8 bytes from [a0+40]:8 +0x48, including `ld` at 0x8d0, `ld` at 0x948, `ld` at 0x960.
  2 such `lw` accesses load 4 bytes from [a0+40]:8 +0x4, including `lw` at 0x8e4, `lw` at 0x8fc.
  The `lw` at 0x8f8 loads 4 bytes from [a0+40]:8 +0x10.
  2 such `sw` accesses store 4 bytes to [a0+40]:8 +0x4, including `sw` at 0x910, `sw` at 0x924.
  The `ld` at 0x92c loads 8 bytes from [a0+40]:8 +0x30.
  The `ld` at 0x930 loads 8 bytes from [a0+40]:8 +0x40.
  The `sd` at 0x938 stores 8 bytes to [a0+40]:8 +0x30.
  The `lw` at 0x93c loads 4 bytes from [a0+40]:8 +0x50.
  The `sd` at 0x940 stores 8 bytes to [a0+40]:8 +0x20.
  The `sd` at 0x944 stores 8 bytes to [a0+40]:8 +0x28.
  The `sd` at 0x94c stores 8 bytes to [a0+40]:8 +0x40.
  The `lw` at 0x950 loads 4 bytes from [[a0+40]:8+72]:8 +0x2c.
  The `sw` at 0x95c stores 4 bytes to [[a0+40]:8+72]:8 +0x34.
  The `lw` at 0x970 loads 4 bytes from [[a0+40]:8+72]:8 +0x34.
  The `jal` at 0x8dc calls mutex_lock with a0=[[a0+40]:8+72]:8+72, a1=0x19, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x8f4 calls untimeout with a0=[[a0+40]:8+16], a1=?, a2=[[a0+40]:8+4], a3=?, a5=-0x13.
  The `jal` at 0x920 calls str_unbcall with a0=a0 at entry (arg0), a1=?, a2=?, a3=?, a5=-0x13.
  The `jal` at 0x928 calls freemsg with a0=[[a0+40]:8+48]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x934 calls freemsg with a0=[[a0+40]:8+64]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x96c calls default_kbd_setting with a0=[a0+40]:8, a1=0x0, a2=[[[a0+40]:8+72]:8+52], a3=?, a4=[[a0+40]:8+72]:8, a7=[[[a0+40]:8+72]:8+44].
  The `jal` at 0x97c calls pckm_pollcmd with a0=[a0+40]:8, a1=0xff, a2=?, a3=?, a4=[[a0+40]:8+72]:8, a7=[[[a0+40]:8+72]:8+44].
  The `jal` at 0x988 calls mutex_unlock with a0=[[a0+40]:8+72]:8+72, a1=?, a2=?, a3=?.
  The `beq` branch at 0x8ec targets 0x904, is taken when (a2(=[[a0+40]:8+4]) & 0x10) == 0, and falls through when (a2(=[[a0+40]:8+4]) & 0x10) != 0.
  The `beq` branch at 0x90c targets 0x928, is taken when (a2(?) & 0x8) == 0, and falls through when (a2(?) & 0x8) != 0.
  The `beq` branch at 0x954 targets 0x97c, is taken when a7(=[[[a0+40]:8+72]:8+44]) == t0(=[[a0+40]:8+80]), and falls through when a7(=[[[a0+40]:8+72]:8+44]) != t0(=[[a0+40]:8+80]).
  The `beq` branch at 0x974 targets 0x984 and is always taken.
  The return at 0x99c has v0 = 0x0.

- `pckm_wput` in `IP30/usr/cpu/sysgen/IP30boot/ioc3_pckm.o` at 0x9a4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/ioc3_pckm.o`.
  Range: 0x9a4-0xcd4 (816 bytes).
  It occupies 816 bytes.
  The `ld` at 0x9ac loads 8 bytes from a0 (arg0 at entry) +0x28.
  15 such `ld` accesses load 8 bytes from [a0+40]:8 +0x48, including `ld` at 0x9b8, `ld` at 0x9fc, `ld` at 0xa80.
  The `ld` at 0x9d4 loads 8 bytes from a1 (arg1 at entry) +0x28.
  The `lbu` at 0x9d8 loads 1 byte from [a1+40]:8 +0x1e.
  9 such `ld` accesses load 8 bytes from a1 (arg1 at entry) +0x18, including `ld` at 0xa1c, `ld` at 0xa40, `ld` at 0xaac.
  6 such `lbu` accesses load 1 byte from [a1+24]:8 +0x0, including `lbu` at 0xa20, `lbu` at 0xa44, `lbu` at 0xabc.
  The `sb` at 0xa64 stores 1 byte to [a1+24]:8 +0x0.
  4 such `ld` accesses load 8 bytes from a1 (arg1 at entry) +0x20, including `ld` at 0xaa8, `ld` at 0xb3c, `ld` at 0xbe8.
  3 such `lw` accesses load 4 bytes from [[a0+40]:8+72]:8 +0x28, including `lw` at 0xae4, `lw` at 0xb50, `lw` at 0xbe4.
  The `ld` at 0xaf8 loads 8 bytes from ([[a0+40]:8+72]:8 + ([[[a0+40]:8+72]:8+40] << 0x3)) +0x18.
  3 such `lw` accesses load 4 bytes from [[a0+40]:8+72]:8 +0x2c, including `lw` at 0xb14, `lw` at 0xb64, `lw` at 0xb98.
  The `ld` at 0xb2c loads 8 bytes from ([[a0+40]:8+72]:8 + ([[[a0+40]:8+72]:8+44] << 0x3)) +0x18.
  3 such `sd` accesses store 8 bytes to a1 (arg1 at entry) +0x18, including `sd` at 0xb38, `sd` at 0xb80, `sd` at 0xc6c.
  2 such `lw` accesses load 4 bytes from [a0+40]:8 +0x50, including `lw` at 0xb60, `lw` at 0xb9c.
  The `lbu` at 0xb74 loads 1 byte from ?.
  3 such `sd` accesses store 8 bytes to a1 (arg1 at entry) +0x20, including `sd` at 0xbf8, `sd` at 0xc34, `sd` at 0xc78.
  The `lw` at 0xc00 loads 4 bytes from [[a0+40]:8+72]:8 +0x58.
  3 such `sb` accesses store 1 byte to [a1+32]:8 +0x0, including `sb` at 0xc04, `sb` at 0xc4c, `sb` at 0xc80.
  The `lw` at 0xc40 loads 4 bytes from [[a0+40]:8+72]:8 +0x5c.
  The `jal` at 0x9cc calls mutex_lock with a0=[[a0+40]:8+72]:8+72, a1=0x19, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa00 calls mutex_unlock with a0=[[a0+40]:8+72]:8+72, a1=0x86, a2=?, a3=?.
  The `jal` at 0xa0c calls sdrv_error with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0xa38 calls flushq with a0=a0 at entry (arg0), a1=0x0, a2=?, a3=?.
  The `jal` at 0xa60 calls RD with a0=a0 at entry (arg0), a1=[[a1+24]:8]:1, a2=?, a3=?.
  The `jal` at 0xa6c calls flushq with a0=ret(RD), a1=0x1, a2=?, a3=?.
  The `jal` at 0xa78 calls qreply with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0xa84 calls mutex_unlock with a0=[[a0+40]:8+72]:8+72, a1=?, a2=?, a3=?.
  The `jal` at 0xaf4 calls pckm_reinit_lock with a0=[([[a0+40]:8+72]:8 + ([[[a0+40]:8+72]:8+40] << 0x3))+24]:8, a1=[[a1+24]:8]:1, a2=?, a3=0xfa, a4=[[[a0+40]:8+72]:8+40], a5=[[a0+40]:8+72]:8, a6=0x13.
  The `jal` at 0xb28 calls pckm_reinit_lock with a0=[([[a0+40]:8+72]:8 + ([[[a0+40]:8+72]:8+44] << 0x3))+24]:8, a1=[[a0+40]:8+72]:8, a2=?, a3=?, a4=[[[a0+40]:8+72]:8+44].
  The `jal` at 0xb70 calls ioc3_lcl_pckm_setleds_lock with a0=[a0+40]:8, a1=?, a2=[[[a0+40]:8+72]:8+40], a3=0x13, a4=[[[a0+40]:8+72]:8+44], a5=[[a0+40]:8+80].
  The `jal` at 0xb84 calls freemsg with a0=a1 at entry (arg1), a1=?, a2=?, a3=?.
  The `jal` at 0xbbc calls freemsg with a0=a1 at entry (arg1), a1=?, a2=?, a3=?, a7=[[[a0+40]:8+72]:8+44].
  The `jal` at 0xc0c calls qreply with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0xc1c calls freemsg with a0=a1 at entry (arg1), a1=[[a1+24]:8]:1, a2=?, a3=?.
  The `jal` at 0xc48 calls qreply with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?, a7=[[[a0+40]:8+72]:8+44].
  The `jal` at 0xc88 calls pckm_pollcmd with a0=[a0+40]:8, a1=0xfa, a2=0xfc, a3=0xfa, a5=[a1+32]:8, a6=0x13.
  The `jal` at 0xc94 calls pckm_pollcmd with a0=[a0+40]:8, a1=0xfc, a2=?, a3=?.
  The `jal` at 0xca0 calls pckm_pollcmd with a0=[a0+40]:8, a1=0x14, a2=?, a3=?.
  The `jal` at 0xcac calls pckm_pollcmd with a0=[a0+40]:8, a1=0xfc, a2=?, a3=?.
  The `jal` at 0xcb8 calls pckm_pollcmd with a0=[a0+40]:8, a1=0x76, a2=?, a3=?.
  The `jal` at 0xcc4 calls pckm_pollcmd with a0=[a0+40]:8, a1=0xf4, a2=?, a3=?.
  The `beq` branch at 0x9dc targets 0xaa8, is taken when v0(=[[a1+40]:8+30]:1) == 0, and falls through when v0(=[[a1+40]:8+30]:1) != 0.
  The `beq` branch at 0x9e4 targets 0xb94, is taken when v0(=[[a1+40]:8+30]:1) == v1(=0xe), and falls through when v0(=[[a1+40]:8+30]:1) != v1(=0xe).
  The `beq` branch at 0x9ec targets 0xbcc, is taken when v0(=[[a1+40]:8+30]:1) == a0(=0xd), and falls through when v0(=[[a1+40]:8+30]:1) != a0(=0xd).
  The `beq` branch at 0x9f4 targets 0xa1c, is taken when v0(=[[a1+40]:8+30]:1) == a1(=0x86), and falls through when v0(=[[a1+40]:8+30]:1) != a1(=0x86).
  The `beq` branch at 0xa14 targets 0xa90 and is always taken.
  The `beq` branch at 0xa2c targets 0xa50, is taken when (a0(=[[a1+24]:8]:1) & 0x2) == 0, and falls through when (a0(=[[a1+24]:8]:1) & 0x2) != 0.
  The `beq` branch at 0xa50 targets 0xc1c, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0xab4 targets 0xb44, is taken when a4(=[a1+24]:8) >= a5(=[a1+32]:8) (unsigned), and falls through when a4(=[a1+24]:8) < a5(=[a1+32]:8) (unsigned).
  The `beq` branch at 0xac4 targets 0xc58, is taken when a1(=[[a1+24]:8]:1) == a2(=0xfc), and falls through when a1(=[[a1+24]:8]:1) != a2(=0xfc).
  The `beq` branch at 0xad0 targets 0xc84, is taken when a1(=[[a1+24]:8]:1) == a3(=0xfa), and falls through when a1(=[[a1+24]:8]:1) != a3(=0xfa).
  The `beq` branch at 0xad8 targets 0xb08, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0xae8 targets 0xb04, is taken when a4(=[[[a0+40]:8+72]:8+40]) == a6(=0x13), and falls through when a4(=[[[a0+40]:8+72]:8+40]) != a6(=0x13).
  The `beq` branch at 0xb08 targets 0xb34, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0xb18 targets 0xb38, is taken when a4(=[[[a0+40]:8+72]:8+44]) == a0(=0x13), and falls through when a4(=[[[a0+40]:8+72]:8+44]) != a0(=0x13).
  The `beq` branch at 0xb44 targets 0xb84, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0xb58 targets 0xb84, is taken when a2(=[[[a0+40]:8+72]:8+40]) == a3(=0x13), and falls through when a2(=[[[a0+40]:8+72]:8+40]) != a3(=0x13).
  The `beq` branch at 0xb68 targets 0xb84, is taken when a4(=[[[a0+40]:8+72]:8+44]) == a5(=[[a0+40]:8+80]), and falls through when a4(=[[[a0+40]:8+72]:8+44]) != a5(=[[a0+40]:8+80]).
  The `beq` branch at 0xb8c targets 0xa84 and is always taken.
  The `bne` branch at 0xba0 targets 0xbbc, is taken when a7(=[[[a0+40]:8+72]:8+44]) != t0(=[[a0+40]:8+80]), and falls through when a7(=[[[a0+40]:8+72]:8+44]) == t0(=[[a0+40]:8+80]).
  The `beq` branch at 0xbb4 targets 0xc2c, is taken when t0(=[[a1+24]:8]:1) == t1(=0x12), and falls through when t0(=[[a1+24]:8]:1) != t1(=0x12).
  The `beq` branch at 0xbc4 targets 0xa84 and is always taken.
  The `bne` branch at 0xbd8 targets 0xa80, is taken when t1(=[[a1+24]:8]:1) != t2(=0xde), and falls through when t1(=[[a1+24]:8]:1) == t2(=0xde).
  The `beq` branch at 0xbf0 targets 0xc78, is taken when t2(=[[[a0+40]:8+72]:8+40]) == a1(=0x13), and falls through when t2(=[[[a0+40]:8+72]:8+40]) != a1(=0x13).
  The `beq` branch at 0xc14 targets 0xa84 and is always taken.
  The `beq` branch at 0xc24 targets 0xa84 and is always taken.
  The `beq` branch at 0xc50 targets 0xa84 and is always taken.
  The `bne` branch at 0xc60 targets 0xb44, is taken when at(?) < 0x2 (signed), and falls through when at(?) >= 0x2 (signed).
  The `beq` branch at 0xc70 targets 0xb44 and is always taken.
  The `beq` branch at 0xc7c targets 0xc08 and is always taken.
  The `beq` branch at 0xccc targets 0xb3c and is always taken.
  The return at 0xaa0 has v0 = 0x0.

- `pckm_getbp` in `IP30/usr/cpu/sysgen/IP30boot/ioc3_pckm.o` at 0xcd4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/ioc3_pckm.o`.
  Range: 0xcd4-0xde0 (268 bytes).
  It occupies 268 bytes.
  The `ld` at 0xce0 loads 8 bytes from a0 (arg0 at entry) +0x40.
  2 such `ld` accesses load 8 bytes from [a0+64]:8 +0x20, including `ld` at 0xd00, `ld` at 0xd50.
  The `ld` at 0xd04 loads 8 bytes from [a0+64]:8 +0x18.
  2 such `ld` accesses load 8 bytes from [a0+64]:8 +0x28, including `ld` at 0xd14, `ld` at 0xd54.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x8, including `lw` at 0xd1c, `lw` at 0xd2c, `lw` at 0xdbc.
  The `ld` at 0xd58 loads 8 bytes from [[a0+64]:8+40]:8 +0x10.
  2 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x40, including `sd` at 0xd9c, `sd` at 0xddc.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x4, including `lw` at 0xda0, `lw` at 0xdc8.
  The `ld` at 0xdb0 loads 8 bytes from a0 (arg0 at entry) +0x20.
  The `sw` at 0xdd4 stores 4 bytes to a0 (arg0 at entry) +0x4.
  The `jal` at 0xd30 calls allocb with a0=[a0+8], a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0xd90 calls str_conmsg with a0=a0+48, a1=a0+56, a2=[a0+64]:8, a3=?.
  The `jal` at 0xdb8 calls str_allocb with a0=[a0+8], a1=[a0+32]:8, a2=0x3, a3=?.
  The `beq` branch at 0xcf8 targets 0xd18, is taken when s2(=[a0+64]:8) == 0, and falls through when s2(=[a0+64]:8) != 0.
  The `bne` branch at 0xd08 targets 0xd18, is taken when at(=[[a0+64]:8+24]:8) != v0(=[[a0+64]:8+32]:8), and falls through when at(=[[a0+64]:8+24]:8) == v0(=[[a0+64]:8+32]:8).
  The `beq` branch at 0xd10 targets 0xd58 and is always taken.
  The `beq` branch at 0xd18 targets 0xd30 and is always taken.
  The `bne` branch at 0xd24 targets 0xda0, is taken when v0(=0x3) != s3(=a1), and falls through when v0(=0x3) == s3(=a1).
  The `beq` branch at 0xd38 targets 0xd20, is taken when v0(=ret(allocb)) == 0, and falls through when v0(=ret(allocb)) != 0.
  The `beq` branch at 0xd40 targets 0xdd8, is taken when s2(=[a0+64]:8) == 0, and falls through when s2(=[a0+64]:8) != 0.
  The `bne` branch at 0xd48 targets 0xd8c, is taken when s1(?) != 0, and falls through when s1(?) == 0.
  The `beq` branch at 0xd60 targets 0xd8c, is taken when v0(=[[a0+64]:8+32]:8) >= v1(=[[[a0+64]:8+40]:8+16]:8) (unsigned), and falls through when v0(=[[a0+64]:8+32]:8) < v1(=[[[a0+64]:8+40]:8+16]:8) (unsigned).
  The `beq` branch at 0xd98 targets 0xd68 and is always taken.
  The `bne` branch at 0xda8 targets 0xd40, is taken when (a0(=[a0+4]) & 0x8) != 0, and falls through when (a0(=[a0+4]) & 0x8) == 0.
  The `bne` branch at 0xdc0 targets 0xd40, is taken when v0(=ret(str_allocb)) != 0, and falls through when v0(=ret(str_allocb)) == 0.
  The `bne` branch at 0xdd0 targets 0xd48, is taken when s2(=[a0+64]:8) != 0, and falls through when s2(=[a0+64]:8) == 0.
  The `beq` branch at 0xdd8 targets 0xd68 and is always taken.
  The return at 0xd80 has v0 = ?.
  The instructions from 0xd88 to 0xd88 are not reached by any path from the entry, and their branches are not listed.

- `pckm_rsrv_timer` in `IP30/usr/cpu/sysgen/IP30boot/ioc3_pckm.o` at 0xde0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/ioc3_pckm.o`.
  Range: 0xde0-0xe24 (68 bytes).
  It occupies 68 bytes.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x48, including `ld` at 0xdec, `ld` at 0xe08.
  The `jal` at 0xdf8 calls mutex_lock with a0=[a0+72]:8+72, a1=0x19, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xe00 calls pckm_rsrv_timer_lock with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xe0c calls mutex_unlock with a0=[a0+72]:8+72, a1=?, a2=?, a3=?.
  The return at 0xe1c has v0 = ret(mutex_unlock).

- `pckm_rsrv_timer_lock` in `IP30/usr/cpu/sysgen/IP30boot/ioc3_pckm.o` at 0xe24 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/ioc3_pckm.o`.
  Range: 0xe24-0xea8 (132 bytes).
  It occupies 132 bytes.
  The `lw` at 0xe24 loads 4 bytes from a0 (arg0 at entry) +0x4.
  The `ld` at 0xe40 loads 8 bytes from a0 (arg0 at entry) +0x20.
  The `ld` at 0xe44 loads 8 bytes from [a0+32]:8 +0x38.
  The `lw` at 0xe64 loads 4 bytes from a0 (arg0 at entry) +0xc.
  The `sw` at 0xe70 stores 4 bytes to a0 (arg0 at entry) +0x10.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x4, including `sw` at 0xe8c, `sw` at 0xea4.
  The `jal` at 0xe68 calls streams_timeout with a0=sym(streams_monp), a1=sym(pckm_rsrv_timer), a2=[a0+12], a3=a0 at entry (arg0), a4=0x0, a5=0x0.
  The `jal` at 0xe88 calls qenable with a0=[a0+32]:8, a1=a1 at entry (arg1), a2=[a0+4], a3=a3 at entry (arg3).
  The `beq` branch at 0xe38 targets 0xe98, is taken when (a2(=[a0+4]) & 0x2) == 0, and falls through when (a2(=[a0+4]) & 0x2) != 0.
  The `beq` branch at 0xe4c targets 0xe84, is taken when (v0(=[[a0+32]:8+56]:8) & 0x40) == 0, and falls through when (v0(=[[a0+32]:8+56]:8) & 0x40) != 0.
  The `beq` branch at 0xe90 targets 0xe78 and is always taken.
  The `beq` branch at 0xea0 targets 0xe74 and is always taken.
  The return at 0xe7c has v0 = one of ?, ret(qenable).

- `pckm_rsrv` in `IP30/usr/cpu/sysgen/IP30boot/ioc3_pckm.o` at 0xea8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/ioc3_pckm.o`.
  Range: 0xea8-0xff8 (336 bytes).
  It occupies 336 bytes.
  The `ld` at 0xeb0 loads 8 bytes from a0 (arg0 at entry) +0x28.
  6 such `ld` accesses load 8 bytes from [a0+40]:8 +0x48, including `ld` at 0xebc, `ld` at 0xf50, `ld` at 0xf74.
  The `ld` at 0xed4 loads 8 bytes from a0 (arg0 at entry) +0x18.
  2 such `lw` accesses load 4 bytes from [a0+40]:8 +0x4, including `lw` at 0xee8, `lw` at 0xf30.
  The `sw` at 0xf04 stores 4 bytes to [a0+40]:8 +0x4.
  2 such `ld` accesses load 8 bytes from [a0+40]:8 +0x40, including `ld` at 0xf08, `ld` at 0xfa4.
  The `ld` at 0xf14 loads 8 bytes from [[a0+40]:8+64]:8 +0x20.
  The `ld` at 0xf18 loads 8 bytes from [[a0+40]:8+64]:8 +0x18.
  3 such `ld` accesses load 8 bytes from [a0+40]:8 +0x30, including `ld` at 0xf24, `ld` at 0xfac, `ld` at 0xff4.
  The `sd` at 0xf78 stores 8 bytes to [a0+40]:8 +0x30.
  The `sd` at 0xfe8 stores 8 bytes to [a0+40]:8 +0x40.
  The `jal` at 0xec8 calls mutex_lock with a0=[[a0+40]:8+72]:8+72, a1=0x19, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xed0 calls canput with a0=[a0+24]:8, a1=?, a2=?, a3=?.
  The `jal` at 0xee0 calls enableok with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xf00 calls str_unbcall with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xf54 calls mutex_unlock with a0=[[a0+40]:8+72]:8+72, a1=?, a2=?, a3=?.
  The `jal` at 0xf7c calls mutex_unlock with a0=[[a0+40]:8+72]:8+72, a1=[[a0+40]:8+48]:8, a2=?, a3=?.
  The `jal` at 0xf88 calls putnext with a0=a0 at entry (arg0), a1=[[a0+40]:8+48]:8, a2=?, a3=?.
  The `jal` at 0xf98 calls mutex_lock with a0=[[a0+40]:8+72]:8+72, a1=0x19, a2=?, a3=?.
  The `jal` at 0xfb0 calls noenable with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xfbc calls mutex_unlock with a0=[[a0+40]:8+72]:8+72, a1=?, a2=?, a3=?.
  The `jal` at 0xfcc calls pckm_getbp with a0=[a0+40]:8, a1=0x1, a2=?, a3=?.
  The `jal` at 0xfe0 calls str_conmsg with a0=[a0+40]:8+48, a1=[a0+40]:8+56, a2=[[a0+40]:8+64]:8, a3=?, a4=[[[a0+40]:8+64]:8+32]:8.
  The `beq` branch at 0xed8 targets 0xfb0, is taken when v0(=ret(canput)) == 0, and falls through when v0(=ret(canput)) != 0.
  The `beq` branch at 0xef0 targets 0xf08, is taken when (v0(=[[a0+40]:8+4]) & 0x8) == 0, and falls through when (v0(=[[a0+40]:8+4]) & 0x8) != 0.
  The `beq` branch at 0xf0c targets 0xfa8, is taken when a2(=[[a0+40]:8+64]:8) == 0, and falls through when a2(=[[a0+40]:8+64]:8) != 0.
  The `beq` branch at 0xf20 targets 0xf40, is taken when a3(=[[[a0+40]:8+64]:8+24]:8) >= a4(=[[[a0+40]:8+64]:8+32]:8) (unsigned), and falls through when a3(=[[[a0+40]:8+64]:8+24]:8) < a4(=[[[a0+40]:8+64]:8+32]:8) (unsigned).
  The `beq` branch at 0xf28 targets 0xfe0, is taken when a1(=[[a0+40]:8+48]:8) == 0, and falls through when a1(=[[a0+40]:8+48]:8) != 0.
  The `beq` branch at 0xf38 targets 0xfe0, is taken when (a5(=[[a0+40]:8+4]) & 0x10) == 0, and falls through when (a5(=[[a0+40]:8+4]) & 0x10) != 0.
  The `bne` branch at 0xf40 targets 0xf74, is taken when a1(=[[a0+40]:8+48]:8) != 0, and falls through when a1(=[[a0+40]:8+48]:8) == 0.
  The `beq` branch at 0xf48 targets 0xfcc, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0xfa0 targets 0xf48 and is always taken.
  The `beq` branch at 0xfa8 targets 0xf40 and is always taken.
  The `beq` branch at 0xfc4 targets 0xf60 and is always taken.
  The `beq` branch at 0xfd4 targets 0xf54 and is always taken.
  The `beq` branch at 0xff0 targets 0xf40 and is always taken.
  The return at 0xf6c has v0 = 0x0.
  The instructions from 0xfdc to 0xfdc are not reached by any path from the entry, and their branches are not listed.

- `pckm_reinit` in `IP30/usr/cpu/sysgen/IP30boot/ioc3_pckm.o` at 0xff8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/ioc3_pckm.o`.
  Range: 0xff8-0x103c (68 bytes).
  It occupies 68 bytes.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x48, including `ld` at 0x1004, `ld` at 0x1020.
  The `jal` at 0x1010 calls mutex_lock with a0=[a0+72]:8+72, a1=0x19, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1018 calls pckm_reinit_lock with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x1024 calls mutex_unlock with a0=[a0+72]:8+72, a1=?, a2=?, a3=?.
  The return at 0x1034 has v0 = ret(mutex_unlock).

- `pckm_reinit_lock` in `IP30/usr/cpu/sysgen/IP30boot/ioc3_pckm.o` at 0x103c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/ioc3_pckm.o`.
  Range: 0x103c-0x1098 (92 bytes).
  It occupies 92 bytes.
  3 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x48, including `ld` at 0x1048, `ld` at 0x1068, `ld` at 0x1078.
  2 such `ld` accesses load 8 bytes from [a0+72]:8 +0x60, including `ld` at 0x105c, `ld` at 0x1084.
  The `ld` at 0x106c loads 8 bytes from [a0+72]:8 +0x10.
  The `sw` at 0x1074 stores 4 bytes to [[a0+72]:8+16]:8 +0x1c.
  The `jal` at 0x1058 calls ioc3_write_ireg with a0=[[a0+72]:8+96]:8, a1=0x400000, a2=0x1, a3=a3 at entry (arg3).
  The `jal` at 0x1060 calls pckm_reinit_core with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x1080 calls ioc3_write_ireg with a0=[[a0+72]:8+96]:8, a1=0x400000, a2=0x0, a3=?.
  The return at 0x1090 has v0 = ret(ioc3_write_ireg).

- `pckm_reinit_core` in `IP30/usr/cpu/sysgen/IP30boot/ioc3_pckm.o` at 0x1098 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/ioc3_pckm.o`.
  Range: 0x1098-0x1110 (120 bytes).
  It occupies 120 bytes.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x48, including `ld` at 0x1098, `ld` at 0x10c0.
  The `lw` at 0x109c loads 4 bytes from a0 (arg0 at entry) +0x50.
  The `lw` at 0x10a0 loads 4 bytes from [a0+72]:8 +0x28.
  The `lw` at 0x10d0 loads 4 bytes from [a0+72]:8 +0x34.
  The `lw` at 0x10d4 loads 4 bytes from a0 (arg0 at entry) +0x4.
  The `jal` at 0x10b8 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xf5, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x10cc calls default_kbd_setting with a0=a0 at entry (arg0), a1=0x0, a2=[[a0+72]:8+52], a3=?.
  The `jal` at 0x10e8 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xf8, a2=?, a3=?.
  The `jal` at 0x10f8 calls default_ms_setting with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `bne` branch at 0x10b0 targets 0x10f8, is taken when at(=[[a0+72]:8+40]) != v0(=[a0+80]), and falls through when at(=[[a0+72]:8+40]) == v0(=[a0+80]).
  The `beq` branch at 0x10dc targets 0x1104, is taken when (a3(=[a0+4]) & 0x2) == 0, and falls through when (a3(=[a0+4]) & 0x2) != 0.
  The `beq` branch at 0x10f0 targets 0x1104 and is always taken.
  The return at 0x1108 has v0 = one of ret(default_kbd_setting), ret(pckm_pollcmd), ret(default_ms_setting).

- `default_kbd_setting` in `IP30/usr/cpu/sysgen/IP30boot/ioc3_pckm.o` at 0x1110 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/ioc3_pckm.o`.
  Range: 0x1110-0x11c8 (184 bytes).
  It occupies 184 bytes.
  The `jal` at 0x112c calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xed, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1138 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=a2 at entry (arg2), a2=?, a3=?.
  The `jal` at 0x1144 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xf0, a2=?, a3=?.
  The `jal` at 0x1150 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0x3, a2=?, a3=?.
  The `jal` at 0x115c calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xfa, a2=?, a3=?.
  The `jal` at 0x1168 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xfc, a2=?, a3=?.
  The `jal` at 0x1174 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0x14, a2=?, a3=?.
  The `jal` at 0x1180 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xfc, a2=?, a3=?.
  The `jal` at 0x1190 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0x76, a2=?, a3=?.
  The `jal` at 0x11b8 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xf4, a2=?, a3=?.
  The `beq` branch at 0x119c targets 0x11b8, is taken when (s8(=a1) & 0x1) == 0, and falls through when (s8(=a1) & 0x1) != 0.
  The `beq` branch at 0x11c0 targets 0x11a8 and is always taken.
  The return at 0x11b0 has v0 = ret(pckm_pollcmd).

- `default_ms_setting` in `IP30/usr/cpu/sysgen/IP30boot/ioc3_pckm.o` at 0x11c8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/ioc3_pckm.o`.
  Range: 0x11c8-0x137c (436 bytes).
  It occupies 436 bytes.
  5 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x48, including `ld` at 0x1218, `ld` at 0x12d8, `ld` at 0x12e0.
  3 such `sw` accesses store 4 bytes to [a0+72]:8 +0x5c, including `sw` at 0x121c, `sw` at 0x12dc, `sw` at 0x1358.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x50, including `lw` at 0x12d4, `lw` at 0x1350.
  2 such `lw` accesses load 4 bytes from [a0+72]:8 +0x5c, including `lw` at 0x12e4, `lw` at 0x1360.
  The `jal` at 0x11d8 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xe8, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x11e4 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0x3, a2=?, a3=?.
  The `jal` at 0x11f0 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xf4, a2=?, a3=?.
  The `jal` at 0x1224 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xf6, a2=?, a3=?.
  The `jal` at 0x1230 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xe6, a2=?, a3=?.
  The `jal` at 0x123c calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xf3, a2=?, a3=?.
  The `jal` at 0x1248 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0x64, a2=?, a3=?.
  The `jal` at 0x1254 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xe8, a2=?, a3=?.
  The `jal` at 0x1260 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0x3, a2=?, a3=?.
  The `jal` at 0x126c calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xf4, a2=?, a3=?.
  The `jal` at 0x1288 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xf3, a2=0x2, a3=?.
  The `jal` at 0x1294 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xc8, a2=?, a3=?.
  The `jal` at 0x12a0 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xf3, a2=?, a3=?.
  The `jal` at 0x12ac calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0x64, a2=?, a3=?.
  The `jal` at 0x12b8 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xf3, a2=?, a3=?.
  The `jal` at 0x12c4 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0x50, a2=?, a3=?.
  The `jal` at 0x12d0 calls check_port with a0=a0 at entry (arg0), a1=[a0+80], a2=?, a3=?.
  The `jal` at 0x1304 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xf3, a2=0x2, a3=?.
  The `jal` at 0x1310 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xc8, a2=?, a3=?.
  The `jal` at 0x131c calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xf3, a2=?, a3=?.
  The `jal` at 0x1328 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xc8, a2=?, a3=?.
  The `jal` at 0x1334 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xf3, a2=?, a3=?.
  The `jal` at 0x1340 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0x50, a2=?, a3=?.
  The `jal` at 0x134c calls check_port with a0=a0 at entry (arg0), a1=[a0+80], a2=?, a3=?.
  The `beq` branch at 0x1200 targets 0x1300, is taken when a0(=[sym(pcmouse_mode)]) == a2(=0x2), and falls through when a0(=[sym(pcmouse_mode)]) != a2(=0x2).
  The `beq` branch at 0x1208 targets 0x1284, is taken when a0(=[sym(pcmouse_mode)]) == at(=0x1), and falls through when a0(=[sym(pcmouse_mode)]) != at(=0x1).
  The `beq` branch at 0x1210 targets 0x1288, is taken when a0(=[sym(pcmouse_mode)]) == a2(=0x2), and falls through when a0(=[sym(pcmouse_mode)]) != a2(=0x2).
  The `beq` branch at 0x12f0 targets 0x121c, is taken when v0(?) >= 0x1 (unsigned), and falls through when v0(?) < 0x1 (unsigned).
  The `beq` branch at 0x12f8 targets 0x1224 and is always taken.
  The `bne` branch at 0x136c targets 0x1220, is taken when a0(?) < 0x1 (unsigned), and falls through when a0(?) >= 0x1 (unsigned).
  The `beq` branch at 0x1374 targets 0x1204 and is always taken.
  The return at 0x127c has v0 = ret(pckm_pollcmd).

- `pckm_rx` in `IP30/usr/cpu/sysgen/IP30boot/ioc3_pckm.o` at 0x137c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/ioc3_pckm.o`.
  Range: 0x137c-0x168c (784 bytes).
  It occupies 784 bytes.
  6 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x48, including `ld` at 0x137c, `ld` at 0x14a4, `ld` at 0x14bc.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x50, including `lw` at 0x1380, `lw` at 0x1634, `lw` at 0x1688.
  The `lw` at 0x1388 loads 4 bytes from [a0+72]:8 +0x2c.
  The `lw` at 0x13b0 loads 4 bytes from [a0+72]:8 +0x28.
  6 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x4, including `lw` at 0x13d0, `lw` at 0x13dc, `lw` at 0x1460.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x18, including `ld` at 0x13e4, `ld` at 0x14b0.
  The `sd` at 0x13fc stores 8 bytes to a0 (arg0 at entry) +0x18.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x40, including `ld` at 0x1410, `ld` at 0x1544.
  2 such `ld` accesses load 8 bytes from [a0+64]:8 +0x28, including `ld` at 0x141c, `ld` at 0x1438.
  2 such `ld` accesses load 8 bytes from [[a0+64]:8+40]:8 +0x10, including `ld` at 0x1420, `ld` at 0x1444.
  3 such `ld` accesses load 8 bytes from [a0+64]:8 +0x20, including `ld` at 0x1424, `ld` at 0x1434, `ld` at 0x154c.
  The `sb` at 0x1430 stores 1 byte to [[a0+64]:8+32]:8 +0x0.
  The `sd` at 0x1440 stores 8 bytes to [a0+64]:8 +0x20.
  The `lw` at 0x1470 loads 4 bytes from a0 (arg0 at entry) +0xc.
  The `sw` at 0x1488 stores 4 bytes to a0 (arg0 at entry) +0x4.
  The `sw` at 0x1498 stores 4 bytes to a0 (arg0 at entry) +0x10.
  The `lw` at 0x14f4 loads 4 bytes from a0 (arg0 at entry) +0x10.
  The `ll` at 0x1524 loads 4 bytes from [a0+72]:8 +0x3c.
  The `sc` at 0x1530 stores 4 bytes to [a0+72]:8 +0x3c.
  2 such `lh` accesses load 2 bytes from abs 0xffffffffffffc3a0, including `lh` at 0x15dc, `lh` at 0x1620.
  The `lw` at 0x1650 loads 4 bytes from [a0+72]:8 +0x34.
  The `jal` at 0x148c calls streams_timeout with a0=sym(streams_monp), a1=sym(pckm_rsrv_timer), a2=[a0+12], a3=a0 at entry (arg0), a4=0x0, a5=0x0, a6=0x76, a7=[a0+4].
  The `jal` at 0x14a8 calls mutex_unlock with a0=[a0+72]:8+72, a1=?, a2=?, a3=?.
  The `jalr` at 0x14b4 calls (unknown callee) with a0=?, a1=[a0+24]:8, a2=?, a3=?.
  The `jal` at 0x14c4 calls mutex_lock with a0=[a0+72]:8+72, a1=0x19, a2=?, a3=?.
  The `jal` at 0x14f0 calls untimeout with a0=[a0+16], a1=a0 at entry (arg0), a2=?, a3=?, a5=0x14, a6=0x76.
  The `jal` at 0x1504 calls streams_interrupt with a0=sym(pckm_rsrv_timer), a1=a0 at entry (arg0), a2=0x0, a3=0x0.
  The `jal` at 0x153c calls pckm_getbp with a0=a0 at entry (arg0), a1=0x3, a2=[[a0+72]:8+60]+1, a3=[a0+72]:8+60, a4=0x1, a5=[[a0+72]:8+60]+1.
  The `jal` at 0x1554 calls pckm_getbp with a0=a0 at entry (arg0), a1=0x1, a2=?, a3=[[[a0+64]:8+40]:8+16]:8, a4=[[a0+64]:8+32]:8+1, a5=0x14.
  The `jal` at 0x1568 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xf0, a2=?, a3=[a0+80], a4=[a0+72]:8.
  The `jal` at 0x1578 calls data_check with a0=ret(pckm_pollcmd), a1=0xfa, a2=?, a3=?.
  The `jal` at 0x1588 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0x0, a2=?, a3=?.
  The `jal` at 0x1598 calls data_check with a0=ret(pckm_pollcmd), a1=0xfa, a2=?, a3=?.
  The `jal` at 0x15ac calls pckm_pollcmd with a0=a0 at entry (arg0), a1=-0x2, a2=?, a3=ret(pckm_pollcmd).
  The `jal` at 0x15bc calls data_check with a0=ret(pckm_pollcmd), a1=0x2, a2=?, a3=ret(pckm_pollcmd).
  The `jal` at 0x15d8 calls dtimeout with a0=sym(pckm_reinit), a1=a0 at entry (arg0), a2=0x1, a3=[sym(plbase)]:8, a4=[-0x3c60]:2.
  The `jal` at 0x15e8 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xe9, a2=a2 at entry (arg2), a3=[a0+80], a4=[a0+72]:8.
  The `jal` at 0x15f4 calls data_check with a0=ret(pckm_pollcmd), a1=0xfa, a2=?, a3=?.
  The `jal` at 0x1604 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=-0x2, a2=?, a3=?.
  The `jal` at 0x1610 calls data_check with a0=ret(pckm_pollcmd), a1=0x0, a2=?, a3=?.
  The `jal` at 0x162c calls dtimeout with a0=sym(pckm_reinit), a1=a0 at entry (arg0), a2=0x1, a3=[sym(plbase)]:8, a4=[-0x3c60]:2.
  The `jal` at 0x164c calls default_kbd_setting with a0=a0 at entry (arg0), a1=0x0, a2=[[a0+72]:8+52], a3=?.
  The `jal` at 0x1668 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xf8, a2=?, a3=?.
  The `jal` at 0x167c calls default_ms_setting with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `bne` branch at 0x139c targets 0x13b0, is taken when at(=[[a0+72]:8+44]) != a3(=[a0+80]), and falls through when at(=[[a0+72]:8+44]) == a3(=[a0+80]).
  The `beq` branch at 0x13a8 targets 0x15e8, is taken when a1 == v0(=0xaa), and falls through when a1 != v0(=0xaa).
  The `bne` branch at 0x13b4 targets 0x13dc, is taken when v1(=[[a0+72]:8+40]) != a3(=[a0+80]), and falls through when v1(=[[a0+72]:8+40]) == a3(=[a0+80]).
  The `beq` branch at 0x13bc targets 0x1568, is taken when s1(=a1) == a1(=0xaa), and falls through when s1(=a1) != a1(=0xaa).
  The `beq` branch at 0x13c8 targets 0x1568, is taken when s1(=a1) == a2(=0xfc), and falls through when s1(=a1) != a2(=0xfc).
  The `beq` branch at 0x13d4 targets 0x13e4 and is always taken.
  The `beq` branch at 0x13e8 targets 0x1400, is taken when a1(=[a0+24]:8) == 0, and falls through when a1(=[a0+24]:8) != 0.
  The `beq` branch at 0x13f0 targets 0x149c, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x1400 targets 0x149c, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `bne` branch at 0x1408 targets 0x14a4, is taken when a1(?) != 0, and falls through when a1(?) == 0.
  The `beq` branch at 0x1414 targets 0x1514, is taken when a0(=[a0+64]:8) == 0, and falls through when a0(=[a0+64]:8) != 0.
  The `beq` branch at 0x1428 targets 0x1514, is taken when a2(=[[[a0+64]:8+40]:8+16]:8) == a1(=[[a0+64]:8+32]:8), and falls through when a2(=[[[a0+64]:8+40]:8+16]:8) != a1(=[[a0+64]:8+32]:8).
  The `beq` branch at 0x1448 targets 0x1550, is taken when a3(=[[[a0+64]:8+40]:8+16]:8) == a4(=[[a0+64]:8+32]:8+1), and falls through when a3(=[[[a0+64]:8+40]:8+16]:8) != a4(=[[a0+64]:8+32]:8+1).
  The `beq` branch at 0x1450 targets 0x14e0, is taken when s1(=a1) == a5(=0x14), and falls through when s1(=a1) != a5(=0x14).
  The `beq` branch at 0x1458 targets 0x14e0, is taken when s1(=a1) == a6(=0x76), and falls through when s1(=a1) != a6(=0x76).
  The `bne` branch at 0x1468 targets 0x14d0, is taken when (a7(=[a0+4]) & 0x10) != 0, and falls through when (a7(=[a0+4]) & 0x10) == 0.
  The `beq` branch at 0x1494 targets 0x14cc and is always taken.
  The `beq` branch at 0x149c targets 0x14d0, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x14e8 targets 0x14fc, is taken when (a1(=[a0+4]) & 0x10) == 0, and falls through when (a1(=[a0+4]) & 0x10) != 0.
  The `beq` branch at 0x150c targets 0x14d0 and is always taken.
  The `beql` branch at 0x1534 targets 0x1524, is taken when a5(=[[a0+72]:8+60]+1) == 0, and falls through when a5(=[[a0+72]:8+60]+1) != 0; its branch-likely delay slot `nop` at 0x1538 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x1548 targets 0x1430 and is always taken.
  The `beq` branch at 0x155c targets 0x1450 and is always taken.
  The `beq` branch at 0x1580 targets 0x1594, is taken when v0(=ret(data_check)) == 0, and falls through when v0(=ret(data_check)) != 0.
  The `beq` branch at 0x15a0 targets 0x15b8, is taken when v0(=ret(data_check)) == 0, and falls through when v0(=ret(data_check)) != 0.
  The `beq` branch at 0x15c4 targets 0x1640, is taken when v0(=ret(data_check)) == 0, and falls through when v0(=ret(data_check)) != 0.
  The `beq` branch at 0x15e0 targets 0x14d0 and is always taken.
  The `beq` branch at 0x15fc targets 0x167c, is taken when v0(=ret(data_check)) == 0, and falls through when v0(=ret(data_check)) != 0.
  The `beq` branch at 0x1618 targets 0x1634, is taken when v0(=ret(data_check)) == 0, and falls through when v0(=ret(data_check)) != 0.
  The `beq` branch at 0x1638 targets 0x13b0 and is always taken.
  The `beq` branch at 0x165c targets 0x13e4, is taken when (a0(=[a0+4]) & 0x2) == 0, and falls through when (a0(=[a0+4]) & 0x2) != 0.
  The `beq` branch at 0x1674 targets 0x13e4 and is always taken.
  The `beq` branch at 0x1684 targets 0x1638 and is always taken.
  The return at 0x14d8 has v0 = one of ?, ret(streams_interrupt), ret(dtimeout).
  The instructions from 0x1564 to 0x1564 are not reached by any path from the entry, and their branches are not listed.

- `pckm_intr` in `IP30/usr/cpu/sysgen/IP30boot/ioc3_pckm.o` at 0x168c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/ioc3_pckm.o`.
  Range: 0x168c-0x16cc (64 bytes).
  It occupies 64 bytes.
  The `jal` at 0x16a4 calls mutex_lock with a0=a0+72, a1=0x19, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x16ac calls pckm_intr_lock with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x16b8 calls mutex_unlock with a0=a0+72, a1=?, a2=?, a3=?.
  The return at 0x16c4 has v0 = ret(mutex_unlock).

- `pckm_intr_lock` in `IP30/usr/cpu/sysgen/IP30boot/ioc3_pckm.o` at 0x16cc (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/ioc3_pckm.o`.
  Range: 0x16cc-0x1810 (324 bytes).
  It occupies 324 bytes.
  10 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x10, including `ld` at 0x16cc, `ld` at 0x1738, `ld` at 0x1774.
  9 such `lw` accesses load 4 bytes from [a0+16]:8 +0x9c, including `lw` at 0x16d0, `lw` at 0x1778, `lw` at 0x1788.
  The `ld` at 0x1724 loads 8 bytes from ?.
  The `sw` at 0x1740 stores 4 bytes to [a0+16]:8 +0x1c.
  The `ld` at 0x1744 loads 8 bytes from a0 (arg0 at entry) +0x60.
  8 such `sw` accesses store 4 bytes to [a0+16]:8 +0x9c, including `sw` at 0x1780, `sw` at 0x1794, `sw` at 0x17a8.
  The `jal` at 0x1720 calls valid_data with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1748 calls ioc3_write_ireg with a0=[a0+96]:8, a1=0x400000, a2=0x0, a3=?.
  The `jal` at 0x176c calls cmn_err with a0=0x4, a1=sym(.rodata), a2=[[a0+16]:8+156], a3=([[a0+16]:8+156] << 0x2f).
  The `jal` at 0x1790 calls us_delay with a0=0x640, a1=?, a2=[[a0+16]:8+156], a3=[a0+16]:8, a4=([[a0+16]:8+156] | 0x80), a5=[a0+16]:8.
  The `jal` at 0x17c0 calls cmn_err with a0=0x4, a1=sym(.rodata), a2=[[a0+16]:8+156], a3=sym(.rodata), a4=([[a0+16]:8+156] << 0x2c).
  The `jal` at 0x17e4 calls us_delay with a0=0x640, a1=?, a2=?, a3=?.
  The `bgez` branch at 0x16ec targets 0x16fc, is taken when at(=([[a0+16]:8+156] << 0x2d)) >= 0 (signed), and falls through when at(=([[a0+16]:8+156] << 0x2d)) < 0 (signed).
  The `bltz` branch at 0x16f4 targets 0x1764, is taken when a3(=([[a0+16]:8+156] << 0x2f)) < 0 (signed), and falls through when a3(=([[a0+16]:8+156] << 0x2f)) >= 0 (signed).
  The `bgez` branch at 0x1704 targets 0x1714, is taken when a4(=([[a0+16]:8+156] << 0x2c)) >= 0 (signed), and falls through when a4(=([[a0+16]:8+156] << 0x2c)) < 0 (signed).
  The `bltz` branch at 0x170c targets 0x17c0, is taken when a0(=([[a0+16]:8+156] << 0x2e)) < 0 (signed), and falls through when a0(=([[a0+16]:8+156] << 0x2e)) >= 0 (signed).
  The `bne` branch at 0x1730 targets 0x171c, is taken when s0(?) < 0x2 (signed), and falls through when s0(?) >= 0x2 (signed).
  The `beq` branch at 0x17b8 targets 0x16fc and is always taken.
  The `beq` branch at 0x1808 targets 0x1714 and is always taken.
  The return at 0x175c has v0 = ret(ioc3_write_ireg).

- `pckm_pollcmd` in `IP30/usr/cpu/sysgen/IP30boot/ioc3_pckm.o` at 0x1810 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/ioc3_pckm.o`.
  Range: 0x1810-0x18ec (220 bytes).
  It occupies 220 bytes.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x50, including `lw` at 0x183c, `lw` at 0x1870.
  The `sw` at 0x1850 stores 4 bytes to ?.
  The `lw` at 0x1888 loads 4 bytes from ?.
  4 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x48, including `ld` at 0x18ac, `ld` at 0x18bc, `ld` at 0x18cc.
  4 such `ld` accesses load 8 bytes from [a0+72]:8 +0x10, including `ld` at 0x18b0, `ld` at 0x18c0, `ld` at 0x18d0.
  The `jal` at 0x1834 calls pckm_sendok with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1868 calls us_delay with a0=0x32, a1=?, a2=?, a3=?.
  The `beq` branch at 0x182c targets 0x1854, is taken when a1 == at(=-0x2), and falls through when a1 != at(=-0x2).
  The `beq` branch at 0x1840 targets 0x18cc, is taken when v0(=[a0+80]) == 0, and falls through when v0(=[a0+80]) != 0.
  The `beq` branch at 0x1848 targets 0x18dc, is taken when v0(=[a0+80]) == v1(=0x1), and falls through when v0(=[a0+80]) != v1(=0x1).
  The `beq` branch at 0x1858 targets 0x1868 and is always taken.
  The `beq` branch at 0x1860 targets 0x1898, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `beq` branch at 0x1878 targets 0x18ac, is taken when v0(=[a0+80]) == 0, and falls through when v0(=[a0+80]) != 0.
  The `beq` branch at 0x1880 targets 0x18bc, is taken when v0(=[a0+80]) == a0(=0x1), and falls through when v0(=[a0+80]) != a0(=0x1).
  The `beq` branch at 0x1890 targets 0x1860, is taken when (s2(=0xffffffffe0000000) & v0(?)) == 0, and falls through when (s2(=0xffffffffe0000000) & v0(?)) != 0.
  The `beq` branch at 0x18b4 targets 0x1888 and is always taken.
  The `beq` branch at 0x18c4 targets 0x1888 and is always taken.
  The `beq` branch at 0x18d4 targets 0x1850 and is always taken.
  The `beq` branch at 0x18e4 targets 0x1850 and is always taken.
  The return at 0x18a4 has v0 = ?.

- `ioc3_pckm_kbdexists` in `IP30/usr/cpu/sysgen/IP30boot/ioc3_pckm.o` at 0x18ec (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/ioc3_pckm.o`.
  Range: 0x18ec-0x1928 (60 bytes).
  It occupies 60 bytes.
  The `lw` at 0x18f8 loads 4 bytes from [sym(.sbss)]:8 +0x28.
  The `ld` at 0x1908 loads 8 bytes from ([sym(.sbss)]:8 + ([[sym(.sbss)]:8+40] << 0x3)) +0x18.
  The `lw` at 0x190c loads 4 bytes from [([sym(.sbss)]:8 + ([[sym(.sbss)]:8+40] << 0x3))+24]:8 +0x4.
  The `beq` branch at 0x18f0 targets 0x1920, is taken when a2(=[sym(.sbss)]:8) == 0, and falls through when a2(=[sym(.sbss)]:8) != 0.
  The `beq` branch at 0x18fc targets 0x1920, is taken when a3(=[[sym(.sbss)]:8+40]) == v0(=0x13), and falls through when a3(=[[sym(.sbss)]:8+40]) != v0(=0x13).
  The return at 0x1918 has v0 = ?.
  The return at 0x1920 has v0 = 0x0.

- `ioc3_pckm_setleds` in `IP30/usr/cpu/sysgen/IP30boot/ioc3_pckm.o` at 0x1928 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/ioc3_pckm.o`.
  Range: 0x1928-0x1964 (60 bytes).
  It occupies 60 bytes.
  The `lw` at 0x1940 loads 4 bytes from [sym(.sbss)]:8 +0x28.
  The `ld` at 0x1954 loads 8 bytes from ([sym(.sbss)]:8 + ([[sym(.sbss)]:8+40] << 0x3)) +0x18.
  The `jal` at 0x1950 calls ioc3_lcl_pckm_setleds with a0=[([sym(.sbss)]:8 + ([[sym(.sbss)]:8+40] << 0x3))+24]:8, a1=a0 at entry (arg0), a2=a2 at entry (arg2), a3=[sym(.sbss)]:8, a4=0x13, a5=[[sym(.sbss)]:8+40].
  The `beq` branch at 0x1938 targets 0x1958, is taken when a3(=[sym(.sbss)]:8) == 0, and falls through when a3(=[sym(.sbss)]:8) != 0.
  The `beq` branch at 0x1944 targets 0x1958, is taken when a5(=[[sym(.sbss)]:8+40]) == a4(=0x13), and falls through when a5(=[[sym(.sbss)]:8+40]) != a4(=0x13).
  The return at 0x195c has v0 = one of ?, ret(ioc3_lcl_pckm_setleds).

- `ioc3_pckm_bell` in `IP30/usr/cpu/sysgen/IP30boot/ioc3_pckm.o` at 0x1964 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/ioc3_pckm.o`.
  Range: 0x1964-0x19a8 (68 bytes).
  It occupies 68 bytes.
  The `lw` at 0x1978 loads 4 bytes from [sym(.sbss)]:8 +0x28.
  The `lw` at 0x1984 loads 4 bytes from [sym(.sbss)]:8 +0x34.
  The `ld` at 0x1998 loads 8 bytes from ([sym(.sbss)]:8 + ([[sym(.sbss)]:8+40] << 0x3)) +0x18.
  The `jal` at 0x1994 calls ioc3_lcl_pckm_setleds with a0=[([sym(.sbss)]:8 + ([[sym(.sbss)]:8+40] << 0x3))+24]:8, a1=([[sym(.sbss)]:8+52] | 0x8), a2=a2 at entry (arg2), a3=[sym(.sbss)]:8, a4=[[sym(.sbss)]:8+40].
  The `beq` branch at 0x1970 targets 0x199c, is taken when a3(=[sym(.sbss)]:8) == 0, and falls through when a3(=[sym(.sbss)]:8) != 0.
  The `beq` branch at 0x197c targets 0x19a0, is taken when a4(=[[sym(.sbss)]:8+40]) == a1(=0x13), and falls through when a4(=[[sym(.sbss)]:8+40]) != a1(=0x13).
  The return at 0x19a0 has v0 = ?.

- `ioc3_gl_setporthandler` in `IP30/usr/cpu/sysgen/IP30boot/ioc3_pckm.o` at 0x19a8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/ioc3_pckm.o`.
  Range: 0x19a8-0x19d4 (44 bytes).
  It occupies 44 bytes.
  The `lw` at 0x19b4 loads 4 bytes from [sym(.sbss)]:8 +0x28.
  The `ld` at 0x19c4 loads 8 bytes from ([sym(.sbss)]:8 + ([[sym(.sbss)]:8+40] << 0x3)) +0x18.
  The `sd` at 0x19c8 stores 8 bytes to [([sym(.sbss)]:8 + ([[sym(.sbss)]:8+40] << 0x3))+24]:8 +0x18.
  The `beq` branch at 0x19ac targets 0x19cc, is taken when a2(=[sym(.sbss)]:8) == 0, and falls through when a2(=[sym(.sbss)]:8) != 0.
  The `beq` branch at 0x19b8 targets 0x19cc, is taken when a4(=[[sym(.sbss)]:8+40]) == a3(=0x13), and falls through when a4(=[[sym(.sbss)]:8+40]) != a3(=0x13).
  The return at 0x19cc has v0 = ?.

- `ioc3_du_keyboard_port` in `IP30/usr/cpu/sysgen/IP30boot/ioc3_pckm.o` at 0x19d4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/ioc3_pckm.o`.
  Range: 0x19d4-0x19dc (8 bytes).
  It occupies 8 bytes.
  The return at 0x19d4 has v0 = -0x1.

- `ioc3_lcl_pckm_setleds` in `IP30/usr/cpu/sysgen/IP30boot/ioc3_pckm.o` at 0x19dc (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/ioc3_pckm.o`.
  Range: 0x19dc-0x1a30 (84 bytes).
  It occupies 84 bytes.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x48, including `ld` at 0x19e8, `ld` at 0x1a10.
  The `jal` at 0x19fc calls mutex_lock with a0=[a0+72]:8+72, a1=0x19, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1a08 calls ioc3_lcl_pckm_setleds_lock with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0x1a18 calls mutex_unlock with a0=[a0+72]:8+72, a1=?, a2=?, a3=?.
  The return at 0x1a28 has v0 = ret(mutex_unlock).

- `ioc3_lcl_pckm_setleds_lock` in `IP30/usr/cpu/sysgen/IP30boot/ioc3_pckm.o` at 0x1a30 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/ioc3_pckm.o`.
  Range: 0x1a30-0x1ba8 (376 bytes).
  It occupies 376 bytes.
  The `ld` at 0x1a3c loads 8 bytes from a0 (arg0 at entry) +0x48.
  5 such `lw` accesses load 4 bytes from [a0+72]:8 +0x34, including `lw` at 0x1a44, `lw` at 0x1ab8, `lw` at 0x1ad8.
  The `lw` at 0x1a74 loads 4 bytes from [a0+72]:8 +0x38.
  The `sw` at 0x1aa0 stores 4 bytes to [a0+72]:8 +0x38.
  2 such `sw` accesses store 4 bytes to [a0+72]:8 +0x34, including `sw` at 0x1aac, `sw` at 0x1ae0.
  The `jal` at 0x1ab4 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=[[a0+72]:8+52], a2=?, a3=?.
  The `jal` at 0x1ac0 calls data_check with a0=ret(pckm_pollcmd), a1=0xfa, a2=?, a3=?.
  The `jal` at 0x1b0c calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xed, a2=?, a3=?.
  The `jal` at 0x1b18 calls data_check with a0=ret(pckm_pollcmd), a1=0xfa, a2=?, a3=?.
  The `jal` at 0x1b38 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xf4, a2=?, a3=?.
  The `jal` at 0x1b44 calls data_check with a0=ret(pckm_pollcmd), a1=0xfa, a2=?, a3=?.
  The `jal` at 0x1b5c calls default_kbd_setting with a0=a0 at entry (arg0), a1=0x0, a2=[[a0+72]:8+52], a3=?.
  The `jal` at 0x1b7c calls pckm_pollcmd with a0=a0 at entry (arg0), a1=[[a0+72]:8+52], a2=?, a3=?.
  The `jal` at 0x1b88 calls data_check with a0=ret(pckm_pollcmd), a1=0xfa, a2=?, a3=?.
  The `jal` at 0x1b98 calls pckm_reinit_core with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `beq` branch at 0x1a64 targets 0x1ae4, is taken when at(=[[a0+72]:8+52]) == a3(?), and falls through when at(=[[a0+72]:8+52]) != a3(?).
  The `beq` branch at 0x1a6c targets 0x1aa8, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `beq` branch at 0x1a80 targets 0x1a90, is taken when a7(?) >= 0xe (signed), and falls through when a7(?) < 0xe (signed).
  The `bne` branch at 0x1a88 targets 0x1ae8, is taken when a4(?) != 0, and falls through when a4(?) == 0.
  The `beq` branch at 0x1a90 targets 0x1aa0, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `bne` branch at 0x1a98 targets 0x1ae8, is taken when a5(?) != 0, and falls through when a5(?) == 0.
  The `beq` branch at 0x1aa8 targets 0x1b08 and is always taken.
  The `beq` branch at 0x1ac8 targets 0x1b7c, is taken when v0(=ret(data_check)) == 0, and falls through when v0(=ret(data_check)) != 0.
  The `beq` branch at 0x1ad0 targets 0x1ae8, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `beq` branch at 0x1b04 targets 0x1b6c, is taken when t1(?) == 0, and falls through when t1(?) != 0.
  The `bne` branch at 0x1b20 targets 0x1ab0, is taken when v0(=ret(data_check)) != 0, and falls through when v0(=ret(data_check)) == 0.
  The `bne` branch at 0x1b2c targets 0x1b00, is taken when s3(?) < 0x2 (unsigned), and falls through when s3(?) >= 0x2 (unsigned).
  The `bne` branch at 0x1b4c targets 0x1b04, is taken when v0(=ret(data_check)) != 0, and falls through when v0(=ret(data_check)) == 0.
  The `beq` branch at 0x1b64 targets 0x1b04 and is always taken.
  The `bne` branch at 0x1b6c targets 0x1ad8, is taken when s2(?) != 0, and falls through when s2(?) == 0.
  The `beq` branch at 0x1b74 targets 0x1ae8 and is always taken.
  The `bne` branch at 0x1b90 targets 0x1ad0, is taken when v0(=ret(data_check)) != 0, and falls through when v0(=ret(data_check)) == 0.
  The `beq` branch at 0x1ba0 targets 0x1ad0 and is always taken.
  The return at 0x1af8 has v0 = ?.

- `pckm_sendok` in `IP30/usr/cpu/sysgen/IP30boot/ioc3_pckm.o` at 0x1ba8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/ioc3_pckm.o`.
  Range: 0x1ba8-0x1c34 (140 bytes).
  It occupies 140 bytes.
  The `lw` at 0x1bb4 loads 4 bytes from a0 (arg0 at entry) +0x50.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x48, including `ld` at 0x1bb8, `ld` at 0x1bf0.
  2 such `ld` accesses load 8 bytes from [a0+72]:8 +0x10, including `ld` at 0x1bcc, `ld` at 0x1bf4.
  2 such `lw` accesses load 4 bytes from [[a0+72]:8+16]:8 +0x9c, including `lw` at 0x1be4, `lw` at 0x1bfc.
  The `jal` at 0x1be8 calls us_delay with a0=0x32, a1=?, a2=[[[a0+72]:8+16]:8+156], a3=?.
  The `beq` branch at 0x1be0 targets 0x1c28 and is always taken.
  The `beq` branch at 0x1c04 targets 0x1c14, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `bne` branch at 0x1c0c targets 0x1be8, is taken when s0(?) != 0, and falls through when s0(?) == 0.
  The `beq` branch at 0x1c2c targets 0x1c04 and is always taken.
  The return at 0x1c20 has v0 = ?.

- `pckm_flushinp` in `IP30/usr/cpu/sysgen/IP30boot/ioc3_pckm.o` at 0x1c34 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/ioc3_pckm.o`.
  Range: 0x1c34-0x1c70 (60 bytes).
  It occupies 60 bytes.
  The `lw` at 0x1c34 loads 4 bytes from a0 (arg0 at entry) +0x50.
  The `lw` at 0x1c4c loads 4 bytes from ?.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x48, including `ld` at 0x1c50, `ld` at 0x1c60.
  2 such `ld` accesses load 8 bytes from [a0+72]:8 +0x10, including `ld` at 0x1c54, `ld` at 0x1c64.
  The `beq` branch at 0x1c38 targets 0x1c60, is taken when a2(=[a0+80]) == 0, and falls through when a2(=[a0+80]) != 0.
  The `beq` branch at 0x1c40 targets 0x1c50, is taken when a2(=[a0+80]) == a3(=0x1), and falls through when a2(=[a0+80]) != a3(=0x1).
  The `beq` branch at 0x1c58 targets 0x1c48 and is always taken.
  The `beq` branch at 0x1c68 targets 0x1c48 and is always taken.
  The return at 0x1c48 has v0 = ?.

- `data_check` in `IP30/usr/cpu/sysgen/IP30boot/ioc3_pckm.o` at 0x1c70 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/ioc3_pckm.o`.
  Range: 0x1c70-0x1ce8 (120 bytes).
  It occupies 120 bytes.
  The `lw` at 0x1c74 loads 4 bytes from sym(.rodata) +0x0.
  The `lw` at 0x1c9c loads 4 bytes from sym(.rodata) +0x10.
  The `lw` at 0x1ca0 loads 4 bytes from sym(.rodata) +0xc.
  The `lw` at 0x1cb0 loads 4 bytes from sym(.rodata) +0x4.
  The `lw` at 0x1cb4 loads 4 bytes from sym(.rodata) +0x8.
  The `beq` branch at 0x1c78 targets 0x1ce0 and is never taken: its condition can never hold for these operands, so execution always falls through.
  The `beq` branch at 0x1c80 targets 0x1c98 and is always taken.
  The `beq` branch at 0x1c88 targets 0x1cd0 and is never taken: its condition can never hold for these operands, so execution always falls through.
  The `bne` branch at 0x1c90 targets 0x1cd4, is taken when a5(?) != 0, and falls through when a5(?) == 0.
  The `beq` branch at 0x1c98 targets 0x1c88, is taken when at(?) == 0, and falls through when at(?) != 0.
  The `bne` branch at 0x1ca8 targets 0x1c88, is taken when (v1(=0x4000000) & a0) != 0, and falls through when (v1(=0x4000000) & a0) == 0.
  The `bne` branch at 0x1cc0 targets 0x1c88, is taken when a1 != a2(?), and falls through when a1 == a2(?).
  The `beq` branch at 0x1cc8 targets 0x1c88 and is always taken.
  The return at 0x1cd8 has v0 = 0x1.
  The instructions from 0x1cd0 to 0x1cd0 are not reached by any path from the entry, and their branches are not listed.
  The instructions from 0x1ce0 to 0x1ce4 are not reached by any path from the entry, and their branches are not listed.

- `valid_data` in `IP30/usr/cpu/sysgen/IP30boot/ioc3_pckm.o` at 0x1ce8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/ioc3_pckm.o`.
  Range: 0x1ce8-0x1e84 (412 bytes).
  It occupies 412 bytes.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x50, including `lw` at 0x1d00, `lw` at 0x1ddc.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0x1d28, `lw` at 0x1d78.
  2 such `lw` accesses load 4 bytes from sym(.rodata) +0x0, including `lw` at 0x1d4c, `lw` at 0x1d94.
  2 such `lw` accesses load 4 bytes from sym(.rodata) +0x10, including `lw` at 0x1d58, `lw` at 0x1e14.
  The `lw` at 0x1da4 loads 4 bytes from sym(.rodata) +0xc.
  The `lw` at 0x1da8 loads 4 bytes from a0 (arg0 at entry) +0x4.
  The `lw` at 0x1de8 loads 4 bytes from sym(.rodata) +0x4.
  The `ld` at 0x1dec loads 8 bytes from abs 0xffffffffffffc488.
  The `lw` at 0x1df0 loads 4 bytes from sym(.rodata) +0x8.
  The `lw` at 0x1df8 loads 4 bytes from [-0x3b78]:8 +0xa0.
  The `sw` at 0x1e0c stores 4 bytes to [-0x3b78]:8 +0xa0.
  4 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x48, including `ld` at 0x1e18, `ld` at 0x1e54, `ld` at 0x1e64.
  4 such `ld` accesses load 8 bytes from [a0+72]:8 +0x10, including `ld` at 0x1e1c, `ld` at 0x1e58, `ld` at 0x1e68.
  The `jal` at 0x1d50 calls pckm_restart with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x1dc4 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xfe, a2=?, a3=?.
  The `jal` at 0x1e08 calls pckm_rx with a0=a0 at entry (arg0), a1=?, a2=0x10, a3=[[-0x3b78]:8+160]+1, a4=[-0x3b78]:8.
  The `beq` branch at 0x1d10 targets 0x1e64, is taken when a2(=[a0+80]) == 0, and falls through when a2(=[a0+80]) != 0.
  The `beq` branch at 0x1d1c targets 0x1e74, is taken when a2(=[a0+80]) == at(=0x1), and falls through when a2(=[a0+80]) != at(=0x1).
  The `beq` branch at 0x1d2c targets 0x1e28, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `beq` branch at 0x1d3c targets 0x1e28, is taken when (s6(=0xffffffffe0000000) & s1(?)) == 0, and falls through when (s6(=0xffffffffe0000000) & s1(?)) != 0.
  The `beq` branch at 0x1d48 targets 0x1d88 and is always taken.
  The `bne` branch at 0x1d5c targets 0x1d94 and is always taken.
  The `beq` branch at 0x1d68 targets 0x1e18, is taken when a2(=[a0+80]) == 0, and falls through when a2(=[a0+80]) != 0.
  The `beq` branch at 0x1d70 targets 0x1e54, is taken when a2(=[a0+80]) == s7(=0x1), and falls through when a2(=[a0+80]) != s7(=0x1).
  The `beq` branch at 0x1d7c targets 0x1e28, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `beq` branch at 0x1d84 targets 0x1e28, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x1d8c targets 0x1d64 and is never taken: its condition can never hold for these operands, so execution always falls through.
  The `beq` branch at 0x1d9c targets 0x1d58, is taken when (a1(=0xffffffff80000000) & s1(?)) == 0, and falls through when (a1(=0xffffffff80000000) & s1(?)) != 0.
  The `beq` branch at 0x1db0 targets 0x1de0, is taken when (a1(=0x4000000) & s1(?)) == 0, and falls through when (a1(=0x4000000) & s1(?)) != 0.
  The `beq` branch at 0x1db8 targets 0x1d50, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `bne` branch at 0x1dd0 targets 0x1d8c, is taken when s3(?) < 0x3 (unsigned), and falls through when s3(?) >= 0x3 (unsigned).
  The `beq` branch at 0x1dd8 targets 0x1d68 and is always taken.
  The `beq` branch at 0x1de0 targets 0x1d50, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x1e10 targets 0x1d5c and is always taken.
  The `beq` branch at 0x1e20 targets 0x1d78 and is always taken.
  The `beq` branch at 0x1e5c targets 0x1d78 and is always taken.
  The `beq` branch at 0x1e6c targets 0x1d28 and is always taken.
  The `beq` branch at 0x1e7c targets 0x1d28 and is always taken.
  The return at 0x1e4c has v0 = one of ?, ret(pckm_pollcmd).
  The instructions from 0x1d64 to 0x1d64 are not reached by any path from the entry, and their branches are not listed.

- `set_ports` in `IP30/usr/cpu/sysgen/IP30boot/ioc3_pckm.o` at 0x1e84 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/ioc3_pckm.o`.
  Range: 0x1e84-0x1fe4 (352 bytes).
  It occupies 352 bytes.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x30, including `sw` at 0x1ea8, `sw` at 0x1fb0.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x28, including `sw` at 0x1eb4, `sw` at 0x1efc.
  The `ld` at 0x1eb8 loads 8 bytes from a0 (arg0 at entry) +0x20.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x2c, including `sw` at 0x1ebc, `sw` at 0x1f64.
  The `sw` at 0x1ec4 stores 4 bytes to [a0+32]:8 +0x50.
  The `ld` at 0x1ed0 loads 8 bytes from a0 (arg0 at entry) +0x18.
  The `sw` at 0x1ee8 stores 4 bytes to [a0+24]:8 +0x50.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x28, including `lw` at 0x1eec, `lw` at 0x1f74.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x58, including `sw` at 0x1ef8, `sw` at 0x1fc8.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0x1f00, `ld` at 0x1f24.
  The `sw` at 0x1f04 stores 4 bytes to ?.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x2c, including `lw` at 0x1f50, `lw` at 0x1f8c.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x5c, including `sw` at 0x1f5c, `sw` at 0x1fe0.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x0, including `lw` at 0x1fb8, `lw` at 0x1fd0.
  The `jal` at 0x1f20 calls check_port with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1fbc calls cmn_err with a0=0x1, a1=sym(.rodata), a2=[a0], a3=?.
  The `jal` at 0x1fd4 calls cmn_err with a0=0x1, a1=sym(.rodata), a2=[a0], a3=?.
  The `beq` branch at 0x1ee4 targets 0x1f14 and is always taken.
  The `bne` branch at 0x1ef0 targets 0x1fb4, is taken when v1(=[a0+40]) != s5(=0x13), and falls through when v1(=[a0+40]) == s5(=0x13).
  The `beq` branch at 0x1f10 targets 0x1f68, is taken when s1(?) >= 0x2 (signed), and falls through when s1(?) < 0x2 (signed).
  The `beq` branch at 0x1f28 targets 0x1eec, is taken when v0(=ret(check_port)) == s4(=0x47), and falls through when v0(=ret(check_port)) != s4(=0x47).
  The `beq` branch at 0x1f30 targets 0x1eec, is taken when v0(=ret(check_port)) == s6(=0x83), and falls through when v0(=ret(check_port)) != s6(=0x83).
  The `beq` branch at 0x1f38 targets 0x1f50, is taken when v0(=ret(check_port)) == 0, and falls through when v0(=ret(check_port)) != 0.
  The `beq` branch at 0x1f40 targets 0x1f50, is taken when v0(=ret(check_port)) == s7(=0x3), and falls through when v0(=ret(check_port)) != s7(=0x3).
  The `bne` branch at 0x1f48 targets 0x1f00, is taken when v0(=ret(check_port)) != s8(=0x4), and falls through when v0(=ret(check_port)) == s8(=0x4).
  The `bne` branch at 0x1f54 targets 0x1fcc, is taken when t8(=[a0+44]) != s5(=0x13), and falls through when t8(=[a0+44]) == s5(=0x13).
  The `beq` branch at 0x1f60 targets 0x1f00 and is always taken.
  The `bne` branch at 0x1f84 targets 0x1f94, is taken when t9(=[a0+40]) != s5(=0x13), and falls through when t9(=[a0+40]) == s5(=0x13).
  The `beq` branch at 0x1f90 targets 0x1fac, is taken when ra(=[a0+44]) == s5(=0x13), and falls through when ra(=[a0+44]) != s5(=0x13).
  The `beq` branch at 0x1fac targets 0x1f94 and is always taken.
  The `beq` branch at 0x1fc4 targets 0x1efc and is always taken.
  The `beq` branch at 0x1fdc targets 0x1f60 and is always taken.
  The return at 0x1fa4 has v0 = 0x1.

- `check_port` in `IP30/usr/cpu/sysgen/IP30boot/ioc3_pckm.o` at 0x1fe4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/ioc3_pckm.o`.
  Range: 0x1fe4-0x2320 (828 bytes).
  It occupies 828 bytes.
  The `sw` at 0x1fe4 stores 4 bytes to a0 (arg0 at entry) +0x50.
  The `lw` at 0x2044 loads 4 bytes from sym(.rodata) +0x0.
  The `lw` at 0x2074 loads 4 bytes from sym(.rodata) +0x10.
  The `lw` at 0x2080 loads 4 bytes from sym(.rodata) +0xc.
  The `lw` at 0x209c loads 4 bytes from sym(.rodata) +0x20.
  The `lw` at 0x20a0 loads 4 bytes from sym(.rodata) +0x1c.
  The `lw` at 0x20b8 loads 4 bytes from sym(.rodata) +0x14.
  The `lw` at 0x20bc loads 4 bytes from sym(.rodata) +0x18.
  The `lw` at 0x2174 loads 4 bytes from sym(.rodata) +0x4.
  The `lw` at 0x2178 loads 4 bytes from sym(.rodata) +0x8.
  The `jal` at 0x1ffc calls pckm_flushinp with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x2020 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xf2, a2=?, a3=?.
  The `beq` branch at 0x204c targets 0x20fc and is never taken: its condition can never hold for these operands, so execution always falls through.
  The `beq` branch at 0x2054 targets 0x2070 and is always taken.
  The `beq` branch at 0x205c targets 0x2068, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `beq` branch at 0x2068 targets 0x20fc and is never taken: its condition can never hold for these operands, so execution always falls through.
  The `beq` branch at 0x2078 targets 0x2090, is taken when (a4(=one of 0xffffffff80000000, 0x20000000) & a5(=ret(pckm_pollcmd))) == 0, and falls through when (a4(=one of 0xffffffff80000000, 0x20000000) & a5(=ret(pckm_pollcmd))) != 0.
  The `beq` branch at 0x2088 targets 0x216c, is taken when (v1(=0x4000000) & a5(=ret(pckm_pollcmd))) == 0, and falls through when (v1(=0x4000000) & a5(=ret(pckm_pollcmd))) != 0.
  The `beq` branch at 0x2090 targets 0x20fc and is never taken: its condition can never hold for these operands, so execution always falls through.
  The `beq` branch at 0x2098 targets 0x2068, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `bne` branch at 0x20a8 targets 0x2068, is taken when (a0(=0x2000000) & a5(=ret(pckm_pollcmd))) != 0, and falls through when (a0(=0x2000000) & a5(=ret(pckm_pollcmd))) == 0.
  The `bne` branch at 0x20b0 targets 0x2068, is taken when s0(?) != s5(=0x13), and falls through when s0(?) == s5(=0x13).
  The `bne` branch at 0x20e4 targets 0x2214, is taken when a6(?) < 0x53 (unsigned), and falls through when a6(?) >= 0x53 (unsigned).
  The `beq` branch at 0x20ec targets 0x225c, is taken when t0(?) == 0, and falls through when t0(?) != 0.
  The `beq` branch at 0x20f4 targets 0x205c and is always taken.
  The `bne` branch at 0x216c targets 0x2090, is taken when s0(?) != s5(=0x13), and falls through when s0(?) == s5(=0x13).
  The `bne` branch at 0x219c targets 0x21fc, is taken when a6(?) < 0x53 (unsigned), and falls through when a6(?) >= 0x53 (unsigned).
  The `beq` branch at 0x21a4 targets 0x222c, is taken when t1(?) == 0, and falls through when t1(?) != 0.
  The `beq` branch at 0x21ac targets 0x2090, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `beq` branch at 0x21b4 targets 0x2090 and is always taken.
  The `bne` branch at 0x21fc targets 0x2244, is taken when t0(?) != 0, and falls through when t0(?) == 0.
  The `beq` branch at 0x2204 targets 0x22a4, is taken when t2(?) == 0, and falls through when t2(?) != 0.
  The `beq` branch at 0x220c targets 0x2090 and is always taken.
  The `bne` branch at 0x2214 targets 0x2274, is taken when v0(?) != 0, and falls through when v0(?) == 0.
  The `beq` branch at 0x221c targets 0x22e0, is taken when t2(?) == 0, and falls through when t2(?) != 0.
  The `beq` branch at 0x2224 targets 0x2068 and is always taken.
  The `bne` branch at 0x222c targets 0x228c, is taken when t8(?) != 0, and falls through when t8(?) == 0.
  The `beq` branch at 0x2234 targets 0x2300, is taken when t9(?) == 0, and falls through when t9(?) != 0.
  The `beq` branch at 0x223c targets 0x2090 and is always taken.
  The `bne` branch at 0x2244 targets 0x22b4, is taken when t3(?) != 0, and falls through when t3(?) == 0.
  The `beq` branch at 0x2254 targets 0x2090 and is always taken.
  The `bne` branch at 0x225c targets 0x22c4, is taken when t3(?) != 0, and falls through when t3(?) == 0.
  The `beq` branch at 0x2264 targets 0x2310, is taken when t9(?) == 0, and falls through when t9(?) != 0.
  The `beq` branch at 0x226c targets 0x2068 and is always taken.
  The `bne` branch at 0x2274 targets 0x22f0, is taken when t1(?) != 0, and falls through when t1(?) == 0.
  The `beq` branch at 0x2284 targets 0x2068 and is always taken.
  The `bne` branch at 0x228c targets 0x2090, is taken when t2(=0x83) != a6(?), and falls through when t2(=0x83) == a6(?).
  The `beq` branch at 0x2294 targets 0x2090, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `beq` branch at 0x229c targets 0x2090 and is always taken.
  The `bne` branch at 0x22a4 targets 0x2090, is taken when t8(=0x47) != a6(?), and falls through when t8(=0x47) == a6(?).
  The `beq` branch at 0x22ac targets 0x2090 and is always taken.
  The `bne` branch at 0x22b4 targets 0x2090, is taken when a6(?) != 0, and falls through when a6(?) == 0.
  The `beq` branch at 0x22bc targets 0x2090 and is always taken.
  The `bne` branch at 0x22c8 targets 0x2068, is taken when t9(=0x83) != a6(?), and falls through when t9(=0x83) == a6(?).
  The `beq` branch at 0x22d0 targets 0x2068, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `beq` branch at 0x22d8 targets 0x2068 and is always taken.
  The `bne` branch at 0x22e0 targets 0x2068, is taken when at(=0x47) != a6(?), and falls through when at(=0x47) == a6(?).
  The `beq` branch at 0x22e8 targets 0x2068 and is always taken.
  The `bne` branch at 0x22f0 targets 0x2068, is taken when a6(?) != 0, and falls through when a6(?) == 0.
  The `beq` branch at 0x22f8 targets 0x2068 and is always taken.
  The `bne` branch at 0x2300 targets 0x2090, is taken when v1(=0xfa) != a6(?), and falls through when v1(=0xfa) == a6(?).
  The `beq` branch at 0x2308 targets 0x2090 and is always taken.
  The `bne` branch at 0x2310 targets 0x2068, is taken when a0(=0xfa) != a6(?), and falls through when a0(=0xfa) == a6(?).
  The `beq` branch at 0x2318 targets 0x2068 and is always taken.
  The instructions from 0x20fc to 0x2168 are not reached by any path from the entry, and their branches are not listed.
  The instructions from 0x21bc to 0x21f8 are not reached by any path from the entry, and their branches are not listed.

- `pckm_restart` in `IP30/usr/cpu/sysgen/IP30boot/ioc3_pckm.o` at 0x2320 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/ioc3_pckm.o`.
  Range: 0x2320-0x25b4 (660 bytes).
  It occupies 660 bytes.
  9 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x50, including `lw` at 0x2320, `lw` at 0x236c, `lw` at 0x2398.
  13 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x48, including `ld` at 0x2330, `ld` at 0x2370, `ld` at 0x2388.
  2 such `ld` accesses load 8 bytes from ([a0+72]:8 + ([a0+80] << 0x3)) +0x18, including `ld` at 0x2348, `ld` at 0x237c.
  The `sw` at 0x2380 stores 4 bytes to [([a0+72]:8 + ([a0+80] << 0x3))+24]:8 +0x50.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x4, including `lw` at 0x2384, `lw` at 0x23dc, `lw` at 0x2480.
  3 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x4, including `sw` at 0x2390, `sw` at 0x23ec, `sw` at 0x24a0.
  2 such `lw` accesses load 4 bytes from [a0+72]:8 +0x28, including `lw` at 0x2394, `lw` at 0x2438.
  2 such `lw` accesses load 4 bytes from [a0+72]:8 +0x2c, including `lw` at 0x23a4, `lw` at 0x24c0.
  The `lw` at 0x23bc loads 4 bytes from [a0+72]:8 +0x5c.
  3 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x8, including `sw` at 0x23d4, `sw` at 0x2498, `sw` at 0x24f8.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0xc, including `sw` at 0x23e4, `sw` at 0x248c.
  2 such `ld` accesses load 8 bytes from [a0+72]:8 +0x10, including `ld` at 0x23f0, `ld` at 0x2414.
  2 such `lw` accesses load 4 bytes from [[a0+72]:8+16]:8 +0x9c, including `lw` at 0x2400, `lw` at 0x2418.
  2 such `sw` accesses store 4 bytes to [[a0+72]:8+16]:8 +0x9c, including `sw` at 0x240c, `sw` at 0x241c.
  2 such `lw` accesses load 4 bytes from [a0+72]:8 +0x30, including `lw` at 0x2448, `lw` at 0x24d0.
  The `sw` at 0x2460 stores 4 bytes to [a0+72]:8 +0x28.
  The `sw` at 0x246c stores 4 bytes to [a0+72]:8 +0x58.
  The `lw` at 0x247c loads 4 bytes from [a0+72]:8 +0x34.
  The `sw` at 0x24f0 stores 4 bytes to [a0+72]:8 +0x2c.
  2 such `lw` accesses load 4 bytes from [a0+72]:8 +0x0, including `lw` at 0x2500, `lw` at 0x2548.
  2 such `ld` accesses load 8 bytes from [a0+72]:8 +0x18, including `ld` at 0x251c, `ld` at 0x2564.
  2 such `lw` accesses load 4 bytes from [[a0+72]:8+24]:8 +0x4, including `lw` at 0x2520, `lw` at 0x2568.
  2 such `sw` accesses store 4 bytes to [[a0+72]:8+24]:8 +0x4, including `sw` at 0x2528, `sw` at 0x2570.
  2 such `ld` accesses load 8 bytes from [a0+72]:8 +0x20, including `ld` at 0x258c, `ld` at 0x25a0.
  2 such `lw` accesses load 4 bytes from [[a0+72]:8+32]:8 +0x4, including `lw` at 0x2590, `lw` at 0x25a4.
  2 such `sw` accesses store 4 bytes to [[a0+72]:8+32]:8 +0x4, including `sw` at 0x259c, `sw` at 0x25b0.
  The `jal` at 0x2344 calls check_port with a0=[([a0+72]:8 + ([a0+80] << 0x3))+24]:8, a1=[a0+80], a2=([a0+80] << 0x3), a3=a3 at entry (arg3).
  The `jal` at 0x23b0 calls default_ms_setting with a0=a0 at entry (arg0), a1=?, a2=?, a3=?, a5=[a0+72]:8.
  The `jal` at 0x2478 calls default_kbd_setting with a0=a0 at entry (arg0), a1=0x0, a2=[[a0+72]:8+52], a3=?, a5=[a0+72]:8, a6=[[a0+72]:8+40], a7=([a0+4] | 0x20).
  The `jal` at 0x24a8 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xf8, a2=?, a3=?.
  The `jal` at 0x2504 calls cmn_err with a0=0x1, a1=sym(.rodata), a2=[[a0+72]:8], a3=0x47, a4=[[a0+72]:8+40], a5=[a0+72]:8, a6=0x13.
  The `jal` at 0x2534 calls cmn_err with a0=0x1, a1=sym(.rodata), a2=?, a3=?, a4=sym(.rodata), a5=[a0+72]:8, a7=[[a0+72]:8+48].
  The `jal` at 0x254c calls cmn_err with a0=0x1, a1=sym(.rodata), a2=[[a0+72]:8], a3=0x47, a4=0x83, a5=[a0+72]:8.
  The `jal` at 0x257c calls cmn_err with a0=0x1, a1=sym(.rodata), a2=?, a3=?, a4=sym(.rodata), a5=[a0+72]:8.
  The `beq` branch at 0x2350 targets 0x2434, is taken when v0(=ret(check_port)) == a3(=0x47), and falls through when v0(=ret(check_port)) != a3(=0x47).
  The `beq` branch at 0x235c targets 0x2434, is taken when v0(=ret(check_port)) == a4(=0x83), and falls through when v0(=ret(check_port)) != a4(=0x83).
  The `beq` branch at 0x2364 targets 0x24bc, is taken when v0(=ret(check_port)) == 0, and falls through when v0(=ret(check_port)) != 0.
  The `beq` branch at 0x239c targets 0x2470, is taken when a6(=[[a0+72]:8+40]) == a0(=[a0+80]), and falls through when a6(=[[a0+72]:8+40]) != a0(=[a0+80]).
  The `bne` branch at 0x23a8 targets 0x23f0, is taken when t3(=[[a0+72]:8+44]) != a0(=[a0+80]), and falls through when t3(=[[a0+72]:8+44]) == a0(=[a0+80]).
  The `beq` branch at 0x23c4 targets 0x24f4, is taken when v0(=[[a0+72]:8+92]) == a3(=0x3), and falls through when v0(=[[a0+72]:8+92]) != a3(=0x3).
  The `beq` branch at 0x23cc targets 0x24f4, is taken when v0(=[[a0+72]:8+92]) == a0(=0x4), and falls through when v0(=[[a0+72]:8+92]) != a0(=0x4).
  The `bne` branch at 0x2440 targets 0x24fc, is taken when a4(=[[a0+72]:8+40]) != a6(=0x13), and falls through when a4(=[[a0+72]:8+40]) == a6(=0x13).
  The `beq` branch at 0x2450 targets 0x2460, is taken when a7(=[[a0+72]:8+48]) == 0, and falls through when a7(=[[a0+72]:8+48]) != 0.
  The `bne` branch at 0x2458 targets 0x2534, is taken when a0(=[a0+80]) != 0, and falls through when a0(=[a0+80]) == 0.
  The `beq` branch at 0x2468 targets 0x236c and is always taken.
  The `beq` branch at 0x249c targets 0x24b0, is taken when (t1(=([a0+4] | 0x1)) & 0x2) == 0, and falls through when (t1(=([a0+4] | 0x1)) & 0x2) != 0.
  The `beq` branch at 0x24b4 targets 0x23a4 and is always taken.
  The `bne` branch at 0x24c8 targets 0x2544, is taken when t2(=[[a0+72]:8+44]) != t3(=0x13), and falls through when t2(=[[a0+72]:8+44]) == t3(=0x13).
  The `beq` branch at 0x24dc targets 0x24ec, is taken when t8(=[[a0+72]:8+48]) == 0, and falls through when t8(=[[a0+72]:8+48]) != 0.
  The `bne` branch at 0x24e4 targets 0x257c, is taken when a0(=[a0+80]) != v0(=0x1), and falls through when a0(=[a0+80]) == v0(=0x1).
  The `beq` branch at 0x24ec targets 0x236c and is always taken.
  The `beq` branch at 0x24f4 targets 0x23d8 and is always taken.
  The `beq` branch at 0x2514 targets 0x258c, is taken when a2(=[a0+80]) == 0, and falls through when a2(=[a0+80]) != 0.
  The `beq` branch at 0x252c targets 0x2448 and is always taken.
  The `beq` branch at 0x253c targets 0x2424 and is always taken.
  The `beq` branch at 0x255c targets 0x25a0, is taken when a2(=[a0+80]) == 0, and falls through when a2(=[a0+80]) != 0.
  The `beq` branch at 0x2574 targets 0x24d0 and is always taken.
  The `beq` branch at 0x2584 targets 0x2424 and is always taken.
  The `beq` branch at 0x2598 targets 0x252c and is always taken.
  The `beq` branch at 0x25ac targets 0x2574 and is always taken.
  The return at 0x242c has v0 = one of ([[[a0+72]:8+16]:8+156] | one of 0x40000, 0x80000), ret(cmn_err).
