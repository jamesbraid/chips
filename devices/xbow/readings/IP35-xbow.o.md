# Readings: `IP35/usr/cpu/sysgen/IP35boot/xbow.o`

One entry per routine, filed here from the reading batches by binary.

- `xbow_widget_num_get` in `IP35/usr/cpu/sysgen/IP35boot/xbow.o` at 0x3e8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/xbow.o`.
  Range: 0x3e8-0x4ac (196 bytes).
  It occupies 196 bytes.
  The `jal` at 0x3f8 calls vertex_to_name with a0=a0 at entry (arg0), a1=sp-288, a2=0x100, a3=a3 at entry (arg3).
  The `jal` at 0x408 calls strstr with a0=sp-288, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x420 calls strstr with a0=sp-288, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x448 calls hwgraph_edge_get with a0=a0 at entry (arg0), a1=sym(.rodata), a2=sp-32, a3=?.
  The `jal` at 0x484 calls xwidget_info_chk with a0=a0 at entry (arg0), a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x49c calls xwidget_info_id_get with a0=ret(xwidget_info_chk), a1=?, a2=?, a3=0xff.
  The `beq` branch at 0x410 targets 0x460, is taken when v0(=ret(strstr)) == 0, and falls through when v0(=ret(strstr)) != 0.
  The `beq` branch at 0x428 targets 0x464, is taken when v0(=ret(strstr)) == 0, and falls through when v0(=ret(strstr)) != 0.
  The `beq` branch at 0x450 targets 0x478, is taken when v0(=ret(hwgraph_edge_get)) == 0, and falls through when v0(=ret(hwgraph_edge_get)) != 0.
  The `beq` branch at 0x458 targets 0x464 and is always taken.
  The `bne` branch at 0x47c targets 0x440, is taken when s0(?) < 0x2 (signed), and falls through when s0(?) >= 0x2 (signed).
  The `bne` branch at 0x48c targets 0x49c, is taken when v0(=ret(xwidget_info_chk)) != 0, and falls through when v0(=ret(xwidget_info_chk)) == 0.
  The `beq` branch at 0x494 targets 0x468 and is always taken.
  The `beq` branch at 0x4a4 targets 0x464 and is always taken.
  The return at 0x470 has v0 = one of ?, 0xff.

- `xbow_ioctl` in `IP35/usr/cpu/sysgen/IP35boot/xbow.o` at 0x4ac (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/xbow.o`.
  Range: 0x4ac-0x818 (876 bytes).
  It occupies 876 bytes.
  The `sw` at 0x4ac stores 4 bytes to a5 (arg5 at entry) +0x0.
  The `jal` at 0x54c calls xbow_get_perf_counters with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0x564 calls copyout with a0=ret(xbow_get_perf_counters), a1=a2 at entry (arg2), a2=0x100, a3=?.
  The `jal` at 0x590 calls cap_able_cred with a0=a4 at entry (arg4), a1=0x2000000000, a2=0x1, a3=a3 at entry (arg3).
  The `jal` at 0x5ac calls copyin with a0=a2 at entry (arg2), a1=sp-64, a2=0xc, a3=?.
  The `jal` at 0x5d4 calls xbow_get_llp_status with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=0x6.
  The `jal` at 0x5ec calls copyout with a0=ret(xbow_get_llp_status), a1=a2 at entry (arg2), a2=0x80, a3=?.
  The `jal` at 0x614 calls cap_able_cred with a0=a4 at entry (arg4), a1=0x2000000000, a2=?, a3=?, a5=0x4.
  The `jal` at 0x644 calls cap_able_cred with a0=a4 at entry (arg4), a1=0x2000000000, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x65c calls xbow_disable_llp_monitor with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x670 calls cap_able with a0=0x2000000000, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=0x6.
  The `jal` at 0x684 calls copyin with a0=a2 at entry (arg2), a1=sp-96, a2=0x10, a3=?.
  The `jal` at 0x6b0 calls cap_able with a0=0x2000000000, a1=0x6702, a2=a2 at entry (arg2), a3=0x6.
  The `jal` at 0x6c4 calls copyin with a0=a2 at entry (arg2), a1=sp-80, a2=0x10, a3=?.
  The `jal` at 0x6f8 calls xbow_enable_perf_counter with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x70c calls xbow_enable_llp_monitor with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x738 calls xbow_widget_num_get with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x744 calls xbow_widget_num_get with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x764 calls xbow_prio_bw_alloc with a0=a0 at entry (arg0), a1=?, a2=?, a3=0x0.
  The `jal` at 0x77c calls xbow_prio_bw_alloc with a0=a0 at entry (arg0), a1=?, a2=?, a3=0x0.
  The `jal` at 0x78c calls xbow_widget_num_get with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x798 calls xbow_widget_num_get with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x7b8 calls xbow_prio_bw_alloc with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x7d0 calls xbow_prio_bw_alloc with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x7ec calls assfail with a0=sym(.rodata), a1=sym(.rodata), a2=0x264, a3=?.
  The `jal` at 0x808 calls assfail with a0=sym(.rodata), a1=sym(.rodata), a2=0x28c, a3=?.
  The `bne` branch at 0x4d8 targets 0x52c, is taken when a1 < 0x5 (signed), and falls through when a1 >= 0x5 (signed).
  The `bne` branch at 0x4e4 targets 0x63c, is taken when a1 < 0x6 (signed), and falls through when a1 >= 0x6 (signed).
  The `bne` branch at 0x4ec targets 0x5c4, is taken when v1(?) != 0, and falls through when v1(?) == 0.
  The `bne` branch at 0x4f8 targets 0x670, is taken when a1 < 0x6702 (signed), and falls through when a1 >= 0x6702 (signed).
  The `beq` branch at 0x504 targets 0x6ac, is taken when s0(=a1) == a1(=0x6702), and falls through when s0(=a1) != a1(=0x6702).
  The `bne` branch at 0x530 targets 0x578, is taken when a1 < 0x3 (signed), and falls through when a1 >= 0x3 (signed).
  The `beq` branch at 0x53c targets 0x600, is taken when a1 >= 0x4 (signed), and falls through when a1 < 0x4 (signed).
  The `beq` branch at 0x544 targets 0x69c, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0x554 targets 0x7e0, is taken when v0(=ret(xbow_get_perf_counters)) == 0, and falls through when v0(=ret(xbow_get_perf_counters)) != 0.
  The `beq` branch at 0x570 targets 0x50c and is always taken.
  The `bne` branch at 0x578 targets 0x62c, is taken when a5(?) != 0, and falls through when a5(?) == 0.
  The `beq` branch at 0x580 targets 0x50c, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x598 targets 0x728, is taken when v0(=ret(cap_able_cred)) == 0, and falls through when v0(=ret(cap_able_cred)) != 0.
  The `beq` branch at 0x5a0 targets 0x6a4, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0x5b4 targets 0x6e4, is taken when v0(=ret(copyin)) == 0, and falls through when v0(=ret(copyin)) != 0.
  The `beq` branch at 0x5bc targets 0x50c and is always taken.
  The `bne` branch at 0x5c4 targets 0x508, is taken when a1 != a3(=0x6), and falls through when a1 == a3(=0x6).
  The `beq` branch at 0x5cc targets 0x6dc, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0x5dc targets 0x7fc, is taken when v0(=ret(xbow_get_llp_status)) == 0, and falls through when v0(=ret(xbow_get_llp_status)) != 0.
  The `beq` branch at 0x5f8 targets 0x50c and is always taken.
  The `bne` branch at 0x604 targets 0x50c, is taken when a1 != a5(=0x4), and falls through when a1 == a5(=0x4).
  The `bne` branch at 0x61c targets 0x70c, is taken when v0(=ret(cap_able_cred)) != 0, and falls through when v0(=ret(cap_able_cred)) == 0.
  The `beq` branch at 0x624 targets 0x50c and is always taken.
  The `bne` branch at 0x62c targets 0x50c, is taken when a1 != a2(=0x1), and falls through when a1 == a2(=0x1).
  The `beq` branch at 0x634 targets 0x58c and is always taken.
  The `bne` branch at 0x64c targets 0x65c, is taken when v0(=ret(cap_able_cred)) != 0, and falls through when v0(=ret(cap_able_cred)) == 0.
  The `beq` branch at 0x654 targets 0x50c and is always taken.
  The `beq` branch at 0x668 targets 0x50c and is always taken.
  The `beq` branch at 0x678 targets 0x720, is taken when v0(=ret(cap_able)) == 0, and falls through when v0(=ret(cap_able)) != 0.
  The `beq` branch at 0x68c targets 0x738, is taken when v0(=ret(copyin)) == 0, and falls through when v0(=ret(copyin)) != 0.
  The `beq` branch at 0x694 targets 0x50c and is always taken.
  The `beq` branch at 0x69c targets 0x50c and is always taken.
  The `beq` branch at 0x6a4 targets 0x50c and is always taken.
  The `beq` branch at 0x6b8 targets 0x730, is taken when v0(=ret(cap_able)) == 0, and falls through when v0(=ret(cap_able)) != 0.
  The `beq` branch at 0x6cc targets 0x78c, is taken when v0(=ret(copyin)) == 0, and falls through when v0(=ret(copyin)) != 0.
  The `beq` branch at 0x6d4 targets 0x50c and is always taken.
  The `beq` branch at 0x6dc targets 0x50c and is always taken.
  The `beq` branch at 0x704 targets 0x50c and is always taken.
  The `beq` branch at 0x718 targets 0x50c and is always taken.
  The `beq` branch at 0x720 targets 0x50c and is always taken.
  The `beq` branch at 0x728 targets 0x50c and is always taken.
  The `beq` branch at 0x730 targets 0x50c and is always taken.
  The `beq` branch at 0x784 targets 0x50c and is always taken.
  The `beq` branch at 0x7d8 targets 0x50c and is always taken.
  The `beq` branch at 0x7f4 targets 0x560 and is always taken.
  The `beq` branch at 0x810 targets 0x5e8 and is always taken.
  The return at 0x524 has v0 = one of 0x0, 0xe, 0x1, ?, 0x9.

