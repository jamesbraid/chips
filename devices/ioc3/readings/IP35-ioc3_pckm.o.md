# Readings: `IP35/usr/cpu/sysgen/IP35boot/ioc3_pckm.o`

One entry per routine, filed here from the reading batches by binary.

- `ioc3_pckm_mlreset` in `IP35/usr/cpu/sysgen/IP35boot/ioc3_pckm.o` at 0x0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc3_pckm.o`.
  Range: 0x0-0x4c (76 bytes).
  It occupies 76 bytes.
  The `jal` at 0x38 calls pckm_console_register with a0=sp-64, a1=sym(ioc3_pckm_kbdexists), a2=sym(ioc3_early_pckminit), a3=a3 at entry (arg3).
  The return at 0x44 has v0 = ret(pckm_console_register).

- `ioc3_early_pckminit` in `IP35/usr/cpu/sysgen/IP35boot/ioc3_pckm.o` at 0x4c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc3_pckm.o`.
  Range: 0x4c-0x54 (8 bytes).
  It occupies 8 bytes.
  The return at 0x4c has v0 = ?.

- `pckminit` in `IP35/usr/cpu/sysgen/IP35boot/ioc3_pckm.o` at 0x54 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc3_pckm.o`.
  Range: 0x54-0x5c (8 bytes).
  It occupies 8 bytes.
  The return at 0x54 has v0 = ?.

- `pckm_open` in `IP35/usr/cpu/sysgen/IP35boot/ioc3_pckm.o` at 0x600 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc3_pckm.o`.
  Range: 0x600-0x7b4 (436 bytes).
  It occupies 436 bytes.
  The `lw` at 0x63c loads 4 bytes from a1 (arg1 at entry) +0x0.
  3 such `lw` accesses load 4 bytes from ret(hwgraph_fastinfo_get) +0x50, including `lw` at 0x670, `lw` at 0x6dc, `lw` at 0x7a8.
  2 such `lw` accesses load 4 bytes from ret(hwgraph_fastinfo_get) +0x4, including `lw` at 0x67c, `lw` at 0x730.
  The `sd` at 0x6ac stores 8 bytes to a0 (arg0 at entry) +0x28.
  The `sd` at 0x6b0 stores 8 bytes to ret(WR) +0x28.
  7 such `ld` accesses load 8 bytes from ret(hwgraph_fastinfo_get) +0x48, including `ld` at 0x6b4, `ld` at 0x6cc, `ld` at 0x6d4.
  The `sd` at 0x6bc stores 8 bytes to ret(hwgraph_fastinfo_get) +0x20.
  The `sd` at 0x6c0 stores 8 bytes to ret(hwgraph_fastinfo_get) +0x28.
  The `sw` at 0x6d0 stores 4 bytes to [ret(hwgraph_fastinfo_get)+72]:8 +0x34.
  The `lw` at 0x6d8 loads 4 bytes from [ret(hwgraph_fastinfo_get)+72]:8 +0x28.
  The `lw` at 0x6e8 loads 4 bytes from [ret(hwgraph_fastinfo_get)+72]:8 +0x2c.
  The `lw` at 0x700 loads 4 bytes from [ret(hwgraph_fastinfo_get)+72]:8 +0x5c.
  3 such `sw` accesses store 4 bytes to ret(hwgraph_fastinfo_get) +0x8, including `sw` at 0x718, `sw` at 0x79c, `sw` at 0x7b0.
  2 such `sw` accesses store 4 bytes to ret(hwgraph_fastinfo_get) +0xc, including `sw` at 0x720, `sw` at 0x790.
  The `sw` at 0x740 stores 4 bytes to ret(hwgraph_fastinfo_get) +0x4.
  The `lw` at 0x780 loads 4 bytes from [ret(hwgraph_fastinfo_get)+72]:8 +0x34.
  The `jal` at 0x614 calls WR with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x65c calls hwgraph_fastinfo_get with a0=[a1], a1=?, a2=?, a3=ret(WR), a5=-0x1.
  The `jal` at 0x6c4 calls mutex_lock with a0=[ret(hwgraph_fastinfo_get)+72]:8+72, a1=0x19, a2=ret(WR), a3=a0 at entry (arg0).
  The `jal` at 0x6f4 calls default_ms_setting with a0=ret(hwgraph_fastinfo_get), a1=?, a2=?, a3=?, a6=[[ret(hwgraph_fastinfo_get)+72]:8+44].
  The `jal` at 0x724 calls pckm_reinit_lock with a0=ret(hwgraph_fastinfo_get), a1=0x3, a2=?, a3=?.
  The `jal` at 0x73c calls mutex_unlock with a0=[ret(hwgraph_fastinfo_get)+72]:8+72, a1=([ret(hwgraph_fastinfo_get)+4] | 0x2), a2=?, a3=?.
  The `jal` at 0x76c calls pckm_pollcmd with a0=ret(hwgraph_fastinfo_get), a1=0xed, a2=?, a3=?, a4=[[ret(hwgraph_fastinfo_get)+72]:8+40], a5=[ret(hwgraph_fastinfo_get)+72]:8.
  The `jal` at 0x77c calls pckm_pollcmd with a0=ret(hwgraph_fastinfo_get), a1=[[ret(hwgraph_fastinfo_get)+72]:8+52], a2=?, a3=?.
  The `jal` at 0x798 calls pckm_pollcmd with a0=ret(hwgraph_fastinfo_get), a1=0xf8, a2=0xc, a3=0x2.
  The `beq` branch at 0x61c targets 0x638, is taken when s3(=a3) == 0, and falls through when s3(=a3) != 0.
  The `bne` branch at 0x64c targets 0x694, is taken when (at(?) & 0x1ff) != 0, and falls through when (at(?) & 0x1ff) == 0.
  The `beq` branch at 0x654 targets 0x69c, is taken when a0(=[a1]) == a5(=-0x1), and falls through when a0(=[a1]) != a5(=-0x1).
  The `beq` branch at 0x664 targets 0x750, is taken when v0(=ret(hwgraph_fastinfo_get)) == 0, and falls through when v0(=ret(hwgraph_fastinfo_get)) != 0.
  The `beq` branch at 0x674 targets 0x75c, is taken when a1(=[ret(hwgraph_fastinfo_get)+80]) == a2(=0x13), and falls through when a1(=[ret(hwgraph_fastinfo_get)+80]) != a2(=0x13).
  The `beq` branch at 0x684 targets 0x6a4, is taken when (a3(=[ret(hwgraph_fastinfo_get)+4]) & 0x2) == 0, and falls through when (a3(=[ret(hwgraph_fastinfo_get)+4]) & 0x2) != 0.
  The `beq` branch at 0x68c targets 0x628 and is always taken.
  The `beq` branch at 0x694 targets 0x628 and is always taken.
  The `beq` branch at 0x69c targets 0x62c and is always taken.
  The `beq` branch at 0x6e0 targets 0x768, is taken when a4(=[[ret(hwgraph_fastinfo_get)+72]:8+40]) == a0(=[ret(hwgraph_fastinfo_get)+80]), and falls through when a4(=[[ret(hwgraph_fastinfo_get)+72]:8+40]) != a0(=[ret(hwgraph_fastinfo_get)+80]).
  The `bne` branch at 0x6ec targets 0x730, is taken when a6(=[[ret(hwgraph_fastinfo_get)+72]:8+44]) != a0(=[ret(hwgraph_fastinfo_get)+80]), and falls through when a6(=[[ret(hwgraph_fastinfo_get)+72]:8+44]) == a0(=[ret(hwgraph_fastinfo_get)+80]).
  The `beq` branch at 0x708 targets 0x7ac, is taken when v0(=[[ret(hwgraph_fastinfo_get)+72]:8+92]) == a1(=0x3), and falls through when v0(=[[ret(hwgraph_fastinfo_get)+72]:8+92]) != a1(=0x3).
  The `beq` branch at 0x710 targets 0x7ac, is taken when v0(=[[ret(hwgraph_fastinfo_get)+72]:8+92]) == a0(=0x4), and falls through when v0(=[[ret(hwgraph_fastinfo_get)+72]:8+92]) != a0(=0x4).
  The `beq` branch at 0x748 targets 0x628 and is always taken.
  The `beq` branch at 0x754 targets 0x628 and is always taken.
  The `beq` branch at 0x760 targets 0x628 and is always taken.
  The `beq` branch at 0x7a4 targets 0x6e8 and is always taken.
  The `beq` branch at 0x7ac targets 0x71c and is always taken.
  The return at 0x630 has v0 = one of 0x0, 0x6, 0x10, 0x13.

