# Readings: `IP32/usr/cpu/sysgen/IP32boot/mhpckm.o`

One entry per routine, filed here from the reading batches by binary.

- `pckminit` in `IP32/usr/cpu/sysgen/IP32boot/mhpckm.o` at 0x8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mhpckm.o`.
  Range: 0x8-0x10 (8 bytes).
  It occupies 8 bytes.
  The return at 0x8 has v0 = ?.

- `pckm_open` in `IP32/usr/cpu/sysgen/IP32boot/mhpckm.o` at 0x500 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mhpckm.o`.
  Range: 0x500-0x60c (268 bytes).
  It occupies 268 bytes.
  The `lw` at 0x53c loads 4 bytes from a1 (arg1 at entry) +0x0.
  2 such `lw` accesses load 4 bytes from ret(device_info_get) +0x0, including `lw` at 0x564, `lw` at 0x5a8.
  The `sw` at 0x590 stores 4 bytes to a0 (arg0 at entry) +0x14.
  The `sw` at 0x594 stores 4 bytes to ret(WR) +0x14.
  The `sw` at 0x598 stores 4 bytes to ret(device_info_get) +0x1c.
  The `sw` at 0x5a4 stores 4 bytes to ret(device_info_get) +0x20.
  The `sw` at 0x5b8 stores 4 bytes to ret(device_info_get) +0x0.
  The `jal` at 0x514 calls WR with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x55c calls device_info_get with a0=[a1], a1=?, a2=?, a3=0x13.
  The `jal` at 0x5a0 calls mutex_lock with a0=ret(device_info_get)+16, a1=0x19, a2=ret(WR), a3=a0 at entry (arg0).
  The `jal` at 0x5bc calls default_ms_setting with a0=[sym(mh_mouse_port)], a1=?, a2=?, a3=?, a4=([ret(device_info_get)] | 0x2).
  The `jal` at 0x5c4 calls pckm_enable_interrupt with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x5cc calls mutex_unlock with a0=ret(device_info_get)+16, a1=?, a2=?, a3=?.
  The `jal` at 0x5e4 calls pckm_pollcmd with a0=[sym(mh_keyboard_port)], a1=0xed, a2=?, a3=?, a4=([ret(device_info_get)] | 0x2).
  The `jal` at 0x5f0 calls pckm_pollcmd with a0=[sym(mh_keyboard_port)], a1=[sym(.sbss)+8], a2=?, a3=?.
  The `jal` at 0x5fc calls pckm_pollcmd with a0=[sym(mh_keyboard_port)], a1=0xf8, a2=?, a3=?.
  The `beq` branch at 0x51c targets 0x53c, is taken when s3(=a3) == 0, and falls through when s3(=a3) != 0.
  The `beq` branch at 0x54c targets 0x55c, is taken when (at(?) & 0x1ff) == 0, and falls through when (at(?) & 0x1ff) != 0.
  The `beq` branch at 0x554 targets 0x52c and is always taken.
  The `beq` branch at 0x570 targets 0x580, is taken when (a1(=[ret(device_info_get)]) & 0x2) == 0, and falls through when (a1(=[ret(device_info_get)]) & 0x2) != 0.
  The `beq` branch at 0x578 targets 0x52c and is always taken.
  The `beq` branch at 0x5b4 targets 0x5dc, is taken when (a4(=([ret(device_info_get)] | 0x2)) & 0x4) == 0, and falls through when (a4(=([ret(device_info_get)] | 0x2)) & 0x4) != 0.
  The `beq` branch at 0x5d4 targets 0x528 and is always taken.
  The `beq` branch at 0x604 targets 0x5c4 and is always taken.
  The return at 0x534 has v0 = one of 0x0, 0x6, 0x10, 0x13.