- `xbow_link_alive` in `IP35/usr/cpu/sysgen/IP35boot/xbow.o` at 0x87c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/xbow.o`.
  Range: 0x87c-0x894 (24 bytes).
  It occupies 24 bytes.
  The `lw` at 0x888 loads 4 bytes from ?.
  The return at 0x88c has v0 = ?.

- `xbow_widget_lookup` in `IP35/usr/cpu/sysgen/IP35boot/xbow.o` at 0x894 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/xbow.o`.
  Range: 0x894-0x8c4 (48 bytes).
  It occupies 48 bytes.
  The `jal` at 0x8a0 calls xswitch_info_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x8ac calls xswitch_info_vhdl_get with a0=ret(xswitch_info_get), a1=?, a2=?, a3=?.
  The return at 0x8bc has v0 = ret(xswitch_info_vhdl_get).

- `xbow_setwidint` in `IP35/usr/cpu/sysgen/IP35boot/xbow.o` at 0x8c4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/xbow.o`.
  Range: 0x8c4-0x930 (108 bytes).
  It occupies 108 bytes.
  The `jal` at 0x8d4 calls xtalk_intr_target_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x8e0 calls xtalk_intr_addr_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x8ec calls xtalk_intr_vector_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x8f8 calls xtalk_intr_sfarg_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x918 calls xbow_intr_preset with a0=ret(xtalk_intr_sfarg_get), a1=0x0, a2=?, a3=ret(xtalk_intr_addr_get).
  The return at 0x928 has v0 = ret(xbow_intr_preset).

- `xbow_intr_preset` in `IP35/usr/cpu/sysgen/IP35boot/xbow.o` at 0x930 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/xbow.o`.
  Range: 0x930-0x964 (52 bytes).
  It occupies 52 bytes.
  The `sw` at 0x958 stores 4 bytes to a0 (arg0 at entry) +0x34.
  The `sw` at 0x960 stores 4 bytes to a0 (arg0 at entry) +0x3c.
  The return at 0x95c has v0 = ?.