- `pckm_close` in `IP35/usr/cpu/sysgen/IP35boot/ioc3_pckm.o` at 0x7b4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc3_pckm.o`.
  Range: 0x7b4-0x898 (228 bytes).
  It occupies 228 bytes.
  The `ld` at 0x7bc loads 8 bytes from a0 (arg0 at entry) +0x28.
  4 such `ld` accesses load 8 bytes from [a0+40]:8 +0x48, including `ld` at 0x7c4, `ld` at 0x83c, `ld` at 0x854.
  2 such `lw` accesses load 4 bytes from [a0+40]:8 +0x4, including `lw` at 0x7d8, `lw` at 0x7f0.
  The `lw` at 0x7ec loads 4 bytes from [a0+40]:8 +0x10.
  2 such `sw` accesses store 4 bytes to [a0+40]:8 +0x4, including `sw` at 0x804, `sw` at 0x818.
  The `ld` at 0x820 loads 8 bytes from [a0+40]:8 +0x30.
  The `ld` at 0x824 loads 8 bytes from [a0+40]:8 +0x40.
  The `sd` at 0x82c stores 8 bytes to [a0+40]:8 +0x30.
  The `lw` at 0x830 loads 4 bytes from [a0+40]:8 +0x50.
  The `sd` at 0x834 stores 8 bytes to [a0+40]:8 +0x20.
  The `sd` at 0x838 stores 8 bytes to [a0+40]:8 +0x28.
  The `sd` at 0x840 stores 8 bytes to [a0+40]:8 +0x40.
  The `lw` at 0x844 loads 4 bytes from [[a0+40]:8+72]:8 +0x2c.
  The `sw` at 0x850 stores 4 bytes to [[a0+40]:8+72]:8 +0x34.
  The `lw` at 0x864 loads 4 bytes from [[a0+40]:8+72]:8 +0x34.
  The `jal` at 0x7d0 calls mutex_lock with a0=[[a0+40]:8+72]:8+72, a1=0x19, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x7e8 calls untimeout with a0=[[a0+40]:8+16], a1=?, a2=[[a0+40]:8+4], a3=?, a5=-0x13.
  The `jal` at 0x814 calls str_unbcall with a0=a0 at entry (arg0), a1=?, a2=?, a3=?, a5=-0x13.
  The `jal` at 0x81c calls freemsg with a0=[[a0+40]:8+48]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x828 calls freemsg with a0=[[a0+40]:8+64]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x860 calls default_kbd_setting with a0=[a0+40]:8, a1=0x0, a2=[[[a0+40]:8+72]:8+52], a3=?, a4=[[a0+40]:8+72]:8, a7=[[[a0+40]:8+72]:8+44].
  The `jal` at 0x870 calls pckm_pollcmd with a0=[a0+40]:8, a1=0xff, a2=?, a3=?, a4=[[a0+40]:8+72]:8, a7=[[[a0+40]:8+72]:8+44].
  The `jal` at 0x87c calls mutex_unlock with a0=[[a0+40]:8+72]:8+72, a1=?, a2=?, a3=?.
  The `beq` branch at 0x7e0 targets 0x7f8, is taken when (a2(=[[a0+40]:8+4]) & 0x10) == 0, and falls through when (a2(=[[a0+40]:8+4]) & 0x10) != 0.
  The `beq` branch at 0x800 targets 0x81c, is taken when (a2(?) & 0x8) == 0, and falls through when (a2(?) & 0x8) != 0.
  The `beq` branch at 0x848 targets 0x870, is taken when a7(=[[[a0+40]:8+72]:8+44]) == t0(=[[a0+40]:8+80]), and falls through when a7(=[[[a0+40]:8+72]:8+44]) != t0(=[[a0+40]:8+80]).
  The `beq` branch at 0x868 targets 0x878 and is always taken.
  The return at 0x890 has v0 = 0x0.

- `pckm_wput` in `IP35/usr/cpu/sysgen/IP35boot/ioc3_pckm.o` at 0x898 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc3_pckm.o`.
  Range: 0x898-0xc54 (956 bytes).
  It occupies 956 bytes.
  The `ld` at 0x8a0 loads 8 bytes from a0 (arg0 at entry) +0x28.
  18 such `ld` accesses load 8 bytes from [a0+40]:8 +0x48, including `ld` at 0x8ac, `ld` at 0x8f0, `ld` at 0x974.
  2 such `ld` accesses load 8 bytes from a1 (arg1 at entry) +0x28, including `ld` at 0x8c8, `ld` at 0xb98.
  The `lbu` at 0x8cc loads 1 byte from [a1+40]:8 +0x1e.
  9 such `ld` accesses load 8 bytes from a1 (arg1 at entry) +0x18, including `ld` at 0x910, `ld` at 0x934, `ld` at 0x99c.
  6 such `lbu` accesses load 1 byte from [a1+24]:8 +0x0, including `lbu` at 0x914, `lbu` at 0x938, `lbu` at 0x9b0.
  The `sb` at 0x958 stores 1 byte to [a1+24]:8 +0x0.
  4 such `ld` accesses load 8 bytes from a1 (arg1 at entry) +0x20, including `ld` at 0x9a0, `ld` at 0xa3c, `ld` at 0xaf8.
  5 such `lw` accesses load 4 bytes from [[a0+40]:8+72]:8 +0x28, including `lw` at 0x9dc, `lw` at 0xa50, `lw` at 0xaf4.
  The `ld` at 0x9f8 loads 8 bytes from ([[a0+40]:8+72]:8 + ([[[a0+40]:8+72]:8+40] << 0x3)) +0x18.
  3 such `lw` accesses load 4 bytes from [[a0+40]:8+72]:8 +0x2c, including `lw` at 0xa14, `lw` at 0xa60, `lw` at 0xaac.
  The `ld` at 0xa2c loads 8 bytes from ([[a0+40]:8+72]:8 + ([[[a0+40]:8+72]:8+44] << 0x3)) +0x18.
  3 such `sd` accesses store 8 bytes to a1 (arg1 at entry) +0x18, including `sd` at 0xa38, `sd` at 0xa80, `sd` at 0xb78.
  4 such `lw` accesses load 4 bytes from [a0+40]:8 +0x50, including `lw` at 0xa64, `lw` at 0xab0, `lw` at 0xc14.
  The `lbu` at 0xa74 loads 1 byte from ?.
  The `lw` at 0xa98 loads 4 bytes from [a1+24]:8 +0x0.
  3 such `sd` accesses store 8 bytes to a1 (arg1 at entry) +0x20, including `sd` at 0xb08, `sd` at 0xb44, `sd` at 0xbb8.
  The `lw` at 0xb10 loads 4 bytes from [[a0+40]:8+72]:8 +0x58.
  3 such `sb` accesses store 1 byte to [a1+32]:8 +0x0, including `sb` at 0xb14, `sb` at 0xb50, `sb` at 0xbc0.
  The `lw` at 0xb4c loads 4 bytes from [[a0+40]:8+72]:8 +0x5c.
  2 such `lw` accesses load 4 bytes from [a0+40]:8 +0x0, including `lw` at 0xb88, `lw` at 0xc3c.
  The `lw` at 0xb8c loads 4 bytes from [a0+40]:8 +0x54.
  The `sb` at 0xbac stores 1 byte to [a1+40]:8 +0x1e.
  The `sw` at 0xc50 stores 4 bytes to [a0+40]:8 +0x54.
  The `jal` at 0x8c0 calls mutex_lock with a0=[[a0+40]:8+72]:8+72, a1=0x19, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x8f4 calls mutex_unlock with a0=[[a0+40]:8+72]:8+72, a1=0x86, a2=?, a3=?.
  The `jal` at 0x900 calls sdrv_error with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0x92c calls flushq with a0=a0 at entry (arg0), a1=0x0, a2=?, a3=?.
  The `jal` at 0x954 calls RD with a0=a0 at entry (arg0), a1=[[a1+24]:8]:1, a2=?, a3=?.
  The `jal` at 0x960 calls flushq with a0=ret(RD), a1=0x1, a2=?, a3=?.
  The `jal` at 0x96c calls qreply with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0x978 calls mutex_unlock with a0=[[a0+40]:8+72]:8+72, a1=?, a2=?, a3=?.
  The `jal` at 0x9f4 calls pckm_reinit_lock with a0=[([[a0+40]:8+72]:8 + ([[[a0+40]:8+72]:8+40] << 0x3))+24]:8, a1=[[a1+24]:8]:1, a2=?, a3=0xfa, a4=[[[a0+40]:8+72]:8+40], a5=[[a0+40]:8+72]:8, a6=0x13.
  The `jal` at 0xa28 calls pckm_reinit_lock with a0=[([[a0+40]:8+72]:8 + ([[[a0+40]:8+72]:8+44] << 0x3))+24]:8, a1=[[a0+40]:8+72]:8, a2=?, a3=0x13, a4=[[[a0+40]:8+72]:8+44].
  The `jal` at 0xa70 calls ioc3_lcl_pckm_setleds_lock with a0=[a0+40]:8, a1=?, a2=?, a3=?, a5=[[[a0+40]:8+72]:8+40], a6=0x13, a7=[[[a0+40]:8+72]:8+44].
  The `jal` at 0xa84 calls freemsg with a0=a1 at entry (arg1), a1=?, a2=?, a3=?.
  The `jal` at 0xacc calls freemsg with a0=a1 at entry (arg1), a1=?, a2=?, a3=?.
  The `jal` at 0xb1c calls qreply with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0xb2c calls freemsg with a0=a1 at entry (arg1), a1=[[a1+24]:8]:1, a2=?, a3=?.
  The `jal` at 0xb58 calls qreply with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=[a1+32]:8+1, a3=?.
  The `jal` at 0xb84 calls device_controller_num_get with a0=[[a0+40]:8], a1=?, a2=?, a3=?.
  The `jal` at 0xba8 calls qreply with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?, a5=0x81, a6=[a1+40]:8.
  The `jal` at 0xbc4 calls pckm_pollcmd with a0=[a0+40]:8, a1=0xfa, a2=0xfc, a3=0xfa, a5=[a1+32]:8.
  The `jal` at 0xbd0 calls pckm_pollcmd with a0=[a0+40]:8, a1=0xfc, a2=?, a3=?.
  The `jal` at 0xbdc calls pckm_pollcmd with a0=[a0+40]:8, a1=0x14, a2=?, a3=?.
  The `jal` at 0xbe8 calls pckm_pollcmd with a0=[a0+40]:8, a1=0xfc, a2=?, a3=?.
  The `jal` at 0xbf4 calls pckm_pollcmd with a0=[a0+40]:8, a1=0x76, a2=?, a3=?.
  The `jal` at 0xc00 calls pckm_pollcmd with a0=[a0+40]:8, a1=0xf4, a2=?, a3=?.
  The `jal` at 0xc20 calls pckm_rmalias with a0=[[a0+40]:8+84], a1=?, a2=[[a0+40]:8+80], a3=?.
  The `jal` at 0xc40 calls ioc_pckm_add_hwgraph_alias with a0=[[a0+40]:8], a1=ret(device_controller_num_get), a2=?, a3=[[a0+40]:8+80].
  The `beq` branch at 0x8d0 targets 0x99c, is taken when v0(=[[a1+40]:8+30]:1) == 0, and falls through when v0(=[[a1+40]:8+30]:1) != 0.
  The `beq` branch at 0x8d8 targets 0xa94, is taken when v0(=[[a1+40]:8+30]:1) == v1(=0xe), and falls through when v0(=[[a1+40]:8+30]:1) != v1(=0xe).
  The `beq` branch at 0x8e0 targets 0xadc, is taken when v0(=[[a1+40]:8+30]:1) == a0(=0xd), and falls through when v0(=[[a1+40]:8+30]:1) != a0(=0xd).
  The `beq` branch at 0x8e8 targets 0x910, is taken when v0(=[[a1+40]:8+30]:1) == a1(=0x86), and falls through when v0(=[[a1+40]:8+30]:1) != a1(=0x86).
  The `beq` branch at 0x908 targets 0x984 and is always taken.
  The `beq` branch at 0x920 targets 0x944, is taken when (a0(=[[a1+24]:8]:1) & 0x2) == 0, and falls through when (a0(=[[a1+24]:8]:1) & 0x2) != 0.
  The `beq` branch at 0x944 targets 0xb2c, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0x9a8 targets 0xa44, is taken when a0(=[a1+24]:8) >= a5(=[a1+32]:8) (unsigned), and falls through when a0(=[a1+24]:8) < a5(=[a1+32]:8) (unsigned).
  The `beq` branch at 0x9b8 targets 0xb68, is taken when a1(=[[a1+24]:8]:1) == a2(=0xfc), and falls through when a1(=[[a1+24]:8]:1) != a2(=0xfc).
  The `beq` branch at 0x9c4 targets 0xbc4, is taken when a1(=[[a1+24]:8]:1) == a3(=0xfa), and falls through when a1(=[[a1+24]:8]:1) != a3(=0xfa).
  The `beq` branch at 0x9d0 targets 0xa08, is taken when (a1(=[[a1+24]:8]:1) & 0x1) == 0, and falls through when (a1(=[[a1+24]:8]:1) & 0x1) != 0.
  The `beq` branch at 0x9e4 targets 0xa08, is taken when a4(=[[[a0+40]:8+72]:8+40]) == a6(=0x13), and falls through when a4(=[[[a0+40]:8+72]:8+40]) != a6(=0x13).
  The `beq` branch at 0xa08 targets 0xa34, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0xa1c targets 0xa34, is taken when a4(=[[[a0+40]:8+72]:8+44]) == a3(=0x13), and falls through when a4(=[[[a0+40]:8+72]:8+44]) != a3(=0x13).
  The `beq` branch at 0xa44 targets 0xa84, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0xa58 targets 0xa84, is taken when a5(=[[[a0+40]:8+72]:8+40]) == a6(=0x13), and falls through when a5(=[[[a0+40]:8+72]:8+40]) != a6(=0x13).
  The `beq` branch at 0xa68 targets 0xa84, is taken when a7(=[[[a0+40]:8+72]:8+44]) == t0(=[[a0+40]:8+80]), and falls through when a7(=[[[a0+40]:8+72]:8+44]) != t0(=[[a0+40]:8+80]).
  The `beq` branch at 0xa8c targets 0x978 and is always taken.
  The `beq` branch at 0xaa0 targets 0xb84, is taken when t2(=[[a1+24]:8]) == t3(=0x7001), and falls through when t2(=[[a1+24]:8]) != t3(=0x7001).
  The `bne` branch at 0xab4 targets 0xacc, is taken when t8(=[[[a0+40]:8+72]:8+44]) != t9(=[[a0+40]:8+80]), and falls through when t8(=[[[a0+40]:8+72]:8+44]) == t9(=[[a0+40]:8+80]).
  The `beq` branch at 0xac4 targets 0xb3c, is taken when t9(=[[a1+24]:8]:1) == ra(=0x12), and falls through when t9(=[[a1+24]:8]:1) != ra(=0x12).
  The `beq` branch at 0xad4 targets 0x978 and is always taken.
  The `bne` branch at 0xae8 targets 0x974, is taken when at(=[[a1+24]:8]:1) != v0(=0xde), and falls through when at(=[[a1+24]:8]:1) == v0(=0xde).
  The `beq` branch at 0xb00 targets 0xbb8, is taken when v0(=[[[a0+40]:8+72]:8+40]) == a1(=0x13), and falls through when v0(=[[[a0+40]:8+72]:8+40]) != a1(=0x13).
  The `beq` branch at 0xb24 targets 0x978 and is always taken.
  The `beq` branch at 0xb34 targets 0x978 and is always taken.
  The `beq` branch at 0xb60 targets 0x978 and is always taken.
  The `bne` branch at 0xb6c targets 0xa44, is taken when a3(?) < 0x2 (signed), and falls through when a3(?) >= 0x2 (signed).
  The `beq` branch at 0xb7c targets 0xa44 and is always taken.
  The `bne` branch at 0xb90 targets 0xc10, is taken when v0(=ret(device_controller_num_get)) != a0(=[[a0+40]:8+84]), and falls through when v0(=ret(device_controller_num_get)) == a0(=[[a0+40]:8+84]).
  The `beq` branch at 0xbb0 targets 0x978 and is always taken.
  The `beq` branch at 0xbbc targets 0xb18 and is always taken.
  The `beq` branch at 0xc08 targets 0xa3c and is always taken.
  The `beq` branch at 0xc4c targets 0xb98 and is always taken.
  The return at 0x994 has v0 = 0x0.

