# Readings: `IP27/usr/cpu/sysgen/IP27boot/xbow.o`

One entry per routine, filed here from the reading batches by binary.

- `xbow_widget_num_get` in `IP27/usr/cpu/sysgen/IP27boot/xbow.o` at 0x3fc (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xbow.o`.
  Range: 0x3fc-0x4f8 (252 bytes).
  It occupies 252 bytes.
  The `lh` at 0x440 loads 2 bytes from table(sym(compact_to_nasid_node)) +0x0.
  The `jal` at 0x410 calls vertex_to_name with a0=a0 at entry (arg0), a1=sp-288, a2=0x100, a3=a3 at entry (arg3).
  The `jal` at 0x418 calls nodevertex_to_cnodeid with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x43c calls hub_widget_id with a0=entry(sym(compact_to_nasid_node)), a1=?, a2=?, a3=?.
  The `jal` at 0x464 calls strstr with a0=sp-288, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x478 calls strstr with a0=sp-288, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x49c calls hwgraph_edge_get with a0=a0 at entry (arg0), a1=sym(.rodata), a2=sp-32, a3=?.
  The `jal` at 0x4d0 calls xwidget_info_chk with a0=a0 at entry (arg0), a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x4e8 calls xwidget_info_id_get with a0=ret(xwidget_info_chk), a1=?, a2=?, a3=?.
  The `beq` branch at 0x424 targets 0x45c, is taken when v0(=ret(nodevertex_to_cnodeid)) == at(=-0x1), and falls through when v0(=ret(nodevertex_to_cnodeid)) != at(=-0x1).
  The `beq` branch at 0x46c targets 0x4b4, is taken when v0(=ret(strstr)) == 0, and falls through when v0(=ret(strstr)) != 0.
  The `beq` branch at 0x480 targets 0x4b4, is taken when v0(=ret(strstr)) == 0, and falls through when v0(=ret(strstr)) != 0.
  The `beq` branch at 0x4a4 targets 0x4bc, is taken when v0(=ret(hwgraph_edge_get)) == 0, and falls through when v0(=ret(hwgraph_edge_get)) != 0.
  The `beq` branch at 0x4ac targets 0x448 and is always taken.
  The `beq` branch at 0x4b4 targets 0x448 and is always taken.
  The `bne` branch at 0x4c8 targets 0x494, is taken when a2(?) < 0x2 (signed), and falls through when a2(?) >= 0x2 (signed).
  The `bne` branch at 0x4d8 targets 0x4e8, is taken when v0(=ret(xwidget_info_chk)) != 0, and falls through when v0(=ret(xwidget_info_chk)) == 0.
  The `beq` branch at 0x4e0 targets 0x448 and is always taken.
  The `beq` branch at 0x4f0 targets 0x448 and is always taken.
  The return at 0x454 has v0 = one of ret(hub_widget_id), 0xff, ret(xwidget_info_id_get).

- `xbow_ioctl` in `IP27/usr/cpu/sysgen/IP27boot/xbow.o` at 0x4f8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xbow.o`.
  Range: 0x4f8-0x864 (876 bytes).
  It occupies 876 bytes.
  The `sw` at 0x4f8 stores 4 bytes to a5 (arg5 at entry) +0x0.
  The `jal` at 0x594 calls xbow_get_perf_counters with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0x5ac calls copyout with a0=ret(xbow_get_perf_counters), a1=a2 at entry (arg2), a2=0x100, a3=?.
  The `jal` at 0x5d8 calls cap_able_cred with a0=a4 at entry (arg4), a1=0x2000000000, a2=0x1, a3=a3 at entry (arg3).
  The `jal` at 0x5f4 calls copyin with a0=a2 at entry (arg2), a1=sp-64, a2=0xc, a3=?.
  The `jal` at 0x61c calls xbow_get_llp_status with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=0x6.
  The `jal` at 0x634 calls copyout with a0=ret(xbow_get_llp_status), a1=a2 at entry (arg2), a2=0x80, a3=?.
  The `jal` at 0x65c calls cap_able_cred with a0=a4 at entry (arg4), a1=0x2000000000, a2=?, a3=?, a5=0x4.
  The `jal` at 0x68c calls cap_able_cred with a0=a4 at entry (arg4), a1=0x2000000000, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x6a4 calls xbow_disable_llp_monitor with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x6bc calls cap_able with a0=0x2000000000, a1=0x6702, a2=a2 at entry (arg2), a3=0x6.
  The `jal` at 0x6d0 calls copyin with a0=a2 at entry (arg2), a1=sp-96, a2=0x10, a3=?.
  The `jal` at 0x6fc calls cap_able with a0=0x2000000000, a1=0x6702, a2=a2 at entry (arg2), a3=0x6.
  The `jal` at 0x710 calls copyin with a0=a2 at entry (arg2), a1=sp-80, a2=0x10, a3=?.
  The `jal` at 0x744 calls xbow_enable_perf_counter with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x758 calls xbow_enable_llp_monitor with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x784 calls xbow_widget_num_get with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x790 calls xbow_widget_num_get with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x7b0 calls xbow_prio_bw_alloc with a0=a0 at entry (arg0), a1=?, a2=?, a3=0x0.
  The `jal` at 0x7c8 calls xbow_prio_bw_alloc with a0=a0 at entry (arg0), a1=?, a2=?, a3=0x0.
  The `jal` at 0x7d8 calls xbow_widget_num_get with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x7e4 calls xbow_widget_num_get with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x804 calls xbow_prio_bw_alloc with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x81c calls xbow_prio_bw_alloc with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x838 calls assfail with a0=sym(.rodata), a1=sym(.rodata), a2=0x264, a3=?.
  The `jal` at 0x854 calls assfail with a0=sym(.rodata), a1=sym(.rodata), a2=0x28c, a3=?.
  The `bne` branch at 0x524 targets 0x574, is taken when a1 < 0x5 (signed), and falls through when a1 >= 0x5 (signed).
  The `bne` branch at 0x530 targets 0x684, is taken when a1 < 0x6 (signed), and falls through when a1 >= 0x6 (signed).
  The `bne` branch at 0x538 targets 0x60c, is taken when v1(?) != 0, and falls through when v1(?) == 0.
  The `bne` branch at 0x544 targets 0x6b8, is taken when a1 < 0x6702 (signed), and falls through when a1 >= 0x6702 (signed).
  The `beq` branch at 0x54c targets 0x6f8, is taken when s0(=a1) == a1(=0x6702), and falls through when s0(=a1) != a1(=0x6702).
  The `bne` branch at 0x578 targets 0x5c0, is taken when a1 < 0x3 (signed), and falls through when a1 >= 0x3 (signed).
  The `beq` branch at 0x584 targets 0x648, is taken when a1 >= 0x4 (signed), and falls through when a1 < 0x4 (signed).
  The `beq` branch at 0x58c targets 0x6e8, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0x59c targets 0x82c, is taken when v0(=ret(xbow_get_perf_counters)) == 0, and falls through when v0(=ret(xbow_get_perf_counters)) != 0.
  The `beq` branch at 0x5b8 targets 0x554 and is always taken.
  The `bne` branch at 0x5c0 targets 0x674, is taken when a5(?) != 0, and falls through when a5(?) == 0.
  The `beq` branch at 0x5c8 targets 0x554, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x5e0 targets 0x774, is taken when v0(=ret(cap_able_cred)) == 0, and falls through when v0(=ret(cap_able_cred)) != 0.
  The `beq` branch at 0x5e8 targets 0x6f0, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0x5fc targets 0x730, is taken when v0(=ret(copyin)) == 0, and falls through when v0(=ret(copyin)) != 0.
  The `beq` branch at 0x604 targets 0x554 and is always taken.
  The `bne` branch at 0x60c targets 0x550, is taken when a1 != a3(=0x6), and falls through when a1 == a3(=0x6).
  The `beq` branch at 0x614 targets 0x728, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0x624 targets 0x848, is taken when v0(=ret(xbow_get_llp_status)) == 0, and falls through when v0(=ret(xbow_get_llp_status)) != 0.
  The `beq` branch at 0x640 targets 0x554 and is always taken.
  The `bne` branch at 0x64c targets 0x554, is taken when a1 != a5(=0x4), and falls through when a1 == a5(=0x4).
  The `bne` branch at 0x664 targets 0x758, is taken when v0(=ret(cap_able_cred)) != 0, and falls through when v0(=ret(cap_able_cred)) == 0.
  The `beq` branch at 0x66c targets 0x554 and is always taken.
  The `bne` branch at 0x674 targets 0x554, is taken when a1 != a2(=0x1), and falls through when a1 == a2(=0x1).
  The `beq` branch at 0x67c targets 0x5d4 and is always taken.
  The `bne` branch at 0x694 targets 0x6a4, is taken when v0(=ret(cap_able_cred)) != 0, and falls through when v0(=ret(cap_able_cred)) == 0.
  The `beq` branch at 0x69c targets 0x554 and is always taken.
  The `beq` branch at 0x6b0 targets 0x554 and is always taken.
  The `beq` branch at 0x6c4 targets 0x76c, is taken when v0(=ret(cap_able)) == 0, and falls through when v0(=ret(cap_able)) != 0.
  The `beq` branch at 0x6d8 targets 0x784, is taken when v0(=ret(copyin)) == 0, and falls through when v0(=ret(copyin)) != 0.
  The `beq` branch at 0x6e0 targets 0x554 and is always taken.
  The `beq` branch at 0x6e8 targets 0x554 and is always taken.
  The `beq` branch at 0x6f0 targets 0x554 and is always taken.
  The `beq` branch at 0x704 targets 0x77c, is taken when v0(=ret(cap_able)) == 0, and falls through when v0(=ret(cap_able)) != 0.
  The `beq` branch at 0x718 targets 0x7d8, is taken when v0(=ret(copyin)) == 0, and falls through when v0(=ret(copyin)) != 0.
  The `beq` branch at 0x720 targets 0x554 and is always taken.
  The `beq` branch at 0x728 targets 0x554 and is always taken.
  The `beq` branch at 0x750 targets 0x554 and is always taken.
  The `beq` branch at 0x764 targets 0x554 and is always taken.
  The `beq` branch at 0x76c targets 0x554 and is always taken.
  The `beq` branch at 0x774 targets 0x554 and is always taken.
  The `beq` branch at 0x77c targets 0x554 and is always taken.
  The `beq` branch at 0x7d0 targets 0x554 and is always taken.
  The `beq` branch at 0x824 targets 0x554 and is always taken.
  The `beq` branch at 0x840 targets 0x5a8 and is always taken.
  The `beq` branch at 0x85c targets 0x630 and is always taken.
  The return at 0x56c has v0 = one of 0x0, 0xe, 0x1, ?, 0x9.

- `xbow_link_alive` in `IP27/usr/cpu/sysgen/IP27boot/xbow.o` at 0x8c8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xbow.o`.
  Range: 0x8c8-0x8e0 (24 bytes).
  It occupies 24 bytes.
  The `lw` at 0x8d4 loads 4 bytes from ?.
  The return at 0x8d8 has v0 = ?.

- `xbow_widget_lookup` in `IP27/usr/cpu/sysgen/IP27boot/xbow.o` at 0x8e0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xbow.o`.
  Range: 0x8e0-0x944 (100 bytes).
  It occupies 100 bytes.
  The `jal` at 0x8ec calls xswitch_info_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x910 calls xswitch_info_vhdl_get with a0=ret(xswitch_info_get), a1=?, a2=?, a3=?.
  The `jal` at 0x934 calls assfail with a0=sym(.rodata), a1=sym(.rodata), a2=0x307, a3=?.
  The `bne` branch at 0x8fc targets 0x928, is taken when s0(=a1) < 0x8 (signed), and falls through when s0(=a1) >= 0x8 (signed).
  The `beq` branch at 0x904 targets 0x92c, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x93c targets 0x910 and is always taken.
  The return at 0x920 has v0 = ret(xswitch_info_vhdl_get).

- `xbow_setwidint` in `IP27/usr/cpu/sysgen/IP27boot/xbow.o` at 0x944 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xbow.o`.
  Range: 0x944-0x9b0 (108 bytes).
  It occupies 108 bytes.
  The `jal` at 0x954 calls xtalk_intr_target_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x960 calls xtalk_intr_addr_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x96c calls xtalk_intr_vector_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x978 calls xtalk_intr_sfarg_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x998 calls xbow_intr_preset with a0=ret(xtalk_intr_sfarg_get), a1=0x0, a2=?, a3=ret(xtalk_intr_addr_get).
  The return at 0x9a8 has v0 = ret(xbow_intr_preset).

- `xbow_intr_preset` in `IP27/usr/cpu/sysgen/IP27boot/xbow.o` at 0x9b0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xbow.o`.
  Range: 0x9b0-0x9e4 (52 bytes).
  It occupies 52 bytes.
  The `sw` at 0x9d8 stores 4 bytes to a0 (arg0 at entry) +0x34.
  The `sw` at 0x9e0 stores 4 bytes to a0 (arg0 at entry) +0x3c.
  The return at 0x9dc has v0 = ?.

- `xem_add_ioe` in `IP27/usr/cpu/sysgen/IP27boot/xbow.o` at 0x9e4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xbow.o`.
  Range: 0x9e4-0xc18 (564 bytes).
  It occupies 564 bytes.
  14 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x0, including `lw` at 0x9e4, `lw` at 0xaa0, `lw` at 0xabc.
  The `lh` at 0xa90 loads 2 bytes from a0 (arg0 at entry) +0x4.
  The `lh` at 0xaac loads 2 bytes from a0 (arg0 at entry) +0x6.
  The `lh` at 0xac8 loads 2 bytes from a0 (arg0 at entry) +0x8.
  The `lh` at 0xae4 loads 2 bytes from a0 (arg0 at entry) +0xa.
  The `lh` at 0xb00 loads 2 bytes from a0 (arg0 at entry) +0xc.
  The `lh` at 0xb1c loads 2 bytes from a0 (arg0 at entry) +0xe.
  The `ld` at 0xb38 loads 8 bytes from a0 (arg0 at entry) +0x10.
  The `ld` at 0xb54 loads 8 bytes from a0 (arg0 at entry) +0x18.
  The `ld` at 0xb70 loads 8 bytes from a0 (arg0 at entry) +0x20.
  The `ld` at 0xb8c loads 8 bytes from a0 (arg0 at entry) +0x28.
  The `ld` at 0xba8 loads 8 bytes from a0 (arg0 at entry) +0x30.
  The `ld` at 0xbc4 loads 8 bytes from a0 (arg0 at entry) +0x38.
  The `ld` at 0xbe4 loads 8 bytes from a0 (arg0 at entry) +0x40.
  The `ld` at 0xc04 loads 8 bytes from a0 (arg0 at entry) +0x48.
  The `jal` at 0xa94 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[a0+4]:2.
  The `jal` at 0xab0 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[a0+6]:2.
  The `jal` at 0xacc calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[a0+8]:2.
  The `jal` at 0xae8 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[a0+10]:2.
  The `jal` at 0xb04 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[a0+12]:2.
  The `jal` at 0xb20 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[a0+14]:2, a4=([a0] << 0x6).
  The `jal` at 0xb3c calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[a0+16]:8, a4=([a0] << 0x6), a5=([a0] << 0x7).
  The `jal` at 0xb58 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[a0+24]:8, a5=([a0] << 0x7), a6=([a0] << 0x8).
  The `jal` at 0xb74 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[a0+32]:8, a6=([a0] << 0x8), a7=([a0] << 0x9).
  The `jal` at 0xb90 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[a0+40]:8, a7=([a0] << 0x9).
  The `jal` at 0xbac calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[a0+48]:8.
  The `jal` at 0xbc8 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[a0+56]:8.
  The `jal` at 0xbe8 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[a0+64]:8.
  The `jal` at 0xc08 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[a0+72]:8.
  The `bne` branch at 0x9fc targets 0xa84, is taken when at(?) != 0, and falls through when at(?) == 0.
  The `bltz` branch at 0xa08 targets 0xaa4, is taken when v0(=([a0] << 0x1)) < 0 (signed), and falls through when v0(=([a0] << 0x1)) >= 0 (signed).
  The `bltz` branch at 0xa14 targets 0xac0, is taken when v1(=([a0] << 0x2)) < 0 (signed), and falls through when v1(=([a0] << 0x2)) >= 0 (signed).
  The `bltz` branch at 0xa1c targets 0xadc, is taken when a0(=([a0] << 0x3)) < 0 (signed), and falls through when a0(=([a0] << 0x3)) >= 0 (signed).
  The `bltz` branch at 0xa24 targets 0xaf8, is taken when a1(=([a0] << 0x4)) < 0 (signed), and falls through when a1(=([a0] << 0x4)) >= 0 (signed).
  The `bltz` branch at 0xa2c targets 0xb14, is taken when a3(=([a0] << 0x5)) < 0 (signed), and falls through when a3(=([a0] << 0x5)) >= 0 (signed).
  The `bltz` branch at 0xa34 targets 0xb30, is taken when a4(=([a0] << 0x6)) < 0 (signed), and falls through when a4(=([a0] << 0x6)) >= 0 (signed).
  The `bltz` branch at 0xa3c targets 0xb4c, is taken when a5(=([a0] << 0x7)) < 0 (signed), and falls through when a5(=([a0] << 0x7)) >= 0 (signed).
  The `bltz` branch at 0xa44 targets 0xb68, is taken when a6(=([a0] << 0x8)) < 0 (signed), and falls through when a6(=([a0] << 0x8)) >= 0 (signed).
  The `bltz` branch at 0xa4c targets 0xb84, is taken when a7(=([a0] << 0x9)) < 0 (signed), and falls through when a7(=([a0] << 0x9)) >= 0 (signed).
  The `bltz` branch at 0xa54 targets 0xba0, is taken when t0(=([a0] << 0xa)) < 0 (signed), and falls through when t0(=([a0] << 0xa)) >= 0 (signed).
  The `bltz` branch at 0xa5c targets 0xbbc, is taken when t1(=([a0] << 0xb)) < 0 (signed), and falls through when t1(=([a0] << 0xb)) >= 0 (signed).
  The `bltz` branch at 0xa64 targets 0xbd8, is taken when t2(=([a0] << 0xc)) < 0 (signed), and falls through when t2(=([a0] << 0xc)) >= 0 (signed).
  The `bltz` branch at 0xa6c targets 0xbf8, is taken when t3(=([a0] << 0xd)) < 0 (signed), and falls through when t3(=([a0] << 0xd)) >= 0 (signed).
  The `beq` branch at 0xa9c targets 0xa04 and is always taken.
  The `beq` branch at 0xab8 targets 0xa10 and is always taken.
  The `beq` branch at 0xad4 targets 0xa18 and is always taken.
  The `beq` branch at 0xaf0 targets 0xa20 and is always taken.
  The `beq` branch at 0xb0c targets 0xa28 and is always taken.
  The `beq` branch at 0xb28 targets 0xa30 and is always taken.
  The `beq` branch at 0xb44 targets 0xa38 and is always taken.
  The `beq` branch at 0xb60 targets 0xa40 and is always taken.
  The `beq` branch at 0xb7c targets 0xa48 and is always taken.
  The `beq` branch at 0xb98 targets 0xa50 and is always taken.
  The `beq` branch at 0xbb4 targets 0xa58 and is always taken.
  The `beq` branch at 0xbd0 targets 0xa60 and is always taken.
  The `beq` branch at 0xbf0 targets 0xa68 and is always taken.
  The `beq` branch at 0xc10 targets 0xa74 and is always taken.
  The return at 0xa7c has v0 = one of ?, ret(cmn_err).

- `xbow_xmit_retry_error` in `IP27/usr/cpu/sysgen/IP27boot/xbow.o` at 0xc18 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xbow.o`.
  Range: 0xc18-0xd1c (260 bytes).
  It occupies 260 bytes.
  The `ld` at 0xc28 loads 8 bytes from (a0 + (a1 << 0x3)) +0x188.
  3 such `lw` accesses load 4 bytes from ?, including `lw` at 0xc3c, `lw` at 0xc9c, `lw` at 0xcac.
  The `sw` at 0xca0 stores 4 bytes to ?.
  The `lw` at 0xcb4 loads 4 bytes from a0 (arg0 at entry) +0x8.
  The `sd` at 0xd08 stores 8 bytes to (a0 + (a1 << 0x3)) +0x188.
  The `jal` at 0xcb0 calls xswitch_info_get with a0=[a0+8], a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a5=[(a0 + (a1 << 0x3))+392]:8.
  The `jal` at 0xcd0 calls xswitch_info_vhdl_get with a0=ret(xswitch_info_get), a1=?, a2=?, a3=?, a4=0x1.
  The `jal` at 0xcf0 calls xtalk_piotrans_addr with a0=ret(xswitch_info_vhdl_get), a1=0x0, a2=0x0, a3=0x58, a4=0x0.
  The `beq` branch at 0xc34 targets 0xcb0, is taken when a5(=[(a0 + (a1 << 0x3))+392]:8) == 0, and falls through when a5(=[(a0 + (a1 << 0x3))+392]:8) != 0.
  The `beq` branch at 0xc50 targets 0xc80, is taken when a0(?) == a7(=0xc002), and falls through when a0(?) != a7(=0xc002).
  The `bne` branch at 0xc58 targets 0xc70, is taken when a0(?) != a1(=0xd002), and falls through when a0(?) == a1(=0xd002).
  The `beq` branch at 0xc68 targets 0xc94, is taken when a1(?) == a2(=0x24), and falls through when a1(?) != a2(=0x24).
  The `bne` branch at 0xc8c targets 0xc58, is taken when a2(?) != a3(=0x36), and falls through when a2(?) == a3(=0x36).
  The `beq` branch at 0xca8 targets 0xc70 and is always taken.
  The `bne` branch at 0xcb8 targets 0xcc8, is taken when v0(=ret(xswitch_info_get)) != 0, and falls through when v0(=ret(xswitch_info_get)) == 0.
  The `beq` branch at 0xcc0 targets 0xc74 and is always taken.
  The `beq` branch at 0xcdc targets 0xd0c, is taken when v0(=ret(xswitch_info_vhdl_get)) == a2(=-0x1), and falls through when v0(=ret(xswitch_info_vhdl_get)) != a2(=-0x1).
  The `beq` branch at 0xcfc targets 0xd14, is taken when v0(=ret(xtalk_piotrans_addr)) == 0, and falls through when v0(=ret(xtalk_piotrans_addr)) != 0.
  The `beq` branch at 0xd04 targets 0xc3c and is always taken.
  The `beq` branch at 0xd0c targets 0xc70 and is always taken.
  The `beq` branch at 0xd14 targets 0xc70 and is always taken.
  The return at 0xc78 has v0 = one of 0x0, 0x1.

- `xbow_errintr_handler` in `IP27/usr/cpu/sysgen/IP27boot/xbow.o` at 0xd1c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xbow.o`.
  Range: 0xd1c-0x1310 (1524 bytes).
  It occupies 1524 bytes.
  The `ld` at 0xd48 loads 8 bytes from a0 (arg0 at entry) +0x10.
  The `lw` at 0xd50 loads 4 bytes from [a0+16]:8 +0x24.
  The `lw` at 0xd54 loads 4 bytes from [a0+16]:8 +0x54.
  The `lw` at 0xd58 loads 4 bytes from [a0+16]:8 +0x44.
  The `lw` at 0xd5c loads 4 bytes from [a0+16]:8 +0x14.
  The `lw` at 0xd60 loads 4 bytes from [a0+16]:8 +0x1c.
  The `sw` at 0xd6c stores 4 bytes to [a0+16]:8 +0x44.
  4 such `lw` accesses load 4 bytes from ?, including `lw` at 0xe30, `lw` at 0xe34, `lw` at 0xe44.
  The `sw` at 0xe88 stores 4 bytes to ?.
  The `lw` at 0xf54 loads 4 bytes from a0 (arg0 at entry) +0x8.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x18, including `ld` at 0xf78, `ld` at 0x10e8.
  The `jal` at 0xe68 calls xbow_xmit_retry_error with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xeb4 calls xbow_error_handler with a0=a0 at entry (arg0), a1=0x8, a2=0x1, a3=sp-272.
  The `jal` at 0xf50 calls xbow_widget_lookup with a0=[a0+8], a1=?, a2=?, a3=?.
  The `jal` at 0xf58 calls xwidget_name_get with a0=ret(xbow_widget_lookup), a1=?, a2=?, a3=?.
  The `jal` at 0xf74 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=[a0+24]:8, a3=?, a4=ret(xwidget_name_get).
  The `jal` at 0x1038 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[[a0+16]:8+84].
  The `jal` at 0x104c calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x1060 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x1074 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x1088 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x10b4 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x10c4 calls cmn_err_tag with a0=0x8, a1=0x0, a2=sym(.rodata), a3=?.
  The `jal` at 0x10e4 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=[a0+24]:8, a3=?.
  The `jal` at 0x111c calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x1144 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x1158 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x116c calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x1180 calls xem_add_ioe with a0=sp-272, a1=?, a2=?, a3=?.
  The `jal` at 0x1198 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x11b0 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x11cc calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x11e8 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x1204 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x121c calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x1238 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x1254 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x1270 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x128c calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x12a8 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x12c4 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x12e0 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `beq` branch at 0xda4 targets 0xf34, is taken when (s3(=[[a0+16]:8+84]) & at(=0xffffffffff000000)) == 0, and falls through when (s3(=[[a0+16]:8+84]) & at(=0xffffffffff000000)) != 0.
  The `beq` branch at 0xdec targets 0x12f0 and is always taken.
  The `bne` branch at 0xdfc targets 0xf4c, is taken when s1(?) != 0, and falls through when s1(?) == 0.
  The `beq` branch at 0xe20 targets 0xed4, is taken when s0(?) >= 0x10 (signed), and falls through when s0(?) < 0x10 (signed).
  The `beq` branch at 0xe28 targets 0xe04, is taken when t8(?) == 0, and falls through when t8(?) != 0.
  The `beq` branch at 0xe4c targets 0xe5c, is taken when (s5(=0x20000) & s1(?)) == 0, and falls through when (s5(=0x20000) & s1(?)) != 0.
  The `beq` branch at 0xe58 targets 0xe94, is taken when s0(?) == t8(?), and falls through when s0(?) != t8(?).
  The `beq` branch at 0xe60 targets 0xdfc, is taken when t9(?) == 0, and falls through when t9(?) != 0.
  The `bne` branch at 0xe70 targets 0xdf4, is taken when v0(=ret(xbow_xmit_retry_error)) != 0, and falls through when v0(=ret(xbow_xmit_retry_error)) == 0.
  The `beq` branch at 0xe8c targets 0xdf4 and is always taken.
  The `beq` branch at 0xec0 targets 0xf24, is taken when v0(=ret(xbow_error_handler)) == 0, and falls through when v0(=ret(xbow_error_handler)) != 0.
  The `beq` branch at 0xecc targets 0xe5c and is always taken.
  The `beq` branch at 0xed8 targets 0xef0, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `bne` branch at 0xee4 targets 0x10dc, is taken when (s3(=[[a0+16]:8+84]) & 0x25) != 0, and falls through when (s3(=[[a0+16]:8+84]) & 0x25) == 0.
  The `bne` branch at 0xef0 targets 0x102c, is taken when a5(?) != 0, and falls through when a5(?) == 0.
  The `beq` branch at 0xf2c targets 0xe5c and is always taken.
  The `bgez` branch at 0xf34 targets 0xef8, is taken when t0(?) >= 0 (signed), and falls through when t0(?) < 0 (signed).
  The `beq` branch at 0xf3c targets 0xef8, is taken when t1(?) == 0, and falls through when t1(?) != 0.
  The `beq` branch at 0xf44 targets 0x10d4 and is always taken.
  The `bne` branch at 0xf84 targets 0x1190, is taken when (a3(=0x40000) & s4(?)) != 0, and falls through when (a3(=0x40000) & s4(?)) == 0.
  The `bne` branch at 0xf90 targets 0x11a8, is taken when a4(?) != 0, and falls through when a4(?) == 0.
  The `bne` branch at 0xfa0 targets 0x11c0, is taken when (a5(=0x10000) & s4(?)) != 0, and falls through when (a5(=0x10000) & s4(?)) == 0.
  The `bne` branch at 0xfa8 targets 0x11dc, is taken when a6(?) != 0, and falls through when a6(?) == 0.
  The `bne` branch at 0xfb0 targets 0x11f8, is taken when a7(?) != 0, and falls through when a7(?) == 0.
  The `bne` branch at 0xfb8 targets 0x1214, is taken when t0(?) != 0, and falls through when t0(?) == 0.
  The `bne` branch at 0xfc4 targets 0x122c, is taken when t1(?) != 0, and falls through when t1(?) == 0.
  The `bne` branch at 0xfcc targets 0x1248, is taken when t2(?) != 0, and falls through when t2(?) == 0.
  The `bne` branch at 0xfd4 targets 0x1264, is taken when t3(?) != 0, and falls through when t3(?) == 0.
  The `bne` branch at 0xfdc targets 0x1280, is taken when t8(?) != 0, and falls through when t8(?) == 0.
  The `bne` branch at 0xff4 targets 0x1114, is taken when (t9(?) & ra(?)) != 0, and falls through when (t9(?) & ra(?)) == 0.
  The `bne` branch at 0x1004 targets 0xfe8, is taken when s1(?) < 0x10 (signed), and falls through when s1(?) >= 0x10 (signed).
  The `bne` branch at 0x1010 targets 0x113c, is taken when v0(=[sym(kdebug)]:2) != 0, and falls through when v0(=[sym(kdebug)]:2) == 0.
  The `beq` branch at 0x1024 targets 0xe04 and is always taken.
  The `beq` branch at 0x10cc targets 0xef8 and is always taken.
  The `bne` branch at 0x10f0 targets 0x129c, is taken when (s3(=[[a0+16]:8+84]) & 0x1) != 0, and falls through when (s3(=[[a0+16]:8+84]) & 0x1) == 0.
  The `bne` branch at 0x10f8 targets 0x12b8, is taken when a4(?) != 0, and falls through when a4(?) == 0.
  The `bne` branch at 0x1100 targets 0x12d4, is taken when a5(?) != 0, and falls through when a5(?) == 0.
  The `beq` branch at 0x110c targets 0xeec and is always taken.
  The `bne` branch at 0x112c targets 0xfe8, is taken when s1(?) < 0x10 (signed), and falls through when s1(?) >= 0x10 (signed).
  The `beq` branch at 0x1134 targets 0x1010 and is always taken.
  The `beq` branch at 0x1178 targets 0x101c, is taken when t0(?) == 0, and falls through when t0(?) != 0.
  The `beq` branch at 0x1188 targets 0x1018 and is always taken.
  The `beq` branch at 0x11a0 targets 0xf90 and is always taken.
  The `beq` branch at 0x11b8 targets 0xf9c and is always taken.
  The `beq` branch at 0x11d4 targets 0xfa8 and is always taken.
  The `beq` branch at 0x11f0 targets 0xfb0 and is always taken.
  The `beq` branch at 0x120c targets 0xfb8 and is always taken.
  The `beq` branch at 0x1224 targets 0xfc4 and is always taken.
  The `beq` branch at 0x1240 targets 0xfcc and is always taken.
  The `beq` branch at 0x125c targets 0xfd4 and is always taken.
  The `beq` branch at 0x1278 targets 0xfdc and is always taken.
  The `beq` branch at 0x1294 targets 0xfe4 and is always taken.
  The `beq` branch at 0x12b0 targets 0x10f8 and is always taken.
  The `beq` branch at 0x12cc targets 0x1100 and is always taken.
  The `beq` branch at 0x12e8 targets 0x1108 and is always taken.
  The `beq` branch at 0x1308 targets 0xe28 and is always taken.
  The return at 0xf1c has v0 = one of ?, ret(cmn_err_tag).

- `xbow_error_handler` in `IP27/usr/cpu/sysgen/IP27boot/xbow.o` at 0x1310 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xbow.o`.
  Range: 0x1310-0x19c0 (1712 bytes).
  It occupies 1712 bytes.
  The `lw` at 0x1310 loads 4 bytes from a0 (arg0 at entry) +0x8.
  The `ld` at 0x1314 loads 8 bytes from a0 (arg0 at entry) +0x10.
  The `lh` at 0x1334 loads 2 bytes from a3 (arg3 at entry) +0x6.
  The `lw` at 0x1358 loads 4 bytes from [a0+16]:8 +0xc.
  The `lw` at 0x135c loads 4 bytes from [a0+16]:8 +0x44.
  The `lw` at 0x1360 loads 4 bytes from [a0+16]:8 +0x14.
  The `lw` at 0x1364 loads 4 bytes from [a0+16]:8 +0x1c.
  3 such `lw` accesses load 4 bytes from ?, including `lw` at 0x13dc, `lw` at 0x13e0, `lw` at 0x13e4.
  3 such `lw` accesses load 4 bytes from [a0+16]:8 +0x4, including `lw` at 0x13e8, `lw` at 0x140c, `lw` at 0x14e8.
  The `lw` at 0x148c loads 4 bytes from a0 (arg0 at entry) +0x0.
  8 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x18, including `ld` at 0x1578, `ld` at 0x1598, `ld` at 0x1644.
  5 such `ld` accesses load 8 bytes from a3 (arg3 at entry) +0x18, including `ld` at 0x158c, `ld` at 0x1658, `ld` at 0x1810.
  2 such `lw` accesses load 4 bytes from a3 (arg3 at entry) +0x0, including `lw` at 0x17a0, `lw` at 0x1954.
  The `jal` at 0x1478 calls xbow_widget_lookup with a0=[a0+8], a1=[a3+6]:2, a2=?, a3=?.
  The `jal` at 0x1514 calls xtalk_error_handler with a0=ret(xbow_widget_lookup), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x157c calls cmn_err with a0=0x1, a1=sym(.rodata), a2=[a0+24]:8, a3=[a3+6]:2, a5=[a0+8].
  The `jal` at 0x159c calls cmn_err with a0=0x1, a1=sym(.rodata), a2=[a0+24]:8, a3=[a3+6]:2, a4=[a3+24]:8.
  The `jal` at 0x15b8 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?, a4=[sym(kdebug)]:2.
  The `jal` at 0x15cc calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[[a0+16]:8+12].
  The `jal` at 0x15e0 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[[a0+16]:8+68].
  The `jal` at 0x15f4 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[[a0+16]:8+20].
  The `jal` at 0x1608 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[[a0+16]:8+28].
  The `jal` at 0x162c calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x1648 calls cmn_err with a0=0x1, a1=sym(.rodata), a2=[a0+24]:8, a3=a3 at entry (arg3), a5=[a0+8].
  The `jal` at 0x1664 calls cmn_err with a0=0x1, a1=sym(.rodata), a2=[a0+24]:8, a3=[a3+24]:8.
  The `jal` at 0x1680 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x1694 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[[a0+16]:8+12].
  The `jal` at 0x16a8 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[[a0+16]:8+68].
  The `jal` at 0x16bc calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[[a0+16]:8+20].
  The `jal` at 0x16d0 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[[a0+16]:8+28].
  The `jal` at 0x16f4 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x170c calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[a3+6]:2.
  The `jal` at 0x1720 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x1734 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x1748 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x178c calls cmn_err with a0=0x1, a1=sym(.rodata), a2=sym(.rodata), a3=sym(.rodata), a4=[a0+24]:8, a5=[a3+6]:2.
  The `jal` at 0x17c8 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x17e0 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x1800 calls cmn_err with a0=0x1, a1=sym(.rodata), a2=[a0+24]:8, a3=[a3+6]:2.
  The `jal` at 0x1820 calls cmn_err with a0=0x1, a1=sym(.rodata), a2=[a0+24]:8, a3=[a3+6]:2, a4=[a3+24]:8.
  The `jal` at 0x1838 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?, a4=[sym(kdebug)]:2.
  The `jal` at 0x184c calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[[a0+16]:8+12].
  The `jal` at 0x1860 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[[a0+16]:8+68].
  The `jal` at 0x1874 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[[a0+16]:8+20].
  The `jal` at 0x1888 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[[a0+16]:8+28].
  The `jal` at 0x18ac calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x18c4 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[a3+6]:2.
  The `jal` at 0x18d8 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x18ec calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x1900 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x1940 calls cmn_err with a0=0x1, a1=sym(.rodata), a2=sym(.rodata), a3=sym(.rodata), a4=[a0+24]:8, a5=[a3+6]:2, a7=0x9.
  The `jal` at 0x199c calls cmn_err with a0=0x6, a1=sym(.rodata), a2=[a3+24]:8, a3=?, a5=([a3] << 0x7).
  The `jal` at 0x19b0 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=[a3+24]:8, a3=?, a5=([a3] << 0x7).
  The `beq` branch at 0x1350 targets 0x1450, is taken when s1(=[a3+6]:2) == 0, and falls through when s1(=[a3+6]:2) != 0.
  The `bne` branch at 0x1370 targets 0x1384, is taken when s1(=[a3+6]:2) < 0x8 (signed), and falls through when s1(=[a3+6]:2) >= 0x8 (signed).
  The `bne` branch at 0x137c targets 0x13d4, is taken when s1(=[a3+6]:2) < 0x10 (signed), and falls through when s1(=[a3+6]:2) >= 0x10 (signed).
  The `beq` branch at 0x1384 targets 0x14b4, is taken when s3(=a2) == 0, and falls through when s3(=a2) != 0.
  The `bne` branch at 0x138c targets 0x156c, is taken when a2(?) != 0, and falls through when a2(?) == 0.
  The `bne` branch at 0x1394 targets 0x158c, is taken when a3(?) != 0, and falls through when a3(?) == 0.
  The `bne` branch at 0x13a0 targets 0x15ac, is taken when a4(=[sym(kdebug)]:2) != 0, and falls through when a4(=[sym(kdebug)]:2) == 0.
  The `beq` branch at 0x1404 targets 0x1420, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `beq` branch at 0x141c targets 0x14e8, is taken when t1(?) == t2(=0xd100), and falls through when t1(?) != t2(=0xd100).
  The `beq` branch at 0x1428 targets 0x14bc, is taken when (t2(?) & 0x20) == 0, and falls through when (t2(?) & 0x20) != 0.
  The `bne` branch at 0x1438 targets 0x1474, is taken when (t3(?) & t8(=0xffffffff80000000)) != 0, and falls through when (t3(?) & t8(=0xffffffff80000000)) == 0.
  The `bne` branch at 0x1440 targets 0x1758, is taken when s3(=a2) != 0, and falls through when s3(=a2) == 0.
  The `beq` branch at 0x1448 targets 0x13a8 and is always taken.
  The `beq` branch at 0x1450 targets 0x154c, is taken when a2 == 0, and falls through when a2 != 0.
  The `bne` branch at 0x1458 targets 0x163c, is taken when t9(?) != 0, and falls through when t9(?) == 0.
  The `bne` branch at 0x1460 targets 0x1658, is taken when ra(?) != 0, and falls through when ra(?) == 0.
  The `beq` branch at 0x1468 targets 0x13a8 and is always taken.
  The `beq` branch at 0x1484 targets 0x153c, is taken when v0(=ret(xbow_widget_lookup)) == at(=-0x1), and falls through when v0(=ret(xbow_widget_lookup)) != at(=-0x1).
  The `bne` branch at 0x1490 targets 0x150c, is taken when v1(=[a0]) != v0(=ret(xbow_widget_lookup)), and falls through when v1(=[a0]) == v0(=ret(xbow_widget_lookup)).
  The `beq` branch at 0x1498 targets 0x1554, is taken when s3(=a2) == 0, and falls through when s3(=a2) != 0.
  The `bne` branch at 0x14a4 targets 0x1674, is taken when a1(=[sym(kdebug)]:2) != 0, and falls through when a1(=[sym(kdebug)]:2) == 0.
  The `beq` branch at 0x14ac targets 0x13a8 and is always taken.
  The `beq` branch at 0x14b4 targets 0x13a8 and is always taken.
  The `beq` branch at 0x14bc targets 0x155c, is taken when s3(=a2) == 0, and falls through when s3(=a2) != 0.
  The `bne` branch at 0x14c4 targets 0x17f0, is taken when a2(?) != 0, and falls through when a2(?) == 0.
  The `bne` branch at 0x14cc targets 0x1810, is taken when a3(?) != 0, and falls through when a3(?) == 0.
  The `bne` branch at 0x14d8 targets 0x1830, is taken when a4(=[sym(kdebug)]:2) != 0, and falls through when a4(=[sym(kdebug)]:2) == 0.
  The `beq` branch at 0x14e0 targets 0x13a8 and is always taken.
  The `bne` branch at 0x14f4 targets 0x1420, is taken when (a5(?) & 0x7ff) != 0, and falls through when (a5(?) & 0x7ff) == 0.
  The `bne` branch at 0x14fc targets 0x1424, is taken when s1(=[a3+6]:2) != a6(=0xf), and falls through when s1(=[a3+6]:2) == a6(=0xf).
  The `beq` branch at 0x1504 targets 0x1430 and is always taken.
  The `beq` branch at 0x151c targets 0x1564, is taken when v0(=ret(xtalk_error_handler)) == 0, and falls through when v0(=ret(xtalk_error_handler)) != 0.
  The `beq` branch at 0x1524 targets 0x1554, is taken when s3(=a2) == 0, and falls through when s3(=a2) != 0.
  The `bne` branch at 0x152c targets 0x14a4, is taken when v0(=ret(xtalk_error_handler)) != a7(=0x9), and falls through when v0(=ret(xtalk_error_handler)) == a7(=0x9).
  The `beq` branch at 0x1534 targets 0x1910 and is always taken.
  The `beq` branch at 0x153c targets 0x1554, is taken when s3(=a2) == 0, and falls through when s3(=a2) != 0.
  The `beq` branch at 0x1544 targets 0x14a0 and is always taken.
  The `beq` branch at 0x154c targets 0x13a8 and is always taken.
  The `beq` branch at 0x1554 targets 0x13a8 and is always taken.
  The `beq` branch at 0x155c targets 0x13a8 and is always taken.
  The `beq` branch at 0x1564 targets 0x13a8 and is always taken.
  The `beq` branch at 0x1584 targets 0x1394 and is always taken.
  The `beq` branch at 0x15a4 targets 0x13a0 and is always taken.
  The `beq` branch at 0x1634 targets 0x13a8 and is always taken.
  The `beq` branch at 0x1650 targets 0x1460 and is always taken.
  The `beq` branch at 0x166c targets 0x1468 and is always taken.
  The `beq` branch at 0x1750 targets 0x14ac and is always taken.
  The `beq` branch at 0x1758 targets 0x196c, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0x176c targets 0x1974, is taken when (s2(=a1) & 0x4) == 0, and falls through when (s2(=a1) & 0x4) != 0.
  The `beq` branch at 0x1798 targets 0x17b0, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `bltz` branch at 0x17a8 targets 0x1994, is taken when a5(=([a3] << 0x7)) < 0 (signed), and falls through when a5(=([a3] << 0x7)) >= 0 (signed).
  The `beq` branch at 0x17b4 targets 0x17d8, is taken when (a6(?) & 0x40) == 0, and falls through when (a6(?) & 0x40) != 0.
  The `beq` branch at 0x17d0 targets 0x1474 and is always taken.
  The `beq` branch at 0x17e8 targets 0x1474 and is always taken.
  The `beq` branch at 0x1808 targets 0x14cc and is always taken.
  The `beq` branch at 0x1828 targets 0x14d8 and is always taken.
  The `beq` branch at 0x1908 targets 0x14e0 and is always taken.
  The `beq` branch at 0x1910 targets 0x1980, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0x1924 targets 0x1988, is taken when (s2(=a1) & 0x4) == 0, and falls through when (s2(=a1) & 0x4) != 0.
  The `beq` branch at 0x194c targets 0x1964, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `bltz` branch at 0x195c targets 0x19ac, is taken when a5(=([a3] << 0x7)) < 0 (signed), and falls through when a5(=([a3] << 0x7)) >= 0 (signed).
  The `beq` branch at 0x1964 targets 0x14a0 and is always taken.
  The `beq` branch at 0x196c targets 0x1768 and is always taken.
  The `beq` branch at 0x1978 targets 0x177c and is always taken.
  The `beq` branch at 0x1980 targets 0x1920 and is always taken.
  The `beq` branch at 0x198c targets 0x1934 and is always taken.
  The `beq` branch at 0x19a4 targets 0x17b0 and is always taken.
  The `beq` branch at 0x19b8 targets 0x1964 and is always taken.
  The return at 0x13cc has v0 = one of 0x6, 0x0, ?.
  The instructions from 0x1470 to 0x1470 are not reached by any path from the entry, and their branches are not listed.

- `xbow_update_perf_counters` in `IP27/usr/cpu/sysgen/IP27boot/xbow.o` at 0x19c0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xbow.o`.
  Range: 0x19c0-0x1ac8 (264 bytes).
  It occupies 264 bytes.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0x1a0c, `ld` at 0x1a44.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0x1a10, `lw` at 0x1a1c.
  2 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x1a14, `lbu` at 0x1a74.
  The `sd` at 0x1a54 stores 8 bytes to ?.
  The `sw` at 0x1a60 stores 4 bytes to ?.
  The `jal` at 0x19e0 calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1a04 calls mutex_spinlock with a0=ret(hwgraph_fastinfo_get)+448, a1=?, a2=?, a3=?.
  The `jal` at 0x1a5c calls mutex_spinunlock with a0=ret(hwgraph_fastinfo_get)+448, a1=ret(mutex_spinlock), a2=?, a3=?.
  The `jal` at 0x1a9c calls timeout with a0=sym(xbow_update_perf_counters), a1=?, a2=0x4, a3=?.
  The `beq` branch at 0x19fc targets 0x1a74 and is always taken.
  The `beq` branch at 0x1a6c targets 0x1a90, is taken when s1(?) >= 0x2 (signed), and falls through when s1(?) < 0x2 (signed).
  The `bne` branch at 0x1a78 targets 0x1a04, is taken when ra(?) != 0, and falls through when ra(?) == 0.
  The `bne` branch at 0x1a88 targets 0x1a74, is taken when s1(?) < 0x2 (signed), and falls through when s1(?) >= 0x2 (signed).
  The return at 0x1ac0 has v0 = ret(timeout).

- `xbow_enable_perf_counter` in `IP27/usr/cpu/sysgen/IP27boot/xbow.o` at 0x1ae8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xbow.o`.
  Range: 0x1ae8-0x1cb4 (460 bytes).
  It occupies 460 bytes.
  The `ld` at 0x1b28 loads 8 bytes from ret(hwgraph_fastinfo_get) +0x10.
  The `lbu` at 0x1ba0 loads 1 byte from (ret(hwgraph_fastinfo_get) + (a3 << 0x4)) +0x25.
  2 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x1bdc, `lbu` at 0x1be8.
  The `sb` at 0x1c08 stores 1 byte to (ret(hwgraph_fastinfo_get) + (a3 << 0x4)) +0x27.
  The `sb` at 0x1c0c stores 1 byte to (ret(hwgraph_fastinfo_get) + (a3 << 0x4)) +0x25.
  The `sb` at 0x1c14 stores 1 byte to (ret(hwgraph_fastinfo_get) + (a3 << 0x4)) +0x26.
  The `sb` at 0x1c1c stores 1 byte to (ret(hwgraph_fastinfo_get) + (a3 << 0x4)) +0x24.
  The `lw` at 0x1c28 loads 4 bytes from ([ret(hwgraph_fastinfo_get)+16]:8 + (a1 << 0x6)) -0xf4.
  The `sw` at 0x1c40 stores 4 bytes to ([ret(hwgraph_fastinfo_get)+16]:8 + (a1 << 0x6)) -0xf4.
  The `ld` at 0x1c48 loads 8 bytes from (ret(hwgraph_fastinfo_get) + (a3 << 0x4)) +0x28.
  The `lw` at 0x1c60 loads 4 bytes from [(ret(hwgraph_fastinfo_get) + (a3 << 0x4))+40]:8 +0x0.
  The `sw` at 0x1c80 stores 4 bytes to [(ret(hwgraph_fastinfo_get) + (a3 << 0x4))+40]:8 +0x0.
  The `sw` at 0x1c8c stores 4 bytes to (ret(hwgraph_fastinfo_get) + (a3 << 0x4)) +0x20.
  The `jal` at 0x1b0c calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1b8c calls mutex_spinlock with a0=ret(hwgraph_fastinfo_get)+448, a1=?, a2=?, a3=?, a6=[ret(hwgraph_fastinfo_get)+16]:8.
  The `jal` at 0x1bf8 calls mutex_spinunlock with a0=ret(hwgraph_fastinfo_get)+448, a1=ret(mutex_spinlock), a2=?, a3=?, a7=a1-8.
  The `jal` at 0x1c88 calls timeout with a0=sym(xbow_update_perf_counters), a1=?, a2=0x4, a3=([ret(hwgraph_fastinfo_get)+16]:8 + (a1 << 0x6)), a6=0xfffff.
  The `jal` at 0x1c94 calls mutex_spinunlock with a0=ret(hwgraph_fastinfo_get)+448, a1=ret(mutex_spinlock), a2=?, a3=?.
  The `jal` at 0x1ca4 calls mutex_spinunlock with a0=ret(hwgraph_fastinfo_get)+448, a1=ret(mutex_spinlock), a2=?, a3=?, a6=0x0, a7=a1-8.
  The `bne` branch at 0x1b2c targets 0x1b60, is taken when s3(=a1) < 0x8 (signed), and falls through when s3(=a1) >= 0x8 (signed).
  The `beq` branch at 0x1b34 targets 0x1b60, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `bltz` branch at 0x1b3c targets 0x1b80, is taken when s2(=a2) < 0 (signed), and falls through when s2(=a2) >= 0 (signed).
  The `beq` branch at 0x1b44 targets 0x1b80, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `bltz` branch at 0x1b4c targets 0x1b5c, is taken when s0(=a3) < 0 (signed), and falls through when s0(=a3) >= 0 (signed).
  The `bne` branch at 0x1b54 targets 0x1b88, is taken when a3(?) != 0, and falls through when a3(?) == 0.
  The `beq` branch at 0x1b80 targets 0x1b60 and is always taken.
  The `beq` branch at 0x1ba8 targets 0x1bd0, is taken when v0(=[(ret(hwgraph_fastinfo_get) + (a3 << 0x4))+37]:1) == 0, and falls through when v0(=[(ret(hwgraph_fastinfo_get) + (a3 << 0x4))+37]:1) != 0.
  The `beq` branch at 0x1bb0 targets 0x1bd0, is taken when s2(=a2) == 0, and falls through when s2(=a2) != 0.
  The `beq` branch at 0x1bb8 targets 0x1ca4 and is always taken.
  The `beq` branch at 0x1bc8 targets 0x1c08, is taken when a6(?) >= 0x2 (signed), and falls through when a6(?) < 0x2 (signed).
  The `beq` branch at 0x1bd0 targets 0x1bc0, is taken when s0(=a3) == a6(?), and falls through when s0(=a3) != a6(?).
  The `bne` branch at 0x1be0 targets 0x1bc0, is taken when a7(=a1-8) != t2(?), and falls through when a7(=a1-8) == t2(?).
  The `beq` branch at 0x1bec targets 0x1bc4, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0x1c00 targets 0x1b60 and is always taken.
  The `beq` branch at 0x1c9c targets 0x1b60 and is always taken.
  The `beq` branch at 0x1cac targets 0x1b60 and is always taken.
  The return at 0x1b78 has v0 = one of -0x1, 0x0.

- `xbow_update_llp_status` in `IP27/usr/cpu/sysgen/IP27boot/xbow.o` at 0x1cd4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xbow.o`.
  Range: 0x1cd4-0x1de8 (276 bytes).
  It occupies 276 bytes.
  The `ld` at 0x1d0c loads 8 bytes from ret(hwgraph_fastinfo_get) +0x10.
  The `lw` at 0x1d18 loads 4 bytes from ret(hwgraph_fastinfo_get) +0x8.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0x1d34, `lw` at 0x1d38.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0x1d50, `ld` at 0x1d58.
  2 such `sd` accesses store 8 bytes to ?, including `sd` at 0x1d60, `sd` at 0x1d6c.
  The `lw` at 0x1d84 loads 4 bytes from ret(hwgraph_fastinfo_get) +0x1c4.
  The `jal` at 0x1cf4 calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1d1c calls xbow_widget_lookup with a0=[ret(hwgraph_fastinfo_get)+8], a1=?, a2=?, a3=?.
  The `jal` at 0x1d24 calls xwidget_name_get with a0=ret(xbow_widget_lookup), a1=?, a2=?, a3=?.
  The `jal` at 0x1d9c calls timeout with a0=sym(xbow_update_llp_status), a1=?, a2=0x64, a3=?.
  The `jal` at 0x1dd8 calls cmn_err with a0=0x4, a1=sym(.rodata), a2=?, a3=ret(xwidget_name_get).
  The `beq` branch at 0x1d48 targets 0x1d70, is taken when t8(?) == 0, and falls through when t8(?) != 0.
  The `bne` branch at 0x1d68 targets 0x1dc8, is taken when a6(?) != 0, and falls through when a6(?) == 0.
  The `bne` branch at 0x1d7c targets 0x1d18, is taken when s0(?) < 0x8 (signed), and falls through when s0(?) >= 0x8 (signed).
  The `beq` branch at 0x1d88 targets 0x1da4, is taken when t3(=[ret(hwgraph_fastinfo_get)+452]) == 0, and falls through when t3(=[ret(hwgraph_fastinfo_get)+452]) != 0.
  The `beq` branch at 0x1de0 targets 0x1d74 and is always taken.
  The return at 0x1dc0 has v0 = one of ?, ret(timeout).

- `xbow_disable_llp_monitor` in `IP27/usr/cpu/sysgen/IP27boot/xbow.o` at 0x1de8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xbow.o`.
  Range: 0x1de8-0x1e30 (72 bytes).
  It occupies 72 bytes.
  2 such `sd` accesses store 8 bytes to ?, including `sd` at 0x1e14, `sd` at 0x1e1c.
  The `sw` at 0x1e24 stores 4 bytes to ret(hwgraph_fastinfo_get) +0x1c4.
  The `jal` at 0x1df0 calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `bne` branch at 0x1e18 targets 0x1e04, is taken when a2(?) < 0x8 (signed), and falls through when a2(?) >= 0x8 (signed).
  The return at 0x1e28 has v0 = 0x0.

- `xbow_enable_llp_monitor` in `IP27/usr/cpu/sysgen/IP27boot/xbow.o` at 0x1e30 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xbow.o`.
  Range: 0x1e30-0x1e7c (76 bytes).
  It occupies 76 bytes.
  The `sw` at 0x1e78 stores 4 bytes to ret(hwgraph_fastinfo_get) +0x1c4.
  The `jal` at 0x1e3c calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1e54 calls timeout with a0=sym(xbow_update_llp_status), a1=?, a2=0x64, a3=?.
  The return at 0x1e74 has v0 = 0x0.

- `xbow_get_bridge_pointers` in `IP27/usr/cpu/sysgen/IP27boot/xbow.o` at 0x1e7c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xbow.o`.
  Range: 0x1e7c-0x20f0 (628 bytes).
  It occupies 628 bytes.
  The `lh` at 0x1e9c loads 2 bytes from (sym(compact_to_nasid_node) + (a0 + a0)) +0x0.
  2 such `sd` accesses store 8 bytes to ?, including `sd` at 0x1ebc, `sd` at 0x1ed8.
  The `ld` at 0x1edc loads 8 bytes from abs 0xffffffffffffc400.
  The `ld` at 0x1ee0 loads 8 bytes from [-0x3c00]:8 +0x0.
  The `ld` at 0x1ef0 loads 8 bytes from ([[-0x3c00]:8]:8 + (a0 << 0x3)) +0x0.
  The `lw` at 0x1f00 loads 4 bytes from [([[-0x3c00]:8]:8 + (a0 << 0x3))]:8 +0x5150.
  2 such `lw` accesses load 4 bytes from ret(xwidget_info_get) +0x10, including `lw` at 0x1f48, `lw` at 0x209c.
  6 such `lw` accesses load 4 bytes from ret(xwidget_info_get) +0x18, including `lw` at 0x1f74, `lw` at 0x1fc4, `lw` at 0x2008.
  4 such `lbu` accesses load 1 byte from ret(xwidget_info_get) +0xc, including `lbu` at 0x1f84, `lbu` at 0x2030, `lbu` at 0x20c4.
  The `sd` at 0x1fac stores 8 bytes to a1 (arg1 at entry) +0x0.
  2 such `lw` accesses load 4 bytes from a2 (arg2 at entry) +0x0, including `lw` at 0x1fb0, `lw` at 0x2064.
  2 such `sw` accesses store 4 bytes to a2 (arg2 at entry) +0x0, including `sw` at 0x1fb8, `sw` at 0x206c.
  The `sd` at 0x205c stores 8 bytes to (a1 + ([ret(xwidget_info_get)+12]:1 << 0x3)) +0x0.
  The `jal` at 0x1efc calls hwgraph_traverse with a0=[[([[-0x3c00]:8]:8 + (a0 << 0x3))]:8+20816], a1=sym(.rodata), a2=sp-336, a3=a3 at entry (arg3), a5=a0 at entry (arg0).
  The `jal` at 0x1f28 calls hwgraph_traverse with a0=?, a1=sym(.rodata), a2=sp-332, a3=?.
  The `jal` at 0x1f40 calls xwidget_info_get with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1fe0 calls hwgraph_edge_get_next with a0=?, a1=sp-320, a2=sp-64, a3=sp-328, a4=0x2.
  The `jal` at 0x207c calls hwgraph_edge_get_next with a0=?, a1=sp-320, a2=sp-64, a3=sp-328.
  The `jal` at 0x208c calls xwidget_info_get with a0=?, a1=?, a2=?, a3=?.
  The `beq` branch at 0x1ec0 targets 0x1edc, is taken when v0(?) >= 0x10 (signed), and falls through when v0(?) < 0x10 (signed).
  The `bne` branch at 0x1ed4 targets 0x1eac, is taken when v0(?) < 0x10 (signed), and falls through when v0(?) >= 0x10 (signed).
  The `beq` branch at 0x1f04 targets 0x1f1c, is taken when v0(=ret(hwgraph_traverse)) == 0, and falls through when v0(=ret(hwgraph_traverse)) != 0.
  The `beq` branch at 0x1f30 targets 0x1f40, is taken when v0(=ret(hwgraph_traverse)) == 0, and falls through when v0(=ret(hwgraph_traverse)) != 0.
  The `beq` branch at 0x1f38 targets 0x1f0c and is always taken.
  The `beq` branch at 0x1f4c targets 0x2008, is taken when a0(=[ret(xwidget_info_get)+16]) == 0, and falls through when a0(=[ret(xwidget_info_get)+16]) != 0.
  The `beq` branch at 0x1f54 targets 0x1fc4, is taken when a0(=[ret(xwidget_info_get)+16]) == a2(=0xd000), and falls through when a0(=[ret(xwidget_info_get)+16]) != a2(=0xd000).
  The `beq` branch at 0x1f5c targets 0x1fc4, is taken when a0(=[ret(xwidget_info_get)+16]) == a3(=0xd100), and falls through when a0(=[ret(xwidget_info_get)+16]) != a3(=0xd100).
  The `beq` branch at 0x1f64 targets 0x201c, is taken when a0(=[ret(xwidget_info_get)+16]) == a4(=0xc002), and falls through when a0(=[ret(xwidget_info_get)+16]) != a4(=0xc002).
  The `bne` branch at 0x1f6c targets 0x1fbc, is taken when a0(=[ret(xwidget_info_get)+16]) != a5(=0xd002), and falls through when a0(=[ret(xwidget_info_get)+16]) == a5(=0xd002).
  The `bne` branch at 0x1f7c targets 0x1fbc, is taken when a6(=[ret(xwidget_info_get)+24]) != a7(=0x24), and falls through when a6(=[ret(xwidget_info_get)+24]) == a7(=0x24).
  The `beq` branch at 0x1f8c targets 0x2034, is taken when a1(=[ret(xwidget_info_get)+12]:1) == 0, and falls through when a1(=[ret(xwidget_info_get)+12]:1) != 0.
  The `beq` branch at 0x1fbc targets 0x1f0c and is always taken.
  The `bne` branch at 0x1fc8 targets 0x1f60, is taken when a1(=[ret(xwidget_info_get)+24]) != 0, and falls through when a1(=[ret(xwidget_info_get)+24]) == 0.
  The `bne` branch at 0x1fe8 targets 0x1fbc, is taken when v0(=ret(hwgraph_edge_get_next)) != 0, and falls through when v0(=ret(hwgraph_edge_get_next)) == 0.
  The `beq` branch at 0x2000 targets 0x208c and is always taken.
  The `bne` branch at 0x200c targets 0x1f54, is taken when a6(=[ret(xwidget_info_get)+24]) != 0, and falls through when a6(=[ret(xwidget_info_get)+24]) == 0.
  The `beq` branch at 0x2014 targets 0x1fd0 and is always taken.
  The `bne` branch at 0x2024 targets 0x1f6c, is taken when a7(=[ret(xwidget_info_get)+24]) != t0(=0x36), and falls through when a7(=[ret(xwidget_info_get)+24]) == t0(=0x36).
  The `beq` branch at 0x202c targets 0x1f88 and is always taken.
  The `beq` branch at 0x2038 targets 0x1fa8 and is always taken.
  The `bne` branch at 0x2084 targets 0x1fbc, is taken when v0(=ret(hwgraph_edge_get_next)) != 0, and falls through when v0(=ret(hwgraph_edge_get_next)) == 0.
  The `beq` branch at 0x2094 targets 0x2074, is taken when v0(=ret(xwidget_info_get)) == 0, and falls through when v0(=ret(xwidget_info_get)) != 0.
  The `beq` branch at 0x20a4 targets 0x20d8, is taken when a0(=[ret(xwidget_info_get)+16]) == a4(=0xc002), and falls through when a0(=[ret(xwidget_info_get)+16]) != a4(=0xc002).
  The `bne` branch at 0x20ac targets 0x2074, is taken when a0(=[ret(xwidget_info_get)+16]) != a5(=0xd002), and falls through when a0(=[ret(xwidget_info_get)+16]) == a5(=0xd002).
  The `bne` branch at 0x20bc targets 0x2074, is taken when a6(=[ret(xwidget_info_get)+24]) != a7(=0x24), and falls through when a6(=[ret(xwidget_info_get)+24]) == a7(=0x24).
  The `bne` branch at 0x20c8 targets 0x2040, is taken when a0(=[ret(xwidget_info_get)+12]:1) != 0, and falls through when a0(=[ret(xwidget_info_get)+12]:1) == 0.
  The `beq` branch at 0x20d0 targets 0x2054 and is always taken.
  The `bne` branch at 0x20e0 targets 0x20ac, is taken when t0(=[ret(xwidget_info_get)+24]) != t1(=0x36), and falls through when t0(=[ret(xwidget_info_get)+24]) == t1(=0x36).
  The `beq` branch at 0x20e8 targets 0x20c8 and is always taken.
  The return at 0x1f14 has v0 = 0x0.

- `xbow_disable` in `IP27/usr/cpu/sysgen/IP27boot/xbow.o` at 0x20f0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xbow.o`.
  Range: 0x20f0-0x2178 (136 bytes).
  It occupies 136 bytes.
  The `lw` at 0x2124 loads 4 bytes from ret(hwgraph_fastinfo_get) +0x8.
  The `jal` at 0x210c calls cmn_err with a0=0x1, a1=sym(.rodata), a2=a0 at entry (arg0), a3=a3 at entry (arg3).
  The `jal` at 0x2114 calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x2134 calls hwgraph_edge_get_next with a0=[ret(hwgraph_fastinfo_get)+8], a1=sp-280, a2=sp-24, a3=sp-288, a4=0x2.
  The `jal` at 0x2160 calls hwgraph_edge_get_next with a0=[ret(hwgraph_fastinfo_get)+8], a1=sp-280, a2=sp-24, a3=sp-288.
  The `beq` branch at 0x213c targets 0x2154, is taken when v0(=ret(hwgraph_edge_get_next)) == 0, and falls through when v0(=ret(hwgraph_edge_get_next)) != 0.
  The `beq` branch at 0x2168 targets 0x2158, is taken when v0(=ret(hwgraph_edge_get_next)) == 0, and falls through when v0(=ret(hwgraph_edge_get_next)) != 0.
  The `beq` branch at 0x2170 targets 0x2144 and is always taken.
  The return at 0x214c has v0 = -0x1.

- `xbow_enable` in `IP27/usr/cpu/sysgen/IP27boot/xbow.o` at 0x2178 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xbow.o`.
  Range: 0x2178-0x21f4 (124 bytes).
  It occupies 124 bytes.
  The `jal` at 0x2194 calls cmn_err with a0=0x1, a1=sym(.rodata), a2=a0 at entry (arg0), a3=a3 at entry (arg3).
  The `jal` at 0x21b0 calls hwgraph_edge_get_next with a0=a0 at entry (arg0), a1=sp-280, a2=sp-24, a3=sp-288, a4=0x2.
  The `jal` at 0x21dc calls hwgraph_edge_get_next with a0=a0 at entry (arg0), a1=sp-280, a2=sp-24, a3=sp-288.
  The `beq` branch at 0x21b8 targets 0x21d0, is taken when v0(=ret(hwgraph_edge_get_next)) == 0, and falls through when v0(=ret(hwgraph_edge_get_next)) != 0.
  The `beq` branch at 0x21e4 targets 0x21d4, is taken when v0(=ret(hwgraph_edge_get_next)) == 0, and falls through when v0(=ret(hwgraph_edge_get_next)) != 0.
  The `beq` branch at 0x21ec targets 0x21c0 and is always taken.
  The return at 0x21c8 has v0 = -0x1.

- `idbg_xbowregs` in `IP27/usr/cpu/sysgen/IP27boot/xbow.o` at 0x22f8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xbow.o`.
  Range: 0x22f8-0x23dc (228 bytes).
  It occupies 228 bytes.
  16 such `lw` accesses load 4 bytes from ?, including `lw` at 0x2334, `lw` at 0x2338, `lw` at 0x233c.
  The `ld` at 0x23d8 loads 8 bytes from ret(hwgraph_fastinfo_get) +0x10.
  The `jal` at 0x232c calls qprintf with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jal` at 0x234c calls qprintf with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jal` at 0x2368 calls qprintf with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jal` at 0x2378 calls qprintf with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jal` at 0x23a0 calls qprintf with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jal` at 0x23cc calls hwgraph_fastinfo_get with a0=(a0 << 0x0), a1=(a0 << 0x0), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0x231c targets 0x23cc, is taken when (at(?) & 0x1ff) == 0, and falls through when (at(?) & 0x1ff) != 0.
  The `bne` branch at 0x23b0 targets 0x2374, is taken when s0(?) < 0x10 (signed), and falls through when s0(?) >= 0x10 (signed).
  The `beq` branch at 0x23d4 targets 0x2324 and is always taken.
  The return at 0x23c4 has v0 = ret(qprintf).

- `xbow_bytes_to_gbr` in `IP27/usr/cpu/sysgen/IP27boot/xbow.o` at 0x23dc (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xbow.o`.
  Range: 0x23dc-0x2440 (100 bytes).
  It occupies 100 bytes.
  The `beq` branch at 0x2404 targets 0x2410, is taken when at(?) >= a0 (signed), and falls through when at(?) < a0 (signed).
  The `bne` branch at 0x242c targets 0x2438, is taken when a7(?) < a5(=(a0 + a1)) (signed), and falls through when a7(?) >= a5(=(a0 + a1)) (signed).
  The return at 0x2438 has v0 = ?.

- `xbow_gbr_to_bytes` in `IP27/usr/cpu/sysgen/IP27boot/xbow.o` at 0x2440 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xbow.o`.
  Range: 0x2440-0x2458 (24 bytes).
  It occupies 24 bytes.
  The return at 0x2450 has v0 = ?.

- `xbow_prio_bw_alloc` in `IP27/usr/cpu/sysgen/IP27boot/xbow.o` at 0x2458 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/xbow.o`.
  Range: 0x2458-0x25cc (372 bytes).
  It occupies 372 bytes.
  2 such `ld` accesses load 8 bytes from ret(hwgraph_fastinfo_get) +0x10, including `ld` at 0x24c8, `ld` at 0x24cc.
  The `ld` at 0x2510 loads 8 bytes from (ret(hwgraph_fastinfo_get) + (a2 << 0x3)) +0x210.
  The `ld` at 0x2518 loads 8 bytes from (ret(hwgraph_fastinfo_get) + (a2 << 0x3)) +0x1d0.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0x251c, `lw` at 0x2528.
  The `sw` at 0x25bc stores 4 bytes to ?.
  The `sd` at 0x25c0 stores 8 bytes to (ret(hwgraph_fastinfo_get) + (a2 << 0x3)) +0x210.
  The `jal` at 0x2484 calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x2498 calls mutex_spinlock with a0=ret(hwgraph_fastinfo_get)+520, a1=?, a2=?, a3=?.
  The `jal` at 0x24e8 calls xbow_bytes_to_gbr with a0=a3 at entry (arg3), a1=a4 at entry (arg4), a2=one of 0x1c, 0x24, a3=?.
  The `jal` at 0x24fc calls xbow_gbr_to_bytes with a0=ret(xbow_bytes_to_gbr), a1=?, a2=?, a3=?.
  The `jal` at 0x256c calls mutex_spinunlock with a0=ret(hwgraph_fastinfo_get)+520, a1=ret(mutex_spinlock), a2=?, a3=?.
  The `jal` at 0x2590 calls xbow_gbr_to_bytes with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x25b8 calls xbow_gbr_to_bytes with a0=?, a1=?, a2=?, a3=?, a4=(ret(hwgraph_fastinfo_get) + (a2 << 0x3)).
  The `bne` branch at 0x24b0 targets 0x24cc, is taken when s0(=a1) < 0x8 (signed), and falls through when s0(=a1) >= 0x8 (signed).
  The `beq` branch at 0x24b8 targets 0x24cc, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x24c4 targets 0x24d0 and is always taken.
  The `bltz` branch at 0x24f4 targets 0x2590, is taken when v0(=ret(xbow_bytes_to_gbr)) < 0 (signed), and falls through when v0(=ret(xbow_bytes_to_gbr)) >= 0 (signed).
  The `bne` branch at 0x253c targets 0x2554, is taken when v1(=[(ret(hwgraph_fastinfo_get) + (a2 << 0x3))+464]:8) < a0(?) (unsigned), and falls through when v1(=[(ret(hwgraph_fastinfo_get) + (a2 << 0x3))+464]:8) >= a0(?) (unsigned).
  The `bne` branch at 0x254c targets 0x25a0, is taken when a0(?) < 0x20 (signed), and falls through when a0(?) >= 0x20 (signed).
  The `beq` branch at 0x2598 targets 0x2508 and is always taken.
  The `beq` branch at 0x25c4 targets 0x2558 and is always taken.
  The return at 0x2588 has v0 = one of 0x0, 0x1.