- `xem_add_ioe` in `IP35/usr/cpu/sysgen/IP35boot/xbow.o` at 0x964 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/xbow.o`.
  Range: 0x964-0xb98 (564 bytes).
  It occupies 564 bytes.
  14 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x0, including `lw` at 0x964, `lw` at 0xa20, `lw` at 0xa3c.
  The `lh` at 0xa10 loads 2 bytes from a0 (arg0 at entry) +0x4.
  The `lh` at 0xa2c loads 2 bytes from a0 (arg0 at entry) +0x6.
  The `lh` at 0xa48 loads 2 bytes from a0 (arg0 at entry) +0x8.
  The `lh` at 0xa64 loads 2 bytes from a0 (arg0 at entry) +0xa.
  The `lh` at 0xa80 loads 2 bytes from a0 (arg0 at entry) +0xc.
  The `lh` at 0xa9c loads 2 bytes from a0 (arg0 at entry) +0xe.
  The `ld` at 0xab8 loads 8 bytes from a0 (arg0 at entry) +0x10.
  The `ld` at 0xad4 loads 8 bytes from a0 (arg0 at entry) +0x18.
  The `ld` at 0xaf0 loads 8 bytes from a0 (arg0 at entry) +0x20.
  The `ld` at 0xb0c loads 8 bytes from a0 (arg0 at entry) +0x28.
  The `ld` at 0xb28 loads 8 bytes from a0 (arg0 at entry) +0x30.
  The `ld` at 0xb44 loads 8 bytes from a0 (arg0 at entry) +0x38.
  The `ld` at 0xb64 loads 8 bytes from a0 (arg0 at entry) +0x40.
  The `ld` at 0xb84 loads 8 bytes from a0 (arg0 at entry) +0x48.
  The `jal` at 0xa14 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[a0+4]:2.
  The `jal` at 0xa30 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[a0+6]:2.
  The `jal` at 0xa4c calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[a0+8]:2.
  The `jal` at 0xa68 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[a0+10]:2.
  The `jal` at 0xa84 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[a0+12]:2.
  The `jal` at 0xaa0 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[a0+14]:2, a4=([a0] << 0x6).
  The `jal` at 0xabc calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[a0+16]:8, a4=([a0] << 0x6), a5=([a0] << 0x7).
  The `jal` at 0xad8 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[a0+24]:8, a5=([a0] << 0x7), a6=([a0] << 0x8).
  The `jal` at 0xaf4 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[a0+32]:8, a6=([a0] << 0x8), a7=([a0] << 0x9).
  The `jal` at 0xb10 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[a0+40]:8, a7=([a0] << 0x9).
  The `jal` at 0xb2c calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[a0+48]:8.
  The `jal` at 0xb48 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[a0+56]:8.
  The `jal` at 0xb68 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[a0+64]:8.
  The `jal` at 0xb88 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[a0+72]:8.
  The `bne` branch at 0x97c targets 0xa04, is taken when at(?) != 0, and falls through when at(?) == 0.
  The `bltz` branch at 0x988 targets 0xa24, is taken when v0(=([a0] << 0x1)) < 0 (signed), and falls through when v0(=([a0] << 0x1)) >= 0 (signed).
  The `bltz` branch at 0x994 targets 0xa40, is taken when v1(=([a0] << 0x2)) < 0 (signed), and falls through when v1(=([a0] << 0x2)) >= 0 (signed).
  The `bltz` branch at 0x99c targets 0xa5c, is taken when a0(=([a0] << 0x3)) < 0 (signed), and falls through when a0(=([a0] << 0x3)) >= 0 (signed).
  The `bltz` branch at 0x9a4 targets 0xa78, is taken when a1(=([a0] << 0x4)) < 0 (signed), and falls through when a1(=([a0] << 0x4)) >= 0 (signed).
  The `bltz` branch at 0x9ac targets 0xa94, is taken when a3(=([a0] << 0x5)) < 0 (signed), and falls through when a3(=([a0] << 0x5)) >= 0 (signed).
  The `bltz` branch at 0x9b4 targets 0xab0, is taken when a4(=([a0] << 0x6)) < 0 (signed), and falls through when a4(=([a0] << 0x6)) >= 0 (signed).
  The `bltz` branch at 0x9bc targets 0xacc, is taken when a5(=([a0] << 0x7)) < 0 (signed), and falls through when a5(=([a0] << 0x7)) >= 0 (signed).
  The `bltz` branch at 0x9c4 targets 0xae8, is taken when a6(=([a0] << 0x8)) < 0 (signed), and falls through when a6(=([a0] << 0x8)) >= 0 (signed).
  The `bltz` branch at 0x9cc targets 0xb04, is taken when a7(=([a0] << 0x9)) < 0 (signed), and falls through when a7(=([a0] << 0x9)) >= 0 (signed).
  The `bltz` branch at 0x9d4 targets 0xb20, is taken when t0(=([a0] << 0xa)) < 0 (signed), and falls through when t0(=([a0] << 0xa)) >= 0 (signed).
  The `bltz` branch at 0x9dc targets 0xb3c, is taken when t1(=([a0] << 0xb)) < 0 (signed), and falls through when t1(=([a0] << 0xb)) >= 0 (signed).
  The `bltz` branch at 0x9e4 targets 0xb58, is taken when t2(=([a0] << 0xc)) < 0 (signed), and falls through when t2(=([a0] << 0xc)) >= 0 (signed).
  The `bltz` branch at 0x9ec targets 0xb78, is taken when t3(=([a0] << 0xd)) < 0 (signed), and falls through when t3(=([a0] << 0xd)) >= 0 (signed).
  The `beq` branch at 0xa1c targets 0x984 and is always taken.
  The `beq` branch at 0xa38 targets 0x990 and is always taken.
  The `beq` branch at 0xa54 targets 0x998 and is always taken.
  The `beq` branch at 0xa70 targets 0x9a0 and is always taken.
  The `beq` branch at 0xa8c targets 0x9a8 and is always taken.
  The `beq` branch at 0xaa8 targets 0x9b0 and is always taken.
  The `beq` branch at 0xac4 targets 0x9b8 and is always taken.
  The `beq` branch at 0xae0 targets 0x9c0 and is always taken.
  The `beq` branch at 0xafc targets 0x9c8 and is always taken.
  The `beq` branch at 0xb18 targets 0x9d0 and is always taken.
  The `beq` branch at 0xb34 targets 0x9d8 and is always taken.
  The `beq` branch at 0xb50 targets 0x9e0 and is always taken.
  The `beq` branch at 0xb70 targets 0x9e8 and is always taken.
  The `beq` branch at 0xb90 targets 0x9f4 and is always taken.
  The return at 0x9fc has v0 = one of ?, ret(cmn_err).

- `xbow_xmit_retry_error` in `IP35/usr/cpu/sysgen/IP35boot/xbow.o` at 0xb98 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/xbow.o`.
  Range: 0xb98-0xc9c (260 bytes).
  It occupies 260 bytes.
  The `ld` at 0xba8 loads 8 bytes from (a0 + (a1 << 0x3)) +0x188.
  3 such `lw` accesses load 4 bytes from ?, including `lw` at 0xbbc, `lw` at 0xc1c, `lw` at 0xc2c.
  The `sw` at 0xc20 stores 4 bytes to ?.
  The `lw` at 0xc34 loads 4 bytes from a0 (arg0 at entry) +0x8.
  The `sd` at 0xc88 stores 8 bytes to (a0 + (a1 << 0x3)) +0x188.
  The `jal` at 0xc30 calls xswitch_info_get with a0=[a0+8], a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a5=[(a0 + (a1 << 0x3))+392]:8.
  The `jal` at 0xc50 calls xswitch_info_vhdl_get with a0=ret(xswitch_info_get), a1=?, a2=?, a3=?, a4=0x1.
  The `jal` at 0xc70 calls xtalk_piotrans_addr with a0=ret(xswitch_info_vhdl_get), a1=0x0, a2=0x0, a3=0x58, a4=0x0.
  The `beq` branch at 0xbb4 targets 0xc30, is taken when a5(=[(a0 + (a1 << 0x3))+392]:8) == 0, and falls through when a5(=[(a0 + (a1 << 0x3))+392]:8) != 0.
  The `beq` branch at 0xbd0 targets 0xc00, is taken when a0(?) == a7(=0xc002), and falls through when a0(?) != a7(=0xc002).
  The `bne` branch at 0xbd8 targets 0xbf0, is taken when a0(?) != a1(=0xd002), and falls through when a0(?) == a1(=0xd002).
  The `beq` branch at 0xbe8 targets 0xc14, is taken when a1(?) == a2(=0x24), and falls through when a1(?) != a2(=0x24).
  The `bne` branch at 0xc0c targets 0xbd8, is taken when a2(?) != a3(=0x36), and falls through when a2(?) == a3(=0x36).
  The `beq` branch at 0xc28 targets 0xbf0 and is always taken.
  The `bne` branch at 0xc38 targets 0xc48, is taken when v0(=ret(xswitch_info_get)) != 0, and falls through when v0(=ret(xswitch_info_get)) == 0.
  The `beq` branch at 0xc40 targets 0xbf4 and is always taken.
  The `beq` branch at 0xc5c targets 0xc8c, is taken when v0(=ret(xswitch_info_vhdl_get)) == a2(=-0x1), and falls through when v0(=ret(xswitch_info_vhdl_get)) != a2(=-0x1).
  The `beq` branch at 0xc7c targets 0xc94, is taken when v0(=ret(xtalk_piotrans_addr)) == 0, and falls through when v0(=ret(xtalk_piotrans_addr)) != 0.
  The `beq` branch at 0xc84 targets 0xbbc and is always taken.
  The `beq` branch at 0xc8c targets 0xbf0 and is always taken.
  The `beq` branch at 0xc94 targets 0xbf0 and is always taken.
  The return at 0xbf8 has v0 = one of 0x0, 0x1.