- `pckm_getbp` in `IP35/usr/cpu/sysgen/IP35boot/ioc3_pckm.o` at 0xc54 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc3_pckm.o`.
  Range: 0xc54-0xd60 (268 bytes).
  It occupies 268 bytes.
  The `ld` at 0xc60 loads 8 bytes from a0 (arg0 at entry) +0x40.
  2 such `ld` accesses load 8 bytes from [a0+64]:8 +0x20, including `ld` at 0xc80, `ld` at 0xcd0.
  The `ld` at 0xc84 loads 8 bytes from [a0+64]:8 +0x18.
  2 such `ld` accesses load 8 bytes from [a0+64]:8 +0x28, including `ld` at 0xc94, `ld` at 0xcd4.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x8, including `lw` at 0xc9c, `lw` at 0xcac, `lw` at 0xd3c.
  The `ld` at 0xcd8 loads 8 bytes from [[a0+64]:8+40]:8 +0x10.
  2 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x40, including `sd` at 0xd1c, `sd` at 0xd5c.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x4, including `lw` at 0xd20, `lw` at 0xd48.
  The `ld` at 0xd30 loads 8 bytes from a0 (arg0 at entry) +0x20.
  The `sw` at 0xd54 stores 4 bytes to a0 (arg0 at entry) +0x4.
  The `jal` at 0xcb0 calls allocb with a0=[a0+8], a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0xd10 calls str_conmsg with a0=a0+48, a1=a0+56, a2=[a0+64]:8, a3=?.
  The `jal` at 0xd38 calls str_allocb with a0=[a0+8], a1=[a0+32]:8, a2=0x3, a3=?.
  The `beq` branch at 0xc78 targets 0xc98, is taken when s2(=[a0+64]:8) == 0, and falls through when s2(=[a0+64]:8) != 0.
  The `bne` branch at 0xc88 targets 0xc98, is taken when at(=[[a0+64]:8+24]:8) != v0(=[[a0+64]:8+32]:8), and falls through when at(=[[a0+64]:8+24]:8) == v0(=[[a0+64]:8+32]:8).
  The `beq` branch at 0xc90 targets 0xcd8 and is always taken.
  The `beq` branch at 0xc98 targets 0xcb0 and is always taken.
  The `bne` branch at 0xca4 targets 0xd20, is taken when v0(=0x3) != s3(=a1), and falls through when v0(=0x3) == s3(=a1).
  The `beq` branch at 0xcb8 targets 0xca0, is taken when v0(=ret(allocb)) == 0, and falls through when v0(=ret(allocb)) != 0.
  The `beq` branch at 0xcc0 targets 0xd58, is taken when s2(=[a0+64]:8) == 0, and falls through when s2(=[a0+64]:8) != 0.
  The `bne` branch at 0xcc8 targets 0xd0c, is taken when s1(?) != 0, and falls through when s1(?) == 0.
  The `beq` branch at 0xce0 targets 0xd0c, is taken when v0(=[[a0+64]:8+32]:8) >= v1(=[[[a0+64]:8+40]:8+16]:8) (unsigned), and falls through when v0(=[[a0+64]:8+32]:8) < v1(=[[[a0+64]:8+40]:8+16]:8) (unsigned).
  The `beq` branch at 0xd18 targets 0xce8 and is always taken.
  The `bne` branch at 0xd28 targets 0xcc0, is taken when (a0(=[a0+4]) & 0x8) != 0, and falls through when (a0(=[a0+4]) & 0x8) == 0.
  The `bne` branch at 0xd40 targets 0xcc0, is taken when v0(=ret(str_allocb)) != 0, and falls through when v0(=ret(str_allocb)) == 0.
  The `bne` branch at 0xd50 targets 0xcc8, is taken when s2(=[a0+64]:8) != 0, and falls through when s2(=[a0+64]:8) == 0.
  The `beq` branch at 0xd58 targets 0xce8 and is always taken.
  The return at 0xd00 has v0 = ?.
  The instructions from 0xd08 to 0xd08 are not reached by any path from the entry, and their branches are not listed.

- `pckm_rsrv_timer` in `IP35/usr/cpu/sysgen/IP35boot/ioc3_pckm.o` at 0xd60 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc3_pckm.o`.
  Range: 0xd60-0xda4 (68 bytes).
  It occupies 68 bytes.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x48, including `ld` at 0xd6c, `ld` at 0xd88.
  The `jal` at 0xd78 calls mutex_lock with a0=[a0+72]:8+72, a1=0x19, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xd80 calls pckm_rsrv_timer_lock with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xd8c calls mutex_unlock with a0=[a0+72]:8+72, a1=?, a2=?, a3=?.
  The return at 0xd9c has v0 = ret(mutex_unlock).

- `pckm_rsrv_timer_lock` in `IP35/usr/cpu/sysgen/IP35boot/ioc3_pckm.o` at 0xda4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc3_pckm.o`.
  Range: 0xda4-0xe28 (132 bytes).
  It occupies 132 bytes.
  The `lw` at 0xda4 loads 4 bytes from a0 (arg0 at entry) +0x4.
  The `ld` at 0xdc0 loads 8 bytes from a0 (arg0 at entry) +0x20.
  The `ld` at 0xdc4 loads 8 bytes from [a0+32]:8 +0x38.
  The `lw` at 0xde4 loads 4 bytes from a0 (arg0 at entry) +0xc.
  The `sw` at 0xdf0 stores 4 bytes to a0 (arg0 at entry) +0x10.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x4, including `sw` at 0xe0c, `sw` at 0xe24.
  The `jal` at 0xde8 calls streams_timeout with a0=sym(streams_monp), a1=sym(pckm_rsrv_timer), a2=[a0+12], a3=a0 at entry (arg0), a4=0x0, a5=0x0.
  The `jal` at 0xe08 calls qenable with a0=[a0+32]:8, a1=a1 at entry (arg1), a2=[a0+4], a3=a3 at entry (arg3).
  The `beq` branch at 0xdb8 targets 0xe18, is taken when (a2(=[a0+4]) & 0x2) == 0, and falls through when (a2(=[a0+4]) & 0x2) != 0.
  The `beq` branch at 0xdcc targets 0xe04, is taken when (v0(=[[a0+32]:8+56]:8) & 0x40) == 0, and falls through when (v0(=[[a0+32]:8+56]:8) & 0x40) != 0.
  The `beq` branch at 0xe10 targets 0xdf8 and is always taken.
  The `beq` branch at 0xe20 targets 0xdf4 and is always taken.
  The return at 0xdfc has v0 = one of ?, ret(qenable).

- `pckm_rsrv` in `IP35/usr/cpu/sysgen/IP35boot/ioc3_pckm.o` at 0xe28 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc3_pckm.o`.
  Range: 0xe28-0xf78 (336 bytes).
  It occupies 336 bytes.
  The `ld` at 0xe30 loads 8 bytes from a0 (arg0 at entry) +0x28.
  6 such `ld` accesses load 8 bytes from [a0+40]:8 +0x48, including `ld` at 0xe3c, `ld` at 0xed0, `ld` at 0xef4.
  The `ld` at 0xe54 loads 8 bytes from a0 (arg0 at entry) +0x18.
  2 such `lw` accesses load 4 bytes from [a0+40]:8 +0x4, including `lw` at 0xe68, `lw` at 0xeb0.
  The `sw` at 0xe84 stores 4 bytes to [a0+40]:8 +0x4.
  2 such `ld` accesses load 8 bytes from [a0+40]:8 +0x40, including `ld` at 0xe88, `ld` at 0xf24.
  The `ld` at 0xe94 loads 8 bytes from [[a0+40]:8+64]:8 +0x20.
  The `ld` at 0xe98 loads 8 bytes from [[a0+40]:8+64]:8 +0x18.
  3 such `ld` accesses load 8 bytes from [a0+40]:8 +0x30, including `ld` at 0xea4, `ld` at 0xf2c, `ld` at 0xf74.
  The `sd` at 0xef8 stores 8 bytes to [a0+40]:8 +0x30.
  The `sd` at 0xf68 stores 8 bytes to [a0+40]:8 +0x40.
  The `jal` at 0xe48 calls mutex_lock with a0=[[a0+40]:8+72]:8+72, a1=0x19, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xe50 calls canput with a0=[a0+24]:8, a1=?, a2=?, a3=?.
  The `jal` at 0xe60 calls enableok with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xe80 calls str_unbcall with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xed4 calls mutex_unlock with a0=[[a0+40]:8+72]:8+72, a1=?, a2=?, a3=?.
  The `jal` at 0xefc calls mutex_unlock with a0=[[a0+40]:8+72]:8+72, a1=[[a0+40]:8+48]:8, a2=?, a3=?.
  The `jal` at 0xf08 calls putnext with a0=a0 at entry (arg0), a1=[[a0+40]:8+48]:8, a2=?, a3=?.
  The `jal` at 0xf18 calls mutex_lock with a0=[[a0+40]:8+72]:8+72, a1=0x19, a2=?, a3=?.
  The `jal` at 0xf30 calls noenable with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xf3c calls mutex_unlock with a0=[[a0+40]:8+72]:8+72, a1=?, a2=?, a3=?.
  The `jal` at 0xf4c calls pckm_getbp with a0=[a0+40]:8, a1=0x1, a2=?, a3=?.
  The `jal` at 0xf60 calls str_conmsg with a0=[a0+40]:8+48, a1=[a0+40]:8+56, a2=[[a0+40]:8+64]:8, a3=?, a4=[[[a0+40]:8+64]:8+32]:8.
  The `beq` branch at 0xe58 targets 0xf30, is taken when v0(=ret(canput)) == 0, and falls through when v0(=ret(canput)) != 0.
  The `beq` branch at 0xe70 targets 0xe88, is taken when (v0(=[[a0+40]:8+4]) & 0x8) == 0, and falls through when (v0(=[[a0+40]:8+4]) & 0x8) != 0.
  The `beq` branch at 0xe8c targets 0xf28, is taken when a2(=[[a0+40]:8+64]:8) == 0, and falls through when a2(=[[a0+40]:8+64]:8) != 0.
  The `beq` branch at 0xea0 targets 0xec0, is taken when a3(=[[[a0+40]:8+64]:8+24]:8) >= a4(=[[[a0+40]:8+64]:8+32]:8) (unsigned), and falls through when a3(=[[[a0+40]:8+64]:8+24]:8) < a4(=[[[a0+40]:8+64]:8+32]:8) (unsigned).
  The `beq` branch at 0xea8 targets 0xf60, is taken when a1(=[[a0+40]:8+48]:8) == 0, and falls through when a1(=[[a0+40]:8+48]:8) != 0.
  The `beq` branch at 0xeb8 targets 0xf60, is taken when (a5(=[[a0+40]:8+4]) & 0x10) == 0, and falls through when (a5(=[[a0+40]:8+4]) & 0x10) != 0.
  The `bne` branch at 0xec0 targets 0xef4, is taken when a1(=[[a0+40]:8+48]:8) != 0, and falls through when a1(=[[a0+40]:8+48]:8) == 0.
  The `beq` branch at 0xec8 targets 0xf4c, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0xf20 targets 0xec8 and is always taken.
  The `beq` branch at 0xf28 targets 0xec0 and is always taken.
  The `beq` branch at 0xf44 targets 0xee0 and is always taken.
  The `beq` branch at 0xf54 targets 0xed4 and is always taken.
  The `beq` branch at 0xf70 targets 0xec0 and is always taken.
  The return at 0xeec has v0 = 0x0.
  The instructions from 0xf5c to 0xf5c are not reached by any path from the entry, and their branches are not listed.

- `pckm_reinit` in `IP35/usr/cpu/sysgen/IP35boot/ioc3_pckm.o` at 0xf78 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc3_pckm.o`.
  Range: 0xf78-0xfbc (68 bytes).
  It occupies 68 bytes.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x48, including `ld` at 0xf84, `ld` at 0xfa0.
  The `jal` at 0xf90 calls mutex_lock with a0=[a0+72]:8+72, a1=0x19, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xf98 calls pckm_reinit_lock with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xfa4 calls mutex_unlock with a0=[a0+72]:8+72, a1=?, a2=?, a3=?.
  The return at 0xfb4 has v0 = ret(mutex_unlock).

- `pckm_reinit_lock` in `IP35/usr/cpu/sysgen/IP35boot/ioc3_pckm.o` at 0xfbc (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc3_pckm.o`.
  Range: 0xfbc-0x1018 (92 bytes).
  It occupies 92 bytes.
  3 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x48, including `ld` at 0xfc8, `ld` at 0xfe8, `ld` at 0xff8.
  2 such `ld` accesses load 8 bytes from [a0+72]:8 +0x60, including `ld` at 0xfdc, `ld` at 0x1004.
  The `ld` at 0xfec loads 8 bytes from [a0+72]:8 +0x10.
  The `sw` at 0xff4 stores 4 bytes to [[a0+72]:8+16]:8 +0x1c.
  The `jal` at 0xfd8 calls ioc3_write_ireg with a0=[[a0+72]:8+96]:8, a1=0x400000, a2=0x1, a3=a3 at entry (arg3).
  The `jal` at 0xfe0 calls pckm_reinit_core with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x1000 calls ioc3_write_ireg with a0=[[a0+72]:8+96]:8, a1=0x400000, a2=0x0, a3=?.
  The return at 0x1010 has v0 = ret(ioc3_write_ireg).

- `pckm_reinit_core` in `IP35/usr/cpu/sysgen/IP35boot/ioc3_pckm.o` at 0x1018 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc3_pckm.o`.
  Range: 0x1018-0x108c (116 bytes).
  It occupies 116 bytes.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x48, including `ld` at 0x1018, `ld` at 0x1040.
  The `lw` at 0x101c loads 4 bytes from a0 (arg0 at entry) +0x50.
  The `lw` at 0x1020 loads 4 bytes from [a0+72]:8 +0x28.
  The `lw` at 0x1050 loads 4 bytes from [a0+72]:8 +0x34.
  The `lw` at 0x1054 loads 4 bytes from a0 (arg0 at entry) +0x4.
  The `jal` at 0x1038 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xf5, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x104c calls default_kbd_setting with a0=a0 at entry (arg0), a1=0x0, a2=[[a0+72]:8+52], a3=?.
  The `jal` at 0x1064 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xf8, a2=?, a3=?.
  The `jal` at 0x1074 calls default_ms_setting with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `bne` branch at 0x1030 targets 0x1074, is taken when at(=[[a0+72]:8+40]) != v0(=[a0+80]), and falls through when at(=[[a0+72]:8+40]) == v0(=[a0+80]).
  The `beq` branch at 0x105c targets 0x107c, is taken when (a3(=[a0+4]) & 0x2) == 0, and falls through when (a3(=[a0+4]) & 0x2) != 0.
  The `beq` branch at 0x106c targets 0x1080 and is always taken.
  The return at 0x1084 has v0 = one of ret(pckm_pollcmd), ?.

- `default_kbd_setting` in `IP35/usr/cpu/sysgen/IP35boot/ioc3_pckm.o` at 0x108c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc3_pckm.o`.
  Range: 0x108c-0x1144 (184 bytes).
  It occupies 184 bytes.
  The `jal` at 0x10a8 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xed, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x10b4 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=a2 at entry (arg2), a2=?, a3=?.
  The `jal` at 0x10c0 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xf0, a2=?, a3=?.
  The `jal` at 0x10cc calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0x3, a2=?, a3=?.
  The `jal` at 0x10d8 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xfa, a2=?, a3=?.
  The `jal` at 0x10e4 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xfc, a2=?, a3=?.
  The `jal` at 0x10f0 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0x14, a2=?, a3=?.
  The `jal` at 0x10fc calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xfc, a2=?, a3=?.
  The `jal` at 0x110c calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0x76, a2=?, a3=?.
  The `jal` at 0x1134 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xf4, a2=?, a3=?.
  The `beq` branch at 0x1118 targets 0x1134, is taken when (s8(=a1) & 0x1) == 0, and falls through when (s8(=a1) & 0x1) != 0.
  The `beq` branch at 0x113c targets 0x1124 and is always taken.
  The return at 0x112c has v0 = ret(pckm_pollcmd).