- `pckm_close` in `IP32/usr/cpu/sysgen/IP32boot/mhpckm.o` at 0x60c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mhpckm.o`.
  Range: 0x60c-0x734 (296 bytes).
  It occupies 296 bytes.
  The `lw` at 0x614 loads 4 bytes from a0 (arg0 at entry) +0x14.
  3 such `lw` accesses load 4 bytes from [a0+20] +0x0, including `lw` at 0x618, `lw` at 0x634, `lw` at 0x668.
  The `lw` at 0x630 loads 4 bytes from [a0+20] +0x8.
  2 such `sw` accesses store 4 bytes to [a0+20] +0x0, including `sw` at 0x648, `sw` at 0x688.
  The `lw` at 0x658 loads 4 bytes from [a0+20] +0x24.
  The `lw` at 0x65c loads 4 bytes from [a0+20] +0x2c.
  The `sw` at 0x664 stores 4 bytes to [a0+20] +0x24.
  The `sw` at 0x670 stores 4 bytes to [a0+20] +0x1c.
  The `sw` at 0x678 stores 4 bytes to [a0+20] +0x20.
  The `sw` at 0x680 stores 4 bytes to [a0+20] +0x2c.
  The `jal` at 0x62c calls untimeout with a0=[[a0+20]+8], a1=a1 at entry (arg1), a2=[[a0+20]], a3=a3 at entry (arg3).
  The `jal` at 0x64c calls str_unbcall with a0=a0 at entry (arg0), a1=?, a2=[[a0+20]], a3=?.
  The `jal` at 0x654 calls freemsg with a0=[[a0+20]+36], a1=?, a2=?, a3=?.
  The `jal` at 0x660 calls freemsg with a0=[[a0+20]+44], a1=?, a2=?, a3=?.
  The `jal` at 0x690 calls pckm_pollcmd with a0=[sym(mh_mouse_port)], a1=0xff, a2=?, a3=?.
  The `jal` at 0x6b4 calls mutex_lock with a0=[a0+20]+16, a1=0x19, a2=?, a3=?.
  The `jal` at 0x6c4 calls pckm_pollcmd with a0=[sym(mh_keyboard_port)], a1=0xed, a2=?, a3=?.
  The `jal` at 0x6d0 calls pckm_pollcmd with a0=[sym(mh_keyboard_port)], a1=[sym(.sbss)+8], a2=?, a3=?.
  The `jal` at 0x6dc calls pckm_pollcmd with a0=[sym(mh_keyboard_port)], a1=0xfa, a2=?, a3=?.
  The `jal` at 0x6e8 calls pckm_pollcmd with a0=[sym(mh_keyboard_port)], a1=0xfc, a2=?, a3=?.
  The `jal` at 0x6f4 calls pckm_pollcmd with a0=[sym(mh_keyboard_port)], a1=0x14, a2=?, a3=?.
  The `jal` at 0x700 calls pckm_pollcmd with a0=[sym(mh_keyboard_port)], a1=0xfc, a2=?, a3=?.
  The `jal` at 0x70c calls pckm_pollcmd with a0=[sym(mh_keyboard_port)], a1=0x76, a2=?, a3=?.
  The `jal` at 0x71c calls pckm_pollcmd with a0=[sym(mh_keyboard_port)], a1=0xf4, a2=?, a3=?.
  The `jal` at 0x724 calls mutex_unlock with a0=[a0+20]+16, a1=?, a2=?, a3=?.
  The `beq` branch at 0x624 targets 0x638, is taken when (a2(=[[a0+20]]) & 0x10) == 0, and falls through when (a2(=[[a0+20]]) & 0x10) != 0.
  The `beq` branch at 0x63c targets 0x654, is taken when (a2(=[[a0+20]]) & 0x8) == 0, and falls through when (a2(=[[a0+20]]) & 0x8) != 0.
  The `beq` branch at 0x684 targets 0x6ac, is taken when (a1(?) & 0x4) == 0, and falls through when (a1(?) & 0x4) != 0.
  The `beq` branch at 0x72c targets 0x69c and is always taken.
  The return at 0x6a4 has v0 = 0x0.

- `pckm_wput` in `IP32/usr/cpu/sysgen/IP32boot/mhpckm.o` at 0x734 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mhpckm.o`.
  Range: 0x734-0x960 (556 bytes).
  It occupies 556 bytes.
  The `lw` at 0x740 loads 4 bytes from a0 (arg0 at entry) +0x14.
  The `lw` at 0x768 loads 4 bytes from a1 (arg1 at entry) +0x14.
  The `lbu` at 0x76c loads 1 byte from [a1+20] +0x12.
  8 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0xc, including `lw` at 0x794, `lw` at 0x7c8, `lw` at 0x7f0.
  6 such `lbu` accesses load 1 byte from [a1+12] +0x0, including `lbu` at 0x798, `lbu` at 0x7d8, `lbu` at 0x7f4.
  4 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x10, including `lw` at 0x7c4, `lw` at 0x810, `lw` at 0x8fc.
  2 such `sw` accesses store 4 bytes to a1 (arg1 at entry) +0xc, including `sw` at 0x818, `sw` at 0x838.
  The `lbu` at 0x82c loads 1 byte from ?.
  The `lw` at 0x868 loads 4 bytes from [a0+20] +0x0.
  The `sb` at 0x8d8 stores 1 byte to [a1+12] +0x0.
  2 such `sw` accesses store 4 bytes to a1 (arg1 at entry) +0x10, including `sw` at 0x90c, `sw` at 0x940.
  2 such `sb` accesses store 1 byte to [a1+16] +0x0, including `sb` at 0x918, `sb` at 0x954.
  The `lw` at 0x948 loads 4 bytes from [a0+20] +0x30.
  The `jal` at 0x760 calls mutex_lock with a0=[a0+20]+16, a1=0x19, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x7a8 calls mutex_unlock with a0=[a0+20]+16, a1=0xd, a2=?, a3=?.
  The `jal` at 0x7b4 calls sdrv_error with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0x7e8 calls pckm_reinit with a0=[sym(mh_mouse_port)], a1=[[a1+12]]:1, a2=?, a3=?.
  The `jal` at 0x804 calls pckm_reinit with a0=[sym(mh_keyboard_port)], a1=[[a1+12]]:1, a2=?, a3=?.
  The `jal` at 0x828 calls pckm_setleds with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x83c calls freemsg with a0=a1 at entry (arg1), a1=?, a2=?, a3=?.
  The `jal` at 0x844 calls mutex_unlock with a0=[a0+20]+16, a1=?, a2=?, a3=?.
  The `jal` at 0x88c calls freemsg with a0=a1 at entry (arg1), a1=?, a2=?, a3=?.
  The `jal` at 0x8b0 calls flushq with a0=a0 at entry (arg0), a1=0x0, a2=[a0+20], a3=?.
  The `jal` at 0x8d4 calls RD with a0=a0 at entry (arg0), a1=[[a1+12]]:1, a2=?, a3=?.
  The `jal` at 0x8e0 calls flushq with a0=ret(RD), a1=0x1, a2=?, a3=?.
  The `jal` at 0x8ec calls qreply with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0x914 calls qreply with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=[[a1+12]]:1, a3=0xde, a7=0x83.
  The `jal` at 0x924 calls freemsg with a0=a1 at entry (arg1), a1=[[a1+12]]:1, a2=?, a3=?.
  The `jal` at 0x950 calls qreply with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=[[a1+12]]:1, a4=0x12.
  The `beq` branch at 0x770 targets 0x7c4, is taken when v0(=[[a1+20]+18]:1) == 0, and falls through when v0(=[[a1+20]+18]:1) != 0.
  The `beq` branch at 0x778 targets 0x868, is taken when v0(=[[a1+20]+18]:1) == v1(=0xe), and falls through when v0(=[[a1+20]+18]:1) != v1(=0xe).
  The `beq` branch at 0x784 targets 0x89c, is taken when v0(=[[a1+20]+18]:1) == a0(=0x86), and falls through when v0(=[[a1+20]+18]:1) != a0(=0x86).
  The `bne` branch at 0x78c targets 0x7a8, is taken when v0(=[[a1+20]+18]:1) != a1(=0xd), and falls through when v0(=[[a1+20]+18]:1) == a1(=0xd).
  The `beq` branch at 0x7a0 targets 0x8fc, is taken when a2(=[[a1+12]]:1) == a3(=0xde), and falls through when a2(=[[a1+12]]:1) != a3(=0xde).
  The `beq` branch at 0x7bc targets 0x850 and is always taken.
  The `beq` branch at 0x7d0 targets 0x820, is taken when v0(=[a1+12]) >= a0(=[a1+16]) (unsigned), and falls through when v0(=[a1+12]) < a0(=[a1+16]) (unsigned).
  The `beq` branch at 0x7e0 targets 0x7fc, is taken when (a1(=[[a1+12]]:1) & 0x1) == 0, and falls through when (a1(=[[a1+12]]:1) & 0x1) != 0.
  The `beq` branch at 0x7fc targets 0x810, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0x820 targets 0x83c, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x870 targets 0x88c, is taken when (a2(=[[a0+20]]) & 0x4) == 0, and falls through when (a2(=[[a0+20]]) & 0x4) != 0.
  The `beq` branch at 0x884 targets 0x934, is taken when a3(=[[a1+12]]:1) == a4(=0x12), and falls through when a3(=[[a1+12]]:1) != a4(=0x12).
  The `beq` branch at 0x894 targets 0x844 and is always taken.
  The `beq` branch at 0x8a8 targets 0x8c0, is taken when (a1(=[[a1+12]]:1) & 0x2) == 0, and falls through when (a1(=[[a1+12]]:1) & 0x2) != 0.
  The `beq` branch at 0x8c4 targets 0x924, is taken when (a1(=[[a1+12]]:1) & 0x1) == 0, and falls through when (a1(=[[a1+12]]:1) & 0x1) != 0.
  The `beq` branch at 0x8f4 targets 0x844 and is always taken.
  The `beq` branch at 0x91c targets 0x844 and is always taken.
  The `beq` branch at 0x92c targets 0x844 and is always taken.
  The `beq` branch at 0x958 targets 0x844 and is always taken.
  The return at 0x860 has v0 = 0x0.