- `xbow_errintr_handler` in `IP35/usr/cpu/sysgen/IP35boot/xbow.o` at 0xc9c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/xbow.o`.
  Range: 0xc9c-0x1290 (1524 bytes).
  It occupies 1524 bytes.
  The `ld` at 0xcc8 loads 8 bytes from a0 (arg0 at entry) +0x10.
  The `lw` at 0xcd0 loads 4 bytes from [a0+16]:8 +0x24.
  The `lw` at 0xcd4 loads 4 bytes from [a0+16]:8 +0x54.
  The `lw` at 0xcd8 loads 4 bytes from [a0+16]:8 +0x44.
  The `lw` at 0xcdc loads 4 bytes from [a0+16]:8 +0x14.
  The `lw` at 0xce0 loads 4 bytes from [a0+16]:8 +0x1c.
  The `sw` at 0xcec stores 4 bytes to [a0+16]:8 +0x44.
  4 such `lw` accesses load 4 bytes from ?, including `lw` at 0xdb0, `lw` at 0xdb4, `lw` at 0xdc4.
  The `sw` at 0xe08 stores 4 bytes to ?.
  The `lw` at 0xed4 loads 4 bytes from a0 (arg0 at entry) +0x8.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x18, including `ld` at 0xef8, `ld` at 0x1070.
  The `jal` at 0xde8 calls xbow_xmit_retry_error with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xe34 calls xbow_error_handler with a0=a0 at entry (arg0), a1=0x8, a2=0x1, a3=sp-272.
  The `jal` at 0xed0 calls xbow_widget_lookup with a0=[a0+8], a1=?, a2=?, a3=?.
  The `jal` at 0xed8 calls xwidget_name_get with a0=ret(xbow_widget_lookup), a1=?, a2=?, a3=?.
  The `jal` at 0xef4 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=[a0+24]:8, a3=?, a4=ret(xwidget_name_get).
  The `jal` at 0xfc0 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[[a0+16]:8+84].
  The `jal` at 0xfd4 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0xfe8 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0xffc calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x1010 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x103c calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x104c calls cmn_err_tag with a0=0x8, a1=0x0, a2=sym(.rodata), a3=?.
  The `jal` at 0x106c calls cmn_err with a0=0x6, a1=sym(.rodata), a2=[a0+24]:8, a3=?.
  The `jal` at 0x10a8 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x10d0 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x10e4 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x10f8 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x110c calls xem_add_ioe with a0=sp-272, a1=?, a2=?, a3=?.
  The `jal` at 0x1124 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x113c calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x1158 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x1174 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x1190 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x11a8 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x11c4 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x11e0 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x11f8 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x1210 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x122c calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x1244 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x1260 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `beq` branch at 0xd24 targets 0xeb4, is taken when (s3(=[[a0+16]:8+84]) & at(=0xffffffffff000000)) == 0, and falls through when (s3(=[[a0+16]:8+84]) & at(=0xffffffffff000000)) != 0.
  The `beq` branch at 0xd6c targets 0x1270 and is always taken.
  The `bne` branch at 0xd7c targets 0xecc, is taken when s1(?) != 0, and falls through when s1(?) == 0.
  The `beq` branch at 0xda0 targets 0xe54, is taken when s0(?) >= 0x10 (signed), and falls through when s0(?) < 0x10 (signed).
  The `beq` branch at 0xda8 targets 0xd84, is taken when t8(?) == 0, and falls through when t8(?) != 0.
  The `beq` branch at 0xdcc targets 0xddc, is taken when (s5(=0x20000) & s1(?)) == 0, and falls through when (s5(=0x20000) & s1(?)) != 0.
  The `beq` branch at 0xdd8 targets 0xe14, is taken when s0(?) == t8(?), and falls through when s0(?) != t8(?).
  The `beq` branch at 0xde0 targets 0xd7c, is taken when t9(?) == 0, and falls through when t9(?) != 0.
  The `bne` branch at 0xdf0 targets 0xd74, is taken when v0(=ret(xbow_xmit_retry_error)) != 0, and falls through when v0(=ret(xbow_xmit_retry_error)) == 0.
  The `beq` branch at 0xe0c targets 0xd74 and is always taken.
  The `beq` branch at 0xe40 targets 0xea4, is taken when v0(=ret(xbow_error_handler)) == 0, and falls through when v0(=ret(xbow_error_handler)) != 0.
  The `beq` branch at 0xe4c targets 0xddc and is always taken.
  The `beq` branch at 0xe58 targets 0xe70, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `bne` branch at 0xe64 targets 0x1064, is taken when (s3(=[[a0+16]:8+84]) & 0x25) != 0, and falls through when (s3(=[[a0+16]:8+84]) & 0x25) == 0.
  The `bne` branch at 0xe70 targets 0xfb4, is taken when a5(?) != 0, and falls through when a5(?) == 0.
  The `beq` branch at 0xeac targets 0xddc and is always taken.
  The `bgez` branch at 0xeb4 targets 0xe78, is taken when t0(?) >= 0 (signed), and falls through when t0(?) < 0 (signed).
  The `beq` branch at 0xebc targets 0xe78, is taken when t1(?) == 0, and falls through when t1(?) != 0.
  The `beq` branch at 0xec4 targets 0x105c and is always taken.
  The `bne` branch at 0xf04 targets 0x111c, is taken when (a3(=0x40000) & s4(?)) != 0, and falls through when (a3(=0x40000) & s4(?)) == 0.
  The `bne` branch at 0xf10 targets 0x1134, is taken when a4(?) != 0, and falls through when a4(?) == 0.
  The `bne` branch at 0xf20 targets 0x114c, is taken when (a5(=0x10000) & s4(?)) != 0, and falls through when (a5(=0x10000) & s4(?)) == 0.
  The `bne` branch at 0xf28 targets 0x1168, is taken when a6(?) != 0, and falls through when a6(?) == 0.
  The `bne` branch at 0xf30 targets 0x1184, is taken when a7(?) != 0, and falls through when a7(?) == 0.
  The `bne` branch at 0xf38 targets 0x11a0, is taken when t0(?) != 0, and falls through when t0(?) == 0.
  The `bne` branch at 0xf44 targets 0x11b8, is taken when t1(?) != 0, and falls through when t1(?) == 0.
  The `bne` branch at 0xf4c targets 0x11d4, is taken when t2(?) != 0, and falls through when t2(?) == 0.
  The `bne` branch at 0xf54 targets 0x11f0, is taken when t3(?) != 0, and falls through when t3(?) == 0.
  The `bne` branch at 0xf60 targets 0x1208, is taken when t8(?) != 0, and falls through when t8(?) == 0.
  The `bne` branch at 0xf7c targets 0x10a0, is taken when (t9(?) & ra(?)) != 0, and falls through when (t9(?) & ra(?)) == 0.
  The `bne` branch at 0xf8c targets 0xf70, is taken when s1(?) < 0x10 (signed), and falls through when s1(?) >= 0x10 (signed).
  The `bne` branch at 0xf98 targets 0x10c8, is taken when v0(=[sym(kdebug)]:2) != 0, and falls through when v0(=[sym(kdebug)]:2) == 0.
  The `beq` branch at 0xfac targets 0xd84 and is always taken.
  The `beq` branch at 0x1054 targets 0xe78 and is always taken.
  The `bne` branch at 0x1078 targets 0x1220, is taken when (s3(=[[a0+16]:8+84]) & 0x1) != 0, and falls through when (s3(=[[a0+16]:8+84]) & 0x1) == 0.
  The `bne` branch at 0x1080 targets 0x123c, is taken when a4(?) != 0, and falls through when a4(?) == 0.
  The `bne` branch at 0x108c targets 0x1254, is taken when a5(?) != 0, and falls through when a5(?) == 0.
  The `beq` branch at 0x1098 targets 0xe6c and is always taken.
  The `bne` branch at 0x10b8 targets 0xf70, is taken when s1(?) < 0x10 (signed), and falls through when s1(?) >= 0x10 (signed).
  The `beq` branch at 0x10c0 targets 0xf98 and is always taken.
  The `beq` branch at 0x1104 targets 0xfa4, is taken when t0(?) == 0, and falls through when t0(?) != 0.
  The `beq` branch at 0x1114 targets 0xfa0 and is always taken.
  The `beq` branch at 0x112c targets 0xf10 and is always taken.
  The `beq` branch at 0x1144 targets 0xf1c and is always taken.
  The `beq` branch at 0x1160 targets 0xf28 and is always taken.
  The `beq` branch at 0x117c targets 0xf30 and is always taken.
  The `beq` branch at 0x1198 targets 0xf38 and is always taken.
  The `beq` branch at 0x11b0 targets 0xf44 and is always taken.
  The `beq` branch at 0x11cc targets 0xf4c and is always taken.
  The `beq` branch at 0x11e8 targets 0xf54 and is always taken.
  The `beq` branch at 0x1200 targets 0xf60 and is always taken.
  The `beq` branch at 0x1218 targets 0xf6c and is always taken.
  The `beq` branch at 0x1234 targets 0x1080 and is always taken.
  The `beq` branch at 0x124c targets 0x108c and is always taken.
  The `beq` branch at 0x1268 targets 0x1094 and is always taken.
  The `beq` branch at 0x1288 targets 0xda8 and is always taken.
  The return at 0xe9c has v0 = one of ?, ret(cmn_err_tag).

- `xbow_error_handler` in `IP35/usr/cpu/sysgen/IP35boot/xbow.o` at 0x1290 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/xbow.o`.
  Range: 0x1290-0x1940 (1712 bytes).
  It occupies 1712 bytes.
  The `lw` at 0x1290 loads 4 bytes from a0 (arg0 at entry) +0x8.
  The `ld` at 0x1294 loads 8 bytes from a0 (arg0 at entry) +0x10.
  The `lh` at 0x12b4 loads 2 bytes from a3 (arg3 at entry) +0x6.
  The `lw` at 0x12d8 loads 4 bytes from [a0+16]:8 +0xc.
  The `lw` at 0x12dc loads 4 bytes from [a0+16]:8 +0x44.
  The `lw` at 0x12e0 loads 4 bytes from [a0+16]:8 +0x14.
  The `lw` at 0x12e4 loads 4 bytes from [a0+16]:8 +0x1c.
  3 such `lw` accesses load 4 bytes from ?, including `lw` at 0x135c, `lw` at 0x1360, `lw` at 0x1364.
  3 such `lw` accesses load 4 bytes from [a0+16]:8 +0x4, including `lw` at 0x1368, `lw` at 0x138c, `lw` at 0x1468.
  The `lw` at 0x140c loads 4 bytes from a0 (arg0 at entry) +0x0.
  8 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x18, including `ld` at 0x14f8, `ld` at 0x1518, `ld` at 0x15c4.
  5 such `ld` accesses load 8 bytes from a3 (arg3 at entry) +0x18, including `ld` at 0x150c, `ld` at 0x15d8, `ld` at 0x178c.
  2 such `lw` accesses load 4 bytes from a3 (arg3 at entry) +0x0, including `lw` at 0x171c, `lw` at 0x18d0.
  The `jal` at 0x13f8 calls xbow_widget_lookup with a0=[a0+8], a1=[a3+6]:2, a2=?, a3=?.
  The `jal` at 0x1494 calls xtalk_error_handler with a0=ret(xbow_widget_lookup), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x14fc calls cmn_err with a0=0x1, a1=sym(.rodata), a2=[a0+24]:8, a3=[a3+6]:2, a5=[a0+8].
  The `jal` at 0x151c calls cmn_err with a0=0x1, a1=sym(.rodata), a2=[a0+24]:8, a3=[a3+6]:2, a4=[a3+24]:8.
  The `jal` at 0x1538 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?, a4=[sym(kdebug)]:2.
  The `jal` at 0x154c calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[[a0+16]:8+12].
  The `jal` at 0x1560 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[[a0+16]:8+68].
  The `jal` at 0x1574 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[[a0+16]:8+20].
  The `jal` at 0x1588 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[[a0+16]:8+28].
  The `jal` at 0x15ac calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x15c8 calls cmn_err with a0=0x1, a1=sym(.rodata), a2=[a0+24]:8, a3=a3 at entry (arg3), a5=[a0+8].
  The `jal` at 0x15e4 calls cmn_err with a0=0x1, a1=sym(.rodata), a2=[a0+24]:8, a3=[a3+24]:8.
  The `jal` at 0x1600 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x1614 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[[a0+16]:8+12].
  The `jal` at 0x1628 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[[a0+16]:8+68].
  The `jal` at 0x163c calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[[a0+16]:8+20].
  The `jal` at 0x1650 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[[a0+16]:8+28].
  The `jal` at 0x1674 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x168c calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[a3+6]:2.
  The `jal` at 0x16a0 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x16b4 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x16c8 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x1708 calls cmn_err with a0=0x1, a1=sym(.rodata), a2=sym(.rodata), a3=sym(.rodata), a4=[a0+24]:8, a5=[a3+6]:2.
  The `jal` at 0x1744 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x175c calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x177c calls cmn_err with a0=0x1, a1=sym(.rodata), a2=[a0+24]:8, a3=[a3+6]:2.
  The `jal` at 0x179c calls cmn_err with a0=0x1, a1=sym(.rodata), a2=[a0+24]:8, a3=[a3+6]:2, a4=[a3+24]:8.
  The `jal` at 0x17b4 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?, a4=[sym(kdebug)]:2.
  The `jal` at 0x17c8 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[[a0+16]:8+12].
  The `jal` at 0x17dc calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[[a0+16]:8+68].
  The `jal` at 0x17f0 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[[a0+16]:8+20].
  The `jal` at 0x1804 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[[a0+16]:8+28].
  The `jal` at 0x1828 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x1840 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[a3+6]:2.
  The `jal` at 0x1854 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x1868 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x187c calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x18bc calls cmn_err with a0=0x1, a1=sym(.rodata), a2=sym(.rodata), a3=sym(.rodata), a4=[a0+24]:8, a5=[a3+6]:2, a7=0x9.
  The `jal` at 0x191c calls cmn_err with a0=0x6, a1=sym(.rodata), a2=[a3+24]:8, a3=?, a5=([a3] << 0x7).
  The `jal` at 0x1930 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=[a3+24]:8, a3=?, a5=([a3] << 0x7).
  The `beq` branch at 0x12d0 targets 0x13d0, is taken when s1(=[a3+6]:2) == 0, and falls through when s1(=[a3+6]:2) != 0.
  The `bne` branch at 0x12f0 targets 0x1304, is taken when s1(=[a3+6]:2) < 0x8 (signed), and falls through when s1(=[a3+6]:2) >= 0x8 (signed).
  The `bne` branch at 0x12fc targets 0x1354, is taken when s1(=[a3+6]:2) < 0x10 (signed), and falls through when s1(=[a3+6]:2) >= 0x10 (signed).
  The `beq` branch at 0x1304 targets 0x1434, is taken when s3(=a2) == 0, and falls through when s3(=a2) != 0.
  The `bne` branch at 0x130c targets 0x14ec, is taken when a2(?) != 0, and falls through when a2(?) == 0.
  The `bne` branch at 0x1314 targets 0x150c, is taken when a3(?) != 0, and falls through when a3(?) == 0.
  The `bne` branch at 0x1320 targets 0x152c, is taken when a4(=[sym(kdebug)]:2) != 0, and falls through when a4(=[sym(kdebug)]:2) == 0.
  The `beq` branch at 0x1384 targets 0x13a0, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `beq` branch at 0x139c targets 0x1468, is taken when t1(?) == t2(=0xd100), and falls through when t1(?) != t2(=0xd100).
  The `beq` branch at 0x13a8 targets 0x143c, is taken when (t2(?) & 0x20) == 0, and falls through when (t2(?) & 0x20) != 0.
  The `bne` branch at 0x13b8 targets 0x13f4, is taken when (t3(?) & t8(=0xffffffff80000000)) != 0, and falls through when (t3(?) & t8(=0xffffffff80000000)) == 0.
  The `bne` branch at 0x13c0 targets 0x16d8, is taken when s3(=a2) != 0, and falls through when s3(=a2) == 0.
  The `beq` branch at 0x13c8 targets 0x1328 and is always taken.
  The `beq` branch at 0x13d0 targets 0x14cc, is taken when a2 == 0, and falls through when a2 != 0.
  The `bne` branch at 0x13d8 targets 0x15bc, is taken when t9(?) != 0, and falls through when t9(?) == 0.
  The `bne` branch at 0x13e0 targets 0x15d8, is taken when ra(?) != 0, and falls through when ra(?) == 0.
  The `beq` branch at 0x13e8 targets 0x1328 and is always taken.
  The `beq` branch at 0x1404 targets 0x14bc, is taken when v0(=ret(xbow_widget_lookup)) == at(=-0x1), and falls through when v0(=ret(xbow_widget_lookup)) != at(=-0x1).
  The `bne` branch at 0x1410 targets 0x148c, is taken when v1(=[a0]) != v0(=ret(xbow_widget_lookup)), and falls through when v1(=[a0]) == v0(=ret(xbow_widget_lookup)).
  The `beq` branch at 0x1418 targets 0x14d4, is taken when s3(=a2) == 0, and falls through when s3(=a2) != 0.
  The `bne` branch at 0x1424 targets 0x15f4, is taken when a1(=[sym(kdebug)]:2) != 0, and falls through when a1(=[sym(kdebug)]:2) == 0.
  The `beq` branch at 0x142c targets 0x1328 and is always taken.
  The `beq` branch at 0x1434 targets 0x1328 and is always taken.
  The `beq` branch at 0x143c targets 0x14dc, is taken when s3(=a2) == 0, and falls through when s3(=a2) != 0.
  The `bne` branch at 0x1444 targets 0x176c, is taken when a2(?) != 0, and falls through when a2(?) == 0.
  The `bne` branch at 0x144c targets 0x178c, is taken when a3(?) != 0, and falls through when a3(?) == 0.
  The `bne` branch at 0x1458 targets 0x17ac, is taken when a4(=[sym(kdebug)]:2) != 0, and falls through when a4(=[sym(kdebug)]:2) == 0.
  The `beq` branch at 0x1460 targets 0x1328 and is always taken.
  The `bne` branch at 0x1474 targets 0x13a0, is taken when (a5(?) & 0x7ff) != 0, and falls through when (a5(?) & 0x7ff) == 0.
  The `bne` branch at 0x147c targets 0x13a4, is taken when s1(=[a3+6]:2) != a6(=0xf), and falls through when s1(=[a3+6]:2) == a6(=0xf).
  The `beq` branch at 0x1484 targets 0x13b0 and is always taken.
  The `beq` branch at 0x149c targets 0x14e4, is taken when v0(=ret(xtalk_error_handler)) == 0, and falls through when v0(=ret(xtalk_error_handler)) != 0.
  The `beq` branch at 0x14a4 targets 0x14d4, is taken when s3(=a2) == 0, and falls through when s3(=a2) != 0.
  The `bne` branch at 0x14ac targets 0x1424, is taken when v0(=ret(xtalk_error_handler)) != a7(=0x9), and falls through when v0(=ret(xtalk_error_handler)) == a7(=0x9).
  The `beq` branch at 0x14b4 targets 0x188c and is always taken.
  The `beq` branch at 0x14bc targets 0x14d4, is taken when s3(=a2) == 0, and falls through when s3(=a2) != 0.
  The `beq` branch at 0x14c4 targets 0x1420 and is always taken.
  The `beq` branch at 0x14cc targets 0x1328 and is always taken.
  The `beq` branch at 0x14d4 targets 0x1328 and is always taken.
  The `beq` branch at 0x14dc targets 0x1328 and is always taken.
  The `beq` branch at 0x14e4 targets 0x1328 and is always taken.
  The `beq` branch at 0x1504 targets 0x1314 and is always taken.
  The `beq` branch at 0x1524 targets 0x1320 and is always taken.
  The `beq` branch at 0x15b4 targets 0x1328 and is always taken.
  The `beq` branch at 0x15d0 targets 0x13e0 and is always taken.
  The `beq` branch at 0x15ec targets 0x13e8 and is always taken.
  The `beq` branch at 0x16d0 targets 0x142c and is always taken.
  The `beq` branch at 0x16d8 targets 0x18e8, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0x16e8 targets 0x18f4, is taken when (s2(=a1) & 0x4) == 0, and falls through when (s2(=a1) & 0x4) != 0.
  The `beq` branch at 0x1714 targets 0x172c, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `bltz` branch at 0x1724 targets 0x1914, is taken when a5(=([a3] << 0x7)) < 0 (signed), and falls through when a5(=([a3] << 0x7)) >= 0 (signed).
  The `beq` branch at 0x1730 targets 0x1754, is taken when (a6(?) & 0x40) == 0, and falls through when (a6(?) & 0x40) != 0.
  The `beq` branch at 0x174c targets 0x13f4 and is always taken.
  The `beq` branch at 0x1764 targets 0x13f4 and is always taken.
  The `beq` branch at 0x1784 targets 0x144c and is always taken.
  The `beq` branch at 0x17a4 targets 0x1458 and is always taken.
  The `beq` branch at 0x1884 targets 0x1460 and is always taken.
  The `beq` branch at 0x188c targets 0x1900, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0x18a0 targets 0x1908, is taken when (s2(=a1) & 0x4) == 0, and falls through when (s2(=a1) & 0x4) != 0.
  The `beq` branch at 0x18c8 targets 0x18e0, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `bltz` branch at 0x18d8 targets 0x192c, is taken when a5(=([a3] << 0x7)) < 0 (signed), and falls through when a5(=([a3] << 0x7)) >= 0 (signed).
  The `beq` branch at 0x18e0 targets 0x1420 and is always taken.
  The `beq` branch at 0x18ec targets 0x16e4 and is always taken.
  The `beq` branch at 0x18f8 targets 0x16f8 and is always taken.
  The `beq` branch at 0x1900 targets 0x189c and is always taken.
  The `beq` branch at 0x190c targets 0x18b0 and is always taken.
  The `beq` branch at 0x1924 targets 0x172c and is always taken.
  The `beq` branch at 0x1938 targets 0x18e0 and is always taken.
  The return at 0x134c has v0 = one of 0x6, 0x0, ?.
  The instructions from 0x13f0 to 0x13f0 are not reached by any path from the entry, and their branches are not listed.