- `default_ms_setting` in `IP35/usr/cpu/sysgen/IP35boot/ioc3_pckm.o` at 0x1144 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc3_pckm.o`.
  Range: 0x1144-0x12f8 (436 bytes).
  It occupies 436 bytes.
  5 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x48, including `ld` at 0x1194, `ld` at 0x1254, `ld` at 0x125c.
  3 such `sw` accesses store 4 bytes to [a0+72]:8 +0x5c, including `sw` at 0x1198, `sw` at 0x1258, `sw` at 0x12d4.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x50, including `lw` at 0x1250, `lw` at 0x12cc.
  2 such `lw` accesses load 4 bytes from [a0+72]:8 +0x5c, including `lw` at 0x1260, `lw` at 0x12dc.
  The `jal` at 0x1154 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xe8, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1160 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0x3, a2=?, a3=?.
  The `jal` at 0x116c calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xf4, a2=?, a3=?.
  The `jal` at 0x11a0 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xf6, a2=?, a3=?.
  The `jal` at 0x11ac calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xe6, a2=?, a3=?.
  The `jal` at 0x11b8 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xf3, a2=?, a3=?.
  The `jal` at 0x11c4 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0x64, a2=?, a3=?.
  The `jal` at 0x11d0 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xe8, a2=?, a3=?.
  The `jal` at 0x11dc calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0x3, a2=?, a3=?.
  The `jal` at 0x11e8 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xf4, a2=?, a3=?.
  The `jal` at 0x1204 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xf3, a2=0x2, a3=?.
  The `jal` at 0x1210 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xc8, a2=?, a3=?.
  The `jal` at 0x121c calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xf3, a2=?, a3=?.
  The `jal` at 0x1228 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0x64, a2=?, a3=?.
  The `jal` at 0x1234 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xf3, a2=?, a3=?.
  The `jal` at 0x1240 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0x50, a2=?, a3=?.
  The `jal` at 0x124c calls check_port with a0=a0 at entry (arg0), a1=[a0+80], a2=?, a3=?.
  The `jal` at 0x1280 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xf3, a2=0x2, a3=?.
  The `jal` at 0x128c calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xc8, a2=?, a3=?.
  The `jal` at 0x1298 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xf3, a2=?, a3=?.
  The `jal` at 0x12a4 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xc8, a2=?, a3=?.
  The `jal` at 0x12b0 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xf3, a2=?, a3=?.
  The `jal` at 0x12bc calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0x50, a2=?, a3=?.
  The `jal` at 0x12c8 calls check_port with a0=a0 at entry (arg0), a1=[a0+80], a2=?, a3=?.
  The `beq` branch at 0x117c targets 0x127c, is taken when a0(=[sym(pcmouse_mode)]) == a2(=0x2), and falls through when a0(=[sym(pcmouse_mode)]) != a2(=0x2).
  The `beq` branch at 0x1184 targets 0x1200, is taken when a0(=[sym(pcmouse_mode)]) == at(=0x1), and falls through when a0(=[sym(pcmouse_mode)]) != at(=0x1).
  The `beq` branch at 0x118c targets 0x1204, is taken when a0(=[sym(pcmouse_mode)]) == a2(=0x2), and falls through when a0(=[sym(pcmouse_mode)]) != a2(=0x2).
  The `beq` branch at 0x126c targets 0x1198, is taken when v0(?) >= 0x1 (unsigned), and falls through when v0(?) < 0x1 (unsigned).
  The `beq` branch at 0x1274 targets 0x11a0 and is always taken.
  The `bne` branch at 0x12e8 targets 0x119c, is taken when a0(?) < 0x1 (unsigned), and falls through when a0(?) >= 0x1 (unsigned).
  The `beq` branch at 0x12f0 targets 0x1180 and is always taken.
  The return at 0x11f8 has v0 = ret(pckm_pollcmd).

- `pckm_rx` in `IP35/usr/cpu/sysgen/IP35boot/ioc3_pckm.o` at 0x12f8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc3_pckm.o`.
  Range: 0x12f8-0x160c (788 bytes).
  It occupies 788 bytes.
  6 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x48, including `ld` at 0x12f8, `ld` at 0x1424, `ld` at 0x143c.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x50, including `lw` at 0x12fc, `lw` at 0x15b4, `lw` at 0x1608.
  The `lw` at 0x1304 loads 4 bytes from [a0+72]:8 +0x2c.
  The `lw` at 0x132c loads 4 bytes from [a0+72]:8 +0x28.
  6 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x4, including `lw` at 0x134c, `lw` at 0x1358, `lw` at 0x13e0.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x18, including `ld` at 0x1360, `ld` at 0x1430.
  The `sd` at 0x1378 stores 8 bytes to a0 (arg0 at entry) +0x18.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x40, including `ld` at 0x138c, `ld` at 0x14c4.
  2 such `ld` accesses load 8 bytes from [a0+64]:8 +0x28, including `ld` at 0x1398, `ld` at 0x13b4.
  2 such `ld` accesses load 8 bytes from [[a0+64]:8+40]:8 +0x10, including `ld` at 0x139c, `ld` at 0x13c0.
  3 such `ld` accesses load 8 bytes from [a0+64]:8 +0x20, including `ld` at 0x13a0, `ld` at 0x13b0, `ld` at 0x14cc.
  The `sb` at 0x13ac stores 1 byte to [[a0+64]:8+32]:8 +0x0.
  The `sd` at 0x13bc stores 8 bytes to [a0+64]:8 +0x20.
  The `lw` at 0x13f0 loads 4 bytes from a0 (arg0 at entry) +0xc.
  The `sw` at 0x1408 stores 4 bytes to a0 (arg0 at entry) +0x4.
  The `sw` at 0x1418 stores 4 bytes to a0 (arg0 at entry) +0x10.
  The `lw` at 0x1474 loads 4 bytes from a0 (arg0 at entry) +0x10.
  The `ll` at 0x14a4 loads 4 bytes from [a0+72]:8 +0x3c.
  The `sc` at 0x14b0 stores 4 bytes to [a0+72]:8 +0x3c.
  2 such `lh` accesses load 2 bytes from abs 0xffffffffffffc428, including `lh` at 0x155c, `lh` at 0x15a0.
  The `lw` at 0x15d0 loads 4 bytes from [a0+72]:8 +0x34.
  The `jal` at 0x140c calls streams_timeout with a0=sym(streams_monp), a1=sym(pckm_rsrv_timer), a2=[a0+12], a3=a0 at entry (arg0), a4=0x0, a5=0x0, a6=0x76, a7=[a0+4].
  The `jal` at 0x1428 calls mutex_unlock with a0=[a0+72]:8+72, a1=?, a2=?, a3=?.
  The `jalr` at 0x1434 calls (unknown callee) with a0=?, a1=[a0+24]:8, a2=?, a3=?.
  The `jal` at 0x1444 calls mutex_lock with a0=[a0+72]:8+72, a1=0x19, a2=?, a3=?.
  The `jal` at 0x1470 calls untimeout with a0=[a0+16], a1=a0 at entry (arg0), a2=?, a3=?, a5=0x14, a6=0x76.
  The `jal` at 0x1484 calls streams_interrupt with a0=sym(pckm_rsrv_timer), a1=a0 at entry (arg0), a2=0x0, a3=0x0.
  The `jal` at 0x14bc calls pckm_getbp with a0=a0 at entry (arg0), a1=0x3, a2=[[a0+72]:8+60]+1, a3=[a0+72]:8+60, a4=0x1, a5=[[a0+72]:8+60]+1.
  The `jal` at 0x14d0 calls pckm_getbp with a0=a0 at entry (arg0), a1=0x1, a2=?, a3=[[[a0+64]:8+40]:8+16]:8, a4=[[a0+64]:8+32]:8+1.
  The `jal` at 0x14e4 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xf0, a2=?, a3=[a0+80], a4=[a0+72]:8.
  The `jal` at 0x14f4 calls data_check with a0=ret(pckm_pollcmd), a1=0xfa, a2=?, a3=?.
  The `jal` at 0x1508 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0x0, a2=?, a3=?.
  The `jal` at 0x1518 calls data_check with a0=ret(pckm_pollcmd), a1=0xfa, a2=?, a3=?.
  The `jal` at 0x152c calls pckm_pollcmd with a0=a0 at entry (arg0), a1=-0x2, a2=?, a3=ret(pckm_pollcmd).
  The `jal` at 0x153c calls data_check with a0=ret(pckm_pollcmd), a1=0x2, a2=?, a3=ret(pckm_pollcmd).
  The `jal` at 0x1558 calls dtimeout with a0=sym(pckm_reinit), a1=a0 at entry (arg0), a2=0x1, a3=[sym(plbase)]:8, a4=[-0x3bd8]:2.
  The `jal` at 0x1568 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xe9, a2=a2 at entry (arg2), a3=[a0+80], a4=[a0+72]:8.
  The `jal` at 0x1574 calls data_check with a0=ret(pckm_pollcmd), a1=0xfa, a2=?, a3=?.
  The `jal` at 0x1584 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=-0x2, a2=?, a3=?.
  The `jal` at 0x1590 calls data_check with a0=ret(pckm_pollcmd), a1=0x0, a2=?, a3=?.
  The `jal` at 0x15ac calls dtimeout with a0=sym(pckm_reinit), a1=a0 at entry (arg0), a2=0x1, a3=[sym(plbase)]:8, a4=[-0x3bd8]:2.
  The `jal` at 0x15cc calls default_kbd_setting with a0=a0 at entry (arg0), a1=0x0, a2=[[a0+72]:8+52], a3=?.
  The `jal` at 0x15e8 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xf8, a2=?, a3=?.
  The `jal` at 0x15fc calls default_ms_setting with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `bne` branch at 0x1318 targets 0x132c, is taken when at(=[[a0+72]:8+44]) != a3(=[a0+80]), and falls through when at(=[[a0+72]:8+44]) == a3(=[a0+80]).
  The `beq` branch at 0x1324 targets 0x1568, is taken when a1 == v0(=0xaa), and falls through when a1 != v0(=0xaa).
  The `bne` branch at 0x1330 targets 0x1358, is taken when v1(=[[a0+72]:8+40]) != a3(=[a0+80]), and falls through when v1(=[[a0+72]:8+40]) == a3(=[a0+80]).
  The `beq` branch at 0x1338 targets 0x14e4, is taken when s1(=a1) == a1(=0xaa), and falls through when s1(=a1) != a1(=0xaa).
  The `beq` branch at 0x1344 targets 0x14e4, is taken when s1(=a1) == a2(=0xfc), and falls through when s1(=a1) != a2(=0xfc).
  The `beq` branch at 0x1350 targets 0x1360 and is always taken.
  The `beq` branch at 0x1364 targets 0x137c, is taken when a1(=[a0+24]:8) == 0, and falls through when a1(=[a0+24]:8) != 0.
  The `beq` branch at 0x136c targets 0x141c, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x137c targets 0x141c, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `bne` branch at 0x1384 targets 0x1424, is taken when a1(?) != 0, and falls through when a1(?) == 0.
  The `beq` branch at 0x1390 targets 0x1494, is taken when a0(=[a0+64]:8) == 0, and falls through when a0(=[a0+64]:8) != 0.
  The `beq` branch at 0x13a4 targets 0x1494, is taken when a2(=[[[a0+64]:8+40]:8+16]:8) == a1(=[[a0+64]:8+32]:8), and falls through when a2(=[[[a0+64]:8+40]:8+16]:8) != a1(=[[a0+64]:8+32]:8).
  The `beq` branch at 0x13c4 targets 0x14d0, is taken when a3(=[[[a0+64]:8+40]:8+16]:8) == a4(=[[a0+64]:8+32]:8+1), and falls through when a3(=[[[a0+64]:8+40]:8+16]:8) != a4(=[[a0+64]:8+32]:8+1).
  The `beq` branch at 0x13d0 targets 0x1460, is taken when s1(=a1) == a5(=0x14), and falls through when s1(=a1) != a5(=0x14).
  The `beq` branch at 0x13d8 targets 0x1460, is taken when s1(=a1) == a6(=0x76), and falls through when s1(=a1) != a6(=0x76).
  The `bne` branch at 0x13e8 targets 0x1450, is taken when (a7(=[a0+4]) & 0x10) != 0, and falls through when (a7(=[a0+4]) & 0x10) == 0.
  The `beq` branch at 0x1414 targets 0x144c and is always taken.
  The `beq` branch at 0x141c targets 0x1450, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x1468 targets 0x147c, is taken when (a1(=[a0+4]) & 0x10) == 0, and falls through when (a1(=[a0+4]) & 0x10) != 0.
  The `beq` branch at 0x148c targets 0x1450 and is always taken.
  The `beql` branch at 0x14b4 targets 0x14a4, is taken when a5(=[[a0+72]:8+60]+1) == 0, and falls through when a5(=[[a0+72]:8+60]+1) != 0; its branch-likely delay slot `nop` at 0x14b8 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x14c8 targets 0x13ac and is always taken.
  The `beq` branch at 0x14d8 targets 0x13d0 and is always taken.
  The `beq` branch at 0x14fc targets 0x1518, is taken when v0(=ret(data_check)) == 0, and falls through when v0(=ret(data_check)) != 0.
  The `beq` branch at 0x1520 targets 0x1538, is taken when v0(=ret(data_check)) == 0, and falls through when v0(=ret(data_check)) != 0.
  The `beq` branch at 0x1544 targets 0x15c0, is taken when v0(=ret(data_check)) == 0, and falls through when v0(=ret(data_check)) != 0.
  The `beq` branch at 0x1560 targets 0x1450 and is always taken.
  The `beq` branch at 0x157c targets 0x15fc, is taken when v0(=ret(data_check)) == 0, and falls through when v0(=ret(data_check)) != 0.
  The `beq` branch at 0x1598 targets 0x15b4, is taken when v0(=ret(data_check)) == 0, and falls through when v0(=ret(data_check)) != 0.
  The `beq` branch at 0x15b8 targets 0x132c and is always taken.
  The `beq` branch at 0x15dc targets 0x1360, is taken when (a0(=[a0+4]) & 0x2) == 0, and falls through when (a0(=[a0+4]) & 0x2) != 0.
  The `beq` branch at 0x15f4 targets 0x1360 and is always taken.
  The `beq` branch at 0x1604 targets 0x15b8 and is always taken.
  The return at 0x1458 has v0 = one of ?, ret(streams_interrupt), ret(dtimeout).
  The instructions from 0x14e0 to 0x14e0 are not reached by any path from the entry, and their branches are not listed.