- `pckm_getbp` in `IP32/usr/cpu/sysgen/IP32boot/mhpckm.o` at 0x960 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mhpckm.o`.
  Range: 0x960-0xa68 (264 bytes).
  It occupies 264 bytes.
  The `lw` at 0x96c loads 4 bytes from a0 (arg0 at entry) +0x2c.
  2 such `lw` accesses load 4 bytes from [a0+44] +0x10, including `lw` at 0x98c, `lw` at 0x9dc.
  The `lw` at 0x990 loads 4 bytes from [a0+44] +0xc.
  2 such `lw` accesses load 4 bytes from [a0+44] +0x14, including `lw` at 0x9a4, `lw` at 0x9e0.
  The `lw` at 0x9e4 loads 4 bytes from [[a0+44]+20] +0x8.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x2c, including `sw` at 0xa28, `sw` at 0xa64.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x0, including `lw` at 0xa2c, `lw` at 0xa50.
  The `lw` at 0xa3c loads 4 bytes from a0 (arg0 at entry) +0x1c.
  The `sw` at 0xa5c stores 4 bytes to a0 (arg0 at entry) +0x0.
  The `jal` at 0x9bc calls allocb with a0=0xc, a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0xa1c calls str_conmsg with a0=a0+36, a1=a0+40, a2=[a0+44], a3=?.
  The `jal` at 0xa40 calls str_allocb with a0=0xc, a1=[a0+28], a2=0x3, a3=?.
  The `beq` branch at 0x984 targets 0x9a8, is taken when s1(=[a0+44]) == 0, and falls through when s1(=[a0+44]) != 0.
  The `bne` branch at 0x998 targets 0x9a8, is taken when at(=[[a0+44]+12]) < v0(=[[a0+44]+16]) (unsigned), and falls through when at(=[[a0+44]+12]) >= v0(=[[a0+44]+16]) (unsigned).
  The `beq` branch at 0x9a0 targets 0x9e4 and is always taken.
  The `beq` branch at 0x9a8 targets 0x9bc and is always taken.
  The `bne` branch at 0x9b4 targets 0xa2c, is taken when v0(=0x3) != s2(=a1), and falls through when v0(=0x3) == s2(=a1).
  The `beq` branch at 0x9c4 targets 0x9b0, is taken when v0(=ret(allocb)) == 0, and falls through when v0(=ret(allocb)) != 0.
  The `beq` branch at 0x9cc targets 0xa60, is taken when s1(=[a0+44]) == 0, and falls through when s1(=[a0+44]) != 0.
  The `bne` branch at 0x9d4 targets 0xa18, is taken when s0(?) != 0, and falls through when s0(?) == 0.
  The `beq` branch at 0x9ec targets 0xa18, is taken when v0(=[[a0+44]+16]) >= v1(=[[[a0+44]+20]+8]) (unsigned), and falls through when v0(=[[a0+44]+16]) < v1(=[[[a0+44]+20]+8]) (unsigned).
  The `beq` branch at 0xa24 targets 0x9f4 and is always taken.
  The `bne` branch at 0xa34 targets 0x9cc, is taken when (a0(=[a0]) & 0x8) != 0, and falls through when (a0(=[a0]) & 0x8) == 0.
  The `bne` branch at 0xa48 targets 0x9cc, is taken when v0(=ret(str_allocb)) != 0, and falls through when v0(=ret(str_allocb)) == 0.
  The `beq` branch at 0xa58 targets 0x9cc and is always taken.
  The `beq` branch at 0xa60 targets 0x9f4 and is always taken.
  The return at 0xa0c has v0 = ?.
  The instructions from 0xa14 to 0xa14 are not reached by any path from the entry, and their branches are not listed.

- `pckm_rsrv_timer` in `IP32/usr/cpu/sysgen/IP32boot/mhpckm.o` at 0xa68 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mhpckm.o`.
  Range: 0xa68-0xafc (148 bytes).
  It occupies 148 bytes.
  The `lw` at 0xa68 loads 4 bytes from a0 (arg0 at entry) +0x0.
  The `lw` at 0xa84 loads 4 bytes from a0 (arg0 at entry) +0x1c.
  The `lw` at 0xa88 loads 4 bytes from [a0+28] +0x1c.
  The `sw` at 0xab0 stores 4 bytes to a0 (arg0 at entry) +0x8.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x0, including `sw` at 0xad8, `sw` at 0xaf8.
  The `jal` at 0xaa8 calls dtimeout with a0=sym(pckm_rsrv_timer), a1=a0 at entry (arg0), a2=0x2, a3=[sym(plbase)], a4=0x0, a5=[a0].
  The `jal` at 0xadc calls streams_interrupt with a0=sym(qenable), a1=[a0+28], a2=0x0, a3=0x0, a5=[a0].
  The `beq` branch at 0xa7c targets 0xaec, is taken when (a5(=[a0]) & 0x2) == 0, and falls through when (a5(=[a0]) & 0x2) != 0.
  The `beq` branch at 0xa90 targets 0xac4, is taken when (v0(=[[a0+28]+28]) & 0x40) == 0, and falls through when (v0(=[[a0+28]+28]) & 0x40) != 0.
  The `beq` branch at 0xae4 targets 0xab8 and is always taken.
  The `beq` branch at 0xaf4 targets 0xab4 and is always taken.
  The return at 0xabc has v0 = one of ?, ret(streams_interrupt).