- `xbow_update_perf_counters` in `IP35/usr/cpu/sysgen/IP35boot/xbow.o` at 0x1940 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/xbow.o`.
  Range: 0x1940-0x1a48 (264 bytes).
  It occupies 264 bytes.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0x198c, `ld` at 0x19c4.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0x1990, `lw` at 0x199c.
  2 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x1994, `lbu` at 0x19f4.
  The `sd` at 0x19d4 stores 8 bytes to ?.
  The `sw` at 0x19e0 stores 4 bytes to ?.
  The `jal` at 0x1960 calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1984 calls mutex_spinlock with a0=ret(hwgraph_fastinfo_get)+448, a1=?, a2=?, a3=?.
  The `jal` at 0x19dc calls mutex_spinunlock with a0=ret(hwgraph_fastinfo_get)+448, a1=ret(mutex_spinlock), a2=?, a3=?.
  The `jal` at 0x1a1c calls timeout with a0=sym(xbow_update_perf_counters), a1=?, a2=0x4, a3=?.
  The `beq` branch at 0x197c targets 0x19f4 and is always taken.
  The `beq` branch at 0x19ec targets 0x1a10, is taken when s1(?) >= 0x2 (signed), and falls through when s1(?) < 0x2 (signed).
  The `bne` branch at 0x19f8 targets 0x1984, is taken when ra(?) != 0, and falls through when ra(?) == 0.
  The `bne` branch at 0x1a08 targets 0x19f4, is taken when s1(?) < 0x2 (signed), and falls through when s1(?) >= 0x2 (signed).
  The return at 0x1a40 has v0 = ret(timeout).

- `xbow_enable_perf_counter` in `IP35/usr/cpu/sysgen/IP35boot/xbow.o` at 0x1a68 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/xbow.o`.
  Range: 0x1a68-0x1c34 (460 bytes).
  It occupies 460 bytes.
  The `ld` at 0x1aa8 loads 8 bytes from ret(hwgraph_fastinfo_get) +0x10.
  The `lbu` at 0x1b20 loads 1 byte from (ret(hwgraph_fastinfo_get) + (a3 << 0x4)) +0x25.
  2 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x1b5c, `lbu` at 0x1b68.
  The `sb` at 0x1b88 stores 1 byte to (ret(hwgraph_fastinfo_get) + (a3 << 0x4)) +0x27.
  The `sb` at 0x1b8c stores 1 byte to (ret(hwgraph_fastinfo_get) + (a3 << 0x4)) +0x25.
  The `sb` at 0x1b94 stores 1 byte to (ret(hwgraph_fastinfo_get) + (a3 << 0x4)) +0x26.
  The `sb` at 0x1b9c stores 1 byte to (ret(hwgraph_fastinfo_get) + (a3 << 0x4)) +0x24.
  The `lw` at 0x1ba8 loads 4 bytes from ([ret(hwgraph_fastinfo_get)+16]:8 + (a1 << 0x6)) -0xf4.
  The `sw` at 0x1bc0 stores 4 bytes to ([ret(hwgraph_fastinfo_get)+16]:8 + (a1 << 0x6)) -0xf4.
  The `ld` at 0x1bc8 loads 8 bytes from (ret(hwgraph_fastinfo_get) + (a3 << 0x4)) +0x28.
  The `lw` at 0x1be0 loads 4 bytes from [(ret(hwgraph_fastinfo_get) + (a3 << 0x4))+40]:8 +0x0.
  The `sw` at 0x1c00 stores 4 bytes to [(ret(hwgraph_fastinfo_get) + (a3 << 0x4))+40]:8 +0x0.
  The `sw` at 0x1c0c stores 4 bytes to (ret(hwgraph_fastinfo_get) + (a3 << 0x4)) +0x20.
  The `jal` at 0x1a8c calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1b0c calls mutex_spinlock with a0=ret(hwgraph_fastinfo_get)+448, a1=?, a2=?, a3=?, a6=[ret(hwgraph_fastinfo_get)+16]:8.
  The `jal` at 0x1b78 calls mutex_spinunlock with a0=ret(hwgraph_fastinfo_get)+448, a1=ret(mutex_spinlock), a2=?, a3=?, a7=a1-8.
  The `jal` at 0x1c08 calls timeout with a0=sym(xbow_update_perf_counters), a1=?, a2=0x4, a3=([ret(hwgraph_fastinfo_get)+16]:8 + (a1 << 0x6)), a6=0xfffff.
  The `jal` at 0x1c14 calls mutex_spinunlock with a0=ret(hwgraph_fastinfo_get)+448, a1=ret(mutex_spinlock), a2=?, a3=?.
  The `jal` at 0x1c24 calls mutex_spinunlock with a0=ret(hwgraph_fastinfo_get)+448, a1=ret(mutex_spinlock), a2=?, a3=?, a6=0x0, a7=a1-8.
  The `bne` branch at 0x1aac targets 0x1ae0, is taken when s3(=a1) < 0x8 (signed), and falls through when s3(=a1) >= 0x8 (signed).
  The `beq` branch at 0x1ab4 targets 0x1ae0, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `bltz` branch at 0x1abc targets 0x1b00, is taken when s2(=a2) < 0 (signed), and falls through when s2(=a2) >= 0 (signed).
  The `beq` branch at 0x1ac4 targets 0x1b00, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `bltz` branch at 0x1acc targets 0x1adc, is taken when s0(=a3) < 0 (signed), and falls through when s0(=a3) >= 0 (signed).
  The `bne` branch at 0x1ad4 targets 0x1b08, is taken when a3(?) != 0, and falls through when a3(?) == 0.
  The `beq` branch at 0x1b00 targets 0x1ae0 and is always taken.
  The `beq` branch at 0x1b28 targets 0x1b50, is taken when v0(=[(ret(hwgraph_fastinfo_get) + (a3 << 0x4))+37]:1) == 0, and falls through when v0(=[(ret(hwgraph_fastinfo_get) + (a3 << 0x4))+37]:1) != 0.
  The `beq` branch at 0x1b30 targets 0x1b50, is taken when s2(=a2) == 0, and falls through when s2(=a2) != 0.
  The `beq` branch at 0x1b38 targets 0x1c24 and is always taken.
  The `beq` branch at 0x1b48 targets 0x1b88, is taken when a6(?) >= 0x2 (signed), and falls through when a6(?) < 0x2 (signed).
  The `beq` branch at 0x1b50 targets 0x1b40, is taken when s0(=a3) == a6(?), and falls through when s0(=a3) != a6(?).
  The `bne` branch at 0x1b60 targets 0x1b40, is taken when a7(=a1-8) != t2(?), and falls through when a7(=a1-8) == t2(?).
  The `beq` branch at 0x1b6c targets 0x1b44, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0x1b80 targets 0x1ae0 and is always taken.
  The `beq` branch at 0x1c1c targets 0x1ae0 and is always taken.
  The `beq` branch at 0x1c2c targets 0x1ae0 and is always taken.
  The return at 0x1af8 has v0 = one of -0x1, 0x0.