- `pckm_intr` in `IP35/usr/cpu/sysgen/IP35boot/ioc3_pckm.o` at 0x160c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc3_pckm.o`.
  Range: 0x160c-0x164c (64 bytes).
  It occupies 64 bytes.
  The `jal` at 0x1624 calls mutex_lock with a0=a0+72, a1=0x19, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x162c calls pckm_intr_lock with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x1638 calls mutex_unlock with a0=a0+72, a1=?, a2=?, a3=?.
  The return at 0x1644 has v0 = ret(mutex_unlock).

- `pckm_intr_lock` in `IP35/usr/cpu/sysgen/IP35boot/ioc3_pckm.o` at 0x164c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc3_pckm.o`.
  Range: 0x164c-0x1790 (324 bytes).
  It occupies 324 bytes.
  10 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x10, including `ld` at 0x164c, `ld` at 0x16b8, `ld` at 0x16f4.
  9 such `lw` accesses load 4 bytes from [a0+16]:8 +0x9c, including `lw` at 0x1650, `lw` at 0x16f8, `lw` at 0x1708.
  The `ld` at 0x16a4 loads 8 bytes from ?.
  The `sw` at 0x16c0 stores 4 bytes to [a0+16]:8 +0x1c.
  The `ld` at 0x16c4 loads 8 bytes from a0 (arg0 at entry) +0x60.
  8 such `sw` accesses store 4 bytes to [a0+16]:8 +0x9c, including `sw` at 0x1700, `sw` at 0x1714, `sw` at 0x1728.
  The `jal` at 0x16a0 calls valid_data with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x16c8 calls ioc3_write_ireg with a0=[a0+96]:8, a1=0x400000, a2=0x0, a3=?.
  The `jal` at 0x16ec calls cmn_err with a0=0x4, a1=sym(.rodata), a2=[[a0+16]:8+156], a3=([[a0+16]:8+156] << 0x2f).
  The `jal` at 0x1710 calls us_delay with a0=0x640, a1=?, a2=[[a0+16]:8+156], a3=[a0+16]:8, a4=([[a0+16]:8+156] | 0x80), a5=[a0+16]:8.
  The `jal` at 0x1740 calls cmn_err with a0=0x4, a1=sym(.rodata), a2=[[a0+16]:8+156], a3=sym(.rodata), a4=([[a0+16]:8+156] << 0x2c).
  The `jal` at 0x1764 calls us_delay with a0=0x640, a1=?, a2=?, a3=?.
  The `bgez` branch at 0x166c targets 0x167c, is taken when at(=([[a0+16]:8+156] << 0x2d)) >= 0 (signed), and falls through when at(=([[a0+16]:8+156] << 0x2d)) < 0 (signed).
  The `bltz` branch at 0x1674 targets 0x16e4, is taken when a3(=([[a0+16]:8+156] << 0x2f)) < 0 (signed), and falls through when a3(=([[a0+16]:8+156] << 0x2f)) >= 0 (signed).
  The `bgez` branch at 0x1684 targets 0x1694, is taken when a4(=([[a0+16]:8+156] << 0x2c)) >= 0 (signed), and falls through when a4(=([[a0+16]:8+156] << 0x2c)) < 0 (signed).
  The `bltz` branch at 0x168c targets 0x1740, is taken when a0(=([[a0+16]:8+156] << 0x2e)) < 0 (signed), and falls through when a0(=([[a0+16]:8+156] << 0x2e)) >= 0 (signed).
  The `bne` branch at 0x16b0 targets 0x169c, is taken when s0(?) < 0x2 (signed), and falls through when s0(?) >= 0x2 (signed).
  The `beq` branch at 0x1738 targets 0x167c and is always taken.
  The `beq` branch at 0x1788 targets 0x1694 and is always taken.
  The return at 0x16dc has v0 = ret(ioc3_write_ireg).

- `pckm_pollcmd` in `IP35/usr/cpu/sysgen/IP35boot/ioc3_pckm.o` at 0x1790 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc3_pckm.o`.
  Range: 0x1790-0x186c (220 bytes).
  It occupies 220 bytes.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x50, including `lw` at 0x17bc, `lw` at 0x17f0.
  The `sw` at 0x17d0 stores 4 bytes to ?.
  The `lw` at 0x1808 loads 4 bytes from ?.
  4 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x48, including `ld` at 0x182c, `ld` at 0x183c, `ld` at 0x184c.
  4 such `ld` accesses load 8 bytes from [a0+72]:8 +0x10, including `ld` at 0x1830, `ld` at 0x1840, `ld` at 0x1850.
  The `jal` at 0x17b4 calls pckm_sendok with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x17e8 calls us_delay with a0=0x32, a1=?, a2=?, a3=?.
  The `beq` branch at 0x17ac targets 0x17d4, is taken when a1 == at(=-0x2), and falls through when a1 != at(=-0x2).
  The `beq` branch at 0x17c0 targets 0x184c, is taken when v0(=[a0+80]) == 0, and falls through when v0(=[a0+80]) != 0.
  The `beq` branch at 0x17c8 targets 0x185c, is taken when v0(=[a0+80]) == v1(=0x1), and falls through when v0(=[a0+80]) != v1(=0x1).
  The `beq` branch at 0x17d8 targets 0x17e8 and is always taken.
  The `beq` branch at 0x17e0 targets 0x1818, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `beq` branch at 0x17f8 targets 0x182c, is taken when v0(=[a0+80]) == 0, and falls through when v0(=[a0+80]) != 0.
  The `beq` branch at 0x1800 targets 0x183c, is taken when v0(=[a0+80]) == a0(=0x1), and falls through when v0(=[a0+80]) != a0(=0x1).
  The `beq` branch at 0x1810 targets 0x17e0, is taken when (s2(=0xffffffffe0000000) & v0(?)) == 0, and falls through when (s2(=0xffffffffe0000000) & v0(?)) != 0.
  The `beq` branch at 0x1834 targets 0x1808 and is always taken.
  The `beq` branch at 0x1844 targets 0x1808 and is always taken.
  The `beq` branch at 0x1854 targets 0x17d0 and is always taken.
  The `beq` branch at 0x1864 targets 0x17d0 and is always taken.
  The return at 0x1824 has v0 = ?.

- `ioc3_pckm_kbdexists` in `IP35/usr/cpu/sysgen/IP35boot/ioc3_pckm.o` at 0x186c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc3_pckm.o`.
  Range: 0x186c-0x18a8 (60 bytes).
  It occupies 60 bytes.
  The `lw` at 0x1878 loads 4 bytes from [sym(.sbss)]:8 +0x28.
  The `ld` at 0x1888 loads 8 bytes from ([sym(.sbss)]:8 + ([[sym(.sbss)]:8+40] << 0x3)) +0x18.
  The `lw` at 0x188c loads 4 bytes from [([sym(.sbss)]:8 + ([[sym(.sbss)]:8+40] << 0x3))+24]:8 +0x4.
  The `beq` branch at 0x1870 targets 0x18a0, is taken when a2(=[sym(.sbss)]:8) == 0, and falls through when a2(=[sym(.sbss)]:8) != 0.
  The `beq` branch at 0x187c targets 0x18a0, is taken when a3(=[[sym(.sbss)]:8+40]) == v0(=0x13), and falls through when a3(=[[sym(.sbss)]:8+40]) != v0(=0x13).
  The return at 0x1898 has v0 = ?.
  The return at 0x18a0 has v0 = 0x0.

- `ioc3_pckm_setleds` in `IP35/usr/cpu/sysgen/IP35boot/ioc3_pckm.o` at 0x18a8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc3_pckm.o`.
  Range: 0x18a8-0x18e8 (64 bytes).
  It occupies 64 bytes.
  The `lw` at 0x18c0 loads 4 bytes from [sym(.sbss)]:8 +0x28.
  The `ld` at 0x18d8 loads 8 bytes from ([sym(.sbss)]:8 + ([[sym(.sbss)]:8+40] << 0x3)) +0x18.
  The `jal` at 0x18d4 calls ioc3_lcl_pckm_setleds with a0=[([sym(.sbss)]:8 + ([[sym(.sbss)]:8+40] << 0x3))+24]:8, a1=a0 at entry (arg0), a2=a2 at entry (arg2), a3=[sym(.sbss)]:8, a4=0x13, a5=[[sym(.sbss)]:8+40].
  The `beq` branch at 0x18b8 targets 0x18dc, is taken when a3(=[sym(.sbss)]:8) == 0, and falls through when a3(=[sym(.sbss)]:8) != 0.
  The `beq` branch at 0x18c4 targets 0x18e0, is taken when a5(=[[sym(.sbss)]:8+40]) == a4(=0x13), and falls through when a5(=[[sym(.sbss)]:8+40]) != a4(=0x13).
  The return at 0x18e0 has v0 = ?.

- `ioc3_pckm_bell` in `IP35/usr/cpu/sysgen/IP35boot/ioc3_pckm.o` at 0x18e8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc3_pckm.o`.
  Range: 0x18e8-0x192c (68 bytes).
  It occupies 68 bytes.
  The `lw` at 0x18fc loads 4 bytes from [sym(.sbss)]:8 +0x28.
  The `lw` at 0x1908 loads 4 bytes from [sym(.sbss)]:8 +0x34.
  The `ld` at 0x191c loads 8 bytes from ([sym(.sbss)]:8 + ([[sym(.sbss)]:8+40] << 0x3)) +0x18.
  The `jal` at 0x1918 calls ioc3_lcl_pckm_setleds with a0=[([sym(.sbss)]:8 + ([[sym(.sbss)]:8+40] << 0x3))+24]:8, a1=([[sym(.sbss)]:8+52] | 0x8), a2=a2 at entry (arg2), a3=[sym(.sbss)]:8, a4=[[sym(.sbss)]:8+40].
  The `beq` branch at 0x18f4 targets 0x1920, is taken when a3(=[sym(.sbss)]:8) == 0, and falls through when a3(=[sym(.sbss)]:8) != 0.
  The `beq` branch at 0x1900 targets 0x1924, is taken when a4(=[[sym(.sbss)]:8+40]) == a1(=0x13), and falls through when a4(=[[sym(.sbss)]:8+40]) != a1(=0x13).
  The return at 0x1924 has v0 = ?.

- `ioc3_gl_setporthandler` in `IP35/usr/cpu/sysgen/IP35boot/ioc3_pckm.o` at 0x192c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc3_pckm.o`.
  Range: 0x192c-0x1958 (44 bytes).
  It occupies 44 bytes.
  The `lw` at 0x1938 loads 4 bytes from [sym(.sbss)]:8 +0x28.
  The `ld` at 0x1948 loads 8 bytes from ([sym(.sbss)]:8 + ([[sym(.sbss)]:8+40] << 0x3)) +0x18.
  The `sd` at 0x194c stores 8 bytes to [([sym(.sbss)]:8 + ([[sym(.sbss)]:8+40] << 0x3))+24]:8 +0x18.
  The `beq` branch at 0x1930 targets 0x1950, is taken when a2(=[sym(.sbss)]:8) == 0, and falls through when a2(=[sym(.sbss)]:8) != 0.
  The `beq` branch at 0x193c targets 0x1950, is taken when a4(=[[sym(.sbss)]:8+40]) == a3(=0x13), and falls through when a4(=[[sym(.sbss)]:8+40]) != a3(=0x13).
  The return at 0x1950 has v0 = ?.

- `ioc3_du_keyboard_port` in `IP35/usr/cpu/sysgen/IP35boot/ioc3_pckm.o` at 0x1958 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc3_pckm.o`.
  Range: 0x1958-0x1960 (8 bytes).
  It occupies 8 bytes.
  The return at 0x1958 has v0 = -0x1.

