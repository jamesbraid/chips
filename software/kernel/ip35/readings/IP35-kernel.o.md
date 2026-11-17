# Readings: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`

One entry per routine, filed here from the reading batches by binary.

- `restart` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x10c0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x10c0-0x1238 (376 bytes).
  It occupies 376 bytes.
  2 such `lh` accesses load 2 bytes from ?, including `lh` at 0x10f4, `lh` at 0x111c.
  2 such `sd` accesses store 8 bytes to ?, including `sd` at 0x1100, `sd` at 0x1128.
  2 such `lh` accesses load 2 bytes from abs 0xffffffffffffc428, including `lh` at 0x1198, `lh` at 0x1234.
  The `sd` at 0x121c stores 8 bytes to abs 0x9200000001680010.
  The `sd` at 0x1228 stores 8 bytes to abs 0x9200000001680008.
  The `jal` at 0x114c calls us_delay with a0=0xf4240, a1=?, a2=0x9200000001e10000, a3=sym(compact_to_nasid_node).
  The `jal` at 0x1178 calls get_elsc with a0=?, a1=?, a2=[sym(power_off_flag)], a3=?.
  The `jal` at 0x1180 calls sc_power_down_all with a0=ret(get_elsc), a1=?, a2=?, a3=?.
  The `jal` at 0x1188 calls us_delay with a0=0x2dc6c0, a1=?, a2=?, a3=?.
  The `jal` at 0x11b8 calls ni_reset_port with a0=?, a1=?, a2=[sym(power_off_flag)], a3=?.
  The `jal` at 0x11d0 calls get_nasid with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x11dc calls elsc_init with a0=sp-2416, a1=ret(get_nasid), a2=?, a3=?.
  The `jal` at 0x11e4 calls elsc_system_reset with a0=sp-2416, a1=?, a2=?, a3=?.
  The `jal` at 0x1200 calls printf with a0=sym(.rodata)+120, a1=?, a2=?, a3=?.
  The `jal` at 0x1208 calls us_delay with a0=0xf4240, a1=?, a2=?, a3=?.
  The `beq` branch at 0x10d8 targets 0x11c8, is taken when at(=[sym(panic_level)]) == 0, and falls through when at(=[sym(panic_level)]) != 0.
  The `blez` branch at 0x10e0 targets 0x1144, is taken when a4(=[sym(maxnodes)]) <= 0 (signed), and falls through when a4(=[sym(maxnodes)]) > 0 (signed).
  The `beq` branch at 0x1110 targets 0x1140, is taken when s0(?) >= v0(=[sym(maxnodes)]) (signed), and falls through when s0(?) < v0(=[sym(maxnodes)]) (signed).
  The `bne` branch at 0x1138 targets 0x10f0, is taken when s0(?) < a1(=[sym(maxnodes)]) (signed), and falls through when s0(?) >= a1(=[sym(maxnodes)]) (signed).
  The `beq` branch at 0x1160 targets 0x11d0, is taken when t8(=[sym(reboot_on_panic)]) == t9(=0x2), and falls through when t8(=[sym(reboot_on_panic)]) != t9(=0x2).
  The `beq` branch at 0x1168 targets 0x122c and is always taken.
  The `beq` branch at 0x1170 targets 0x11b8, is taken when a2(=[sym(power_off_flag)]) == 0, and falls through when a2(=[sym(power_off_flag)]) != 0.
  The `beq` branch at 0x11a0 targets 0x1170, is taken when ra(=[-0x3bd8]:2) == at(=[sym(master_procid)]:2), and falls through when ra(=[-0x3bd8]:2) != at(=[sym(master_procid)]:2).
  The `bgtz` branch at 0x11a8 targets 0x1170, is taken when s0(?) > 0 (signed), and falls through when s0(?) <= 0 (signed).
  The `beq` branch at 0x11b0 targets 0x1188 and is always taken.
  The `beq` branch at 0x11c0 targets 0x1188 and is always taken.
  The `beq` branch at 0x11c8 targets 0x10e0 and is always taken.
  The `bltz` branch at 0x11ec targets 0x1200, is taken when v0(=ret(elsc_system_reset)) < 0 (signed), and falls through when v0(=ret(elsc_system_reset)) >= 0 (signed).
  The `beq` branch at 0x1224 targets 0x11f0 and is always taken.
  The `beq` branch at 0x1230 targets 0x119c and is always taken.
  The return at 0x11f8 has v0 = one of ret(elsc_system_reset), ?.

- `get_nasid` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x12b4
  It reads one doubleword at the fixed address 0x9200000001600000 and returns it, and the return value is unresolved in the facts. Callers such as `getcpuid`, `hubpi_eint_handler` and `klsave_spool_registers` pass the result on as an argument to other node routines. The facts do not show the register at that address or how the value is decoded.
  Grade: inferred.
  Reviewed: 2026-11-12

- `get_slice` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x12d0
  It loads the doubleword at 0x9200000001000020 and returns it unchanged. `getcpuid` passes the same doubleword as the second argument to `nasid_slice_to_cpuinfo`, which fits a slice number, but the value's layout is not shown. The facts establish the load and the return only.
  Grade: inferred.
  Reviewed: 2026-11-12

- `is_fine_dirmode` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x12e0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x12e0-0x12f8 (24 bytes).
  It occupies 24 bytes.
  The `ld` at 0x12e4 loads 8 bytes from abs 0x9200000001600000.
  The return at 0x12f0 has v0 = ?.

- `ni_reset_port` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x13b4
  It stores two doublewords, at 0x9200000001680010 and 0x9200000001680008, and returns the second address. The stored values are not shown, so the facts do not say whether the stores assert or clear a reset. The name points at a network-interface port reset in the hub register window, which the facts neither confirm nor rule out.
  Grade: inferred.
  Reviewed: 2026-11-12

- `numalinkstats_up2date` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x2344 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x2344-0x2424 (224 bytes).
  It occupies 224 bytes.
  The `ld` at 0x2358 loads 8 bytes from abs 0xffffffffffffc400.
  The `ld` at 0x2368 loads 8 bytes from [-0x3c00]:8 +0x0.
  5 such `ld` accesses load 8 bytes from ?, including `ld` at 0x237c, `ld` at 0x2384, `ld` at 0x2390.
  The `ld` at 0x23d0 loads 8 bytes from abs 0x9200000001030100.
  The `ld` at 0x23d4 loads 8 bytes from abs 0x9200000001604200.
  The `blez` branch at 0x2350 targets 0x23d0, is taken when t3(=[sym(numnodes)]) <= 0 (signed), and falls through when t3(=[sym(numnodes)]) > 0 (signed).
  The `beq` branch at 0x2388 targets 0x23bc, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0x2394 targets 0x23b0, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0x23a4 targets 0x23b0, is taken when a4(?) >= a5(?) (unsigned), and falls through when a4(?) < a5(?) (unsigned).
  The `bne` branch at 0x23b4 targets 0x2390, is taken when a2(?) != 0, and falls through when a2(?) == 0.
  The `bne` branch at 0x23c8 targets 0x2378, is taken when a6(?) < t3(=[sym(numnodes)]) (signed), and falls through when a6(?) >= t3(=[sym(numnodes)]) (signed).
  The return at 0x241c has v0 = ?.

- `router_set_leds` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x26cc (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x26cc-0x270c (64 bytes).
  It occupies 64 bytes.
  2 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x7, including `lbu` at 0x26cc, `lbu` at 0x26f0.
  The `lbu` at 0x26d0 loads 1 byte from a0 (arg0 at entry) +0x6.
  The `sb` at 0x26fc stores 1 byte to a0 (arg0 at entry) +0x6.
  The `jal` at 0x26f8 calls router_reg_write with a0=a0 at entry (arg0), a1=0x200, a2=[a0+7]:1, a3=a3 at entry (arg3).
  The `bne` branch at 0x26d8 targets 0x26f0, is taken when at(=[a0+6]:1) != v0(=[a0+7]:1), and falls through when at(=[a0+6]:1) == v0(=[a0+7]:1).
  The `beq` branch at 0x2704 targets 0x26e4 and is always taken.
  The return at 0x26e8 has v0 = one of 0x0, ret(router_reg_write).

- `router_decode_port_errors` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x270c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x270c-0x27bc (176 bytes).
  It occupies 176 bytes.
  4 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x10, including `ld` at 0x270c, `ld` at 0x2728, `ld` at 0x2748.
  The `lw` at 0x2720 loads 4 bytes from a0 (arg0 at entry) +0x18.
  The `sw` at 0x2724 stores 4 bytes to a1 (arg1 at entry) +0x0.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x18, including `sw` at 0x2734, `sw` at 0x2790.
  The `lw` at 0x2740 loads 4 bytes from a0 (arg0 at entry) +0x1c.
  The `sw` at 0x2744 stores 4 bytes to a1 (arg1 at entry) +0x4.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x1c, including `sw` at 0x2750, `sw` at 0x27a4.
  The `lw` at 0x2760 loads 4 bytes from a0 (arg0 at entry) +0x20.
  The `sw` at 0x2764 stores 4 bytes to a1 (arg1 at entry) +0x8.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x20, including `sw` at 0x2774, `sw` at 0x27b8.
  The `lw` at 0x2780 loads 4 bytes from a1 (arg1 at entry) +0x0.
  The `lw` at 0x2794 loads 4 bytes from a1 (arg1 at entry) +0x4.
  The `lw` at 0x27a8 loads 4 bytes from a1 (arg1 at entry) +0x8.
  The `beq` branch at 0x271c targets 0x2780, is taken when a5(=0xff) == a6(?), and falls through when a5(=0xff) != a6(?).
  The `beq` branch at 0x273c targets 0x2794, is taken when a5(=0xff) == a6(?), and falls through when a5(=0xff) != a6(?).
  The `beq` branch at 0x275c targets 0x27a8, is taken when a5(=0xff) == a6(?), and falls through when a5(=0xff) != a6(?).
  The `beq` branch at 0x278c targets 0x2738 and is always taken.
  The `beq` branch at 0x27a0 targets 0x2754 and is always taken.
  The return at 0x2778 has v0 = ?.
  The return at 0x27b4 has v0 = ?.

- `router_acquire_port_info` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x27bc (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x27bc-0x2a1c (608 bytes).
  It occupies 608 bytes.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0x27f4, `lw` at 0x2910.
  2 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x7, including `lbu` at 0x2804, `lbu` at 0x29d4.
  3 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x7, including `sb` at 0x2814, `sb` at 0x2930, `sb` at 0x29e4.
  The `lbu` at 0x2834 loads 1 byte from a0 (arg0 at entry) +0x228.
  3 such `ld` accesses load 8 bytes from ?, including `ld` at 0x2860, `ld` at 0x293c, `ld` at 0x2950.
  5 such `sh` accesses store 2 bytes to ?, including `sh` at 0x2880, `sh` at 0x2948, `sh` at 0x2998.
  2 such `lh` accesses load 2 bytes from a0 (arg0 at entry) +0x1f8, including `lh` at 0x2898, `lh` at 0x28c8.
  2 such `lh` accesses load 2 bytes from a0 (arg0 at entry) +0x4, including `lh` at 0x28a0, `lh` at 0x28cc.
  The `sd` at 0x28e8 stores 8 bytes to ?.
  The `lbu` at 0x2914 loads 1 byte from a0 (arg0 at entry) +0x6.
  2 such `lhu` accesses load 2 bytes from ?, including `lhu` at 0x29b4, `lhu` at 0x29c4.
  The `jal` at 0x28ac calls read_rr_reg with a0=[a0+4]:2, a1=[a0+504]:2, a2=(a1 + a1)-1, a3=?, a4=sp-336.
  The `jal` at 0x28d0 calls read_rr_reg with a0=[a0+4]:2, a1=[a0+504]:2, a2=?, a3=sp-80, a4=sp-336.
  The `jal` at 0x28e4 calls mutex_spinlock with a0=a0+572, a1=?, a2=?, a3=?.
  The `jal` at 0x2904 calls router_decode_port_errors with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x292c calls mutex_spinunlock with a0=a0+572, a1=?, a2=?, a3=[a0+7]:1.
  The `jal` at 0x2a0c calls mutex_spinunlock with a0=a0+572, a1=?, a2=[a0+552]:1, a3=?.
  The `beq` branch at 0x27ec targets 0x2894, is taken when a2 == 0, and falls through when a2 != 0.
  The `beq` branch at 0x27fc targets 0x2834, is taken when t8(?) == 0, and falls through when t8(?) != 0.
  The `beq` branch at 0x2808 targets 0x2914, is taken when s3(=a2) == 0, and falls through when s3(=a2) != 0.
  The `beq` branch at 0x283c targets 0x293c, is taken when v0(=0x1) == a2(=[a0+552]:1), and falls through when v0(=0x1) != a2(=[a0+552]:1).
  The `bne` branch at 0x287c targets 0x2848, is taken when v0(?) < 0x4 (signed), and falls through when v0(?) >= 0x4 (signed).
  The `beq` branch at 0x2884 targets 0x2a0c, is taken when s3(=a2) == 0, and falls through when s3(=a2) != 0.
  The `beq` branch at 0x288c targets 0x2818 and is always taken.
  The `beq` branch at 0x28b4 targets 0x29e8, is taken when v0(=ret(read_rr_reg)) == 0, and falls through when v0(=ret(read_rr_reg)) != 0.
  The `beq` branch at 0x28d8 targets 0x29f8, is taken when v0(=ret(read_rr_reg)) == 0, and falls through when v0(=ret(read_rr_reg)) != 0.
  The `beq` branch at 0x290c targets 0x27f8 and is always taken.
  The `beq` branch at 0x2934 targets 0x2818 and is always taken.
  The `beq` branch at 0x2944 targets 0x29b4, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x29bc targets 0x29d4, is taken when t1(?) >= 0x14 (signed), and falls through when t1(?) < 0x14 (signed).
  The `bne` branch at 0x29cc targets 0x2884, is taken when t2(?) < 0x14 (signed), and falls through when t2(?) >= 0x14 (signed).
  The `beq` branch at 0x29e0 targets 0x2884 and is always taken.
  The `beq` branch at 0x29f0 targets 0x2818 and is always taken.
  The `beq` branch at 0x2a04 targets 0x2818 and is always taken.
  The `beq` branch at 0x2a14 targets 0x288c and is always taken.
  The return at 0x282c has v0 = one of 0x0, 0x1.

- `router_print_error` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x2b84 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x2b84-0x2c5c (216 bytes).
  It occupies 216 bytes.
  The `ld` at 0x2b84 loads 8 bytes from a0 (arg0 at entry) +0x220.
  The `lbu` at 0x2be8 loads 1 byte from (a4 + a0) +0x257.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x250, including `ld` at 0x2c14, `ld` at 0x2c48.
  The `sb` at 0x2c28 stores 1 byte to (a4 + a0) +0x257.
  The `jal` at 0x2bf8 calls error_flag_to_type [0x2b3c] with a0=a3 at entry (arg3), a1=a1 at entry (arg1), a2=(a3 | [(a4 + a0)+599]:1), a3=a3 at entry (arg3), a4=(a4 + a0).
  The `jal` at 0x2c18 calls cmn_err with a0=0x4, a1=sym(.rodata)+616, a2=ret(error_flag_to_type), a3=?, a4=[a0+592]:8, a5=a4 at entry (arg4).
  The `jal` at 0x2c2c calls error_flag_to_type [0x2b3c] with a0=a3 at entry (arg3), a1=a1 at entry (arg1), a2=(a3 | [(a4 + a0)+599]:1), a3=a3 at entry (arg3), a4=(a4 + a0).
  The `jal` at 0x2c4c calls cmn_err with a0=0x404, a1=sym(.rodata)+616, a2=ret(error_flag_to_type), a3=?, a4=[a0+592]:8, a5=a4 at entry (arg4).
  The `beq` branch at 0x2bc0 targets 0x2be4, is taken when s2(?) >= 0x1f5 (signed), and falls through when s2(?) < 0x1f5 (signed).
  The `beq` branch at 0x2bf0 targets 0x2c28, is taken when (a3 & v0(=[(a4 + a0)+599]:1)) == 0, and falls through when (a3 & v0(=[(a4 + a0)+599]:1)) != 0.
  The `beq` branch at 0x2c20 targets 0x2c54 and is always taken.
  The `beq` branch at 0x2c54 targets 0x2bcc and is always taken.
  The return at 0x2bdc has v0 = one of 0x0, 0x1.

- `router_check_port` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x2c5c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x2c5c-0x2d04 (168 bytes).
  It occupies 168 bytes.
  The `ld` at 0x2c6c loads 8 bytes from a0 (arg0 at entry) +0x28.
  The `ld` at 0x2c74 loads 8 bytes from a0 (arg0 at entry) +0x30.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0x2cb4, `lw` at 0x2cd0.
  The `sw` at 0x2cf0 stores 4 bytes to ?.
  The `jal` at 0x2c88 calls external_router_port [0x2424] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x2cb8 calls router_print_error [0x2b84] with a0=a0 at entry (arg0), a1=?, a2=?, a3=0x1, a4=a1 at entry (arg1).
  The `jal` at 0x2cd4 calls router_print_error [0x2b84] with a0=a0 at entry (arg0), a1=?, a2=?, a3=0x4, a4=a1 at entry (arg1).
  The `beq` branch at 0x2ca0 targets 0x2cc4, is taken when v0(=ret(external_router_port)) == 0, and falls through when v0(=ret(external_router_port)) != 0.
  The return at 0x2cfc has v0 = ?.

- `router_check_errors` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x2d04 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x2d04-0x2d5c (88 bytes).
  It occupies 88 bytes.
  The `jal` at 0x2d28 calls router_check_port with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `bne` branch at 0x2d38 targets 0x2d24, is taken when s0(?) < 0x9 (signed), and falls through when s0(?) >= 0x9 (signed).
  The return at 0x2d54 has v0 = ?.

- `router_port_init` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x2d5c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x2d5c-0x2e10 (180 bytes).
  It occupies 180 bytes.
  The `jal` at 0x2d90 calls router_reg_read with a0=a0 at entry (arg0), a1=?, a2=sp-48, a3=a3 at entry (arg3).
  The `jal` at 0x2db8 calls router_reg_write with a0=a0 at entry (arg0), a1=?, a2=?, a3=0x140000.
  The `jal` at 0x2dcc calls router_reg_write with a0=a0 at entry (arg0), a1=?, a2=0x0, a3=?.
  The `jal` at 0x2ddc calls router_reg_write with a0=a0 at entry (arg0), a1=?, a2=0x0, a3=?.
  The `jal` at 0x2dec calls router_reg_read with a0=a0 at entry (arg0), a1=?, a2=sp-48, a3=?.
  The return at 0x2e08 has v0 = ret(router_reg_write).

- `router_port_hist_reselect` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x2e10 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x2e10-0x2f1c (268 bytes).
  It occupies 268 bytes.
  The `ld` at 0x2e10 loads 8 bytes from abs 0xffffffffffffc400.
  The `lh` at 0x2e14 loads 2 bytes from a0 (arg0 at entry) +0x2.
  The `ld` at 0x2e18 loads 8 bytes from [-0x3c00]:8 +0x0.
  The `ld` at 0x2e24 loads 8 bytes from ([[-0x3c00]:8]:8 + ([a0+2]:2 << 0x3)) +0x0.
  The `lh` at 0x2e38 loads 2 bytes from [([[-0x3c00]:8]:8 + ([a0+2]:2 << 0x3))]:8 +0x8596.
  The `jal` at 0x2e5c calls setnoderun with a0=[a0+2]:2, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a5=[a0+2]:2.
  The `jal` at 0x2ea0 calls router_reg_read with a0=a0 at entry (arg0), a1=?, a2=sp-64, a3=?.
  The `jal` at 0x2ecc calls router_reg_write with a0=a0 at entry (arg0), a1=?, a2=?, a3=(a2 << 0x12).
  The `jal` at 0x2ee0 calls router_reg_write with a0=a0 at entry (arg0), a1=?, a2=0x0, a3=?.
  The `jal` at 0x2ef0 calls router_reg_write with a0=a0 at entry (arg0), a1=?, a2=0x0, a3=?.
  The `jal` at 0x2f00 calls restorenoderun with a0=?, a1=?, a2=?, a3=?.
  The `beq` branch at 0x2e50 targets 0x2f10, is taken when at(=[[([[-0x3c00]:8]:8 + ([a0+2]:2 << 0x3))]:8+34198]:2) == v1(=-0x1), and falls through when at(=[[([[-0x3c00]:8]:8 + ([a0+2]:2 << 0x3))]:8+34198]:2) != v1(=-0x1).
  The return at 0x2f14 has v0 = one of 0x16, ?.

- `router_hist_reselect` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x2f1c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x2f1c-0x2fcc (176 bytes).
  It occupies 176 bytes.
  The `lbu` at 0x2f28 loads 1 byte from a0 (arg0 at entry) +0x228.
  The `sb` at 0x2f74 stores 1 byte to a0 (arg0 at entry) +0x228.
  The `ld` at 0x2fac loads 8 bytes from a0 (arg0 at entry) +0x250.
  The `lh` at 0x2fb8 loads 2 bytes from a0 (arg0 at entry) +0x2.
  The `jal` at 0x2f54 calls router_port_hist_reselect with a0=a0 at entry (arg0), a1=?, a2=a1 at entry (arg1), a3=?.
  The `jal` at 0x2f98 calls net_errmsg with a0=ret(router_port_hist_reselect), a1=?, a2=?, a3=?.
  The `jal` at 0x2fbc calls cmn_err with a0=0x4, a1=sym(.rodata)+616, a2=[a0+2]:2, a3=[a0+592]:8, a5=ret(router_port_hist_reselect), a6=ret(net_errmsg).
  The `beq` branch at 0x2f44 targets 0x2f7c, is taken when a1 == at(=[a0+552]:1), and falls through when a1 != at(=[a0+552]:1).
  The `bne` branch at 0x2f5c targets 0x2f98, is taken when v0(=ret(router_port_hist_reselect)) != 0, and falls through when v0(=ret(router_port_hist_reselect)) == 0.
  The `bne` branch at 0x2f6c targets 0x2f50, is taken when s0(?) < 0x9 (signed), and falls through when s0(?) >= 0x9 (signed).
  The `beq` branch at 0x2fc4 targets 0x2f68 and is always taken.
  The return at 0x2f90 has v0 = 0x0.

- `router_set_fences` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x2fcc (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x2fcc-0x3104 (312 bytes).
  It occupies 312 bytes.
  2 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x8, including `lbu` at 0x3034, `lbu` at 0x3088.
  The `sd` at 0x30d0 stores 8 bytes to a0 (arg0 at entry) +0x218.
  The `jal` at 0x2ff0 calls router_reg_read with a0=a0 at entry (arg0), a1=0x10, a2=sp-80, a3=a3 at entry (arg3).
  The `jal` at 0x3068 calls router_reg_read with a0=a0 at entry (arg0), a1=?, a2=sp-72, a3=?.
  The `jal` at 0x30b8 calls router_reg_write with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x30d8 calls router_reg_write with a0=a0 at entry (arg0), a1=0x10, a2=?, a3=?.
  The `beq` branch at 0x3008 targets 0x3030 and is always taken.
  The `beq` branch at 0x3028 targets 0x30c8, is taken when s4(?) >= 0x9 (signed), and falls through when s4(?) < 0x9 (signed).
  The `beq` branch at 0x3040 targets 0x3010, is taken when (v1(=[a0+8]:1) & a0(?)) == 0, and falls through when (v1(=[a0+8]:1) & a0(?)) != 0.
  The `beq` branch at 0x3078 targets 0x3088 and is always taken.
  The `beq` branch at 0x3080 targets 0x30b4, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `bne` branch at 0x3098 targets 0x3080, is taken when (t8(=[a0+8]:1) & t9(?)) != 0, and falls through when (t8(=[a0+8]:1) & t9(?)) == 0.
  The `beq` branch at 0x30ac targets 0x3080 and is always taken.
  The `beq` branch at 0x30c0 targets 0x3020 and is always taken.
  The return at 0x30fc has v0 = ret(router_reg_write).

- `capture_router_stats` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x3104 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x3104-0x31c8 (196 bytes).
  It occupies 196 bytes.
  The `lbu` at 0x311c loads 1 byte from a0 (arg0 at entry) +0x239.
  The `sb` at 0x3130 stores 1 byte to a0 (arg0 at entry) +0x239.
  2 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x238, including `lbu` at 0x3134, `lbu` at 0x31c4.
  2 such `ld` accesses load 8 bytes from abs 0x9200000001030100, including `ld` at 0x3150, `ld` at 0x3170.
  2 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x238, including `sb` at 0x3154, `sb` at 0x3184.
  The `sd` at 0x315c stores 8 bytes to a0 (arg0 at entry) +0x230.
  The `ld` at 0x3168 loads 8 bytes from a0 (arg0 at entry) +0x230.
  The `jal` at 0x3114 calls router_acquire_info with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x3140 calls router_check_errors [0x2d04] with a0=a0 at entry (arg0), a1=?, a2=?, a3=[a0+569]:1, a4=0x9200000001030100.
  The `beq` branch at 0x3128 targets 0x31b8, is taken when a3(=[a0+569]:1) == 0, and falls through when a3(=[a0+569]:1) != 0.
  The `beq` branch at 0x3138 targets 0x3168, is taken when at(=[a0+568]:1) == 0, and falls through when at(=[a0+568]:1) != 0.
  The `beq` branch at 0x3148 targets 0x3188, is taken when v0(=ret(router_check_errors)) == 0, and falls through when v0(=ret(router_check_errors)) != 0.
  The `bne` branch at 0x3158 targets 0x3190, is taken when s1(=ret(router_acquire_info)) != 0, and falls through when s1(=ret(router_acquire_info)) == 0.
  The `beq` branch at 0x3160 targets 0x31a0 and is always taken.
  The `beq` branch at 0x317c targets 0x3188, is taken when v1(=[sym(router_print_usecs)]) >= a0(?) (unsigned), and falls through when v1(=[sym(router_print_usecs)]) < a0(?) (unsigned).
  The `beq` branch at 0x3188 targets 0x3160, is taken when s1(=ret(router_acquire_info)) == 0, and falls through when s1(=ret(router_acquire_info)) != 0.
  The `bne` branch at 0x31b8 targets 0x3130, is taken when v0(=ret(router_acquire_info)) != 0, and falls through when v0(=ret(router_acquire_info)) == 0.
  The `beq` branch at 0x31c0 targets 0x3138 and is always taken.
  The return at 0x31b0 has v0 = one of [sym(router_poll_ticks)], ?.

- `router_get_info` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x3890 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x3890-0x3914 (132 bytes).
  It occupies 132 bytes.
  The `jal` at 0x38bc calls hwgraph_info_get_LBL with a0=a0 at entry (arg0), a1=sym(.rodata)+616, a2=sp-48, a3=a3 at entry (arg3).
  The `jal` at 0x38c8 calls mutex_spinlock with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x38ec calls bcopy with a0=?, a1=a1 at entry (arg1), a2=?, a3=?, a4=0x2c0.
  The `jal` at 0x38fc calls mutex_spinunlock with a0=?, a1=?, a2=?, a3=?.
  The `bne` branch at 0x38a4 targets 0x38b4, is taken when a0 != at(=-0x1), and falls through when a0 == at(=-0x1).
  The `beq` branch at 0x38ac targets 0x390c and is always taken.
  The return at 0x390c has v0 = one of 0x0, 0x13.

- `timeout_poll` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x3914 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x3914-0x399c (136 bytes).
  It occupies 136 bytes.
  The `ld` at 0x3968 loads 8 bytes from (a1 + (a0 << 0x21)) -0x6dfffffffe800000.
  The `jal` at 0x3960 calls us_delay with a0=(a4 << 0x0), a1=?, a2=?, a3=?.
  The `blez` branch at 0x393c targets 0x397c, is taken when a3 <= 0 (signed), and falls through when a3 > 0 (signed).
  The `beq` branch at 0x3950 targets 0x3960 and is always taken.
  The `beq` branch at 0x3958 targets 0x397c, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x3974 targets 0x3958, is taken when (s1(=a2) & t8(=[(a1 + (a0 << 0x21))-7926335344146907136]:8)) == 0, and falls through when (s1(=a2) & t8(=[(a1 + (a0 << 0x21))-7926335344146907136]:8)) != 0.
  The return at 0x3994 has v0 = one of ?, ret(us_delay).

- `router_state_empty` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x399c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x399c-0x3ae4 (328 bytes).
  It occupies 328 bytes.
  2 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x8, including `lbu` at 0x39f8, `lbu` at 0x3a48.
  The `jal` at 0x39d0 calls router_reg_read with a0=a0 at entry (arg0), a1=0x0, a2=sp-80, a3=a3 at entry (arg3).
  The `jal` at 0x3a90 calls router_reg_read with a0=a0 at entry (arg0), a1=?, a2=sp-80, a3=?.
  The `beq` branch at 0x3a1c targets 0x3a28, is taken when (v0(=[a0+8]:1) & at(?)) == 0, and falls through when (v0(=[a0+8]:1) & at(?)) != 0.
  The `bne` branch at 0x3a28 targets 0x3a04, is taken when a6(?) != 0, and falls through when a6(?) == 0.
  The `beq` branch at 0x3a44 targets 0x3a5c and is always taken.
  The `beq` branch at 0x3a54 targets 0x3ab8, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0x3a68 targets 0x3a4c, is taken when (v0(=[a0+8]:1) & t8(?)) == 0, and falls through when (v0(=[a0+8]:1) & t8(?)) != 0.
  The `bne` branch at 0x3ab0 targets 0x3a44, is taken when s3(?) < 0x9 (signed), and falls through when s3(?) >= 0x9 (signed).
  The return at 0x3adc has v0 = one of 0x0, 0x1.

- `router_print_state_specific` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x3ae4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x3ae4-0x3cdc (504 bytes).
  It occupies 504 bytes.
  The `lbu` at 0x3b20 loads 1 byte from a0 (arg0 at entry) +0x238.
  The `sb` at 0x3b64 stores 1 byte to a0 (arg0 at entry) +0x238.
  The `ld` at 0x3b70 loads 8 bytes from abs 0xffffffffffffc400.
  2 such `lh` accesses load 2 bytes from a0 (arg0 at entry) +0x2, including `lh` at 0x3b74, `lh` at 0x3bb8.
  The `ld` at 0x3b78 loads 8 bytes from [-0x3c00]:8 +0x0.
  The `ld` at 0x3b84 loads 8 bytes from ([[-0x3c00]:8]:8 + ([a0+2]:2 << 0x3)) +0x0.
  The `lbu` at 0x3b90 loads 1 byte from [([[-0x3c00]:8]:8 + ([a0+2]:2 << 0x3))]:8 +0x8594.
  The `lh` at 0x3be0 loads 2 bytes from (sym(compact_to_nasid_node) + ([a0+2]:2 + [a0+2]:2)) +0x0.
  The `sb` at 0x3be4 stores 1 byte to [([[-0x3c00]:8]:8 + ([a0+2]:2 << 0x3))]:8 +0x8594.
  The `lh` at 0x3c10 loads 2 bytes from a0 (arg0 at entry) +0x1f8.
  2 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x8, including `lbu` at 0x3c2c, `lbu` at 0x3c4c.
  The `jal` at 0x3b18 calls mutex_spinlock with a0=a0+572, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x3b34 calls mutex_spinunlock with a0=a0+572, a1=ret(mutex_spinlock), a2=[a0+568]:1, a3=?.
  The `jal` at 0x3b68 calls mutex_spinunlock with a0=a0+572, a1=ret(mutex_spinlock), a2=[a0+568]:1, a3=?.
  The `jalr` at 0x3ba0 calls (unknown callee) with a0=a1 at entry (arg1), a1=sym(.rodata)+616, a2=[a0+2]:2, a3=?.
  The `jal` at 0x3bac calls max with a0=0x100, a1=0x100, a2=?, a3=?.
  The `jal` at 0x3bdc calls timeout_poll with a0=[(sym(compact_to_nasid_node) + ([a0+2]:2 + [a0+2]:2))]:2, a1=0x60c020, a2=0x8000000000000000, a3=ret(max), a4=0x1, a5=([a0+2]:2 + [a0+2]:2).
  The `jal` at 0x3bec calls router_state_empty [0x399c] with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jalr` at 0x3bfc calls (unknown callee) with a0=a1 at entry (arg1), a1=sym(.rodata)+616, a2=?, a3=?.
  The `jalr` at 0x3c0c calls (unknown callee) with a0=a1 at entry (arg1), a1=sym(.rodata)+616, a2=[a0+504]:2, a3=?.
  The `jal` at 0x3c1c calls router_reg_read with a0=a0 at entry (arg0), a1=0x0, a2=sp-64, a3=?.
  The `jal` at 0x3c30 calls show_rr_status_rev_id with a0=?, a1=[a0+8]:1, a2=a1 at entry (arg1), a3=a2 at entry (arg2).
  The `jal` at 0x3c90 calls router_reg_read with a0=a0 at entry (arg0), a1=?, a2=sp-64, a3=?.
  The `jal` at 0x3cb4 calls show_rr_error_status with a0=?, a1=?, a2=a1 at entry (arg1), a3=a2 at entry (arg2), a4=0x0.
  The `beq` branch at 0x3b28 targets 0x3b60, is taken when (s3(=a3) & a2(=[a0+568]:1)) == 0, and falls through when (s3(=a3) & a2(=[a0+568]:1)) != 0.
  The `beq` branch at 0x3b94 targets 0x3be8, is taken when a0(=[[([[-0x3c00]:8]:8 + ([a0+2]:2 << 0x3))]:8+34196]:1) == 0, and falls through when a0(=[[([[-0x3c00]:8]:8 + ([a0+2]:2 << 0x3))]:8+34196]:1) != 0.
  The `bne` branch at 0x3bf4 targets 0x3b3c, is taken when v0(=ret(router_state_empty)) != 0, and falls through when v0(=ret(router_state_empty)) == 0.
  The `beq` branch at 0x3c48 targets 0x3c60 and is always taken.
  The `beq` branch at 0x3c58 targets 0x3b3c, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x3c6c targets 0x3c50, is taken when (a1(=[a0+8]:1) & a6(?)) == 0, and falls through when (a1(=[a0+8]:1) & a6(?)) != 0.
  The `bne` branch at 0x3ccc targets 0x3c48, is taken when s4(?) < 0x9 (signed), and falls through when s4(?) >= 0x9 (signed).
  The `beq` branch at 0x3cd4 targets 0x3b40 and is always taken.
  The return at 0x3b58 has v0 = one of ?, ret(show_rr_error_status).

- `router_print_state` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x3cdc (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x3cdc-0x3db0 (212 bytes).
  It occupies 212 bytes.
  The `ld` at 0x3d08 loads 8 bytes from abs 0xffffffffffffc400.
  2 such `lh` accesses load 2 bytes from abs 0xffffffffffffc42a, including `lh` at 0x3d0c, `lh` at 0x3d48.
  The `ld` at 0x3d10 loads 8 bytes from [-0x3c00]:8 +0x0.
  The `ld` at 0x3d1c loads 8 bytes from ([[-0x3c00]:8]:8 + ([-0x3bd6]:2 << 0x3)) +0x0.
  The `ld` at 0x3d24 loads 8 bytes from [([[-0x3c00]:8]:8 + ([-0x3bd6]:2 << 0x3))]:8 +0x85e8.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0x3d34, `ld` at 0x3d78.
  2 such `sh` accesses store 2 bytes to ?, including `sh` at 0x3d4c, `sh` at 0x3d74.
  2 such `lh` accesses load 2 bytes from ?, including `lh` at 0x3d50, `lh` at 0x3d5c.
  The `sw` at 0x3d68 stores 4 bytes to ?.
  The `jal` at 0x3d70 calls router_print_state_specific with a0=?, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a5=sym(compact_to_nasid_node).
  The `jal` at 0x3da0 calls router_print_state_specific with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `bne` branch at 0x3d00 targets 0x3da0, is taken when a0 != 0, and falls through when a0 == 0.
  The `beq` branch at 0x3d28 targets 0x3d84, is taken when s0(=[[([[-0x3c00]:8]:8 + ([-0x3bd6]:2 << 0x3))]:8+34280]:8) == 0, and falls through when s0(=[[([[-0x3c00]:8]:8 + ([-0x3bd6]:2 << 0x3))]:8+34280]:8) != 0.
  The `beq` branch at 0x3d30 targets 0x3d40 and is always taken.
  The `beq` branch at 0x3d38 targets 0x3d84, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0x3d40 targets 0x3d38, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `bne` branch at 0x3d7c targets 0x3d30, is taken when s0(?) != 0, and falls through when s0(?) == 0.
  The `beq` branch at 0x3da8 targets 0x3d88 and is always taken.
  The return at 0x3d98 has v0 = one of ?, ret(router_print_state_specific).

- `nic_name_convert` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x4608 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x4608-0x47bc (436 bytes).
  It occupies 436 bytes.
  2 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x0, including `lbu` at 0x4614, `lbu` at 0x47b8.
  The `lbu` at 0x4630 loads 1 byte from a0 (arg0 at entry) +0x1.
  4 such `sb` accesses store 1 byte to ?, including `sb` at 0x465c, `sb` at 0x46b4, `sb` at 0x46c0.
  2 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x467c, `lbu` at 0x4684.
  The `ld` at 0x4748 loads 8 bytes from sym(.rodata) +0x5d8.
  The `sdl` at 0x474c stores 8 bytes to a1 (arg1 at entry) +0x0.
  The `sdr` at 0x4754 stores 8 bytes to a1 (arg1 at entry) +0x7.
  The `lbu` at 0x475c loads 1 byte from sym(.rodata) +0x5ee.
  The `lw` at 0x4760 loads 4 bytes from sym(.rodata) +0x5e8.
  The `lbu` at 0x4764 loads 1 byte from sym(.rodata) +0x5ed.
  The `lbu` at 0x4768 loads 1 byte from sym(.rodata) +0x5ec.
  2 such `swl` accesses store 4 bytes to a1 (arg1 at entry) +0x0, including `swl` at 0x476c, `swl` at 0x4794.
  2 such `swr` accesses store 4 bytes to a1 (arg1 at entry) +0x3, including `swr` at 0x4770, `swr` at 0x4798.
  The `sb` at 0x4774 stores 1 byte to a1 (arg1 at entry) +0x6.
  The `sb` at 0x4778 stores 1 byte to a1 (arg1 at entry) +0x5.
  2 such `sb` accesses store 1 byte to a1 (arg1 at entry) +0x4, including `sb` at 0x4780, `sb` at 0x47a0.
  The `lbu` at 0x478c loads 1 byte from sym(.rodata) +0x5f4.
  The `lw` at 0x4790 loads 4 bytes from sym(.rodata) +0x5f0.
  The `jal` at 0x463c calls strlen with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=sym(.rodata)+1440.
  The `jal` at 0x4664 calls strlen with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x46d0 calls strncmp with a0=a1 at entry (arg1), a1=sym(.rodata)+1440, a2=0x3, a3=?.
  The `jal` at 0x46ec calls strncmp with a0=a1 at entry (arg1), a1=sym(.rodata)+1440, a2=0x3, a3=sym(.rodata)+1440.
  The `jal` at 0x4708 calls strncmp with a0=a1 at entry (arg1), a1=sym(.rodata)+1440, a2=0x8, a3=sym(.rodata)+1440.
  The `jal` at 0x4720 calls strncmp with a0=a1 at entry (arg1), a1=sym(.rodata)+1440, a2=0x4, a3=?.
  The `beq` branch at 0x4628 targets 0x4748, is taken when at(=[a0]:1) == 0, and falls through when at(=[a0]:1) != 0.
  The `beq` branch at 0x4634 targets 0x4748, is taken when v0(=[a0+1]:1) == 0, and falls through when v0(=[a0+1]:1) != 0.
  The `beq` branch at 0x4648 targets 0x47a4, is taken when v0(=ret(strlen)) == 0, and falls through when v0(=ret(strlen)) != 0.
  The `beq` branch at 0x4654 targets 0x47ac and is always taken.
  The `beq` branch at 0x4674 targets 0x46b8, is taken when s0(?) >= v0(=ret(strlen)) (unsigned), and falls through when s0(?) < v0(=ret(strlen)) (unsigned).
  The `beq` branch at 0x4690 targets 0x46a8, is taken when (a3(?) & 0x4003) == 0, and falls through when (a3(?) & 0x4003) != 0.
  The `bne` branch at 0x4698 targets 0x465c, is taken when a3(?) != 0, and falls through when a3(?) == 0.
  The `beq` branch at 0x46a0 targets 0x465c and is always taken.
  The `beq` branch at 0x46a8 targets 0x4784, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0x46b0 targets 0x4660 and is always taken.
  The `beq` branch at 0x46d8 targets 0x475c, is taken when v0(=ret(strncmp)) == 0, and falls through when v0(=ret(strncmp)) != 0.
  The `beq` branch at 0x46f4 targets 0x475c, is taken when v0(=ret(strncmp)) == 0, and falls through when v0(=ret(strncmp)) != 0.
  The `beq` branch at 0x4710 targets 0x4758, is taken when v0(=ret(strncmp)) == 0, and falls through when v0(=ret(strncmp)) != 0.
  The `beq` branch at 0x4728 targets 0x478c, is taken when v0(=ret(strncmp)) == 0, and falls through when v0(=ret(strncmp)) != 0.
  The `beq` branch at 0x4750 targets 0x46c4 and is always taken.
  The `beq` branch at 0x477c targets 0x4730 and is always taken.
  The `beq` branch at 0x4784 targets 0x4660 and is always taken.
  The `beq` branch at 0x479c targets 0x4730 and is always taken.
  The `beq` branch at 0x47a4 targets 0x46bc and is always taken.
  The `beq` branch at 0x47b4 targets 0x4680 and is always taken.
  The return at 0x4740 has v0 = ret(strncmp).

- `xbow_port_io_enabled` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x4f04 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x4f04-0x4fe8 (228 bytes).
  It occupies 228 bytes.
  The `ld` at 0x4f18 loads 8 bytes from (a0 << 0x21) -0x6fffffffcc000000.
  The `ld` at 0x4f44 loads 8 bytes from ((a0 << 0x21)+0x9600000000000000 | 0x2000) +0x48.
  The `lw` at 0x4f50 loads 4 bytes from ?.
  The `lbu` at 0x4fa4 loads 1 byte from (ret(find_component) + (a1 << 0x3)) -0x6.
  The `jal` at 0x4f68 calls find_lboard with a0=?, a1=0x42, a2=?, a3=?.
  The `jal` at 0x4f8c calls find_component with a0=ret(find_lboard), a1=0x0, a2=0x4, a3=?.
  The `jal` at 0x4fd8 calls chk_for_pebrick with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a4=(a0 << 0x21)+0x9600000000000000, a5=((a0 << 0x21)+0x9600000000000000 | 0x2000), a6=0xffffffffff, a7=0x9600000000000000.
  The `beq` branch at 0x4f3c targets 0x4fd8, is taken when at(?) == v1(=0xc000), and falls through when at(?) != v1(=0xc000).
  The `beq` branch at 0x4f5c targets 0x4f68, is taken when t1(?) == 0, and falls through when t1(?) != 0.
  The `bne` branch at 0x4f70 targets 0x4f88, is taken when v0(=ret(find_lboard)) != 0, and falls through when v0(=ret(find_lboard)) == 0.
  The `beq` branch at 0x4f98 targets 0x4fc8, is taken when v0(=ret(find_component)) == 0, and falls through when v0(=ret(find_component)) != 0.
  The `beq` branch at 0x4fb0 targets 0x4fd0, is taken when (a1(=[(ret(find_component) + (a1 << 0x3))-6]:1) & 0x1) == 0, and falls through when (a1(=[(ret(find_component) + (a1 << 0x3))-6]:1) & 0x1) != 0.
  The `beq` branch at 0x4fb8 targets 0x4fd0, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x4fc0 targets 0x4f80 and is always taken.
  The `beq` branch at 0x4fc8 targets 0x4f7c and is always taken.
  The `beq` branch at 0x4fd0 targets 0x4f7c and is always taken.
  The `beq` branch at 0x4fe0 targets 0x4f68 and is always taken.
  The return at 0x4f80 has v0 = one of 0x0, 0x1.

- `hub_vector_read` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x7240 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x7240-0x7330 (240 bytes).
  It occupies 240 bytes.
  The `ld` at 0x7260 loads 8 bytes from abs 0xffffffffffffc400.
  The `ld` at 0x7270 loads 8 bytes from [-0x3c00]:8 +0x0.
  The `lh` at 0x7278 loads 2 bytes from (sym(compact_to_nasid_node) + (a0 + a0)) +0x0.
  The `ld` at 0x7290 loads 8 bytes from ([[-0x3c00]:8]:8 + (a0 << 0x3)) +0x0.
  The `lh` at 0x729c loads 2 bytes from abs 0xffffffffffffc42a.
  2 such `sb` accesses store 1 byte to [([[-0x3c00]:8]:8 + (a0 << 0x3))]:8 +0x8594, including `sb` at 0x72f8, `sb` at 0x7304.
  The `jal` at 0x728c calls in_panic_mode with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x72a8 calls in_panic_mode with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x72f4 calls vector_read_node with a0=a1 at entry (arg1), a1=[(sym(compact_to_nasid_node) + (a0 + a0))]:2, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x730c calls mutex_spinunlock with a0=[([[-0x3c00]:8]:8 + (a0 << 0x3))]:8+34192, a1=?, a2=?, a3=?.
  The `jal` at 0x7320 calls mutex_spinlock with a0=[([[-0x3c00]:8]:8 + (a0 << 0x3))]:8+34192, a1=?, a2=?, a3=?.
  The `beq` branch at 0x7294 targets 0x731c, is taken when v0(=ret(in_panic_mode)) == 0, and falls through when v0(=ret(in_panic_mode)) != 0.
  The `beq` branch at 0x72a0 targets 0x72d4, is taken when t8(=[-0x3bd6]:2) == s3(=a0), and falls through when t8(=[-0x3bd6]:2) != s3(=a0).
  The `beq` branch at 0x72b0 targets 0x7308, is taken when v0(=ret(in_panic_mode)) == 0, and falls through when v0(=ret(in_panic_mode)) != 0.
  The `beq` branch at 0x7300 targets 0x72a8 and is always taken.
  The `beq` branch at 0x7314 targets 0x72bc and is always taken.
  The `beq` branch at 0x7328 targets 0x729c and is always taken.
  The return at 0x72cc has v0 = ?.

- `hub_vector_write` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x7330 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x7330-0x7420 (240 bytes).
  It occupies 240 bytes.
  The `ld` at 0x7350 loads 8 bytes from abs 0xffffffffffffc400.
  The `ld` at 0x7360 loads 8 bytes from [-0x3c00]:8 +0x0.
  The `lh` at 0x7368 loads 2 bytes from (sym(compact_to_nasid_node) + (a0 + a0)) +0x0.
  The `ld` at 0x7380 loads 8 bytes from ([[-0x3c00]:8]:8 + (a0 << 0x3)) +0x0.
  The `lh` at 0x738c loads 2 bytes from abs 0xffffffffffffc42a.
  2 such `sb` accesses store 1 byte to [([[-0x3c00]:8]:8 + (a0 << 0x3))]:8 +0x8594, including `sb` at 0x73e4, `sb` at 0x73f0.
  The `jal` at 0x737c calls in_panic_mode with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x7398 calls in_panic_mode with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x73e0 calls vector_write_node with a0=a1 at entry (arg1), a1=[(sym(compact_to_nasid_node) + (a0 + a0))]:2, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x73fc calls mutex_spinunlock with a0=[([[-0x3c00]:8]:8 + (a0 << 0x3))]:8+34192, a1=?, a2=?, a3=?.
  The `jal` at 0x7410 calls mutex_spinlock with a0=[([[-0x3c00]:8]:8 + (a0 << 0x3))]:8+34192, a1=?, a2=?, a3=?.
  The `beq` branch at 0x7384 targets 0x740c, is taken when v0(=ret(in_panic_mode)) == 0, and falls through when v0(=ret(in_panic_mode)) != 0.
  The `beq` branch at 0x7390 targets 0x73c0, is taken when t8(=[-0x3bd6]:2) == s3(=a0), and falls through when t8(=[-0x3bd6]:2) != s3(=a0).
  The `beq` branch at 0x73a0 targets 0x73f4, is taken when v0(=ret(in_panic_mode)) == 0, and falls through when v0(=ret(in_panic_mode)) != 0.
  The `beq` branch at 0x73ec targets 0x7398 and is always taken.
  The `beq` branch at 0x7404 targets 0x73a8 and is always taken.
  The `beq` branch at 0x7418 targets 0x738c and is always taken.
  The return at 0x73b8 has v0 = ?.

- `ust_init` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0xa5f0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0xa5f0-0xa654 (100 bytes).
  It occupies 100 bytes.
  2 such `ld` accesses load 8 bytes from abs 0x9200000001604200, including `ld` at 0xa5f4, `ld` at 0xa624.
  The return at 0xa64c has v0 = ?.

- `xbwidget_to_xtslot` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0xb0ac (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0xb0ac-0xb134 (136 bytes).
  It occupies 136 bytes.
  3 such `lbu` accesses load 1 byte from (sym(.data)+352 + (a1 << 0x2)) -0x1d, including `lbu` at 0xb10c, `lbu` at 0xb11c, `lbu` at 0xb130.
  The `bne` branch at 0xb0c0 targets 0xb0f4, is taken when a1 < 0x8 (signed), and falls through when a1 >= 0x8 (signed).
  The `beq` branch at 0xb0c8 targets 0xb0f4, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0xb0d0 targets 0xb110, is taken when a2 == a5(=0x49), and falls through when a2 != a5(=0x49).
  The `beq` branch at 0xb0d8 targets 0xb120, is taken when a2 == a6(=0x50), and falls through when a2 != a6(=0x50).
  The `beq` branch at 0xb0e0 targets 0xb0fc, is taken when a2 == a7(=0x58), and falls through when a2 != a7(=0x58).
  The return at 0xb0ec has v0 = 0xf0.
  The return at 0xb0f4 has v0 = 0xf0.
  The return at 0xb108 has v0 = [(sym(.data)+352 + (a1 << 0x2))-29]:1.
  The return at 0xb118 has v0 = [(sym(.data)+352 + (a1 << 0x2))-29]:1.
  The return at 0xb12c has v0 = [(sym(.data)+352 + (a1 << 0x2))-29]:1.

- `xswitch_volunteer_delete` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0xb284 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0xb284-0xb2b0 (44 bytes).
  It occupies 44 bytes.
  The `jal` at 0xb290 calls hwgraph_info_remove_LBL with a0=a0 at entry (arg0), a1=sym(.rodata)+4936, a2=sp-16, a3=a3 at entry (arg3).
  The `jal` at 0xb29c calls kmem_free with a0=?, a1=0x20, a2=?, a3=?.
  The return at 0xb2a8 has v0 = ret(kmem_free).

- `early_probe_for_widget` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0xb91c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0xb91c-0xb9b0 (148 bytes).
  It occupies 148 bytes.
  The `lh` at 0xb940 loads 2 bytes from ?.
  The `ld` at 0xb950 loads 8 bytes from table(0x9200000001c00128) +0x0.
  The `lw` at 0xb96c loads 4 bytes from table(0x9200000000000004) +0x0.
  2 such `sw` accesses store 4 bytes to a1 (arg1 at entry) +0x4, including `sw` at 0xb974, `sw` at 0xb9a4.
  2 such `sw` accesses store 4 bytes to a1 (arg1 at entry) +0x8, including `sw` at 0xb984, `sw` at 0xb9a0.
  2 such `sw` accesses store 4 bytes to a1 (arg1 at entry) +0x0, including `sw` at 0xb98c, `sw` at 0xb9ac.
  The `jal` at 0xb934 calls hwgraph_info_get_LBL with a0=a0 at entry (arg0), a1=sym(.rodata)+4936, a2=sp-32, a3=a3 at entry (arg3).
  The `beq` branch at 0xb964 targets 0xb99c, is taken when (a3(=entry(0x9200000001c00128)) & 0x2000) == 0, and falls through when (a3(=entry(0x9200000001c00128)) & 0x2000) != 0.
  The `beq` branch at 0xb9a8 targets 0xb990 and is always taken.
  The return at 0xb994 has v0 = ret(hwgraph_info_get_LBL).

- `xwidget_inventory_add` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0xb9b0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0xb9b0-0xb9f0 (64 bytes).
  It occupies 64 bytes.
  The `lbu` at 0xb9cc loads 1 byte from a1 (arg1 at entry) +0x5.
  The `lbu` at 0xb9d0 loads 1 byte from a1 (arg1 at entry) +0xa.
  The `lh` at 0xb9d8 loads 2 bytes from a1 (arg1 at entry) +0xe.
  The `jal` at 0xb9e0 calls device_inventory_add with a0=a0 at entry (arg0), a1=0xb, a2=[a1+5]:1, a3=[a1+14]:2, a7=a1 at entry (arg1).
  The `bne` branch at 0xb9bc targets 0xb9cc, is taken when a1 != 0, and falls through when a1 == 0.
  The `beq` branch at 0xb9e8 targets 0xb9c4 and is always taken.
  The return at 0xb9c4 has v0 = one of ?, ret(device_inventory_add).

- `do_io_init_node` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0xc4ac (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0xc4ac-0xc7b4 (776 bytes).
  It occupies 776 bytes.
  2 such `ld` accesses load 8 bytes from abs 0xffffffffffffc400, including `ld` at 0xc4ac, `ld` at 0xc6a8.
  2 such `ld` accesses load 8 bytes from [-0x3c00]:8 +0x0, including `ld` at 0xc4b4, `ld` at 0xc6b4.
  The `ld` at 0xc4c8 loads 8 bytes from ((a0 << 0x3) + [[-0x3c00]:8]:8) +0x0.
  The `lw` at 0xc4dc loads 4 bytes from [((a0 << 0x3) + [[-0x3c00]:8]:8)]:8 +0x8c80.
  The `ld` at 0xc4f4 loads 8 bytes from [((a0 << 0x3) + [[-0x3c00]:8]:8)]:8 +0x85e8.
  4 such `ld` accesses load 8 bytes from ?, including `ld` at 0xc514, `ld` at 0xc520, `ld` at 0xc52c.
  2 such `lh` accesses load 2 bytes from (sym(compact_to_nasid_node) + (a0 + a0)) +0x0, including `lh` at 0xc554, `lh` at 0xc598.
  The `lw` at 0xc5a8 loads 4 bytes from ([(sym(compact_to_nasid_node) + (a0 + a0))]:2 << 0x21) -0x6dffffff1ffffffc.
  3 such `sb` accesses store 1 byte to [((a0 << 0x3) + [[-0x3c00]:8]:8)]:8 +0x863c, including `sb` at 0xc5ec, `sb` at 0xc778, `sb` at 0xc7a8.
  The `sw` at 0xc614 stores 4 bytes to [((a0 << 0x3) + [[-0x3c00]:8]:8)]:8 +0x8640.
  2 such `lbu` accesses load 1 byte from [((a0 << 0x3) + [[-0x3c00]:8]:8)]:8 +0x863c, including `lbu` at 0xc668, `lbu` at 0xc7b0.
  The `lbu` at 0xc67c loads 1 byte from ?.
  The `lh` at 0xc690 loads 2 bytes from [((a0 << 0x3) + [[-0x3c00]:8]:8)]:8 +0x8600.
  The `lh` at 0xc6b0 loads 2 bytes from (sym(nasid_to_compact_node) + ([[((a0 << 0x3) + [[-0x3c00]:8]:8)]:8+34304]:2 + [[((a0 << 0x3) + [[-0x3c00]:8]:8)]:8+34304]:2)) +0x0.
  The `lw` at 0xc6dc loads 4 bytes from table(0x8c80) +0x0.
  2 such `lw` accesses load 4 bytes from ([(sym(compact_to_nasid_node) + (a0 + a0))]:2 << 0x21) -0x6dffffff1fffffdc, including `lw` at 0xc768, `lw` at 0xc78c.
  The `jal` at 0xc4ec calls hubdev_docallouts with a0=[[((a0 << 0x3) + [[-0x3c00]:8]:8)]:8+35968], a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xc50c calls router_init with a0=a0 at entry (arg0), a1=0x0, a2=?, a3=?.
  The `jal` at 0xc550 calls eeprom_vertex_info_set with a0=0x100, a1=[(sym(compact_to_nasid_node) + (a0 + a0))]:2, a2=[[((a0 << 0x3) + [[-0x3c00]:8]:8)]:8+35968], a3=0x0, a4=0x0.
  The `jal` at 0xc55c calls early_probe_for_widget [0xb91c] with a0=[[((a0 << 0x3) + [[-0x3c00]:8]:8)]:8+35968], a1=sp-112, a2=?, a3=?.
  The `jal` at 0xc57c calls hwgraph_path_add with a0=[[((a0 << 0x3) + [[-0x3c00]:8]:8)]:8+35968], a1=sym(.rodata)+4936, a2=sp-96, a3=?.
  The `jal` at 0xc590 calls hwgraph_edge_add with a0=[[((a0 << 0x3) + [[-0x3c00]:8]:8)]:8+35968], a1=?, a2=sym(.rodata)+4936, a3=?.
  The `jal` at 0xc5f8 calls sprintf with a0=sp-88, a1=sym(.rodata)+4936, a2=?, a3=?.
  The `jal` at 0xc608 calls hwgraph_path_add with a0=?, a1=sp-88, a2=sp-72, a3=?.
  The `jal` at 0xc640 calls device_master_set with a0=?, a1=[[((a0 << 0x3) + [[-0x3c00]:8]:8)]:8+35968], a2=?, a3=?.
  The `jal` at 0xc658 calls hwgraph_info_get_LBL with a0=[[((a0 << 0x3) + [[-0x3c00]:8]:8)]:8+35968], a1=sym(.rodata)+4936, a2=sp-64, a3=?.
  The `jal` at 0xc678 calls xwidget_register with a0=sp-112, a1=?, a2=[[((a0 << 0x3) + [[-0x3c00]:8]:8)]:8+34364]:1, a3=[[((a0 << 0x3) + [[-0x3c00]:8]:8)]:8+35968], a5=0x0.
  The `jal` at 0xc688 calls volunteer_for_widgets [0xb2b0] with a0=?, a1=[[((a0 << 0x3) + [[-0x3c00]:8]:8)]:8+35968], a2=?, a3=?.
  The `jal` at 0xc6d8 calls volunteer_for_widgets [0xb2b0] with a0=?, a1=entry(0x8c80), a2=[[((a0 << 0x3) + [[-0x3c00]:8]:8)]:8+34304]:2, a3=?, a5=-0x1.
  The `jal` at 0xc6f4 calls psema with a0=table(0x8608), a1=0x19, a2=0x8608, a3=?.
  The `jal` at 0xc700 calls io_init_xswitch_widgets [0xc184] with a0=?, a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0xc70c calls io_link_xswitch_widgets [0xc22c] with a0=?, a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0xc748 calls assign_widgets_to_volunteers [0xb3d8] with a0=?, a1=[[((a0 << 0x3) + [[-0x3c00]:8]:8)]:8+35968], a2=?, a3=?.
  The `jal` at 0xc758 calls vsema with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xc7a4 calls cmn_err with a0=0x0, a1=sym(.rodata)+4936, a2=?, a3=?, a4=[[((a0 << 0x3) + [[-0x3c00]:8]:8)]:8+35968], a6=([(sym(compact_to_nasid_node) + (a0 + a0))]:2 << 0x21)+0x92000000e0000000, a7=0xd002.
  The `bne` branch at 0xc4f8 targets 0xc520, is taken when s0(=[[((a0 << 0x3) + [[-0x3c00]:8]:8)]:8+34280]:8) != 0, and falls through when s0(=[[((a0 << 0x3) + [[-0x3c00]:8]:8)]:8+34280]:8) == 0.
  The `beq` branch at 0xc500 targets 0xc538 and is always taken.
  The `beq` branch at 0xc518 targets 0xc538, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0xc524 targets 0xc508, is taken when ra(?) == 0, and falls through when ra(?) != 0.
  The `bne` branch at 0xc530 targets 0xc520, is taken when s0(?) != 0, and falls through when s0(?) == 0.
  The `beq` branch at 0xc56c targets 0xc714, is taken when t9(?) == ra(=-0x1), and falls through when t9(?) != ra(=-0x1).
  The `beq` branch at 0xc5bc targets 0xc768, is taken when a2(?) == a3(=0xc002), and falls through when a2(?) != a3(=0xc002).
  The `beq` branch at 0xc5c8 targets 0xc768, is taken when a2(?) == a7(=0xd002), and falls through when a2(?) != a7(=0xd002).
  The `beq` branch at 0xc5d0 targets 0xc5e8, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0xc5d8 targets 0xc5e8, is taken when a2(?) == a0(=0xd000), and falls through when a2(?) != a0(=0xd000).
  The `bne` branch at 0xc5e0 targets 0xc78c, is taken when a2(?) != a1(=0xd100), and falls through when a2(?) == a1(=0xd100).
  The `beq` branch at 0xc61c targets 0xc77c, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0xc628 targets 0xc734, is taken when a0(?) == a3(=0xd000), and falls through when a0(?) != a3(=0xd000).
  The `beq` branch at 0xc634 targets 0xc730, is taken when a0(?) == a4(=0xd100), and falls through when a0(?) != a4(=0xd100).
  The `bne` branch at 0xc648 targets 0xc6e8, is taken when v0(=ret(device_master_set)) != 0, and falls through when v0(=ret(device_master_set)) == 0.
  The `beq` branch at 0xc680 targets 0xc714, is taken when s0(=one of 0x0, 0x1) == 0, and falls through when s0(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0xc698 targets 0xc744, is taken when a2(=[[((a0 << 0x3) + [[-0x3c00]:8]:8)]:8+34304]:2) == a5(=-0x1), and falls through when a2(=[[((a0 << 0x3) + [[-0x3c00]:8]:8)]:8+34304]:2) != a5(=-0x1).
  The `beq` branch at 0xc6e0 targets 0xc748 and is always taken.
  The `bne` branch at 0xc734 targets 0xc63c, is taken when a3(?) != 0, and falls through when a3(?) == 0.
  The `beq` branch at 0xc73c targets 0xc63c and is always taken.
  The `beq` branch at 0xc750 targets 0xc700, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0xc760 targets 0xc700 and is always taken.
  The `beq` branch at 0xc774 targets 0xc5f0 and is always taken.
  The `bne` branch at 0xc77c targets 0xc628, is taken when a1(?) != 0, and falls through when a1(?) == 0.
  The `beq` branch at 0xc784 targets 0xc73c and is always taken.
  The `beq` branch at 0xc7ac targets 0xc5f0 and is always taken.
  The return at 0xc728 has v0 = one of ret(early_probe_for_widget), ret(xwidget_register), ret(io_link_xswitch_widgets).

- `init_all_devices` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0xd2c0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0xd2c0-0xd498 (472 bytes).
  It occupies 472 bytes.
  The `jal` at 0xd2e0 calls init_sema with a0=sym(.bss)+1792, a1=0x0, a2=sym(.rodata)+4936, a3=-0x1.
  The `jal` at 0xd2e8 calls init_hub_provider with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xd338 calls sprintf with a0=sp-80, a1=sym(.rodata)+4936, a2=?, a3=?.
  The `jal` at 0xd368 calls sthread_create with a0=sp-80, a1=0x0, a2=0x4000, a3=0x0, a4=[sym(io_init_pri)], a5=0x1000, a6=sym(io_init_node).
  The `jal` at 0xd390 calls psema with a0=sym(.bss)+1792, a1=0x19, a2=?, a3=?.
  The `jal` at 0xd3b0 calls psema with a0=sym(.bss)+1792, a1=0x19, a2=?, a3=?.
  The `jal` at 0xd3d8 calls update_node_information with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xd3fc calls baseio_ctlr_num_set [0xcdec] with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xd404 calls sys_critical_graph_init [0xcbc0] with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xd40c calls kopt_find with a0=sym(.rodata)+4936, a1=?, a2=?, a3=?.
  The `jal` at 0xd414 calls atoi with a0=ret(kopt_find), a1=?, a2=?, a3=?.
  The `jal` at 0xd424 calls hwgraph_fastinfo_get with a0=[sym(.sdata)+96], a1=?, a2=?, a3=?.
  The `jal` at 0xd43c calls hwgraph_info_get_LBL with a0=[sym(.sdata)+96], a1=sym(.rodata)+4936, a2=sp-64, a3=?.
  The `jal` at 0xd450 calls ef_ifattach with a0=ret(hwgraph_fastinfo_get), a1=0x0, a2=?, a3=?.
  The `jalr` at 0xd488 calls (unknown callee) with a0=ret(hwgraph_fastinfo_get), a1=0x0, a2=?, a3=?.
  The `blez` branch at 0xd304 targets 0xd478, is taken when v0(=[sym(maxnodes)]) <= 0 (signed), and falls through when v0(=[sym(maxnodes)]) > 0 (signed).
  The `beq` branch at 0xd310 targets 0xd330 and is always taken.
  The `beq` branch at 0xd32c targets 0xd3a8, is taken when s0(?) >= v0(=[sym(maxnodes)]) (signed), and falls through when s0(?) < v0(=[sym(maxnodes)]) (signed).
  The `beq` branch at 0xd37c targets 0xd318, is taken when v0(=[sym(io_init_node_threads)]) == 0, and falls through when v0(=[sym(io_init_node_threads)]) != 0.
  The `bne` branch at 0xd388 targets 0xd318, is taken when s1(?) < v0(=[sym(io_init_node_threads)]) (signed), and falls through when s1(?) >= v0(=[sym(io_init_node_threads)]) (signed).
  The `beq` branch at 0xd3a0 targets 0xd318 and is always taken.
  The `blez` branch at 0xd3a8 targets 0xd3d0, is taken when s1(?) <= 0 (signed), and falls through when s1(?) > 0 (signed).
  The `bgtz` branch at 0xd3c4 targets 0xd3b0, is taken when s1(?) > 0 (signed), and falls through when s1(?) <= 0 (signed).
  The `blez` branch at 0xd3d0 targets 0xd3fc, is taken when v0(=[sym(maxnodes)]) <= 0 (signed), and falls through when v0(=[sym(maxnodes)]) > 0 (signed).
  The `bne` branch at 0xd3f4 targets 0xd3d8, is taken when s0(?) < t8(=[sym(maxnodes)]) (signed), and falls through when s0(?) >= t8(=[sym(maxnodes)]) (signed).
  The `beq` branch at 0xd41c targets 0xd458, is taken when v0(=ret(atoi)) == 0, and falls through when v0(=ret(atoi)) != 0.
  The `beq` branch at 0xd42c targets 0xd458, is taken when v0(=ret(hwgraph_fastinfo_get)) == 0, and falls through when v0(=ret(hwgraph_fastinfo_get)) != 0.
  The `beq` branch at 0xd444 targets 0xd484, is taken when v0(=ret(hwgraph_info_get_LBL)) == 0, and falls through when v0(=ret(hwgraph_info_get_LBL)) != 0.
  The `beq` branch at 0xd47c targets 0xd3d0 and is always taken.
  The `beq` branch at 0xd490 targets 0xd45c and is always taken.
  The return at 0xd470 has v0 = one of ?, ret(?).

- `mlreset` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0xd7cc
  Role (from name): the machine-level reset path for the IP35 kernel. The facts list the calls by address, and they are not one path. It calls `r1nkperf_control_register_set` and `r1nkperf_data_register_set` with selectors 0 and 1 at 0xd7e0 to 0xd804, then `get_cpu_irr`. Two more pairs with selectors 2 and 3 (0xd864 to 0xd888) are reached when the branch at 0xd81c or 0xd834 is taken. When s3 (a copy of a0) is nonzero at 0xd83c, it calls `flush_tlb` and `flush_cache` and returns the `flush_cache` result at 0xd858. When s3 is zero it continues at 0xd898 with `get_nasid`, `set_master_bridge_base`, `ioc3_mlreset`, `ioc4_mlreset`, `l1_mlreset`, `nvram_baseinit` and `cpu_node_probe`, and then `mem_init`, `hubdev_init` and `intrgroup_init` among others. Three `assfail` calls (0xdc04, 0xdc20, 0xdc3c) sit on checks along the way. What each callee does is not in the facts.
  Grade: inferred.
  Reviewed: 2026-11-12

- `getcpuid` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0xe718
  Role (from name): returns the caller's CPU id. It raises the interrupt level with `splhi`, maps the node from `get_nasid` and the slice doubleword at 0x9200000001000020 to a CPU info record through `nasid_slice_to_cpuinfo`, and restores the level with `splx`. It returns the halfword at +30 of that record, and a zero lookup result reaches `assfail` at 0xe77c. The meaning of the +30 field is not in the facts.
  Grade: inferred.
  Reviewed: 2026-11-12

- `memory_read_accessible` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0xf40c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0xf40c-0xf58c (384 bytes).
  It occupies 384 bytes.
  The `lh` at 0xf420 loads 2 bytes from abs 0xffffffffffffc42a.
  The `ld` at 0xf48c loads 8 bytes from table(0x9200000001f80008) +0x0.
  The `ld` at 0xf4c4 loads 8 bytes from table(0x9200000001f80000) +0x0.
  The `ld` at 0xf500 loads 8 bytes from table(0x9200000001fc0000) +0x0.
  The `ld` at 0xf538 loads 8 bytes from ?.
  The `jal` at 0xf434 calls get_region with a0=[-0x3bd6]:2, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xf440 calls memory_iscalias with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xf450 calls get_nasid with a0=?, a1=?, a2=?, a3=?, a4=0x9200000001f80000.
  The `beq` branch at 0xf448 targets 0xf478, is taken when v0(=ret(memory_iscalias)) == 0, and falls through when v0(=ret(memory_iscalias)) != 0.
  The `beq` branch at 0xf4bc targets 0xf4e0, is taken when (t8(=entry(0x9200000001f80008)) & t9(=0x100000000000)) == 0, and falls through when (t8(=entry(0x9200000001f80008)) & t9(=0x100000000000)) != 0.
  The `beq` branch at 0xf4cc targets 0xf4e4, is taken when (a5(=entry(0x9200000001f80000)) & a6(?)) == 0, and falls through when (a5(=entry(0x9200000001f80000)) & a6(?)) != 0.
  The `beq` branch at 0xf534 targets 0xf57c, is taken when 0 >= v1(?) (unsigned), and falls through when 0 < v1(?) (unsigned).
  The `beq` branch at 0xf53c targets 0xf54c, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0xf558 targets 0xf574, is taken when a0(?) == a4(=0xff), and falls through when a0(?) != a4(=0xff).
  The `beq` branch at 0xf564 targets 0xf574, is taken when a0(?) == a2(=0xf), and falls through when a0(?) != a2(=0xf).
  The `beq` branch at 0xf56c targets 0xf4d8 and is always taken.
  The `beq` branch at 0xf574 targets 0xf4d4 and is always taken.
  The `beq` branch at 0xf57c targets 0xf558, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0xf584 targets 0xf554 and is always taken.
  The return at 0xf4d8 has v0 = one of 0x0, 0x1.

- `memory_write_accessible` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0xf5e0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0xf5e0-0xf754 (372 bytes).
  It occupies 372 bytes.
  The `lh` at 0xf5f4 loads 2 bytes from abs 0xffffffffffffc42a.
  The `ld` at 0xf660 loads 8 bytes from table(0x9200000001f80008) +0x0.
  The `ld` at 0xf698 loads 8 bytes from table(0x9200000001f80000) +0x0.
  The `ld` at 0xf6d4 loads 8 bytes from table(0x9200000001fc0000) +0x0.
  The `ld` at 0xf708 loads 8 bytes from ?.
  The `jal` at 0xf608 calls get_region with a0=[-0x3bd6]:2, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xf614 calls memory_iscalias with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xf624 calls get_nasid with a0=?, a1=?, a2=?, a3=?, a4=0x9200000001f80000.
  The `beq` branch at 0xf61c targets 0xf64c, is taken when v0(=ret(memory_iscalias)) == 0, and falls through when v0(=ret(memory_iscalias)) != 0.
  The `beq` branch at 0xf690 targets 0xf6b4, is taken when (t8(=entry(0x9200000001f80008)) & t9(=0x100000000000)) == 0, and falls through when (t8(=entry(0x9200000001f80008)) & t9(=0x100000000000)) != 0.
  The `beq` branch at 0xf6a0 targets 0xf6b8, is taken when (a5(=entry(0x9200000001f80000)) & a6(?)) == 0, and falls through when (a5(=entry(0x9200000001f80000)) & a6(?)) != 0.
  The `beq` branch at 0xf704 targets 0xf744, is taken when 0 >= v1(?) (unsigned), and falls through when 0 < v1(?) (unsigned).
  The `beq` branch at 0xf70c targets 0xf71c, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0xf72c targets 0xf73c, is taken when a2(?) == a3(=0xff), and falls through when a2(?) != a3(=0xff).
  The `beq` branch at 0xf734 targets 0xf6a8 and is always taken.
  The `beq` branch at 0xf73c targets 0xf6ac and is always taken.
  The `beq` branch at 0xf744 targets 0xf728, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0xf74c targets 0xf724 and is always taken.
  The return at 0xf6ac has v0 = one of 0x0, 0x1.

- `set_dir_access` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0xf7a8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0xf7a8-0xf838 (144 bytes).
  It occupies 144 bytes.
  The `ld` at 0xf7dc loads 8 bytes from table(0x9200000001fc0000) +0x0.
  The `ld` at 0xf804 loads 8 bytes from ?.
  2 such `sd` accesses store 8 bytes to ?, including `sd` at 0xf810, `sd` at 0xf834.
  The `beq` branch at 0xf800 targets 0xf81c, is taken when (at(=entry(0x9200000001fc0000)) & 0x1) == 0, and falls through when (at(=entry(0x9200000001fc0000)) & 0x1) != 0.
  The return at 0xf814 has v0 = 0x9200000001fc0000.
  The return at 0xf830 has v0 = 0x9200000001fc0000.

- `memory_set_access` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0xf838 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0xf838-0xf990 (344 bytes).
  It occupies 344 bytes.
  The `ld` at 0xf89c loads 8 bytes from table(0x9200000001fc0000) +0x0.
  The `ld` at 0xf8d8 loads 8 bytes from ?.
  4 such `sd` accesses store 8 bytes to ?, including `sd` at 0xf900, `sd` at 0xf904, `sd` at 0xf908.
  The `jal` at 0xf90c calls get_nasid with a0=?, a1=a1 at entry (arg1), a2=?, a3=a3 at entry (arg3).
  The `jal` at 0xf928 calls set_dir_access with a0=?, a1=?, a2=?, a3=?.
  The `beq` branch at 0xf8d4 targets 0xf95c, is taken when 0 >= at(?) (unsigned), and falls through when 0 < at(?) (unsigned).
  The `beq` branch at 0xf8dc targets 0xf96c, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `beq` branch at 0xf8ec targets 0xf978, is taken when t0(?) == 0, and falls through when t0(?) != 0.
  The `bne` branch at 0xf914 targets 0xf940, is taken when v0(=ret(get_nasid)) != s0(?), and falls through when v0(=ret(get_nasid)) == s0(?).
  The `bne` branch at 0xf938 targets 0xf928, is taken when s0(?) < 0x1000 (signed), and falls through when s0(?) >= 0x1000 (signed).
  The `beq` branch at 0xf95c targets 0xf984, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `beq` branch at 0xf964 targets 0xf8f8 and is always taken.
  The `beq` branch at 0xf970 targets 0xf8ec and is always taken.
  The `beq` branch at 0xf97c targets 0xf8fc and is always taken.
  The `beq` branch at 0xf988 targets 0xf8fc and is always taken.
  The return at 0xf954 has v0 = one of ret(get_nasid), ret(set_dir_access).

- `set_dir_owner` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0xfefc (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0xfefc-0x10004 (264 bytes).
  It occupies 264 bytes.
  The `ld` at 0xff38 loads 8 bytes from table(0x9200000001fc0000) +0x0.
  The `ld` at 0xff60 loads 8 bytes from ?.
  2 such `sd` accesses store 8 bytes to ?, including `sd` at 0xff90, `sd` at 0xffc8.
  The `beq` branch at 0xff5c targets 0xff9c, is taken when (at(=entry(0x9200000001fc0000)) & 0x1) == 0, and falls through when (at(=entry(0x9200000001fc0000)) & 0x1) != 0.
  The `beq` branch at 0xff6c targets 0xffcc, is taken when a1 == t1(=-0x1), and falls through when a1 != t1(=-0x1).
  The `bne` branch at 0xff9c targets 0xffb8, is taken when a1 != t1(=-0x1), and falls through when a1 == t1(=-0x1).
  The `beq` branch at 0xfffc targets 0xff90 and is always taken.
  The return at 0xff94 has v0 = 0x9200000001fc0000.
  The return at 0xffc4 has v0 = 0x9200000001fc0000.

- `get_dir_ent` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x10004 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x10004-0x100c4 (192 bytes).
  It occupies 192 bytes.
  The `ld` at 0x1004c loads 8 bytes from ?.
  The `ld` at 0x1005c loads 8 bytes from table(0x9200000001fc0000) +0x0.
  The `sw` at 0x10078 stores 4 bytes to a1 (arg1 at entry) +0x0.
  The `sd` at 0x10080 stores 8 bytes to a3 (arg3 at entry) +0x0.
  2 such `sd` accesses store 8 bytes to a2 (arg2 at entry) +0x0, including `sd` at 0x10090, `sd` at 0x100ac.
  The `beq` branch at 0x1006c targets 0x100b8, is taken when t3(=0x1) == t8(?), and falls through when t3(=0x1) != t8(?).
  The `beq` branch at 0x10084 targets 0x10094, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `beq` branch at 0x10094 targets 0x100ac, is taken when t0(?) == 0, and falls through when t0(?) != 0.
  The `beq` branch at 0x100bc targets 0x10078 and is always taken.
  The return at 0x1008c has v0 = ?.
  The return at 0x100b0 has v0 = ?.

- `memory_iscalias` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x100c4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x100c4-0x10104 (64 bytes).
  It occupies 64 bytes.
  The `ld` at 0x100cc loads 8 bytes from abs 0x9200000001000028.
  The `beq` branch at 0x100dc targets 0x100f8, is taken when v0(=[0x9200000001000028]:8) == 0, and falls through when v0(=[0x9200000001000028]:8) != 0.
  The `bne` branch at 0x100f0 targets 0x100fc, is taken when v1(?) < a1(?) (unsigned), and falls through when v1(?) >= a1(?) (unsigned).
  The return at 0x100fc has v0 = one of 0x0, 0x1.

- `page_local_calias` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x10124 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x10124-0x10160 (60 bytes).
  It occupies 60 bytes.
  The `ld` at 0x10128 loads 8 bytes from abs 0x9200000001000028.
  The `beq` branch at 0x10138 targets 0x10154, is taken when v0(=[0x9200000001000028]:8) == 0, and falls through when v0(=[0x9200000001000028]:8) != 0.
  The `bne` branch at 0x1014c targets 0x10158, is taken when a3(?) < v1(?) (unsigned), and falls through when a3(?) >= v1(?) (unsigned).
  The return at 0x10158 has v0 = one of 0x0, 0x1.

- `fetchop_flush` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x10160 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x10160-0x10260 (256 bytes).
  It occupies 256 bytes.
  The `ld` at 0x101c8 loads 8 bytes from table(0x9200000001f80028) +0x0.
  The `ld` at 0x10244 loads 8 bytes from ?.
  The `ld` at 0x1025c loads 8 bytes from table(0x9200000001f80020) +0x0.
  The `beq` branch at 0x101c0 targets 0x10258, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0x101dc targets 0x10248, is taken when t8(?) == 0, and falls through when t8(?) != 0.
  The `bne` branch at 0x1020c targets 0x10248, is taken when t8(?) < a1(?) (unsigned), and falls through when t8(?) >= a1(?) (unsigned).
  The `beq` branch at 0x1021c targets 0x10248, is taken when at(?) >= v0(?) (unsigned), and falls through when at(?) < v0(?) (unsigned).
  The `bne` branch at 0x10248 targets 0x101c0, is taken when a3(?) != 0, and falls through when a3(?) == 0.
  The `beq` branch at 0x10258 targets 0x101cc and is always taken.
  The return at 0x10250 has v0 = 0x1.

- `router_map_init` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x115e4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x115e4-0x11798 (436 bytes).
  It occupies 436 bytes.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x8c68, including `sw` at 0x11610, `sw` at 0x11720.
  The `lh` at 0x11670 loads 2 bytes from ?.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0x1167c, `ld` at 0x11690.
  The `lw` at 0x1169c loads 4 bytes from ?.
  2 such `lbu` accesses load 1 byte from ret(find_lboard_class) +0x9, including `lbu` at 0x116c8, `lbu` at 0x116e4.
  The `lw` at 0x11700 loads 4 bytes from ret(find_lboard_class) +0x0.
  The `lw` at 0x11714 loads 4 bytes from a0 (arg0 at entry) +0x8c68.
  The `lh` at 0x11728 loads 2 bytes from ret(find_lboard_class) +0xe.
  The `sh` at 0x11730 stores 2 bytes to (a0 + ([a0+35944]+1 << 0x4)) +0x8860.
  The `lbu` at 0x11734 loads 1 byte from ret(find_lboard_class) +0xa.
  The `sb` at 0x11738 stores 1 byte to (a0 + ([a0+35944]+1 << 0x4)) +0x8862.
  The `ld` at 0x1173c loads 8 bytes from ret(find_lboard_class) +0x18.
  The `sd` at 0x11744 stores 8 bytes to (a0 + ([a0+35944]+1 << 0x4)) +0x8858.
  The `lh` at 0x11794 loads 2 bytes from sym(compact_to_nasid_node) +0x0.
  The `jal` at 0x116b4 calls find_lboard_class with a0=?, a1=0x31, a2=?, a3=?.
  The `jal` at 0x116d4 calls find_lboard_class with a0=?, a1=0x31, a2=?, a3=ret(find_lboard_class).
  The `jal` at 0x11748 calls chk_for_pebrick with a0=?, a1=?, a2=?, a3=?.
  The `blez` branch at 0x1162c targets 0x11758, is taken when at(=[sym(maxnodes)]) <= 0 (signed), and falls through when at(=[sym(maxnodes)]) > 0 (signed).
  The `beq` branch at 0x11648 targets 0x11788 and is always taken.
  The `beq` branch at 0x11668 targets 0x11758, is taken when s2(?) >= t8(=[sym(maxnodes)]) (signed), and falls through when s2(?) < t8(=[sym(maxnodes)]) (signed).
  The `beq` branch at 0x11688 targets 0x11748, is taken when s3(=0xc000) == t8(?), and falls through when s3(=0xc000) != t8(?).
  The `beq` branch at 0x116a8 targets 0x116b4, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `beq` branch at 0x116bc targets 0x11650, is taken when v0(=ret(find_lboard_class)) == 0, and falls through when v0(=ret(find_lboard_class)) != 0.
  The `beq` branch at 0x116c4 targets 0x116e8 and is always taken.
  The `beq` branch at 0x116dc targets 0x11650, is taken when v0(=ret(find_lboard_class)) == 0, and falls through when v0(=ret(find_lboard_class)) != 0.
  The `beq` branch at 0x116f8 targets 0x11714, is taken when (a1(=[ret(find_lboard_class)+9]:1) & 0x4) == 0, and falls through when (a1(=[ret(find_lboard_class)+9]:1) & 0x4) != 0.
  The `bne` branch at 0x11704 targets 0x116cc, is taken when a4(=[ret(find_lboard_class)]) != 0, and falls through when a4(=[ret(find_lboard_class)]) == 0.
  The `beq` branch at 0x1170c targets 0x116d4 and is always taken.
  The `beq` branch at 0x11740 targets 0x11700 and is always taken.
  The `beq` branch at 0x11750 targets 0x116b4 and is always taken.
  The `beq` branch at 0x11790 targets 0x11674 and is always taken.
  The return at 0x11780 has v0 = one of ?, ret(find_lboard_class).

- `router_map_get` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x11798 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x11798-0x11804 (108 bytes).
  It occupies 108 bytes.
  The `ld` at 0x11798 loads 8 bytes from abs 0xffffffffffffc400.
  The `lw` at 0x117a4 loads 4 bytes from [-0x3c00]:8 +0x8c68.
  2 such `sh` accesses store 2 bytes to a1 (arg1 at entry) +0x0, including `sh` at 0x117b4, `sh` at 0x117f0.
  2 such `sb` accesses store 1 byte to a2 (arg2 at entry) +0x0, including `sb` at 0x117c0, `sb` at 0x117f8.
  The `ld` at 0x117cc loads 8 bytes from ?.
  The `lh` at 0x117ec loads 2 bytes from ?.
  The `lbu` at 0x117f4 loads 1 byte from ?.
  The `blez` branch at 0x117bc targets 0x117fc, is taken when a6(=[[-0x3c00]:8+35944]) <= 0 (signed), and falls through when a6(=[[-0x3c00]:8+35944]) > 0 (signed).
  The `beq` branch at 0x117d4 targets 0x117ec, is taken when t1(?) == a0, and falls through when t1(?) != a0.
  The `bne` branch at 0x117dc targets 0x117c8, is taken when a5(?) != 0, and falls through when a5(?) == 0.
  The `beq` branch at 0x117e4 targets 0x117fc and is always taken.
  The return at 0x117fc has v0 = ?.

- `net_link_up` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x11984 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x11984-0x11998 (20 bytes).
  It occupies 20 bytes.
  The `ld` at 0x11988 loads 8 bytes from abs 0x9200000001680000.
  The return at 0x11990 has v0 = ?.

- `router_queue_init` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x11998 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x11998-0x11a34 (156 bytes).
  It occupies 156 bytes.
  The `sd` at 0x119cc stores 8 bytes to a0 (arg0 at entry) +0x8858.
  The `sd` at 0x119e8 stores 8 bytes to a0 (arg0 at entry) +0x8860.
  The `jal` at 0x119b4 calls kmem_zalloc_node with a0=0xa08, a1=0x1, a2=a1 at entry (arg1), a3=a3 at entry (arg3).
  The `jal` at 0x119dc calls kmem_zalloc_node with a0=0xa08, a1=0x1, a2=a1 at entry (arg1), a3=?.
  The `jal` at 0x11a08 calls assfail with a0=sym(.rodata)+7152, a1=sym(.rodata)+7152, a2=0x2ac, a3=?.
  The `jal` at 0x11a24 calls assfail with a0=sym(.rodata)+7152, a1=sym(.rodata)+7152, a2=0x2b0, a3=?.
  The `beq` branch at 0x119c8 targets 0x119fc, is taken when v0(=ret(kmem_zalloc_node)) == 0, and falls through when v0(=ret(kmem_zalloc_node)) != 0.
  The `beq` branch at 0x119e4 targets 0x11a18, is taken when v0(=ret(kmem_zalloc_node)) == 0, and falls through when v0(=ret(kmem_zalloc_node)) != 0.
  The `beq` branch at 0x11a10 targets 0x119d4 and is always taken.
  The `beq` branch at 0x11a2c targets 0x119f0 and is always taken.
  The return at 0x119f4 has v0 = one of ret(kmem_zalloc_node), ret(assfail).

- `router_link_get` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x11b14 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x11b14-0x11ba0 (140 bytes).
  It occupies 140 bytes.
  The `jal` at 0x11b50 calls sprintf with a0=sp-64, a1=sym(.rodata)+7152, a2=?, a3=?.
  The `jal` at 0x11b60 calls hwgraph_traverse with a0=a0 at entry (arg0), a1=sp-64, a2=sp-48, a3=?.
  The `beq` branch at 0x11b30 targets 0x11b44 and is always taken.
  The `beq` branch at 0x11b40 targets 0x11b80, is taken when s0(?) >= 0x9 (signed), and falls through when s0(?) < 0x9 (signed).
  The `bne` branch at 0x11b68 targets 0x11b38, is taken when v0(=ret(hwgraph_traverse)) != 0, and falls through when v0(=ret(hwgraph_traverse)) == 0.
  The `bne` branch at 0x11b70 targets 0x11b38, is taken when a2(?) != s2(=a1), and falls through when a2(?) == s2(=a1).
  The `beq` branch at 0x11b78 targets 0x11b88 and is always taken.
  The return at 0x11b98 has v0 = one of ?, 0x0.

- `router_guardian_search` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x11ba0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x11ba0-0x11ec4 (804 bytes).
  It occupies 804 bytes.
  The `lw` at 0x11d54 loads 4 bytes from ?.
  The `ld` at 0x11da0 loads 8 bytes from abs 0xffffffffffffc400.
  The `ld` at 0x11da4 loads 8 bytes from [-0x3c00]:8 +0x0.
  The `ld` at 0x11dac loads 8 bytes from ?.
  3 such `lw` accesses load 4 bytes from table(0x85f8) +0x0, including `lw` at 0x11db8, `lw` at 0x11dcc, `lw` at 0x11dd4.
  The `ld` at 0x11e54 loads 8 bytes from ret(queue_find) +0x8.
  The `sd` at 0x11e74 stores 8 bytes to ret(queue_find) +0x8.
  2 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x0, including `sd` at 0x11e8c, `sd` at 0x11ec0.
  The `jal` at 0x11bfc calls kmem_alloc with a0=0xa08, a1=0x0, a2=0x4, a3=0x3, a4=0x2.
  The `jal` at 0x11c0c calls queue_init [0x10e14] with a0=ret(kmem_alloc), a1=0x2, a2=?, a3=?.
  The `jal` at 0x11c1c calls kmem_alloc with a0=0xa08, a1=0x0, a2=?, a3=?.
  The `jal` at 0x11c30 calls queue_init [0x10e14] with a0=ret(kmem_alloc), a1=0x2, a2=?, a3=?.
  The `jal` at 0x11c4c calls queue_push [0x10e5c] with a0=ret(kmem_alloc), a1=sp-240, a2=?, a3=?.
  The `jal` at 0x11c54 calls queue_empty [0x10e48] with a0=ret(kmem_alloc), a1=?, a2=?, a3=?.
  The `jal` at 0x11c94 calls kmem_free with a0=ret(kmem_alloc), a1=0xa08, a2=?, a3=?.
  The `jal` at 0x11ca4 calls kmem_free with a0=ret(kmem_alloc), a1=0xa08, a2=?, a3=?.
  The `jal` at 0x11ce4 calls queue_push [0x10e5c] with a0=ret(kmem_alloc), a1=sp-240, a2=?, a3=?.
  The `jal` at 0x11cec calls queue_empty [0x10e48] with a0=ret(kmem_alloc), a1=?, a2=?, a3=?.
  The `jal` at 0x11cfc calls queue_pop [0x10f30] with a0=ret(kmem_alloc), a1=sp-240, a2=?, a3=?.
  The `jal` at 0x11d08 calls queue_find [0x10f94] with a0=ret(kmem_alloc), a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0x11d58 calls sprintf with a0=sp-184, a1=sym(.rodata)+7152, a2=?, a3=?.
  The `jal` at 0x11d68 calls hwgraph_traverse with a0=a1 at entry (arg1), a1=sp-184, a2=sp-168, a3=?.
  The `jal` at 0x11d78 calls nodevertex_to_cnodeid with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x11d90 calls cnodetocpu with a0=?, a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0x11de4 calls vector_length with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x11df0 calls vector_length with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x11e20 calls router_link_get with a0=?, a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0x11e30 calls vector_concat with a0=ret(router_link_get), a1=?, a2=?, a3=?.
  The `jal` at 0x11e40 calls queue_find [0x10f94] with a0=ret(kmem_alloc), a1=?, a2=?, a3=?.
  The `jal` at 0x11e50 calls vector_length with a0=[ret(queue_find)+8]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x11e5c calls vector_length with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x11e78 calls vector_length with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x11e9c calls queue_push [0x10e5c] with a0=ret(kmem_alloc), a1=sp-160, a2=?, a3=?.
  The `beq` branch at 0x11c6c targets 0x11cc4, is taken when v0(=ret(queue_empty)) == 0, and falls through when v0(=ret(queue_empty)) != 0.
  The `beq` branch at 0x11cdc targets 0x11cf8 and is always taken.
  The `bne` branch at 0x11cf4 targets 0x11eac, is taken when v0(=ret(queue_empty)) != 0, and falls through when v0(=ret(queue_empty)) == 0.
  The `bne` branch at 0x11d10 targets 0x11cec, is taken when v0(=ret(queue_find)) != 0, and falls through when v0(=ret(queue_find)) == 0.
  The `beq` branch at 0x11d18 targets 0x11d48 and is always taken.
  The `beq` branch at 0x11d3c targets 0x11ce4, is taken when s0(?) >= 0x8 (signed), and falls through when s0(?) < 0x8 (signed).
  The `bne` branch at 0x11d70 targets 0x11d34, is taken when v0(=ret(hwgraph_traverse)) != 0, and falls through when v0(=ret(hwgraph_traverse)) == 0.
  The `beq` branch at 0x11d80 targets 0x11e18, is taken when v0(=ret(nodevertex_to_cnodeid)) == s5(=-0x1), and falls through when v0(=ret(nodevertex_to_cnodeid)) != s5(=-0x1).
  The `beq` branch at 0x11d98 targets 0x11d34, is taken when v0(=ret(cnodetocpu)) == s5(=-0x1), and falls through when v0(=ret(cnodetocpu)) != s5(=-0x1).
  The `beq` branch at 0x11dbc targets 0x11e78, is taken when t8(=entry(0x85f8)) == 0, and falls through when t8(=entry(0x85f8)) != 0.
  The `beq` branch at 0x11dc4 targets 0x11d20, is taken when s3(?) == 0, and falls through when s3(?) != 0.
  The `bne` branch at 0x11ddc targets 0x11d34, is taken when t8(=entry(0x85f8)) < t9(=entry(0x85f8)) (signed), and falls through when t8(=entry(0x85f8)) >= t9(=entry(0x85f8)) (signed).
  The `bne` branch at 0x11dfc targets 0x11d34, is taken when v0(=ret(vector_length)) < s6(=ret(vector_length)) (signed), and falls through when v0(=ret(vector_length)) >= s6(=ret(vector_length)) (signed).
  The `beq` branch at 0x11e10 targets 0x11d34 and is always taken.
  The `beq` branch at 0x11e28 targets 0x11d34, is taken when v0(=ret(router_link_get)) == 0, and falls through when v0(=ret(router_link_get)) != 0.
  The `beq` branch at 0x11e48 targets 0x11e98, is taken when v0(=ret(queue_find)) == 0, and falls through when v0(=ret(queue_find)) != 0.
  The `beq` branch at 0x11e68 targets 0x11d34, is taken when v0(=ret(vector_length)) >= s7(=ret(vector_length)) (signed), and falls through when v0(=ret(vector_length)) < s7(=ret(vector_length)) (signed).
  The `beq` branch at 0x11e70 targets 0x11d34 and is always taken.
  The `bne` branch at 0x11e80 targets 0x11dc4, is taken when v0(=ret(vector_length)) != 0, and falls through when v0(=ret(vector_length)) == 0.
  The `beq` branch at 0x11e90 targets 0x11c78 and is always taken.
  The `beq` branch at 0x11ea4 targets 0x11d38 and is always taken.
  The `beq` branch at 0x11eac targets 0x11c74, is taken when s3(?) == 0, and falls through when s3(?) != 0.
  The `beq` branch at 0x11ebc targets 0x11c78 and is always taken.
  The return at 0x11cbc has v0 = ?.

- `router_guardian_set` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x11f98 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x11f98-0x12068 (208 bytes).
  It occupies 208 bytes.
  The `lbu` at 0x11fa0 loads 1 byte from a1 (arg1 at entry) +0x9.
  The `lbu` at 0x11ffc loads 1 byte from a1 (arg1 at entry) +0x17.
  The `jal` at 0x11fc0 calls board_to_path with a0=a1 at entry (arg1), a1=sp-88, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x11fdc calls board_to_path with a0=a1 at entry (arg1), a1=sp-88, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x11fec calls hwgraph_traverse with a0=a0 at entry (arg0), a1=sp-88, a2=sp-32, a3=?.
  The `jal` at 0x12010 calls router_guardian_search [0x11ba0] with a0=sp-96, a1=?, a2=[a1+23]:1, a3=?.
  The `jal` at 0x1202c calls guardian_nodepda_update [0x11ec4] with a0=ret(router_guardian_search), a1=?, a2=a1 at entry (arg1), a3=?.
  The `jal` at 0x12044 calls cmn_err with a0=0x4, a1=sym(.rodata)+7152, a2=sp-88, a3=?.
  The `jal` at 0x12058 calls cmn_err with a0=0x0, a1=sym(.rodata)+7152, a2=[a1+23]:1, a3=?.
  The `beq` branch at 0x11fb4 targets 0x11fd8, is taken when (at(=[a1+9]:1) & 0x4) == 0, and falls through when (at(=[a1+9]:1) & 0x4) != 0.
  The `bne` branch at 0x11ff4 targets 0x1203c, is taken when v0(=ret(hwgraph_traverse)) != 0, and falls through when v0(=ret(hwgraph_traverse)) == 0.
  The `bne` branch at 0x12004 targets 0x12054, is taken when a2(=[a1+23]:1) != v0(=0x1), and falls through when a2(=[a1+23]:1) == v0(=0x1).
  The `beq` branch at 0x1201c targets 0x11fc8, is taken when v0(=ret(router_guardian_search)) == v1(=-0x1), and falls through when v0(=ret(router_guardian_search)) != v1(=-0x1).
  The `beq` branch at 0x12034 targets 0x11fcc and is always taken.
  The `beq` branch at 0x1204c targets 0x11fcc and is always taken.
  The `beq` branch at 0x12060 targets 0x11fcc and is always taken.
  The return at 0x11fd0 has v0 = one of ?, ret(guardian_nodepda_update), ret(cmn_err).

- `router_guardians_set` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x12068 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x12068-0x121d0 (360 bytes).
  It occupies 360 bytes.
  The `lh` at 0x120e0 loads 2 bytes from ?.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0x120ec, `ld` at 0x12100.
  The `lw` at 0x1210c loads 4 bytes from ?.
  The `lw` at 0x12160 loads 4 bytes from ret(find_lboard_class) +0x0.
  The `lh` at 0x121cc loads 2 bytes from sym(compact_to_nasid_node) +0x0.
  The `jal` at 0x12124 calls find_lboard_class with a0=?, a1=0x31, a2=?, a3=?.
  The `jal` at 0x12144 calls find_lboard_class with a0=?, a1=0x31, a2=?, a3=?.
  The `jal` at 0x12158 calls router_guardian_set [0x11f98] with a0=a0 at entry (arg0), a1=ret(find_lboard_class), a2=?, a3=?.
  The `jal` at 0x12184 calls chk_for_pebrick with a0=?, a1=?, a2=?, a3=?.
  The `blez` branch at 0x120ac targets 0x12194, is taken when at(=[sym(maxnodes)]) <= 0 (signed), and falls through when at(=[sym(maxnodes)]) > 0 (signed).
  The `beq` branch at 0x120b8 targets 0x121c0 and is always taken.
  The `beq` branch at 0x120d8 targets 0x12194, is taken when s4(?) >= v0(=[sym(maxnodes)]) (signed), and falls through when s4(?) < v0(=[sym(maxnodes)]) (signed).
  The `beq` branch at 0x120f8 targets 0x12184, is taken when s6(=0xc000) == t8(?), and falls through when s6(=0xc000) != t8(?).
  The `beq` branch at 0x12118 targets 0x12124, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `beq` branch at 0x1212c targets 0x120c0, is taken when v0(=ret(find_lboard_class)) == 0, and falls through when v0(=ret(find_lboard_class)) != 0.
  The `beq` branch at 0x12134 targets 0x12158 and is always taken.
  The `beq` branch at 0x1214c targets 0x120c0, is taken when v0(=ret(find_lboard_class)) == 0, and falls through when v0(=ret(find_lboard_class)) != 0.
  The `bne` branch at 0x12174 targets 0x1213c, is taken when a1(=[ret(find_lboard_class)]) != 0, and falls through when a1(=[ret(find_lboard_class)]) == 0.
  The `beq` branch at 0x1217c targets 0x12144 and is always taken.
  The `beq` branch at 0x1218c targets 0x12124 and is always taken.
  The `beq` branch at 0x121c8 targets 0x120e4 and is always taken.
  The return at 0x121b8 has v0 = ?.

- `router_lock` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x121d0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x121d0-0x123b8 (488 bytes).
  It occupies 488 bytes.
  The `ld` at 0x121fc loads 8 bytes from abs 0xffffffffffffc7c8.
  The `ld` at 0x1221c loads 8 bytes from (sym(pdaindr) + (ret(getcpuid) << 0x4)) +0x8.
  The `ld` at 0x12220 loads 8 bytes from [(sym(pdaindr) + (ret(getcpuid) << 0x4))+8]:8 +0x7c8.
  The `ld` at 0x1227c loads 8 bytes from ?.
  The `sd` at 0x12280 stores 8 bytes to ?.
  2 such `ld` accesses load 8 bytes from abs 0x9200000001030100, including `ld` at 0x122a0, `ld` at 0x12328.
  2 such `ld` accesses load 8 bytes from abs 0x9200000001604200, including `ld` at 0x122a4, `ld` at 0x1232c.
  The `ld` at 0x123a8 loads 8 bytes from table(sym(pdaindr)) +0x8.
  The `sd` at 0x123b4 stores 8 bytes to [table(sym(pdaindr))+8]:8 +0x7c8.
  The `jal` at 0x121ec calls splhi with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x121f4 calls getcpuid with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x12230 calls splx with a0=ret(splhi), a1=?, a2=?, a3=?.
  The `jal` at 0x12260 calls vector_write with a0=a0 at entry (arg0), a1=0x0, a2=0x118, a3=0x0, a5=(ret(getcpuid) << 0x4).
  The `jal` at 0x12290 calls splx with a0=ret(splhi), a1=?, a2=?, a3=?.
  The `jal` at 0x122e4 calls splhi with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x122fc calls vector_read with a0=a0 at entry (arg0), a1=0x0, a2=0x518, a3=sp-80.
  The `jal` at 0x12378 calls splx with a0=ret(splhi), a1=?, a2=?, a3=?.
  The `jal` at 0x12380 calls us_delay with a0=a1 at entry (arg1), a1=?, a2=?, a3=?.
  The `beq` branch at 0x12208 targets 0x12390, is taken when a2(=0xf) == at(=[-0x3838]:8), and falls through when a2(=0xf) != at(=[-0x3838]:8).
  The `bne` branch at 0x12224 targets 0x12254, is taken when v0(=[[(sym(pdaindr) + (ret(getcpuid) << 0x4))+8]:8+1992]:8) != s1(=a0), and falls through when v0(=[[(sym(pdaindr) + (ret(getcpuid) << 0x4))+8]:8+1992]:8) == s1(=a0).
  The `bltz` branch at 0x12274 targets 0x12284, is taken when v0(=ret(vector_write)) < 0 (signed), and falls through when v0(=ret(vector_write)) >= 0 (signed).
  The `bne` branch at 0x12284 targets 0x12230, is taken when a5(?) != 0, and falls through when a5(?) == 0.
  The `bltz` branch at 0x12308 targets 0x12230, is taken when v0(=ret(vector_read)) < 0 (signed), and falls through when v0(=ret(vector_read)) >= 0 (signed).
  The `beq` branch at 0x12314 targets 0x12398, is taken when (a2(?) & 0x1) == 0, and falls through when (a2(?) & 0x1) != 0.
  The `bne` branch at 0x12368 targets 0x12378, is taken when a6(?) < a7(?) (unsigned), and falls through when a6(?) >= a7(?) (unsigned).
  The `beq` branch at 0x12370 targets 0x12230 and is always taken.
  The `beq` branch at 0x12388 targets 0x122e4 and is always taken.
  The `beq` branch at 0x12390 targets 0x1228c and is always taken.
  The `beq` branch at 0x123b0 targets 0x12230 and is always taken.
  The return at 0x1224c has v0 = ?.

- `router_unlock` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x123b8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x123b8-0x1242c (116 bytes).
  It occupies 116 bytes.
  The `ld` at 0x12404 loads 8 bytes from (sym(pdaindr) + (ret(getcpuid) << 0x4)) +0x8.
  The `sd` at 0x1240c stores 8 bytes to [(sym(pdaindr) + (ret(getcpuid) << 0x4))+8]:8 +0x7c8.
  The `jal` at 0x123c4 calls splhi with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x123dc calls vector_write with a0=a0 at entry (arg0), a1=0x0, a2=0x118, a3=0x0.
  The `jal` at 0x123f0 calls getcpuid with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x12410 calls splx with a0=ret(splhi), a1=?, a2=?, a3=?.
  The `bltz` branch at 0x123e8 targets 0x12410, is taken when v0(=ret(vector_write)) < 0 (signed), and falls through when v0(=ret(vector_write)) >= 0 (signed).
  The return at 0x12424 has v0 = ret(vector_write).

- `set_md_outgoing_rq_queue_size` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x1242c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x1242c-0x12578 (332 bytes).
  It occupies 332 bytes.
  The `lh` at 0x12458 loads 2 bytes from (sym(compact_to_nasid_node) + (a0 + a0)) +0x0.
  The `ld` at 0x1247c loads 8 bytes from ([(sym(compact_to_nasid_node) + (a0 + a0))]:2 << 0x21) -0x6dfffffffe03ffb0.
  The `sd` at 0x124c4 stores 8 bytes to ([(sym(compact_to_nasid_node) + (a0 + a0))]:2 << 0x21) -0x6dfffffffe03ffb0.
  The `ld` at 0x1252c loads 8 bytes from table(sym(pdaindr)) +0x8.
  The `lw` at 0x12530 loads 4 bytes from [table(sym(pdaindr))+8]:8 +0x748.
  The `jal` at 0x12500 calls cnode_slice_to_cpuid with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x1255c calls cmn_err with a0=0x4, a1=sym(.rodata)+7152, a2=[sym(md_rq_depth)], a3=a3 at entry (arg3).
  The `beq` branch at 0x12454 targets 0x124c8, is taken when a2(=[sym(md_rq_depth)]) == at(=0x5), and falls through when a2(=[sym(md_rq_depth)]) != at(=0x5).
  The `beq` branch at 0x1245c targets 0x12558, is taken when a1(=[sym(.sdata)+164]) == 0, and falls through when a1(=[sym(.sdata)+164]) != 0.
  The `bne` branch at 0x124d4 targets 0x12550, is taken when a1(=[sym(maxcpus)]) < 0x81 (signed), and falls through when a1(=[sym(maxcpus)]) >= 0x81 (signed).
  The `bne` branch at 0x124e0 targets 0x124f0, is taken when a1(=[sym(maxcpus)]) < 0x201 (signed), and falls through when a1(=[sym(maxcpus)]) >= 0x201 (signed).
  The `beq` branch at 0x124e8 targets 0x12464 and is always taken.
  The `beq` branch at 0x124f0 targets 0x124fc and is always taken.
  The `beq` branch at 0x124f8 targets 0x12548, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x12524 targets 0x124f8, is taken when a3(?) == a6(=-0x1), and falls through when a3(?) != a6(=-0x1).
  The `bne` branch at 0x12538 targets 0x124f8, is taken when a4(=[[table(sym(pdaindr))+8]:8+1864]) < 0xfb (signed), and falls through when a4(=[[table(sym(pdaindr))+8]:8+1864]) >= 0xfb (signed).
  The `beq` branch at 0x12540 targets 0x12464 and is always taken.
  The `beq` branch at 0x12548 targets 0x12464 and is always taken.
  The `beq` branch at 0x12550 targets 0x12468 and is always taken.
  The `beq` branch at 0x12570 targets 0x12464 and is always taken.
  The return at 0x124c0 has v0 = one of ?, 0x400.

- `kl_perr_init` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x125c4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x125c4-0x125d0 (12 bytes).
  It occupies 12 bytes.
  The `sw` at 0x125cc stores 4 bytes to sym(.bss) +0x5088.
  The return at 0x125c8 has v0 = ?.

- `kl_perr` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x125d0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x125d0-0x127a0 (464 bytes).
  It occupies 464 bytes.
  The `sb` at 0x12660 stores 1 byte to table(sym(err_buf)) +0x4004.
  6 such `sb` accesses store 1 byte to ?, including `sb` at 0x12678, `sb` at 0x1268c, `sb` at 0x126a0.
  2 such `lw` accesses load 4 bytes from sym(.bss) +0x5088, including `lw` at 0x1271c, `lw` at 0x1275c.
  The `sw` at 0x12724 stores 4 bytes to sym(.bss) +0x5088.
  The `jal` at 0x12610 calls vsprintf with a0=sym(err_buf), a1=a1 at entry (arg1), a2=sp-48, a3=a3 at entry (arg3).
  The `jal` at 0x126ac calls strlen with a0=sym(err_buf), a1=-0x11, a2=?, a3=?, a5=0x20.
  The `jal` at 0x126e0 calls strncpy with a0=?, a1=sym(err_buf), a2=?, a3=?.
  The `jal` at 0x12714 calls bcopy with a0=?, a1=([sym(err_buf)] + sym(err_buf))+4, a2=?, a3=?, a4=[sym(err_buf)].
  The `jal` at 0x1274c calls strlen with a0=?, a1=?, a2=?, a3=?.
  The `beq` branch at 0x12634 targets 0x12640, is taken when (s3(=a0) & 0x10) == 0, and falls through when (s3(=a0) & 0x10) != 0.
  The `beq` branch at 0x12658 targets 0x126ac, is taken when s3(?) == 0, and falls through when s3(?) != 0.
  The `blez` branch at 0x12664 targets 0x126ac, is taken when s3(?) <= 0 (signed), and falls through when s3(?) > 0 (signed).
  The `beq` branch at 0x12680 targets 0x126ac, is taken when a2(?) >= a4(?) (signed), and falls through when a2(?) < a4(?) (signed).
  The `beq` branch at 0x12694 targets 0x126ac, is taken when a2(?) >= a4(?) (signed), and falls through when a2(?) < a4(?) (signed).
  The `bne` branch at 0x126a4 targets 0x12670, is taken when a2(?) < a4(?) (signed), and falls through when a2(?) >= a4(?) (signed).
  The `bne` branch at 0x126c8 targets 0x126d4, is taken when at(?) < 0x4104 (signed), and falls through when at(?) >= 0x4104 (signed).
  The `beq` branch at 0x126f0 targets 0x1277c, is taken when s5(?) == 0, and falls through when s5(?) != 0.
  The `bltz` branch at 0x126f8 targets 0x12780, is taken when s3(?) < 0 (signed), and falls through when s3(?) >= 0 (signed).
  The `beq` branch at 0x12700 targets 0x12744 and is always taken.
  The `bne` branch at 0x1273c targets 0x1277c, is taken when s3(?) < s0(?) (signed), and falls through when s3(?) >= s0(?) (signed).
  The `beq` branch at 0x12758 targets 0x12734, is taken when s2(=(ret(strlen) << 0x0)) == 0, and falls through when s2(=(ret(strlen) << 0x0)) != 0.
  The `bne` branch at 0x12768 targets 0x12708, is taken when t8(=((ret(strlen) << 0x0) + [sym(err_buf)])) < 0x4000 (signed), and falls through when t8(=((ret(strlen) << 0x0) + [sym(err_buf)])) >= 0x4000 (signed).
  The `beq` branch at 0x12774 targets 0x12708 and is always taken.
  The return at 0x12798 has v0 = ?.

- `kl_perr_dumpbuf` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x127a0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x127a0-0x12888 (232 bytes).
  It occupies 232 bytes.
  2 such `lbu` accesses load 1 byte from sym(.bss) +0x508c, including `lbu` at 0x127bc, `lbu` at 0x127dc.
  2 such `lw` accesses load 4 bytes from sym(.bss) +0x5088, including `lw` at 0x127e0, `lw` at 0x12830.
  3 such `lbu` accesses load 1 byte from sym(.bss) +0x5088, including `lbu` at 0x127f4, `lbu` at 0x12800, `lbu` at 0x1280c.
  2 such `sb` accesses store 1 byte to sym(.bss) +0x5088, including `sb` at 0x12818, `sb` at 0x1282c.
  The `sw` at 0x12878 stores 4 bytes to sym(.bss) +0x5088.
  The `jalr` at 0x1281c calls (unknown callee) with a0=a1 at entry (arg1), a1=sym(err_buf), a2=?, a3=?.
  The `jalr` at 0x12850 calls (unknown callee) with a0=sym(err_buf), a1=sym(err_buf), a2=?, a3=?.
  The `beq` branch at 0x127d8 targets 0x12860, is taken when at(=[sym(err_buf+4)]:1) == 0, and falls through when at(=[sym(err_buf+4)]:1) != 0.
  The `bgtz` branch at 0x127e4 targets 0x12848, is taken when v0(=[sym(err_buf)]) > 0 (signed), and falls through when v0(=[sym(err_buf)]) <= 0 (signed).
  The `beq` branch at 0x127ec targets 0x12864 and is always taken.
  The `beq` branch at 0x127f8 targets 0x12814, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `bne` branch at 0x12804 targets 0x127f4, is taken when s1(=0xa) != v1(=[sym(err_buf)]:1), and falls through when s1(=0xa) == v1(=[sym(err_buf)]:1).
  The `beq` branch at 0x12814 targets 0x12850, is taken when s2(=a1) == 0, and falls through when s2(=a1) != 0.
  The `beq` branch at 0x12828 targets 0x12860, is taken when s4(?) == 0, and falls through when s4(?) != 0.
  The `beq` branch at 0x12840 targets 0x12860, is taken when s0(=sym(err_buf)) >= a0(=([sym(err_buf)] + sym(err_buf))+4) (unsigned), and falls through when s0(=sym(err_buf)) < a0(=([sym(err_buf)] + sym(err_buf))+4) (unsigned).
  The `beq` branch at 0x12848 targets 0x127f8 and is always taken.
  The `beq` branch at 0x12858 targets 0x12824 and is always taken.
  The return at 0x12880 has v0 = one of [sym(err_buf)], ?.

- `save_cache_error` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x12888
  Role (from name): saves cache-error state for the calling node. The facts do not show what is saved. It loads a doubleword from a table at 0x9000000034000000 and the doubleword at offset 0x48 of (0x9600000000000000 | 0x2000), and the branch at 0x128d4 compares an unresolved value with 0xc000 and goes to the `chk_for_pebrick` call when they are equal. It compares another value against 0x10 at 0x12938 among byte and word loads from unresolved addresses, and stores doublewords, a word and a byte to addresses the facts leave unresolved. `get_nasid` is called at entry, and `chk_for_pebrick` is called at 0x12a18 with a4 = 0xffffffffff.
  Grade: inferred.
  Reviewed: 2026-11-12

- `kl_save_hw_state_node` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x12a28 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x12a28-0x12c50 (552 bytes).
  It occupies 552 bytes.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0x12a64, `ld` at 0x12a88.
  8 such `lw` accesses load 4 bytes from ?, including `lw` at 0x12a94, `lw` at 0x12b00, `lw` at 0x12b1c.
  3 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x12ad8, `lbu` at 0x12af0, `lbu` at 0x12b3c.
  The `jal` at 0x12bdc calls save_err_io_comp with a0=?, a1=?, a2=a1 at entry (arg1), a3=?, a5=0x20, a6=0x70, a7=0x80.
  The `jal` at 0x12bf4 calls save_err_node_comp with a0=?, a1=?, a2=a1 at entry (arg1), a3=?, a5=0x20, a6=0x70, a7=0x80.
  The `jal` at 0x12c04 calls get_nasid with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x12c18 calls chk_for_pebrick with a0=?, a1=?, a2=?, a3=?, a4=0xffffffffff.
  The `jal` at 0x12c2c calls save_err_router_comp with a0=?, a1=?, a2=a1 at entry (arg1), a3=?, a5=0x20, a6=0x70, a7=0x80.
  The `jal` at 0x12c40 calls save_err_xbow_comp with a0=?, a1=?, a2=a1 at entry (arg1), a3=?, a5=0x20, a6=0x70, a7=0x80.
  The `beq` branch at 0x12a48 targets 0x12c04, is taken when a0 == at(=-0x1), and falls through when a0 != at(=-0x1).
  The `beq` branch at 0x12a80 targets 0x12c18, is taken when v0(?) == v1(=0xc000), and falls through when v0(?) != v1(=0xc000).
  The `beq` branch at 0x12a9c targets 0x12aa8, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `beq` branch at 0x12aac targets 0x12bb4, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0x12ac0 targets 0x12ad8 and is always taken.
  The `beq` branch at 0x12ad0 targets 0x12bb4, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0x12ae8 targets 0x12b1c, is taken when (t8(?) & 0x1) == 0, and falls through when (t8(?) & 0x1) != 0.
  The `beq` branch at 0x12af8 targets 0x12b3c, is taken when (t9(?) & 0x4) == 0, and falls through when (t9(?) & 0x4) != 0.
  The `bne` branch at 0x12b0c targets 0x12ac8, is taken when t0(?) != 0, and falls through when t0(?) == 0.
  The `beq` branch at 0x12b14 targets 0x12acc and is always taken.
  The `beq` branch at 0x12b24 targets 0x12ad0, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x12b34 targets 0x12ad0 and is always taken.
  The `beq` branch at 0x12b54 targets 0x12bec, is taken when a4(?) == a1(=0x10), and falls through when a4(?) != a1(=0x10).
  The `beq` branch at 0x12b5c targets 0x12bd8, is taken when a4(?) == a5(=0x20), and falls through when a4(?) != a5(=0x20).
  The `beq` branch at 0x12b64 targets 0x12bd8, is taken when a4(?) == a6(=0x70), and falls through when a4(?) != a6(=0x70).
  The `beq` branch at 0x12b6c targets 0x12bd8, is taken when a4(?) == a7(=0x80), and falls through when a4(?) != a7(=0x80).
  The `beq` branch at 0x12b74 targets 0x12c28, is taken when a4(?) == t0(=0x30), and falls through when a4(?) != t0(=0x30).
  The `beq` branch at 0x12b7c targets 0x12c3c, is taken when a4(?) == t1(=0x40), and falls through when a4(?) != t1(=0x40).
  The `beq` branch at 0x12b9c targets 0x12ad0, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x12bac targets 0x12ad0 and is always taken.
  The `beq` branch at 0x12be4 targets 0x12b88 and is always taken.
  The `beq` branch at 0x12bfc targets 0x12b88 and is always taken.
  The `beq` branch at 0x12c10 targets 0x12a50 and is always taken.
  The `beq` branch at 0x12c20 targets 0x12aa8 and is always taken.
  The `beq` branch at 0x12c34 targets 0x12b88 and is always taken.
  The `beq` branch at 0x12c48 targets 0x12b88 and is always taken.
  The return at 0x12bcc has v0 = ?.
  The instructions from 0x12bd4 to 0x12bd4 are not reached by any path from the entry, and their branches are not listed.

- `kl_save_hw_state_all` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x12c50 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x12c50-0x12cb8 (104 bytes).
  It occupies 104 bytes.
  The `lh` at 0x12c88 loads 2 bytes from ?.
  The `jal` at 0x12c84 calls kl_save_hw_state_node with a0=?, a1=a0 at entry (arg0), a2=?, a3=?.
  The `blez` branch at 0x12c6c targets 0x12ca0, is taken when at(=[sym(numnodes)]) <= 0 (signed), and falls through when at(=[sym(numnodes)]) > 0 (signed).
  The `bne` branch at 0x12c98 targets 0x12c7c, is taken when s0(?) < a1(=[sym(numnodes)]) (signed), and falls through when s0(?) >= a1(=[sym(numnodes)]) (signed).
  The return at 0x12cb0 has v0 = one of ?, ret(kl_save_hw_state_node).

- `restore_cpu_err` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x12cb8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x12cb8-0x12d10 (88 bytes).
  It occupies 88 bytes.
  The `lbu` at 0x12cb8 loads 1 byte from a0 (arg0 at entry) +0x38.
  The `ld` at 0x12ccc loads 8 bytes from a0 (arg0 at entry) +0x0.
  The `ld` at 0x12cd0 loads 8 bytes from abs 0x9200000001030100.
  2 such `sb` accesses store 1 byte to a0 (arg0 at entry) +0x39, including `sb` at 0x12ce4, `sb` at 0x12d0c.
  The `ld` at 0x12ce8 loads 8 bytes from a0 (arg0 at entry) +0x18.
  The `ld` at 0x12cec loads 8 bytes from a0 (arg0 at entry) +0x10.
  The `ld` at 0x12cf0 loads 8 bytes from a0 (arg0 at entry) +0x8.
  The `sd` at 0x12cf4 stores 8 bytes to a0 (arg0 at entry) +0x20.
  The `sd` at 0x12cf8 stores 8 bytes to a0 (arg0 at entry) +0x28.
  The `sd` at 0x12cfc stores 8 bytes to a0 (arg0 at entry) +0x30.
  The `beq` branch at 0x12cc0 targets 0x12d00, is taken when at(=[a0+56]:1) == 0, and falls through when at(=[a0+56]:1) != 0.
  The `beq` branch at 0x12cdc targets 0x12d08, is taken when v0(?) >= v1(=0x55d4a80) (unsigned), and falls through when v0(?) < v1(=0x55d4a80) (unsigned).
  The return at 0x12d00 has v0 = ?.
  The return at 0x12d08 has v0 = ?.

- `restore_hub_err` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x12d10 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x12d10-0x12f0c (508 bytes).
  It occupies 508 bytes.
  The `ld` at 0x12d10 loads 8 bytes from a0 (arg0 at entry) +0x3b0.
  The `ld` at 0x12d24 loads 8 bytes from a0 (arg0 at entry) +0x3a0.
  The `ld` at 0x12d30 loads 8 bytes from a0 (arg0 at entry) +0x3c0.
  The `ld` at 0x12d3c loads 8 bytes from a0 (arg0 at entry) +0x3d0.
  12 such `ld` accesses load 8 bytes from ?, including `ld` at 0x12d50, `ld` at 0x12d7c, `ld` at 0x12d9c.
  7 such `ld` accesses load 8 bytes from abs 0x9200000001030100, including `ld` at 0x12db8, `ld` at 0x12df4, `ld` at 0x12e28.
  6 such `sd` accesses store 8 bytes to ?, including `sd` at 0x12dcc, `sd` at 0x12dd8, `sd` at 0x12e08.
  The `ld` at 0x12e4c loads 8 bytes from a0 (arg0 at entry) +0x138.
  The `ld` at 0x12e60 loads 8 bytes from a0 (arg0 at entry) +0x130.
  The `sd` at 0x12e7c stores 8 bytes to a0 (arg0 at entry) +0x3b0.
  The `ld` at 0x12e80 loads 8 bytes from a0 (arg0 at entry) +0x128.
  The `ld` at 0x12e8c loads 8 bytes from a0 (arg0 at entry) +0x120.
  The `sd` at 0x12ea8 stores 8 bytes to a0 (arg0 at entry) +0x3a0.
  The `ld` at 0x12eac loads 8 bytes from a0 (arg0 at entry) +0x148.
  The `ld` at 0x12eb8 loads 8 bytes from a0 (arg0 at entry) +0x140.
  The `sd` at 0x12ed4 stores 8 bytes to a0 (arg0 at entry) +0x3c0.
  The `ld` at 0x12ed8 loads 8 bytes from a0 (arg0 at entry) +0x158.
  The `ld` at 0x12ee4 loads 8 bytes from a0 (arg0 at entry) +0x150.
  The `sd` at 0x12efc stores 8 bytes to a0 (arg0 at entry) +0x3d0.
  The `ld` at 0x12f00 loads 8 bytes from a0 (arg0 at entry) +0x160.
  The `sd` at 0x12f08 stores 8 bytes to a0 (arg0 at entry) +0x3d8.
  The `beq` branch at 0x12d18 targets 0x12e4c, is taken when at(=[a0+944]:8) == 0, and falls through when at(=[a0+944]:8) != 0.
  The `beq` branch at 0x12d28 targets 0x12e80, is taken when v0(=[a0+928]:8) == 0, and falls through when v0(=[a0+928]:8) != 0.
  The `beq` branch at 0x12d34 targets 0x12eac, is taken when v1(=[a0+960]:8) == 0, and falls through when v1(=[a0+960]:8) != 0.
  The `beq` branch at 0x12d40 targets 0x12ed8, is taken when a1(=[a0+976]:8) == 0, and falls through when a1(=[a0+976]:8) != 0.
  The `beq` branch at 0x12d58 targets 0x12e18, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `bne` branch at 0x12d60 targets 0x12d4c, is taken when a3(?) != 0, and falls through when a3(?) == 0.
  The `beq` branch at 0x12d68 targets 0x12d74 and is always taken.
  The `beq` branch at 0x12d70 targets 0x12ddc, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0x12d88 targets 0x12de4, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `beq` branch at 0x12d90 targets 0x12ddc, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `bne` branch at 0x12da0 targets 0x12d70, is taken when a4(?) != 0, and falls through when a4(?) == 0.
  The `beq` branch at 0x12dac targets 0x12d70, is taken when t0(?) == 0, and falls through when t0(?) != 0.
  The `beq` branch at 0x12dc4 targets 0x12d70, is taken when a5(?) >= a7(=0x55d4a80) (unsigned), and falls through when a5(?) < a7(=0x55d4a80) (unsigned).
  The `beq` branch at 0x12dd4 targets 0x12d70 and is always taken.
  The `beq` branch at 0x12de8 targets 0x12d90, is taken when t0(?) == 0, and falls through when t0(?) != 0.
  The `beq` branch at 0x12e00 targets 0x12d90, is taken when t3(?) >= a7(=0x55d4a80) (unsigned), and falls through when t3(?) < a7(=0x55d4a80) (unsigned).
  The `beq` branch at 0x12e10 targets 0x12d90 and is always taken.
  The `beq` branch at 0x12e1c targets 0x12d60, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `beq` branch at 0x12e34 targets 0x12d60, is taken when at(?) >= a7(=0x55d4a80) (unsigned), and falls through when at(?) < a7(=0x55d4a80) (unsigned).
  The `beq` branch at 0x12e44 targets 0x12d60 and is always taken.
  The `beq` branch at 0x12e58 targets 0x12d24, is taken when a2(=[a0+312]:8) == 0, and falls through when a2(=[a0+312]:8) != 0.
  The `beq` branch at 0x12e70 targets 0x12d24, is taken when t0(?) >= a7(=0x55d4a80) (unsigned), and falls through when t0(?) < a7(=0x55d4a80) (unsigned).
  The `beq` branch at 0x12e78 targets 0x12d24 and is always taken.
  The `beq` branch at 0x12e84 targets 0x12d30, is taken when a2(=[a0+296]:8) == 0, and falls through when a2(=[a0+296]:8) != 0.
  The `beq` branch at 0x12e9c targets 0x12d30, is taken when t2(?) >= a7(=0x55d4a80) (unsigned), and falls through when t2(?) < a7(=0x55d4a80) (unsigned).
  The `beq` branch at 0x12ea4 targets 0x12d30 and is always taken.
  The `beq` branch at 0x12eb0 targets 0x12d3c, is taken when a2(=[a0+328]:8) == 0, and falls through when a2(=[a0+328]:8) != 0.
  The `beq` branch at 0x12ec8 targets 0x12d3c, is taken when t8(?) >= a7(=0x55d4a80) (unsigned), and falls through when t8(?) < a7(=0x55d4a80) (unsigned).
  The `beq` branch at 0x12ed0 targets 0x12d3c and is always taken.
  The `beq` branch at 0x12edc targets 0x12d44, is taken when a2(=[a0+344]:8) == 0, and falls through when a2(=[a0+344]:8) != 0.
  The `beq` branch at 0x12ef4 targets 0x12f00, is taken when at(?) >= a7(=0x55d4a80) (unsigned), and falls through when at(?) < a7(=0x55d4a80) (unsigned).
  The `beq` branch at 0x12f04 targets 0x12d44 and is always taken.
  The return at 0x12ddc has v0 = ?.

- `save_router_err` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x1340c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x1340c-0x13544 (312 bytes).
  It occupies 312 bytes.
  2 such `sd` accesses store 8 bytes to ?, including `sd` at 0x134dc, `sd` at 0x13540.
  The `jal` at 0x13430 calls bzero with a0=a2 at entry (arg2), a1=0x58, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1345c calls vector_read_node with a0=a1 at entry (arg1), a1=a0 at entry (arg0), a2=0x0, a3=0x0, a4=sp-96.
  The `jal` at 0x1350c calls vector_read_node with a0=a1 at entry (arg1), a1=a0 at entry (arg0), a2=0x0, a3=?.
  The `bltz` branch at 0x13478 targets 0x134d0, is taken when s3(=ret(vector_read_node)) < 0 (signed), and falls through when s3(=ret(vector_read_node)) >= 0 (signed).
  The `beq` branch at 0x13488 targets 0x134e0, is taken when (at(?) & v0(?)) == 0, and falls through when (at(?) & v0(?)) != 0.
  The `bne` branch at 0x1349c targets 0x13478, is taken when s1(?) < 0x9 (signed), and falls through when s1(?) >= 0x9 (signed).
  The `beq` branch at 0x134d8 targets 0x13490 and is always taken.
  The `bltz` branch at 0x13518 targets 0x1353c, is taken when v0(=ret(vector_read_node)) < 0 (signed), and falls through when v0(=ret(vector_read_node)) >= 0 (signed).
  The `bne` branch at 0x1352c targets 0x13478, is taken when a0(?) < 0x9 (signed), and falls through when a0(?) >= 0x9 (signed).
  The `beq` branch at 0x13534 targets 0x134a8 and is always taken.
  The `beq` branch at 0x1353c targets 0x13520 and is always taken.
  The return at 0x134c8 has v0 = one of ?, ret(vector_read_node).

- `save_hub_pi_error` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x1362c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x1362c-0x13704 (216 bytes).
  It occupies 216 bytes.
  The `ld` at 0x13650 loads 8 bytes from a0 (arg0 at entry) +0x400.
  3 such `sd` accesses store 8 bytes to a1 (arg1 at entry) +0x10, including `sd` at 0x13654, `sd` at 0x136f4, `sd` at 0x13700.
  The `ld` at 0x13658 loads 8 bytes from a0 (arg0 at entry) +0x50.
  The `ld` at 0x13668 loads 8 bytes from a0 (arg0 at entry) +0x58.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x430, including `ld` at 0x13674, `ld` at 0x13688.
  The `sd` at 0x1368c stores 8 bytes to a1 (arg1 at entry) +0x28.
  The `ld` at 0x13690 loads 8 bytes from a0 (arg0 at entry) +0x440.
  The `sd` at 0x13694 stores 8 bytes to a1 (arg1 at entry) +0x38.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x450, including `ld` at 0x13698, `ld` at 0x136a8.
  The `sd` at 0x136ac stores 8 bytes to a1 (arg1 at entry) +0x30.
  The `ld` at 0x136b0 loads 8 bytes from a0 (arg0 at entry) +0x460.
  The `sd` at 0x136b4 stores 8 bytes to a1 (arg1 at entry) +0x40.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x4c8, including `ld` at 0x136b8, `ld` at 0x136c8.
  The `sd` at 0x136cc stores 8 bytes to a1 (arg1 at entry) +0x48.
  The `ld` at 0x136d0 loads 8 bytes from a0 (arg0 at entry) +0x4d0.
  The `sd` at 0x136d4 stores 8 bytes to a1 (arg1 at entry) +0x50.
  The `jal` at 0x13648 calls bzero with a0=a1 at entry (arg1), a1=0x60, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0x13660 targets 0x136e8, is taken when at(=[a0+80]:8) == 0, and falls through when at(=[a0+80]:8) != 0.
  The `beq` branch at 0x1366c targets 0x136f8, is taken when v0(=[a0+88]:8) == 0, and falls through when v0(=[a0+88]:8) != 0.
  The `beq` branch at 0x13680 targets 0x13698, is taken when (a1(=0x8000000000000000) & v1(=[a0+1072]:8)) == 0, and falls through when (a1(=0x8000000000000000) & v1(=[a0+1072]:8)) != 0.
  The `beq` branch at 0x136a0 targets 0x136b8, is taken when (a1(=0x8000000000000000) & a3(=[a0+1104]:8)) == 0, and falls through when (a1(=0x8000000000000000) & a3(=[a0+1104]:8)) != 0.
  The `beq` branch at 0x136c0 targets 0x136d8, is taken when (a1(=0x8000000000000000) & a6(=[a0+1224]:8)) == 0, and falls through when (a1(=0x8000000000000000) & a6(=[a0+1224]:8)) != 0.
  The `beq` branch at 0x136f0 targets 0x13668 and is always taken.
  The `beq` branch at 0x136fc targets 0x13674 and is always taken.
  The return at 0x136e0 has v0 = [a0+88]:8.

- `save_hub_md_error` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x13704 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x13704-0x137f0 (236 bytes).
  It occupies 236 bytes.
  The `ld` at 0x13730 loads 8 bytes from a0 (arg0 at entry) +0x7c0010.
  2 such `sd` accesses store 8 bytes to a1 (arg1 at entry) +0x8, including `sd` at 0x1374c, `sd` at 0x137c8.
  The `ld` at 0x13750 loads 8 bytes from a0 (arg0 at entry) +0x7e0010.
  The `sd` at 0x13768 stores 8 bytes to a1 (arg1 at entry) +0x18.
  The `ld` at 0x1376c loads 8 bytes from a0 (arg0 at entry) +0x7c0020.
  The `sd` at 0x1377c stores 8 bytes to a1 (arg1 at entry) +0x28.
  The `ld` at 0x13780 loads 8 bytes from a0 (arg0 at entry) +0x780040.
  The `sd` at 0x1378c stores 8 bytes to a1 (arg1 at entry) +0x38.
  The `ld` at 0x13790 loads 8 bytes from a0 (arg0 at entry) +0x780048.
  The `sd` at 0x13794 stores 8 bytes to a1 (arg1 at entry) +0x40.
  The `jal` at 0x13720 calls bzero with a0=a1 at entry (arg1), a1=0x58, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0x13744 targets 0x137a4, is taken when at(?) == 0, and falls through when at(?) != 0.
  The `beq` branch at 0x13760 targets 0x137cc, is taken when (t0(?) & 0x3) == 0, and falls through when (t0(?) & 0x3) != 0.
  The `beq` branch at 0x13774 targets 0x13780, is taken when t1(?) == 0, and falls through when t1(?) != 0.
  The `beq` branch at 0x13784 targets 0x13798, is taken when a2(=[a0+7864384]:8) == 0, and falls through when a2(=[a0+7864384]:8) != 0.
  The `bltz` branch at 0x137ac targets 0x1374c, is taken when t3(=([a0+8126480]:8 << 0x1)) < 0 (signed), and falls through when t3(=([a0+8126480]:8 << 0x1)) >= 0 (signed).
  The `bltz` branch at 0x137b4 targets 0x1374c, is taken when a2(=([a0+8126480]:8 << 0x2)) < 0 (signed), and falls through when a2(=([a0+8126480]:8 << 0x2)) >= 0 (signed).
  The `bgez` branch at 0x137bc targets 0x13750, is taken when a7(=([a0+8126480]:8 << 0x3)) >= 0 (signed), and falls through when a7(=([a0+8126480]:8 << 0x3)) < 0 (signed).
  The `beq` branch at 0x137c4 targets 0x13750 and is always taken.
  The `bne` branch at 0x137d8 targets 0x13768, is taken when (a5(?) & 0x3) != 0, and falls through when (a5(?) & 0x3) == 0.
  The `bne` branch at 0x137e0 targets 0x13768, is taken when a3(?) != 0, and falls through when a3(?) == 0.
  The `beq` branch at 0x137e8 targets 0x1376c and is always taken.
  The return at 0x1379c has v0 = ret(bzero).

- `save_hub_io_crb` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x137f0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x137f0-0x1384c (92 bytes).
  It occupies 92 bytes.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0x13814, `ld` at 0x1381c.
  2 such `sd` accesses store 8 bytes to ?, including `sd` at 0x13818, `sd` at 0x13840.
  The `bne` branch at 0x1383c targets 0x13800, is taken when a3(?) < 0xf (signed), and falls through when a3(?) >= 0xf (signed).
  The return at 0x13844 has v0 = ?.

- `save_hub_io_ieph` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x1384c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x1384c-0x13868 (28 bytes).
  It occupies 28 bytes.
  The `ld` at 0x13854 loads 8 bytes from a0 (arg0 at entry) +0x400220.
  The `sd` at 0x13858 stores 8 bytes to a1 (arg1 at entry) +0xb8.
  The `ld` at 0x1385c loads 8 bytes from a0 (arg0 at entry) +0x400228.
  The `sd` at 0x13864 stores 8 bytes to a1 (arg1 at entry) +0xc0.
  The return at 0x13860 has v0 = [a0+4194848]:8.

- `save_hub_io_error` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x13868 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x13868-0x1390c (164 bytes).
  It occupies 164 bytes.
  The `ld` at 0x1389c loads 8 bytes from a0 (arg0 at entry) +0x400008.
  The `sd` at 0x138a4 stores 8 bytes to a1 (arg1 at entry) +0x8.
  The `ld` at 0x138a8 loads 8 bytes from a0 (arg0 at entry) +0x410000.
  The `sd` at 0x138ac stores 8 bytes to a1 (arg1 at entry) +0x88.
  The `ld` at 0x138b0 loads 8 bytes from a0 (arg0 at entry) +0x410008.
  The `sd` at 0x138b4 stores 8 bytes to a1 (arg1 at entry) +0x98.
  The `ld` at 0x138bc loads 8 bytes from a0 (arg0 at entry) +0x410010.
  The `sd` at 0x138c4 stores 8 bytes to a1 (arg1 at entry) +0xa8.
  The `ld` at 0x138c8 loads 8 bytes from a0 (arg0 at entry) +0x420000.
  The `sd` at 0x138cc stores 8 bytes to a1 (arg1 at entry) +0x90.
  The `ld` at 0x138d0 loads 8 bytes from a0 (arg0 at entry) +0x420008.
  The `sd` at 0x138d4 stores 8 bytes to a1 (arg1 at entry) +0xa0.
  The `ld` at 0x138dc loads 8 bytes from a0 (arg0 at entry) +0x420010.
  The `sd` at 0x138e8 stores 8 bytes to a1 (arg1 at entry) +0xb0.
  The `jal` at 0x13884 calls bzero with a0=a1 at entry (arg1), a1=0xd0, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x138e4 calls save_hub_io_crb with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=[a0+4259840]:8, a3=[a0+4194312]:8.
  The `jal` at 0x138f0 calls save_hub_io_ieph with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?.
  The return at 0x13904 has v0 = ret(save_hub_io_ieph).

- `save_hub_err_ext` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x1390c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x1390c-0x139c4 (184 bytes).
  It occupies 184 bytes.
  3 such `ld` accesses load 8 bytes from ?, including `ld` at 0x13958, `ld` at 0x13980, `ld` at 0x139a8.
  3 such `sd` accesses store 8 bytes to ?, including `sd` at 0x1395c, `sd` at 0x13988, `sd` at 0x139b0.
  The `jal` at 0x13928 calls bzero with a0=a1 at entry (arg1), a1=0xc0, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0x13960 targets 0x1398c, is taken when a2(?) >= 0xf (signed), and falls through when a2(?) < 0xf (signed).
  The `bne` branch at 0x13984 targets 0x1393c, is taken when a2(?) < 0xf (signed), and falls through when a2(?) >= 0xf (signed).
  The `bne` branch at 0x139ac targets 0x13990, is taken when a2(?) < 0x9 (signed), and falls through when a2(?) >= 0x9 (signed).
  The return at 0x139bc has v0 = ?.

- `save_hub_ni_error` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x139c4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x139c4-0x13a28 (100 bytes).
  It occupies 100 bytes.
  The `ld` at 0x139f0 loads 8 bytes from a0 (arg0 at entry) +0x680100.
  The `sd` at 0x13a00 stores 8 bytes to a1 (arg1 at entry) +0x8.
  The `ld` at 0x13a04 loads 8 bytes from a0 (arg0 at entry) +0x680108.
  The `sd` at 0x13a08 stores 8 bytes to a1 (arg1 at entry) +0x10.
  The `ld` at 0x13a0c loads 8 bytes from a0 (arg0 at entry) +0x680110.
  The `sd` at 0x13a10 stores 8 bytes to a1 (arg1 at entry) +0x18.
  The `ld` at 0x13a14 loads 8 bytes from a0 (arg0 at entry) +0x680118.
  The `sd` at 0x13a18 stores 8 bytes to a1 (arg1 at entry) +0x20.
  The `jal` at 0x139e0 calls bzero with a0=a1 at entry (arg1), a1=0x30, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0x139fc targets 0x13a1c, is taken when at(=[a0+6816000]:8) == 0, and falls through when at(=[a0+6816000]:8) != 0.
  The return at 0x13a20 has v0 = ret(bzero).

- `save_hub_lb_error` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x13a28 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x13a28-0x13ab0 (136 bytes).
  It occupies 136 bytes.
  The `ld` at 0x13a54 loads 8 bytes from a0 (arg0 at entry) +0x604040.
  The `sd` at 0x13a58 stores 8 bytes to a1 (arg1 at entry) +0x8.
  The `ld` at 0x13a5c loads 8 bytes from a0 (arg0 at entry) +0x604050.
  The `ld` at 0x13a78 loads 8 bytes from a0 (arg0 at entry) +0x60c020.
  The `sd` at 0x13a88 stores 8 bytes to a1 (arg1 at entry) +0x28.
  The `sd` at 0x13a98 stores 8 bytes to a1 (arg1 at entry) +0x10.
  The `ld` at 0x13a9c loads 8 bytes from a0 (arg0 at entry) +0x604058.
  The `sd` at 0x13aa0 stores 8 bytes to a1 (arg1 at entry) +0x18.
  The `ld` at 0x13aa4 loads 8 bytes from a0 (arg0 at entry) +0x604060.
  The `sd` at 0x13aac stores 8 bytes to a1 (arg1 at entry) +0x20.
  The `jal` at 0x13a44 calls bzero with a0=a1 at entry (arg1), a1=0x38, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `bltz` branch at 0x13a70 targets 0x13a98, is taken when at(=([a0+6307920]:8 << 0x13)) < 0 (signed), and falls through when at(=([a0+6307920]:8 << 0x13)) >= 0 (signed).
  The `beq` branch at 0x13a80 targets 0x13a8c, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0x13aa8 targets 0x13a78 and is always taken.
  The return at 0x13a90 has v0 = [a0+6307904]:8.

- `save_hub_xb_error` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x13ab0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x13ab0-0x13bf8 (328 bytes).
  It occupies 328 bytes.
  The `ld` at 0x13adc loads 8 bytes from a0 (arg0 at entry) +0x700090.
  The `sd` at 0x13b14 stores 8 bytes to a1 (arg1 at entry) +0x8.
  The `ld` at 0x13b20 loads 8 bytes from table(sym(.rodata)+7952) +0x0.
  The `jal` at 0x13acc calls bzero with a0=a1 at entry (arg1), a1=0x20, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x13b38 calls printf with a0=sym(.rodata)+7952, a1=?, a2=?, a3=[a0+7340176]:8, a4=table(sym(.rodata)+7952).
  The `jal` at 0x13b40 calls printf with a0=sym(.rodata)+7952, a1=?, a2=?, a3=?.
  The `bltz` branch at 0x13ae4 targets 0x13b00, is taken when at(=([a0+7340176]:8 << 0x33)) < 0 (signed), and falls through when at(=([a0+7340176]:8 << 0x33)) >= 0 (signed).
  The `beq` branch at 0x13b18 targets 0x13b2c, is taken when a1(?) >= 0x10 (unsigned), and falls through when a1(?) < 0x10 (unsigned).
  The `beq` branch at 0x13b48 targets 0x13af0 and is always taken.
  The return at 0x13af8 has v0 = one of ret(bzero), ret(printf).
  The instructions from 0x13b50 to 0x13bf4 are not reached by any path from the entry, and their branches are not listed.
  The indirect jump at 0x13b24 uses a jump table whose successors are unresolved.

- `save_hub_err` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x13bf8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x13bf8-0x13d98 (416 bytes).
  It occupies 416 bytes.
  The `lw` at 0x13c0c loads 4 bytes from a2 (arg2 at entry) +0xc.
  The `ld` at 0x13c68 loads 8 bytes from ?.
  The `lw` at 0x13ce4 loads 4 bytes from a1 (arg1 at entry) +0x4f4.
  The `jal` at 0x13c78 calls save_hub_pi_error with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x13c84 calls bzero with a0=?, a1=0x60, a2=?, a3=?.
  The `jal` at 0x13c9c calls save_hub_md_error with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x13ca8 calls save_hub_io_error with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x13cb8 calls save_hub_ni_error with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x13cc4 calls save_hub_lb_error with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x13cd0 calls save_hub_xb_error with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x13d04 calls save_hub_err_ext with a0=?, a1=?, a2=0x9600000000000000, a3=0xffffffffff.
  The `jal` at 0x13d24 calls save_hub_pi_error with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x13d34 calls save_hub_pi_error with a0=table(0x200000), a1=?, a2=?, a3=?.
  The `jal` at 0x13d58 calls bzero with a0=?, a1=0x60, a2=?, a3=?.
  The `jal` at 0x13d68 calls save_hub_pi_error with a0=table(0x200000), a1=?, a2=?, a3=?.
  The `jal` at 0x13d78 calls clear_hub_pi_error with a0=?, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a4=0x2, a5=[a2+12], a6=(a0 << 0x21), a7=0x9200000001800000.
  The `jal` at 0x13d80 calls clear_hub_pi_error with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x13d88 calls clear_hub_md_error with a0=?, a1=?, a2=?, a3=?.
  The `beq` branch at 0x13c34 targets 0x13d4c, is taken when (a5(=[a2+12]) & 0x1) == 0, and falls through when (a5(=[a2+12]) & 0x1) != 0.
  The `beq` branch at 0x13c44 targets 0x13d44, is taken when s5(=a0) == t0(=-0x1), and falls through when s5(=a0) != t0(=-0x1).
  The `beq` branch at 0x13c58 targets 0x13d78, is taken when a5(=[a2+12]) == a4(=0x2), and falls through when a5(=[a2+12]) != a4(=0x2).
  The `bne` branch at 0x13c60 targets 0x13d24, is taken when s5(=a0) != t0(=-0x1), and falls through when s5(=a0) == t0(=-0x1).
  The `bltz` branch at 0x13c70 targets 0x13d54, is taken when v0(?) < 0 (signed), and falls through when v0(?) >= 0 (signed).
  The `beq` branch at 0x13d3c targets 0x13c90 and is always taken.
  The `beq` branch at 0x13d44 targets 0x13c50 and is always taken.
  The `beq` branch at 0x13d4c targets 0x13c40 and is always taken.
  The `beq` branch at 0x13d70 targets 0x13c90 and is always taken.
  The `beq` branch at 0x13d90 targets 0x13c60 and is always taken.
  The return at 0x13d1c has v0 = ret(save_hub_err_ext).

- `save_bridge_err` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x13d98 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x13d98-0x13ff4 (604 bytes).
  It occupies 604 bytes.
  The `lw` at 0x13dc0 loads 4 bytes from a3 (arg3 at entry) +0xc.
  23 such `lw` accesses load 4 bytes from ?, including `lw` at 0x13de0, `lw` at 0x13de8, `lw` at 0x13df0.
  The `sw` at 0x13de4 stores 4 bytes to (a1 + one of 0x8, 0x90) +0x0.
  The `sw` at 0x13dec stores 4 bytes to (a1 + one of 0xc, 0x94) +0x0.
  The `sw` at 0x13df4 stores 4 bytes to (a1 + one of 0x10, 0x98) +0x0.
  The `sw` at 0x13dfc stores 4 bytes to (a1 + one of 0x14, 0x9c) +0x0.
  The `sw` at 0x13e04 stores 4 bytes to (a1 + one of 0x18, 0xa0) +0x0.
  The `sw` at 0x13e0c stores 4 bytes to (a1 + one of 0x1c, 0xa4) +0x0.
  The `sw` at 0x13e14 stores 4 bytes to (a1 + one of 0x20, 0xa8) +0x0.
  The `sw` at 0x13e1c stores 4 bytes to (a1 + one of 0x24, 0xac) +0x0.
  The `sw` at 0x13e24 stores 4 bytes to (a1 + one of 0x28, 0xb0) +0x0.
  2 such `sd` accesses store 8 bytes to (a1 + one of 0x30, 0xb8) +0x0, including `sd` at 0x13e34, `sd` at 0x13f30.
  The `sw` at 0x13eac stores 4 bytes to (a1 + one of 0x38, 0xc0) +0x0.
  The `sw` at 0x13ed8 stores 4 bytes to (a1 + one of 0x3c, 0xc4) +0x0.
  The `sw` at 0x13ee0 stores 4 bytes to (a1 + one of 0x40, 0xc8) +0x0.
  10 such `ld` accesses load 8 bytes from ?, including `ld` at 0x13ee4, `ld` at 0x13eec, `ld` at 0x13ef4.
  The `sd` at 0x13ee8 stores 8 bytes to (a1 + one of 0x48, 0xd0) +0x0.
  The `sd` at 0x13ef0 stores 8 bytes to (a1 + one of 0x50, 0xd8) +0x0.
  The `sd` at 0x13ef8 stores 8 bytes to (a1 + one of 0x58, 0xe0) +0x0.
  The `sd` at 0x13f00 stores 8 bytes to (a1 + one of 0x60, 0xe8) +0x0.
  The `sd` at 0x13f08 stores 8 bytes to (a1 + one of 0x68, 0xf0) +0x0.
  The `sd` at 0x13f10 stores 8 bytes to (a1 + one of 0x70, 0xf8) +0x0.
  The `sd` at 0x13f18 stores 8 bytes to (a1 + one of 0x78, 0x100) +0x0.
  The `sd` at 0x13f20 stores 8 bytes to (a1 + one of 0x80, 0x108) +0x0.
  The `sd` at 0x13f28 stores 8 bytes to (a1 + one of 0x88, 0x110) +0x0.
  The `jal` at 0x13dd8 calls bzero with a0=(a1 + one of 0x8, 0x90), a1=0x88, a2=a2 at entry (arg2), a3=a3 at entry (arg3), a5=(a0 << 0x21), a6=-0x37.
  The `jal` at 0x13fe4 calls pcireg_mode_get with a0=?, a1=one of 0x0, 0x1, a2=0x24, a3=?.
  The `beq` branch at 0x13da8 targets 0x13f48, is taken when a2 == 0, and falls through when a2 != 0.
  The `beq` branch at 0x13dc8 targets 0x13f54, is taken when (t8(=[a3+12]) & 0x1) == 0, and falls through when (t8(=[a3+12]) & 0x1) != 0.
  The `beq` branch at 0x13e48 targets 0x13f5c, is taken when a0(=0xd102) == t9(?), and falls through when a0(=0xd102) != t9(?).
  The `bne` branch at 0x13e5c targets 0x13f38, is taken when a6(?) != a7(=0xd112), and falls through when a6(?) == a7(=0xd112).
  The `bne` branch at 0x13e74 targets 0x13f38, is taken when a2(=0x24) != a7(?), and falls through when a2(=0x24) == a7(?).
  The `beq` branch at 0x13e90 targets 0x13f7c, is taken when a0(=0xd102) == t0(?), and falls through when a0(=0xd102) != t0(?).
  The `beq` branch at 0x13ea4 targets 0x13f98, is taken when t1(?) == t2(=0xd112), and falls through when t1(?) != t2(=0xd112).
  The `beq` branch at 0x13ebc targets 0x13fb4, is taken when a0(=0xd102) == t2(?), and falls through when a0(=0xd102) != t2(?).
  The `beq` branch at 0x13ed0 targets 0x13fd0, is taken when t3(?) == t8(=0xd112), and falls through when t3(?) != t8(=0xd112).
  The `beq` branch at 0x13f4c targets 0x13dc0 and is always taken.
  The `beq` branch at 0x13f54 targets 0x13dd4 and is always taken.
  The `bne` branch at 0x13f6c targets 0x13e50, is taken when a2(=0x24) != t8(?), and falls through when a2(=0x24) == t8(?).
  The `beq` branch at 0x13f74 targets 0x13e7c and is always taken.
  The `bne` branch at 0x13f88 targets 0x13e98, is taken when a2(=0x24) != t9(?), and falls through when a2(=0x24) == t9(?).
  The `beq` branch at 0x13f90 targets 0x13fac and is always taken.
  The `bne` branch at 0x13fa4 targets 0x13eac, is taken when a2(=0x24) != ra(?), and falls through when a2(=0x24) == ra(?).
  The `beq` branch at 0x13fac targets 0x13eac and is always taken.
  The `bne` branch at 0x13fc0 targets 0x13ec4, is taken when a2(=0x24) != at(?), and falls through when a2(=0x24) == at(?).
  The `beq` branch at 0x13fc8 targets 0x13fe4 and is always taken.
  The `bne` branch at 0x13fdc targets 0x13ed8, is taken when a2(=0x24) != v0(?), and falls through when a2(=0x24) == v0(?).
  The `beq` branch at 0x13fec targets 0x13ed8 and is always taken.
  The return at 0x13f40 has v0 = ?.

- `save_xbow_err` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x13ff4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x13ff4-0x140a8 (180 bytes).
  It occupies 180 bytes.
  The `lw` at 0x13ff4 loads 4 bytes from a2 (arg2 at entry) +0xc.
  The `lw` at 0x1403c loads 4 bytes from (a0 << 0x21) -0x6dffffff1ffffff4.
  The `sw` at 0x14040 stores 4 bytes to (a1 + one of 0x8, 0x58) +0x0.
  The `lw` at 0x14044 loads 4 bytes from (a0 << 0x21) -0x6dffffff1fffffec.
  The `sw` at 0x14048 stores 4 bytes to (a1 + one of 0xc, 0x5c) +0x0.
  The `lw` at 0x1404c loads 4 bytes from (a0 << 0x21) -0x6dffffff1fffffe4.
  The `sw` at 0x14050 stores 4 bytes to (a1 + one of 0x10, 0x60) +0x0.
  The `lw` at 0x14054 loads 4 bytes from (a0 << 0x21) -0x6dffffff1fffffbc.
  The `sw` at 0x14060 stores 4 bytes to (a1 + one of 0x14, 0x64) +0x0.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0x14080, `lw` at 0x1408c.
  2 such `sw` accesses store 4 bytes to ?, including `sw` at 0x14088, `sw` at 0x14098.
  The `jal` at 0x14020 calls bzero with a0=(a1 + one of 0x8, 0x58), a1=0x50, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0x14010 targets 0x1401c, is taken when (at(=[a2+12]) & 0x1) == 0, and falls through when (at(=[a2+12]) & 0x1) != 0.
  The `bne` branch at 0x14094 targets 0x14064, is taken when a1(?) < 0x8 (signed), and falls through when a1(?) >= 0x8 (signed).
  The return at 0x140a0 has v0 = [(a0 << 0x21)-7926335340413976508].

- `kl_error_show_node` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x140a8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x140a8-0x142e4 (572 bytes).
  It occupies 572 bytes.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0x140f0, `ld` at 0x14110.
  8 such `lw` accesses load 4 bytes from ?, including `lw` at 0x14124, `lw` at 0x14194, `lw` at 0x141b0.
  3 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x1416c, `lbu` at 0x14184, `lbu` at 0x141d4.
  The `lw` at 0x14258 loads 4 bytes from a1 (arg1 at entry) +0x8.
  The `ld` at 0x14260 loads 8 bytes from a1 (arg1 at entry) +0x0.
  The `jal` at 0x140dc calls kl_perr with a0=0x1, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x1425c calls kl_perr_dumpbuf with a0=[a1]:8, a1=[a1+8], a2=?, a3=?.
  The `jal` at 0x14278 calls show_err_io_comp with a0=?, a1=a1 at entry (arg1), a2=0x20, a3=0x70, a4=0x80, a5=0x30, a6=0x40.
  The `jal` at 0x1428c calls show_err_node_comp with a0=?, a1=a1 at entry (arg1), a2=0x20, a3=0x70, a4=0x80, a5=0x30, a6=0x40.
  The `jal` at 0x1429c calls get_nasid with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x142b0 calls chk_for_pebrick with a0=?, a1=?, a2=?, a3=0xc000.
  The `jal` at 0x142c4 calls show_err_router_comp with a0=?, a1=a1 at entry (arg1), a2=0x20, a3=0x70, a4=0x80, a5=0x30, a6=0x40.
  The `jal` at 0x142d4 calls show_err_xbow_comp with a0=?, a1=a1 at entry (arg1), a2=0x20, a3=0x70, a4=0x80, a5=0x30, a6=0x40.
  The `beq` branch at 0x140c0 targets 0x1429c, is taken when a0 == at(=-0x1), and falls through when a0 != at(=-0x1).
  The `beq` branch at 0x14108 targets 0x142b0, is taken when a2(?) == a3(=0xc000), and falls through when a2(?) != a3(=0xc000).
  The `beq` branch at 0x14130 targets 0x1413c, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `beq` branch at 0x14140 targets 0x1424c, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0x14154 targets 0x1416c and is always taken.
  The `beq` branch at 0x14164 targets 0x1424c, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0x1417c targets 0x141b0, is taken when (t8(?) & 0x1) == 0, and falls through when (t8(?) & 0x1) != 0.
  The `beq` branch at 0x1418c targets 0x141d4, is taken when (t9(?) & 0x4) == 0, and falls through when (t9(?) & 0x4) != 0.
  The `bne` branch at 0x141a0 targets 0x1415c, is taken when a4(?) != 0, and falls through when a4(?) == 0.
  The `beq` branch at 0x141a8 targets 0x14160 and is always taken.
  The `beq` branch at 0x141bc targets 0x14164, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x141cc targets 0x14164 and is always taken.
  The `beq` branch at 0x141ec targets 0x14288, is taken when a0(?) == a1(=0x10), and falls through when a0(?) != a1(=0x10).
  The `beq` branch at 0x141f4 targets 0x14274, is taken when a0(?) == a2(=0x20), and falls through when a0(?) != a2(=0x20).
  The `beq` branch at 0x141fc targets 0x14274, is taken when a0(?) == a3(=0x70), and falls through when a0(?) != a3(=0x70).
  The `beq` branch at 0x14204 targets 0x14274, is taken when a0(?) == a4(=0x80), and falls through when a0(?) != a4(=0x80).
  The `beq` branch at 0x1420c targets 0x142c0, is taken when a0(?) == a5(=0x30), and falls through when a0(?) != a5(=0x30).
  The `beq` branch at 0x14214 targets 0x142d4, is taken when a0(?) == a6(=0x40), and falls through when a0(?) != a6(=0x40).
  The `beq` branch at 0x14234 targets 0x14164, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x14244 targets 0x14164 and is always taken.
  The `beq` branch at 0x14280 targets 0x14220 and is always taken.
  The `beq` branch at 0x14294 targets 0x14220 and is always taken.
  The `beq` branch at 0x142a8 targets 0x140c8 and is always taken.
  The `beq` branch at 0x142b8 targets 0x1413c and is always taken.
  The `beq` branch at 0x142cc targets 0x14220 and is always taken.
  The `beq` branch at 0x142dc targets 0x14220 and is always taken.
  The return at 0x1426c has v0 = ret(kl_perr_dumpbuf).

- `kl_error_show` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x142e4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x142e4-0x14388 (164 bytes).
  It occupies 164 bytes.
  The `lh` at 0x1433c loads 2 bytes from ?.
  The `lw` at 0x1436c loads 4 bytes from a2 (arg2 at entry) +0x8.
  The `ld` at 0x14374 loads 8 bytes from a2 (arg2 at entry) +0x0.
  The `jal` at 0x14304 calls kl_perr_init with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x14310 calls kl_perr with a0=0x10, a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0x14338 calls kl_error_show_node with a0=?, a1=a2 at entry (arg2), a2=?, a3=?.
  The `jal` at 0x14360 calls kl_perr with a0=0x10, a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0x14370 calls kl_perr_dumpbuf with a0=[a2]:8, a1=[a2+8], a2=?, a3=?.
  The `blez` branch at 0x14320 targets 0x14354, is taken when at(=[sym(numnodes)]) <= 0 (signed), and falls through when at(=[sym(numnodes)]) > 0 (signed).
  The `bne` branch at 0x1434c targets 0x14330, is taken when s0(?) < a1(=[sym(numnodes)]) (signed), and falls through when s0(?) >= a1(=[sym(numnodes)]) (signed).
  The return at 0x14380 has v0 = ret(kl_perr_dumpbuf).

- `kl_dump_hw_state` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x14388 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x14388-0x143b8 (48 bytes).
  It occupies 48 bytes.
  The `jal` at 0x143a4 calls kl_save_hw_state_all with a0=sp-32, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x143b0 has v0 = ret(kl_save_hw_state_all).

- `kl_log_hw_state` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x143b8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x143b8-0x143e8 (48 bytes).
  It occupies 48 bytes.
  The `jal` at 0x143d4 calls kl_save_hw_state_all with a0=sp-32, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x143e0 has v0 = ret(kl_save_hw_state_all).

- `kl_error_show_dump` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x143e8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x143e8-0x1441c (52 bytes).
  It occupies 52 bytes.
  The `jal` at 0x14408 calls kl_error_show with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=sp-32, a3=a3 at entry (arg3).
  The return at 0x14414 has v0 = ret(kl_error_show).

- `kl_error_show_log` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x1441c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x1441c-0x1444c (48 bytes).
  It occupies 48 bytes.
  The `jal` at 0x14438 calls kl_error_show with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=sp-32, a3=a3 at entry (arg3).
  The return at 0x14444 has v0 = ret(kl_error_show).

- `kl_error_show_idbg` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x1444c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x1444c-0x1447c (48 bytes).
  It occupies 48 bytes.
  The `jal` at 0x14468 calls kl_error_show with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=sp-32, a3=a3 at entry (arg3).
  The return at 0x14474 has v0 = ret(kl_error_show).

- `kl_error_show_reset_ste` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x1447c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x1447c-0x144a8 (44 bytes).
  It occupies 44 bytes.
  The `jal` at 0x14494 calls kl_error_show with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=sp-32, a3=a3 at entry (arg3).
  The return at 0x144a0 has v0 = ret(kl_error_show).

- `show_hub_err` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x14a10 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x14a10-0x14ac4 (180 bytes).
  It occupies 180 bytes.
  2 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0xc, including `lw` at 0x14a18, `lw` at 0x14a84.
  The `jal` at 0x14a50 calls kl_perr with a0=0x3, a1=sym(.rodata)+7952, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x14a60 calls show_hub_pi_err with a0=?, a1=a2 at entry (arg2), a2=0x0, a3=?.
  The `jal` at 0x14a70 calls show_hub_pi_err with a0=?, a1=a2 at entry (arg2), a2=0x1, a3=?.
  The `jal` at 0x14a78 calls show_hub_md_err with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x14a88 calls show_hub_io_err with a0=a0 at entry (arg0), a1=[a1+12], a2=a2 at entry (arg2), a3=?.
  The `jal` at 0x14a9c calls show_hub_ni_err with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x14aa4 calls show_hub_lb_err with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x14aac calls show_hub_xb_err with a0=?, a1=?, a2=?, a3=?.
  The `beq` branch at 0x14a3c targets 0x14a48, is taken when (at(=[a1+12]) & 0x1) == 0, and falls through when (at(=[a1+12]) & 0x1) != 0.
  The return at 0x14abc has v0 = ret(show_hub_xb_err).

- `show_hub_pi_err` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x14c10 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x14c10-0x151d8 (1480 bytes).
  It occupies 1480 bytes.
  The `ld` at 0x14c38 loads 8 bytes from a0 (arg0 at entry) +0x10.
  7 such `ld` accesses load 8 bytes from ?, including `ld` at 0x14c8c, `ld` at 0x14d0c, `ld` at 0x14d34.
  The `ld` at 0x14d6c loads 8 bytes from table(sym(pi_err_status_cmd)) +0x800.
  The `ld` at 0x14dd0 loads 8 bytes from table(sym(pi_err_status_cmd)) +0x0.
  2 such `ld` accesses load 8 bytes from ((a1 << 0x21) + one of 0x9200000001800428, 0x9200000001a00428) +0x0, including `ld` at 0x14ec4, `ld` at 0x14ed8.
  The `ld` at 0x15000 loads 8 bytes from a0 (arg0 at entry) +0x48.
  The `ld` at 0x150b0 loads 8 bytes from a0 (arg0 at entry) +0x50.
  The `ld` at 0x15198 loads 8 bytes from table(sym(pi_err_status_cmd)) +0x840.
  The `jal` at 0x14c5c calls kl_perr with a0=0x4, a1=sym(.rodata)+7952, a2=a2 at entry (arg2), a3=[a0+16]:8.
  The `jal` at 0x14c90 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x14d38 calls kl_perr with a0=0x4, a1=sym(.rodata)+7952, a2=a2 at entry (arg2), a3=one of 0x41, 0x42.
  The `jal` at 0x14d68 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=[table(sym(pi_err_status_cmd))+2048]:8, a3=?.
  The `jal` at 0x14d80 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x14d98 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x14dcc calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=sym(.rodata)+7952, a4=entry(sym(pi_err_status_cmd)).
  The `jal` at 0x14dec calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x14e04 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x14e1c calls kl_perr with a0=0x4, a1=sym(.rodata)+7952, a2=a2 at entry (arg2), a3=one of 0x41, 0x42.
  The `jal` at 0x14e38 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x14e50 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x14e6c calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x14e8c calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x14ea4 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x14eb8 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x14f14 calls kl_perr with a0=0x4, a1=sym(.rodata)+7952, a2=a2 at entry (arg2), a3=one of 0x41, 0x42.
  The `jal` at 0x14f64 calls show_pi_error_spool_entry with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x14fc4 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x14fd8 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x15018 calls kl_perr with a0=0x4, a1=sym(.rodata)+7952, a2=a2 at entry (arg2), a3=[a0+72]:8.
  The `jal` at 0x15030 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x1504c calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x15060 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x15080 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x15094 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x150a0 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x150bc calls kl_perr with a0=0x4, a1=sym(.rodata)+7952, a2=a2 at entry (arg2), a3=[a0+80]:8.
  The `jal` at 0x150cc calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x15104 calls memory_present with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x15154 calls memory_present with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x15174 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x15194 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=[table(sym(pi_err_status_cmd))+2112]:8, a3=?.
  The `jal` at 0x151b4 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x151c8 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `beq` branch at 0x14c48 targets 0x14cb0, is taken when s1(=[a0+16]:8) == 0, and falls through when s1(=[a0+16]:8) != 0.
  The `beq` branch at 0x14c80 targets 0x14c98, is taken when (s1(=[a0+16]:8) & a2(?)) == 0, and falls through when (s1(=[a0+16]:8) & a2(?)) != 0.
  The `bne` branch at 0x14ca4 targets 0x14c78, is taken when s0(?) < 0x23 (unsigned), and falls through when s0(?) >= 0x23 (unsigned).
  The `beq` branch at 0x14d14 targets 0x14fe0, is taken when t1(?) == 0, and falls through when t1(?) != 0.
  The `bltz` branch at 0x14d48 targets 0x15184, is taken when t1(?) < 0 (signed), and falls through when t1(?) >= 0 (signed).
  The `beq` branch at 0x14d50 targets 0x15148, is taken when s4(?) == 0, and falls through when s4(?) != 0.
  The `beq` branch at 0x14d78 targets 0x14d88, is taken when (a2(?) & 0x7) == 0, and falls through when (a2(?) & 0x7) != 0.
  The `beq` branch at 0x14d90 targets 0x14da0, is taken when (a2(?) & 0x7ff) == 0, and falls through when (a2(?) & 0x7ff) != 0.
  The `beq` branch at 0x14dac targets 0x1516c, is taken when (a6(?) & 0x80) == 0, and falls through when (a6(?) & 0x80) != 0.
  The `bltz` branch at 0x14df8 targets 0x15174, is taken when t8(?) < 0 (signed), and falls through when t8(?) >= 0 (signed).
  The `beq` branch at 0x14e30 targets 0x14e40, is taken when (a2(=0x1fffff) & s2(?)) == 0, and falls through when (a2(=0x1fffff) & s2(?)) != 0.
  The `beq` branch at 0x14e48 targets 0x14e58, is taken when (a2(?) & 0xff) == 0, and falls through when (a2(?) & 0xff) != 0.
  The `beq` branch at 0x14e60 targets 0x14e78, is taken when (a2(?) & 0x3ff) == 0, and falls through when (a2(?) & 0x3ff) != 0.
  The `bltz` branch at 0x14e7c targets 0x151b0, is taken when a3(?) < 0 (signed), and falls through when a3(?) >= 0 (signed).
  The `beq` branch at 0x14e84 targets 0x14e94, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0x14e9c targets 0x14eac, is taken when (a2(?) & 0x3ff) == 0, and falls through when (a2(?) & 0x3ff) != 0.
  The `beq` branch at 0x14eb0 targets 0x14ec0, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0x14ed0 targets 0x15138, is taken when a3(=[((a1 << 0x21) + one of 0x9200000001800428, 0x9200000001a00428)]:8) == 0, and falls through when a3(=[((a1 << 0x21) + one of 0x9200000001800428, 0x9200000001a00428)]:8) != 0.
  The `beq` branch at 0x14ee8 targets 0x15140, is taken when s3(=a2) == 0, and falls through when s3(=a2) != 0.
  The `beq` branch at 0x14f50 targets 0x14fe0, is taken when s0(?) >= s5(?) (unsigned), and falls through when s0(?) < s5(?) (unsigned).
  The `beq` branch at 0x14f58 targets 0x14f80 and is always taken.
  The `bne` branch at 0x14f78 targets 0x14fb8, is taken when s5(?) < s0(?) (unsigned), and falls through when s5(?) >= s0(?) (unsigned).
  The `bltz` branch at 0x14f8c targets 0x14f60, is taken when ra(?) < 0 (signed), and falls through when ra(?) >= 0 (signed).
  The `beq` branch at 0x14f94 targets 0x15104, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `bne` branch at 0x14f9c targets 0x14f60, is taken when at(=0x4) != a3(?), and falls through when at(=0x4) == a3(?).
  The `beq` branch at 0x14fac targets 0x14f80, is taken when s5(?) >= s0(?) (unsigned), and falls through when s5(?) < s0(?) (unsigned).
  The `beq` branch at 0x14fb8 targets 0x14fcc, is taken when v1(?) == 0, and falls through when v1(?) != 0.
  The `beq` branch at 0x14fcc targets 0x14fe0, is taken when s4(?) == 0, and falls through when s4(?) != 0.
  The `bne` branch at 0x14ff4 targets 0x14d00, is taken when s6(?) < 0x2 (signed), and falls through when s6(?) >= 0x2 (signed).
  The `beq` branch at 0x15008 targets 0x150d4, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0x15024 targets 0x1503c, is taken when (s0(=[a0+72]:8) & 0x1) == 0, and falls through when (s0(=[a0+72]:8) & 0x1) != 0.
  The `bltz` branch at 0x1503c targets 0x151c4, is taken when t9(=([a0+72]:8 << 0x3e)) < 0 (signed), and falls through when t9(=([a0+72]:8 << 0x3e)) >= 0 (signed).
  The `beq` branch at 0x1510c targets 0x151a4, is taken when v0(=ret(memory_present)) == 0, and falls through when v0(=ret(memory_present)) != 0.
  The `bltz` branch at 0x1511c targets 0x14f60, is taken when a2(?) < 0 (signed), and falls through when a2(?) >= 0 (signed).
  The `bne` branch at 0x15128 targets 0x14f60, is taken when a3(=0x4) != a1(?), and falls through when a3(=0x4) == a1(?).
  The `beq` branch at 0x15130 targets 0x14f70 and is always taken.
  The `bne` branch at 0x15138 targets 0x14ef0, is taken when s3(=a2) != 0, and falls through when s3(=a2) == 0.
  The `beq` branch at 0x15140 targets 0x14ef8 and is always taken.
  The `bne` branch at 0x1515c targets 0x14d5c, is taken when v0(=ret(memory_present)) != 0, and falls through when v0(=ret(memory_present)) == 0.
  The `beq` branch at 0x15164 targets 0x14ec4 and is always taken.
  The `beq` branch at 0x1516c targets 0x14db8 and is always taken.
  The `beq` branch at 0x1517c targets 0x14e0c and is always taken.
  The `beq` branch at 0x1519c targets 0x14d8c and is always taken.
  The `beq` branch at 0x151a8 targets 0x14f70 and is always taken.
  The `beq` branch at 0x151bc targets 0x14e98 and is always taken.
  The `beq` branch at 0x151d0 targets 0x15044 and is always taken.
  The return at 0x150fc has v0 = one of ?, ret(kl_perr).

- `show_hub_md_misc_error_flags` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x151d8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x151d8-0x15350 (376 bytes).
  It occupies 376 bytes.
  The `ld` at 0x15228 loads 8 bytes from ?.
  6 such `ld` accesses load 8 bytes from table(sym(pi_err_status_cmd)) +0xac0, including `ld` at 0x1526c, `ld` at 0x152a4, `ld` at 0x152c8.
  The `jal` at 0x1522c calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x15270 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=[table(sym(pi_err_status_cmd))+2752]:8, a3=?.
  The `jal` at 0x152a0 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=[table(sym(pi_err_status_cmd))+2752]:8, a3=?.
  The `jal` at 0x152c4 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=[table(sym(pi_err_status_cmd))+2752]:8, a3=?.
  The `jal` at 0x152e8 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=[table(sym(pi_err_status_cmd))+2752]:8, a3=?.
  The `jal` at 0x1530c calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=[table(sym(pi_err_status_cmd))+2752]:8, a3=?.
  The `jal` at 0x15330 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=[table(sym(pi_err_status_cmd))+2752]:8, a3=?.
  The `beq` branch at 0x1521c targets 0x15234, is taken when at(?) == 0, and falls through when at(?) != 0.
  The `bne` branch at 0x15248 targets 0x15218, is taken when s0(?) < 0x4 (unsigned), and falls through when s0(?) >= 0x4 (unsigned).
  The `beq` branch at 0x15258 targets 0x15278, is taken when (a4(?) & 0x3) == 0, and falls through when (a4(?) & 0x3) != 0.
  The `beq` branch at 0x15288 targets 0x152a8, is taken when (a4(?) & 0x3) == 0, and falls through when (a4(?) & 0x3) != 0.
  The `beq` branch at 0x152b0 targets 0x152cc, is taken when (a4(?) & 0x3) == 0, and falls through when (a4(?) & 0x3) != 0.
  The `beq` branch at 0x152d4 targets 0x152f0, is taken when (a4(?) & 0x3) == 0, and falls through when (a4(?) & 0x3) != 0.
  The `beq` branch at 0x152f8 targets 0x15314, is taken when (a4(?) & 0x3) == 0, and falls through when (a4(?) & 0x3) != 0.
  The `beq` branch at 0x15318 targets 0x1533c, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The return at 0x15348 has v0 = one of ?, ret(kl_perr).

- `show_hub_md_err` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x15350 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x15350-0x15960 (1552 bytes).
  It occupies 1552 bytes.
  The `ld` at 0x15368 loads 8 bytes from a0 (arg0 at entry) +0x8.
  The `ld` at 0x15448 loads 8 bytes from a0 (arg0 at entry) +0x18.
  3 such `ld` accesses load 8 bytes from table(sym(pi_err_status_cmd)) +0xac0, including `ld` at 0x154cc, `ld` at 0x154ec, `ld` at 0x1550c.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x28, including `ld` at 0x15524, `ld` at 0x15840.
  The `ld` at 0x155ec loads 8 bytes from ?.
  2 such `ld` accesses load 8 bytes from table(sym(pi_err_status_cmd)) +0xa60, including `ld` at 0x15644, `ld` at 0x156ec.
  The `ld` at 0x15654 loads 8 bytes from a0 (arg0 at entry) +0x38.
  The `ld` at 0x15738 loads 8 bytes from a0 (arg0 at entry) +0x40.
  The `jal` at 0x153a4 calls kl_perr with a0=0x4, a1=sym(.rodata)+7952, a2=[a0+8]:8, a3=a3 at entry (arg3).
  The `jal` at 0x153c4 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x15440 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x15474 calls kl_perr with a0=0x4, a1=sym(.rodata)+7952, a2=[a0+24]:8, a3=?.
  The `jal` at 0x15494 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x154a8 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x154c8 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=[table(sym(pi_err_status_cmd))+2752]:8, a3=?.
  The `jal` at 0x154e8 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=[table(sym(pi_err_status_cmd))+2752]:8, a3=?.
  The `jal` at 0x15508 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=[table(sym(pi_err_status_cmd))+2752]:8, a3=?.
  The `jal` at 0x1551c calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x1553c calls kl_perr with a0=0x4, a1=sym(.rodata)+7952, a2=[a0+40]:8, a3=?.
  The `jal` at 0x15550 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x15568 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?, a6=([a0+40]:8 << 0x3e).
  The `jal` at 0x15588 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x1559c calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x155b4 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x155e8 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x15604 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x15618 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x15640 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=[table(sym(pi_err_status_cmd))+2656]:8.
  The `jal` at 0x1564c calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x156b0 calls kl_perr with a0=0x4, a1=sym(.rodata)+7952, a2=[a0+56]:8, a3=?.
  The `jal` at 0x156c0 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x156e8 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=[table(sym(pi_err_status_cmd))+2656]:8.
  The `jal` at 0x156fc calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x15710 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x15724 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x1572c calls show_hub_md_misc_error_flags [0x151d8] with a0=[a0+56]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x157b8 calls kl_perr with a0=0x4, a1=sym(.rodata)+7952, a2=[a0+64]:8, a3=?.
  The `jal` at 0x157d8 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x157e0 calls show_hub_md_misc_error_flags [0x151d8] with a0=[a0+64]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x1584c calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x15864 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x1587c calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x15894 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?, a6=([a0+40]:8 << 0x3e).
  The `jal` at 0x158b0 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?, a4=0x4.
  The `jal` at 0x158cc calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?, a6=0x3.
  The `jal` at 0x158e0 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x158f0 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x15900 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x15910 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x15920 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x1593c calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?, a4=([a0+40]:8 << 0x15).
  The `beq` branch at 0x15384 targets 0x15800, is taken when s7(?) == 0, and falls through when s7(?) != 0.
  The `beq` branch at 0x153d0 targets 0x158a8, is taken when s2(?) == a4(=0x4), and falls through when s2(?) != a4(=0x4).
  The `beq` branch at 0x153dc targets 0x158a4, is taken when s2(?) == a5(=0x2), and falls through when s2(?) != a5(=0x2).
  The `beq` branch at 0x153e4 targets 0x158c4, is taken when s2(?) == a6(=0x3), and falls through when s2(?) != a6(=0x3).
  The `beq` branch at 0x153f0 targets 0x158c4, is taken when s2(?) == a7(=0x1), and falls through when s2(?) != a7(=0x1).
  The `bltz` branch at 0x153f8 targets 0x15844, is taken when s3(=([a0+8]:8 << 0x3)) < 0 (signed), and falls through when s3(=([a0+8]:8 << 0x3)) >= 0 (signed).
  The `bltz` branch at 0x15400 targets 0x1585c, is taken when s4(=([a0+8]:8 << 0x2)) < 0 (signed), and falls through when s4(=([a0+8]:8 << 0x2)) >= 0 (signed).
  The `bltz` branch at 0x15408 targets 0x15874, is taken when s5(=([a0+8]:8 << 0x1)) < 0 (signed), and falls through when s5(=([a0+8]:8 << 0x1)) >= 0 (signed).
  The `beq` branch at 0x15410 targets 0x15420, is taken when s7(?) == 0, and falls through when s7(?) != 0.
  The `bltz` branch at 0x15418 targets 0x15920, is taken when t0(=([a0+8]:8 << 0x4)) < 0 (signed), and falls through when t0(=([a0+8]:8 << 0x4)) >= 0 (signed).
  The `bltz` branch at 0x15420 targets 0x158f0, is taken when s3(=([a0+8]:8 << 0x3)) < 0 (signed), and falls through when s3(=([a0+8]:8 << 0x3)) >= 0 (signed).
  The `bltz` branch at 0x15428 targets 0x15900, is taken when s4(=([a0+8]:8 << 0x2)) < 0 (signed), and falls through when s4(=([a0+8]:8 << 0x2)) >= 0 (signed).
  The `bltz` branch at 0x15430 targets 0x15910, is taken when s5(=([a0+8]:8 << 0x1)) < 0 (signed), and falls through when s5(=([a0+8]:8 << 0x1)) >= 0 (signed).
  The `beq` branch at 0x15438 targets 0x15448, is taken when s7(?) == 0, and falls through when s7(?) != 0.
  The `beq` branch at 0x1545c targets 0x15828, is taken when (s4(?) & 0x3) == 0, and falls through when (s4(?) & 0x3) != 0.
  The `beq` branch at 0x154b0 targets 0x154d0, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `beq` branch at 0x154d0 targets 0x154f0, is taken when s3(?) == 0, and falls through when s3(?) != 0.
  The `beq` branch at 0x154f0 targets 0x15514, is taken when s4(?) == 0, and falls through when s4(?) != 0.
  The `beq` branch at 0x15514 targets 0x15524, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0x1552c targets 0x15654, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0x15548 targets 0x15558, is taken when (s1(=[a0+40]:8) & 0x1) == 0, and falls through when (s1(=[a0+40]:8) & 0x1) != 0.
  The `bltz` branch at 0x1555c targets 0x15894, is taken when a6(=([a0+40]:8 << 0x3e)) < 0 (signed), and falls through when a6(=([a0+40]:8 << 0x3e)) >= 0 (signed).
  The `beq` branch at 0x155c4 targets 0x1588c, is taken when a0(=0x1) == s3(?), and falls through when a0(=0x1) != s3(?).
  The `bltz` branch at 0x155f4 targets 0x15930, is taken when a4(=([a0+40]:8 << 0x15)) < 0 (signed), and falls through when a4(=([a0+40]:8 << 0x15)) >= 0 (signed).
  The `bne` branch at 0x1565c targets 0x156a8, is taken when a4(?) != 0, and falls through when a4(?) == 0.
  The `bne` branch at 0x15668 targets 0x156a8, is taken when (a5(?) & 0x3) != 0, and falls through when (a5(?) & 0x3) == 0.
  The `bne` branch at 0x15674 targets 0x156a8, is taken when (a6(?) & 0x3) != 0, and falls through when (a6(?) & 0x3) == 0.
  The `bne` branch at 0x15684 targets 0x156a8, is taken when (a1(?) & 0x3) != 0, and falls through when (a1(?) & 0x3) == 0.
  The `bne` branch at 0x1568c targets 0x156a8, is taken when a0(?) != 0, and falls through when a0(?) == 0.
  The `bne` branch at 0x15698 targets 0x156a8, is taken when (a2(?) & 0x3) != 0, and falls through when (a2(?) & 0x3) == 0.
  The `beq` branch at 0x156a4 targets 0x15734, is taken when (a3(?) & 0xf) == 0, and falls through when (a3(?) & 0xf) != 0.
  The `bne` branch at 0x1574c targets 0x157b0, is taken when a3(?) != 0, and falls through when a3(?) == 0.
  The `bne` branch at 0x1575c targets 0x157b4, is taken when (a4(?) & 0x3) != 0, and falls through when (a4(?) & 0x3) == 0.
  The `bne` branch at 0x1576c targets 0x157b4, is taken when (a5(?) & 0x3) != 0, and falls through when (a5(?) & 0x3) == 0.
  The `bne` branch at 0x1577c targets 0x157b4, is taken when (a6(?) & 0x3) != 0, and falls through when (a6(?) & 0x3) == 0.
  The `bne` branch at 0x15790 targets 0x157b0, is taken when (a7(?) & 0x3) != 0, and falls through when (a7(?) & 0x3) == 0.
  The `bne` branch at 0x157a0 targets 0x157b4, is taken when (t0(?) & 0x3) != 0, and falls through when (t0(?) & 0x3) == 0.
  The `beq` branch at 0x157a8 targets 0x157ec, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `bltz` branch at 0x15800 targets 0x1594c, is taken when s5(=([a0+8]:8 << 0x1)) < 0 (signed), and falls through when s5(=([a0+8]:8 << 0x1)) >= 0 (signed).
  The `bltz` branch at 0x1580c targets 0x15958, is taken when s4(=([a0+8]:8 << 0x2)) < 0 (signed), and falls through when s4(=([a0+8]:8 << 0x2)) >= 0 (signed).
  The `beq` branch at 0x15818 targets 0x15448, is taken when s3(=([a0+8]:8 << 0x3)) >= 0x0 (signed), and falls through when s3(=([a0+8]:8 << 0x3)) < 0x0 (signed).
  The `beq` branch at 0x15820 targets 0x1539c and is always taken.
  The `bne` branch at 0x1582c targets 0x1546c, is taken when s3(?) != 0, and falls through when s3(?) == 0.
  The `bne` branch at 0x15834 targets 0x15470, is taken when s2(?) != 0, and falls through when s2(?) == 0.
  The `beq` branch at 0x1583c targets 0x15528 and is always taken.
  The `bgez` branch at 0x15844 targets 0x15400, is taken when t8(=([a0+8]:8 << 0x7)) >= 0 (signed), and falls through when t8(=([a0+8]:8 << 0x7)) < 0 (signed).
  The `beq` branch at 0x15854 targets 0x15400 and is always taken.
  The `bgez` branch at 0x1585c targets 0x15408, is taken when t9(=([a0+8]:8 << 0x6)) >= 0 (signed), and falls through when t9(=([a0+8]:8 << 0x6)) < 0 (signed).
  The `beq` branch at 0x1586c targets 0x15408 and is always taken.
  The `bgez` branch at 0x15874 targets 0x15410, is taken when ra(=([a0+8]:8 << 0x5)) >= 0 (signed), and falls through when ra(=([a0+8]:8 << 0x5)) < 0 (signed).
  The `beq` branch at 0x15884 targets 0x15410 and is always taken.
  The `beq` branch at 0x1588c targets 0x155d8 and is always taken.
  The `beq` branch at 0x1589c targets 0x15574 and is always taken.
  The `beq` branch at 0x158b8 targets 0x153e4 and is always taken.
  The `beq` branch at 0x158e8 targets 0x153f8 and is always taken.
  The `beq` branch at 0x158f8 targets 0x15428 and is always taken.
  The `beq` branch at 0x15908 targets 0x15430 and is always taken.
  The `beq` branch at 0x15918 targets 0x15438 and is always taken.
  The `beq` branch at 0x15928 targets 0x15420 and is always taken.
  The `beq` branch at 0x15944 targets 0x155fc and is always taken.
  The `beq` branch at 0x15950 targets 0x15398 and is always taken.
  The `beq` branch at 0x15958 targets 0x1539c and is always taken.
  The return at 0x157f8 has v0 = one of ?, ret(show_hub_md_misc_error_flags).
  The instructions from 0x158c0 to 0x158c0 are not reached by any path from the entry, and their branches are not listed.

- `show_hub_io_ieph` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x15960 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x15960-0x15ac4 (356 bytes).
  It occupies 356 bytes.
  The `ld` at 0x15968 loads 8 bytes from a0 (arg0 at entry) +0xb8.
  The `ld` at 0x15a48 loads 8 bytes from a0 (arg0 at entry) +0xc0.
  The `jal` at 0x159ac calls kl_perr with a0=0x4, a1=sym(.rodata)+7952, a2=[a0+184]:8, a3=a3 at entry (arg3).
  The `jal` at 0x159f4 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=0x4, a4=0x5.
  The `jal` at 0x15a08 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x15a1c calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x15a30 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=sym(.rodata)+7952.
  The `jal` at 0x15a54 calls kl_perr with a0=0x4, a1=sym(.rodata)+7952, a2=[a0+192]:8, a3=?.
  The `jal` at 0x15a6c calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x15a80 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=([a0+192]:8 << 0x17).
  The `jal` at 0x15ab4 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=([a0+184]:8 << 0x17).
  The `bltz` branch at 0x1597c targets 0x1599c, is taken when at(=([a0+184]:8 << 0x13)) < 0 (signed), and falls through when at(=([a0+184]:8 << 0x13)) >= 0 (signed).
  The `beq` branch at 0x159cc targets 0x15a90, is taken when s3(?) == v1(=0x2), and falls through when s3(?) != v1(=0x2).
  The `beq` branch at 0x159d4 targets 0x15a98, is taken when s3(?) == a2(=0x3), and falls through when s3(?) != a2(=0x3).
  The `beq` branch at 0x159dc targets 0x15aa0, is taken when s3(?) == a3(=0x4), and falls through when s3(?) != a3(=0x4).
  The `beq` branch at 0x159e4 targets 0x15aa8, is taken when s3(?) == a4(=0x5), and falls through when s3(?) != a4(=0x5).
  The `bltz` branch at 0x15a3c targets 0x15ab0, is taken when a3(=([a0+184]:8 << 0x17)) < 0 (signed), and falls through when a3(=([a0+184]:8 << 0x17)) >= 0 (signed).
  The `bgez` branch at 0x15a78 targets 0x15984, is taken when a3(=([a0+192]:8 << 0x17)) >= 0 (signed), and falls through when a3(=([a0+192]:8 << 0x17)) < 0 (signed).
  The `beq` branch at 0x15a88 targets 0x15988 and is always taken.
  The `beq` branch at 0x15a90 targets 0x159ec and is always taken.
  The `beq` branch at 0x15a98 targets 0x159ec and is always taken.
  The `beq` branch at 0x15aa0 targets 0x159ec and is always taken.
  The `beq` branch at 0x15aa8 targets 0x159ec and is always taken.
  The `beq` branch at 0x15abc targets 0x15a48 and is always taken.
  The return at 0x15994 has v0 = one of ?, ret(kl_perr).

- `show_hub_io_err` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x15ac4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x15ac4-0x15e74 (944 bytes).
  It occupies 944 bytes.
  10 such `ld` accesses load 8 bytes from ?, including `ld` at 0x15af0, `ld` at 0x15b30, `ld` at 0x15b54.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x4f4, including `lw` at 0x15c08, `lw` at 0x15d88.
  The `jal` at 0x15b6c calls kl_perr with a0=0x4, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x15b7c calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x15b88 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x15b98 calls kl_perr with a0=0x14, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x15ba8 calls kl_perr with a0=0x14, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x15bc4 calls kl_perr with a0=0x4, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x15bd4 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x15be0 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x15bf0 calls kl_perr with a0=0x14, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x15c00 calls kl_perr with a0=0x14, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x15c48 calls kl_perr with a0=0x4, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x15c84 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x15cb8 calls show_hub_io_ieph with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x15cd8 calls kl_perr with a0=0x4, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x15cf0 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x15d18 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x15d2c calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x15d40 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x15d74 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x15d80 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x15db4 calls kl_perr with a0=0x14, a1=sym(.rodata)+7952, a2=?, a3=?, a5=[a0+1268].
  The `jal` at 0x15dc4 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x15dd4 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x15de8 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x15dfc calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x15e14 calls kl_perr with a0=0x4, a1=sym(.rodata)+7952, a2=?, a3=a3 at entry (arg3).
  The `jal` at 0x15e20 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x15e30 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x15e40 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x15e50 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x15e64 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `beq` branch at 0x15ae4 targets 0x15af0, is taken when (a1 & 0x1) == 0, and falls through when (a1 & 0x1) != 0.
  The `bltz` branch at 0x15b04 targets 0x15e0c, is taken when v0(?) < 0 (signed), and falls through when v0(?) >= 0 (signed).
  The `bltz` branch at 0x15b38 targets 0x15cd0, is taken when t8(?) < 0 (signed), and falls through when t8(?) >= 0 (signed).
  The `bne` branch at 0x15b4c targets 0x15b30, is taken when s0(?) < 0xf (signed), and falls through when s0(?) >= 0xf (signed).
  The `bgez` branch at 0x15b5c targets 0x15bb0, is taken when t9(?) >= 0 (signed), and falls through when t9(?) < 0 (signed).
  The `beq` branch at 0x15bb8 targets 0x15c08, is taken when (s2(=0x10000) & s0(?)) == 0, and falls through when (s2(=0x10000) & s0(?)) != 0.
  The `beq` branch at 0x15c20 targets 0x15c9c, is taken when a2(=[a0+1268]) == a3(=-0x1), and falls through when a2(=[a0+1268]) != a3(=-0x1).
  The `bltz` branch at 0x15c54 targets 0x15dc4, is taken when t8(?) < 0 (signed), and falls through when t8(?) >= 0 (signed).
  The `bltz` branch at 0x15c60 targets 0x15dd4, is taken when t9(?) < 0 (signed), and falls through when t9(?) >= 0 (signed).
  The `bltz` branch at 0x15c6c targets 0x15de4, is taken when ra(?) < 0 (signed), and falls through when ra(?) >= 0 (signed).
  The `bltz` branch at 0x15c74 targets 0x15df8, is taken when at(?) < 0 (signed), and falls through when at(?) >= 0 (signed).
  The `beq` branch at 0x15c7c targets 0x15c8c, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `bne` branch at 0x15c94 targets 0x15c30, is taken when s2(?) < 0x9 (signed), and falls through when s2(?) >= 0x9 (signed).
  The `beq` branch at 0x15ce4 targets 0x15cfc, is taken when (s2(?) & 0x1) == 0, and falls through when (s2(?) & 0x1) != 0.
  The `bltz` branch at 0x15cfc targets 0x15e30, is taken when a1(?) < 0 (signed), and falls through when a1(?) >= 0 (signed).
  The `bltz` branch at 0x15d4c targets 0x15e40, is taken when a3(?) < 0 (signed), and falls through when a3(?) >= 0 (signed).
  The `bltz` branch at 0x15d58 targets 0x15e50, is taken when a4(?) < 0 (signed), and falls through when a4(?) >= 0 (signed).
  The `bltz` branch at 0x15d64 targets 0x15e60, is taken when a5(?) < 0 (signed), and falls through when a5(?) >= 0 (signed).
  The `beq` branch at 0x15d90 targets 0x15b40, is taken when a5(=[a0+1268]) == a3(=-0x1), and falls through when a5(=[a0+1268]) != a3(=-0x1).
  The `beq` branch at 0x15dbc targets 0x15b44 and is always taken.
  The `beq` branch at 0x15dcc targets 0x15c60 and is always taken.
  The `beq` branch at 0x15ddc targets 0x15c6c and is always taken.
  The `beq` branch at 0x15df0 targets 0x15c74 and is always taken.
  The `beq` branch at 0x15e04 targets 0x15c7c and is always taken.
  The `beq` branch at 0x15e28 targets 0x15b10 and is always taken.
  The `beq` branch at 0x15e38 targets 0x15d08 and is always taken.
  The `beq` branch at 0x15e48 targets 0x15d58 and is always taken.
  The `beq` branch at 0x15e58 targets 0x15d64 and is always taken.
  The `beq` branch at 0x15e6c targets 0x15d6c and is always taken.
  The return at 0x15cc8 has v0 = ret(show_hub_io_ieph).

- `show_hub_ni_err` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x15f28 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x15f28-0x162b0 (904 bytes).
  It occupies 904 bytes.
  The `ld` at 0x15f40 loads 8 bytes from a0 (arg0 at entry) +0x8.
  The `ld` at 0x15fdc loads 8 bytes from ?.
  The `ld` at 0x16004 loads 8 bytes from a0 (arg0 at entry) +0x10.
  The `ld` at 0x160a0 loads 8 bytes from table(sym(pi_err_status_cmd)) +0xbc8.
  The `ld` at 0x160c0 loads 8 bytes from a0 (arg0 at entry) +0x18.
  2 such `ld` accesses load 8 bytes from table(sym(pi_err_status_cmd)) +0xa60, including `ld` at 0x160f8, `ld` at 0x16120.
  The `ld` at 0x16178 loads 8 bytes from a0 (arg0 at entry) +0x20.
  The `jal` at 0x15f64 calls kl_perr with a0=0x4, a1=sym(.rodata)+7952, a2=[a0+8]:8, a3=a3 at entry (arg3).
  The `jal` at 0x15f78 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x15f90 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x15fa8 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x15fe0 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x16014 calls kl_perr with a0=0x4, a1=sym(.rodata)+7952, a2=[a0+16]:8, a3=?.
  The `jal` at 0x1602c calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x16040 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x16054 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x16068 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x1607c calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x1609c calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=[table(sym(pi_err_status_cmd))+3016]:8, a3=?.
  The `jal` at 0x160b8 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=0x7ffffff.
  The `jal` at 0x160d0 calls kl_perr with a0=0x4, a1=sym(.rodata)+7952, a2=[a0+24]:8, a3=?.
  The `jal` at 0x160f4 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=[table(sym(pi_err_status_cmd))+2656]:8.
  The `jal` at 0x1611c calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=[table(sym(pi_err_status_cmd))+2656]:8.
  The `jal` at 0x16134 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x16170 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?, a6=0x7ffffff.
  The `jal` at 0x1618c calls kl_perr with a0=0x4, a1=sym(.rodata)+7952, a2=[a0+32]:8, a3=?.
  The `jal` at 0x161a4 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?, a7=([a0+32]:8 << 0x30).
  The `jal` at 0x161e4 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x16218 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?, a7=([a0+32]:8 << 0x30).
  The `jal` at 0x1622c calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x1623c calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x16250 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x16264 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x16278 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x1628c calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x162a0 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `beq` branch at 0x15f50 targets 0x161ec, is taken when s4(=[a0+8]:8) == 0, and falls through when s4(=[a0+8]:8) != 0.
  The `beq` branch at 0x15f70 targets 0x15f80, is taken when (s4(=[a0+8]:8) & 0xff) == 0, and falls through when (s4(=[a0+8]:8) & 0xff) != 0.
  The `beq` branch at 0x15f88 targets 0x15f98, is taken when (a2(?) & 0xff) == 0, and falls through when (a2(?) & 0xff) != 0.
  The `beq` branch at 0x15fa0 targets 0x15fb0, is taken when (a2(?) & 0xff) == 0, and falls through when (a2(?) & 0xff) != 0.
  The `beq` branch at 0x15fd0 targets 0x15fe8, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `bne` branch at 0x15ffc targets 0x15fd0, is taken when s1(?) < 0x1d (unsigned), and falls through when s1(?) >= 0x1d (unsigned).
  The `beq` branch at 0x16008 targets 0x160c0, is taken when s1(=[a0+16]:8) == 0, and falls through when s1(=[a0+16]:8) != 0.
  The `beq` branch at 0x16020 targets 0x16038, is taken when (s1(=[a0+16]:8) & 0x1) == 0, and falls through when (s1(=[a0+16]:8) & 0x1) != 0.
  The `beq` branch at 0x160c4 targets 0x16178, is taken when s2(=[a0+24]:8) == 0, and falls through when s2(=[a0+24]:8) != 0.
  The `beq` branch at 0x1617c targets 0x161f0, is taken when s1(=[a0+32]:8) == 0, and falls through when s1(=[a0+32]:8) != 0.
  The `bltz` branch at 0x16198 targets 0x16214, is taken when a7(=([a0+32]:8 << 0x30)) < 0 (signed), and falls through when a7(=([a0+32]:8 << 0x30)) >= 0 (signed).
  The `bltz` branch at 0x161b0 targets 0x16228, is taken when t0(=([a0+32]:8 << 0x37)) < 0 (signed), and falls through when t0(=([a0+32]:8 << 0x37)) >= 0 (signed).
  The `bltz` branch at 0x161b8 targets 0x1623c, is taken when t1(=([a0+32]:8 << 0x36)) < 0 (signed), and falls through when t1(=([a0+32]:8 << 0x36)) >= 0 (signed).
  The `bltz` branch at 0x161c4 targets 0x1624c, is taken when t2(=([a0+32]:8 << 0x35)) < 0 (signed), and falls through when t2(=([a0+32]:8 << 0x35)) >= 0 (signed).
  The `bltz` branch at 0x161cc targets 0x16260, is taken when t3(=([a0+32]:8 << 0x34)) < 0 (signed), and falls through when t3(=([a0+32]:8 << 0x34)) >= 0 (signed).
  The `bltz` branch at 0x161d4 targets 0x16274, is taken when t8(=([a0+32]:8 << 0x33)) < 0 (signed), and falls through when t8(=([a0+32]:8 << 0x33)) >= 0 (signed).
  The `beq` branch at 0x16220 targets 0x161f0 and is always taken.
  The `beq` branch at 0x16234 targets 0x161b8 and is always taken.
  The `beq` branch at 0x16244 targets 0x161c4 and is always taken.
  The `beq` branch at 0x16258 targets 0x161cc and is always taken.
  The `beq` branch at 0x1626c targets 0x161d4 and is always taken.
  The `beq` branch at 0x162a8 targets 0x161dc and is always taken.
  The return at 0x1620c has v0 = one of ret(kl_perr), ?.

- `show_hub_lb_err` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x162b0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x162b0-0x164b0 (512 bytes).
  It occupies 512 bytes.
  The `ld` at 0x162c0 loads 8 bytes from a0 (arg0 at entry) +0x8.
  The `ld` at 0x16314 loads 8 bytes from ?.
  The `ld` at 0x16334 loads 8 bytes from a0 (arg0 at entry) +0x10.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x28, including `ld` at 0x16348, `ld` at 0x1649c.
  The `ld` at 0x1638c loads 8 bytes from table(sym(pi_err_status_cmd)) +0xc48.
  2 such `ld` accesses load 8 bytes from table(sym(pi_err_status_cmd)) +0xa60, including `ld` at 0x163f4, `ld` at 0x1641c.
  The `ld` at 0x1643c loads 8 bytes from table(sym(pi_err_status_cmd)) +0xc68.
  The `ld` at 0x16458 loads 8 bytes from a0 (arg0 at entry) +0x18.
  The `ld` at 0x1648c loads 8 bytes from a0 (arg0 at entry) +0x20.
  The `jal` at 0x162e4 calls kl_perr with a0=0x4, a1=sym(.rodata)+7952, a2=[a0+8]:8, a3=a3 at entry (arg3).
  The `jal` at 0x16318 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x1636c calls kl_perr with a0=0x4, a1=sym(.rodata)+7952, a2=[a0+40]:8, a3=?.
  The `jal` at 0x16388 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=[table(sym(pi_err_status_cmd))+3144]:8, a3=?.
  The `jal` at 0x163b8 calls kl_perr with a0=0x4, a1=sym(.rodata)+7952, a2=[a0+16]:8, a3=([a0+16]:8 << 0x13).
  The `jal` at 0x163c8 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x163f0 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=[table(sym(pi_err_status_cmd))+2656]:8.
  The `jal` at 0x16418 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=[table(sym(pi_err_status_cmd))+2656]:8.
  The `jal` at 0x16438 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=[table(sym(pi_err_status_cmd))+3176]:8, a3=?.
  The `jal` at 0x16450 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x16464 calls kl_perr with a0=0x4, a1=sym(.rodata)+7952, a2=[a0+24]:8, a3=?.
  The `jal` at 0x16480 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x16490 calls kl_perr with a0=0x14, a1=sym(.rodata)+7952, a2=[a0+32]:8, a3=?.
  The `jal` at 0x164a0 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=([a0+16]:8 << 0x17).
  The `beq` branch at 0x162d0 targets 0x16334, is taken when s1(=[a0+8]:8) == 0, and falls through when s1(=[a0+8]:8) != 0.
  The `beq` branch at 0x16308 targets 0x16320, is taken when (s1(=[a0+8]:8) & a2(?)) == 0, and falls through when (s1(=[a0+8]:8) & a2(?)) != 0.
  The `bne` branch at 0x1632c targets 0x16300, is taken when s0(?) < 0xb (signed), and falls through when s0(?) >= 0xb (signed).
  The `bltz` branch at 0x16340 targets 0x163b0, is taken when a3(=([a0+16]:8 << 0x13)) < 0 (signed), and falls through when a3(=([a0+16]:8 << 0x13)) >= 0 (signed).
  The `beq` branch at 0x16358 targets 0x16390, is taken when (s1(=[a0+40]:8) & a4(=0x8000000000000000)) == 0, and falls through when (s1(=[a0+40]:8) & a4(=0x8000000000000000)) != 0.
  The `beq` branch at 0x16360 targets 0x16390, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `bltz` branch at 0x16444 targets 0x164a0, is taken when a3(=([a0+16]:8 << 0x17)) < 0 (signed), and falls through when a3(=([a0+16]:8 << 0x17)) >= 0 (signed).
  The `beq` branch at 0x16498 targets 0x1634c and is always taken.
  The `beq` branch at 0x164a8 targets 0x16450 and is always taken.
  The return at 0x163a8 has v0 = one of ?, ret(kl_perr).

- `show_hub_xb_err` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x164b0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x164b0-0x166c4 (532 bytes).
  It occupies 532 bytes.
  The `ld` at 0x164b8 loads 8 bytes from a0 (arg0 at entry) +0x8.
  The `ld` at 0x16514 loads 8 bytes from table(sym(pi_err_status_cmd)) +0xce8.
  2 such `ld` accesses load 8 bytes from table(sym(pi_err_status_cmd)) +0xd68, including `ld` at 0x1654c, `ld` at 0x1657c.
  The `ld` at 0x16570 loads 8 bytes from a0 (arg0 at entry) +0x10.
  The `ld` at 0x165a4 loads 8 bytes from table(sym(.rodata)+7952) +0x0.
  The `jal` at 0x164f0 calls kl_perr with a0=0x4, a1=sym(.rodata)+7952, a2=[a0+8]:8, a3=a3 at entry (arg3).
  The `jal` at 0x16510 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=[table(sym(pi_err_status_cmd))+3304]:8, a3=?.
  The `jal` at 0x16524 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x16554 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=[table(sym(pi_err_status_cmd))+3432]:8, a4=table(sym(pi_err_status_cmd))+3432.
  The `jal` at 0x16560 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x16580 calls kl_perr with a0=0x4, a1=sym(.rodata)+7952, a2=[table(sym(pi_err_status_cmd))+3432]:8, a3=[a0+16]:8.
  The `jal` at 0x165b0 calls printf with a0=sym(.rodata)+7952, a1=?, a2=?, a3=?.
  The `jal` at 0x165b8 calls printf with a0=sym(.rodata)+7952, a1=?, a2=?, a3=?.
  The `bltz` branch at 0x164c8 targets 0x164e4, is taken when at(=([a0+8]:8 << 0x33)) < 0 (signed), and falls through when at(=([a0+8]:8 << 0x33)) >= 0 (signed).
  The `beq` branch at 0x1659c targets 0x165b0, is taken when a1(?) >= 0x10 (unsigned), and falls through when a1(?) < 0x10 (unsigned).
  The `beq` branch at 0x165c0 targets 0x164d4 and is always taken.
  The return at 0x164dc has v0 = one of ?, ret(printf).
  The instructions from 0x165c8 to 0x166c0 are not reached by any path from the entry, and their branches are not listed.
  The indirect jump at 0x165a8 uses a jump table whose successors are unresolved.

- `show_bridge_err` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x16800 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x16800-0x16e68 (1640 bytes).
  It occupies 1640 bytes.
  The `lw` at 0x16810 loads 4 bytes from a1 (arg1 at entry) +0xc.
  2 such `ld` accesses load 8 bytes from (a0 + one of 0x30, 0xb8) +0x0, including `ld` at 0x16838, `ld` at 0x16870.
  8 such `lw` accesses load 4 bytes from (a0 + one of 0x38, 0xc0) +0x0, including `lw` at 0x16860, `lw` at 0x16a1c, `lw` at 0x16b58.
  The `ld` at 0x168d4 loads 8 bytes from (a0 + one of 0x68, 0xf0) +0x0.
  The `ld` at 0x168e4 loads 8 bytes from (a0 + one of 0x70, 0xf8) +0x0.
  The `ld` at 0x168f4 loads 8 bytes from (a0 + one of 0x78, 0x100) +0x0.
  The `ld` at 0x16904 loads 8 bytes from (a0 + one of 0x80, 0x108) +0x0.
  The `ld` at 0x16914 loads 8 bytes from (a0 + one of 0x88, 0x110) +0x0.
  The `ld` at 0x16948 loads 8 bytes from ?.
  2 such `lw` accesses load 4 bytes from (a0 + one of 0x20, 0xa8) +0x0, including `lw` at 0x16a28, `lw` at 0x16cac.
  The `lw` at 0x16b00 loads 4 bytes from (a0 + one of 0x24, 0xac) +0x0.
  The `lw` at 0x16b10 loads 4 bytes from (a0 + one of 0x28, 0xb0) +0x0.
  3 such `lw` accesses load 4 bytes from (a0 + one of 0x10, 0x98) +0x0, including `lw` at 0x16b60, `lw` at 0x16d18, `lw` at 0x16e0c.
  2 such `lw` accesses load 4 bytes from (a0 + one of 0x3c, 0xc4) +0x0, including `lw` at 0x16b78, `lw` at 0x16dc4.
  3 such `ld` accesses load 8 bytes from (a0 + one of 0x58, 0xe0) +0x0, including `ld` at 0x16b84, `ld` at 0x16cd8, `ld` at 0x16dd0.
  3 such `ld` accesses load 8 bytes from (a0 + one of 0x60, 0xe8) +0x0, including `ld` at 0x16b94, `ld` at 0x16ce8, `ld` at 0x16de0.
  The `ld` at 0x16be8 loads 8 bytes from (a0 + one of 0x50, 0xd8) +0x0.
  2 such `lw` accesses load 4 bytes from (a0 + one of 0x14, 0x9c) +0x0, including `lw` at 0x16c4c, `lw` at 0x16dac.
  2 such `ld` accesses load 8 bytes from (a0 + one of 0x48, 0xd0) +0x0, including `ld` at 0x16c5c, `ld` at 0x16d60.
  2 such `lw` accesses load 4 bytes from (a0 + one of 0x18, 0xa0) +0x0, including `lw` at 0x16c80, `lw` at 0x16e44.
  2 such `lw` accesses load 4 bytes from (a0 + one of 0x1c, 0xa4) +0x0, including `lw` at 0x16c90, `lw` at 0x16e54.
  2 such `lw` accesses load 4 bytes from (a0 + one of 0x8, 0x90) +0x0, including `lw` at 0x16d28, `lw` at 0x16e1c.
  2 such `lw` accesses load 4 bytes from (a0 + one of 0xc, 0x94) +0x0, including `lw` at 0x16d38, `lw` at 0x16e2c.
  The `lw` at 0x16df8 loads 4 bytes from (a0 + one of 0x40, 0xc8) +0x0.
  The `jal` at 0x16868 calls kl_perr with a0=0x3, a1=sym(.rodata)+7952, a2=[(a0 + one of 0x38, 0xc0)], a3=0x20.
  The `jal` at 0x16880 calls kl_perr with a0=0x4, a1=sym(.rodata)+7952, a2=[(a0 + one of 0x30, 0xb8)]:8, a3=?.
  The `jal` at 0x16890 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x168d8 calls kl_perr with a0=0x14, a1=sym(.rodata)+7952, a2=[(a0 + one of 0x68, 0xf0)]:8, a3=0x80000000000.
  The `jal` at 0x168e8 calls kl_perr with a0=0x14, a1=sym(.rodata)+7952, a2=[(a0 + one of 0x70, 0xf8)]:8, a3=?.
  The `jal` at 0x168f8 calls kl_perr with a0=0x14, a1=sym(.rodata)+7952, a2=[(a0 + one of 0x78, 0x100)]:8, a3=?.
  The `jal` at 0x16908 calls kl_perr with a0=0x14, a1=sym(.rodata)+7952, a2=[(a0 + one of 0x80, 0x108)]:8, a3=?.
  The `jal` at 0x16918 calls kl_perr with a0=0x14, a1=sym(.rodata)+7952, a2=[(a0 + one of 0x88, 0x110)]:8, a3=?.
  The `jal` at 0x1694c calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x16a2c calls kl_perr with a0=0x14, a1=sym(.rodata)+7952, a2=[(a0 + one of 0x20, 0xa8)], a3=?, a7=[(a0 + one of 0x38, 0xc0)].
  The `jal` at 0x16b04 calls kl_perr with a0=0x14, a1=sym(.rodata)+7952, a2=[(a0 + one of 0x24, 0xac)], a3=?.
  The `jal` at 0x16b14 calls kl_perr with a0=0x14, a1=sym(.rodata)+7952, a2=[(a0 + one of 0x28, 0xb0)], a3=?.
  The `jal` at 0x16b64 calls kl_perr with a0=0x14, a1=sym(.rodata)+7952, a2=[(a0 + one of 0x10, 0x98)], a3=?, a4=0x1.
  The `jal` at 0x16b88 calls kl_perr with a0=0x14, a1=sym(.rodata)+7952, a2=[(a0 + one of 0x58, 0xe0)]:8, a3=?.
  The `jal` at 0x16b98 calls kl_perr with a0=0x14, a1=sym(.rodata)+7952, a2=[(a0 + one of 0x60, 0xe8)]:8, a3=?.
  The `jal` at 0x16bec calls kl_perr with a0=0x14, a1=sym(.rodata)+7952, a2=[(a0 + one of 0x50, 0xd8)]:8, a3=?.
  The `jal` at 0x16c50 calls kl_perr with a0=0x14, a1=sym(.rodata)+7952, a2=[(a0 + one of 0x14, 0x9c)], a3=?.
  The `jal` at 0x16c60 calls kl_perr with a0=0x14, a1=sym(.rodata)+7952, a2=[(a0 + one of 0x48, 0xd0)]:8, a3=?.
  The `jal` at 0x16c84 calls kl_perr with a0=0x14, a1=sym(.rodata)+7952, a2=[(a0 + one of 0x18, 0xa0)], a3=?.
  The `jal` at 0x16c94 calls kl_perr with a0=0x14, a1=sym(.rodata)+7952, a2=[(a0 + one of 0x1c, 0xa4)], a3=?.
  The `jal` at 0x16cb0 calls kl_perr with a0=0x14, a1=sym(.rodata)+7952, a2=[(a0 + one of 0x20, 0xa8)], a3=?.
  The `jal` at 0x16cdc calls kl_perr with a0=0x14, a1=sym(.rodata)+7952, a2=[(a0 + one of 0x58, 0xe0)]:8, a3=?.
  The `jal` at 0x16cec calls kl_perr with a0=0x14, a1=sym(.rodata)+7952, a2=[(a0 + one of 0x60, 0xe8)]:8, a3=?.
  The `jal` at 0x16d1c calls kl_perr with a0=0x14, a1=sym(.rodata)+7952, a2=[(a0 + one of 0x10, 0x98)], a3=?.
  The `jal` at 0x16d2c calls kl_perr with a0=0x14, a1=sym(.rodata)+7952, a2=[(a0 + one of 0x8, 0x90)], a3=?.
  The `jal` at 0x16d3c calls kl_perr with a0=0x14, a1=sym(.rodata)+7952, a2=[(a0 + one of 0xc, 0x94)], a3=?.
  The `jal` at 0x16d64 calls kl_perr with a0=0x14, a1=sym(.rodata)+7952, a2=[(a0 + one of 0x48, 0xd0)]:8, a3=?.
  The `jal` at 0x16db0 calls kl_perr with a0=0x14, a1=sym(.rodata)+7952, a2=[(a0 + one of 0x14, 0x9c)], a3=?, a4=0x4000000, a5=[(a0 + one of 0x38, 0xc0)].
  The `jal` at 0x16dd4 calls kl_perr with a0=0x14, a1=sym(.rodata)+7952, a2=[(a0 + one of 0x58, 0xe0)]:8, a3=?, a6=[(a0 + one of 0x3c, 0xc4)].
  The `jal` at 0x16de4 calls kl_perr with a0=0x14, a1=sym(.rodata)+7952, a2=[(a0 + one of 0x60, 0xe8)]:8, a3=?.
  The `jal` at 0x16dfc calls kl_perr with a0=0x14, a1=sym(.rodata)+7952, a2=[(a0 + one of 0x40, 0xc8)], a3=?.
  The `jal` at 0x16e10 calls kl_perr with a0=0x14, a1=sym(.rodata)+7952, a2=[(a0 + one of 0x10, 0x98)], a3=?.
  The `jal` at 0x16e20 calls kl_perr with a0=0x14, a1=sym(.rodata)+7952, a2=[(a0 + one of 0x8, 0x90)], a3=?.
  The `jal` at 0x16e30 calls kl_perr with a0=0x14, a1=sym(.rodata)+7952, a2=[(a0 + one of 0xc, 0x94)], a3=?.
  The `jal` at 0x16e48 calls kl_perr with a0=0x14, a1=sym(.rodata)+7952, a2=[(a0 + one of 0x18, 0xa0)], a3=?.
  The `jal` at 0x16e58 calls kl_perr with a0=0x14, a1=sym(.rodata)+7952, a2=[(a0 + one of 0x1c, 0xa4)], a3=?.
  The `beq` branch at 0x16828 targets 0x16834, is taken when (at(=[a1+12]) & 0x1) == 0, and falls through when (at(=[a1+12]) & 0x1) != 0.
  The `beq` branch at 0x16848 targets 0x16bfc, is taken when (v0(=[(a0 + one of 0x30, 0xb8)]:8) & v1(=0xffffffff7fffff00)) == 0, and falls through when (v0(=[(a0 + one of 0x30, 0xb8)]:8) & v1(=0xffffffff7fffff00)) != 0.
  The `beq` branch at 0x16874 targets 0x16bfc, is taken when s4(=[(a0 + one of 0x30, 0xb8)]:8) == 0, and falls through when s4(=[(a0 + one of 0x30, 0xb8)]:8) != 0.
  The `bne` branch at 0x168a8 targets 0x16bfc, is taken when s5(=one of 0x20, 0x2d) < 0x9 (signed), and falls through when s5(=one of 0x20, 0x2d) >= 0x9 (signed).
  The `beq` branch at 0x168b0 targets 0x16930 and is always taken.
  The `beq` branch at 0x168bc targets 0x168d4, is taken when t0(=0x100000000000) >= s0(?) (unsigned), and falls through when t0(=0x100000000000) < s0(?) (unsigned).
  The `bne` branch at 0x168cc targets 0x16920, is taken when t1(=0x200000000000) != s0(?), and falls through when t1(=0x200000000000) == s0(?).
  The `beq` branch at 0x16928 targets 0x16bfc, is taken when s1(?) >= s5(=one of 0x20, 0x2d) (signed), and falls through when s1(?) < s5(=one of 0x20, 0x2d) (signed).
  The `beq` branch at 0x1693c targets 0x16920, is taken when (s4(=[(a0 + one of 0x30, 0xb8)]:8) & s0(?)) == 0, and falls through when (s4(=[(a0 + one of 0x30, 0xb8)]:8) & s0(?)) != 0.
  The `bne` branch at 0x16958 targets 0x169e0, is taken when s0(?) < s3(=0x20000000) (unsigned), and falls through when s0(?) >= s3(=0x20000000) (unsigned).
  The `beq` branch at 0x16960 targets 0x16b5c, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `bne` branch at 0x16970 targets 0x16a84, is taken when s0(?) < a4(=0x4000000000) (unsigned), and falls through when s0(?) >= a4(=0x4000000000) (unsigned).
  The `beq` branch at 0x169a0 targets 0x168f0, is taken when a1(=0x4000000000) >= s0(?) (unsigned), and falls through when a1(=0x4000000000) < s0(?) (unsigned).
  The `bne` branch at 0x169bc targets 0x16bcc, is taken when s0(?) < a5(=0x40000000000) (unsigned), and falls through when s0(?) >= a5(=0x40000000000) (unsigned).
  The `beq` branch at 0x169c4 targets 0x168f0, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `bne` branch at 0x169cc targets 0x16d84, is taken when a4(?) != 0, and falls through when a4(?) == 0.
  The `beq` branch at 0x169d8 targets 0x168b8 and is always taken.
  The `bne` branch at 0x169e8 targets 0x16a3c, is taken when s0(?) < a6(=0x10000) (unsigned), and falls through when s0(?) >= a6(=0x10000) (unsigned).
  The `bne` branch at 0x16a14 targets 0x16b24, is taken when a6(=0x10000) < s0(?) (unsigned), and falls through when a6(=0x10000) >= s0(?) (unsigned).
  The `bne` branch at 0x16a20 targets 0x16920, is taken when a7(=[(a0 + one of 0x38, 0xc0)]) != 0, and falls through when a7(=[(a0 + one of 0x38, 0xc0)]) == 0.
  The `beq` branch at 0x16a34 targets 0x16924 and is always taken.
  The `bne` branch at 0x16a54 targets 0x16ae8, is taken when s0(?) < 0x1000 (unsigned), and falls through when s0(?) >= 0x1000 (unsigned).
  The `bne` branch at 0x16a5c targets 0x16b00, is taken when a2(?) != 0, and falls through when a2(?) == 0.
  The `bne` branch at 0x16a64 targets 0x16cc0, is taken when a3(?) != 0, and falls through when a3(?) == 0.
  The `bne` branch at 0x16a6c targets 0x16afc, is taken when a6(?) != 0, and falls through when a6(?) == 0.
  The `bne` branch at 0x16a74 targets 0x16920, is taken when t1(=0x8000) != s0(?), and falls through when t1(=0x8000) == s0(?).
  The `beq` branch at 0x16a7c targets 0x16b00 and is always taken.
  The `bne` branch at 0x16ab0 targets 0x16ba8, is taken when s0(?) < a6(=0x400000000) (unsigned), and falls through when s0(?) >= a6(=0x400000000) (unsigned).
  The `beq` branch at 0x16ab8 targets 0x168f4, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `bne` branch at 0x16ac0 targets 0x16cfc, is taken when a3(?) != 0, and falls through when a3(?) == 0.
  The `beq` branch at 0x16ac8 targets 0x168f4, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `bne` branch at 0x16ad8 targets 0x16920, is taken when a5(=0x2000000000) != s0(?), and falls through when a5(=0x2000000000) == s0(?).
  The `beq` branch at 0x16ae0 targets 0x168f4 and is always taken.
  The `bne` branch at 0x16ae8 targets 0x16c70, is taken when a0(?) != 0, and falls through when a0(?) == 0.
  The `bne` branch at 0x16af0 targets 0x16afc, is taken when a5(?) != 0, and falls through when a5(?) == 0.
  The `bne` branch at 0x16af8 targets 0x16920, is taken when a6(=0x800) != s0(?), and falls through when a6(=0x800) == s0(?).
  The `beq` branch at 0x16b1c targets 0x16924 and is always taken.
  The `bne` branch at 0x16b2c targets 0x16c2c, is taken when a0(?) != 0, and falls through when a0(?) == 0.
  The `beq` branch at 0x16b34 targets 0x16d18, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `bne` branch at 0x16b3c targets 0x16d94, is taken when a3(?) != 0, and falls through when a3(?) == 0.
  The `beq` branch at 0x16b44 targets 0x16d14, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `bne` branch at 0x16b4c targets 0x16920, is taken when a7(=0x10000000) != s0(?), and falls through when a7(=0x10000000) == s0(?).
  The `beq` branch at 0x16b54 targets 0x16da0 and is always taken.
  The `beq` branch at 0x16b70 targets 0x16920, is taken when t0(=[(a0 + one of 0x38, 0xc0)]) == 0, and falls through when t0(=[(a0 + one of 0x38, 0xc0)]) != 0.
  The `beq` branch at 0x16b7c targets 0x16920, is taken when t1(=[(a0 + one of 0x3c, 0xc4)]) == 0, and falls through when t1(=[(a0 + one of 0x3c, 0xc4)]) != 0.
  The `beq` branch at 0x16ba0 targets 0x16924 and is always taken.
  The `bne` branch at 0x16ba8 targets 0x16ca4, is taken when a0(?) != 0, and falls through when a0(?) == 0.
  The `beq` branch at 0x16bb0 targets 0x168f0, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `bne` branch at 0x16bbc targets 0x16920, is taken when t2(=0x200000000) != s0(?), and falls through when t2(=0x200000000) == s0(?).
  The `beq` branch at 0x16bc4 targets 0x168f4 and is always taken.
  The `bne` branch at 0x16bcc targets 0x16cd0, is taken when a0(?) != 0, and falls through when a0(?) == 0.
  The `beq` branch at 0x16bd4 targets 0x16df4, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `bne` branch at 0x16be0 targets 0x16920, is taken when t3(=0x20000000000) != s0(?), and falls through when t3(=0x20000000000) == s0(?).
  The `beq` branch at 0x16bf4 targets 0x16924 and is always taken.
  The `bne` branch at 0x16c2c targets 0x16d4c, is taken when a6(?) != 0, and falls through when a6(?) == 0.
  The `bne` branch at 0x16c34 targets 0x16d10, is taken when a4(?) != 0, and falls through when a4(?) == 0.
  The `beq` branch at 0x16c40 targets 0x16e0c, is taken when t8(=[(a0 + one of 0x38, 0xc0)]) == 0, and falls through when t8(=[(a0 + one of 0x38, 0xc0)]) != 0.
  The `beq` branch at 0x16c68 targets 0x16924 and is always taken.
  The `bne` branch at 0x16c70 targets 0x16d74, is taken when a4(?) != 0, and falls through when a4(?) == 0.
  The `beq` branch at 0x16c78 targets 0x16920, is taken when a7(?) == 0, and falls through when a7(?) != 0.
  The `beq` branch at 0x16c9c targets 0x16924 and is always taken.
  The `bne` branch at 0x16ca4 targets 0x16920, is taken when t9(=0x40000000) != s0(?), and falls through when t9(=0x40000000) == s0(?).
  The `beq` branch at 0x16cb8 targets 0x16924 and is always taken.
  The `bne` branch at 0x16cc0 targets 0x16920, is taken when ra(=0x2000) != s0(?), and falls through when ra(=0x2000) == s0(?).
  The `beq` branch at 0x16cc8 targets 0x16b00 and is always taken.
  The `bne` branch at 0x16cd0 targets 0x16920, is taken when at(=0x8000000000) != s0(?), and falls through when at(=0x8000000000) == s0(?).
  The `beq` branch at 0x16cf4 targets 0x16924 and is always taken.
  The `bne` branch at 0x16d00 targets 0x16920, is taken when v0(=0x800000000) != s0(?), and falls through when v0(=0x800000000) == s0(?).
  The `beq` branch at 0x16d08 targets 0x168f4 and is always taken.
  The `bne` branch at 0x16d10 targets 0x16920, is taken when v1(=0x1000000) != s0(?), and falls through when v1(=0x1000000) == s0(?).
  The `beq` branch at 0x16d44 targets 0x16924 and is always taken.
  The `bne` branch at 0x16d4c targets 0x16920, is taken when a0(=0x400000) != s0(?), and falls through when a0(=0x400000) == s0(?).
  The `beq` branch at 0x16d58 targets 0x16920, is taken when a1(=[(a0 + one of 0x38, 0xc0)]) == 0, and falls through when a1(=[(a0 + one of 0x38, 0xc0)]) != 0.
  The `beq` branch at 0x16d6c targets 0x16924 and is always taken.
  The `bne` branch at 0x16d74 targets 0x16920, is taken when a2(=0x100) != s0(?), and falls through when a2(=0x100) == s0(?).
  The `beq` branch at 0x16d7c targets 0x16b00 and is always taken.
  The `bne` branch at 0x16d84 targets 0x16920, is taken when a3(=0x80000000000) != s0(?), and falls through when a3(=0x80000000000) == s0(?).
  The `beq` branch at 0x16d8c targets 0x168d4 and is always taken.
  The `bne` branch at 0x16d94 targets 0x16920, is taken when a4(=0x4000000) != s0(?), and falls through when a4(=0x4000000) == s0(?).
  The `beq` branch at 0x16da0 targets 0x16dbc, is taken when a5(=[(a0 + one of 0x38, 0xc0)]) == 0, and falls through when a5(=[(a0 + one of 0x38, 0xc0)]) != 0.
  The `beq` branch at 0x16dbc targets 0x16e44, is taken when a0(=[(a0 + one of 0x38, 0xc0)]) == 0, and falls through when a0(=[(a0 + one of 0x38, 0xc0)]) != 0.
  The `beq` branch at 0x16dc8 targets 0x16e40, is taken when a6(=[(a0 + one of 0x3c, 0xc4)]) == 0, and falls through when a6(=[(a0 + one of 0x3c, 0xc4)]) != 0.
  The `beq` branch at 0x16dec targets 0x16924 and is always taken.
  The `beq` branch at 0x16e04 targets 0x16924 and is always taken.
  The `beq` branch at 0x16e38 targets 0x16924 and is always taken.
  The `beq` branch at 0x16e60 targets 0x16924 and is always taken.
  The return at 0x16c24 has v0 = one of ?, ret(kl_perr).

- `show_xbow_err` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x16f64 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x16f64-0x17220 (700 bytes).
  It occupies 700 bytes.
  The `lw` at 0x16f80 loads 4 bytes from a1 (arg1 at entry) +0xc.
  2 such `lw` accesses load 4 bytes from (a0 + one of 0x8, 0x58) +0x0, including `lw` at 0x16fa8, `lw` at 0x16fd0.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0x1701c, `ld` at 0x17080.
  The `ld` at 0x170c4 loads 8 bytes from table(sym(pi_err_status_cmd)) +0x1178.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0x17118, `lw` at 0x17128.
  The `lw` at 0x17170 loads 4 bytes from (a0 + one of 0x14, 0x64) +0x0.
  The `lw` at 0x1719c loads 4 bytes from (a0 + one of 0xc, 0x5c) +0x0.
  The `lw` at 0x171b0 loads 4 bytes from (a0 + one of 0x10, 0x60) +0x0.
  The `lw` at 0x1721c loads 4 bytes from (a0 + one of 0x38, 0x88) +0x0.
  The `jal` at 0x16fc4 calls kl_perr with a0=0x3, a1=sym(.rodata)+7952, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x16fdc calls kl_perr with a0=0x4, a1=sym(.rodata)+7952, a2=[(a0 + one of 0x8, 0x58)], a3=?.
  The `jal` at 0x17020 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x17058 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x17084 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x170c8 calls kl_perr with a0=0x5, a1=sym(.rodata)+7952, a2=[table(sym(pi_err_status_cmd))+4472]:8, a3=?.
  The `jal` at 0x17158 calls kl_perr with a0=0x4, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `jal` at 0x1718c calls kl_perr with a0=0x14, a1=sym(.rodata)+7952, a2=[(a0 + one of 0x14, 0x64)], a3=?.
  The `jal` at 0x171a0 calls kl_perr with a0=0x14, a1=sym(.rodata)+7952, a2=[(a0 + one of 0xc, 0x5c)], a3=?.
  The `jal` at 0x171b4 calls kl_perr with a0=0x14, a1=sym(.rodata)+7952, a2=[(a0 + one of 0x10, 0x60)], a3=?.
  The `jal` at 0x171fc calls kl_perr with a0=0x14, a1=sym(.rodata)+7952, a2=?, a3=?.
  The `beq` branch at 0x16f9c targets 0x16fa8, is taken when (at(=[a1+12]) & 0x1) == 0, and falls through when (at(=[a1+12]) & 0x1) != 0.
  The `beq` branch at 0x16fb4 targets 0x170a8, is taken when (v0(=[(a0 + one of 0x8, 0x58)]) & v1(=0xffffffffff80003f)) == 0, and falls through when (v0(=[(a0 + one of 0x8, 0x58)]) & v1(=0xffffffffff80003f)) != 0.
  The `beq` branch at 0x17010 targets 0x17028, is taken when t8(?) == 0, and falls through when t8(?) != 0.
  The `bne` branch at 0x1703c targets 0x17010, is taken when s1(?) < 0x6 (signed), and falls through when s1(?) >= 0x6 (signed).
  The `beq` branch at 0x17074 targets 0x1708c, is taken when (s0(?) & a2(?)) == 0, and falls through when (s0(?) & a2(?)) != 0.
  The `bne` branch at 0x17098 targets 0x1706c, is taken when s1(?) < 0x20 (unsigned), and falls through when s1(?) >= 0x20 (unsigned).
  The `beq` branch at 0x170a0 targets 0x170ac and is always taken.
  The `beq` branch at 0x170b0 targets 0x1720c and is always taken.
  The `beq` branch at 0x170d8 targets 0x170fc, is taken when s0(?) >= 0x13 (unsigned), and falls through when s0(?) < 0x13 (unsigned).
  The `bne` branch at 0x170e4 targets 0x170b8, is taken when (s1(?) & a4(?)) != 0, and falls through when (s1(?) & a4(?)) == 0.
  The `bne` branch at 0x170f4 targets 0x170e0, is taken when s0(?) < 0x13 (unsigned), and falls through when s0(?) >= 0x13 (unsigned).
  The `beq` branch at 0x17110 targets 0x17170, is taken when s4(?) >= 0x8 (signed), and falls through when s4(?) < 0x8 (signed).
  The `beq` branch at 0x17120 targets 0x170fc, is taken when (a7(?) & 0x20) == 0, and falls through when (a7(?) & 0x20) != 0.
  The `beq` branch at 0x17130 targets 0x170fc, is taken when s6(?) == 0, and falls through when s6(?) != 0.
  The `beq` branch at 0x17138 targets 0x17144, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0x17144 targets 0x171ec, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0x17168 targets 0x170dc and is always taken.
  The `bne` branch at 0x17178 targets 0x17188, is taken when (a2(=[(a0 + one of 0x14, 0x64)]) & 0x200) != 0, and falls through when (a2(=[(a0 + one of 0x14, 0x64)]) & 0x200) == 0.
  The `beq` branch at 0x17180 targets 0x171bc, is taken when s8(?) == 0, and falls through when s8(?) != 0.
  The `beq` branch at 0x17204 targets 0x17100 and is always taken.
  The `beq` branch at 0x17218 targets 0x1711c and is always taken.
  The return at 0x171e4 has v0 = one of ?, ret(kl_perr).

- `hub_error_clear` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x177ac (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x177ac-0x17950 (420 bytes).
  It occupies 420 bytes.
  The `sd` at 0x17844 stores 8 bytes to ((a0 << 0x21) + one of 0x9200000001800400, 0x9200000001a00400) +0x0.
  The `sd` at 0x17850 stores 8 bytes to ((a0 << 0x21) + one of 0x9200000001800438, 0x9200000001a00438) +0x0.
  The `sd` at 0x1785c stores 8 bytes to ((a0 << 0x21) + one of 0x9200000001800458, 0x9200000001a00458) +0x0.
  The `sd` at 0x17864 stores 8 bytes to ((a0 << 0x21) + one of 0x92000000018004c8, 0x9200000001a004c8) +0x0.
  The `sd` at 0x1786c stores 8 bytes to ((a0 << 0x21) + one of 0x92000000018004d0, 0x9200000001a004d0) +0x0.
  The `ld` at 0x17884 loads 8 bytes from (a0 << 0x21) -0x6dfffffffe03ffe8.
  The `ld` at 0x17890 loads 8 bytes from (a0 << 0x21) -0x6dfffffffe01ffe8.
  The `ld` at 0x1789c loads 8 bytes from (a0 << 0x21) -0x6dfffffffe07ffa8.
  The `ld` at 0x178a8 loads 8 bytes from (a0 << 0x21) -0x6dfffffffe03ffd8.
  The `ld` at 0x178b8 loads 8 bytes from ?.
  3 such `sd` accesses store 8 bytes to ?, including `sd` at 0x178d8, `sd` at 0x17928, `sd` at 0x17944.
  The `sd` at 0x178e8 stores 8 bytes to (a0 << 0x21) -0x6dfffffffe3ffe08.
  The `ld` at 0x178ec loads 8 bytes from (a0 << 0x21) -0x6dfffffffe3ffec8.
  The `sd` at 0x178fc stores 8 bytes to (a0 << 0x21) -0x6dfffffffe3ffec8.
  The `ld` at 0x17904 loads 8 bytes from (a0 << 0x21) -0x6dfffffffe17fee0.
  The `sd` at 0x17908 stores 8 bytes to (a0 << 0x21) -0x6dfffffffe1fbfb8.
  The `sd` at 0x1790c stores 8 bytes to (a0 << 0x21) -0x6dfffffffe1fbfb0.
  The `bne` branch at 0x17868 targets 0x17800, is taken when a6(?) < 0x2 (signed), and falls through when a6(?) >= 0x2 (signed).
  The `bne` branch at 0x178d4 targets 0x178ac, is taken when a1(?) < 0x9 (signed), and falls through when a1(?) >= 0x9 (signed).
  The `beq` branch at 0x1792c targets 0x17948, is taken when a1(?) >= 0x71 (signed), and falls through when a1(?) < 0x71 (signed).
  The `bne` branch at 0x17940 targets 0x17918, is taken when a1(?) < 0x71 (signed), and falls through when a1(?) >= 0x71 (signed).
  The return at 0x17948 has v0 = (a0 << 0x21)+0x9200000001c00000.

- `hub_error_init` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x17950
  Role (from name): sets up hub error handling for one node. Several of these calls sit behind branches. It calls `hub_error_clear` first, with a nasid looked up in `compact_to_nasid_node`, then `hubii_eint_init` and `hubni_eint_init`. It calls `recover_error_init` four times, with a0 equal to a pointer loaded from the `kl_error_log` entry plus 8208, 8336, 8464 and 8592. It calls `kmem_zalloc_node` with sizes 0x2258 and 0x40, connects `hubpi_eint_handler` through `cause_intr_connect` (a0 = 6), and calls `spinlock_init` on `kl_error_log`. Three `assfail` calls and one `cmn_err` (level 0x14) are on other paths. The return at 0x17a4c is a doubleword loaded from -0x3c00 plus 34892, which the facts do not resolve further.
  Grade: inferred.
  Reviewed: 2026-11-12

- `hubni_eint_init` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x180cc (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x180cc-0x181d0 (260 bytes).
  It occupies 260 bytes.
  The `jal` at 0x180d8 calls cnodetocpu with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x18108 calls intr_connect_level with a0=?, a1=0x7e, a2=0x0, a3=sym(hubni_eint_handler), a4=0x0, a5=0x0.
  The `jal` at 0x18130 calls cnode_slice_to_cpuid with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x18154 calls cpu_enabled with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x18178 calls intr_connect_level with a0=?, a1=?, a2=0x0, a3=sym(hubni_rmteint_handler), a4=0x0, a5=0x0.
  The `jal` at 0x181ac calls cmn_err with a0=0x14, a1=sym(.rodata)+28464, a2=?, a3=?.
  The `jal` at 0x181c0 calls cmn_err with a0=0x14, a1=sym(.rodata)+28464, a2=?, a3=?.
  The `beq` branch at 0x180e8 targets 0x18190, is taken when v0(=ret(cnodetocpu)) == at(=-0x1), and falls through when v0(=ret(cnodetocpu)) != at(=-0x1).
  The `bne` branch at 0x18110 targets 0x181a8, is taken when v0(=ret(intr_connect_level)) != 0, and falls through when v0(=ret(intr_connect_level)) == 0.
  The `beq` branch at 0x18118 targets 0x1812c and is always taken.
  The `beq` branch at 0x18128 targets 0x18190, is taken when s0(?) >= 0x4 (signed), and falls through when s0(?) < 0x4 (signed).
  The `bltz` branch at 0x18144 targets 0x18120, is taken when s1(?) < 0 (signed), and falls through when s1(?) >= 0 (signed).
  The `beq` branch at 0x1814c targets 0x18120, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x1815c targets 0x18120, is taken when v0(=ret(cpu_enabled)) == 0, and falls through when v0(=ret(cpu_enabled)) != 0.
  The `beql` branch at 0x18180 targets 0x18124, is taken when v0(=ret(intr_connect_level)) == 0, and falls through when v0(=ret(intr_connect_level)) != 0; its branch-likely delay slot `addiu s0,s0,1` at 0x18184 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x18188 targets 0x181bc and is always taken.
  The `beq` branch at 0x181b4 targets 0x18118 and is always taken.
  The `beq` branch at 0x181c8 targets 0x18124 and is always taken.
  The return at 0x181a0 has v0 = one of ret(cnodetocpu), ?.

- `hubpi_eint_handler` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x181d0
  Role (from name): the handler for hub processor-interface errors. It calls `check_ni_errors` first and, when that returns nonzero, `hubni_error_handler` with a1 = 1. Under a sign test at 0x182f0 it calls `get_nasid`, passes the result to `log_md_errors`, and then calls `md_int_block`. `process_error_spool` is called three times, each under a mask test. It has 21 `cmn_err` call sites at levels 0x10, 0x12, 0x14 and 0x15, and one path calls `kl_panic_setup`. The format strings are not rendered, so the report contents are unknown.
  Grade: inferred.
  Reviewed: 2026-11-12

- `hubni_print_state` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x18828 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x18828-0x18974 (332 bytes).
  It occupies 332 bytes.
  The `ld` at 0x18844 loads 8 bytes from abs 0xffffffffffffc400.
  The `lh` at 0x1884c loads 2 bytes from (sym(nasid_to_compact_node) + (a0 + a0)) +0x0.
  The `ld` at 0x18854 loads 8 bytes from [-0x3c00]:8 +0x0.
  The `ld` at 0x18878 loads 8 bytes from ([[-0x3c00]:8]:8 + ([(sym(nasid_to_compact_node) + (a0 + a0))]:2 << 0x3)) +0x0.
  The `ll` at 0x18884 loads 4 bytes from [([[-0x3c00]:8]:8 + ([(sym(nasid_to_compact_node) + (a0 + a0))]:2 << 0x3))]:8 +0x8f08.
  The `sc` at 0x1888c stores 4 bytes to [([[-0x3c00]:8]:8 + ([(sym(nasid_to_compact_node) + (a0 + a0))]:2 << 0x3))]:8 +0x8f08.
  The `lh` at 0x18928 loads 2 bytes from [([[-0x3c00]:8]:8 + ([(sym(nasid_to_compact_node) + (a0 + a0))]:2 << 0x3))]:8 +0x861a.
  The `ld` at 0x18948 loads 8 bytes from (a0 << 0x21) -0x6dfffffffe17ff00.
  The `jal` at 0x188e0 calls mutex_spintrylock with a0=[([[-0x3c00]:8]:8 + ([(sym(nasid_to_compact_node) + (a0 + a0))]:2 << 0x3))]:8+34372, a1=?, a2=?, a3=?.
  The `jal` at 0x188f8 calls mutex_spinunlock with a0=[([[-0x3c00]:8]:8 + ([(sym(nasid_to_compact_node) + (a0 + a0))]:2 << 0x3))]:8+34372, a1=ret(mutex_spintrylock), a2=[([[-0x3c00]:8]:8 + ([(sym(nasid_to_compact_node) + (a0 + a0))]:2 << 0x3))]:8+34372, a3=?.
  The `jalr` at 0x1890c calls (unknown callee) with a0=a1 at entry (arg1), a1=sym(.rodata)+28464, a2=?, a3=?.
  The `jalr` at 0x18924 calls (unknown callee) with a0=a1 at entry (arg1), a1=sym(.rodata)+28464, a2=[[([[-0x3c00]:8]:8 + ([(sym(nasid_to_compact_node) + (a0 + a0))]:2 << 0x3))]:8+34330]:2, a3=?.
  The `jal` at 0x18944 calls show_ni_port_error with a0=[(a0 << 0x21)-7926335344140091136]:8, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=?.
  The `jal` at 0x18954 calls us_delay with a0=0x1, a1=ret(mutex_spintrylock), a2=?, a3=?.
  The `beq` branch at 0x18874 targets 0x188c0, is taken when a3 == at(=0x2), and falls through when a3 != at(=0x2).
  The `beql` branch at 0x18890 targets 0x18884, is taken when a0(=([[([[-0x3c00]:8]:8 + ([(sym(nasid_to_compact_node) + (a0 + a0))]:2 << 0x3))]:8+36616] | a3)) == 0, and falls through when a0(=([[([[-0x3c00]:8]:8 + ([(sym(nasid_to_compact_node) + (a0 + a0))]:2 << 0x3))]:8+36616] | a3)) != 0; its branch-likely delay slot `nop` at 0x18894 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x1889c targets 0x18908, is taken when (v0(=[[([[-0x3c00]:8]:8 + ([(sym(nasid_to_compact_node) + (a0 + a0))]:2 << 0x3))]:8+36616]) & s7(=a3)) == 0, and falls through when (v0(=[[([[-0x3c00]:8]:8 + ([(sym(nasid_to_compact_node) + (a0 + a0))]:2 << 0x3))]:8+36616]) & s7(=a3)) != 0.
  The `beq` branch at 0x188d8 targets 0x188f8 and is never taken: its condition can never hold for these operands, so execution always falls through.
  The `beq` branch at 0x188ec targets 0x18954, is taken when v0(=ret(mutex_spintrylock)) == 0, and falls through when v0(=ret(mutex_spintrylock)) != 0.
  The `beq` branch at 0x18900 targets 0x18880 and is always taken.
  The `beq` branch at 0x1894c targets 0x188a8 and is always taken.
  The `bne` branch at 0x18964 targets 0x188e0, is taken when a1(?) != 0, and falls through when a1(?) == 0.
  The `beq` branch at 0x1896c targets 0x188f4 and is always taken.
  The return at 0x188b8 has v0 = one of ?, ret(show_ni_port_error).

- `ni_port_down_reset` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x18974 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x18974-0x18a24 (176 bytes).
  It occupies 176 bytes.
  2 such `ld` accesses load 8 bytes from (a0 << 0x21) -0x6dfffffffe180000, including `ld` at 0x1899c, `ld` at 0x18a04.
  3 such `ld` accesses load 8 bytes from (a0 << 0x21) -0x6dfffffffe17fee0, including `ld` at 0x189b0, `ld` at 0x189c4, `ld` at 0x189d4.
  2 such `sd` accesses store 8 bytes to (a0 << 0x21) -0x6dfffffffe17ff00, including `sd` at 0x189c0, `sd` at 0x189d8.
  The `jal` at 0x1897c calls part_id with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x189fc calls us_delay with a0=0xc8, a1=?, a2=?, a3=?.
  The `blez` branch at 0x18984 targets 0x189dc, is taken when v0(=ret(part_id)) <= 0 (signed), and falls through when v0(=ret(part_id)) > 0 (signed).
  The `beq` branch at 0x189a8 targets 0x189ec, is taken when at(?) == v0(=0x4), and falls through when at(?) != v0(=0x4).
  The `beq` branch at 0x189bc targets 0x189dc, is taken when (t8(=[(a0 << 0x21)-7926335344140091104]:8) & t9(=0xfffffff000000)) == 0, and falls through when (t8(=[(a0 << 0x21)-7926335344140091104]:8) & t9(=0xfffffff000000)) != 0.
  The `beq` branch at 0x189cc targets 0x189e0, is taken when (ra(=[(a0 << 0x21)-7926335344140091104]:8) & at(=0x1fffffff000000)) == 0, and falls through when (ra(=[(a0 << 0x21)-7926335344140091104]:8) & at(=0x1fffffff000000)) != 0.
  The `beq` branch at 0x189ec targets 0x189fc and is always taken.
  The `beq` branch at 0x189f4 targets 0x18a1c, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0x18a14 targets 0x189f4, is taken when (v1(=[(a0 << 0x21)-7926335344140091392]:8) & 0x2) == 0, and falls through when (v1(=[(a0 << 0x21)-7926335344140091392]:8) & 0x2) != 0.
  The `beq` branch at 0x18a1c targets 0x189b0 and is always taken.
  The return at 0x189e4 has v0 = ?.

- `check_ni_errors_nasid` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x18a24 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x18a24-0x18d20 (764 bytes).
  It occupies 764 bytes.
  The `ld` at 0x18a44 loads 8 bytes from (a0 << 0x21) -0x6dfffffffe17ff00.
  The `ld` at 0x18a58 loads 8 bytes from (a0 << 0x21) -0x6dfffffffe180000.
  The `ld` at 0x18a64 loads 8 bytes from (a0 << 0x21) -0x6dfffffffe7fff60.
  4 such `ld` accesses load 8 bytes from (a0 << 0x21) -0x6dfffffffe17fee0, including `ld` at 0x18a78, `ld` at 0x18a88, `ld` at 0x18b08.
  3 such `sd` accesses store 8 bytes to (a0 << 0x21) -0x6dfffffffe17ff00, including `sd` at 0x18a7c, `sd` at 0x18b0c, `sd` at 0x18cd4.
  2 such `ld` accesses load 8 bytes from (a0 << 0x21) -0x6dfffffffe17fff0, including `ld` at 0x18ae0, `ld` at 0x18cac.
  The `ld` at 0x18c68 loads 8 bytes from abs 0x9200000001680108.
  The `ld` at 0x18c7c loads 8 bytes from abs 0x9200000001680110.
  The `ld` at 0x18c90 loads 8 bytes from abs 0x9200000001680118.
  The `jal` at 0x18a68 calls part_id with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=[(a0 << 0x21)-7926335344140091392]:8, a3=a3 at entry (arg3).
  The `jal` at 0x18a80 calls ni_port_down_reset with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x18af8 calls cmn_err with a0=0x15, a1=sym(.rodata)+28464, a2=a0 at entry (arg0), a3=?.
  The `jal` at 0x18b00 calls ni_port_down_reset with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x18b28 calls cmn_err with a0=0x14, a1=sym(.rodata)+28464, a2=a0 at entry (arg0), a3=?.
  The `jal` at 0x18b38 calls cmn_err with a0=0x14, a1=sym(.rodata)+28464, a2=[(a0 << 0x21)-7926335344140091136]:8, a3=?.
  The `jal` at 0x18b58 calls cmn_err with a0=0x14, a1=sym(.rodata)+28464, a2=?, a3=?.
  The `jal` at 0x18b7c calls cmn_err with a0=0x14, a1=sym(.rodata)+28464, a2=?, a3=?.
  The `jal` at 0x18ba0 calls cmn_err with a0=0x14, a1=sym(.rodata)+28464, a2=?, a3=?.
  The `jal` at 0x18bc4 calls cmn_err with a0=0x14, a1=sym(.rodata)+28464, a2=?, a3=?.
  The `jal` at 0x18be8 calls cmn_err with a0=0x14, a1=sym(.rodata)+28464, a2=?, a3=?.
  The `jal` at 0x18c0c calls cmn_err with a0=0x14, a1=sym(.rodata)+28464, a2=?, a3=?.
  The `jal` at 0x18c30 calls cmn_err with a0=0x14, a1=sym(.rodata)+28464, a2=?, a3=?.
  The `jal` at 0x18c50 calls cmn_err with a0=0x14, a1=sym(.rodata)+28464, a2=0x10000000000000, a3=?.
  The `jal` at 0x18c64 calls cmn_err with a0=0x14, a1=sym(.rodata)+28464, a2=[0x9200000001680108]:8, a3=?.
  The `jal` at 0x18c78 calls cmn_err with a0=0x14, a1=sym(.rodata)+28464, a2=[0x9200000001680110]:8, a3=?.
  The `jal` at 0x18c8c calls cmn_err with a0=0x14, a1=sym(.rodata)+28464, a2=[0x9200000001680118]:8, a3=?.
  The `jal` at 0x18c94 calls protected_broadcast with a0=0x67, a1=?, a2=?, a3=?.
  The `jal` at 0x18c9c calls protected_broadcast with a0=0x68, a1=?, a2=?, a3=?.
  The `jal` at 0x18cc0 calls cmn_err with a0=0x15, a1=sym(.rodata)+28464, a2=[(a0 << 0x21)-7926335344140091392]:8, a3=[(a0 << 0x21)-7926335344140091376]:8.
  The `jal` at 0x18cc8 calls ni_port_down_reset with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x18cec calls cmn_err with a0=0x14, a1=sym(.rodata)+28464, a2=[(a0 << 0x21)-7926335344140091392]:8, a3=[(a0 << 0x21)-7926335344140091376]:8.
  The `jal` at 0x18cf8 calls cmn_err with a0=0x14, a1=sym(.rodata)+28464, a2=?, a3=?.
  The `jal` at 0x18d10 calls cmn_err with a0=0x14, a1=sym(.rodata)+28464, a2=[(a0 << 0x21)-7926335344146906976]:8, a3=a3 at entry (arg3).
  The `beq` branch at 0x18a60 targets 0x18a98, is taken when (s0(=[(a0 << 0x21)-7926335344140091136]:8) & at(=0x1fffffff000000)) == 0, and falls through when (s0(=[(a0 << 0x21)-7926335344140091136]:8) & at(=0x1fffffff000000)) != 0.
  The `blez` branch at 0x18a70 targets 0x18ad0, is taken when v0(=ret(part_id)) <= 0 (signed), and falls through when v0(=ret(part_id)) > 0 (signed).
  The `beq` branch at 0x18a90 targets 0x18ab8 and is always taken.
  The `beq` branch at 0x18a9c targets 0x18cac, is taken when (a2(=[(a0 << 0x21)-7926335344140091392]:8) & 0x3) == 0, and falls through when (a2(=[(a0 << 0x21)-7926335344140091392]:8) & 0x3) != 0.
  The `bne` branch at 0x18aac targets 0x18d08, is taken when (v0(=[(a0 << 0x21)-7926335344146906976]:8) & at(=0x18000000000)) != 0, and falls through when (v0(=[(a0 << 0x21)-7926335344146906976]:8) & at(=0x18000000000)) == 0.
  The `beq` branch at 0x18ad8 targets 0x18b1c, is taken when (v0(=0x10000000000000) & s0(=[(a0 << 0x21)-7926335344140091136]:8)) == 0, and falls through when (v0(=0x10000000000000) & s0(=[(a0 << 0x21)-7926335344140091136]:8)) != 0.
  The `bne` branch at 0x18ae4 targets 0x18b1c, is taken when v1(=[(a0 << 0x21)-7926335344140091376]:8) != 0, and falls through when v1(=[(a0 << 0x21)-7926335344140091376]:8) == 0.
  The `beq` branch at 0x18b14 targets 0x18ab8 and is always taken.
  The `beq` branch at 0x18b48 targets 0x18b60, is taken when (s0(=[(a0 << 0x21)-7926335344140091136]:8) & a2(=0xf000000)) == 0, and falls through when (s0(=[(a0 << 0x21)-7926335344140091136]:8) & a2(=0xf000000)) != 0.
  The `beq` branch at 0x18b6c targets 0x18b84, is taken when (s0(=[(a0 << 0x21)-7926335344140091136]:8) & a2(=0xf0000000)) == 0, and falls through when (s0(=[(a0 << 0x21)-7926335344140091136]:8) & a2(=0xf0000000)) != 0.
  The `beq` branch at 0x18b90 targets 0x18ba8, is taken when (s0(=[(a0 << 0x21)-7926335344140091136]:8) & a2(=0xf00000000)) == 0, and falls through when (s0(=[(a0 << 0x21)-7926335344140091136]:8) & a2(=0xf00000000)) != 0.
  The `beq` branch at 0x18bb4 targets 0x18bcc, is taken when (s0(=[(a0 << 0x21)-7926335344140091136]:8) & a2(=0xf000000000)) == 0, and falls through when (s0(=[(a0 << 0x21)-7926335344140091136]:8) & a2(=0xf000000000)) != 0.
  The `beq` branch at 0x18bd8 targets 0x18bf0, is taken when (s0(=[(a0 << 0x21)-7926335344140091136]:8) & a2(=0xf0000000000)) == 0, and falls through when (s0(=[(a0 << 0x21)-7926335344140091136]:8) & a2(=0xf0000000000)) != 0.
  The `beq` branch at 0x18bfc targets 0x18c14, is taken when (s0(=[(a0 << 0x21)-7926335344140091136]:8) & a2(=0xf00000000000)) == 0, and falls through when (s0(=[(a0 << 0x21)-7926335344140091136]:8) & a2(=0xf00000000000)) != 0.
  The `beq` branch at 0x18c20 targets 0x18c38, is taken when (s0(=[(a0 << 0x21)-7926335344140091136]:8) & a2(=0xf000000000000)) == 0, and falls through when (s0(=[(a0 << 0x21)-7926335344140091136]:8) & a2(=0xf000000000000)) != 0.
  The `beq` branch at 0x18c3c targets 0x18c5c, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0x18ca4 targets 0x18ab8 and is always taken.
  The `bne` branch at 0x18cb0 targets 0x18ce4, is taken when a3(=[(a0 << 0x21)-7926335344140091376]:8) != 0, and falls through when a3(=[(a0 << 0x21)-7926335344140091376]:8) == 0.
  The `beq` branch at 0x18cdc targets 0x18ab8 and is always taken.
  The `beq` branch at 0x18d00 targets 0x18ab8 and is always taken.
  The `beq` branch at 0x18d18 targets 0x18ab8 and is always taken.
  The return at 0x18ac8 has v0 = one of 0x0, 0x1.

- `hubni_error_handler_nasid` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x18d20 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x18d20-0x18ec0 (416 bytes).
  It occupies 416 bytes.
  The `ld` at 0x18d3c loads 8 bytes from (a1 << 0x21) -0x6dfffffffe17ff00.
  3 such `ld` accesses load 8 bytes from (a1 << 0x21) -0x6dfffffffe17fee0, including `ld` at 0x18d74, `ld` at 0x18ea4, `ld` at 0x18eb4.
  The `ld` at 0x18d94 loads 8 bytes from (a1 << 0x21) -0x6dfffffffe17fff0.
  The `sd` at 0x18dd4 stores 8 bytes to ((ret(get_slice) << 0x3) + (ret(get_nasid) << 0x21)) -0x6fffffffcfffff40.
  The `jal` at 0x18d5c calls part_id with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=[(a1 << 0x21)-7926335344140091136]:8.
  The `jal` at 0x18d6c calls ni_port_down_reset with a0=a1 at entry (arg1), a1=?, a2=?, a3=[(a1 << 0x21)-7926335344140091136]:8.
  The `jal` at 0x18da0 calls splerr with a0=?, a1=?, a2=?, a3=[(a1 << 0x21)-7926335344140091136]:8.
  The `jal` at 0x18da8 calls get_slice with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x18db0 calls get_nasid with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x18dd0 calls set_node_panic_flag with a0=0x9000000030000000, a1=(ret(get_nasid) << 0x21), a2=?, a3=?.
  The `jal` at 0x18de8 calls hubni_print_state with a0=a1 at entry (arg1), a1=0x0, a2=sym(ip27log_printf), a3=0x2.
  The `jal` at 0x18df0 calls enter_panic_mode with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x18e04 calls router_print_state with a0=0x0, a1=0x0, a2=sym(ip27log_printf), a3=0x2.
  The `jal` at 0x18e1c calls ip27log_printf with a0=0x2, a1=sym(.rodata)+28464, a2=a0 at entry (arg0), a3=a1 at entry (arg1).
  The `jal` at 0x18e24 calls enter_promlog_mode with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x18e3c calls hubni_print_state with a0=a1 at entry (arg1), a1=0x16, a2=sym(cmn_err), a3=0x4.
  The `jal` at 0x18e50 calls router_print_state with a0=0x0, a1=0x16, a2=sym(cmn_err), a3=0x4.
  The `jal` at 0x18e64 calls panicspin with a0=?, a1=sym(.rodata)+28464, a2=a2 at entry (arg2), a3=?.
  The `jal` at 0x18e84 calls cmn_err with a0=0x0, a1=sym(.rodata)+28464, a2=a2 at entry (arg2), a3=?.
  The `jal` at 0x18e9c calls cmn_err with a0=0x15, a1=sym(.rodata)+28464, a2=?, a3=[(a1 << 0x21)-7926335344140091136]:8.
  The `jal` at 0x18eac calls ni_port_down_reset with a0=a1 at entry (arg1), a1=?, a2=[(a1 << 0x21)-7926335344140091104]:8, a3=?.
  The `beq` branch at 0x18d54 targets 0x18d80, is taken when (a3(=[(a1 << 0x21)-7926335344140091136]:8) & at(=0x1fffffff000000)) == 0, and falls through when (a3(=[(a1 << 0x21)-7926335344140091136]:8) & at(=0x1fffffff000000)) != 0.
  The `blez` branch at 0x18d64 targets 0x18d80, is taken when v0(=ret(part_id)) <= 0 (signed), and falls through when v0(=ret(part_id)) > 0 (signed).
  The `beq` branch at 0x18d78 targets 0x18e6c and is always taken.
  The `beq` branch at 0x18d8c targets 0x18da0, is taken when (a3(=[(a1 << 0x21)-7926335344140091136]:8) & ra(=0x10000000000000)) == 0, and falls through when (a3(=[(a1 << 0x21)-7926335344140091136]:8) & ra(=0x10000000000000)) != 0.
  The `beq` branch at 0x18d98 targets 0x18e94, is taken when at(=[(a1 << 0x21)-7926335344140091376]:8) == 0, and falls through when at(=[(a1 << 0x21)-7926335344140091376]:8) != 0.
  The `bne` branch at 0x18e5c targets 0x18e80, is taken when a2 != 0, and falls through when a2 == 0.
  The `beq` branch at 0x18e8c targets 0x18e70 and is always taken.
  The `beq` branch at 0x18eb8 targets 0x18e6c and is always taken.
  The return at 0x18e78 has v0 = one of ?, ret(cmn_err).

- `hubni_error_handler` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x18ee4
  It is a short wrapper. It gets the node id from `get_nasid`, calls `hubni_error_handler_nasid` with its first argument, that node id and its second argument, and returns the result. The name suggests it handles network-interface errors for one node, which the facts fit but do not prove.
  Grade: inferred.
  Reviewed: 2026-11-12

- `klsave_md_registers` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x18f64 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x18f64-0x190d4 (368 bytes).
  It occupies 368 bytes.
  The `ld` at 0x18f80 loads 8 bytes from (a3 << 0x21) -0x6fffffffcc000000.
  The `ld` at 0x18fb8 loads 8 bytes from ((a3 << 0x21)+0x9600000000000000 | 0x2000) +0x48.
  The `lw` at 0x18fc8 loads 4 bytes from ?.
  The `lw` at 0x19014 loads 4 bytes from ret(find_first_component) +0x30.
  9 such `sd` accesses store 8 bytes to ?, including `sd` at 0x19080, `sd` at 0x1908c, `sd` at 0x19098.
  4 such `ld` accesses load 8 bytes from abs 0x9200000001030100, including `ld` at 0x19090, `ld` at 0x190a0, `ld` at 0x190b4.
  The `jal` at 0x18fdc calls find_lboard with a0=?, a1=0x11, a2=?, a3=?.
  The `jal` at 0x18ff0 calls find_first_component with a0=ret(find_lboard), a1=0x2, a2=?, a3=?.
  The `jal` at 0x19070 calls chk_for_pebrick with a0=a3 at entry (arg3), a1=a1 at entry (arg1), a2=-0x1, a3=a3 at entry (arg3), a6=(a3 << 0x21)+0x9600000000000000, a7=(a3 << 0x21).
  The `beq` branch at 0x18fac targets 0x19070, is taken when at(?) == v1(=0xc000), and falls through when at(?) != v1(=0xc000).
  The `beq` branch at 0x18fd0 targets 0x18fdc, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0x18fe4 targets 0x19058, is taken when v0(=ret(find_lboard)) == 0, and falls through when v0(=ret(find_lboard)) != 0.
  The `beq` branch at 0x19004 targets 0x19058, is taken when v0(=ret(find_first_component)) == 0, and falls through when v0(=ret(find_first_component)) != 0.
  The `beq` branch at 0x19034 targets 0x1905c, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x1903c targets 0x1909c, is taken when s0(=a2) == a3(=0x2), and falls through when s0(=a2) != a3(=0x2).
  The `beq` branch at 0x19044 targets 0x190ac, is taken when s0(=a2) == a6(=0x1), and falls through when s0(=a2) != a6(=0x1).
  The `beq` branch at 0x1904c targets 0x190c0, is taken when s0(=a2) == a2(=0x3), and falls through when s0(=a2) != a2(=0x3).
  The `beq` branch at 0x19054 targets 0x19080, is taken when s0(=a2) == a7(=0x4), and falls through when s0(=a2) != a7(=0x4).
  The `beq` branch at 0x19078 targets 0x18fdc and is always taken.
  The `beq` branch at 0x19094 targets 0x19058 and is always taken.
  The `beq` branch at 0x190a4 targets 0x19058 and is always taken.
  The `beq` branch at 0x190b8 targets 0x19058 and is always taken.
  The `beq` branch at 0x190cc targets 0x19058 and is always taken.
  The return at 0x19068 has v0 = one of ret(find_first_component), ?.

- `md_err_log_first` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x1972c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x1972c-0x19764 (56 bytes).
  It occupies 56 bytes.
  The `lw` at 0x1972c loads 4 bytes from a0 (arg0 at entry) +0x0.
  The `lw` at 0x1973c loads 4 bytes from ?.
  The `lw` at 0x19758 loads 4 bytes from a0 (arg0 at entry) +0x20.
  The `beq` branch at 0x19740 targets 0x19758, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0x1975c targets 0x19748 and is always taken.
  The return at 0x19750 has v0 = ?.

- `md_err_log_next` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x19764 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x19764-0x197f8 (148 bytes).
  It occupies 148 bytes.
  The `lw` at 0x197a8 loads 4 bytes from a0 (arg0 at entry) +0x0.
  The `jal` at 0x197e8 calls assfail with a0=sym(.rodata)+28464, a1=sym(.rodata)+28464, a2=0x603, a3=a3 at entry (arg3).
  The `bltz` branch at 0x19784 targets 0x197dc, is taken when at(?) < 0 (signed), and falls through when at(?) >= 0 (signed).
  The `beq` branch at 0x1978c targets 0x197dc, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x197c8 targets 0x197d4, is taken when a5(?) == a6(?), and falls through when a5(?) != a6(?).
  The `beq` branch at 0x197f0 targets 0x19794 and is always taken.
  The return at 0x197d4 has v0 = one of 0x0, ?.

- `md_err_log_last` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x197f8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x197f8-0x19824 (44 bytes).
  It occupies 44 bytes.
  The `lw` at 0x197f8 loads 4 bytes from a0 (arg0 at entry) +0x0.
  The `lw` at 0x19810 loads 4 bytes from ?.
  The return at 0x1981c has v0 = ?.

- `md_err_log_prev` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x19824 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x19824-0x198cc (168 bytes).
  It occupies 168 bytes.
  The `lw` at 0x19868 loads 4 bytes from a0 (arg0 at entry) +0x0.
  The `lw` at 0x19898 loads 4 bytes from ?.
  The `jal` at 0x198bc calls assfail with a0=sym(.rodata)+28464, a1=sym(.rodata)+28464, a2=0x625, a3=a3 at entry (arg3).
  The `bltz` branch at 0x19844 targets 0x198b0, is taken when at(?) < 0 (signed), and falls through when at(?) >= 0 (signed).
  The `beq` branch at 0x1984c targets 0x198b4, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x19890 targets 0x198a8, is taken when a5(?) == a6(?), and falls through when a5(?) != a6(?).
  The `beq` branch at 0x198c4 targets 0x19858 and is always taken.
  The return at 0x198a8 has v0 = one of 0x0, ?.

- `md_err_log_new` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x198cc (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x198cc-0x1994c (128 bytes).
  It occupies 128 bytes.
  The `ll` at 0x198d0 loads 4 bytes from a0 (arg0 at entry) +0x0.
  The `sc` at 0x198dc stores 4 bytes to a0 (arg0 at entry) +0x0.
  The `lw` at 0x198f8 loads 4 bytes from ?.
  The `ld` at 0x19900 loads 8 bytes from abs 0x9200000001030100.
  The `ld` at 0x19910 loads 8 bytes from ?.
  The `sd` at 0x19930 stores 8 bytes to ?.
  The `beql` branch at 0x198e0 targets 0x198d0, is taken when a1(=[a0]+1) == 0, and falls through when a1(=[a0]+1) != 0; its branch-likely delay slot `nop` at 0x198e4 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x19904 targets 0x1993c, is taken when v1(?) == 0, and falls through when v1(?) != 0.
  The `beq` branch at 0x19928 targets 0x19934, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `bne` branch at 0x1993c targets 0x19930, is taken when v0(?) != 0, and falls through when v0(?) == 0.
  The `beq` branch at 0x19944 targets 0x19934 and is always taken.
  The return at 0x19934 has v0 = ?.

- `klsave_spool_registers` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x1994c
  It reads the doubleword at 0x9200000001000020 and calls `get_nasid` several times. It reads the per-node register block at 0x9600000000000000 offset by the node id, then finds the board and component records with `find_lboard` (argument 0x11) and `find_first_component` (argument 0x2). It writes six doublewords to addresses the facts leave unresolved, and it calls `chk_for_pebrick` on one path. The name suggests saving hub registers into the error spool, but the destinations are unresolved.
  Grade: inferred.
  Reviewed: 2026-11-12

- `huberror_process_rrb_error` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x19d50 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x19d50-0x1a290 (1344 bytes).
  It occupies 1344 bytes.
  The `ld` at 0x19d7c loads 8 bytes from (sym(.rodata)+28464 + (a0 << 0x3)) +0x0.
  Calls (unknown callee) via register with a0=?, a1=a1 at entry (arg1), a2=a0 at entry (arg0), a3=a3 at entry (arg3), a5=sym(.rodata)+28464 (`jr` at 0x19d80).
  The `jal` at 0x1a19c calls cmn_err with a0=0x14, a1=sym(.rodata)+28464, a2=a0 at entry (arg0), a3=a3 at entry (arg3), a5=sym(.rodata)+28464.
  The `beq` branch at 0x19d74 targets 0x1a198, is taken when a0 >= 0x8 (unsigned), and falls through when a0 < 0x8 (unsigned).
  The `beq` branch at 0x1a1a4 targets 0x19e44 and is always taken.
  The return at 0x19e50 has v0 = 0x19.
  The instructions from 0x19d88 to 0x19e40 are not reached by any path from the entry, and their branches are not listed.
  The instructions from 0x19e58 to 0x1a194 are not reached by any path from the entry, and their branches are not listed.
  The instructions from 0x1a1ac to 0x1a28c are not reached by any path from the entry, and their branches are not listed.
  The indirect jump at 0x19d80 uses a jump table whose successors are unresolved.

- `huberror_process_wrb_error` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x1a290 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x1a290-0x1a70c (1148 bytes).
  It occupies 1148 bytes.
  3 such `lh` accesses load 2 bytes from abs 0xffffffffffffc42a, including `lh` at 0x1a62c, `lh` at 0x1a6dc, `lh` at 0x1a6f8.
  The `jal` at 0x1a2e8 calls nasid_to_partid with a0=?, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1a2f0 calls part_id with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1a300 calls error_check_part_page with a0=a1 at entry (arg1), a1=?, a2=?, a3=?.
  The `jal` at 0x1a318 calls partition_handle_error with a0=0x0, a1=a1 at entry (arg1), a2=0x8, a3=?.
  The `jal` at 0x1a350 calls partition_handle_error with a0=0x0, a1=a1 at entry (arg1), a2=0x8, a3=?.
  The `jal` at 0x1a378 calls nasid_to_partid with a0=?, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1a380 calls part_id with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1a390 calls error_check_part_page with a0=a1 at entry (arg1), a1=?, a2=?, a3=?.
  The `jal` at 0x1a3a8 calls partition_handle_error with a0=0x0, a1=a1 at entry (arg1), a2=0x3, a3=?.
  The `jal` at 0x1a3d0 calls nasid_to_partid with a0=?, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1a3d8 calls part_id with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1a3e8 calls error_check_part_page with a0=a1 at entry (arg1), a1=?, a2=?, a3=?.
  The `jal` at 0x1a3fc calls partition_handle_error with a0=0x0, a1=a1 at entry (arg1), a2=0x3, a3=?.
  The `jal` at 0x1a424 calls nasid_to_partid with a0=?, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1a42c calls part_id with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1a440 calls error_check_part_page with a0=a1 at entry (arg1), a1=ret(nasid_to_partid), a2=?, a3=?.
  The `jal` at 0x1a458 calls partition_handle_error with a0=0x0, a1=a1 at entry (arg1), a2=0xa, a3=?.
  The `jal` at 0x1a47c calls nasid_to_partid with a0=?, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1a484 calls part_id with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1a494 calls error_check_part_page with a0=a1 at entry (arg1), a1=?, a2=?, a3=?.
  The `jal` at 0x1a4ac calls partition_handle_error with a0=0x0, a1=a1 at entry (arg1), a2=0x7, a3=?.
  The `jal` at 0x1a4cc calls partition_handle_error with a0=0x0, a1=a1 at entry (arg1), a2=0x3, a3=?.
  The `jal` at 0x1a4ec calls partition_handle_error with a0=0x0, a1=a1 at entry (arg1), a2=0x3, a3=?.
  The `jal` at 0x1a50c calls partition_handle_error with a0=0x0, a1=a1 at entry (arg1), a2=0xa, a3=?.
  The `jal` at 0x1a52c calls partition_handle_error with a0=0x0, a1=a1 at entry (arg1), a2=0x7, a3=?.
  The `jal` at 0x1a54c calls error_check_poisoned_state with a0=a1 at entry (arg1), a1=0x0, a2=0x1, a3=?.
  The `jal` at 0x1a56c calls error_check_memory_access with a0=a1 at entry (arg1), a1=0x1, a2=0x0, a3=?.
  The `jal` at 0x1a590 calls error_check_memory_access with a0=a1 at entry (arg1), a1=0x1, a2=0x0, a3=?.
  The `jal` at 0x1a638 calls kl_ioerror_handler with a0=[-0x3bd6]:2, a1=[-0x3bd6]:2, a2=-0x1, a3=0x6, a4=a1 at entry (arg1), a5=0x0, a6=0x1, a7=0x0.
  The `jal` at 0x1a65c calls cmn_err with a0=0x14, a1=sym(.rodata)+28464, a2=a0 at entry (arg0), a3=a3 at entry (arg3).
  The `jal` at 0x1a674 calls cmn_err with a0=0x14, a1=sym(.rodata)+28464, a2=a1 at entry (arg1), a3=?.
  The `jal` at 0x1a68c calls cmn_err with a0=0x14, a1=sym(.rodata)+28464, a2=a1 at entry (arg1), a3=?.
  The `jal` at 0x1a6a8 calls cmn_err with a0=0x14, a1=sym(.rodata)+28464, a2=a1 at entry (arg1), a3=?.
  The `jal` at 0x1a6c4 calls cmn_err with a0=0x14, a1=sym(.rodata)+28464, a2=a1 at entry (arg1), a3=?.
  The `jal` at 0x1a6e0 calls cmn_err with a0=0x4, a1=sym(.rodata)+28464, a2=a1 at entry (arg1), a3=[-0x3bd6]:2.
  The `jal` at 0x1a6fc calls cmn_err with a0=0x14, a1=sym(.rodata)+28464, a2=sym(.rodata)+28464, a3=a1 at entry (arg1), a4=[-0x3bd6]:2.
  The `beq` branch at 0x1a2b0 targets 0x1a36c, is taken when a0 == s1(=0x3), and falls through when a0 != s1(=0x3).
  The `beq` branch at 0x1a2b8 targets 0x1a3c4, is taken when a0 == 0, and falls through when a0 != 0.
  The `beq` branch at 0x1a2c0 targets 0x1a418, is taken when a0 == at(=0x1), and falls through when a0 != at(=0x1).
  The `beq` branch at 0x1a2cc targets 0x1a474, is taken when a0 == v1(=0x6), and falls through when a0 != v1(=0x6).
  The `bne` branch at 0x1a2d8 targets 0x1a650, is taken when v0(=a0) != a0(=0x7), and falls through when v0(=a0) == a0(=0x7).
  The `bne` branch at 0x1a2f8 targets 0x1a34c, is taken when s2(=ret(nasid_to_partid)) != v0(=ret(part_id)), and falls through when s2(=ret(nasid_to_partid)) == v0(=ret(part_id)).
  The `beq` branch at 0x1a308 targets 0x1a66c, is taken when v0(=ret(error_check_part_page)) == 0, and falls through when v0(=ret(error_check_part_page)) != 0.
  The `beq` branch at 0x1a364 targets 0x1a330 and is always taken.
  The `bne` branch at 0x1a388 targets 0x1a4c8, is taken when s2(=ret(nasid_to_partid)) != v0(=ret(part_id)), and falls through when s2(=ret(nasid_to_partid)) == v0(=ret(part_id)).
  The `beq` branch at 0x1a398 targets 0x1a548, is taken when v0(=ret(error_check_part_page)) == 0, and falls through when v0(=ret(error_check_part_page)) != 0.
  The `beq` branch at 0x1a3bc targets 0x1a330 and is always taken.
  The `bne` branch at 0x1a3e0 targets 0x1a4e8, is taken when s2(=ret(nasid_to_partid)) != v0(=ret(part_id)), and falls through when s2(=ret(nasid_to_partid)) == v0(=ret(part_id)).
  The `beq` branch at 0x1a3f0 targets 0x1a564, is taken when v0(=ret(error_check_part_page)) == 0, and falls through when v0(=ret(error_check_part_page)) != 0.
  The `beq` branch at 0x1a410 targets 0x1a330 and is always taken.
  The `bne` branch at 0x1a438 targets 0x1a508, is taken when a1(=ret(nasid_to_partid)) != v0(=ret(part_id)), and falls through when a1(=ret(nasid_to_partid)) == v0(=ret(part_id)).
  The `beq` branch at 0x1a448 targets 0x1a58c, is taken when v0(=ret(error_check_part_page)) == 0, and falls through when v0(=ret(error_check_part_page)) != 0.
  The `beq` branch at 0x1a46c targets 0x1a330 and is always taken.
  The `bne` branch at 0x1a48c targets 0x1a528, is taken when s2(=ret(nasid_to_partid)) != v0(=ret(part_id)), and falls through when s2(=ret(nasid_to_partid)) == v0(=ret(part_id)).
  The `beq` branch at 0x1a49c targets 0x1a684, is taken when v0(=ret(error_check_part_page)) == 0, and falls through when v0(=ret(error_check_part_page)) != 0.
  The `beq` branch at 0x1a4c0 targets 0x1a330 and is always taken.
  The `beq` branch at 0x1a4e0 targets 0x1a330 and is always taken.
  The `beq` branch at 0x1a500 targets 0x1a330 and is always taken.
  The `beq` branch at 0x1a520 targets 0x1a330 and is always taken.
  The `beq` branch at 0x1a540 targets 0x1a330 and is always taken.
  The `beq` branch at 0x1a554 targets 0x1a69c, is taken when v0(=ret(error_check_poisoned_state)) == s1(=0x3), and falls through when v0(=ret(error_check_poisoned_state)) != s1(=0x3).
  The `beq` branch at 0x1a55c targets 0x1a334 and is always taken.
  The `beq` branch at 0x1a574 targets 0x1a6b8, is taken when v0(=ret(error_check_memory_access)) == 0, and falls through when v0(=ret(error_check_memory_access)) != 0.
  The `beq` branch at 0x1a584 targets 0x1a55c and is always taken.
  The `beq` branch at 0x1a598 targets 0x1a5b0, is taken when v0(=ret(error_check_memory_access)) == 0, and falls through when v0(=ret(error_check_memory_access)) != 0.
  The `beq` branch at 0x1a5a8 targets 0x1a55c and is always taken.
  The `beq` branch at 0x1a5b4 targets 0x1a6d4, is taken when t0(=a2) == 0, and falls through when t0(=a2) != 0.
  The `beq` branch at 0x1a5bc targets 0x1a5fc, is taken when s2(=a3) == 0, and falls through when s2(=a3) != 0.
  The `beq` branch at 0x1a5c8 targets 0x1a610, is taken when s2(=a3) == t1(=0x2), and falls through when s2(=a3) != t1(=0x2).
  The `beq` branch at 0x1a5d4 targets 0x1a620, is taken when s2(=a3) == t2(=0x1), and falls through when s2(=a3) != t2(=0x1).
  The `beq` branch at 0x1a5dc targets 0x1a618, is taken when s2(=a3) == s1(=0x3), and falls through when s2(=a3) != s1(=0x3).
  The `bne` branch at 0x1a5ec targets 0x1a6f4, is taken when a2(=sym(.rodata)+28464) != 0, and falls through when a2(=sym(.rodata)+28464) == 0.
  The `beq` branch at 0x1a5f4 targets 0x1a55c and is always taken.
  The `beq` branch at 0x1a600 targets 0x1a5f4, is taken when a2(=sym(.rodata)+28464) == 0, and falls through when a2(=sym(.rodata)+28464) != 0.
  The `beq` branch at 0x1a608 targets 0x1a6f4 and is always taken.
  The `beq` branch at 0x1a610 targets 0x1a600 and is always taken.
  The `beq` branch at 0x1a618 targets 0x1a600 and is always taken.
  The `beq` branch at 0x1a640 targets 0x1a5f4, is taken when v0(=ret(kl_ioerror_handler)) == 0, and falls through when v0(=ret(kl_ioerror_handler)) != 0.
  The `beq` branch at 0x1a648 targets 0x1a600 and is always taken.
  The `beq` branch at 0x1a664 targets 0x1a55c and is always taken.
  The `beq` branch at 0x1a67c targets 0x1a55c and is always taken.
  The `beq` branch at 0x1a694 targets 0x1a55c and is always taken.
  The `beq` branch at 0x1a6b0 targets 0x1a55c and is always taken.
  The `beq` branch at 0x1a6cc targets 0x1a55c and is always taken.
  The `beq` branch at 0x1a6e8 targets 0x1a55c and is always taken.
  The `beq` branch at 0x1a704 targets 0x1a55c and is always taken.
  The return at 0x1a344 has v0 = ?.
  The instructions from 0x1a6f0 to 0x1a6f0 are not reached by any path from the entry, and their branches are not listed.

- `huberror_process_stack_entry` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x1a70c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x1a70c-0x1a804 (248 bytes).
  It occupies 248 bytes.
  The `sd` at 0x1a784 stores 8 bytes to a3 (arg3 at entry) +0x0.
  The `jal` at 0x1a774 calls huberror_process_wrb_error with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1a7cc calls huberror_process_rrb_error with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1a7e4 calls cmn_err with a0=0x14, a1=sym(.rodata)+28464, a2=a2 at entry (arg2), a3=a3 at entry (arg3), a6=a0 at entry (arg0).
  The `beq` branch at 0x1a728 targets 0x1a79c, is taken when a2 == at(=0x1), and falls through when a2 != at(=0x1).
  The `bne` branch at 0x1a730 targets 0x1a7dc, is taken when a2 != v0(=0x2), and falls through when a2 == v0(=0x2).
  The `beq` branch at 0x1a76c targets 0x1a7cc, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `bne` branch at 0x1a7c4 targets 0x1a774, is taken when (v0(?) & 0x1) != 0, and falls through when (v0(?) & 0x1) == 0.
  The `beq` branch at 0x1a7d4 targets 0x1a780 and is always taken.
  The `beq` branch at 0x1a7fc targets 0x1a76c and is always taken.
  The return at 0x1a794 has v0 = one of ret(huberror_process_wrb_error), ret(huberror_process_rrb_error).

- `hubiio_crb_free` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x1aab8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x1aab8-0x1ab58 (160 bytes).
  It occupies 160 bytes.
  4 such `lh` accesses load 2 bytes from a0 (arg0 at entry) +0xa, including `lh` at 0x1aabc, `lh` at 0x1aae8, `lh` at 0x1aafc.
  The `ld` at 0x1aadc loads 8 bytes from ((a1 << 0x5) + ([a0+10]:2 << 0x21)) -0x6dfffffffe3ffc00.
  The `sd` at 0x1aae4 stores 8 bytes to ((a1 << 0x5) + ([a0+10]:2 << 0x21)) -0x6dfffffffe3ffc00.
  The `sd` at 0x1aaf8 stores 8 bytes to ([a0+10]:2 << 0x21) -0x6dfffffffe3ffc70.
  2 such `ld` accesses load 8 bytes from ([a0+10]:2 << 0x21) -0x6dfffffffe3ffc70, including `ld` at 0x1ab08, `ld` at 0x1ab34.
  The `jal` at 0x1ab20 calls us_delay with a0=0x1, a1=?, a2=?, a3=?.
  The `beq` branch at 0x1ab18 targets 0x1ab44, is taken when (at(=[([a0+10]:2 << 0x21)-7926335344142711920]:8) & 0x10) == 0, and falls through when (at(=[([a0+10]:2 << 0x21)-7926335344142711920]:8) & 0x10) != 0.
  The `bne` branch at 0x1ab3c targets 0x1ab20, is taken when (a5(=[([a0+10]:2 << 0x21)-7926335344142711920]:8) & 0x10) != 0, and falls through when (a5(=[([a0+10]:2 << 0x21)-7926335344142711920]:8) & 0x10) == 0.
  The return at 0x1ab50 has v0 = one of (a1 | 0x10), ret(us_delay).

- `hubii_check_widget_disabled` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x1ae80 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x1ae80-0x1aee8 (104 bytes).
  It occupies 104 bytes.
  The `ld` at 0x1aea8 loads 8 bytes from table(0x9200000001c00198) +0x0.
  The `ld` at 0x1aecc loads 8 bytes from (a0 << 0x21) -0x6dfffffffe3ffff8.
  The `beq` branch at 0x1ae8c targets 0x1ae98, is taken when a1 >= 0x8 (signed), and falls through when a1 < 0x8 (signed).
  The `beq` branch at 0x1aeb4 targets 0x1aec4, is taken when (v0(=entry(0x9200000001c00198)) & v1(=0xf000000000000)) == 0, and falls through when (v0(=entry(0x9200000001c00198)) & v1(=0xf000000000000)) != 0.
  The `beq` branch at 0x1aed8 targets 0x1aebc, is taken when (v1(=[(a0 << 0x21)-7926335344142712824]:8) & a0(=0x100000000)) == 0, and falls through when (v1(=[(a0 << 0x21)-7926335344142712824]:8) & a0(=0x100000000)) != 0.
  The return at 0x1aebc has v0 = one of 0x0, 0x1.
  The return at 0x1aee0 has v0 = 0x1.

- `hubii_prb_handler` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x1aee8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x1aee8-0x1af30 (72 bytes).
  It occupies 72 bytes.
  The `lh` at 0x1aee8 loads 2 bytes from a1 (arg1 at entry) +0xa.
  The `sd` at 0x1af20 stores 8 bytes to ([a1+10]:2 << 0x21) -0x6dfffffffe3ffe08.
  The `jal` at 0x1af1c calls cmn_err with a0=0x4, a1=sym(.rodata)+28464, a2=[a1+10]:2, a3=a2 at entry (arg2), a4=0x9200000001c00000.
  The return at 0x1af28 has v0 = ret(cmn_err).

- `hubiio_prb_error_handler` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x1af30 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x1af30-0x1affc (204 bytes).
  It occupies 204 bytes.
  The `lh` at 0x1af3c loads 2 bytes from a1 (arg1 at entry) +0xa.
  The `ld` at 0x1af54 loads 8 bytes from ([a1+10]:2 << 0x21) -0x6dfffffffe3ffe68.
  The `ld` at 0x1af88 loads 8 bytes from ?.
  The `jal` at 0x1afd8 calls hubii_prb_handler [0x1aee8] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0x1afec calls hubii_prb_handler [0x1aee8] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0x0, a3=a3 at entry (arg3).
  The `bltz` branch at 0x1af68 targets 0x1afe8, is taken when at(=([([a1+10]:2 << 0x21)-7926335344142712424]:8 << 0xf)) < 0 (signed), and falls through when at(=([([a1+10]:2 << 0x21)-7926335344142712424]:8 << 0xf)) >= 0 (signed).
  The `bltz` branch at 0x1af90 targets 0x1afcc, is taken when t8(?) < 0 (signed), and falls through when t8(?) >= 0 (signed).
  The `bne` branch at 0x1afa0 targets 0x1af7c, is taken when s1(?) < 0x10 (signed), and falls through when s1(?) >= 0x10 (signed).
  The `beq` branch at 0x1afe0 targets 0x1af9c and is always taken.
  The `beq` branch at 0x1aff4 targets 0x1af74 and is always taken.
  The return at 0x1afc4 has v0 = ?.

- `hubii_eint_handler` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x1affc (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x1affc-0x1b19c (416 bytes).
  It occupies 416 bytes.
  5 such `lh` accesses load 2 bytes from ?, including `lh` at 0x1b048, `lh` at 0x1b088, `lh` at 0x1b0c4.
  The `ld` at 0x1b05c loads 8 bytes from table(0x92000000018000a0) +0x0.
  The `ld` at 0x1b098 loads 8 bytes from table(0x9200000001c00008) +0x0.
  The `sd` at 0x1b0d8 stores 8 bytes to table(0x9200000001c001f8) +0x0.
  The `ld` at 0x1b0fc loads 8 bytes from table(0x9200000001c00138) +0x0.
  The `sd` at 0x1b114 stores 8 bytes to table(0x9200000001c00138) +0x0.
  The `ld` at 0x1b15c loads 8 bytes from table(0x9200000001c001e8) +0x0.
  The `jal` at 0x1b008 calls check_ni_errors with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1b024 calls hubni_error_handler with a0=sym(.rodata)+28464, a1=0x1, a2=?, a3=?.
  The `jal` at 0x1b03c calls hwgraph_info_get_LBL with a0=(a0 << 0x0), a1=sym(.rodata)+28464, a2=sp-48, a3=?.
  The `jal` at 0x1b074 calls hubni_error_handler_nasid [0x18d20] with a0=sym(.rodata)+28464, a1=?, a2=0x1, a3=?, a4=0x4000000000000000.
  The `jal` at 0x1b084 calls cleanup_remote_pi with a0=?, a1=0x7e, a2=?, a3=?.
  The `jal` at 0x1b0ac calls hubiio_crb_error_handler with a0=(a0 << 0x0), a1=?, a2=?, a3=?.
  The `jal` at 0x1b0b8 calls hubiio_prb_error_handler with a0=(a0 << 0x0), a1=?, a2=?, a3=?.
  The `jal` at 0x1b12c calls cmn_err with a0=0x0, a1=sym(.rodata)+28464, a2=?, a3=sym(.rodata)+28464, a4=0x4000000000000000, a7=(entry(0x9200000001c00008) << 0x36).
  The `beq` branch at 0x1b014 targets 0x1b02c, is taken when v0(=ret(check_ni_errors)) == 0, and falls through when v0(=ret(check_ni_errors)) != 0.
  The `beq` branch at 0x1b068 targets 0x1b094, is taken when (a2(=entry(0x92000000018000a0)) & a4(=0x4000000000000000)) == 0, and falls through when (a2(=entry(0x92000000018000a0)) & a4(=0x4000000000000000)) != 0.
  The `beq` branch at 0x1b08c targets 0x1b0c0 and is always taken.
  The `bltz` branch at 0x1b0a0 targets 0x1b118, is taken when a2(=(entry(0x9200000001c00008) << 0x1f)) < 0 (signed), and falls through when a2(=(entry(0x9200000001c00008) << 0x1f)) >= 0 (signed).
  The `bgez` branch at 0x1b118 targets 0x1b13c, is taken when a7(=(entry(0x9200000001c00008) << 0x36)) >= 0 (signed), and falls through when a7(=(entry(0x9200000001c00008) << 0x36)) < 0 (signed).
  The `beq` branch at 0x1b134 targets 0x1b0a8 and is always taken.
  The `bgez` branch at 0x1b13c targets 0x1b14c, is taken when t0(=(entry(0x9200000001c00008) << 0x3a)) >= 0 (signed), and falls through when t0(=(entry(0x9200000001c00008) << 0x3a)) < 0 (signed).
  The `beq` branch at 0x1b144 targets 0x1b124 and is always taken.
  The `bgez` branch at 0x1b14c targets 0x1b15c, is taken when t1(=(entry(0x9200000001c00008) << 0x3b)) >= 0 (signed), and falls through when t1(=(entry(0x9200000001c00008) << 0x3b)) < 0 (signed).
  The `beq` branch at 0x1b154 targets 0x1b124 and is always taken.
  The `beq` branch at 0x1b164 targets 0x1b174, is taken when (a0(=entry(0x9200000001c001e8)) & 0x1) == 0, and falls through when (a0(=entry(0x9200000001c001e8)) & 0x1) != 0.
  The `beq` branch at 0x1b16c targets 0x1b124 and is always taken.
  The `beq` branch at 0x1b174 targets 0x1b184, is taken when t3(?) == 0, and falls through when t3(?) != 0.
  The `beq` branch at 0x1b17c targets 0x1b124 and is always taken.
  The `beq` branch at 0x1b184 targets 0x1b194, is taken when t8(?) == 0, and falls through when t8(?) != 0.
  The `beq` branch at 0x1b18c targets 0x1b124 and is always taken.
  The `beq` branch at 0x1b194 targets 0x1b124 and is always taken.
  The return at 0x1b110 has v0 = one of ret(cleanup_remote_pi), ret(hubiio_prb_error_handler).

- `ii_llp_error_monitor` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x1b19c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x1b19c-0x1b204 (104 bytes).
  It occupies 104 bytes.
  The `ld` at 0x1b1a0 loads 8 bytes from abs 0x9200000001400130.
  The `sd` at 0x1b1b0 stores 8 bytes to abs 0x9200000001400130.
  The `ld` at 0x1b1bc loads 8 bytes from a0 (arg0 at entry) +0x0.
  The `sd` at 0x1b1c4 stores 8 bytes to a0 (arg0 at entry) +0x0.
  The `ld` at 0x1b1d0 loads 8 bytes from a0 (arg0 at entry) +0x8.
  The `sd` at 0x1b1d8 stores 8 bytes to a0 (arg0 at entry) +0x8.
  The `lbu` at 0x1b1e4 loads 1 byte from a0 (arg0 at entry) +0x10.
  The `sb` at 0x1b1f0 stores 1 byte to a0 (arg0 at entry) +0x10.
  The `lbu` at 0x1b1f4 loads 1 byte from a0 (arg0 at entry) +0x11.
  The `sb` at 0x1b200 stores 1 byte to a0 (arg0 at entry) +0x11.
  The `beq` branch at 0x1b1b4 targets 0x1b1e4, is taken when a4(=0xffff) == a3(?), and falls through when a4(=0xffff) != a3(?).
  The `beq` branch at 0x1b1c8 targets 0x1b1f4, is taken when a4(=0xffff) == a2(?), and falls through when a4(=0xffff) != a2(?).
  The `beq` branch at 0x1b1ec targets 0x1b1c8 and is always taken.
  The return at 0x1b1dc has v0 = ?.
  The return at 0x1b1fc has v0 = ?.

- `ni_llp_error_monitor` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x1b204 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x1b204-0x1b330 (300 bytes).
  It occupies 300 bytes.
  The `ld` at 0x1b208 loads 8 bytes from abs 0x9200000001680120.
  The `ld` at 0x1b2a4 loads 8 bytes from a0 (arg0 at entry) +0x0.
  The `sd` at 0x1b2ac stores 8 bytes to a0 (arg0 at entry) +0x0.
  The `ld` at 0x1b2bc loads 8 bytes from a0 (arg0 at entry) +0x8.
  The `sd` at 0x1b2c4 stores 8 bytes to a0 (arg0 at entry) +0x8.
  The `ld` at 0x1b2d0 loads 8 bytes from a0 (arg0 at entry) +0x10.
  The `sd` at 0x1b2d8 stores 8 bytes to a0 (arg0 at entry) +0x10.
  The `lbu` at 0x1b2e8 loads 1 byte from a0 (arg0 at entry) +0x18.
  The `sb` at 0x1b2f4 stores 1 byte to a0 (arg0 at entry) +0x18.
  The `lbu` at 0x1b2f8 loads 1 byte from a0 (arg0 at entry) +0x19.
  The `sb` at 0x1b304 stores 1 byte to a0 (arg0 at entry) +0x19.
  The `lbu` at 0x1b308 loads 1 byte from a0 (arg0 at entry) +0x1a.
  The `sb` at 0x1b314 stores 1 byte to a0 (arg0 at entry) +0x1a.
  The `jal` at 0x1b320 calls cmn_err with a0=0x4, a1=sym(.rodata)+28464, a2=[0x9200000001680120]:8, a3=?.
  The `bltz` branch at 0x1b224 targets 0x1b318, is taken when at(=([0x9200000001680120]:8 << 0xb)) < 0 (signed), and falls through when at(=([0x9200000001680120]:8 << 0xb)) >= 0 (signed).
  The `bne` branch at 0x1b234 targets 0x1b31c, is taken when (a7(?) & 0xf) != 0, and falls through when (a7(?) & 0xf) == 0.
  The `bne` branch at 0x1b244 targets 0x1b31c, is taken when (t0(?) & 0xf) != 0, and falls through when (t0(?) & 0xf) == 0.
  The `bne` branch at 0x1b254 targets 0x1b31c, is taken when (t1(?) & 0xf) != 0, and falls through when (t1(?) & 0xf) == 0.
  The `bne` branch at 0x1b264 targets 0x1b318, is taken when (t2(?) & 0xf) != 0, and falls through when (t2(?) & 0xf) == 0.
  The `bne` branch at 0x1b270 targets 0x1b31c, is taken when (t3(?) & 0xf) != 0, and falls through when (t3(?) & 0xf) == 0.
  The `bne` branch at 0x1b27c targets 0x1b31c, is taken when (a3(?) & 0xf) != 0, and falls through when (a3(?) & 0xf) == 0.
  The `bne` branch at 0x1b284 targets 0x1b31c, is taken when a4(?) != 0, and falls through when a4(?) == 0.
  The `beq` branch at 0x1b29c targets 0x1b2e8, is taken when a7(=0xff) == a6(?), and falls through when a7(=0xff) != a6(?).
  The `beq` branch at 0x1b2b4 targets 0x1b2f8, is taken when a7(=0xff) == a5(?), and falls through when a7(=0xff) != a5(?).
  The `beq` branch at 0x1b2c8 targets 0x1b308, is taken when a7(=0xff) == a3(?), and falls through when a7(=0xff) != a3(?).
  The `beq` branch at 0x1b2f0 targets 0x1b2b0 and is always taken.
  The `beq` branch at 0x1b300 targets 0x1b2c8 and is always taken.
  The `beq` branch at 0x1b310 targets 0x1b2dc and is always taken.
  The `beq` branch at 0x1b328 targets 0x1b2e0 and is always taken.
  The return at 0x1b2e0 has v0 = one of ?, ret(cmn_err).

- `cleanup_remote_pi` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x1b330 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x1b330-0x1b370 (64 bytes).
  It occupies 64 bytes.
  The `sd` at 0x1b364 stores 8 bytes to ((a0 << 0x21) + one of 0x9200000001800090, 0x9200000001a00090) +0x0.
  The `bne` branch at 0x1b360 targets 0x1b348, is taken when a3(?) < 0x2 (signed), and falls through when a3(?) >= 0x2 (signed).
  The return at 0x1b368 has v0 = ?.

- `dump_error_spool` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x1b76c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x1b76c-0x1b93c (464 bytes).
  It occupies 464 bytes.
  The `ld` at 0x1b780 loads 8 bytes from (sym(pdaindr) + (a0 << 0x4)) +0x8.
  The `lbu` at 0x1b788 loads 1 byte from [(sym(pdaindr) + (a0 << 0x4))+8]:8 +0x528.
  The `lh` at 0x1b794 loads 2 bytes from [(sym(pdaindr) + (a0 << 0x4))+8]:8 +0x42c.
  2 such `ld` accesses load 8 bytes from (([[(sym(pdaindr) + (a0 << 0x4))+8]:8+1068]:2 << 0x21) + one of 0x9200000001800428, 0x9200000001a00428) +0x0, including `ld` at 0x1b7c8, `ld` at 0x1b7e8.
  3 such `ld` accesses load 8 bytes from ?, including `ld` at 0x1b824, `ld` at 0x1b88c, `ld` at 0x1b8b4.
  The `jalr` at 0x1b834 calls (unknown callee) with a0=sym(.rodata)+28464, a1=a0 at entry (arg0), a2=sym(.rodata)+28464, a3=0x428, a4=sym(.rodata)+28464, a5=a0 at entry (arg0), a7=0x9200000001800000.
  The `jal` at 0x1b890 calls print_spool_entry with a0=?, a1=?, a2=a1 at entry (arg1), a3=?.
  The `jal` at 0x1b8d0 calls memory_present with a0=?, a1=?, a2=?, a3=?.
  The `jalr` at 0x1b8f4 calls (unknown callee) with a0=sym(.rodata)+28464, a1=?, a2=?, a3=?.
  The `jalr` at 0x1b914 calls (unknown callee) with a0=sym(.rodata)+28464, a1=?, a2=?, a3=?.
  The `beq` branch at 0x1b7e0 targets 0x1b7fc, is taken when at(=[(([[(sym(pdaindr) + (a0 << 0x4))+8]:8+1068]:2 << 0x21) + one of 0x9200000001800428, 0x9200000001a00428)]:8) == 0, and falls through when at(=[(([[(sym(pdaindr) + (a0 << 0x4))+8]:8+1068]:2 << 0x21) + one of 0x9200000001800428, 0x9200000001a00428)]:8) != 0.
  The `beq` branch at 0x1b7fc targets 0x1b92c, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0x1b820 targets 0x1b830, is taken when a0(=[sym(filter_error_spool)]) == 0, and falls through when a0(=[sym(filter_error_spool)]) != 0.
  The `beq` branch at 0x1b878 targets 0x1b8fc, is taken when s0(?) >= s3(?) (unsigned), and falls through when s0(?) < s3(?) (unsigned).
  The `beq` branch at 0x1b880 targets 0x1b934 and is always taken.
  The `bne` branch at 0x1b8a4 targets 0x1b8e8, is taken when s3(?) < s0(?) (unsigned), and falls through when s3(?) >= s0(?) (unsigned).
  The `beq` branch at 0x1b8ac targets 0x1b88c, is taken when ra(=[sym(filter_error_spool)]) == 0, and falls through when ra(=[sym(filter_error_spool)]) != 0.
  The `bltz` branch at 0x1b8bc targets 0x1b888, is taken when at(?) < 0 (signed), and falls through when at(?) >= 0 (signed).
  The `bne` branch at 0x1b8c4 targets 0x1b88c, is taken when a0(?) != 0, and falls through when a0(?) == 0.
  The `bne` branch at 0x1b8d8 targets 0x1b88c, is taken when v0(=ret(memory_present)) != 0, and falls through when v0(=ret(memory_present)) == 0.
  The `beq` branch at 0x1b8e0 targets 0x1b89c and is always taken.
  The `beq` branch at 0x1b8e8 targets 0x1b8fc, is taken when s4(?) == 0, and falls through when s4(?) != 0.
  The `beq` branch at 0x1b92c targets 0x1b810 and is always taken.
  The `beq` branch at 0x1b934 targets 0x1b8ac and is always taken.
  The return at 0x1b924 has v0 = ret(?).

- `err_int_unblock_mask` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x1b980
  It reads the halfword at -0x3bd8 and uses it to index the per-processor table, then reads a byte at +0x528 of that entry. It stores to the register at 0x9200000001000400 (0x1b9b4), and loads and stores one of 0x9200000001000408 or 0x9200000001000410 (0x1b9bc, 0x1b9c8); the facts do not say which. The branch at 0x1b9a8 is taken when a1 == 0. The name suggests unblocking an error interrupt mask, but the bit changed and the stored values are not shown.
  Grade: inferred.
  Reviewed: 2026-11-12

- `md_int_block` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x1b9cc (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x1b9cc-0x1ba18 (76 bytes).
  It occupies 76 bytes.
  The `lh` at 0x1b9cc loads 2 bytes from abs 0xffffffffffffc428.
  The `ld` at 0x1b9dc loads 8 bytes from (sym(pdaindr) + ([-0x3bd8]:2 << 0x4)) +0x8.
  The `lbu` at 0x1b9e0 loads 1 byte from [(sym(pdaindr) + ([-0x3bd8]:2 << 0x4))+8]:8 +0x528.
  The `ld` at 0x1ba04 loads 8 bytes from one of 0x9200000001000408, 0x9200000001000410 +0x0.
  The `sd` at 0x1ba14 stores 8 bytes to one of 0x9200000001000408, 0x9200000001000410 +0x0.
  The return at 0x1ba10 has v0 = one of 0x9200000001000408, 0x9200000001000410.

- `md_int_unblock` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x1ba18 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x1ba18-0x1ba60 (72 bytes).
  It occupies 72 bytes.
  The `lh` at 0x1ba18 loads 2 bytes from abs 0xffffffffffffc428.
  The `ld` at 0x1ba28 loads 8 bytes from (sym(pdaindr) + ([-0x3bd8]:2 << 0x4)) +0x8.
  The `lbu` at 0x1ba2c loads 1 byte from [(sym(pdaindr) + ([-0x3bd8]:2 << 0x4))+8]:8 +0x528.
  The `ld` at 0x1ba4c loads 8 bytes from one of 0x9200000001000408, 0x9200000001000410 +0x0.
  The `sd` at 0x1ba5c stores 8 bytes to one of 0x9200000001000408, 0x9200000001000410 +0x0.
  The return at 0x1ba58 has v0 = one of 0x9200000001000408, 0x9200000001000410.

- `klerror_global_check` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x1bacc (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x1bacc-0x1bb38 (108 bytes).
  It occupies 108 bytes.
  2 such `ld` accesses load 8 bytes from abs 0x9200000001030100, including `ld` at 0x1bae4, `ld` at 0x1bb24.
  The `ll` at 0x1baf8 loads 4 bytes from sym(_prom_cleared) +0xe0.
  The `sc` at 0x1bb04 stores 4 bytes to sym(_prom_cleared) +0xe0.
  The `beq` branch at 0x1bad8 targets 0x1bb24, is taken when v0(=[sym(.sdata)+216]:8) == 0, and falls through when v0(=[sym(.sdata)+216]:8) != 0.
  The `beq` branch at 0x1baf0 targets 0x1bb24, is taken when at(?) >= v1(=0x1000000) (unsigned), and falls through when at(?) < v1(=0x1000000) (unsigned).
  The `beql` branch at 0x1bb08 targets 0x1baf8, is taken when a0(=[sym(.sdata)+224]+1) == 0, and falls through when a0(=[sym(.sdata)+224]+1) != 0; its branch-likely delay slot `nop` at 0x1bb0c runs only when taken and is annulled on fall-through.
  The return at 0x1bb1c has v0 = one of -0x1, 0x0.
  The return at 0x1bb30 has v0 = 0x0.

- `stop_all_cpus` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x1bcf0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x1bcf0-0x1bf2c (572 bytes).
  It occupies 572 bytes.
  3 such `ld` accesses load 8 bytes from abs 0x9200000001000020, including `ld` at 0x1bd38, `ld` at 0x1be80, `ld` at 0x1beb8.
  The `sd` at 0x1bd6c stores 8 bytes to abs 0x9200000001000410.
  2 such `ld` accesses load 8 bytes from abs 0x9200000001600000, including `ld` at 0x1bd74, `ld` at 0x1bda4.
  The `ld` at 0x1bd98 loads 8 bytes from abs 0x9200000001604020.
  The `ld` at 0x1bd9c loads 8 bytes from abs 0x9200000001780000.
  The `ld` at 0x1bda0 loads 8 bytes from abs 0x9200000001604028.
  The `sd` at 0x1be64 stores 8 bytes to table(0x9200000001fa0038) +0x0.
  The `sd` at 0x1be7c stores 8 bytes to table(0x9200000001800000) +0x0.
  The `sd` at 0x1be98 stores 8 bytes to ?.
  The `sd` at 0x1bf00 stores 8 bytes to abs 0x9200000001000408.
  The `beq` branch at 0x1bd64 targets 0x1befc, is taken when (at(=[0x9200000001000020]:8) & 0x1) == 0, and falls through when (at(=[0x9200000001000020]:8) & 0x1) != 0.
  The `beq` branch at 0x1bd80 targets 0x1bf04, is taken when (a1(?) & 0x3) == 0, and falls through when (a1(?) & 0x3) != 0.
  The `beq` branch at 0x1bd88 targets 0x1bd98, is taken when a1(?) == a2(=0x1), and falls through when a1(?) != a2(=0x1).
  The `beq` branch at 0x1bd90 targets 0x1bf0c, is taken when a1(?) == a3(=0x2), and falls through when a1(?) != a3(=0x2).
  The `beq` branch at 0x1bdc0 targets 0x1becc, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x1bdcc targets 0x1bf20 and is always taken.
  The `bne` branch at 0x1bddc targets 0x1becc, is taken when s5(?) < a4(?) (unsigned), and falls through when s5(?) >= a4(?) (unsigned).
  The `bne` branch at 0x1be08 targets 0x1bf18, is taken when (s4(?) & v0(?)) != 0, and falls through when (s4(?) & v0(?)) == 0.
  The `beq` branch at 0x1be10 targets 0x1bdd4 and is always taken.
  The `beq` branch at 0x1be18 targets 0x1be48, is taken when a4(?) == a3(?), and falls through when a4(?) != a3(?).
  The `beq` branch at 0x1be30 targets 0x1be48, is taken when a2(?) >= 0x4 (signed), and falls through when a2(?) < 0x4 (signed).
  The `bne` branch at 0x1be38 targets 0x1be18, is taken when t1(?) != 0, and falls through when t1(?) == 0.
  The `bnel` branch at 0x1be40 targets 0x1be24, is taken when a4(?) != a6(=-0x1), and falls through when a4(?) == a6(=-0x1); its branch-likely delay slot `addiu a2,a2,1` at 0x1be44 runs only when taken and is annulled on fall-through.
  The `bne` branch at 0x1be48 targets 0x1bdd4, is taken when a2(?) != s7(=0x4), and falls through when a2(?) == s7(=0x4).
  The `beq` branch at 0x1be60 targets 0x1beb0 and is always taken.
  The `bne` branch at 0x1be78 targets 0x1be98, is taken when t0(?) != a4(?), and falls through when t0(?) == a4(?).
  The `beq` branch at 0x1be90 targets 0x1be9c, is taken when a2(?) == at(=[0x9200000001000020]:8), and falls through when a2(?) != at(=[0x9200000001000020]:8).
  The `beq` branch at 0x1bea8 targets 0x1bdd4, is taken when a1(?) >= 0x2 (signed), and falls through when a1(?) < 0x2 (signed).
  The `bne` branch at 0x1beb0 targets 0x1be6c, is taken when t0(?) != a4(?), and falls through when t0(?) == a4(?).
  The `beq` branch at 0x1bebc targets 0x1be80, is taken when a3(?) == v0(=[0x9200000001000020]:8), and falls through when a3(?) != v0(=[0x9200000001000020]:8).
  The `beq` branch at 0x1bec4 targets 0x1be6c and is always taken.
  The `beq` branch at 0x1befc targets 0x1bd70 and is always taken.
  The `beq` branch at 0x1bf04 targets 0x1bd98 and is always taken.
  The `beq` branch at 0x1bf10 targets 0x1bd98 and is always taken.
  The `beq` branch at 0x1bf18 targets 0x1be38 and is always taken.
  The `beq` branch at 0x1bf24 targets 0x1bde8 and is always taken.
  The return at 0x1bef4 has v0 = ?.
  The instructions from 0x1be68 to 0x1be68 are not reached by any path from the entry, and their branches are not listed.

- `sn0_error_dump` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x1bf2c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x1bf2c-0x1c0f4 (456 bytes).
  It occupies 456 bytes.
  The `lh` at 0x1bf60 loads 2 bytes from sym(error_consistency_check) +0x4.
  The `lh` at 0x1bf70 loads 2 bytes from abs 0xffffffffffffc428.
  The `sh` at 0x1bf94 stores 2 bytes to sym(error_consistency_check) +0x4.
  6 such `lw` accesses load 4 bytes from sym(error_consistency_check) +0x0, including `lw` at 0x1bfcc, `lw` at 0x1bff8, `lw` at 0x1c048.
  6 such `sw` accesses store 4 bytes to sym(error_consistency_check) +0x0, including `sw` at 0x1c03c, `sw` at 0x1c054, `sw` at 0x1c094.
  The `jal` at 0x1bf34 calls probe_routers with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1bf48 calls printf with a0=sym(.rodata)+36904, a1=?, a2=?, a3=?.
  The `jal` at 0x1bf58 calls mutex_spinlock with a0=sym(error_consistency_check), a1=?, a2=?, a3=?.
  The `jal` at 0x1bf7c calls mutex_spinunlock with a0=sym(error_consistency_check), a1=ret(mutex_spinlock), a2=?, a3=?, a4=[-0x3bd8]:2, a5=[sym(error_consistency_check)+4]:2.
  The `jal` at 0x1bf84 calls sn0_skip_dump with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1bf98 calls mutex_spinunlock with a0=sym(error_consistency_check), a1=ret(mutex_spinlock), a2=?, a3=?, a4=[-0x3bd8]:2, a5=[sym(error_consistency_check)+4]:2.
  The `jal` at 0x1bfa0 calls splhi with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1bfa8 calls enter_panic_mode with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1bfb0 calls stop_all_cpus [0x1bcf0] with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1bfb8 calls get_nasid with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1bfc4 calls kf_hint_set with a0=ret(get_nasid), a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0x1c010 calls exit_panic_mode with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1c018 calls splx with a0=ret(splhi), a1=?, a2=?, a3=?.
  The `jal` at 0x1c040 calls sn_fru_entry with a0=sym(printf), a1=?, a2=?, a3=?.
  The `jal` at 0x1c064 calls cmn_err_tag with a0=0xb56, a1=0x14, a2=sym(.rodata)+36904, a3=?, a4=[sym(error_consistency_check)].
  The `jal` at 0x1c07c calls cmn_err_tag with a0=0xb57, a1=0x14, a2=sym(.rodata)+36904, a3=?.
  The `jal` at 0x1c090 calls kl_dump_hw_state with a0=?, a1=?, a2=?, a3=([sym(error_consistency_check)] | 0x1), a4=[sym(error_consistency_check)].
  The `jal` at 0x1c0b4 calls kl_error_show_dump with a0=sym(.rodata)+36904, a1=sym(.rodata)+36904, a2=?, a3=?.
  The `jal` at 0x1c0d4 calls cmn_err_tag with a0=0xb55, a1=0x14, a2=sym(.rodata)+36904, a3=?, a4=[sym(error_consistency_check)].
  The `jal` at 0x1c0dc calls exit_panic_mode with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1c0e4 calls splx with a0=ret(splhi), a1=?, a2=?, a3=?.
  The `beq` branch at 0x1bf3c targets 0x1bf50, is taken when v0(=ret(probe_routers)) == 0, and falls through when v0(=ret(probe_routers)) != 0.
  The `beq` branch at 0x1bf6c targets 0x1bf94, is taken when a5(=[sym(error_consistency_check)+4]:2) == a1(=-0x1), and falls through when a5(=[sym(error_consistency_check)+4]:2) != a1(=-0x1).
  The `beq` branch at 0x1bf74 targets 0x1bf94, is taken when a4(=[-0x3bd8]:2) == a5(=[sym(error_consistency_check)+4]:2), and falls through when a4(=[-0x3bd8]:2) != a5(=[sym(error_consistency_check)+4]:2).
  The `beq` branch at 0x1bf8c targets 0x1c024 and is always taken.
  The `beq` branch at 0x1bfd4 targets 0x1c08c, is taken when (a4(=[sym(error_consistency_check)]) & 0x1) == 0, and falls through when (a4(=[sym(error_consistency_check)]) & 0x1) != 0.
  The `beq` branch at 0x1bfdc targets 0x1c0cc, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x1bfe8 targets 0x1c0a8, is taken when (a4(?) & 0x10) == 0, and falls through when (a4(?) & 0x10) != 0.
  The `beq` branch at 0x1bff4 targets 0x1c058, is taken when (a4(?) & 0x20) == 0, and falls through when (a4(?) & 0x20) != 0.
  The `beq` branch at 0x1c000 targets 0x1c030, is taken when (a4(?) & 0x4) == 0, and falls through when (a4(?) & 0x4) != 0.
  The `beq` branch at 0x1c008 targets 0x1c074, is taken when a7(?) == 0, and falls through when a7(?) != 0.
  The `beq` branch at 0x1c038 targets 0x1c04c, is taken when t0(=[sym(sn_fru_enabled)]) == 0, and falls through when t0(=[sym(sn_fru_enabled)]) != 0.
  The `beq` branch at 0x1c050 targets 0x1c010 and is always taken.
  The `beq` branch at 0x1c06c targets 0x1bffc and is always taken.
  The `beq` branch at 0x1c084 targets 0x1c010 and is always taken.
  The `beq` branch at 0x1c0a0 targets 0x1bfe4 and is always taken.
  The `beq` branch at 0x1c0c4 targets 0x1bffc and is always taken.
  The `beq` branch at 0x1c0ec targets 0x1c024 and is always taken.
  The return at 0x1c028 has v0 = one of ret(sn0_skip_dump), ret(splx).

- `sn0_error_state` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x1c0f4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x1c0f4-0x1c120 (44 bytes).
  It occupies 44 bytes.
  The `jal` at 0x1c0fc calls kl_dump_hw_state with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1c10c calls kl_error_show_dump with a0=sym(.rodata)+36904, a1=sym(.rodata)+36904, a2=?, a3=?.
  The return at 0x1c118 has v0 = ret(kl_error_show_dump).

- `handle_io_buserr` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x1cd5c
  Role (from name): handles an I/O bus error for the calling node. It calls `get_matching_spool_addr`, and its result is compared with 0, -1, 1 and 2 by the branches at 0x1cdc0 to 0x1cddc. `kl_ioerror_handler` is called at three sites (0x1ce58, 0x1cecc, 0x1cf88) with a3 = 5. `cmn_err_tag` is called with ids 0xb6c (0x1cf2c) and 0xb6d (0x1cf48). The return at 0x1ce00 is 1 or 2. The callee behaviour is not rendered, so the role rests on the names.
  Grade: inferred.
  Reviewed: 2026-11-12

- `handle_uncac_buserr` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x1cfac
  Role (from name): handles an error from an uncached access. It calls `get_matching_spool_addr`, then `nasid_to_partid` and `part_id`, and compares their results at 0x1d4d0. `cmn_err_tag` is called at seven sites with ids 0xb6f, 0xb79, 0xb72, 0xb6e, 0xb70, 0xb71 and 0xb73. `partition_handle_error` is called at 0x1d0e8 and 0x1d588 with a2 = 9, and `error_page_discard` and `error_check_part_page` are called in the block from 0x1d528 to 0x1d564. The return is 0, 2 or 3, or the result of `partition_handle_error` or `error_page_discard`. What each callee does is not rendered.
  Grade: inferred.
  Reviewed: 2026-11-12

- `handle_cac_buserr` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x1d8b0
  Role (from name): handles an error from a cached access. It calls `get_matching_spool_addr` first. Behind branches it calls `error_check_memory_access` (0x1da34), `error_check_poisoned_state` (0x1dd88), `memory_iscalias` (0x1e028) and `klerror_check_recoverable` (a0 = 3, 0x1e04c). `partition_handle_error` is called at 0x1da58, 0x1dd68, 0x1ddac and 0x1e194 with a2 = 6, 9, 5 and 2. There are eight `cmn_err_tag` call sites, and `kl_panic` is reached at 0x1d964 on one path. The facts give the call sites, not a single execution order, and what each callee decides rests on its name.
  Grade: inferred.
  Reviewed: 2026-11-12

- `dump_crb` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x1e224 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x1e224-0x1e35c (312 bytes).
  It occupies 312 bytes.
  The `lh` at 0x1e278 loads 2 bytes from (sym(nasid_to_compact_node) + (a0 + a0)) +0x0.
  4 such `ld` accesses load 8 bytes from ?, including `ld` at 0x1e2a8, `ld` at 0x1e304, `ld` at 0x1e310.
  The `jal` at 0x1e338 calls cmn_err with a0=0x4, a1=sym(.rodata)+36904, a2=a0 at entry (arg0), a3=?.
  The `bltz` branch at 0x1e25c targets 0x1e2dc, is taken when a0 < 0 (signed), and falls through when a0 >= 0 (signed).
  The `beq` branch at 0x1e26c targets 0x1e2dc, is taken when a0 >= 0x81 (signed), and falls through when a0 < 0x81 (signed).
  The `beq` branch at 0x1e27c targets 0x1e2dc, is taken when a3(=[(sym(nasid_to_compact_node) + (a0 + a0))]:2) == a4(=-0x1), and falls through when a3(=[(sym(nasid_to_compact_node) + (a0 + a0))]:2) != a4(=-0x1).
  The `beq` branch at 0x1e2c8 targets 0x1e304, is taken when s2(?) == a2(?), and falls through when s2(?) != a2(?).
  The `bne` branch at 0x1e2d4 targets 0x1e2a0, is taken when a6(?) != 0, and falls through when a6(?) == 0.
  The `bne` branch at 0x1e34c targets 0x1e29c, is taken when s1(?) < 0xf (signed), and falls through when s1(?) >= 0xf (signed).
  The `beq` branch at 0x1e354 targets 0x1e2e0 and is always taken.
  The return at 0x1e2fc has v0 = one of ?, ret(cmn_err).

- `kl_ioerror_handler` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x1e35c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x1e35c-0x1e4e0 (388 bytes).
  It occupies 388 bytes.
  The `ld` at 0x1e398 loads 8 bytes from a7 (arg7 at entry) +0x120.
  2 such `ld` accesses load 8 bytes from abs 0xffffffffffffc400, including `ld` at 0x1e40c, `ld` at 0x1e4dc.
  The `ld` at 0x1e410 loads 8 bytes from [-0x3c00]:8 +0x0.
  The `ld` at 0x1e41c loads 8 bytes from ([[-0x3c00]:8]:8 + (a0 << 0x3)) +0x0.
  The `lw` at 0x1e438 loads 4 bytes from [([[-0x3c00]:8]:8 + (a0 << 0x3))]:8 +0x8c80.
  The `jal` at 0x1e434 calls hub_ioerror_handler with a0=[[([[-0x3c00]:8]:8 + (a0 << 0x3))]:8+35968], a1=a3 at entry (arg3), a2=a6 at entry (arg6), a3=sp-128.
  The `jal` at 0x1e46c calls ioerror_dump with a0=sym(.rodata)+36904, a1=a3 at entry (arg3), a2=0x1, a3=sp-128.
  The `beq` branch at 0x1e390 targets 0x1e3ac, is taken when a7 == 0, and falls through when a7 != 0.
  The `beq` branch at 0x1e3ac targets 0x1e490, is taken when a1 == t8(=-0x1), and falls through when a1 != t8(=-0x1).
  The `beq` branch at 0x1e3bc targets 0x1e3d0, is taken when a2 == t8(=-0x1), and falls through when a2 != t8(=-0x1).
  The `beq` branch at 0x1e3e4 targets 0x1e3f8, is taken when v1(?) == 0, and falls through when v1(?) != 0.
  The `beq` branch at 0x1e3f0 targets 0x1e4a8, is taken when (a1(?) & 0x7) == 0, and falls through when (a1(?) & 0x7) != 0.
  The `beq` branch at 0x1e3f8 targets 0x1e40c, is taken when a5 == 0, and falls through when a5 != 0.
  The `beq` branch at 0x1e440 targets 0x1e4a0, is taken when s0(=a6) == 0, and falls through when s0(=a6) != 0.
  The `beq` branch at 0x1e448 targets 0x1e4a0, is taken when s0(=a6) == a0(=0x2), and falls through when s0(=a6) != a0(=0x2).
  The `bne` branch at 0x1e450 targets 0x1e460, is taken when v0(=ret(hub_ioerror_handler)) != 0, and falls through when v0(=ret(hub_ioerror_handler)) == 0.
  The `beq` branch at 0x1e458 targets 0x1e478 and is always taken.
  The `bne` branch at 0x1e490 targets 0x1e3c4, is taken when a2 != t8(=-0x1), and falls through when a2 == t8(=-0x1).
  The `beq` branch at 0x1e498 targets 0x1e3d4 and is always taken.
  The `beq` branch at 0x1e4a0 targets 0x1e478 and is always taken.
  The `bne` branch at 0x1e4d0 targets 0x1e400, is taken when a5 != 0, and falls through when a5 == 0.
  The `beq` branch at 0x1e4d8 targets 0x1e410 and is always taken.
  The return at 0x1e488 has v0 = ret(hub_ioerror_handler).

- `kl_panic_setup` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x1e4e0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x1e4e0-0x1e528 (72 bytes).
  It occupies 72 bytes.
  The `jal` at 0x1e4e8 calls enter_panic_mode with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1e4f0 calls check_ni_errors with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1e508 calls hubni_error_handler with a0=sym(.rodata)+36904, a1=0x1, a2=?, a3=?.
  The `jal` at 0x1e514 calls sn0_error_dump with a0=sym(.rodata)+36904, a1=?, a2=?, a3=?.
  The `beq` branch at 0x1e4f8 targets 0x1e514, is taken when v0(=ret(check_ni_errors)) == 0, and falls through when v0(=ret(check_ni_errors)) != 0.
  The return at 0x1e520 has v0 = ret(sn0_error_dump).

- `kl_panic` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x1e528 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x1e528-0x1e558 (48 bytes).
  It occupies 48 bytes.
  The `jal` at 0x1e534 calls kl_panic_setup with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1e540 calls cmn_err with a0=0x12, a1=a0 at entry (arg0), a2=?, a3=?.
  The return at 0x1e550 has v0 = ret(cmn_err).

- `sn0_error_mark_page` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x1ea80 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x1ea80-0x1ea9c (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x1ea88 calls poison_page with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x1ea94 has v0 = ret(poison_page).

- `sn0_error_reclaim_page` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x1ea9c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x1ea9c-0x1eaf4 (88 bytes).
  It occupies 88 bytes.
  The `jal` at 0x1ead4 calls set_dir_state_UNOWNED with a0=?, a1=?, a2=?, a3=?.
  The `beq` branch at 0x1eaa8 targets 0x1eac8, is taken when a1 == 0, and falls through when a1 != 0.
  The `bne` branch at 0x1eae4 targets 0x1ead4, is taken when s0(?) < 0x4000 (unsigned), and falls through when s0(?) >= 0x4000 (unsigned).
  The `beq` branch at 0x1eaec targets 0x1eab4 and is always taken.
  The return at 0x1eac0 has v0 = one of 0x0, 0x1.

- `intr_stray` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x1eccc (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x1eccc-0x1ecf4 (40 bytes).
  It occupies 40 bytes.
  The `lh` at 0x1ece4 loads 2 bytes from abs 0xffffffffffffc428.
  The `jal` at 0x1ece0 calls cmn_err with a0=0x4, a1=sym(.rodata)+43384, a2=a0 at entry (arg0), a3=[-0x3bd8]:2.
  The return at 0x1ecec has v0 = ret(cmn_err).

- `intr_init_vecblk` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x1ecf4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x1ecf4-0x1eea8 (436 bytes).
  It occupies 436 bytes.
  The `lbu` at 0x1ed80 loads 1 byte from sym(.rodata) +0xa9a4.
  The `lw` at 0x1ed88 loads 4 bytes from sym(.rodata) +0xa9a0.
  4 such `sd` accesses store 8 bytes to ?, including `sd` at 0x1ed98, `sd` at 0x1eda0, `sd` at 0x1eda8.
  5 such `sw` accesses store 4 bytes to ?, including `sw` at 0x1edac, `sw` at 0x1edd4, `sw` at 0x1ede4.
  The `swl` at 0x1edb0 stores 4 bytes to ?.
  The `swr` at 0x1edb4 stores 4 bytes to ?.
  3 such `sb` accesses store 1 byte to ?, including `sb` at 0x1edb8, `sb` at 0x1edc0, `sb` at 0x1edcc.
  The `lbu` at 0x1edbc loads 1 byte from sym(.rodata) +0xa9a5.
  The `lbu` at 0x1edc4 loads 1 byte from sym(.rodata) +0xa9a6.
  The `sh` at 0x1edd8 stores 2 bytes to ?.
  The `sw` at 0x1ee30 stores 4 bytes to table(0x1e18) +0x0.
  The `sw` at 0x1ee4c stores 4 bytes to table(0x1e1c) +0x0.
  The `jal` at 0x1ee00 calls init_spinlock with a0=?, a1=sym(.rodata)+43384, a2=?, a3=?.
  The `beq` branch at 0x1ed64 targets 0x1ee58 and is always taken.
  The `bne` branch at 0x1ede0 targets 0x1ed74, is taken when a3(?) < 0x40 (signed), and falls through when a3(?) >= 0x40 (signed).
  The `beq` branch at 0x1ede8 targets 0x1ee6c, is taken when s3(?) == 0, and falls through when s3(?) != 0.
  The `beq` branch at 0x1ee34 targets 0x1ee50 and is never taken: its condition can never hold for these operands, so execution always falls through.
  The `bne` branch at 0x1ee48 targets 0x1ee20 and is never taken: its condition can never hold for these operands, so execution always falls through.
  The `beq` branch at 0x1ee50 targets 0x1ee78, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `bne` branch at 0x1ee58 targets 0x1ed6c, is taken when s3(?) != 0, and falls through when s3(?) == 0.
  The `beq` branch at 0x1ee64 targets 0x1ed6c and is always taken.
  The `beq` branch at 0x1ee70 targets 0x1edf0 and is always taken.
  The return at 0x1eea0 has v0 = ret(init_spinlock).

- `intr_reserve_level` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x1f0dc (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x1f0dc-0x1f104 (40 bytes).
  It occupies 40 bytes.
  The `jal` at 0x1f0f0 calls do_intr_reserve_level [0x1eea8] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=0x1, a4=a3 at entry (arg3), a5=a4 at entry (arg4).
  The return at 0x1f0fc has v0 = ret(do_intr_reserve_level).

- `intr_unreserve_level` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x1f104 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x1f104-0x1f12c (40 bytes).
  It occupies 40 bytes.
  The `jal` at 0x1f118 calls do_intr_reserve_level [0x1eea8] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0x0, a3=0x0, a4=0x0, a5=0x0.
  The return at 0x1f124 has v0 = ret(do_intr_reserve_level).

- `intr_get_ptrs` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x1f12c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x1f12c-0x1f188 (92 bytes).
  It occupies 92 bytes.
  The `ld` at 0x1f13c loads 8 bytes from (sym(pdaindr) + (a0 << 0x4)) +0x8.
  2 such `sd` accesses store 8 bytes to a3 (arg3 at entry) +0x0, including `sd` at 0x1f150, `sd` at 0x1f16c.
  The `ld` at 0x1f154 loads 8 bytes from [(sym(pdaindr) + (a0 << 0x4))+8]:8 +0x5b0.
  2 such `sd` accesses store 8 bytes to a4 (arg4 at entry) +0x0, including `sd` at 0x1f158, `sd` at 0x1f174.
  2 such `sw` accesses store 4 bytes to a5 (arg5 at entry) +0x0, including `sw` at 0x1f15c, `sw` at 0x1f178.
  2 such `sw` accesses store 4 bytes to a2 (arg2 at entry) +0x0, including `sw` at 0x1f164, `sw` at 0x1f17c.
  The `ld` at 0x1f170 loads 8 bytes from [(sym(pdaindr) + (a0 << 0x4))+8]:8 +0x5b8.
  The `beq` branch at 0x1f148 targets 0x1f168, is taken when a1 >= 0x40 (signed), and falls through when a1 < 0x40 (signed).
  The return at 0x1f160 has v0 = [(sym(pdaindr) + (a0 << 0x4))+8]:8+1440.
  The return at 0x1f180 has v0 = [(sym(pdaindr) + (a0 << 0x4))+8]:8+1440.

- `intr_cpu_choose_from_node` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x1f9cc (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x1f9cc-0x1f9e8 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x1f9d4 calls do_intr_cpu_choose [0x1f86c] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x1f9e0 has v0 = ret(do_intr_cpu_choose).

- `intr_target_from_desc` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x1fae4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x1fae4-0x1fb9c (184 bytes).
  It occupies 184 bytes.
  The `jal` at 0x1faf4 calls device_desc_intr_target_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1fb0c calls cpuvertex_to_cpuid with a0=ret(device_desc_intr_target_get), a1=?, a2=?, a3=?.
  The `jal` at 0x1fb44 calls subnodevertex_to_subnode [0x1f9e8] with a0=ret(device_desc_intr_target_get), a1=sp-48, a2=sp-44, a3=?.
  The `jal` at 0x1fb54 calls master_node_get with a0=ret(device_desc_intr_target_get), a1=?, a2=?, a3=?.
  The `jal` at 0x1fb74 calls intr_cpu_choose_from_node [0x1f9cc] with a0=?, a1=a1 at entry (arg1), a2=?, a3=?, a4=ret(master_node_get).
  The `jal` at 0x1fb88 calls intr_cpu_choose_from_node [0x1f9cc] with a0=?, a1=?, a2=?, a3=?.
  The `beq` branch at 0x1fb04 targets 0x1fb24, is taken when at(=-0x1) == v0(=ret(device_desc_intr_target_get)), and falls through when at(=-0x1) != v0(=ret(device_desc_intr_target_get)).
  The `beq` branch at 0x1fb20 targets 0x1fb3c, is taken when v0(=-0x1) == s0(?), and falls through when v0(=-0x1) != s0(?).
  The `beq` branch at 0x1fb4c targets 0x1fb88, is taken when v0(=ret(subnodevertex_to_subnode)) == 0, and falls through when v0(=ret(subnodevertex_to_subnode)) != 0.
  The `beq` branch at 0x1fb68 targets 0x1fb24, is taken when a0(?) == t8(=-0x1), and falls through when a0(?) != t8(=-0x1).
  The `beq` branch at 0x1fb80 targets 0x1fb24 and is always taken.
  The `beq` branch at 0x1fb94 targets 0x1fb24 and is always taken.
  The return at 0x1fb34 has v0 = ?.

- `intr_cnode_seen` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x1fb9c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x1fb9c-0x1fbdc (64 bytes).
  It occupies 64 bytes.
  The `lw` at 0x1fb9c loads 4 bytes from a2 (arg2 at entry) +0x0.
  The `lh` at 0x1fbb4 loads 2 bytes from ?.
  The `blez` branch at 0x1fba4 targets 0x1fbcc, is taken when a6(=[a2]) <= 0 (signed), and falls through when a6(=[a2]) > 0 (signed).
  The `beq` branch at 0x1fbbc targets 0x1fbd4, is taken when at(?) == a0, and falls through when at(?) != a0.
  The `bne` branch at 0x1fbc4 targets 0x1fbb0, is taken when a5(?) != 0, and falls through when a5(?) == 0.
  The return at 0x1fbcc has v0 = a1.
  The return at 0x1fbd4 has v0 = 0x0.

- `intr_bit_reserve_test` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x1fbdc (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x1fbdc-0x1fc84 (168 bytes).
  It occupies 168 bytes.
  The `sw` at 0x1fc60 stores 4 bytes to a7 (arg7 at entry) +0x0.
  The `jal` at 0x1fc14 calls intr_cpu_choose_from_node [0x1f9cc] with a0=a2 at entry (arg2), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1fc50 calls do_intr_reserve_level [0x1eea8] with a0=?, a1=a3 at entry (arg3), a2=a4 at entry (arg4), a3=0x1, a4=a5 at entry (arg5), a5=a6 at entry (arg6).
  The `beq` branch at 0x1fc0c targets 0x1fc38, is taken when a2 == t9(=-0x1), and falls through when a2 != t9(=-0x1).
  The `beq` branch at 0x1fc38 targets 0x1fc6c, is taken when s0(?) == t9(=-0x1), and falls through when s0(?) != t9(=-0x1).
  The `bltz` branch at 0x1fc5c targets 0x1fc6c, is taken when v0(=ret(do_intr_reserve_level)) < 0 (signed), and falls through when v0(=ret(do_intr_reserve_level)) >= 0 (signed).
  The `beq` branch at 0x1fc64 targets 0x1fc74 and is always taken.
  The return at 0x1fc7c has v0 = one of ?, -0x1.

- `intr_heuristic` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x1fc84 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x1fc84-0x20058 (980 bytes).
  It occupies 980 bytes.
  4 such `ld` accesses load 8 bytes from table(sym(pdaindr)) +0x8, including `ld` at 0x1fd50, `ld` at 0x1fde8, `ld` at 0x1ff40.
  4 such `lbu` accesses load 1 byte from [table(sym(pdaindr))+8]:8 +0x528, including `lbu` at 0x1fd54, `lbu` at 0x1fdec, `lbu` at 0x1ff44.
  The `lh` at 0x1fe24 loads 2 bytes from ret(hwgraph_fastinfo_get) +0x72.
  The `ld` at 0x1fe40 loads 8 bytes from ret(hwgraph_fastinfo_get) +0x830.
  The `lh` at 0x1fe4c loads 2 bytes from [ret(hwgraph_fastinfo_get)+2096]:8 +0x24.
  The `ld` at 0x1fe5c loads 8 bytes from (sym(pdaindr) + ([[ret(hwgraph_fastinfo_get)+2096]:8+36]:2 << 0x4)) +0x8.
  The `lbu` at 0x1fe60 loads 1 byte from [(sym(pdaindr) + ([[ret(hwgraph_fastinfo_get)+2096]:8+36]:2 << 0x4))+8]:8 +0x528.
  4 such `lw` accesses load 4 bytes from a6 (arg6 at entry) +0x0, including `lw` at 0x1fe84, `lw` at 0x1ff5c, `lw` at 0x1ff94.
  The `lh` at 0x1fea0 loads 2 bytes from abs 0xffffffffffffc42a.
  The `sh` at 0x1ff14 stores 2 bytes to ?.
  The `ld` at 0x1ffd8 loads 8 bytes from (sym(pdaindr) + ([sym(master_procid)]:2 << 0x4)) +0x8.
  The `lh` at 0x1ffec loads 2 bytes from [(sym(pdaindr) + ([sym(master_procid)]:2 << 0x4))+8]:8 +0x42a.
  The `jal` at 0x1fcc8 calls physmem_maxradius with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1fce4 calls hwgraph_edge_get with a0=a0 at entry (arg0), a1=sym(.rodata)+43384, a2=sp-380, a3=?.
  The `jal` at 0x1fd00 calls intr_target_from_desc with a0=a1 at entry (arg1), a1=?, a2=?, a3=?.
  The `jal` at 0x1fd24 calls intr_bit_reserve_test [0x1fbdc] with a0=ret(intr_target_from_desc), a1=?, a2=-0x1, a3=a2 at entry (arg2), a4=a3 at entry (arg3), a5=a4 at entry (arg4), a6=a5 at entry (arg5), a7=a6 at entry (arg6).
  The `jal` at 0x1fd9c calls master_node_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x1fdc0 calls intr_bit_reserve_test [0x1fbdc] with a0=-0x1, a1=?, a2=ret(master_node_get), a3=a2 at entry (arg2), a4=a3 at entry (arg3), a5=a4 at entry (arg4), a6=a5 at entry (arg5), a7=a6 at entry (arg6).
  The `jal` at 0x1fe08 calls hwgraph_fastinfo_get with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1fe14 calls hwgraph_vertex_unref with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1fe80 calls intr_unreserve_level with a0=?, a1=[a6], a2=?, a3=?.
  The `jal` at 0x1fe94 calls cmn_err with a0=0x4, a1=sym(.rodata)+43384, a2=a4 at entry (arg4), a3=a4 at entry (arg4).
  The `jal` at 0x1fed4 calls physmem_select_neighbor_node with a0=?, a1=?, a2=sp-120, a3=sym(intr_cnode_seen), a4=sp-376, a5=sp-384.
  The `jal` at 0x1ff18 calls intr_bit_reserve_test [0x1fbdc] with a0=-0x1, a1=?, a2=?, a3=a2 at entry (arg2), a4=a3 at entry (arg3), a5=a4 at entry (arg4), a6=a5 at entry (arg5), a7=a6 at entry (arg6).
  The `jal` at 0x1ff58 calls intr_unreserve_level with a0=?, a1=[a6], a2=?, a3=?.
  The `jal` at 0x1ff84 calls cmn_err with a0=0x4, a1=sym(.rodata)+43384, a2=a4 at entry (arg4), a3=a4 at entry (arg4).
  The `jal` at 0x1ff90 calls intr_unreserve_level with a0=?, a1=[a6], a2=?, a3=?.
  The `jal` at 0x1ffb0 calls cmn_err with a0=0x4, a1=sym(.rodata)+43384, a2=a4 at entry (arg4), a3=a4 at entry (arg4).
  The `jal` at 0x1ffe8 calls intr_bit_reserve_test [0x1fbdc] with a0=-0x1, a1=?, a2=[[(sym(pdaindr) + ([sym(master_procid)]:2 << 0x4))+8]:8+1066]:2, a3=a2 at entry (arg2), a4=a3 at entry (arg3), a5=a4 at entry (arg4), a6=a5 at entry (arg5), a7=a6 at entry (arg6).
  The `jal` at 0x20030 calls intr_unreserve_level with a0=?, a1=[a6], a2=?, a3=?.
  The `jal` at 0x20048 calls cmn_err with a0=0x4, a1=sym(.rodata)+43384, a2=a4 at entry (arg4), a3=a4 at entry (arg4).
  The `beq` branch at 0x1fcec targets 0x1fe08, is taken when v0(=ret(hwgraph_edge_get)) == 0, and falls through when v0(=ret(hwgraph_edge_get)) != 0.
  The `beq` branch at 0x1fcf8 targets 0x1fd98, is taken when s7(=a1) == 0, and falls through when s7(=a1) != 0.
  The `beq` branch at 0x1fd34 targets 0x1fd98, is taken when s7(?) == s3(=-0x1), and falls through when s7(?) != s3(=-0x1).
  The `beq` branch at 0x1fd3c targets 0x1fd68, is taken when s0(?) == s3(=-0x1), and falls through when s0(?) != s3(=-0x1).
  The `bne` branch at 0x1fd60 targets 0x1ff70, is taken when s0(?) != t8(?), and falls through when s0(?) == t8(?).
  The `beq` branch at 0x1fdd0 targets 0x1fe8c, is taken when a0(?) == s3(=-0x1), and falls through when a0(?) != s3(=-0x1).
  The `beq` branch at 0x1fdd8 targets 0x1fe00, is taken when s0(?) == s3(=-0x1), and falls through when s0(?) != s3(=-0x1).
  The `bne` branch at 0x1fdf8 targets 0x1fe80, is taken when s0(?) != a1(?), and falls through when s0(?) == a1(?).
  The `beq` branch at 0x1fe00 targets 0x1fd68 and is always taken.
  The `beq` branch at 0x1fe1c targets 0x1fe70, is taken when s0(=ret(hwgraph_fastinfo_get)) == 0, and falls through when s0(=ret(hwgraph_fastinfo_get)) != 0.
  The `beq` branch at 0x1fe30 targets 0x1fe40, is taken when a1(=[ret(hwgraph_fastinfo_get)+114]:2) == a3(=0x1), and falls through when a1(=[ret(hwgraph_fastinfo_get)+114]:2) != a3(=0x1).
  The `bne` branch at 0x1fe38 targets 0x1fcf8, is taken when a1(=[ret(hwgraph_fastinfo_get)+114]:2) != 0, and falls through when a1(=[ret(hwgraph_fastinfo_get)+114]:2) == 0.
  The `beq` branch at 0x1fe44 targets 0x1fe78, is taken when a1(=[ret(hwgraph_fastinfo_get)+2096]:8) == 0, and falls through when a1(=[ret(hwgraph_fastinfo_get)+2096]:8) != 0.
  The `beq` branch at 0x1fe68 targets 0x1fcf8 and is always taken.
  The `beq` branch at 0x1fe70 targets 0x1fcf8 and is always taken.
  The `beq` branch at 0x1fe78 targets 0x1fcf8 and is always taken.
  The `blez` branch at 0x1fea4 targets 0x1ffa0, is taken when s8(?) <= 0 (signed), and falls through when s8(?) > 0 (signed).
  The `beq` branch at 0x1feac targets 0x1fec0 and is always taken.
  The `bne` branch at 0x1febc targets 0x1ffa0, is taken when t9(?) != 0, and falls through when t9(?) == 0.
  The `beq` branch at 0x1fedc targets 0x1feb4, is taken when v0(=ret(physmem_select_neighbor_node)) == 0, and falls through when v0(=ret(physmem_select_neighbor_node)) != 0.
  The `beq` branch at 0x1ff28 targets 0x1febc, is taken when a0(?) == s3(=-0x1), and falls through when a0(?) != s3(=-0x1).
  The `beq` branch at 0x1ff30 targets 0x1ff68, is taken when s0(?) == s3(=-0x1), and falls through when s0(?) != s3(=-0x1).
  The `beq` branch at 0x1ff50 targets 0x1ff68, is taken when s0(?) == a1(?), and falls through when s0(?) != a1(?).
  The `beq` branch at 0x1ff60 targets 0x1febc and is always taken.
  The `beq` branch at 0x1ff68 targets 0x1fd68 and is always taken.
  The `beq` branch at 0x1ff98 targets 0x1fd98 and is always taken.
  The `beq` branch at 0x1fff8 targets 0x20038, is taken when a0(?) == s3(=-0x1), and falls through when a0(?) != s3(=-0x1).
  The `beq` branch at 0x20000 targets 0x20028, is taken when s0(?) == s3(=-0x1), and falls through when s0(?) != s3(=-0x1).
  The `bne` branch at 0x20020 targets 0x20030, is taken when s0(?) != a1(?), and falls through when s0(?) == a1(?).
  The `beq` branch at 0x20028 targets 0x1fd68 and is always taken.
  The `beq` branch at 0x20050 targets 0x1fd68 and is always taken.
  The return at 0x1fd90 has v0 = one of ?, -0x1.

- `intpend0` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x200f0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x200f0-0x20250 (352 bytes).
  It occupies 352 bytes.
  2 such `ld` accesses load 8 bytes from abs 0xffffffffffffc5a0, including `ld` at 0x2010c, `ld` at 0x201f0.
  3 such `ld` accesses load 8 bytes from abs 0x9200000001000098, including `ld` at 0x20110, `ld` at 0x20198, `ld` at 0x201ec.
  3 such `ld` accesses load 8 bytes from abs 0xffffffffffffc510, including `ld` at 0x2013c, `ld` at 0x20158, `ld` at 0x20218.
  2 such `lw` accesses load 4 bytes from [-0x3af0]:8 +0xd0, including `lw` at 0x2015c, `lw` at 0x20220.
  2 such `sw` accesses store 4 bytes to [-0x3af0]:8 +0xd0, including `sw` at 0x20164, `sw` at 0x20234.
  The `sd` at 0x20170 stores 8 bytes to abs 0x9200000001000090.
  3 such `ld` accesses load 8 bytes from abs 0xffffffffffffc5b0, including `ld` at 0x20178, `ld` at 0x201b4, `ld` at 0x201c8.
  The `lw` at 0x20188 loads 4 bytes from ([-0x3a50]:8 + (((ret(ms1bit) << 0x3) + ret(ms1bit)) << 0x3)) +0x18.
  The `ld` at 0x2019c loads 8 bytes from ([-0x3a50]:8 + (((ret(ms1bit) << 0x3) + ret(ms1bit)) << 0x3)) +0x8.
  2 such `ld` accesses load 8 bytes from ([-0x3a50]:8 + (((ret(ms1bit) << 0x3) + ret(ms1bit)) << 0x3)) +0x10, including `ld` at 0x201a8, `ld` at 0x20244.
  The `ld` at 0x20238 loads 8 bytes from ([-0x3a50]:8 + (((ret(ms1bit) << 0x3) + ret(ms1bit)) << 0x3)) +0x0.
  The `jal` at 0x20140 calls cvsema with a0=([-0x3a50]:8 + (((ret(ms1bit) << 0x3) + ret(ms1bit)) << 0x3))+32, a1=?, a2=?, a3=?.
  The `jal` at 0x20168 calls ms1bit with a0=?, a1=[-0x3af0]:8, a2=?, a3=?.
  The `jalr` at 0x201ac calls (unknown callee) with a0=[([-0x3a50]:8 + (((ret(ms1bit) << 0x3) + ret(ms1bit)) << 0x3))+16]:8, a1=a0 at entry (arg0), a2=?, a3=?, a4=([-0x3a50]:8 + (((ret(ms1bit) << 0x3) + ret(ms1bit)) << 0x3)).
  The `jal` at 0x201bc calls valusema with a0=([-0x3a50]:8 + (((ret(ms1bit) << 0x3) + ret(ms1bit)) << 0x3))+32, a1=?, a2=?, a3=?, a4=([-0x3a50]:8 + (((ret(ms1bit) << 0x3) + ret(ms1bit)) << 0x3)).
  The `jal` at 0x201dc calls vsema with a0=([-0x3a50]:8 + (((ret(ms1bit) << 0x3) + ret(ms1bit)) << 0x3))+32, a1=?, a2=?, a3=?.
  The `jalr` at 0x20240 calls (unknown callee) with a0=[([-0x3a50]:8 + (((ret(ms1bit) << 0x3) + ret(ms1bit)) << 0x3))+16]:8, a1=a0 at entry (arg0), a2=?, a3=?, a4=([-0x3a50]:8 + (((ret(ms1bit) << 0x3) + ret(ms1bit)) << 0x3)), a5=[([-0x3a50]:8 + (((ret(ms1bit) << 0x3) + ret(ms1bit)) << 0x3))]:8.
  The `beq` branch at 0x20130 targets 0x20200, is taken when (at(=[-0x3a60]:8) & v0(=[0x9200000001000098]:8)) == 0, and falls through when (at(=[-0x3a60]:8) & v0(=[0x9200000001000098]:8)) != 0.
  The `beq` branch at 0x20138 targets 0x2015c and is always taken.
  The `beq` branch at 0x20150 targets 0x201ec, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `beq` branch at 0x20194 targets 0x20238, is taken when (a2(=[([-0x3a50]:8 + (((ret(ms1bit) << 0x3) + ret(ms1bit)) << 0x3))+24]) & 0x1000) == 0, and falls through when (a2(=[([-0x3a50]:8 + (((ret(ms1bit) << 0x3) + ret(ms1bit)) << 0x3))+24]) & 0x1000) != 0.
  The `beq` branch at 0x201a0 targets 0x201bc, is taken when v0(=[([-0x3a50]:8 + (((ret(ms1bit) << 0x3) + ret(ms1bit)) << 0x3))+8]:8) == 0, and falls through when v0(=[([-0x3a50]:8 + (((ret(ms1bit) << 0x3) + ret(ms1bit)) << 0x3))+8]:8) != 0.
  The `beq` branch at 0x201d4 targets 0x20140, is taken when v0(=ret(valusema)) >= a1(=[sym(hub_intr_wakeup_cnt)]) (signed), and falls through when v0(=ret(valusema)) < a1(=[sym(hub_intr_wakeup_cnt)]) (signed).
  The `beq` branch at 0x201e4 targets 0x2014c and is always taken.
  The `bne` branch at 0x201f8 targets 0x20158, is taken when (a2(=[-0x3a60]:8) & a3(=[0x9200000001000098]:8)) != 0, and falls through when (a2(=[-0x3a60]:8) & a3(=[0x9200000001000098]:8)) == 0.
  The `beq` branch at 0x20248 targets 0x2014c and is always taken.
  The return at 0x20230 has v0 = one of [0x9200000001000098]:8, ?.

- `intpend1` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x20250 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x20250-0x2033c (236 bytes).
  It occupies 236 bytes.
  The `ld` at 0x20268 loads 8 bytes from abs 0xffffffffffffc5a8.
  The `ld` at 0x2026c loads 8 bytes from abs 0x92000000010000a0.
  2 such `ld` accesses load 8 bytes from abs 0xffffffffffffc510, including `ld` at 0x2028c, `ld` at 0x20300.
  2 such `lw` accesses load 4 bytes from [-0x3af0]:8 +0xd0, including `lw` at 0x20290, `lw` at 0x20308.
  2 such `sw` accesses store 4 bytes to [-0x3af0]:8 +0xd0, including `sw` at 0x20298, `sw` at 0x2031c.
  The `sd` at 0x202a8 stores 8 bytes to abs 0x9200000001000090.
  The `ld` at 0x202b0 loads 8 bytes from abs 0xffffffffffffc5b8.
  The `ld` at 0x202c0 loads 8 bytes from ([-0x3a48]:8 + (((ret(ms1bit) << 0x3) + ret(ms1bit)) << 0x3)) +0x0.
  The `ld` at 0x202cc loads 8 bytes from abs 0x9200000001000098.
  The `ld` at 0x202d0 loads 8 bytes from ([-0x3a48]:8 + (((ret(ms1bit) << 0x3) + ret(ms1bit)) << 0x3)) +0x10.
  The `jal` at 0x2029c calls ms1bit with a0=?, a1=?, a2=?, a3=?.
  The `jalr` at 0x202d4 calls (unknown callee) with a0=[([-0x3a48]:8 + (((ret(ms1bit) << 0x3) + ret(ms1bit)) << 0x3))+16]:8, a1=a0 at entry (arg0), a2=?, a3=?, a5=([-0x3a48]:8 + (((ret(ms1bit) << 0x3) + ret(ms1bit)) << 0x3)), a6=[([-0x3a48]:8 + (((ret(ms1bit) << 0x3) + ret(ms1bit)) << 0x3))]:8, a7=ret(ms1bit)+64.
  The `jal` at 0x2032c calls cmn_err with a0=0x0, a1=sym(.rodata)+43384, a2=ret(ms1bit), a3=?, a5=([-0x3a48]:8 + (((ret(ms1bit) << 0x3) + ret(ms1bit)) << 0x3)), a6=[([-0x3a48]:8 + (((ret(ms1bit) << 0x3) + ret(ms1bit)) << 0x3))]:8, a7=ret(ms1bit)+64.
  The `beq` branch at 0x20284 targets 0x202f0, is taken when (s2(=[-0x3a58]:8) & t8(=[0x92000000010000a0]:8)) == 0, and falls through when (s2(=[-0x3a58]:8) & t8(=[0x92000000010000a0]:8)) != 0.
  The `beq` branch at 0x202c8 targets 0x20320, is taken when a6(=[([-0x3a48]:8 + (((ret(ms1bit) << 0x3) + ret(ms1bit)) << 0x3))]:8) == 0, and falls through when a6(=[([-0x3a48]:8 + (((ret(ms1bit) << 0x3) + ret(ms1bit)) << 0x3))]:8) != 0.
  The `bne` branch at 0x202e8 targets 0x2028c, is taken when s2(?) != 0, and falls through when s2(?) == 0.
  The `beq` branch at 0x20334 targets 0x202e0 and is always taken.
  The return at 0x20318 has v0 = ?.

- `sendintr` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x206a4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x206a4-0x20710 (108 bytes).
  It occupies 108 bytes.
  The `ld` at 0x206b0 loads 8 bytes from (sym(pdaindr) + (a0 << 0x4)) +0x8.
  The `lbu` at 0x206c0 loads 1 byte from [(sym(pdaindr) + (a0 << 0x4))+8]:8 +0x528.
  The `lh` at 0x206d8 loads 2 bytes from [(sym(pdaindr) + (a0 << 0x4))+8]:8 +0x42c.
  The `sd` at 0x20700 stores 8 bytes to (([[(sym(pdaindr) + (a0 << 0x4))+8]:8+1068]:2 << 0x21) + one of 0x9200000001800090, 0x9200000001a00090) +0x0.
  The `beq` branch at 0x206dc targets 0x20704, is taken when a1 == at(=0xab), and falls through when a1 != at(=0xab).
  The `beq` branch at 0x20708 targets 0x206e8 and is always taken.
  The return at 0x206fc has v0 = 0x0.

- `cpuintr` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x20710 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x20710-0x20820 (272 bytes).
  It occupies 272 bytes.
  2 such `ld` accesses load 8 bytes from abs 0xffffffffffffc280, including `ld` at 0x20710, `ld` at 0x207c8.
  2 such `lh` accesses load 2 bytes from abs 0xffffffffffffc428, including `lh` at 0x2072c, `lh` at 0x20770.
  2 such `ld` accesses load 8 bytes from (sym(pdaindr) + ([-0x3bd8]:2 << 0x4)) +0x8, including `ld` at 0x2073c, `ld` at 0x2077c.
  2 such `lbu` accesses load 1 byte from [(sym(pdaindr) + ([-0x3bd8]:2 << 0x4))+8]:8 +0x528, including `lbu` at 0x20740, `lbu` at 0x20798.
  The `sd` at 0x20754 stores 8 bytes to abs 0x9200000001000090.
  The `lbu` at 0x20758 loads 1 byte from abs 0xffffffffffffc080.
  The `ld` at 0x2075c loads 8 bytes from abs 0x9200000001000098.
  The `lh` at 0x20784 loads 2 bytes from [(sym(pdaindr) + ([-0x3bd8]:2 << 0x4))+8]:8 +0x42c.
  The `jal` at 0x207b0 calls bcopy with a0=a1 at entry (arg1), a1=?, a2=0x168, a3=?, a4=0x9600000000000000, a5=0xffffffffff.
  The `jal` at 0x207b8 calls doacvec with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x207c0 calls doactions with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x207f0 calls log_tstamp_event with a0=0x71, a1=0x0, a2=0x0, a3=0x0, a4=0x0.
  The `jal` at 0x20810 calls log_tstamp_event with a0=0x65, a1=0x71, a2=0x0, a3=0x0, a4=0x0.
  The `bne` branch at 0x20724 targets 0x207e0, is taken when (at(=[-0x3d80]:8) & 0x20) != 0, and falls through when (at(=[-0x3d80]:8) & 0x20) == 0.
  The `beq` branch at 0x20760 targets 0x207b8, is taken when v0(=[-0x3f80]:1) == 0, and falls through when v0(=[-0x3f80]:1) != 0.
  The `beq` branch at 0x20768 targets 0x207b8, is taken when a3(=[sym(nmied)]) == 0, and falls through when a3(=[sym(nmied)]) != 0.
  The `bne` branch at 0x207d0 targets 0x20800, is taken when (a2(=[-0x3d80]:8) & 0x20) != 0, and falls through when (a2(=[-0x3d80]:8) & 0x20) == 0.
  The `beq` branch at 0x207f8 targets 0x2072c and is always taken.
  The `beq` branch at 0x20818 targets 0x207d8 and is always taken.
  The return at 0x207d8 has v0 = one of ret(doactions), ret(log_tstamp_event).

- `dbgintr` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x20884 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x20884-0x208d4 (80 bytes).
  It occupies 80 bytes.
  The `lh` at 0x20884 loads 2 bytes from abs 0xffffffffffffc428.
  The `ld` at 0x2089c loads 8 bytes from (sym(pdaindr) + ([-0x3bd8]:2 << 0x4)) +0x8.
  The `lbu` at 0x208a4 loads 1 byte from [(sym(pdaindr) + ([-0x3bd8]:2 << 0x4))+8]:8 +0x528.
  The `sd` at 0x208b8 stores 8 bytes to abs 0x9200000001000090.
  The `ld` at 0x208c4 loads 8 bytes from abs 0x9200000001000098.
  The `jal` at 0x208c0 calls debug with a0=sym(.rodata)+43384, a1=?, a2=0x9200000001000090, a3=a3 at entry (arg3).
  The return at 0x208cc has v0 = ret(debug).

- `tlbintr` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x20988 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x20988-0x209d0 (72 bytes).
  It occupies 72 bytes.
  The `lh` at 0x20988 loads 2 bytes from abs 0xffffffffffffc428.
  The `ld` at 0x2099c loads 8 bytes from (sym(pdaindr) + ([-0x3bd8]:2 << 0x4)) +0x8.
  The `lbu` at 0x209a4 loads 1 byte from [(sym(pdaindr) + ([-0x3bd8]:2 << 0x4))+8]:8 +0x528.
  The `sd` at 0x209b8 stores 8 bytes to abs 0x9200000001000090.
  The `ld` at 0x209c0 loads 8 bytes from abs 0x9200000001000098.
  The `jal` at 0x209bc calls tlbflush_rand with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x209c8 has v0 = ret(tlbflush_rand).

- `chkdebug` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x20bb4
  It reads the halfword at -0x3bd8, uses it to index the per-processor table, and reads the byte at +0x528 of that entry. It loads the doubleword at 0x92000000010000a0 and ANDs it with an unresolved value at 0x20bec. When the result is nonzero it calls `dbgintr` (at 0x20884) with a0 = 0 and the caller's a1 to a3, and the return is that call's result or an unresolved value. The debug-enable reading comes from the name and the mask test, which the facts do not confirm.
  Grade: inferred.
  Reviewed: 2026-11-12

- `debug_stop_all_cpus` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x20c74
  It loops over CPU numbers below `maxcpus`, calling `get_cpu_slice` at 0x20ca4 and `cpu_enabled` at 0x20d14, and it skips the caller by comparing the halfword at -0x3bd8 with the loop counter at 0x20d08. The store at 0x20cec goes to an address the facts leave unresolved. The stop mechanism is not in the facts, so the role rests on the name.
  Grade: inferred.
  Reviewed: 2026-11-12

- `intr_reserve_hardwired` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x20d84 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x20d84-0x20ee0 (348 bytes).
  It occupies 348 bytes.
  2 such `sb` accesses store 1 byte to ?, including `sb` at 0x20dd0, `sb` at 0x20e8c.
  The `lw` at 0x20de4 loads 4 bytes from ?.
  The `ld` at 0x20df0 loads 8 bytes from ?.
  The `lb` at 0x20e0c loads 1 byte from ?.
  The `ld` at 0x20e50 loads 8 bytes from table(sym(pdaindr)) +0x8.
  The `lh` at 0x20e54 loads 2 bytes from [table(sym(pdaindr))+8]:8 +0x42a.
  The `lbu` at 0x20e60 loads 1 byte from [table(sym(pdaindr))+8]:8 +0x528.
  The `lbu` at 0x20e70 loads 1 byte from ?.
  The `lb` at 0x20e80 loads 1 byte from sym(.data) +0x1e98.
  The `jal` at 0x20d98 calls cnodetocpu with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x20dec calls intr_reserve_level with a0=?, a1=?, a2=?, a3=0x0.
  The `jal` at 0x20e38 calls cpu_enabled with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x20ec8 calls cmn_err with a0=0x0, a1=sym(.rodata)+43384, a2=?, a3=?.
  The `beq` branch at 0x20db8 targets 0x20ea0, is taken when at(=-0x1) == s0(?), and falls through when at(=-0x1) != s0(?).
  The `bne` branch at 0x20dcc targets 0x20dc0, is taken when a0(?) < 0x2 (signed), and falls through when a0(?) >= 0x2 (signed).
  The `beq` branch at 0x20dd4 targets 0x20ed8 and is always taken.
  The `bne` branch at 0x20df4 targets 0x20ec0, is taken when v0(=ret(intr_reserve_level)) != s2(?), and falls through when v0(=ret(intr_reserve_level)) == s2(?).
  The `bne` branch at 0x20e14 targets 0x20ddc, is taken when a1(?) != a7(=-0x1), and falls through when a1(?) == a7(=-0x1).
  The `beq` branch at 0x20e30 targets 0x20ea0, is taken when t8(?) == 0, and falls through when t8(?) != 0.
  The `beq` branch at 0x20e40 targets 0x20ea0, is taken when v0(=ret(cpu_enabled)) == 0, and falls through when v0(=ret(cpu_enabled)) != 0.
  The `bne` branch at 0x20e58 targets 0x20ea0, is taken when t9(=[[table(sym(pdaindr))+8]:8+1066]:2) != s3(=a0), and falls through when t9(=[[table(sym(pdaindr))+8]:8+1066]:2) == s3(=a0).
  The `bne` branch at 0x20e74 targets 0x20e1c, is taken when a2(?) != 0, and falls through when a2(?) == 0.
  The `bne` branch at 0x20e90 targets 0x20ddc, is taken when a1(=[sym(hardwired_intr)]:1) != a5(=-0x1), and falls through when a1(=[sym(hardwired_intr)]:1) == a5(=-0x1).
  The `beq` branch at 0x20e98 targets 0x20e20 and is always taken.
  The `beq` branch at 0x20ed0 targets 0x20e00 and is always taken.
  The `beq` branch at 0x20ed8 targets 0x20e30 and is always taken.
  The return at 0x20eb8 has v0 = one of ret(cnodetocpu), ?, ret(cpu_enabled).

- `intr_clear_bits` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x20ee0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x20ee0-0x20f58 (120 bytes).
  It occupies 120 bytes.
  The `ld` at 0x20ee0 loads 8 bytes from a1 (arg1 at entry) +0x0.
  2 such `sd` accesses store 8 bytes to abs 0x9200000001000090, including `sd` at 0x20f1c, `sd` at 0x20f40.
  2 such `ld` accesses load 8 bytes from abs 0x9200000001000098, including `ld` at 0x20f20, `ld` at 0x20f44.
  The `beq` branch at 0x20ef8 targets 0x20f50, is taken when at(=[a1]:8) == 0, and falls through when at(=[a1]:8) != 0.
  The `beq` branch at 0x20f14 targets 0x20f24, is taken when (v0(=[a1]:8) & v1(?)) == 0, and falls through when (v0(=[a1]:8) & v1(?)) != 0.
  The `beq` branch at 0x20f24 targets 0x20f50, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `beq` branch at 0x20f38 targets 0x20f48, is taken when (a5(=[a1]:8) & a7(?)) == 0, and falls through when (a5(=[a1]:8) & a7(?)) != 0.
  The `bne` branch at 0x20f48 targets 0x20f00, is taken when a5(?) != 0, and falls through when a5(?) == 0.
  The return at 0x20f50 has v0 = ?.

- `intr_clear_all` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x20f58 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x20f58-0x21094 (316 bytes).
  It occupies 316 bytes.
  The `sd` at 0x2100c stores 8 bytes to ((a0 << 0x21) + one of 0x92000000018000a8, 0x9200000001a000a8) +0x0.
  The `sd` at 0x21018 stores 8 bytes to ((a0 << 0x21) + one of 0x92000000018000b8, 0x9200000001a000b8) +0x0.
  The `sd` at 0x21024 stores 8 bytes to ((a0 << 0x21) + one of 0x92000000018000b0, 0x9200000001a000b0) +0x0.
  The `sd` at 0x21030 stores 8 bytes to ((a0 << 0x21) + one of 0x92000000018000c0, 0x9200000001a000c0) +0x0.
  The `jal` at 0x2102c calls intr_clear_bits [0x20ee0] with a0=a0 at entry (arg0), a1=((a0 << 0x21) + one of 0x9200000001800098, 0x9200000001a00098), a2=0x0, a3=sym(.rodata)+43384, a4=((a0 << 0x21) + one of 0x92000000018000b0, 0x9200000001a000b0), a5=((a0 << 0x21) + one of 0x92000000018000b8, 0x9200000001a000b8).
  The `jal` at 0x2104c calls intr_clear_bits [0x20ee0] with a0=a0 at entry (arg0), a1=((a0 << 0x21) + one of 0x92000000018000a0, 0x9200000001a000a0), a2=0x40, a3=sym(.rodata)+43384.
  The `bne` branch at 0x2105c targets 0x20fac, is taken when s0(?) < 0x2 (signed), and falls through when s0(?) >= 0x2 (signed).
  The return at 0x2108c has v0 = ret(intr_clear_bits).

- `intr_thread_setup` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x2179c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x2179c-0x217f8 (92 bytes).
  It occupies 92 bytes.
  The `jal` at 0x217c8 calls sprintf with a0=sp-64, a1=sym(.rodata)+43384, a2=a1 at entry (arg1), a3=a2 at entry (arg2).
  The `jal` at 0x217e0 calls xthread_setup with a0=sp-64, a1=a3 at entry (arg3), a2=a0+24, a3=sym(intpend0_intrd_start), a4=a0 at entry (arg0).
  The return at 0x217f0 has v0 = ret(xthread_setup).

- `hubio_init` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x21f18 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x21f18-0x21f34 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x21f20 calls early_brl1_port_init with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x21f2c has v0 = ret(early_brl1_port_init).

- `hub_pio_init` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x21f34 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x21f34-0x22094 (352 bytes).
  It occupies 352 bytes.
  The `lh` at 0x21f6c loads 2 bytes from ?.
  4 such `sw` accesses store 4 bytes to ?, including `sw` at 0x21f94, `sw` at 0x21f9c, `sw` at 0x2200c.
  4 such `sd` accesses store 8 bytes to ?, including `sd` at 0x21fa8, `sd` at 0x21fc8, `sd` at 0x21fd0.
  The `sb` at 0x21fdc stores 1 byte to ?.
  The `sh` at 0x22018 stores 2 bytes to ?.
  The `sd` at 0x2202c stores 8 bytes to table(0x9200000001c00160) +0x0.
  The `jal` at 0x21f4c calls hwgraph_info_get_LBL with a0=a0 at entry (arg0), a1=sym(.rodata)+45112, a2=sp-32, a3=a3 at entry (arg3).
  The `jal` at 0x22034 calls hub_set_piomode with a0=?, a1=0x1, a2=?, a3=?, a5=table(0x9200000001c00000).
  The `jal` at 0x22054 calls init_sv with a0=?, a1=0x0, a2=sym(.rodata)+45112, a3=-0x1.
  The `jal` at 0x22068 calls spinlock_init with a0=?, a1=sym(.rodata)+45112, a2=?, a3=?.
  The `beq` branch at 0x21f88 targets 0x2207c and is always taken.
  The `beq` branch at 0x21fb4 targets 0x21fe8, is taken when a2(?) >= 0x10 (signed), and falls through when a2(?) < 0x10 (signed).
  The `bne` branch at 0x21fd8 targets 0x21f90, is taken when a2(?) != 0, and falls through when a2(?) == 0.
  The `beq` branch at 0x21fe0 targets 0x21f94 and is always taken.
  The `bne` branch at 0x22028 targets 0x21ff0, is taken when a3(?) < 0x6 (signed), and falls through when a3(?) >= 0x6 (signed).
  The `beq` branch at 0x2208c targets 0x21fc0 and is always taken.
  The return at 0x22074 has v0 = ret(spinlock_init).

- `hub_piomap_free` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x223ac (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x223ac-0x22498 (236 bytes).
  It occupies 236 bytes.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x28, including `lw` at 0x223ac, `lw` at 0x22448.
  The `lw` at 0x223d4 loads 4 bytes from a0 (arg0 at entry) +0x20.
  The `lh` at 0x223e0 loads 2 bytes from ?.
  The `lh` at 0x223ec loads 2 bytes from a0 (arg0 at entry) +0x24.
  The `sh` at 0x22400 stores 2 bytes to a0 (arg0 at entry) +0x24.
  The `lbu` at 0x22428 loads 1 byte from a0 (arg0 at entry) +0x26.
  The `sd` at 0x22444 stores 8 bytes to table(0x9200000001c00160) +0x0.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x28, including `sw` at 0x22460, `sw` at 0x22494.
  The `lw` at 0x22468 loads 4 bytes from ?.
  The `sw` at 0x22470 stores 4 bytes to ?.
  The `jal` at 0x223d0 calls hwgraph_info_get_LBL with a0=[a0+32], a1=sym(.rodata)+45112, a2=sp-48, a3=a3 at entry (arg3).
  The `jal` at 0x223e4 calls mutex_spinlock with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x2240c calls mutex_spinunlock with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x22478 calls sv_signal with a0=?, a1=?, a2=table(0x9200000001c00000), a3=?.
  The `beq` branch at 0x223c0 targets 0x22414, is taken when (at(=[a0+40]) & 0x2) == 0, and falls through when (at(=[a0+40]) & 0x2) != 0.
  The `beq` branch at 0x223fc targets 0x22424, is taken when v1(?) == 0, and falls through when v1(?) != 0.
  The `beq` branch at 0x22458 targets 0x22488, is taken when (a4(=[a0+40]) & 0x4) == 0, and falls through when (a4(=[a0+40]) & 0x4) != 0.
  The `beq` branch at 0x22480 targets 0x22404 and is always taken.
  The `beq` branch at 0x22490 targets 0x22474 and is always taken.
  The return at 0x2241c has v0 = one of ?, ret(mutex_spinunlock).

- `hub_dma_init` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x225c4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x225c4-0x225cc (8 bytes).
  It occupies 8 bytes.
  The return at 0x225c4 has v0 = ?.

- `hub_intr_init` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x227a4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x227a4-0x227ac (8 bytes).
  It occupies 8 bytes.
  The return at 0x227a4 has v0 = ?.

- `hub_device_desc_update` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x227ac (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x227ac-0x22800 (84 bytes).
  It occupies 84 bytes.
  The `jal` at 0x227bc calls device_desc_intr_swlevel_set with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x227d0 calls sprintf with a0=sp-64, a1=sym(.rodata)+45112, a2=a2 at entry (arg2), a3=?.
  The `jal` at 0x227dc calls hwgraph_path_to_dev with a0=sp-64, a1=?, a2=?, a3=?.
  The `jal` at 0x227e8 calls device_desc_intr_target_set with a0=a0 at entry (arg0), a1=ret(hwgraph_path_to_dev), a2=?, a3=?.
  The return at 0x227f8 has v0 = ret(device_desc_intr_target_set).

- `hub_setup_prb` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x22d5c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x22d5c-0x22df0 (148 bytes).
  It occupies 148 bytes.
  The `ld` at 0x22dac loads 8 bytes from table(0x9200000001c00198) +0x0.
  The `sd` at 0x22dec stores 8 bytes to table(0x9200000001c00198) +0x0.
  The `beq` branch at 0x22d64 targets 0x22d88, is taken when at(=[sym(force_fire_and_forget)]) == 0, and falls through when at(=[sym(force_fire_and_forget)]) != 0.
  The `beq` branch at 0x22d88 targets 0x22d94, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The return at 0x22de8 has v0 = ?.

- `hub_set_piomode` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x22df0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x22df0-0x22ee0 (240 bytes).
  It occupies 240 bytes.
  2 such `ld` accesses load 8 bytes from (a0 << 0x21) -0x6dfffffffe3ffef0, including `ld` at 0x22e2c, `ld` at 0x22e88.
  2 such `sd` accesses store 8 bytes to (a0 << 0x21) -0x6dfffffffe3ffef0, including `sd` at 0x22e30, `sd` at 0x22e80.
  The `ld` at 0x22e34 loads 8 bytes from (a0 << 0x21) -0x6dfffffffe3fffe0.
  The `jal` at 0x22e04 calls get_console_nasid with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x22e50 calls hub_setup_prb with a0=a0 at entry (arg0), a1=0x0, a2=0x1, a3=a1 at entry (arg1).
  The `jal` at 0x22e68 calls hub_setup_prb with a0=a0 at entry (arg0), a1=?, a2=0x3, a3=a1 at entry (arg1).
  The `jal` at 0x22e8c calls putbuf_unlock with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x22eb4 calls putbuf_lock with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x22ed0 calls hub_setup_prb with a0=a0 at entry (arg0), a1=0x0, a2=0x3, a3=a1 at entry (arg1).
  The `beq` branch at 0x22e18 targets 0x22eb4, is taken when s1(=a0) == v0(=ret(get_console_nasid)), and falls through when s1(=a0) != v0(=ret(get_console_nasid)).
  The `bltz` branch at 0x22e3c targets 0x22ec4, is taken when at(=([(a0 << 0x21)-7926335344142712800]:8 << 0x2e)) < 0 (signed), and falls through when at(=([(a0 << 0x21)-7926335344142712800]:8 << 0x2e)) >= 0 (signed).
  The `bne` branch at 0x22e78 targets 0x22e5c, is taken when s0(?) < 0x10 (signed), and falls through when s0(?) >= 0x10 (signed).
  The `beq` branch at 0x22e84 targets 0x22e94, is taken when s3(=one of 0x0, 0x1) == 0, and falls through when s3(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x22ebc targets 0x22e20 and is always taken.
  The `beq` branch at 0x22ed8 targets 0x22e5c and is always taken.
  The return at 0x22eac has v0 = one of [(a0 << 0x21)-7926335344142712560]:8, ret(putbuf_unlock).

- `hub_widget_flags_set` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x22ee0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x22ee0-0x22f28 (72 bytes).
  It occupies 72 bytes.
  The `jal` at 0x22ef8 calls hub_setup_prb with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0x3, a3=0x1.
  The `jal` at 0x22f10 calls hub_setup_prb with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0x3, a3=0x2.
  The `beq` branch at 0x22eec targets 0x22f08, is taken when (a2 & 0x1) == 0, and falls through when (a2 & 0x1) != 0.
  The `beq` branch at 0x22f00 targets 0x22f1c and is always taken.
  The `beq` branch at 0x22f08 targets 0x22f18, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The return at 0x22f20 has v0 = 0x1.

- `hubii_ixtt_set` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x22fbc (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x22fbc-0x23038 (124 bytes).
  It occupies 124 bytes.
  The `lh` at 0x22ffc loads 2 bytes from ?.
  The `ld` at 0x23008 loads 8 bytes from a1 (arg1 at entry) +0x0.
  The `sd` at 0x23010 stores 8 bytes to ?.
  The `jal` at 0x22fc8 calls xwidget_info_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x22fd0 calls xwidget_info_master_get with a0=ret(xwidget_info_get), a1=?, a2=?, a3=?.
  The `jal` at 0x22fe4 calls hwgraph_info_get_LBL with a0=ret(xwidget_info_master_get), a1=sym(.rodata)+45112, a2=sp-32, a3=?.
  The `jal` at 0x22ff0 calls mutex_spinlock with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x2301c calls mutex_spinunlock with a0=?, a1=ret(mutex_spinlock), a2=[a1]:8, a3=?, a4=0x6dfffffffe400000.
  The return at 0x23030 has v0 = 0x0.

- `hubii_ixtt_get` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x23038 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x23038-0x230b4 (124 bytes).
  It occupies 124 bytes.
  The `lh` at 0x23078 loads 2 bytes from ?.
  The `ld` at 0x23088 loads 8 bytes from ?.
  The `sd` at 0x2308c stores 8 bytes to a1 (arg1 at entry) +0x0.
  The `jal` at 0x23044 calls xwidget_info_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x2304c calls xwidget_info_master_get with a0=ret(xwidget_info_get), a1=?, a2=?, a3=?.
  The `jal` at 0x23060 calls hwgraph_info_get_LBL with a0=ret(xwidget_info_master_get), a1=sym(.rodata)+45112, a2=sp-32, a3=?.
  The `jal` at 0x2306c calls mutex_spinlock with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x23098 calls mutex_spinunlock with a0=?, a1=ret(mutex_spinlock), a2=?, a3=0x6dfffffffe400000.
  The return at 0x230ac has v0 = 0x0.

- `nmi_cpu_eframe_save` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x26708 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x26708-0x26798 (144 bytes).
  It occupies 144 bytes.
  The `lw` at 0x2675c loads 4 bytes from ?.
  The `ld` at 0x26774 loads 8 bytes from ?.
  The `sd` at 0x26778 stores 8 bytes to ?.
  The `beq` branch at 0x26768 targets 0x2677c, is taken when a3(?) == a7(=-0x1), and falls through when a3(?) != a7(=-0x1).
  The `bne` branch at 0x26788 targets 0x2675c, is taken when a4(?) < 0x27 (signed), and falls through when a4(?) >= 0x27 (signed).
  The return at 0x26790 has v0 = ?.

- `nmi_node_eframe_save` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x26798 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x26798-0x26848 (176 bytes).
  It occupies 176 bytes.
  The `lh` at 0x267cc loads 2 bytes from (sym(compact_to_nasid_node) + (a0 + a0)) +0x0.
  2 such `ld` accesses load 8 bytes from abs 0xffffffffffffc400, including `ld` at 0x267d8, `ld` at 0x26804.
  2 such `ld` accesses load 8 bytes from [-0x3c00]:8 +0x0, including `ld` at 0x267dc, `ld` at 0x26808.
  2 such `ld` accesses load 8 bytes from ([[-0x3c00]:8]:8 + (a0 << 0x3)) +0x0, including `ld` at 0x267e4, `ld` at 0x26810.
  2 such `lhu` accesses load 2 bytes from [([[-0x3c00]:8]:8 + (a0 << 0x3))]:8 +0x8598, including `lhu` at 0x267ec, `lhu` at 0x26818.
  The `jal` at 0x267fc calls nmi_cpu_eframe_save with a0=[(sym(compact_to_nasid_node) + (a0 + a0))]:2, a1=?, a2=?, a3=?.
  The `beq` branch at 0x267c0 targets 0x2682c, is taken when a0 == a4(=-0x1), and falls through when a0 != a4(=-0x1).
  The `beq` branch at 0x267d0 targets 0x2682c, is taken when s2(=[(sym(compact_to_nasid_node) + (a0 + a0))]:2) == a4(=-0x1), and falls through when s2(=[(sym(compact_to_nasid_node) + (a0 + a0))]:2) != a4(=-0x1).
  The `blez` branch at 0x267f0 targets 0x2682c, is taken when t8(=[[([[-0x3c00]:8]:8 + (a0 << 0x3))]:8+34200]:2) <= 0 (signed), and falls through when t8(=[[([[-0x3c00]:8]:8 + (a0 << 0x3))]:8+34200]:2) > 0 (signed).
  The `bne` branch at 0x26824 targets 0x267fc, is taken when s0(?) < t9(=[[([[-0x3c00]:8]:8 + (a0 << 0x3))]:8+34200]:2) (signed), and falls through when s0(?) >= t9(=[[([[-0x3c00]:8]:8 + (a0 << 0x3))]:8+34200]:2) (signed).
  The return at 0x26840 has v0 = one of ?, ret(nmi_cpu_eframe_save).

- `nmi_eframes_save` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x26848 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x26848-0x26894 (76 bytes).
  It occupies 76 bytes.
  The `jal` at 0x26860 calls nmi_node_eframe_save with a0=?, a1=?, a2=?, a3=?.
  The `blez` branch at 0x26854 targets 0x26884, is taken when at(=[sym(numnodes)]) <= 0 (signed), and falls through when at(=[sym(numnodes)]) > 0 (signed).
  The `bne` branch at 0x2687c targets 0x26860, is taken when s0(?) < v0(=[sym(numnodes)]) (signed), and falls through when s0(?) >= v0(=[sym(numnodes)]) (signed).
  The return at 0x2688c has v0 = ?.

- `adjust_nmi_handler` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x26b04 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x26b04-0x26ea4 (928 bytes).
  It occupies 928 bytes.
  4 such `lh` accesses load 2 bytes from ?, including `lh` at 0x26b40, `lh` at 0x26b5c, `lh` at 0x26c2c.
  9 such `ld` accesses load 8 bytes from ?, including `ld` at 0x26b68, `ld` at 0x26bd4, `ld` at 0x26c54.
  2 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x26b74, `lbu` at 0x26c60.
  The `ld` at 0x26b7c loads 8 bytes from (table(0x9600000000000000) | 0x2000) +0xa8.
  The `ld` at 0x26ba0 loads 8 bytes from (table(0x9600000000000000) | 0x2000) +0x88.
  11 such `sd` accesses store 8 bytes to ?, including `sd` at 0x26bf4, `sd` at 0x26c04, `sd` at 0x26d4c.
  2 such `ld` accesses load 8 bytes from table(0x9200000001fc0000) +0x0, including `ld` at 0x26ca0, `ld` at 0x26da4.
  The `jal` at 0x26b10 calls get_nasid with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x26b24 calls getcpuid with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x26c84 calls is_fine_dirmode with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x26d64 calls qprintf with a0=sym(.rodata)+45664, a1=?, a2=?, a3=?.
  The `jal` at 0x26d80 calls is_fine_dirmode with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x26e84 calls qprintf with a0=sym(.rodata)+45664, a1=sym(cpuid_to_compact_node), a2=?, a3=?, a4=sym(nmi_dump), a5=sym(compact_to_nasid_node).
  The `jal` at 0x26e94 calls qprintf with a0=sym(.rodata)+45664, a1=sym(cpuid_to_compact_node), a2=?, a3=?, a4=sym(nmi_dump), a5=sym(compact_to_nasid_node).
  The `bne` branch at 0x26bcc targets 0x26bdc, is taken when at(=[sym(.sdata)+288]:8) != 0, and falls through when at(=[sym(.sdata)+288]:8) == 0.
  The `bltz` branch at 0x26bdc targets 0x26e74, is taken when s0(=a0) < 0 (signed), and falls through when s0(=a0) >= 0 (signed).
  The `blez` branch at 0x26be4 targets 0x26e44, is taken when a0(=[sym(maxcpus)]) <= 0 (signed), and falls through when a0(=[sym(maxcpus)]) > 0 (signed).
  The `beq` branch at 0x26bec targets 0x26c24 and is always taken.
  The `bne` branch at 0x26c00 targets 0x26d80, is taken when s4(?) != s3(?), and falls through when s4(?) == s3(?).
  The `beq` branch at 0x26c1c targets 0x26e44, is taken when s0(?) >= ra(=[sym(maxcpus)]) (signed), and falls through when s0(?) < ra(=[sym(maxcpus)]) (signed).
  The `beq` branch at 0x26ccc targets 0x26e04, is taken when 0 >= t9(?) (unsigned), and falls through when 0 < t9(?) (unsigned).
  The `beq` branch at 0x26cd4 targets 0x26e14, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x26ce8 targets 0x26e20, is taken when (a5(?) & 0x20) == 0, and falls through when (a5(?) & 0x20) != 0.
  The `beq` branch at 0x26d70 targets 0x26bf4, is taken when v0(=[sym(.sdata)+288]:8) == s5(?), and falls through when v0(=[sym(.sdata)+288]:8) != s5(?).
  The `beq` branch at 0x26d78 targets 0x26bfc and is always taken.
  The `beq` branch at 0x26ddc targets 0x26e28, is taken when 0 >= a3(?) (unsigned), and falls through when 0 < a3(?) (unsigned).
  The `beq` branch at 0x26dfc targets 0x26c08 and is always taken.
  The `beq` branch at 0x26e04 targets 0x26e38, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x26e0c targets 0x26cfc and is always taken.
  The `beq` branch at 0x26e18 targets 0x26ce4 and is always taken.
  The `beq` branch at 0x26e20 targets 0x26cf8 and is always taken.
  The `beq` branch at 0x26e30 targets 0x26dec and is always taken.
  The `beq` branch at 0x26e3c targets 0x26cf8 and is always taken.
  The `bne` branch at 0x26e78 targets 0x26e94, is taken when a3(?) != a4(=sym(nmi_dump)), and falls through when a3(?) == a4(=sym(nmi_dump)).
  The `beq` branch at 0x26e8c targets 0x26e48 and is always taken.
  The `beq` branch at 0x26e9c targets 0x26e48 and is always taken.
  The return at 0x26e6c has v0 = one of ?, ret(qprintf).

- `query_fasttimer` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x27ac8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x27ac8-0x27aec (36 bytes).
  It occupies 36 bytes.
  The `ld` at 0x27acc loads 8 bytes from abs 0x9200000001604200.
  The return at 0x27ae4 has v0 = ?.

- `tick_maint` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x27af4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x27af4-0x27b98 (164 bytes).
  It occupies 164 bytes.
  The `lh` at 0x27b20 loads 2 bytes from abs 0xffffffffffffc428.
  The `ld` at 0x27b34 loads 8 bytes from abs 0x9200000001030100.
  The `ld` at 0x27b38 loads 8 bytes from abs 0x9200000001604200.
  The `jal` at 0x27b88 calls __nanotime [0x28e3c] with a0=?, a1=[sym(.sbss)+144], a2=0x1, a3=?.
  The `beq` branch at 0x27b00 targets 0x27b20, is taken when at(=[sym(lbolt)]) == a2(=0x1), and falls through when at(=[sym(lbolt)]) != a2(=0x1).
  The `beq` branch at 0x27b10 targets 0x27b88, is taken when v0(=[sym(.sbss)+144]-1) == 0, and falls through when v0(=[sym(.sbss)+144]-1) != 0.
  The `bne` branch at 0x27b24 targets 0x27b0c, is taken when v1(=[-0x3bd8]:2) != 0, and falls through when v1(=[-0x3bd8]:2) == 0.
  The `beq` branch at 0x27b80 targets 0x27b08 and is always taken.
  The `beq` branch at 0x27b90 targets 0x27b18 and is always taken.
  The return at 0x27b18 has v0 = one of [sym(.sbss)+144]-1, ret(__nanotime).

- `init_fasthz_variables` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x27ebc (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x27ebc-0x27f5c (160 bytes).
  It occupies 160 bytes.
  2 such `ld` accesses load 8 bytes from abs 0x9200000001604200, including `ld` at 0x27ec0, `ld` at 0x27efc.
  The return at 0x27f54 has v0 = ?.

- `rtc_resolution` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x27f68 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x27f68-0x27f8c (36 bytes).
  It occupies 36 bytes.
  The `ld` at 0x27f6c loads 8 bytes from abs 0x9200000001604200.
  The return at 0x27f84 has v0 = ?.

- `doadjtime` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x28b8c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x28b8c-0x28e3c (688 bytes).
  It occupies 688 bytes.
  3 such `ld` accesses load 8 bytes from abs 0x9200000001604200, including `ld` at 0x28bd8, `ld` at 0x28d08, `ld` at 0x28d50.
  The `jal` at 0x28c14 calls splprof with a0=?, a1=?, a2=0x3e8, a3=a3 at entry (arg3).
  The `jal` at 0x28c1c calls __nanotime [0x28e3c] with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x28c2c calls nested_spinlock with a0=sym(timelock), a1=?, a2=?, a3=?.
  The `jal` at 0x28cd4 calls mutex_spinunlock with a0=sym(timelock), a1=ret(splprof), a2=[sym(.sbss)+108]+1, a3=?.
  The `jal` at 0x28db0 calls splprof with a0=a0 at entry (arg0), a1=0xf0000, a2=0x3e8, a3=a3 at entry (arg3).
  The `jal` at 0x28db8 calls __nanotime [0x28e3c] with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x28dc4 calls nested_spinlock with a0=sym(timelock), a1=?, a2=?, a3=?.
  The `jal` at 0x28e24 calls mutex_spinunlock with a0=sym(timelock), a1=ret(splprof), a2=?, a3=?, a4=0x3e8.
  The `beq` branch at 0x28bb8 targets 0x28db0, is taken when a0 == 0, and falls through when a0 != 0.
  The `bltz` branch at 0x28bc4 targets 0x28da0, is taken when a0 < 0 (signed), and falls through when a0 >= 0 (signed).
  The `beq` branch at 0x28bd0 targets 0x28cfc, is taken when s0(?) >= 0x3e8 (signed), and falls through when s0(?) < 0x3e8 (signed).
  The `bne` branch at 0x28c0c targets 0x28d98, is taken when a0(?) != 0, and falls through when a0(?) == 0.
  The `blez` branch at 0x28c70 targets 0x28cb4, is taken when a0(?) <= 0 (signed), and falls through when a0(?) > 0 (signed).
  The `bltz` branch at 0x28cb4 targets 0x28da8, is taken when s2(?) < 0 (signed), and falls through when s2(?) >= 0 (signed).
  The `bne` branch at 0x28d00 targets 0x28d50, is taken when t9(=0xf4240) < s0(?) (signed), and falls through when t9(=0xf4240) >= s0(?) (signed).
  The `beq` branch at 0x28d48 targets 0x28d90 and is always taken.
  The `beq` branch at 0x28d90 targets 0x28c14, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x28d98 targets 0x28c14 and is always taken.
  The `beq` branch at 0x28da0 targets 0x28bcc and is always taken.
  The `beq` branch at 0x28da8 targets 0x28cc0 and is always taken.
  The `blez` branch at 0x28ddc targets 0x28e34, is taken when a0(?) <= 0 (signed), and falls through when a0(?) > 0 (signed).
  The `beq` branch at 0x28e2c targets 0x28ce0 and is always taken.
  The `beq` branch at 0x28e34 targets 0x28e20 and is always taken.
  The return at 0x28cf4 has v0 = ?.

- `__nanotime` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x28e3c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x28e3c-0x290d4 (664 bytes).
  It occupies 664 bytes.
  The `ld` at 0x28e64 loads 8 bytes from abs 0x9200000001030100.
  4 such `ld` accesses load 8 bytes from abs 0x9200000001604200, including `ld` at 0x28e94, `ld` at 0x28f58, `ld` at 0x28fa0.
  3 such `ld` accesses load 8 bytes from sym(.bss) +0xa838, including `ld` at 0x28f54, `ld` at 0x28f9c, `ld` at 0x29048.
  2 such `sd` accesses store 8 bytes to sym(.bss) +0xa838, including `sd` at 0x2900c, `sd` at 0x290b0.
  2 such `lw` accesses load 4 bytes from sym(.bss) +0xa830, including `lw` at 0x29010, `lw` at 0x2901c.
  2 such `sw` accesses store 4 bytes to sym(.bss) +0xa830, including `sw` at 0x29018, `sw` at 0x290ac.
  The `jal` at 0x28e48 calls mutex_spinlock_spl with a0=sym(timelock), a1=sym(splprof), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x29034 calls mutex_spinunlock with a0=sym(timelock), a1=ret(mutex_spinlock_spl), a2=?, a3=?, a7=[0x9200000001030100]:8.
  The `jal` at 0x290c4 calls mutex_spinunlock with a0=sym(timelock), a1=ret(mutex_spinlock_spl), a2=?, a3=?, a5=0x3b9aca00, a7=[0x9200000001030100]:8.
  The `beq` branch at 0x28e80 targets 0x290a4, is taken when at(=[sym(.sbss)+112]:8) == 0, and falls through when at(=[sym(.sbss)+112]:8) != 0.
  The `beq` branch at 0x28ee8 targets 0x28f18, is taken when a7(=[0x9200000001030100]:8) >= t9(=([sym(adjtime_delta)]:8 + [sym(adjtime_RTC)]:8)) (unsigned), and falls through when a7(=[0x9200000001030100]:8) < t9(=([sym(adjtime_delta)]:8 + [sym(adjtime_RTC)]:8)) (unsigned).
  The `beq` branch at 0x28f10 targets 0x28f1c and is always taken.
  The `beq` branch at 0x28f20 targets 0x28f54, is taken when at(=[sym(adjtime_nanos)]:8) == 0, and falls through when at(=[sym(adjtime_nanos)]:8) != 0.
  The `bltz` branch at 0x28f34 targets 0x2908c, is taken when t0(?) < 0 (signed), and falls through when t0(?) >= 0 (signed).
  The `blez` branch at 0x28f3c targets 0x29094, is taken when a4(?) <= 0 (signed), and falls through when a4(?) > 0 (signed).
  The `bne` branch at 0x28f94 targets 0x29048, is taken when t8(?) < a5(=0x3b9aca00) (signed), and falls through when t8(?) >= a5(=0x3b9aca00) (signed).
  The `bne` branch at 0x28fec targets 0x29004, is taken when a4(=table(0xffffffffc4653600)) < a5(=0x3b9aca00) (signed), and falls through when a4(=table(0xffffffffc4653600)) >= a5(=0x3b9aca00) (signed).
  The `beq` branch at 0x28ffc targets 0x28fe0, is taken when a4(=table(0xffffffff88ca6c00)) >= a5(=0x3b9aca00) (signed), and falls through when a4(=table(0xffffffff88ca6c00)) < a5(=0x3b9aca00) (signed).
  The `beq` branch at 0x29008 targets 0x29024, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0x29084 targets 0x29004 and is always taken.
  The `bltz` branch at 0x2908c targets 0x28f44, is taken when a4(?) < 0 (signed), and falls through when a4(?) >= 0 (signed).
  The `beq` branch at 0x2909c targets 0x28f48 and is always taken.
  The `beq` branch at 0x290cc targets 0x29040 and is always taken.
  The return at 0x29040 has v0 = ret(mutex_spinunlock).

- `tstoclock` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x29628 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x29628-0x29694 (108 bytes).
  It occupies 108 bytes.
  The `lw` at 0x29628 loads 4 bytes from a0 (arg0 at entry) +0x0.
  The `ld` at 0x2963c loads 8 bytes from abs 0x9200000001604200.
  The `ld` at 0x2964c loads 8 bytes from a0 (arg0 at entry) +0x8.
  The `ld` at 0x29688 loads 8 bytes from abs 0x9200000001030100.
  The `beq` branch at 0x29674 targets 0x29684, is taken when a1 == v1(=0x1), and falls through when a1 != v1(=0x1).
  The return at 0x2967c has v0 = ?.
  The return at 0x2968c has v0 = ?.

- `tvtoclock` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x29694 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x29694-0x29714 (128 bytes).
  It occupies 128 bytes.
  The `lw` at 0x29694 loads 4 bytes from a0 (arg0 at entry) +0x4.
  The `ld` at 0x296a8 loads 8 bytes from a0 (arg0 at entry) +0x8.
  The `ld` at 0x296ac loads 8 bytes from abs 0x9200000001604200.
  The `ld` at 0x29708 loads 8 bytes from abs 0x9200000001030100.
  The `beq` branch at 0x296f4 targets 0x29704, is taken when a1 == v1(=0x1), and falls through when a1 != v1(=0x1).
  The return at 0x296fc has v0 = ?.
  The return at 0x2970c has v0 = ?.

- `findcpufreq_cycles` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x2973c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x2973c-0x29838 (252 bytes).
  It occupies 252 bytes.
  The `lw` at 0x2973c loads 4 bytes from abs 0xffffffffffffc74c.
  7 such `ld` accesses load 8 bytes from abs 0x9200000001030100, including `ld` at 0x29764, `ld` at 0x297a4, `ld` at 0x297bc.
  The `ld` at 0x29778 loads 8 bytes from abs 0x9200000001604200.
  The `sw` at 0x29820 stores 4 bytes to abs 0xffffffffffffc74c.
  The `jal` at 0x29754 calls splhi with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x2976c calls _set_count with a0=0x0, a1=?, a2=?, a3=?.
  The `jal` at 0x2980c calls _get_count with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x29814 calls cpu_cycles_adjust with a0=ret(_get_count), a1=?, a2=?, a3=?.
  The `jal` at 0x29824 calls splx with a0=ret(splhi), a1=?, a2=?, a3=?.
  The `beq` branch at 0x29744 targets 0x29754, is taken when v0(=[-0x38b4]) == 0, and falls through when v0(=[-0x38b4]) != 0.
  The `beq` branch at 0x297b4 targets 0x2980c, is taken when v1(=[0x9200000001030100]:8) >= a3(?) (unsigned), and falls through when v1(=[0x9200000001030100]:8) < a3(?) (unsigned).
  The `beq` branch at 0x297c4 targets 0x2980c, is taken when a0(=[0x9200000001030100]:8) >= a3(?) (unsigned), and falls through when a0(=[0x9200000001030100]:8) < a3(?) (unsigned).
  The `beq` branch at 0x297d4 targets 0x2980c, is taken when a1(=[0x9200000001030100]:8) >= a3(?) (unsigned), and falls through when a1(=[0x9200000001030100]:8) < a3(?) (unsigned).
  The `beq` branch at 0x297e4 targets 0x2980c, is taken when a2(=[0x9200000001030100]:8) >= a3(?) (unsigned), and falls through when a2(=[0x9200000001030100]:8) < a3(?) (unsigned).
  The `beq` branch at 0x297f4 targets 0x2980c, is taken when a4(=[0x9200000001030100]:8) >= a3(?) (unsigned), and falls through when a4(=[0x9200000001030100]:8) < a3(?) (unsigned).
  The `bne` branch at 0x29804 targets 0x297bc, is taken when a5(=[0x9200000001030100]:8) < a3(?) (unsigned), and falls through when a5(=[0x9200000001030100]:8) >= a3(?) (unsigned).
  The `beq` branch at 0x29830 targets 0x2974c and is always taken.
  The return at 0x2974c has v0 = one of [-0x38b4], ret(cpu_cycles_adjust).

- `acktmoclock` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x29f84.
  The routine takes the running processor's number from the halfword at -0x3bd8, uses it to index the per-processor
  pointer table at pdaindr (16 bytes per entry), and tests bit 0 of the byte at 0x528 past the pointer stored at +8 in
  that entry (beq at 0x29fa4). When the bit is set it stores a doubleword to 0x9200000001000128 and returns; when it is
  clear it stores to 0x9200000001000120 and returns. The name suggests a timeout acknowledgement, but no timer access
  appears in the facts. Grade: inferred.
  Reviewed: 2026-11-12

- `ackkgclock` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x29fc0.
  This has the same shape as `acktmoclock` at 0x29f84: the same processor number and per-processor byte are tested
  (beq at 0x29fe0), and the two exits store to 0x9200000001000130 and 0x9200000001000138. The stores mirror the pair in
  `acktmoclock`, so the two are probably companions, but the facts do not show how they are used. Grade: inferred.
  Reviewed: 2026-11-12

- `startkgclock` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x29ffc.
  The routine takes a spinlock at .sbss+192 with mutex_spinlock_spl (0x2a008), then tests the .sdata word at +368 (beq
  at 0x2a020). When that word is zero it calls setkgvector with prof_intr (0x2a1c4) and then rejoins the main path at
  0x2a028. On the main path it compares the value at -0x3ac4 with a1 (beq at 0x2a074); when they are equal it skips to
  mutex_spinunlock at 0x2a1b4. Otherwise it stores a word to -0x3ac4 and stores a doubleword to 0x9200000001000158
  (0x2a0f0) or to 0x9200000001000150 (0x2a1ac), chosen by bit 0 of the byte at 0x528 past the pointer at +8 of the
  pdaindr entry (beq at 0x2a0e4). It also stores a doubleword to 0x9200000001000118 (0x2a170) unless the bne at
  0x2a110 skips it. It passes the halfword at -0x3bd6 to cnodetocpu (0x2a104) only when the word at +0x3c58 past the
  pointer at -0x3bf8 is not 1 (beq at 0x2a0fc). It releases the lock through mutex_spinunlock at 0x2a184 and 0x2a1b4.
  Grade: inferred. The meanings of the -0x3bd6 and -0x3ac4 values are not established.
  Reviewed: 2026-11-12

- `slowkgclock` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x2a1dc.
  The routine takes the same spinlock (.sbss+192) through mutex_spinlock_spl (0x2a1f0) and releases it through
  mutex_spinunlock at 0x2a220 and 0x2a27c. When the .sdata word at +376 is zero (beq at 0x2a1e4) it first calls
  spinlock_init on that lock (0x2a2a4) and then rejoins before the lock is taken. It compares the halfword at
  master_procid with the running processor's number (bne at 0x2a20c). When they are equal and the word at audioclock
  is nonzero (beq at 0x2a214) it unlocks at 0x2a220 and returns; otherwise it continues. On the continuing path it
  stores a 32-bit word to the -0x3bf8 block at +0x3c58 (0x2a270) only when the .sdata word at +368 is nonzero (beq at
  0x2a250), then calls mutex_spinunlock (0x2a27c) with a 32-bit store to 0xffffffffffffc53c in its delay slot
  (0x2a280), and then calls ackkgclock (0x2a284). Grade: inferred.
  Reviewed: 2026-11-12

- `timestamp_init` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x2ac08 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x2ac08-0x2ac80 (120 bytes).
  It occupies 120 bytes.
  The `ld` at 0x2ac0c loads 8 bytes from abs 0x9200000001604200.
  The return at 0x2ac78 has v0 = ?.

- `prof_intr` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x2ac80 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x2ac80-0x2ae50 (464 bytes).
  It occupies 464 bytes.
  2 such `ld` accesses load 8 bytes from abs 0xffffffffffffc280, including `ld` at 0x2ac80, `ld` at 0x2adf8.
  3 such `ld` accesses load 8 bytes from abs 0x9200000001604200, including `ld` at 0x2aca4, `ld` at 0x2ad54, `ld` at 0x2ada8.
  The `lw` at 0x2ace0 loads 4 bytes from abs 0xffffffffffffc53c.
  4 such `ld` accesses load 8 bytes from abs 0xffffffffffffc408, including `ld` at 0x2acf4, `ld` at 0x2ad48, `ld` at 0x2ad94.
  The `lw` at 0x2acf8 loads 4 bytes from [-0x3bf8]:8 +0x3c58.
  The `lh` at 0x2acfc loads 2 bytes from abs 0xffffffffffffc428.
  The `ld` at 0x2ad18 loads 8 bytes from (sym(pdaindr) + ([-0x3bd8]:2 << 0x4)) +0x8.
  The `lbu` at 0x2ad1c loads 1 byte from [(sym(pdaindr) + ([-0x3bd8]:2 << 0x4))+8]:8 +0x528.
  The `lh` at 0x2ad24 loads 2 bytes from abs 0xffffffffffffc42a.
  The `ld` at 0x2ad50 loads 8 bytes from abs 0x9200000001030100.
  3 such `ld` accesses load 8 bytes from [-0x3bf8]:8 +0x3c50, including `ld` at 0x2ad84, `ld` at 0x2ad98, `ld` at 0x2adec.
  2 such `sd` accesses store 8 bytes to [-0x3bf8]:8 +0x3c50, including `sd` at 0x2ad90, `sd` at 0x2ade0.
  The `sd` at 0x2adf4 stores 8 bytes to abs 0x9200000001000118.
  The `jal` at 0x2ac98 calls fastick_maint with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x2ad28 calls cnode_subnode_to_cpu with a0=[-0x3bd6]:2, a1=?, a2=([-0x3bd8]:2 << 0x4), a3=0x9200000001604200, a4=0x3b9aca00, a5=[-0x3bd8]:2, a6=0x3e8.
  The `jal` at 0x2ae20 calls log_tstamp_event with a0=0x6e, a1=0x0, a2=0x0, a3=0x0, a4=0x0.
  The `jal` at 0x2ae40 calls log_tstamp_event with a0=0x65, a1=0x6e, a2=0x0, a3=0x0, a4=0x0, a6=0x3e8.
  The `bne` branch at 0x2ac90 targets 0x2ae10, is taken when (at(=[-0x3d80]:8) & 0x20) != 0, and falls through when (at(=[-0x3d80]:8) & 0x20) == 0.
  The `bne` branch at 0x2acec targets 0x2adf8, is taken when v1(=[-0x3ac4]) != a0(?), and falls through when v1(=[-0x3ac4]) == a0(?).
  The `beq` branch at 0x2ad00 targets 0x2ad4c, is taken when a1(=[[-0x3bf8]:8+15448]) == a2(=0x1), and falls through when a1(=[[-0x3bf8]:8+15448]) != a2(=0x1).
  The `bne` branch at 0x2ad40 targets 0x2adf8, is taken when a5(=[-0x3bd8]:2) != v0(=ret(cnode_subnode_to_cpu)), and falls through when a5(=[-0x3bd8]:2) == v0(=ret(cnode_subnode_to_cpu)).
  The `beq` branch at 0x2ada0 targets 0x2adf0, is taken when a2(=[[-0x3bf8]:8+15440]:8) >= a5(=[0x9200000001030100]:8) (unsigned), and falls through when a2(=[[-0x3bf8]:8+15440]:8) < a5(=[0x9200000001030100]:8) (unsigned).
  The `bne` branch at 0x2ae00 targets 0x2ae30, is taken when (t2(=[-0x3d80]:8) & 0x20) != 0, and falls through when (t2(=[-0x3d80]:8) & 0x20) == 0.
  The `beq` branch at 0x2ae28 targets 0x2ac98 and is always taken.
  The `beq` branch at 0x2ae48 targets 0x2ae08 and is always taken.
  The return at 0x2ae08 has v0 = one of ?, ret(log_tstamp_event).

- `init_hub_stats` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x2b20c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x2b20c-0x2b358 (332 bytes).
  It occupies 332 bytes.
  The `lh` at 0x2b23c loads 2 bytes from (sym(compact_to_nasid_node) + (a0 + a0)) +0x0.
  The `sh` at 0x2b264 stores 2 bytes to a1 (arg1 at entry) +0x87ca.
  The `sb` at 0x2b26c stores 1 byte to a1 (arg1 at entry) +0x87c8.
  The `sh` at 0x2b274 stores 2 bytes to a1 (arg1 at entry) +0x87cc.
  The `ld` at 0x2b278 loads 8 bytes from abs 0x9200000001030100.
  The `sd` at 0x2b280 stores 8 bytes to a1 (arg1 at entry) +0x87d0.
  The `ld` at 0x2b288 loads 8 bytes from ([(sym(compact_to_nasid_node) + (a0 + a0))]:2 << 0x21) -0x6dfffffffe180000.
  The `sd` at 0x2b290 stores 8 bytes to a1 (arg1 at entry) +0x87e8.
  The `sd` at 0x2b294 stores 8 bytes to ([(sym(compact_to_nasid_node) + (a0 + a0))]:2 << 0x21) -0x6dfffffffe3ffed0.
  The `ld` at 0x2b298 loads 8 bytes from ([(sym(compact_to_nasid_node) + (a0 + a0))]:2 << 0x21) -0x6dfffffffe17fee0.
  The `ld` at 0x2b29c loads 8 bytes from abs 0x9200000001604200.
  The `sw` at 0x2b2dc stores 4 bytes to a1 (arg1 at entry) +0x8848.
  The `sd` at 0x2b2e4 stores 8 bytes to a1 (arg1 at entry) +0x87e0.
  The `sd` at 0x2b300 stores 8 bytes to a1 (arg1 at entry) +0x8838.
  The `lh` at 0x2b310 loads 2 bytes from a1 (arg1 at entry) +0x861a.
  The `sd` at 0x2b314 stores 8 bytes to a1 (arg1 at entry) +0x8828.
  The `sb` at 0x2b31c stores 1 byte to a1 (arg1 at entry) +0x8830.
  The `ld` at 0x2b354 loads 8 bytes from a1 (arg1 at entry) +0x8838.
  The `jal` at 0x2b244 calls bzero with a0=a1+34760, a1=0x80, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x2b2e8 calls kmem_alloc_node with a0=0x50, a1=0x1, a2=a0 at entry (arg0), a3=?, a5=0xc8, a6=0x3b9aca00, a7=([(sym(compact_to_nasid_node) + (a0 + a0))]:2 << 0x21)+0x9200000001c00000.
  The `jal` at 0x2b30c calls sprintf with a0=?, a1=sym(.rodata)+46952, a2=[a1+34330]:2, a3=?, a4=sym(.rodata)+46952.
  The `jal` at 0x2b344 calls assfail with a0=sym(.rodata)+46952, a1=sym(.rodata)+46952, a2=0x116, a3=?.
  The `beq` branch at 0x2b2fc targets 0x2b338, is taken when v0(=ret(kmem_alloc_node)) == 0, and falls through when v0(=ret(kmem_alloc_node)) != 0.
  The `beq` branch at 0x2b350 targets 0x2b308 and is always taken.
  The return at 0x2b330 has v0 = ret(sprintf).

- `kl_compute_parity` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x2b454 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x2b454-0x2b4fc (168 bytes).
  It occupies 168 bytes.
  The `jal` at 0x2b4a8 calls ecc_bitcount with a0=?, a1=?, a2=?, a3=?.
  The `blez` branch at 0x2b48c targets 0x2b4d0, is taken when a2 <= 0 (signed), and falls through when a2 > 0 (signed).
  The `beq` branch at 0x2b4bc targets 0x2b4c8, is taken when (v0(=ret(ecc_bitcount)) & 0x1) == 0, and falls through when (v0(=ret(ecc_bitcount)) & 0x1) != 0.
  The `bne` branch at 0x2b4c8 targets 0x2b4a8, is taken when a0(?) != 0, and falls through when a0(?) == 0.
  The return at 0x2b4f4 has v0 = one of 0x0, ?.

- `kl_compute_dir_ecc_cb` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x2b4fc (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x2b4fc-0x2b5bc (192 bytes).
  It occupies 192 bytes.
  The `ld` at 0x2b550 loads 8 bytes from ?.
  The `jal` at 0x2b558 calls ecc_bitcount with a0=?, a1=?, a2=?, a3=?.
  The `beq` branch at 0x2b524 targets 0x2b5a8, is taken when a1 == 0, and falls through when a1 != 0.
  The `beq` branch at 0x2b56c targets 0x2b578, is taken when (v0(=ret(ecc_bitcount)) & 0x1) == 0, and falls through when (v0(=ret(ecc_bitcount)) & 0x1) != 0.
  The `beq` branch at 0x2b578 targets 0x2b54c, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0x2b5b4 targets 0x2b538 and is always taken.
  The return at 0x2b5a0 has v0 = ?.

- `kl_compute_mem_ecc_cb` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x2b5bc (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x2b5bc-0x2b630 (116 bytes).
  It occupies 116 bytes.
  The `ld` at 0x2b5ec loads 8 bytes from ?.
  The `jal` at 0x2b5f0 calls ecc_bitcount with a0=?, a1=?, a2=?, a3=?.
  The `bne` branch at 0x2b608 targets 0x2b5e4, is taken when s0(?) < 0x8 (signed), and falls through when s0(?) >= 0x8 (signed).
  The return at 0x2b628 has v0 = ?.

- `mdir_xlate_syndrome` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x2b630 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x2b630-0x2b86c (572 bytes).
  It occupies 572 bytes.
  The `lbu` at 0x2b678 loads 1 byte from a0 (arg0 at entry) +0x0.
  8 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x2b684, `lbu` at 0x2b694, `lbu` at 0x2b6a4.
  The `lbu` at 0x2b774 loads 1 byte from sym(.rodata) +0xb854.
  The `lw` at 0x2b778 loads 4 bytes from sym(.rodata) +0xb850.
  The `ld` at 0x2b77c loads 8 bytes from sym(.rodata) +0xb848.
  The `sdl` at 0x2b780 stores 8 bytes to ?.
  The `sdr` at 0x2b784 stores 8 bytes to ?.
  3 such `swl` accesses store 4 bytes to ?, including `swl` at 0x2b788, `swl` at 0x2b7cc, `swl` at 0x2b810.
  3 such `swr` accesses store 4 bytes to ?, including `swr` at 0x2b78c, `swr` at 0x2b7d0, `swr` at 0x2b814.
  4 such `sb` accesses store 1 byte to ?, including `sb` at 0x2b798, `sb` at 0x2b7dc, `sb` at 0x2b818.
  The `lbu` at 0x2b7c4 loads 1 byte from sym(.rodata) +0xb87c.
  The `lw` at 0x2b7c8 loads 4 bytes from sym(.rodata) +0xb878.
  The `lbu` at 0x2b804 loads 1 byte from sym(.rodata) +0xb885.
  The `lw` at 0x2b808 loads 4 bytes from sym(.rodata) +0xb880.
  The `lbu` at 0x2b80c loads 1 byte from sym(.rodata) +0xb884.
  The `jal` at 0x2b670 calls sprintf with a0=a0 at entry (arg0), a1=sym(.rodata)+47160, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x2b73c calls sprintf with a0=?, a1=sym(.rodata)+47160, a2=?, a3=?, a4=0x7f, a7=sym(.rodata)+47160.
  The `jal` at 0x2b750 calls strcat with a0=?, a1=sym(.rodata)+47160, a2=?, a3=?.
  The `jal` at 0x2b85c calls sprintf with a0=?, a1=sym(.rodata)+47160, a2=?, a3=?, a4=0x7f, a7=sym(.rodata)+47160.
  The `beq` branch at 0x2b650 targets 0x2b79c, is taken when a1 == 0, and falls through when a1 != 0.
  The `beq` branch at 0x2b65c targets 0x2b7e0, is taken when a1 == at(=0x2), and falls through when a1 != at(=0x2).
  The `beq` branch at 0x2b664 targets 0x2b828, is taken when a1 == v0(=0x1), and falls through when a1 != v0(=0x1).
  The `beq` branch at 0x2b67c targets 0x2b6d0, is taken when v0(=[a0]:1) == 0, and falls through when v0(=[a0]:1) != 0.
  The `beq` branch at 0x2b68c targets 0x2b6d0, is taken when v1(?) == 0, and falls through when v1(?) != 0.
  The `beq` branch at 0x2b69c targets 0x2b6d0, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x2b6ac targets 0x2b6d0, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x2b6bc targets 0x2b6d0, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `bne` branch at 0x2b6c8 targets 0x2b684, is taken when a3(?) != 0, and falls through when a3(?) == 0.
  The `beq` branch at 0x2b6d0 targets 0x2b7c0, is taken when s1(=a2) == 0, and falls through when s1(=a2) != 0.
  The `beq` branch at 0x2b6dc targets 0x2b770, is taken when s1(=a2) == a4(=0x7f), and falls through when s1(=a2) != a4(=0x7f).
  The `bne` branch at 0x2b6e8 targets 0x2b710, is taken when v0(?) != 0, and falls through when v0(?) == 0.
  The `beq` branch at 0x2b6f0 targets 0x2b71c and is always taken.
  The `beq` branch at 0x2b708 targets 0x2b71c, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `bne` branch at 0x2b710 targets 0x2b6f8, is taken when v0(?) != s1(=a2), and falls through when v0(?) == s1(=a2).
  The `beq` branch at 0x2b71c targets 0x2b800, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x2b728 targets 0x2b848, is taken when (a6(?) & 0x80) == 0, and falls through when (a6(?) & 0x80) != 0.
  The `bne` branch at 0x2b770 targets 0x2b6e0, is taken when s2(=a1) != 0, and falls through when s2(=a1) == 0.
  The `beq` branch at 0x2b794 targets 0x2b744 and is always taken.
  The `beq` branch at 0x2b7b8 targets 0x2b668 and is always taken.
  The `beq` branch at 0x2b7d8 targets 0x2b744 and is always taken.
  The `beq` branch at 0x2b7f8 targets 0x2b668 and is always taken.
  The `beq` branch at 0x2b820 targets 0x2b744 and is always taken.
  The `beq` branch at 0x2b840 targets 0x2b668 and is always taken.
  The `beq` branch at 0x2b864 targets 0x2b748 and is always taken.
  The return at 0x2b768 has v0 = ?.

- `mdir_xlate_addr_mem` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x2b86c.
  The routine loads a doubleword from 0x9200000001780008 (0x2b870) and branches on the sign of a2 (bltz at 0x2b8a8).
  Both paths format text with sprintf (calls at 0x2b8e0 and 0x2b900) and return sprintf's result. The facts render
  .rodata+47160 as the format string of both calls, but the disassembly adds 128 to the base pointer before the first
  call (0x2b8d8) and 96 in the second call's delay slot (0x2b904), so the two strings differ and the facts' value for
  the second call is doubtful. Role (from name): a directory-address translation. The facts show no translation
  arithmetic, so what the formatted text is for is unknown. Grade: inferred.
  Reviewed: 2026-11-12

- `mdir_xlate_addr_pdir` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x2b910 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x2b910-0x2b990 (128 bytes).
  It occupies 128 bytes.
  The `ld` at 0x2b914 loads 8 bytes from abs 0x9200000001780008.
  The `jal` at 0x2b960 calls sprintf with a0=a0 at entry (arg0), a1=sym(.rodata)+47160, a2=?, a3=a3 at entry (arg3), a4=a2 at entry (arg2).
  The `jal` at 0x2b980 calls sprintf with a0=a0 at entry (arg0), a1=sym(.rodata)+47160, a2=?, a3=?, a4=a2 at entry (arg2).
  The `bltz` branch at 0x2b948 targets 0x2b974, is taken when a2 < 0 (signed), and falls through when a2 >= 0 (signed).
  The `beq` branch at 0x2b988 targets 0x2b96c and is always taken.
  The return at 0x2b96c has v0 = ret(sprintf).

- `mdir_xlate_addr_sdir` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x2b990 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x2b990-0x2b9e0 (80 bytes).
  It occupies 80 bytes.
  The `ld` at 0x2b994 loads 8 bytes from abs 0x9200000001780008.
  The `jal` at 0x2b9cc calls sprintf with a0=a0 at entry (arg0), a1=sym(.rodata)+47160, a2=?, a3=?, a4=0x1ffffffff.
  The return at 0x2b9d8 has v0 = ret(sprintf).

- `intrgroup_init` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x2c8d8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x2c8d8-0x2c988 (176 bytes).
  It occupies 176 bytes.
  2 such `sd` accesses store 8 bytes to ?, including `sd` at 0x2c904, `sd` at 0x2c940.
  The `sw` at 0x2c94c stores 4 bytes to ?.
  The `jal` at 0x2c90c calls spinlock_init with a0=sym(.bss)+45120, a1=sym(.rodata)+48512, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x2c950 calls spinlock_init with a0=?, a1=sym(.rodata)+48512, a2=?, a3=?.
  The `bne` branch at 0x2c900 targets 0x2c8f0, is taken when a1(?) < 0x8 (signed), and falls through when a1(?) >= 0x8 (signed).
  The `bne` branch at 0x2c93c targets 0x2c92c, is taken when a1(?) < 0x8 (signed), and falls through when a1(?) >= 0x8 (signed).
  The `bne` branch at 0x2c96c targets 0x2c928, is taken when s0(?) < 0x10 (signed), and falls through when s0(?) >= 0x10 (signed).
  The return at 0x2c980 has v0 = ret(spinlock_init).

- `intrgroup_alloc` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x2c988 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x2c988-0x2ca6c (228 bytes).
  It occupies 228 bytes.
  The `ld` at 0x2c9c4 loads 8 bytes from ?.
  2 such `sd` accesses store 8 bytes to ?, including `sd` at 0x2ca0c, `sd` at 0x2ca2c.
  The `sd` at 0x2ca4c stores 8 bytes to table(sym(.bss)+45120) +0x48.
  The `jal` at 0x2c9a4 calls mutex_spinlock with a0=sym(.bss)+45120, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x2c9f0 calls mutex_spinunlock with a0=sym(.bss)+45120, a1=ret(mutex_spinlock), a2=?, a3=?, a7=table(sym(.bss)+45120).
  The `jal` at 0x2ca34 calls mutex_spinunlock with a0=sym(.bss)+45120, a1=ret(mutex_spinlock), a2=?, a3=?.
  The `jal` at 0x2ca44 calls kmem_zalloc with a0=([sym(maxcpus)] << 0x2), a1=0x0, a2=?, a3=?.
  The `beq` branch at 0x2c9cc targets 0x2ca00, is taken when (a5(?) & a6(?)) == 0, and falls through when (a5(?) & a6(?)) != 0.
  The `bne` branch at 0x2c9e4 targets 0x2c9c0, is taken when a4(?) < 0x10 (signed), and falls through when a4(?) >= 0x10 (signed).
  The `beq` branch at 0x2c9f8 targets 0x2ca50 and is always taken.
  The `bne` branch at 0x2ca28 targets 0x2ca18, is taken when t0(?) < 0x8 (signed), and falls through when t0(?) >= 0x8 (signed).
  The return at 0x2ca64 has v0 = one of 0x0, table(sym(.bss)+45120).

- `intrgroup_join` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x2ca6c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x2ca6c-0x2cbd0 (356 bytes).
  It occupies 356 bytes.
  The `ld` at 0x2caa8 loads 8 bytes from ?.
  The `sd` at 0x2caf0 stores 8 bytes to ?.
  4 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x40, including `lw` at 0x2caf4, `lw` at 0x2cb38, `lw` at 0x2cba0.
  3 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x48, including `ld` at 0x2cb50, `ld` at 0x2cb70, `ld` at 0x2cbcc.
  The `sb` at 0x2cb68 stores 1 byte to ([a0+72]:8 + (a1 << 0x2)) +0x0.
  The `ld` at 0x2cb6c loads 8 bytes from (sym(pdaindr) + (a1 << 0x4)) +0x8.
  The `lh` at 0x2cb7c loads 2 bytes from [(sym(pdaindr) + (a1 << 0x4))+8]:8 +0x42c.
  The `sh` at 0x2cb88 stores 2 bytes to ([a0+72]:8 + (a1 << 0x2)) +0x2.
  The `jal` at 0x2ca90 calls mutex_spinlock with a0=a0+68, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x2cac0 calls mutex_spinunlock with a0=a0+68, a1=ret(mutex_spinlock), a2=?, a3=?.
  The `jal` at 0x2caf8 calls sprintf with a0=sp-64, a1=sym(.rodata)+48512, a2=[a0+64], a3=?.
  The `jal` at 0x2cb14 calls intr_reserve_level with a0=a1 at entry (arg1), a1=-0x1, a2=0x0, a3=-0x1, a4=sp-64.
  The `jal` at 0x2cb3c calls intr_connect_level with a0=a1 at entry (arg1), a1=ret(intr_reserve_level), a2=0x0, a3=sym(groupintr), a4=[a0+64], a5=0x0.
  The `jal` at 0x2cb84 calls mutex_spinunlock with a0=a0+68, a1=ret(mutex_spinlock), a2=?, a3=?, a5=[[(sym(pdaindr) + (a1 << 0x4))+8]:8+1068]:2, a6=([a0+72]:8 + (a1 << 0x2)), a7=(a1 << 0x2).
  The `jal` at 0x2cba4 calls cmn_err with a0=0x0, a1=sym(.rodata)+48512, a2=ret(intr_reserve_level), a3=[a0+64].
  The `jal` at 0x2cbc0 calls cmn_err with a0=0x0, a1=sym(.rodata)+48512, a2=ret(intr_reserve_level), a3=[a0+64], a4=-0x1.
  The `beq` branch at 0x2cab4 targets 0x2cae4, is taken when (a5(?) & a7(?)) == 0, and falls through when (a5(?) & a7(?)) != 0.
  The `beq` branch at 0x2cb20 targets 0x2cb94, is taken when v0(=ret(intr_reserve_level)) == a3(=-0x1), and falls through when v0(=ret(intr_reserve_level)) != a3(=-0x1).
  The `beq` branch at 0x2cb48 targets 0x2cbb4, is taken when v0(=ret(intr_connect_level)) == a4(=-0x1), and falls through when v0(=ret(intr_connect_level)) != a4(=-0x1).
  The `beq` branch at 0x2cb8c targets 0x2cac8 and is always taken.
  The `beq` branch at 0x2cbac targets 0x2cb2c and is always taken.
  The `beq` branch at 0x2cbc8 targets 0x2cb54 and is always taken.
  The return at 0x2cadc has v0 = ret(mutex_spinunlock).

- `intrgroup_unjoin` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x2cbd0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x2cbd0-0x2cce4 (276 bytes).
  It occupies 276 bytes.
  The `ld` at 0x2cc0c loads 8 bytes from ?.
  The `sd` at 0x2cc2c stores 8 bytes to ?.
  5 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x48, including `ld` at 0x2cc30, `ld` at 0x2cc58, `ld` at 0x2cc6c.
  2 such `lbu` accesses load 1 byte from ([a0+72]:8 + (a1 << 0x2)) +0x0, including `lbu` at 0x2cc3c, `lbu` at 0x2cc68.
  The `sb` at 0x2cc74 stores 1 byte to ([a0+72]:8 + (a1 << 0x2)) +0x0.
  The `sh` at 0x2cc90 stores 2 bytes to ([a0+72]:8 + (a1 << 0x2)) +0x2.
  The `lw` at 0x2ccd0 loads 4 bytes from a0 (arg0 at entry) +0x40.
  The `jal` at 0x2cbf4 calls mutex_spinlock with a0=a0+68, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x2cc44 calls intr_disconnect_level with a0=a1 at entry (arg1), a1=[([a0+72]:8 + (a1 << 0x2))]:1, a2=?, a3=?.
  The `jal` at 0x2cc64 calls intr_unreserve_level with a0=a1 at entry (arg1), a1=[([a0+72]:8 + (a1 << 0x2))]:1, a2=?, a3=?.
  The `jal` at 0x2cc8c calls mutex_spinunlock with a0=a0+68, a1=ret(mutex_spinlock), a2=-0x1, a3=([a0+72]:8 + (a1 << 0x2)), a4=([a0+72]:8 + (a1 << 0x2)).
  The `jal` at 0x2ccb8 calls mutex_spinunlock with a0=a0+68, a1=ret(mutex_spinlock), a2=?, a3=?.
  The `jal` at 0x2ccd4 calls cmn_err with a0=0x0, a1=sym(.rodata)+48512, a2=[([a0+72]:8 + (a1 << 0x2))]:1, a3=[a0+64].
  The `beq` branch at 0x2cc1c targets 0x2ccb4, is taken when (a5(?) & a7(?)) == 0, and falls through when (a5(?) & a7(?)) != 0.
  The `beq` branch at 0x2cc50 targets 0x2ccc8, is taken when v0(=ret(intr_disconnect_level)) == a3(=-0x1), and falls through when v0(=ret(intr_disconnect_level)) != a3(=-0x1).
  The `beq` branch at 0x2ccc0 targets 0x2cc98 and is always taken.
  The `beq` branch at 0x2ccdc targets 0x2cc5c and is always taken.
  The return at 0x2ccac has v0 = ret(mutex_spinunlock).

- `intrgroup_free` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x2cce4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x2cce4-0x2cdcc (232 bytes).
  It occupies 232 bytes.
  The `ld` at 0x2cd3c loads 8 bytes from ?.
  The `ld` at 0x2cd64 loads 8 bytes from a0 (arg0 at entry) +0x48.
  The `lw` at 0x2cd7c loads 4 bytes from a0 (arg0 at entry) +0x40.
  The `ld` at 0x2cd94 loads 8 bytes from table(sym(.bss)+45120) +0x500.
  The `sd` at 0x2cdac stores 8 bytes to table(sym(.bss)+45120) +0x500.
  The `jal` at 0x2cd14 calls intrgroup_unjoin with a0=a0 at entry (arg0), a1=?, a2=?, a3=[sym(maxcpus)].
  The `jal` at 0x2cd60 calls kmem_free with a0=[a0+72]:8, a1=([sym(maxcpus)] << 0x2), a2=?, a3=[sym(maxcpus)].
  The `jal` at 0x2cd74 calls mutex_spinlock with a0=sym(.bss)+45120, a1=?, a2=?, a3=?.
  The `jal` at 0x2cda8 calls mutex_spinunlock with a0=sym(.bss)+45120, a1=ret(mutex_spinlock), a2=?, a3=table(sym(.bss)+45120).
  The `blez` branch at 0x2ccfc targets 0x2cdc4, is taken when a3(=[sym(maxcpus)]) <= 0 (signed), and falls through when a3(=[sym(maxcpus)]) > 0 (signed).
  The `beq` branch at 0x2cd08 targets 0x2cd30 and is always taken.
  The `beq` branch at 0x2cd28 targets 0x2cd60, is taken when s0(?) >= a3(=[sym(maxcpus)]) (signed), and falls through when s0(?) < a3(=[sym(maxcpus)]) (signed).
  The `bne` branch at 0x2cd48 targets 0x2cd10, is taken when (a4(?) & a5(?)) != 0, and falls through when (a4(?) & a5(?)) == 0.
  The `bne` branch at 0x2cd58 targets 0x2cd30, is taken when s0(?) < a3(=[sym(maxcpus)]) (signed), and falls through when s0(?) >= a3(=[sym(maxcpus)]) (signed).
  The `beq` branch at 0x2cdc4 targets 0x2cd5c and is always taken.
  The return at 0x2cdbc has v0 = ret(mutex_spinunlock).

- `sendgroupintr` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x2ce4c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x2ce4c-0x2cf54 (264 bytes).
  It occupies 264 bytes.
  The `lh` at 0x2ce54 loads 2 bytes from abs 0xffffffffffffc428.
  3 such `ld` accesses load 8 bytes from ?, including `ld` at 0x2ce98, `ld` at 0x2cebc, `ld` at 0x2cf0c.
  2 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x2cec0, `lbu` at 0x2cee8.
  The `ld` at 0x2cec8 loads 8 bytes from a0 (arg0 at entry) +0x48.
  The `lh` at 0x2ced0 loads 2 bytes from ?.
  The `sd` at 0x2cef4 stores 8 bytes to ?.
  The `ld` at 0x2cf50 loads 8 bytes from a0 (arg0 at entry) +0x0.
  The `jal` at 0x2cf20 calls groupintr with a0=0x0, a1=?, a2=?, a3=?, a4=[sym(maxcpus)], a6=[-0x3bd8]:2, a7=0x1.
  The `blez` branch at 0x2ce70 targets 0x2cf38, is taken when a4(=[sym(maxcpus)]) <= 0 (signed), and falls through when a4(=[sym(maxcpus)]) > 0 (signed).
  The `beq` branch at 0x2ce78 targets 0x2cf40 and is always taken.
  The `beq` branch at 0x2ce90 targets 0x2cf00, is taken when a2(?) >= a4(=[sym(maxcpus)]) (signed), and falls through when a2(?) < a4(=[sym(maxcpus)]) (signed).
  The `beq` branch at 0x2ceac targets 0x2ce80, is taken when (t9(?) & at(?)) == 0, and falls through when (t9(?) & at(?)) != 0.
  The `beq` branch at 0x2ceb4 targets 0x2ce80, is taken when a6(=[-0x3bd8]:2) == a2(?), and falls through when a6(=[-0x3bd8]:2) != a2(?).
  The `beq` branch at 0x2cef8 targets 0x2ce80 and is always taken.
  The `beq` branch at 0x2cf18 targets 0x2cf28, is taken when (a2(?) & a3(?)) == 0, and falls through when (a2(?) & a3(?)) != 0.
  The `beq` branch at 0x2cf38 targets 0x2cf04 and is always taken.
  The `beq` branch at 0x2cf4c targets 0x2ce9c and is always taken.
  The return at 0x2cf30 has v0 = 0x0.

- `hubdev_init` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x2d2d0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x2d2d0-0x2d2fc (44 bytes).
  It occupies 44 bytes.
  The `jal` at 0x2d2e4 calls init_mutex with a0=sym(hubdev_callout_mutex), a1=0x0, a2=sym(.rodata)+48704, a3=-0x1.
  The return at 0x2d2f4 has v0 = ret(init_mutex).

- `hubdev_register` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x2d2fc (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x2d2fc-0x2d354 (88 bytes).
  It occupies 88 bytes.
  The `sd` at 0x2d334 stores 8 bytes to ret(kmem_zalloc) +0x8.
  The `sd` at 0x2d340 stores 8 bytes to ret(kmem_zalloc) +0x0.
  The `jal` at 0x2d310 calls kmem_zalloc with a0=0x10, a1=0x0, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x2d320 calls mutex_lock with a0=sym(hubdev_callout_mutex), a1=0x19, a2=?, a3=?.
  The `jal` at 0x2d33c calls mutex_unlock with a0=sym(hubdev_callout_mutex), a1=?, a2=?, a3=?.
  The return at 0x2d34c has v0 = ret(mutex_unlock).

- `hubdev_unregister` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x2d354 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x2d354-0x2d3d4 (128 bytes).
  It occupies 128 bytes.
  3 such `ld` accesses load 8 bytes from ?, including `ld` at 0x2d37c, `ld` at 0x2d38c, `ld` at 0x2d3b4.
  The `sd` at 0x2d3c0 stores 8 bytes to ?.
  The `jal` at 0x2d368 calls mutex_lock with a0=sym(hubdev_callout_mutex), a1=0x19, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x2d398 calls mutex_unlock with a0=sym(hubdev_callout_mutex), a1=?, a2=?, a3=?.
  The `jal` at 0x2d3bc calls kmem_free with a0=?, a1=0x10, a2=?, a3=?.
  The `jal` at 0x2d3c4 calls mutex_unlock with a0=sym(hubdev_callout_mutex), a1=?, a2=?, a3=?.
  The `beq` branch at 0x2d374 targets 0x2d398, is taken when a0(=[sym(hubdev_callout_list)]:8) == 0, and falls through when a0(=[sym(hubdev_callout_list)]:8) != 0.
  The `beq` branch at 0x2d380 targets 0x2d3b4, is taken when at(?) == s0(=a0), and falls through when at(?) != s0(=a0).
  The `bne` branch at 0x2d390 targets 0x2d37c, is taken when a0(?) != 0, and falls through when a0(?) == 0.
  The `beq` branch at 0x2d3cc targets 0x2d3a4 and is always taken.
  The return at 0x2d3ac has v0 = one of 0x0, 0x2.

- `hubdev_docallouts` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x2d3d4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x2d3d4-0x2d460 (140 bytes).
  It occupies 140 bytes.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0x2d408, `ld` at 0x2d41c.
  The `jal` at 0x2d3f4 calls mutex_lock with a0=sym(hubdev_callout_mutex), a1=0x19, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jalr` at 0x2d40c calls (unknown callee) with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x2d428 calls mutex_unlock with a0=sym(hubdev_callout_mutex), a1=?, a2=?, a3=?.
  The `jal` at 0x2d450 calls mutex_unlock with a0=sym(hubdev_callout_mutex), a1=?, a2=?, a3=?.
  The `beq` branch at 0x2d400 targets 0x2d428, is taken when at(=[sym(hubdev_callout_list)]:8) == 0, and falls through when at(=[sym(hubdev_callout_list)]:8) != 0.
  The `bne` branch at 0x2d414 targets 0x2d450, is taken when v0(=ret(?)) != 0, and falls through when v0(=ret(?)) == 0.
  The `bne` branch at 0x2d420 targets 0x2d408, is taken when s0(?) != 0, and falls through when s0(?) == 0.
  The `beq` branch at 0x2d458 targets 0x2d438 and is always taken.
  The return at 0x2d448 has v0 = one of 0x0, ret(?).

- `klhwg_invent_alloc` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x321a8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x321a8-0x32228 (128 bytes).
  It occupies 128 bytes.
  2 such `ld` accesses load 8 bytes from abs 0xffffffffffffc400, including `ld` at 0x321d4, `ld` at 0x321f8.
  2 such `ld` accesses load 8 bytes from [-0x3c00]:8 +0x0, including `ld` at 0x321dc, `ld` at 0x321fc.
  2 such `ld` accesses load 8 bytes from ([[-0x3c00]:8]:8 + (a0 << 0x3)) +0x0, including `ld` at 0x321e8, `ld` at 0x32204.
  The `lh` at 0x321f0 loads 2 bytes from [([[-0x3c00]:8]:8 + (a0 << 0x3))]:8 +0x861a.
  The `sh` at 0x321f4 stores 2 bytes to ret(kern_malloc) +0x0.
  The `lbu` at 0x32210 loads 1 byte from [([[-0x3c00]:8]:8 + (a0 << 0x3))]:8 +0x8618.
  The `sw` at 0x32214 stores 4 bytes to ret(kern_malloc) +0x8.
  The `sh` at 0x3221c stores 2 bytes to ret(kern_malloc) +0x2.
  The `jal` at 0x321b8 calls kern_malloc with a0=a2 at entry (arg2), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `bne` branch at 0x321c4 targets 0x321d4, is taken when v0(=ret(kern_malloc)) != 0, and falls through when v0(=ret(kern_malloc)) == 0.
  The `beq` branch at 0x321cc targets 0x32220 and is always taken.
  The return at 0x32220 has v0 = one of 0x0, ret(kern_malloc).

- `klhwg_cpu_invent_info` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x32228 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x32228-0x3233c (276 bytes).
  It occupies 276 bytes.
  The `lbu` at 0x32260 loads 1 byte from a2 (arg2 at entry) +0x2.
  2 such `sb` accesses store 1 byte to ret(klhwg_invent_alloc) +0x4, including `sb` at 0x32274, `sb` at 0x32314.
  2 such `lhu` accesses load 2 bytes from a2 (arg2 at entry) +0x38, including `lhu` at 0x32278, `lhu` at 0x322c4.
  The `sw` at 0x3227c stores 4 bytes to ret(klhwg_invent_alloc) +0xc.
  2 such `lhu` accesses load 2 bytes from a2 (arg2 at entry) +0x3c, including `lhu` at 0x32280, `lhu` at 0x32318.
  The `sw` at 0x32284 stores 4 bytes to ret(klhwg_invent_alloc) +0x10.
  The `lhu` at 0x32288 loads 2 bytes from a2 (arg2 at entry) +0x40.
  The `sw` at 0x32290 stores 4 bytes to ret(klhwg_invent_alloc) +0x18.
  The `lhu` at 0x32294 loads 2 bytes from a2 (arg2 at entry) +0x3e.
  The `sw` at 0x32298 stores 4 bytes to ret(klhwg_invent_alloc) +0x14.
  2 such `lw` accesses load 4 bytes from a2 (arg2 at entry) +0x1c, including `lw` at 0x3229c, `lw` at 0x32328.
  The `sh` at 0x322a0 stores 2 bytes to ret(klhwg_invent_alloc) +0x1c.
  The `lwu` at 0x322a4 loads 4 bytes from a2 (arg2 at entry) +0x1c.
  The `ld` at 0x322b0 loads 8 bytes from (sym(pdaindr) + ([a2+28] << 0x4)) +0x8.
  The `lbu` at 0x322b4 loads 1 byte from [(sym(pdaindr) + ([a2+28] << 0x4))+8]:8 +0x528.
  The `sh` at 0x322b8 stores 2 bytes to ret(klhwg_invent_alloc) +0x1e.
  The `lhu` at 0x322bc loads 2 bytes from a2 (arg2 at entry) +0x3a.
  The `sh` at 0x322c0 stores 2 bytes to ret(klhwg_invent_alloc) +0x20.
  The `jal` at 0x3224c calls klhwg_invent_alloc with a0=a1 at entry (arg1), a1=0x1, a2=0x24, a3=a3 at entry (arg3).
  The `jal` at 0x322e0 calls hwgraph_info_add_LBL with a0=a0 at entry (arg0), a1=sym(.rodata)+51152, a2=ret(klhwg_invent_alloc), a3=?.
  The `jal` at 0x322f0 calls hwgraph_info_export_LBL with a0=a0 at entry (arg0), a1=sym(.rodata)+51152, a2=0x24, a3=?.
  The `jal` at 0x3232c calls cmn_err with a0=0x4, a1=sym(.rodata)+51152, a2=[a2+28], a3=a0 at entry (arg0), a4=[a2+56]:2, a5=([a2+28] << 0x4), a6=[a2+28], a7=[a2+62]:2.
  The `beq` branch at 0x32258 targets 0x322f8, is taken when v0(=ret(klhwg_invent_alloc)) == 0, and falls through when v0(=ret(klhwg_invent_alloc)) != 0.
  The `beq` branch at 0x3226c targets 0x32310, is taken when (at(=[a2+2]:1) & 0x1) == 0, and falls through when (at(=[a2+2]:1) & 0x1) != 0.
  The `beq` branch at 0x3228c targets 0x32318, is taken when v0(=[sym(.sdata)+404]) == 0, and falls through when v0(=[sym(.sdata)+404]) != 0.
  The `bne` branch at 0x322cc targets 0x32324, is taken when a4(=[a2+56]:2) < 0x926 (signed), and falls through when a4(=[a2+56]:2) >= 0x926 (signed).
  The `beq` branch at 0x32310 targets 0x32278 and is always taken.
  The `beq` branch at 0x3231c targets 0x32294 and is always taken.
  The `beq` branch at 0x32334 targets 0x322d8 and is always taken.
  The return at 0x32308 has v0 = one of ret(klhwg_invent_alloc), ret(hwgraph_info_export_LBL).

- `klhwg_disabled_cpu_invent_info` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x3233c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x3233c-0x32458 (284 bytes).
  It occupies 284 bytes.
  The `sb` at 0x3238c stores 1 byte to ret(klhwg_invent_alloc) +0x4.
  The `sh` at 0x32394 stores 2 bytes to ret(klhwg_invent_alloc) +0x2.
  2 such `lhu` accesses load 2 bytes from a2 (arg2 at entry) +0x38, including `lhu` at 0x32398, `lhu` at 0x323d0.
  The `sw` at 0x3239c stores 4 bytes to ret(klhwg_invent_alloc) +0xc.
  The `lhu` at 0x323a0 loads 2 bytes from a2 (arg2 at entry) +0x3c.
  The `sw` at 0x323a4 stores 4 bytes to ret(klhwg_invent_alloc) +0x10.
  The `lhu` at 0x323a8 loads 2 bytes from a2 (arg2 at entry) +0x40.
  The `sw` at 0x323ac stores 4 bytes to ret(klhwg_invent_alloc) +0x18.
  The `lhu` at 0x323b0 loads 2 bytes from a2 (arg2 at entry) +0x3e.
  The `sw` at 0x323b4 stores 4 bytes to ret(klhwg_invent_alloc) +0x14.
  2 such `lw` accesses load 4 bytes from a2 (arg2 at entry) +0x1c, including `lw` at 0x323b8, `lw` at 0x32444.
  The `sh` at 0x323bc stores 2 bytes to ret(klhwg_invent_alloc) +0x1c.
  The `lbu` at 0x323c0 loads 1 byte from a2 (arg2 at entry) +0x18.
  The `sh` at 0x323c4 stores 2 bytes to ret(klhwg_invent_alloc) +0x1e.
  The `lhu` at 0x323c8 loads 2 bytes from a2 (arg2 at entry) +0x3a.
  The `sh` at 0x323cc stores 2 bytes to ret(klhwg_invent_alloc) +0x20.
  The `jal` at 0x32364 calls klhwg_invent_alloc with a0=a1 at entry (arg1), a1=0x1, a2=0x24, a3=a3 at entry (arg3).
  The `jal` at 0x3237c calls klhwg_invent_alloc with a0=a1 at entry (arg1), a1=0x46, a2=0x5c, a3=?.
  The `jal` at 0x323ec calls hwgraph_info_add_LBL with a0=a0 at entry (arg0), a1=sym(.rodata)+51152, a2=ret(klhwg_invent_alloc), a3=?.
  The `jal` at 0x32400 calls hwgraph_info_export_LBL with a0=a0 at entry (arg0), a1=sym(.rodata)+51152, a2=0x24, a3=?.
  The `jal` at 0x32410 calls hwgraph_info_add_LBL with a0=a0 at entry (arg0), a1=sym(.rodata)+51152, a2=ret(klhwg_invent_alloc), a3=?.
  The `jal` at 0x32420 calls hwgraph_info_export_LBL with a0=a0 at entry (arg0), a1=sym(.rodata)+51152, a2=0x5c, a3=?.
  The `jal` at 0x32448 calls cmn_err with a0=0x4, a1=sym(.rodata)+51152, a2=[a2+28], a3=a0 at entry (arg0), a4=[a2+56]:2, a5=[a2+56]:2, a6=a3 at entry (arg3), a7=a2 at entry (arg2).
  The `beq` branch at 0x3236c targets 0x32428, is taken when v0(=ret(klhwg_invent_alloc)) == 0, and falls through when v0(=ret(klhwg_invent_alloc)) != 0.
  The `beq` branch at 0x32384 targets 0x32428, is taken when v0(=ret(klhwg_invent_alloc)) == 0, and falls through when v0(=ret(klhwg_invent_alloc)) != 0.
  The `bne` branch at 0x323d8 targets 0x3243c, is taken when a4(=[a2+56]:2) < 0x926 (signed), and falls through when a4(=[a2+56]:2) >= 0x926 (signed).
  The `beq` branch at 0x32450 targets 0x323e4 and is always taken.
  The return at 0x32434 has v0 = one of ret(klhwg_invent_alloc), ret(hwgraph_info_export_LBL).

- `klhwg_baseio_inventory_add` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x32458 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x32458-0x324e4 (140 bytes).
  It occupies 140 bytes.
  The `sw` at 0x3248c stores 4 bytes to ret(klhwg_invent_alloc) +0x14.
  The `sw` at 0x324a0 stores 4 bytes to ret(klhwg_invent_alloc) +0x10.
  The `sw` at 0x324b0 stores 4 bytes to ret(klhwg_invent_alloc) +0xc.
  The `jal` at 0x3247c calls klhwg_invent_alloc with a0=a1 at entry (arg1), a1=0x15, a2=0x20, a3=a3 at entry (arg3).
  The `jal` at 0x32490 calls nvram_prom_version_get with a0=sp-32, a1=sp-31, a2=?, a3=?.
  The `jal` at 0x324b4 calls hwgraph_info_add_LBL with a0=a0 at entry (arg0), a1=sym(.rodata)+51152, a2=ret(klhwg_invent_alloc), a3=?.
  The `jal` at 0x324cc calls hwgraph_info_export_LBL with a0=a0 at entry (arg0), a1=sym(.rodata)+51152, a2=0x20, a3=?.
  The return at 0x324dc has v0 = ret(hwgraph_info_export_LBL).

- `klhwg_hub_invent_info` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x324e4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x324e4-0x3257c (152 bytes).
  It occupies 152 bytes.
  The `lbu` at 0x32514 loads 1 byte from a2 (arg2 at entry) +0x2.
  The `sb` at 0x32524 stores 1 byte to ret(klhwg_invent_alloc) +0x4.
  The `sw` at 0x32530 stores 4 bytes to ret(klhwg_invent_alloc) +0x14.
  The `lbu` at 0x32534 loads 1 byte from a2 (arg2 at entry) +0x3.
  The `sw` at 0x32538 stores 4 bytes to ret(klhwg_invent_alloc) +0xc.
  The `ld` at 0x32540 loads 8 bytes from a2 (arg2 at entry) +0x58.
  The `sd` at 0x32548 stores 8 bytes to ret(klhwg_invent_alloc) +0x18.
  The `jal` at 0x32504 calls klhwg_invent_alloc with a0=a1 at entry (arg1), a1=0xe, a2=0x20, a3=a3 at entry (arg3).
  The `jal` at 0x3254c calls hwgraph_info_add_LBL with a0=a0 at entry (arg0), a1=sym(.rodata)+51152, a2=ret(klhwg_invent_alloc), a3=[a2+3]:1, a4=0x4.
  The `jal` at 0x32560 calls hwgraph_info_export_LBL with a0=a0 at entry (arg0), a1=sym(.rodata)+51152, a2=0x20, a3=?.
  The `beq` branch at 0x3250c targets 0x32568, is taken when v0(=ret(klhwg_invent_alloc)) == 0, and falls through when v0(=ret(klhwg_invent_alloc)) != 0.
  The `beq` branch at 0x3251c targets 0x3252c, is taken when (at(=[a2+2]:1) & 0x1) == 0, and falls through when (at(=[a2+2]:1) & 0x1) != 0.
  The return at 0x32574 has v0 = one of ret(klhwg_invent_alloc), ret(hwgraph_info_export_LBL).

- `klhwg_mem_invent_info` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x3257c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x3257c-0x327bc (576 bytes).
  It occupies 576 bytes.
  The `sh` at 0x325d4 stores 2 bytes to ret(klhwg_invent_alloc) +0x2.
  2 such `lbu` accesses load 1 byte from a2 (arg2 at entry) +0x2, including `lbu` at 0x325d8, `lbu` at 0x326dc.
  2 such `sb` accesses store 1 byte to ret(klhwg_invent_alloc) +0x4, including `sb` at 0x325e8, `sb` at 0x327a4.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0x32654, `lw` at 0x3272c.
  3 such `sw` accesses store 4 bytes to ?, including `sw` at 0x3265c, `sw` at 0x3268c, `sw` at 0x32738.
  2 such `lh` accesses load 2 bytes from ?, including `lh` at 0x32680, `lh` at 0x326a0.
  5 such `sh` accesses store 2 bytes to ?, including `sh` at 0x32688, `sh` at 0x32690, `sh` at 0x326c4.
  3 such `lbu` accesses load 1 byte from a2 (arg2 at entry) +0x1, including `lbu` at 0x32694, `lbu` at 0x326c8, `lbu` at 0x326f0.
  The `lh` at 0x32698 loads 2 bytes from a2 (arg2 at entry) +0x4c.
  The `lbu` at 0x3270c loads 1 byte from ?.
  The `sh` at 0x32748 stores 2 bytes to ret(klhwg_invent_alloc) +0xe.
  The `sh` at 0x32750 stores 2 bytes to ret(klhwg_invent_alloc) +0xc.
  The `jal` at 0x325ac calls klhwg_invent_alloc with a0=a1 at entry (arg1), a1=0x3, a2=0x50, a3=a3 at entry (arg3).
  The `jal` at 0x32600 calls ip27log_getenv with a0=a4 at entry (arg4), a1=sym(.rodata)+51152, a2=sp-144, a3=0x0, a4=0x0.
  The `jal` at 0x32624 calls ip27log_getenv with a0=a4 at entry (arg4), a1=sym(.rodata)+51152, a2=sp-128, a3=0x0, a4=0x0.
  The `jal` at 0x326fc calls strchr with a0=sp-144, a1=?, a2=?, a3=[a2+1]:1.
  The `jal` at 0x32754 calls hwgraph_info_add_LBL with a0=a0 at entry (arg0), a1=sym(.rodata)+51152, a2=ret(klhwg_invent_alloc), a3=?.
  The `jal` at 0x3276c calls hwgraph_info_export_LBL with a0=a0 at entry (arg0), a1=sym(.rodata)+51152, a2=0x50, a3=?.
  The `beq` branch at 0x325c8 targets 0x32774, is taken when v0(=ret(klhwg_invent_alloc)) == 0, and falls through when v0(=ret(klhwg_invent_alloc)) != 0.
  The `beq` branch at 0x325e0 targets 0x327a0, is taken when (at(=[a2+2]:1) & 0x1) == 0, and falls through when (at(=[a2+2]:1) & 0x1) != 0.
  The `bltz` branch at 0x32608 targets 0x3262c, is taken when v0(=ret(ip27log_getenv)) < 0 (signed), and falls through when v0(=ret(ip27log_getenv)) >= 0 (signed).
  The `beq` branch at 0x32640 targets 0x327a8 and is always taken.
  The `beq` branch at 0x3264c targets 0x32660, is taken when (a1(=[a2+2]:1) & 0x1) == 0, and falls through when (a1(=[a2+2]:1) & 0x1) != 0.
  The `beq` branch at 0x32674 targets 0x3273c, is taken when s0(?) >= 0x8 (signed), and falls through when s0(?) < 0x8 (signed).
  The `bne` branch at 0x326b4 targets 0x326e0, is taken when a3(=[a2+1]:1) < 0x2 (signed), and falls through when a3(=[a2+1]:1) >= 0x2 (signed).
  The `beq` branch at 0x326bc targets 0x326d0, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x326d0 targets 0x326f4, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `beq` branch at 0x326d8 targets 0x32648 and is always taken.
  The `beq` branch at 0x326e0 targets 0x326d0, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0x326ec targets 0x326cc and is always taken.
  The `bltz` branch at 0x326f4 targets 0x3272c, is taken when a7(?) < 0 (signed), and falls through when a7(?) >= 0 (signed).
  The `beq` branch at 0x32704 targets 0x3272c, is taken when v0(=ret(strchr)) == 0, and falls through when v0(=ret(strchr)) != 0.
  The `beq` branch at 0x32714 targets 0x32724, is taken when a3(=0x30) == a2(?), and falls through when a3(=0x30) != a2(?).
  The `beq` branch at 0x32724 targets 0x32660 and is always taken.
  The `beq` branch at 0x32734 targets 0x32660 and is always taken.
  The `beq` branch at 0x327a0 targets 0x325ec and is always taken.
  The `beq` branch at 0x327b4 targets 0x32680 and is always taken.
  The return at 0x32798 has v0 = one of ret(klhwg_invent_alloc), ret(hwgraph_info_export_LBL).

- `klhwg_add_hub` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x327bc (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x327bc-0x32890 (212 bytes).
  It occupies 212 bytes.
  2 such `ld` accesses load 8 bytes from abs 0xffffffffffffc400, including `ld` at 0x327f4, `ld` at 0x3283c.
  2 such `ld` accesses load 8 bytes from [-0x3c00]:8 +0x0, including `ld` at 0x327f8, `ld` at 0x32844.
  The `ld` at 0x3280c loads 8 bytes from ([[-0x3c00]:8]:8 + (a2 << 0x3)) +0x0.
  The `ld` at 0x32854 loads 8 bytes from ?.
  The `jal` at 0x327e0 calls hwgraph_path_add with a0=a0 at entry (arg0), a1=sym(.rodata)+51152, a2=sp-48, a3=a3 at entry (arg3).
  The `jal` at 0x327ec calls device_master_set with a0=?, a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0x32820 calls hwgraph_info_add_LBL with a0=?, a1=sym(.rodata)+51152, a2=[([[-0x3c00]:8]:8 + (a2 << 0x3))]:8+34760, a3=0x87c8.
  The `jal` at 0x32834 calls klhwg_hub_invent_info with a0=?, a1=a2 at entry (arg2), a2=a1 at entry (arg1), a3=?.
  The `jal` at 0x32850 calls init_hub_stats with a0=a2 at entry (arg2), a1=?, a2=?, a3=?.
  The `jal` at 0x3285c calls sndrv_attach with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x32880 calls cmn_err with a0=0x4, a1=sym(.rodata)+51152, a2=?, a3=ret(hwgraph_info_add_LBL).
  The `bne` branch at 0x32828 targets 0x32870, is taken when v0(=ret(hwgraph_info_add_LBL)) != 0, and falls through when v0(=ret(hwgraph_info_add_LBL)) == 0.
  The `beq` branch at 0x32888 targets 0x32830 and is always taken.
  The return at 0x32868 has v0 = ret(sndrv_attach).

- `klhwg_add_disabled_cpu` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x32890 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x32890-0x32930 (160 bytes).
  It occupies 160 bytes.
  The `lh` at 0x3289c loads 2 bytes from a2 (arg2 at entry) +0x1e.
  The `lbu` at 0x328c0 loads 1 byte from a2 (arg2 at entry) +0x18.
  The `jal` at 0x328d8 calls sprintf with a0=sp-176, a1=sym(.rodata)+51152, a2=sym(.rodata)+51152, a3=sym(.rodata)+51152, a4=[a2+24]:1+97.
  The `jal` at 0x328e8 calls hwgraph_path_add with a0=a0 at entry (arg0), a1=sp-176, a2=sp-56, a3=?.
  The `jal` at 0x328f4 calls mark_cpuvertex_as_cpu with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x32900 calls device_master_set with a0=?, a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0x32914 calls klhwg_disabled_cpu_invent_info with a0=?, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0x328b8 targets 0x3291c, is taken when at(=[a2+30]:2) == v0(=-0x1), and falls through when at(=[a2+30]:2) != v0(=-0x1).
  The return at 0x32928 has v0 = one of -0x1, ret(klhwg_disabled_cpu_invent_info).

- `klhwg_add_cpu` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x32930 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x32930-0x32af0 (448 bytes).
  It occupies 448 bytes.
  2 such `lh` accesses load 2 bytes from a2 (arg2 at entry) +0x1e, including `lh` at 0x32938, `lh` at 0x329a4.
  The `ld` at 0x32954 loads 8 bytes from (sym(pdaindr) + ([a2+30]:2 << 0x4)) +0x8.
  The `lbu` at 0x32968 loads 1 byte from [(sym(pdaindr) + ([a2+30]:2 << 0x4))+8]:8 +0x528.
  2 such `lwu` accesses load 4 bytes from a2 (arg2 at entry) +0x1c, including `lwu` at 0x329b0, `lwu` at 0x32a38.
  2 such `ld` accesses load 8 bytes from (sym(pdaindr) + ([a2+28] << 0x4)) +0x8, including `ld` at 0x329c0, `ld` at 0x32a44.
  The `ld` at 0x329d0 loads 8 bytes from [(sym(pdaindr) + ([a2+28] << 0x4))+8]:8 +0x740.
  The `sd` at 0x32a48 stores 8 bytes to [(sym(pdaindr) + ([a2+28] << 0x4))+8]:8 +0x698.
  2 such `lw` accesses load 4 bytes from a2 (arg2 at entry) +0x1c, including `lw` at 0x32a4c, `lw` at 0x32aec.
  2 such `ld` accesses load 8 bytes from table(sym(pdaindr)) +0x8, including `ld` at 0x32a5c, `ld` at 0x32a78.
  2 such `ld` accesses load 8 bytes from [table(sym(pdaindr))+8]:8 +0x698, including `ld` at 0x32a60, `ld` at 0x32a88.
  The `ld` at 0x32aa0 loads 8 bytes from ?.
  The `lbu` at 0x32aa8 loads 1 byte from ?.
  The `jal` at 0x3298c calls sprintf with a0=sp-176, a1=sym(.rodata)+51152, a2=sym(.rodata)+51152, a3=?.
  The `jal` at 0x3299c calls hwgraph_path_add with a0=a0 at entry (arg0), a1=sp-176, a2=sp-56, a3=?.
  The `jal` at 0x329a8 calls mark_cpuvertex_as_cpu with a0=?, a1=[a2+30]:2, a2=?, a3=?.
  The `jal` at 0x329cc calls hwgraph_info_add_LBL with a0=?, a1=sym(.rodata)+51152, a2=[[(sym(pdaindr) + ([a2+28] << 0x4))+8]:8+1856]:8, a3=?.
  The `jal` at 0x329d8 calls device_master_set with a0=?, a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0x329ec calls hwgraph_edge_get with a0=a0 at entry (arg0), a1=sym(.rodata)+51152, a2=sp-52, a3=?.
  The `jal` at 0x32a04 calls klhwg_cpu_invent_info with a0=?, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=?.
  The `jal` at 0x32a18 calls sprintf with a0=sp-176, a1=sym(.rodata)+51152, a2=?, a3=?.
  The `jal` at 0x32a20 calls strlen with a0=sp-176, a1=?, a2=?, a3=?.
  The `jal` at 0x32a30 calls kmem_alloc_node with a0=ret(strlen)+1, a1=0x101, a2=a1 at entry (arg1), a3=?.
  The `jal` at 0x32a84 calls strcpy with a0=[[table(sym(pdaindr))+8]:8+1688]:8, a1=sp-176, a2=[a2+28], a3=?.
  The `jal` at 0x32ab4 calls sprintf with a0=sp-176, a1=sym(.rodata)+51152, a2=?, a3=?.
  The `jal` at 0x32ac4 calls hwgraph_edge_add with a0=?, a1=?, a2=sp-176, a3=?.
  The `jal` at 0x32ae0 calls assfail with a0=sym(.rodata)+51152, a1=sym(.rodata)+51152, a2=0x222, a3=[[table(sym(pdaindr))+8]:8+1688]:8, a4=[(sym(pdaindr) + ([a2+28] << 0x4))+8]:8.
  The `beq` branch at 0x329f4 targets 0x32a9c, is taken when v0(=ret(hwgraph_edge_get)) == 0, and falls through when v0(=ret(hwgraph_edge_get)) != 0.
  The `beq` branch at 0x32a64 targets 0x32ad4, is taken when a3(=[[table(sym(pdaindr))+8]:8+1688]:8) == 0, and falls through when a3(=[[table(sym(pdaindr))+8]:8+1688]:8) != 0.
  The `beq` branch at 0x32acc targets 0x32a00 and is always taken.
  The `beq` branch at 0x32ae8 targets 0x32a6c and is always taken.
  The return at 0x32a94 has v0 = ret(strcpy).

- `klhwg_add_mem` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x32af0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x32af0-0x32b58 (104 bytes).
  It occupies 104 bytes.
  The `jal` at 0x32b14 calls hwgraph_path_add with a0=a0 at entry (arg0), a1=sym(.rodata)+51152, a2=sp-64, a3=a3 at entry (arg3).
  The `jal` at 0x32b30 calls device_master_set with a0=?, a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0x32b48 calls klhwg_mem_invent_info with a0=?, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0x32b1c targets 0x32b30, is taken when v0(=ret(hwgraph_path_add)) == 0, and falls through when v0(=ret(hwgraph_path_add)) != 0.
  The `beq` branch at 0x32b50 targets 0x32b28 and is always taken.
  The return at 0x32b28 has v0 = one of ret(hwgraph_path_add), ret(klhwg_mem_invent_info).

- `klhwg_add_xbow` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x32db4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x32db4-0x33068 (692 bytes).
  It occupies 692 bytes.
  The `lbu` at 0x32dbc loads 1 byte from a2 (arg2 at entry) +0x9.
  The `ld` at 0x32e2c loads 8 bytes from (a1 << 0x21) -0x6fffffffcc000000.
  The `lbu` at 0x32eb4 loads 1 byte from ?.
  3 such `lh` accesses load 2 bytes from ?, including `lh` at 0x32ec4, `lh` at 0x32ee0, `lh` at 0x32f48.
  4 such `ld` accesses load 8 bytes from abs 0xffffffffffffc400, including `ld` at 0x32f00, `ld` at 0x32f2c, `ld` at 0x32f44.
  4 such `ld` accesses load 8 bytes from [-0x3c00]:8 +0x0, including `ld` at 0x32f04, `ld` at 0x32f30, `ld` at 0x32f4c.
  3 such `ld` accesses load 8 bytes from ?, including `ld` at 0x32f10, `ld` at 0x32f38, `ld` at 0x32f58.
  The `sw` at 0x32f18 stores 4 bytes to table(0x85fc) +0x0.
  The `lw` at 0x32f1c loads 4 bytes from table(0x8c80) +0x0.
  2 such `sh` accesses store 2 bytes to table(0x8600) +0x0, including `sh` at 0x32f40, `sh` at 0x32f64.
  The `lh` at 0x32f74 loads 2 bytes from (sym(nasid_to_compact_node) + (a1 + a1)) +0x0.
  The `ld` at 0x32f84 loads 8 bytes from ([[-0x3c00]:8]:8 + ([(sym(nasid_to_compact_node) + (a1 + a1))]:2 << 0x3)) +0x0.
  The `lw` at 0x32f90 loads 4 bytes from [([[-0x3c00]:8]:8 + ([(sym(nasid_to_compact_node) + (a1 + a1))]:2 << 0x3))]:8 +0x8c80.
  The `jal` at 0x32e00 calls find_component with a0=a2 at entry (arg2), a1=0x0, a2=0x4, a3=a3 at entry (arg3).
  The `jal` at 0x32e10 calls hwgraph_vertex_create with a0=sp-80, a1=?, a2=?, a3=?.
  The `jal` at 0x32e18 calls xswitch_vertex_init with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x32e54 calls iobrick_module_get_nasid with a0=a1 at entry (arg1), a1=0x8, a2=sym(nasid_to_compact_node), a3=(sym(nasid_to_compact_node) + (a1 + a1)).
  The `jal` at 0x32e70 calls iobrick_register with a0=?, a1=?, a2=-0x1, a3=?.
  The `jal` at 0x32e8c calls hwgraph_edge_add with a0=entry(0x8c80), a1=?, a2=sym(.rodata)+51152, a3=?, a7=entry(0x8c80).
  The `jal` at 0x32ee4 calls is_specified with a0=sym(arg_maxnodes), a1=sym(.rodata)+51152, a2=?, a3=-0x1.
  The `jal` at 0x32f9c calls hwgraph_edge_add with a0=[[([[-0x3c00]:8]:8 + ([(sym(nasid_to_compact_node) + (a1 + a1))]:2 << 0x3))]:8+35968], a1=?, a2=sym(.rodata)+51152, a3=(sym(nasid_to_compact_node) + (a1 + a1)).
  The `jal` at 0x32fac calls elsc_module_get_nasid with a0=a1 at entry (arg1), a1=?, a2=?, a3=?.
  The `jal` at 0x32fc8 calls iobrick_register with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x32fdc calls cmn_err with a0=0x4, a1=sym(.rodata)+51152, a2=?, a3=-0x1.
  The `jal` at 0x33000 calls cmn_err with a0=0x4, a1=sym(.rodata)+51152, a2=0x1, a3=?.
  The `jal` at 0x33024 calls cmn_err with a0=one of 0x0, 0x4, a1=sym(.rodata)+51152, a2=?, a3=?, a6=ret(hwgraph_edge_add).
  The `jal` at 0x3304c calls cmn_err with a0=0x4, a1=sym(.rodata)+51152, a2=[[([[-0x3c00]:8]:8 + ([(sym(nasid_to_compact_node) + (a1 + a1))]:2 << 0x3))]:8+35968], a3=[[([[-0x3c00]:8]:8 + ([(sym(nasid_to_compact_node) + (a1 + a1))]:2 << 0x3))]:8+35968], a6=ret(hwgraph_edge_add).
  The `beq` branch at 0x32dd8 targets 0x32dfc, is taken when (at(=[a2+9]:1) & 0x4) == 0, and falls through when (at(=[a2+9]:1) & 0x4) != 0.
  The `beq` branch at 0x32e08 targets 0x32de0, is taken when v0(=ret(find_component)) == 0, and falls through when v0(=ret(find_component)) != 0.
  The `beq` branch at 0x32e48 targets 0x32f70, is taken when a0(?) == a1(=0xc000), and falls through when a0(?) != a1(=0xc000).
  The `beq` branch at 0x32e68 targets 0x32e78, is taken when a0(?) == a2(=-0x1), and falls through when a0(?) != a2(=-0x1).
  The `beq` branch at 0x32e78 targets 0x3305c and is always taken.
  The `bne` branch at 0x32e94 targets 0x32fec, is taken when v0(=ret(hwgraph_edge_add)) != 0, and falls through when v0(=ret(hwgraph_edge_add)) == 0.
  The `beq` branch at 0x32ea4 targets 0x32f68, is taken when s1(?) >= 0x10 (signed), and falls through when s1(?) < 0x10 (signed).
  The `beq` branch at 0x32ebc targets 0x32e9c, is taken when (a4(?) & 0x2) == 0, and falls through when (a4(?) & 0x2) != 0.
  The `beq` branch at 0x32ec8 targets 0x32fd8, is taken when s2(?) == a3(=-0x1), and falls through when s2(?) != a3(=-0x1).
  The `beq` branch at 0x32ef0 targets 0x32efc, is taken when v0(=ret(is_specified)) == 0, and falls through when v0(=ret(is_specified)) != 0.
  The `beq` branch at 0x32ef8 targets 0x32e9c, is taken when a1(?) == a6(=-0x1), and falls through when a1(?) != a6(=-0x1).
  The `beq` branch at 0x32f20 targets 0x32e80, is taken when s0(=a1) == s2(?), and falls through when s0(=a1) != s2(?).
  The `beq` branch at 0x32f60 targets 0x32e80 and is always taken.
  The `beq` branch at 0x32f68 targets 0x32de4 and is always taken.
  The `bne` branch at 0x32fa4 targets 0x33034, is taken when v0(=ret(hwgraph_edge_add)) != 0, and falls through when v0(=ret(hwgraph_edge_add)) == 0.
  The `beq` branch at 0x32fc0 targets 0x32de4, is taken when a0(?) == t9(=-0x1), and falls through when a0(?) != t9(=-0x1).
  The `beq` branch at 0x32fd0 targets 0x32de4 and is always taken.
  The `beq` branch at 0x32fe4 targets 0x32ea0 and is always taken.
  The `bne` branch at 0x32ff0 targets 0x3300c, is taken when v0(=ret(hwgraph_edge_add)) != a2(=0x1), and falls through when v0(=ret(hwgraph_edge_add)) == a2(=0x1).
  The `beq` branch at 0x3302c targets 0x32ea0 and is always taken.
  The `beq` branch at 0x33054 targets 0x32fac and is always taken.
  The `beq` branch at 0x33060 targets 0x32eb0 and is always taken.
  The return at 0x32df4 has v0 = one of ?, ret(elsc_module_get_nasid), ret(iobrick_register).

- `klhwg_add_node` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x330e8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x330e8-0x33634 (1356 bytes).
  It occupies 1356 bytes.
  The `lh` at 0x3310c loads 2 bytes from (sym(compact_to_nasid_node) + (a1 + a1)) +0x0.
  The `ld` at 0x33124 loads 8 bytes from ([(sym(compact_to_nasid_node) + (a1 + a1))]:2 << 0x21) -0x6fffffffcc000000.
  The `ld` at 0x33168 loads 8 bytes from (([(sym(compact_to_nasid_node) + (a1 + a1))]:2 << 0x21)+0x9600000000000000 | 0x2000) +0x48.
  The `lw` at 0x33174 loads 4 bytes from ?.
  3 such `lw` accesses load 4 bytes from ret(find_lboard) +0x0, including `lw` at 0x3319c, `lw` at 0x333c0, `lw` at 0x334dc.
  The `lh` at 0x33230 loads 2 bytes from ret(find_component) +0x3a.
  The `lh` at 0x33254 loads 2 bytes from (sym(nasid_to_compact_node) + ([ret(find_component)+58]:2 + [ret(find_component)+58]:2)) +0x0.
  2 such `lbu` accesses load 1 byte from ret(find_first_component) +0x2, including `lbu` at 0x3326c, `lbu` at 0x33474.
  7 such `ld` accesses load 8 bytes from abs 0xffffffffffffc400, including `ld` at 0x332c4, `ld` at 0x332e0, `ld` at 0x33308.
  7 such `ld` accesses load 8 bytes from [-0x3c00]:8 +0x0, including `ld` at 0x332c8, `ld` at 0x332e4, `ld` at 0x3330c.
  9 such `ld` accesses load 8 bytes from ?, including `ld` at 0x332d4, `ld` at 0x332ec, `ld` at 0x332f4.
  The `sd` at 0x332dc stores 8 bytes to ?.
  3 such `lbu` accesses load 1 byte from ret(find_lboard) +0xa, including `lbu` at 0x33340, `lbu` at 0x3339c, `lbu` at 0x334b8.
  The `sb` at 0x33348 stores 1 byte to ?.
  2 such `lh` accesses load 2 bytes from ret(find_lboard) +0xe, including `lh` at 0x3335c, `lh` at 0x33590.
  The `sh` at 0x33368 stores 2 bytes to ?.
  The `lbu` at 0x3338c loads 1 byte from ?.
  The `sb` at 0x33418 stores 1 byte to ret(strrchr) +0x0.
  The `lbu` at 0x3349c loads 1 byte from ret(find_component) +0x2.
  The `sd` at 0x335ac stores 8 bytes to table(0x8620) +0x0.
  The `ld` at 0x33608 loads 8 bytes from table(0x8c70) +0x0.
  The `jal` at 0x33188 calls find_lboard with a0=?, a1=0x11, a2=?, a3=?.
  The `jal` at 0x331bc calls find_lboard with a0=?, a1=0x11, a2=[sym(.sdata)+408], a3=?.
  The `jal` at 0x331d0 calls board_to_path with a0=ret(find_lboard), a1=sp-336, a2=?, a3=?.
  The `jal` at 0x331e0 calls hwgraph_path_add with a0=a0 at entry (arg0), a1=sp-336, a2=sp-232, a3=?.
  The `jal` at 0x331f4 calls find_component with a0=ret(find_lboard), a1=0x0, a2=0x26, a3=?.
  The `jal` at 0x33228 calls init_pebrick with a0=ret(find_lboard), a1=ret(find_component), a2=?, a3=?.
  The `jal` at 0x33250 calls eeprom_vertex_info_set with a0=0x420, a1=[ret(find_component)+58]:2, a2=?, a3=0x0, a4=0x0.
  The `jal` at 0x33264 calls find_first_component with a0=ret(find_lboard), a1=0x2, a2=?, a3=?.
  The `jal` at 0x33294 calls mark_nodevertex_as_node with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x332a4 calls dev_to_name with a0=?, a1=sp-336, a2=0x64, a3=?.
  The `jal` at 0x332b0 calls strlen with a0=ret(dev_to_name), a1=?, a2=?, a3=?.
  The `jal` at 0x332bc calls kmem_alloc with a0=ret(strlen)+1, a1=0x1, a2=?, a3=?.
  The `jal` at 0x33300 calls strcpy with a0=?, a1=ret(dev_to_name), a2=?, a3=?.
  The `jal` at 0x33328 calls hwgraph_info_add_LBL with a0=?, a1=sym(.rodata)+51152, a2=?, a3=?.
  The `jal` at 0x33374 calls find_first_component with a0=ret(find_lboard), a1=0x3, a2=?, a3=?.
  The `jal` at 0x33398 calls klhwg_add_mem with a0=?, a1=?, a2=ret(find_first_component), a3=[ret(find_lboard)+10]:1.
  The `jal` at 0x333a8 calls find_first_component with a0=ret(find_lboard), a1=0x1, a2=?, a3=?.
  The `jal` at 0x333e0 calls find_lboard with a0=?, a1=0x11, a2=?, a3=?.
  The `jal` at 0x333f4 calls board_to_full_path with a0=ret(find_lboard), a1=sp-224, a2=[sym(.sdata)+408], a3=?.
  The `jal` at 0x33400 calls strrchr with a0=sp-224, a1=0x2f, a2=?, a3=?.
  The `jal` at 0x33414 calls hwgraph_link_add with a0=sp-336, a1=sp-224, a2=ret(strrchr)+1, a3=?.
  The `jal` at 0x33460 calls hwgraph_path_add with a0=?, a1=sym(.rodata)+51152, a2=sp-108, a3=?.
  The `jal` at 0x3347c calls klhwg_add_cpu with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x3348c calls find_component with a0=ret(find_lboard), a1=?, a2=0x1, a3=?.
  The `jal` at 0x334b4 calls klhwg_add_disabled_cpu with a0=?, a1=?, a2=?, a3=[ret(find_lboard)+10]:1.
  The `jal` at 0x334d0 calls klhwg_add_hub with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x334ec calls hwgraph_path_add with a0=?, a1=sym(.rodata)+51152, a2=sp-120, a3=?.
  The `jal` at 0x33510 calls eeprom_vertex_info_set with a0=?, a1=?, a2=?, a3=0x0, a4=0x0.
  The `jal` at 0x33528 calls cnode_subnode_to_cpu with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x33544 calls sprintf with a0=sp-116, a1=sym(.rodata)+51152, a2=?, a3=-0x1.
  The `jal` at 0x33554 calls hwgraph_path_add with a0=?, a1=sp-116, a2=sp-112, a3=?.
  The `jal` at 0x33560 calls mark_subnodevertex_as_subnode with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x3356c calls pimm_bearing_node [0x33068] with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x3358c calls module_lookup with a0=[ret(find_lboard)+14]:2, a1=?, a2=?, a3=[ret(find_lboard)+14]:2, a5=[ret(find_lboard)+10]:1.
  The `jal` at 0x335b0 calls chk_for_pebrick with a0=[(sym(compact_to_nasid_node) + (a1 + a1))]:2, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x335cc calls cmn_err with a0=0x0, a1=sym(.rodata)+51152, a2=sp-336, a3=?.
  The `jal` at 0x335e8 calls assfail with a0=sym(.rodata)+51152, a1=sym(.rodata)+51152, a2=0x415, a3=?.
  The `jal` at 0x33610 calls cmn_err with a0=0x0, a1=sym(.rodata)+51152, a2=?, a3=?.
  The `jal` at 0x33624 calls cmn_err with a0=0x0, a1=sym(.rodata)+51152, a2=?, a3=?.
  The `beq` branch at 0x33154 targets 0x335b0, is taken when at(?) == v1(=0xc000), and falls through when at(?) != v1(=0xc000).
  The `beq` branch at 0x3317c targets 0x33188, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0x33194 targets 0x331cc and is always taken.
  The `beq` branch at 0x331a0 targets 0x33424, is taken when v0(=[ret(find_lboard)]) == 0, and falls through when v0(=[ret(find_lboard)]) != 0.
  The `beq` branch at 0x331c8 targets 0x33424, is taken when s0(=ret(find_lboard)) == 0, and falls through when s0(=ret(find_lboard)) != 0.
  The `bne` branch at 0x331e8 targets 0x335c0, is taken when v0(=ret(hwgraph_path_add)) != 0, and falls through when v0(=ret(hwgraph_path_add)) == 0.
  The `beq` branch at 0x33200 targets 0x333f0, is taken when v0(=ret(find_component)) == 0, and falls through when v0(=ret(find_component)) != 0.
  The `bne` branch at 0x33214 targets 0x3319c, is taken when a3(=[sym(num_pebricks)]) < a1(=[sym(.sdata)+408]+1) (signed), and falls through when a3(=[sym(num_pebricks)]) >= a1(=[sym(.sdata)+408]+1) (signed).
  The `bne` branch at 0x33274 targets 0x3328c, is taken when (t8(=[ret(find_first_component)+2]:1) & 0x1) != 0, and falls through when (t8(=[ret(find_first_component)+2]:1) & 0x1) == 0.
  The `bne` branch at 0x3327c targets 0x33290, is taken when s6(=one of 0x0, 0x1) != 0, and falls through when s6(=one of 0x0, 0x1) == 0.
  The `beq` branch at 0x33284 targets 0x33370 and is always taken.
  The `beq` branch at 0x332f8 targets 0x335dc, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x33364 targets 0x3358c, is taken when s6(=one of 0x0, 0x1) == 0, and falls through when s6(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x33380 targets 0x33390, is taken when s7(=one of 0x0, 0x1) == 0, and falls through when s7(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x333a0 targets 0x334e0, is taken when s6(=one of 0x0, 0x1) == 0, and falls through when s6(=one of 0x0, 0x1) != 0.
  The `bne` branch at 0x333b0 targets 0x33454, is taken when v0(=ret(find_first_component)) != 0, and falls through when v0(=ret(find_first_component)) == 0.
  The `beq` branch at 0x333b8 targets 0x334c4, is taken when s7(=one of 0x0, 0x1) == 0, and falls through when s7(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x333c4 targets 0x33424, is taken when v0(=[ret(find_lboard)]) == 0, and falls through when v0(=[ret(find_lboard)]) != 0.
  The `beq` branch at 0x333e8 targets 0x331c8 and is always taken.
  The `beq` branch at 0x3341c targets 0x33260 and is always taken.
  The `bne` branch at 0x33468 targets 0x3360c, is taken when v0(=ret(hwgraph_path_add)) != 0, and falls through when v0(=ret(hwgraph_path_add)) == 0.
  The `beq` branch at 0x33470 targets 0x334a0 and is always taken.
  The `beq` branch at 0x33494 targets 0x333b8, is taken when v0(=ret(find_component)) == 0, and falls through when v0(=ret(find_component)) != 0.
  The `bne` branch at 0x334a4 targets 0x33478, is taken when (a2(?) & 0x1) != 0, and falls through when (a2(?) & 0x1) == 0.
  The `beq` branch at 0x334bc targets 0x33484 and is always taken.
  The `bne` branch at 0x334c4 targets 0x333c0, is taken when s6(=one of 0x0, 0x1) != 0, and falls through when s6(=one of 0x0, 0x1) == 0.
  The `beq` branch at 0x334d8 targets 0x333c4 and is always taken.
  The `bne` branch at 0x334f4 targets 0x33620, is taken when v0(=ret(hwgraph_path_add)) != 0, and falls through when v0(=ret(hwgraph_path_add)) == 0.
  The `beq` branch at 0x334fc targets 0x33524 and is always taken.
  The `beq` branch at 0x33520 targets 0x33584, is taken when s1(?) >= 0x2 (signed), and falls through when s1(?) < 0x2 (signed).
  The `beq` branch at 0x33534 targets 0x33518, is taken when v0(=ret(cnode_subnode_to_cpu)) == a3(=-0x1), and falls through when v0(=ret(cnode_subnode_to_cpu)) != a3(=-0x1).
  The `bne` branch at 0x33574 targets 0x33504, is taken when v0(=ret(pimm_bearing_node)) != 0, and falls through when v0(=ret(pimm_bearing_node)) == 0.
  The `beq` branch at 0x3357c targets 0x3351c and is always taken.
  The `beq` branch at 0x33584 targets 0x333a8 and is always taken.
  The `beq` branch at 0x335a8 targets 0x3336c and is always taken.
  The `beq` branch at 0x335b8 targets 0x33188 and is always taken.
  The `beq` branch at 0x335d4 targets 0x331f0 and is always taken.
  The `beq` branch at 0x33604 targets 0x33300 and is always taken.
  The `beq` branch at 0x33618 targets 0x33470 and is always taken.
  The `beq` branch at 0x3362c targets 0x334fc and is always taken.
  The return at 0x3344c has v0 = one of [ret(find_lboard)], ret(find_lboard).

- `klhwg_add_all_xbows` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x33634 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x33634-0x3374c (280 bytes).
  It occupies 280 bytes.
  The `lh` at 0x33640 loads 2 bytes from (sym(compact_to_nasid_node) + (a0 + a0)) +0x0.
  The `ld` at 0x33664 loads 8 bytes from ([(sym(compact_to_nasid_node) + (a0 + a0))]:2 << 0x21) -0x6fffffffcc000000.
  The `ld` at 0x33698 loads 8 bytes from (([(sym(compact_to_nasid_node) + (a0 + a0))]:2 << 0x21)+0x9600000000000000 | 0x2000) +0x48.
  The `lw` at 0x336a4 loads 4 bytes from ?.
  2 such `lw` accesses load 4 bytes from ret(find_lboard) +0x0, including `lw` at 0x336c8, `lw` at 0x3371c.
  The `lh` at 0x3370c loads 2 bytes from ret(find_lboard) +0x20.
  The `jal` at 0x336b8 calls find_lboard with a0=?, a1=0x11, a2=?, a3=?.
  The `jal` at 0x336e8 calls find_lboard with a0=?, a1=0x11, a2=?, a3=?.
  The `jal` at 0x336fc calls find_lboard with a0=ret(find_lboard), a1=0x42, a2=?, a3=?.
  The `jal` at 0x33710 calls klhwg_add_xbow with a0=a0 at entry (arg0), a1=[ret(find_lboard)+32]:2, a2=ret(find_lboard), a3=?.
  The `jal` at 0x3373c calls chk_for_pebrick with a0=[(sym(compact_to_nasid_node) + (a0 + a0))]:2, a1=a1 at entry (arg1), a2=[(sym(compact_to_nasid_node) + (a0 + a0))]:2, a3=([(sym(compact_to_nasid_node) + (a0 + a0))]:2 << 0x21)+0x9600000000000000, a4=(([(sym(compact_to_nasid_node) + (a0 + a0))]:2 << 0x21)+0x9600000000000000 | 0x2000).
  The `beq` branch at 0x3368c targets 0x3373c, is taken when t8(?) == t9(=0xc000), and falls through when t8(?) != t9(=0xc000).
  The `beq` branch at 0x336ac targets 0x336b8, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0x336c0 targets 0x336f8 and is always taken.
  The `beq` branch at 0x336cc targets 0x33720, is taken when v0(=[ret(find_lboard)]) == 0, and falls through when v0(=[ret(find_lboard)]) != 0.
  The `beq` branch at 0x336f0 targets 0x33720, is taken when v0(=ret(find_lboard)) == 0, and falls through when v0(=ret(find_lboard)) != 0.
  The `beq` branch at 0x33704 targets 0x336c8, is taken when v0(=ret(find_lboard)) == 0, and falls through when v0(=ret(find_lboard)) != 0.
  The `beq` branch at 0x33718 targets 0x336cc and is always taken.
  The `beq` branch at 0x33744 targets 0x336b8 and is always taken.
  The return at 0x33734 has v0 = one of [ret(find_lboard)], ret(find_lboard).

- `klhwg_add_all_routers` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x3374c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x3374c-0x33914 (456 bytes).
  It occupies 456 bytes.
  The `lh` at 0x337c4 loads 2 bytes from ?.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0x337d0, `ld` at 0x337e4.
  The `lw` at 0x337f0 loads 4 bytes from ?.
  2 such `lbu` accesses load 1 byte from ret(find_lboard_class) +0x9, including `lbu` at 0x3381c, `lbu` at 0x33834.
  2 such `lw` accesses load 4 bytes from ret(find_lboard_class) +0x0, including `lw` at 0x33850, `lw` at 0x33890.
  The `lh` at 0x33910 loads 2 bytes from sym(compact_to_nasid_node) +0x0.
  The `jal` at 0x33808 calls find_lboard_class with a0=?, a1=0x31, a2=?, a3=?.
  The `jal` at 0x33824 calls find_lboard_class with a0=?, a1=0x31, a2=?, a3=?.
  The `jal` at 0x3386c calls board_to_path with a0=ret(find_lboard_class), a1=sp-192, a2=?, a3=?.
  The `jal` at 0x3387c calls hwgraph_path_add with a0=a0 at entry (arg0), a1=sp-192, a2=sp-88, a3=?.
  The `jal` at 0x338b0 calls chk_for_pebrick with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x338f4 calls cmn_err with a0=0x0, a1=sym(.rodata)+51152, a2=sp-192, a3=?.
  The `blez` branch at 0x33784 targets 0x338c0, is taken when at(=[sym(maxnodes)]) <= 0 (signed), and falls through when at(=[sym(maxnodes)]) > 0 (signed).
  The `beq` branch at 0x3379c targets 0x33904 and is always taken.
  The `beq` branch at 0x337bc targets 0x338c0, is taken when s3(?) >= t8(=[sym(maxnodes)]) (signed), and falls through when s3(?) < t8(=[sym(maxnodes)]) (signed).
  The `beq` branch at 0x337dc targets 0x338b0, is taken when s5(=0xc000) == t8(?), and falls through when s5(=0xc000) != t8(?).
  The `beq` branch at 0x337fc targets 0x33808, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `beq` branch at 0x33810 targets 0x337a4, is taken when v0(=ret(find_lboard_class)) == 0, and falls through when v0(=ret(find_lboard_class)) != 0.
  The `beq` branch at 0x33818 targets 0x33838 and is always taken.
  The `beq` branch at 0x3382c targets 0x337a4, is taken when v0(=ret(find_lboard_class)) == 0, and falls through when v0(=ret(find_lboard_class)) != 0.
  The `beq` branch at 0x33848 targets 0x33868, is taken when (a7(=[ret(find_lboard_class)+9]:1) & 0x4) == 0, and falls through when (a7(=[ret(find_lboard_class)+9]:1) & 0x4) != 0.
  The `bne` branch at 0x33858 targets 0x33820, is taken when a6(=[ret(find_lboard_class)]) != 0, and falls through when a6(=[ret(find_lboard_class)]) == 0.
  The `beq` branch at 0x33860 targets 0x33824 and is always taken.
  The `bne` branch at 0x33884 targets 0x338ec, is taken when v0(=ret(hwgraph_path_add)) != 0, and falls through when v0(=ret(hwgraph_path_add)) == 0.
  The `beq` branch at 0x338a8 targets 0x33824 and is always taken.
  The `beq` branch at 0x338b8 targets 0x33808 and is always taken.
  The `beq` branch at 0x338fc targets 0x33890 and is always taken.
  The `beq` branch at 0x3390c targets 0x337c8 and is always taken.
  The return at 0x338e4 has v0 = one of ?, ret(find_lboard_class).

- `klhwg_connect_one_router` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x33914 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x33914-0x33ba0 (652 bytes).
  It occupies 652 bytes.
  The `lbu` at 0x33930 loads 1 byte from a1 (arg1 at entry) +0x9.
  2 such `lbu` accesses load 1 byte from a1 (arg1 at entry) +0x17, including `lbu` at 0x339c0, `lbu` at 0x33b78.
  The `lh` at 0x339d4 loads 2 bytes from a1 (arg1 at entry) +0xe.
  The `lw` at 0x339e4 loads 4 bytes from a1 (arg1 at entry) +0x24.
  3 such `lh` accesses load 2 bytes from ?, including `lh` at 0x33a30, `lh` at 0x33a48, `lh` at 0x33a58.
  The `lw` at 0x33a64 loads 4 bytes from ?.
  The `lbu` at 0x33aac loads 1 byte from ?.
  The `lh` at 0x33b9c loads 2 bytes from table(0x50) +0x0.
  The `jal` at 0x33988 calls board_to_path with a0=a1 at entry (arg1), a1=sp-208, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x33998 calls hwgraph_traverse with a0=a0 at entry (arg0), a1=sp-208, a2=sp-152, a3=?.
  The `jal` at 0x339a8 calls is_specified with a0=sym(arg_maxnodes), a1=?, a2=?, a3=?.
  The `jal` at 0x339d0 calls rbrick_register with a0=[a1+14]:2, a1=?, a2=[a1+23]:1, a3=?.
  The `jal` at 0x33a3c calls is_specified with a0=sym(arg_maxnodes), a1=?, a2=?, a3=?.
  The `jal` at 0x33a7c calls board_to_path with a0=?, a1=sp-144, a2=?, a3=?.
  The `jal` at 0x33a8c calls hwgraph_traverse with a0=a0 at entry (arg0), a1=sp-144, a2=sp-88, a3=?.
  The `jal` at 0x33a9c calls is_specified with a0=sym(arg_maxnodes), a1=sym(.rodata)+51152, a2=?, a3=?.
  The `jal` at 0x33ad0 calls sprintf with a0=sp-144, a1=sym(.rodata)+51152, a2=?, a3=?.
  The `jal` at 0x33ae0 calls hwgraph_edge_add with a0=?, a1=?, a2=sp-144, a3=?.
  The `jal` at 0x33afc calls is_specified with a0=sym(arg_maxnodes), a1=?, a2=0x1, a3=?.
  The `jal` at 0x33b24 calls cmn_err with a0=0x0, a1=sym(.rodata)+51152, a2=sp-144, a3=?.
  The `jal` at 0x33b50 calls cmn_err with a0=0x0, a1=sym(.rodata)+51152, a2=sp-208, a3=sp-144, a5=ret(hwgraph_edge_add).
  The `jal` at 0x33b6c calls cmn_err with a0=0x4, a1=sym(.rodata)+51152, a2=sp-208, a3=?.
  The `jal` at 0x33b80 calls cmn_err with a0=0x0, a1=sym(.rodata)+51152, a2=[a1+23]:1, a3=?.
  The `beq` branch at 0x3394c targets 0x33984, is taken when (at(=[a1+9]:1) & 0x4) == 0, and falls through when (at(=[a1+9]:1) & 0x4) != 0.
  The `beq` branch at 0x339a0 targets 0x339b8, is taken when v0(=ret(hwgraph_traverse)) == 0, and falls through when v0(=ret(hwgraph_traverse)) != 0.
  The `bne` branch at 0x339b0 targets 0x33958, is taken when v0(=ret(is_specified)) != 0, and falls through when v0(=ret(is_specified)) == 0.
  The `bne` branch at 0x339b8 targets 0x33b60, is taken when s0(=ret(hwgraph_traverse)) != 0, and falls through when s0(=ret(hwgraph_traverse)) == 0.
  The `bne` branch at 0x339c8 targets 0x33b7c, is taken when v0(=0x1) != a2(=[a1+23]:1), and falls through when v0(=0x1) == a2(=[a1+23]:1).
  The `beq` branch at 0x33a08 targets 0x33b90 and is always taken.
  The `bne` branch at 0x33a14 targets 0x33b1c, is taken when v0(=one of 0x0, 0x1) < 0x1 (unsigned), and falls through when v0(=one of 0x0, 0x1) >= 0x1 (unsigned).
  The `beq` branch at 0x33a28 targets 0x33b14, is taken when s0(?) >= 0x9 (signed), and falls through when s0(?) < 0x9 (signed).
  The `beq` branch at 0x33a34 targets 0x33a1c, is taken when ra(?) == s2(=-0x1), and falls through when ra(?) != s2(=-0x1).
  The `beq` branch at 0x33a44 targets 0x33a64, is taken when v0(=ret(is_specified)) == 0, and falls through when v0(=ret(is_specified)) != 0.
  The `beq` branch at 0x33a5c targets 0x33a1c, is taken when t8(?) == s2(=-0x1), and falls through when t8(?) != s2(=-0x1).
  The `beq` branch at 0x33a94 targets 0x33ac8, is taken when v0(=ret(hwgraph_traverse)) == 0, and falls through when v0(=ret(hwgraph_traverse)) != 0.
  The `beq` branch at 0x33aa4 targets 0x33abc, is taken when v0(=ret(is_specified)) == 0, and falls through when v0(=ret(is_specified)) != 0.
  The `bne` branch at 0x33ab4 targets 0x33a10, is taken when (t9(?) & 0x4) != 0, and falls through when (t9(?) & 0x4) == 0.
  The `beq` branch at 0x33abc targets 0x33a10 and is always taken.
  The `beq` branch at 0x33aec targets 0x33a1c, is taken when v0(=ret(hwgraph_edge_add)) == a2(=0x1), and falls through when v0(=ret(hwgraph_edge_add)) != a2(=0x1).
  The `beq` branch at 0x33af4 targets 0x33a1c, is taken when v0(=ret(hwgraph_edge_add)) == 0, and falls through when v0(=ret(hwgraph_edge_add)) != 0.
  The `bnel` branch at 0x33b04 targets 0x33a20, is taken when v0(=ret(is_specified)) != 0, and falls through when v0(=ret(is_specified)) == 0; its branch-likely delay slot `addiu s0,s0,1` at 0x33b08 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x33b0c targets 0x33b3c and is always taken.
  The `beq` branch at 0x33b14 targets 0x33958 and is always taken.
  The `beq` branch at 0x33b2c targets 0x33a1c, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `beq` branch at 0x33b34 targets 0x33ac8 and is always taken.
  The `beq` branch at 0x33b58 targets 0x33a20 and is always taken.
  The `beq` branch at 0x33b74 targets 0x339c4 and is always taken.
  The `beq` branch at 0x33b88 targets 0x33958 and is always taken.
  The `beq` branch at 0x33b98 targets 0x33a34 and is always taken.
  The return at 0x3397c has v0 = one of ?, ret(is_specified), ret(cmn_err).
  The instructions from 0x33ac4 to 0x33ac4 are not reached by any path from the entry, and their branches are not listed.

- `klhwg_connect_routers` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x33ba0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x33ba0-0x33d18 (376 bytes).
  It occupies 376 bytes.
  2 such `lh` accesses load 2 bytes from ?, including `lh` at 0x33c1c, `lh` at 0x33ca0.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0x33c28, `ld` at 0x33c3c.
  The `lw` at 0x33c48 loads 4 bytes from ?.
  The `lw` at 0x33ca4 loads 4 bytes from ret(find_lboard_class) +0x0.
  The `lh` at 0x33d14 loads 2 bytes from sym(compact_to_nasid_node) +0x0.
  The `jal` at 0x33c60 calls find_lboard_class with a0=?, a1=0x31, a2=?, a3=?.
  The `jal` at 0x33c80 calls find_lboard_class with a0=?, a1=0x31, a2=?, a3=?.
  The `jal` at 0x33c9c calls klhwg_connect_one_router with a0=a0 at entry (arg0), a1=ret(find_lboard_class), a2=?, a3=?.
  The `jal` at 0x33cc8 calls chk_for_pebrick with a0=?, a1=?, a2=?, a3=?.
  The `blez` branch at 0x33be8 targets 0x33cd8, is taken when at(=[sym(maxnodes)]) <= 0 (signed), and falls through when at(=[sym(maxnodes)]) > 0 (signed).
  The `beq` branch at 0x33bf4 targets 0x33d08 and is always taken.
  The `beq` branch at 0x33c14 targets 0x33cd8, is taken when s3(?) >= v0(=[sym(maxnodes)]) (signed), and falls through when s3(?) < v0(=[sym(maxnodes)]) (signed).
  The `beq` branch at 0x33c34 targets 0x33cc8, is taken when s7(=0xc000) == t8(?), and falls through when s7(=0xc000) != t8(?).
  The `beq` branch at 0x33c54 targets 0x33c60, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `beq` branch at 0x33c68 targets 0x33bfc, is taken when v0(=ret(find_lboard_class)) == 0, and falls through when v0(=ret(find_lboard_class)) != 0.
  The `beq` branch at 0x33c70 targets 0x33c94 and is always taken.
  The `beq` branch at 0x33c88 targets 0x33bfc, is taken when v0(=ret(find_lboard_class)) == 0, and falls through when v0(=ret(find_lboard_class)) != 0.
  The `bne` branch at 0x33cb8 targets 0x33c78, is taken when a1(=[ret(find_lboard_class)]) != 0, and falls through when a1(=[ret(find_lboard_class)]) == 0.
  The `beq` branch at 0x33cc0 targets 0x33c80 and is always taken.
  The `beq` branch at 0x33cd0 targets 0x33c60 and is always taken.
  The `beq` branch at 0x33d10 targets 0x33c20 and is always taken.
  The return at 0x33d00 has v0 = ?.

- `klhwg_connect_hubs` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x33d18 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x33d18-0x33f70 (600 bytes).
  It occupies 600 bytes.
  The `lbu` at 0x33d88 loads 1 byte from ?.
  The `lh` at 0x33db8 loads 2 bytes from ?.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0x33dc4, `ld` at 0x33dd8.
  The `lw` at 0x33de4 loads 4 bytes from ?.
  4 such `lh` accesses load 2 bytes from ret(find_first_component) +0x3c, including `lh` at 0x33e14, `lh` at 0x33e34, `lh` at 0x33e6c.
  The `lh` at 0x33e40 loads 2 bytes from (sym(nasid_to_compact_node) + ([ret(find_first_component)+60]:2 + [ret(find_first_component)+60]:2)) +0x0.
  The `lw` at 0x33e70 loads 4 bytes from ret(find_first_component) +0x40.
  The `lh` at 0x33f6c loads 2 bytes from sym(compact_to_nasid_node) +0x0.
  The `jal` at 0x33d78 calls is_specified with a0=sym(arg_maxnodes), a1=?, a2=sym(.rodata)+51152, a3=?.
  The `jal` at 0x33dfc calls find_lboard with a0=?, a1=0x11, a2=?, a3=?.
  The `jal` at 0x33e0c calls find_first_component with a0=ret(find_lboard), a1=0x2, a2=?, a3=?.
  The `jal` at 0x33e20 calls is_specified with a0=sym(arg_maxnodes), a1=?, a2=?, a3=?, a7=[ret(find_first_component)+60]:2.
  The `jal` at 0x33e4c calls board_to_path with a0=ret(find_lboard), a1=sp-224, a2=?, a3=?.
  The `jal` at 0x33e5c calls hwgraph_traverse with a0=a0 at entry (arg0), a1=sp-224, a2=sp-168, a3=?.
  The `jal` at 0x33e88 calls board_to_path with a0=?, a1=sp-160, a2=?, a3=?.
  The `jal` at 0x33e98 calls hwgraph_traverse with a0=a0 at entry (arg0), a1=sp-160, a2=sp-104, a3=?.
  The `jal` at 0x33eb0 calls hwgraph_edge_add with a0=?, a1=?, a2=sym(.rodata)+51152, a3=?.
  The `jal` at 0x33ec8 calls chk_for_pebrick with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x33f14 calls cmn_err with a0=0x0, a1=sym(.rodata)+51152, a2=sp-160, a3=?.
  The `jal` at 0x33f2c calls cmn_err with a0=0x4, a1=sym(.rodata)+51152, a2=sp-224, a3=?.
  The `jal` at 0x33f50 calls cmn_err with a0=0x0, a1=sym(.rodata)+51152, a2=sp-224, a3=sp-160, a5=ret(hwgraph_edge_add).
  The `blez` branch at 0x33d60 targets 0x33ed8, is taken when at(=[sym(maxnodes)]) <= 0 (signed), and falls through when at(=[sym(maxnodes)]) > 0 (signed).
  The `beq` branch at 0x33d70 targets 0x33f60 and is always taken.
  The `beq` branch at 0x33d80 targets 0x33f0c, is taken when v0(=ret(is_specified)) == 0, and falls through when v0(=ret(is_specified)) != 0.
  The `beq` branch at 0x33d90 targets 0x33f0c, is taken when (t8(?) & 0x4) == 0, and falls through when (t8(?) & 0x4) != 0.
  The `beq` branch at 0x33db0 targets 0x33ed8, is taken when s1(?) >= t9(=[sym(maxnodes)]) (signed), and falls through when s1(?) < t9(=[sym(maxnodes)]) (signed).
  The `beq` branch at 0x33dd0 targets 0x33ec8, is taken when s5(=0xc000) == t8(?), and falls through when s5(=0xc000) != t8(?).
  The `beq` branch at 0x33df0 targets 0x33dfc, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `beq` branch at 0x33e18 targets 0x33d98, is taken when a7(=[ret(find_first_component)+60]:2) == s7(=-0x1), and falls through when a7(=[ret(find_first_component)+60]:2) != s7(=-0x1).
  The `beq` branch at 0x33e28 targets 0x33e4c, is taken when v0(=ret(is_specified)) == 0, and falls through when v0(=ret(is_specified)) != 0.
  The `beq` branch at 0x33e44 targets 0x33d98, is taken when t0(=[(sym(nasid_to_compact_node) + ([ret(find_first_component)+60]:2 + [ret(find_first_component)+60]:2))]:2) == s7(=-0x1), and falls through when t0(=[(sym(nasid_to_compact_node) + ([ret(find_first_component)+60]:2 + [ret(find_first_component)+60]:2))]:2) != s7(=-0x1).
  The `bne` branch at 0x33e64 targets 0x33f24, is taken when v0(=ret(hwgraph_traverse)) != 0, and falls through when v0(=ret(hwgraph_traverse)) == 0.
  The `bne` branch at 0x33ea0 targets 0x33d78, is taken when v0(=ret(hwgraph_traverse)) != 0, and falls through when v0(=ret(hwgraph_traverse)) == 0.
  The `beql` branch at 0x33eb8 targets 0x33d9c, is taken when v0(=ret(hwgraph_edge_add)) == 0, and falls through when v0(=ret(hwgraph_edge_add)) != 0; its branch-likely delay slot `addiu s1,s1,1` at 0x33ebc runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x33ec0 targets 0x33f3c and is always taken.
  The `beq` branch at 0x33ed0 targets 0x33dfc and is always taken.
  The `beq` branch at 0x33f1c targets 0x33d9c and is always taken.
  The `beq` branch at 0x33f34 targets 0x33e70 and is always taken.
  The `beq` branch at 0x33f58 targets 0x33d9c and is always taken.
  The `beq` branch at 0x33f68 targets 0x33dbc and is always taken.
  The return at 0x33f00 has v0 = ?.
  The instructions from 0x33f08 to 0x33f08 are not reached by any path from the entry, and their branches are not listed.

- `klhwg_device_disable_hints_add` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x33f70 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x33f70-0x341a0 (560 bytes).
  It occupies 560 bytes.
  The `lh` at 0x33ff4 loads 2 bytes from ?.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0x34000, `ld` at 0x34018.
  5 such `lw` accesses load 4 bytes from ?, including `lw` at 0x34024, `lw` at 0x34070, `lw` at 0x340b4.
  6 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x34044, `lbu` at 0x34058, `lbu` at 0x3408c.
  The `lh` at 0x3419c loads 2 bytes from sym(compact_to_nasid_node) +0x0.
  The `jal` at 0x33f78 calls device_admin_table_init with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x34114 calls device_component_canonical_name_get with a0=?, a1=?, a2=sp-336, a3=?, a5=sym(compact_to_nasid_node).
  The `jal` at 0x34128 calls device_admin_table_update with a0=sp-336, a1=sym(.rodata)+51152, a2=sym(.rodata)+51152, a3=?.
  The `jal` at 0x3414c calls chk_for_pebrick with a0=?, a1=?, a2=?, a3=?, a5=sym(compact_to_nasid_node).
  The `blez` branch at 0x33fa4 targets 0x34160, is taken when at(=[sym(numnodes)]) <= 0 (signed), and falls through when at(=[sym(numnodes)]) > 0 (signed).
  The `beq` branch at 0x33fcc targets 0x34190 and is always taken.
  The `beq` branch at 0x33fec targets 0x34160, is taken when s4(?) >= t8(=[sym(numnodes)]) (signed), and falls through when s4(?) < t8(=[sym(numnodes)]) (signed).
  The `beq` branch at 0x34010 targets 0x3414c, is taken when s6(=0xc000) == t8(?), and falls through when s6(=0xc000) != t8(?).
  The `beq` branch at 0x3402c targets 0x34038, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0x34038 targets 0x33fd4, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0x34040 targets 0x3405c and is always taken.
  The `beq` branch at 0x34050 targets 0x33fd4, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0x34068 targets 0x3408c, is taken when (a6(?) & 0x4) == 0, and falls through when (a6(?) & 0x4) != 0.
  The `bne` branch at 0x3407c targets 0x34048, is taken when a2(?) != 0, and falls through when a2(?) == 0.
  The `beq` branch at 0x34084 targets 0x3404c and is always taken.
  The `bne` branch at 0x34094 targets 0x34070, is taken when s8(=0x20) != a6(?), and falls through when s8(=0x20) == a6(?).
  The `blez` branch at 0x340a4 targets 0x340e4, is taken when a0(?) <= 0 (signed), and falls through when a0(?) > 0 (signed).
  The `beq` branch at 0x340cc targets 0x34110, is taken when (t8(?) & 0x1) == 0, and falls through when (t8(?) & 0x1) != 0.
  The `bne` branch at 0x340dc targets 0x340b0, is taken when s3(?) < a0(?) (signed), and falls through when s3(?) >= a0(?) (signed).
  The `beq` branch at 0x340f8 targets 0x34050, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x34108 targets 0x34050 and is always taken.
  The `bne` branch at 0x3413c targets 0x340ac, is taken when s3(?) < a0(?) (signed), and falls through when s3(?) >= a0(?) (signed).
  The `beq` branch at 0x34144 targets 0x340e8 and is always taken.
  The `beq` branch at 0x34158 targets 0x34038 and is always taken.
  The `beq` branch at 0x34198 targets 0x33ff8 and is always taken.
  The return at 0x34188 has v0 = one of ret(device_admin_table_init), ?.

- `klhwg_dimm_flavor_info_print` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x341a0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x341a0-0x343a0 (512 bytes).
  It occupies 512 bytes.
  4 such `lh` accesses load 2 bytes from ?, including `lh` at 0x341ec, `lh` at 0x34268, `lh` at 0x342d0.
  The `lh` at 0x34218 loads 2 bytes from a1 (arg1 at entry) +0x0.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0x34300, `ld` at 0x34328.
  The `lw` at 0x34334 loads 4 bytes from ?.
  The `jal` at 0x34210 calls cmn_err with a0=0x6, a1=sym(.rodata)+51152, a2=sym(.rodata)+51152, a3=?.
  The `jal` at 0x34238 calls cmn_err with a0=0x6, a1=sym(.rodata)+51152, a2=?, a3=?.
  The `jal` at 0x3428c calls cmn_err with a0=0x6, a1=sym(.rodata)+51152, a2=?, a3=?.
  The `jal` at 0x342a8 calls cmn_err with a0=0x6, a1=sym(.rodata)+51152, a2=?, a3=?.
  The `jal` at 0x342c4 calls cmn_err with a0=0x6, a1=sym(.rodata)+51152, a2=?, a3=?.
  The `jal` at 0x34314 calls chk_for_pebrick with a0=?, a1=0x9600000000000000, a2=0xffffffffff, a3=?, a6=0x9000000034000000.
  The `jal` at 0x34350 calls find_lboard with a0=?, a1=0x11, a2=?, a3=?.
  The `jal` at 0x3435c calls board_to_path with a0=ret(find_lboard), a1=sp-176, a2=?, a3=?.
  The `jal` at 0x3436c calls cmn_err with a0=0x6, a1=sym(.rodata)+51152, a2=sp-176, a3=?.
  The `blez` branch at 0x341c4 targets 0x34230, is taken when a0 <= 0 (signed), and falls through when a0 > 0 (signed).
  The `bne` branch at 0x341f0 targets 0x34264, is taken when s0(?) != 0, and falls through when s0(?) == 0.
  The `beq` branch at 0x341f8 targets 0x34208, is taken when t8(=a2) == 0, and falls through when t8(=a2) != 0.
  The `bne` branch at 0x34228 targets 0x341e0, is taken when s0(?) < s1(=a0) (signed), and falls through when s0(?) >= s1(=a0) (signed).
  The `bgtz` branch at 0x34240 targets 0x342d4, is taken when s1(=a0) > 0 (signed), and falls through when s1(=a0) <= 0 (signed).
  The `bne` branch at 0x34270 targets 0x3429c, is taken when a3(?) != a4(?), and falls through when a3(?) == a4(?).
  The `bne` branch at 0x34278 targets 0x3421c, is taken when a6(?) != s0(?), and falls through when a6(?) == s0(?).
  The `beq` branch at 0x34294 targets 0x3421c and is always taken.
  The `beq` branch at 0x3429c targets 0x342b8, is taken when a2(?) == a5(?), and falls through when a2(?) != a5(?).
  The `beq` branch at 0x342b0 targets 0x342cc and is always taken.
  The `beq` branch at 0x342cc targets 0x3421c and is always taken.
  The `bne` branch at 0x3430c targets 0x34324, is taken when a5(=0xc000) != a4(?), and falls through when a5(=0xc000) == a4(?).
  The `beq` branch at 0x3431c targets 0x34350 and is always taken.
  The `beq` branch at 0x34338 targets 0x3434c, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `beq` branch at 0x34344 targets 0x34350 and is always taken.
  The `bne` branch at 0x34390 targets 0x342ec, is taken when s0(?) < s1(=a0) (signed), and falls through when s0(?) >= s1(=a0) (signed).
  The `beq` branch at 0x34398 targets 0x3424c and is always taken.
  The return at 0x3425c has v0 = ret(cmn_err).

- `klhwg_premium_std_dimm_mix_check` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x343a0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x343a0-0x345d0 (560 bytes).
  It occupies 560 bytes.
  4 such `sh` accesses store 2 bytes to ?, including `sh` at 0x34450, `sh` at 0x3450c, `sh` at 0x3453c.
  The `lh` at 0x34464 loads 2 bytes from ?.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0x34470, `ld` at 0x34488.
  The `lw` at 0x34494 loads 4 bytes from ?.
  The `lh` at 0x344bc loads 2 bytes from ret(find_first_component) +0x4c.
  The `lbu` at 0x344d4 loads 1 byte from ret(find_first_component) +0x1.
  The `jal` at 0x344a8 calls find_lboard with a0=?, a1=0x11, a2=?, a3=?.
  The `jal` at 0x344b4 calls find_first_component with a0=ret(find_lboard), a1=0x3, a2=?, a3=?.
  The `jal` at 0x34558 calls chk_for_pebrick with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x34574 calls klhwg_dimm_flavor_info_print with a0=?, a1=sp-336, a2=0x0, a3=?.
  The `jal` at 0x34584 calls cmn_err with a0=0x0, a1=sym(.rodata)+51152, a2=?, a3=?.
  The `jal` at 0x3459c calls cmn_err with a0=0x204, a1=sym(.rodata)+51152, a2=?, a3=?.
  The `jal` at 0x345ac calls klhwg_dimm_flavor_info_print with a0=?, a1=sp-336, a2=0x0, a3=?.
  The `jal` at 0x345bc calls klhwg_dimm_flavor_info_print with a0=?, a1=sp-592, a2=0x1, a3=?.
  The `bne` branch at 0x343b4 targets 0x343f4, is taken when v0(=[sym(.sdata)+412]:1) != at(=0xff), and falls through when v0(=[sym(.sdata)+412]:1) == at(=0xff).
  The `beq` branch at 0x343bc targets 0x343fc and is always taken.
  The `blez` branch at 0x34424 targets 0x343c4, is taken when v1(=[sym(numnodes)]) <= 0 (signed), and falls through when v1(=[sym(numnodes)]) > 0 (signed).
  The `beq` branch at 0x3443c targets 0x34458 and is always taken.
  The `beq` branch at 0x34444 targets 0x34528, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0x34454 targets 0x34510, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0x34480 targets 0x34558, is taken when s6(=0xc000) == t8(?), and falls through when s6(=0xc000) != t8(?).
  The `beq` branch at 0x3449c targets 0x344a8, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `beq` branch at 0x344f4 targets 0x34444, is taken when at(=[ret(find_first_component)+1]:1) >= 0x2 (signed), and falls through when at(=[ret(find_first_component)+1]:1) < 0x2 (signed).
  The `beq` branch at 0x344fc targets 0x34540, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x34508 targets 0x34454 and is always taken.
  The `beq` branch at 0x34510 targets 0x343c8, is taken when s4(?) == 0, and falls through when s4(?) != 0.
  The `bne` branch at 0x34518 targets 0x34568, is taken when s2(?) != 0, and falls through when s2(?) == 0.
  The `beq` branch at 0x34520 targets 0x343cc and is always taken.
  The `beq` branch at 0x34538 targets 0x34454 and is always taken.
  The `beq` branch at 0x34550 targets 0x34454 and is always taken.
  The `beq` branch at 0x34560 targets 0x344a8 and is always taken.
  The `bne` branch at 0x34568 targets 0x34594, is taken when v0(?) != 0, and falls through when v0(?) == 0.
  The `beq` branch at 0x3458c targets 0x345c8 and is always taken.
  The `beq` branch at 0x345c8 targets 0x343d0 and is always taken.
  The return at 0x343f4 has v0 = one of [sym(.sdata)+412]:1, ?.

- `klhwg_add_all_modules` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x345d0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x345d0-0x3472c (348 bytes).
  It occupies 348 bytes.
  4 such `ld` accesses load 8 bytes from ?, including `ld` at 0x34640, `ld` at 0x34664, `ld` at 0x34670.
  3 such `lh` accesses load 2 bytes from ?, including `lh` at 0x34650, `lh` at 0x34680, `lh` at 0x346cc.
  The `jal` at 0x34610 calls kern_free with a0=ret(kern_malloc), a1=sym(.rodata)+51152, a2=?, a3=?.
  The `jal` at 0x34618 calls sndrv_attach with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x3464c calls sprintf with a0=sp-192, a1=sym(.rodata)+51152, a2=?, a3=?.
  The `jal` at 0x3465c calls hwgraph_path_add with a0=a0 at entry (arg0), a1=sp-192, a2=sp-64, a3=?.
  The `jal` at 0x34668 calls hwgraph_fastinfo_set with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x3467c calls sprintf with a0=sp-192, a1=sym(.rodata)+51152, a2=?, a3=?.
  The `jal` at 0x3468c calls hwgraph_path_add with a0=a0 at entry (arg0), a1=sp-192, a2=sp-64, a3=?.
  The `jal` at 0x346a4 calls hwgraph_info_add_LBL with a0=?, a1=sym(.rodata)+51152, a2=0x1, a3=?.
  The `jal` at 0x346ac calls kern_malloc with a0=0x20, a1=?, a2=?, a3=?.
  The `jal` at 0x346c8 calls l1_mfg_string with a0=ret(kern_malloc), a1=?, a2=?, a3=0x0.
  The `jal` at 0x346e0 calls hwgraph_info_add_LBL with a0=?, a1=sym(.rodata)+51152, a2=ret(kern_malloc), a3=?.
  The `jal` at 0x3471c calls assfail with a0=sym(.rodata)+51152, a1=sym(.rodata)+51152, a2=0x6f0, a3=?.
  The `blez` branch at 0x345fc targets 0x346f0, is taken when at(=[sym(nummodules)]) <= 0 (signed), and falls through when at(=[sym(nummodules)]) > 0 (signed).
  The `beq` branch at 0x34608 targets 0x3463c and is always taken.
  The `beq` branch at 0x34634 targets 0x346f0, is taken when s1(?) >= v0(=[sym(nummodules)]) (signed), and falls through when s1(?) < v0(=[sym(nummodules)]) (signed).
  The `bne` branch at 0x34694 targets 0x34714, is taken when v0(=ret(hwgraph_path_add)) != 0, and falls through when v0(=ret(hwgraph_path_add)) == 0.
  The `bne` branch at 0x346d0 targets 0x34610, is taken when v0(=ret(l1_mfg_string)) != 0, and falls through when v0(=ret(l1_mfg_string)) == 0.
  The `beq` branch at 0x346e8 targets 0x34618 and is always taken.
  The `beq` branch at 0x34724 targets 0x3469c and is always taken.
  The return at 0x3470c has v0 = ?.

- `klhwg_add_all_nodes` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x3472c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x3472c-0x34800 (212 bytes).
  It occupies 212 bytes.
  The `ld` at 0x34768 loads 8 bytes from ((ret(get_nasid) << 0x21)+0x9600000000000000 | 0x2000) +0xd0.
  The `jal` at 0x3473c calls get_nasid with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x34774 calls klhwg_add_node with a0=a0 at entry (arg0), a1=?, a2=[((ret(get_nasid) << 0x21)+0x9600000000000000 | 0x2000)+208]:8, a3=?.
  The `jal` at 0x347a0 calls klhwg_add_all_xbows with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x347cc calls klhwg_add_all_routers with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x347d4 calls klhwg_connect_routers with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x347dc calls klhwg_connect_hubs with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x347e4 calls router_guardians_set with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x347ec calls klhwg_device_disable_hints_add with a0=?, a1=?, a2=?, a3=?.
  The `blez` branch at 0x34764 targets 0x347c4, is taken when at(=[sym(numnodes)]) <= 0 (signed), and falls through when at(=[sym(numnodes)]) > 0 (signed).
  The `bnel` branch at 0x34790 targets 0x34770, is taken when s0(?) < a0(=[sym(numnodes)]) (signed), and falls through when s0(?) >= a0(=[sym(numnodes)]) (signed); its branch-likely delay slot `or a0,s1,zero` at 0x34794 runs only when taken and is annulled on fall-through.
  The `blez` branch at 0x34798 targets 0x347c4, is taken when a0(=[sym(numnodes)]) <= 0 (signed), and falls through when a0(=[sym(numnodes)]) > 0 (signed).
  The `bne` branch at 0x347bc targets 0x347a0, is taken when s0(?) < t8(=[sym(numnodes)]) (signed), and falls through when s0(?) >= t8(=[sym(numnodes)]) (signed).
  The return at 0x347f8 has v0 = ret(klhwg_device_disable_hints_add).

- `hub_ioerror_local` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x37900 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x37900-0x379fc (252 bytes).
  It occupies 252 bytes.
  The `lw` at 0x3793c loads 4 bytes from a3 (arg3 at entry) +0x0.
  2 such `lh` accesses load 2 bytes from a3 (arg3 at entry) +0xc, including `lh` at 0x37940, `lh` at 0x379c4.
  2 such `lh` accesses load 2 bytes from a3 (arg3 at entry) +0xe, including `lh` at 0x37948, `lh` at 0x379c8.
  The `lh` at 0x3795c loads 2 bytes from (sym(compact_to_nasid_node) + ([a3+12]:2 + [a3+12]:2)) +0x0.
  The `lh` at 0x37968 loads 2 bytes from (sym(compact_to_nasid_node) + ([a3+14]:2 + [a3+14]:2)) +0x0.
  2 such `ld` accesses load 8 bytes from a3 (arg3 at entry) +0x10, including `ld` at 0x37970, `ld` at 0x379cc.
  The `ld` at 0x37988 loads 8 bytes from ([(sym(compact_to_nasid_node) + ([a3+14]:2 + [a3+14]:2))]:2 << 0x21) -0x6dfffffffe800000.
  The `jal` at 0x379b0 calls cmn_err with a0=0x4, a1=sym(.rodata)+56232, a2=?, a3=[(sym(compact_to_nasid_node) + ([a3+14]:2 + [a3+14]:2))]:2, a4=[a3+14]:2, a5=[(sym(compact_to_nasid_node) + ([a3+12]:2 + [a3+12]:2))]:2, a6=[a3+12]:2.
  The `jal` at 0x379bc calls kl_panic with a0=sym(.rodata)+56232, a1=?, a2=?, a3=?.
  The `jal` at 0x379e0 calls cmn_err with a0=0x4, a1=sym(.rodata)+56232, a2=[a3+16]:8, a3=[(sym(compact_to_nasid_node) + ([a3+14]:2 + [a3+14]:2))]:2, a4=[a3+14]:2, a5=[(sym(compact_to_nasid_node) + ([a3+12]:2 + [a3+12]:2))]:2, a6=[a3+12]:2.
  The `jal` at 0x379ec calls kl_panic with a0=sym(.rodata)+56232, a1=?, a2=?, a3=?.
  The `beq` branch at 0x3790c targets 0x37934, is taken when a2 == 0, and falls through when a2 != 0.
  The `beq` branch at 0x37918 targets 0x37934, is taken when a2 == at(=0x2), and falls through when a2 != at(=0x2).
  The `bne` branch at 0x37920 targets 0x3793c, is taken when a2 != v0(=0x3), and falls through when a2 == v0(=0x3).
  The `beq` branch at 0x37934 targets 0x37928 and is always taken.
  The `bgez` branch at 0x37964 targets 0x37974, is taken when a2(=([a3] << 0x6)) >= 0 (signed), and falls through when a2(=([a3] << 0x6)) < 0 (signed).
  The `beq` branch at 0x3796c targets 0x37978 and is always taken.
  The `beq` branch at 0x3799c targets 0x379cc, is taken when (a3(=[([(sym(compact_to_nasid_node) + ([a3+14]:2 + [a3+14]:2))]:2 << 0x21)-7926335344146907136]:8) & a5(?)) == 0, and falls through when (a3(=[([(sym(compact_to_nasid_node) + ([a3+14]:2 + [a3+14]:2))]:2 << 0x21)-7926335344146907136]:8) & a5(?)) != 0.
  The `beq` branch at 0x379f4 targets 0x37928 and is always taken.
  The return at 0x3792c has v0 = one of 0x0, ret(kl_panic).

- `hub_xp_error_handler` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x379fc (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x379fc-0x37ae4 (232 bytes).
  It occupies 232 bytes.
  The `ld` at 0x37a14 loads 8 bytes from (a1 << 0x21) -0x6dfffffffe3ffe18.
  The `ld` at 0x37a4c loads 8 bytes from abs 0xffffffffffffc400.
  The `lh` at 0x37a54 loads 2 bytes from (sym(nasid_to_compact_node) + (a1 + a1)) +0x0.
  The `ld` at 0x37a58 loads 8 bytes from [-0x3c00]:8 +0x0.
  The `ld` at 0x37a64 loads 8 bytes from ([[-0x3c00]:8]:8 + ([(sym(nasid_to_compact_node) + (a1 + a1))]:2 << 0x3)) +0x0.
  The `lw` at 0x37a74 loads 4 bytes from [([[-0x3c00]:8]:8 + ([(sym(nasid_to_compact_node) + (a1 + a1))]:2 << 0x3))]:8 +0x8640.
  The `jal` at 0x37a38 calls error_state_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a7=0x7.
  The `jal` at 0x37a7c calls error_state_set with a0=[[([[-0x3c00]:8]:8 + ([(sym(nasid_to_compact_node) + (a1 + a1))]:2 << 0x3))]:8+34368], a1=ret(error_state_get), a2=[([[-0x3c00]:8]:8 + ([(sym(nasid_to_compact_node) + (a1 + a1))]:2 << 0x3))]:8, a3=([(sym(nasid_to_compact_node) + (a1 + a1))]:2 << 0x3), a4=(a1 + a1).
  The `jal` at 0x37aac calls xtalk_error_handler with a0=[[([[-0x3c00]:8]:8 + ([(sym(nasid_to_compact_node) + (a1 + a1))]:2 << 0x3))]:8+34368], a1=a2 at entry (arg2), a2=a3 at entry (arg3), a3=a4 at entry (arg4).
  The `jal` at 0x37ad4 calls error_state_set with a0=a0 at entry (arg0), a1=0x1, a2=?, a3=?, a5=0x7, a6=ret(error_state_get), a7=0x9.
  The `beq` branch at 0x37a30 targets 0x37ab8, is taken when (at(=[(a1 << 0x21)-7926335344142712344]:8) & 0x11) == 0, and falls through when (at(=[(a1 << 0x21)-7926335344142712344]:8) & 0x11) != 0.
  The `beq` branch at 0x37a90 targets 0x37acc, is taken when v0(=ret(error_state_set)) == a5(=0x7), and falls through when v0(=ret(error_state_set)) != a5(=0x7).
  The `beq` branch at 0x37a98 targets 0x37ad4, is taken when a6(=ret(error_state_get)) == t0(=0x3), and falls through when a6(=ret(error_state_get)) != t0(=0x3).
  The `beq` branch at 0x37acc targets 0x37abc and is always taken.
  The `beq` branch at 0x37adc targets 0x37aa4 and is always taken.
  The return at 0x37ac4 has v0 = one of ?, 0x9.

- `hub_widgetdev_enable` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x38c8c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x38c8c-0x38d2c (160 bytes).
  It occupies 160 bytes.
  The `lh` at 0x38cf0 loads 2 bytes from ?.
  The `ld` at 0x38d08 loads 8 bytes from table(0x9200000001c00120) +0x0.
  The `sd` at 0x38d28 stores 8 bytes to table(0x9200000001c00120) +0x0.
  The `jal` at 0x38c98 calls xwidget_info_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x38ca4 calls xwidget_info_id_get with a0=ret(xwidget_info_get), a1=?, a2=?, a3=?.
  The `jal` at 0x38cb0 calls xwidget_info_master_get with a0=ret(xwidget_info_get), a1=?, a2=?, a3=?.
  The `jal` at 0x38cc8 calls hwgraph_info_get_LBL with a0=ret(xwidget_info_master_get), a1=sym(.rodata)+56232, a2=sp-48, a3=?.
  The `beq` branch at 0x38ce8 targets 0x38d1c, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `beq` branch at 0x38d14 targets 0x38d24, is taken when (a6(?) & a7(=entry(0x9200000001c00120))) == 0, and falls through when (a6(?) & a7(=entry(0x9200000001c00120))) != 0.
  The `beq` branch at 0x38d24 targets 0x38d1c and is always taken.
  The return at 0x38d1c has v0 = one of ret(hwgraph_info_get_LBL), table(0x9200000001c00000).

- `bte_init` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x3d1d8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x3d1d8-0x3d330 (344 bytes).
  It occupies 344 bytes.
  The `sd` at 0x3d228 stores 8 bytes to a0 (arg0 at entry) +0x20.
  The `sd` at 0x3d22c stores 8 bytes to a0 (arg0 at entry) +0x28.
  The `lh` at 0x3d230 loads 2 bytes from abs 0xffffffffffffc42a.
  The `sh` at 0x3d23c stores 2 bytes to a0 (arg0 at entry) +0x38.
  The `sd` at 0x3d24c stores 8 bytes to a0 (arg0 at entry) +0x18.
  The `lh` at 0x3d254 loads 2 bytes from (sym(compact_to_nasid_node) + ([-0x3bd6]:2 + [-0x3bd6]:2)) +0x0.
  2 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x0, including `sd` at 0x3d278, `sd` at 0x3d280.
  2 such `sd` accesses store 8 bytes to abs 0x92000000014001f8, including `sd` at 0x3d284, `sd` at 0x3d324.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x4c, including `sw` at 0x3d288, `sw` at 0x3d32c.
  2 such `ld` accesses load 8 bytes from abs 0x9200000001604200, including `ld` at 0x3d28c, `ld` at 0x3d2e0.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x68, including `sw` at 0x3d2c8, `sw` at 0x3d30c.
  The `jal` at 0x3d214 calls spinlock_init with a0=a0+60, a1=sym(.rodata)+64800, a2=a2 at entry (arg2), a3=a3 at entry (arg3), a5=[sym(scache_linemask)].
  The `beq` branch at 0x3d200 targets 0x3d210, is taken when (a5(=[sym(scache_linemask)]) & a1) == 0, and falls through when (a5(=[sym(scache_linemask)]) & a1) != 0.
  The `beq` branch at 0x3d274 targets 0x3d320, is taken when s8(=a2) == 0, and falls through when s8(=a2) != 0.
  The `beq` branch at 0x3d2d8 targets 0x3d310, is taken when t2(=[sym(maxcpus)]) >= 0x21 (signed), and falls through when t2(=[sym(maxcpus)]) < 0x21 (signed).
  The `beq` branch at 0x3d328 targets 0x3d28c and is always taken.
  The return at 0x3d318 has v0 = a0.

- `bte_notification_war` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x3dbbc (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x3dbbc-0x3dd14 (344 bytes).
  It occupies 344 bytes.
  5 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x58, including `ld` at 0x3dbd8, `ld` at 0x3dc44, `ld` at 0x3dc6c.
  2 such `lh` accesses load 2 bytes from a0 (arg0 at entry) +0x38, including `lh` at 0x3dbf4, `lh` at 0x3dd10.
  The `ld` at 0x3dc04 loads 8 bytes from a0 (arg0 at entry) +0x0.
  The `lh` at 0x3dc08 loads 2 bytes from (sym(compact_to_nasid_node) + ([a0+56]:2 + [a0+56]:2)) +0x0.
  The `ld` at 0x3dc10 loads 8 bytes from [a0]:8 +0x18.
  The `ld` at 0x3dc20 loads 8 bytes from ([(sym(compact_to_nasid_node) + ([a0+56]:2 + [a0+56]:2))]:2 << 0x21) -0x6dfffffffe3ffe00.
  The `sd` at 0x3dc30 stores 8 bytes to ([(sym(compact_to_nasid_node) + ([a0+56]:2 + [a0+56]:2))]:2 << 0x21) -0x6dfffffffe3ffe00.
  The `lw` at 0x3dc3c loads 4 bytes from a0 (arg0 at entry) +0x4c.
  The `lw` at 0x3dc48 loads 4 bytes from a0 (arg0 at entry) +0x48.
  The `sw` at 0x3dc50 stores 4 bytes to a0 (arg0 at entry) +0x48.
  2 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x0, including `lw` at 0x3dc9c, `lw` at 0x3dcd0.
  2 such `sw` accesses store 4 bytes to a1 (arg1 at entry) +0x0, including `sw` at 0x3dcb0, `sw` at 0x3dce4.
  The `jal` at 0x3dbd4 calls nested_spintrylock with a0=[a0+88]:8, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x3dbe4 calls bte_get_all_interfaces with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0x3dc2c calls us_delay with a0=0x190, a1=?, a2=?, a3=?.
  The `jal` at 0x3dc38 calls bte_free_interfaces with a0=a0 at entry (arg0), a1=[a0+76], a2=?, a3=?.
  The `jal` at 0x3dc40 calls nested_spinunlock with a0=[a0+88]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x3dc68 calls nested_spintrylock with a0=[a0+88]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x3dc78 calls nested_spintrylock with a0=a0+60, a1=?, a2=?, a3=?.
  The `jal` at 0x3dc88 calls nested_spinunlock with a0=[a0+88]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x3dc98 calls splx with a0=[a1], a1=?, a2=?, a3=?.
  The `jal` at 0x3dca0 calls us_delay with a0=0x1, a1=?, a2=?, a3=?.
  The `jal` at 0x3dca8 calls splhi with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x3dcb4 calls nested_spintrylock with a0=a0+60, a1=?, a2=?, a3=?.
  The `jal` at 0x3dccc calls splx with a0=[a1], a1=?, a2=?, a3=?.
  The `jal` at 0x3dcd4 calls us_delay with a0=0x1, a1=?, a2=?, a3=?.
  The `jal` at 0x3dcdc calls splhi with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x3dce8 calls nested_spintrylock with a0=[a0+88]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x3dd04 calls cmn_err with a0=0xc, a1=sym(.rodata)+64800, a2=?, a3=?.
  The `beq` branch at 0x3dbdc targets 0x3dc68, is taken when v0(=ret(nested_spintrylock)) == 0, and falls through when v0(=ret(nested_spintrylock)) != 0.
  The `bne` branch at 0x3dbec targets 0x3dd00, is taken when v0(=ret(bte_get_all_interfaces)) != 0, and falls through when v0(=ret(bte_get_all_interfaces)) == 0.
  The `beq` branch at 0x3dc70 targets 0x3dccc, is taken when v0(=ret(nested_spintrylock)) == 0, and falls through when v0(=ret(nested_spintrylock)) != 0.
  The `beq` branch at 0x3dc80 targets 0x3dc98, is taken when v0(=ret(nested_spintrylock)) == 0, and falls through when v0(=ret(nested_spintrylock)) != 0.
  The `beq` branch at 0x3dc90 targets 0x3dc58 and is always taken.
  The `beq` branch at 0x3dcbc targets 0x3dc98, is taken when v0(=ret(nested_spintrylock)) == 0, and falls through when v0(=ret(nested_spintrylock)) != 0.
  The `beq` branch at 0x3dcc4 targets 0x3dc88 and is always taken.
  The `beq` branch at 0x3dcf0 targets 0x3dccc, is taken when v0(=ret(nested_spintrylock)) == 0, and falls through when v0(=ret(nested_spintrylock)) != 0.
  The `beq` branch at 0x3dcf8 targets 0x3dc78 and is always taken.
  The `beq` branch at 0x3dd0c targets 0x3dbf8 and is always taken.
  The return at 0x3dc60 has v0 = ret(nested_spinunlock).

- `bte_acquire_buffer` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x3e300 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x3e300-0x3e464 (356 bytes).
  It occupies 356 bytes.
  The `lh` at 0x3e32c loads 2 bytes from table(sym(nasid_to_compact_node)) +0x0.
  The `lbu` at 0x3e37c loads 1 byte from ((entry(sym(nasid_to_compact_node)) << 0x2) + sym(.bss)+55512) +0x1000.
  The `lbu` at 0x3e398 loads 1 byte from ?.
  The `ld` at 0x3e3b4 loads 8 bytes from ?.
  The `ld` at 0x3e42c loads 8 bytes from table(sym(.bss)+55512) +0x0.
  The `sb` at 0x3e448 stores 1 byte to ?.
  The `ld` at 0x3e450 loads 8 bytes from (sym(.bss)+55512 + ((entry(sym(nasid_to_compact_node)) << 0x2) << 0x3)) +0x0.
  The `jal` at 0x3e374 calls mutex_spinlock with a0=((entry(sym(nasid_to_compact_node)) << 0x2) + sym(.bss)+55512)+4608, a1=?, a2=?, a3=?.
  The `jal` at 0x3e3c4 calls mutex_spinunlock with a0=((entry(sym(nasid_to_compact_node)) << 0x2) + sym(.bss)+55512)+4608, a1=ret(mutex_spinlock), a2=?, a3=?.
  The `beq` branch at 0x3e384 targets 0x3e44c, is taken when t8(=[((entry(sym(nasid_to_compact_node)) << 0x2) + sym(.bss)+55512)+4096]:1) == 0, and falls through when t8(=[((entry(sym(nasid_to_compact_node)) << 0x2) + sym(.bss)+55512)+4096]:1) != 0.
  The `beq` branch at 0x3e38c targets 0x3e3a4 and is always taken.
  The `beq` branch at 0x3e39c targets 0x3e428, is taken when t9(?) == 0, and falls through when t9(?) != 0.
  The `bne` branch at 0x3e3bc targets 0x3e394, is taken when s0(?) < 0x4 (signed), and falls through when s0(?) >= 0x4 (signed).
  The `beq` branch at 0x3e3cc targets 0x3e418, is taken when s7(=a1) == 0, and falls through when s7(=a1) != 0.
  The `bne` branch at 0x3e3d8 targets 0x3e418, is taken when s0(?) != at(=0x4), and falls through when s0(?) == at(=0x4).
  The `bne` branch at 0x3e3e0 targets 0x3e374, is taken when s1(=one of 0x0, 0x1) != 0, and falls through when s1(=one of 0x0, 0x1) == 0.
  The `beq` branch at 0x3e418 targets 0x3e3e8, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x3e420 targets 0x3e3e8 and is always taken.
  The `beq` branch at 0x3e430 targets 0x3e3a4, is taken when v1(=entry(sym(.bss)+55512)) == 0, and falls through when v1(=entry(sym(.bss)+55512)) != 0.
  The `beq` branch at 0x3e438 targets 0x3e3c4, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `beq` branch at 0x3e444 targets 0x3e3c4 and is always taken.
  The `beq` branch at 0x3e454 targets 0x3e38c, is taken when a2(=[(sym(.bss)+55512 + ((entry(sym(nasid_to_compact_node)) << 0x2) << 0x3))]:8) == 0, and falls through when a2(=[(sym(.bss)+55512 + ((entry(sym(nasid_to_compact_node)) << 0x2) << 0x3))]:8) != 0.
  The `beq` branch at 0x3e45c targets 0x3e440 and is always taken.
  The return at 0x3e40c has v0 = one of -0x1, ?.
  The instructions from 0x3e414 to 0x3e414 are not reached by any path from the entry, and their branches are not listed.

- `bte_release_buffer` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x3e464 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x3e464-0x3e4c4 (96 bytes).
  It occupies 96 bytes.
  The `sb` at 0x3e4b0 stores 1 byte to (a0 + sym(.bss)+55512) +0x1000.
  The `jal` at 0x3e494 calls mutex_spinlock with a0=table(sym(.bss)+55512)+4608, a1=?, a2=?, a3=a3 at entry (arg3).
  The `jal` at 0x3e4ac calls mutex_spinunlock with a0=table(sym(.bss)+55512)+4608, a1=ret(mutex_spinlock), a2=?, a3=(a0 + sym(.bss)+55512).
  The return at 0x3e4bc has v0 = ret(mutex_spinunlock).

- `bte_pull` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x3e4c4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x3e4c4-0x3e74c (648 bytes).
  It occupies 648 bytes.
  2 such `ld` accesses load 8 bytes from abs 0xffffffffffffc018, including `ld` at 0x3e57c, `ld` at 0x3e718.
  2 such `ld` accesses load 8 bytes from [-0x3fe8]:8 +0x3f8, including `ld` at 0x3e580, `ld` at 0x3e71c.
  The `ld` at 0x3e6c0 loads 8 bytes from (sym(.bss)+55512 + (ret(bte_acquire_buffer) << 0x3)) +0x0.
  The `jal` at 0x3e5dc calls bte_copy with a0=?, a1=?, a2=?, a3=a3 at entry (arg3).
  The `jal` at 0x3e654 calls bcopy with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x3e680 calls bte_release_buffer [0x3e464] with a0=?, a1=?, a2=?, a3=?, a6=-0x1.
  The `jal` at 0x3e694 calls bte_acquire_buffer [0x3e300] with a0=a1 at entry (arg1), a1=?, a2=a2 at entry (arg2), a3=a3 at entry (arg3), a6=0x9000000000000000, a7=0xa800010000000000.
  The `bne` branch at 0x3e520 targets 0x3e52c, is taken when a2 < 0x401 (unsigned), and falls through when a2 >= 0x401 (unsigned).
  The `beq` branch at 0x3e528 targets 0x3e690, is taken when v0(=[sym(.sdata)+432]:1) == 0, and falls through when v0(=[sym(.sdata)+432]:1) != 0.
  The `bne` branch at 0x3e550 targets 0x3e560, is taken when a3(?) < a1(=0xa800000000000000) (unsigned), and falls through when a3(?) >= a1(=0xa800000000000000) (unsigned).
  The `bne` branch at 0x3e558 targets 0x3e570, is taken when a3(?) != 0, and falls through when a3(?) == 0.
  The `bne` branch at 0x3e560 targets 0x3e57c, is taken when a0(?) != 0, and falls through when a0(?) == 0.
  The `beq` branch at 0x3e568 targets 0x3e57c, is taken when t3(?) == 0, and falls through when t3(?) != 0.
  The `beq` branch at 0x3e570 targets 0x3e59c and is always taken.
  The `beq` branch at 0x3e5bc targets 0x3e674, is taken when s1(=a2) == 0, and falls through when s1(=a2) != 0.
  The `beq` branch at 0x3e5e4 targets 0x3e61c, is taken when v0(=ret(bte_copy)) == 0, and falls through when v0(=ret(bte_copy)) != 0.
  The `bne` branch at 0x3e66c targets 0x3e5c4, is taken when s1(?) != 0, and falls through when s1(?) == 0.
  The `beq` branch at 0x3e678 targets 0x3e688, is taken when s6(?) == a6(=-0x1), and falls through when s6(?) != a6(=-0x1).
  The `beq` branch at 0x3e688 targets 0x3e5ec and is always taken.
  The `beq` branch at 0x3e6b0 targets 0x3e6c4, is taken when v0(=ret(bte_acquire_buffer)) == a2(=-0x1), and falls through when v0(=ret(bte_acquire_buffer)) != a2(=-0x1).
  The `beq` branch at 0x3e6bc targets 0x3e5a4 and is always taken.
  The `bne` branch at 0x3e6d8 targets 0x3e6e8, is taken when a0(?) < a1(=0xa800000000000000) (unsigned), and falls through when a0(?) >= a1(=0xa800000000000000) (unsigned).
  The `bne` branch at 0x3e6e4 targets 0x3e70c, is taken when a0(?) < a2(=0xa800010000000000) (unsigned), and falls through when a0(?) >= a2(=0xa800010000000000) (unsigned).
  The `bne` branch at 0x3e6fc targets 0x3e718, is taken when a2(?) < a3(=0x9000000000000000) (unsigned), and falls through when a2(?) >= a3(=0x9000000000000000) (unsigned).
  The `beq` branch at 0x3e708 targets 0x3e718, is taken when a2(?) >= a3(=0x9000010000000000) (unsigned), and falls through when a2(?) < a3(=0x9000010000000000) (unsigned).
  The `beq` branch at 0x3e710 targets 0x3e73c and is always taken.
  The `beq` branch at 0x3e744 targets 0x3e5a4 and is always taken.
  The return at 0x3e614 has v0 = one of ret(bte_copy), 0x0.
  The instructions from 0x3e578 to 0x3e578 are not reached by any path from the entry, and their branches are not listed.

- `probe_common` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x3ec6c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x3ec6c-0x3ed8c (288 bytes).
  It occupies 288 bytes.
  The `lw` at 0x3eccc loads 4 bytes from a0 (arg0 at entry) +0x0.
  The `ld` at 0x3ecdc loads 8 bytes from ((ret(get_nasid) << 0x21) + one of 0x9200000001800400, 0x9200000001a00400) +0x0.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x18, including `ld` at 0x3ecf4, `ld` at 0x3ed74.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x4, including `lw` at 0x3ecf8, `lw` at 0x3ed78.
  3 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x10, including `ld` at 0x3ed00, `ld` at 0x3ed40, `ld` at 0x3ed80.
  The `sd` at 0x3ed38 stores 8 bytes to ((ret(get_nasid) << 0x21) + one of 0x9200000001800400, 0x9200000001a00400) +0x0.
  The `jal` at 0x3ec84 calls mutex_lock with a0=sym(probe_sema), a1=0x14, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x3ec8c calls getsr with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x3ec98 calls setsr with a0=0x80, a1=?, a2=?, a3=?.
  The `jal` at 0x3eca0 calls get_slice with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x3ecac calls get_nasid with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x3ecfc calls _badaddr_val with a0=[a0+16]:8, a1=[a0+4], a2=[a0+24]:8, a3=0x3, a4=[a0].
  The `jal` at 0x3ed08 calls get_slice with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x3ed10 calls get_nasid with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x3ed3c calls is_buserror with a0=[a0+16]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x3ed50 calls setsr with a0=ret(getsr), a1=?, a2=?, a3=?.
  The `jal` at 0x3ed58 calls mutex_unlock with a0=sym(probe_sema), a1=?, a2=?, a3=?.
  The `jal` at 0x3ed7c calls _wbadaddr_val with a0=[a0+16]:8, a1=[a0+4], a2=[a0+24]:8, a3=0x3, a4=[a0].
  The `beq` branch at 0x3ece4 targets 0x3ed74, is taken when a4(=[a0]) == at(=0x1), and falls through when a4(=[a0]) != at(=0x1).
  The `beq` branch at 0x3ecec targets 0x3ed74, is taken when a4(=[a0]) == a3(=0x3), and falls through when a4(=[a0]) != a3(=0x3).
  The `beq` branch at 0x3ed84 targets 0x3ed08 and is always taken.
  The return at 0x3ed6c has v0 = ?.

- `bte_crb_error_handler` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x3f14c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x3f14c-0x3f29c (336 bytes).
  It occupies 336 bytes.
  The `ld` at 0x3f180 loads 8 bytes from ?.
  The `ld` at 0x3f198 loads 8 bytes from table(0x8ef8) +0x0.
  The `lh` at 0x3f19c loads 2 bytes from a3 (arg3 at entry) +0x4.
  The `sh` at 0x3f1a0 stores 2 bytes to entry(0x8ef8) +0x30.
  The `lh` at 0x3f1a8 loads 2 bytes from ?.
  The `ld` at 0x3f1c0 loads 8 bytes from entry(0x8ef8) +0x18.
  The `ld` at 0x3f1d8 loads 8 bytes from table(0x9200000001c00400) +0x0.
  The `sd` at 0x3f200 stores 8 bytes to table(0x9200000001c00400) +0x0.
  The `sd` at 0x3f208 stores 8 bytes to table(0x9200000001c003b0) +0x0.
  6 such `ld` accesses load 8 bytes from table(0x9200000001c003b0) +0x0, including `ld` at 0x3f20c, `ld` at 0x3f21c, `ld` at 0x3f22c.
  The `ld` at 0x3f278 loads 8 bytes from entry(0x8ef8) +0x20.
  The `sd` at 0x3f28c stores 8 bytes to [entry(0x8ef8)+32]:8 +0x0.
  The `jal` at 0x3f174 calls hwgraph_info_get_LBL with a0=a0 at entry (arg0), a1=sym(.rodata)+65336, a2=sp-64, a3=a3 at entry (arg3).
  The `jal` at 0x3f270 calls us_delay with a0=0xa, a1=table(0x9200000001c00000), a2=(entry(0x9200000001c003b0) << 0x2f), a3=(a2 | 0x10800), a5=table(0x9200000001c00000), a6=0xff0fffffffffffff.
  The `bgez` branch at 0x3f214 targets 0x3f270, is taken when a2(=(entry(0x9200000001c003b0) << 0x2f)) >= 0 (signed), and falls through when a2(=(entry(0x9200000001c003b0) << 0x2f)) < 0 (signed).
  The `beq` branch at 0x3f224 targets 0x3f26c, is taken when (s0(=0x10000) & a7(=entry(0x9200000001c003b0))) == 0, and falls through when (s0(=0x10000) & a7(=entry(0x9200000001c003b0))) != 0.
  The `beq` branch at 0x3f234 targets 0x3f26c, is taken when (s0(=0x10000) & t0(=entry(0x9200000001c003b0))) == 0, and falls through when (s0(=0x10000) & t0(=entry(0x9200000001c003b0))) != 0.
  The `beq` branch at 0x3f244 targets 0x3f26c, is taken when (s0(=0x10000) & t1(=entry(0x9200000001c003b0))) == 0, and falls through when (s0(=0x10000) & t1(=entry(0x9200000001c003b0))) != 0.
  The `beq` branch at 0x3f254 targets 0x3f26c, is taken when (s0(=0x10000) & t2(=entry(0x9200000001c003b0))) == 0, and falls through when (s0(=0x10000) & t2(=entry(0x9200000001c003b0))) != 0.
  The `bne` branch at 0x3f264 targets 0x3f21c, is taken when (s0(=0x10000) & t3(=entry(0x9200000001c003b0))) != 0, and falls through when (s0(=0x10000) & t3(=entry(0x9200000001c003b0))) == 0.
  The `beq` branch at 0x3f284 targets 0x3f290, is taken when a1(=[entry(0x8ef8)+32]:8) == 0, and falls through when a1(=[entry(0x8ef8)+32]:8) != 0.
  The return at 0x3f294 has v0 = ret(us_delay).

- `sn1_sc_versioncheck` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x41138 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x41138-0x41330 (504 bytes).
  It occupies 504 bytes.
  The `ld` at 0x41240 loads 8 bytes from table(sym(pdaindr)) +0x8.
  The `lw` at 0x41244 loads 4 bytes from [table(sym(pdaindr))+8]:8 +0x484.
  2 such `lh` accesses load 2 bytes from ret(cnodemodule_lookup) +0x0, including `lh` at 0x41298, `lh` at 0x412d8.
  The `jal` at 0x41190 calls cnodemodule_lookup with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x411a4 calls sc_version with a0=ret(cnodemodule_lookup)+40, a1=sp-112, a2=sp-108, a3=sp-104.
  The `jal` at 0x41220 calls cnode_slice_to_cpuid with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x41288 calls cnodemodule_lookup with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x4129c calls cmn_err with a0=0x1, a1=sym(.rodata)+65600, a2=[ret(cnodemodule_lookup)]:2, a3=ret(sc_version).
  The `jal` at 0x412b0 calls sprintf with a0=sp-96, a1=sym(.rodata)+65600, a2=?, a3=?.
  The `jal` at 0x412b8 calls cnodemodule_lookup with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x412dc calls cmn_err with a0=0x1, a1=sym(.rodata)+65600, a2=0x1, a3=0x3, a4=0x14, a5=[ret(cnodemodule_lookup)]:2, a6=sp-96.
  The `jal` at 0x412f8 calls cmn_err with a0=0x1, a1=sym(.rodata)+65600, a2=0x1, a3=0x3, a4=0x14.
  The `jal` at 0x41308 calls cmn_err with a0=0x1, a1=sym(.rodata)+65600, a2=?, a3=?.
  The `jal` at 0x41314 calls us_delay with a0=0x4c4b40, a1=?, a2=?, a3=?.
  The `jal` at 0x41320 calls mdboot with a0=0x0, a1=0x0, a2=?, a3=?.
  The `blez` branch at 0x41164 targets 0x4125c, is taken when at(=[sym(numnodes)]) <= 0 (signed), and falls through when at(=[sym(numnodes)]) > 0 (signed).
  The `beq` branch at 0x41180 targets 0x41208 and is always taken.
  The `beq` branch at 0x41188 targets 0x411f0, is taken when s5(?) == 0, and falls through when s5(?) != 0.
  The `bltz` branch at 0x411b0 targets 0x41288, is taken when v0(=ret(sc_version)) < 0 (signed), and falls through when v0(=ret(sc_version)) >= 0 (signed).
  The `bne` branch at 0x411e8 targets 0x412ac, is taken when t8(?) < s6(=0xf4e0c) (signed), and falls through when t8(?) >= s6(=0xf4e0c) (signed).
  The `beq` branch at 0x41204 targets 0x4125c, is taken when s1(?) >= t9(=[sym(numnodes)]) (signed), and falls through when s1(?) < t9(=[sym(numnodes)]) (signed).
  The `beq` branch at 0x4120c targets 0x4121c and is always taken.
  The `beq` branch at 0x41218 targets 0x41188, is taken when t8(?) == 0, and falls through when t8(?) != 0.
  The `beq` branch at 0x41228 targets 0x41214, is taken when v0(=ret(cnode_slice_to_cpuid)) == s2(=-0x1), and falls through when v0(=ret(cnode_slice_to_cpuid)) != s2(=-0x1).
  The `bne` branch at 0x4124c targets 0x41218, is taken when s4(=0xf) != t9(?), and falls through when s4(=0xf) == t9(?).
  The `beq` branch at 0x41254 targets 0x41214 and is always taken.
  The `beq` branch at 0x412a4 targets 0x411f4 and is always taken.
  The `beq` branch at 0x41328 targets 0x411f4 and is always taken.
  The return at 0x41280 has v0 = ?.

- `io_perf_start_count` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x42a70 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x42a70-0x42ad0 (96 bytes).
  It occupies 96 bytes.
  The `lh` at 0x42a70 loads 2 bytes from a0 (arg0 at entry) +0x1a.
  The `lh` at 0x42a74 loads 2 bytes from a0 (arg0 at entry) +0x4.
  The `ld` at 0x42a9c loads 8 bytes from ([a0+26]:2 << 0x21) -0x6dfffffffe3d0000.
  The `ld` at 0x42ac4 loads 8 bytes from ([a0+26]:2 << 0x21) -0x6dfffffffe3cfff8.
  The `sd` at 0x42acc stores 8 bytes to ([a0+26]:2 << 0x21) -0x6dfffffffe3d0000.
  The `beq` branch at 0x42a98 targets 0x42ab4, is taken when a6(=[a0+4]:2) >= 0x10 (signed), and falls through when a6(=[a0+4]:2) < 0x10 (signed).
  The `beq` branch at 0x42aac targets 0x42ac4 and is always taken.
  The return at 0x42ac8 has v0 = ?.

- `io_perf_stop_count` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x42ad0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x42ad0-0x42af0 (32 bytes).
  It occupies 32 bytes.
  The `lh` at 0x42ad0 loads 2 bytes from a0 (arg0 at entry) +0x1a.
  The `ld` at 0x42ae0 loads 8 bytes from ([a0+26]:2 << 0x21) -0x6dfffffffe3d0000.
  The `sd` at 0x42aec stores 8 bytes to ([a0+26]:2 << 0x21) -0x6dfffffffe3d0000.
  The return at 0x42ae8 has v0 = ([a0+26]:2 << 0x21)+0x9200000001c30000.

- `io_perf_update_count` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x42af0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x42af0-0x42b60 (112 bytes).
  It occupies 112 bytes.
  The `lh` at 0x42b00 loads 2 bytes from a0 (arg0 at entry) +0x1a.
  2 such `lh` accesses load 2 bytes from a0 (arg0 at entry) +0x4, including `lh` at 0x42b08, `lh` at 0x42b40.
  The `ld` at 0x42b14 loads 8 bytes from ([a0+26]:2 << 0x21) -0x6dfffffffe3cfff8.
  The `ld` at 0x42b2c loads 8 bytes from (a0 + ([a0+4]:2 << 0x3)) +0x20.
  The `lwu` at 0x42b34 loads 4 bytes from ?.
  The `sd` at 0x42b3c stores 8 bytes to (a0 + ([a0+4]:2 << 0x3)) +0x20.
  The `sd` at 0x42b50 stores 8 bytes to (a0 + ([a0+4]:2 << 0x3)) +0x120.
  The `beq` branch at 0x42af8 targets 0x42b58, is taken when a3(=[sym(lfsr_table)]:8) == 0, and falls through when a3(=[sym(lfsr_table)]:8) != 0.
  The return at 0x42b58 has v0 = one of -0x1, 0x0.

- `md_perf_init` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x42c34 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x42c34-0x42d14 (224 bytes).
  It occupies 224 bytes.
  The `sh` at 0x42c84 stores 2 bytes to sym(.bss) +0xf0b4.
  The `sw` at 0x42c8c stores 4 bytes to sym(.bss) +0xf0cc.
  The `sh` at 0x42c98 stores 2 bytes to sym(.bss) +0xf0b2.
  2 such `ld` accesses load 8 bytes from abs 0xffffffffffffc400, including `ld` at 0x42c9c, `ld` at 0x42cf8.
  The `ld` at 0x42ca0 loads 8 bytes from [-0x3c00]:8 +0x0.
  The `ld` at 0x42cb0 loads 8 bytes from ?.
  The `lh` at 0x42cbc loads 2 bytes from ?.
  3 such `sh` accesses store 2 bytes to ?, including `sh` at 0x42cc4, `sh` at 0x42cd8, `sh` at 0x42cdc.
  The `sw` at 0x42ccc stores 4 bytes to ?.
  The `jal` at 0x42c40 calls spinlock_init with a0=sym(mdp_lock), a1=sym(.rodata)+66048, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x42c68 calls init_mutex with a0=sym(global_mdp_mon), a1=0x0, a2=sym(.rodata)+66048, a3=0x0.
  The `jal` at 0x42ce0 calls init_mutex with a0=?, a1=0x0, a2=sym(.rodata)+66048, a3=?.
  The `blez` branch at 0x42c94 targets 0x42cfc, is taken when a1(=[sym(maxnodes)]) <= 0 (signed), and falls through when a1(=[sym(maxnodes)]) > 0 (signed).
  The `bnel` branch at 0x42cf4 targets 0x42ca0, is taken when s0(?) < a5(=[sym(maxnodes)]) (signed), and falls through when s0(?) >= a5(=[sym(maxnodes)]) (signed); its branch-likely delay slot `ld a4,-15360(zero)` at 0x42cf8 runs only when taken and is annulled on fall-through.
  The return at 0x42d0c has v0 = ret(init_mutex).

- `md_perf_turnon_node` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x42d14 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x42d14-0x42f74 (608 bytes).
  It occupies 608 bytes.
  The `ld` at 0x42d4c loads 8 bytes from abs 0xffffffffffffc400.
  The `ld` at 0x42d50 loads 8 bytes from [-0x3c00]:8 +0x0.
  The `ld` at 0x42d5c loads 8 bytes from ((a1 << 0x3) + [[-0x3c00]:8]:8) +0x0.
  The `lh` at 0x42d68 loads 2 bytes from [((a1 << 0x3) + [[-0x3c00]:8]:8)]:8 +0x8596.
  4 such `lh` accesses load 2 bytes from [((a1 << 0x3) + [[-0x3c00]:8]:8)]:8 +0x8652, including `lh` at 0x42d98, `lh` at 0x42e44, `lh` at 0x42e5c.
  2 such `sh` accesses store 2 bytes to [((a1 << 0x3) + [[-0x3c00]:8]:8)]:8 +0x8650, including `sh` at 0x42dcc, `sh` at 0x42e04.
  3 such `sh` accesses store 2 bytes to [((a1 << 0x3) + [[-0x3c00]:8]:8)]:8 +0x8652, including `sh` at 0x42dd8, `sh` at 0x42e58, `sh` at 0x42f04.
  2 such `sh` accesses store 2 bytes to [((a1 << 0x3) + [[-0x3c00]:8]:8)]:8 +0x8654, including `sh` at 0x42de0, `sh` at 0x42e38.
  The `lw` at 0x42dec loads 4 bytes from a0 (arg0 at entry) +0x0.
  The `sw` at 0x42df8 stores 4 bytes to [((a1 << 0x3) + [[-0x3c00]:8]:8)]:8 +0x87c0.
  The `lh` at 0x42dfc loads 2 bytes from [((a1 << 0x3) + [[-0x3c00]:8]:8)]:8 +0x8650.
  The `lw` at 0x42e8c loads 4 bytes from [((a1 << 0x3) + [[-0x3c00]:8]:8)]:8 +0x866c.
  The `sw` at 0x42e94 stores 4 bytes to [((a1 << 0x3) + [[-0x3c00]:8]:8)]:8 +0x866c.
  The `ld` at 0x42edc loads 8 bytes from ?.
  The `sd` at 0x42ee8 stores 8 bytes to ?.
  The `ld` at 0x42f20 loads 8 bytes from (sym(pdaindr) + ([[((a1 << 0x3) + [[-0x3c00]:8]:8)]:8+34198]:2 << 0x4)) +0x8.
  The `sb` at 0x42f30 stores 1 byte to [(sym(pdaindr) + ([[((a1 << 0x3) + [[-0x3c00]:8]:8)]:8+34198]:2 << 0x4))+8]:8 +0x52a.
  The `jal` at 0x42d90 calls mutex_lock with a0=[((a1 << 0x3) + [[-0x3c00]:8]:8)]:8+34392, a1=0x19, a2=a2 at entry (arg2), a3=a3 at entry (arg3), a5=[((a1 << 0x3) + [[-0x3c00]:8]:8)]:8, a6=[[-0x3c00]:8]:8.
  The `jal` at 0x42da8 calls mutex_unlock with a0=[((a1 << 0x3) + [[-0x3c00]:8]:8)]:8+34392, a1=0x150, a2=?, a3=?.
  The `jal` at 0x42dd4 calls bzero with a0=[((a1 << 0x3) + [[-0x3c00]:8]:8)]:8+34416, a1=0x150, a2=?, a3=?.
  The `jal` at 0x42e54 calls mutex_spinlock with a0=sym(mdp_lock), a1=?, a2=?, a3=?, a5=[a0], a6=0x1.
  The `jal` at 0x42e9c calls mutex_spinunlock with a0=sym(mdp_lock), a1=ret(mutex_spinlock), a2=[sym(mdp_mode)]:2, a3=?, a5=[sym(mdp_cnt)]+1, a6=0x4.
  The `jal` at 0x42f00 calls md_perf_start_count with a0=[((a1 << 0x3) + [[-0x3c00]:8]:8)]:8+34384, a1=0x7fffffffffffffff, a2=?, a3=?, a5=([[((a1 << 0x3) + [[-0x3c00]:8]:8)]:8+34386]:2 | 0x1).
  The `jal` at 0x42f08 calls mutex_unlock with a0=[((a1 << 0x3) + [[-0x3c00]:8]:8)]:8+34392, a1=?, a2=?, a3=?.
  The `jal` at 0x42f3c calls mutex_unlock with a0=[((a1 << 0x3) + [[-0x3c00]:8]:8)]:8+34392, a1=?, a2=?, a3=a2 at entry (arg2), a5=[a0], a6=0x1.
  The `jal` at 0x42f4c calls mutex_spinunlock with a0=sym(mdp_lock), a1=ret(mutex_spinlock), a2=[sym(mdp_mode)]:2, a3=?, a5=[sym(mdp_cnt)]+1, a6=0x4.
  The `jal` at 0x42f54 calls mutex_unlock with a0=[((a1 << 0x3) + [[-0x3c00]:8]:8)]:8+34392, a1=?, a2=?, a3=?.
  The `beq` branch at 0x42d34 targets 0x42db4, is taken when a1 >= at(=[sym(maxnodes)]) (signed), and falls through when a1 < at(=[sym(maxnodes)]) (signed).
  The `bltz` branch at 0x42d3c targets 0x42db4, is taken when a1 < 0 (signed), and falls through when a1 >= 0 (signed).
  The `beq` branch at 0x42d44 targets 0x42db4, is taken when a1 == s1(=-0x1), and falls through when a1 != s1(=-0x1).
  The `beq` branch at 0x42d78 targets 0x42f34, is taken when v1(=[[((a1 << 0x3) + [[-0x3c00]:8]:8)]:8+34198]:2) == s1(=-0x1), and falls through when v1(=[[((a1 << 0x3) + [[-0x3c00]:8]:8)]:8+34198]:2) != s1(=-0x1).
  The `beq` branch at 0x42da0 targets 0x42dcc, is taken when (t8(=[[((a1 << 0x3) + [[-0x3c00]:8]:8)]:8+34386]:2) & 0x1) == 0, and falls through when (t8(=[[((a1 << 0x3) + [[-0x3c00]:8]:8)]:8+34386]:2) & 0x1) != 0.
  The `beq` branch at 0x42df4 targets 0x42f64 and is always taken.
  The `beq` branch at 0x42e14 targets 0x42e3c, is taken when v0(?) >= 0x6 (signed), and falls through when v0(?) < 0x6 (signed).
  The `beq` branch at 0x42e1c targets 0x42e08, is taken when t1(?) == 0, and falls through when t1(?) != 0.
  The `bne` branch at 0x42e24 targets 0x42dfc, is taken when a1(?) != s1(=-0x1), and falls through when a1(?) == s1(=-0x1).
  The `beq` branch at 0x42e34 targets 0x42e08 and is always taken.
  The `beq` branch at 0x42e3c targets 0x42f3c, is taken when a1(?) == s1(=-0x1), and falls through when a1(?) != s1(=-0x1).
  The `beq` branch at 0x42e74 targets 0x42e98, is taken when (a4(=[[((a1 << 0x3) + [[-0x3c00]:8]:8)]:8+34386]:2) & 0x4) == 0, and falls through when (a4(=[[((a1 << 0x3) + [[-0x3c00]:8]:8)]:8+34386]:2) & 0x4) != 0.
  The `beq` branch at 0x42e7c targets 0x42f4c, is taken when a2(=[sym(mdp_mode)]:2) == a1(=0x2), and falls through when a2(=[sym(mdp_mode)]:2) != a1(=0x2).
  The `bne` branch at 0x42ee4 targets 0x42ec8, is taken when v0(?) < 0x6 (signed), and falls through when v0(?) >= 0x6 (signed).
  The `bne` branch at 0x42eec targets 0x42eb4, is taken when a0(?) != 0, and falls through when a0(?) == 0.
  The `beq` branch at 0x42f2c targets 0x42db4 and is always taken.
  The `beq` branch at 0x42f34 targets 0x42db8 and is always taken.
  The `beq` branch at 0x42f44 targets 0x42db4 and is always taken.
  The `beq` branch at 0x42f5c targets 0x42db4 and is always taken.
  The `beq` branch at 0x42f6c targets 0x42e1c and is always taken.
  The return at 0x42dc4 has v0 = one of 0x0, 0x10, 0x16.

- `md_perf_turnoff_node` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x42f74 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x42f74-0x430cc (344 bytes).
  It occupies 344 bytes.
  The `ld` at 0x42fa4 loads 8 bytes from abs 0xffffffffffffc400.
  The `ld` at 0x42fa8 loads 8 bytes from [-0x3c00]:8 +0x0.
  The `ld` at 0x42fb4 loads 8 bytes from ((a0 << 0x3) + [[-0x3c00]:8]:8) +0x0.
  The `lh` at 0x42fc0 loads 2 bytes from [((a0 << 0x3) + [[-0x3c00]:8]:8)]:8 +0x8596.
  3 such `lh` accesses load 2 bytes from [((a0 << 0x3) + [[-0x3c00]:8]:8)]:8 +0x8652, including `lh` at 0x42fe8, `lh` at 0x4300c, `lh` at 0x43050.
  The `lw` at 0x4303c loads 4 bytes from [((a0 << 0x3) + [[-0x3c00]:8]:8)]:8 +0x866c.
  The `sw` at 0x43044 stores 4 bytes to [((a0 << 0x3) + [[-0x3c00]:8]:8)]:8 +0x866c.
  The `sh` at 0x43064 stores 2 bytes to [((a0 << 0x3) + [[-0x3c00]:8]:8)]:8 +0x8652.
  The `ld` at 0x43088 loads 8 bytes from (sym(pdaindr) + ([[((a0 << 0x3) + [[-0x3c00]:8]:8)]:8+34198]:2 << 0x4)) +0x8.
  The `sb` at 0x43090 stores 1 byte to [(sym(pdaindr) + ([[((a0 << 0x3) + [[-0x3c00]:8]:8)]:8+34198]:2 << 0x4))+8]:8 +0x52a.
  The `jal` at 0x42fe0 calls mutex_lock with a0=[((a0 << 0x3) + [[-0x3c00]:8]:8)]:8+34392, a1=0x19, a2=a2 at entry (arg2), a3=a3 at entry (arg3), a4=-0x1.
  The `jal` at 0x43004 calls mutex_spinlock with a0=sym(mdp_lock), a1=?, a2=?, a3=?.
  The `jal` at 0x43048 calls mutex_spinunlock with a0=sym(mdp_lock), a1=ret(mutex_spinlock), a2=?, a3=?, a4=[sym(mdp_cnt)], a5=[sym(mdp_mode)]:2.
  The `jal` at 0x43060 calls md_perf_stop_count with a0=[((a0 << 0x3) + [[-0x3c00]:8]:8)]:8+34384, a1=?, a2=?, a3=?.
  The `jal` at 0x43068 calls md_perf_update_count with a0=[((a0 << 0x3) + [[-0x3c00]:8]:8)]:8+34384, a1=?, a2=?, a3=?.
  The `jal` at 0x43070 calls mutex_unlock with a0=[((a0 << 0x3) + [[-0x3c00]:8]:8)]:8+34392, a1=?, a2=?, a3=?.
  The `jal` at 0x430a4 calls mutex_unlock with a0=[((a0 << 0x3) + [[-0x3c00]:8]:8)]:8+34392, a1=?, a2=?, a3=?.
  The `jal` at 0x430bc calls mutex_unlock with a0=[((a0 << 0x3) + [[-0x3c00]:8]:8)]:8+34392, a1=?, a2=?, a3=?.
  The `beq` branch at 0x42f8c targets 0x43094, is taken when a0 >= at(=[sym(maxnodes)]) (signed), and falls through when a0 < at(=[sym(maxnodes)]) (signed).
  The `bltz` branch at 0x42f94 targets 0x43094, is taken when a0 < 0 (signed), and falls through when a0 >= 0 (signed).
  The `beq` branch at 0x42f9c targets 0x43094, is taken when a0 == a4(=-0x1), and falls through when a0 != a4(=-0x1).
  The `beq` branch at 0x42fc8 targets 0x430b4, is taken when v1(=[[((a0 << 0x3) + [[-0x3c00]:8]:8)]:8+34198]:2) == a4(=-0x1), and falls through when v1(=[[((a0 << 0x3) + [[-0x3c00]:8]:8)]:8+34198]:2) != a4(=-0x1).
  The `beq` branch at 0x42ff4 targets 0x430bc, is taken when (v0(=[[((a0 << 0x3) + [[-0x3c00]:8]:8)]:8+34386]:2) & 0x1) == 0, and falls through when (v0(=[[((a0 << 0x3) + [[-0x3c00]:8]:8)]:8+34386]:2) & 0x1) != 0.
  The `bne` branch at 0x42ffc targets 0x430a4, is taken when a0(=a1) != v0(?), and falls through when a0(=a1) == v0(?).
  The `beq` branch at 0x43020 targets 0x43048, is taken when (a2(=[[((a0 << 0x3) + [[-0x3c00]:8]:8)]:8+34386]:2) & 0x4) == 0, and falls through when (a2(=[[((a0 << 0x3) + [[-0x3c00]:8]:8)]:8+34386]:2) & 0x4) != 0.
  The `beq` branch at 0x430ac targets 0x43094 and is always taken.
  The `beq` branch at 0x430b4 targets 0x43094 and is always taken.
  The `beq` branch at 0x430c4 targets 0x43094 and is always taken.
  The return at 0x4309c has v0 = one of -0x1, 0x0, 0x16.

- `md_perf_enable` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x430cc (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x430cc-0x43200 (308 bytes).
  It occupies 308 bytes.
  2 such `lw` accesses load 4 bytes from sym(.bss) +0xf0cc, including `lw` at 0x4319c, `lw` at 0x431d0.
  The `lh` at 0x431a0 loads 2 bytes from sym(.bss) +0xf0b2.
  The `sw` at 0x431a8 stores 4 bytes to sym(.bss) +0xf0cc.
  The `lw` at 0x431ac loads 4 bytes from a0 (arg0 at entry) +0x0.
  The `sh` at 0x431b4 stores 2 bytes to sym(.bss) +0xf0b2.
  The `sw` at 0x431c0 stores 4 bytes to sym(.bss) +0xf220.
  The `sw` at 0x431dc stores 4 bytes to a1 (arg1 at entry) +0x0.
  The `jal` at 0x430e4 calls cap_able with a0=0x2000000000, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x43100 calls mutex_lock with a0=sym(global_mdp_mon), a1=0x19, a2=?, a3=?.
  The `jal` at 0x43108 calls mutex_spinlock with a0=sym(mdp_lock), a1=?, a2=?, a3=?.
  The `jal` at 0x4311c calls mutex_spinunlock with a0=sym(mdp_lock), a1=ret(mutex_spinlock), a2=?, a3=?.
  The `jal` at 0x43124 calls mutex_unlock with a0=sym(global_mdp_mon), a1=?, a2=?, a3=?.
  The `jal` at 0x43150 calls mutex_spinunlock with a0=sym(mdp_lock), a1=ret(mutex_spinlock), a2=?, a3=?.
  The `jal` at 0x43174 calls md_perf_turnon_node with a0=a0 at entry (arg0), a1=?, a2=0x2, a3=?.
  The `jal` at 0x431bc calls mutex_unlock with a0=sym(global_mdp_mon), a1=?, a2=?, a3=?, a4=[a0], a5=sym(global_mdp_mon), a6=([sym(global_mdp_mon+2)]:2 | 0x1), a7=[sym(global_mdp_mon+28)]+1.
  The `jal` at 0x431e8 calls mutex_unlock with a0=sym(global_mdp_mon), a1=?, a2=?, a3=?.
  The `jal` at 0x431f0 calls md_perf_disable with a0=?, a1=?, a2=?, a3=?.
  The `beq` branch at 0x430ec targets 0x431e0, is taken when v0(=ret(cap_able)) == 0, and falls through when v0(=ret(cap_able)) != 0.
  The `beq` branch at 0x43114 targets 0x43144, is taken when t8(=[sym(mdp_mode)]:2) == 0, and falls through when t8(=[sym(mdp_mode)]:2) != 0.
  The `blez` branch at 0x4315c targets 0x43198, is taken when ra(=[sym(maxnodes)]) <= 0 (signed), and falls through when ra(=[sym(maxnodes)]) > 0 (signed).
  The `bne` branch at 0x43180 targets 0x431e8, is taken when v0(=ret(md_perf_turnon_node)) != 0, and falls through when v0(=ret(md_perf_turnon_node)) == 0.
  The `bne` branch at 0x43190 targets 0x4316c, is taken when s0(?) < a0(=[sym(maxnodes)]) (signed), and falls through when s0(?) >= a0(=[sym(maxnodes)]) (signed).
  The `beq` branch at 0x431d8 targets 0x43130 and is always taken.
  The `beq` branch at 0x431e0 targets 0x43130 and is always taken.
  The `beq` branch at 0x431f8 targets 0x43130 and is always taken.
  The return at 0x4313c has v0 = one of 0x10, 0x0, 0x1, ret(md_perf_turnon_node).

- `md_perf_disable` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x43200 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x43200-0x43304 (260 bytes).
  It occupies 260 bytes.
  The `lh` at 0x43298 loads 2 bytes from sym(.bss) +0xf0b2.
  The `sh` at 0x432b0 stores 2 bytes to sym(.bss) +0xf0b2.
  The `lw` at 0x432b8 loads 4 bytes from sym(.bss) +0xf0cc.
  The `sw` at 0x432c8 stores 4 bytes to sym(.bss) +0xf0cc.
  The `jal` at 0x4320c calls cap_able with a0=0x2000000000, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x43228 calls mutex_lock with a0=sym(global_mdp_mon), a1=0x19, a2=?, a3=?.
  The `jal` at 0x43240 calls mutex_unlock with a0=sym(global_mdp_mon), a1=?, a2=?, a3=?.
  The `jal` at 0x43264 calls md_perf_turnoff_node with a0=?, a1=0x2, a2=?, a3=?.
  The `jal` at 0x43288 calls mutex_spinlock with a0=sym(mdp_lock), a1=?, a2=?, a3=?.
  The `jal` at 0x432ac calls mutex_spinunlock with a0=sym(mdp_lock), a1=ret(mutex_spinlock), a2=?, a3=sym(global_mdp_mon), a4=-0x2.
  The `jal` at 0x432c4 calls mutex_unlock with a0=sym(global_mdp_mon), a1=?, a2=?, a3=?, a5=[sym(global_mdp_mon+28)]+1, a6=sym(global_mdp_mon).
  The `jal` at 0x432f4 calls assfail with a0=sym(.rodata)+66048, a1=sym(.rodata)+66048, a2=0x178, a3=?.
  The `beq` branch at 0x43214 targets 0x432e0, is taken when v0(=ret(cap_able)) == 0, and falls through when v0(=ret(cap_able)) != 0.
  The `beq` branch at 0x43238 targets 0x43250, is taken when t8(=[sym(mdp_mode)]:2) == t9(=0x2), and falls through when t8(=[sym(mdp_mode)]:2) != t9(=0x2).
  The `beq` branch at 0x43248 targets 0x432d0 and is always taken.
  The `blez` branch at 0x43250 targets 0x43284, is taken when v0(=[sym(maxnodes)]) <= 0 (signed), and falls through when v0(=[sym(maxnodes)]) > 0 (signed).
  The `bne` branch at 0x4326c targets 0x432e8, is taken when v0(=ret(md_perf_turnoff_node)) != 0, and falls through when v0(=ret(md_perf_turnoff_node)) == 0.
  The `bne` branch at 0x4327c targets 0x43260, is taken when s0(?) < a1(=[sym(maxnodes)]) (signed), and falls through when s0(?) >= a1(=[sym(maxnodes)]) (signed).
  The `beq` branch at 0x432e0 targets 0x432d0 and is always taken.
  The `beq` branch at 0x432fc targets 0x43274 and is always taken.
  The return at 0x432d8 has v0 = one of 0x0, 0x1, 0x16.

- `md_perf_node_enable` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x43304 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x43304-0x43388 (132 bytes).
  It occupies 132 bytes.
  The `ld` at 0x43348 loads 8 bytes from abs 0xffffffffffffc400.
  The `ld` at 0x4334c loads 8 bytes from [-0x3c00]:8 +0x0.
  The `ld` at 0x43358 loads 8 bytes from ([[-0x3c00]:8]:8 + (a1 << 0x3)) +0x0.
  The `lw` at 0x43368 loads 4 bytes from [([[-0x3c00]:8]:8 + (a1 << 0x3))]:8 +0x866c.
  The `sw` at 0x43374 stores 4 bytes to a2 (arg2 at entry) +0x0.
  The `jal` at 0x43324 calls md_perf_turnon_node with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0x4, a3=a3 at entry (arg3).
  The `jal` at 0x43378 calls md_perf_enable with a0=a0 at entry (arg0), a1=a2 at entry (arg2), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0x4331c targets 0x43378, is taken when a1 == at(=-0x1), and falls through when a1 != at(=-0x1).
  The `beq` branch at 0x4332c targets 0x43348, is taken when v0(=ret(md_perf_turnon_node)) == 0, and falls through when v0(=ret(md_perf_turnon_node)) != 0.
  The `beq` branch at 0x43370 targets 0x43334 and is always taken.
  The `beq` branch at 0x43380 targets 0x43334 and is always taken.
  The return at 0x43340 has v0 = one of ret(md_perf_turnon_node), 0x0, ret(md_perf_enable).

- `md_perf_node_disable` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x43388 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x43388-0x433c4 (60 bytes).
  It occupies 60 bytes.
  The `jal` at 0x43398 calls md_perf_turnoff_node with a0=a0 at entry (arg0), a1=0x4, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x433b4 calls md_perf_disable with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0x43390 targets 0x433b4, is taken when a0 == at(=-0x1), and falls through when a0 != at(=-0x1).
  The `beq` branch at 0x433bc targets 0x433a4 and is always taken.
  The return at 0x433ac has v0 = one of ret(md_perf_turnoff_node), ret(md_perf_disable).

- `md_perf_transfer_values` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x433c4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x433c4-0x43484 (192 bytes).
  It occupies 192 bytes.
  5 such `ld` accesses load 8 bytes from ?, including `ld` at 0x433f0, `ld` at 0x43410, `ld` at 0x43414.
  4 such `sd` accesses store 8 bytes to ?, including `sd` at 0x433fc, `sd` at 0x43430, `sd` at 0x43448.
  The `beq` branch at 0x4345c targets 0x43468, is taken when t3(?) == 0, and falls through when t3(?) != 0.
  The `bne` branch at 0x43468 targets 0x43404, is taken when a4(?) != 0, and falls through when a4(?) == 0.
  The `bne` branch at 0x43474 targets 0x433dc, is taken when t2(?) < 0x6 (signed), and falls through when t2(?) >= 0x6 (signed).
  The return at 0x4347c has v0 = ?.

- `md_perf_get_count` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x43484 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x43484-0x43534 (176 bytes).
  It occupies 176 bytes.
  2 such `sw` accesses store 4 bytes to a1 (arg1 at entry) +0x0, including `sw` at 0x434c4, `sw` at 0x43518.
  2 such `ld` accesses load 8 bytes from abs 0xffffffffffffc400, including `ld` at 0x434d4, `ld` at 0x43504.
  The `ld` at 0x434d8 loads 8 bytes from [-0x3c00]:8 +0x0.
  The `ld` at 0x434e4 loads 8 bytes from ?.
  The `lw` at 0x43510 loads 4 bytes from sym(.bss) +0xf0cc.
  The `jal` at 0x434a0 calls bzero with a0=a0 at entry (arg0), a1=0x150, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x434ec calls md_perf_transfer_values with a0=a0 at entry (arg0), a1=table(0x8670), a2=?, a3=?.
  The `beq` branch at 0x434b8 targets 0x434c8, is taken when at(=[sym(mdp_mode)]:2) == v0(=0x2), and falls through when at(=[sym(mdp_mode)]:2) != v0(=0x2).
  The `beq` branch at 0x434c0 targets 0x4351c and is always taken.
  The `blez` branch at 0x434c8 targets 0x43508, is taken when a0(=[sym(maxnodes)]) <= 0 (signed), and falls through when a0(=[sym(maxnodes)]) > 0 (signed).
  The `bnel` branch at 0x43500 targets 0x434d8, is taken when s0(?) < a2(=[sym(maxnodes)]) (signed), and falls through when s0(?) >= a2(=[sym(maxnodes)]) (signed); its branch-likely delay slot `ld a1,-15360(zero)` at 0x43504 runs only when taken and is annulled on fall-through.
  The return at 0x4352c has v0 = one of -0x1, 0x0.

- `md_perf_get_node_count` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x43534 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x43534-0x43614 (224 bytes).
  It occupies 224 bytes.
  The `ld` at 0x43580 loads 8 bytes from abs 0xffffffffffffc400.
  The `ld` at 0x43584 loads 8 bytes from [-0x3c00]:8 +0x0.
  The `ld` at 0x43590 loads 8 bytes from ([[-0x3c00]:8]:8 + (a0 << 0x3)) +0x0.
  The `lh` at 0x435b0 loads 2 bytes from [([[-0x3c00]:8]:8 + (a0 << 0x3))]:8 +0x8652.
  The `lw` at 0x435c4 loads 4 bytes from sym(.bss) +0xf0cc.
  2 such `sw` accesses store 4 bytes to a2 (arg2 at entry) +0x0, including `sw` at 0x435c8, `sw` at 0x435fc.
  The `lw` at 0x435f4 loads 4 bytes from [([[-0x3c00]:8]:8 + (a0 << 0x3))]:8 +0x866c.
  The `jal` at 0x43560 calls bzero with a0=a1 at entry (arg1), a1=0x150, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x435a4 calls md_perf_transfer_values with a0=a1 at entry (arg1), a1=[([[-0x3c00]:8]:8 + (a0 << 0x3))]:8+34416, a2=0x8650, a3=?.
  The `jal` at 0x43604 calls md_perf_get_count with a0=a1 at entry (arg1), a1=a2 at entry (arg2), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0x43554 targets 0x43600, is taken when a0 == at(=-0x1), and falls through when a0 != at(=-0x1).
  The `beq` branch at 0x43570 targets 0x435ec, is taken when s0(=a0) >= v0(=[sym(maxnodes)]) (signed), and falls through when s0(=a0) < v0(=[sym(maxnodes)]) (signed).
  The `bltz` branch at 0x43578 targets 0x435ec, is taken when s0(=a0) < 0 (signed), and falls through when s0(=a0) >= 0 (signed).
  The `beq` branch at 0x435c0 targets 0x435f4, is taken when a1(?) == a2(=0x4), and falls through when a1(?) != a2(=0x4).
  The `beq` branch at 0x435ec targets 0x435d4 and is always taken.
  The `beq` branch at 0x435f8 targets 0x435cc and is always taken.
  The `beq` branch at 0x4360c targets 0x435d0 and is always taken.
  The return at 0x435e4 has v0 = one of ?, 0x16.

- `md_perf_get_ctrl` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x43614 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x43614-0x43690 (124 bytes).
  It occupies 124 bytes.
  The `lh` at 0x43640 loads 2 bytes from sym(.bss) +0xf0b2.
  The `lw` at 0x43654 loads 4 bytes from sym(.bss) +0xf220.
  The `sw` at 0x43658 stores 4 bytes to a0 (arg0 at entry) +0x0.
  The `lw` at 0x4365c loads 4 bytes from sym(.bss) +0xf0cc.
  The `sw` at 0x43660 stores 4 bytes to a1 (arg1 at entry) +0x0.
  The `jal` at 0x43634 calls mutex_lock with a0=sym(global_mdp_mon), a1=0x19, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x43664 calls mutex_unlock with a0=sym(global_mdp_mon), a1=?, a2=?, a3=?.
  The `jal` at 0x43680 calls mutex_unlock with a0=sym(global_mdp_mon), a1=?, a2=?, a3=?.
  The `beq` branch at 0x43648 targets 0x43680, is taken when (t8(=[sym(global_mdp_mon+2)]:2) & 0x1) == 0, and falls through when (t8(=[sym(global_mdp_mon+2)]:2) & 0x1) != 0.
  The `beq` branch at 0x43688 targets 0x43670 and is always taken.
  The return at 0x43678 has v0 = one of 0x0, 0x16.

- `md_perf_get_node_ctrl` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x43690 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x43690-0x43794 (260 bytes).
  It occupies 260 bytes.
  The `ld` at 0x436d4 loads 8 bytes from abs 0xffffffffffffc400.
  The `ld` at 0x436d8 loads 8 bytes from [-0x3c00]:8 +0x0.
  The `ld` at 0x436e4 loads 8 bytes from ([[-0x3c00]:8]:8 + (a0 << 0x3)) +0x0.
  2 such `lh` accesses load 2 bytes from [([[-0x3c00]:8]:8 + (a0 << 0x3))]:8 +0x8652, including `lh` at 0x43700, `lh` at 0x4371c.
  The `lw` at 0x43714 loads 4 bytes from [([[-0x3c00]:8]:8 + (a0 << 0x3))]:8 +0x87c0.
  The `sw` at 0x43718 stores 4 bytes to a1 (arg1 at entry) +0x0.
  The `lw` at 0x4372c loads 4 bytes from sym(.bss) +0xf0cc.
  2 such `sw` accesses store 4 bytes to a2 (arg2 at entry) +0x0, including `sw` at 0x43730, `sw` at 0x4376c.
  The `lw` at 0x43764 loads 4 bytes from [([[-0x3c00]:8]:8 + (a0 << 0x3))]:8 +0x866c.
  The `jal` at 0x436f8 calls mutex_lock with a0=[([[-0x3c00]:8]:8 + (a0 << 0x3))]:8+34392, a1=0x19, a2=a2 at entry (arg2), a3=a3 at entry (arg3), a5=a0 at entry (arg0), a6=0x16.
  The `jal` at 0x43734 calls mutex_unlock with a0=[([[-0x3c00]:8]:8 + (a0 << 0x3))]:8+34392, a1=[sym(global_mdp_mon+28)], a2=?, a3=?.
  The `jal` at 0x43774 calls md_perf_get_ctrl with a0=a1 at entry (arg1), a1=a2 at entry (arg2), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a5=a0 at entry (arg0), a6=0x16.
  The `jal` at 0x43784 calls mutex_unlock with a0=[([[-0x3c00]:8]:8 + (a0 << 0x3))]:8+34392, a1=?, a2=?, a3=?.
  The `beq` branch at 0x436b8 targets 0x43770, is taken when a0 == at(=-0x1), and falls through when a0 != at(=-0x1).
  The `beq` branch at 0x436c4 targets 0x4375c, is taken when a0 >= v0(=[sym(maxnodes)]) (signed), and falls through when a0 < v0(=[sym(maxnodes)]) (signed).
  The `bltz` branch at 0x436cc targets 0x4375c, is taken when a0 < 0 (signed), and falls through when a0 >= 0 (signed).
  The `beq` branch at 0x4370c targets 0x43784, is taken when (t8(=[[([[-0x3c00]:8]:8 + (a0 << 0x3))]:8+34386]:2) & 0x1) == 0, and falls through when (t8(=[[([[-0x3c00]:8]:8 + (a0 << 0x3))]:8+34386]:2) & 0x1) != 0.
  The `beq` branch at 0x43728 targets 0x43764, is taken when t9(?) == ra(=0x4), and falls through when t9(?) != ra(=0x4).
  The `beq` branch at 0x4375c targets 0x43744 and is always taken.
  The `beq` branch at 0x43768 targets 0x43734 and is always taken.
  The `beq` branch at 0x4377c targets 0x43740 and is always taken.
  The `beq` branch at 0x4378c targets 0x43740 and is always taken.
  The return at 0x43754 has v0 = one of ?, 0x16.

- `md_perf_start_count` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x43794 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x43794-0x437ec (88 bytes).
  It occupies 88 bytes.
  2 such `lh` accesses load 2 bytes from a0 (arg0 at entry) +0x1a, including `lh` at 0x437a8, `lh` at 0x437cc.
  The `sd` at 0x437c8 stores 8 bytes to ?.
  The `lh` at 0x437d0 loads 2 bytes from a0 (arg0 at entry) +0x4.
  The `sd` at 0x437e8 stores 8 bytes to ([a0+26]:2 << 0x21) -0x6dfffffffe5f0000.
  The `bne` branch at 0x437c4 targets 0x437a8, is taken when a2(?) < 0x6 (signed), and falls through when a2(?) >= 0x6 (signed).
  The return at 0x437e4 has v0 = ?.

- `md_perf_update_count` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x43804 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x43804-0x438d8 (212 bytes).
  It occupies 212 bytes.
  3 such `lh` accesses load 2 bytes from a0 (arg0 at entry) +0x4, including `lh` at 0x43810, `lh` at 0x43840, `lh` at 0x438ac.
  The `sd` at 0x4383c stores 8 bytes to (a0 + ([a0+4]:2 << 0x3)) +0x140.
  The `lh` at 0x43848 loads 2 bytes from a0 (arg0 at entry) +0x1a.
  3 such `ld` accesses load 8 bytes from ?, including `ld` at 0x4386c, `ld` at 0x43870, `ld` at 0x438c8.
  2 such `sd` accesses store 8 bytes to ?, including `sd` at 0x43890, `sd` at 0x438d4.
  The `beq` branch at 0x4388c targets 0x438ac, is taken when a7(=0xfffff) == t2(?), and falls through when a7(=0xfffff) != t2(?).
  The `bne` branch at 0x4389c targets 0x43840, is taken when a2(?) < 0x6 (signed), and falls through when a2(?) >= 0x6 (signed).
  The `beq` branch at 0x438d0 targets 0x43894 and is always taken.
  The return at 0x438a4 has v0 = ?.

- `md_perf_multiplex` in `IP35/usr/cpu/sysgen/IP35boot/kernel.o` at 0x438d8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/kernel.o`.
  Range: 0x438d8-0x439ac (212 bytes).
  It occupies 212 bytes.
  The `ld` at 0x438e0 loads 8 bytes from abs 0xffffffffffffc400.
  The `ld` at 0x438e4 loads 8 bytes from [-0x3c00]:8 +0x0.
  The `ld` at 0x438f0 loads 8 bytes from ([[-0x3c00]:8]:8 + (a0 << 0x3)) +0x0.
  The `lh` at 0x43910 loads 2 bytes from [([[-0x3c00]:8]:8 + (a0 << 0x3))]:8 +0x8652.
  The `lh` at 0x43924 loads 2 bytes from [([[-0x3c00]:8]:8 + (a0 << 0x3))]:8 +0x8650.
  The `lh` at 0x43930 loads 2 bytes from [([[-0x3c00]:8]:8 + (a0 << 0x3))]:8 +0x8654.
  The `lw` at 0x43934 loads 4 bytes from [([[-0x3c00]:8]:8 + (a0 << 0x3))]:8 +0x87c0.
  The `sh` at 0x43990 stores 2 bytes to [([[-0x3c00]:8]:8 + (a0 << 0x3))]:8 +0x8654.
  The `jal` at 0x43900 calls md_perf_stop_count with a0=[([[-0x3c00]:8]:8 + (a0 << 0x3))]:8+34384, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x43908 calls md_perf_update_count with a0=[([[-0x3c00]:8]:8 + (a0 << 0x3))]:8+34384, a1=?, a2=?, a3=?.
  The `jal` at 0x43994 calls md_perf_start_count with a0=[([[-0x3c00]:8]:8 + (a0 << 0x3))]:8+34384, a1=?, a2=?, a3=?, a6=0x1, a7=0x5.
  The `beq` branch at 0x4391c targets 0x4399c, is taken when (t8(=[[([[-0x3c00]:8]:8 + (a0 << 0x3))]:8+34386]:2) & 0x1) == 0, and falls through when (t8(=[[([[-0x3c00]:8]:8 + (a0 << 0x3))]:8+34386]:2) & 0x1) != 0.
  The `beq` branch at 0x43928 targets 0x43994, is taken when t9(=[[([[-0x3c00]:8]:8 + (a0 << 0x3))]:8+34384]:2) == 0, and falls through when t9(=[[([[-0x3c00]:8]:8 + (a0 << 0x3))]:8+34384]:2) != 0.
  The `bne` branch at 0x4395c targets 0x43990, is taken when (a2(=[[([[-0x3c00]:8]:8 + (a0 << 0x3))]:8+34752]) & ra(?)) != 0, and falls through when (a2(=[[([[-0x3c00]:8]:8 + (a0 << 0x3))]:8+34752]) & ra(?)) == 0.
  The `beq` branch at 0x43964 targets 0x43990, is taken when a3(=[[([[-0x3c00]:8]:8 + (a0 << 0x3))]:8+34388]:2) == a0(?), and falls through when a3(=[[([[-0x3c00]:8]:8 + (a0 << 0x3))]:8+34388]:2) != a0(?).
  The `bne` branch at 0x43980 targets 0x43990, is taken when (a2(=[[([[-0x3c00]:8]:8 + (a0 << 0x3))]:8+34752]) & v0(?)) != 0, and falls through when (a2(=[[([[-0x3c00]:8]:8 + (a0 << 0x3))]:8+34752]) & v0(?)) == 0.
  The `bne` branch at 0x43988 targets 0x43940, is taken when a3(=[[([[-0x3c00]:8]:8 + (a0 << 0x3))]:8+34388]:2) != a0(?), and falls through when a3(=[[([[-0x3c00]:8]:8 + (a0 << 0x3))]:8+34388]:2) == a0(?).
  The return at 0x439a4 has v0 = one of ret(md_perf_update_count), ret(md_perf_start_count).