- `xbow_update_llp_status` in `IP35/usr/cpu/sysgen/IP35boot/xbow.o` at 0x1c54 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/xbow.o`.
  Range: 0x1c54-0x1d68 (276 bytes).
  It occupies 276 bytes.
  The `ld` at 0x1c8c loads 8 bytes from ret(hwgraph_fastinfo_get) +0x10.
  The `lw` at 0x1c98 loads 4 bytes from ret(hwgraph_fastinfo_get) +0x8.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0x1cb4, `lw` at 0x1cb8.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0x1cd0, `ld` at 0x1cd8.
  2 such `sd` accesses store 8 bytes to ?, including `sd` at 0x1ce0, `sd` at 0x1cec.
  The `lw` at 0x1d04 loads 4 bytes from ret(hwgraph_fastinfo_get) +0x1c4.
  The `jal` at 0x1c74 calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1c9c calls xbow_widget_lookup with a0=[ret(hwgraph_fastinfo_get)+8], a1=?, a2=?, a3=?.
  The `jal` at 0x1ca4 calls xwidget_name_get with a0=ret(xbow_widget_lookup), a1=?, a2=?, a3=?.
  The `jal` at 0x1d1c calls timeout with a0=sym(xbow_update_llp_status), a1=?, a2=0x64, a3=?.
  The `jal` at 0x1d58 calls cmn_err with a0=0x4, a1=sym(.rodata), a2=?, a3=ret(xwidget_name_get).
  The `beq` branch at 0x1cc8 targets 0x1cf0, is taken when t8(?) == 0, and falls through when t8(?) != 0.
  The `bne` branch at 0x1ce8 targets 0x1d48, is taken when a6(?) != 0, and falls through when a6(?) == 0.
  The `bne` branch at 0x1cfc targets 0x1c98, is taken when s0(?) < 0x8 (signed), and falls through when s0(?) >= 0x8 (signed).
  The `beq` branch at 0x1d08 targets 0x1d24, is taken when t3(=[ret(hwgraph_fastinfo_get)+452]) == 0, and falls through when t3(=[ret(hwgraph_fastinfo_get)+452]) != 0.
  The `beq` branch at 0x1d60 targets 0x1cf4 and is always taken.
  The return at 0x1d40 has v0 = one of ?, ret(timeout).

- `xbow_disable_llp_monitor` in `IP35/usr/cpu/sysgen/IP35boot/xbow.o` at 0x1d68 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/xbow.o`.
  Range: 0x1d68-0x1db0 (72 bytes).
  It occupies 72 bytes.
  2 such `sd` accesses store 8 bytes to ?, including `sd` at 0x1d94, `sd` at 0x1d9c.
  The `sw` at 0x1da4 stores 4 bytes to ret(hwgraph_fastinfo_get) +0x1c4.
  The `jal` at 0x1d70 calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `bne` branch at 0x1d98 targets 0x1d84, is taken when a2(?) < 0x8 (signed), and falls through when a2(?) >= 0x8 (signed).
  The return at 0x1da8 has v0 = 0x0.