- `ioc3_lcl_pckm_setleds` in `IP35/usr/cpu/sysgen/IP35boot/ioc3_pckm.o` at 0x1960 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc3_pckm.o`.
  Range: 0x1960-0x19b4 (84 bytes).
  It occupies 84 bytes.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x48, including `ld` at 0x196c, `ld` at 0x1994.
  The `jal` at 0x1980 calls mutex_lock with a0=[a0+72]:8+72, a1=0x19, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x198c calls ioc3_lcl_pckm_setleds_lock with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0x199c calls mutex_unlock with a0=[a0+72]:8+72, a1=?, a2=?, a3=?.
  The return at 0x19ac has v0 = ret(mutex_unlock).

- `ioc3_lcl_pckm_setleds_lock` in `IP35/usr/cpu/sysgen/IP35boot/ioc3_pckm.o` at 0x19b4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc3_pckm.o`.
  Range: 0x19b4-0x1b28 (372 bytes).
  It occupies 372 bytes.
  The `ld` at 0x19c0 loads 8 bytes from a0 (arg0 at entry) +0x48.
  5 such `lw` accesses load 4 bytes from [a0+72]:8 +0x34, including `lw` at 0x19c8, `lw` at 0x1a3c, `lw` at 0x1a5c.
  The `lw` at 0x19f8 loads 4 bytes from [a0+72]:8 +0x38.
  The `sw` at 0x1a24 stores 4 bytes to [a0+72]:8 +0x38.
  2 such `sw` accesses store 4 bytes to [a0+72]:8 +0x34, including `sw` at 0x1a30, `sw` at 0x1a64.
  The `jal` at 0x1a38 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=[[a0+72]:8+52], a2=?, a3=?.
  The `jal` at 0x1a44 calls data_check with a0=ret(pckm_pollcmd), a1=0xfa, a2=?, a3=?.
  The `jal` at 0x1a90 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xed, a2=?, a3=?.
  The `jal` at 0x1a9c calls data_check with a0=ret(pckm_pollcmd), a1=0xfa, a2=?, a3=?.
  The `jal` at 0x1abc calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xf4, a2=?, a3=?.
  The `jal` at 0x1ac8 calls data_check with a0=ret(pckm_pollcmd), a1=0xfa, a2=?, a3=?.
  The `jal` at 0x1adc calls default_kbd_setting with a0=a0 at entry (arg0), a1=0x0, a2=[[a0+72]:8+52], a3=?.
  The `jal` at 0x1afc calls pckm_pollcmd with a0=a0 at entry (arg0), a1=[[a0+72]:8+52], a2=?, a3=?.
  The `jal` at 0x1b08 calls data_check with a0=ret(pckm_pollcmd), a1=0xfa, a2=?, a3=?.
  The `jal` at 0x1b18 calls pckm_reinit_core with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `beq` branch at 0x19e8 targets 0x1a68, is taken when at(=[[a0+72]:8+52]) == a3(?), and falls through when at(=[[a0+72]:8+52]) != a3(?).
  The `beq` branch at 0x19f0 targets 0x1a2c, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `beq` branch at 0x1a04 targets 0x1a14, is taken when a7(?) >= 0xe (signed), and falls through when a7(?) < 0xe (signed).
  The `bne` branch at 0x1a0c targets 0x1a6c, is taken when a4(?) != 0, and falls through when a4(?) == 0.
  The `beq` branch at 0x1a14 targets 0x1a24, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `bne` branch at 0x1a1c targets 0x1a6c, is taken when a5(?) != 0, and falls through when a5(?) == 0.
  The `beq` branch at 0x1a2c targets 0x1a8c and is always taken.
  The `beq` branch at 0x1a4c targets 0x1afc, is taken when v0(=ret(data_check)) == 0, and falls through when v0(=ret(data_check)) != 0.
  The `beq` branch at 0x1a54 targets 0x1a6c, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `beq` branch at 0x1a88 targets 0x1aec, is taken when t1(?) == 0, and falls through when t1(?) != 0.
  The `bne` branch at 0x1aa4 targets 0x1a34, is taken when v0(=ret(data_check)) != 0, and falls through when v0(=ret(data_check)) == 0.
  The `bne` branch at 0x1ab0 targets 0x1a84, is taken when s3(?) < 0x2 (unsigned), and falls through when s3(?) >= 0x2 (unsigned).
  The `bne` branch at 0x1ad0 targets 0x1a84, is taken when v0(=ret(data_check)) != 0, and falls through when v0(=ret(data_check)) == 0.
  The `beq` branch at 0x1ae4 targets 0x1a88 and is always taken.
  The `bne` branch at 0x1aec targets 0x1a5c, is taken when s2(?) != 0, and falls through when s2(?) == 0.
  The `beq` branch at 0x1af4 targets 0x1a6c and is always taken.
  The `bne` branch at 0x1b10 targets 0x1a54, is taken when v0(=ret(data_check)) != 0, and falls through when v0(=ret(data_check)) == 0.
  The `beq` branch at 0x1b20 targets 0x1a54 and is always taken.
  The return at 0x1a7c has v0 = ?.

- `pckm_sendok` in `IP35/usr/cpu/sysgen/IP35boot/ioc3_pckm.o` at 0x1b28 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc3_pckm.o`.
  Range: 0x1b28-0x1bb4 (140 bytes).
  It occupies 140 bytes.
  The `lw` at 0x1b34 loads 4 bytes from a0 (arg0 at entry) +0x50.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x48, including `ld` at 0x1b38, `ld` at 0x1b70.
  2 such `ld` accesses load 8 bytes from [a0+72]:8 +0x10, including `ld` at 0x1b4c, `ld` at 0x1b74.
  2 such `lw` accesses load 4 bytes from [[a0+72]:8+16]:8 +0x9c, including `lw` at 0x1b64, `lw` at 0x1b7c.
  The `jal` at 0x1b68 calls us_delay with a0=0x32, a1=?, a2=[[[a0+72]:8+16]:8+156], a3=?.
  The `beq` branch at 0x1b60 targets 0x1ba8 and is always taken.
  The `beq` branch at 0x1b84 targets 0x1b94, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `bne` branch at 0x1b8c targets 0x1b68, is taken when s0(?) != 0, and falls through when s0(?) == 0.
  The `beq` branch at 0x1bac targets 0x1b84 and is always taken.
  The return at 0x1ba0 has v0 = ?.

- `pckm_flushinp` in `IP35/usr/cpu/sysgen/IP35boot/ioc3_pckm.o` at 0x1bb4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc3_pckm.o`.
  Range: 0x1bb4-0x1bf0 (60 bytes).
  It occupies 60 bytes.
  The `lw` at 0x1bb4 loads 4 bytes from a0 (arg0 at entry) +0x50.
  The `lw` at 0x1bcc loads 4 bytes from ?.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x48, including `ld` at 0x1bd0, `ld` at 0x1be0.
  2 such `ld` accesses load 8 bytes from [a0+72]:8 +0x10, including `ld` at 0x1bd4, `ld` at 0x1be4.
  The `beq` branch at 0x1bb8 targets 0x1be0, is taken when a2(=[a0+80]) == 0, and falls through when a2(=[a0+80]) != 0.
  The `beq` branch at 0x1bc0 targets 0x1bd0, is taken when a2(=[a0+80]) == a3(=0x1), and falls through when a2(=[a0+80]) != a3(=0x1).
  The `beq` branch at 0x1bd8 targets 0x1bc8 and is always taken.
  The `beq` branch at 0x1be8 targets 0x1bc8 and is always taken.
  The return at 0x1bc8 has v0 = ?.

- `data_check` in `IP35/usr/cpu/sysgen/IP35boot/ioc3_pckm.o` at 0x1bf0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc3_pckm.o`.
  Range: 0x1bf0-0x1c68 (120 bytes).
  It occupies 120 bytes.
  The `lw` at 0x1bf4 loads 4 bytes from sym(.rodata) +0x0.
  The `lw` at 0x1c1c loads 4 bytes from sym(.rodata) +0x10.
  The `lw` at 0x1c20 loads 4 bytes from sym(.rodata) +0xc.
  The `lw` at 0x1c30 loads 4 bytes from sym(.rodata) +0x4.
  The `lw` at 0x1c34 loads 4 bytes from sym(.rodata) +0x8.
  The `beq` branch at 0x1bf8 targets 0x1c60 and is never taken: its condition can never hold for these operands, so execution always falls through.
  The `beq` branch at 0x1c00 targets 0x1c18 and is always taken.
  The `beq` branch at 0x1c08 targets 0x1c50 and is never taken: its condition can never hold for these operands, so execution always falls through.
  The `bne` branch at 0x1c10 targets 0x1c54, is taken when a5(?) != 0, and falls through when a5(?) == 0.
  The `beq` branch at 0x1c18 targets 0x1c08, is taken when at(?) == 0, and falls through when at(?) != 0.
  The `bne` branch at 0x1c28 targets 0x1c08, is taken when (v1(=0x4000000) & a0) != 0, and falls through when (v1(=0x4000000) & a0) == 0.
  The `bne` branch at 0x1c40 targets 0x1c08, is taken when a1 != a2(?), and falls through when a1 == a2(?).
  The `beq` branch at 0x1c48 targets 0x1c08 and is always taken.
  The return at 0x1c58 has v0 = 0x1.
  The instructions from 0x1c50 to 0x1c50 are not reached by any path from the entry, and their branches are not listed.
  The instructions from 0x1c60 to 0x1c64 are not reached by any path from the entry, and their branches are not listed.

- `valid_data` in `IP35/usr/cpu/sysgen/IP35boot/ioc3_pckm.o` at 0x1c68 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc3_pckm.o`.
  Range: 0x1c68-0x1e04 (412 bytes).
  It occupies 412 bytes.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x50, including `lw` at 0x1c80, `lw` at 0x1d5c.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0x1ca8, `lw` at 0x1cf8.
  2 such `lw` accesses load 4 bytes from sym(.rodata) +0x0, including `lw` at 0x1ccc, `lw` at 0x1d14.
  2 such `lw` accesses load 4 bytes from sym(.rodata) +0x10, including `lw` at 0x1cd8, `lw` at 0x1d94.
  The `lw` at 0x1d24 loads 4 bytes from sym(.rodata) +0xc.
  The `lw` at 0x1d28 loads 4 bytes from a0 (arg0 at entry) +0x4.
  The `lw` at 0x1d68 loads 4 bytes from sym(.rodata) +0x4.
  The `ld` at 0x1d6c loads 8 bytes from abs 0xffffffffffffc510.
  The `lw` at 0x1d70 loads 4 bytes from sym(.rodata) +0x8.
  The `lw` at 0x1d78 loads 4 bytes from [-0x3af0]:8 +0xa0.
  The `sw` at 0x1d8c stores 4 bytes to [-0x3af0]:8 +0xa0.
  4 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x48, including `ld` at 0x1d98, `ld` at 0x1dd4, `ld` at 0x1de4.
  4 such `ld` accesses load 8 bytes from [a0+72]:8 +0x10, including `ld` at 0x1d9c, `ld` at 0x1dd8, `ld` at 0x1de8.
  The `jal` at 0x1cd0 calls pckm_restart with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x1d44 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xfe, a2=?, a3=?.
  The `jal` at 0x1d88 calls pckm_rx with a0=a0 at entry (arg0), a1=?, a2=0x10, a3=[[-0x3af0]:8+160]+1, a4=[-0x3af0]:8.
  The `beq` branch at 0x1c90 targets 0x1de4, is taken when a2(=[a0+80]) == 0, and falls through when a2(=[a0+80]) != 0.
  The `beq` branch at 0x1c9c targets 0x1df4, is taken when a2(=[a0+80]) == at(=0x1), and falls through when a2(=[a0+80]) != at(=0x1).
  The `beq` branch at 0x1cac targets 0x1da8, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `beq` branch at 0x1cbc targets 0x1da8, is taken when (s6(=0xffffffffe0000000) & s1(?)) == 0, and falls through when (s6(=0xffffffffe0000000) & s1(?)) != 0.
  The `beq` branch at 0x1cc8 targets 0x1d08 and is always taken.
  The `bne` branch at 0x1cdc targets 0x1d14 and is always taken.
  The `beq` branch at 0x1ce8 targets 0x1d98, is taken when a2(=[a0+80]) == 0, and falls through when a2(=[a0+80]) != 0.
  The `beq` branch at 0x1cf0 targets 0x1dd4, is taken when a2(=[a0+80]) == s7(=0x1), and falls through when a2(=[a0+80]) != s7(=0x1).
  The `beq` branch at 0x1cfc targets 0x1da8, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `beq` branch at 0x1d04 targets 0x1da8, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x1d0c targets 0x1ce4 and is never taken: its condition can never hold for these operands, so execution always falls through.
  The `beq` branch at 0x1d1c targets 0x1cd8, is taken when (a1(=0xffffffff80000000) & s1(?)) == 0, and falls through when (a1(=0xffffffff80000000) & s1(?)) != 0.
  The `beq` branch at 0x1d30 targets 0x1d60, is taken when (a1(=0x4000000) & s1(?)) == 0, and falls through when (a1(=0x4000000) & s1(?)) != 0.
  The `beq` branch at 0x1d38 targets 0x1cd0, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `bne` branch at 0x1d50 targets 0x1d0c, is taken when s3(?) < 0x3 (unsigned), and falls through when s3(?) >= 0x3 (unsigned).
  The `beq` branch at 0x1d58 targets 0x1ce8 and is always taken.
  The `beq` branch at 0x1d60 targets 0x1cd0, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x1d90 targets 0x1cdc and is always taken.
  The `beq` branch at 0x1da0 targets 0x1cf8 and is always taken.
  The `beq` branch at 0x1ddc targets 0x1cf8 and is always taken.
  The `beq` branch at 0x1dec targets 0x1ca8 and is always taken.
  The `beq` branch at 0x1dfc targets 0x1ca8 and is always taken.
  The return at 0x1dcc has v0 = one of ?, ret(pckm_pollcmd).
  The instructions from 0x1ce4 to 0x1ce4 are not reached by any path from the entry, and their branches are not listed.