- `pckm_rsrv` in `IP32/usr/cpu/sysgen/IP32boot/mhpckm.o` at 0xafc (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mhpckm.o`.
  Range: 0xafc-0xc44 (328 bytes).
  It occupies 328 bytes.
  The `lw` at 0xb04 loads 4 bytes from a0 (arg0 at entry) +0x14.
  The `lw` at 0xb2c loads 4 bytes from a0 (arg0 at entry) +0xc.
  2 such `lw` accesses load 4 bytes from [a0+20] +0x0, including `lw` at 0xb40, `lw` at 0xb88.
  The `sw` at 0xb5c stores 4 bytes to [a0+20] +0x0.
  2 such `lw` accesses load 4 bytes from [a0+20] +0x2c, including `lw` at 0xb60, `lw` at 0xbf4.
  The `lw` at 0xb6c loads 4 bytes from [[a0+20]+44] +0x10.
  The `lw` at 0xb70 loads 4 bytes from [[a0+20]+44] +0xc.
  3 such `lw` accesses load 4 bytes from [a0+20] +0x24, including `lw` at 0xb7c, `lw` at 0xbfc, `lw` at 0xc40.
  The `sw` at 0xbcc stores 4 bytes to [a0+20] +0x24.
  The `sw` at 0xc34 stores 4 bytes to [a0+20] +0x2c.
  The `jal` at 0xb20 calls mutex_lock with a0=[a0+20]+16, a1=0x19, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xb28 calls canput with a0=[a0+12], a1=?, a2=?, a3=?.
  The `jal` at 0xb38 calls enableok with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xb58 calls str_unbcall with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xba8 calls mutex_unlock with a0=[a0+20]+16, a1=?, a2=?, a3=?.
  The `jal` at 0xbd0 calls mutex_unlock with a0=[a0+20]+16, a1=[[a0+20]+36], a2=?, a3=?.
  The `jal` at 0xbdc calls putnext with a0=a0 at entry (arg0), a1=[[a0+20]+36], a2=?, a3=?.
  The `jal` at 0xbe8 calls mutex_lock with a0=[a0+20]+16, a1=0x19, a2=?, a3=?.
  The `jal` at 0xc00 calls noenable with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xc08 calls mutex_unlock with a0=[a0+20]+16, a1=?, a2=?, a3=?.
  The `jal` at 0xc18 calls pckm_getbp with a0=[a0+20], a1=0x1, a2=?, a3=?.
  The `jal` at 0xc2c calls str_conmsg with a0=[a0+20]+36, a1=[a0+20]+40, a2=[[a0+20]+44], a3=[[[a0+20]+44]+16].
  The `beq` branch at 0xb30 targets 0xc00, is taken when v0(=ret(canput)) == 0, and falls through when v0(=ret(canput)) != 0.
  The `beq` branch at 0xb48 targets 0xb60, is taken when (v0(=[[a0+20]]) & 0x8) == 0, and falls through when (v0(=[[a0+20]]) & 0x8) != 0.
  The `beq` branch at 0xb64 targets 0xbf8, is taken when a2(=[[a0+20]+44]) == 0, and falls through when a2(=[[a0+20]+44]) != 0.
  The `beq` branch at 0xb78 targets 0xb98, is taken when a0(=[[[a0+20]+44]+12]) >= a3(=[[[a0+20]+44]+16]) (unsigned), and falls through when a0(=[[[a0+20]+44]+12]) < a3(=[[[a0+20]+44]+16]) (unsigned).
  The `beq` branch at 0xb80 targets 0xc2c, is taken when a1(=[[a0+20]+36]) == 0, and falls through when a1(=[[a0+20]+36]) != 0.
  The `beq` branch at 0xb90 targets 0xc2c, is taken when (a4(=[[a0+20]]) & 0x10) == 0, and falls through when (a4(=[[a0+20]]) & 0x10) != 0.
  The `bne` branch at 0xb98 targets 0xbcc, is taken when a1(=[[a0+20]+36]) != 0, and falls through when a1(=[[a0+20]+36]) == 0.
  The `beq` branch at 0xba0 targets 0xc18, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0xbf0 targets 0xba0 and is always taken.
  The `beq` branch at 0xbf8 targets 0xb98 and is always taken.
  The `beq` branch at 0xc10 targets 0xbb4 and is always taken.
  The `beq` branch at 0xc20 targets 0xba8 and is always taken.
  The `beq` branch at 0xc3c targets 0xb98 and is always taken.
  The return at 0xbc4 has v0 = 0x0.
  The instructions from 0xc28 to 0xc28 are not reached by any path from the entry, and their branches are not listed.

- `pckm_reinit` in `IP32/usr/cpu/sysgen/IP32boot/mhpckm.o` at 0xc44 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mhpckm.o`.
  Range: 0xc44-0xd38 (244 bytes).
  It occupies 244 bytes.
  The `lw` at 0xcfc loads 4 bytes from table(sym(kmports)) +0x0.
  The `jal` at 0xc5c calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xf5, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xc68 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xed, a2=?, a3=?.
  The `jal` at 0xc74 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=[sym(.sbss)+8], a2=?, a3=?.
  The `jal` at 0xc80 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xf0, a2=?, a3=?.
  The `jal` at 0xc8c calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0x3, a2=?, a3=?.
  The `jal` at 0xc98 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xfa, a2=?, a3=?.
  The `jal` at 0xca4 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xfc, a2=?, a3=?.
  The `jal` at 0xcb0 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0x14, a2=?, a3=?.
  The `jal` at 0xcbc calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xfc, a2=?, a3=?.
  The `jal` at 0xcc8 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0x76, a2=?, a3=?.
  The `jal` at 0xcd4 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xf4, a2=?, a3=?.
  The `jal` at 0xd0c calls pckm_pollcmd with a0=[sym(mh_keyboard_port)], a1=0xf8, a2=?, a3=?.
  The `jal` at 0xd14 calls pckm_enable_interrupt with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xd28 calls default_ms_setting with a0=[sym(mh_mouse_port)], a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `bne` branch at 0xc54 targets 0xd28, is taken when at(=[sym(mh_keyboard_port)]) != a0, and falls through when at(=[sym(mh_keyboard_port)]) == a0.
  The `beq` branch at 0xd04 targets 0xd14, is taken when (v0(=entry(sym(kmports))) & 0x2) == 0, and falls through when (v0(=entry(sym(kmports))) & 0x2) != 0.
  The `beq` branch at 0xd30 targets 0xd14 and is always taken.
  The return at 0xd20 has v0 = ret(pckm_enable_interrupt).

- `pckm_rx` in `IP32/usr/cpu/sysgen/IP32boot/mhpckm.o` at 0xd38 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mhpckm.o`.
  Range: 0xd38-0xef4 (444 bytes).
  It occupies 444 bytes.
  4 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x0, including `lw` at 0xd64, `lw` at 0xdb8, `lw` at 0xdd8.
  The `lw` at 0xd74 loads 4 bytes from a0 (arg0 at entry) +0x2c.
  4 such `lw` accesses load 4 bytes from ?, including `lw` at 0xd80, `lw` at 0xd88, `lw` at 0xd8c.
  The `sb` at 0xd84 stores 1 byte to ?.
  The `sw` at 0xd94 stores 4 bytes to ?.
  The `lw` at 0xe28 loads 4 bytes from a0 (arg0 at entry) +0x8.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x18, including `lw` at 0xe50, `lw` at 0xe64.
  The `sw` at 0xeb0 stores 4 bytes to a0 (arg0 at entry) +0x0.
  The `sw` at 0xed0 stores 4 bytes to a0 (arg0 at entry) +0x8.
  The `jal` at 0xe04 calls dtimeout with a0=sym(pckm_reinit), a1=[sym(mh_mouse_port)], a2=0x1, a3=[sym(plbase)], a4=0x0.
  The `jal` at 0xe24 calls untimeout with a0=[a0+8], a1=?, a2=?, a3=0x14.
  The `jal` at 0xe2c calls pckm_rsrv_timer with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xe40 calls pckm_getbp with a0=a0 at entry (arg0), a1=0x1, a2=?, a3=0x14.
  The `jal` at 0xe5c calls mutex_unlock with a0=a0+16, a1=a1 at entry (arg1), a2=[a0+24], a3=0xaa.
  The `jalr` at 0xe68 calls (unknown callee) with a0=?, a1=?, a2=?, a3=[a0+24].
  The `jal` at 0xe74 calls mutex_lock with a0=a0+16, a1=0x19, a2=?, a3=?.
  The `jal` at 0xe88 calls pckm_getbp with a0=a0 at entry (arg0), a1=0x3, a2=?, a3=0xaa.
  The `jal` at 0xec4 calls dtimeout with a0=sym(pckm_rsrv_timer), a1=a0 at entry (arg0), a2=0x2, a3=[sym(plbase)], a4=0x0, a6=[a0].
  The `jal` at 0xee4 calls dtimeout with a0=sym(pckm_reinit), a1=[sym(mh_keyboard_port)], a2=0x1, a3=[sym(plbase)], a4=0x0.
  The `beq` branch at 0xd50 targets 0xdd8, is taken when a1 == a3(=0xaa), and falls through when a1 != a3(=0xaa).
  The `beq` branch at 0xd5c targets 0xdd8, is taken when a1 == at(=0xfc), and falls through when a1 != at(=0xfc).
  The `beq` branch at 0xd6c targets 0xe50, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0xd78 targets 0xe84, is taken when v1(=[a0+44]) == 0, and falls through when v1(=[a0+44]) != 0.
  The `beq` branch at 0xda0 targets 0xe3c, is taken when a1(?) >= a2(?) (unsigned), and falls through when a1(?) < a2(?) (unsigned).
  The `beq` branch at 0xda8 targets 0xe14, is taken when s1(=a1) == a3(=0x14), and falls through when s1(=a1) != a3(=0x14).
  The `beq` branch at 0xdb0 targets 0xe14, is taken when s1(=a1) == a0(=0x76), and falls through when s1(=a1) != a0(=0x76).
  The `beq` branch at 0xdc0 targets 0xea8, is taken when (a6(=[a0]) & 0x10) == 0, and falls through when (a6(=[a0]) & 0x10) != 0.
  The `beq` branch at 0xde0 targets 0xed4, is taken when (a0(=[a0]) & 0x4) == 0, and falls through when (a0(=[a0]) & 0x4) != 0.
  The `bne` branch at 0xde8 targets 0xd6c, is taken when s1(=a1) != a3(=0xaa), and falls through when s1(=a1) == a3(=0xaa).
  The `beq` branch at 0xe0c targets 0xdc8 and is always taken.
  The `beq` branch at 0xe1c targets 0xe2c, is taken when (a1(=[a0]) & 0x10) == 0, and falls through when (a1(=[a0]) & 0x10) != 0.
  The `beq` branch at 0xe34 targets 0xdc8 and is always taken.
  The `beq` branch at 0xe48 targets 0xda8 and is always taken.
  The `beq` branch at 0xe54 targets 0xdc4, is taken when a2(=[a0+24]) == 0, and falls through when a2(=[a0+24]) != 0.
  The `beq` branch at 0xe7c targets 0xdc8 and is always taken.
  The `bne` branch at 0xe90 targets 0xd80, is taken when v0(=ret(pckm_getbp)) != 0, and falls through when v0(=ret(pckm_getbp)) == 0.
  The `beq` branch at 0xea0 targets 0xdc4 and is always taken.
  The `beq` branch at 0xecc targets 0xdc4 and is always taken.
  The `beq` branch at 0xeec targets 0xdc8 and is always taken.
  The return at 0xdd0 has v0 = one of ?, ret(dtimeout), ret(pckm_rsrv_timer), ret(mutex_lock).

- `pckm_intr` in `IP32/usr/cpu/sysgen/IP32boot/mhpckm.o` at 0xef4 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mhpckm.o`.
  Range: 0xef4-0x1154 (608 bytes).
  It occupies 608 bytes.
  6 such `lw` accesses load 4 bytes from ?, including `lw` at 0xf58, `lw` at 0xf94, `lw` at 0xfb0.
  The `lw` at 0xfbc loads 4 bytes from abs 0xffffffffffffa224.
  The `lw` at 0xfc4 loads 4 bytes from [-0x5ddc] +0xa0.
  The `sw` at 0xfd0 stores 4 bytes to [-0x5ddc] +0xa0.
  The `sb` at 0x10b8 stores 1 byte to ?.
  The `lw` at 0x10c4 loads 4 bytes from abs 0xffffffffbfc00000.
  The `jal` at 0xf50 calls mutex_lock with a0=?, a1=0x19, a2=?, a3=a3 at entry (arg3).
  The `jal` at 0xf5c calls pciio_pio_read64 with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xf8c calls printf with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jal` at 0xf98 calls pciio_pio_read64 with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xfb4 calls pciio_pio_read64 with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1034 calls mutex_unlock with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1040 calls mace_mask_enable with a0=0xa00, a1=?, a2=?, a3=?.
  The `jal` at 0x1070 calls printf with a0=sym(.rodata), a1=?, a2=?, a3=[sym(mhkm_print)].
  The `jal` at 0x1084 calls pckm_rx with a0=?, a1=?, a2=[-0x5ddc], a3=?.
  The `jal` at 0x1094 calls pckm_reinit with a0=[sym(mh_keyboard_port)], a1=[[-0x5ddc]+160]+1, a2=[sym(pckm_parity)]+1, a3=?.
  The `jal` at 0x109c calls pckm_reinit with a0=[sym(mh_mouse_port)], a1=?, a2=?, a3=?.
  The `jal` at 0x10ac calls pckm_sendok with a0=?, a1=[[-0x5ddc]+160]+1, a2=[sym(pckm_parity)]+1, a3=[sym(mhkm_print)].
  The `beq` branch at 0xf1c targets 0x10c8, is taken when (a1 & 0x200) == 0, and falls through when (a1 & 0x200) != 0.
  The `beq` branch at 0xf28 targets 0x1108, is taken when a0(=[sym(mh_keyboard_port)]) == 0, and falls through when a0(=[sym(mh_keyboard_port)]) != 0.
  The `beq` branch at 0xf6c targets 0x1024, is taken when (s1(?) & 0x10) == 0, and falls through when (s1(?) & 0x10) != 0.
  The `beq` branch at 0xf7c targets 0xfb0 and is always taken.
  The `beq` branch at 0xfa8 targets 0x1024, is taken when (s1(?) & 0x10) == 0, and falls through when (s1(?) & 0x10) != 0.
  The `beq` branch at 0xfcc targets 0x1080, is taken when (s1(?) & 0xc0) == 0, and falls through when (s1(?) & 0xc0) != 0.
  The `beq` branch at 0xfe0 targets 0x1094, is taken when v0(=[sym(mhkm_reset)]) == s2(=0x1), and falls through when v0(=[sym(mhkm_reset)]) != s2(=0x1).
  The `beq` branch at 0xfe8 targets 0x10ac, is taken when v0(=[sym(mhkm_reset)]) == 0, and falls through when v0(=[sym(mhkm_reset)]) != 0.
  The `beq` branch at 0xff0 targets 0xf94, is taken when a3(=[sym(mhkm_print)]) == 0, and falls through when a3(=[sym(mhkm_print)]) != 0.
  The `beq` branch at 0xff8 targets 0x1054, is taken when v0(=[sym(mhkm_reset)]) == s2(=0x1), and falls through when v0(=[sym(mhkm_reset)]) != s2(=0x1).
  The `bne` branch at 0x1000 targets 0xf94, is taken when v0(=[sym(mhkm_reset)]) != 0, and falls through when v0(=[sym(mhkm_reset)]) == 0.
  The `bne` branch at 0x1014 targets 0xf84, is taken when (a4(?) & 0x4) != 0, and falls through when (a4(?) & 0x4) == 0.
  The `beq` branch at 0x101c targets 0xf88 and is always taken.
  The `beq` branch at 0x1060 targets 0x106c, is taken when (a5(?) & 0x4) == 0, and falls through when (a5(?) & 0x4) != 0.
  The `beq` branch at 0x1078 targets 0x1000 and is always taken.
  The `beq` branch at 0x108c targets 0xf98 and is always taken.
  The `beq` branch at 0x10a4 targets 0xff0 and is always taken.
  The `beq` branch at 0x10c0 targets 0xfec and is always taken.
  The `beq` branch at 0x10d8 targets 0x1128, is taken when (a1 & 0x800) == 0, and falls through when (a1 & 0x800) != 0.
  The `beq` branch at 0x10e4 targets 0x1130, is taken when a0(=[sym(mh_keyboard_port)]) == v0(=0x1), and falls through when a0(=[sym(mh_keyboard_port)]) != v0(=0x1).
  The `beq` branch at 0x1100 targets 0xf48 and is always taken.
  The `beq` branch at 0x1120 targets 0xf48 and is always taken.
  The `beq` branch at 0x1128 targets 0xf4c and is always taken.
  The `beq` branch at 0x114c targets 0xf48 and is always taken.
  The return at 0x104c has v0 = ret(mace_mask_enable).

- `outb` in `IP32/usr/cpu/sysgen/IP32boot/mhpckm.o` at 0x1154 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mhpckm.o`.
  Range: 0x1154-0x11e4 (144 bytes).
  It occupies 144 bytes.
  4 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x4, including `lw` at 0x1164, `lw` at 0x1188, `lw` at 0x11a0.
  The `jal` at 0x1174 calls pciio_pio_read64 with a0=[a0+4]+16, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1180 calls pckm_sendok with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x1190 calls pciio_pio_write64 with a0=0x0, a1=[a0+4]+16, a2=?, a3=?.
  The `jal` at 0x1198 calls us_delay with a0=0x64, a1=?, a2=?, a3=?.
  The `jal` at 0x11a4 calls pciio_pio_write64 with a0=?, a1=[a0+4], a2=?, a3=?.
  The `jal` at 0x11cc calls pciio_pio_write64 with a0=?, a1=[a0+4]+16, a2=?, a3=?.
  The return at 0x11dc has v0 = ret(pciio_pio_write64).

- `_pckm_pollcmd` in `IP32/usr/cpu/sysgen/IP32boot/mhpckm.o` at 0x11e4 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mhpckm.o`.
  Range: 0x11e4-0x1338 (340 bytes).
  It occupies 340 bytes.
  3 such `lw` accesses load 4 bytes from table(sym(kmports)) +0x4, including `lw` at 0x123c, `lw` at 0x1278, `lw` at 0x12f0.
  The `jal` at 0x1230 calls outb with a0=table(sym(kmports)), a1=a1 at entry (arg1), a2=0x0, a3=?.
  The `jal` at 0x1240 calls pciio_pio_read64 with a0=[table(sym(kmports))+4]+24, a1=?, a2=?, a3=?.
  The `jal` at 0x1270 calls us_delay with a0=0x2, a1=[sym(mace_rev)], a2=?, a3=?.
  The `jal` at 0x127c calls pciio_pio_read64 with a0=[table(sym(kmports))+4]+8, a1=?, a2=?, a3=?.
  The `jal` at 0x12cc calls us_delay with a0=0xfa, a1=[sym(mace_rev)], a2=?, a3=?.
  The `jal` at 0x12f4 calls pciio_pio_read64 with a0=[table(sym(kmports))+4]+8, a1=[sym(mace_rev)], a2=?, a3=?.
  The `beq` branch at 0x124c targets 0x1264, is taken when a1(=[sym(mace_rev)]) == 0, and falls through when a1(=[sym(mace_rev)]) != 0.
  The `beq` branch at 0x1258 targets 0x1268, is taken when (s2(?) & 0x40) == 0, and falls through when (s2(?) & 0x40) != 0.
  The `bne` branch at 0x1260 targets 0x12f0, is taken when s1(?) != 0, and falls through when s1(?) == 0.
  The `beq` branch at 0x1268 targets 0x12cc, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0x1290 targets 0x1304, is taken when a1(=[sym(mace_rev)]) == 0, and falls through when a1(=[sym(mace_rev)]) != 0.
  The `beq` branch at 0x1298 targets 0x1320, is taken when a0(=0xfe) == a4(?), and falls through when a0(=0xfe) != a4(?).
  The `beq` branch at 0x12a0 targets 0x12cc, is taken when a2(=0xff) == a4(?), and falls through when a2(=0xff) != a4(?).
  The `bne` branch at 0x12d8 targets 0x123c, is taken when s3(?) != 0, and falls through when s3(?) == 0.
  The `beq` branch at 0x12e0 targets 0x1330, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `beq` branch at 0x12e8 targets 0x1228 and is always taken.
  The `beq` branch at 0x12fc targets 0x1228 and is always taken.
  The `beq` branch at 0x130c targets 0x1298, is taken when (s2(?) & 0x40) == 0, and falls through when (s2(?) & 0x40) != 0.
  The `beq` branch at 0x1318 targets 0x1298 and is always taken.
  The `beq` branch at 0x1320 targets 0x12a0, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `beq` branch at 0x1328 targets 0x1228 and is always taken.
  The `beq` branch at 0x1330 targets 0x12a8 and is always taken.
  The return at 0x12c4 has v0 = one of ?, -0x1.

- `pckm_kbdexists` in `IP32/usr/cpu/sysgen/IP32boot/mhpckm.o` at 0x1338 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mhpckm.o`.
  Range: 0x1338-0x136c (52 bytes).
  It occupies 52 bytes.
  The `lw` at 0x135c loads 4 bytes from table(sym(kmports)) +0x0.
  The return at 0x1364 has v0 = ?.

- `pckm_setleds` in `IP32/usr/cpu/sysgen/IP32boot/mhpckm.o` at 0x136c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mhpckm.o`.
  Range: 0x136c-0x13d0 (100 bytes).
  It occupies 100 bytes.
  The `jal` at 0x1388 calls pckm_pollcmd with a0=[sym(mh_keyboard_port)], a1=0xed, a2=a2 at entry (arg2), a3=a0 at entry (arg0).
  The `jal` at 0x139c calls pckm_pollcmd with a0=[sym(mh_keyboard_port)], a1=[sym(.sbss)+8], a2=?, a3=?.
  The `jal` at 0x13a4 calls pckm_enable_interrupt with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x13c0 calls cmn_err with a0=0x4, a1=sym(.rodata)+288, a2=?, a3=?.
  The `beq` branch at 0x1378 targets 0x13ac, is taken when at(=[sym(.sbss)+8]) == a0, and falls through when at(=[sym(.sbss)+8]) != a0.
  The `bne` branch at 0x1394 targets 0x13b8, is taken when v0(=ret(pckm_pollcmd)) != v1(=0xfa), and falls through when v0(=ret(pckm_pollcmd)) == v1(=0xfa).
  The `beq` branch at 0x13c8 targets 0x139c and is always taken.
  The return at 0x13b0 has v0 = one of ?, ret(pckm_enable_interrupt).

- `pckm_sendok` in `IP32/usr/cpu/sysgen/IP32boot/mhpckm.o` at 0x13d0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mhpckm.o`.
  Range: 0x13d0-0x1430 (96 bytes).
  It occupies 96 bytes.
  The `lw` at 0x13f0 loads 4 bytes from a0 (arg0 at entry) +0x4.
  The `jal` at 0x13e8 calls us_delay with a0=0x2, a1=?, a2=?, a3=?.
  The `jal` at 0x13f4 calls pciio_pio_read64 with a0=[a0+4]+24, a1=?, a2=?, a3=?.
  The `jal` at 0x1414 calls us_delay with a0=0x2, a1=?, a2=?, a3=?.
  The `beq` branch at 0x1404 targets 0x1414, is taken when (a1(?) & 0x24) == 0, and falls through when (a1(?) & 0x24) != 0.
  The `bne` branch at 0x140c targets 0x13e8, is taken when s0(?) != 0, and falls through when s0(?) == 0.
  The return at 0x1428 has v0 = ret(us_delay).

- `pckm_flushinp` in `IP32/usr/cpu/sysgen/IP32boot/mhpckm.o` at 0x1430 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mhpckm.o`.
  Range: 0x1430-0x14a0 (112 bytes).
  It occupies 112 bytes.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x4, including `lw` at 0x145c, `lw` at 0x1470.
  The `jal` at 0x1444 calls us_delay with a0=0x2, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1454 calls us_delay with a0=0x2, a1=?, a2=?, a3=?.
  The `jal` at 0x1460 calls pciio_pio_read64 with a0=[a0+4]+8, a1=?, a2=?, a3=?.
  The `jal` at 0x1468 calls us_delay with a0=0x2, a1=?, a2=?, a3=?.
  The `jal` at 0x1474 calls pciio_pio_read64 with a0=[a0+4]+24, a1=?, a2=?, a3=?.
  The `beq` branch at 0x144c targets 0x1470 and is always taken.
  The `beq` branch at 0x1480 targets 0x148c, is taken when (v0(=ret(pciio_pio_read64)) & 0x10) == 0, and falls through when (v0(=ret(pciio_pio_read64)) & 0x10) != 0.
  The `bne` branch at 0x1488 targets 0x1454, is taken when s0(?) != 0, and falls through when s0(?) == 0.
  The return at 0x1498 has v0 = ret(pciio_pio_read64).

- `gl_setporthandler` in `IP32/usr/cpu/sysgen/IP32boot/mhpckm.o` at 0x14a0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mhpckm.o`.
  Range: 0x14a0-0x14cc (44 bytes).
  It occupies 44 bytes.
  The `sw` at 0x14c8 stores 4 bytes to table(sym(kmports)) +0x18.
  The return at 0x14c4 has v0 = ?.

- `du_keyboard_port` in `IP32/usr/cpu/sysgen/IP32boot/mhpckm.o` at 0x14cc (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mhpckm.o`.
  Range: 0x14cc-0x14d4 (8 bytes).
  It occupies 8 bytes.
  The return at 0x14cc has v0 = -0x1.

- `pckm_pollcmd` in `IP32/usr/cpu/sysgen/IP32boot/mhpckm.o` at 0x14d4 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mhpckm.o`.
  Range: 0x14d4-0x14f0 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x14dc calls _pckm_pollcmd with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x14e8 has v0 = ret(_pckm_pollcmd).

- `default_ms_setting` in `IP32/usr/cpu/sysgen/IP32boot/mhpckm.o` at 0x14f0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mhpckm.o`.
  Range: 0x14f0-0x16a8 (440 bytes).
  It occupies 440 bytes.
  3 such `sw` accesses store 4 bytes to table(sym(kmports)) +0x30, including `sw` at 0x1564, `sw` at 0x162c, `sw` at 0x169c.
  The `jal` at 0x1500 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xe8, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x150c calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0x3, a2=?, a3=?.
  The `jal` at 0x151c calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xf4, a2=?, a3=?.
  The `jal` at 0x1570 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xf6, a2=?, a3=?.
  The `jal` at 0x157c calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xe6, a2=?, a3=?.
  The `jal` at 0x1588 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xf3, a2=?, a3=?.
  The `jal` at 0x1594 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0x64, a2=?, a3=?.
  The `jal` at 0x15a0 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xe8, a2=?, a3=?.
  The `jal` at 0x15ac calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0x3, a2=?, a3=?.
  The `jal` at 0x15b8 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xf4, a2=?, a3=?.
  The `jal` at 0x15d4 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xf3, a2=0x2, a3=?.
  The `jal` at 0x15e0 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xc8, a2=?, a3=?.
  The `jal` at 0x15ec calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xf3, a2=?, a3=?.
  The `jal` at 0x15f8 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0x64, a2=?, a3=?.
  The `jal` at 0x1604 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xf3, a2=?, a3=?.
  The `jal` at 0x1610 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0x50, a2=?, a3=?.
  The `jal` at 0x1618 calls check_port with a0=table(sym(kmports)), a1=?, a2=?, a3=?.
  The `jal` at 0x163c calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xf3, a2=0x2, a3=?.
  The `jal` at 0x1648 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xc8, a2=?, a3=?.
  The `jal` at 0x1654 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xf3, a2=?, a3=?.
  The `jal` at 0x1660 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xc8, a2=?, a3=?.
  The `jal` at 0x166c calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0xf3, a2=?, a3=?.
  The `jal` at 0x1678 calls pckm_pollcmd with a0=a0 at entry (arg0), a1=0x50, a2=?, a3=?.
  The `jal` at 0x1680 calls check_port with a0=table(sym(kmports)), a1=?, a2=?, a3=?.
  The `beq` branch at 0x1548 targets 0x1638, is taken when a0(=[sym(pcmouse_mode)]) == a2(=0x2), and falls through when a0(=[sym(pcmouse_mode)]) != a2(=0x2).
  The `beq` branch at 0x1554 targets 0x15d0, is taken when a0(=[sym(pcmouse_mode)]) == t9(=0x1), and falls through when a0(=[sym(pcmouse_mode)]) != t9(=0x1).
  The `beq` branch at 0x155c targets 0x15d4, is taken when a0(=[sym(pcmouse_mode)]) == a2(=0x2), and falls through when a0(=[sym(pcmouse_mode)]) != a2(=0x2).
  The `beq` branch at 0x1628 targets 0x1564, is taken when ra(?) >= 0x1 (unsigned), and falls through when ra(?) < 0x1 (unsigned).
  The `beq` branch at 0x1630 targets 0x156c and is always taken.
  The `bne` branch at 0x1698 targets 0x1568, is taken when at(?) < 0x1 (unsigned), and falls through when at(?) >= 0x1 (unsigned).
  The `beq` branch at 0x16a0 targets 0x1554 and is always taken.
  The return at 0x15c8 has v0 = ret(pckm_pollcmd).

- `check_port` in `IP32/usr/cpu/sysgen/IP32boot/mhpckm.o` at 0x16a8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mhpckm.o`.
  Range: 0x16a8-0x1710 (104 bytes).
  It occupies 104 bytes.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x4, including `lw` at 0x16e4, `lw` at 0x16fc.
  The `jal` at 0x16b0 calls pckm_flushinp with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x16bc calls pckm_pollcmd with a0=[sym(mh_mouse_port)], a1=0xf2, a2=?, a3=?.
  The `jal` at 0x16e8 calls pciio_pio_read64 with a0=[a0+4]+8, a1=?, a2=0x0, a3=?.
  The `jal` at 0x16f0 calls us_delay with a0=0x9c4, a1=?, a2=?, a3=?.
  The `jal` at 0x1700 calls pciio_pio_read64 with a0=[a0+4]+8, a1=?, a2=?, a3=?.
  The `beq` branch at 0x16c8 targets 0x16e0, is taken when v0(=ret(pckm_pollcmd)) == at(=0xfa), and falls through when v0(=ret(pckm_pollcmd)) != at(=0xfa).
  The `beq` branch at 0x1708 targets 0x16d0 and is always taken.
  The return at 0x16d8 has v0 = one of 0x0, ?.

- `pckm_enable_interrupt` in `IP32/usr/cpu/sysgen/IP32boot/mhpckm.o` at 0x1710 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mhpckm.o`.
  Range: 0x1710-0x17e0 (208 bytes).
  It occupies 208 bytes.
  4 such `lw` accesses load 4 bytes from table(sym(kmports)) +0x4, including `lw` at 0x175c, `lw` at 0x1768, `lw` at 0x17a8.
  The `jal` at 0x1744 calls pciio_pio_read64 with a0=0xffffffffbf310018, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1754 calls pciio_pio_write64 with a0=(ret(pciio_pio_read64) | 0xa00), a1=0xffffffffbf310018, a2=?, a3=?.
  The `jal` at 0x1760 calls pciio_pio_read64 with a0=[table(sym(kmports))+4]+16, a1=?, a2=?, a3=?.
  The `jal` at 0x177c calls pciio_pio_write64 with a0=?, a1=[table(sym(kmports))+4]+16, a2=?, a3=?.
  The `jal` at 0x17b0 calls pciio_pio_read64 with a0=[table(sym(kmports))+4]+16, a1=?, a2=?, a3=?.
  The `jal` at 0x17c8 calls pciio_pio_write64 with a0=?, a1=[table(sym(kmports))+4]+16, a2=?, a3=?.
  The return at 0x17d8 has v0 = ret(pciio_pio_write64).
