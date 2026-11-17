# Readings: `IP30/usr/cpu/sysgen/IP30boot/xbow.o`

One entry per routine, filed here from the reading batches by binary.

- `xbow_widget_num_get` in `IP30/usr/cpu/sysgen/IP30boot/xbow.o` at 0x3fc (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/xbow.o`.
  Range: 0x3fc-0x4e8 (236 bytes).
  It occupies 236 bytes.
  The `jal` at 0x410 calls vertex_to_name with a0=a0 at entry (arg0), a1=sp-288, a2=0x100, a3=a3 at entry (arg3).
  The `jal` at 0x424 calls hwgraph_edge_get with a0=a0 at entry (arg0), a1=sym(.rodata), a2=sp-32, a3=?.
  The `jal` at 0x438 calls strstr with a0=sp-288, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x450 calls strstr with a0=sp-288, a1=sym(.rodata), a2=?, a3=0xff.
  The `jal` at 0x474 calls hwgraph_edge_get with a0=a0 at entry (arg0), a1=sym(.rodata), a2=sp-32, a3=?.
  The `jal` at 0x4b8 calls xwidget_info_chk with a0=a0 at entry (arg0), a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x4d8 calls xwidget_info_id_get with a0=ret(xwidget_info_chk), a1=?, a2=?, a3=0xff.
  The `beq` branch at 0x42c targets 0x4d0, is taken when v0(=ret(hwgraph_edge_get)) == 0, and falls through when v0(=ret(hwgraph_edge_get)) != 0.
  The `beq` branch at 0x440 targets 0x490, is taken when v0(=ret(strstr)) == 0, and falls through when v0(=ret(strstr)) != 0.
  The `beq` branch at 0x458 targets 0x490, is taken when v0(=ret(strstr)) == 0, and falls through when v0(=ret(strstr)) != 0.
  The `beq` branch at 0x47c targets 0x4a4, is taken when v0(=ret(hwgraph_edge_get)) == 0, and falls through when v0(=ret(hwgraph_edge_get)) != 0.
  The `beq` branch at 0x484 targets 0x490 and is always taken.
  The `bne` branch at 0x4b0 targets 0x46c, is taken when a2(?) < 0x2 (signed), and falls through when a2(?) >= 0x2 (signed).
  The `bne` branch at 0x4c0 targets 0x4d8, is taken when v0(=ret(xwidget_info_chk)) != 0, and falls through when v0(=ret(xwidget_info_chk)) == 0.
  The `beq` branch at 0x4c8 targets 0x494 and is always taken.
  The `beq` branch at 0x4d0 targets 0x490 and is always taken.
  The `beq` branch at 0x4e0 targets 0x490 and is always taken.
  The return at 0x49c has v0 = one of ?, 0xff.
  The instructions from 0x48c to 0x48c are not reached by any path from the entry, and their branches are not listed.

- `xbow_ioctl` in `IP30/usr/cpu/sysgen/IP30boot/xbow.o` at 0x4e8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/xbow.o`.
  Range: 0x4e8-0x854 (876 bytes).
  It occupies 876 bytes.
  The `sw` at 0x4e8 stores 4 bytes to a5 (arg5 at entry) +0x0.
  The `jal` at 0x588 calls xbow_get_perf_counters with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0x5a0 calls copyout with a0=ret(xbow_get_perf_counters), a1=a2 at entry (arg2), a2=0x100, a3=?.
  The `jal` at 0x5cc calls cap_able_cred with a0=a4 at entry (arg4), a1=0x2000000000, a2=0x1, a3=a3 at entry (arg3).
  The `jal` at 0x5e8 calls copyin with a0=a2 at entry (arg2), a1=sp-64, a2=0xc, a3=?.
  The `jal` at 0x610 calls xbow_get_llp_status with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=0x6.
  The `jal` at 0x628 calls copyout with a0=ret(xbow_get_llp_status), a1=a2 at entry (arg2), a2=0x80, a3=?.
  The `jal` at 0x650 calls cap_able_cred with a0=a4 at entry (arg4), a1=0x2000000000, a2=?, a3=?, a5=0x4.
  The `jal` at 0x680 calls cap_able_cred with a0=a4 at entry (arg4), a1=0x2000000000, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x698 calls xbow_disable_llp_monitor with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x6ac calls cap_able with a0=0x2000000000, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=0x6.
  The `jal` at 0x6c0 calls copyin with a0=a2 at entry (arg2), a1=sp-96, a2=0x10, a3=?.
  The `jal` at 0x6ec calls cap_able with a0=0x2000000000, a1=0x6702, a2=a2 at entry (arg2), a3=0x6.
  The `jal` at 0x700 calls copyin with a0=a2 at entry (arg2), a1=sp-80, a2=0x10, a3=?.
  The `jal` at 0x734 calls xbow_enable_perf_counter with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x748 calls xbow_enable_llp_monitor with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x774 calls xbow_widget_num_get with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x780 calls xbow_widget_num_get with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x7a0 calls xbow_prio_bw_alloc with a0=a0 at entry (arg0), a1=?, a2=?, a3=0x0.
  The `jal` at 0x7b8 calls xbow_prio_bw_alloc with a0=a0 at entry (arg0), a1=?, a2=?, a3=0x0.
  The `jal` at 0x7c8 calls xbow_widget_num_get with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x7d4 calls xbow_widget_num_get with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x7f4 calls xbow_prio_bw_alloc with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x80c calls xbow_prio_bw_alloc with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x828 calls assfail with a0=sym(.rodata), a1=sym(.rodata), a2=0x264, a3=?.
  The `jal` at 0x844 calls assfail with a0=sym(.rodata), a1=sym(.rodata), a2=0x28c, a3=?.
  The `bne` branch at 0x514 targets 0x568, is taken when a1 < 0x5 (signed), and falls through when a1 >= 0x5 (signed).
  The `bne` branch at 0x520 targets 0x678, is taken when a1 < 0x6 (signed), and falls through when a1 >= 0x6 (signed).
  The `bne` branch at 0x528 targets 0x600, is taken when v1(?) != 0, and falls through when v1(?) == 0.
  The `bne` branch at 0x534 targets 0x6ac, is taken when a1 < 0x6702 (signed), and falls through when a1 >= 0x6702 (signed).
  The `beq` branch at 0x540 targets 0x6e8, is taken when s0(=a1) == a1(=0x6702), and falls through when s0(=a1) != a1(=0x6702).
  The `bne` branch at 0x56c targets 0x5b4, is taken when a1 < 0x3 (signed), and falls through when a1 >= 0x3 (signed).
  The `beq` branch at 0x578 targets 0x63c, is taken when a1 >= 0x4 (signed), and falls through when a1 < 0x4 (signed).
  The `beq` branch at 0x580 targets 0x6d8, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0x590 targets 0x81c, is taken when v0(=ret(xbow_get_perf_counters)) == 0, and falls through when v0(=ret(xbow_get_perf_counters)) != 0.
  The `beq` branch at 0x5ac targets 0x548 and is always taken.
  The `bne` branch at 0x5b4 targets 0x668, is taken when a5(?) != 0, and falls through when a5(?) == 0.
  The `beq` branch at 0x5bc targets 0x548, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x5d4 targets 0x764, is taken when v0(=ret(cap_able_cred)) == 0, and falls through when v0(=ret(cap_able_cred)) != 0.
  The `beq` branch at 0x5dc targets 0x6e0, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0x5f0 targets 0x720, is taken when v0(=ret(copyin)) == 0, and falls through when v0(=ret(copyin)) != 0.
  The `beq` branch at 0x5f8 targets 0x548 and is always taken.
  The `bne` branch at 0x600 targets 0x544, is taken when a1 != a3(=0x6), and falls through when a1 == a3(=0x6).
  The `beq` branch at 0x608 targets 0x718, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0x618 targets 0x838, is taken when v0(=ret(xbow_get_llp_status)) == 0, and falls through when v0(=ret(xbow_get_llp_status)) != 0.
  The `beq` branch at 0x634 targets 0x548 and is always taken.
  The `bne` branch at 0x640 targets 0x548, is taken when a1 != a5(=0x4), and falls through when a1 == a5(=0x4).
  The `bne` branch at 0x658 targets 0x748, is taken when v0(=ret(cap_able_cred)) != 0, and falls through when v0(=ret(cap_able_cred)) == 0.
  The `beq` branch at 0x660 targets 0x548 and is always taken.
  The `bne` branch at 0x668 targets 0x548, is taken when a1 != a2(=0x1), and falls through when a1 == a2(=0x1).
  The `beq` branch at 0x670 targets 0x5c8 and is always taken.
  The `bne` branch at 0x688 targets 0x698, is taken when v0(=ret(cap_able_cred)) != 0, and falls through when v0(=ret(cap_able_cred)) == 0.
  The `beq` branch at 0x690 targets 0x548 and is always taken.
  The `beq` branch at 0x6a4 targets 0x548 and is always taken.
  The `beq` branch at 0x6b4 targets 0x75c, is taken when v0(=ret(cap_able)) == 0, and falls through when v0(=ret(cap_able)) != 0.
  The `beq` branch at 0x6c8 targets 0x774, is taken when v0(=ret(copyin)) == 0, and falls through when v0(=ret(copyin)) != 0.
  The `beq` branch at 0x6d0 targets 0x548 and is always taken.
  The `beq` branch at 0x6d8 targets 0x548 and is always taken.
  The `beq` branch at 0x6e0 targets 0x548 and is always taken.
  The `beq` branch at 0x6f4 targets 0x76c, is taken when v0(=ret(cap_able)) == 0, and falls through when v0(=ret(cap_able)) != 0.
  The `beq` branch at 0x708 targets 0x7c8, is taken when v0(=ret(copyin)) == 0, and falls through when v0(=ret(copyin)) != 0.
  The `beq` branch at 0x710 targets 0x548 and is always taken.
  The `beq` branch at 0x718 targets 0x548 and is always taken.
  The `beq` branch at 0x740 targets 0x548 and is always taken.
  The `beq` branch at 0x754 targets 0x548 and is always taken.
  The `beq` branch at 0x75c targets 0x548 and is always taken.
  The `beq` branch at 0x764 targets 0x548 and is always taken.
  The `beq` branch at 0x76c targets 0x548 and is always taken.
  The `beq` branch at 0x7c0 targets 0x548 and is always taken.
  The `beq` branch at 0x814 targets 0x548 and is always taken.
  The `beq` branch at 0x830 targets 0x59c and is always taken.
  The `beq` branch at 0x84c targets 0x624 and is always taken.
  The return at 0x560 has v0 = one of 0x0, 0xe, 0x1, ?, 0x9.

- `xbow_link_alive` in `IP30/usr/cpu/sysgen/IP30boot/xbow.o` at 0x8b8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/xbow.o`.
  Range: 0x8b8-0x8d0 (24 bytes).
  It occupies 24 bytes.
  The `lw` at 0x8c4 loads 4 bytes from ?.
  The return at 0x8c8 has v0 = ?.

- `xbow_widget_lookup` in `IP30/usr/cpu/sysgen/IP30boot/xbow.o` at 0x8d0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/xbow.o`.
  Range: 0x8d0-0x900 (48 bytes).
  It occupies 48 bytes.
  The `jal` at 0x8dc calls xswitch_info_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x8e8 calls xswitch_info_vhdl_get with a0=ret(xswitch_info_get), a1=?, a2=?, a3=?.
  The return at 0x8f8 has v0 = ret(xswitch_info_vhdl_get).

- `xbow_setwidint` in `IP30/usr/cpu/sysgen/IP30boot/xbow.o` at 0x900 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/xbow.o`.
  Range: 0x900-0x96c (108 bytes).
  It occupies 108 bytes.
  The `jal` at 0x910 calls xtalk_intr_target_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x91c calls xtalk_intr_addr_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x928 calls xtalk_intr_vector_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x934 calls xtalk_intr_sfarg_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x954 calls xbow_intr_preset with a0=ret(xtalk_intr_sfarg_get), a1=0x0, a2=?, a3=ret(xtalk_intr_addr_get).
  The return at 0x964 has v0 = ret(xbow_intr_preset).

- `xbow_intr_preset` in `IP30/usr/cpu/sysgen/IP30boot/xbow.o` at 0x96c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/xbow.o`.
  Range: 0x96c-0x9a0 (52 bytes).
  It occupies 52 bytes.
  The `sw` at 0x994 stores 4 bytes to a0 (arg0 at entry) +0x34.
  The `sw` at 0x99c stores 4 bytes to a0 (arg0 at entry) +0x3c.
  The return at 0x998 has v0 = ?.

- `xem_add_ioe` in `IP30/usr/cpu/sysgen/IP30boot/xbow.o` at 0x9a0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/xbow.o`.
  Range: 0x9a0-0xbd4 (564 bytes).
  It occupies 564 bytes.
  14 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x0, including `lw` at 0x9a0, `lw` at 0xa5c, `lw` at 0xa78.
  The `lh` at 0xa4c loads 2 bytes from a0 (arg0 at entry) +0x4.
  The `lh` at 0xa68 loads 2 bytes from a0 (arg0 at entry) +0x6.
  The `lh` at 0xa84 loads 2 bytes from a0 (arg0 at entry) +0x8.
  The `lh` at 0xaa0 loads 2 bytes from a0 (arg0 at entry) +0xa.
  The `lh` at 0xabc loads 2 bytes from a0 (arg0 at entry) +0xc.
  The `lh` at 0xad8 loads 2 bytes from a0 (arg0 at entry) +0xe.
  The `ld` at 0xaf4 loads 8 bytes from a0 (arg0 at entry) +0x10.
  The `ld` at 0xb10 loads 8 bytes from a0 (arg0 at entry) +0x18.
  The `ld` at 0xb2c loads 8 bytes from a0 (arg0 at entry) +0x20.
  The `ld` at 0xb48 loads 8 bytes from a0 (arg0 at entry) +0x28.
  The `ld` at 0xb64 loads 8 bytes from a0 (arg0 at entry) +0x30.
  The `ld` at 0xb80 loads 8 bytes from a0 (arg0 at entry) +0x38.
  The `ld` at 0xba0 loads 8 bytes from a0 (arg0 at entry) +0x40.
  The `ld` at 0xbc0 loads 8 bytes from a0 (arg0 at entry) +0x48.
  The `jal` at 0xa50 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[a0+4]:2.
  The `jal` at 0xa6c calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[a0+6]:2.
  The `jal` at 0xa88 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[a0+8]:2.
  The `jal` at 0xaa4 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[a0+10]:2.
  The `jal` at 0xac0 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[a0+12]:2.
  The `jal` at 0xadc calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[a0+14]:2, a4=([a0] << 0x6).
  The `jal` at 0xaf8 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[a0+16]:8, a4=([a0] << 0x6), a5=([a0] << 0x7).
  The `jal` at 0xb14 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[a0+24]:8, a5=([a0] << 0x7), a6=([a0] << 0x8).
  The `jal` at 0xb30 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[a0+32]:8, a6=([a0] << 0x8), a7=([a0] << 0x9).
  The `jal` at 0xb4c calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[a0+40]:8, a7=([a0] << 0x9).
  The `jal` at 0xb68 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[a0+48]:8.
  The `jal` at 0xb84 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[a0+56]:8.
  The `jal` at 0xba4 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[a0+64]:8.
  The `jal` at 0xbc4 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[a0+72]:8.
  The `bne` branch at 0x9b8 targets 0xa40, is taken when at(?) != 0, and falls through when at(?) == 0.
  The `bltz` branch at 0x9c4 targets 0xa60, is taken when v0(=([a0] << 0x1)) < 0 (signed), and falls through when v0(=([a0] << 0x1)) >= 0 (signed).
  The `bltz` branch at 0x9d0 targets 0xa7c, is taken when v1(=([a0] << 0x2)) < 0 (signed), and falls through when v1(=([a0] << 0x2)) >= 0 (signed).
  The `bltz` branch at 0x9d8 targets 0xa98, is taken when a0(=([a0] << 0x3)) < 0 (signed), and falls through when a0(=([a0] << 0x3)) >= 0 (signed).
  The `bltz` branch at 0x9e0 targets 0xab4, is taken when a1(=([a0] << 0x4)) < 0 (signed), and falls through when a1(=([a0] << 0x4)) >= 0 (signed).
  The `bltz` branch at 0x9e8 targets 0xad0, is taken when a3(=([a0] << 0x5)) < 0 (signed), and falls through when a3(=([a0] << 0x5)) >= 0 (signed).
  The `bltz` branch at 0x9f0 targets 0xaec, is taken when a4(=([a0] << 0x6)) < 0 (signed), and falls through when a4(=([a0] << 0x6)) >= 0 (signed).
  The `bltz` branch at 0x9f8 targets 0xb08, is taken when a5(=([a0] << 0x7)) < 0 (signed), and falls through when a5(=([a0] << 0x7)) >= 0 (signed).
  The `bltz` branch at 0xa00 targets 0xb24, is taken when a6(=([a0] << 0x8)) < 0 (signed), and falls through when a6(=([a0] << 0x8)) >= 0 (signed).
  The `bltz` branch at 0xa08 targets 0xb40, is taken when a7(=([a0] << 0x9)) < 0 (signed), and falls through when a7(=([a0] << 0x9)) >= 0 (signed).
  The `bltz` branch at 0xa10 targets 0xb5c, is taken when t0(=([a0] << 0xa)) < 0 (signed), and falls through when t0(=([a0] << 0xa)) >= 0 (signed).
  The `bltz` branch at 0xa18 targets 0xb78, is taken when t1(=([a0] << 0xb)) < 0 (signed), and falls through when t1(=([a0] << 0xb)) >= 0 (signed).
  The `bltz` branch at 0xa20 targets 0xb94, is taken when t2(=([a0] << 0xc)) < 0 (signed), and falls through when t2(=([a0] << 0xc)) >= 0 (signed).
  The `bltz` branch at 0xa28 targets 0xbb4, is taken when t3(=([a0] << 0xd)) < 0 (signed), and falls through when t3(=([a0] << 0xd)) >= 0 (signed).
  The `beq` branch at 0xa58 targets 0x9c0 and is always taken.
  The `beq` branch at 0xa74 targets 0x9cc and is always taken.
  The `beq` branch at 0xa90 targets 0x9d4 and is always taken.
  The `beq` branch at 0xaac targets 0x9dc and is always taken.
  The `beq` branch at 0xac8 targets 0x9e4 and is always taken.
  The `beq` branch at 0xae4 targets 0x9ec and is always taken.
  The `beq` branch at 0xb00 targets 0x9f4 and is always taken.
  The `beq` branch at 0xb1c targets 0x9fc and is always taken.
  The `beq` branch at 0xb38 targets 0xa04 and is always taken.
  The `beq` branch at 0xb54 targets 0xa0c and is always taken.
  The `beq` branch at 0xb70 targets 0xa14 and is always taken.
  The `beq` branch at 0xb8c targets 0xa1c and is always taken.
  The `beq` branch at 0xbac targets 0xa24 and is always taken.
  The `beq` branch at 0xbcc targets 0xa30 and is always taken.
  The return at 0xa38 has v0 = one of ?, ret(cmn_err).

- `xbow_xmit_retry_error` in `IP30/usr/cpu/sysgen/IP30boot/xbow.o` at 0xbd4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/xbow.o`.
  Range: 0xbd4-0xcd8 (260 bytes).
  It occupies 260 bytes.
  The `ld` at 0xbe4 loads 8 bytes from (a0 + (a1 << 0x3)) +0x188.
  3 such `lw` accesses load 4 bytes from ?, including `lw` at 0xbf8, `lw` at 0xc58, `lw` at 0xc68.
  The `sw` at 0xc5c stores 4 bytes to ?.
  The `lw` at 0xc70 loads 4 bytes from a0 (arg0 at entry) +0x8.
  The `sd` at 0xcc4 stores 8 bytes to (a0 + (a1 << 0x3)) +0x188.
  The `jal` at 0xc6c calls xswitch_info_get with a0=[a0+8], a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a5=[(a0 + (a1 << 0x3))+392]:8.
  The `jal` at 0xc8c calls xswitch_info_vhdl_get with a0=ret(xswitch_info_get), a1=?, a2=?, a3=?, a4=0x1.
  The `jal` at 0xcac calls xtalk_piotrans_addr with a0=ret(xswitch_info_vhdl_get), a1=0x0, a2=0x0, a3=0x58, a4=0x0.
  The `beq` branch at 0xbf0 targets 0xc6c, is taken when a5(=[(a0 + (a1 << 0x3))+392]:8) == 0, and falls through when a5(=[(a0 + (a1 << 0x3))+392]:8) != 0.
  The `beq` branch at 0xc0c targets 0xc3c, is taken when a0(?) == a7(=0xc002), and falls through when a0(?) != a7(=0xc002).
  The `bne` branch at 0xc14 targets 0xc2c, is taken when a0(?) != a1(=0xd002), and falls through when a0(?) == a1(=0xd002).
  The `beq` branch at 0xc24 targets 0xc50, is taken when a1(?) == a2(=0x24), and falls through when a1(?) != a2(=0x24).
  The `bne` branch at 0xc48 targets 0xc14, is taken when a2(?) != a3(=0x36), and falls through when a2(?) == a3(=0x36).
  The `beq` branch at 0xc64 targets 0xc2c and is always taken.
  The `bne` branch at 0xc74 targets 0xc84, is taken when v0(=ret(xswitch_info_get)) != 0, and falls through when v0(=ret(xswitch_info_get)) == 0.
  The `beq` branch at 0xc7c targets 0xc30 and is always taken.
  The `beq` branch at 0xc98 targets 0xcc8, is taken when v0(=ret(xswitch_info_vhdl_get)) == a2(=-0x1), and falls through when v0(=ret(xswitch_info_vhdl_get)) != a2(=-0x1).
  The `beq` branch at 0xcb8 targets 0xcd0, is taken when v0(=ret(xtalk_piotrans_addr)) == 0, and falls through when v0(=ret(xtalk_piotrans_addr)) != 0.
  The `beq` branch at 0xcc0 targets 0xbf8 and is always taken.
  The `beq` branch at 0xcc8 targets 0xc2c and is always taken.
  The `beq` branch at 0xcd0 targets 0xc2c and is always taken.
  The return at 0xc34 has v0 = one of 0x0, 0x1.

- `xbow_errintr_handler` in `IP30/usr/cpu/sysgen/IP30boot/xbow.o` at 0xcd8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/xbow.o`.
  Range: 0xcd8-0x12cc (1524 bytes).
  It occupies 1524 bytes.
  The `ld` at 0xd04 loads 8 bytes from a0 (arg0 at entry) +0x10.
  The `lw` at 0xd0c loads 4 bytes from [a0+16]:8 +0x24.
  The `lw` at 0xd10 loads 4 bytes from [a0+16]:8 +0x54.
  The `lw` at 0xd14 loads 4 bytes from [a0+16]:8 +0x44.
  The `lw` at 0xd18 loads 4 bytes from [a0+16]:8 +0x14.
  The `lw` at 0xd1c loads 4 bytes from [a0+16]:8 +0x1c.
  The `sw` at 0xd28 stores 4 bytes to [a0+16]:8 +0x44.
  4 such `lw` accesses load 4 bytes from ?, including `lw` at 0xdec, `lw` at 0xdf0, `lw` at 0xe00.
  The `sw` at 0xe44 stores 4 bytes to ?.
  The `lw` at 0xf10 loads 4 bytes from a0 (arg0 at entry) +0x8.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x18, including `ld` at 0xf34, `ld` at 0x10b4.
  The `jal` at 0xe24 calls xbow_xmit_retry_error with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xe70 calls xbow_error_handler with a0=a0 at entry (arg0), a1=0x8, a2=0x1, a3=sp-272.
  The `jal` at 0xf0c calls xbow_widget_lookup with a0=[a0+8], a1=?, a2=?, a3=?.
  The `jal` at 0xf14 calls xwidget_name_get with a0=ret(xbow_widget_lookup), a1=?, a2=?, a3=?.
  The `jal` at 0xf30 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=[a0+24]:8, a3=?, a4=ret(xwidget_name_get).
  The `jal` at 0x1004 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[[a0+16]:8+84].
  The `jal` at 0x1018 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x102c calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x1040 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x1054 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x1080 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x1090 calls cmn_err_tag with a0=0x8, a1=0x0, a2=sym(.rodata), a3=?.
  The `jal` at 0x10b0 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=[a0+24]:8, a3=?.
  The `jal` at 0x10ec calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x1114 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x1128 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x113c calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x1150 calls xem_add_ioe with a0=sp-272, a1=?, a2=?, a3=?.
  The `jal` at 0x1168 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x1180 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x119c calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x11b8 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x11d0 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x11e8 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x1204 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x121c calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x1234 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x124c calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x1268 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x1280 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x129c calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `beq` branch at 0xd60 targets 0xef0, is taken when (s3(=[[a0+16]:8+84]) & at(=0xffffffffff000000)) == 0, and falls through when (s3(=[[a0+16]:8+84]) & at(=0xffffffffff000000)) != 0.
  The `beq` branch at 0xda8 targets 0x12ac and is always taken.
  The `bne` branch at 0xdb8 targets 0xf08, is taken when s1(?) != 0, and falls through when s1(?) == 0.
  The `beq` branch at 0xddc targets 0xe90, is taken when s0(?) >= 0x10 (signed), and falls through when s0(?) < 0x10 (signed).
  The `beq` branch at 0xde4 targets 0xdc0, is taken when t8(?) == 0, and falls through when t8(?) != 0.
  The `beq` branch at 0xe08 targets 0xe18, is taken when (s5(=0x20000) & s1(?)) == 0, and falls through when (s5(=0x20000) & s1(?)) != 0.
  The `beq` branch at 0xe14 targets 0xe50, is taken when s0(?) == t8(?), and falls through when s0(?) != t8(?).
  The `beq` branch at 0xe1c targets 0xdb8, is taken when t9(?) == 0, and falls through when t9(?) != 0.
  The `bne` branch at 0xe2c targets 0xdb0, is taken when v0(=ret(xbow_xmit_retry_error)) != 0, and falls through when v0(=ret(xbow_xmit_retry_error)) == 0.
  The `beq` branch at 0xe48 targets 0xdb0 and is always taken.
  The `beq` branch at 0xe7c targets 0xee0, is taken when v0(=ret(xbow_error_handler)) == 0, and falls through when v0(=ret(xbow_error_handler)) != 0.
  The `beq` branch at 0xe88 targets 0xe18 and is always taken.
  The `beq` branch at 0xe94 targets 0xeac, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `bne` branch at 0xea0 targets 0x10a8, is taken when (s3(=[[a0+16]:8+84]) & 0x25) != 0, and falls through when (s3(=[[a0+16]:8+84]) & 0x25) == 0.
  The `bne` branch at 0xeac targets 0xff8, is taken when a5(?) != 0, and falls through when a5(?) == 0.
  The `beq` branch at 0xee8 targets 0xe18 and is always taken.
  The `bgez` branch at 0xef0 targets 0xeb4, is taken when t0(?) >= 0 (signed), and falls through when t0(?) < 0 (signed).
  The `beq` branch at 0xef8 targets 0xeb4, is taken when t1(?) == 0, and falls through when t1(?) != 0.
  The `beq` branch at 0xf00 targets 0x10a0 and is always taken.
  The `bne` branch at 0xf40 targets 0x1160, is taken when (a3(=0x40000) & s4(?)) != 0, and falls through when (a3(=0x40000) & s4(?)) == 0.
  The `bne` branch at 0xf4c targets 0x1178, is taken when a4(?) != 0, and falls through when a4(?) == 0.
  The `bne` branch at 0xf5c targets 0x1190, is taken when (a5(=0x10000) & s4(?)) != 0, and falls through when (a5(=0x10000) & s4(?)) == 0.
  The `bne` branch at 0xf64 targets 0x11ac, is taken when a6(?) != 0, and falls through when a6(?) == 0.
  The `bne` branch at 0xf6c targets 0x11c8, is taken when a7(?) != 0, and falls through when a7(?) == 0.
  The `bne` branch at 0xf78 targets 0x11e0, is taken when t0(?) != 0, and falls through when t0(?) == 0.
  The `bne` branch at 0xf84 targets 0x11f8, is taken when t1(?) != 0, and falls through when t1(?) == 0.
  The `bne` branch at 0xf8c targets 0x1214, is taken when t2(?) != 0, and falls through when t2(?) == 0.
  The `bne` branch at 0xf98 targets 0x122c, is taken when t3(?) != 0, and falls through when t3(?) == 0.
  The `bne` branch at 0xfa4 targets 0x1244, is taken when t8(?) != 0, and falls through when t8(?) == 0.
  The `bne` branch at 0xfc0 targets 0x10e4, is taken when (t9(?) & ra(?)) != 0, and falls through when (t9(?) & ra(?)) == 0.
  The `bne` branch at 0xfd0 targets 0xfb4, is taken when s1(?) < 0x10 (signed), and falls through when s1(?) >= 0x10 (signed).
  The `bne` branch at 0xfdc targets 0x110c, is taken when v0(=[sym(kdebug)]:2) != 0, and falls through when v0(=[sym(kdebug)]:2) == 0.
  The `beq` branch at 0xff0 targets 0xdc0 and is always taken.
  The `beq` branch at 0x1098 targets 0xeb4 and is always taken.
  The `bne` branch at 0x10bc targets 0x125c, is taken when (s3(=[[a0+16]:8+84]) & 0x1) != 0, and falls through when (s3(=[[a0+16]:8+84]) & 0x1) == 0.
  The `bne` branch at 0x10c4 targets 0x1278, is taken when a4(?) != 0, and falls through when a4(?) == 0.
  The `bne` branch at 0x10d0 targets 0x1290, is taken when a5(?) != 0, and falls through when a5(?) == 0.
  The `beq` branch at 0x10dc targets 0xea8 and is always taken.
  The `bne` branch at 0x10fc targets 0xfb4, is taken when s1(?) < 0x10 (signed), and falls through when s1(?) >= 0x10 (signed).
  The `beq` branch at 0x1104 targets 0xfdc and is always taken.
  The `beq` branch at 0x1148 targets 0xfe8, is taken when t0(?) == 0, and falls through when t0(?) != 0.
  The `beq` branch at 0x1158 targets 0xfe4 and is always taken.
  The `beq` branch at 0x1170 targets 0xf4c and is always taken.
  The `beq` branch at 0x1188 targets 0xf58 and is always taken.
  The `beq` branch at 0x11a4 targets 0xf64 and is always taken.
  The `beq` branch at 0x11c0 targets 0xf6c and is always taken.
  The `beq` branch at 0x11d8 targets 0xf78 and is always taken.
  The `beq` branch at 0x11f0 targets 0xf84 and is always taken.
  The `beq` branch at 0x120c targets 0xf8c and is always taken.
  The `beq` branch at 0x1224 targets 0xf98 and is always taken.
  The `beq` branch at 0x123c targets 0xfa4 and is always taken.
  The `beq` branch at 0x1254 targets 0xfb0 and is always taken.
  The `beq` branch at 0x1270 targets 0x10c4 and is always taken.
  The `beq` branch at 0x1288 targets 0x10d0 and is always taken.
  The `beq` branch at 0x12a4 targets 0x10d8 and is always taken.
  The `beq` branch at 0x12c4 targets 0xde4 and is always taken.
  The return at 0xed8 has v0 = one of ?, ret(cmn_err_tag).

- `xbow_error_handler` in `IP30/usr/cpu/sysgen/IP30boot/xbow.o` at 0x12cc (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/xbow.o`.
  Range: 0x12cc-0x1980 (1716 bytes).
  It occupies 1716 bytes.
  The `lw` at 0x12cc loads 4 bytes from a0 (arg0 at entry) +0x8.
  The `ld` at 0x12d0 loads 8 bytes from a0 (arg0 at entry) +0x10.
  The `lh` at 0x12f0 loads 2 bytes from a3 (arg3 at entry) +0x6.
  The `lw` at 0x1314 loads 4 bytes from [a0+16]:8 +0xc.
  The `lw` at 0x1318 loads 4 bytes from [a0+16]:8 +0x44.
  The `lw` at 0x131c loads 4 bytes from [a0+16]:8 +0x14.
  The `lw` at 0x1320 loads 4 bytes from [a0+16]:8 +0x1c.
  3 such `lw` accesses load 4 bytes from ?, including `lw` at 0x139c, `lw` at 0x13a0, `lw` at 0x13a4.
  3 such `lw` accesses load 4 bytes from [a0+16]:8 +0x4, including `lw` at 0x13a8, `lw` at 0x13cc, `lw` at 0x14a8.
  The `lw` at 0x144c loads 4 bytes from a0 (arg0 at entry) +0x0.
  8 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x18, including `ld` at 0x1538, `ld` at 0x1558, `ld` at 0x1604.
  5 such `ld` accesses load 8 bytes from a3 (arg3 at entry) +0x18, including `ld` at 0x154c, `ld` at 0x1618, `ld` at 0x17d0.
  2 such `lw` accesses load 4 bytes from a3 (arg3 at entry) +0x0, including `lw` at 0x1760, `lw` at 0x1914.
  The `jal` at 0x1438 calls xbow_widget_lookup with a0=[a0+8], a1=[a3+6]:2, a2=?, a3=?.
  The `jal` at 0x14d8 calls xtalk_error_handler with a0=ret(xbow_widget_lookup), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x153c calls cmn_err with a0=0x1, a1=sym(.rodata), a2=[a0+24]:8, a3=[a3+6]:2, a5=[a0+8].
  The `jal` at 0x155c calls cmn_err with a0=0x1, a1=sym(.rodata), a2=[a0+24]:8, a3=[a3+6]:2, a4=[a3+24]:8.
  The `jal` at 0x1578 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?, a4=[sym(kdebug)]:2.
  The `jal` at 0x158c calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[[a0+16]:8+12].
  The `jal` at 0x15a0 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[[a0+16]:8+68].
  The `jal` at 0x15b4 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[[a0+16]:8+20].
  The `jal` at 0x15c8 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[[a0+16]:8+28].
  The `jal` at 0x15ec calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x1608 calls cmn_err with a0=0x1, a1=sym(.rodata), a2=[a0+24]:8, a3=a3 at entry (arg3), a5=[a0+8].
  The `jal` at 0x1624 calls cmn_err with a0=0x1, a1=sym(.rodata), a2=[a0+24]:8, a3=[a3+24]:8.
  The `jal` at 0x1640 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x1654 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[[a0+16]:8+12].
  The `jal` at 0x1668 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[[a0+16]:8+68].
  The `jal` at 0x167c calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[[a0+16]:8+20].
  The `jal` at 0x1690 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[[a0+16]:8+28].
  The `jal` at 0x16b4 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x16cc calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[a3+6]:2.
  The `jal` at 0x16e0 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x16f4 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x1708 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x174c calls cmn_err with a0=0x1, a1=sym(.rodata), a2=sym(.rodata), a3=sym(.rodata), a4=[a0+24]:8, a5=[a3+6]:2.
  The `jal` at 0x1788 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x17a0 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x17c0 calls cmn_err with a0=0x1, a1=sym(.rodata), a2=[a0+24]:8, a3=[a3+6]:2.
  The `jal` at 0x17e0 calls cmn_err with a0=0x1, a1=sym(.rodata), a2=[a0+24]:8, a3=[a3+6]:2, a4=[a3+24]:8.
  The `jal` at 0x17f8 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?, a4=[sym(kdebug)]:2.
  The `jal` at 0x180c calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[[a0+16]:8+12].
  The `jal` at 0x1820 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[[a0+16]:8+68].
  The `jal` at 0x1834 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[[a0+16]:8+20].
  The `jal` at 0x1848 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[[a0+16]:8+28].
  The `jal` at 0x186c calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x1884 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=[a3+6]:2.
  The `jal` at 0x1898 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x18ac calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x18c0 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=sym(.rodata), a3=?.
  The `jal` at 0x1900 calls cmn_err with a0=0x1, a1=sym(.rodata), a2=sym(.rodata), a3=sym(.rodata), a4=[a0+24]:8, a5=[a3+6]:2, a7=0x9.
  The `jal` at 0x195c calls cmn_err with a0=0x6, a1=sym(.rodata), a2=[a3+24]:8, a3=?, a5=([a3] << 0x7).
  The `jal` at 0x1970 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=[a3+24]:8, a3=?, a5=([a3] << 0x7).
  The `beq` branch at 0x130c targets 0x1410, is taken when s1(=[a3+6]:2) == 0, and falls through when s1(=[a3+6]:2) != 0.
  The `bne` branch at 0x132c targets 0x1340, is taken when s1(=[a3+6]:2) < 0x8 (signed), and falls through when s1(=[a3+6]:2) >= 0x8 (signed).
  The `bne` branch at 0x1338 targets 0x1394, is taken when s1(=[a3+6]:2) < 0x10 (signed), and falls through when s1(=[a3+6]:2) >= 0x10 (signed).
  The `beq` branch at 0x1340 targets 0x1474, is taken when s3(=a2) == 0, and falls through when s3(=a2) != 0.
  The `bne` branch at 0x1348 targets 0x1530, is taken when a2(?) != 0, and falls through when a2(?) == 0.
  The `bne` branch at 0x1354 targets 0x154c, is taken when a3(?) != 0, and falls through when a3(?) == 0.
  The `bne` branch at 0x1360 targets 0x156c, is taken when a4(=[sym(kdebug)]:2) != 0, and falls through when a4(=[sym(kdebug)]:2) == 0.
  The `beq` branch at 0x13c4 targets 0x13e0, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `beq` branch at 0x13dc targets 0x14a8, is taken when t1(?) == t2(=0xd100), and falls through when t1(?) != t2(=0xd100).
  The `beq` branch at 0x13e8 targets 0x147c, is taken when (t2(?) & 0x20) == 0, and falls through when (t2(?) & 0x20) != 0.
  The `bne` branch at 0x13f8 targets 0x1434, is taken when (t3(?) & t8(=0xffffffff80000000)) != 0, and falls through when (t3(?) & t8(=0xffffffff80000000)) == 0.
  The `bne` branch at 0x1400 targets 0x1718, is taken when s3(=a2) != 0, and falls through when s3(=a2) == 0.
  The `beq` branch at 0x1408 targets 0x1368 and is always taken.
  The `beq` branch at 0x1410 targets 0x1510, is taken when a2 == 0, and falls through when a2 != 0.
  The `bne` branch at 0x1418 targets 0x15fc, is taken when t9(?) != 0, and falls through when t9(?) == 0.
  The `bne` branch at 0x1420 targets 0x1618, is taken when ra(?) != 0, and falls through when ra(?) == 0.
  The `beq` branch at 0x1428 targets 0x1368 and is always taken.
  The `beq` branch at 0x1444 targets 0x1500, is taken when v0(=ret(xbow_widget_lookup)) == at(=-0x1), and falls through when v0(=ret(xbow_widget_lookup)) != at(=-0x1).
  The `bne` branch at 0x1450 targets 0x14d0, is taken when v1(=[a0]) != v0(=ret(xbow_widget_lookup)), and falls through when v1(=[a0]) == v0(=ret(xbow_widget_lookup)).
  The `beq` branch at 0x1458 targets 0x1518, is taken when s3(=a2) == 0, and falls through when s3(=a2) != 0.
  The `bne` branch at 0x1464 targets 0x1634, is taken when a1(=[sym(kdebug)]:2) != 0, and falls through when a1(=[sym(kdebug)]:2) == 0.
  The `beq` branch at 0x146c targets 0x1368 and is always taken.
  The `beq` branch at 0x1474 targets 0x1368 and is always taken.
  The `beq` branch at 0x147c targets 0x1520, is taken when s3(=a2) == 0, and falls through when s3(=a2) != 0.
  The `bne` branch at 0x1484 targets 0x17b0, is taken when a2(?) != 0, and falls through when a2(?) == 0.
  The `bne` branch at 0x148c targets 0x17d0, is taken when a3(?) != 0, and falls through when a3(?) == 0.
  The `bne` branch at 0x1498 targets 0x17f0, is taken when a4(=[sym(kdebug)]:2) != 0, and falls through when a4(=[sym(kdebug)]:2) == 0.
  The `beq` branch at 0x14a0 targets 0x1368 and is always taken.
  The `bne` branch at 0x14b4 targets 0x13e4, is taken when (a5(?) & 0x7ff) != 0, and falls through when (a5(?) & 0x7ff) == 0.
  The `bne` branch at 0x14c0 targets 0x13e4, is taken when s1(=[a3+6]:2) != a6(=0xf), and falls through when s1(=[a3+6]:2) == a6(=0xf).
  The `beq` branch at 0x14c8 targets 0x13f0 and is always taken.
  The `beq` branch at 0x14e0 targets 0x1528, is taken when v0(=ret(xtalk_error_handler)) == 0, and falls through when v0(=ret(xtalk_error_handler)) != 0.
  The `beq` branch at 0x14e8 targets 0x1518, is taken when s3(=a2) == 0, and falls through when s3(=a2) != 0.
  The `bne` branch at 0x14f0 targets 0x1464, is taken when v0(=ret(xtalk_error_handler)) != a7(=0x9), and falls through when v0(=ret(xtalk_error_handler)) == a7(=0x9).
  The `beq` branch at 0x14f8 targets 0x18d0 and is always taken.
  The `beq` branch at 0x1500 targets 0x1518, is taken when s3(=a2) == 0, and falls through when s3(=a2) != 0.
  The `beq` branch at 0x1508 targets 0x1460 and is always taken.
  The `beq` branch at 0x1510 targets 0x1368 and is always taken.
  The `beq` branch at 0x1518 targets 0x1368 and is always taken.
  The `beq` branch at 0x1520 targets 0x1368 and is always taken.
  The `beq` branch at 0x1528 targets 0x1368 and is always taken.
  The `beq` branch at 0x1544 targets 0x1354 and is always taken.
  The `beq` branch at 0x1564 targets 0x1360 and is always taken.
  The `beq` branch at 0x15f4 targets 0x1368 and is always taken.
  The `beq` branch at 0x1610 targets 0x1420 and is always taken.
  The `beq` branch at 0x162c targets 0x1428 and is always taken.
  The `beq` branch at 0x1710 targets 0x146c and is always taken.
  The `beq` branch at 0x1718 targets 0x192c, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0x172c targets 0x1934, is taken when (s2(=a1) & 0x4) == 0, and falls through when (s2(=a1) & 0x4) != 0.
  The `beq` branch at 0x1758 targets 0x1770, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `bltz` branch at 0x1768 targets 0x1954, is taken when a5(=([a3] << 0x7)) < 0 (signed), and falls through when a5(=([a3] << 0x7)) >= 0 (signed).
  The `beq` branch at 0x1774 targets 0x1798, is taken when (a6(?) & 0x40) == 0, and falls through when (a6(?) & 0x40) != 0.
  The `beq` branch at 0x1790 targets 0x1434 and is always taken.
  The `beq` branch at 0x17a8 targets 0x1434 and is always taken.
  The `beq` branch at 0x17c8 targets 0x148c and is always taken.
  The `beq` branch at 0x17e8 targets 0x1498 and is always taken.
  The `beq` branch at 0x18c8 targets 0x14a0 and is always taken.
  The `beq` branch at 0x18d0 targets 0x1940, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0x18e4 targets 0x1948, is taken when (s2(=a1) & 0x4) == 0, and falls through when (s2(=a1) & 0x4) != 0.
  The `beq` branch at 0x190c targets 0x1924, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `bltz` branch at 0x191c targets 0x196c, is taken when a5(=([a3] << 0x7)) < 0 (signed), and falls through when a5(=([a3] << 0x7)) >= 0 (signed).
  The `beq` branch at 0x1924 targets 0x1460 and is always taken.
  The `beq` branch at 0x192c targets 0x1728 and is always taken.
  The `beq` branch at 0x1938 targets 0x173c and is always taken.
  The `beq` branch at 0x1940 targets 0x18e0 and is always taken.
  The `beq` branch at 0x194c targets 0x18f4 and is always taken.
  The `beq` branch at 0x1964 targets 0x1770 and is always taken.
  The `beq` branch at 0x1978 targets 0x1924 and is always taken.
  The return at 0x138c has v0 = one of 0x6, 0x0, ?.
  The instructions from 0x1430 to 0x1430 are not reached by any path from the entry, and their branches are not listed.

- `xbow_update_perf_counters` in `IP30/usr/cpu/sysgen/IP30boot/xbow.o` at 0x1980 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/xbow.o`.
  Range: 0x1980-0x1a88 (264 bytes).
  It occupies 264 bytes.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0x19cc, `ld` at 0x1a04.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0x19d0, `lw` at 0x19dc.
  2 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x19d4, `lbu` at 0x1a34.
  The `sd` at 0x1a14 stores 8 bytes to ?.
  The `sw` at 0x1a20 stores 4 bytes to ?.
  The `jal` at 0x19a0 calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x19c4 calls mutex_spinlock with a0=ret(hwgraph_fastinfo_get)+448, a1=?, a2=?, a3=?.
  The `jal` at 0x1a1c calls mutex_spinunlock with a0=ret(hwgraph_fastinfo_get)+448, a1=ret(mutex_spinlock), a2=?, a3=?.
  The `jal` at 0x1a5c calls timeout with a0=sym(xbow_update_perf_counters), a1=?, a2=0x4, a3=?.
  The `beq` branch at 0x19bc targets 0x1a34 and is always taken.
  The `beq` branch at 0x1a2c targets 0x1a50, is taken when s1(?) >= 0x2 (signed), and falls through when s1(?) < 0x2 (signed).
  The `bne` branch at 0x1a38 targets 0x19c4, is taken when ra(?) != 0, and falls through when ra(?) == 0.
  The `bne` branch at 0x1a48 targets 0x1a34, is taken when s1(?) < 0x2 (signed), and falls through when s1(?) >= 0x2 (signed).
  The return at 0x1a80 has v0 = ret(timeout).

- `xbow_enable_perf_counter` in `IP30/usr/cpu/sysgen/IP30boot/xbow.o` at 0x1aa8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/xbow.o`.
  Range: 0x1aa8-0x1c74 (460 bytes).
  It occupies 460 bytes.
  The `ld` at 0x1ae8 loads 8 bytes from ret(hwgraph_fastinfo_get) +0x10.
  The `lbu` at 0x1b60 loads 1 byte from (ret(hwgraph_fastinfo_get) + (a3 << 0x4)) +0x25.
  2 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x1b9c, `lbu` at 0x1ba8.
  The `sb` at 0x1bc8 stores 1 byte to (ret(hwgraph_fastinfo_get) + (a3 << 0x4)) +0x27.
  The `sb` at 0x1bcc stores 1 byte to (ret(hwgraph_fastinfo_get) + (a3 << 0x4)) +0x25.
  The `sb` at 0x1bd4 stores 1 byte to (ret(hwgraph_fastinfo_get) + (a3 << 0x4)) +0x26.
  The `sb` at 0x1bdc stores 1 byte to (ret(hwgraph_fastinfo_get) + (a3 << 0x4)) +0x24.
  The `lw` at 0x1be8 loads 4 bytes from ([ret(hwgraph_fastinfo_get)+16]:8 + (a1 << 0x6)) -0xf4.
  The `sw` at 0x1c00 stores 4 bytes to ([ret(hwgraph_fastinfo_get)+16]:8 + (a1 << 0x6)) -0xf4.
  The `ld` at 0x1c08 loads 8 bytes from (ret(hwgraph_fastinfo_get) + (a3 << 0x4)) +0x28.
  The `lw` at 0x1c20 loads 4 bytes from [(ret(hwgraph_fastinfo_get) + (a3 << 0x4))+40]:8 +0x0.
  The `sw` at 0x1c40 stores 4 bytes to [(ret(hwgraph_fastinfo_get) + (a3 << 0x4))+40]:8 +0x0.
  The `sw` at 0x1c4c stores 4 bytes to (ret(hwgraph_fastinfo_get) + (a3 << 0x4)) +0x20.
  The `jal` at 0x1acc calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1b4c calls mutex_spinlock with a0=ret(hwgraph_fastinfo_get)+448, a1=?, a2=?, a3=?, a6=[ret(hwgraph_fastinfo_get)+16]:8.
  The `jal` at 0x1bb8 calls mutex_spinunlock with a0=ret(hwgraph_fastinfo_get)+448, a1=ret(mutex_spinlock), a2=?, a3=?, a7=a1-8.
  The `jal` at 0x1c48 calls timeout with a0=sym(xbow_update_perf_counters), a1=?, a2=0x4, a3=([ret(hwgraph_fastinfo_get)+16]:8 + (a1 << 0x6)), a6=0xfffff.
  The `jal` at 0x1c54 calls mutex_spinunlock with a0=ret(hwgraph_fastinfo_get)+448, a1=ret(mutex_spinlock), a2=?, a3=?.
  The `jal` at 0x1c64 calls mutex_spinunlock with a0=ret(hwgraph_fastinfo_get)+448, a1=ret(mutex_spinlock), a2=?, a3=?, a6=0x0, a7=a1-8.
  The `bne` branch at 0x1aec targets 0x1b20, is taken when s3(=a1) < 0x8 (signed), and falls through when s3(=a1) >= 0x8 (signed).
  The `beq` branch at 0x1af4 targets 0x1b20, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `bltz` branch at 0x1afc targets 0x1b40, is taken when s2(=a2) < 0 (signed), and falls through when s2(=a2) >= 0 (signed).
  The `beq` branch at 0x1b04 targets 0x1b40, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `bltz` branch at 0x1b0c targets 0x1b1c, is taken when s0(=a3) < 0 (signed), and falls through when s0(=a3) >= 0 (signed).
  The `bne` branch at 0x1b14 targets 0x1b48, is taken when a3(?) != 0, and falls through when a3(?) == 0.
  The `beq` branch at 0x1b40 targets 0x1b20 and is always taken.
  The `beq` branch at 0x1b68 targets 0x1b90, is taken when v0(=[(ret(hwgraph_fastinfo_get) + (a3 << 0x4))+37]:1) == 0, and falls through when v0(=[(ret(hwgraph_fastinfo_get) + (a3 << 0x4))+37]:1) != 0.
  The `beq` branch at 0x1b70 targets 0x1b90, is taken when s2(=a2) == 0, and falls through when s2(=a2) != 0.
  The `beq` branch at 0x1b78 targets 0x1c64 and is always taken.
  The `beq` branch at 0x1b88 targets 0x1bc8, is taken when a6(?) >= 0x2 (signed), and falls through when a6(?) < 0x2 (signed).
  The `beq` branch at 0x1b90 targets 0x1b80, is taken when s0(=a3) == a6(?), and falls through when s0(=a3) != a6(?).
  The `bne` branch at 0x1ba0 targets 0x1b80, is taken when a7(=a1-8) != t2(?), and falls through when a7(=a1-8) == t2(?).
  The `beq` branch at 0x1bac targets 0x1b84, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0x1bc0 targets 0x1b20 and is always taken.
  The `beq` branch at 0x1c5c targets 0x1b20 and is always taken.
  The `beq` branch at 0x1c6c targets 0x1b20 and is always taken.
  The return at 0x1b38 has v0 = one of -0x1, 0x0.

- `xbow_update_llp_status` in `IP30/usr/cpu/sysgen/IP30boot/xbow.o` at 0x1c94 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/xbow.o`.
  Range: 0x1c94-0x1da8 (276 bytes).
  It occupies 276 bytes.
  The `ld` at 0x1ccc loads 8 bytes from ret(hwgraph_fastinfo_get) +0x10.
  The `lw` at 0x1cd8 loads 4 bytes from ret(hwgraph_fastinfo_get) +0x8.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0x1cf4, `lw` at 0x1cf8.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0x1d10, `ld` at 0x1d18.
  2 such `sd` accesses store 8 bytes to ?, including `sd` at 0x1d20, `sd` at 0x1d2c.
  The `lw` at 0x1d44 loads 4 bytes from ret(hwgraph_fastinfo_get) +0x1c4.
  The `jal` at 0x1cb4 calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1cdc calls xbow_widget_lookup with a0=[ret(hwgraph_fastinfo_get)+8], a1=?, a2=?, a3=?.
  The `jal` at 0x1ce4 calls xwidget_name_get with a0=ret(xbow_widget_lookup), a1=?, a2=?, a3=?.
  The `jal` at 0x1d5c calls timeout with a0=sym(xbow_update_llp_status), a1=?, a2=0x64, a3=?.
  The `jal` at 0x1d98 calls cmn_err with a0=0x4, a1=sym(.rodata), a2=?, a3=ret(xwidget_name_get).
  The `beq` branch at 0x1d08 targets 0x1d30, is taken when t8(?) == 0, and falls through when t8(?) != 0.
  The `bne` branch at 0x1d28 targets 0x1d88, is taken when a6(?) != 0, and falls through when a6(?) == 0.
  The `bne` branch at 0x1d3c targets 0x1cd8, is taken when s0(?) < 0x8 (signed), and falls through when s0(?) >= 0x8 (signed).
  The `beq` branch at 0x1d48 targets 0x1d64, is taken when t3(=[ret(hwgraph_fastinfo_get)+452]) == 0, and falls through when t3(=[ret(hwgraph_fastinfo_get)+452]) != 0.
  The `beq` branch at 0x1da0 targets 0x1d34 and is always taken.
  The return at 0x1d80 has v0 = one of ?, ret(timeout).

- `xbow_disable_llp_monitor` in `IP30/usr/cpu/sysgen/IP30boot/xbow.o` at 0x1da8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/xbow.o`.
  Range: 0x1da8-0x1df0 (72 bytes).
  It occupies 72 bytes.
  2 such `sd` accesses store 8 bytes to ?, including `sd` at 0x1dd4, `sd` at 0x1ddc.
  The `sw` at 0x1de4 stores 4 bytes to ret(hwgraph_fastinfo_get) +0x1c4.
  The `jal` at 0x1db0 calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `bne` branch at 0x1dd8 targets 0x1dc4, is taken when a2(?) < 0x8 (signed), and falls through when a2(?) >= 0x8 (signed).
  The return at 0x1de8 has v0 = 0x0.

- `xbow_enable_llp_monitor` in `IP30/usr/cpu/sysgen/IP30boot/xbow.o` at 0x1df0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/xbow.o`.
  Range: 0x1df0-0x1e3c (76 bytes).
  It occupies 76 bytes.
  The `sw` at 0x1e38 stores 4 bytes to ret(hwgraph_fastinfo_get) +0x1c4.
  The `jal` at 0x1dfc calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1e14 calls timeout with a0=sym(xbow_update_llp_status), a1=?, a2=0x64, a3=?.
  The return at 0x1e34 has v0 = 0x0.

- `idbg_xbowregs` in `IP30/usr/cpu/sysgen/IP30boot/xbow.o` at 0x1f28 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/xbow.o`.
  Range: 0x1f28-0x200c (228 bytes).
  It occupies 228 bytes.
  16 such `lw` accesses load 4 bytes from ?, including `lw` at 0x1f64, `lw` at 0x1f68, `lw` at 0x1f6c.
  The `ld` at 0x2008 loads 8 bytes from ret(hwgraph_fastinfo_get) +0x10.
  The `jal` at 0x1f5c calls qprintf with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jal` at 0x1f7c calls qprintf with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jal` at 0x1f98 calls qprintf with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jal` at 0x1fa8 calls qprintf with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jal` at 0x1fd0 calls qprintf with a0=sym(.rodata), a1=?, a2=?, a3=?.
  The `jal` at 0x1ffc calls hwgraph_fastinfo_get with a0=(a0 << 0x0), a1=(a0 << 0x0), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0x1f4c targets 0x1ffc, is taken when (at(?) & 0x1ff) == 0, and falls through when (at(?) & 0x1ff) != 0.
  The `bne` branch at 0x1fe0 targets 0x1fa4, is taken when s0(?) < 0x10 (signed), and falls through when s0(?) >= 0x10 (signed).
  The `beq` branch at 0x2004 targets 0x1f54 and is always taken.
  The return at 0x1ff4 has v0 = ret(qprintf).

- `xbow_bytes_to_gbr` in `IP30/usr/cpu/sysgen/IP30boot/xbow.o` at 0x200c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/xbow.o`.
  Range: 0x200c-0x2070 (100 bytes).
  It occupies 100 bytes.
  The `beq` branch at 0x2034 targets 0x2040, is taken when at(?) >= a0 (signed), and falls through when at(?) < a0 (signed).
  The `bne` branch at 0x205c targets 0x2068, is taken when a7(?) < a5(=(a0 + a1)) (signed), and falls through when a7(?) >= a5(=(a0 + a1)) (signed).
  The return at 0x2068 has v0 = ?.

- `xbow_gbr_to_bytes` in `IP30/usr/cpu/sysgen/IP30boot/xbow.o` at 0x2070 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/xbow.o`.
  Range: 0x2070-0x2088 (24 bytes).
  It occupies 24 bytes.
  The return at 0x2080 has v0 = ?.

- `xbow_prio_bw_alloc` in `IP30/usr/cpu/sysgen/IP30boot/xbow.o` at 0x2088 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/xbow.o`.
  Range: 0x2088-0x21fc (372 bytes).
  It occupies 372 bytes.
  2 such `ld` accesses load 8 bytes from ret(hwgraph_fastinfo_get) +0x10, including `ld` at 0x20f8, `ld` at 0x20fc.
  The `ld` at 0x2140 loads 8 bytes from (ret(hwgraph_fastinfo_get) + (a2 << 0x3)) +0x210.
  The `ld` at 0x2148 loads 8 bytes from (ret(hwgraph_fastinfo_get) + (a2 << 0x3)) +0x1d0.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0x214c, `lw` at 0x2158.
  The `sw` at 0x21ec stores 4 bytes to ?.
  The `sd` at 0x21f0 stores 8 bytes to (ret(hwgraph_fastinfo_get) + (a2 << 0x3)) +0x210.
  The `jal` at 0x20b4 calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x20c8 calls mutex_spinlock with a0=ret(hwgraph_fastinfo_get)+520, a1=?, a2=?, a3=?.
  The `jal` at 0x2118 calls xbow_bytes_to_gbr with a0=a3 at entry (arg3), a1=a4 at entry (arg4), a2=one of 0x1c, 0x24, a3=?.
  The `jal` at 0x212c calls xbow_gbr_to_bytes with a0=ret(xbow_bytes_to_gbr), a1=?, a2=?, a3=?.
  The `jal` at 0x219c calls mutex_spinunlock with a0=ret(hwgraph_fastinfo_get)+520, a1=ret(mutex_spinlock), a2=?, a3=?.
  The `jal` at 0x21c0 calls xbow_gbr_to_bytes with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x21e8 calls xbow_gbr_to_bytes with a0=?, a1=?, a2=?, a3=?, a4=(ret(hwgraph_fastinfo_get) + (a2 << 0x3)).
  The `bne` branch at 0x20e0 targets 0x20fc, is taken when s0(=a1) < 0x8 (signed), and falls through when s0(=a1) >= 0x8 (signed).
  The `beq` branch at 0x20e8 targets 0x20fc, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x20f4 targets 0x2100 and is always taken.
  The `bltz` branch at 0x2124 targets 0x21c0, is taken when v0(=ret(xbow_bytes_to_gbr)) < 0 (signed), and falls through when v0(=ret(xbow_bytes_to_gbr)) >= 0 (signed).
  The `bne` branch at 0x216c targets 0x2184, is taken when v1(=[(ret(hwgraph_fastinfo_get) + (a2 << 0x3))+464]:8) < a0(?) (unsigned), and falls through when v1(=[(ret(hwgraph_fastinfo_get) + (a2 << 0x3))+464]:8) >= a0(?) (unsigned).
  The `bne` branch at 0x217c targets 0x21d0, is taken when a0(?) < 0x20 (signed), and falls through when a0(?) >= 0x20 (signed).
  The `beq` branch at 0x21c8 targets 0x2138 and is always taken.
  The `beq` branch at 0x21f4 targets 0x2188 and is always taken.
  The return at 0x21b8 has v0 = one of 0x0, 0x1.