- `set_ports` in `IP35/usr/cpu/sysgen/IP35boot/ioc3_pckm.o` at 0x1e04 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc3_pckm.o`.
  Range: 0x1e04-0x1f64 (352 bytes).
  It occupies 352 bytes.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x30, including `sw` at 0x1e28, `sw` at 0x1f30.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x28, including `sw` at 0x1e34, `sw` at 0x1e7c.
  The `ld` at 0x1e38 loads 8 bytes from a0 (arg0 at entry) +0x20.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x2c, including `sw` at 0x1e3c, `sw` at 0x1ee4.
  The `sw` at 0x1e44 stores 4 bytes to [a0+32]:8 +0x50.
  The `ld` at 0x1e50 loads 8 bytes from a0 (arg0 at entry) +0x18.
  The `sw` at 0x1e68 stores 4 bytes to [a0+24]:8 +0x50.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x28, including `lw` at 0x1e6c, `lw` at 0x1ef4.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x58, including `sw` at 0x1e78, `sw` at 0x1f48.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0x1e80, `ld` at 0x1ea4.
  The `sw` at 0x1e84 stores 4 bytes to ?.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x2c, including `lw` at 0x1ed0, `lw` at 0x1f0c.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x5c, including `sw` at 0x1edc, `sw` at 0x1f60.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x0, including `lw` at 0x1f38, `lw` at 0x1f50.
  The `jal` at 0x1ea0 calls check_port with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1f3c calls cmn_err with a0=0x1, a1=sym(.rodata), a2=[a0], a3=?.
  The `jal` at 0x1f54 calls cmn_err with a0=0x1, a1=sym(.rodata), a2=[a0], a3=?.
  The `beq` branch at 0x1e64 targets 0x1e94 and is always taken.
  The `bne` branch at 0x1e70 targets 0x1f34, is taken when v1(=[a0+40]) != s5(=0x13), and falls through when v1(=[a0+40]) == s5(=0x13).
  The `beq` branch at 0x1e90 targets 0x1ee8, is taken when s1(?) >= 0x2 (signed), and falls through when s1(?) < 0x2 (signed).
  The `beq` branch at 0x1ea8 targets 0x1e6c, is taken when v0(=ret(check_port)) == s4(=0x47), and falls through when v0(=ret(check_port)) != s4(=0x47).
  The `beq` branch at 0x1eb0 targets 0x1e6c, is taken when v0(=ret(check_port)) == s6(=0x83), and falls through when v0(=ret(check_port)) != s6(=0x83).
  The `beq` branch at 0x1eb8 targets 0x1ed0, is taken when v0(=ret(check_port)) == 0, and falls through when v0(=ret(check_port)) != 0.
  The `beq` branch at 0x1ec0 targets 0x1ed0, is taken when v0(=ret(check_port)) == s7(=0x3), and falls through when v0(=ret(check_port)) != s7(=0x3).
  The `bne` branch at 0x1ec8 targets 0x1e80, is taken when v0(=ret(check_port)) != s8(=0x4), and falls through when v0(=ret(check_port)) == s8(=0x4).
  The `bne` branch at 0x1ed4 targets 0x1f4c, is taken when t8(=[a0+44]) != s5(=0x13), and falls through when t8(=[a0+44]) == s5(=0x13).
  The `beq` branch at 0x1ee0 targets 0x1e80 and is always taken.
  The `bne` branch at 0x1f04 targets 0x1f14, is taken when t9(=[a0+40]) != s5(=0x13), and falls through when t9(=[a0+40]) == s5(=0x13).
  The `beq` branch at 0x1f10 targets 0x1f2c, is taken when ra(=[a0+44]) == s5(=0x13), and falls through when ra(=[a0+44]) != s5(=0x13).
  The `beq` branch at 0x1f2c targets 0x1f14 and is always taken.
  The `beq` branch at 0x1f44 targets 0x1e7c and is always taken.
  The `beq` branch at 0x1f5c targets 0x1ee0 and is always taken.
  The return at 0x1f24 has v0 = 0x1.

- `check_port` in `IP35/usr/cpu/sysgen/IP35boot/ioc3_pckm.o` at 0x1f64 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc3_pckm.o`.
  Range: 0x1f64-0x22a0 (828 bytes).
  It occupies 828 bytes.
  The `sw` at 0x1f64 stores 4 bytes to a0 (arg0 at entry) +0x50.
  The `lw` at 0x1fc4 loads 4 bytes from sym(.rodata) +0x0.
  The `lw` at 0x1ff4 loads 4 bytes from sym(.rodata) +0x10.
  The `lw` at 0x2000 loads 4 bytes from sym(.rodata) +0xc.
  The `lw` at 0x201c loads 4 bytes from sym(.rodata) +0x20.
  The `lw` at 0x2020 loads 4 bytes from sym(.rodata) +0x1c.
  The `lw` at 0x2038 loads 4 bytes from sym(.rodata) +0x14.
  The `lw` at 0x203c loads 4 bytes from sym(.rodata) +0x18.
  The `lw` at 0x20f4 loads 4 bytes from sym(.rodata) +0x4.
  The `lw` at 0x20f8 loads 4 bytes from sym(.rodata) +0x8.
  The `jal` at 0x1f7c calls pckm_flushinp with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1fa0 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xf2, a2=?, a3=?.
  The `beq` branch at 0x1fcc targets 0x207c and is never taken: its condition can never hold for these operands, so execution always falls through.
  The `beq` branch at 0x1fd4 targets 0x1ff0 and is always taken.
  The `beq` branch at 0x1fdc targets 0x1fe8, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `beq` branch at 0x1fe8 targets 0x207c and is never taken: its condition can never hold for these operands, so execution always falls through.
  The `beq` branch at 0x1ff8 targets 0x2010, is taken when (a4(=one of 0xffffffff80000000, 0x20000000) & a5(=ret(pckm_pollcmd))) == 0, and falls through when (a4(=one of 0xffffffff80000000, 0x20000000) & a5(=ret(pckm_pollcmd))) != 0.
  The `beq` branch at 0x2008 targets 0x20ec, is taken when (v1(=0x4000000) & a5(=ret(pckm_pollcmd))) == 0, and falls through when (v1(=0x4000000) & a5(=ret(pckm_pollcmd))) != 0.
  The `beq` branch at 0x2010 targets 0x207c and is never taken: its condition can never hold for these operands, so execution always falls through.
  The `beq` branch at 0x2018 targets 0x1fe8, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `bne` branch at 0x2028 targets 0x1fe8, is taken when (a0(=0x2000000) & a5(=ret(pckm_pollcmd))) != 0, and falls through when (a0(=0x2000000) & a5(=ret(pckm_pollcmd))) == 0.
  The `bne` branch at 0x2030 targets 0x1fe8, is taken when s0(?) != s5(=0x13), and falls through when s0(?) == s5(=0x13).
  The `bne` branch at 0x2064 targets 0x2194, is taken when a6(?) < 0x53 (unsigned), and falls through when a6(?) >= 0x53 (unsigned).
  The `beq` branch at 0x206c targets 0x21dc, is taken when t0(?) == 0, and falls through when t0(?) != 0.
  The `beq` branch at 0x2074 targets 0x1fdc and is always taken.
  The `bne` branch at 0x20ec targets 0x2010, is taken when s0(?) != s5(=0x13), and falls through when s0(?) == s5(=0x13).
  The `bne` branch at 0x211c targets 0x217c, is taken when a6(?) < 0x53 (unsigned), and falls through when a6(?) >= 0x53 (unsigned).
  The `beq` branch at 0x2124 targets 0x21ac, is taken when t1(?) == 0, and falls through when t1(?) != 0.
  The `beq` branch at 0x212c targets 0x2010, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `beq` branch at 0x2134 targets 0x2010 and is always taken.
  The `bne` branch at 0x217c targets 0x21c4, is taken when t0(?) != 0, and falls through when t0(?) == 0.
  The `beq` branch at 0x2184 targets 0x2224, is taken when t2(?) == 0, and falls through when t2(?) != 0.
  The `beq` branch at 0x218c targets 0x2010 and is always taken.
  The `bne` branch at 0x2194 targets 0x21f4, is taken when v0(?) != 0, and falls through when v0(?) == 0.
  The `beq` branch at 0x219c targets 0x2260, is taken when t2(?) == 0, and falls through when t2(?) != 0.
  The `beq` branch at 0x21a4 targets 0x1fe8 and is always taken.
  The `bne` branch at 0x21ac targets 0x220c, is taken when t8(?) != 0, and falls through when t8(?) == 0.
  The `beq` branch at 0x21b4 targets 0x2280, is taken when t9(?) == 0, and falls through when t9(?) != 0.
  The `beq` branch at 0x21bc targets 0x2010 and is always taken.
  The `bne` branch at 0x21c4 targets 0x2234, is taken when t3(?) != 0, and falls through when t3(?) == 0.
  The `beq` branch at 0x21d4 targets 0x2010 and is always taken.
  The `bne` branch at 0x21dc targets 0x2244, is taken when t3(?) != 0, and falls through when t3(?) == 0.
  The `beq` branch at 0x21e4 targets 0x2290, is taken when t9(?) == 0, and falls through when t9(?) != 0.
  The `beq` branch at 0x21ec targets 0x1fe8 and is always taken.
  The `bne` branch at 0x21f4 targets 0x2270, is taken when t1(?) != 0, and falls through when t1(?) == 0.
  The `beq` branch at 0x2204 targets 0x1fe8 and is always taken.
  The `bne` branch at 0x220c targets 0x2010, is taken when t2(=0x83) != a6(?), and falls through when t2(=0x83) == a6(?).
  The `beq` branch at 0x2214 targets 0x2010, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `beq` branch at 0x221c targets 0x2010 and is always taken.
  The `bne` branch at 0x2224 targets 0x2010, is taken when t8(=0x47) != a6(?), and falls through when t8(=0x47) == a6(?).
  The `beq` branch at 0x222c targets 0x2010 and is always taken.
  The `bne` branch at 0x2234 targets 0x2010, is taken when a6(?) != 0, and falls through when a6(?) == 0.
  The `beq` branch at 0x223c targets 0x2010 and is always taken.
  The `bne` branch at 0x2248 targets 0x1fe8, is taken when t9(=0x83) != a6(?), and falls through when t9(=0x83) == a6(?).
  The `beq` branch at 0x2250 targets 0x1fe8, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `beq` branch at 0x2258 targets 0x1fe8 and is always taken.
  The `bne` branch at 0x2260 targets 0x1fe8, is taken when at(=0x47) != a6(?), and falls through when at(=0x47) == a6(?).
  The `beq` branch at 0x2268 targets 0x1fe8 and is always taken.
  The `bne` branch at 0x2270 targets 0x1fe8, is taken when a6(?) != 0, and falls through when a6(?) == 0.
  The `beq` branch at 0x2278 targets 0x1fe8 and is always taken.
  The `bne` branch at 0x2280 targets 0x2010, is taken when v1(=0xfa) != a6(?), and falls through when v1(=0xfa) == a6(?).
  The `beq` branch at 0x2288 targets 0x2010 and is always taken.
  The `bne` branch at 0x2290 targets 0x1fe8, is taken when a0(=0xfa) != a6(?), and falls through when a0(=0xfa) == a6(?).
  The `beq` branch at 0x2298 targets 0x1fe8 and is always taken.
  The instructions from 0x207c to 0x20e8 are not reached by any path from the entry, and their branches are not listed.
  The instructions from 0x213c to 0x2178 are not reached by any path from the entry, and their branches are not listed.