- `xbow_enable_llp_monitor` in `IP35/usr/cpu/sysgen/IP35boot/xbow.o` at 0x1db0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/xbow.o`.
  Range: 0x1db0-0x1dfc (76 bytes).
  It occupies 76 bytes.
  The `sw` at 0x1df8 stores 4 bytes to ret(hwgraph_fastinfo_get) +0x1c4.
  The `jal` at 0x1dbc calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1dd4 calls timeout with a0=sym(xbow_update_llp_status), a1=?, a2=0x64, a3=?.
  The return at 0x1df4 has v0 = 0x0.

- `idbg_xbowregs` in `IP35/usr/cpu/sysgen/IP35boot/xbow.o` at 0x1f00 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/xbow.o`.
  Range: 0x1f00-0x1fe4 (228 bytes).
  It occupies 228 bytes.
  16 such `lw` accesses load 4 bytes from ?, including `lw` at 0x1f3c, `lw` at 0x1f40, `lw` at 0x1f44.
  The `ld` at 0x1fe0 loads 8 bytes from ret(hwgraph_fastinfo_get) +0x10.
  The `jal` at 0x1f34 calls qprintf with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jal` at 0x1f54 calls qprintf with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jal` at 0x1f70 calls qprintf with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jal` at 0x1f80 calls qprintf with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jal` at 0x1fa8 calls qprintf with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jal` at 0x1fd4 calls hwgraph_fastinfo_get with a0=(a0 << 0x0), a1=(a0 << 0x0), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0x1f24 targets 0x1fd4, is taken when (at(?) & 0x1ff) == 0, and falls through when (at(?) & 0x1ff) != 0.
  The `bne` branch at 0x1fb8 targets 0x1f7c, is taken when s0(?) < 0x10 (signed), and falls through when s0(?) >= 0x10 (signed).
  The `beq` branch at 0x1fdc targets 0x1f2c and is always taken.
  The return at 0x1fcc has v0 = ret(qprintf).

- `xbow_bytes_to_gbr` in `IP35/usr/cpu/sysgen/IP35boot/xbow.o` at 0x1fe4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/xbow.o`.
  Range: 0x1fe4-0x2048 (100 bytes).
  It occupies 100 bytes.
  The `beq` branch at 0x200c targets 0x2018, is taken when at(?) >= a0 (signed), and falls through when at(?) < a0 (signed).
  The `bne` branch at 0x2034 targets 0x2040, is taken when a7(?) < a5(=(a0 + a1)) (signed), and falls through when a7(?) >= a5(=(a0 + a1)) (signed).
  The return at 0x2040 has v0 = ?.