- `pckm_restart` in `IP35/usr/cpu/sysgen/IP35boot/ioc3_pckm.o` at 0x22a0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc3_pckm.o`.
  Range: 0x22a0-0x2534 (660 bytes).
  It occupies 660 bytes.
  9 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x50, including `lw` at 0x22a0, `lw` at 0x22ec, `lw` at 0x2318.
  13 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x48, including `ld` at 0x22b0, `ld` at 0x22f0, `ld` at 0x2308.
  2 such `ld` accesses load 8 bytes from ([a0+72]:8 + ([a0+80] << 0x3)) +0x18, including `ld` at 0x22c8, `ld` at 0x22fc.
  The `sw` at 0x2300 stores 4 bytes to [([a0+72]:8 + ([a0+80] << 0x3))+24]:8 +0x50.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x4, including `lw` at 0x2304, `lw` at 0x235c, `lw` at 0x2400.
  3 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x4, including `sw` at 0x2310, `sw` at 0x236c, `sw` at 0x2420.
  2 such `lw` accesses load 4 bytes from [a0+72]:8 +0x28, including `lw` at 0x2314, `lw` at 0x23b8.
  2 such `lw` accesses load 4 bytes from [a0+72]:8 +0x2c, including `lw` at 0x2324, `lw` at 0x2440.
  The `lw` at 0x233c loads 4 bytes from [a0+72]:8 +0x5c.
  3 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x8, including `sw` at 0x2354, `sw` at 0x2418, `sw` at 0x2478.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0xc, including `sw` at 0x2364, `sw` at 0x240c.
  2 such `ld` accesses load 8 bytes from [a0+72]:8 +0x10, including `ld` at 0x2370, `ld` at 0x2394.
  2 such `lw` accesses load 4 bytes from [[a0+72]:8+16]:8 +0x9c, including `lw` at 0x2380, `lw` at 0x2398.
  2 such `sw` accesses store 4 bytes to [[a0+72]:8+16]:8 +0x9c, including `sw` at 0x238c, `sw` at 0x239c.
  2 such `lw` accesses load 4 bytes from [a0+72]:8 +0x30, including `lw` at 0x23c8, `lw` at 0x2450.
  The `sw` at 0x23e0 stores 4 bytes to [a0+72]:8 +0x28.
  The `sw` at 0x23ec stores 4 bytes to [a0+72]:8 +0x58.
  The `lw` at 0x23fc loads 4 bytes from [a0+72]:8 +0x34.
  The `sw` at 0x2470 stores 4 bytes to [a0+72]:8 +0x2c.
  2 such `lw` accesses load 4 bytes from [a0+72]:8 +0x0, including `lw` at 0x2480, `lw` at 0x24c8.
  2 such `ld` accesses load 8 bytes from [a0+72]:8 +0x18, including `ld` at 0x249c, `ld` at 0x24e4.
  2 such `lw` accesses load 4 bytes from [[a0+72]:8+24]:8 +0x4, including `lw` at 0x24a0, `lw` at 0x24e8.
  2 such `sw` accesses store 4 bytes to [[a0+72]:8+24]:8 +0x4, including `sw` at 0x24a8, `sw` at 0x24f0.
  2 such `ld` accesses load 8 bytes from [a0+72]:8 +0x20, including `ld` at 0x250c, `ld` at 0x2520.
  2 such `lw` accesses load 4 bytes from [[a0+72]:8+32]:8 +0x4, including `lw` at 0x2510, `lw` at 0x2524.
  2 such `sw` accesses store 4 bytes to [[a0+72]:8+32]:8 +0x4, including `sw` at 0x251c, `sw` at 0x2530.
  The `jal` at 0x22c4 calls check_port with a0=[([a0+72]:8 + ([a0+80] << 0x3))+24]:8, a1=[a0+80], a2=([a0+80] << 0x3), a3=a3 at entry (arg3).
  The `jal` at 0x2330 calls default_ms_setting with a0=a0 at entry (arg0), a1=?, a2=?, a3=?, a5=[a0+72]:8.
  The `jal` at 0x23f8 calls default_kbd_setting with a0=a0 at entry (arg0), a1=0x0, a2=[[a0+72]:8+52], a3=?, a5=[a0+72]:8, a6=[[a0+72]:8+40], a7=([a0+4] | 0x20).
  The `jal` at 0x2428 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xf8, a2=?, a3=?.
  The `jal` at 0x2484 calls cmn_err with a0=0x1, a1=sym(.rodata), a2=[[a0+72]:8], a3=0x47, a4=[[a0+72]:8+40], a5=[a0+72]:8, a6=0x13.
  The `jal` at 0x24b4 calls cmn_err with a0=0x1, a1=sym(.rodata), a2=?, a3=?, a4=sym(.rodata), a5=[a0+72]:8, a7=[[a0+72]:8+48].
  The `jal` at 0x24cc calls cmn_err with a0=0x1, a1=sym(.rodata), a2=[[a0+72]:8], a3=0x47, a4=0x83, a5=[a0+72]:8.
  The `jal` at 0x24fc calls cmn_err with a0=0x1, a1=sym(.rodata), a2=?, a3=?, a4=sym(.rodata), a5=[a0+72]:8.
  The `beq` branch at 0x22d0 targets 0x23b4, is taken when v0(=ret(check_port)) == a3(=0x47), and falls through when v0(=ret(check_port)) != a3(=0x47).
  The `beq` branch at 0x22dc targets 0x23b4, is taken when v0(=ret(check_port)) == a4(=0x83), and falls through when v0(=ret(check_port)) != a4(=0x83).
  The `beq` branch at 0x22e4 targets 0x243c, is taken when v0(=ret(check_port)) == 0, and falls through when v0(=ret(check_port)) != 0.
  The `beq` branch at 0x231c targets 0x23f0, is taken when a6(=[[a0+72]:8+40]) == a0(=[a0+80]), and falls through when a6(=[[a0+72]:8+40]) != a0(=[a0+80]).
  The `bne` branch at 0x2328 targets 0x2370, is taken when t3(=[[a0+72]:8+44]) != a0(=[a0+80]), and falls through when t3(=[[a0+72]:8+44]) == a0(=[a0+80]).
  The `beq` branch at 0x2344 targets 0x2474, is taken when v0(=[[a0+72]:8+92]) == a3(=0x3), and falls through when v0(=[[a0+72]:8+92]) != a3(=0x3).
  The `beq` branch at 0x234c targets 0x2474, is taken when v0(=[[a0+72]:8+92]) == a0(=0x4), and falls through when v0(=[[a0+72]:8+92]) != a0(=0x4).
  The `bne` branch at 0x23c0 targets 0x247c, is taken when a4(=[[a0+72]:8+40]) != a6(=0x13), and falls through when a4(=[[a0+72]:8+40]) == a6(=0x13).
  The `beq` branch at 0x23d0 targets 0x23e0, is taken when a7(=[[a0+72]:8+48]) == 0, and falls through when a7(=[[a0+72]:8+48]) != 0.
  The `bne` branch at 0x23d8 targets 0x24b4, is taken when a0(=[a0+80]) != 0, and falls through when a0(=[a0+80]) == 0.
  The `beq` branch at 0x23e8 targets 0x22ec and is always taken.
  The `beq` branch at 0x241c targets 0x2430, is taken when (t1(=([a0+4] | 0x1)) & 0x2) == 0, and falls through when (t1(=([a0+4] | 0x1)) & 0x2) != 0.
  The `beq` branch at 0x2434 targets 0x2324 and is always taken.
  The `bne` branch at 0x2448 targets 0x24c4, is taken when t2(=[[a0+72]:8+44]) != t3(=0x13), and falls through when t2(=[[a0+72]:8+44]) == t3(=0x13).
  The `beq` branch at 0x245c targets 0x246c, is taken when t8(=[[a0+72]:8+48]) == 0, and falls through when t8(=[[a0+72]:8+48]) != 0.
  The `bne` branch at 0x2464 targets 0x24fc, is taken when a0(=[a0+80]) != v0(=0x1), and falls through when a0(=[a0+80]) == v0(=0x1).
  The `beq` branch at 0x246c targets 0x22ec and is always taken.
  The `beq` branch at 0x2474 targets 0x2358 and is always taken.
  The `beq` branch at 0x2494 targets 0x250c, is taken when a2(=[a0+80]) == 0, and falls through when a2(=[a0+80]) != 0.
  The `beq` branch at 0x24ac targets 0x23c8 and is always taken.
  The `beq` branch at 0x24bc targets 0x23a4 and is always taken.
  The `beq` branch at 0x24dc targets 0x2520, is taken when a2(=[a0+80]) == 0, and falls through when a2(=[a0+80]) != 0.
  The `beq` branch at 0x24f4 targets 0x2450 and is always taken.
  The `beq` branch at 0x2504 targets 0x23a4 and is always taken.
  The `beq` branch at 0x2518 targets 0x24ac and is always taken.
  The `beq` branch at 0x252c targets 0x24f4 and is always taken.
  The return at 0x23ac has v0 = one of ([[[a0+72]:8+16]:8+156] | one of 0x40000, 0x80000), ret(cmn_err).

- `ioc3_pckm_rmalias` in `IP35/usr/cpu/sysgen/IP35boot/ioc3_pckm.o` at 0x2534 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc3_pckm.o`.
  Range: 0x2534-0x25f8 (196 bytes).
  It occupies 196 bytes.
  5 such `lw` accesses load 4 bytes from ?, including `lw` at 0x2558, `lw` at 0x2578, `lw` at 0x258c.
  5 such `ld` accesses load 8 bytes from ?, including `ld` at 0x2564, `ld` at 0x2588, `ld` at 0x25a4.
  The `sw` at 0x25c8 stores 4 bytes to ?.
  The `jal` at 0x25a8 calls pckm_rmalias with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=?, a5=0x13.
  The `jal` at 0x25b8 calls mutex_lock with a0=?, a1=0x19, a2=?, a3=?.
  The `jal` at 0x25d4 calls device_controller_num_set with a0=?, a1=-0x1, a2=?, a3=?.
  The `jal` at 0x25dc calls mutex_unlock with a0=?, a1=?, a2=?, a3=?.
  The `beq` branch at 0x2548 targets 0x25e4, is taken when at(=[sym(.sdata)+8]:8) == 0, and falls through when at(=[sym(.sdata)+8]:8) != 0.
  The `beq` branch at 0x2550 targets 0x2570 and is always taken.
  The `bne` branch at 0x255c targets 0x2584, is taken when a3(?) != a5(=0x13), and falls through when a3(?) == a5(=0x13).
  The `beq` branch at 0x2568 targets 0x25e8, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0x2570 targets 0x2558, is taken when a1 == 0, and falls through when a1 != 0.
  The `beq` branch at 0x257c targets 0x2564, is taken when a3(?) == a5(=0x13), and falls through when a3(?) != a5(=0x13).
  The `bne` branch at 0x2590 targets 0x2564, is taken when v0(?) != a0, and falls through when v0(?) == a0.
  The `bnel` branch at 0x25a0 targets 0x2568, is taken when (t8(?) & 0x2) != 0, and falls through when (t8(?) & 0x2) == 0; its branch-likely delay slot `ld s0,104(s0)` at 0x25a4 runs only when taken and is annulled on fall-through.
  The return at 0x25f0 has v0 = ?.

- `ioc_pckm_add_hwgraph_alias` in `IP35/usr/cpu/sysgen/IP35boot/ioc3_pckm.o` at 0x25f8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/ioc3_pckm.o`.
  Range: 0x25f8-0x270c (276 bytes).
  It occupies 276 bytes.
  The `jal` at 0x261c calls ioc3_pckm_rmalias with a0=a1 at entry (arg1), a1=a2 at entry (arg2), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x2628 calls ioc4_pckm_rmalias with a0=a1 at entry (arg1), a1=a2 at entry (arg2), a2=?, a3=?.
  The `jal` at 0x2634 calls usb_pckm_rmalias with a0=a1 at entry (arg1), a1=a2 at entry (arg2), a2=?, a3=?.
  The `jal` at 0x264c calls sprintf with a0=sp-64, a1=sym(.rodata), a2=a1 at entry (arg1), a3=?.
  The `jal` at 0x265c calls hwgraph_traverse with a0=[sym(hwgraph_root)], a1=sp-64, a2=sp-48, a3=?.
  The `jal` at 0x2690 calls hwgraph_edge_add with a0=?, a1=a0 at entry (arg0), a2=sym(.rodata), a3=?.
  The `jal` at 0x26b8 calls hwgraph_edge_remove with a0=?, a1=sym(.rodata), a2=0x0, a3=?.
  The `jal` at 0x26dc calls sprintf with a0=sp-64, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x26f0 calls hwgraph_path_add with a0=[sym(hwgraph_root)], a1=sp-64, a2=sp-48, a3=?.
  The `beq` branch at 0x263c targets 0x26d4, is taken when s0(=a1) == 0, and falls through when s0(=a1) != 0.
  The `beq` branch at 0x2668 targets 0x26ec, is taken when v0(=ret(hwgraph_traverse)) == a2(=0x2), and falls through when v0(=ret(hwgraph_traverse)) != a2(=0x2).
  The `beq` branch at 0x2670 targets 0x26ac, is taken when s0(=a1) == 0, and falls through when s0(=a1) != 0.
  The `beq` branch at 0x2678 targets 0x26c8, is taken when s1(=a2) == 0, and falls through when s1(=a2) != 0.
  The `beq` branch at 0x26ac targets 0x2700, is taken when s1(=a2) == 0, and falls through when s1(=a2) != 0.
  The `bne` branch at 0x26c0 targets 0x2680, is taken when s1(=a2) != 0, and falls through when s1(=a2) == 0.
  The `beq` branch at 0x26cc targets 0x2684 and is always taken.
  The `beq` branch at 0x26e4 targets 0x2658 and is always taken.
  The `beq` branch at 0x26f8 targets 0x2670 and is always taken.
  The `beq` branch at 0x2704 targets 0x26b4 and is always taken.
  The return at 0x26a4 has v0 = 0x0.