- `xbow_gbr_to_bytes` in `IP35/usr/cpu/sysgen/IP35boot/xbow.o` at 0x2048 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/xbow.o`.
  Range: 0x2048-0x2060 (24 bytes).
  It occupies 24 bytes.
  The return at 0x2058 has v0 = ?.

- `xbow_prio_bw_alloc` in `IP35/usr/cpu/sysgen/IP35boot/xbow.o` at 0x2060 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/xbow.o`.
  Range: 0x2060-0x21d4 (372 bytes).
  It occupies 372 bytes.
  2 such `ld` accesses load 8 bytes from ret(hwgraph_fastinfo_get) +0x10, including `ld` at 0x20d0, `ld` at 0x20d4.
  The `ld` at 0x2118 loads 8 bytes from (ret(hwgraph_fastinfo_get) + (a2 << 0x3)) +0x210.
  The `ld` at 0x2120 loads 8 bytes from (ret(hwgraph_fastinfo_get) + (a2 << 0x3)) +0x1d0.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0x2124, `lw` at 0x2130.
  The `sw` at 0x21c4 stores 4 bytes to ?.
  The `sd` at 0x21c8 stores 8 bytes to (ret(hwgraph_fastinfo_get) + (a2 << 0x3)) +0x210.
  The `jal` at 0x208c calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x20a0 calls mutex_spinlock with a0=ret(hwgraph_fastinfo_get)+520, a1=?, a2=?, a3=?.
  The `jal` at 0x20f0 calls xbow_bytes_to_gbr with a0=a3 at entry (arg3), a1=a4 at entry (arg4), a2=one of 0x1c, 0x24, a3=?.
  The `jal` at 0x2104 calls xbow_gbr_to_bytes with a0=ret(xbow_bytes_to_gbr), a1=?, a2=?, a3=?.
  The `jal` at 0x2174 calls mutex_spinunlock with a0=ret(hwgraph_fastinfo_get)+520, a1=ret(mutex_spinlock), a2=?, a3=?.
  The `jal` at 0x2198 calls xbow_gbr_to_bytes with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x21c0 calls xbow_gbr_to_bytes with a0=?, a1=?, a2=?, a3=?, a4=(ret(hwgraph_fastinfo_get) + (a2 << 0x3)).
  The `bne` branch at 0x20b8 targets 0x20d4, is taken when s0(=a1) < 0x8 (signed), and falls through when s0(=a1) >= 0x8 (signed).
  The `beq` branch at 0x20c0 targets 0x20d4, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x20cc targets 0x20d8 and is always taken.
  The `bltz` branch at 0x20fc targets 0x2198, is taken when v0(=ret(xbow_bytes_to_gbr)) < 0 (signed), and falls through when v0(=ret(xbow_bytes_to_gbr)) >= 0 (signed).
  The `bne` branch at 0x2144 targets 0x215c, is taken when v1(=[(ret(hwgraph_fastinfo_get) + (a2 << 0x3))+464]:8) < a0(?) (unsigned), and falls through when v1(=[(ret(hwgraph_fastinfo_get) + (a2 << 0x3))+464]:8) >= a0(?) (unsigned).
  The `bne` branch at 0x2154 targets 0x21a8, is taken when a0(?) < 0x20 (signed), and falls through when a0(?) >= 0x20 (signed).
  The `beq` branch at 0x21a0 targets 0x2110 and is always taken.
  The `beq` branch at 0x21cc targets 0x2160 and is always taken.
  The return at 0x2190 has v0 = one of 0x0, 0x1.
